/*
 * sundries.h
 * Support function prototypes.  Functions are in sundries.c.
 */
#ifndef SUNDRIES_H
#define SUNDRIES_H

#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
#if !defined(bool_t) && !defined(__GLIBC__)
#include <rpc/types.h>
#endif

extern int mount_quiet;
extern int verbose;
extern int sloppy;

#define streq(s, t)	(strcmp ((s), (t)) == 0)

/* Functions in sundries.c that are used in mount.c and umount.c  */ 
void block_signals (int how);
char *canonicalize (const char *path);
void error (const char *fmt, ...);
int matching_type (const char *type, const char *types);
int matching_opts (const char *options, const char *test_opts);
void *xmalloc (size_t size);
char *xstrdup (const char *s);
char *xstrndup (const char *s, int n);
char *xstrconcat3 (char *, const char *, const char *);
char *xstrconcat4 (char *, const char *, const char *, const char *);

int parse_spec(const char *spec, char **name, char **value);

void die (int errcode, const char *fmt, ...);

/* exit status - bits below are ORed */
#define EX_USAGE	1	/* incorrect invocation or permission */
#define EX_SYSERR	2	/* out of memory, cannot fork, ... */
#define EX_SOFTWARE	4	/* internal mount bug or wrong version */
#define EX_USER		8	/* user interrupt */
#define EX_FILEIO      16	/* problems writing, locking, ... mtab/fstab */
#define EX_FAIL	       32	/* mount failure */
#define EX_SOMEOK      64	/* some mount succeeded */

#define EX_BG         256       /* retry in background (internal only) */

#endif /* SUNDRIES_H */

