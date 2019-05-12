struct proc{
	char p_stat;	//状態。NULLの場合はそのproc[]エントリは空
	char p_flag;	//フラグ
	char p_pri;
	char p_sig;
	char p_uid;
	char p_time;
	char p_cpu;
	char p_nice;
	int p_ttyp;
	int p_pid;		//プロセスのID(unique)
	int p_ppid;		//親プロセスのID
	int p_addr;
	int p_size;
	int p_wchan;
	int *p_textp;
}

#define SSLEEP	1
#define	SWAIT	2
#define	SRUN	3	//実行可能状態
#define	SIDL	4
#define	SZOMB	5
#define	SSTOP	6

#define SLOAD	01	//メモリ上に存在（スワップアウトされてない）
#define	SSYS	02
#define SLOCK	04
#define	SSWAP	010
#define	STRC	020
#define	SWTED	040	
	
