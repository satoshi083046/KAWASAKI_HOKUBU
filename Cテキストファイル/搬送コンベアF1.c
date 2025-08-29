'搬送コンベアF1
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	搬送コンベアF1
'
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
'===================================================================================================================


'【 初期化処理 】
if CR2008 then '電源ON時初期化処理

	搬送コンベアF1AutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    搬送コンベアF1AutoRun=OFF
    搬送コンベアF1許可=ON
    搬送コンベアF1OrgErr=OFF
    搬送コンベアF1Err=OFF
    搬送コンベアF1Emg=OFF
    搬送コンベアF1step=0
    搬送コンベアF1ErrStep=0
    搬送コンベアF1OrgErrStep=0
    搬送コンベアF1EmgStep=0

	if SSW3_自動モード then	
		ManualInite=1
	else
		ManualInite=0	
	end if

	モータローラ排出step=0
	IH炊飯ユニット搬出step=0
	
end if

'===================================================================================================================
'【 原点 】
搬送コンベアF1Org=1

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	搬送コンベアF1Emg=ON
	搬送コンベアF1EmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
if 自動搬送AutoMode then
	tmr(MC17_モータローラ,timerr_MC17_モータローラ,60)
	tmr(MC18_モータローラ,timerr_MC18_モータローラ,60)
	tmr(MC19_モータローラ,timerr_MC19_モータローラ,60)
	tmr(MC20_モータローラ,timerr_MC20_モータローラ,60)
	tmr(MC21_モータローラ,timerr_MC21_モータローラ,60)
	tmr(MC22_モータローラ,timerr_MC22_モータローラ,60)
	tmr(MC23_モータローラ,timerr_MC23_モータローラ,60)
	tmr(MC24_モータローラ,timerr_MC24_モータローラ,60)
	tmr(MC25_モータローラ,timerr_MC25_モータローラ,60)
	tmr(MC26_モータローラ,timerr_MC26_モータローラ,60)
	tmr(MC27_モータローラ,timerr_MC27_モータローラ,60)
	tmr(MC28_モータローラ,timerr_MC28_モータローラ,60)
else
	res(timerr_MC17_モータローラ)
	res(timerr_MC18_モータローラ)
	res(timerr_MC19_モータローラ)
	res(timerr_MC20_モータローラ)
	res(timerr_MC21_モータローラ)
	res(timerr_MC22_モータローラ)
	res(timerr_MC23_モータローラ)
	res(timerr_MC24_モータローラ)
	res(timerr_MC25_モータローラ)
	res(timerr_MC26_モータローラ)
	res(timerr_MC27_モータローラ)
	res(timerr_MC28_モータローラ)
end if

if ldp(timerr_MC17_モータローラ.B) then
	almMC17_モータローラ=ON
	搬送コンベアF1ErrStep=1

else if ldp(timerr_MC18_モータローラ.B) then
	almMC18_モータローラ=ON
	搬送コンベアF1ErrStep=1

else if ldp(timerr_MC19_モータローラ.B) then
	almMC19_モータローラ=ON
	搬送コンベアF1ErrStep=1

else if ldp(timerr_MC20_モータローラ.B) then
	almMC20_モータローラ=ON
	搬送コンベアF1ErrStep=1

else if ldp(timerr_MC21_モータローラ.B) then
	almMC21_モータローラ=ON
	搬送コンベアF1ErrStep=1

else if ldp(timerr_MC22_モータローラ.B) then
	almMC22_モータローラ=ON
	搬送コンベアF1ErrStep=1

else if ldp(timerr_MC23_モータローラ.B) then
	almMC23_モータローラ=ON
	搬送コンベアF1ErrStep=1

else if ldp(timerr_MC24_モータローラ.B) then
	almMC24_モータローラ=ON
	搬送コンベアF1ErrStep=1

else if ldp(timerr_MC25_モータローラ.B) then
	almMC25_モータローラ=ON
	搬送コンベアF1ErrStep=1

else if ldp(timerr_MC26_モータローラ.B) then
	almMC26_モータローラ=ON
	搬送コンベアF1ErrStep=1

else if ldp(timerr_MC27_モータローラ.B) then
	almMC27_モータローラ=ON
	搬送コンベアF1ErrStep=1

else if ldp(timerr_MC28_モータローラ.B) then
	almMC28_モータローラ=ON
	搬送コンベアF1ErrStep=1

end if




'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 搬送コンベアF1AutoMode	自動モード セレクトスイッチ
'System :: 搬送コンベアF1AutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 搬送コンベアF1Emg	その場停止


if 搬送コンベアF1EmgStep=0 then  
	
	if 搬送コンベアF1ErrStep=0  then

	if not(搬送コンベアF1OrgErr) then

	
	tmr(PH25_釜検知,timdly_PH25_釜検知,2)
	tmr(PH26_釜検知,timdly_PH26_釜検知,2)
	tmr(PH27_釜検知,timdly_PH27_釜検知,2)
	tmr(PH28_釜検知,timdly_PH28_釜検知,2)
	tmr(PH29_釜検知,timdly_PH29_釜検知,2)
	tmr(PH30_釜検知,timdly_PH30_釜検知,2)
	tmr(PH31_釜検知,timdly_PH31_釜検知,2)
	tmr(PH32_釜検知,timdly_PH32_釜検知,2)
	tmr(PH33_釜検知,timdly_PH33_釜検知,2)
	tmr(PH34_釜検知,timdly_PH34_釜検知,2)
	tmr(PH35_釜検知,timdly_PH35_釜検知,2)
	tmr(PH36_釜検知,timdly_PH36_釜検知,2)
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
		
		tim_IH炊飯ユニット搬出_val=50
		res(tim_IH炊飯ユニット搬出)
		
		inc(IH炊飯ユニット搬出step)

	case 4
		if not(*pinB搬出コマンド受付可能.B) or errpass搬出指令 or tim_IH炊飯ユニット搬出.B then
			inc(IH炊飯ユニット搬出step)
		end if

	case 5
		if errpass搬出指令 then
			IH炊飯ユニット搬出step=0
		else
			*poutB搬出指令.B=OFF
			inc(IH炊飯ユニット搬出step)
		end if
	
	case 6 	
		ejectMC17_モータローラ=ON
		inc(IH炊飯ユニット搬出step)
	
	case 7
		'if not(*pinB搬出要求.B) then
			inc(IH炊飯ユニット搬出step)
		'end if
	
	case 8
		if 	PH25_釜検知 and timdly_PH25_釜検知 then
			inc(IH炊飯ユニット搬出step)
		 end if
	

	case 9
		tim_IH炊飯ユニット搬出_val=6
		res(tim_IH炊飯ユニット搬出)
		inc(IH炊飯ユニット搬出step)
	
	case 10
		if tim_IH炊飯ユニット搬出.B then
			inc(IH炊飯ユニット搬出step)
		end if

	case 11
		ejectMC17_モータローラ=OFF
		inc(IH炊飯ユニット搬出step)

	case 12
		搬出アイテムNOA=*pinU搬出アイテムNO.U '空釜 99
		
		StageDevice13=搬出アイテムNOA
		
		if IH搬入炊飯釜カウント>0 and  搬出アイテムNOA<99 then
			dec(IH搬入炊飯釜カウント)
		end if


		IH炊飯ユニット搬出step=0
		
	end select

	
	'---------------------------------------------------------------------------------------
	tmr(tim_モータローラ排出,tim_モータローラ排出_val)
	select case モータローラ排出step
	case 0
	
	case 1
		if PH36_釜検知 then
			モータローラ排出step=0
		else
			モータローラ排出step=100
		end if


	'PH35_釜検知 MC27_モータローラ	StageDevice23
	'PH36_釜検知 MC28_モータローラ	StageDevice24
		'----------------------------------
	case 100
		'----------------------------------
		if not(PH36_釜検知) and PH35_釜検知 then 
			mMC27_モータローラ=ON
			mMC28_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 101
		if not(PH35_釜検知) and not(PH36_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 102
		if PH36_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 103
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 104
		if tim_モータローラ排出.B then
			mMC27_モータローラ=OFF
			mMC28_モータローラ=OFF

			StageDevice24=StageDevice23
			StageDevice23=0

			inc(モータローラ排出step)
		end if
	
	case 105
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 106
		if tim_モータローラ排出.B then
			inc(モータローラ排出step)
		end if
		


	'PH34_釜検知 MC26_モータローラ	StageDevice22
	'PH35_釜検知 MC27_モータローラ	StageDevice23
		'----------------------------------
	case 107
		if not(PH35_釜検知) and PH34_釜検知 then 
			mMC26_モータローラ=ON
			mMC27_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 108
		if not(PH34_釜検知) and not(PH35_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 109
		if PH35_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 110
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 111
		if tim_モータローラ排出.B then
			mMC26_モータローラ=OFF
			mMC27_モータローラ=OFF

			StageDevice23=StageDevice22
			StageDevice22=0

			inc(モータローラ排出step)
		end if
	
	case 112
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 113
		if tim_モータローラ排出.B then
			if PH36_釜検知 or 1 then
				inc(モータローラ排出step)
			else
				モータローラ排出step=100
			end if
		end if

	'PH33_釜検知 MC25_モータローラ	StageDevice21
	'PH34_釜検知 MC26_モータローラ	StageDevice22
		'----------------------------------
	case 114
		'----------------------------------
		if not(PH34_釜検知) and PH33_釜検知 then 
			mMC25_モータローラ=ON
			mMC26_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 115
		if not(PH33_釜検知) and not(PH34_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 116
		if PH34_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 117
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 118
		if tim_モータローラ排出.B then
			mMC25_モータローラ=OFF
			mMC26_モータローラ=OFF

			StageDevice22=StageDevice21
			StageDevice21=0

			inc(モータローラ排出step)
		end if
	
	case 119
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 120
		if tim_モータローラ排出.B then
			if PH35_釜検知 or 1 then
				inc(モータローラ排出step)
			else
				モータローラ排出step=107
			end if
		end if

	'PH32_釜検知 MC24_モータローラ	StageDevice20
	'PH33_釜検知 MC25_モータローラ	StageDevice21
		'----------------------------------
	case 121
		'----------------------------------
		if not(PH33_釜検知) and PH32_釜検知 then 
			mMC24_モータローラ=ON
			mMC25_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 122
		if not(PH32_釜検知) and not(PH33_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 123
		if PH33_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 124
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 125
		if tim_モータローラ排出.B then
			mMC24_モータローラ=OFF
			mMC25_モータローラ=OFF

			StageDevice21=StageDevice20
			StageDevice20=0

			inc(モータローラ排出step)
		end if
	
	case 126
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 127
		if tim_モータローラ排出.B then
			if PH34_釜検知 or 1 then
				inc(モータローラ排出step)
			else
				モータローラ排出step=114
			end if
		end if

	'PH31_釜検知 MC23_モータローラ	StageDevice19
	'PH32_釜検知 MC24_モータローラ	StageDevice20
		'----------------------------------
	case 128
		'----------------------------------
		if not(PH32_釜検知) and PH31_釜検知 then 
			mMC23_モータローラ=ON
			mMC24_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 129
		if not(PH31_釜検知) and not(PH32_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 130
		if PH32_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 131
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 132
		if tim_モータローラ排出.B then
			mMC23_モータローラ=OFF
			mMC24_モータローラ=OFF

			StageDevice20=StageDevice19
			StageDevice19=0

			inc(モータローラ排出step)
		end if
	
	case 133
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 134
		if tim_モータローラ排出.B then
			if PH33_釜検知 or 1 then
				inc(モータローラ排出step)
			else
				モータローラ排出step=121
			end if
		end if

	'PH30_釜検知 MC22_モータローラ	StageDevice18
	'PH31_釜検知 MC23_モータローラ	StageDevice19
		'----------------------------------
	case 135
		'----------------------------------
		if not(PH31_釜検知) and PH30_釜検知 then 
			mMC22_モータローラ=ON
			mMC23_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 136
		if not(PH30_釜検知) and not(PH31_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 137
		if PH31_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 138
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 139
		if tim_モータローラ排出.B then
			mMC22_モータローラ=OFF
			mMC23_モータローラ=OFF

			StageDevice19=StageDevice18
			StageDevice18=0

			inc(モータローラ排出step)
		end if
	
	case 140
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 141
		if tim_モータローラ排出.B then
			if PH32_釜検知 or 1 then
				inc(モータローラ排出step)
			else
				モータローラ排出step=128
			end if
		end if

	'PH29_釜検知 MC21_モータローラ	StageDevice17
	'PH30_釜検知 MC22_モータローラ	StageDevice18
		'----------------------------------
	case 142
		'----------------------------------
		if not(PH30_釜検知) and PH29_釜検知 then 
			mMC21_モータローラ=ON
			mMC22_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 143
		if not(PH29_釜検知) and not(PH30_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 144
		if PH30_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 145
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 146
		if tim_モータローラ排出.B then
			mMC21_モータローラ=OFF
			mMC22_モータローラ=OFF

			StageDevice18=StageDevice17
			StageDevice17=0

			inc(モータローラ排出step)
		end if
	
	case 147
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 148
		if tim_モータローラ排出.B then
			if PH31_釜検知 or 1 then
				inc(モータローラ排出step)
			else
				モータローラ排出step=135
			end if
		end if

	'PH28_釜検知 MC20_モータローラ	StageDevice16
	'PH29_釜検知 MC21_モータローラ	StageDevice17
		'----------------------------------
	case 149
		'----------------------------------
		if not(PH29_釜検知) and PH28_釜検知 then 
			mMC20_モータローラ=ON
			mMC21_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 150
		if not(PH28_釜検知) and not(PH29_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 151
		if PH29_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 152
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 153
		if tim_モータローラ排出.B then
			mMC20_モータローラ=OFF
			mMC21_モータローラ=OFF

			StageDevice17=StageDevice16
			StageDevice16=0

			inc(モータローラ排出step)
		end if
	
	case 154
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 155
		if tim_モータローラ排出.B then
			if PH30_釜検知 or 1 then
				inc(モータローラ排出step)
			else
				モータローラ排出step=142
			end if
		end if

	'PH27_釜検知 MC19_モータローラ	StageDevice15
	'PH28_釜検知 MC20_モータローラ	StageDevice16
		'----------------------------------
	case 156
		'----------------------------------
		if not(PH28_釜検知) and PH27_釜検知 then 
			mMC19_モータローラ=ON
			mMC20_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 157
		if not(PH27_釜検知) and not(PH28_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 158
		if PH28_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 159
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 160
		if tim_モータローラ排出.B then
			mMC19_モータローラ=OFF
			mMC20_モータローラ=OFF

			StageDevice16=StageDevice15
			StageDevice15=0

			inc(モータローラ排出step)
		end if
	
	case 161
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 162
		if tim_モータローラ排出.B then
			if PH29_釜検知 or 1 then
				inc(モータローラ排出step)
			else
				モータローラ排出step=149
			end if
		end if

	'PH26_釜検知 MC18_モータローラ	StageDevice14
	'PH27_釜検知 MC19_モータローラ	StageDevice15
		'----------------------------------
	case 163
		'----------------------------------
		if not(PH27_釜検知) and PH26_釜検知 then 
			mMC18_モータローラ=ON
			mMC19_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 164
		if not(PH26_釜検知) and not(PH27_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 165
		if PH27_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 166
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 167
		if tim_モータローラ排出.B then
			mMC18_モータローラ=OFF
			mMC19_モータローラ=OFF

			StageDevice15=StageDevice14
			StageDevice14=0

			inc(モータローラ排出step)
		end if
	
	case 168
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 169
		if tim_モータローラ排出.B then
			if PH28_釜検知 or 1 then
				inc(モータローラ排出step)
			else
				モータローラ排出step=156
			end if
		end if

	'PH25_釜検知 MC17_モータローラ	StageDevice13
	'PH26_釜検知 MC18_モータローラ	StageDevice14
		'----------------------------------
	case 170
		'----------------------------------
		if not(PH26_釜検知) and PH25_釜検知 then 
			mMC17_モータローラ=ON
			mMC18_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 171
		if not(PH25_釜検知) and not(PH26_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 172
		if PH26_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 173
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 174
		if tim_モータローラ排出.B then
			mMC17_モータローラ=OFF
			mMC18_モータローラ=OFF

			StageDevice14=StageDevice13
			StageDevice13=0

			inc(モータローラ排出step)
		end if
	
	case 175
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 176
		if tim_モータローラ排出.B then
			if PH27_釜検知 or 1 then
				inc(モータローラ排出step)
			else
				モータローラ排出step=163
			end if
		end if

		'----------------------------------
	case 177
		'----------------------------------
		モータローラ排出step=0
	end select

	'===================================================================================================================
	'【 リフタータスク 】
	'
	if (搬送コンベアF1AutoMode and 自動搬送AutoMode ) or 搬送コンベアF1step<>0 then
	
		if ManualInite=1 then
			ManualInite=0
		end if
		
		if not(搬送コンベアF1AutoMode and 自動搬送AutoMode ) then
			搬送コンベアF1AutoRun=OFF
		end if


		tmr(tim_procstep,tim_procstep_val)

		select case 搬送コンベアF1step
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 搬送コンベアF1AutoRun then
				inc(搬送コンベアF1step)
			else 
				搬送コンベアF1step=0 '終了待機
			end if
		
		case 2
			if PH36_釜検知 then
				搬送コンベアF1動作中=OFF
				搬送コンベアF1排出要求=ON
				搬送コンベアF1step=1
			else
				inc(搬送コンベアF1step)
			end if

		case 3
			if IH炊飯機A禁止 then
				inc(搬送コンベアF1step)				
			else 
				if *pinBオンライン.B and *pinB異常.B then
					inc(搬送コンベアF1step)
				else
					搬送コンベアF1step=1
				end if
			end if
				
		case 4
		' [ 次の搬送コンベア停止確認 ]
			if 搬送コンベアF1排出要求=OFF and  搬送コンベアG動作中=OFF and (IH炊飯機A禁止 or (*pinB搬出コマンド受付可能.B and *pinB搬出要求.B)) then
				搬送コンベアF1動作中=ON
				搬送コンベアF1step=100
			else
				搬送コンベアF1step=1
			end if
			
		'--------------------------------------------------------------------------------------------------------------
		case 100
			搬送コンベアF1釜検知 = PH25_釜検知
			搬送コンベアF1釜検知 = 搬送コンベアF1釜検知 or PH26_釜検知
			搬送コンベアF1釜検知 = 搬送コンベアF1釜検知 or PH27_釜検知
			搬送コンベアF1釜検知 = 搬送コンベアF1釜検知 or PH28_釜検知
			搬送コンベアF1釜検知 = 搬送コンベアF1釜検知 or PH29_釜検知
			搬送コンベアF1釜検知 = 搬送コンベアF1釜検知 or PH30_釜検知
			搬送コンベアF1釜検知 = 搬送コンベアF1釜検知 or PH31_釜検知
			搬送コンベアF1釜検知 = 搬送コンベアF1釜検知 or PH32_釜検知
			搬送コンベアF1釜検知 = 搬送コンベアF1釜検知 or PH33_釜検知
			搬送コンベアF1釜検知 = 搬送コンベアF1釜検知 or PH34_釜検知
			搬送コンベアF1釜検知 = 搬送コンベアF1釜検知 or PH35_釜検知
			inc(搬送コンベアF1step)

		case 101
			if 搬送コンベアF1釜検知 or *pinB搬出口センサ.B then
				inc(搬送コンベアF1step)
			else
				搬送コンベアF1step=1
			end if

		case 102
			モータローラ排出step=1
			inc(搬送コンベアF1step)
			
		case 103
			if モータローラ排出step=0 then
				inc(搬送コンベアF1step)
			end if
	
		'------------------------------------------------------------------------
		case 104
			if PH36_釜検知 then
				搬送コンベアF1排出要求=ON
			end if
			inc(搬送コンベアF1step)
			
		'------------------------------------------------------------------------
		case 105
			if not(PH25_釜検知) then
				IH炊飯ユニット搬出step=1
				inc(搬送コンベアF1step)
			end if
		
		case 106
			if IH炊飯ユニット搬出step=0 then
				inc(搬送コンベアF1step)
			end if

		'------------------------------------------------------------------------
		case 107
			
			搬送コンベアF1動作中=OFF
			搬送コンベアF1step=1

		'--------------------------------------------------------------------------------------------------------------
		case 200
			if not(PH36_釜検知) then
				inc(搬送コンベアF1step)
			else
				搬送コンベアF1step=1
			end if

		case 201
			mMC17_モータローラ=ON
			mMC18_モータローラ=ON
			mMC19_モータローラ=ON
			mMC20_モータローラ=ON
			mMC21_モータローラ=ON
			mMC22_モータローラ=ON
			mMC23_モータローラ=ON
			mMC24_モータローラ=ON
			mMC25_モータローラ=ON
			mMC26_モータローラ=ON
			mMC27_モータローラ=ON
			mMC28_モータローラ=ON
			inc(搬送コンベアF1step)
		
		case 202
			if PH36_釜検知 then
				inc(搬送コンベアF1step)
			end if
		
		case 203
			mMC17_モータローラ=OFF
			mMC18_モータローラ=OFF
			mMC19_モータローラ=OFF
			mMC20_モータローラ=OFF
			mMC21_モータローラ=OFF
			mMC22_モータローラ=OFF
			mMC23_モータローラ=OFF
			mMC24_モータローラ=OFF
			mMC25_モータローラ=OFF
			mMC26_モータローラ=OFF
			mMC27_モータローラ=OFF
			mMC28_モータローラ=OFF
			搬送コンベアF1step=1
			

		
		end select



	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		if ManualInite=0 then
			ManualInite=1
		end if
	
		搬送コンベアF1AutoRun=OFF
		
		搬送コンベアF1step=0 '終了


		res(timerr_MC17_モータローラ)'tmr(MC17_モータローラ,timerr_MC18_モータローラ,60)
		res(timerr_MC18_モータローラ)'tmr(MC18_モータローラ,timerr_MC18_モータローラ,60)
		res(timerr_MC19_モータローラ)'tmr(MC19_モータローラ,timerr_MC19_モータローラ,60)
		res(timerr_MC20_モータローラ)'tmr(MC20_モータローラ,timerr_MC20_モータローラ,60)
		res(timerr_MC21_モータローラ)'tmr(MC21_モータローラ,timerr_MC21_モータローラ,60)
		res(timerr_MC22_モータローラ)'tmr(MC22_モータローラ,timerr_MC22_モータローラ,60)
		res(timerr_MC23_モータローラ)'tmr(MC23_モータローラ,timerr_MC23_モータローラ,60)
		res(timerr_MC24_モータローラ)'tmr(MC24_モータローラ,timerr_MC24_モータローラ,60)
		res(timerr_MC25_モータローラ)'tmr(MC25_モータローラ,timerr_MC25_モータローラ,60)
		res(timerr_MC26_モータローラ)'tmr(MC26_モータローラ,timerr_MC26_モータローラ,60)
		res(timerr_MC27_モータローラ)'tmr(MC27_モータローラ,timerr_MC27_モータローラ,60)
		res(timerr_MC28_モータローラ)'tmr(MC28_モータローラ,timerr_MC28_モータローラ,60)
		
		if ldp(pnlPBMC17_モータローラ) then
			if mMC17_モータローラ then
				mMC17_モータローラ=OFF
			else 
				mMC17_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC18_モータローラ) then
			if mMC18_モータローラ then
				mMC18_モータローラ=OFF
			else 
				mMC18_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC19_モータローラ) then
			if mMC19_モータローラ then
				mMC19_モータローラ=OFF
			else 
				mMC19_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC20_モータローラ) then
			if mMC20_モータローラ then
				mMC20_モータローラ=OFF
			else 
				mMC20_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC21_モータローラ) then
			if mMC21_モータローラ then
				mMC21_モータローラ=OFF
			else 
				mMC21_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC22_モータローラ) then
			if mMC22_モータローラ then
				mMC22_モータローラ=OFF
			else 
				mMC22_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC23_モータローラ) then
			if mMC23_モータローラ then
				mMC23_モータローラ=OFF
			else 
				mMC23_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC24_モータローラ) then
			if mMC24_モータローラ then
				mMC24_モータローラ=OFF
			else 
				mMC24_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC25_モータローラ) then
			if mMC25_モータローラ then
				mMC25_モータローラ=OFF
			else 
				mMC25_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC26_モータローラ) then
			if mMC26_モータローラ then
				mMC26_モータローラ=OFF
			else 
				mMC26_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC27_モータローラ) then
			if mMC27_モータローラ then
				mMC27_モータローラ=OFF
			else 
				mMC27_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC28_モータローラ) then
			if mMC28_モータローラ then
				mMC28_モータローラ=OFF
			else 
				mMC28_モータローラ=ON
			end if
		end if
		
			
	end if '搬送コンベアF1AutoMode and not(搬送コンベアF1OrgErrStep)

	'===================================================================================================================
	'【 搬送コンベアF1OrgErr処理 】
	else
	
		if ResetFlg then
			搬送コンベアF1OrgErr=OFF
		end if


	end if

	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else

		搬送コンベアF1Err=ON

		pauseMC17_モータローラ=ON
		pauseMC18_モータローラ=ON
		pauseMC19_モータローラ=ON
		pauseMC20_モータローラ=ON
		pauseMC21_モータローラ=ON
		pauseMC22_モータローラ=ON
		pauseMC23_モータローラ=ON
		pauseMC24_モータローラ=ON
		pauseMC25_モータローラ=ON
		pauseMC26_モータローラ=ON
		pauseMC27_モータローラ=ON
		pauseMC28_モータローラ=ON

		select case 搬送コンベアF1ErrStep
		case 0
		case 1
			if ResetFlg then
				almMC17_モータローラ=OFF
				almMC18_モータローラ=OFF
				almMC19_モータローラ=OFF
				almMC20_モータローラ=OFF
				almMC21_モータローラ=OFF
				almMC22_モータローラ=OFF
				almMC23_モータローラ=OFF
				almMC24_モータローラ=OFF
				almMC25_モータローラ=OFF
				almMC26_モータローラ=OFF
				almMC27_モータローラ=OFF
				almMC28_モータローラ=OFF
				inc(搬送コンベアF1ErrStep)
			end if
		case 2
			pauseMC17_モータローラ=OFF
			pauseMC18_モータローラ=OFF
			pauseMC19_モータローラ=OFF
			pauseMC20_モータローラ=OFF
			pauseMC21_モータローラ=OFF
			pauseMC22_モータローラ=OFF
			pauseMC23_モータローラ=OFF
			pauseMC24_モータローラ=OFF
			pauseMC25_モータローラ=OFF
			pauseMC26_モータローラ=OFF
			pauseMC27_モータローラ=OFF
			pauseMC28_モータローラ=OFF


			搬送コンベアF1Err=OFF
			搬送コンベアF1ErrStep=0
		end select

	end if 'if 搬送コンベアF1ErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	
	select case 搬送コンベアF1EmgStep
	case 0
		
	case 1
		搬送コンベアF1AutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (搬送コンベアF1AutoMode and 自動搬送AutoMode ) or 搬送コンベアF1step<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseMC17_モータローラ=ON
			pauseMC18_モータローラ=ON
			pauseMC19_モータローラ=ON
			pauseMC20_モータローラ=ON
			pauseMC21_モータローラ=ON
			pauseMC22_モータローラ=ON
			pauseMC23_モータローラ=ON
			pauseMC24_モータローラ=ON
			pauseMC25_モータローラ=ON
			pauseMC26_モータローラ=ON
			pauseMC27_モータローラ=ON
			pauseMC28_モータローラ=ON
			
			if timstack=OFF then
				timdly_PH25_釜検知_stack=timdly_PH25_釜検知.U
				timdly_PH26_釜検知_stack=timdly_PH26_釜検知.U
				timdly_PH27_釜検知_stack=timdly_PH27_釜検知.U
				timdly_PH28_釜検知_stack=timdly_PH28_釜検知.U
				timdly_PH29_釜検知_stack=timdly_PH29_釜検知.U
				timdly_PH30_釜検知_stack=timdly_PH30_釜検知.U
				timdly_PH31_釜検知_stack=timdly_PH31_釜検知.U
				timdly_PH32_釜検知_stack=timdly_PH32_釜検知.U
				timdly_PH33_釜検知_stack=timdly_PH33_釜検知.U
				timdly_PH34_釜検知_stack=timdly_PH34_釜検知.U
				timdly_PH35_釜検知_stack=timdly_PH35_釜検知.U
				timdly_PH36_釜検知_stack=timdly_PH36_釜検知.U
				tim_procstep_stack=tim_procstep.U
				tim_IH炊飯ユニット搬入_stack=tim_IH炊飯ユニット搬入.U
				tim_MC17_モータローラ_stack=tim_MC17_モータローラ.U
				tim_MC18_モータローラ_stack=tim_MC18_モータローラ.U
				tim_MC19_モータローラ_stack=tim_MC19_モータローラ.U
				tim_搬入指令_stack=tim_搬入指令.U
				tim_搬出指令_stack=tim_搬出指令.U
				tim_MC20_モータローラ_stack=tim_MC20_モータローラ.U
				tim_MC21_モータローラ_stack=tim_MC21_モータローラ.U
				tim_MC22_モータローラ_stack=tim_MC22_モータローラ.U
				tim_MC23_モータローラ_stack=tim_MC23_モータローラ.U
				tim_モータローラ排出_stack=tim_モータローラ排出.U
				tim_MC24_モータローラ_stack=tim_MC24_モータローラ.U
				tim_MC25_モータローラ_stack=tim_MC25_モータローラ.U
				tim_MC26_モータローラ_stack=tim_MC26_モータローラ.U
				tim_MC27_モータローラ_stack=tim_MC27_モータローラ.U
				tim_MC28_モータローラ_stack=tim_MC28_モータローラ.U
				tim_IH炊飯ユニット搬出_stack=tim_IH炊飯ユニット搬出.U
				timdly_PH49_釜検知_stack=timdly_PH49_釜検知.U

				timstack=ON
			end if
			
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC17_モータローラ=OFF
			mMC18_モータローラ=OFF
			mMC19_モータローラ=OFF
			mMC20_モータローラ=OFF
			mMC21_モータローラ=OFF
			mMC22_モータローラ=OFF
			mMC23_モータローラ=OFF
			mMC24_モータローラ=OFF
			mMC25_モータローラ=OFF
			mMC26_モータローラ=OFF
			mMC27_モータローラ=OFF
			mMC28_モータローラ=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(搬送コンベアF1EmgStep)
	case 2
		if ResetFlg then
			inc(搬送コンベアF1EmgStep)
		end if
	case 3
		if (搬送コンベアF1AutoMode and 自動搬送AutoMode ) or 搬送コンベアF1step<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseMC17_モータローラ=OFF
				pauseMC18_モータローラ=OFF
				pauseMC19_モータローラ=OFF
				pauseMC20_モータローラ=OFF
				pauseMC21_モータローラ=OFF
				pauseMC22_モータローラ=OFF
				pauseMC23_モータローラ=OFF
				pauseMC24_モータローラ=OFF
				pauseMC25_モータローラ=OFF
				pauseMC26_モータローラ=OFF
				pauseMC27_モータローラ=OFF
				pauseMC28_モータローラ=OFF

						
				timdly_PH25_釜検知.U=timdly_PH25_釜検知_stack
				timdly_PH26_釜検知.U=timdly_PH26_釜検知_stack
				timdly_PH27_釜検知.U=timdly_PH27_釜検知_stack
				timdly_PH28_釜検知.U=timdly_PH28_釜検知_stack
				timdly_PH29_釜検知.U=timdly_PH29_釜検知_stack
				timdly_PH30_釜検知.U=timdly_PH30_釜検知_stack
				timdly_PH31_釜検知.U=timdly_PH31_釜検知_stack
				timdly_PH32_釜検知.U=timdly_PH32_釜検知_stack
				timdly_PH33_釜検知.U=timdly_PH33_釜検知_stack
				timdly_PH34_釜検知.U=timdly_PH34_釜検知_stack
				timdly_PH35_釜検知.U=timdly_PH35_釜検知_stack
				timdly_PH36_釜検知.U=timdly_PH36_釜検知_stack
				tim_procstep.U=tim_procstep_stack
				tim_IH炊飯ユニット搬入.U=tim_IH炊飯ユニット搬入_stack
				tim_MC17_モータローラ.U=tim_MC17_モータローラ_stack
				tim_MC18_モータローラ.U=tim_MC18_モータローラ_stack
				tim_MC19_モータローラ.U=tim_MC19_モータローラ_stack
				tim_搬入指令.U=tim_搬入指令_stack
				tim_搬出指令.U=tim_搬出指令_stack
				tim_MC20_モータローラ.U=tim_MC20_モータローラ_stack
				tim_MC21_モータローラ.U=tim_MC21_モータローラ_stack
				tim_MC22_モータローラ.U=tim_MC22_モータローラ_stack
				tim_MC23_モータローラ.U=tim_MC23_モータローラ_stack
				tim_モータローラ排出.U=tim_モータローラ排出_stack
				tim_MC24_モータローラ.U=tim_MC24_モータローラ_stack
				tim_MC25_モータローラ.U=tim_MC25_モータローラ_stack
				tim_MC26_モータローラ.U=tim_MC26_モータローラ_stack
				tim_MC27_モータローラ.U=tim_MC27_モータローラ_stack
				tim_MC28_モータローラ.U=tim_MC28_モータローラ_stack
				tim_IH炊飯ユニット搬出.U=tim_IH炊飯ユニット搬出_stack
				timdly_PH49_釜検知.U=timdly_PH49_釜検知_stack

				
				'---------------------------------
				inc(搬送コンベアF1EmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(搬送コンベアF1EmgStep)		
		end if				
	case 4
		timstack=OFF
		搬送コンベアF1EmgStep=0
		搬送コンベアF1Emg=OFF
	end select

		
end if 'if 搬送コンベアF1EmgStep=0 then
