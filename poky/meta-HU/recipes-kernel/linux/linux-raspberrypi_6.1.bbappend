LINUX_VERSION = "6.1.46"
SRCREV_machine = "e89e7655a197d28df49da2be7e2003436cf52197"

FILESEXTRAPATHS:prepend := "${THISDIR}/linux-raspberrypi:"


RPI_KERNEL_DEVICETREE_OVERLAYS:append = " overlays/mcp251xfd-overlay.dtbo"


do_configure:append() {

    cp ${WORKDIR}/overlays/mcp251xfd-overlay.dts \
       ${S}/arch/arm/boot/dts/overlays/


    makefile="${S}/arch/arm/boot/dts/overlays/Makefile"
    grep -q "mcp251xfd-overlay.dtbo" "$makefile" || \
        echo 'dtbo-$(CONFIG_ARCH_BCM2711) += mcp251xfd-overlay.dtbo' >> "$makefile"
}