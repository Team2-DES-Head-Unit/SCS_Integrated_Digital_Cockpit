DESCRIPTION = "booting animation"
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

LICENSE = "CLOSED"
SRC_URI = " \
file://domic.cfg \
file://guest.cfg \
"

S = "${WORKDIR}"

do_install() {
    install -d  ${D}${sysconfdir}/xen
    install -m 0644 ${WORKDIR}/domic.cfg    ${D}${sysconfdir}/xen/
    install -m 0644 ${WORKDIR}/guest.cfg ${D}${sysconfdir}/xen/

    install -d  ${D}${sysconfdir}/xen/auto
    ln -s ../guest.cfg ${D}${sysconfdir}/xen/auto/
    ln -s ../domic.cfg    ${D}${sysconfdir}/xen/auto/
    

}


FILES:${PN} += "${sysconfdir}/xen"
FILES:${PN} += "${sysconfdir}/xen/auto"


