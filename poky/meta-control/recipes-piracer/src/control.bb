SUMMARY = "Custom Python script for PiRacer"
DESCRIPTION = "Install custom Python script into /usr/bin/piracer"
LICENSE = "MIT"
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"
SRC_URI = "file://control.py \
file://COPYING \
file://gpiotest.py \
"
 
LIC_FILES_CHKSUM = "file://COPYING;md5=2d0ac4608dd8146d0b618a8249a5ba3e"


S = "${WORKDIR}"

inherit allarch systemd

do_install() {
    install -d ${D}${bindir}/
    install -m 0755 ${S}/control.py ${D}${bindir}/
    install -m 0755 ${S}/gpiotest.py ${D}${bindir}/

}


FILES:${PN} += "${bindir}/control.py"
FILES:${PN} += "${bindir}/gpiotest.py"



