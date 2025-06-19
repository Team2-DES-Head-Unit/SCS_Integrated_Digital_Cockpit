ENABLE_SPI_BUS = "1"
ENABLE_I2C = "1"

do_deploy:append() {
    echo "#[HDMI:0]" >> $CONFIG
    echo "hdmi_force_hotplug:0=1" >> $CONFIG
    echo "hdmi_force_hotplug:1=1" >> $CONFIG
    echo "hdmi_drive=2" >> $CONFIG
    echo "#hdmi_group=2" >> $CONFIG
    echo "#hdmi_mode=87" >> $CONFIG
    echo "#hdmi_cvt=1024 600 60 6 0 0 0" >> $CONFIG
    echo "#[HDMI:1]" >> $CONFIG
    echo "hdmi_ignore_edid:0=0xa5000080" >> $CONFIG
    echo "hdmi_ignore_edid:1=0xa5000080" >> $CONFIG
    echo "#hdmi_cvt=1024 600 60 6 0 0 0" >> $CONFIG

    echo "hdmi_safe=1" >> $CONFIG
    echo "#hdmi_force_hotplug=1" >> $CONFIG
    echo "#hdmi_drive=2" >> $CONFIG
    echo "#arm_boost=1" >> $CONFIG
    echo "#hdmi_group=2" >> $CONFIG
    echo "#hdmi_mode=87" >> $CONFIG
    echo "#hdmi_cvt 1024 600 60 6 0 0 0" >> $CONFIG
    echo "dtparam=i2c_arm=on" >> $CONFIG
    echo "dtoverlay=spi1-3cs" >> $CONFIG
    echo "dtoverlay=spi0-3cs" >> $CONFIG


    echo "# Automatically load overlays for detected DSI displays" >> $CONFIG
    echo "display_auto_detect=1" >> $CONFIG

    echo "# Enable DRM VC4 V3D driver" >> $CONFIG
    echo "max_framebuffers=2" >> $CONFIG
    echo "dtoverlay=vc4-kms-dsi-waveshare-panel-overlay" >> $CONFIG
    echo "#ignore_lcd=0" >> $CONFIG

    echo "# Disable compensation for displays with overscan" >> $CONFIG
    echo "#disable_overscan=1" >> $CONFIG

    echo "# Enable CAN" >> $CONFIG
    echo "#dtoverlay=seeed-can-fd-hat-v1" >> $CONFIG

    echo "# Enable audio" >> $CONFIG
    echo "dtparam=audio=on" >> $CONFIG
    echo "disable_splash=1" >> $CONFIG
    echo "start_x=1" >> $CONFIG
    echo "gpu_mem=256" >> $CONFIG
}


