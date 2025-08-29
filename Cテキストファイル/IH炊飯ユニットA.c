'IH炊飯ユニットA
'===================================================================================================================

' 本プログラムはサンプルです。

'<<<<<<<	ユニット	>>>>>>>>
'
'	白米は	は アイテムNO=1
'	空釜搬入は アイテムNO=99
'-------------------------------------------------------------------------------------
'  搬入順に搬出させるには、次のこと手順が必要になります。
'  IH炊飯ユニットA,B の 【A,BのNO1_位置は空けておく】
'  IH炊飯ユニットA,B の スタートする【A,Bの釜数と位置を合わせる】
'  IH炊飯ユニットの【自動実行画面】の 搬入位置の番号=NO1_位置 搬出位置の番号=NO1_位置に合わせる。
'===================================================================================================================
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
    IH炊飯ユニットAAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    IH炊飯ユニットAAutoRun=OFF
    IH炊飯ユニットA許可=ON
    IH炊飯ユニットAOrgErr=OFF
    IH炊飯ユニットAErr=OFF
    IH炊飯ユニットAEmg=OFF
    IH炊飯ユニットAstep=0
    IH炊飯ユニットAErrStep=0
    IH炊飯ユニットAOrgErrStep=0
    IH炊飯ユニットAEmgStep=0


	IH炊飯ユニット搬入step=0
	IH炊飯ユニット搬出step=0

end if
'===================================================================================================================
'【 原点 】
IH炊飯ユニットAOrg=IH炊飯機A禁止 or (*pinBオンライン.B and *pinB異常.B) 

if 自動搬送AutoRun and not(IH炊飯機A禁止) and ldp(not(*pinBオンライン.B) or not(*pinB異常.B)) then
	almIH炊飯機A=ON
	IH炊飯ユニットAErrStep=1

else if ldp(ResetFlg) and almIH炊飯機A=ON then
	almIH炊飯機A=OFF
	IH炊飯ユニットAErrStep=0

end if


'*****************************************************************
if 0 then
'*****************************************************************


'===================================================================================================================
'【 緊急停止 】

'if not(PB非常停止) then
'	IH炊飯ユニットAEmg=ON
'	IH炊飯ユニットAEmgStep=1
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
	IH炊飯ユニットAErrStep=1

else if ldp(tim_搬入指令.B) then
	errpass搬入指令=ON
	*poutB搬入指令.B=OFF
	IH炊飯ユニットAErrStep=1

else if ldp(tim_搬出指令.B) then
	errpass搬出指令=ON
	*poutB搬出指令.B=OFF
	IH炊飯ユニットAErrStep=1

end if

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
	*poutU搬入アイテムNO.U=搬入アイテムNOA '空釜99
	if 搬入アイテムNOA<99 then
		inc(IH搬入炊飯釜カウント)
	end if
	'-----------------------------------
	'搬入釜に対してのラベリング
	*poutU搬入釜NO.U=poutU搬入釜NO.U+1
	*poutU通しNo.U=*poutU通しNo.U+1
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
		inc(IH炊飯ユニット搬入step)
	end if

case 7
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
case 8
	if not(*pinB搬入受付可能.B) then
		inc(IH炊飯ユニット搬入step)
	end if

case 9
	if *pinB搬入受付可能.B then
		inc(IH炊飯ユニット搬入step)
	end if

case 10
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
	搬出アイテムNOA=*pinU搬出アイテムNO.U '空釜 99
	
	if IH搬入炊飯釜カウント>0 and 搬出アイテムNOA<99 then
		dec(IH搬入炊飯釜カウント)
	end if

	IH炊飯ユニット搬出step=0
	
end select
'------------------------------------------------------------------
	
'===================================================================================================================
if IH炊飯ユニットAEmgStep=0 then  
	
	if IH炊飯ユニットAErrStep=0 then
	
		'------------------------------------------------------------------
	if not(IH炊飯ユニットAOrgErr) then

	if (IH炊飯ユニットAAutoMode and 自動搬送AutoMode ) or IH炊飯ユニットAstep<>0 or IH炊飯ユニット搬入step<>0 or IH炊飯ユニット搬出step<>0 then
		
		if not(IH炊飯ユニットAAutoMode and 自動搬送AutoMode ) then
			IH炊飯ユニットAAutoRun=OFF
		end if

	'===================================================================================================================
	'【 プロセス処理 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case IH炊飯ユニットAstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
			IH炊飯ユニットAStatusMsg=#0

		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' 作業工程を振り分ける
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if IH炊飯ユニットAAutoRun then				
				inc(IH炊飯ユニットAstep)
			else 
				IH炊飯ユニットAstep=0 '終了待機
			end if

		case 2
		' [ 蓋カマ移動停止確認 ]
			if IH炊飯ユニットA排出要求=OFF and  搬送コンベアC動作中=OFF then

				'[ 自ステージに"釜"有検出 ]
					if PH19_釜検知 and PH20_フタ検知 then
						IH炊飯ユニットAStatusMsg=#42
						inc(IH炊飯ユニットAstep) 'フタ被せ
						
				'[ 自ステージに"フタ"有検出 ]	
					else if not(PH19_釜検知) and PH20_フタ検知 then 
							IH炊飯ユニットAStatusMsg=#40
							inc(IH炊飯ユニットAstep) 'フタ取り
				
				'[ 自ステージに"釜フタ"なし ]
						else
							IH炊飯ユニットA排出要求=ON
							IH炊飯ユニットAstep=1  '終了
					end if
			
			else
			
				IH炊飯ユニットAstep=1
			
			end if
		
		case 3
		' [ ユニット許可検出 ]
			if IH炊飯ユニットA許可 then
				IH炊飯ユニットAstep=100 'プロセス処理
			else
				IH炊飯ユニットA排出要求=ON
				IH炊飯ユニットAstep=1
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		'プロセス処理
		case 100
			if フタ被せ完了 then '搬送移動でOFF
				IH炊飯ユニットA排出要求=ON
				IH炊飯ユニットAstep=1
			else
				if フタ被せフタ取り中 and  PH19_釜検知 and PH20_フタ検知 then
					inc(IH炊飯ユニットAstep) 'フタ被せ処理
				else if not(フタ被せフタ取り中) and  not(PH19_釜検知) and PH20_フタ検知 then
					IH炊飯ユニットAstep=150 'フタ取り処理
				else
					IH炊飯ユニットA排出要求=ON
					IH炊飯ユニットAstep=1
				end if
			end if

		'------------------------------------------------------
		end select

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		IH炊飯ユニットAAutoRun=OFF
		
		IH炊飯ユニットAstep=0 '終了

		'------------------------------------------------------
	end if 'IH炊飯ユニットAAutoMode
	'===================================================================================================================
	'【 IH炊飯ユニットAOrgErr処理 】
	else
	
		if ResetFlg then
			IH炊飯ユニットAOrgErr=OFF
		end if		

	end if

	
	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else

		IH炊飯ユニットAErr=ON

		select case IH炊飯ユニットAErrStep
		case 0
		case 1
			if ResetFlg then
				
				inc(IH炊飯ユニットAErrStep)
			end if
		case 2
			パラメータ書込みstep=0
			IH炊飯ユニット搬入step=0
			IH炊飯ユニット搬出step=0
			IH炊飯ユニットAErr=OFF
			IH炊飯ユニットAErrStep=0
		end select
		

	end if 'if IH炊飯ユニットAErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else

	select case IH炊飯ユニットAEmgStep
	
	case 1
		IH炊飯ユニットAAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if IH炊飯ユニットAstep<>0 then
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
		inc(IH炊飯ユニットAEmgStep)
	case 2
		if ResetFlg then
			inc(IH炊飯ユニットAEmgStep)
		end if
	case 3
		if  IH炊飯ユニットAstep<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				
				
				
				'---------------------------------
				inc(IH炊飯ユニットAEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(IH炊飯ユニットAEmgStep)		
		end if				
	case 4
		IH炊飯ユニットAEmgStep=0
		IH炊飯ユニットAEmg=OFF
	end select
		
end if 'if IH炊飯ユニットAEmgStep=0 then

'*****************************************************************
end if
'*****************************************************************
