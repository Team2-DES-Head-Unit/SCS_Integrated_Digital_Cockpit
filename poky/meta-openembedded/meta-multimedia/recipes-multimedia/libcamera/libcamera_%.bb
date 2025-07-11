SUMMARY = "Linux libcamera framework"
SECTION = "libs"

LICENSE = "GPL-2.0-or-later & LGPL-2.1-or-later"

LIC_FILES_CHKSUM = "\
    file://LICENSES/GPL-2.0-or-later.txt;md5=fed54355545ffd980b814dab4a3b312c \
    file://LICENSES/LGPL-2.1-or-later.txt;md5=2a4f4fd2128ea2f65047ee63fbca9f68 \
"

SRC_URI = " \
        git://git.libcamera.org/libcamera/libcamera.git;protocol=https;branch=master \
"

SRCREV = "acf8d028edda0a59b10e15962c2606137a4940af"

PV = "202105+git${SRCPV}"

S = "${WORKDIR}/git"

DEPENDS = "python3-pyyaml-native python3-jinja2-native python3-ply-native python3-jinja2-native udev gnutls boost chrpath-native libevent"
DEPENDS += "${@bb.utils.contains('DISTRO_FEATURES', 'qt', 'qtbase qtbase-native', '', d)}"

PACKAGES =+ "${PN}-gst"

PACKAGECONFIG ??= ""
PACKAGECONFIG[gst] = "-Dgstreamer=enabled,-Dgstreamer=disabled,gstreamer1.0 gstreamer1.0-plugins-base"

EXTRA_OEMESON = " \
    -Dpipelines=uvcvideo,simple,vimc \
    -Dipas=vimc \
    -Dv4l2=true \
    -Dcam=enabled \
    -Dlc-compliance=disabled \
    -Dtest=false \
    -Ddocumentation=disabled \
"

RDEPENDS:${PN} = "${@bb.utils.contains('DISTRO_FEATURES', 'wayland qt', 'qtwayland', '', d)}"

inherit meson pkgconfig python3native

do_configure:prepend() {
    sed -i -e 's|py_compile=True,||' ${S}/utils/ipc/mojo/public/tools/mojom/mojom/generate/template_expander.py
}

do_install:append() {
    chrpath -d ${D}${libdir}/libcamera.so.0.0.0
    chrpath -d ${D}${libdir}/libcamera-base.so.0.0.0
}

addtask do_recalculate_ipa_signatures_package after do_package before do_packagedata
do_recalculate_ipa_signatures_package() {
    local modules
    for module in $(find ${PKGD}/usr/lib/libcamera -name "*.so.sign"); do
        module="${module%.sign}"
        if [ -f "${module}" ] ; then
            modules="${modules} ${module}"
        fi
    done

    ${S}/src/ipa/ipa-sign-install.sh ${B}/src/ipa-priv-key.pem "${modules}"
}

FILES:${PN}-dev = "${includedir} ${libdir}/pkgconfig"
FILES:${PN}-dev += " ${libdir}/libcamera.so"
FILES:${PN} += " ${libdir}/libcamera.so.0"
FILES:${PN} += " ${libdir}/libcamera.so.0.0.0"
FILES:${PN}-dev += " ${libdir}/libcamera-base.so"
FILES:${PN} += " ${libdir}/libcamera-base.so.0"
FILES:${PN} += " ${libdir}/libcamera-base.so.0.0.0"
FILES:${PN} += " ${libdir}/v4l2-compat.so"
FILES:${PN}-gst = "${libdir}/gstreamer-1.0/libgstlibcamera.so"
FILES:${PN} += " ${bindir}/cam"