'�����]�o��
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	�����]�o��
'
' PH7_�����m	-> PH63_�����m
' PH8_�t�^���m	-> PH64_�t�^���m
' PH9_�����m	-> PH65_�����m
' PH10_�t�^���m	-> PH66_�t�^���m
' MC10_���]���[�^���]	-> MC37_���]���[�^���]
' MC10_���]���[�^�t�]	-> MC37_���]���[�^�t�]
' (LS5_�󊘔��]���_�ʒu) -> (LS5_�󊘔��]���_�ʒu)
' (LS6_�󊘔��]���]�ʒu) -> (LS6_�󊘔��]���]�ʒu)
' MC32_�������[�^	-> MC38_�������[�^
'
' 
'===================================================================================================================

'�y ���������� �z
if CR2008 then '�d��ON������������
    �����]�o��AutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �����]�o��AutoRun=OFF
    �����]�o������=ON
    �����]�o��OrgErr=OFF
    �����]�o��Err=OFF
    �����]�o��Emg=OFF
    �����]�o��step=0
    �����]�o��ErrStep=0
    �����]�o��OrgErrStep=0
    �����]�o��EmgStep=0
	
	MC37_���]���[�^���]step=0
	MC37_���]���[�^�t�]step=0
	
end if
'===================================================================================================================
'�y ���_ �z
�����]�o��Org=LS5_�󊘔��]���_�ʒu

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�����]�o��Emg=ON
	�����]�o��EmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

tmr(MC37_���]���[�^���] and not(LS6_�󊘔��]���]�ʒu) and not(pnlPBLS6_�󊘔��]���]�ʒu),tim_LS6_�󊘔��]���]�ʒu,#50)
tmr(MC37_���]���[�^�t�] and not(LS5_�󊘔��]���_�ʒu) and not(pnlPBLS5_�󊘔��]���_�ʒu),tim_LS5_�󊘔��]���_�ʒu,#50)

if LS5_�󊘔��]���_�ʒu and LS6_�󊘔��]���]�ʒu then
	mMC37_���]���[�^���]=OFF
	mMC37_���]���[�^�t�]=OFF
	almLS6_�󊘔��]���]�ʒu=ON
	almLS5_�󊘔��]���_�ʒu=ON
	�����]�o��ErrStep=1

else if ldp(tim_LS6_�󊘔��]���]�ʒu.B) then
	mMC37_���]���[�^���]=OFF
	errpassLS6_�󊘔��]���]�ʒu=ON	
	almLS6_�󊘔��]���]�ʒu=ON
	
	�����]�o��ErrStep=1
else if ldp(tim_LS5_�󊘔��]���_�ʒu.B) then
	mMC37_���]���[�^�t�]=OFF
	errpassLS5_�󊘔��]���_�ʒu=ON
	almLS5_�󊘔��]���_�ʒu=ON
	�����]�o��ErrStep=1
end if

tmr(PH63_�����m,timdly_PH63_�����m,5)
tmr(PH64_�t�^���m,timdly_PH64_�t�^���m,5)

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �����]�o��AutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �����]�o��AutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �����]�o��Emg	���̏��~


if not(�����]�o��Emg) then  
	
	if �����]�o��ErrStep=0  then

	if not(�����]�o��OrgErr) then

	'------------------------------------------------------------------------------------------------
	'MC37_���]���[�^���]  �i���~���u->���@���j
	tmr(tim_MC37_���]���[�^���],tim_MC37_���]���[�^���]_val)
	
	select case MC37_���]���[�^���]step
	
	case 0
	
	case 1
		mMC37_���]���[�^���]=ON
		errpassLS6_�󊘔��]���]�ʒu=OFF
		inc(MC37_���]���[�^���]step)

	case 2
		if LS6_�󊘔��]���]�ʒu or errpassLS6_�󊘔��]���]�ʒu then
			inc(MC37_���]���[�^���]step)
		end if
		
	case 3
		mMC37_���]���[�^���]=OFF
		inc(MC37_���]���[�^���]step)

	case 4		
		MC37_���]���[�^���]step=0

	end select
	'------------------------------------------------------------------------------------------------
	'MC37_���]���[�^�t�] (���@�� -> ���~�@���j
	tmr(tim_MC37_���]���[�^�t�],tim_MC37_���]���[�^�t�]_val)
	
	select case MC37_���]���[�^�t�]step
	
	case 0
	
	case 1
		mMC37_���]���[�^�t�]=ON
		errpassLS5_�󊘔��]���_�ʒu=OFF
		inc(MC37_���]���[�^�t�]step)

	case 2
		if LS5_�󊘔��]���_�ʒu or errpassLS5_�󊘔��]���_�ʒu then
			inc(MC37_���]���[�^�t�]step)
		end if
	
	case 3
		mMC37_���]���[�^�t�]=OFF
		inc(MC37_���]���[�^�t�]step)
		
	case 4
		MC37_���]���[�^�t�]step=0

	end select

	'------------------------------------------------------------------------------------------------
	if (�����]�o��AutoMode and ��������AutoMode ) or �����]�o��step<>0 then
	
		if not(�����]�o��AutoMode and ��������AutoMode ) then
			�����]�o��AutoRun=OFF
		end if


	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case �����]�o��step
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �����]�o��AutoRun then
				inc(�����]�o��step)
			else 
				�����]�o��step=0 '�I���ҋ@
			end if
	
		case 2				
			if �����]�o��Org then
				inc(�����]�o��step)
			else
				�����]�o��step=1
			end if

		case 3
			if PH65_�����m or PH66_�t�^���m  then '���t�g��O�ʒu�̃��[�N
				�����]�o�����쒆=OFF
				�����]�o���r�o�v��=ON
				�����]�o��step=1
			else
				inc(�����]�o��step)
			end if

		case 4
			if �����]�o���r�o�v��=OFF and  ���R���x�A�������쒆=OFF and ���R���x�A�����r�o�v�� then
				inc(�����]�o��step)
			else
				�����]�o��step=1
			end if

		case 5
			�����]�o��step=100
		
		'--------------------------------------------------------------------------------------------------------------
		'�����]�@�N��
		case 100 'mINV3�Ŕ������ꂽ���t�^�m�F
			�����]�o�����쒆=ON
			tim_procstep_val=20
			res(tim_procstep)
			
			res(timdly_PH63_�����m)
			res(timdly_PH64_�t�^���m)
			
			inc(�����]�o��step) 
		
		case 101
			if tim_procstep.B then
				inc(�����]�o��step) 
			end if
		
		case 102

		if 1 then
			if timdly_PH63_�����m.B and timdly_PH64_�t�^���m.B then
				'���]�@ ���] LS5 -> LS6
				��������=ON
				�����]�o��step=200
			
			else if not(timdly_PH63_�����m.B) and timdly_PH64_�t�^���m.B then
				'���]�@ �t�] LS6 -> LS5
				��������=OFF
				�����]�o��step=250
			
			else if not(timdly_PH63_�����m.B) and not(timdly_PH64_�t�^���m.B) then
				'�������Ȃ��ŏI��
				��������=OFF
				���R���x�A�����r�o�v��=OFF
				�����]�o�����쒆=OFF
				�����]�o��step=1
			
			end if
		end if
		
		if 0 then
			if StageDevice50=$80 then '�����o
				'���]�@ ���] LS5 -> LS6
				��������=ON
				�����]�o��step=200
			
			else if StageDevice50=$40 then '�t�^���o
				'���]�@ �t�] LS6 -> LS5
				��������=OFF
				�����]�o��step=250
			
			else if StageDevice50=0 then '�����Ȃ�
				'�������Ȃ��ŏI��
				��������=OFF
				���R���x�A�����r�o�v��=OFF
				�����]�o�����쒆=OFF
				�����]�o��step=1
			
			end if
		end if
		'--------------------------------------------------------
		'������
		case 200
			MC37_���]���[�^���]step=1
			inc(�����]�o��step)
				
		case 201
			if MC37_���]���[�^���]step=0 then
				inc(�����]�o��step)
			end if
		
		case 202
			setS05c3=3500
			mINV3_�R���x�A���[�^���]=ON
			tim_procstep_val=INV3���}������ '1���@(47) 2���@(45)
			res(tim_procstep)
			inc(�����]�o��step)
		
		case 203
			if tim_procstep.B then
				inc(�����]�o��step)
			end if		

		case 204
			if not(PH63_�����m) and not(PH64_�t�^���m) then
				mINV3_�R���x�A���[�^���]=OFF
				inc(�����]�o��step)
			end if

		case 205
			inc(�����]�o��step)

		case 206
			MC37_���]���[�^�t�]step=1
			inc(�����]�o��step)
		
		case 207

			���R���x�A�����r�o�v��=OFF
			�����]�o�����쒆=OFF
			inc(�����]�o��step)

		case 208
			if MC37_���]���[�^�t�]step=0 then
				'if PH65_�����m then
				'	StageDevice50=0
				'	StageDevice51=$8000+$100 '<- StageDevice  [ ��  �n�̃f�[�^���ꍞ�ݽ��Ēn�_
				'else
				'	StageDevice50=0
				'	StageDevice51=0 '<- StageDevice  [ ��  �n�̃f�[�^���ꍞ�ݽ��Ēn�_
				'end if
				�����]�o���r�o�v��=ON
				�����]�o�����쒆=OFF

				�����]�o��step=1
			end if
					

		'----------------------------------------------------------------------
		'�t�^����
		case 250
			MC37_���]���[�^�t�]step=1
			inc(�����]�o��step)
		
		case 251
			if MC37_���]���[�^�t�]step=0 then
				inc(�����]�o��step)
			end if		
		
		case 252
			setS05c3=4500
			mINV3_�R���x�A���[�^���]=ON
			ejectMC38_�������[�^=ON
			inc(�����]�o��step)
			
		case 253
			if not(PH63_�����m) and not(PH64_�t�^���m)  then
				res(tim���t�^���m�Ď�)
				inc(�����]�o��step)
			end if

		case 254
			tmr(tim���t�^���m�Ď�,100)
			if PH65_�����m or PH66_�t�^���m or tim���t�^���m�Ď�.B then
				inc(�����]�o��step)
			end if

		case 255
			mINV3_�R���x�A���[�^���]=OFF
			ejectMC38_�������[�^=OFF
			inc(�����]�o��step)
			
		case 256
			StageDevice50=0
			StageDevice51=0              '<- StageDevice [ �t�^  �n�̃f�[�^���ꍞ�ݽ��Ēn�_
			�����]�o���r�o�v��=ON
			���R���x�A�����r�o�v��=OFF
			�����]�o�����쒆=OFF
			�����]�o��step=1
		end select
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		�����]�o��AutoRun=OFF
		
		�����]�o��step=0 '�I��
	
		res(tim_LS6_�󊘔��]���]�ʒu)
		res(tim_LS5_�󊘔��]���_�ʒu)
		
		if ldp(pnlPBINV3_�R���x�A���[�^���]) then
			if mINV3_�R���x�A���[�^���] then
				mINV3_�R���x�A���[�^���]=OFF
			else
				mINV3_�R���x�A���[�^���]=ON
			end if
		end if
		
		if ldp(pnlPBMC38_�������[�^) then
			if ejectMC38_�������[�^ then
				ejectMC38_�������[�^=OFF
			else
				ejectMC38_�������[�^=ON
			end if
		end if
		
		
		if ldp(pnlPBMC37_���]���[�^���] or pnlPBMC37_���]���[�^�t�]) then
			if ldp(pnlPBMC37_���]���[�^���]) or LS5_�󊘔��]���_�ʒu then
				if not(mMC37_���]���[�^�t�]) and not(PH63_�����m) and not(PH64_�t�^���m) then
					mMC37_���]���[�^���]=ON
					mMC37_���]���[�^�t�]=OFF
				end if
			else if ldp(pnlPBMC37_���]���[�^�t�]) or LS6_�󊘔��]���]�ʒu then
				if not(mMC37_���]���[�^���]) then
					mMC37_���]���[�^���]=OFF
					mMC37_���]���[�^�t�]=ON
				end if
			else
					mMC37_���]���[�^���]=OFF
					mMC37_���]���[�^�t�]=ON
			end if
		end if
		if mMC37_���]���[�^���] and LS6_�󊘔��]���]�ʒu then
			mMC37_���]���[�^���]=OFF
		end if
		if mMC37_���]���[�^�t�] and LS5_�󊘔��]���_�ʒu then
			mMC37_���]���[�^�t�]=OFF
		end if


	end if '�����]�o��AutoMode and not(�����]�o��OrgErrStep)

	'===================================================================================================================
	'�y �����]�o��OrgErr���� �z
	else

		res(tim_LS6_�󊘔��]���]�ʒu)
		res(tim_LS5_�󊘔��]���_�ʒu)

		if ResetFlg then
			�����]�o��OrgErr=OFF
		end if		

	end if

	'===================================================================================================================
	'�y�^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
		res(tim_LS6_�󊘔��]���]�ʒu)
		res(tim_LS5_�󊘔��]���_�ʒu)

		�����]�o��Err=ON

		�����]�o��AutoRun=OFF
		
		�����]�o��step=0
		MC37_���]���[�^���]step=0
		MC37_���]���[�^�t�]step=0

		mINV3_�R���x�A���[�^���]=OFF
		
		tmr(tim_�����]�o��ErrStep,tim_�����]�o��ErrStep_val)
		
		select case �����]�o��ErrStep
		case 0
		
		case 1
			if ResetFlg then
				inc(�����]�o��ErrStep)
			end if
			
		case 2
			almLS6_�󊘔��]���]�ʒu=OFF
			almLS5_�󊘔��]���_�ʒu=OFF
			inc(�����]�o��ErrStep) 
			
		case 3
			�����]�o��Err=OFF
			�����]�o��ErrStep=0
		end select

	end if 'if �����]�o��ErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	select case �����]�o��EmgStep
	case 0
	
	case 1
		�����]�o��AutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�����]�o��AutoMode and ��������AutoMode ) or �����]�o��step<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseMC37_���]���[�^�t�]=ON
			pauseMC37_���]���[�^���]=ON
			pauseMC38_�������[�^=ON
			pauseINV3_�R���x�A���[�^���]=ON
		
			if timstack=OFF then
				timdly_PH63_�����m_stack=timdly_PH63_�����m.U
				timdly_PH64_�t�^���m_stack=timdly_PH64_�t�^���m.U
				tim���t�^���m�Ď�_stack=tim���t�^���m�Ď�.U
				tim_procstep_stack=tim_procstep.U
				tim_INV3_�R���x�A���[�^���]_stack=tim_INV3_�R���x�A���[�^���].U
				tim_MC37_���]���[�^�t�]_stack=tim_MC37_���]���[�^�t�].U
				tim_MC37_���]���[�^���]_stack=tim_MC37_���]���[�^���].U
				tim_�����]�o��ErrStep_stack=tim_�����]�o��ErrStep.U
			
				timstack=ON
			end if

			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC37_���]���[�^�t�]=OFF
			mMC37_���]���[�^���]=OFF
			mMC38_�������[�^=OFF
			ejectMC38_�������[�^=OFF
			mINV3_�R���x�A���[�^���]=OFF
		
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�����]�o��EmgStep)
	case 2
		if ResetFlg then
			inc(�����]�o��EmgStep)
		end if
	case 3
		if (�����]�o��AutoMode and ��������AutoMode ) or �����]�o��step<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseMC37_���]���[�^�t�]=OFF
				pauseMC37_���]���[�^���]=OFF
				pauseMC38_�������[�^=OFF
				pauseINV3_�R���x�A���[�^���]=OFF

				tim���t�^���m�Ď�.U=tim���t�^���m�Ď�_stack
				tim_procstep.U=tim_procstep_stack
				tim_INV3_�R���x�A���[�^���].U=tim_INV3_�R���x�A���[�^���]_stack
				tim_MC37_���]���[�^�t�].U=tim_MC37_���]���[�^�t�]_stack
				tim_MC37_���]���[�^���].U=tim_MC37_���]���[�^���]_stack
				tim_�����]�o��ErrStep.U=tim_�����]�o��ErrStep_stack
				
				res(timdly_PH63_�����m)
				res(timdly_PH64_�t�^���m)
				'---------------------------------
				inc(�����]�o��EmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�����]�o��EmgStep)		
		end if				
	case 4
		timstack=OFF
		�����]�o��EmgStep=0
		�����]�o��Emg=OFF
	end select
		
end if 'if �����]�o��EmgStep=0 then
