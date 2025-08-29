'釜反転出口
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	釜反転出口
'
' PH7_釜検知	-> PH63_釜検知
' PH8_フタ検知	-> PH64_フタ検知
' PH9_釜検知	-> PH65_釜検知
' PH10_フタ検知	-> PH66_フタ検知
' MC10_反転モータ正転	-> MC37_反転モータ正転
' MC10_反転モータ逆転	-> MC37_反転モータ逆転
' (LS5_空釜反転原点位置) -> (LS5_空釜反転原点位置)
' (LS6_空釜反転反転位置) -> (LS6_空釜反転反転位置)
' MC32_搬送モータ	-> MC38_搬送モータ
'
' 
'===================================================================================================================

'【 初期化処理 】
if CR2008 then '電源ON時初期化処理
    釜反転出口AutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    釜反転出口AutoRun=OFF
    釜反転出口許可=ON
    釜反転出口OrgErr=OFF
    釜反転出口Err=OFF
    釜反転出口Emg=OFF
    釜反転出口step=0
    釜反転出口ErrStep=0
    釜反転出口OrgErrStep=0
    釜反転出口EmgStep=0
	
	MC37_反転モータ正転step=0
	MC37_反転モータ逆転step=0
	
end if
'===================================================================================================================
'【 原点 】
釜反転出口Org=LS5_空釜反転原点位置

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	釜反転出口Emg=ON
	釜反転出口EmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】

tmr(MC37_反転モータ正転 and not(LS6_空釜反転反転位置) and not(pnlPBLS6_空釜反転反転位置),tim_LS6_空釜反転反転位置,#50)
tmr(MC37_反転モータ逆転 and not(LS5_空釜反転原点位置) and not(pnlPBLS5_空釜反転原点位置),tim_LS5_空釜反転原点位置,#50)

if LS5_空釜反転原点位置 and LS6_空釜反転反転位置 then
	mMC37_反転モータ正転=OFF
	mMC37_反転モータ逆転=OFF
	almLS6_空釜反転反転位置=ON
	almLS5_空釜反転原点位置=ON
	釜反転出口ErrStep=1

else if ldp(tim_LS6_空釜反転反転位置.B) then
	mMC37_反転モータ正転=OFF
	errpassLS6_空釜反転反転位置=ON	
	almLS6_空釜反転反転位置=ON
	
	釜反転出口ErrStep=1
else if ldp(tim_LS5_空釜反転原点位置.B) then
	mMC37_反転モータ逆転=OFF
	errpassLS5_空釜反転原点位置=ON
	almLS5_空釜反転原点位置=ON
	釜反転出口ErrStep=1
end if

tmr(PH63_釜検知,timdly_PH63_釜検知,5)
tmr(PH64_フタ検知,timdly_PH64_フタ検知,5)

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 釜反転出口AutoMode	自動モード セレクトスイッチ
'System :: 釜反転出口AutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 釜反転出口Emg	その場停止


if not(釜反転出口Emg) then  
	
	if 釜反転出口ErrStep=0  then

	if not(釜反転出口OrgErr) then

	'------------------------------------------------------------------------------------------------
	'MC37_反転モータ正転  （昇降装置->洗浄機側）
	tmr(tim_MC37_反転モータ正転,tim_MC37_反転モータ正転_val)
	
	select case MC37_反転モータ正転step
	
	case 0
	
	case 1
		mMC37_反転モータ正転=ON
		errpassLS6_空釜反転反転位置=OFF
		inc(MC37_反転モータ正転step)

	case 2
		if LS6_空釜反転反転位置 or errpassLS6_空釜反転反転位置 then
			inc(MC37_反転モータ正転step)
		end if
		
	case 3
		mMC37_反転モータ正転=OFF
		inc(MC37_反転モータ正転step)

	case 4		
		MC37_反転モータ正転step=0

	end select
	'------------------------------------------------------------------------------------------------
	'MC37_反転モータ逆転 (洗浄機側 -> 昇降機側）
	tmr(tim_MC37_反転モータ逆転,tim_MC37_反転モータ逆転_val)
	
	select case MC37_反転モータ逆転step
	
	case 0
	
	case 1
		mMC37_反転モータ逆転=ON
		errpassLS5_空釜反転原点位置=OFF
		inc(MC37_反転モータ逆転step)

	case 2
		if LS5_空釜反転原点位置 or errpassLS5_空釜反転原点位置 then
			inc(MC37_反転モータ逆転step)
		end if
	
	case 3
		mMC37_反転モータ逆転=OFF
		inc(MC37_反転モータ逆転step)
		
	case 4
		MC37_反転モータ逆転step=0

	end select

	'------------------------------------------------------------------------------------------------
	if (釜反転出口AutoMode and 自動搬送AutoMode ) or 釜反転出口step<>0 then
	
		if not(釜反転出口AutoMode and 自動搬送AutoMode ) then
			釜反転出口AutoRun=OFF
		end if


	'===================================================================================================================
	'【 リフタータスク 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case 釜反転出口step
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 釜反転出口AutoRun then
				inc(釜反転出口step)
			else 
				釜反転出口step=0 '終了待機
			end if
	
		case 2				
			if 釜反転出口Org then
				inc(釜反転出口step)
			else
				釜反転出口step=1
			end if

		case 3
			if PH65_釜検知 or PH66_フタ検知  then 'リフト手前位置のワーク
				釜反転出口動作中=OFF
				釜反転出口排出要求=ON
				釜反転出口step=1
			else
				inc(釜反転出口step)
			end if

		case 4
			if 釜反転出口排出要求=OFF and  洗浄コンベア搬送動作中=OFF and 洗浄コンベア搬送排出要求 then
				inc(釜反転出口step)
			else
				釜反転出口step=1
			end if

		case 5
			釜反転出口step=100
		
		'--------------------------------------------------------------------------------------------------------------
		'釜反転機起動
		case 100 'mINV3で搬送された釜フタ確認
			釜反転出口動作中=ON
			tim_procstep_val=20
			res(tim_procstep)
			
			res(timdly_PH63_釜検知)
			res(timdly_PH64_フタ検知)
			
			inc(釜反転出口step) 
		
		case 101
			if tim_procstep.B then
				inc(釜反転出口step) 
			end if
		
		case 102

		if 1 then
			if timdly_PH63_釜検知.B and timdly_PH64_フタ検知.B then
				'反転機 正転 LS5 -> LS6
				釜搬送中=ON
				釜反転出口step=200
			
			else if not(timdly_PH63_釜検知.B) and timdly_PH64_フタ検知.B then
				'反転機 逆転 LS6 -> LS5
				釜搬送中=OFF
				釜反転出口step=250
			
			else if not(timdly_PH63_釜検知.B) and not(timdly_PH64_フタ検知.B) then
				'何もしないで終了
				釜搬送中=OFF
				洗浄コンベア搬送排出要求=OFF
				釜反転出口動作中=OFF
				釜反転出口step=1
			
			end if
		end if
		
		if 0 then
			if StageDevice50=$80 then '釜検出
				'反転機 正転 LS5 -> LS6
				釜搬送中=ON
				釜反転出口step=200
			
			else if StageDevice50=$40 then 'フタ検出
				'反転機 逆転 LS6 -> LS5
				釜搬送中=OFF
				釜反転出口step=250
			
			else if StageDevice50=0 then '何もない
				'何もしないで終了
				釜搬送中=OFF
				洗浄コンベア搬送排出要求=OFF
				釜反転出口動作中=OFF
				釜反転出口step=1
			
			end if
		end if
		'--------------------------------------------------------
		'釜搬送
		case 200
			MC37_反転モータ正転step=1
			inc(釜反転出口step)
				
		case 201
			if MC37_反転モータ正転step=0 then
				inc(釜反転出口step)
			end if
		
		case 202
			setS05c3=3500
			mINV3_コンベアモータ正転=ON
			tim_procstep_val=INV3釜挿入時間 '1号機(47) 2号機(45)
			res(tim_procstep)
			inc(釜反転出口step)
		
		case 203
			if tim_procstep.B then
				inc(釜反転出口step)
			end if		

		case 204
			if not(PH63_釜検知) and not(PH64_フタ検知) then
				mINV3_コンベアモータ正転=OFF
				inc(釜反転出口step)
			end if

		case 205
			inc(釜反転出口step)

		case 206
			MC37_反転モータ逆転step=1
			inc(釜反転出口step)
		
		case 207

			洗浄コンベア搬送排出要求=OFF
			釜反転出口動作中=OFF
			inc(釜反転出口step)

		case 208
			if MC37_反転モータ逆転step=0 then
				'if PH65_釜検知 then
				'	StageDevice50=0
				'	StageDevice51=$8000+$100 '<- StageDevice  [ 釜  ］のデータ入れ込みｽﾀｰﾄ地点
				'else
				'	StageDevice50=0
				'	StageDevice51=0 '<- StageDevice  [ 釜  ］のデータ入れ込みｽﾀｰﾄ地点
				'end if
				釜反転出口排出要求=ON
				釜反転出口動作中=OFF

				釜反転出口step=1
			end if
					

		'----------------------------------------------------------------------
		'フタ搬送
		case 250
			MC37_反転モータ逆転step=1
			inc(釜反転出口step)
		
		case 251
			if MC37_反転モータ逆転step=0 then
				inc(釜反転出口step)
			end if		
		
		case 252
			setS05c3=4500
			mINV3_コンベアモータ正転=ON
			ejectMC38_搬送モータ=ON
			inc(釜反転出口step)
			
		case 253
			if not(PH63_釜検知) and not(PH64_フタ検知)  then
				res(tim釜フタ検知監視)
				inc(釜反転出口step)
			end if

		case 254
			tmr(tim釜フタ検知監視,100)
			if PH65_釜検知 or PH66_フタ検知 or tim釜フタ検知監視.B then
				inc(釜反転出口step)
			end if

		case 255
			mINV3_コンベアモータ正転=OFF
			ejectMC38_搬送モータ=OFF
			inc(釜反転出口step)
			
		case 256
			StageDevice50=0
			StageDevice51=0              '<- StageDevice [ フタ  ］のデータ入れ込みｽﾀｰﾄ地点
			釜反転出口排出要求=ON
			洗浄コンベア搬送排出要求=OFF
			釜反転出口動作中=OFF
			釜反転出口step=1
		end select
	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		釜反転出口AutoRun=OFF
		
		釜反転出口step=0 '終了
	
		res(tim_LS6_空釜反転反転位置)
		res(tim_LS5_空釜反転原点位置)
		
		if ldp(pnlPBINV3_コンベアモータ正転) then
			if mINV3_コンベアモータ正転 then
				mINV3_コンベアモータ正転=OFF
			else
				mINV3_コンベアモータ正転=ON
			end if
		end if
		
		if ldp(pnlPBMC38_搬送モータ) then
			if ejectMC38_搬送モータ then
				ejectMC38_搬送モータ=OFF
			else
				ejectMC38_搬送モータ=ON
			end if
		end if
		
		
		if ldp(pnlPBMC37_反転モータ正転 or pnlPBMC37_反転モータ逆転) then
			if ldp(pnlPBMC37_反転モータ正転) or LS5_空釜反転原点位置 then
				if not(mMC37_反転モータ逆転) and not(PH63_釜検知) and not(PH64_フタ検知) then
					mMC37_反転モータ正転=ON
					mMC37_反転モータ逆転=OFF
				end if
			else if ldp(pnlPBMC37_反転モータ逆転) or LS6_空釜反転反転位置 then
				if not(mMC37_反転モータ正転) then
					mMC37_反転モータ正転=OFF
					mMC37_反転モータ逆転=ON
				end if
			else
					mMC37_反転モータ正転=OFF
					mMC37_反転モータ逆転=ON
			end if
		end if
		if mMC37_反転モータ正転 and LS6_空釜反転反転位置 then
			mMC37_反転モータ正転=OFF
		end if
		if mMC37_反転モータ逆転 and LS5_空釜反転原点位置 then
			mMC37_反転モータ逆転=OFF
		end if


	end if '釜反転出口AutoMode and not(釜反転出口OrgErrStep)

	'===================================================================================================================
	'【 釜反転出口OrgErr処理 】
	else

		res(tim_LS6_空釜反転反転位置)
		res(tim_LS5_空釜反転原点位置)

		if ResetFlg then
			釜反転出口OrgErr=OFF
		end if		

	end if

	'===================================================================================================================
	'【タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
		res(tim_LS6_空釜反転反転位置)
		res(tim_LS5_空釜反転原点位置)

		釜反転出口Err=ON

		釜反転出口AutoRun=OFF
		
		釜反転出口step=0
		MC37_反転モータ正転step=0
		MC37_反転モータ逆転step=0

		mINV3_コンベアモータ正転=OFF
		
		tmr(tim_釜反転出口ErrStep,tim_釜反転出口ErrStep_val)
		
		select case 釜反転出口ErrStep
		case 0
		
		case 1
			if ResetFlg then
				inc(釜反転出口ErrStep)
			end if
			
		case 2
			almLS6_空釜反転反転位置=OFF
			almLS5_空釜反転原点位置=OFF
			inc(釜反転出口ErrStep) 
			
		case 3
			釜反転出口Err=OFF
			釜反転出口ErrStep=0
		end select

	end if 'if 釜反転出口ErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case 釜反転出口EmgStep
	case 0
	
	case 1
		釜反転出口AutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (釜反転出口AutoMode and 自動搬送AutoMode ) or 釜反転出口step<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseMC37_反転モータ逆転=ON
			pauseMC37_反転モータ正転=ON
			pauseMC38_搬送モータ=ON
			pauseINV3_コンベアモータ正転=ON
		
			if timstack=OFF then
				timdly_PH63_釜検知_stack=timdly_PH63_釜検知.U
				timdly_PH64_フタ検知_stack=timdly_PH64_フタ検知.U
				tim釜フタ検知監視_stack=tim釜フタ検知監視.U
				tim_procstep_stack=tim_procstep.U
				tim_INV3_コンベアモータ正転_stack=tim_INV3_コンベアモータ正転.U
				tim_MC37_反転モータ逆転_stack=tim_MC37_反転モータ逆転.U
				tim_MC37_反転モータ正転_stack=tim_MC37_反転モータ正転.U
				tim_釜反転出口ErrStep_stack=tim_釜反転出口ErrStep.U
			
				timstack=ON
			end if

			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC37_反転モータ逆転=OFF
			mMC37_反転モータ正転=OFF
			mMC38_搬送モータ=OFF
			ejectMC38_搬送モータ=OFF
			mINV3_コンベアモータ正転=OFF
		
			'---------------------------------
		end if
		
		'---------------------------------
		inc(釜反転出口EmgStep)
	case 2
		if ResetFlg then
			inc(釜反転出口EmgStep)
		end if
	case 3
		if (釜反転出口AutoMode and 自動搬送AutoMode ) or 釜反転出口step<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseMC37_反転モータ逆転=OFF
				pauseMC37_反転モータ正転=OFF
				pauseMC38_搬送モータ=OFF
				pauseINV3_コンベアモータ正転=OFF

				tim釜フタ検知監視.U=tim釜フタ検知監視_stack
				tim_procstep.U=tim_procstep_stack
				tim_INV3_コンベアモータ正転.U=tim_INV3_コンベアモータ正転_stack
				tim_MC37_反転モータ逆転.U=tim_MC37_反転モータ逆転_stack
				tim_MC37_反転モータ正転.U=tim_MC37_反転モータ正転_stack
				tim_釜反転出口ErrStep.U=tim_釜反転出口ErrStep_stack
				
				res(timdly_PH63_釜検知)
				res(timdly_PH64_フタ検知)
				'---------------------------------
				inc(釜反転出口EmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(釜反転出口EmgStep)		
		end if				
	case 4
		timstack=OFF
		釜反転出口EmgStep=0
		釜反転出口Emg=OFF
	end select
		
end if 'if 釜反転出口EmgStep=0 then
