'Main
'===================================================================================================================
'
'<<<<<<<	Main操作部	>>>>>>>>
'
'===================================================================================================================
客先コード=川崎北部

'-------------------------------------------------------------------------------------------------------------------
'【前処理工程】
'	前処理
'		注水			DM_Aタンク設定値 > 0
'		送米			DM_Aタンク送米現在値 < DM_Aタンク設定値
'
'		貯米カウント 	DM_浸漬タンクA貯米釜数=DM_Aタンク送米現在値 - DM_A配米現在値
'
'		手動・浸漬タンク排水 and 米無し 	DM_Aタンク送米現在値=0 DM_浸漬タンクA貯米釜数=0
'
'	搬送コンベア運転
'
'		加水釜数現在値>=加水釜数設定値
'			*炊飯器に着火するタイミング
'		配米準備釜数現在値>=配米準備釜数設定値 and  ldp(PB22_自動運転 and 自動搬送AutoMode)  DM_A配米現在値=0
'			*配米準備釜数：配米可能な洗浄された釜
'
'		配米			DM_浸漬タンクA貯米釜数>0
'		配米終了		DM_A配米設定値=0 or DM_A配米現在値>=DM_A配米設定値 or 米無し
'
'		消火警告までの残釜数>=消火警告までの残釜数設定値
'
'		DM_排出残数=0
'			*自動終了タイミング(炊飯された釜が洗浄終了されるタイミング)
'
'-------------------------------------------------------------------------------------------------------------------
'デバックモニター
'
DM_Aタンク設定値=DM_Aタンク設定値
DM_Aタンク送米現在値=DM_Aタンク送米現在値
DM_Aタンク送米現在値残数=DM_Aタンク設定値-DM_Aタンク送米現在値
if DM_Aタンク送米現在値残数<0 then
	DM_Aタンク送米現在値残数=0
end if
DM_浸漬タンクA貯米釜数=DM_浸漬タンクA貯米釜数
DM_A配米設定値=DM_Aタンク設定値+DM_Aタンク補正値 'DM_Aタンク補正値 (初期値=5)
DM_A配米現在値=DM_A配米現在値
DM_A配米現在値残数=DM_A配米設定値-DM_A配米現在値
if DM_A配米現在値残数<0 then
	DM_A配米現在値残数=0
end if

	if DM_A配米現在値=0 then
		配米現在値Aグラフ=0
	else if DM_A配米現在値>=DM_Aタンク設定値 then
		配米現在値Aグラフ=100
	else
		配米現在値Aグラフ=(DM_A配米現在値*100)/ DM_Aタンク設定値
	end if

'
DM_Bタンク設定値=DM_Bタンク設定値
DM_Bタンク送米現在値=DM_Bタンク送米現在値
DM_Bタンク送米現在値残数=DM_Bタンク設定値-DM_Bタンク送米現在値
if DM_Bタンク送米現在値残数<0 then
	DM_Bタンク送米現在値残数=0
end if
DM_浸漬タンクB貯米釜数=DM_浸漬タンクB貯米釜数
DM_B配米設定値=DM_Bタンク設定値+DM_Bタンク補正値 'DM_Bタンク補正値 (初期値=5)
DM_B配米現在値=DM_B配米現在値

DM_B配米現在値残数=DM_B配米設定値-DM_B配米現在値
if DM_B配米現在値残数<0 then
	DM_B配米現在値残数=0
end if
	
	if DM_B配米現在値=0 then
		配米現在値Bグラフ=0
	else if DM_B配米現在値 >= DM_Bタンク設定値 then
		配米現在値Bグラフ=100
	else
		配米現在値Bグラフ= (DM_B配米現在値*100) / DM_Bタンク設定値
	end if

DM_配米総数設定値=DM_Aタンク設定値+DM_Bタンク設定値
DM_配米総数=DM_A配米現在値+DM_B配米現在値

DM_排出残数=DM_配米総数-DM_排出総数
if DM_排出残数<0 or (DM_排出残数>=0 and pnlPB排出残数リセット) then
	DM_排出総数=DM_配米総数
	DM_排出残数=0	
end if

	if DM_排出総数=0 then
		反転釜現在値グラフ=0
		反転釜残数グラフ=0
	else if DM_排出総数>=DM_配米総数 then
		反転釜現在値グラフ=100
		反転釜残数グラフ=0
	else
		反転釜現在値グラフ=(DM_排出総数*100) / DM_配米総数
		反転釜残数グラフ=100-((DM_排出総数*100) / DM_配米総数)
	end if



運転準備中=運転準備中
運転準備完了=運転準備完了

加水釜数設定値=加水釜数設定値 '(初期値=25) 
加水釜数現在値=加水釜数現在値
加水釜数現在値残数=加水釜数設定値-加水釜数現在値
if 加水釜数現在値残数<0 then
	加水釜数現在値残数=0
end if

if 加水釜数<0 then
	加水釜数=0
else if 加水釜数>DM_配米総数 then
	加水釜数=DM_配米総数-1
end if

配米準備釜数設定値=配米準備釜数設定値 '(初期値=5)
配米準備釜数現在値=配米準備釜数現在値
配米準備釜数現在値残数=配米準備釜数設定値-配米準備釜数現在値
if 配米準備釜数現在値残数<0 then
	配米準備釜数現在値残数=0
end if

消火警告までの残釜数設定値=消火警告までの残釜数設定値 '(初期値=30)
消火警告までの残釜数=消火警告までの残釜数
消火警告までの残釜数残数=消火警告までの残釜数設定値-消火警告までの残釜数
if 消火警告までの残釜数残数<0 then
	消火警告までの残釜数残数=0
end if

配米終了フラグ=配米終了フラグ


'IH_A,IH_B に搬入時 inc(IH搬入炊飯釜カウント) 搬出時 dec(IH搬入炊飯釜カウント)
if IH搬入炊飯釜カウント<0 then
	IH搬入炊飯釜カウント=0
else if IH搬入炊飯釜カウント>0 then
	IND_炊飯中=ON
else if IH搬入炊飯釜カウント=0 then
	IND_炊飯中=OFF
end if

'配米総数 / 2 の計算値
if (DM_Aタンク設定値 + DM_Bタンク設定値)>0 then
	チェック釜数設定値=(DM_Aタンク設定値 + DM_Bタンク設定値)/2
else
	チェック釜数設定値=0
end if
チェック釜数現在値=DM_A配米現在値 + DM_B配米現在値 


'===================================================================================================================
'【 初期化処理 】
'-------------------------------------------------------
if CR2008 then '電源ON時初期化処理
	if not(PB23_自動停止) and PB34_リセット then
		テスト運転=ON
	else	
		テスト運転=OFF
	end if
	
	炊飯完了停止【済】=OFF
end if
'-------------------------------------------------------
'テスト運転初期化処理
if ldp(テスト運転) and 自動搬送AutoMode then
	浸漬タンクAユニット許可=OFF
	浸漬タンクBユニット許可=OFF
	計水ユニット許可=OFF
	洗浄タンクAutoMode=ON
	洗浄タンクAutoRun=ON
	すすぎ禁止=ON
end if

if ldf(テスト運転)  and 自動搬送AutoMode then
	洗浄タンクAutoMode=OFF
	洗浄タンクAutoRun=OFF
	すすぎ禁止=OFF
end if
	
'-------------------------------------------------------
'前処理予約による自動クリア
'-------------------------------------------------------
if ldp(前処理工程AutoRun) and DM_Aタンク送米現在値=0 and DM_Bタンク送米現在値=0 then
	運転準備中=OFF
	運転準備完了=OFF
	
	shiftreg釜フタ判定0=0
	shiftreg釜フタ判定1=0
	shiftreg釜フタ判定2=0
	shiftreg釜フタ判定3=0
	shiftreg釜フタ判定4=0
	shiftreg釜フタ判定5=0
	
end if
'-------------------------------------------------------
'各工程処理 
if テスト運転 then
	自動停止=OFF
	IND_自動停止可能=OFF
end if

if not(テスト運転) then

'--運転準備中
if 運転準備中 then
	if Main手順初期化 then
		StageDevice0=0
		StageDevice1=0
		StageDevice2=0
		StageDevice3=0
		StageDevice4=0
		StageDevice5=0
		StageDevice6=0
		StageDevice7=0
		StageDevice8=0
		StageDevice9=0
		StageDevice10=0
		StageDevice11=0
		StageDevice12=0
		
		Main手順初期化=OFF

		'グローバルウィンドウ消去		
		tmsg運転準備完了=OFF
		tmsg運転準備完了消去=ON
		
		tmsg配米完了表示=OFF
		tmsg配米完了消去=ON
		
		tmsg検温停止中表示=OFF
		tmsg検温停止中消去=ON
		
		tmsg炊飯完了表示=OFF
		tmsg炊飯完了消去=ON
		
	end if
	
	IND_配米準備=ON
	IND_配米中=OFF
	IND_炊飯中=OFF
	IND_炊飯完了=OFF
	IND_停止待機=OFF
	
	浸漬タンクAユニット許可=OFF
	浸漬タンクBユニット許可=OFF
	
	ITEM登録禁止=OFF
	
	if not(PB23_自動停止) then
		運転準備中=OFF
		運転準備完了=OFF
				
		洗浄タンクAutoMode=OFF
		洗浄タンクAutoRun=OFF

		運転準備開始確認【済】=OFF
		炊飯機点火実行確認【済】=OFF
		
		浸漬タンクAユニット許可=OFF
		浸漬タンクBユニット許可=OFF

		tmsg運転準備完了=OFF '配米始まり
		tmsg運転準備完了消去=OFF'配米始まり
		tmsg配米完了表示=OFF
		tmsg配米完了消去=OFF
		tmsg検温停止中表示=OFF
		tmsg検温停止中消去=OFF
		tmsg炊飯完了表示 =OFF
		tmsg炊飯完了消去=OFF

	
	else
		if 炊飯機点火実行確認【済】 then


			if 運転準備開始確認【済】 and (配米準備釜数現在値>=配米準備釜数設定値 or 洗浄禁止) then '加水釜を炊飯機に搬送済み
				
				'配米準備
				tmsg運転準備完了=ON '配米始まり
				tmsg運転準備完了消去=OFF'配米始まり
				
				MainStatusMsg=#110
			
				if ldp(pnlPBOK) or (ldp(PB22_自動運転 and 自動搬送AutoMode) and PB23_自動停止) then 'and 自動搬送AutoRun then
					
					'配米実行準備
					運転準備中=OFF
					運転準備完了=ON
					
					洗浄タンクAutoMode=ON
					洗浄タンクAutoRun=ON
					
					炊飯機消火警告【済】=OFF
					炊飯完了停止【済】=OFF
					配米終了フラグ=OFF
					
					検温待ち停止=OFF

					'-------------------------------------------------------
					'データクリア
					'-------------------------------------------------------			
					DM_A配米現在値=0
					DM_B配米現在値=0
					DM_排出総数=0
					
					'グローバルウィンドウ消去
					tmsg運転準備完了=OFF
					tmsg運転準備完了消去=ON
					
					tmsg配米完了表示=OFF
					tmsg配米完了消去=OFF
					
					tmsg検温停止中表示=OFF
					tmsg検温停止中消去=OFF
					
					tmsg炊飯完了表示=OFF
					tmsg炊飯完了消去=OFF
					'-------------------------------------------------------
					StageDevice51=0 '釜反転位置(反転位置）
					StageDevice52=0 'リフト位置
					'-------------------------------------------------------

					運転初期化=OFF
				end if
			end if
			
	
		else if 運転準備開始確認【済】 then '洗浄タンクAutoRun済み

			炊飯機点火実行確認【済】=ON
			配米準備釜数現在値=0			
	
		else if メインTP_切替ページＮｏ15【済】 then 'チェックシート  チェック済み	
			メインTP_切替ページＮｏ=21

			if ldp(PB22_自動運転 and 自動搬送AutoMode) and PB23_自動停止  then 'and 自動搬送AutoRun then

				'洗浄タンク=ON
				運転準備開始確認【済】=ON
				
				洗浄タンクAutoMode=ON
				洗浄タンクAutoRun=ON

			end if
		end if
	
	end if

'--運転準備完了 (配米運転）
else if 運転準備完了 then
	
	Main手順初期化=OFF
	運転準備初期化=OFF			
	
	if not(運転初期化) then '運転初期化する<処理内容>未登録
		'<処理内容>
		運転初期化=ON

		IND_配米準備=OFF
		IND_配米中=OFF
		'IND_炊飯中=OFF
		IND_炊飯完了=OFF
		IND_停止待機=OFF

		浸漬タンクAユニット許可=ON
		浸漬タンクBユニット許可=ON
		計水ユニット許可=ON
		
		炊飯完了からの釜カウント=0
		空釜搬送実行step=0
	end if

	if ldp(検温待ち停止) then
		tmsg検温停止中表示=ON
		tmsg検温停止中消去=OFF
	else if ldp(検温待ち停止解除) then
		tmsg検温停止中表示=OFF
		tmsg検温停止中消去=ON		
	end if

	if IND_配米中 then
		if ldp(浸漬タンクA米無し) then
			pnlPB強制米無しA=ON
		else if ldp(浸漬タンクB米無し) then
			pnlPB強制米無しB=ON
		end if
	end if

	if ldp(チェック釜数現在値=チェック釜数設定値) and not(洗浄禁止) then
		空釜搬送実行step=1		
	end if
	
	select case 空釜搬送実行step
	case 0
	case 1
		if アイドル釜数設定値=0 then
			アイドル釜数現在値=アイドル釜数設定値
			空釜搬送実行step=0
		else
			アイドル釜数現在値=0
			inc(空釜搬送実行step)
		end if
	case 2
		浸漬タンクAユニット許可=OFF
		浸漬タンクBユニット許可=OFF
		inc(空釜搬送実行step)
	
	
	case 3
		if アイドル釜数現在値>アイドル釜数設定値 or 洗浄禁止 then
			浸漬タンクAユニット許可=ON
			浸漬タンクBユニット許可=ON
			空釜搬送実行step=0
		end if
	
	end select
	
	if 配米終了フラグ or (not(浸漬タンクAユニット許可) and not(浸漬タンクBユニット許可)) then
		IND_配米中=OFF
	else
		IND_配米中=ON
	end if	
	
'-- A配米完了 and B配米完了
	if (DM_Aタンク設定値=0 or 浸漬タンクA米無し) and  (DM_Bタンク設定値=0 or 浸漬タンクB米無し) then
		
		if not(配米終了フラグ) then
			配米終了フラグ=ON
			tmsg運転準備完了消去=OFF 'tmsg運転準備完了消去 tmsg運転準備完了とIDが同じのため ON中の消去をOFF状態にする 
			tmsg配米完了表示=ON '配米完了表示
			tmsg配米完了消去=OFF '配米完了消去		
		else 	
			if tmsg配米完了表示 then
				if pnlPBOK or pnlPB戻る then
					tmsg配米完了表示=OFF '配米完了表示
					tmsg配米完了消去=ON '配米完了消去		
				end if			
			end if
		end if

		if ldp(DM_排出残数=0) then
			炊飯完了からの釜カウント=5
		end if


		if DM_排出残数<=0 or tmsg炊飯完了表示 then
			
		
			if 炊飯完了停止【済】 then
				'tmsg自動運転停止警告表示=OFF
				'tmsg自動運転停止警告消去=ON
				
				'終了処理 ->
				tmsg炊飯完了表示=OFF '炊飯完了通知
				tmsg炊飯完了消去=ON  '炊飯完了通知

				IND_炊飯完了=OFF
				IND_停止待機=OFF				
						
				浸漬時間計測タンクA=OFF
				浸漬時間計測タンクB=OFF
						
			else
				IND_炊飯中=OFF
				IND_炊飯完了=ON
				if 炊飯完了からの釜カウント>0 then
					IND_停止待機=CR2006
				else
					IND_停止待機=ON
				end if

				select case 炊飯完了からの釜カウント
				case 0
					IND_EndCnt1=OFF
					IND_EndCnt2=OFF
					IND_EndCnt3=OFF
					IND_EndCnt4=OFF
					IND_EndCnt5=OFF
					IND_EndCnt6=OFF
					IND_EndCnt7=OFF
					IND_EndCnt8=OFF
					
					if 自動停止設定 then
						自動停止=ON
					else 
						自動停止=OFF
					end if
					IND_自動停止可能=ON
					
				case 1
					IND_EndCnt1=ON
					IND_EndCnt2=OFF
					IND_EndCnt3=OFF
					IND_EndCnt4=OFF
					IND_EndCnt5=OFF
					IND_EndCnt6=OFF
					IND_EndCnt7=OFF
					IND_EndCnt8=OFF
				case 2
					IND_EndCnt1=ON
					IND_EndCnt2=ON
					IND_EndCnt3=OFF
					IND_EndCnt4=OFF
					IND_EndCnt5=OFF
					IND_EndCnt6=OFF
					IND_EndCnt7=OFF
					IND_EndCnt8=OFF
				case 3
					IND_EndCnt1=ON
					IND_EndCnt2=ON
					IND_EndCnt3=ON
					IND_EndCnt4=OFF
					IND_EndCnt5=OFF
					IND_EndCnt6=OFF
					IND_EndCnt7=OFF
					IND_EndCnt8=OFF
				case 4
					IND_EndCnt1=ON
					IND_EndCnt2=ON
					IND_EndCnt3=ON
					IND_EndCnt4=ON
					IND_EndCnt5=OFF
					IND_EndCnt6=OFF
					IND_EndCnt7=OFF
					IND_EndCnt8=OFF
				case 5
					IND_EndCnt1=ON
					IND_EndCnt2=ON
					IND_EndCnt3=ON
					IND_EndCnt4=ON
					IND_EndCnt5=ON
					IND_EndCnt6=OFF
					IND_EndCnt7=OFF
					IND_EndCnt8=OFF				
				end select

				MainStatusMsg=#120 '停止準備中		
				'tmsg自動運転停止警告表示=ON
				'tmsg自動運転停止警告消去=OFF
				
				tmsg炊飯完了表示=ON '炊飯完了通知
				tmsg炊飯完了消去=OFF '炊飯完了通知

				if not(PB23_自動停止) or not(PB35_停止) or not(PB37_停止) or 自動停止 or 洗浄禁止 then
					'tmsg自動運転停止警告表示=OFF
					'tmsg自動運転停止警告消去=ON
					
					tmsg炊飯完了表示=OFF '炊飯完了通知
					tmsg炊飯完了消去=ON '炊飯完了通知
					運転準備完了=OFF
					炊飯完了停止【済】=ON '->終了
					
					pnlPB強制米無しA=OFF
					pnlPB強制米無しB=OFF

				end if				
			end if
			
		end if
	
	else
		配米終了フラグ=OFF
	
		炊飯機消火警告【済】=OFF
		炊飯完了停止【済】=OFF
		
		tmsg配米完了表示=OFF
		tmsg配米完了消去=OFF


	end if
	
	
else '運転準備=OFF 運転準備完了=OFF
	IND_配米準備=OFF
	IND_配米中=OFF
	'IND_炊飯中=OFF
	IH搬入炊飯釜カウント=0
	IND_炊飯完了=OFF
	IND_停止待機=OFF
	
	自動停止=OFF
	IND_自動停止可能=OFF
	
	ITEM登録禁止=ON

	
	
	if not(PB23_自動停止) then

		メインTP_切替ページＮｏ=21

		'tmsgxxxx=OFF
		tmsg運転準備開始確認=OFF
		tmsg運転準備完了=OFF
		
		tmsg自動運転停止警告表示=OFF			
		tmsg自動運転停止警告消去=ON
		
		tmsg炊飯完了表示=OFF
		tmsg炊飯完了消去=ON
		
		IND_配米準備=OFF
		IND_配米中=OFF
		'IND_炊飯中=OFF
		IH搬入炊飯釜カウント=0
		IND_炊飯完了=OFF
		IND_停止待機=OFF



	else 
	
		if メインTP_切替ページＮｏ=15 then

			
			tmsg運転準備開始確認=OFF
			
			tmsg運転準備完了=OFF '配米始まり
			tmsg運転準備完了消去=OFF'配米始まり
			tmsg配米完了表示=OFF
			tmsg配米完了消去=OFF
			tmsg検温停止中表示=OFF
			tmsg検温停止中消去=OFF
			tmsg炊飯完了表示 =OFF
			tmsg炊飯完了消去=OFF
			
			
			msg検温停止中表示=OFF
			msg検温停止中消去=OFF

			if 排水栓確認【済】 and 換気設備確認【済】 and 浸漬タンク米投入確認【済】 then
				if pnlPBOK then
				
					運転準備中=ON
					運転準備完了=OFF
					メインTP_切替ページＮｏ15【済】=ON
					換気設備確認【済】=OFF
					浸漬タンク米投入確認【済】=OFF
					排水栓確認【済】=OFF
					
	
				end if
			end if

		else if ldp(PB22_自動運転) and PB23_自動停止 and 自動搬送AutoMode then
			
			'運転準備のための初期設定
			メインTP_切替ページＮｏ=15
			
			'xxx【済】=OFF
			メインTP_切替ページＮｏ15【済】=OFF
			換気設備確認【済】=OFF
			浸漬タンク米投入確認【済】=OFF
			浸漬タンク米投入確認【済】=OFF
			排水栓確認【済】=OFF					

			運転準備開始確認【済】=OFF
			炊飯機点火実行確認【済】=OFF
			配米終了フラグ=OFF

			
		else		
			if not(Main手順初期化) then
				
				洗浄タンクAutoMode=OFF
				洗浄タンクAutoRun=OFF
				
				Main手順初期化=ON
			end if

			if not(運転準備初期化) then
				
				排水栓確認【済】=OFF
				換気設備確認【済】=OFF
				浸漬タンク米投入確認【済】=OFF

				配米終了フラグ=OFF
				
				メインTP_切替ページＮｏ=21
				メインTP_切替ページＮｏ15【済】=OFF
			
				運転準備初期化=ON

			end if
			

			加水釜数現在値=0
			配米準備釜数現在値=0
			DM_A配米現在値=0
			DM_B配米現在値=0
			DM_排出総数=0
			加水釜数=0

			消火警告までの残釜数=0
			搬送釜数=0
			空釜搬送釜数=0
			釜カウントA=0
			釜カウントB=0
			

			運転準備中=OFF
			運転準備完了=OFF
			検温待ち停止=OFF


		end if
		
	end if
	
end if

end if
'===================================================================================================================
'表示信号がONのとき、消去信号をすべてOFFにする。
tmr(tブザー警報,tim_tブザー警報,#20)
ブザー警報=tブザー警報 and not(tim_tブザー警報.B) 

if tmsg運転準備完了 or tmsg配米完了表示 or tmsg検温停止中表示 or tmsg炊飯完了表示 then

	tブザー警報=ON
	tmsg運転準備完了消去=OFF
	tmsg配米完了消去=OFF
	tmsg検温停止中消去=OFF
	tmsg炊飯完了消去=OFF

else
	tブザー警報=OFF
end if

'===================================================================================================================
'msg信号(1sec)確定出力
if (20<=メインTP_表示中ページNo and メインTP_表示中ページNo<=24) and (20<=サブTP_表示中ページNo and サブTP_表示中ページNo<=24) and (20<=むらしTP_表示中ページNo and むらしTP_表示中ページNo<=24) then

	tmr(tmsg運転準備開始確認,tim_tmsg運転準備開始確認,10)
	msg運転準備開始確認=tmsg運転準備開始確認 and not(tim_tmsg運転準備開始確認.B)
	tmr(tmsg運転準備開始確認消去,tim_tmsg運転準備開始確認消去,20)
	msg運転準備開始確認消去=tmsg運転準備開始確認消去 and not(tim_tmsg運転準備開始確認消去.B)

	'---
	tmr(tmsg運転準備完了,tim_tmsg運転準備完了,20)
	msg運転準備完了=tmsg運転準備完了 and not(tim_tmsg運転準備完了.B)
	tmr(tmsg運転準備完了消去,tim_tmsg運転準備完了消去,20)
	msg運転準備完了消去=tmsg運転準備完了消去 and not(tim_tmsg運転準備完了消去.B)
	'---
	tmr(tmsg炊飯完了表示,tim_tmsg炊飯完了表示,10)
	msg炊飯完了表示=tmsg炊飯完了表示 and not(tim_tmsg炊飯完了表示.B)
	tmr(tmsg炊飯完了消去,tim_tmsg炊飯完了消去,10)
	msg炊飯完了消去=tmsg炊飯完了消去 and not(tim_tmsg炊飯完了消去.B)
	'---
	tmr(tmsg配米完了表示,tim_tmsg配米完了表示,10)
	msg配米完了表示=tmsg配米完了表示 and not(tim_tmsg配米完了表示.B)
	tmr(tmsg配米完了消去,tim_tmsg配米完了消去,10)
	msg配米完了消去=tmsg配米完了消去 and not(tim_tmsg配米完了消去.B)
	'---
	tmr(tmsg検温停止中表示,tim_tmsg検温停止中表示,10)
	msg検温停止中表示=tmsg検温停止中表示 and not(tim_tmsg検温停止中表示.B)
	tmr(tmsg検温停止中消去,tim_tmsg検温停止中消去,10)
	msg検温停止中消去=tmsg検温停止中消去 and not(tim_tmsg検温停止中消去.B)

else

	msg運転準備開始確認=OFF
	msg運転準備開始確認消去=ON
	
	msg炊飯機点火実行警告=OFF
	
	msg運転準備完了=OFF
	msg運転準備完了消去=ON
	
	msg配米完了表示=OFF	
	msg配米完了消去=ON
	
	msg炊飯完了表示=OFF
	msg炊飯完了消去=ON
	
	msg炊飯機消火警告表示=OFF
	msg炊飯機消火警告消去=ON

end if

tmr(msgFleshCycl,#40)
if ldp(msgFleshCycl.B) then
	res(msgFleshCycl)

	res(tim_tmsg運転準備開始確認)
	res(tim_tmsg運転準備開始確認消去)	
	res(tim_tmsg運転準備完了)
	res(tim_tmsg運転準備完了消去)
	res(tim_tmsg炊飯完了表示)
	res(tim_tmsg炊飯完了消去)
	res(tim_tmsg配米完了表示)
	res(tim_tmsg配米完了消去)
	res(tim_tmsg検温停止中表示)
	res(tim_tmsg検温停止中消去)

end if


'===================================================================================================================
'パトライト

	PTL1_パトライト赤=パトライト赤 and CR2006
	PTL2_パトライト赤=パトライト赤 and CR2006
	PTL3_パトライト赤=パトライト赤 and CR2006
	PTL4_パトライト赤=パトライト赤 and CR2006
	PTL5_パトライト赤=パトライト赤 and CR2006
	'
	PTL1_パトライト黄=パトライト黄 and CR2006
	PTL2_パトライト黄=パトライト黄 and CR2006
	PTL3_パトライト黄=パトライト黄 and CR2006
	PTL4_パトライト黄=パトライト黄 and CR2006
	PTL5_パトライト黄=パトライト黄 and CR2006
	'
	PTL1_パトライト青=パトライト青 and CR2006
	PTL2_パトライト青=パトライト青 and CR2006
	PTL3_パトライト青=パトライト青 and CR2006
	PTL4_パトライト青=パトライト青 and CR2006
	PTL5_パトライト青=パトライト青 and CR2006
	'
	PTL1_パトライトブザー=PBL非常停止 or (ブザー警報 and CR2006) 
	PTL2_パトライトブザー=PBL非常停止 or (ブザー警報 and CR2006) 
	PTL3_パトライトブザー=PBL非常停止 or (ブザー警報 and CR2006) 
	PTL4_パトライトブザー=PBL非常停止 or (ブザー警報 and CR2006) 
	PTL5_パトライトブザー=PBL非常停止 or (ブザー警報 and CR2006) 


	if 自動搬送ErrStep<>0 then
		パトライト赤=ON
		パトライト黄=OFF
		パトライト青=OFF	
	else if OtherErrStep<>0 then
		パトライト赤=OFF
		パトライト黄=ON
		パトライト青=OFF
	else if 自動搬送AutoRun then
		パトライト赤=OFF
		パトライト黄=OFF
		パトライト青=ON
	else
		パトライト赤=OFF
		パトライト黄=OFF
		パトライト青=OFF	
	end if	
	

' PLインジケータ

	PBL22_自動運転=(運転準備中 and CR2006) or (運転準備完了 and 自動搬送AutoRun)
	
	'--------------------------------
	if 自動搬送AutoRun then
		PL9_運転中=ON
		PL11_運転中=ON
		PL21_運転中=ON
	else
		if OtherStep<>0 then
			if CR2006 then
				PL9_運転中=ON
				PL11_運転中=ON
				PL21_運転中=ON
			else
				PL9_運転中=OFF
				PL11_運転中=OFF
				PL21_運転中=OFF
			end if
		else
			PL9_運転中=OFF
			PL11_運転中=OFF
			PL21_運転中=OFF
		end if		
	end if

	'--------------------------------
	if 自動搬送ErrStep<>0 or OtherErrStep<>0  then

		if CR2006 then
			PL10_異常=ON
			PL12_異常=ON
			PL16_異常=ON
		else
			PL10_異常=OFF
			PL12_異常=OFF
			PL16_異常=OFF
		end if

	else
		PL10_異常=OFF
		PL12_異常=OFF
		PL16_異常=OFF
	end if
	'--------------------------------
	
'===================================================================================================================
' 光電センサ電源OFF
if 自動搬送AutoMode or 自動搬送AutoRun or OtherStep<>0 then
	RLY_光電センサ電源OFF1=OFF
	RLY_光電センサ電源OFF2=OFF
	RLY_光電センサ電源OFF3=OFF
	RLY_光電センサ電源OFF4=OFF
	RLY_光電センサ電源OFF5=OFF
	RLY_光電センサ電源OFF6=OFF
	RLY_光電センサ電源OFF7=OFF

else
	if ldp(pnlPBRLY_光電センサ電源OFF1) then
		if RLY_光電センサ電源OFF1=ON then
			RLY_光電センサ電源OFF1=OFF
		else
			RLY_光電センサ電源OFF1=ON
		end if
	end if
	if ldp(pnlPBRLY_光電センサ電源OFF2) then
		if RLY_光電センサ電源OFF2=ON then
			RLY_光電センサ電源OFF2=OFF
		else
			RLY_光電センサ電源OFF2=ON
		end if
	end if
	if ldp(pnlPBRLY_光電センサ電源OFF3) then
		if RLY_光電センサ電源OFF3=ON then
			RLY_光電センサ電源OFF3=OFF
		else
			RLY_光電センサ電源OFF3=ON
		end if
	end if
	if ldp(pnlPBRLY_光電センサ電源OFF4) then
		if RLY_光電センサ電源OFF4=ON then
			RLY_光電センサ電源OFF4=OFF
		else
			RLY_光電センサ電源OFF4=ON
		end if
	end if
	if ldp(pnlPBRLY_光電センサ電源OFF5) then
		if RLY_光電センサ電源OFF5=ON then
			RLY_光電センサ電源OFF5=OFF
		else
			RLY_光電センサ電源OFF5=ON
		end if
	end if
	if ldp(pnlPBRLY_光電センサ電源OFF6) then
		if RLY_光電センサ電源OFF6=ON then
			RLY_光電センサ電源OFF6=OFF
		else
			RLY_光電センサ電源OFF6=ON
		end if
	end if
	if ldp(pnlPBRLY_光電センサ電源OFF7) then
		if RLY_光電センサ電源OFF7=ON then
			RLY_光電センサ電源OFF7=OFF
		else
			RLY_光電センサ電源OFF7=ON
		end if
	end if
end if

'===================================================================================================================
'非常停止フラグ
	PB非常停止=PB非常停止メイン and PB非常停止むらし and PB非常停止サブ and PB26_コンベア停止 and PB27_コンベア停止 and PB28_コンベア停止 and PB29_コンベア停止
	PBL非常停止 = not(PB非常停止) and CR2006
	EmgFlg=not(PB非常停止) or EmgFlg
	if not(PB非常停止) then
		自動搬送EmgStep=1
	end if
	
'リセットフラグ
	ResetFlg=PB34_リセット or PB24_リセット or PB38_リセット



'===================================================================================================================
'ステージシグナル 
'===================================================================================================================
OtherOrgErr= 浸漬タンクAユニットOrgErr
OtherOrgErr= OtherOrgErr or 浸漬タンクBユニットOrgErr
OtherOrgErr= OtherOrgErr or 計水ユニットOrgErr
OtherOrgErr= OtherOrgErr or ならしユニットOrgErr
OtherOrgErr= OtherOrgErr or 蓋被せユニットOrgErr
OtherOrgErr= OtherOrgErr or 蓋取りユニットOrgErr
OtherOrgErr= OtherOrgErr or ほぐし機AユニットOrgErr
OtherOrgErr= OtherOrgErr or 搬送コンベアAOrgErr
OtherOrgErr= OtherOrgErr or 搬送コンベアBOrgErr
OtherOrgErr= OtherOrgErr or 搬送コンベアCOrgErr
OtherOrgErr= OtherOrgErr or 搬送コンベアC2OrgErr
OtherOrgErr= OtherOrgErr or 搬送コンベアDOrgErr
OtherOrgErr= OtherOrgErr or 搬送コンベアEOrgErr
'OtherOrgErr= OtherOrgErr or 搬送コンベアF1OrgErr
'OtherOrgErr= OtherOrgErr or 搬送コンベアF2OrgErr
OtherOrgErr= OtherOrgErr or 搬送コンベアGOrgErr
OtherOrgErr= OtherOrgErr or 搬送コンベアHOrgErr
OtherOrgErr= OtherOrgErr or 釜フタ昇降装置AOrgErr
OtherOrgErr= OtherOrgErr or 釜反転入口OrgErr
OtherOrgErr= OtherOrgErr or 洗浄ユニットOrgErr
'OtherOrgErr= OtherOrgErr or 洗浄タンクOrgErr
OtherOrgErr= OtherOrgErr or 洗浄コンベア搬送OrgErr
OtherOrgErr= OtherOrgErr or 釜反転出口OrgErr
OtherOrgErr= OtherOrgErr or 釜フタ昇降装置BOrgErr
'OtherOrgErr= OtherOrgErr or IH炊飯ユニットAOrgErr
'OtherOrgErr= OtherOrgErr or IH炊飯ユニットBOrgErr

'===================================================================================================================
OtherErr= 浸漬タンクAユニットErr
OtherErr= OtherErr or 浸漬タンクBユニットErr
OtherErr= OtherErr or 計水ユニットErr
OtherErr= OtherErr or ならしユニットErr
OtherErr= OtherErr or 蓋被せユニットErr
OtherErr= OtherErr or 蓋取りユニットErr
OtherErr= OtherErr or ほぐし機AユニットErr
OtherErr= OtherErr or 搬送コンベアAErr
OtherErr= OtherErr or 搬送コンベアBErr
OtherErr= OtherErr or 搬送コンベアCErr
OtherErr= OtherErr or 搬送コンベアC2Err
OtherErr= OtherErr or 搬送コンベアDErr
OtherErr= OtherErr or 搬送コンベアEErr
OtherErr= OtherErr or 搬送コンベアF1Err
OtherErr= OtherErr or 搬送コンベアF2Err
OtherErr= OtherErr or 搬送コンベアGErr
OtherErr= OtherErr or 搬送コンベアHErr
OtherErr= OtherErr or 釜フタ昇降装置AErr
OtherErr= OtherErr or 釜反転入口Err
OtherErr= OtherErr or 洗浄ユニットErr
'OtherErr= OtherErr or 洗浄タンクErr
OtherErr= OtherErr or 洗浄コンベア搬送Err
OtherErr= OtherErr or 釜反転出口Err
OtherErr= OtherErr or 釜フタ昇降装置BErr
'OtherErr= OtherErr or IH炊飯ユニットAErr
'OtherErr= OtherErr or IH炊飯ユニットBErr
'==================================================================================================================
OtherEmg= 浸漬タンクAユニットEmg
OtherEmg= OtherEmg or 浸漬タンクBユニットEmg
OtherEmg= OtherEmg or 計水ユニットEmg
OtherEmg= OtherEmg or ならしユニットEmg
OtherEmg= OtherEmg or 蓋被せユニットEmg
OtherEmg= OtherEmg or 蓋取りユニットEmg
OtherEmg= OtherEmg or ほぐし機AユニットEmg
OtherEmg= OtherEmg or 搬送コンベアAEmg
OtherEmg= OtherEmg or 搬送コンベアBEmg
OtherEmg= OtherEmg or 搬送コンベアCEmg
OtherEmg= OtherEmg or 搬送コンベアC2Emg
OtherEmg= OtherEmg or 搬送コンベアDEmg
OtherEmg= OtherEmg or 搬送コンベアEEmg
OtherEmg= OtherEmg or 搬送コンベアF1Emg
OtherEmg= OtherEmg or 搬送コンベアF2Emg
OtherEmg= OtherEmg or 搬送コンベアGEmg
OtherEmg= OtherEmg or 搬送コンベアHEmg
OtherEmg= OtherEmg or 釜フタ昇降装置AEmg
OtherEmg= OtherEmg or 釜反転入口Emg
OtherEmg= OtherEmg or 洗浄ユニットEmg
'OtherEmg= OtherEmg or 洗浄タンクEmg
OtherEmg= OtherEmg or 洗浄コンベア搬送Emg
OtherEmg= OtherEmg or 釜反転出口Emg
OtherEmg= OtherEmg or 釜フタ昇降装置BEmg
'OtherEmg= OtherEmg or IH炊飯ユニットAEmg
'OtherEmg= OtherEmg or IH炊飯ユニットBEmg
'===================================================================================================================
OtherOrg= 浸漬タンクAユニットOrg
OtherOrg= OtherOrg and 浸漬タンクBユニットOrg
OtherOrg= OtherOrg and 計水ユニットOrg
OtherOrg= OtherOrg and ならしユニットOrg
OtherOrg= OtherOrg and 蓋被せユニットOrg
OtherOrg= OtherOrg and 蓋取りユニットOrg
OtherOrg= OtherOrg and ほぐし機AユニットOrg
OtherOrg= OtherOrg and 搬送コンベアAOrg
OtherOrg= OtherOrg and 搬送コンベアBOrg
OtherOrg= OtherOrg and 搬送コンベアCOrg
OtherOrg= OtherOrg and 搬送コンベアC2Org
OtherOrg= OtherOrg and 搬送コンベアDOrg
OtherOrg= OtherOrg and 搬送コンベアEOrg
'OtherOrg= OtherOrg and 搬送コンベアF1Org
'OtherOrg= OtherOrg and 搬送コンベアF2Org
OtherOrg= OtherOrg and 搬送コンベアGOrg
OtherOrg= OtherOrg and 搬送コンベアHOrg
if not(洗浄禁止) then
	OtherOrg= OtherOrg and 釜フタ昇降装置AOrg
	OtherOrg= OtherOrg and 釜反転入口Org
	OtherOrg= OtherOrg and 洗浄ユニットOrg
	'OtherOrg= OtherOrg and 洗浄タンクOrg
	OtherOrg= OtherOrg and 洗浄コンベア搬送Org
	OtherOrg= OtherOrg and 釜反転出口Org
	OtherOrg= OtherOrg and 釜フタ昇降装置BOrg
end if
OtherOrg= OtherOrg and IH炊飯ユニットAOrg
OtherOrg= OtherOrg and IH炊飯ユニットBOrg
'===================================================================================================================
OtherStep= 浸漬タンクAユニットStep
OtherStep= OtherStep or 浸漬タンクBユニットStep
OtherStep= OtherStep or 計水ユニットStep
OtherStep= OtherStep or ならしユニットStep
OtherStep= OtherStep or 蓋被せユニットStep
OtherStep= OtherStep or 蓋取りユニットStep
OtherStep= OtherStep or ほぐし機AユニットStep
OtherStep= OtherStep or 搬送コンベアAStep
OtherStep= OtherStep or 搬送コンベアBStep
OtherStep= OtherStep or 搬送コンベアCStep
OtherStep= OtherStep or 搬送コンベアC2Step
OtherStep= OtherStep or 搬送コンベアDStep
OtherStep= OtherStep or 搬送コンベアEStep
'OtherStep= OtherStep or 搬送コンベアF1Step
'OtherStep= OtherStep or 搬送コンベアF2Step
OtherStep= OtherStep or 搬送コンベアGStep
OtherStep= OtherStep or 搬送コンベアHStep
OtherStep= OtherStep or 釜フタ昇降装置AStep
OtherStep= OtherStep or 釜反転入口Step
OtherStep= OtherStep or 洗浄ユニットStep
'OtherStep= OtherStep or 洗浄タンクStep
OtherStep= OtherStep or 洗浄コンベア搬送Step
OtherStep= OtherStep or 釜反転出口Step
OtherStep= OtherStep or 釜フタ昇降装置BStep
'OtherStep= OtherStep or IH炊飯ユニットAStep
'OtherStep= OtherStep or IH炊飯ユニットBStep
'===================================================================================================================
OtherOrgErrStep=浸漬タンクAユニットOrgErrStep
OtherOrgErrStep= ORA(OtherOrgErrStep,浸漬タンクBユニットOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,計水ユニットOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,ならしユニットOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,蓋被せユニットOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,蓋取りユニットOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,ほぐし機AユニットOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,搬送コンベアAOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,搬送コンベアBOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,搬送コンベアCOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,搬送コンベアC2OrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,搬送コンベアDOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,搬送コンベアEOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,搬送コンベアF1OrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,搬送コンベアF2OrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,搬送コンベアGOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,搬送コンベアHOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,釜フタ昇降装置AOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,釜反転入口OrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,洗浄ユニットOrgErrStep)
'OtherOrgErrStep= ORA(OtherOrgErrStep,洗浄タンクOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,洗浄コンベア搬送OrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,釜反転出口OrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,釜フタ昇降装置BOrgErrStep)
'OtherOrgErrStep= ORA(OtherOrgErrStep,IH炊飯ユニットAOrgErrStep)
'OtherOrgErrStep= ORA(OtherOrgErrStep,IH炊飯ユニットBOrgErrStep)
'===================================================================================================================
OtherErrStep=浸漬タンクAユニットErrStep
OtherErrStep= ORA(OtherErrStep,浸漬タンクBユニットErrStep)
OtherErrStep= ORA(OtherErrStep,計水ユニットErrStep)
OtherErrStep= ORA(OtherErrStep,ならしユニットErrStep)
OtherErrStep= ORA(OtherErrStep,蓋被せユニットErrStep)
OtherErrStep= ORA(OtherErrStep,蓋取りユニットErrStep)
OtherErrStep= ORA(OtherErrStep,ほぐし機AユニットErrStep)
OtherErrStep= ORA(OtherErrStep,搬送コンベアAErrStep)
OtherErrStep= ORA(OtherErrStep,搬送コンベアBErrStep)
OtherErrStep= ORA(OtherErrStep,搬送コンベアCErrStep)
OtherErrStep= ORA(OtherErrStep,搬送コンベアC2ErrStep)
OtherErrStep= ORA(OtherErrStep,搬送コンベアDErrStep)
OtherErrStep= ORA(OtherErrStep,搬送コンベアEErrStep)
OtherErrStep= ORA(OtherErrStep,搬送コンベアF1ErrStep)
OtherErrStep= ORA(OtherErrStep,搬送コンベアF2ErrStep)
OtherErrStep= ORA(OtherErrStep,搬送コンベアGErrStep)
OtherErrStep= ORA(OtherErrStep,搬送コンベアHErrStep)
OtherErrStep= ORA(OtherErrStep,釜フタ昇降装置AErrStep)
OtherErrStep= ORA(OtherErrStep,釜反転入口ErrStep)
OtherErrStep= ORA(OtherErrStep,洗浄ユニットErrStep)
'OtherErrStep= ORA(OtherErrStep,洗浄タンクErrStep)
OtherErrStep= ORA(OtherErrStep,洗浄コンベア搬送ErrStep)
OtherErrStep= ORA(OtherErrStep,釜反転出口ErrStep)
OtherErrStep= ORA(OtherErrStep,釜フタ昇降装置BErrStep)
OtherErrStep= ORA(OtherErrStep,IH炊飯ユニットAErrStep)
OtherErrStep= ORA(OtherErrStep,IH炊飯ユニットBErrStep)
'===================================================================================================================
OtherEmgStep=浸漬タンクAユニットEmgStep
OtherEmgStep= ORA(OtherEmgStep,浸漬タンクBユニットEmgStep)
OtherEmgStep= ORA(OtherEmgStep,計水ユニットEmgStep)
OtherEmgStep= ORA(OtherEmgStep,ならしユニットEmgStep)
OtherEmgStep= ORA(OtherEmgStep,蓋被せユニットEmgStep)
OtherEmgStep= ORA(OtherEmgStep,蓋取りユニットEmgStep)
OtherEmgStep= ORA(OtherEmgStep,ほぐし機AユニットEmgStep)
OtherEmgStep= ORA(OtherEmgStep,搬送コンベアAEmgStep)
OtherEmgStep= ORA(OtherEmgStep,搬送コンベアBEmgStep)
OtherEmgStep= ORA(OtherEmgStep,搬送コンベアCEmgStep)
OtherEmgStep= ORA(OtherEmgStep,搬送コンベアC2EmgStep)
OtherEmgStep= ORA(OtherEmgStep,搬送コンベアDEmgStep)
OtherEmgStep= ORA(OtherEmgStep,搬送コンベアEEmgStep)
OtherEmgStep= ORA(OtherEmgStep,搬送コンベアF1EmgStep)
OtherEmgStep= ORA(OtherEmgStep,搬送コンベアF2EmgStep)
OtherEmgStep= ORA(OtherEmgStep,搬送コンベアGEmgStep)
OtherEmgStep= ORA(OtherEmgStep,搬送コンベアHEmgStep)
OtherEmgStep= ORA(OtherEmgStep,釜フタ昇降装置AEmgStep)
OtherEmgStep= ORA(OtherEmgStep,釜反転入口EmgStep)
OtherEmgStep= ORA(OtherEmgStep,洗浄ユニットEmgStep)
'OtherEmgStep= ORA(OtherEmgStep,洗浄タンクEmgStep)
OtherEmgStep= ORA(OtherEmgStep,洗浄コンベア搬送EmgStep)
OtherEmgStep= ORA(OtherEmgStep,釜反転出口EmgStep)
OtherEmgStep= ORA(OtherEmgStep,釜フタ昇降装置BEmgStep)
'OtherEmgStep= ORA(OtherEmgStep,IH炊飯ユニットAEmgStep)
'OtherEmgStep= ORA(OtherEmgStep,IH炊飯ユニットBEmgStep)
'==================================================================================================================
'【  デバイスへの給電  】


'	if 前処理工程AutoRun or 浸漬タンクAユニットAutoRun or 浸漬タンクBユニットAutoRun then
'		RLY5_パドルセンサ電源=ON
'	else
'		RLY5_パドルセンサ電源=OFF
'	end if

	mMC1_インバータ用電源=ON

	'RLY_投光側電源OFF=ON

'===================================================================================================================
'【 初期化処理 】
if CR2008 then

    自動搬送AutoMode=OFF
    自動搬送OrgErr=OFF
    自動搬送Err=OFF
    自動搬送Emg=OFF
    自動搬送step=0
    自動搬送ErrStep=0
    自動搬送OrgErrStep=0
    自動搬送EmgStep=0
	
	OtherEmgStep=0
	OtherErrStep=0
	OtherOrgErr=0
	
	自動搬送手動許可step=0
	
end if

'===================================================================================================================
'【 緊急停止 】
if 自動搬送Emg  then
	自動搬送EmgStep=1
end if

'===================================================================================================================


'===================================================================================================================
'  コマンド処理
'===================================================================================================================
' 自動搬送コマンド処理
'
if 自動搬送EmgStep=0 and OtherEmgStep=0 then  
	
	if 自動搬送ErrStep=0  and OtherErrStep=0 then
	
		if not(自動搬送OrgErr) and not(OtherOrgErr) then

			if not(PB23_自動停止) or not(PB35_停止) or not(PB37_停止)  or 自動搬送停止 or 自動停止 or ldp(検温待ち停止) or pnlPB停止 then
			
				自動停止=OFF
			
				自動搬送AutoRun=OFF

				浸漬タンクAAutoRun=OFF
				浸漬タンクBAutoRun=OFF
				浸漬タンクAユニットAutoRun=OFF
				浸漬タンクBユニットAutoRun=OFF
				計水ユニットAutoRun=OFF
				ならしユニットAutoRun=OFF
				蓋被せユニットAutoRun=OFF
				蓋取りユニットAutoRun=OFF
				ほぐし機AユニットAutoRun=OFF
				搬送コンベアAAutoRun=OFF
				搬送コンベアBAutoRun=OFF
				搬送コンベアCAutoRun=OFF
				搬送コンベアC2AutoRun=OFF
				搬送コンベアDAutoRun=OFF
				搬送コンベアEAutoRun=OFF
				搬送コンベアF1AutoRun=OFF
				搬送コンベアF2AutoRun=OFF
				搬送コンベアGAutoRun=OFF
				搬送コンベアHAutoRun=OFF
				釜フタ昇降装置AAutoRun=OFF
				釜反転入口AutoRun=OFF
				洗浄ユニットAutoRun=OFF
				洗浄タンクAutoRun=OFF
				洗浄コンベア搬送AutoRun=OFF
				釜反転出口AutoRun=OFF
				釜フタ昇降装置BAutoRun=OFF

			else
				'-------------------------------------------------------------------------------------
				'メイン              むらし                  洗浄機
				'SSW3_自動モード     SSW1_2_運転切換（連動） SEL2_2_運転切換（連動）
				'-------------------------------------------------------------------------------------
				' 自動搬送 自動 - 手動  (2ステップ切り替え）
				'メイン操作ボックス部 SSW3_手動モード  SSW3_自動モード
				if 	not(自動搬送手動切替済み) and SSW3_手動モード and  not(SSW3_自動モード) then
				
					select case 自動搬送手動許可step
					case 0
						自動搬送手動要求=ON
						inc(自動搬送手動許可step)
					case 1
						if 自動搬送手動許可 then

							自動搬送AutoMode=OFF
				
							'前処理工程AutoMode=OFF
							'前処理工程AutoRun=OFF
							'計量AutoRun=OFF
							
							'if 即時運転モード and (計量step<>0 or 洗米step<>0) then
							'	即時運転モードEndWait=ON
							'end if
							'即時運転モード=OFF
							
							'if 予約運転モード and (計量step<>0 or 洗米step<>0) then
							'	予約運転モードEndWait=ON
							'end if
							'予約運転モード=OFF

							inc(自動搬送手動許可step)
						else if 自動搬送手動禁止 then
							自動搬送AutoMode=ON
							inc(自動搬送手動許可step)
						end if						
					case 2
						自動搬送手動要求=OFF
						inc(自動搬送手動許可step)
					case 3
						自動搬送手動切替済み=ON
						inc(自動搬送手動許可step)
						'自動搬送手動許可step=0
						
					end select
				
				else if SSW3_自動モード and not(SSW3_手動モード) then
					自動搬送手動切替済み=OFF
					自動搬送手動許可step=0
					自動搬送手動要求=OFF
					自動搬送AutoMode=ON
				end if
				'-------------------------------------------------------------------------------------
				' 起動
				if not(OtherOrg) then
					if 自動搬送AutoMode and OtherStep=0 then
						if (ldp(PB22_自動運転) or ldp(検温待ち停止解除) or ldp(pnlPB起動)) and (運転準備中 or 運転準備完了 or テスト運転) then
						
							浸漬タンクAユニットOrgErr=not(浸漬タンクAユニットOrg)
							浸漬タンクBユニットOrgErr=not(浸漬タンクBユニットOrg)
							計水ユニットOrgErr=not(計水ユニットOrg)
							ならしユニットOrgErr=not(ならしユニットOrg)
							蓋被せユニットOrgErr=not(蓋被せユニットOrg)
							蓋取りユニットOrgErr=not(蓋取りユニットOrg)
							ほぐし機AユニットOrgErr=not(ほぐし機AユニットOrg)
							搬送コンベアAOrgErr=not(搬送コンベアAOrg)
							搬送コンベアBOrgErr=not(搬送コンベアBOrg)
							搬送コンベアCOrgErr=not(搬送コンベアCOrg)
							搬送コンベアC2OrgErr=not(搬送コンベアC2Org)
							搬送コンベアDOrgErr=not(搬送コンベアDOrg)
							搬送コンベアEOrgErr=not(搬送コンベアEOrg)
							搬送コンベアF1OrgErr=not(搬送コンベアF1Org)
							搬送コンベアF2OrgErr=not(搬送コンベアF2Org)
							搬送コンベアGOrgErr=not(搬送コンベアGOrg)
							搬送コンベアHOrgErr=not(搬送コンベアHOrg)
							釜フタ昇降装置AOrgErr=not(釜フタ昇降装置AOrg)
							釜反転入口OrgErr=not(釜反転入口Org)
							洗浄ユニットOrgErr=not(洗浄ユニットOrg)
							'洗浄タンクOrgErr=not(洗浄タンクOrg)
							洗浄コンベア搬送OrgErr=not(洗浄コンベア搬送Org)
							釜反転出口OrgErr=not(釜反転出口Org)
							釜フタ昇降装置BOrgErr=not(釜フタ昇降装置BOrg)
							IH炊飯ユニットAOrgErr=not(IH炊飯ユニットAOrg)
							IH炊飯ユニットBOrgErr=not(IH炊飯ユニットBOrg)
					
						end if
						
					end if
				
				else if 自動搬送AutoMode and OtherStep=0 then
					if (ldp(PB22_自動運転) or ldp(検温待ち停止解除) or ldp(pnlPB起動))  and (運転準備中 or 運転準備完了 or テスト運転 ) then

						自動搬送AutoRun=ON

						'------------------------------------------------------
						浸漬タンクAAutoRun=ON
						浸漬タンクBAutoRun=ON
						浸漬タンクAユニットAutoRun=ON
						浸漬タンクBユニットAutoRun=ON
						計水ユニットAutoRun=ON
						ならしユニットAutoRun=ON
						蓋被せユニットAutoRun=ON
						蓋取りユニットAutoRun=ON
						ほぐし機AユニットAutoRun=ON
						搬送コンベアAAutoRun=ON
						搬送コンベアBAutoRun=ON
						搬送コンベアCAutoRun=ON
						搬送コンベアC2AutoRun=ON
						搬送コンベアDAutoRun=ON
						搬送コンベアEAutoRun=ON
						搬送コンベアF1AutoRun=ON
						搬送コンベアF2AutoRun=ON
						搬送コンベアGAutoRun=ON
						搬送コンベアHAutoRun=ON
					if not(洗浄禁止) then
						釜フタ昇降装置AAutoRun=ON
						釜反転入口AutoRun=ON
						洗浄ユニットAutoRun=ON
						洗浄タンクAutoRun=ON
						洗浄コンベア搬送AutoRun=ON
						釜反転出口AutoRun=ON
						釜フタ昇降装置BAutoRun=ON
					end if
						'------------------------------------------------------
						浸漬タンクAユニットstep=1
						浸漬タンクBユニットstep=1
						計水ユニットstep=1
						ならしユニットstep=1
						蓋被せユニットstep=1
						蓋取りユニットstep=1
						ほぐし機Aユニットstep=1
						搬送コンベアAstep=1
						搬送コンベアBstep=1
						搬送コンベアCstep=1
						搬送コンベアC2step=1
						搬送コンベアDstep=1
						搬送コンベアEstep=1
						搬送コンベアF1step=1
						搬送コンベアF2step=1
						搬送コンベアGstep=1
						搬送コンベアHstep=1
					if not(洗浄禁止) then
						釜フタ昇降装置Astep=1
						釜反転入口step=1
						洗浄ユニットstep=1
						洗浄タンクstep=1
						洗浄コンベア搬送step=1
						釜反転出口step=1
						釜フタ昇降装置Bstep=1
					end if
						'------------------------------------------------------
						搬送コンベアA動作中=OFF
						搬送コンベアB動作中=OFF
						搬送コンベアC動作中=OFF
						搬送コンベアC2動作中=OFF
						搬送コンベアD動作中=OFF
						搬送コンベアE動作中=OFF
						搬送コンベアF1動作中=OFF
						搬送コンベアF2動作中=OFF
						搬送コンベアG動作中=OFF
						搬送コンベアH動作中=OFF
						釜フタ昇降装置A動作中=OFF
						釜反転入口動作中=OFF
						洗浄コンベア搬送動作中=OFF
						釜反転出口動作中=OFF
						釜フタ昇降装置B動作中=OFF
						'------------------------------------------------------
						搬送コンベアA排出要求=OFF
						搬送コンベアB排出要求=OFF
						搬送コンベアC排出要求=OFF
						搬送コンベアC2排出要求=OFF
						搬送コンベアD排出要求=OFF
						搬送コンベアE排出要求=OFF
						搬送コンベアF1排出要求=OFF
						搬送コンベアF2排出要求=OFF
						搬送コンベアG排出要求=OFF
						搬送コンベアH排出要求=OFF
						釜フタ昇降装置A排出要求=OFF
						釜反転入口排出要求=OFF
						洗浄コンベア搬送排出要求=OFF
						釜反転出口排出要求=OFF
						釜フタ昇降装置B排出要求=OFF
						'------------------------------------------------------
					end if	
				end if				
				'-------------------------------------------------------------------------------------
				
			end if


	'==================================================================================================================
	'【 原点異常 】
	
	
		else

			'--------------------------------------------------------------------------------
			' 各モジュールへのResetFlg指令
			自動搬送AutoRun=OFF


			浸漬タンクAAutoRun=OFF
			浸漬タンクBAutoRun=OFF
			浸漬タンクAユニットAutoRun=OFF
			浸漬タンクBユニットAutoRun=OFF
			計水ユニットAutoRun=OFF
			ならしユニットAutoRun=OFF
			蓋被せユニットAutoRun=OFF
			蓋取りユニットAutoRun=OFF
			ほぐし機AユニットAutoRun=OFF
			搬送コンベアAAutoRun=OFF
			搬送コンベアBAutoRun=OFF
			搬送コンベアCAutoRun=OFF
			搬送コンベアC2AutoRun=OFF
			搬送コンベアDAutoRun=OFF
			搬送コンベアEAutoRun=OFF
			搬送コンベアF1AutoRun=OFF
			搬送コンベアF2AutoRun=OFF
			搬送コンベアGAutoRun=OFF
			搬送コンベアHAutoRun=OFF
			釜フタ昇降装置AAutoRun=OFF
			釜反転入口AutoRun=OFF
			洗浄ユニットAutoRun=OFF
			洗浄タンクAutoRun=OFF
			洗浄コンベア搬送AutoRun=OFF
			釜反転出口AutoRun=OFF
			釜フタ昇降装置BAutoRun=OFF

			if ResetFlg then

				浸漬タンクAユニットOrgErr=not(浸漬タンクAユニットOrg)
				浸漬タンクBユニットOrgErr=not(浸漬タンクBユニットOrg)
				計水ユニットOrgErr=not(計水ユニットOrg)
				ならしユニットOrgErr=not(ならしユニットOrg)
				蓋被せユニットOrgErr=not(蓋被せユニットOrg)
				蓋取りユニットOrgErr=not(蓋取りユニットOrg)
				ほぐし機AユニットOrgErr=not(ほぐし機AユニットOrg)
				搬送コンベアAOrgErr=not(搬送コンベアAOrg)
				搬送コンベアBOrgErr=not(搬送コンベアBOrg)
				搬送コンベアCOrgErr=not(搬送コンベアCOrg)
				搬送コンベアC2OrgErr=not(搬送コンベアC2Org)
				搬送コンベアDOrgErr=not(搬送コンベアDOrg)
				搬送コンベアEOrgErr=not(搬送コンベアEOrg)
				搬送コンベアF1OrgErr=not(搬送コンベアF1Org)
				搬送コンベアF2OrgErr=not(搬送コンベアF2Org)
				搬送コンベアGOrgErr=not(搬送コンベアGOrg)
				搬送コンベアHOrgErr=not(搬送コンベアHOrg)
				釜フタ昇降装置AOrgErr=not(釜フタ昇降装置AOrg)
				釜反転入口OrgErr=not(釜反転入口Org)
				洗浄ユニットOrgErr=not(洗浄ユニットOrg)
				'洗浄タンクOrgErr=not(洗浄タンクOrg)
				洗浄コンベア搬送OrgErr=not(洗浄コンベア搬送Org)
				釜反転出口OrgErr=not(釜反転出口Org)
				釜フタ昇降装置BOrgErr=not(釜フタ昇降装置BOrg)
				IH炊飯ユニットAOrgErr=not(IH炊飯ユニットAOrg)
				IH炊飯ユニットBOrgErr=not(IH炊飯ユニットBOrg)
			end if
		
		end if
	'==================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
					
			浸漬タンクAユニットOrgErr=OFF
			浸漬タンクBユニットOrgErr=OFF
			計水ユニットOrgErr=OFF
			ならしユニットOrgErr=OFF
			蓋被せユニットOrgErr=OFF
			蓋取りユニットOrgErr=OFF
			ほぐし機AユニットOrgErr=OFF
			搬送コンベアAOrgErr=OFF
			搬送コンベアBOrgErr=OFF
			搬送コンベアCOrgErr=OFF
			搬送コンベアC2OrgErr=OFF
			搬送コンベアDOrgErr=OFF
			搬送コンベアEOrgErr=OFF
			搬送コンベアF1OrgErr=OFF
			搬送コンベアF2OrgErr=OFF
			搬送コンベアGOrgErr=OFF
			搬送コンベアHOrgErr=OFF
			釜フタ昇降装置AOrgErr=OFF
			釜反転入口OrgErr=OFF
			洗浄ユニットOrgErr=OFF
			'洗浄タンクOrgErr=OFF
			洗浄コンベア搬送OrgErr=OFF
			釜反転出口OrgErr=OFF
			釜フタ昇降装置BOrgErr=OFF
			'IH炊飯ユニットAOrgErr=OFF
			'IH炊飯ユニットBOrgErr=OFF
	
	
			自動搬送AutoRun=OFF

			浸漬タンクAAutoRun=OFF
			浸漬タンクBAutoRun=OFF
			浸漬タンクAユニットAutoRun=OFF
			浸漬タンクBユニットAutoRun=OFF
			計水ユニットAutoRun=OFF
			ならしユニットAutoRun=OFF
			蓋被せユニットAutoRun=OFF
			蓋取りユニットAutoRun=OFF
			ほぐし機AユニットAutoRun=OFF
			搬送コンベアAAutoRun=OFF
			搬送コンベアBAutoRun=OFF
			搬送コンベアCAutoRun=OFF
			搬送コンベアC2AutoRun=OFF
			搬送コンベアDAutoRun=OFF
			搬送コンベアEAutoRun=OFF
			搬送コンベアF1AutoRun=OFF
			搬送コンベアF2AutoRun=OFF
			搬送コンベアGAutoRun=OFF
			搬送コンベアHAutoRun=OFF
			釜フタ昇降装置AAutoRun=OFF
			釜反転入口AutoRun=OFF
			洗浄ユニットAutoRun=OFF
			洗浄タンクAutoRun=OFF
			洗浄コンベア搬送AutoRun=OFF
			釜反転出口AutoRun=OFF
			釜フタ昇降装置BAutoRun=OFF

		select case 自動搬送ErrStep
		case 0
		
		case 1
			パトライト赤=ON

			if PB34_リセット or PB24_リセット or PB38_リセット then
				
				パトライト赤=OFF

				almDCPLC電源電圧降下=OFF
				almDC電源電圧降下1=OFF
				almDC電源電圧降下2=OFF
				almRLY_電源確認納米庫=OFF
				almRLY_浸漬電源確認=OFF
				almRLY_搬送1電源確認=OFF
				almRLY_搬送2電源確認=OFF
				almRLY_F1A電源確認=OFF
				almRLY_F1B電源確認=OFF
				almRLY_F2A電源確認=OFF
				almRLY_F2B電源確認=OFF
				almRLY_洗浄機電源確認=OFF
				almRLY_反転機電源確認=OFF
				almRLY_サブ1電源確認=OFF
				almRLY_サブ2電源確認=OFF
				almPS1_エアー圧力=OFF
				almPS2_エアー圧力=OFF
				almPS3_エアー圧力=OFF
				almPS4_エアー圧力=OFF
				almPS5_エアー圧力=OFF				
				almTHR4_送米ポンプ=OFF
				almTHR5_洗米羽根=OFF
				almTHR1_張込用昇降機モータ=OFF
				almTHR2_排出用昇降機モータ=OFF
				almTHR3_計量機モータ=OFF
				almTHR11_搬送モータ=OFF
				almTHR6_搬送モータ=OFF
				almTHR7_搬送モータ=OFF
				almTHR8_搬送モータ=OFF
				almTHR40_ならしモータ=OFF
				almTHR9_モータローラ=OFF
				almTHR12_搬送モータ=OFF
				almTHR13_搬送モータ=OFF
				almTHR16_モータローラ=OFF
				almTHR14_搬送モータ=OFF
				almTHR15_搬送モータ=OFF
				almTHR34_モータローラ=OFF
				almTHR44_モータローラ=OFF
				almTHR46_モータローラ=OFF
				almTHR45_搬送モータ=OFF
				almTHR17_モータローラ=OFF
				almTHR18_モータローラ=OFF
				almTHR19_モータローラ=OFF
				almTHR20_モータローラ=OFF
				almTHR21_モータローラ=OFF
				almTHR22_モータローラ=OFF
				almTHR23_モータローラ=OFF
				almTHR24_モータローラ=OFF
				almTHR25_モータローラ=OFF
				almTHR26_モータローラ=OFF
				almTHR27_モータローラ=OFF
				almTHR28_モータローラ=OFF
				almTHR29_モータローラ=OFF
				almTHR30_モータローラ=OFF
				almTHR31_モータローラ=OFF
				almTHR32_モータローラ=OFF
				almTHR33_モータローラ=OFF
				almTHR47_モータローラ=OFF
				almTHR48_モータローラ=OFF
				almTHR49_モータローラ=OFF
				almTHR50_モータローラ=OFF
				almTHR51_モータローラ=OFF
				almTHR52_モータローラ=OFF
				almTHR53_モータローラ=OFF
				almTHR41_モータローラ=OFF
				almTHR42_モータローラ=OFF
				almTHR43_搬送モータ=OFF
				almTHR54_モータローラ=OFF
				almTHR10_搬送モータ=OFF
				almTHR55_搬送モータ=OFF
				almTHR57_搬送モータ=OFF
				almTHR56_ブラシサーマル=OFF
				almTHR58_洗浄ポンプA=OFF
				almTHR59_洗浄ポンプB=OFF
				almTHR60_洗浄ポンプC=OFF
				almTHR61_洗浄ポンプD=OFF
				almINV1_コンベア異常=OFF
				almINV2_コンベア異常=OFF
				almINV3_コンベア異常=OFF
				almDCPLC電源電圧降下=OFF
				
				インバータ1リセット=ON
				インバータ2リセット=ON
				インバータ3リセット=ON

				IH炊飯ユニットAOrgErr=OFF
				IH炊飯ユニットBOrgErr=OFF

				inc(自動搬送ErrStep)

			end if

		case 2
			if OtherErrStep=0 then
				自動搬送ErrStep=0
			end if
			
		end select

	end if
	
	'==================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	
	
	select case 自動搬送EmgStep
	case 0
	case 1
		'非常停止処理
		PBL非常停止=CR2006
		PBL22_自動運転=OFF

		inc(自動搬送EmgStep)
	case 2
		PBL非常停止=CR2006

		if PB34_リセット or PB24_リセット or PB38_リセット then
			PBL非常停止=OFF
			inc(自動搬送EmgStep)
		end if

	case 3
		PBL非常停止=OFF
		PBL22_自動運転=CR2006
		if ldp(PB22_自動運転) then
			StartFlg=ON
			自動搬送AutoRun=OFF
			inc(自動搬送EmgStep)
		end if		

	case 4
		PBL22_自動運転=OFF
		EmgFlg=OFF	
		inc(自動搬送EmgStep)
		
	case 5	
		if 前処理工程EmgStep=0 and  OtherEmgStep=0 and not(PB22_自動運転) then
			StartFlg=OFF
			自動搬送ErrStep=0
			自動搬送EmgStep=0
		end if
		
	end select
		
end if

