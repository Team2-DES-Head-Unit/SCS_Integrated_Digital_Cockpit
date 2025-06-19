SUMMARY = "Piracer cpp"
DESCRIPTION = "Piracer cpp"
LICENSE = "CLOSED"

SRC_URI = "git://github.com/Team2-DES-Head-Unit/SCS_Integrated_Digital_Cockpit.git;branch=master;protocol=https"
SRCREV ="${AUTOREV}"

S = "${WORKDIR}/git/piracer-cpp"

inherit cmake 

DEPENDS += "pigpio"
RDEPENDS:${PN} = "pigpio"



do_install() {
    install -d ${D}/usr/bin/controlcpp
    install -m 0755 ${B}/gamepad_control ${D}/usr/bin/controlcpp
    
}

INSANE_SKIP:${PN} += "dev-deps"



FILES:${PN} += "/usr/bin/controlcpp"




