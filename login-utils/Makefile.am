include $(top_srcdir)/config/include-Makefile.am

bin_PROGRAMS =
usrbinexec_PROGRAMS =
sbin_PROGRAMS =
usrsbinexec_PROGRAMS =
man_MANS =

EXTRA_DIST = README.getty  README.modems-with-agetty  README.poeigl

if BUILD_AGETTY
sbin_PROGRAMS += agetty
man_MANS += agetty.8
endif

if BUILD_INIT

sbin_PROGRAMS += simpleinit shutdown initctl
man_MANS += fastboot.8 fasthalt.8 halt.8 reboot.8 simpleinit.8 shutdown.8 \
	initctl.8

simpleinit_SOURCES = simpleinit.c my_crypt.h simpleinit.h
initctl_SOURCES = initctl.c simpleinit.h

if NEED_LIBCRYPT
simpleinit_LDADD = -lcrypt
endif

endif

if BUILD_LAST
usrbinexec_PROGRAMS += last
man_MANS += last.1
endif

if BUILD_LOGIN_UTILS

bin_PROGRAMS += login
usrbinexec_PROGRAMS += chfn chsh newgrp
usrsbinexec_PROGRAMS += vipw
man_MANS += chfn.1 chsh.1 login.1 newgrp.1 vipw.8 vigr.8

chfn_SOURCES = chfn.c $(chfn_chsh_common)
chsh_SOURCES = chsh.c $(chfn_chsh_common)
chfn_chsh_common = islocal.c setpwnam.c islocal.h my_crypt.h setpwnam.h \
	../lib/env.c
login_SOURCES = login.c login.h my_crypt.h ../lib/setproctitle.c
newgrp_SOURCES = newgrp.c my_crypt.h
vipw_SOURCES = vipw.c setpwnam.h

chfn_LDADD =
chsh_LDADD =
login_LDADD =
newgrp_LDADD =
vipw_LDADD =

chfn_CFLAGS = $(SUID_CFLAGS) $(AM_CFLAGS)
chsh_CFLAGS = $(SUID_CFLAGS) $(AM_CFLAGS)
newgrp_CFLAGS = $(SUID_CFLAGS) $(AM_CFLAGS)

chfn_LDFLAGS = $(SUID_LDFLAGS) $(AM_LDFLAGS)
chsh_LDFLAGS = $(SUID_LDFLAGS) $(AM_LDFLAGS)
newgrp_LDFLAGS = $(SUID_LDFLAGS) $(AM_LDFLAGS)

if NEED_LIBCRYPT
chfn_LDADD += -lcrypt
chsh_LDADD += -lcrypt
login_LDADD += -lcrypt
newgrp_LDADD += -lcrypt
endif

if HAVE_PAM
chfn_LDADD += -lpam -lpam_misc
chsh_LDADD += -lpam -lpam_misc
login_LDADD += -lpam -lpam_misc
else
login_SOURCES += checktty.c
endif

if HAVE_AUDIT
login_LDADD += -laudit
endif

if HAVE_SELINUX
chfn_SOURCES += selinux_utils.c selinux_utils.h
chfn_LDADD += -lselinux
chsh_SOURCES += selinux_utils.c selinux_utils.h
chsh_LDADD += -lselinux
vipw_LDADD += -lselinux
endif


install-exec-hook::
	cd $(DESTDIR)$(usrsbinexecdir) && ln -sf vipw vigr

endif

if BUILD_MESG
usrbinexec_PROGRAMS += mesg
man_MANS += mesg.1
endif

if BUILD_WALL
usrbinexec_PROGRAMS += wall
wall_SOURCES = wall.c ttymsg.c ttymsg.h
man_MANS += wall.1

if USE_TTY_GROUP
if MAKEINSTALL_DO_CHOWN
install-exec-hook::
	chgrp tty $(DESTDIR)$(usrbinexecdir)/wall
	chmod g+s $(DESTDIR)$(usrbinexecdir)/wall
endif
endif
endif

if BUILD_INIT

install-exec-hook::
	cd $(DESTDIR)$(sbindir) && ln -sf shutdown reboot
	cd $(DESTDIR)$(sbindir) && ln -sf shutdown fastboot
	cd $(DESTDIR)$(sbindir) && ln -sf shutdown halt
	cd $(DESTDIR)$(sbindir) && ln -sf shutdown fasthalt
	cd $(DESTDIR)$(sbindir) && ln -sf initctl need
	cd $(DESTDIR)$(sbindir) && ln -sf initctl display-services
	cd $(DESTDIR)$(sbindir) && ln -sf initctl provide
	cd $(DESTDIR)$(mandir)/man8 && ln -sf initctl.8 need.8
	cd $(DESTDIR)$(mandir)/man8 && ln -sf initctl.8 display-services.8
	cd $(DESTDIR)$(mandir)/man8 && ln -sf initctl.8 provide.8

endif

noinst_PROGRAMS = checktty_test
checktty_test_SOURCES = checktty.c login.h
checktty_test_CPPFLAGS = -DMAIN_TEST_CHECKTTY $(AM_CPPFLAGS)

