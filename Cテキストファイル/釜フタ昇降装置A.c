'���t�^���~���uA
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	���t�^���~���uA
'	
' PH41_�����m	-> PH55_�����m
' PH42_�t�^���m	-> PH56_�t�^���m
' PH43_�����m	-> PH57_�����m
' PH44_�t�^���m -> PH58_�t�^���m
' PH45_�����m	-> PH59_�����m
' PH46_�t�^���m	-> PH62__�t�^���m
' MC30_�������[�^ -> MC57_�������[�^
' SV57_���t�g	-> SV59_���t�g�㏸
' (�V�K)		-> SV76_���t�g���~
' XSW72_���t�g�㏸�[ -> XSW80_���t�g�㏸�[
' XSW71_���t�g���~�[ -> XSW81_���t�g���~�[
' �����R���x�AF�r�o�v�� -> �����R���x�AH�r�o�v��
'===================================================================================================================

'�y ���������� �z
if CR2008 then '�d��ON������������

    ���t�^���~���uAAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    ���t�^���~���uAAutoRun=OFF
    ���t�^���~���uA����=ON
    ���t�^���~���uAOrgErr=OFF
    ���t�^���~���uAErr=OFF
    ���t�^���~���uAEmg=OFF
    ���t�^���~���uAstep=0
    ���t�^���~���uAErrStep=0
    ���t�^���~���uAOrgErrStep=0
    ���t�^���~���uAEmgStep=0
	
	MC55_�������[�^step=0
	MC57_�������[�^step=0
	
	
end if
'===================================================================================================================
'�y ���_ �z
���t�^���~���uAOrg=((XSW80_���t�g�㏸�[ and not(pnlPBXSW80_���t�g�㏸�[)) or passXSW80_���t�g�㏸�[) or ((XSW81_���t�g���~�[ and not(pnlPBXSW81_���t�g���~�[)) or passXSW81_���t�g���~�[)

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	���t�^���~���uAEmg=ON
	���t�^���~���uAEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
'�G���[���o��Keep���g�p����ƁA��~���ɃG���[�����o�����~���u�������o���B
'tmr( (SVxx or Keepxx) and ....)  ->  tmr(SVxx and)
tmr(SV59_���t�g�㏸ and not(XSW80_���t�g�㏸�[) and not(pnlPBXSW80_���t�g�㏸�[), tim_notXSW80_���t�g�㏸�[,#70)
tmr(SV76_���t�g���~ and not(XSW81_���t�g���~�[) and not(pnlPBXSW81_���t�g���~�[), tim_notXSW81_���t�g���~�[,#70)
tmr(SV59_���t�g�㏸ and XSW81_���t�g���~�[ and not(pnlPBXSW81_���t�g���~�[), tim_XSW81_���t�g���~�[,#10)
tmr(SV76_���t�g���~ and XSW80_���t�g�㏸�[ and not(pnlPBXSW80_���t�g�㏸�[), tim_XSW80_���t�g�㏸�[,#10)

if SV59_���t�g�㏸ and not(SV76_���t�g���~) then
	KeepSV59_���t�g�㏸=ON
else if SV76_���t�g���~ then
	KeepSV59_���t�g�㏸=OFF
end if

if SV76_���t�g���~ and not(SV59_���t�g�㏸) then
	KeepSV76_���t�g���~=ON
else if SV59_���t�g�㏸ then
	KeepSV76_���t�g���~=OFF
end if


tms(SV59_���t�g�㏸ or KeepSV59_���t�g�㏸,passtimXSW80_���t�g�㏸�[,passtimXSW80_���t�g�㏸�[_val)
tms(SV76_���t�g���~ or KeepSV76_���t�g���~,passtimXSW81_���t�g���~�[,passtimXSW81_���t�g���~�[_val)

if ldp(tim_XSW80_���t�g�㏸�[.B) or ldp(tim_notXSW80_���t�g�㏸�[.B) then
	if ���t�^���~���uAstep>0 and tim_notXSW80_���t�g�㏸�[.B then
		errpassXSW80_���t�g�㏸�[=ON
		mSV59_���t�g�㏸=OFF
		mSV76_���t�g���~=ON	
	end if
	almXSW80_���t�g�㏸�[=ON
	pnlPBXSW80_���t�g�㏸�[=ON
	���t�^���~���uAErrStep=1

else if ldp(tim_XSW81_���t�g���~�[.B) or ldp(tim_notXSW81_���t�g���~�[.B) then
	if ���t�^���~���uAstep>0 and tim_notXSW81_���t�g���~�[.B then
		errpassXSW81_���t�g���~�[=ON
		mSV59_���t�g�㏸=ON
		mSV76_���t�g���~=OFF
	end if
	almXSW81_���t�g���~�[=ON
	pnlPBXSW81_���t�g���~�[=ON
	���t�^���~���uAErrStep=1

end if

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: ���t�^���~���uAAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: ���t�^���~���uAAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: ���t�^���~���uAEmg	���̏��~

tmr(PH55_�����m,timdly_PH55_�����m,4)
tmr(PH56_�t�^���m,timdly_PH56_�t�^���m,4)
tmr(not(PH55_�����m),timnotdly_PH55_�����m,4)
tmr(not(PH56_�t�^���m),timnotdly_PH56_�t�^���m,4)


if ���t�^���~���uAEmgStep=0 then  
	
	if ���t�^���~���uAErrStep=0  then

	if not(���t�^���~���uAOrgErr) then

	if (���t�^���~���uAAutoMode and ��������AutoMode ) or ���t�^���~���uAstep<>0 then
	
		if not(���t�^���~���uAAutoMode and ��������AutoMode ) then
			���t�^���~���uAAutoRun=OFF
		end if
	'------------------------------------------------------------------------------------------------
	'�t�^������
	tmr(tim_MC55_�������[�^,tim_MC55_�������[�^_val)
	
	select case MC55_�������[�^step
	case 0
	
	case 1
		if (PH68_�����m or PH69_�t�^���m) and not(PH55_�����m) and not(PH56_�t�^���m) then
			inc(MC55_�������[�^step)
		else
			MC55_�������[�^step=0
		end if

	case 2
		mMC55_�������[�^=ON
		mMC57_�������[�^=ON
		inc(MC55_�������[�^step)
	
	case 3
		if not(PH68_�����m) and not(PH69_�t�^���m) then
			inc(MC55_�������[�^step)
		end if

	case 4
		if PH55_�����m or PH56_�t�^���m then
			inc(MC55_�������[�^step)
		end if
	
	case 5
		tim_MC55_�������[�^_val=2
		res(tim_MC55_�������[�^)
		inc(MC55_�������[�^step)
	
	case 6
		if tim_MC55_�������[�^.B then
			inc(MC55_�������[�^step)
		end if
	
	case 7
		if PH55_�����m and  PH56_�t�^���m then 
			tim_MC55_�������[�^_val=20
		else
			tim_MC55_�������[�^_val=15
		end if
		
		res(tim_MC55_�������[�^)
		inc(MC55_�������[�^step)
		
	case 8
		if tim_MC55_�������[�^.B then
			inc(MC55_�������[�^step)
		end if
	
	case 9
		mMC55_�������[�^=OFF
		mMC57_�������[�^=OFF
		inc(MC55_�������[�^step)
		
	case 10
		�����R���x�AH�r�o�v��=OFF
		MC55_�������[�^step=0
	end select
	'------------------------------------------------------------------------------------------------
	'�t�^���r�o
	tmr(tim_MC57_�������[�^,tim_MC57_�������[�^_val)
	
	select case MC57_�������[�^step
	case 0
	case 1
		mMC57_�������[�^=ON
		ejectMC35_�������[�^=ON
		inc(MC57_�������[�^step)
	case 2
		if not(PH55_�����m) and not(PH56_�t�^���m) then
			inc(MC57_�������[�^step)
		end if	
	case 3
		if PH57_�����m or PH58_�t�^���m then
			inc(MC57_�������[�^step)
		end if	

	case 4
		if �������� then
			tim_MC57_�������[�^_val=10
		else
			tim_MC57_�������[�^_val=4
		end if
		
		res(tim_MC57_�������[�^)
		inc(MC57_�������[�^step)

	case 5
		if tim_MC57_�������[�^.B then
			���t�^���~���uA�r�o�v��=ON
			mMC57_�������[�^=OFF
			ejectMC35_�������[�^=OFF
			inc(MC57_�������[�^step)
		end if

	case 6
		mSV59_���t�g�㏸=OFF
		mSV76_���t�g���~=ON
		errpassXSW81_���t�g���~�[=OFF
		inc(MC57_�������[�^step)
	
	case 7
		tim_MC57_�������[�^_val=40
		res(tim_MC57_�������[�^)
		inc(MC57_�������[�^step)

	case 8
		if tim_MC57_�������[�^.B then
			inc(MC57_�������[�^step)	
		end if

	case 9
		if errpassXSW81_���t�g���~�[ or ((XSW81_���t�g���~�[ and not(pnlPBXSW81_���t�g���~�[)) or passXSW81_���t�g���~�[) then
			inc(MC57_�������[�^step)
		end if
	
	case 10
		���t�^���~���uA���쒆=OFF
		inc(MC57_�������[�^step)

	case 11
		MC57_�������[�^step=0
	
	end select

	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case ���t�^���~���uAstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if ���t�^���~���uAAutoRun then
				inc(���t�^���~���uAstep)
			else 
				���t�^���~���uAstep=0 '�I���ҋ@
			end if

		case 2
			if ���t�^���~���uAOrg then
				inc(���t�^���~���uAstep)
			else
				���t�^���~���uAstep=1
			end if

		case 3
			if PH57_�����m or PH58_�t�^���m then '���R���x�A��̃��[�N����
				���t�^���~���uA�r�o�v��=ON
				���t�^���~���uA���쒆=OFF
			end if
			inc(���t�^���~���uAstep)

		case 4
			if timdly_PH55_�����m or timdly_PH56_�t�^���m then '�ʏ�����F���t�g�̃��[�N����
				���t�^���~���uAstep=200
			else if timnotdly_PH55_�����m and timnotdly_PH56_�t�^���m then
				���t�^���~���uAstep=100
			else
				���t�^���~���uAstep=1
			end if
	

		'--------------------------------------------------------------------------------------------------------------
		case 100
			if not(mSV76_���t�g���~) then
				tim_procstep_val=40
				res(tim_procstep)
			end if
			mSV59_���t�g�㏸=OFF
			mSV76_���t�g���~=ON
			errpassXSW81_���t�g���~�[=OFF
			inc(���t�^���~���uAstep)

		case 101
			if tim_procstep.B then
				inc(���t�^���~���uAstep)
			end if
		
		case 102
			if errpassXSW81_���t�g���~�[ or ((XSW81_���t�g���~�[ and not(pnlPBXSW81_���t�g���~�[)) or passXSW81_���t�g���~�[) then
				inc(���t�^���~���uAstep)
			end if
		
		case 103
			if �����R���x�AH�r�o�v�� then
				inc(���t�^���~���uAstep)
			else
				���t�^���~���uAstep=1
			end if
		
		case 104
			MC55_�������[�^step=1
			inc(���t�^���~���uAstep)
		
		case 105
			if MC55_�������[�^step=0 then
				inc(���t�^���~���uAstep)
			end if
		
		case 106
			if timdly_PH55_�����m or timdly_PH56_�t�^���m then '�ʏ�����F���t�g�̃��[�N����
				���t�^���~���uAstep=200
			else
				���t�^���~���uAstep=1
			end if

		'--------------------------------------------------------------------------------------------------------------
		case 200 '���t�g�㏸ -> �w��ҋ@�ʒu�Ɋ��t�^����
			if not(mSV59_���t�g�㏸) then
				tim_procstep_val=40
				res(tim_procstep)
			end if		
		
			mSV59_���t�g�㏸=ON
			mSV76_���t�g���~=OFF
			errpassXSW80_���t�g�㏸�[=OFF
			�����R���x�AH�r�o�v��=OFF
			���t�^���~���uA���쒆=ON
			inc(���t�^���~���uAstep)
		
		case 201
			if tim_procstep.B then
				inc(���t�^���~���uAstep)
			end if
		
		case 202
			if errpassXSW80_���t�g�㏸�[ or ((XSW80_���t�g�㏸�[ and not(pnlPBXSW80_���t�g�㏸�[)) or passXSW80_���t�g�㏸�[) then
				inc(���t�^���~���uAstep)
			end if

		case 203
			'------------------------------------------------------
			' ���t�^���~���uA �㏸�ҋ@
			if ���t�^���~���uA�r�o�v��=OFF and  �����]�������쒆=OFF and LS7_�����]�@���_�ʒu then
				inc(���t�^���~���uAstep)
			else
				���t�^���~���uAstep=1
			end if
			'------------------------------------------------------

		case 204
			if not(PH57_�����m) and not(PH58_�t�^���m) then
				inc(���t�^���~���uAstep)
			end if				

		case 205
			if PH55_�����m and PH56_�t�^���m then
				��������=ON
			else if not(PH55_�����m) and PH56_�t�^���m then
				��������=OFF
			end if
			inc(���t�^���~���uAstep)
		
		case 206
			MC57_�������[�^step=1
			inc(���t�^���~���uAstep)
		
		case 207
			if MC57_�������[�^step=0 then
				inc(���t�^���~���uAstep)
			end if
		
		case 208
			if not(mSV76_���t�g���~) then
				tim_procstep_val=40
				res(tim_procstep)
			end if
			mSV59_���t�g�㏸=OFF
			mSV76_���t�g���~=ON
			errpassXSW81_���t�g���~�[=OFF
			inc(���t�^���~���uAstep)
		
		case 209
			if tim_procstep.B then
				inc(���t�^���~���uAstep)
			end if

		case 210
			if errpassXSW81_���t�g���~�[ or ((XSW81_���t�g���~�[ and not(pnlPBXSW81_���t�g���~�[)) or passXSW81_���t�g���~�[) then
				inc(���t�^���~���uAstep)
			end if

		case 211
			���t�^���~���uA���쒆=OFF
			���t�^���~���uAstep=1
		'--------------------------------------------------------------------------------------------------------------
			
		end select
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		���t�^���~���uAAutoRun=OFF
		
		���t�^���~���uAstep=0 '�I��
	
		
		if ldp(pnlPBSV59_���t�g�㏸)  then
			if mSV59_���t�g�㏸ then
				mSV59_���t�g�㏸=OFF
				mSV76_���t�g���~=ON
			else if not(MC57_�������[�^) then
				mSV59_���t�g�㏸=ON
				mSV76_���t�g���~=OFF
			end if
		end if
		
		if ldp(pnlPBMC57_�������[�^) then
			if mMC57_�������[�^ then
				mMC57_�������[�^=OFF
			else if ((XSW80_���t�g�㏸�[ and not(pnlPBXSW80_���t�g�㏸�[)) or passXSW80_���t�g�㏸�[) or ((XSW81_���t�g���~�[ and not(pnlPBXSW81_���t�g���~�[)) or passXSW81_���t�g���~�[) then
				mMC57_�������[�^=ON
			end if
		end if
		
		if ldp(pnlPBMC35_�������[�^) then
			if ejectMC35_�������[�^ then
				ejectMC35_�������[�^=OFF
			else
				ejectMC35_�������[�^=ON
			end if
		end if
		

	end if '���t�^���~���uAAutoMode and not(���t�^���~���uAOrgErrStep)

	'===================================================================================================================
	'�y ���t�^���~���uAOrgErr���� �z
	else

		res(tim_XSW80_���t�g�㏸�[)
		res(tim_XSW81_���t�g���~�[)

		if ResetFlg then
			���t�^���~���uAOrgErr=OFF
		end if		

	end if

	'===================================================================================================================
	'�y�^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
		res(tim_XSW80_���t�g�㏸�[)
		res(tim_XSW81_���t�g���~�[)
		res(tim_notXSW80_���t�g�㏸�[)
		res(tim_notXSW81_���t�g���~�[)

		���t�^���~���uAErr=ON

		select case ���t�^���~���uAErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW80_���t�g�㏸�[=OFF
				almXSW81_���t�g���~�[=OFF

				inc(���t�^���~���uAErrStep)
			end if
		case 2

			���t�^���~���uAErr=OFF
			���t�^���~���uAErrStep=0
			
			���t�^���~���uAstep=0 '�I���ҋ@

		end select

	end if 'if ���t�^���~���uAErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	select case ���t�^���~���uAEmgStep
	case 0
	
	case 1
		���t�^���~���uAAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (���t�^���~���uAAutoMode and ��������AutoMode ) or ���t�^���~���uAstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseMC35_�������[�^=ON
			pauseMC55_�������[�^=ON
			pauseMC57_�������[�^=ON

			if timstack=OFF then
				timdly_PH55_�����m_stack=timdly_PH55_�����m.U
				timdly_PH56_�t�^���m_stack=timdly_PH56_�t�^���m.U
				timnotdly_PH55_�����m_stack=timnotdly_PH55_�����m.U
				timnotdly_PH56_�t�^���m_stack=timnotdly_PH56_�t�^���m.U
				tim_procstep_stack=tim_procstep.U
				tim_MC55_�������[�^_stack=tim_MC55_�������[�^.U
				tim_MC57_�������[�^_stack=tim_MC57_�������[�^.U

				timstack=ON
			end if

			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			ejectMC35_�������[�^=OFF
			mMC55_�������[�^=OFF
			mMC57_�������[�^=OFF
			mSV59_���t�g�㏸=OFF
			mSV76_���t�g���~=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(���t�^���~���uAEmgStep)
	case 2
		if ResetFlg then
			inc(���t�^���~���uAEmgStep)
		end if
	case 3
		if (���t�^���~���uAAutoMode and ��������AutoMode ) or ���t�^���~���uAstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseMC35_�������[�^=OFF
				pauseMC55_�������[�^=OFF
				pauseMC57_�������[�^=OFF

				timdly_PH55_�����m.U=timdly_PH55_�����m_stack
				timdly_PH56_�t�^���m.U=timdly_PH56_�t�^���m_stack
				timnotdly_PH55_�����m.U=timnotdly_PH55_�����m_stack
				timnotdly_PH56_�t�^���m.U=timnotdly_PH56_�t�^���m_stack
				tim_procstep.U=tim_procstep_stack
				tim_MC55_�������[�^.U=tim_MC55_�������[�^_stack
				tim_MC57_�������[�^.U=tim_MC57_�������[�^_stack

				'---------------------------------
				inc(���t�^���~���uAEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(���t�^���~���uAEmgStep)		
		end if				
	case 4
		timstack=OFF
		���t�^���~���uAEmgStep=0
		���t�^���~���uAEmg=OFF
	end select

end if 'if ���t�^���~���uAEmgStep=0 then
