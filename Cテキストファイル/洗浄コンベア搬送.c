'洗浄コンベア搬送
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	洗浄コンベア搬送
'
'	MC10_反転モータ正転	-> MC37_反転モータ正転
'	MC10_反転モータ逆転 -> MC37_反転モータ逆転
'
'	PH45_釜検知		-> PH59_釜検知
'	PH46_フタ検知	-> PH62_フタ検知
'	PH7_釜検知		-> PH63_釜検知
'	PH8_フタ検知	-> PH64_フタ検知
'	PH9_釜検知		-> PH65_釜検知
'	PH10_フタ検知	-> PH66_フタ検知
'
'===================================================================================================================
客先コード=川崎北部
'===================================================================================================================
select case 客先コード

case 川崎南部

case 川崎北部

end select

'===================================================================================================================
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理
    洗浄コンベア搬送AutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    洗浄コンベア搬送AutoRun=OFF
    洗浄コンベア搬送許可=ON
    洗浄コンベア搬送OrgErr=OFF
    洗浄コンベア搬送Err=OFF
    洗浄コンベア搬送Emg=OFF
    洗浄コンベア搬送step=0
    洗浄コンベア搬送ErrStep=0
    洗浄コンベア搬送OrgErrStep=0
    洗浄コンベア搬送EmgStep=0

	INV1_コンベアモータ正転step=0
	INV2_コンベアモータ正転step=0
	INV3_コンベアモータ正転step=0
	MC37_反転モータ正転step=0
	MC37_反転モータ逆転step=0
	釜フタストッパ1step=0
	釜フタストッパ2step=0
	釜フタストッパ3step=0
	釜フタストッパ4step=0
	
	ワンサイクルflg=OFF

	if SSW3_自動モード then	
		ManualInite=1
	else
		ManualInite=0	
	end if

end if
'===================================================================================================================
'【 原点 】
洗浄コンベア搬送Org=1

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	洗浄コンベア搬送Emg=ON
	洗浄コンベア搬送EmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
tmr(not(SV71_釜フタストッパ) and not(XSW85_釜フタストッパ下降端) and not(pnlPBXSW85_釜フタストッパ下降端), tim_notXSW85_釜フタストッパ下降端,#40)
tmr(not(SV77_釜フタストッパ) and not(XSW90_釜フタストッパ下降端) and not(pnlPBXSW90_釜フタストッパ下降端), tim_notXSW90_釜フタストッパ下降端,#40)
tmr(not(SV83_釜フタストッパ) and not(XSW95_釜フタストッパ下降端) and not(pnlPBXSW95_釜フタストッパ下降端), tim_notXSW95_釜フタストッパ下降端,#40)
tmr(not(SV89_釜フタストッパ) and not(XSW100_釜フタストッパ下降端) and not(pnlPBXSW100_釜フタストッパ下降端), tim_notXSW100_釜フタストッパ下降端,#40)

'tmr(SV71_釜フタストッパ and XSW85_釜フタストッパ下降端 and not(pnlPBXSW85_釜フタストッパ下降端), tim_XSW85_釜フタストッパ下降端,#10)
if LDF(SV71_釜フタストッパ) and XSW85_釜フタストッパ下降端 and not(pnlPBXSW85_釜フタストッパ下降端) then
	SET(tim_XSW85_釜フタストッパ下降端)
end if
'tmr(SV77_釜フタストッパ and XSW90_釜フタストッパ下降端 and not(pnlPBXSW90_釜フタストッパ下降端), tim_XSW90_釜フタストッパ下降端,#10)
if LDF(SV77_釜フタストッパ) and XSW90_釜フタストッパ下降端 and not(pnlPBXSW90_釜フタストッパ下降端) then
	SET(tim_XSW90_釜フタストッパ下降端)
end if
'tmr(SV83_釜フタストッパ and XSW95_釜フタストッパ下降端 and not(pnlPBXSW95_釜フタストッパ下降端), tim_XSW95_釜フタストッパ下降端,#10)
if LDF(SV83_釜フタストッパ) and XSW95_釜フタストッパ下降端 and not(pnlPBXSW95_釜フタストッパ下降端) then
	SET(tim_XSW95_釜フタストッパ下降端)
end if
'tmr(SV89_釜フタストッパ and XSW100_釜フタストッパ下降端 and not(pnlPBXSW100_釜フタストッパ下降端), tim_XSW100_釜フタストッパ下降端,#10)
if LDF(SV89_釜フタストッパ) and XSW100_釜フタストッパ下降端 and not(pnlPBXSW100_釜フタストッパ下降端) then
	SET(tim_XSW100_釜フタストッパ下降端)
end if


tms(not(SV71_釜フタストッパ),passtimXSW85_釜フタストッパ下降端,passtimXSW85_釜フタストッパ下降端_val)
tms(not(SV77_釜フタストッパ),passtimXSW90_釜フタストッパ下降端,passtimXSW90_釜フタストッパ下降端_val)
tms(not(SV83_釜フタストッパ),passtimXSW95_釜フタストッパ下降端,passtimXSW95_釜フタストッパ下降端_val)
tms(not(SV89_釜フタストッパ),passtimXSW100_釜フタストッパ下降端,passtimXSW100_釜フタストッパ下降端_val)

tmr(MC37_反転モータ正転 and not(LS6_空釜反転反転位置) and not(pnlPBLS6_空釜反転反転位置),tim_LS6_空釜反転反転位置,#80)
tmr(MC37_反転モータ逆転 and not(LS5_空釜反転原点位置) and not(pnlPBLS5_空釜反転原点位置),tim_LS5_空釜反転原点位置,#80)

if ldp(tim_XSW85_釜フタストッパ下降端.B) or ldp(tim_notXSW85_釜フタストッパ下降端.B) then
	errpassXSW85_釜フタストッパ下降端=ON
	almXSW85_釜フタストッパ下降端=ON
	pnlPBXSW85_釜フタストッパ下降端=ON
	洗浄コンベア搬送ErrStep=1

else if ldp(tim_XSW90_釜フタストッパ下降端.B) or ldp(tim_notXSW90_釜フタストッパ下降端.B) then
	errpassXSW90_釜フタストッパ下降端=ON
	almXSW90_釜フタストッパ下降端=ON
	pnlPBXSW90_釜フタストッパ下降端=ON
	洗浄コンベア搬送ErrStep=1

else if ldp(tim_XSW95_釜フタストッパ下降端.B) or ldp(tim_notXSW95_釜フタストッパ下降端.B) then
	errpassXSW95_釜フタストッパ下降端=ON
	almXSW95_釜フタストッパ下降端=ON
	pnlPBXSW95_釜フタストッパ下降端=ON
	洗浄コンベア搬送ErrStep=1

else if ldp(tim_XSW100_釜フタストッパ下降端.B) or ldp(tim_notXSW100_釜フタストッパ下降端.B) then
	errpassXSW100_釜フタストッパ下降端=ON
	almXSW100_釜フタストッパ下降端=ON
	pnlPBXSW100_釜フタストッパ下降端=ON
	洗浄コンベア搬送ErrStep=1

else if ldp(tim_LS6_空釜反転反転位置.B) then
	ejectMC37_反転モータ正転=OFF
	almLS6_空釜反転反転位置=ON
	洗浄コンベア搬送ErrStep=1

else if ldp(tim_LS5_空釜反転原点位置.B) then
	ejectMC37_反転モータ逆転=OFF
	almLS5_空釜反転原点位置=ON
	洗浄コンベア搬送ErrStep=1


end if	
'===================================================================================================================
'【 フタ釜検出LSディレー】
'tmr(LS11_釜フタ検知,timdly_LS11_釜フタ検知,2)
'tmr(LS12_釜フタ検知,timdly_LS12_釜フタ検知,2)
'tmr(LS13_釜フタ検知,timdly_LS13_釜フタ検知,2)
'tmr(LS14_釜フタ検知,timdly_LS14_釜フタ検知,2)

'tmr(not(LS11_釜フタ検知),nottimdly_LS11_釜フタ検知,2)
'tmr(not(LS12_釜フタ検知),nottimdly_LS12_釜フタ検知,2)
'tmr(not(LS13_釜フタ検知),nottimdly_LS13_釜フタ検知,2)
'tmr(not(LS14_釜フタ検知),nottimdly_LS14_釜フタ検知,2)

tmr(PH63_釜検知,timdly_PH63_釜検知,4)
tmr(PH64_フタ検知,timdly_PH64_フタ検知,4)
tmr(PH59_釜検知,timdly_PH59_釜検知,4)
tmr(PH62_フタ検知,timdly_PH62_フタ検知,4)

if 洗浄コンベア搬送AutoRun  then	
	if not(洗浄ユニット1禁止) and (mMC58_洗浄ポンプA and not(pauseMC58_洗浄ポンプA) and  getEDC1_PV>=(setEDC1_SV-5) ) then
		配米準備釜数カウント可能=ON
	else if not(洗浄ユニット2禁止) and (mMC59_洗浄ポンプB and not(pauseMC59_洗浄ポンプB) and  getEDC2_PV>=(setEDC2_SV-5) ) then
		配米準備釜数カウント可能=ON
	else if not(洗浄ユニット3禁止) and (mMC60_洗浄ポンプC and not(pauseMC60_洗浄ポンプC) and  getEDC3_PV>=(setEDC3_SV-5) ) then
		配米準備釜数カウント可能=ON
	else if not(洗浄ユニット4禁止) and (mMC61_洗浄ポンプD and not(pauseMC61_洗浄ポンプD) and  getEDC4_PV>=(setEDC4_SV-5) ) then
		配米準備釜数カウント可能=ON
	end if
else
	配米準備釜数カウント可能=OFF
end if


if not(配米準備釜数カウント可能) then
	IND_洗浄準備中=ON
else
	IND_洗浄準備中=OFF
end if


'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 洗浄コンベア搬送AutoMode	自動モード セレクトスイッチ
'System :: 洗浄コンベア搬送AutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 洗浄コンベア搬送Emg	その場停止


if not(洗浄コンベア搬送Emg) then  
	
	if 洗浄コンベア搬送ErrStep=0  then

	if not(洗浄コンベア搬送OrgErr) then

	if ワンサイクルflg or (洗浄コンベア搬送AutoMode and 自動搬送AutoMode ) or 洗浄コンベア搬送step<>0 then
	
		if not(洗浄コンベア搬送AutoMode and 自動搬送AutoMode ) then
			洗浄コンベア搬送AutoRun=OFF
		end if

		if ManualInite=1 then
			PBL44_コンベア=OFF
		
			mSV71_釜フタストッパ=ON
			mSV77_釜フタストッパ=ON
			mSV83_釜フタストッパ=ON
			mSV89_釜フタストッパ=ON

			mINV1_コンベアモータ正転=OFF
			mINV2_コンベアモータ正転=OFF
			ejectINV3_コンベアモータ正転=OFF
			
			manual洗浄コンベア=OFF
			tmp1INV1_コンベアモータ正転=OFF
			tmp1INV2_コンベアモータ正転=OFF
			tmp1INV3_コンベアモータ正転=OFF
			tmp2INV1_コンベアモータ正転=OFF
			tmp2INV2_コンベアモータ正転=OFF
			tmp2INV3_コンベアモータ正転=OFF
	
			ManualInite=0
		end if

	'------------------------------------------------------------------------------------------------
	'INV1_コンベアモータ正転
	tmr(tim_INV1_コンベアモータ正転,tim_INV1_コンベアモータ正転_val)
	
	select case INV1_コンベアモータ正転step
	
	case 0
	
	case 1
	
		PH59_釜起動検知=timdly_PH59_釜検知
		PH62_フタ起動検知=timdly_PH62_フタ検知
		
		if PH59_釜起動検知 or PH62_フタ起動検知 then
		
			if PH59_釜起動検知 and PH62_フタ起動検知 then '釜搬送
				shiftreg釜フタ判定0=$80

				'if 配米準備釜数カウント可能  and 運転準備中 then
				'	if 配米準備釜数現在値<配米準備釜数設定値 then
				'		inc(配米準備釜数現在値)
				'	end if
				'end if			
				'
				'if 炊飯完了からの釜カウント>0 then
				'	dec(炊飯完了からの釜カウント)
				'end if

			else if not(PH59_釜起動検知) and PH62_フタ起動検知 then 'フタ搬送
				shiftreg釜フタ判定0=$40			

				if 配米準備釜数カウント可能  and 運転準備中 then
					if 配米準備釜数現在値<配米準備釜数設定値 then
						inc(配米準備釜数現在値)
					end if
				end if			
				
				if 炊飯完了からの釜カウント>0 then
					dec(炊飯完了からの釜カウント)
				end if

			end if

			inc(INV1_コンベアモータ正転step)
		else
			INV1_コンベアモータ正転step=0
			洗浄入口搬送排出要求=OFF
			釜反転入口排出要求=OFF
		end if

	case 2
		setS05c1=5000
		setS08c1=10
		setS09c1=10
		mINV1_コンベアモータ正転=ON
		inc(INV1_コンベアモータ正転step)
	
	case 3
		if not(PH59_釜検知) and not(PH62_フタ検知) then
			inc(INV1_コンベアモータ正転step)
		end if

	case 4
		tim_INV1_コンベアモータ正転_val=60 'モータ停止タイミング
		res(tim_INV1_コンベアモータ正転)
		inc(INV1_コンベアモータ正転step)
	
	case 5
		if tim_INV1_コンベアモータ正転.B then
			inc(INV1_コンベアモータ正転step)
		end if
		
	case 6
		mINV1_コンベアモータ正転=OFF
		inc(INV1_コンベアモータ正転step)
	
	case 7
		釜反転入口排出要求=OFF
		洗浄入口搬送排出要求=OFF
		INV1_コンベアモータ正転step=0

	end select
	'------------------------------------------------------------------------------------------------
	'ストッパー上昇タスク
	'---------------------------------------------------
	tmr(tim_釜フタストッパ1,tim_釜フタストッパ1_val)
	select case 釜フタストッパ1step
	case 0
	case 1
		tim_釜フタストッパ1_val=洗浄1ストッパー上昇タイミング
		res(tim_釜フタストッパ1)
		inc(釜フタストッパ1step)

	case 2
		if tim_釜フタストッパ1.B then
			inc(釜フタストッパ1step)
		end if	
	
	case 3
		mSV71_釜フタストッパ=ON	'ストッパー上昇
		inc(釜フタストッパ1step)
	case 4
		釜フタストッパ1step=0	
	end select
	'---------------------------------------------------
	tmr(tim_釜フタストッパ2,tim_釜フタストッパ2_val)
	select case 釜フタストッパ2step
	case 0
	case 1
		tim_釜フタストッパ2_val=洗浄2ストッパー上昇タイミング
		res(tim_釜フタストッパ2)
		inc(釜フタストッパ2step)

	case 2
		if tim_釜フタストッパ2.B then
			inc(釜フタストッパ2step)
		end if	
	
	case 3
		mSV77_釜フタストッパ=ON
		inc(釜フタストッパ2step)
	case 4
		釜フタストッパ2step=0	
	end select
	'---------------------------------------------------
	tmr(tim_釜フタストッパ3,tim_釜フタストッパ3_val)
	select case 釜フタストッパ3step
	case 0
	case 1
		tim_釜フタストッパ3_val=洗浄3ストッパー上昇タイミング
		res(tim_釜フタストッパ3)
		inc(釜フタストッパ3step)

	case 2
		if tim_釜フタストッパ3.B then
			inc(釜フタストッパ3step)
		end if	
	
	case 3
		mSV83_釜フタストッパ=ON
		inc(釜フタストッパ3step)
	case 4
		釜フタストッパ3step=0	
	end select
	'---------------------------------------------------
	tmr(tim_釜フタストッパ4,tim_釜フタストッパ4_val)
	select case 釜フタストッパ4step
	case 0
	case 1
		tim_釜フタストッパ4_val=洗浄4ストッパー上昇タイミング
		res(tim_釜フタストッパ4)
		inc(釜フタストッパ4step)

	case 2
		if tim_釜フタストッパ4.B then
			inc(釜フタストッパ4step)
		end if	
	
	case 3
		mSV89_釜フタストッパ=ON
		inc(釜フタストッパ4step)
	case 4
		釜フタストッパ4step=0	
	end select
	'------------------------------------------------------------------------------------------------
	'INV2_コンベアモータ正転
	tmr(tim_INV2_コンベアモータ正転,tim_INV2_コンベアモータ正転_val)
	
	select case INV2_コンベアモータ正転step
	
	case 0
	
	case 1
		tim_INV2_コンベアモータ正転_val=INV2起動待ち時間 '1号機(0) 2号機(10)
		res(tim_INV2_コンベアモータ正転)
		inc(INV2_コンベアモータ正転step)
		
	case 2
		if tim_INV2_コンベアモータ正転.B then
			inc(INV2_コンベアモータ正転step)
		end if		
	
	case 3
		'if not(XSW82_釜フタ押さえ下降端A) and not(XSW84_釜フタ押さえ下降端B) then
			'if not(XSW87_釜フタ押さえ下降端A) and not(XSW89_釜フタ押さえ下降端B) then
				'if not(XSW92_釜フタ押さえ下降端A) and not(XSW94_釜フタ押さえ下降端B) then
					'if not(XSW97_釜フタ押さえ下降端A) and not(XSW99_釜フタ押さえ下降端B) then
							inc(INV2_コンベアモータ正転step)
					'end if
				'end if
			'end if	
		'end if

	case 4
		setS05c2=5000
		setS08c2=10
		setS09c2=25 '<-停止調整
		mINV2_コンベアモータ正転=ON
		
		釜フタストッパ1step=1
		釜フタストッパ2step=1
		釜フタストッパ3step=1
		釜フタストッパ4step=1
		
		
		inc(INV2_コンベアモータ正転step)
	
	case 5
		tim_INV2_コンベアモータ正転_val=INV2ブレーキタイミング '1号機(28) 2号機(24)
		res(tim_INV2_コンベアモータ正転)
		inc(INV2_コンベアモータ正転step)

	
	case 6
		if tim_INV2_コンベアモータ正転.B then
			inc(INV2_コンベアモータ正転step)
		end if		

	case 7
		mINV2_コンベアモータ正転=OFF
		inc(INV2_コンベアモータ正転step)
	
	case 8
		tim_INV2_コンベアモータ正転_val=30
		res(tim_INV2_コンベアモータ正転)
		inc(INV2_コンベアモータ正転step)

	case 9
		if tim_INV2_コンベアモータ正転.B then
			inc(INV2_コンベアモータ正転step)
		end if		

	case 10
		if 釜フタストッパ1step=0 and 釜フタストッパ2step=0 and 釜フタストッパ3step=0 and 釜フタストッパ4step=0 then
			inc(INV2_コンベアモータ正転step)
		end if
		
	case 11
		INV2_コンベアモータ正転step=0

	end select
	
	'------------------------------------------------------------------------------------------------
	'INV3_コンベアモータ正転
	tmr(tim_INV3_コンベアモータ正転,tim_INV3_コンベアモータ正転_val)
	
	select case INV3_コンベアモータ正転step
	
	case 0
	
	case 1
		if PH63_釜検知 or PH64_フタ検知 then
			INV3_コンベアモータ正転step=0
		else
			inc(INV3_コンベアモータ正転step)	
		end if
	
	case 2
		setS05c3=5000
		setS08c3=10
		setS09c3=10
		ejectINV3_コンベアモータ正転=ON
		
		
		StageDevice50=shiftreg釜フタ判定4 'StageDevice37 , 釜:$80  フタ:$40

'		if not(ワンサイクルflg) and StageDevice50=$80 and not(PH65_釜検知) then
'			if MC37_反転モータ正転step=0 then
'				MC37_反転モータ正転step=1
'			end if
'		end if


		LatchPH63_釜検知=OFF
		LatchPH64_フタ検知=OFF
		
		inc(INV3_コンベアモータ正転step)

	case 3
		if not(PH63_釜検知) and not(PH64_フタ検知) then
				tim_INV3_コンベアモータ正転_val=120 'モータ停止タイミング
				res(tim_INV3_コンベアモータ正転)
				inc(INV3_コンベアモータ正転step)
		end if

	case 4
		if (PH63_釜検知 and timdly_PH63_釜検知.B) or (PH64_フタ検知 and timdly_PH64_フタ検知.B) or tim_INV3_コンベアモータ正転.B then
		
			if SEL2_1_運転切換（単動） and tim_INV3_コンベアモータ正転.B then
				StageDevice50=0
			end if
			
			inc(INV3_コンベアモータ正転step)
		end if
		
	case 5
		ejectINV3_コンベアモータ正転=OFF
		inc(INV3_コンベアモータ正転step)
	
	case 6
		if StageDevice50=$80 or StageDevice50=$40 then
			洗浄コンベア搬送排出要求=ON
		else
			洗浄コンベア搬送排出要求=OFF
		end if		
		
		INV3_コンベアモータ正転step=0
	
	end select
	'------------------------------------------------------------------------------------------------
	'MC37_反転モータ正転  （昇降装置->洗浄機側）
	tmr(tim_MC37_反転モータ正転,tim_MC37_反転モータ正転_val)
	
	select case MC37_反転モータ正転step
	
	case 0
	
	case 1
		ejectMC37_反転モータ正転=ON
		inc(MC37_反転モータ正転step)

	case 2
		if LS6_空釜反転反転位置 then
			inc(MC37_反転モータ正転step)
		end if
		
	case 3
		ejectMC37_反転モータ正転=OFF
		inc(MC37_反転モータ正転step)

	case 4		
		MC37_反転モータ正転step=0

	end select
	'------------------------------------------------------------------------------------------------
	'MC37_反転モータ逆転 (洗浄機側 -> 昇降機側）
	tmr(tim_MC37_反転モータ逆転,tim_MC37_反転モータ逆転_val)
	
	select case MC37_反転モータ逆転step
	
	case 0
	
	case 1
		ejectMC37_反転モータ逆転=ON
		inc(MC37_反転モータ逆転step)

	case 2
		if LS5_空釜反転原点位置 then
			inc(MC37_反転モータ逆転step)
		end if
	
	case 3
		ejectMC37_反転モータ逆転=OFF
		inc(MC37_反転モータ逆転step)
		
	case 4
		MC37_反転モータ逆転step=0

	end select

	'------------------------------------------------------------------------------------------------


	'===================================================================================================================
	'【 リフタータスク 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case 洗浄コンベア搬送step
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 洗浄コンベア搬送AutoRun or ワンサイクルflg then
				inc(洗浄コンベア搬送step)
			else 
				洗浄コンベア搬送step=0 '終了待機
			end if
		
		case 2
			if PH63_釜検知 or PH64_フタ検知 then
				StageDevice50=shiftreg釜フタ判定5
				洗浄コンベア搬送動作中=OFF
				洗浄コンベア搬送排出要求=ON
				洗浄コンベア搬送step=1
			else
				inc(洗浄コンベア搬送step)
			end if
							
		
		case 3
		
		' [ 次の搬送コンベア停止確認 ]
			if (洗浄コンベア搬送排出要求=OFF or ワンサイクルflg) and  釜反転出口動作中=OFF and  (釜反転入口排出要求 or ワンサイクルflg) and 洗浄ユニットorg then
				inc(洗浄コンベア搬送step)
			else
				洗浄コンベア搬送step=1s
			end if
		
		case 4
			if 洗浄完了 then
				inc(洗浄コンベア搬送step)
			else
				洗浄コンベア搬送step=1
			end if

		case 5
			洗浄コンベア搬送step=100
		'--------------------------------------------------------------------------------------------------------------
		case 100			
			PH59_釜起動検知=PH59_釜検知
			PH62_フタ起動検知=PH62_フタ検知
			洗浄コンベア搬送動作中=ON

			mSV71_釜フタストッパ=OFF	'ストッパー下降
			mSV77_釜フタストッパ=OFF
			mSV83_釜フタストッパ=OFF
			mSV89_釜フタストッパ=OFF
			
			errpassXSW85_釜フタストッパ下降端=OFF
			errpassXSW90_釜フタストッパ下降端=OFF
			errpassXSW95_釜フタストッパ下降端=OFF
			errpassXSW100_釜フタストッパ下降端=OFF
			
			inc(洗浄コンベア搬送step)
		
		case 101
			if (errpassXSW85_釜フタストッパ下降端 or ((XSW85_釜フタストッパ下降端 and not(pnlPBXSW85_釜フタストッパ下降端)) or passXSW85_釜フタストッパ下降端) or 洗浄ユニット1禁止) then
				if (errpassXSW90_釜フタストッパ下降端 or ((XSW90_釜フタストッパ下降端 and not(pnlPBXSW90_釜フタストッパ下降端)) or passXSW90_釜フタストッパ下降端) or 洗浄ユニット2禁止) then
					if (errpassXSW95_釜フタストッパ下降端 or ((XSW95_釜フタストッパ下降端 and not(pnlPBXSW95_釜フタストッパ下降端)) or passXSW95_釜フタストッパ下降端) or 洗浄ユニット3禁止) then
						if (errpassXSW100_釜フタストッパ下降端 or ((XSW100_釜フタストッパ下降端 and not(pnlPBXSW100_釜フタストッパ下降端)) or passXSW100_釜フタストッパ下降端) or 洗浄ユニット4禁止) then
							inc(洗浄コンベア搬送step)
						end if
					end if
				end if
			end if

		case 102
			tim_procstep_val=10
			res(tim_procstep)
			inc(洗浄コンベア搬送step)

		case 103
			if tim_procstep.B then			
				inc(洗浄コンベア搬送step)
			end if

		case 104

			INV1_コンベアモータ正転step=1			
			INV2_コンベアモータ正転step=1
			INV3_コンベアモータ正転step=1
			
			inc(洗浄コンベア搬送step)
		
		case 105
			if INV1_コンベアモータ正転step=0 and  INV2_コンベアモータ正転step=0 and INV3_コンベアモータ正転step=0 then
				inc(洗浄コンベア搬送step)
			end if
		
		case 106
			tim_procstep_val=0
			res(tim_procstep)
			inc(洗浄コンベア搬送step)

		case 107
			if tim_procstep.B then			
				inc(洗浄コンベア搬送step)
			end if
		
		case 108

			shiftreg釜フタ判定8	=	shiftreg釜フタ判定7
			shiftreg釜フタ判定7	=	shiftreg釜フタ判定6
			shiftreg釜フタ判定6	=	shiftreg釜フタ判定5
			shiftreg釜フタ判定5	=	shiftreg釜フタ判定4
			shiftreg釜フタ判定4	=	shiftreg釜フタ判定3
			shiftreg釜フタ判定3	=	shiftreg釜フタ判定2
			shiftreg釜フタ判定2	=	shiftreg釜フタ判定1
			shiftreg釜フタ判定1	=	shiftreg釜フタ判定0
			shiftreg釜フタ判定0 = 0

			洗浄完了=OFF
			釜反転入口排出要求=OFF
			洗浄入口搬送排出要求=OFF
			洗浄コンベア搬送動作中=OFF
			洗浄コンベア搬送step=1
			
					
			ワンサイクルflg=OFF

		end select
	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else
		if ManualInite=0 and ワンサイクルflg=OFF then
			PBL44_コンベア=OFF
		
			mSV71_釜フタストッパ=OFF
			mSV77_釜フタストッパ=OFF
			mSV83_釜フタストッパ=OFF
			mSV89_釜フタストッパ=OFF

			mINV1_コンベアモータ正転=OFF
			mINV2_コンベアモータ正転=OFF
			ejectINV3_コンベアモータ正転=OFF
			
			manual洗浄コンベア=OFF
			tmp1INV1_コンベアモータ正転=OFF
			tmp1INV2_コンベアモータ正転=OFF
			tmp1INV3_コンベアモータ正転=OFF
			tmp2INV1_コンベアモータ正転=OFF
			tmp2INV2_コンベアモータ正転=OFF
			tmp2INV3_コンベアモータ正転=OFF

			ManualInite=1
		end if

		
		'res(tim_XSW85_釜フタストッパ下降端.B)
		'res(tim_XSW90_釜フタストッパ下降端.B)
		'res(tim_XSW95_釜フタストッパ下降端.B)
		'res(tim_XSW100_釜フタストッパ下降端.B)

		洗浄コンベア搬送AutoRun=OFF
		洗浄コンベア搬送step=0 '終了
		

		'---------------------------------------------------------------------
		' 洗浄コンベア マニュアル運転
		'---------------------------------------------------------------------
		PBL44_コンベア=mINV1_コンベアモータ正転 or mINV2_コンベアモータ正転 or ejectINV3_コンベアモータ正転
		
		mINV1_コンベアモータ正転=tmp1INV1_コンベアモータ正転 or tmp2INV1_コンベアモータ正転
		mINV2_コンベアモータ正転=tmp1INV2_コンベアモータ正転 or tmp2INV2_コンベアモータ正転
		ejectINV3_コンベアモータ正転=tmp1INV3_コンベアモータ正転 or tmp2INV3_コンベアモータ正転
		
		if PB45_全停止SW and (not(timdly_PH63_釜検知) and not(timdly_PH64_フタ検知)) then

			if SEL2_1_運転切換（単動） then
				if 洗浄ユニットOrg and 洗浄コンベア搬送Org and 釜反転出口Org then 

					tmp2INV1_コンベアモータ正転=OFF
					tmp2INV2_コンベアモータ正転=OFF
					tmp2INV3_コンベアモータ正転=OFF
					
					if ldp(PB44_コンベアSW) then
						if manual洗浄コンベア then
							manual洗浄コンベア=OFF
						else
							manual洗浄コンベア=ON
						end if
					end if
					
					tmp1INV1_コンベアモータ正転=manual洗浄コンベア
					tmp1INV2_コンベアモータ正転=manual洗浄コンベア
					tmp1INV3_コンベアモータ正転=manual洗浄コンベア

				else
					if ldp(PB44_コンベアSW) then
						if not(洗浄ユニットOrg) then
							洗浄ユニットOrgErr=ON
						end if
						
						if not(洗浄コンベア搬送Org) then
							洗浄コンベア搬送OrgErr=ON
						end if
						
						if not(釜反転出口Org) then
							釜反転出口OrgErr=ON
						end if
					end if
				end if
			else
				
					manual洗浄コンベア=OFF
					tmp1INV1_コンベアモータ正転=OFF
					tmp1INV2_コンベアモータ正転=OFF
					tmp1INV3_コンベアモータ正転=OFF

					if ldp(pnlPBINV1_コンベアモータ正転) then
						if tmp2INV1_コンベアモータ正転 then
							tmp2INV1_コンベアモータ正転=OFF
						else
							tmp2INV1_コンベアモータ正転=ON
						end if
					end if
							
				if 洗浄ユニットOrg and 洗浄コンベア搬送Org  and 釜反転出口Org then 
					if ldp(pnlPBINV2_コンベアモータ正転) then
						if tmp2INV2_コンベアモータ正転 then
							tmp2INV2_コンベアモータ正転=OFF
						else
							tmp2INV2_コンベアモータ正転=ON
						end if
					end if

					if ldp(pnlPBINV3_コンベアモータ正転) then
						if tmp2INV3_コンベアモータ正転 then
							tmp2INV3_コンベアモータ正転=OFF
						else
							tmp2INV3_コンベアモータ正転=ON
						end if
					end if
				else
					if ldp(pnlPBINV2_コンベアモータ正転) or ldp(pnlPBINV3_コンベアモータ正転) then
						if not(洗浄ユニットOrg) then
							洗浄ユニットOrgErr=ON
						end if
						
						if not(洗浄コンベア搬送Org) then
							洗浄コンベア搬送OrgErr=ON
						end if
						
						if not(釜反転出口Org) then
							釜反転出口OrgErr=ON
						end if

					end if								
				end if
			end if

		else
			mINV1_コンベアモータ正転=OFF
			mINV2_コンベアモータ正転=OFF
			ejectINV3_コンベアモータ正転=OFF
			
			manual洗浄コンベア=OFF
			tmp1INV1_コンベアモータ正転=OFF
			tmp1INV2_コンベアモータ正転=OFF
			tmp1INV3_コンベアモータ正転=OFF
			tmp2INV1_コンベアモータ正転=OFF
			tmp2INV2_コンベアモータ正転=OFF
			tmp2INV3_コンベアモータ正転=OFF
						
		end if
		'---------------------------------------------------------------------		
		'洗浄ストッパ  マニュアル運転		
		'---------------------------------------------------------------------		
		if not(manual洗浄コンベア) then
		
			if ldp(pnlPBSV71_釜フタストッパ) then
				if mSV71_釜フタストッパ then
					mSV71_釜フタストッパ=OFF
				else
					mSV71_釜フタストッパ=ON
				end if
			end if
			
			if ldp(pnlPBSV77_釜フタストッパ) then
				if mSV77_釜フタストッパ then
					mSV77_釜フタストッパ=OFF
				else
					mSV77_釜フタストッパ=ON
				end if
			end if
			
			if ldp(pnlPBSV83_釜フタストッパ) then
				if mSV83_釜フタストッパ then
					mSV83_釜フタストッパ=OFf
				else
					mSV83_釜フタストッパ=ON
				end if
			end if
			
			if ldp(pnlPBSV89_釜フタストッパ) then
				if mSV89_釜フタストッパ then
					mSV89_釜フタストッパ=OFF
				else
					mSV89_釜フタストッパ=ON
				end if
			end if
			
			
			if ldp(PB25_洗浄機単動運転) and (not(PH63_釜検知) and not(PH64_フタ検知))  and (not(PH65_釜検知) and not(PH66_フタ検知)) and  洗浄ユニットOrg then

					PH59_釜起動検知=PH59_釜検知
					PH62_フタ起動検知=PH62_フタ検知
					
					if PH59_釜検知 or PH62_フタ検知 then			
						if PH59_釜検知 and PH62_フタ検知 then
							shiftreg釜フタ判定0=$80
						else if not(PH59_釜検知) and PH62_フタ検知 then
							shiftreg釜フタ判定0=$40			
						end if
					else
						shiftreg釜フタ判定0=$0
					end if
			
'					if not(LS5_空釜反転原点位置) and MC37_反転モータ逆転step=0 then
'						MC37_反転モータ逆転step=1
'					else
						ワンサイクルflg=ON
						洗浄コンベア搬送step=1
'					end if
			end if
			
		end if		
		
	end if '洗浄コンベア搬送AutoMode and not(洗浄コンベア搬送OrgErrStep)

	'===================================================================================================================
	'【 洗浄コンベア搬送OrgErr処理 】
	else

		if ResetFlg then
			洗浄コンベア搬送OrgErr=OFF
		end if


	end if

	'===================================================================================================================
	'【タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
		洗浄コンベア搬送Err=ON

		mINV1_コンベアモータ正転=OFF
		mINV2_コンベアモータ正転=OFF
		ejectINV3_コンベアモータ正転=OFF
		
		mSV71_釜フタストッパ=OFF
		mSV77_釜フタストッパ=OFF
		mSV83_釜フタストッパ=OFF
		mSV89_釜フタストッパ=OFF


		洗浄コンベア搬送動作中=OFF

		tmr(tim_洗浄コンベア搬送ErrStep,tim_洗浄コンベア搬送ErrStep_val)
		
		select case 洗浄コンベア搬送ErrStep
		case 0
		
		'------------------------------------------------------------------
		case 1
			if ResetFlg then
			 	inc(洗浄コンベア搬送ErrStep)
			end if
			
		case 2
			almXSW85_釜フタストッパ下降端=OFF
			almXSW90_釜フタストッパ下降端=OFF
			almXSW95_釜フタストッパ下降端=OFF
			almXSW100_釜フタストッパ下降端=OFF
			almLS6_空釜反転反転位置=OFF
			almLS5_空釜反転原点位置=OFF

		 	inc(洗浄コンベア搬送ErrStep)
		case 3
			洗浄コンベア搬送Err=OFF

			res(tim_XSW85_釜フタストッパ下降端)
			res(tim_XSW90_釜フタストッパ下降端)
			res(tim_XSW95_釜フタストッパ下降端)
			res(tim_XSW100_釜フタストッパ下降端)
			res(tim_notXSW85_釜フタストッパ下降端)
			res(tim_notXSW90_釜フタストッパ下降端)
			res(tim_notXSW95_釜フタストッパ下降端)
			res(tim_notXSW100_釜フタストッパ下降端)
			res(tim_LS6_空釜反転反転位置)
			res(tim_LS5_空釜反転原点位置)

			洗浄コンベア搬送step=0
			INV1_コンベアモータ正転step=0
			INV2_コンベアモータ正転step=0
			INV3_コンベアモータ正転step=0
			MC37_反転モータ正転step=0
			MC37_反転モータ逆転step=0

			洗浄コンベア搬送ErrStep=0
		end select

	end if 'if 洗浄コンベア搬送ErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else

	select case 洗浄コンベア搬送EmgStep
	case 0
	
	case 1
		洗浄コンベア搬送AutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if ワンサイクルflg or (洗浄コンベア搬送AutoMode and 自動搬送AutoMode ) or 洗浄コンベア搬送step<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseMC37_反転モータ逆転=ON
			pauseMC37_反転モータ正転=ON
			
			pauseINV1_コンベアモータ正転=ON
			pauseINV2_コンベアモータ正転=ON
			pauseINV3_コンベアモータ正転=ON
			
			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				tim_manualコンベア_stack=tim_manualコンベア.U
				tim_INV1_コンベアモータ正転_stack=tim_INV1_コンベアモータ正転.U
				tim_INV2_コンベアモータ正転_stack=tim_INV2_コンベアモータ正転.U
				tim_INV3_コンベアモータ正転_stack=tim_INV3_コンベアモータ正転.U
				tim_MC37_反転モータ逆転_stack=tim_MC37_反転モータ逆転.U
				tim_MC37_反転モータ正転_stack=tim_MC37_反転モータ正転.U
				tim_釜フタストッパ1_stack=tim_釜フタストッパ1.U
				tim_釜フタストッパ2_stack=tim_釜フタストッパ2.U
				tim_釜フタストッパ3_stack=tim_釜フタストッパ3.U
				tim_釜フタストッパ4_stack=tim_釜フタストッパ4.U
				tim_洗浄コンベア搬送ErrStep_stack=tim_洗浄コンベア搬送ErrStep.U

				timdly_PH63_釜検知_stack=timdly_PH63_釜検知.U
				timdly_PH64_フタ検知_stack=timdly_PH64_フタ検知.U
				timdly_PH7_釜検知_stack=timdly_PH7_釜検知.U
				timdly_PH8_フタ検知_stack=timdly_PH8_フタ検知.U

				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC37_反転モータ逆転=OFF
			mMC37_反転モータ正転=OFF
			
			mINV1_コンベアモータ正転=OFF
			mINV2_コンベアモータ正転=OFF
			mINV3_コンベアモータ正転=OFF
			ejectINV3_コンベアモータ正転=OFF

			mSV71_釜フタストッパ=OFF	'ストッパー下降
			mSV77_釜フタストッパ=OFF
			mSV83_釜フタストッパ=OFF
			mSV89_釜フタストッパ=OFF

			tmp1INV1_コンベアモータ正転=OFF
			tmp1INV2_コンベアモータ正転=OFF
			tmp1INV3_コンベアモータ正転=OFF
			tmp2INV1_コンベアモータ正転=OFF
			tmp2INV2_コンベアモータ正転=OFF
			tmp2INV3_コンベアモータ正転=OFF

			'---------------------------------
		end if
		
		'---------------------------------
		inc(洗浄コンベア搬送EmgStep)
	case 2
		if ResetFlg then
			inc(洗浄コンベア搬送EmgStep)
		end if
	case 3
		if ワンサイクルflg or (洗浄コンベア搬送AutoMode and 自動搬送AutoMode ) or 洗浄コンベア搬送step<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseMC37_反転モータ逆転=OFF
				pauseMC37_反転モータ正転=OFF
				
				pauseINV1_コンベアモータ正転=OFF
				pauseINV2_コンベアモータ正転=OFF
				pauseINV3_コンベアモータ正転=OFF
				
				tim_procstep.U=tim_procstep_stack
				tim_manualコンベア.U=tim_manualコンベア_stack
				tim_INV1_コンベアモータ正転.U=tim_INV1_コンベアモータ正転_stack
				tim_INV2_コンベアモータ正転.U=tim_INV2_コンベアモータ正転_stack
				tim_INV3_コンベアモータ正転.U=tim_INV3_コンベアモータ正転_stack
				tim_MC37_反転モータ逆転.U=tim_MC37_反転モータ逆転_stack
				tim_MC37_反転モータ正転.U=tim_MC37_反転モータ正転_stack
				tim_釜フタストッパ1.U=tim_釜フタストッパ1_stack
				tim_釜フタストッパ2.U=tim_釜フタストッパ2_stack
				tim_釜フタストッパ3.U=tim_釜フタストッパ3_stack
				tim_釜フタストッパ4.U=tim_釜フタストッパ4_stack
				tim_洗浄コンベア搬送ErrStep.U=tim_洗浄コンベア搬送ErrStep_stack
				
				res(timdly_PH63_釜検知)
				res(timdly_PH64_フタ検知)
				res(timdly_PH7_釜検知)
				res(timdly_PH8_フタ検知)

				'---------------------------------
				inc(洗浄コンベア搬送EmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(洗浄コンベア搬送EmgStep)		
		end if				
	case 4
		timstack=OFF
		洗浄コンベア搬送EmgStep=0
		洗浄コンベア搬送Emg=OFF
	end select
		
end if 'if Emgstep_proc=0 then
