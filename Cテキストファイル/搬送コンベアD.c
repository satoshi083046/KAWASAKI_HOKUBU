'搬送コンベアD
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	搬送コンベアD
'
'  	移動速度  161.667mm/1sec
'
'11	SV28_リフト		XSW34_リフト上昇端		PH22_釜検知
'					XSW35_リフト下降端	
'	SV29_ストッパ	XSW37_ストッパ上昇端	
'					XSW36_ストッパ下降端	
'	MC34_モータローラ
'	MC44_モータローラ
'	MC46_モータローラ
'			
'12	SV43_リフト		XSW53_リフト上昇端		PH24_釜検知
'					XSW54_リフト下降端	
'	SV42_ストッパ	XSW51_ストッパ上昇端	
'					XSW52_ストッパ下降端	
'			
'			
'===================================================================================================================

'【 初期化処理 】
if CR2008 then '電源ON時初期化処理

	搬送コンベアDAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    搬送コンベアDAutoRun=OFF
    搬送コンベアD許可=ON
    搬送コンベアDOrgErr=OFF
    搬送コンベアDErr=OFF
    搬送コンベアDEmg=OFF
    搬送コンベアDstep=0
    搬送コンベアDErrStep=0
    搬送コンベアDOrgErrStep=0
    搬送コンベアDEmgStep=0
	
	MC34_モータローラstep=0
	MC44_モータローラstep=0
	MC46_モータローラstep=0

	if SSW3_自動モード then	
		ManualInite=1
	else
		ManualInite=0	
	end if
	
	
end if

'===================================================================================================================
'【 原点 】
搬送コンベアDOrg=((XSW53_リフト上昇端 and not(pnlPBXSW53_リフト上昇端)) or passXSW53_リフト上昇端) or ((XSW54_リフト下降端 and not(pnlPBXSW54_リフト下降端)) or passXSW54_リフト下降端)
搬送コンベアDOrg= 搬送コンベアDOrg and ( ((XSW51_ストッパ上昇端 and not(pnlPBXSW51_ストッパ上昇端)) or passXSW51_ストッパ上昇端) or ((XSW52_ストッパ下降端 and not(pnlPBXSW52_ストッパ下降端)) or passXSW52_ストッパ下降端) )

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	搬送コンベアDEmg=ON
	搬送コンベアDEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
tmr(SV29_ストッパ and not(XSW37_ストッパ上昇端) and not(pnlPBXSW37_ストッパ上昇端),tim_notXSW37_ストッパ上昇端,#30)
tmr(not(SV29_ストッパ) and not(XSW36_ストッパ下降端) and not(pnlPBXSW36_ストッパ下降端),tim_notXSW36_ストッパ下降端,#30)
tmr(SV28_リフト and not(XSW34_リフト上昇端) and not(pnlPBXSW34_リフト上昇端) ,tim_notXSW34_リフト上昇端,#30)
tmr(not(SV28_リフト) and not(XSW35_リフト下降端) and not(pnlPBXSW35_リフト下降端) ,tim_notXSW35_リフト下降端,#30)
tmr(SV42_ストッパ and not(XSW51_ストッパ上昇端) and not(pnlPBXSW51_ストッパ上昇端), tim_notXSW51_ストッパ上昇端,#30)
tmr(not(SV42_ストッパ) and not(XSW52_ストッパ下降端) and not(pnlPBXSW52_ストッパ下降端),tim_notXSW52_ストッパ下降端,#30)
tmr(SV43_リフト and not(XSW53_リフト上昇端) and not(pnlPBXSW53_リフト上昇端), tim_notXSW53_リフト上昇端, #30) 
tmr(not(SV43_リフト) and not(XSW54_リフト下降端) and not(pnlPBXSW54_リフト下降端),tim_notXSW54_リフト下降端,#30)

'tmr(not(SV29_ストッパ) and XSW37_ストッパ上昇端 and not(pnlPBXSW37_ストッパ上昇端),tim_XSW37_ストッパ上昇端,#10)
if LDP(SV29_ストッパ) and XSW37_ストッパ上昇端 and not(pnlPBXSW37_ストッパ上昇端) then
	SET(tim_XSW37_ストッパ上昇端)
end if
'tmr(SV29_ストッパ and XSW36_ストッパ下降端 and not(pnlPBXSW36_ストッパ下降端),tim_XSW36_ストッパ下降端,#10)
if LDF(SV29_ストッパ) and XSW36_ストッパ下降端 and not(pnlPBXSW36_ストッパ下降端) and not(pauseSV29_ストッパ) then
	SET(tim_XSW36_ストッパ下降端)
end if
'tmr(not(SV28_リフト) and XSW34_リフト上昇端 and not(pnlPBXSW34_リフト上昇端) ,tim_XSW34_リフト上昇端,#10)
if LDP(SV28_リフト) and XSW34_リフト上昇端 and not(pnlPBXSW34_リフト上昇端) then
	SET(tim_XSW34_リフト上昇端)
end if
'tmr(SV28_リフト and XSW35_リフト下降端 and not(pnlPBXSW35_リフト下降端) ,tim_XSW35_リフト下降端,#10)
if LDF(SV28_リフト) and XSW35_リフト下降端 and not(pnlPBXSW35_リフト下降端) and not(pauseSV28_リフト) then
	SET(tim_XSW35_リフト下降端)
end if
'tmr(not(SV42_ストッパ) and XSW51_ストッパ上昇端 and not(pnlPBXSW51_ストッパ上昇端), tim_XSW51_ストッパ上昇端,#10)
if LDP(SV42_ストッパ) and XSW51_ストッパ上昇端 and not(pnlPBXSW51_ストッパ上昇端) then
	SET(tim_XSW51_ストッパ上昇端)
end if
'tmr(SV42_ストッパ and XSW52_ストッパ下降端 and not(pnlPBXSW52_ストッパ下降端),tim_XSW52_ストッパ下降端,#10)
if LDF(SV42_ストッパ) and XSW52_ストッパ下降端 and not(pnlPBXSW52_ストッパ下降端) and not(pauseSV42_ストッパ) then
	SET(tim_XSW52_ストッパ下降端)
end if
'tmr(not(SV43_リフト) and XSW53_リフト上昇端 and not(pnlPBXSW53_リフト上昇端), tim_XSW53_リフト上昇端, #10) 
if LDP(SV43_リフト) and XSW53_リフト上昇端 and not(pnlPBXSW53_リフト上昇端) then
	SET(tim_XSW53_リフト上昇端)
end if
'tmr(SV43_リフト and XSW54_リフト下降端 and not(pnlPBXSW54_リフト下降端),tim_XSW54_リフト下降端,#10)
if LDF(SV43_リフト) and XSW54_リフト下降端 and not(pnlPBXSW54_リフト下降端) and not(pauseSV43_リフト) then
	SET(tim_XSW54_リフト下降端)
end if

'tms(SV29_ストッパ,passtimXSW37_ストッパ上昇端,passtimXSW37_ストッパ上昇端_val)
'tms(not(SV29_ストッパ),passtimXSW36_ストッパ下降端,passtimXSW36_ストッパ下降端_val)
'tms(SV28_リフト,passtimXSW34_リフト上昇端,passtimXSW34_リフト上昇端_val)
'tms(not(SV28_リフト),passtimXSW35_リフト下降端,passtimXSW35_リフト下降端_val)
tms(SV42_ストッパ,passtimXSW51_ストッパ上昇端,passtimXSW51_ストッパ上昇端_val)
tms(not(SV42_ストッパ),passtimXSW52_ストッパ下降端,passtimXSW52_ストッパ下降端_val)
tms(SV43_リフト,passtimXSW53_リフト上昇端,passtimXSW53_リフト上昇端_val)
tms(not(SV43_リフト),passtimXSW54_リフト下降端,passtimXSW54_リフト下降端_val)

if ldp(tim_XSW51_ストッパ上昇端.B) or ldp(tim_notXSW51_ストッパ上昇端.B) then
	errpassXSW51_ストッパ上昇端=ON
	almXSW51_ストッパ上昇端=ON
	pnlPBXSW51_ストッパ上昇端=ON
	搬送コンベアDErrStep=1

else if ldp(tim_XSW52_ストッパ下降端.B) or ldp(tim_notXSW52_ストッパ下降端.B) then
	errpassXSW52_ストッパ下降端=ON
	almXSW52_ストッパ下降端=ON
	pnlPBXSW52_ストッパ下降端=ON
	搬送コンベアDErrStep=1

else if ldp(tim_XSW37_ストッパ上昇端.B) or ldp(tim_notXSW37_ストッパ上昇端.B) then
	errpassXSW37_ストッパ上昇端=ON
	almXSW37_ストッパ上昇端=ON
	pnlPBXSW37_ストッパ上昇端=ON
	搬送コンベアDErrStep=1

else if ldp(tim_XSW36_ストッパ下降端.B) or ldp(tim_notXSW36_ストッパ下降端.B) then
	errpassXSW36_ストッパ下降端=ON
	almXSW36_ストッパ下降端=ON
	pnlPBXSW36_ストッパ下降端=ON
	搬送コンベアDErrStep=1

else if ldp(tim_XSW53_リフト上昇端.B) or ldp(tim_notXSW53_リフト上昇端.B) then
	errpassXSW53_リフト上昇端=ON
	almXSW53_リフト上昇端=ON
	pnlPBXSW53_リフト上昇端=ON
	搬送コンベアDErrStep=1

else if ldp(tim_XSW54_リフト下降端.B) or ldp(tim_notXSW54_リフト下降端.B) then
	errpassXSW54_リフト下降端=ON
	almXSW54_リフト下降端=ON
	pnlPBXSW54_リフト下降端=ON
	搬送コンベアDErrStep=1

else if ldp(tim_XSW34_リフト上昇端.B) or ldp(tim_notXSW34_リフト上昇端.B) then
	errpassXSW34_リフト上昇端=ON
	almXSW34_リフト上昇端=ON
	pnlPBXSW34_リフト上昇端=ON
	搬送コンベアDErrStep=1

else if ldp(tim_XSW35_リフト下降端.B) or ldp(tim_notXSW35_リフト下降端.B) then
	errpassXSW35_リフト下降端=ON
	almXSW35_リフト下降端=ON
	pnlPBXSW35_リフト下降端=ON
	搬送コンベアDErrStep=1

end if
'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 搬送コンベアDAutoMode	自動モード セレクトスイッチ
'System :: 搬送コンベアDAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 搬送コンベアDEmg	その場停止


if 搬送コンベアDEmgStep=0 then  
	
	if 搬送コンベアDErrStep=0  then

	if not(搬送コンベアDOrgErr) then

	
	tmr(PH24_釜検知,timdly_PH24_釜検知,2)
	
	'-----------------------------------------------------------------
	' 搬送モータ、ストッパON/OFFタイミングタスク
	'-----------------------------------------------------------------
	tmr(tim_MC34_モータローラ,tim_MC34_モータローラ_val)
	select case MC34_モータローラstep
	case 0
	case 1
		if  PH22_釜起動検知  then
			mSV28_リフト=ON
			errpassXSW34_リフト上昇端=OFF

			mSV29_ストッパ=OFF
			errpassXSW36_ストッパ下降端=OFF
			
			inc(MC34_モータローラstep)
		else
			MC34_モータローラstep=0
		end if
	
	case 2
		if errpassXSW34_リフト上昇端 or ((XSW34_リフト上昇端 and not(pnlPBXSW34_リフト上昇端)) or passXSW34_リフト上昇端) then
			inc(MC34_モータローラstep)
		end if
		
	case 3
		if errpassXSW36_ストッパ下降端 or ((XSW36_ストッパ下降端 or not(pnlPBXSW36_ストッパ下降端)) or passXSW36_ストッパ下降端) then
			inc(MC34_モータローラstep)
		end if

	case 4
		mMC34_モータローラ=ON
		inc(MC34_モータローラstep)

	case 5
		if not(PH22_釜検知) then
			inc(MC34_モータローラstep)
		end if
	
	case 6
		if  PH22_釜起動検知  then
			if (PH24_釜検知 and timdly_PH24_釜検知.B) then
				inc(MC34_モータローラstep)
			end if
		end if
	
	case 7
		mMC34_モータローラ=OFF
		inc(MC34_モータローラstep)
	
	case 8
		tim_MC34_モータローラ_val=0
		res(tim_MC34_モータローラ)
		inc(MC34_モータローラstep)
	
	case 9
		if tim_MC34_モータローラ.B then
			inc(MC34_モータローラstep)
		end if
	
	case 10
		mSV28_リフト=OFF
		errpassXSW35_リフト下降端=OFF
		inc(MC34_モータローラstep)
	
	case 11
		if errpassXSW35_リフト下降端 or ((XSW35_リフト下降端 and not(pnlPBXSW35_リフト下降端)) or passXSW35_リフト下降端) then
			inc(MC34_モータローラstep)
		end if		
	
	case 12
		mSV29_ストッパ=ON
		errpassXSW37_ストッパ上昇端=OFF
		inc(MC34_モータローラstep)
	
	case 13
		if errpassXSW37_ストッパ上昇端 or ((XSW37_ストッパ上昇端 and not(pnlPBXSW37_ストッパ上昇端)) or passXSW37_ストッパ上昇端) then
			inc(MC34_モータローラstep)
		end if
		
	case 14
		搬送コンベアC2排出要求=OFF
		搬送コンベアD動作中=OFF
		MC34_モータローラstep=0
	end select
	
	
	'-----------------------------------------------------------------
	'MC44_モータローラ
	tmr(tim_MC44_モータローラ,tim_MC44_モータローラ_val)
	select case MC44_モータローラstep
	case 0
	case 1
		if  PH22_釜起動検知  then
				mMC44_モータローラ=ON		
				inc(MC44_モータローラstep)
		else
			MC44_モータローラstep=0
		end if
	

	case 2
		if  PH22_釜起動検知  then
			if (PH24_釜検知 and timdly_PH24_釜検知.B) then
				inc(MC44_モータローラstep)
			end if
		end if
	
	case 3
		tim_MC44_モータローラ_val=10
		res(tim_MC44_モータローラ)
		inc(MC44_モータローラstep)
	
	case 4
		if tim_MC44_モータローラ.B then
			inc(MC44_モータローラstep)
		end if

	
	case 5
		mMC44_モータローラ=OFF
		inc(MC44_モータローラstep)
	
	case 6
		tim_MC44_モータローラ_val=0
		res(tim_MC44_モータローラ)
		inc(MC44_モータローラstep)
	
	case 7
		if tim_MC44_モータローラ.B then
			inc(MC44_モータローラstep)
		end if
	
	case 8
		MC44_モータローラstep=0

	end select

	'--------------------------------------------
	tmr(tim_MC46_モータローラ,tim_MC46_モータローラ_val)
	select case MC46_モータローラstep
	case 0
	case 1
		if  PH22_釜起動検知  then
			mSV43_リフト=ON
			errpassXSW53_リフト上昇端=OFF
			mSV42_ストッパ=ON
			errpassXSW51_ストッパ上昇端=OFF
			inc(MC46_モータローラstep)
		else
			MC46_モータローラstep=0
		end if
		
	
	case 2
		if (errpassXSW53_リフト上昇端 or ((XSW53_リフト上昇端 and not(pnlPBXSW53_リフト上昇端)) or passXSW53_リフト上昇端)) and (errpassXSW51_ストッパ上昇端 or ((XSW51_ストッパ上昇端 and not(pnlPBXSW51_ストッパ上昇端)) or passXSW51_ストッパ上昇端)) then
			inc(MC46_モータローラstep)
		end if

	case 3
		mMC46_モータローラ=ON
		inc(MC46_モータローラstep)
	
	case 4
		if not(PH22_釜検知) then
			inc(MC46_モータローラstep)
		end if
	
	case 5
		if  PH22_釜起動検知  then
			if (PH24_釜検知 and timdly_PH24_釜検知.B) then
				inc(MC46_モータローラstep)
			end if
		end if
	
	case 6
		tim_MC46_モータローラ_val=10
		res(tim_MC46_モータローラ)
		inc(MC46_モータローラstep)
	
	case 7
		if tim_MC46_モータローラ.B then
			inc(MC46_モータローラstep)
		end if

	
	case 8
		mMC46_モータローラ=OFF
		inc(MC46_モータローラstep)
	
	case 9
		tim_MC46_モータローラ_val=0
		res(tim_MC46_モータローラ)
		inc(MC46_モータローラstep)
	
	case 10
		if tim_MC46_モータローラ.B then
			inc(MC46_モータローラstep)
		end if
	
	case 11
		搬送コンベアD排出要求=ON
		MC46_モータローラstep=0
	end select
	'-----------------------------------------------------------------

	'===================================================================================================================
	'【 リフタータスク 】
	'
	if (搬送コンベアDAutoMode and 自動搬送AutoMode ) or 搬送コンベアDstep<>0 then
	
		if ManualInite=1 then
			mSV42_ストッパ=ON
			mSV29_ストッパ=ON
			ManualInite=0
		end if
		
		if not(搬送コンベアDAutoMode and 自動搬送AutoMode ) then
			搬送コンベアDAutoRun=OFF
		end if

		tmr(tim_procstep,tim_procstep_val)

		select case 搬送コンベアDstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 搬送コンベアDAutoRun then
				inc(搬送コンベアDstep)
			else 
				搬送コンベアDstep=0 '終了待機
			end if
		
		case 2
			if PH24_釜検知 then
				搬送コンベアD動作中=OFF
				搬送コンベアD排出要求=ON
				搬送コンベアDstep=1
			else
				inc(搬送コンベアDstep)
			end if
		
		case 3
		' [ 次の搬送コンベア停止確認 ]
			if 搬送コンベアD排出要求=OFF and  搬送コンベアE動作中=OFF and 搬送コンベアC2排出要求 then
				搬送コンベアD動作中=ON
				搬送コンベアDstep=100
			else
				搬送コンベアDstep=1
			end if
			
		case 4  '原点検出
			if 搬送コンベアDOrg then				
				inc(搬送コンベアDstep)
			else
				搬送コンベアDstep=1
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		case 100
			if 搬送コンベアDOrg or 1 then
				inc(搬送コンベアDstep)
			else
				搬送コンベアDOrgErr=ON
			end if

		
		case 101
			LatchPH22_釜検知=OFF
			inc(搬送コンベアDstep)

		case 102
			PH22_釜起動検知=LatchPH22_釜検知
			
			MC34_モータローラstep=1
			MC44_モータローラstep=1
			MC46_モータローラstep=1
			
			inc(搬送コンベアDstep)


		case 103
			if 	MC34_モータローラstep=0 and MC44_モータローラstep=0 and MC46_モータローラstep=0 then
				inc(搬送コンベアDstep)
			end if
			
		case 104
			StageDevice12=StageDevice11
			StageItem12=ANDA(StageDevice12.U,$00FF)  
			StageItem11=ANDA(StageDevice11.U,$00FF)  
			inc(搬送コンベアDstep)
		
		case 105
			IHA挿入優先=ON
			搬送コンベアD動作中=OFF
			搬送コンベアDstep=1

	 end select
	 
	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		if ManualInite=0 then
			mSV42_ストッパ=OFF
			mSV29_ストッパ=OFF
			ManualInite=1
		end if
	
		搬送コンベアDAutoRun=OFF
		
		搬送コンベアDstep=0 '終了

		res(tim_notXSW51_ストッパ上昇端)
		res(tim_notXSW52_ストッパ下降端)
		res(tim_notXSW37_ストッパ上昇端)
		res(tim_notXSW36_ストッパ下降端)
		res(tim_notXSW53_リフト上昇端)
		res(tim_notXSW54_リフト下降端)
		res(tim_notXSW34_リフト上昇端)
		res(tim_notXSW35_リフト下降端)

		res(tim_XSW51_ストッパ上昇端)
		res(tim_XSW52_ストッパ下降端)
		res(tim_XSW37_ストッパ上昇端)
		res(tim_XSW36_ストッパ下降端)
		res(tim_XSW53_リフト上昇端)
		res(tim_XSW54_リフト下降端)
		res(tim_XSW34_リフト上昇端)
		res(tim_XSW35_リフト下降端)
		
		if ldp(pnlPBMC34_モータローラ) then
			if mMC34_モータローラ then
				mMC34_モータローラ=OFF
			else
					mMC34_モータローラ=ON
			end if
		end if
		
		if ldp(pnlPBMC44_モータローラ) then
			if mMC44_モータローラ then
				mMC44_モータローラ=OFF
			else
				mMC44_モータローラ=ON
			end if
		end if
		
		if ldp(pnlPBMC46_モータローラ) then
			if mMC46_モータローラ then
				mMC46_モータローラ=OFF
			else
				mMC46_モータローラ=ON
			end if
		end if

	end if '搬送コンベアDAutoMode and not(搬送コンベアDOrgErrStep)

	'===================================================================================================================
	'【 搬送コンベアDOrgErr処理 】
	else
	
		res(tim_notXSW51_ストッパ上昇端)
		res(tim_notXSW52_ストッパ下降端)
		res(tim_notXSW37_ストッパ上昇端)
		res(tim_notXSW36_ストッパ下降端)
		res(tim_notXSW53_リフト上昇端)
		res(tim_notXSW54_リフト下降端)
		res(tim_notXSW34_リフト上昇端)
		res(tim_notXSW35_リフト下降端)

		res(tim_XSW51_ストッパ上昇端)
		res(tim_XSW52_ストッパ下降端)
		res(tim_XSW37_ストッパ上昇端)
		res(tim_XSW36_ストッパ下降端)
		res(tim_XSW53_リフト上昇端)
		res(tim_XSW54_リフト下降端)

		if ResetFlg then
			搬送コンベアDOrgErr=OFF
		end if

	end if

	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else

		搬送コンベアDErr=ON

		pauseMC34_モータローラ=ON
		pauseMC44_モータローラ=ON
		pauseMC46_モータローラ=ON

		select case 搬送コンベアDErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW51_ストッパ上昇端=OFF
				almXSW52_ストッパ下降端=OFF
				almXSW37_ストッパ上昇端=OFF
				almXSW36_ストッパ下降端=OFF
				almXSW53_リフト上昇端=OFF
				almXSW54_リフト下降端=OFF
				almXSW34_リフト上昇端=OFF
				almXSW35_リフト下降端=OFF

				inc(搬送コンベアDErrStep)
			end if
		case 2
			搬送コンベアDErr=OFF

			res(tim_notXSW51_ストッパ上昇端)
			res(tim_notXSW52_ストッパ下降端)
			res(tim_notXSW37_ストッパ上昇端)
			res(tim_notXSW36_ストッパ下降端)
			res(tim_notXSW53_リフト上昇端)
			res(tim_notXSW54_リフト下降端)
			res(tim_notXSW34_リフト上昇端)
			res(tim_notXSW35_リフト下降端)

			res(tim_XSW51_ストッパ上昇端)
			res(tim_XSW52_ストッパ下降端)
			res(tim_XSW37_ストッパ上昇端)
			res(tim_XSW36_ストッパ下降端)
			res(tim_XSW53_リフト上昇端)
			res(tim_XSW54_リフト下降端)
			res(tim_XSW34_リフト上昇端)
			res(tim_XSW35_リフト下降端)

			pauseMC34_モータローラ=OFF
			pauseMC44_モータローラ=OFF
			pauseMC46_モータローラ=OFF
			

			搬送コンベアDErrStep=0
		end select

	end if 'if 搬送コンベアDErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else

	select case 搬送コンベアDEmgStep
	case 0
		
	case 1
		搬送コンベアDAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (搬送コンベアDAutoMode and 自動搬送AutoMode ) or 搬送コンベアDstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseMC34_モータローラ=ON
			pauseMC44_モータローラ=ON
			pauseMC46_モータローラ=ON

			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				tim_MC44_モータローラ_stack=tim_MC44_モータローラ.U
				tim_SV43_リフト_stack=tim_SV43_リフト.U
				tim_SV29_ストッパ_stack=tim_SV29_ストッパ.U
				tim_MC46_モータローラ_stack=tim_MC46_モータローラ.U
				tim_MC34_モータローラ_stack=tim_MC34_モータローラ.U
				tim_SV42_ストッパ_stack=tim_SV42_ストッパ.U
				tim_SV28_リフト_stack=tim_SV28_リフト.U
			
				timdly_PH22_釜検知_stack=timdly_PH22_釜検知.U
				timdly_PH24_釜検知_stack=timdly_PH24_釜検知.U
				timstack=ON
			end if
			
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC34_モータローラ=OFF
			mMC44_モータローラ=OFF
			mMC46_モータローラ=OFF
		
			'---------------------------------
		end if
		
		'---------------------------------
		inc(搬送コンベアDEmgStep)
	case 2
		if ResetFlg then
			inc(搬送コンベアDEmgStep)
		end if
	case 3
		if (搬送コンベアDAutoMode and 自動搬送AutoMode ) or 搬送コンベアDstep<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseMC34_モータローラ=OFF
				pauseMC44_モータローラ=OFF
				pauseMC46_モータローラ=OFF

				tim_procstep.U=tim_procstep_stack
				tim_MC44_モータローラ.U=tim_MC44_モータローラ_stack
				tim_SV43_リフト.U=tim_SV43_リフト_stack
				tim_SV29_ストッパ.U=tim_SV29_ストッパ_stack
				tim_MC46_モータローラ.U=tim_MC46_モータローラ_stack
				tim_MC34_モータローラ.U=tim_MC34_モータローラ_stack
				tim_SV42_ストッパ.U=tim_SV42_ストッパ_stack
				tim_SV28_リフト.U=tim_SV28_リフト_stack			

				res(timdly_PH22_釜検知)
				res(timdly_PH24_釜検知)
				'---------------------------------
				inc(搬送コンベアDEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(搬送コンベアDEmgStep)		
		end if				
	case 4
		timstack=OFF
		搬送コンベアDEmgStep=0
		搬送コンベアDEmg=OFF
	end select
		
end if 'if 搬送コンベアDEmgStep=0 then
