SUMMARY = "cmdline.txt file used to boot the kernel on a Raspberry Pi device"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

COMPATIBLE_MACHINE = "^rpi$"
INHIBIT_DEFAULT_DEPS = "1"
inherit deploy nopackages

CMDLINE_DWC_OTG ?= "dwc_otg.lpm_enable=0"

CMDLINE_ROOT_FSTYPE ?= "rootfstype=ext4"
CMDLINE_ROOT_PARTITION ?= "/dev/mmcblk0p2"

CMDLINE_ROOTFS ?= "root=${CMDLINE_ROOT_PARTITION} ${CMDLINE_ROOT_FSTYPE} rootwait"

CMDLINE_SERIAL ?= "${@oe.utils.conditional("ENABLE_UART", "1", "console=serial0,115200", "", d)}"

CMDLINE_PITFT ?= "${@bb.utils.contains("MACHINE_FEATURES", "pitft", "fbcon=map:10 fbcon=font:VGA8x8", "", d)}"

# Add the kernel debugger over console kernel command line option if enabled
CMDLINE_KGDB ?= '${@oe.utils.conditional("ENABLE_KGDB", "1", "kgdboc=serial0,115200", "", d)}'

# Disable rpi logo on boot
CMDLINE_LOGO ?= '${@oe.utils.conditional("DISABLE_RPI_BOOT_LOGO", "1", "logo.nologo", "", d)}'

CMDLINE_LOGO = "logo.nologo"
CMDLINE_QUIET = "quiet"
# You can define CMDLINE_DEBUG as "debug" in your local.conf or distro.conf
# to enable kernel debugging.
CMDLINE_DEBUG ?= ""
CMDLINE_DSI = "video=DSI-1:400x1280M@60"

# Add a request to isolate processors from the Linux scheduler. ISOLATED_CPUS
# may have the form of a comma separated list of processor numbers "0,1,3", a
# range "0-2", a combination of the two "0-1,3", or a single processor you may
# not specify ALL processors simultaneously
def setup_isolcpus(d):
    string = ""
    if d.getVar('ISOLATED_CPUS'):
        string = 'isolcpus=' + d.getVar('ISOLATED_CPUS')
    return string

CMDLINE_ISOL_CPUS ?= "${@setup_isolcpus(d)}"

# Add RNDIS capabilities (must be after rootwait)
# example: 
# CMDLINE_RNDIS = "modules-load=dwc2,g_ether g_ether.host_addr=<some MAC 
# address> g_ether.dev_addr=<some MAC address>"
# if the MAC addresses are omitted, random values will be used
CMDLINE_RNDIS ?= ""

# That allows to keep the traditional network interface names
CMDLINE_IFNAMES ?= "net.ifnames=0"

CMDLINE = " \
    ${CMDLINE_ISOL_CPUS} \
    ${CMDLINE_DWC_OTG} \
    ${CMDLINE_SERIAL} \
    ${CMDLINE_ROOTFS} \
    ${CMDLINE_CMA} \
    ${CMDLINE_KGDB} \
    ${CMDLINE_LOGO} \
    ${CMDLINE_PITFT} \
    ${CMDLINE_DEBUG} \
    ${CMDLINE_RNDIS} \
    ${CMDLINE_IFNAMES} \
    ${CMDLINE_LOGO} \
    ${CMDLINE_QUIET} \
    ${CMDLINE_DSI} \
    "

do_compile() {
    echo "${@' '.join(d.getVar('CMDLINE').split())}" > "${WORKDIR}/cmdline.txt"
}

do_deploy() {
    install -d "${DEPLOYDIR}/${BOOTFILES_DIR_NAME}"
    install -m 0644 "${WORKDIR}/cmdline.txt" "${DEPLOYDIR}/${BOOTFILES_DIR_NAME}"
}

addtask deploy before do_build after do_install
do_deploy[dirs] += "${DEPLOYDIR}/${BOOTFILES_DIR_NAME}"

PACKAGE_ARCH = "${MACHINE_ARCH}"
