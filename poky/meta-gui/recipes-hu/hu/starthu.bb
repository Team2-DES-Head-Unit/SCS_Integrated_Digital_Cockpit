DESCRIPTION = "booting animation"
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

LICENSE = "CLOSED"
SRC_URI = " \
file://starthu.sh \
file://hustart.service \
"

S = "${WORKDIR}"

inherit systemd
RDEPENDS:${PN} += "bash" 
do_install() {
    install -d ${D}${bindir}/
    install -m 0755 ${S}/starthu.sh ${D}${bindir}/starthu.sh

    install -d ${D}${systemd_unitdir}/system/
    install -m 644 ${WORKDIR}/hustart.service ${D}${systemd_unitdir}/system/
}



FILES:${PN} += "/usr/bin/starthu.sh"

SYSTEMD_SERVICE:${PN} = "hustart.service"
SYSTEMD_AUTO_ENABLE = "enable"
FILES:${PN} += "${systemd_unitdir}/system/hustart.service"