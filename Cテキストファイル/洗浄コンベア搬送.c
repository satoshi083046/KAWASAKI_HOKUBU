'���R���x�A����
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	���R���x�A����
'
'	MC10_���]���[�^���]	-> MC37_���]���[�^���]
'	MC10_���]���[�^�t�] -> MC37_���]���[�^�t�]
'
'	PH45_�����m		-> PH59_�����m
'	PH46_�t�^���m	-> PH62_�t�^���m
'	PH7_�����m		-> PH63_�����m
'	PH8_�t�^���m	-> PH64_�t�^���m
'	PH9_�����m		-> PH65_�����m
'	PH10_�t�^���m	-> PH66_�t�^���m
'
'===================================================================================================================
�q��R�[�h=���k��
'===================================================================================================================
select case �q��R�[�h

case ���암

case ���k��

end select

'===================================================================================================================
'�y ���������� �z
if CR2008 then '�d��ON������������
    ���R���x�A����AutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    ���R���x�A����AutoRun=OFF
    ���R���x�A��������=ON
    ���R���x�A����OrgErr=OFF
    ���R���x�A����Err=OFF
    ���R���x�A����Emg=OFF
    ���R���x�A����step=0
    ���R���x�A����ErrStep=0
    ���R���x�A����OrgErrStep=0
    ���R���x�A����EmgStep=0

	INV1_�R���x�A���[�^���]step=0
	INV2_�R���x�A���[�^���]step=0
	INV3_�R���x�A���[�^���]step=0
	MC37_���]���[�^���]step=0
	MC37_���]���[�^�t�]step=0
	���t�^�X�g�b�p1step=0
	���t�^�X�g�b�p2step=0
	���t�^�X�g�b�p3step=0
	���t�^�X�g�b�p4step=0
	
	�����T�C�N��flg=OFF

	if SSW3_�������[�h then	
		ManualInite=1
	else
		ManualInite=0	
	end if

end if
'===================================================================================================================
'�y ���_ �z
���R���x�A����Org=1

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	���R���x�A����Emg=ON
	���R���x�A����EmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
tmr(not(SV71_���t�^�X�g�b�p) and not(XSW85_���t�^�X�g�b�p���~�[) and not(pnlPBXSW85_���t�^�X�g�b�p���~�[), tim_notXSW85_���t�^�X�g�b�p���~�[,#40)
tmr(not(SV77_���t�^�X�g�b�p) and not(XSW90_���t�^�X�g�b�p���~�[) and not(pnlPBXSW90_���t�^�X�g�b�p���~�[), tim_notXSW90_���t�^�X�g�b�p���~�[,#40)
tmr(not(SV83_���t�^�X�g�b�p) and not(XSW95_���t�^�X�g�b�p���~�[) and not(pnlPBXSW95_���t�^�X�g�b�p���~�[), tim_notXSW95_���t�^�X�g�b�p���~�[,#40)
tmr(not(SV89_���t�^�X�g�b�p) and not(XSW100_���t�^�X�g�b�p���~�[) and not(pnlPBXSW100_���t�^�X�g�b�p���~�[), tim_notXSW100_���t�^�X�g�b�p���~�[,#40)

'tmr(SV71_���t�^�X�g�b�p and XSW85_���t�^�X�g�b�p���~�[ and not(pnlPBXSW85_���t�^�X�g�b�p���~�[), tim_XSW85_���t�^�X�g�b�p���~�[,#10)
if LDF(SV71_���t�^�X�g�b�p) and XSW85_���t�^�X�g�b�p���~�[ and not(pnlPBXSW85_���t�^�X�g�b�p���~�[) then
	SET(tim_XSW85_���t�^�X�g�b�p���~�[)
end if
'tmr(SV77_���t�^�X�g�b�p and XSW90_���t�^�X�g�b�p���~�[ and not(pnlPBXSW90_���t�^�X�g�b�p���~�[), tim_XSW90_���t�^�X�g�b�p���~�[,#10)
if LDF(SV77_���t�^�X�g�b�p) and XSW90_���t�^�X�g�b�p���~�[ and not(pnlPBXSW90_���t�^�X�g�b�p���~�[) then
	SET(tim_XSW90_���t�^�X�g�b�p���~�[)
end if
'tmr(SV83_���t�^�X�g�b�p and XSW95_���t�^�X�g�b�p���~�[ and not(pnlPBXSW95_���t�^�X�g�b�p���~�[), tim_XSW95_���t�^�X�g�b�p���~�[,#10)
if LDF(SV83_���t�^�X�g�b�p) and XSW95_���t�^�X�g�b�p���~�[ and not(pnlPBXSW95_���t�^�X�g�b�p���~�[) then
	SET(tim_XSW95_���t�^�X�g�b�p���~�[)
end if
'tmr(SV89_���t�^�X�g�b�p and XSW100_���t�^�X�g�b�p���~�[ and not(pnlPBXSW100_���t�^�X�g�b�p���~�[), tim_XSW100_���t�^�X�g�b�p���~�[,#10)
if LDF(SV89_���t�^�X�g�b�p) and XSW100_���t�^�X�g�b�p���~�[ and not(pnlPBXSW100_���t�^�X�g�b�p���~�[) then
	SET(tim_XSW100_���t�^�X�g�b�p���~�[)
end if


tms(not(SV71_���t�^�X�g�b�p),passtimXSW85_���t�^�X�g�b�p���~�[,passtimXSW85_���t�^�X�g�b�p���~�[_val)
tms(not(SV77_���t�^�X�g�b�p),passtimXSW90_���t�^�X�g�b�p���~�[,passtimXSW90_���t�^�X�g�b�p���~�[_val)
tms(not(SV83_���t�^�X�g�b�p),passtimXSW95_���t�^�X�g�b�p���~�[,passtimXSW95_���t�^�X�g�b�p���~�[_val)
tms(not(SV89_���t�^�X�g�b�p),passtimXSW100_���t�^�X�g�b�p���~�[,passtimXSW100_���t�^�X�g�b�p���~�[_val)

tmr(MC37_���]���[�^���] and not(LS6_�󊘔��]���]�ʒu) and not(pnlPBLS6_�󊘔��]���]�ʒu),tim_LS6_�󊘔��]���]�ʒu,#80)
tmr(MC37_���]���[�^�t�] and not(LS5_�󊘔��]���_�ʒu) and not(pnlPBLS5_�󊘔��]���_�ʒu),tim_LS5_�󊘔��]���_�ʒu,#80)

if ldp(tim_XSW85_���t�^�X�g�b�p���~�[.B) or ldp(tim_notXSW85_���t�^�X�g�b�p���~�[.B) then
	errpassXSW85_���t�^�X�g�b�p���~�[=ON
	almXSW85_���t�^�X�g�b�p���~�[=ON
	pnlPBXSW85_���t�^�X�g�b�p���~�[=ON
	���R���x�A����ErrStep=1

else if ldp(tim_XSW90_���t�^�X�g�b�p���~�[.B) or ldp(tim_notXSW90_���t�^�X�g�b�p���~�[.B) then
	errpassXSW90_���t�^�X�g�b�p���~�[=ON
	almXSW90_���t�^�X�g�b�p���~�[=ON
	pnlPBXSW90_���t�^�X�g�b�p���~�[=ON
	���R���x�A����ErrStep=1

else if ldp(tim_XSW95_���t�^�X�g�b�p���~�[.B) or ldp(tim_notXSW95_���t�^�X�g�b�p���~�[.B) then
	errpassXSW95_���t�^�X�g�b�p���~�[=ON
	almXSW95_���t�^�X�g�b�p���~�[=ON
	pnlPBXSW95_���t�^�X�g�b�p���~�[=ON
	���R���x�A����ErrStep=1

else if ldp(tim_XSW100_���t�^�X�g�b�p���~�[.B) or ldp(tim_notXSW100_���t�^�X�g�b�p���~�[.B) then
	errpassXSW100_���t�^�X�g�b�p���~�[=ON
	almXSW100_���t�^�X�g�b�p���~�[=ON
	pnlPBXSW100_���t�^�X�g�b�p���~�[=ON
	���R���x�A����ErrStep=1

else if ldp(tim_LS6_�󊘔��]���]�ʒu.B) then
	ejectMC37_���]���[�^���]=OFF
	almLS6_�󊘔��]���]�ʒu=ON
	���R���x�A����ErrStep=1

else if ldp(tim_LS5_�󊘔��]���_�ʒu.B) then
	ejectMC37_���]���[�^�t�]=OFF
	almLS5_�󊘔��]���_�ʒu=ON
	���R���x�A����ErrStep=1


end if	
'===================================================================================================================
'�y �t�^�����oLS�f�B���[�z
'tmr(LS11_���t�^���m,timdly_LS11_���t�^���m,2)
'tmr(LS12_���t�^���m,timdly_LS12_���t�^���m,2)
'tmr(LS13_���t�^���m,timdly_LS13_���t�^���m,2)
'tmr(LS14_���t�^���m,timdly_LS14_���t�^���m,2)

'tmr(not(LS11_���t�^���m),nottimdly_LS11_���t�^���m,2)
'tmr(not(LS12_���t�^���m),nottimdly_LS12_���t�^���m,2)
'tmr(not(LS13_���t�^���m),nottimdly_LS13_���t�^���m,2)
'tmr(not(LS14_���t�^���m),nottimdly_LS14_���t�^���m,2)

tmr(PH63_�����m,timdly_PH63_�����m,4)
tmr(PH64_�t�^���m,timdly_PH64_�t�^���m,4)
tmr(PH59_�����m,timdly_PH59_�����m,4)
tmr(PH62_�t�^���m,timdly_PH62_�t�^���m,4)

if ���R���x�A����AutoRun  then	
	if not(��򃆃j�b�g1�֎~) and (mMC58_���|���vA and not(pauseMC58_���|���vA) and  getEDC1_PV>=(setEDC1_SV-5) ) then
		�z�ď��������J�E���g�\=ON
	else if not(��򃆃j�b�g2�֎~) and (mMC59_���|���vB and not(pauseMC59_���|���vB) and  getEDC2_PV>=(setEDC2_SV-5) ) then
		�z�ď��������J�E���g�\=ON
	else if not(��򃆃j�b�g3�֎~) and (mMC60_���|���vC and not(pauseMC60_���|���vC) and  getEDC3_PV>=(setEDC3_SV-5) ) then
		�z�ď��������J�E���g�\=ON
	else if not(��򃆃j�b�g4�֎~) and (mMC61_���|���vD and not(pauseMC61_���|���vD) and  getEDC4_PV>=(setEDC4_SV-5) ) then
		�z�ď��������J�E���g�\=ON
	end if
else
	�z�ď��������J�E���g�\=OFF
end if


if not(�z�ď��������J�E���g�\) then
	IND_��򏀔���=ON
else
	IND_��򏀔���=OFF
end if


'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: ���R���x�A����AutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: ���R���x�A����AutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: ���R���x�A����Emg	���̏��~


if not(���R���x�A����Emg) then  
	
	if ���R���x�A����ErrStep=0  then

	if not(���R���x�A����OrgErr) then

	if �����T�C�N��flg or (���R���x�A����AutoMode and ��������AutoMode ) or ���R���x�A����step<>0 then
	
		if not(���R���x�A����AutoMode and ��������AutoMode ) then
			���R���x�A����AutoRun=OFF
		end if

		if ManualInite=1 then
			PBL44_�R���x�A=OFF
		
			mSV71_���t�^�X�g�b�p=ON
			mSV77_���t�^�X�g�b�p=ON
			mSV83_���t�^�X�g�b�p=ON
			mSV89_���t�^�X�g�b�p=ON

			mINV1_�R���x�A���[�^���]=OFF
			mINV2_�R���x�A���[�^���]=OFF
			ejectINV3_�R���x�A���[�^���]=OFF
			
			manual���R���x�A=OFF
			tmp1INV1_�R���x�A���[�^���]=OFF
			tmp1INV2_�R���x�A���[�^���]=OFF
			tmp1INV3_�R���x�A���[�^���]=OFF
			tmp2INV1_�R���x�A���[�^���]=OFF
			tmp2INV2_�R���x�A���[�^���]=OFF
			tmp2INV3_�R���x�A���[�^���]=OFF
	
			ManualInite=0
		end if

	'------------------------------------------------------------------------------------------------
	'INV1_�R���x�A���[�^���]
	tmr(tim_INV1_�R���x�A���[�^���],tim_INV1_�R���x�A���[�^���]_val)
	
	select case INV1_�R���x�A���[�^���]step
	
	case 0
	
	case 1
	
		PH59_���N�����m=timdly_PH59_�����m
		PH62_�t�^�N�����m=timdly_PH62_�t�^���m
		
		if PH59_���N�����m or PH62_�t�^�N�����m then
		
			if PH59_���N�����m and PH62_�t�^�N�����m then '������
				shiftreg���t�^����0=$80

				'if �z�ď��������J�E���g�\  and �^�]������ then
				'	if �z�ď����������ݒl<�z�ď��������ݒ�l then
				'		inc(�z�ď����������ݒl)
				'	end if
				'end if			
				'
				'if ���ъ�������̊��J�E���g>0 then
				'	dec(���ъ�������̊��J�E���g)
				'end if

			else if not(PH59_���N�����m) and PH62_�t�^�N�����m then '�t�^����
				shiftreg���t�^����0=$40			

				if �z�ď��������J�E���g�\  and �^�]������ then
					if �z�ď����������ݒl<�z�ď��������ݒ�l then
						inc(�z�ď����������ݒl)
					end if
				end if			
				
				if ���ъ�������̊��J�E���g>0 then
					dec(���ъ�������̊��J�E���g)
				end if

			end if

			inc(INV1_�R���x�A���[�^���]step)
		else
			INV1_�R���x�A���[�^���]step=0
			�����������r�o�v��=OFF
			�����]�����r�o�v��=OFF
		end if

	case 2
		setS05c1=5000
		setS08c1=10
		setS09c1=10
		mINV1_�R���x�A���[�^���]=ON
		inc(INV1_�R���x�A���[�^���]step)
	
	case 3
		if not(PH59_�����m) and not(PH62_�t�^���m) then
			inc(INV1_�R���x�A���[�^���]step)
		end if

	case 4
		tim_INV1_�R���x�A���[�^���]_val=60 '���[�^��~�^�C�~���O
		res(tim_INV1_�R���x�A���[�^���])
		inc(INV1_�R���x�A���[�^���]step)
	
	case 5
		if tim_INV1_�R���x�A���[�^���].B then
			inc(INV1_�R���x�A���[�^���]step)
		end if
		
	case 6
		mINV1_�R���x�A���[�^���]=OFF
		inc(INV1_�R���x�A���[�^���]step)
	
	case 7
		�����]�����r�o�v��=OFF
		�����������r�o�v��=OFF
		INV1_�R���x�A���[�^���]step=0

	end select
	'------------------------------------------------------------------------------------------------
	'�X�g�b�p�[�㏸�^�X�N
	'---------------------------------------------------
	tmr(tim_���t�^�X�g�b�p1,tim_���t�^�X�g�b�p1_val)
	select case ���t�^�X�g�b�p1step
	case 0
	case 1
		tim_���t�^�X�g�b�p1_val=���1�X�g�b�p�[�㏸�^�C�~���O
		res(tim_���t�^�X�g�b�p1)
		inc(���t�^�X�g�b�p1step)

	case 2
		if tim_���t�^�X�g�b�p1.B then
			inc(���t�^�X�g�b�p1step)
		end if	
	
	case 3
		mSV71_���t�^�X�g�b�p=ON	'�X�g�b�p�[�㏸
		inc(���t�^�X�g�b�p1step)
	case 4
		���t�^�X�g�b�p1step=0	
	end select
	'---------------------------------------------------
	tmr(tim_���t�^�X�g�b�p2,tim_���t�^�X�g�b�p2_val)
	select case ���t�^�X�g�b�p2step
	case 0
	case 1
		tim_���t�^�X�g�b�p2_val=���2�X�g�b�p�[�㏸�^�C�~���O
		res(tim_���t�^�X�g�b�p2)
		inc(���t�^�X�g�b�p2step)

	case 2
		if tim_���t�^�X�g�b�p2.B then
			inc(���t�^�X�g�b�p2step)
		end if	
	
	case 3
		mSV77_���t�^�X�g�b�p=ON
		inc(���t�^�X�g�b�p2step)
	case 4
		���t�^�X�g�b�p2step=0	
	end select
	'---------------------------------------------------
	tmr(tim_���t�^�X�g�b�p3,tim_���t�^�X�g�b�p3_val)
	select case ���t�^�X�g�b�p3step
	case 0
	case 1
		tim_���t�^�X�g�b�p3_val=���3�X�g�b�p�[�㏸�^�C�~���O
		res(tim_���t�^�X�g�b�p3)
		inc(���t�^�X�g�b�p3step)

	case 2
		if tim_���t�^�X�g�b�p3.B then
			inc(���t�^�X�g�b�p3step)
		end if	
	
	case 3
		mSV83_���t�^�X�g�b�p=ON
		inc(���t�^�X�g�b�p3step)
	case 4
		���t�^�X�g�b�p3step=0	
	end select
	'---------------------------------------------------
	tmr(tim_���t�^�X�g�b�p4,tim_���t�^�X�g�b�p4_val)
	select case ���t�^�X�g�b�p4step
	case 0
	case 1
		tim_���t�^�X�g�b�p4_val=���4�X�g�b�p�[�㏸�^�C�~���O
		res(tim_���t�^�X�g�b�p4)
		inc(���t�^�X�g�b�p4step)

	case 2
		if tim_���t�^�X�g�b�p4.B then
			inc(���t�^�X�g�b�p4step)
		end if	
	
	case 3
		mSV89_���t�^�X�g�b�p=ON
		inc(���t�^�X�g�b�p4step)
	case 4
		���t�^�X�g�b�p4step=0	
	end select
	'------------------------------------------------------------------------------------------------
	'INV2_�R���x�A���[�^���]
	tmr(tim_INV2_�R���x�A���[�^���],tim_INV2_�R���x�A���[�^���]_val)
	
	select case INV2_�R���x�A���[�^���]step
	
	case 0
	
	case 1
		tim_INV2_�R���x�A���[�^���]_val=INV2�N���҂����� '1���@(0) 2���@(10)
		res(tim_INV2_�R���x�A���[�^���])
		inc(INV2_�R���x�A���[�^���]step)
		
	case 2
		if tim_INV2_�R���x�A���[�^���].B then
			inc(INV2_�R���x�A���[�^���]step)
		end if		
	
	case 3
		'if not(XSW82_���t�^���������~�[A) and not(XSW84_���t�^���������~�[B) then
			'if not(XSW87_���t�^���������~�[A) and not(XSW89_���t�^���������~�[B) then
				'if not(XSW92_���t�^���������~�[A) and not(XSW94_���t�^���������~�[B) then
					'if not(XSW97_���t�^���������~�[A) and not(XSW99_���t�^���������~�[B) then
							inc(INV2_�R���x�A���[�^���]step)
					'end if
				'end if
			'end if	
		'end if

	case 4
		setS05c2=5000
		setS08c2=10
		setS09c2=25 '<-��~����
		mINV2_�R���x�A���[�^���]=ON
		
		���t�^�X�g�b�p1step=1
		���t�^�X�g�b�p2step=1
		���t�^�X�g�b�p3step=1
		���t�^�X�g�b�p4step=1
		
		
		inc(INV2_�R���x�A���[�^���]step)
	
	case 5
		tim_INV2_�R���x�A���[�^���]_val=INV2�u���[�L�^�C�~���O '1���@(28) 2���@(24)
		res(tim_INV2_�R���x�A���[�^���])
		inc(INV2_�R���x�A���[�^���]step)

	
	case 6
		if tim_INV2_�R���x�A���[�^���].B then
			inc(INV2_�R���x�A���[�^���]step)
		end if		

	case 7
		mINV2_�R���x�A���[�^���]=OFF
		inc(INV2_�R���x�A���[�^���]step)
	
	case 8
		tim_INV2_�R���x�A���[�^���]_val=30
		res(tim_INV2_�R���x�A���[�^���])
		inc(INV2_�R���x�A���[�^���]step)

	case 9
		if tim_INV2_�R���x�A���[�^���].B then
			inc(INV2_�R���x�A���[�^���]step)
		end if		

	case 10
		if ���t�^�X�g�b�p1step=0 and ���t�^�X�g�b�p2step=0 and ���t�^�X�g�b�p3step=0 and ���t�^�X�g�b�p4step=0 then
			inc(INV2_�R���x�A���[�^���]step)
		end if
		
	case 11
		INV2_�R���x�A���[�^���]step=0

	end select
	
	'------------------------------------------------------------------------------------------------
	'INV3_�R���x�A���[�^���]
	tmr(tim_INV3_�R���x�A���[�^���],tim_INV3_�R���x�A���[�^���]_val)
	
	select case INV3_�R���x�A���[�^���]step
	
	case 0
	
	case 1
		if PH63_�����m or PH64_�t�^���m then
			INV3_�R���x�A���[�^���]step=0
		else
			inc(INV3_�R���x�A���[�^���]step)	
		end if
	
	case 2
		setS05c3=5000
		setS08c3=10
		setS09c3=10
		ejectINV3_�R���x�A���[�^���]=ON
		
		
		StageDevice50=shiftreg���t�^����4 'StageDevice37 , ��:$80  �t�^:$40

'		if not(�����T�C�N��flg) and StageDevice50=$80 and not(PH65_�����m) then
'			if MC37_���]���[�^���]step=0 then
'				MC37_���]���[�^���]step=1
'			end if
'		end if


		LatchPH63_�����m=OFF
		LatchPH64_�t�^���m=OFF
		
		inc(INV3_�R���x�A���[�^���]step)

	case 3
		if not(PH63_�����m) and not(PH64_�t�^���m) then
				tim_INV3_�R���x�A���[�^���]_val=120 '���[�^��~�^�C�~���O
				res(tim_INV3_�R���x�A���[�^���])
				inc(INV3_�R���x�A���[�^���]step)
		end if

	case 4
		if (PH63_�����m and timdly_PH63_�����m.B) or (PH64_�t�^���m and timdly_PH64_�t�^���m.B) or tim_INV3_�R���x�A���[�^���].B then
		
			if SEL2_1_�^�]�؊��i�P���j and tim_INV3_�R���x�A���[�^���].B then
				StageDevice50=0
			end if
			
			inc(INV3_�R���x�A���[�^���]step)
		end if
		
	case 5
		ejectINV3_�R���x�A���[�^���]=OFF
		inc(INV3_�R���x�A���[�^���]step)
	
	case 6
		if StageDevice50=$80 or StageDevice50=$40 then
			���R���x�A�����r�o�v��=ON
		else
			���R���x�A�����r�o�v��=OFF
		end if		
		
		INV3_�R���x�A���[�^���]step=0
	
	end select
	'------------------------------------------------------------------------------------------------
	'MC37_���]���[�^���]  �i���~���u->���@���j
	tmr(tim_MC37_���]���[�^���],tim_MC37_���]���[�^���]_val)
	
	select case MC37_���]���[�^���]step
	
	case 0
	
	case 1
		ejectMC37_���]���[�^���]=ON
		inc(MC37_���]���[�^���]step)

	case 2
		if LS6_�󊘔��]���]�ʒu then
			inc(MC37_���]���[�^���]step)
		end if
		
	case 3
		ejectMC37_���]���[�^���]=OFF
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
		ejectMC37_���]���[�^�t�]=ON
		inc(MC37_���]���[�^�t�]step)

	case 2
		if LS5_�󊘔��]���_�ʒu then
			inc(MC37_���]���[�^�t�]step)
		end if
	
	case 3
		ejectMC37_���]���[�^�t�]=OFF
		inc(MC37_���]���[�^�t�]step)
		
	case 4
		MC37_���]���[�^�t�]step=0

	end select

	'------------------------------------------------------------------------------------------------


	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case ���R���x�A����step
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if ���R���x�A����AutoRun or �����T�C�N��flg then
				inc(���R���x�A����step)
			else 
				���R���x�A����step=0 '�I���ҋ@
			end if
		
		case 2
			if PH63_�����m or PH64_�t�^���m then
				StageDevice50=shiftreg���t�^����5
				���R���x�A�������쒆=OFF
				���R���x�A�����r�o�v��=ON
				���R���x�A����step=1
			else
				inc(���R���x�A����step)
			end if
							
		
		case 3
		
		' [ ���̔����R���x�A��~�m�F ]
			if (���R���x�A�����r�o�v��=OFF or �����T�C�N��flg) and  �����]�o�����쒆=OFF and  (�����]�����r�o�v�� or �����T�C�N��flg) and ��򃆃j�b�gorg then
				inc(���R���x�A����step)
			else
				���R���x�A����step=1s
			end if
		
		case 4
			if ��򊮗� then
				inc(���R���x�A����step)
			else
				���R���x�A����step=1
			end if

		case 5
			���R���x�A����step=100
		'--------------------------------------------------------------------------------------------------------------
		case 100			
			PH59_���N�����m=PH59_�����m
			PH62_�t�^�N�����m=PH62_�t�^���m
			���R���x�A�������쒆=ON

			mSV71_���t�^�X�g�b�p=OFF	'�X�g�b�p�[���~
			mSV77_���t�^�X�g�b�p=OFF
			mSV83_���t�^�X�g�b�p=OFF
			mSV89_���t�^�X�g�b�p=OFF
			
			errpassXSW85_���t�^�X�g�b�p���~�[=OFF
			errpassXSW90_���t�^�X�g�b�p���~�[=OFF
			errpassXSW95_���t�^�X�g�b�p���~�[=OFF
			errpassXSW100_���t�^�X�g�b�p���~�[=OFF
			
			inc(���R���x�A����step)
		
		case 101
			if (errpassXSW85_���t�^�X�g�b�p���~�[ or ((XSW85_���t�^�X�g�b�p���~�[ and not(pnlPBXSW85_���t�^�X�g�b�p���~�[)) or passXSW85_���t�^�X�g�b�p���~�[) or ��򃆃j�b�g1�֎~) then
				if (errpassXSW90_���t�^�X�g�b�p���~�[ or ((XSW90_���t�^�X�g�b�p���~�[ and not(pnlPBXSW90_���t�^�X�g�b�p���~�[)) or passXSW90_���t�^�X�g�b�p���~�[) or ��򃆃j�b�g2�֎~) then
					if (errpassXSW95_���t�^�X�g�b�p���~�[ or ((XSW95_���t�^�X�g�b�p���~�[ and not(pnlPBXSW95_���t�^�X�g�b�p���~�[)) or passXSW95_���t�^�X�g�b�p���~�[) or ��򃆃j�b�g3�֎~) then
						if (errpassXSW100_���t�^�X�g�b�p���~�[ or ((XSW100_���t�^�X�g�b�p���~�[ and not(pnlPBXSW100_���t�^�X�g�b�p���~�[)) or passXSW100_���t�^�X�g�b�p���~�[) or ��򃆃j�b�g4�֎~) then
							inc(���R���x�A����step)
						end if
					end if
				end if
			end if

		case 102
			tim_procstep_val=10
			res(tim_procstep)
			inc(���R���x�A����step)

		case 103
			if tim_procstep.B then			
				inc(���R���x�A����step)
			end if

		case 104

			INV1_�R���x�A���[�^���]step=1			
			INV2_�R���x�A���[�^���]step=1
			INV3_�R���x�A���[�^���]step=1
			
			inc(���R���x�A����step)
		
		case 105
			if INV1_�R���x�A���[�^���]step=0 and  INV2_�R���x�A���[�^���]step=0 and INV3_�R���x�A���[�^���]step=0 then
				inc(���R���x�A����step)
			end if
		
		case 106
			tim_procstep_val=0
			res(tim_procstep)
			inc(���R���x�A����step)

		case 107
			if tim_procstep.B then			
				inc(���R���x�A����step)
			end if
		
		case 108

			shiftreg���t�^����8	=	shiftreg���t�^����7
			shiftreg���t�^����7	=	shiftreg���t�^����6
			shiftreg���t�^����6	=	shiftreg���t�^����5
			shiftreg���t�^����5	=	shiftreg���t�^����4
			shiftreg���t�^����4	=	shiftreg���t�^����3
			shiftreg���t�^����3	=	shiftreg���t�^����2
			shiftreg���t�^����2	=	shiftreg���t�^����1
			shiftreg���t�^����1	=	shiftreg���t�^����0
			shiftreg���t�^����0 = 0

			��򊮗�=OFF
			�����]�����r�o�v��=OFF
			�����������r�o�v��=OFF
			���R���x�A�������쒆=OFF
			���R���x�A����step=1
			
					
			�����T�C�N��flg=OFF

		end select
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else
		if ManualInite=0 and �����T�C�N��flg=OFF then
			PBL44_�R���x�A=OFF
		
			mSV71_���t�^�X�g�b�p=OFF
			mSV77_���t�^�X�g�b�p=OFF
			mSV83_���t�^�X�g�b�p=OFF
			mSV89_���t�^�X�g�b�p=OFF

			mINV1_�R���x�A���[�^���]=OFF
			mINV2_�R���x�A���[�^���]=OFF
			ejectINV3_�R���x�A���[�^���]=OFF
			
			manual���R���x�A=OFF
			tmp1INV1_�R���x�A���[�^���]=OFF
			tmp1INV2_�R���x�A���[�^���]=OFF
			tmp1INV3_�R���x�A���[�^���]=OFF
			tmp2INV1_�R���x�A���[�^���]=OFF
			tmp2INV2_�R���x�A���[�^���]=OFF
			tmp2INV3_�R���x�A���[�^���]=OFF

			ManualInite=1
		end if

		
		'res(tim_XSW85_���t�^�X�g�b�p���~�[.B)
		'res(tim_XSW90_���t�^�X�g�b�p���~�[.B)
		'res(tim_XSW95_���t�^�X�g�b�p���~�[.B)
		'res(tim_XSW100_���t�^�X�g�b�p���~�[.B)

		���R���x�A����AutoRun=OFF
		���R���x�A����step=0 '�I��
		

		'---------------------------------------------------------------------
		' ���R���x�A �}�j���A���^�]
		'---------------------------------------------------------------------
		PBL44_�R���x�A=mINV1_�R���x�A���[�^���] or mINV2_�R���x�A���[�^���] or ejectINV3_�R���x�A���[�^���]
		
		mINV1_�R���x�A���[�^���]=tmp1INV1_�R���x�A���[�^���] or tmp2INV1_�R���x�A���[�^���]
		mINV2_�R���x�A���[�^���]=tmp1INV2_�R���x�A���[�^���] or tmp2INV2_�R���x�A���[�^���]
		ejectINV3_�R���x�A���[�^���]=tmp1INV3_�R���x�A���[�^���] or tmp2INV3_�R���x�A���[�^���]
		
		if PB45_�S��~SW and (not(timdly_PH63_�����m) and not(timdly_PH64_�t�^���m)) then

			if SEL2_1_�^�]�؊��i�P���j then
				if ��򃆃j�b�gOrg and ���R���x�A����Org and �����]�o��Org then 

					tmp2INV1_�R���x�A���[�^���]=OFF
					tmp2INV2_�R���x�A���[�^���]=OFF
					tmp2INV3_�R���x�A���[�^���]=OFF
					
					if ldp(PB44_�R���x�ASW) then
						if manual���R���x�A then
							manual���R���x�A=OFF
						else
							manual���R���x�A=ON
						end if
					end if
					
					tmp1INV1_�R���x�A���[�^���]=manual���R���x�A
					tmp1INV2_�R���x�A���[�^���]=manual���R���x�A
					tmp1INV3_�R���x�A���[�^���]=manual���R���x�A

				else
					if ldp(PB44_�R���x�ASW) then
						if not(��򃆃j�b�gOrg) then
							��򃆃j�b�gOrgErr=ON
						end if
						
						if not(���R���x�A����Org) then
							���R���x�A����OrgErr=ON
						end if
						
						if not(�����]�o��Org) then
							�����]�o��OrgErr=ON
						end if
					end if
				end if
			else
				
					manual���R���x�A=OFF
					tmp1INV1_�R���x�A���[�^���]=OFF
					tmp1INV2_�R���x�A���[�^���]=OFF
					tmp1INV3_�R���x�A���[�^���]=OFF

					if ldp(pnlPBINV1_�R���x�A���[�^���]) then
						if tmp2INV1_�R���x�A���[�^���] then
							tmp2INV1_�R���x�A���[�^���]=OFF
						else
							tmp2INV1_�R���x�A���[�^���]=ON
						end if
					end if
							
				if ��򃆃j�b�gOrg and ���R���x�A����Org  and �����]�o��Org then 
					if ldp(pnlPBINV2_�R���x�A���[�^���]) then
						if tmp2INV2_�R���x�A���[�^���] then
							tmp2INV2_�R���x�A���[�^���]=OFF
						else
							tmp2INV2_�R���x�A���[�^���]=ON
						end if
					end if

					if ldp(pnlPBINV3_�R���x�A���[�^���]) then
						if tmp2INV3_�R���x�A���[�^���] then
							tmp2INV3_�R���x�A���[�^���]=OFF
						else
							tmp2INV3_�R���x�A���[�^���]=ON
						end if
					end if
				else
					if ldp(pnlPBINV2_�R���x�A���[�^���]) or ldp(pnlPBINV3_�R���x�A���[�^���]) then
						if not(��򃆃j�b�gOrg) then
							��򃆃j�b�gOrgErr=ON
						end if
						
						if not(���R���x�A����Org) then
							���R���x�A����OrgErr=ON
						end if
						
						if not(�����]�o��Org) then
							�����]�o��OrgErr=ON
						end if

					end if								
				end if
			end if

		else
			mINV1_�R���x�A���[�^���]=OFF
			mINV2_�R���x�A���[�^���]=OFF
			ejectINV3_�R���x�A���[�^���]=OFF
			
			manual���R���x�A=OFF
			tmp1INV1_�R���x�A���[�^���]=OFF
			tmp1INV2_�R���x�A���[�^���]=OFF
			tmp1INV3_�R���x�A���[�^���]=OFF
			tmp2INV1_�R���x�A���[�^���]=OFF
			tmp2INV2_�R���x�A���[�^���]=OFF
			tmp2INV3_�R���x�A���[�^���]=OFF
						
		end if
		'---------------------------------------------------------------------		
		'���X�g�b�p  �}�j���A���^�]		
		'---------------------------------------------------------------------		
		if not(manual���R���x�A) then
		
			if ldp(pnlPBSV71_���t�^�X�g�b�p) then
				if mSV71_���t�^�X�g�b�p then
					mSV71_���t�^�X�g�b�p=OFF
				else
					mSV71_���t�^�X�g�b�p=ON
				end if
			end if
			
			if ldp(pnlPBSV77_���t�^�X�g�b�p) then
				if mSV77_���t�^�X�g�b�p then
					mSV77_���t�^�X�g�b�p=OFF
				else
					mSV77_���t�^�X�g�b�p=ON
				end if
			end if
			
			if ldp(pnlPBSV83_���t�^�X�g�b�p) then
				if mSV83_���t�^�X�g�b�p then
					mSV83_���t�^�X�g�b�p=OFf
				else
					mSV83_���t�^�X�g�b�p=ON
				end if
			end if
			
			if ldp(pnlPBSV89_���t�^�X�g�b�p) then
				if mSV89_���t�^�X�g�b�p then
					mSV89_���t�^�X�g�b�p=OFF
				else
					mSV89_���t�^�X�g�b�p=ON
				end if
			end if
			
			
			if ldp(PB25_���@�P���^�]) and (not(PH63_�����m) and not(PH64_�t�^���m))  and (not(PH65_�����m) and not(PH66_�t�^���m)) and  ��򃆃j�b�gOrg then

					PH59_���N�����m=PH59_�����m
					PH62_�t�^�N�����m=PH62_�t�^���m
					
					if PH59_�����m or PH62_�t�^���m then			
						if PH59_�����m and PH62_�t�^���m then
							shiftreg���t�^����0=$80
						else if not(PH59_�����m) and PH62_�t�^���m then
							shiftreg���t�^����0=$40			
						end if
					else
						shiftreg���t�^����0=$0
					end if
			
'					if not(LS5_�󊘔��]���_�ʒu) and MC37_���]���[�^�t�]step=0 then
'						MC37_���]���[�^�t�]step=1
'					else
						�����T�C�N��flg=ON
						���R���x�A����step=1
'					end if
			end if
			
		end if		
		
	end if '���R���x�A����AutoMode and not(���R���x�A����OrgErrStep)

	'===================================================================================================================
	'�y ���R���x�A����OrgErr���� �z
	else

		if ResetFlg then
			���R���x�A����OrgErr=OFF
		end if


	end if

	'===================================================================================================================
	'�y�^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
		���R���x�A����Err=ON

		mINV1_�R���x�A���[�^���]=OFF
		mINV2_�R���x�A���[�^���]=OFF
		ejectINV3_�R���x�A���[�^���]=OFF
		
		mSV71_���t�^�X�g�b�p=OFF
		mSV77_���t�^�X�g�b�p=OFF
		mSV83_���t�^�X�g�b�p=OFF
		mSV89_���t�^�X�g�b�p=OFF


		���R���x�A�������쒆=OFF

		tmr(tim_���R���x�A����ErrStep,tim_���R���x�A����ErrStep_val)
		
		select case ���R���x�A����ErrStep
		case 0
		
		'------------------------------------------------------------------
		case 1
			if ResetFlg then
			 	inc(���R���x�A����ErrStep)
			end if
			
		case 2
			almXSW85_���t�^�X�g�b�p���~�[=OFF
			almXSW90_���t�^�X�g�b�p���~�[=OFF
			almXSW95_���t�^�X�g�b�p���~�[=OFF
			almXSW100_���t�^�X�g�b�p���~�[=OFF
			almLS6_�󊘔��]���]�ʒu=OFF
			almLS5_�󊘔��]���_�ʒu=OFF

		 	inc(���R���x�A����ErrStep)
		case 3
			���R���x�A����Err=OFF

			res(tim_XSW85_���t�^�X�g�b�p���~�[)
			res(tim_XSW90_���t�^�X�g�b�p���~�[)
			res(tim_XSW95_���t�^�X�g�b�p���~�[)
			res(tim_XSW100_���t�^�X�g�b�p���~�[)
			res(tim_notXSW85_���t�^�X�g�b�p���~�[)
			res(tim_notXSW90_���t�^�X�g�b�p���~�[)
			res(tim_notXSW95_���t�^�X�g�b�p���~�[)
			res(tim_notXSW100_���t�^�X�g�b�p���~�[)
			res(tim_LS6_�󊘔��]���]�ʒu)
			res(tim_LS5_�󊘔��]���_�ʒu)

			���R���x�A����step=0
			INV1_�R���x�A���[�^���]step=0
			INV2_�R���x�A���[�^���]step=0
			INV3_�R���x�A���[�^���]step=0
			MC37_���]���[�^���]step=0
			MC37_���]���[�^�t�]step=0

			���R���x�A����ErrStep=0
		end select

	end if 'if ���R���x�A����ErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	select case ���R���x�A����EmgStep
	case 0
	
	case 1
		���R���x�A����AutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if �����T�C�N��flg or (���R���x�A����AutoMode and ��������AutoMode ) or ���R���x�A����step<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseMC37_���]���[�^�t�]=ON
			pauseMC37_���]���[�^���]=ON
			
			pauseINV1_�R���x�A���[�^���]=ON
			pauseINV2_�R���x�A���[�^���]=ON
			pauseINV3_�R���x�A���[�^���]=ON
			
			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				tim_manual�R���x�A_stack=tim_manual�R���x�A.U
				tim_INV1_�R���x�A���[�^���]_stack=tim_INV1_�R���x�A���[�^���].U
				tim_INV2_�R���x�A���[�^���]_stack=tim_INV2_�R���x�A���[�^���].U
				tim_INV3_�R���x�A���[�^���]_stack=tim_INV3_�R���x�A���[�^���].U
				tim_MC37_���]���[�^�t�]_stack=tim_MC37_���]���[�^�t�].U
				tim_MC37_���]���[�^���]_stack=tim_MC37_���]���[�^���].U
				tim_���t�^�X�g�b�p1_stack=tim_���t�^�X�g�b�p1.U
				tim_���t�^�X�g�b�p2_stack=tim_���t�^�X�g�b�p2.U
				tim_���t�^�X�g�b�p3_stack=tim_���t�^�X�g�b�p3.U
				tim_���t�^�X�g�b�p4_stack=tim_���t�^�X�g�b�p4.U
				tim_���R���x�A����ErrStep_stack=tim_���R���x�A����ErrStep.U

				timdly_PH63_�����m_stack=timdly_PH63_�����m.U
				timdly_PH64_�t�^���m_stack=timdly_PH64_�t�^���m.U
				timdly_PH7_�����m_stack=timdly_PH7_�����m.U
				timdly_PH8_�t�^���m_stack=timdly_PH8_�t�^���m.U

				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC37_���]���[�^�t�]=OFF
			mMC37_���]���[�^���]=OFF
			
			mINV1_�R���x�A���[�^���]=OFF
			mINV2_�R���x�A���[�^���]=OFF
			mINV3_�R���x�A���[�^���]=OFF
			ejectINV3_�R���x�A���[�^���]=OFF

			mSV71_���t�^�X�g�b�p=OFF	'�X�g�b�p�[���~
			mSV77_���t�^�X�g�b�p=OFF
			mSV83_���t�^�X�g�b�p=OFF
			mSV89_���t�^�X�g�b�p=OFF

			tmp1INV1_�R���x�A���[�^���]=OFF
			tmp1INV2_�R���x�A���[�^���]=OFF
			tmp1INV3_�R���x�A���[�^���]=OFF
			tmp2INV1_�R���x�A���[�^���]=OFF
			tmp2INV2_�R���x�A���[�^���]=OFF
			tmp2INV3_�R���x�A���[�^���]=OFF

			'---------------------------------
		end if
		
		'---------------------------------
		inc(���R���x�A����EmgStep)
	case 2
		if ResetFlg then
			inc(���R���x�A����EmgStep)
		end if
	case 3
		if �����T�C�N��flg or (���R���x�A����AutoMode and ��������AutoMode ) or ���R���x�A����step<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseMC37_���]���[�^�t�]=OFF
				pauseMC37_���]���[�^���]=OFF
				
				pauseINV1_�R���x�A���[�^���]=OFF
				pauseINV2_�R���x�A���[�^���]=OFF
				pauseINV3_�R���x�A���[�^���]=OFF
				
				tim_procstep.U=tim_procstep_stack
				tim_manual�R���x�A.U=tim_manual�R���x�A_stack
				tim_INV1_�R���x�A���[�^���].U=tim_INV1_�R���x�A���[�^���]_stack
				tim_INV2_�R���x�A���[�^���].U=tim_INV2_�R���x�A���[�^���]_stack
				tim_INV3_�R���x�A���[�^���].U=tim_INV3_�R���x�A���[�^���]_stack
				tim_MC37_���]���[�^�t�].U=tim_MC37_���]���[�^�t�]_stack
				tim_MC37_���]���[�^���].U=tim_MC37_���]���[�^���]_stack
				tim_���t�^�X�g�b�p1.U=tim_���t�^�X�g�b�p1_stack
				tim_���t�^�X�g�b�p2.U=tim_���t�^�X�g�b�p2_stack
				tim_���t�^�X�g�b�p3.U=tim_���t�^�X�g�b�p3_stack
				tim_���t�^�X�g�b�p4.U=tim_���t�^�X�g�b�p4_stack
				tim_���R���x�A����ErrStep.U=tim_���R���x�A����ErrStep_stack
				
				res(timdly_PH63_�����m)
				res(timdly_PH64_�t�^���m)
				res(timdly_PH7_�����m)
				res(timdly_PH8_�t�^���m)

				'---------------------------------
				inc(���R���x�A����EmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(���R���x�A����EmgStep)		
		end if				
	case 4
		timstack=OFF
		���R���x�A����EmgStep=0
		���R���x�A����Emg=OFF
	end select
		
end if 'if Emgstep_proc=0 then
