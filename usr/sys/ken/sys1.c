fork(){
	register struct proc *p1, *p2;

	p1 = u.u_procp;									//現在実行中のプロセスをp1に
	for(p2 = & proc[0]; p2 < &proc[NPROC]; p2++)	//proc[]から空きエントリを検索
		if(p2->p_stat == NULL)						// 見つかった
			goto found;								// foundへ
	u.u_error = EAGAIN;								//見つからなかったのでエラーコード格納
	goto out;										//outへ

found:
	if(newproc()){
	
	}
