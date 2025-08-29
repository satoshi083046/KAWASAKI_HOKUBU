'洗浄タンク
'===================================================================================================================
'
'<<<<<<<	ユニット	>>>>>>>>
'
'===================================================================================================================
'
'	洗浄タンクユニット
'	
'mSV70_蒸気電磁弁 -> mMC_HT1_タンクヒータ
'pauseSV70_蒸気電磁弁 -> pauseMC_HT1_タンクヒータ

'mSV76_蒸気電磁弁 -> mMC_HT2_タンクヒータ
'pauseSV76_蒸気電磁弁 -> pauseMC_HT2_タンクヒータ

'mSV82_蒸気電磁弁 -> mMC_HT3_タンクヒータ
'pauseSV82_蒸気電磁弁 -> pauseMC_HT3_タンクヒータ

'mSV88_蒸気電磁弁 -> mMC_HT4_タンクヒータ
'pauseSV88_蒸気電磁弁 -> pauseMC_HT4_タンクヒータ

'mSV94_蒸気電磁弁 -> 削除
'pauseSV94_蒸気電磁弁 -> 削除

'===================================================================================================================
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理
    洗浄タンクAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    洗浄タンクAutoRun=OFF
    洗浄タンク許可=ON
    洗浄タンクOrgErr=OFF
    洗浄タンクErr=OFF
    洗浄タンクEmg=OFF
    洗浄タンクstep=0
    洗浄タンクErrStep=0
    洗浄タンクOrgErrStep=0
    洗浄タンクEmgStep=0
	
	set(tim_notFLT1_タンク上限) '上限ヒステリシスタイマー
	set(tim_notFLT3_タンク上限) '上限ヒステリシスタイマー
	set(tim_notFLT5_タンク上限) '上限ヒステリシスタイマー
	set(tim_notFLT7_タンク上限) '上限ヒステリシスタイマー
end if
'===================================================================================================================
'【 原点 】
洗浄タンクOrg=1

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	洗浄タンクEmg=ON
	洗浄タンクEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出

tmr(SV69_給湯電磁弁 and not(FLT2_タンク下限) and not(pnlPBFLT2_タンク下限),tim_FLT2_タンク下限,#100)
tmr(SV69_給湯電磁弁 and FLT2_タンク下限 and not(FLT1_タンク上限) and not(pnlPBFLT1_タンク上限),tim_FLT1_タンク上限,#100)
tmr(SV75_給湯電磁弁 and not(FLT4_タンク下限) and not(pnlPBFLT4_タンク下限),tim_FLT4_タンク下限,#100)
tmr(SV75_給湯電磁弁 and FLT4_タンク下限 and not(FLT3_タンク上限) and not(pnlPBFLT3_タンク上限),tim_FLT3_タンク上限,#100)
tmr(SV81_給湯電磁弁 and not(FLT6_タンク下限) and not(pnlPBFLT6_タンク下限),tim_FLT6_タンク下限,#100)
tmr(SV81_給湯電磁弁 and FLT6_タンク下限 and not(FLT5_タンク上限) and not(pnlPBFLT5_タンク上限),tim_FLT5_タンク上限,#100)
tmr(SV87_給湯電磁弁 and not(FLT8_タンク下限) and not(pnlPBFLT8_タンク下限),tim_FLT8_タンク下限,#100)
tmr(SV87_給湯電磁弁 and FLT8_タンク下限 and not(FLT7_タンク上限) and not(pnlPBFLT7_タンク上限),tim_FLT7_タンク上限,#100)

if 0 then

if ldp(tim_FLT2_タンク下限.B) then
	almFLT2_タンク下限 =ON
	洗浄タンクErrStep=1

else if ldp(tim_FLT1_タンク上限.B) then
	almFLT1_タンク上限=ON
	洗浄タンクErrStep=1	

else if ldp(tim_FLT4_タンク下限.B) then
	almFLT4_タンク下限=ON
	洗浄タンクErrStep=1

else if ldp(tim_FLT3_タンク上限.B) then
	almFLT3_タンク上限=ON
	洗浄タンクErrStep=1

else if ldp(tim_FLT6_タンク下限.B) then
	almFLT6_タンク下限=ON
	洗浄タンクErrStep=1

else if ldp(tim_FLT7_タンク上限.B) then
	洗浄タンクErrStep=1


end if

end if

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 洗浄タンクAutoMode	自動モード セレクトスイッチ
'System :: 洗浄タンクAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 洗浄タンクEmg	その場停止

'------------------------------------------------------------------------------------------
'ヒステリシスタイマー
'------------------------------------------------------------------------------------------
tmr(tim_notFLT1_タンク上限,#100) '上限ヒステリシスタイマー
tmr(tim_notFLT3_タンク上限,#100) '上限ヒステリシスタイマー
tmr(tim_notFLT5_タンク上限,#100) '上限ヒステリシスタイマー
tmr(tim_notFLT7_タンク上限,#100) '上限ヒステリシスタイマー
'------------------------------------------------------------------------------------------
'温度調節器制御
'
' 83℃で共振する。（推定要因：バルブの熱による共振）
'------------------------------------------------------------------------------------------
	'-- タンク1
	if ANDA(getEDC1_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8 then
		RLY_H1_タンク温調器入力=ON
	else
		RLY_H1_タンク温調器入力=OFF
	end if	
	if mMC_HT1_タンクヒータ and 0 then
		if ANDA(getEDC1_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8  and not(温度調節器1Alm) then
			pauseMC_HT1_タンクヒータ=OFF '一時停止解除
		else
			pauseMC_HT1_タンクヒータ=ON '一時停止	
		end if
	else
		pauseMC_HT1_タンクヒータ=OFF '一時停止解除
	end if

	'-- タンク2
	if ANDA(getEDC2_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8 then
		RLY_H2_タンク温調器入力=ON
	else
		RLY_H2_タンク温調器入力=OFF
	end if	
	if mMC_HT2_タンクヒータ  and 0 then
		if  ANDA(getEDC2_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8 and not(温度調節器2Alm) then
			pauseMC_HT2_タンクヒータ=OFF
		else
			pauseMC_HT2_タンクヒータ=ON
		end if
	else
		pauseMC_HT2_タンクヒータ=OFF
	end if
	
	'-- タンク3
	if ANDA(getEDC3_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8 then
		RLY_H3_タンク温調器入力=ON
	else
		RLY_H3_タンク温調器入力=OFF
	end if	
	if mMC_HT3_タンクヒータ  and 0 then
		if  ANDA(getEDC3_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8  and not(温度調節器3Alm) then
			pauseMC_HT3_タンクヒータ=OFF
		else
			pauseMC_HT3_タンクヒータ=ON
		end if
	else
		pauseMC_HT3_タンクヒータ=OFF
	end if
	
	'-- タンク4
	if ANDA(getEDC4_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8 then
		RLY_H4_タンク温調器入力=ON
	else
		RLY_H4_タンク温調器入力=OFF
	end if	
	if mMC_HT4_タンクヒータ  and 0 then
		if ANDA(getEDC4_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8  and not(温度調節器4Alm) then
			pauseMC_HT4_タンクヒータ=OFF
		else
			pauseMC_HT4_タンクヒータ=ON
		end if
	else
		pauseMC_HT4_タンクヒータ=OFF	
	end if

'------------------------------------------------------------------------------------------
if not(PB45_全停止SW) and not(自動搬送AutoMode) then
		洗浄タンクAutoRun=OFF
end if

if ldp(PB36_給水SW) then
	if 洗浄タンクAutoRun and not(自動搬送AutoRun) and not(テスト運転) then
		洗浄タンクAutoRun=OFF
	else 
		洗浄タンクAutoRun=ON
	end if
end if

PBL36_給水=洗浄タンクAutoRun
PBL42_ヒータ=洗浄タンクAutoRun

'------------------------------------------------------------------------------------------

if 洗浄タンクEmgStep=0 then  
	
	if 洗浄タンクErrStep=0 then

	if 洗浄タンクAutoRun then

	'===================================================================================================================
	'【 プロセス処理 】
	'
		if 洗浄タンクAutoRun  then
			手動初期起動=OFF


			'-----------------------
			'	1：給湯  , 蒸気
			'-----------------------			
			if timFLT2_タンク下限.B  then
				mMC_HT1_タンクヒータ=ON
			else
				mMC_HT1_タンクヒータ=OFF
			end if
		
			
			if not(timFLT1_タンク上限.B) and not(timFLT2_タンク下限.B) then
				mSV69_給湯電磁弁=ON	
			else if not(timFLT1_タンク上限.B) and tim_notFLT1_タンク上限.B and timFLT2_タンク下限.B  then
				mSV69_給湯電磁弁=ON	
			else if timFLT1_タンク上限.B and timFLT2_タンク下限.B then
				mSV69_給湯電磁弁=OFF
				res(tim_notFLT1_タンク上限)
			end if
			
			'-----------------------
			'	2：給湯  , 蒸気
			'-----------------------
			if timFLT4_タンク下限.B  then
				mMC_HT2_タンクヒータ=ON
			else
				mMC_HT2_タンクヒータ=OFF
			end if
		
			if not(timFLT3_タンク上限.B) and not(timFLT4_タンク下限.B) then
				mSV75_給湯電磁弁=ON	
			else if not(timFLT3_タンク上限.B) and tim_notFLT3_タンク上限.B and timFLT4_タンク下限.B then
				mSV75_給湯電磁弁=ON	
			else if timFLT3_タンク上限.B and timFLT4_タンク下限.B then
				mSV75_給湯電磁弁=OFF
				res(tim_notFLT3_タンク上限)
			end if
			'-----------------------
			'	3：給湯  , 蒸気
			'-----------------------
			if timFLT6_タンク下限.B then
				mMC_HT3_タンクヒータ=ON
			else 
				mMC_HT3_タンクヒータ=OFF
			end if

			if not(timFLT5_タンク上限.B) and not(timFLT6_タンク下限.B) then
				mSV81_給湯電磁弁=ON	
			else if not(timFLT5_タンク上限.B) and tim_notFLT5_タンク上限.B and timFLT6_タンク下限.B then
				mSV81_給湯電磁弁=ON	
			else if timFLT5_タンク上限.B and timFLT6_タンク下限.B then
				mSV81_給湯電磁弁=OFF
				res(tim_notFLT5_タンク上限)
			end if
			'-----------------------
			'	  4：給湯  , 蒸気
			'-----------------------
			if timFLT8_タンク下限.B then
				mMC_HT4_タンクヒータ=ON
			else
				mMC_HT4_タンクヒータ=OFF
			end if
			
			if not(timFLT7_タンク上限.B) and not(timFLT8_タンク下限.B) then
				mSV87_給湯電磁弁=ON	
			else if not(timFLT7_タンク上限.B) and tim_notFLT7_タンク上限.B and timFLT8_タンク下限.B then
				mSV87_給湯電磁弁=ON	
			else if timFLT7_タンク上限.B and timFLT8_タンク下限.B then
				mSV87_給湯電磁弁=OFF
				res(tim_notFLT7_タンク上限)
			end if

		else
			mMC_HT1_タンクヒータ=OFF
			mSV69_給湯電磁弁=OFF
			
			mMC_HT2_タンクヒータ=OFF
			mSV75_給湯電磁弁=OFF
			
			mMC_HT3_タンクヒータ=OFF
			mSV81_給湯電磁弁=OFF
			
			mMC_HT4_タンクヒータ=OFF
			mSV87_給湯電磁弁=OFF
			
		end if
			

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		'給湯、給水は自動、手動関係なくマニュアル操作可能なこと
		'AutoモードOFFでのマニュアル動作部分はない
		
		if not(手動初期起動) then
			手動初期起動=ON

			mMC_HT1_タンクヒータ=OFF
			mSV69_給湯電磁弁=OFF
			
			mMC_HT2_タンクヒータ=OFF
			mSV75_給湯電磁弁=OFF
			
			mMC_HT3_タンクヒータ=OFF
			mSV81_給湯電磁弁=OFF
			
			mMC_HT4_タンクヒータ=OFF
			mSV87_給湯電磁弁=OFF

			tmp_給湯電磁弁=OFF
			tmp1SV69_給湯電磁弁=OFF
			tmp2SV69_給湯電磁弁=OFF
			tmp1SV75_給湯電磁弁=OFF
			tmp2SV75_給湯電磁弁=OFF
			tmp1SV81_給湯電磁弁=OFF
			tmp2SV81_給湯電磁弁=OFF
			tmp1SV87_給湯電磁弁=OFF
			tmp2SV87_給湯電磁弁=OFF
			tmp_タンクヒータ=OFF
			tmp1MC_HT1_タンクヒータ=OFF
			tmp2MC_HT1_タンクヒータ=OFF
			tmp1MC_HT2_タンクヒータ=OFF
			tmp2MC_HT2_タンクヒータ=OFF
			tmp1MC_HT3_タンクヒータ=OFF
			tmp2MC_HT3_タンクヒータ=OFF
			tmp1MC_HT4_タンクヒータ=OFF
			tmp2MC_HT4_タンクヒータ=OFF	
		end if

		mSV69_給湯電磁弁=tmp1SV69_給湯電磁弁 or tmp2SV69_給湯電磁弁
		mSV75_給湯電磁弁=tmp1SV75_給湯電磁弁 or tmp2SV75_給湯電磁弁
		mSV81_給湯電磁弁=tmp1SV81_給湯電磁弁 or tmp2SV81_給湯電磁弁
		mSV87_給湯電磁弁=tmp1SV87_給湯電磁弁 or tmp2SV87_給湯電磁弁

		mMC_HT1_タンクヒータ=(tmp1MC_HT1_タンクヒータ or tmp2MC_HT1_タンクヒータ) and FLT2_タンク下限
		mMC_HT2_タンクヒータ=(tmp1MC_HT2_タンクヒータ or tmp2MC_HT2_タンクヒータ) and FLT4_タンク下限
		mMC_HT3_タンクヒータ=(tmp1MC_HT3_タンクヒータ or tmp2MC_HT3_タンクヒータ) and FLT6_タンク下限
		mMC_HT4_タンクヒータ=(tmp1MC_HT4_タンクヒータ or tmp2MC_HT4_タンクヒータ) and FLT8_タンク下限

		if PB45_全停止SW then 'B接点
			'----------------
			'コマンドSW操作
			'----------------
			if SEL2_1_運転切換（単動） then 'B接点
				tmp2SV69_給湯電磁弁=OFF
				tmp2SV75_給湯電磁弁=OFF
				tmp2SV81_給湯電磁弁=OFF
				tmp2SV87_給湯電磁弁=OFF

				tmp2MC_HT1_タンクヒータ=OFF
				tmp2MC_HT2_タンクヒータ=OFF
				tmp2MC_HT3_タンクヒータ=OFF
				tmp2MC_HT4_タンクヒータ=OFF
			'--------------------------------------------------------------
			'	if ldp(PB36_給水SW) then
			'		if tmp_給湯電磁弁 then
			'			tmp_給湯電磁弁=OFF
			'		else
			'			tmp_給湯電磁弁=ON
			'		end if
			'	end if
			'	
			'	tmp1SV69_給湯電磁弁=tmp_給湯電磁弁
			'	tmp1SV75_給湯電磁弁=tmp_給湯電磁弁
			'	tmp1SV81_給湯電磁弁=tmp_給湯電磁弁
			'	tmp1SV87_給湯電磁弁=tmp_給湯電磁弁
			'--------------------------------------------------------------
			'	if ldp(PB42_ヒータSW) then 
			'		if tmp_タンクヒータ then
			'			tmp_タンクヒータ=OFF
			'		else
			'			tmp_タンクヒータ=ON
			'		end if
			'	end if
			'		
			'	if tmp_タンクヒータ and FLT2_タンク下限 then
			'		tmp1MC_HT1_タンクヒータ=ON
			'	else
			'		tmp1MC_HT1_タンクヒータ=OFF
			'	end if
			'	'----------------
			'	if tmp_タンクヒータ and FLT4_タンク下限 then
			'		tmp1MC_HT2_タンクヒータ=ON
			'	else
			'		tmp1MC_HT2_タンクヒータ=OFF
			'	end if
			'	'----------------
			'	if tmp_タンクヒータ and FLT6_タンク下限 then
			'		tmp1MC_HT3_タンクヒータ=ON
			'	else
			'		tmp1MC_HT3_タンクヒータ=OFF
			'	end if
			'	'----------------			
			'	if tmp_タンクヒータ and FLT8_タンク下限 then
			'		tmp1MC_HT4_タンクヒータ=ON
			'	else
			'		tmp1MC_HT4_タンクヒータ=OFF
			'	end if
				'----------------

			else
				tmp_給湯電磁弁=OFF
				tmp1SV69_給湯電磁弁=OFF
				tmp1SV75_給湯電磁弁=OFF
				tmp1SV81_給湯電磁弁=OFF
				tmp1SV87_給湯電磁弁=OFF
				tmp_タンクヒータ=OFF
				tmp1MC_HT1_タンクヒータ=OFF
				tmp1MC_HT2_タンクヒータ=OFF
				tmp1MC_HT3_タンクヒータ=OFF
				tmp1MC_HT4_タンクヒータ=OFF
				
				'----------------			
				' パネル操作	
				'----------------			
				if ldp(pnlPBSV69_給湯電磁弁) then
					if tmp2SV69_給湯電磁弁 then
						tmp2SV69_給湯電磁弁=OFF
					else
						tmp2SV69_給湯電磁弁=ON
					end if
				end if
				'----------------						
				if ldp(pnlPBSV75_給湯電磁弁) then
					if tmp2SV75_給湯電磁弁 then
						tmp2SV75_給湯電磁弁=OFF
					else
						tmp2SV75_給湯電磁弁=ON
					end if
				end if
				'----------------
				if ldp(pnlPBSV81_給湯電磁弁) then
					if tmp2SV81_給湯電磁弁 then
						tmp2SV81_給湯電磁弁=OFF
					else
						tmp2SV81_給湯電磁弁=ON
					end if
				end if
				'----------------
				if ldp(pnlPBSV87_給湯電磁弁) then
					if tmp2SV87_給湯電磁弁 then
						tmp2SV87_給湯電磁弁=OFF
					else
						tmp2SV87_給湯電磁弁=ON
					end if
				end if
				'--------------------------------------------------------------
				if ldp(pnlPBMC_HT1_タンクヒータ) then
					if tmp2MC_HT1_タンクヒータ then
						tmp2MC_HT1_タンクヒータ=OFF
					else if FLT2_タンク下限 then
						tmp2MC_HT1_タンクヒータ=ON
					end if
				end if
				'----------------
					if ldp(pnlPBMC_HT2_タンクヒータ) then
					if tmp2MC_HT2_タンクヒータ then
						tmp2MC_HT2_タンクヒータ=OFF
					else if FLT4_タンク下限 then
						tmp2MC_HT2_タンクヒータ=ON
					end if
				end if
				'----------------
				if ldp(pnlPBMC_HT3_タンクヒータ) then
					if tmp2MC_HT3_タンクヒータ then
						tmp2MC_HT3_タンクヒータ=OFF
					else if FLT6_タンク下限 then
						tmp2MC_HT3_タンクヒータ=ON
					end if
				end if
				'----------------
				if ldp(pnlPBMC_HT4_タンクヒータ) then
					if tmp2MC_HT4_タンクヒータ then
						tmp2MC_HT4_タンクヒータ=OFF
					else if FLT8_タンク下限 then
						tmp2MC_HT4_タンクヒータ=ON
					end if
				end if
				'--------------------------------------------------------------

			end if
		else
		
			mSV69_給湯電磁弁=OFF
			mMC_HT1_タンクヒータ=OFF
	
			mSV75_給湯電磁弁=OFF
			mMC_HT2_タンクヒータ=OFF

			mSV81_給湯電磁弁=OFF
			mMC_HT3_タンクヒータ=OFF

			mSV87_給湯電磁弁=OFF
			mMC_HT4_タンクヒータ=OFF

		
			tmp_給湯電磁弁=OFF
			tmp1SV69_給湯電磁弁=OFF
			tmp2SV69_給湯電磁弁=OFF
			tmp1SV75_給湯電磁弁=OFF
			tmp2SV75_給湯電磁弁=OFF
			tmp1SV81_給湯電磁弁=OFF
			tmp2SV81_給湯電磁弁=OFF
			tmp1SV87_給湯電磁弁=OFF
			tmp2SV87_給湯電磁弁=OFF
			tmp_タンクヒータ=OFF
			tmp1MC_HT1_タンクヒータ=OFF
			tmp2MC_HT1_タンクヒータ=OFF
			tmp1MC_HT2_タンクヒータ=OFF
			tmp2MC_HT2_タンクヒータ=OFF
			tmp1MC_HT3_タンクヒータ=OFF
			tmp2MC_HT3_タンクヒータ=OFF
			tmp1MC_HT4_タンクヒータ=OFF
			tmp2MC_HT4_タンクヒータ=OFF

		end if
	end if
	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
	
		洗浄タンクErr=ON

		mMC_HT1_タンクヒータ=OFF
		mSV69_給湯電磁弁=OFF
		
		mMC_HT2_タンクヒータ=OFF
		mSV75_給湯電磁弁=OFF
		
		mMC_HT3_タンクヒータ=OFF
		mSV81_給湯電磁弁=OFF
		
		mMC_HT4_タンクヒータ=OFF
		mSV87_給湯電磁弁=OFF
		

		select case 洗浄タンクErrStep
		case 0
		case 1
			if ResetFlg then
				almFLT2_タンク下限 =OFF
				almFLT1_タンク上限=OFF
				almFLT4_タンク下限=OFF
				almFLT3_タンク上限=OFF
				almFLT6_タンク下限=OFF

				inc(洗浄タンクErrStep)
			end if
		case 2
			洗浄タンクErr=OFF
			
			res(tim_FLT2_タンク下限.B)
			res(tim_FLT1_タンク上限.B)
			res(tim_FLT4_タンク下限.B)
			res(tim_FLT3_タンク上限.B)
			res(tim_FLT6_タンク下限.B)
			res(tim_FLT7_タンク上限.B)

			洗浄タンクErrStep=0
		end select

	end if
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case 洗浄タンクEmgStep
	
	case 1
		洗浄タンクAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if 洗浄タンクAutoMode  and 自動搬送AutoMode then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			mMC_HT1_タンクヒータ=OFF
			mSV69_給湯電磁弁=OFF
			
			mMC_HT2_タンクヒータ=OFF
			mSV75_給湯電磁弁=OFF
			
			mMC_HT3_タンクヒータ=OFF
			mSV81_給湯電磁弁=OFF
			
			mMC_HT4_タンクヒータ=OFF
			mSV87_給湯電磁弁=OFF

			tmp_給湯電磁弁=OFF
			tmp1SV69_給湯電磁弁=OFF
			tmp2SV69_給湯電磁弁=OFF
			tmp1SV75_給湯電磁弁=OFF
			tmp2SV75_給湯電磁弁=OFF
			tmp1SV81_給湯電磁弁=OFF
			tmp2SV81_給湯電磁弁=OFF
			tmp1SV87_給湯電磁弁=OFF
			tmp2SV87_給湯電磁弁=OFF
			tmp_タンクヒータ=OFF
			tmp1MC_HT1_タンクヒータ=OFF
			tmp2MC_HT1_タンクヒータ=OFF
			tmp1MC_HT2_タンクヒータ=OFF
			tmp2MC_HT2_タンクヒータ=OFF
			tmp1MC_HT3_タンクヒータ=OFF
			tmp2MC_HT3_タンクヒータ=OFF
			tmp1MC_HT4_タンクヒータ=OFF
			tmp2MC_HT4_タンクヒータ=OFF	
			
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC_HT1_タンクヒータ=OFF
			mSV69_給湯電磁弁=OFF
			
			mMC_HT2_タンクヒータ=OFF
			mSV75_給湯電磁弁=OFF
			
			mMC_HT3_タンクヒータ=OFF
			mSV81_給湯電磁弁=OFF
			
			mMC_HT4_タンクヒータ=OFF
			mSV87_給湯電磁弁=OFF

			tmp_給湯電磁弁=OFF
			tmp1SV69_給湯電磁弁=OFF
			tmp2SV69_給湯電磁弁=OFF
			tmp1SV75_給湯電磁弁=OFF
			tmp2SV75_給湯電磁弁=OFF
			tmp1SV81_給湯電磁弁=OFF
			tmp2SV81_給湯電磁弁=OFF
			tmp1SV87_給湯電磁弁=OFF
			tmp2SV87_給湯電磁弁=OFF
			tmp_タンクヒータ=OFF
			tmp1MC_HT1_タンクヒータ=OFF
			tmp2MC_HT1_タンクヒータ=OFF
			tmp1MC_HT2_タンクヒータ=OFF
			tmp2MC_HT2_タンクヒータ=OFF
			tmp1MC_HT3_タンクヒータ=OFF
			tmp2MC_HT3_タンクヒータ=OFF
			tmp1MC_HT4_タンクヒータ=OFF
			tmp2MC_HT4_タンクヒータ=OFF	
			'---------------------------------
		end if
		
		'---------------------------------
		inc(洗浄タンクEmgStep)
	case 2
		if ResetFlg then
			inc(洗浄タンクEmgStep)
		end if
	case 3
		if 洗浄タンクAutoMode  and 自動搬送AutoMode then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				
				
				
				'---------------------------------
				inc(洗浄タンクEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(洗浄タンクEmgStep)		
		end if				
	case 4
		洗浄タンクEmgStep=0
		洗浄タンクEmg=OFF
	end select
		
end if 'if 洗浄タンクEmgStep=0 then
