'�����]����
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	�����]����
'
' PH43_�����m -> PH57_�����m
' PH44_�t�^���m -> PH58_�t�^���m
' PH45_�����m -> PH59_�����m
' PH46_�t�^���m -> PH62__�t�^���m
'===================================================================================================================

'�y ���������� �z
if CR2008 then '�d��ON������������
    �����]����AutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �����]����AutoRun=OFF
    �����]��������=ON
    �����]����OrgErr=OFF
    �����]����Err=OFF
    �����]����Emg=OFF
    �����]����step=0
    �����]����ErrStep=0
    �����]����OrgErrStep=0
    �����]����EmgStep=0
	
	MC36_���]���[�^���]step=0
	MC36_���]���[�^�t�]step=0
	MC35_�������[�^step=0
	INV1_�R���x�A���[�^���]step=0

end if
'===================================================================================================================
'�y ���_ �z
�����]����Org=LS7_�����]�@���_�ʒu

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�����]����Emg=ON
	�����]����EmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

tmr(MC36_���]���[�^���] and not(LS8_�����]�@���]�ʒu) and not(pnlPBLS8_�����]�@���]�ʒu),tim_LS8_�����]�@���]�ʒu,#50)
tmr(MC36_���]���[�^�t�] and not(LS7_�����]�@���_�ʒu) and not(pnlPBLS7_�����]�@���_�ʒu),tim_LS7_�����]�@���_�ʒu,#50)

if LS7_�����]�@���_�ʒu and LS8_�����]�@���]�ʒu then
	mMC36_���]���[�^���]=OFF
	mMC36_���]���[�^�t�]=OFF
	almLS8_�����]�@���]�ʒu=ON
	almLS7_�����]�@���_�ʒu=ON
	�����]����ErrStep=1

else if ldp(tim_LS8_�����]�@���]�ʒu.B) then
	mMC36_���]���[�^���]=OFF
	almLS8_�����]�@���]�ʒu=ON
	errpassLS8_�����]�@���]�ʒu=ON
	�����]����ErrStep=1
else if ldp(tim_LS7_�����]�@���_�ʒu.B) then
	mMC36_���]���[�^�t�]=OFF
	almLS7_�����]�@���_�ʒu=ON
	errpassLS7_�����]�@���_�ʒu=ON
	�����]����ErrStep=1
end if

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �����]����AutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �����]����AutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �����]����Emg	���̏��~


if not(�����]����Emg) then  
	
	if �����]����ErrStep=0  then

	if not(�����]����OrgErr) then

	
	'-----------------------------------------------------------------------------------------------
	'�����]���u���]
	tmr(tim_MC36_���]���[�^���],tim_MC36_���]���[�^���]_val)
	
	select case MC36_���]���[�^���]step
	
	case 0
	
	case 1
		mMC36_���]���[�^�t�]=OFF
		mMC36_���]���[�^���]=ON
		errpassLS8_�����]�@���]�ʒu=OFF
		inc(MC36_���]���[�^���]step)
		
	
	case 2
		if LS8_�����]�@���]�ʒu or errpassLS8_�����]�@���]�ʒu then
			inc(MC36_���]���[�^���]step)
		end if
	
	case 3
		mMC36_���]���[�^���]=OFF
		inc(MC36_���]���[�^���]step)
	
	case 4
		MC36_���]���[�^���]step=0
		
	end select

	'------------------------------------------------------------------------------------------------
	'�����]���u�t�]
	tmr(tim_MC36_���]���[�^�t�],tim_MC36_���]���[�^�t�]_val)
	
	select case MC36_���]���[�^�t�]step
	
	case 0
	
	case 1
		inc(MC36_���]���[�^�t�]step)
		
	case 2
		mMC36_���]���[�^���]=OFF
		mMC36_���]���[�^�t�]=ON
		errpassLS7_�����]�@���_�ʒu=OFF
		inc(MC36_���]���[�^�t�]step)

	case 3
		if LS7_�����]�@���_�ʒu or errpassLS7_�����]�@���_�ʒu then
			inc(MC36_���]���[�^�t�]step)
		end if

	case 4
		mMC36_���]���[�^�t�]=OFF
		inc(MC36_���]���[�^�t�]step)
		
	case 5
		MC36_���]���[�^�t�]step=0
		
	end select
	'------------------------------------------------------------------------------------------------
	'MC35_�������[�^
	tmr(tim_MC35_�������[�^,tim_MC35_�������[�^_val)
	
	select case MC35_�������[�^step
	
	case 0
	
	case 1
		mMC35_�������[�^=ON
		inc(MC35_�������[�^step)

	case 2
		if not(PH57_�����m) and not(PH58_�t�^���m) then
			inc(MC35_�������[�^step)
		end if	

	case 3
		if PH59_�����m or PH62_�t�^���m then
			inc(MC35_�������[�^step)
		end if	

	case 4
		tim_MC35_�������[�^_val=10
		res(tim_MC35_�������[�^)
		inc(MC35_�������[�^step)
		
	case 5
		if tim_MC35_�������[�^.B then
			inc(MC35_�������[�^step)
		end if

	case 6
		mMC35_�������[�^=OFF
		inc(MC35_�������[�^step)
	
	case 7
		MC35_�������[�^step=0
	
	end select
	'------------------------------------------------------------------------------------------------
	'INV1_�R���x�A���[�^���]
	tmr(tim_INV1_�R���x�A���[�^���],tim_INV1_�R���x�A���[�^���]_val)
	tmr(tim_���H���I��,tim_���H���I��_val)

	
	select case INV1_�R���x�A���[�^���]step
	
	case 0
	
	case 1
		if �������� then
			setS05c1=4000
		else
			setS05c1=4000
		end if
		
		ejectINV1_�R���x�A���[�^���]=ON
		inc(INV1_�R���x�A���[�^���]step)


	case 2
		if �������� then
			tim_���H���I��_val=0
			tim_INV1_�R���x�A���[�^���]_val=INV1���r�o���� '1���@(27)  2���@(43)
		else
			tim_���H���I��_val=40
			tim_INV1_�R���x�A���[�^���]_val=INV1�t�^�r�o���� '1���@(80)  2���@(83)
		end if
		
		res(tim_���H���I��)
		res(tim_INV1_�R���x�A���[�^���])
		inc(INV1_�R���x�A���[�^���]step)
		
	case 3
		if not(��������) and tim_���H���I��.B then
			���H���I��=ON
		end if
		
		if tim_INV1_�R���x�A���[�^���].B then
			inc(INV1_�R���x�A���[�^���]step)
		end if

	case 4

		��������=OFF
		ejectINV1_�R���x�A���[�^���]=OFF
		inc(INV1_�R���x�A���[�^���]step)
	
	case 5
		INV1_�R���x�A���[�^���]step=0
	
	end select
	'------------------------------------------------------------------------------------------------

	if (�����]����AutoMode and ��������AutoMode ) or �����]����step<>0 then
	
		if not(�����]����AutoMode and ��������AutoMode ) then
			�����]����AutoRun=OFF
		end if

	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case �����]����step
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �����]����AutoRun then
				inc(�����]����step)
			else 
				�����]����step=0 '�I���ҋ@
			end if
	
		case 2
			if �����]����Org then
				inc(�����]����step)
			else
				�����]����step=1
			end if
	
		case 3
'			if PH59_�����m or PH62_�t�^���m or shiftreg���t�^����0<>0 then '���R���x�A��̃��[�N����
			if PH59_�����m or PH62_�t�^���m then '���R���x�A��̃��[�N����
				�����]�������쒆=OFF
				�����]�����r�o�v��=ON
				�����]����step=1
			else
				inc(�����]����step)
			end if

		case 4
			if �����]�����r�o�v��=OFF and  ���R���x�A�������쒆=OFF and ���t�^���~���uA�r�o�v�� then
				�����]����step=100
			else
				�����]����step=1
			end if
		'--------------------------------------------------------------------------------------------------------------
		case 100
			if not(LS7_�����]�@���_�ʒu) then 
				�����]����OrgErr=ON
				�����]����step=0	

			else if PH57_�����m or PH58_�t�^���m then '�`�F�[�������R���x�A�̃��[�N����
				�����]�������쒆=ON
				inc(�����]����step)

			else
				���t�^���~���uA�r�o�v��=OFF
				�����]����step=1
			end if
			
		'--------------------------------------------------------------------------------------------------------------
		case 101
			if PH57_�����m and PH58_�t�^���m then
				inc(�����]����step) '������
			else if not(PH57_�����m) and PH58_�t�^���m then
				�����]����step=150 '�t�^����
			end if

		'--------------------------------------------------------------------------------------------------------------
		'������
		case 102
			��������=ON
			mMC35_�������[�^=ON
			tim_procstep_val=10 '���}������
			res(tim_procstep)
			inc(�����]����step)
		
		case 103
			if tim_procstep.B then
				mMC35_�������[�^=OFF
				inc(�����]����step)
			end if
		
		case 104
			MC36_���]���[�^���]step=1
			inc(�����]����step)
		
		case 105
			if MC36_���]���[�^���]step=0 then
				inc(�����]����step)
			end if
		
		case 106
			INV1_�R���x�A���[�^���]step=1
			inc(�����]����step)
		
		case 107
			if INV1_�R���x�A���[�^���]step=0 then
				inc(�����]����step)
			end if
		
		case 108
			�����]�����r�o�v��=ON '���R���x�A�F�N��
			MC36_���]���[�^�t�]step=1
			inc(�����]����step)

		case 109
			if MC36_���]���[�^�t�]step=0 then
				inc(�����]����step)
			end if
						
		case 110
			���t�^���~���uA�r�o�v��=OFF	'���t�^���~���uA�F���t�g���~
			�����������r�o�v��=ON
			�����]�����r�o�v��=ON
			�����]�������쒆=OFF
			�����]����step=1

		'------------------------------------
		'�t�^����
		case 150
			MC35_�������[�^step=1
			INV1_�R���x�A���[�^���]step=1
			inc(�����]����step)
		
		case 151
			if MC35_�������[�^step=0 and INV1_�R���x�A���[�^���]step=0 then
				inc(�����]����step)
			end if
		
		case 152
			���t�^���~���uA�r�o�v��=OFF	'���t�^���~���uA�F���t�g���~
			�����������r�o�v��=ON
			�����]�����r�o�v��=ON
			�����]�������쒆=OFF
			�����]����step=1
		'--------------------------------------------------------------------------------------------------------------
			
		end select
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		�����]����AutoRun=OFF
		
		�����]����step=0 '�I��
	
		res(tim_LS7_�����]�@���_�ʒu)
		res(tim_LS8_�����]�@���]�ʒu)
		
		if ldp(pnlPBINV1_�R���x�A���[�^���]) then
			if ejectINV1_�R���x�A���[�^���] then
				ejectINV1_�R���x�A���[�^���]=OFF
			else
				ejectINV1_�R���x�A���[�^���]=ON
			end if
		end if
		
		if ldp(pnlPBMC35_�������[�^) then
			if mMC35_�������[�^ then
				mMC35_�������[�^=OFF
			else
				mMC35_�������[�^=ON
			end if
		end if
		
		
		if ldp(pnlPBMC36_���]���[�^���] or pnlPBMC36_���]���[�^�t�]) then
			if ldp(pnlPBMC36_���]���[�^���]) or LS7_�����]�@���_�ʒu then
				if not(mMC36_���]���[�^�t�]) and not(PH59_�����m) and not(PH62_�t�^���m) then
					mMC36_���]���[�^���]=ON
					mMC36_���]���[�^�t�]=OFF
				end if
			else if ldp(pnlPBMC36_���]���[�^�t�]) or LS8_�����]�@���]�ʒu then
				if not(mMC36_���]���[�^���]) then
					mMC36_���]���[�^���]=OFF
					mMC36_���]���[�^�t�]=ON
				end if
			else
					mMC36_���]���[�^���]=OFF
					mMC36_���]���[�^�t�]=ON
			end if
		end if
		if mMC36_���]���[�^���] and LS8_�����]�@���]�ʒu then
			mMC36_���]���[�^���]=OFF
		end if
		if mMC36_���]���[�^�t�] and LS7_�����]�@���_�ʒu then
			mMC36_���]���[�^�t�]=OFF
		end if


	end if '�����]����AutoMode and not(�����]����OrgErrStep)

	'===================================================================================================================
	'�y �����]����OrgErr���� �z
	else

		res(tim_LS7_�����]�@���_�ʒu)
		res(tim_LS8_�����]�@���]�ʒu)

		if ResetFlg then
			�����]����OrgErr=OFF
		end if		

	end if

	'===================================================================================================================
	'�y�^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
		res(tim_LS7_�����]�@���_�ʒu)
		res(tim_LS8_�����]�@���]�ʒu)

		�����]����Err=ON

		�����]����AutoRun=OFF
		�����]����step=0

		select case �����]����ErrStep
		case 0
		case 1
			if ResetFlg then
				almLS8_�����]�@���]�ʒu=OFF
				almLS7_�����]�@���_�ʒu=OFF
				inc(�����]����ErrStep)
			end if
		case 2
			�����]����Err=OFF
			�����]����ErrStep=0
		end select

	end if 'if �����]����ErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	select case �����]����EmgStep
	case 0

	case 1
		�����]����AutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�����]����AutoMode and ��������AutoMode ) or �����]����step<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseMC35_�������[�^=ON
			pauseMC36_���]���[�^���]=ON
			pauseMC36_���]���[�^�t�]=ON
			pauseINV1_�R���x�A���[�^���]=ON

			if timstack=OFF then
				timdly_PH59_�����m_stack=timdly_PH59_�����m.U
				timdly_PH60_�t�^���m_stack=timdly_PH60_�t�^���m.U
				tim_procstep_stack=tim_procstep.U
				tim_INV1_�R���x�A���[�^���]_stack=tim_INV1_�R���x�A���[�^���].U
				tim_MC30_�������[�^_stack=tim_MC30_�������[�^.U
				tim_MC36_���]���[�^�t�]_stack=tim_MC36_���]���[�^�t�].U
				tim_MC36_���]���[�^���]_stack=tim_MC36_���]���[�^���].U
				tim_MC35_�������[�^_stack=tim_MC35_�������[�^.U
				tim_���H���I��_stack=tim_���H���I��.U
			
				timstack=ON
			end if
			
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC35_�������[�^=OFF
			mMC36_���]���[�^���]=OFF
			mMC36_���]���[�^�t�]=OFF
			mINV1_�R���x�A���[�^���]=OFF
			ejectINV1_�R���x�A���[�^���]=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�����]����EmgStep)
	case 2
		if ResetFlg then
			inc(�����]����EmgStep)
		end if
	case 3
		if (�����]����AutoMode and ��������AutoMode ) or �����]����step<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseMC35_�������[�^=OFF
				pauseMC36_���]���[�^���]=OFF
				pauseMC36_���]���[�^�t�]=OFF
				pauseINV1_�R���x�A���[�^���]=OFF

				timdly_PH59_�����m.U=timdly_PH59_�����m_stack
				timdly_PH60_�t�^���m.U=timdly_PH60_�t�^���m_stack
				tim_procstep.U=tim_procstep_stack
				tim_INV1_�R���x�A���[�^���].U=tim_INV1_�R���x�A���[�^���]_stack
				tim_MC30_�������[�^.U=tim_MC30_�������[�^_stack
				tim_MC36_���]���[�^�t�].U=tim_MC36_���]���[�^�t�]_stack
				tim_MC36_���]���[�^���].U=tim_MC36_���]���[�^���]_stack
				tim_MC35_�������[�^.U=tim_MC35_�������[�^_stack
				tim_���H���I��.U=tim_���H���I��_stack
			
				'---------------------------------
				inc(�����]����EmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�����]����EmgStep)		
		end if				
	case 4
		timstack=OFF
		�����]����EmgStep=0
		�����]����Emg=OFF
	end select

end if 'if �����]����EmgStep=0 then
