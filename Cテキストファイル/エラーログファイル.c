'エラーログファイル

'-----------------------------------------------------------------------------------------------------------------------------
'<IOMAP.XLS / パネルインターフェース> 
'----------------------------------
'【グローバルラベル】
'pnlPBel今日	ビット	MR00100
'pnlPBel日	ビット	MR00101
'pnlPBel週	ビット	MR00102
'pnlPBel月	ビット	MR00103
'pnlPBel左移動	ビット	MR00104
'pnlPBel右移動	ビット	MR00105
'pnlPBel下移動	ビット	MR00106
'pnlPBel下限移動	ビット	MR00107
'pnlPBel上移動	ビット	MR00108
'pnlPBel上限移動	ビット	MR00109
'pnlPBel更新	ビット	MR00110
'pnlPBelALL	ビット	MR00111
'pnlPBel運転中	ビット	MR00112
'pnlPBel自動モード	ビット	MR00113
'pnlPBelテスト運転	ビット	MR00114
'pnlPBel非常停止	ビット	MR00115
'pnlPBel前処理運転中	ビット	MR00200
'init今日	ビット	MR00201
'init日	ビット	MR00202
'init週	ビット	MR00203
'init月	ビット	MR00204
'		
'Filewritestep	1ワード符号なし整数	DM1000
'Filereadstep	1ワード符号なし整数	DM1001
'ErrAnalyzestep	1ワード符号なし整数	DM1002
'ErrAnalyzeStatcheckBit	1ワード符号なし整数	DM1003
'ErrAnlyzeTotalCnt	1ワード符号なし整数	DM1004
'dspErrAnalOffset	1ワード符号なし整数	DM1005
'el現在ページNO	1ワード符号なし整数	DM1006
'dspErrAnalIndex	1ワード符号なし整数	DM1007
'wFilewritestep	1ワード符号なし整数	DM1008
'		
'setFindStart年月日	1ワード符号なし整数[6]	DM1010
'setFindEnd年月日	1ワード符号なし整数[6]	DM1020
'FindStart年月日	1ワード符号なし整数[6]	DM1030
'FindEnd年月日	1ワード符号なし整数[6]	DM1040 
'ErrAnalyzeCode	1ワード符号なし整数[50]	DM1100
'ErrAnalyzePersent	1ワード符号なし整数[50]	DM1150
'ErrAnalyzeCnt	1ワード符号なし整数[50]	DM1200
'----------------------------------------------------------------------------------
'【ローカルラベル】
'FileErr	ビット[2]
'FindEndSec	2ワード符号なし整数
'FindStartSec	2ワード符号なし整数
'OffsetAddres	2ワード符号なし整数
'ReadCnt	1ワード符号なし整数
'ReadErrCode	2ワード符号なし整数
'ReadErrCodeStr	文字列[20]
'ReadFileName	文字列[40]
'ReadSec	2ワード符号なし整数
'ReadSecStr	文字列[20]
'ReadStr	文字列[1500]
'StackEnablebit	ビット
'WriteAlmstr	文字列[40]
'WriteErrAddres	2ワード符号なし整数
'WriteErrCode	2ワード符号なし整数
'WriteErrCodeStr	文字列[20]
'WriteFileName	文字列[40]
'WriteSec	2ワード符号なし整数
'WriteSecStr	文字列[20]
'WriteStatstr	文字列[100]
'WriteStepstr	文字列[1000]
'WriteStr	文字列[1500]
'anloop	1ワード符号なし整数
'dmystr	文字列[25]
'elFindStart年月日	1ワード符号なし整数[6]
'elStatBitstr	文字列[20]
'elテスト運転	1ワード符号なし整数
'elテスト運転str	文字列[20]
'el前処理運転中	1ワード符号なし整数
'el前処理運転中str	文字列[20]
'el自動モード	1ワード符号なし整数
'el自動モードstr	文字列[20]
'el運転中	1ワード符号なし整数
'el運転中str	文字列[20]
'el非常t停止str	文字列[20]
'el非常停止	1ワード符号なし整数
'initFileread	ビット
'linecnt	1ワード符号なし整数
'loop	1ワード符号なし整数
'readerr	ビット[4]
'readpar	1ワード符号なし整数[4]
'readparstak	2ワード符号なし整数
'tmpreadstr	文字列[100]
'-----------------------------------------------------------------------------------------------------------------------------
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理
	Filewritestep=0
	Filereadstep=0
	ErrAnalyzestep=0
end if

'-----------------------------------------------------------------------------------------------------------------------------
'エラーファイル書込み

	select case Filewritestep
	'----------------------------------------------------------------------
	case 1
		MMKDIR("Machine",FileErr)
		INC(Filewritestep)

	case 2
		if FileErr[0] then '完了
			INC(Filewritestep)
		end if
	
	case 3
		if FileErr[1] then '異常終了
		end if
		INC(Filewritestep)

	
	'----------------------------------------------------------------------
	case 4
		if 0 then 'テスト用アドレス
		    adrset(almRS1_水タンク上限センサー,WriteErrAddres)
		    WriteAlmstr="almRS1_水タンク上限センサー"
			
			前処理工程step=120
		end if

		'-------------------------------
		ADRSET(R78000,OffsetAddres) 'almxxxxの先頭アドレス
		WriteErrCode=(WriteErrAddres-OffsetAddres)+7000

		WriteErrCodeStr.T=DASC(WriteErrCode.D,1)
		WriteSec=SEC(CM700)
		WriteSecStr.T=DASC(WriteSec.D,1)		
		'-------------------------------
		if 自動搬送AutoMode then
			WriteStatstr="自動"+","
		else
			WriteStatstr="手動"+","
		end if
		if 自動搬送step>0 or OtherStep>0 or 前処理工程step>0 then
			WriteStatstr=WriteStatstr+"運転中"+","
		else
			WriteStatstr=WriteStatstr+"停止中"+","
		end if
		if テスト運転 then
			WriteStatstr=WriteStatstr+"テスト運転"+","+"ON"+","
		else
			WriteStatstr=WriteStatstr+"テスト運転"+","+"OFF"+","
		end if
		if EmgFlg then
			WriteStatstr=WriteStatstr+"非常停止"+","+"ON"+","
		else
			WriteStatstr=WriteStatstr+"非常停止"+","+"OFF"+","
		end if
		if 前処理工程step<>0 then
			WriteStatstr=WriteStatstr+"前処理運転中"+","+"ON"
		else
			WriteStatstr=WriteStatstr+"前処理運転中"+","+"OFF"
		end if
		'-------------------------------
		'運転step WriteStep 20x30
		WriteStepstr="前処理工程step"+","+DASC(前処理工程step.U,1)+","
		WriteStepstr=WriteStepstr+"計量step"+","+DASC(計量step.U,1)+","
		WriteStepstr=WriteStepstr+"洗米step"+","+DASC(洗米step.U,1)+","
		WriteStepstr=WriteStepstr+"浸漬タンクAユニットstep"+","+DASC(浸漬タンクAユニットstep.U,1)+","
		WriteStepstr=WriteStepstr+"浸漬タンクBユニットstep"+","+DASC(浸漬タンクBユニットstep.U,1)+","
		WriteStepstr=WriteStepstr+"計水ユニットstep"+","+DASC(計水ユニットstep.U,1)+","
		WriteStepstr=WriteStepstr+"ならしユニットstep"+","+DASC(ならしユニットstep.U,1)+","
		WriteStepstr=WriteStepstr+"蓋被せユニットstep"+","+DASC(蓋被せユニットstep.U,1)+","
		WriteStepstr=WriteStepstr+"蓋取りユニットstep"+","+DASC(蓋取りユニットstep.U,1)+","
		WriteStepstr=WriteStepstr+"ほぐし機Aユニットstep"+","+DASC(ほぐし機Aユニットstep.U,1)+","
		WriteStepstr=WriteStepstr+"搬送コンベアAstep"+","+DASC(搬送コンベアAstep.U,1)+","
		WriteStepstr=WriteStepstr+"搬送コンベアBstep"+","+DASC(搬送コンベアBstep.U,1)+","
		WriteStepstr=WriteStepstr+"搬送コンベアCstep"+","+DASC(搬送コンベアCstep.U,1)+","
		WriteStepstr=WriteStepstr+"搬送コンベアC2step"+","+DASC(搬送コンベアC2step.U,1)+","
		WriteStepstr=WriteStepstr+"搬送コンベアDstep"+","+DASC(搬送コンベアDstep.U,1)+","
		WriteStepstr=WriteStepstr+"搬送コンベアEstep"+","+DASC(搬送コンベアEstep.U,1)+","
		WriteStepstr=WriteStepstr+"搬送コンベアF1step"+","+DASC(搬送コンベアF1step.U,1)+","
		WriteStepstr=WriteStepstr+"搬送コンベアF2step"+","+DASC(搬送コンベアF2step.U,1)+","
		WriteStepstr=WriteStepstr+"搬送コンベアGstep"+","+DASC(搬送コンベアGstep.U,1)+","
		WriteStepstr=WriteStepstr+"搬送コンベアHstep"+","+DASC(搬送コンベアHstep.U,1)+","
		WriteStepstr=WriteStepstr+"釜フタ昇降装置Astep"+","+DASC(釜フタ昇降装置Astep.U,1)
		WriteStepstr=WriteStepstr+"釜反転入口step"+","+DASC(釜反転入口step.U,1)+","
		WriteStepstr=WriteStepstr+"洗浄ユニットstep"+","+DASC(洗浄ユニットstep.U,1)+","
		WriteStepstr=WriteStepstr+"洗浄タンクstep"+","+DASC(洗浄タンクstep.U,1)+","
		WriteStepstr=WriteStepstr+"洗浄コンベア搬送step"+","+DASC(洗浄コンベア搬送step.U,1)+","
		WriteStepstr=WriteStepstr+"釜反転出口step"+","+DASC(釜反転出口step.U,1)+","
		WriteStepstr=WriteStepstr+"釜フタ昇降装置Bstep"+","+DASC(釜フタ昇降装置Bstep.U,1)
		WriteStepstr=WriteStepstr+"IH炊飯ユニットAstep"+","+DASC(IH炊飯ユニットAstep.U,1)
		WriteStepstr=WriteStepstr+"IH炊飯ユニットBstep"+","+DASC(IH炊飯ユニットBstep.U,1)
		'----------------------------------------------------------------------
		'ファイル書込み文字列		
		WriteStr.T=str(CM700)+"/"+str(CM701)+"/"+str(CM702)+" "+str(CM703)+":"+STR(CM704)+"," '日付
		WriteStr.T=WriteStr.T+WriteAlmstr+"," 'アラーム名称
		WriteStr.T=WriteStr.T+WriteStatstr+"," '運転状態
		WriteStr.T=WriteStr.T+WriteStepstr 'ユニットSTEP
		'-------------------------------
		WriteStr.T=WriteStr.T+CHR($0D) 
		'----------------------------------------------------------------------
		'ファイル書込み
		WriteFileName.T="Machine\"+"ERRLOG"+"20"+STR(CM700)+STR(CM701)+"."+"CSV" 'ファイル名
		MPRINT(WriteFileName.T,WriteStr.T,FileErr)

		INC(Filewritestep)
	
	case 5
		if FileErr[0] then '完了
			INC(Filewritestep)
		end if
	
	case 6
		if FileErr[1] then '異常終了
		end if
		INC(Filewritestep)

	'----------------------------------------------------------------------
	case 7
		MMKDIR("Machine",FileErr)
		INC(Filewritestep)

	case 8
		if FileErr[0] then '完了
			INC(Filewritestep)
		end if
	
	case 9
		if FileErr[1] then '異常終了
		end if
		INC(Filewritestep)

	'----------------------------------------------------------------------
	case 10
		'-------------------------------
		if 自動搬送AutoMode then
			elStatBitstr="1"+","
		else
			elStatBitstr="0"+","
		end if
		if 自動搬送step>0 or OtherStep>0 or 前処理工程step>0 then
			elStatBitstr=elStatBitstr+"1"+","
		else
			elStatBitstr=elStatBitstr+"0"+","
		end if
		if テスト運転 then
			elStatBitstr=elStatBitstr+"1"+","
		else
			elStatBitstr=elStatBitstr+"0"+","
		end if
		if EmgFlg then
			elStatBitstr=elStatBitstr+"1"+","
		else
			elStatBitstr=elStatBitstr+"0"+","
		end if
		if 前処理工程step<>0 then
			elStatBitstr=elStatBitstr+"1"+","
		else
			elStatBitstr=elStatBitstr+"0"+","
		end if 
		if 自動搬送AutoRun then 'これはフォーマット上の予備です
			elStatBitstr=elStatBitstr+"1"+","
		else
			elStatBitstr=elStatBitstr+"0"+","
		end if
		if 自動搬送AutoRun then
			elStatBitstr=elStatBitstr+"1"+","
		else
			elStatBitstr=elStatBitstr+"0"+","
		end if
		if 自動搬送AutoRun then
			elStatBitstr=elStatBitstr+"1"
		else
			elStatBitstr=elStatBitstr+"0"
		end if
		'----------------------------------------------------------------------
		WriteStr.T=WriteSecStr.T+","+WriteErrCodeStr.T+","+elStatBitstr.T
		WriteStr.T=WriteStr.T+CHR($0D)
		'----------------------------------------------------------------------
		'ファイル書込み
		WriteFileName.T="Machine\"+"ERRAnal"+"20"+STR(CM700)+STR(CM701)+"."+"CSV" 'ファイル名
		MPRINT(WriteFileName.T,WriteStr.T,FileErr)
	
		INC(Filewritestep)
		
	case 11
		if FileErr[0] then '完了
			INC(Filewritestep)
		end if
	
	case 12
		if FileErr[1] then '異常終了
		end if
		
		Filewritestep=0
		
	end select

'-----------------------------------------------------------------------------------------------------------------------------
'エラーファイル読み出し

'ErrAnalxxx.CSV
'Lineフレーム		6000181416"",1234"",1"",1"",1"",1"",1"",1"",1"",1""cr
'                     (11),       (5),  (2),(2),(2),(2),(2),(2),(2),(2),1 = 
	select case Filereadstep
	
	case 1

		FindStartSec=sec(FindStart年月日)
		FindEndSec=sec(FindEnd年月日)
	
		ReadFileName.T="Machine\"+"ERRAnal"+"20"+STR(FindStart年月日[0])+STR(FindStart年月日[1])+"."+"CSV"
		initFileread=ON
		linecnt=0
		readpar[0]=0  '最初の行から読込
		readpar[1]=0  '最初の行から読込
		readpar[2]=50 '最大読込文字列

		'クリア
		for loop=0 to 49 step 1
			ErrAnalyzeCode[loop]=0
			ErrAnalyzeCnt[loop]=0
		next		
		
		INC(Filereadstep)
	
	case 2
	
		if initFileread or (readerr[0] and ErrAnalyzestep=0) then
			if MREADL(ReadFileName.T,ReadStr,readpar,readerr) then
				inc(linecnt)
				ReadCnt=SPLIT(ReadStr.T,",",ReadSecStr,ReadErrCodeStr,el自動モードstr,el運転中str,elテスト運転str,el非常t停止str,el前処理運転中str,el自動モードstr,el自動モードstr,el自動モードstr)
				if ReadCnt>=7 then
					ReadSec.D=RDASC(ReadSecStr)
					ReadErrCode.D=RDASC(ReadErrCodeStr)
					if LEN(el自動モードstr)>0 then
						el自動モード.U=RDASC(el自動モードstr)
					else
						el自動モード=0
					end if
					
					if LEN(el運転中str)>0 then
						el運転中.U=RDASC(el運転中str)
					else
						el運転中=0
					end if
					
					if LEN(elテスト運転str)>0 then
						elテスト運転.U=RDASC(elテスト運転str)
					else 
						elテスト運転=0
					end if
					
					if LEN(el非常t停止str)>0 then
						el非常停止.U=RDASC(el非常t停止str)
					else
						el非常停止=0
					end if
					
					if LEN(el前処理運転中str)>0 then
						el前処理運転中.U=RDASC(el前処理運転中str)
					else
						el前処理運転中=0
					end if					
					StackEnablebit=not(pnlPBel自動モード) or (pnlPBel自動モード and el自動モード=1) '自動モードのみ
					StackEnablebit=StackEnablebit and (not(pnlPBel運転中) or (pnlPBel運転中 and el運転中=1)) '運転中のみ
					StackEnablebit=StackEnablebit and (not(pnlPBelテスト運転) or (pnlPBelテスト運転 and elテスト運転=0)) 'テスト運転除外
					StackEnablebit=StackEnablebit and (not(pnlPBel非常停止) or (pnlPBel非常停止 and el非常停止=0)) '非常停止除外
					StackEnablebit=StackEnablebit and (not(pnlPBel前処理運転中) or (pnlPBel前処理運転中 and el前処理運転中=0)) '前処理運転除外
					if pnlPBelALL then
						StackEnablebit=ON
					end if
					'----------------------------------------
					'エラー統計プログラム	
					if ReadSec>=FindStartSec and ReadSec<=FindEndSec then
						if StackEnablebit then
							for loop=0 to 49 step 1
								if ErrAnalyzeCode[loop]=0 or ErrAnalyzeCode[loop]=TOU(ReadErrCode) then
									ErrAnalyzeCode[loop]=TOU(ReadErrCode)
									INC(ErrAnalyzeCnt[loop])
									break
								end if
							next
						end if
					end if
					'----------------------------------------
				end if
				if initFileread or readparstak<>readpar[0] then
					readparstak=readpar[0]
					initFileread=OFF
				else
					ErrAnalyzestep=1
					inc(Filereadstep)		
				end if
				
			end if
		end if

	case 3
		'週検索で月をまたぐ場合にはFindEnd年月日の月のファイルを1日から指定日まで再集計する
		' FindStart年月日 2018年12月29日  FindEnd年月日 2019年1月5日
		' (case1,2) 2018年12月29日~末日（集計）(case3,4) 2019年1月1日~2019年1月5日（再集計）
		
		
		if not(pnlPBel週) or (pnlPBel週 and FindStart年月日[1]=FindEnd年月日[1]) then
			Filereadstep=0
		else 
		
			elFindStart年月日[0]=FindEnd年月日[0]
			elFindStart年月日[1]=FindEnd年月日[1]
			elFindStart年月日[2]=1
			elFindStart年月日[3]=0
			elFindStart年月日[4]=0
			elFindStart年月日[5]=0
			
		
			FindStartSec=sec(elFindStart年月日)
			FindEndSec=sec(FindEnd年月日)
		
			ReadFileName.T="Machine\"+"ERRAnal"+"20"+STR(FindEnd年月日[0])+STR(FindEnd年月日[1])+"."+"CSV"
			initFileread=ON
			linecnt=0
			readpar[0]=0  '最初の行から読込
			readpar[1]=0  '最初の行から読込
			readpar[2]=50 '最大読込文字列

			INC(Filereadstep)
		end if


	case 4

		if initFileread or (readerr[0] and ErrAnalyzestep=0) then
			if MREADL(ReadFileName.T,ReadStr,readpar,readerr) then
				inc(linecnt)
				ReadCnt=SPLIT(ReadStr.T,",",ReadSecStr,ReadErrCodeStr,el自動モードstr,el運転中str,elテスト運転str,el非常t停止str,el前処理運転中str,el自動モードstr,el自動モードstr,el自動モードstr)
				if ReadCnt>=7 then
					ReadSec.D=RDASC(ReadSecStr)
					ReadErrCode.D=RDASC(ReadErrCodeStr)
					if LEN(el自動モードstr)>0 then
						el自動モード.U=RDASC(el自動モードstr)
					else
						el自動モード=0
					end if
					
					if LEN(el運転中str)>0 then
						el運転中.U=RDASC(el運転中str)
					else
						el運転中=0
					end if
					
					if LEN(elテスト運転str)>0 then
						elテスト運転.U=RDASC(elテスト運転str)
					else 
						elテスト運転=0
					end if
					
					if LEN(el非常t停止str)>0 then
						el非常停止.U=RDASC(el非常t停止str)
					else
						el非常停止=0
					end if
					
					if LEN(el前処理運転中str)>0 then
						el前処理運転中.U=RDASC(el前処理運転中str)
					else
						el前処理運転中=0
					end if
					StackEnablebit=not(pnlPBel自動モード) or (pnlPBel自動モード and el自動モード=1) '自動モードのみ
					StackEnablebit=StackEnablebit and (not(pnlPBel運転中) or (pnlPBel運転中 and el運転中=1)) '運転中のみ
					StackEnablebit=StackEnablebit and (not(pnlPBelテスト運転) or (pnlPBelテスト運転 and elテスト運転=0)) 'テスト運転除外
					StackEnablebit=StackEnablebit and (not(pnlPBel非常停止) or (pnlPBel非常停止 and el非常停止=0)) '非常停止除外
					StackEnablebit=StackEnablebit and (not(pnlPBel前処理運転中) or (pnlPBel前処理運転中 and el前処理運転中=0)) '前処理運転除外
					if pnlPBelALL then
						StackEnablebit=ON
					end if
					'----------------------------------------
					'エラー統計プログラム	
					if ReadSec>=FindStartSec and ReadSec<=FindEndSec then
						if StackEnablebit then
							for loop=0 to 49 step 1
								if ErrAnalyzeCode[loop]=0 or ErrAnalyzeCode[loop]=TOU(ReadErrCode) then
									ErrAnalyzeCode[loop]=TOU(ReadErrCode)
									INC(ErrAnalyzeCnt[loop])
									break
								end if
							next
						end if
					end if
					'----------------------------------------
				end if
				if initFileread or readparstak<>readpar[0] then
					readparstak=readpar[0]
					initFileread=OFF
				else
					ErrAnalyzestep=1
					inc(Filereadstep)		
				end if
				
			end if
		end if

	
	case 5
		Filereadstep=0
	end select
	
'-----------------------------------------------------------------------------------------------------------------------------
'Analysis ％計算

	select case ErrAnalyzestep
	
	case 1
		ErrAnlyzeTotalCnt=0
		for anloop=0 to 49 step 1
			ErrAnalyzePersent[anloop]=0
		next
		inc(ErrAnalyzestep)
	case 2
		for anloop=0 to 49 step 1
			ErrAnlyzeTotalCnt=ErrAnlyzeTotalCnt+ ErrAnalyzeCnt[anloop]
		next
		inc(ErrAnalyzestep)	
	case 3
		if ErrAnlyzeTotalCnt>0 then
			for anloop=0 to 49 step 1
			
				if ErrAnalyzeCnt[anloop]>0 then
					ErrAnalyzePersent[anloop]=(ErrAnalyzeCnt[anloop]*10000)/ErrAnlyzeTotalCnt
				else
					ErrAnalyzePersent[anloop]=0
				end if
				
			next
		end if
		inc(ErrAnalyzestep)	
	case 4
		ErrAnalyzestep=0
	end select
'-----------------------------------------------------------------------------------------------------------------------------
if ldp(almSSW3_手動モード) then
    adrset(almSSW3_手動モード,WriteErrAddres)
    WriteAlmstr.T="almSSW3_手動モード"
    Filewritestep=1
end if
if ldp(almSSW3_自動モード) then
    adrset(almSSW3_自動モード,WriteErrAddres)
    WriteAlmstr.T="almSSW3_自動モード"
    Filewritestep=1
end if
if ldp(almRS1_水タンク上限センサー) then
    adrset(almRS1_水タンク上限センサー,WriteErrAddres)
    WriteAlmstr.T="almRS1_水タンク上限センサー"
    Filewritestep=1
end if
if ldp(almTHR5_洗米羽根) then
    adrset(almTHR5_洗米羽根,WriteErrAddres)
    WriteAlmstr.T="almTHR5_洗米羽根"
    Filewritestep=1
end if
if ldp(almTHR4_送米ポンプ) then
    adrset(almTHR4_送米ポンプ,WriteErrAddres)
    WriteAlmstr.T="almTHR4_送米ポンプ"
    Filewritestep=1
end if
if ldp(almDCPLC電源電圧降下) then
    adrset(almDCPLC電源電圧降下,WriteErrAddres)
    WriteAlmstr.T="almDCPLC電源電圧降下"
    Filewritestep=1
end if
if ldp(almDC電源電圧降下1) then
    adrset(almDC電源電圧降下1,WriteErrAddres)
    WriteAlmstr.T="almDC電源電圧降下1"
    Filewritestep=1
end if
if ldp(almDC電源電圧降下2) then
    adrset(almDC電源電圧降下2,WriteErrAddres)
    WriteAlmstr.T="almDC電源電圧降下2"
    Filewritestep=1
end if
if ldp(almPTL1_パトライト赤) then
    adrset(almPTL1_パトライト赤,WriteErrAddres)
    WriteAlmstr.T="almPTL1_パトライト赤"
    Filewritestep=1
end if
if ldp(almPTL1_パトライト黄) then
    adrset(almPTL1_パトライト黄,WriteErrAddres)
    WriteAlmstr.T="almPTL1_パトライト黄"
    Filewritestep=1
end if
if ldp(almPTL1_パトライト青) then
    adrset(almPTL1_パトライト青,WriteErrAddres)
    WriteAlmstr.T="almPTL1_パトライト青"
    Filewritestep=1
end if
if ldp(almPTL1_パトライトブザー) then
    adrset(almPTL1_パトライトブザー,WriteErrAddres)
    WriteAlmstr.T="almPTL1_パトライトブザー"
    Filewritestep=1
end if
if ldp(almRLY_レベルスイッチ用電源) then
    adrset(almRLY_レベルスイッチ用電源,WriteErrAddres)
    WriteAlmstr.T="almRLY_レベルスイッチ用電源"
    Filewritestep=1
end if
if ldp(almMC5_洗米羽根) then
    adrset(almMC5_洗米羽根,WriteErrAddres)
    WriteAlmstr.T="almMC5_洗米羽根"
    Filewritestep=1
end if
if ldp(almMC4_送米ポンプ) then
    adrset(almMC4_送米ポンプ,WriteErrAddres)
    WriteAlmstr.T="almMC4_送米ポンプ"
    Filewritestep=1
end if
if ldp(almSV1_給水電磁弁) then
    adrset(almSV1_給水電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV1_給水電磁弁"
    Filewritestep=1
end if
if ldp(almSV58_洗米バルブA) then
    adrset(almSV58_洗米バルブA,WriteErrAddres)
    WriteAlmstr.T="almSV58_洗米バルブA"
    Filewritestep=1
end if
if ldp(almRLY_電源確認納米庫) then
    adrset(almRLY_電源確認納米庫,WriteErrAddres)
    WriteAlmstr.T="almRLY_電源確認納米庫"
    Filewritestep=1
end if
if ldp(almSSW4_納米庫手動) then
    adrset(almSSW4_納米庫手動,WriteErrAddres)
    WriteAlmstr.T="almSSW4_納米庫手動"
    Filewritestep=1
end if
if ldp(almSSW4_納米庫自動) then
    adrset(almSSW4_納米庫自動,WriteErrAddres)
    WriteAlmstr.T="almSSW4_納米庫自動"
    Filewritestep=1
end if
if ldp(almFLOS2_洗米無洗米切換検知) then
    adrset(almFLOS2_洗米無洗米切換検知,WriteErrAddres)
    WriteAlmstr.T="almFLOS2_洗米無洗米切換検知"
    Filewritestep=1
end if
if ldp(almFLOS1_計量機近接センサー) then
    adrset(almFLOS1_計量機近接センサー,WriteErrAddres)
    WriteAlmstr.T="almFLOS1_計量機近接センサー"
    Filewritestep=1
end if
if ldp(almTHR1_張込用昇降機モータ) then
    adrset(almTHR1_張込用昇降機モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR1_張込用昇降機モータ"
    Filewritestep=1
end if
if ldp(almTHR2_排出用昇降機モータ) then
    adrset(almTHR2_排出用昇降機モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR2_排出用昇降機モータ"
    Filewritestep=1
end if
if ldp(almTHR3_計量機モータ) then
    adrset(almTHR3_計量機モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR3_計量機モータ"
    Filewritestep=1
end if
if ldp(almMC1_張込用昇降機) then
    adrset(almMC1_張込用昇降機,WriteErrAddres)
    WriteAlmstr.T="almMC1_張込用昇降機"
    Filewritestep=1
end if
if ldp(almMC2_排出用昇降機) then
    adrset(almMC2_排出用昇降機,WriteErrAddres)
    WriteAlmstr.T="almMC2_排出用昇降機"
    Filewritestep=1
end if
if ldp(almMC3_計量機) then
    adrset(almMC3_計量機,WriteErrAddres)
    WriteAlmstr.T="almMC3_計量機"
    Filewritestep=1
end if
if ldp(almRLY_浸漬電源確認) then
    adrset(almRLY_浸漬電源確認,WriteErrAddres)
    WriteAlmstr.T="almRLY_浸漬電源確認"
    Filewritestep=1
end if
if ldp(almPS1_エアー圧力) then
    adrset(almPS1_エアー圧力,WriteErrAddres)
    WriteAlmstr.T="almPS1_エアー圧力"
    Filewritestep=1
end if
if ldp(almXSW9_送米切換A側) then
    adrset(almXSW9_送米切換A側,WriteErrAddres)
    WriteAlmstr.T="almXSW9_送米切換A側"
    Filewritestep=1
end if
if ldp(almXSW10_送米切換B側) then
    adrset(almXSW10_送米切換B側,WriteErrAddres)
    WriteAlmstr.T="almXSW10_送米切換B側"
    Filewritestep=1
end if
if ldp(almPDL1_パドルセンサー上限A) then
    adrset(almPDL1_パドルセンサー上限A,WriteErrAddres)
    WriteAlmstr.T="almPDL1_パドルセンサー上限A"
    Filewritestep=1
end if
if ldp(almRLY_光電センサ電源OFF1) then
    adrset(almRLY_光電センサ電源OFF1,WriteErrAddres)
    WriteAlmstr.T="almRLY_光電センサ電源OFF1"
    Filewritestep=1
end if
if ldp(almPTL2_パトライト赤) then
    adrset(almPTL2_パトライト赤,WriteErrAddres)
    WriteAlmstr.T="almPTL2_パトライト赤"
    Filewritestep=1
end if
if ldp(almPTL2_パトライト黄) then
    adrset(almPTL2_パトライト黄,WriteErrAddres)
    WriteAlmstr.T="almPTL2_パトライト黄"
    Filewritestep=1
end if
if ldp(almPTL2_パトライト青) then
    adrset(almPTL2_パトライト青,WriteErrAddres)
    WriteAlmstr.T="almPTL2_パトライト青"
    Filewritestep=1
end if
if ldp(almPTL2_パトライトブザー) then
    adrset(almPTL2_パトライトブザー,WriteErrAddres)
    WriteAlmstr.T="almPTL2_パトライトブザー"
    Filewritestep=1
end if
if ldp(almPDL2_パドルセンサー下限A) then
    adrset(almPDL2_パドルセンサー下限A,WriteErrAddres)
    WriteAlmstr.T="almPDL2_パドルセンサー下限A"
    Filewritestep=1
end if
if ldp(almXSW1_充填バルブ開A) then
    adrset(almXSW1_充填バルブ開A,WriteErrAddres)
    WriteAlmstr.T="almXSW1_充填バルブ開A"
    Filewritestep=1
end if
if ldp(almXSW2_充填バルブ閉A) then
    adrset(almXSW2_充填バルブ閉A,WriteErrAddres)
    WriteAlmstr.T="almXSW2_充填バルブ閉A"
    Filewritestep=1
end if
if ldp(almXSW3_水切りシャッター開A) then
    adrset(almXSW3_水切りシャッター開A,WriteErrAddres)
    WriteAlmstr.T="almXSW3_水切りシャッター開A"
    Filewritestep=1
end if
if ldp(almXSW4_水切りシャッター閉A) then
    adrset(almXSW4_水切りシャッター閉A,WriteErrAddres)
    WriteAlmstr.T="almXSW4_水切りシャッター閉A"
    Filewritestep=1
end if
if ldp(almXSW76_排水バルブ開A) then
    adrset(almXSW76_排水バルブ開A,WriteErrAddres)
    WriteAlmstr.T="almXSW76_排水バルブ開A"
    Filewritestep=1
end if
if ldp(almXSW77_排水バルブ閉A) then
    adrset(almXSW77_排水バルブ閉A,WriteErrAddres)
    WriteAlmstr.T="almXSW77_排水バルブ閉A"
    Filewritestep=1
end if
if ldp(almPDL3_パドルセンサー上限B) then
    adrset(almPDL3_パドルセンサー上限B,WriteErrAddres)
    WriteAlmstr.T="almPDL3_パドルセンサー上限B"
    Filewritestep=1
end if
if ldp(almPDL4_パドルセンサー下限B) then
    adrset(almPDL4_パドルセンサー下限B,WriteErrAddres)
    WriteAlmstr.T="almPDL4_パドルセンサー下限B"
    Filewritestep=1
end if
if ldp(almXSW5_充填バルブ開B) then
    adrset(almXSW5_充填バルブ開B,WriteErrAddres)
    WriteAlmstr.T="almXSW5_充填バルブ開B"
    Filewritestep=1
end if
if ldp(almXSW6_充填バルブ閉B) then
    adrset(almXSW6_充填バルブ閉B,WriteErrAddres)
    WriteAlmstr.T="almXSW6_充填バルブ閉B"
    Filewritestep=1
end if
if ldp(almXSW7_水切りシャッター開B) then
    adrset(almXSW7_水切りシャッター開B,WriteErrAddres)
    WriteAlmstr.T="almXSW7_水切りシャッター開B"
    Filewritestep=1
end if
if ldp(almXSW8_水切りシャッター閉B) then
    adrset(almXSW8_水切りシャッター閉B,WriteErrAddres)
    WriteAlmstr.T="almXSW8_水切りシャッター閉B"
    Filewritestep=1
end if
if ldp(almXSW78_排水バルブ開B) then
    adrset(almXSW78_排水バルブ開B,WriteErrAddres)
    WriteAlmstr.T="almXSW78_排水バルブ開B"
    Filewritestep=1
end if
if ldp(almSV12_送米切換バルブA側) then
    adrset(almSV12_送米切換バルブA側,WriteErrAddres)
    WriteAlmstr.T="almSV12_送米切換バルブA側"
    Filewritestep=1
end if
if ldp(almSV13_送米切換バルブB側) then
    adrset(almSV13_送米切換バルブB側,WriteErrAddres)
    WriteAlmstr.T="almSV13_送米切換バルブB側"
    Filewritestep=1
end if
if ldp(almRLY5_パドルセンサ電源) then
    adrset(almRLY5_パドルセンサ電源,WriteErrAddres)
    WriteAlmstr.T="almRLY5_パドルセンサ電源"
    Filewritestep=1
end if
if ldp(almSV2_充填バルブ開A) then
    adrset(almSV2_充填バルブ開A,WriteErrAddres)
    WriteAlmstr.T="almSV2_充填バルブ開A"
    Filewritestep=1
end if
if ldp(almSV3_充填バルブ閉A) then
    adrset(almSV3_充填バルブ閉A,WriteErrAddres)
    WriteAlmstr.T="almSV3_充填バルブ閉A"
    Filewritestep=1
end if
if ldp(almSV4_水切りシャッター開A) then
    adrset(almSV4_水切りシャッター開A,WriteErrAddres)
    WriteAlmstr.T="almSV4_水切りシャッター開A"
    Filewritestep=1
end if
if ldp(almSV5_水切りシャッター閉A) then
    adrset(almSV5_水切りシャッター閉A,WriteErrAddres)
    WriteAlmstr.T="almSV5_水切りシャッター閉A"
    Filewritestep=1
end if
if ldp(almSV60_排水バルブ開A) then
    adrset(almSV60_排水バルブ開A,WriteErrAddres)
    WriteAlmstr.T="almSV60_排水バルブ開A"
    Filewritestep=1
end if
if ldp(almSV61_排水バルブ閉A) then
    adrset(almSV61_排水バルブ閉A,WriteErrAddres)
    WriteAlmstr.T="almSV61_排水バルブ閉A"
    Filewritestep=1
end if
if ldp(almSV7_充填バルブ開B) then
    adrset(almSV7_充填バルブ開B,WriteErrAddres)
    WriteAlmstr.T="almSV7_充填バルブ開B"
    Filewritestep=1
end if
if ldp(almSV8_充填バルブ閉B) then
    adrset(almSV8_充填バルブ閉B,WriteErrAddres)
    WriteAlmstr.T="almSV8_充填バルブ閉B"
    Filewritestep=1
end if
if ldp(almSV9_水切りシャッター開B) then
    adrset(almSV9_水切りシャッター開B,WriteErrAddres)
    WriteAlmstr.T="almSV9_水切りシャッター開B"
    Filewritestep=1
end if
if ldp(almSV10_水切りシャッター閉B) then
    adrset(almSV10_水切りシャッター閉B,WriteErrAddres)
    WriteAlmstr.T="almSV10_水切りシャッター閉B"
    Filewritestep=1
end if
if ldp(almSV62_排水バルブ開B) then
    adrset(almSV62_排水バルブ開B,WriteErrAddres)
    WriteAlmstr.T="almSV62_排水バルブ開B"
    Filewritestep=1
end if
if ldp(almSV63_排水バルブ閉B) then
    adrset(almSV63_排水バルブ閉B,WriteErrAddres)
    WriteAlmstr.T="almSV63_排水バルブ閉B"
    Filewritestep=1
end if
if ldp(almXSW79_排水バルブ閉B) then
    adrset(almXSW79_排水バルブ閉B,WriteErrAddres)
    WriteAlmstr.T="almXSW79_排水バルブ閉B"
    Filewritestep=1
end if
if ldp(almFLOS3_LMT121ALM) then
    adrset(almFLOS3_LMT121ALM,WriteErrAddres)
    WriteAlmstr.T="almFLOS3_LMT121ALM"
    Filewritestep=1
end if
if ldp(almFLOS4_LMT121ALM) then
    adrset(almFLOS4_LMT121ALM,WriteErrAddres)
    WriteAlmstr.T="almFLOS4_LMT121ALM"
    Filewritestep=1
end if
if ldp(almFLOS3_LMT121) then
    adrset(almFLOS3_LMT121,WriteErrAddres)
    WriteAlmstr.T="almFLOS3_LMT121"
    Filewritestep=1
end if
if ldp(almFLOS4_LMT121) then
    adrset(almFLOS4_LMT121,WriteErrAddres)
    WriteAlmstr.T="almFLOS4_LMT121"
    Filewritestep=1
end if
if ldp(almAD4532_HI) then
    adrset(almAD4532_HI,WriteErrAddres)
    WriteAlmstr.T="almAD4532_HI"
    Filewritestep=1
end if
if ldp(almAD4532_OK) then
    adrset(almAD4532_OK,WriteErrAddres)
    WriteAlmstr.T="almAD4532_OK"
    Filewritestep=1
end if
if ldp(almAD4532_LO) then
    adrset(almAD4532_LO,WriteErrAddres)
    WriteAlmstr.T="almAD4532_LO"
    Filewritestep=1
end if
if ldp(almTHR11_搬送モータ) then
    adrset(almTHR11_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR11_搬送モータ"
    Filewritestep=1
end if
if ldp(almXSW18_リフト上昇端) then
    adrset(almXSW18_リフト上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW18_リフト上昇端"
    Filewritestep=1
end if
if ldp(almXSW17_リフト下降端) then
    adrset(almXSW17_リフト下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW17_リフト下降端"
    Filewritestep=1
end if
if ldp(almPH60_釜検知) then
    adrset(almPH60_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH60_釜検知"
    Filewritestep=1
end if
if ldp(almPH61_フタ検知) then
    adrset(almPH61_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH61_フタ検知"
    Filewritestep=1
end if
if ldp(almAD4532_ZERO) then
    adrset(almAD4532_ZERO,WriteErrAddres)
    WriteAlmstr.T="almAD4532_ZERO"
    Filewritestep=1
end if
if ldp(almAD4532_ON) then
    adrset(almAD4532_ON,WriteErrAddres)
    WriteAlmstr.T="almAD4532_ON"
    Filewritestep=1
end if
if ldp(almAD4532_COMP1) then
    adrset(almAD4532_COMP1,WriteErrAddres)
    WriteAlmstr.T="almAD4532_COMP1"
    Filewritestep=1
end if
if ldp(almAD4532_COMP2) then
    adrset(almAD4532_COMP2,WriteErrAddres)
    WriteAlmstr.T="almAD4532_COMP2"
    Filewritestep=1
end if
if ldp(almSV6_給水電磁弁A) then
    adrset(almSV6_給水電磁弁A,WriteErrAddres)
    WriteAlmstr.T="almSV6_給水電磁弁A"
    Filewritestep=1
end if
if ldp(almSV11_給水電磁弁B) then
    adrset(almSV11_給水電磁弁B,WriteErrAddres)
    WriteAlmstr.T="almSV11_給水電磁弁B"
    Filewritestep=1
end if
if ldp(almSV17_計水タンク給水（大）) then
    adrset(almSV17_計水タンク給水（大）,WriteErrAddres)
    WriteAlmstr.T="almSV17_計水タンク給水（大）"
    Filewritestep=1
end if
if ldp(almSV18_計水タンク給水（小）) then
    adrset(almSV18_計水タンク給水（小）,WriteErrAddres)
    WriteAlmstr.T="almSV18_計水タンク給水（小）"
    Filewritestep=1
end if
if ldp(almSV19_計水電磁弁_A) then
    adrset(almSV19_計水電磁弁_A,WriteErrAddres)
    WriteAlmstr.T="almSV19_計水電磁弁_A"
    Filewritestep=1
end if
if ldp(almSV64_計水電磁弁_B) then
    adrset(almSV64_計水電磁弁_B,WriteErrAddres)
    WriteAlmstr.T="almSV64_計水電磁弁_B"
    Filewritestep=1
end if
if ldp(almTHR6_搬送モータ) then
    adrset(almTHR6_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR6_搬送モータ"
    Filewritestep=1
end if
if ldp(almTHR7_搬送モータ) then
    adrset(almTHR7_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR7_搬送モータ"
    Filewritestep=1
end if
if ldp(almTHR8_搬送モータ) then
    adrset(almTHR8_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR8_搬送モータ"
    Filewritestep=1
end if
if ldp(almPH1_釜検知) then
    adrset(almPH1_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH1_釜検知"
    Filewritestep=1
end if
if ldp(almPH2_フタ検知) then
    adrset(almPH2_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH2_フタ検知"
    Filewritestep=1
end if
if ldp(almPH3_釜検知) then
    adrset(almPH3_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH3_釜検知"
    Filewritestep=1
end if
if ldp(almPH4_フタ検知) then
    adrset(almPH4_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH4_フタ検知"
    Filewritestep=1
end if
if ldp(almPH5_釜検知) then
    adrset(almPH5_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH5_釜検知"
    Filewritestep=1
end if
if ldp(almPH6_フタ検知) then
    adrset(almPH6_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH6_フタ検知"
    Filewritestep=1
end if
if ldp(almPH7_釜検知) then
    adrset(almPH7_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH7_釜検知"
    Filewritestep=1
end if
if ldp(almPH8_フタ検知) then
    adrset(almPH8_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH8_フタ検知"
    Filewritestep=1
end if
if ldp(almXSW14_ストッパ上昇端) then
    adrset(almXSW14_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW14_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almXSW15_ストッパ下降端) then
    adrset(almXSW15_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW15_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW16_ストッパ上昇端) then
    adrset(almXSW16_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW16_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almXSW17_ストッパ下降端) then
    adrset(almXSW17_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW17_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almMC6_搬送モータ) then
    adrset(almMC6_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC6_搬送モータ"
    Filewritestep=1
end if
if ldp(almMC7_搬送モータ) then
    adrset(almMC7_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC7_搬送モータ"
    Filewritestep=1
end if
if ldp(almMC8_搬送モータ) then
    adrset(almMC8_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC8_搬送モータ"
    Filewritestep=1
end if
if ldp(almSV14_ストッパ上昇) then
    adrset(almSV14_ストッパ上昇,WriteErrAddres)
    WriteAlmstr.T="almSV14_ストッパ上昇"
    Filewritestep=1
end if
if ldp(almSV15_ストッパ下降) then
    adrset(almSV15_ストッパ下降,WriteErrAddres)
    WriteAlmstr.T="almSV15_ストッパ下降"
    Filewritestep=1
end if
if ldp(almSV64_ストッパ上昇) then
    adrset(almSV64_ストッパ上昇,WriteErrAddres)
    WriteAlmstr.T="almSV64_ストッパ上昇"
    Filewritestep=1
end if
if ldp(almSV70_ストッパ下降) then
    adrset(almSV70_ストッパ下降,WriteErrAddres)
    WriteAlmstr.T="almSV70_ストッパ下降"
    Filewritestep=1
end if
if ldp(almSV20_リフト上昇) then
    adrset(almSV20_リフト上昇,WriteErrAddres)
    WriteAlmstr.T="almSV20_リフト上昇"
    Filewritestep=1
end if
if ldp(almMC11_搬送モータ) then
    adrset(almMC11_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC11_搬送モータ"
    Filewritestep=1
end if
if ldp(almSV32_リフト下降) then
    adrset(almSV32_リフト下降,WriteErrAddres)
    WriteAlmstr.T="almSV32_リフト下降"
    Filewritestep=1
end if
if ldp(almTHR9_モータローラ) then
    adrset(almTHR9_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR9_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR12_搬送モータ) then
    adrset(almTHR12_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR12_搬送モータ"
    Filewritestep=1
end if
if ldp(almTHR13_搬送モータ) then
    adrset(almTHR13_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR13_搬送モータ"
    Filewritestep=1
end if
if ldp(almTHR16_モータローラ) then
    adrset(almTHR16_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR16_モータローラ"
    Filewritestep=1
end if
if ldp(almPH9_釜検知) then
    adrset(almPH9_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH9_釜検知"
    Filewritestep=1
end if
if ldp(almPH10_フタ検知) then
    adrset(almPH10_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH10_フタ検知"
    Filewritestep=1
end if
if ldp(almPH11_釜検知) then
    adrset(almPH11_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH11_釜検知"
    Filewritestep=1
end if
if ldp(almPH12_フタ検知) then
    adrset(almPH12_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH12_フタ検知"
    Filewritestep=1
end if
if ldp(almPH13_釜検知) then
    adrset(almPH13_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH13_釜検知"
    Filewritestep=1
end if
if ldp(almPH14_フタ検知) then
    adrset(almPH14_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH14_フタ検知"
    Filewritestep=1
end if
if ldp(almPH16_フタ検知) then
    adrset(almPH16_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH16_フタ検知"
    Filewritestep=1
end if
if ldp(almPH15_釜検知) then
    adrset(almPH15_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH15_釜検知"
    Filewritestep=1
end if
if ldp(almXSW18_ストッパ上昇端) then
    adrset(almXSW18_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW18_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almXSW19_ストッパ下降端) then
    adrset(almXSW19_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW19_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW21_リフト上昇端) then
    adrset(almXSW21_リフト上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW21_リフト上昇端"
    Filewritestep=1
end if
if ldp(almXSW20_リフト下降端) then
    adrset(almXSW20_リフト下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW20_リフト下降端"
    Filewritestep=1
end if
if ldp(almMC9_モータローラ) then
    adrset(almMC9_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC9_モータローラ"
    Filewritestep=1
end if
if ldp(almMC12_搬送モータ) then
    adrset(almMC12_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC12_搬送モータ"
    Filewritestep=1
end if
if ldp(almMC13_搬送モータ) then
    adrset(almMC13_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC13_搬送モータ"
    Filewritestep=1
end if
if ldp(almMC16_モータローラ) then
    adrset(almMC16_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC16_モータローラ"
    Filewritestep=1
end if
if ldp(almSV21_リフト) then
    adrset(almSV21_リフト,WriteErrAddres)
    WriteAlmstr.T="almSV21_リフト"
    Filewritestep=1
end if
if ldp(almSV51_ストッパ) then
    adrset(almSV51_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV51_ストッパ"
    Filewritestep=1
end if
if ldp(almSV22_ストッパ) then
    adrset(almSV22_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV22_ストッパ"
    Filewritestep=1
end if
if ldp(almSV23_リフト) then
    adrset(almSV23_リフト,WriteErrAddres)
    WriteAlmstr.T="almSV23_リフト"
    Filewritestep=1
end if
if ldp(almMC14_搬送モータ) then
    adrset(almMC14_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC14_搬送モータ"
    Filewritestep=1
end if
if ldp(almMC15_搬送モータ) then
    adrset(almMC15_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC15_搬送モータ"
    Filewritestep=1
end if
if ldp(almMC34_モータローラ) then
    adrset(almMC34_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC34_モータローラ"
    Filewritestep=1
end if
if ldp(almSV24_クランプ) then
    adrset(almSV24_クランプ,WriteErrAddres)
    WriteAlmstr.T="almSV24_クランプ"
    Filewritestep=1
end if
if ldp(almSV25_ストッパ) then
    adrset(almSV25_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV25_ストッパ"
    Filewritestep=1
end if
if ldp(almSV26_クランプ) then
    adrset(almSV26_クランプ,WriteErrAddres)
    WriteAlmstr.T="almSV26_クランプ"
    Filewritestep=1
end if
if ldp(almSV27_ストッパ) then
    adrset(almSV27_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV27_ストッパ"
    Filewritestep=1
end if
if ldp(almSV28_リフト) then
    adrset(almSV28_リフト,WriteErrAddres)
    WriteAlmstr.T="almSV28_リフト"
    Filewritestep=1
end if
if ldp(almXSW23_ストッパ上昇端) then
    adrset(almXSW23_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW23_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almXSW22_ストッパ下降端) then
    adrset(almXSW22_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW22_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW25_リフト上昇端) then
    adrset(almXSW25_リフト上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW25_リフト上昇端"
    Filewritestep=1
end if
if ldp(almXSW24_リフト下降端) then
    adrset(almXSW24_リフト下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW24_リフト下降端"
    Filewritestep=1
end if
if ldp(almRLY_搬送1電源確認) then
    adrset(almRLY_搬送1電源確認,WriteErrAddres)
    WriteAlmstr.T="almRLY_搬送1電源確認"
    Filewritestep=1
end if
if ldp(almTHR14_搬送モータ) then
    adrset(almTHR14_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR14_搬送モータ"
    Filewritestep=1
end if
if ldp(almTHR15_搬送モータ) then
    adrset(almTHR15_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR15_搬送モータ"
    Filewritestep=1
end if
if ldp(almTHR34_モータローラ) then
    adrset(almTHR34_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR34_モータローラ"
    Filewritestep=1
end if
if ldp(almPH17_釜検知) then
    adrset(almPH17_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH17_釜検知"
    Filewritestep=1
end if
if ldp(almPH18_フタ検知) then
    adrset(almPH18_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH18_フタ検知"
    Filewritestep=1
end if
if ldp(almPH19_釜検知) then
    adrset(almPH19_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH19_釜検知"
    Filewritestep=1
end if
if ldp(almPH20_フタ検知) then
    adrset(almPH20_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH20_フタ検知"
    Filewritestep=1
end if
if ldp(almPH21_釜検知) then
    adrset(almPH21_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH21_釜検知"
    Filewritestep=1
end if
if ldp(almPH22_釜検知) then
    adrset(almPH22_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH22_釜検知"
    Filewritestep=1
end if
if ldp(almXSW26_クランプ下降端) then
    adrset(almXSW26_クランプ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW26_クランプ下降端"
    Filewritestep=1
end if
if ldp(almXSW27_クランプ上昇端) then
    adrset(almXSW27_クランプ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW27_クランプ上昇端"
    Filewritestep=1
end if
if ldp(almSV29_ストッパ) then
    adrset(almSV29_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV29_ストッパ"
    Filewritestep=1
end if
if ldp(almMC40_ならしモータ) then
    adrset(almMC40_ならしモータ,WriteErrAddres)
    WriteAlmstr.T="almMC40_ならしモータ"
    Filewritestep=1
end if
if ldp(almSV26_ならし上昇) then
    adrset(almSV26_ならし上昇,WriteErrAddres)
    WriteAlmstr.T="almSV26_ならし上昇"
    Filewritestep=1
end if
if ldp(almSV25_ならし下降) then
    adrset(almSV25_ならし下降,WriteErrAddres)
    WriteAlmstr.T="almSV25_ならし下降"
    Filewritestep=1
end if
if ldp(almSV23_ならし前進) then
    adrset(almSV23_ならし前進,WriteErrAddres)
    WriteAlmstr.T="almSV23_ならし前進"
    Filewritestep=1
end if
if ldp(almSV24_ならし後退) then
    adrset(almSV24_ならし後退,WriteErrAddres)
    WriteAlmstr.T="almSV24_ならし後退"
    Filewritestep=1
end if
if ldp(almSV34_シリンダ上昇A) then
    adrset(almSV34_シリンダ上昇A,WriteErrAddres)
    WriteAlmstr.T="almSV34_シリンダ上昇A"
    Filewritestep=1
end if
if ldp(almSV35_シリンダ下降A) then
    adrset(almSV35_シリンダ下降A,WriteErrAddres)
    WriteAlmstr.T="almSV35_シリンダ下降A"
    Filewritestep=1
end if
if ldp(almSV36_シリンダ上昇B) then
    adrset(almSV36_シリンダ上昇B,WriteErrAddres)
    WriteAlmstr.T="almSV36_シリンダ上昇B"
    Filewritestep=1
end if
if ldp(almSV37_シリンダ下降B) then
    adrset(almSV37_シリンダ下降B,WriteErrAddres)
    WriteAlmstr.T="almSV37_シリンダ下降B"
    Filewritestep=1
end if
if ldp(almSV39_アンクランプ) then
    adrset(almSV39_アンクランプ,WriteErrAddres)
    WriteAlmstr.T="almSV39_アンクランプ"
    Filewritestep=1
end if
if ldp(almSV38_クランプ) then
    adrset(almSV38_クランプ,WriteErrAddres)
    WriteAlmstr.T="almSV38_クランプ"
    Filewritestep=1
end if
if ldp(almMC44_モータローラ) then
    adrset(almMC44_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC44_モータローラ"
    Filewritestep=1
end if
if ldp(almXSW28_ストッパ下降端) then
    adrset(almXSW28_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW28_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW29_ストッパ上昇端) then
    adrset(almXSW29_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW29_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almXSW30_クランプ下降端) then
    adrset(almXSW30_クランプ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW30_クランプ下降端"
    Filewritestep=1
end if
if ldp(almXSW31_クランプ上昇端) then
    adrset(almXSW31_クランプ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW31_クランプ上昇端"
    Filewritestep=1
end if
if ldp(almXSW32_ストッパ下降端) then
    adrset(almXSW32_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW32_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW33_ストッパ上昇端) then
    adrset(almXSW33_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW33_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almXSW34_リフト上昇端) then
    adrset(almXSW34_リフト上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW34_リフト上昇端"
    Filewritestep=1
end if
if ldp(almXSW35_リフト下降端) then
    adrset(almXSW35_リフト下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW35_リフト下降端"
    Filewritestep=1
end if
if ldp(almXSW36_ストッパ下降端) then
    adrset(almXSW36_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW36_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW37_ストッパ上昇端) then
    adrset(almXSW37_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW37_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almPS2_エアー圧力) then
    adrset(almPS2_エアー圧力,WriteErrAddres)
    WriteAlmstr.T="almPS2_エアー圧力"
    Filewritestep=1
end if
if ldp(almTHR44_モータローラ) then
    adrset(almTHR44_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR44_モータローラ"
    Filewritestep=1
end if
if ldp(almPH23_釜検知) then
    adrset(almPH23_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH23_釜検知"
    Filewritestep=1
end if
if ldp(almPS4_エアー圧力) then
    adrset(almPS4_エアー圧力,WriteErrAddres)
    WriteAlmstr.T="almPS4_エアー圧力"
    Filewritestep=1
end if
if ldp(almMC45_搬送モータ) then
    adrset(almMC45_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC45_搬送モータ"
    Filewritestep=1
end if
if ldp(almMC46_モータローラ) then
    adrset(almMC46_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC46_モータローラ"
    Filewritestep=1
end if
if ldp(almSV42_ストッパ) then
    adrset(almSV42_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV42_ストッパ"
    Filewritestep=1
end if
if ldp(almSV43_リフト) then
    adrset(almSV43_リフト,WriteErrAddres)
    WriteAlmstr.T="almSV43_リフト"
    Filewritestep=1
end if
if ldp(almRLY_光電センサ電源OFF2) then
    adrset(almRLY_光電センサ電源OFF2,WriteErrAddres)
    WriteAlmstr.T="almRLY_光電センサ電源OFF2"
    Filewritestep=1
end if
if ldp(almTHR40_ならしモータ) then
    adrset(almTHR40_ならしモータ,WriteErrAddres)
    WriteAlmstr.T="almTHR40_ならしモータ"
    Filewritestep=1
end if
if ldp(almXSW25_ならし上昇端) then
    adrset(almXSW25_ならし上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW25_ならし上昇端"
    Filewritestep=1
end if
if ldp(almXSW26_ならし下降端) then
    adrset(almXSW26_ならし下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW26_ならし下降端"
    Filewritestep=1
end if
if ldp(almXSW24_ならし前進端) then
    adrset(almXSW24_ならし前進端,WriteErrAddres)
    WriteAlmstr.T="almXSW24_ならし前進端"
    Filewritestep=1
end if
if ldp(almXSW23_ならし後退端) then
    adrset(almXSW23_ならし後退端,WriteErrAddres)
    WriteAlmstr.T="almXSW23_ならし後退端"
    Filewritestep=1
end if
if ldp(almXSW44_ならし原点センサ) then
    adrset(almXSW44_ならし原点センサ,WriteErrAddres)
    WriteAlmstr.T="almXSW44_ならし原点センサ"
    Filewritestep=1
end if
if ldp(almXSW39_シリンダ上昇端A) then
    adrset(almXSW39_シリンダ上昇端A,WriteErrAddres)
    WriteAlmstr.T="almXSW39_シリンダ上昇端A"
    Filewritestep=1
end if
if ldp(almXSW40_シリンダ下降端A) then
    adrset(almXSW40_シリンダ下降端A,WriteErrAddres)
    WriteAlmstr.T="almXSW40_シリンダ下降端A"
    Filewritestep=1
end if
if ldp(almXSW41_シリンダ上昇端B) then
    adrset(almXSW41_シリンダ上昇端B,WriteErrAddres)
    WriteAlmstr.T="almXSW41_シリンダ上昇端B"
    Filewritestep=1
end if
if ldp(almXSW42_シリンダ下降端B) then
    adrset(almXSW42_シリンダ下降端B,WriteErrAddres)
    WriteAlmstr.T="almXSW42_シリンダ下降端B"
    Filewritestep=1
end if
if ldp(almXSW44_アンクランプ) then
    adrset(almXSW44_アンクランプ,WriteErrAddres)
    WriteAlmstr.T="almXSW44_アンクランプ"
    Filewritestep=1
end if
if ldp(almXSW43_クランプ) then
    adrset(almXSW43_クランプ,WriteErrAddres)
    WriteAlmstr.T="almXSW43_クランプ"
    Filewritestep=1
end if
if ldp(almTHR45_搬送モータ) then
    adrset(almTHR45_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR45_搬送モータ"
    Filewritestep=1
end if
if ldp(almTHR46_モータローラ) then
    adrset(almTHR46_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR46_モータローラ"
    Filewritestep=1
end if
if ldp(almXSW51_ストッパ上昇端) then
    adrset(almXSW51_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW51_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almXSW52_ストッパ下降端) then
    adrset(almXSW52_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW52_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW53_リフト上昇端) then
    adrset(almXSW53_リフト上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW53_リフト上昇端"
    Filewritestep=1
end if
if ldp(almXSW54_リフト下降端) then
    adrset(almXSW54_リフト下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW54_リフト下降端"
    Filewritestep=1
end if
if ldp(almPH24_釜検知) then
    adrset(almPH24_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH24_釜検知"
    Filewritestep=1
end if
if ldp(almIH炊飯機A) then
    adrset(almIH炊飯機A,WriteErrAddres)
    WriteAlmstr.T="almIH炊飯機A"
    Filewritestep=1
end if
if ldp(almIH炊飯機B) then
    adrset(almIH炊飯機B,WriteErrAddres)
    WriteAlmstr.T="almIH炊飯機B"
    Filewritestep=1
end if
if ldp(almTHR17_モータローラ) then
    adrset(almTHR17_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR17_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR18_モータローラ) then
    adrset(almTHR18_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR18_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR19_モータローラ) then
    adrset(almTHR19_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR19_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR20_モータローラ) then
    adrset(almTHR20_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR20_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR21_モータローラ) then
    adrset(almTHR21_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR21_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR22_モータローラ) then
    adrset(almTHR22_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR22_モータローラ"
    Filewritestep=1
end if
if ldp(almPH25_釜検知) then
    adrset(almPH25_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH25_釜検知"
    Filewritestep=1
end if
if ldp(almPH26_釜検知) then
    adrset(almPH26_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH26_釜検知"
    Filewritestep=1
end if
if ldp(almPH27_釜検知) then
    adrset(almPH27_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH27_釜検知"
    Filewritestep=1
end if
if ldp(almPH28_釜検知) then
    adrset(almPH28_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH28_釜検知"
    Filewritestep=1
end if
if ldp(almPH29_釜検知) then
    adrset(almPH29_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH29_釜検知"
    Filewritestep=1
end if
if ldp(almPH30_釜検知) then
    adrset(almPH30_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH30_釜検知"
    Filewritestep=1
end if
if ldp(almRLY_F1A電源確認) then
    adrset(almRLY_F1A電源確認,WriteErrAddres)
    WriteAlmstr.T="almRLY_F1A電源確認"
    Filewritestep=1
end if
if ldp(almMC17_モータローラ) then
    adrset(almMC17_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC17_モータローラ"
    Filewritestep=1
end if
if ldp(almMC18_モータローラ) then
    adrset(almMC18_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC18_モータローラ"
    Filewritestep=1
end if
if ldp(almMC19_モータローラ) then
    adrset(almMC19_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC19_モータローラ"
    Filewritestep=1
end if
if ldp(almMC20_モータローラ) then
    adrset(almMC20_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC20_モータローラ"
    Filewritestep=1
end if
if ldp(almMC21_モータローラ) then
    adrset(almMC21_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC21_モータローラ"
    Filewritestep=1
end if
if ldp(almMC22_モータローラ) then
    adrset(almMC22_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC22_モータローラ"
    Filewritestep=1
end if
if ldp(almRLY_光電センサ電源OFF3) then
    adrset(almRLY_光電センサ電源OFF3,WriteErrAddres)
    WriteAlmstr.T="almRLY_光電センサ電源OFF3"
    Filewritestep=1
end if
if ldp(almTHR23_モータローラ) then
    adrset(almTHR23_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR23_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR24_モータローラ) then
    adrset(almTHR24_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR24_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR25_モータローラ) then
    adrset(almTHR25_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR25_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR26_モータローラ) then
    adrset(almTHR26_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR26_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR27_モータローラ) then
    adrset(almTHR27_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR27_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR28_モータローラ) then
    adrset(almTHR28_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR28_モータローラ"
    Filewritestep=1
end if
if ldp(almPH31_釜検知) then
    adrset(almPH31_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH31_釜検知"
    Filewritestep=1
end if
if ldp(almPH32_釜検知) then
    adrset(almPH32_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH32_釜検知"
    Filewritestep=1
end if
if ldp(almPH33_釜検知) then
    adrset(almPH33_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH33_釜検知"
    Filewritestep=1
end if
if ldp(almPH34_釜検知) then
    adrset(almPH34_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH34_釜検知"
    Filewritestep=1
end if
if ldp(almPH35_釜検知) then
    adrset(almPH35_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH35_釜検知"
    Filewritestep=1
end if
if ldp(almPH36_釜検知) then
    adrset(almPH36_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH36_釜検知"
    Filewritestep=1
end if
if ldp(almRLY_F1B電源確認) then
    adrset(almRLY_F1B電源確認,WriteErrAddres)
    WriteAlmstr.T="almRLY_F1B電源確認"
    Filewritestep=1
end if
if ldp(almMC23_モータローラ) then
    adrset(almMC23_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC23_モータローラ"
    Filewritestep=1
end if
if ldp(almMC24_モータローラ) then
    adrset(almMC24_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC24_モータローラ"
    Filewritestep=1
end if
if ldp(almMC25_モータローラ) then
    adrset(almMC25_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC25_モータローラ"
    Filewritestep=1
end if
if ldp(almMC26_モータローラ) then
    adrset(almMC26_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC26_モータローラ"
    Filewritestep=1
end if
if ldp(almMC27_モータローラ) then
    adrset(almMC27_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC27_モータローラ"
    Filewritestep=1
end if
if ldp(almMC28_モータローラ) then
    adrset(almMC28_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC28_モータローラ"
    Filewritestep=1
end if
if ldp(almRLY_光電センサ電源OFF4) then
    adrset(almRLY_光電センサ電源OFF4,WriteErrAddres)
    WriteAlmstr.T="almRLY_光電センサ電源OFF4"
    Filewritestep=1
end if
if ldp(almTHR29_モータローラ) then
    adrset(almTHR29_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR29_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR30_モータローラ) then
    adrset(almTHR30_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR30_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR31_モータローラ) then
    adrset(almTHR31_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR31_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR32_モータローラ) then
    adrset(almTHR32_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR32_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR33_モータローラ) then
    adrset(almTHR33_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR33_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR47_モータローラ) then
    adrset(almTHR47_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR47_モータローラ"
    Filewritestep=1
end if
if ldp(almPH37_釜検知) then
    adrset(almPH37_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH37_釜検知"
    Filewritestep=1
end if
if ldp(almPH38_釜検知) then
    adrset(almPH38_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH38_釜検知"
    Filewritestep=1
end if
if ldp(almPH39_釜検知) then
    adrset(almPH39_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH39_釜検知"
    Filewritestep=1
end if
if ldp(almPH40_釜検知) then
    adrset(almPH40_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH40_釜検知"
    Filewritestep=1
end if
if ldp(almPH41_釜検知) then
    adrset(almPH41_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH41_釜検知"
    Filewritestep=1
end if
if ldp(almPH42_釜検知) then
    adrset(almPH42_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH42_釜検知"
    Filewritestep=1
end if
if ldp(almRLY_F2A電源確認) then
    adrset(almRLY_F2A電源確認,WriteErrAddres)
    WriteAlmstr.T="almRLY_F2A電源確認"
    Filewritestep=1
end if
if ldp(almMC29_モータローラ) then
    adrset(almMC29_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC29_モータローラ"
    Filewritestep=1
end if
if ldp(almMC30_モータローラ) then
    adrset(almMC30_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC30_モータローラ"
    Filewritestep=1
end if
if ldp(almMC31_モータローラ) then
    adrset(almMC31_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC31_モータローラ"
    Filewritestep=1
end if
if ldp(almMC32_モータローラ) then
    adrset(almMC32_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC32_モータローラ"
    Filewritestep=1
end if
if ldp(almMC33_モータローラ) then
    adrset(almMC33_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC33_モータローラ"
    Filewritestep=1
end if
if ldp(almMC47_モータローラ) then
    adrset(almMC47_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC47_モータローラ"
    Filewritestep=1
end if
if ldp(almRLY_光電センサ電源OFF5) then
    adrset(almRLY_光電センサ電源OFF5,WriteErrAddres)
    WriteAlmstr.T="almRLY_光電センサ電源OFF5"
    Filewritestep=1
end if
if ldp(almTHR48_モータローラ) then
    adrset(almTHR48_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR48_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR49_モータローラ) then
    adrset(almTHR49_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR49_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR50_モータローラ) then
    adrset(almTHR50_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR50_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR51_モータローラ) then
    adrset(almTHR51_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR51_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR52_モータローラ) then
    adrset(almTHR52_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR52_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR53_モータローラ) then
    adrset(almTHR53_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR53_モータローラ"
    Filewritestep=1
end if
if ldp(almPH43_釜検知) then
    adrset(almPH43_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH43_釜検知"
    Filewritestep=1
end if
if ldp(almPH44_釜検知) then
    adrset(almPH44_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH44_釜検知"
    Filewritestep=1
end if
if ldp(almPH45_釜検知) then
    adrset(almPH45_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH45_釜検知"
    Filewritestep=1
end if
if ldp(almPH46_釜検知) then
    adrset(almPH46_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH46_釜検知"
    Filewritestep=1
end if
if ldp(almPH47_釜検知) then
    adrset(almPH47_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH47_釜検知"
    Filewritestep=1
end if
if ldp(almPH48_釜検知) then
    adrset(almPH48_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH48_釜検知"
    Filewritestep=1
end if
if ldp(almRLY_F2B電源確認) then
    adrset(almRLY_F2B電源確認,WriteErrAddres)
    WriteAlmstr.T="almRLY_F2B電源確認"
    Filewritestep=1
end if
if ldp(almMC48_モータローラ) then
    adrset(almMC48_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC48_モータローラ"
    Filewritestep=1
end if
if ldp(almMC49_モータローラ) then
    adrset(almMC49_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC49_モータローラ"
    Filewritestep=1
end if
if ldp(almMC50_モータローラ) then
    adrset(almMC50_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC50_モータローラ"
    Filewritestep=1
end if
if ldp(almMC51_モータローラ) then
    adrset(almMC51_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC51_モータローラ"
    Filewritestep=1
end if
if ldp(almMC52_モータローラ) then
    adrset(almMC52_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC52_モータローラ"
    Filewritestep=1
end if
if ldp(almMC53_モータローラ) then
    adrset(almMC53_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC53_モータローラ"
    Filewritestep=1
end if
if ldp(almRLY_光電センサ電源OFF6) then
    adrset(almRLY_光電センサ電源OFF6,WriteErrAddres)
    WriteAlmstr.T="almRLY_光電センサ電源OFF6"
    Filewritestep=1
end if
if ldp(almTHR41_モータローラ) then
    adrset(almTHR41_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR41_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR42_モータローラ) then
    adrset(almTHR42_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR42_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR43_搬送モータ) then
    adrset(almTHR43_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR43_搬送モータ"
    Filewritestep=1
end if
if ldp(almPH49_釜検知) then
    adrset(almPH49_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH49_釜検知"
    Filewritestep=1
end if
if ldp(almPH50_釜検知) then
    adrset(almPH50_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH50_釜検知"
    Filewritestep=1
end if
if ldp(almPH51_釜検知) then
    adrset(almPH51_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH51_釜検知"
    Filewritestep=1
end if
if ldp(almPH52_フタ検知) then
    adrset(almPH52_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH52_フタ検知"
    Filewritestep=1
end if
if ldp(almXSW55_リフト上昇端) then
    adrset(almXSW55_リフト上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW55_リフト上昇端"
    Filewritestep=1
end if
if ldp(almXSW56_リフト下降端) then
    adrset(almXSW56_リフト下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW56_リフト下降端"
    Filewritestep=1
end if
if ldp(almXSW57_リフト上昇端) then
    adrset(almXSW57_リフト上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW57_リフト上昇端"
    Filewritestep=1
end if
if ldp(almXSW58_リフト下降端) then
    adrset(almXSW58_リフト下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW58_リフト下降端"
    Filewritestep=1
end if
if ldp(almXSW59_ストッパ上昇端) then
    adrset(almXSW59_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW59_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almXSW60_ストッパ下降端) then
    adrset(almXSW60_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW60_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW61_ストッパ上昇端) then
    adrset(almXSW61_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW61_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almXSW62_ストッパ下降端) then
    adrset(almXSW62_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW62_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW63_ストッパ上昇端) then
    adrset(almXSW63_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW63_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almMC41_モータローラ) then
    adrset(almMC41_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC41_モータローラ"
    Filewritestep=1
end if
if ldp(almMC42_モータローラ) then
    adrset(almMC42_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC42_モータローラ"
    Filewritestep=1
end if
if ldp(almMC43_搬送モータ) then
    adrset(almMC43_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC43_搬送モータ"
    Filewritestep=1
end if
if ldp(almSV44_ストッパ) then
    adrset(almSV44_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV44_ストッパ"
    Filewritestep=1
end if
if ldp(almSV45_ストッパ) then
    adrset(almSV45_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV45_ストッパ"
    Filewritestep=1
end if
if ldp(almSV46_ストッパ) then
    adrset(almSV46_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV46_ストッパ"
    Filewritestep=1
end if
if ldp(almSV47_リフト) then
    adrset(almSV47_リフト,WriteErrAddres)
    WriteAlmstr.T="almSV47_リフト"
    Filewritestep=1
end if
if ldp(almSV48_リフト) then
    adrset(almSV48_リフト,WriteErrAddres)
    WriteAlmstr.T="almSV48_リフト"
    Filewritestep=1
end if
if ldp(almMC54_モータローラ) then
    adrset(almMC54_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC54_モータローラ"
    Filewritestep=1
end if
if ldp(almMC10_搬送モータ正転) then
    adrset(almMC10_搬送モータ正転,WriteErrAddres)
    WriteAlmstr.T="almMC10_搬送モータ正転"
    Filewritestep=1
end if
if ldp(almMC10_搬送モータ逆転) then
    adrset(almMC10_搬送モータ逆転,WriteErrAddres)
    WriteAlmstr.T="almMC10_搬送モータ逆転"
    Filewritestep=1
end if
if ldp(almMC55_搬送モータ) then
    adrset(almMC55_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC55_搬送モータ"
    Filewritestep=1
end if
if ldp(almSV49_ストッパ) then
    adrset(almSV49_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV49_ストッパ"
    Filewritestep=1
end if
if ldp(almSV50_リフト) then
    adrset(almSV50_リフト,WriteErrAddres)
    WriteAlmstr.T="almSV50_リフト"
    Filewritestep=1
end if
if ldp(almXSW64_ストッパ下降端) then
    adrset(almXSW64_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW64_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almPS3_エアー圧力) then
    adrset(almPS3_エアー圧力,WriteErrAddres)
    WriteAlmstr.T="almPS3_エアー圧力"
    Filewritestep=1
end if
if ldp(almTHR54_モータローラ) then
    adrset(almTHR54_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almTHR54_モータローラ"
    Filewritestep=1
end if
if ldp(almTHR10_搬送モータ) then
    adrset(almTHR10_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR10_搬送モータ"
    Filewritestep=1
end if
if ldp(almTHR55_搬送モータ) then
    adrset(almTHR55_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR55_搬送モータ"
    Filewritestep=1
end if
if ldp(almPH53_釜検知) then
    adrset(almPH53_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH53_釜検知"
    Filewritestep=1
end if
if ldp(almPH54_フタ検知) then
    adrset(almPH54_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH54_フタ検知"
    Filewritestep=1
end if
if ldp(almXSW65_ストッパ上昇端) then
    adrset(almXSW65_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW65_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almXSW66_ストッパ下降端) then
    adrset(almXSW66_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW66_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW67_リフト上昇端) then
    adrset(almXSW67_リフト上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW67_リフト上昇端"
    Filewritestep=1
end if
if ldp(almXSW68_リフト下降端) then
    adrset(almXSW68_リフト下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW68_リフト下降端"
    Filewritestep=1
end if
if ldp(almRLY_搬送2電源確認) then
    adrset(almRLY_搬送2電源確認,WriteErrAddres)
    WriteAlmstr.T="almRLY_搬送2電源確認"
    Filewritestep=1
end if
if ldp(almTHR56_ブラシサーマル) then
    adrset(almTHR56_ブラシサーマル,WriteErrAddres)
    WriteAlmstr.T="almTHR56_ブラシサーマル"
    Filewritestep=1
end if
if ldp(almXSW69_ブラシ上昇端) then
    adrset(almXSW69_ブラシ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW69_ブラシ上昇端"
    Filewritestep=1
end if
if ldp(almXSW70_ブラシ下降端) then
    adrset(almXSW70_ブラシ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW70_ブラシ下降端"
    Filewritestep=1
end if
if ldp(almSV45_シリンダ上昇A) then
    adrset(almSV45_シリンダ上昇A,WriteErrAddres)
    WriteAlmstr.T="almSV45_シリンダ上昇A"
    Filewritestep=1
end if
if ldp(almSV46_シリンダ下降A) then
    adrset(almSV46_シリンダ下降A,WriteErrAddres)
    WriteAlmstr.T="almSV46_シリンダ下降A"
    Filewritestep=1
end if
if ldp(almSV47_シリンダ上昇B) then
    adrset(almSV47_シリンダ上昇B,WriteErrAddres)
    WriteAlmstr.T="almSV47_シリンダ上昇B"
    Filewritestep=1
end if
if ldp(almSV48_シリンダ下降B) then
    adrset(almSV48_シリンダ下降B,WriteErrAddres)
    WriteAlmstr.T="almSV48_シリンダ下降B"
    Filewritestep=1
end if
if ldp(almSV49_アンクランプ) then
    adrset(almSV49_アンクランプ,WriteErrAddres)
    WriteAlmstr.T="almSV49_アンクランプ"
    Filewritestep=1
end if
if ldp(almSV50_クランプ) then
    adrset(almSV50_クランプ,WriteErrAddres)
    WriteAlmstr.T="almSV50_クランプ"
    Filewritestep=1
end if
if ldp(almMC57_搬送モータ) then
    adrset(almMC57_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC57_搬送モータ"
    Filewritestep=1
end if
if ldp(almSV59_リフト上昇) then
    adrset(almSV59_リフト上昇,WriteErrAddres)
    WriteAlmstr.T="almSV59_リフト上昇"
    Filewritestep=1
end if
if ldp(almMC56_ブラシモータ) then
    adrset(almMC56_ブラシモータ,WriteErrAddres)
    WriteAlmstr.T="almMC56_ブラシモータ"
    Filewritestep=1
end if
if ldp(almSV65_シリンダ上昇) then
    adrset(almSV65_シリンダ上昇,WriteErrAddres)
    WriteAlmstr.T="almSV65_シリンダ上昇"
    Filewritestep=1
end if
if ldp(almSV66_シリンダ下降) then
    adrset(almSV66_シリンダ下降,WriteErrAddres)
    WriteAlmstr.T="almSV66_シリンダ下降"
    Filewritestep=1
end if
if ldp(almSV76_リフト下降) then
    adrset(almSV76_リフト下降,WriteErrAddres)
    WriteAlmstr.T="almSV76_リフト下降"
    Filewritestep=1
end if
if ldp(almRLY_光電センサ電源OFF7) then
    adrset(almRLY_光電センサ電源OFF7,WriteErrAddres)
    WriteAlmstr.T="almRLY_光電センサ電源OFF7"
    Filewritestep=1
end if
if ldp(almXSW55_シリンダ上昇端A) then
    adrset(almXSW55_シリンダ上昇端A,WriteErrAddres)
    WriteAlmstr.T="almXSW55_シリンダ上昇端A"
    Filewritestep=1
end if
if ldp(almXSW56_シリンダ下降端A) then
    adrset(almXSW56_シリンダ下降端A,WriteErrAddres)
    WriteAlmstr.T="almXSW56_シリンダ下降端A"
    Filewritestep=1
end if
if ldp(almXSW57_シリンダ上昇端B) then
    adrset(almXSW57_シリンダ上昇端B,WriteErrAddres)
    WriteAlmstr.T="almXSW57_シリンダ上昇端B"
    Filewritestep=1
end if
if ldp(almXSW58_シリンダ下降端B) then
    adrset(almXSW58_シリンダ下降端B,WriteErrAddres)
    WriteAlmstr.T="almXSW58_シリンダ下降端B"
    Filewritestep=1
end if
if ldp(almXSW59_アンクランプ) then
    adrset(almXSW59_アンクランプ,WriteErrAddres)
    WriteAlmstr.T="almXSW59_アンクランプ"
    Filewritestep=1
end if
if ldp(almXSW60_クランプ) then
    adrset(almXSW60_クランプ,WriteErrAddres)
    WriteAlmstr.T="almXSW60_クランプ"
    Filewritestep=1
end if
if ldp(almTHR57_搬送モータ) then
    adrset(almTHR57_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR57_搬送モータ"
    Filewritestep=1
end if
if ldp(almXSW80_リフト上昇端) then
    adrset(almXSW80_リフト上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW80_リフト上昇端"
    Filewritestep=1
end if
if ldp(almXSW81_リフト下降端) then
    adrset(almXSW81_リフト下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW81_リフト下降端"
    Filewritestep=1
end if
if ldp(almPH55_釜検知) then
    adrset(almPH55_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH55_釜検知"
    Filewritestep=1
end if
if ldp(almPH56_フタ検知) then
    adrset(almPH56_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH56_フタ検知"
    Filewritestep=1
end if
if ldp(almPH67_釜検知) then
    adrset(almPH67_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH67_釜検知"
    Filewritestep=1
end if
if ldp(almPH68_釜検知) then
    adrset(almPH68_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH68_釜検知"
    Filewritestep=1
end if
if ldp(almPH69_フタ検知) then
    adrset(almPH69_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH69_フタ検知"
    Filewritestep=1
end if
if ldp(almRLY_反転機電源確認) then
    adrset(almRLY_反転機電源確認,WriteErrAddres)
    WriteAlmstr.T="almRLY_反転機電源確認"
    Filewritestep=1
end if
if ldp(alm釜搬入可能信号_A) then
    adrset(alm釜搬入可能信号_A,WriteErrAddres)
    WriteAlmstr.T="alm釜搬入可能信号_A"
    Filewritestep=1
end if
if ldp(alm反転機反転完了信号_A) then
    adrset(alm反転機反転完了信号_A,WriteErrAddres)
    WriteAlmstr.T="alm反転機反転完了信号_A"
    Filewritestep=1
end if
if ldp(alm反転機異常信号_A) then
    adrset(alm反転機異常信号_A,WriteErrAddres)
    WriteAlmstr.T="alm反転機異常信号_A"
    Filewritestep=1
end if
if ldp(alm反転機運転指令_A) then
    adrset(alm反転機運転指令_A,WriteErrAddres)
    WriteAlmstr.T="alm反転機運転指令_A"
    Filewritestep=1
end if
if ldp(alm反転機停止指令_A) then
    adrset(alm反転機停止指令_A,WriteErrAddres)
    WriteAlmstr.T="alm反転機停止指令_A"
    Filewritestep=1
end if
if ldp(almRLY_サブ1電源確認) then
    adrset(almRLY_サブ1電源確認,WriteErrAddres)
    WriteAlmstr.T="almRLY_サブ1電源確認"
    Filewritestep=1
end if
if ldp(almPTL3_パトライト赤) then
    adrset(almPTL3_パトライト赤,WriteErrAddres)
    WriteAlmstr.T="almPTL3_パトライト赤"
    Filewritestep=1
end if
if ldp(almPTL3_パトライト黄) then
    adrset(almPTL3_パトライト黄,WriteErrAddres)
    WriteAlmstr.T="almPTL3_パトライト黄"
    Filewritestep=1
end if
if ldp(almPTL3_パトライト青) then
    adrset(almPTL3_パトライト青,WriteErrAddres)
    WriteAlmstr.T="almPTL3_パトライト青"
    Filewritestep=1
end if
if ldp(almPTL3_パトライトブザー) then
    adrset(almPTL3_パトライトブザー,WriteErrAddres)
    WriteAlmstr.T="almPTL3_パトライトブザー"
    Filewritestep=1
end if
if ldp(almRLY_サブ2電源確認) then
    adrset(almRLY_サブ2電源確認,WriteErrAddres)
    WriteAlmstr.T="almRLY_サブ2電源確認"
    Filewritestep=1
end if
if ldp(almPTL4_パトライト赤) then
    adrset(almPTL4_パトライト赤,WriteErrAddres)
    WriteAlmstr.T="almPTL4_パトライト赤"
    Filewritestep=1
end if
if ldp(almPTL4_パトライト黄) then
    adrset(almPTL4_パトライト黄,WriteErrAddres)
    WriteAlmstr.T="almPTL4_パトライト黄"
    Filewritestep=1
end if
if ldp(almPTL4_パトライト青) then
    adrset(almPTL4_パトライト青,WriteErrAddres)
    WriteAlmstr.T="almPTL4_パトライト青"
    Filewritestep=1
end if
if ldp(almPTL4_パトライトブザー) then
    adrset(almPTL4_パトライトブザー,WriteErrAddres)
    WriteAlmstr.T="almPTL4_パトライトブザー"
    Filewritestep=1
end if
if ldp(almSEL2_1_運転切換（単動）) then
    adrset(almSEL2_1_運転切換（単動）,WriteErrAddres)
    WriteAlmstr.T="almSEL2_1_運転切換（単動）"
    Filewritestep=1
end if
if ldp(almSEL2_2_運転切換（連動）) then
    adrset(almSEL2_2_運転切換（連動）,WriteErrAddres)
    WriteAlmstr.T="almSEL2_2_運転切換（連動）"
    Filewritestep=1
end if
if ldp(almTHR35_搬送モータ) then
    adrset(almTHR35_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR35_搬送モータ"
    Filewritestep=1
end if
if ldp(almTHR36_反転モータ) then
    adrset(almTHR36_反転モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR36_反転モータ"
    Filewritestep=1
end if
if ldp(almPS5_エアー圧力) then
    adrset(almPS5_エアー圧力,WriteErrAddres)
    WriteAlmstr.T="almPS5_エアー圧力"
    Filewritestep=1
end if
if ldp(almTHR58_洗浄ポンプA) then
    adrset(almTHR58_洗浄ポンプA,WriteErrAddres)
    WriteAlmstr.T="almTHR58_洗浄ポンプA"
    Filewritestep=1
end if
if ldp(almTHR59_洗浄ポンプB) then
    adrset(almTHR59_洗浄ポンプB,WriteErrAddres)
    WriteAlmstr.T="almTHR59_洗浄ポンプB"
    Filewritestep=1
end if
if ldp(almTHR60_洗浄ポンプC) then
    adrset(almTHR60_洗浄ポンプC,WriteErrAddres)
    WriteAlmstr.T="almTHR60_洗浄ポンプC"
    Filewritestep=1
end if
if ldp(almTHR61_洗浄ポンプD) then
    adrset(almTHR61_洗浄ポンプD,WriteErrAddres)
    WriteAlmstr.T="almTHR61_洗浄ポンプD"
    Filewritestep=1
end if
if ldp(almMC1_インバータ用電源) then
    adrset(almMC1_インバータ用電源,WriteErrAddres)
    WriteAlmstr.T="almMC1_インバータ用電源"
    Filewritestep=1
end if
if ldp(almMC35_搬送モータ) then
    adrset(almMC35_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC35_搬送モータ"
    Filewritestep=1
end if
if ldp(almMC36_反転モータ正転) then
    adrset(almMC36_反転モータ正転,WriteErrAddres)
    WriteAlmstr.T="almMC36_反転モータ正転"
    Filewritestep=1
end if
if ldp(almMC36_反転モータ逆転) then
    adrset(almMC36_反転モータ逆転,WriteErrAddres)
    WriteAlmstr.T="almMC36_反転モータ逆転"
    Filewritestep=1
end if
if ldp(almINV1_コンベアモータ正転) then
    adrset(almINV1_コンベアモータ正転,WriteErrAddres)
    WriteAlmstr.T="almINV1_コンベアモータ正転"
    Filewritestep=1
end if
if ldp(almINV2_コンベアモータ正転) then
    adrset(almINV2_コンベアモータ正転,WriteErrAddres)
    WriteAlmstr.T="almINV2_コンベアモータ正転"
    Filewritestep=1
end if
if ldp(almINV3_コンベアモータ正転) then
    adrset(almINV3_コンベアモータ正転,WriteErrAddres)
    WriteAlmstr.T="almINV3_コンベアモータ正転"
    Filewritestep=1
end if
if ldp(almMC58_洗浄ポンプA) then
    adrset(almMC58_洗浄ポンプA,WriteErrAddres)
    WriteAlmstr.T="almMC58_洗浄ポンプA"
    Filewritestep=1
end if
if ldp(almMC59_洗浄ポンプB) then
    adrset(almMC59_洗浄ポンプB,WriteErrAddres)
    WriteAlmstr.T="almMC59_洗浄ポンプB"
    Filewritestep=1
end if
if ldp(almMC60_洗浄ポンプC) then
    adrset(almMC60_洗浄ポンプC,WriteErrAddres)
    WriteAlmstr.T="almMC60_洗浄ポンプC"
    Filewritestep=1
end if
if ldp(almMC61_洗浄ポンプD) then
    adrset(almMC61_洗浄ポンプD,WriteErrAddres)
    WriteAlmstr.T="almMC61_洗浄ポンプD"
    Filewritestep=1
end if
if ldp(almTHR38_搬送モータ) then
    adrset(almTHR38_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR38_搬送モータ"
    Filewritestep=1
end if
if ldp(almTHR37_反転モータ) then
    adrset(almTHR37_反転モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR37_反転モータ"
    Filewritestep=1
end if
if ldp(almRLY_洗浄機電源確認) then
    adrset(almRLY_洗浄機電源確認,WriteErrAddres)
    WriteAlmstr.T="almRLY_洗浄機電源確認"
    Filewritestep=1
end if
if ldp(almPH57_釜検知) then
    adrset(almPH57_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH57_釜検知"
    Filewritestep=1
end if
if ldp(almPH58_フタ検知) then
    adrset(almPH58_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH58_フタ検知"
    Filewritestep=1
end if
if ldp(almLS7_釜反転機原点位置) then
    adrset(almLS7_釜反転機原点位置,WriteErrAddres)
    WriteAlmstr.T="almLS7_釜反転機原点位置"
    Filewritestep=1
end if
if ldp(almLS8_釜反転機反転位置) then
    adrset(almLS8_釜反転機反転位置,WriteErrAddres)
    WriteAlmstr.T="almLS8_釜反転機反転位置"
    Filewritestep=1
end if
if ldp(almPH59_釜検知) then
    adrset(almPH59_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH59_釜検知"
    Filewritestep=1
end if
if ldp(almPH62_フタ検知) then
    adrset(almPH62_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH62_フタ検知"
    Filewritestep=1
end if
if ldp(almPH63_釜検知) then
    adrset(almPH63_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH63_釜検知"
    Filewritestep=1
end if
if ldp(almPH64_フタ検知) then
    adrset(almPH64_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH64_フタ検知"
    Filewritestep=1
end if
if ldp(almMC37_反転モータ逆転) then
    adrset(almMC37_反転モータ逆転,WriteErrAddres)
    WriteAlmstr.T="almMC37_反転モータ逆転"
    Filewritestep=1
end if
if ldp(almMC37_反転モータ正転) then
    adrset(almMC37_反転モータ正転,WriteErrAddres)
    WriteAlmstr.T="almMC37_反転モータ正転"
    Filewritestep=1
end if
if ldp(almMC38_搬送モータ) then
    adrset(almMC38_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC38_搬送モータ"
    Filewritestep=1
end if
if ldp(almSV97_すすぎ電磁弁) then
    adrset(almSV97_すすぎ電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV97_すすぎ電磁弁"
    Filewritestep=1
end if
if ldp(almSV98_仕上げ電磁弁) then
    adrset(almSV98_仕上げ電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV98_仕上げ電磁弁"
    Filewritestep=1
end if
if ldp(almPTL5_パトライト赤) then
    adrset(almPTL5_パトライト赤,WriteErrAddres)
    WriteAlmstr.T="almPTL5_パトライト赤"
    Filewritestep=1
end if
if ldp(almPTL5_パトライト黄) then
    adrset(almPTL5_パトライト黄,WriteErrAddres)
    WriteAlmstr.T="almPTL5_パトライト黄"
    Filewritestep=1
end if
if ldp(almPTL5_パトライト青) then
    adrset(almPTL5_パトライト青,WriteErrAddres)
    WriteAlmstr.T="almPTL5_パトライト青"
    Filewritestep=1
end if
if ldp(almPTL5_パトライトブザー) then
    adrset(almPTL5_パトライトブザー,WriteErrAddres)
    WriteAlmstr.T="almPTL5_パトライトブザー"
    Filewritestep=1
end if
if ldp(almSV69_給湯電磁弁) then
    adrset(almSV69_給湯電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV69_給湯電磁弁"
    Filewritestep=1
end if
if ldp(almSV75_給湯電磁弁) then
    adrset(almSV75_給湯電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV75_給湯電磁弁"
    Filewritestep=1
end if
if ldp(almMC_HT1_タンクヒータ) then
    adrset(almMC_HT1_タンクヒータ,WriteErrAddres)
    WriteAlmstr.T="almMC_HT1_タンクヒータ"
    Filewritestep=1
end if
if ldp(almMC_HT2_タンクヒータ) then
    adrset(almMC_HT2_タンクヒータ,WriteErrAddres)
    WriteAlmstr.T="almMC_HT2_タンクヒータ"
    Filewritestep=1
end if
if ldp(almMC_HT3_タンクヒータ) then
    adrset(almMC_HT3_タンクヒータ,WriteErrAddres)
    WriteAlmstr.T="almMC_HT3_タンクヒータ"
    Filewritestep=1
end if
if ldp(almMC_HT4_タンクヒータ) then
    adrset(almMC_HT4_タンクヒータ,WriteErrAddres)
    WriteAlmstr.T="almMC_HT4_タンクヒータ"
    Filewritestep=1
end if
if ldp(almLS5_空釜反転原点位置) then
    adrset(almLS5_空釜反転原点位置,WriteErrAddres)
    WriteAlmstr.T="almLS5_空釜反転原点位置"
    Filewritestep=1
end if
if ldp(almLS6_空釜反転反転位置) then
    adrset(almLS6_空釜反転反転位置,WriteErrAddres)
    WriteAlmstr.T="almLS6_空釜反転反転位置"
    Filewritestep=1
end if
if ldp(almPH65_釜検知) then
    adrset(almPH65_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH65_釜検知"
    Filewritestep=1
end if
if ldp(almPH66_フタ検知) then
    adrset(almPH66_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH66_フタ検知"
    Filewritestep=1
end if
if ldp(almXSW81_釜フタ押さえ上昇端A) then
    adrset(almXSW81_釜フタ押さえ上昇端A,WriteErrAddres)
    WriteAlmstr.T="almXSW81_釜フタ押さえ上昇端A"
    Filewritestep=1
end if
if ldp(almXSW82_釜フタ押さえ下降端A) then
    adrset(almXSW82_釜フタ押さえ下降端A,WriteErrAddres)
    WriteAlmstr.T="almXSW82_釜フタ押さえ下降端A"
    Filewritestep=1
end if
if ldp(almXSW83_釜フタ押さえ上昇端B) then
    adrset(almXSW83_釜フタ押さえ上昇端B,WriteErrAddres)
    WriteAlmstr.T="almXSW83_釜フタ押さえ上昇端B"
    Filewritestep=1
end if
if ldp(almXSW84_釜フタ押さえ下降端B) then
    adrset(almXSW84_釜フタ押さえ下降端B,WriteErrAddres)
    WriteAlmstr.T="almXSW84_釜フタ押さえ下降端B"
    Filewritestep=1
end if
if ldp(almXSW85_釜フタストッパ下降端) then
    adrset(almXSW85_釜フタストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW85_釜フタストッパ下降端"
    Filewritestep=1
end if
if ldp(almINV10_洗浄ポンプA異常) then
    adrset(almINV10_洗浄ポンプA異常,WriteErrAddres)
    WriteAlmstr.T="almINV10_洗浄ポンプA異常"
    Filewritestep=1
end if
if ldp(almFLT1_タンク上限) then
    adrset(almFLT1_タンク上限,WriteErrAddres)
    WriteAlmstr.T="almFLT1_タンク上限"
    Filewritestep=1
end if
if ldp(almFLT2_タンク下限) then
    adrset(almFLT2_タンク下限,WriteErrAddres)
    WriteAlmstr.T="almFLT2_タンク下限"
    Filewritestep=1
end if
if ldp(almXSW86_釜フタ押さえ上昇端A) then
    adrset(almXSW86_釜フタ押さえ上昇端A,WriteErrAddres)
    WriteAlmstr.T="almXSW86_釜フタ押さえ上昇端A"
    Filewritestep=1
end if
if ldp(almXSW87_釜フタ押さえ下降端A) then
    adrset(almXSW87_釜フタ押さえ下降端A,WriteErrAddres)
    WriteAlmstr.T="almXSW87_釜フタ押さえ下降端A"
    Filewritestep=1
end if
if ldp(almXSW88_釜フタ押さえ上昇端B) then
    adrset(almXSW88_釜フタ押さえ上昇端B,WriteErrAddres)
    WriteAlmstr.T="almXSW88_釜フタ押さえ上昇端B"
    Filewritestep=1
end if
if ldp(almXSW89_釜フタ押さえ下降端B) then
    adrset(almXSW89_釜フタ押さえ下降端B,WriteErrAddres)
    WriteAlmstr.T="almXSW89_釜フタ押さえ下降端B"
    Filewritestep=1
end if
if ldp(almSV81_給湯電磁弁) then
    adrset(almSV81_給湯電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV81_給湯電磁弁"
    Filewritestep=1
end if
if ldp(almSV87_給湯電磁弁) then
    adrset(almSV87_給湯電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV87_給湯電磁弁"
    Filewritestep=1
end if
if ldp(almSV72_下洗浄電磁弁) then
    adrset(almSV72_下洗浄電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV72_下洗浄電磁弁"
    Filewritestep=1
end if
if ldp(almSV78_下洗浄電磁弁) then
    adrset(almSV78_下洗浄電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV78_下洗浄電磁弁"
    Filewritestep=1
end if
if ldp(almSV84_下洗浄電磁弁) then
    adrset(almSV84_下洗浄電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV84_下洗浄電磁弁"
    Filewritestep=1
end if
if ldp(almSV90_下洗浄電磁弁) then
    adrset(almSV90_下洗浄電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV90_下洗浄電磁弁"
    Filewritestep=1
end if
if ldp(almSV67_釜フタ押さえ下降A) then
    adrset(almSV67_釜フタ押さえ下降A,WriteErrAddres)
    WriteAlmstr.T="almSV67_釜フタ押さえ下降A"
    Filewritestep=1
end if
if ldp(almSV68_釜フタ押さえ下降B) then
    adrset(almSV68_釜フタ押さえ下降B,WriteErrAddres)
    WriteAlmstr.T="almSV68_釜フタ押さえ下降B"
    Filewritestep=1
end if
if ldp(almSV71_釜フタストッパ) then
    adrset(almSV71_釜フタストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV71_釜フタストッパ"
    Filewritestep=1
end if
if ldp(almSV73_釜フタ押さえ下降A) then
    adrset(almSV73_釜フタ押さえ下降A,WriteErrAddres)
    WriteAlmstr.T="almSV73_釜フタ押さえ下降A"
    Filewritestep=1
end if
if ldp(almSV74_釜フタ押さえ下降B) then
    adrset(almSV74_釜フタ押さえ下降B,WriteErrAddres)
    WriteAlmstr.T="almSV74_釜フタ押さえ下降B"
    Filewritestep=1
end if
if ldp(almSV77_釜フタストッパ) then
    adrset(almSV77_釜フタストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV77_釜フタストッパ"
    Filewritestep=1
end if
if ldp(almSV79_釜フタ押さえ下降A) then
    adrset(almSV79_釜フタ押さえ下降A,WriteErrAddres)
    WriteAlmstr.T="almSV79_釜フタ押さえ下降A"
    Filewritestep=1
end if
if ldp(almSV80_釜フタ押さえ下降B) then
    adrset(almSV80_釜フタ押さえ下降B,WriteErrAddres)
    WriteAlmstr.T="almSV80_釜フタ押さえ下降B"
    Filewritestep=1
end if
if ldp(almSV83_釜フタストッパ) then
    adrset(almSV83_釜フタストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV83_釜フタストッパ"
    Filewritestep=1
end if
if ldp(almSV85_釜フタ押さえ下降A) then
    adrset(almSV85_釜フタ押さえ下降A,WriteErrAddres)
    WriteAlmstr.T="almSV85_釜フタ押さえ下降A"
    Filewritestep=1
end if
if ldp(almXSW90_釜フタストッパ下降端) then
    adrset(almXSW90_釜フタストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW90_釜フタストッパ下降端"
    Filewritestep=1
end if
if ldp(almINV11_洗浄ポンプB異常) then
    adrset(almINV11_洗浄ポンプB異常,WriteErrAddres)
    WriteAlmstr.T="almINV11_洗浄ポンプB異常"
    Filewritestep=1
end if
if ldp(almFLT3_タンク上限) then
    adrset(almFLT3_タンク上限,WriteErrAddres)
    WriteAlmstr.T="almFLT3_タンク上限"
    Filewritestep=1
end if
if ldp(almFLT4_タンク下限) then
    adrset(almFLT4_タンク下限,WriteErrAddres)
    WriteAlmstr.T="almFLT4_タンク下限"
    Filewritestep=1
end if
if ldp(almXSW91_釜フタ押さえ上昇端A) then
    adrset(almXSW91_釜フタ押さえ上昇端A,WriteErrAddres)
    WriteAlmstr.T="almXSW91_釜フタ押さえ上昇端A"
    Filewritestep=1
end if
if ldp(almXSW92_釜フタ押さえ下降端A) then
    adrset(almXSW92_釜フタ押さえ下降端A,WriteErrAddres)
    WriteAlmstr.T="almXSW92_釜フタ押さえ下降端A"
    Filewritestep=1
end if
if ldp(almXSW93_釜フタ押さえ上昇端B) then
    adrset(almXSW93_釜フタ押さえ上昇端B,WriteErrAddres)
    WriteAlmstr.T="almXSW93_釜フタ押さえ上昇端B"
    Filewritestep=1
end if
if ldp(almXSW94_釜フタ押さえ下降端B) then
    adrset(almXSW94_釜フタ押さえ下降端B,WriteErrAddres)
    WriteAlmstr.T="almXSW94_釜フタ押さえ下降端B"
    Filewritestep=1
end if
if ldp(almXSW95_釜フタストッパ下降端) then
    adrset(almXSW95_釜フタストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW95_釜フタストッパ下降端"
    Filewritestep=1
end if
if ldp(almINV12_洗浄ポンプC異常) then
    adrset(almINV12_洗浄ポンプC異常,WriteErrAddres)
    WriteAlmstr.T="almINV12_洗浄ポンプC異常"
    Filewritestep=1
end if
if ldp(almFLT5_タンク上限) then
    adrset(almFLT5_タンク上限,WriteErrAddres)
    WriteAlmstr.T="almFLT5_タンク上限"
    Filewritestep=1
end if
if ldp(almFLT6_タンク下限) then
    adrset(almFLT6_タンク下限,WriteErrAddres)
    WriteAlmstr.T="almFLT6_タンク下限"
    Filewritestep=1
end if
if ldp(almXSW96_釜フタ押さえ上昇端A) then
    adrset(almXSW96_釜フタ押さえ上昇端A,WriteErrAddres)
    WriteAlmstr.T="almXSW96_釜フタ押さえ上昇端A"
    Filewritestep=1
end if
if ldp(almXSW97_釜フタ押さえ下降端A) then
    adrset(almXSW97_釜フタ押さえ下降端A,WriteErrAddres)
    WriteAlmstr.T="almXSW97_釜フタ押さえ下降端A"
    Filewritestep=1
end if
if ldp(almXSW98_釜フタ押さえ上昇端B) then
    adrset(almXSW98_釜フタ押さえ上昇端B,WriteErrAddres)
    WriteAlmstr.T="almXSW98_釜フタ押さえ上昇端B"
    Filewritestep=1
end if
if ldp(almXSW99_釜フタ押さえ下降端B) then
    adrset(almXSW99_釜フタ押さえ下降端B,WriteErrAddres)
    WriteAlmstr.T="almXSW99_釜フタ押さえ下降端B"
    Filewritestep=1
end if
if ldp(almSV86_釜フタ押さえ下降B) then
    adrset(almSV86_釜フタ押さえ下降B,WriteErrAddres)
    WriteAlmstr.T="almSV86_釜フタ押さえ下降B"
    Filewritestep=1
end if
if ldp(almSV89_釜フタストッパ) then
    adrset(almSV89_釜フタストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV89_釜フタストッパ"
    Filewritestep=1
end if
if ldp(alm洗浄剤投入機) then
    adrset(alm洗浄剤投入機,WriteErrAddres)
    WriteAlmstr.T="alm洗浄剤投入機"
    Filewritestep=1
end if
if ldp(almINV10_洗浄ポンプA運転) then
    adrset(almINV10_洗浄ポンプA運転,WriteErrAddres)
    WriteAlmstr.T="almINV10_洗浄ポンプA運転"
    Filewritestep=1
end if
if ldp(almINV11_洗浄ポンプB運転) then
    adrset(almINV11_洗浄ポンプB運転,WriteErrAddres)
    WriteAlmstr.T="almINV11_洗浄ポンプB運転"
    Filewritestep=1
end if
if ldp(almINV12_洗浄ポンプC運転) then
    adrset(almINV12_洗浄ポンプC運転,WriteErrAddres)
    WriteAlmstr.T="almINV12_洗浄ポンプC運転"
    Filewritestep=1
end if
if ldp(almINV13_洗浄ポンプD運転) then
    adrset(almINV13_洗浄ポンプD運転,WriteErrAddres)
    WriteAlmstr.T="almINV13_洗浄ポンプD運転"
    Filewritestep=1
end if
if ldp(almXSW100_釜フタストッパ下降端) then
    adrset(almXSW100_釜フタストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW100_釜フタストッパ下降端"
    Filewritestep=1
end if
if ldp(almINV13_洗浄ポンプD異常) then
    adrset(almINV13_洗浄ポンプD異常,WriteErrAddres)
    WriteAlmstr.T="almINV13_洗浄ポンプD異常"
    Filewritestep=1
end if
if ldp(almFLT7_タンク上限) then
    adrset(almFLT7_タンク上限,WriteErrAddres)
    WriteAlmstr.T="almFLT7_タンク上限"
    Filewritestep=1
end if
if ldp(almFLT8_タンク下限) then
    adrset(almFLT8_タンク下限,WriteErrAddres)
    WriteAlmstr.T="almFLT8_タンク下限"
    Filewritestep=1
end if
if ldp(almRLY_SCR1_MC36_反転モータ) then
    adrset(almRLY_SCR1_MC36_反転モータ,WriteErrAddres)
    WriteAlmstr.T="almRLY_SCR1_MC36_反転モータ"
    Filewritestep=1
end if
if ldp(almRLY_SCR2_MC37_反転モータ) then
    adrset(almRLY_SCR2_MC37_反転モータ,WriteErrAddres)
    WriteAlmstr.T="almRLY_SCR2_MC37_反転モータ"
    Filewritestep=1
end if
if ldp(almINV1_コンベア異常) then
    adrset(almINV1_コンベア異常,WriteErrAddres)
    WriteAlmstr.T="almINV1_コンベア異常"
    Filewritestep=1
end if
if ldp(almINV2_コンベア異常) then
    adrset(almINV2_コンベア異常,WriteErrAddres)
    WriteAlmstr.T="almINV2_コンベア異常"
    Filewritestep=1
end if
if ldp(almINV3_コンベア異常) then
    adrset(almINV3_コンベア異常,WriteErrAddres)
    WriteAlmstr.T="almINV3_コンベア異常"
    Filewritestep=1
end if
'-----------------------------------------------------------------------------------------------------------------------------
