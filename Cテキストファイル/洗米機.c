'���ċ@
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'
'	���ă��j�b�g
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
if CR2008 then
    ����AutoMode=OFF
    ����AutoRun=OFF
    ���ċ���=ON
    ����OrgErr=OFF
    ����Err=OFF
    ����Emg=OFF
    ����step=0
    ����ErrStep=0
    ����OrgErrStep=0
    ����EmgStep=0

end if
'===================================================================================================================
'�y ���_ �z
����Org=1


'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~���C��) then
	����Emg=ON
	����EmgStep=1
end if


'===================================================================================================================
' PL�C���W�P�[�^


'===================================================================================================================
' �Z���T�[���o�f�B���C�\

	tmr(PDL2_�p�h���Z���T�[����A,tim_PDL2_�p�h���Z���T�[����A,20)
	tmr(PDL4_�p�h���Z���T�[����B,tim_PDL4_�p�h���Z���T�[����B,20)


	tmr(mMC4_���ă|���v and not(RS1_���^���N����Z���T�[), nottimdly_RS1_���^���N����Z���T�[, #50)
	if nottimdly_RS1_���^���N����Z���T�[.B  then
		pauseMC4_���ă|���v=ON
	else
		pauseMC4_���ă|���v=OFF	
	end if

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: ����AutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: ����AutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: ����Emg	���̏��~


if ����EmgStep=0 then  
	
	if ����ErrStep=0  then

	if not(����OrgErr) then

	if ����AutoMode or ����step<>0 then

		'if not(����AutoMode) then
			'����AutoRun=OFF
		'end if
		

	'===================================================================================================================
	'�y �v���Z�X���� �z
	'
		tmr(tim���ċ@,tim���ċ@_val)

		
		select case ����step
		case 0

		case 1
			if ����AutoRun then
				inc(����step)			
			else
				mSV1_�����d����=OFF
				mSV58_���ăo���uA=OFF
				mMC5_���ĉH��=OFF
				mMC4_���ă|���v=OFF
				����step=0
			end if
				
		case 2
			inc(����step)			

		case 3
			if not(�v�ʓ��쒆) then	'�I������
				if �v��AutoMode or ((timPDL1_�p�h���Z���T�[���A or DM_A�^���N���Č��ݒl>=DM_A�^���N�ݒ�l) or (timPDL3_�p�h���Z���T�[���B or DM_B�^���N���Č��ݒl>=DM_B�^���N�ݒ�l)) then
					DM_���ĉ^�]���[�h=2 '�c�ď���
					����step=40
				else
					tim���ċ@_val=100
					res(tim���ċ@)
					����step=50
				end if
			else
				inc(����step)
			end if
			
		case 4
			if �����ă��[�h then
				DM_���ĉ^�]���[�h=1 '�����ď���
				����step=20
			else 
				DM_���ĉ^�]���[�h=0 '���ď���
				����step=10

			end if
		
		case 10 '���ă��[�h
			mSV1_�����d����=ON
			mSV58_���ăo���uA=ON
			mMC5_���ĉH��=ON
			mMC4_���ă|���v=ON
			����step=1
		
		case 20 '�����ă��[�h
			mSV1_�����d����=ON
			mSV58_���ăo���uA=ON
			mMC5_���ĉH��=OFF
			mMC4_���ă|���v=ON
			����step=1

		'----------------------------------------------------------
		' �c�ď���
		case 40
			if not(����AutoRun) then
				����step=1
			else if tim���ċ@.B then
				mSV1_�����d����=ON
				mSV58_���ăo���uA=OFF
				mMC5_���ĉH��=OFF
				mMC4_���ă|���v=ON

				tim���ċ@_val=100  '���ă|���v  ���đ҂�����
				res(tim���ċ@)
				inc(����step)
			end if					

		case 41
			if not(����AutoRun) then
				����step=1
			else if tim���ċ@.B then
				mSV1_�����d����=ON
				mSV58_���ăo���uA=OFF
				mMC5_���ĉH��=OFF
				mMC4_���ă|���v=OFF
				
				res(TIM_���ăo���uAON)
				res(TIM_���ăo���uAOFF)
				res(TIM_���ăo���uBON)
				res(TIM_���ăo���uBOFF)
				res(TIM_���ĉH��ON)
				res(TIM_���ĉH��OFF)

				tim���ċ@_val=10 '���ă|���v  ���S��~�҂�����
				res(tim���ċ@)
					
					'7���Ԏc�ď���
				
				
				if �����ă��[�h then
					tim_�C���`���O_val=�C���`���O����_������ '1200 '2��=2x60=120.0
					res(tim_�C���`���O)
				else
					tim_�C���`���O_val=�C���`���O����_���� '4200 '7��=7x60=420.0
					res(tim_�C���`���O)
				end if
				
				
				inc(����step)
			end if					
		case 42
			if not(����AutoRun) then
				����step=1
			else if tim���ċ@.B then
				mSV1_�����d����=ON
				mMC4_���ă|���v=ON

				
				if �����ă��[�h then
					TIM_���ăo���uAON_val=���ăo���uAON����_������ '200
					TIM_���ăo���uAOFF_val=���ăo���uAOFF����_������ '30
					TIM_���ăo���uBON_val=���ăo���uBON����_������ '0
					TIM_���ăo���uBOFF_val=���ăo���uBOFF����_������ '0
					TIM_���ĉH��ON_val=���ĉH��ON����_������ '0
					TIM_���ĉH��OFF_val=���ĉH��OFF����_������ '0
				else
					TIM_���ăo���uAON_val=���ăo���uAON����_���� '600
					TIM_���ăo���uAOFF_val=���ăo���uAOFF����_���� '30
					TIM_���ăo���uBON_val=���ăo���uBON����_���� '600
					TIM_���ăo���uBOFF_val=���ăo���uBOFF����_���� '30
					TIM_���ĉH��ON_val=���ĉH��ON����_���� '600
					TIM_���ĉH��OFF_val=���ĉH��OFF����_���� '1000
				end if

				tmr(TIM_���ăo���uAON,TIM_���ăo���uAON_val)
				tmr(TIM_���ăo���uAOFF,TIM_���ăo���uAOFF_val)
				tmr(TIM_���ăo���uBON,TIM_���ăo���uBON_val)
				tmr(TIM_���ăo���uBOFF,TIM_���ăo���uBOFF_val)
				tmr(TIM_���ĉH��ON,TIM_���ĉH��ON_val)
				tmr(TIM_���ĉH��OFF,TIM_���ĉH��OFF_val)
			
				
				if ldp(TIM_���ăo���uAOFF.B) then
					res(TIM_���ăo���uAON.B)
				else if ldp(TIM_���ăo���uAON.B) then
					res(TIM_���ăo���uAOFF.B)
				else if not(TIM_���ăo���uAON.B) then 'ON
					mSV58_���ăo���uA=ON
				else if not(TIM_���ăo���uAOFF.B) then 'OFF
					mSV58_���ăo���uA=OFF
				end if
			
				if ldp(TIM_���ăo���uBOFF.B) then
					res(TIM_���ăo���uBON.B)
				else if ldp(TIM_���ăo���uBON.B) then
					res(TIM_���ăo���uBOFF.B)
				end if
			
				if not(�����ă��[�h) then
				
					if ldp(TIM_���ĉH��OFF.B) then
						res(TIM_���ĉH��ON.B)
					else if ldp(TIM_���ĉH��ON.B) then
						res(TIM_���ĉH��OFF.B)
					else if not(TIM_���ĉH��ON.B) then 'ON
						mMC5_���ĉH��=ON
					else if not(TIM_���ĉH��OFF.B) then 'OFF
						mMC5_���ĉH��=OFF
					end if
				
				end if

				tmr(tim_�C���`���O,tim_�C���`���O_val)
				if tim_�C���`���O.B then
					mSV58_���ăo���uA=OFF
					mMC5_���ĉH��=OFF
					inc(����step)
				end if

			end if					
		case 43
			if not(����AutoRun) then
				����step=1
			else if tim���ċ@.B then
				mSV1_�����d����=ON
				mSV58_���ăo���uA=OFF
				mMC5_���ĉH��=OFF
				mMC4_���ă|���v=ON

				tim���ċ@_val=100 '���ă|���v  ���đ҂�����
				res(tim���ċ@)
				inc(����step)
			end if
		case 44
			if not(����AutoRun) then
				����step=1
			else if tim���ċ@.B then
				mSV1_�����d����=ON
				mSV58_���ăo���uA=OFF
				mMC5_���ĉH��=OFF
				mMC4_���ă|���v=OFF

				tim���ċ@_val=100 '���ă|���v  ���Ē�~�҂�����(���ă^���N�ɐ��𒣂�j
				res(tim���ċ@)
				inc(����step)
			end if
		case 45
			if not(����AutoRun) then
				����step=1
			else if tim���ċ@.B then
				mSV1_�����d����=ON
				mSV58_���ăo���uA=OFF
				mMC5_���ĉH��=OFF
				mMC4_���ă|���v=ON

				tim���ċ@_val=100 '���ă|���v  ���đ҂�����
				res(tim���ċ@)
				inc(����step)
			end if
		case 46			
			if not(����AutoRun) then
				����step=1
			else if tim���ċ@.B then
				mSV1_�����d����=OFF
				mSV58_���ăo���uA=OFF
				mMC5_���ĉH��=OFF
				mMC4_���ă|���v=OFF
				inc(����step)
			end if
		case 47
				����AutoRun=OFF
				����step=0

		case 50		
			if not(����AutoRun) then
				����step=1
			else if tim���ċ@.B then
				mSV1_�����d����=OFF
				mSV58_���ăo���uA=OFF
				mMC5_���ĉH��=OFF
				mMC4_���ă|���v=OFF
				����step=0
			end if
		end select
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		
		'����AutoRun=OFF
		
		if ldp(pnlPBMC4_���ă|���v) then 
			if mMC4_���ă|���v then
				mMC4_���ă|���v=OFF
			else if RS1_���^���N����Z���T�[ then
				mMC4_���ă|���v=ON
			end if
		end if
		
		if ldp(pnlPBMC5_���ĉH��) then
			if mMC5_���ĉH�� then
				mMC5_���ĉH��=OFF
			else
				mMC5_���ĉH��=ON
			end if
		end if

		if ldp(pnlPBSV1_�����d����) then
			if mSV1_�����d���� then
				mSV1_�����d����=OFF
			else
				mSV1_�����d����=ON
			end if
		end if
		
		if ldp(pnlPBSV58_���ăo���uA) then
			if mSV58_���ăo���uA then
				mSV58_���ăo���uA=OFF
			else
				mSV58_���ăo���uA=ON
			end if
		end if
		
		if ldp(pnlPBSV12_���Đ؊��o���uA��) then
				mSV12_���Đ؊��o���uA��=ON
				mSV13_���Đ؊��o���uB��=OFF
		else if ldp(pnlPBSV13_���Đ؊��o���uB��) then
				mSV12_���Đ؊��o���uA��=OFF
				mSV13_���Đ؊��o���uB��=ON
		end if
		
	
	end if '����AutoMode and not(����OrgErrStep)

	'===================================================================================================================
	'�y ����OrgErr���� �z
	else
	
		if ResetFlg then	
			����OrgErr=OFF
		end if		

	end if

	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else

		PL2_�ُ�=ON

		pauseMC4_���ă|���v=ON
		pauseMC5_���ĉH��=ON


		select case ����ErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW9_���Đ؊�A��=OFF
				almXSW10_���Đ؊�B��=OFF
				inc(����ErrStep)
			end if
		case 2

			pauseMC4_���ă|���v=OFF
			pauseMC5_���ĉH��=OFF

			PL2_�ُ�=OFF
			����ErrStep=0
		end select

	end if 'if ����ErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	select case ����EmgStep
	case 0

	case 1
		����AutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (����AutoMode and ��������AutoMode) or ����step<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseSV1_�����d����=ON
			pauseSV58_���ăo���uA=ON
			pauseMC5_���ĉH��=ON
			pauseMC4_���ă|���v=ON			
			pauseSV12_���Đ؊��o���uA��=ON
			pauseSV13_���Đ؊��o���uB��=ON

			if timstack=OFF then
				tim_procstep_stack=tim���ċ@.U
				TIM_���ăo���uAON_stack=TIM_���ăo���uAON.U
				TIM_���ăo���uAOFF_stack=TIM_���ăo���uAOFF.U
				TIM_���ăo���uBON_stack=TIM_���ăo���uBON.U
				TIM_���ăo���uBOFF_stack=TIM_���ăo���uBOFF.U
				TIM_���ĉH��ON_stack=TIM_���ĉH��ON.U
				TIM_���ĉH��OFF_stack=TIM_���ĉH��OFF.U
				tim_�C���`���O_stack=tim_�C���`���O.U
				timstack=ON
			end if
			
			'---------------------------------
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mSV1_�����d����=OFF
			mSV58_���ăo���uA=OFF
			mMC5_���ĉH��=OFF
			mMC4_���ă|���v=OFF
			mSV12_���Đ؊��o���uA��=OFF
			mSV13_���Đ؊��o���uB��=OFF		
			'---------------------------------
		end if
		
		'---------------------------------
		inc(����EmgStep)
	case 2
		if ResetFlg then
			inc(����EmgStep)
		end if
	case 3
		if (����AutoMode and ��������AutoMode) or ����step<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseSV1_�����d����=OFF
				pauseSV58_���ăo���uA=OFF
				pauseMC5_���ĉH��=OFF
				pauseMC4_���ă|���v=OFF
				pauseSV12_���Đ؊��o���uA��=OFF
				pauseSV13_���Đ؊��o���uB��=OFF

				tim���ċ@.U=tim_procstep_stack
				TIM_���ăo���uAON.U=TIM_���ăo���uAON_stack
				TIM_���ăo���uAOFF.U=TIM_���ăo���uAOFF_stack
				TIM_���ăo���uBON.U=TIM_���ăo���uBON_stack
				TIM_���ăo���uBOFF.U=TIM_���ăo���uBOFF_stack
				TIM_���ĉH��ON.U=TIM_���ĉH��ON_stack
				TIM_���ĉH��OFF.U=TIM_���ĉH��OFF_stack
				tim_�C���`���O.U=tim_�C���`���O_stack
				
				'---------------------------------
				inc(����EmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(����EmgStep)		
		end if				
	case 4
		timstack=OFF	
		����EmgStep=0
		����Emg=OFF
	end select
		
end if 'if ����EmgStep=0 then
