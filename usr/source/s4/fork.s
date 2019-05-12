.globl	_fork, cerror, _par_uid

_fork:
	mov		r5, -(sp)
	mov		sp, r5
	sys		fork
