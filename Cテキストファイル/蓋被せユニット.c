'蓋被せユニット
'===================================================================================================================
'
'<<<<<<<	ユニット	>>>>>>>>
'
'===================================================================================================================
'
'	蓋被せユニット
'
'
'	フタ被せ時のエラー回避
'	フタ被せ位置修正エラー発生  -> リトライ  ->   → フタ被せエラー発生
'                    (reset sw) 
'                    *フタ修正
'
'SV32_クランプ ->SV26_クランプ
'XSW36_クランプ上昇端 -> XSW31_クランプ上昇端
'XSW35_クランプ下降端 -> XSW30_クランプ下降端
'
'SV30_ストッパ -> SV27_ストッパ
'XSW32_ストッパ上昇端 -> XSW33_ストッパ上昇端
'XSW31_ストッパ下降端 -> XSW32_ストッパ下降端
'===================================================================================================================

'【 初期化処理 】
if CR2008 then
    蓋被せユニットAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    蓋被せユニットAutoRun=OFF
    蓋被せユニット許可=ON
    蓋被せユニットOrgErr=OFF
    蓋被せユニットErr=OFF
    蓋被せユニットEmg=OFF
    蓋被せユニットstep=0
    蓋被せユニットErrStep=0
    蓋被せユニットOrgErrStep=0
    蓋被せユニットEmgStep=0

end if
'===================================================================================================================
'【 原点 】
蓋被せユニットOrg=not(蓋被せユニット許可) or (XSW39_シリンダ上昇端A and XSW41_シリンダ上昇端B)

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	蓋被せユニットEmg=ON
	蓋被せユニットEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
tmr(SV34_シリンダ上昇A and not(XSW39_シリンダ上昇端A) and not(pnlPBXSW39_シリンダ上昇端A),tim_XSW39_シリンダ上昇端A,#50)
tmr(SV35_シリンダ下降A and not(XSW40_シリンダ下降端A) and not(pnlPBXSW40_シリンダ下降端A),tim_XSW40_シリンダ下降端A,#50)
tmr(SV36_シリンダ上昇B and not(XSW41_シリンダ上昇端B) and not(pnlPBXSW41_シリンダ上昇端B),tim_XSW41_シリンダ上昇端B,#50)
tmr(SV37_シリンダ下降B and not(XSW42_シリンダ下降端B) and not(pnlPBXSW42_シリンダ下降端B),tim_XSW42_シリンダ下降端B,#50)
tmr(SV38_クランプ and not(XSW43_クランプ) and not(pnlPBXSW43_クランプ),tim_XSW43_クランプ,#40)
tmr(SV39_アンクランプ and not(XSW44_アンクランプ) and not(pnlPBXSW44_アンクランプ),tim_XSW44_アンクランプ,#40)


if ldp(tim_XSW39_シリンダ上昇端A.B) then
	errpassXSW39_シリンダ上昇端A=ON
	almXSW39_シリンダ上昇端A=ON
	蓋被せユニットErrStep=1

else if ldp(tim_XSW40_シリンダ下降端A.B) then
	if フタ被せフタ取り中 then
		errXSW40_シリンダ下降端A=ON 'フタ被せエラー通知
		errpassXSW40_シリンダ下降端A=ON 'フタ被せエラー工程pass
		almXSW40_シリンダ下降端A=ON
		蓋被せユニットErrStep=1
	else
		errpassXSW40_シリンダ下降端A=ON 'フタ被せエラー工程pass
		almXSW40_シリンダ下降端A=ON
		蓋被せユニットErrStep=1
	end if
	

else if ldp(tim_XSW41_シリンダ上昇端B.B) then
	errpassXSW41_シリンダ上昇端B=ON
	almXSW41_シリンダ上昇端B=ON
	蓋被せユニットErrStep=1
	
else if ldp(tim_XSW42_シリンダ下降端B.B) then
	errpassXSW42_シリンダ下降端B=ON
	almXSW42_シリンダ下降端B=On
	蓋被せユニットErrStep=1
	
else if ldp(tim_XSW43_クランプ.B) then
	errpassXSW43_クランプ=ON
	almXSW43_クランプ=ON
	蓋被せユニットErrStep=1

else if ldp(tim_XSW44_アンクランプ.B) then
	errpassXSW44_アンクランプ=ON
	almXSW44_アンクランプ=ON
	蓋被せユニットErrStep=1

end if

if 0 then
tmr(not(SV26_クランプ) and not(XSW30_クランプ下降端) and not(pnlPBXSW30_クランプ下降端), tim_XSW30_クランプ下降端, #30)
tmr(SV26_クランプ and not(XSW31_クランプ上昇端) and not(pnlPBXSW31_クランプ上昇端), tim_XSW31_クランプ上昇端,#30)
tmr(not(SV27_ストッパ) and not(XSW32_ストッパ下降端) and not(pnlPBXSW32_ストッパ下降端),tim_XSW32_ストッパ下降端,#30)
tmr(SV27_ストッパ and not(XSW33_ストッパ上昇端) and not(pnlPBXSW33_ストッパ上昇端),tim_XSW33_ストッパ上昇端,#30)

if ldp(tim_XSW30_クランプ下降端.B) then
	errpassXSW30_クランプ下降端=ON
	almXSW30_クランプ下降端=ON
	搬送コンベアCErrStep=1

else if ldp(tim_XSW31_クランプ上昇端.B) then
	errpassXSW31_クランプ上昇端=ON
	pauseSV26_クランプ=ON
	almXSW31_クランプ上昇端=ON
	蓋被せユニットErrStep=1

else if ldp(tim_XSW32_ストッパ下降端.B) then
	errpassXSW32_ストッパ下降端=ON
	almXSW32_ストッパ下降端=ON
	蓋被せユニットErrStep=1

else if ldp(tim_XSW33_ストッパ上昇端.B) then
	errpassXSW33_ストッパ上昇端=ON
	pauseSV27_ストッパ=ON
	almXSW33_ストッパ上昇端=ON
	蓋被せユニットErrStep=1
end if

end if
'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 蓋被せユニットAutoMode	自動モード セレクトスイッチ
'System :: 蓋被せユニットAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能
'System :: 蓋被せユニットEmg	その場停止

if 蓋被せユニットEmgStep=0 then  
	
	if 蓋被せユニットErrStep=0  or errXSW40_シリンダ下降端A then
	
	if not(蓋被せユニットOrgErr) then

	if (蓋被せユニットAutoMode and 自動搬送AutoMode ) or 蓋被せユニットstep<>0 then
		
		if not(蓋被せユニットAutoMode and 自動搬送AutoMode ) then
			蓋被せユニットAutoRun=OFF
		end if
		

	'===================================================================================================================
	'【 プロセス処理 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case 蓋被せユニットstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
			蓋被せユニットStatusMsg=#0

		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' 作業工程を振り分ける
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 蓋被せユニットAutoRun then
				if XSW39_シリンダ上昇端A and XSW41_シリンダ上昇端B and XSW43_クランプ then
					フタ被せフタ取り中=ON
				else				
					フタ被せフタ取り中=OFF
				end if
			
				inc(蓋被せユニットstep)
			else 
				蓋被せユニットstep=0 '終了待機
			end if

		case 2
		' [ 蓋カマ移動停止確認 ]
			if 蓋被せユニット排出要求=OFF and  搬送コンベアC動作中=OFF then

				'[ 自ステージに"釜"有検出 ]
					if PH19_釜検知 and PH20_フタ検知 then
						蓋被せユニットStatusMsg=#42	'	フタ置き中
						inc(蓋被せユニットstep) 'フタ被せ
						
				'[ 自ステージに"フタ"有検出 ]	
					else if not(PH19_釜検知) and PH20_フタ検知 then 
							蓋被せユニットStatusMsg=#40	'	フタ取り中
							inc(蓋被せユニットstep) 'フタ取り
				
				'[ 自ステージに"釜フタ"なし ]
						else
							蓋被せユニット排出要求=ON
							蓋被せユニットstep=1  '終了
					end if
			
			else
			
				蓋被せユニットstep=1
			
			end if
		
		case 3
		' [ ユニット許可検出 ]
			if 蓋被せユニット許可 then
				inc(蓋被せユニットstep)
			else
				蓋被せユニット排出要求=ON
				蓋被せユニットstep=1
			end if
		
		case 4
			if XSW39_シリンダ上昇端A and XSW41_シリンダ上昇端B then '原点
				蓋被せユニットstep=100 'プロセス処理
			else
				蓋被せユニットstep=1
			end if
			
		'--------------------------------------------------------------------------------------------------------------
		'プロセス処理
		case 100
			if フタ被せ完了 then '搬送移動でOFF
				蓋被せユニット排出要求=ON
				蓋被せユニットstep=1
			else
				if フタ被せフタ取り中 and  PH19_釜検知 and PH20_フタ検知 then
					inc(蓋被せユニットstep) 'フタ被せ処理
				else if not(フタ被せフタ取り中) and  not(PH19_釜検知) and PH20_フタ検知 then
					蓋被せユニットstep=150 'フタ取り処理
				else
					蓋被せユニット排出要求=ON
					蓋被せユニットstep=1
				end if
			end if

		'------------------------------------------------------
		case 101  'フタ被せ (アンクランプ）
			mSV34_シリンダ上昇A=OFF
			mSV35_シリンダ下降A=OFF
			mSV36_シリンダ上昇B=OFF
			mSV37_シリンダ下降B=OFF
			mSV38_クランプ=OFF
			mSV39_アンクランプ=OFF

			
			inc(蓋被せユニットstep)

		'------------------------------------------------------
		case 102
			mSV35_シリンダ下降A=ON
			errpassXSW40_シリンダ下降端A=OFF
			inc(蓋被せユニットstep)

		case 103
			if errpassXSW40_シリンダ下降端A or  XSW40_シリンダ下降端A then
				inc(蓋被せユニットstep)
			end if
		
		case 104
			mSV35_シリンダ下降A=OFF
			tim_procstep_val=5
			res(tim_procstep)
			inc(蓋被せユニットstep)
		
		case 105
			if tim_procstep.B then
				inc(蓋被せユニットstep)
			end if
		
		case 106
			'-- errpassXSW40_シリンダ下降端A  の場合はクランプを外さない --
			if not(errXSW40_シリンダ下降端A) then
				mSV39_アンクランプ=ON	
				errpassXSW44_アンクランプ=OFF
				inc(蓋被せユニットstep)
			else
				inc(蓋被せユニットstep)
			end if				
		
		case 107
			if not(errXSW40_シリンダ下降端A) then		
				if errpassXSW44_アンクランプ or XSW44_アンクランプ then
					inc(蓋被せユニットstep)
				end if
			else
				inc(蓋被せユニットstep)		
			end if
		
		case 108
			mSV39_アンクランプ=OFF
			tim_procstep_val=0 'アンクランプ待機時間
			res(tim_procstep)
			inc(蓋被せユニットstep)
		
		case 109
			if tim_procstep.B then
				inc(蓋被せユニットstep)
			end if
		
		case 110
			mSV34_シリンダ上昇A=ON
			errpassXSW39_シリンダ上昇端A=OFF
			inc(蓋被せユニットstep)

		case 111
			if errpassXSW39_シリンダ上昇端A or XSW39_シリンダ上昇端A then
				inc(蓋被せユニットstep)
			end if
		
		case 112
			mSV34_シリンダ上昇A=OFF
			tim_procstep_val=0
			res(tim_procstep)
			inc(蓋被せユニットstep)
			
		
		case 113
			if tim_procstep.B then
				if not(errXSW40_シリンダ下降端A) then					
					フタ被せフタ取り中=OFF
				end if
				inc(蓋被せユニットstep)
			end if
		
		case 114
			if errXSW40_シリンダ下降端A then
				errXSW40_シリンダ下降端A=OFF
			else
				RetryMode=OFF
				フタ被せ完了=ON
				蓋被せユニット排出要求=ON
			end if
			蓋被せユニットstep=1
		'------------------------------------------------------
		case 150 'フタ取り  （クランプ）
			mSV34_シリンダ上昇A=OFF
			mSV35_シリンダ下降A=OFF
			mSV36_シリンダ上昇B=OFF
			mSV37_シリンダ下降B=OFF
			mSV38_クランプ=OFF
			mSV39_アンクランプ=OFF
			inc(蓋被せユニットstep)

		case 151
			mSV39_アンクランプ=ON	
			errpassXSW44_アンクランプ=OFF
			inc(蓋被せユニットstep)

		case 152
			if errpassXSW44_アンクランプ or XSW44_アンクランプ then
				inc(蓋被せユニットstep)
			end if
		
		case 153
			mSV39_アンクランプ=OFF
			tim_procstep_val=0 'アンクランプ待機時間
			res(tim_procstep)
			inc(蓋被せユニットstep)


		case 154
			if tim_procstep.B then
				if XSW39_シリンダ上昇端A and XSW41_シリンダ上昇端B then '原点
					if XSW44_アンクランプ then
						inc(蓋被せユニットstep)
					else
						蓋被せユニットOrgErr=ON
					end if
				else
					蓋被せユニットOrgErr=ON
				end if
			end if


		case 155
			mSV35_シリンダ下降A=ON
			mSV37_シリンダ下降B=ON
			errpassXSW40_シリンダ下降端A=OFF
			inc(蓋被せユニットstep)

		case 156
			if errpassXSW40_シリンダ下降端A or XSW40_シリンダ下降端A then
				mSV35_シリンダ下降A=OFF
				inc(蓋被せユニットstep)
			end if		
		
		case 157
			if XSW42_シリンダ下降端B then
				mSV37_シリンダ下降B=OFF
				inc(蓋被せユニットstep)
			end if

		case 158
			tim_procstep_val=2
			res(tim_procstep)
			inc(蓋被せユニットstep)		

		case 159
			if tim_procstep.B then
				inc(蓋被せユニットstep)
			end if
		
		case 160
			mSV38_クランプ=ON
			errpassXSW43_クランプ=OFF
			inc(蓋被せユニットstep)
		
		case 161
			if errpassXSW43_クランプ or XSW43_クランプ then
				inc(蓋被せユニットstep)
			end if
		
		case 162
			mSV38_クランプ=OFF
			inc(蓋被せユニットstep)

		case 163
			tim_procstep_val=0
			res(tim_procstep)
			inc(蓋被せユニットstep)				

		case 164
			if tim_procstep.B then
				inc(蓋被せユニットstep)
			end if

		case 165
			mSV27_ストッパ=OFF
			errpassXSW32_ストッパ下降端=OFF
			mSV26_クランプ=OFF
			errpassXSW30_クランプ下降端=OFF
			inc(蓋被せユニットstep)
		
		case 166
			if (errpassXSW32_ストッパ下降端 or ((XSW32_ストッパ下降端 and not(pnlPBXSW32_ストッパ下降端)) or passXSW32_ストッパ下降端)) and (errpassXSW30_クランプ下降端 or ((XSW30_クランプ下降端 and not(pnlPBXSW30_クランプ下降端)) or passXSW30_クランプ下降端)) then
				inc(蓋被せユニットstep)
			end if

		
		case 167
			mSV36_シリンダ上昇B=ON
			mSV34_シリンダ上昇A=ON
			errpassXSW41_シリンダ上昇端B=OFF
			errpassXSW39_シリンダ上昇端A=OFF
			inc(蓋被せユニットstep)

		case 168
			if errpassXSW41_シリンダ上昇端B or XSW41_シリンダ上昇端B then
				mSV36_シリンダ上昇B=OFF
				inc(蓋被せユニットstep)
			end if
		
		case 169
			if errpassXSW39_シリンダ上昇端A or XSW39_シリンダ上昇端A then
				mSV34_シリンダ上昇A=OFF
				inc(蓋被せユニットstep)
			end if

		case 170
			
			tim_procstep_val=0
			res(tim_procstep)
			inc(蓋被せユニットstep)

		case 171
			if tim_procstep.B then
				フタ被せフタ取り中=ON
				inc(蓋被せユニットstep)
			end if

		case 172
			if errpassXSW40_シリンダ下降端A then
				errpassXSW40_シリンダ下降端A=OFF
			end if
			
			フタ被せ完了=ON
			蓋被せユニット排出要求=ON
			蓋被せユニットstep=1
		end select

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		蓋被せユニットAutoRun=OFF
		
		蓋被せユニットstep=0 '終了
		フタ被せ完了=OFF
		

		res(tim_XSW39_シリンダ上昇端A)
		res(tim_XSW40_シリンダ下降端A)
		res(tim_XSW41_シリンダ上昇端B)
		res(tim_XSW42_シリンダ下降端B)
		res(tim_XSW43_クランプ)
		res(tim_XSW44_アンクランプ)

		'------------------------------------------------------
		if ldp(pnlPBSV34_シリンダ上昇A or pnlPBSV35_シリンダ下降A) and (XSW44_アンクランプ or (XSW43_クランプ and ((XSW32_ストッパ下降端 and not(pnlPBXSW32_ストッパ下降端)) or passXSW32_ストッパ下降端 ) and  ((XSW30_クランプ下降端 and not(pnlPBXSW30_クランプ下降端)) or passXSW30_クランプ下降端)) ) then
			if XSW39_シリンダ上昇端A then
				mSV35_シリンダ下降A=ON
				mSV34_シリンダ上昇A=OFF
			else if XSW40_シリンダ下降端A then
				mSV35_シリンダ下降A=OFF
				mSV34_シリンダ上昇A=ON
			else
				mSV35_シリンダ下降A=OFF
				mSV34_シリンダ上昇A=ON			
			end if
		end if
		if mSV35_シリンダ下降A and XSW40_シリンダ下降端A then
			mSV35_シリンダ下降A=OFF
		end if
		if mSV34_シリンダ上昇A and XSW39_シリンダ上昇端A then
			mSV34_シリンダ上昇A=OFF
		end if
		'------------------------------------------------------
		if ldp(pnlPBSV36_シリンダ上昇B or pnlPBSV37_シリンダ下降B) and (XSW44_アンクランプ or (XSW43_クランプ and ((XSW32_ストッパ下降端 and not(pnlPBXSW32_ストッパ下降端)) or passXSW32_ストッパ下降端 ) and  ((XSW30_クランプ下降端 and not(pnlPBXSW30_クランプ下降端)) or passXSW30_クランプ下降端)) ) then
			if XSW41_シリンダ上昇端B then
				mSV37_シリンダ下降B=ON
				mSV36_シリンダ上昇B=OFF
			else if XSW42_シリンダ下降端B then
				mSV37_シリンダ下降B=OFF
				mSV36_シリンダ上昇B=ON
			else
				mSV37_シリンダ下降B=OFF
				mSV36_シリンダ上昇B=ON			
			end if
		end if
		if mSV37_シリンダ下降B and XSW42_シリンダ下降端B then
			mSV37_シリンダ下降B=OFF
		end if
		if mSV36_シリンダ上昇B and XSW41_シリンダ上昇端B then
			mSV36_シリンダ上昇B=OFF
		end if
		'------------------------------------------------------
		if ldp(pnlPBSV38_クランプ or pnlPBSV39_アンクランプ) then
			if XSW44_アンクランプ then
				mSV38_クランプ=ON
				mSV39_アンクランプ=OFF
				
				フタ被せフタ取り中=ON

			else if XSW43_クランプ then
				mSV38_クランプ=OFF
				mSV39_アンクランプ=ON
				
				フタ被せフタ取り中=OFF
			else
				mSV38_クランプ=OFF
				mSV39_アンクランプ=ON
				
				フタ被せフタ取り中=OFF			
			
			end if
		end if
		if mSV39_アンクランプ and XSW44_アンクランプ then
			mSV39_アンクランプ=OFF
		end if
		if mSV38_クランプ and XSW43_クランプ then
			mSV38_クランプ=OFF
		end if
		'------------------------------------------------------

	end if '蓋被せユニットAutoMode
	'===================================================================================================================
	'【 蓋被せユニットOrgErr処理 】
	else
	
		res(tim_XSW39_シリンダ上昇端A)
		res(tim_XSW40_シリンダ下降端A)
		res(tim_XSW41_シリンダ上昇端B)
		res(tim_XSW42_シリンダ下降端B)
		res(tim_XSW43_クランプ)
		res(tim_XSW44_アンクランプ)
		
		if ResetFlg then
			蓋被せユニットOrgErr=OFF
		end if

	end if	
	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
		'res(tim_XSW30_クランプ下降端)
		'res(tim_XSW32_ストッパ下降端)
		res(tim_XSW39_シリンダ上昇端A)
		res(tim_XSW40_シリンダ下降端A)
		res(tim_XSW41_シリンダ上昇端B)
		res(tim_XSW42_シリンダ下降端B)
		res(tim_XSW43_クランプ)
		res(tim_XSW44_アンクランプ)


		if フタ被せフタ取り中 then

			select case 蓋被せユニットErrStep
			case 0
			'------------------------------------------------------------------
			case 1
				if ResetFlg then
					'almXSW30_クランプ下降端=OFF
					'almXSW32_ストッパ下降端=OFF

					almXSW39_シリンダ上昇端A=OFF
					almXSW40_シリンダ下降端A=OFF
					almXSW41_シリンダ上昇端B=OFF
					almXSW42_シリンダ下降端B=OFF
					almXSW43_クランプ=OFF
					almXSW44_アンクランプ=OFF
					
					almXSW30_クランプ下降端=OFF
					almXSW31_クランプ上昇端=OFF
					almXSW32_ストッパ下降端=OFF
					almXSW33_ストッパ上昇端=OFF


					pauseSV26_クランプ=OFF
					pauseSV27_ストッパ=OFF

					inc(蓋被せユニットErrStep)
				end if
			case 2
				if RetryMode then
					RetryMode=OFF
					inc(蓋被せユニットErrStep)
				else
					RetryMode=ON
					inc(蓋被せユニットErrStep)
				end if

			case 3
				if RetryMode and 蓋被せユニットstep<100 then '蓋被せユニットstepが 0または1でプロセスが終了していること
					蓋被せユニットstep=101
				end if
				inc(蓋被せユニットErrStep)
			'------------------------------------------------------------------
			case 4
				蓋被せユニットErr=OFF
				蓋被せユニットErrStep=0
			
			end select
		
		else
			蓋被せユニットErr=ON

			select case 蓋被せユニットErrStep
			case 0
			case 1
				if ResetFlg then
					
					'almXSW30_クランプ下降端=OFF
					'almXSW32_ストッパ下降端=OFF
					
					almXSW39_シリンダ上昇端A=OFF
					almXSW40_シリンダ下降端A=OFF
					almXSW41_シリンダ上昇端B=OFF
					almXSW42_シリンダ下降端B=OFF
					almXSW43_クランプ=OFF
					almXSW44_アンクランプ=OFF

					almXSW30_クランプ下降端=OFF
					almXSW31_クランプ上昇端=OFF
					almXSW32_ストッパ下降端=OFF
					almXSW33_ストッパ上昇端=OFF

					
					inc(蓋被せユニットErrStep)
				end if
			case 2
				蓋被せユニットErr=OFF
				蓋被せユニットErrStep=0
			end select
		
		end if

	end if 'if 蓋被せユニットErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case 蓋被せユニットEmgStep
	case 0
	
	case 1
		蓋被せユニットAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (蓋被せユニットAutoMode and 自動搬送AutoMode ) or 蓋被せユニットstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mSV35_シリンダ下降A=OFF
			mSV34_シリンダ上昇A=OFF
			mSV37_シリンダ下降B=OFF
			mSV36_シリンダ上昇B=OFF
			mSV38_クランプ=OFF
			mSV39_アンクランプ=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(蓋被せユニットEmgStep)
	case 2
		if ResetFlg then
			inc(蓋被せユニットEmgStep)
		end if
	case 3
		if (蓋被せユニットAutoMode and 自動搬送AutoMode ) or 蓋被せユニットstep<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				tim_procstep.U=tim_procstep_stack
				
				'---------------------------------
				inc(蓋被せユニットEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(蓋被せユニットEmgStep)		
		end if				
	case 4
		timstack=OFF
		蓋被せユニットEmgStep=0
		蓋被せユニットEmg=OFF
	end select
		
end if 'if 蓋被せユニットEmgStep=0 then
