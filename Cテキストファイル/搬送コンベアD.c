'�����R���x�AD
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	�����R���x�AD
'
'  	�ړ����x  161.667mm/1sec
'
'11	SV28_���t�g		XSW34_���t�g�㏸�[		PH22_�����m
'					XSW35_���t�g���~�[	
'	SV29_�X�g�b�p	XSW37_�X�g�b�p�㏸�[	
'					XSW36_�X�g�b�p���~�[	
'	MC34_���[�^���[��
'	MC44_���[�^���[��
'	MC46_���[�^���[��
'			
'12	SV43_���t�g		XSW53_���t�g�㏸�[		PH24_�����m
'					XSW54_���t�g���~�[	
'	SV42_�X�g�b�p	XSW51_�X�g�b�p�㏸�[	
'					XSW52_�X�g�b�p���~�[	
'			
'			
'===================================================================================================================

'�y ���������� �z
if CR2008 then '�d��ON������������

	�����R���x�ADAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �����R���x�ADAutoRun=OFF
    �����R���x�AD����=ON
    �����R���x�ADOrgErr=OFF
    �����R���x�ADErr=OFF
    �����R���x�ADEmg=OFF
    �����R���x�ADstep=0
    �����R���x�ADErrStep=0
    �����R���x�ADOrgErrStep=0
    �����R���x�ADEmgStep=0
	
	MC34_���[�^���[��step=0
	MC44_���[�^���[��step=0
	MC46_���[�^���[��step=0

	if SSW3_�������[�h then	
		ManualInite=1
	else
		ManualInite=0	
	end if
	
	
end if

'===================================================================================================================
'�y ���_ �z
�����R���x�ADOrg=((XSW53_���t�g�㏸�[ and not(pnlPBXSW53_���t�g�㏸�[)) or passXSW53_���t�g�㏸�[) or ((XSW54_���t�g���~�[ and not(pnlPBXSW54_���t�g���~�[)) or passXSW54_���t�g���~�[)
�����R���x�ADOrg= �����R���x�ADOrg and ( ((XSW51_�X�g�b�p�㏸�[ and not(pnlPBXSW51_�X�g�b�p�㏸�[)) or passXSW51_�X�g�b�p�㏸�[) or ((XSW52_�X�g�b�p���~�[ and not(pnlPBXSW52_�X�g�b�p���~�[)) or passXSW52_�X�g�b�p���~�[) )

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�����R���x�ADEmg=ON
	�����R���x�ADEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
tmr(SV29_�X�g�b�p and not(XSW37_�X�g�b�p�㏸�[) and not(pnlPBXSW37_�X�g�b�p�㏸�[),tim_notXSW37_�X�g�b�p�㏸�[,#30)
tmr(not(SV29_�X�g�b�p) and not(XSW36_�X�g�b�p���~�[) and not(pnlPBXSW36_�X�g�b�p���~�[),tim_notXSW36_�X�g�b�p���~�[,#30)
tmr(SV28_���t�g and not(XSW34_���t�g�㏸�[) and not(pnlPBXSW34_���t�g�㏸�[) ,tim_notXSW34_���t�g�㏸�[,#30)
tmr(not(SV28_���t�g) and not(XSW35_���t�g���~�[) and not(pnlPBXSW35_���t�g���~�[) ,tim_notXSW35_���t�g���~�[,#30)
tmr(SV42_�X�g�b�p and not(XSW51_�X�g�b�p�㏸�[) and not(pnlPBXSW51_�X�g�b�p�㏸�[), tim_notXSW51_�X�g�b�p�㏸�[,#30)
tmr(not(SV42_�X�g�b�p) and not(XSW52_�X�g�b�p���~�[) and not(pnlPBXSW52_�X�g�b�p���~�[),tim_notXSW52_�X�g�b�p���~�[,#30)
tmr(SV43_���t�g and not(XSW53_���t�g�㏸�[) and not(pnlPBXSW53_���t�g�㏸�[), tim_notXSW53_���t�g�㏸�[, #30) 
tmr(not(SV43_���t�g) and not(XSW54_���t�g���~�[) and not(pnlPBXSW54_���t�g���~�[),tim_notXSW54_���t�g���~�[,#30)

'tmr(not(SV29_�X�g�b�p) and XSW37_�X�g�b�p�㏸�[ and not(pnlPBXSW37_�X�g�b�p�㏸�[),tim_XSW37_�X�g�b�p�㏸�[,#10)
if LDP(SV29_�X�g�b�p) and XSW37_�X�g�b�p�㏸�[ and not(pnlPBXSW37_�X�g�b�p�㏸�[) then
	SET(tim_XSW37_�X�g�b�p�㏸�[)
end if
'tmr(SV29_�X�g�b�p and XSW36_�X�g�b�p���~�[ and not(pnlPBXSW36_�X�g�b�p���~�[),tim_XSW36_�X�g�b�p���~�[,#10)
if LDF(SV29_�X�g�b�p) and XSW36_�X�g�b�p���~�[ and not(pnlPBXSW36_�X�g�b�p���~�[) and not(pauseSV29_�X�g�b�p) then
	SET(tim_XSW36_�X�g�b�p���~�[)
end if
'tmr(not(SV28_���t�g) and XSW34_���t�g�㏸�[ and not(pnlPBXSW34_���t�g�㏸�[) ,tim_XSW34_���t�g�㏸�[,#10)
if LDP(SV28_���t�g) and XSW34_���t�g�㏸�[ and not(pnlPBXSW34_���t�g�㏸�[) then
	SET(tim_XSW34_���t�g�㏸�[)
end if
'tmr(SV28_���t�g and XSW35_���t�g���~�[ and not(pnlPBXSW35_���t�g���~�[) ,tim_XSW35_���t�g���~�[,#10)
if LDF(SV28_���t�g) and XSW35_���t�g���~�[ and not(pnlPBXSW35_���t�g���~�[) and not(pauseSV28_���t�g) then
	SET(tim_XSW35_���t�g���~�[)
end if
'tmr(not(SV42_�X�g�b�p) and XSW51_�X�g�b�p�㏸�[ and not(pnlPBXSW51_�X�g�b�p�㏸�[), tim_XSW51_�X�g�b�p�㏸�[,#10)
if LDP(SV42_�X�g�b�p) and XSW51_�X�g�b�p�㏸�[ and not(pnlPBXSW51_�X�g�b�p�㏸�[) then
	SET(tim_XSW51_�X�g�b�p�㏸�[)
end if
'tmr(SV42_�X�g�b�p and XSW52_�X�g�b�p���~�[ and not(pnlPBXSW52_�X�g�b�p���~�[),tim_XSW52_�X�g�b�p���~�[,#10)
if LDF(SV42_�X�g�b�p) and XSW52_�X�g�b�p���~�[ and not(pnlPBXSW52_�X�g�b�p���~�[) and not(pauseSV42_�X�g�b�p) then
	SET(tim_XSW52_�X�g�b�p���~�[)
end if
'tmr(not(SV43_���t�g) and XSW53_���t�g�㏸�[ and not(pnlPBXSW53_���t�g�㏸�[), tim_XSW53_���t�g�㏸�[, #10) 
if LDP(SV43_���t�g) and XSW53_���t�g�㏸�[ and not(pnlPBXSW53_���t�g�㏸�[) then
	SET(tim_XSW53_���t�g�㏸�[)
end if
'tmr(SV43_���t�g and XSW54_���t�g���~�[ and not(pnlPBXSW54_���t�g���~�[),tim_XSW54_���t�g���~�[,#10)
if LDF(SV43_���t�g) and XSW54_���t�g���~�[ and not(pnlPBXSW54_���t�g���~�[) and not(pauseSV43_���t�g) then
	SET(tim_XSW54_���t�g���~�[)
end if

'tms(SV29_�X�g�b�p,passtimXSW37_�X�g�b�p�㏸�[,passtimXSW37_�X�g�b�p�㏸�[_val)
'tms(not(SV29_�X�g�b�p),passtimXSW36_�X�g�b�p���~�[,passtimXSW36_�X�g�b�p���~�[_val)
'tms(SV28_���t�g,passtimXSW34_���t�g�㏸�[,passtimXSW34_���t�g�㏸�[_val)
'tms(not(SV28_���t�g),passtimXSW35_���t�g���~�[,passtimXSW35_���t�g���~�[_val)
tms(SV42_�X�g�b�p,passtimXSW51_�X�g�b�p�㏸�[,passtimXSW51_�X�g�b�p�㏸�[_val)
tms(not(SV42_�X�g�b�p),passtimXSW52_�X�g�b�p���~�[,passtimXSW52_�X�g�b�p���~�[_val)
tms(SV43_���t�g,passtimXSW53_���t�g�㏸�[,passtimXSW53_���t�g�㏸�[_val)
tms(not(SV43_���t�g),passtimXSW54_���t�g���~�[,passtimXSW54_���t�g���~�[_val)

if ldp(tim_XSW51_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW51_�X�g�b�p�㏸�[.B) then
	errpassXSW51_�X�g�b�p�㏸�[=ON
	almXSW51_�X�g�b�p�㏸�[=ON
	pnlPBXSW51_�X�g�b�p�㏸�[=ON
	�����R���x�ADErrStep=1

else if ldp(tim_XSW52_�X�g�b�p���~�[.B) or ldp(tim_notXSW52_�X�g�b�p���~�[.B) then
	errpassXSW52_�X�g�b�p���~�[=ON
	almXSW52_�X�g�b�p���~�[=ON
	pnlPBXSW52_�X�g�b�p���~�[=ON
	�����R���x�ADErrStep=1

else if ldp(tim_XSW37_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW37_�X�g�b�p�㏸�[.B) then
	errpassXSW37_�X�g�b�p�㏸�[=ON
	almXSW37_�X�g�b�p�㏸�[=ON
	pnlPBXSW37_�X�g�b�p�㏸�[=ON
	�����R���x�ADErrStep=1

else if ldp(tim_XSW36_�X�g�b�p���~�[.B) or ldp(tim_notXSW36_�X�g�b�p���~�[.B) then
	errpassXSW36_�X�g�b�p���~�[=ON
	almXSW36_�X�g�b�p���~�[=ON
	pnlPBXSW36_�X�g�b�p���~�[=ON
	�����R���x�ADErrStep=1

else if ldp(tim_XSW53_���t�g�㏸�[.B) or ldp(tim_notXSW53_���t�g�㏸�[.B) then
	errpassXSW53_���t�g�㏸�[=ON
	almXSW53_���t�g�㏸�[=ON
	pnlPBXSW53_���t�g�㏸�[=ON
	�����R���x�ADErrStep=1

else if ldp(tim_XSW54_���t�g���~�[.B) or ldp(tim_notXSW54_���t�g���~�[.B) then
	errpassXSW54_���t�g���~�[=ON
	almXSW54_���t�g���~�[=ON
	pnlPBXSW54_���t�g���~�[=ON
	�����R���x�ADErrStep=1

else if ldp(tim_XSW34_���t�g�㏸�[.B) or ldp(tim_notXSW34_���t�g�㏸�[.B) then
	errpassXSW34_���t�g�㏸�[=ON
	almXSW34_���t�g�㏸�[=ON
	pnlPBXSW34_���t�g�㏸�[=ON
	�����R���x�ADErrStep=1

else if ldp(tim_XSW35_���t�g���~�[.B) or ldp(tim_notXSW35_���t�g���~�[.B) then
	errpassXSW35_���t�g���~�[=ON
	almXSW35_���t�g���~�[=ON
	pnlPBXSW35_���t�g���~�[=ON
	�����R���x�ADErrStep=1

end if
'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �����R���x�ADAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �����R���x�ADAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �����R���x�ADEmg	���̏��~


if �����R���x�ADEmgStep=0 then  
	
	if �����R���x�ADErrStep=0  then

	if not(�����R���x�ADOrgErr) then

	
	tmr(PH24_�����m,timdly_PH24_�����m,2)
	
	'-----------------------------------------------------------------
	' �������[�^�A�X�g�b�pON/OFF�^�C�~���O�^�X�N
	'-----------------------------------------------------------------
	tmr(tim_MC34_���[�^���[��,tim_MC34_���[�^���[��_val)
	select case MC34_���[�^���[��step
	case 0
	case 1
		if  PH22_���N�����m  then
			mSV28_���t�g=ON
			errpassXSW34_���t�g�㏸�[=OFF

			mSV29_�X�g�b�p=OFF
			errpassXSW36_�X�g�b�p���~�[=OFF
			
			inc(MC34_���[�^���[��step)
		else
			MC34_���[�^���[��step=0
		end if
	
	case 2
		if errpassXSW34_���t�g�㏸�[ or ((XSW34_���t�g�㏸�[ and not(pnlPBXSW34_���t�g�㏸�[)) or passXSW34_���t�g�㏸�[) then
			inc(MC34_���[�^���[��step)
		end if
		
	case 3
		if errpassXSW36_�X�g�b�p���~�[ or ((XSW36_�X�g�b�p���~�[ or not(pnlPBXSW36_�X�g�b�p���~�[)) or passXSW36_�X�g�b�p���~�[) then
			inc(MC34_���[�^���[��step)
		end if

	case 4
		mMC34_���[�^���[��=ON
		inc(MC34_���[�^���[��step)

	case 5
		if not(PH22_�����m) then
			inc(MC34_���[�^���[��step)
		end if
	
	case 6
		if  PH22_���N�����m  then
			if (PH24_�����m and timdly_PH24_�����m.B) then
				inc(MC34_���[�^���[��step)
			end if
		end if
	
	case 7
		mMC34_���[�^���[��=OFF
		inc(MC34_���[�^���[��step)
	
	case 8
		tim_MC34_���[�^���[��_val=0
		res(tim_MC34_���[�^���[��)
		inc(MC34_���[�^���[��step)
	
	case 9
		if tim_MC34_���[�^���[��.B then
			inc(MC34_���[�^���[��step)
		end if
	
	case 10
		mSV28_���t�g=OFF
		errpassXSW35_���t�g���~�[=OFF
		inc(MC34_���[�^���[��step)
	
	case 11
		if errpassXSW35_���t�g���~�[ or ((XSW35_���t�g���~�[ and not(pnlPBXSW35_���t�g���~�[)) or passXSW35_���t�g���~�[) then
			inc(MC34_���[�^���[��step)
		end if		
	
	case 12
		mSV29_�X�g�b�p=ON
		errpassXSW37_�X�g�b�p�㏸�[=OFF
		inc(MC34_���[�^���[��step)
	
	case 13
		if errpassXSW37_�X�g�b�p�㏸�[ or ((XSW37_�X�g�b�p�㏸�[ and not(pnlPBXSW37_�X�g�b�p�㏸�[)) or passXSW37_�X�g�b�p�㏸�[) then
			inc(MC34_���[�^���[��step)
		end if
		
	case 14
		�����R���x�AC2�r�o�v��=OFF
		�����R���x�AD���쒆=OFF
		MC34_���[�^���[��step=0
	end select
	
	
	'-----------------------------------------------------------------
	'MC44_���[�^���[��
	tmr(tim_MC44_���[�^���[��,tim_MC44_���[�^���[��_val)
	select case MC44_���[�^���[��step
	case 0
	case 1
		if  PH22_���N�����m  then
				mMC44_���[�^���[��=ON		
				inc(MC44_���[�^���[��step)
		else
			MC44_���[�^���[��step=0
		end if
	

	case 2
		if  PH22_���N�����m  then
			if (PH24_�����m and timdly_PH24_�����m.B) then
				inc(MC44_���[�^���[��step)
			end if
		end if
	
	case 3
		tim_MC44_���[�^���[��_val=10
		res(tim_MC44_���[�^���[��)
		inc(MC44_���[�^���[��step)
	
	case 4
		if tim_MC44_���[�^���[��.B then
			inc(MC44_���[�^���[��step)
		end if

	
	case 5
		mMC44_���[�^���[��=OFF
		inc(MC44_���[�^���[��step)
	
	case 6
		tim_MC44_���[�^���[��_val=0
		res(tim_MC44_���[�^���[��)
		inc(MC44_���[�^���[��step)
	
	case 7
		if tim_MC44_���[�^���[��.B then
			inc(MC44_���[�^���[��step)
		end if
	
	case 8
		MC44_���[�^���[��step=0

	end select

	'--------------------------------------------
	tmr(tim_MC46_���[�^���[��,tim_MC46_���[�^���[��_val)
	select case MC46_���[�^���[��step
	case 0
	case 1
		if  PH22_���N�����m  then
			mSV43_���t�g=ON
			errpassXSW53_���t�g�㏸�[=OFF
			mSV42_�X�g�b�p=ON
			errpassXSW51_�X�g�b�p�㏸�[=OFF
			inc(MC46_���[�^���[��step)
		else
			MC46_���[�^���[��step=0
		end if
		
	
	case 2
		if (errpassXSW53_���t�g�㏸�[ or ((XSW53_���t�g�㏸�[ and not(pnlPBXSW53_���t�g�㏸�[)) or passXSW53_���t�g�㏸�[)) and (errpassXSW51_�X�g�b�p�㏸�[ or ((XSW51_�X�g�b�p�㏸�[ and not(pnlPBXSW51_�X�g�b�p�㏸�[)) or passXSW51_�X�g�b�p�㏸�[)) then
			inc(MC46_���[�^���[��step)
		end if

	case 3
		mMC46_���[�^���[��=ON
		inc(MC46_���[�^���[��step)
	
	case 4
		if not(PH22_�����m) then
			inc(MC46_���[�^���[��step)
		end if
	
	case 5
		if  PH22_���N�����m  then
			if (PH24_�����m and timdly_PH24_�����m.B) then
				inc(MC46_���[�^���[��step)
			end if
		end if
	
	case 6
		tim_MC46_���[�^���[��_val=10
		res(tim_MC46_���[�^���[��)
		inc(MC46_���[�^���[��step)
	
	case 7
		if tim_MC46_���[�^���[��.B then
			inc(MC46_���[�^���[��step)
		end if

	
	case 8
		mMC46_���[�^���[��=OFF
		inc(MC46_���[�^���[��step)
	
	case 9
		tim_MC46_���[�^���[��_val=0
		res(tim_MC46_���[�^���[��)
		inc(MC46_���[�^���[��step)
	
	case 10
		if tim_MC46_���[�^���[��.B then
			inc(MC46_���[�^���[��step)
		end if
	
	case 11
		�����R���x�AD�r�o�v��=ON
		MC46_���[�^���[��step=0
	end select
	'-----------------------------------------------------------------

	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
	if (�����R���x�ADAutoMode and ��������AutoMode ) or �����R���x�ADstep<>0 then
	
		if ManualInite=1 then
			mSV42_�X�g�b�p=ON
			mSV29_�X�g�b�p=ON
			ManualInite=0
		end if
		
		if not(�����R���x�ADAutoMode and ��������AutoMode ) then
			�����R���x�ADAutoRun=OFF
		end if

		tmr(tim_procstep,tim_procstep_val)

		select case �����R���x�ADstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �����R���x�ADAutoRun then
				inc(�����R���x�ADstep)
			else 
				�����R���x�ADstep=0 '�I���ҋ@
			end if
		
		case 2
			if PH24_�����m then
				�����R���x�AD���쒆=OFF
				�����R���x�AD�r�o�v��=ON
				�����R���x�ADstep=1
			else
				inc(�����R���x�ADstep)
			end if
		
		case 3
		' [ ���̔����R���x�A��~�m�F ]
			if �����R���x�AD�r�o�v��=OFF and  �����R���x�AE���쒆=OFF and �����R���x�AC2�r�o�v�� then
				�����R���x�AD���쒆=ON
				�����R���x�ADstep=100
			else
				�����R���x�ADstep=1
			end if
			
		case 4  '���_���o
			if �����R���x�ADOrg then				
				inc(�����R���x�ADstep)
			else
				�����R���x�ADstep=1
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		case 100
			if �����R���x�ADOrg or 1 then
				inc(�����R���x�ADstep)
			else
				�����R���x�ADOrgErr=ON
			end if

		
		case 101
			LatchPH22_�����m=OFF
			inc(�����R���x�ADstep)

		case 102
			PH22_���N�����m=LatchPH22_�����m
			
			MC34_���[�^���[��step=1
			MC44_���[�^���[��step=1
			MC46_���[�^���[��step=1
			
			inc(�����R���x�ADstep)


		case 103
			if 	MC34_���[�^���[��step=0 and MC44_���[�^���[��step=0 and MC46_���[�^���[��step=0 then
				inc(�����R���x�ADstep)
			end if
			
		case 104
			StageDevice12=StageDevice11
			StageItem12=ANDA(StageDevice12.U,$00FF)  
			StageItem11=ANDA(StageDevice11.U,$00FF)  
			inc(�����R���x�ADstep)
		
		case 105
			IHA�}���D��=ON
			�����R���x�AD���쒆=OFF
			�����R���x�ADstep=1

	 end select
	 
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		if ManualInite=0 then
			mSV42_�X�g�b�p=OFF
			mSV29_�X�g�b�p=OFF
			ManualInite=1
		end if
	
		�����R���x�ADAutoRun=OFF
		
		�����R���x�ADstep=0 '�I��

		res(tim_notXSW51_�X�g�b�p�㏸�[)
		res(tim_notXSW52_�X�g�b�p���~�[)
		res(tim_notXSW37_�X�g�b�p�㏸�[)
		res(tim_notXSW36_�X�g�b�p���~�[)
		res(tim_notXSW53_���t�g�㏸�[)
		res(tim_notXSW54_���t�g���~�[)
		res(tim_notXSW34_���t�g�㏸�[)
		res(tim_notXSW35_���t�g���~�[)

		res(tim_XSW51_�X�g�b�p�㏸�[)
		res(tim_XSW52_�X�g�b�p���~�[)
		res(tim_XSW37_�X�g�b�p�㏸�[)
		res(tim_XSW36_�X�g�b�p���~�[)
		res(tim_XSW53_���t�g�㏸�[)
		res(tim_XSW54_���t�g���~�[)
		res(tim_XSW34_���t�g�㏸�[)
		res(tim_XSW35_���t�g���~�[)
		
		if ldp(pnlPBMC34_���[�^���[��) then
			if mMC34_���[�^���[�� then
				mMC34_���[�^���[��=OFF
			else
					mMC34_���[�^���[��=ON
			end if
		end if
		
		if ldp(pnlPBMC44_���[�^���[��) then
			if mMC44_���[�^���[�� then
				mMC44_���[�^���[��=OFF
			else
				mMC44_���[�^���[��=ON
			end if
		end if
		
		if ldp(pnlPBMC46_���[�^���[��) then
			if mMC46_���[�^���[�� then
				mMC46_���[�^���[��=OFF
			else
				mMC46_���[�^���[��=ON
			end if
		end if

	end if '�����R���x�ADAutoMode and not(�����R���x�ADOrgErrStep)

	'===================================================================================================================
	'�y �����R���x�ADOrgErr���� �z
	else
	
		res(tim_notXSW51_�X�g�b�p�㏸�[)
		res(tim_notXSW52_�X�g�b�p���~�[)
		res(tim_notXSW37_�X�g�b�p�㏸�[)
		res(tim_notXSW36_�X�g�b�p���~�[)
		res(tim_notXSW53_���t�g�㏸�[)
		res(tim_notXSW54_���t�g���~�[)
		res(tim_notXSW34_���t�g�㏸�[)
		res(tim_notXSW35_���t�g���~�[)

		res(tim_XSW51_�X�g�b�p�㏸�[)
		res(tim_XSW52_�X�g�b�p���~�[)
		res(tim_XSW37_�X�g�b�p�㏸�[)
		res(tim_XSW36_�X�g�b�p���~�[)
		res(tim_XSW53_���t�g�㏸�[)
		res(tim_XSW54_���t�g���~�[)

		if ResetFlg then
			�����R���x�ADOrgErr=OFF
		end if

	end if

	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else

		�����R���x�ADErr=ON

		pauseMC34_���[�^���[��=ON
		pauseMC44_���[�^���[��=ON
		pauseMC46_���[�^���[��=ON

		select case �����R���x�ADErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW51_�X�g�b�p�㏸�[=OFF
				almXSW52_�X�g�b�p���~�[=OFF
				almXSW37_�X�g�b�p�㏸�[=OFF
				almXSW36_�X�g�b�p���~�[=OFF
				almXSW53_���t�g�㏸�[=OFF
				almXSW54_���t�g���~�[=OFF
				almXSW34_���t�g�㏸�[=OFF
				almXSW35_���t�g���~�[=OFF

				inc(�����R���x�ADErrStep)
			end if
		case 2
			�����R���x�ADErr=OFF

			res(tim_notXSW51_�X�g�b�p�㏸�[)
			res(tim_notXSW52_�X�g�b�p���~�[)
			res(tim_notXSW37_�X�g�b�p�㏸�[)
			res(tim_notXSW36_�X�g�b�p���~�[)
			res(tim_notXSW53_���t�g�㏸�[)
			res(tim_notXSW54_���t�g���~�[)
			res(tim_notXSW34_���t�g�㏸�[)
			res(tim_notXSW35_���t�g���~�[)

			res(tim_XSW51_�X�g�b�p�㏸�[)
			res(tim_XSW52_�X�g�b�p���~�[)
			res(tim_XSW37_�X�g�b�p�㏸�[)
			res(tim_XSW36_�X�g�b�p���~�[)
			res(tim_XSW53_���t�g�㏸�[)
			res(tim_XSW54_���t�g���~�[)
			res(tim_XSW34_���t�g�㏸�[)
			res(tim_XSW35_���t�g���~�[)

			pauseMC34_���[�^���[��=OFF
			pauseMC44_���[�^���[��=OFF
			pauseMC46_���[�^���[��=OFF
			

			�����R���x�ADErrStep=0
		end select

	end if 'if �����R���x�ADErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	select case �����R���x�ADEmgStep
	case 0
		
	case 1
		�����R���x�ADAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�����R���x�ADAutoMode and ��������AutoMode ) or �����R���x�ADstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseMC34_���[�^���[��=ON
			pauseMC44_���[�^���[��=ON
			pauseMC46_���[�^���[��=ON

			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				tim_MC44_���[�^���[��_stack=tim_MC44_���[�^���[��.U
				tim_SV43_���t�g_stack=tim_SV43_���t�g.U
				tim_SV29_�X�g�b�p_stack=tim_SV29_�X�g�b�p.U
				tim_MC46_���[�^���[��_stack=tim_MC46_���[�^���[��.U
				tim_MC34_���[�^���[��_stack=tim_MC34_���[�^���[��.U
				tim_SV42_�X�g�b�p_stack=tim_SV42_�X�g�b�p.U
				tim_SV28_���t�g_stack=tim_SV28_���t�g.U
			
				timdly_PH22_�����m_stack=timdly_PH22_�����m.U
				timdly_PH24_�����m_stack=timdly_PH24_�����m.U
				timstack=ON
			end if
			
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC34_���[�^���[��=OFF
			mMC44_���[�^���[��=OFF
			mMC46_���[�^���[��=OFF
		
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�����R���x�ADEmgStep)
	case 2
		if ResetFlg then
			inc(�����R���x�ADEmgStep)
		end if
	case 3
		if (�����R���x�ADAutoMode and ��������AutoMode ) or �����R���x�ADstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseMC34_���[�^���[��=OFF
				pauseMC44_���[�^���[��=OFF
				pauseMC46_���[�^���[��=OFF

				tim_procstep.U=tim_procstep_stack
				tim_MC44_���[�^���[��.U=tim_MC44_���[�^���[��_stack
				tim_SV43_���t�g.U=tim_SV43_���t�g_stack
				tim_SV29_�X�g�b�p.U=tim_SV29_�X�g�b�p_stack
				tim_MC46_���[�^���[��.U=tim_MC46_���[�^���[��_stack
				tim_MC34_���[�^���[��.U=tim_MC34_���[�^���[��_stack
				tim_SV42_�X�g�b�p.U=tim_SV42_�X�g�b�p_stack
				tim_SV28_���t�g.U=tim_SV28_���t�g_stack			

				res(timdly_PH22_�����m)
				res(timdly_PH24_�����m)
				'---------------------------------
				inc(�����R���x�ADEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�����R���x�ADEmgStep)		
		end if				
	case 4
		timstack=OFF
		�����R���x�ADEmgStep=0
		�����R���x�ADEmg=OFF
	end select
		
end if 'if �����R���x�ADEmgStep=0 then
