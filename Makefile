#

PROG=		fdpass
SRCS=		fdpass.c
SCRIPTS=	qnet qrun
MAN=		qnet.1 qrun.1

BINDIR?=	${TRUEPREFIX}/sbin

beforeinstall:
.for script in ${SCRIPTS}
	${INSTALL} ${INSTALL_COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${.CURDIR}/${script} ${DESTDIR}${BINDIR}/${script}
.endfor

.include <bsd.prog.mk>
