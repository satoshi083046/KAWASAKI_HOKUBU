'�����R���x�AB
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	�����R���x�AB
'
'  	�ړ����x  161.667mm/1sec
'
' MC9_���[�^���[��
' [ 4 ]
' PH5_�����m			-> PH9_�����m
' PH6_�t�^���m			-> PH10_�t�^���m
' SV16_���t�g			-> SV21_���t�g
' XSW16_���t�g�㏸�[	-> XSW21_���t�g�㏸�[
' XSW15_���t�g���~�[	-> XSW20_���t�g���~�[
' ( �V�K )				-> SV51�X�g�b�p
' ( �V�K )				-> XSW18_�X�g�b�p�㏸�[
' ( �V�K )				-> XSW19_�X�g�b�p���~�[
'
' MC12_�������[�^
' [ 5 ]
' (PH11_�����m)			-> (PH11_�����m)
' (PH12_�t�^���m)		-> (PH12_�t�^���m)
' SV21_�X�g�b�p			-> SV22_�X�g�b�p
' XSW20_�X�g�b�p�㏸�[	-> XSW23_�X�g�b�p�㏸�[
' XSW19_�X�g�b�p���~�[	-> XSW22_�X�g�b�p���~�[
'
' MC13_�������[�^
' [ 6 ]
' (PH13_�����m)			-> (PH13_�����m)
' (PH14_�t�^���m)		-> (PH14_�t�^���m)
' SV22_�X�g�b�p			-> �i �폜  �V�K )	-> SV51�X�g�b�p)
' XSW22_�X�g�b�p�㏸�[	->  ( �폜  �V�K )	-> XSW18_�X�g�b�p�㏸�[)
' XSW21_�X�g�b�p���~�[	->  ( �폜  �V�K )	-> XSW19_�X�g�b�p���~�[)
'                                  
' MC16_���[�^���[��
' [ 7 ]
' (PH15_�����m)			-> (PH15_�����m)
' (PH16_�t�^���m)		-> (PH16_�t�^���m)
' SV33_���t�g			-> SV23_���t�g
' XSW38_���t�g�㏸�[	-> XSW25_���t�g�㏸�[
' XSW37_���t�g���~�[	-> XSW24_���t�g���~�[
' SV65_�X�g�b�p			->  ( �폜 )
' XSW75_�X�g�b�p�㏸�[	->  ( �폜 )
' XSW74_�X�g�b�p���~�[	->  ( �폜 )
'
'
'
'
'===================================================================================================================

'�y ���������� �z
if CR2008 then '�d��ON������������

	�����R���x�ABAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �����R���x�ABAutoRun=OFF
    �����R���x�AB����=ON
    �����R���x�ABOrgErr=OFF
    �����R���x�ABErr=OFF
    �����R���x�ABEmg=OFF
    �����R���x�ABstep=0
    �����R���x�ABErrStep=0
    �����R���x�ABOrgErrStep=0
    �����R���x�ABEmgStep=0
	

	SV21_���t�gstep=0
	SV22_�X�g�b�pstep=0
	MC12_�������[�^����step=0
	MC12_�������[�^�r�ostep=0
	MC13_�������[�^����step=0
	MC13_�������[�^�r�ostep=0

	if SSW3_�������[�h  then	
		ManualInite=1
	else
		ManualInite=0	
	end if
	
	
end if

'===================================================================================================================
'�y ���_ �z
�����R���x�ABOrg=((XSW23_�X�g�b�p�㏸�[ and not(pnlPBXSW23_�X�g�b�p�㏸�[)) or passXSW23_�X�g�b�p�㏸�[) or ((XSW22_�X�g�b�p���~�[ and not(pnlPBXSW22_�X�g�b�p���~�[)) or passXSW22_�X�g�b�p���~�[)


'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�����R���x�ABEmg=ON
	�����R���x�ABEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
tmr(SV22_�X�g�b�p and not(XSW23_�X�g�b�p�㏸�[) and not(pnlPBXSW23_�X�g�b�p�㏸�[), tim_notXSW23_�X�g�b�p�㏸�[,#30)
tmr(not(SV22_�X�g�b�p) and not(XSW22_�X�g�b�p���~�[) and not(pnlPBXSW22_�X�g�b�p���~�[),tim_notXSW22_�X�g�b�p���~�[,#30)
tmr(SV51_�X�g�b�p and not(XSW18_�X�g�b�p�㏸�[) and not(pnlPBXSW18_�X�g�b�p�㏸�[),tim_notXSW18_�X�g�b�p�㏸�[,#30)
tmr(not(SV51_�X�g�b�p) and not(XSW19_�X�g�b�p���~�[) and not(pnlPBXSW19_�X�g�b�p���~�[),tim_notXSW19_�X�g�b�p���~�[,#30)
tmr(SV23_���t�g and not(XSW25_���t�g�㏸�[) and not(pnlPBXSW25_���t�g�㏸�[), tim_notXSW25_���t�g�㏸�[, #30) 
tmr(not(SV23_���t�g) and not(XSW24_���t�g���~�[) and not(pnlPBXSW24_���t�g���~�[),tim_notXSW24_���t�g���~�[,#30)
tmr(SV21_���t�g and not(XSW21_���t�g�㏸�[) and not(pnlPBXSW21_���t�g�㏸�[) ,tim_notXSW21_���t�g�㏸�[,#30)
tmr(not(SV21_���t�g) and not(XSW20_���t�g���~�[) and not(pnlPBXSW20_���t�g���~�[) ,tim_notXSW20_���t�g���~�[,#30)

'tmr(not(SV22_�X�g�b�p) and XSW23_�X�g�b�p�㏸�[ and not(pnlPBXSW23_�X�g�b�p�㏸�[), tim_XSW23_�X�g�b�p�㏸�[,#20)
if LDP(SV22_�X�g�b�p) and XSW23_�X�g�b�p�㏸�[ and not(pnlPBXSW23_�X�g�b�p�㏸�[) then
	SET(tim_XSW23_�X�g�b�p�㏸�[)
end if
'tmr(SV22_�X�g�b�p and XSW22_�X�g�b�p���~�[ and not(pnlPBXSW22_�X�g�b�p���~�[),tim_XSW22_�X�g�b�p���~�[,#20)
if LDF(SV22_�X�g�b�p) and XSW22_�X�g�b�p���~�[ and not(pnlPBXSW22_�X�g�b�p���~�[) and not(pauseSV22_�X�g�b�p) then
	SET(tim_XSW22_�X�g�b�p���~�[)
end if
'tmr(not(SV51_�X�g�b�p) and XSW18_�X�g�b�p�㏸�[ and not(pnlPBXSW18_�X�g�b�p�㏸�[),tim_XSW18_�X�g�b�p�㏸�[,#20)
if LDP(SV51_�X�g�b�p) and XSW18_�X�g�b�p�㏸�[ and not(pnlPBXSW18_�X�g�b�p�㏸�[) then
	SET(tim_XSW18_�X�g�b�p�㏸�[)
end if
'tmr(SV51_�X�g�b�p and XSW19_�X�g�b�p���~�[ and not(pnlPBXSW19_�X�g�b�p���~�[),tim_XSW19_�X�g�b�p���~�[,#20)
if LDF(SV51_�X�g�b�p) and XSW19_�X�g�b�p���~�[ and not(pnlPBXSW19_�X�g�b�p���~�[) and not(pauseSV51_�X�g�b�p) then
	SET(tim_XSW19_�X�g�b�p���~�[)
end if
'tmr(not(SV23_���t�g) and XSW25_���t�g�㏸�[ and not(pnlPBXSW25_���t�g�㏸�[), tim_XSW25_���t�g�㏸�[, #10) 
if LDP(SV23_���t�g) and XSW25_���t�g�㏸�[ and not(pnlPBXSW25_���t�g�㏸�[) then
	SET(tim_XSW25_���t�g�㏸�[)
end if
'tmr(SV23_���t�g and XSW24_���t�g���~�[ and not(pnlPBXSW24_���t�g���~�[),tim_XSW24_���t�g���~�[,#10)
if LDF(SV23_���t�g) and XSW24_���t�g���~�[ and not(pnlPBXSW24_���t�g���~�[) and not(pauseSV23_���t�g) then
	SET(tim_XSW24_���t�g���~�[)
end if
'tmr(not(SV21_���t�g) and XSW21_���t�g�㏸�[ and not(pnlPBXSW21_���t�g�㏸�[) ,tim_XSW21_���t�g�㏸�[,#10)
if LDP(SV21_���t�g) and XSW21_���t�g�㏸�[ and not(pnlPBXSW21_���t�g�㏸�[) then
	SET(tim_XSW21_���t�g�㏸�[)
end if
'tmr(SV21_���t�g and XSW20_���t�g���~�[ and not(pnlPBXSW20_���t�g���~�[) ,tim_XSW20_���t�g���~�[,#10)
if LDF(SV21_���t�g) and XSW20_���t�g���~�[ and not(pnlPBXSW20_���t�g���~�[) and not(pauseSV21_���t�g) then
	SET(tim_XSW20_���t�g���~�[)
end if


tmr(MC12_�������[�^,timerr_MC12_�������[�^,#100)
tmr(MC13_�������[�^,timerr_MC13_�������[�^,#100)

tms(SV22_�X�g�b�p, passtimXSW23_�X�g�b�p�㏸�[,passtimXSW23_�X�g�b�p�㏸�[_val)
tms(not(SV22_�X�g�b�p),passtimXSW22_�X�g�b�p���~�[,passtimXSW22_�X�g�b�p���~�[_val)
'tms(SV51_�X�g�b�p,passtimXSW18_�X�g�b�p�㏸�[,passtimXSW18_�X�g�b�p�㏸�[_val)
'tms(not(SV51_�X�g�b�p),passtimXSW19_�X�g�b�p���~�[,passtimXSW19_�X�g�b�p���~�[_val)
tms(SV23_���t�g,passtimXSW25_���t�g�㏸�[,passtimXSW25_���t�g�㏸�[_val)
tms(not(SV23_���t�g),passtimXSW24_���t�g���~�[,passtimXSW24_���t�g���~�[_val)
'tms(SV21_���t�g,passtimXSW21_���t�g�㏸�[,passtimXSW21_���t�g�㏸�[_val)
'tms(not(SV21_���t�g),passtimXSW20_���t�g���~�[,passtimXSW20_���t�g���~�[_val)


if ldp(timerr_MC12_�������[�^.B) or ldp(timerr_MC13_�������[�^.B) then
	errpassMC12_�������[�^=ON
	mMC12_�������[�^=OFF
	ejectMC12_�������[�^=OFF

	errpassMC13_�������[�^=ON
	mMC13_�������[�^=OFF
	ejectMC13_�������[�^=OFF

	if timerr_MC12_�������[�^.B then
		almMC12_�������[�^=ON
	else if timerr_MC13_�������[�^.B then
		almMC13_�������[�^=ON
	end if
	
	�����R���x�ABErrStep=1

else if ldp(tim_XSW23_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW23_�X�g�b�p�㏸�[.B) then
	errpassXSW23_�X�g�b�p�㏸�[=ON
	pauseSV22_�X�g�b�p=ON
	almXSW23_�X�g�b�p�㏸�[=ON
	pnlPBXSW23_�X�g�b�p�㏸�[=ON
	�����R���x�ABErrStep=1

else if ldp(tim_XSW22_�X�g�b�p���~�[.B) or ldp(tim_notXSW22_�X�g�b�p���~�[.B) then
	errpassXSW22_�X�g�b�p���~�[=ON
	almXSW22_�X�g�b�p���~�[=ON
	pnlPBXSW22_�X�g�b�p���~�[=ON
	�����R���x�ABErrStep=1

else if ldp(tim_XSW18_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW18_�X�g�b�p�㏸�[.B) then
	errpassXSW18_�X�g�b�p�㏸�[=ON
	pauseSV51_�X�g�b�p=ON
	almXSW18_�X�g�b�p�㏸�[=ON
	pnlPBXSW18_�X�g�b�p�㏸�[=ON
	�����R���x�ABErrStep=1

else if ldp(tim_XSW19_�X�g�b�p���~�[.B) or ldp(tim_notXSW19_�X�g�b�p���~�[.B) then
	errpassXSW19_�X�g�b�p���~�[=ON
	almXSW22_�X�g�b�p���~�[=ON
	pnlPBXSW19_�X�g�b�p���~�[=ON
	�����R���x�ABErrStep=1

else if ldp(tim_XSW25_���t�g�㏸�[.B) or ldp(tim_notXSW25_���t�g�㏸�[.B) then
	errpassXSW25_���t�g�㏸�[=ON
	pauseSV23_���t�g=ON
	almXSW25_���t�g�㏸�[=ON
	pnlPBXSW25_���t�g�㏸�[=ON
	�����R���x�ABErrStep=1

else if ldp(tim_XSW24_���t�g���~�[.B) or ldp(tim_notXSW24_���t�g���~�[.B) then
	errpassXSW24_���t�g���~�[=ON
	almXSW24_���t�g���~�[=ON
	pnlPBXSW24_���t�g���~�[=ON
	�����R���x�ABErrStep=1

else if ldp(tim_XSW21_���t�g�㏸�[.B) or ldp(tim_notXSW21_���t�g�㏸�[.B) then
	errpassXSW21_���t�g�㏸�[=ON
	pauseSV21_���t�g=ON
	almXSW21_���t�g�㏸�[=ON
	pnlPBXSW21_���t�g�㏸�[=ON
	�����R���x�ABErrStep=1

else if ldp(tim_XSW20_���t�g���~�[.B) or ldp(tim_notXSW20_���t�g���~�[.B) then
	errpassXSW20_���t�g���~�[=ON
	almXSW20_���t�g���~�[=ON
	pnlPBXSW20_���t�g���~�[=ON
	�����R���x�ABErrStep=1

end if
'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �����R���x�ABAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �����R���x�ABAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �����R���x�ABEmg	���̏��~


if �����R���x�ABEmgStep=0 then  
	
	if �����R���x�ABErrStep=0  then

	if not(�����R���x�ABOrgErr) then

	
	tmr(PH11_�����m,timdly_PH11_�����m,2)
	tmr(PH12_�t�^���m,timdly_PH12_�t�^���m,2)
	tmr(PH13_�����m,timdly_PH13_�����m,2)
	tmr(PH14_�t�^���m,timdly_PH14_�t�^���m,2)
	tmr(PH15_�����m,timdly_PH15_�����m,10)
	tmr(PH16_�t�^���m,timdly_PH16_�t�^���m,10)
	
	'-----------------------------------------------------------------
	' �������[�^�A�X�g�b�pON/OFF�^�C�~���O�^�X�N
	'-----------------------------------------------------------------
	'�����R���x�AA SV21_���t�g
	tmr(tim_SV21_���t�g,tim_SV21_���t�g_val)
	select case SV21_���t�gstep
	case 0
		
	case 1
		PH9_���N�����m=PH9_�����m
		PH10_�t�^�N�����m=PH10_�t�^���m
	
		if  PH9_���N�����m or PH10_�t�^�N�����m then
			mSV21_���t�g=OFF
			errpassXSW20_���t�g���~�[=OFF

			mSV51_�X�g�b�p=OFF
			errpassXSW19_�X�g�b�p���~�[=OFF
			inc(SV21_���t�gstep)
		else
			SV21_���t�gstep=0
		end if
	
	case 2
'		if (errpassXSW20_���t�g���~�[ or XSW20_���t�g���~�[) and (errapssXSW19_�X�g�b�p���~�[ or XSW19_�X�g�b�p���~�[)  then
		if (errpassXSW20_���t�g���~�[ or ( (XSW20_���t�g���~�[ and not(pnlPBXSW20_���t�g���~�[)) or passXSW20_���t�g���~�[)) and ( (XSW19_�X�g�b�p���~�[ and not(pnlPBXSW19_�X�g�b�p���~�[)) or passXSW19_�X�g�b�p���~�[ or errpassXSW19_�X�g�b�p���~�[)  then
			inc(SV21_���t�gstep)
		end if

	case 3
		if errpassMC12_�������[�^ or errpassMC13_�������[�^ then
			inc(SV21_���t�gstep)
		end if		
		
		if not(PH9_�����m) and not(PH10_�t�^���m) and not(PH11_�����m) and not(PH12_�t�^���m) then
			inc(SV21_���t�gstep)
		end if
	
	case 4
		if errpassMC12_�������[�^ or errpassMC13_�������[�^ then
			inc(SV21_���t�gstep)
		end if		

		if PH9_���N�����m or PH10_�t�^�N�����m then
			if (PH11_�����m and timdly_PH11_�����m.B) or (PH12_�t�^���m and timdly_PH12_�t�^���m.B) then
				inc(SV21_���t�gstep)
			end if
		else
			inc(SV21_���t�gstep)
		end if
	
	case 5
		mSV21_���t�g=ON
		errpassXSW21_���t�g�㏸�[=OFF

		mSV51_�X�g�b�p=ON
		errpassXSW18_�X�g�b�p�㏸�[=OFF
		inc(SV21_���t�gstep)
	
	case 6
		if (errpassXSW21_���t�g�㏸�[ or ((XSW21_���t�g�㏸�[ and not(pnlPBXSW21_���t�g�㏸�[)) or passXSW21_���t�g�㏸�[)) and (errpassXSW18_�X�g�b�p�㏸�[ or ((XSW18_�X�g�b�p�㏸�[ and not(pnlPBXSW18_�X�g�b�p�㏸�[)) or passXSW18_�X�g�b�p�㏸�[)) then
			inc(SV21_���t�gstep)
		end if		
	
	case 7
		�����R���x�AA�r�o�v��=OFF
		�����R���x�AB���쒆=OFF
		SV21_���t�gstep=0
	end select
	
	
	'-----------------------------------------------------------------
	'�������j�b�g�X�g�b�p
	tmr(tim_SV22_�X�g�b�p,tim_SV22_�X�g�b�p_val)
	select case SV22_�X�g�b�pstep
	case 0
	case 1
		'PH9_���N�����m=PH9_�����m
		'PH10_�t�^�N�����m=PH10_�t�^���m
		PH11_���N�����m=PH11_�����m
		PH12_�t�^�N�����m=PH12_�t�^���m
		
		if PH9_���N�����m or PH10_�t�^�N�����m or PH11_���N�����m or PH12_�t�^�N�����m then
			mSV22_�X�g�b�p=OFF
			errpassXSW22_�X�g�b�p���~�[=OFF		
			inc(SV22_�X�g�b�pstep)
		else
			SV22_�X�g�b�pstep=0
		end if
	
	case 2
		if errpassXSW22_�X�g�b�p���~�[ or ((XSW22_�X�g�b�p���~�[ and not(pnlPBXSW22_�X�g�b�p���~�[)) or passXSW22_�X�g�b�p���~�[) then
			inc(SV22_�X�g�b�pstep)
		end if
	
	case 3
		if errpassMC12_�������[�^ or errpassMC13_�������[�^ then
			inc(SV22_�X�g�b�pstep)
		end if		

		if not(PH11_�����m) and not(PH12_�t�^���m) then
			inc(SV22_�X�g�b�pstep)
		end if
	
	case 4
		if errpassMC12_�������[�^ or errpassMC13_�������[�^ then
			inc(SV22_�X�g�b�pstep)
		end if		

		if  PH9_���N�����m or PH10_�t�^�N�����m then
			if (PH11_�����m and timdly_PH11_�����m.B) or (PH12_�t�^���m and timdly_PH12_�t�^���m.B) then
				inc(SV22_�X�g�b�pstep)
			end if
		else if PH11_���N�����m or PH12_�t�^�N�����m then
			if (PH13_�����m and timdly_PH13_�����m.B) or (PH14_�t�^���m and timdly_PH14_�t�^���m.B) then
				inc(SV22_�X�g�b�pstep)
			end if
		else
			inc(SV22_�X�g�b�pstep)
		end if
	
	case 5
		tim_SV22_�X�g�b�p_val=0
		res(tim_SV22_�X�g�b�p)
		inc(SV22_�X�g�b�pstep)
	
	case 6
		if tim_SV22_�X�g�b�p.B then
			inc(SV22_�X�g�b�pstep)
		end if
		
	case 7
		if errpassMC12_�������[�^ or errpassMC13_�������[�^ then
			inc(SV22_�X�g�b�pstep)
		end if		

		if  PH9_���N�����m or PH10_�t�^�N�����m then
			if (PH11_�����m and timdly_PH11_�����m.B) or (PH12_�t�^���m and timdly_PH12_�t�^���m.B) then
				inc(SV22_�X�g�b�pstep)
			end if
		else
			inc(SV22_�X�g�b�pstep)
		end if
	
	case 8
		mSV22_�X�g�b�p=ON
		errpassXSW23_�X�g�b�p�㏸�[=OFF
		inc(SV22_�X�g�b�pstep)

	case 9
		if mSV22_�X�g�b�p then
			if errpassXSW23_�X�g�b�p�㏸�[ or ((XSW23_�X�g�b�p�㏸�[ and not(pnlPBXSW23_�X�g�b�p�㏸�[)) or passXSW23_�X�g�b�p�㏸�[)then
				inc(SV22_�X�g�b�pstep)
			end if
		else
			inc(SV22_�X�g�b�pstep)
		end if
	
	case 10
		tim_SV22_�X�g�b�p_val=0
		res(tim_SV22_�X�g�b�p)
		inc(SV22_�X�g�b�pstep)
	
	case 11
		if tim_SV22_�X�g�b�p.B then
			inc(SV22_�X�g�b�pstep)
		end if
	
	case 12
		SV22_�X�g�b�pstep=0
		
	end select	
	'-----------------------------------------------------------------
	'MC12_�������[�^����
	tmr(tim_MC12_�������[�^����,tim_MC12_�������[�^����_val)
	select case MC12_�������[�^����step
	case 0
	case 1
		'PH9_���N�����m=PH9_�����m
		'PH10_�t�^�N�����m=PH10_�t�^���m
		
		if PH9_���N�����m or PH10_�t�^�N�����m then
			if errpassXSW22_�X�g�b�p���~�[ or ((XSW22_�X�g�b�p���~�[ and not(pnlPBXSW22_�X�g�b�p���~�[)) or passXSW22_�X�g�b�p���~�[) then
				mMC12_�������[�^=ON
				errpassMC12_�������[�^=OFF
				inc(MC12_�������[�^����step)
			end if
		else
			MC12_�������[�^����step=0
		end if
	
	case 2
		if errpassMC12_�������[�^ then
			inc(MC12_�������[�^����step)		
		end if
		
		if not(PH11_�����m) and not(PH12_�t�^���m) then
			tim_MC12_�������[�^����_val=25
			res(tim_MC12_�������[�^����)
		end if
		inc(MC12_�������[�^����step)
	
	case 3
		if tim_MC12_�������[�^����.B then
			inc(MC12_�������[�^����step)
		end if

	case 4
		if errpassMC12_�������[�^ then
			inc(MC12_�������[�^����step)		
		end if

		if not(PH9_�����m) and not(PH10_�t�^���m) then
			inc(MC12_�������[�^����step)
		end if
	
	case 5
		if errpassMC12_�������[�^ then
			inc(MC12_�������[�^����step)		
		end if

		if (PH11_�����m and timdly_PH11_�����m.B) or (PH12_�t�^���m and timdly_PH12_�t�^���m.B) then
			inc(MC12_�������[�^����step)
		end if
	
	case 6
		tim_MC12_�������[�^����_val=15
		res(tim_MC12_�������[�^����)
		inc(MC12_�������[�^����step)
	
	case 7
		if tim_MC12_�������[�^����.B then
			inc(MC12_�������[�^����step)
		end if

	case 8
		mMC12_�������[�^=OFF		
		inc(MC12_�������[�^����step)

	case 9
		MC12_�������[�^����step=0

	end select
	'-----------------------------------------------------------------
	'MC12_�������[�^�r�o
	tmr(tim_MC12_�������[�^�r�o,tim_MC12_�������[�^�r�o_val)
	select case MC12_�������[�^�r�ostep
	case 0
	case 1
		PH11_���N�����m=PH11_�����m
		PH12_�t�^�N�����m=PH12_�t�^���m
		
		if PH11_���N�����m or PH12_�t�^�N�����m then
			inc(MC12_�������[�^�r�ostep)
		else
			MC12_�������[�^�r�ostep=0
		end if
	
	case 2
		if not(PH13_�����m) and not(PH14_�t�^���m) then
			inc(MC12_�������[�^�r�ostep)
		end if			
	
	case 3
		mSV22_�X�g�b�p=OFF
		inc(MC12_�������[�^�r�ostep)
	
	case 4
		if errpassXSW22_�X�g�b�p���~�[ or ((XSW22_�X�g�b�p���~�[ and not(pnlPBXSW22_�X�g�b�p���~�[)) or passXSW22_�X�g�b�p���~�[) then
			inc(MC12_�������[�^�r�ostep)
		end if

	case 5
		ejectMC12_�������[�^=ON
		errpassMC12_�������[�^=OFF
		inc(MC12_�������[�^�r�ostep)
	

	case 6
		if errpassMC12_�������[�^ then
			inc(MC12_�������[�^�r�ostep)		
		end if
		
		if not(PH11_�����m) and not(PH12_�t�^���m) then
			inc(MC12_�������[�^�r�ostep)
		end if
	
	case 7
		if errpassMC12_�������[�^ then
			inc(MC12_�������[�^�r�ostep)		
		end if

		if (PH13_�����m and timdly_PH13_�����m.B) or (PH14_�t�^���m and timdly_PH14_�t�^���m.B) then
			inc(MC12_�������[�^�r�ostep)
		end if
	
	case 8
		tim_MC12_�������[�^�r�o_val=15
		res(tim_MC12_�������[�^�r�o)
		inc(MC12_�������[�^�r�ostep)
	
	case 9
		if tim_MC12_�������[�^�r�o.B then
			inc(MC12_�������[�^�r�ostep)
		end if
	
	case 10
		ejectMC12_�������[�^=OFF
		inc(MC12_�������[�^�r�ostep)
	
	case 11
		MC12_�������[�^�r�ostep=0

	end select

	'-----------------------------------------------------------------
	'MC13_�������[�^����
	tmr(tim_MC13_�������[�^����,tim_MC13_�������[�^����_val)
	select case MC13_�������[�^����step
	case 0
	case 1
		PH11_���N�����m=PH11_�����m
		PH12_�t�^�N�����m=PH12_�t�^���m
		
		if PH11_���N�����m or PH12_�t�^�N�����m then
			inc(MC13_�������[�^����step)
		else
			MC13_�������[�^����step=0
		end if
	
	case 2
		if not(PH13_�����m) and not(PH14_�t�^���m) then
			inc(MC13_�������[�^����step)
		end if		
	
	case 3
		if PH11_���N�����m or PH12_�t�^�N�����m then
			if errpassXSW19_�X�g�b�p���~�[ or ((XSW19_�X�g�b�p���~�[ and not(pnlPBXSW19_�X�g�b�p���~�[)) or passXSW19_�X�g�b�p���~�[) then
				inc(MC13_�������[�^����step)
			end if
		end if 

	case 4
		mMC13_�������[�^=ON
		errpassMC13_�������[�^=OFF
		inc(MC13_�������[�^����step)

	case 5
		if errpassMC13_�������[�^ then		
			inc(MC13_�������[�^�r�ostep)
		end if

		if not(PH11_�����m) and not(PH12_�t�^���m) and  not(PH13_�����m) and not(PH14_�t�^���m) then
			inc(MC13_�������[�^����step)
		end if
	
	case 6
		if errpassMC13_�������[�^ then		
			inc(MC13_�������[�^�r�ostep)
		end if

		if PH11_���N�����m or PH12_�t�^�N�����m then
			if (PH13_�����m and timdly_PH13_�����m.B) or (PH14_�t�^���m and timdly_PH14_�t�^���m.B) then
				inc(MC13_�������[�^����step)
			end if
		else
			inc(MC13_�������[�^����step)
		end if
	
	case 7
		tim_MC13_�������[�^����_val=4
		res(tim_MC13_�������[�^����)
		inc(MC13_�������[�^����step)
	
	case 8
		if tim_MC13_�������[�^����.B then
			inc(MC13_�������[�^����step)
		end if
	
	case 9
		mMC13_�������[�^=OFF
		inc(MC13_�������[�^����step)
	
	case 10
		MC13_�������[�^����step=0

	end select
	'-----------------------------------------------------------------
	'MC13_�������[�^�r�o
	tmr(tim_MC13_�������[�^�r�o,tim_MC13_�������[�^�r�o_val)
	select case MC13_�������[�^�r�ostep
	case 0
	case 1
		PH13_���N�����m=PH13_�����m
		PH14_�t�^�N�����m=PH14_�t�^���m
		
		if PH13_���N�����m or PH14_�t�^�N�����m then
			inc(MC13_�������[�^�r�ostep)
		else
			MC13_�������[�^�r�ostep=0
		end if

	case 2
		mSV23_���t�g=OFF
		errpassXSW24_���t�g���~�[=OFF
		inc(MC13_�������[�^�r�ostep)
		
	case 3
		if errpassXSW24_���t�g���~�[ or ((XSW24_���t�g���~�[ and not(pnlPBXSW24_���t�g���~�[)) or passXSW24_���t�g���~�[) then
			inc(MC13_�������[�^�r�ostep)
		end if
	
	case 4
		ejectMC13_�������[�^=ON
		errpassMC13_�������[�^=OFF
		inc(MC13_�������[�^�r�ostep)
	
	case 5
		if errpassMC13_�������[�^ then		
			inc(MC13_�������[�^�r�ostep)
		end if
		
		if not(PH13_�����m) and not(PH14_�t�^���m) then
			inc(MC13_�������[�^�r�ostep)
		end if
	
	case 6
		if errpassMC13_�������[�^ then
			inc(MC13_�������[�^�r�ostep)		
		end if
	
		if PH13_���N�����m or PH14_�t�^�N�����m then
			if (PH15_�����m and timdly_PH15_�����m.B) or (PH16_�t�^���m and timdly_PH16_�t�^���m.B) then
				inc(MC13_�������[�^�r�ostep)
			end if
		else
			inc(MC13_�������[�^�r�ostep)
		end if
	case 7
		tim_MC13_�������[�^�r�o_val=12
		res(tim_MC13_�������[�^�r�o)
		inc(MC13_�������[�^�r�ostep)
	
	case 8
		if tim_MC13_�������[�^�r�o.B then
			inc(MC13_�������[�^�r�ostep)
		end if
	
	case 9
		ejectMC13_�������[�^=OFF
		inc(MC13_�������[�^�r�ostep)
	
	case 10
		�����R���x�AB�r�o�v��=ON
		MC13_�������[�^�r�ostep=0

	end select
	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
	if (�����R���x�ABAutoMode and ��������AutoMode ) or �����R���x�ABstep<>0 then

		if not(�����R���x�ABAutoMode and ��������AutoMode ) then
			�����R���x�ABAutoRun=OFF
		end if

		if ManualInite=1 then
			mSV22_�X�g�b�p=ON
			mSV51_�X�g�b�p=ON
			mSV21_���t�g=ON
			ManualInite=0
		end if

		tmr(tim_procstep,tim_procstep_val)

		select case �����R���x�ABstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �����R���x�ABAutoRun then
				inc(�����R���x�ABstep)
			else 
				�����R���x�ABstep=0 '�I���ҋ@
			end if
		
		case 2
			if PH15_�����m or PH16_�t�^���m then
				�����R���x�AB���쒆=OFF
				�����R���x�AB�r�o�v��=ON
				�����R���x�ABstep=1
			else
				inc(�����R���x�ABstep)
			end if

		case 3
		' [ ���̔����R���x�A��~�m�F ]
			if �����R���x�AB�r�o�v��=OFF and  �����R���x�AC���쒆=OFF and �����R���x�AA�r�o�v�� then
				�����R���x�AB���쒆=ON
				inc(�����R���x�ABstep)
			else
				�����R���x�ABstep=1
			end if
			
		case 4
			if �v�����j�b�g�r�o�v�� then
				LatchPH9_�����m=OFF
				LatchPH10_�t�^���m=OFF
				inc(�����R���x�ABstep)
			else
				�����R���x�ABstep=1
			end if
		
		case 5
			if �����R���x�ABOrg then
				�����R���x�ABstep=100
			else
				�����R���x�ABstep=1
			end if

		'--------------------------------------------------------------------------------------------------------------
		case 100
			if �����R���x�ABOrg or 1 then
				errpassMC12_�������[�^=OFF
				errpassMC13_�������[�^=OFF
				errpassXSW20_���t�g���~�[=OFF
				errpassXSW19_�X�g�b�p���~�[=OFF
				inc(�����R���x�ABstep)
			else
				�����R���x�ABOrgErr=ON
			end if

		case 101
			SV21_���t�gstep=1
			inc(�����R���x�ABstep)
			
		case 102
			if not(mSV21_���t�g) and not(mSV51_�X�g�b�p) then
				inc(�����R���x�ABstep)
			end if
		
		case 103
'			if (errpassXSW20_���t�g���~�[ or XSW20_���t�g���~�[) and (errapssXSW19_�X�g�b�p���~�[ or XSW19_�X�g�b�p���~�[)  then
			if (errpassXSW20_���t�g���~�[ or ((XSW20_���t�g���~�[ and not(pnlPBXSW20_���t�g���~�[)) or passXSW20_���t�g���~�[)) and (errpassXSW19_�X�g�b�p���~�[ or (XSW19_�X�g�b�p���~�[ and not(pnlPBXSW19_�X�g�b�p���~�[)) or passXSW19_�X�g�b�p���~�[) then
				inc(�����R���x�ABstep)
			end if

			
		case 104
			SV22_�X�g�b�pstep=1
			MC12_�������[�^����step=1
			MC12_�������[�^�r�ostep=1
			MC13_�������[�^����step=1
			MC13_�������[�^�r�ostep=1
			inc(�����R���x�ABstep)

		case 105
			if 	SV21_���t�gstep=0 and SV22_�X�g�b�pstep=0 then
				if MC12_�������[�^����step=0 and MC12_�������[�^�r�ostep=0 and MC13_�������[�^����step=0 and MC13_�������[�^�r�ostep=0 then
					inc(�����R���x�ABstep)
				end if
			end if
 
			
		case 106
			StageDevice7=StageDevice6
			StageItem7=ANDA(StageDevice7.U,$00FF)  
		
			StageDevice6=StageDevice5
			StageItem6=ANDA(StageDevice6.U,$00FF)  
			
			StageDevice5=StageDevice4
			StageItem5=ANDA(StageDevice5.U,$00FF)  
			StageItem4=ANDA(StageDevice4.U,$00FF)

			inc(�����R���x�ABstep)
			
		case 107
			�����R���x�AB���쒆=OFF
			�����R���x�AA�r�o�v��=OFF
			�v�����j�b�g�r�o�v��=OFF
			�����R���x�ABstep=1

	 end select
	 
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		if ManualInite=0 then
			mSV22_�X�g�b�p=OFF
			mSV51_�X�g�b�p=OFF
			ManualInite=1
		end if
	
		�����R���x�ABAutoRun=OFF
		
		�����R���x�ABstep=0 '�I��

		res(tim_XSW23_�X�g�b�p�㏸�[)
		res(tim_XSW22_�X�g�b�p���~�[)
		res(tim_XSW18_�X�g�b�p�㏸�[)
		res(tim_XSW19_�X�g�b�p���~�[)
		res(tim_XSW25_���t�g�㏸�[)
		res(tim_XSW24_���t�g���~�[)
		res(tim_notXSW23_�X�g�b�p�㏸�[)
		res(tim_notXSW22_�X�g�b�p���~�[)
		res(tim_notXSW18_�X�g�b�p�㏸�[)
		res(tim_notXSW19_�X�g�b�p���~�[)
		res(tim_notXSW25_���t�g�㏸�[)
		res(tim_notXSW24_���t�g���~�[)
		res(timerr_MC12_�������[�^)
		res(timerr_MC13_�������[�^)

		
		if ldp(pnlPBMC9_���[�^���[��) then
			if mMC9_���[�^���[�� then
				mMC9_���[�^���[��=OFF
			else
					mMC9_���[�^���[��=ON
			end if
		end if
		
		if ldp(pnlPBMC12_�������[�^) then
			if mMC12_�������[�^ then
				mMC12_�������[�^=OFF
			else
				mMC12_�������[�^=ON
			end if
		end if
		
		if ldp(pnlPBMC13_�������[�^) then
			if mMC13_�������[�^ then
				mMC13_�������[�^=OFF
			else
				mMC13_�������[�^=ON
			end if
		end if
		
		if ldp(pnlPBMC16_���[�^���[��) then
			if mMC16_���[�^���[�� then
				mMC16_���[�^���[��=OFF
			else
				mMC16_���[�^���[��=ON
			end if
		end if
		
		if ldp(pnlPBSV22_�X�g�b�p) then
			if mSV22_�X�g�b�p then
				mSV22_�X�g�b�p=OFF
			else
				mSV22_�X�g�b�p=ON
			end if
		end if
		
		if ldp(pnlPBSV51_�X�g�b�p) then
			if mSV51_�X�g�b�p then
				mSV51_�X�g�b�p=OFF
			else
				mSV51_�X�g�b�p=ON
			end if
		end if
		
		if ldp(pnlPBSV21_���t�g) then
			if mSV21_���t�g then
				mSV21_���t�g=OFF
			else
				mSV21_���t�g=ON
			end if
		end if
			
	end if '�����R���x�ABAutoMode and not(�����R���x�ABOrgErrStep)

	'===================================================================================================================
	'�y �����R���x�ABOrgErr���� �z
	else
	
		res(tim_XSW23_�X�g�b�p�㏸�[)
		res(tim_XSW22_�X�g�b�p���~�[)
		res(tim_XSW18_�X�g�b�p�㏸�[)
		res(tim_XSW19_�X�g�b�p���~�[)
		res(tim_XSW25_���t�g�㏸�[)
		res(tim_XSW24_���t�g���~�[)
		res(tim_notXSW23_�X�g�b�p�㏸�[)
		res(tim_notXSW22_�X�g�b�p���~�[)
		res(tim_notXSW18_�X�g�b�p�㏸�[)
		res(tim_notXSW19_�X�g�b�p���~�[)
		res(tim_notXSW25_���t�g�㏸�[)
		res(tim_notXSW24_���t�g���~�[)

		if ResetFlg then
			�����R���x�ABOrgErr=OFF
		end if

	end if

	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else

		�����R���x�ABErr=ON

		pauseMC9_���[�^���[��=ON
		pauseMC12_�������[�^=ON
		pauseMC13_�������[�^=ON
		'pauseMC16_���[�^���[��=ON
		res(timerr_MC12_�������[�^)
		res(timerr_MC13_�������[�^)

		select case �����R���x�ABErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW23_�X�g�b�p�㏸�[=OFF
				almXSW22_�X�g�b�p���~�[=OFF
				almXSW21_���t�g�㏸�[=OFF
				almXSW18_�X�g�b�p�㏸�[=OFF
				almXSW19_�X�g�b�p���~�[=OFF
				almXSW25_���t�g�㏸�[=OFF
				almXSW24_���t�g���~�[=OFF
				
				almMC12_�������[�^=OFF
				almMC13_�������[�^=OFF

				inc(�����R���x�ABErrStep)
			end if
		case 2
			�����R���x�ABErr=OFF

			pauseMC9_���[�^���[��=OFF
			pauseMC12_�������[�^=OFF
			pauseMC13_�������[�^=OFF
			'pauseMC16_���[�^���[��=OFF
			
			pauseSV22_�X�g�b�p=OFF
			pauseSV51_�X�g�b�p=OFF
			pauseSV23_���t�g=OFF
			pauseSV21_���t�g=OFF

			res(tim_XSW23_�X�g�b�p�㏸�[)
			res(tim_XSW22_�X�g�b�p���~�[)
			res(tim_XSW18_�X�g�b�p�㏸�[)
			res(tim_XSW19_�X�g�b�p���~�[)
			res(tim_XSW25_���t�g�㏸�[)
			res(tim_XSW24_���t�g���~�[)
			res(tim_notXSW23_�X�g�b�p�㏸�[)
			res(tim_notXSW22_�X�g�b�p���~�[)
			res(tim_notXSW18_�X�g�b�p�㏸�[)
			res(tim_notXSW19_�X�g�b�p���~�[)
			res(tim_notXSW25_���t�g�㏸�[)
			res(tim_notXSW24_���t�g���~�[)
			res(timerr_MC12_�������[�^)
			res(timerr_MC13_�������[�^)

			�����R���x�ABErrStep=0
		end select

	end if 'if �����R���x�ABErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	select case �����R���x�ABEmgStep
	case 0
	
	case 1
		�����R���x�ABAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�����R���x�ABAutoMode and ��������AutoMode ) or �����R���x�ABstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseMC12_�������[�^=ON
			pauseMC13_�������[�^=ON
						
			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				tim_SV51_�X�g�b�p_stack=tim_SV51_�X�g�b�p.U
				tim_MC12_�������[�^����_stack=tim_MC12_�������[�^����.U
				tim_MC12_�������[�^�r�o_stack=tim_MC12_�������[�^�r�o.U
				tim_MC13_�������[�^����_stack=tim_MC13_�������[�^����.U
				tim_MC13_�������[�^�r�o_stack=tim_MC13_�������[�^�r�o.U
				tim_MC16_���[�^���[��_stack=tim_MC16_���[�^���[��.U
				tim_MC9_���[�^���[��_stack=tim_MC9_���[�^���[��.U
				tim_SV21_���t�g_stack=tim_SV21_���t�g.U
				tim_SV22_�X�g�b�p_stack=tim_SV22_�X�g�b�p.U
			
				tim_PH9_�����m_stack=tim_PH9_�����m.U
				tim_PH10_�t�^���m_stack=tim_PH10_�t�^���m.U
				timdly_PH11_�����m_stack=timdly_PH11_�����m.U
				timdly_PH12_�t�^���m_stack=timdly_PH12_�t�^���m.U
				timdly_PH13_�����m_stack=timdly_PH13_�����m.U
				timdly_PH14_�t�^���m_stack=timdly_PH14_�t�^���m.U
				timdly_PH15_�����m_stack=timdly_PH15_�����m.U
				timdly_PH16_�t�^���m_stack=timdly_PH16_�t�^���m.U

				timstack=ON
			end if
			
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC9_���[�^���[��=OFF
			mMC12_�������[�^=OFF
			mMC13_�������[�^=OFF
			mMC16_���[�^���[��=OFF
			mSV22_�X�g�b�p=OFF
			mSV51_�X�g�b�p=OFF
			mSV21_���t�g=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�����R���x�ABEmgStep)
	case 2
		if ResetFlg then
			inc(�����R���x�ABEmgStep)
		end if
	case 3
		if (�����R���x�ABAutoMode and ��������AutoMode ) or �����R���x�ABstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseMC12_�������[�^=OFF
				pauseMC13_�������[�^=OFF

				tim_procstep.U=tim_procstep_stack
				tim_SV51_�X�g�b�p.U=tim_SV51_�X�g�b�p_stack
				tim_MC12_�������[�^����.U=tim_MC12_�������[�^����_stack
				tim_MC12_�������[�^�r�o.U=tim_MC12_�������[�^�r�o_stack
				tim_MC13_�������[�^����.U=tim_MC13_�������[�^����_stack
				tim_MC13_�������[�^�r�o.U=tim_MC13_�������[�^�r�o_stack
				tim_MC16_���[�^���[��.U=tim_MC16_���[�^���[��_stack
				tim_MC9_���[�^���[��.U=tim_MC9_���[�^���[��_stack
				tim_SV21_���t�g.U=tim_SV21_���t�g_stack
				tim_SV22_�X�g�b�p.U=tim_SV22_�X�g�b�p_stack

				res(tim_PH9_�����m)
				res(tim_PH10_�t�^���m)
				res(timdly_PH11_�����m)
				res(timdly_PH12_�t�^���m)
				res(timdly_PH13_�����m)
				res(timdly_PH14_�t�^���m)
				res(timdly_PH15_�����m)
				res(timdly_PH16_�t�^���m)
				'---------------------------------
				inc(�����R���x�ABEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�����R���x�ABEmgStep)		
		end if				
	case 4
		timstack=OFF
		�����R���x�ABEmgStep=0
		�����R���x�ABEmg=OFF
	end select

end if 'if �����R���x�ABEmgStep=0 then
