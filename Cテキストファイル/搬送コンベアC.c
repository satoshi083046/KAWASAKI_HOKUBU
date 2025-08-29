'搬送コンベアC
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	搬送コンベアC
'
'-------------------------------------------------------
' [ 7 ]
' (PH15_釜検知)			-> (PH15_釜検知)
' (PH16_フタ検知)		-> (PH16_フタ検知)
'-------- 
' SV33_リフト			-> SV23_リフト
' XSW38_リフト上昇端	-> XSW25_リフト上昇端
' XSW37_リフト下降端	-> XSW24_リフト下降端
'--------
' SV65_ストッパ			->  ( 削除 )
' XSW75_ストッパ上昇端	->  ( 削除 )
' XSW74_ストッパ下降端	->  ( 削除 )
'-------------------------------------------------------
' [ 8 ]
' PH17_釜検知	-> (PH17_釜検知)
' PH18_フタ検知	-> (PH18_フタ検知)
'--------
' SV29_ストッパ			->  SV25_ストッパ		
' XSW30_ストッパ上昇端	->  XSW29_ストッパ上昇端
' XSW29_ストッパ下降端	->  XSW28_ストッパ下降端
'--------
' SV31_クランプ			->  SV24_クランプ		
' XSW34_クランプ上昇端	->  XSW27_クランプ上昇端
' XSW33_クランプ下降端	->  XSW26_クランプ下降端
'-------------------------------------------------------
' [ 9 ]
' PH19_釜検知	-> (PH19_釜検知)
' PH20_フタ検知	-> (PH20_フタ検知)
'--------
' SV30_ストッパ			->  SV27_ストッパ		
' XSW32_ストッパ上昇端	->  XSW33_ストッパ上昇端
' XSW31_ストッパ下降端	->  XSW32_ストッパ下降端
'--------
' SV32_クランプ			->  SV26_クランプ		
' XSW36_クランプ上昇端	->  XSW31_クランプ上昇端
' XSW35_クランプ下降端	->  XSW30_クランプ下降端
'-------------------------------------------------------
' [ 10 ]
' 	( 新規 )	-> PH21_釜検知
'
'-------------------------------------------------------
' [ 11 ]
' PH54_釜送りトリガ	-> PH22_釜検知
'--------
' 	( 新規 )		-> SV29_ストッパ
' 	( 新規 )		-> XSW37_ストッパ上昇端
' 	( 新規 )		-> XSW36_ストッパ下降端
'--------
' 	( 新規 )		-> SV28_リフト
' 	( 新規 )		-> XSW34_リフト上昇端
' 	( 新規 )		-> XSW35_リフト下降端
'-------------------------------------------------------
'
'===================================================================================================================
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理

    搬送コンベアCAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    搬送コンベアCAutoRun=OFF
    搬送コンベアC許可=ON
    搬送コンベアCOrgErr=OFF
    搬送コンベアCErr=OFF
    搬送コンベアCEmg=OFF
    搬送コンベアCstep=0
    搬送コンベアCErrStep=0
    搬送コンベアCOrgErrStep=0
    搬送コンベアCEmgStep=0

	SV25_ストッパstep=0
	SV27_ストッパstep=0
	MC16_モータローラstep=0
	MC14_搬送モータstep=0
	MC15_搬送モータstep=0

	if SSW3_自動モード then	
		ManualInite=1
	else
		ManualInite=0	
	end if
	
end if
'===================================================================================================================
'【 原点 】
搬送コンベアCOrg= ((XSW28_ストッパ下降端 and not(pnlPBXSW28_ストッパ下降端)) or passXSW28_ストッパ下降端) or ((XSW29_ストッパ上昇端 and not(pnlPBXSW29_ストッパ上昇端)) or passXSW29_ストッパ上昇端) 
搬送コンベアCOrg= 搬送コンベアCOrg and (((XSW32_ストッパ下降端 and not(pnlPBXSW32_ストッパ下降端)) or passXSW32_ストッパ下降端) or ((XSW33_ストッパ上昇端 and not(pnlPBXSW33_ストッパ上昇端)) or passXSW33_ストッパ上昇端))
搬送コンベアCOrg= 搬送コンベアCOrg and (((XSW26_クランプ下降端 and not(pnlPBXSW26_クランプ下降端)) or passXSW26_クランプ下降端) or ((XSW27_クランプ上昇端 and not(pnlPBXSW27_クランプ上昇端)) or passXSW27_クランプ上昇端))
搬送コンベアCOrg= 搬送コンベアCOrg and (((XSW30_クランプ下降端 and not(pnlPBXSW30_クランプ下降端)) or passXSW30_クランプ下降端) or ((XSW31_クランプ上昇端 and not(pnlPBXSW31_クランプ上昇端)) or passXSW31_クランプ上昇端))


'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	搬送コンベアCEmg=ON
	搬送コンベアCEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】

tmr(not(SV24_クランプ) and not(XSW26_クランプ下降端) and not(pnlPBXSW26_クランプ下降端),tim_notXSW26_クランプ下降端,#30)
tmr(SV24_クランプ and not(XSW27_クランプ上昇端) and not(pnlPBXSW27_クランプ上昇端),tim_notXSW27_クランプ上昇端,#30)
tmr(not(SV25_ストッパ) and not(XSW28_ストッパ下降端) and not(pnlPBXSW28_ストッパ下降端), tim_notXSW28_ストッパ下降端,#30)
tmr(SV25_ストッパ and not(XSW29_ストッパ上昇端) and not(pnlPBXSW29_ストッパ上昇端), tim_notXSW29_ストッパ上昇端,#30)
tmr(not(SV26_クランプ) and not(XSW30_クランプ下降端) and not(pnlPBXSW30_クランプ下降端), tim_notXSW30_クランプ下降端, #30)
tmr(SV26_クランプ and not(XSW31_クランプ上昇端) and not(pnlPBXSW31_クランプ上昇端), tim_notXSW31_クランプ上昇端,#30)
tmr(not(SV27_ストッパ) and not(XSW32_ストッパ下降端) and not(pnlPBXSW32_ストッパ下降端),tim_notXSW32_ストッパ下降端,#30)
tmr(SV27_ストッパ and not(XSW33_ストッパ上昇端) and not(pnlPBXSW33_ストッパ上昇端),tim_notXSW33_ストッパ上昇端,#30)
tmr(not(SV23_リフト) and not(XSW24_リフト下降端) and not(pnlPBXSW24_リフト下降端),tim_notXSW24_リフト下降端,#50)
tmr(SV23_リフト and not(XSW25_リフト上昇端) and not(pnlPBXSW25_リフト上昇端),tim_notXSW25_リフト上昇端,#50)
' stage [11]
tmr(not(SV29_ストッパ) and not(XSW36_ストッパ下降端) and not(pnlPBXSW36_ストッパ下降端),tim_notXSW36_ストッパ下降端,#30)
tmr(SV29_ストッパ and not(XSW37_ストッパ上昇端) and not(pnlPBXSW37_ストッパ上昇端),tim_notXSW37_ストッパ上昇端,#30)

'---------------------------------------------------------------------------------------------------------------------
'tmr(SV24_クランプ and XSW26_クランプ下降端 and not(pnlPBXSW26_クランプ下降端),tim_XSW26_クランプ下降端,#20)
if LDF(SV24_クランプ) and XSW26_クランプ下降端 and not(pnlPBXSW26_クランプ下降端) and not(pauseSV24_クランプ) then
	SET(tim_XSW26_クランプ下降端)
end if
'tmr(not(SV24_クランプ) and XSW27_クランプ上昇端 and not(pnlPBXSW27_クランプ上昇端),tim_XSW27_クランプ上昇端,#20)
if LDP(SV24_クランプ) and XSW27_クランプ上昇端 and not(pnlPBXSW27_クランプ上昇端) then 
	SET(tim_XSW27_クランプ上昇端) 
end if
'tmr(SV25_ストッパ and XSW28_ストッパ下降端 and not(pnlPBXSW28_ストッパ下降端), tim_XSW28_ストッパ下降端,#20)
if LDF(SV25_ストッパ) and XSW28_ストッパ下降端 and not(pnlPBXSW28_ストッパ下降端) and not(pauseSV25_ストッパ) then
	SET(tim_XSW28_ストッパ下降端)
end if
'tmr(not(SV25_ストッパ) and XSW29_ストッパ上昇端 and not(pnlPBXSW29_ストッパ上昇端), tim_XSW29_ストッパ上昇端,#20)
if LDP(SV25_ストッパ) and XSW29_ストッパ上昇端 and not(pnlPBXSW29_ストッパ上昇端) then
	SET(tim_XSW29_ストッパ上昇端)
end if
'tmr(SV26_クランプ and XSW30_クランプ下降端 and not(pnlPBXSW30_クランプ下降端), tim_XSW30_クランプ下降端, #20)
if LDF(SV26_クランプ) and XSW30_クランプ下降端 and not(pnlPBXSW30_クランプ下降端) and not(pauseSV26_クランプ) then
	SET(tim_XSW30_クランプ下降端)
end if
'tmr(not(SV26_クランプ) and XSW31_クランプ上昇端 and not(pnlPBXSW31_クランプ上昇端), tim_XSW31_クランプ上昇端,#20)
if LDP(SV26_クランプ) and XSW31_クランプ上昇端 and not(pnlPBXSW31_クランプ上昇端) then
	SET(tim_XSW31_クランプ上昇端)
end if
'tmr(SV27_ストッパ and XSW32_ストッパ下降端 and not(pnlPBXSW32_ストッパ下降端),tim_XSW32_ストッパ下降端,#20)
if LDF(SV27_ストッパ) and XSW32_ストッパ下降端 and not(pnlPBXSW32_ストッパ下降端) and not(pauseSV27_ストッパ) then
	SET(tim_XSW32_ストッパ下降端)
end if
'tmr(not(SV27_ストッパ) and XSW33_ストッパ上昇端 and not(pnlPBXSW33_ストッパ上昇端),tim_XSW33_ストッパ上昇端,#20)
if LDP(SV27_ストッパ) and XSW33_ストッパ上昇端 and not(pnlPBXSW33_ストッパ上昇端) then
	SET(tim_XSW33_ストッパ上昇端)
end if
'tmr(SV23_リフト and XSW24_リフト下降端 and not(pnlPBXSW24_リフト下降端),tim_XSW24_リフト下降端,#20)
if LDF(SV23_リフト) and XSW24_リフト下降端 and not(pnlPBXSW24_リフト下降端) and not(pauseSV28_リフト) then
	SET(tim_XSW24_リフト下降端)
end if
'tmr(not(SV23_リフト) and XSW25_リフト上昇端 and not(pnlPBXSW25_リフト上昇端),tim_XSW25_リフト上昇端,#20)
if LDP(SV23_リフト) and XSW25_リフト上昇端 and not(pnlPBXSW25_リフト上昇端) then
	SET(tim_XSW25_リフト上昇端)
end if
'tmr(SV29_ストッパ and XSW36_ストッパ下降端 and not(pnlPBXSW36_ストッパ下降端),tim_XSW36_ストッパ下降端,#10)
if LDF(SV29_ストッパ) and XSW36_ストッパ下降端 and not(pnlPBXSW36_ストッパ下降端) and not(pauseSV29_ストッパ) then
	SET(tim_XSW36_ストッパ下降端)
end if
'tmr(not(SV29_ストッパ) and XSW37_ストッパ上昇端 and not(pnlPBXSW37_ストッパ上昇端),tim_XSW37_ストッパ上昇端,#10)
if LDP(SV29_ストッパ) and XSW37_ストッパ上昇端 and not(pnlPBXSW37_ストッパ上昇端) then
	SET(tim_XSW37_ストッパ上昇端)
end if
'---------------------------------------------------------------------------------------------------------------------



tms(not(SV24_クランプ),passtimXSW26_クランプ下降端,passtimXSW26_クランプ下降端_val)
tms(SV24_クランプ,passtimXSW27_クランプ上昇端,passtimXSW27_クランプ上昇端_val)
tms(not(SV25_ストッパ),passtimXSW28_ストッパ下降端,passtimXSW28_ストッパ下降端_val)
tms(SV25_ストッパ,passtimXSW29_ストッパ上昇端,passtimXSW29_ストッパ上昇端_val)
tms(not(SV26_クランプ),passtimXSW30_クランプ下降端,passtimXSW30_クランプ下降端_val)
tms(SV26_クランプ,passtimXSW31_クランプ上昇端,passtimXSW31_クランプ上昇端_val)
tms(not(SV27_ストッパ),passtimXSW32_ストッパ下降端,passtimXSW32_ストッパ下降端_val)
tms(SV27_ストッパ,passtimXSW33_ストッパ上昇端,passtimXSW33_ストッパ上昇端_val)
'tms(not(SV23_リフト),passtimXSW24_リフト下降端,passtimXSW24_リフト下降端_val)
'tms(SV23_リフト,passtimXSW25_リフト上昇端,passtimXSW25_リフト上昇端_val)
' stage [11]
tms(not(SV29_ストッパ),passtimXSW36_ストッパ下降端,passtimXSW36_ストッパ下降端_val)
tms(SV29_ストッパ,passtimXSW37_ストッパ上昇端,passtimXSW37_ストッパ上昇端_val)


tmr(MC16_モータローラ,timerr_MC16_モータローラ,#120)
tmr(MC14_搬送モータ,timerr_MC14_搬送モータ,#120)
'--------- フタ被せユニットから搬送されたPH21_釜検知位置のフタが排除されないで残っている  -----
tmr(フタ搬送中 and PH21_釜検知,timerr_PH21フタ有,30)
コンベアC2フタ有=timerr_PH21フタ有.B


if ldp(timerr_MC16_モータローラ.B) then
	errpassMC16_モータローラ=ON
	errpassMC14_搬送モータ=ON
	mMC14_搬送モータ=OFF
	mMC16_モータローラ=OFF
	almMC16_モータローラ=ON
	搬送コンベアCErrStep=1

else if ldp(timerr_MC14_搬送モータ.B) then
	errpassMC16_モータローラ=ON
	errpassMC14_搬送モータ=ON
	mMC14_搬送モータ=OFF
	mMC16_モータローラ=OFF
	almMC14_搬送モータ=ON
	搬送コンベアCErrStep=1

else if ldp(tim_XSW26_クランプ下降端.B) or ldp(tim_notXSW26_クランプ下降端.B) then
	errpassXSW26_クランプ下降端=ON
	almXSW26_クランプ下降端=ON
	pnlPBXSW26_クランプ下降端=ON
	搬送コンベアCErrStep=1

else if ldp(tim_XSW27_クランプ上昇端.B) or ldp(tim_notXSW27_クランプ上昇端.B) then
	errpassXSW27_クランプ上昇端=ON
	pauseSV24_クランプ=ON
	almXSW27_クランプ上昇端=ON
	pnlPBXSW27_クランプ上昇端=ON
	搬送コンベアCErrStep=1

else if ldp(tim_XSW28_ストッパ下降端.B) or ldp(tim_notXSW28_ストッパ下降端.B) then
	errpassXSW28_ストッパ下降端=ON
	almXSW28_ストッパ下降端=ON
	pnlPBXSW28_ストッパ下降端=ON
	搬送コンベアCErrStep=1

else if ldp(tim_XSW29_ストッパ上昇端.B) or ldp(tim_notXSW29_ストッパ上昇端.B) then
	errpassXSW29_ストッパ上昇端=ON
	pauseSV25_ストッパ=ON
	almXSW29_ストッパ上昇端=ON
	pnlPBXSW29_ストッパ上昇端=ON
	搬送コンベアCErrStep=1
	
else if ldp(tim_XSW30_クランプ下降端.B) or ldp(tim_notXSW30_クランプ下降端.B) then
	errpassXSW30_クランプ下降端=ON
	almXSW30_クランプ下降端=ON
	pnlPBXSW30_クランプ下降端=ON
	搬送コンベアCErrStep=1

else if ldp(tim_XSW31_クランプ上昇端.B) or ldp(tim_notXSW31_クランプ上昇端.B) then
	errpassXSW31_クランプ上昇端=ON
	pauseSV26_クランプ=ON
	almXSW31_クランプ上昇端=ON
	pnlPBXSW31_クランプ上昇端=ON
	搬送コンベアCErrStep=1	

else if ldp(tim_XSW32_ストッパ下降端.B) or ldp(tim_notXSW32_ストッパ下降端.B) then
	errpassXSW32_ストッパ下降端=ON
	almXSW32_ストッパ下降端=ON
	pnlPBXSW32_ストッパ下降端=ON
	搬送コンベアCErrStep=1

else if ldp(tim_XSW33_ストッパ上昇端.B) or ldp(tim_notXSW33_ストッパ上昇端.B) then
	errpassXSW33_ストッパ上昇端=ON
	pauseSV27_ストッパ=ON
	almXSW33_ストッパ上昇端=ON
	pnlPBXSW33_ストッパ上昇端=ON
	搬送コンベアCErrStep=1

else if ldp(tim_XSW24_リフト下降端) or ldp(tim_notXSW24_リフト下降端) then
	errpassXSW24_リフト下降端=ON
	almXSW24_リフト下降端=ON
	pnlPBXSW24_リフト下降端=ON
	搬送コンベアCErrStep=1

else if ldp(tim_XSW25_リフト上昇端) or ldp(tim_notXSW25_リフト上昇端) then
	errpassXSW25_リフト上昇端=ON
	almXSW25_リフト上昇端=ON
	pnlPBXSW25_リフト上昇端=ON
	搬送コンベアCErrStep=1

'-- stage [11]
else if ldp(tim_XSW36_ストッパ下降端.B) or ldp(tim_notXSW36_ストッパ下降端.B) then
	errpassXSW36_ストッパ下降端=ON
	almXSW36_ストッパ下降端=ON
	pnlPBXSW36_ストッパ下降端=ON
	搬送コンベアCErrStep=1

else if ldp(tim_XSW37_ストッパ上昇端.B) or ldp(tim_notXSW37_ストッパ上昇端.B) then
	errpassXSW37_ストッパ上昇端=ON
	pauseSV29_ストッパ=ON
	almXSW37_ストッパ上昇端=ON
	pnlPBXSW37_ストッパ上昇端=ON
	搬送コンベアCErrStep=1

end if

	

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 搬送コンベアCAutoMode	自動モード セレクトスイッチ
'System :: 搬送コンベアCAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 搬送コンベアCEmg	その場停止


if 搬送コンベアCEmgStep=0 then  
	
	if 搬送コンベアCErrStep=0  then

	if not(搬送コンベアCOrgErr) then

	if (搬送コンベアCAutoMode and 自動搬送AutoMode ) or 搬送コンベアCstep<>0 then
	
		timstack=OFF
		
		if ManualInite=1 then		
			mSV25_ストッパ=ON
			mSV27_ストッパ=ON
			ManualInite=0
		end if
	
		if not(搬送コンベアCAutoMode and 自動搬送AutoMode ) then
			搬送コンベアCAutoRun=OFF
		end if
	
	tmr(PH17_釜検知,timdly_PH17_釜検知,2)
	tmr(PH18_フタ検知,timdly_PH18_フタ検知,2)
	tmr(PH19_釜検知,timdly_PH19_釜検知,2)
	tmr(PH20_フタ検知,timdly_PH20_フタ検知,2)
	tmr(PH21_釜検知,timdly_PH21_釜検知,2)
	
	'-----------------------------------------------------------------
	' ストッパON/OFFタイミングタスク
	'-----------------------------------------------------------------
	tmr(tim_SV25_ストッパ,tim_SV25_ストッパ_val) 'ならしストッパ、クランプ
	select case SV25_ストッパstep
	case 0
		
	case 1
		PH15_釜起動検知=LatchPH15_釜検知
		PH16_フタ起動検知=LatchPH16_フタ検知
		PH17_釜起動検知=PH17_釜検知
		PH18_フタ起動検知=PH18_フタ検知
		
		if LatchPH15_釜検知 or LatchPH16_フタ検知 or PH17_釜検知 or PH18_フタ検知 then '前のステージ(搬送コンベアBリフト）
			
			mSV25_ストッパ=OFF 'ストッパ下降
			mSV24_クランプ=OFF 'クランプ下降
			errpassXSW28_ストッパ下降端=OFF
			errpassXSW26_クランプ下降端=OFF

			inc(SV25_ストッパstep)
		else
			SV25_ストッパstep=0
		end if
		
	case 2
		if  (errpassXSW28_ストッパ下降端 or ((XSW28_ストッパ下降端 and not(pnlPBXSW28_ストッパ下降端)) or passXSW28_ストッパ下降端)) and (errpassXSW26_クランプ下降端 or ((XSW26_クランプ下降端 and not(pnlPBXSW26_クランプ下降端)) or passXSW26_クランプ下降端)) then 			
			inc(SV25_ストッパstep)
		end if
	
	case 3
		if not(PH17_釜検知) and not(PH18_フタ検知) then
			inc(SV25_ストッパstep)
		end if
		
	case 4
		tim_SV25_ストッパ_val=35
		res(tim_SV25_ストッパ)
		inc(SV25_ストッパstep)

	case 5
		if tim_SV25_ストッパ.B then
			inc(SV25_ストッパstep)
		end if
	
	case 6
		mSV25_ストッパ=ON 'ストッパ上昇
		errpassXSW29_ストッパ上昇端=OFF
		inc(SV25_ストッパstep)

	case 7
		if errpassXSW29_ストッパ上昇端 or ( (XSW29_ストッパ上昇端 and not(pnlPBXSW29_ストッパ上昇端)) or passXSW29_ストッパ上昇端) then
			inc(SV25_ストッパstep)
		end if		
		

	case 8
		if errpassMC16_モータローラ or errpassMC14_搬送モータ then
			inc(SV25_ストッパstep)
		else if PH15_釜起動検知 or PH16_フタ起動検知 then
			if (PH17_釜検知 and timdly_PH17_釜検知.B) or (PH18_フタ検知 and timdly_PH18_フタ検知.B) then
				inc(SV25_ストッパstep)
			end if
		else if PH17_釜起動検知 or PH18_フタ起動検知 then
			if (PH19_釜検知 and timdly_PH19_釜検知.B) or (PH20_フタ検知 and timdly_PH20_フタ検知.B) then
				inc(SV25_ストッパstep)
			end if
		else
			inc(SV25_ストッパstep)		
		end if
		
	case 9
		mSV25_ストッパ=ON 'ストッパ上昇
		errpassXSW29_ストッパ上昇端=OFF
		inc(SV25_ストッパstep)

	case 10
		if (errpassXSW29_ストッパ上昇端 or ( (XSW29_ストッパ上昇端 and not(pnlPBXSW29_ストッパ上昇端)) or passXSW29_ストッパ上昇端) ) then		
			inc(SV25_ストッパstep)
		end if
		
	case 11
		tim_SV25_ストッパ_val=10 
		res(tim_SV25_ストッパ)
		inc(SV25_ストッパstep)
	
	case 12
		if tim_SV25_ストッパ.B then
			inc(SV25_ストッパstep)
		end if

	case 13
		if PH17_釜検知 or PH18_フタ検知 then
			mSV24_クランプ=ON 'クランプ上昇			
			errpassXSW27_クランプ上昇端=OFF
			inc(SV25_ストッパstep)
		else
			inc(SV25_ストッパstep)
		end if
		
	case 14
		if mSV24_クランプ then
			if errpassXSW27_クランプ上昇端 or ((XSW27_クランプ上昇端 and not(pnlPBXSW27_クランプ上昇端)) or passXSW27_クランプ上昇端) then
				inc(SV25_ストッパstep)
			end if
		else
			inc(SV25_ストッパstep)
		end if

	case 15
		SV25_ストッパstep=0

	end select	
	'--------------------------------------------
	tmr(tim_SV27_ストッパ, tim_SV27_ストッパ_val) 'フタ被せストッパー、クランプ
	select case SV27_ストッパstep
	case 0

	case 1
		PH17_釜起動検知=PH17_釜検知
		PH18_フタ起動検知=PH18_フタ検知
		PH19_釜起動検知=PH19_釜検知
		PH20_フタ起動検知=PH20_フタ検知
		
		if PH17_釜検知 or PH18_フタ検知 or PH19_釜検知 or PH20_フタ検知 then 
			mSV26_クランプ=OFF '下降
			mSV27_ストッパ=OFF '下降	
			errpassXSW32_ストッパ下降端=OFF
			errpassXSW30_クランプ下降端=OFF
			inc(SV27_ストッパstep)
		else
			SV27_ストッパstep=0
		end if
		
	case 2
		if (errpassXSW32_ストッパ下降端 or ((XSW32_ストッパ下降端 and not(pnlPBXSW32_ストッパ下降端)) or passXSW32_ストッパ下降端)) and (errpassXSW30_クランプ下降端 or ((XSW30_クランプ下降端 and not(pnlPBXSW30_クランプ下降端)) or passXSW30_クランプ下降端)) then 
			inc(SV27_ストッパstep)
		end if
	
	case 3
		if not(PH19_釜検知) and not(PH20_フタ検知) then		
			inc(SV27_ストッパstep)
		end if
	
	case 4
		tim_SV27_ストッパ_val=35
		res(tim_SV27_ストッパ)
		inc(SV27_ストッパstep)

	case 5
		if tim_SV27_ストッパ.B then
			inc(SV27_ストッパstep)
		end if
	
	case 6
		mSV27_ストッパ=ON '上昇	
		errpassXSW33_ストッパ上昇端=OFF
		inc(SV27_ストッパstep)
	
	case 7
		if errpassXSW33_ストッパ上昇端 or ((XSW33_ストッパ上昇端 and not(pnlPBXSW33_ストッパ上昇端)) or passXSW33_ストッパ上昇端) then
			inc(SV27_ストッパstep)
		end if

	case 8
		if errpassMC16_モータローラ or errpassMC14_搬送モータ then
			inc(SV27_ストッパstep)				
		else if PH17_釜起動検知 or PH18_フタ起動検知 then			
			if (PH19_釜検知 and timdly_PH19_釜検知.B) or (PH20_フタ検知 and timdly_PH20_フタ検知.B) then
				inc(SV27_ストッパstep)
			end if
		else
			inc(SV27_ストッパstep)		
		end if
		
	case 9
		if errpassMC16_モータローラ or errpassMC14_搬送モータ then
			inc(SV27_ストッパstep)		
		else if PH19_釜起動検知 or PH20_フタ起動検知 then
			if PH21_釜検知 and timdly_PH21_釜検知 then
				inc(SV27_ストッパstep)
			end if
		else
			inc(SV27_ストッパstep)
		end if	
		
	case 10
		mSV27_ストッパ=ON '上昇	
		errpassXSW33_ストッパ上昇端=OFF
		inc(SV27_ストッパstep)
	
	case 11
		if errpassXSW33_ストッパ上昇端 or ((XSW33_ストッパ上昇端 and not(pnlPBXSW33_ストッパ上昇端)) or passXSW33_ストッパ上昇端) then
			inc(SV27_ストッパstep)
		end if

	case 12
		tim_SV27_ストッパ_val=10 'クランプ上昇タイミング
		res(tim_SV27_ストッパ)
		inc(SV27_ストッパstep)
	
	case 13
		if tim_SV27_ストッパ.B then
			inc(SV27_ストッパstep)
		end if
	
	case 14
		if 蓋被せユニット許可 and (PH19_釜検知 or PH20_フタ検知) then
			mSV26_クランプ=ON '上昇
			errpassXSW31_クランプ上昇端=OFF
			inc(SV27_ストッパstep)
		else
			inc(SV27_ストッパstep)
		end if
	
	case 15
		if mSV26_クランプ then
			if errpassXSW31_クランプ上昇端 or ((XSW31_クランプ上昇端 and not(pnlPBXSW31_クランプ上昇端)) or passXSW31_クランプ上昇端) then
				inc(SV27_ストッパstep)
			end if
		else
			inc(SV27_ストッパstep)
		end if
		
	case 16
		SV27_ストッパstep=0

	end select

	'--------------------------------------------
	'MC16_モータローラ
	tmr(tim_MC16_モータローラ,tim_MC16_モータローラ_val)

	
	select case MC16_モータローラstep
	case 0

	case 1
		if LatchPH15_釜検知 or LatchPH16_フタ検知 then
				mSV23_リフト=ON 'リフト下降
				errpassXSW25_リフト上昇端=OFF
				inc(MC16_モータローラstep)
		else 
			MC16_モータローラstep=0
		end if
		
	case 2
		if errpassXSW25_リフト上昇端 or ((XSW25_リフト上昇端 and not(pnlPBXSW25_リフト上昇端)) or passXSW25_リフト上昇端) then
			inc(MC16_モータローラstep)
		end if

	case 3
		if (errpassXSW26_クランプ下降端 or ( (XSW26_クランプ下降端 and not(pnlPBXSW26_クランプ下降端)) or passXSW26_クランプ下降端) ) then		
			inc(MC16_モータローラstep)
		end if
	
	case 4
		if (errpassXSW28_ストッパ下降端 or ( (XSW28_ストッパ下降端 and not(pnlPBXSW28_ストッパ下降端)) or passXSW28_ストッパ下降端) ) then		
			inc(MC16_モータローラstep)
		end if
	
	case 5
		if (errpassXSW28_ストッパ下降端 or ( (XSW28_ストッパ下降端 and not(pnlPBXSW28_ストッパ下降端)) or passXSW28_ストッパ下降端) ) then		
			inc(MC16_モータローラstep)
		end if
		
	case 6	
		if (errpassXSW30_クランプ下降端 or ( (XSW30_クランプ下降端 and not(pnlPBXSW30_クランプ下降端)) or passXSW30_クランプ下降端) ) then		
			inc(MC16_モータローラstep)
		end if
	
	case 7	
		if (errpassXSW32_ストッパ下降端 or ( (XSW32_ストッパ下降端 and not(pnlPBXSW32_ストッパ下降端)) or passXSW32_ストッパ下降端) ) then		
			inc(MC16_モータローラstep)
		end if
	
	case 8	
		mMC16_モータローラ=ON
		errpassMC16_モータローラ=OFF
		inc(MC16_モータローラstep)
		
	case 9
		if (not(PH15_釜検知) and not(PH16_フタ検知) and not(PH17_釜検知) and not(PH18_フタ検知)) or errpassMC16_モータローラ then
			inc(MC16_モータローラstep)
		end if
	
	case 10
		if PH15_釜起動検知 or PH16_フタ起動検知 then
			if (PH17_釜検知 and timdly_PH17_釜検知.B) or (PH18_フタ検知 and timdly_PH18_フタ検知.B) or errpassMC16_モータローラ then
				inc(MC16_モータローラstep)
			end if
		end if
	
	case 11
		tim_MC16_モータローラ_val=10
		res(tim_MC16_モータローラ)
		inc(MC16_モータローラstep)
	
	case 12
		if tim_MC16_モータローラ.B then
			inc(MC16_モータローラstep)
		end if
	
	case 13
		mMC16_モータローラ=OFF
		inc(MC16_モータローラstep)
		
	case 14
		mSV23_リフト=OFF 'リフト下降
		errpassXSW24_リフト下降端=OFF
		inc(MC16_モータローラstep)

	case 15
		if	errpassXSW24_リフト下降端 or ((XSW24_リフト下降端 and not(pnlPBXSW24_リフト下降端)) or passXSW24_リフト下降端) then
			inc(MC16_モータローラstep)
		end if

	case 16
		搬送コンベアB排出要求=OFF
		MC16_モータローラstep=0
	
	end select
	'--------------------------------------------
	'MC14_搬送モータ
	tmr(tim_MC14_搬送モータ,tim_MC14_搬送モータ_val)
	
	select case MC14_搬送モータstep
	case 0
	
	case 1
		inc(MC14_搬送モータstep)
		
	case 2
		PH15_釜起動検知=LatchPH15_釜検知
		PH16_フタ起動検知=LatchPH16_フタ検知
		PH17_釜起動検知=PH17_釜検知
		PH18_フタ起動検知=PH18_フタ検知
		PH19_釜起動検知=PH19_釜検知
		PH20_フタ起動検知=PH20_フタ検知
		
		if LatchPH15_釜検知 or LatchPH16_フタ検知 or PH17_釜検知 or PH18_フタ検知 or PH19_釜検知 or PH20_フタ検知 then
			inc(MC14_搬送モータstep)
		else
			MC14_搬送モータstep=0
		end if
	
	case 3
		if PH17_釜検知 or PH18_フタ検知 then
			if  (errpassXSW28_ストッパ下降端 or ((XSW28_ストッパ下降端 and not(pnlPBXSW28_ストッパ下降端)) or passXSW28_ストッパ下降端)) and (errpassXSW26_クランプ下降端 or ((XSW26_クランプ下降端 and not(pnlPBXSW26_クランプ下降端)) or passXSW26_クランプ下降端)) then
				inc(MC14_搬送モータstep)
			end if
		else
			inc(MC14_搬送モータstep)
		end if
		
	case 4
		if PH19_釜検知 or PH20_フタ検知 then
			if  (errpassXSW32_ストッパ下降端 or ((XSW32_ストッパ下降端 and not(pnlPBXSW32_ストッパ下降端)) or passXSW32_ストッパ下降端)) and (errpassXSW30_クランプ下降端 or ((XSW30_クランプ下降端 and not(pnlPBXSW30_クランプ下降端)) or passXSW30_クランプ下降端)) then
					inc(MC14_搬送モータstep)
			end if
		else
			inc(MC14_搬送モータstep)
		end if

	case 5
		mMC14_搬送モータ=ON
		errpassMC14_搬送モータ=OFF
		inc(MC14_搬送モータstep)

	case 6
		if (not(PH15_釜検知) and not(PH16_フタ検知) and not(PH17_釜検知) and not(PH18_フタ検知) and not(PH19_釜検知) and not(PH20_フタ検知)) or errpassMC14_搬送モータ then
			inc(MC14_搬送モータstep)
		end if
	
	case 7
		if errpassMC14_搬送モータ then
			inc(MC14_搬送モータstep)
		else if PH15_釜起動検知 or PH16_フタ起動検知 then
			if (PH17_釜検知 and timdly_PH17_釜検知.B) or (PH18_フタ検知 and timdly_PH18_フタ検知.B) then
				inc(MC14_搬送モータstep)
			end if
		else if PH17_釜起動検知 or PH18_フタ起動検知 then
			if (PH19_釜検知 and timdly_PH19_釜検知.B) or (PH20_フタ検知 and timdly_PH20_フタ検知.B) then
				inc(MC14_搬送モータstep)
			end if
		else if PH19_釜起動検知 or PH20_フタ起動検知 then
			if PH21_釜検知 and timdly_PH21_釜検知.B  then
				inc(MC14_搬送モータstep)
			end if
		end if
	
	case 8
		tim_MC14_搬送モータ_val=27
		res(tim_MC14_搬送モータ)
		inc(MC14_搬送モータstep)
	
	case 9
		if tim_MC14_搬送モータ.B then
			inc(MC14_搬送モータstep)
		end if
	
	case 10
		mMC14_搬送モータ=OFF
		inc(MC14_搬送モータstep)

	case 11
		MC14_搬送モータstep=0
	
	end select
	'--------------------------------------------
	'MC15_搬送モータ
	tmr(not(PH21_釜検知),timnotdlyPH21_釜検知,20)
	tmr(tim_MC15_搬送モータ,tim_MC15_搬送モータ_val)
	
	select case MC15_搬送モータstep
	case 0
	case 1
		errpassXSW32_ストッパ下降端=OFF
		errpassXSW30_クランプ下降端=OFF
		inc(MC15_搬送モータstep)
	
	case 2
		PH19_釜起動検知=PH19_釜検知
		PH20_フタ起動検知=PH20_フタ検知
		フタ搬送中=not(PH19_釜検知) and PH20_フタ検知
		'PH22_釜検知
		
		if PH19_釜検知 or PH20_フタ検知 then
			if (errpassXSW32_ストッパ下降端 or ((XSW32_ストッパ下降端 and not(pnlPBXSW32_ストッパ下降端)) or passXSW32_ストッパ下降端)) and (errpassXSW30_クランプ下降端 or ((XSW30_クランプ下降端 and not(pnlPBXSW30_クランプ下降端)) or passXSW30_クランプ下降端) ) then
				ejectMC15_搬送モータ=ON
				inc(MC15_搬送モータstep)
			end if
		else
			MC15_搬送モータstep=0
		end if
		
	case 3
		if not(PH19_釜検知) and not(PH20_フタ検知) then
			inc(MC15_搬送モータstep)	
		end if
	
	case 4
		if PH19_釜起動検知 or PH20_フタ起動検知 then
			if (PH21_釜検知 and timdly_PH21_釜検知.B) then
				inc(MC15_搬送モータstep)
			end if
		end if
		
	case 5
		if フタ搬送中 then
			tim_MC15_搬送モータ_val=5 'ブレークタイミング
		else
			tim_MC15_搬送モータ_val=10 'ブレークタイミング
		end if		
		
		res(tim_MC15_搬送モータ)
		inc(MC15_搬送モータstep)
	
	case 6
		if tim_MC15_搬送モータ.B then 
			inc(MC15_搬送モータstep)
		end if
	
	case 7
		ejectMC15_搬送モータ=OFF
		inc(MC15_搬送モータstep)
		
	case 8
		if フタ搬送中 then
			if timnotdlyPH21_釜検知.B then
				inc(MC15_搬送モータstep)
			end if
		else
			inc(MC15_搬送モータstep)
		end if
	
	case 9
		MC15_搬送モータstep=0
		
	end select
		

	'===================================================================================================================
	'【 炊飯入口コンベア 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case 搬送コンベアCstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 搬送コンベアCAutoRun then
				inc(搬送コンベアCstep)
			else 
				搬送コンベアCstep=0 '終了待機
			end if

		case 2
			if PH21_釜検知 then
				搬送コンベアC動作中=OFF
				搬送コンベアC排出要求=ON
				搬送コンベアCstep=1
			else
				inc(搬送コンベアCstep)
			end if
				


		case 3
		' [ 搬送コンベア停止確認 ]
			'                                 ＊ not(PH19_釜検知) and not(PH20_フタ検知): 自タスクの排出要求がOFFしなくても、フタ取り箇所にワークがなければワークを供給させる。
			if (搬送コンベアC排出要求=OFF or (not(PH19_釜検知) and not(PH20_フタ検知)) ) and  搬送コンベアC2動作中=OFF and 搬送コンベアB排出要求  then
				inc(搬送コンベアCstep)
			else
				搬送コンベアCstep=1
			end if


		case 4
			if 	ならしユニット排出要求 and 蓋被せユニット排出要求 then
				inc(搬送コンベアCstep)
			else
				搬送コンベアCstep=1
			end if
	
		case 5 
		'[ 原点検出 ]
			if 搬送コンベアCOrg  then
				inc(搬送コンベアCstep)
			else
				搬送コンベアCstep=1
			end if
		
		case 6
			LatchPH15_釜検知=OFF
			LatchPH16_フタ検知=OFF
			
			搬送コンベアC動作中=ON
			搬送コンベアCstep=100
			
		'--------------------------------------------------------------------------------------------------------------
		' 【 プロセス処理 】
		case 100
			LatchPH15_釜検知=PH15_釜検知
			LatchPH16_フタ検知=PH16_フタ検知
			
			inc(搬送コンベアCstep)			

		case 101
				SV25_ストッパstep=1
				SV27_ストッパstep=1
				MC14_搬送モータstep=1
				MC15_搬送モータstep=1
				MC16_モータローラstep=1
				inc(搬送コンベアCstep)
		
		case 102
			if SV25_ストッパstep=0 and SV27_ストッパstep=0 and MC14_搬送モータstep=0 and MC15_搬送モータstep=0 and MC16_モータローラstep=0 then
				inc(搬送コンベアCstep)
			end if			
		
		case 103

			StageDevice10=StageDevice9
			StageItem10=ANDA(StageDevice10.U,$00FF)  

			StageDevice9=StageDevice8
			StageItem9=ANDA(StageDevice9.U,$00FF)

			StageDevice8=StageDevice7
			StageItem8=ANDA(StageDevice8.U,$00FF)  
			StageItem7=ANDA(StageDevice7.U,$00FF)  

			inc(搬送コンベアCstep)

		case 104
			搬送コンベアB排出要求=OFF
			ならし完了=OFF
			ならしユニット排出要求=OFF
			フタ被せ完了=OFF
			蓋被せユニット排出要求=OFF
			
			if PH21_釜検知 then
				搬送コンベアC排出要求=ON
			end if
			搬送コンベアC動作中=OFF
			搬送コンベアCstep=1
			
		end select

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		if ManualInite=0 then
			mSV24_クランプ=OFF
			mSV25_ストッパ=OFF
			mSV26_クランプ=OFF
			mSV27_ストッパ=OFF
		
			ManualInite=1
		end if
	
		搬送コンベアCAutoRun=OFF
		
		搬送コンベアCstep=0 '終了
		
		res(timerr_MC16_モータローラ)'tmr(MC16_モータローラ,timerr_MC16_モータローラ,#120)
		res(timerr_MC14_搬送モータ)'tmr(MC14_搬送モータ,timerr_MC14_搬送モータ,#120)
		
		if ldp(pnlPBMC14_搬送モータ) then
			if mMC14_搬送モータ then
				mMC14_搬送モータ=OFF
			else if ((XSW24_リフト下降端 and not(pnlPBXSW24_リフト下降端)) or passXSW24_リフト下降端) and ((XSW25_ならし上昇端 and not(pnlPBXSW25_ならし上昇端)) or passXSW25_ならし上昇端) and ((XSW39_シリンダ上昇端A and not(pnlPBXSW39_シリンダ上昇端A)) or passXSW39_シリンダ上昇端A) and ((XSW41_シリンダ上昇端B and not(pnlPBXSW41_シリンダ上昇端B)) or passXSW41_シリンダ上昇端B) then
				mMC14_搬送モータ=ON
			end if
		end if
		

		if ldp(pnlPBMC15_搬送モータ) then
			if mMC15_搬送モータ then
				mMC15_搬送モータ=OFF
			else if ((XSW25_ならし上昇端 and not(pnlPBXSW25_ならし上昇端)) or passXSW25_ならし上昇端) and ((XSW39_シリンダ上昇端A and not(pnlPBXSW39_シリンダ上昇端A)) or passXSW39_シリンダ上昇端A) and ((XSW41_シリンダ上昇端B and not(pnlPBXSW41_シリンダ上昇端B)) or passXSW41_シリンダ上昇端B) then
				mMC15_搬送モータ=ON
			end if
		end if

		
		if ldp(pnlPBSV23_リフト) then
			if mSV23_リフト then
				mSV23_リフト=OFF
			else
				mSV23_リフト=ON
			end if
		end if
		
		if ldp(pnlPBSV24_クランプ) then
			if mSV24_クランプ then
				mSV24_クランプ=OFF
			else
				mSV24_クランプ=ON
			end if
		end if
		
		if ldp(pnlPBSV25_ストッパ) then
			if mSV25_ストッパ then
				mSV25_ストッパ=OFF
			else
				mSV25_ストッパ=ON
			end if
		end if
		
		if ldp(pnlPBSV26_クランプ) then
			if mSV26_クランプ then
				mSV26_クランプ=OFF
			else
				mSV26_クランプ=ON
			end if
		end if
		
		if ldp(pnlPBSV27_ストッパ) then
			if mSV27_ストッパ then
				mSV27_ストッパ=OFF
			else 
				mSV27_ストッパ=ON
			end if
		end if
		

	end if '搬送コンベアCAutoMode and not(搬送コンベアCOrgErrStep)

	'===================================================================================================================
	'【 搬送コンベアCOrgErr処理 】
	else
		res(tim_XSW24_リフト下降端)
		res(tim_XSW25_リフト上昇端)
		res(tim_XSW26_クランプ下降端)
		res(tim_XSW27_クランプ上昇端)
		res(tim_XSW28_ストッパ下降端)
		res(tim_XSW29_ストッパ上昇端)
		res(tim_XSW30_クランプ下降端)
		res(tim_XSW31_クランプ上昇端)
		res(tim_XSW32_ストッパ下降端)
		res(tim_XSW33_ストッパ上昇端)

		res(tim_notXSW24_リフト下降端)
		res(tim_notXSW25_リフト上昇端)
		res(tim_notXSW26_クランプ下降端)
		res(tim_notXSW27_クランプ上昇端)
		res(tim_notXSW28_ストッパ下降端)
		res(tim_notXSW29_ストッパ上昇端)
		res(tim_notXSW30_クランプ下降端)
		res(tim_notXSW31_クランプ上昇端)
		res(tim_notXSW32_ストッパ下降端)
		res(tim_notXSW33_ストッパ上昇端)

		if ResetFlg then
			搬送コンベアCOrgErr=OFF
		end if


	end if

	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
	
		搬送コンベアCErr=ON

		pauseMC14_搬送モータ=ON
		pauseMC15_搬送モータ=ON
		pauseMC16_モータローラ=ON
		res(timerr_MC16_モータローラ)
		res(timerr_MC14_搬送モータ)
		
		select case 搬送コンベアCErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW24_リフト下降端=OFF
				almXSW25_リフト上昇端=OFF
				almXSW26_クランプ下降端=OFF
				almXSW27_クランプ上昇端=OFF
				almXSW28_ストッパ下降端=OFF
				almXSW29_ストッパ上昇端=OFF
				almXSW30_クランプ下降端=OFF
				almXSW31_クランプ上昇端=OFF
				almXSW32_ストッパ下降端=OFF
				almXSW33_ストッパ上昇端=OFF
				almXSW36_ストッパ下降端=OFF
				almXSW37_ストッパ上昇端=OFF
				almMC14_搬送モータ=OFF
				almMC16_モータローラ=OFF

				inc(搬送コンベアCErrStep)
			end if
		case 2
			搬送コンベアCErr=OFF

			res(tim_XSW24_リフト下降端)
			res(tim_XSW25_リフト上昇端)
			res(tim_XSW26_クランプ下降端)
			res(tim_XSW27_クランプ上昇端)
			res(tim_XSW28_ストッパ下降端)
			res(tim_XSW29_ストッパ上昇端)
			res(tim_XSW30_クランプ下降端)
			res(tim_XSW31_クランプ上昇端)
			res(tim_XSW32_ストッパ下降端)
			res(tim_XSW33_ストッパ上昇端)

			res(tim_notXSW24_リフト下降端)
			res(tim_notXSW25_リフト上昇端)
			res(tim_notXSW26_クランプ下降端)
			res(tim_notXSW27_クランプ上昇端)
			res(tim_notXSW28_ストッパ下降端)
			res(tim_notXSW29_ストッパ上昇端)
			res(tim_notXSW30_クランプ下降端)
			res(tim_notXSW31_クランプ上昇端)
			res(tim_notXSW32_ストッパ下降端)
			res(tim_notXSW33_ストッパ上昇端)

			pauseMC14_搬送モータ=OFF
			pauseMC15_搬送モータ=OFF
			pauseMC16_モータローラ=OFF
		
			pauseSV24_クランプ=OFF
			pauseSV25_ストッパ=OFF
			pauseSV26_クランプ=OFF
			pauseSV27_ストッパ=OFF
			pauseSV23_リフト=OFF
			pauseSV29_ストッパ=OFF


			搬送コンベアCErrStep=0
		end select

	end if 'if 搬送コンベアCErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case 搬送コンベアCEmgStep
	case 0
	
	case 1
		搬送コンベアCAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (搬送コンベアCAutoMode and 自動搬送AutoMode ) or 搬送コンベアCstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseMC16_モータローラ=ON
			pauseMC14_搬送モータ=ON
			pauseMC15_搬送モータ=ON

			if timstack=OFF then
				tim_SV25_ストッパ_stack=tim_SV25_ストッパ.U
				tim_SV27_ストッパ_stack=tim_SV27_ストッパ.U
				tim_MC14_搬送モータ_stack=tim_MC14_搬送モータ.U
				tim_procstep_stack=tim_procstep.U
				timdly_PH15_釜検知_stack=timdly_PH15_釜検知.U
				timdly_PH16_フタ検知_stack=timdly_PH16_フタ検知.U
				timdly_PH17_釜検知_stack=timdly_PH17_釜検知.U
				timdly_PH18_フタ検知_stack=timdly_PH18_フタ検知.U
				timdly_PH19_釜検知_stack=timdly_PH19_釜検知.U
				timdly_PH20_フタ検知_stack=timdly_PH20_フタ検知.U
				timdly_PH21_釜検知_stack=timdly_PH21_釜検知.U
				tim_MC16_モータローラ_stack=tim_MC16_モータローラ.U
				tim_MC15_搬送モータ_stack=tim_MC15_搬送モータ.U
				timerr_MC16_モータローラ_stack=timerr_MC16_モータローラ.U
				timerr_MC14_搬送モータ_stack=timerr_MC14_搬送モータ.U
			
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC14_搬送モータ=OFF
			mMC15_搬送モータ=OFF
			mMC16_モータローラ=OFF
			mSV23_リフト=OFF
			mSV24_クランプ=OFF
			mSV25_ストッパ=OFF
			mSV26_クランプ=OFF
			mSV27_ストッパ=OFF		
			'---------------------------------
		end if
		
		'---------------------------------
		inc(搬送コンベアCEmgStep)
	case 2
		if ResetFlg then
			inc(搬送コンベアCEmgStep)
		end if
	case 3
		if (搬送コンベアCAutoMode and 自動搬送AutoMode ) or 搬送コンベアCstep<>0 then
			if ldp(StartFlg) then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseMC16_モータローラ=OFF
				pauseMC14_搬送モータ=OFF
				pauseMC15_搬送モータ=OFF

				tim_SV25_ストッパ.U=tim_SV25_ストッパ_stack
				tim_SV27_ストッパ.U=tim_SV27_ストッパ_stack
				tim_MC14_搬送モータ.U=tim_MC14_搬送モータ_stack
				tim_procstep.U=tim_procstep_stack
				tim_MC16_モータローラ.U=tim_MC16_モータローラ_stack
				tim_MC15_搬送モータ.U=tim_MC15_搬送モータ_stack
				timerr_MC16_モータローラ.U=timerr_MC16_モータローラ_stack
				timerr_MC14_搬送モータ.U=timerr_MC14_搬送モータ_stack


				res(timdly_PH15_釜検知)
				res(timdly_PH16_フタ検知)
				res(timdly_PH17_釜検知)
				res(timdly_PH18_フタ検知)
				res(timdly_PH19_釜検知)
				res(timdly_PH20_フタ検知)
				res(timdly_PH21_釜検知)
				'---------------------------------
				inc(搬送コンベアCEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(搬送コンベアCEmgStep)		
		end if				
	case 4
		timstack=OFF
		搬送コンベアCEmgStep=0
		搬送コンベアCEmg=OFF
	end select

end if 'if 搬送コンベアCEmgStep=0 then
