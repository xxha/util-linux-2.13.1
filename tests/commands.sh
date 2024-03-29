TOPDIR=..
TS_TOPDIR=$TOPDIR/tests

AWK=gawk

# Misc settings
TS_TESTUSER=${TS_TESTUSER:-"test"}

# helpers
TS_HELPER_SYSINFO="$TS_TOPDIR/helpers/mnt_test_sysinfo"

# external commands
TS_ECMD_BLKID="/sbin/blkid"
TS_ECMD_VOLID=""

# paths to commands
TS_CMD_MOUNT=${TS_CMD_MOUNT:-"$TOPDIR/mount/mount"}
TS_CMD_UMOUNT=${TS_CMD_UMOUNT:-"$TOPDIR/mount/umount"}
TS_CMD_SWAPON=${TS_CMD_SWAPON:-"$TOPDIR/mount/swapon"}
TS_CMD_SWAPOFF=${TS_CMD_SWAPOFF:-"$TOPDIR/mount/swapoff"}
TS_CMD_LOSETUP=${TS_CMD_LOSETUP:-"$TOPDIR/mount/losetup"}

TS_CMD_MTABLOCK=${TS_CMD_MTABLOCK:-"$TOPDIR/mount/mtab_lock_test"}

TS_CMD_MKSWAP=${TS_CMD_MKSWAP:-"$TOPDIR/disk-utils/mkswap"}
TS_CMD_MKCRAMFS=${TS_CMD_MKCRAMFS:-"$TOPDIR/disk-utils/mkfs.cramfs"}

TS_CMD_IPCS=${TS_CMD_IPCS:-"$TOPDIR/sys-utils/ipcs"}

TS_CMD_COL=${TS_CMD_COL:-"$TOPDIR/text-utils/col"}

TS_CMD_NAMEI=${TS_CMD_NAMEI-"$TOPDIR/misc-utils/namei"}
TS_CMD_LOOK=${TS_CMD_LOOK-"$TOPDIR/misc-utils/look"}
TS_CMD_CAL=${TS_CMD_CAL-"$TOPDIR/misc-utils/cal"}
TS_CMD_CALTEST=${TS_CMD_CALTEST-"$TOPDIR/misc-utils/cal_test"}
TS_CMD_SCRIPT=${TS_CMD_SCRIPT-"$TOPDIR/misc-utils/script"}

TS_CMD_CHECKTTY=${TS_CMD_CHECKTTY-"$TOPDIR/login-utils/checktty_test"}

TS_CMD_HWCLOCK=${TS_CMD_HWCLOCK-"$TOPDIR/hwclock/hwclock"}



