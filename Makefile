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

all: README.md

README.md: ${.CURDIR}/qrun.1
	@make ${.CURDIR}/README.md

${.CURDIR}/README.md: ${.CURDIR}/qrun.1
	mandoc -Thtml ${.CURDIR}/qrun.1 | grep -v DOCTYPE > ${.CURDIR}/README.md

.include <bsd.prog.mk>
