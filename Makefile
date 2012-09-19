#

PROG=		fdpass
SRCS=		fdpass.c
SCRIPTS=	qnet qrun
MAN=		qnet.1 qrun.1 fdpass.1
TRUEPREFIX?=	/usr/local

TRUEPREFIX?=	/usr/local

BINDIR?=	${TRUEPREFIX}/sbin

beforeinstall:
.for script in ${SCRIPTS}
	${INSTALL} ${INSTALL_COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${.CURDIR}/${script} ${DESTDIR}${BINDIR}/${script}
.endfor

.include <bsd.prog.mk>
