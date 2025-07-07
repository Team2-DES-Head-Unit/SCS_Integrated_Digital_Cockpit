SRC_URI += "file://99-scrcpy.rules \
            file://scrcpy@.service \
"

inherit systemd

do_install:append() {
    install -Dm 0644 ${WORKDIR}/99-scrcpy.rules ${D}${sysconfdir}/udev/rules.d/99-scrcpy.rules
    install -Dm 0644 ${WORKDIR}/scrcpy@.service ${D}${systemd_system_unitdir}/scrcpy@.service
}

FILES:${PN} += "${systemd_system_unitdir}/scrcpy@.service"
