LINUX_VERSION = "6.1.46"
SRCREV_machine = "e89e7655a197d28df49da2be7e2003436cf52197"

FILESEXTRAPATHS:prepend := "${THISDIR}/linux-raspberrypi:"

SRC_URI += " \
file://spi0-2cs-overlay.dts \
file://spi1-3cs-overlay.dts \
file://vc4-kms-dsi-waveshare-panel-overlay.dts \
file://edt-ft5406.dtsi \
file://vc4-kms-v3d-pi4-overlay.dts \
file://bcm2835.h \
file://vc4-kms-dsi-7inch-overlay.dts \
file://vc4-fkms-v3d-overlay.dts \
file://vc4-kms-v3d-pi4-overlay.dts \
"
DEPENDS += "dtc-native"

do_install:append() {
    dtc -@ -I dts -O dtb -o ${B}/spi0-2cs.dtbo ${WORKDIR}/spi0-2cs-overlay.dts
    dtc -@ -I dts -O dtb -o ${B}/spi1-3cs.dtbo ${WORKDIR}/spi1-3cs-overlay.dts
    dtc -@ -I dts -O dtb -o ${B}/vc4-fkms-v3d-overlay.dtbo ${WORKDIR}/vc4-fkms-v3d-overlay.dts
    dtc -@ -I dts -O dtb -o ${B}/vc4-kms-dsi-waveshare-panel-overlay.dtbo ${WORKDIR}/vc4-kms-dsi-waveshare-panel-overlay.dts




    BASE_DTB="${B}/arch/arm64/boot/dts/broadcom/bcm2711-rpi-4-b.dtb"
    MERGED_DTB="${B}/bcm2711-merged.dtb"

    if [ -f "$BASE_DTB" ]; then
        fdtoverlay -i "$BASE_DTB" -o "$MERGED_DTB" -v \
            ${B}/spi0-2cs.dtbo \
            ${B}/spi1-3cs.dtbo \
            ${B}/vc4-fkms-v3d-overlay.dtbo \
            ${B}/vc4-kms-dsi-waveshare-panel-overlay.dtbo 

    else
        echo "ERROR: BASE_DTB not found at $BASE_DTB"
        exit 1
    fi
}


do_deploy:append() {
    install -Dm 0644 ${B}/bcm2711-merged.dtb ${DEPLOYDIR}/bcm2711-rpi-4-b.dtb
}