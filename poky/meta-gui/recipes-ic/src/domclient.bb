SUMMARY = "Head unit GUI"
DESCRIPTION = "Head unit GUI"
LICENSE = "CLOSED"

SRC_URI = "git://github.com/Team2-DES-Head-Unit/SCS_Integrated_Digital_Cockpit.git;branch=vchan;protocol=https"
SRCREV ="${AUTOREV}"

S = "${WORKDIR}/git/vchan_test/domu1_client"


DEPENDS += "xen-tools"
RDEPENDS:${PN} += "xen-tools"



do_compile() {
    oe_runmake
}

do_install() {
    install -d ${D}/usr/bin/
    install -m 0755 domu1_client ${D}/usr/bin/
}

FILES:${PN} += "/usr/bin/"




