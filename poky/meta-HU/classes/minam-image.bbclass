inherit core-image

IMAGE_FSTYPES = "tar.bz2 ext4 rpi-sdimg"

IMAGE_ROOTFS_SIZE = "10000000"
IMAGE_ROOTFS_EXTRA_SPACE = "102400"
IMAGE_ROOTFS_ALIGNMENT = "10240"

CORE_IMAGE_BASE_INSTALL = "\
	packagegroup-core-boot \
	packagegroup-base-extended \
	packagegroup-base \
	${CORE_IMAGE_EXTRA_INSTALL} \
"
