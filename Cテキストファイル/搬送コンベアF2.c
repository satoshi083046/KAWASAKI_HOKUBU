'�����R���x�AF2
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	�����R���x�AF2
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

'===================================================================================================================

'�y ���������� �z
if CR2008 then '�d��ON������������

	�����R���x�AF2AutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �����R���x�AF2AutoRun=OFF
    �����R���x�AF2����=ON
    �����R���x�AF2OrgErr=OFF
    �����R���x�AF2Err=OFF
    �����R���x�AF2Emg=OFF
    �����R���x�AF2step=0
    �����R���x�AF2ErrStep=0
    �����R���x�AF2OrgErrStep=0
    �����R���x�AF2EmgStep=0

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
�����R���x�AF2Org=1

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�����R���x�AF2Emg=ON
	�����R���x�AF2EmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

if ��������AutoMode then
	tmr(MC29_���[�^���[��,timerr_MC29_���[�^���[��,60)
	tmr(MC30_���[�^���[��,timerr_MC30_���[�^���[��,60)
	tmr(MC31_���[�^���[��,timerr_MC31_���[�^���[��,60)
	tmr(MC32_���[�^���[��,timerr_MC32_���[�^���[��,60)
	tmr(MC33_���[�^���[��,timerr_MC33_���[�^���[��,60)
	tmr(MC47_���[�^���[��,timerr_MC47_���[�^���[��,60)
	tmr(MC48_���[�^���[��,timerr_MC48_���[�^���[��,60)
	tmr(MC49_���[�^���[��,timerr_MC49_���[�^���[��,60)
	tmr(MC50_���[�^���[��,timerr_MC50_���[�^���[��,60)
	tmr(MC51_���[�^���[��,timerr_MC51_���[�^���[��,60)
	tmr(MC52_���[�^���[��,timerr_MC52_���[�^���[��,60)
	tmr(MC53_���[�^���[��,timerr_MC53_���[�^���[��,60)
else
	res(timerr_MC29_���[�^���[��)
	res(timerr_MC30_���[�^���[��)
	res(timerr_MC31_���[�^���[��)
	res(timerr_MC32_���[�^���[��)
	res(timerr_MC33_���[�^���[��)
	res(timerr_MC47_���[�^���[��)
	res(timerr_MC48_���[�^���[��)
	res(timerr_MC49_���[�^���[��)
	res(timerr_MC50_���[�^���[��)
	res(timerr_MC51_���[�^���[��)
	res(timerr_MC52_���[�^���[��)
	res(timerr_MC53_���[�^���[��)
end if

if ldp(timerr_MC29_���[�^���[��.B) then
	almMC29_���[�^���[��=ON
	�����R���x�AF2ErrStep=1

else if ldp(timerr_MC30_���[�^���[��.B) then
	almMC30_���[�^���[��=ON
	�����R���x�AF2ErrStep=1

else if ldp(timerr_MC31_���[�^���[��.B) then
	almMC31_���[�^���[��=ON
	�����R���x�AF2ErrStep=1

else if ldp(timerr_MC32_���[�^���[��.B) then
	almMC32_���[�^���[��=ON
	�����R���x�AF2ErrStep=1

else if ldp(timerr_MC33_���[�^���[��.B) then
	almMC33_���[�^���[��=ON
	�����R���x�AF2ErrStep=1

else if ldp(timerr_MC47_���[�^���[��.B) then
	almMC47_���[�^���[��=ON
	�����R���x�AF2ErrStep=1

else if ldp(timerr_MC48_���[�^���[��.B) then
	almMC48_���[�^���[��=ON
	�����R���x�AF2ErrStep=1

else if ldp(timerr_MC49_���[�^���[��.B) then
	almMC49_���[�^���[��=ON
	�����R���x�AF2ErrStep=1

else if ldp(timerr_MC50_���[�^���[��.B) then
	almMC50_���[�^���[��=ON
	�����R���x�AF2ErrStep=1

else if ldp(timerr_MC51_���[�^���[��.B) then
	almMC51_���[�^���[��=ON
	�����R���x�AF2ErrStep=1

else if ldp(timerr_MC52_���[�^���[��.B) then
	almMC52_���[�^���[��=ON
	�����R���x�AF2ErrStep=1

else if ldp(timerr_MC53_���[�^���[��.B) then
	almMC53_���[�^���[��=ON
	�����R���x�AF2ErrStep=1

end if



'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �����R���x�AF2AutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �����R���x�AF2AutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �����R���x�AF2Emg	���̏��~


if �����R���x�AF2EmgStep=0 then  
	
	if �����R���x�AF2ErrStep=0  then

	if not(�����R���x�AF2OrgErr) then

	
	tmr(PH37_�����m,timdly_PH37_�����m,2)
	tmr(PH38_�����m,timdly_PH38_�����m,2)
	tmr(PH39_�����m,timdly_PH39_�����m,2)
	tmr(PH40_�����m,timdly_PH40_�����m,2)
	tmr(PH41_�����m,timdly_PH41_�����m,2)
	tmr(PH42_�����m,timdly_PH42_�����m,2)
	tmr(PH43_�����m,timdly_PH43_�����m,2)
	tmr(PH44_�����m,timdly_PH44_�����m,2)
	tmr(PH45_�����m,timdly_PH45_�����m,2)
	tmr(PH46_�����m,timdly_PH46_�����m,2)
	tmr(PH47_�����m,timdly_PH47_�����m,2)
	tmr(PH48_�����m,timdly_PH48_�����m,2)

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
	case 6
		ejectMC29_���[�^���[��=ON
		inc(IH���у��j�b�g���ostep)
	
	case 7
		'if not(*pinB���o�v��.B) then
			inc(IH���у��j�b�g���ostep)
		'end if
	
	case 8
		if 	PH37_�����m then
			inc(IH���у��j�b�g���ostep)
		 end if

	case 9
		tim_IH���у��j�b�g���o_val=8
		res(tim_IH���у��j�b�g���o)
		inc(IH���у��j�b�g���ostep)
	
	case 10
		if tim_IH���у��j�b�g���o.B then
			inc(IH���у��j�b�g���ostep)
		end if

	case 11
		ejectMC29_���[�^���[��=OFF
		inc(IH���у��j�b�g���ostep)

	case 12
		���o�A�C�e��NOB=*pinU���o�A�C�e��NO.U '�� 99
		StageDevice25=���o�A�C�e��NOB

		if IH�������ъ��J�E���g>0 and ���o�A�C�e��NOB<99 then
			dec(IH�������ъ��J�E���g)
		end if

		IH���у��j�b�g���ostep=0
		
	end select
	'---------------------------------------------------------------------------------------
	tmr(tim_���[�^���[���r�o,tim_���[�^���[���r�o_val)
	select case ���[�^���[���r�ostep
	case 0
	
	case 1
		if PH48_�����m then
			���[�^���[���r�ostep=0
		else
			���[�^���[���r�ostep=100
		end if
	

	'PH47_�����m MC52_���[�^���[��	StageDevice35
	'PH48_�����m MC53_���[�^���[��	StageDevice36
		'----------------------------------
	case 100
		'----------------------------------
		if not(PH48_�����m) and PH47_�����m then 
			mMC52_���[�^���[��=ON
			mMC53_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 101
		if not(PH47_�����m) and not(PH48_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 102
		if PH48_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 103
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 104
		if tim_���[�^���[���r�o.B then
			mMC52_���[�^���[��=OFF
			mMC53_���[�^���[��=OFF

			StageDevice36=StageDevice35
			StageDevice35=0

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
		

	'PH46_�����m MC51_���[�^���[��	StageDevice34
	'PH47_�����m MC52_���[�^���[��	StageDevice35
		'----------------------------------
	case 107
		if not(PH47_�����m) and PH46_�����m then 
			mMC51_���[�^���[��=ON
			mMC52_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 108
		if not(PH46_�����m) and not(PH47_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 109
		if PH47_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 110
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 111
		if tim_���[�^���[���r�o.B then
			mMC51_���[�^���[��=OFF
			mMC52_���[�^���[��=OFF

			StageDevice35=StageDevice34
			StageDevice34=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 112
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 113
		if tim_���[�^���[���r�o.B then
			if PH48_�����m or 1 then
				inc(���[�^���[���r�ostep)
			else
				���[�^���[���r�ostep=100
			end if
		end if

	'PH45_�����m MC50_���[�^���[��	StageDevice33
	'PH46_�����m MC51_���[�^���[��	StageDevice34
		'----------------------------------
	case 114
		'----------------------------------
		if not(PH46_�����m) and PH45_�����m then 
			mMC50_���[�^���[��=ON
			mMC51_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 115
		if not(PH45_�����m) and not(PH46_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 116
		if PH46_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 117
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 118
		if tim_���[�^���[���r�o.B then
			mMC50_���[�^���[��=OFF
			mMC51_���[�^���[��=OFF

			StageDevice34=StageDevice33
			StageDevice33=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 119
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 120
		if tim_���[�^���[���r�o.B then
			if PH47_�����m or 1 then
				inc(���[�^���[���r�ostep)
			else
				���[�^���[���r�ostep=107
			end if
		end if

	'PH44_�����m MC49_���[�^���[��	StageDevice32
	'PH45_�����m MC50_���[�^���[��	StageDevice33
		'----------------------------------
	case 121
		'----------------------------------
		if not(PH45_�����m) and PH44_�����m then 
			mMC49_���[�^���[��=ON
			mMC50_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 122
		if not(PH44_�����m) and not(PH45_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 123
		if PH45_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 124
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 125
		if tim_���[�^���[���r�o.B then
			mMC49_���[�^���[��=OFF
			mMC50_���[�^���[��=OFF

			StageDevice33=StageDevice32
			StageDevice32=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 126
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 127
		if tim_���[�^���[���r�o.B then
			if PH46_�����m or 1 then
				inc(���[�^���[���r�ostep)
			else
				���[�^���[���r�ostep=114
			end if
		end if

	'PH43_�����m MC48_���[�^���[��	StageDevice31
	'PH44_�����m MC49_���[�^���[��	StageDevice32
		'----------------------------------
	case 128
		'----------------------------------
		if not(PH44_�����m) and PH43_�����m then 
			mMC48_���[�^���[��=ON
			mMC49_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 129
		if not(PH43_�����m) and not(PH44_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 130
		if PH44_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 131
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 132
		if tim_���[�^���[���r�o.B then
			mMC48_���[�^���[��=OFF
			mMC49_���[�^���[��=OFF

			StageDevice32=StageDevice31
			StageDevice31=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 133
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 134
		if tim_���[�^���[���r�o.B then
			if PH45_�����m or 1 then
				inc(���[�^���[���r�ostep)
			else
				���[�^���[���r�ostep=121
			end if
		end if

	'PH42_�����m MC47_���[�^���[��	StageDevice30
	'PH43_�����m MC48_���[�^���[��	StageDevice31
		'----------------------------------
	case 135
		'----------------------------------
		if not(PH43_�����m) and PH42_�����m then 
			mMC47_���[�^���[��=ON
			mMC48_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 136
		if not(PH42_�����m) and not(PH43_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 137
		if PH43_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 138
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 139
		if tim_���[�^���[���r�o.B then
			mMC47_���[�^���[��=OFF
			mMC48_���[�^���[��=OFF

			StageDevice31=StageDevice30
			StageDevice30=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 140
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 141
		if tim_���[�^���[���r�o.B then
			if PH44_�����m or 1 then
				inc(���[�^���[���r�ostep)
			else
				���[�^���[���r�ostep=128
			end if
		end if

	'PH41_�����m MC33_���[�^���[��	StageDevice29
	'PH42_�����m MC47_���[�^���[��	StageDevice30
		'----------------------------------
	case 142
		'----------------------------------
		if not(PH42_�����m) and PH41_�����m then 
			mMC33_���[�^���[��=ON
			mMC47_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 143
		if not(PH41_�����m) and not(PH42_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 144
		if PH42_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 145
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 146
		if tim_���[�^���[���r�o.B then
			mMC33_���[�^���[��=OFF
			mMC47_���[�^���[��=OFF

			StageDevice30=StageDevice29
			StageDevice29=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 147
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 148
		if tim_���[�^���[���r�o.B then
			if PH43_�����m or 1 then
				inc(���[�^���[���r�ostep)
			else
				���[�^���[���r�ostep=135
			end if
		end if

	'PH40_�����m MC32_���[�^���[��	StageDevice28
	'PH41_�����m MC33_���[�^���[��	StageDevice29
		'----------------------------------
	case 149
		'----------------------------------
		if not(PH41_�����m) and PH40_�����m then 
			mMC32_���[�^���[��=ON
			mMC33_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 150
		if not(PH40_�����m) and not(PH41_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 151
		if PH41_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 152
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 153
		if tim_���[�^���[���r�o.B then
			mMC32_���[�^���[��=OFF
			mMC33_���[�^���[��=OFF

			StageDevice29=StageDevice28
			StageDevice28=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 154
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 155
		if tim_���[�^���[���r�o.B then
			if PH42_�����m or 1 then
				inc(���[�^���[���r�ostep)
			else
				���[�^���[���r�ostep=142
			end if
		end if

	'PH39_�����m MC31_���[�^���[��	StageDevice27
	'PH40_�����m MC32_���[�^���[��	StageDevice28
		'----------------------------------
	case 156
		'----------------------------------
		if not(PH40_�����m) and PH39_�����m then 
			mMC31_���[�^���[��=ON
			mMC32_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 157
		if not(PH39_�����m) and not(PH40_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 158
		if PH40_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 159
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 160
		if tim_���[�^���[���r�o.B then
			mMC31_���[�^���[��=OFF
			mMC32_���[�^���[��=OFF

			StageDevice28=StageDevice27
			StageDevice27=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 161
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 162
		if tim_���[�^���[���r�o.B then
			if PH41_�����m or 1 then
				inc(���[�^���[���r�ostep)
			else
				���[�^���[���r�ostep=149
			end if
		end if

	'PH38_�����m MC30_���[�^���[��	StageDevice26
	'PH39_�����m MC31_���[�^���[��	StageDevice27
		'----------------------------------
	case 163
		'----------------------------------
		if not(PH39_�����m) and PH38_�����m then 
			mMC30_���[�^���[��=ON
			mMC31_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 164
		if not(PH38_�����m) and not(PH39_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 165
		if PH39_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 166
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 167
		if tim_���[�^���[���r�o.B then
			mMC30_���[�^���[��=OFF
			mMC31_���[�^���[��=OFF

			StageDevice27=StageDevice26
			StageDevice26=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 168
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 169
		if tim_���[�^���[���r�o.B then
			if PH40_�����m or 1 then
				inc(���[�^���[���r�ostep)
			else
				���[�^���[���r�ostep=156
			end if
		end if

	'PH37_�����m MC29_���[�^���[��	StageDevice25
	'PH38_�����m MC30_���[�^���[��	StageDevice26
		'----------------------------------
	case 170
		'----------------------------------
		if not(PH38_�����m) and PH37_�����m then 
			mMC29_���[�^���[��=ON
			mMC30_���[�^���[��=ON
			inc(���[�^���[���r�ostep)
		else
			���[�^���[���r�ostep=���[�^���[���r�ostep+7
		end if

	case 171
		if not(PH37_�����m) and not(PH38_�����m) then
			inc(���[�^���[���r�ostep)		
		end if

	case 172
		if PH38_�����m then 
			inc(���[�^���[���r�ostep)
		end if
	
	case 173
		tim_���[�^���[���r�o_val=8
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)

	case 174
		if tim_���[�^���[���r�o.B then
			mMC29_���[�^���[��=OFF
			mMC30_���[�^���[��=OFF

			StageDevice26=StageDevice25
			StageDevice25=0

			inc(���[�^���[���r�ostep)
		end if
	
	case 175
		tim_���[�^���[���r�o_val=0
		res(tim_���[�^���[���r�o)
		inc(���[�^���[���r�ostep)
	
	case 176
		if tim_���[�^���[���r�o.B then
			if PH39_�����m or 1 then
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
	if (�����R���x�AF2AutoMode and ��������AutoMode ) or �����R���x�AF2step<>0 then
	
		if ManualInite=1 then
			ManualInite=0
		end if
		
		if not(�����R���x�AF2AutoMode and ��������AutoMode ) then
			�����R���x�AF2AutoRun=OFF
		end if
		tmr(tim_procstep,tim_procstep_val)

		select case �����R���x�AF2step
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �����R���x�AF2AutoRun then
				inc(�����R���x�AF2step)
			else 
				�����R���x�AF2step=0 '�I���ҋ@
			end if
		
		case 2
			if PH48_�����m then
				�����R���x�AF2���쒆=OFF
				�����R���x�AF2�r�o�v��=ON
				�����R���x�AF2step=1
			else
				inc(�����R���x�AF2step)
			end if


		case 3
			if IH���ы@B�֎~ then
				inc(�����R���x�AF2step)
			else
				if *pinB�I�����C��.B and *pinB�ُ�.B then
					inc(�����R���x�AF2step)
				else
					�����R���x�AF2step=1
				end if
			end if
		case 4
		' [ ���̔����R���x�A��~�m�F ]
			if �����R���x�AF2�r�o�v��=OFF and  �����R���x�AG���쒆=OFF and (IH���ы@B�֎~ or (*pinB���o�R�}���h��t�\.B and *pinB���o�v��.B)) then
				�����R���x�AF2���쒆=ON
				�����R���x�AF2step=100
			else
				�����R���x�AF2step=1
			end if
			
		'--------------------------------------------------------------------------------------------------------------
		case 100
			�����R���x�AF2�����m = PH37_�����m
			�����R���x�AF2�����m = �����R���x�AF2�����m or PH38_�����m
			�����R���x�AF2�����m = �����R���x�AF2�����m or PH39_�����m
			�����R���x�AF2�����m = �����R���x�AF2�����m or PH40_�����m
			�����R���x�AF2�����m = �����R���x�AF2�����m or PH41_�����m
			�����R���x�AF2�����m = �����R���x�AF2�����m or PH42_�����m
			�����R���x�AF2�����m = �����R���x�AF2�����m or PH43_�����m
			�����R���x�AF2�����m = �����R���x�AF2�����m or PH44_�����m
			�����R���x�AF2�����m = �����R���x�AF2�����m or PH45_�����m
			�����R���x�AF2�����m = �����R���x�AF2�����m or PH46_�����m
			�����R���x�AF2�����m = �����R���x�AF2�����m or PH47_�����m
			inc(�����R���x�AF2step)

		case 101		
			if �����R���x�AF2�����m or *pinB���o���Z���T.B then
				inc(�����R���x�AF2step)
			else
				�����R���x�AF2step=1
			end if

		case 102
			���[�^���[���r�ostep=1
			inc(�����R���x�AF2step)
				
		case 103
			if ���[�^���[���r�ostep=0 then
				inc(�����R���x�AF2step)
			end if

		'------------------------------------------------------------------------
		case 104
			if PH48_�����m then
				�����R���x�AF2�r�o�v��=ON
			end if
			inc(�����R���x�AF2step)

		'------------------------------------------------------------------------
		case 105
			if not(PH37_�����m) then
				IH���у��j�b�g���ostep=1
				inc(�����R���x�AF2step)
			end if
		
		case 106
			if IH���у��j�b�g���ostep=0 then
				inc(�����R���x�AF2step)
			end if
		'------------------------------------------------------------------------
		case 107
			�����R���x�AF2���쒆=OFF
			�����R���x�AF2step=1
		
		'--------------------------------------------------------------------------------------------------------------
		case 200
			if not(PH48_�����m) then
				inc(�����R���x�AF2step)
			else
				�����R���x�AF2step=1
			end if

		case 201
			mMC29_���[�^���[��=ON
			mMC30_���[�^���[��=ON
			mMC31_���[�^���[��=ON
			mMC32_���[�^���[��=ON
			mMC33_���[�^���[��=ON
			mMC47_���[�^���[��=ON
			mMC48_���[�^���[��=ON
			mMC49_���[�^���[��=ON
			mMC50_���[�^���[��=ON
			mMC51_���[�^���[��=ON
			mMC52_���[�^���[��=ON
			mMC53_���[�^���[��=ON
			inc(�����R���x�AF2step)
		
		case 202
			if PH48_�����m then
				inc(�����R���x�AF2step)
			end if
		
		case 203
			mMC29_���[�^���[��=OFF
			mMC30_���[�^���[��=OFF
			mMC31_���[�^���[��=OFF
			mMC32_���[�^���[��=OFF
			mMC33_���[�^���[��=OFF
			mMC47_���[�^���[��=OFF
			mMC48_���[�^���[��=OFF
			mMC49_���[�^���[��=OFF
			mMC50_���[�^���[��=OFF
			mMC51_���[�^���[��=OFF
			mMC52_���[�^���[��=OFF
			mMC53_���[�^���[��=OFF
			�����R���x�AF2step=1
			

		end select

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		if ManualInite=0 then
			ManualInite=1
		end if
	
		�����R���x�AF2AutoRun=OFF
		
		�����R���x�AF2step=0 '�I��

		
		if ldp(pnlPBMC29_���[�^���[��) then
			if mMC29_���[�^���[�� then
				mMC29_���[�^���[��=OFF
			else 
				mMC29_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC30_���[�^���[��) then
			if mMC30_���[�^���[�� then
				mMC30_���[�^���[��=OFF
			else 
				mMC30_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC31_���[�^���[��) then
			if mMC31_���[�^���[�� then
				mMC31_���[�^���[��=OFF
			else 
				mMC31_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC32_���[�^���[��) then
			if mMC32_���[�^���[�� then
				mMC32_���[�^���[��=OFF
			else 
				mMC32_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC33_���[�^���[��) then
			if mMC33_���[�^���[�� then
				mMC33_���[�^���[��=OFF
			else 
				mMC33_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC47_���[�^���[��) then
			if mMC47_���[�^���[�� then
				mMC47_���[�^���[��=OFF
			else 
				mMC47_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC48_���[�^���[��) then
			if mMC48_���[�^���[�� then
				mMC48_���[�^���[��=OFF
			else 
				mMC48_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC49_���[�^���[��) then
			if mMC49_���[�^���[�� then
				mMC49_���[�^���[��=OFF
			else 
				mMC49_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC50_���[�^���[��) then
			if mMC50_���[�^���[�� then
				mMC50_���[�^���[��=OFF
			else 
				mMC50_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC51_���[�^���[��) then
			if mMC51_���[�^���[�� then
				mMC51_���[�^���[��=OFF
			else 
				mMC51_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC52_���[�^���[��) then
			if mMC52_���[�^���[�� then
				mMC52_���[�^���[��=OFF
			else 
				mMC52_���[�^���[��=ON
			end if
		end if

		if ldp(pnlPBMC53_���[�^���[��) then
			if mMC53_���[�^���[�� then
				mMC53_���[�^���[��=OFF
			else 
				mMC53_���[�^���[��=ON
			end if
		end if

	end if '�����R���x�AF2AutoMode and not(�����R���x�AF2OrgErrStep)

	'===================================================================================================================
	'�y �����R���x�AF2OrgErr���� �z
	else
	
		if ResetFlg then
			�����R���x�AF2OrgErr=OFF
		end if


	end if

	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else

		�����R���x�AF2Err=ON

		res(timerr_MC29_���[�^���[��)'tmr(MC29_���[�^���[��,timerr_MC29_���[�^���[��,60)
		res(timerr_MC30_���[�^���[��)'tmr(MC30_���[�^���[��,timerr_MC30_���[�^���[��,60)
		res(timerr_MC31_���[�^���[��)'tmr(MC31_���[�^���[��,timerr_MC31_���[�^���[��,60)
		res(timerr_MC32_���[�^���[��)'tmr(MC32_���[�^���[��,timerr_MC32_���[�^���[��,60)
		res(timerr_MC33_���[�^���[��)'tmr(MC33_���[�^���[��,timerr_MC33_���[�^���[��,60)
		res(timerr_MC47_���[�^���[��)'tmr(MC47_���[�^���[��,timerr_MC47_���[�^���[��,60)
		res(timerr_MC48_���[�^���[��)'tmr(MC48_���[�^���[��,timerr_MC48_���[�^���[��,60)
		res(timerr_MC49_���[�^���[��)'tmr(MC49_���[�^���[��,timerr_MC49_���[�^���[��,60)
		res(timerr_MC50_���[�^���[��)'tmr(MC50_���[�^���[��,timerr_MC50_���[�^���[��,60)
		res(timerr_MC51_���[�^���[��)'tmr(MC51_���[�^���[��,timerr_MC51_���[�^���[��,60)
		res(timerr_MC52_���[�^���[��)'tmr(MC52_���[�^���[��,timerr_MC52_���[�^���[��,60)
		res(timerr_MC53_���[�^���[��)'tmr(MC53_���[�^���[��,timerr_MC53_���[�^���[��,60)

		pauseMC29_���[�^���[��=ON
		pauseMC30_���[�^���[��=ON
		pauseMC31_���[�^���[��=ON
		pauseMC32_���[�^���[��=ON
		pauseMC33_���[�^���[��=ON
		pauseMC47_���[�^���[��=ON
		pauseMC48_���[�^���[��=ON
		pauseMC49_���[�^���[��=ON
		pauseMC50_���[�^���[��=ON
		pauseMC51_���[�^���[��=ON
		pauseMC52_���[�^���[��=ON
		pauseMC53_���[�^���[��=ON

		select case �����R���x�AF2ErrStep
		case 0
		case 1
			if ResetFlg then
				almMC29_���[�^���[��=OFF
				almMC30_���[�^���[��=OFF
				almMC31_���[�^���[��=OFF
				almMC32_���[�^���[��=OFF
				almMC33_���[�^���[��=OFF
				almMC47_���[�^���[��=OFF
				almMC48_���[�^���[��=OFF
				almMC49_���[�^���[��=OFF
				almMC50_���[�^���[��=OFF
				almMC51_���[�^���[��=OFF
				almMC52_���[�^���[��=OFF
				almMC53_���[�^���[��=OFF
				inc(�����R���x�AF2ErrStep)
			end if
		case 2
			pauseMC29_���[�^���[��=OFF
			pauseMC30_���[�^���[��=OFF
			pauseMC31_���[�^���[��=OFF
			pauseMC32_���[�^���[��=OFF
			pauseMC33_���[�^���[��=OFF
			pauseMC47_���[�^���[��=OFF
			pauseMC48_���[�^���[��=OFF
			pauseMC49_���[�^���[��=OFF
			pauseMC50_���[�^���[��=OFF
			pauseMC51_���[�^���[��=OFF
			pauseMC52_���[�^���[��=OFF
			pauseMC53_���[�^���[��=OFF
			

			�����R���x�AF2Err=OFF
			�����R���x�AF2ErrStep=0
		end select

	end if 'if �����R���x�AF2ErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	select case �����R���x�AF2EmgStep
	case 0
		
	case 1
		�����R���x�AF2AutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�����R���x�AF2AutoMode and ��������AutoMode ) or �����R���x�AF2step<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseMC29_���[�^���[��=ON
			pauseMC30_���[�^���[��=ON
			pauseMC31_���[�^���[��=ON
			pauseMC32_���[�^���[��=ON
			pauseMC33_���[�^���[��=ON
			pauseMC47_���[�^���[��=ON
			pauseMC48_���[�^���[��=ON
			pauseMC49_���[�^���[��=ON
			pauseMC50_���[�^���[��=ON
			pauseMC51_���[�^���[��=ON
			pauseMC52_���[�^���[��=ON
			pauseMC53_���[�^���[��=ON		

			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				tim_���o�w��_stack=tim_���o�w��.U
				tim_�����w��_stack=tim_�����w��.U
				tim_IH���у��j�b�g���o_stack=tim_IH���у��j�b�g���o.U
				tim_IH���у��j�b�g����_stack=tim_IH���у��j�b�g����.U
				tim_���[�^���[���r�o_stack=tim_���[�^���[���r�o.U
				timdly_PH37_�����m_stack=timdly_PH37_�����m.U
				timdly_PH38_�����m_stack=timdly_PH38_�����m.U
				timdly_PH39_�����m_stack=timdly_PH39_�����m.U
				timdly_PH40_�����m_stack=timdly_PH40_�����m.U
				timdly_PH41_�����m_stack=timdly_PH41_�����m.U
				timdly_PH42_�����m_stack=timdly_PH42_�����m.U
				timdly_PH43_�����m_stack=timdly_PH43_�����m.U
				timdly_PH44_�����m_stack=timdly_PH44_�����m.U
				timdly_PH45_�����m_stack=timdly_PH45_�����m.U
				timdly_PH46_�����m_stack=timdly_PH46_�����m.U
				timdly_PH47_�����m_stack=timdly_PH47_�����m.U
				timdly_PH48_�����m_stack=timdly_PH48_�����m.U
				timdly_PH50_�����m_stack=timdly_PH50_�����m.U
				tim_MC29_���[�^���[��_stack=tim_MC29_���[�^���[��.U
				tim_MC30_���[�^���[��_stack=tim_MC30_���[�^���[��.U
				tim_MC31_���[�^���[��_stack=tim_MC31_���[�^���[��.U
				tim_MC32_���[�^���[��_stack=tim_MC32_���[�^���[��.U
				tim_MC33_���[�^���[��_stack=tim_MC33_���[�^���[��.U
				tim_MC47_���[�^���[��_stack=tim_MC47_���[�^���[��.U
				tim_MC48_���[�^���[��_stack=tim_MC48_���[�^���[��.U
				tim_MC49_���[�^���[��_stack=tim_MC49_���[�^���[��.U
				tim_MC50_���[�^���[��_stack=tim_MC50_���[�^���[��.U
				tim_MC51_���[�^���[��_stack=tim_MC51_���[�^���[��.U
				tim_MC52_���[�^���[��_stack=tim_MC52_���[�^���[��.U
				tim_MC53_���[�^���[��_stack=tim_MC53_���[�^���[��.U

				timstack=ON
			end if

			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC29_���[�^���[��=OFF
			mMC30_���[�^���[��=OFF
			mMC31_���[�^���[��=OFF
			mMC32_���[�^���[��=OFF
			mMC33_���[�^���[��=OFF
			mMC47_���[�^���[��=OFF
			mMC48_���[�^���[��=OFF
			mMC49_���[�^���[��=OFF
			mMC50_���[�^���[��=OFF
			mMC51_���[�^���[��=OFF
			mMC52_���[�^���[��=OFF
			mMC53_���[�^���[��=OFF		

			'---------------------------------
		end if
		
		'---------------------------------
		inc(�����R���x�AF2EmgStep)
	case 2
		if ResetFlg then
			inc(�����R���x�AF2EmgStep)
		end if
	case 3
		if (�����R���x�AF2AutoMode and ��������AutoMode ) or �����R���x�AF2step<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseMC29_���[�^���[��=OFF
				pauseMC30_���[�^���[��=OFF
				pauseMC31_���[�^���[��=OFF
				pauseMC32_���[�^���[��=OFF
				pauseMC33_���[�^���[��=OFF
				pauseMC47_���[�^���[��=OFF
				pauseMC48_���[�^���[��=OFF
				pauseMC49_���[�^���[��=OFF
				pauseMC50_���[�^���[��=OFF
				pauseMC51_���[�^���[��=OFF
				pauseMC52_���[�^���[��=OFF
				pauseMC53_���[�^���[��=OFF

				tim_procstep.U=tim_procstep_stack
				tim_���o�w��.U=tim_���o�w��_stack
				tim_�����w��.U=tim_�����w��_stack
				tim_IH���у��j�b�g���o.U=tim_IH���у��j�b�g���o_stack
				tim_IH���у��j�b�g����.U=tim_IH���у��j�b�g����_stack
				tim_���[�^���[���r�o.U=tim_���[�^���[���r�o_stack
				timdly_PH37_�����m.U=timdly_PH37_�����m_stack
				timdly_PH38_�����m.U=timdly_PH38_�����m_stack
				timdly_PH39_�����m.U=timdly_PH39_�����m_stack
				timdly_PH40_�����m.U=timdly_PH40_�����m_stack
				timdly_PH41_�����m.U=timdly_PH41_�����m_stack
				timdly_PH42_�����m.U=timdly_PH42_�����m_stack
				timdly_PH43_�����m.U=timdly_PH43_�����m_stack
				timdly_PH44_�����m.U=timdly_PH44_�����m_stack
				timdly_PH45_�����m.U=timdly_PH45_�����m_stack
				timdly_PH46_�����m.U=timdly_PH46_�����m_stack
				timdly_PH47_�����m.U=timdly_PH47_�����m_stack
				timdly_PH48_�����m.U=timdly_PH48_�����m_stack
				timdly_PH50_�����m.U=timdly_PH50_�����m_stack
				tim_MC29_���[�^���[��.U=tim_MC29_���[�^���[��_stack
				tim_MC30_���[�^���[��.U=tim_MC30_���[�^���[��_stack
				tim_MC31_���[�^���[��.U=tim_MC31_���[�^���[��_stack
				tim_MC32_���[�^���[��.U=tim_MC32_���[�^���[��_stack
				tim_MC33_���[�^���[��.U=tim_MC33_���[�^���[��_stack
				tim_MC47_���[�^���[��.U=tim_MC47_���[�^���[��_stack
				tim_MC48_���[�^���[��.U=tim_MC48_���[�^���[��_stack
				tim_MC49_���[�^���[��.U=tim_MC49_���[�^���[��_stack
				tim_MC50_���[�^���[��.U=tim_MC50_���[�^���[��_stack
				tim_MC51_���[�^���[��.U=tim_MC51_���[�^���[��_stack
				tim_MC52_���[�^���[��.U=tim_MC52_���[�^���[��_stack
				tim_MC53_���[�^���[��.U=tim_MC53_���[�^���[��_stack

				'---------------------------------
				inc(�����R���x�AF2EmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�����R���x�AF2EmgStep)		
		end if				
	case 4
		timstack=OFF
		�����R���x�AF2EmgStep=0
		�����R���x�AF2Emg=OFF
	end select
		
end if 'if �����R���x�AF2EmgStep=0 then
