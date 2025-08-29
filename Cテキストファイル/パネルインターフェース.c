'パネルインターフェース
'===================================================================================================================
'
'<<<<<<<	パネルインターフェース部	>>>>>>>>
'
'===================================================================================================================
客先コード=川崎北部

'----------------------------------------------------------------------------------
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
'FindEndSec	2ワード符号なし整数
'FindStartSec	2ワード符号なし整数
'Find年月日	1ワード符号なし整数[6]
'dsp更新	ビット
'todaySec	2ワード符号なし整数
'-----------------------------------------------------------------------------------------------------------------------------
'ページ移動
	el現在ページNO=dspErrAnalIndex+1
	dspErrAnalOffset=dspErrAnalIndex*10

	if ldp(pnlPBel下限移動) then
		dspErrAnalIndex=4
	
	else if ldp(pnlPBel下移動) then
		
		if dspErrAnalIndex>=4 then
			dspErrAnalIndex=4
		else
			dspErrAnalIndex=dspErrAnalIndex+1
		end if
		
	else if ldp(pnlPBel上限移動) then
		dspErrAnalIndex=0
	
	else if ldp(pnlPBel上移動) then
		if dspErrAnalIndex>0 then
			dspErrAnalIndex=dspErrAnalIndex-1
		else
			dspErrAnalIndex=0
		end if
	end if

'----------------------------------------------------------------------------------
if ldp(pnlPBel更新) or dsp更新 then
	FindStart年月日[0]=setFindStart年月日[0]
	FindStart年月日[1]=setFindStart年月日[1]
	FindStart年月日[2]=setFindStart年月日[2]
	setFindStart年月日[3]=0
	setFindStart年月日[4]=0
	setFindStart年月日[5]=0
	setFindEnd年月日[3]=23
	setFindEnd年月日[4]=59
	setFindEnd年月日[5]=0

	FindEnd年月日[0]=setFindEnd年月日[0]
	FindEnd年月日[1]=setFindEnd年月日[1]
	FindEnd年月日[2]=setFindEnd年月日[2]
	FindStart年月日[3]=0
	FindStart年月日[4]=0
	FindStart年月日[5]=0
	FindEnd年月日[3]=23
	FindEnd年月日[4]=59
	FindEnd年月日[5]=0
	
	Filereadstep=1
	dspErrAnalIndex=0
	dsp更新=OFF
	
end if

'----------------------------------------------------------------------------------
if ldp(pnlPBel今日) then
	pnlPBel今日=ON
	pnlPBel日=OFF
	pnlPBel週=OFF
	pnlPBel月=OFF
	init今日=ON	
else if ldp(pnlPBel日) then
	pnlPBel今日=OFF
	pnlPBel日=ON
	pnlPBel週=OFF
	pnlPBel月=OFF
	init日=ON
else if ldp(pnlPBel週) then
	pnlPBel今日=OFF
	pnlPBel日=OFF
	pnlPBel週=ON
	pnlPBel月=OFF
	init週=ON
else if ldp(pnlPBel月) then
	pnlPBel今日=OFF
	pnlPBel日=OFF
	pnlPBel週=OFF
	pnlPBel月=ON
	init月=ON
end if
'----------------------------------------------------------------------------------
if 	pnlPBel今日 then
	if init今日 then
		init今日=OFF	
	
		setFindStart年月日[0]=CM700
		setFindStart年月日[1]=CM701
		setFindStart年月日[2]=CM702
		setFindEnd年月日[0]=CM700
		setFindEnd年月日[1]=CM701
		setFindEnd年月日[2]=CM702
	
		dspErrAnalIndex=0
		dsp更新=ON
	else if CM700<>FindStart年月日[0] or CM701<>FindStart年月日[1] or  CM702<>FindStart年月日[2] then
		
		setFindStart年月日[0]=CM700
		setFindStart年月日[1]=CM701
		setFindStart年月日[2]=CM702
		setFindEnd年月日[0]=CM700
		setFindEnd年月日[1]=CM701
		setFindEnd年月日[2]=CM702
		
		dsp更新=ON
	
	end if

	

else if pnlPBel日 then
	if init日 then
		init日=OFF
		
		setFindStart年月日[0]=CM700
		setFindStart年月日[1]=CM701
		setFindStart年月日[2]=CM702
		setFindEnd年月日[0]=CM700
		setFindEnd年月日[1]=CM701
		setFindEnd年月日[2]=CM702

		dspErrAnalIndex=0
		dsp更新=ON
	else if setFindStart年月日[0]<>FindStart年月日[0] or setFindStart年月日[1]<>FindStart年月日[1] or  setFindStart年月日[2]<>FindStart年月日[2] then

		todaySec=SEC(CM700)

		FindStartSec=SEC(setFindStart年月日)
		if FindStartSec>=todaySec then
			setFindStart年月日[0]=CM700
			setFindStart年月日[1]=CM701
			setFindStart年月日[2]=CM702
			setFindEnd年月日[0]=CM700
			setFindEnd年月日[1]=CM701
			setFindEnd年月日[2]=CM702			
		else
			RSEC(FindStartSec,setFindStart年月日)
			RSEC(FindStartSec,setFindEnd年月日)			
		end if
		
		dsp更新=ON

	end if

	if ldp(pnlPBel左移動) then
		FindStartSec=SEC(setFindStart年月日)-86400
		RSEC(FindStartSec,setFindStart年月日)
		RSEC(FindStartSec,setFindEnd年月日)			
		
		dsp更新=ON

	else if ldp(pnlPBel右移動) then
	
		Find年月日[0]=CM700
		Find年月日[1]=CM701
		Find年月日[2]=CM702
		Find年月日[3]=0
		Find年月日[4]=0
		Find年月日[5]=0
		
		todaySec=SEC(Find年月日)
		
		FindStartSec=SEC(setFindStart年月日)
		if FindStartSec>=todaySec then
			setFindStart年月日[0]=CM700
			setFindStart年月日[1]=CM701
			setFindStart年月日[2]=CM702
			setFindEnd年月日[0]=CM700
			setFindEnd年月日[1]=CM701
			setFindEnd年月日[2]=CM702			
		else
			FindStartSec=SEC(setFindStart年月日)+86400
			RSEC(FindStartSec,setFindStart年月日)
			RSEC(FindStartSec,setFindEnd年月日)			
		end if

		dsp更新=ON
	
	end if
	

else if pnlPBel週 then
	if init週 then
		init週=OFF

		FindStartSec=SEC(CM700)-518400
		RSEC(FindStartSec,setFindStart年月日)
		setFindEnd年月日[0]=CM700
		setFindEnd年月日[1]=CM701
		setFindEnd年月日[2]=CM702

		dspErrAnalIndex=0
		dsp更新=ON
	else if setFindStart年月日[0]<>FindStart年月日[0] or setFindStart年月日[1]<>FindStart年月日[1] or  setFindStart年月日[2]<>FindStart年月日[2] then

		todaySec=SEC(CM700)

		FindStartSec=SEC(setFindStart年月日)
		if FindStartSec>=todaySec then
			setFindStart年月日[0]=CM700
			setFindStart年月日[1]=CM701
			setFindStart年月日[2]=CM702
		else
			RSEC(FindStartSec,setFindStart年月日)	
		end if
		FindEndSec=SEC(setFindEnd年月日)+518400-1 '1週間
		if FindEndSec>=todaySec then
			setFindEnd年月日[0]=CM700
			setFindEnd年月日[1]=CM701
			setFindEnd年月日[2]=CM702
		else
			RSEC(FindEndSec,setFindEnd年月日)
		end if
		
		dsp更新=ON
		
	end if
	
	if ldp(pnlPBel左移動) then
		todaySec=SEC(CM700)

		FindStartSec=SEC(setFindStart年月日)-518400
		if FindStartSec>=todaySec then
			setFindStart年月日[0]=CM700
			setFindStart年月日[1]=CM701
			setFindStart年月日[2]=CM702
		else
			RSEC(FindStartSec,setFindStart年月日)		
		end if
		
		FindEndSec=SEC(setFindStart年月日)+518400-1 '1週間
		if FindEndSec>=todaySec then
			setFindEnd年月日[0]=CM700
			setFindEnd年月日[1]=CM701
			setFindEnd年月日[2]=CM702
		else
			RSEC(FindEndSec,setFindEnd年月日)
		end if
		
		dsp更新=ON

	
	else if ldp(pnlPBel右移動) then
		todaySec=SEC(CM700)

		FindStartSec=SEC(setFindStart年月日)+518400
		if FindStartSec>=todaySec then
			setFindStart年月日[0]=CM700
			setFindStart年月日[1]=CM701
			setFindStart年月日[2]=CM702
		else
			RSEC(FindStartSec,setFindStart年月日)
		end if
		FindEndSec=SEC(setFindStart年月日)+518400-1 '1週間
		if FindEndSec>=todaySec then
			setFindEnd年月日[0]=CM700
			setFindEnd年月日[1]=CM701
			setFindEnd年月日[2]=CM702
		else
			RSEC(FindEndSec,setFindEnd年月日)
		end if
		
		dsp更新=ON


	end if

else if	pnlPBel月 then
	setFindEnd年月日[0]=CM700
	setFindEnd年月日[1]=CM701
	setFindEnd年月日[2]=CM702

	if init月 then
		init月=OFF

		Find年月日[0]=CM700
		Find年月日[1]=CM701
		Find年月日[2]=1
		Find年月日[3]=0
		Find年月日[4]=0
		Find年月日[5]=0
		FindStartSec=SEC(Find年月日)
		RSEC(FindStartSec,setFindStart年月日)
		setFindEnd年月日[0]=CM700
		setFindEnd年月日[1]=CM701
		setFindEnd年月日[2]=CM702

		dspErrAnalIndex=0
		dsp更新=ON

	else if setFindStart年月日[0]<>FindStart年月日[0] or setFindStart年月日[1]<>FindStart年月日[1] or  setFindStart年月日[2]<>FindStart年月日[2] then

		Find年月日[0]=CM700
		Find年月日[1]=CM701
		Find年月日[2]=1
		Find年月日[3]=0
		Find年月日[4]=0
		Find年月日[5]=0
		todaySec=SEC(Find年月日)
		
		setFindStart年月日[2]=1 '強制的に1日にする
		
		FindStartSec=SEC(setFindStart年月日)
		if FindStartSec>=todaySec then
			setFindStart年月日[0]=CM700
			setFindStart年月日[1]=CM701
			setFindStart年月日[2]=1
		else
			RSEC(FindStartSec,setFindStart年月日)
		end if
		dsp更新=ON
		
	end if
	
	if ldp(pnlPBel左移動) then
		Find年月日[0]=CM700
		Find年月日[1]=CM701
		Find年月日[2]=1
		Find年月日[3]=0
		Find年月日[4]=0
		Find年月日[5]=0
		todaySec=SEC(Find年月日)

		setFindStart年月日[2]=1 '強制的に1日にする
		
		if setFindStart年月日[1]>=2 and setFindStart年月日[1]<=12 then
			setFindStart年月日[1]=setFindStart年月日[1]-1
		else if setFindStart年月日[1]=1 then
			setFindStart年月日[0]=setFindStart年月日[0]-1
			setFindStart年月日[1]=12
		end if
		
		FindStartSec=SEC(setFindStart年月日)
		if FindStartSec>=todaySec then
			setFindStart年月日[0]=CM700
			setFindStart年月日[1]=CM701
			setFindStart年月日[2]=1
		else
			RSEC(FindStartSec,setFindStart年月日)		
		end if
		
		dsp更新=ON

	
	else if ldp(pnlPBel右移動) then
		Find年月日[0]=CM700
		Find年月日[1]=CM701
		Find年月日[2]=1
		Find年月日[3]=0
		Find年月日[4]=0
		Find年月日[5]=0
		todaySec=SEC(Find年月日)

		setFindStart年月日[2]=1 '強制的に1日にする
		
		if setFindStart年月日[1]>=1 and setFindStart年月日[1]<12 then
			setFindStart年月日[1]=setFindStart年月日[1]+1
		else if setFindStart年月日[1]=12 then
			setFindStart年月日[0]=setFindStart年月日[0]+1
			setFindStart年月日[1]=1
		end if

		FindStartSec=SEC(setFindStart年月日)
		if FindStartSec>=todaySec then
			setFindStart年月日[0]=CM700
			setFindStart年月日[1]=CM701
			setFindStart年月日[2]=1
		else
			RSEC(FindStartSec,setFindStart年月日)
		end if

		dsp更新=ON


	end if

end if

'----------------------------------------------------------------------------------

' 切替ページ
if CR2008 then '電源ON時初期化処理
	
	メインTP_切替ページＮｏ=スタートアップ画面
	サブTP_切替ページＮｏ=スタートアップ画面
	むらしTP_切替ページＮｏ=スタートアップ画面
	
	
	MainStatusMsg=0
	前処理工程StatusMsg=0
	自動搬送StatusMsg=0
	計量StatusMsg=0
	洗米StatusMsg=0
	浸漬タンクAStatusMsg=0
	浸漬タンクBStatusMsg=0
	浸漬タンクAユニットStatusMsg=0
	浸漬タンクBユニットStatusMsg=0
	計水ユニットStatusMsg=0
	ならしユニットStatusMsg=0
	蓋被せユニットStatusMsg=0
	蓋取りユニットStatusMsg=0
'	ごはん検知StatusMsg=0
'	バキュームユニットStatusMsg=0
	ほぐし機AユニットStatusMsg=0
'	ほぐし機BユニットStatusMsg=0
	搬送コンベアAStatusMsg=0
	搬送コンベアBStatusMsg=0
	搬送コンベアCStatusMsg=0
	搬送コンベアC2StatusMsg=0
	搬送コンベアDStatusMsg=0
	搬送コンベアEStatusMsg=0
	搬送コンベアF1StatusMsg=0
	搬送コンベアF2StatusMsg=0
	搬送コンベアGStatusMsg=0
	搬送コンベアHStatusMsg=0
	釜フタ昇降装置AStatusMsg=0
	釜反転入口StatusMsg=0
	洗浄ユニットStatusMsg=0
	洗浄タンクStatusMsg=0
	洗浄コンベア搬送StatusMsg=0
	釜反転出口StatusMsg=0
	釜フタ昇降装置BStatusMsg=0	

else

	'--------------------------------------------------------------------------------	
	'異常履歴画面
	if ldp(自動搬送ErrStep<>0) then
		メインTP_切替ページＮｏ=異常履歴画面
		サブTP_切替ページＮｏ=異常履歴画面
	end if
	'--------------------------------------------------------------------------------	
	'予約内容確認画面
	前処理設定完了=ON
	if 予約確認 then
			if DM_Aタンク設定値<>0 or DM_Bタンク設定値<>0 then
				前処理設定完了=ON
				メインTP_切替ページＮｏ=12 '予約内容確認画面
			else
				前処理設定完了=OFF		
			end if
	'--------------------------------------------------------------------------------	
	'ホーム画面
	else if (即時運転モード or 予約運転モード) and PB21_前処理停止 then
			メインTP_切替ページＮｏ=1 'ホーム画面

	'--------------------------------------------------------------------------------	
	end if

end if



'--------------------------------------------------------------------------------	
'----------------------------------------------------------------------------------
' タッチパネルに登録されたメッセージ番号を書き込む
' xxxxStatusMsg=（メッセージ番号）
'
'----------------------------------------------------------------------------------
'	メッセージコード			
'		#0	'	メッセージなし
'----------------------------------------------------------------------------------
'	シーケンシャル運転状態
'	MainStatusMsg=0
'		MainStatusMsg=#100 '洗浄機タンク給湯中
'		MainStatusMsg=#102 '洗浄機タンク加熱中
'		MainStatusMsg=#103 '洗浄機タンク給湯中、加熱中
'		MainStatusMsg=#101 '洗浄機タンク準備完了
'		MainStatusMsg=#110 '炊飯運転スイッチを押してください。搬送コンベアが動作します。ご注意ください。
'		MainStatusMsg=#111 '炊飯機着火確認
'		MainStatusMsg=#112 '配米の準備が完了しました。
'		MainStatusMsg=#113 '自動運転中
'		MainStatusMsg=#120 '停止準備中
'		MainStatusMsg=#121 '停止準備中。炊飯機消火可能です。
'----------------------------------------------------------------------------------
'	前処理工程			
'	前処理工程StatusMsg=0
'		前処理工程StatusMsg=#20	'	前処理中
'		前処理工程StatusMsg=#21	'	浸漬中
'		前処理工程StatusMsg=#22	'	自動運転中
'		前処理工程StatusMsg=#23	'	停止準備中
'		前処理工程StatusMsg=#24	'	停止中
'----------------------------------------------------------------------------------
'	浸漬タンク		'	
'	浸漬タンクAユニットStatusMsg=0
'		浸漬タンクAユニットStatusMsg=#10	'	給水中
'		浸漬タンクAユニットStatusMsg=#11	'	送米中
'		浸漬タンクAユニットStatusMsg=#12	'	浸漬中
'		浸漬タンクAユニットStatusMsg=#13	'	配米中
'		浸漬タンクAユニットStatusMsg=#14	'	配米完了
'	浸漬タンクBユニットStatusMsg=0
'		浸漬タンクBユニットStatusMsg=#10	'	給水中
'		浸漬タンクBユニットStatusMsg=#11	'	送米中
'		浸漬タンクBユニットStatusMsg=#12	'	浸漬中
'		浸漬タンクBユニットStatusMsg=#13	'	配米中
'		浸漬タンクBユニットStatusMsg=#14	'	配米完了
'----------------------------------------------------------------------------------
'	ならし機		'
'	ならし装置StatusMsg=0
'		ならし装置StatusMsg=#30	'	待機中
'		ならし装置StatusMsg=#31	'	ならし中
'----------------------------------------------------------------------------------
'	フタ被せ
'	蓋被せユニットStatusMsg=0
'		蓋被せユニットStatusMsg=#40	'	フタ取り中
'		蓋被せユニットStatusMsg=#41	'	フタ被せ待機中（フタを持っている状態）
'		蓋被せユニットStatusMsg=#42	'	フタ置き中
'		蓋被せユニットStatusMsg=#43	'	待機中（フタを持っていない）
'----------------------------------------------------------------------------------
'	フタ取り
'	蓋取りユニットStatusMsg=0
'		蓋取りユニットStatusMsg=#45	'	待機中
'		蓋取りユニットStatusMsg=#46	'	フタ取り中
'		蓋取りユニットStatusMsg=#47	'	フタ置き中
'----------------------------------------------------------------------------------
'	炊飯釜確認装置
'	ごはん検知StatusMsg=0
'		ごはん検知StatusMsg=#50	'	待機中
'		ごはん検知StatusMsg=#51	'	確認中
'		ごはん検知StatusMsg=#56	'	水釜
'		ごはん検知StatusMsg=#57	'	米飯釜
'----------------------------------------------------------------------------------
'	水釜バキューマ
'	バキュームユニットStatusMsg=0
'		バキュームユニットStatusMsg=#60	'	待機中
'		バキュームユニットStatusMsg=#61	'	吸水中
'----------------------------------------------------------------------------------
'	釜洗浄機
'	洗浄ユニットStatusMsg=0
'		洗浄ユニットStatusMsg=#70	'	待機中
'		洗浄ユニットStatusMsg=#71	'	準備中
'		洗浄ユニットStatusMsg=#72	'	運転中
'----------------------------------------------------------------------------------

System変更通知=洗浄ユニット1禁止 or 洗浄ユニット2禁止 or 洗浄ユニット3禁止 or 洗浄ユニット4禁止  
System変更通知=System変更通知 or not(計水ユニット許可) or not(ならしユニット許可) or not(蓋被せユニット許可) or not(蓋取りユニット許可)

'----------------------------------------------------------------------------------
'アイテムアドレス参照
'
'
'ITEM TABLE
'       配米重量    計量水重量  アイテム名称
' 1		EM1020		EM1021(+1)	EM1030(+10)
' 2		EM1040(+20)	EM1041		EM1050
' 3		EM1060		EM1061		EM1070
' 4		EM1080		EM1081		EM1090

	'アイテム設定NO
	DM_ITEMNO=DM_ITEMNO

	if DM_ITEMNO>0 then

		'【配米重量】
		ADRSET(EM1020,ptrアイテム配米重量)
		ADRADD(20 * (DM_ITEMNO-1),ptrアイテム配米重量)

		'【計量水重量】
		ADRSET(EM1021,ptrアイテム計量水重量)
		ADRADD(20 * (DM_ITEMNO-1),ptrアイテム計量水重量)
		if メインTP_切替ページＮｏ<>160 then 'メインTP_切替ページＮｏ=160  一般設定（一般設定では計量水の微調整を可能にする）
			DM_計水目標下限1.U=*ptrアイテム計量水重量
		end if
		
		'【アイテム名称】
		ADRSET(EM1030,ptrアイテム名称)
		ADRADD(20 * (DM_ITEMNO-1),ptrアイテム名称)
		' -- 文字バッファクリア --
		ADRSET(EM4001.U,loopptr)
		FOR loop=1 TO 10
			*loopptr.U=0
			inc(loopptr)
		NEXT
		'-- 文字列コピー
		EM4001.T=*ptrアイテム名称.T
	
	else if DM_ITEMNO=0 then
		' -- 文字バッファクリア --
		ADRSET(EM4001.U,loopptr)
		FOR loop=1 TO 10
			*loopptr.U=0
			inc(loopptr)
		NEXT
		'-- 文字列空白
		EM4001.T=""	
	
	end if	
'----------------------------------------------------------------------------------
'強制米無し 

	pnlPBL強制米無しA=pnlPB強制米無しA and CR2006
	pnlPBL強制米無しB=pnlPB強制米無しB and CR2006


'----------------------------------------------------------------------------------
'StageItem シフトと変更 

if Item変更通知パネル then
	StageDevice0=ORA(ANDA(StageDevice0,$FF00),StageItem0)
	StageDevice1=ORA(ANDA(StageDevice1,$FF00),StageItem1)
	StageDevice2=ORA(ANDA(StageDevice2,$FF00),StageItem2)
	StageDevice3=ORA(ANDA(StageDevice3,$FF00),StageItem3)
	StageDevice4=ORA(ANDA(StageDevice4,$FF00),StageItem4)
	StageDevice5=ORA(ANDA(StageDevice5,$FF00),StageItem5)
	StageDevice6=ORA(ANDA(StageDevice6,$FF00),StageItem6)
	StageDevice7=ORA(ANDA(StageDevice7,$FF00),StageItem7)
	StageDevice8=ORA(ANDA(StageDevice8,$FF00),StageItem8)
	StageDevice9=ORA(ANDA(StageDevice9,$FF00),StageItem9)
	StageDevice10=ORA(ANDA(StageDevice10,$FF00),StageItem10)
	StageDevice11=ORA(ANDA(StageDevice11,$FF00),StageItem11)
	StageDevice12=ORA(ANDA(StageDevice12,$FF00),StageItem12)

	Item変更通知パネル=OFF
end if

'----------------------------------------------------------------------------------
'自動運転モニタ排出
	'-----------------------------------------------
	'むらし F1 アイテム
	if 0<StageDevice17 and StageDevice17<99 and PH29_釜検知 then 
		IND_StageDevice17=ON
	else 
		IND_StageDevice17=OFF
	end if
	if 0<StageDevice18 and StageDevice18<99 and PH30_釜検知 then 
		IND_StageDevice18=ON
	else 
		IND_StageDevice18=OFF
	end if
	if 0<StageDevice19 and StageDevice19<99 and PH31_釜検知 then 
		IND_StageDevice19=ON
	else 
		IND_StageDevice19=OFF
	end if
	if 0<StageDevice20 and StageDevice20<99 and PH32_釜検知 then 
		IND_StageDevice20=ON
	else 
		IND_StageDevice20=OFF
	end if
	if 0<StageDevice21 and StageDevice21<99 and PH33_釜検知 then 
		IND_StageDevice21=ON
	else 
		IND_StageDevice21=OFF
	end if
	if 0<StageDevice22 and StageDevice22<99 and PH34_釜検知 then 
		IND_StageDevice22=ON
	else 
		IND_StageDevice22=OFF
	end if
	if 0<StageDevice23 and StageDevice23<99 and PH35_釜検知 then 
		IND_StageDevice23=ON
	else 
		IND_StageDevice23=OFF
	end if
	if 0<StageDevice24 and StageDevice24<99 and PH36_釜検知 then 
		IND_StageDevice24=ON
	else 
		IND_StageDevice24=OFF
	end if
	'-----------------------------------------------
	'むらし F2	アイテム 
	if 0<StageDevice29 and StageDevice29<99 and PH41_釜検知 then 
		IND_StageDevice29=ON
	else 
		IND_StageDevice29=OFF
	end if
	if 0<StageDevice30 and StageDevice30<99 and PH42_釜検知 then 
		IND_StageDevice30=ON
	else 
		IND_StageDevice30=OFF
	end if
	if 0<StageDevice31 and StageDevice31<99 and PH43_釜検知 then 
		IND_StageDevice31=ON
	else 
		IND_StageDevice31=OFF
	end if
	if 0<StageDevice32 and StageDevice32<99 and PH44_釜検知 then 
		IND_StageDevice32=ON
	else 
		IND_StageDevice32=OFF
	end if
	if 0<StageDevice33 and StageDevice33<99 and PH45_釜検知 then 
		IND_StageDevice33=ON
	else 
		IND_StageDevice33=OFF
	end if
	if 0<StageDevice34 and StageDevice34<99 and PH46_釜検知 then 
		IND_StageDevice34=ON
	else 
		IND_StageDevice34=OFF
	end if
	if 0<StageDevice35 and StageDevice35<99 and PH47_釜検知 then 
		IND_StageDevice35=ON
	else 
		IND_StageDevice35=OFF
	end if
	if 0<StageDevice36 and StageDevice36<99 and PH48_釜検知 then 
		IND_StageDevice36=ON
	else 
		IND_StageDevice36=OFF
	end if
	'-----------------------------------------------
	'搬送コンベアG アイテム
	if 0<StageDevice37 and StageDevice37<99 and PH49_釜検知 then 
		IND_StageDevice37=ON
	else 
		IND_StageDevice37=OFF
	end if
	if 0<StageDevice38 and StageDevice38<99 and PH50_釜検知 then 
		IND_StageDevice38=ON
	else 
		IND_StageDevice38=OFF
	end if
	if 0<StageDevice39 and StageDevice39<99 and PH51_釜検知 then 
		IND_StageDevice39=ON
	else 
		IND_StageDevice39=OFF
	end if
	if 0<StageDevice40 and StageDevice40<99 and PH53_釜検知 then 
		IND_StageDevice40=ON
	else 
		IND_StageDevice40=OFF
	end if
	'-----------------------------------------------
	'反転ほぐし アイテム
	if 0<StageDevice41 and StageDevice41<99 and PH57_釜検知 then 
		IND_StageDevice41=ON
	else 
		IND_StageDevice41=OFF
	end if
	'-----------------------------------------------
	
'----------------------------------------------------------------------------------
'強制米無し 

	pnlPBL強制米有A=pnlPB強制米有A and CR2006
	pnlPBL強制米無しA=pnlPB強制米無しA and CR2006
	
	pnlPBL強制米有B=pnlPB強制米有B and CR2006
	pnlPBL強制米無しB=pnlPB強制米無しB and CR2006
'-----------------------------------------------------------------------------------------------------------------------------
'コンベアアラーム表示
if 0 then 'コンベアアラーム表示無効

if almMC6_搬送モータ then 		'MC6
	コンベアアラーム表示=ON
else if almMC7_搬送モータ then	'MC7
	コンベアアラーム表示=ON
else if almMC8_搬送モータ then	'MC8
	コンベアアラーム表示=ON
else if almMC9_モータローラ then	'MC9
	コンベアアラーム表示=ON
else if almMC12_搬送モータ then	'MC12
	コンベアアラーム表示=ON
else if almMC13_搬送モータ then	'MC13
	コンベアアラーム表示=ON
else if almMC16_モータローラ then	'MC16
	コンベアアラーム表示=ON
else if almMC14_搬送モータ then	'MC14
	コンベアアラーム表示=ON
else if almMC15_搬送モータ then	'MC15
	コンベアアラーム表示=ON
else if almMC34_モータローラ then	'MC34
	コンベアアラーム表示=ON
else if almMC44_モータローラ then	'MC44
	コンベアアラーム表示=ON
else if almMC46_モータローラ then	'MC46
	コンベアアラーム表示=ON
else if almMC45_搬送モータ then	'MC45
	コンベアアラーム表示=ON
	
else if almMC17_モータローラ then	'MC17
	コンベアアラーム表示=ON
else if almMC18_モータローラ then	'MC18
	コンベアアラーム表示=ON
else if almMC19_モータローラ then	'MC19
	コンベアアラーム表示=ON
else if almMC20_モータローラ then	'MC20
	コンベアアラーム表示=ON
else if almMC21_モータローラ then	'MC21
	コンベアアラーム表示=ON
else if almMC22_モータローラ then	'MC22
	コンベアアラーム表示=ON
else if almMC23_モータローラ then	'MC23
	コンベアアラーム表示=ON
else if almMC24_モータローラ then	'MC24
	コンベアアラーム表示=ON
else if almMC25_モータローラ then	'MC25
	コンベアアラーム表示=ON
else if almMC26_モータローラ then	'MC26
	コンベアアラーム表示=ON
else if almMC27_モータローラ then	'MC27
	コンベアアラーム表示=ON
else if almMC28_モータローラ then	'MC28
	コンベアアラーム表示=ON
	
else if almMC29_モータローラ then	'MC29
	コンベアアラーム表示=ON
else if almMC30_モータローラ then	'MC30
	コンベアアラーム表示=ON
else if almMC31_モータローラ then	'MC31
	コンベアアラーム表示=ON
else if almMC32_モータローラ then	'MC32
	コンベアアラーム表示=ON
else if almMC33_モータローラ then	'MC33
	コンベアアラーム表示=ON
else if almMC47_モータローラ then	'MC47
	コンベアアラーム表示=ON
else if almMC48_モータローラ then	'MC48
	コンベアアラーム表示=ON
else if almMC49_モータローラ then	'MC49
	コンベアアラーム表示=ON
else if almMC50_モータローラ then	'MC50
	コンベアアラーム表示=ON
else if almMC51_モータローラ then	'MC51
	コンベアアラーム表示=ON
else if almMC52_モータローラ then	'MC52
	コンベアアラーム表示=ON
else if almMC53_モータローラ then	'MC53
	コンベアアラーム表示=ON

else if almMC41_モータローラ then	'MC41
	コンベアアラーム表示=ON
else if almMC42_モータローラ then	'MC42
	コンベアアラーム表示=ON
else if almMC43_搬送モータ then	'MC43
	コンベアアラーム表示=ON
else if almMC54_モータローラ then	'MC54
	コンベアアラーム表示=ON
	
else if almMC10_搬送モータ正転 then	'MC10正転
	コンベアアラーム表示=ON
else if almMC10_搬送モータ逆転 then	'MC10逆転
	コンベアアラーム表示=ON
else if almMC55_搬送モータ then	'MC55
	コンベアアラーム表示=ON
else if almMC57_搬送モータ then	'MC57
	コンベアアラーム表示=ON
else if almMC33_モータローラ then	'MC33
	コンベアアラーム表示=ON
else if almINV1_コンベアモータ正転 then	'INV1
	コンベアアラーム表示=ON
else if almINV2_コンベアモータ正転 then	'INV2
	コンベアアラーム表示=ON
else if almINV3_コンベアモータ正転 then	'INV3
	コンベアアラーム表示=ON
else if almMC38_搬送モータ then	'MC38
	コンベアアラーム表示=ON
else
	コンベアアラーム表示=OFF
end if

end if
'-----------------------------------------------------------------------------------------------------------------------------
'------ 納米庫BOX表示
if INDalmTHR1_張込用昇降機モータ then
	納米庫BOX表示=ON
else if INDalmTHR2_排出用昇降機モータ then
	納米庫BOX表示=ON
else if INDalmTHR3_計量機モータ then
	納米庫BOX表示=ON
else if INDalmRLY_電源確認納米庫 then
	納米庫BOX表示=ON
else
	納米庫BOX表示=OFF
end if
'------	メインBOX表示
if INDalmTHR4_送米ポンプ then
	メインBOX表示=ON
else if	INDalmTHR5_洗米羽根 then
	メインBOX表示=ON
else if INDalmDCPLC電源電圧降下 or INDalmDC電源電圧降下1 or INDalmDC電源電圧降下2 then
	メインBOX表示=ON
else
	メインBOX表示=OFF
end if
'------	浸漬タンクBOX表示
if INDalmTHR6_搬送モータ then
	浸漬タンクBOX表示=ON
else if	INDalmTHR7_搬送モータ then
	浸漬タンクBOX表示=ON
else if	INDalmTHR8_搬送モータ then
	浸漬タンクBOX表示=ON
else if	INDalmTHR11_搬送モータ then
	浸漬タンクBOX表示=ON
else if INDalmRLY_浸漬電源確認 then
	浸漬タンクBOX表示=ON
else
	浸漬タンクBOX表示=OFF
end if
'------	搬送BOX表示
if INDalmTHR9_モータローラ then
	搬送BOX表示=ON
else if INDalmTHR12_搬送モータ then
	搬送BOX表示=ON
else if INDalmTHR13_搬送モータ then
	搬送BOX表示=ON
else if INDalmTHR14_搬送モータ then
	搬送BOX表示=ON
else if INDalmTHR15_搬送モータ then
	搬送BOX表示=ON
else if INDalmTHR16_モータローラ then
	搬送BOX表示=ON
else if INDalmTHR34_モータローラ then
	搬送BOX表示=ON
else if INDalmTHR40_ならしモータ then
	搬送BOX表示=ON
else if INDalmTHR44_モータローラ then
	搬送BOX表示=ON
else if INDalmTHR45_搬送モータ then
	搬送BOX表示=ON
else if INDalmTHR46_モータローラ then
	搬送BOX表示=ON
else if INDalmRLY_搬送1電源確認 then
	搬送BOX表示=ON
else
	搬送BOX表示=OFF
end if
'------	むらしF1ABOX表示
if INDalmTHR17_モータローラ then
	むらしF1ABOX表示=ON
else if INDalmTHR18_モータローラ then
	むらしF1ABOX表示=ON
else if INDalmTHR19_モータローラ then
	むらしF1ABOX表示=ON
else if INDalmTHR20_モータローラ then
	むらしF1ABOX表示=ON
else if INDalmTHR21_モータローラ then
	むらしF1ABOX表示=ON
else if INDalmTHR22_モータローラ then
	むらしF1ABOX表示=ON
else if INDalmRLY_F1A電源確認 then
	むらしF1ABOX表示=ON
else
	むらしF1ABOX表示=OFF
end if
'------	むらしF1BBOX表示
if INDalmTHR23_モータローラ then
	むらしF1BBOX表示=ON
else if INDalmTHR24_モータローラ then
	むらしF1BBOX表示=ON
else if INDalmTHR25_モータローラ then
	むらしF1BBOX表示=ON
else if INDalmTHR26_モータローラ then
	むらしF1BBOX表示=ON
else if INDalmTHR27_モータローラ then
	むらしF1BBOX表示=ON
else if INDalmTHR28_モータローラ then
	むらしF1BBOX表示=ON
else if INDalmRLY_F1B電源確認 then
	むらしF1BBOX表示=ON
else
	むらしF1BBOX表示=OFF
end if
'------	むらしF2ABOX表示
if INDalmTHR29_モータローラ then
	むらしF2ABOX表示=ON
else if INDalmTHR30_モータローラ then
	むらしF2ABOX表示=ON
else if INDalmTHR31_モータローラ then
	むらしF2ABOX表示=ON
else if INDalmTHR32_モータローラ then
	むらしF2ABOX表示=ON
else if INDalmTHR33_モータローラ then
	むらしF2ABOX表示=ON
else if INDalmTHR47_モータローラ then
	むらしF2ABOX表示=ON
else if INDalmRLY_F2A電源確認 then
	むらしF2ABOX表示=ON
else
	むらしF2ABOX表示=OFF
end if
'------	むらしF2BBOX表示
if INDalmTHR48_モータローラ then
	むらしF2BBOX表示=ON
else if INDalmTHR49_モータローラ then
	むらしF2BBOX表示=ON
else if INDalmTHR50_モータローラ then
	むらしF2BBOX表示=ON
else if INDalmTHR51_モータローラ then
	むらしF2BBOX表示=ON
else if INDalmTHR52_モータローラ then
	むらしF2BBOX表示=ON
else if INDalmTHR53_モータローラ then
	むらしF2BBOX表示=ON
else if INDalmRLY_F2B電源確認 then
	むらしF2BBOX表示=ON
else
	むらしF2BBOX表示=OFF
end if
'------	搬送BOX2表示
if INDalmTHR10_搬送モータ then	
	搬送BOX2表示=ON
else if INDalmTHR41_モータローラ then
	搬送BOX2表示=ON
else if INDalmTHR42_モータローラ then
	搬送BOX2表示=ON
else if INDalmTHR43_搬送モータ then
	搬送BOX2表示=ON
else if INDalmTHR54_モータローラ then
	搬送BOX2表示=ON
else if INDalmTHR55_搬送モータ then
	搬送BOX2表示=ON
else if INDalmTHR56_ブラシサーマル then
	搬送BOX2表示=ON
else if INDalmTHR57_搬送モータ then
	搬送BOX2表示=ON
else if INDalmRLY_搬送2電源確認 then
	搬送BOX2表示=ON
else
	搬送BOX2表示=OFF
end if
'------	洗浄機BOX表示
if INDalmTHR36_反転モータ then	
	洗浄機BOX表示=ON
else if INDalmTHR35_搬送モータ then
	洗浄機BOX表示=ON
else if INDalmTHR37_反転モータ then
	洗浄機BOX表示=ON
else if INDalmTHR38_搬送モータ then
	洗浄機BOX表示=ON
else if INDalmTHR58_洗浄ポンプA then
	洗浄機BOX表示=ON
else if INDalmTHR59_洗浄ポンプB then
	洗浄機BOX表示=ON
else if INDalmTHR60_洗浄ポンプC then
	洗浄機BOX表示=ON
else if INDalmTHR61_洗浄ポンプD then
	洗浄機BOX表示=ON
else if INDalmINV1_コンベア異常 then
	洗浄機BOX表示=ON
else if INDalmINV2_コンベア異常 then
	洗浄機BOX表示=ON
else if INDalmINV3_コンベア異常 then
	洗浄機BOX表示=ON
else if INDalmRLY_洗浄機電源確認 then
	洗浄機BOX表示=ON
else
	洗浄機BOX表示=OFF
end if
'------	サブBOX1表示
if INDalmRLY_サブ2電源確認 then	
	サブBOX1表示=ON
else
	サブBOX1表示=OFF
end if
'------	サブBOX2表示
if INDalmRLY_サブ2電源確認 then	
	サブBOX2表示=ON
else
	サブBOX2表示=OFF
end if
'------	反転ほぐし機BOX表示
if INDalmRLY_反転機電源確認 then	
	反転機BOX表示=ON
else
	反転機BOX表示=OFF
end if
	
'-----------------------------------------------------------------------------------------------------------------------------
if ldp(INDalmビットクリア) then
	FMOV(0,R90000.U,49)
end if
'-----------------------------------------------------------------------------------------------------------------------------

INDpnlPBXSW=pnlPBXSW3_水切りシャッター開A or pnlPBXSW4_水切りシャッター閉A
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW7_水切りシャッター開B or pnlPBXSW8_水切りシャッター閉B
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW14_ストッパ上昇端 or pnlPBXSW15_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW16_ストッパ上昇端 or pnlPBXSW17_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW18_ストッパ上昇端 or pnlPBXSW19_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW20_リフト下降端 or pnlPBXSW21_リフト上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW22_ストッパ下降端 or pnlPBXSW23_ストッパ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW24_リフト下降端 or pnlPBXSW25_リフト上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW26_クランプ下降端 or pnlPBXSW27_クランプ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW28_ストッパ下降端 or pnlPBXSW29_ストッパ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW30_クランプ下降端 or pnlPBXSW31_クランプ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW32_ストッパ下降端 or pnlPBXSW33_ストッパ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW34_リフト上昇端 or pnlPBXSW35_リフト下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW36_ストッパ下降端 or pnlPBXSW37_ストッパ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW51_ストッパ上昇端 or pnlPBXSW52_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW53_リフト上昇端 or pnlPBXSW54_リフト下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW55_リフト上昇端 or pnlPBXSW56_リフト下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW57_リフト上昇端 or pnlPBXSW58_リフト下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW59_ストッパ上昇端 or pnlPBXSW60_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW61_ストッパ上昇端 or pnlPBXSW62_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW63_ストッパ上昇端 or pnlPBXSW64_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW65_ストッパ上昇端 or pnlPBXSW66_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW67_リフト上昇端 or pnlPBXSW68_リフト下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW80_リフト上昇端 or pnlPBXSW81_リフト下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW85_釜フタストッパ下降端 or pnlPBXSW90_釜フタストッパ下降端 or pnlPBXSW95_釜フタストッパ下降端 or pnlPBXSW100_釜フタストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW17_ストッパ下降端 or pnlPBXSW18_ストッパ上昇端

'----------------------------------------------------------------------------------------------------------------------------
アイテムNO有効_STG1=not(アイテムNOの変更有効) and PH1_釜検知
アイテムNO有効_STG2=not(アイテムNOの変更有効) and PH3_釜検知
アイテムNO有効_STG3=not(アイテムNOの変更有効) and PH5_釜検知
アイテムNO有効_STG4=not(アイテムNOの変更有効) and PH7_釜検知
アイテムNO有効_STG5=not(アイテムNOの変更有効) and PH9_釜検知
アイテムNO有効_STG6=not(アイテムNOの変更有効) and PH11_釜検知
アイテムNO有効_STG7=not(アイテムNOの変更有効) and PH13_釜検知
アイテムNO有効_STG8=not(アイテムNOの変更有効) and PH15_釜検知
アイテムNO有効_STG9=not(アイテムNOの変更有効) and PH17_釜検知
アイテムNO有効_STG10=not(アイテムNOの変更有効) and PH19_釜検知
アイテムNO有効_STG11=not(アイテムNOの変更有効) and PH21_釜検知
アイテムNO有効_STG12=not(アイテムNOの変更有効) and PH22_釜検知
アイテムNO有効_STG13=not(アイテムNOの変更有効) and PH24_釜検知
'-----------------------------------------------------------------------------------------------------------------------------

