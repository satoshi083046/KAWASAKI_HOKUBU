'浸漬タンクAユニット
'===================================================================================================================
'
'<<<<<<<	ユニット	>>>>>>>>
'
'
'	浸漬タンクA
'
'PH1_釜検知	->	PH3_釜検知
'PH2_フタ検知  -> PH4_フタ検知

'===================================================================================================================
客先コード=川崎北部
'===================================================================================================================
select case 客先コード

case 川崎南部
	ADRSET(PH1_釜検知.B,pPH_釜検知.D)
	ADRSET(PH2_フタ検知.B,pPH_フタ検知.D)

case 川崎北部
	ADRSET(PH3_釜検知.B,pPH_釜検知.D)
	ADRSET(PH4_フタ検知.B,pPH_フタ検知.D)

end select
'===================================================================================================================
'【 初期化処理 】
if CR2008 then
    浸漬タンクAユニットAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    浸漬タンクAユニットAutoRun=OFF
    浸漬タンクAユニット許可=OFF
    浸漬タンクAユニットOrgErr=OFF
    浸漬タンクAユニットErr=OFF
    浸漬タンクAユニットEmg=OFF
    浸漬タンクAユニットstep=0
    浸漬タンクAユニットErrStep=0
    浸漬タンクAユニットOrgErrStep=0
    浸漬タンクAユニットEmgStep=0

	浸漬Aワンサイクルflg=OFF
	
	配米準備step=0
	シャッター開閉step=0

end if

'===================================================================================================================
'【 原点 】 
浸漬タンクAユニットOrg= not(浸漬タンクAユニット許可) or (XSW2_充填バルブ閉A and ((XSW4_水切りシャッター閉A and not(pnlPBXSW4_水切りシャッター閉A)) or passXSW4_水切りシャッター閉A))

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	浸漬タンクAユニットEmg=ON
	浸漬タンクAユニットEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】

tmr(SV2_充填バルブ開A and not(XSW1_充填バルブ開A) and not(pnlPBXSW1_充填バルブ開A),tim_充填バルブ開A,#30)
tmr(not(SV2_充填バルブ開A) and not(XSW2_充填バルブ閉A) and not(pnlPBXSW2_充填バルブ閉A),tim_充填バルブ閉A,#30)
tmr(SSW3_自動モード and (SV4_水切りシャッター開A or KeepSV4_水切りシャッター開A) and not(XSW3_水切りシャッター開A) and not(pnlPBXSW3_水切りシャッター開A),tim_not水切りシャッター開A,#50)
tmr(SSW3_自動モード and (SV5_水切りシャッター閉A or KeepSV5_水切りシャッター閉A) and not(XSW4_水切りシャッター閉A) and not(pnlPBXSW4_水切りシャッター閉A),tim_not水切りシャッター閉A,#50)

'tmr((SV5_水切りシャッター閉A or KeepSV5_水切りシャッター閉A) and XSW3_水切りシャッター開A and not(pnlPBXSW3_水切りシャッター開A),tim_水切りシャッター開A,#20)
if LDP(SV4_水切りシャッター開A) and XSW3_水切りシャッター開A and not(pnlPBXSW3_水切りシャッター開A) then
	SET(tim_水切りシャッター開A)
end if
'tmr((SV4_水切りシャッター開A or KeepSV4_水切りシャッター開A) and XSW4_水切りシャッター閉A and not(pnlPBXSW4_水切りシャッター閉A),tim_水切りシャッター閉A,#20)
if LDP(SV5_水切りシャッター閉A) and XSW4_水切りシャッター閉A and not(pnlPBXSW4_水切りシャッター閉A) then
	SET(tim_水切りシャッター閉A)
end if
tmr(SV60_排水バルブ開A and not(XSW76_排水バルブ開A) and not(pnlPBXSW76_排水バルブ開A), tim_排水バルブ開A,#30)
tmr(not(SV60_排水バルブ開A) and not(XSW77_排水バルブ閉A) and not(pnlPBXSW77_排水バルブ閉A),tim_排水バルブ閉A,#30)


if SV4_水切りシャッター開A and not(SV5_水切りシャッター閉A) then
	KeepSV4_水切りシャッター開A=ON
else if SV5_水切りシャッター閉A then
	KeepSV4_水切りシャッター開A=OFF
end if

if SV5_水切りシャッター閉A and not(SV4_水切りシャッター開A) then
	KeepSV5_水切りシャッター閉A=ON
else if SV4_水切りシャッター開A then
	KeepSV5_水切りシャッター閉A=OFF
end if

tms(KeepSV4_水切りシャッター開A,passtimXSW3_水切りシャッター開A,passtimXSW3_水切りシャッター開A_val)
tms(KeepSV5_水切りシャッター閉A,passtimXSW4_水切りシャッター閉A,passtimXSW4_水切りシャッター閉A_val)

if ldp(tim_充填バルブ開A.B) then
	errpassXSW1_充填バルブ開A=ON
	almXSW1_充填バルブ開A=ON
	浸漬タンクAユニットErrStep=1
else if ldp(tim_充填バルブ閉A.B) then
	errpassXSW2_充填バルブ閉A=ON
	almXSW2_充填バルブ閉A=ON
	浸漬タンクAユニットErrStep=1
else if ldp(tim_水切りシャッター開A.B) or ldp(tim_not水切りシャッター開A.B) then
	errpassXSW3_水切りシャッター開A=ON
	almXSW3_水切りシャッター開A=ON
	pnlPBXSW3_水切りシャッター開A=ON
	浸漬タンクAユニットErrStep=1
else if ldp(tim_水切りシャッター閉A.B) or ldp(tim_not水切りシャッター閉A.B) then
	errpassXSW4_水切りシャッター閉A=ON
	almXSW4_水切りシャッター閉A=ON
	pnlPBXSW4_水切りシャッター閉A=ON
	浸漬タンクAユニットErrStep=1
else if ldp(tim_排水バルブ開A.B) then
	almXSW76_排水バルブ開A=ON
	浸漬タンクAユニットErrStep=1
else if ldp(tim_排水バルブ閉A.B) then
	almXSW77_排水バルブ閉A=ON
	浸漬タンクAユニットErrStep=1
end if




'===================================================================================================================
' PLインジケータ
	if not(自動搬送AutoMode) or not(浸漬タンクAユニットAutoMode) or 浸漬タンクA米無し then
		PBL9_自動配米=浸漬Aワンサイクルflg and CR2006
	else
		PBL9_自動配米=OFF
	end if
	
	'-------------------------------------------------------------
	PBL10_タンク給水A=SV6_給水電磁弁A

	if ldp(PB10_タンク給水A or pnlPBSV6_給水電磁弁A) then
		if mSV6_給水電磁弁A then
			mSV6_給水電磁弁A=OFF
		else
			mSV6_給水電磁弁A=ON
		end if
	end if
	'-------------------------------------------------------------
	PBL30_排水バルブ開閉A=SV60_排水バルブ開A or XSW76_排水バルブ開A

	if ldp(PB30_排水バルブ開閉A or pnlPBSV60_排水バルブ開A ) then
		if XSW77_排水バルブ閉A then
			mSV60_排水バルブ開A=ON
		else if XSW76_排水バルブ開A then
			mSV60_排水バルブ開A=OFF
		else
			mSV60_排水バルブ開A=OFF
		end if
	end if
	'-------------------------------------------------------------
	PBL7_充填バルブA=SV2_充填バルブ開A and not(tPBL7_充填バルブA and CR2006)
	tmr(PB7_充填バルブA,tim_PB7_充填バルブA,#30)
	
	select case 充填バルブstep

	case 0
		tPBL7_充填バルブA=OFF

		'通常のON/OFF動作
		if not(mSV2_充填バルブ開A) and not(SV4_水切りシャッター開A) then
			ejectSV2_充填バルブ開A=PB7_充填バルブA
		else
			ejectSV2_充填バルブ開A=OFF
		end if
		
		if tim_PB7_充填バルブA.B then
			inc(充填バルブstep)
		end if
		
	case 1
		'PB7_充填バルブA OFF待ち		
		tPBL7_充填バルブA=ON
		
		if not(mSV2_充填バルブ開A) and not(SV4_水切りシャッター開A) then
			ejectSV2_充填バルブ開A=ON
		else
			ejectSV2_充填バルブ開A=OFF
		end if
		
		if not(tim_PB7_充填バルブA.B) then
			inc(充填バルブstep)
		end if


	case 2
		'PB7_充填バルブA 
		tPBL7_充填バルブA=ON

		if PB7_充填バルブA or mSV2_充填バルブ開A or SV4_水切りシャッター開A then
			ejectSV2_充填バルブ開A=OFF
			充填バルブstep=0
		end if
	
	end select
	
	'-------------------------------------------------------------	
	PBL8_水切りシャッターA=KeepSV4_水切りシャッター開A

	if ldp(PB8_水切りシャッターA) then
		if not(tPBL8_水切りシャッターA) and not(SV2_充填バルブ開A) then
			mSV4_水切りシャッター開A=ON
			mSV5_水切りシャッター閉A=OFF
			tPBL8_水切りシャッターA=ON

			if 自動搬送AutoMode and 自動搬送AutoRun then			
				if ANDA(StageDevice0,$200)=0 and ANDA(StageDevice1,$200)=0 then  
					inc(DM_A配米現在値)
				end if
			end if
			
			if ITEM登録禁止 then
				StageDevice0=ORA(StageDevice0,$200)
				StageDevice1=ORA(StageDevice1,$200)			
			else
				StageDevice0=ORA(ORA(StageDevice0,$200),tm_ITEMNO)
				StageDevice1=ORA(ORA(StageDevice1,$200),tm_ITEMNO)
			end if

		else if tPBL8_水切りシャッターA then
			mSV4_水切りシャッター開A=OFF
			mSV5_水切りシャッター閉A=ON
			tPBL8_水切りシャッターA=OFF
		end if
	end if

'	if not(mSV4_水切りシャッター開A) then
'		tPBL8_水切りシャッターA=OFF
'	end if
	'-------------------------------------------------------------	


'===================================================================================================================
' センサー検出ディレイ―

	tmr(PDL2_パドルセンサー下限A or pnlPBPDL2_パドルセンサー下限A,tim_PDL2_パドルセンサー下限A,20)
	tmr(RLY5_パドルセンサ電源 and not(PDL2_パドルセンサー下限A),timnot_PDL2_パドルセンサー下限A,60)

'===================================================================================================================
' 充填バルブ開閉

	'FLOS03_LMT121ALM 
	'SV2_充填バルブ開A
	
	tmr(not(FLOS3_LMT121),timdly_FLOS03_LMT121,20)
	tmr(FLOS3_LMT121,timnotdly_FLOS03_LMT121,20)

	if pnlPB強制米有A then
		浸漬タンクA米無し=OFF
	else if pnlPB強制米無しA then
		浸漬タンクA米無し=ON '米センサーOFF and パドルセンサー下限OFF
	else if timdly_FLOS03_LMT121.B or tim_PDL2_パドルセンサー下限A.B then
		浸漬タンクA米無し=OFF '米センサーON or パドルセンサー下限  or pnlPBパドルセンサー下限
	else if timnotdly_FLOS03_LMT121.B and timnot_PDL2_パドルセンサー下限A.B then
		浸漬タンクA米無し=ON '米センサーOFF and パドルセンサー下限OFF
	end if
	

	if ldp(浸漬タンクAユニットAutoRun) then
		初期充填動作=ON
	end if
	
'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 浸漬タンクAユニットAutoMode	自動モード セレクトスイッチ
'System :: 浸漬タンクAユニットAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能
'System :: 浸漬タンクAユニットEmg	その場停止


if 浸漬タンクAユニットEmgStep=0 then  
	
	if 浸漬タンクAユニットErrStep=0  then
	
	if not(浸漬タンクAユニットOrgErr) then

		'---------------------------------------------------------------------------------
		tmr(tim_配米準備,tim_配米準備_val)
		select case 配米準備step

		case 0

		'1回目_充填バルブ1秒間_開閉
		
		case 1		
			if 浸漬Aワンサイクルflg or not(浸漬タンクA米無し) then
				浸漬タンクAユニットStatusMsg=#12	'	浸漬中
				inc(配米準備step)
			else
				浸漬タンクAユニットStatusMsg=#0	'	浸漬中
				
				配米準備完了A=ON
				配米完了A=ON
				配米準備step=0
			end if	

		case 2
			if 浸漬タンクA米無し then
				inc(配米準備step)
				
			else		
				mSV2_充填バルブ開A=ON
				'mSV3_充填バルブ閉A=OFF
				errpassXSW1_充填バルブ開A=OFF
				inc(配米準備step)
			end if
			
		case 3
			if mSV2_充填バルブ開A then
				if errpassXSW1_充填バルブ開A or XSW1_充填バルブ開A  then
					inc(配米準備step)
				end if
			else
				inc(配米準備step)
			end if			

		case 4
			'mSV2_充填バルブ開A=OFF
			if 初期充填動作 or 浸漬Aワンサイクルflg then				
				tim_配米準備_val=#50 '1回目充填バルブ開き時間
				res(tim_配米準備)
			else
				tim_配米準備_val=#15 '1回目充填バルブ開き時間
				res(tim_配米準備)
			end if			
			
			inc(配米準備step)
			
		case 5
			if tim_配米準備.B or 浸漬タンクA米無し then
				inc(配米準備step)
			end if

		case 6
			'mSV3_充填バルブ閉A=ON
			mSV2_充填バルブ開A=OFF
			errpassXSW2_充填バルブ閉A=OFF
			inc(配米準備step)

		case 7
			if errpassXSW2_充填バルブ閉A or XSW2_充填バルブ閉A then
				inc(配米準備step)
			end if

		case 8
			'mSV3_充填バルブ閉A=OFF
			tim_配米準備_val=#10 '1回目充填バルブ閉時間
			res(tim_配米準備)
			inc(配米準備step)

		'-------------------------------------------------------------------------------------------
		'2回目_充填バルブ1秒間_開閉
		case 9
			浸漬タンクAユニットStatusMsg=#12	'	浸漬中
			inc(配米準備step)

		case 10
			if 浸漬タンクA米無し then
				inc(配米準備step)
			
			else if tim_配米準備.B then
				mSV2_充填バルブ開A=ON
				errpassXSW1_充填バルブ開A=OFF
				inc(配米準備step)
			end if

		case 11
			if mSV2_充填バルブ開A then
				if errpassXSW1_充填バルブ開A or XSW1_充填バルブ開A then
					inc(配米準備step)
				end if
			else
				inc(配米準備step)			
			end if

		case 12
			'mSV2_充填バルブ開A=OFF
			if 初期充填動作 or 浸漬Aワンサイクルflg then				
				tim_配米準備_val=#50 '1回目充填バルブ開き時間
				res(tim_配米準備)
			else
				tim_配米準備_val=#15 '1回目充填バルブ開き時間
				res(tim_配米準備)
			end if			

			inc(配米準備step)
			
		case 13
			if tim_配米準備.B or 浸漬タンクA米無し then
				inc(配米準備step)
			end if

		case 14
			'mSV3_充填バルブ閉A=ON
			mSV2_充填バルブ開A=OFF
			errpassXSW2_充填バルブ閉A=OFF
			inc(配米準備step)

		case 15
			if errpassXSW2_充填バルブ閉A or XSW2_充填バルブ閉A then
				inc(配米準備step)
			end if

		case 16
			'mSV3_充填バルブ閉A=OFF
			tim_配米準備_val=#10 '1回目充填バルブ閉時間
			res(tim_配米準備)
			inc(配米準備step)

		'---------------------------------------------------------------------------------
		
		'充填バルブ_開閉
		case 17
			浸漬タンクAユニットStatusMsg=#12	'	浸漬中
			inc(配米準備step)

		case 18
			if 浸漬タンクA米無し then
				inc(配米準備step)
			
			else if tim_配米準備.B then
				mSV2_充填バルブ開A=ON
				errpassXSW1_充填バルブ開A=OFF
				inc(配米準備step)
			end if

		case 19
			if mSV2_充填バルブ開A then
				if errpassXSW1_充填バルブ開A or XSW1_充填バルブ開A then
					inc(配米準備step)
				end if
			else
				inc(配米準備step)			
			end if

		case 20
			'mSV2_充填バルブ開A=OFF
			tim_配米準備_val=#10 '充填バルブ開時間
			res(tim_配米準備)
			inc(配米準備step)
			
		case 21
			if tim_配米準備.B or 浸漬タンクA米無し then
				inc(配米準備step)
			end if

		case 22
			'mSV3_充填バルブ閉A=ON
			mSV2_充填バルブ開A=OFF
			errpassXSW2_充填バルブ閉A=OFF
			inc(配米準備step)

		case 23
			if errpassXSW2_充填バルブ閉A or XSW2_充填バルブ閉A then
				inc(配米準備step)
			end if

		case 24
			tim_配米準備_val=#10
			res(tim_配米準備)
			inc(配米準備step)
			
		case 25
			if tim_配米準備.B then
				inc(配米準備step)
			end if
		
		'-------------------------------------------------------------------------------
		'充填バルブ4回目
		case 26
			if 初期充填動作 or 浸漬Aワンサイクルflg then
				inc(配米準備step)
			else
				配米準備step=100
			end if
		
		case 27
			if 浸漬タンクA米無し then
				inc(配米準備step)
			
			else 
				mSV2_充填バルブ開A=ON
				errpassXSW1_充填バルブ開A=OFF
				inc(配米準備step)
			end if
			
		case 28
			if mSV2_充填バルブ開A then
				if errpassXSW1_充填バルブ開A or XSW1_充填バルブ開A then
					inc(配米準備step)
				end if
			else
				inc(配米準備step)			
			end if

		case 29
			'mSV2_充填バルブ開A=OFF
			tim_配米準備_val=#10 '充填バルブ開時間
			res(tim_配米準備)
			inc(配米準備step)
			
		case 30
			if tim_配米準備.B or 浸漬タンクA米無し then
				inc(配米準備step)
			end if

		case 31
			'mSV3_充填バルブ閉A=ON
			mSV2_充填バルブ開A=OFF
			errpassXSW2_充填バルブ閉A=OFF
			inc(配米準備step)

		case 32
			if errpassXSW2_充填バルブ閉A or XSW2_充填バルブ閉A then
				inc(配米準備step)
			end if

		case 33
			tim_配米準備_val=#10
			res(tim_配米準備)
			inc(配米準備step)
			
		case 34
			if tim_配米準備.B then
				inc(配米準備step)
			end if
		'-------------------------------------------------------------------------------
		'充填バルブ5回目
		case 35
			if 浸漬タンクA米無し then
				inc(配米準備step)
			
			else		
				mSV2_充填バルブ開A=ON
				errpassXSW1_充填バルブ開A=OFF
				inc(配米準備step)
			end if
			
		case 36
			if mSV2_充填バルブ開A then
				if errpassXSW1_充填バルブ開A or XSW1_充填バルブ開A then
					inc(配米準備step)
				end if
			else
				inc(配米準備step)			
			end if

		case 37
			'mSV2_充填バルブ開A=OFF
			tim_配米準備_val=#10 '充填バルブ開時間
			res(tim_配米準備)
			inc(配米準備step)
			
		case 38
			if tim_配米準備.B or 浸漬タンクA米無し then
				inc(配米準備step)
			end if

		case 39
			'mSV3_充填バルブ閉A=ON
			mSV2_充填バルブ開A=OFF
			errpassXSW2_充填バルブ閉A=OFF
			inc(配米準備step)

		case 40
			if errpassXSW2_充填バルブ閉A or XSW2_充填バルブ閉A then
				配米準備step=100
			end if

		'-------------------------------------------------------------------------------
		'水切り時間
		case 100
			tim_配米準備_val=#20 '水切り時間
			res(tim_配米準備)
			inc(配米準備step)

		case 101
			if tim_配米準備.B then
				inc(配米準備step)
			end if

		'-------------------------------------------------------------------------------
		case 102
			if 浸漬タンクA米無し then
				inc(配米準備step)
			
			else		
				mSV2_充填バルブ開A=ON
				errpassXSW1_充填バルブ開A=OFF
				inc(配米準備step)
			end if
			
		case 103
			if mSV2_充填バルブ開A then
				if errpassXSW1_充填バルブ開A or XSW1_充填バルブ開A then
					inc(配米準備step)
				end if
			else
				inc(配米準備step)			
			end if

		case 104
			if 初期充填動作 or 浸漬Aワンサイクルflg then				
				tim_配米準備_val=#50 '1回目充填バルブ開き時間
				res(tim_配米準備)
			else
				tim_配米準備_val=#20 '1回目充填バルブ開き時間
				res(tim_配米準備)
			end if			

			inc(配米準備step)
			
		case 105
			if tim_配米準備.B or 浸漬タンクA米無し then
				inc(配米準備step)
			end if

		case 106
			mSV2_充填バルブ開A=OFF
			errpassXSW2_充填バルブ閉A=OFF
			inc(配米準備step)

		case 107
			if errpassXSW2_充填バルブ閉A or XSW2_充填バルブ閉A then
				inc(配米準備step)
			end if

		'-------------------------------------------------------------------------------
		case 108
			'mSV3_充填バルブ閉A=OFF
			tim_配米準備_val=#80 '水切り時間
			res(tim_配米準備)
			inc(配米準備step)

		case 109
			if tim_配米準備.B then
				inc(配米準備step)
			end if

		case 110
			浸漬タンクAユニットStatusMsg=#0	'	浸漬中

			配米準備完了A=ON
			if DM_浸漬タンクA貯米釜数>0 then
				dec(DM_浸漬タンクA貯米釜数)
				DM_Aタンク補正釜数=DM_Aタンク補正値	
				
				if pnlPBPDL2_パドルセンサー下限A then
					DM_Aタンク補正釜数=0
				else
					DM_Aタンク補正釜数=DM_Aタンク補正値				
				end if
				
			else if DM_Aタンク補正釜数>0 then  
				dec(DM_Aタンク補正釜数)
			
			end if
			
			if 浸漬Aワンサイクルflg and シャッター開閉step=0 then
				シャッター開閉step=1
			end if
			
			配米準備step=0
			初期充填動作=OFF


		end select
		'===================================================================================================================
		'シャッター開閉
		tmr(tim_シャッター開閉,tim_シャッター開閉_val)
		select case シャッター開閉step
		case 0
		case 1
			if 浸漬Aワンサイクルflg or (not(浸漬タンクA米無し) and 配米準備完了A) then
				浸漬タンクAユニットStatusMsg=#13	'	配米中
				errpassXSW3_水切りシャッター開A=OFF
				errpassXSW4_水切りシャッター閉A=OFF

				inc(シャッター開閉step)
			else
				if 浸漬タンクA米無し then
					配米準備完了A=OFF
					配米完了A=OFF
				end if
				
				浸漬タンクAユニットStatusMsg=#0	'	配米中
				シャッター開閉step=0
			end if
			
		case 2
			mSV4_水切りシャッター開A=ON
			mSV5_水切りシャッター閉A=OFF
			errpassXSW3_水切りシャッター開A=OFF
			inc(シャッター開閉step)

		case 3
			if mSV4_水切りシャッター開A then
				if errpassXSW3_水切りシャッター開A or ((XSW3_水切りシャッター開A and not(pnlPBXSW3_水切りシャッター開A)) or passXSW3_水切りシャッター開A) then
					inc(シャッター開閉step)
				end if
			else
				inc(シャッター開閉step)
			end if

		case 4
			mSV4_水切りシャッター開A=OFF
			tim_シャッター開閉_val=#10 '水切りシャッター開時間
			res(tim_シャッター開閉)
			inc(シャッター開閉step)

		case 5
			if tim_シャッター開閉.B then
				inc(シャッター開閉step)
			end if
			
		case 6
			mSV5_水切りシャッター閉A=ON
			errpassXSW4_水切りシャッター閉A=OFF
			inc(シャッター開閉step)

		case 7
			if mSV5_水切りシャッター閉A then
				if errpassXSW4_水切りシャッター閉A or ((XSW4_水切りシャッター閉A and not(pnlPBXSW4_水切りシャッター閉A)) or passXSW4_水切りシャッター閉A) then
					inc(シャッター開閉step)
				end if
			else
				inc(シャッター開閉step)			
			end if

		case 8
			mSV5_水切りシャッター閉A=OFF
			tim_シャッター開閉_val=10	'水切りシャッター閉時間
			res(tim_シャッター開閉)
			inc(シャッター開閉step)

		case 9
			if tim_シャッター開閉.B then
				inc(シャッター開閉step)
			end if

		'---------------------------------------------------------------------------------
		' 2回目の水切りシャッター
		case 10
			mSV4_水切りシャッター開A=ON
			mSV5_水切りシャッター閉A=OFF
			errpassXSW3_水切りシャッター開A=OFF
			inc(シャッター開閉step)

		case 11
			if mSV4_水切りシャッター開A then 
				if errpassXSW3_水切りシャッター開A or ((XSW3_水切りシャッター開A and not(pnlPBXSW3_水切りシャッター開A)) or passXSW3_水切りシャッター開A) then
					inc(シャッター開閉step)
				end if
			else
				inc(シャッター開閉step)			
			end if
		case 12
			mSV4_水切りシャッター開A=OFF
			tim_シャッター開閉_val=#40 '水切りシャッター開時間
			res(tim_シャッター開閉)				
			inc(シャッター開閉step)

		case 13
			if tim_シャッター開閉.B then
				inc(シャッター開閉step)
			end if
			
		case 14
			mSV5_水切りシャッター閉A=ON
			errpassXSW4_水切りシャッター閉A=OFF
			inc(シャッター開閉step)

		case 15
			if mSV5_水切りシャッター閉A then
				if errpassXSW4_水切りシャッター閉A or ((XSW4_水切りシャッター閉A and not(pnlPBXSW4_水切りシャッター閉A)) or passXSW4_水切りシャッター閉A) then
					inc(シャッター開閉step)
				end if
			else
				inc(シャッター開閉step)			
			end if
			
		case 16
			mSV5_水切りシャッター閉A=OFF
			tim_シャッター開閉_val=10'水切りシャッター閉時間
			res(tim_シャッター開閉)
			inc(シャッター開閉step)

		'---------------------------------------------------------------------------------
		case 17
			if tim_シャッター開閉.B then
				inc(シャッター開閉step)
			end if

		case 18
			浸漬タンクAユニットStatusMsg=#0	'	配米中

			配米準備完了A=OFF
			配米完了A=ON
			if not(浸漬Aワンサイクルflg) then 
				StageDevice1=ORA(ORA(StageDevice1,$200),tm_ITEMNO)
			end if
			浸漬Aワンサイクルflg=OFF

			浸漬タンクA排出要求=ON
			
			inc(DM_A配米現在値)
			
			シャッター開閉step=0
		end select

	'===================================================================================================================
	'【 プロセス処理（配米） 】
	'
	if (not(浸漬タンクA米無し) and  浸漬タンクAユニットAutoMode and 自動搬送AutoMode ) or  浸漬タンクAユニットstep<>0  then
		if not(浸漬タンクAユニットAutoMode and 自動搬送AutoMode ) then
			浸漬タンクAユニットAutoRun=OFF
		end if

		tmr(tim_procstep,tim_procstep_val)

		select case 浸漬タンクAユニットstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' 作業工程を振り分ける
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 浸漬タンクAユニットAutoRun then
				inc(浸漬タンクAユニットstep)
			else 
				浸漬タンクAユニット動作中=OFF
				浸漬タンクAユニットstep=0 '終了待機
			end if
		
		case 2
		' [ 浸漬タンク釜数確認 ]
			if not(浸漬タンクA米無し)  then
				inc(浸漬タンクAユニットstep)
			else
				浸漬タンクA排出要求=ON
				配米準備完了A=OFF
				配米完了A=OFF
				浸漬タンクAユニットstep=1
			end if
		
		case 3
			' [ ユニット許可検出 ]
			if 浸漬タンクAユニット許可 and DM_ITEMNO>0 then
				'タンク米有
				tm_ITEMNO=DM_ITEMNO
				浸漬タンクAユニット動作中=ON
				浸漬タンクBユニット動作中=OFF
				inc(浸漬タンクAユニットstep)
			else
				'タンク米無し
				配米完了A=ON				
				浸漬タンクAユニット動作中=OFF
				浸漬タンクA排出要求=ON
				浸漬タンクAユニットstep=1
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		case 4
			'配米準備完了A=OFF 毎サイクル配米準備をしない
			if 配米準備完了A then
				inc(浸漬タンクAユニットstep)
			else 
				if DM_A配米現在値<DM_A配米設定値 then
					if 配米準備step=0 then
						配米準備step=1
						浸漬タンクAユニットstep=1
					end if
				
				 else
					浸漬タンクA排出要求=ON
					浸漬タンクAユニットstep=1
				end if				
			end if			

		case 5
			if 配米完了A then
				浸漬タンクAユニットStatusMsg=#14	'	配米完了				浸漬タンクA排出要求=ON
				浸漬タンクA排出要求=ON
				浸漬タンクAユニットstep=1
			else
				inc(浸漬タンクAユニットstep)
			end if

		'---------------------------------------------------------------------------------
		case 6					
				' [ 蓋カマ移動停止確認 ]
			if 浸漬タンクA排出要求=OFF and 搬送コンベアA動作中=OFF then

				'[ 自ステージに"釜"有検出 ]
					if *pPH_釜検知.B and *pPH_フタ検知.B  then
						if ANDA(StageDevice1,$100)=$100 and ANDA(StageDevice1,$200)=0 then
							if not(配米完了A) and シャッター開閉step=0 then
								シャッター開閉step=1
							end if	
						else
							浸漬タンクA排出要求=ON
						end if
						浸漬タンクAユニットstep=1

				'[ 自ステージに"フタ"有検出 ]	
					else if not(*pPH_釜検知.B) and *pPH_フタ検知.B then 
						浸漬タンクA排出要求=ON
						浸漬タンクAユニットstep=1
				
				'[ 自ステージに"釜フタ"なし ]
						else
							浸漬タンクA排出要求=ON
							浸漬タンクAユニットstep=1
					end if
			else			
				
				浸漬タンクAユニットstep=1
			
			end if
		'---------------------------------------------------------------------------------

		end select

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		if 浸漬タンクAユニットstep=0 and 浸漬タンクA米無し then
			浸漬タンクA排出要求=ON
		end if
	
	
	
		浸漬タンクAユニットAutoRun=OFF
		
		浸漬タンクAユニットstep=0 '終了
		配米準備完了A=OFF
		配米完了A=OFF
		
		'res(tim_充填バルブ開A.B)
		'res(tim_充填バルブ閉A.B)
		'res(tim_水切りシャッター開A.B) 
		'res(tim_水切りシャッター閉A.B)
		'res(tim_排水バルブ開A.B)
		'res(tim_排水バルブ閉A.B)

		
		if 浸漬タンクAユニットstep=0 and 配米準備step=0 and シャッター開閉step=0 then
			if not(浸漬タンクAユニットAutoMode and 自動搬送AutoMode ) then
				'-------------------------------------------------------------	
				'充填１サイクル
				if ldp(PB9_自動配米A ) and 浸漬Aワンサイクルflg=OFF  then
					if XSW2_充填バルブ閉A and ((XSW4_水切りシャッター閉A and not(pnlPBXSW4_水切りシャッター閉A)) or passXSW4_水切りシャッター閉A) then
						mSV2_充填バルブ開A=OFF
						mSV4_水切りシャッター開A=OFF
						mSV5_水切りシャッター閉A=OFF
						浸漬Aワンサイクルflg=ON
						配米準備step=1
					end if
				end if
				'-------------------------------------------------------------	
				if ldp(pnlPBSV2_充填バルブ開A ) then
					if XSW2_充填バルブ閉A then
						mSV2_充填バルブ開A=ON
					else if XSW1_充填バルブ開A then
						mSV2_充填バルブ開A=OFF
					end if
				end if

			end if
			'パネルスイッチでの操作
			if ldp(pnlPBSV4_水切りシャッター開A) then
				if (XSW4_水切りシャッター閉A and not(pnlPBXSW4_水切りシャッター閉A)) or passXSW4_水切りシャッター閉A then
					mSV4_水切りシャッター開A=ON
					mSV5_水切りシャッター閉A=OFF

					StageDevice0=ORA(StageDevice0,$200)			
					StageDevice1=ORA(StageDevice1,$200)			
					
				else if (XSW3_水切りシャッター開A and not(pnlPBXSW3_水切りシャッター開A)) or passXSW3_水切りシャッター開A then
					mSV4_水切りシャッター開A=OFF
					mSV5_水切りシャッター閉A=ON
				end if
			end if						
			
'			if mSV4_水切りシャッター開A and XSW3_水切りシャッター開A then
'				mSV4_水切りシャッター開A=OFF
'			end if
'			if mSV5_水切りシャッター閉A and XSW4_水切りシャッター閉A then
'				mSV5_水切りシャッター閉A=OFF
'			end if		
		end if
	
	end if '浸漬タンクAユニットAutoMode and not(浸漬タンクAユニットOrgErrStep)

	'===================================================================================================================
	'【 浸漬タンクAユニットOrgErr 】
	else
	

		if ResetFlg then
			res(tim_充填バルブ開A.B)
			res(tim_充填バルブ閉A.B)
			res(tim_not水切りシャッター開A.B)
			res(tim_not水切りシャッター閉A.B)
			res(tim_水切りシャッター開A.B)
			res(tim_水切りシャッター閉A.B)
			res(tim_排水バルブ開A.B)
			res(tim_排水バルブ閉A.B)
			浸漬タンクAユニットOrgErr=OFF

		end if		
		
	end if	
	
	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
	
		select case 浸漬タンクAユニットErrStep
		case 0
		case 1
			浸漬タンクAユニットErr=ON
			mSV2_充填バルブ開A=OFF

			if ResetFlg then
				almXSW1_充填バルブ開A=OFF
				almXSW2_充填バルブ閉A=OFF
				almXSW3_水切りシャッター開A=OFF
				almXSW4_水切りシャッター閉A=OFF
				almXSW76_排水バルブ開A=OFF
				almXSW77_排水バルブ閉A=OFF

				inc(浸漬タンクAユニットErrStep)
			end if
		case 2
			浸漬タンクAユニットErr=OFF

			mSV2_充填バルブ開A=OFF
			res(tim_充填バルブ開A.B)
			res(tim_充填バルブ閉A.B)
			res(tim_not水切りシャッター開A.B) 
			res(tim_not水切りシャッター閉A.B)
			res(tim_水切りシャッター開A.B) 
			res(tim_水切りシャッター閉A.B)
			res(tim_排水バルブ開A.B)
			res(tim_排水バルブ閉A.B)
			浸漬タンクAユニットErrStep=0
		end select

	end if 'if 浸漬タンクAユニットErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case 浸漬タンクAユニットEmgStep
	case 0
	
	case 1
		浸漬タンクAユニットAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (浸漬タンクAユニットAutoMode and 自動搬送AutoMode ) or  浸漬タンクAユニットstep<>0  or 浸漬Aワンサイクルflg then

			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseSV2_充填バルブ開A=ON
			'eject2SV3_充填バルブ閉A=ON
			pauseSV4_水切りシャッター開A=ON
			'eject2SV5_水切りシャッター閉A=ON
			pauseSV60_排水バルブ開A=ON
			'eject2SV61_排水バルブ閉A=ON
			pauseSV6_給水電磁弁A=ON

			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				tim_シャッター開閉_stack=tim_シャッター開閉.U
				tim_配米準備_stack=tim_配米準備.U
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mSV2_充填バルブ開A=OFF
			mSV4_水切りシャッター開A=OFF
			mSV5_水切りシャッター閉A=ON '-> Reset解除
			mSV60_排水バルブ開A=OFF
			mSV6_給水電磁弁A=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(浸漬タンクAユニットEmgStep)
	case 2
		if ResetFlg then
			inc(浸漬タンクAユニットEmgStep)
		end if
	case 3
		if (浸漬タンクAユニットAutoMode and 自動搬送AutoMode ) or  浸漬タンクAユニットstep<>0  or 浸漬Aワンサイクルflg then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseSV2_充填バルブ開A=OFF
				'eject2SV3_充填バルブ閉A=OFF
				pauseSV4_水切りシャッター開A=OFF
				'eject2SV5_水切りシャッター閉A=OFF
				pauseSV60_排水バルブ開A=OFF
				'eject2SV61_排水バルブ閉A=OFF
				pauseSV6_給水電磁弁A=OFF

				tim_procstep.U=tim_procstep_stack
				tim_シャッター開閉.U=tim_シャッター開閉_stack
				tim_配米準備.U=tim_配米準備_stack
				
				'---------------------------------
				inc(浸漬タンクAユニットEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			mSV5_水切りシャッター閉A=OFF
			'---------------------------------
			inc(浸漬タンクAユニットEmgStep)		
		end if				
	case 4
		timstack=OFF
		浸漬タンクAユニットEmgStep=0
		浸漬タンクAユニットEmg=OFF
	end select
		
end if 'if 浸漬タンクAユニットEmgStep=0 then
