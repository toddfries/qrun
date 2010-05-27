#

PROG=		fdpass
SCRIPTS=	qemu-nat qemu-routed qemu-bridged
NOMAN=

BINDIR?=	${PREFIX}/sbin

beforeinstall:
.for script in ${SCRIPTS}
	${INSTALL} ${INSTALL_COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${.CURDIR}/${script} ${DESTDIR}${BINDIR}/${script}
.endfor

.include <bsd.prog.mk>