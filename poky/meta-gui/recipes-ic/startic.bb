DESCRIPTION = "booting animation"
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

LICENSE = "CLOSED"
SRC_URI = " \
file://startic.sh \
file://icstart.service \
"

S = "${WORKDIR}"

inherit systemd
RDEPENDS:${PN} += "bash" 
do_install() {
    install -d ${D}${bindir}/
    install -m 0755 ${S}/startic.sh ${D}${bindir}/startic.sh

    install -d ${D}${systemd_unitdir}/system/
    install -m 644 ${WORKDIR}/icstart.service ${D}${systemd_unitdir}/system/
}



FILES:${PN} += "/usr/bin/startic.sh"

SYSTEMD_SERVICE:${PN} = "icstart.service"
SYSTEMD_AUTO_ENABLE = "enable"
FILES:${PN} += "${systemd_unitdir}/system/icstart.service"