'�����R���x�AH
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	�����R���x�AH 
'
'-------------------------------------------------
'	[ 40 ]	�󂯓n�����t�g �R���x�AG -> �R���x�AH
'-------------------------------------------------
' 	PH53_�����m
'	PH54_�t�^���m
'
'	MC54_���[�^���[�� MC55_�������[�^
'					  MC10_�������[�^���](�t�]�j
'
'	SV50_���t�g		XSW67_���t�g�㏸�[
'					XSW68_���t�g���~�[
'	
'	SV49_�X�g�b�p	XSW65_�X�g�b�p�㏸�[
'					XSW66_�X�g�b�p���~�[
'
'-------------------------------------------------
'	[ 41 ]	���]�ق����@A
'-------------------------------------------------
' 	PH67_�����m
'
'	MC10_�������[�^���](�t�]�j MC55_�������[�^
'
'-------------------------------------------------
'	[ 42 ]	���]�ق����@A �ҋ@�ʒu
'-------------------------------------------------
' 	PH68_�����m
' 	PH69_�t�^���m
'
'-------------------------------------------------
'	[ 43 ]	���t�^���~���uA
'-------------------------------------------------
' 	PH55_�����m
'	PH56_�t�^���m
'
'	MC57_�������[�^
'
'	SV59_���t�g�㏸		XSW80_���t�g�㏸�[
'	SV76_���t�g���~		XSW81_���t�g���~�[
'
'	�����]�ق��������� : �ق����H��������A�܂��A�����R���x�AH�ɓr���ɑ��݂��銘
'
'
'===================================================================================================================
'�y ���������� �z
if CR2008 then '�d��ON������������
    �����R���x�AHAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �����R���x�AHAutoRun=OFF
    �����R���x�AH����=ON
    �����R���x�AHOrgErr=OFF
    �����R���x�AHErr=OFF
    �����R���x�AHEmg=OFF
    �����R���x�AHstep=0
    �����R���x�AHErrStep=0
    �����R���x�AHOrgErrStep=0
    �����R���x�AHEmgStep=0

	�t�^�r�ostep=0
	������step=0
	���r�ostep=0
	�������t�gstep=0
	
	if SSW3_�������[�h then	
		ManualInite=1
	else
		ManualInite=0	
	end if

end if
'===================================================================================================================
'�y ���_ �z
�����R���x�AHOrg=((XSW67_���t�g�㏸�[ and not(pnlPBXSW67_���t�g�㏸�[)) or passXSW67_���t�g�㏸�[) or ((XSW68_���t�g���~�[ and not(pnlPBXSW68_���t�g���~�[)) or passXSW68_���t�g���~�[)
�����R���x�AHOrg=�����R���x�AHOrg and (((XSW65_�X�g�b�p�㏸�[ and not(pnlPBXSW65_�X�g�b�p�㏸�[)) or passXSW65_�X�g�b�p�㏸�[) or ((XSW66_�X�g�b�p���~�[ and not(pnlPBXSW66_�X�g�b�p���~�[)) or passXSW66_�X�g�b�p���~�[))

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�����R���x�AHEmg=ON
	�����R���x�AHEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

tmr(SV50_���t�g and not(XSW67_���t�g�㏸�[) and not(pnlPBXSW67_���t�g�㏸�[), tim_notXSW67_���t�g�㏸�[, #40)
tmr(not(SV50_���t�g) and not(XSW68_���t�g���~�[) and not(pnlPBXSW68_���t�g���~�[),tim_notXSW68_���t�g���~�[, #40)
tmr(SV49_�X�g�b�p and not(XSW65_�X�g�b�p�㏸�[) and not(pnlPBXSW65_�X�g�b�p�㏸�[),tim_notXSW65_�X�g�b�p�㏸�[, #40)
tmr(not(SV49_�X�g�b�p) and not(XSW66_�X�g�b�p���~�[) and not(pnlPBXSW66_�X�g�b�p���~�[),tim_notXSW66_�X�g�b�p���~�[, #40)

'tmr(not(SV50_���t�g) and XSW67_���t�g�㏸�[ and not(pnlPBXSW67_���t�g�㏸�[), tim_XSW67_���t�g�㏸�[, #10)
if LDP(SV50_���t�g) and XSW67_���t�g�㏸�[ and not(pnlPBXSW67_���t�g�㏸�[) then
	SET(tim_XSW67_���t�g�㏸�[)
end if
'tmr(SV50_���t�g and XSW68_���t�g���~�[ and not(pnlPBXSW68_���t�g���~�[),tim_XSW68_���t�g���~�[, #10)
if LDF(SV50_���t�g) and XSW68_���t�g���~�[ and not(pnlPBXSW68_���t�g���~�[) and not(pauseSV50_���t�g) then
	SET(tim_XSW68_���t�g���~�[)
end if
'tmr(not(SV49_�X�g�b�p) and XSW65_�X�g�b�p�㏸�[ and not(pnlPBXSW65_�X�g�b�p�㏸�[),tim_XSW65_�X�g�b�p�㏸�[, #10)
if LDP(SV49_�X�g�b�p) and XSW65_�X�g�b�p�㏸�[ and not(pnlPBXSW65_�X�g�b�p�㏸�[) then
	SET(tim_XSW65_�X�g�b�p�㏸�[)
end if
'tmr(SV49_�X�g�b�p and XSW66_�X�g�b�p���~�[ and not(pnlPBXSW66_�X�g�b�p���~�[),tim_XSW66_�X�g�b�p���~�[, #10)
if LDF(SV49_�X�g�b�p) and XSW66_�X�g�b�p���~�[ and not(pnlPBXSW66_�X�g�b�p���~�[) and not(pauseSV49_�X�g�b�p) then
	SET(tim_XSW66_�X�g�b�p���~�[)
end if

'tms(SV50_���t�g,passtimXSW67_���t�g�㏸�[,passtimXSW67_���t�g�㏸�[_val)
'tms(not(SV50_���t�g),passtimXSW68_���t�g���~�[,passtimXSW68_���t�g���~�[_val)
'tms(SV49_�X�g�b�p,passtimXSW65_�X�g�b�p�㏸�[,passtimXSW65_�X�g�b�p�㏸�[_val)
'tms(not(SV49_�X�g�b�p),passtimXSW66_�X�g�b�p���~�[,passtimXSW66_�X�g�b�p���~�[_val)

if ldp(tim_XSW67_���t�g�㏸�[.B) or ldp(tim_notXSW67_���t�g�㏸�[.B) then
	errpassXSW67_���t�g�㏸�[=ON
	pauseSV50_���t�g=ON
	almXSW67_���t�g�㏸�[=ON
	pnlPBXSW67_���t�g�㏸�[=ON
	�����R���x�AHErrStep=1

else if ldp(tim_XSW68_���t�g���~�[.B) or ldp(tim_notXSW68_���t�g���~�[.B) then
	errpassXSW68_���t�g���~�[=ON
	almXSW68_���t�g���~�[=ON
	pnlPBXSW68_���t�g���~�[=ON
	�����R���x�AHErrStep=1

else if ldp(tim_XSW65_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW65_�X�g�b�p�㏸�[.B) then
	errpassXSW65_�X�g�b�p�㏸�[=ON
	pauseSV49_�X�g�b�p=ON
	almXSW65_�X�g�b�p�㏸�[=ON
	pnlPBXSW65_�X�g�b�p�㏸�[=ON
	�����R���x�AHErrStep=1

else if ldp(tim_XSW66_�X�g�b�p���~�[.B) or ldp(tim_notXSW66_�X�g�b�p���~�[.B) then
	errpassXSW66_�X�g�b�p���~�[=ON
	almXSW66_�X�g�b�p���~�[=ON
	pnlPBXSW66_�X�g�b�p���~�[=ON
	�����R���x�AHErrStep=1

end if

'MC55�̃R���x�A���犘�����E���Ă��鎞�Ԃ̌o��
'���E�����t�^�r�o�͉\�ł��B
tim_�ق����@A���j�b�g���쒆_setval=1800
tmr(�ق����@A���j�b�g���쒆 ,tim_�ق����@A���j�b�g���쒆,tim_�ق����@A���j�b�g���쒆_setval)
if PH67_�����m then
	res(tim_�ق����@A���j�b�g���쒆)
end if

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �����R���x�AHAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �����R���x�AHAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �����R���x�AHEmg	���̏��~


tmr(PH53_�����m,timdly_PH53_�����m,4)
tmr(PH54_�t�^���m,timdly_PH54_�t�^���m,4)

if �����R���x�AHEmgStep=0 then  
	
	if �����R���x�AHErrStep=0  then

	if not(�����R���x�AHOrgErr) then

	if (�����R���x�AHAutoMode and ��������AutoMode ) or �����R���x�AHstep<>0 then
	
		if not(�����R���x�AHAutoMode and ��������AutoMode ) then
			�����R���x�AHAutoRun=OFF
		end if
	
		if 	ManualInite=1 then
			mSV50_���t�g=ON
			ManualInite=0	
		end if 

		

	'-----------------------------------------------------------------
	' �������[�^�A�X�g�b�pON/OFF�^�C�~���O�^�X�N
	'-----------------------------------------------------------------
	' �y �t�^�r�o �z
	tmr(tim_�t�^�r�o,tim_�t�^�r�o_val)
	select case �t�^�r�ostep
	case 0

	case 1	
		if not(PH53_�����m) and PH54_�t�^���m then '���t�g�ʒu �t�^���m
			inc(�t�^�r�ostep)
		else
			�t�^�r�ostep=0 '[ ���t�g�ʒu ]�̊��t�^����
		end if

	case 2
		mSV50_���t�g=OFF
		errpassXSW68_���t�g���~�[=OFF
		mSV49_�X�g�b�p=OFF
		errpassXSW66_�X�g�b�p���~�[=OFF
		inc(�t�^�r�ostep)
	
	case 3
		if errpassXSW68_���t�g���~�[ or ((XSW68_���t�g���~�[ and not(pnlPBXSW68_���t�g���~�[)) or passXSW68_���t�g���~�[) then
			inc(�t�^�r�ostep)
		end if
		

	case 4
		if errpassXSW66_�X�g�b�p���~�[ or ((XSW66_�X�g�b�p���~�[ and not(pnlPBXSW66_�X�g�b�p���~�[)) or passXSW66_�X�g�b�p���~�[) then
			inc(�t�^�r�ostep)
		end if	
	
	case 5
		mMC10_�������[�^�t�]=ON
		ejectMC55_�������[�^=ON
		ejectMC57_�������[�^=ON
		inc(�t�^�r�ostep)

	case 6
		if not(PH53_�����m) and not(PH54_�t�^���m) then '�R���x�A���t�g�ʒu�̊��t�^�ړ����m
			inc(�t�^�r�ostep)
		end if

	case 7
		if not(PH68_�����m) and PH69_�t�^���m then
			inc(�t�^�r�ostep)
		end if

	case 8
		if not(extMC55_�������[�^) then
			�������t�gstep=1 '�������t�g�㏸ �� �����R���x�AG�N��
		end if
		inc(�t�^�r�ostep)
	
	case 9
		if PH55_�����m or PH56_�t�^���m then
			inc(�t�^�r�ostep)
		end if
	
	case 10
		tim_�t�^�r�o_val=15
		res(tim_�t�^�r�o)
		inc(�t�^�r�ostep)
	
	case 11
		if tim_�t�^�r�o.B then
			inc(�t�^�r�ostep)
		end if
	
	case 12
		mMC10_�������[�^�t�]=OFF
		ejectMC55_�������[�^=OFF
		ejectMC57_�������[�^=OFF
		inc(�t�^�r�ostep)
	
	case 13
		�����R���x�AH�r�o�v��=ON
		�t�^�r�ostep=0
	
	end select
		
	'-----------------------------------------------------------------
	' �y ������ �z
	tmr(tim_������,tim_������_val)
	select case ������step
	case 0
	
	case 1
		if not(���]�ق�����������A) and not(PH67_�����m) and PH53_�����m and PH54_�t�^���m then
			inc(������step)
		else
			������step=0
		end if

	case 2
		mSV50_���t�g=OFF
		errpassXSW68_���t�g���~�[=OFF
		inc(������step)
	
	case 3
		if errpassXSW68_���t�g���~�[ or ((XSW68_���t�g���~�[ and not(pnlPBXSW68_���t�g���~�[)) or passXSW68_���t�g���~�[) then
			inc(������step)
		end if
		
	case 4
		mSV49_�X�g�b�p=OFF
		errpassXSW66_�X�g�b�p���~�[=OFF
		inc(������step)

	case 5
		if errpassXSW66_�X�g�b�p���~�[ or ((XSW66_�X�g�b�p���~�[ and not(pnlPBXSW66_�X�g�b�p���~�[)) or passXSW66_�X�g�b�p���~�[) then
			inc(������step)
		end if	

	case 6
		mMC10_�������[�^���]=ON
		inc(������step)
	
	case 7
		if not(PH53_�����m) and not(PH54_�t�^���m) then
			inc(������step)
		end if
		
	case 8
		if PH67_�����m then
			inc(������step)
		end if
	
	case 9
		tim_������_val=15
		res(tim_������)
		inc(������step)
	
	case 10
		if tim_������.B then
			inc(������step)
		end if

	case 11
		StageDevice41=StageDevice40
		mMC10_�������[�^���]=OFF
		inc(������step)
	
	case 12
		�������t�gstep=1 '�������t�g�㏸ �� �����R���x�AG�N��
		���]�ق�����������A=ON
		������step=0
		
	end select

	'-----------------------------------------------------------------
	' �y ���r�o �z
	tmr(tim_���r�o,tim_���r�o_val)
	select case ���r�ostep
	case 0
	
	case 1	
		if �ق����@A���j�b�g���� and ���]�ق�����������A and PH67_�����m then '�ق���A�̊����m
			inc(���r�ostep)
		else
			���r�ostep=0 '�ق���A�̊����m �Ȃ�
		end if

	case 2
		mSV50_���t�g=OFF
		errpassXSW68_���t�g���~�[=OFF

		inc(���r�ostep)
	
	case 3
		if errpassXSW68_���t�g���~�[ or ((XSW68_���t�g���~�[ and not(pnlPBXSW68_���t�g���~�[)) or passXSW68_���t�g���~�[) then
			inc(���r�ostep)
		end if

	case 4
		mSV49_�X�g�b�p=OFF
		errpassXSW66_�X�g�b�p���~�[=OFF
		inc(���r�ostep)


	case 5
		if errpassXSW66_�X�g�b�p���~�[ or ((XSW66_�X�g�b�p���~�[ and not(pnlPBXSW66_�X�g�b�p���~�[)) or passXSW66_�X�g�b�p���~�[) then
			inc(���r�ostep)
		end if	

	case 6
		ejectMC10_�������[�^�t�]=ON
		extMC55_�������[�^=ON 'eject2
		inc(���r�ostep)
		
	case 7
		if not(PH67_�����m) then
			inc(���r�ostep)
		end if

	case 8
		if PH68_�����m then '���t�^���~���uA �ҋ@�ʒu �����m
			inc(���r�ostep)
		end if
	
	case 9
		�������t�gstep=1 '�������t�g�㏸ �� �����R���x�AG�N��
		
		ejectMC10_�������[�^�t�]=OFF
		extMC55_�������[�^=OFF
		inc(���r�ostep)

	case 10
		if �������t�gstep=0 then
			inc(���r�ostep)
		end if

	case 11
		�����R���x�AH�r�o�v��=ON '���t�^���~���uA �N��
		�ق����@A���j�b�g�r�o�v��=OFF
		���]�ق�����������A=OFF
		�ق����@A���j�b�g����=OFF
		���r�ostep=0

	end select
	
	'-----------------------------------------------------------------
	'
	' �������t�g�㏸
	' 	'
	tmr(tim_�������t�g,tim_�������t�g_val)
	select case �������t�gstep
	case 0
	case 1
		if not(PH53_�����m) or not(PH54_�t�^���m) then
			inc(�������t�gstep) 
		else				
			�������t�gstep=0
		end if

	case 2
		mSV50_���t�g=ON
		errpassXSW67_���t�g�㏸�[=OFF
		mSV49_�X�g�b�p=ON
		errpassXSW65_�X�g�b�p�㏸�[=OFF
		inc(�������t�gstep) 
	
	case 3
		if (errpassXSW67_���t�g�㏸�[ or ((XSW67_���t�g�㏸�[ and not(pnlPBXSW67_���t�g�㏸�[)) or passXSW67_���t�g�㏸�[)) and (errpassXSW65_�X�g�b�p�㏸�[ or ((XSW65_�X�g�b�p�㏸�[ and not(pnlPBXSW65_�X�g�b�p�㏸�[)) or passXSW65_�X�g�b�p�㏸�[)) then
			inc(�������t�gstep)		
		end if

	case 4
		�����R���x�AH���쒆=OFF
'		�����R���x�AG�r�o�v��=OFF '�����R���x�AG�N��
		�������t�gstep=0

	end select
	'-----------------------------------------------------------------
	'
	' ���֎~����
	' 	'
	tmr(tim_���֎~����,tim_���֎~����_val)
	select case ���֎~����step
	case 0
	case 1
		if �����R���x�AHAutoRun then
			if (not(PH53_�����m) and PH54_�t�^���m) or PH67_�����m then '���t�g�ʒu �t�^���m
				���֎~����step=1
			else if �ق����@A���j�b�g���� and ���]�ق�����������A and PH67_�����m then
				inc(���֎~����step)
			else if  not(PH54_�t�^���m) and not(PH67_�����m) then
				���֎~����step=10
			end if
		else
			���֎~����step=0		
		end if
		
	case 2
		if  not(PH54_�t�^���m) and not(PH67_�����m) then
			���֎~����step=10
		end if

	case 10
		'�t�^�r�o�̏I���H��
		'�����R���x�AH�r�o�v��=ON '���t�^���~���uA �N��
		�ق����@A���j�b�g�r�o�v��=OFF
		���]�ق�����������A=OFF
		�ق����@A���j�b�g����=OFF

		�����R���x�AG�r�o�v��=OFF

		���֎~����step=0
		
	end select
	'-----------------------------------------------------------------

	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
		if ManualInite=1 then
			mSV50_���t�g=ON
			mSV49_�X�g�b�p=ON
			ManualInite=0
		end if

		tmr(tim_procstep,tim_procstep_val)

		select case �����R���x�AHstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �����R���x�AHAutoRun then
				inc(�����R���x�AHstep)
			else 
				�����R���x�AHstep=0 '�I���ҋ@
			end if
		
		case 2
			if PH68_�����m or PH69_�t�^���m then
				�����R���x�AH�r�o�v��=ON
			end if
				
			inc(�����R���x�AHstep)		

		case 3
			if �����R���x�AH�r�o�v��=OFF  and (�ق����@A���j�b�g�r�o�v�� or �����R���x�AG�r�o�v��) then '�N���g���K
				inc(�����R���x�AHstep)
			else if not(���]�ق�����������A) and �����R���x�AG�r�o�v�� and PH53_�����m and PH54_�t�^���m then
					�����R���x�AHstep=300
			else
				�����R���x�AH���쒆=OFF
				�����R���x�AHstep=1
			end if
		
		case 4  '���_���o
			if  �����R���x�AHOrg then
				inc(�����R���x�AHstep)
			else
				�����R���x�AHstep=1
			end if
		
		case 5
'			if not(SV50_���t�g) and not(timdly_PH53_�����m.B) and not(timdly_PH54_�t�^���m.B) then
'				mSV50_���t�g=ON
'				errpassXSW67_���t�g�㏸�[=OFF
'			end if
			errpassXSW67_���t�g�㏸�[=OFF
			inc(�����R���x�AHstep)
		
		case 6
			if mSV50_���t�g then
				if errpassXSW67_���t�g�㏸�[ or ((XSW67_���t�g�㏸�[ and not(pnlPBXSW67_���t�g�㏸�[)) or passXSW67_���t�g�㏸�[) then
					inc(�����R���x�AHstep)
				end if
			else
				inc(�����R���x�AHstep)
			end if
				
		case 7
			�����R���x�AHstep=100
		'--------------------------------------------------------------------------------------------------------------
		case 100
			
			if not(���]�ق�����������A) and timdly_PH53_�����m.B and timdly_PH54_�t�^���m.B then '���t�g��=��
			'���ق���A������					
				�R���x�AH���r�o�ҋ@=ON
				�����R���x�AHstep=300
				
			else if not(timdly_PH53_�����m.B) and timdly_PH54_�t�^���m.B then '���t�g��=�t�^
			'���t�^
				if ���]�ق�����������A then
					if �ق����@A���j�b�g�r�o�v�� and �ق����@A���j�b�g���� then '�ق���A�����҂�
						if not(mSV59_���t�g�㏸) and ((XSW81_���t�g���~�[ and not(pnlPBXSW81_���t�g���~�[)) or passXSW81_���t�g���~�[) and not(PH55_�����m) and not(PH56_�t�^���m) then '���~���t�g���~�[
							if not(PH68_�����m) and not(PH69_�t�^���m) then '���]�ق����ҋ@�ʒu�Ƀt�^���Ȃ�
								�����R���x�AHstep=500 '�t�^, �ق����@���r�o
							else 
								�����R���x�AHstep=1
							end if
						else
							�����R���x�AHstep=1
						end if
					else
						�����R���x�AHstep=1
					end if
				else
					�����R���x�AHstep=400 '�t�^�̂�
				end if
				
			else if not(timdly_PH53_�����m.B) and not(timdly_PH54_�t�^���m.B) then  '���t�g��=�����Ȃ�
			'���ق���A���r�o
'				if ���]�ق�����������A then
'					if not(�R���x�AH���r�o�ҋ@) and  ���]�ق�����������A and �ق����@A���j�b�g�r�o�v�� and �ق����@A���j�b�g���� then
'						�����R���x�AHstep=200
'					else 
'						�����R���x�AHstep=1
'					end if					
'				else
			'���������t�g�ɕ����Ȃ�
				�����R���x�AG�r�o�v��=OFF
				�����R���x�AHstep=1
'				end if
			else
				�����R���x�AHstep=1
				
			end if
		'--------------------------------------------------------------------------------------------------------------
		'���ق���A���r�o
		
		case 200 
				�����R���x�AH���쒆=ON
				���r�ostep=1
				inc(�����R���x�AHstep)
		case 201
				if ���r�ostep=0 then 
					inc(�����R���x�AHstep)
				end if
		case 202
				�����R���x�AG�r�o�v��=OFF

				���]�ق�����������A=OFF
				�ق����@A���j�b�g�r�o�v��=OFF				
				�ق����@A���j�b�g����=OFF
				�����R���x�AH���쒆=OFF
				�����R���x�AHstep=1
				
		'--------------------------------------------------------------------------------------------------------------
		'���ق���A������
		case 300 
				�����R���x�AH���쒆=ON
				������step=1
				inc(�����R���x�AHstep)

		case 301
				if ������step=0 then
					inc(�����R���x�AHstep)
				end if
			
		case 302
				�����R���x�AG�r�o�v��=OFF
				���]�ق�����������A=ON
				�����R���x�AH���쒆=OFF
				�����R���x�AHstep=1
		'--------------------------------------------------------------------------------------------------------------
		'���t�^
		case 400 

				�t�^������=not(PH53_�����m) and  PH54_�t�^���m
				�t�^�r�ostep=1
				
				�����R���x�AH���쒆=ON
				inc(�����R���x�AHstep)
		case 401
			if �t�^�r�ostep=0 then
				inc(�����R���x�AHstep)
			end if
				
		case 402		
				�����R���x�AG�r�o�v��=OFF
				�����R���x�AH���쒆=OFF
				�����R���x�AHstep=1
		'--------------------------------------------------------------------------------------------------------------
		'���t�^ , �ق������r�o 
		case 500
			if ���֎~ then
				���֎~����step=1		
				inc(�����R���x�AHstep)
			else
				
				�t�^������=not(PH53_�����m) and  PH54_�t�^���m
				�t�^�r�ostep=1
				���r�ostep=1
				
				�����R���x�AH���쒆=ON
				inc(�����R���x�AHstep)
			end if

		case 501
			if �t�^�r�ostep=0 then
				inc(�����R���x�AHstep)
			end if
			
		case 502
			if ���r�ostep=0 then
				inc(�����R���x�AHstep)
			end if
		
		case 503
			if ���֎~ then
				if ���֎~����step=0 then
					inc(�����R���x�AHstep)			
				end if
			else
				inc(�����R���x�AHstep)		
			end if
			
		case 504
				�����R���x�AG�r�o�v��=OFF
				�����R���x�AH���쒆=OFF
				�����R���x�AHstep=1
		'--------------------------------------------------------------------------------------------------------------
		end select
	
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		�����R���x�AHAutoRun=OFF
		
		�����R���x�AHstep=0 '�I��
		
		if ldp(pnlPBMC10_�������[�^���])  then
			if mMC10_�������[�^���] then
				mMC10_�������[�^���]=OFF
			else if ((XSW68_���t�g���~�[ and not(pnlPBXSW68_���t�g���~�[)) or passXSW68_���t�g���~�[) and not(pnlPBMC10_�������[�^�t�]) and not(mMC10_�������[�^�t�]) then
				mMC10_�������[�^���]=ON
			end if
		end if
		if ldp(pnlPBMC10_�������[�^�t�]) then
			if mMC10_�������[�^�t�] then
				mMC10_�������[�^�t�]=OFF
			else if ((XSW68_���t�g���~�[ and not(pnlPBXSW68_���t�g���~�[)) or passXSW68_���t�g���~�[) and not(pnlPBMC10_�������[�^���]) and not(mMC10_�������[�^���]) then
				mMC10_�������[�^�t�]=ON
			end if
		end if
		
		if ldp(pnlPBMC55_�������[�^) then
			if mMC55_�������[�^ then
				mMC55_�������[�^=OFF
			else if ((XSW68_���t�g���~�[ and not(pnlPBXSW68_���t�g���~�[)) or passXSW68_���t�g���~�[)  then
				mMC55_�������[�^=ON
			end if
		end if
			
	end if '�����R���x�AHAutoMode and not(�����R���x�AHOrgErrStep)

	'===================================================================================================================
	'�y �����R���x�AHOrgErr���� �z
	else
	

		if ResetFlg then
			�����R���x�AHOrgErr=OFF
		end if


	end if

	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else

		�����R���x�AHErr=ON

		pauseMC10_�������[�^���]=ON
		pauseMC10_�������[�^�t�]=ON
		pauseMC55_�������[�^=ON
		pauseMC57_�������[�^=ON

		select case �����R���x�AHErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW67_���t�g�㏸�[=OFF
				almXSW68_���t�g���~�[=OFF
				almXSW65_�X�g�b�p�㏸�[=OFF
				almXSW66_�X�g�b�p���~�[=OFF

				inc(�����R���x�AHErrStep)
			end if
		case 2
			res(tim_XSW67_���t�g�㏸�[)
			res(tim_XSW68_���t�g���~�[)
			res(tim_XSW65_�X�g�b�p�㏸�[)
			res(tim_XSW66_�X�g�b�p���~�[)
			res(tim_notXSW67_���t�g�㏸�[)
			res(tim_notXSW68_���t�g���~�[)
			res(tim_notXSW65_�X�g�b�p�㏸�[)
			res(tim_notXSW66_�X�g�b�p���~�[)

			pauseMC10_�������[�^���]=OFF
			pauseMC10_�������[�^�t�]=OFF
			pauseMC55_�������[�^=OFF
			pauseMC57_�������[�^=OFF

			pauseSV50_���t�g=OFF
			pauseSV49_�X�g�b�p=OFF

			�����R���x�AHErr=OFF
			�����R���x�AHErrStep=0

		end select

	end if 'if �����R���x�AHErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	select case �����R���x�AHEmgStep
	case 0
		
	case 1
		�����R���x�AHAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�����R���x�AHAutoMode and ��������AutoMode ) or �����R���x�AHstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseMC10_�������[�^���]=ON
			pauseMC10_�������[�^�t�]=ON
			pauseMC55_�������[�^=ON
			pauseMC57_�������[�^=ON

			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				timdly_PH36_�����m_stack=timdly_PH36_�����m.U
				timdly_PH37_�t�^���m_stack=timdly_PH37_�t�^���m.U
				timdly_PH53_�����m_stack=timdly_PH53_�����m.U
				timdly_PH54_�t�^���m_stack=timdly_PH54_�t�^���m.U
				tim_MC55_�������[�^_stack=tim_MC55_�������[�^.U
				tim_�t�^�r�o_stack=tim_�t�^�r�o.U
				tim_�ق����@A���j�b�g���쒆_stack=tim_�ق����@A���j�b�g���쒆.U
				tim_������_stack=tim_������.U
				tim_���r�o_stack=tim_���r�o.U
				tim_�������t�g_stack=tim_�������t�g.U

				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC10_�������[�^���]=OFF
			mMC10_�������[�^�t�]=OFF
			mMC55_�������[�^=OFF
			mMC57_�������[�^=OFF
			
			mSV50_���t�g=OFF
			mSV49_�X�g�b�p=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�����R���x�AHEmgStep)
	case 2
		if ResetFlg then
			inc(�����R���x�AHEmgStep)
		end if
	case 3
		if (�����R���x�AHAutoMode and ��������AutoMode ) or �����R���x�AHstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseMC10_�������[�^���]=OFF
				pauseMC10_�������[�^�t�]=OFF
				pauseMC55_�������[�^=OFF
				pauseMC57_�������[�^=OFF

				tim_procstep.U=tim_procstep_stack
				timdly_PH36_�����m.U=timdly_PH36_�����m_stack
				timdly_PH37_�t�^���m.U=timdly_PH37_�t�^���m_stack
				timdly_PH53_�����m.U=timdly_PH53_�����m_stack
				timdly_PH54_�t�^���m.U=timdly_PH54_�t�^���m_stack
				tim_MC55_�������[�^.U=tim_MC55_�������[�^_stack
				tim_�t�^�r�o.U=tim_�t�^�r�o_stack
				tim_�ق����@A���j�b�g���쒆_stack=tim_�ق����@A���j�b�g���쒆.U
				tim_������.U=tim_������_stack
				tim_���r�o.U=tim_���r�o_stack
				tim_�������t�g.U=tim_�������t�g_stack

				'---------------------------------
				inc(�����R���x�AHEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			'---------------------------------
			inc(�����R���x�AHEmgStep)		
		end if				
	case 4
		timstack=OFF
		�����R���x�AHEmgStep=0
		�����R���x�AHEmg=OFF
	end select
		
end if 'if �����R���x�AHEmgStep=0 then
