SUMMARY = "INSTRUMENT CLUSTER GUI"
DESCRIPTION = "INSTRUMENT CLUSTER GUI"
LICENSE = "CLOSED"

SRC_URI = "git://github.com/Team2-DES-Head-Unit/SCS_Integrated_Digital_Cockpit.git;branch=vchan;protocol=https"
SRCREV ="${AUTOREV}"


S = "${WORKDIR}/git/IC_TEST"

inherit cmake_qt5 

DEPENDS += "qtbase qtdeclarative qtquickcontrols2 xen-tools"
RDEPENDS:${PN} += "xen-tools"

do_install() {
    install -d ${D}/usr/bin/ic
    install -m 0755 ${B}/IC_TEST ${D}/usr/bin/ic
    install -m 0755 ${S}/main.qml ${D}/usr/bin/ic
}


FILES:${PN} += "/usr/bin/ic"


