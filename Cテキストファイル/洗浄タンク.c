'���^���N
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'
'	���^���N���j�b�g
'	
'mSV70_���C�d���� -> mMC_HT1_�^���N�q�[�^
'pauseSV70_���C�d���� -> pauseMC_HT1_�^���N�q�[�^

'mSV76_���C�d���� -> mMC_HT2_�^���N�q�[�^
'pauseSV76_���C�d���� -> pauseMC_HT2_�^���N�q�[�^

'mSV82_���C�d���� -> mMC_HT3_�^���N�q�[�^
'pauseSV82_���C�d���� -> pauseMC_HT3_�^���N�q�[�^

'mSV88_���C�d���� -> mMC_HT4_�^���N�q�[�^
'pauseSV88_���C�d���� -> pauseMC_HT4_�^���N�q�[�^

'mSV94_���C�d���� -> �폜
'pauseSV94_���C�d���� -> �폜

'===================================================================================================================
'�y ���������� �z
if CR2008 then '�d��ON������������
    ���^���NAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    ���^���NAutoRun=OFF
    ���^���N����=ON
    ���^���NOrgErr=OFF
    ���^���NErr=OFF
    ���^���NEmg=OFF
    ���^���Nstep=0
    ���^���NErrStep=0
    ���^���NOrgErrStep=0
    ���^���NEmgStep=0
	
	set(tim_notFLT1_�^���N���) '����q�X�e���V�X�^�C�}�[
	set(tim_notFLT3_�^���N���) '����q�X�e���V�X�^�C�}�[
	set(tim_notFLT5_�^���N���) '����q�X�e���V�X�^�C�}�[
	set(tim_notFLT7_�^���N���) '����q�X�e���V�X�^�C�}�[
end if
'===================================================================================================================
'�y ���_ �z
���^���NOrg=1

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	���^���NEmg=ON
	���^���NEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o

tmr(SV69_�����d���� and not(FLT2_�^���N����) and not(pnlPBFLT2_�^���N����),tim_FLT2_�^���N����,#100)
tmr(SV69_�����d���� and FLT2_�^���N���� and not(FLT1_�^���N���) and not(pnlPBFLT1_�^���N���),tim_FLT1_�^���N���,#100)
tmr(SV75_�����d���� and not(FLT4_�^���N����) and not(pnlPBFLT4_�^���N����),tim_FLT4_�^���N����,#100)
tmr(SV75_�����d���� and FLT4_�^���N���� and not(FLT3_�^���N���) and not(pnlPBFLT3_�^���N���),tim_FLT3_�^���N���,#100)
tmr(SV81_�����d���� and not(FLT6_�^���N����) and not(pnlPBFLT6_�^���N����),tim_FLT6_�^���N����,#100)
tmr(SV81_�����d���� and FLT6_�^���N���� and not(FLT5_�^���N���) and not(pnlPBFLT5_�^���N���),tim_FLT5_�^���N���,#100)
tmr(SV87_�����d���� and not(FLT8_�^���N����) and not(pnlPBFLT8_�^���N����),tim_FLT8_�^���N����,#100)
tmr(SV87_�����d���� and FLT8_�^���N���� and not(FLT7_�^���N���) and not(pnlPBFLT7_�^���N���),tim_FLT7_�^���N���,#100)

if 0 then

if ldp(tim_FLT2_�^���N����.B) then
	almFLT2_�^���N���� =ON
	���^���NErrStep=1

else if ldp(tim_FLT1_�^���N���.B) then
	almFLT1_�^���N���=ON
	���^���NErrStep=1	

else if ldp(tim_FLT4_�^���N����.B) then
	almFLT4_�^���N����=ON
	���^���NErrStep=1

else if ldp(tim_FLT3_�^���N���.B) then
	almFLT3_�^���N���=ON
	���^���NErrStep=1

else if ldp(tim_FLT6_�^���N����.B) then
	almFLT6_�^���N����=ON
	���^���NErrStep=1

else if ldp(tim_FLT7_�^���N���.B) then
	���^���NErrStep=1


end if

end if

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: ���^���NAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: ���^���NAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: ���^���NEmg	���̏��~

'------------------------------------------------------------------------------------------
'�q�X�e���V�X�^�C�}�[
'------------------------------------------------------------------------------------------
tmr(tim_notFLT1_�^���N���,#100) '����q�X�e���V�X�^�C�}�[
tmr(tim_notFLT3_�^���N���,#100) '����q�X�e���V�X�^�C�}�[
tmr(tim_notFLT5_�^���N���,#100) '����q�X�e���V�X�^�C�}�[
tmr(tim_notFLT7_�^���N���,#100) '����q�X�e���V�X�^�C�}�[
'------------------------------------------------------------------------------------------
'���x���ߊ퐧��
'
' 83���ŋ��U����B�i����v���F�o���u�̔M�ɂ�鋤�U�j
'------------------------------------------------------------------------------------------
	'-- �^���N1
	if ANDA(getEDC1_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8 then
		RLY_H1_�^���N���������=ON
	else
		RLY_H1_�^���N���������=OFF
	end if	
	if mMC_HT1_�^���N�q�[�^ and 0 then
		if ANDA(getEDC1_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8  and not(���x���ߊ�1Alm) then
			pauseMC_HT1_�^���N�q�[�^=OFF '�ꎞ��~����
		else
			pauseMC_HT1_�^���N�q�[�^=ON '�ꎞ��~	
		end if
	else
		pauseMC_HT1_�^���N�q�[�^=OFF '�ꎞ��~����
	end if

	'-- �^���N2
	if ANDA(getEDC2_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8 then
		RLY_H2_�^���N���������=ON
	else
		RLY_H2_�^���N���������=OFF
	end if	
	if mMC_HT2_�^���N�q�[�^  and 0 then
		if  ANDA(getEDC2_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8 and not(���x���ߊ�2Alm) then
			pauseMC_HT2_�^���N�q�[�^=OFF
		else
			pauseMC_HT2_�^���N�q�[�^=ON
		end if
	else
		pauseMC_HT2_�^���N�q�[�^=OFF
	end if
	
	'-- �^���N3
	if ANDA(getEDC3_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8 then
		RLY_H3_�^���N���������=ON
	else
		RLY_H3_�^���N���������=OFF
	end if	
	if mMC_HT3_�^���N�q�[�^  and 0 then
		if  ANDA(getEDC3_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8  and not(���x���ߊ�3Alm) then
			pauseMC_HT3_�^���N�q�[�^=OFF
		else
			pauseMC_HT3_�^���N�q�[�^=ON
		end if
	else
		pauseMC_HT3_�^���N�q�[�^=OFF
	end if
	
	'-- �^���N4
	if ANDA(getEDC4_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8 then
		RLY_H4_�^���N���������=ON
	else
		RLY_H4_�^���N���������=OFF
	end if	
	if mMC_HT4_�^���N�q�[�^  and 0 then
		if ANDA(getEDC4_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8  and not(���x���ߊ�4Alm) then
			pauseMC_HT4_�^���N�q�[�^=OFF
		else
			pauseMC_HT4_�^���N�q�[�^=ON
		end if
	else
		pauseMC_HT4_�^���N�q�[�^=OFF	
	end if

'------------------------------------------------------------------------------------------
if not(PB45_�S��~SW) and not(��������AutoMode) then
		���^���NAutoRun=OFF
end if

if ldp(PB36_����SW) then
	if ���^���NAutoRun and not(��������AutoRun) and not(�e�X�g�^�]) then
		���^���NAutoRun=OFF
	else 
		���^���NAutoRun=ON
	end if
end if

PBL36_����=���^���NAutoRun
PBL42_�q�[�^=���^���NAutoRun

'------------------------------------------------------------------------------------------

if ���^���NEmgStep=0 then  
	
	if ���^���NErrStep=0 then

	if ���^���NAutoRun then

	'===================================================================================================================
	'�y �v���Z�X���� �z
	'
		if ���^���NAutoRun  then
			�蓮�����N��=OFF


			'-----------------------
			'	1�F����  , ���C
			'-----------------------			
			if timFLT2_�^���N����.B  then
				mMC_HT1_�^���N�q�[�^=ON
			else
				mMC_HT1_�^���N�q�[�^=OFF
			end if
		
			
			if not(timFLT1_�^���N���.B) and not(timFLT2_�^���N����.B) then
				mSV69_�����d����=ON	
			else if not(timFLT1_�^���N���.B) and tim_notFLT1_�^���N���.B and timFLT2_�^���N����.B  then
				mSV69_�����d����=ON	
			else if timFLT1_�^���N���.B and timFLT2_�^���N����.B then
				mSV69_�����d����=OFF
				res(tim_notFLT1_�^���N���)
			end if
			
			'-----------------------
			'	2�F����  , ���C
			'-----------------------
			if timFLT4_�^���N����.B  then
				mMC_HT2_�^���N�q�[�^=ON
			else
				mMC_HT2_�^���N�q�[�^=OFF
			end if
		
			if not(timFLT3_�^���N���.B) and not(timFLT4_�^���N����.B) then
				mSV75_�����d����=ON	
			else if not(timFLT3_�^���N���.B) and tim_notFLT3_�^���N���.B and timFLT4_�^���N����.B then
				mSV75_�����d����=ON	
			else if timFLT3_�^���N���.B and timFLT4_�^���N����.B then
				mSV75_�����d����=OFF
				res(tim_notFLT3_�^���N���)
			end if
			'-----------------------
			'	3�F����  , ���C
			'-----------------------
			if timFLT6_�^���N����.B then
				mMC_HT3_�^���N�q�[�^=ON
			else 
				mMC_HT3_�^���N�q�[�^=OFF
			end if

			if not(timFLT5_�^���N���.B) and not(timFLT6_�^���N����.B) then
				mSV81_�����d����=ON	
			else if not(timFLT5_�^���N���.B) and tim_notFLT5_�^���N���.B and timFLT6_�^���N����.B then
				mSV81_�����d����=ON	
			else if timFLT5_�^���N���.B and timFLT6_�^���N����.B then
				mSV81_�����d����=OFF
				res(tim_notFLT5_�^���N���)
			end if
			'-----------------------
			'	  4�F����  , ���C
			'-----------------------
			if timFLT8_�^���N����.B then
				mMC_HT4_�^���N�q�[�^=ON
			else
				mMC_HT4_�^���N�q�[�^=OFF
			end if
			
			if not(timFLT7_�^���N���.B) and not(timFLT8_�^���N����.B) then
				mSV87_�����d����=ON	
			else if not(timFLT7_�^���N���.B) and tim_notFLT7_�^���N���.B and timFLT8_�^���N����.B then
				mSV87_�����d����=ON	
			else if timFLT7_�^���N���.B and timFLT8_�^���N����.B then
				mSV87_�����d����=OFF
				res(tim_notFLT7_�^���N���)
			end if

		else
			mMC_HT1_�^���N�q�[�^=OFF
			mSV69_�����d����=OFF
			
			mMC_HT2_�^���N�q�[�^=OFF
			mSV75_�����d����=OFF
			
			mMC_HT3_�^���N�q�[�^=OFF
			mSV81_�����d����=OFF
			
			mMC_HT4_�^���N�q�[�^=OFF
			mSV87_�����d����=OFF
			
		end if
			

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		'�����A�����͎����A�蓮�֌W�Ȃ��}�j���A������\�Ȃ���
		'Auto���[�hOFF�ł̃}�j���A�����암���͂Ȃ�
		
		if not(�蓮�����N��) then
			�蓮�����N��=ON

			mMC_HT1_�^���N�q�[�^=OFF
			mSV69_�����d����=OFF
			
			mMC_HT2_�^���N�q�[�^=OFF
			mSV75_�����d����=OFF
			
			mMC_HT3_�^���N�q�[�^=OFF
			mSV81_�����d����=OFF
			
			mMC_HT4_�^���N�q�[�^=OFF
			mSV87_�����d����=OFF

			tmp_�����d����=OFF
			tmp1SV69_�����d����=OFF
			tmp2SV69_�����d����=OFF
			tmp1SV75_�����d����=OFF
			tmp2SV75_�����d����=OFF
			tmp1SV81_�����d����=OFF
			tmp2SV81_�����d����=OFF
			tmp1SV87_�����d����=OFF
			tmp2SV87_�����d����=OFF
			tmp_�^���N�q�[�^=OFF
			tmp1MC_HT1_�^���N�q�[�^=OFF
			tmp2MC_HT1_�^���N�q�[�^=OFF
			tmp1MC_HT2_�^���N�q�[�^=OFF
			tmp2MC_HT2_�^���N�q�[�^=OFF
			tmp1MC_HT3_�^���N�q�[�^=OFF
			tmp2MC_HT3_�^���N�q�[�^=OFF
			tmp1MC_HT4_�^���N�q�[�^=OFF
			tmp2MC_HT4_�^���N�q�[�^=OFF	
		end if

		mSV69_�����d����=tmp1SV69_�����d���� or tmp2SV69_�����d����
		mSV75_�����d����=tmp1SV75_�����d���� or tmp2SV75_�����d����
		mSV81_�����d����=tmp1SV81_�����d���� or tmp2SV81_�����d����
		mSV87_�����d����=tmp1SV87_�����d���� or tmp2SV87_�����d����

		mMC_HT1_�^���N�q�[�^=(tmp1MC_HT1_�^���N�q�[�^ or tmp2MC_HT1_�^���N�q�[�^) and FLT2_�^���N����
		mMC_HT2_�^���N�q�[�^=(tmp1MC_HT2_�^���N�q�[�^ or tmp2MC_HT2_�^���N�q�[�^) and FLT4_�^���N����
		mMC_HT3_�^���N�q�[�^=(tmp1MC_HT3_�^���N�q�[�^ or tmp2MC_HT3_�^���N�q�[�^) and FLT6_�^���N����
		mMC_HT4_�^���N�q�[�^=(tmp1MC_HT4_�^���N�q�[�^ or tmp2MC_HT4_�^���N�q�[�^) and FLT8_�^���N����

		if PB45_�S��~SW then 'B�ړ_
			'----------------
			'�R�}���hSW����
			'----------------
			if SEL2_1_�^�]�؊��i�P���j then 'B�ړ_
				tmp2SV69_�����d����=OFF
				tmp2SV75_�����d����=OFF
				tmp2SV81_�����d����=OFF
				tmp2SV87_�����d����=OFF

				tmp2MC_HT1_�^���N�q�[�^=OFF
				tmp2MC_HT2_�^���N�q�[�^=OFF
				tmp2MC_HT3_�^���N�q�[�^=OFF
				tmp2MC_HT4_�^���N�q�[�^=OFF
			'--------------------------------------------------------------
			'	if ldp(PB36_����SW) then
			'		if tmp_�����d���� then
			'			tmp_�����d����=OFF
			'		else
			'			tmp_�����d����=ON
			'		end if
			'	end if
			'	
			'	tmp1SV69_�����d����=tmp_�����d����
			'	tmp1SV75_�����d����=tmp_�����d����
			'	tmp1SV81_�����d����=tmp_�����d����
			'	tmp1SV87_�����d����=tmp_�����d����
			'--------------------------------------------------------------
			'	if ldp(PB42_�q�[�^SW) then 
			'		if tmp_�^���N�q�[�^ then
			'			tmp_�^���N�q�[�^=OFF
			'		else
			'			tmp_�^���N�q�[�^=ON
			'		end if
			'	end if
			'		
			'	if tmp_�^���N�q�[�^ and FLT2_�^���N���� then
			'		tmp1MC_HT1_�^���N�q�[�^=ON
			'	else
			'		tmp1MC_HT1_�^���N�q�[�^=OFF
			'	end if
			'	'----------------
			'	if tmp_�^���N�q�[�^ and FLT4_�^���N���� then
			'		tmp1MC_HT2_�^���N�q�[�^=ON
			'	else
			'		tmp1MC_HT2_�^���N�q�[�^=OFF
			'	end if
			'	'----------------
			'	if tmp_�^���N�q�[�^ and FLT6_�^���N���� then
			'		tmp1MC_HT3_�^���N�q�[�^=ON
			'	else
			'		tmp1MC_HT3_�^���N�q�[�^=OFF
			'	end if
			'	'----------------			
			'	if tmp_�^���N�q�[�^ and FLT8_�^���N���� then
			'		tmp1MC_HT4_�^���N�q�[�^=ON
			'	else
			'		tmp1MC_HT4_�^���N�q�[�^=OFF
			'	end if
				'----------------

			else
				tmp_�����d����=OFF
				tmp1SV69_�����d����=OFF
				tmp1SV75_�����d����=OFF
				tmp1SV81_�����d����=OFF
				tmp1SV87_�����d����=OFF
				tmp_�^���N�q�[�^=OFF
				tmp1MC_HT1_�^���N�q�[�^=OFF
				tmp1MC_HT2_�^���N�q�[�^=OFF
				tmp1MC_HT3_�^���N�q�[�^=OFF
				tmp1MC_HT4_�^���N�q�[�^=OFF
				
				'----------------			
				' �p�l������	
				'----------------			
				if ldp(pnlPBSV69_�����d����) then
					if tmp2SV69_�����d���� then
						tmp2SV69_�����d����=OFF
					else
						tmp2SV69_�����d����=ON
					end if
				end if
				'----------------						
				if ldp(pnlPBSV75_�����d����) then
					if tmp2SV75_�����d���� then
						tmp2SV75_�����d����=OFF
					else
						tmp2SV75_�����d����=ON
					end if
				end if
				'----------------
				if ldp(pnlPBSV81_�����d����) then
					if tmp2SV81_�����d���� then
						tmp2SV81_�����d����=OFF
					else
						tmp2SV81_�����d����=ON
					end if
				end if
				'----------------
				if ldp(pnlPBSV87_�����d����) then
					if tmp2SV87_�����d���� then
						tmp2SV87_�����d����=OFF
					else
						tmp2SV87_�����d����=ON
					end if
				end if
				'--------------------------------------------------------------
				if ldp(pnlPBMC_HT1_�^���N�q�[�^) then
					if tmp2MC_HT1_�^���N�q�[�^ then
						tmp2MC_HT1_�^���N�q�[�^=OFF
					else if FLT2_�^���N���� then
						tmp2MC_HT1_�^���N�q�[�^=ON
					end if
				end if
				'----------------
					if ldp(pnlPBMC_HT2_�^���N�q�[�^) then
					if tmp2MC_HT2_�^���N�q�[�^ then
						tmp2MC_HT2_�^���N�q�[�^=OFF
					else if FLT4_�^���N���� then
						tmp2MC_HT2_�^���N�q�[�^=ON
					end if
				end if
				'----------------
				if ldp(pnlPBMC_HT3_�^���N�q�[�^) then
					if tmp2MC_HT3_�^���N�q�[�^ then
						tmp2MC_HT3_�^���N�q�[�^=OFF
					else if FLT6_�^���N���� then
						tmp2MC_HT3_�^���N�q�[�^=ON
					end if
				end if
				'----------------
				if ldp(pnlPBMC_HT4_�^���N�q�[�^) then
					if tmp2MC_HT4_�^���N�q�[�^ then
						tmp2MC_HT4_�^���N�q�[�^=OFF
					else if FLT8_�^���N���� then
						tmp2MC_HT4_�^���N�q�[�^=ON
					end if
				end if
				'--------------------------------------------------------------

			end if
		else
		
			mSV69_�����d����=OFF
			mMC_HT1_�^���N�q�[�^=OFF
	
			mSV75_�����d����=OFF
			mMC_HT2_�^���N�q�[�^=OFF

			mSV81_�����d����=OFF
			mMC_HT3_�^���N�q�[�^=OFF

			mSV87_�����d����=OFF
			mMC_HT4_�^���N�q�[�^=OFF

		
			tmp_�����d����=OFF
			tmp1SV69_�����d����=OFF
			tmp2SV69_�����d����=OFF
			tmp1SV75_�����d����=OFF
			tmp2SV75_�����d����=OFF
			tmp1SV81_�����d����=OFF
			tmp2SV81_�����d����=OFF
			tmp1SV87_�����d����=OFF
			tmp2SV87_�����d����=OFF
			tmp_�^���N�q�[�^=OFF
			tmp1MC_HT1_�^���N�q�[�^=OFF
			tmp2MC_HT1_�^���N�q�[�^=OFF
			tmp1MC_HT2_�^���N�q�[�^=OFF
			tmp2MC_HT2_�^���N�q�[�^=OFF
			tmp1MC_HT3_�^���N�q�[�^=OFF
			tmp2MC_HT3_�^���N�q�[�^=OFF
			tmp1MC_HT4_�^���N�q�[�^=OFF
			tmp2MC_HT4_�^���N�q�[�^=OFF

		end if
	end if
	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
	
		���^���NErr=ON

		mMC_HT1_�^���N�q�[�^=OFF
		mSV69_�����d����=OFF
		
		mMC_HT2_�^���N�q�[�^=OFF
		mSV75_�����d����=OFF
		
		mMC_HT3_�^���N�q�[�^=OFF
		mSV81_�����d����=OFF
		
		mMC_HT4_�^���N�q�[�^=OFF
		mSV87_�����d����=OFF
		

		select case ���^���NErrStep
		case 0
		case 1
			if ResetFlg then
				almFLT2_�^���N���� =OFF
				almFLT1_�^���N���=OFF
				almFLT4_�^���N����=OFF
				almFLT3_�^���N���=OFF
				almFLT6_�^���N����=OFF

				inc(���^���NErrStep)
			end if
		case 2
			���^���NErr=OFF
			
			res(tim_FLT2_�^���N����.B)
			res(tim_FLT1_�^���N���.B)
			res(tim_FLT4_�^���N����.B)
			res(tim_FLT3_�^���N���.B)
			res(tim_FLT6_�^���N����.B)
			res(tim_FLT7_�^���N���.B)

			���^���NErrStep=0
		end select

	end if
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	select case ���^���NEmgStep
	
	case 1
		���^���NAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if ���^���NAutoMode  and ��������AutoMode then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			mMC_HT1_�^���N�q�[�^=OFF
			mSV69_�����d����=OFF
			
			mMC_HT2_�^���N�q�[�^=OFF
			mSV75_�����d����=OFF
			
			mMC_HT3_�^���N�q�[�^=OFF
			mSV81_�����d����=OFF
			
			mMC_HT4_�^���N�q�[�^=OFF
			mSV87_�����d����=OFF

			tmp_�����d����=OFF
			tmp1SV69_�����d����=OFF
			tmp2SV69_�����d����=OFF
			tmp1SV75_�����d����=OFF
			tmp2SV75_�����d����=OFF
			tmp1SV81_�����d����=OFF
			tmp2SV81_�����d����=OFF
			tmp1SV87_�����d����=OFF
			tmp2SV87_�����d����=OFF
			tmp_�^���N�q�[�^=OFF
			tmp1MC_HT1_�^���N�q�[�^=OFF
			tmp2MC_HT1_�^���N�q�[�^=OFF
			tmp1MC_HT2_�^���N�q�[�^=OFF
			tmp2MC_HT2_�^���N�q�[�^=OFF
			tmp1MC_HT3_�^���N�q�[�^=OFF
			tmp2MC_HT3_�^���N�q�[�^=OFF
			tmp1MC_HT4_�^���N�q�[�^=OFF
			tmp2MC_HT4_�^���N�q�[�^=OFF	
			
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC_HT1_�^���N�q�[�^=OFF
			mSV69_�����d����=OFF
			
			mMC_HT2_�^���N�q�[�^=OFF
			mSV75_�����d����=OFF
			
			mMC_HT3_�^���N�q�[�^=OFF
			mSV81_�����d����=OFF
			
			mMC_HT4_�^���N�q�[�^=OFF
			mSV87_�����d����=OFF

			tmp_�����d����=OFF
			tmp1SV69_�����d����=OFF
			tmp2SV69_�����d����=OFF
			tmp1SV75_�����d����=OFF
			tmp2SV75_�����d����=OFF
			tmp1SV81_�����d����=OFF
			tmp2SV81_�����d����=OFF
			tmp1SV87_�����d����=OFF
			tmp2SV87_�����d����=OFF
			tmp_�^���N�q�[�^=OFF
			tmp1MC_HT1_�^���N�q�[�^=OFF
			tmp2MC_HT1_�^���N�q�[�^=OFF
			tmp1MC_HT2_�^���N�q�[�^=OFF
			tmp2MC_HT2_�^���N�q�[�^=OFF
			tmp1MC_HT3_�^���N�q�[�^=OFF
			tmp2MC_HT3_�^���N�q�[�^=OFF
			tmp1MC_HT4_�^���N�q�[�^=OFF
			tmp2MC_HT4_�^���N�q�[�^=OFF	
			'---------------------------------
		end if
		
		'---------------------------------
		inc(���^���NEmgStep)
	case 2
		if ResetFlg then
			inc(���^���NEmgStep)
		end if
	case 3
		if ���^���NAutoMode  and ��������AutoMode then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				
				
				
				'---------------------------------
				inc(���^���NEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(���^���NEmgStep)		
		end if				
	case 4
		���^���NEmgStep=0
		���^���NEmg=OFF
	end select
		
end if 'if ���^���NEmgStep=0 then
