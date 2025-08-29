'蓋取りユニット
'===================================================================================================================
'
'<<<<<<<	ユニット	>>>>>>>>
'
'===================================================================================================================
'
'	蓋取りユニット
'
'	PH23_釜検知		-> PH51_釜検知
'	PH24_フタ検知	-> PH52_フタ検知
'	mSV40_ストッパ -> mSV49_ストッパ
'===================================================================================================================

'【 初期化処理 】
if CR2008 then

	蓋取りユニットAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    蓋取りユニットAutoRun=OFF
    蓋取りユニット許可=ON
    蓋取りユニットOrgErr=OFF
    蓋取りユニットErr=OFF
    蓋取りユニットEmg=OFF
    蓋取りユニットstep=0
    蓋取りユニットErrStep=0
    蓋取りユニットOrgErrStep=0
    蓋取りユニットEmgStep=0

end if
'===================================================================================================================
'【 原点 】
蓋取りユニットOrg=not(蓋取りユニット許可) or (XSW55_シリンダ上昇端A and XSW57_シリンダ上昇端B)

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	蓋取りユニットEmg=ON
	蓋取りユニットEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
tmr(SV45_シリンダ上昇A and not(XSW55_シリンダ上昇端A) and not(pnlPBXSW55_シリンダ上昇端A),tim_XSW55_シリンダ上昇端A,#40)
tmr(SV46_シリンダ下降A and not(XSW56_シリンダ下降端A) and not(pnlPBXSW56_シリンダ下降端A),tim_XSW56_シリンダ下降端A,#40)
tmr(SV47_シリンダ上昇B and not(XSW57_シリンダ上昇端B) and not(pnlPBXSW57_シリンダ上昇端B),tim_XSW57_シリンダ上昇端B,#40)
tmr(SV48_シリンダ下降B and not(XSW58_シリンダ下降端B) and not(pnlPBXSW58_シリンダ下降端B),tim_XSW58_シリンダ下降端B,#40)
tmr(SV49_アンクランプ and not(XSW59_アンクランプ) and not(pnlPBXSW59_アンクランプ),tim_XSW59_アンクランプ,#40)
tmr(SV50_クランプ and not(XSW60_クランプ) and not(pnlPBXSW60_クランプ),tim_XSW60_クランプ,#40)

'tmr(SV46_ストッパ and not(XSW63_ストッパ上昇端),tim_XSW63_ストッパ上昇端,#40)
'tmr(not(SV46_ストッパ) and not(XSW64_ストッパ下降端),tim_XSW64_ストッパ下降端,#40)


if ldp(tim_XSW55_シリンダ上昇端A.B) then
	errpassXSW55_シリンダ上昇端A=ON
	almXSW55_シリンダ上昇端A=ON
	蓋取りユニットErrStep=1

else if ldp(tim_XSW56_シリンダ下降端A.B) then
	errpassXSW56_シリンダ下降端A=ON
	almXSW56_シリンダ下降端A=ON
	蓋取りユニットErrStep=1

else if ldp(tim_XSW57_シリンダ上昇端B.B) then
	errpassXSW57_シリンダ上昇端B=ON
	almXSW57_シリンダ上昇端B=ON
	蓋取りユニットErrStep=1

else if ldp(tim_XSW58_シリンダ下降端B.B) then
	errpassXSW58_シリンダ下降端B=ON
	almXSW58_シリンダ下降端B=ON
	蓋取りユニットErrStep=1

else if ldp(tim_XSW59_アンクランプ.B) then
	errpassXSW59_アンクランプ=ON
	almXSW59_アンクランプ=ON
	蓋取りユニットErrStep=1

else if ldp(tim_XSW60_クランプ.B) then
	errpassXSW60_クランプ=ON
	almXSW60_クランプ=ON
	蓋取りユニットErrStep=1

'else if ldp(tim_XSW63_ストッパ上昇端.B) then
'	errpassXSW63_ストッパ上昇端=ON
'	almXSW63_ストッパ上昇端=ON
'	蓋取りユニットErrStep=1
'
'else if ldp(tim_XSW64_ストッパ下降端.B) then
'	errpassXSW64_ストッパ下降端=ON
'	almXSW64_ストッパ下降端=ON
'	蓋取りユニットErrStep=1

end if

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 蓋取りユニットAutoMode	自動モード セレクトスイッチ
'System :: 蓋取りユニットAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能
'System :: 蓋取りユニットEmg	その場停止


if 蓋取りユニットEmgStep=0 then  
	
	if 蓋取りユニットErrStep=0  then

	if not(蓋取りユニットOrgErr) then

	if (蓋取りユニットAutoMode and 自動搬送AutoMode ) or 蓋取りユニットstep<>0 then
		
		if not(蓋取りユニットAutoMode and 自動搬送AutoMode ) then
			蓋取りユニットAutoRun=OFF
		end if

	'===================================================================================================================
	'【 プロセス処理 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case 蓋取りユニットstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
			蓋取りユニットStatusMsg=#0
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' 作業工程を振り分ける
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 蓋取りユニットAutoRun then
				蓋取りユニットStatusMsg=#45	'	待機中
				inc(蓋取りユニットstep)
			else 
				蓋取りユニットstep=0 '終了待機
			end if
		
		case 2
		' [ 蓋カマ移動停止確認 ]
			if 蓋取りユニット排出要求=OFF and  搬送コンベアG動作中=OFF then
				inc(蓋取りユニットstep)
			else
				蓋取りユニットstep=1
			end if
		
		case 3
		' [ ユニット許可検出 ]
			if 蓋取りユニット許可 then
				inc(蓋取りユニットstep)
			else
				フタ取り完了=ON
				蓋取りユニット排出要求=ON
				蓋取りユニットstep=1
			end if
		
		case 4
			if XSW55_シリンダ上昇端A and XSW57_シリンダ上昇端B then '原点
				蓋取りユニットstep=100 'プロセス処理
			else
				蓋取りユニットstep=1
			end if
		'--------------------------------------------------------------------------------------------------------------
		'プロセス処理
		case 100
			if フタ取り完了 then '搬送移動でOFF
				蓋取りユニットstep=199
			else
				if not(フタ取りフタ取り中) and  PH51_釜検知 and PH52_フタ検知 then
					蓋取りユニットStatusMsg=#46	'	フタ取り中
					inc(蓋取りユニットstep) 'フタ取り
				else if フタ取りフタ取り中 and  not(PH51_釜検知) and not(PH52_フタ検知) then
					蓋取りユニットStatusMsg=#47	'	フタ置き中
					蓋取りユニットstep=150 'フタ置き
				else
					フタ取り完了=ON
					蓋取りユニット排出要求=ON
					蓋取りユニットstep=1
				end if
			end if

		'------------------------------------------------------
		case 101  'フタ取り
			mSV45_シリンダ上昇A=OFF
			mSV46_シリンダ下降A=OFF
			mSV47_シリンダ上昇B=OFF
			mSV48_シリンダ下降B=OFF
			mSV49_アンクランプ=OFF
			mSV50_クランプ=OFF
			
			tim_procstep_val=0
			res(tim_procstep)
			inc(蓋取りユニットstep)

		case 102
			if tim_procstep.B then
				inc(蓋取りユニットstep)
			end if

		case 103
			mSV46_シリンダ下降A=ON
			errpassXSW56_シリンダ下降端A=OFF
			inc(蓋取りユニットstep)

		case 104
			if errpassXSW56_シリンダ下降端A or XSW56_シリンダ下降端A then
				inc(蓋取りユニットstep)
			end if
		
		case 105
			mSV46_シリンダ下降A=OFF
			tim_procstep_val=0
			res(tim_procstep)
			inc(蓋取りユニットstep)
		
		case 106
			if tim_procstep.B then
				inc(蓋取りユニットstep)
			end if
		
		case 107
			mSV50_クランプ=ON
			errpassXSW60_クランプ=OFF
			inc(蓋取りユニットstep)
		
		case 108
			if errpassXSW60_クランプ or XSW60_クランプ then
				inc(蓋取りユニットstep)
			end if
		
		case 109
			mSV50_クランプ=OFF
			tim_procstep_val=0
			res(tim_procstep)
			inc(蓋取りユニットstep)
		
		case 110
			if tim_procstep.B then
				inc(蓋取りユニットstep)
			end if
		
		case 111
			mSV45_シリンダ上昇A=ON
			errpassXSW55_シリンダ上昇端A=OFF
			inc(蓋取りユニットstep)
		
		case 112
			if errpassXSW55_シリンダ上昇端A or XSW55_シリンダ上昇端A then
				inc(蓋取りユニットstep)
			end if
		
		case 113
			mSV45_シリンダ上昇A=OFF
			tim_procstep_val=0
			res(tim_procstep)
			inc(蓋取りユニットstep)
		
		case 114
			if tim_procstep.B then
				フタ取りフタ取り中=ON
				蓋取りユニットstep=199
			end if
		'------------------------------------------------------
		case 150 'フタ置き
			mSV45_シリンダ上昇A=OFF
			mSV46_シリンダ下降A=OFF
			mSV47_シリンダ上昇B=OFF
			mSV48_シリンダ下降B=OFF
			mSV49_アンクランプ=OFF
			mSV50_クランプ=OFF
			mSV49_ストッパ=OFF
			inc(蓋取りユニットstep)
		
		case 151
			mSV46_ストッパ=OFF
			inc(蓋取りユニットstep)
		
		case 152
			if errpassXSW64_ストッパ下降端 or ((XSW64_ストッパ下降端 and not(pnlPBXSW64_ストッパ下降端)) or passXSW64_ストッパ下降端) then
				inc(蓋取りユニットstep)
			end if
		
		case 153 
			tim_procstep_val=0
			res(tim_procstep)
			inc(蓋取りユニットstep)

		case 154
			if tim_procstep.B then
				if XSW55_シリンダ上昇端A and XSW57_シリンダ上昇端B then '原点
					if XSW60_クランプ then
						inc(蓋取りユニットstep)
					else
						蓋取りユニットOrgErr=ON
					end if
				else
					蓋取りユニットOrgErr=ON
				end if
			end if

		case 155
			mSV46_シリンダ下降A=ON
			inc(蓋取りユニットstep)
			
		case 156
			mSV48_シリンダ下降B=ON
			errpassXSW56_シリンダ下降端A=OFF
			inc(蓋取りユニットstep)		
		
		case 157
			if errpassXSW56_シリンダ下降端A or XSW56_シリンダ下降端A then
				inc(蓋取りユニットstep)
			end if		
		
		case 158
			mSV46_シリンダ下降A=OFF
			errpassXSW58_シリンダ下降端B=OFF
			inc(蓋取りユニットstep)

		case 159
			if errpassXSW58_シリンダ下降端B or XSW58_シリンダ下降端B then
				inc(蓋取りユニットstep)
			end if
		
		case 160			
			mSV48_シリンダ下降B=OFF
			tim_procstep_val=0
			res(tim_procstep)
			inc(蓋取りユニットstep)

		case 161
			if tim_procstep.B then
				inc(蓋取りユニットstep)
			end if
		
		case 162
			inc(蓋取りユニットstep)
		
		case 163
			mSV49_アンクランプ=ON
			errpassXSW59_アンクランプ=OFF
			inc(蓋取りユニットstep)
		
		case 164
			if errpassXSW59_アンクランプ or XSW59_アンクランプ then
				inc(蓋取りユニットstep)
			end if

		case 165
			mSV49_アンクランプ=OFF
			tim_procstep_val=0
			res(tim_procstep)
			inc(蓋取りユニットstep)
				
		case 166
			if tim_procstep.B then
				inc(蓋取りユニットstep)
			end if
		
		case 167
			mSV45_シリンダ上昇A=ON
			inc(蓋取りユニットstep)
		
		case 168
			mSV47_シリンダ上昇B=ON
			errpassXSW55_シリンダ上昇端A=OFF
			inc(蓋取りユニットstep)

		case 169
			if errpassXSW55_シリンダ上昇端A or XSW55_シリンダ上昇端A then
				inc(蓋取りユニットstep)
			end if
			
		case 170
			mSV45_シリンダ上昇A=OFF
			inc(蓋取りユニットstep)

		
		case 171
			if XSW57_シリンダ上昇端B then
				inc(蓋取りユニットstep)
			end if
	
		case 172
			mSV47_シリンダ上昇B=OFF
			inc(蓋取りユニットstep)

		
		case 173
			フタ取りフタ取り中=OFF
			蓋取りユニットstep=199

		'------------------------------------------------------
		case 199
			フタ取り完了=ON
			蓋取りユニット排出要求=ON
			蓋取りユニットstep=1
		'------------------------------------------------------


		end select

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		蓋取りユニットAutoRun=OFF
		
		蓋取りユニットstep=0 '終了
		
		res(tim_XSW55_シリンダ上昇端A.B)
		res(tim_XSW56_シリンダ下降端A.B)
		res(tim_XSW57_シリンダ上昇端B.B)
		res(tim_XSW58_シリンダ下降端B.B)
		res(tim_XSW59_アンクランプ)
		res(tim_XSW60_クランプ)


		'------------------------------------------------------
		if ldp(pnlPBSV45_シリンダ上昇A or pnlPBSV46_シリンダ下降A) and (XSW59_アンクランプ or (XSW60_クランプ and ((XSW64_ストッパ下降端 and not(pnlPBXSW64_ストッパ下降端)) or passXSW64_ストッパ下降端 )) ) then
			if XSW55_シリンダ上昇端A then
				mSV46_シリンダ下降A=ON
				mSV45_シリンダ上昇A=OFF
			else if XSW56_シリンダ下降端A then
				mSV46_シリンダ下降A=OFF
				mSV45_シリンダ上昇A=ON
			else
				mSV46_シリンダ下降A=OFF
				mSV45_シリンダ上昇A=ON			
			end if
		end if
		if mSV46_シリンダ下降A and XSW56_シリンダ下降端A then
			mSV46_シリンダ下降A=OFF
		end if
		if mSV45_シリンダ上昇A and XSW55_シリンダ上昇端A then
			mSV45_シリンダ上昇A=OFF
		end if
		'------------------------------------------------------
		if ldp(pnlPBSV47_シリンダ上昇B or pnlPBSV48_シリンダ下降B) and (XSW59_アンクランプ or (XSW60_クランプ and ((XSW64_ストッパ下降端 and not(pnlPBXSW64_ストッパ下降端)) or passXSW64_ストッパ下降端 )) ) then
			if XSW57_シリンダ上昇端B then
				mSV48_シリンダ下降B=ON
				mSV47_シリンダ上昇B=OFF
			else if XSW58_シリンダ下降端B then
				mSV48_シリンダ下降B=OFF
				mSV47_シリンダ上昇B=ON
			else
				mSV48_シリンダ下降B=OFF
				mSV47_シリンダ上昇B=ON			
			end if
		end if
		if mSV48_シリンダ下降B and XSW58_シリンダ下降端B then
			mSV48_シリンダ下降B=OFF
		end if
		if mSV47_シリンダ上昇B and XSW57_シリンダ上昇端B then
			mSV47_シリンダ上昇B=OFF
		end if
		'------------------------------------------------------
		if ldp(pnlPBSV49_アンクランプ or pnlPBSV50_クランプ) then
			if XSW59_アンクランプ then
				mSV50_クランプ=ON
				mSV49_アンクランプ=OFF
			
				フタ取りフタ取り中=ON

			else if XSW60_クランプ then
				mSV50_クランプ=OFF
				mSV49_アンクランプ=ON			

				フタ取りフタ取り中=OFF
				
			else
				mSV50_クランプ=OFF
				mSV49_アンクランプ=ON			

				フタ取りフタ取り中=OFF
			

			end if
		end if
		if mSV50_クランプ and XSW60_クランプ then
			mSV50_クランプ=OFF
		end if
		if mSV49_アンクランプ and XSW59_アンクランプ then
			mSV49_アンクランプ=OFF
		end if
		'------------------------------------------------------

	end if '蓋取りユニットAutoMode and not(蓋取りユニットOrgErrStep)
	'===================================================================================================================
	'【 蓋取りユニットOrgErr処理 】
	else

		res(tim_XSW55_シリンダ上昇端A.B)
		res(tim_XSW56_シリンダ下降端A.B)
		res(tim_XSW57_シリンダ上昇端B.B)
		res(tim_XSW58_シリンダ下降端B.B)
		res(tim_XSW59_アンクランプ)
		res(tim_XSW60_クランプ)
			
		if ResetFlg then
			蓋取りユニットOrgErr=OFF
		end if

	end if
	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
	
		蓋取りユニットErr=ON
	
		select case 蓋取りユニットErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW55_シリンダ上昇端A=OFF
				almXSW56_シリンダ下降端A=OFF
				almXSW57_シリンダ上昇端B=OFF
				almXSW58_シリンダ下降端B=OFF
				almXSW59_アンクランプ=OFF
				almXSW60_クランプ=OFF

				inc(蓋取りユニットErrStep)
			end if
		case 2
			蓋取りユニットErr=OFF

			res(tim_XSW55_シリンダ上昇端A.B)
			res(tim_XSW56_シリンダ下降端A.B)
			res(tim_XSW57_シリンダ上昇端B.B)
			res(tim_XSW58_シリンダ下降端B.B)
			res(tim_XSW59_アンクランプ)
			res(tim_XSW60_クランプ)
			蓋取りユニットErrStep=0
		end select

	end if 'if 蓋取りユニットErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case 蓋取りユニットEmgStep
	case 0
	
	case 1
		蓋取りユニットAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (蓋取りユニットAutoMode and 自動搬送AutoMode ) or 蓋取りユニットstep<>0 then
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
			mSV45_シリンダ上昇A=OFF
			mSV46_シリンダ下降A=OFF
			mSV47_シリンダ上昇B=OFF
			mSV48_シリンダ下降B=OFF
			mSV49_アンクランプ=OFF
			mSV50_クランプ=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(蓋取りユニットEmgStep)
	case 2
		if ResetFlg then
			inc(蓋取りユニットEmgStep)
		end if
	case 3
		if (蓋取りユニットAutoMode and 自動搬送AutoMode ) or 蓋取りユニットstep<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				tim_procstep.U=tim_procstep_stack
				
				
				
				'---------------------------------
				inc(蓋取りユニットEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(蓋取りユニットEmgStep)		
		end if				
	case 4
		timstack=OFF
		蓋取りユニットEmgStep=0
		蓋取りユニットEmg=OFF
	end select
		
end if 'if 蓋取りユニットEmgStep=0 then
