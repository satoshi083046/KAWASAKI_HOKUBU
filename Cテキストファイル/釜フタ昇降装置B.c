'釜フタ昇降装置B
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	釜フタ昇降装置B
'	
' PH9_釜検知	->PH65_釜検知
' PH10_フタ検知	->PH66_フタ検知
' MC32_搬送モータ ->MC38_搬送モータ
' (SV20_リフト)	-> (SV20_リフト)
' (XSW18_リフト上昇端)	->(XSW18_リフト上昇端)
' (XSW17_リフト下降端)	->(XSW17_リフト下降端)
' 
' PH39釜検知	->PH60_釜検知
' PH40_フタ検知	->PH61_フタ検知
' (MC11_搬送モータ) ->(MC11_搬送モータ)
' 
' PH50_釜検知	->PH1_釜検知
' PH51_フタ検知	->PH2_フタ検知
' 
' 
'===================================================================================================================
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理
    釜フタ昇降装置BAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    釜フタ昇降装置BAutoRun=OFF
    釜フタ昇降装置B許可=ON
    釜フタ昇降装置BOrgErr=OFF
    釜フタ昇降装置BErr=OFF
    釜フタ昇降装置BEmg=OFF
    釜フタ昇降装置Bstep=0
    釜フタ昇降装置BErrStep=0
    釜フタ昇降装置BOrgErrStep=0
    釜フタ昇降装置BEmgStep=0
	
	MC38_搬送モータstep=0
	MC11_搬送モータstep=0
	MC11_搬送モータ排出step=0
	
	
end if
'===================================================================================================================
'【 原点 】
釜フタ昇降装置BOrg=((XSW17_リフト下降端 and not(pnlPBXSW17_リフト下降端)) or passXSW17_リフト下降端) or ((XSW18_リフト上昇端 and not(pnlPBXSW18_リフト上昇端))  or passXSW18_リフト上昇端)

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	釜フタ昇降装置BEmg=ON
	釜フタ昇降装置BEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
'エラー検出にKeepを使用すると、停止時にエラーを検出し昇降装置が動き出す。
'tmr( (SVxx or Keepxx) and ....)  ->  tmr(SVxx and)
tmr(SV20_リフト上昇 and not(XSW18_リフト上昇端) and not(pnlPBXSW18_リフト上昇端), tim_notXSW18_リフト上昇端,#60)
tmr(SV32_リフト下降 and not(XSW17_リフト下降端) and not(pnlPBXSW17_リフト下降端), tim_notXSW17_リフト下降端,#60)
tmr(SV32_リフト下降 and XSW18_リフト上昇端 and not(pnlPBXSW18_リフト上昇端), tim_XSW18_リフト上昇端,#10)
tmr(SV20_リフト上昇 and XSW17_リフト下降端 and not(pnlPBXSW17_リフト下降端), tim_XSW17_リフト下降端,#10)

if SV20_リフト上昇 and not(SV32_リフト下降) then
	KeepSV20_リフト上昇=ON
else if SV32_リフト下降 then
	KeepSV20_リフト上昇=OFF
end if

if SV32_リフト下降 and not(SV20_リフト上昇) then
	KeepSV32_リフト下降=ON
else if SV20_リフト上昇 then
	KeepSV32_リフト下降=OFF
end if

tms(SV20_リフト上昇 or KeepSV20_リフト上昇,passtimXSW18_リフト上昇端,passtimXSW18_リフト上昇端_val)
tms(SV32_リフト下降 or KeepSV32_リフト下降,passtimXSW17_リフト下降端,passtimXSW17_リフト下降端_val)

if ldp(tim_XSW18_リフト上昇端.B) or ldp(tim_notXSW18_リフト上昇端.B) then
	if 釜フタ昇降装置Bstep>0 and tim_notXSW18_リフト上昇端 then
		errpassXSW18_リフト上昇端=ON
		mSV20_リフト上昇=OFF
		mSV32_リフト下降=ON
	end if
	almXSW18_リフト上昇端=ON
	pnlPBXSW18_リフト上昇端=ON
	釜フタ昇降装置BErrStep=1

else if ldp(tim_XSW17_リフト下降端.B) or ldp(tim_notXSW17_リフト下降端.B) then
	if 釜フタ昇降装置Bstep>0 and tim_notXSW17_リフト下降端.B then
		errpassXSW17_リフト下降端=ON
		mSV20_リフト上昇=ON
		mSV32_リフト下降=OFF
	end if
	almXSW17_リフト下降端=ON
	pnlPBXSW17_リフト下降端=ON
	釜フタ昇降装置BErrStep=1

end if
'===================================================================================================================
'検知タイマー

TMR(PH1_釜検知,timdly_PH1_釜検知,5)
TMR(PH2_フタ検知,timdly_PH2_フタ検知,5)

tmr(PH60_釜検知,timdly_PH60_釜検知,4)
tmr(PH61_フタ検知,timdly_PH61_フタ検知,4)
tmr(not(PH60_釜検知),timnotdly_PH60_釜検知,4)
tmr(not(PH61_フタ検知),timnotdly_PH61_フタ検知,4)

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 釜フタ昇降装置BAutoMode	自動モード セレクトスイッチ
'System :: 釜フタ昇降装置BAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 釜フタ昇降装置BEmg	その場停止


if 釜フタ昇降装置BEmgStep=0 then  
	
	if 釜フタ昇降装置BErrStep=0  then

	if not(釜フタ昇降装置BOrgErr) then

		
	'------------------------------------------------------------------------------------------------
	'MC38_搬送モータ
	tmr(tim_MC38_搬送モータ,tim_MC38_搬送モータ_val)
	
	select case MC38_搬送モータstep
	
	case 0
	
	case 1
		mMC38_搬送モータ=ON
		inc(MC38_搬送モータstep)

	case 2
		if not(PH65_釜検知) and not(PH66_フタ検知) then
				inc(MC38_搬送モータstep)
		end if

	case 3
		if PH60_釜検知 or PH61_フタ検知 then
			tim_MC38_搬送モータ_val=1 'モータ停止タイミング
			res(tim_MC38_搬送モータ)
			inc(MC38_搬送モータstep)
		end if
	
	case 4
		if tim_MC38_搬送モータ.B then
			inc(MC38_搬送モータstep)
		end if
		
	case 5
		mMC38_搬送モータ=OFF
		inc(MC38_搬送モータstep)
	
	case 6
		MC38_搬送モータstep=0

	end select
	'------------------------------------------------------------------------------------------------
	'MC11_搬送モータ
	tmr(tim_MC11_搬送モータ,tim_MC11_搬送モータ_val)
	
	select case MC11_搬送モータstep	
	case 0
	case 1
		mMC11_搬送モータ=ON
		inc(MC11_搬送モータstep)

	case 2
		if not(PH65_釜検知) and not(PH66_フタ検知) then
				inc(MC11_搬送モータstep)
		end if
	case 3
		if PH60_釜検知 or PH61_フタ検知 then
			if 釜搬送中 or PH60_釜検知 then
				tim_MC11_搬送モータ_val=17 '15 'モータ停止タイミング
			else if not(釜搬送中) or PH61_フタ検知 then
				tim_MC11_搬送モータ_val=6 'モータ停止タイミング
			end if			
			
			res(tim_MC11_搬送モータ)
			inc(MC11_搬送モータstep)
		end if
	
	case 4
		釜搬送中=OFF
		if tim_MC11_搬送モータ.B then
			inc(MC11_搬送モータstep)
		end if
		
	case 5
		mMC11_搬送モータ=OFF
		inc(MC11_搬送モータstep)
	
	case 6
		MC11_搬送モータstep=0

	end select
	'------------------------------------------------------------------------------------------------
	'MC11_搬送モータ排出
	tmr(tim_MC11_搬送モータ排出,tim_MC11_搬送モータ排出_val)
	
	select case MC11_搬送モータ排出step	
	case 0
	case 1
		PH60_釜起動検知=PH60_釜検知 '----釜フタ昇降装置B
		PH61_フタ起動検知=PH61_フタ検知
		'PH1_釜検知 '----搬送口
		'PH2_フタ検知
		inc(MC11_搬送モータ排出step)
	
	case 2
		if not(mSV32_リフト下降) then
			tim_MC11_搬送モータ排出_val=40
			res(tim_MC11_搬送モータ排出)
		end if
		mSV20_リフト上昇=OFF
		mSV32_リフト下降=ON
		errpassXSW17_リフト下降端=OFF
		inc(MC11_搬送モータ排出step)
	
	case 3
		if tim_MC11_搬送モータ排出.B then
			inc(MC11_搬送モータ排出step)
		end if		
	
	case 4
		if errpassXSW17_リフト下降端 or ((XSW17_リフト下降端 and not(pnlPBXSW17_リフト下降端)) or passXSW17_リフト下降端) then
			inc(MC11_搬送モータ排出step)
		end if
	
	case 5
		tim_MC11_搬送モータ排出_val=0
		res(tim_MC11_搬送モータ排出)
		inc(MC11_搬送モータ排出step)
	
	case 6
		if tim_MC11_搬送モータ排出.B then
			inc(MC11_搬送モータ排出step)
		end if
	
	case 7
		mMC11_搬送モータ=ON
		ejectMC6_搬送モータ=ON
		inc(MC11_搬送モータ排出step)

	case 8
		if not(PH60_釜検知) and not(PH61_フタ検知) then
			inc(MC11_搬送モータ排出step)
		end if
	
	case 9
		tim_MC11_搬送モータ排出_val=37
		res(tim_MC11_搬送モータ排出)
		inc(MC11_搬送モータ排出step)
	
	case 10
		if tim_MC11_搬送モータ排出.B then
			RES(timdly_PH1_釜検知)
			RES(timdly_PH2_フタ検知)
			inc(MC11_搬送モータ排出step)
		end if

	case 11
		if (PH1_釜検知 and timdly_PH1_釜検知) or (PH2_フタ検知 and timdly_PH2_フタ検知) then
			inc(MC11_搬送モータ排出step)
		end if
	
	case 12
		tim_MC11_搬送モータ排出_val=3
		res(tim_MC11_搬送モータ排出)
		inc(MC11_搬送モータ排出step)

	case 13
		if tim_MC11_搬送モータ排出.B then
			inc(MC11_搬送モータ排出step)		
		end if
	
	case 14
		mMC11_搬送モータ=OFF
		ejectMC6_搬送モータ=OFF
		inc(MC11_搬送モータ排出step)
	
	case 15
		MC11_搬送モータ排出step=0

	end select

	'===================================================================================================================
	'【 リフタータスク 】
	'
	if (釜フタ昇降装置BAutoMode and 自動搬送AutoMode ) or 釜フタ昇降装置Bstep<>0 then
	
		if not(釜フタ昇降装置BAutoMode and 自動搬送AutoMode ) then
			釜フタ昇降装置BAutoRun=OFF
		end if


		tmr(tim_procstep,tim_procstep_val)

		select case 釜フタ昇降装置Bstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 釜フタ昇降装置BAutoRun then
				inc(釜フタ昇降装置Bstep)
			else 
				釜フタ昇降装置Bstep=0 '終了待機
			end if
		
		case 2
			if 釜フタ昇降装置BOrg then
				inc(釜フタ昇降装置Bstep)
			else
				釜フタ昇降装置Bstep=1
			end if

		case 3
			if timdly_PH60_釜検知.B or timdly_PH61_フタ検知.B then
				釜フタ昇降装置Bstep=100 'リフトに釜フタあり
			else if timnotdly_PH60_釜検知.B and timnotdly_PH61_フタ検知.B then
				釜フタ昇降装置Bstep=200 'リフトに釜フタなし
			end if
		'--------------------------------------------------------------------------------------------------------------
		’[リフト下降]
		case 100
			釜フタ昇降装置B動作中=OFF
			inc(釜フタ昇降装置Bstep)
		
		case 101
			if not(mSV32_リフト下降) then
				tim_procstep_val=40
				res(tim_procstep)
			end if
						
			mSV20_リフト上昇=OFF 'リフト下降
			mSV32_リフト下降=ON 'リフト下降
			errpassXSW17_リフト下降端=OFF
			inc(釜フタ昇降装置Bstep)
		
		case 102
			if tim_procstep.B then
				inc(釜フタ昇降装置Bstep)
			end if		
		
		case 103
			if errpassXSW17_リフト下降端 or ((XSW17_リフト下降端 and not(pnlPBXSW17_リフト下降端)) or passXSW17_リフト下降端) then
				inc(釜フタ昇降装置Bstep)
			end if		
	
		case 104
			釜フタ昇降装置Bstep=110
		
		'--------------------------------------------------------------------------------------------------------------
		'【リフト下降端】
		case 110
			if 釜フタ昇降装置B排出要求=OFF and 搬送コンベアA動作中=OFF  then '搬送コンベアA搬送移動確認
				inc(釜フタ昇降装置Bstep)
			else
				釜フタ昇降装置Bstep=1
			end if
			
		case 111
			if not(PH1_釜検知) and not(PH2_フタ検知) then
				MC11_搬送モータ排出step=1 'MC6を含む
				inc(釜フタ昇降装置Bstep)
			else
				釜フタ昇降装置Bstep=1			
			end if
			
		case 112
			if MC11_搬送モータ排出step=0 then
	 			釜フタ昇降装置B排出要求=ON  '排出要求
				inc(釜フタ昇降装置Bstep)
			end if			

		case 113
			if  not(PH60_釜検知) and not(PH61_フタ検知) then 'リフト上の釜フタなし確認
				StageDevice0=StageDevice52
				StageDevice52=0
				釜フタ昇降装置Bstep=200
			end if

		'--------------------------------------------------------------------------------------------------------------
		'[リフト上昇]
		case 200 'リフト手前位置のワーク搬送
			if not(mSV20_リフト上昇) then
				tim_procstep_val=40
				res(tim_procstep)
			end if
		
			mSV20_リフト上昇=ON '上昇
			mSV32_リフト下降=OFF '上昇
			errpassXSW18_リフト上昇端=OFF
			inc(釜フタ昇降装置Bstep)

		case 201
			if tim_procstep.B then
				inc(釜フタ昇降装置Bstep)
			end if
		
		case 202
			if errpassXSW18_リフト上昇端 or ((XSW18_リフト上昇端 and not(pnlPBXSW18_リフト上昇端)) or passXSW18_リフト上昇端) then
				inc(釜フタ昇降装置Bstep)
			end if
			
		case 203
			if 釜反転出口動作中=OFF and 釜反転出口排出要求 then	
				釜フタ昇降装置Bstep=210
			else
				釜フタ昇降装置Bstep=1
			end if
			
		'--------------------------------------------------------------------------------------------------------------
		'【リフト上昇端】
		case 210
			if PH65_釜検知 or PH66_フタ検知 then
				if PH65_釜検知 and PH66_フタ検知 then
					釜搬送中=ON
				else
					釜搬送中=OFF
				end if
								
				inc(釜フタ昇降装置Bstep)
			else
				釜フタ昇降装置Bstep=1
			end if
		
		case 211
			if errpassXSW18_リフト上昇端 or ((XSW18_リフト上昇端 and not(pnlPBXSW18_リフト上昇端)) or passXSW18_リフト上昇端) then
				MC38_搬送モータstep=1
				MC11_搬送モータstep=1
				inc(釜フタ昇降装置Bstep)
			end if
		
		case 212
			if MC38_搬送モータstep=0 and MC11_搬送モータstep=0 then
				StageDevice52=StageDevice51
				StageDevice51=0
				inc(釜フタ昇降装置Bstep)
			end if

		case 213
			釜反転出口排出要求=OFF
			釜フタ昇降装置B動作中=OFF
			釜フタ昇降装置Bstep=1

		end select
	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 

		釜フタ昇降装置BAutoRun=OFF	
		釜フタ昇降装置Bstep=0 '終了
		
		if ldp(pnlPBSV20_リフト上昇) then
			if mSV20_リフト上昇 then
				mSV20_リフト上昇=OFF
				mSV32_リフト下降=ON
				
			else if not(mMC11_搬送モータ) then
				mSV20_リフト上昇=ON
				mSV32_リフト下降=OFF
			end if
		end if
				
		if ldp(pnlPBMC11_搬送モータ) then
			if mMC11_搬送モータ then
				mMC11_搬送モータ=OFF
			else if ((XSW17_リフト下降端 and not(pnlPBXSW17_リフト下降端)) or passXSW17_リフト下降端) or ((XSW18_リフト上昇端 and not(pnlPBXSW18_リフト上昇端))  or passXSW18_リフト上昇端) then
				mMC11_搬送モータ=ON
			end if
		end if
		
	end if '釜フタ昇降装置BAutoMode and not(釜フタ昇降装置BOrgErrStep)

	'===================================================================================================================
	'【 釜フタ昇降装置BOrgErr処理 】
	else
		res(tim_XSW18_リフト上昇端)
		res(tim_XSW17_リフト下降端)

		if ResetFlg then
			釜フタ昇降装置BOrgErr=OFF
		end if		

	end if

	'===================================================================================================================
	'【タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
		res(tim_XSW18_リフト上昇端)
		res(tim_XSW17_リフト下降端)
		res(tim_notXSW18_リフト上昇端)
		res(tim_notXSW17_リフト下降端)

		釜フタ昇降装置BErr=ON

		釜フタ昇降装置BAutoRun=OFF	
		釜フタ昇降装置Bstep=0 '終了

		select case 釜フタ昇降装置BErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW18_リフト上昇端=OFF
				almXSW17_リフト下降端=OFF
				
				inc(釜フタ昇降装置BErrStep)
			end if
		case 2
			釜フタ昇降装置BErr=OFF
			釜フタ昇降装置BErrStep=0
		end select

	end if 'if 釜フタ昇降装置BErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case 釜フタ昇降装置BEmgStep
	case 0
		
	case 1
		釜フタ昇降装置BAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (釜フタ昇降装置BAutoMode and 自動搬送AutoMode ) or 釜フタ昇降装置Bstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseMC38_搬送モータ=ON
			pauseMC11_搬送モータ=ON
			pauseMC6_搬送モータ=ON
		
			if timstack=OFF then
				timdly_PH1_釜検知_stack=timdly_PH1_釜検知.U
				timdly_PH2_フタ検知_stack=timdly_PH2_フタ検知.U
				timdly_PH60_釜検知_stack=timdly_PH60_釜検知.U
				timdly_PH61_フタ検知_stack=timdly_PH61_フタ検知.U
				timnotdly_PH60_釜検知_stack=timnotdly_PH60_釜検知.U
				timnotdly_PH61_フタ検知_stack=timnotdly_PH61_フタ検知.U
				tim_procstep_stack=tim_procstep.U
				tim_MC11_搬送モータ_stack=tim_MC11_搬送モータ.U
				tim_MC11_搬送モータ排出_stack=tim_MC11_搬送モータ排出.U
				tim_MC38_搬送モータ_stack=tim_MC38_搬送モータ.U
				tim_MC38_搬送モータ待機_stack=tim_MC38_搬送モータ待機.U
				
				timstack=ON
			end if

			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mSV20_リフト上昇=OFF
			mSV32_リフト下降=OFF
			mMC11_搬送モータ=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(釜フタ昇降装置BEmgStep)
	case 2
		if ResetFlg then
			inc(釜フタ昇降装置BEmgStep)
		end if
	case 3
		if (釜フタ昇降装置BAutoMode and 自動搬送AutoMode ) or 釜フタ昇降装置Bstep<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseMC38_搬送モータ=OFF
				pauseMC11_搬送モータ=OFF
				pauseMC6_搬送モータ=OFF
				
				tim_procstep.U=tim_procstep_stack
				tim_MC11_搬送モータ.U=tim_MC11_搬送モータ_stack
				tim_MC11_搬送モータ排出.U=tim_MC11_搬送モータ排出_stack
				tim_MC38_搬送モータ.U=tim_MC38_搬送モータ_stack
				tim_MC38_搬送モータ待機.U=tim_MC38_搬送モータ待機_stack

				res(timdly_PH1_釜検知)
				res(timdly_PH2_フタ検知)
				res(timdly_PH60_釜検知)
				res(timdly_PH61_フタ検知)
				res(timnotdly_PH60_釜検知)
				res(timnotdly_PH61_フタ検知)

				'---------------------------------
				inc(釜フタ昇降装置BEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(釜フタ昇降装置BEmgStep)		
		end if				
	case 4
		timstack=OFF
		釜フタ昇降装置BEmgStep=0
		釜フタ昇降装置BEmg=OFF
	end select
		
end if 'if 釜フタ昇降装置BEmgStep=0 then
