'�p�l���C���^�[�t�F�[�X
'===================================================================================================================
'
'<<<<<<<	�p�l���C���^�[�t�F�[�X��	>>>>>>>>
'
'===================================================================================================================
�q��R�[�h=���k��

'----------------------------------------------------------------------------------
'<IOMAP.XLS / �p�l���C���^�[�t�F�[�X> 
'----------------------------------
'�y�O���[�o�����x���z
'pnlPBel����	�r�b�g	MR00100
'pnlPBel��	�r�b�g	MR00101
'pnlPBel�T	�r�b�g	MR00102
'pnlPBel��	�r�b�g	MR00103
'pnlPBel���ړ�	�r�b�g	MR00104
'pnlPBel�E�ړ�	�r�b�g	MR00105
'pnlPBel���ړ�	�r�b�g	MR00106
'pnlPBel�����ړ�	�r�b�g	MR00107
'pnlPBel��ړ�	�r�b�g	MR00108
'pnlPBel����ړ�	�r�b�g	MR00109
'pnlPBel�X�V	�r�b�g	MR00110
'pnlPBelALL	�r�b�g	MR00111
'pnlPBel�^�]��	�r�b�g	MR00112
'pnlPBel�������[�h	�r�b�g	MR00113
'pnlPBel�e�X�g�^�]	�r�b�g	MR00114
'pnlPBel����~	�r�b�g	MR00115
'pnlPBel�O�����^�]��	�r�b�g	MR00200
'init����	�r�b�g	MR00201
'init��	�r�b�g	MR00202
'init�T	�r�b�g	MR00203
'init��	�r�b�g	MR00204
'		
'Filewritestep	1���[�h�����Ȃ�����	DM1000
'Filereadstep	1���[�h�����Ȃ�����	DM1001
'ErrAnalyzestep	1���[�h�����Ȃ�����	DM1002
'ErrAnalyzeStatcheckBit	1���[�h�����Ȃ�����	DM1003
'ErrAnlyzeTotalCnt	1���[�h�����Ȃ�����	DM1004
'dspErrAnalOffset	1���[�h�����Ȃ�����	DM1005
'el���݃y�[�WNO	1���[�h�����Ȃ�����	DM1006
'dspErrAnalIndex	1���[�h�����Ȃ�����	DM1007
'wFilewritestep	1���[�h�����Ȃ�����	DM1008
'		
'setFindStart�N����	1���[�h�����Ȃ�����[6]	DM1010
'setFindEnd�N����	1���[�h�����Ȃ�����[6]	DM1020
'FindStart�N����	1���[�h�����Ȃ�����[6]	DM1030
'FindEnd�N����	1���[�h�����Ȃ�����[6]	DM1040 
'ErrAnalyzeCode	1���[�h�����Ȃ�����[50]	DM1100
'ErrAnalyzePersent	1���[�h�����Ȃ�����[50]	DM1150
'ErrAnalyzeCnt	1���[�h�����Ȃ�����[50]	DM1200
'----------------------------------------------------------------------------------
'�y���[�J�����x���z
'FindEndSec	2���[�h�����Ȃ�����
'FindStartSec	2���[�h�����Ȃ�����
'Find�N����	1���[�h�����Ȃ�����[6]
'dsp�X�V	�r�b�g
'todaySec	2���[�h�����Ȃ�����
'-----------------------------------------------------------------------------------------------------------------------------
'�y�[�W�ړ�
	el���݃y�[�WNO=dspErrAnalIndex+1
	dspErrAnalOffset=dspErrAnalIndex*10

	if ldp(pnlPBel�����ړ�) then
		dspErrAnalIndex=4
	
	else if ldp(pnlPBel���ړ�) then
		
		if dspErrAnalIndex>=4 then
			dspErrAnalIndex=4
		else
			dspErrAnalIndex=dspErrAnalIndex+1
		end if
		
	else if ldp(pnlPBel����ړ�) then
		dspErrAnalIndex=0
	
	else if ldp(pnlPBel��ړ�) then
		if dspErrAnalIndex>0 then
			dspErrAnalIndex=dspErrAnalIndex-1
		else
			dspErrAnalIndex=0
		end if
	end if

'----------------------------------------------------------------------------------
if ldp(pnlPBel�X�V) or dsp�X�V then
	FindStart�N����[0]=setFindStart�N����[0]
	FindStart�N����[1]=setFindStart�N����[1]
	FindStart�N����[2]=setFindStart�N����[2]
	setFindStart�N����[3]=0
	setFindStart�N����[4]=0
	setFindStart�N����[5]=0
	setFindEnd�N����[3]=23
	setFindEnd�N����[4]=59
	setFindEnd�N����[5]=0

	FindEnd�N����[0]=setFindEnd�N����[0]
	FindEnd�N����[1]=setFindEnd�N����[1]
	FindEnd�N����[2]=setFindEnd�N����[2]
	FindStart�N����[3]=0
	FindStart�N����[4]=0
	FindStart�N����[5]=0
	FindEnd�N����[3]=23
	FindEnd�N����[4]=59
	FindEnd�N����[5]=0
	
	Filereadstep=1
	dspErrAnalIndex=0
	dsp�X�V=OFF
	
end if

'----------------------------------------------------------------------------------
if ldp(pnlPBel����) then
	pnlPBel����=ON
	pnlPBel��=OFF
	pnlPBel�T=OFF
	pnlPBel��=OFF
	init����=ON	
else if ldp(pnlPBel��) then
	pnlPBel����=OFF
	pnlPBel��=ON
	pnlPBel�T=OFF
	pnlPBel��=OFF
	init��=ON
else if ldp(pnlPBel�T) then
	pnlPBel����=OFF
	pnlPBel��=OFF
	pnlPBel�T=ON
	pnlPBel��=OFF
	init�T=ON
else if ldp(pnlPBel��) then
	pnlPBel����=OFF
	pnlPBel��=OFF
	pnlPBel�T=OFF
	pnlPBel��=ON
	init��=ON
end if
'----------------------------------------------------------------------------------
if 	pnlPBel���� then
	if init���� then
		init����=OFF	
	
		setFindStart�N����[0]=CM700
		setFindStart�N����[1]=CM701
		setFindStart�N����[2]=CM702
		setFindEnd�N����[0]=CM700
		setFindEnd�N����[1]=CM701
		setFindEnd�N����[2]=CM702
	
		dspErrAnalIndex=0
		dsp�X�V=ON
	else if CM700<>FindStart�N����[0] or CM701<>FindStart�N����[1] or  CM702<>FindStart�N����[2] then
		
		setFindStart�N����[0]=CM700
		setFindStart�N����[1]=CM701
		setFindStart�N����[2]=CM702
		setFindEnd�N����[0]=CM700
		setFindEnd�N����[1]=CM701
		setFindEnd�N����[2]=CM702
		
		dsp�X�V=ON
	
	end if

	

else if pnlPBel�� then
	if init�� then
		init��=OFF
		
		setFindStart�N����[0]=CM700
		setFindStart�N����[1]=CM701
		setFindStart�N����[2]=CM702
		setFindEnd�N����[0]=CM700
		setFindEnd�N����[1]=CM701
		setFindEnd�N����[2]=CM702

		dspErrAnalIndex=0
		dsp�X�V=ON
	else if setFindStart�N����[0]<>FindStart�N����[0] or setFindStart�N����[1]<>FindStart�N����[1] or  setFindStart�N����[2]<>FindStart�N����[2] then

		todaySec=SEC(CM700)

		FindStartSec=SEC(setFindStart�N����)
		if FindStartSec>=todaySec then
			setFindStart�N����[0]=CM700
			setFindStart�N����[1]=CM701
			setFindStart�N����[2]=CM702
			setFindEnd�N����[0]=CM700
			setFindEnd�N����[1]=CM701
			setFindEnd�N����[2]=CM702			
		else
			RSEC(FindStartSec,setFindStart�N����)
			RSEC(FindStartSec,setFindEnd�N����)			
		end if
		
		dsp�X�V=ON

	end if

	if ldp(pnlPBel���ړ�) then
		FindStartSec=SEC(setFindStart�N����)-86400
		RSEC(FindStartSec,setFindStart�N����)
		RSEC(FindStartSec,setFindEnd�N����)			
		
		dsp�X�V=ON

	else if ldp(pnlPBel�E�ړ�) then
	
		Find�N����[0]=CM700
		Find�N����[1]=CM701
		Find�N����[2]=CM702
		Find�N����[3]=0
		Find�N����[4]=0
		Find�N����[5]=0
		
		todaySec=SEC(Find�N����)
		
		FindStartSec=SEC(setFindStart�N����)
		if FindStartSec>=todaySec then
			setFindStart�N����[0]=CM700
			setFindStart�N����[1]=CM701
			setFindStart�N����[2]=CM702
			setFindEnd�N����[0]=CM700
			setFindEnd�N����[1]=CM701
			setFindEnd�N����[2]=CM702			
		else
			FindStartSec=SEC(setFindStart�N����)+86400
			RSEC(FindStartSec,setFindStart�N����)
			RSEC(FindStartSec,setFindEnd�N����)			
		end if

		dsp�X�V=ON
	
	end if
	

else if pnlPBel�T then
	if init�T then
		init�T=OFF

		FindStartSec=SEC(CM700)-518400
		RSEC(FindStartSec,setFindStart�N����)
		setFindEnd�N����[0]=CM700
		setFindEnd�N����[1]=CM701
		setFindEnd�N����[2]=CM702

		dspErrAnalIndex=0
		dsp�X�V=ON
	else if setFindStart�N����[0]<>FindStart�N����[0] or setFindStart�N����[1]<>FindStart�N����[1] or  setFindStart�N����[2]<>FindStart�N����[2] then

		todaySec=SEC(CM700)

		FindStartSec=SEC(setFindStart�N����)
		if FindStartSec>=todaySec then
			setFindStart�N����[0]=CM700
			setFindStart�N����[1]=CM701
			setFindStart�N����[2]=CM702
		else
			RSEC(FindStartSec,setFindStart�N����)	
		end if
		FindEndSec=SEC(setFindEnd�N����)+518400-1 '1�T��
		if FindEndSec>=todaySec then
			setFindEnd�N����[0]=CM700
			setFindEnd�N����[1]=CM701
			setFindEnd�N����[2]=CM702
		else
			RSEC(FindEndSec,setFindEnd�N����)
		end if
		
		dsp�X�V=ON
		
	end if
	
	if ldp(pnlPBel���ړ�) then
		todaySec=SEC(CM700)

		FindStartSec=SEC(setFindStart�N����)-518400
		if FindStartSec>=todaySec then
			setFindStart�N����[0]=CM700
			setFindStart�N����[1]=CM701
			setFindStart�N����[2]=CM702
		else
			RSEC(FindStartSec,setFindStart�N����)		
		end if
		
		FindEndSec=SEC(setFindStart�N����)+518400-1 '1�T��
		if FindEndSec>=todaySec then
			setFindEnd�N����[0]=CM700
			setFindEnd�N����[1]=CM701
			setFindEnd�N����[2]=CM702
		else
			RSEC(FindEndSec,setFindEnd�N����)
		end if
		
		dsp�X�V=ON

	
	else if ldp(pnlPBel�E�ړ�) then
		todaySec=SEC(CM700)

		FindStartSec=SEC(setFindStart�N����)+518400
		if FindStartSec>=todaySec then
			setFindStart�N����[0]=CM700
			setFindStart�N����[1]=CM701
			setFindStart�N����[2]=CM702
		else
			RSEC(FindStartSec,setFindStart�N����)
		end if
		FindEndSec=SEC(setFindStart�N����)+518400-1 '1�T��
		if FindEndSec>=todaySec then
			setFindEnd�N����[0]=CM700
			setFindEnd�N����[1]=CM701
			setFindEnd�N����[2]=CM702
		else
			RSEC(FindEndSec,setFindEnd�N����)
		end if
		
		dsp�X�V=ON


	end if

else if	pnlPBel�� then
	setFindEnd�N����[0]=CM700
	setFindEnd�N����[1]=CM701
	setFindEnd�N����[2]=CM702

	if init�� then
		init��=OFF

		Find�N����[0]=CM700
		Find�N����[1]=CM701
		Find�N����[2]=1
		Find�N����[3]=0
		Find�N����[4]=0
		Find�N����[5]=0
		FindStartSec=SEC(Find�N����)
		RSEC(FindStartSec,setFindStart�N����)
		setFindEnd�N����[0]=CM700
		setFindEnd�N����[1]=CM701
		setFindEnd�N����[2]=CM702

		dspErrAnalIndex=0
		dsp�X�V=ON

	else if setFindStart�N����[0]<>FindStart�N����[0] or setFindStart�N����[1]<>FindStart�N����[1] or  setFindStart�N����[2]<>FindStart�N����[2] then

		Find�N����[0]=CM700
		Find�N����[1]=CM701
		Find�N����[2]=1
		Find�N����[3]=0
		Find�N����[4]=0
		Find�N����[5]=0
		todaySec=SEC(Find�N����)
		
		setFindStart�N����[2]=1 '�����I��1���ɂ���
		
		FindStartSec=SEC(setFindStart�N����)
		if FindStartSec>=todaySec then
			setFindStart�N����[0]=CM700
			setFindStart�N����[1]=CM701
			setFindStart�N����[2]=1
		else
			RSEC(FindStartSec,setFindStart�N����)
		end if
		dsp�X�V=ON
		
	end if
	
	if ldp(pnlPBel���ړ�) then
		Find�N����[0]=CM700
		Find�N����[1]=CM701
		Find�N����[2]=1
		Find�N����[3]=0
		Find�N����[4]=0
		Find�N����[5]=0
		todaySec=SEC(Find�N����)

		setFindStart�N����[2]=1 '�����I��1���ɂ���
		
		if setFindStart�N����[1]>=2 and setFindStart�N����[1]<=12 then
			setFindStart�N����[1]=setFindStart�N����[1]-1
		else if setFindStart�N����[1]=1 then
			setFindStart�N����[0]=setFindStart�N����[0]-1
			setFindStart�N����[1]=12
		end if
		
		FindStartSec=SEC(setFindStart�N����)
		if FindStartSec>=todaySec then
			setFindStart�N����[0]=CM700
			setFindStart�N����[1]=CM701
			setFindStart�N����[2]=1
		else
			RSEC(FindStartSec,setFindStart�N����)		
		end if
		
		dsp�X�V=ON

	
	else if ldp(pnlPBel�E�ړ�) then
		Find�N����[0]=CM700
		Find�N����[1]=CM701
		Find�N����[2]=1
		Find�N����[3]=0
		Find�N����[4]=0
		Find�N����[5]=0
		todaySec=SEC(Find�N����)

		setFindStart�N����[2]=1 '�����I��1���ɂ���
		
		if setFindStart�N����[1]>=1 and setFindStart�N����[1]<12 then
			setFindStart�N����[1]=setFindStart�N����[1]+1
		else if setFindStart�N����[1]=12 then
			setFindStart�N����[0]=setFindStart�N����[0]+1
			setFindStart�N����[1]=1
		end if

		FindStartSec=SEC(setFindStart�N����)
		if FindStartSec>=todaySec then
			setFindStart�N����[0]=CM700
			setFindStart�N����[1]=CM701
			setFindStart�N����[2]=1
		else
			RSEC(FindStartSec,setFindStart�N����)
		end if

		dsp�X�V=ON


	end if

end if

'----------------------------------------------------------------------------------

' �ؑփy�[�W
if CR2008 then '�d��ON������������
	
	���C��TP_�ؑփy�[�W�m��=�X�^�[�g�A�b�v���
	�T�uTP_�ؑփy�[�W�m��=�X�^�[�g�A�b�v���
	�ނ炵TP_�ؑփy�[�W�m��=�X�^�[�g�A�b�v���
	
	
	MainStatusMsg=0
	�O�����H��StatusMsg=0
	��������StatusMsg=0
	�v��StatusMsg=0
	����StatusMsg=0
	�Z�Ѓ^���NAStatusMsg=0
	�Z�Ѓ^���NBStatusMsg=0
	�Z�Ѓ^���NA���j�b�gStatusMsg=0
	�Z�Ѓ^���NB���j�b�gStatusMsg=0
	�v�����j�b�gStatusMsg=0
	�Ȃ炵���j�b�gStatusMsg=0
	�W�킹���j�b�gStatusMsg=0
	�W��胆�j�b�gStatusMsg=0
'	���͂񌟒mStatusMsg=0
'	�o�L���[�����j�b�gStatusMsg=0
	�ق����@A���j�b�gStatusMsg=0
'	�ق����@B���j�b�gStatusMsg=0
	�����R���x�AAStatusMsg=0
	�����R���x�ABStatusMsg=0
	�����R���x�ACStatusMsg=0
	�����R���x�AC2StatusMsg=0
	�����R���x�ADStatusMsg=0
	�����R���x�AEStatusMsg=0
	�����R���x�AF1StatusMsg=0
	�����R���x�AF2StatusMsg=0
	�����R���x�AGStatusMsg=0
	�����R���x�AHStatusMsg=0
	���t�^���~���uAStatusMsg=0
	�����]����StatusMsg=0
	��򃆃j�b�gStatusMsg=0
	���^���NStatusMsg=0
	���R���x�A����StatusMsg=0
	�����]�o��StatusMsg=0
	���t�^���~���uBStatusMsg=0	

else

	'--------------------------------------------------------------------------------	
	'�ُ헚�����
	if ldp(��������ErrStep<>0) then
		���C��TP_�ؑփy�[�W�m��=�ُ헚�����
		�T�uTP_�ؑփy�[�W�m��=�ُ헚�����
	end if
	'--------------------------------------------------------------------------------	
	'�\����e�m�F���
	�O�����ݒ芮��=ON
	if �\��m�F then
			if DM_A�^���N�ݒ�l<>0 or DM_B�^���N�ݒ�l<>0 then
				�O�����ݒ芮��=ON
				���C��TP_�ؑփy�[�W�m��=12 '�\����e�m�F���
			else
				�O�����ݒ芮��=OFF		
			end if
	'--------------------------------------------------------------------------------	
	'�z�[�����
	else if (�����^�]���[�h or �\��^�]���[�h) and PB21_�O������~ then
			���C��TP_�ؑփy�[�W�m��=1 '�z�[�����

	'--------------------------------------------------------------------------------	
	end if

end if



'--------------------------------------------------------------------------------	
'----------------------------------------------------------------------------------
' �^�b�`�p�l���ɓo�^���ꂽ���b�Z�[�W�ԍ�����������
' xxxxStatusMsg=�i���b�Z�[�W�ԍ��j
'
'----------------------------------------------------------------------------------
'	���b�Z�[�W�R�[�h			
'		#0	'	���b�Z�[�W�Ȃ�
'----------------------------------------------------------------------------------
'	�V�[�P���V�����^�]���
'	MainStatusMsg=0
'		MainStatusMsg=#100 '���@�^���N������
'		MainStatusMsg=#102 '���@�^���N���M��
'		MainStatusMsg=#103 '���@�^���N�������A���M��
'		MainStatusMsg=#101 '���@�^���N��������
'		MainStatusMsg=#110 '���щ^�]�X�C�b�`�������Ă��������B�����R���x�A�����삵�܂��B�����ӂ��������B
'		MainStatusMsg=#111 '���ы@���Ίm�F
'		MainStatusMsg=#112 '�z�Ă̏������������܂����B
'		MainStatusMsg=#113 '�����^�]��
'		MainStatusMsg=#120 '��~������
'		MainStatusMsg=#121 '��~�������B���ы@���Ή\�ł��B
'----------------------------------------------------------------------------------
'	�O�����H��			
'	�O�����H��StatusMsg=0
'		�O�����H��StatusMsg=#20	'	�O������
'		�O�����H��StatusMsg=#21	'	�Z�В�
'		�O�����H��StatusMsg=#22	'	�����^�]��
'		�O�����H��StatusMsg=#23	'	��~������
'		�O�����H��StatusMsg=#24	'	��~��
'----------------------------------------------------------------------------------
'	�Z�Ѓ^���N		'	
'	�Z�Ѓ^���NA���j�b�gStatusMsg=0
'		�Z�Ѓ^���NA���j�b�gStatusMsg=#10	'	������
'		�Z�Ѓ^���NA���j�b�gStatusMsg=#11	'	���Ē�
'		�Z�Ѓ^���NA���j�b�gStatusMsg=#12	'	�Z�В�
'		�Z�Ѓ^���NA���j�b�gStatusMsg=#13	'	�z�Ē�
'		�Z�Ѓ^���NA���j�b�gStatusMsg=#14	'	�z�Ċ���
'	�Z�Ѓ^���NB���j�b�gStatusMsg=0
'		�Z�Ѓ^���NB���j�b�gStatusMsg=#10	'	������
'		�Z�Ѓ^���NB���j�b�gStatusMsg=#11	'	���Ē�
'		�Z�Ѓ^���NB���j�b�gStatusMsg=#12	'	�Z�В�
'		�Z�Ѓ^���NB���j�b�gStatusMsg=#13	'	�z�Ē�
'		�Z�Ѓ^���NB���j�b�gStatusMsg=#14	'	�z�Ċ���
'----------------------------------------------------------------------------------
'	�Ȃ炵�@		'
'	�Ȃ炵���uStatusMsg=0
'		�Ȃ炵���uStatusMsg=#30	'	�ҋ@��
'		�Ȃ炵���uStatusMsg=#31	'	�Ȃ炵��
'----------------------------------------------------------------------------------
'	�t�^�킹
'	�W�킹���j�b�gStatusMsg=0
'		�W�킹���j�b�gStatusMsg=#40	'	�t�^��蒆
'		�W�킹���j�b�gStatusMsg=#41	'	�t�^�킹�ҋ@���i�t�^�������Ă����ԁj
'		�W�킹���j�b�gStatusMsg=#42	'	�t�^�u����
'		�W�킹���j�b�gStatusMsg=#43	'	�ҋ@���i�t�^�������Ă��Ȃ��j
'----------------------------------------------------------------------------------
'	�t�^���
'	�W��胆�j�b�gStatusMsg=0
'		�W��胆�j�b�gStatusMsg=#45	'	�ҋ@��
'		�W��胆�j�b�gStatusMsg=#46	'	�t�^��蒆
'		�W��胆�j�b�gStatusMsg=#47	'	�t�^�u����
'----------------------------------------------------------------------------------
'	���ъ��m�F���u
'	���͂񌟒mStatusMsg=0
'		���͂񌟒mStatusMsg=#50	'	�ҋ@��
'		���͂񌟒mStatusMsg=#51	'	�m�F��
'		���͂񌟒mStatusMsg=#56	'	����
'		���͂񌟒mStatusMsg=#57	'	�Ĕъ�
'----------------------------------------------------------------------------------
'	�����o�L���[�}
'	�o�L���[�����j�b�gStatusMsg=0
'		�o�L���[�����j�b�gStatusMsg=#60	'	�ҋ@��
'		�o�L���[�����j�b�gStatusMsg=#61	'	�z����
'----------------------------------------------------------------------------------
'	�����@
'	��򃆃j�b�gStatusMsg=0
'		��򃆃j�b�gStatusMsg=#70	'	�ҋ@��
'		��򃆃j�b�gStatusMsg=#71	'	������
'		��򃆃j�b�gStatusMsg=#72	'	�^�]��
'----------------------------------------------------------------------------------

System�ύX�ʒm=��򃆃j�b�g1�֎~ or ��򃆃j�b�g2�֎~ or ��򃆃j�b�g3�֎~ or ��򃆃j�b�g4�֎~  
System�ύX�ʒm=System�ύX�ʒm or not(�v�����j�b�g����) or not(�Ȃ炵���j�b�g����) or not(�W�킹���j�b�g����) or not(�W��胆�j�b�g����)

'----------------------------------------------------------------------------------
'�A�C�e���A�h���X�Q��
'
'
'ITEM TABLE
'       �z�ďd��    �v�ʐ��d��  �A�C�e������
' 1		EM1020		EM1021(+1)	EM1030(+10)
' 2		EM1040(+20)	EM1041		EM1050
' 3		EM1060		EM1061		EM1070
' 4		EM1080		EM1081		EM1090

	'�A�C�e���ݒ�NO
	DM_ITEMNO=DM_ITEMNO

	if DM_ITEMNO>0 then

		'�y�z�ďd�ʁz
		ADRSET(EM1020,ptr�A�C�e���z�ďd��)
		ADRADD(20 * (DM_ITEMNO-1),ptr�A�C�e���z�ďd��)

		'�y�v�ʐ��d�ʁz
		ADRSET(EM1021,ptr�A�C�e���v�ʐ��d��)
		ADRADD(20 * (DM_ITEMNO-1),ptr�A�C�e���v�ʐ��d��)
		if ���C��TP_�ؑփy�[�W�m��<>160 then '���C��TP_�ؑփy�[�W�m��=160  ��ʐݒ�i��ʐݒ�ł͌v�ʐ��̔��������\�ɂ���j
			DM_�v���ڕW����1.U=*ptr�A�C�e���v�ʐ��d��
		end if
		
		'�y�A�C�e�����́z
		ADRSET(EM1030,ptr�A�C�e������)
		ADRADD(20 * (DM_ITEMNO-1),ptr�A�C�e������)
		' -- �����o�b�t�@�N���A --
		ADRSET(EM4001.U,loopptr)
		FOR loop=1 TO 10
			*loopptr.U=0
			inc(loopptr)
		NEXT
		'-- ������R�s�[
		EM4001.T=*ptr�A�C�e������.T
	
	else if DM_ITEMNO=0 then
		' -- �����o�b�t�@�N���A --
		ADRSET(EM4001.U,loopptr)
		FOR loop=1 TO 10
			*loopptr.U=0
			inc(loopptr)
		NEXT
		'-- �������
		EM4001.T=""	
	
	end if	
'----------------------------------------------------------------------------------
'�����Ė��� 

	pnlPBL�����Ė���A=pnlPB�����Ė���A and CR2006
	pnlPBL�����Ė���B=pnlPB�����Ė���B and CR2006


'----------------------------------------------------------------------------------
'StageItem �V�t�g�ƕύX 

if Item�ύX�ʒm�p�l�� then
	StageDevice0=ORA(ANDA(StageDevice0,$FF00),StageItem0)
	StageDevice1=ORA(ANDA(StageDevice1,$FF00),StageItem1)
	StageDevice2=ORA(ANDA(StageDevice2,$FF00),StageItem2)
	StageDevice3=ORA(ANDA(StageDevice3,$FF00),StageItem3)
	StageDevice4=ORA(ANDA(StageDevice4,$FF00),StageItem4)
	StageDevice5=ORA(ANDA(StageDevice5,$FF00),StageItem5)
	StageDevice6=ORA(ANDA(StageDevice6,$FF00),StageItem6)
	StageDevice7=ORA(ANDA(StageDevice7,$FF00),StageItem7)
	StageDevice8=ORA(ANDA(StageDevice8,$FF00),StageItem8)
	StageDevice9=ORA(ANDA(StageDevice9,$FF00),StageItem9)
	StageDevice10=ORA(ANDA(StageDevice10,$FF00),StageItem10)
	StageDevice11=ORA(ANDA(StageDevice11,$FF00),StageItem11)
	StageDevice12=ORA(ANDA(StageDevice12,$FF00),StageItem12)

	Item�ύX�ʒm�p�l��=OFF
end if

'----------------------------------------------------------------------------------
'�����^�]���j�^�r�o
	'-----------------------------------------------
	'�ނ炵 F1 �A�C�e��
	if 0<StageDevice17 and StageDevice17<99 and PH29_�����m then 
		IND_StageDevice17=ON
	else 
		IND_StageDevice17=OFF
	end if
	if 0<StageDevice18 and StageDevice18<99 and PH30_�����m then 
		IND_StageDevice18=ON
	else 
		IND_StageDevice18=OFF
	end if
	if 0<StageDevice19 and StageDevice19<99 and PH31_�����m then 
		IND_StageDevice19=ON
	else 
		IND_StageDevice19=OFF
	end if
	if 0<StageDevice20 and StageDevice20<99 and PH32_�����m then 
		IND_StageDevice20=ON
	else 
		IND_StageDevice20=OFF
	end if
	if 0<StageDevice21 and StageDevice21<99 and PH33_�����m then 
		IND_StageDevice21=ON
	else 
		IND_StageDevice21=OFF
	end if
	if 0<StageDevice22 and StageDevice22<99 and PH34_�����m then 
		IND_StageDevice22=ON
	else 
		IND_StageDevice22=OFF
	end if
	if 0<StageDevice23 and StageDevice23<99 and PH35_�����m then 
		IND_StageDevice23=ON
	else 
		IND_StageDevice23=OFF
	end if
	if 0<StageDevice24 and StageDevice24<99 and PH36_�����m then 
		IND_StageDevice24=ON
	else 
		IND_StageDevice24=OFF
	end if
	'-----------------------------------------------
	'�ނ炵 F2	�A�C�e�� 
	if 0<StageDevice29 and StageDevice29<99 and PH41_�����m then 
		IND_StageDevice29=ON
	else 
		IND_StageDevice29=OFF
	end if
	if 0<StageDevice30 and StageDevice30<99 and PH42_�����m then 
		IND_StageDevice30=ON
	else 
		IND_StageDevice30=OFF
	end if
	if 0<StageDevice31 and StageDevice31<99 and PH43_�����m then 
		IND_StageDevice31=ON
	else 
		IND_StageDevice31=OFF
	end if
	if 0<StageDevice32 and StageDevice32<99 and PH44_�����m then 
		IND_StageDevice32=ON
	else 
		IND_StageDevice32=OFF
	end if
	if 0<StageDevice33 and StageDevice33<99 and PH45_�����m then 
		IND_StageDevice33=ON
	else 
		IND_StageDevice33=OFF
	end if
	if 0<StageDevice34 and StageDevice34<99 and PH46_�����m then 
		IND_StageDevice34=ON
	else 
		IND_StageDevice34=OFF
	end if
	if 0<StageDevice35 and StageDevice35<99 and PH47_�����m then 
		IND_StageDevice35=ON
	else 
		IND_StageDevice35=OFF
	end if
	if 0<StageDevice36 and StageDevice36<99 and PH48_�����m then 
		IND_StageDevice36=ON
	else 
		IND_StageDevice36=OFF
	end if
	'-----------------------------------------------
	'�����R���x�AG �A�C�e��
	if 0<StageDevice37 and StageDevice37<99 and PH49_�����m then 
		IND_StageDevice37=ON
	else 
		IND_StageDevice37=OFF
	end if
	if 0<StageDevice38 and StageDevice38<99 and PH50_�����m then 
		IND_StageDevice38=ON
	else 
		IND_StageDevice38=OFF
	end if
	if 0<StageDevice39 and StageDevice39<99 and PH51_�����m then 
		IND_StageDevice39=ON
	else 
		IND_StageDevice39=OFF
	end if
	if 0<StageDevice40 and StageDevice40<99 and PH53_�����m then 
		IND_StageDevice40=ON
	else 
		IND_StageDevice40=OFF
	end if
	'-----------------------------------------------
	'���]�ق��� �A�C�e��
	if 0<StageDevice41 and StageDevice41<99 and PH57_�����m then 
		IND_StageDevice41=ON
	else 
		IND_StageDevice41=OFF
	end if
	'-----------------------------------------------
	
'----------------------------------------------------------------------------------
'�����Ė��� 

	pnlPBL�����ėLA=pnlPB�����ėLA and CR2006
	pnlPBL�����Ė���A=pnlPB�����Ė���A and CR2006
	
	pnlPBL�����ėLB=pnlPB�����ėLB and CR2006
	pnlPBL�����Ė���B=pnlPB�����Ė���B and CR2006
'-----------------------------------------------------------------------------------------------------------------------------
'�R���x�A�A���[���\��
if 0 then '�R���x�A�A���[���\������

if almMC6_�������[�^ then 		'MC6
	�R���x�A�A���[���\��=ON
else if almMC7_�������[�^ then	'MC7
	�R���x�A�A���[���\��=ON
else if almMC8_�������[�^ then	'MC8
	�R���x�A�A���[���\��=ON
else if almMC9_���[�^���[�� then	'MC9
	�R���x�A�A���[���\��=ON
else if almMC12_�������[�^ then	'MC12
	�R���x�A�A���[���\��=ON
else if almMC13_�������[�^ then	'MC13
	�R���x�A�A���[���\��=ON
else if almMC16_���[�^���[�� then	'MC16
	�R���x�A�A���[���\��=ON
else if almMC14_�������[�^ then	'MC14
	�R���x�A�A���[���\��=ON
else if almMC15_�������[�^ then	'MC15
	�R���x�A�A���[���\��=ON
else if almMC34_���[�^���[�� then	'MC34
	�R���x�A�A���[���\��=ON
else if almMC44_���[�^���[�� then	'MC44
	�R���x�A�A���[���\��=ON
else if almMC46_���[�^���[�� then	'MC46
	�R���x�A�A���[���\��=ON
else if almMC45_�������[�^ then	'MC45
	�R���x�A�A���[���\��=ON
	
else if almMC17_���[�^���[�� then	'MC17
	�R���x�A�A���[���\��=ON
else if almMC18_���[�^���[�� then	'MC18
	�R���x�A�A���[���\��=ON
else if almMC19_���[�^���[�� then	'MC19
	�R���x�A�A���[���\��=ON
else if almMC20_���[�^���[�� then	'MC20
	�R���x�A�A���[���\��=ON
else if almMC21_���[�^���[�� then	'MC21
	�R���x�A�A���[���\��=ON
else if almMC22_���[�^���[�� then	'MC22
	�R���x�A�A���[���\��=ON
else if almMC23_���[�^���[�� then	'MC23
	�R���x�A�A���[���\��=ON
else if almMC24_���[�^���[�� then	'MC24
	�R���x�A�A���[���\��=ON
else if almMC25_���[�^���[�� then	'MC25
	�R���x�A�A���[���\��=ON
else if almMC26_���[�^���[�� then	'MC26
	�R���x�A�A���[���\��=ON
else if almMC27_���[�^���[�� then	'MC27
	�R���x�A�A���[���\��=ON
else if almMC28_���[�^���[�� then	'MC28
	�R���x�A�A���[���\��=ON
	
else if almMC29_���[�^���[�� then	'MC29
	�R���x�A�A���[���\��=ON
else if almMC30_���[�^���[�� then	'MC30
	�R���x�A�A���[���\��=ON
else if almMC31_���[�^���[�� then	'MC31
	�R���x�A�A���[���\��=ON
else if almMC32_���[�^���[�� then	'MC32
	�R���x�A�A���[���\��=ON
else if almMC33_���[�^���[�� then	'MC33
	�R���x�A�A���[���\��=ON
else if almMC47_���[�^���[�� then	'MC47
	�R���x�A�A���[���\��=ON
else if almMC48_���[�^���[�� then	'MC48
	�R���x�A�A���[���\��=ON
else if almMC49_���[�^���[�� then	'MC49
	�R���x�A�A���[���\��=ON
else if almMC50_���[�^���[�� then	'MC50
	�R���x�A�A���[���\��=ON
else if almMC51_���[�^���[�� then	'MC51
	�R���x�A�A���[���\��=ON
else if almMC52_���[�^���[�� then	'MC52
	�R���x�A�A���[���\��=ON
else if almMC53_���[�^���[�� then	'MC53
	�R���x�A�A���[���\��=ON

else if almMC41_���[�^���[�� then	'MC41
	�R���x�A�A���[���\��=ON
else if almMC42_���[�^���[�� then	'MC42
	�R���x�A�A���[���\��=ON
else if almMC43_�������[�^ then	'MC43
	�R���x�A�A���[���\��=ON
else if almMC54_���[�^���[�� then	'MC54
	�R���x�A�A���[���\��=ON
	
else if almMC10_�������[�^���] then	'MC10���]
	�R���x�A�A���[���\��=ON
else if almMC10_�������[�^�t�] then	'MC10�t�]
	�R���x�A�A���[���\��=ON
else if almMC55_�������[�^ then	'MC55
	�R���x�A�A���[���\��=ON
else if almMC57_�������[�^ then	'MC57
	�R���x�A�A���[���\��=ON
else if almMC33_���[�^���[�� then	'MC33
	�R���x�A�A���[���\��=ON
else if almINV1_�R���x�A���[�^���] then	'INV1
	�R���x�A�A���[���\��=ON
else if almINV2_�R���x�A���[�^���] then	'INV2
	�R���x�A�A���[���\��=ON
else if almINV3_�R���x�A���[�^���] then	'INV3
	�R���x�A�A���[���\��=ON
else if almMC38_�������[�^ then	'MC38
	�R���x�A�A���[���\��=ON
else
	�R���x�A�A���[���\��=OFF
end if

end if
'-----------------------------------------------------------------------------------------------------------------------------
'------ �[�Č�BOX�\��
if INDalmTHR1_�����p���~�@���[�^ then
	�[�Č�BOX�\��=ON
else if INDalmTHR2_�r�o�p���~�@���[�^ then
	�[�Č�BOX�\��=ON
else if INDalmTHR3_�v�ʋ@���[�^ then
	�[�Č�BOX�\��=ON
else if INDalmRLY_�d���m�F�[�Č� then
	�[�Č�BOX�\��=ON
else
	�[�Č�BOX�\��=OFF
end if
'------	���C��BOX�\��
if INDalmTHR4_���ă|���v then
	���C��BOX�\��=ON
else if	INDalmTHR5_���ĉH�� then
	���C��BOX�\��=ON
else if INDalmDCPLC�d���d���~�� or INDalmDC�d���d���~��1 or INDalmDC�d���d���~��2 then
	���C��BOX�\��=ON
else
	���C��BOX�\��=OFF
end if
'------	�Z�Ѓ^���NBOX�\��
if INDalmTHR6_�������[�^ then
	�Z�Ѓ^���NBOX�\��=ON
else if	INDalmTHR7_�������[�^ then
	�Z�Ѓ^���NBOX�\��=ON
else if	INDalmTHR8_�������[�^ then
	�Z�Ѓ^���NBOX�\��=ON
else if	INDalmTHR11_�������[�^ then
	�Z�Ѓ^���NBOX�\��=ON
else if INDalmRLY_�Z�Гd���m�F then
	�Z�Ѓ^���NBOX�\��=ON
else
	�Z�Ѓ^���NBOX�\��=OFF
end if
'------	����BOX�\��
if INDalmTHR9_���[�^���[�� then
	����BOX�\��=ON
else if INDalmTHR12_�������[�^ then
	����BOX�\��=ON
else if INDalmTHR13_�������[�^ then
	����BOX�\��=ON
else if INDalmTHR14_�������[�^ then
	����BOX�\��=ON
else if INDalmTHR15_�������[�^ then
	����BOX�\��=ON
else if INDalmTHR16_���[�^���[�� then
	����BOX�\��=ON
else if INDalmTHR34_���[�^���[�� then
	����BOX�\��=ON
else if INDalmTHR40_�Ȃ炵���[�^ then
	����BOX�\��=ON
else if INDalmTHR44_���[�^���[�� then
	����BOX�\��=ON
else if INDalmTHR45_�������[�^ then
	����BOX�\��=ON
else if INDalmTHR46_���[�^���[�� then
	����BOX�\��=ON
else if INDalmRLY_����1�d���m�F then
	����BOX�\��=ON
else
	����BOX�\��=OFF
end if
'------	�ނ炵F1ABOX�\��
if INDalmTHR17_���[�^���[�� then
	�ނ炵F1ABOX�\��=ON
else if INDalmTHR18_���[�^���[�� then
	�ނ炵F1ABOX�\��=ON
else if INDalmTHR19_���[�^���[�� then
	�ނ炵F1ABOX�\��=ON
else if INDalmTHR20_���[�^���[�� then
	�ނ炵F1ABOX�\��=ON
else if INDalmTHR21_���[�^���[�� then
	�ނ炵F1ABOX�\��=ON
else if INDalmTHR22_���[�^���[�� then
	�ނ炵F1ABOX�\��=ON
else if INDalmRLY_F1A�d���m�F then
	�ނ炵F1ABOX�\��=ON
else
	�ނ炵F1ABOX�\��=OFF
end if
'------	�ނ炵F1BBOX�\��
if INDalmTHR23_���[�^���[�� then
	�ނ炵F1BBOX�\��=ON
else if INDalmTHR24_���[�^���[�� then
	�ނ炵F1BBOX�\��=ON
else if INDalmTHR25_���[�^���[�� then
	�ނ炵F1BBOX�\��=ON
else if INDalmTHR26_���[�^���[�� then
	�ނ炵F1BBOX�\��=ON
else if INDalmTHR27_���[�^���[�� then
	�ނ炵F1BBOX�\��=ON
else if INDalmTHR28_���[�^���[�� then
	�ނ炵F1BBOX�\��=ON
else if INDalmRLY_F1B�d���m�F then
	�ނ炵F1BBOX�\��=ON
else
	�ނ炵F1BBOX�\��=OFF
end if
'------	�ނ炵F2ABOX�\��
if INDalmTHR29_���[�^���[�� then
	�ނ炵F2ABOX�\��=ON
else if INDalmTHR30_���[�^���[�� then
	�ނ炵F2ABOX�\��=ON
else if INDalmTHR31_���[�^���[�� then
	�ނ炵F2ABOX�\��=ON
else if INDalmTHR32_���[�^���[�� then
	�ނ炵F2ABOX�\��=ON
else if INDalmTHR33_���[�^���[�� then
	�ނ炵F2ABOX�\��=ON
else if INDalmTHR47_���[�^���[�� then
	�ނ炵F2ABOX�\��=ON
else if INDalmRLY_F2A�d���m�F then
	�ނ炵F2ABOX�\��=ON
else
	�ނ炵F2ABOX�\��=OFF
end if
'------	�ނ炵F2BBOX�\��
if INDalmTHR48_���[�^���[�� then
	�ނ炵F2BBOX�\��=ON
else if INDalmTHR49_���[�^���[�� then
	�ނ炵F2BBOX�\��=ON
else if INDalmTHR50_���[�^���[�� then
	�ނ炵F2BBOX�\��=ON
else if INDalmTHR51_���[�^���[�� then
	�ނ炵F2BBOX�\��=ON
else if INDalmTHR52_���[�^���[�� then
	�ނ炵F2BBOX�\��=ON
else if INDalmTHR53_���[�^���[�� then
	�ނ炵F2BBOX�\��=ON
else if INDalmRLY_F2B�d���m�F then
	�ނ炵F2BBOX�\��=ON
else
	�ނ炵F2BBOX�\��=OFF
end if
'------	����BOX2�\��
if INDalmTHR10_�������[�^ then	
	����BOX2�\��=ON
else if INDalmTHR41_���[�^���[�� then
	����BOX2�\��=ON
else if INDalmTHR42_���[�^���[�� then
	����BOX2�\��=ON
else if INDalmTHR43_�������[�^ then
	����BOX2�\��=ON
else if INDalmTHR54_���[�^���[�� then
	����BOX2�\��=ON
else if INDalmTHR55_�������[�^ then
	����BOX2�\��=ON
else if INDalmTHR56_�u���V�T�[�}�� then
	����BOX2�\��=ON
else if INDalmTHR57_�������[�^ then
	����BOX2�\��=ON
else if INDalmRLY_����2�d���m�F then
	����BOX2�\��=ON
else
	����BOX2�\��=OFF
end if
'------	���@BOX�\��
if INDalmTHR36_���]���[�^ then	
	���@BOX�\��=ON
else if INDalmTHR35_�������[�^ then
	���@BOX�\��=ON
else if INDalmTHR37_���]���[�^ then
	���@BOX�\��=ON
else if INDalmTHR38_�������[�^ then
	���@BOX�\��=ON
else if INDalmTHR58_���|���vA then
	���@BOX�\��=ON
else if INDalmTHR59_���|���vB then
	���@BOX�\��=ON
else if INDalmTHR60_���|���vC then
	���@BOX�\��=ON
else if INDalmTHR61_���|���vD then
	���@BOX�\��=ON
else if INDalmINV1_�R���x�A�ُ� then
	���@BOX�\��=ON
else if INDalmINV2_�R���x�A�ُ� then
	���@BOX�\��=ON
else if INDalmINV3_�R���x�A�ُ� then
	���@BOX�\��=ON
else if INDalmRLY_���@�d���m�F then
	���@BOX�\��=ON
else
	���@BOX�\��=OFF
end if
'------	�T�uBOX1�\��
if INDalmRLY_�T�u2�d���m�F then	
	�T�uBOX1�\��=ON
else
	�T�uBOX1�\��=OFF
end if
'------	�T�uBOX2�\��
if INDalmRLY_�T�u2�d���m�F then	
	�T�uBOX2�\��=ON
else
	�T�uBOX2�\��=OFF
end if
'------	���]�ق����@BOX�\��
if INDalmRLY_���]�@�d���m�F then	
	���]�@BOX�\��=ON
else
	���]�@BOX�\��=OFF
end if
	
'-----------------------------------------------------------------------------------------------------------------------------
if ldp(INDalm�r�b�g�N���A) then
	FMOV(0,R90000.U,49)
end if
'-----------------------------------------------------------------------------------------------------------------------------

INDpnlPBXSW=pnlPBXSW3_���؂�V���b�^�[�JA or pnlPBXSW4_���؂�V���b�^�[��A
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW7_���؂�V���b�^�[�JB or pnlPBXSW8_���؂�V���b�^�[��B
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW14_�X�g�b�p�㏸�[ or pnlPBXSW15_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW16_�X�g�b�p�㏸�[ or pnlPBXSW17_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW18_�X�g�b�p�㏸�[ or pnlPBXSW19_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW20_���t�g���~�[ or pnlPBXSW21_���t�g�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW22_�X�g�b�p���~�[ or pnlPBXSW23_�X�g�b�p�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW24_���t�g���~�[ or pnlPBXSW25_���t�g�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW26_�N�����v���~�[ or pnlPBXSW27_�N�����v�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW28_�X�g�b�p���~�[ or pnlPBXSW29_�X�g�b�p�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW30_�N�����v���~�[ or pnlPBXSW31_�N�����v�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW32_�X�g�b�p���~�[ or pnlPBXSW33_�X�g�b�p�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW34_���t�g�㏸�[ or pnlPBXSW35_���t�g���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW36_�X�g�b�p���~�[ or pnlPBXSW37_�X�g�b�p�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW51_�X�g�b�p�㏸�[ or pnlPBXSW52_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW53_���t�g�㏸�[ or pnlPBXSW54_���t�g���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW55_���t�g�㏸�[ or pnlPBXSW56_���t�g���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW57_���t�g�㏸�[ or pnlPBXSW58_���t�g���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW59_�X�g�b�p�㏸�[ or pnlPBXSW60_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW61_�X�g�b�p�㏸�[ or pnlPBXSW62_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW63_�X�g�b�p�㏸�[ or pnlPBXSW64_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW65_�X�g�b�p�㏸�[ or pnlPBXSW66_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW67_���t�g�㏸�[ or pnlPBXSW68_���t�g���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW80_���t�g�㏸�[ or pnlPBXSW81_���t�g���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW85_���t�^�X�g�b�p���~�[ or pnlPBXSW90_���t�^�X�g�b�p���~�[ or pnlPBXSW95_���t�^�X�g�b�p���~�[ or pnlPBXSW100_���t�^�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW17_�X�g�b�p���~�[ or pnlPBXSW18_�X�g�b�p�㏸�[

'----------------------------------------------------------------------------------------------------------------------------
�A�C�e��NO�L��_STG1=not(�A�C�e��NO�̕ύX�L��) and PH1_�����m
�A�C�e��NO�L��_STG2=not(�A�C�e��NO�̕ύX�L��) and PH3_�����m
�A�C�e��NO�L��_STG3=not(�A�C�e��NO�̕ύX�L��) and PH5_�����m
�A�C�e��NO�L��_STG4=not(�A�C�e��NO�̕ύX�L��) and PH7_�����m
�A�C�e��NO�L��_STG5=not(�A�C�e��NO�̕ύX�L��) and PH9_�����m
�A�C�e��NO�L��_STG6=not(�A�C�e��NO�̕ύX�L��) and PH11_�����m
�A�C�e��NO�L��_STG7=not(�A�C�e��NO�̕ύX�L��) and PH13_�����m
�A�C�e��NO�L��_STG8=not(�A�C�e��NO�̕ύX�L��) and PH15_�����m
�A�C�e��NO�L��_STG9=not(�A�C�e��NO�̕ύX�L��) and PH17_�����m
�A�C�e��NO�L��_STG10=not(�A�C�e��NO�̕ύX�L��) and PH19_�����m
�A�C�e��NO�L��_STG11=not(�A�C�e��NO�̕ύX�L��) and PH21_�����m
�A�C�e��NO�L��_STG12=not(�A�C�e��NO�̕ύX�L��) and PH22_�����m
�A�C�e��NO�L��_STG13=not(�A�C�e��NO�̕ύX�L��) and PH24_�����m
'-----------------------------------------------------------------------------------------------------------------------------

