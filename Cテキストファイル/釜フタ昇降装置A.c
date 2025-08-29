'釜フタ昇降装置A
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	釜フタ昇降装置A
'	
' PH41_釜検知	-> PH55_釜検知
' PH42_フタ検知	-> PH56_フタ検知
' PH43_釜検知	-> PH57_釜検知
' PH44_フタ検知 -> PH58_フタ検知
' PH45_釜検知	-> PH59_釜検知
' PH46_フタ検知	-> PH62__フタ検知
' MC30_搬送モータ -> MC57_搬送モータ
' SV57_リフト	-> SV59_リフト上昇
' (新規)		-> SV76_リフト下降
' XSW72_リフト上昇端 -> XSW80_リフト上昇端
' XSW71_リフト下降端 -> XSW81_リフト下降端
' 搬送コンベアF排出要求 -> 搬送コンベアH排出要求
'===================================================================================================================

'【 初期化処理 】
if CR2008 then '電源ON時初期化処理

    釜フタ昇降装置AAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    釜フタ昇降装置AAutoRun=OFF
    釜フタ昇降装置A許可=ON
    釜フタ昇降装置AOrgErr=OFF
    釜フタ昇降装置AErr=OFF
    釜フタ昇降装置AEmg=OFF
    釜フタ昇降装置Astep=0
    釜フタ昇降装置AErrStep=0
    釜フタ昇降装置AOrgErrStep=0
    釜フタ昇降装置AEmgStep=0
	
	MC55_搬送モータstep=0
	MC57_搬送モータstep=0
	
	
end if
'===================================================================================================================
'【 原点 】
釜フタ昇降装置AOrg=((XSW80_リフト上昇端 and not(pnlPBXSW80_リフト上昇端)) or passXSW80_リフト上昇端) or ((XSW81_リフト下降端 and not(pnlPBXSW81_リフト下降端)) or passXSW81_リフト下降端)

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	釜フタ昇降装置AEmg=ON
	釜フタ昇降装置AEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
'エラー検出にKeepを使用すると、停止時にエラーを検出し昇降装置が動き出す。
'tmr( (SVxx or Keepxx) and ....)  ->  tmr(SVxx and)
tmr(SV59_リフト上昇 and not(XSW80_リフト上昇端) and not(pnlPBXSW80_リフト上昇端), tim_notXSW80_リフト上昇端,#70)
tmr(SV76_リフト下降 and not(XSW81_リフト下降端) and not(pnlPBXSW81_リフト下降端), tim_notXSW81_リフト下降端,#70)
tmr(SV59_リフト上昇 and XSW81_リフト下降端 and not(pnlPBXSW81_リフト下降端), tim_XSW81_リフト下降端,#10)
tmr(SV76_リフト下降 and XSW80_リフト上昇端 and not(pnlPBXSW80_リフト上昇端), tim_XSW80_リフト上昇端,#10)

if SV59_リフト上昇 and not(SV76_リフト下降) then
	KeepSV59_リフト上昇=ON
else if SV76_リフト下降 then
	KeepSV59_リフト上昇=OFF
end if

if SV76_リフト下降 and not(SV59_リフト上昇) then
	KeepSV76_リフト下降=ON
else if SV59_リフト上昇 then
	KeepSV76_リフト下降=OFF
end if


tms(SV59_リフト上昇 or KeepSV59_リフト上昇,passtimXSW80_リフト上昇端,passtimXSW80_リフト上昇端_val)
tms(SV76_リフト下降 or KeepSV76_リフト下降,passtimXSW81_リフト下降端,passtimXSW81_リフト下降端_val)

if ldp(tim_XSW80_リフト上昇端.B) or ldp(tim_notXSW80_リフト上昇端.B) then
	if 釜フタ昇降装置Astep>0 and tim_notXSW80_リフト上昇端.B then
		errpassXSW80_リフト上昇端=ON
		mSV59_リフト上昇=OFF
		mSV76_リフト下降=ON	
	end if
	almXSW80_リフト上昇端=ON
	pnlPBXSW80_リフト上昇端=ON
	釜フタ昇降装置AErrStep=1

else if ldp(tim_XSW81_リフト下降端.B) or ldp(tim_notXSW81_リフト下降端.B) then
	if 釜フタ昇降装置Astep>0 and tim_notXSW81_リフト下降端.B then
		errpassXSW81_リフト下降端=ON
		mSV59_リフト上昇=ON
		mSV76_リフト下降=OFF
	end if
	almXSW81_リフト下降端=ON
	pnlPBXSW81_リフト下降端=ON
	釜フタ昇降装置AErrStep=1

end if

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 釜フタ昇降装置AAutoMode	自動モード セレクトスイッチ
'System :: 釜フタ昇降装置AAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 釜フタ昇降装置AEmg	その場停止

tmr(PH55_釜検知,timdly_PH55_釜検知,4)
tmr(PH56_フタ検知,timdly_PH56_フタ検知,4)
tmr(not(PH55_釜検知),timnotdly_PH55_釜検知,4)
tmr(not(PH56_フタ検知),timnotdly_PH56_フタ検知,4)


if 釜フタ昇降装置AEmgStep=0 then  
	
	if 釜フタ昇降装置AErrStep=0  then

	if not(釜フタ昇降装置AOrgErr) then

	if (釜フタ昇降装置AAutoMode and 自動搬送AutoMode ) or 釜フタ昇降装置Astep<>0 then
	
		if not(釜フタ昇降装置AAutoMode and 自動搬送AutoMode ) then
			釜フタ昇降装置AAutoRun=OFF
		end if
	'------------------------------------------------------------------------------------------------
	'フタ釜供給
	tmr(tim_MC55_搬送モータ,tim_MC55_搬送モータ_val)
	
	select case MC55_搬送モータstep
	case 0
	
	case 1
		if (PH68_釜検知 or PH69_フタ検知) and not(PH55_釜検知) and not(PH56_フタ検知) then
			inc(MC55_搬送モータstep)
		else
			MC55_搬送モータstep=0
		end if

	case 2
		mMC55_搬送モータ=ON
		mMC57_搬送モータ=ON
		inc(MC55_搬送モータstep)
	
	case 3
		if not(PH68_釜検知) and not(PH69_フタ検知) then
			inc(MC55_搬送モータstep)
		end if

	case 4
		if PH55_釜検知 or PH56_フタ検知 then
			inc(MC55_搬送モータstep)
		end if
	
	case 5
		tim_MC55_搬送モータ_val=2
		res(tim_MC55_搬送モータ)
		inc(MC55_搬送モータstep)
	
	case 6
		if tim_MC55_搬送モータ.B then
			inc(MC55_搬送モータstep)
		end if
	
	case 7
		if PH55_釜検知 and  PH56_フタ検知 then 
			tim_MC55_搬送モータ_val=20
		else
			tim_MC55_搬送モータ_val=15
		end if
		
		res(tim_MC55_搬送モータ)
		inc(MC55_搬送モータstep)
		
	case 8
		if tim_MC55_搬送モータ.B then
			inc(MC55_搬送モータstep)
		end if
	
	case 9
		mMC55_搬送モータ=OFF
		mMC57_搬送モータ=OFF
		inc(MC55_搬送モータstep)
		
	case 10
		搬送コンベアH排出要求=OFF
		MC55_搬送モータstep=0
	end select
	'------------------------------------------------------------------------------------------------
	'フタ釜排出
	tmr(tim_MC57_搬送モータ,tim_MC57_搬送モータ_val)
	
	select case MC57_搬送モータstep
	case 0
	case 1
		mMC57_搬送モータ=ON
		ejectMC35_搬送モータ=ON
		inc(MC57_搬送モータstep)
	case 2
		if not(PH55_釜検知) and not(PH56_フタ検知) then
			inc(MC57_搬送モータstep)
		end if	
	case 3
		if PH57_釜検知 or PH58_フタ検知 then
			inc(MC57_搬送モータstep)
		end if	

	case 4
		if 釜搬送中 then
			tim_MC57_搬送モータ_val=10
		else
			tim_MC57_搬送モータ_val=4
		end if
		
		res(tim_MC57_搬送モータ)
		inc(MC57_搬送モータstep)

	case 5
		if tim_MC57_搬送モータ.B then
			釜フタ昇降装置A排出要求=ON
			mMC57_搬送モータ=OFF
			ejectMC35_搬送モータ=OFF
			inc(MC57_搬送モータstep)
		end if

	case 6
		mSV59_リフト上昇=OFF
		mSV76_リフト下降=ON
		errpassXSW81_リフト下降端=OFF
		inc(MC57_搬送モータstep)
	
	case 7
		tim_MC57_搬送モータ_val=40
		res(tim_MC57_搬送モータ)
		inc(MC57_搬送モータstep)

	case 8
		if tim_MC57_搬送モータ.B then
			inc(MC57_搬送モータstep)	
		end if

	case 9
		if errpassXSW81_リフト下降端 or ((XSW81_リフト下降端 and not(pnlPBXSW81_リフト下降端)) or passXSW81_リフト下降端) then
			inc(MC57_搬送モータstep)
		end if
	
	case 10
		釜フタ昇降装置A動作中=OFF
		inc(MC57_搬送モータstep)

	case 11
		MC57_搬送モータstep=0
	
	end select

	'===================================================================================================================
	'【 リフタータスク 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case 釜フタ昇降装置Astep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 釜フタ昇降装置AAutoRun then
				inc(釜フタ昇降装置Astep)
			else 
				釜フタ昇降装置Astep=0 '終了待機
			end if

		case 2
			if 釜フタ昇降装置AOrg then
				inc(釜フタ昇降装置Astep)
			else
				釜フタ昇降装置Astep=1
			end if

		case 3
			if PH57_釜検知 or PH58_フタ検知 then '洗浄コンベア上のワーク搬送
				釜フタ昇降装置A排出要求=ON
				釜フタ昇降装置A動作中=OFF
			end if
			inc(釜フタ昇降装置Astep)

		case 4
			if timdly_PH55_釜検知 or timdly_PH56_フタ検知 then '通常搬送：リフトのワーク搬送
				釜フタ昇降装置Astep=200
			else if timnotdly_PH55_釜検知 and timnotdly_PH56_フタ検知 then
				釜フタ昇降装置Astep=100
			else
				釜フタ昇降装置Astep=1
			end if
	

		'--------------------------------------------------------------------------------------------------------------
		case 100
			if not(mSV76_リフト下降) then
				tim_procstep_val=40
				res(tim_procstep)
			end if
			mSV59_リフト上昇=OFF
			mSV76_リフト下降=ON
			errpassXSW81_リフト下降端=OFF
			inc(釜フタ昇降装置Astep)

		case 101
			if tim_procstep.B then
				inc(釜フタ昇降装置Astep)
			end if
		
		case 102
			if errpassXSW81_リフト下降端 or ((XSW81_リフト下降端 and not(pnlPBXSW81_リフト下降端)) or passXSW81_リフト下降端) then
				inc(釜フタ昇降装置Astep)
			end if
		
		case 103
			if 搬送コンベアH排出要求 then
				inc(釜フタ昇降装置Astep)
			else
				釜フタ昇降装置Astep=1
			end if
		
		case 104
			MC55_搬送モータstep=1
			inc(釜フタ昇降装置Astep)
		
		case 105
			if MC55_搬送モータstep=0 then
				inc(釜フタ昇降装置Astep)
			end if
		
		case 106
			if timdly_PH55_釜検知 or timdly_PH56_フタ検知 then '通常搬送：リフトのワーク搬送
				釜フタ昇降装置Astep=200
			else
				釜フタ昇降装置Astep=1
			end if

		'--------------------------------------------------------------------------------------------------------------
		case 200 'リフト上昇 -> 指定待機位置に釜フタ搬送
			if not(mSV59_リフト上昇) then
				tim_procstep_val=40
				res(tim_procstep)
			end if		
		
			mSV59_リフト上昇=ON
			mSV76_リフト下降=OFF
			errpassXSW80_リフト上昇端=OFF
			搬送コンベアH排出要求=OFF
			釜フタ昇降装置A動作中=ON
			inc(釜フタ昇降装置Astep)
		
		case 201
			if tim_procstep.B then
				inc(釜フタ昇降装置Astep)
			end if
		
		case 202
			if errpassXSW80_リフト上昇端 or ((XSW80_リフト上昇端 and not(pnlPBXSW80_リフト上昇端)) or passXSW80_リフト上昇端) then
				inc(釜フタ昇降装置Astep)
			end if

		case 203
			'------------------------------------------------------
			' 釜フタ昇降装置A 上昇待機
			if 釜フタ昇降装置A排出要求=OFF and  釜反転入口動作中=OFF and LS7_釜反転機原点位置 then
				inc(釜フタ昇降装置Astep)
			else
				釜フタ昇降装置Astep=1
			end if
			'------------------------------------------------------

		case 204
			if not(PH57_釜検知) and not(PH58_フタ検知) then
				inc(釜フタ昇降装置Astep)
			end if				

		case 205
			if PH55_釜検知 and PH56_フタ検知 then
				釜搬送中=ON
			else if not(PH55_釜検知) and PH56_フタ検知 then
				釜搬送中=OFF
			end if
			inc(釜フタ昇降装置Astep)
		
		case 206
			MC57_搬送モータstep=1
			inc(釜フタ昇降装置Astep)
		
		case 207
			if MC57_搬送モータstep=0 then
				inc(釜フタ昇降装置Astep)
			end if
		
		case 208
			if not(mSV76_リフト下降) then
				tim_procstep_val=40
				res(tim_procstep)
			end if
			mSV59_リフト上昇=OFF
			mSV76_リフト下降=ON
			errpassXSW81_リフト下降端=OFF
			inc(釜フタ昇降装置Astep)
		
		case 209
			if tim_procstep.B then
				inc(釜フタ昇降装置Astep)
			end if

		case 210
			if errpassXSW81_リフト下降端 or ((XSW81_リフト下降端 and not(pnlPBXSW81_リフト下降端)) or passXSW81_リフト下降端) then
				inc(釜フタ昇降装置Astep)
			end if

		case 211
			釜フタ昇降装置A動作中=OFF
			釜フタ昇降装置Astep=1
		'--------------------------------------------------------------------------------------------------------------
			
		end select
	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		釜フタ昇降装置AAutoRun=OFF
		
		釜フタ昇降装置Astep=0 '終了
	
		
		if ldp(pnlPBSV59_リフト上昇)  then
			if mSV59_リフト上昇 then
				mSV59_リフト上昇=OFF
				mSV76_リフト下降=ON
			else if not(MC57_搬送モータ) then
				mSV59_リフト上昇=ON
				mSV76_リフト下降=OFF
			end if
		end if
		
		if ldp(pnlPBMC57_搬送モータ) then
			if mMC57_搬送モータ then
				mMC57_搬送モータ=OFF
			else if ((XSW80_リフト上昇端 and not(pnlPBXSW80_リフト上昇端)) or passXSW80_リフト上昇端) or ((XSW81_リフト下降端 and not(pnlPBXSW81_リフト下降端)) or passXSW81_リフト下降端) then
				mMC57_搬送モータ=ON
			end if
		end if
		
		if ldp(pnlPBMC35_搬送モータ) then
			if ejectMC35_搬送モータ then
				ejectMC35_搬送モータ=OFF
			else
				ejectMC35_搬送モータ=ON
			end if
		end if
		

	end if '釜フタ昇降装置AAutoMode and not(釜フタ昇降装置AOrgErrStep)

	'===================================================================================================================
	'【 釜フタ昇降装置AOrgErr処理 】
	else

		res(tim_XSW80_リフト上昇端)
		res(tim_XSW81_リフト下降端)

		if ResetFlg then
			釜フタ昇降装置AOrgErr=OFF
		end if		

	end if

	'===================================================================================================================
	'【タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
		res(tim_XSW80_リフト上昇端)
		res(tim_XSW81_リフト下降端)
		res(tim_notXSW80_リフト上昇端)
		res(tim_notXSW81_リフト下降端)

		釜フタ昇降装置AErr=ON

		select case 釜フタ昇降装置AErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW80_リフト上昇端=OFF
				almXSW81_リフト下降端=OFF

				inc(釜フタ昇降装置AErrStep)
			end if
		case 2

			釜フタ昇降装置AErr=OFF
			釜フタ昇降装置AErrStep=0
			
			釜フタ昇降装置Astep=0 '終了待機

		end select

	end if 'if 釜フタ昇降装置AErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else

	select case 釜フタ昇降装置AEmgStep
	case 0
	
	case 1
		釜フタ昇降装置AAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (釜フタ昇降装置AAutoMode and 自動搬送AutoMode ) or 釜フタ昇降装置Astep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseMC35_搬送モータ=ON
			pauseMC55_搬送モータ=ON
			pauseMC57_搬送モータ=ON

			if timstack=OFF then
				timdly_PH55_釜検知_stack=timdly_PH55_釜検知.U
				timdly_PH56_フタ検知_stack=timdly_PH56_フタ検知.U
				timnotdly_PH55_釜検知_stack=timnotdly_PH55_釜検知.U
				timnotdly_PH56_フタ検知_stack=timnotdly_PH56_フタ検知.U
				tim_procstep_stack=tim_procstep.U
				tim_MC55_搬送モータ_stack=tim_MC55_搬送モータ.U
				tim_MC57_搬送モータ_stack=tim_MC57_搬送モータ.U

				timstack=ON
			end if

			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			ejectMC35_搬送モータ=OFF
			mMC55_搬送モータ=OFF
			mMC57_搬送モータ=OFF
			mSV59_リフト上昇=OFF
			mSV76_リフト下降=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(釜フタ昇降装置AEmgStep)
	case 2
		if ResetFlg then
			inc(釜フタ昇降装置AEmgStep)
		end if
	case 3
		if (釜フタ昇降装置AAutoMode and 自動搬送AutoMode ) or 釜フタ昇降装置Astep<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseMC35_搬送モータ=OFF
				pauseMC55_搬送モータ=OFF
				pauseMC57_搬送モータ=OFF

				timdly_PH55_釜検知.U=timdly_PH55_釜検知_stack
				timdly_PH56_フタ検知.U=timdly_PH56_フタ検知_stack
				timnotdly_PH55_釜検知.U=timnotdly_PH55_釜検知_stack
				timnotdly_PH56_フタ検知.U=timnotdly_PH56_フタ検知_stack
				tim_procstep.U=tim_procstep_stack
				tim_MC55_搬送モータ.U=tim_MC55_搬送モータ_stack
				tim_MC57_搬送モータ.U=tim_MC57_搬送モータ_stack

				'---------------------------------
				inc(釜フタ昇降装置AEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(釜フタ昇降装置AEmgStep)		
		end if				
	case 4
		timstack=OFF
		釜フタ昇降装置AEmgStep=0
		釜フタ昇降装置AEmg=OFF
	end select

end if 'if 釜フタ昇降装置AEmgStep=0 then
