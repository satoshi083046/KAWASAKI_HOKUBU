'計水ユニット
'===================================================================================================================
'
'<<<<<<<	ユニット	>>>>>>>>
' 麦飯 7.60 = 2.29 →  2.20 / 2.29 * 7.60 = 7.30
'===================================================================================================================
'
'	計水ユニット
'	
'PH52_釜検知 -> PH11__釜検知
'PH53_フタ検知 -> PH12__フタ検知
'
'===================================================================================================================
客先コード=川崎北部
'===================================================================================================================
select case 客先コード

case 川崎南部
'	ADRSET(PH52_釜検知.B,pPH_釜検知.D)
'	ADRSET(PH53_フタ検知.B,pPH_フタ検知.D)
'	ADRSET(注水排出要求.B,p注水排出要求.D)
	
case 川崎北部
	ADRSET(PH11_釜検知.B,pPH_釜検知.D)
	ADRSET(PH12_フタ検知.B,pPH_フタ検知.D)
	ADRSET(計水ユニット排出要求.B,p注水排出要求.D)

end select
'===================================================================================================================
'
'  ●  Modbsu通信で計測する上限下限をを設定する。
'
'	setADR4532c1_Up	=DM_計水目標上限x (x: 1,2,3)
'	setADR4532c1_Low=DM_計水目標下限x (x: 1,2,3)
'
'	*注意  ZERO機能（本体、前面スイッチ）  ZEROスイッチを押して値を0にすることができるが、再電源投入後、0ではなく値がもとに戻ります。

'配米済み釜への注水
	DM_計水目標上限1=DM_計水目標下限1+100	'水位満了
'	DM_計水目標下限1=1027					'水位満了 基準 (設定値）
	DM_計水目標上限2=DM_計水目標下限2+100	'水位中間
	DM_計水目標下限2=(DM_計水目標下限1-100)	'水位中間
	DM_計水目標上限3=10	'排水
	DM_計水目標下限3=-20




'排水


	'【計量水重量】

	if 自動搬送AutoMode then
		'自ステージの釜のITEMNO
		ThisItem=ANDA(StageDevice5,$FF)
		if 0<ThisItem and ThisItem<99 then
			ADRSET(EM1021.U,ptrアイテム計量水重量)
			ADRADD(20 * (ThisItem-1),ptrアイテム計量水重量)
		else
			ADRSET(R0,ptrアイテム計量水重量)		
		end if
		
	else 
		'マニュアル
		if 0<DM_ITEMNO and DM_ITEMNO<99 then
			ADRSET(EM1021.U,ptrアイテム計量水重量)
			ADRADD(20 * (DM_ITEMNO-1),ptrアイテム計量水重量)
		else
			ADRSET(R0,ptrアイテム計量水重量)					
		end if
	end if
	
	
	ADRSET(R0.U,ptrcheck)
	'アドレスが設定されているかをチェックする
	if ptrcheck<>ptrアイテム計量水重量 then
		'メインTP_切替ページＮｏ=160(一般設定では調整可能)
		if メインTP_切替ページＮｏ<>160 then 
			DM_計水目標下限1=*ptrアイテム計量水重量
		end if
	else
		DM_計水目標下限1=0
	end if
	
	tmDM_計水目標下限1補正値=0
	tmDM_計水目標上限1=tmDM_計水目標下限1+10
	tmDM_計水目標下限1=DM_計水目標下限1+tmDM_計水目標下限1補正値

'空釜への注水
if 1 then
	DM_空釜計水目標上限1=DM_空釜計水目標下限1+100	'水位満了
	DM_空釜計水目標下限1=DM_空釜計水目標下限1		'水位満了 基準 (設定値）
	DM_空釜計水目標上限2=DM_空釜計水目標下限2+100	'水位中間
	DM_空釜計水目標下限2=DM_空釜計水目標下限1-100 	'水位中間

	if DM_空釜計水目標下限1<400 or DM_空釜計水目標下限1>650 then
		if DM_空釜計水目標下限1<400 then
			DM_空釜計水目標下限1=400
		else if DM_空釜計水目標下限1>650 then
			DM_空釜計水目標下限1=650
		end if
	end if
end if


'インジケータ表示値
'
	DM_計水量現在値=getADR4532c1_Raw


	if DM_計水目標下限1>0 then
		if  DM_計水量現在値<10 then
			加水量グラフ=0
		else if DM_計水量現在値>(DM_計水目標下限1-20) then
			加水量グラフ=100
		else 	
			加水量グラフ=(DM_計水量現在値*100) / DM_計水目標下限1
		end if	
	else
		'麦飯の水量 650 で計算
		if  DM_計水量現在値<10 then
			加水量グラフ=0
		else if DM_計水量現在値>(650-20) then
			加水量グラフ=100
		else 	
			加水量グラフ=(DM_計水量現在値*100) / 650
		end if	
	end if	
	
'
'給水  排水バルブ
'
'給水バルブ
'	SV17_計水タンク給水（大）
'	SV18_計水タンク給水（小）
'排水バルブ
'	mSV19_計水電磁弁_A 開き
'	mSV64_計水電磁弁_B 閉じ - 2017/7/5 削除
'

'------------------------------------------------------------------------------------------------------------------
'AD4532 ZERO RESET 1.0S ワンショット

tmr(AD4532_ZERO,tim_AD4532_ZERO,10)
if AD4532_ZERO and not(tim_AD4532_ZERO.B) then
	AD4532_ZERO=ON
else
	AD4532_ZERO=OFF
end if

if not(SV17_計水タンク給水（大）) and not(SV18_計水タンク給水（小）) and not(SV19_計水電磁弁_A) then
	if ldp(pnlPBAD4532_ZERO) then
			AD4532_ZERO=ON
			res(tim_AD4532_ZERO)
	end if
end if

'===================================================================================================================
'

'【 初期化処理 】
if CR2008 then
    計水ユニットAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    計水ユニットAutoRun=OFF
    計水ユニット許可=ON
    計水ユニットOrgErr=OFF
    計水ユニットErr=OFF
    計水ユニットEmg=OFF
    計水ユニットstep=0
    計水ユニットErrStep=0
    計水ユニットOrgErrStep=0
    計水ユニットEmgStep=0

	計水ワンサイクルflg=OFF
	計水準備step=0
	
	TestPass=0

end if
'===================================================================================================================
'【 原点 】
計水ユニットOrg=not(計水ユニット許可) or 1

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	計水ユニットEmg=ON
	計水ユニットEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】

tmr(SV18_計水タンク給水（小） ,tim_計水タンク給水（小）,#1000)
tmr(SV17_計水タンク給水（大）,tim_計水タンク給水（大）,#1000)
tmr(SV19_計水電磁弁_A,tim_計水電磁弁_A,#1000)

if ldp(tim_計水タンク給水（小）.B) then
	errpassSV18_計水タンク給水（小）=ON
	almSV18_計水タンク給水（小）=ON
	計水ユニットErrStep=1

else if ldp(tim_計水タンク給水（大）.B) then
	errpassSV17_計水タンク給水（大）=ON
	almSV17_計水タンク給水（大）=ON
	計水ユニットErrStep=1

else if ldp(tim_計水電磁弁_A.B) then
	errpassSV17_計水タンク給水（大）=ON
	errpassSV18_計水タンク給水（小）=ON

	almSV19_計水電磁弁_A=ON
	計水ユニットErrStep=1
end if
'===================================================================================================================
' PLインジケータ
	if not(自動搬送AutoMode) or not(計水ユニットAutoMode) then
		PBL32_計水= 計水ワンサイクルflg
	else
		PBL32_計水=OFF
	end if

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 計水ユニットAutoMode	自動モード セレクトスイッチ
'System :: 計水ユニットAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能
'System :: 計水ユニットEmg	その場停止

tmr(tim_TestPass,tim_TestPass_val) 

if 計水ユニットEmgStep=0 then  
	
	if 計水ユニットErrStep=0  then
	
	if not(計水ユニットOrgErr) then


		'-----------------------------------------------------------------------------
		' 計量
		tmr(tim_計水準備,tim_計水準備_val)
		select case 計水準備step
		case 0
		case 1
			注水準備完了=OFF
			mSV19_計水電磁弁_A=OFF '開き
			'mSV64_計水電磁弁_B=ON '閉じ
			tim_計水準備_val=#10
			res(tim_計水準備)
			inc(計水準備step)
		
		case 2
			if tim_計水準備.B then
				inc(計水準備step)
			end if

		case 3
			setADR4532c1_Low=DM_空釜計水目標下限2
			setADR4532c1_Up=DM_空釜計水目標上限2

			inc(計水準備step)

		case 4
			if setADR4532c1_Low=getADR4532c1_Low and setADR4532c1_Up=getADR4532c1_Up then 
				inc(計水準備step)
			end if

		case 5
			tim_計水準備_val=#10 '通信待ち時間
			res(tim_計水準備)
			inc(計水準備step)

		case 6
			if  tim_計水準備.B then
				inc(計水準備step)
			end if
		
		case 7
			mSV17_計水タンク給水（大）=ON
			mSV18_計水タンク給水（小）=ON
			errpassSV18_計水タンク給水（小）=OFF 
			errpassSV17_計水タンク給水（大）=OFF

			tim_TestPass_val=120
			res(tim_TestPass)

			inc(計水準備step)
		
		case 8

			inc(計水準備step)
		
		case 9
			if (TestPass and tim_TestPass.B) or errpassSV18_計水タンク給水（小） or errpassSV17_計水タンク給水（大） or AD4532_OK or AD4532_HI or DM_計水量現在値>setADR4532c1_Low then
				mSV17_計水タンク給水（大）=OFF
				mSV18_計水タンク給水（小）=OFF
				inc(計水準備step)
			end if

		case 10
			setADR4532c1_Low=DM_空釜計水目標下限1
			setADR4532c1_Up=DM_空釜計水目標上限1

			inc(計水準備step)

		case 11
			if setADR4532c1_Low=getADR4532c1_Low and setADR4532c1_Up=getADR4532c1_Up then 
				inc(計水準備step)
			end if

		case 12
			tim_計水準備_val=#3 '通信待ち時間
			res(tim_計水準備)
			inc(計水準備step)

		case 13
			if  tim_計水準備.B then
				inc(計水準備step)
			end if

		case 14
			mSV17_計水タンク給水（大）=OFF
			mSV18_計水タンク給水（小）=ON
			errpassSV18_計水タンク給水（小）=OFF 
			errpassSV17_計水タンク給水（大）=OFF

			tim_TestPass_val=80
			res(tim_TestPass)
			inc(計水準備step)
		
		case 15
			inc(計水準備step)
		
		case 16
			if (TestPass and tim_TestPass.B) or errpassSV18_計水タンク給水（小） or errpassSV17_計水タンク給水（大） or AD4532_OK or AD4532_HI or DM_計水量現在値>setADR4532c1_Low then
				mSV17_計水タンク給水（大）=OFF
				mSV18_計水タンク給水（小）=OFF
				inc(計水準備step)
			end if


		case 17
			tim_計水準備_val=#10 'Wait
			res(tim_計水準備)
			inc(計水準備step)
		
		case 18
			if tim_計水準備.B then
				inc(計水準備step)
			end if

		case 19
			注水準備完了=ON
			計水準備step=0

		end select

		'-----------------------------------------------------------------------------
		' 炊飯釜の計水
		tmr(tim_計水追加,tim_計水追加_val)
		select case 計水追加step
		case 0

		case 1
			if DM_計水量現在値>=DM_計水目標下限1 then
				計水追加step=0
			else
				inc(計水追加step)
			end if

		
		case 2		
			setADR4532c1_Low=tmDM_計水目標下限1
			setADR4532c1_Up=tmDM_計水目標上限1
			inc(計水追加step)

		case 3
			if setADR4532c1_Low=getADR4532c1_Low and setADR4532c1_Up=getADR4532c1_Up then 
				inc(計水追加step)
			end if

		case 4
			tim_計水追加_val=#1 '通信待ち時間
			res(tim_計水追加)
			inc(計水追加step)
		
		case 5
			if tim_計水追加.B then
				tim_TestPass_val=60
				res(tim_TestPass)
				inc(計水追加step)
			end if
		
		case 6
			mSV17_計水タンク給水（大）=OFF
			mSV18_計水タンク給水（小）=ON
			errpassSV18_計水タンク給水（小）=OFF 
			errpassSV17_計水タンク給水（大）=OFF
			inc(計水追加step)

		case 7
			if (TestPass and tim_TestPass.B) or errpassSV18_計水タンク給水（小） or errpassSV17_計水タンク給水（大） or AD4532_OK or AD4532_HI or DM_計水量現在値>setADR4532c1_Low then
				mSV17_計水タンク給水（大）=OFF
				mSV18_計水タンク給水（小）=OFF
				inc(計水追加step)
			end if


		case 8
			tim_計水追加_val=#10 'Wait
			res(tim_計水追加)
			inc(計水追加step)
		
		case 9
			if tim_計水追加.B then
				inc(計水追加step)
			end if
			
		case 10
			加水釜数=加水釜数+1
			計水追加step=0

		end select


	
	'===================================================================================================================
	'【 プロセス処理（配米） 】
	'
	if (計水ユニットAutoMode and 自動搬送AutoMode) or 計水ワンサイクルflg or 計水ユニットstep<>0 then
	
		if not(計水ユニットAutoMode and 自動搬送AutoMode) then
			計水ユニットAutoRun=OFF
		end if

		tmr(tim_procstep,tim_procstep_val)

		select case 計水ユニットstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' 作業工程を振り分ける
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 計水ユニットAutoRun then
				inc(計水ユニットstep)
			else 
				計水ユニットstep=0 '終了待機
			end if
		
		case 2
		' [ 工程準備完了 ]
		 if 計水ユニット許可 then

			if 注水準備完了 then
				inc(計水ユニットstep)
			else
			 	if ANDA(ORA(ORA(ORA(StageDevice0,StageDevice1),StageDevice2),StageDevice3),$FF)>0 and ANDA(ORA(ORA(ORA(StageDevice0,StageDevice1),StageDevice2),StageDevice3),$FF)<99 then
					if 計水準備step=0 then
						計水準備step=1
					end if
					inc(計水ユニットstep)
				else
					*p注水排出要求.B=ON
					計水ユニットstep=1				
				end if
			
			end if
		
		else
			if 注水準備完了 then
				inc(計水ユニットstep)
			else
				*p注水排出要求.B=ON
				計水ユニットstep=1
			end if
		end if
		
		case 3
		' [ 蓋カマ移動停止確認 ]
			if *p注水排出要求.B=OFF and  搬送コンベアA動作中=OFF then

				'[ 自ステージに"釜"有検出 ]
					if *pPH_釜検知.B and *pPH_フタ検知.B then
							計水ユニットstep=100 'プロセス処理
						
				'[ 自ステージに"フタ"有検出 ]	
					else if not(*pPH_釜検知.B) and *pPH_フタ検知.B then 
							*p注水排出要求.B=ON
							計水ユニットstep=1
				
				'[ 自ステージに"釜フタ"なし ]
						else
							*p注水排出要求.B=ON
							計水ユニットstep=1
					end if
			
			else
			
				計水ユニットstep=1
			
			end if
		
		case 4
			計水ユニットstep=100 'プロセス処理
		'--------------------------------------------------------------------------------------------------------------
		'プロセス処理
		case 100
			if 注水完了 then '搬送移動でOFF
				計水ユニットstep=199
				
			else if 注水準備完了  then

				if ANDA(StageDevice5,$200)=$200 or ANDA(StageDevice5,$400)=$400 or 計水ワンサイクルflg then '配米A or 配米B
				 	炊飯釜計水許可=ON
					inc(計水ユニットstep)
				else
				 	炊飯釜計水許可=OFF
					*p注水排出要求.B=ON
				 	計水ユニットstep=1

				end if

			end if

		'-----------------------------------------------------------------------------
		case 101
			注水準備完了=OFF
			inc(計水ユニットstep)
		
		'-----------------------------------------------------------------------------
		' 炊飯釜への水量追加
		case 102
			if 炊飯釜計水許可 then
				if 計水追加step=0 then
					計水追加step=1
					inc(計水ユニットstep)
				end if
			else
				inc(計水ユニットstep)
			end if
		
		case 103
			if 計水追加step=0 then
				inc(計水ユニットstep)
			end if
		'-----------------------------------------------------------------------------
		' 加水 （釜への排水）
		case 104
			setADR4532c1_Low=DM_計水目標下限3
			setADR4532c1_Up=DM_計水目標上限3

			mSV19_計水電磁弁_A=ON '開き
			'mSV64_計水電磁弁_B=OFF '閉じ
			errpassSV18_計水タンク給水（小）=OFF 
			errpassSV17_計水タンク給水（大）=OFF

			inc(計水ユニットstep)

		case 105 
			if setADR4532c1_Low=getADR4532c1_Low and setADR4532c1_Up=getADR4532c1_Up then 
				inc(計水ユニットstep)
			end if
			
		case 106
			tim_procstep_val=#1 '通信待ち時間
			res(tim_procstep)
			inc(計水ユニットstep)
		
		case 107
			if tim_procstep.B then
				tim_TestPass_val=80
				res(tim_TestPass)			
				inc(計水ユニットstep)
			end if
		
		case 108
			if (TestPass and tim_TestPass.B) or errpassSV18_計水タンク給水（小） or errpassSV17_計水タンク給水（大） or AD4532_OK or AD4532_LO or DM_計水量現在値<setADR4532c1_Up then
				mSV19_計水電磁弁_A=OFF '開き
				'mSV64_計水電磁弁_B=ON '閉じ
				inc(計水ユニットstep)
			end if
						
		case 109
			tim_procstep_val=#20 '閉じ待ち時間
			res(tim_procstep)
			inc(計水ユニットstep)
		
		case 110
			if tim_procstep.B then
				計水ユニットstep=199
			end if
		

		'--------------------------------------------------------------------------------------------------------------
		case 199
			if 加水釜数現在値<加水釜数設定値 then
				inc(加水釜数現在値)
			end if

			計水ワンサイクルflg=OFF
			mSV19_計水電磁弁_A=OFF '開き
			'mSV64_計水電磁弁_B=ON '閉じ
			注水完了=ON
			*p注水排出要求.B=ON
			計水ユニットstep=1
		'--------------------------------------------------------------------------------------------------------------
		'ワンサイクル処理
		case 200
			if 注水準備完了  then
				inc(計水ユニットstep)
			else
				if 計水準備step=0 then
					計水準備step=1
				end if
				inc(計水ユニットstep)
			end if
		
		case 201
			if 注水準備完了  then
				計水ユニットstep=100
			end if
			
		end select


	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		計水ユニットAutoRun=OFF
		
		res(tim_計水タンク給水（小）.B) 
		res(tim_計水タンク給水（大）.B)
		res(tim_計水電磁弁_A.B)
		
		
		if not(計水ワンサイクルflg) then
		
				if ldp(PB32_計水) and 計水ユニットstep=0 then
					if *pPH_釜検知.B and *pPH_フタ検知.B then
						注水準備完了=OFF
						注水完了=OFF
						計水ワンサイクルflg=ON
						計水ユニットstep=200
					end if											
				end if
				
				
				if ldp(pnlPBSV17_計水タンク給水（大）) then
					if mSV17_計水タンク給水（大） then
						mSV17_計水タンク給水（大）=OFF
					else
						mSV17_計水タンク給水（大）=ON
					end if
				end if
				if ldp(pnlPBSV18_計水タンク給水（小）) then
					if mSV18_計水タンク給水（小） then
						mSV18_計水タンク給水（小）=OFF
					else
						mSV18_計水タンク給水（小）=ON
					end if
				end if
				if ldp(pnlPBSV19_計水電磁弁_A) then
					if mSV19_計水電磁弁_A then
						mSV19_計水電磁弁_A=OFF
						'mSV64_計水電磁弁_B=OFF
					else
						mSV19_計水電磁弁_A=ON
						'mSV64_計水電磁弁_B=OFF
					end if
				end if
		end if
	end if '計水ユニットAutoMode and not(計水ユニットOrgErrStep)
	'===================================================================================================================
	'【 OrgErr】
	else
	
		if ResetFlg then
			計水ユニットOrgErr=OFF
		end if
		
	end if
	
	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else

		計水ユニットErr=ON

		mSV17_計水タンク給水（大）=OFF
		mSV18_計水タンク給水（小）=OFF
		mSV19_計水電磁弁_A=OFF '開き
		'mSV64_計水電磁弁_B=ON '閉じ

		select case 計水ユニットErrStep
		case 0
		case 1
			if ResetFlg then
				almSV18_計水タンク給水（小）=OFF
				almSV17_計水タンク給水（大）=OFF
				almSV19_計水電磁弁_A=OFF
			
				inc(計水ユニットErrStep)
			end if
		case 2
			res(tim_計水タンク給水（小）.B) 
			res(tim_計水タンク給水（大）.B)
			res(tim_計水電磁弁_A.B)
			計水ユニットErrStep=0
			計水ユニットErr=OFF
		end select

	end if 'if 計水ユニットErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case 計水ユニットEmgStep
	case 0
	
	case 1
		計水ユニットAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (計水ユニットAutoMode and 自動搬送AutoMode) or 計水ワンサイクルflg or 計水ユニットstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			計水ワンサイクルflg=OFF

			計水ユニットstep=0 '終了待機
			計水準備step=0
			計水追加step=0
			注水準備完了=OFF

			mSV17_計水タンク給水（大）=OFF
			mSV18_計水タンク給水（小）=OFF
			mSV19_計水電磁弁_A=OFF
			mSV64_計水電磁弁_B=OFF
		
			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				tim_TestPass_stack=tim_TestPass.U
				tim_計水追加_stack=tim_計水追加.U
				tim_計水準備_stack=tim_計水準備.U
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mSV17_計水タンク給水（大）=OFF
			mSV18_計水タンク給水（小）=OFF
			mSV19_計水電磁弁_A=OFF
			mSV64_計水電磁弁_B=OFF		

			tim_procstep_stack=tim_procstep.U
			tim_TestPass_stack=tim_TestPass.U
			tim_計水追加_stack=tim_計水追加.U
			tim_計水準備_stack=tim_計水準備.U

			'---------------------------------
		end if
		
		'---------------------------------
		inc(計水ユニットEmgStep)
	case 2
		if ResetFlg then
			inc(計水ユニットEmgStep)
		end if
	case 3
		if (計水ユニットAutoMode and 自動搬送AutoMode) or 計水ワンサイクルflg or 計水ユニットstep<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				tim_procstep.U=tim_procstep_stack
				tim_TestPass.U=tim_TestPass_stack
				tim_計水追加.U=tim_計水追加_stack
				tim_計水準備.U=tim_計水準備_stack

				'---------------------------------
				inc(計水ユニットEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			tim_procstep.U=tim_procstep_stack
			tim_TestPass.U=tim_TestPass_stack
			tim_計水追加.U=tim_計水追加_stack
			tim_計水準備.U=tim_計水準備_stack
			
			'---------------------------------
			inc(計水ユニットEmgStep)		
		end if				
	case 4
		timstack=OFF
		計水ユニットEmgStep=0
		計水ユニットEmg=OFF
	end select

end if 'if 計水ユニットEmgStep=0 then
