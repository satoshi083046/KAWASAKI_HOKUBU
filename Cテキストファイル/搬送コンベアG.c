'�����R���x�AG
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'---- �폜 ------
'�u���V��
'-----------------------------------------
'THR56_�u���V�T�[�}��
'XSW69_�u���V�㏸�[
'XSW70_�u���V���~�[
'-----------------------------------------
'MC56_�u���V���[�^
'SV65_�V�����_�㏸
'SV66_�V�����_���~
'-----------------------------------------

'===================================================================================================================
'
'	�����R���x�AG
'-----------------------------------------------------
' [ 37 ] �����H���x�AF1���o���t�g
'	MC41_���[�^���[��

'	PH49_�����m
'
'	SV47_���t�g	
'	XSW55_���t�g�㏸�[
'	XSW56_���t�g���~�[
'
'	SV44_�X�g�b�p
'	XSW59_�X�g�b�p�㏸�[
'	XSW60_�X�g�b�p���~�[
'-----------------------------------------------------
' [ 38 ] �����H���x�AF2���o���t�g
'	MC42_���[�^���[��
'
'	PH50_�����m
'
'	SV48_���t�g
'	XSW57_���t�g�㏸�[
'	XSW58_���t�g���~�[
'
'	SV45_�X�g�b�p
'	XSW61_�X�g�b�p�㏸�[
'	XSW62_�X�g�b�p���~�[
'
'-----------------------------------------------------
' [ 39 ] �t�^��芘�X�g�b�p
'	MC43_�������[�^
'
'	PH51_�����m
'	PH52_�t�^���m
'
'	SV46_�X�g�b�p
'	XSW63_�X�g�b�p�㏸�[
'	XSW64_�X�g�b�p���~�[
'
'-----------------------------------------------------
' [ 40 ] �����R���x�AG���o���t�g
'	MC54_���[�^���[��
'
'	PH53_�����m
'	PH54_�t�^���m
'
'	SV50_���t�g
'	XSW56_���t�g�㏸�[
'	XSW68_���t�g���~�[
'
'	SV49_�X�g�b�p
'	XSW65_�X�g�b�p�㏸�[
'	XSW66_�X�g�b�p���~�[
'
'===================================================================================================================
'�y ���������� �z
if CR2008 then '�d��ON������������
    �����R���x�AGAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �����R���x�AGAutoRun=OFF
    �����R���x�AG����=ON
    �����R���x�AGOrgErr=OFF
    �����R���x�AGErr=OFF
    �����R���x�AGEmg=OFF
    �����R���x�AGstep=0
    �����R���x�AGErrStep=0
    �����R���x�AGOrgErrStep=0
    �����R���x�AGEmgStep=0

	SV46_�X�g�b�pstep=0
	�t�^���r�ostep=0
	���t�gF1����step=0
	���t�gF1�r�ostep=0
	���t�gF2����step=0
	���t�gF2�r�ostep=0

	if PH49_�����m then
		mSV44_�X�g�b�p=ON
		mSV47_���t�g=ON
	end if
	
	if PH50_�����m then
		mSV45_�X�g�b�p=ON
		mSV48_���t�g=ON
	end if

	if PH51_�����m then
		mSV46_�X�g�b�p=ON
	end if

	mSV49_�X�g�b�p=ON
	mSV50_���t�g=ON

	if SSW3_�������[�h then
		ManualInite=1
	else
		ManualInite=0	
	end if
	
				


end if
'===================================================================================================================
'�y ���_ �z
�����R���x�AGOrg=((XSW55_���t�g�㏸�[ and not(pnlPBXSW55_���t�g�㏸�[)) or passXSW55_���t�g�㏸�[) or ((XSW56_���t�g���~�[ and not(pnlPBXSW56_���t�g���~�[)) or passXSW56_���t�g���~�[)
�����R���x�AGOrg= �����R���x�AGOrg and (((XSW59_�X�g�b�p�㏸�[ and not(pnlPBXSW59_�X�g�b�p�㏸�[)) or passXSW59_�X�g�b�p�㏸�[) or ((XSW60_�X�g�b�p���~�[ and not(pnlPBXSW60_�X�g�b�p���~�[)) or passXSW60_�X�g�b�p���~�[))
�����R���x�AGOrg= �����R���x�AGOrg and (((XSW57_���t�g�㏸�[ and not(pnlPBXSW57_���t�g�㏸�[)) or passXSW57_���t�g�㏸�[) or ((XSW58_���t�g���~�[ and not(pnlPBXSW58_���t�g���~�[)) or passXSW58_���t�g���~�[))
�����R���x�AGOrg= �����R���x�AGOrg and (((XSW61_�X�g�b�p�㏸�[ and not(pnlPBXSW61_�X�g�b�p�㏸�[)) or passXSW61_�X�g�b�p�㏸�[) or ((XSW62_�X�g�b�p���~�[ and not(pnlPBXSW62_�X�g�b�p���~�[)) or passXSW62_�X�g�b�p���~�[))
�����R���x�AGOrg= �����R���x�AGOrg and (((XSW63_�X�g�b�p�㏸�[ and not(pnlPBXSW63_�X�g�b�p�㏸�[)) or passXSW63_�X�g�b�p�㏸�[) or ((XSW64_�X�g�b�p���~�[ and not(pnlPBXSW64_�X�g�b�p���~�[)) or passXSW64_�X�g�b�p���~�[))
�����R���x�AGOrg= �����R���x�AGOrg and (((XSW67_���t�g�㏸�[ and not(pnlPBXSW67_���t�g�㏸�[)) or passXSW67_���t�g�㏸�[) or ((XSW68_���t�g���~�[ and not(pnlPBXSW68_���t�g���~�[)) or passXSW68_���t�g���~�[))
�����R���x�AGOrg= �����R���x�AGOrg and (((XSW65_�X�g�b�p�㏸�[ and not(pnlPBXSW65_�X�g�b�p�㏸�[)) or passXSW65_�X�g�b�p�㏸�[) or ((XSW66_�X�g�b�p���~�[ and not(pnlPBXSW66_�X�g�b�p���~�[)) or passXSW66_�X�g�b�p���~�[))

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�����R���x�AGEmg=ON
	�����R���x�AGEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
' �����H���x�AF1���o���t�g
tmr(SV47_���t�g and not(XSW55_���t�g�㏸�[) and not(pnlPBXSW55_���t�g�㏸�[), tim_notXSW55_���t�g�㏸�[, #40)
tmr(not(SV47_���t�g) and not(XSW56_���t�g���~�[) and not(pnlPBXSW56_���t�g���~�[),tim_notXSW56_���t�g���~�[, #40)
tmr(SV44_�X�g�b�p and not(XSW59_�X�g�b�p�㏸�[) and not(pnlPBXSW59_�X�g�b�p�㏸�[),tim_notXSW59_�X�g�b�p�㏸�[,#40)
tmr(not(SV44_�X�g�b�p) and not(XSW60_�X�g�b�p���~�[) and not(pnlPBXSW60_�X�g�b�p���~�[),tim_notXSW60_�X�g�b�p���~�[,#40)

'tmr(not(SV47_���t�g) and XSW55_���t�g�㏸�[ and not(pnlPBXSW55_���t�g�㏸�[), tim_XSW55_���t�g�㏸�[, #10)
if LDP(SV47_���t�g) and XSW55_���t�g�㏸�[ and not(pnlPBXSW55_���t�g�㏸�[) then
	SET(tim_XSW55_���t�g�㏸�[)
end if
'tmr(SV47_���t�g and XSW56_���t�g���~�[ and not(pnlPBXSW56_���t�g���~�[),tim_XSW56_���t�g���~�[, #10)
if LDF(SV47_���t�g) and XSW56_���t�g���~�[ and not(pnlPBXSW56_���t�g���~�[) and not(pauseSV47_���t�g) then
	SET(tim_XSW56_���t�g���~�[)
end if
'tmr(not(SV44_�X�g�b�p) and XSW59_�X�g�b�p�㏸�[ and not(pnlPBXSW59_�X�g�b�p�㏸�[),tim_XSW59_�X�g�b�p�㏸�[,#10)
if LDP(SV44_�X�g�b�p) and XSW59_�X�g�b�p�㏸�[ and not(pnlPBXSW59_�X�g�b�p�㏸�[) then
	SET(tim_XSW59_�X�g�b�p�㏸�[)
end if
'tmr(SV44_�X�g�b�p and XSW60_�X�g�b�p���~�[ and not(pnlPBXSW60_�X�g�b�p���~�[),tim_XSW60_�X�g�b�p���~�[,#10)
if LDF(SV44_�X�g�b�p) and XSW60_�X�g�b�p���~�[ and not(pnlPBXSW60_�X�g�b�p���~�[) and not(pauseSV44_�X�g�b�p) then
	SET(tim_XSW60_�X�g�b�p���~�[)
end if

' �����H���x�AF2���o���t�g
tmr(SV48_���t�g and not(XSW57_���t�g�㏸�[) and not(pnlPBXSW57_���t�g�㏸�[), tim_notXSW57_���t�g�㏸�[, #40)
tmr(not(SV48_���t�g) and not(XSW58_���t�g���~�[) and not(pnlPBXSW58_���t�g���~�[),tim_notXSW58_���t�g���~�[, #40)
tmr(SV45_�X�g�b�p and not(XSW61_�X�g�b�p�㏸�[) and not(pnlPBXSW61_�X�g�b�p�㏸�[),tim_notXSW61_�X�g�b�p�㏸�[,#40)
tmr(not(SV45_�X�g�b�p) and not(XSW62_�X�g�b�p���~�[) and not(pnlPBXSW62_�X�g�b�p���~�[),tim_notXSW62_�X�g�b�p���~�[,#40)

'tmr(not(SV48_���t�g) and XSW57_���t�g�㏸�[ and not(pnlPBXSW57_���t�g�㏸�[), tim_XSW57_���t�g�㏸�[, #10)
if LDP(SV48_���t�g) and XSW57_���t�g�㏸�[ and not(pnlPBXSW57_���t�g�㏸�[) then
	SET(tim_XSW57_���t�g�㏸�[)
end if
'tmr(SV48_���t�g and XSW58_���t�g���~�[ and not(pnlPBXSW58_���t�g���~�[),tim_XSW58_���t�g���~�[, #10)
if LDF(SV48_���t�g) and XSW58_���t�g���~�[ and not(pnlPBXSW58_���t�g���~�[) and not(pauseSV48_���t�g) then
	SET(tim_XSW58_���t�g���~�[)
end if
'tmr(not(SV45_�X�g�b�p) and XSW61_�X�g�b�p�㏸�[ and not(pnlPBXSW61_�X�g�b�p�㏸�[),tim_XSW61_�X�g�b�p�㏸�[,#10)
if LDP(SV45_�X�g�b�p) and XSW61_�X�g�b�p�㏸�[ and not(pnlPBXSW61_�X�g�b�p�㏸�[) then
	SET(tim_XSW61_�X�g�b�p�㏸�[)
end if
'tmr(SV45_�X�g�b�p and XSW62_�X�g�b�p���~�[ and not(pnlPBXSW62_�X�g�b�p���~�[),tim_XSW62_�X�g�b�p���~�[,#10)
if LDF(SV45_�X�g�b�p) and XSW62_�X�g�b�p���~�[ and not(pnlPBXSW62_�X�g�b�p���~�[) and not(pauseSV45_�X�g�b�p) then
	SET(tim_XSW62_�X�g�b�p���~�[)
end if
'�t�^��芘�X�g�b�p
tmr(SV46_�X�g�b�p and not(XSW63_�X�g�b�p�㏸�[) and not(pnlPBXSW63_�X�g�b�p�㏸�[),tim_notXSW63_�X�g�b�p�㏸�[,#40)
tmr(not(SV46_�X�g�b�p) and not(XSW64_�X�g�b�p���~�[) and not(pnlPBXSW64_�X�g�b�p���~�[),tim_notXSW64_�X�g�b�p���~�[,#40)

'tmr(not(SV46_�X�g�b�p) and XSW63_�X�g�b�p�㏸�[ and not(pnlPBXSW63_�X�g�b�p�㏸�[),tim_XSW63_�X�g�b�p�㏸�[,#10)
if LDP(SV46_�X�g�b�p) and XSW63_�X�g�b�p�㏸�[ and not(pnlPBXSW63_�X�g�b�p�㏸�[) then
	SET(tim_XSW63_�X�g�b�p�㏸�[)
end if
'tmr(SV46_�X�g�b�p and XSW64_�X�g�b�p���~�[ and not(pnlPBXSW64_�X�g�b�p���~�[),tim_XSW64_�X�g�b�p���~�[,#10)
if LDF(SV46_�X�g�b�p) and XSW64_�X�g�b�p���~�[ and not(pnlPBXSW64_�X�g�b�p���~�[) and not(pauseSV46_�X�g�b�p) then
	SET(tim_XSW64_�X�g�b�p���~�[)
end if

'�����R���x�AG���o���t�g
tmr(SV50_���t�g and not(XSW67_���t�g�㏸�[) and not(pnlPBXSW67_���t�g�㏸�[), tim_notXSW67_���t�g�㏸�[, #40)
tmr(not(SV50_���t�g) and not(XSW68_���t�g���~�[) and not(pnlPBXSW68_���t�g���~�[),tim_notXSW68_���t�g���~�[, #40)
tmr(SV49_�X�g�b�p and not(XSW65_�X�g�b�p�㏸�[) and not(pnlPBXSW65_�X�g�b�p�㏸�[),tim_notXSW65_�X�g�b�p�㏸�[,#40)
tmr(not(SV49_�X�g�b�p) and not(XSW66_�X�g�b�p���~�[) and not(pnlPBXSW66_�X�g�b�p���~�[),tim_notXSW66_�X�g�b�p���~�[,#40)

'tmr(not(SV50_���t�g) and XSW67_���t�g�㏸�[ and not(pnlPBXSW67_���t�g�㏸�[), tim_XSW67_���t�g�㏸�[, #10)
if LDP(SV50_���t�g) and XSW67_���t�g�㏸�[ and not(pnlPBXSW67_���t�g�㏸�[) then
	SET(tim_XSW67_���t�g�㏸�[)
end if
'tmr(SV50_���t�g and XSW68_���t�g���~�[ and not(pnlPBXSW68_���t�g���~�[),tim_XSW68_���t�g���~�[, #10)
if LDF(SV50_���t�g) and XSW68_���t�g���~�[ and not(pnlPBXSW68_���t�g���~�[) and not(pauseSV50_���t�g) then
	SET(tim_XSW68_���t�g���~�[)
end if
'tmr(not(SV49_�X�g�b�p) and XSW65_�X�g�b�p�㏸�[ and not(pnlPBXSW65_�X�g�b�p�㏸�[),tim_XSW65_�X�g�b�p�㏸�[,#10)
if LDP(SV49_�X�g�b�p) and XSW65_�X�g�b�p�㏸�[ and not(pnlPBXSW65_�X�g�b�p�㏸�[) then
	SET(tim_XSW65_�X�g�b�p�㏸�[)
end if
'tmr(SV49_�X�g�b�p and XSW66_�X�g�b�p���~�[ and not(pnlPBXSW66_�X�g�b�p���~�[),tim_XSW66_�X�g�b�p���~�[,#10)
if LDF(SV49_�X�g�b�p) and XSW66_�X�g�b�p���~�[ and not(pnlPBXSW66_�X�g�b�p���~�[) and not(pauseSV49_�X�g�b�p) then
	SET(tim_XSW66_�X�g�b�p���~�[)
end if
' -------------------------------------------------------------------------------------------------------------------
' �����H���x�AF1���o���t�g
tms(SV47_���t�g,passtimXSW55_���t�g�㏸�[,passtimXSW55_���t�g�㏸�[_val)
tms(not(SV47_���t�g),passtimXSW56_���t�g���~�[,passtimXSW56_���t�g���~�[_val)
tms(SV44_�X�g�b�p,passtimXSW59_�X�g�b�p�㏸�[,passtimXSW59_�X�g�b�p�㏸�[_val)
tms(not(SV44_�X�g�b�p),passtimXSW60_�X�g�b�p���~�[,passtimXSW60_�X�g�b�p���~�[_val)

' �����H���x�AF2���o���t�g
tms(SV48_���t�g,passtimXSW57_���t�g�㏸�[,passtimXSW57_���t�g�㏸�[_val)
tms(not(SV48_���t�g),passtimXSW58_���t�g���~�[,passtimXSW58_���t�g���~�[_val)
tms(SV45_�X�g�b�p,passtimXSW61_�X�g�b�p�㏸�[,passtimXSW61_�X�g�b�p�㏸�[_val)
tms(not(SV45_�X�g�b�p),passtimXSW62_�X�g�b�p���~�[,passtimXSW62_�X�g�b�p���~�[_val)

'�t�^��芘�X�g�b�p
tms(SV46_�X�g�b�p,passtimXSW63_�X�g�b�p�㏸�[,passtimXSW63_�X�g�b�p�㏸�[_val)
tms(not(SV46_�X�g�b�p),passtimXSW64_�X�g�b�p���~�[,passtimXSW64_�X�g�b�p���~�[_val)

'�����R���x�AG���o���t�g
tms(SV50_���t�g,passtimXSW67_���t�g�㏸�[,passtimXSW67_���t�g�㏸�[_val)
tms(not(SV50_���t�g),passtimXSW68_���t�g���~�[,passtimXSW68_���t�g���~�[_val)
tms(SV49_�X�g�b�p,passtimXSW65_�X�g�b�p�㏸�[,passtimXSW65_�X�g�b�p�㏸�[_val)
tms(not(SV49_�X�g�b�p),passtimXSW66_�X�g�b�p���~�[,passtimXSW66_�X�g�b�p���~�[_val)

'--------------------------------------------------
tmr(MC54_���[�^���[��,timerr_MC54_���[�^���[��,#65)

'--------------------------------------------------
if ldp(timerr_MC54_���[�^���[��.B) then
	errpassMC54_���[�^���[��=ON
	mMC54_���[�^���[��=OFF
	almMC54_���[�^���[��=ON
	�����R���x�AGErrStep=1

'--------------------------------------------------
else if ldp(tim_XSW55_���t�g�㏸�[.B) or ldp(tim_notXSW55_���t�g�㏸�[.B) then
	errpassXSW55_���t�g�㏸�[=ON
	almXSW55_���t�g�㏸�[=ON
	pnlPBXSW55_���t�g�㏸�[=ON
	�����R���x�AGErrStep=1

else if ldp(tim_XSW56_���t�g���~�[.B) or ldp(tim_notXSW56_���t�g���~�[.B) then
	errpassXSW56_���t�g���~�[=ON
	almXSW56_���t�g���~�[=ON
	pnlPBXSW56_���t�g���~�[=ON
	�����R���x�AGErrStep=1
'--------------------------------------------------
else if ldp(tim_XSW59_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW59_�X�g�b�p�㏸�[.B) then
	errpassXSW59_�X�g�b�p�㏸�[=ON
	'pauseSV44_�X�g�b�p=ON
	almXSW59_�X�g�b�p�㏸�[=ON
	pnlPBXSW59_�X�g�b�p�㏸�[=ON
	�����R���x�AGErrStep=1

else if ldp(tim_XSW60_�X�g�b�p���~�[.B) or ldp(tim_notXSW60_�X�g�b�p���~�[.B) then
	errpassXSW60_�X�g�b�p���~�[=ON
	almXSW60_�X�g�b�p���~�[=ON
	pnlPBXSW60_�X�g�b�p���~�[=ON
	�����R���x�AGErrStep=1

'--------------------------------------------------
else if ldp(tim_XSW57_���t�g�㏸�[.B) or ldp(tim_notXSW57_���t�g�㏸�[.B) then
	errpassXSW57_���t�g�㏸�[=ON
	almXSW57_���t�g�㏸�[=ON
	pnlPBXSW57_���t�g�㏸�[=ON
	�����R���x�AGErrStep=1

else if ldp(tim_XSW58_���t�g���~�[.B) or ldp(tim_notXSW58_���t�g���~�[.B) then
	errpassXSW58_���t�g���~�[=ON
	almXSW58_���t�g���~�[=ON
	pnlPBXSW58_���t�g���~�[=ON
	�����R���x�AGErrStep=1

'--------------------------------------------------
else if ldp(tim_XSW61_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW61_�X�g�b�p�㏸�[.B) then
	errpassXSW61_�X�g�b�p�㏸�[=ON
	'pauseSV45_�X�g�b�p=ON
	almXSW61_�X�g�b�p�㏸�[=ON
	pnlPBXSW61_�X�g�b�p�㏸�[=ON
	�����R���x�AGErrStep=1

else if ldp(tim_XSW62_�X�g�b�p���~�[.B) or ldp(tim_notXSW62_�X�g�b�p���~�[.B) then
	errpassXSW62_�X�g�b�p���~�[=ON
	almXSW62_�X�g�b�p���~�[=ON
	pnlPBXSW62_�X�g�b�p���~�[=ON
	�����R���x�AGErrStep=1

'--------------------------------------------------
else if ldp(tim_XSW63_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW63_�X�g�b�p�㏸�[.B) then
	errpassXSW63_�X�g�b�p�㏸�[=ON
	pauseSV46_�X�g�b�p=ON
	almXSW63_�X�g�b�p�㏸�[=ON
	pnlPBXSW63_�X�g�b�p�㏸�[=ON
	�����R���x�AGErrStep=1

else if ldp(tim_XSW64_�X�g�b�p���~�[.B) or ldp(tim_notXSW64_�X�g�b�p���~�[.B) then
	errpassXSW64_�X�g�b�p���~�[=ON
	almXSW64_�X�g�b�p���~�[=ON
	pnlPBXSW64_�X�g�b�p���~�[=ON
	�����R���x�AGErrStep=1

'--------------------------------------------------
else if (�����R���x�AGStep>0  and �����R���x�AHStep=0) and (ldp(tim_XSW67_���t�g�㏸�[.B) or ldp(tim_notXSW67_���t�g�㏸�[.B)) then
	errpassXSW67_���t�g�㏸�[=ON
	almXSW67_���t�g�㏸�[=ON
	pnlPBXSW67_���t�g�㏸�[=ON
	�����R���x�AGErrStep=1

else if (�����R���x�AGStep>0  and �����R���x�AHStep=0) and (ldp(tim_XSW68_���t�g���~�[.B) or ldp(tim_notXSW68_���t�g���~�[.B)) then
	errpassXSW68_���t�g���~�[=ON
	almXSW68_���t�g���~�[=ON
	pnlPBXSW68_���t�g���~�[=ON
	�����R���x�AGErrStep=1

'--------------------------------------------------
else if (�����R���x�AGStep>0  and �����R���x�AHStep=0) and (ldp(tim_XSW65_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW65_�X�g�b�p�㏸�[.B)) then
	errpassXSW65_�X�g�b�p�㏸�[=ON
	'pauseSV49_�X�g�b�p=ON
	almXSW65_�X�g�b�p�㏸�[=ON
	pnlPBXSW65_�X�g�b�p�㏸�[=ON
	�����R���x�AGErrStep=1

else if (�����R���x�AGStep>0  and �����R���x�AHStep=0) and (ldp(tim_XSW66_�X�g�b�p���~�[.B) or ldp(tim_notXSW66_�X�g�b�p���~�[.B)) then
	errpassXSW66_�X�g�b�p���~�[=ON
	almXSW66_�X�g�b�p���~�[=ON
	pnlPBXSW66_�X�g�b�p���~�[=ON
	�����R���x�AGErrStep=1
'--------------------------------------------------

end if

'===================================================================================================================


'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �����R���x�AGEmgStep	�������[�h �Z���N�g�X�C�b�`
'System :: �����R���x�AGAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �����R���x�AGEmg	���̏��~


if �����R���x�AGEmgStep=0 then  
	
	if �����R���x�AGErrStep=0  then

	if not(�����R���x�AGOrgErr) then

	if (�����R���x�AGAutoMode and ��������AutoMode ) or �����R���x�AGstep<>0 or ���t�gF1����step<>0 or ���t�gF2����step<>0 then
	

		if ManualInite=0 then
			if PH49_�����m then
				mSV44_�X�g�b�p=ON
				mSV47_���t�g=ON
			else
				mSV44_�X�g�b�p=OFF
				mSV47_���t�g=OFF
			end if
			
			if PH50_�����m then
				mSV45_�X�g�b�p=ON
				mSV48_���t�g=ON
			else
				mSV45_�X�g�b�p=OFF
				mSV48_���t�g=OFF
			end if
			
			if PH51_�����m then
				mSV46_�X�g�b�p=ON
			end if
						
			mSV49_�X�g�b�p=ON
			mSV50_���t�g=ON


			ManualInite=1
		end if
		
	
		if not(�����R���x�AGAutoMode and ��������AutoMode ) then
			�����R���x�AGAutoRun=OFF
		end if

		'--------------------------------------------
		'�y �t�^���X�g�b�p �z
		'--------------------------------------------
		tmr(tim_SV46_�X�g�b�p,tim_SV46_�X�g�b�p_val)
	
		select case SV46_�X�g�b�pstep
		case 0
		
		case 1
			PH51_���N�����m = PH51_�����m
			PH52_�t�^�N�����m = PH52_�t�^���m
			
			if PH51_���N�����m or PH52_�t�^�N�����m then
				inc(SV46_�X�g�b�pstep)
			else
				mSV46_�X�g�b�p=ON '�t�^���
				SV46_�X�g�b�pstep=0
			end if
		
		case 2
			mSV46_�X�g�b�p=OFF '�t�^���
			errpassXSW64_�X�g�b�p���~�[=OFF
			inc(SV46_�X�g�b�pstep)
		
		case 3
			if errpassXSW64_�X�g�b�p���~�[ or ((XSW64_�X�g�b�p���~�[ and not(pnlPBXSW64_�X�g�b�p���~�[)) or passXSW64_�X�g�b�p���~�[) then
				inc(SV46_�X�g�b�pstep)
			end if
		
		case 4
			if not(PH51_�����m) and not(PH52_�t�^���m) then
				inc(SV46_�X�g�b�pstep)
			end if
		
		
		case 5
			if PH53_�����m or PH54_�t�^���m then
				inc(SV46_�X�g�b�pstep)
			end if			
		
		case 6
			mSV46_�X�g�b�p=ON '�t�^���
			errpassXSW63_�X�g�b�p�㏸�[=OFF
			inc(SV46_�X�g�b�pstep)
		
		case 7
			if errpassXSW63_�X�g�b�p�㏸�[ or ((XSW63_�X�g�b�p�㏸�[ and not(pnlPBXSW63_�X�g�b�p�㏸�[)) or passXSW63_�X�g�b�p�㏸�[) then
				inc(SV46_�X�g�b�pstep)
			end if
		
		case 8
			SV46_�X�g�b�pstep=0

		end select
		'--------------------------------------------
		'�y �t�^���r�o �z
		'--------------------------------------------
		tmr(tim_�t�^���r�o,tim_�t�^���r�o_val)
	
		select case �t�^���r�ostep
		case 0
	
		case 1
			PH51_���N�����m = PH51_�����m
			PH52_�t�^�N�����m = PH52_�t�^���m
			
			if PH51_���N�����m or PH52_�t�^�N�����m then
				inc(�t�^���r�ostep)
			else
				�t�^���r�ostep=0
			end if
		
		case 2
			�����R���x�AG���쒆=ON
			'���t�g��
			mSV50_���t�g=ON
			errpassXSW67_���t�g�㏸�[=OFF
			mSV49_�X�g�b�p=ON '���t�g�X�g�b�p�[
			errpassXSW65_�X�g�b�p�㏸�[=OFF
			
			inc(�t�^���r�ostep)

		case 3
			if (errpassXSW67_���t�g�㏸�[ or ((XSW67_���t�g�㏸�[ and not(pnlPBXSW67_���t�g�㏸�[)) or passXSW67_���t�g�㏸�[)) and (errpassXSW65_�X�g�b�p�㏸�[ or ((XSW65_�X�g�b�p�㏸�[ and not(pnlPBXSW65_�X�g�b�p�㏸�[)) or passXSW65_�X�g�b�p�㏸�[)) then
				inc(�t�^���r�ostep)
			end if
		
		case 4
			'�t�^��胆�j�b�g�㏸�[�m�F
			if ((XSW55_�V�����_�㏸�[A and not(pnlPBXSW55_�V�����_�㏸�[A)) or passXSW55_�V�����_�㏸�[A) and ((XSW57_�V�����_�㏸�[B and not(pnlPBXSW57_�V�����_�㏸�[B))  or passXSW57_�V�����_�㏸�[B) then
				inc(�t�^���r�ostep)
			end if
		
		case 5
			mMC54_���[�^���[��=ON
			errpassMC54_���[�^���[��=OFF
			mMC43_�������[�^=ON
			inc(�t�^���r�ostep)
		
		case 6
			if errpassMC54_���[�^���[�� then
				inc(�t�^���r�ostep)
			
			else if not(PH51_�����m) and not(PH52_�t�^���m) then
				inc(�t�^���r�ostep)
			end if

		case 7
			if PH53_�����m or PH54_�t�^���m then
				inc(�t�^���r�ostep)
			end if
		
		case 8
			tim_�t�^���r�o_val=12
			res(tim_�t�^���r�o)
			inc(�t�^���r�ostep)
		
		case 9
			if tim_�t�^���r�o.B then
				inc(�t�^���r�ostep)
			end if

		case 10
			StageDevice40=StageDevice39
			mMC54_���[�^���[��=OFF
			mMC43_�������[�^=OFF
			inc(�t�^���r�ostep)
				
		case 11
			if not(PH53_�����m) and  PH54_�t�^���m then			
				�R���x�AH���r�o�ҋ@=OFF
			end if
		
			�����R���x�AG�r�o�v��=ON
			�t�^���r�ostep=0

		end select

		'--------------------------------------------
		'�y �����R���x�AF1����
		'--------------------------------------------
		tmr(tim_���t�gF1����,tim_���t�gF1����_val)
		
		select case ���t�gF1����step
		case 0
		
		case 1
			if not(PH49_�����m) and PH36_�����m and �����R���x�AF1�r�o�v�� then
				mSV47_���t�g=ON
				errpassXSW55_���t�g�㏸�[=OFF
				mSV44_�X�g�b�p=ON
				errpassXSW59_�X�g�b�p�㏸�[=OFF
				inc(���t�gF1����step)
			else
				���t�gF1����step=0
			end if
			
		case 2
			if errpassXSW55_���t�g�㏸�[ or ((XSW55_���t�g�㏸�[ and not(pnlPBXSW55_���t�g�㏸�[)) or passXSW55_���t�g�㏸�[) then
				inc(���t�gF1����step)
			end if
			
		case 3
			if errpassXSW59_�X�g�b�p�㏸�[ or ((XSW59_�X�g�b�p�㏸�[ and not(pnlPBXSW59_�X�g�b�p�㏸�[)) or passXSW59_�X�g�b�p�㏸�[) then
				inc(���t�gF1����step)
			end if

		case 4
			mMC41_���[�^���[��=ON
			mMC28_���[�^���[��=ON
			inc(���t�gF1����step)

		case 5
			if not(PH36_�����m) then
				inc(���t�gF1����step)
			end if
			
		case 6
			if PH49_�����m then
				inc(���t�gF1����step)
			end if
		
		case 7
			tim_���t�gF1����_val=15
			res(tim_���t�gF1����)
			inc(���t�gF1����step)
		
		case 8
			if tim_���t�gF1����.B then
				inc(���t�gF1����step)
			end if			
		
		case 9
			StageDevice37=StageDevice24
			if ANDA(StageDevice37,$FF)>0 and ANDA(StageDevice37,$FF)<99 then
				�����҂���~=ON
			end if
			
			mMC41_���[�^���[��=OFF
			mMC28_���[�^���[��=OFF
			inc(���t�gF1����step)
			
		case 10
			�����R���x�AF1�r�o�v��=OFF
			���t�gF1����step=0

		end select

		'--------------------------------------------
		'�y �����R���x�AF1�r�o
		'--------------------------------------------
		tmr(tim_���t�gF1�r�o,tim_���t�gF1�r�o_val)
		
		select case ���t�gF1�r�ostep
		
		case 0
		
		case 1
			if PH49_�����m and not(PH50_�����m) then
				inc(���t�gF1�r�ostep)
			else
				���t�gF1�r�ostep=0
			end if

		case 2
			ejectMC43_�������[�^=ON
			inc(���t�gF1�r�ostep)
		
		case 3
			if not(PH49_�����m) then
				inc(���t�gF1�r�ostep)
			end if
		
		case 4
			if PH51_�����m and PH52_�t�^���m then
				inc(���t�gF1�r�ostep)
			end if
			
		case 5
			tim_���t�gF1�r�o_val=12
			res(tim_���t�gF1�r�o)
			inc(���t�gF1�r�ostep)
		
		case 6
			if tim_���t�gF1�r�o.B then
				inc(���t�gF1�r�ostep)
			end if
		
		case 7
			StageDevice39=StageDevice37
			ejectMC43_�������[�^=OFF
			inc(���t�gF1�r�ostep)
		
		case 8
			���t�gF1�r�ostep=0

		end select
		'--------------------------------------------
		'�y �����R���x�AF2���� �z
		'--------------------------------------------
		tmr(tim_���t�gF2����,tim_���t�gF2����_val)
		
		select case ���t�gF2����step
		case 0
		
		case 1
			if not(PH49_�����m) and not(PH50_�����m) and PH48_�����m and �����R���x�AF2�r�o�v�� then
				mSV48_���t�g=ON
				errpassXSW57_���t�g�㏸�[=OFF
				mSV45_�X�g�b�p=ON
				errpassXSW61_�X�g�b�p�㏸�[=OFF
				inc(���t�gF2����step)
			else
				���t�gF2����step=0
			end if
			
		case 2
			if errpassXSW57_���t�g�㏸�[ or ((XSW57_���t�g�㏸�[ and not(pnlPBXSW57_���t�g�㏸�[)) or passXSW57_���t�g�㏸�[) then
				inc(���t�gF2����step)
			end if
			
		case 3
			if errpassXSW61_�X�g�b�p�㏸�[ or ((XSW61_�X�g�b�p�㏸�[ and not(pnlPBXSW61_�X�g�b�p�㏸�[)) or passXSW61_�X�g�b�p�㏸�[) then
				inc(���t�gF2����step)
			end if

		case 4
			mMC42_���[�^���[��=ON
			mMC53_���[�^���[��=ON
			inc(���t�gF2����step)

		case 5
			if not(PH48_�����m) then
				inc(���t�gF2����step)
			end if
			
		case 6
			if PH50_�����m then
				inc(���t�gF2����step)
			end if
		
		case 7
			tim_���t�gF2����_val=15
			res(tim_���t�gF2����)
			inc(���t�gF2����step)
		
		case 8
			if tim_���t�gF2����.B then
				inc(���t�gF2����step)
			end if
			
		case 9
			StageDevice38=StageDevice36
			if ANDA(StageDevice38,$FF)>0 and ANDA(StageDevice38,$FF)<99 then
				�����҂���~=ON
			end if
			mMC42_���[�^���[��=OFF
			mMC53_���[�^���[��=OFF
			inc(���t�gF2����step)
			
		case 10
			�����R���x�AF2�r�o�v��=OFF
			���t�gF2����step=0
		end select

		'--------------------------------------------
		'�y �����R���x�AF2�r�o
		'--------------------------------------------
		tmr(tim_���t�gF2�r�o,tim_���t�gF2�r�o_val)
		
		select case ���t�gF2�r�ostep
		case 0

		case 1
			if PH50_�����m then
				inc(���t�gF2�r�ostep)
			else
				���t�gF2�r�ostep=0
			end if
		
		case 2
			ejectMC43_�������[�^=ON
			inc(���t�gF2�r�ostep)

		case 3
			if not(PH50_�����m) then
				inc(���t�gF2�r�ostep)
			end if
	
		case 4
			if PH51_�����m and PH52_�t�^���m then
				inc(���t�gF2�r�ostep)
			end if
			
		case 5
			tim_���t�gF2�r�o_val=12
			res(tim_���t�gF2�r�o)
			inc(���t�gF2�r�ostep)
		
		case 6
			if tim_���t�gF2�r�o.B then
				inc(���t�gF2�r�ostep)
			end if
		
		case 7
			StageDevice39=StageDevice38
			ejectMC43_�������[�^=OFF
			inc(���t�gF2�r�ostep)

		case 8
			���t�gF2�r�ostep=0
		
		end select
	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case �����R���x�AGstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �����R���x�AGAutoRun then
				inc(�����R���x�AGstep)
			else 
				�����R���x�AGstep=0 '�I���ҋ@
			end if
		
		case 2
			if  �t�^��芮�� then
				inc(�����R���x�AGstep)			
			else
				�����R���x�AGstep=1
			end if
		
		case 3
			if (MC10_�������[�^���] or MC10_�������[�^�t�]) or (PH53_�����m or PH54_�t�^���m) then '�r�o���t�g
				�����R���x�AG���쒆=OFF
				�����R���x�AG�r�o�v��=ON
				�����R���x�AGstep=1
			else
				inc(�����R���x�AGstep)		
			end if

		case 4
			if not(PH49_�����m)  and not(PH50_�����m) then
				if not(PH49_�����m) and ���t�gF1����step=0 then
					���t�gF1����step=1
				end if
				
				if not(PH50_�����m) and ���t�gF2����step=0 then
					���t�gF2����step=1
				end if

				�����R���x�AGstep=1
			else
				inc(�����R���x�AGstep)
			end if
		

		case 5
			if �����R���x�AG�r�o�v��=OFF and �����R���x�AH���쒆=OFF and ���t�gF1����step=0 and ���t�gF2����step=0 then
				inc(�����R���x�AGstep)
			else
				�����R���x�AGstep=1
			end if

		case 6
			if �����R���x�AGOrg then
				inc(�����R���x�AGstep)
			else
				�����R���x�AGstep=1
			end if
				
		case 7
		
			if �W��胆�j�b�g���� then
			
				if �t�^���t�^��蒆 then
					if PH51_�����m and PH52_�t�^���m then
					'�t�^��肳�ꂽ���݂̂̔r�o ���t�gF1�AF2���狟�������Ȃ��B
						'�t�^��肳�ꂽ���r�o
						�����R���x�AGstep=100
					else
						'�t�^�u����������
						�W��胆�j�b�g�r�o�v��=OFF
						�t�^��芮��=OFF
						�����R���x�AGstep=1
					end if

				else
					if ���t�gF1�r�o�H���� then
						�����R���x�AGstep=200
					
					else if ���t�gF2�r�o�H���� then
						�����R���x�AGstep=300

					else if PH50_�����m then
						'���t�gF2�r�o
						���t�gF1�r�o�H����=OFF
						���t�gF2�r�o�H����=ON
						�����R���x�AGstep=300

					else if PH49_�����m and not(PH50_�����m) then
							'���t�gF1�r�o
							���t�gF1�r�o�H����=ON
							���t�gF2�r�o�H����=OFF
							�����R���x�AGstep=200
					else
						�����R���x�AGstep=1
					end if

				end if '�t�^���t�^��蒆
		else
			if PH51_�����m and PH52_�t�^���m then
				'�t�^���ʒu�̊��r�o
				�����R���x�AGstep=100
			
			else if ���t�gF1�r�o�H���� then
				�����R���x�AGstep=200
			
			else if ���t�gF2�r�o�H���� then
				�����R���x�AGstep=300

			else if PH50_�����m then
				'���t�gF2�r�o
				���t�gF1�r�o�H����=OFF
				���t�gF2�r�o�H����=ON
				�����R���x�AGstep=300

			else if PH49_�����m and not(PH50_�����m) then
					'���t�gF1�r�o
					���t�gF1�r�o�H����=ON
					���t�gF2�r�o�H����=OFF
					�����R���x�AGstep=200
			else
				�����R���x�AGstep=1
			end if
			
		end if

		'--------------------------------------------
		'�y �t�^�킹���r�o �z
		'--------------------------------------------
		case 100
			if �����R���x�AH���쒆=OFF and not(PH53_�����m) and not(PH54_�t�^���m) then
				inc(�����R���x�AGstep)
			else
				�����R���x�AGstep=1
			end if

		case 101
			SV46_�X�g�b�pstep=1
			�t�^���r�ostep=1
			inc(�����R���x�AGstep)
			
		case 102
			if SV46_�X�g�b�pstep=0 and �t�^���r�ostep=0 then
				inc(�����R���x�AGstep)
			end if

		case 103
		    if PH53_�����m or PH54_�t�^���m then
				�����R���x�AG�r�o�v��=ON
			end if
			�W��胆�j�b�g�r�o�v��=OFF
			�t�^��芮��=OFF
			�����R���x�AH��������=OFF '�����R���x�AH��������: ���]�@�I���̔r�o����H�R���x�A��̃��t�g�𒴂��Đ��b�������ʒu
			�����R���x�AG���쒆=OFF
			�����R���x�AGstep=1

		'--------------------------------------------
		'�y F1���t�g���r�o �� �t�^���ʒu�܂Ŕ��� -> F2���t�g�������z
		'--------------------------------------------
		case 200
			if �����R���x�AH���쒆=OFF then
				inc(�����R���x�AGstep)
			else
				�����R���x�AGstep=1
			end if

		case 201
			�����R���x�AG���쒆=ON
			'�t�^���V�����_�[�㏸�m�F
			if (errpassXSW55_���t�g�㏸�[ or ((XSW55_�V�����_�㏸�[A and not(pnlPBXSW55_�V�����_�㏸�[A)) or passXSW55_�V�����_�㏸�[A)) and (errpassXSW57_���t�g�㏸�[ or ((XSW57_�V�����_�㏸�[B and not(pnlPBXSW57_�V�����_�㏸�[B)) or passXSW57_�V�����_�㏸�[B)) then
				inc(�����R���x�AGstep)
			end if

		
		case 202
			SV46_�X�g�b�pstep=1
			�t�^���r�ostep=1
			inc(�����R���x�AGstep)

		case 203
			if SV46_�X�g�b�pstep=0 and �t�^���r�ostep=0 then
				inc(�����R���x�AGstep)
			end if

		case 204
			 'F1���t�g�X�g�b�p
			mSV47_���t�g=OFF
			errpassXSW56_���t�g���~�[=OFF
			mSV44_�X�g�b�p=OFF
			errpassXSW60_�X�g�b�p���~�[=OFF
			
			mSV48_���t�g=OFF	'F2���t�g
			errpassXSW58_���t�g���~�[=OFF
			mSV45_�X�g�b�p=OFF	'F2���t�g�X�g�b�p
			errpassXSW62_�X�g�b�p���~�[=OFF
			
			inc(�����R���x�AGstep)

		case 205
			'F1���t�g�X�g�b�p
			if (errpassXSW60_�X�g�b�p���~�[ or ((XSW60_�X�g�b�p���~�[ and not(pnlPBXSW60_�X�g�b�p���~�[)) or passXSW60_�X�g�b�p���~�[)) and (errpassXSW56_���t�g���~�[ or ((XSW56_���t�g���~�[ and not(pnlPBXSW56_���t�g���~�[)) or passXSW56_���t�g���~�[)) then
				inc(�����R���x�AGstep)
			end if
		
		case 206
			'F2���t�g,���t�g�X�g�b�p
			if (errpassXSW58_���t�g���~�[ or ((XSW58_���t�g���~�[ and not(pnlPBXSW58_���t�g���~�[)) or passXSW58_���t�g���~�[)) and (errpassXSW62_�X�g�b�p���~�[ or ((XSW62_�X�g�b�p���~�[ and not(pnlPBXSW62_�X�g�b�p���~�[)) or passXSW62_�X�g�b�p���~�[)) then
				inc(�����R���x�AGstep)
			end if

		case 207
			���t�gF1�r�ostep=1
			inc(�����R���x�AGstep)
			
		case 208
			if ���t�gF1�r�ostep=0 then
				inc(�����R���x�AGstep)
			end if
			
		case 209
		    if PH53_�����m or PH54_�t�^���m then
				�����R���x�AG�r�o�v��=ON
			end if

			���t�gF1�r�o�H����=OFF
			���t�gF2�r�o�H����=OFF
			�W��胆�j�b�g�r�o�v��=OFF
			�t�^��芮��=OFF
			�����R���x�AG���쒆=OFF '�r�o���쎞�̓��쒆�M��OFF
			�����R���x�AGstep=1

		'--------------------------------------------
		'�y F2���t�g���r�o �� �t�^���ʒu�܂Ŕ���  -> F1���t�g�������z
		'--------------------------------------------
		case 300
			if �����R���x�AH���쒆=OFF then
				inc(�����R���x�AGstep)
			else
				�����R���x�AGstep=1
			end if
		
		case 301
			�����R���x�AG���쒆=ON		
			if (errpassXSW55_���t�g�㏸�[ or (XSW55_�V�����_�㏸�[A and not(pnlPBXSW55_�V�����_�㏸�[A)) or passXSW55_���t�g�㏸�[) and (errpassXSW57_���t�g�㏸�[ or (XSW57_�V�����_�㏸�[B and not(pnlPBXSW57_���t�g�㏸�[)) or passXSW57_���t�g�㏸�[) then
				inc(�����R���x�AGstep)
			end if

		case 302
			SV46_�X�g�b�pstep=1
			�t�^���r�ostep=1
			inc(�����R���x�AGstep)

		case 303
			if SV46_�X�g�b�pstep=0 and �t�^���r�ostep=0 then
				inc(�����R���x�AGstep)
			end if

		case 304
			mSV48_���t�g=OFF
			errpassXSW58_���t�g���~�[=OFF
			mSV45_�X�g�b�p=OFF
			errpassXSW62_�X�g�b�p���~�[=OFF
			inc(�����R���x�AGstep)

		case 305
			if (errpassXSW58_���t�g���~�[ or (XSW58_���t�g���~�[ and not(pnlPBXSW58_���t�g���~�[)) or XSW58_���t�g���~�[) and (errpassXSW62_�X�g�b�p���~�[ or (XSW62_�X�g�b�p���~�[ and not(pnlPBXSW62_�X�g�b�p���~�[)) or passXSW62_�X�g�b�p���~�[) then
				inc(�����R���x�AGstep)
			end if
		
		case 306
			���t�gF2�r�ostep=1
			inc(�����R���x�AGstep)
		
		case 307
			if ���t�gF2�r�ostep=0 then
				inc(�����R���x�AGstep)
			end if
		
		case 308
		    if PH53_�����m or PH54_�t�^���m then
				�����R���x�AG�r�o�v��=ON
			end if
			���t�gF1�r�o�H����=OFF
			���t�gF2�r�o�H����=OFF
			�W��胆�j�b�g�r�o�v��=OFF
			�t�^��芮��=OFF
			�����R���x�AG���쒆=OFF '�r�o���쎞�̓��쒆�M��OFF
			�����R���x�AGstep=1
			
	end select
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else
	
		if ManualInite=1 then
			mSV44_�X�g�b�p=OFF
			mSV45_�X�g�b�p=OFF
			mSV46_�X�g�b�p=OFF
			mSV49_�X�g�b�p=OFF

			ManualInite=0
		end if

		�����R���x�AGAutoRun=OFF
		
		�����R���x�AGstep=0 '�I��

		res(timerr_MC54_���[�^���[��)'tmr(MC54_���[�^���[��,timerr_MC54_���[�^���[��,#65)
		
		'------------------------------------------------
		' [37]
		if ldp(pnlPBSV47_���t�g) then
			if mSV47_���t�g then
				mSV47_���t�g=OFF
			else
				mSV47_���t�g=ON
			end if
		end if
		
		
		if ldp(pnlPBSV44_�X�g�b�p) then
			if mSV44_�X�g�b�p then
				mSV44_�X�g�b�p=OFF
			else
				mSV44_�X�g�b�p=ON
			end if
		end if

		if ldp(pnlPBMC41_���[�^���[��) then
			if mMC41_���[�^���[�� then
				mMC41_���[�^���[��=OFF
			else
				mMC41_���[�^���[��=ON
			end if
		end if

		'------------------------------------------------
		' [38]
		if ldp(pnlPBSV48_���t�g) then
			if mSV48_���t�g then
				mSV48_���t�g=OFF
			else
				mSV48_���t�g=ON
			end if
		end if
		
		
		if ldp(pnlPBSV45_�X�g�b�p) then
			if mSV45_�X�g�b�p then
				mSV45_�X�g�b�p=OFF
			else
				mSV45_�X�g�b�p=ON
			end if
		end if

		if ldp(pnlPBMC42_���[�^���[��) then
			if mMC42_���[�^���[�� then
				mMC42_���[�^���[��=OFF
			else
				mMC42_���[�^���[��=ON
			end if
		end if

		'------------------------------------------------
		' [39]
		if ldp(pnlPBSV46_�X�g�b�p) then
			if mSV46_�X�g�b�p then
				mSV46_�X�g�b�p=OFF
			else
				mSV46_�X�g�b�p=ON
			end if
		end if
		'------------------------------------------------
		' [40]
		if ldp(pnlPBSV50_���t�g) then
			if mSV50_���t�g then
				mSV50_���t�g=OFF
			else
				mSV50_���t�g=ON
			end if
		end if
		
		
		if ldp(pnlPBSV49_�X�g�b�p) then
			if mSV49_�X�g�b�p then
				mSV49_�X�g�b�p=OFF
			else
				mSV49_�X�g�b�p=ON
			end if
		end if

		if ldp(pnlPBMC54_���[�^���[��) then
			if mMC54_���[�^���[�� then
				mMC54_���[�^���[��=OFF
			else
				mMC54_���[�^���[��=ON
			end if
		end if

		'------------------------------------------------
		if ldp(pnlPBMC43_�������[�^) then
			if mMC43_�������[�^ then
				mMC43_�������[�^=OFF
			else if ((XSW55_�V�����_�㏸�[A and not(pnlPBXSW55_�V�����_�㏸�[A)) or passXSW55_�V�����_�㏸�[A) and ((XSW57_�V�����_�㏸�[B and not(pnlPBXSW57_�V�����_�㏸�[B)) or passXSW57_�V�����_�㏸�[B) then
				mMC43_�������[�^=ON
			end if
		end if
			
	end if '�����R���x�AGEmgStep and not(�����R���x�AGOrgErrStep)

	'===================================================================================================================
	'�y �����R���x�AGOrgErr���� �z
	else

		res(tim_XSW55_���t�g�㏸�[)
		res(tim_XSW56_���t�g���~�[)
		res(tim_XSW59_�X�g�b�p�㏸�[)
		res(tim_XSW60_�X�g�b�p���~�[)
		res(tim_XSW57_���t�g�㏸�[)
		res(tim_XSW58_���t�g���~�[)
		res(tim_XSW61_�X�g�b�p�㏸�[)
		res(tim_XSW62_�X�g�b�p���~�[)
		res(tim_XSW63_�X�g�b�p�㏸�[)
		res(tim_XSW64_�X�g�b�p���~�[)
		res(tim_XSW67_���t�g�㏸�[)
		res(tim_XSW68_���t�g���~�[)
		res(tim_XSW65_�X�g�b�p�㏸�[)
		res(tim_XSW66_�X�g�b�p���~�[)

		res(tim_notXSW55_���t�g�㏸�[)
		res(tim_notXSW56_���t�g���~�[)
		res(tim_notXSW59_�X�g�b�p�㏸�[)
		res(tim_notXSW60_�X�g�b�p���~�[)
		res(tim_notXSW57_���t�g�㏸�[)
		res(tim_notXSW58_���t�g���~�[)
		res(tim_notXSW61_�X�g�b�p�㏸�[)
		res(tim_notXSW62_�X�g�b�p���~�[)
		res(tim_notXSW63_�X�g�b�p�㏸�[)
		res(tim_notXSW64_�X�g�b�p���~�[)
		res(tim_notXSW67_���t�g�㏸�[)
		res(tim_notXSW68_���t�g���~�[)
		res(tim_notXSW65_�X�g�b�p�㏸�[)
		res(tim_notXSW66_�X�g�b�p���~�[)

		if ResetFlg then
			�����R���x�AGOrgErr=OFF
		end if


	end if

	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else

		�����R���x�AGErr=ON

		pauseMC41_���[�^���[��=ON
		pauseMC42_���[�^���[��=ON
		pauseMC43_�������[�^=ON
		pauseMC54_���[�^���[��=ON
		
		pauseMC28_���[�^���[��=ON
		pauseMC53_���[�^���[��=ON

		res(timerr_MC54_���[�^���[��)


		select case �����R���x�AGErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW55_���t�g�㏸�[=OFF
				almXSW56_���t�g���~�[=OFF
				almXSW59_�X�g�b�p�㏸�[=OFF
				almXSW60_�X�g�b�p���~�[=OFF
				almXSW57_���t�g�㏸�[=OFF
				almXSW58_���t�g���~�[=OFF
				almXSW61_�X�g�b�p�㏸�[=OFF
				almXSW62_�X�g�b�p���~�[=OFF
				almXSW63_�X�g�b�p�㏸�[=OFF
				almXSW64_�X�g�b�p���~�[=OFF
				almXSW67_���t�g�㏸�[=OFF
				almXSW68_���t�g���~�[=OFF
				almXSW65_�X�g�b�p�㏸�[=OFF
				almXSW66_�X�g�b�p���~�[=OFF
				almMC54_���[�^���[��=OFF

				inc(�����R���x�AGErrStep)
			end if
		case 2


			res(tim_XSW55_���t�g�㏸�[)
			res(tim_XSW56_���t�g���~�[)
			res(tim_XSW59_�X�g�b�p�㏸�[)
			res(tim_XSW60_�X�g�b�p���~�[)
			res(tim_XSW57_���t�g�㏸�[)
			res(tim_XSW58_���t�g���~�[)
			res(tim_XSW61_�X�g�b�p�㏸�[)
			res(tim_XSW62_�X�g�b�p���~�[)
			res(tim_XSW63_�X�g�b�p�㏸�[)
			res(tim_XSW64_�X�g�b�p���~�[)
			res(tim_XSW67_���t�g�㏸�[)
			res(tim_XSW68_���t�g���~�[)
			res(tim_XSW65_�X�g�b�p�㏸�[)
			res(tim_XSW66_�X�g�b�p���~�[)

			res(tim_notXSW55_���t�g�㏸�[)
			res(tim_notXSW56_���t�g���~�[)
			res(tim_notXSW59_�X�g�b�p�㏸�[)
			res(tim_notXSW60_�X�g�b�p���~�[)
			res(tim_notXSW57_���t�g�㏸�[)
			res(tim_notXSW58_���t�g���~�[)
			res(tim_notXSW61_�X�g�b�p�㏸�[)
			res(tim_notXSW62_�X�g�b�p���~�[)
			res(tim_notXSW63_�X�g�b�p�㏸�[)
			res(tim_notXSW64_�X�g�b�p���~�[)
			res(tim_notXSW67_���t�g�㏸�[)
			res(tim_notXSW68_���t�g���~�[)
			res(tim_notXSW65_�X�g�b�p�㏸�[)
			res(tim_notXSW66_�X�g�b�p���~�[)

			pauseMC41_���[�^���[��=OFF
			pauseMC42_���[�^���[��=OFF
			pauseMC43_�������[�^=OFF
			pauseMC54_���[�^���[��=OFF
			
			pauseMC28_���[�^���[��=OFF
			pauseMC53_���[�^���[��=OFF

			pauseSV47_���t�g=OFF
			'pauseSV44_�X�g�b�p=OFF
			pauseSV48_���t�g=OFF
			'pauseSV45_�X�g�b�p=OFF
			pauseSV46_�X�g�b�p=OFF
			pauseSV50_���t�g=OFF
			'pauseSV49_�X�g�b�p=OFF


			�����R���x�AGErr=OFF
			�����R���x�AGErrStep=0
		end select

	end if 'if �����R���x�AGErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	select case �����R���x�AGEmgStep
	case 0
		
	case 1
		�����R���x�AGAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�����R���x�AGAutoMode and ��������AutoMode ) or �����R���x�AGstep<>0 or ���t�gF1����step<>0 or ���t�gF2����step<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseMC41_���[�^���[��=ON
			pauseMC42_���[�^���[��=ON
			pauseMC54_���[�^���[��=ON
			pauseMC43_�������[�^=ON

			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				tim_SV46_�X�g�b�p_stack=tim_SV46_�X�g�b�p.U
				tim_SV47_���t�g_stack=tim_SV47_���t�g.U
				tim_SV48_���t�g_stack=tim_SV48_���t�g.U
				tim_SV50_���t�g_stack=tim_SV50_���t�g.U
				tim_MC41_���[�^���[��_stack=tim_MC41_���[�^���[��.U
				tim_MC42_���[�^���[��_stack=tim_MC42_���[�^���[��.U
				tim_�t�^���r�o_stack=tim_�t�^���r�o.U
				tim_���t�gF1����_stack=tim_���t�gF1����.U
				tim_���t�gF1�r�o_stack=tim_���t�gF1�r�o.U
				tim_���t�gF2����_stack=tim_���t�gF2����.U
				tim_���t�gF2�r�o_stack=tim_���t�gF2�r�o.U

				timstack=ON
			end if

			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC41_���[�^���[��=OFF
			mMC42_���[�^���[��=OFF
			mMC54_���[�^���[��=OFF
			mMC43_�������[�^=OFF

			mSV47_���t�g=OFF
			mSV44_�X�g�b�p=OFF
			mSV48_���t�g=OFF
			mSV45_�X�g�b�p=OFF
			mSV46_�X�g�b�p=OFF
			mSV49_�X�g�b�p=OFF
			mSV50_���t�g=OFF

			'---------------------------------
		end if
		
		'---------------------------------
		inc(�����R���x�AGEmgStep)
	case 2
		if ResetFlg then
			inc(�����R���x�AGEmgStep)
		end if
	case 3
		if (�����R���x�AGAutoMode and ��������AutoMode ) or �����R���x�AGstep<>0 or ���t�gF1����step<>0 or ���t�gF2����step<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseMC41_���[�^���[��=OFF
				pauseMC42_���[�^���[��=OFF
				pauseMC54_���[�^���[��=OFF
				pauseMC43_�������[�^=OFF

				tim_procstep.U=tim_procstep_stack
				tim_SV46_�X�g�b�p.U=tim_SV46_�X�g�b�p_stack
				tim_SV47_���t�g.U=tim_SV47_���t�g_stack
				tim_SV48_���t�g.U=tim_SV48_���t�g_stack
				tim_SV50_���t�g.U=tim_SV50_���t�g_stack
				tim_MC41_���[�^���[��.U=tim_MC41_���[�^���[��_stack
				tim_MC42_���[�^���[��.U=tim_MC42_���[�^���[��_stack
				tim_�t�^���r�o.U=tim_�t�^���r�o_stack
				tim_���t�gF1����.U=tim_���t�gF1����_stack
				tim_���t�gF1�r�o.U=tim_���t�gF1�r�o_stack
				tim_���t�gF2����.U=tim_���t�gF2����_stack
				tim_���t�gF2�r�o.U=tim_���t�gF2�r�o_stack
				timerr_MC54_���[�^���[��.U=timerr_MC54_���[�^���[��_stack
				
				'---------------------------------
				inc(�����R���x�AGEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�����R���x�AGEmgStep)		
		end if				
	case 4
		timstack=OFF
		�����R���x�AGEmgStep=0
		�����R���x�AGEmg=OFF
	end select
		
end if 'if �����R���x�AGEmgStep=0 then
