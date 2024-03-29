#ifndef MOUNT_FSTAB_H
#define MOUNT_FSTAB_H

#include "mount_mntent.h"
int mtab_is_writable(void);
int mtab_does_not_exist(void);
int is_mounted_once(const char *name);

struct mntentchn {
	struct mntentchn *nxt, *prev;
	struct my_mntent m;
};

struct mntentchn *mtab_head (void);
struct mntentchn *getmntfile (const char *name);
struct mntentchn *getmntoptfile (const char *file);
struct mntentchn *getmntdirbackward (const char *dir, struct mntentchn *mc);
struct mntentchn *getmntdevbackward (const char *dev, struct mntentchn *mc);

struct mntentchn *fstab_head (void);
struct mntentchn *getfs_by_dir (const char *dir);
struct mntentchn *getfs_by_spec (const char *spec);
struct mntentchn *getfs_by_devname (const char *devname);
struct mntentchn *getfs_by_specdir (const char *spec, const char *dir);
struct mntentchn *getfs_by_uuid (const char *uuid);
struct mntentchn *getfs_by_label (const char *label);

void lock_mtab (void);
void unlock_mtab (void);
void update_mtab (const char *special, struct my_mntent *with);

#endif /* MOUNT_FSTAB_H */
