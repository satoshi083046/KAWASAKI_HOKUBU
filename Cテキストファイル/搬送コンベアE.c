'�����R���x�AE
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	�����R���x�AE


'	SV43_���t�g		XSW53_���t�g�㏸�[		PH24_�����m
'					XSW54_���t�g���~�[	
'	SV42_�X�g�b�p	XSW51_�X�g�b�p�㏸�[	
'					XSW52_�X�g�b�p���~�[	
'
'	MC45_�������[�^
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

	�����R���x�AEAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �����R���x�AEAutoRun=OFF
    �����R���x�AE����=ON
    �����R���x�AEOrgErr=OFF
    �����R���x�AEErr=OFF
    �����R���x�AEEmg=OFF
    �����R���x�AEstep=0
    �����R���x�AEErrStep=0
    �����R���x�AEOrgErrStep=0
    �����R���x�AEEmgStep=0
	
	IH���у��j�b�g����step=0

	if SSW3_�������[�h then	
		ManualInite=1
	else
		ManualInite=0	
	end if
	
	
end if

'===================================================================================================================
'�y ���_ �z
�����R���x�AEOrg=((XSW53_���t�g�㏸�[ and not(pnlPBXSW53_���t�g�㏸�[)) or passXSW53_���t�g�㏸�[) or ((XSW54_���t�g���~�[ and not(pnlPBXSW54_���t�g���~�[)) or passXSW54_���t�g���~�[)
�����R���x�AEOrg=�����R���x�AEOrg and ( ((XSW51_�X�g�b�p�㏸�[ and not(pnlPBXSW51_�X�g�b�p�㏸�[)) or passXSW51_�X�g�b�p�㏸�[) or ((XSW52_�X�g�b�p���~�[ and not(pnlPBXSW52_�X�g�b�p���~�[)) or passXSW52_�X�g�b�p���~�[) )


'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�����R���x�AEEmg=ON
	�����R���x�AEEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
tmr(SV42_�X�g�b�p and not(XSW51_�X�g�b�p�㏸�[) and not(pnlPBXSW51_�X�g�b�p�㏸�[), tim_notXSW51_�X�g�b�p�㏸�[,#30)
tmr(not(SV42_�X�g�b�p) and not(XSW52_�X�g�b�p���~�[) and not(pnlPBXSW52_�X�g�b�p���~�[),tim_notXSW52_�X�g�b�p���~�[,#30)
tmr(SV43_���t�g and not(XSW53_���t�g�㏸�[) and not(pnlPBXSW53_���t�g�㏸�[), tim_notXSW53_���t�g�㏸�[, #30) 
tmr(not(SV43_���t�g) and not(XSW54_���t�g���~�[) and not(pnlPBXSW54_���t�g���~�[),tim_notXSW54_���t�g���~�[,#30)

'tmr(not(SV42_�X�g�b�p) and XSW51_�X�g�b�p�㏸�[ and not(pnlPBXSW51_�X�g�b�p�㏸�[), tim_XSW51_�X�g�b�p�㏸�[,#10)
if LDP(SV42_�X�g�b�p) and XSW51_�X�g�b�p�㏸�[ and not(pnlPBXSW51_�X�g�b�p�㏸�[) then
	SET(tim_XSW51_�X�g�b�p�㏸�[)
end if
'tmr(SV42_�X�g�b�p and XSW52_�X�g�b�p���~�[ and not(pnlPBXSW52_�X�g�b�p���~�[),tim_XSW52_�X�g�b�p���~�[,#10)
if LDF(SV42_�X�g�b�p) and XSW52_�X�g�b�p���~�[ and not(pnlPBXSW52_�X�g�b�p���~�[) and not(pauseSV42_�X�g�b�p) then
	SET(tim_XSW52_�X�g�b�p���~�[)
end if
'tmr(not(SV43_���t�g) and XSW53_���t�g�㏸�[ and not(pnlPBXSW53_���t�g�㏸�[), tim_XSW53_���t�g�㏸�[, #10) 
if LDP(SV43_���t�g) and XSW53_���t�g�㏸�[ and not(pnlPBXSW53_���t�g�㏸�[) then
	SET(tim_XSW53_���t�g�㏸�[)
end if
'tmr(SV43_���t�g and XSW54_���t�g���~�[ and not(pnlPBXSW54_���t�g���~�[),tim_XSW54_���t�g���~�[,#10)
if LDF(SV43_���t�g) and XSW54_���t�g���~�[ and not(pnlPBXSW54_���t�g���~�[) and not(pauseSV43_���t�g) then
	SET(tim_XSW54_���t�g���~�[)
end if

'tms(SV42_�X�g�b�p,passtimXSW51_�X�g�b�p�㏸�[,passtimXSW51_�X�g�b�p�㏸�[_val)
'tms(not(SV42_�X�g�b�p),passtimXSW52_�X�g�b�p���~�[,passtimXSW52_�X�g�b�p���~�[_val)
'tms(SV43_���t�g,passtimXSW53_���t�g�㏸�[,passtimXSW53_���t�g�㏸�[_val)
'tms(not(SV43_���t�g),passtimXSW54_���t�g���~�[,passtimXSW54_���t�g���~�[_val)

if ldp(tim_XSW51_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW51_�X�g�b�p�㏸�[.B) then
	errpassXSW51_�X�g�b�p�㏸�[=ON
	almXSW51_�X�g�b�p�㏸�[=ON
	pnlPBXSW51_�X�g�b�p�㏸�[=ON
	�����R���x�AEErrStep=1

else if ldp(tim_XSW52_�X�g�b�p���~�[.B) or ldp(tim_notXSW52_�X�g�b�p���~�[.B) then
	errpassXSW52_�X�g�b�p���~�[=ON
	almXSW52_�X�g�b�p���~�[=ON
	pnlPBXSW52_�X�g�b�p���~�[=ON
	�����R���x�AEErrStep=1

else if ldp(tim_XSW53_���t�g�㏸�[.B) or ldp(tim_notXSW53_���t�g�㏸�[.B) then
	errpassXSW53_���t�g�㏸�[=ON
	almXSW53_���t�g�㏸�[=ON
	pnlPBXSW53_���t�g�㏸�[=ON
	�����R���x�AEErrStep=1

else if ldp(tim_XSW54_���t�g���~�[.B) or ldp(tim_notXSW54_���t�g���~�[.B) then
	errpassXSW54_���t�g���~�[=ON
	almXSW54_���t�g���~�[=ON
	pnlPBXSW54_���t�g���~�[=ON
	�����R���x�AEErrStep=1

end if
'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �����R���x�AEAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �����R���x�AEAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �����R���x�AEEmg	���̏��~


if �����R���x�AEEmgStep=0 then  
	
	if �����R���x�AEErrStep=0  then

	if not(�����R���x�AEOrgErr) then

	
	tmr(PH24_�����m,timdly_PH24_�����m,2)
	
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
			if *pinB������t�\.B then
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
			*poutU������NO.U=������NOB
			*poutU�ʂ�No.U=*poutU�ʂ�No.U+1
			*poutD�|�d��.D=0
			*poutD���f�[�^.D=0
			'-----------------------------------
			*poutB�����w��.B=ON
			errpass�����w��=OFF
			inc(IH���у��j�b�g����step)

		case 4
			if not(*pinB�����R�}���h��t�\.B) or errpass�����w�� then
				*poutB�����w��.B=OFF
				inc(IH���у��j�b�g����step)
			end if

		case 5
			if errpass�����w�� then
				IH���у��j�b�g����step=0
			else
				inc(IH���у��j�b�g����step)
			end if
			
		
		case 6	
			mMC45_�������[�^=ON
			tim_IH���у��j�b�g����_val=80
			res(tim_IH���у��j�b�g����)
			inc(IH���у��j�b�g����step)
		case 7
			if *pinB���쒆.B or tim_IH���у��j�b�g����.B then
				tim_IH���у��j�b�g����_val=80
				res(tim_IH���у��j�b�g����)
				inc(IH���у��j�b�g����step)
			end if
		
		case 8
			if (not(*pinB���쒆.B) and *pinB�������Z���T.B) or tim_IH���у��j�b�g����.B then
				mMC45_�������[�^=OFF
				tim_IH���у��j�b�g����_val=50
				res(tim_IH���у��j�b�g����)
				inc(IH���у��j�b�g����step)	
		   end if
		
		case 9
			if not(*pinB������t�\.B) or tim_IH���у��j�b�g����.B then
				inc(IH���у��j�b�g����step)
			end if

		case 10
'			if *pinB������t�\.B then
				inc(IH���у��j�b�g����step)
'			end if

		case 11
			IH���у��j�b�g����step=0
			
		end select



	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
	if (�����R���x�AEAutoMode and ��������AutoMode ) or �����R���x�AEstep<>0 then
	
		if ManualInite=1 then
			mSV42_�X�g�b�p=ON
			mSV29_�X�g�b�p=ON
			ManualInite=0
		end if
		
		if not(�����R���x�AEAutoMode and ��������AutoMode ) then
			�����R���x�AEAutoRun=OFF
		end if

		tmr(tim_procstep,tim_procstep_val)

		select case �����R���x�AEstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �����R���x�AEAutoRun then
				inc(�����R���x�AEstep)
			else 
				�����R���x�AEstep=0 '�I���ҋ@
			end if
		
		case 2
			if *pinB�I�����C��.B and *pinB�ُ�.B and *pinB������t�\.B then
				inc(�����R���x�AEstep)
			else
				�����R���x�AEstep=1
			end if
		
		case 3
		' [ ���̔����R���x�A��~�m�F ]
			if �����R���x�AE�r�o�v��=OFF and �����R���x�AD�r�o�v�� then
				�����R���x�AE���쒆=ON
				�����R���x�AEstep=100
			else
				�����R���x�AEstep=1
			end if
			
		case 4  '���_���o
			if �����R���x�AEOrg then				
				inc(�����R���x�AEstep)
			else
				�����R���x�AEstep=1
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		case 100
			mSV43_���t�g=OFF
			errpassXSW54_���t�g���~�[=OFF
			inc(�����R���x�AEstep)
		
		case 101
			if errpassXSW54_���t�g���~�[ or ((XSW54_���t�g���~�[ and not(pnlPBXSW54_���t�g���~�[)) or passXSW54_���t�g���~�[) then
				inc(�����R���x�AEstep)
			end if
		
		case 102
			mSV42_�X�g�b�p=OFF
			errpassXSW52_�X�g�b�p���~�[=OFF
			inc(�����R���x�AEstep)

		case 103
			if errpassXSW52_�X�g�b�p���~�[ or ((XSW52_�X�g�b�p���~�[ and not(pnlPBXSW52_�X�g�b�p���~�[)) or passXSW52_�X�g�b�p���~�[) then
				inc(�����R���x�AEstep)
			end if

		case 104
			mMC45_�������[�^=ON
			inc(�����R���x�AEstep)
		
		case 105
			if ANDA(StageDevice12,$200)=$200 or ANDA(StageDevice12,$400)=$400 then '�z��A or �z��B
				�����A�C�e��NOB=ANDA(StageDevice12,$FF) '���ɕĂ���				
			else
				�����A�C�e��NOB=99 '��
			end if

			'-----------------------------------
			'���эH���f�[�^
			*poutU�����A�C�e��NO.U=�����A�C�e��NOB '��  99
			'-----------------------------------
			'�������ɑ΂��Ẵ��x�����O
			*poutU������NO.U=������NOB
			*poutU�ʂ�No.U=�������ʂ�NOB
			*poutD�|�d��.D=0
			*poutD���f�[�^.D=0
			'-----------------------------------
			IH���у��j�b�g����step=1
			
			inc(�����R���x�AEstep)

		case 106
			if IH���у��j�b�g����step=0 then
				inc(�����R���x�AEstep)
			end if
		
		case 107
			mMC45_�������[�^=OFF
			inc(�����R���x�AEstep)

		case 108
			�����R���x�AE���쒆=OFF
			�����R���x�AD�r�o�v��=OFF
			�����R���x�AE�r�o�v��=OFF
			�����R���x�AEstep=1

	 end select
	 
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		if ManualInite=0 then
			mSV42_�X�g�b�p=OFF
			mSV29_�X�g�b�p=OFF
			ManualInite=1
		end if
	
		�����R���x�AEAutoRun=OFF
		
		�����R���x�AEstep=0 '�I��

		res(tim_XSW51_�X�g�b�p�㏸�[)
		res(tim_XSW52_�X�g�b�p���~�[)
		res(tim_XSW53_���t�g�㏸�[)
		res(tim_XSW54_���t�g���~�[)

		
		
		if ldp(pnlPBMC45_�������[�^) then
			if mMC45_�������[�^ then
				mMC45_�������[�^=OFF
			else
				mMC45_�������[�^=ON
			end if
		end if
		
		if ldp(pnlPBSV42_�X�g�b�p) then
			if mSV42_�X�g�b�p then
				mSV42_�X�g�b�p=OFF
			else
				mSV42_�X�g�b�p=ON
			end if
		end if
		
		if ldp(pnlPBSV43_���t�g) then
			if mSV43_���t�g then
				mSV43_���t�g=OFF
			else
				mSV43_���t�g=ON
			end if
		end if

	end if '�����R���x�AEAutoMode and not(�����R���x�AEOrgErrStep)

	'===================================================================================================================
	'�y �����R���x�AEOrgErr���� �z
	else
	
		res(tim_notXSW51_�X�g�b�p�㏸�[)
		res(tim_notXSW52_�X�g�b�p���~�[)
		res(tim_notXSW53_���t�g�㏸�[)
		res(tim_notXSW54_���t�g���~�[)

		res(tim_XSW51_�X�g�b�p�㏸�[)
		res(tim_XSW52_�X�g�b�p���~�[)
		res(tim_XSW53_���t�g�㏸�[)
		res(tim_XSW54_���t�g���~�[)

		if ResetFlg then
			�����R���x�AEOrgErr=OFF
		end if


	end if

	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else

		�����R���x�AEErr=ON

		pauseMC45_�������[�^=ON

		select case �����R���x�AEErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW51_�X�g�b�p�㏸�[=OFF
				almXSW52_�X�g�b�p���~�[=OFF
				almXSW53_���t�g�㏸�[=OFF
				almXSW54_���t�g���~�[=OFF

				inc(�����R���x�AEErrStep)
			end if
		case 2
			�����R���x�AEErr=OFF

			res(tim_notXSW51_�X�g�b�p�㏸�[)
			res(tim_notXSW52_�X�g�b�p���~�[)
			res(tim_notXSW53_���t�g�㏸�[)
			res(tim_notXSW54_���t�g���~�[)

			res(tim_XSW51_�X�g�b�p�㏸�[)
			res(tim_XSW52_�X�g�b�p���~�[)
			res(tim_XSW53_���t�g�㏸�[)
			res(tim_XSW54_���t�g���~�[)

			pauseMC45_�������[�^=OFF

			�����R���x�AEErrStep=0
		end select

	end if 'if �����R���x�AEErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	select case �����R���x�AEEmgStep
	case 0
	
	case 1
		�����R���x�AEAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�����R���x�AEAutoMode and ��������AutoMode ) or �����R���x�AEstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseMC45_�������[�^=ON
			
			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				tim_IH���у��j�b�g����_stack=tim_IH���у��j�b�g����.U
			
				timdly_PH24_�����m_stack=timdly_PH24_�����m.U
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC45_�������[�^=OFF
			mSV42_�X�g�b�p=OFF
			mSV43_���t�g=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�����R���x�AEEmgStep)
	case 2
		if ResetFlg then
			inc(�����R���x�AEEmgStep)
		end if
	case 3
		if (�����R���x�AEAutoMode and ��������AutoMode ) or �����R���x�AEstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseMC45_�������[�^=OFF

				tim_procstep.U=tim_procstep_stack
				tim_IH���у��j�b�g����.U=tim_IH���у��j�b�g����_stack
				
				res(timdly_PH24_�����m)
				'---------------------------------
				inc(�����R���x�AEEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�����R���x�AEEmgStep)		
		end if				
	case 4
		timstack=OFF
		�����R���x�AEEmgStep=0
		�����R���x�AEEmg=OFF
	end select
		
end if 'if �����R���x�AEEmgStep=0 then
