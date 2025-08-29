'ならしユニット
'===================================================================================================================
'
'<<<<<<<	ユニット	>>>>>>>>
'
'===================================================================================================================
'
'	ならしユニット
'===================================================================================================================

'【 初期化処理 】

if CR2008 then
    ならしユニットAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    ならしユニットAutoRun=OFF
    ならしユニット許可=ON
    ならしユニットOrgErr=OFF
    ならしユニットErr=OFF
    ならしユニットEmg=OFF
    ならしユニットstep=0
    ならしユニットErrStep=0
    ならしユニットOrgErrStep=0
    ならしユニットEmgStep=0
	
	SV23_ならし前進step=0
	SV24_ならし後退step=0

end if

'===================================================================================================================
'【 原点 】
ならしユニットOrg= not(ならしユニット許可) or (XSW25_ならし上昇端 and (XSW24_ならし前進端 or XSW23_ならし後退端))

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	ならしユニットEmg=ON
	ならしユニットEmgStep=1
end if

'------------------------------------------------------
'しずく受けに移動
tmr(tim_SV23_ならし前進,tim_SV23_ならし前進_val)
select case SV23_ならし前進step 'しずく受けに移動
case 0

case 1
	if XSW25_ならし上昇端 then
		inc(SV23_ならし前進step)	
	end if

case 2
	if not(XSW24_ならし前進端) then
		mSV23_ならし前進=ON
		mSV24_ならし後退=OFF
		errpassXSW24_ならし前進端=OFF
	end if
	
	inc(SV23_ならし前進step)
case 3
	if errpassXSW24_ならし前進端 or XSW24_ならし前進端 then
		inc(SV23_ならし前進step)
	end if
case 4
	mSV23_ならし前進=OFF
	mSV24_ならし後退=OFF
	SV23_ならし前進step=0
end select
'------------------------------------------------------
'しずく受けから離脱
tmr(tim_SV24_ならし後退,tim_SV24_ならし後退_val)
select case SV24_ならし後退step 'しずく受けから離脱
case 0

case 1
	if XSW25_ならし上昇端 then
		inc(SV24_ならし後退step)
	end if

case 2
	if not(XSW23_ならし後退端) then
		mSV23_ならし前進=OFF
		mSV24_ならし後退=ON
		errpassXSW23_ならし後退端=OFF
	end if
	inc(SV24_ならし後退step)
case 3
	if errpassXSW23_ならし後退端 or XSW23_ならし後退端 then
		inc(SV24_ならし後退step)	
	end if
case 4
	mSV23_ならし前進=OFF
	mSV24_ならし後退=OFF
	SV24_ならし後退step=0
end select
'------------------------------------------------------


'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】

tmr(XSW44_ならし原点センサ,tim_dly_XSW44_ならし原点センサ,0)
tmr(not(XSW44_ならし原点センサ),tim_notdly_XSW44_ならし原点センサ,10)

tmr(MC40_ならしモータ and not(pnlPBMC40_ならしモータ),tim_MC40_ならしモータ,40*DM_ならし回数設定値)
tmr(SV23_ならし前進 and not(XSW24_ならし前進端) and not(pnlPBXSW24_ならし前進端),tim_XSW24_ならし前進端,#60)
'しずく受けに移動
tmr(SV24_ならし後退 and not(XSW23_ならし後退端) and not(pnlPBXSW23_ならし後退端),tim_XSW23_ならし後退端,#60)
tmr(SV25_ならし下降 and not(XSW26_ならし下降端) and not(pnlPBXSW26_ならし下降端),tim_XSW26_ならし下降端,#80)
tmr(SV26_ならし上昇 and not(XSW25_ならし上昇端) and not(pnlPBXSW25_ならし上昇端), tim_XSW25_ならし上昇端,#80)

if ldp(tim_MC40_ならしモータ.B) then
	errpassMC40_ならしモータ=ON
	mMC40_ならしモータ=OFF
	almMC40_ならしモータ=ON
	ならしユニットErrStep=1

else if ldp(tim_XSW24_ならし前進端.B) then
	errpassXSW24_ならし前進端=ON
	almXSW24_ならし前進端=ON
	ならしユニットErrStep=1

else if ldp(tim_XSW23_ならし後退端.B) then	
	errpassXSW23_ならし後退端=ON
	almXSW23_ならし後退端=ON
	ならしユニットErrStep=1

else if ldp(tim_XSW26_ならし下降端.B) then
	errpassXSW26_ならし下降端=ON
	almXSW26_ならし下降端=ON
	ならしユニットErrStep=1

else if ldp(tim_XSW25_ならし上昇端.B) then
	errpassXSW25_ならし上昇端=ON
	almXSW25_ならし上昇端=ON
	ならしユニットErrStep=1

end if

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: ならしユニットAutoMode	自動モード セレクトスイッチ
'System :: ならしユニットAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能
'System :: ならしユニットEmg	その場停止


if ならしユニットEmgStep=0 then  
	
	if ならしユニットErrStep=0  then

	if not(ならしユニットOrgErr) then

	if (ならしユニットAutoMode and 自動搬送AutoMode ) or ならしユニットstep<>0 then
		
		if not(ならしユニットAutoMode and 自動搬送AutoMode ) then
			ならしユニットAutoRUn=OFF
		end if

	'===================================================================================================================
	'【 プロセス処理 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case ならしユニットstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
				ならしユニットStatusMsg=#0
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' 作業工程を振り分ける
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if ならしユニットAutoRun then
				inc(ならしユニットstep)
			else 
				SV23_ならし前進step=1 'しずく受けに移動
				ならしユニットstep=0 '終了待機 
			end if
		
		case 2
		' [ 蓋カマ移動停止確認 ]
			if ならしユニット排出要求=OFF and  搬送コンベアC動作中=OFF then

				'[ 自ステージに"釜"有検出 ]
					if PH17_釜検知 and PH18_フタ検知 then
						if ANDA(StageDevice8,$200)=$200 or ANDA(StageDevice8,$400)=$400 or 1 then 
							inc(ならしユニットstep) 'プロセス処理
						else
							ならしユニット排出要求=ON
							ならしユニットstep=1						
						end if
				'[ 自ステージに"フタ"有検出 ]	
					else if not(PH17_釜検知) and PH18_フタ検知 then 
							ならしユニット排出要求=ON
							ならしユニットstep=1
				
				'[ 自ステージに"釜フタ"なし ]
						else
							ならしユニット排出要求=ON
							ならしユニットstep=1  '終了
					end if
			
			else
			
				ならしユニットstep=1
			
			end if
		
		case 3
		' [ ユニット許可検出 ]
			if ならしユニット許可 then
				inc(ならしユニットstep)
			else
				ならしユニット排出要求=ON
				ならしユニットstep=1
			end if
	
		case 4
			if XSW25_ならし上昇端 and (XSW24_ならし前進端 or XSW23_ならし後退端) then '原点
				ならしユニットstep=100 'プロセス処理
			else
				ならしユニットstep=1
			end if

		
		'--------------------------------------------------------------------------------------------------------------
		'プロセス処理
		case 100		
			if ならし完了 then '搬送移動でOFF
				ならしユニットstep=199
			else
				inc(ならしユニットstep)
			end if
				
		case 101
			ならしユニットStatusMsg=#31	'	ならし中
			
			DM_ならし回数現在値=0
			mSV23_ならし前進=OFF
			mSV24_ならし後退=ON	'しずく受けから離脱
			errpassXSW24_ならし前進端=OFF
			inc(ならしユニットstep)
			
		case 102
			if errpassXSW23_ならし後退端 or XSW23_ならし後退端 then
				inc(ならしユニットstep)
			end if
		
		case 103
			mSV24_ならし後退=OFF
			tim_procstep_val=#0
			res(tim_procstep)
			inc(ならしユニットstep)

		case 104
			if tim_procstep.B then
				inc(ならしユニットstep)
			end if
				
		case 105
			mSV25_ならし下降=ON
			errpassXSW26_ならし下降端=OFF
			inc(ならしユニットstep)

		case 106
			if errpassXSW26_ならし下降端 or XSW26_ならし下降端 then
				inc(ならしユニットstep)
			end if
		
		case 107
			mSV25_ならし下降=OFF				
			tim_procstep_val=#0
			res(tim_procstep)
			inc(ならしユニットstep)
			
		case 108
			if tim_procstep.B then		
				errpassMC40_ならしモータ=OFF
				ならしユニットstep=110
			end if
		
		'----------------------------------------------------
		case 110 'ならしループ  <-
			if DM_ならし回数現在値 < DM_ならし回数設定値 and not(errpassMC40_ならしモータ) then
				inc(ならしユニットstep)
			else 
				mMC40_ならしモータ=OFF
				ならしユニットstep=150
			end if
		
		case 111
			mMC40_ならしモータ=ON
			inc(ならしユニットstep)
		
		case 112
			tim_procstep_val=10
			res(tim_procstep)
			inc(ならしユニットstep)

		case 113
			if tim_procstep.B then
				inc(ならしユニットstep)
			end if			
				
		case 114
			if errpassMC40_ならしモータ then
				inc(ならしユニットstep)			
			else if not(XSW44_ならし原点センサ) and tim_notdly_XSW44_ならし原点センサ.B then
				inc(ならしユニットstep)
			end if
		
		case 115
			if errpassMC40_ならしモータ then
				inc(ならしユニットstep)			
			else if XSW44_ならし原点センサ and tim_dly_XSW44_ならし原点センサ.B then
				inc(DM_ならし回数現在値)
				if DM_ならし回数現在値 >= DM_ならし回数設定値 then
					mMC40_ならしモータ=OFF
				end if
				inc(ならしユニットstep)
			end if
		
		case 116
			ならしユニットstep=110 'ならしループ ->
		'----------------------------------------------------			
		case 150
			mSV26_ならし上昇=ON
			errpassXSW25_ならし上昇端=OFF
			inc(ならしユニットstep)
			
		case 151
			if errpassXSW25_ならし上昇端 or XSW25_ならし上昇端 then
				inc(ならしユニットstep)
			end if
		
		case 152
			mSV26_ならし上昇=OFF
			tim_procstep_val=#0
			res(tim_procstep)
			inc(ならしユニットstep)
			
			ならし完了=ON
			ならしユニット排出要求=ON

		
		case 153
			if tim_procstep.B then
				inc(ならしユニットstep)
			end if
		
		case 154
			mSV23_ならし前進=ON	'しずく受けに移動
			mSV24_ならし後退=OFF
			errpassXSW24_ならし前進端=OFF
			inc(ならしユニットstep)
			
		case 155
			if errpassXSW24_ならし前進端 or XSW24_ならし前進端 then
				inc(ならしユニットstep)
			end if

		case 156
			mSV23_ならし前進=OFF
			tim_procstep_val=#0
			res(tim_procstep)
			ならしユニットstep=199

		case 199
			ならしユニット排出要求=ON
			ならしユニットstep=1

		end select

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		ならしユニットAutoRun=OFF
		
		ならしユニットstep=0 '終了
		ならし完了=OFF

		res(tim_MC40_ならしモータ)
		res(tim_XSW24_ならし前進端)
		res(tim_XSW23_ならし後退端)
		res(tim_XSW26_ならし下降端)
		res(tim_XSW25_ならし上昇端)

		
		'---------------------------------------------------------
		if ldp(pnlPBSV23_ならし前進 or pnlPBSV24_ならし後退) then
			if XSW23_ならし後退端 and XSW25_ならし上昇端 then
				mSV23_ならし前進=ON
				mSV24_ならし後退=OFF		
			else if XSW24_ならし前進端 and XSW25_ならし上昇端 then
				mSV23_ならし前進=OFF
				mSV24_ならし後退=ON
			else
				mSV23_ならし前進=OFF
				mSV24_ならし後退=ON			
			end if
		end if
		if mSV23_ならし前進 and XSW24_ならし前進端 then
			mSV23_ならし前進=OFF
		end if 
		if mSV24_ならし後退 and XSW23_ならし後退端 then 
			mSV24_ならし後退=OFF
		end if
		'---------------------------------------------------------
		if ldp(pnlPBSV25_ならし下降 or pnlPBSV26_ならし上昇) then
			if XSW25_ならし上昇端 and XSW23_ならし後退端 then
				mSV25_ならし下降=ON
				mSV26_ならし上昇=OFF
			else if XSW26_ならし下降端 and XSW23_ならし後退端 then
				mSV25_ならし下降=OFF
				mSV26_ならし上昇=ON
			else
				mSV25_ならし下降=OFF
				mSV26_ならし上昇=ON			
			end if
		end if
		if mSV25_ならし下降 and XSW26_ならし下降端 then
			mSV25_ならし下降=OFF
		end if
		if mSV26_ならし上昇 and XSW25_ならし上昇端 then
			mSV26_ならし上昇=OFF
		end if
		'---------------------------------------------------------
		if ldp(pnlPBMC40_ならしモータ) and not(MC40_ならしモータEndWait) then
			if mMC40_ならしモータ then
				MC40_ならしモータEndWait=ON
			else
				mMC40_ならしモータ=ON
				MC40_ならしモータEndWait=OFF
			end if
		end if
		
		if MC40_ならしモータEndWait and XSW44_ならし原点センサ then
			mMC40_ならしモータ=OFF
			MC40_ならしモータEndWait=OFF
		end if
		'---------------------------------------------------------
			
			
		
	end if 'ならしユニットAutoMode and not(ならしユニットOrgErrStep)

	'===================================================================================================================
	'【 ならしユニットOrgErr処理 】
	else
	
		res(tim_MC40_ならしモータ)
		res(tim_XSW24_ならし前進端)
		res(tim_XSW23_ならし後退端)
		res(tim_XSW26_ならし下降端)
		res(tim_XSW25_ならし上昇端)
		
		if ResetFlg then
			ならしユニットOrgErr=OFF
		end if
	
	end if
	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
		
		ならしユニットErr=ON
		
		select case ならしユニットErrStep
		case 0
		case 1
			if ResetFlg then
				almMC40_ならしモータ=OFF
				almXSW24_ならし前進端=OFF
				almXSW23_ならし後退端=OFF
				almXSW26_ならし下降端=OFF
				almXSW25_ならし上昇端=OFF
			
				inc(ならしユニットErrStep)
			end if
		case 2
			ならしユニットErr=OFF
			res(tim_MC40_ならしモータ)
			res(tim_XSW24_ならし前進端)
			res(tim_XSW23_ならし後退端)
			res(tim_XSW26_ならし下降端)
			res(tim_XSW25_ならし上昇端)
			ならしユニットErrStep=0
		end select

	end if 'if ならしユニットErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case ならしユニットEmgStep
	case 0
	
	case 1
		ならしユニットAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (ならしユニットAutoMode and 自動搬送AutoMode ) or ならしユニットstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseMC40_ならしモータ=ON
			
			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC40_ならしモータ=OFF
			mSV23_ならし前進=OFF
			mSV24_ならし後退=OFF
			mSV25_ならし下降=OFF
			mSV26_ならし上昇=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(ならしユニットEmgStep)
	case 2
		if ResetFlg then
			inc(ならしユニットEmgStep)
		end if
	case 3
		if (ならしユニットAutoMode and 自動搬送AutoMode ) or ならしユニットstep<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseMC40_ならしモータ=OFF
				tim_procstep.U=tim_procstep_stack
				'---------------------------------
				inc(ならしユニットEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(ならしユニットEmgStep)		
		end if				
	case 4
		timstack=OFF
		ならしユニットEmgStep=0
		ならしユニットEmg=OFF
	end select
		
end if 'if ならしユニットEmgStep=0 then
