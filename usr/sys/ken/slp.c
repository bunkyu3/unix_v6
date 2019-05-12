newproc(){
	int a1, a2;
	struct proc *p, *up;
	register struct proc *rpp;
	register *rip, n;

	p = NULL;

retry:
	mpid++;							//プロセスを生成するごとにmpidをインクリメント
	if(mpid < 0){					//unsigned int型がないのでいずれ負になる
		mpid = 0;					// 0に戻す
		goto retry;					// retryへ
	}
	for(rpp = &proc[0]; rpp < &proc[NPROC]; rpp++){		//proc[]から空きエントリを検索
		if(rpp->p_stat == NULL && p == NULL)			// 見つかった
			p = rpp;									//  pに格納
		if(rpp->p_pid == mpid)							// 同じIDを持っているエントリが存在した
			goto retry;									//  retryへ 
	}
	if((rpp = p)==NULL)									//空きエントリが見つからなかった
		panic("no procs");								// panic()を呼びシステムを止める 

	rip = u.u_procp;				//ripは現在実行中のプロセス（親プロセス）のproc[]エントリを指す
	up = rip;
	rpp->p_stat = SRUN;				//子プロセスを実行可能状態に
	rpp->p_flag = SLOAD;			//子プロセスは「メモリ中に存在する」
	rpp->p_uid = rip->p_uid;		//子プロセスに親プロセスの情報をコピー
	rpp->p_ttyp = rip->ttyp;		//子プロセスに親プロセスの情報をコピー
	rpp->p_nice = rip->nice;		//子プロセスに親プロセスの情報をコピー
	rpp->textp = rip->p_textp;		//子プロセスに親プロセスの情報をコピー
	rpp->p_pid = mpid;				//子プロセスのプロセスIDを設定
	rpp->p_ppid = rip->p_pid;		//子プロセスの親プロセスIDを設定
	rpp->p_time = 0;				//実行時間の初期化

	return(0);
}
