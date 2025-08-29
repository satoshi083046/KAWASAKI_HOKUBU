'IH炊飯ユニットB
'===================================================================================================================

' 本プログラムはサンプルです。

'
'<<<<<<<	ユニット	>>>>>>>>
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
'------------------------------------------------------------------
' IH炊飯ユニット連動テストプログラム
'------------------------------------------------------------------
if 0 then
	if *pinB搬入コマンド受付可能.B and *pinB搬入受付可能.B then
	
		if IH炊飯ユニット搬入step=0 then
			IH炊飯ユニット搬入step=1
		end if
			
	end if
	
	
	if *pinB搬出コマンド受付可能.B and *pinB搬出要求.B then
		if IH炊飯ユニット搬出step=0 then
			IH炊飯ユニット搬出step=1
		end if
	end if
	
end if


'===================================================================================================================
'【 初期化処理 】
if CR2008 then
    IH炊飯ユニットBAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    IH炊飯ユニットBAutoRun=OFF
    IH炊飯ユニットB許可=ON
    IH炊飯ユニットBOrgErr=OFF
    IH炊飯ユニットBErr=OFF
    IH炊飯ユニットBEmg=OFF
    IH炊飯ユニットBstep=0
    IH炊飯ユニットBErrStep=0
    IH炊飯ユニットBOrgErrStep=0
    IH炊飯ユニットBEmgStep=0
	
	IH炊飯ユニット搬入step=0
	IH炊飯ユニット搬出step=0
	

end if
'===================================================================================================================
'【 原点 】
IH炊飯ユニットBOrg=IH炊飯機B禁止 or (*pinBオンライン.B and *pinB異常.B)

if 自動搬送AutoRun and not(IH炊飯機B禁止) and ldp(not(*pinBオンライン.B) or not(*pinB異常.B)) then
	almIH炊飯機B=ON
	IH炊飯ユニットBErrStep=1

else if ldp(ResetFlg) and almIH炊飯機B=ON then
	almIH炊飯機B=OFF
	IH炊飯ユニットBErrStep=0

end if


'*****************************************************************
if 0 then
'*****************************************************************


'===================================================================================================================
'【 緊急停止 】

'if not(PB非常停止) then
'	IH炊飯ユニットBEmg=ON
'	IH炊飯ユニットBEmgStep=1
'	*poutB非常停止指令.B=ON
'else
'	*poutB非常停止指令.B=OFF
'end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
tmr(**poutBコマンド処理要求.B,tim_コマンド処理要求,#200)
tmr(*poutB搬入指令.B,tim_搬入指令,#200)
tmr(*poutB搬出指令.B,tim_搬出指令,#200)

if ldp(tim_コマンド処理要求) then
	errpassコマンド処理要求=ON
	*poutBコマンド処理要求.B=OFF
	IH炊飯ユニットBErrStep=1

else if ldp(tim_搬入指令.B) then
	errpass搬入指令=ON
	*poutB搬入指令.B=OFF
	IH炊飯ユニットBErrStep=1

else if ldp(tim_搬出指令.B) then
	errpass搬出指令=ON
	*poutB搬出指令.B=OFF
	IH炊飯ユニットBErrStep=1

end if

'===================================================================================================================

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
	if *pinB搬入コマンド受付可能.B and *pinB搬入受付可能.B then
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
	*poutU搬入釜NO.U=*poutU搬入釜NO.U+1
	*poutU通しNo.U=*poutU通しNo.U+1
	*poutD酢重量.D=0
	*poutD釜データ.D=0
	'-----------------------------------
	*poutB搬入指令.B=ON
	errpass搬入指令=OFF
	inc(IH炊飯ユニット搬入step)

case 4
	if not(*pinB搬入コマンド受付可能.B) or errpass搬入指令 then
		inc(IH炊飯ユニット搬入step)
	end if

case 5
	if errpass搬入指令 then
		IH炊飯ユニット搬入step=0
	else
		*poutB搬入指令.B=OFF
		inc(IH炊飯ユニット搬入step)
	end if
	
'
'case x 	
'	コンベアローラ=ON
'	inc(IH炊飯ユニット搬入step)
'case x
'	if *pinB動作中.B then
'		inc(IH炊飯ユニット搬入step)
'	end if
'
'case x
'	if not(*pinB動作中.B) and *pinB搬入口センサ.B then
'		コンベアローラ=OFF
'		inc(IH炊飯ユニット搬入step)	
'   end if
'
case 6
	if not(*pinB搬入受付可能.B) then
		inc(IH炊飯ユニット搬入step)
	end if

case 7
	if *pinB搬入受付可能.B then
		inc(IH炊飯ユニット搬入step)
	end if

case 8
	IH炊飯ユニット搬入step=0
	
end select

'------------------------------------------------------------------
' IH炊飯ユニット搬出
'------------------------------------------------------------------
tmr(tim_IH炊飯ユニット搬出,tim_IH炊飯ユニット搬出_val)
select case IH炊飯ユニット搬出step
case 0
case 1
	if *pinBオンライン.B and *pinB異常.B then
		inc(IH炊飯ユニット搬出step)
	else
		IH炊飯ユニット搬出step=0
	end if

case 2
	if *pinB搬出コマンド受付可能.B and *pinB搬出要求.B then
		inc(IH炊飯ユニット搬出step)
	else
		IH炊飯ユニット搬出step=0
	end if

case 3
	*poutB搬出指令.B=ON
	errpass搬出指令=OFF
	inc(IH炊飯ユニット搬出step)

case 4
	if not(*pinB搬出コマンド受付可能.B) or errpass搬出指令 then
		inc(IH炊飯ユニット搬出step)
	end if

case 5
	if errpass搬出指令 then
		IH炊飯ユニット搬出step=0
	else
		*poutB搬出指令.B=OFF
		inc(IH炊飯ユニット搬出step)
	end if
'
'case x 	
'	コンベアローラ=ON
'	inc(IH炊飯ユニット搬出step)
'case x
'	if not(*pinB搬出要求.B) then
'		inc(IH炊飯ユニット搬出step)
'	end if
'
'case x
'	if 	PH25_釜検知 then
'		コンベアローラ=OFF
'		inc(IH炊飯ユニット搬出step)
'	 end if
case 6
	搬出アイテムNOB=*pinU搬出アイテムNO.U '空釜  99

	if IH搬入炊飯釜カウント>0 and 搬出アイテムNOB<99 then
		dec(IH搬入炊飯釜カウント)
	end if
	
	IH炊飯ユニット搬出step=0
	
end select
'------------------------------------------------------------------




	
'===================================================================================================================

if IH炊飯ユニットBEmgStep=0 then  
	
	if IH炊飯ユニットBErrStep=0 then
	
	if not(IH炊飯ユニットBOrgErr) then

	if (IH炊飯ユニットBAutoMode and 自動搬送AutoMode ) or IH炊飯ユニットBstep<>0 or IH炊飯ユニット搬入step<>0 or IH炊飯ユニット搬出step<>0 then
		
		if not(IH炊飯ユニットBAutoMode and 自動搬送AutoMode ) then
			IH炊飯ユニットBAutoRun=OFF
		end if


	'===================================================================================================================
	'【 プロセス処理 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case IH炊飯ユニットBstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
			IH炊飯ユニットBStatusMsg=#0

		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' 作業工程を振り分ける
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if IH炊飯ユニットBAutoRun then				
				inc(IH炊飯ユニットBstep)
			else 
				IH炊飯ユニットBstep=0 '終了待機
			end if

		case 2
		' [ 蓋カマ移動停止確認 ]
			if IH炊飯ユニットB排出要求=OFF and  搬送コンベアC動作中=OFF then

				'[ 自ステージに"釜"有検出 ]
					if PH19_釜検知 and PH20_フタ検知 then
						IH炊飯ユニットBStatusMsg=#42	'	フタ置き中
						inc(IH炊飯ユニットBstep) 'フタ被せ
						
				'[ 自ステージに"フタ"有検出 ]	
					else if not(PH19_釜検知) and PH20_フタ検知 then 
							IH炊飯ユニットBStatusMsg=#40	'	フタ取り中
							inc(IH炊飯ユニットBstep) 'フタ取り
				
				'[ 自ステージに"釜フタ"なし ]
						else
							IH炊飯ユニットB排出要求=ON
							IH炊飯ユニットBstep=1  '終了
					end if
			
			else
			
				IH炊飯ユニットBstep=1
			
			end if
		
		case 3
		' [ ユニット許可検出 ]
			if IH炊飯ユニットB許可 then
				IH炊飯ユニットBstep=100 'プロセス処理
			else
				IH炊飯ユニットB排出要求=ON
				IH炊飯ユニットBstep=1
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		'プロセス処理
		case 100
			if フタ被せ完了 then '搬送移動でOFF
				IH炊飯ユニットB排出要求=ON
				IH炊飯ユニットBstep=1
			else
				if フタ被せフタ取り中 and  PH19_釜検知 and PH20_フタ検知 then
					inc(IH炊飯ユニットBstep) 'フタ被せ処理
				else if not(フタ被せフタ取り中) and  not(PH19_釜検知) and PH20_フタ検知 then
					IH炊飯ユニットBstep=150 'フタ取り処理
				else
					IH炊飯ユニットB排出要求=ON
					IH炊飯ユニットBstep=1
				end if
			end if

		'------------------------------------------------------
		end select

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		IH炊飯ユニットBAutoRun=OFF
		
		IH炊飯ユニットBstep=0 '終了

		'------------------------------------------------------
	end if 'IH炊飯ユニットBAutoMode
	'===================================================================================================================
	'【 IH炊飯ユニットBOrgErr処理 】
	else
		
		if ResetFlg then
			IH炊飯ユニットBOrgErr=OFF
		end if

	end if

	
	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else

		IH炊飯ユニットBErr=ON

		select case IH炊飯ユニットBErrStep
		case 0
		case 1
			if ResetFlg then
				
				inc(IH炊飯ユニットBErrStep)
			end if
		case 2
			パラメータ書込みstep=0
			IH炊飯ユニット搬入step=0
			IH炊飯ユニット搬出step=0
			IH炊飯ユニットBErr=OFF
			IH炊飯ユニットBErrStep=0
		end select
		

	end if 'if IH炊飯ユニットBErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case IH炊飯ユニットBEmgStep
	
	case 1
		IH炊飯ユニットBAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if IH炊飯ユニットBstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
		
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
		
			'---------------------------------
		end if
		
		'---------------------------------
		inc(IH炊飯ユニットBEmgStep)
	case 2
		if ResetFlg then
			inc(IH炊飯ユニットBEmgStep)
		end if
	case 3
		if  IH炊飯ユニットBstep<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				
				
				
				'---------------------------------
				inc(IH炊飯ユニットBEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(IH炊飯ユニットBEmgStep)		
		end if				
	case 4
		IH炊飯ユニットBEmgStep=0
		IH炊飯ユニットBEmg=OFF
	end select
		
end if 'if IH炊飯ユニットBEmgStep=0 then

'*****************************************************************
end if
'*****************************************************************
