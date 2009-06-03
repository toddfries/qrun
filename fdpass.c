/*
 * Copyright (c) 2009 Claudio Jerker <claudio@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <sys/types.h>
#include <err.h>
#include <fcntl.h>
#include <limits.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

__dead void
usage(void)
{
	extern char *__progname;

	fprintf(stderr, "usage: %s [-u user] -f file [-rw] [-n num] [-f ...] "
	    "utility [argument ...]\n", __progname);
	exit(1);
}

int
main(int argc, char *argv[])
{
	struct passwd	*pw;
	const char	*errstr;
	char		*path = NULL, *user = NULL;
	int		 ch, ro = 0, wo = 0, n = -1, flags = O_RDWR, fd = -1;

	while ((ch = getopt(argc, argv, "f:n:ru:w")) != -1) {
		switch (ch) {
		case 'f':
			path = optarg;
			flags = O_RDWR;
			if (wo && ro)
				errx(1, "only one of -r and -w allowed");
			else if (wo)
				flags = O_WRONLY;
			else if (ro)
				flags = O_RDONLY;

			if ((fd = open(path, flags, 0)) == -1)
				err(1, "open(%s)", path);
			wo = ro = 0;
			break;
		case 'n':
			n = strtonum(optarg, 0, INT_MAX, &errstr);
			if (errstr)
				errx(1, "file descriptor %s is %s", optarg,
				    errstr);
			if (dup2(fd, n) == -1)
				err(1, "dup2");
			close(fd);
			break;
		case 'r':
			ro = 1;
			break;
		case 'u':
			user = optarg;
			break;
		case 'w':
			wo = 1;
			break;
		default:
			usage();
		}
	}
	argc -= optind;
	argv += optind;

	if (path == NULL || user == NULL || argc < 1)
		usage();

	/* drop priviledges */
	if ((pw = getpwnam(user)) == NULL)
		err(1, "getpwnam");
	if (initgroups(user, pw->pw_gid) == -1)
		err(1, "initgroups");
	if (setresgid(pw->pw_gid, pw->pw_gid, pw->pw_gid) ||
	    setresuid(pw->pw_uid, pw->pw_uid, pw->pw_uid))
		err(1, "setres[gu]id");

	if (execvp(argv[0], argv) == -1)
		err(1, "execvp");
}
