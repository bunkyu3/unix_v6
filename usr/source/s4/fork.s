.globl	_fork, cerror, _par_uid

_fork:
	mov		r5, -(sp)
	mov		sp, r5
	sys		fork		//forkシステムコール発行(sysがカーネルモードへの移行をしてるはず)

	bec		2f			//システムコール中にエラーがなければ2へ

2:
	mov		(sp)+,r5
	rts		pc			//_forkを呼び出した関数へリターン
