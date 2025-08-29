'デバイスアラーム検出

tmr(systemwait,#30)

if systemwait.B then

'===================================================================================================================
'【  デバイスのアラーム検出  】
'-----------------------------------------------------------
'① KL-N20V  KLリンクリレーコントローラ


'② KL-L21V Modbus通信(リトライ通信中： 接続に異常がなければ自動復帰します ）

	select case ModbusC1AlmID

	case 0	'正常
		温度調節器1通信Alm=OFF
		温度調節器2通信Alm=OFF
		温度調節器3通信Alm=OFF
		温度調節器4通信Alm=OFF
		温度調節器5通信Alm=OFF
		温度調節器6通信Alm=OFF
		インバータ1通信Alm=OFF
		インバータ2通信Alm=OFF
		インバータ3通信Alm=OFF
		インバータ4通信Alm=OFF

	'----------------------------------
	case 1
		温度調節器1通信Alm=ON
	case 2
		温度調節器2通信Alm=ON
	case 3
		温度調節器3通信Alm=ON
	case 4
		温度調節器4通信Alm=ON
	case 5
		温度調節器5通信Alm=ON
	case 6
		温度調節器6通信Alm=ON
	'----------------------------------
	case 10
		インバータ1通信Alm=ON
	case 11
		インバータ2通信Alm=ON
	case 12
		インバータ3通信Alm=ON
	case 13
		インバータ4通信Alm=ON
	'----------------------------------

	end select

'③ KL-L21V Modbus通信(リトライ通信中： 接続に異常がなければ自動復帰します）

	select case ModbusC2AlmID
	case 0	'正常
		ADR4410ch1通信Alm=OFF
		ADR4410ch2通信Alm=OFF
		AD4532ch1通信Alm=OFF

	'----------------------------------
	case 1	
		ADR4410ch1通信Alm=ON
	case 2	
		ADR4410ch2通信Alm=ON
	'----------------------------------
	case 10	
		AD4532ch1通信Alm=ON
	'----------------------------------

	end select

'-----------------------------------------------------------
'電圧降下

if not(DCPLC電源電圧降下) then
	almDCPLC電源電圧降下=ON
	自動搬送EmgStep=1
end if

if not(DC電源電圧降下1) then
	almDC電源電圧降下1=ON
	自動搬送EmgStep=1
end if

if not(DC電源電圧降下2) then
	almDC電源電圧降下2=ON
	自動搬送EmgStep=1
end if

'-----------------------------------------------------------
'操作ボックスの電源確認

'-- 納米庫
if ldp( not(RLY_電源確認納米庫)) then
	almRLY_電源確認納米庫=ON
	自動搬送ErrStep=1
end if

'-- 浸漬A,B,注水
if ldp( not(RLY_浸漬電源確認)) then
	almRLY_浸漬電源確認=ON
	自動搬送ErrStep=1
end if	

'-- 1搬送
if ldp(not(RLY_搬送1電源確認)) then
	almRLY_搬送1電源確認=ON
	自動搬送ErrStep=1
end if

'-- 2搬送
if ldp(not(RLY_搬送2電源確認)) then
	almRLY_搬送2電源確認=ON
	自動搬送ErrStep=1
end if

'-- むらし機
if ldp(not(RLY_F1A電源確認)) then
	almRLY_F1A電源確認=ON
	自動搬送ErrStep=1
end if
if ldp(not(RLY_F1B電源確認)) then
	almRLY_F1B電源確認=ON
	自動搬送ErrStep=1
end if

if ldp(not(RLY_F2A電源確認)) then
	almRLY_F2A電源確認=ON
	自動搬送ErrStep=1
end if
if ldp(not(RLY_F2B電源確認)) then
	almRLY_F2B電源確認=ON
	自動搬送ErrStep=1
end if

'-- 洗浄機
if ldp(not(RLY_洗浄機電源確認)) then
	almRLY_洗浄機電源確認=ON
	自動搬送ErrStep=1
end if

'-- 反転幾A
if ldp(not(RLY_反転機電源確認) and not(反転ほぐし機A禁止)) then
	almRLY_反転機電源確認=ON
	自動搬送ErrStep=1
end if


'-- サブ1電源
if ldp(not(RLY_サブ1電源確認)) then
	almRLY_サブ1電源確認=ON
	自動搬送ErrStep=1
end if

'-- サブ2電源
if ldp(not(RLY_サブ2電源確認)) then
	almRLY_サブ2電源確認=ON
	自動搬送ErrStep=1
end if

if ldp(not(IH炊飯ユニットAOrg)) then
	IH炊飯ユニットAOrgErr=ON
	自動搬送ErrStep=1
end if

if ldp(not(IH炊飯ユニットBOrg)) then
	IH炊飯ユニットBOrgErr=ON
	自動搬送ErrStep=1
end if


'-----------------------------------------------------------
'デジタル圧力計のアラーム検出


'-----------------------------------------------------------
'空圧スイッチ
if ldp(not(PS1_エアー圧力)) then
	almPS1_エアー圧力=ON
	自動搬送ErrStep=1
end if
if ldp(not(PS2_エアー圧力)) then
	almPS2_エアー圧力=ON
	自動搬送ErrStep=1
end if
if ldp(not(PS3_エアー圧力)) then
	almPS3_エアー圧力=ON
	自動搬送ErrStep=1
end if
if ldp(not(PS4_エアー圧力)) then
	almPS4_エアー圧力=ON
	自動搬送ErrStep=1
end if
if ldp(not(PS5_エアー圧力)) then
	almPS5_エアー圧力=ON
	自動搬送ErrStep=1
end if

'-----------------------------------------------------------
'モータ過負荷 THR、ショックリレー、INVアラーム

'--納米庫BOX
if ldp(THR4_送米ポンプ or not(RLY_電源確認納米庫)) then
	almTHR4_送米ポンプ=ON
	mMC4_送米ポンプ=OFF
	ejectMC4_送米ポンプ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR5_洗米羽根 or not(RLY_電源確認納米庫)) then
	almTHR5_洗米羽根=ON
	mMC5_洗米羽根=OFF
	ejectMC5_洗米羽根=OFF
	自動搬送ErrStep=1
end if
if ldp(THR1_張込用昇降機モータ or not(RLY_電源確認納米庫)) then
	almTHR1_張込用昇降機モータ=ON
	mMC1_張込用昇降機=OFF
	ejectMC1_張込用昇降機=OFF
	自動搬送ErrStep=1
end if
if ldp(THR2_排出用昇降機モータ or not(RLY_電源確認納米庫)) then
	almTHR2_排出用昇降機モータ=ON
	mMC2_排出用昇降機=OFF
	ejectMC2_排出用昇降機=OFF
	自動搬送ErrStep=1
end if
if ldp(THR3_計量機モータ or not(RLY_電源確認納米庫)) then
	almTHR3_計量機モータ=ON
	mMC3_計量機=OFF
	ejectMC3_計量機=OFF
	自動搬送ErrStep=1
end if

'--浸漬BOX
if ldp(THR11_搬送モータ or not(RLY_浸漬電源確認)) then
	almTHR11_搬送モータ=ON
	mMC11_搬送モータ=OFF
	ejectMC11_搬送モータ=OFF
	自動搬送ErrStep=1
end if

if ldp(THR6_搬送モータ or not(RLY_浸漬電源確認)) then
	almTHR6_搬送モータ=ON
	mMC6_搬送モータ=OFF
	ejectMC6_搬送モータ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR7_搬送モータ or not(RLY_浸漬電源確認)) then
	almTHR7_搬送モータ=ON
	mMC7_搬送モータ=OFF
	ejectMC7_搬送モータ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR8_搬送モータ or not(RLY_浸漬電源確認)) then
	almTHR8_搬送モータ=ON
	mMC8_搬送モータ=OFF
	ejectMC8_搬送モータ=OFF
	自動搬送ErrStep=1
end if

'１搬送BOX
if ldp(THR40_ならしモータ or not(RLY_搬送1電源確認)) then
	almTHR40_ならしモータ=ON
	mMC40_ならしモータ=OFF
	ejectMC40_ならしモータ=OFF
	自動搬送ErrStep=1
end if

if ldp(THR9_モータローラ or not(RLY_搬送1電源確認)) then
	almTHR9_モータローラ=ON
	mMC9_モータローラ=OFF
	ejectMC9_モータローラ=OFF
	自動搬送ErrStep=1
end if

if ldp(THR12_搬送モータ or not(RLY_搬送1電源確認)) then
	almTHR12_搬送モータ=ON
	mMC12_搬送モータ=OFF
	ejectMC12_搬送モータ=OFF
	自動搬送ErrStep=1
end if

if ldp(THR13_搬送モータ or not(RLY_搬送1電源確認)) then
	almTHR13_搬送モータ=ON
	mMC13_搬送モータ=OFF
	ejectMC13_搬送モータ=OFF
	自動搬送ErrStep=1
end if

if ldp(THR16_モータローラ or not(RLY_搬送1電源確認)) then
	almTHR16_モータローラ=ON
	mMC16_モータローラ=OFF
	ejectMC16_モータローラ=OFF
	自動搬送ErrStep=1
end if

if ldp(THR14_搬送モータ or not(RLY_搬送1電源確認)) then
	almTHR14_搬送モータ=ON
	mMC14_搬送モータ=OFF
	ejectMC14_搬送モータ=OFF
	自動搬送ErrStep=1
end if

if ldp(THR15_搬送モータ or not(RLY_搬送1電源確認)) then
	almTHR15_搬送モータ=ON
	mMC15_搬送モータ=OFF
	ejectMC15_搬送モータ=OFF
	自動搬送ErrStep=1
end if

if ldp(THR34_モータローラ or not(RLY_搬送1電源確認)) then
	almTHR34_モータローラ=ON
	mMC34_モータローラ=OFF
	ejectMC34_モータローラ=OFF
	自動搬送ErrStep=1
end if

if ldp(THR44_モータローラ or not(RLY_搬送1電源確認)) then
	almTHR44_モータローラ=ON
	mMC44_モータローラ=OFF
	ejectMC44_モータローラ=OFF
	自動搬送ErrStep=1
end if

if ldp(THR46_モータローラ or not(RLY_搬送1電源確認)) then
	almTHR46_モータローラ=ON
	mMC46_モータローラ=OFF
	ejectMC46_モータローラ=OFF
	自動搬送ErrStep=1
end if

if ldp(THR45_搬送モータ or not(RLY_搬送1電源確認)) then
	almTHR45_搬送モータ=ON
	mMC45_搬送モータ=OFF
	ejectMC45_搬送モータ=OFF
	自動搬送ErrStep=1
end if

'--F1AむらしBOX
if ldp(THR17_モータローラ or not(RLY_F1A電源確認)) then
	almTHR17_モータローラ=ON
	mMC17_モータローラ=OFF
	ejectMC17_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR18_モータローラ or not(RLY_F1A電源確認)) then
	almTHR18_モータローラ=ON
	mMC18_モータローラ=OFF
	ejectMC18_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR19_モータローラ or not(RLY_F1A電源確認)) then
	almTHR19_モータローラ=ON
	mMC19_モータローラ=OFF
	ejectMC19_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR20_モータローラ or not(RLY_F1A電源確認)) then
	almTHR20_モータローラ=ON
	mMC20_モータローラ=OFF
	ejectMC20_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR21_モータローラ or not(RLY_F1A電源確認)) then
	almTHR21_モータローラ=ON
	mMC21_モータローラ=OFF
	ejectMC21_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR22_モータローラ or not(RLY_F1A電源確認)) then
	almTHR22_モータローラ=ON
	mMC22_モータローラ=OFF
	ejectMC22_モータローラ=OFF
	自動搬送ErrStep=1
end if
'--F1BむらしBOX
if ldp(THR23_モータローラ or not(RLY_F1B電源確認)) then
	almTHR23_モータローラ=ON
	mMC23_モータローラ=OFF
	ejectMC23_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR24_モータローラ or not(RLY_F1B電源確認)) then
	almTHR24_モータローラ=ON
	mMC24_モータローラ=OFF
	ejectMC24_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR25_モータローラ or not(RLY_F1B電源確認)) then
	almTHR25_モータローラ=ON
	mMC25_モータローラ=OFF
	ejectMC25_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR26_モータローラ or not(RLY_F1B電源確認)) then
	almTHR26_モータローラ=ON
	mMC26_モータローラ=OFF
	ejectMC26_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR27_モータローラ or not(RLY_F1B電源確認)) then
	almTHR27_モータローラ=ON
	mMC27_モータローラ=OFF
	ejectMC27_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR28_モータローラ or not(RLY_F1B電源確認)) then
	almTHR28_モータローラ=ON
	mMC28_モータローラ=OFF
	ejectMC28_モータローラ=OFF
	自動搬送ErrStep=1
end if
'--F2AむらしBOX
if ldp(THR29_モータローラ or not(RLY_F2A電源確認)) then
	almTHR29_モータローラ=ON
	mMC29_モータローラ=OFF
	ejectMC29_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR30_モータローラ or not(RLY_F2A電源確認)) then
	almTHR30_モータローラ=ON
	mMC30_モータローラ=OFF
	ejectMC30_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR31_モータローラ or not(RLY_F2A電源確認)) then
	almTHR31_モータローラ=ON
	mMC31_モータローラ=OFF
	ejectMC31_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR32_モータローラ or not(RLY_F2A電源確認)) then
	almTHR32_モータローラ=ON
	mMC32_モータローラ=OFF
	ejectMC32_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR33_モータローラ or not(RLY_F2A電源確認)) then
	almTHR33_モータローラ=ON
	mMC33_モータローラ=OFF
	ejectMC33_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR47_モータローラ or not(RLY_F2A電源確認)) then
	almTHR47_モータローラ=ON
	mMC47_モータローラ=OFF
	ejectMC47_モータローラ=OFF
	自動搬送ErrStep=1
end if
'--F2BむらしBOX
if ldp(THR48_モータローラ or not(RLY_F2B電源確認)) then
	almTHR48_モータローラ=ON
	mMC48_モータローラ=OFF
	ejectMC48_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR49_モータローラ or not(RLY_F2B電源確認)) then
	almTHR49_モータローラ=ON
	mMC49_モータローラ=OFF
	ejectMC49_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR50_モータローラ or not(RLY_F2B電源確認)) then
	almTHR50_モータローラ=ON
	mMC50_モータローラ=OFF
	ejectMC50_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR51_モータローラ or not(RLY_F2B電源確認)) then
	almTHR51_モータローラ=ON
	mMC51_モータローラ=OFF
	ejectMC51_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR52_モータローラ or not(RLY_F2B電源確認)) then
	almTHR52_モータローラ=ON
	mMC52_モータローラ=OFF
	ejectMC52_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR53_モータローラ or not(RLY_F2B電源確認)) then
	almTHR53_モータローラ=ON
	mMC53_モータローラ=OFF
	ejectMC53_モータローラ=OFF
	自動搬送ErrStep=1
end if
'--2搬送BOX
if ldp(THR41_モータローラ or not(RLY_搬送2電源確認)) then
	almTHR41_モータローラ=ON
	mMC41_モータローラ=OFF
	ejectMC41_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR42_モータローラ or not(RLY_搬送2電源確認)) then
	almTHR42_モータローラ=ON
	mMC42_モータローラ=OFF
	ejectMC42_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR43_搬送モータ or not(RLY_搬送2電源確認)) then
	almTHR43_搬送モータ=ON
	mMC43_搬送モータ=OFF
	ejectMC43_搬送モータ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR54_モータローラ or not(RLY_搬送2電源確認)) then
	almTHR54_モータローラ=ON
	mMC54_モータローラ=OFF
	ejectMC54_モータローラ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR10_搬送モータ or not(RLY_搬送2電源確認)) then
	almTHR10_搬送モータ=ON
	mMC10_搬送モータ正転=OFF
	ejectMC10_搬送モータ正転=OFF
	mMC10_搬送モータ逆転=OFF
	ejectMC10_搬送モータ逆転=OFF
	自動搬送ErrStep=1
end if
if ldp(THR55_搬送モータ or not(RLY_搬送2電源確認)) then
	almTHR55_搬送モータ=ON
	mMC55_搬送モータ=OFF
	ejectMC55_搬送モータ=OFF
	extMC55_搬送モータ=OFF
	自動搬送ErrStep=1
end if
if ldp(THR57_搬送モータ or not(RLY_搬送2電源確認)) then
	almTHR57_搬送モータ=ON
	mMC57_搬送モータ=OFF
	ejectMC57_搬送モータ=OFF
	自動搬送ErrStep=1
end if
'--洗浄機BOX

if LDP( (THR58_洗浄ポンプA and MC58_洗浄ポンプA) or not(RLY_洗浄機電源確認) ) then
	almTHR58_洗浄ポンプA=ON
	mMC58_洗浄ポンプA=OFF
	ejectMC58_洗浄ポンプA=OFF
	自動搬送ErrStep=1
end if
if LDP( (THR59_洗浄ポンプB and MC59_洗浄ポンプB) or not(RLY_洗浄機電源確認) ) then
	almTHR59_洗浄ポンプB=ON
	mMC59_洗浄ポンプB=OFF
	ejectMC59_洗浄ポンプB=OFF
	自動搬送ErrStep=1
end if
if LDP( (THR60_洗浄ポンプC and MC60_洗浄ポンプC) or not(RLY_洗浄機電源確認) ) then
	almTHR60_洗浄ポンプC=ON
	mMC60_洗浄ポンプC=OFF
	ejectMC60_洗浄ポンプC=OFF
	自動搬送ErrStep=1
end if
if LDP( (THR61_洗浄ポンプD and MC61_洗浄ポンプD) or not(RLY_洗浄機電源確認) ) then
	almTHR61_洗浄ポンプD=ON
	mMC61_洗浄ポンプD=OFF
	ejectMC61_洗浄ポンプD=OFF
	自動搬送ErrStep=1
end if

if LDP( THR35_搬送モータ or not(RLY_洗浄機電源確認) ) then
	almTHR35_搬送モータ=ON
	mMC35_搬送モータ=OFF
	ejectMC35_搬送モータ=OFF
	自動搬送ErrStep=1
end if
if LDP( THR36_反転モータ or not(RLY_洗浄機電源確認) or RLY_SCR1_MC36_反転モータ) then
	almTHR36_反転モータ=ON
	mMC36_反転モータ正転=OFF
	ejectMC36_反転モータ正転=OFF
	mMC36_反転モータ逆転=OFF
	ejectMC36_反転モータ逆転=OFF
	自動搬送ErrStep=1
end if
if LDP( THR38_搬送モータ or not(RLY_洗浄機電源確認) ) then
	almTHR38_搬送モータ=ON
	mMC38_搬送モータ=OFF
	ejectMC38_搬送モータ=OFF
	自動搬送ErrStep=1
end if
if LDP( THR37_反転モータ or not(RLY_洗浄機電源確認) or RLY_SCR2_MC37_反転モータ) then
	almTHR37_反転モータ=ON
	mMC37_反転モータ正転=OFF
	ejectMC37_反転モータ正転=OFF
	mMC37_反転モータ逆転=OFF
	ejectMC37_反転モータ逆転=OFF
	自動搬送ErrStep=1
end if


'-----------------------------------------------------------
'インバータアラーム

if MC1_インバータ用電源 or not(RLY_洗浄機電源確認) then
 	if anda(getM14c1,statALM)=statALM or  INV1_コンベア異常 then
		almINV1_コンベア異常=ON
		mINV1_コンベアモータ正転=OFF
		ejectINV1_コンベアモータ正転=OFF
		自動搬送ErrStep=1
	end if
	if  anda(getM14c2,statALM)=statALM or INV2_コンベア異常 then
		almINV2_コンベア異常=ON
		mINV2_コンベアモータ正転=OFF
		ejectINV2_コンベアモータ正転=OFF
		自動搬送ErrStep=1
	end if
	if  anda(getM14c3,statALM)=statALM or INV3_コンベア異常 then
		almINV3_コンベア異常=ON
		mINV3_コンベアモータ正転=OFF
		ejectINV3_コンベアモータ正転=OFF
		自動搬送ErrStep=1
	end if
end if


'-----------------------------------------------------------
' IH炊飯機 ONLINE状態 異常なし

if not(IH炊飯ユニットAOrg) then
	IH炊飯ユニットAOrgErr=ON
	自動搬送ErrStep=1
end if


if not(IH炊飯ユニットBOrg) then
	IH炊飯ユニットBOrgErr=ON
	自動搬送ErrStep=1
end if

'===================================================================================================================
'ヒータ継電器溶着検出




'===================================================================================================================
'-----------------------------------------------------------
'温度調節器アラーム
'
'●	EDC_ST1LBT0	1ワード符号なし整数	#1	$1:ヒータ電流値オーバー（CT1）
'●	EDC_ST1LBT1	1ワード符号なし整数	#2	$2:ヒータ電流値ホールド(CT1)
'●	EDC_ST1LBT2	1ワード符号なし整数	#4	$4:ADコンバータ異常
'●	EDC_ST1LBT3	1ワード符号なし整数	#8	$8:HS（SSR故障）警報(CT1)
'●	EDC_ST1LBT4	1ワード符号なし整数	#16	$10:RSP入力異常
'●	EDC_ST1LBT6	1ワード符号なし整数	#64	$40:入力異常
'●	EDC_ST1LBT7	1ワード符号なし整数	#128	$80:ポテンションメータ入力異常
'	EDC_ST1LBT8	1ワード符号なし整数	#256	$100:制御出力(加熱）オープン出力
'	EDC_ST1LBT9	1ワード符号なし整数	#512	$200:制御出力(冷却)クローズ出力
'	EDC_ST1LBT10	1ワード符号なし整数	#1024	$400:HB(ヒータ断線）警報(CT1)
'	EDC_ST1LBT11	1ワード符号なし整数	#2048	$800:HB(ヒータ断線）警報(CT2)
'	EDC_ST1LBT12	1ワード符号なし整数	#4096	$1000:警報1
'	EDC_ST1LBT13	1ワード符号なし整数	#8192	$2000:警報2
'	EDC_ST1LBT14	1ワード符号なし整数	#16384	$4000:警報3
'	EDC_ST1LBT15	1ワード符号なし整数	#32768	$8000:プログラムエンド出力
'
	EDC_Almbit=0
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT0)
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT1)
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT2)
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT3)
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT4)
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT6)
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT7)
	
if ANDA(getEDC1_ST1L,EDC_Almbit)<>0 then
	温度調節器1Alm=ON
else
	温度調節器1Alm=OFF
end if

if ANDA(getEDC2_ST1L,EDC_Almbit)<>0 then
	温度調節器2Alm=ON
else
	温度調節器2Alm=OFF
end if

if ANDA(getEDC3_ST1L,EDC_Almbit)<>0 then
	温度調節器3Alm=ON
else
	温度調節器3Alm=OFF
end if

if ANDA(getEDC4_ST1L,EDC_Almbit)<>0 then
	温度調節器4Alm=ON
else
	温度調節器4Alm=OFF
end if

if ANDA(getEDC5_ST1L,EDC_Almbit)<>0 then
	温度調節器5Alm=ON
else
	温度調節器5Alm=OFF
end if

'-----------------------------------------------------------
'拡張ユニットおよび通信エラー検出

if CR2306 then 'バッテリーエラー 交換用リチウム電池  型番 : KV-B1
	almDCPLC電源電圧降下=ON
end if

'-----------------------------------------------------------
'アラームリレー（CR3300～CR3415）にデバイスコメントとしてメッセージを登録
'[ファイル(F)] - CSV/TXT形式でデバイスコメントを保存
'[ファイル(F)] - CSV/TXT形式のデバイスコメントを読出

if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ0
	set(CR3300)
else
	res(CR3300)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ1
	set(CR3301)
else
	res(CR3301)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ2
	set(CR3302)
else
	res(CR3302)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ3
	set(CR3303)
else
	res(CR3303)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ4
	set(CR3304)
else
	res(CR3304)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ5
	set(CR3305)
else
	res(CR3305)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ6
	set(CR3306)
else
	res(CR3306)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ7
	set(CR3307)
else
	res(CR3307)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ8
	set(CR3308)
else
	res(CR3308)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ9
	set(CR3309)
else
	res(CR3309)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ10
	set(CR3310)
else
	res(CR3310)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ11
	set(CR3311)
else
	res(CR3311)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ12
	set(CR3312)
else
	res(CR3312)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ13
	set(CR3313)
else
	res(CR3313)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ14
	set(CR3314)
else
	res(CR3314)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ15
	set(CR3315)
else
	res(CR3315)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ16
	set(CR3400)
else
	res(CR3400)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ17
	set(CR3401)
else
	res(CR3401)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ18
	set(CR3402)
else
	res(CR3402)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ19
	set(CR3403)
else
	res(CR3403)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ20
	set(CR3404)
else
	res(CR3404)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ21
	set(CR3405)
else
	res(CR3405)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ22
	set(CR3406)
else
	res(CR3406)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ23
	set(CR3407)
else
	res(CR3407)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ24
	set(CR3408)
else
	res(CR3408)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ25
	set(CR3409)
else
	res(CR3409)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ26
	set(CR3410)
else
	res(CR3410)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ27
	set(CR3411)
else
	res(CR3411)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ28
	set(CR3412)
else
	res(CR3412)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ29
	set(CR3413)
else
	res(CR3413)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ30
	set(CR3414)
else
	res(CR3414)	
end if
if  0 then	 		'ﾕｰｻﾞｱﾗｰﾑ31
	set(CR3415)
else
	res(CR3415)	
end if

if 0 and CR3500 then 

end if


end if 'if systemwait.B then
'===================================================================================================================
