'搬送コンベアG
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'---- 削除 ------
'ブラシ部
'-----------------------------------------
'THR56_ブラシサーマル
'XSW69_ブラシ上昇端
'XSW70_ブラシ下降端
'-----------------------------------------
'MC56_ブラシモータ
'SV65_シリンダ上昇
'SV66_シリンダ下降
'-----------------------------------------

'===================================================================================================================
'
'	搬送コンベアG
'-----------------------------------------------------
' [ 37 ] 搬送工ンベアF1搬出リフト
'	MC41_モータローラ

'	PH49_釜検知
'
'	SV47_リフト	
'	XSW55_リフト上昇端
'	XSW56_リフト下降端
'
'	SV44_ストッパ
'	XSW59_ストッパ上昇端
'	XSW60_ストッパ下降端
'-----------------------------------------------------
' [ 38 ] 搬送工ンベアF2搬出リフト
'	MC42_モータローラ
'
'	PH50_釜検知
'
'	SV48_リフト
'	XSW57_リフト上昇端
'	XSW58_リフト下降端
'
'	SV45_ストッパ
'	XSW61_ストッパ上昇端
'	XSW62_ストッパ下降端
'
'-----------------------------------------------------
' [ 39 ] フタ取り釜ストッパ
'	MC43_搬送モータ
'
'	PH51_釜検知
'	PH52_フタ検知
'
'	SV46_ストッパ
'	XSW63_ストッパ上昇端
'	XSW64_ストッパ下降端
'
'-----------------------------------------------------
' [ 40 ] 搬送コンベアG搬出リフト
'	MC54_モータローラ
'
'	PH53_釜検知
'	PH54_フタ検知
'
'	SV50_リフト
'	XSW56_リフト上昇端
'	XSW68_リフト下降端
'
'	SV49_ストッパ
'	XSW65_ストッパ上昇端
'	XSW66_ストッパ下降端
'
'===================================================================================================================
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理
    搬送コンベアGAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    搬送コンベアGAutoRun=OFF
    搬送コンベアG許可=ON
    搬送コンベアGOrgErr=OFF
    搬送コンベアGErr=OFF
    搬送コンベアGEmg=OFF
    搬送コンベアGstep=0
    搬送コンベアGErrStep=0
    搬送コンベアGOrgErrStep=0
    搬送コンベアGEmgStep=0

	SV46_ストッパstep=0
	フタ取り排出step=0
	リフトF1供給step=0
	リフトF1排出step=0
	リフトF2供給step=0
	リフトF2排出step=0

	if PH49_釜検知 then
		mSV44_ストッパ=ON
		mSV47_リフト=ON
	end if
	
	if PH50_釜検知 then
		mSV45_ストッパ=ON
		mSV48_リフト=ON
	end if

	if PH51_釜検知 then
		mSV46_ストッパ=ON
	end if

	mSV49_ストッパ=ON
	mSV50_リフト=ON

	if SSW3_自動モード then
		ManualInite=1
	else
		ManualInite=0	
	end if
	
				


end if
'===================================================================================================================
'【 原点 】
搬送コンベアGOrg=((XSW55_リフト上昇端 and not(pnlPBXSW55_リフト上昇端)) or passXSW55_リフト上昇端) or ((XSW56_リフト下降端 and not(pnlPBXSW56_リフト下降端)) or passXSW56_リフト下降端)
搬送コンベアGOrg= 搬送コンベアGOrg and (((XSW59_ストッパ上昇端 and not(pnlPBXSW59_ストッパ上昇端)) or passXSW59_ストッパ上昇端) or ((XSW60_ストッパ下降端 and not(pnlPBXSW60_ストッパ下降端)) or passXSW60_ストッパ下降端))
搬送コンベアGOrg= 搬送コンベアGOrg and (((XSW57_リフト上昇端 and not(pnlPBXSW57_リフト上昇端)) or passXSW57_リフト上昇端) or ((XSW58_リフト下降端 and not(pnlPBXSW58_リフト下降端)) or passXSW58_リフト下降端))
搬送コンベアGOrg= 搬送コンベアGOrg and (((XSW61_ストッパ上昇端 and not(pnlPBXSW61_ストッパ上昇端)) or passXSW61_ストッパ上昇端) or ((XSW62_ストッパ下降端 and not(pnlPBXSW62_ストッパ下降端)) or passXSW62_ストッパ下降端))
搬送コンベアGOrg= 搬送コンベアGOrg and (((XSW63_ストッパ上昇端 and not(pnlPBXSW63_ストッパ上昇端)) or passXSW63_ストッパ上昇端) or ((XSW64_ストッパ下降端 and not(pnlPBXSW64_ストッパ下降端)) or passXSW64_ストッパ下降端))
搬送コンベアGOrg= 搬送コンベアGOrg and (((XSW67_リフト上昇端 and not(pnlPBXSW67_リフト上昇端)) or passXSW67_リフト上昇端) or ((XSW68_リフト下降端 and not(pnlPBXSW68_リフト下降端)) or passXSW68_リフト下降端))
搬送コンベアGOrg= 搬送コンベアGOrg and (((XSW65_ストッパ上昇端 and not(pnlPBXSW65_ストッパ上昇端)) or passXSW65_ストッパ上昇端) or ((XSW66_ストッパ下降端 and not(pnlPBXSW66_ストッパ下降端)) or passXSW66_ストッパ下降端))

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	搬送コンベアGEmg=ON
	搬送コンベアGEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
' 搬送工ンベアF1搬出リフト
tmr(SV47_リフト and not(XSW55_リフト上昇端) and not(pnlPBXSW55_リフト上昇端), tim_notXSW55_リフト上昇端, #40)
tmr(not(SV47_リフト) and not(XSW56_リフト下降端) and not(pnlPBXSW56_リフト下降端),tim_notXSW56_リフト下降端, #40)
tmr(SV44_ストッパ and not(XSW59_ストッパ上昇端) and not(pnlPBXSW59_ストッパ上昇端),tim_notXSW59_ストッパ上昇端,#40)
tmr(not(SV44_ストッパ) and not(XSW60_ストッパ下降端) and not(pnlPBXSW60_ストッパ下降端),tim_notXSW60_ストッパ下降端,#40)

'tmr(not(SV47_リフト) and XSW55_リフト上昇端 and not(pnlPBXSW55_リフト上昇端), tim_XSW55_リフト上昇端, #10)
if LDP(SV47_リフト) and XSW55_リフト上昇端 and not(pnlPBXSW55_リフト上昇端) then
	SET(tim_XSW55_リフト上昇端)
end if
'tmr(SV47_リフト and XSW56_リフト下降端 and not(pnlPBXSW56_リフト下降端),tim_XSW56_リフト下降端, #10)
if LDF(SV47_リフト) and XSW56_リフト下降端 and not(pnlPBXSW56_リフト下降端) and not(pauseSV47_リフト) then
	SET(tim_XSW56_リフト下降端)
end if
'tmr(not(SV44_ストッパ) and XSW59_ストッパ上昇端 and not(pnlPBXSW59_ストッパ上昇端),tim_XSW59_ストッパ上昇端,#10)
if LDP(SV44_ストッパ) and XSW59_ストッパ上昇端 and not(pnlPBXSW59_ストッパ上昇端) then
	SET(tim_XSW59_ストッパ上昇端)
end if
'tmr(SV44_ストッパ and XSW60_ストッパ下降端 and not(pnlPBXSW60_ストッパ下降端),tim_XSW60_ストッパ下降端,#10)
if LDF(SV44_ストッパ) and XSW60_ストッパ下降端 and not(pnlPBXSW60_ストッパ下降端) and not(pauseSV44_ストッパ) then
	SET(tim_XSW60_ストッパ下降端)
end if

' 搬送工ンベアF2搬出リフト
tmr(SV48_リフト and not(XSW57_リフト上昇端) and not(pnlPBXSW57_リフト上昇端), tim_notXSW57_リフト上昇端, #40)
tmr(not(SV48_リフト) and not(XSW58_リフト下降端) and not(pnlPBXSW58_リフト下降端),tim_notXSW58_リフト下降端, #40)
tmr(SV45_ストッパ and not(XSW61_ストッパ上昇端) and not(pnlPBXSW61_ストッパ上昇端),tim_notXSW61_ストッパ上昇端,#40)
tmr(not(SV45_ストッパ) and not(XSW62_ストッパ下降端) and not(pnlPBXSW62_ストッパ下降端),tim_notXSW62_ストッパ下降端,#40)

'tmr(not(SV48_リフト) and XSW57_リフト上昇端 and not(pnlPBXSW57_リフト上昇端), tim_XSW57_リフト上昇端, #10)
if LDP(SV48_リフト) and XSW57_リフト上昇端 and not(pnlPBXSW57_リフト上昇端) then
	SET(tim_XSW57_リフト上昇端)
end if
'tmr(SV48_リフト and XSW58_リフト下降端 and not(pnlPBXSW58_リフト下降端),tim_XSW58_リフト下降端, #10)
if LDF(SV48_リフト) and XSW58_リフト下降端 and not(pnlPBXSW58_リフト下降端) and not(pauseSV48_リフト) then
	SET(tim_XSW58_リフト下降端)
end if
'tmr(not(SV45_ストッパ) and XSW61_ストッパ上昇端 and not(pnlPBXSW61_ストッパ上昇端),tim_XSW61_ストッパ上昇端,#10)
if LDP(SV45_ストッパ) and XSW61_ストッパ上昇端 and not(pnlPBXSW61_ストッパ上昇端) then
	SET(tim_XSW61_ストッパ上昇端)
end if
'tmr(SV45_ストッパ and XSW62_ストッパ下降端 and not(pnlPBXSW62_ストッパ下降端),tim_XSW62_ストッパ下降端,#10)
if LDF(SV45_ストッパ) and XSW62_ストッパ下降端 and not(pnlPBXSW62_ストッパ下降端) and not(pauseSV45_ストッパ) then
	SET(tim_XSW62_ストッパ下降端)
end if
'フタ取り釜ストッパ
tmr(SV46_ストッパ and not(XSW63_ストッパ上昇端) and not(pnlPBXSW63_ストッパ上昇端),tim_notXSW63_ストッパ上昇端,#40)
tmr(not(SV46_ストッパ) and not(XSW64_ストッパ下降端) and not(pnlPBXSW64_ストッパ下降端),tim_notXSW64_ストッパ下降端,#40)

'tmr(not(SV46_ストッパ) and XSW63_ストッパ上昇端 and not(pnlPBXSW63_ストッパ上昇端),tim_XSW63_ストッパ上昇端,#10)
if LDP(SV46_ストッパ) and XSW63_ストッパ上昇端 and not(pnlPBXSW63_ストッパ上昇端) then
	SET(tim_XSW63_ストッパ上昇端)
end if
'tmr(SV46_ストッパ and XSW64_ストッパ下降端 and not(pnlPBXSW64_ストッパ下降端),tim_XSW64_ストッパ下降端,#10)
if LDF(SV46_ストッパ) and XSW64_ストッパ下降端 and not(pnlPBXSW64_ストッパ下降端) and not(pauseSV46_ストッパ) then
	SET(tim_XSW64_ストッパ下降端)
end if

'搬送コンベアG搬出リフト
tmr(SV50_リフト and not(XSW67_リフト上昇端) and not(pnlPBXSW67_リフト上昇端), tim_notXSW67_リフト上昇端, #40)
tmr(not(SV50_リフト) and not(XSW68_リフト下降端) and not(pnlPBXSW68_リフト下降端),tim_notXSW68_リフト下降端, #40)
tmr(SV49_ストッパ and not(XSW65_ストッパ上昇端) and not(pnlPBXSW65_ストッパ上昇端),tim_notXSW65_ストッパ上昇端,#40)
tmr(not(SV49_ストッパ) and not(XSW66_ストッパ下降端) and not(pnlPBXSW66_ストッパ下降端),tim_notXSW66_ストッパ下降端,#40)

'tmr(not(SV50_リフト) and XSW67_リフト上昇端 and not(pnlPBXSW67_リフト上昇端), tim_XSW67_リフト上昇端, #10)
if LDP(SV50_リフト) and XSW67_リフト上昇端 and not(pnlPBXSW67_リフト上昇端) then
	SET(tim_XSW67_リフト上昇端)
end if
'tmr(SV50_リフト and XSW68_リフト下降端 and not(pnlPBXSW68_リフト下降端),tim_XSW68_リフト下降端, #10)
if LDF(SV50_リフト) and XSW68_リフト下降端 and not(pnlPBXSW68_リフト下降端) and not(pauseSV50_リフト) then
	SET(tim_XSW68_リフト下降端)
end if
'tmr(not(SV49_ストッパ) and XSW65_ストッパ上昇端 and not(pnlPBXSW65_ストッパ上昇端),tim_XSW65_ストッパ上昇端,#10)
if LDP(SV49_ストッパ) and XSW65_ストッパ上昇端 and not(pnlPBXSW65_ストッパ上昇端) then
	SET(tim_XSW65_ストッパ上昇端)
end if
'tmr(SV49_ストッパ and XSW66_ストッパ下降端 and not(pnlPBXSW66_ストッパ下降端),tim_XSW66_ストッパ下降端,#10)
if LDF(SV49_ストッパ) and XSW66_ストッパ下降端 and not(pnlPBXSW66_ストッパ下降端) and not(pauseSV49_ストッパ) then
	SET(tim_XSW66_ストッパ下降端)
end if
' -------------------------------------------------------------------------------------------------------------------
' 搬送工ンベアF1搬出リフト
tms(SV47_リフト,passtimXSW55_リフト上昇端,passtimXSW55_リフト上昇端_val)
tms(not(SV47_リフト),passtimXSW56_リフト下降端,passtimXSW56_リフト下降端_val)
tms(SV44_ストッパ,passtimXSW59_ストッパ上昇端,passtimXSW59_ストッパ上昇端_val)
tms(not(SV44_ストッパ),passtimXSW60_ストッパ下降端,passtimXSW60_ストッパ下降端_val)

' 搬送工ンベアF2搬出リフト
tms(SV48_リフト,passtimXSW57_リフト上昇端,passtimXSW57_リフト上昇端_val)
tms(not(SV48_リフト),passtimXSW58_リフト下降端,passtimXSW58_リフト下降端_val)
tms(SV45_ストッパ,passtimXSW61_ストッパ上昇端,passtimXSW61_ストッパ上昇端_val)
tms(not(SV45_ストッパ),passtimXSW62_ストッパ下降端,passtimXSW62_ストッパ下降端_val)

'フタ取り釜ストッパ
tms(SV46_ストッパ,passtimXSW63_ストッパ上昇端,passtimXSW63_ストッパ上昇端_val)
tms(not(SV46_ストッパ),passtimXSW64_ストッパ下降端,passtimXSW64_ストッパ下降端_val)

'搬送コンベアG搬出リフト
tms(SV50_リフト,passtimXSW67_リフト上昇端,passtimXSW67_リフト上昇端_val)
tms(not(SV50_リフト),passtimXSW68_リフト下降端,passtimXSW68_リフト下降端_val)
tms(SV49_ストッパ,passtimXSW65_ストッパ上昇端,passtimXSW65_ストッパ上昇端_val)
tms(not(SV49_ストッパ),passtimXSW66_ストッパ下降端,passtimXSW66_ストッパ下降端_val)

'--------------------------------------------------
tmr(MC54_モータローラ,timerr_MC54_モータローラ,#65)

'--------------------------------------------------
if ldp(timerr_MC54_モータローラ.B) then
	errpassMC54_モータローラ=ON
	mMC54_モータローラ=OFF
	almMC54_モータローラ=ON
	搬送コンベアGErrStep=1

'--------------------------------------------------
else if ldp(tim_XSW55_リフト上昇端.B) or ldp(tim_notXSW55_リフト上昇端.B) then
	errpassXSW55_リフト上昇端=ON
	almXSW55_リフト上昇端=ON
	pnlPBXSW55_リフト上昇端=ON
	搬送コンベアGErrStep=1

else if ldp(tim_XSW56_リフト下降端.B) or ldp(tim_notXSW56_リフト下降端.B) then
	errpassXSW56_リフト下降端=ON
	almXSW56_リフト下降端=ON
	pnlPBXSW56_リフト下降端=ON
	搬送コンベアGErrStep=1
'--------------------------------------------------
else if ldp(tim_XSW59_ストッパ上昇端.B) or ldp(tim_notXSW59_ストッパ上昇端.B) then
	errpassXSW59_ストッパ上昇端=ON
	'pauseSV44_ストッパ=ON
	almXSW59_ストッパ上昇端=ON
	pnlPBXSW59_ストッパ上昇端=ON
	搬送コンベアGErrStep=1

else if ldp(tim_XSW60_ストッパ下降端.B) or ldp(tim_notXSW60_ストッパ下降端.B) then
	errpassXSW60_ストッパ下降端=ON
	almXSW60_ストッパ下降端=ON
	pnlPBXSW60_ストッパ下降端=ON
	搬送コンベアGErrStep=1

'--------------------------------------------------
else if ldp(tim_XSW57_リフト上昇端.B) or ldp(tim_notXSW57_リフト上昇端.B) then
	errpassXSW57_リフト上昇端=ON
	almXSW57_リフト上昇端=ON
	pnlPBXSW57_リフト上昇端=ON
	搬送コンベアGErrStep=1

else if ldp(tim_XSW58_リフト下降端.B) or ldp(tim_notXSW58_リフト下降端.B) then
	errpassXSW58_リフト下降端=ON
	almXSW58_リフト下降端=ON
	pnlPBXSW58_リフト下降端=ON
	搬送コンベアGErrStep=1

'--------------------------------------------------
else if ldp(tim_XSW61_ストッパ上昇端.B) or ldp(tim_notXSW61_ストッパ上昇端.B) then
	errpassXSW61_ストッパ上昇端=ON
	'pauseSV45_ストッパ=ON
	almXSW61_ストッパ上昇端=ON
	pnlPBXSW61_ストッパ上昇端=ON
	搬送コンベアGErrStep=1

else if ldp(tim_XSW62_ストッパ下降端.B) or ldp(tim_notXSW62_ストッパ下降端.B) then
	errpassXSW62_ストッパ下降端=ON
	almXSW62_ストッパ下降端=ON
	pnlPBXSW62_ストッパ下降端=ON
	搬送コンベアGErrStep=1

'--------------------------------------------------
else if ldp(tim_XSW63_ストッパ上昇端.B) or ldp(tim_notXSW63_ストッパ上昇端.B) then
	errpassXSW63_ストッパ上昇端=ON
	pauseSV46_ストッパ=ON
	almXSW63_ストッパ上昇端=ON
	pnlPBXSW63_ストッパ上昇端=ON
	搬送コンベアGErrStep=1

else if ldp(tim_XSW64_ストッパ下降端.B) or ldp(tim_notXSW64_ストッパ下降端.B) then
	errpassXSW64_ストッパ下降端=ON
	almXSW64_ストッパ下降端=ON
	pnlPBXSW64_ストッパ下降端=ON
	搬送コンベアGErrStep=1

'--------------------------------------------------
else if (搬送コンベアGStep>0  and 搬送コンベアHStep=0) and (ldp(tim_XSW67_リフト上昇端.B) or ldp(tim_notXSW67_リフト上昇端.B)) then
	errpassXSW67_リフト上昇端=ON
	almXSW67_リフト上昇端=ON
	pnlPBXSW67_リフト上昇端=ON
	搬送コンベアGErrStep=1

else if (搬送コンベアGStep>0  and 搬送コンベアHStep=0) and (ldp(tim_XSW68_リフト下降端.B) or ldp(tim_notXSW68_リフト下降端.B)) then
	errpassXSW68_リフト下降端=ON
	almXSW68_リフト下降端=ON
	pnlPBXSW68_リフト下降端=ON
	搬送コンベアGErrStep=1

'--------------------------------------------------
else if (搬送コンベアGStep>0  and 搬送コンベアHStep=0) and (ldp(tim_XSW65_ストッパ上昇端.B) or ldp(tim_notXSW65_ストッパ上昇端.B)) then
	errpassXSW65_ストッパ上昇端=ON
	'pauseSV49_ストッパ=ON
	almXSW65_ストッパ上昇端=ON
	pnlPBXSW65_ストッパ上昇端=ON
	搬送コンベアGErrStep=1

else if (搬送コンベアGStep>0  and 搬送コンベアHStep=0) and (ldp(tim_XSW66_ストッパ下降端.B) or ldp(tim_notXSW66_ストッパ下降端.B)) then
	errpassXSW66_ストッパ下降端=ON
	almXSW66_ストッパ下降端=ON
	pnlPBXSW66_ストッパ下降端=ON
	搬送コンベアGErrStep=1
'--------------------------------------------------

end if

'===================================================================================================================


'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 搬送コンベアGEmgStep	自動モード セレクトスイッチ
'System :: 搬送コンベアGAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 搬送コンベアGEmg	その場停止


if 搬送コンベアGEmgStep=0 then  
	
	if 搬送コンベアGErrStep=0  then

	if not(搬送コンベアGOrgErr) then

	if (搬送コンベアGAutoMode and 自動搬送AutoMode ) or 搬送コンベアGstep<>0 or リフトF1供給step<>0 or リフトF2供給step<>0 then
	

		if ManualInite=0 then
			if PH49_釜検知 then
				mSV44_ストッパ=ON
				mSV47_リフト=ON
			else
				mSV44_ストッパ=OFF
				mSV47_リフト=OFF
			end if
			
			if PH50_釜検知 then
				mSV45_ストッパ=ON
				mSV48_リフト=ON
			else
				mSV45_ストッパ=OFF
				mSV48_リフト=OFF
			end if
			
			if PH51_釜検知 then
				mSV46_ストッパ=ON
			end if
						
			mSV49_ストッパ=ON
			mSV50_リフト=ON


			ManualInite=1
		end if
		
	
		if not(搬送コンベアGAutoMode and 自動搬送AutoMode ) then
			搬送コンベアGAutoRun=OFF
		end if

		'--------------------------------------------
		'【 フタ釜ストッパ 】
		'--------------------------------------------
		tmr(tim_SV46_ストッパ,tim_SV46_ストッパ_val)
	
		select case SV46_ストッパstep
		case 0
		
		case 1
			PH51_釜起動検知 = PH51_釜検知
			PH52_フタ起動検知 = PH52_フタ検知
			
			if PH51_釜起動検知 or PH52_フタ起動検知 then
				inc(SV46_ストッパstep)
			else
				mSV46_ストッパ=ON 'フタ取り
				SV46_ストッパstep=0
			end if
		
		case 2
			mSV46_ストッパ=OFF 'フタ取り
			errpassXSW64_ストッパ下降端=OFF
			inc(SV46_ストッパstep)
		
		case 3
			if errpassXSW64_ストッパ下降端 or ((XSW64_ストッパ下降端 and not(pnlPBXSW64_ストッパ下降端)) or passXSW64_ストッパ下降端) then
				inc(SV46_ストッパstep)
			end if
		
		case 4
			if not(PH51_釜検知) and not(PH52_フタ検知) then
				inc(SV46_ストッパstep)
			end if
		
		
		case 5
			if PH53_釜検知 or PH54_フタ検知 then
				inc(SV46_ストッパstep)
			end if			
		
		case 6
			mSV46_ストッパ=ON 'フタ取り
			errpassXSW63_ストッパ上昇端=OFF
			inc(SV46_ストッパstep)
		
		case 7
			if errpassXSW63_ストッパ上昇端 or ((XSW63_ストッパ上昇端 and not(pnlPBXSW63_ストッパ上昇端)) or passXSW63_ストッパ上昇端) then
				inc(SV46_ストッパstep)
			end if
		
		case 8
			SV46_ストッパstep=0

		end select
		'--------------------------------------------
		'【 フタ釜排出 】
		'--------------------------------------------
		tmr(tim_フタ取り排出,tim_フタ取り排出_val)
	
		select case フタ取り排出step
		case 0
	
		case 1
			PH51_釜起動検知 = PH51_釜検知
			PH52_フタ起動検知 = PH52_フタ検知
			
			if PH51_釜起動検知 or PH52_フタ起動検知 then
				inc(フタ取り排出step)
			else
				フタ取り排出step=0
			end if
		
		case 2
			搬送コンベアG動作中=ON
			'リフト部
			mSV50_リフト=ON
			errpassXSW67_リフト上昇端=OFF
			mSV49_ストッパ=ON 'リフトストッパー
			errpassXSW65_ストッパ上昇端=OFF
			
			inc(フタ取り排出step)

		case 3
			if (errpassXSW67_リフト上昇端 or ((XSW67_リフト上昇端 and not(pnlPBXSW67_リフト上昇端)) or passXSW67_リフト上昇端)) and (errpassXSW65_ストッパ上昇端 or ((XSW65_ストッパ上昇端 and not(pnlPBXSW65_ストッパ上昇端)) or passXSW65_ストッパ上昇端)) then
				inc(フタ取り排出step)
			end if
		
		case 4
			'フタ取りユニット上昇端確認
			if ((XSW55_シリンダ上昇端A and not(pnlPBXSW55_シリンダ上昇端A)) or passXSW55_シリンダ上昇端A) and ((XSW57_シリンダ上昇端B and not(pnlPBXSW57_シリンダ上昇端B))  or passXSW57_シリンダ上昇端B) then
				inc(フタ取り排出step)
			end if
		
		case 5
			mMC54_モータローラ=ON
			errpassMC54_モータローラ=OFF
			mMC43_搬送モータ=ON
			inc(フタ取り排出step)
		
		case 6
			if errpassMC54_モータローラ then
				inc(フタ取り排出step)
			
			else if not(PH51_釜検知) and not(PH52_フタ検知) then
				inc(フタ取り排出step)
			end if

		case 7
			if PH53_釜検知 or PH54_フタ検知 then
				inc(フタ取り排出step)
			end if
		
		case 8
			tim_フタ取り排出_val=12
			res(tim_フタ取り排出)
			inc(フタ取り排出step)
		
		case 9
			if tim_フタ取り排出.B then
				inc(フタ取り排出step)
			end if

		case 10
			StageDevice40=StageDevice39
			mMC54_モータローラ=OFF
			mMC43_搬送モータ=OFF
			inc(フタ取り排出step)
				
		case 11
			if not(PH53_釜検知) and  PH54_フタ検知 then			
				コンベアH釜排出待機=OFF
			end if
		
			搬送コンベアG排出要求=ON
			フタ取り排出step=0

		end select

		'--------------------------------------------
		'【 搬送コンベアF1供給
		'--------------------------------------------
		tmr(tim_リフトF1供給,tim_リフトF1供給_val)
		
		select case リフトF1供給step
		case 0
		
		case 1
			if not(PH49_釜検知) and PH36_釜検知 and 搬送コンベアF1排出要求 then
				mSV47_リフト=ON
				errpassXSW55_リフト上昇端=OFF
				mSV44_ストッパ=ON
				errpassXSW59_ストッパ上昇端=OFF
				inc(リフトF1供給step)
			else
				リフトF1供給step=0
			end if
			
		case 2
			if errpassXSW55_リフト上昇端 or ((XSW55_リフト上昇端 and not(pnlPBXSW55_リフト上昇端)) or passXSW55_リフト上昇端) then
				inc(リフトF1供給step)
			end if
			
		case 3
			if errpassXSW59_ストッパ上昇端 or ((XSW59_ストッパ上昇端 and not(pnlPBXSW59_ストッパ上昇端)) or passXSW59_ストッパ上昇端) then
				inc(リフトF1供給step)
			end if

		case 4
			mMC41_モータローラ=ON
			mMC28_モータローラ=ON
			inc(リフトF1供給step)

		case 5
			if not(PH36_釜検知) then
				inc(リフトF1供給step)
			end if
			
		case 6
			if PH49_釜検知 then
				inc(リフトF1供給step)
			end if
		
		case 7
			tim_リフトF1供給_val=15
			res(tim_リフトF1供給)
			inc(リフトF1供給step)
		
		case 8
			if tim_リフトF1供給.B then
				inc(リフトF1供給step)
			end if			
		
		case 9
			StageDevice37=StageDevice24
			if ANDA(StageDevice37,$FF)>0 and ANDA(StageDevice37,$FF)<99 then
				検温待ち停止=ON
			end if
			
			mMC41_モータローラ=OFF
			mMC28_モータローラ=OFF
			inc(リフトF1供給step)
			
		case 10
			搬送コンベアF1排出要求=OFF
			リフトF1供給step=0

		end select

		'--------------------------------------------
		'【 搬送コンベアF1排出
		'--------------------------------------------
		tmr(tim_リフトF1排出,tim_リフトF1排出_val)
		
		select case リフトF1排出step
		
		case 0
		
		case 1
			if PH49_釜検知 and not(PH50_釜検知) then
				inc(リフトF1排出step)
			else
				リフトF1排出step=0
			end if

		case 2
			ejectMC43_搬送モータ=ON
			inc(リフトF1排出step)
		
		case 3
			if not(PH49_釜検知) then
				inc(リフトF1排出step)
			end if
		
		case 4
			if PH51_釜検知 and PH52_フタ検知 then
				inc(リフトF1排出step)
			end if
			
		case 5
			tim_リフトF1排出_val=12
			res(tim_リフトF1排出)
			inc(リフトF1排出step)
		
		case 6
			if tim_リフトF1排出.B then
				inc(リフトF1排出step)
			end if
		
		case 7
			StageDevice39=StageDevice37
			ejectMC43_搬送モータ=OFF
			inc(リフトF1排出step)
		
		case 8
			リフトF1排出step=0

		end select
		'--------------------------------------------
		'【 搬送コンベアF2供給 】
		'--------------------------------------------
		tmr(tim_リフトF2供給,tim_リフトF2供給_val)
		
		select case リフトF2供給step
		case 0
		
		case 1
			if not(PH49_釜検知) and not(PH50_釜検知) and PH48_釜検知 and 搬送コンベアF2排出要求 then
				mSV48_リフト=ON
				errpassXSW57_リフト上昇端=OFF
				mSV45_ストッパ=ON
				errpassXSW61_ストッパ上昇端=OFF
				inc(リフトF2供給step)
			else
				リフトF2供給step=0
			end if
			
		case 2
			if errpassXSW57_リフト上昇端 or ((XSW57_リフト上昇端 and not(pnlPBXSW57_リフト上昇端)) or passXSW57_リフト上昇端) then
				inc(リフトF2供給step)
			end if
			
		case 3
			if errpassXSW61_ストッパ上昇端 or ((XSW61_ストッパ上昇端 and not(pnlPBXSW61_ストッパ上昇端)) or passXSW61_ストッパ上昇端) then
				inc(リフトF2供給step)
			end if

		case 4
			mMC42_モータローラ=ON
			mMC53_モータローラ=ON
			inc(リフトF2供給step)

		case 5
			if not(PH48_釜検知) then
				inc(リフトF2供給step)
			end if
			
		case 6
			if PH50_釜検知 then
				inc(リフトF2供給step)
			end if
		
		case 7
			tim_リフトF2供給_val=15
			res(tim_リフトF2供給)
			inc(リフトF2供給step)
		
		case 8
			if tim_リフトF2供給.B then
				inc(リフトF2供給step)
			end if
			
		case 9
			StageDevice38=StageDevice36
			if ANDA(StageDevice38,$FF)>0 and ANDA(StageDevice38,$FF)<99 then
				検温待ち停止=ON
			end if
			mMC42_モータローラ=OFF
			mMC53_モータローラ=OFF
			inc(リフトF2供給step)
			
		case 10
			搬送コンベアF2排出要求=OFF
			リフトF2供給step=0
		end select

		'--------------------------------------------
		'【 搬送コンベアF2排出
		'--------------------------------------------
		tmr(tim_リフトF2排出,tim_リフトF2排出_val)
		
		select case リフトF2排出step
		case 0

		case 1
			if PH50_釜検知 then
				inc(リフトF2排出step)
			else
				リフトF2排出step=0
			end if
		
		case 2
			ejectMC43_搬送モータ=ON
			inc(リフトF2排出step)

		case 3
			if not(PH50_釜検知) then
				inc(リフトF2排出step)
			end if
	
		case 4
			if PH51_釜検知 and PH52_フタ検知 then
				inc(リフトF2排出step)
			end if
			
		case 5
			tim_リフトF2排出_val=12
			res(tim_リフトF2排出)
			inc(リフトF2排出step)
		
		case 6
			if tim_リフトF2排出.B then
				inc(リフトF2排出step)
			end if
		
		case 7
			StageDevice39=StageDevice38
			ejectMC43_搬送モータ=OFF
			inc(リフトF2排出step)

		case 8
			リフトF2排出step=0
		
		end select
	'===================================================================================================================
	'【 リフタータスク 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case 搬送コンベアGstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 搬送コンベアGAutoRun then
				inc(搬送コンベアGstep)
			else 
				搬送コンベアGstep=0 '終了待機
			end if
		
		case 2
			if  フタ取り完了 then
				inc(搬送コンベアGstep)			
			else
				搬送コンベアGstep=1
			end if
		
		case 3
			if (MC10_搬送モータ正転 or MC10_搬送モータ逆転) or (PH53_釜検知 or PH54_フタ検知) then '排出リフト
				搬送コンベアG動作中=OFF
				搬送コンベアG排出要求=ON
				搬送コンベアGstep=1
			else
				inc(搬送コンベアGstep)		
			end if

		case 4
			if not(PH49_釜検知)  and not(PH50_釜検知) then
				if not(PH49_釜検知) and リフトF1供給step=0 then
					リフトF1供給step=1
				end if
				
				if not(PH50_釜検知) and リフトF2供給step=0 then
					リフトF2供給step=1
				end if

				搬送コンベアGstep=1
			else
				inc(搬送コンベアGstep)
			end if
		

		case 5
			if 搬送コンベアG排出要求=OFF and 搬送コンベアH動作中=OFF and リフトF1供給step=0 and リフトF2供給step=0 then
				inc(搬送コンベアGstep)
			else
				搬送コンベアGstep=1
			end if

		case 6
			if 搬送コンベアGOrg then
				inc(搬送コンベアGstep)
			else
				搬送コンベアGstep=1
			end if
				
		case 7
		
			if 蓋取りユニット許可 then
			
				if フタ取りフタ取り中 then
					if PH51_釜検知 and PH52_フタ検知 then
					'フタ取りされた釜のみの排出 リフトF1、F2から供給をしない。
						'フタ取りされた釜排出
						搬送コンベアGstep=100
					else
						'フタ置きをさせる
						蓋取りユニット排出要求=OFF
						フタ取り完了=OFF
						搬送コンベアGstep=1
					end if

				else
					if リフトF1排出工程中 then
						搬送コンベアGstep=200
					
					else if リフトF2排出工程中 then
						搬送コンベアGstep=300

					else if PH50_釜検知 then
						'リフトF2排出
						リフトF1排出工程中=OFF
						リフトF2排出工程中=ON
						搬送コンベアGstep=300

					else if PH49_釜検知 and not(PH50_釜検知) then
							'リフトF1排出
							リフトF1排出工程中=ON
							リフトF2排出工程中=OFF
							搬送コンベアGstep=200
					else
						搬送コンベアGstep=1
					end if

				end if 'フタ取りフタ取り中
		else
			if PH51_釜検知 and PH52_フタ検知 then
				'フタ取り位置の釜排出
				搬送コンベアGstep=100
			
			else if リフトF1排出工程中 then
				搬送コンベアGstep=200
			
			else if リフトF2排出工程中 then
				搬送コンベアGstep=300

			else if PH50_釜検知 then
				'リフトF2排出
				リフトF1排出工程中=OFF
				リフトF2排出工程中=ON
				搬送コンベアGstep=300

			else if PH49_釜検知 and not(PH50_釜検知) then
					'リフトF1排出
					リフトF1排出工程中=ON
					リフトF2排出工程中=OFF
					搬送コンベアGstep=200
			else
				搬送コンベアGstep=1
			end if
			
		end if

		'--------------------------------------------
		'【 フタ被せ釜排出 】
		'--------------------------------------------
		case 100
			if 搬送コンベアH動作中=OFF and not(PH53_釜検知) and not(PH54_フタ検知) then
				inc(搬送コンベアGstep)
			else
				搬送コンベアGstep=1
			end if

		case 101
			SV46_ストッパstep=1
			フタ取り排出step=1
			inc(搬送コンベアGstep)
			
		case 102
			if SV46_ストッパstep=0 and フタ取り排出step=0 then
				inc(搬送コンベアGstep)
			end if

		case 103
		    if PH53_釜検知 or PH54_フタ検知 then
				搬送コンベアG排出要求=ON
			end if
			蓋取りユニット排出要求=OFF
			フタ取り完了=OFF
			搬送コンベアH準備完了=OFF '搬送コンベアH準備完了: 反転機終了の排出釜がHコンベア上のリフトを超えて数秒たった位置
			搬送コンベアG動作中=OFF
			搬送コンベアGstep=1

		'--------------------------------------------
		'【 F1リフト釜排出 → フタ取り位置まで搬送 -> F2リフト釜供給】
		'--------------------------------------------
		case 200
			if 搬送コンベアH動作中=OFF then
				inc(搬送コンベアGstep)
			else
				搬送コンベアGstep=1
			end if

		case 201
			搬送コンベアG動作中=ON
			'フタ取りシリンダー上昇確認
			if (errpassXSW55_リフト上昇端 or ((XSW55_シリンダ上昇端A and not(pnlPBXSW55_シリンダ上昇端A)) or passXSW55_シリンダ上昇端A)) and (errpassXSW57_リフト上昇端 or ((XSW57_シリンダ上昇端B and not(pnlPBXSW57_シリンダ上昇端B)) or passXSW57_シリンダ上昇端B)) then
				inc(搬送コンベアGstep)
			end if

		
		case 202
			SV46_ストッパstep=1
			フタ取り排出step=1
			inc(搬送コンベアGstep)

		case 203
			if SV46_ストッパstep=0 and フタ取り排出step=0 then
				inc(搬送コンベアGstep)
			end if

		case 204
			 'F1リフトストッパ
			mSV47_リフト=OFF
			errpassXSW56_リフト下降端=OFF
			mSV44_ストッパ=OFF
			errpassXSW60_ストッパ下降端=OFF
			
			mSV48_リフト=OFF	'F2リフト
			errpassXSW58_リフト下降端=OFF
			mSV45_ストッパ=OFF	'F2リフトストッパ
			errpassXSW62_ストッパ下降端=OFF
			
			inc(搬送コンベアGstep)

		case 205
			'F1リフトストッパ
			if (errpassXSW60_ストッパ下降端 or ((XSW60_ストッパ下降端 and not(pnlPBXSW60_ストッパ下降端)) or passXSW60_ストッパ下降端)) and (errpassXSW56_リフト下降端 or ((XSW56_リフト下降端 and not(pnlPBXSW56_リフト下降端)) or passXSW56_リフト下降端)) then
				inc(搬送コンベアGstep)
			end if
		
		case 206
			'F2リフト,リフトストッパ
			if (errpassXSW58_リフト下降端 or ((XSW58_リフト下降端 and not(pnlPBXSW58_リフト下降端)) or passXSW58_リフト下降端)) and (errpassXSW62_ストッパ下降端 or ((XSW62_ストッパ下降端 and not(pnlPBXSW62_ストッパ下降端)) or passXSW62_ストッパ下降端)) then
				inc(搬送コンベアGstep)
			end if

		case 207
			リフトF1排出step=1
			inc(搬送コンベアGstep)
			
		case 208
			if リフトF1排出step=0 then
				inc(搬送コンベアGstep)
			end if
			
		case 209
		    if PH53_釜検知 or PH54_フタ検知 then
				搬送コンベアG排出要求=ON
			end if

			リフトF1排出工程中=OFF
			リフトF2排出工程中=OFF
			蓋取りユニット排出要求=OFF
			フタ取り完了=OFF
			搬送コンベアG動作中=OFF '排出動作時の動作中信号OFF
			搬送コンベアGstep=1

		'--------------------------------------------
		'【 F2リフト釜排出 → フタ取り位置まで搬送  -> F1リフト釜供給】
		'--------------------------------------------
		case 300
			if 搬送コンベアH動作中=OFF then
				inc(搬送コンベアGstep)
			else
				搬送コンベアGstep=1
			end if
		
		case 301
			搬送コンベアG動作中=ON		
			if (errpassXSW55_リフト上昇端 or (XSW55_シリンダ上昇端A and not(pnlPBXSW55_シリンダ上昇端A)) or passXSW55_リフト上昇端) and (errpassXSW57_リフト上昇端 or (XSW57_シリンダ上昇端B and not(pnlPBXSW57_リフト上昇端)) or passXSW57_リフト上昇端) then
				inc(搬送コンベアGstep)
			end if

		case 302
			SV46_ストッパstep=1
			フタ取り排出step=1
			inc(搬送コンベアGstep)

		case 303
			if SV46_ストッパstep=0 and フタ取り排出step=0 then
				inc(搬送コンベアGstep)
			end if

		case 304
			mSV48_リフト=OFF
			errpassXSW58_リフト下降端=OFF
			mSV45_ストッパ=OFF
			errpassXSW62_ストッパ下降端=OFF
			inc(搬送コンベアGstep)

		case 305
			if (errpassXSW58_リフト下降端 or (XSW58_リフト下降端 and not(pnlPBXSW58_リフト下降端)) or XSW58_リフト下降端) and (errpassXSW62_ストッパ下降端 or (XSW62_ストッパ下降端 and not(pnlPBXSW62_ストッパ下降端)) or passXSW62_ストッパ下降端) then
				inc(搬送コンベアGstep)
			end if
		
		case 306
			リフトF2排出step=1
			inc(搬送コンベアGstep)
		
		case 307
			if リフトF2排出step=0 then
				inc(搬送コンベアGstep)
			end if
		
		case 308
		    if PH53_釜検知 or PH54_フタ検知 then
				搬送コンベアG排出要求=ON
			end if
			リフトF1排出工程中=OFF
			リフトF2排出工程中=OFF
			蓋取りユニット排出要求=OFF
			フタ取り完了=OFF
			搬送コンベアG動作中=OFF '排出動作時の動作中信号OFF
			搬送コンベアGstep=1
			
	end select
	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else
	
		if ManualInite=1 then
			mSV44_ストッパ=OFF
			mSV45_ストッパ=OFF
			mSV46_ストッパ=OFF
			mSV49_ストッパ=OFF

			ManualInite=0
		end if

		搬送コンベアGAutoRun=OFF
		
		搬送コンベアGstep=0 '終了

		res(timerr_MC54_モータローラ)'tmr(MC54_モータローラ,timerr_MC54_モータローラ,#65)
		
		'------------------------------------------------
		' [37]
		if ldp(pnlPBSV47_リフト) then
			if mSV47_リフト then
				mSV47_リフト=OFF
			else
				mSV47_リフト=ON
			end if
		end if
		
		
		if ldp(pnlPBSV44_ストッパ) then
			if mSV44_ストッパ then
				mSV44_ストッパ=OFF
			else
				mSV44_ストッパ=ON
			end if
		end if

		if ldp(pnlPBMC41_モータローラ) then
			if mMC41_モータローラ then
				mMC41_モータローラ=OFF
			else
				mMC41_モータローラ=ON
			end if
		end if

		'------------------------------------------------
		' [38]
		if ldp(pnlPBSV48_リフト) then
			if mSV48_リフト then
				mSV48_リフト=OFF
			else
				mSV48_リフト=ON
			end if
		end if
		
		
		if ldp(pnlPBSV45_ストッパ) then
			if mSV45_ストッパ then
				mSV45_ストッパ=OFF
			else
				mSV45_ストッパ=ON
			end if
		end if

		if ldp(pnlPBMC42_モータローラ) then
			if mMC42_モータローラ then
				mMC42_モータローラ=OFF
			else
				mMC42_モータローラ=ON
			end if
		end if

		'------------------------------------------------
		' [39]
		if ldp(pnlPBSV46_ストッパ) then
			if mSV46_ストッパ then
				mSV46_ストッパ=OFF
			else
				mSV46_ストッパ=ON
			end if
		end if
		'------------------------------------------------
		' [40]
		if ldp(pnlPBSV50_リフト) then
			if mSV50_リフト then
				mSV50_リフト=OFF
			else
				mSV50_リフト=ON
			end if
		end if
		
		
		if ldp(pnlPBSV49_ストッパ) then
			if mSV49_ストッパ then
				mSV49_ストッパ=OFF
			else
				mSV49_ストッパ=ON
			end if
		end if

		if ldp(pnlPBMC54_モータローラ) then
			if mMC54_モータローラ then
				mMC54_モータローラ=OFF
			else
				mMC54_モータローラ=ON
			end if
		end if

		'------------------------------------------------
		if ldp(pnlPBMC43_搬送モータ) then
			if mMC43_搬送モータ then
				mMC43_搬送モータ=OFF
			else if ((XSW55_シリンダ上昇端A and not(pnlPBXSW55_シリンダ上昇端A)) or passXSW55_シリンダ上昇端A) and ((XSW57_シリンダ上昇端B and not(pnlPBXSW57_シリンダ上昇端B)) or passXSW57_シリンダ上昇端B) then
				mMC43_搬送モータ=ON
			end if
		end if
			
	end if '搬送コンベアGEmgStep and not(搬送コンベアGOrgErrStep)

	'===================================================================================================================
	'【 搬送コンベアGOrgErr処理 】
	else

		res(tim_XSW55_リフト上昇端)
		res(tim_XSW56_リフト下降端)
		res(tim_XSW59_ストッパ上昇端)
		res(tim_XSW60_ストッパ下降端)
		res(tim_XSW57_リフト上昇端)
		res(tim_XSW58_リフト下降端)
		res(tim_XSW61_ストッパ上昇端)
		res(tim_XSW62_ストッパ下降端)
		res(tim_XSW63_ストッパ上昇端)
		res(tim_XSW64_ストッパ下降端)
		res(tim_XSW67_リフト上昇端)
		res(tim_XSW68_リフト下降端)
		res(tim_XSW65_ストッパ上昇端)
		res(tim_XSW66_ストッパ下降端)

		res(tim_notXSW55_リフト上昇端)
		res(tim_notXSW56_リフト下降端)
		res(tim_notXSW59_ストッパ上昇端)
		res(tim_notXSW60_ストッパ下降端)
		res(tim_notXSW57_リフト上昇端)
		res(tim_notXSW58_リフト下降端)
		res(tim_notXSW61_ストッパ上昇端)
		res(tim_notXSW62_ストッパ下降端)
		res(tim_notXSW63_ストッパ上昇端)
		res(tim_notXSW64_ストッパ下降端)
		res(tim_notXSW67_リフト上昇端)
		res(tim_notXSW68_リフト下降端)
		res(tim_notXSW65_ストッパ上昇端)
		res(tim_notXSW66_ストッパ下降端)

		if ResetFlg then
			搬送コンベアGOrgErr=OFF
		end if


	end if

	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else

		搬送コンベアGErr=ON

		pauseMC41_モータローラ=ON
		pauseMC42_モータローラ=ON
		pauseMC43_搬送モータ=ON
		pauseMC54_モータローラ=ON
		
		pauseMC28_モータローラ=ON
		pauseMC53_モータローラ=ON

		res(timerr_MC54_モータローラ)


		select case 搬送コンベアGErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW55_リフト上昇端=OFF
				almXSW56_リフト下降端=OFF
				almXSW59_ストッパ上昇端=OFF
				almXSW60_ストッパ下降端=OFF
				almXSW57_リフト上昇端=OFF
				almXSW58_リフト下降端=OFF
				almXSW61_ストッパ上昇端=OFF
				almXSW62_ストッパ下降端=OFF
				almXSW63_ストッパ上昇端=OFF
				almXSW64_ストッパ下降端=OFF
				almXSW67_リフト上昇端=OFF
				almXSW68_リフト下降端=OFF
				almXSW65_ストッパ上昇端=OFF
				almXSW66_ストッパ下降端=OFF
				almMC54_モータローラ=OFF

				inc(搬送コンベアGErrStep)
			end if
		case 2


			res(tim_XSW55_リフト上昇端)
			res(tim_XSW56_リフト下降端)
			res(tim_XSW59_ストッパ上昇端)
			res(tim_XSW60_ストッパ下降端)
			res(tim_XSW57_リフト上昇端)
			res(tim_XSW58_リフト下降端)
			res(tim_XSW61_ストッパ上昇端)
			res(tim_XSW62_ストッパ下降端)
			res(tim_XSW63_ストッパ上昇端)
			res(tim_XSW64_ストッパ下降端)
			res(tim_XSW67_リフト上昇端)
			res(tim_XSW68_リフト下降端)
			res(tim_XSW65_ストッパ上昇端)
			res(tim_XSW66_ストッパ下降端)

			res(tim_notXSW55_リフト上昇端)
			res(tim_notXSW56_リフト下降端)
			res(tim_notXSW59_ストッパ上昇端)
			res(tim_notXSW60_ストッパ下降端)
			res(tim_notXSW57_リフト上昇端)
			res(tim_notXSW58_リフト下降端)
			res(tim_notXSW61_ストッパ上昇端)
			res(tim_notXSW62_ストッパ下降端)
			res(tim_notXSW63_ストッパ上昇端)
			res(tim_notXSW64_ストッパ下降端)
			res(tim_notXSW67_リフト上昇端)
			res(tim_notXSW68_リフト下降端)
			res(tim_notXSW65_ストッパ上昇端)
			res(tim_notXSW66_ストッパ下降端)

			pauseMC41_モータローラ=OFF
			pauseMC42_モータローラ=OFF
			pauseMC43_搬送モータ=OFF
			pauseMC54_モータローラ=OFF
			
			pauseMC28_モータローラ=OFF
			pauseMC53_モータローラ=OFF

			pauseSV47_リフト=OFF
			'pauseSV44_ストッパ=OFF
			pauseSV48_リフト=OFF
			'pauseSV45_ストッパ=OFF
			pauseSV46_ストッパ=OFF
			pauseSV50_リフト=OFF
			'pauseSV49_ストッパ=OFF


			搬送コンベアGErr=OFF
			搬送コンベアGErrStep=0
		end select

	end if 'if 搬送コンベアGErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case 搬送コンベアGEmgStep
	case 0
		
	case 1
		搬送コンベアGAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (搬送コンベアGAutoMode and 自動搬送AutoMode ) or 搬送コンベアGstep<>0 or リフトF1供給step<>0 or リフトF2供給step<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseMC41_モータローラ=ON
			pauseMC42_モータローラ=ON
			pauseMC54_モータローラ=ON
			pauseMC43_搬送モータ=ON

			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				tim_SV46_ストッパ_stack=tim_SV46_ストッパ.U
				tim_SV47_リフト_stack=tim_SV47_リフト.U
				tim_SV48_リフト_stack=tim_SV48_リフト.U
				tim_SV50_リフト_stack=tim_SV50_リフト.U
				tim_MC41_モータローラ_stack=tim_MC41_モータローラ.U
				tim_MC42_モータローラ_stack=tim_MC42_モータローラ.U
				tim_フタ取り排出_stack=tim_フタ取り排出.U
				tim_リフトF1供給_stack=tim_リフトF1供給.U
				tim_リフトF1排出_stack=tim_リフトF1排出.U
				tim_リフトF2供給_stack=tim_リフトF2供給.U
				tim_リフトF2排出_stack=tim_リフトF2排出.U

				timstack=ON
			end if

			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC41_モータローラ=OFF
			mMC42_モータローラ=OFF
			mMC54_モータローラ=OFF
			mMC43_搬送モータ=OFF

			mSV47_リフト=OFF
			mSV44_ストッパ=OFF
			mSV48_リフト=OFF
			mSV45_ストッパ=OFF
			mSV46_ストッパ=OFF
			mSV49_ストッパ=OFF
			mSV50_リフト=OFF

			'---------------------------------
		end if
		
		'---------------------------------
		inc(搬送コンベアGEmgStep)
	case 2
		if ResetFlg then
			inc(搬送コンベアGEmgStep)
		end if
	case 3
		if (搬送コンベアGAutoMode and 自動搬送AutoMode ) or 搬送コンベアGstep<>0 or リフトF1供給step<>0 or リフトF2供給step<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseMC41_モータローラ=OFF
				pauseMC42_モータローラ=OFF
				pauseMC54_モータローラ=OFF
				pauseMC43_搬送モータ=OFF

				tim_procstep.U=tim_procstep_stack
				tim_SV46_ストッパ.U=tim_SV46_ストッパ_stack
				tim_SV47_リフト.U=tim_SV47_リフト_stack
				tim_SV48_リフト.U=tim_SV48_リフト_stack
				tim_SV50_リフト.U=tim_SV50_リフト_stack
				tim_MC41_モータローラ.U=tim_MC41_モータローラ_stack
				tim_MC42_モータローラ.U=tim_MC42_モータローラ_stack
				tim_フタ取り排出.U=tim_フタ取り排出_stack
				tim_リフトF1供給.U=tim_リフトF1供給_stack
				tim_リフトF1排出.U=tim_リフトF1排出_stack
				tim_リフトF2供給.U=tim_リフトF2供給_stack
				tim_リフトF2排出.U=tim_リフトF2排出_stack
				timerr_MC54_モータローラ.U=timerr_MC54_モータローラ_stack
				
				'---------------------------------
				inc(搬送コンベアGEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(搬送コンベアGEmgStep)		
		end if				
	case 4
		timstack=OFF
		搬送コンベアGEmgStep=0
		搬送コンベアGEmg=OFF
	end select
		
end if 'if 搬送コンベアGEmgStep=0 then
