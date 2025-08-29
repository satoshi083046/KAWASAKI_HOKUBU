'IH炊飯ユニットA文字列操作
'===================================================================================================================
'
'<<<<<<<	ユニット	>>>>>>>>
'
'
'	空釜搬入は アイテムNO=99
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
'【 初期化処理 】
if CR2008 then

	ファイル読込step=0
	ファイル書込みstep=0
	一括転送step=0
	一括読込step=0
	パラメータ書込みstep=0
	パラメータ読込みstep=0

end if
'===================================================================================================================
' インデックス
	OffsetAdr=0
'------------------------------------------------------------------
' ファイル読込 	FR001.fru => ZF0 - ZF32767 => IH炊飯器A
'------------------------------------------------------------------
if LDP(pnlPBIH文字列更新) and not(ファイル読込み中)then
	ファイル読込step=1
end if

tmr(tim_ファイル読込,tim_ファイル読込_val)
select case ファイル読込step
case 0
case 1
	ファイル読込み中=ON
	inc(ファイル読込step)

case 2
	ファイル読込み完了=OFF
	ファイル読込みERR=OFF
	ドライブ番号=0
	バンク番号=0
	ファイル番号=1
	FRLDM(ドライブ番号,バンク番号,ファイル番号,ファイル読込み完了)
	inc(ファイル読込step)

case 3
	if ファイル読込み完了 or ファイル読込みERR then
		inc(ファイル読込step)
	end if
	
case 4
	if ファイル読込みERR then
		inc(ファイル読込step)
	else
		if 一括転送step=0 then
			一括転送step=1
			inc(ファイル読込step)
		end if
	end if
	
case 5
	if 一括転送step=0 then
		inc(ファイル読込step)
	end if

case 6
	ファイル読込み中=OFF
	ファイル読込step=0

end select


'------------------------------------------------------------------
' ファイル書込み IH炊飯器A => ZF0 - ZF32767 => FR000.fru
'------------------------------------------------------------------
if LDP(pnlPBIH文字列保存) and not(ファイル書込み中) then
	ファイル書込みstep=1
end if

tmr(tim_ファイル書込み,tim_ファイル書込み_val)
select case ファイル書込みstep
case 0
case 1
	ファイル書込み中=ON
	inc(ファイル書込みstep)

case 2
	if 一括読込step=0 then
		一括読込step=1
		inc(ファイル書込みstep)
	end if

case 3
	if 一括読込step=0 then
		inc(ファイル書込みstep)
	end if

case 4
	'タイムスタンプ
	ZF0.T=STR(CM700.U)
	ZF1=$2F
	ZF2.T=STR(CM701.U)
	ZF3=$2F
	ZF4.T=STR(CM702.U)
	ZF5=$2F
	ZF6.T=STR(CM703.U)
	ZF7=$3A
	ZF8.T=STR(CM704.U)

	ドライブ番号=0
	バンク番号=0
	ファイル番号=0
	FRSTM(ドライブ番号,バンク番号,ファイル番号,ファイル書込み完了)
	inc(ファイル書込みstep)

case 5
	if ファイル書込み完了 or ファイル書込みERR then
		inc(ファイル書込みstep)
	end if	
 
case 6
	ファイル書込み中=OFF
	ファイル書込みstep=0

end select


'------------------------------------------------------------------
' パラメータ一括転送
'------------------------------------------------------------------
if ldp(pnlPB一括転送) and 一括転送step=0 and not(パラメータ転送中) then
	一括転送step=1
end if

tmr(tim_一括転送,tim_一括転送_val)

select case 一括転送step
case 0
case 1
	パラメータ転送中=ON
	parアイテムNO=0
	inc(一括転送step)

case 2
	parアイテムNO=parアイテムNO+1
	if parアイテムNO < 100 then
		inc(一括転送step)
	else
		一括転送step=99
	end if
	
case 3
	'文字列の読み出し
	ADRSET(ZF0.U,SourceAdr) ' バンク先頭アドレス
	SourceAdr=SourceAdr+10*parアイテムNO
	ADRSET(ラベル文字列.U,DestAdr)
	for loop=0 to 9 step 1
		*DestAdr.U=*SourceAdr.U
		inc(DestAdr)
		inc(SourceAdr)
	next
	inc(一括転送step)

case 4 '---------------------------------------------
	if パラメータ書込みstep=0 then		
		パラメータ書込みstep=1
		inc(一括転送step)
	end if

case 5
	if パラメータ書込みstep=0 then
		inc(一括転送step)
	end if


	一括転送step=2
	
case 99
	パラメータ転送中=OFF
	一括転送step=0
	

end select

'------------------------------------------------------------------

'------------------------------------------------------------------
' パラメータ一括読込
'------------------------------------------------------------------
if ldp(pnlPB一括読出し) and 一括転送step=0 and not(パラメータ転送中) then
	一括読込step=1
end if

tmr( tim_一括読込,tim_一括読込_val)

select case 一括読込step
case 0
case 1
	パラメータ転送中=ON
	parアイテムNO=0
	inc(一括読込step)

case 2
	parアイテムNO=parアイテムNO+1
	if parアイテムNO < 100 then
		inc(一括読込step)
	else
		一括読込step=99
	end if
	
case 3 '---------------------------------------------
	if パラメータ読込みstep=0 then
		*poutUコマンドNo.U=1
		*poutUコマンドデータ0.U=parアイテムNO
		パラメータ読込みstep=1
	end if
	inc(一括読込step)

case 4
	if パラメータ読込みstep=0 then
		inc(一括読込step)
	end if

case 5
	
	parアイテムNO	=*pinUコマンドデータ0.U
	ラベル文字列=*pinUコマンドデータ1.U
	ラベル文字列1=*pinUコマンドデータ2.U
	ラベル文字列2=*pinUコマンドデータ3.U
	ラベル文字列3=*pinUコマンドデータ4.U
	ラベル文字列4=*pinUコマンドデータ5.U
	ラベル文字列5=*pinUコマンドデータ6.U
	ラベル文字列6=*pinUコマンドデータ7.U
	ラベル文字列7=*pinUコマンドデータ8.U
	
	ラベル文字列=swap(ラベル文字列)
	ラベル文字列1=swap(ラベル文字列1)
	ラベル文字列2=swap(ラベル文字列2)
	ラベル文字列3=swap(ラベル文字列3)
	ラベル文字列4=swap(ラベル文字列4)
	ラベル文字列5=swap(ラベル文字列5)
	ラベル文字列6=swap(ラベル文字列6)
	ラベル文字列7=swap(ラベル文字列7)
	
	
	ADRSET(ラベル文字列.U,SourceAdr)
	ADRSET(ZF0.U,DestAdr) ' バンク先頭アドレス
	DestAdr=DestAdr+10*parアイテムNO
	for loop=0 to 9 step 1
		*DestAdr.U=*SourceAdr.U
		inc(DestAdr)
		inc(SourceAdr)
	next

	一括読込step=2
	
case 99
	パラメータ転送中=OFF
	一括読込step=0
	

end select

'------------------------------------------------------------------
' パラメータテーブル書き込みタイミング
'------------------------------------------------------------------
tmr(tim_パラメータ書込み,tim_パラメータ書込み_val)
select case パラメータ書込みstep
case 0
case 1
	if *pinBコマンド処理応答.B then
		*poutUコマンドNo.U=1
		*poutUコマンドデータ0.U=parアイテムNO
		*poutUコマンドデータ1.U=swap(ラベル文字列)
		*poutUコマンドデータ2.U=swap(ラベル文字列1)
		*poutUコマンドデータ3.U=swap(ラベル文字列2)
		*poutUコマンドデータ4.U=swap(ラベル文字列3)
		*poutUコマンドデータ5.U=swap(ラベル文字列4)
		*poutUコマンドデータ6.U=swap(ラベル文字列5)
		*poutUコマンドデータ7.U=swap(ラベル文字列6)
		*poutUコマンドデータ8.U=swap(ラベル文字列7)
		inc(パラメータ書込みstep)
	end if

case 2
	*poutB読出書込設定.B=ON  '書込みモード
	inc(パラメータ書込みstep)

case 3
	tim_パラメータ書込み_val=1
	res(tim_パラメータ書込み)
	inc(パラメータ書込みstep)

case 4
	*poutBコマンド処理要求.B=ON
	inc(パラメータ書込みstep)

case 5
	if *pinBコマンド処理応答.B=OFF then
		*poutBコマンド処理要求.B=OFF
		*poutB読出書込設定.B=OFF
		inc(パラメータ書込みstep)
	end if

case 6
	if *pinBコマンド処理応答.B then
		inc(パラメータ書込みstep)
	end if

case 7
	tim_パラメータ書込み_val=1
	res(tim_パラメータ書込み)
	inc(パラメータ書込みstep)

case 8
	if tim_パラメータ書込み.B then
		inc(パラメータ書込みstep)
	end if
	
case 9
	パラメータ書込みstep=0
	
end select
'------------------------------------------------------------------
' パラメータテーブル読込みタイミング
'------------------------------------------------------------------
tmr(tim_パラメータ読込み,tim_パラメータ読込み_val)
select case パラメータ読込みstep
case 0
case 1
	if  *pinBコマンド処理応答.B then
		inc(パラメータ読込みstep)
	else
		パラメータ読込みstep=0
	end if

case 2
	*poutUコマンドデータ0.U=parアイテムNO

	*poutB読出書込設定.B=OFF '読込モード
	inc(パラメータ読込みstep)


case 3
	tim_パラメータ読込み_val=1
	res(tim_パラメータ読込み)
	inc(パラメータ読込みstep)

case 4
	if tim_パラメータ読込み.B then
		*poutBコマンド処理要求.B=ON
		inc(パラメータ読込みstep)
	end if
	
case 5
	if *pinBコマンド処理応答.B=OFF then
		*poutBコマンド処理要求.B=OFF
		*poutB読出書込設定.B=OFF
		inc(パラメータ読込みstep)
	end if

case 6
	if *pinBコマンド処理応答.B then
		inc(パラメータ読込みstep)
	end if

case 7
	tim_パラメータ読込み_val=0
	res(tim_パラメータ読込み)
	inc(パラメータ読込みstep)

case 8
	if tim_パラメータ読込み.B then
		inc(パラメータ読込みstep)
	end if
	
case 9
	parアイテムNO	=*pinUコマンドデータ0.U
	ラベル文字列=*pinUコマンドデータ1.U
	ラベル文字列1=*pinUコマンドデータ2.U
	ラベル文字列2=*pinUコマンドデータ3.U
	ラベル文字列3=*pinUコマンドデータ4.U
	ラベル文字列4=*pinUコマンドデータ5.U
	ラベル文字列5=*pinUコマンドデータ6.U
	ラベル文字列6=*pinUコマンドデータ7.U
	ラベル文字列7=*pinUコマンドデータ8.U
	
	ラベル文字列=swap(ラベル文字列)
	ラベル文字列1=swap(ラベル文字列1)
	ラベル文字列2=swap(ラベル文字列2)
	ラベル文字列3=swap(ラベル文字列3)
	ラベル文字列4=swap(ラベル文字列4)
	ラベル文字列5=swap(ラベル文字列5)
	ラベル文字列6=swap(ラベル文字列6)
	ラベル文字列7=swap(ラベル文字列7)

	inc(パラメータ読込みstep)

case 10
	パラメータ読込みstep=0
end select


