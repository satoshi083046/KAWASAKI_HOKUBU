'搬送コンベアF2
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	搬送コンベアF2
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

	搬送コンベアF2AutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    搬送コンベアF2AutoRun=OFF
    搬送コンベアF2許可=ON
    搬送コンベアF2OrgErr=OFF
    搬送コンベアF2Err=OFF
    搬送コンベアF2Emg=OFF
    搬送コンベアF2step=0
    搬送コンベアF2ErrStep=0
    搬送コンベアF2OrgErrStep=0
    搬送コンベアF2EmgStep=0

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
搬送コンベアF2Org=1

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	搬送コンベアF2Emg=ON
	搬送コンベアF2EmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】

if 自動搬送AutoMode then
	tmr(MC29_モータローラ,timerr_MC29_モータローラ,60)
	tmr(MC30_モータローラ,timerr_MC30_モータローラ,60)
	tmr(MC31_モータローラ,timerr_MC31_モータローラ,60)
	tmr(MC32_モータローラ,timerr_MC32_モータローラ,60)
	tmr(MC33_モータローラ,timerr_MC33_モータローラ,60)
	tmr(MC47_モータローラ,timerr_MC47_モータローラ,60)
	tmr(MC48_モータローラ,timerr_MC48_モータローラ,60)
	tmr(MC49_モータローラ,timerr_MC49_モータローラ,60)
	tmr(MC50_モータローラ,timerr_MC50_モータローラ,60)
	tmr(MC51_モータローラ,timerr_MC51_モータローラ,60)
	tmr(MC52_モータローラ,timerr_MC52_モータローラ,60)
	tmr(MC53_モータローラ,timerr_MC53_モータローラ,60)
else
	res(timerr_MC29_モータローラ)
	res(timerr_MC30_モータローラ)
	res(timerr_MC31_モータローラ)
	res(timerr_MC32_モータローラ)
	res(timerr_MC33_モータローラ)
	res(timerr_MC47_モータローラ)
	res(timerr_MC48_モータローラ)
	res(timerr_MC49_モータローラ)
	res(timerr_MC50_モータローラ)
	res(timerr_MC51_モータローラ)
	res(timerr_MC52_モータローラ)
	res(timerr_MC53_モータローラ)
end if

if ldp(timerr_MC29_モータローラ.B) then
	almMC29_モータローラ=ON
	搬送コンベアF2ErrStep=1

else if ldp(timerr_MC30_モータローラ.B) then
	almMC30_モータローラ=ON
	搬送コンベアF2ErrStep=1

else if ldp(timerr_MC31_モータローラ.B) then
	almMC31_モータローラ=ON
	搬送コンベアF2ErrStep=1

else if ldp(timerr_MC32_モータローラ.B) then
	almMC32_モータローラ=ON
	搬送コンベアF2ErrStep=1

else if ldp(timerr_MC33_モータローラ.B) then
	almMC33_モータローラ=ON
	搬送コンベアF2ErrStep=1

else if ldp(timerr_MC47_モータローラ.B) then
	almMC47_モータローラ=ON
	搬送コンベアF2ErrStep=1

else if ldp(timerr_MC48_モータローラ.B) then
	almMC48_モータローラ=ON
	搬送コンベアF2ErrStep=1

else if ldp(timerr_MC49_モータローラ.B) then
	almMC49_モータローラ=ON
	搬送コンベアF2ErrStep=1

else if ldp(timerr_MC50_モータローラ.B) then
	almMC50_モータローラ=ON
	搬送コンベアF2ErrStep=1

else if ldp(timerr_MC51_モータローラ.B) then
	almMC51_モータローラ=ON
	搬送コンベアF2ErrStep=1

else if ldp(timerr_MC52_モータローラ.B) then
	almMC52_モータローラ=ON
	搬送コンベアF2ErrStep=1

else if ldp(timerr_MC53_モータローラ.B) then
	almMC53_モータローラ=ON
	搬送コンベアF2ErrStep=1

end if



'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 搬送コンベアF2AutoMode	自動モード セレクトスイッチ
'System :: 搬送コンベアF2AutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 搬送コンベアF2Emg	その場停止


if 搬送コンベアF2EmgStep=0 then  
	
	if 搬送コンベアF2ErrStep=0  then

	if not(搬送コンベアF2OrgErr) then

	
	tmr(PH37_釜検知,timdly_PH37_釜検知,2)
	tmr(PH38_釜検知,timdly_PH38_釜検知,2)
	tmr(PH39_釜検知,timdly_PH39_釜検知,2)
	tmr(PH40_釜検知,timdly_PH40_釜検知,2)
	tmr(PH41_釜検知,timdly_PH41_釜検知,2)
	tmr(PH42_釜検知,timdly_PH42_釜検知,2)
	tmr(PH43_釜検知,timdly_PH43_釜検知,2)
	tmr(PH44_釜検知,timdly_PH44_釜検知,2)
	tmr(PH45_釜検知,timdly_PH45_釜検知,2)
	tmr(PH46_釜検知,timdly_PH46_釜検知,2)
	tmr(PH47_釜検知,timdly_PH47_釜検知,2)
	tmr(PH48_釜検知,timdly_PH48_釜検知,2)

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
	case 6
		ejectMC29_モータローラ=ON
		inc(IH炊飯ユニット搬出step)
	
	case 7
		'if not(*pinB搬出要求.B) then
			inc(IH炊飯ユニット搬出step)
		'end if
	
	case 8
		if 	PH37_釜検知 then
			inc(IH炊飯ユニット搬出step)
		 end if

	case 9
		tim_IH炊飯ユニット搬出_val=8
		res(tim_IH炊飯ユニット搬出)
		inc(IH炊飯ユニット搬出step)
	
	case 10
		if tim_IH炊飯ユニット搬出.B then
			inc(IH炊飯ユニット搬出step)
		end if

	case 11
		ejectMC29_モータローラ=OFF
		inc(IH炊飯ユニット搬出step)

	case 12
		搬出アイテムNOB=*pinU搬出アイテムNO.U '空釜 99
		StageDevice25=搬出アイテムNOB

		if IH搬入炊飯釜カウント>0 and 搬出アイテムNOB<99 then
			dec(IH搬入炊飯釜カウント)
		end if

		IH炊飯ユニット搬出step=0
		
	end select
	'---------------------------------------------------------------------------------------
	tmr(tim_モータローラ排出,tim_モータローラ排出_val)
	select case モータローラ排出step
	case 0
	
	case 1
		if PH48_釜検知 then
			モータローラ排出step=0
		else
			モータローラ排出step=100
		end if
	

	'PH47_釜検知 MC52_モータローラ	StageDevice35
	'PH48_釜検知 MC53_モータローラ	StageDevice36
		'----------------------------------
	case 100
		'----------------------------------
		if not(PH48_釜検知) and PH47_釜検知 then 
			mMC52_モータローラ=ON
			mMC53_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 101
		if not(PH47_釜検知) and not(PH48_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 102
		if PH48_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 103
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 104
		if tim_モータローラ排出.B then
			mMC52_モータローラ=OFF
			mMC53_モータローラ=OFF

			StageDevice36=StageDevice35
			StageDevice35=0

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
		

	'PH46_釜検知 MC51_モータローラ	StageDevice34
	'PH47_釜検知 MC52_モータローラ	StageDevice35
		'----------------------------------
	case 107
		if not(PH47_釜検知) and PH46_釜検知 then 
			mMC51_モータローラ=ON
			mMC52_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 108
		if not(PH46_釜検知) and not(PH47_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 109
		if PH47_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 110
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 111
		if tim_モータローラ排出.B then
			mMC51_モータローラ=OFF
			mMC52_モータローラ=OFF

			StageDevice35=StageDevice34
			StageDevice34=0

			inc(モータローラ排出step)
		end if
	
	case 112
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 113
		if tim_モータローラ排出.B then
			if PH48_釜検知 or 1 then
				inc(モータローラ排出step)
			else
				モータローラ排出step=100
			end if
		end if

	'PH45_釜検知 MC50_モータローラ	StageDevice33
	'PH46_釜検知 MC51_モータローラ	StageDevice34
		'----------------------------------
	case 114
		'----------------------------------
		if not(PH46_釜検知) and PH45_釜検知 then 
			mMC50_モータローラ=ON
			mMC51_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 115
		if not(PH45_釜検知) and not(PH46_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 116
		if PH46_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 117
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 118
		if tim_モータローラ排出.B then
			mMC50_モータローラ=OFF
			mMC51_モータローラ=OFF

			StageDevice34=StageDevice33
			StageDevice33=0

			inc(モータローラ排出step)
		end if
	
	case 119
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 120
		if tim_モータローラ排出.B then
			if PH47_釜検知 or 1 then
				inc(モータローラ排出step)
			else
				モータローラ排出step=107
			end if
		end if

	'PH44_釜検知 MC49_モータローラ	StageDevice32
	'PH45_釜検知 MC50_モータローラ	StageDevice33
		'----------------------------------
	case 121
		'----------------------------------
		if not(PH45_釜検知) and PH44_釜検知 then 
			mMC49_モータローラ=ON
			mMC50_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 122
		if not(PH44_釜検知) and not(PH45_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 123
		if PH45_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 124
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 125
		if tim_モータローラ排出.B then
			mMC49_モータローラ=OFF
			mMC50_モータローラ=OFF

			StageDevice33=StageDevice32
			StageDevice32=0

			inc(モータローラ排出step)
		end if
	
	case 126
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 127
		if tim_モータローラ排出.B then
			if PH46_釜検知 or 1 then
				inc(モータローラ排出step)
			else
				モータローラ排出step=114
			end if
		end if

	'PH43_釜検知 MC48_モータローラ	StageDevice31
	'PH44_釜検知 MC49_モータローラ	StageDevice32
		'----------------------------------
	case 128
		'----------------------------------
		if not(PH44_釜検知) and PH43_釜検知 then 
			mMC48_モータローラ=ON
			mMC49_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 129
		if not(PH43_釜検知) and not(PH44_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 130
		if PH44_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 131
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 132
		if tim_モータローラ排出.B then
			mMC48_モータローラ=OFF
			mMC49_モータローラ=OFF

			StageDevice32=StageDevice31
			StageDevice31=0

			inc(モータローラ排出step)
		end if
	
	case 133
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 134
		if tim_モータローラ排出.B then
			if PH45_釜検知 or 1 then
				inc(モータローラ排出step)
			else
				モータローラ排出step=121
			end if
		end if

	'PH42_釜検知 MC47_モータローラ	StageDevice30
	'PH43_釜検知 MC48_モータローラ	StageDevice31
		'----------------------------------
	case 135
		'----------------------------------
		if not(PH43_釜検知) and PH42_釜検知 then 
			mMC47_モータローラ=ON
			mMC48_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 136
		if not(PH42_釜検知) and not(PH43_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 137
		if PH43_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 138
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 139
		if tim_モータローラ排出.B then
			mMC47_モータローラ=OFF
			mMC48_モータローラ=OFF

			StageDevice31=StageDevice30
			StageDevice30=0

			inc(モータローラ排出step)
		end if
	
	case 140
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 141
		if tim_モータローラ排出.B then
			if PH44_釜検知 or 1 then
				inc(モータローラ排出step)
			else
				モータローラ排出step=128
			end if
		end if

	'PH41_釜検知 MC33_モータローラ	StageDevice29
	'PH42_釜検知 MC47_モータローラ	StageDevice30
		'----------------------------------
	case 142
		'----------------------------------
		if not(PH42_釜検知) and PH41_釜検知 then 
			mMC33_モータローラ=ON
			mMC47_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 143
		if not(PH41_釜検知) and not(PH42_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 144
		if PH42_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 145
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 146
		if tim_モータローラ排出.B then
			mMC33_モータローラ=OFF
			mMC47_モータローラ=OFF

			StageDevice30=StageDevice29
			StageDevice29=0

			inc(モータローラ排出step)
		end if
	
	case 147
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 148
		if tim_モータローラ排出.B then
			if PH43_釜検知 or 1 then
				inc(モータローラ排出step)
			else
				モータローラ排出step=135
			end if
		end if

	'PH40_釜検知 MC32_モータローラ	StageDevice28
	'PH41_釜検知 MC33_モータローラ	StageDevice29
		'----------------------------------
	case 149
		'----------------------------------
		if not(PH41_釜検知) and PH40_釜検知 then 
			mMC32_モータローラ=ON
			mMC33_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 150
		if not(PH40_釜検知) and not(PH41_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 151
		if PH41_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 152
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 153
		if tim_モータローラ排出.B then
			mMC32_モータローラ=OFF
			mMC33_モータローラ=OFF

			StageDevice29=StageDevice28
			StageDevice28=0

			inc(モータローラ排出step)
		end if
	
	case 154
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 155
		if tim_モータローラ排出.B then
			if PH42_釜検知 or 1 then
				inc(モータローラ排出step)
			else
				モータローラ排出step=142
			end if
		end if

	'PH39_釜検知 MC31_モータローラ	StageDevice27
	'PH40_釜検知 MC32_モータローラ	StageDevice28
		'----------------------------------
	case 156
		'----------------------------------
		if not(PH40_釜検知) and PH39_釜検知 then 
			mMC31_モータローラ=ON
			mMC32_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 157
		if not(PH39_釜検知) and not(PH40_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 158
		if PH40_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 159
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 160
		if tim_モータローラ排出.B then
			mMC31_モータローラ=OFF
			mMC32_モータローラ=OFF

			StageDevice28=StageDevice27
			StageDevice27=0

			inc(モータローラ排出step)
		end if
	
	case 161
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 162
		if tim_モータローラ排出.B then
			if PH41_釜検知 or 1 then
				inc(モータローラ排出step)
			else
				モータローラ排出step=149
			end if
		end if

	'PH38_釜検知 MC30_モータローラ	StageDevice26
	'PH39_釜検知 MC31_モータローラ	StageDevice27
		'----------------------------------
	case 163
		'----------------------------------
		if not(PH39_釜検知) and PH38_釜検知 then 
			mMC30_モータローラ=ON
			mMC31_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 164
		if not(PH38_釜検知) and not(PH39_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 165
		if PH39_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 166
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 167
		if tim_モータローラ排出.B then
			mMC30_モータローラ=OFF
			mMC31_モータローラ=OFF

			StageDevice27=StageDevice26
			StageDevice26=0

			inc(モータローラ排出step)
		end if
	
	case 168
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 169
		if tim_モータローラ排出.B then
			if PH40_釜検知 or 1 then
				inc(モータローラ排出step)
			else
				モータローラ排出step=156
			end if
		end if

	'PH37_釜検知 MC29_モータローラ	StageDevice25
	'PH38_釜検知 MC30_モータローラ	StageDevice26
		'----------------------------------
	case 170
		'----------------------------------
		if not(PH38_釜検知) and PH37_釜検知 then 
			mMC29_モータローラ=ON
			mMC30_モータローラ=ON
			inc(モータローラ排出step)
		else
			モータローラ排出step=モータローラ排出step+7
		end if

	case 171
		if not(PH37_釜検知) and not(PH38_釜検知) then
			inc(モータローラ排出step)		
		end if

	case 172
		if PH38_釜検知 then 
			inc(モータローラ排出step)
		end if
	
	case 173
		tim_モータローラ排出_val=8
		res(tim_モータローラ排出)
		inc(モータローラ排出step)

	case 174
		if tim_モータローラ排出.B then
			mMC29_モータローラ=OFF
			mMC30_モータローラ=OFF

			StageDevice26=StageDevice25
			StageDevice25=0

			inc(モータローラ排出step)
		end if
	
	case 175
		tim_モータローラ排出_val=0
		res(tim_モータローラ排出)
		inc(モータローラ排出step)
	
	case 176
		if tim_モータローラ排出.B then
			if PH39_釜検知 or 1 then
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
	if (搬送コンベアF2AutoMode and 自動搬送AutoMode ) or 搬送コンベアF2step<>0 then
	
		if ManualInite=1 then
			ManualInite=0
		end if
		
		if not(搬送コンベアF2AutoMode and 自動搬送AutoMode ) then
			搬送コンベアF2AutoRun=OFF
		end if
		tmr(tim_procstep,tim_procstep_val)

		select case 搬送コンベアF2step
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 搬送コンベアF2AutoRun then
				inc(搬送コンベアF2step)
			else 
				搬送コンベアF2step=0 '終了待機
			end if
		
		case 2
			if PH48_釜検知 then
				搬送コンベアF2動作中=OFF
				搬送コンベアF2排出要求=ON
				搬送コンベアF2step=1
			else
				inc(搬送コンベアF2step)
			end if


		case 3
			if IH炊飯機B禁止 then
				inc(搬送コンベアF2step)
			else
				if *pinBオンライン.B and *pinB異常.B then
					inc(搬送コンベアF2step)
				else
					搬送コンベアF2step=1
				end if
			end if
		case 4
		' [ 次の搬送コンベア停止確認 ]
			if 搬送コンベアF2排出要求=OFF and  搬送コンベアG動作中=OFF and (IH炊飯機B禁止 or (*pinB搬出コマンド受付可能.B and *pinB搬出要求.B)) then
				搬送コンベアF2動作中=ON
				搬送コンベアF2step=100
			else
				搬送コンベアF2step=1
			end if
			
		'--------------------------------------------------------------------------------------------------------------
		case 100
			搬送コンベアF2釜検知 = PH37_釜検知
			搬送コンベアF2釜検知 = 搬送コンベアF2釜検知 or PH38_釜検知
			搬送コンベアF2釜検知 = 搬送コンベアF2釜検知 or PH39_釜検知
			搬送コンベアF2釜検知 = 搬送コンベアF2釜検知 or PH40_釜検知
			搬送コンベアF2釜検知 = 搬送コンベアF2釜検知 or PH41_釜検知
			搬送コンベアF2釜検知 = 搬送コンベアF2釜検知 or PH42_釜検知
			搬送コンベアF2釜検知 = 搬送コンベアF2釜検知 or PH43_釜検知
			搬送コンベアF2釜検知 = 搬送コンベアF2釜検知 or PH44_釜検知
			搬送コンベアF2釜検知 = 搬送コンベアF2釜検知 or PH45_釜検知
			搬送コンベアF2釜検知 = 搬送コンベアF2釜検知 or PH46_釜検知
			搬送コンベアF2釜検知 = 搬送コンベアF2釜検知 or PH47_釜検知
			inc(搬送コンベアF2step)

		case 101		
			if 搬送コンベアF2釜検知 or *pinB搬出口センサ.B then
				inc(搬送コンベアF2step)
			else
				搬送コンベアF2step=1
			end if

		case 102
			モータローラ排出step=1
			inc(搬送コンベアF2step)
				
		case 103
			if モータローラ排出step=0 then
				inc(搬送コンベアF2step)
			end if

		'------------------------------------------------------------------------
		case 104
			if PH48_釜検知 then
				搬送コンベアF2排出要求=ON
			end if
			inc(搬送コンベアF2step)

		'------------------------------------------------------------------------
		case 105
			if not(PH37_釜検知) then
				IH炊飯ユニット搬出step=1
				inc(搬送コンベアF2step)
			end if
		
		case 106
			if IH炊飯ユニット搬出step=0 then
				inc(搬送コンベアF2step)
			end if
		'------------------------------------------------------------------------
		case 107
			搬送コンベアF2動作中=OFF
			搬送コンベアF2step=1
		
		'--------------------------------------------------------------------------------------------------------------
		case 200
			if not(PH48_釜検知) then
				inc(搬送コンベアF2step)
			else
				搬送コンベアF2step=1
			end if

		case 201
			mMC29_モータローラ=ON
			mMC30_モータローラ=ON
			mMC31_モータローラ=ON
			mMC32_モータローラ=ON
			mMC33_モータローラ=ON
			mMC47_モータローラ=ON
			mMC48_モータローラ=ON
			mMC49_モータローラ=ON
			mMC50_モータローラ=ON
			mMC51_モータローラ=ON
			mMC52_モータローラ=ON
			mMC53_モータローラ=ON
			inc(搬送コンベアF2step)
		
		case 202
			if PH48_釜検知 then
				inc(搬送コンベアF2step)
			end if
		
		case 203
			mMC29_モータローラ=OFF
			mMC30_モータローラ=OFF
			mMC31_モータローラ=OFF
			mMC32_モータローラ=OFF
			mMC33_モータローラ=OFF
			mMC47_モータローラ=OFF
			mMC48_モータローラ=OFF
			mMC49_モータローラ=OFF
			mMC50_モータローラ=OFF
			mMC51_モータローラ=OFF
			mMC52_モータローラ=OFF
			mMC53_モータローラ=OFF
			搬送コンベアF2step=1
			

		end select

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		if ManualInite=0 then
			ManualInite=1
		end if
	
		搬送コンベアF2AutoRun=OFF
		
		搬送コンベアF2step=0 '終了

		
		if ldp(pnlPBMC29_モータローラ) then
			if mMC29_モータローラ then
				mMC29_モータローラ=OFF
			else 
				mMC29_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC30_モータローラ) then
			if mMC30_モータローラ then
				mMC30_モータローラ=OFF
			else 
				mMC30_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC31_モータローラ) then
			if mMC31_モータローラ then
				mMC31_モータローラ=OFF
			else 
				mMC31_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC32_モータローラ) then
			if mMC32_モータローラ then
				mMC32_モータローラ=OFF
			else 
				mMC32_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC33_モータローラ) then
			if mMC33_モータローラ then
				mMC33_モータローラ=OFF
			else 
				mMC33_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC47_モータローラ) then
			if mMC47_モータローラ then
				mMC47_モータローラ=OFF
			else 
				mMC47_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC48_モータローラ) then
			if mMC48_モータローラ then
				mMC48_モータローラ=OFF
			else 
				mMC48_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC49_モータローラ) then
			if mMC49_モータローラ then
				mMC49_モータローラ=OFF
			else 
				mMC49_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC50_モータローラ) then
			if mMC50_モータローラ then
				mMC50_モータローラ=OFF
			else 
				mMC50_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC51_モータローラ) then
			if mMC51_モータローラ then
				mMC51_モータローラ=OFF
			else 
				mMC51_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC52_モータローラ) then
			if mMC52_モータローラ then
				mMC52_モータローラ=OFF
			else 
				mMC52_モータローラ=ON
			end if
		end if

		if ldp(pnlPBMC53_モータローラ) then
			if mMC53_モータローラ then
				mMC53_モータローラ=OFF
			else 
				mMC53_モータローラ=ON
			end if
		end if

	end if '搬送コンベアF2AutoMode and not(搬送コンベアF2OrgErrStep)

	'===================================================================================================================
	'【 搬送コンベアF2OrgErr処理 】
	else
	
		if ResetFlg then
			搬送コンベアF2OrgErr=OFF
		end if


	end if

	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else

		搬送コンベアF2Err=ON

		res(timerr_MC29_モータローラ)'tmr(MC29_モータローラ,timerr_MC29_モータローラ,60)
		res(timerr_MC30_モータローラ)'tmr(MC30_モータローラ,timerr_MC30_モータローラ,60)
		res(timerr_MC31_モータローラ)'tmr(MC31_モータローラ,timerr_MC31_モータローラ,60)
		res(timerr_MC32_モータローラ)'tmr(MC32_モータローラ,timerr_MC32_モータローラ,60)
		res(timerr_MC33_モータローラ)'tmr(MC33_モータローラ,timerr_MC33_モータローラ,60)
		res(timerr_MC47_モータローラ)'tmr(MC47_モータローラ,timerr_MC47_モータローラ,60)
		res(timerr_MC48_モータローラ)'tmr(MC48_モータローラ,timerr_MC48_モータローラ,60)
		res(timerr_MC49_モータローラ)'tmr(MC49_モータローラ,timerr_MC49_モータローラ,60)
		res(timerr_MC50_モータローラ)'tmr(MC50_モータローラ,timerr_MC50_モータローラ,60)
		res(timerr_MC51_モータローラ)'tmr(MC51_モータローラ,timerr_MC51_モータローラ,60)
		res(timerr_MC52_モータローラ)'tmr(MC52_モータローラ,timerr_MC52_モータローラ,60)
		res(timerr_MC53_モータローラ)'tmr(MC53_モータローラ,timerr_MC53_モータローラ,60)

		pauseMC29_モータローラ=ON
		pauseMC30_モータローラ=ON
		pauseMC31_モータローラ=ON
		pauseMC32_モータローラ=ON
		pauseMC33_モータローラ=ON
		pauseMC47_モータローラ=ON
		pauseMC48_モータローラ=ON
		pauseMC49_モータローラ=ON
		pauseMC50_モータローラ=ON
		pauseMC51_モータローラ=ON
		pauseMC52_モータローラ=ON
		pauseMC53_モータローラ=ON

		select case 搬送コンベアF2ErrStep
		case 0
		case 1
			if ResetFlg then
				almMC29_モータローラ=OFF
				almMC30_モータローラ=OFF
				almMC31_モータローラ=OFF
				almMC32_モータローラ=OFF
				almMC33_モータローラ=OFF
				almMC47_モータローラ=OFF
				almMC48_モータローラ=OFF
				almMC49_モータローラ=OFF
				almMC50_モータローラ=OFF
				almMC51_モータローラ=OFF
				almMC52_モータローラ=OFF
				almMC53_モータローラ=OFF
				inc(搬送コンベアF2ErrStep)
			end if
		case 2
			pauseMC29_モータローラ=OFF
			pauseMC30_モータローラ=OFF
			pauseMC31_モータローラ=OFF
			pauseMC32_モータローラ=OFF
			pauseMC33_モータローラ=OFF
			pauseMC47_モータローラ=OFF
			pauseMC48_モータローラ=OFF
			pauseMC49_モータローラ=OFF
			pauseMC50_モータローラ=OFF
			pauseMC51_モータローラ=OFF
			pauseMC52_モータローラ=OFF
			pauseMC53_モータローラ=OFF
			

			搬送コンベアF2Err=OFF
			搬送コンベアF2ErrStep=0
		end select

	end if 'if 搬送コンベアF2ErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else

	select case 搬送コンベアF2EmgStep
	case 0
		
	case 1
		搬送コンベアF2AutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (搬送コンベアF2AutoMode and 自動搬送AutoMode ) or 搬送コンベアF2step<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseMC29_モータローラ=ON
			pauseMC30_モータローラ=ON
			pauseMC31_モータローラ=ON
			pauseMC32_モータローラ=ON
			pauseMC33_モータローラ=ON
			pauseMC47_モータローラ=ON
			pauseMC48_モータローラ=ON
			pauseMC49_モータローラ=ON
			pauseMC50_モータローラ=ON
			pauseMC51_モータローラ=ON
			pauseMC52_モータローラ=ON
			pauseMC53_モータローラ=ON		

			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				tim_搬出指令_stack=tim_搬出指令.U
				tim_搬入指令_stack=tim_搬入指令.U
				tim_IH炊飯ユニット搬出_stack=tim_IH炊飯ユニット搬出.U
				tim_IH炊飯ユニット搬入_stack=tim_IH炊飯ユニット搬入.U
				tim_モータローラ排出_stack=tim_モータローラ排出.U
				timdly_PH37_釜検知_stack=timdly_PH37_釜検知.U
				timdly_PH38_釜検知_stack=timdly_PH38_釜検知.U
				timdly_PH39_釜検知_stack=timdly_PH39_釜検知.U
				timdly_PH40_釜検知_stack=timdly_PH40_釜検知.U
				timdly_PH41_釜検知_stack=timdly_PH41_釜検知.U
				timdly_PH42_釜検知_stack=timdly_PH42_釜検知.U
				timdly_PH43_釜検知_stack=timdly_PH43_釜検知.U
				timdly_PH44_釜検知_stack=timdly_PH44_釜検知.U
				timdly_PH45_釜検知_stack=timdly_PH45_釜検知.U
				timdly_PH46_釜検知_stack=timdly_PH46_釜検知.U
				timdly_PH47_釜検知_stack=timdly_PH47_釜検知.U
				timdly_PH48_釜検知_stack=timdly_PH48_釜検知.U
				timdly_PH50_釜検知_stack=timdly_PH50_釜検知.U
				tim_MC29_モータローラ_stack=tim_MC29_モータローラ.U
				tim_MC30_モータローラ_stack=tim_MC30_モータローラ.U
				tim_MC31_モータローラ_stack=tim_MC31_モータローラ.U
				tim_MC32_モータローラ_stack=tim_MC32_モータローラ.U
				tim_MC33_モータローラ_stack=tim_MC33_モータローラ.U
				tim_MC47_モータローラ_stack=tim_MC47_モータローラ.U
				tim_MC48_モータローラ_stack=tim_MC48_モータローラ.U
				tim_MC49_モータローラ_stack=tim_MC49_モータローラ.U
				tim_MC50_モータローラ_stack=tim_MC50_モータローラ.U
				tim_MC51_モータローラ_stack=tim_MC51_モータローラ.U
				tim_MC52_モータローラ_stack=tim_MC52_モータローラ.U
				tim_MC53_モータローラ_stack=tim_MC53_モータローラ.U

				timstack=ON
			end if

			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC29_モータローラ=OFF
			mMC30_モータローラ=OFF
			mMC31_モータローラ=OFF
			mMC32_モータローラ=OFF
			mMC33_モータローラ=OFF
			mMC47_モータローラ=OFF
			mMC48_モータローラ=OFF
			mMC49_モータローラ=OFF
			mMC50_モータローラ=OFF
			mMC51_モータローラ=OFF
			mMC52_モータローラ=OFF
			mMC53_モータローラ=OFF		

			'---------------------------------
		end if
		
		'---------------------------------
		inc(搬送コンベアF2EmgStep)
	case 2
		if ResetFlg then
			inc(搬送コンベアF2EmgStep)
		end if
	case 3
		if (搬送コンベアF2AutoMode and 自動搬送AutoMode ) or 搬送コンベアF2step<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseMC29_モータローラ=OFF
				pauseMC30_モータローラ=OFF
				pauseMC31_モータローラ=OFF
				pauseMC32_モータローラ=OFF
				pauseMC33_モータローラ=OFF
				pauseMC47_モータローラ=OFF
				pauseMC48_モータローラ=OFF
				pauseMC49_モータローラ=OFF
				pauseMC50_モータローラ=OFF
				pauseMC51_モータローラ=OFF
				pauseMC52_モータローラ=OFF
				pauseMC53_モータローラ=OFF

				tim_procstep.U=tim_procstep_stack
				tim_搬出指令.U=tim_搬出指令_stack
				tim_搬入指令.U=tim_搬入指令_stack
				tim_IH炊飯ユニット搬出.U=tim_IH炊飯ユニット搬出_stack
				tim_IH炊飯ユニット搬入.U=tim_IH炊飯ユニット搬入_stack
				tim_モータローラ排出.U=tim_モータローラ排出_stack
				timdly_PH37_釜検知.U=timdly_PH37_釜検知_stack
				timdly_PH38_釜検知.U=timdly_PH38_釜検知_stack
				timdly_PH39_釜検知.U=timdly_PH39_釜検知_stack
				timdly_PH40_釜検知.U=timdly_PH40_釜検知_stack
				timdly_PH41_釜検知.U=timdly_PH41_釜検知_stack
				timdly_PH42_釜検知.U=timdly_PH42_釜検知_stack
				timdly_PH43_釜検知.U=timdly_PH43_釜検知_stack
				timdly_PH44_釜検知.U=timdly_PH44_釜検知_stack
				timdly_PH45_釜検知.U=timdly_PH45_釜検知_stack
				timdly_PH46_釜検知.U=timdly_PH46_釜検知_stack
				timdly_PH47_釜検知.U=timdly_PH47_釜検知_stack
				timdly_PH48_釜検知.U=timdly_PH48_釜検知_stack
				timdly_PH50_釜検知.U=timdly_PH50_釜検知_stack
				tim_MC29_モータローラ.U=tim_MC29_モータローラ_stack
				tim_MC30_モータローラ.U=tim_MC30_モータローラ_stack
				tim_MC31_モータローラ.U=tim_MC31_モータローラ_stack
				tim_MC32_モータローラ.U=tim_MC32_モータローラ_stack
				tim_MC33_モータローラ.U=tim_MC33_モータローラ_stack
				tim_MC47_モータローラ.U=tim_MC47_モータローラ_stack
				tim_MC48_モータローラ.U=tim_MC48_モータローラ_stack
				tim_MC49_モータローラ.U=tim_MC49_モータローラ_stack
				tim_MC50_モータローラ.U=tim_MC50_モータローラ_stack
				tim_MC51_モータローラ.U=tim_MC51_モータローラ_stack
				tim_MC52_モータローラ.U=tim_MC52_モータローラ_stack
				tim_MC53_モータローラ.U=tim_MC53_モータローラ_stack

				'---------------------------------
				inc(搬送コンベアF2EmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(搬送コンベアF2EmgStep)		
		end if				
	case 4
		timstack=OFF
		搬送コンベアF2EmgStep=0
		搬送コンベアF2Emg=OFF
	end select
		
end if 'if 搬送コンベアF2EmgStep=0 then
