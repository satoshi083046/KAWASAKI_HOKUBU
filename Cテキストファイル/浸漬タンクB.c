'�Z�Ѓ^���NB
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'
'	�Z�Ѓ^���NB�Ǘ� �����Ǘ�
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
    �Z�Ѓ^���NBAutoMode=ON
    �Z�Ѓ^���NBAutoRun=OFF
    �Z�Ѓ^���NB����=ON
    �Z�Ѓ^���NBOrgErr=OFF
    �Z�Ѓ^���NBErr=OFF
    �Z�Ѓ^���NBEmg=OFF
    �Z�Ѓ^���NBstep=0
    �Z�Ѓ^���NBErrStep=0
    �Z�Ѓ^���NBOrgErrStep=0
    �Z�Ѓ^���NBEmgStep=0
	
end if
'===================================================================================================================
'�y ���_ �z
�Z�Ѓ^���NBOrg=1

'===================================================================================================================
'�y �ً}��~ �z

	if not(PB����~) then
		�Z�Ѓ^���NBEmgStep=1
	end if

	select case �Z�Ѓ^���NBEmgStep
	case 0
	case 1
		�Z�Ѓ^���NBEmg=ON
		inc(�Z�Ѓ^���NBEmgStep)	
	case 2
		if ResetFlg then
			inc(�Z�Ѓ^���NBEmgStep)	
		end if
	case 3
		if StartFlg then
			inc(�Z�Ѓ^���NBEmgStep)
		end if
	case 4
		�Z�Ѓ^���NBEmg=OFF
		�Z�Ѓ^���NBEmgStep=0
	end select

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

	tmr(not(FLOS4_LMT121),timdly_FLOS4_LMT121,20)
	tmr(FLOS4_LMT121,timnotdly_FLOS4_LMT121,20)


'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �Z�Ѓ^���NBAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �Z�Ѓ^���NBAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �Z�Ѓ^���NBEmg	���̏��~

if SSW3_�������[�h and not(�Z�Ѓ^���NBEmg)  then

	RLY5_�p�h���Z���T�d��=ON	

	if �O������������ and �O�����H��step=0 then

		tmr(TIM_��pON_B,DM_��p����*10) 'ON=10�b
		tmr(TIM_��pOFF_B,DM_��p�C���^�[�o������*10) 'OFF=30��
		if ldp(TIM_��pOFF_B.B) then
			res(TIM_��pOFF_B) '�����̃^�C�}�[���N���A���A30�����Ƃ̃g���K�𔭐�
			res(TIM_��pON_B)
		end if
		

		if pnlPB�����ėLB or PDL4_�p�h���Z���T�[����B or not(FLOS4_LMT121) then
			if not(TIM_��pON_B.B) then
				extSV11_�����d����B=ON
			else
				extSV11_�����d����B=OFF	
			end if

		else
			extSV11_�����d����B=OFF	
		end if

	else
		extSV11_�����d����B=OFF		
		res(TIM_��pOFF_B)	'�����̃^�C�}�[���N���A���A30�����Ƃ̃g���K�𔭐�
		res(TIM_��pON_B)
	end if

else
	ejectSV11_�����d����B=OFF		
	RLY5_�p�h���Z���T�d��=OFF
	res(TIM_��pOFF_B)	'�����̃^�C�}�[���N���A���A30�����Ƃ̃g���K�𔭐�
	res(TIM_��pON_B)
end if

