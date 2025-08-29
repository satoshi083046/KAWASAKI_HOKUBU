'搬送コンベアC2
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	搬送コンベアC2
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
'IH炊飯ユニットA
' [Rx ]---------------------------------
adrset(R47600,pinBオンライン.D)
adrset(R47601,pinB異常.D)
adrset(R47602,pinB動作中.D)
adrset(R47603,pinB搬入コマンド受付可能.D)
adrset(R47604,pinB搬入受付可能.D)
adrset(R47605,pinB搬出要求.D)
adrset(R47606,pinB搬入口センサ.D)
adrset(R47607,pinB搬出口センサ.D)
adrset(R47608,pinB搬出コマンド受付可能.D)

adrset(R47700,pinBコマンド処理応答.D)
adrset(R47701,pinB読出書込設定.D)
' [Ry ]---------------------------------
adrset(R51600,poutB非常停止指令.D)
adrset(R51601,poutB搬入指令.D)
adrset(R51602,poutB搬出指令.D)

adrset(R51700,poutBコマンド処理要求.D)
adrset(R51701,poutB読出書込設定.D)
' [Wr ]---------------------------------
adrset(DM12100,pinU搬出アイテムNO.D)
adrset(DM12101,pinU搬出釜NO.D)
adrset(DM12102,pinU通しNo.D)
adrset(DM12103,pinD酢重量.D)

adrset(DM12105,pinD釜データ.D)


adrset(DM12108,pinUアイテム登録CH1.D)
adrset(DM12109,pinUアイテム登録CH2.D)
adrset(DM12110,pinUアイテム登録CH3.D)
adrset(DM12111,pinUアイテム登録CH4.D)
adrset(DM12112,pinUアイテム登録CH5.D)
adrset(DM12113,pinUアイテム登録CH6.D)
adrset(DM12114,pinUアイテム登録CH7.D)
adrset(DM12115,pinUコマンドNo応答.D)
adrset(DM12116,pinUコマンドデータ0.D)
adrset(DM12117,pinUコマンドデータ1.D)
adrset(DM12118,pinUコマンドデータ2.D)
adrset(DM12119,pinUコマンドデータ3.D)
adrset(DM12120,pinUコマンドデータ4.D)
adrset(DM12121,pinUコマンドデータ5.D)
adrset(DM12122,pinUコマンドデータ6.D)
adrset(DM12123,pinUコマンドデータ7.D)
adrset(DM12124,pinUコマンドデータ8.D)
adrset(DM12125,pinUコマンドデータ9.D)
adrset(DM12126,pinUコマンドデータ10.D)
adrset(DM12127,pinUコマンドデータ11.D)
adrset(DM12128,pinUコマンドデータ12.D)
adrset(DM12129,pinUコマンドデータ13.D)
adrset(DM12130,pinUコマンドデータ14.D)
adrset(DM12131,pinUコマンドデータ15.D)
' [Ww ]---------------------------------
adrset(DM12612,poutU搬入アイテムNO.D)
adrset(DM12613,poutU搬入釜NO.D)
adrset(DM12614,poutU通しNo.D)
adrset(DM12615,poutD酢重量.D)

adrset(DM12617,poutD釜データ.D)


adrset(DM12627,poutUコマンドNo.D)
adrset(DM12628,poutUコマンドデータ0.D)
adrset(DM12629,poutUコマンドデータ1.D)
adrset(DM12630,poutUコマンドデータ2.D)
adrset(DM12631,poutUコマンドデータ3.D)
adrset(DM12632,poutUコマンドデータ4.D)
adrset(DM12633,poutUコマンドデータ5.D)
adrset(DM12634,poutUコマンドデータ6.D)
adrset(DM12635,poutUコマンドデータ7.D)
adrset(DM12636,poutUコマンドデータ8.D)
adrset(DM12637,poutUコマンドデータ9.D)
adrset(DM12638,poutUコマンドデータ10.D)
adrset(DM12639,poutUコマンドデータ11.D)
adrset(DM12640,poutUコマンドデータ12.D)
adrset(DM12641,poutUコマンドデータ13.D)
adrset(DM12642,poutUコマンドデータ14.D)
adrset(DM12643,poutUコマンドデータ15.D)
' --------------------------------------

'===================================================================================================================
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理

    搬送コンベアC2AutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    搬送コンベアC2AutoRun=OFF
    搬送コンベアC2許可=ON
    搬送コンベアC2OrgErr=OFF
    搬送コンベアC2Err=OFF
    搬送コンベアC2Emg=OFF
    搬送コンベアC2step=0
    搬送コンベアC2ErrStep=0
    搬送コンベアC2OrgErrStep=0
    搬送コンベアC2EmgStep=0

	SV28_ストッパstep=0
	MC15_搬送モータ供給step=0
	IH炊飯ユニット搬入step=0
	
	
	if SSW3_自動モード then	
		ManualInite=1
	else
		ManualInite=0	
	end if
	
end if
'===================================================================================================================
'【 原点 】
搬送コンベアC2Org= ((XSW37_ストッパ上昇端 and not(pnlPBXSW37_ストッパ上昇端)) or passXSW37_ストッパ上昇端) or ((XSW36_ストッパ下降端 and not(pnlPBXSW36_ストッパ下降端)) or passXSW36_ストッパ下降端)
搬送コンベアC2Org= 搬送コンベアC2Org and (((XSW34_リフト上昇端 and not(pnlPBXSW34_リフト上昇端)) or passXSW34_リフト上昇端) or ((XSW35_リフト下降端 and not(pnlPBXSW35_リフト下降端)) or passXSW35_リフト下降端))

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	搬送コンベアC2Emg=ON
	搬送コンベアC2EmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
tmr(not(SV29_ストッパ) and not(XSW36_ストッパ下降端) and not(pnlPBXSW36_ストッパ下降端),tim_notXSW36_ストッパ下降端,#30)
tmr(SV29_ストッパ and not(XSW37_ストッパ上昇端) and not(pnlPBXSW37_ストッパ上昇端),tim_notXSW37_ストッパ上昇端,#30)
tmr(not(SV28_リフト) and not(XSW35_リフト下降端) and not(pnlPBXSW35_リフト下降端), tim_notXSW35_リフト下降端,#30)
tmr(SV28_リフト and not(XSW34_リフト上昇端) and not(pnlPBXSW34_リフト上昇端), tim_notXSW34_リフト上昇端,#30)

'tmr(SV29_ストッパ and XSW36_ストッパ下降端 and not(pnlPBXSW36_ストッパ下降端),tim_XSW36_ストッパ下降端,#20)
if LDF(SV29_ストッパ) and XSW36_ストッパ下降端 and not(pnlPBXSW36_ストッパ下降端) and not(pauseSV29_ストッパ) then
	SET(tim_XSW36_ストッパ下降端)
end if
'tmr(not(SV29_ストッパ) and XSW37_ストッパ上昇端 and not(pnlPBXSW37_ストッパ上昇端),tim_XSW37_ストッパ上昇端,#20)
if LDP(SV29_ストッパ) and XSW37_ストッパ上昇端 and not(pnlPBXSW37_ストッパ上昇端) then
	SET(tim_XSW37_ストッパ上昇端)
end if
'tmr(SV28_リフト and XSW35_リフト下降端 and not(pnlPBXSW35_リフト下降端), tim_XSW35_リフト下降端,#20)
if LDF(SV28_リフト)  and XSW35_リフト下降端 and not(pnlPBXSW35_リフト下降端) and not(pauseSV28_リフト) then
	SET(tim_XSW35_リフト下降端)
end if
'tmr(not(SV28_リフト) and XSW34_リフト上昇端 and not(pnlPBXSW34_リフト上昇端), tim_XSW34_リフト上昇端,#20)
if LDP(SV28_リフト) and XSW34_リフト上昇端 and not(pnlPBXSW34_リフト上昇端) then
	SET(tim_XSW34_リフト上昇端)
end if

'tms(not(SV29_ストッパ),passtimXSW36_ストッパ下降端,passtimXSW36_ストッパ下降端_val)
'tms(SV29_ストッパ, passtimXSW37_ストッパ上昇端,passtimXSW37_ストッパ上昇端_val)
tms(not(SV28_リフト),passtimXSW35_リフト下降端,passtimXSW35_リフト下降端_val)
tms(SV28_リフト,passtimXSW34_リフト上昇端,passtimXSW34_リフト上昇端_val)

'-- stage [11]
if ldp(tim_XSW36_ストッパ下降端.B) or ldp(tim_notXSW36_ストッパ下降端.B) then
	errpassXSW36_ストッパ下降端=ON
	almXSW36_ストッパ下降端=ON
	pnlPBXSW36_ストッパ下降端=ON
	搬送コンベアC2ErrStep=1

else if ldp(tim_XSW37_ストッパ上昇端.B) or ldp(tim_notXSW37_ストッパ上昇端.B) then
	errpassXSW37_ストッパ上昇端=ON
	pauseSV29_ストッパ=ON
	almXSW37_ストッパ上昇端=ON
	pnlPBXSW37_ストッパ上昇端=ON
	搬送コンベアC2ErrStep=1

else if ldp(tim_XSW34_リフト上昇端.B) or ldp(tim_notXSW34_リフト上昇端.B) then
	errpassXSW34_リフト上昇端=ON
	almXSW34_リフト上昇端=ON
	pnlPBXSW34_リフト上昇端=ON
	搬送コンベアC2ErrStep=1

else if ldp(tim_XSW35_リフト下降端.B) or ldp(tim_notXSW35_リフト下降端.B) then
	errpassXSW35_リフト下降端=ON
	almXSW35_リフト下降端=ON
	pnlPBXSW35_リフト下降端=ON
	搬送コンベアC2ErrStep=1

end if

	

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 搬送コンベアC2AutoMode	自動モード セレクトスイッチ
'System :: 搬送コンベアC2AutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 搬送コンベアC2Emg	その場停止


if 搬送コンベアC2EmgStep=0 then  
	
	if 搬送コンベアC2ErrStep=0  then

	if not(搬送コンベアC2OrgErr) then

	if (搬送コンベアC2AutoMode and 自動搬送AutoMode ) or 搬送コンベアC2step<>0 then
	
		if ManualInite=1 then		
			mSV25_ストッパ=ON
			mSV27_ストッパ=ON
			ManualInite=0
		end if
	
		if not(搬送コンベアC2AutoMode and 自動搬送AutoMode ) then
			搬送コンベアC2AutoRun=OFF
		end if
	
	tmr(PH21_釜検知,timdly_PH21_釜検知,2)
	tmr(not(PH21_釜検知),timdly_notPH21_釜検知,20)
	tmr(PH22_釜検知,timdly_PH22_釜検知,2)	
	tmr(not(PH22_釜検知),timdly_notPH22_釜検知,20)
	
	'-----------------------------------------------------------------
	' ストッパON/OFFタイミングタスク
	'-----------------------------------------------------------------
	tmr(tim_SV28_ストッパ, tim_SV28_ストッパ_val) 'リフトストッパ
	select case SV28_ストッパstep
	case 0

	case 1
		mSV28_リフト=OFF
		errpassXSW35_リフト下降端=OFF
		inc(SV28_ストッパstep)
	
	case 2
		if errpassXSW35_リフト下降端 or ((XSW35_リフト下降端 and not(pnlPBXSW35_リフト下降端)) or passXSW35_リフト下降端) then
			inc(SV28_ストッパstep)
		end if
	
	case 3
		mSV29_ストッパ=ON
		errpassXSW37_ストッパ上昇端=OFF
		inc(SV28_ストッパstep)

	case 4
		if errpassXSW37_ストッパ上昇端 or ((XSW37_ストッパ上昇端 and not(pnlPBXSW37_ストッパ上昇端)) or passXSW37_ストッパ上昇端) then
			inc(SV28_ストッパstep)
		end if
		
	case 5
		SV28_ストッパstep=0

	end select
	'--------------------------------------------
	'MC15_搬送モータ供給 (フタ被せからリフト）
	tmr(tim_MC15_搬送モータ供給,tim_MC15_搬送モータ供給_val)
	
	select case MC15_搬送モータ供給step
	case 0
	case 1
		if errpassXSW35_リフト下降端 or ((XSW35_リフト下降端 and not(pnlPBXSW35_リフト下降端)) or passXSW35_リフト下降端) then
			errpassXSW37_ストッパ上昇端=OFF
			inc(MC15_搬送モータ供給step)
		end if

	case 2
		if 	errpassXSW37_ストッパ上昇端 or ((XSW37_ストッパ上昇端 and not(pnlPBXSW37_ストッパ上昇端)) or passXSW37_ストッパ上昇端) then
			inc(MC15_搬送モータ供給step)
		end if
	
	case 3
		mMC15_搬送モータ=ON
		inc(MC15_搬送モータ供給step)
		
	case 4
		if (PH22_釜検知 and timdly_PH22_釜検知.B) then
			inc(MC15_搬送モータ供給step)
		end if
		
	case 5
		tim_MC15_搬送モータ供給_val=20 'ブレークタイミング
		res(tim_MC15_搬送モータ供給)
		inc(MC15_搬送モータ供給step)
	
	case 6
		if tim_MC15_搬送モータ供給.B then 
			inc(MC15_搬送モータ供給step)
		end if
	
	case 7
		mMC15_搬送モータ=OFF
		inc(MC15_搬送モータ供給step)
		
	case 8
		MC15_搬送モータ供給step=0
		
	end select

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
		*poutU搬入アイテムNO.U=搬入アイテムNOA '空釜99
		if 搬入アイテムNOA<99 then
			inc(IH搬入炊飯釜カウント)
		end if

		'-----------------------------------
		'搬入釜に対してのラベリング
		*poutU搬入釜NO.U=搬入釜NOA
		*poutU通しNo.U=搬入釜通しNOA
		*poutD酢重量.D=0
		*poutD釜データ.D=0
		'-----------------------------------
		inc(IH炊飯ユニット搬入step)

	case 4
		tim_IH炊飯ユニット搬入_val=1
		res(tim_IH炊飯ユニット搬入)
		inc(IH炊飯ユニット搬入step)

	case 5
		if tim_IH炊飯ユニット搬入.B then
			*poutB搬入指令.B=ON
			errpass搬入指令=OFF
			inc(IH炊飯ユニット搬入step)
		end if
		
	case 6
		if not(*pinB搬入コマンド受付可能.B) or errpass搬入指令 then
			*poutB搬入指令.B=OFF
			inc(IH炊飯ユニット搬入step)
		end if

	case 7
		if errpass搬入指令 then
			IH炊飯ユニット搬入step=0
		else
			inc(IH炊飯ユニット搬入step)
		end if
		
	case 8
		mMC15_搬送モータ=ON
		inc(IH炊飯ユニット搬入step)
	
	case 9
		if not(PH22_釜検知) then
			tim_IH炊飯ユニット搬入_val=50
			res(tim_IH炊飯ユニット搬入)
			inc(IH炊飯ユニット搬入step)
		end if
	
	case 10
		if tim_IH炊飯ユニット搬入.B then
			inc(IH炊飯ユニット搬入step)		
		end if
	
	case 11
		if SV28_ストッパstep=0 then
			SV28_ストッパstep=1

			tim_IH炊飯ユニット搬入_val=50
			res(tim_IH炊飯ユニット搬入)

			inc(IH炊飯ユニット搬入step)
		end if
		
	case 12
		if *pinB動作中.B or tim_IH炊飯ユニット搬入.B then
			tim_IH炊飯ユニット搬入_val=50
			res(tim_IH炊飯ユニット搬入)
			inc(IH炊飯ユニット搬入step)
		end if

	case 13
		if (not(*pinB動作中.B) and *pinB搬入口センサ.B) or tim_IH炊飯ユニット搬入.B  then
			mMC15_搬送モータ=OFF
			tim_IH炊飯ユニット搬入_val=50
			res(tim_IH炊飯ユニット搬入)
			inc(IH炊飯ユニット搬入step)	
	 	end if
	
	case 14
		if not(*pinB搬入受付可能.B) or tim_IH炊飯ユニット搬入.B then
			inc(IH炊飯ユニット搬入step)
		end if

	case 15
		if SV28_ストッパstep=0 then
			inc(IH炊飯ユニット搬入step)
		end if

	case 16
		IH炊飯ユニット搬入step=0
		
	end select

	'--------------------------------------------


	'===================================================================================================================
		tmr(tim_procstep,tim_procstep_val)

		select case 搬送コンベアC2step
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 搬送コンベアC2AutoRun then
				inc(搬送コンベアC2step)
			else 
				搬送コンベアC2step=0 '終了待機
			end if

		case 2
			if 搬送コンベアC2Org then
				inc(搬送コンベアC2step)
			else
				搬送コンベアC2step=1
			end if

		case 3
			if 搬送コンベアC2排出要求=OFF and  搬送コンベアD動作中=OFF then
			
			if IH炊飯機A禁止 or IH炊飯機B禁止 then
				if IH炊飯機B禁止 then
					IHA挿入優先=ON
				else if IH炊飯機A禁止 then
					IHA挿入優先=OFF
				else
					IHA挿入優先=ON				
				end if
			end if
			
				if IHA挿入優先 and PH22_釜検知 then	'IHA炊飯機に釜挿入
					if not(IH炊飯機A禁止) and *pinBオンライン.B and *pinB異常.B and *pinB搬入受付可能.B then
						搬送コンベアC2step=100
					else
						搬送コンベアC2step=1
					end if
				
				else if not(IH炊飯機B禁止) and 搬送コンベアD動作中=OFF and not(IHA挿入優先) and PH22_釜検知 then '搬送コンベアDに排出要求
					搬送コンベアC2step=200
				
				else if 搬送コンベアC排出要求 then 'リフターに釜引き込み
							if PH21_釜検知 then
								搬送コンベアC2step=300
							else							
								搬送コンベアC排出要求=OFF
								搬送コンベアC2動作中=OFF
								搬送コンベアC2step=1
							end if
				else 
					搬送コンベアC2step=1			

				end if
			else
				if 搬送コンベアC2排出要求 and timdly_notPH22_釜検知 then
					搬送コンベアC2排出要求=OFF
				end if
				搬送コンベアC2step=1
			end if
		'----------------------------------------------------------
		case 100
			'IHA挿入
			搬送コンベアC2動作中=ON
			inc(搬送コンベアC2step)
		
		case 101
			mSV28_リフト=OFF
			mSV29_ストッパ=OFF
			errpassXSW35_リフト下降端=OFF
			errpassXSW36_ストッパ下降端=OFF
			inc(搬送コンベアC2step)

		case 102
			if (errpassXSW35_リフト下降端 or (XSW35_リフト下降端 and not(pnlPBXSW35_リフト下降端)) or passXSW35_リフト下降端) and (errpassXSW36_ストッパ下降端 or (XSW36_ストッパ下降端 and not(pnlPBXSW36_ストッパ下降端)) or passXSW36_ストッパ下降端) then
				inc(搬送コンベアC2step)		
			end if

		case 103
			if ANDA(StageDevice11,$200)=$200 or ANDA(StageDevice11,$400)=$400 then '配米A or 配米B
				搬入アイテムNOA=ANDA(StageDevice11,$FF) '釜に米あり
			else
				搬入アイテムNOA=99 '空釜
			end if
		
			*poutU搬入アイテムNO.U=搬入アイテムNOA '空釜99
			'-----------------------------------
			'搬入釜に対してのラベリング
			*poutU搬入釜NO.U=搬入釜NOA
			*poutU通しNo.U=搬入釜通しNOA
			*poutD酢重量.D=0
			*poutD釜データ.D=0
		
			IH炊飯ユニット搬入step=1
			inc(搬送コンベアC2step)
		
		case 104
			if IH炊飯ユニット搬入step=0 then
				inc(搬送コンベアC2step)
			end if

		case 105
			IHA挿入優先=OFF
			搬送コンベアC2動作中=OFF
			搬送コンベアC排出要求=OFF
			搬送コンベアC2step=1

		'----------------------------------------------------------
		case 200
			搬送コンベアC排出要求=OFF
			搬送コンベアC2排出要求=ON
			搬送コンベアC2step=1
		'----------------------------------------------------------
		case 300
			'リフターに釜引き込み
			搬送コンベアC2動作中=ON
			SV28_ストッパstep=1
			MC15_搬送モータ供給step=1
			inc(搬送コンベアC2step)
		
		case 301
			if SV28_ストッパstep=0 and MC15_搬送モータ供給step=0 then
				inc(搬送コンベアC2step)
			end if
		
		case 302
			StageDevice11=StageDevice10
			StageItem11=ANDA(StageDevice11.U,$00FF)  
			StageItem10=ANDA(StageDevice10.U,$00FF)  
			inc(搬送コンベアC2step)
			
		case 303
			搬送コンベアC排出要求=OFF
			搬送コンベアC2動作中=OFF
			搬送コンベアC2step=1
			
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
	
		搬送コンベアC2AutoRun=OFF
		
		搬送コンベアC2step=0 '終了

		if ldp(pnlPBSV29_ストッパ) then
			if mSV29_ストッパ then
				mSV29_ストッパ=OFF
			else
				mSV29_ストッパ=ON
			end if
		end if
		
		if ldp(pnlPBSV28_リフト) then
			if mSV28_リフト then
				mSV28_リフト=OFF
			else
				mSV28_リフト=ON
			end if
		end if
		

	end if '搬送コンベアC2AutoMode and not(搬送コンベアC2OrgErrStep)

	'===================================================================================================================
	'【 搬送コンベアC2OrgErr処理 】
	else
	
		if ResetFlg then
			搬送コンベアC2OrgErr=OFF
		end if


	end if

	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
		res(tim_XSW36_ストッパ下降端)
		res(tim_XSW37_ストッパ上昇端)
		res(tim_XSW35_リフト下降端)
		res(tim_XSW34_リフト上昇端)
	
		搬送コンベアC2Err=ON

		pauseMC15_搬送モータ=ON
		
		select case 搬送コンベアC2ErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW36_ストッパ下降端=OFF
				almXSW37_ストッパ上昇端=OFF
				almXSW35_リフト下降端=OFF
				almXSW34_リフト上昇端=OFF				
				inc(搬送コンベアC2ErrStep)
			end if
		case 2
			搬送コンベアC2Err=OFF
			pauseMC15_搬送モータ=OFF
			pauseSV29_ストッパ=OFF		
			搬送コンベアC2ErrStep=0
		end select

	end if 'if 搬送コンベアC2ErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case 搬送コンベアC2EmgStep
	case 0
		
	case 1
		搬送コンベアC2AutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (搬送コンベアC2AutoMode and 自動搬送AutoMode ) or 搬送コンベアC2step<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseMC15_搬送モータ=ON

			if timstack=OFF then
				tim_SV28_ストッパ_stack=tim_SV28_ストッパ.U
				tim_IH炊飯ユニット搬入_stack=tim_IH炊飯ユニット搬入.U
				tim_procstep_stack=tim_procstep.U
				tim_MC15_搬送モータ供給_stack=tim_MC15_搬送モータ供給.U
		
				timdly_PH22_釜検知_stack=timdly_PH22_釜検知.U
				timdly_PH21_釜検知_stack=timdly_PH21_釜検知.U
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC15_搬送モータ=OFF
			mSV29_ストッパ=OFF
			mSV28_リフト=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(搬送コンベアC2EmgStep)
	case 2
		if ResetFlg then
			inc(搬送コンベアC2EmgStep)
		end if
	case 3
		if (搬送コンベアC2AutoMode and 自動搬送AutoMode ) or 搬送コンベアC2step<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseMC15_搬送モータ=OFF

				tim_SV28_ストッパ.U=tim_SV28_ストッパ_stack
				tim_IH炊飯ユニット搬入.U=tim_IH炊飯ユニット搬入_stack
				tim_procstep.U=tim_procstep_stack
				tim_MC15_搬送モータ供給.U=tim_MC15_搬送モータ供給_stack
				
				res(timdly_PH22_釜検知)
				res(timdly_PH21_釜検知)
				'---------------------------------
				inc(搬送コンベアC2EmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(搬送コンベアC2EmgStep)		
		end if				
	case 4
		timstack=OFF
		搬送コンベアC2EmgStep=0
		搬送コンベアC2Emg=OFF
	end select

end if 'if 搬送コンベアC2EmgStep=0 then

