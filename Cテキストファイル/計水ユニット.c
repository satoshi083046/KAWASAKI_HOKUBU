'�v�����j�b�g
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
' ���� 7.60 = 2.29 ��  2.20 / 2.29 * 7.60 = 7.30
'===================================================================================================================
'
'	�v�����j�b�g
'	
'PH52_�����m -> PH11__�����m
'PH53_�t�^���m -> PH12__�t�^���m
'
'===================================================================================================================
�q��R�[�h=���k��
'===================================================================================================================
select case �q��R�[�h

case ���암
'	ADRSET(PH52_�����m.B,pPH_�����m.D)
'	ADRSET(PH53_�t�^���m.B,pPH_�t�^���m.D)
'	ADRSET(�����r�o�v��.B,p�����r�o�v��.D)
	
case ���k��
	ADRSET(PH11_�����m.B,pPH_�����m.D)
	ADRSET(PH12_�t�^���m.B,pPH_�t�^���m.D)
	ADRSET(�v�����j�b�g�r�o�v��.B,p�����r�o�v��.D)

end select
'===================================================================================================================
'
'  ��  Modbsu�ʐM�Ōv����������������ݒ肷��B
'
'	setADR4532c1_Up	=DM_�v���ڕW���x (x: 1,2,3)
'	setADR4532c1_Low=DM_�v���ڕW����x (x: 1,2,3)
'
'	*����  ZERO�@�\�i�{�́A�O�ʃX�C�b�`�j  ZERO�X�C�b�`�������Ēl��0�ɂ��邱�Ƃ��ł��邪�A�ēd��������A0�ł͂Ȃ��l�����Ƃɖ߂�܂��B

'�z�čς݊��ւ̒���
	DM_�v���ڕW���1=DM_�v���ڕW����1+100	'���ʖ���
'	DM_�v���ڕW����1=1027					'���ʖ��� � (�ݒ�l�j
	DM_�v���ڕW���2=DM_�v���ڕW����2+100	'���ʒ���
	DM_�v���ڕW����2=(DM_�v���ڕW����1-100)	'���ʒ���
	DM_�v���ڕW���3=10	'�r��
	DM_�v���ڕW����3=-20




'�r��


	'�y�v�ʐ��d�ʁz

	if ��������AutoMode then
		'���X�e�[�W�̊���ITEMNO
		ThisItem=ANDA(StageDevice5,$FF)
		if 0<ThisItem and ThisItem<99 then
			ADRSET(EM1021.U,ptr�A�C�e���v�ʐ��d��)
			ADRADD(20 * (ThisItem-1),ptr�A�C�e���v�ʐ��d��)
		else
			ADRSET(R0,ptr�A�C�e���v�ʐ��d��)		
		end if
		
	else 
		'�}�j���A��
		if 0<DM_ITEMNO and DM_ITEMNO<99 then
			ADRSET(EM1021.U,ptr�A�C�e���v�ʐ��d��)
			ADRADD(20 * (DM_ITEMNO-1),ptr�A�C�e���v�ʐ��d��)
		else
			ADRSET(R0,ptr�A�C�e���v�ʐ��d��)					
		end if
	end if
	
	
	ADRSET(R0.U,ptrcheck)
	'�A�h���X���ݒ肳��Ă��邩���`�F�b�N����
	if ptrcheck<>ptr�A�C�e���v�ʐ��d�� then
		'���C��TP_�ؑփy�[�W�m��=160(��ʐݒ�ł͒����\)
		if ���C��TP_�ؑփy�[�W�m��<>160 then 
			DM_�v���ڕW����1=*ptr�A�C�e���v�ʐ��d��
		end if
	else
		DM_�v���ڕW����1=0
	end if
	
	tmDM_�v���ڕW����1�␳�l=0
	tmDM_�v���ڕW���1=tmDM_�v���ڕW����1+10
	tmDM_�v���ڕW����1=DM_�v���ڕW����1+tmDM_�v���ڕW����1�␳�l

'�󊘂ւ̒���
if 1 then
	DM_�󊘌v���ڕW���1=DM_�󊘌v���ڕW����1+100	'���ʖ���
	DM_�󊘌v���ڕW����1=DM_�󊘌v���ڕW����1		'���ʖ��� � (�ݒ�l�j
	DM_�󊘌v���ڕW���2=DM_�󊘌v���ڕW����2+100	'���ʒ���
	DM_�󊘌v���ڕW����2=DM_�󊘌v���ڕW����1-100 	'���ʒ���

	if DM_�󊘌v���ڕW����1<400 or DM_�󊘌v���ڕW����1>650 then
		if DM_�󊘌v���ڕW����1<400 then
			DM_�󊘌v���ڕW����1=400
		else if DM_�󊘌v���ڕW����1>650 then
			DM_�󊘌v���ڕW����1=650
		end if
	end if
end if


'�C���W�P�[�^�\���l
'
	DM_�v���ʌ��ݒl=getADR4532c1_Raw


	if DM_�v���ڕW����1>0 then
		if  DM_�v���ʌ��ݒl<10 then
			�����ʃO���t=0
		else if DM_�v���ʌ��ݒl>(DM_�v���ڕW����1-20) then
			�����ʃO���t=100
		else 	
			�����ʃO���t=(DM_�v���ʌ��ݒl*100) / DM_�v���ڕW����1
		end if	
	else
		'���т̐��� 650 �Ōv�Z
		if  DM_�v���ʌ��ݒl<10 then
			�����ʃO���t=0
		else if DM_�v���ʌ��ݒl>(650-20) then
			�����ʃO���t=100
		else 	
			�����ʃO���t=(DM_�v���ʌ��ݒl*100) / 650
		end if	
	end if	
	
'
'����  �r���o���u
'
'�����o���u
'	SV17_�v���^���N�����i��j
'	SV18_�v���^���N�����i���j
'�r���o���u
'	mSV19_�v���d����_A �J��
'	mSV64_�v���d����_B �� - 2017/7/5 �폜
'

'------------------------------------------------------------------------------------------------------------------
'AD4532 ZERO RESET 1.0S �����V���b�g

tmr(AD4532_ZERO,tim_AD4532_ZERO,10)
if AD4532_ZERO and not(tim_AD4532_ZERO.B) then
	AD4532_ZERO=ON
else
	AD4532_ZERO=OFF
end if

if not(SV17_�v���^���N�����i��j) and not(SV18_�v���^���N�����i���j) and not(SV19_�v���d����_A) then
	if ldp(pnlPBAD4532_ZERO) then
			AD4532_ZERO=ON
			res(tim_AD4532_ZERO)
	end if
end if

'===================================================================================================================
'

'�y ���������� �z
if CR2008 then
    �v�����j�b�gAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �v�����j�b�gAutoRun=OFF
    �v�����j�b�g����=ON
    �v�����j�b�gOrgErr=OFF
    �v�����j�b�gErr=OFF
    �v�����j�b�gEmg=OFF
    �v�����j�b�gstep=0
    �v�����j�b�gErrStep=0
    �v�����j�b�gOrgErrStep=0
    �v�����j�b�gEmgStep=0

	�v�������T�C�N��flg=OFF
	�v������step=0
	
	TestPass=0

end if
'===================================================================================================================
'�y ���_ �z
�v�����j�b�gOrg=not(�v�����j�b�g����) or 1

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�v�����j�b�gEmg=ON
	�v�����j�b�gEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

tmr(SV18_�v���^���N�����i���j ,tim_�v���^���N�����i���j,#1000)
tmr(SV17_�v���^���N�����i��j,tim_�v���^���N�����i��j,#1000)
tmr(SV19_�v���d����_A,tim_�v���d����_A,#1000)

if ldp(tim_�v���^���N�����i���j.B) then
	errpassSV18_�v���^���N�����i���j=ON
	almSV18_�v���^���N�����i���j=ON
	�v�����j�b�gErrStep=1

else if ldp(tim_�v���^���N�����i��j.B) then
	errpassSV17_�v���^���N�����i��j=ON
	almSV17_�v���^���N�����i��j=ON
	�v�����j�b�gErrStep=1

else if ldp(tim_�v���d����_A.B) then
	errpassSV17_�v���^���N�����i��j=ON
	errpassSV18_�v���^���N�����i���j=ON

	almSV19_�v���d����_A=ON
	�v�����j�b�gErrStep=1
end if
'===================================================================================================================
' PL�C���W�P�[�^
	if not(��������AutoMode) or not(�v�����j�b�gAutoMode) then
		PBL32_�v��= �v�������T�C�N��flg
	else
		PBL32_�v��=OFF
	end if

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �v�����j�b�gAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �v�����j�b�gAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\
'System :: �v�����j�b�gEmg	���̏��~

tmr(tim_TestPass,tim_TestPass_val) 

if �v�����j�b�gEmgStep=0 then  
	
	if �v�����j�b�gErrStep=0  then
	
	if not(�v�����j�b�gOrgErr) then


		'-----------------------------------------------------------------------------
		' �v��
		tmr(tim_�v������,tim_�v������_val)
		select case �v������step
		case 0
		case 1
			������������=OFF
			mSV19_�v���d����_A=OFF '�J��
			'mSV64_�v���d����_B=ON '��
			tim_�v������_val=#10
			res(tim_�v������)
			inc(�v������step)
		
		case 2
			if tim_�v������.B then
				inc(�v������step)
			end if

		case 3
			setADR4532c1_Low=DM_�󊘌v���ڕW����2
			setADR4532c1_Up=DM_�󊘌v���ڕW���2

			inc(�v������step)

		case 4
			if setADR4532c1_Low=getADR4532c1_Low and setADR4532c1_Up=getADR4532c1_Up then 
				inc(�v������step)
			end if

		case 5
			tim_�v������_val=#10 '�ʐM�҂�����
			res(tim_�v������)
			inc(�v������step)

		case 6
			if  tim_�v������.B then
				inc(�v������step)
			end if
		
		case 7
			mSV17_�v���^���N�����i��j=ON
			mSV18_�v���^���N�����i���j=ON
			errpassSV18_�v���^���N�����i���j=OFF 
			errpassSV17_�v���^���N�����i��j=OFF

			tim_TestPass_val=120
			res(tim_TestPass)

			inc(�v������step)
		
		case 8

			inc(�v������step)
		
		case 9
			if (TestPass and tim_TestPass.B) or errpassSV18_�v���^���N�����i���j or errpassSV17_�v���^���N�����i��j or AD4532_OK or AD4532_HI or DM_�v���ʌ��ݒl>setADR4532c1_Low then
				mSV17_�v���^���N�����i��j=OFF
				mSV18_�v���^���N�����i���j=OFF
				inc(�v������step)
			end if

		case 10
			setADR4532c1_Low=DM_�󊘌v���ڕW����1
			setADR4532c1_Up=DM_�󊘌v���ڕW���1

			inc(�v������step)

		case 11
			if setADR4532c1_Low=getADR4532c1_Low and setADR4532c1_Up=getADR4532c1_Up then 
				inc(�v������step)
			end if

		case 12
			tim_�v������_val=#3 '�ʐM�҂�����
			res(tim_�v������)
			inc(�v������step)

		case 13
			if  tim_�v������.B then
				inc(�v������step)
			end if

		case 14
			mSV17_�v���^���N�����i��j=OFF
			mSV18_�v���^���N�����i���j=ON
			errpassSV18_�v���^���N�����i���j=OFF 
			errpassSV17_�v���^���N�����i��j=OFF

			tim_TestPass_val=80
			res(tim_TestPass)
			inc(�v������step)
		
		case 15
			inc(�v������step)
		
		case 16
			if (TestPass and tim_TestPass.B) or errpassSV18_�v���^���N�����i���j or errpassSV17_�v���^���N�����i��j or AD4532_OK or AD4532_HI or DM_�v���ʌ��ݒl>setADR4532c1_Low then
				mSV17_�v���^���N�����i��j=OFF
				mSV18_�v���^���N�����i���j=OFF
				inc(�v������step)
			end if


		case 17
			tim_�v������_val=#10 'Wait
			res(tim_�v������)
			inc(�v������step)
		
		case 18
			if tim_�v������.B then
				inc(�v������step)
			end if

		case 19
			������������=ON
			�v������step=0

		end select

		'-----------------------------------------------------------------------------
		' ���ъ��̌v��
		tmr(tim_�v���ǉ�,tim_�v���ǉ�_val)
		select case �v���ǉ�step
		case 0

		case 1
			if DM_�v���ʌ��ݒl>=DM_�v���ڕW����1 then
				�v���ǉ�step=0
			else
				inc(�v���ǉ�step)
			end if

		
		case 2		
			setADR4532c1_Low=tmDM_�v���ڕW����1
			setADR4532c1_Up=tmDM_�v���ڕW���1
			inc(�v���ǉ�step)

		case 3
			if setADR4532c1_Low=getADR4532c1_Low and setADR4532c1_Up=getADR4532c1_Up then 
				inc(�v���ǉ�step)
			end if

		case 4
			tim_�v���ǉ�_val=#1 '�ʐM�҂�����
			res(tim_�v���ǉ�)
			inc(�v���ǉ�step)
		
		case 5
			if tim_�v���ǉ�.B then
				tim_TestPass_val=60
				res(tim_TestPass)
				inc(�v���ǉ�step)
			end if
		
		case 6
			mSV17_�v���^���N�����i��j=OFF
			mSV18_�v���^���N�����i���j=ON
			errpassSV18_�v���^���N�����i���j=OFF 
			errpassSV17_�v���^���N�����i��j=OFF
			inc(�v���ǉ�step)

		case 7
			if (TestPass and tim_TestPass.B) or errpassSV18_�v���^���N�����i���j or errpassSV17_�v���^���N�����i��j or AD4532_OK or AD4532_HI or DM_�v���ʌ��ݒl>setADR4532c1_Low then
				mSV17_�v���^���N�����i��j=OFF
				mSV18_�v���^���N�����i���j=OFF
				inc(�v���ǉ�step)
			end if


		case 8
			tim_�v���ǉ�_val=#10 'Wait
			res(tim_�v���ǉ�)
			inc(�v���ǉ�step)
		
		case 9
			if tim_�v���ǉ�.B then
				inc(�v���ǉ�step)
			end if
			
		case 10
			��������=��������+1
			�v���ǉ�step=0

		end select


	
	'===================================================================================================================
	'�y �v���Z�X�����i�z�āj �z
	'
	if (�v�����j�b�gAutoMode and ��������AutoMode) or �v�������T�C�N��flg or �v�����j�b�gstep<>0 then
	
		if not(�v�����j�b�gAutoMode and ��������AutoMode) then
			�v�����j�b�gAutoRun=OFF
		end if

		tmr(tim_procstep,tim_procstep_val)

		select case �v�����j�b�gstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' ��ƍH����U�蕪����
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �v�����j�b�gAutoRun then
				inc(�v�����j�b�gstep)
			else 
				�v�����j�b�gstep=0 '�I���ҋ@
			end if
		
		case 2
		' [ �H���������� ]
		 if �v�����j�b�g���� then

			if ������������ then
				inc(�v�����j�b�gstep)
			else
			 	if ANDA(ORA(ORA(ORA(StageDevice0,StageDevice1),StageDevice2),StageDevice3),$FF)>0 and ANDA(ORA(ORA(ORA(StageDevice0,StageDevice1),StageDevice2),StageDevice3),$FF)<99 then
					if �v������step=0 then
						�v������step=1
					end if
					inc(�v�����j�b�gstep)
				else
					*p�����r�o�v��.B=ON
					�v�����j�b�gstep=1				
				end if
			
			end if
		
		else
			if ������������ then
				inc(�v�����j�b�gstep)
			else
				*p�����r�o�v��.B=ON
				�v�����j�b�gstep=1
			end if
		end if
		
		case 3
		' [ �W�J�}�ړ���~�m�F ]
			if *p�����r�o�v��.B=OFF and  �����R���x�AA���쒆=OFF then

				'[ ���X�e�[�W��"��"�L���o ]
					if *pPH_�����m.B and *pPH_�t�^���m.B then
							�v�����j�b�gstep=100 '�v���Z�X����
						
				'[ ���X�e�[�W��"�t�^"�L���o ]	
					else if not(*pPH_�����m.B) and *pPH_�t�^���m.B then 
							*p�����r�o�v��.B=ON
							�v�����j�b�gstep=1
				
				'[ ���X�e�[�W��"���t�^"�Ȃ� ]
						else
							*p�����r�o�v��.B=ON
							�v�����j�b�gstep=1
					end if
			
			else
			
				�v�����j�b�gstep=1
			
			end if
		
		case 4
			�v�����j�b�gstep=100 '�v���Z�X����
		'--------------------------------------------------------------------------------------------------------------
		'�v���Z�X����
		case 100
			if �������� then '�����ړ���OFF
				�v�����j�b�gstep=199
				
			else if ������������  then

				if ANDA(StageDevice5,$200)=$200 or ANDA(StageDevice5,$400)=$400 or �v�������T�C�N��flg then '�z��A or �z��B
				 	���ъ��v������=ON
					inc(�v�����j�b�gstep)
				else
				 	���ъ��v������=OFF
					*p�����r�o�v��.B=ON
				 	�v�����j�b�gstep=1

				end if

			end if

		'-----------------------------------------------------------------------------
		case 101
			������������=OFF
			inc(�v�����j�b�gstep)
		
		'-----------------------------------------------------------------------------
		' ���ъ��ւ̐��ʒǉ�
		case 102
			if ���ъ��v������ then
				if �v���ǉ�step=0 then
					�v���ǉ�step=1
					inc(�v�����j�b�gstep)
				end if
			else
				inc(�v�����j�b�gstep)
			end if
		
		case 103
			if �v���ǉ�step=0 then
				inc(�v�����j�b�gstep)
			end if
		'-----------------------------------------------------------------------------
		' ���� �i���ւ̔r���j
		case 104
			setADR4532c1_Low=DM_�v���ڕW����3
			setADR4532c1_Up=DM_�v���ڕW���3

			mSV19_�v���d����_A=ON '�J��
			'mSV64_�v���d����_B=OFF '��
			errpassSV18_�v���^���N�����i���j=OFF 
			errpassSV17_�v���^���N�����i��j=OFF

			inc(�v�����j�b�gstep)

		case 105 
			if setADR4532c1_Low=getADR4532c1_Low and setADR4532c1_Up=getADR4532c1_Up then 
				inc(�v�����j�b�gstep)
			end if
			
		case 106
			tim_procstep_val=#1 '�ʐM�҂�����
			res(tim_procstep)
			inc(�v�����j�b�gstep)
		
		case 107
			if tim_procstep.B then
				tim_TestPass_val=80
				res(tim_TestPass)			
				inc(�v�����j�b�gstep)
			end if
		
		case 108
			if (TestPass and tim_TestPass.B) or errpassSV18_�v���^���N�����i���j or errpassSV17_�v���^���N�����i��j or AD4532_OK or AD4532_LO or DM_�v���ʌ��ݒl<setADR4532c1_Up then
				mSV19_�v���d����_A=OFF '�J��
				'mSV64_�v���d����_B=ON '��
				inc(�v�����j�b�gstep)
			end if
						
		case 109
			tim_procstep_val=#20 '���҂�����
			res(tim_procstep)
			inc(�v�����j�b�gstep)
		
		case 110
			if tim_procstep.B then
				�v�����j�b�gstep=199
			end if
		

		'--------------------------------------------------------------------------------------------------------------
		case 199
			if �����������ݒl<���������ݒ�l then
				inc(�����������ݒl)
			end if

			�v�������T�C�N��flg=OFF
			mSV19_�v���d����_A=OFF '�J��
			'mSV64_�v���d����_B=ON '��
			��������=ON
			*p�����r�o�v��.B=ON
			�v�����j�b�gstep=1
		'--------------------------------------------------------------------------------------------------------------
		'�����T�C�N������
		case 200
			if ������������  then
				inc(�v�����j�b�gstep)
			else
				if �v������step=0 then
					�v������step=1
				end if
				inc(�v�����j�b�gstep)
			end if
		
		case 201
			if ������������  then
				�v�����j�b�gstep=100
			end if
			
		end select


	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		�v�����j�b�gAutoRun=OFF
		
		res(tim_�v���^���N�����i���j.B) 
		res(tim_�v���^���N�����i��j.B)
		res(tim_�v���d����_A.B)
		
		
		if not(�v�������T�C�N��flg) then
		
				if ldp(PB32_�v��) and �v�����j�b�gstep=0 then
					if *pPH_�����m.B and *pPH_�t�^���m.B then
						������������=OFF
						��������=OFF
						�v�������T�C�N��flg=ON
						�v�����j�b�gstep=200
					end if											
				end if
				
				
				if ldp(pnlPBSV17_�v���^���N�����i��j) then
					if mSV17_�v���^���N�����i��j then
						mSV17_�v���^���N�����i��j=OFF
					else
						mSV17_�v���^���N�����i��j=ON
					end if
				end if
				if ldp(pnlPBSV18_�v���^���N�����i���j) then
					if mSV18_�v���^���N�����i���j then
						mSV18_�v���^���N�����i���j=OFF
					else
						mSV18_�v���^���N�����i���j=ON
					end if
				end if
				if ldp(pnlPBSV19_�v���d����_A) then
					if mSV19_�v���d����_A then
						mSV19_�v���d����_A=OFF
						'mSV64_�v���d����_B=OFF
					else
						mSV19_�v���d����_A=ON
						'mSV64_�v���d����_B=OFF
					end if
				end if
		end if
	end if '�v�����j�b�gAutoMode and not(�v�����j�b�gOrgErrStep)
	'===================================================================================================================
	'�y OrgErr�z
	else
	
		if ResetFlg then
			�v�����j�b�gOrgErr=OFF
		end if
		
	end if
	
	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else

		�v�����j�b�gErr=ON

		mSV17_�v���^���N�����i��j=OFF
		mSV18_�v���^���N�����i���j=OFF
		mSV19_�v���d����_A=OFF '�J��
		'mSV64_�v���d����_B=ON '��

		select case �v�����j�b�gErrStep
		case 0
		case 1
			if ResetFlg then
				almSV18_�v���^���N�����i���j=OFF
				almSV17_�v���^���N�����i��j=OFF
				almSV19_�v���d����_A=OFF
			
				inc(�v�����j�b�gErrStep)
			end if
		case 2
			res(tim_�v���^���N�����i���j.B) 
			res(tim_�v���^���N�����i��j.B)
			res(tim_�v���d����_A.B)
			�v�����j�b�gErrStep=0
			�v�����j�b�gErr=OFF
		end select

	end if 'if �v�����j�b�gErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	select case �v�����j�b�gEmgStep
	case 0
	
	case 1
		�v�����j�b�gAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�v�����j�b�gAutoMode and ��������AutoMode) or �v�������T�C�N��flg or �v�����j�b�gstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			�v�������T�C�N��flg=OFF

			�v�����j�b�gstep=0 '�I���ҋ@
			�v������step=0
			�v���ǉ�step=0
			������������=OFF

			mSV17_�v���^���N�����i��j=OFF
			mSV18_�v���^���N�����i���j=OFF
			mSV19_�v���d����_A=OFF
			mSV64_�v���d����_B=OFF
		
			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				tim_TestPass_stack=tim_TestPass.U
				tim_�v���ǉ�_stack=tim_�v���ǉ�.U
				tim_�v������_stack=tim_�v������.U
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mSV17_�v���^���N�����i��j=OFF
			mSV18_�v���^���N�����i���j=OFF
			mSV19_�v���d����_A=OFF
			mSV64_�v���d����_B=OFF		

			tim_procstep_stack=tim_procstep.U
			tim_TestPass_stack=tim_TestPass.U
			tim_�v���ǉ�_stack=tim_�v���ǉ�.U
			tim_�v������_stack=tim_�v������.U

			'---------------------------------
		end if
		
		'---------------------------------
		inc(�v�����j�b�gEmgStep)
	case 2
		if ResetFlg then
			inc(�v�����j�b�gEmgStep)
		end if
	case 3
		if (�v�����j�b�gAutoMode and ��������AutoMode) or �v�������T�C�N��flg or �v�����j�b�gstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				tim_procstep.U=tim_procstep_stack
				tim_TestPass.U=tim_TestPass_stack
				tim_�v���ǉ�.U=tim_�v���ǉ�_stack
				tim_�v������.U=tim_�v������_stack

				'---------------------------------
				inc(�v�����j�b�gEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			tim_procstep.U=tim_procstep_stack
			tim_TestPass.U=tim_TestPass_stack
			tim_�v���ǉ�.U=tim_�v���ǉ�_stack
			tim_�v������.U=tim_�v������_stack
			
			'---------------------------------
			inc(�v�����j�b�gEmgStep)		
		end if				
	case 4
		timstack=OFF
		�v�����j�b�gEmgStep=0
		�v�����j�b�gEmg=OFF
	end select

end if 'if �v�����j�b�gEmgStep=0 then
