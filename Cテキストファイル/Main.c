'Main
'===================================================================================================================
'
'<<<<<<<	Main���암	>>>>>>>>
'
'===================================================================================================================
�q��R�[�h=���k��

'-------------------------------------------------------------------------------------------------------------------
'�y�O�����H���z
'	�O����
'		����			DM_A�^���N�ݒ�l > 0
'		����			DM_A�^���N���Č��ݒl < DM_A�^���N�ݒ�l
'
'		���ăJ�E���g 	DM_�Z�Ѓ^���NA���Ċ���=DM_A�^���N���Č��ݒl - DM_A�z�Č��ݒl
'
'		�蓮�E�Z�Ѓ^���N�r�� and �Ė��� 	DM_A�^���N���Č��ݒl=0 DM_�Z�Ѓ^���NA���Ċ���=0
'
'	�����R���x�A�^�]
'
'		�����������ݒl>=���������ݒ�l
'			*���ъ�ɒ��΂���^�C�~���O
'		�z�ď����������ݒl>=�z�ď��������ݒ�l and  ldp(PB22_�����^�] and ��������AutoMode)  DM_A�z�Č��ݒl=0
'			*�z�ď��������F�z�ĉ\�Ȑ�򂳂ꂽ��
'
'		�z��			DM_�Z�Ѓ^���NA���Ċ���>0
'		�z�ďI��		DM_A�z�Đݒ�l=0 or DM_A�z�Č��ݒl>=DM_A�z�Đݒ�l or �Ė���
'
'		���Όx���܂ł̎c����>=���Όx���܂ł̎c�����ݒ�l
'
'		DM_�r�o�c��=0
'			*�����I���^�C�~���O(���т��ꂽ�������I�������^�C�~���O)
'
'-------------------------------------------------------------------------------------------------------------------
'�f�o�b�N���j�^�[
'
DM_A�^���N�ݒ�l=DM_A�^���N�ݒ�l
DM_A�^���N���Č��ݒl=DM_A�^���N���Č��ݒl
DM_A�^���N���Č��ݒl�c��=DM_A�^���N�ݒ�l-DM_A�^���N���Č��ݒl
if DM_A�^���N���Č��ݒl�c��<0 then
	DM_A�^���N���Č��ݒl�c��=0
end if
DM_�Z�Ѓ^���NA���Ċ���=DM_�Z�Ѓ^���NA���Ċ���
DM_A�z�Đݒ�l=DM_A�^���N�ݒ�l+DM_A�^���N�␳�l 'DM_A�^���N�␳�l (�����l=5)
DM_A�z�Č��ݒl=DM_A�z�Č��ݒl
DM_A�z�Č��ݒl�c��=DM_A�z�Đݒ�l-DM_A�z�Č��ݒl
if DM_A�z�Č��ݒl�c��<0 then
	DM_A�z�Č��ݒl�c��=0
end if

	if DM_A�z�Č��ݒl=0 then
		�z�Č��ݒlA�O���t=0
	else if DM_A�z�Č��ݒl>=DM_A�^���N�ݒ�l then
		�z�Č��ݒlA�O���t=100
	else
		�z�Č��ݒlA�O���t=(DM_A�z�Č��ݒl*100)/ DM_A�^���N�ݒ�l
	end if

'
DM_B�^���N�ݒ�l=DM_B�^���N�ݒ�l
DM_B�^���N���Č��ݒl=DM_B�^���N���Č��ݒl
DM_B�^���N���Č��ݒl�c��=DM_B�^���N�ݒ�l-DM_B�^���N���Č��ݒl
if DM_B�^���N���Č��ݒl�c��<0 then
	DM_B�^���N���Č��ݒl�c��=0
end if
DM_�Z�Ѓ^���NB���Ċ���=DM_�Z�Ѓ^���NB���Ċ���
DM_B�z�Đݒ�l=DM_B�^���N�ݒ�l+DM_B�^���N�␳�l 'DM_B�^���N�␳�l (�����l=5)
DM_B�z�Č��ݒl=DM_B�z�Č��ݒl

DM_B�z�Č��ݒl�c��=DM_B�z�Đݒ�l-DM_B�z�Č��ݒl
if DM_B�z�Č��ݒl�c��<0 then
	DM_B�z�Č��ݒl�c��=0
end if
	
	if DM_B�z�Č��ݒl=0 then
		�z�Č��ݒlB�O���t=0
	else if DM_B�z�Č��ݒl >= DM_B�^���N�ݒ�l then
		�z�Č��ݒlB�O���t=100
	else
		�z�Č��ݒlB�O���t= (DM_B�z�Č��ݒl*100) / DM_B�^���N�ݒ�l
	end if

DM_�z�đ����ݒ�l=DM_A�^���N�ݒ�l+DM_B�^���N�ݒ�l
DM_�z�đ���=DM_A�z�Č��ݒl+DM_B�z�Č��ݒl

DM_�r�o�c��=DM_�z�đ���-DM_�r�o����
if DM_�r�o�c��<0 or (DM_�r�o�c��>=0 and pnlPB�r�o�c�����Z�b�g) then
	DM_�r�o����=DM_�z�đ���
	DM_�r�o�c��=0	
end if

	if DM_�r�o����=0 then
		���]�����ݒl�O���t=0
		���]���c���O���t=0
	else if DM_�r�o����>=DM_�z�đ��� then
		���]�����ݒl�O���t=100
		���]���c���O���t=0
	else
		���]�����ݒl�O���t=(DM_�r�o����*100) / DM_�z�đ���
		���]���c���O���t=100-((DM_�r�o����*100) / DM_�z�đ���)
	end if



�^�]������=�^�]������
�^�]��������=�^�]��������

���������ݒ�l=���������ݒ�l '(�����l=25) 
�����������ݒl=�����������ݒl
�����������ݒl�c��=���������ݒ�l-�����������ݒl
if �����������ݒl�c��<0 then
	�����������ݒl�c��=0
end if

if ��������<0 then
	��������=0
else if ��������>DM_�z�đ��� then
	��������=DM_�z�đ���-1
end if

�z�ď��������ݒ�l=�z�ď��������ݒ�l '(�����l=5)
�z�ď����������ݒl=�z�ď����������ݒl
�z�ď����������ݒl�c��=�z�ď��������ݒ�l-�z�ď����������ݒl
if �z�ď����������ݒl�c��<0 then
	�z�ď����������ݒl�c��=0
end if

���Όx���܂ł̎c�����ݒ�l=���Όx���܂ł̎c�����ݒ�l '(�����l=30)
���Όx���܂ł̎c����=���Όx���܂ł̎c����
���Όx���܂ł̎c�����c��=���Όx���܂ł̎c�����ݒ�l-���Όx���܂ł̎c����
if ���Όx���܂ł̎c�����c��<0 then
	���Όx���܂ł̎c�����c��=0
end if

�z�ďI���t���O=�z�ďI���t���O


'IH_A,IH_B �ɔ����� inc(IH�������ъ��J�E���g) ���o�� dec(IH�������ъ��J�E���g)
if IH�������ъ��J�E���g<0 then
	IH�������ъ��J�E���g=0
else if IH�������ъ��J�E���g>0 then
	IND_���ђ�=ON
else if IH�������ъ��J�E���g=0 then
	IND_���ђ�=OFF
end if

'�z�đ��� / 2 �̌v�Z�l
if (DM_A�^���N�ݒ�l + DM_B�^���N�ݒ�l)>0 then
	�`�F�b�N�����ݒ�l=(DM_A�^���N�ݒ�l + DM_B�^���N�ݒ�l)/2
else
	�`�F�b�N�����ݒ�l=0
end if
�`�F�b�N�������ݒl=DM_A�z�Č��ݒl + DM_B�z�Č��ݒl 


'===================================================================================================================
'�y ���������� �z
'-------------------------------------------------------
if CR2008 then '�d��ON������������
	if not(PB23_������~) and PB34_���Z�b�g then
		�e�X�g�^�]=ON
	else	
		�e�X�g�^�]=OFF
	end if
	
	���ъ�����~�y�ρz=OFF
end if
'-------------------------------------------------------
'�e�X�g�^�]����������
if ldp(�e�X�g�^�]) and ��������AutoMode then
	�Z�Ѓ^���NA���j�b�g����=OFF
	�Z�Ѓ^���NB���j�b�g����=OFF
	�v�����j�b�g����=OFF
	���^���NAutoMode=ON
	���^���NAutoRun=ON
	�������֎~=ON
end if

if ldf(�e�X�g�^�])  and ��������AutoMode then
	���^���NAutoMode=OFF
	���^���NAutoRun=OFF
	�������֎~=OFF
end if
	
'-------------------------------------------------------
'�O�����\��ɂ�鎩���N���A
'-------------------------------------------------------
if ldp(�O�����H��AutoRun) and DM_A�^���N���Č��ݒl=0 and DM_B�^���N���Č��ݒl=0 then
	�^�]������=OFF
	�^�]��������=OFF
	
	shiftreg���t�^����0=0
	shiftreg���t�^����1=0
	shiftreg���t�^����2=0
	shiftreg���t�^����3=0
	shiftreg���t�^����4=0
	shiftreg���t�^����5=0
	
end if
'-------------------------------------------------------
'�e�H������ 
if �e�X�g�^�] then
	������~=OFF
	IND_������~�\=OFF
end if

if not(�e�X�g�^�]) then

'--�^�]������
if �^�]������ then
	if Main�菇������ then
		StageDevice0=0
		StageDevice1=0
		StageDevice2=0
		StageDevice3=0
		StageDevice4=0
		StageDevice5=0
		StageDevice6=0
		StageDevice7=0
		StageDevice8=0
		StageDevice9=0
		StageDevice10=0
		StageDevice11=0
		StageDevice12=0
		
		Main�菇������=OFF

		'�O���[�o���E�B���h�E����		
		tmsg�^�]��������=OFF
		tmsg�^�]������������=ON
		
		tmsg�z�Ċ����\��=OFF
		tmsg�z�Ċ�������=ON
		
		tmsg������~���\��=OFF
		tmsg������~������=ON
		
		tmsg���ъ����\��=OFF
		tmsg���ъ�������=ON
		
	end if
	
	IND_�z�ď���=ON
	IND_�z�Ē�=OFF
	IND_���ђ�=OFF
	IND_���ъ���=OFF
	IND_��~�ҋ@=OFF
	
	�Z�Ѓ^���NA���j�b�g����=OFF
	�Z�Ѓ^���NB���j�b�g����=OFF
	
	ITEM�o�^�֎~=OFF
	
	if not(PB23_������~) then
		�^�]������=OFF
		�^�]��������=OFF
				
		���^���NAutoMode=OFF
		���^���NAutoRun=OFF

		�^�]�����J�n�m�F�y�ρz=OFF
		���ы@�_�Ύ��s�m�F�y�ρz=OFF
		
		�Z�Ѓ^���NA���j�b�g����=OFF
		�Z�Ѓ^���NB���j�b�g����=OFF

		tmsg�^�]��������=OFF '�z�Ďn�܂�
		tmsg�^�]������������=OFF'�z�Ďn�܂�
		tmsg�z�Ċ����\��=OFF
		tmsg�z�Ċ�������=OFF
		tmsg������~���\��=OFF
		tmsg������~������=OFF
		tmsg���ъ����\�� =OFF
		tmsg���ъ�������=OFF

	
	else
		if ���ы@�_�Ύ��s�m�F�y�ρz then


			if �^�]�����J�n�m�F�y�ρz and (�z�ď����������ݒl>=�z�ď��������ݒ�l or ���֎~) then '�������𐆔ы@�ɔ����ς�
				
				'�z�ď���
				tmsg�^�]��������=ON '�z�Ďn�܂�
				tmsg�^�]������������=OFF'�z�Ďn�܂�
				
				MainStatusMsg=#110
			
				if ldp(pnlPBOK) or (ldp(PB22_�����^�] and ��������AutoMode) and PB23_������~) then 'and ��������AutoRun then
					
					'�z�Ď��s����
					�^�]������=OFF
					�^�]��������=ON
					
					���^���NAutoMode=ON
					���^���NAutoRun=ON
					
					���ы@���Όx���y�ρz=OFF
					���ъ�����~�y�ρz=OFF
					�z�ďI���t���O=OFF
					
					�����҂���~=OFF

					'-------------------------------------------------------
					'�f�[�^�N���A
					'-------------------------------------------------------			
					DM_A�z�Č��ݒl=0
					DM_B�z�Č��ݒl=0
					DM_�r�o����=0
					
					'�O���[�o���E�B���h�E����
					tmsg�^�]��������=OFF
					tmsg�^�]������������=ON
					
					tmsg�z�Ċ����\��=OFF
					tmsg�z�Ċ�������=OFF
					
					tmsg������~���\��=OFF
					tmsg������~������=OFF
					
					tmsg���ъ����\��=OFF
					tmsg���ъ�������=OFF
					'-------------------------------------------------------
					StageDevice51=0 '�����]�ʒu(���]�ʒu�j
					StageDevice52=0 '���t�g�ʒu
					'-------------------------------------------------------

					�^�]������=OFF
				end if
			end if
			
	
		else if �^�]�����J�n�m�F�y�ρz then '���^���NAutoRun�ς�

			���ы@�_�Ύ��s�m�F�y�ρz=ON
			�z�ď����������ݒl=0			
	
		else if ���C��TP_�ؑփy�[�W�m��15�y�ρz then '�`�F�b�N�V�[�g  �`�F�b�N�ς�	
			���C��TP_�ؑփy�[�W�m��=21

			if ldp(PB22_�����^�] and ��������AutoMode) and PB23_������~  then 'and ��������AutoRun then

				'���^���N=ON
				�^�]�����J�n�m�F�y�ρz=ON
				
				���^���NAutoMode=ON
				���^���NAutoRun=ON

			end if
		end if
	
	end if

'--�^�]�������� (�z�ĉ^�]�j
else if �^�]�������� then
	
	Main�菇������=OFF
	�^�]����������=OFF			
	
	if not(�^�]������) then '�^�]����������<�������e>���o�^
		'<�������e>
		�^�]������=ON

		IND_�z�ď���=OFF
		IND_�z�Ē�=OFF
		'IND_���ђ�=OFF
		IND_���ъ���=OFF
		IND_��~�ҋ@=OFF

		�Z�Ѓ^���NA���j�b�g����=ON
		�Z�Ѓ^���NB���j�b�g����=ON
		�v�����j�b�g����=ON
		
		���ъ�������̊��J�E���g=0
		�󊘔������sstep=0
	end if

	if ldp(�����҂���~) then
		tmsg������~���\��=ON
		tmsg������~������=OFF
	else if ldp(�����҂���~����) then
		tmsg������~���\��=OFF
		tmsg������~������=ON		
	end if

	if IND_�z�Ē� then
		if ldp(�Z�Ѓ^���NA�Ė���) then
			pnlPB�����Ė���A=ON
		else if ldp(�Z�Ѓ^���NB�Ė���) then
			pnlPB�����Ė���B=ON
		end if
	end if

	if ldp(�`�F�b�N�������ݒl=�`�F�b�N�����ݒ�l) and not(���֎~) then
		�󊘔������sstep=1		
	end if
	
	select case �󊘔������sstep
	case 0
	case 1
		if �A�C�h�������ݒ�l=0 then
			�A�C�h���������ݒl=�A�C�h�������ݒ�l
			�󊘔������sstep=0
		else
			�A�C�h���������ݒl=0
			inc(�󊘔������sstep)
		end if
	case 2
		�Z�Ѓ^���NA���j�b�g����=OFF
		�Z�Ѓ^���NB���j�b�g����=OFF
		inc(�󊘔������sstep)
	
	
	case 3
		if �A�C�h���������ݒl>�A�C�h�������ݒ�l or ���֎~ then
			�Z�Ѓ^���NA���j�b�g����=ON
			�Z�Ѓ^���NB���j�b�g����=ON
			�󊘔������sstep=0
		end if
	
	end select
	
	if �z�ďI���t���O or (not(�Z�Ѓ^���NA���j�b�g����) and not(�Z�Ѓ^���NB���j�b�g����)) then
		IND_�z�Ē�=OFF
	else
		IND_�z�Ē�=ON
	end if	
	
'-- A�z�Ċ��� and B�z�Ċ���
	if (DM_A�^���N�ݒ�l=0 or �Z�Ѓ^���NA�Ė���) and  (DM_B�^���N�ݒ�l=0 or �Z�Ѓ^���NB�Ė���) then
		
		if not(�z�ďI���t���O) then
			�z�ďI���t���O=ON
			tmsg�^�]������������=OFF 'tmsg�^�]������������ tmsg�^�]����������ID�������̂��� ON���̏�����OFF��Ԃɂ��� 
			tmsg�z�Ċ����\��=ON '�z�Ċ����\��
			tmsg�z�Ċ�������=OFF '�z�Ċ�������		
		else 	
			if tmsg�z�Ċ����\�� then
				if pnlPBOK or pnlPB�߂� then
					tmsg�z�Ċ����\��=OFF '�z�Ċ����\��
					tmsg�z�Ċ�������=ON '�z�Ċ�������		
				end if			
			end if
		end if

		if ldp(DM_�r�o�c��=0) then
			���ъ�������̊��J�E���g=5
		end if


		if DM_�r�o�c��<=0 or tmsg���ъ����\�� then
			
		
			if ���ъ�����~�y�ρz then
				'tmsg�����^�]��~�x���\��=OFF
				'tmsg�����^�]��~�x������=ON
				
				'�I������ ->
				tmsg���ъ����\��=OFF '���ъ����ʒm
				tmsg���ъ�������=ON  '���ъ����ʒm

				IND_���ъ���=OFF
				IND_��~�ҋ@=OFF				
						
				�Z�Ў��Ԍv���^���NA=OFF
				�Z�Ў��Ԍv���^���NB=OFF
						
			else
				IND_���ђ�=OFF
				IND_���ъ���=ON
				if ���ъ�������̊��J�E���g>0 then
					IND_��~�ҋ@=CR2006
				else
					IND_��~�ҋ@=ON
				end if

				select case ���ъ�������̊��J�E���g
				case 0
					IND_EndCnt1=OFF
					IND_EndCnt2=OFF
					IND_EndCnt3=OFF
					IND_EndCnt4=OFF
					IND_EndCnt5=OFF
					IND_EndCnt6=OFF
					IND_EndCnt7=OFF
					IND_EndCnt8=OFF
					
					if ������~�ݒ� then
						������~=ON
					else 
						������~=OFF
					end if
					IND_������~�\=ON
					
				case 1
					IND_EndCnt1=ON
					IND_EndCnt2=OFF
					IND_EndCnt3=OFF
					IND_EndCnt4=OFF
					IND_EndCnt5=OFF
					IND_EndCnt6=OFF
					IND_EndCnt7=OFF
					IND_EndCnt8=OFF
				case 2
					IND_EndCnt1=ON
					IND_EndCnt2=ON
					IND_EndCnt3=OFF
					IND_EndCnt4=OFF
					IND_EndCnt5=OFF
					IND_EndCnt6=OFF
					IND_EndCnt7=OFF
					IND_EndCnt8=OFF
				case 3
					IND_EndCnt1=ON
					IND_EndCnt2=ON
					IND_EndCnt3=ON
					IND_EndCnt4=OFF
					IND_EndCnt5=OFF
					IND_EndCnt6=OFF
					IND_EndCnt7=OFF
					IND_EndCnt8=OFF
				case 4
					IND_EndCnt1=ON
					IND_EndCnt2=ON
					IND_EndCnt3=ON
					IND_EndCnt4=ON
					IND_EndCnt5=OFF
					IND_EndCnt6=OFF
					IND_EndCnt7=OFF
					IND_EndCnt8=OFF
				case 5
					IND_EndCnt1=ON
					IND_EndCnt2=ON
					IND_EndCnt3=ON
					IND_EndCnt4=ON
					IND_EndCnt5=ON
					IND_EndCnt6=OFF
					IND_EndCnt7=OFF
					IND_EndCnt8=OFF				
				end select

				MainStatusMsg=#120 '��~������		
				'tmsg�����^�]��~�x���\��=ON
				'tmsg�����^�]��~�x������=OFF
				
				tmsg���ъ����\��=ON '���ъ����ʒm
				tmsg���ъ�������=OFF '���ъ����ʒm

				if not(PB23_������~) or not(PB35_��~) or not(PB37_��~) or ������~ or ���֎~ then
					'tmsg�����^�]��~�x���\��=OFF
					'tmsg�����^�]��~�x������=ON
					
					tmsg���ъ����\��=OFF '���ъ����ʒm
					tmsg���ъ�������=ON '���ъ����ʒm
					�^�]��������=OFF
					���ъ�����~�y�ρz=ON '->�I��
					
					pnlPB�����Ė���A=OFF
					pnlPB�����Ė���B=OFF

				end if				
			end if
			
		end if
	
	else
		�z�ďI���t���O=OFF
	
		���ы@���Όx���y�ρz=OFF
		���ъ�����~�y�ρz=OFF
		
		tmsg�z�Ċ����\��=OFF
		tmsg�z�Ċ�������=OFF


	end if
	
	
else '�^�]����=OFF �^�]��������=OFF
	IND_�z�ď���=OFF
	IND_�z�Ē�=OFF
	'IND_���ђ�=OFF
	IH�������ъ��J�E���g=0
	IND_���ъ���=OFF
	IND_��~�ҋ@=OFF
	
	������~=OFF
	IND_������~�\=OFF
	
	ITEM�o�^�֎~=ON

	
	
	if not(PB23_������~) then

		���C��TP_�ؑփy�[�W�m��=21

		'tmsgxxxx=OFF
		tmsg�^�]�����J�n�m�F=OFF
		tmsg�^�]��������=OFF
		
		tmsg�����^�]��~�x���\��=OFF			
		tmsg�����^�]��~�x������=ON
		
		tmsg���ъ����\��=OFF
		tmsg���ъ�������=ON
		
		IND_�z�ď���=OFF
		IND_�z�Ē�=OFF
		'IND_���ђ�=OFF
		IH�������ъ��J�E���g=0
		IND_���ъ���=OFF
		IND_��~�ҋ@=OFF



	else 
	
		if ���C��TP_�ؑփy�[�W�m��=15 then

			
			tmsg�^�]�����J�n�m�F=OFF
			
			tmsg�^�]��������=OFF '�z�Ďn�܂�
			tmsg�^�]������������=OFF'�z�Ďn�܂�
			tmsg�z�Ċ����\��=OFF
			tmsg�z�Ċ�������=OFF
			tmsg������~���\��=OFF
			tmsg������~������=OFF
			tmsg���ъ����\�� =OFF
			tmsg���ъ�������=OFF
			
			
			msg������~���\��=OFF
			msg������~������=OFF

			if �r�����m�F�y�ρz and ���C�ݔ��m�F�y�ρz and �Z�Ѓ^���N�ē����m�F�y�ρz then
				if pnlPBOK then
				
					�^�]������=ON
					�^�]��������=OFF
					���C��TP_�ؑփy�[�W�m��15�y�ρz=ON
					���C�ݔ��m�F�y�ρz=OFF
					�Z�Ѓ^���N�ē����m�F�y�ρz=OFF
					�r�����m�F�y�ρz=OFF
					
	
				end if
			end if

		else if ldp(PB22_�����^�]) and PB23_������~ and ��������AutoMode then
			
			'�^�]�����̂��߂̏����ݒ�
			���C��TP_�ؑփy�[�W�m��=15
			
			'xxx�y�ρz=OFF
			���C��TP_�ؑփy�[�W�m��15�y�ρz=OFF
			���C�ݔ��m�F�y�ρz=OFF
			�Z�Ѓ^���N�ē����m�F�y�ρz=OFF
			�Z�Ѓ^���N�ē����m�F�y�ρz=OFF
			�r�����m�F�y�ρz=OFF					

			�^�]�����J�n�m�F�y�ρz=OFF
			���ы@�_�Ύ��s�m�F�y�ρz=OFF
			�z�ďI���t���O=OFF

			
		else		
			if not(Main�菇������) then
				
				���^���NAutoMode=OFF
				���^���NAutoRun=OFF
				
				Main�菇������=ON
			end if

			if not(�^�]����������) then
				
				�r�����m�F�y�ρz=OFF
				���C�ݔ��m�F�y�ρz=OFF
				�Z�Ѓ^���N�ē����m�F�y�ρz=OFF

				�z�ďI���t���O=OFF
				
				���C��TP_�ؑփy�[�W�m��=21
				���C��TP_�ؑփy�[�W�m��15�y�ρz=OFF
			
				�^�]����������=ON

			end if
			

			�����������ݒl=0
			�z�ď����������ݒl=0
			DM_A�z�Č��ݒl=0
			DM_B�z�Č��ݒl=0
			DM_�r�o����=0
			��������=0

			���Όx���܂ł̎c����=0
			��������=0
			�󊘔�������=0
			���J�E���gA=0
			���J�E���gB=0
			

			�^�]������=OFF
			�^�]��������=OFF
			�����҂���~=OFF


		end if
		
	end if
	
end if

end if
'===================================================================================================================
'�\���M����ON�̂Ƃ��A�����M�������ׂ�OFF�ɂ���B
tmr(t�u�U�[�x��,tim_t�u�U�[�x��,#20)
�u�U�[�x��=t�u�U�[�x�� and not(tim_t�u�U�[�x��.B) 

if tmsg�^�]�������� or tmsg�z�Ċ����\�� or tmsg������~���\�� or tmsg���ъ����\�� then

	t�u�U�[�x��=ON
	tmsg�^�]������������=OFF
	tmsg�z�Ċ�������=OFF
	tmsg������~������=OFF
	tmsg���ъ�������=OFF

else
	t�u�U�[�x��=OFF
end if

'===================================================================================================================
'msg�M��(1sec)�m��o��
if (20<=���C��TP_�\�����y�[�WNo and ���C��TP_�\�����y�[�WNo<=24) and (20<=�T�uTP_�\�����y�[�WNo and �T�uTP_�\�����y�[�WNo<=24) and (20<=�ނ炵TP_�\�����y�[�WNo and �ނ炵TP_�\�����y�[�WNo<=24) then

	tmr(tmsg�^�]�����J�n�m�F,tim_tmsg�^�]�����J�n�m�F,10)
	msg�^�]�����J�n�m�F=tmsg�^�]�����J�n�m�F and not(tim_tmsg�^�]�����J�n�m�F.B)
	tmr(tmsg�^�]�����J�n�m�F����,tim_tmsg�^�]�����J�n�m�F����,20)
	msg�^�]�����J�n�m�F����=tmsg�^�]�����J�n�m�F���� and not(tim_tmsg�^�]�����J�n�m�F����.B)

	'---
	tmr(tmsg�^�]��������,tim_tmsg�^�]��������,20)
	msg�^�]��������=tmsg�^�]�������� and not(tim_tmsg�^�]��������.B)
	tmr(tmsg�^�]������������,tim_tmsg�^�]������������,20)
	msg�^�]������������=tmsg�^�]������������ and not(tim_tmsg�^�]������������.B)
	'---
	tmr(tmsg���ъ����\��,tim_tmsg���ъ����\��,10)
	msg���ъ����\��=tmsg���ъ����\�� and not(tim_tmsg���ъ����\��.B)
	tmr(tmsg���ъ�������,tim_tmsg���ъ�������,10)
	msg���ъ�������=tmsg���ъ������� and not(tim_tmsg���ъ�������.B)
	'---
	tmr(tmsg�z�Ċ����\��,tim_tmsg�z�Ċ����\��,10)
	msg�z�Ċ����\��=tmsg�z�Ċ����\�� and not(tim_tmsg�z�Ċ����\��.B)
	tmr(tmsg�z�Ċ�������,tim_tmsg�z�Ċ�������,10)
	msg�z�Ċ�������=tmsg�z�Ċ������� and not(tim_tmsg�z�Ċ�������.B)
	'---
	tmr(tmsg������~���\��,tim_tmsg������~���\��,10)
	msg������~���\��=tmsg������~���\�� and not(tim_tmsg������~���\��.B)
	tmr(tmsg������~������,tim_tmsg������~������,10)
	msg������~������=tmsg������~������ and not(tim_tmsg������~������.B)

else

	msg�^�]�����J�n�m�F=OFF
	msg�^�]�����J�n�m�F����=ON
	
	msg���ы@�_�Ύ��s�x��=OFF
	
	msg�^�]��������=OFF
	msg�^�]������������=ON
	
	msg�z�Ċ����\��=OFF	
	msg�z�Ċ�������=ON
	
	msg���ъ����\��=OFF
	msg���ъ�������=ON
	
	msg���ы@���Όx���\��=OFF
	msg���ы@���Όx������=ON

end if

tmr(msgFleshCycl,#40)
if ldp(msgFleshCycl.B) then
	res(msgFleshCycl)

	res(tim_tmsg�^�]�����J�n�m�F)
	res(tim_tmsg�^�]�����J�n�m�F����)	
	res(tim_tmsg�^�]��������)
	res(tim_tmsg�^�]������������)
	res(tim_tmsg���ъ����\��)
	res(tim_tmsg���ъ�������)
	res(tim_tmsg�z�Ċ����\��)
	res(tim_tmsg�z�Ċ�������)
	res(tim_tmsg������~���\��)
	res(tim_tmsg������~������)

end if


'===================================================================================================================
'�p�g���C�g

	PTL1_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL2_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL3_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL4_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL5_�p�g���C�g��=�p�g���C�g�� and CR2006
	'
	PTL1_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL2_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL3_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL4_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL5_�p�g���C�g��=�p�g���C�g�� and CR2006
	'
	PTL1_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL2_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL3_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL4_�p�g���C�g��=�p�g���C�g�� and CR2006
	PTL5_�p�g���C�g��=�p�g���C�g�� and CR2006
	'
	PTL1_�p�g���C�g�u�U�[=PBL����~ or (�u�U�[�x�� and CR2006) 
	PTL2_�p�g���C�g�u�U�[=PBL����~ or (�u�U�[�x�� and CR2006) 
	PTL3_�p�g���C�g�u�U�[=PBL����~ or (�u�U�[�x�� and CR2006) 
	PTL4_�p�g���C�g�u�U�[=PBL����~ or (�u�U�[�x�� and CR2006) 
	PTL5_�p�g���C�g�u�U�[=PBL����~ or (�u�U�[�x�� and CR2006) 


	if ��������ErrStep<>0 then
		�p�g���C�g��=ON
		�p�g���C�g��=OFF
		�p�g���C�g��=OFF	
	else if OtherErrStep<>0 then
		�p�g���C�g��=OFF
		�p�g���C�g��=ON
		�p�g���C�g��=OFF
	else if ��������AutoRun then
		�p�g���C�g��=OFF
		�p�g���C�g��=OFF
		�p�g���C�g��=ON
	else
		�p�g���C�g��=OFF
		�p�g���C�g��=OFF
		�p�g���C�g��=OFF	
	end if	
	

' PL�C���W�P�[�^

	PBL22_�����^�]=(�^�]������ and CR2006) or (�^�]�������� and ��������AutoRun)
	
	'--------------------------------
	if ��������AutoRun then
		PL9_�^�]��=ON
		PL11_�^�]��=ON
		PL21_�^�]��=ON
	else
		if OtherStep<>0 then
			if CR2006 then
				PL9_�^�]��=ON
				PL11_�^�]��=ON
				PL21_�^�]��=ON
			else
				PL9_�^�]��=OFF
				PL11_�^�]��=OFF
				PL21_�^�]��=OFF
			end if
		else
			PL9_�^�]��=OFF
			PL11_�^�]��=OFF
			PL21_�^�]��=OFF
		end if		
	end if

	'--------------------------------
	if ��������ErrStep<>0 or OtherErrStep<>0  then

		if CR2006 then
			PL10_�ُ�=ON
			PL12_�ُ�=ON
			PL16_�ُ�=ON
		else
			PL10_�ُ�=OFF
			PL12_�ُ�=OFF
			PL16_�ُ�=OFF
		end if

	else
		PL10_�ُ�=OFF
		PL12_�ُ�=OFF
		PL16_�ُ�=OFF
	end if
	'--------------------------------
	
'===================================================================================================================
' ���d�Z���T�d��OFF
if ��������AutoMode or ��������AutoRun or OtherStep<>0 then
	RLY_���d�Z���T�d��OFF1=OFF
	RLY_���d�Z���T�d��OFF2=OFF
	RLY_���d�Z���T�d��OFF3=OFF
	RLY_���d�Z���T�d��OFF4=OFF
	RLY_���d�Z���T�d��OFF5=OFF
	RLY_���d�Z���T�d��OFF6=OFF
	RLY_���d�Z���T�d��OFF7=OFF

else
	if ldp(pnlPBRLY_���d�Z���T�d��OFF1) then
		if RLY_���d�Z���T�d��OFF1=ON then
			RLY_���d�Z���T�d��OFF1=OFF
		else
			RLY_���d�Z���T�d��OFF1=ON
		end if
	end if
	if ldp(pnlPBRLY_���d�Z���T�d��OFF2) then
		if RLY_���d�Z���T�d��OFF2=ON then
			RLY_���d�Z���T�d��OFF2=OFF
		else
			RLY_���d�Z���T�d��OFF2=ON
		end if
	end if
	if ldp(pnlPBRLY_���d�Z���T�d��OFF3) then
		if RLY_���d�Z���T�d��OFF3=ON then
			RLY_���d�Z���T�d��OFF3=OFF
		else
			RLY_���d�Z���T�d��OFF3=ON
		end if
	end if
	if ldp(pnlPBRLY_���d�Z���T�d��OFF4) then
		if RLY_���d�Z���T�d��OFF4=ON then
			RLY_���d�Z���T�d��OFF4=OFF
		else
			RLY_���d�Z���T�d��OFF4=ON
		end if
	end if
	if ldp(pnlPBRLY_���d�Z���T�d��OFF5) then
		if RLY_���d�Z���T�d��OFF5=ON then
			RLY_���d�Z���T�d��OFF5=OFF
		else
			RLY_���d�Z���T�d��OFF5=ON
		end if
	end if
	if ldp(pnlPBRLY_���d�Z���T�d��OFF6) then
		if RLY_���d�Z���T�d��OFF6=ON then
			RLY_���d�Z���T�d��OFF6=OFF
		else
			RLY_���d�Z���T�d��OFF6=ON
		end if
	end if
	if ldp(pnlPBRLY_���d�Z���T�d��OFF7) then
		if RLY_���d�Z���T�d��OFF7=ON then
			RLY_���d�Z���T�d��OFF7=OFF
		else
			RLY_���d�Z���T�d��OFF7=ON
		end if
	end if
end if

'===================================================================================================================
'����~�t���O
	PB����~=PB����~���C�� and PB����~�ނ炵 and PB����~�T�u and PB26_�R���x�A��~ and PB27_�R���x�A��~ and PB28_�R���x�A��~ and PB29_�R���x�A��~
	PBL����~ = not(PB����~) and CR2006
	EmgFlg=not(PB����~) or EmgFlg
	if not(PB����~) then
		��������EmgStep=1
	end if
	
'���Z�b�g�t���O
	ResetFlg=PB34_���Z�b�g or PB24_���Z�b�g or PB38_���Z�b�g



'===================================================================================================================
'�X�e�[�W�V�O�i�� 
'===================================================================================================================
OtherOrgErr= �Z�Ѓ^���NA���j�b�gOrgErr
OtherOrgErr= OtherOrgErr or �Z�Ѓ^���NB���j�b�gOrgErr
OtherOrgErr= OtherOrgErr or �v�����j�b�gOrgErr
OtherOrgErr= OtherOrgErr or �Ȃ炵���j�b�gOrgErr
OtherOrgErr= OtherOrgErr or �W�킹���j�b�gOrgErr
OtherOrgErr= OtherOrgErr or �W��胆�j�b�gOrgErr
OtherOrgErr= OtherOrgErr or �ق����@A���j�b�gOrgErr
OtherOrgErr= OtherOrgErr or �����R���x�AAOrgErr
OtherOrgErr= OtherOrgErr or �����R���x�ABOrgErr
OtherOrgErr= OtherOrgErr or �����R���x�ACOrgErr
OtherOrgErr= OtherOrgErr or �����R���x�AC2OrgErr
OtherOrgErr= OtherOrgErr or �����R���x�ADOrgErr
OtherOrgErr= OtherOrgErr or �����R���x�AEOrgErr
'OtherOrgErr= OtherOrgErr or �����R���x�AF1OrgErr
'OtherOrgErr= OtherOrgErr or �����R���x�AF2OrgErr
OtherOrgErr= OtherOrgErr or �����R���x�AGOrgErr
OtherOrgErr= OtherOrgErr or �����R���x�AHOrgErr
OtherOrgErr= OtherOrgErr or ���t�^���~���uAOrgErr
OtherOrgErr= OtherOrgErr or �����]����OrgErr
OtherOrgErr= OtherOrgErr or ��򃆃j�b�gOrgErr
'OtherOrgErr= OtherOrgErr or ���^���NOrgErr
OtherOrgErr= OtherOrgErr or ���R���x�A����OrgErr
OtherOrgErr= OtherOrgErr or �����]�o��OrgErr
OtherOrgErr= OtherOrgErr or ���t�^���~���uBOrgErr
'OtherOrgErr= OtherOrgErr or IH���у��j�b�gAOrgErr
'OtherOrgErr= OtherOrgErr or IH���у��j�b�gBOrgErr

'===================================================================================================================
OtherErr= �Z�Ѓ^���NA���j�b�gErr
OtherErr= OtherErr or �Z�Ѓ^���NB���j�b�gErr
OtherErr= OtherErr or �v�����j�b�gErr
OtherErr= OtherErr or �Ȃ炵���j�b�gErr
OtherErr= OtherErr or �W�킹���j�b�gErr
OtherErr= OtherErr or �W��胆�j�b�gErr
OtherErr= OtherErr or �ق����@A���j�b�gErr
OtherErr= OtherErr or �����R���x�AAErr
OtherErr= OtherErr or �����R���x�ABErr
OtherErr= OtherErr or �����R���x�ACErr
OtherErr= OtherErr or �����R���x�AC2Err
OtherErr= OtherErr or �����R���x�ADErr
OtherErr= OtherErr or �����R���x�AEErr
OtherErr= OtherErr or �����R���x�AF1Err
OtherErr= OtherErr or �����R���x�AF2Err
OtherErr= OtherErr or �����R���x�AGErr
OtherErr= OtherErr or �����R���x�AHErr
OtherErr= OtherErr or ���t�^���~���uAErr
OtherErr= OtherErr or �����]����Err
OtherErr= OtherErr or ��򃆃j�b�gErr
'OtherErr= OtherErr or ���^���NErr
OtherErr= OtherErr or ���R���x�A����Err
OtherErr= OtherErr or �����]�o��Err
OtherErr= OtherErr or ���t�^���~���uBErr
'OtherErr= OtherErr or IH���у��j�b�gAErr
'OtherErr= OtherErr or IH���у��j�b�gBErr
'==================================================================================================================
OtherEmg= �Z�Ѓ^���NA���j�b�gEmg
OtherEmg= OtherEmg or �Z�Ѓ^���NB���j�b�gEmg
OtherEmg= OtherEmg or �v�����j�b�gEmg
OtherEmg= OtherEmg or �Ȃ炵���j�b�gEmg
OtherEmg= OtherEmg or �W�킹���j�b�gEmg
OtherEmg= OtherEmg or �W��胆�j�b�gEmg
OtherEmg= OtherEmg or �ق����@A���j�b�gEmg
OtherEmg= OtherEmg or �����R���x�AAEmg
OtherEmg= OtherEmg or �����R���x�ABEmg
OtherEmg= OtherEmg or �����R���x�ACEmg
OtherEmg= OtherEmg or �����R���x�AC2Emg
OtherEmg= OtherEmg or �����R���x�ADEmg
OtherEmg= OtherEmg or �����R���x�AEEmg
OtherEmg= OtherEmg or �����R���x�AF1Emg
OtherEmg= OtherEmg or �����R���x�AF2Emg
OtherEmg= OtherEmg or �����R���x�AGEmg
OtherEmg= OtherEmg or �����R���x�AHEmg
OtherEmg= OtherEmg or ���t�^���~���uAEmg
OtherEmg= OtherEmg or �����]����Emg
OtherEmg= OtherEmg or ��򃆃j�b�gEmg
'OtherEmg= OtherEmg or ���^���NEmg
OtherEmg= OtherEmg or ���R���x�A����Emg
OtherEmg= OtherEmg or �����]�o��Emg
OtherEmg= OtherEmg or ���t�^���~���uBEmg
'OtherEmg= OtherEmg or IH���у��j�b�gAEmg
'OtherEmg= OtherEmg or IH���у��j�b�gBEmg
'===================================================================================================================
OtherOrg= �Z�Ѓ^���NA���j�b�gOrg
OtherOrg= OtherOrg and �Z�Ѓ^���NB���j�b�gOrg
OtherOrg= OtherOrg and �v�����j�b�gOrg
OtherOrg= OtherOrg and �Ȃ炵���j�b�gOrg
OtherOrg= OtherOrg and �W�킹���j�b�gOrg
OtherOrg= OtherOrg and �W��胆�j�b�gOrg
OtherOrg= OtherOrg and �ق����@A���j�b�gOrg
OtherOrg= OtherOrg and �����R���x�AAOrg
OtherOrg= OtherOrg and �����R���x�ABOrg
OtherOrg= OtherOrg and �����R���x�ACOrg
OtherOrg= OtherOrg and �����R���x�AC2Org
OtherOrg= OtherOrg and �����R���x�ADOrg
OtherOrg= OtherOrg and �����R���x�AEOrg
'OtherOrg= OtherOrg and �����R���x�AF1Org
'OtherOrg= OtherOrg and �����R���x�AF2Org
OtherOrg= OtherOrg and �����R���x�AGOrg
OtherOrg= OtherOrg and �����R���x�AHOrg
if not(���֎~) then
	OtherOrg= OtherOrg and ���t�^���~���uAOrg
	OtherOrg= OtherOrg and �����]����Org
	OtherOrg= OtherOrg and ��򃆃j�b�gOrg
	'OtherOrg= OtherOrg and ���^���NOrg
	OtherOrg= OtherOrg and ���R���x�A����Org
	OtherOrg= OtherOrg and �����]�o��Org
	OtherOrg= OtherOrg and ���t�^���~���uBOrg
end if
OtherOrg= OtherOrg and IH���у��j�b�gAOrg
OtherOrg= OtherOrg and IH���у��j�b�gBOrg
'===================================================================================================================
OtherStep= �Z�Ѓ^���NA���j�b�gStep
OtherStep= OtherStep or �Z�Ѓ^���NB���j�b�gStep
OtherStep= OtherStep or �v�����j�b�gStep
OtherStep= OtherStep or �Ȃ炵���j�b�gStep
OtherStep= OtherStep or �W�킹���j�b�gStep
OtherStep= OtherStep or �W��胆�j�b�gStep
OtherStep= OtherStep or �ق����@A���j�b�gStep
OtherStep= OtherStep or �����R���x�AAStep
OtherStep= OtherStep or �����R���x�ABStep
OtherStep= OtherStep or �����R���x�ACStep
OtherStep= OtherStep or �����R���x�AC2Step
OtherStep= OtherStep or �����R���x�ADStep
OtherStep= OtherStep or �����R���x�AEStep
'OtherStep= OtherStep or �����R���x�AF1Step
'OtherStep= OtherStep or �����R���x�AF2Step
OtherStep= OtherStep or �����R���x�AGStep
OtherStep= OtherStep or �����R���x�AHStep
OtherStep= OtherStep or ���t�^���~���uAStep
OtherStep= OtherStep or �����]����Step
OtherStep= OtherStep or ��򃆃j�b�gStep
'OtherStep= OtherStep or ���^���NStep
OtherStep= OtherStep or ���R���x�A����Step
OtherStep= OtherStep or �����]�o��Step
OtherStep= OtherStep or ���t�^���~���uBStep
'OtherStep= OtherStep or IH���у��j�b�gAStep
'OtherStep= OtherStep or IH���у��j�b�gBStep
'===================================================================================================================
OtherOrgErrStep=�Z�Ѓ^���NA���j�b�gOrgErrStep
OtherOrgErrStep= ORA(OtherOrgErrStep,�Z�Ѓ^���NB���j�b�gOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�v�����j�b�gOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�Ȃ炵���j�b�gOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�W�킹���j�b�gOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�W��胆�j�b�gOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�ق����@A���j�b�gOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�����R���x�AAOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�����R���x�ABOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�����R���x�ACOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�����R���x�AC2OrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�����R���x�ADOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�����R���x�AEOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�����R���x�AF1OrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�����R���x�AF2OrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�����R���x�AGOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�����R���x�AHOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,���t�^���~���uAOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�����]����OrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,��򃆃j�b�gOrgErrStep)
'OtherOrgErrStep= ORA(OtherOrgErrStep,���^���NOrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,���R���x�A����OrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,�����]�o��OrgErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,���t�^���~���uBOrgErrStep)
'OtherOrgErrStep= ORA(OtherOrgErrStep,IH���у��j�b�gAOrgErrStep)
'OtherOrgErrStep= ORA(OtherOrgErrStep,IH���у��j�b�gBOrgErrStep)
'===================================================================================================================
OtherErrStep=�Z�Ѓ^���NA���j�b�gErrStep
OtherErrStep= ORA(OtherErrStep,�Z�Ѓ^���NB���j�b�gErrStep)
OtherErrStep= ORA(OtherErrStep,�v�����j�b�gErrStep)
OtherErrStep= ORA(OtherErrStep,�Ȃ炵���j�b�gErrStep)
OtherErrStep= ORA(OtherErrStep,�W�킹���j�b�gErrStep)
OtherErrStep= ORA(OtherErrStep,�W��胆�j�b�gErrStep)
OtherErrStep= ORA(OtherErrStep,�ق����@A���j�b�gErrStep)
OtherErrStep= ORA(OtherErrStep,�����R���x�AAErrStep)
OtherErrStep= ORA(OtherErrStep,�����R���x�ABErrStep)
OtherErrStep= ORA(OtherErrStep,�����R���x�ACErrStep)
OtherErrStep= ORA(OtherErrStep,�����R���x�AC2ErrStep)
OtherErrStep= ORA(OtherErrStep,�����R���x�ADErrStep)
OtherErrStep= ORA(OtherErrStep,�����R���x�AEErrStep)
OtherErrStep= ORA(OtherErrStep,�����R���x�AF1ErrStep)
OtherErrStep= ORA(OtherErrStep,�����R���x�AF2ErrStep)
OtherErrStep= ORA(OtherErrStep,�����R���x�AGErrStep)
OtherErrStep= ORA(OtherErrStep,�����R���x�AHErrStep)
OtherErrStep= ORA(OtherErrStep,���t�^���~���uAErrStep)
OtherErrStep= ORA(OtherErrStep,�����]����ErrStep)
OtherErrStep= ORA(OtherErrStep,��򃆃j�b�gErrStep)
'OtherErrStep= ORA(OtherErrStep,���^���NErrStep)
OtherErrStep= ORA(OtherErrStep,���R���x�A����ErrStep)
OtherErrStep= ORA(OtherErrStep,�����]�o��ErrStep)
OtherErrStep= ORA(OtherErrStep,���t�^���~���uBErrStep)
OtherErrStep= ORA(OtherErrStep,IH���у��j�b�gAErrStep)
OtherErrStep= ORA(OtherErrStep,IH���у��j�b�gBErrStep)
'===================================================================================================================
OtherEmgStep=�Z�Ѓ^���NA���j�b�gEmgStep
OtherEmgStep= ORA(OtherEmgStep,�Z�Ѓ^���NB���j�b�gEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�v�����j�b�gEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�Ȃ炵���j�b�gEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�W�킹���j�b�gEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�W��胆�j�b�gEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�ق����@A���j�b�gEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�����R���x�AAEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�����R���x�ABEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�����R���x�ACEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�����R���x�AC2EmgStep)
OtherEmgStep= ORA(OtherEmgStep,�����R���x�ADEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�����R���x�AEEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�����R���x�AF1EmgStep)
OtherEmgStep= ORA(OtherEmgStep,�����R���x�AF2EmgStep)
OtherEmgStep= ORA(OtherEmgStep,�����R���x�AGEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�����R���x�AHEmgStep)
OtherEmgStep= ORA(OtherEmgStep,���t�^���~���uAEmgStep)
OtherEmgStep= ORA(OtherEmgStep,�����]����EmgStep)
OtherEmgStep= ORA(OtherEmgStep,��򃆃j�b�gEmgStep)
'OtherEmgStep= ORA(OtherEmgStep,���^���NEmgStep)
OtherEmgStep= ORA(OtherEmgStep,���R���x�A����EmgStep)
OtherEmgStep= ORA(OtherEmgStep,�����]�o��EmgStep)
OtherEmgStep= ORA(OtherEmgStep,���t�^���~���uBEmgStep)
'OtherEmgStep= ORA(OtherEmgStep,IH���у��j�b�gAEmgStep)
'OtherEmgStep= ORA(OtherEmgStep,IH���у��j�b�gBEmgStep)
'==================================================================================================================
'�y  �f�o�C�X�ւ̋��d  �z


'	if �O�����H��AutoRun or �Z�Ѓ^���NA���j�b�gAutoRun or �Z�Ѓ^���NB���j�b�gAutoRun then
'		RLY5_�p�h���Z���T�d��=ON
'	else
'		RLY5_�p�h���Z���T�d��=OFF
'	end if

	mMC1_�C���o�[�^�p�d��=ON

	'RLY_�������d��OFF=ON

'===================================================================================================================
'�y ���������� �z
if CR2008 then

    ��������AutoMode=OFF
    ��������OrgErr=OFF
    ��������Err=OFF
    ��������Emg=OFF
    ��������step=0
    ��������ErrStep=0
    ��������OrgErrStep=0
    ��������EmgStep=0
	
	OtherEmgStep=0
	OtherErrStep=0
	OtherOrgErr=0
	
	���������蓮����step=0
	
end if

'===================================================================================================================
'�y �ً}��~ �z
if ��������Emg  then
	��������EmgStep=1
end if

'===================================================================================================================


'===================================================================================================================
'  �R�}���h����
'===================================================================================================================
' ���������R�}���h����
'
if ��������EmgStep=0 and OtherEmgStep=0 then  
	
	if ��������ErrStep=0  and OtherErrStep=0 then
	
		if not(��������OrgErr) and not(OtherOrgErr) then

			if not(PB23_������~) or not(PB35_��~) or not(PB37_��~)  or ����������~ or ������~ or ldp(�����҂���~) or pnlPB��~ then
			
				������~=OFF
			
				��������AutoRun=OFF

				�Z�Ѓ^���NAAutoRun=OFF
				�Z�Ѓ^���NBAutoRun=OFF
				�Z�Ѓ^���NA���j�b�gAutoRun=OFF
				�Z�Ѓ^���NB���j�b�gAutoRun=OFF
				�v�����j�b�gAutoRun=OFF
				�Ȃ炵���j�b�gAutoRun=OFF
				�W�킹���j�b�gAutoRun=OFF
				�W��胆�j�b�gAutoRun=OFF
				�ق����@A���j�b�gAutoRun=OFF
				�����R���x�AAAutoRun=OFF
				�����R���x�ABAutoRun=OFF
				�����R���x�ACAutoRun=OFF
				�����R���x�AC2AutoRun=OFF
				�����R���x�ADAutoRun=OFF
				�����R���x�AEAutoRun=OFF
				�����R���x�AF1AutoRun=OFF
				�����R���x�AF2AutoRun=OFF
				�����R���x�AGAutoRun=OFF
				�����R���x�AHAutoRun=OFF
				���t�^���~���uAAutoRun=OFF
				�����]����AutoRun=OFF
				��򃆃j�b�gAutoRun=OFF
				���^���NAutoRun=OFF
				���R���x�A����AutoRun=OFF
				�����]�o��AutoRun=OFF
				���t�^���~���uBAutoRun=OFF

			else
				'-------------------------------------------------------------------------------------
				'���C��              �ނ炵                  ���@
				'SSW3_�������[�h     SSW1_2_�^�]�؊��i�A���j SEL2_2_�^�]�؊��i�A���j
				'-------------------------------------------------------------------------------------
				' �������� ���� - �蓮  (2�X�e�b�v�؂�ւ��j
				'���C������{�b�N�X�� SSW3_�蓮���[�h  SSW3_�������[�h
				if 	not(���������蓮�ؑ֍ς�) and SSW3_�蓮���[�h and  not(SSW3_�������[�h) then
				
					select case ���������蓮����step
					case 0
						���������蓮�v��=ON
						inc(���������蓮����step)
					case 1
						if ���������蓮���� then

							��������AutoMode=OFF
				
							'�O�����H��AutoMode=OFF
							'�O�����H��AutoRun=OFF
							'�v��AutoRun=OFF
							
							'if �����^�]���[�h and (�v��step<>0 or ����step<>0) then
							'	�����^�]���[�hEndWait=ON
							'end if
							'�����^�]���[�h=OFF
							
							'if �\��^�]���[�h and (�v��step<>0 or ����step<>0) then
							'	�\��^�]���[�hEndWait=ON
							'end if
							'�\��^�]���[�h=OFF

							inc(���������蓮����step)
						else if ���������蓮�֎~ then
							��������AutoMode=ON
							inc(���������蓮����step)
						end if						
					case 2
						���������蓮�v��=OFF
						inc(���������蓮����step)
					case 3
						���������蓮�ؑ֍ς�=ON
						inc(���������蓮����step)
						'���������蓮����step=0
						
					end select
				
				else if SSW3_�������[�h and not(SSW3_�蓮���[�h) then
					���������蓮�ؑ֍ς�=OFF
					���������蓮����step=0
					���������蓮�v��=OFF
					��������AutoMode=ON
				end if
				'-------------------------------------------------------------------------------------
				' �N��
				if not(OtherOrg) then
					if ��������AutoMode and OtherStep=0 then
						if (ldp(PB22_�����^�]) or ldp(�����҂���~����) or ldp(pnlPB�N��)) and (�^�]������ or �^�]�������� or �e�X�g�^�]) then
						
							�Z�Ѓ^���NA���j�b�gOrgErr=not(�Z�Ѓ^���NA���j�b�gOrg)
							�Z�Ѓ^���NB���j�b�gOrgErr=not(�Z�Ѓ^���NB���j�b�gOrg)
							�v�����j�b�gOrgErr=not(�v�����j�b�gOrg)
							�Ȃ炵���j�b�gOrgErr=not(�Ȃ炵���j�b�gOrg)
							�W�킹���j�b�gOrgErr=not(�W�킹���j�b�gOrg)
							�W��胆�j�b�gOrgErr=not(�W��胆�j�b�gOrg)
							�ق����@A���j�b�gOrgErr=not(�ق����@A���j�b�gOrg)
							�����R���x�AAOrgErr=not(�����R���x�AAOrg)
							�����R���x�ABOrgErr=not(�����R���x�ABOrg)
							�����R���x�ACOrgErr=not(�����R���x�ACOrg)
							�����R���x�AC2OrgErr=not(�����R���x�AC2Org)
							�����R���x�ADOrgErr=not(�����R���x�ADOrg)
							�����R���x�AEOrgErr=not(�����R���x�AEOrg)
							�����R���x�AF1OrgErr=not(�����R���x�AF1Org)
							�����R���x�AF2OrgErr=not(�����R���x�AF2Org)
							�����R���x�AGOrgErr=not(�����R���x�AGOrg)
							�����R���x�AHOrgErr=not(�����R���x�AHOrg)
							���t�^���~���uAOrgErr=not(���t�^���~���uAOrg)
							�����]����OrgErr=not(�����]����Org)
							��򃆃j�b�gOrgErr=not(��򃆃j�b�gOrg)
							'���^���NOrgErr=not(���^���NOrg)
							���R���x�A����OrgErr=not(���R���x�A����Org)
							�����]�o��OrgErr=not(�����]�o��Org)
							���t�^���~���uBOrgErr=not(���t�^���~���uBOrg)
							IH���у��j�b�gAOrgErr=not(IH���у��j�b�gAOrg)
							IH���у��j�b�gBOrgErr=not(IH���у��j�b�gBOrg)
					
						end if
						
					end if
				
				else if ��������AutoMode and OtherStep=0 then
					if (ldp(PB22_�����^�]) or ldp(�����҂���~����) or ldp(pnlPB�N��))  and (�^�]������ or �^�]�������� or �e�X�g�^�] ) then

						��������AutoRun=ON

						'------------------------------------------------------
						�Z�Ѓ^���NAAutoRun=ON
						�Z�Ѓ^���NBAutoRun=ON
						�Z�Ѓ^���NA���j�b�gAutoRun=ON
						�Z�Ѓ^���NB���j�b�gAutoRun=ON
						�v�����j�b�gAutoRun=ON
						�Ȃ炵���j�b�gAutoRun=ON
						�W�킹���j�b�gAutoRun=ON
						�W��胆�j�b�gAutoRun=ON
						�ق����@A���j�b�gAutoRun=ON
						�����R���x�AAAutoRun=ON
						�����R���x�ABAutoRun=ON
						�����R���x�ACAutoRun=ON
						�����R���x�AC2AutoRun=ON
						�����R���x�ADAutoRun=ON
						�����R���x�AEAutoRun=ON
						�����R���x�AF1AutoRun=ON
						�����R���x�AF2AutoRun=ON
						�����R���x�AGAutoRun=ON
						�����R���x�AHAutoRun=ON
					if not(���֎~) then
						���t�^���~���uAAutoRun=ON
						�����]����AutoRun=ON
						��򃆃j�b�gAutoRun=ON
						���^���NAutoRun=ON
						���R���x�A����AutoRun=ON
						�����]�o��AutoRun=ON
						���t�^���~���uBAutoRun=ON
					end if
						'------------------------------------------------------
						�Z�Ѓ^���NA���j�b�gstep=1
						�Z�Ѓ^���NB���j�b�gstep=1
						�v�����j�b�gstep=1
						�Ȃ炵���j�b�gstep=1
						�W�킹���j�b�gstep=1
						�W��胆�j�b�gstep=1
						�ق����@A���j�b�gstep=1
						�����R���x�AAstep=1
						�����R���x�ABstep=1
						�����R���x�ACstep=1
						�����R���x�AC2step=1
						�����R���x�ADstep=1
						�����R���x�AEstep=1
						�����R���x�AF1step=1
						�����R���x�AF2step=1
						�����R���x�AGstep=1
						�����R���x�AHstep=1
					if not(���֎~) then
						���t�^���~���uAstep=1
						�����]����step=1
						��򃆃j�b�gstep=1
						���^���Nstep=1
						���R���x�A����step=1
						�����]�o��step=1
						���t�^���~���uBstep=1
					end if
						'------------------------------------------------------
						�����R���x�AA���쒆=OFF
						�����R���x�AB���쒆=OFF
						�����R���x�AC���쒆=OFF
						�����R���x�AC2���쒆=OFF
						�����R���x�AD���쒆=OFF
						�����R���x�AE���쒆=OFF
						�����R���x�AF1���쒆=OFF
						�����R���x�AF2���쒆=OFF
						�����R���x�AG���쒆=OFF
						�����R���x�AH���쒆=OFF
						���t�^���~���uA���쒆=OFF
						�����]�������쒆=OFF
						���R���x�A�������쒆=OFF
						�����]�o�����쒆=OFF
						���t�^���~���uB���쒆=OFF
						'------------------------------------------------------
						�����R���x�AA�r�o�v��=OFF
						�����R���x�AB�r�o�v��=OFF
						�����R���x�AC�r�o�v��=OFF
						�����R���x�AC2�r�o�v��=OFF
						�����R���x�AD�r�o�v��=OFF
						�����R���x�AE�r�o�v��=OFF
						�����R���x�AF1�r�o�v��=OFF
						�����R���x�AF2�r�o�v��=OFF
						�����R���x�AG�r�o�v��=OFF
						�����R���x�AH�r�o�v��=OFF
						���t�^���~���uA�r�o�v��=OFF
						�����]�����r�o�v��=OFF
						���R���x�A�����r�o�v��=OFF
						�����]�o���r�o�v��=OFF
						���t�^���~���uB�r�o�v��=OFF
						'------------------------------------------------------
					end if	
				end if				
				'-------------------------------------------------------------------------------------
				
			end if


	'==================================================================================================================
	'�y ���_�ُ� �z
	
	
		else

			'--------------------------------------------------------------------------------
			' �e���W���[���ւ�ResetFlg�w��
			��������AutoRun=OFF


			�Z�Ѓ^���NAAutoRun=OFF
			�Z�Ѓ^���NBAutoRun=OFF
			�Z�Ѓ^���NA���j�b�gAutoRun=OFF
			�Z�Ѓ^���NB���j�b�gAutoRun=OFF
			�v�����j�b�gAutoRun=OFF
			�Ȃ炵���j�b�gAutoRun=OFF
			�W�킹���j�b�gAutoRun=OFF
			�W��胆�j�b�gAutoRun=OFF
			�ق����@A���j�b�gAutoRun=OFF
			�����R���x�AAAutoRun=OFF
			�����R���x�ABAutoRun=OFF
			�����R���x�ACAutoRun=OFF
			�����R���x�AC2AutoRun=OFF
			�����R���x�ADAutoRun=OFF
			�����R���x�AEAutoRun=OFF
			�����R���x�AF1AutoRun=OFF
			�����R���x�AF2AutoRun=OFF
			�����R���x�AGAutoRun=OFF
			�����R���x�AHAutoRun=OFF
			���t�^���~���uAAutoRun=OFF
			�����]����AutoRun=OFF
			��򃆃j�b�gAutoRun=OFF
			���^���NAutoRun=OFF
			���R���x�A����AutoRun=OFF
			�����]�o��AutoRun=OFF
			���t�^���~���uBAutoRun=OFF

			if ResetFlg then

				�Z�Ѓ^���NA���j�b�gOrgErr=not(�Z�Ѓ^���NA���j�b�gOrg)
				�Z�Ѓ^���NB���j�b�gOrgErr=not(�Z�Ѓ^���NB���j�b�gOrg)
				�v�����j�b�gOrgErr=not(�v�����j�b�gOrg)
				�Ȃ炵���j�b�gOrgErr=not(�Ȃ炵���j�b�gOrg)
				�W�킹���j�b�gOrgErr=not(�W�킹���j�b�gOrg)
				�W��胆�j�b�gOrgErr=not(�W��胆�j�b�gOrg)
				�ق����@A���j�b�gOrgErr=not(�ق����@A���j�b�gOrg)
				�����R���x�AAOrgErr=not(�����R���x�AAOrg)
				�����R���x�ABOrgErr=not(�����R���x�ABOrg)
				�����R���x�ACOrgErr=not(�����R���x�ACOrg)
				�����R���x�AC2OrgErr=not(�����R���x�AC2Org)
				�����R���x�ADOrgErr=not(�����R���x�ADOrg)
				�����R���x�AEOrgErr=not(�����R���x�AEOrg)
				�����R���x�AF1OrgErr=not(�����R���x�AF1Org)
				�����R���x�AF2OrgErr=not(�����R���x�AF2Org)
				�����R���x�AGOrgErr=not(�����R���x�AGOrg)
				�����R���x�AHOrgErr=not(�����R���x�AHOrg)
				���t�^���~���uAOrgErr=not(���t�^���~���uAOrg)
				�����]����OrgErr=not(�����]����Org)
				��򃆃j�b�gOrgErr=not(��򃆃j�b�gOrg)
				'���^���NOrgErr=not(���^���NOrg)
				���R���x�A����OrgErr=not(���R���x�A����Org)
				�����]�o��OrgErr=not(�����]�o��Org)
				���t�^���~���uBOrgErr=not(���t�^���~���uBOrg)
				IH���у��j�b�gAOrgErr=not(IH���у��j�b�gAOrg)
				IH���у��j�b�gBOrgErr=not(IH���у��j�b�gBOrg)
			end if
		
		end if
	'==================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
					
			�Z�Ѓ^���NA���j�b�gOrgErr=OFF
			�Z�Ѓ^���NB���j�b�gOrgErr=OFF
			�v�����j�b�gOrgErr=OFF
			�Ȃ炵���j�b�gOrgErr=OFF
			�W�킹���j�b�gOrgErr=OFF
			�W��胆�j�b�gOrgErr=OFF
			�ق����@A���j�b�gOrgErr=OFF
			�����R���x�AAOrgErr=OFF
			�����R���x�ABOrgErr=OFF
			�����R���x�ACOrgErr=OFF
			�����R���x�AC2OrgErr=OFF
			�����R���x�ADOrgErr=OFF
			�����R���x�AEOrgErr=OFF
			�����R���x�AF1OrgErr=OFF
			�����R���x�AF2OrgErr=OFF
			�����R���x�AGOrgErr=OFF
			�����R���x�AHOrgErr=OFF
			���t�^���~���uAOrgErr=OFF
			�����]����OrgErr=OFF
			��򃆃j�b�gOrgErr=OFF
			'���^���NOrgErr=OFF
			���R���x�A����OrgErr=OFF
			�����]�o��OrgErr=OFF
			���t�^���~���uBOrgErr=OFF
			'IH���у��j�b�gAOrgErr=OFF
			'IH���у��j�b�gBOrgErr=OFF
	
	
			��������AutoRun=OFF

			�Z�Ѓ^���NAAutoRun=OFF
			�Z�Ѓ^���NBAutoRun=OFF
			�Z�Ѓ^���NA���j�b�gAutoRun=OFF
			�Z�Ѓ^���NB���j�b�gAutoRun=OFF
			�v�����j�b�gAutoRun=OFF
			�Ȃ炵���j�b�gAutoRun=OFF
			�W�킹���j�b�gAutoRun=OFF
			�W��胆�j�b�gAutoRun=OFF
			�ق����@A���j�b�gAutoRun=OFF
			�����R���x�AAAutoRun=OFF
			�����R���x�ABAutoRun=OFF
			�����R���x�ACAutoRun=OFF
			�����R���x�AC2AutoRun=OFF
			�����R���x�ADAutoRun=OFF
			�����R���x�AEAutoRun=OFF
			�����R���x�AF1AutoRun=OFF
			�����R���x�AF2AutoRun=OFF
			�����R���x�AGAutoRun=OFF
			�����R���x�AHAutoRun=OFF
			���t�^���~���uAAutoRun=OFF
			�����]����AutoRun=OFF
			��򃆃j�b�gAutoRun=OFF
			���^���NAutoRun=OFF
			���R���x�A����AutoRun=OFF
			�����]�o��AutoRun=OFF
			���t�^���~���uBAutoRun=OFF

		select case ��������ErrStep
		case 0
		
		case 1
			�p�g���C�g��=ON

			if PB34_���Z�b�g or PB24_���Z�b�g or PB38_���Z�b�g then
				
				�p�g���C�g��=OFF

				almDCPLC�d���d���~��=OFF
				almDC�d���d���~��1=OFF
				almDC�d���d���~��2=OFF
				almRLY_�d���m�F�[�Č�=OFF
				almRLY_�Z�Гd���m�F=OFF
				almRLY_����1�d���m�F=OFF
				almRLY_����2�d���m�F=OFF
				almRLY_F1A�d���m�F=OFF
				almRLY_F1B�d���m�F=OFF
				almRLY_F2A�d���m�F=OFF
				almRLY_F2B�d���m�F=OFF
				almRLY_���@�d���m�F=OFF
				almRLY_���]�@�d���m�F=OFF
				almRLY_�T�u1�d���m�F=OFF
				almRLY_�T�u2�d���m�F=OFF
				almPS1_�G�A�[����=OFF
				almPS2_�G�A�[����=OFF
				almPS3_�G�A�[����=OFF
				almPS4_�G�A�[����=OFF
				almPS5_�G�A�[����=OFF				
				almTHR4_���ă|���v=OFF
				almTHR5_���ĉH��=OFF
				almTHR1_�����p���~�@���[�^=OFF
				almTHR2_�r�o�p���~�@���[�^=OFF
				almTHR3_�v�ʋ@���[�^=OFF
				almTHR11_�������[�^=OFF
				almTHR6_�������[�^=OFF
				almTHR7_�������[�^=OFF
				almTHR8_�������[�^=OFF
				almTHR40_�Ȃ炵���[�^=OFF
				almTHR9_���[�^���[��=OFF
				almTHR12_�������[�^=OFF
				almTHR13_�������[�^=OFF
				almTHR16_���[�^���[��=OFF
				almTHR14_�������[�^=OFF
				almTHR15_�������[�^=OFF
				almTHR34_���[�^���[��=OFF
				almTHR44_���[�^���[��=OFF
				almTHR46_���[�^���[��=OFF
				almTHR45_�������[�^=OFF
				almTHR17_���[�^���[��=OFF
				almTHR18_���[�^���[��=OFF
				almTHR19_���[�^���[��=OFF
				almTHR20_���[�^���[��=OFF
				almTHR21_���[�^���[��=OFF
				almTHR22_���[�^���[��=OFF
				almTHR23_���[�^���[��=OFF
				almTHR24_���[�^���[��=OFF
				almTHR25_���[�^���[��=OFF
				almTHR26_���[�^���[��=OFF
				almTHR27_���[�^���[��=OFF
				almTHR28_���[�^���[��=OFF
				almTHR29_���[�^���[��=OFF
				almTHR30_���[�^���[��=OFF
				almTHR31_���[�^���[��=OFF
				almTHR32_���[�^���[��=OFF
				almTHR33_���[�^���[��=OFF
				almTHR47_���[�^���[��=OFF
				almTHR48_���[�^���[��=OFF
				almTHR49_���[�^���[��=OFF
				almTHR50_���[�^���[��=OFF
				almTHR51_���[�^���[��=OFF
				almTHR52_���[�^���[��=OFF
				almTHR53_���[�^���[��=OFF
				almTHR41_���[�^���[��=OFF
				almTHR42_���[�^���[��=OFF
				almTHR43_�������[�^=OFF
				almTHR54_���[�^���[��=OFF
				almTHR10_�������[�^=OFF
				almTHR55_�������[�^=OFF
				almTHR57_�������[�^=OFF
				almTHR56_�u���V�T�[�}��=OFF
				almTHR58_���|���vA=OFF
				almTHR59_���|���vB=OFF
				almTHR60_���|���vC=OFF
				almTHR61_���|���vD=OFF
				almINV1_�R���x�A�ُ�=OFF
				almINV2_�R���x�A�ُ�=OFF
				almINV3_�R���x�A�ُ�=OFF
				almDCPLC�d���d���~��=OFF
				
				�C���o�[�^1���Z�b�g=ON
				�C���o�[�^2���Z�b�g=ON
				�C���o�[�^3���Z�b�g=ON

				IH���у��j�b�gAOrgErr=OFF
				IH���у��j�b�gBOrgErr=OFF

				inc(��������ErrStep)

			end if

		case 2
			if OtherErrStep=0 then
				��������ErrStep=0
			end if
			
		end select

	end if
	
	'==================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	
	
	select case ��������EmgStep
	case 0
	case 1
		'����~����
		PBL����~=CR2006
		PBL22_�����^�]=OFF

		inc(��������EmgStep)
	case 2
		PBL����~=CR2006

		if PB34_���Z�b�g or PB24_���Z�b�g or PB38_���Z�b�g then
			PBL����~=OFF
			inc(��������EmgStep)
		end if

	case 3
		PBL����~=OFF
		PBL22_�����^�]=CR2006
		if ldp(PB22_�����^�]) then
			StartFlg=ON
			��������AutoRun=OFF
			inc(��������EmgStep)
		end if		

	case 4
		PBL22_�����^�]=OFF
		EmgFlg=OFF	
		inc(��������EmgStep)
		
	case 5	
		if �O�����H��EmgStep=0 and  OtherEmgStep=0 and not(PB22_�����^�]) then
			StartFlg=OFF
			��������ErrStep=0
			��������EmgStep=0
		end if
		
	end select
		
end if

