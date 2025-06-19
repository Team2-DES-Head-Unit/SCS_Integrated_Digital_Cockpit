SUMMARY = "pigpio GPIO library"
LICENSE = "Unlicense"
LIC_FILES_CHKSUM = "file://UNLICENCE;md5=61287f92700ec1bdf13bc86d8228cd13"

SRC_URI = "git://github.com/joan2937/pigpio.git;protocol=https;branch=master"
SRCREV = "c33738a320a3e28824af7807edafda440952c05d"
S = "${WORKDIR}/git"

inherit cmake

FILES:${PN}-bin-pigpiod = "${bindir}/pigpiod"
FILES:${PN}-bin-pigs = "${bindir}/pigs"
FILES:${PN}-bin-pig2vcd = "${bindir}/pig2vcd"
