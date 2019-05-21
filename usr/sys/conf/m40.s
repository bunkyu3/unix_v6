.globl	_savu, _retu
_savu:
	bis		$340,PS		//割り込み禁止
	mov		(sp)+,r1	//savu()から返るアドレスをr1に
	mov		(sp),r0		//引数(r5,r6を格納するアドレス)をr0に
	mov		sp,(r0)+	//spをuser構造体のu_rsavの示す場所に保存
	mov		r5,(r0)+	//r5をuser構造体のu_rsavの示す場所に保存
	bic		$340,PS		//割り込み禁止解除
	jmp		(r1)		//リターン

_retu:
	bis		$340,PS		//割り込み禁止
	mov		(sp)+,r1	//retu()から返るアドレスをr1に
	mov		(sp),KISA6	//引数のproc.p_addrをKISA6に、これでuで新しいプロセスを指す
	mov		$_u,r0		//u_rsavをr0に
1:
	mov		(r0)+,sp	//u_rsav[0]つまりr6を復帰
	mov		(r0)+,r5	//u_rsav[1]つましr5を復帰
	bic		$340,PS		//割り込み禁止解除
	jmp		(r1) 		//リターン

.globl	csv
csv:
	mov		r5,r0
	mov		sp,r5
	mov		r4,-(sp)
	mov		r3,-(sp)
	mov		r2,-(sp)
	jsr		pc,(r0)

.globl	cret
cret:
	mov		r5,r1
	mov		-(r1),r4
	mov		-(r1),r3
	mov		-(r1),r2
	mov		r5,sp
	mov		(sp)+,r5
	rts		pc


