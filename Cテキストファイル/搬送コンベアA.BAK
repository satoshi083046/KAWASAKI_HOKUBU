'搬送コンベアA
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	搬送コンベアA
'
'  	移動速度  161.667mm/1sec
'
' (MC6_搬送モータ) -> (MC6_搬送モータ)
' [ 0 ]
' PH50_釜検知 	->	PH1_釜検知
' PH51_フタ検知 ->	PH2_フタ検知
' [ 1 ]
' PH1_釜検知 	->	PH3_釜検知
' PH2_フタ検知 	->	PH4_フタ検知
' SV14_ストッパ 		-> SV14_ストッパ上昇	
' not(SV14_ストッパ) 	-> 	
' XSW12_ストッパ上昇端	-> XSW14_ストッパ上昇端
' XSW11_ストッパ下降端	-> XSW15_ストッパ下降端
'
' (MC7_搬送モータ) -> (MC7_搬送モータ)
' [ 2 ]
' PH3_釜検知 	->	PH5_釜検知
' PH4_フタ検知 	->	PH6_フタ検知
' SV15_ストッパ 		-> SV64_ストッパ上昇
' not(SV15_ストッパ) 	-> 
' XSW14_ストッパ上昇端	-> XSW16_ストッパ上昇端
' XSW13_ストッパ下降端	-> XSW17_ストッパ下降端
'
' (MC8_搬送モータ) -> (MC8_搬送モータ)
' [ 3 ]
' PH52_釜検知 	->	PH7_釜検知
' PH53_フタ検知 ->	PH8_フタ検知

' (MC9_モータローラ) -> (MC9_モータローラ)
' [ 4 ]
' PH5_釜検知 ->	PH9_釜検知
' PH6_フタ検知 ->	PH10_釜検知
' SV16_リフト		->	SV21_リフト	
' XSW16_リフト上昇端 ->	XSW21_リフト上昇端
' XSW15_リフト下降端 ->	XSW20_リフト下降端
' (		新規	)	->	SV51ストッパ
' (		新規	)	->	XSW18_ストッパ上昇端
' (		新規	)	->	XSW19_ストッパ下降端
'
'===================================================================================================================
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理

    搬送コンベアAAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    搬送コンベアAAutoRun=OFF
    搬送コンベアA許可=ON
    搬送コンベアAOrgErr=OFF
    搬送コンベアAErr=OFF
    搬送コンベアAEmg=OFF
    搬送コンベアAstep=0
    搬送コンベアAErrStep=0
    搬送コンベアAOrgErrStep=0
    搬送コンベアAEmgStep=0
	
	SV14_ストッパ上昇step=0
	SV64_ストッパ上昇step=0
	MC6_搬送モータstep=0
	MC7_搬送モータstep=0
	MC8_搬送モータ供給step=0
	MC8_搬送モータ排出step=0
	MC9_モータローラstep=0
	
	
	if SSW3_自動モード  then	
		ManualInite=1
	else
		ManualInite=0	
	end if

end if

'===================================================================================================================
'【 原点 】
搬送コンベアAOrg=((XSW14_ストッパ上昇端 and not(pnlPBXSW14_ストッパ上昇端)) or passXSW14_ストッパ上昇端) or ((XSW15_ストッパ下降端 and not(pnlPBXSW15_ストッパ下降端)) or passXSW15_ストッパ下降端) 
搬送コンベアAOrg=搬送コンベアAOrg and ( ((XSW16_ストッパ上昇端 and not(pnlPBXSW16_ストッパ上昇端)) or passXSW16_ストッパ上昇端) or ((XSW17_ストッパ下降端 and not(pnlPBXSW17_ストッパ下降端)) or passXSW17_ストッパ下降端))

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	搬送コンベアAEmg=ON
	搬送コンベアAEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
tmr(SV14_ストッパ上昇 and not(XSW14_ストッパ上昇端) and not(pnlPBXSW14_ストッパ上昇端), tim_notXSW14_ストッパ上昇端,#30)
tmr(not(SV14_ストッパ上昇) and not(XSW15_ストッパ下降端) and not(pnlPBXSW15_ストッパ下降端), tim_notXSW15_ストッパ下降端,#30)
tmr(SV64_ストッパ上昇 and not(XSW16_ストッパ上昇端) and not(pnlPBXSW16_ストッパ上昇端),tim_notXSW16_ストッパ上昇端,#30)
tmr(not(SV64_ストッパ上昇) and not(XSW17_ストッパ下降端) and not(pnlPBXSW17_ストッパ下降端) ,tim_notXSW17_ストッパ下降端,#30)
tmr(SV21_リフト and not(XSW21_リフト上昇端) and not(pnlPBXSW21_リフト上昇端) ,tim_notXSW21_リフト上昇端,#30)
tmr(not(SV21_リフト) and not(XSW20_リフト下降端) and not(pnlPBXSW20_リフト下降端) ,tim_notXSW20_リフト下降端,#30)
tmr(SV51_ストッパ and not(XSW18_ストッパ上昇端) and not(pnlPBXSW18_ストッパ上昇端),tim_notXSW18_ストッパ上昇端,#30)
tmr(not(SV51_ストッパ) and not(XSW19_ストッパ下降端) and not(pnlPBXSW19_ストッパ下降端),tim_notXSW19_ストッパ下降端,#30)

'tmr(not(SV14_ストッパ上昇) and XSW14_ストッパ上昇端 and not(pnlPBXSW14_ストッパ上昇端), tim_XSW14_ストッパ上昇端,#20)
if LDP(SV14_ストッパ上昇) and XSW14_ストッパ上昇端 and not(pnlPBXSW14_ストッパ上昇端) then
	SET(tim_XSW14_ストッパ上昇端)
end if
'tmr(SV14_ストッパ上昇 and XSW15_ストッパ下降端 and not(pnlPBXSW15_ストッパ下降端), tim_XSW15_ストッパ下降端,#20)
if LDF(SV14_ストッパ上昇)  and XSW15_ストッパ下降端 and not(pnlPBXSW15_ストッパ下降端) and not(pauseSV14_ストッパ上昇) then
	SET(tim_XSW15_ストッパ下降端)
end if
'tmr(not(SV64_ストッパ上昇) and XSW16_ストッパ上昇端 and not(pnlPBXSW16_ストッパ上昇端),tim_XSW16_ストッパ上昇端,#20)
if LDP(SV64_ストッパ上昇) and XSW16_ストッパ上昇端 and not(pnlPBXSW16_ストッパ上昇端) then
	SET(tim_XSW16_ストッパ上昇端)
end if
'tmr(SV64_ストッパ上昇 and XSW17_ストッパ下降端 and not(pnlPBXSW17_ストッパ下降端) ,tim_XSW17_ストッパ下降端,#20)
if LDF(SV64_ストッパ上昇) and XSW17_ストッパ下降端 and not(pnlPBXSW17_ストッパ下降端) and not(pauseSV64_ストッパ上昇) then
	SET(tim_XSW17_ストッパ下降端)
end if
'tmr(not(SV21_リフト) and XSW21_リフト上昇端 and not(pnlPBXSW21_リフト上昇端) ,tim_XSW21_リフト上昇端,#20)
if LDP(SV21_リフト) and XSW21_リフト上昇端 and not(pnlPBXSW21_リフト上昇端) then
	SET(tim_XSW21_リフト上昇端)
end if
'tmr(SV21_リフト and XSW20_リフト下降端 and not(pnlPBXSW20_リフト下降端) ,tim_XSW20_リフト下降端,#20)
if LDF(SV21_リフト) and XSW20_リフト下降端 and not(pnlPBXSW20_リフト下降端) and not(pauseSV21_リフト) then
	SET(tim_XSW20_リフト下降端)
end if
'tmr(not(SV51_ストッパ) and XSW18_ストッパ上昇端 and not(pnlPBXSW18_ストッパ上昇端),tim_XSW18_ストッパ上昇端,#20)
if LDP(SV51_ストッパ) and XSW18_ストッパ上昇端 and not(pnlPBXSW18_ストッパ上昇端) then
	SET(tim_XSW18_ストッパ上昇端)
end if
'tmr(SV51_ストッパ and XSW19_ストッパ下降端 and not(pnlPBXSW19_ストッパ下降端),tim_XSW19_ストッパ下降端,#20)
if LDF(SV51_ストッパ) and XSW19_ストッパ下降端 and not(pnlPBXSW19_ストッパ下降端) and not(pauseSV51_ストッパ) then
	SET(tim_XSW19_ストッパ下降端)
end if

tms(SV14_ストッパ上昇,passtimXSW14_ストッパ上昇端,passtimXSW14_ストッパ上昇端_val)
tms(not(SV14_ストッパ上昇),passtimXSW15_ストッパ下降端,passtimXSW15_ストッパ下降端_val)
tms(SV64_ストッパ上昇,passtimXSW16_ストッパ上昇端,passtimXSW16_ストッパ上昇端_val)
tms(not(SV64_ストッパ上昇),passtimXSW17_ストッパ下降端,passtimXSW17_ストッパ下降端_val)
tms(SV21_リフト,passtimXSW21_リフト上昇端,passtimXSW21_リフト上昇端_val)
tms(not(SV21_リフト),passtimXSW20_リフト下降端,passtimXSW20_リフト下降端_val)
tms(SV51_ストッパ,passtimXSW18_ストッパ上昇端,passtimXSW18_ストッパ上昇端_val)
tms(not(SV51_ストッパ),passtimXSW19_ストッパ下降端,passtimXSW19_ストッパ下降端_val)


tmr(搬送コンベアAAutoRun and (PBL8_水切りシャッターA or PBL12_水切りシャッターB),tim_配米シャッターErr,#200)

if 	almXSW4_水切りシャッター閉A or almXSW8_水切りシャッター閉B then

	if ResetFlg then
		almXSW4_水切りシャッター閉A=OFF
		almXSW8_水切りシャッター閉B=OFF
	end if
	
end if

tmr(MC6_搬送モータ,timerr_MC6_搬送モータ,#150)
tmr(MC7_搬送モータ,timerr_MC7_搬送モータ,#150)
tmr(MC8_搬送モータ,timerr_MC8_搬送モータ,#100)
tmr(MC9_モータローラ,timerr_MC9_モータローラ,#100)

if ldp(timerr_MC6_搬送モータ.B) then
	errpassMC6_搬送モータ=ON
	mMC6_搬送モータ=OFF
	ejectMC6_搬送モータ=OFF
	almMC6_搬送モータ=ON
	搬送コンベアAErrStep=1

else if ldp(timerr_MC7_搬送モータ.B) then
	errpassMC7_搬送モータ=ON
	mMC7_搬送モータ=OFF
	ejectMC7_搬送モータ=OFF
	almMC7_搬送モータ=ON
	搬送コンベアAErrStep=1

else if ldp(timerr_MC8_搬送モータ.B) then
	errpassMC8_搬送モータ=ON
	mMC8_搬送モータ=OFF
	ejectMC8_搬送モータ=OFF
	mMC9_モータローラ=OFF
	almMC8_搬送モータ=ON
	搬送コンベアAErrStep=1

else if ldp(timerr_MC9_モータローラ.B) then
	errpassMC9_モータローラ=ON
	mMC8_搬送モータ=OFF
	ejectMC8_搬送モータ=OFF
	mMC9_モータローラ=OFF
	almMC9_モータローラ=ON
	搬送コンベアAErrStep=1
	
else if ldp(tim_XSW14_ストッパ上昇端.B) or ldp(tim_notXSW14_ストッパ上昇端.B) then
	errpassXSW14_ストッパ上昇端=ON
	pauseSV14_ストッパ上昇=ON
	almXSW14_ストッパ上昇端=ON
	pnlPBXSW14_ストッパ上昇端=ON
	搬送コンベアAErrStep=1

else if ldp(tim_XSW15_ストッパ下降端.B) or ldp(tim_notXSW15_ストッパ下降端.B) then
	errpassXSW15_ストッパ下降端=ON
	almXSW15_ストッパ下降端=ON
	pnlPBXSW15_ストッパ下降端=ON
	搬送コンベアAErrStep=1

else if ldp(tim_XSW16_ストッパ上昇端.B) or ldp(tim_notXSW16_ストッパ上昇端.B) then
	errpassXSW16_ストッパ上昇端=ON
	pauseSV64_ストッパ上昇=ON
	almXSW16_ストッパ上昇端=ON
	pnlPBXSW16_ストッパ上昇端=ON
	搬送コンベアAErrStep=1

else if ldp(tim_XSW17_ストッパ下降端.B) or ldp(tim_notXSW17_ストッパ下降端.B) then
	errpassXSW17_ストッパ下降端=ON
	almXSW17_ストッパ下降端=ON
	pnlPBXSW17_ストッパ下降端=ON
	搬送コンベアAErrStep=1

else if ldp(tim_XSW21_リフト上昇端.B) or ldp(tim_notXSW21_リフト上昇端.B) then
	errpassXSW21_リフト上昇端=ON
	pauseSV21_リフト=ON
	almXSW21_リフト上昇端=ON
	pnlPBXSW21_リフト上昇端=ON
	搬送コンベアAErrStep=1

else if ldp(tim_XSW20_リフト下降端.B) or ldp(tim_notXSW20_リフト下降端.B) then
	errpassXSW20_リフト下降端=ON
	almXSW20_リフト下降端=ON
	pnlPBXSW20_リフト下降端=ON
	搬送コンベアAErrStep=1

else if ldp(tim_XSW18_ストッパ上昇端.B) or ldp(tim_notXSW18_ストッパ上昇端.B) then
	errpassXSW18_ストッパ上昇端=ON
	almXSW18_ストッパ上昇端=ON
	pnlPBXSW18_ストッパ上昇端=ON
	搬送コンベアAErrStep=1

else if ldp(tim_XSW19_ストッパ下降端.B) or ldp(tim_notXSW19_ストッパ下降端.B) then
	errpassXSW19_ストッパ下降端=ON
	almXSW19_ストッパ下降端=ON
	pnlPBXSW19_ストッパ下降端=ON
	搬送コンベアAErrStep=1

else if ldp(tim_配米シャッターErr.B) then

	if not(XSW4_水切りシャッター閉A) then
		almXSW4_水切りシャッター閉A=ON
	else if not(XSW8_水切りシャッター閉B) then
		almXSW8_水切りシャッター閉B=ON
	end if

	自動搬送ErrStep=1
	
else if ldp(almPH1_釜検知 or almPH2_フタ検知) then
	搬送コンベアAErrStep=1
end if

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 搬送コンベアAAutoMode	自動モード セレクトスイッチ
'System :: 搬送コンベアAAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 搬送コンベアAEmg	その場停止

'釜フタ搬送:	昇降装置B  -> 搬送口

'釜浸漬搬送:   	搬送口 -> 浸漬A(浸漬B）
'フタ搬送:		搬送口 -> 浸漬B
'釜注水:		浸漬A(浸漬B）-> 注水
'フタ排出:		浸漬B -> (リフト）

'釜排出:		注水 -> （リフト）

if 搬送コンベアAEmgStep=0 then  
	
	if 搬送コンベアAErrStep=0  then

	if not(搬送コンベアAOrgErr) then

	if (搬送コンベアAAutoMode and 自動搬送AutoMode ) or 搬送コンベアAstep<>0 then

		
		if not(搬送コンベアAAutoMode and 自動搬送AutoMode ) then
			搬送コンベアAAutoRun=OFF
		end if

		if ManualInite=1 then
			mSV14_ストッパ上昇=ON
			mSV64_ストッパ上昇=ON
			
			mSV21_リフト=ON
			mSV51_ストッパ=ON
			ManualInite=0
		end if
	
	tmr(PH3_釜検知,timdly_PH3_釜検知,2)
	tmr(PH4_フタ検知,timdly_PH4_フタ検知,2)
	tmr(PH5_釜検知,timdly_PH5_釜検知,2)
	tmr(PH6_フタ検知,timdly_PH6_フタ検知,2)
	tmr(PH7_釜検知,timdly_PH7_釜検知,2)
	tmr(PH8_フタ検知,timdly_PH8_フタ検知,2)	
	tmr(PH9_釜検知,timdly_PH9_釜検知,2)
	tmr(PH10_フタ検知,timdly_PH10_フタ検知,2)

	'-----------------------------------------------------------------
	' ストッパON/OFFタイミングタスク
	'-----------------------------------------------------------------
	'SV14_ストッパ上昇 
	tmr(tim_SV14_ストッパ上昇,tim_SV14_ストッパ上昇_val)
	select case SV14_ストッパ上昇step
	case 0
	case 1
		PH1_釜起動検知=PH1_釜検知 '----搬送口
		PH2_フタ起動検知=PH2_フタ検知
		PH3_釜起動検知=PH3_釜検知 '----浸漬A
		PH4_フタ起動検知=PH4_フタ検知
		'PH5_釜検知 '----浸漬B
		'PH6_フタ検知
		inc(SV14_ストッパ上昇step)
	
	case 2
		if PH1_釜検知 or PH2_フタ検知 or PH3_釜検知 or PH4_フタ検知 then
			inc(SV14_ストッパ上昇step)
		else
			SV14_ストッパ上昇step=0
		end if
	
	case 3
		mSV14_ストッパ上昇=OFF
		errpassXSW15_ストッパ下降端=OFF
		inc(SV14_ストッパ上昇step)
		
	case 4
		if errpassXSW15_ストッパ下降端 or ( (XSW15_ストッパ下降端  and not(pnlPBXSW15_ストッパ下降端)) or passXSW15_ストッパ下降端) then
			inc(SV14_ストッパ上昇step)
		end if				
		
	case 5
		if not(PH1_釜検知) and not(PH2_フタ検知) and not(PH3_釜検知) and not(PH4_フタ検知) then
				tim_SV14_ストッパ上昇_val=30
				res(tim_SV14_ストッパ上昇)
				inc(SV14_ストッパ上昇step)
		end if
		
		
	case 6
		if 1 then
			if tim_SV14_ストッパ上昇.B then
				inc(SV14_ストッパ上昇step)
			end if
		else
			
			if (PH1_釜起動検知 or PH2_フタ起動検知) then
				if (PH3_釜検知 and timdly_PH3_釜検知) or (PH4_フタ検知 and timdly_PH4_フタ検知) then
					tim_SV14_ストッパ上昇_val=0
					res(tim_SV14_ストッパ上昇)
					inc(SV14_ストッパ上昇step)
				end if
			else
				inc(SV14_ストッパ上昇step)
			end if
		
		end if
		
	case 7
		if tim_SV14_ストッパ上昇.B then
			inc(SV14_ストッパ上昇step)
		end if
	
	case 8
		mSV14_ストッパ上昇=ON
		errpassXSW14_ストッパ上昇端=OFF
		inc(SV14_ストッパ上昇step)

	case 9
		if errpassXSW14_ストッパ上昇端 or ( (XSW14_ストッパ上昇端 and not(pnlPBXSW14_ストッパ上昇端)) or passXSW14_ストッパ上昇端) then
			inc(SV14_ストッパ上昇step)
		end if				


	case 10
		if 	PH3_釜検知 and PH4_フタ検知 then  '浸漬A
			inc(釜カウントA)
		end if

		SV14_ストッパ上昇step=0
	end select	
	'--------------------------------------------
	'SV64_ストッパ上昇
	tmr(tim_SV64_ストッパ上昇, tim_SV64_ストッパ上昇_val)
	select case SV64_ストッパ上昇step
	case 0
	case 1
		PH1_釜起動検知=PH1_釜検知 '----搬送口
		PH2_フタ起動検知=PH2_フタ検知
		PH3_釜起動検知=PH3_釜検知 '----浸漬A
		PH4_フタ起動検知=PH4_フタ検知
		PH5_釜起動検知=PH5_釜検知 '----浸漬B
		PH6_フタ起動検知=PH6_フタ検知
		'PH7_釜検知 '----注水
		'PH8_フタ起動検知=PH8_フタ検知
		inc(SV64_ストッパ上昇step)
	
	case 2
		if PH3_釜検知 or PH4_フタ検知 or PH5_釜検知 or PH6_フタ検知 then
			inc(SV64_ストッパ上昇step)
		else
			SV64_ストッパ上昇step=0
		end if

	case 3
		mSV64_ストッパ上昇=OFF
		errpassXSW17_ストッパ下降端=OFF
		inc(SV64_ストッパ上昇step)

	case 4
		if errpassXSW17_ストッパ下降端 or ( (XSW17_ストッパ下降端 and not(pnlPBXSW17_ストッパ下降端)) or passXSW17_ストッパ下降端) then			
			mSV64_ストッパ上昇=OFF
			inc(SV64_ストッパ上昇step)
		end if
		
	case 5
		if not(PH5_釜検知) and not(PH6_フタ検知) then '----浸漬B
			tim_SV64_ストッパ上昇_val=40
			res(tim_SV64_ストッパ上昇)
			inc(SV64_ストッパ上昇step)
		end if
	
	case 6
		if 1 then
			if tim_SV64_ストッパ上昇.B then
				inc(SV64_ストッパ上昇step)
			end if
		else
		
			if (PH3_釜起動検知 or PH4_フタ起動検知) then
				if (PH5_釜検知 and timdly_PH5_釜検知)  or (PH6_フタ検知 and timdly_PH6_フタ検知) then
					tim_SV64_ストッパ上昇_val=0
					res(tim_SV64_ストッパ上昇)
					inc(SV64_ストッパ上昇step)
				end if
			else
				inc(SV64_ストッパ上昇step)
			end if
		
		end if
		
	case 7
		if tim_SV64_ストッパ上昇.B then
			inc(SV64_ストッパ上昇step)
		end if
	
	case 8
		mSV64_ストッパ上昇=ON
		errpassXSW16_ストッパ上昇端=OFF
		inc(SV64_ストッパ上昇step)
	
	case 9
		if errpassXSW16_ストッパ上昇端 or ( (XSW16_ストッパ上昇端 and not(pnlPBXSW16_ストッパ上昇端)) or passXSW16_ストッパ上昇端) then			
			inc(SV64_ストッパ上昇step)
		end if		

	case 10
		if 	PH5_釜検知 and PH6_フタ検知 then  '浸漬B
			inc(釜カウントB)
		end if
		SV64_ストッパ上昇step=0
	
	end select
	'--------------------------------------------
	'MC6_搬送モータ [搬送口->浸漬A]
	tmr(tim_MC6_搬送モータ,tim_MC6_搬送モータ_val)
	select case MC6_搬送モータstep
	case 0
	case 1
		PH1_釜起動検知=PH1_釜検知 '----搬送口
		PH2_フタ起動検知=PH2_フタ検知
		'PH3_釜検知 '----浸漬A
		'PH4_フタ検知
		inc(MC6_搬送モータstep)
		
	case 2
		if PH1_釜検知 or PH2_フタ検知 then
				if PH1_釜検知 then
					StageDevice52=0
					StageDevice0=$8000+$100 '<- StageDevice  [ 釜  ］のデータ入れ込みｽﾀｰﾄ地点
				else
					StageDevice52=0
					StageDevice0=0 '<- StageDevice  [ 釜  ］のデータ入れ込みｽﾀｰﾄ地点
				end if
			inc(MC6_搬送モータstep)
		else
			MC6_搬送モータstep=0
		end if		

	case 3
		mMC6_搬送モータ=ON
		errpassMC6_搬送モータ=OFF
		inc(MC6_搬送モータstep)
	
	case 4
		if errpassMC6_搬送モータ then
			inc(MC6_搬送モータstep)
		
		else if not(PH1_釜検知) and not(PH2_フタ検知) and not(PH3_釜検知) and not(PH4_フタ検知) then
			inc(MC6_搬送モータstep)
		end if		
	
	case 5
		if errpassMC6_搬送モータ then
			inc(MC6_搬送モータstep)
		
		else if PH1_釜起動検知 or PH2_フタ起動検知  then
			if (PH3_釜検知 and timdly_PH3_釜検知.B) or (PH4_フタ検知 and timdly_PH4_フタ検知.B) then
				inc(MC6_搬送モータstep)
			end if
		else
			inc(MC6_搬送モータstep)
		end if

	case 6
		tim_MC6_搬送モータ_val=0
		res(tim_MC6_搬送モータ)
		inc(MC6_搬送モータstep)
	
	case 7
		if tim_MC6_搬送モータ.B then
			inc(MC6_搬送モータstep)
		end if	

	case 8
		mMC6_搬送モータ=OFF
		inc(MC6_搬送モータstep)
	
	case 9
		釜フタ昇降装置B排出要求=OFF
		MC6_搬送モータstep=0
		
	end select
	'--------------------------------------------
	'MC7_搬送モータ	[搬送口,浸漬A、浸漬B,注水,リフト -> 浸漬A、浸漬B,注水,リフト ]
	tmr(tim_MC7_搬送モータ,tim_MC7_搬送モータ_val)
	select case MC7_搬送モータstep
	case 0
	case 1
		PH1_釜起動検知=PH1_釜検知 '----搬送口
		PH2_フタ起動検知=PH2_フタ検知
		PH3_釜起動検知=PH3_釜検知 '----浸漬A
		PH4_フタ起動検知=PH4_フタ検知
		PH5_釜起動検知=PH5_釜検知 '----浸漬B
		PH6_フタ起動検知=PH6_フタ検知
		PH7_釜起動検知=PH7_釜検知 '----注水
		PH8_フタ起動検知=PH8_フタ検知
		'PH9_釜検知 '----コンベアBリフト
		'PH10_フタ検知
		inc(MC7_搬送モータstep)
		
	
	case 2
		if PH1_釜検知 or PH2_フタ検知 then '----搬送口
			inc(MC7_搬送モータstep)
		else if PH3_釜検知 or PH4_フタ検知 then '----浸漬A
			inc(MC7_搬送モータstep)
		else if PH5_釜検知 or PH6_フタ検知 then  '----浸漬B
			inc(MC7_搬送モータstep)
		else if PH7_釜検知 or PH8_フタ検知 then
			inc(MC7_搬送モータstep)
		else
			MC7_搬送モータstep=0
		end if
	
	case 3
		if (not(PH3_釜起動検知) or not(PH4_フタ起動検知) ) or (PH3_釜起動検知 and PH4_フタ起動検知 and  ((XSW15_ストッパ下降端 and not(pnlPBXSW15_ストッパ下降端)) or passXSW15_ストッパ下降端))  then 
			if (not(PH5_釜起動検知) or not(PH6_フタ起動検知) ) or (PH5_釜起動検知 and PH6_フタ起動検知 and  ((XSW17_ストッパ下降端 and not(pnlPBXSW17_ストッパ下降端)) or passXSW17_ストッパ下降端))  then 
				inc(MC7_搬送モータstep)
			end if
		end if	
	
	case 4
		mMC7_搬送モータ=ON
		errpassMC7_搬送モータ=OFF
		inc(MC7_搬送モータstep)
	
	case 5
		if errpassMC7_搬送モータ then
			inc(MC7_搬送モータstep)
		
		else if not(PH3_釜検知) and not(PH4_フタ検知) then
			if not(PH5_釜検知) and not(PH6_フタ検知) then
				if not(PH7_釜検知) and  not(PH8_フタ検知) then
				inc(MC7_搬送モータstep)
				end if
			end if
		end if
	
	case 6
		if errpassMC7_搬送モータ then
			inc(MC7_搬送モータstep)
		
		else if PH1_釜起動検知 or PH2_フタ起動検知 then '搬送口
			if (PH3_釜検知 and timdly_PH3_釜検知) or (PH4_フタ検知 and timdly_PH4_フタ検知) then '----浸漬A
				inc(MC7_搬送モータstep)						
			end if
		else if PH3_釜起動検知 or PH4_フタ起動検知 then '----浸漬A
			if (PH5_釜検知 and timdly_PH5_釜検知.B) or (PH6_フタ検知 and PH6_フタ起動検知)   then '----浸漬B
				inc(MC7_搬送モータstep)			
			end if
		else if PH5_釜起動検知 or PH6_フタ起動検知 then '----浸漬B
			if (PH7_釜検知 and timdly_PH7_釜検知.B) or (PH8_フタ検知 and timdly_PH8_フタ検知) then '----待機
				inc(MC7_搬送モータstep)						
			end if
		else if PH7_釜起動検知 or PH8_フタ起動検知 then '----待機
			if (PH9_釜検知 and timdly_PH9_釜検知.B) or (PH10_フタ検知 and timdly_PH10_フタ検知.B) then '----コンベアBリフト
				inc(MC7_搬送モータstep)			
			end if
		end if
	
	case 7
		if 0 then
		if PH1_釜起動検知 then'搬送口
			if (PH3_釜検知 and timdly_PH3_釜検知) then'----浸漬A
				inc(MC7_搬送モータstep)						
			end if
		else if PH3_釜起動検知 then '----浸漬A
			if PH5_釜検知 and timdly_PH5_釜検知.B  then '----浸漬B
				inc(MC7_搬送モータstep)			
			end if
		else
			inc(MC7_搬送モータstep)			
		end if
		end if
		
		inc(MC7_搬送モータstep)			
		
	
	case 8
		tim_MC7_搬送モータ_val=16 'ブレークタイミング
		res(tim_MC7_搬送モータ)
		inc(MC7_搬送モータstep)
	
	case 9
		if tim_MC7_搬送モータ.B then
			inc(MC7_搬送モータstep)
		end if
	
	case 10
		mMC7_搬送モータ=OFF
		inc(MC7_搬送モータstep)
	
	case 11
		MC7_搬送モータstep=0
	
	end select
	'--------------------------------------------
	'MC8_搬送モータ
	tmr(tim_MC8_搬送モータ供給,tim_MC8_搬送モータ供給_val)
	select case MC8_搬送モータ供給step
	case 0
	case 1
		PH5_釜起動検知=PH5_釜検知
		PH6_フタ起動検知=PH6_フタ検知
		inc(MC8_搬送モータ供給step)
	
	case 2
		if PH5_釜検知 or PH6_フタ検知 then
			inc(MC8_搬送モータ供給step)
		else
			MC8_搬送モータ供給step=0
		end if
	
	case 3
		mMC8_搬送モータ=ON
		errpassMC8_搬送モータ=OFF
		inc(MC8_搬送モータ供給step)

	case 4
		if errpassMC8_搬送モータ then
			inc(MC8_搬送モータ供給step)		
		else if not(PH5_釜検知) and not(PH6_フタ検知) and not(PH7_釜検知) and not(PH8_フタ検知) then
			inc(MC8_搬送モータ供給step)
		end if

	case 5
		if errpassMC8_搬送モータ then
			inc(MC8_搬送モータ供給step)
		else if (PH7_釜検知 and timdly_PH7_釜検知.B) or (PH8_フタ検知  and timdly_PH8_フタ検知.B) then
			inc(MC8_搬送モータ供給step)
		end if
	
	case 6
		tim_MC8_搬送モータ供給_val=5
		res(tim_MC8_搬送モータ供給)
		inc(MC8_搬送モータ供給step)		
		
	case 7
		if tim_MC8_搬送モータ供給.B then
			inc(MC8_搬送モータ供給step)
		end if
	
	case 8
		mMC8_搬送モータ=OFF
		inc(MC8_搬送モータ供給step)
		
	case 9
		MC8_搬送モータ供給step=0
						
	end select
	
	'--------------------------------------------
	'MC8_搬送モータ
	tmr(tim_MC8_搬送モータ排出,tim_MC8_搬送モータ排出_val)
	select case MC8_搬送モータ排出step
	case 0
	case 1
		PH7_釜起動検知=PH7_釜検知
		PH8_フタ起動検知=PH8_フタ検知
		inc(MC8_搬送モータ排出step)
	
	case 2
		if PH7_釜検知 or PH8_フタ検知 then
			inc(MC8_搬送モータ排出step)
		else
			MC8_搬送モータ排出step=0
		end if
	
	case 3
		ejectMC8_搬送モータ=ON
		errpassMC8_搬送モータ=OFF
		inc(MC8_搬送モータ排出step)

	case 4
		if errpassMC8_搬送モータ then
			inc(MC8_搬送モータ排出step)		
		else if not(PH7_釜検知) and not(PH8_フタ検知) and not(PH9_釜検知) and not(PH10_フタ検知) then
			inc(MC8_搬送モータ排出step)
		end if

	case 5
		if errpassMC8_搬送モータ then
			inc(MC8_搬送モータ排出step)		
		else if (PH9_釜検知 and timdly_PH9_釜検知.B) or (PH10_フタ検知 and timdly_PH10_フタ検知.B) then
			inc(MC8_搬送モータ排出step)
		end if
	
	case 6
		tim_MC8_搬送モータ排出_val=8
		res(tim_MC8_搬送モータ排出)
		inc(MC8_搬送モータ排出step)		
		
	case 7
		if tim_MC8_搬送モータ排出.B then
			inc(MC8_搬送モータ排出step)
		end if
	
	case 8
		ejectMC8_搬送モータ=OFF
		inc(MC8_搬送モータ排出step)
		
	case 9
		MC8_搬送モータ排出step=0
						
	end select
	
	'--------------------------------------------
	tmr(tim_MC9_モータローラ,tim_MC9_モータローラ_val)
	select case MC9_モータローラstep
	case 0
		
	case 1
		if PH7_釜検知 or PH8_フタ検知 then
			inc(MC9_モータローラstep)
		else
			MC9_モータローラstep=0
		end if
	
	case 2
		mMC9_モータローラ=ON
		errpassMC9_モータローラ=OFF
		inc(MC9_モータローラstep)
	
	case 3
		if errpassMC9_モータローラ then
			inc(MC9_モータローラstep)		
		else if not(PH7_釜検知) and not(PH8_フタ検知) then
			inc(MC9_モータローラstep)
		end if
	
	case 4
		if errpassMC9_モータローラ then
			inc(MC9_モータローラstep)		
		else if PH9_釜検知 or PH10_フタ検知 then
			inc(MC9_モータローラstep)
		end if
	
	case 5
		tim_MC9_モータローラ_val=15
		res(tim_MC9_モータローラ)
		inc(MC9_モータローラstep)
	
	case 6
		if tim_MC9_モータローラ.B then
			inc(MC9_モータローラstep)
		end if
	
	case 7
		mMC9_モータローラ=OFF
		inc(MC9_モータローラstep)
	
	case 8
		搬送コンベアA排出要求=ON
		MC9_モータローラstep=0
	end select

	'===================================================================================================================
	'【 リフタータスク 】
	'
		tmr(tim_procstep,tim_procstep_val)
		tmr(PH1_釜検知 or PH2_フタ検知, tim_搬送入口検知 , 20)

		select case 搬送コンベアAstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 搬送コンベアAAutoRun then
				inc(搬送コンベアAstep)
			else 
				搬送コンベアAstep=0 '終了待機
			end if
		
		case 2
			if PH9_釜検知 or PH10_フタ検知 then
				搬送コンベアA動作中=OFF
				搬送コンベアA排出要求=ON
				搬送コンベアAstep=1
			else
				inc(搬送コンベアAstep)
			end if
			
		case 3
		' [ 次の搬送コンベア停止確認 ]		
			if 搬送コンベアA排出要求=OFF  and (釜フタ昇降装置B排出要求 or tim_搬送入口検知.B ) then
				inc(搬送コンベアAstep)
			else
				搬送コンベアAstep=1
			end if
		
		case 4
			if 浸漬タンクA排出要求 and ((XSW4_水切りシャッター閉A and not(pnlPBXSW4_水切りシャッター閉A)) or passXSW4_水切りシャッター閉A) and 浸漬タンクB排出要求 and ((XSW8_水切りシャッター閉B and not(pnlPBXSW8_水切りシャッター閉B)) or passXSW8_水切りシャッター閉B) then
				inc(搬送コンベアAstep)
			else
				搬送コンベアAstep=1
			end if
			
		case 5  '原点検出
			if 搬送コンベアAOrg then
				搬送コンベアAstep=100
			else
				搬送コンベアAstep=1
			end if
		'--------------------------------------------------------------------------------------------------------------
		case 100
			PH1_釜起動検知=PH1_釜検知 '----搬送口
			PH2_フタ起動検知=PH2_フタ検知
			PH3_釜起動検知=PH3_釜検知 '----浸漬A
			PH4_フタ起動検知=PH4_フタ検知
			PH5_釜起動検知=PH5_釜検知 '----浸漬B
			PH6_フタ起動検知=PH6_フタ検知
			PH7_釜起動検知=PH7_釜検知 '----待機
			PH8_フタ起動検知=PH8_フタ検知			
		
			if フタ検知 and not(PH1_釜検知) and PH2_フタ検知 then
				almPH2_フタ検知=ON
				釜フタ昇降装置B排出要求=OFF
				搬送コンベアAstep=1
			else if not(フタ検知) and PH1_釜検知 and PH2_フタ検知 then
				almPH1_釜検知=ON
				釜フタ昇降装置B排出要求=OFF
				搬送コンベアAstep=1
			else 
			
				if not(PH1_釜検知) and PH2_フタ検知 then 'フタ検知
						フタ検知=ON
				else if PH1_釜検知 and PH2_フタ検知 then '釜検知
						フタ検知=OFF
				end if
				inc(搬送コンベアAstep)	

			end if

		
		case 101 
			搬送コンベアA動作中=ON

			mSV21_リフト=ON
			mSV51_ストッパ=ON
			errpassXSW21_リフト上昇端=OFF
			errpassXSW18_ストッパ上昇端=OFF
			inc(搬送コンベアAstep)

		case 102
			if ((XSW21_リフト上昇端 and not(pnlPBXSW21_リフト上昇端)) or passXSW21_リフト上昇端) or errpassXSW21_リフト上昇端 then
				inc(搬送コンベアAstep)
			end if
		
		case 103
			if ((XSW18_ストッパ上昇端 and not(pnlPBXSW18_ストッパ上昇端)) or passXSW18_ストッパ上昇端) or errpassXSW18_ストッパ上昇端 then
				inc(搬送コンベアAstep)
			end if			
				
		
		case 104

			SV14_ストッパ上昇step=1
			SV64_ストッパ上昇step=1
			MC7_搬送モータstep=1
			MC8_搬送モータ供給step=1
			MC8_搬送モータ排出step=1
			MC9_モータローラstep=1
			inc(搬送コンベアAstep)

		case 105
			tim_procstep_val=40
			res(tim_procstep)
			inc(搬送コンベアAstep)
			
		case 106
			if tim_procstep.B then
				MC6_搬送モータstep=1
				inc(搬送コンベアAstep)
			end if
		
		case 107
			if 	SV14_ストッパ上昇step=0 and SV64_ストッパ上昇step=0	and MC6_搬送モータstep=0 and MC7_搬送モータstep=0 and MC8_搬送モータ供給step=0 and MC8_搬送モータ排出step=0 and MC9_モータローラstep=0 then
				inc(搬送コンベアAstep)
			end if		

		case 108
			StageDevice4=StageDevice3
			StageItem4=ANDA(StageDevice4.U,$00FF)

			StageDevice3=StageDevice2
			StageItem3=ANDA(StageDevice3.U,$00FF)  
			
			StageDevice2=StageDevice1
			StageItem2=ANDA(StageDevice2.U,$00FF)  

			StageDevice1=StageDevice0	
			StageItem1=ANDA(StageDevice1.U,$00FF)  
			StageItem0=ANDA(StageDevice0.U,$00FF)  
			

			if not(PH1_釜検知) and PH2_フタ検知 then
				StageDevice0=0
			end if

			if not(PH3_釜検知) and PH4_フタ検知 then
				StageDevice1=0
			end if
			
			if not(PH5_釜検知) and PH6_フタ検知 then
				Stagedevice2=0
			end if

			if not(PH7_釜検知) and PH8_フタ検知 then
				Stagedevice3=0
			end if
			
			if PH3_釜検知 and PH4_フタ検知 then
				inc(空釜搬送釜数)
				inc(搬送釜数)
				inc(アイドル釜数現在値)
				if 消火警告までの残釜数>0 then
					DEC(消火警告までの残釜数)
				end if
			end if

			inc(搬送コンベアAstep)

		case 109
			if 残米処理A実行 and ANDA(StageDevice4,$8200)=$8200 then
				残米A処理待機=ON
				if 残米A手動排出確認 then
					残米A処理待機=OFF
					inc(搬送コンベアAstep)
				end if
			else
				inc(搬送コンベアAstep)
			end if
		
		case 110
			if 残米処理B実行 and ANDA(StageDevice4,$8400)=$8400 then
				残米B処理待機=ON
				if 残米B手動排出確認 then
					残米B処理待機=OFF
					inc(搬送コンベアAstep)
				end if
			else
				inc(搬送コンベアAstep)
			end if

		case 111

			浸漬タンクA排出要求=OFF
			浸漬タンクB排出要求=OFF
			配米完了A=OFF
			配米完了B=OFF
			注水完了=OFF

			搬送コンベアA動作中=OFF
			搬送コンベアAstep=1
			

		end select

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else
		if ManualInite=0 then
			mSV14_ストッパ上昇=OFF
			mSV64_ストッパ上昇=OFF

			ManualInite=1
		end if
		
		搬送コンベアAAutoRun=OFF
		
		搬送コンベアAstep=0 '終了

		res(timerr_MC6_搬送モータ)'tmr(MC6_搬送モータ,timerr_MC6_搬送モータ,#150)
		res(timerr_MC7_搬送モータ)'tmr(MC7_搬送モータ,timerr_MC7_搬送モータ,#150)
		res(timerr_MC8_搬送モータ)'tmr(MC8_搬送モータ,timerr_MC8_搬送モータ,#100)
		res(timerr_MC9_モータローラ)'tmr(MC9_モータローラ,timerr_MC9_モータローラ,#100)

		
		if ldp(pnlPBMC6_搬送モータ) then
			if mMC6_搬送モータ then
				mMC6_搬送モータ=OFF
			else
				mMC6_搬送モータ=ON
			end if
		end if
		
		if ldp(pnlPBMC7_搬送モータ) then
			if mMC7_搬送モータ then
				mMC7_搬送モータ=OFF
			else
				mMC7_搬送モータ=ON
			end if
		end if
		
		if ldp(pnlPBMC8_搬送モータ) then
			if mMC8_搬送モータ then
				mMC8_搬送モータ=OFF
			else
				mMC8_搬送モータ=ON
			end if
		end if
		
		if ldp(pnlPBSV14_ストッパ上昇) then
			if mSV14_ストッパ上昇 then
				mSV14_ストッパ上昇=OFF
				'mSV15_ストッパ下降=ON
			else
				mSV14_ストッパ上昇=ON
				'mSV15_ストッパ下降=OFF
			end if
		end if
		
		if ldp(pnlPBSV64_ストッパ上昇) then
			if mSV64_ストッパ上昇 then
				mSV64_ストッパ上昇=OFF
				'mSV70_ストッパ下降=ON
			else
				mSV64_ストッパ上昇=ON
				'mSV70_ストッパ下降=OFF
			end if
		end if
		
	end if '搬送コンベアAAutoMode and not(搬送コンベアAOrgErrStep)

	'===================================================================================================================
	'【 搬送コンベアAOrgErr処理 】
	else
		
		if ResetFlg then
			搬送コンベアAOrgErr=OFF
		end if		


	end if

	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else

		搬送コンベアAErr=ON
		pauseMC6_搬送モータ=ON
		pauseMC7_搬送モータ=ON
		pauseMC8_搬送モータ=ON
		pauseMC9_モータローラ=ON
		res(timerr_MC6_搬送モータ)
		res(timerr_MC7_搬送モータ)
		res(timerr_MC8_搬送モータ)
		res(timerr_MC9_モータローラ)

		select case 搬送コンベアAErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW14_ストッパ上昇端=OFF
				almXSW15_ストッパ下降端=OFF
				almXSW16_ストッパ上昇端=OFF
				almXSW17_ストッパ下降端=OFF
				almXSW21_リフト上昇端=OFF
				almXSW20_リフト下降端=OFF
				almXSW18_ストッパ上昇端=OFF
				almXSW19_ストッパ下降端=OFF
				almMC6_搬送モータ=OFF
				almMC7_搬送モータ=OFF
				almMC8_搬送モータ=OFF
				almMC9_モータローラ=OFF
				almXSW4_水切りシャッター閉A=OFF
				almXSW8_水切りシャッター閉B=OFF
				
				almPH1_釜検知=OFF
				almPH2_フタ検知=OFF

				inc(搬送コンベアAErrStep)
			end if
		case 2
			搬送コンベアAErr=OFF

			res(tim_XSW14_ストッパ上昇端.B)
			res(tim_XSW15_ストッパ下降端.B)
			res(tim_XSW16_ストッパ上昇端.B)
			res(tim_XSW17_ストッパ下降端.B)
			res(tim_XSW21_リフト上昇端.B)
			res(tim_XSW20_リフト下降端.B)
			
			res(tim_notXSW14_ストッパ上昇端.B)
			res(tim_notXSW15_ストッパ下降端.B)
			res(tim_notXSW16_ストッパ上昇端.B)
			res(tim_notXSW17_ストッパ下降端.B)
			res(tim_notXSW21_リフト上昇端.B)
			res(tim_notXSW20_リフト下降端.B)

			pauseMC6_搬送モータ=OFF
			pauseMC7_搬送モータ=OFF
			pauseMC8_搬送モータ=OFF
			pauseMC9_モータローラ=OFF
			
			pauseSV14_ストッパ上昇=OFF
			pauseSV64_ストッパ上昇=OFF

			pauseSV21_リフト=OFF


			搬送コンベアAErrStep=0
		end select

	end if 'if 搬送コンベアAErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case 搬送コンベアAEmgStep
	case 0
		
	case 1
		搬送コンベアAAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (搬送コンベアAAutoMode and 自動搬送AutoMode ) or 搬送コンベアAstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseMC6_搬送モータ=ON
			pauseMC7_搬送モータ=ON
			pauseMC8_搬送モータ=ON
			pauseMC9_モータローラ=ON

			if timstack=OFF then
				timdly_PH6_フタ検知_stack=timdly_PH6_フタ検知.U
				timdly_PH7_釜検知_stack=timdly_PH7_釜検知.U
				timdly_PH8_フタ検知_stack=timdly_PH8_フタ検知.U
				timdly_PH9_釜検知_stack=timdly_PH9_釜検知.U
				timdly_PH10_フタ検知_stack=timdly_PH10_フタ検知.U
				timdly_PH1_釜検知_stack=timdly_PH1_釜検知.U
				tim_MC7_搬送モータ_stack=tim_MC7_搬送モータ.U
				tim_MC6_搬送モータ_stack=tim_MC6_搬送モータ.U
				tim_MC9_モータローラ_stack=tim_MC9_モータローラ.U
				tim_procstep_stack=tim_procstep.U
				tim_SV14_ストッパ上昇_stack=tim_SV14_ストッパ上昇.U
				tim_MC8_搬送モータ供給_stack=tim_MC8_搬送モータ供給.U
				timdly_PH2_フタ検知_stack=timdly_PH2_フタ検知.U
				tim_SV64_ストッパ上昇_stack=tim_SV64_ストッパ上昇.U
				tim_MC8_搬送モータ排出_stack=tim_MC8_搬送モータ排出.U
				tim_搬送入口検知_stack=tim_搬送入口検知.U
				timdly_PH3_釜検知_stack=timdly_PH3_釜検知.U
				timdly_PH4_フタ検知_stack=timdly_PH4_フタ検知.U
				timdly_PH5_釜検知_stack=timdly_PH5_釜検知.U
				
				timstack=ON
			end if
			
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC6_搬送モータ=OFF
			mMC7_搬送モータ=OFF
			mMC8_搬送モータ=OFF
			mMC9_モータローラ=OFF
			mSV14_ストッパ上昇=OFF
			mSV64_ストッパ上昇=OFF		
			'---------------------------------
		end if
		
		'---------------------------------
		inc(搬送コンベアAEmgStep)
	case 2
		if ResetFlg then
			inc(搬送コンベアAEmgStep)
		end if
	case 3
		if (搬送コンベアAAutoMode and 自動搬送AutoMode ) or 搬送コンベアAstep<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseMC6_搬送モータ=OFF
				pauseMC7_搬送モータ=OFF
				pauseMC8_搬送モータ=OFF
				pauseMC9_モータローラ=OFF

				tim_MC7_搬送モータ.U=tim_MC7_搬送モータ_stack
				tim_MC6_搬送モータ.U=tim_MC6_搬送モータ_stack
				tim_MC9_モータローラ.U=tim_MC9_モータローラ_stack
				tim_procstep.U=tim_procstep_stack
				tim_SV14_ストッパ上昇.U=tim_SV14_ストッパ上昇_stack
				tim_MC8_搬送モータ供給.U=tim_MC8_搬送モータ供給_stack
				tim_SV64_ストッパ上昇.U=tim_SV64_ストッパ上昇_stack
				tim_MC8_搬送モータ排出.U=tim_MC8_搬送モータ排出_stack
				tim_搬送入口検知.U=tim_搬送入口検知_stack

				res(timdly_PH1_釜検知)
				res(timdly_PH2_フタ検知)
				res(timdly_PH3_釜検知)
				res(timdly_PH4_フタ検知)
				res(timdly_PH5_釜検知)
				res(timdly_PH6_フタ検知)
				res(timdly_PH7_釜検知)
				res(timdly_PH8_フタ検知)
				res(timdly_PH9_釜検知)
				res(timdly_PH10_フタ検知)
				'---------------------------------
				inc(搬送コンベアAEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(搬送コンベアAEmgStep)		
		end if				
	case 4
		timstack=OFF
		搬送コンベアAEmgStep=0
		搬送コンベアAEmg=OFF
	end select
		
end if 'if 搬送コンベアAEmgStep=0 then
