'�W��胆�j�b�g
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'
'	�W��胆�j�b�g
'
'	PH23_�����m		-> PH51_�����m
'	PH24_�t�^���m	-> PH52_�t�^���m
'	mSV40_�X�g�b�p -> mSV49_�X�g�b�p
'===================================================================================================================

'�y ���������� �z
if CR2008 then

	�W��胆�j�b�gAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �W��胆�j�b�gAutoRun=OFF
    �W��胆�j�b�g����=ON
    �W��胆�j�b�gOrgErr=OFF
    �W��胆�j�b�gErr=OFF
    �W��胆�j�b�gEmg=OFF
    �W��胆�j�b�gstep=0
    �W��胆�j�b�gErrStep=0
    �W��胆�j�b�gOrgErrStep=0
    �W��胆�j�b�gEmgStep=0

end if
'===================================================================================================================
'�y ���_ �z
�W��胆�j�b�gOrg=not(�W��胆�j�b�g����) or (XSW55_�V�����_�㏸�[A and XSW57_�V�����_�㏸�[B)

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�W��胆�j�b�gEmg=ON
	�W��胆�j�b�gEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
tmr(SV45_�V�����_�㏸A and not(XSW55_�V�����_�㏸�[A) and not(pnlPBXSW55_�V�����_�㏸�[A),tim_XSW55_�V�����_�㏸�[A,#40)
tmr(SV46_�V�����_���~A and not(XSW56_�V�����_���~�[A) and not(pnlPBXSW56_�V�����_���~�[A),tim_XSW56_�V�����_���~�[A,#40)
tmr(SV47_�V�����_�㏸B and not(XSW57_�V�����_�㏸�[B) and not(pnlPBXSW57_�V�����_�㏸�[B),tim_XSW57_�V�����_�㏸�[B,#40)
tmr(SV48_�V�����_���~B and not(XSW58_�V�����_���~�[B) and not(pnlPBXSW58_�V�����_���~�[B),tim_XSW58_�V�����_���~�[B,#40)
tmr(SV49_�A���N�����v and not(XSW59_�A���N�����v) and not(pnlPBXSW59_�A���N�����v),tim_XSW59_�A���N�����v,#40)
tmr(SV50_�N�����v and not(XSW60_�N�����v) and not(pnlPBXSW60_�N�����v),tim_XSW60_�N�����v,#40)

'tmr(SV46_�X�g�b�p and not(XSW63_�X�g�b�p�㏸�[),tim_XSW63_�X�g�b�p�㏸�[,#40)
'tmr(not(SV46_�X�g�b�p) and not(XSW64_�X�g�b�p���~�[),tim_XSW64_�X�g�b�p���~�[,#40)


if ldp(tim_XSW55_�V�����_�㏸�[A.B) then
	errpassXSW55_�V�����_�㏸�[A=ON
	almXSW55_�V�����_�㏸�[A=ON
	�W��胆�j�b�gErrStep=1

else if ldp(tim_XSW56_�V�����_���~�[A.B) then
	errpassXSW56_�V�����_���~�[A=ON
	almXSW56_�V�����_���~�[A=ON
	�W��胆�j�b�gErrStep=1

else if ldp(tim_XSW57_�V�����_�㏸�[B.B) then
	errpassXSW57_�V�����_�㏸�[B=ON
	almXSW57_�V�����_�㏸�[B=ON
	�W��胆�j�b�gErrStep=1

else if ldp(tim_XSW58_�V�����_���~�[B.B) then
	errpassXSW58_�V�����_���~�[B=ON
	almXSW58_�V�����_���~�[B=ON
	�W��胆�j�b�gErrStep=1

else if ldp(tim_XSW59_�A���N�����v.B) then
	errpassXSW59_�A���N�����v=ON
	almXSW59_�A���N�����v=ON
	�W��胆�j�b�gErrStep=1

else if ldp(tim_XSW60_�N�����v.B) then
	errpassXSW60_�N�����v=ON
	almXSW60_�N�����v=ON
	�W��胆�j�b�gErrStep=1

'else if ldp(tim_XSW63_�X�g�b�p�㏸�[.B) then
'	errpassXSW63_�X�g�b�p�㏸�[=ON
'	almXSW63_�X�g�b�p�㏸�[=ON
'	�W��胆�j�b�gErrStep=1
'
'else if ldp(tim_XSW64_�X�g�b�p���~�[.B) then
'	errpassXSW64_�X�g�b�p���~�[=ON
'	almXSW64_�X�g�b�p���~�[=ON
'	�W��胆�j�b�gErrStep=1

end if

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �W��胆�j�b�gAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �W��胆�j�b�gAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\
'System :: �W��胆�j�b�gEmg	���̏��~


if �W��胆�j�b�gEmgStep=0 then  
	
	if �W��胆�j�b�gErrStep=0  then

	if not(�W��胆�j�b�gOrgErr) then

	if (�W��胆�j�b�gAutoMode and ��������AutoMode ) or �W��胆�j�b�gstep<>0 then
		
		if not(�W��胆�j�b�gAutoMode and ��������AutoMode ) then
			�W��胆�j�b�gAutoRun=OFF
		end if

	'===================================================================================================================
	'�y �v���Z�X���� �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case �W��胆�j�b�gstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
			�W��胆�j�b�gStatusMsg=#0
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' ��ƍH����U�蕪����
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �W��胆�j�b�gAutoRun then
				�W��胆�j�b�gStatusMsg=#45	'	�ҋ@��
				inc(�W��胆�j�b�gstep)
			else 
				�W��胆�j�b�gstep=0 '�I���ҋ@
			end if
		
		case 2
		' [ �W�J�}�ړ���~�m�F ]
			if �W��胆�j�b�g�r�o�v��=OFF and  �����R���x�AG���쒆=OFF then
				inc(�W��胆�j�b�gstep)
			else
				�W��胆�j�b�gstep=1
			end if
		
		case 3
		' [ ���j�b�g�����o ]
			if �W��胆�j�b�g���� then
				inc(�W��胆�j�b�gstep)
			else
				�t�^��芮��=ON
				�W��胆�j�b�g�r�o�v��=ON
				�W��胆�j�b�gstep=1
			end if
		
		case 4
			if XSW55_�V�����_�㏸�[A and XSW57_�V�����_�㏸�[B then '���_
				�W��胆�j�b�gstep=100 '�v���Z�X����
			else
				�W��胆�j�b�gstep=1
			end if
		'--------------------------------------------------------------------------------------------------------------
		'�v���Z�X����
		case 100
			if �t�^��芮�� then '�����ړ���OFF
				�W��胆�j�b�gstep=199
			else
				if not(�t�^���t�^��蒆) and  PH51_�����m and PH52_�t�^���m then
					�W��胆�j�b�gStatusMsg=#46	'	�t�^��蒆
					inc(�W��胆�j�b�gstep) '�t�^���
				else if �t�^���t�^��蒆 and  not(PH51_�����m) and not(PH52_�t�^���m) then
					�W��胆�j�b�gStatusMsg=#47	'	�t�^�u����
					�W��胆�j�b�gstep=150 '�t�^�u��
				else
					�t�^��芮��=ON
					�W��胆�j�b�g�r�o�v��=ON
					�W��胆�j�b�gstep=1
				end if
			end if

		'------------------------------------------------------
		case 101  '�t�^���
			mSV45_�V�����_�㏸A=OFF
			mSV46_�V�����_���~A=OFF
			mSV47_�V�����_�㏸B=OFF
			mSV48_�V�����_���~B=OFF
			mSV49_�A���N�����v=OFF
			mSV50_�N�����v=OFF
			
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W��胆�j�b�gstep)

		case 102
			if tim_procstep.B then
				inc(�W��胆�j�b�gstep)
			end if

		case 103
			mSV46_�V�����_���~A=ON
			errpassXSW56_�V�����_���~�[A=OFF
			inc(�W��胆�j�b�gstep)

		case 104
			if errpassXSW56_�V�����_���~�[A or XSW56_�V�����_���~�[A then
				inc(�W��胆�j�b�gstep)
			end if
		
		case 105
			mSV46_�V�����_���~A=OFF
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W��胆�j�b�gstep)
		
		case 106
			if tim_procstep.B then
				inc(�W��胆�j�b�gstep)
			end if
		
		case 107
			mSV50_�N�����v=ON
			errpassXSW60_�N�����v=OFF
			inc(�W��胆�j�b�gstep)
		
		case 108
			if errpassXSW60_�N�����v or XSW60_�N�����v then
				inc(�W��胆�j�b�gstep)
			end if
		
		case 109
			mSV50_�N�����v=OFF
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W��胆�j�b�gstep)
		
		case 110
			if tim_procstep.B then
				inc(�W��胆�j�b�gstep)
			end if
		
		case 111
			mSV45_�V�����_�㏸A=ON
			errpassXSW55_�V�����_�㏸�[A=OFF
			inc(�W��胆�j�b�gstep)
		
		case 112
			if errpassXSW55_�V�����_�㏸�[A or XSW55_�V�����_�㏸�[A then
				inc(�W��胆�j�b�gstep)
			end if
		
		case 113
			mSV45_�V�����_�㏸A=OFF
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W��胆�j�b�gstep)
		
		case 114
			if tim_procstep.B then
				�t�^���t�^��蒆=ON
				�W��胆�j�b�gstep=199
			end if
		'------------------------------------------------------
		case 150 '�t�^�u��
			mSV45_�V�����_�㏸A=OFF
			mSV46_�V�����_���~A=OFF
			mSV47_�V�����_�㏸B=OFF
			mSV48_�V�����_���~B=OFF
			mSV49_�A���N�����v=OFF
			mSV50_�N�����v=OFF
			mSV49_�X�g�b�p=OFF
			inc(�W��胆�j�b�gstep)
		
		case 151
			mSV46_�X�g�b�p=OFF
			inc(�W��胆�j�b�gstep)
		
		case 152
			if errpassXSW64_�X�g�b�p���~�[ or ((XSW64_�X�g�b�p���~�[ and not(pnlPBXSW64_�X�g�b�p���~�[)) or passXSW64_�X�g�b�p���~�[) then
				inc(�W��胆�j�b�gstep)
			end if
		
		case 153 
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W��胆�j�b�gstep)

		case 154
			if tim_procstep.B then
				if XSW55_�V�����_�㏸�[A and XSW57_�V�����_�㏸�[B then '���_
					if XSW60_�N�����v then
						inc(�W��胆�j�b�gstep)
					else
						�W��胆�j�b�gOrgErr=ON
					end if
				else
					�W��胆�j�b�gOrgErr=ON
				end if
			end if

		case 155
			mSV46_�V�����_���~A=ON
			inc(�W��胆�j�b�gstep)
			
		case 156
			mSV48_�V�����_���~B=ON
			errpassXSW56_�V�����_���~�[A=OFF
			inc(�W��胆�j�b�gstep)		
		
		case 157
			if errpassXSW56_�V�����_���~�[A or XSW56_�V�����_���~�[A then
				inc(�W��胆�j�b�gstep)
			end if		
		
		case 158
			mSV46_�V�����_���~A=OFF
			errpassXSW58_�V�����_���~�[B=OFF
			inc(�W��胆�j�b�gstep)

		case 159
			if errpassXSW58_�V�����_���~�[B or XSW58_�V�����_���~�[B then
				inc(�W��胆�j�b�gstep)
			end if
		
		case 160			
			mSV48_�V�����_���~B=OFF
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W��胆�j�b�gstep)

		case 161
			if tim_procstep.B then
				inc(�W��胆�j�b�gstep)
			end if
		
		case 162
			inc(�W��胆�j�b�gstep)
		
		case 163
			mSV49_�A���N�����v=ON
			errpassXSW59_�A���N�����v=OFF
			inc(�W��胆�j�b�gstep)
		
		case 164
			if errpassXSW59_�A���N�����v or XSW59_�A���N�����v then
				inc(�W��胆�j�b�gstep)
			end if

		case 165
			mSV49_�A���N�����v=OFF
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W��胆�j�b�gstep)
				
		case 166
			if tim_procstep.B then
				inc(�W��胆�j�b�gstep)
			end if
		
		case 167
			mSV45_�V�����_�㏸A=ON
			inc(�W��胆�j�b�gstep)
		
		case 168
			mSV47_�V�����_�㏸B=ON
			errpassXSW55_�V�����_�㏸�[A=OFF
			inc(�W��胆�j�b�gstep)

		case 169
			if errpassXSW55_�V�����_�㏸�[A or XSW55_�V�����_�㏸�[A then
				inc(�W��胆�j�b�gstep)
			end if
			
		case 170
			mSV45_�V�����_�㏸A=OFF
			inc(�W��胆�j�b�gstep)

		
		case 171
			if XSW57_�V�����_�㏸�[B then
				inc(�W��胆�j�b�gstep)
			end if
	
		case 172
			mSV47_�V�����_�㏸B=OFF
			inc(�W��胆�j�b�gstep)

		
		case 173
			�t�^���t�^��蒆=OFF
			�W��胆�j�b�gstep=199

		'------------------------------------------------------
		case 199
			�t�^��芮��=ON
			�W��胆�j�b�g�r�o�v��=ON
			�W��胆�j�b�gstep=1
		'------------------------------------------------------


		end select

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		�W��胆�j�b�gAutoRun=OFF
		
		�W��胆�j�b�gstep=0 '�I��
		
		res(tim_XSW55_�V�����_�㏸�[A.B)
		res(tim_XSW56_�V�����_���~�[A.B)
		res(tim_XSW57_�V�����_�㏸�[B.B)
		res(tim_XSW58_�V�����_���~�[B.B)
		res(tim_XSW59_�A���N�����v)
		res(tim_XSW60_�N�����v)


		'------------------------------------------------------
		if ldp(pnlPBSV45_�V�����_�㏸A or pnlPBSV46_�V�����_���~A) and (XSW59_�A���N�����v or (XSW60_�N�����v and ((XSW64_�X�g�b�p���~�[ and not(pnlPBXSW64_�X�g�b�p���~�[)) or passXSW64_�X�g�b�p���~�[ )) ) then
			if XSW55_�V�����_�㏸�[A then
				mSV46_�V�����_���~A=ON
				mSV45_�V�����_�㏸A=OFF
			else if XSW56_�V�����_���~�[A then
				mSV46_�V�����_���~A=OFF
				mSV45_�V�����_�㏸A=ON
			else
				mSV46_�V�����_���~A=OFF
				mSV45_�V�����_�㏸A=ON			
			end if
		end if
		if mSV46_�V�����_���~A and XSW56_�V�����_���~�[A then
			mSV46_�V�����_���~A=OFF
		end if
		if mSV45_�V�����_�㏸A and XSW55_�V�����_�㏸�[A then
			mSV45_�V�����_�㏸A=OFF
		end if
		'------------------------------------------------------
		if ldp(pnlPBSV47_�V�����_�㏸B or pnlPBSV48_�V�����_���~B) and (XSW59_�A���N�����v or (XSW60_�N�����v and ((XSW64_�X�g�b�p���~�[ and not(pnlPBXSW64_�X�g�b�p���~�[)) or passXSW64_�X�g�b�p���~�[ )) ) then
			if XSW57_�V�����_�㏸�[B then
				mSV48_�V�����_���~B=ON
				mSV47_�V�����_�㏸B=OFF
			else if XSW58_�V�����_���~�[B then
				mSV48_�V�����_���~B=OFF
				mSV47_�V�����_�㏸B=ON
			else
				mSV48_�V�����_���~B=OFF
				mSV47_�V�����_�㏸B=ON			
			end if
		end if
		if mSV48_�V�����_���~B and XSW58_�V�����_���~�[B then
			mSV48_�V�����_���~B=OFF
		end if
		if mSV47_�V�����_�㏸B and XSW57_�V�����_�㏸�[B then
			mSV47_�V�����_�㏸B=OFF
		end if
		'------------------------------------------------------
		if ldp(pnlPBSV49_�A���N�����v or pnlPBSV50_�N�����v) then
			if XSW59_�A���N�����v then
				mSV50_�N�����v=ON
				mSV49_�A���N�����v=OFF
			
				�t�^���t�^��蒆=ON

			else if XSW60_�N�����v then
				mSV50_�N�����v=OFF
				mSV49_�A���N�����v=ON			

				�t�^���t�^��蒆=OFF
				
			else
				mSV50_�N�����v=OFF
				mSV49_�A���N�����v=ON			

				�t�^���t�^��蒆=OFF
			

			end if
		end if
		if mSV50_�N�����v and XSW60_�N�����v then
			mSV50_�N�����v=OFF
		end if
		if mSV49_�A���N�����v and XSW59_�A���N�����v then
			mSV49_�A���N�����v=OFF
		end if
		'------------------------------------------------------

	end if '�W��胆�j�b�gAutoMode and not(�W��胆�j�b�gOrgErrStep)
	'===================================================================================================================
	'�y �W��胆�j�b�gOrgErr���� �z
	else

		res(tim_XSW55_�V�����_�㏸�[A.B)
		res(tim_XSW56_�V�����_���~�[A.B)
		res(tim_XSW57_�V�����_�㏸�[B.B)
		res(tim_XSW58_�V�����_���~�[B.B)
		res(tim_XSW59_�A���N�����v)
		res(tim_XSW60_�N�����v)
			
		if ResetFlg then
			�W��胆�j�b�gOrgErr=OFF
		end if

	end if
	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
	
		�W��胆�j�b�gErr=ON
	
		select case �W��胆�j�b�gErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW55_�V�����_�㏸�[A=OFF
				almXSW56_�V�����_���~�[A=OFF
				almXSW57_�V�����_�㏸�[B=OFF
				almXSW58_�V�����_���~�[B=OFF
				almXSW59_�A���N�����v=OFF
				almXSW60_�N�����v=OFF

				inc(�W��胆�j�b�gErrStep)
			end if
		case 2
			�W��胆�j�b�gErr=OFF

			res(tim_XSW55_�V�����_�㏸�[A.B)
			res(tim_XSW56_�V�����_���~�[A.B)
			res(tim_XSW57_�V�����_�㏸�[B.B)
			res(tim_XSW58_�V�����_���~�[B.B)
			res(tim_XSW59_�A���N�����v)
			res(tim_XSW60_�N�����v)
			�W��胆�j�b�gErrStep=0
		end select

	end if 'if �W��胆�j�b�gErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	select case �W��胆�j�b�gEmgStep
	case 0
	
	case 1
		�W��胆�j�b�gAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�W��胆�j�b�gAutoMode and ��������AutoMode ) or �W��胆�j�b�gstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mSV45_�V�����_�㏸A=OFF
			mSV46_�V�����_���~A=OFF
			mSV47_�V�����_�㏸B=OFF
			mSV48_�V�����_���~B=OFF
			mSV49_�A���N�����v=OFF
			mSV50_�N�����v=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�W��胆�j�b�gEmgStep)
	case 2
		if ResetFlg then
			inc(�W��胆�j�b�gEmgStep)
		end if
	case 3
		if (�W��胆�j�b�gAutoMode and ��������AutoMode ) or �W��胆�j�b�gstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				tim_procstep.U=tim_procstep_stack
				
				
				
				'---------------------------------
				inc(�W��胆�j�b�gEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�W��胆�j�b�gEmgStep)		
		end if				
	case 4
		timstack=OFF
		�W��胆�j�b�gEmgStep=0
		�W��胆�j�b�gEmg=OFF
	end select
		
end if 'if �W��胆�j�b�gEmgStep=0 then
