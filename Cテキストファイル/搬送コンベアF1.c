'�����R���x�AF1
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	�����R���x�AF1
'
'===================================================================================================================
'IH���у��j�b�gA
' [Rx ]---------------------------------
adrset(R47600,pinB�I�����C��.D)
adrset(R47601,pinB�ُ�.D)
adrset(R47602,pinB���쒆.D)
adrset(R47603,pinB�����R�}���h��t�\.D)
adrset(R47604,pinB������t�\.D)
adrset(R47605,pinB���o�v��.D)
adrset(R47606,pinB�������Z���T.D)
adrset(R47607,pinB���o���Z���T.D)
adrset(R47608,pinB���o�R�}���h��t�\.D)

adrset(R47700,pinB�R�}���h��������.D)
adrset(R47701,pinB�Ǐo�����ݒ�.D)
' [Ry ]---------------------------------
adrset(R51600,poutB����~�w��.D)
adrset(R51601,poutB�����w��.D)
adrset(R51602,poutB���o�w��.D)

adrset(R51700,poutB�R�}���h�����v��.D)
adrset(R51701,poutB�Ǐo�����ݒ�.D)
' [Wr ]---------------------------------
adrset(DM12100,pinU���o�A�C�e��NO.D)
adrset(DM12101,pinU���o��NO.D)
adrset(DM12102,pinU�ʂ�No.D)
adrset(DM12103,pinD�|�d��.D)

adrset(DM12105,pinD���f�[�^.D)


adrset(DM12108,pinU�A�C�e���o�^CH1.D)
adrset(DM12109,pinU�A�C�e���o�^CH2.D)
adrset(DM12110,pinU�A�C�e���o�^CH3.D)
adrset(DM12111,pinU�A�C�e���o�^CH4.D)
adrset(DM12112,pinU�A�C�e���o�^CH5.D)
adrset(DM12113,pinU�A�C�e���o�^CH6.D)
adrset(DM12114,pinU�A�C�e���o�^CH7.D)
adrset(DM12115,pinU�R�}���hNo����.D)
adrset(DM12116,pinU�R�}���h�f�[�^0.D)
adrset(DM12117,pinU�R�}���h�f�[�^1.D)
adrset(DM12118,pinU�R�}���h�f�[�^2.D)
adrset(DM12119,pinU�R�}���h�f�[�^3.D)
adrset(DM12120,pinU�R�}���h�f�[�^4.D)
adrset(DM12121,pinU�R�}���h�f�[�^5.D)
adrset(DM12122,pinU�R�}���h�f�[�^6.D)
adrset(DM12123,pinU�R�}���h�f�[�^7.D)
adrset(DM12124,pinU�R�}���h�f�[�^8.D)
adrset(DM12125,pinU�R�}���h�f�[�^9.D)
adrset(DM12126,pinU�R�}���h�f�[�^10.D)
adrset(DM12127,pinU�R�}���h�f�[�^11.D)
adrset(DM12128,pinU�R�}���h�f�[�^12.D)
adrset(DM12129,pinU�R�}���h�f�[�^13.D)
adrset(DM12130,pinU�R�}���h�f�[�^14.D)
adrset(DM12131,pinU�R�}���h�f�[�^15.D)
' [Ww ]---------------------------------
adrset(DM12612,poutU�����A�C�e��NO.D)
adrset(DM12613,poutU������NO.D)
adrset(DM12614,poutU�ʂ�No.D)
adrset(DM12615,poutD�|�d��.D)

adrset(DM12617,poutD���f�[�^.D)


adrset(DM12627,poutU�R�}���hNo.D)
adrset(DM12628,poutU�R�}���h�f�[�^0.D)
adrset(DM12629,poutU�R�}���h�f�[�^1.D)
adrset(DM12630,poutU�R�}���h�f�[�^2.D)
adrset(DM12631,poutU�R�}���h�f�[�^3.D)
adrset(DM12632,poutU�R�}���h�f�[�^4.D)
adrset(DM12633,poutU�R�}���h�f�[�^5.D)
adrset(DM12634,poutU�R�}���h�f�[�^6.D)
adrset(DM12635,poutU�R�}���h�f�[�^7.D)
adrset(DM12636,poutU�R�}���h�f�[�^8.D)
adrset(DM12637,poutU�R�}���h�f�[�^9.D)
adrset(DM12638,poutU�R�}���h�f�[�^10.D)
adrset(DM12639,poutU�R�}���h�f�[�^11.D)
adrset(DM12640,poutU�R�}���h�f�[�^12.D)
adrset(DM12641,poutU�R�}���h�f�[�^13.D)
adrset(DM12642,poutU�R�}���h�f�[�^14.D)
adrset(DM12643,poutU�R�}���h�f�[�^15.D)
' --------------------------------------
'===================================================================================================================


'�y ���������� �z
if CR2008 then '�d��ON������������

	�����R���x�AF1AutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �����R���x�AF1AutoRun=OFF
    �����R���x�AF1����=ON
    �����R���x�AF1OrgErr=OFF
    �����R���x�AF1Err=OFF
    �����R���x�AF1Emg=OFF
    �����R���x�AF1step=0
    �����R���x�AF1ErrStep=0
    �����R���x�AF1OrgErrStep=0
    �����R���x�AF1EmgStep=0

	if SSW3_�������[�h then	
		ManualInite=1
	else
		ManualInite=0	
	end if

	���[�^���[���r�ostep=0
	IH���у��j�b�g���ostep=0
	
end if

'===================================================================================================================
'�y ���_ �z
�����R���x�AF1Org=1

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�����R���x�AF1Emg=ON
	�����R���x�AF1EmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
if ��������AutoMode then
	tmr(MC17_���[�^���[��,timerr_MC17_���[�^���[��,60)
	tmr(MC18_���[�^���[��,timerr_MC18_���[�^���[��,60)
	tmr(MC19_���[�^���[��,timerr_MC19_���[�^���[��,60)
	tmr(MC20_���[�^���[��,timerr_MC20_���[�^���[��,60)
	tmr(MC21_���[�^���[��,timerr_MC21_���[�^���[��,60)
	tmr(MC22_���[�^���[��,timerr_MC22_���[�^���[��,60)
	tmr(MC23_���[�^���[��,timerr_MC23_���[�^���[��,60)
	tmr(MC24_���[�^���[��,timerr_MC24_���[�^���[��,60)
	tmr(MC25_���[�^���[��,timerr_MC25_���[�^���[��,60)
	tmr(MC26_���[�^���[��,timerr_MC26_���[�^���[��,60)
	tmr(MC27_���[�^���[��,timerr_MC27_���[�^���[��,60)
	tmr(MC28_���[�^���[��,timerr_MC28_���[�^���[��,60)
else
	res(timerr_MC17_���[�^���[��)
	res(timerr_MC18_���[�^���[��)
	res(timerr_MC19_���[�^���[��)
	res(timerr_MC20_���[�^���[��)
	res(timerr_MC21_���[�^���[��)
	res(timerr_MC22_���[�^���[��)
	res(timerr_MC23_���[�^���[��)
	res(timerr_MC24_���[�^���[��)
	res(timerr_MC25_���[�^���[��)
	res(timerr_MC26_���[�^���[��)
	res(timerr_MC27_���[�^���[��)
	res(timerr_MC28_���[�^���[��)
end if

if ldp(timerr_MC17_���[�^���[��.B) then
	almMC17_���[�^���[��=ON
	�����R���x�AF1ErrStep=1

else if ldp(timerr_MC18_���[�^���[��.B) then
	almMC18_���[�^���[��=ON
	�����R���x�AF1ErrStep=1

else if ldp(timerr_MC19_���[�^���[��.B) then
	almMC19_���[�^���[��=ON
	�����R���x�AF1ErrStep=1

else if ldp(timerr_MC20_���[�^���[��.B) then
	almMC20_���[�^���[��=ON
	�����R���x�AF1ErrStep=1

else if ldp(timerr_MC21_���[�^���[��.B) then
	almMC21_���[�^���[��=ON
	�����R���x�AF1ErrStep=1

else if ldp(timerr_MC22_���[�^���[��.B) then
	almMC22_���[�^���[��=ON
	�����R���x�AF1ErrStep=1

else if ldp(timerr_MC23_���[�^���[��.B) then
	almMC23_���[�^���[��=ON
	�����R���x�AF1ErrStep=1

else if ldp(timerr_MC24_���[�^���[��.B) then
	almMC24_���[�^���[��=ON
	�����R���x�AF1ErrStep=1

else if ldp(timerr_MC25_���[�^���[��.B) then
	almMC25_���[�^���[��=ON
	�����R���x�AF1ErrStep=1

else if ldp(timerr_MC26_���[�^���[��.B) then
	almMC26_���[�^���[��=ON
	�����R���x�AF1ErrStep=1

else if ldp(timerr_MC27_���[�^���[��.B) then
	almMC27_���[�^���[��=ON
	�����R���x�AF1ErrStep=1

else if ldp(timerr_MC28_���[�^���[��.B) then
	almMC28_���[�^���[��=ON
	�����R���x�AF1ErrStep=1

end if




'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �����R���x�AF1AutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �����R���x�AF1AutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �����R���x�AF1Emg	���̏��~


if �����R���x�AF1EmgStep=0 then  
	
	if �����R���x�AF1ErrStep=0  then

	if not(�����R���x�AF1OrgErr) then

	
	tmr(PH25_�����m,timdly_PH25_�����m,2)
	tmr(PH26_�����m,timdly_PH26_�����m,2)
	tmr(PH27_�����m,timdly_PH27_�����m,2)
	tmr(PH28_�����m,timdly_PH28_�����m,2)
	tmr(PH29_�����m,timdly_PH29_�����m,2)
	tmr(PH30_�����m,timdly_PH30_�����m,2)
	tmr(PH31_�����m,timdly_PH31_�����m,2)
	tmr(PH32_�����m,timdly_PH32_�����m,2)
	tmr(PH33_�����m,timdly_PH33_�����m,2)
	tmr(PH34_�����m,timdly_PH34_�����m,2)
	tmr(PH35_�����m,timdly_PH35_�����m,2)
	tmr(PH36_�����m,timdly_PH36_�����m,2)
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
		
		tim_IH���у��j�b�g���o_val=50
		res(tim_IH���у��j�b�g���o)
		
		inc(IH���у��j�b�g���ostep)

	case 4
		if not(*pinB���o�R�}���h��t�\.B) or errpass���o�w�� or tim_IH���у��j�b�g���o.B then
			inc(IH���у��j�b�g���ostep)
		end if

	case 5
		if errpass���o�w�� then
			IH���у��j�b�g���ostep=0
		else
			*poutB���o�w��.B=OFF
			inc(IH���у��j�b�g���ostep)
		end if
	
	case 6 	
		ejectMC17_���[�^���[��=ON
		inc(IH���у��j�b�g���ostep)
	
	case 7
		'if not(*pinB���o�v��.B) then
			inc(IH���у��j�b�g���ostep)
		'end if
	
	case 8
		if 	PH25_�����m and timdly_PH25_�����m then
			inc(IH���у��j�b�g���ostep)
		 end if
	

	case 9
		tim_IH���у��j�b�g���o_val=6
		res(tim_IH���у��j�b�g���o)
		inc(IH���у��j�b�g���ostep)
	
	case 10
		if tim_IH���у��j�b�g���o.B then
			inc(IH���у��j�b�g���ostep)
		end if

	case 11
		ejectMC17_���[�^���[��=OFF
		inc(IH���у��j�b�g���ostep)

	case 12
		���o�A�C�e��NOA=*pinU���o�A�C�e��NO.U '�� 99
		
		StageDevice13=���o�A�C�e��NOA
		
		if IH�������ъ��J�E���g>0 and  ���o�A�C�e��NOA<99 then
			dec(IH�������ъ��J�E���g)
		end if


		IH���у��j�b�g���ostep=0
		
	end select

	
	'---------------------------------------------------------------------------------------
	tmr(tim_���[�^���[���r�o,tim_���[�^���[���r�o_val)
	select case ���[�^���[���r�ostep
	case 0
	
	case 1
		if PH36_�����m then
			���[�^���[���r�ostep=0
		else
			���[�^���[���r�ostep=100
		end if


	'PH35_�����m MC27_���[�^���[��	StageDevice23
	'PH36_�����m MC28_���[�^���[��	StageDevice24
		'----------------------------------
	case 100
		'----------------------------------
		if not(PH36_�����m) and PH35_�����m then 
			mMC27_���[�^���[��=ON
			mMC28_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 101
		if not(PH35_�����m) and not(PH36_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 102
		if PH36_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 103
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 104
		if tim_���[�^���[���r�o.B then
			mMC27_���[�^���[��=OFF
			mMC28_���[�^���[��=OFF

			StageDevice24=StageDevice23
			StageDevice23=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 105
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 106
		if tim_���[�^���[���r�o.B then
			inc(���[�^���[���r�ostep)
		end if
		


	'PH34_�����m MC26_���[�^���[��	StageDevice22
	'PH35_�����m MC27_���[�^���[��	StageDevice23
		'----------------------------------
	case 107
		if not(PH35_�����m) and PH34_�����m then 
			mMC26_���[�^���[��=ON
			mMC27_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 108
		if not(PH34_�����m) and not(PH35_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 109
		if PH35_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 110
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 111
		if tim_���[�^���[���r�o.B then
			mMC26_���[�^���[��=OFF
			mMC27_���[�^���[��=OFF

			StageDevice23=StageDevice22
			StageDevice22=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 112
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 113
		if tim_���[�^���[���r�o.B then
			if PH36_�����m or 1 then
				inc(���[�^���[���r�ostep)
			else
				���[�^���[���r�ostep=100
			end if
		end if

	'PH33_�����m MC25_���[�^���[��	StageDevice21
	'PH34_�����m MC26_���[�^���[��	StageDevice22
		'----------------------------------
	case 114
		'----------------------------------
		if not(PH34_�����m) and PH33_�����m then 
			mMC25_���[�^���[��=ON
			mMC26_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 115
		if not(PH33_�����m) and not(PH34_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 116
		if PH34_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 117
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 118
		if tim_���[�^���[���r�o.B then
			mMC25_���[�^���[��=OFF
			mMC26_���[�^���[��=OFF

			StageDevice22=StageDevice21
			StageDevice21=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 119
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 120
		if tim_���[�^���[���r�o.B then
			if PH35_�����m or 1 then
				inc(���[�^���[���r�ostep)
			else
				���[�^���[���r�ostep=107
			end if
		end if

	'PH32_�����m MC24_���[�^���[��	StageDevice20
	'PH33_�����m MC25_���[�^���[��	StageDevice21
		'----------------------------------
	case 121
		'----------------------------------
		if not(PH33_�����m) and PH32_�����m then 
			mMC24_���[�^���[��=ON
			mMC25_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 122
		if not(PH32_�����m) and not(PH33_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 123
		if PH33_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 124
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 125
		if tim_���[�^���[���r�o.B then
			mMC24_���[�^���[��=OFF
			mMC25_���[�^���[��=OFF

			StageDevice21=StageDevice20
			StageDevice20=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 126
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 127
		if tim_���[�^���[���r�o.B then
			if PH34_�����m or 1 then
				inc(���[�^���[���r�ostep)
			else
				���[�^���[���r�ostep=114
			end if
		end if

	'PH31_�����m MC23_���[�^���[��	StageDevice19
	'PH32_�����m MC24_���[�^���[��	StageDevice20
		'----------------------------------
	case 128
		'----------------------------------
		if not(PH32_�����m) and PH31_�����m then 
			mMC23_���[�^���[��=ON
			mMC24_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 129
		if not(PH31_�����m) and not(PH32_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 130
		if PH32_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 131
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 132
		if tim_���[�^���[���r�o.B then
			mMC23_���[�^���[��=OFF
			mMC24_���[�^���[��=OFF

			StageDevice20=StageDevice19
			StageDevice19=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 133
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 134
		if tim_���[�^���[���r�o.B then
			if PH33_�����m or 1 then
				inc(���[�^���[���r�ostep)
			else
				���[�^���[���r�ostep=121
			end if
		end if

	'PH30_�����m MC22_���[�^���[��	StageDevice18
	'PH31_�����m MC23_���[�^���[��	StageDevice19
		'----------------------------------
	case 135
		'----------------------------------
		if not(PH31_�����m) and PH30_�����m then 
			mMC22_���[�^���[��=ON
			mMC23_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 136
		if not(PH30_�����m) and not(PH31_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 137
		if PH31_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 138
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 139
		if tim_���[�^���[���r�o.B then
			mMC22_���[�^���[��=OFF
			mMC23_���[�^���[��=OFF

			StageDevice19=StageDevice18
			StageDevice18=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 140
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 141
		if tim_���[�^���[���r�o.B then
			if PH32_�����m or 1 then
				inc(���[�^���[���r�ostep)
			else
				���[�^���[���r�ostep=128
			end if
		end if

	'PH29_�����m MC21_���[�^���[��	StageDevice17
	'PH30_�����m MC22_���[�^���[��	StageDevice18
		'----------------------------------
	case 142
		'----------------------------------
		if not(PH30_�����m) and PH29_�����m then 
			mMC21_���[�^���[��=ON
			mMC22_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 143
		if not(PH29_�����m) and not(PH30_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 144
		if PH30_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 145
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 146
		if tim_���[�^���[���r�o.B then
			mMC21_���[�^���[��=OFF
			mMC22_���[�^���[��=OFF

			StageDevice18=StageDevice17
			StageDevice17=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 147
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 148
		if tim_���[�^���[���r�o.B then
			if PH31_�����m or 1 then
				inc(���[�^���[���r�ostep)
			else
				���[�^���[���r�ostep=135
			end if
		end if

	'PH28_�����m MC20_���[�^���[��	StageDevice16
	'PH29_�����m MC21_���[�^���[��	StageDevice17
		'----------------------------------
	case 149
		'----------------------------------
		if not(PH29_�����m) and PH28_�����m then 
			mMC20_���[�^���[��=ON
			mMC21_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 150
		if not(PH28_�����m) and not(PH29_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 151
		if PH29_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 152
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 153
		if tim_���[�^���[���r�o.B then
			mMC20_���[�^���[��=OFF
			mMC21_���[�^���[��=OFF

			StageDevice17=StageDevice16
			StageDevice16=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 154
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 155
		if tim_���[�^���[���r�o.B then
			if PH30_�����m or 1 then
				inc(���[�^���[���r�ostep)
			else
				���[�^���[���r�ostep=142
			end if
		end if

	'PH27_�����m MC19_���[�^���[��	StageDevice15
	'PH28_�����m MC20_���[�^���[��	StageDevice16
		'----------------------------------
	case 156
		'----------------------------------
		if not(PH28_�����m) and PH27_�����m then 
			mMC19_���[�^���[��=ON
			mMC20_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 157
		if not(PH27_�����m) and not(PH28_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 158
		if PH28_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 159
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 160
		if tim_���[�^���[���r�o.B then
			mMC19_���[�^���[��=OFF
			mMC20_���[�^���[��=OFF

			StageDevice16=StageDevice15
			StageDevice15=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 161
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 162
		if tim_���[�^���[���r�o.B then
			if PH29_�����m or 1 then
				inc(���[�^���[���r�ostep)
			else
				���[�^���[���r�ostep=149
			end if
		end if

	'PH26_�����m MC18_���[�^���[��	StageDevice14
	'PH27_�����m MC19_���[�^���[��	StageDevice15
		'----------------------------------
	case 163
		'----------------------------------
		if not(PH27_�����m) and PH26_�����m then 
			mMC18_���[�^���[��=ON
			mMC19_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 164
		if not(PH26_�����m) and not(PH27_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 165
		if PH27_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 166
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 167
		if tim_���[�^���[���r�o.B then
			mMC18_���[�^���[��=OFF
			mMC19_���[�^���[��=OFF

			StageDevice15=StageDevice14
			StageDevice14=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 168
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 169
		if tim_���[�^���[���r�o.B then
			if PH28_�����m or 1 then
				inc(���[�^���[���r�ostep)
			else
				���[�^���[���r�ostep=156
			end if
		end if

	'PH25_�����m MC17_���[�^���[��	StageDevice13
	'PH26_�����m MC18_���[�^���[��	StageDevice14
		'----------------------------------
	case 170
		'----------------------------------
		if not(PH26_�����m) and PH25_�����m then 
			mMC17_���[�^���[��=ON
			mMC18_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 171
		if not(PH25_�����m) and not(PH26_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 172
		if PH26_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 173
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 174
		if tim_���[�^���[���r�o.B then
			mMC17_���[�^���[��=OFF
			mMC18_���[�^���[��=OFF

			StageDevice14=StageDevice13
			StageDevice13=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 175
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 176
		if tim_���[�^���[���r�o.B then
			if PH27_�����m or 1 then
				inc(���[�^���[���r�ostep)
			else
				���[�^���[���r�ostep=163
			end if
		end if

		'----------------------------------
	case 177
		'----------------------------------
		���[�^���[���r�ostep=0
	end select

	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
	if (�����R���x�AF1AutoMode and ��������AutoMode ) or �����R���x�AF1step<>0 then
	
		if ManualInite=1 then
			ManualInite=0
		end if
		
		if not(�����R���x�AF1AutoMode and ��������AutoMode ) then
			�����R���x�AF1AutoRun=OFF
		end if


		tmr(tim_procstep,tim_procstep_val)

		select case �����R���x�AF1step
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �����R���x�AF1AutoRun then
				inc(�����R���x�AF1step)
			else 
				�����R���x�AF1step=0 '�I���ҋ@
			end if
		
		case 2
			if PH36_�����m then
				�����R���x�AF1���쒆=OFF
				�����R���x�AF1�r�o�v��=ON
				�����R���x�AF1step=1
			else
				inc(�����R���x�AF1step)
			end if

		case 3
			if IH���ы@A�֎~ then
				inc(�����R���x�AF1step)				
			else 
				if *pinB�I�����C��.B and *pinB�ُ�.B then
					inc(�����R���x�AF1step)
				else
					�����R���x�AF1step=1
				end if
			end if
				
		case 4
		' [ ���̔����R���x�A��~�m�F ]
			if �����R���x�AF1�r�o�v��=OFF and  �����R���x�AG���쒆=OFF and (IH���ы@A�֎~ or (*pinB���o�R�}���h��t�\.B and *pinB���o�v��.B)) then
				�����R���x�AF1���쒆=ON
				�����R���x�AF1step=100
			else
				�����R���x�AF1step=1
			end if
			
		'--------------------------------------------------------------------------------------------------------------
		case 100
			�����R���x�AF1�����m = PH25_�����m
			�����R���x�AF1�����m = �����R���x�AF1�����m or PH26_�����m
			�����R���x�AF1�����m = �����R���x�AF1�����m or PH27_�����m
			�����R���x�AF1�����m = �����R���x�AF1�����m or PH28_�����m
			�����R���x�AF1�����m = �����R���x�AF1�����m or PH29_�����m
			�����R���x�AF1�����m = �����R���x�AF1�����m or PH30_�����m
			�����R���x�AF1�����m = �����R���x�AF1�����m or PH31_�����m
			�����R���x�AF1�����m = �����R���x�AF1�����m or PH32_�����m
			�����R���x�AF1�����m = �����R���x�AF1�����m or PH33_�����m
			�����R���x�AF1�����m = �����R���x�AF1�����m or PH34_�����m
			�����R���x�AF1�����m = �����R���x�AF1�����m or PH35_�����m
			inc(�����R���x�AF1step)

		case 101
			if �����R���x�AF1�����m or *pinB���o���Z���T.B then
				inc(�����R���x�AF1step)
			else
				�����R���x�AF1step=1
			end if

		case 102
			���[�^���[���r�ostep=1
			inc(�����R���x�AF1step)
			
		case 103
			if ���[�^���[���r�ostep=0 then
				inc(�����R���x�AF1step)
			end if
	
		'------------------------------------------------------------------------
		case 104
			if PH36_�����m then
				�����R���x�AF1�r�o�v��=ON
			end if
			inc(�����R���x�AF1step)
			
		'------------------------------------------------------------------------
		case 105
			if not(PH25_�����m) then
				IH���у��j�b�g���ostep=1
				inc(�����R���x�AF1step)
			end if
		
		case 106
			if IH���у��j�b�g���ostep=0 then
				inc(�����R���x�AF1step)
			end if

		'------------------------------------------------------------------------
		case 107
			
			�����R���x�AF1���쒆=OFF
			�����R���x�AF1step=1

		'--------------------------------------------------------------------------------------------------------------
		case 200
			if not(PH36_�����m) then
				inc(�����R���x�AF1step)
			else
				�����R���x�AF1step=1
			end if

		case 201
			mMC17_���[�^���[��=ON
			mMC18_���[�^���[��=ON
			mMC19_���[�^���[��=ON
			mMC20_���[�^���[��=ON
			mMC21_���[�^���[��=ON
			mMC22_���[�^���[��=ON
			mMC23_���[�^���[��=ON
			mMC24_���[�^���[��=ON
			mMC25_���[�^���[��=ON
			mMC26_���[�^���[��=ON
			mMC27_���[�^���[��=ON
			mMC28_���[�^���[��=ON
			inc(�����R���x�AF1step)
		
		case 202
			if PH36_�����m then
				inc(�����R���x�AF1step)
			end if
		
		case 203
			mMC17_���[�^���[��=OFF
			mMC18_���[�^���[��=OFF
			mMC19_���[�^���[��=OFF
			mMC20_���[�^���[��=OFF
			mMC21_���[�^���[��=OFF
			mMC22_���[�^���[��=OFF
			mMC23_���[�^���[��=OFF
			mMC24_���[�^���[��=OFF
			mMC25_���[�^���[��=OFF
			mMC26_���[�^���[��=OFF
			mMC27_���[�^���[��=OFF
			mMC28_���[�^���[��=OFF
			�����R���x�AF1step=1
			

		
		end select



	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		if ManualInite=0 then
			ManualInite=1
		end if
	
		�����R���x�AF1AutoRun=OFF
		
		�����R���x�AF1step=0 '�I��


		res(timerr_MC17_���[�^���[��)'tmr(MC17_���[�^���[��,timerr_MC18_���[�^���[��,60)
		res(timerr_MC18_���[�^���[��)'tmr(MC18_���[�^���[��,timerr_MC18_���[�^���[��,60)
		res(timerr_MC19_���[�^���[��)'tmr(MC19_���[�^���[��,timerr_MC19_���[�^���[��,60)
		res(timerr_MC20_���[�^���[��)'tmr(MC20_���[�^���[��,timerr_MC20_���[�^���[��,60)
		res(timerr_MC21_���[�^���[��)'tmr(MC21_���[�^���[��,timerr_MC21_���[�^���[��,60)
		res(timerr_MC22_���[�^���[��)'tmr(MC22_���[�^���[��,timerr_MC22_���[�^���[��,60)
		res(timerr_MC23_���[�^���[��)'tmr(MC23_���[�^���[��,timerr_MC23_���[�^���[��,60)
		res(timerr_MC24_���[�^���[��)'tmr(MC24_���[�^���[��,timerr_MC24_���[�^���[��,60)
		res(timerr_MC25_���[�^���[��)'tmr(MC25_���[�^���[��,timerr_MC25_���[�^���[��,60)
		res(timerr_MC26_���[�^���[��)'tmr(MC26_���[�^���[��,timerr_MC26_���[�^���[��,60)
		res(timerr_MC27_���[�^���[��)'tmr(MC27_���[�^���[��,timerr_MC27_���[�^���[��,60)
		res(timerr_MC28_���[�^���[��)'tmr(MC28_���[�^���[��,timerr_MC28_���[�^���[��,60)
		
		if ldp(pnlPBMC17_���[�^���[��) then
			if mMC17_���[�^���[�� then
				mMC17_���[�^���[��=OFF
			else 
				mMC17_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC18_���[�^���[��) then
			if mMC18_���[�^���[�� then
				mMC18_���[�^���[��=OFF
			else 
				mMC18_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC19_���[�^���[��) then
			if mMC19_���[�^���[�� then
				mMC19_���[�^���[��=OFF
			else 
				mMC19_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC20_���[�^���[��) then
			if mMC20_���[�^���[�� then
				mMC20_���[�^���[��=OFF
			else 
				mMC20_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC21_���[�^���[��) then
			if mMC21_���[�^���[�� then
				mMC21_���[�^���[��=OFF
			else 
				mMC21_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC22_���[�^���[��) then
			if mMC22_���[�^���[�� then
				mMC22_���[�^���[��=OFF
			else 
				mMC22_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC23_���[�^���[��) then
			if mMC23_���[�^���[�� then
				mMC23_���[�^���[��=OFF
			else 
				mMC23_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC24_���[�^���[��) then
			if mMC24_���[�^���[�� then
				mMC24_���[�^���[��=OFF
			else 
				mMC24_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC25_���[�^���[��) then
			if mMC25_���[�^���[�� then
				mMC25_���[�^���[��=OFF
			else 
				mMC25_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC26_���[�^���[��) then
			if mMC26_���[�^���[�� then
				mMC26_���[�^���[��=OFF
			else 
				mMC26_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC27_���[�^���[��) then
			if mMC27_���[�^���[�� then
				mMC27_���[�^���[��=OFF
			else 
				mMC27_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC28_���[�^���[��) then
			if mMC28_���[�^���[�� then
				mMC28_���[�^���[��=OFF
			else 
				mMC28_���[�^���[��=ON
			end if
		end if
		
			
	end if '�����R���x�AF1AutoMode and not(�����R���x�AF1OrgErrStep)

	'===================================================================================================================
	'�y �����R���x�AF1OrgErr���� �z
	else
	
		if ResetFlg then
			�����R���x�AF1OrgErr=OFF
		end if


	end if

	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else

		�����R���x�AF1Err=ON

		pauseMC17_���[�^���[��=ON
		pauseMC18_���[�^���[��=ON
		pauseMC19_���[�^���[��=ON
		pauseMC20_���[�^���[��=ON
		pauseMC21_���[�^���[��=ON
		pauseMC22_���[�^���[��=ON
		pauseMC23_���[�^���[��=ON
		pauseMC24_���[�^���[��=ON
		pauseMC25_���[�^���[��=ON
		pauseMC26_���[�^���[��=ON
		pauseMC27_���[�^���[��=ON
		pauseMC28_���[�^���[��=ON

		select case �����R���x�AF1ErrStep
		case 0
		case 1
			if ResetFlg then
				almMC17_���[�^���[��=OFF
				almMC18_���[�^���[��=OFF
				almMC19_���[�^���[��=OFF
				almMC20_���[�^���[��=OFF
				almMC21_���[�^���[��=OFF
				almMC22_���[�^���[��=OFF
				almMC23_���[�^���[��=OFF
				almMC24_���[�^���[��=OFF
				almMC25_���[�^���[��=OFF
				almMC26_���[�^���[��=OFF
				almMC27_���[�^���[��=OFF
				almMC28_���[�^���[��=OFF
				inc(�����R���x�AF1ErrStep)
			end if
		case 2
			pauseMC17_���[�^���[��=OFF
			pauseMC18_���[�^���[��=OFF
			pauseMC19_���[�^���[��=OFF
			pauseMC20_���[�^���[��=OFF
			pauseMC21_���[�^���[��=OFF
			pauseMC22_���[�^���[��=OFF
			pauseMC23_���[�^���[��=OFF
			pauseMC24_���[�^���[��=OFF
			pauseMC25_���[�^���[��=OFF
			pauseMC26_���[�^���[��=OFF
			pauseMC27_���[�^���[��=OFF
			pauseMC28_���[�^���[��=OFF


			�����R���x�AF1Err=OFF
			�����R���x�AF1ErrStep=0
		end select

	end if 'if �����R���x�AF1ErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	
	select case �����R���x�AF1EmgStep
	case 0
		
	case 1
		�����R���x�AF1AutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�����R���x�AF1AutoMode and ��������AutoMode ) or �����R���x�AF1step<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseMC17_���[�^���[��=ON
			pauseMC18_���[�^���[��=ON
			pauseMC19_���[�^���[��=ON
			pauseMC20_���[�^���[��=ON
			pauseMC21_���[�^���[��=ON
			pauseMC22_���[�^���[��=ON
			pauseMC23_���[�^���[��=ON
			pauseMC24_���[�^���[��=ON
			pauseMC25_���[�^���[��=ON
			pauseMC26_���[�^���[��=ON
			pauseMC27_���[�^���[��=ON
			pauseMC28_���[�^���[��=ON
			
			if timstack=OFF then
				timdly_PH25_�����m_stack=timdly_PH25_�����m.U
				timdly_PH26_�����m_stack=timdly_PH26_�����m.U
				timdly_PH27_�����m_stack=timdly_PH27_�����m.U
				timdly_PH28_�����m_stack=timdly_PH28_�����m.U
				timdly_PH29_�����m_stack=timdly_PH29_�����m.U
				timdly_PH30_�����m_stack=timdly_PH30_�����m.U
				timdly_PH31_�����m_stack=timdly_PH31_�����m.U
				timdly_PH32_�����m_stack=timdly_PH32_�����m.U
				timdly_PH33_�����m_stack=timdly_PH33_�����m.U
				timdly_PH34_�����m_stack=timdly_PH34_�����m.U
				timdly_PH35_�����m_stack=timdly_PH35_�����m.U
				timdly_PH36_�����m_stack=timdly_PH36_�����m.U
				tim_procstep_stack=tim_procstep.U
				tim_IH���у��j�b�g����_stack=tim_IH���у��j�b�g����.U
				tim_MC17_���[�^���[��_stack=tim_MC17_���[�^���[��.U
				tim_MC18_���[�^���[��_stack=tim_MC18_���[�^���[��.U
				tim_MC19_���[�^���[��_stack=tim_MC19_���[�^���[��.U
				tim_�����w��_stack=tim_�����w��.U
				tim_���o�w��_stack=tim_���o�w��.U
				tim_MC20_���[�^���[��_stack=tim_MC20_���[�^���[��.U
				tim_MC21_���[�^���[��_stack=tim_MC21_���[�^���[��.U
				tim_MC22_���[�^���[��_stack=tim_MC22_���[�^���[��.U
				tim_MC23_���[�^���[��_stack=tim_MC23_���[�^���[��.U
				tim_���[�^���[���r�o_stack=tim_���[�^���[���r�o.U
				tim_MC24_���[�^���[��_stack=tim_MC24_���[�^���[��.U
				tim_MC25_���[�^���[��_stack=tim_MC25_���[�^���[��.U
				tim_MC26_���[�^���[��_stack=tim_MC26_���[�^���[��.U
				tim_MC27_���[�^���[��_stack=tim_MC27_���[�^���[��.U
				tim_MC28_���[�^���[��_stack=tim_MC28_���[�^���[��.U
				tim_IH���у��j�b�g���o_stack=tim_IH���у��j�b�g���o.U
				timdly_PH49_�����m_stack=timdly_PH49_�����m.U

				timstack=ON
			end if
			
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC17_���[�^���[��=OFF
			mMC18_���[�^���[��=OFF
			mMC19_���[�^���[��=OFF
			mMC20_���[�^���[��=OFF
			mMC21_���[�^���[��=OFF
			mMC22_���[�^���[��=OFF
			mMC23_���[�^���[��=OFF
			mMC24_���[�^���[��=OFF
			mMC25_���[�^���[��=OFF
			mMC26_���[�^���[��=OFF
			mMC27_���[�^���[��=OFF
			mMC28_���[�^���[��=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�����R���x�AF1EmgStep)
	case 2
		if ResetFlg then
			inc(�����R���x�AF1EmgStep)
		end if
	case 3
		if (�����R���x�AF1AutoMode and ��������AutoMode ) or �����R���x�AF1step<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseMC17_���[�^���[��=OFF
				pauseMC18_���[�^���[��=OFF
				pauseMC19_���[�^���[��=OFF
				pauseMC20_���[�^���[��=OFF
				pauseMC21_���[�^���[��=OFF
				pauseMC22_���[�^���[��=OFF
				pauseMC23_���[�^���[��=OFF
				pauseMC24_���[�^���[��=OFF
				pauseMC25_���[�^���[��=OFF
				pauseMC26_���[�^���[��=OFF
				pauseMC27_���[�^���[��=OFF
				pauseMC28_���[�^���[��=OFF

						
				timdly_PH25_�����m.U=timdly_PH25_�����m_stack
				timdly_PH26_�����m.U=timdly_PH26_�����m_stack
				timdly_PH27_�����m.U=timdly_PH27_�����m_stack
				timdly_PH28_�����m.U=timdly_PH28_�����m_stack
				timdly_PH29_�����m.U=timdly_PH29_�����m_stack
				timdly_PH30_�����m.U=timdly_PH30_�����m_stack
				timdly_PH31_�����m.U=timdly_PH31_�����m_stack
				timdly_PH32_�����m.U=timdly_PH32_�����m_stack
				timdly_PH33_�����m.U=timdly_PH33_�����m_stack
				timdly_PH34_�����m.U=timdly_PH34_�����m_stack
				timdly_PH35_�����m.U=timdly_PH35_�����m_stack
				timdly_PH36_�����m.U=timdly_PH36_�����m_stack
				tim_procstep.U=tim_procstep_stack
				tim_IH���у��j�b�g����.U=tim_IH���у��j�b�g����_stack
				tim_MC17_���[�^���[��.U=tim_MC17_���[�^���[��_stack
				tim_MC18_���[�^���[��.U=tim_MC18_���[�^���[��_stack
				tim_MC19_���[�^���[��.U=tim_MC19_���[�^���[��_stack
				tim_�����w��.U=tim_�����w��_stack
				tim_���o�w��.U=tim_���o�w��_stack
				tim_MC20_���[�^���[��.U=tim_MC20_���[�^���[��_stack
				tim_MC21_���[�^���[��.U=tim_MC21_���[�^���[��_stack
				tim_MC22_���[�^���[��.U=tim_MC22_���[�^���[��_stack
				tim_MC23_���[�^���[��.U=tim_MC23_���[�^���[��_stack
				tim_���[�^���[���r�o.U=tim_���[�^���[���r�o_stack
				tim_MC24_���[�^���[��.U=tim_MC24_���[�^���[��_stack
				tim_MC25_���[�^���[��.U=tim_MC25_���[�^���[��_stack
				tim_MC26_���[�^���[��.U=tim_MC26_���[�^���[��_stack
				tim_MC27_���[�^���[��.U=tim_MC27_���[�^���[��_stack
				tim_MC28_���[�^���[��.U=tim_MC28_���[�^���[��_stack
				tim_IH���у��j�b�g���o.U=tim_IH���у��j�b�g���o_stack
				timdly_PH49_�����m.U=timdly_PH49_�����m_stack

				
				'---------------------------------
				inc(�����R���x�AF1EmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�����R���x�AF1EmgStep)		
		end if				
	case 4
		timstack=OFF
		�����R���x�AF1EmgStep=0
		�����R���x�AF1Emg=OFF
	end select

		
end if 'if �����R���x�AF1EmgStep=0 then
