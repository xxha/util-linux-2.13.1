include $(top_srcdir)/config/include-Makefile.am

EXTRA_DIST = README.clear README.col

usrbinexec_PROGRAMS = col colcrt colrm column hexdump rev line tailf

hexdump_SOURCES = hexdump.c conv.c display.c hexsyntax.c odsyntax.c parse.c \
		  hexdump.h

man_MANS = col.1 colcrt.1 colrm.1 column.1 hexdump.1 rev.1 line.1 tailf.1

if HAVE_NCURSES
bin_PROGRAMS = more
usrbinexec_PROGRAMS += ul pg
if HAVE_TINFO
more_LDADD = -ltinfo
pg_LDADD = -ltinfo -lncurses
ul_LDADD = -ltinfo
else
more_LDADD = -lncurses
pg_LDADD = -lncurses
ul_LDADD = -lncurses
endif
man_MANS += ul.1 more.1 pg.1
else
if HAVE_TERMCAP
bin_PROGRAMS = more
more_LDADD = -ltermcap
man_MANS += more.1
endif
endif

EXTRA_DIST += README.pg LICENSE.pg
