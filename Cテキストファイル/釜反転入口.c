'釜反転入口
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	釜反転入口
'
' PH43_釜検知 -> PH57_釜検知
' PH44_フタ検知 -> PH58_フタ検知
' PH45_釜検知 -> PH59_釜検知
' PH46_フタ検知 -> PH62__フタ検知
'===================================================================================================================

'【 初期化処理 】
if CR2008 then '電源ON時初期化処理
    釜反転入口AutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    釜反転入口AutoRun=OFF
    釜反転入口許可=ON
    釜反転入口OrgErr=OFF
    釜反転入口Err=OFF
    釜反転入口Emg=OFF
    釜反転入口step=0
    釜反転入口ErrStep=0
    釜反転入口OrgErrStep=0
    釜反転入口EmgStep=0
	
	MC36_反転モータ正転step=0
	MC36_反転モータ逆転step=0
	MC35_搬送モータstep=0
	INV1_コンベアモータ正転step=0

end if
'===================================================================================================================
'【 原点 】
釜反転入口Org=LS7_釜反転機原点位置

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	釜反転入口Emg=ON
	釜反転入口EmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】

tmr(MC36_反転モータ正転 and not(LS8_釜反転機反転位置) and not(pnlPBLS8_釜反転機反転位置),tim_LS8_釜反転機反転位置,#50)
tmr(MC36_反転モータ逆転 and not(LS7_釜反転機原点位置) and not(pnlPBLS7_釜反転機原点位置),tim_LS7_釜反転機原点位置,#50)

if LS7_釜反転機原点位置 and LS8_釜反転機反転位置 then
	mMC36_反転モータ正転=OFF
	mMC36_反転モータ逆転=OFF
	almLS8_釜反転機反転位置=ON
	almLS7_釜反転機原点位置=ON
	釜反転入口ErrStep=1

else if ldp(tim_LS8_釜反転機反転位置.B) then
	mMC36_反転モータ正転=OFF
	almLS8_釜反転機反転位置=ON
	errpassLS8_釜反転機反転位置=ON
	釜反転入口ErrStep=1
else if ldp(tim_LS7_釜反転機原点位置.B) then
	mMC36_反転モータ逆転=OFF
	almLS7_釜反転機原点位置=ON
	errpassLS7_釜反転機原点位置=ON
	釜反転入口ErrStep=1
end if

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 釜反転入口AutoMode	自動モード セレクトスイッチ
'System :: 釜反転入口AutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 釜反転入口Emg	その場停止


if not(釜反転入口Emg) then  
	
	if 釜反転入口ErrStep=0  then

	if not(釜反転入口OrgErr) then

	
	'-----------------------------------------------------------------------------------------------
	'釜反転装置正転
	tmr(tim_MC36_反転モータ正転,tim_MC36_反転モータ正転_val)
	
	select case MC36_反転モータ正転step
	
	case 0
	
	case 1
		mMC36_反転モータ逆転=OFF
		mMC36_反転モータ正転=ON
		errpassLS8_釜反転機反転位置=OFF
		inc(MC36_反転モータ正転step)
		
	
	case 2
		if LS8_釜反転機反転位置 or errpassLS8_釜反転機反転位置 then
			inc(MC36_反転モータ正転step)
		end if
	
	case 3
		mMC36_反転モータ正転=OFF
		inc(MC36_反転モータ正転step)
	
	case 4
		MC36_反転モータ正転step=0
		
	end select

	'------------------------------------------------------------------------------------------------
	'釜反転装置逆転
	tmr(tim_MC36_反転モータ逆転,tim_MC36_反転モータ逆転_val)
	
	select case MC36_反転モータ逆転step
	
	case 0
	
	case 1
		inc(MC36_反転モータ逆転step)
		
	case 2
		mMC36_反転モータ正転=OFF
		mMC36_反転モータ逆転=ON
		errpassLS7_釜反転機原点位置=OFF
		inc(MC36_反転モータ逆転step)

	case 3
		if LS7_釜反転機原点位置 or errpassLS7_釜反転機原点位置 then
			inc(MC36_反転モータ逆転step)
		end if

	case 4
		mMC36_反転モータ逆転=OFF
		inc(MC36_反転モータ逆転step)
		
	case 5
		MC36_反転モータ逆転step=0
		
	end select
	'------------------------------------------------------------------------------------------------
	'MC35_搬送モータ
	tmr(tim_MC35_搬送モータ,tim_MC35_搬送モータ_val)
	
	select case MC35_搬送モータstep
	
	case 0
	
	case 1
		mMC35_搬送モータ=ON
		inc(MC35_搬送モータstep)

	case 2
		if not(PH57_釜検知) and not(PH58_フタ検知) then
			inc(MC35_搬送モータstep)
		end if	

	case 3
		if PH59_釜検知 or PH62_フタ検知 then
			inc(MC35_搬送モータstep)
		end if	

	case 4
		tim_MC35_搬送モータ_val=10
		res(tim_MC35_搬送モータ)
		inc(MC35_搬送モータstep)
		
	case 5
		if tim_MC35_搬送モータ.B then
			inc(MC35_搬送モータstep)
		end if

	case 6
		mMC35_搬送モータ=OFF
		inc(MC35_搬送モータstep)
	
	case 7
		MC35_搬送モータstep=0
	
	end select
	'------------------------------------------------------------------------------------------------
	'INV1_コンベアモータ正転
	tmr(tim_INV1_コンベアモータ正転,tim_INV1_コンベアモータ正転_val)
	tmr(tim_洗浄工程終了,tim_洗浄工程終了_val)

	
	select case INV1_コンベアモータ正転step
	
	case 0
	
	case 1
		if 釜搬送中 then
			setS05c1=4000
		else
			setS05c1=4000
		end if
		
		ejectINV1_コンベアモータ正転=ON
		inc(INV1_コンベアモータ正転step)


	case 2
		if 釜搬送中 then
			tim_洗浄工程終了_val=0
			tim_INV1_コンベアモータ正転_val=INV1釜排出時間 '1号機(27)  2号機(43)
		else
			tim_洗浄工程終了_val=40
			tim_INV1_コンベアモータ正転_val=INV1フタ排出時間 '1号機(80)  2号機(83)
		end if
		
		res(tim_洗浄工程終了)
		res(tim_INV1_コンベアモータ正転)
		inc(INV1_コンベアモータ正転step)
		
	case 3
		if not(釜搬送中) and tim_洗浄工程終了.B then
			洗浄工程終了=ON
		end if
		
		if tim_INV1_コンベアモータ正転.B then
			inc(INV1_コンベアモータ正転step)
		end if

	case 4

		釜搬送中=OFF
		ejectINV1_コンベアモータ正転=OFF
		inc(INV1_コンベアモータ正転step)
	
	case 5
		INV1_コンベアモータ正転step=0
	
	end select
	'------------------------------------------------------------------------------------------------

	if (釜反転入口AutoMode and 自動搬送AutoMode ) or 釜反転入口step<>0 then
	
		if not(釜反転入口AutoMode and 自動搬送AutoMode ) then
			釜反転入口AutoRun=OFF
		end if

	'===================================================================================================================
	'【 リフタータスク 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case 釜反転入口step
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 釜反転入口AutoRun then
				inc(釜反転入口step)
			else 
				釜反転入口step=0 '終了待機
			end if
	
		case 2
			if 釜反転入口Org then
				inc(釜反転入口step)
			else
				釜反転入口step=1
			end if
	
		case 3
'			if PH59_釜検知 or PH62_フタ検知 or shiftreg釜フタ判定0<>0 then '洗浄コンベア上のワーク搬送
			if PH59_釜検知 or PH62_フタ検知 then '洗浄コンベア上のワーク搬送
				釜反転入口動作中=OFF
				釜反転入口排出要求=ON
				釜反転入口step=1
			else
				inc(釜反転入口step)
			end if

		case 4
			if 釜反転入口排出要求=OFF and  洗浄コンベア搬送動作中=OFF and 釜フタ昇降装置A排出要求 then
				釜反転入口step=100
			else
				釜反転入口step=1
			end if
		'--------------------------------------------------------------------------------------------------------------
		case 100
			if not(LS7_釜反転機原点位置) then 
				釜反転入口OrgErr=ON
				釜反転入口step=0	

			else if PH57_釜検知 or PH58_フタ検知 then 'チェーン搬送コンベアのワーク搬送
				釜反転入口動作中=ON
				inc(釜反転入口step)

			else
				釜フタ昇降装置A排出要求=OFF
				釜反転入口step=1
			end if
			
		'--------------------------------------------------------------------------------------------------------------
		case 101
			if PH57_釜検知 and PH58_フタ検知 then
				inc(釜反転入口step) '釜搬送
			else if not(PH57_釜検知) and PH58_フタ検知 then
				釜反転入口step=150 'フタ搬送
			end if

		'--------------------------------------------------------------------------------------------------------------
		'釜搬送
		case 102
			釜搬送中=ON
			mMC35_搬送モータ=ON
			tim_procstep_val=10 '釜挿入時間
			res(tim_procstep)
			inc(釜反転入口step)
		
		case 103
			if tim_procstep.B then
				mMC35_搬送モータ=OFF
				inc(釜反転入口step)
			end if
		
		case 104
			MC36_反転モータ正転step=1
			inc(釜反転入口step)
		
		case 105
			if MC36_反転モータ正転step=0 then
				inc(釜反転入口step)
			end if
		
		case 106
			INV1_コンベアモータ正転step=1
			inc(釜反転入口step)
		
		case 107
			if INV1_コンベアモータ正転step=0 then
				inc(釜反転入口step)
			end if
		
		case 108
			釜反転入口排出要求=ON '洗浄コンベア：起動
			MC36_反転モータ逆転step=1
			inc(釜反転入口step)

		case 109
			if MC36_反転モータ逆転step=0 then
				inc(釜反転入口step)
			end if
						
		case 110
			釜フタ昇降装置A排出要求=OFF	'釜フタ昇降装置A：リフト下降
			洗浄入口搬送排出要求=ON
			釜反転入口排出要求=ON
			釜反転入口動作中=OFF
			釜反転入口step=1

		'------------------------------------
		'フタ搬送
		case 150
			MC35_搬送モータstep=1
			INV1_コンベアモータ正転step=1
			inc(釜反転入口step)
		
		case 151
			if MC35_搬送モータstep=0 and INV1_コンベアモータ正転step=0 then
				inc(釜反転入口step)
			end if
		
		case 152
			釜フタ昇降装置A排出要求=OFF	'釜フタ昇降装置A：リフト下降
			洗浄入口搬送排出要求=ON
			釜反転入口排出要求=ON
			釜反転入口動作中=OFF
			釜反転入口step=1
		'--------------------------------------------------------------------------------------------------------------
			
		end select
	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		釜反転入口AutoRun=OFF
		
		釜反転入口step=0 '終了
	
		res(tim_LS7_釜反転機原点位置)
		res(tim_LS8_釜反転機反転位置)
		
		if ldp(pnlPBINV1_コンベアモータ正転) then
			if ejectINV1_コンベアモータ正転 then
				ejectINV1_コンベアモータ正転=OFF
			else
				ejectINV1_コンベアモータ正転=ON
			end if
		end if
		
		if ldp(pnlPBMC35_搬送モータ) then
			if mMC35_搬送モータ then
				mMC35_搬送モータ=OFF
			else
				mMC35_搬送モータ=ON
			end if
		end if
		
		
		if ldp(pnlPBMC36_反転モータ正転 or pnlPBMC36_反転モータ逆転) then
			if ldp(pnlPBMC36_反転モータ正転) or LS7_釜反転機原点位置 then
				if not(mMC36_反転モータ逆転) and not(PH59_釜検知) and not(PH62_フタ検知) then
					mMC36_反転モータ正転=ON
					mMC36_反転モータ逆転=OFF
				end if
			else if ldp(pnlPBMC36_反転モータ逆転) or LS8_釜反転機反転位置 then
				if not(mMC36_反転モータ正転) then
					mMC36_反転モータ正転=OFF
					mMC36_反転モータ逆転=ON
				end if
			else
					mMC36_反転モータ正転=OFF
					mMC36_反転モータ逆転=ON
			end if
		end if
		if mMC36_反転モータ正転 and LS8_釜反転機反転位置 then
			mMC36_反転モータ正転=OFF
		end if
		if mMC36_反転モータ逆転 and LS7_釜反転機原点位置 then
			mMC36_反転モータ逆転=OFF
		end if


	end if '釜反転入口AutoMode and not(釜反転入口OrgErrStep)

	'===================================================================================================================
	'【 釜反転入口OrgErr処理 】
	else

		res(tim_LS7_釜反転機原点位置)
		res(tim_LS8_釜反転機反転位置)

		if ResetFlg then
			釜反転入口OrgErr=OFF
		end if		

	end if

	'===================================================================================================================
	'【タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
		res(tim_LS7_釜反転機原点位置)
		res(tim_LS8_釜反転機反転位置)

		釜反転入口Err=ON

		釜反転入口AutoRun=OFF
		釜反転入口step=0

		select case 釜反転入口ErrStep
		case 0
		case 1
			if ResetFlg then
				almLS8_釜反転機反転位置=OFF
				almLS7_釜反転機原点位置=OFF
				inc(釜反転入口ErrStep)
			end if
		case 2
			釜反転入口Err=OFF
			釜反転入口ErrStep=0
		end select

	end if 'if 釜反転入口ErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else

	select case 釜反転入口EmgStep
	case 0

	case 1
		釜反転入口AutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (釜反転入口AutoMode and 自動搬送AutoMode ) or 釜反転入口step<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseMC35_搬送モータ=ON
			pauseMC36_反転モータ正転=ON
			pauseMC36_反転モータ逆転=ON
			pauseINV1_コンベアモータ正転=ON

			if timstack=OFF then
				timdly_PH59_釜検知_stack=timdly_PH59_釜検知.U
				timdly_PH60_フタ検知_stack=timdly_PH60_フタ検知.U
				tim_procstep_stack=tim_procstep.U
				tim_INV1_コンベアモータ正転_stack=tim_INV1_コンベアモータ正転.U
				tim_MC30_搬送モータ_stack=tim_MC30_搬送モータ.U
				tim_MC36_反転モータ逆転_stack=tim_MC36_反転モータ逆転.U
				tim_MC36_反転モータ正転_stack=tim_MC36_反転モータ正転.U
				tim_MC35_搬送モータ_stack=tim_MC35_搬送モータ.U
				tim_洗浄工程終了_stack=tim_洗浄工程終了.U
			
				timstack=ON
			end if
			
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC35_搬送モータ=OFF
			mMC36_反転モータ正転=OFF
			mMC36_反転モータ逆転=OFF
			mINV1_コンベアモータ正転=OFF
			ejectINV1_コンベアモータ正転=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(釜反転入口EmgStep)
	case 2
		if ResetFlg then
			inc(釜反転入口EmgStep)
		end if
	case 3
		if (釜反転入口AutoMode and 自動搬送AutoMode ) or 釜反転入口step<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseMC35_搬送モータ=OFF
				pauseMC36_反転モータ正転=OFF
				pauseMC36_反転モータ逆転=OFF
				pauseINV1_コンベアモータ正転=OFF

				timdly_PH59_釜検知.U=timdly_PH59_釜検知_stack
				timdly_PH60_フタ検知.U=timdly_PH60_フタ検知_stack
				tim_procstep.U=tim_procstep_stack
				tim_INV1_コンベアモータ正転.U=tim_INV1_コンベアモータ正転_stack
				tim_MC30_搬送モータ.U=tim_MC30_搬送モータ_stack
				tim_MC36_反転モータ逆転.U=tim_MC36_反転モータ逆転_stack
				tim_MC36_反転モータ正転.U=tim_MC36_反転モータ正転_stack
				tim_MC35_搬送モータ.U=tim_MC35_搬送モータ_stack
				tim_洗浄工程終了.U=tim_洗浄工程終了_stack
			
				'---------------------------------
				inc(釜反転入口EmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(釜反転入口EmgStep)		
		end if				
	case 4
		timstack=OFF
		釜反転入口EmgStep=0
		釜反転入口Emg=OFF
	end select

end if 'if 釜反転入口EmgStep=0 then
