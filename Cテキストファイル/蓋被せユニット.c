'�W�킹���j�b�g
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'
'	�W�킹���j�b�g
'
'
'	�t�^�킹���̃G���[���
'	�t�^�킹�ʒu�C���G���[����  -> ���g���C  ->   �� �t�^�킹�G���[����
'                    (reset sw) 
'                    *�t�^�C��
'
'SV32_�N�����v ->SV26_�N�����v
'XSW36_�N�����v�㏸�[ -> XSW31_�N�����v�㏸�[
'XSW35_�N�����v���~�[ -> XSW30_�N�����v���~�[
'
'SV30_�X�g�b�p -> SV27_�X�g�b�p
'XSW32_�X�g�b�p�㏸�[ -> XSW33_�X�g�b�p�㏸�[
'XSW31_�X�g�b�p���~�[ -> XSW32_�X�g�b�p���~�[
'===================================================================================================================

'�y ���������� �z
if CR2008 then
    �W�킹���j�b�gAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �W�킹���j�b�gAutoRun=OFF
    �W�킹���j�b�g����=ON
    �W�킹���j�b�gOrgErr=OFF
    �W�킹���j�b�gErr=OFF
    �W�킹���j�b�gEmg=OFF
    �W�킹���j�b�gstep=0
    �W�킹���j�b�gErrStep=0
    �W�킹���j�b�gOrgErrStep=0
    �W�킹���j�b�gEmgStep=0

end if
'===================================================================================================================
'�y ���_ �z
�W�킹���j�b�gOrg=not(�W�킹���j�b�g����) or (XSW39_�V�����_�㏸�[A and XSW41_�V�����_�㏸�[B)

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�W�킹���j�b�gEmg=ON
	�W�킹���j�b�gEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
tmr(SV34_�V�����_�㏸A and not(XSW39_�V�����_�㏸�[A) and not(pnlPBXSW39_�V�����_�㏸�[A),tim_XSW39_�V�����_�㏸�[A,#50)
tmr(SV35_�V�����_���~A and not(XSW40_�V�����_���~�[A) and not(pnlPBXSW40_�V�����_���~�[A),tim_XSW40_�V�����_���~�[A,#50)
tmr(SV36_�V�����_�㏸B and not(XSW41_�V�����_�㏸�[B) and not(pnlPBXSW41_�V�����_�㏸�[B),tim_XSW41_�V�����_�㏸�[B,#50)
tmr(SV37_�V�����_���~B and not(XSW42_�V�����_���~�[B) and not(pnlPBXSW42_�V�����_���~�[B),tim_XSW42_�V�����_���~�[B,#50)
tmr(SV38_�N�����v and not(XSW43_�N�����v) and not(pnlPBXSW43_�N�����v),tim_XSW43_�N�����v,#40)
tmr(SV39_�A���N�����v and not(XSW44_�A���N�����v) and not(pnlPBXSW44_�A���N�����v),tim_XSW44_�A���N�����v,#40)


if ldp(tim_XSW39_�V�����_�㏸�[A.B) then
	errpassXSW39_�V�����_�㏸�[A=ON
	almXSW39_�V�����_�㏸�[A=ON
	�W�킹���j�b�gErrStep=1

else if ldp(tim_XSW40_�V�����_���~�[A.B) then
	if �t�^�킹�t�^��蒆 then
		errXSW40_�V�����_���~�[A=ON '�t�^�킹�G���[�ʒm
		errpassXSW40_�V�����_���~�[A=ON '�t�^�킹�G���[�H��pass
		almXSW40_�V�����_���~�[A=ON
		�W�킹���j�b�gErrStep=1
	else
		errpassXSW40_�V�����_���~�[A=ON '�t�^�킹�G���[�H��pass
		almXSW40_�V�����_���~�[A=ON
		�W�킹���j�b�gErrStep=1
	end if
	

else if ldp(tim_XSW41_�V�����_�㏸�[B.B) then
	errpassXSW41_�V�����_�㏸�[B=ON
	almXSW41_�V�����_�㏸�[B=ON
	�W�킹���j�b�gErrStep=1
	
else if ldp(tim_XSW42_�V�����_���~�[B.B) then
	errpassXSW42_�V�����_���~�[B=ON
	almXSW42_�V�����_���~�[B=On
	�W�킹���j�b�gErrStep=1
	
else if ldp(tim_XSW43_�N�����v.B) then
	errpassXSW43_�N�����v=ON
	almXSW43_�N�����v=ON
	�W�킹���j�b�gErrStep=1

else if ldp(tim_XSW44_�A���N�����v.B) then
	errpassXSW44_�A���N�����v=ON
	almXSW44_�A���N�����v=ON
	�W�킹���j�b�gErrStep=1

end if

if 0 then
tmr(not(SV26_�N�����v) and not(XSW30_�N�����v���~�[) and not(pnlPBXSW30_�N�����v���~�[), tim_XSW30_�N�����v���~�[, #30)
tmr(SV26_�N�����v and not(XSW31_�N�����v�㏸�[) and not(pnlPBXSW31_�N�����v�㏸�[), tim_XSW31_�N�����v�㏸�[,#30)
tmr(not(SV27_�X�g�b�p) and not(XSW32_�X�g�b�p���~�[) and not(pnlPBXSW32_�X�g�b�p���~�[),tim_XSW32_�X�g�b�p���~�[,#30)
tmr(SV27_�X�g�b�p and not(XSW33_�X�g�b�p�㏸�[) and not(pnlPBXSW33_�X�g�b�p�㏸�[),tim_XSW33_�X�g�b�p�㏸�[,#30)

if ldp(tim_XSW30_�N�����v���~�[.B) then
	errpassXSW30_�N�����v���~�[=ON
	almXSW30_�N�����v���~�[=ON
	�����R���x�ACErrStep=1

else if ldp(tim_XSW31_�N�����v�㏸�[.B) then
	errpassXSW31_�N�����v�㏸�[=ON
	pauseSV26_�N�����v=ON
	almXSW31_�N�����v�㏸�[=ON
	�W�킹���j�b�gErrStep=1

else if ldp(tim_XSW32_�X�g�b�p���~�[.B) then
	errpassXSW32_�X�g�b�p���~�[=ON
	almXSW32_�X�g�b�p���~�[=ON
	�W�킹���j�b�gErrStep=1

else if ldp(tim_XSW33_�X�g�b�p�㏸�[.B) then
	errpassXSW33_�X�g�b�p�㏸�[=ON
	pauseSV27_�X�g�b�p=ON
	almXSW33_�X�g�b�p�㏸�[=ON
	�W�킹���j�b�gErrStep=1
end if

end if
'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �W�킹���j�b�gAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �W�킹���j�b�gAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\
'System :: �W�킹���j�b�gEmg	���̏��~

if �W�킹���j�b�gEmgStep=0 then  
	
	if �W�킹���j�b�gErrStep=0  or errXSW40_�V�����_���~�[A then
	
	if not(�W�킹���j�b�gOrgErr) then

	if (�W�킹���j�b�gAutoMode and ��������AutoMode ) or �W�킹���j�b�gstep<>0 then
		
		if not(�W�킹���j�b�gAutoMode and ��������AutoMode ) then
			�W�킹���j�b�gAutoRun=OFF
		end if
		

	'===================================================================================================================
	'�y �v���Z�X���� �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case �W�킹���j�b�gstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
			�W�킹���j�b�gStatusMsg=#0

		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' ��ƍH����U�蕪����
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �W�킹���j�b�gAutoRun then
				if XSW39_�V�����_�㏸�[A and XSW41_�V�����_�㏸�[B and XSW43_�N�����v then
					�t�^�킹�t�^��蒆=ON
				else				
					�t�^�킹�t�^��蒆=OFF
				end if
			
				inc(�W�킹���j�b�gstep)
			else 
				�W�킹���j�b�gstep=0 '�I���ҋ@
			end if

		case 2
		' [ �W�J�}�ړ���~�m�F ]
			if �W�킹���j�b�g�r�o�v��=OFF and  �����R���x�AC���쒆=OFF then

				'[ ���X�e�[�W��"��"�L���o ]
					if PH19_�����m and PH20_�t�^���m then
						�W�킹���j�b�gStatusMsg=#42	'	�t�^�u����
						inc(�W�킹���j�b�gstep) '�t�^�킹
						
				'[ ���X�e�[�W��"�t�^"�L���o ]	
					else if not(PH19_�����m) and PH20_�t�^���m then 
							�W�킹���j�b�gStatusMsg=#40	'	�t�^��蒆
							inc(�W�킹���j�b�gstep) '�t�^���
				
				'[ ���X�e�[�W��"���t�^"�Ȃ� ]
						else
							�W�킹���j�b�g�r�o�v��=ON
							�W�킹���j�b�gstep=1  '�I��
					end if
			
			else
			
				�W�킹���j�b�gstep=1
			
			end if
		
		case 3
		' [ ���j�b�g�����o ]
			if �W�킹���j�b�g���� then
				inc(�W�킹���j�b�gstep)
			else
				�W�킹���j�b�g�r�o�v��=ON
				�W�킹���j�b�gstep=1
			end if
		
		case 4
			if XSW39_�V�����_�㏸�[A and XSW41_�V�����_�㏸�[B then '���_
				�W�킹���j�b�gstep=100 '�v���Z�X����
			else
				�W�킹���j�b�gstep=1
			end if
			
		'--------------------------------------------------------------------------------------------------------------
		'�v���Z�X����
		case 100
			if �t�^�킹���� then '�����ړ���OFF
				�W�킹���j�b�g�r�o�v��=ON
				�W�킹���j�b�gstep=1
			else
				if �t�^�킹�t�^��蒆 and  PH19_�����m and PH20_�t�^���m then
					inc(�W�킹���j�b�gstep) '�t�^�킹����
				else if not(�t�^�킹�t�^��蒆) and  not(PH19_�����m) and PH20_�t�^���m then
					�W�킹���j�b�gstep=150 '�t�^��菈��
				else
					�W�킹���j�b�g�r�o�v��=ON
					�W�킹���j�b�gstep=1
				end if
			end if

		'------------------------------------------------------
		case 101  '�t�^�킹 (�A���N�����v�j
			mSV34_�V�����_�㏸A=OFF
			mSV35_�V�����_���~A=OFF
			mSV36_�V�����_�㏸B=OFF
			mSV37_�V�����_���~B=OFF
			mSV38_�N�����v=OFF
			mSV39_�A���N�����v=OFF

			
			inc(�W�킹���j�b�gstep)

		'------------------------------------------------------
		case 102
			mSV35_�V�����_���~A=ON
			errpassXSW40_�V�����_���~�[A=OFF
			inc(�W�킹���j�b�gstep)

		case 103
			if errpassXSW40_�V�����_���~�[A or  XSW40_�V�����_���~�[A then
				inc(�W�킹���j�b�gstep)
			end if
		
		case 104
			mSV35_�V�����_���~A=OFF
			tim_procstep_val=5
			res(tim_procstep)
			inc(�W�킹���j�b�gstep)
		
		case 105
			if tim_procstep.B then
				inc(�W�킹���j�b�gstep)
			end if
		
		case 106
			'-- errpassXSW40_�V�����_���~�[A  �̏ꍇ�̓N�����v���O���Ȃ� --
			if not(errXSW40_�V�����_���~�[A) then
				mSV39_�A���N�����v=ON	
				errpassXSW44_�A���N�����v=OFF
				inc(�W�킹���j�b�gstep)
			else
				inc(�W�킹���j�b�gstep)
			end if				
		
		case 107
			if not(errXSW40_�V�����_���~�[A) then		
				if errpassXSW44_�A���N�����v or XSW44_�A���N�����v then
					inc(�W�킹���j�b�gstep)
				end if
			else
				inc(�W�킹���j�b�gstep)		
			end if
		
		case 108
			mSV39_�A���N�����v=OFF
			tim_procstep_val=0 '�A���N�����v�ҋ@����
			res(tim_procstep)
			inc(�W�킹���j�b�gstep)
		
		case 109
			if tim_procstep.B then
				inc(�W�킹���j�b�gstep)
			end if
		
		case 110
			mSV34_�V�����_�㏸A=ON
			errpassXSW39_�V�����_�㏸�[A=OFF
			inc(�W�킹���j�b�gstep)

		case 111
			if errpassXSW39_�V�����_�㏸�[A or XSW39_�V�����_�㏸�[A then
				inc(�W�킹���j�b�gstep)
			end if
		
		case 112
			mSV34_�V�����_�㏸A=OFF
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W�킹���j�b�gstep)
			
		
		case 113
			if tim_procstep.B then
				if not(errXSW40_�V�����_���~�[A) then					
					�t�^�킹�t�^��蒆=OFF
				end if
				inc(�W�킹���j�b�gstep)
			end if
		
		case 114
			if errXSW40_�V�����_���~�[A then
				errXSW40_�V�����_���~�[A=OFF
			else
				RetryMode=OFF
				�t�^�킹����=ON
				�W�킹���j�b�g�r�o�v��=ON
			end if
			�W�킹���j�b�gstep=1
		'------------------------------------------------------
		case 150 '�t�^���  �i�N�����v�j
			mSV34_�V�����_�㏸A=OFF
			mSV35_�V�����_���~A=OFF
			mSV36_�V�����_�㏸B=OFF
			mSV37_�V�����_���~B=OFF
			mSV38_�N�����v=OFF
			mSV39_�A���N�����v=OFF
			inc(�W�킹���j�b�gstep)

		case 151
			mSV39_�A���N�����v=ON	
			errpassXSW44_�A���N�����v=OFF
			inc(�W�킹���j�b�gstep)

		case 152
			if errpassXSW44_�A���N�����v or XSW44_�A���N�����v then
				inc(�W�킹���j�b�gstep)
			end if
		
		case 153
			mSV39_�A���N�����v=OFF
			tim_procstep_val=0 '�A���N�����v�ҋ@����
			res(tim_procstep)
			inc(�W�킹���j�b�gstep)


		case 154
			if tim_procstep.B then
				if XSW39_�V�����_�㏸�[A and XSW41_�V�����_�㏸�[B then '���_
					if XSW44_�A���N�����v then
						inc(�W�킹���j�b�gstep)
					else
						�W�킹���j�b�gOrgErr=ON
					end if
				else
					�W�킹���j�b�gOrgErr=ON
				end if
			end if


		case 155
			mSV35_�V�����_���~A=ON
			mSV37_�V�����_���~B=ON
			errpassXSW40_�V�����_���~�[A=OFF
			inc(�W�킹���j�b�gstep)

		case 156
			if errpassXSW40_�V�����_���~�[A or XSW40_�V�����_���~�[A then
				mSV35_�V�����_���~A=OFF
				inc(�W�킹���j�b�gstep)
			end if		
		
		case 157
			if XSW42_�V�����_���~�[B then
				mSV37_�V�����_���~B=OFF
				inc(�W�킹���j�b�gstep)
			end if

		case 158
			tim_procstep_val=2
			res(tim_procstep)
			inc(�W�킹���j�b�gstep)		

		case 159
			if tim_procstep.B then
				inc(�W�킹���j�b�gstep)
			end if
		
		case 160
			mSV38_�N�����v=ON
			errpassXSW43_�N�����v=OFF
			inc(�W�킹���j�b�gstep)
		
		case 161
			if errpassXSW43_�N�����v or XSW43_�N�����v then
				inc(�W�킹���j�b�gstep)
			end if
		
		case 162
			mSV38_�N�����v=OFF
			inc(�W�킹���j�b�gstep)

		case 163
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W�킹���j�b�gstep)				

		case 164
			if tim_procstep.B then
				inc(�W�킹���j�b�gstep)
			end if

		case 165
			mSV27_�X�g�b�p=OFF
			errpassXSW32_�X�g�b�p���~�[=OFF
			mSV26_�N�����v=OFF
			errpassXSW30_�N�����v���~�[=OFF
			inc(�W�킹���j�b�gstep)
		
		case 166
			if (errpassXSW32_�X�g�b�p���~�[ or ((XSW32_�X�g�b�p���~�[ and not(pnlPBXSW32_�X�g�b�p���~�[)) or passXSW32_�X�g�b�p���~�[)) and (errpassXSW30_�N�����v���~�[ or ((XSW30_�N�����v���~�[ and not(pnlPBXSW30_�N�����v���~�[)) or passXSW30_�N�����v���~�[)) then
				inc(�W�킹���j�b�gstep)
			end if

		
		case 167
			mSV36_�V�����_�㏸B=ON
			mSV34_�V�����_�㏸A=ON
			errpassXSW41_�V�����_�㏸�[B=OFF
			errpassXSW39_�V�����_�㏸�[A=OFF
			inc(�W�킹���j�b�gstep)

		case 168
			if errpassXSW41_�V�����_�㏸�[B or XSW41_�V�����_�㏸�[B then
				mSV36_�V�����_�㏸B=OFF
				inc(�W�킹���j�b�gstep)
			end if
		
		case 169
			if errpassXSW39_�V�����_�㏸�[A or XSW39_�V�����_�㏸�[A then
				mSV34_�V�����_�㏸A=OFF
				inc(�W�킹���j�b�gstep)
			end if

		case 170
			
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W�킹���j�b�gstep)

		case 171
			if tim_procstep.B then
				�t�^�킹�t�^��蒆=ON
				inc(�W�킹���j�b�gstep)
			end if

		case 172
			if errpassXSW40_�V�����_���~�[A then
				errpassXSW40_�V�����_���~�[A=OFF
			end if
			
			�t�^�킹����=ON
			�W�킹���j�b�g�r�o�v��=ON
			�W�킹���j�b�gstep=1
		end select

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		�W�킹���j�b�gAutoRun=OFF
		
		�W�킹���j�b�gstep=0 '�I��
		�t�^�킹����=OFF
		

		res(tim_XSW39_�V�����_�㏸�[A)
		res(tim_XSW40_�V�����_���~�[A)
		res(tim_XSW41_�V�����_�㏸�[B)
		res(tim_XSW42_�V�����_���~�[B)
		res(tim_XSW43_�N�����v)
		res(tim_XSW44_�A���N�����v)

		'------------------------------------------------------
		if ldp(pnlPBSV34_�V�����_�㏸A or pnlPBSV35_�V�����_���~A) and (XSW44_�A���N�����v or (XSW43_�N�����v and ((XSW32_�X�g�b�p���~�[ and not(pnlPBXSW32_�X�g�b�p���~�[)) or passXSW32_�X�g�b�p���~�[ ) and  ((XSW30_�N�����v���~�[ and not(pnlPBXSW30_�N�����v���~�[)) or passXSW30_�N�����v���~�[)) ) then
			if XSW39_�V�����_�㏸�[A then
				mSV35_�V�����_���~A=ON
				mSV34_�V�����_�㏸A=OFF
			else if XSW40_�V�����_���~�[A then
				mSV35_�V�����_���~A=OFF
				mSV34_�V�����_�㏸A=ON
			else
				mSV35_�V�����_���~A=OFF
				mSV34_�V�����_�㏸A=ON			
			end if
		end if
		if mSV35_�V�����_���~A and XSW40_�V�����_���~�[A then
			mSV35_�V�����_���~A=OFF
		end if
		if mSV34_�V�����_�㏸A and XSW39_�V�����_�㏸�[A then
			mSV34_�V�����_�㏸A=OFF
		end if
		'------------------------------------------------------
		if ldp(pnlPBSV36_�V�����_�㏸B or pnlPBSV37_�V�����_���~B) and (XSW44_�A���N�����v or (XSW43_�N�����v and ((XSW32_�X�g�b�p���~�[ and not(pnlPBXSW32_�X�g�b�p���~�[)) or passXSW32_�X�g�b�p���~�[ ) and  ((XSW30_�N�����v���~�[ and not(pnlPBXSW30_�N�����v���~�[)) or passXSW30_�N�����v���~�[)) ) then
			if XSW41_�V�����_�㏸�[B then
				mSV37_�V�����_���~B=ON
				mSV36_�V�����_�㏸B=OFF
			else if XSW42_�V�����_���~�[B then
				mSV37_�V�����_���~B=OFF
				mSV36_�V�����_�㏸B=ON
			else
				mSV37_�V�����_���~B=OFF
				mSV36_�V�����_�㏸B=ON			
			end if
		end if
		if mSV37_�V�����_���~B and XSW42_�V�����_���~�[B then
			mSV37_�V�����_���~B=OFF
		end if
		if mSV36_�V�����_�㏸B and XSW41_�V�����_�㏸�[B then
			mSV36_�V�����_�㏸B=OFF
		end if
		'------------------------------------------------------
		if ldp(pnlPBSV38_�N�����v or pnlPBSV39_�A���N�����v) then
			if XSW44_�A���N�����v then
				mSV38_�N�����v=ON
				mSV39_�A���N�����v=OFF
				
				�t�^�킹�t�^��蒆=ON

			else if XSW43_�N�����v then
				mSV38_�N�����v=OFF
				mSV39_�A���N�����v=ON
				
				�t�^�킹�t�^��蒆=OFF
			else
				mSV38_�N�����v=OFF
				mSV39_�A���N�����v=ON
				
				�t�^�킹�t�^��蒆=OFF			
			
			end if
		end if
		if mSV39_�A���N�����v and XSW44_�A���N�����v then
			mSV39_�A���N�����v=OFF
		end if
		if mSV38_�N�����v and XSW43_�N�����v then
			mSV38_�N�����v=OFF
		end if
		'------------------------------------------------------

	end if '�W�킹���j�b�gAutoMode
	'===================================================================================================================
	'�y �W�킹���j�b�gOrgErr���� �z
	else
	
		res(tim_XSW39_�V�����_�㏸�[A)
		res(tim_XSW40_�V�����_���~�[A)
		res(tim_XSW41_�V�����_�㏸�[B)
		res(tim_XSW42_�V�����_���~�[B)
		res(tim_XSW43_�N�����v)
		res(tim_XSW44_�A���N�����v)
		
		if ResetFlg then
			�W�킹���j�b�gOrgErr=OFF
		end if

	end if	
	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
		'res(tim_XSW30_�N�����v���~�[)
		'res(tim_XSW32_�X�g�b�p���~�[)
		res(tim_XSW39_�V�����_�㏸�[A)
		res(tim_XSW40_�V�����_���~�[A)
		res(tim_XSW41_�V�����_�㏸�[B)
		res(tim_XSW42_�V�����_���~�[B)
		res(tim_XSW43_�N�����v)
		res(tim_XSW44_�A���N�����v)


		if �t�^�킹�t�^��蒆 then

			select case �W�킹���j�b�gErrStep
			case 0
			'------------------------------------------------------------------
			case 1
				if ResetFlg then
					'almXSW30_�N�����v���~�[=OFF
					'almXSW32_�X�g�b�p���~�[=OFF

					almXSW39_�V�����_�㏸�[A=OFF
					almXSW40_�V�����_���~�[A=OFF
					almXSW41_�V�����_�㏸�[B=OFF
					almXSW42_�V�����_���~�[B=OFF
					almXSW43_�N�����v=OFF
					almXSW44_�A���N�����v=OFF
					
					almXSW30_�N�����v���~�[=OFF
					almXSW31_�N�����v�㏸�[=OFF
					almXSW32_�X�g�b�p���~�[=OFF
					almXSW33_�X�g�b�p�㏸�[=OFF


					pauseSV26_�N�����v=OFF
					pauseSV27_�X�g�b�p=OFF

					inc(�W�킹���j�b�gErrStep)
				end if
			case 2
				if RetryMode then
					RetryMode=OFF
					inc(�W�킹���j�b�gErrStep)
				else
					RetryMode=ON
					inc(�W�킹���j�b�gErrStep)
				end if

			case 3
				if RetryMode and �W�킹���j�b�gstep<100 then '�W�킹���j�b�gstep�� 0�܂���1�Ńv���Z�X���I�����Ă��邱��
					�W�킹���j�b�gstep=101
				end if
				inc(�W�킹���j�b�gErrStep)
			'------------------------------------------------------------------
			case 4
				�W�킹���j�b�gErr=OFF
				�W�킹���j�b�gErrStep=0
			
			end select
		
		else
			�W�킹���j�b�gErr=ON

			select case �W�킹���j�b�gErrStep
			case 0
			case 1
				if ResetFlg then
					
					'almXSW30_�N�����v���~�[=OFF
					'almXSW32_�X�g�b�p���~�[=OFF
					
					almXSW39_�V�����_�㏸�[A=OFF
					almXSW40_�V�����_���~�[A=OFF
					almXSW41_�V�����_�㏸�[B=OFF
					almXSW42_�V�����_���~�[B=OFF
					almXSW43_�N�����v=OFF
					almXSW44_�A���N�����v=OFF

					almXSW30_�N�����v���~�[=OFF
					almXSW31_�N�����v�㏸�[=OFF
					almXSW32_�X�g�b�p���~�[=OFF
					almXSW33_�X�g�b�p�㏸�[=OFF

					
					inc(�W�킹���j�b�gErrStep)
				end if
			case 2
				�W�킹���j�b�gErr=OFF
				�W�킹���j�b�gErrStep=0
			end select
		
		end if

	end if 'if �W�킹���j�b�gErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	select case �W�킹���j�b�gEmgStep
	case 0
	
	case 1
		�W�킹���j�b�gAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�W�킹���j�b�gAutoMode and ��������AutoMode ) or �W�킹���j�b�gstep<>0 then
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
			mSV35_�V�����_���~A=OFF
			mSV34_�V�����_�㏸A=OFF
			mSV37_�V�����_���~B=OFF
			mSV36_�V�����_�㏸B=OFF
			mSV38_�N�����v=OFF
			mSV39_�A���N�����v=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�W�킹���j�b�gEmgStep)
	case 2
		if ResetFlg then
			inc(�W�킹���j�b�gEmgStep)
		end if
	case 3
		if (�W�킹���j�b�gAutoMode and ��������AutoMode ) or �W�킹���j�b�gstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				tim_procstep.U=tim_procstep_stack
				
				'---------------------------------
				inc(�W�킹���j�b�gEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�W�킹���j�b�gEmgStep)		
		end if				
	case 4
		timstack=OFF
		�W�킹���j�b�gEmgStep=0
		�W�킹���j�b�gEmg=OFF
	end select
		
end if 'if �W�킹���j�b�gEmgStep=0 then
