fork(){
	register struct proc *p1, *p2;

	p1 = u.u_procp;									//現在実行中のプロセス(親)をp1に
	for(p2 = & proc[0]; p2 < &proc[NPROC]; p2++)	//proc[]から空きエントリを検索
		if(p2->p_stat == NULL)						// 見つかった, p2は子プロセス用
			goto found;								// foundへ
	u.u_error = EAGAIN;								//見つからなかったのでエラーコード格納
	goto out;										//outへ

found:
	if(newproc()){	//親のときは条件式は偽、子のときは真(switch関数のおかげ)となり{}内へ
		u.u_ar0[R0] = p1->p_pid;	//子(ユーザプロセス)のr0レジスタに親のID
		u.u_cstime[0] = 0;			//初期化?
		u.u_sctime[1] = 0;			//初期化?
		u.u_stime = 0;				//初期化?
		u.u_cutime[0] = 0;			//初期化?
		u.u_cutime[1] = 1;			//初期化?
		u.u_utime = 0;				//初期化?
		return;
	}
	u.u_ar0[R0] = p2->p_pid;	//親(ユーザプロセス)のr0レジスタに子のID

out:
	u.u_ar0[R7] =+ 2;			//親(ユーザプロセス)のPCを1命令文進める
}
