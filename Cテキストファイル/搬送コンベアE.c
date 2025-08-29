'搬送コンベアE
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	搬送コンベアE


'	SV43_リフト		XSW53_リフト上昇端		PH24_釜検知
'					XSW54_リフト下降端	
'	SV42_ストッパ	XSW51_ストッパ上昇端	
'					XSW52_ストッパ下降端	
'
'	MC45_搬送モータ
'
'===================================================================================================================
'IH炊飯ユニットB
' [Rx ]---------------------------------
adrset(R48400,pinBオンライン.D)
adrset(R48401,pinB異常.D)
adrset(R48402,pinB動作中.D)
adrset(R48403,pinB搬入コマンド受付可能.D)
adrset(R48404,pinB搬入受付可能.D)
adrset(R48405,pinB搬出要求.D)
adrset(R48406,pinB搬入口センサ.D)
adrset(R48407,pinB搬出口センサ.D)
adrset(R48408,pinB搬出コマンド受付可能.D)

adrset(R48500,pinBコマンド処理応答.D)
adrset(R48501,pinB読出書込設定.D)
' [Ry ]---------------------------------
adrset(R52400,poutB非常停止指令.D)
adrset(R52401,poutB搬入指令.D)
adrset(R52402,poutB搬出指令.D)

adrset(R52500,poutBコマンド処理要求.D)
adrset(R52501,poutB読出書込設定.D)
' [Wr ]---------------------------------
adrset(DM12132,pinU搬出アイテムNO.D)
adrset(DM12133,pinU搬出釜NO.D)
adrset(DM12134,pinU通しNo.D)
adrset(DM12135,pinD酢重量.D)

adrset(DM12137,pinD釜データ.D)


adrset(DM12140,pinUアイテム登録CH1.D)
adrset(DM12141,pinUアイテム登録CH2.D)
adrset(DM12142,pinUアイテム登録CH3.D)
adrset(DM12143,pinUアイテム登録CH4.D)
adrset(DM12144,pinUアイテム登録CH5.D)
adrset(DM12145,pinUアイテム登録CH6.D)
adrset(DM12146,pinUアイテム登録CH7.D)
adrset(DM12147,pinUコマンドNo応答.D)
adrset(DM12148,pinUコマンドデータ0.D)
adrset(DM12149,pinUコマンドデータ1.D)
adrset(DM12150,pinUコマンドデータ2.D)
adrset(DM12151,pinUコマンドデータ3.D)
adrset(DM12152,pinUコマンドデータ4.D)
adrset(DM12153,pinUコマンドデータ5.D)
adrset(DM12154,pinUコマンドデータ6.D)
adrset(DM12155,pinUコマンドデータ7.D)
adrset(DM12156,pinUコマンドデータ8.D)
adrset(DM12157,pinUコマンドデータ9.D)
adrset(DM12158,pinUコマンドデータ10.D)
adrset(DM12159,pinUコマンドデータ11.D)
adrset(DM12160,pinUコマンドデータ12.D)
adrset(DM12161,pinUコマンドデータ13.D)
adrset(DM12162,pinUコマンドデータ14.D)
adrset(DM12163,pinUコマンドデータ15.D)
' [Ww ]---------------------------------
adrset(DM12644,poutU搬入アイテムNO.D)
adrset(DM12645,poutU搬入釜NO.D)
adrset(DM12646,poutU通しNo.D)
adrset(DM12647,poutD酢重量.D)

adrset(DM12649,poutD釜データ.D)


adrset(DM12659,poutUコマンドNo.D)
adrset(DM12660,poutUコマンドデータ0.D)
adrset(DM12661,poutUコマンドデータ1.D)
adrset(DM12662,poutUコマンドデータ2.D)
adrset(DM12663,poutUコマンドデータ3.D)
adrset(DM12664,poutUコマンドデータ4.D)
adrset(DM12665,poutUコマンドデータ5.D)
adrset(DM12666,poutUコマンドデータ6.D)
adrset(DM12667,poutUコマンドデータ7.D)
adrset(DM12668,poutUコマンドデータ8.D)
adrset(DM12669,poutUコマンドデータ9.D)
adrset(DM12670,poutUコマンドデータ10.D)
adrset(DM12671,poutUコマンドデータ11.D)
adrset(DM12672,poutUコマンドデータ12.D)
adrset(DM12673,poutUコマンドデータ13.D)
adrset(DM12674,poutUコマンドデータ14.D)
adrset(DM12675,poutUコマンドデータ15.D)
' --------------------------------------

'===================================================================================================================
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理

	搬送コンベアEAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    搬送コンベアEAutoRun=OFF
    搬送コンベアE許可=ON
    搬送コンベアEOrgErr=OFF
    搬送コンベアEErr=OFF
    搬送コンベアEEmg=OFF
    搬送コンベアEstep=0
    搬送コンベアEErrStep=0
    搬送コンベアEOrgErrStep=0
    搬送コンベアEEmgStep=0
	
	IH炊飯ユニット搬入step=0

	if SSW3_自動モード then	
		ManualInite=1
	else
		ManualInite=0	
	end if
	
	
end if

'===================================================================================================================
'【 原点 】
搬送コンベアEOrg=((XSW53_リフト上昇端 and not(pnlPBXSW53_リフト上昇端)) or passXSW53_リフト上昇端) or ((XSW54_リフト下降端 and not(pnlPBXSW54_リフト下降端)) or passXSW54_リフト下降端)
搬送コンベアEOrg=搬送コンベアEOrg and ( ((XSW51_ストッパ上昇端 and not(pnlPBXSW51_ストッパ上昇端)) or passXSW51_ストッパ上昇端) or ((XSW52_ストッパ下降端 and not(pnlPBXSW52_ストッパ下降端)) or passXSW52_ストッパ下降端) )


'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	搬送コンベアEEmg=ON
	搬送コンベアEEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
tmr(SV42_ストッパ and not(XSW51_ストッパ上昇端) and not(pnlPBXSW51_ストッパ上昇端), tim_notXSW51_ストッパ上昇端,#30)
tmr(not(SV42_ストッパ) and not(XSW52_ストッパ下降端) and not(pnlPBXSW52_ストッパ下降端),tim_notXSW52_ストッパ下降端,#30)
tmr(SV43_リフト and not(XSW53_リフト上昇端) and not(pnlPBXSW53_リフト上昇端), tim_notXSW53_リフト上昇端, #30) 
tmr(not(SV43_リフト) and not(XSW54_リフト下降端) and not(pnlPBXSW54_リフト下降端),tim_notXSW54_リフト下降端,#30)

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

'tms(SV42_ストッパ,passtimXSW51_ストッパ上昇端,passtimXSW51_ストッパ上昇端_val)
'tms(not(SV42_ストッパ),passtimXSW52_ストッパ下降端,passtimXSW52_ストッパ下降端_val)
'tms(SV43_リフト,passtimXSW53_リフト上昇端,passtimXSW53_リフト上昇端_val)
'tms(not(SV43_リフト),passtimXSW54_リフト下降端,passtimXSW54_リフト下降端_val)

if ldp(tim_XSW51_ストッパ上昇端.B) or ldp(tim_notXSW51_ストッパ上昇端.B) then
	errpassXSW51_ストッパ上昇端=ON
	almXSW51_ストッパ上昇端=ON
	pnlPBXSW51_ストッパ上昇端=ON
	搬送コンベアEErrStep=1

else if ldp(tim_XSW52_ストッパ下降端.B) or ldp(tim_notXSW52_ストッパ下降端.B) then
	errpassXSW52_ストッパ下降端=ON
	almXSW52_ストッパ下降端=ON
	pnlPBXSW52_ストッパ下降端=ON
	搬送コンベアEErrStep=1

else if ldp(tim_XSW53_リフト上昇端.B) or ldp(tim_notXSW53_リフト上昇端.B) then
	errpassXSW53_リフト上昇端=ON
	almXSW53_リフト上昇端=ON
	pnlPBXSW53_リフト上昇端=ON
	搬送コンベアEErrStep=1

else if ldp(tim_XSW54_リフト下降端.B) or ldp(tim_notXSW54_リフト下降端.B) then
	errpassXSW54_リフト下降端=ON
	almXSW54_リフト下降端=ON
	pnlPBXSW54_リフト下降端=ON
	搬送コンベアEErrStep=1

end if
'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 搬送コンベアEAutoMode	自動モード セレクトスイッチ
'System :: 搬送コンベアEAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 搬送コンベアEEmg	その場停止


if 搬送コンベアEEmgStep=0 then  
	
	if 搬送コンベアEErrStep=0  then

	if not(搬送コンベアEOrgErr) then

	
	tmr(PH24_釜検知,timdly_PH24_釜検知,2)
	
		'------------------------------------------------------------------
		' IH炊飯ユニット搬入
		'------------------------------------------------------------------
		tmr(tim_IH炊飯ユニット搬入,tim_IH炊飯ユニット搬入_val)
		select case IH炊飯ユニット搬入step
		case 0
		case 1
			if *pinBオンライン.B and *pinB異常.B then
				inc(IH炊飯ユニット搬入step)
			else
				IH炊飯ユニット搬入step=0
			end if

		case 2
			if *pinB搬入受付可能.B then
				inc(IH炊飯ユニット搬入step)
			else
				IH炊飯ユニット搬入step=0
			end if

		case 3
			'-----------------------------------
			'炊飯工程データ
			*poutU搬入アイテムNO.U=搬入アイテムNOB '空釜  99
			if 搬入アイテムNOB<99 then
				inc(IH搬入炊飯釜カウント)
			end if			
			'-----------------------------------
			'搬入釜に対してのラベリング
			*poutU搬入釜NO.U=搬入釜NOB
			*poutU通しNo.U=*poutU通しNo.U+1
			*poutD酢重量.D=0
			*poutD釜データ.D=0
			'-----------------------------------
			*poutB搬入指令.B=ON
			errpass搬入指令=OFF
			inc(IH炊飯ユニット搬入step)

		case 4
			if not(*pinB搬入コマンド受付可能.B) or errpass搬入指令 then
				*poutB搬入指令.B=OFF
				inc(IH炊飯ユニット搬入step)
			end if

		case 5
			if errpass搬入指令 then
				IH炊飯ユニット搬入step=0
			else
				inc(IH炊飯ユニット搬入step)
			end if
			
		
		case 6	
			mMC45_搬送モータ=ON
			tim_IH炊飯ユニット搬入_val=80
			res(tim_IH炊飯ユニット搬入)
			inc(IH炊飯ユニット搬入step)
		case 7
			if *pinB動作中.B or tim_IH炊飯ユニット搬入.B then
				tim_IH炊飯ユニット搬入_val=80
				res(tim_IH炊飯ユニット搬入)
				inc(IH炊飯ユニット搬入step)
			end if
		
		case 8
			if (not(*pinB動作中.B) and *pinB搬入口センサ.B) or tim_IH炊飯ユニット搬入.B then
				mMC45_搬送モータ=OFF
				tim_IH炊飯ユニット搬入_val=50
				res(tim_IH炊飯ユニット搬入)
				inc(IH炊飯ユニット搬入step)	
		   end if
		
		case 9
			if not(*pinB搬入受付可能.B) or tim_IH炊飯ユニット搬入.B then
				inc(IH炊飯ユニット搬入step)
			end if

		case 10
'			if *pinB搬入受付可能.B then
				inc(IH炊飯ユニット搬入step)
'			end if

		case 11
			IH炊飯ユニット搬入step=0
			
		end select



	'===================================================================================================================
	'【 リフタータスク 】
	'
	if (搬送コンベアEAutoMode and 自動搬送AutoMode ) or 搬送コンベアEstep<>0 then
	
		if ManualInite=1 then
			mSV42_ストッパ=ON
			mSV29_ストッパ=ON
			ManualInite=0
		end if
		
		if not(搬送コンベアEAutoMode and 自動搬送AutoMode ) then
			搬送コンベアEAutoRun=OFF
		end if

		tmr(tim_procstep,tim_procstep_val)

		select case 搬送コンベアEstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 搬送コンベアEAutoRun then
				inc(搬送コンベアEstep)
			else 
				搬送コンベアEstep=0 '終了待機
			end if
		
		case 2
			if *pinBオンライン.B and *pinB異常.B and *pinB搬入受付可能.B then
				inc(搬送コンベアEstep)
			else
				搬送コンベアEstep=1
			end if
		
		case 3
		' [ 次の搬送コンベア停止確認 ]
			if 搬送コンベアE排出要求=OFF and 搬送コンベアD排出要求 then
				搬送コンベアE動作中=ON
				搬送コンベアEstep=100
			else
				搬送コンベアEstep=1
			end if
			
		case 4  '原点検出
			if 搬送コンベアEOrg then				
				inc(搬送コンベアEstep)
			else
				搬送コンベアEstep=1
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		case 100
			mSV43_リフト=OFF
			errpassXSW54_リフト下降端=OFF
			inc(搬送コンベアEstep)
		
		case 101
			if errpassXSW54_リフト下降端 or ((XSW54_リフト下降端 and not(pnlPBXSW54_リフト下降端)) or passXSW54_リフト下降端) then
				inc(搬送コンベアEstep)
			end if
		
		case 102
			mSV42_ストッパ=OFF
			errpassXSW52_ストッパ下降端=OFF
			inc(搬送コンベアEstep)

		case 103
			if errpassXSW52_ストッパ下降端 or ((XSW52_ストッパ下降端 and not(pnlPBXSW52_ストッパ下降端)) or passXSW52_ストッパ下降端) then
				inc(搬送コンベアEstep)
			end if

		case 104
			mMC45_搬送モータ=ON
			inc(搬送コンベアEstep)
		
		case 105
			if ANDA(StageDevice12,$200)=$200 or ANDA(StageDevice12,$400)=$400 then '配米A or 配米B
				搬入アイテムNOB=ANDA(StageDevice12,$FF) '釜に米あり				
			else
				搬入アイテムNOB=99 '空釜
			end if

			'-----------------------------------
			'炊飯工程データ
			*poutU搬入アイテムNO.U=搬入アイテムNOB '空釜  99
			'-----------------------------------
			'搬入釜に対してのラベリング
			*poutU搬入釜NO.U=搬入釜NOB
			*poutU通しNo.U=搬入釜通しNOB
			*poutD酢重量.D=0
			*poutD釜データ.D=0
			'-----------------------------------
			IH炊飯ユニット搬入step=1
			
			inc(搬送コンベアEstep)

		case 106
			if IH炊飯ユニット搬入step=0 then
				inc(搬送コンベアEstep)
			end if
		
		case 107
			mMC45_搬送モータ=OFF
			inc(搬送コンベアEstep)

		case 108
			搬送コンベアE動作中=OFF
			搬送コンベアD排出要求=OFF
			搬送コンベアE排出要求=OFF
			搬送コンベアEstep=1

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
	
		搬送コンベアEAutoRun=OFF
		
		搬送コンベアEstep=0 '終了

		res(tim_XSW51_ストッパ上昇端)
		res(tim_XSW52_ストッパ下降端)
		res(tim_XSW53_リフト上昇端)
		res(tim_XSW54_リフト下降端)

		
		
		if ldp(pnlPBMC45_搬送モータ) then
			if mMC45_搬送モータ then
				mMC45_搬送モータ=OFF
			else
				mMC45_搬送モータ=ON
			end if
		end if
		
		if ldp(pnlPBSV42_ストッパ) then
			if mSV42_ストッパ then
				mSV42_ストッパ=OFF
			else
				mSV42_ストッパ=ON
			end if
		end if
		
		if ldp(pnlPBSV43_リフト) then
			if mSV43_リフト then
				mSV43_リフト=OFF
			else
				mSV43_リフト=ON
			end if
		end if

	end if '搬送コンベアEAutoMode and not(搬送コンベアEOrgErrStep)

	'===================================================================================================================
	'【 搬送コンベアEOrgErr処理 】
	else
	
		res(tim_notXSW51_ストッパ上昇端)
		res(tim_notXSW52_ストッパ下降端)
		res(tim_notXSW53_リフト上昇端)
		res(tim_notXSW54_リフト下降端)

		res(tim_XSW51_ストッパ上昇端)
		res(tim_XSW52_ストッパ下降端)
		res(tim_XSW53_リフト上昇端)
		res(tim_XSW54_リフト下降端)

		if ResetFlg then
			搬送コンベアEOrgErr=OFF
		end if


	end if

	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else

		搬送コンベアEErr=ON

		pauseMC45_搬送モータ=ON

		select case 搬送コンベアEErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW51_ストッパ上昇端=OFF
				almXSW52_ストッパ下降端=OFF
				almXSW53_リフト上昇端=OFF
				almXSW54_リフト下降端=OFF

				inc(搬送コンベアEErrStep)
			end if
		case 2
			搬送コンベアEErr=OFF

			res(tim_notXSW51_ストッパ上昇端)
			res(tim_notXSW52_ストッパ下降端)
			res(tim_notXSW53_リフト上昇端)
			res(tim_notXSW54_リフト下降端)

			res(tim_XSW51_ストッパ上昇端)
			res(tim_XSW52_ストッパ下降端)
			res(tim_XSW53_リフト上昇端)
			res(tim_XSW54_リフト下降端)

			pauseMC45_搬送モータ=OFF

			搬送コンベアEErrStep=0
		end select

	end if 'if 搬送コンベアEErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else

	select case 搬送コンベアEEmgStep
	case 0
	
	case 1
		搬送コンベアEAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (搬送コンベアEAutoMode and 自動搬送AutoMode ) or 搬送コンベアEstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseMC45_搬送モータ=ON
			
			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				tim_IH炊飯ユニット搬入_stack=tim_IH炊飯ユニット搬入.U
			
				timdly_PH24_釜検知_stack=timdly_PH24_釜検知.U
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC45_搬送モータ=OFF
			mSV42_ストッパ=OFF
			mSV43_リフト=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(搬送コンベアEEmgStep)
	case 2
		if ResetFlg then
			inc(搬送コンベアEEmgStep)
		end if
	case 3
		if (搬送コンベアEAutoMode and 自動搬送AutoMode ) or 搬送コンベアEstep<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseMC45_搬送モータ=OFF

				tim_procstep.U=tim_procstep_stack
				tim_IH炊飯ユニット搬入.U=tim_IH炊飯ユニット搬入_stack
				
				res(timdly_PH24_釜検知)
				'---------------------------------
				inc(搬送コンベアEEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(搬送コンベアEEmgStep)		
		end if				
	case 4
		timstack=OFF
		搬送コンベアEEmgStep=0
		搬送コンベアEEmg=OFF
	end select
		
end if 'if 搬送コンベアEEmgStep=0 then
