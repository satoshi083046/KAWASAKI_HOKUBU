'�Ȃ炵���j�b�g
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'
'	�Ȃ炵���j�b�g
'===================================================================================================================

'�y ���������� �z

if CR2008 then
    �Ȃ炵���j�b�gAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �Ȃ炵���j�b�gAutoRun=OFF
    �Ȃ炵���j�b�g����=ON
    �Ȃ炵���j�b�gOrgErr=OFF
    �Ȃ炵���j�b�gErr=OFF
    �Ȃ炵���j�b�gEmg=OFF
    �Ȃ炵���j�b�gstep=0
    �Ȃ炵���j�b�gErrStep=0
    �Ȃ炵���j�b�gOrgErrStep=0
    �Ȃ炵���j�b�gEmgStep=0
	
	SV23_�Ȃ炵�O�istep=0
	SV24_�Ȃ炵���step=0

end if

'===================================================================================================================
'�y ���_ �z
�Ȃ炵���j�b�gOrg= not(�Ȃ炵���j�b�g����) or (XSW25_�Ȃ炵�㏸�[ and (XSW24_�Ȃ炵�O�i�[ or XSW23_�Ȃ炵��ޒ[))

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�Ȃ炵���j�b�gEmg=ON
	�Ȃ炵���j�b�gEmgStep=1
end if

'------------------------------------------------------
'�������󂯂Ɉړ�
tmr(tim_SV23_�Ȃ炵�O�i,tim_SV23_�Ȃ炵�O�i_val)
select case SV23_�Ȃ炵�O�istep '�������󂯂Ɉړ�
case 0

case 1
	if XSW25_�Ȃ炵�㏸�[ then
		inc(SV23_�Ȃ炵�O�istep)	
	end if

case 2
	if not(XSW24_�Ȃ炵�O�i�[) then
		mSV23_�Ȃ炵�O�i=ON
		mSV24_�Ȃ炵���=OFF
		errpassXSW24_�Ȃ炵�O�i�[=OFF
	end if
	
	inc(SV23_�Ȃ炵�O�istep)
case 3
	if errpassXSW24_�Ȃ炵�O�i�[ or XSW24_�Ȃ炵�O�i�[ then
		inc(SV23_�Ȃ炵�O�istep)
	end if
case 4
	mSV23_�Ȃ炵�O�i=OFF
	mSV24_�Ȃ炵���=OFF
	SV23_�Ȃ炵�O�istep=0
end select
'------------------------------------------------------
'�������󂯂��痣�E
tmr(tim_SV24_�Ȃ炵���,tim_SV24_�Ȃ炵���_val)
select case SV24_�Ȃ炵���step '�������󂯂��痣�E
case 0

case 1
	if XSW25_�Ȃ炵�㏸�[ then
		inc(SV24_�Ȃ炵���step)
	end if

case 2
	if not(XSW23_�Ȃ炵��ޒ[) then
		mSV23_�Ȃ炵�O�i=OFF
		mSV24_�Ȃ炵���=ON
		errpassXSW23_�Ȃ炵��ޒ[=OFF
	end if
	inc(SV24_�Ȃ炵���step)
case 3
	if errpassXSW23_�Ȃ炵��ޒ[ or XSW23_�Ȃ炵��ޒ[ then
		inc(SV24_�Ȃ炵���step)	
	end if
case 4
	mSV23_�Ȃ炵�O�i=OFF
	mSV24_�Ȃ炵���=OFF
	SV24_�Ȃ炵���step=0
end select
'------------------------------------------------------


'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

tmr(XSW44_�Ȃ炵���_�Z���T,tim_dly_XSW44_�Ȃ炵���_�Z���T,0)
tmr(not(XSW44_�Ȃ炵���_�Z���T),tim_notdly_XSW44_�Ȃ炵���_�Z���T,10)

tmr(MC40_�Ȃ炵���[�^ and not(pnlPBMC40_�Ȃ炵���[�^),tim_MC40_�Ȃ炵���[�^,40*DM_�Ȃ炵�񐔐ݒ�l)
tmr(SV23_�Ȃ炵�O�i and not(XSW24_�Ȃ炵�O�i�[) and not(pnlPBXSW24_�Ȃ炵�O�i�[),tim_XSW24_�Ȃ炵�O�i�[,#60)
'�������󂯂Ɉړ�
tmr(SV24_�Ȃ炵��� and not(XSW23_�Ȃ炵��ޒ[) and not(pnlPBXSW23_�Ȃ炵��ޒ[),tim_XSW23_�Ȃ炵��ޒ[,#60)
tmr(SV25_�Ȃ炵���~ and not(XSW26_�Ȃ炵���~�[) and not(pnlPBXSW26_�Ȃ炵���~�[),tim_XSW26_�Ȃ炵���~�[,#80)
tmr(SV26_�Ȃ炵�㏸ and not(XSW25_�Ȃ炵�㏸�[) and not(pnlPBXSW25_�Ȃ炵�㏸�[), tim_XSW25_�Ȃ炵�㏸�[,#80)

if ldp(tim_MC40_�Ȃ炵���[�^.B) then
	errpassMC40_�Ȃ炵���[�^=ON
	mMC40_�Ȃ炵���[�^=OFF
	almMC40_�Ȃ炵���[�^=ON
	�Ȃ炵���j�b�gErrStep=1

else if ldp(tim_XSW24_�Ȃ炵�O�i�[.B) then
	errpassXSW24_�Ȃ炵�O�i�[=ON
	almXSW24_�Ȃ炵�O�i�[=ON
	�Ȃ炵���j�b�gErrStep=1

else if ldp(tim_XSW23_�Ȃ炵��ޒ[.B) then	
	errpassXSW23_�Ȃ炵��ޒ[=ON
	almXSW23_�Ȃ炵��ޒ[=ON
	�Ȃ炵���j�b�gErrStep=1

else if ldp(tim_XSW26_�Ȃ炵���~�[.B) then
	errpassXSW26_�Ȃ炵���~�[=ON
	almXSW26_�Ȃ炵���~�[=ON
	�Ȃ炵���j�b�gErrStep=1

else if ldp(tim_XSW25_�Ȃ炵�㏸�[.B) then
	errpassXSW25_�Ȃ炵�㏸�[=ON
	almXSW25_�Ȃ炵�㏸�[=ON
	�Ȃ炵���j�b�gErrStep=1

end if

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �Ȃ炵���j�b�gAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �Ȃ炵���j�b�gAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\
'System :: �Ȃ炵���j�b�gEmg	���̏��~


if �Ȃ炵���j�b�gEmgStep=0 then  
	
	if �Ȃ炵���j�b�gErrStep=0  then

	if not(�Ȃ炵���j�b�gOrgErr) then

	if (�Ȃ炵���j�b�gAutoMode and ��������AutoMode ) or �Ȃ炵���j�b�gstep<>0 then
		
		if not(�Ȃ炵���j�b�gAutoMode and ��������AutoMode ) then
			�Ȃ炵���j�b�gAutoRUn=OFF
		end if

	'===================================================================================================================
	'�y �v���Z�X���� �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case �Ȃ炵���j�b�gstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
				�Ȃ炵���j�b�gStatusMsg=#0
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' ��ƍH����U�蕪����
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �Ȃ炵���j�b�gAutoRun then
				inc(�Ȃ炵���j�b�gstep)
			else 
				SV23_�Ȃ炵�O�istep=1 '�������󂯂Ɉړ�
				�Ȃ炵���j�b�gstep=0 '�I���ҋ@ 
			end if
		
		case 2
		' [ �W�J�}�ړ���~�m�F ]
			if �Ȃ炵���j�b�g�r�o�v��=OFF and  �����R���x�AC���쒆=OFF then

				'[ ���X�e�[�W��"��"�L���o ]
					if PH17_�����m and PH18_�t�^���m then
						if ANDA(StageDevice8,$200)=$200 or ANDA(StageDevice8,$400)=$400 or 1 then 
							inc(�Ȃ炵���j�b�gstep) '�v���Z�X����
						else
							�Ȃ炵���j�b�g�r�o�v��=ON
							�Ȃ炵���j�b�gstep=1						
						end if
				'[ ���X�e�[�W��"�t�^"�L���o ]	
					else if not(PH17_�����m) and PH18_�t�^���m then 
							�Ȃ炵���j�b�g�r�o�v��=ON
							�Ȃ炵���j�b�gstep=1
				
				'[ ���X�e�[�W��"���t�^"�Ȃ� ]
						else
							�Ȃ炵���j�b�g�r�o�v��=ON
							�Ȃ炵���j�b�gstep=1  '�I��
					end if
			
			else
			
				�Ȃ炵���j�b�gstep=1
			
			end if
		
		case 3
		' [ ���j�b�g�����o ]
			if �Ȃ炵���j�b�g���� then
				inc(�Ȃ炵���j�b�gstep)
			else
				�Ȃ炵���j�b�g�r�o�v��=ON
				�Ȃ炵���j�b�gstep=1
			end if
	
		case 4
			if XSW25_�Ȃ炵�㏸�[ and (XSW24_�Ȃ炵�O�i�[ or XSW23_�Ȃ炵��ޒ[) then '���_
				�Ȃ炵���j�b�gstep=100 '�v���Z�X����
			else
				�Ȃ炵���j�b�gstep=1
			end if

		
		'--------------------------------------------------------------------------------------------------------------
		'�v���Z�X����
		case 100		
			if �Ȃ炵���� then '�����ړ���OFF
				�Ȃ炵���j�b�gstep=199
			else
				inc(�Ȃ炵���j�b�gstep)
			end if
				
		case 101
			�Ȃ炵���j�b�gStatusMsg=#31	'	�Ȃ炵��
			
			DM_�Ȃ炵�񐔌��ݒl=0
			mSV23_�Ȃ炵�O�i=OFF
			mSV24_�Ȃ炵���=ON	'�������󂯂��痣�E
			errpassXSW24_�Ȃ炵�O�i�[=OFF
			inc(�Ȃ炵���j�b�gstep)
			
		case 102
			if errpassXSW23_�Ȃ炵��ޒ[ or XSW23_�Ȃ炵��ޒ[ then
				inc(�Ȃ炵���j�b�gstep)
			end if
		
		case 103
			mSV24_�Ȃ炵���=OFF
			tim_procstep_val=#0
			res(tim_procstep)
			inc(�Ȃ炵���j�b�gstep)

		case 104
			if tim_procstep.B then
				inc(�Ȃ炵���j�b�gstep)
			end if
				
		case 105
			mSV25_�Ȃ炵���~=ON
			errpassXSW26_�Ȃ炵���~�[=OFF
			inc(�Ȃ炵���j�b�gstep)

		case 106
			if errpassXSW26_�Ȃ炵���~�[ or XSW26_�Ȃ炵���~�[ then
				inc(�Ȃ炵���j�b�gstep)
			end if
		
		case 107
			mSV25_�Ȃ炵���~=OFF				
			tim_procstep_val=#0
			res(tim_procstep)
			inc(�Ȃ炵���j�b�gstep)
			
		case 108
			if tim_procstep.B then		
				errpassMC40_�Ȃ炵���[�^=OFF
				�Ȃ炵���j�b�gstep=110
			end if
		
		'----------------------------------------------------
		case 110 '�Ȃ炵���[�v  <-
			if DM_�Ȃ炵�񐔌��ݒl < DM_�Ȃ炵�񐔐ݒ�l and not(errpassMC40_�Ȃ炵���[�^) then
				inc(�Ȃ炵���j�b�gstep)
			else 
				mMC40_�Ȃ炵���[�^=OFF
				�Ȃ炵���j�b�gstep=150
			end if
		
		case 111
			mMC40_�Ȃ炵���[�^=ON
			inc(�Ȃ炵���j�b�gstep)
		
		case 112
			tim_procstep_val=10
			res(tim_procstep)
			inc(�Ȃ炵���j�b�gstep)

		case 113
			if tim_procstep.B then
				inc(�Ȃ炵���j�b�gstep)
			end if			
				
		case 114
			if errpassMC40_�Ȃ炵���[�^ then
				inc(�Ȃ炵���j�b�gstep)			
			else if not(XSW44_�Ȃ炵���_�Z���T) and tim_notdly_XSW44_�Ȃ炵���_�Z���T.B then
				inc(�Ȃ炵���j�b�gstep)
			end if
		
		case 115
			if errpassMC40_�Ȃ炵���[�^ then
				inc(�Ȃ炵���j�b�gstep)			
			else if XSW44_�Ȃ炵���_�Z���T and tim_dly_XSW44_�Ȃ炵���_�Z���T.B then
				inc(DM_�Ȃ炵�񐔌��ݒl)
				if DM_�Ȃ炵�񐔌��ݒl >= DM_�Ȃ炵�񐔐ݒ�l then
					mMC40_�Ȃ炵���[�^=OFF
				end if
				inc(�Ȃ炵���j�b�gstep)
			end if
		
		case 116
			�Ȃ炵���j�b�gstep=110 '�Ȃ炵���[�v ->
		'----------------------------------------------------			
		case 150
			mSV26_�Ȃ炵�㏸=ON
			errpassXSW25_�Ȃ炵�㏸�[=OFF
			inc(�Ȃ炵���j�b�gstep)
			
		case 151
			if errpassXSW25_�Ȃ炵�㏸�[ or XSW25_�Ȃ炵�㏸�[ then
				inc(�Ȃ炵���j�b�gstep)
			end if
		
		case 152
			mSV26_�Ȃ炵�㏸=OFF
			tim_procstep_val=#0
			res(tim_procstep)
			inc(�Ȃ炵���j�b�gstep)
			
			�Ȃ炵����=ON
			�Ȃ炵���j�b�g�r�o�v��=ON

		
		case 153
			if tim_procstep.B then
				inc(�Ȃ炵���j�b�gstep)
			end if
		
		case 154
			mSV23_�Ȃ炵�O�i=ON	'�������󂯂Ɉړ�
			mSV24_�Ȃ炵���=OFF
			errpassXSW24_�Ȃ炵�O�i�[=OFF
			inc(�Ȃ炵���j�b�gstep)
			
		case 155
			if errpassXSW24_�Ȃ炵�O�i�[ or XSW24_�Ȃ炵�O�i�[ then
				inc(�Ȃ炵���j�b�gstep)
			end if

		case 156
			mSV23_�Ȃ炵�O�i=OFF
			tim_procstep_val=#0
			res(tim_procstep)
			�Ȃ炵���j�b�gstep=199

		case 199
			�Ȃ炵���j�b�g�r�o�v��=ON
			�Ȃ炵���j�b�gstep=1

		end select

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		�Ȃ炵���j�b�gAutoRun=OFF
		
		�Ȃ炵���j�b�gstep=0 '�I��
		�Ȃ炵����=OFF

		res(tim_MC40_�Ȃ炵���[�^)
		res(tim_XSW24_�Ȃ炵�O�i�[)
		res(tim_XSW23_�Ȃ炵��ޒ[)
		res(tim_XSW26_�Ȃ炵���~�[)
		res(tim_XSW25_�Ȃ炵�㏸�[)

		
		'---------------------------------------------------------
		if ldp(pnlPBSV23_�Ȃ炵�O�i or pnlPBSV24_�Ȃ炵���) then
			if XSW23_�Ȃ炵��ޒ[ and XSW25_�Ȃ炵�㏸�[ then
				mSV23_�Ȃ炵�O�i=ON
				mSV24_�Ȃ炵���=OFF		
			else if XSW24_�Ȃ炵�O�i�[ and XSW25_�Ȃ炵�㏸�[ then
				mSV23_�Ȃ炵�O�i=OFF
				mSV24_�Ȃ炵���=ON
			else
				mSV23_�Ȃ炵�O�i=OFF
				mSV24_�Ȃ炵���=ON			
			end if
		end if
		if mSV23_�Ȃ炵�O�i and XSW24_�Ȃ炵�O�i�[ then
			mSV23_�Ȃ炵�O�i=OFF
		end if 
		if mSV24_�Ȃ炵��� and XSW23_�Ȃ炵��ޒ[ then 
			mSV24_�Ȃ炵���=OFF
		end if
		'---------------------------------------------------------
		if ldp(pnlPBSV25_�Ȃ炵���~ or pnlPBSV26_�Ȃ炵�㏸) then
			if XSW25_�Ȃ炵�㏸�[ and XSW23_�Ȃ炵��ޒ[ then
				mSV25_�Ȃ炵���~=ON
				mSV26_�Ȃ炵�㏸=OFF
			else if XSW26_�Ȃ炵���~�[ and XSW23_�Ȃ炵��ޒ[ then
				mSV25_�Ȃ炵���~=OFF
				mSV26_�Ȃ炵�㏸=ON
			else
				mSV25_�Ȃ炵���~=OFF
				mSV26_�Ȃ炵�㏸=ON			
			end if
		end if
		if mSV25_�Ȃ炵���~ and XSW26_�Ȃ炵���~�[ then
			mSV25_�Ȃ炵���~=OFF
		end if
		if mSV26_�Ȃ炵�㏸ and XSW25_�Ȃ炵�㏸�[ then
			mSV26_�Ȃ炵�㏸=OFF
		end if
		'---------------------------------------------------------
		if ldp(pnlPBMC40_�Ȃ炵���[�^) and not(MC40_�Ȃ炵���[�^EndWait) then
			if mMC40_�Ȃ炵���[�^ then
				MC40_�Ȃ炵���[�^EndWait=ON
			else
				mMC40_�Ȃ炵���[�^=ON
				MC40_�Ȃ炵���[�^EndWait=OFF
			end if
		end if
		
		if MC40_�Ȃ炵���[�^EndWait and XSW44_�Ȃ炵���_�Z���T then
			mMC40_�Ȃ炵���[�^=OFF
			MC40_�Ȃ炵���[�^EndWait=OFF
		end if
		'---------------------------------------------------------
			
			
		
	end if '�Ȃ炵���j�b�gAutoMode and not(�Ȃ炵���j�b�gOrgErrStep)

	'===================================================================================================================
	'�y �Ȃ炵���j�b�gOrgErr���� �z
	else
	
		res(tim_MC40_�Ȃ炵���[�^)
		res(tim_XSW24_�Ȃ炵�O�i�[)
		res(tim_XSW23_�Ȃ炵��ޒ[)
		res(tim_XSW26_�Ȃ炵���~�[)
		res(tim_XSW25_�Ȃ炵�㏸�[)
		
		if ResetFlg then
			�Ȃ炵���j�b�gOrgErr=OFF
		end if
	
	end if
	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
		
		�Ȃ炵���j�b�gErr=ON
		
		select case �Ȃ炵���j�b�gErrStep
		case 0
		case 1
			if ResetFlg then
				almMC40_�Ȃ炵���[�^=OFF
				almXSW24_�Ȃ炵�O�i�[=OFF
				almXSW23_�Ȃ炵��ޒ[=OFF
				almXSW26_�Ȃ炵���~�[=OFF
				almXSW25_�Ȃ炵�㏸�[=OFF
			
				inc(�Ȃ炵���j�b�gErrStep)
			end if
		case 2
			�Ȃ炵���j�b�gErr=OFF
			res(tim_MC40_�Ȃ炵���[�^)
			res(tim_XSW24_�Ȃ炵�O�i�[)
			res(tim_XSW23_�Ȃ炵��ޒ[)
			res(tim_XSW26_�Ȃ炵���~�[)
			res(tim_XSW25_�Ȃ炵�㏸�[)
			�Ȃ炵���j�b�gErrStep=0
		end select

	end if 'if �Ȃ炵���j�b�gErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	select case �Ȃ炵���j�b�gEmgStep
	case 0
	
	case 1
		�Ȃ炵���j�b�gAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�Ȃ炵���j�b�gAutoMode and ��������AutoMode ) or �Ȃ炵���j�b�gstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseMC40_�Ȃ炵���[�^=ON
			
			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC40_�Ȃ炵���[�^=OFF
			mSV23_�Ȃ炵�O�i=OFF
			mSV24_�Ȃ炵���=OFF
			mSV25_�Ȃ炵���~=OFF
			mSV26_�Ȃ炵�㏸=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�Ȃ炵���j�b�gEmgStep)
	case 2
		if ResetFlg then
			inc(�Ȃ炵���j�b�gEmgStep)
		end if
	case 3
		if (�Ȃ炵���j�b�gAutoMode and ��������AutoMode ) or �Ȃ炵���j�b�gstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseMC40_�Ȃ炵���[�^=OFF
				tim_procstep.U=tim_procstep_stack
				'---------------------------------
				inc(�Ȃ炵���j�b�gEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�Ȃ炵���j�b�gEmgStep)		
		end if				
	case 4
		timstack=OFF
		�Ȃ炵���j�b�gEmgStep=0
		�Ȃ炵���j�b�gEmg=OFF
	end select
		
end if 'if �Ȃ炵���j�b�gEmgStep=0 then
