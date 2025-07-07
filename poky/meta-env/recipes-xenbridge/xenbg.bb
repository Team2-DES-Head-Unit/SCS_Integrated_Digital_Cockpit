DESCRIPTION = "booting animation"
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

LICENSE = "CLOSED"
SRC_URI = " \
file://autobridgeassign.sh \
file://bridge.service \
file://huip.sh \
file://icip.sh \
"

S = "${WORKDIR}"

inherit systemd
RDEPENDS:${PN} += "bash" 
do_install() {
    install -d ${D}${systemd_unitdir}/system/
    install -m 644 ${WORKDIR}/bridge.service ${D}${systemd_unitdir}/system/
    install -d ${D}${bindir}/
    install -m 0755 ${S}/autobridgeassign.sh ${D}${bindir}/autobridgeassign.sh
    install -m 0755 ${S}/huip.sh ${D}${bindir}/huip.sh
    install -m 0755 ${S}/icip.sh ${D}${bindir}/icip.sh

}


SYSTEMD_SERVICE:${PN} = "bridge.service"
SYSTEMD_AUTO_ENABLE = "enable"
FILES:${PN} += "${systemd_unitdir}/system/bridge.service"
FILES:${PN} += "/usr/bin/autobridgeassign.sh"
FILES:${PN} += "/usr/bin/huip.sh"
FILES:${PN} += "/usr/bin/icip.sh"




