'���t�^���~���uB
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	���t�^���~���uB
'	
' PH9_�����m	->PH65_�����m
' PH10_�t�^���m	->PH66_�t�^���m
' MC32_�������[�^ ->MC38_�������[�^
' (SV20_���t�g)	-> (SV20_���t�g)
' (XSW18_���t�g�㏸�[)	->(XSW18_���t�g�㏸�[)
' (XSW17_���t�g���~�[)	->(XSW17_���t�g���~�[)
' 
' PH39�����m	->PH60_�����m
' PH40_�t�^���m	->PH61_�t�^���m
' (MC11_�������[�^) ->(MC11_�������[�^)
' 
' PH50_�����m	->PH1_�����m
' PH51_�t�^���m	->PH2_�t�^���m
' 
' 
'===================================================================================================================
'�y ���������� �z
if CR2008 then '�d��ON������������
    ���t�^���~���uBAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    ���t�^���~���uBAutoRun=OFF
    ���t�^���~���uB����=ON
    ���t�^���~���uBOrgErr=OFF
    ���t�^���~���uBErr=OFF
    ���t�^���~���uBEmg=OFF
    ���t�^���~���uBstep=0
    ���t�^���~���uBErrStep=0
    ���t�^���~���uBOrgErrStep=0
    ���t�^���~���uBEmgStep=0
	
	MC38_�������[�^step=0
	MC11_�������[�^step=0
	MC11_�������[�^�r�ostep=0
	
	
end if
'===================================================================================================================
'�y ���_ �z
���t�^���~���uBOrg=((XSW17_���t�g���~�[ and not(pnlPBXSW17_���t�g���~�[)) or passXSW17_���t�g���~�[) or ((XSW18_���t�g�㏸�[ and not(pnlPBXSW18_���t�g�㏸�[))  or passXSW18_���t�g�㏸�[)

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	���t�^���~���uBEmg=ON
	���t�^���~���uBEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
'�G���[���o��Keep���g�p����ƁA��~���ɃG���[�����o�����~���u�������o���B
'tmr( (SVxx or Keepxx) and ....)  ->  tmr(SVxx and)
tmr(SV20_���t�g�㏸ and not(XSW18_���t�g�㏸�[) and not(pnlPBXSW18_���t�g�㏸�[), tim_notXSW18_���t�g�㏸�[,#60)
tmr(SV32_���t�g���~ and not(XSW17_���t�g���~�[) and not(pnlPBXSW17_���t�g���~�[), tim_notXSW17_���t�g���~�[,#60)
tmr(SV32_���t�g���~ and XSW18_���t�g�㏸�[ and not(pnlPBXSW18_���t�g�㏸�[), tim_XSW18_���t�g�㏸�[,#10)
tmr(SV20_���t�g�㏸ and XSW17_���t�g���~�[ and not(pnlPBXSW17_���t�g���~�[), tim_XSW17_���t�g���~�[,#10)

if SV20_���t�g�㏸ and not(SV32_���t�g���~) then
	KeepSV20_���t�g�㏸=ON
else if SV32_���t�g���~ then
	KeepSV20_���t�g�㏸=OFF
end if

if SV32_���t�g���~ and not(SV20_���t�g�㏸) then
	KeepSV32_���t�g���~=ON
else if SV20_���t�g�㏸ then
	KeepSV32_���t�g���~=OFF
end if

tms(SV20_���t�g�㏸ or KeepSV20_���t�g�㏸,passtimXSW18_���t�g�㏸�[,passtimXSW18_���t�g�㏸�[_val)
tms(SV32_���t�g���~ or KeepSV32_���t�g���~,passtimXSW17_���t�g���~�[,passtimXSW17_���t�g���~�[_val)

if ldp(tim_XSW18_���t�g�㏸�[.B) or ldp(tim_notXSW18_���t�g�㏸�[.B) then
	if ���t�^���~���uBstep>0 and tim_notXSW18_���t�g�㏸�[ then
		errpassXSW18_���t�g�㏸�[=ON
		mSV20_���t�g�㏸=OFF
		mSV32_���t�g���~=ON
	end if
	almXSW18_���t�g�㏸�[=ON
	pnlPBXSW18_���t�g�㏸�[=ON
	���t�^���~���uBErrStep=1

else if ldp(tim_XSW17_���t�g���~�[.B) or ldp(tim_notXSW17_���t�g���~�[.B) then
	if ���t�^���~���uBstep>0 and tim_notXSW17_���t�g���~�[.B then
		errpassXSW17_���t�g���~�[=ON
		mSV20_���t�g�㏸=ON
		mSV32_���t�g���~=OFF
	end if
	almXSW17_���t�g���~�[=ON
	pnlPBXSW17_���t�g���~�[=ON
	���t�^���~���uBErrStep=1

end if
'===================================================================================================================
'���m�^�C�}�[

TMR(PH1_�����m,timdly_PH1_�����m,5)
TMR(PH2_�t�^���m,timdly_PH2_�t�^���m,5)

tmr(PH60_�����m,timdly_PH60_�����m,4)
tmr(PH61_�t�^���m,timdly_PH61_�t�^���m,4)
tmr(not(PH60_�����m),timnotdly_PH60_�����m,4)
tmr(not(PH61_�t�^���m),timnotdly_PH61_�t�^���m,4)

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: ���t�^���~���uBAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: ���t�^���~���uBAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: ���t�^���~���uBEmg	���̏��~


if ���t�^���~���uBEmgStep=0 then  
	
	if ���t�^���~���uBErrStep=0  then

	if not(���t�^���~���uBOrgErr) then

		
	'------------------------------------------------------------------------------------------------
	'MC38_�������[�^
	tmr(tim_MC38_�������[�^,tim_MC38_�������[�^_val)
	
	select case MC38_�������[�^step
	
	case 0
	
	case 1
		mMC38_�������[�^=ON
		inc(MC38_�������[�^step)

	case 2
		if not(PH65_�����m) and not(PH66_�t�^���m) then
				inc(MC38_�������[�^step)
		end if

	case 3
		if PH60_�����m or PH61_�t�^���m then
			tim_MC38_�������[�^_val=1 '���[�^��~�^�C�~���O
			res(tim_MC38_�������[�^)
			inc(MC38_�������[�^step)
		end if
	
	case 4
		if tim_MC38_�������[�^.B then
			inc(MC38_�������[�^step)
		end if
		
	case 5
		mMC38_�������[�^=OFF
		inc(MC38_�������[�^step)
	
	case 6
		MC38_�������[�^step=0

	end select
	'------------------------------------------------------------------------------------------------
	'MC11_�������[�^
	tmr(tim_MC11_�������[�^,tim_MC11_�������[�^_val)
	
	select case MC11_�������[�^step	
	case 0
	case 1
		mMC11_�������[�^=ON
		inc(MC11_�������[�^step)

	case 2
		if not(PH65_�����m) and not(PH66_�t�^���m) then
				inc(MC11_�������[�^step)
		end if
	case 3
		if PH60_�����m or PH61_�t�^���m then
			if �������� or PH60_�����m then
				tim_MC11_�������[�^_val=17 '15 '���[�^��~�^�C�~���O
			else if not(��������) or PH61_�t�^���m then
				tim_MC11_�������[�^_val=6 '���[�^��~�^�C�~���O
			end if			
			
			res(tim_MC11_�������[�^)
			inc(MC11_�������[�^step)
		end if
	
	case 4
		��������=OFF
		if tim_MC11_�������[�^.B then
			inc(MC11_�������[�^step)
		end if
		
	case 5
		mMC11_�������[�^=OFF
		inc(MC11_�������[�^step)
	
	case 6
		MC11_�������[�^step=0

	end select
	'------------------------------------------------------------------------------------------------
	'MC11_�������[�^�r�o
	tmr(tim_MC11_�������[�^�r�o,tim_MC11_�������[�^�r�o_val)
	
	select case MC11_�������[�^�r�ostep	
	case 0
	case 1
		PH60_���N�����m=PH60_�����m '----���t�^���~���uB
		PH61_�t�^�N�����m=PH61_�t�^���m
		'PH1_�����m '----������
		'PH2_�t�^���m
		inc(MC11_�������[�^�r�ostep)
	
	case 2
		if not(mSV32_���t�g���~) then
			tim_MC11_�������[�^�r�o_val=40
			res(tim_MC11_�������[�^�r�o)
		end if
		mSV20_���t�g�㏸=OFF
		mSV32_���t�g���~=ON
		errpassXSW17_���t�g���~�[=OFF
		inc(MC11_�������[�^�r�ostep)
	
	case 3
		if tim_MC11_�������[�^�r�o.B then
			inc(MC11_�������[�^�r�ostep)
		end if		
	
	case 4
		if errpassXSW17_���t�g���~�[ or ((XSW17_���t�g���~�[ and not(pnlPBXSW17_���t�g���~�[)) or passXSW17_���t�g���~�[) then
			inc(MC11_�������[�^�r�ostep)
		end if
	
	case 5
		tim_MC11_�������[�^�r�o_val=0
		res(tim_MC11_�������[�^�r�o)
		inc(MC11_�������[�^�r�ostep)
	
	case 6
		if tim_MC11_�������[�^�r�o.B then
			inc(MC11_�������[�^�r�ostep)
		end if
	
	case 7
		mMC11_�������[�^=ON
		ejectMC6_�������[�^=ON
		inc(MC11_�������[�^�r�ostep)

	case 8
		if not(PH60_�����m) and not(PH61_�t�^���m) then
			inc(MC11_�������[�^�r�ostep)
		end if
	
	case 9
		tim_MC11_�������[�^�r�o_val=37
		res(tim_MC11_�������[�^�r�o)
		inc(MC11_�������[�^�r�ostep)
	
	case 10
		if tim_MC11_�������[�^�r�o.B then
			RES(timdly_PH1_�����m)
			RES(timdly_PH2_�t�^���m)
			inc(MC11_�������[�^�r�ostep)
		end if

	case 11
		if (PH1_�����m and timdly_PH1_�����m) or (PH2_�t�^���m and timdly_PH2_�t�^���m) then
			inc(MC11_�������[�^�r�ostep)
		end if
	
	case 12
		tim_MC11_�������[�^�r�o_val=3
		res(tim_MC11_�������[�^�r�o)
		inc(MC11_�������[�^�r�ostep)

	case 13
		if tim_MC11_�������[�^�r�o.B then
			inc(MC11_�������[�^�r�ostep)		
		end if
	
	case 14
		mMC11_�������[�^=OFF
		ejectMC6_�������[�^=OFF
		inc(MC11_�������[�^�r�ostep)
	
	case 15
		MC11_�������[�^�r�ostep=0

	end select

	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
	if (���t�^���~���uBAutoMode and ��������AutoMode ) or ���t�^���~���uBstep<>0 then
	
		if not(���t�^���~���uBAutoMode and ��������AutoMode ) then
			���t�^���~���uBAutoRun=OFF
		end if


		tmr(tim_procstep,tim_procstep_val)

		select case ���t�^���~���uBstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if ���t�^���~���uBAutoRun then
				inc(���t�^���~���uBstep)
			else 
				���t�^���~���uBstep=0 '�I���ҋ@
			end if
		
		case 2
			if ���t�^���~���uBOrg then
				inc(���t�^���~���uBstep)
			else
				���t�^���~���uBstep=1
			end if

		case 3
			if timdly_PH60_�����m.B or timdly_PH61_�t�^���m.B then
				���t�^���~���uBstep=100 '���t�g�Ɋ��t�^����
			else if timnotdly_PH60_�����m.B and timnotdly_PH61_�t�^���m.B then
				���t�^���~���uBstep=200 '���t�g�Ɋ��t�^�Ȃ�
			end if
		'--------------------------------------------------------------------------------------------------------------
		�f[���t�g���~]
		case 100
			���t�^���~���uB���쒆=OFF
			inc(���t�^���~���uBstep)
		
		case 101
			if not(mSV32_���t�g���~) then
				tim_procstep_val=40
				res(tim_procstep)
			end if
						
			mSV20_���t�g�㏸=OFF '���t�g���~
			mSV32_���t�g���~=ON '���t�g���~
			errpassXSW17_���t�g���~�[=OFF
			inc(���t�^���~���uBstep)
		
		case 102
			if tim_procstep.B then
				inc(���t�^���~���uBstep)
			end if		
		
		case 103
			if errpassXSW17_���t�g���~�[ or ((XSW17_���t�g���~�[ and not(pnlPBXSW17_���t�g���~�[)) or passXSW17_���t�g���~�[) then
				inc(���t�^���~���uBstep)
			end if		
	
		case 104
			���t�^���~���uBstep=110
		
		'--------------------------------------------------------------------------------------------------------------
		'�y���t�g���~�[�z
		case 110
			if ���t�^���~���uB�r�o�v��=OFF and �����R���x�AA���쒆=OFF  then '�����R���x�AA�����ړ��m�F
				inc(���t�^���~���uBstep)
			else
				���t�^���~���uBstep=1
			end if
			
		case 111
			if not(PH1_�����m) and not(PH2_�t�^���m) then
				MC11_�������[�^�r�ostep=1 'MC6���܂�
				inc(���t�^���~���uBstep)
			else
				���t�^���~���uBstep=1			
			end if
			
		case 112
			if MC11_�������[�^�r�ostep=0 then
	 			���t�^���~���uB�r�o�v��=ON  '�r�o�v��
				inc(���t�^���~���uBstep)
			end if			

		case 113
			if  not(PH60_�����m) and not(PH61_�t�^���m) then '���t�g��̊��t�^�Ȃ��m�F
				StageDevice0=StageDevice52
				StageDevice52=0
				���t�^���~���uBstep=200
			end if

		'--------------------------------------------------------------------------------------------------------------
		'[���t�g�㏸]
		case 200 '���t�g��O�ʒu�̃��[�N����
			if not(mSV20_���t�g�㏸) then
				tim_procstep_val=40
				res(tim_procstep)
			end if
		
			mSV20_���t�g�㏸=ON '�㏸
			mSV32_���t�g���~=OFF '�㏸
			errpassXSW18_���t�g�㏸�[=OFF
			inc(���t�^���~���uBstep)

		case 201
			if tim_procstep.B then
				inc(���t�^���~���uBstep)
			end if
		
		case 202
			if errpassXSW18_���t�g�㏸�[ or ((XSW18_���t�g�㏸�[ and not(pnlPBXSW18_���t�g�㏸�[)) or passXSW18_���t�g�㏸�[) then
				inc(���t�^���~���uBstep)
			end if
			
		case 203
			if �����]�o�����쒆=OFF and �����]�o���r�o�v�� then	
				���t�^���~���uBstep=210
			else
				���t�^���~���uBstep=1
			end if
			
		'--------------------------------------------------------------------------------------------------------------
		'�y���t�g�㏸�[�z
		case 210
			if PH65_�����m or PH66_�t�^���m then
				if PH65_�����m and PH66_�t�^���m then
					��������=ON
				else
					��������=OFF
				end if
								
				inc(���t�^���~���uBstep)
			else
				���t�^���~���uBstep=1
			end if
		
		case 211
			if errpassXSW18_���t�g�㏸�[ or ((XSW18_���t�g�㏸�[ and not(pnlPBXSW18_���t�g�㏸�[)) or passXSW18_���t�g�㏸�[) then
				MC38_�������[�^step=1
				MC11_�������[�^step=1
				inc(���t�^���~���uBstep)
			end if
		
		case 212
			if MC38_�������[�^step=0 and MC11_�������[�^step=0 then
				StageDevice52=StageDevice51
				StageDevice51=0
				inc(���t�^���~���uBstep)
			end if

		case 213
			�����]�o���r�o�v��=OFF
			���t�^���~���uB���쒆=OFF
			���t�^���~���uBstep=1

		end select
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 

		���t�^���~���uBAutoRun=OFF	
		���t�^���~���uBstep=0 '�I��
		
		if ldp(pnlPBSV20_���t�g�㏸) then
			if mSV20_���t�g�㏸ then
				mSV20_���t�g�㏸=OFF
				mSV32_���t�g���~=ON
				
			else if not(mMC11_�������[�^) then
				mSV20_���t�g�㏸=ON
				mSV32_���t�g���~=OFF
			end if
		end if
				
		if ldp(pnlPBMC11_�������[�^) then
			if mMC11_�������[�^ then
				mMC11_�������[�^=OFF
			else if ((XSW17_���t�g���~�[ and not(pnlPBXSW17_���t�g���~�[)) or passXSW17_���t�g���~�[) or ((XSW18_���t�g�㏸�[ and not(pnlPBXSW18_���t�g�㏸�[))  or passXSW18_���t�g�㏸�[) then
				mMC11_�������[�^=ON
			end if
		end if
		
	end if '���t�^���~���uBAutoMode and not(���t�^���~���uBOrgErrStep)

	'===================================================================================================================
	'�y ���t�^���~���uBOrgErr���� �z
	else
		res(tim_XSW18_���t�g�㏸�[)
		res(tim_XSW17_���t�g���~�[)

		if ResetFlg then
			���t�^���~���uBOrgErr=OFF
		end if		

	end if

	'===================================================================================================================
	'�y�^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
		res(tim_XSW18_���t�g�㏸�[)
		res(tim_XSW17_���t�g���~�[)
		res(tim_notXSW18_���t�g�㏸�[)
		res(tim_notXSW17_���t�g���~�[)

		���t�^���~���uBErr=ON

		���t�^���~���uBAutoRun=OFF	
		���t�^���~���uBstep=0 '�I��

		select case ���t�^���~���uBErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW18_���t�g�㏸�[=OFF
				almXSW17_���t�g���~�[=OFF
				
				inc(���t�^���~���uBErrStep)
			end if
		case 2
			���t�^���~���uBErr=OFF
			���t�^���~���uBErrStep=0
		end select

	end if 'if ���t�^���~���uBErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	select case ���t�^���~���uBEmgStep
	case 0
		
	case 1
		���t�^���~���uBAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (���t�^���~���uBAutoMode and ��������AutoMode ) or ���t�^���~���uBstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseMC38_�������[�^=ON
			pauseMC11_�������[�^=ON
			pauseMC6_�������[�^=ON
		
			if timstack=OFF then
				timdly_PH1_�����m_stack=timdly_PH1_�����m.U
				timdly_PH2_�t�^���m_stack=timdly_PH2_�t�^���m.U
				timdly_PH60_�����m_stack=timdly_PH60_�����m.U
				timdly_PH61_�t�^���m_stack=timdly_PH61_�t�^���m.U
				timnotdly_PH60_�����m_stack=timnotdly_PH60_�����m.U
				timnotdly_PH61_�t�^���m_stack=timnotdly_PH61_�t�^���m.U
				tim_procstep_stack=tim_procstep.U
				tim_MC11_�������[�^_stack=tim_MC11_�������[�^.U
				tim_MC11_�������[�^�r�o_stack=tim_MC11_�������[�^�r�o.U
				tim_MC38_�������[�^_stack=tim_MC38_�������[�^.U
				tim_MC38_�������[�^�ҋ@_stack=tim_MC38_�������[�^�ҋ@.U
				
				timstack=ON
			end if

			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mSV20_���t�g�㏸=OFF
			mSV32_���t�g���~=OFF
			mMC11_�������[�^=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(���t�^���~���uBEmgStep)
	case 2
		if ResetFlg then
			inc(���t�^���~���uBEmgStep)
		end if
	case 3
		if (���t�^���~���uBAutoMode and ��������AutoMode ) or ���t�^���~���uBstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseMC38_�������[�^=OFF
				pauseMC11_�������[�^=OFF
				pauseMC6_�������[�^=OFF
				
				tim_procstep.U=tim_procstep_stack
				tim_MC11_�������[�^.U=tim_MC11_�������[�^_stack
				tim_MC11_�������[�^�r�o.U=tim_MC11_�������[�^�r�o_stack
				tim_MC38_�������[�^.U=tim_MC38_�������[�^_stack
				tim_MC38_�������[�^�ҋ@.U=tim_MC38_�������[�^�ҋ@_stack

				res(timdly_PH1_�����m)
				res(timdly_PH2_�t�^���m)
				res(timdly_PH60_�����m)
				res(timdly_PH61_�t�^���m)
				res(timnotdly_PH60_�����m)
				res(timnotdly_PH61_�t�^���m)

				'---------------------------------
				inc(���t�^���~���uBEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(���t�^���~���uBEmgStep)		
		end if				
	case 4
		timstack=OFF
		���t�^���~���uBEmgStep=0
		���t�^���~���uBEmg=OFF
	end select
		
end if 'if ���t�^���~���uBEmgStep=0 then
