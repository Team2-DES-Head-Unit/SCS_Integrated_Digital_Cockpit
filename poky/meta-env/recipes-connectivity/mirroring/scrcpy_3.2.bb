DESCRIPTION = "Display and control your Android device"
HOMEPAGE = "https://github.com/Genymobile/scrcpy"
LICENSE = "CLOSED"

SRCREV = "e0f37f834bb2e9371c0ca893757b60eb36e759af" 

SRC_URI = "\
    git://github.com/Genymobile/scrcpy.git;protocol=https;branch=master \
    file://scrcpy-server-v3.2 \
"

S = "${WORKDIR}/git"

SRC_URI[scrcpy-server-v3.2.sha256sum] = "b920e0ea01936bf2482f4ba2fa985c22c13c621999e3d33b45baa5acfc1ea3d0"

DEPENDS = "android-tools ffmpeg libsdl2 libusb1 libxml2"

inherit meson pkgconfig gettext

EXTRA_OEMESON += " \
  --buildtype=release \
  -Db_lto=true \
  -Dprebuilt_server=${WORKDIR}/scrcpy-server-v3.2 \
"

FILES:${PN} += " \
    ${bindir}/scrcpy \
    ${datadir}/icons/hicolor/256x256/apps/scrcpy.png \
    ${datadir}/bash-completion/completions/scrcpy \
    ${datadir}/zsh/site-functions/_scrcpy \
"
