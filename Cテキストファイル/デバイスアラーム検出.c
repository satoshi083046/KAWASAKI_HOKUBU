'�f�o�C�X�A���[�����o

tmr(systemwait,#30)

if systemwait.B then

'===================================================================================================================
'�y  �f�o�C�X�̃A���[�����o  �z
'-----------------------------------------------------------
'�@ KL-N20V  KL�����N�����[�R���g���[��


'�A KL-L21V Modbus�ʐM(���g���C�ʐM���F �ڑ��Ɉُ킪�Ȃ���Ύ������A���܂� �j

	select case ModbusC1AlmID

	case 0	'����
		���x���ߊ�1�ʐMAlm=OFF
		���x���ߊ�2�ʐMAlm=OFF
		���x���ߊ�3�ʐMAlm=OFF
		���x���ߊ�4�ʐMAlm=OFF
		���x���ߊ�5�ʐMAlm=OFF
		���x���ߊ�6�ʐMAlm=OFF
		�C���o�[�^1�ʐMAlm=OFF
		�C���o�[�^2�ʐMAlm=OFF
		�C���o�[�^3�ʐMAlm=OFF
		�C���o�[�^4�ʐMAlm=OFF

	'----------------------------------
	case 1
		���x���ߊ�1�ʐMAlm=ON
	case 2
		���x���ߊ�2�ʐMAlm=ON
	case 3
		���x���ߊ�3�ʐMAlm=ON
	case 4
		���x���ߊ�4�ʐMAlm=ON
	case 5
		���x���ߊ�5�ʐMAlm=ON
	case 6
		���x���ߊ�6�ʐMAlm=ON
	'----------------------------------
	case 10
		�C���o�[�^1�ʐMAlm=ON
	case 11
		�C���o�[�^2�ʐMAlm=ON
	case 12
		�C���o�[�^3�ʐMAlm=ON
	case 13
		�C���o�[�^4�ʐMAlm=ON
	'----------------------------------

	end select

'�B KL-L21V Modbus�ʐM(���g���C�ʐM���F �ڑ��Ɉُ킪�Ȃ���Ύ������A���܂��j

	select case ModbusC2AlmID
	case 0	'����
		ADR4410ch1�ʐMAlm=OFF
		ADR4410ch2�ʐMAlm=OFF
		AD4532ch1�ʐMAlm=OFF

	'----------------------------------
	case 1	
		ADR4410ch1�ʐMAlm=ON
	case 2	
		ADR4410ch2�ʐMAlm=ON
	'----------------------------------
	case 10	
		AD4532ch1�ʐMAlm=ON
	'----------------------------------

	end select

'-----------------------------------------------------------
'�d���~��

if not(DCPLC�d���d���~��) then
	almDCPLC�d���d���~��=ON
	��������EmgStep=1
end if

if not(DC�d���d���~��1) then
	almDC�d���d���~��1=ON
	��������EmgStep=1
end if

if not(DC�d���d���~��2) then
	almDC�d���d���~��2=ON
	��������EmgStep=1
end if

'-----------------------------------------------------------
'����{�b�N�X�̓d���m�F

'-- �[�Č�
if ldp( not(RLY_�d���m�F�[�Č�)) then
	almRLY_�d���m�F�[�Č�=ON
	��������ErrStep=1
end if

'-- �Z��A,B,����
if ldp( not(RLY_�Z�Гd���m�F)) then
	almRLY_�Z�Гd���m�F=ON
	��������ErrStep=1
end if	

'-- 1����
if ldp(not(RLY_����1�d���m�F)) then
	almRLY_����1�d���m�F=ON
	��������ErrStep=1
end if

'-- 2����
if ldp(not(RLY_����2�d���m�F)) then
	almRLY_����2�d���m�F=ON
	��������ErrStep=1
end if

'-- �ނ炵�@
if ldp(not(RLY_F1A�d���m�F)) then
	almRLY_F1A�d���m�F=ON
	��������ErrStep=1
end if
if ldp(not(RLY_F1B�d���m�F)) then
	almRLY_F1B�d���m�F=ON
	��������ErrStep=1
end if

if ldp(not(RLY_F2A�d���m�F)) then
	almRLY_F2A�d���m�F=ON
	��������ErrStep=1
end if
if ldp(not(RLY_F2B�d���m�F)) then
	almRLY_F2B�d���m�F=ON
	��������ErrStep=1
end if

'-- ���@
if ldp(not(RLY_���@�d���m�F)) then
	almRLY_���@�d���m�F=ON
	��������ErrStep=1
end if

'-- ���]��A
if ldp(not(RLY_���]�@�d���m�F) and not(���]�ق����@A�֎~)) then
	almRLY_���]�@�d���m�F=ON
	��������ErrStep=1
end if


'-- �T�u1�d��
if ldp(not(RLY_�T�u1�d���m�F)) then
	almRLY_�T�u1�d���m�F=ON
	��������ErrStep=1
end if

'-- �T�u2�d��
if ldp(not(RLY_�T�u2�d���m�F)) then
	almRLY_�T�u2�d���m�F=ON
	��������ErrStep=1
end if

if ldp(not(IH���у��j�b�gAOrg)) then
	IH���у��j�b�gAOrgErr=ON
	��������ErrStep=1
end if

if ldp(not(IH���у��j�b�gBOrg)) then
	IH���у��j�b�gBOrgErr=ON
	��������ErrStep=1
end if


'-----------------------------------------------------------
'�f�W�^�����͌v�̃A���[�����o


'-----------------------------------------------------------
'�󈳃X�C�b�`
if ldp(not(PS1_�G�A�[����)) then
	almPS1_�G�A�[����=ON
	��������ErrStep=1
end if
if ldp(not(PS2_�G�A�[����)) then
	almPS2_�G�A�[����=ON
	��������ErrStep=1
end if
if ldp(not(PS3_�G�A�[����)) then
	almPS3_�G�A�[����=ON
	��������ErrStep=1
end if
if ldp(not(PS4_�G�A�[����)) then
	almPS4_�G�A�[����=ON
	��������ErrStep=1
end if
if ldp(not(PS5_�G�A�[����)) then
	almPS5_�G�A�[����=ON
	��������ErrStep=1
end if

'-----------------------------------------------------------
'���[�^�ߕ��� THR�A�V���b�N�����[�AINV�A���[��

'--�[�Č�BOX
if ldp(THR4_���ă|���v or not(RLY_�d���m�F�[�Č�)) then
	almTHR4_���ă|���v=ON
	mMC4_���ă|���v=OFF
	ejectMC4_���ă|���v=OFF
	��������ErrStep=1
end if
if ldp(THR5_���ĉH�� or not(RLY_�d���m�F�[�Č�)) then
	almTHR5_���ĉH��=ON
	mMC5_���ĉH��=OFF
	ejectMC5_���ĉH��=OFF
	��������ErrStep=1
end if
if ldp(THR1_�����p���~�@���[�^ or not(RLY_�d���m�F�[�Č�)) then
	almTHR1_�����p���~�@���[�^=ON
	mMC1_�����p���~�@=OFF
	ejectMC1_�����p���~�@=OFF
	��������ErrStep=1
end if
if ldp(THR2_�r�o�p���~�@���[�^ or not(RLY_�d���m�F�[�Č�)) then
	almTHR2_�r�o�p���~�@���[�^=ON
	mMC2_�r�o�p���~�@=OFF
	ejectMC2_�r�o�p���~�@=OFF
	��������ErrStep=1
end if
if ldp(THR3_�v�ʋ@���[�^ or not(RLY_�d���m�F�[�Č�)) then
	almTHR3_�v�ʋ@���[�^=ON
	mMC3_�v�ʋ@=OFF
	ejectMC3_�v�ʋ@=OFF
	��������ErrStep=1
end if

'--�Z��BOX
if ldp(THR11_�������[�^ or not(RLY_�Z�Гd���m�F)) then
	almTHR11_�������[�^=ON
	mMC11_�������[�^=OFF
	ejectMC11_�������[�^=OFF
	��������ErrStep=1
end if

if ldp(THR6_�������[�^ or not(RLY_�Z�Гd���m�F)) then
	almTHR6_�������[�^=ON
	mMC6_�������[�^=OFF
	ejectMC6_�������[�^=OFF
	��������ErrStep=1
end if
if ldp(THR7_�������[�^ or not(RLY_�Z�Гd���m�F)) then
	almTHR7_�������[�^=ON
	mMC7_�������[�^=OFF
	ejectMC7_�������[�^=OFF
	��������ErrStep=1
end if
if ldp(THR8_�������[�^ or not(RLY_�Z�Гd���m�F)) then
	almTHR8_�������[�^=ON
	mMC8_�������[�^=OFF
	ejectMC8_�������[�^=OFF
	��������ErrStep=1
end if

'�P����BOX
if ldp(THR40_�Ȃ炵���[�^ or not(RLY_����1�d���m�F)) then
	almTHR40_�Ȃ炵���[�^=ON
	mMC40_�Ȃ炵���[�^=OFF
	ejectMC40_�Ȃ炵���[�^=OFF
	��������ErrStep=1
end if

if ldp(THR9_���[�^���[�� or not(RLY_����1�d���m�F)) then
	almTHR9_���[�^���[��=ON
	mMC9_���[�^���[��=OFF
	ejectMC9_���[�^���[��=OFF
	��������ErrStep=1
end if

if ldp(THR12_�������[�^ or not(RLY_����1�d���m�F)) then
	almTHR12_�������[�^=ON
	mMC12_�������[�^=OFF
	ejectMC12_�������[�^=OFF
	��������ErrStep=1
end if

if ldp(THR13_�������[�^ or not(RLY_����1�d���m�F)) then
	almTHR13_�������[�^=ON
	mMC13_�������[�^=OFF
	ejectMC13_�������[�^=OFF
	��������ErrStep=1
end if

if ldp(THR16_���[�^���[�� or not(RLY_����1�d���m�F)) then
	almTHR16_���[�^���[��=ON
	mMC16_���[�^���[��=OFF
	ejectMC16_���[�^���[��=OFF
	��������ErrStep=1
end if

if ldp(THR14_�������[�^ or not(RLY_����1�d���m�F)) then
	almTHR14_�������[�^=ON
	mMC14_�������[�^=OFF
	ejectMC14_�������[�^=OFF
	��������ErrStep=1
end if

if ldp(THR15_�������[�^ or not(RLY_����1�d���m�F)) then
	almTHR15_�������[�^=ON
	mMC15_�������[�^=OFF
	ejectMC15_�������[�^=OFF
	��������ErrStep=1
end if

if ldp(THR34_���[�^���[�� or not(RLY_����1�d���m�F)) then
	almTHR34_���[�^���[��=ON
	mMC34_���[�^���[��=OFF
	ejectMC34_���[�^���[��=OFF
	��������ErrStep=1
end if

if ldp(THR44_���[�^���[�� or not(RLY_����1�d���m�F)) then
	almTHR44_���[�^���[��=ON
	mMC44_���[�^���[��=OFF
	ejectMC44_���[�^���[��=OFF
	��������ErrStep=1
end if

if ldp(THR46_���[�^���[�� or not(RLY_����1�d���m�F)) then
	almTHR46_���[�^���[��=ON
	mMC46_���[�^���[��=OFF
	ejectMC46_���[�^���[��=OFF
	��������ErrStep=1
end if

if ldp(THR45_�������[�^ or not(RLY_����1�d���m�F)) then
	almTHR45_�������[�^=ON
	mMC45_�������[�^=OFF
	ejectMC45_�������[�^=OFF
	��������ErrStep=1
end if

'--F1A�ނ炵BOX
if ldp(THR17_���[�^���[�� or not(RLY_F1A�d���m�F)) then
	almTHR17_���[�^���[��=ON
	mMC17_���[�^���[��=OFF
	ejectMC17_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR18_���[�^���[�� or not(RLY_F1A�d���m�F)) then
	almTHR18_���[�^���[��=ON
	mMC18_���[�^���[��=OFF
	ejectMC18_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR19_���[�^���[�� or not(RLY_F1A�d���m�F)) then
	almTHR19_���[�^���[��=ON
	mMC19_���[�^���[��=OFF
	ejectMC19_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR20_���[�^���[�� or not(RLY_F1A�d���m�F)) then
	almTHR20_���[�^���[��=ON
	mMC20_���[�^���[��=OFF
	ejectMC20_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR21_���[�^���[�� or not(RLY_F1A�d���m�F)) then
	almTHR21_���[�^���[��=ON
	mMC21_���[�^���[��=OFF
	ejectMC21_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR22_���[�^���[�� or not(RLY_F1A�d���m�F)) then
	almTHR22_���[�^���[��=ON
	mMC22_���[�^���[��=OFF
	ejectMC22_���[�^���[��=OFF
	��������ErrStep=1
end if
'--F1B�ނ炵BOX
if ldp(THR23_���[�^���[�� or not(RLY_F1B�d���m�F)) then
	almTHR23_���[�^���[��=ON
	mMC23_���[�^���[��=OFF
	ejectMC23_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR24_���[�^���[�� or not(RLY_F1B�d���m�F)) then
	almTHR24_���[�^���[��=ON
	mMC24_���[�^���[��=OFF
	ejectMC24_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR25_���[�^���[�� or not(RLY_F1B�d���m�F)) then
	almTHR25_���[�^���[��=ON
	mMC25_���[�^���[��=OFF
	ejectMC25_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR26_���[�^���[�� or not(RLY_F1B�d���m�F)) then
	almTHR26_���[�^���[��=ON
	mMC26_���[�^���[��=OFF
	ejectMC26_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR27_���[�^���[�� or not(RLY_F1B�d���m�F)) then
	almTHR27_���[�^���[��=ON
	mMC27_���[�^���[��=OFF
	ejectMC27_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR28_���[�^���[�� or not(RLY_F1B�d���m�F)) then
	almTHR28_���[�^���[��=ON
	mMC28_���[�^���[��=OFF
	ejectMC28_���[�^���[��=OFF
	��������ErrStep=1
end if
'--F2A�ނ炵BOX
if ldp(THR29_���[�^���[�� or not(RLY_F2A�d���m�F)) then
	almTHR29_���[�^���[��=ON
	mMC29_���[�^���[��=OFF
	ejectMC29_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR30_���[�^���[�� or not(RLY_F2A�d���m�F)) then
	almTHR30_���[�^���[��=ON
	mMC30_���[�^���[��=OFF
	ejectMC30_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR31_���[�^���[�� or not(RLY_F2A�d���m�F)) then
	almTHR31_���[�^���[��=ON
	mMC31_���[�^���[��=OFF
	ejectMC31_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR32_���[�^���[�� or not(RLY_F2A�d���m�F)) then
	almTHR32_���[�^���[��=ON
	mMC32_���[�^���[��=OFF
	ejectMC32_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR33_���[�^���[�� or not(RLY_F2A�d���m�F)) then
	almTHR33_���[�^���[��=ON
	mMC33_���[�^���[��=OFF
	ejectMC33_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR47_���[�^���[�� or not(RLY_F2A�d���m�F)) then
	almTHR47_���[�^���[��=ON
	mMC47_���[�^���[��=OFF
	ejectMC47_���[�^���[��=OFF
	��������ErrStep=1
end if
'--F2B�ނ炵BOX
if ldp(THR48_���[�^���[�� or not(RLY_F2B�d���m�F)) then
	almTHR48_���[�^���[��=ON
	mMC48_���[�^���[��=OFF
	ejectMC48_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR49_���[�^���[�� or not(RLY_F2B�d���m�F)) then
	almTHR49_���[�^���[��=ON
	mMC49_���[�^���[��=OFF
	ejectMC49_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR50_���[�^���[�� or not(RLY_F2B�d���m�F)) then
	almTHR50_���[�^���[��=ON
	mMC50_���[�^���[��=OFF
	ejectMC50_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR51_���[�^���[�� or not(RLY_F2B�d���m�F)) then
	almTHR51_���[�^���[��=ON
	mMC51_���[�^���[��=OFF
	ejectMC51_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR52_���[�^���[�� or not(RLY_F2B�d���m�F)) then
	almTHR52_���[�^���[��=ON
	mMC52_���[�^���[��=OFF
	ejectMC52_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR53_���[�^���[�� or not(RLY_F2B�d���m�F)) then
	almTHR53_���[�^���[��=ON
	mMC53_���[�^���[��=OFF
	ejectMC53_���[�^���[��=OFF
	��������ErrStep=1
end if
'--2����BOX
if ldp(THR41_���[�^���[�� or not(RLY_����2�d���m�F)) then
	almTHR41_���[�^���[��=ON
	mMC41_���[�^���[��=OFF
	ejectMC41_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR42_���[�^���[�� or not(RLY_����2�d���m�F)) then
	almTHR42_���[�^���[��=ON
	mMC42_���[�^���[��=OFF
	ejectMC42_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR43_�������[�^ or not(RLY_����2�d���m�F)) then
	almTHR43_�������[�^=ON
	mMC43_�������[�^=OFF
	ejectMC43_�������[�^=OFF
	��������ErrStep=1
end if
if ldp(THR54_���[�^���[�� or not(RLY_����2�d���m�F)) then
	almTHR54_���[�^���[��=ON
	mMC54_���[�^���[��=OFF
	ejectMC54_���[�^���[��=OFF
	��������ErrStep=1
end if
if ldp(THR10_�������[�^ or not(RLY_����2�d���m�F)) then
	almTHR10_�������[�^=ON
	mMC10_�������[�^���]=OFF
	ejectMC10_�������[�^���]=OFF
	mMC10_�������[�^�t�]=OFF
	ejectMC10_�������[�^�t�]=OFF
	��������ErrStep=1
end if
if ldp(THR55_�������[�^ or not(RLY_����2�d���m�F)) then
	almTHR55_�������[�^=ON
	mMC55_�������[�^=OFF
	ejectMC55_�������[�^=OFF
	extMC55_�������[�^=OFF
	��������ErrStep=1
end if
if ldp(THR57_�������[�^ or not(RLY_����2�d���m�F)) then
	almTHR57_�������[�^=ON
	mMC57_�������[�^=OFF
	ejectMC57_�������[�^=OFF
	��������ErrStep=1
end if
'--���@BOX

if LDP( (THR58_���|���vA and MC58_���|���vA) or not(RLY_���@�d���m�F) ) then
	almTHR58_���|���vA=ON
	mMC58_���|���vA=OFF
	ejectMC58_���|���vA=OFF
	��������ErrStep=1
end if
if LDP( (THR59_���|���vB and MC59_���|���vB) or not(RLY_���@�d���m�F) ) then
	almTHR59_���|���vB=ON
	mMC59_���|���vB=OFF
	ejectMC59_���|���vB=OFF
	��������ErrStep=1
end if
if LDP( (THR60_���|���vC and MC60_���|���vC) or not(RLY_���@�d���m�F) ) then
	almTHR60_���|���vC=ON
	mMC60_���|���vC=OFF
	ejectMC60_���|���vC=OFF
	��������ErrStep=1
end if
if LDP( (THR61_���|���vD and MC61_���|���vD) or not(RLY_���@�d���m�F) ) then
	almTHR61_���|���vD=ON
	mMC61_���|���vD=OFF
	ejectMC61_���|���vD=OFF
	��������ErrStep=1
end if

if LDP( THR35_�������[�^ or not(RLY_���@�d���m�F) ) then
	almTHR35_�������[�^=ON
	mMC35_�������[�^=OFF
	ejectMC35_�������[�^=OFF
	��������ErrStep=1
end if
if LDP( THR36_���]���[�^ or not(RLY_���@�d���m�F) or RLY_SCR1_MC36_���]���[�^) then
	almTHR36_���]���[�^=ON
	mMC36_���]���[�^���]=OFF
	ejectMC36_���]���[�^���]=OFF
	mMC36_���]���[�^�t�]=OFF
	ejectMC36_���]���[�^�t�]=OFF
	��������ErrStep=1
end if
if LDP( THR38_�������[�^ or not(RLY_���@�d���m�F) ) then
	almTHR38_�������[�^=ON
	mMC38_�������[�^=OFF
	ejectMC38_�������[�^=OFF
	��������ErrStep=1
end if
if LDP( THR37_���]���[�^ or not(RLY_���@�d���m�F) or RLY_SCR2_MC37_���]���[�^) then
	almTHR37_���]���[�^=ON
	mMC37_���]���[�^���]=OFF
	ejectMC37_���]���[�^���]=OFF
	mMC37_���]���[�^�t�]=OFF
	ejectMC37_���]���[�^�t�]=OFF
	��������ErrStep=1
end if


'-----------------------------------------------------------
'�C���o�[�^�A���[��

if MC1_�C���o�[�^�p�d�� or not(RLY_���@�d���m�F) then
 	if anda(getM14c1,statALM)=statALM or  INV1_�R���x�A�ُ� then
		almINV1_�R���x�A�ُ�=ON
		mINV1_�R���x�A���[�^���]=OFF
		ejectINV1_�R���x�A���[�^���]=OFF
		��������ErrStep=1
	end if
	if  anda(getM14c2,statALM)=statALM or INV2_�R���x�A�ُ� then
		almINV2_�R���x�A�ُ�=ON
		mINV2_�R���x�A���[�^���]=OFF
		ejectINV2_�R���x�A���[�^���]=OFF
		��������ErrStep=1
	end if
	if  anda(getM14c3,statALM)=statALM or INV3_�R���x�A�ُ� then
		almINV3_�R���x�A�ُ�=ON
		mINV3_�R���x�A���[�^���]=OFF
		ejectINV3_�R���x�A���[�^���]=OFF
		��������ErrStep=1
	end if
end if


'-----------------------------------------------------------
' IH���ы@ ONLINE��� �ُ�Ȃ�

if not(IH���у��j�b�gAOrg) then
	IH���у��j�b�gAOrgErr=ON
	��������ErrStep=1
end if


if not(IH���у��j�b�gBOrg) then
	IH���у��j�b�gBOrgErr=ON
	��������ErrStep=1
end if

'===================================================================================================================
'�q�[�^�p�d��n�����o




'===================================================================================================================
'-----------------------------------------------------------
'���x���ߊ�A���[��
'
'��	EDC_ST1LBT0	1���[�h�����Ȃ�����	#1	$1:�q�[�^�d���l�I�[�o�[�iCT1�j
'��	EDC_ST1LBT1	1���[�h�����Ȃ�����	#2	$2:�q�[�^�d���l�z�[���h(CT1)
'��	EDC_ST1LBT2	1���[�h�����Ȃ�����	#4	$4:AD�R���o�[�^�ُ�
'��	EDC_ST1LBT3	1���[�h�����Ȃ�����	#8	$8:HS�iSSR�̏�j�x��(CT1)
'��	EDC_ST1LBT4	1���[�h�����Ȃ�����	#16	$10:RSP���ُ͈�
'��	EDC_ST1LBT6	1���[�h�����Ȃ�����	#64	$40:���ُ͈�
'��	EDC_ST1LBT7	1���[�h�����Ȃ�����	#128	$80:�|�e���V�������[�^���ُ͈�
'	EDC_ST1LBT8	1���[�h�����Ȃ�����	#256	$100:����o��(���M�j�I�[�v���o��
'	EDC_ST1LBT9	1���[�h�����Ȃ�����	#512	$200:����o��(��p)�N���[�Y�o��
'	EDC_ST1LBT10	1���[�h�����Ȃ�����	#1024	$400:HB(�q�[�^�f���j�x��(CT1)
'	EDC_ST1LBT11	1���[�h�����Ȃ�����	#2048	$800:HB(�q�[�^�f���j�x��(CT2)
'	EDC_ST1LBT12	1���[�h�����Ȃ�����	#4096	$1000:�x��1
'	EDC_ST1LBT13	1���[�h�����Ȃ�����	#8192	$2000:�x��2
'	EDC_ST1LBT14	1���[�h�����Ȃ�����	#16384	$4000:�x��3
'	EDC_ST1LBT15	1���[�h�����Ȃ�����	#32768	$8000:�v���O�����G���h�o��
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
	���x���ߊ�1Alm=ON
else
	���x���ߊ�1Alm=OFF
end if

if ANDA(getEDC2_ST1L,EDC_Almbit)<>0 then
	���x���ߊ�2Alm=ON
else
	���x���ߊ�2Alm=OFF
end if

if ANDA(getEDC3_ST1L,EDC_Almbit)<>0 then
	���x���ߊ�3Alm=ON
else
	���x���ߊ�3Alm=OFF
end if

if ANDA(getEDC4_ST1L,EDC_Almbit)<>0 then
	���x���ߊ�4Alm=ON
else
	���x���ߊ�4Alm=OFF
end if

if ANDA(getEDC5_ST1L,EDC_Almbit)<>0 then
	���x���ߊ�5Alm=ON
else
	���x���ߊ�5Alm=OFF
end if

'-----------------------------------------------------------
'�g�����j�b�g����ђʐM�G���[���o

if CR2306 then '�o�b�e���[�G���[ �����p���`�E���d�r  �^�� : KV-B1
	almDCPLC�d���d���~��=ON
end if

'-----------------------------------------------------------
'�A���[�������[�iCR3300�`CR3415�j�Ƀf�o�C�X�R�����g�Ƃ��ă��b�Z�[�W��o�^
'[�t�@�C��(F)] - CSV/TXT�`���Ńf�o�C�X�R�����g��ۑ�
'[�t�@�C��(F)] - CSV/TXT�`���̃f�o�C�X�R�����g��Ǐo

if  0 then	 		'հ�ޱװ�0
	set(CR3300)
else
	res(CR3300)	
end if
if  0 then	 		'հ�ޱװ�1
	set(CR3301)
else
	res(CR3301)	
end if
if  0 then	 		'հ�ޱװ�2
	set(CR3302)
else
	res(CR3302)	
end if
if  0 then	 		'հ�ޱװ�3
	set(CR3303)
else
	res(CR3303)	
end if
if  0 then	 		'հ�ޱװ�4
	set(CR3304)
else
	res(CR3304)	
end if
if  0 then	 		'հ�ޱװ�5
	set(CR3305)
else
	res(CR3305)	
end if
if  0 then	 		'հ�ޱװ�6
	set(CR3306)
else
	res(CR3306)	
end if
if  0 then	 		'հ�ޱװ�7
	set(CR3307)
else
	res(CR3307)	
end if
if  0 then	 		'հ�ޱװ�8
	set(CR3308)
else
	res(CR3308)	
end if
if  0 then	 		'հ�ޱװ�9
	set(CR3309)
else
	res(CR3309)	
end if
if  0 then	 		'հ�ޱװ�10
	set(CR3310)
else
	res(CR3310)	
end if
if  0 then	 		'հ�ޱװ�11
	set(CR3311)
else
	res(CR3311)	
end if
if  0 then	 		'հ�ޱװ�12
	set(CR3312)
else
	res(CR3312)	
end if
if  0 then	 		'հ�ޱװ�13
	set(CR3313)
else
	res(CR3313)	
end if
if  0 then	 		'հ�ޱװ�14
	set(CR3314)
else
	res(CR3314)	
end if
if  0 then	 		'հ�ޱװ�15
	set(CR3315)
else
	res(CR3315)	
end if
if  0 then	 		'հ�ޱװ�16
	set(CR3400)
else
	res(CR3400)	
end if
if  0 then	 		'հ�ޱװ�17
	set(CR3401)
else
	res(CR3401)	
end if
if  0 then	 		'հ�ޱװ�18
	set(CR3402)
else
	res(CR3402)	
end if
if  0 then	 		'հ�ޱװ�19
	set(CR3403)
else
	res(CR3403)	
end if
if  0 then	 		'հ�ޱװ�20
	set(CR3404)
else
	res(CR3404)	
end if
if  0 then	 		'հ�ޱװ�21
	set(CR3405)
else
	res(CR3405)	
end if
if  0 then	 		'հ�ޱװ�22
	set(CR3406)
else
	res(CR3406)	
end if
if  0 then	 		'հ�ޱװ�23
	set(CR3407)
else
	res(CR3407)	
end if
if  0 then	 		'հ�ޱװ�24
	set(CR3408)
else
	res(CR3408)	
end if
if  0 then	 		'հ�ޱװ�25
	set(CR3409)
else
	res(CR3409)	
end if
if  0 then	 		'հ�ޱװ�26
	set(CR3410)
else
	res(CR3410)	
end if
if  0 then	 		'հ�ޱװ�27
	set(CR3411)
else
	res(CR3411)	
end if
if  0 then	 		'հ�ޱװ�28
	set(CR3412)
else
	res(CR3412)	
end if
if  0 then	 		'հ�ޱװ�29
	set(CR3413)
else
	res(CR3413)	
end if
if  0 then	 		'հ�ޱװ�30
	set(CR3414)
else
	res(CR3414)	
end if
if  0 then	 		'հ�ޱװ�31
	set(CR3415)
else
	res(CR3415)	
end if

if 0 and CR3500 then 

end if


end if 'if systemwait.B then
'===================================================================================================================
