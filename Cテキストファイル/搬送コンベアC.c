'�����R���x�AC
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	�����R���x�AC
'
'-------------------------------------------------------
' [ 7 ]
' (PH15_�����m)			-> (PH15_�����m)
' (PH16_�t�^���m)		-> (PH16_�t�^���m)
'-------- 
' SV33_���t�g			-> SV23_���t�g
' XSW38_���t�g�㏸�[	-> XSW25_���t�g�㏸�[
' XSW37_���t�g���~�[	-> XSW24_���t�g���~�[
'--------
' SV65_�X�g�b�p			->  ( �폜 )
' XSW75_�X�g�b�p�㏸�[	->  ( �폜 )
' XSW74_�X�g�b�p���~�[	->  ( �폜 )
'-------------------------------------------------------
' [ 8 ]
' PH17_�����m	-> (PH17_�����m)
' PH18_�t�^���m	-> (PH18_�t�^���m)
'--------
' SV29_�X�g�b�p			->  SV25_�X�g�b�p		
' XSW30_�X�g�b�p�㏸�[	->  XSW29_�X�g�b�p�㏸�[
' XSW29_�X�g�b�p���~�[	->  XSW28_�X�g�b�p���~�[
'--------
' SV31_�N�����v			->  SV24_�N�����v		
' XSW34_�N�����v�㏸�[	->  XSW27_�N�����v�㏸�[
' XSW33_�N�����v���~�[	->  XSW26_�N�����v���~�[
'-------------------------------------------------------
' [ 9 ]
' PH19_�����m	-> (PH19_�����m)
' PH20_�t�^���m	-> (PH20_�t�^���m)
'--------
' SV30_�X�g�b�p			->  SV27_�X�g�b�p		
' XSW32_�X�g�b�p�㏸�[	->  XSW33_�X�g�b�p�㏸�[
' XSW31_�X�g�b�p���~�[	->  XSW32_�X�g�b�p���~�[
'--------
' SV32_�N�����v			->  SV26_�N�����v		
' XSW36_�N�����v�㏸�[	->  XSW31_�N�����v�㏸�[
' XSW35_�N�����v���~�[	->  XSW30_�N�����v���~�[
'-------------------------------------------------------
' [ 10 ]
' 	( �V�K )	-> PH21_�����m
'
'-------------------------------------------------------
' [ 11 ]
' PH54_������g���K	-> PH22_�����m
'--------
' 	( �V�K )		-> SV29_�X�g�b�p
' 	( �V�K )		-> XSW37_�X�g�b�p�㏸�[
' 	( �V�K )		-> XSW36_�X�g�b�p���~�[
'--------
' 	( �V�K )		-> SV28_���t�g
' 	( �V�K )		-> XSW34_���t�g�㏸�[
' 	( �V�K )		-> XSW35_���t�g���~�[
'-------------------------------------------------------
'
'===================================================================================================================
'�y ���������� �z
if CR2008 then '�d��ON������������

    �����R���x�ACAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �����R���x�ACAutoRun=OFF
    �����R���x�AC����=ON
    �����R���x�ACOrgErr=OFF
    �����R���x�ACErr=OFF
    �����R���x�ACEmg=OFF
    �����R���x�ACstep=0
    �����R���x�ACErrStep=0
    �����R���x�ACOrgErrStep=0
    �����R���x�ACEmgStep=0

	SV25_�X�g�b�pstep=0
	SV27_�X�g�b�pstep=0
	MC16_���[�^���[��step=0
	MC14_�������[�^step=0
	MC15_�������[�^step=0

	if SSW3_�������[�h then	
		ManualInite=1
	else
		ManualInite=0	
	end if
	
end if
'===================================================================================================================
'�y ���_ �z
�����R���x�ACOrg= ((XSW28_�X�g�b�p���~�[ and not(pnlPBXSW28_�X�g�b�p���~�[)) or passXSW28_�X�g�b�p���~�[) or ((XSW29_�X�g�b�p�㏸�[ and not(pnlPBXSW29_�X�g�b�p�㏸�[)) or passXSW29_�X�g�b�p�㏸�[) 
�����R���x�ACOrg= �����R���x�ACOrg and (((XSW32_�X�g�b�p���~�[ and not(pnlPBXSW32_�X�g�b�p���~�[)) or passXSW32_�X�g�b�p���~�[) or ((XSW33_�X�g�b�p�㏸�[ and not(pnlPBXSW33_�X�g�b�p�㏸�[)) or passXSW33_�X�g�b�p�㏸�[))
�����R���x�ACOrg= �����R���x�ACOrg and (((XSW26_�N�����v���~�[ and not(pnlPBXSW26_�N�����v���~�[)) or passXSW26_�N�����v���~�[) or ((XSW27_�N�����v�㏸�[ and not(pnlPBXSW27_�N�����v�㏸�[)) or passXSW27_�N�����v�㏸�[))
�����R���x�ACOrg= �����R���x�ACOrg and (((XSW30_�N�����v���~�[ and not(pnlPBXSW30_�N�����v���~�[)) or passXSW30_�N�����v���~�[) or ((XSW31_�N�����v�㏸�[ and not(pnlPBXSW31_�N�����v�㏸�[)) or passXSW31_�N�����v�㏸�[))


'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�����R���x�ACEmg=ON
	�����R���x�ACEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

tmr(not(SV24_�N�����v) and not(XSW26_�N�����v���~�[) and not(pnlPBXSW26_�N�����v���~�[),tim_notXSW26_�N�����v���~�[,#30)
tmr(SV24_�N�����v and not(XSW27_�N�����v�㏸�[) and not(pnlPBXSW27_�N�����v�㏸�[),tim_notXSW27_�N�����v�㏸�[,#30)
tmr(not(SV25_�X�g�b�p) and not(XSW28_�X�g�b�p���~�[) and not(pnlPBXSW28_�X�g�b�p���~�[), tim_notXSW28_�X�g�b�p���~�[,#30)
tmr(SV25_�X�g�b�p and not(XSW29_�X�g�b�p�㏸�[) and not(pnlPBXSW29_�X�g�b�p�㏸�[), tim_notXSW29_�X�g�b�p�㏸�[,#30)
tmr(not(SV26_�N�����v) and not(XSW30_�N�����v���~�[) and not(pnlPBXSW30_�N�����v���~�[), tim_notXSW30_�N�����v���~�[, #30)
tmr(SV26_�N�����v and not(XSW31_�N�����v�㏸�[) and not(pnlPBXSW31_�N�����v�㏸�[), tim_notXSW31_�N�����v�㏸�[,#30)
tmr(not(SV27_�X�g�b�p) and not(XSW32_�X�g�b�p���~�[) and not(pnlPBXSW32_�X�g�b�p���~�[),tim_notXSW32_�X�g�b�p���~�[,#30)
tmr(SV27_�X�g�b�p and not(XSW33_�X�g�b�p�㏸�[) and not(pnlPBXSW33_�X�g�b�p�㏸�[),tim_notXSW33_�X�g�b�p�㏸�[,#30)
tmr(not(SV23_���t�g) and not(XSW24_���t�g���~�[) and not(pnlPBXSW24_���t�g���~�[),tim_notXSW24_���t�g���~�[,#50)
tmr(SV23_���t�g and not(XSW25_���t�g�㏸�[) and not(pnlPBXSW25_���t�g�㏸�[),tim_notXSW25_���t�g�㏸�[,#50)
' stage [11]
tmr(not(SV29_�X�g�b�p) and not(XSW36_�X�g�b�p���~�[) and not(pnlPBXSW36_�X�g�b�p���~�[),tim_notXSW36_�X�g�b�p���~�[,#30)
tmr(SV29_�X�g�b�p and not(XSW37_�X�g�b�p�㏸�[) and not(pnlPBXSW37_�X�g�b�p�㏸�[),tim_notXSW37_�X�g�b�p�㏸�[,#30)

'---------------------------------------------------------------------------------------------------------------------
'tmr(SV24_�N�����v and XSW26_�N�����v���~�[ and not(pnlPBXSW26_�N�����v���~�[),tim_XSW26_�N�����v���~�[,#20)
if LDF(SV24_�N�����v) and XSW26_�N�����v���~�[ and not(pnlPBXSW26_�N�����v���~�[) and not(pauseSV24_�N�����v) then
	SET(tim_XSW26_�N�����v���~�[)
end if
'tmr(not(SV24_�N�����v) and XSW27_�N�����v�㏸�[ and not(pnlPBXSW27_�N�����v�㏸�[),tim_XSW27_�N�����v�㏸�[,#20)
if LDP(SV24_�N�����v) and XSW27_�N�����v�㏸�[ and not(pnlPBXSW27_�N�����v�㏸�[) then 
	SET(tim_XSW27_�N�����v�㏸�[) 
end if
'tmr(SV25_�X�g�b�p and XSW28_�X�g�b�p���~�[ and not(pnlPBXSW28_�X�g�b�p���~�[), tim_XSW28_�X�g�b�p���~�[,#20)
if LDF(SV25_�X�g�b�p) and XSW28_�X�g�b�p���~�[ and not(pnlPBXSW28_�X�g�b�p���~�[) and not(pauseSV25_�X�g�b�p) then
	SET(tim_XSW28_�X�g�b�p���~�[)
end if
'tmr(not(SV25_�X�g�b�p) and XSW29_�X�g�b�p�㏸�[ and not(pnlPBXSW29_�X�g�b�p�㏸�[), tim_XSW29_�X�g�b�p�㏸�[,#20)
if LDP(SV25_�X�g�b�p) and XSW29_�X�g�b�p�㏸�[ and not(pnlPBXSW29_�X�g�b�p�㏸�[) then
	SET(tim_XSW29_�X�g�b�p�㏸�[)
end if
'tmr(SV26_�N�����v and XSW30_�N�����v���~�[ and not(pnlPBXSW30_�N�����v���~�[), tim_XSW30_�N�����v���~�[, #20)
if LDF(SV26_�N�����v) and XSW30_�N�����v���~�[ and not(pnlPBXSW30_�N�����v���~�[) and not(pauseSV26_�N�����v) then
	SET(tim_XSW30_�N�����v���~�[)
end if
'tmr(not(SV26_�N�����v) and XSW31_�N�����v�㏸�[ and not(pnlPBXSW31_�N�����v�㏸�[), tim_XSW31_�N�����v�㏸�[,#20)
if LDP(SV26_�N�����v) and XSW31_�N�����v�㏸�[ and not(pnlPBXSW31_�N�����v�㏸�[) then
	SET(tim_XSW31_�N�����v�㏸�[)
end if
'tmr(SV27_�X�g�b�p and XSW32_�X�g�b�p���~�[ and not(pnlPBXSW32_�X�g�b�p���~�[),tim_XSW32_�X�g�b�p���~�[,#20)
if LDF(SV27_�X�g�b�p) and XSW32_�X�g�b�p���~�[ and not(pnlPBXSW32_�X�g�b�p���~�[) and not(pauseSV27_�X�g�b�p) then
	SET(tim_XSW32_�X�g�b�p���~�[)
end if
'tmr(not(SV27_�X�g�b�p) and XSW33_�X�g�b�p�㏸�[ and not(pnlPBXSW33_�X�g�b�p�㏸�[),tim_XSW33_�X�g�b�p�㏸�[,#20)
if LDP(SV27_�X�g�b�p) and XSW33_�X�g�b�p�㏸�[ and not(pnlPBXSW33_�X�g�b�p�㏸�[) then
	SET(tim_XSW33_�X�g�b�p�㏸�[)
end if
'tmr(SV23_���t�g and XSW24_���t�g���~�[ and not(pnlPBXSW24_���t�g���~�[),tim_XSW24_���t�g���~�[,#20)
if LDF(SV23_���t�g) and XSW24_���t�g���~�[ and not(pnlPBXSW24_���t�g���~�[) and not(pauseSV28_���t�g) then
	SET(tim_XSW24_���t�g���~�[)
end if
'tmr(not(SV23_���t�g) and XSW25_���t�g�㏸�[ and not(pnlPBXSW25_���t�g�㏸�[),tim_XSW25_���t�g�㏸�[,#20)
if LDP(SV23_���t�g) and XSW25_���t�g�㏸�[ and not(pnlPBXSW25_���t�g�㏸�[) then
	SET(tim_XSW25_���t�g�㏸�[)
end if
'tmr(SV29_�X�g�b�p and XSW36_�X�g�b�p���~�[ and not(pnlPBXSW36_�X�g�b�p���~�[),tim_XSW36_�X�g�b�p���~�[,#10)
if LDF(SV29_�X�g�b�p) and XSW36_�X�g�b�p���~�[ and not(pnlPBXSW36_�X�g�b�p���~�[) and not(pauseSV29_�X�g�b�p) then
	SET(tim_XSW36_�X�g�b�p���~�[)
end if
'tmr(not(SV29_�X�g�b�p) and XSW37_�X�g�b�p�㏸�[ and not(pnlPBXSW37_�X�g�b�p�㏸�[),tim_XSW37_�X�g�b�p�㏸�[,#10)
if LDP(SV29_�X�g�b�p) and XSW37_�X�g�b�p�㏸�[ and not(pnlPBXSW37_�X�g�b�p�㏸�[) then
	SET(tim_XSW37_�X�g�b�p�㏸�[)
end if
'---------------------------------------------------------------------------------------------------------------------



tms(not(SV24_�N�����v),passtimXSW26_�N�����v���~�[,passtimXSW26_�N�����v���~�[_val)
tms(SV24_�N�����v,passtimXSW27_�N�����v�㏸�[,passtimXSW27_�N�����v�㏸�[_val)
tms(not(SV25_�X�g�b�p),passtimXSW28_�X�g�b�p���~�[,passtimXSW28_�X�g�b�p���~�[_val)
tms(SV25_�X�g�b�p,passtimXSW29_�X�g�b�p�㏸�[,passtimXSW29_�X�g�b�p�㏸�[_val)
tms(not(SV26_�N�����v),passtimXSW30_�N�����v���~�[,passtimXSW30_�N�����v���~�[_val)
tms(SV26_�N�����v,passtimXSW31_�N�����v�㏸�[,passtimXSW31_�N�����v�㏸�[_val)
tms(not(SV27_�X�g�b�p),passtimXSW32_�X�g�b�p���~�[,passtimXSW32_�X�g�b�p���~�[_val)
tms(SV27_�X�g�b�p,passtimXSW33_�X�g�b�p�㏸�[,passtimXSW33_�X�g�b�p�㏸�[_val)
'tms(not(SV23_���t�g),passtimXSW24_���t�g���~�[,passtimXSW24_���t�g���~�[_val)
'tms(SV23_���t�g,passtimXSW25_���t�g�㏸�[,passtimXSW25_���t�g�㏸�[_val)
' stage [11]
tms(not(SV29_�X�g�b�p),passtimXSW36_�X�g�b�p���~�[,passtimXSW36_�X�g�b�p���~�[_val)
tms(SV29_�X�g�b�p,passtimXSW37_�X�g�b�p�㏸�[,passtimXSW37_�X�g�b�p�㏸�[_val)


tmr(MC16_���[�^���[��,timerr_MC16_���[�^���[��,#120)
tmr(MC14_�������[�^,timerr_MC14_�������[�^,#120)
'--------- �t�^�킹���j�b�g����������ꂽPH21_�����m�ʒu�̃t�^���r������Ȃ��Ŏc���Ă���  -----
tmr(�t�^������ and PH21_�����m,timerr_PH21�t�^�L,30)
�R���x�AC2�t�^�L=timerr_PH21�t�^�L.B


if ldp(timerr_MC16_���[�^���[��.B) then
	errpassMC16_���[�^���[��=ON
	errpassMC14_�������[�^=ON
	mMC14_�������[�^=OFF
	mMC16_���[�^���[��=OFF
	almMC16_���[�^���[��=ON
	�����R���x�ACErrStep=1

else if ldp(timerr_MC14_�������[�^.B) then
	errpassMC16_���[�^���[��=ON
	errpassMC14_�������[�^=ON
	mMC14_�������[�^=OFF
	mMC16_���[�^���[��=OFF
	almMC14_�������[�^=ON
	�����R���x�ACErrStep=1

else if ldp(tim_XSW26_�N�����v���~�[.B) or ldp(tim_notXSW26_�N�����v���~�[.B) then
	errpassXSW26_�N�����v���~�[=ON
	almXSW26_�N�����v���~�[=ON
	pnlPBXSW26_�N�����v���~�[=ON
	�����R���x�ACErrStep=1

else if ldp(tim_XSW27_�N�����v�㏸�[.B) or ldp(tim_notXSW27_�N�����v�㏸�[.B) then
	errpassXSW27_�N�����v�㏸�[=ON
	pauseSV24_�N�����v=ON
	almXSW27_�N�����v�㏸�[=ON
	pnlPBXSW27_�N�����v�㏸�[=ON
	�����R���x�ACErrStep=1

else if ldp(tim_XSW28_�X�g�b�p���~�[.B) or ldp(tim_notXSW28_�X�g�b�p���~�[.B) then
	errpassXSW28_�X�g�b�p���~�[=ON
	almXSW28_�X�g�b�p���~�[=ON
	pnlPBXSW28_�X�g�b�p���~�[=ON
	�����R���x�ACErrStep=1

else if ldp(tim_XSW29_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW29_�X�g�b�p�㏸�[.B) then
	errpassXSW29_�X�g�b�p�㏸�[=ON
	pauseSV25_�X�g�b�p=ON
	almXSW29_�X�g�b�p�㏸�[=ON
	pnlPBXSW29_�X�g�b�p�㏸�[=ON
	�����R���x�ACErrStep=1
	
else if ldp(tim_XSW30_�N�����v���~�[.B) or ldp(tim_notXSW30_�N�����v���~�[.B) then
	errpassXSW30_�N�����v���~�[=ON
	almXSW30_�N�����v���~�[=ON
	pnlPBXSW30_�N�����v���~�[=ON
	�����R���x�ACErrStep=1

else if ldp(tim_XSW31_�N�����v�㏸�[.B) or ldp(tim_notXSW31_�N�����v�㏸�[.B) then
	errpassXSW31_�N�����v�㏸�[=ON
	pauseSV26_�N�����v=ON
	almXSW31_�N�����v�㏸�[=ON
	pnlPBXSW31_�N�����v�㏸�[=ON
	�����R���x�ACErrStep=1	

else if ldp(tim_XSW32_�X�g�b�p���~�[.B) or ldp(tim_notXSW32_�X�g�b�p���~�[.B) then
	errpassXSW32_�X�g�b�p���~�[=ON
	almXSW32_�X�g�b�p���~�[=ON
	pnlPBXSW32_�X�g�b�p���~�[=ON
	�����R���x�ACErrStep=1

else if ldp(tim_XSW33_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW33_�X�g�b�p�㏸�[.B) then
	errpassXSW33_�X�g�b�p�㏸�[=ON
	pauseSV27_�X�g�b�p=ON
	almXSW33_�X�g�b�p�㏸�[=ON
	pnlPBXSW33_�X�g�b�p�㏸�[=ON
	�����R���x�ACErrStep=1

else if ldp(tim_XSW24_���t�g���~�[) or ldp(tim_notXSW24_���t�g���~�[) then
	errpassXSW24_���t�g���~�[=ON
	almXSW24_���t�g���~�[=ON
	pnlPBXSW24_���t�g���~�[=ON
	�����R���x�ACErrStep=1

else if ldp(tim_XSW25_���t�g�㏸�[) or ldp(tim_notXSW25_���t�g�㏸�[) then
	errpassXSW25_���t�g�㏸�[=ON
	almXSW25_���t�g�㏸�[=ON
	pnlPBXSW25_���t�g�㏸�[=ON
	�����R���x�ACErrStep=1

'-- stage [11]
else if ldp(tim_XSW36_�X�g�b�p���~�[.B) or ldp(tim_notXSW36_�X�g�b�p���~�[.B) then
	errpassXSW36_�X�g�b�p���~�[=ON
	almXSW36_�X�g�b�p���~�[=ON
	pnlPBXSW36_�X�g�b�p���~�[=ON
	�����R���x�ACErrStep=1

else if ldp(tim_XSW37_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW37_�X�g�b�p�㏸�[.B) then
	errpassXSW37_�X�g�b�p�㏸�[=ON
	pauseSV29_�X�g�b�p=ON
	almXSW37_�X�g�b�p�㏸�[=ON
	pnlPBXSW37_�X�g�b�p�㏸�[=ON
	�����R���x�ACErrStep=1

end if

	

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �����R���x�ACAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �����R���x�ACAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �����R���x�ACEmg	���̏��~


if �����R���x�ACEmgStep=0 then  
	
	if �����R���x�ACErrStep=0  then

	if not(�����R���x�ACOrgErr) then

	if (�����R���x�ACAutoMode and ��������AutoMode ) or �����R���x�ACstep<>0 then
	
		timstack=OFF
		
		if ManualInite=1 then		
			mSV25_�X�g�b�p=ON
			mSV27_�X�g�b�p=ON
			ManualInite=0
		end if
	
		if not(�����R���x�ACAutoMode and ��������AutoMode ) then
			�����R���x�ACAutoRun=OFF
		end if
	
	tmr(PH17_�����m,timdly_PH17_�����m,2)
	tmr(PH18_�t�^���m,timdly_PH18_�t�^���m,2)
	tmr(PH19_�����m,timdly_PH19_�����m,2)
	tmr(PH20_�t�^���m,timdly_PH20_�t�^���m,2)
	tmr(PH21_�����m,timdly_PH21_�����m,2)
	
	'-----------------------------------------------------------------
	' �X�g�b�pON/OFF�^�C�~���O�^�X�N
	'-----------------------------------------------------------------
	tmr(tim_SV25_�X�g�b�p,tim_SV25_�X�g�b�p_val) '�Ȃ炵�X�g�b�p�A�N�����v
	select case SV25_�X�g�b�pstep
	case 0
		
	case 1
		PH15_���N�����m=LatchPH15_�����m
		PH16_�t�^�N�����m=LatchPH16_�t�^���m
		PH17_���N�����m=PH17_�����m
		PH18_�t�^�N�����m=PH18_�t�^���m
		
		if LatchPH15_�����m or LatchPH16_�t�^���m or PH17_�����m or PH18_�t�^���m then '�O�̃X�e�[�W(�����R���x�AB���t�g�j
			
			mSV25_�X�g�b�p=OFF '�X�g�b�p���~
			mSV24_�N�����v=OFF '�N�����v���~
			errpassXSW28_�X�g�b�p���~�[=OFF
			errpassXSW26_�N�����v���~�[=OFF

			inc(SV25_�X�g�b�pstep)
		else
			SV25_�X�g�b�pstep=0
		end if
		
	case 2
		if  (errpassXSW28_�X�g�b�p���~�[ or ((XSW28_�X�g�b�p���~�[ and not(pnlPBXSW28_�X�g�b�p���~�[)) or passXSW28_�X�g�b�p���~�[)) and (errpassXSW26_�N�����v���~�[ or ((XSW26_�N�����v���~�[ and not(pnlPBXSW26_�N�����v���~�[)) or passXSW26_�N�����v���~�[)) then 			
			inc(SV25_�X�g�b�pstep)
		end if
	
	case 3
		if not(PH17_�����m) and not(PH18_�t�^���m) then
			inc(SV25_�X�g�b�pstep)
		end if
		
	case 4
		tim_SV25_�X�g�b�p_val=35
		res(tim_SV25_�X�g�b�p)
		inc(SV25_�X�g�b�pstep)

	case 5
		if tim_SV25_�X�g�b�p.B then
			inc(SV25_�X�g�b�pstep)
		end if
	
	case 6
		mSV25_�X�g�b�p=ON '�X�g�b�p�㏸
		errpassXSW29_�X�g�b�p�㏸�[=OFF
		inc(SV25_�X�g�b�pstep)

	case 7
		if errpassXSW29_�X�g�b�p�㏸�[ or ( (XSW29_�X�g�b�p�㏸�[ and not(pnlPBXSW29_�X�g�b�p�㏸�[)) or passXSW29_�X�g�b�p�㏸�[) then
			inc(SV25_�X�g�b�pstep)
		end if		
		

	case 8
		if errpassMC16_���[�^���[�� or errpassMC14_�������[�^ then
			inc(SV25_�X�g�b�pstep)
		else if PH15_���N�����m or PH16_�t�^�N�����m then
			if (PH17_�����m and timdly_PH17_�����m.B) or (PH18_�t�^���m and timdly_PH18_�t�^���m.B) then
				inc(SV25_�X�g�b�pstep)
			end if
		else if PH17_���N�����m or PH18_�t�^�N�����m then
			if (PH19_�����m and timdly_PH19_�����m.B) or (PH20_�t�^���m and timdly_PH20_�t�^���m.B) then
				inc(SV25_�X�g�b�pstep)
			end if
		else
			inc(SV25_�X�g�b�pstep)		
		end if
		
	case 9
		mSV25_�X�g�b�p=ON '�X�g�b�p�㏸
		errpassXSW29_�X�g�b�p�㏸�[=OFF
		inc(SV25_�X�g�b�pstep)

	case 10
		if (errpassXSW29_�X�g�b�p�㏸�[ or ( (XSW29_�X�g�b�p�㏸�[ and not(pnlPBXSW29_�X�g�b�p�㏸�[)) or passXSW29_�X�g�b�p�㏸�[) ) then		
			inc(SV25_�X�g�b�pstep)
		end if
		
	case 11
		tim_SV25_�X�g�b�p_val=10 
		res(tim_SV25_�X�g�b�p)
		inc(SV25_�X�g�b�pstep)
	
	case 12
		if tim_SV25_�X�g�b�p.B then
			inc(SV25_�X�g�b�pstep)
		end if

	case 13
		if PH17_�����m or PH18_�t�^���m then
			mSV24_�N�����v=ON '�N�����v�㏸			
			errpassXSW27_�N�����v�㏸�[=OFF
			inc(SV25_�X�g�b�pstep)
		else
			inc(SV25_�X�g�b�pstep)
		end if
		
	case 14
		if mSV24_�N�����v then
			if errpassXSW27_�N�����v�㏸�[ or ((XSW27_�N�����v�㏸�[ and not(pnlPBXSW27_�N�����v�㏸�[)) or passXSW27_�N�����v�㏸�[) then
				inc(SV25_�X�g�b�pstep)
			end if
		else
			inc(SV25_�X�g�b�pstep)
		end if

	case 15
		SV25_�X�g�b�pstep=0

	end select	
	'--------------------------------------------
	tmr(tim_SV27_�X�g�b�p, tim_SV27_�X�g�b�p_val) '�t�^�킹�X�g�b�p�[�A�N�����v
	select case SV27_�X�g�b�pstep
	case 0

	case 1
		PH17_���N�����m=PH17_�����m
		PH18_�t�^�N�����m=PH18_�t�^���m
		PH19_���N�����m=PH19_�����m
		PH20_�t�^�N�����m=PH20_�t�^���m
		
		if PH17_�����m or PH18_�t�^���m or PH19_�����m or PH20_�t�^���m then 
			mSV26_�N�����v=OFF '���~
			mSV27_�X�g�b�p=OFF '���~	
			errpassXSW32_�X�g�b�p���~�[=OFF
			errpassXSW30_�N�����v���~�[=OFF
			inc(SV27_�X�g�b�pstep)
		else
			SV27_�X�g�b�pstep=0
		end if
		
	case 2
		if (errpassXSW32_�X�g�b�p���~�[ or ((XSW32_�X�g�b�p���~�[ and not(pnlPBXSW32_�X�g�b�p���~�[)) or passXSW32_�X�g�b�p���~�[)) and (errpassXSW30_�N�����v���~�[ or ((XSW30_�N�����v���~�[ and not(pnlPBXSW30_�N�����v���~�[)) or passXSW30_�N�����v���~�[)) then 
			inc(SV27_�X�g�b�pstep)
		end if
	
	case 3
		if not(PH19_�����m) and not(PH20_�t�^���m) then		
			inc(SV27_�X�g�b�pstep)
		end if
	
	case 4
		tim_SV27_�X�g�b�p_val=35
		res(tim_SV27_�X�g�b�p)
		inc(SV27_�X�g�b�pstep)

	case 5
		if tim_SV27_�X�g�b�p.B then
			inc(SV27_�X�g�b�pstep)
		end if
	
	case 6
		mSV27_�X�g�b�p=ON '�㏸	
		errpassXSW33_�X�g�b�p�㏸�[=OFF
		inc(SV27_�X�g�b�pstep)
	
	case 7
		if errpassXSW33_�X�g�b�p�㏸�[ or ((XSW33_�X�g�b�p�㏸�[ and not(pnlPBXSW33_�X�g�b�p�㏸�[)) or passXSW33_�X�g�b�p�㏸�[) then
			inc(SV27_�X�g�b�pstep)
		end if

	case 8
		if errpassMC16_���[�^���[�� or errpassMC14_�������[�^ then
			inc(SV27_�X�g�b�pstep)				
		else if PH17_���N�����m or PH18_�t�^�N�����m then			
			if (PH19_�����m and timdly_PH19_�����m.B) or (PH20_�t�^���m and timdly_PH20_�t�^���m.B) then
				inc(SV27_�X�g�b�pstep)
			end if
		else
			inc(SV27_�X�g�b�pstep)		
		end if
		
	case 9
		if errpassMC16_���[�^���[�� or errpassMC14_�������[�^ then
			inc(SV27_�X�g�b�pstep)		
		else if PH19_���N�����m or PH20_�t�^�N�����m then
			if PH21_�����m and timdly_PH21_�����m then
				inc(SV27_�X�g�b�pstep)
			end if
		else
			inc(SV27_�X�g�b�pstep)
		end if	
		
	case 10
		mSV27_�X�g�b�p=ON '�㏸	
		errpassXSW33_�X�g�b�p�㏸�[=OFF
		inc(SV27_�X�g�b�pstep)
	
	case 11
		if errpassXSW33_�X�g�b�p�㏸�[ or ((XSW33_�X�g�b�p�㏸�[ and not(pnlPBXSW33_�X�g�b�p�㏸�[)) or passXSW33_�X�g�b�p�㏸�[) then
			inc(SV27_�X�g�b�pstep)
		end if

	case 12
		tim_SV27_�X�g�b�p_val=10 '�N�����v�㏸�^�C�~���O
		res(tim_SV27_�X�g�b�p)
		inc(SV27_�X�g�b�pstep)
	
	case 13
		if tim_SV27_�X�g�b�p.B then
			inc(SV27_�X�g�b�pstep)
		end if
	
	case 14
		if �W�킹���j�b�g���� and (PH19_�����m or PH20_�t�^���m) then
			mSV26_�N�����v=ON '�㏸
			errpassXSW31_�N�����v�㏸�[=OFF
			inc(SV27_�X�g�b�pstep)
		else
			inc(SV27_�X�g�b�pstep)
		end if
	
	case 15
		if mSV26_�N�����v then
			if errpassXSW31_�N�����v�㏸�[ or ((XSW31_�N�����v�㏸�[ and not(pnlPBXSW31_�N�����v�㏸�[)) or passXSW31_�N�����v�㏸�[) then
				inc(SV27_�X�g�b�pstep)
			end if
		else
			inc(SV27_�X�g�b�pstep)
		end if
		
	case 16
		SV27_�X�g�b�pstep=0

	end select

	'--------------------------------------------
	'MC16_���[�^���[��
	tmr(tim_MC16_���[�^���[��,tim_MC16_���[�^���[��_val)

	
	select case MC16_���[�^���[��step
	case 0

	case 1
		if LatchPH15_�����m or LatchPH16_�t�^���m then
				mSV23_���t�g=ON '���t�g���~
				errpassXSW25_���t�g�㏸�[=OFF
				inc(MC16_���[�^���[��step)
		else 
			MC16_���[�^���[��step=0
		end if
		
	case 2
		if errpassXSW25_���t�g�㏸�[ or ((XSW25_���t�g�㏸�[ and not(pnlPBXSW25_���t�g�㏸�[)) or passXSW25_���t�g�㏸�[) then
			inc(MC16_���[�^���[��step)
		end if

	case 3
		if (errpassXSW26_�N�����v���~�[ or ( (XSW26_�N�����v���~�[ and not(pnlPBXSW26_�N�����v���~�[)) or passXSW26_�N�����v���~�[) ) then		
			inc(MC16_���[�^���[��step)
		end if
	
	case 4
		if (errpassXSW28_�X�g�b�p���~�[ or ( (XSW28_�X�g�b�p���~�[ and not(pnlPBXSW28_�X�g�b�p���~�[)) or passXSW28_�X�g�b�p���~�[) ) then		
			inc(MC16_���[�^���[��step)
		end if
	
	case 5
		if (errpassXSW28_�X�g�b�p���~�[ or ( (XSW28_�X�g�b�p���~�[ and not(pnlPBXSW28_�X�g�b�p���~�[)) or passXSW28_�X�g�b�p���~�[) ) then		
			inc(MC16_���[�^���[��step)
		end if
		
	case 6	
		if (errpassXSW30_�N�����v���~�[ or ( (XSW30_�N�����v���~�[ and not(pnlPBXSW30_�N�����v���~�[)) or passXSW30_�N�����v���~�[) ) then		
			inc(MC16_���[�^���[��step)
		end if
	
	case 7	
		if (errpassXSW32_�X�g�b�p���~�[ or ( (XSW32_�X�g�b�p���~�[ and not(pnlPBXSW32_�X�g�b�p���~�[)) or passXSW32_�X�g�b�p���~�[) ) then		
			inc(MC16_���[�^���[��step)
		end if
	
	case 8	
		mMC16_���[�^���[��=ON
		errpassMC16_���[�^���[��=OFF
		inc(MC16_���[�^���[��step)
		
	case 9
		if (not(PH15_�����m) and not(PH16_�t�^���m) and not(PH17_�����m) and not(PH18_�t�^���m)) or errpassMC16_���[�^���[�� then
			inc(MC16_���[�^���[��step)
		end if
	
	case 10
		if PH15_���N�����m or PH16_�t�^�N�����m then
			if (PH17_�����m and timdly_PH17_�����m.B) or (PH18_�t�^���m and timdly_PH18_�t�^���m.B) or errpassMC16_���[�^���[�� then
				inc(MC16_���[�^���[��step)
			end if
		end if
	
	case 11
		tim_MC16_���[�^���[��_val=10
		res(tim_MC16_���[�^���[��)
		inc(MC16_���[�^���[��step)
	
	case 12
		if tim_MC16_���[�^���[��.B then
			inc(MC16_���[�^���[��step)
		end if
	
	case 13
		mMC16_���[�^���[��=OFF
		inc(MC16_���[�^���[��step)
		
	case 14
		mSV23_���t�g=OFF '���t�g���~
		errpassXSW24_���t�g���~�[=OFF
		inc(MC16_���[�^���[��step)

	case 15
		if	errpassXSW24_���t�g���~�[ or ((XSW24_���t�g���~�[ and not(pnlPBXSW24_���t�g���~�[)) or passXSW24_���t�g���~�[) then
			inc(MC16_���[�^���[��step)
		end if

	case 16
		�����R���x�AB�r�o�v��=OFF
		MC16_���[�^���[��step=0
	
	end select
	'--------------------------------------------
	'MC14_�������[�^
	tmr(tim_MC14_�������[�^,tim_MC14_�������[�^_val)
	
	select case MC14_�������[�^step
	case 0
	
	case 1
		inc(MC14_�������[�^step)
		
	case 2
		PH15_���N�����m=LatchPH15_�����m
		PH16_�t�^�N�����m=LatchPH16_�t�^���m
		PH17_���N�����m=PH17_�����m
		PH18_�t�^�N�����m=PH18_�t�^���m
		PH19_���N�����m=PH19_�����m
		PH20_�t�^�N�����m=PH20_�t�^���m
		
		if LatchPH15_�����m or LatchPH16_�t�^���m or PH17_�����m or PH18_�t�^���m or PH19_�����m or PH20_�t�^���m then
			inc(MC14_�������[�^step)
		else
			MC14_�������[�^step=0
		end if
	
	case 3
		if PH17_�����m or PH18_�t�^���m then
			if  (errpassXSW28_�X�g�b�p���~�[ or ((XSW28_�X�g�b�p���~�[ and not(pnlPBXSW28_�X�g�b�p���~�[)) or passXSW28_�X�g�b�p���~�[)) and (errpassXSW26_�N�����v���~�[ or ((XSW26_�N�����v���~�[ and not(pnlPBXSW26_�N�����v���~�[)) or passXSW26_�N�����v���~�[)) then
				inc(MC14_�������[�^step)
			end if
		else
			inc(MC14_�������[�^step)
		end if
		
	case 4
		if PH19_�����m or PH20_�t�^���m then
			if  (errpassXSW32_�X�g�b�p���~�[ or ((XSW32_�X�g�b�p���~�[ and not(pnlPBXSW32_�X�g�b�p���~�[)) or passXSW32_�X�g�b�p���~�[)) and (errpassXSW30_�N�����v���~�[ or ((XSW30_�N�����v���~�[ and not(pnlPBXSW30_�N�����v���~�[)) or passXSW30_�N�����v���~�[)) then
					inc(MC14_�������[�^step)
			end if
		else
			inc(MC14_�������[�^step)
		end if

	case 5
		mMC14_�������[�^=ON
		errpassMC14_�������[�^=OFF
		inc(MC14_�������[�^step)

	case 6
		if (not(PH15_�����m) and not(PH16_�t�^���m) and not(PH17_�����m) and not(PH18_�t�^���m) and not(PH19_�����m) and not(PH20_�t�^���m)) or errpassMC14_�������[�^ then
			inc(MC14_�������[�^step)
		end if
	
	case 7
		if errpassMC14_�������[�^ then
			inc(MC14_�������[�^step)
		else if PH15_���N�����m or PH16_�t�^�N�����m then
			if (PH17_�����m and timdly_PH17_�����m.B) or (PH18_�t�^���m and timdly_PH18_�t�^���m.B) then
				inc(MC14_�������[�^step)
			end if
		else if PH17_���N�����m or PH18_�t�^�N�����m then
			if (PH19_�����m and timdly_PH19_�����m.B) or (PH20_�t�^���m and timdly_PH20_�t�^���m.B) then
				inc(MC14_�������[�^step)
			end if
		else if PH19_���N�����m or PH20_�t�^�N�����m then
			if PH21_�����m and timdly_PH21_�����m.B  then
				inc(MC14_�������[�^step)
			end if
		end if
	
	case 8
		tim_MC14_�������[�^_val=27
		res(tim_MC14_�������[�^)
		inc(MC14_�������[�^step)
	
	case 9
		if tim_MC14_�������[�^.B then
			inc(MC14_�������[�^step)
		end if
	
	case 10
		mMC14_�������[�^=OFF
		inc(MC14_�������[�^step)

	case 11
		MC14_�������[�^step=0
	
	end select
	'--------------------------------------------
	'MC15_�������[�^
	tmr(not(PH21_�����m),timnotdlyPH21_�����m,20)
	tmr(tim_MC15_�������[�^,tim_MC15_�������[�^_val)
	
	select case MC15_�������[�^step
	case 0
	case 1
		errpassXSW32_�X�g�b�p���~�[=OFF
		errpassXSW30_�N�����v���~�[=OFF
		inc(MC15_�������[�^step)
	
	case 2
		PH19_���N�����m=PH19_�����m
		PH20_�t�^�N�����m=PH20_�t�^���m
		�t�^������=not(PH19_�����m) and PH20_�t�^���m
		'PH22_�����m
		
		if PH19_�����m or PH20_�t�^���m then
			if (errpassXSW32_�X�g�b�p���~�[ or ((XSW32_�X�g�b�p���~�[ and not(pnlPBXSW32_�X�g�b�p���~�[)) or passXSW32_�X�g�b�p���~�[)) and (errpassXSW30_�N�����v���~�[ or ((XSW30_�N�����v���~�[ and not(pnlPBXSW30_�N�����v���~�[)) or passXSW30_�N�����v���~�[) ) then
				ejectMC15_�������[�^=ON
				inc(MC15_�������[�^step)
			end if
		else
			MC15_�������[�^step=0
		end if
		
	case 3
		if not(PH19_�����m) and not(PH20_�t�^���m) then
			inc(MC15_�������[�^step)	
		end if
	
	case 4
		if PH19_���N�����m or PH20_�t�^�N�����m then
			if (PH21_�����m and timdly_PH21_�����m.B) then
				inc(MC15_�������[�^step)
			end if
		end if
		
	case 5
		if �t�^������ then
			tim_MC15_�������[�^_val=5 '�u���[�N�^�C�~���O
		else
			tim_MC15_�������[�^_val=10 '�u���[�N�^�C�~���O
		end if		
		
		res(tim_MC15_�������[�^)
		inc(MC15_�������[�^step)
	
	case 6
		if tim_MC15_�������[�^.B then 
			inc(MC15_�������[�^step)
		end if
	
	case 7
		ejectMC15_�������[�^=OFF
		inc(MC15_�������[�^step)
		
	case 8
		if �t�^������ then
			if timnotdlyPH21_�����m.B then
				inc(MC15_�������[�^step)
			end if
		else
			inc(MC15_�������[�^step)
		end if
	
	case 9
		MC15_�������[�^step=0
		
	end select
		

	'===================================================================================================================
	'�y ���ѓ����R���x�A �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case �����R���x�ACstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �����R���x�ACAutoRun then
				inc(�����R���x�ACstep)
			else 
				�����R���x�ACstep=0 '�I���ҋ@
			end if

		case 2
			if PH21_�����m then
				�����R���x�AC���쒆=OFF
				�����R���x�AC�r�o�v��=ON
				�����R���x�ACstep=1
			else
				inc(�����R���x�ACstep)
			end if
				


		case 3
		' [ �����R���x�A��~�m�F ]
			'                                 �� not(PH19_�����m) and not(PH20_�t�^���m): ���^�X�N�̔r�o�v����OFF���Ȃ��Ă��A�t�^���ӏ��Ƀ��[�N���Ȃ���΃��[�N������������B
			if (�����R���x�AC�r�o�v��=OFF or (not(PH19_�����m) and not(PH20_�t�^���m)) ) and  �����R���x�AC2���쒆=OFF and �����R���x�AB�r�o�v��  then
				inc(�����R���x�ACstep)
			else
				�����R���x�ACstep=1
			end if


		case 4
			if 	�Ȃ炵���j�b�g�r�o�v�� and �W�킹���j�b�g�r�o�v�� then
				inc(�����R���x�ACstep)
			else
				�����R���x�ACstep=1
			end if
	
		case 5 
		'[ ���_���o ]
			if �����R���x�ACOrg  then
				inc(�����R���x�ACstep)
			else
				�����R���x�ACstep=1
			end if
		
		case 6
			LatchPH15_�����m=OFF
			LatchPH16_�t�^���m=OFF
			
			�����R���x�AC���쒆=ON
			�����R���x�ACstep=100
			
		'--------------------------------------------------------------------------------------------------------------
		' �y �v���Z�X���� �z
		case 100
			LatchPH15_�����m=PH15_�����m
			LatchPH16_�t�^���m=PH16_�t�^���m
			
			inc(�����R���x�ACstep)			

		case 101
				SV25_�X�g�b�pstep=1
				SV27_�X�g�b�pstep=1
				MC14_�������[�^step=1
				MC15_�������[�^step=1
				MC16_���[�^���[��step=1
				inc(�����R���x�ACstep)
		
		case 102
			if SV25_�X�g�b�pstep=0 and SV27_�X�g�b�pstep=0 and MC14_�������[�^step=0 and MC15_�������[�^step=0 and MC16_���[�^���[��step=0 then
				inc(�����R���x�ACstep)
			end if			
		
		case 103

			StageDevice10=StageDevice9
			StageItem10=ANDA(StageDevice10.U,$00FF)  

			StageDevice9=StageDevice8
			StageItem9=ANDA(StageDevice9.U,$00FF)

			StageDevice8=StageDevice7
			StageItem8=ANDA(StageDevice8.U,$00FF)  
			StageItem7=ANDA(StageDevice7.U,$00FF)  

			inc(�����R���x�ACstep)

		case 104
			�����R���x�AB�r�o�v��=OFF
			�Ȃ炵����=OFF
			�Ȃ炵���j�b�g�r�o�v��=OFF
			�t�^�킹����=OFF
			�W�킹���j�b�g�r�o�v��=OFF
			
			if PH21_�����m then
				�����R���x�AC�r�o�v��=ON
			end if
			�����R���x�AC���쒆=OFF
			�����R���x�ACstep=1
			
		end select

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		if ManualInite=0 then
			mSV24_�N�����v=OFF
			mSV25_�X�g�b�p=OFF
			mSV26_�N�����v=OFF
			mSV27_�X�g�b�p=OFF
		
			ManualInite=1
		end if
	
		�����R���x�ACAutoRun=OFF
		
		�����R���x�ACstep=0 '�I��
		
		res(timerr_MC16_���[�^���[��)'tmr(MC16_���[�^���[��,timerr_MC16_���[�^���[��,#120)
		res(timerr_MC14_�������[�^)'tmr(MC14_�������[�^,timerr_MC14_�������[�^,#120)
		
		if ldp(pnlPBMC14_�������[�^) then
			if mMC14_�������[�^ then
				mMC14_�������[�^=OFF
			else if ((XSW24_���t�g���~�[ and not(pnlPBXSW24_���t�g���~�[)) or passXSW24_���t�g���~�[) and ((XSW25_�Ȃ炵�㏸�[ and not(pnlPBXSW25_�Ȃ炵�㏸�[)) or passXSW25_�Ȃ炵�㏸�[) and ((XSW39_�V�����_�㏸�[A and not(pnlPBXSW39_�V�����_�㏸�[A)) or passXSW39_�V�����_�㏸�[A) and ((XSW41_�V�����_�㏸�[B and not(pnlPBXSW41_�V�����_�㏸�[B)) or passXSW41_�V�����_�㏸�[B) then
				mMC14_�������[�^=ON
			end if
		end if
		

		if ldp(pnlPBMC15_�������[�^) then
			if mMC15_�������[�^ then
				mMC15_�������[�^=OFF
			else if ((XSW25_�Ȃ炵�㏸�[ and not(pnlPBXSW25_�Ȃ炵�㏸�[)) or passXSW25_�Ȃ炵�㏸�[) and ((XSW39_�V�����_�㏸�[A and not(pnlPBXSW39_�V�����_�㏸�[A)) or passXSW39_�V�����_�㏸�[A) and ((XSW41_�V�����_�㏸�[B and not(pnlPBXSW41_�V�����_�㏸�[B)) or passXSW41_�V�����_�㏸�[B) then
				mMC15_�������[�^=ON
			end if
		end if

		
		if ldp(pnlPBSV23_���t�g) then
			if mSV23_���t�g then
				mSV23_���t�g=OFF
			else
				mSV23_���t�g=ON
			end if
		end if
		
		if ldp(pnlPBSV24_�N�����v) then
			if mSV24_�N�����v then
				mSV24_�N�����v=OFF
			else
				mSV24_�N�����v=ON
			end if
		end if
		
		if ldp(pnlPBSV25_�X�g�b�p) then
			if mSV25_�X�g�b�p then
				mSV25_�X�g�b�p=OFF
			else
				mSV25_�X�g�b�p=ON
			end if
		end if
		
		if ldp(pnlPBSV26_�N�����v) then
			if mSV26_�N�����v then
				mSV26_�N�����v=OFF
			else
				mSV26_�N�����v=ON
			end if
		end if
		
		if ldp(pnlPBSV27_�X�g�b�p) then
			if mSV27_�X�g�b�p then
				mSV27_�X�g�b�p=OFF
			else 
				mSV27_�X�g�b�p=ON
			end if
		end if
		

	end if '�����R���x�ACAutoMode and not(�����R���x�ACOrgErrStep)

	'===================================================================================================================
	'�y �����R���x�ACOrgErr���� �z
	else
		res(tim_XSW24_���t�g���~�[)
		res(tim_XSW25_���t�g�㏸�[)
		res(tim_XSW26_�N�����v���~�[)
		res(tim_XSW27_�N�����v�㏸�[)
		res(tim_XSW28_�X�g�b�p���~�[)
		res(tim_XSW29_�X�g�b�p�㏸�[)
		res(tim_XSW30_�N�����v���~�[)
		res(tim_XSW31_�N�����v�㏸�[)
		res(tim_XSW32_�X�g�b�p���~�[)
		res(tim_XSW33_�X�g�b�p�㏸�[)

		res(tim_notXSW24_���t�g���~�[)
		res(tim_notXSW25_���t�g�㏸�[)
		res(tim_notXSW26_�N�����v���~�[)
		res(tim_notXSW27_�N�����v�㏸�[)
		res(tim_notXSW28_�X�g�b�p���~�[)
		res(tim_notXSW29_�X�g�b�p�㏸�[)
		res(tim_notXSW30_�N�����v���~�[)
		res(tim_notXSW31_�N�����v�㏸�[)
		res(tim_notXSW32_�X�g�b�p���~�[)
		res(tim_notXSW33_�X�g�b�p�㏸�[)

		if ResetFlg then
			�����R���x�ACOrgErr=OFF
		end if


	end if

	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
	
		�����R���x�ACErr=ON

		pauseMC14_�������[�^=ON
		pauseMC15_�������[�^=ON
		pauseMC16_���[�^���[��=ON
		res(timerr_MC16_���[�^���[��)
		res(timerr_MC14_�������[�^)
		
		select case �����R���x�ACErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW24_���t�g���~�[=OFF
				almXSW25_���t�g�㏸�[=OFF
				almXSW26_�N�����v���~�[=OFF
				almXSW27_�N�����v�㏸�[=OFF
				almXSW28_�X�g�b�p���~�[=OFF
				almXSW29_�X�g�b�p�㏸�[=OFF
				almXSW30_�N�����v���~�[=OFF
				almXSW31_�N�����v�㏸�[=OFF
				almXSW32_�X�g�b�p���~�[=OFF
				almXSW33_�X�g�b�p�㏸�[=OFF
				almXSW36_�X�g�b�p���~�[=OFF
				almXSW37_�X�g�b�p�㏸�[=OFF
				almMC14_�������[�^=OFF
				almMC16_���[�^���[��=OFF

				inc(�����R���x�ACErrStep)
			end if
		case 2
			�����R���x�ACErr=OFF

			res(tim_XSW24_���t�g���~�[)
			res(tim_XSW25_���t�g�㏸�[)
			res(tim_XSW26_�N�����v���~�[)
			res(tim_XSW27_�N�����v�㏸�[)
			res(tim_XSW28_�X�g�b�p���~�[)
			res(tim_XSW29_�X�g�b�p�㏸�[)
			res(tim_XSW30_�N�����v���~�[)
			res(tim_XSW31_�N�����v�㏸�[)
			res(tim_XSW32_�X�g�b�p���~�[)
			res(tim_XSW33_�X�g�b�p�㏸�[)

			res(tim_notXSW24_���t�g���~�[)
			res(tim_notXSW25_���t�g�㏸�[)
			res(tim_notXSW26_�N�����v���~�[)
			res(tim_notXSW27_�N�����v�㏸�[)
			res(tim_notXSW28_�X�g�b�p���~�[)
			res(tim_notXSW29_�X�g�b�p�㏸�[)
			res(tim_notXSW30_�N�����v���~�[)
			res(tim_notXSW31_�N�����v�㏸�[)
			res(tim_notXSW32_�X�g�b�p���~�[)
			res(tim_notXSW33_�X�g�b�p�㏸�[)

			pauseMC14_�������[�^=OFF
			pauseMC15_�������[�^=OFF
			pauseMC16_���[�^���[��=OFF
		
			pauseSV24_�N�����v=OFF
			pauseSV25_�X�g�b�p=OFF
			pauseSV26_�N�����v=OFF
			pauseSV27_�X�g�b�p=OFF
			pauseSV23_���t�g=OFF
			pauseSV29_�X�g�b�p=OFF


			�����R���x�ACErrStep=0
		end select

	end if 'if �����R���x�ACErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	select case �����R���x�ACEmgStep
	case 0
	
	case 1
		�����R���x�ACAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�����R���x�ACAutoMode and ��������AutoMode ) or �����R���x�ACstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseMC16_���[�^���[��=ON
			pauseMC14_�������[�^=ON
			pauseMC15_�������[�^=ON

			if timstack=OFF then
				tim_SV25_�X�g�b�p_stack=tim_SV25_�X�g�b�p.U
				tim_SV27_�X�g�b�p_stack=tim_SV27_�X�g�b�p.U
				tim_MC14_�������[�^_stack=tim_MC14_�������[�^.U
				tim_procstep_stack=tim_procstep.U
				timdly_PH15_�����m_stack=timdly_PH15_�����m.U
				timdly_PH16_�t�^���m_stack=timdly_PH16_�t�^���m.U
				timdly_PH17_�����m_stack=timdly_PH17_�����m.U
				timdly_PH18_�t�^���m_stack=timdly_PH18_�t�^���m.U
				timdly_PH19_�����m_stack=timdly_PH19_�����m.U
				timdly_PH20_�t�^���m_stack=timdly_PH20_�t�^���m.U
				timdly_PH21_�����m_stack=timdly_PH21_�����m.U
				tim_MC16_���[�^���[��_stack=tim_MC16_���[�^���[��.U
				tim_MC15_�������[�^_stack=tim_MC15_�������[�^.U
				timerr_MC16_���[�^���[��_stack=timerr_MC16_���[�^���[��.U
				timerr_MC14_�������[�^_stack=timerr_MC14_�������[�^.U
			
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC14_�������[�^=OFF
			mMC15_�������[�^=OFF
			mMC16_���[�^���[��=OFF
			mSV23_���t�g=OFF
			mSV24_�N�����v=OFF
			mSV25_�X�g�b�p=OFF
			mSV26_�N�����v=OFF
			mSV27_�X�g�b�p=OFF		
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�����R���x�ACEmgStep)
	case 2
		if ResetFlg then
			inc(�����R���x�ACEmgStep)
		end if
	case 3
		if (�����R���x�ACAutoMode and ��������AutoMode ) or �����R���x�ACstep<>0 then
			if ldp(StartFlg) then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseMC16_���[�^���[��=OFF
				pauseMC14_�������[�^=OFF
				pauseMC15_�������[�^=OFF

				tim_SV25_�X�g�b�p.U=tim_SV25_�X�g�b�p_stack
				tim_SV27_�X�g�b�p.U=tim_SV27_�X�g�b�p_stack
				tim_MC14_�������[�^.U=tim_MC14_�������[�^_stack
				tim_procstep.U=tim_procstep_stack
				tim_MC16_���[�^���[��.U=tim_MC16_���[�^���[��_stack
				tim_MC15_�������[�^.U=tim_MC15_�������[�^_stack
				timerr_MC16_���[�^���[��.U=timerr_MC16_���[�^���[��_stack
				timerr_MC14_�������[�^.U=timerr_MC14_�������[�^_stack


				res(timdly_PH15_�����m)
				res(timdly_PH16_�t�^���m)
				res(timdly_PH17_�����m)
				res(timdly_PH18_�t�^���m)
				res(timdly_PH19_�����m)
				res(timdly_PH20_�t�^���m)
				res(timdly_PH21_�����m)
				'---------------------------------
				inc(�����R���x�ACEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�����R���x�ACEmgStep)		
		end if				
	case 4
		timstack=OFF
		�����R���x�ACEmgStep=0
		�����R���x�ACEmg=OFF
	end select

end if 'if �����R���x�ACEmgStep=0 then
