'IH���у��j�b�gB
'===================================================================================================================

' �{�v���O�����̓T���v���ł��B

'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'IH���у��j�b�gB
' [Rx ]---------------------------------
adrset(R48400,pinB�I�����C��.D)
adrset(R48401,pinB�ُ�.D)
adrset(R48402,pinB���쒆.D)
adrset(R48403,pinB�����R�}���h��t�\.D)
adrset(R48404,pinB������t�\.D)
adrset(R48405,pinB���o�v��.D)
adrset(R48406,pinB�������Z���T.D)
adrset(R48407,pinB���o���Z���T.D)
adrset(R48408,pinB���o�R�}���h��t�\.D)

adrset(R48500,pinB�R�}���h��������.D)
adrset(R48501,pinB�Ǐo�����ݒ�.D)
' [Ry ]---------------------------------
adrset(R52400,poutB����~�w��.D)
adrset(R52401,poutB�����w��.D)
adrset(R52402,poutB���o�w��.D)

adrset(R52500,poutB�R�}���h�����v��.D)
adrset(R52501,poutB�Ǐo�����ݒ�.D)
' [Wr ]---------------------------------
adrset(DM12132,pinU���o�A�C�e��NO.D)
adrset(DM12133,pinU���o��NO.D)
adrset(DM12134,pinU�ʂ�No.D)
adrset(DM12135,pinD�|�d��.D)

adrset(DM12137,pinD���f�[�^.D)


adrset(DM12140,pinU�A�C�e���o�^CH1.D)
adrset(DM12141,pinU�A�C�e���o�^CH2.D)
adrset(DM12142,pinU�A�C�e���o�^CH3.D)
adrset(DM12143,pinU�A�C�e���o�^CH4.D)
adrset(DM12144,pinU�A�C�e���o�^CH5.D)
adrset(DM12145,pinU�A�C�e���o�^CH6.D)
adrset(DM12146,pinU�A�C�e���o�^CH7.D)
adrset(DM12147,pinU�R�}���hNo����.D)
adrset(DM12148,pinU�R�}���h�f�[�^0.D)
adrset(DM12149,pinU�R�}���h�f�[�^1.D)
adrset(DM12150,pinU�R�}���h�f�[�^2.D)
adrset(DM12151,pinU�R�}���h�f�[�^3.D)
adrset(DM12152,pinU�R�}���h�f�[�^4.D)
adrset(DM12153,pinU�R�}���h�f�[�^5.D)
adrset(DM12154,pinU�R�}���h�f�[�^6.D)
adrset(DM12155,pinU�R�}���h�f�[�^7.D)
adrset(DM12156,pinU�R�}���h�f�[�^8.D)
adrset(DM12157,pinU�R�}���h�f�[�^9.D)
adrset(DM12158,pinU�R�}���h�f�[�^10.D)
adrset(DM12159,pinU�R�}���h�f�[�^11.D)
adrset(DM12160,pinU�R�}���h�f�[�^12.D)
adrset(DM12161,pinU�R�}���h�f�[�^13.D)
adrset(DM12162,pinU�R�}���h�f�[�^14.D)
adrset(DM12163,pinU�R�}���h�f�[�^15.D)
' [Ww ]---------------------------------
adrset(DM12644,poutU�����A�C�e��NO.D)
adrset(DM12645,poutU������NO.D)
adrset(DM12646,poutU�ʂ�No.D)
adrset(DM12647,poutD�|�d��.D)

adrset(DM12649,poutD���f�[�^.D)


adrset(DM12659,poutU�R�}���hNo.D)
adrset(DM12660,poutU�R�}���h�f�[�^0.D)
adrset(DM12661,poutU�R�}���h�f�[�^1.D)
adrset(DM12662,poutU�R�}���h�f�[�^2.D)
adrset(DM12663,poutU�R�}���h�f�[�^3.D)
adrset(DM12664,poutU�R�}���h�f�[�^4.D)
adrset(DM12665,poutU�R�}���h�f�[�^5.D)
adrset(DM12666,poutU�R�}���h�f�[�^6.D)
adrset(DM12667,poutU�R�}���h�f�[�^7.D)
adrset(DM12668,poutU�R�}���h�f�[�^8.D)
adrset(DM12669,poutU�R�}���h�f�[�^9.D)
adrset(DM12670,poutU�R�}���h�f�[�^10.D)
adrset(DM12671,poutU�R�}���h�f�[�^11.D)
adrset(DM12672,poutU�R�}���h�f�[�^12.D)
adrset(DM12673,poutU�R�}���h�f�[�^13.D)
adrset(DM12674,poutU�R�}���h�f�[�^14.D)
adrset(DM12675,poutU�R�}���h�f�[�^15.D)
' --------------------------------------
'------------------------------------------------------------------
' IH���у��j�b�g�A���e�X�g�v���O����
'------------------------------------------------------------------
if 0 then
	if *pinB�����R�}���h��t�\.B and *pinB������t�\.B then
	
		if IH���у��j�b�g����step=0 then
			IH���у��j�b�g����step=1
		end if
			
	end if
	
	
	if *pinB���o�R�}���h��t�\.B and *pinB���o�v��.B then
		if IH���у��j�b�g���ostep=0 then
			IH���у��j�b�g���ostep=1
		end if
	end if
	
end if


'===================================================================================================================
'�y ���������� �z
if CR2008 then
    IH���у��j�b�gBAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    IH���у��j�b�gBAutoRun=OFF
    IH���у��j�b�gB����=ON
    IH���у��j�b�gBOrgErr=OFF
    IH���у��j�b�gBErr=OFF
    IH���у��j�b�gBEmg=OFF
    IH���у��j�b�gBstep=0
    IH���у��j�b�gBErrStep=0
    IH���у��j�b�gBOrgErrStep=0
    IH���у��j�b�gBEmgStep=0
	
	IH���у��j�b�g����step=0
	IH���у��j�b�g���ostep=0
	

end if
'===================================================================================================================
'�y ���_ �z
IH���у��j�b�gBOrg=IH���ы@B�֎~ or (*pinB�I�����C��.B and *pinB�ُ�.B)

if ��������AutoRun and not(IH���ы@B�֎~) and ldp(not(*pinB�I�����C��.B) or not(*pinB�ُ�.B)) then
	almIH���ы@B=ON
	IH���у��j�b�gBErrStep=1

else if ldp(ResetFlg) and almIH���ы@B=ON then
	almIH���ы@B=OFF
	IH���у��j�b�gBErrStep=0

end if


'*****************************************************************
if 0 then
'*****************************************************************


'===================================================================================================================
'�y �ً}��~ �z

'if not(PB����~) then
'	IH���у��j�b�gBEmg=ON
'	IH���у��j�b�gBEmgStep=1
'	*poutB����~�w��.B=ON
'else
'	*poutB����~�w��.B=OFF
'end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
tmr(**poutB�R�}���h�����v��.B,tim_�R�}���h�����v��,#200)
tmr(*poutB�����w��.B,tim_�����w��,#200)
tmr(*poutB���o�w��.B,tim_���o�w��,#200)

if ldp(tim_�R�}���h�����v��) then
	errpass�R�}���h�����v��=ON
	*poutB�R�}���h�����v��.B=OFF
	IH���у��j�b�gBErrStep=1

else if ldp(tim_�����w��.B) then
	errpass�����w��=ON
	*poutB�����w��.B=OFF
	IH���у��j�b�gBErrStep=1

else if ldp(tim_���o�w��.B) then
	errpass���o�w��=ON
	*poutB���o�w��.B=OFF
	IH���у��j�b�gBErrStep=1

end if

'===================================================================================================================

'------------------------------------------------------------------
' IH���у��j�b�g����
'------------------------------------------------------------------
tmr(tim_IH���у��j�b�g����,tim_IH���у��j�b�g����_val)
select case IH���у��j�b�g����step
case 0
case 1
	if *pinB�I�����C��.B and *pinB�ُ�.B then
		inc(IH���у��j�b�g����step)
	else
		IH���у��j�b�g����step=0
	end if

case 2
	if *pinB�����R�}���h��t�\.B and *pinB������t�\.B then
		inc(IH���у��j�b�g����step)
	else
		IH���у��j�b�g����step=0
	end if

case 3
	'-----------------------------------
	'���эH���f�[�^
	*poutU�����A�C�e��NO.U=�����A�C�e��NOB '��  99
	if �����A�C�e��NOB<99 then
		inc(IH�������ъ��J�E���g)
	end if
	'-----------------------------------
	'�������ɑ΂��Ẵ��x�����O
	*poutU������NO.U=*poutU������NO.U+1
	*poutU�ʂ�No.U=*poutU�ʂ�No.U+1
	*poutD�|�d��.D=0
	*poutD���f�[�^.D=0
	'-----------------------------------
	*poutB�����w��.B=ON
	errpass�����w��=OFF
	inc(IH���у��j�b�g����step)

case 4
	if not(*pinB�����R�}���h��t�\.B) or errpass�����w�� then
		inc(IH���у��j�b�g����step)
	end if

case 5
	if errpass�����w�� then
		IH���у��j�b�g����step=0
	else
		*poutB�����w��.B=OFF
		inc(IH���у��j�b�g����step)
	end if
	
'
'case x 	
'	�R���x�A���[��=ON
'	inc(IH���у��j�b�g����step)
'case x
'	if *pinB���쒆.B then
'		inc(IH���у��j�b�g����step)
'	end if
'
'case x
'	if not(*pinB���쒆.B) and *pinB�������Z���T.B then
'		�R���x�A���[��=OFF
'		inc(IH���у��j�b�g����step)	
'   end if
'
case 6
	if not(*pinB������t�\.B) then
		inc(IH���у��j�b�g����step)
	end if

case 7
	if *pinB������t�\.B then
		inc(IH���у��j�b�g����step)
	end if

case 8
	IH���у��j�b�g����step=0
	
end select

'------------------------------------------------------------------
' IH���у��j�b�g���o
'------------------------------------------------------------------
tmr(tim_IH���у��j�b�g���o,tim_IH���у��j�b�g���o_val)
select case IH���у��j�b�g���ostep
case 0
case 1
	if *pinB�I�����C��.B and *pinB�ُ�.B then
		inc(IH���у��j�b�g���ostep)
	else
		IH���у��j�b�g���ostep=0
	end if

case 2
	if *pinB���o�R�}���h��t�\.B and *pinB���o�v��.B then
		inc(IH���у��j�b�g���ostep)
	else
		IH���у��j�b�g���ostep=0
	end if

case 3
	*poutB���o�w��.B=ON
	errpass���o�w��=OFF
	inc(IH���у��j�b�g���ostep)

case 4
	if not(*pinB���o�R�}���h��t�\.B) or errpass���o�w�� then
		inc(IH���у��j�b�g���ostep)
	end if

case 5
	if errpass���o�w�� then
		IH���у��j�b�g���ostep=0
	else
		*poutB���o�w��.B=OFF
		inc(IH���у��j�b�g���ostep)
	end if
'
'case x 	
'	�R���x�A���[��=ON
'	inc(IH���у��j�b�g���ostep)
'case x
'	if not(*pinB���o�v��.B) then
'		inc(IH���у��j�b�g���ostep)
'	end if
'
'case x
'	if 	PH25_�����m then
'		�R���x�A���[��=OFF
'		inc(IH���у��j�b�g���ostep)
'	 end if
case 6
	���o�A�C�e��NOB=*pinU���o�A�C�e��NO.U '��  99

	if IH�������ъ��J�E���g>0 and ���o�A�C�e��NOB<99 then
		dec(IH�������ъ��J�E���g)
	end if
	
	IH���у��j�b�g���ostep=0
	
end select
'------------------------------------------------------------------




	
'===================================================================================================================

if IH���у��j�b�gBEmgStep=0 then  
	
	if IH���у��j�b�gBErrStep=0 then
	
	if not(IH���у��j�b�gBOrgErr) then

	if (IH���у��j�b�gBAutoMode and ��������AutoMode ) or IH���у��j�b�gBstep<>0 or IH���у��j�b�g����step<>0 or IH���у��j�b�g���ostep<>0 then
		
		if not(IH���у��j�b�gBAutoMode and ��������AutoMode ) then
			IH���у��j�b�gBAutoRun=OFF
		end if


	'===================================================================================================================
	'�y �v���Z�X���� �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case IH���у��j�b�gBstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
			IH���у��j�b�gBStatusMsg=#0

		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' ��ƍH����U�蕪����
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if IH���у��j�b�gBAutoRun then				
				inc(IH���у��j�b�gBstep)
			else 
				IH���у��j�b�gBstep=0 '�I���ҋ@
			end if

		case 2
		' [ �W�J�}�ړ���~�m�F ]
			if IH���у��j�b�gB�r�o�v��=OFF and  �����R���x�AC���쒆=OFF then

				'[ ���X�e�[�W��"��"�L���o ]
					if PH19_�����m and PH20_�t�^���m then
						IH���у��j�b�gBStatusMsg=#42	'	�t�^�u����
						inc(IH���у��j�b�gBstep) '�t�^�킹
						
				'[ ���X�e�[�W��"�t�^"�L���o ]	
					else if not(PH19_�����m) and PH20_�t�^���m then 
							IH���у��j�b�gBStatusMsg=#40	'	�t�^��蒆
							inc(IH���у��j�b�gBstep) '�t�^���
				
				'[ ���X�e�[�W��"���t�^"�Ȃ� ]
						else
							IH���у��j�b�gB�r�o�v��=ON
							IH���у��j�b�gBstep=1  '�I��
					end if
			
			else
			
				IH���у��j�b�gBstep=1
			
			end if
		
		case 3
		' [ ���j�b�g�����o ]
			if IH���у��j�b�gB���� then
				IH���у��j�b�gBstep=100 '�v���Z�X����
			else
				IH���у��j�b�gB�r�o�v��=ON
				IH���у��j�b�gBstep=1
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		'�v���Z�X����
		case 100
			if �t�^�킹���� then '�����ړ���OFF
				IH���у��j�b�gB�r�o�v��=ON
				IH���у��j�b�gBstep=1
			else
				if �t�^�킹�t�^��蒆 and  PH19_�����m and PH20_�t�^���m then
					inc(IH���у��j�b�gBstep) '�t�^�킹����
				else if not(�t�^�킹�t�^��蒆) and  not(PH19_�����m) and PH20_�t�^���m then
					IH���у��j�b�gBstep=150 '�t�^��菈��
				else
					IH���у��j�b�gB�r�o�v��=ON
					IH���у��j�b�gBstep=1
				end if
			end if

		'------------------------------------------------------
		end select

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		IH���у��j�b�gBAutoRun=OFF
		
		IH���у��j�b�gBstep=0 '�I��

		'------------------------------------------------------
	end if 'IH���у��j�b�gBAutoMode
	'===================================================================================================================
	'�y IH���у��j�b�gBOrgErr���� �z
	else
		
		if ResetFlg then
			IH���у��j�b�gBOrgErr=OFF
		end if

	end if

	
	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else

		IH���у��j�b�gBErr=ON

		select case IH���у��j�b�gBErrStep
		case 0
		case 1
			if ResetFlg then
				
				inc(IH���у��j�b�gBErrStep)
			end if
		case 2
			�p�����[�^������step=0
			IH���у��j�b�g����step=0
			IH���у��j�b�g���ostep=0
			IH���у��j�b�gBErr=OFF
			IH���у��j�b�gBErrStep=0
		end select
		

	end if 'if IH���у��j�b�gBErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	select case IH���у��j�b�gBEmgStep
	
	case 1
		IH���у��j�b�gBAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if IH���у��j�b�gBstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
		
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
		
			'---------------------------------
		end if
		
		'---------------------------------
		inc(IH���у��j�b�gBEmgStep)
	case 2
		if ResetFlg then
			inc(IH���у��j�b�gBEmgStep)
		end if
	case 3
		if  IH���у��j�b�gBstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				
				
				
				'---------------------------------
				inc(IH���у��j�b�gBEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(IH���у��j�b�gBEmgStep)		
		end if				
	case 4
		IH���у��j�b�gBEmgStep=0
		IH���у��j�b�gBEmg=OFF
	end select
		
end if 'if IH���у��j�b�gBEmgStep=0 then

'*****************************************************************
end if
'*****************************************************************
