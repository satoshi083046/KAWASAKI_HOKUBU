'搬送コンベアH
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	搬送コンベアH 
'
'-------------------------------------------------
'	[ 40 ]	受け渡しリフト コンベアG -> コンベアH
'-------------------------------------------------
' 	PH53_釜検知
'	PH54_フタ検知
'
'	MC54_モータローラ MC55_搬送モータ
'					  MC10_搬送モータ正転(逆転）
'
'	SV50_リフト		XSW67_リフト上昇端
'					XSW68_リフト下降端
'	
'	SV49_ストッパ	XSW65_ストッパ上昇端
'					XSW66_ストッパ下降端
'
'-------------------------------------------------
'	[ 41 ]	反転ほぐし機A
'-------------------------------------------------
' 	PH67_釜検知
'
'	MC10_搬送モータ正転(逆転） MC55_搬送モータ
'
'-------------------------------------------------
'	[ 42 ]	反転ほぐし機A 待機位置
'-------------------------------------------------
' 	PH68_釜検知
' 	PH69_フタ検知
'
'-------------------------------------------------
'	[ 43 ]	釜フタ昇降装置A
'-------------------------------------------------
' 	PH55_釜検知
'	PH56_フタ検知
'
'	MC57_搬送モータ
'
'	SV59_リフト上昇		XSW80_リフト上昇端
'	SV76_リフト下降		XSW81_リフト下降端
'
'	釜反転ほぐし完了釜 : ほぐし工程完了後、まだ、搬送コンベアHに途中に存在する釜
'
'
'===================================================================================================================
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理
    搬送コンベアHAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    搬送コンベアHAutoRun=OFF
    搬送コンベアH許可=ON
    搬送コンベアHOrgErr=OFF
    搬送コンベアHErr=OFF
    搬送コンベアHEmg=OFF
    搬送コンベアHstep=0
    搬送コンベアHErrStep=0
    搬送コンベアHOrgErrStep=0
    搬送コンベアHEmgStep=0

	フタ排出step=0
	釜供給step=0
	釜排出step=0
	供給リフトstep=0
	
	if SSW3_自動モード then	
		ManualInite=1
	else
		ManualInite=0	
	end if

end if
'===================================================================================================================
'【 原点 】
搬送コンベアHOrg=((XSW67_リフト上昇端 and not(pnlPBXSW67_リフト上昇端)) or passXSW67_リフト上昇端) or ((XSW68_リフト下降端 and not(pnlPBXSW68_リフト下降端)) or passXSW68_リフト下降端)
搬送コンベアHOrg=搬送コンベアHOrg and (((XSW65_ストッパ上昇端 and not(pnlPBXSW65_ストッパ上昇端)) or passXSW65_ストッパ上昇端) or ((XSW66_ストッパ下降端 and not(pnlPBXSW66_ストッパ下降端)) or passXSW66_ストッパ下降端))

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	搬送コンベアHEmg=ON
	搬送コンベアHEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】

tmr(SV50_リフト and not(XSW67_リフト上昇端) and not(pnlPBXSW67_リフト上昇端), tim_notXSW67_リフト上昇端, #40)
tmr(not(SV50_リフト) and not(XSW68_リフト下降端) and not(pnlPBXSW68_リフト下降端),tim_notXSW68_リフト下降端, #40)
tmr(SV49_ストッパ and not(XSW65_ストッパ上昇端) and not(pnlPBXSW65_ストッパ上昇端),tim_notXSW65_ストッパ上昇端, #40)
tmr(not(SV49_ストッパ) and not(XSW66_ストッパ下降端) and not(pnlPBXSW66_ストッパ下降端),tim_notXSW66_ストッパ下降端, #40)

'tmr(not(SV50_リフト) and XSW67_リフト上昇端 and not(pnlPBXSW67_リフト上昇端), tim_XSW67_リフト上昇端, #10)
if LDP(SV50_リフト) and XSW67_リフト上昇端 and not(pnlPBXSW67_リフト上昇端) then
	SET(tim_XSW67_リフト上昇端)
end if
'tmr(SV50_リフト and XSW68_リフト下降端 and not(pnlPBXSW68_リフト下降端),tim_XSW68_リフト下降端, #10)
if LDF(SV50_リフト) and XSW68_リフト下降端 and not(pnlPBXSW68_リフト下降端) and not(pauseSV50_リフト) then
	SET(tim_XSW68_リフト下降端)
end if
'tmr(not(SV49_ストッパ) and XSW65_ストッパ上昇端 and not(pnlPBXSW65_ストッパ上昇端),tim_XSW65_ストッパ上昇端, #10)
if LDP(SV49_ストッパ) and XSW65_ストッパ上昇端 and not(pnlPBXSW65_ストッパ上昇端) then
	SET(tim_XSW65_ストッパ上昇端)
end if
'tmr(SV49_ストッパ and XSW66_ストッパ下降端 and not(pnlPBXSW66_ストッパ下降端),tim_XSW66_ストッパ下降端, #10)
if LDF(SV49_ストッパ) and XSW66_ストッパ下降端 and not(pnlPBXSW66_ストッパ下降端) and not(pauseSV49_ストッパ) then
	SET(tim_XSW66_ストッパ下降端)
end if

'tms(SV50_リフト,passtimXSW67_リフト上昇端,passtimXSW67_リフト上昇端_val)
'tms(not(SV50_リフト),passtimXSW68_リフト下降端,passtimXSW68_リフト下降端_val)
'tms(SV49_ストッパ,passtimXSW65_ストッパ上昇端,passtimXSW65_ストッパ上昇端_val)
'tms(not(SV49_ストッパ),passtimXSW66_ストッパ下降端,passtimXSW66_ストッパ下降端_val)

if ldp(tim_XSW67_リフト上昇端.B) or ldp(tim_notXSW67_リフト上昇端.B) then
	errpassXSW67_リフト上昇端=ON
	pauseSV50_リフト=ON
	almXSW67_リフト上昇端=ON
	pnlPBXSW67_リフト上昇端=ON
	搬送コンベアHErrStep=1

else if ldp(tim_XSW68_リフト下降端.B) or ldp(tim_notXSW68_リフト下降端.B) then
	errpassXSW68_リフト下降端=ON
	almXSW68_リフト下降端=ON
	pnlPBXSW68_リフト下降端=ON
	搬送コンベアHErrStep=1

else if ldp(tim_XSW65_ストッパ上昇端.B) or ldp(tim_notXSW65_ストッパ上昇端.B) then
	errpassXSW65_ストッパ上昇端=ON
	pauseSV49_ストッパ=ON
	almXSW65_ストッパ上昇端=ON
	pnlPBXSW65_ストッパ上昇端=ON
	搬送コンベアHErrStep=1

else if ldp(tim_XSW66_ストッパ下降端.B) or ldp(tim_notXSW66_ストッパ下降端.B) then
	errpassXSW66_ストッパ下降端=ON
	almXSW66_ストッパ下降端=ON
	pnlPBXSW66_ストッパ下降端=ON
	搬送コンベアHErrStep=1

end if

'MC55のコンベアから釜が離脱している時間の経過
'離脱中もフタ排出は可能です。
tim_ほぐし機Aユニット動作中_setval=1800
tmr(ほぐし機Aユニット動作中 ,tim_ほぐし機Aユニット動作中,tim_ほぐし機Aユニット動作中_setval)
if PH67_釜検知 then
	res(tim_ほぐし機Aユニット動作中)
end if

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 搬送コンベアHAutoMode	自動モード セレクトスイッチ
'System :: 搬送コンベアHAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 搬送コンベアHEmg	その場停止


tmr(PH53_釜検知,timdly_PH53_釜検知,4)
tmr(PH54_フタ検知,timdly_PH54_フタ検知,4)

if 搬送コンベアHEmgStep=0 then  
	
	if 搬送コンベアHErrStep=0  then

	if not(搬送コンベアHOrgErr) then

	if (搬送コンベアHAutoMode and 自動搬送AutoMode ) or 搬送コンベアHstep<>0 then
	
		if not(搬送コンベアHAutoMode and 自動搬送AutoMode ) then
			搬送コンベアHAutoRun=OFF
		end if
	
		if 	ManualInite=1 then
			mSV50_リフト=ON
			ManualInite=0	
		end if 

		

	'-----------------------------------------------------------------
	' 搬送モータ、ストッパON/OFFタイミングタスク
	'-----------------------------------------------------------------
	' 【 フタ排出 】
	tmr(tim_フタ排出,tim_フタ排出_val)
	select case フタ排出step
	case 0

	case 1	
		if not(PH53_釜検知) and PH54_フタ検知 then 'リフト位置 フタ検知
			inc(フタ排出step)
		else
			フタ排出step=0 '[ リフト位置 ]の釜フタあり
		end if

	case 2
		mSV50_リフト=OFF
		errpassXSW68_リフト下降端=OFF
		mSV49_ストッパ=OFF
		errpassXSW66_ストッパ下降端=OFF
		inc(フタ排出step)
	
	case 3
		if errpassXSW68_リフト下降端 or ((XSW68_リフト下降端 and not(pnlPBXSW68_リフト下降端)) or passXSW68_リフト下降端) then
			inc(フタ排出step)
		end if
		

	case 4
		if errpassXSW66_ストッパ下降端 or ((XSW66_ストッパ下降端 and not(pnlPBXSW66_ストッパ下降端)) or passXSW66_ストッパ下降端) then
			inc(フタ排出step)
		end if	
	
	case 5
		mMC10_搬送モータ逆転=ON
		ejectMC55_搬送モータ=ON
		ejectMC57_搬送モータ=ON
		inc(フタ排出step)

	case 6
		if not(PH53_釜検知) and not(PH54_フタ検知) then 'コンベアリフト位置の釜フタ移動検知
			inc(フタ排出step)
		end if

	case 7
		if not(PH68_釜検知) and PH69_フタ検知 then
			inc(フタ排出step)
		end if

	case 8
		if not(extMC55_搬送モータ) then
			供給リフトstep=1 '供給リフト上昇 → 搬送コンベアG起動
		end if
		inc(フタ排出step)
	
	case 9
		if PH55_釜検知 or PH56_フタ検知 then
			inc(フタ排出step)
		end if
	
	case 10
		tim_フタ排出_val=15
		res(tim_フタ排出)
		inc(フタ排出step)
	
	case 11
		if tim_フタ排出.B then
			inc(フタ排出step)
		end if
	
	case 12
		mMC10_搬送モータ逆転=OFF
		ejectMC55_搬送モータ=OFF
		ejectMC57_搬送モータ=OFF
		inc(フタ排出step)
	
	case 13
		搬送コンベアH排出要求=ON
		フタ排出step=0
	
	end select
		
	'-----------------------------------------------------------------
	' 【 釜供給 】
	tmr(tim_釜供給,tim_釜供給_val)
	select case 釜供給step
	case 0
	
	case 1
		if not(反転ほぐし釜供給中A) and not(PH67_釜検知) and PH53_釜検知 and PH54_フタ検知 then
			inc(釜供給step)
		else
			釜供給step=0
		end if

	case 2
		mSV50_リフト=OFF
		errpassXSW68_リフト下降端=OFF
		inc(釜供給step)
	
	case 3
		if errpassXSW68_リフト下降端 or ((XSW68_リフト下降端 and not(pnlPBXSW68_リフト下降端)) or passXSW68_リフト下降端) then
			inc(釜供給step)
		end if
		
	case 4
		mSV49_ストッパ=OFF
		errpassXSW66_ストッパ下降端=OFF
		inc(釜供給step)

	case 5
		if errpassXSW66_ストッパ下降端 or ((XSW66_ストッパ下降端 and not(pnlPBXSW66_ストッパ下降端)) or passXSW66_ストッパ下降端) then
			inc(釜供給step)
		end if	

	case 6
		mMC10_搬送モータ正転=ON
		inc(釜供給step)
	
	case 7
		if not(PH53_釜検知) and not(PH54_フタ検知) then
			inc(釜供給step)
		end if
		
	case 8
		if PH67_釜検知 then
			inc(釜供給step)
		end if
	
	case 9
		tim_釜供給_val=15
		res(tim_釜供給)
		inc(釜供給step)
	
	case 10
		if tim_釜供給.B then
			inc(釜供給step)
		end if

	case 11
		StageDevice41=StageDevice40
		mMC10_搬送モータ正転=OFF
		inc(釜供給step)
	
	case 12
		供給リフトstep=1 '供給リフト上昇 → 搬送コンベアG起動
		反転ほぐし釜供給中A=ON
		釜供給step=0
		
	end select

	'-----------------------------------------------------------------
	' 【 釜排出 】
	tmr(tim_釜排出,tim_釜排出_val)
	select case 釜排出step
	case 0
	
	case 1	
		if ほぐし機Aユニット完了 and 反転ほぐし釜供給中A and PH67_釜検知 then 'ほぐしAの釜検知
			inc(釜排出step)
		else
			釜排出step=0 'ほぐしAの釜検知 なし
		end if

	case 2
		mSV50_リフト=OFF
		errpassXSW68_リフト下降端=OFF

		inc(釜排出step)
	
	case 3
		if errpassXSW68_リフト下降端 or ((XSW68_リフト下降端 and not(pnlPBXSW68_リフト下降端)) or passXSW68_リフト下降端) then
			inc(釜排出step)
		end if

	case 4
		mSV49_ストッパ=OFF
		errpassXSW66_ストッパ下降端=OFF
		inc(釜排出step)


	case 5
		if errpassXSW66_ストッパ下降端 or ((XSW66_ストッパ下降端 and not(pnlPBXSW66_ストッパ下降端)) or passXSW66_ストッパ下降端) then
			inc(釜排出step)
		end if	

	case 6
		ejectMC10_搬送モータ逆転=ON
		extMC55_搬送モータ=ON 'eject2
		inc(釜排出step)
		
	case 7
		if not(PH67_釜検知) then
			inc(釜排出step)
		end if

	case 8
		if PH68_釜検知 then '釜フタ昇降装置A 待機位置 釜検知
			inc(釜排出step)
		end if
	
	case 9
		供給リフトstep=1 '供給リフト上昇 → 搬送コンベアG起動
		
		ejectMC10_搬送モータ逆転=OFF
		extMC55_搬送モータ=OFF
		inc(釜排出step)

	case 10
		if 供給リフトstep=0 then
			inc(釜排出step)
		end if

	case 11
		搬送コンベアH排出要求=ON '釜フタ昇降装置A 起動
		ほぐし機Aユニット排出要求=OFF
		反転ほぐし釜供給中A=OFF
		ほぐし機Aユニット完了=OFF
		釜排出step=0

	end select
	
	'-----------------------------------------------------------------
	'
	' 供給リフト上昇
	' 	'
	tmr(tim_供給リフト,tim_供給リフト_val)
	select case 供給リフトstep
	case 0
	case 1
		if not(PH53_釜検知) or not(PH54_フタ検知) then
			inc(供給リフトstep) 
		else				
			供給リフトstep=0
		end if

	case 2
		mSV50_リフト=ON
		errpassXSW67_リフト上昇端=OFF
		mSV49_ストッパ=ON
		errpassXSW65_ストッパ上昇端=OFF
		inc(供給リフトstep) 
	
	case 3
		if (errpassXSW67_リフト上昇端 or ((XSW67_リフト上昇端 and not(pnlPBXSW67_リフト上昇端)) or passXSW67_リフト上昇端)) and (errpassXSW65_ストッパ上昇端 or ((XSW65_ストッパ上昇端 and not(pnlPBXSW65_ストッパ上昇端)) or passXSW65_ストッパ上昇端)) then
			inc(供給リフトstep)		
		end if

	case 4
		搬送コンベアH動作中=OFF
'		搬送コンベアG排出要求=OFF '搬送コンベアG起動
		供給リフトstep=0

	end select
	'-----------------------------------------------------------------
	'
	' 洗浄禁止処理
	' 	'
	tmr(tim_洗浄禁止処理,tim_洗浄禁止処理_val)
	select case 洗浄禁止処理step
	case 0
	case 1
		if 搬送コンベアHAutoRun then
			if (not(PH53_釜検知) and PH54_フタ検知) or PH67_釜検知 then 'リフト位置 フタ検知
				洗浄禁止処理step=1
			else if ほぐし機Aユニット完了 and 反転ほぐし釜供給中A and PH67_釜検知 then
				inc(洗浄禁止処理step)
			else if  not(PH54_フタ検知) and not(PH67_釜検知) then
				洗浄禁止処理step=10
			end if
		else
			洗浄禁止処理step=0		
		end if
		
	case 2
		if  not(PH54_フタ検知) and not(PH67_釜検知) then
			洗浄禁止処理step=10
		end if

	case 10
		'フタ排出の終了工程
		'搬送コンベアH排出要求=ON '釜フタ昇降装置A 起動
		ほぐし機Aユニット排出要求=OFF
		反転ほぐし釜供給中A=OFF
		ほぐし機Aユニット完了=OFF

		搬送コンベアG排出要求=OFF

		洗浄禁止処理step=0
		
	end select
	'-----------------------------------------------------------------

	'===================================================================================================================
	'【 リフタータスク 】
	'
		if ManualInite=1 then
			mSV50_リフト=ON
			mSV49_ストッパ=ON
			ManualInite=0
		end if

		tmr(tim_procstep,tim_procstep_val)

		select case 搬送コンベアHstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 搬送コンベアHAutoRun then
				inc(搬送コンベアHstep)
			else 
				搬送コンベアHstep=0 '終了待機
			end if
		
		case 2
			if PH68_釜検知 or PH69_フタ検知 then
				搬送コンベアH排出要求=ON
			end if
				
			inc(搬送コンベアHstep)		

		case 3
			if 搬送コンベアH排出要求=OFF  and (ほぐし機Aユニット排出要求 or 搬送コンベアG排出要求) then '起動トリガ
				inc(搬送コンベアHstep)
			else if not(反転ほぐし釜供給中A) and 搬送コンベアG排出要求 and PH53_釜検知 and PH54_フタ検知 then
					搬送コンベアHstep=300
			else
				搬送コンベアH動作中=OFF
				搬送コンベアHstep=1
			end if
		
		case 4  '原点検出
			if  搬送コンベアHOrg then
				inc(搬送コンベアHstep)
			else
				搬送コンベアHstep=1
			end if
		
		case 5
'			if not(SV50_リフト) and not(timdly_PH53_釜検知.B) and not(timdly_PH54_フタ検知.B) then
'				mSV50_リフト=ON
'				errpassXSW67_リフト上昇端=OFF
'			end if
			errpassXSW67_リフト上昇端=OFF
			inc(搬送コンベアHstep)
		
		case 6
			if mSV50_リフト then
				if errpassXSW67_リフト上昇端 or ((XSW67_リフト上昇端 and not(pnlPBXSW67_リフト上昇端)) or passXSW67_リフト上昇端) then
					inc(搬送コンベアHstep)
				end if
			else
				inc(搬送コンベアHstep)
			end if
				
		case 7
			搬送コンベアHstep=100
		'--------------------------------------------------------------------------------------------------------------
		case 100
			
			if not(反転ほぐし釜供給中A) and timdly_PH53_釜検知.B and timdly_PH54_フタ検知.B then 'リフト上=釜
			'●ほぐしA釜供給					
				コンベアH釜排出待機=ON
				搬送コンベアHstep=300
				
			else if not(timdly_PH53_釜検知.B) and timdly_PH54_フタ検知.B then 'リフト上=フタ
			'●フタ
				if 反転ほぐし釜供給中A then
					if ほぐし機Aユニット排出要求 and ほぐし機Aユニット完了 then 'ほぐしA完了待ち
						if not(mSV59_リフト上昇) and ((XSW81_リフト下降端 and not(pnlPBXSW81_リフト下降端)) or passXSW81_リフト下降端) and not(PH55_釜検知) and not(PH56_フタ検知) then '昇降リフト下降端
							if not(PH68_釜検知) and not(PH69_フタ検知) then '反転ほぐし待機位置にフタ釜なし
								搬送コンベアHstep=500 'フタ, ほぐし機釜排出
							else 
								搬送コンベアHstep=1
							end if
						else
							搬送コンベアHstep=1
						end if
					else
						搬送コンベアHstep=1
					end if
				else
					搬送コンベアHstep=400 'フタのみ
				end if
				
			else if not(timdly_PH53_釜検知.B) and not(timdly_PH54_フタ検知.B) then  'リフト上=何もなし
			'●ほぐしA釜排出
'				if 反転ほぐし釜供給中A then
'					if not(コンベアH釜排出待機) and  反転ほぐし釜供給中A and ほぐし機Aユニット排出要求 and ほぐし機Aユニット完了 then
'						搬送コンベアHstep=200
'					else 
'						搬送コンベアHstep=1
'					end if					
'				else
			'●供給リフトに物がない
				搬送コンベアG排出要求=OFF
				搬送コンベアHstep=1
'				end if
			else
				搬送コンベアHstep=1
				
			end if
		'--------------------------------------------------------------------------------------------------------------
		'●ほぐしA釜排出
		
		case 200 
				搬送コンベアH動作中=ON
				釜排出step=1
				inc(搬送コンベアHstep)
		case 201
				if 釜排出step=0 then 
					inc(搬送コンベアHstep)
				end if
		case 202
				搬送コンベアG排出要求=OFF

				反転ほぐし釜供給中A=OFF
				ほぐし機Aユニット排出要求=OFF				
				ほぐし機Aユニット完了=OFF
				搬送コンベアH動作中=OFF
				搬送コンベアHstep=1
				
		'--------------------------------------------------------------------------------------------------------------
		'●ほぐしA釜供給
		case 300 
				搬送コンベアH動作中=ON
				釜供給step=1
				inc(搬送コンベアHstep)

		case 301
				if 釜供給step=0 then
					inc(搬送コンベアHstep)
				end if
			
		case 302
				搬送コンベアG排出要求=OFF
				反転ほぐし釜供給中A=ON
				搬送コンベアH動作中=OFF
				搬送コンベアHstep=1
		'--------------------------------------------------------------------------------------------------------------
		'●フタ
		case 400 

				フタ搬送中=not(PH53_釜検知) and  PH54_フタ検知
				フタ排出step=1
				
				搬送コンベアH動作中=ON
				inc(搬送コンベアHstep)
		case 401
			if フタ排出step=0 then
				inc(搬送コンベアHstep)
			end if
				
		case 402		
				搬送コンベアG排出要求=OFF
				搬送コンベアH動作中=OFF
				搬送コンベアHstep=1
		'--------------------------------------------------------------------------------------------------------------
		'●フタ , ほぐし釜排出 
		case 500
			if 洗浄禁止 then
				洗浄禁止処理step=1		
				inc(搬送コンベアHstep)
			else
				
				フタ搬送中=not(PH53_釜検知) and  PH54_フタ検知
				フタ排出step=1
				釜排出step=1
				
				搬送コンベアH動作中=ON
				inc(搬送コンベアHstep)
			end if

		case 501
			if フタ排出step=0 then
				inc(搬送コンベアHstep)
			end if
			
		case 502
			if 釜排出step=0 then
				inc(搬送コンベアHstep)
			end if
		
		case 503
			if 洗浄禁止 then
				if 洗浄禁止処理step=0 then
					inc(搬送コンベアHstep)			
				end if
			else
				inc(搬送コンベアHstep)		
			end if
			
		case 504
				搬送コンベアG排出要求=OFF
				搬送コンベアH動作中=OFF
				搬送コンベアHstep=1
		'--------------------------------------------------------------------------------------------------------------
		end select
	
	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		搬送コンベアHAutoRun=OFF
		
		搬送コンベアHstep=0 '終了
		
		if ldp(pnlPBMC10_搬送モータ正転)  then
			if mMC10_搬送モータ正転 then
				mMC10_搬送モータ正転=OFF
			else if ((XSW68_リフト下降端 and not(pnlPBXSW68_リフト下降端)) or passXSW68_リフト下降端) and not(pnlPBMC10_搬送モータ逆転) and not(mMC10_搬送モータ逆転) then
				mMC10_搬送モータ正転=ON
			end if
		end if
		if ldp(pnlPBMC10_搬送モータ逆転) then
			if mMC10_搬送モータ逆転 then
				mMC10_搬送モータ逆転=OFF
			else if ((XSW68_リフト下降端 and not(pnlPBXSW68_リフト下降端)) or passXSW68_リフト下降端) and not(pnlPBMC10_搬送モータ正転) and not(mMC10_搬送モータ正転) then
				mMC10_搬送モータ逆転=ON
			end if
		end if
		
		if ldp(pnlPBMC55_搬送モータ) then
			if mMC55_搬送モータ then
				mMC55_搬送モータ=OFF
			else if ((XSW68_リフト下降端 and not(pnlPBXSW68_リフト下降端)) or passXSW68_リフト下降端)  then
				mMC55_搬送モータ=ON
			end if
		end if
			
	end if '搬送コンベアHAutoMode and not(搬送コンベアHOrgErrStep)

	'===================================================================================================================
	'【 搬送コンベアHOrgErr処理 】
	else
	

		if ResetFlg then
			搬送コンベアHOrgErr=OFF
		end if


	end if

	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else

		搬送コンベアHErr=ON

		pauseMC10_搬送モータ正転=ON
		pauseMC10_搬送モータ逆転=ON
		pauseMC55_搬送モータ=ON
		pauseMC57_搬送モータ=ON

		select case 搬送コンベアHErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW67_リフト上昇端=OFF
				almXSW68_リフト下降端=OFF
				almXSW65_ストッパ上昇端=OFF
				almXSW66_ストッパ下降端=OFF

				inc(搬送コンベアHErrStep)
			end if
		case 2
			res(tim_XSW67_リフト上昇端)
			res(tim_XSW68_リフト下降端)
			res(tim_XSW65_ストッパ上昇端)
			res(tim_XSW66_ストッパ下降端)
			res(tim_notXSW67_リフト上昇端)
			res(tim_notXSW68_リフト下降端)
			res(tim_notXSW65_ストッパ上昇端)
			res(tim_notXSW66_ストッパ下降端)

			pauseMC10_搬送モータ正転=OFF
			pauseMC10_搬送モータ逆転=OFF
			pauseMC55_搬送モータ=OFF
			pauseMC57_搬送モータ=OFF

			pauseSV50_リフト=OFF
			pauseSV49_ストッパ=OFF

			搬送コンベアHErr=OFF
			搬送コンベアHErrStep=0

		end select

	end if 'if 搬送コンベアHErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else

	select case 搬送コンベアHEmgStep
	case 0
		
	case 1
		搬送コンベアHAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (搬送コンベアHAutoMode and 自動搬送AutoMode ) or 搬送コンベアHstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseMC10_搬送モータ正転=ON
			pauseMC10_搬送モータ逆転=ON
			pauseMC55_搬送モータ=ON
			pauseMC57_搬送モータ=ON

			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				timdly_PH36_釜検知_stack=timdly_PH36_釜検知.U
				timdly_PH37_フタ検知_stack=timdly_PH37_フタ検知.U
				timdly_PH53_釜検知_stack=timdly_PH53_釜検知.U
				timdly_PH54_フタ検知_stack=timdly_PH54_フタ検知.U
				tim_MC55_搬送モータ_stack=tim_MC55_搬送モータ.U
				tim_フタ排出_stack=tim_フタ排出.U
				tim_ほぐし機Aユニット動作中_stack=tim_ほぐし機Aユニット動作中.U
				tim_釜供給_stack=tim_釜供給.U
				tim_釜排出_stack=tim_釜排出.U
				tim_供給リフト_stack=tim_供給リフト.U

				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC10_搬送モータ正転=OFF
			mMC10_搬送モータ逆転=OFF
			mMC55_搬送モータ=OFF
			mMC57_搬送モータ=OFF
			
			mSV50_リフト=OFF
			mSV49_ストッパ=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(搬送コンベアHEmgStep)
	case 2
		if ResetFlg then
			inc(搬送コンベアHEmgStep)
		end if
	case 3
		if (搬送コンベアHAutoMode and 自動搬送AutoMode ) or 搬送コンベアHstep<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseMC10_搬送モータ正転=OFF
				pauseMC10_搬送モータ逆転=OFF
				pauseMC55_搬送モータ=OFF
				pauseMC57_搬送モータ=OFF

				tim_procstep.U=tim_procstep_stack
				timdly_PH36_釜検知.U=timdly_PH36_釜検知_stack
				timdly_PH37_フタ検知.U=timdly_PH37_フタ検知_stack
				timdly_PH53_釜検知.U=timdly_PH53_釜検知_stack
				timdly_PH54_フタ検知.U=timdly_PH54_フタ検知_stack
				tim_MC55_搬送モータ.U=tim_MC55_搬送モータ_stack
				tim_フタ排出.U=tim_フタ排出_stack
				tim_ほぐし機Aユニット動作中_stack=tim_ほぐし機Aユニット動作中.U
				tim_釜供給.U=tim_釜供給_stack
				tim_釜排出.U=tim_釜排出_stack
				tim_供給リフト.U=tim_供給リフト_stack

				'---------------------------------
				inc(搬送コンベアHEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			'---------------------------------
			inc(搬送コンベアHEmgStep)		
		end if				
	case 4
		timstack=OFF
		搬送コンベアHEmgStep=0
		搬送コンベアHEmg=OFF
	end select
		
end if 'if 搬送コンベアHEmgStep=0 then
