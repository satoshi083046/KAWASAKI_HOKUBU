'搬送コンベアB
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	搬送コンベアB
'
'  	移動速度  161.667mm/1sec
'
' MC9_モータローラ
' [ 4 ]
' PH5_釜検知			-> PH9_釜検知
' PH6_フタ検知			-> PH10_フタ検知
' SV16_リフト			-> SV21_リフト
' XSW16_リフト上昇端	-> XSW21_リフト上昇端
' XSW15_リフト下降端	-> XSW20_リフト下降端
' ( 新規 )				-> SV51ストッパ
' ( 新規 )				-> XSW18_ストッパ上昇端
' ( 新規 )				-> XSW19_ストッパ下降端
'
' MC12_搬送モータ
' [ 5 ]
' (PH11_釜検知)			-> (PH11_釜検知)
' (PH12_フタ検知)		-> (PH12_フタ検知)
' SV21_ストッパ			-> SV22_ストッパ
' XSW20_ストッパ上昇端	-> XSW23_ストッパ上昇端
' XSW19_ストッパ下降端	-> XSW22_ストッパ下降端
'
' MC13_搬送モータ
' [ 6 ]
' (PH13_釜検知)			-> (PH13_釜検知)
' (PH14_フタ検知)		-> (PH14_フタ検知)
' SV22_ストッパ			-> （ 削除  新規 )	-> SV51ストッパ)
' XSW22_ストッパ上昇端	->  ( 削除  新規 )	-> XSW18_ストッパ上昇端)
' XSW21_ストッパ下降端	->  ( 削除  新規 )	-> XSW19_ストッパ下降端)
'                                  
' MC16_モータローラ
' [ 7 ]
' (PH15_釜検知)			-> (PH15_釜検知)
' (PH16_フタ検知)		-> (PH16_フタ検知)
' SV33_リフト			-> SV23_リフト
' XSW38_リフト上昇端	-> XSW25_リフト上昇端
' XSW37_リフト下降端	-> XSW24_リフト下降端
' SV65_ストッパ			->  ( 削除 )
' XSW75_ストッパ上昇端	->  ( 削除 )
' XSW74_ストッパ下降端	->  ( 削除 )
'
'
'
'
'===================================================================================================================

'【 初期化処理 】
if CR2008 then '電源ON時初期化処理

	搬送コンベアBAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    搬送コンベアBAutoRun=OFF
    搬送コンベアB許可=ON
    搬送コンベアBOrgErr=OFF
    搬送コンベアBErr=OFF
    搬送コンベアBEmg=OFF
    搬送コンベアBstep=0
    搬送コンベアBErrStep=0
    搬送コンベアBOrgErrStep=0
    搬送コンベアBEmgStep=0
	

	SV21_リフトstep=0
	SV22_ストッパstep=0
	MC12_搬送モータ供給step=0
	MC12_搬送モータ排出step=0
	MC13_搬送モータ供給step=0
	MC13_搬送モータ排出step=0

	if SSW3_自動モード  then	
		ManualInite=1
	else
		ManualInite=0	
	end if
	
	
end if

'===================================================================================================================
'【 原点 】
搬送コンベアBOrg=((XSW23_ストッパ上昇端 and not(pnlPBXSW23_ストッパ上昇端)) or passXSW23_ストッパ上昇端) or ((XSW22_ストッパ下降端 and not(pnlPBXSW22_ストッパ下降端)) or passXSW22_ストッパ下降端)


'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	搬送コンベアBEmg=ON
	搬送コンベアBEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
tmr(SV22_ストッパ and not(XSW23_ストッパ上昇端) and not(pnlPBXSW23_ストッパ上昇端), tim_notXSW23_ストッパ上昇端,#30)
tmr(not(SV22_ストッパ) and not(XSW22_ストッパ下降端) and not(pnlPBXSW22_ストッパ下降端),tim_notXSW22_ストッパ下降端,#30)
tmr(SV51_ストッパ and not(XSW18_ストッパ上昇端) and not(pnlPBXSW18_ストッパ上昇端),tim_notXSW18_ストッパ上昇端,#30)
tmr(not(SV51_ストッパ) and not(XSW19_ストッパ下降端) and not(pnlPBXSW19_ストッパ下降端),tim_notXSW19_ストッパ下降端,#30)
tmr(SV23_リフト and not(XSW25_リフト上昇端) and not(pnlPBXSW25_リフト上昇端), tim_notXSW25_リフト上昇端, #30) 
tmr(not(SV23_リフト) and not(XSW24_リフト下降端) and not(pnlPBXSW24_リフト下降端),tim_notXSW24_リフト下降端,#30)
tmr(SV21_リフト and not(XSW21_リフト上昇端) and not(pnlPBXSW21_リフト上昇端) ,tim_notXSW21_リフト上昇端,#30)
tmr(not(SV21_リフト) and not(XSW20_リフト下降端) and not(pnlPBXSW20_リフト下降端) ,tim_notXSW20_リフト下降端,#30)

'tmr(not(SV22_ストッパ) and XSW23_ストッパ上昇端 and not(pnlPBXSW23_ストッパ上昇端), tim_XSW23_ストッパ上昇端,#20)
if LDP(SV22_ストッパ) and XSW23_ストッパ上昇端 and not(pnlPBXSW23_ストッパ上昇端) then
	SET(tim_XSW23_ストッパ上昇端)
end if
'tmr(SV22_ストッパ and XSW22_ストッパ下降端 and not(pnlPBXSW22_ストッパ下降端),tim_XSW22_ストッパ下降端,#20)
if LDF(SV22_ストッパ) and XSW22_ストッパ下降端 and not(pnlPBXSW22_ストッパ下降端) and not(pauseSV22_ストッパ) then
	SET(tim_XSW22_ストッパ下降端)
end if
'tmr(not(SV51_ストッパ) and XSW18_ストッパ上昇端 and not(pnlPBXSW18_ストッパ上昇端),tim_XSW18_ストッパ上昇端,#20)
if LDP(SV51_ストッパ) and XSW18_ストッパ上昇端 and not(pnlPBXSW18_ストッパ上昇端) then
	SET(tim_XSW18_ストッパ上昇端)
end if
'tmr(SV51_ストッパ and XSW19_ストッパ下降端 and not(pnlPBXSW19_ストッパ下降端),tim_XSW19_ストッパ下降端,#20)
if LDF(SV51_ストッパ) and XSW19_ストッパ下降端 and not(pnlPBXSW19_ストッパ下降端) and not(pauseSV51_ストッパ) then
	SET(tim_XSW19_ストッパ下降端)
end if
'tmr(not(SV23_リフト) and XSW25_リフト上昇端 and not(pnlPBXSW25_リフト上昇端), tim_XSW25_リフト上昇端, #10) 
if LDP(SV23_リフト) and XSW25_リフト上昇端 and not(pnlPBXSW25_リフト上昇端) then
	SET(tim_XSW25_リフト上昇端)
end if
'tmr(SV23_リフト and XSW24_リフト下降端 and not(pnlPBXSW24_リフト下降端),tim_XSW24_リフト下降端,#10)
if LDF(SV23_リフト) and XSW24_リフト下降端 and not(pnlPBXSW24_リフト下降端) and not(pauseSV23_リフト) then
	SET(tim_XSW24_リフト下降端)
end if
'tmr(not(SV21_リフト) and XSW21_リフト上昇端 and not(pnlPBXSW21_リフト上昇端) ,tim_XSW21_リフト上昇端,#10)
if LDP(SV21_リフト) and XSW21_リフト上昇端 and not(pnlPBXSW21_リフト上昇端) then
	SET(tim_XSW21_リフト上昇端)
end if
'tmr(SV21_リフト and XSW20_リフト下降端 and not(pnlPBXSW20_リフト下降端) ,tim_XSW20_リフト下降端,#10)
if LDF(SV21_リフト) and XSW20_リフト下降端 and not(pnlPBXSW20_リフト下降端) and not(pauseSV21_リフト) then
	SET(tim_XSW20_リフト下降端)
end if


tmr(MC12_搬送モータ,timerr_MC12_搬送モータ,#100)
tmr(MC13_搬送モータ,timerr_MC13_搬送モータ,#100)

tms(SV22_ストッパ, passtimXSW23_ストッパ上昇端,passtimXSW23_ストッパ上昇端_val)
tms(not(SV22_ストッパ),passtimXSW22_ストッパ下降端,passtimXSW22_ストッパ下降端_val)
'tms(SV51_ストッパ,passtimXSW18_ストッパ上昇端,passtimXSW18_ストッパ上昇端_val)
'tms(not(SV51_ストッパ),passtimXSW19_ストッパ下降端,passtimXSW19_ストッパ下降端_val)
tms(SV23_リフト,passtimXSW25_リフト上昇端,passtimXSW25_リフト上昇端_val)
tms(not(SV23_リフト),passtimXSW24_リフト下降端,passtimXSW24_リフト下降端_val)
'tms(SV21_リフト,passtimXSW21_リフト上昇端,passtimXSW21_リフト上昇端_val)
'tms(not(SV21_リフト),passtimXSW20_リフト下降端,passtimXSW20_リフト下降端_val)


if ldp(timerr_MC12_搬送モータ.B) or ldp(timerr_MC13_搬送モータ.B) then
	errpassMC12_搬送モータ=ON
	mMC12_搬送モータ=OFF
	ejectMC12_搬送モータ=OFF

	errpassMC13_搬送モータ=ON
	mMC13_搬送モータ=OFF
	ejectMC13_搬送モータ=OFF

	if timerr_MC12_搬送モータ.B then
		almMC12_搬送モータ=ON
	else if timerr_MC13_搬送モータ.B then
		almMC13_搬送モータ=ON
	end if
	
	搬送コンベアBErrStep=1

else if ldp(tim_XSW23_ストッパ上昇端.B) or ldp(tim_notXSW23_ストッパ上昇端.B) then
	errpassXSW23_ストッパ上昇端=ON
	pauseSV22_ストッパ=ON
	almXSW23_ストッパ上昇端=ON
	pnlPBXSW23_ストッパ上昇端=ON
	搬送コンベアBErrStep=1

else if ldp(tim_XSW22_ストッパ下降端.B) or ldp(tim_notXSW22_ストッパ下降端.B) then
	errpassXSW22_ストッパ下降端=ON
	almXSW22_ストッパ下降端=ON
	pnlPBXSW22_ストッパ下降端=ON
	搬送コンベアBErrStep=1

else if ldp(tim_XSW18_ストッパ上昇端.B) or ldp(tim_notXSW18_ストッパ上昇端.B) then
	errpassXSW18_ストッパ上昇端=ON
	pauseSV51_ストッパ=ON
	almXSW18_ストッパ上昇端=ON
	pnlPBXSW18_ストッパ上昇端=ON
	搬送コンベアBErrStep=1

else if ldp(tim_XSW19_ストッパ下降端.B) or ldp(tim_notXSW19_ストッパ下降端.B) then
	errpassXSW19_ストッパ下降端=ON
	almXSW22_ストッパ下降端=ON
	pnlPBXSW19_ストッパ下降端=ON
	搬送コンベアBErrStep=1

else if ldp(tim_XSW25_リフト上昇端.B) or ldp(tim_notXSW25_リフト上昇端.B) then
	errpassXSW25_リフト上昇端=ON
	pauseSV23_リフト=ON
	almXSW25_リフト上昇端=ON
	pnlPBXSW25_リフト上昇端=ON
	搬送コンベアBErrStep=1

else if ldp(tim_XSW24_リフト下降端.B) or ldp(tim_notXSW24_リフト下降端.B) then
	errpassXSW24_リフト下降端=ON
	almXSW24_リフト下降端=ON
	pnlPBXSW24_リフト下降端=ON
	搬送コンベアBErrStep=1

else if ldp(tim_XSW21_リフト上昇端.B) or ldp(tim_notXSW21_リフト上昇端.B) then
	errpassXSW21_リフト上昇端=ON
	pauseSV21_リフト=ON
	almXSW21_リフト上昇端=ON
	pnlPBXSW21_リフト上昇端=ON
	搬送コンベアBErrStep=1

else if ldp(tim_XSW20_リフト下降端.B) or ldp(tim_notXSW20_リフト下降端.B) then
	errpassXSW20_リフト下降端=ON
	almXSW20_リフト下降端=ON
	pnlPBXSW20_リフト下降端=ON
	搬送コンベアBErrStep=1

end if
'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 搬送コンベアBAutoMode	自動モード セレクトスイッチ
'System :: 搬送コンベアBAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 搬送コンベアBEmg	その場停止


if 搬送コンベアBEmgStep=0 then  
	
	if 搬送コンベアBErrStep=0  then

	if not(搬送コンベアBOrgErr) then

	
	tmr(PH11_釜検知,timdly_PH11_釜検知,2)
	tmr(PH12_フタ検知,timdly_PH12_フタ検知,2)
	tmr(PH13_釜検知,timdly_PH13_釜検知,2)
	tmr(PH14_フタ検知,timdly_PH14_フタ検知,2)
	tmr(PH15_釜検知,timdly_PH15_釜検知,10)
	tmr(PH16_フタ検知,timdly_PH16_フタ検知,10)
	
	'-----------------------------------------------------------------
	' 搬送モータ、ストッパON/OFFタイミングタスク
	'-----------------------------------------------------------------
	'搬送コンベアA SV21_リフト
	tmr(tim_SV21_リフト,tim_SV21_リフト_val)
	select case SV21_リフトstep
	case 0
		
	case 1
		PH9_釜起動検知=PH9_釜検知
		PH10_フタ起動検知=PH10_フタ検知
	
		if  PH9_釜起動検知 or PH10_フタ起動検知 then
			mSV21_リフト=OFF
			errpassXSW20_リフト下降端=OFF

			mSV51_ストッパ=OFF
			errpassXSW19_ストッパ下降端=OFF
			inc(SV21_リフトstep)
		else
			SV21_リフトstep=0
		end if
	
	case 2
'		if (errpassXSW20_リフト下降端 or XSW20_リフト下降端) and (errapssXSW19_ストッパ下降端 or XSW19_ストッパ下降端)  then
		if (errpassXSW20_リフト下降端 or ( (XSW20_リフト下降端 and not(pnlPBXSW20_リフト下降端)) or passXSW20_リフト下降端)) and ( (XSW19_ストッパ下降端 and not(pnlPBXSW19_ストッパ下降端)) or passXSW19_ストッパ下降端 or errpassXSW19_ストッパ下降端)  then
			inc(SV21_リフトstep)
		end if

	case 3
		if errpassMC12_搬送モータ or errpassMC13_搬送モータ then
			inc(SV21_リフトstep)
		end if		
		
		if not(PH9_釜検知) and not(PH10_フタ検知) and not(PH11_釜検知) and not(PH12_フタ検知) then
			inc(SV21_リフトstep)
		end if
	
	case 4
		if errpassMC12_搬送モータ or errpassMC13_搬送モータ then
			inc(SV21_リフトstep)
		end if		

		if PH9_釜起動検知 or PH10_フタ起動検知 then
			if (PH11_釜検知 and timdly_PH11_釜検知.B) or (PH12_フタ検知 and timdly_PH12_フタ検知.B) then
				inc(SV21_リフトstep)
			end if
		else
			inc(SV21_リフトstep)
		end if
	
	case 5
		mSV21_リフト=ON
		errpassXSW21_リフト上昇端=OFF

		mSV51_ストッパ=ON
		errpassXSW18_ストッパ上昇端=OFF
		inc(SV21_リフトstep)
	
	case 6
		if (errpassXSW21_リフト上昇端 or ((XSW21_リフト上昇端 and not(pnlPBXSW21_リフト上昇端)) or passXSW21_リフト上昇端)) and (errpassXSW18_ストッパ上昇端 or ((XSW18_ストッパ上昇端 and not(pnlPBXSW18_ストッパ上昇端)) or passXSW18_ストッパ上昇端)) then
			inc(SV21_リフトstep)
		end if		
	
	case 7
		搬送コンベアA排出要求=OFF
		搬送コンベアB動作中=OFF
		SV21_リフトstep=0
	end select
	
	
	'-----------------------------------------------------------------
	'注水ユニットストッパ
	tmr(tim_SV22_ストッパ,tim_SV22_ストッパ_val)
	select case SV22_ストッパstep
	case 0
	case 1
		'PH9_釜起動検知=PH9_釜検知
		'PH10_フタ起動検知=PH10_フタ検知
		PH11_釜起動検知=PH11_釜検知
		PH12_フタ起動検知=PH12_フタ検知
		
		if PH9_釜起動検知 or PH10_フタ起動検知 or PH11_釜起動検知 or PH12_フタ起動検知 then
			mSV22_ストッパ=OFF
			errpassXSW22_ストッパ下降端=OFF		
			inc(SV22_ストッパstep)
		else
			SV22_ストッパstep=0
		end if
	
	case 2
		if errpassXSW22_ストッパ下降端 or ((XSW22_ストッパ下降端 and not(pnlPBXSW22_ストッパ下降端)) or passXSW22_ストッパ下降端) then
			inc(SV22_ストッパstep)
		end if
	
	case 3
		if errpassMC12_搬送モータ or errpassMC13_搬送モータ then
			inc(SV22_ストッパstep)
		end if		

		if not(PH11_釜検知) and not(PH12_フタ検知) then
			inc(SV22_ストッパstep)
		end if
	
	case 4
		if errpassMC12_搬送モータ or errpassMC13_搬送モータ then
			inc(SV22_ストッパstep)
		end if		

		if  PH9_釜起動検知 or PH10_フタ起動検知 then
			if (PH11_釜検知 and timdly_PH11_釜検知.B) or (PH12_フタ検知 and timdly_PH12_フタ検知.B) then
				inc(SV22_ストッパstep)
			end if
		else if PH11_釜起動検知 or PH12_フタ起動検知 then
			if (PH13_釜検知 and timdly_PH13_釜検知.B) or (PH14_フタ検知 and timdly_PH14_フタ検知.B) then
				inc(SV22_ストッパstep)
			end if
		else
			inc(SV22_ストッパstep)
		end if
	
	case 5
		tim_SV22_ストッパ_val=0
		res(tim_SV22_ストッパ)
		inc(SV22_ストッパstep)
	
	case 6
		if tim_SV22_ストッパ.B then
			inc(SV22_ストッパstep)
		end if
		
	case 7
		if errpassMC12_搬送モータ or errpassMC13_搬送モータ then
			inc(SV22_ストッパstep)
		end if		

		if  PH9_釜起動検知 or PH10_フタ起動検知 then
			if (PH11_釜検知 and timdly_PH11_釜検知.B) or (PH12_フタ検知 and timdly_PH12_フタ検知.B) then
				inc(SV22_ストッパstep)
			end if
		else
			inc(SV22_ストッパstep)
		end if
	
	case 8
		mSV22_ストッパ=ON
		errpassXSW23_ストッパ上昇端=OFF
		inc(SV22_ストッパstep)

	case 9
		if mSV22_ストッパ then
			if errpassXSW23_ストッパ上昇端 or ((XSW23_ストッパ上昇端 and not(pnlPBXSW23_ストッパ上昇端)) or passXSW23_ストッパ上昇端)then
				inc(SV22_ストッパstep)
			end if
		else
			inc(SV22_ストッパstep)
		end if
	
	case 10
		tim_SV22_ストッパ_val=0
		res(tim_SV22_ストッパ)
		inc(SV22_ストッパstep)
	
	case 11
		if tim_SV22_ストッパ.B then
			inc(SV22_ストッパstep)
		end if
	
	case 12
		SV22_ストッパstep=0
		
	end select	
	'-----------------------------------------------------------------
	'MC12_搬送モータ供給
	tmr(tim_MC12_搬送モータ供給,tim_MC12_搬送モータ供給_val)
	select case MC12_搬送モータ供給step
	case 0
	case 1
		'PH9_釜起動検知=PH9_釜検知
		'PH10_フタ起動検知=PH10_フタ検知
		
		if PH9_釜起動検知 or PH10_フタ起動検知 then
			if errpassXSW22_ストッパ下降端 or ((XSW22_ストッパ下降端 and not(pnlPBXSW22_ストッパ下降端)) or passXSW22_ストッパ下降端) then
				mMC12_搬送モータ=ON
				errpassMC12_搬送モータ=OFF
				inc(MC12_搬送モータ供給step)
			end if
		else
			MC12_搬送モータ供給step=0
		end if
	
	case 2
		if errpassMC12_搬送モータ then
			inc(MC12_搬送モータ供給step)		
		end if
		
		if not(PH11_釜検知) and not(PH12_フタ検知) then
			tim_MC12_搬送モータ供給_val=25
			res(tim_MC12_搬送モータ供給)
		end if
		inc(MC12_搬送モータ供給step)
	
	case 3
		if tim_MC12_搬送モータ供給.B then
			inc(MC12_搬送モータ供給step)
		end if

	case 4
		if errpassMC12_搬送モータ then
			inc(MC12_搬送モータ供給step)		
		end if

		if not(PH9_釜検知) and not(PH10_フタ検知) then
			inc(MC12_搬送モータ供給step)
		end if
	
	case 5
		if errpassMC12_搬送モータ then
			inc(MC12_搬送モータ供給step)		
		end if

		if (PH11_釜検知 and timdly_PH11_釜検知.B) or (PH12_フタ検知 and timdly_PH12_フタ検知.B) then
			inc(MC12_搬送モータ供給step)
		end if
	
	case 6
		tim_MC12_搬送モータ供給_val=15
		res(tim_MC12_搬送モータ供給)
		inc(MC12_搬送モータ供給step)
	
	case 7
		if tim_MC12_搬送モータ供給.B then
			inc(MC12_搬送モータ供給step)
		end if

	case 8
		mMC12_搬送モータ=OFF		
		inc(MC12_搬送モータ供給step)

	case 9
		MC12_搬送モータ供給step=0

	end select
	'-----------------------------------------------------------------
	'MC12_搬送モータ排出
	tmr(tim_MC12_搬送モータ排出,tim_MC12_搬送モータ排出_val)
	select case MC12_搬送モータ排出step
	case 0
	case 1
		PH11_釜起動検知=PH11_釜検知
		PH12_フタ起動検知=PH12_フタ検知
		
		if PH11_釜起動検知 or PH12_フタ起動検知 then
			inc(MC12_搬送モータ排出step)
		else
			MC12_搬送モータ排出step=0
		end if
	
	case 2
		if not(PH13_釜検知) and not(PH14_フタ検知) then
			inc(MC12_搬送モータ排出step)
		end if			
	
	case 3
		mSV22_ストッパ=OFF
		inc(MC12_搬送モータ排出step)
	
	case 4
		if errpassXSW22_ストッパ下降端 or ((XSW22_ストッパ下降端 and not(pnlPBXSW22_ストッパ下降端)) or passXSW22_ストッパ下降端) then
			inc(MC12_搬送モータ排出step)
		end if

	case 5
		ejectMC12_搬送モータ=ON
		errpassMC12_搬送モータ=OFF
		inc(MC12_搬送モータ排出step)
	

	case 6
		if errpassMC12_搬送モータ then
			inc(MC12_搬送モータ排出step)		
		end if
		
		if not(PH11_釜検知) and not(PH12_フタ検知) then
			inc(MC12_搬送モータ排出step)
		end if
	
	case 7
		if errpassMC12_搬送モータ then
			inc(MC12_搬送モータ排出step)		
		end if

		if (PH13_釜検知 and timdly_PH13_釜検知.B) or (PH14_フタ検知 and timdly_PH14_フタ検知.B) then
			inc(MC12_搬送モータ排出step)
		end if
	
	case 8
		tim_MC12_搬送モータ排出_val=15
		res(tim_MC12_搬送モータ排出)
		inc(MC12_搬送モータ排出step)
	
	case 9
		if tim_MC12_搬送モータ排出.B then
			inc(MC12_搬送モータ排出step)
		end if
	
	case 10
		ejectMC12_搬送モータ=OFF
		inc(MC12_搬送モータ排出step)
	
	case 11
		MC12_搬送モータ排出step=0

	end select

	'-----------------------------------------------------------------
	'MC13_搬送モータ供給
	tmr(tim_MC13_搬送モータ供給,tim_MC13_搬送モータ供給_val)
	select case MC13_搬送モータ供給step
	case 0
	case 1
		PH11_釜起動検知=PH11_釜検知
		PH12_フタ起動検知=PH12_フタ検知
		
		if PH11_釜起動検知 or PH12_フタ起動検知 then
			inc(MC13_搬送モータ供給step)
		else
			MC13_搬送モータ供給step=0
		end if
	
	case 2
		if not(PH13_釜検知) and not(PH14_フタ検知) then
			inc(MC13_搬送モータ供給step)
		end if		
	
	case 3
		if PH11_釜起動検知 or PH12_フタ起動検知 then
			if errpassXSW19_ストッパ下降端 or ((XSW19_ストッパ下降端 and not(pnlPBXSW19_ストッパ下降端)) or passXSW19_ストッパ下降端) then
				inc(MC13_搬送モータ供給step)
			end if
		end if 

	case 4
		mMC13_搬送モータ=ON
		errpassMC13_搬送モータ=OFF
		inc(MC13_搬送モータ供給step)

	case 5
		if errpassMC13_搬送モータ then		
			inc(MC13_搬送モータ排出step)
		end if

		if not(PH11_釜検知) and not(PH12_フタ検知) and  not(PH13_釜検知) and not(PH14_フタ検知) then
			inc(MC13_搬送モータ供給step)
		end if
	
	case 6
		if errpassMC13_搬送モータ then		
			inc(MC13_搬送モータ排出step)
		end if

		if PH11_釜起動検知 or PH12_フタ起動検知 then
			if (PH13_釜検知 and timdly_PH13_釜検知.B) or (PH14_フタ検知 and timdly_PH14_フタ検知.B) then
				inc(MC13_搬送モータ供給step)
			end if
		else
			inc(MC13_搬送モータ供給step)
		end if
	
	case 7
		tim_MC13_搬送モータ供給_val=4
		res(tim_MC13_搬送モータ供給)
		inc(MC13_搬送モータ供給step)
	
	case 8
		if tim_MC13_搬送モータ供給.B then
			inc(MC13_搬送モータ供給step)
		end if
	
	case 9
		mMC13_搬送モータ=OFF
		inc(MC13_搬送モータ供給step)
	
	case 10
		MC13_搬送モータ供給step=0

	end select
	'-----------------------------------------------------------------
	'MC13_搬送モータ排出
	tmr(tim_MC13_搬送モータ排出,tim_MC13_搬送モータ排出_val)
	select case MC13_搬送モータ排出step
	case 0
	case 1
		PH13_釜起動検知=PH13_釜検知
		PH14_フタ起動検知=PH14_フタ検知
		
		if PH13_釜起動検知 or PH14_フタ起動検知 then
			inc(MC13_搬送モータ排出step)
		else
			MC13_搬送モータ排出step=0
		end if

	case 2
		mSV23_リフト=OFF
		errpassXSW24_リフト下降端=OFF
		inc(MC13_搬送モータ排出step)
		
	case 3
		if errpassXSW24_リフト下降端 or ((XSW24_リフト下降端 and not(pnlPBXSW24_リフト下降端)) or passXSW24_リフト下降端) then
			inc(MC13_搬送モータ排出step)
		end if
	
	case 4
		ejectMC13_搬送モータ=ON
		errpassMC13_搬送モータ=OFF
		inc(MC13_搬送モータ排出step)
	
	case 5
		if errpassMC13_搬送モータ then		
			inc(MC13_搬送モータ排出step)
		end if
		
		if not(PH13_釜検知) and not(PH14_フタ検知) then
			inc(MC13_搬送モータ排出step)
		end if
	
	case 6
		if errpassMC13_搬送モータ then
			inc(MC13_搬送モータ排出step)		
		end if
	
		if PH13_釜起動検知 or PH14_フタ起動検知 then
			if (PH15_釜検知 and timdly_PH15_釜検知.B) or (PH16_フタ検知 and timdly_PH16_フタ検知.B) then
				inc(MC13_搬送モータ排出step)
			end if
		else
			inc(MC13_搬送モータ排出step)
		end if
	case 7
		tim_MC13_搬送モータ排出_val=12
		res(tim_MC13_搬送モータ排出)
		inc(MC13_搬送モータ排出step)
	
	case 8
		if tim_MC13_搬送モータ排出.B then
			inc(MC13_搬送モータ排出step)
		end if
	
	case 9
		ejectMC13_搬送モータ=OFF
		inc(MC13_搬送モータ排出step)
	
	case 10
		搬送コンベアB排出要求=ON
		MC13_搬送モータ排出step=0

	end select
	'===================================================================================================================
	'【 リフタータスク 】
	'
	if (搬送コンベアBAutoMode and 自動搬送AutoMode ) or 搬送コンベアBstep<>0 then

		if not(搬送コンベアBAutoMode and 自動搬送AutoMode ) then
			搬送コンベアBAutoRun=OFF
		end if

		if ManualInite=1 then
			mSV22_ストッパ=ON
			mSV51_ストッパ=ON
			mSV21_リフト=ON
			ManualInite=0
		end if

		tmr(tim_procstep,tim_procstep_val)

		select case 搬送コンベアBstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 搬送コンベアBAutoRun then
				inc(搬送コンベアBstep)
			else 
				搬送コンベアBstep=0 '終了待機
			end if
		
		case 2
			if PH15_釜検知 or PH16_フタ検知 then
				搬送コンベアB動作中=OFF
				搬送コンベアB排出要求=ON
				搬送コンベアBstep=1
			else
				inc(搬送コンベアBstep)
			end if

		case 3
		' [ 次の搬送コンベア停止確認 ]
			if 搬送コンベアB排出要求=OFF and  搬送コンベアC動作中=OFF and 搬送コンベアA排出要求 then
				搬送コンベアB動作中=ON
				inc(搬送コンベアBstep)
			else
				搬送コンベアBstep=1
			end if
			
		case 4
			if 計水ユニット排出要求 then
				LatchPH9_釜検知=OFF
				LatchPH10_フタ検知=OFF
				inc(搬送コンベアBstep)
			else
				搬送コンベアBstep=1
			end if
		
		case 5
			if 搬送コンベアBOrg then
				搬送コンベアBstep=100
			else
				搬送コンベアBstep=1
			end if

		'--------------------------------------------------------------------------------------------------------------
		case 100
			if 搬送コンベアBOrg or 1 then
				errpassMC12_搬送モータ=OFF
				errpassMC13_搬送モータ=OFF
				errpassXSW20_リフト下降端=OFF
				errpassXSW19_ストッパ下降端=OFF
				inc(搬送コンベアBstep)
			else
				搬送コンベアBOrgErr=ON
			end if

		case 101
			SV21_リフトstep=1
			inc(搬送コンベアBstep)
			
		case 102
			if not(mSV21_リフト) and not(mSV51_ストッパ) then
				inc(搬送コンベアBstep)
			end if
		
		case 103
'			if (errpassXSW20_リフト下降端 or XSW20_リフト下降端) and (errapssXSW19_ストッパ下降端 or XSW19_ストッパ下降端)  then
			if (errpassXSW20_リフト下降端 or ((XSW20_リフト下降端 and not(pnlPBXSW20_リフト下降端)) or passXSW20_リフト下降端)) and (errpassXSW19_ストッパ下降端 or (XSW19_ストッパ下降端 and not(pnlPBXSW19_ストッパ下降端)) or passXSW19_ストッパ下降端) then
				inc(搬送コンベアBstep)
			end if

			
		case 104
			SV22_ストッパstep=1
			MC12_搬送モータ供給step=1
			MC12_搬送モータ排出step=1
			MC13_搬送モータ供給step=1
			MC13_搬送モータ排出step=1
			inc(搬送コンベアBstep)

		case 105
			if 	SV21_リフトstep=0 and SV22_ストッパstep=0 then
				if MC12_搬送モータ供給step=0 and MC12_搬送モータ排出step=0 and MC13_搬送モータ供給step=0 and MC13_搬送モータ排出step=0 then
					inc(搬送コンベアBstep)
				end if
			end if
 
			
		case 106
			StageDevice7=StageDevice6
			StageItem7=ANDA(StageDevice7.U,$00FF)  
		
			StageDevice6=StageDevice5
			StageItem6=ANDA(StageDevice6.U,$00FF)  
			
			StageDevice5=StageDevice4
			StageItem5=ANDA(StageDevice5.U,$00FF)  
			StageItem4=ANDA(StageDevice4.U,$00FF)

			inc(搬送コンベアBstep)
			
		case 107
			搬送コンベアB動作中=OFF
			搬送コンベアA排出要求=OFF
			計水ユニット排出要求=OFF
			搬送コンベアBstep=1

	 end select
	 
	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		if ManualInite=0 then
			mSV22_ストッパ=OFF
			mSV51_ストッパ=OFF
			ManualInite=1
		end if
	
		搬送コンベアBAutoRun=OFF
		
		搬送コンベアBstep=0 '終了

		res(tim_XSW23_ストッパ上昇端)
		res(tim_XSW22_ストッパ下降端)
		res(tim_XSW18_ストッパ上昇端)
		res(tim_XSW19_ストッパ下降端)
		res(tim_XSW25_リフト上昇端)
		res(tim_XSW24_リフト下降端)
		res(tim_notXSW23_ストッパ上昇端)
		res(tim_notXSW22_ストッパ下降端)
		res(tim_notXSW18_ストッパ上昇端)
		res(tim_notXSW19_ストッパ下降端)
		res(tim_notXSW25_リフト上昇端)
		res(tim_notXSW24_リフト下降端)
		res(timerr_MC12_搬送モータ)
		res(timerr_MC13_搬送モータ)

		
		if ldp(pnlPBMC9_モータローラ) then
			if mMC9_モータローラ then
				mMC9_モータローラ=OFF
			else
					mMC9_モータローラ=ON
			end if
		end if
		
		if ldp(pnlPBMC12_搬送モータ) then
			if mMC12_搬送モータ then
				mMC12_搬送モータ=OFF
			else
				mMC12_搬送モータ=ON
			end if
		end if
		
		if ldp(pnlPBMC13_搬送モータ) then
			if mMC13_搬送モータ then
				mMC13_搬送モータ=OFF
			else
				mMC13_搬送モータ=ON
			end if
		end if
		
		if ldp(pnlPBMC16_モータローラ) then
			if mMC16_モータローラ then
				mMC16_モータローラ=OFF
			else
				mMC16_モータローラ=ON
			end if
		end if
		
		if ldp(pnlPBSV22_ストッパ) then
			if mSV22_ストッパ then
				mSV22_ストッパ=OFF
			else
				mSV22_ストッパ=ON
			end if
		end if
		
		if ldp(pnlPBSV51_ストッパ) then
			if mSV51_ストッパ then
				mSV51_ストッパ=OFF
			else
				mSV51_ストッパ=ON
			end if
		end if
		
		if ldp(pnlPBSV21_リフト) then
			if mSV21_リフト then
				mSV21_リフト=OFF
			else
				mSV21_リフト=ON
			end if
		end if
			
	end if '搬送コンベアBAutoMode and not(搬送コンベアBOrgErrStep)

	'===================================================================================================================
	'【 搬送コンベアBOrgErr処理 】
	else
	
		res(tim_XSW23_ストッパ上昇端)
		res(tim_XSW22_ストッパ下降端)
		res(tim_XSW18_ストッパ上昇端)
		res(tim_XSW19_ストッパ下降端)
		res(tim_XSW25_リフト上昇端)
		res(tim_XSW24_リフト下降端)
		res(tim_notXSW23_ストッパ上昇端)
		res(tim_notXSW22_ストッパ下降端)
		res(tim_notXSW18_ストッパ上昇端)
		res(tim_notXSW19_ストッパ下降端)
		res(tim_notXSW25_リフト上昇端)
		res(tim_notXSW24_リフト下降端)

		if ResetFlg then
			搬送コンベアBOrgErr=OFF
		end if

	end if

	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else

		搬送コンベアBErr=ON

		pauseMC9_モータローラ=ON
		pauseMC12_搬送モータ=ON
		pauseMC13_搬送モータ=ON
		'pauseMC16_モータローラ=ON
		res(timerr_MC12_搬送モータ)
		res(timerr_MC13_搬送モータ)

		select case 搬送コンベアBErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW23_ストッパ上昇端=OFF
				almXSW22_ストッパ下降端=OFF
				almXSW21_リフト上昇端=OFF
				almXSW18_ストッパ上昇端=OFF
				almXSW19_ストッパ下降端=OFF
				almXSW25_リフト上昇端=OFF
				almXSW24_リフト下降端=OFF
				
				almMC12_搬送モータ=OFF
				almMC13_搬送モータ=OFF

				inc(搬送コンベアBErrStep)
			end if
		case 2
			搬送コンベアBErr=OFF

			pauseMC9_モータローラ=OFF
			pauseMC12_搬送モータ=OFF
			pauseMC13_搬送モータ=OFF
			'pauseMC16_モータローラ=OFF
			
			pauseSV22_ストッパ=OFF
			pauseSV51_ストッパ=OFF
			pauseSV23_リフト=OFF
			pauseSV21_リフト=OFF

			res(tim_XSW23_ストッパ上昇端)
			res(tim_XSW22_ストッパ下降端)
			res(tim_XSW18_ストッパ上昇端)
			res(tim_XSW19_ストッパ下降端)
			res(tim_XSW25_リフト上昇端)
			res(tim_XSW24_リフト下降端)
			res(tim_notXSW23_ストッパ上昇端)
			res(tim_notXSW22_ストッパ下降端)
			res(tim_notXSW18_ストッパ上昇端)
			res(tim_notXSW19_ストッパ下降端)
			res(tim_notXSW25_リフト上昇端)
			res(tim_notXSW24_リフト下降端)
			res(timerr_MC12_搬送モータ)
			res(timerr_MC13_搬送モータ)

			搬送コンベアBErrStep=0
		end select

	end if 'if 搬送コンベアBErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case 搬送コンベアBEmgStep
	case 0
	
	case 1
		搬送コンベアBAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (搬送コンベアBAutoMode and 自動搬送AutoMode ) or 搬送コンベアBstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseMC12_搬送モータ=ON
			pauseMC13_搬送モータ=ON
						
			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				tim_SV51_ストッパ_stack=tim_SV51_ストッパ.U
				tim_MC12_搬送モータ供給_stack=tim_MC12_搬送モータ供給.U
				tim_MC12_搬送モータ排出_stack=tim_MC12_搬送モータ排出.U
				tim_MC13_搬送モータ供給_stack=tim_MC13_搬送モータ供給.U
				tim_MC13_搬送モータ排出_stack=tim_MC13_搬送モータ排出.U
				tim_MC16_モータローラ_stack=tim_MC16_モータローラ.U
				tim_MC9_モータローラ_stack=tim_MC9_モータローラ.U
				tim_SV21_リフト_stack=tim_SV21_リフト.U
				tim_SV22_ストッパ_stack=tim_SV22_ストッパ.U
			
				tim_PH9_釜検知_stack=tim_PH9_釜検知.U
				tim_PH10_フタ検知_stack=tim_PH10_フタ検知.U
				timdly_PH11_釜検知_stack=timdly_PH11_釜検知.U
				timdly_PH12_フタ検知_stack=timdly_PH12_フタ検知.U
				timdly_PH13_釜検知_stack=timdly_PH13_釜検知.U
				timdly_PH14_フタ検知_stack=timdly_PH14_フタ検知.U
				timdly_PH15_釜検知_stack=timdly_PH15_釜検知.U
				timdly_PH16_フタ検知_stack=timdly_PH16_フタ検知.U

				timstack=ON
			end if
			
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC9_モータローラ=OFF
			mMC12_搬送モータ=OFF
			mMC13_搬送モータ=OFF
			mMC16_モータローラ=OFF
			mSV22_ストッパ=OFF
			mSV51_ストッパ=OFF
			mSV21_リフト=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(搬送コンベアBEmgStep)
	case 2
		if ResetFlg then
			inc(搬送コンベアBEmgStep)
		end if
	case 3
		if (搬送コンベアBAutoMode and 自動搬送AutoMode ) or 搬送コンベアBstep<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseMC12_搬送モータ=OFF
				pauseMC13_搬送モータ=OFF

				tim_procstep.U=tim_procstep_stack
				tim_SV51_ストッパ.U=tim_SV51_ストッパ_stack
				tim_MC12_搬送モータ供給.U=tim_MC12_搬送モータ供給_stack
				tim_MC12_搬送モータ排出.U=tim_MC12_搬送モータ排出_stack
				tim_MC13_搬送モータ供給.U=tim_MC13_搬送モータ供給_stack
				tim_MC13_搬送モータ排出.U=tim_MC13_搬送モータ排出_stack
				tim_MC16_モータローラ.U=tim_MC16_モータローラ_stack
				tim_MC9_モータローラ.U=tim_MC9_モータローラ_stack
				tim_SV21_リフト.U=tim_SV21_リフト_stack
				tim_SV22_ストッパ.U=tim_SV22_ストッパ_stack

				res(tim_PH9_釜検知)
				res(tim_PH10_フタ検知)
				res(timdly_PH11_釜検知)
				res(timdly_PH12_フタ検知)
				res(timdly_PH13_釜検知)
				res(timdly_PH14_フタ検知)
				res(timdly_PH15_釜検知)
				res(timdly_PH16_フタ検知)
				'---------------------------------
				inc(搬送コンベアBEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(搬送コンベアBEmgStep)		
		end if				
	case 4
		timstack=OFF
		搬送コンベアBEmgStep=0
		搬送コンベアBEmg=OFF
	end select

end if 'if 搬送コンベアBEmgStep=0 then
