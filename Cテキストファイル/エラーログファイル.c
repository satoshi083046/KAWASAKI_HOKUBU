'�G���[���O�t�@�C��

'-----------------------------------------------------------------------------------------------------------------------------
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
'FileErr	�r�b�g[2]
'FindEndSec	2���[�h�����Ȃ�����
'FindStartSec	2���[�h�����Ȃ�����
'OffsetAddres	2���[�h�����Ȃ�����
'ReadCnt	1���[�h�����Ȃ�����
'ReadErrCode	2���[�h�����Ȃ�����
'ReadErrCodeStr	������[20]
'ReadFileName	������[40]
'ReadSec	2���[�h�����Ȃ�����
'ReadSecStr	������[20]
'ReadStr	������[1500]
'StackEnablebit	�r�b�g
'WriteAlmstr	������[40]
'WriteErrAddres	2���[�h�����Ȃ�����
'WriteErrCode	2���[�h�����Ȃ�����
'WriteErrCodeStr	������[20]
'WriteFileName	������[40]
'WriteSec	2���[�h�����Ȃ�����
'WriteSecStr	������[20]
'WriteStatstr	������[100]
'WriteStepstr	������[1000]
'WriteStr	������[1500]
'anloop	1���[�h�����Ȃ�����
'dmystr	������[25]
'elFindStart�N����	1���[�h�����Ȃ�����[6]
'elStatBitstr	������[20]
'el�e�X�g�^�]	1���[�h�����Ȃ�����
'el�e�X�g�^�]str	������[20]
'el�O�����^�]��	1���[�h�����Ȃ�����
'el�O�����^�]��str	������[20]
'el�������[�h	1���[�h�����Ȃ�����
'el�������[�hstr	������[20]
'el�^�]��	1���[�h�����Ȃ�����
'el�^�]��str	������[20]
'el���t��~str	������[20]
'el����~	1���[�h�����Ȃ�����
'initFileread	�r�b�g
'linecnt	1���[�h�����Ȃ�����
'loop	1���[�h�����Ȃ�����
'readerr	�r�b�g[4]
'readpar	1���[�h�����Ȃ�����[4]
'readparstak	2���[�h�����Ȃ�����
'tmpreadstr	������[100]
'-----------------------------------------------------------------------------------------------------------------------------
'�y ���������� �z
if CR2008 then '�d��ON������������
	Filewritestep=0
	Filereadstep=0
	ErrAnalyzestep=0
end if

'-----------------------------------------------------------------------------------------------------------------------------
'�G���[�t�@�C��������

	select case Filewritestep
	'----------------------------------------------------------------------
	case 1
		MMKDIR("Machine",FileErr)
		INC(Filewritestep)

	case 2
		if FileErr[0] then '����
			INC(Filewritestep)
		end if
	
	case 3
		if FileErr[1] then '�ُ�I��
		end if
		INC(Filewritestep)

	
	'----------------------------------------------------------------------
	case 4
		if 0 then '�e�X�g�p�A�h���X
		    adrset(almRS1_���^���N����Z���T�[,WriteErrAddres)
		    WriteAlmstr="almRS1_���^���N����Z���T�["
			
			�O�����H��step=120
		end if

		'-------------------------------
		ADRSET(R78000,OffsetAddres) 'almxxxx�̐擪�A�h���X
		WriteErrCode=(WriteErrAddres-OffsetAddres)+7000

		WriteErrCodeStr.T=DASC(WriteErrCode.D,1)
		WriteSec=SEC(CM700)
		WriteSecStr.T=DASC(WriteSec.D,1)		
		'-------------------------------
		if ��������AutoMode then
			WriteStatstr="����"+","
		else
			WriteStatstr="�蓮"+","
		end if
		if ��������step>0 or OtherStep>0 or �O�����H��step>0 then
			WriteStatstr=WriteStatstr+"�^�]��"+","
		else
			WriteStatstr=WriteStatstr+"��~��"+","
		end if
		if �e�X�g�^�] then
			WriteStatstr=WriteStatstr+"�e�X�g�^�]"+","+"ON"+","
		else
			WriteStatstr=WriteStatstr+"�e�X�g�^�]"+","+"OFF"+","
		end if
		if EmgFlg then
			WriteStatstr=WriteStatstr+"����~"+","+"ON"+","
		else
			WriteStatstr=WriteStatstr+"����~"+","+"OFF"+","
		end if
		if �O�����H��step<>0 then
			WriteStatstr=WriteStatstr+"�O�����^�]��"+","+"ON"
		else
			WriteStatstr=WriteStatstr+"�O�����^�]��"+","+"OFF"
		end if
		'-------------------------------
		'�^�]step WriteStep 20x30
		WriteStepstr="�O�����H��step"+","+DASC(�O�����H��step.U,1)+","
		WriteStepstr=WriteStepstr+"�v��step"+","+DASC(�v��step.U,1)+","
		WriteStepstr=WriteStepstr+"����step"+","+DASC(����step.U,1)+","
		WriteStepstr=WriteStepstr+"�Z�Ѓ^���NA���j�b�gstep"+","+DASC(�Z�Ѓ^���NA���j�b�gstep.U,1)+","
		WriteStepstr=WriteStepstr+"�Z�Ѓ^���NB���j�b�gstep"+","+DASC(�Z�Ѓ^���NB���j�b�gstep.U,1)+","
		WriteStepstr=WriteStepstr+"�v�����j�b�gstep"+","+DASC(�v�����j�b�gstep.U,1)+","
		WriteStepstr=WriteStepstr+"�Ȃ炵���j�b�gstep"+","+DASC(�Ȃ炵���j�b�gstep.U,1)+","
		WriteStepstr=WriteStepstr+"�W�킹���j�b�gstep"+","+DASC(�W�킹���j�b�gstep.U,1)+","
		WriteStepstr=WriteStepstr+"�W��胆�j�b�gstep"+","+DASC(�W��胆�j�b�gstep.U,1)+","
		WriteStepstr=WriteStepstr+"�ق����@A���j�b�gstep"+","+DASC(�ق����@A���j�b�gstep.U,1)+","
		WriteStepstr=WriteStepstr+"�����R���x�AAstep"+","+DASC(�����R���x�AAstep.U,1)+","
		WriteStepstr=WriteStepstr+"�����R���x�ABstep"+","+DASC(�����R���x�ABstep.U,1)+","
		WriteStepstr=WriteStepstr+"�����R���x�ACstep"+","+DASC(�����R���x�ACstep.U,1)+","
		WriteStepstr=WriteStepstr+"�����R���x�AC2step"+","+DASC(�����R���x�AC2step.U,1)+","
		WriteStepstr=WriteStepstr+"�����R���x�ADstep"+","+DASC(�����R���x�ADstep.U,1)+","
		WriteStepstr=WriteStepstr+"�����R���x�AEstep"+","+DASC(�����R���x�AEstep.U,1)+","
		WriteStepstr=WriteStepstr+"�����R���x�AF1step"+","+DASC(�����R���x�AF1step.U,1)+","
		WriteStepstr=WriteStepstr+"�����R���x�AF2step"+","+DASC(�����R���x�AF2step.U,1)+","
		WriteStepstr=WriteStepstr+"�����R���x�AGstep"+","+DASC(�����R���x�AGstep.U,1)+","
		WriteStepstr=WriteStepstr+"�����R���x�AHstep"+","+DASC(�����R���x�AHstep.U,1)+","
		WriteStepstr=WriteStepstr+"���t�^���~���uAstep"+","+DASC(���t�^���~���uAstep.U,1)
		WriteStepstr=WriteStepstr+"�����]����step"+","+DASC(�����]����step.U,1)+","
		WriteStepstr=WriteStepstr+"��򃆃j�b�gstep"+","+DASC(��򃆃j�b�gstep.U,1)+","
		WriteStepstr=WriteStepstr+"���^���Nstep"+","+DASC(���^���Nstep.U,1)+","
		WriteStepstr=WriteStepstr+"���R���x�A����step"+","+DASC(���R���x�A����step.U,1)+","
		WriteStepstr=WriteStepstr+"�����]�o��step"+","+DASC(�����]�o��step.U,1)+","
		WriteStepstr=WriteStepstr+"���t�^���~���uBstep"+","+DASC(���t�^���~���uBstep.U,1)
		WriteStepstr=WriteStepstr+"IH���у��j�b�gAstep"+","+DASC(IH���у��j�b�gAstep.U,1)
		WriteStepstr=WriteStepstr+"IH���у��j�b�gBstep"+","+DASC(IH���у��j�b�gBstep.U,1)
		'----------------------------------------------------------------------
		'�t�@�C�������ݕ�����		
		WriteStr.T=str(CM700)+"/"+str(CM701)+"/"+str(CM702)+" "+str(CM703)+":"+STR(CM704)+"," '���t
		WriteStr.T=WriteStr.T+WriteAlmstr+"," '�A���[������
		WriteStr.T=WriteStr.T+WriteStatstr+"," '�^�]���
		WriteStr.T=WriteStr.T+WriteStepstr '���j�b�gSTEP
		'-------------------------------
		WriteStr.T=WriteStr.T+CHR($0D) 
		'----------------------------------------------------------------------
		'�t�@�C��������
		WriteFileName.T="Machine\"+"ERRLOG"+"20"+STR(CM700)+STR(CM701)+"."+"CSV" '�t�@�C����
		MPRINT(WriteFileName.T,WriteStr.T,FileErr)

		INC(Filewritestep)
	
	case 5
		if FileErr[0] then '����
			INC(Filewritestep)
		end if
	
	case 6
		if FileErr[1] then '�ُ�I��
		end if
		INC(Filewritestep)

	'----------------------------------------------------------------------
	case 7
		MMKDIR("Machine",FileErr)
		INC(Filewritestep)

	case 8
		if FileErr[0] then '����
			INC(Filewritestep)
		end if
	
	case 9
		if FileErr[1] then '�ُ�I��
		end if
		INC(Filewritestep)

	'----------------------------------------------------------------------
	case 10
		'-------------------------------
		if ��������AutoMode then
			elStatBitstr="1"+","
		else
			elStatBitstr="0"+","
		end if
		if ��������step>0 or OtherStep>0 or �O�����H��step>0 then
			elStatBitstr=elStatBitstr+"1"+","
		else
			elStatBitstr=elStatBitstr+"0"+","
		end if
		if �e�X�g�^�] then
			elStatBitstr=elStatBitstr+"1"+","
		else
			elStatBitstr=elStatBitstr+"0"+","
		end if
		if EmgFlg then
			elStatBitstr=elStatBitstr+"1"+","
		else
			elStatBitstr=elStatBitstr+"0"+","
		end if
		if �O�����H��step<>0 then
			elStatBitstr=elStatBitstr+"1"+","
		else
			elStatBitstr=elStatBitstr+"0"+","
		end if 
		if ��������AutoRun then '����̓t�H�[�}�b�g��̗\���ł�
			elStatBitstr=elStatBitstr+"1"+","
		else
			elStatBitstr=elStatBitstr+"0"+","
		end if
		if ��������AutoRun then
			elStatBitstr=elStatBitstr+"1"+","
		else
			elStatBitstr=elStatBitstr+"0"+","
		end if
		if ��������AutoRun then
			elStatBitstr=elStatBitstr+"1"
		else
			elStatBitstr=elStatBitstr+"0"
		end if
		'----------------------------------------------------------------------
		WriteStr.T=WriteSecStr.T+","+WriteErrCodeStr.T+","+elStatBitstr.T
		WriteStr.T=WriteStr.T+CHR($0D)
		'----------------------------------------------------------------------
		'�t�@�C��������
		WriteFileName.T="Machine\"+"ERRAnal"+"20"+STR(CM700)+STR(CM701)+"."+"CSV" '�t�@�C����
		MPRINT(WriteFileName.T,WriteStr.T,FileErr)
	
		INC(Filewritestep)
		
	case 11
		if FileErr[0] then '����
			INC(Filewritestep)
		end if
	
	case 12
		if FileErr[1] then '�ُ�I��
		end if
		
		Filewritestep=0
		
	end select

'-----------------------------------------------------------------------------------------------------------------------------
'�G���[�t�@�C���ǂݏo��

'ErrAnalxxx.CSV
'Line�t���[��		6000181416"",1234"",1"",1"",1"",1"",1"",1"",1"",1""cr
'                     (11),       (5),  (2),(2),(2),(2),(2),(2),(2),(2),1 = 
	select case Filereadstep
	
	case 1

		FindStartSec=sec(FindStart�N����)
		FindEndSec=sec(FindEnd�N����)
	
		ReadFileName.T="Machine\"+"ERRAnal"+"20"+STR(FindStart�N����[0])+STR(FindStart�N����[1])+"."+"CSV"
		initFileread=ON
		linecnt=0
		readpar[0]=0  '�ŏ��̍s����Ǎ�
		readpar[1]=0  '�ŏ��̍s����Ǎ�
		readpar[2]=50 '�ő�Ǎ�������

		'�N���A
		for loop=0 to 49 step 1
			ErrAnalyzeCode[loop]=0
			ErrAnalyzeCnt[loop]=0
		next		
		
		INC(Filereadstep)
	
	case 2
	
		if initFileread or (readerr[0] and ErrAnalyzestep=0) then
			if MREADL(ReadFileName.T,ReadStr,readpar,readerr) then
				inc(linecnt)
				ReadCnt=SPLIT(ReadStr.T,",",ReadSecStr,ReadErrCodeStr,el�������[�hstr,el�^�]��str,el�e�X�g�^�]str,el���t��~str,el�O�����^�]��str,el�������[�hstr,el�������[�hstr,el�������[�hstr)
				if ReadCnt>=7 then
					ReadSec.D=RDASC(ReadSecStr)
					ReadErrCode.D=RDASC(ReadErrCodeStr)
					if LEN(el�������[�hstr)>0 then
						el�������[�h.U=RDASC(el�������[�hstr)
					else
						el�������[�h=0
					end if
					
					if LEN(el�^�]��str)>0 then
						el�^�]��.U=RDASC(el�^�]��str)
					else
						el�^�]��=0
					end if
					
					if LEN(el�e�X�g�^�]str)>0 then
						el�e�X�g�^�].U=RDASC(el�e�X�g�^�]str)
					else 
						el�e�X�g�^�]=0
					end if
					
					if LEN(el���t��~str)>0 then
						el����~.U=RDASC(el���t��~str)
					else
						el����~=0
					end if
					
					if LEN(el�O�����^�]��str)>0 then
						el�O�����^�]��.U=RDASC(el�O�����^�]��str)
					else
						el�O�����^�]��=0
					end if					
					StackEnablebit=not(pnlPBel�������[�h) or (pnlPBel�������[�h and el�������[�h=1) '�������[�h�̂�
					StackEnablebit=StackEnablebit and (not(pnlPBel�^�]��) or (pnlPBel�^�]�� and el�^�]��=1)) '�^�]���̂�
					StackEnablebit=StackEnablebit and (not(pnlPBel�e�X�g�^�]) or (pnlPBel�e�X�g�^�] and el�e�X�g�^�]=0)) '�e�X�g�^�]���O
					StackEnablebit=StackEnablebit and (not(pnlPBel����~) or (pnlPBel����~ and el����~=0)) '����~���O
					StackEnablebit=StackEnablebit and (not(pnlPBel�O�����^�]��) or (pnlPBel�O�����^�]�� and el�O�����^�]��=0)) '�O�����^�]���O
					if pnlPBelALL then
						StackEnablebit=ON
					end if
					'----------------------------------------
					'�G���[���v�v���O����	
					if ReadSec>=FindStartSec and ReadSec<=FindEndSec then
						if StackEnablebit then
							for loop=0 to 49 step 1
								if ErrAnalyzeCode[loop]=0 or ErrAnalyzeCode[loop]=TOU(ReadErrCode) then
									ErrAnalyzeCode[loop]=TOU(ReadErrCode)
									INC(ErrAnalyzeCnt[loop])
									break
								end if
							next
						end if
					end if
					'----------------------------------------
				end if
				if initFileread or readparstak<>readpar[0] then
					readparstak=readpar[0]
					initFileread=OFF
				else
					ErrAnalyzestep=1
					inc(Filereadstep)		
				end if
				
			end if
		end if

	case 3
		'�T�����Ō����܂����ꍇ�ɂ�FindEnd�N�����̌��̃t�@�C����1������w����܂ōďW�v����
		' FindStart�N���� 2018�N12��29��  FindEnd�N���� 2019�N1��5��
		' (case1,2) 2018�N12��29��~�����i�W�v�j(case3,4) 2019�N1��1��~2019�N1��5���i�ďW�v�j
		
		
		if not(pnlPBel�T) or (pnlPBel�T and FindStart�N����[1]=FindEnd�N����[1]) then
			Filereadstep=0
		else 
		
			elFindStart�N����[0]=FindEnd�N����[0]
			elFindStart�N����[1]=FindEnd�N����[1]
			elFindStart�N����[2]=1
			elFindStart�N����[3]=0
			elFindStart�N����[4]=0
			elFindStart�N����[5]=0
			
		
			FindStartSec=sec(elFindStart�N����)
			FindEndSec=sec(FindEnd�N����)
		
			ReadFileName.T="Machine\"+"ERRAnal"+"20"+STR(FindEnd�N����[0])+STR(FindEnd�N����[1])+"."+"CSV"
			initFileread=ON
			linecnt=0
			readpar[0]=0  '�ŏ��̍s����Ǎ�
			readpar[1]=0  '�ŏ��̍s����Ǎ�
			readpar[2]=50 '�ő�Ǎ�������

			INC(Filereadstep)
		end if


	case 4

		if initFileread or (readerr[0] and ErrAnalyzestep=0) then
			if MREADL(ReadFileName.T,ReadStr,readpar,readerr) then
				inc(linecnt)
				ReadCnt=SPLIT(ReadStr.T,",",ReadSecStr,ReadErrCodeStr,el�������[�hstr,el�^�]��str,el�e�X�g�^�]str,el���t��~str,el�O�����^�]��str,el�������[�hstr,el�������[�hstr,el�������[�hstr)
				if ReadCnt>=7 then
					ReadSec.D=RDASC(ReadSecStr)
					ReadErrCode.D=RDASC(ReadErrCodeStr)
					if LEN(el�������[�hstr)>0 then
						el�������[�h.U=RDASC(el�������[�hstr)
					else
						el�������[�h=0
					end if
					
					if LEN(el�^�]��str)>0 then
						el�^�]��.U=RDASC(el�^�]��str)
					else
						el�^�]��=0
					end if
					
					if LEN(el�e�X�g�^�]str)>0 then
						el�e�X�g�^�].U=RDASC(el�e�X�g�^�]str)
					else 
						el�e�X�g�^�]=0
					end if
					
					if LEN(el���t��~str)>0 then
						el����~.U=RDASC(el���t��~str)
					else
						el����~=0
					end if
					
					if LEN(el�O�����^�]��str)>0 then
						el�O�����^�]��.U=RDASC(el�O�����^�]��str)
					else
						el�O�����^�]��=0
					end if
					StackEnablebit=not(pnlPBel�������[�h) or (pnlPBel�������[�h and el�������[�h=1) '�������[�h�̂�
					StackEnablebit=StackEnablebit and (not(pnlPBel�^�]��) or (pnlPBel�^�]�� and el�^�]��=1)) '�^�]���̂�
					StackEnablebit=StackEnablebit and (not(pnlPBel�e�X�g�^�]) or (pnlPBel�e�X�g�^�] and el�e�X�g�^�]=0)) '�e�X�g�^�]���O
					StackEnablebit=StackEnablebit and (not(pnlPBel����~) or (pnlPBel����~ and el����~=0)) '����~���O
					StackEnablebit=StackEnablebit and (not(pnlPBel�O�����^�]��) or (pnlPBel�O�����^�]�� and el�O�����^�]��=0)) '�O�����^�]���O
					if pnlPBelALL then
						StackEnablebit=ON
					end if
					'----------------------------------------
					'�G���[���v�v���O����	
					if ReadSec>=FindStartSec and ReadSec<=FindEndSec then
						if StackEnablebit then
							for loop=0 to 49 step 1
								if ErrAnalyzeCode[loop]=0 or ErrAnalyzeCode[loop]=TOU(ReadErrCode) then
									ErrAnalyzeCode[loop]=TOU(ReadErrCode)
									INC(ErrAnalyzeCnt[loop])
									break
								end if
							next
						end if
					end if
					'----------------------------------------
				end if
				if initFileread or readparstak<>readpar[0] then
					readparstak=readpar[0]
					initFileread=OFF
				else
					ErrAnalyzestep=1
					inc(Filereadstep)		
				end if
				
			end if
		end if

	
	case 5
		Filereadstep=0
	end select
	
'-----------------------------------------------------------------------------------------------------------------------------
'Analysis ���v�Z

	select case ErrAnalyzestep
	
	case 1
		ErrAnlyzeTotalCnt=0
		for anloop=0 to 49 step 1
			ErrAnalyzePersent[anloop]=0
		next
		inc(ErrAnalyzestep)
	case 2
		for anloop=0 to 49 step 1
			ErrAnlyzeTotalCnt=ErrAnlyzeTotalCnt+ ErrAnalyzeCnt[anloop]
		next
		inc(ErrAnalyzestep)	
	case 3
		if ErrAnlyzeTotalCnt>0 then
			for anloop=0 to 49 step 1
			
				if ErrAnalyzeCnt[anloop]>0 then
					ErrAnalyzePersent[anloop]=(ErrAnalyzeCnt[anloop]*10000)/ErrAnlyzeTotalCnt
				else
					ErrAnalyzePersent[anloop]=0
				end if
				
			next
		end if
		inc(ErrAnalyzestep)	
	case 4
		ErrAnalyzestep=0
	end select
'-----------------------------------------------------------------------------------------------------------------------------
if ldp(almSSW3_�蓮���[�h) then
    adrset(almSSW3_�蓮���[�h,WriteErrAddres)
    WriteAlmstr.T="almSSW3_�蓮���[�h"
    Filewritestep=1
end if
if ldp(almSSW3_�������[�h) then
    adrset(almSSW3_�������[�h,WriteErrAddres)
    WriteAlmstr.T="almSSW3_�������[�h"
    Filewritestep=1
end if
if ldp(almRS1_���^���N����Z���T�[) then
    adrset(almRS1_���^���N����Z���T�[,WriteErrAddres)
    WriteAlmstr.T="almRS1_���^���N����Z���T�["
    Filewritestep=1
end if
if ldp(almTHR5_���ĉH��) then
    adrset(almTHR5_���ĉH��,WriteErrAddres)
    WriteAlmstr.T="almTHR5_���ĉH��"
    Filewritestep=1
end if
if ldp(almTHR4_���ă|���v) then
    adrset(almTHR4_���ă|���v,WriteErrAddres)
    WriteAlmstr.T="almTHR4_���ă|���v"
    Filewritestep=1
end if
if ldp(almDCPLC�d���d���~��) then
    adrset(almDCPLC�d���d���~��,WriteErrAddres)
    WriteAlmstr.T="almDCPLC�d���d���~��"
    Filewritestep=1
end if
if ldp(almDC�d���d���~��1) then
    adrset(almDC�d���d���~��1,WriteErrAddres)
    WriteAlmstr.T="almDC�d���d���~��1"
    Filewritestep=1
end if
if ldp(almDC�d���d���~��2) then
    adrset(almDC�d���d���~��2,WriteErrAddres)
    WriteAlmstr.T="almDC�d���d���~��2"
    Filewritestep=1
end if
if ldp(almPTL1_�p�g���C�g��) then
    adrset(almPTL1_�p�g���C�g��,WriteErrAddres)
    WriteAlmstr.T="almPTL1_�p�g���C�g��"
    Filewritestep=1
end if
if ldp(almPTL1_�p�g���C�g��) then
    adrset(almPTL1_�p�g���C�g��,WriteErrAddres)
    WriteAlmstr.T="almPTL1_�p�g���C�g��"
    Filewritestep=1
end if
if ldp(almPTL1_�p�g���C�g��) then
    adrset(almPTL1_�p�g���C�g��,WriteErrAddres)
    WriteAlmstr.T="almPTL1_�p�g���C�g��"
    Filewritestep=1
end if
if ldp(almPTL1_�p�g���C�g�u�U�[) then
    adrset(almPTL1_�p�g���C�g�u�U�[,WriteErrAddres)
    WriteAlmstr.T="almPTL1_�p�g���C�g�u�U�["
    Filewritestep=1
end if
if ldp(almRLY_���x���X�C�b�`�p�d��) then
    adrset(almRLY_���x���X�C�b�`�p�d��,WriteErrAddres)
    WriteAlmstr.T="almRLY_���x���X�C�b�`�p�d��"
    Filewritestep=1
end if
if ldp(almMC5_���ĉH��) then
    adrset(almMC5_���ĉH��,WriteErrAddres)
    WriteAlmstr.T="almMC5_���ĉH��"
    Filewritestep=1
end if
if ldp(almMC4_���ă|���v) then
    adrset(almMC4_���ă|���v,WriteErrAddres)
    WriteAlmstr.T="almMC4_���ă|���v"
    Filewritestep=1
end if
if ldp(almSV1_�����d����) then
    adrset(almSV1_�����d����,WriteErrAddres)
    WriteAlmstr.T="almSV1_�����d����"
    Filewritestep=1
end if
if ldp(almSV58_���ăo���uA) then
    adrset(almSV58_���ăo���uA,WriteErrAddres)
    WriteAlmstr.T="almSV58_���ăo���uA"
    Filewritestep=1
end if
if ldp(almRLY_�d���m�F�[�Č�) then
    adrset(almRLY_�d���m�F�[�Č�,WriteErrAddres)
    WriteAlmstr.T="almRLY_�d���m�F�[�Č�"
    Filewritestep=1
end if
if ldp(almSSW4_�[�ČɎ蓮) then
    adrset(almSSW4_�[�ČɎ蓮,WriteErrAddres)
    WriteAlmstr.T="almSSW4_�[�ČɎ蓮"
    Filewritestep=1
end if
if ldp(almSSW4_�[�ČɎ���) then
    adrset(almSSW4_�[�ČɎ���,WriteErrAddres)
    WriteAlmstr.T="almSSW4_�[�ČɎ���"
    Filewritestep=1
end if
if ldp(almFLOS2_���Ė����Đ؊����m) then
    adrset(almFLOS2_���Ė����Đ؊����m,WriteErrAddres)
    WriteAlmstr.T="almFLOS2_���Ė����Đ؊����m"
    Filewritestep=1
end if
if ldp(almFLOS1_�v�ʋ@�ߐڃZ���T�[) then
    adrset(almFLOS1_�v�ʋ@�ߐڃZ���T�[,WriteErrAddres)
    WriteAlmstr.T="almFLOS1_�v�ʋ@�ߐڃZ���T�["
    Filewritestep=1
end if
if ldp(almTHR1_�����p���~�@���[�^) then
    adrset(almTHR1_�����p���~�@���[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR1_�����p���~�@���[�^"
    Filewritestep=1
end if
if ldp(almTHR2_�r�o�p���~�@���[�^) then
    adrset(almTHR2_�r�o�p���~�@���[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR2_�r�o�p���~�@���[�^"
    Filewritestep=1
end if
if ldp(almTHR3_�v�ʋ@���[�^) then
    adrset(almTHR3_�v�ʋ@���[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR3_�v�ʋ@���[�^"
    Filewritestep=1
end if
if ldp(almMC1_�����p���~�@) then
    adrset(almMC1_�����p���~�@,WriteErrAddres)
    WriteAlmstr.T="almMC1_�����p���~�@"
    Filewritestep=1
end if
if ldp(almMC2_�r�o�p���~�@) then
    adrset(almMC2_�r�o�p���~�@,WriteErrAddres)
    WriteAlmstr.T="almMC2_�r�o�p���~�@"
    Filewritestep=1
end if
if ldp(almMC3_�v�ʋ@) then
    adrset(almMC3_�v�ʋ@,WriteErrAddres)
    WriteAlmstr.T="almMC3_�v�ʋ@"
    Filewritestep=1
end if
if ldp(almRLY_�Z�Гd���m�F) then
    adrset(almRLY_�Z�Гd���m�F,WriteErrAddres)
    WriteAlmstr.T="almRLY_�Z�Гd���m�F"
    Filewritestep=1
end if
if ldp(almPS1_�G�A�[����) then
    adrset(almPS1_�G�A�[����,WriteErrAddres)
    WriteAlmstr.T="almPS1_�G�A�[����"
    Filewritestep=1
end if
if ldp(almXSW9_���Đ؊�A��) then
    adrset(almXSW9_���Đ؊�A��,WriteErrAddres)
    WriteAlmstr.T="almXSW9_���Đ؊�A��"
    Filewritestep=1
end if
if ldp(almXSW10_���Đ؊�B��) then
    adrset(almXSW10_���Đ؊�B��,WriteErrAddres)
    WriteAlmstr.T="almXSW10_���Đ؊�B��"
    Filewritestep=1
end if
if ldp(almPDL1_�p�h���Z���T�[���A) then
    adrset(almPDL1_�p�h���Z���T�[���A,WriteErrAddres)
    WriteAlmstr.T="almPDL1_�p�h���Z���T�[���A"
    Filewritestep=1
end if
if ldp(almRLY_���d�Z���T�d��OFF1) then
    adrset(almRLY_���d�Z���T�d��OFF1,WriteErrAddres)
    WriteAlmstr.T="almRLY_���d�Z���T�d��OFF1"
    Filewritestep=1
end if
if ldp(almPTL2_�p�g���C�g��) then
    adrset(almPTL2_�p�g���C�g��,WriteErrAddres)
    WriteAlmstr.T="almPTL2_�p�g���C�g��"
    Filewritestep=1
end if
if ldp(almPTL2_�p�g���C�g��) then
    adrset(almPTL2_�p�g���C�g��,WriteErrAddres)
    WriteAlmstr.T="almPTL2_�p�g���C�g��"
    Filewritestep=1
end if
if ldp(almPTL2_�p�g���C�g��) then
    adrset(almPTL2_�p�g���C�g��,WriteErrAddres)
    WriteAlmstr.T="almPTL2_�p�g���C�g��"
    Filewritestep=1
end if
if ldp(almPTL2_�p�g���C�g�u�U�[) then
    adrset(almPTL2_�p�g���C�g�u�U�[,WriteErrAddres)
    WriteAlmstr.T="almPTL2_�p�g���C�g�u�U�["
    Filewritestep=1
end if
if ldp(almPDL2_�p�h���Z���T�[����A) then
    adrset(almPDL2_�p�h���Z���T�[����A,WriteErrAddres)
    WriteAlmstr.T="almPDL2_�p�h���Z���T�[����A"
    Filewritestep=1
end if
if ldp(almXSW1_�[�U�o���u�JA) then
    adrset(almXSW1_�[�U�o���u�JA,WriteErrAddres)
    WriteAlmstr.T="almXSW1_�[�U�o���u�JA"
    Filewritestep=1
end if
if ldp(almXSW2_�[�U�o���u��A) then
    adrset(almXSW2_�[�U�o���u��A,WriteErrAddres)
    WriteAlmstr.T="almXSW2_�[�U�o���u��A"
    Filewritestep=1
end if
if ldp(almXSW3_���؂�V���b�^�[�JA) then
    adrset(almXSW3_���؂�V���b�^�[�JA,WriteErrAddres)
    WriteAlmstr.T="almXSW3_���؂�V���b�^�[�JA"
    Filewritestep=1
end if
if ldp(almXSW4_���؂�V���b�^�[��A) then
    adrset(almXSW4_���؂�V���b�^�[��A,WriteErrAddres)
    WriteAlmstr.T="almXSW4_���؂�V���b�^�[��A"
    Filewritestep=1
end if
if ldp(almXSW76_�r���o���u�JA) then
    adrset(almXSW76_�r���o���u�JA,WriteErrAddres)
    WriteAlmstr.T="almXSW76_�r���o���u�JA"
    Filewritestep=1
end if
if ldp(almXSW77_�r���o���u��A) then
    adrset(almXSW77_�r���o���u��A,WriteErrAddres)
    WriteAlmstr.T="almXSW77_�r���o���u��A"
    Filewritestep=1
end if
if ldp(almPDL3_�p�h���Z���T�[���B) then
    adrset(almPDL3_�p�h���Z���T�[���B,WriteErrAddres)
    WriteAlmstr.T="almPDL3_�p�h���Z���T�[���B"
    Filewritestep=1
end if
if ldp(almPDL4_�p�h���Z���T�[����B) then
    adrset(almPDL4_�p�h���Z���T�[����B,WriteErrAddres)
    WriteAlmstr.T="almPDL4_�p�h���Z���T�[����B"
    Filewritestep=1
end if
if ldp(almXSW5_�[�U�o���u�JB) then
    adrset(almXSW5_�[�U�o���u�JB,WriteErrAddres)
    WriteAlmstr.T="almXSW5_�[�U�o���u�JB"
    Filewritestep=1
end if
if ldp(almXSW6_�[�U�o���u��B) then
    adrset(almXSW6_�[�U�o���u��B,WriteErrAddres)
    WriteAlmstr.T="almXSW6_�[�U�o���u��B"
    Filewritestep=1
end if
if ldp(almXSW7_���؂�V���b�^�[�JB) then
    adrset(almXSW7_���؂�V���b�^�[�JB,WriteErrAddres)
    WriteAlmstr.T="almXSW7_���؂�V���b�^�[�JB"
    Filewritestep=1
end if
if ldp(almXSW8_���؂�V���b�^�[��B) then
    adrset(almXSW8_���؂�V���b�^�[��B,WriteErrAddres)
    WriteAlmstr.T="almXSW8_���؂�V���b�^�[��B"
    Filewritestep=1
end if
if ldp(almXSW78_�r���o���u�JB) then
    adrset(almXSW78_�r���o���u�JB,WriteErrAddres)
    WriteAlmstr.T="almXSW78_�r���o���u�JB"
    Filewritestep=1
end if
if ldp(almSV12_���Đ؊��o���uA��) then
    adrset(almSV12_���Đ؊��o���uA��,WriteErrAddres)
    WriteAlmstr.T="almSV12_���Đ؊��o���uA��"
    Filewritestep=1
end if
if ldp(almSV13_���Đ؊��o���uB��) then
    adrset(almSV13_���Đ؊��o���uB��,WriteErrAddres)
    WriteAlmstr.T="almSV13_���Đ؊��o���uB��"
    Filewritestep=1
end if
if ldp(almRLY5_�p�h���Z���T�d��) then
    adrset(almRLY5_�p�h���Z���T�d��,WriteErrAddres)
    WriteAlmstr.T="almRLY5_�p�h���Z���T�d��"
    Filewritestep=1
end if
if ldp(almSV2_�[�U�o���u�JA) then
    adrset(almSV2_�[�U�o���u�JA,WriteErrAddres)
    WriteAlmstr.T="almSV2_�[�U�o���u�JA"
    Filewritestep=1
end if
if ldp(almSV3_�[�U�o���u��A) then
    adrset(almSV3_�[�U�o���u��A,WriteErrAddres)
    WriteAlmstr.T="almSV3_�[�U�o���u��A"
    Filewritestep=1
end if
if ldp(almSV4_���؂�V���b�^�[�JA) then
    adrset(almSV4_���؂�V���b�^�[�JA,WriteErrAddres)
    WriteAlmstr.T="almSV4_���؂�V���b�^�[�JA"
    Filewritestep=1
end if
if ldp(almSV5_���؂�V���b�^�[��A) then
    adrset(almSV5_���؂�V���b�^�[��A,WriteErrAddres)
    WriteAlmstr.T="almSV5_���؂�V���b�^�[��A"
    Filewritestep=1
end if
if ldp(almSV60_�r���o���u�JA) then
    adrset(almSV60_�r���o���u�JA,WriteErrAddres)
    WriteAlmstr.T="almSV60_�r���o���u�JA"
    Filewritestep=1
end if
if ldp(almSV61_�r���o���u��A) then
    adrset(almSV61_�r���o���u��A,WriteErrAddres)
    WriteAlmstr.T="almSV61_�r���o���u��A"
    Filewritestep=1
end if
if ldp(almSV7_�[�U�o���u�JB) then
    adrset(almSV7_�[�U�o���u�JB,WriteErrAddres)
    WriteAlmstr.T="almSV7_�[�U�o���u�JB"
    Filewritestep=1
end if
if ldp(almSV8_�[�U�o���u��B) then
    adrset(almSV8_�[�U�o���u��B,WriteErrAddres)
    WriteAlmstr.T="almSV8_�[�U�o���u��B"
    Filewritestep=1
end if
if ldp(almSV9_���؂�V���b�^�[�JB) then
    adrset(almSV9_���؂�V���b�^�[�JB,WriteErrAddres)
    WriteAlmstr.T="almSV9_���؂�V���b�^�[�JB"
    Filewritestep=1
end if
if ldp(almSV10_���؂�V���b�^�[��B) then
    adrset(almSV10_���؂�V���b�^�[��B,WriteErrAddres)
    WriteAlmstr.T="almSV10_���؂�V���b�^�[��B"
    Filewritestep=1
end if
if ldp(almSV62_�r���o���u�JB) then
    adrset(almSV62_�r���o���u�JB,WriteErrAddres)
    WriteAlmstr.T="almSV62_�r���o���u�JB"
    Filewritestep=1
end if
if ldp(almSV63_�r���o���u��B) then
    adrset(almSV63_�r���o���u��B,WriteErrAddres)
    WriteAlmstr.T="almSV63_�r���o���u��B"
    Filewritestep=1
end if
if ldp(almXSW79_�r���o���u��B) then
    adrset(almXSW79_�r���o���u��B,WriteErrAddres)
    WriteAlmstr.T="almXSW79_�r���o���u��B"
    Filewritestep=1
end if
if ldp(almFLOS3_LMT121ALM) then
    adrset(almFLOS3_LMT121ALM,WriteErrAddres)
    WriteAlmstr.T="almFLOS3_LMT121ALM"
    Filewritestep=1
end if
if ldp(almFLOS4_LMT121ALM) then
    adrset(almFLOS4_LMT121ALM,WriteErrAddres)
    WriteAlmstr.T="almFLOS4_LMT121ALM"
    Filewritestep=1
end if
if ldp(almFLOS3_LMT121) then
    adrset(almFLOS3_LMT121,WriteErrAddres)
    WriteAlmstr.T="almFLOS3_LMT121"
    Filewritestep=1
end if
if ldp(almFLOS4_LMT121) then
    adrset(almFLOS4_LMT121,WriteErrAddres)
    WriteAlmstr.T="almFLOS4_LMT121"
    Filewritestep=1
end if
if ldp(almAD4532_HI) then
    adrset(almAD4532_HI,WriteErrAddres)
    WriteAlmstr.T="almAD4532_HI"
    Filewritestep=1
end if
if ldp(almAD4532_OK) then
    adrset(almAD4532_OK,WriteErrAddres)
    WriteAlmstr.T="almAD4532_OK"
    Filewritestep=1
end if
if ldp(almAD4532_LO) then
    adrset(almAD4532_LO,WriteErrAddres)
    WriteAlmstr.T="almAD4532_LO"
    Filewritestep=1
end if
if ldp(almTHR11_�������[�^) then
    adrset(almTHR11_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR11_�������[�^"
    Filewritestep=1
end if
if ldp(almXSW18_���t�g�㏸�[) then
    adrset(almXSW18_���t�g�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW18_���t�g�㏸�["
    Filewritestep=1
end if
if ldp(almXSW17_���t�g���~�[) then
    adrset(almXSW17_���t�g���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW17_���t�g���~�["
    Filewritestep=1
end if
if ldp(almPH60_�����m) then
    adrset(almPH60_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH60_�����m"
    Filewritestep=1
end if
if ldp(almPH61_�t�^���m) then
    adrset(almPH61_�t�^���m,WriteErrAddres)
    WriteAlmstr.T="almPH61_�t�^���m"
    Filewritestep=1
end if
if ldp(almAD4532_ZERO) then
    adrset(almAD4532_ZERO,WriteErrAddres)
    WriteAlmstr.T="almAD4532_ZERO"
    Filewritestep=1
end if
if ldp(almAD4532_ON) then
    adrset(almAD4532_ON,WriteErrAddres)
    WriteAlmstr.T="almAD4532_ON"
    Filewritestep=1
end if
if ldp(almAD4532_COMP1) then
    adrset(almAD4532_COMP1,WriteErrAddres)
    WriteAlmstr.T="almAD4532_COMP1"
    Filewritestep=1
end if
if ldp(almAD4532_COMP2) then
    adrset(almAD4532_COMP2,WriteErrAddres)
    WriteAlmstr.T="almAD4532_COMP2"
    Filewritestep=1
end if
if ldp(almSV6_�����d����A) then
    adrset(almSV6_�����d����A,WriteErrAddres)
    WriteAlmstr.T="almSV6_�����d����A"
    Filewritestep=1
end if
if ldp(almSV11_�����d����B) then
    adrset(almSV11_�����d����B,WriteErrAddres)
    WriteAlmstr.T="almSV11_�����d����B"
    Filewritestep=1
end if
if ldp(almSV17_�v���^���N�����i��j) then
    adrset(almSV17_�v���^���N�����i��j,WriteErrAddres)
    WriteAlmstr.T="almSV17_�v���^���N�����i��j"
    Filewritestep=1
end if
if ldp(almSV18_�v���^���N�����i���j) then
    adrset(almSV18_�v���^���N�����i���j,WriteErrAddres)
    WriteAlmstr.T="almSV18_�v���^���N�����i���j"
    Filewritestep=1
end if
if ldp(almSV19_�v���d����_A) then
    adrset(almSV19_�v���d����_A,WriteErrAddres)
    WriteAlmstr.T="almSV19_�v���d����_A"
    Filewritestep=1
end if
if ldp(almSV64_�v���d����_B) then
    adrset(almSV64_�v���d����_B,WriteErrAddres)
    WriteAlmstr.T="almSV64_�v���d����_B"
    Filewritestep=1
end if
if ldp(almTHR6_�������[�^) then
    adrset(almTHR6_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR6_�������[�^"
    Filewritestep=1
end if
if ldp(almTHR7_�������[�^) then
    adrset(almTHR7_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR7_�������[�^"
    Filewritestep=1
end if
if ldp(almTHR8_�������[�^) then
    adrset(almTHR8_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR8_�������[�^"
    Filewritestep=1
end if
if ldp(almPH1_�����m) then
    adrset(almPH1_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH1_�����m"
    Filewritestep=1
end if
if ldp(almPH2_�t�^���m) then
    adrset(almPH2_�t�^���m,WriteErrAddres)
    WriteAlmstr.T="almPH2_�t�^���m"
    Filewritestep=1
end if
if ldp(almPH3_�����m) then
    adrset(almPH3_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH3_�����m"
    Filewritestep=1
end if
if ldp(almPH4_�t�^���m) then
    adrset(almPH4_�t�^���m,WriteErrAddres)
    WriteAlmstr.T="almPH4_�t�^���m"
    Filewritestep=1
end if
if ldp(almPH5_�����m) then
    adrset(almPH5_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH5_�����m"
    Filewritestep=1
end if
if ldp(almPH6_�t�^���m) then
    adrset(almPH6_�t�^���m,WriteErrAddres)
    WriteAlmstr.T="almPH6_�t�^���m"
    Filewritestep=1
end if
if ldp(almPH7_�����m) then
    adrset(almPH7_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH7_�����m"
    Filewritestep=1
end if
if ldp(almPH8_�t�^���m) then
    adrset(almPH8_�t�^���m,WriteErrAddres)
    WriteAlmstr.T="almPH8_�t�^���m"
    Filewritestep=1
end if
if ldp(almXSW14_�X�g�b�p�㏸�[) then
    adrset(almXSW14_�X�g�b�p�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW14_�X�g�b�p�㏸�["
    Filewritestep=1
end if
if ldp(almXSW15_�X�g�b�p���~�[) then
    adrset(almXSW15_�X�g�b�p���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW15_�X�g�b�p���~�["
    Filewritestep=1
end if
if ldp(almXSW16_�X�g�b�p�㏸�[) then
    adrset(almXSW16_�X�g�b�p�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW16_�X�g�b�p�㏸�["
    Filewritestep=1
end if
if ldp(almXSW17_�X�g�b�p���~�[) then
    adrset(almXSW17_�X�g�b�p���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW17_�X�g�b�p���~�["
    Filewritestep=1
end if
if ldp(almMC6_�������[�^) then
    adrset(almMC6_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almMC6_�������[�^"
    Filewritestep=1
end if
if ldp(almMC7_�������[�^) then
    adrset(almMC7_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almMC7_�������[�^"
    Filewritestep=1
end if
if ldp(almMC8_�������[�^) then
    adrset(almMC8_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almMC8_�������[�^"
    Filewritestep=1
end if
if ldp(almSV14_�X�g�b�p�㏸) then
    adrset(almSV14_�X�g�b�p�㏸,WriteErrAddres)
    WriteAlmstr.T="almSV14_�X�g�b�p�㏸"
    Filewritestep=1
end if
if ldp(almSV15_�X�g�b�p���~) then
    adrset(almSV15_�X�g�b�p���~,WriteErrAddres)
    WriteAlmstr.T="almSV15_�X�g�b�p���~"
    Filewritestep=1
end if
if ldp(almSV64_�X�g�b�p�㏸) then
    adrset(almSV64_�X�g�b�p�㏸,WriteErrAddres)
    WriteAlmstr.T="almSV64_�X�g�b�p�㏸"
    Filewritestep=1
end if
if ldp(almSV70_�X�g�b�p���~) then
    adrset(almSV70_�X�g�b�p���~,WriteErrAddres)
    WriteAlmstr.T="almSV70_�X�g�b�p���~"
    Filewritestep=1
end if
if ldp(almSV20_���t�g�㏸) then
    adrset(almSV20_���t�g�㏸,WriteErrAddres)
    WriteAlmstr.T="almSV20_���t�g�㏸"
    Filewritestep=1
end if
if ldp(almMC11_�������[�^) then
    adrset(almMC11_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almMC11_�������[�^"
    Filewritestep=1
end if
if ldp(almSV32_���t�g���~) then
    adrset(almSV32_���t�g���~,WriteErrAddres)
    WriteAlmstr.T="almSV32_���t�g���~"
    Filewritestep=1
end if
if ldp(almTHR9_���[�^���[��) then
    adrset(almTHR9_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR9_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR12_�������[�^) then
    adrset(almTHR12_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR12_�������[�^"
    Filewritestep=1
end if
if ldp(almTHR13_�������[�^) then
    adrset(almTHR13_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR13_�������[�^"
    Filewritestep=1
end if
if ldp(almTHR16_���[�^���[��) then
    adrset(almTHR16_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR16_���[�^���[��"
    Filewritestep=1
end if
if ldp(almPH9_�����m) then
    adrset(almPH9_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH9_�����m"
    Filewritestep=1
end if
if ldp(almPH10_�t�^���m) then
    adrset(almPH10_�t�^���m,WriteErrAddres)
    WriteAlmstr.T="almPH10_�t�^���m"
    Filewritestep=1
end if
if ldp(almPH11_�����m) then
    adrset(almPH11_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH11_�����m"
    Filewritestep=1
end if
if ldp(almPH12_�t�^���m) then
    adrset(almPH12_�t�^���m,WriteErrAddres)
    WriteAlmstr.T="almPH12_�t�^���m"
    Filewritestep=1
end if
if ldp(almPH13_�����m) then
    adrset(almPH13_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH13_�����m"
    Filewritestep=1
end if
if ldp(almPH14_�t�^���m) then
    adrset(almPH14_�t�^���m,WriteErrAddres)
    WriteAlmstr.T="almPH14_�t�^���m"
    Filewritestep=1
end if
if ldp(almPH16_�t�^���m) then
    adrset(almPH16_�t�^���m,WriteErrAddres)
    WriteAlmstr.T="almPH16_�t�^���m"
    Filewritestep=1
end if
if ldp(almPH15_�����m) then
    adrset(almPH15_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH15_�����m"
    Filewritestep=1
end if
if ldp(almXSW18_�X�g�b�p�㏸�[) then
    adrset(almXSW18_�X�g�b�p�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW18_�X�g�b�p�㏸�["
    Filewritestep=1
end if
if ldp(almXSW19_�X�g�b�p���~�[) then
    adrset(almXSW19_�X�g�b�p���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW19_�X�g�b�p���~�["
    Filewritestep=1
end if
if ldp(almXSW21_���t�g�㏸�[) then
    adrset(almXSW21_���t�g�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW21_���t�g�㏸�["
    Filewritestep=1
end if
if ldp(almXSW20_���t�g���~�[) then
    adrset(almXSW20_���t�g���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW20_���t�g���~�["
    Filewritestep=1
end if
if ldp(almMC9_���[�^���[��) then
    adrset(almMC9_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC9_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC12_�������[�^) then
    adrset(almMC12_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almMC12_�������[�^"
    Filewritestep=1
end if
if ldp(almMC13_�������[�^) then
    adrset(almMC13_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almMC13_�������[�^"
    Filewritestep=1
end if
if ldp(almMC16_���[�^���[��) then
    adrset(almMC16_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC16_���[�^���[��"
    Filewritestep=1
end if
if ldp(almSV21_���t�g) then
    adrset(almSV21_���t�g,WriteErrAddres)
    WriteAlmstr.T="almSV21_���t�g"
    Filewritestep=1
end if
if ldp(almSV51_�X�g�b�p) then
    adrset(almSV51_�X�g�b�p,WriteErrAddres)
    WriteAlmstr.T="almSV51_�X�g�b�p"
    Filewritestep=1
end if
if ldp(almSV22_�X�g�b�p) then
    adrset(almSV22_�X�g�b�p,WriteErrAddres)
    WriteAlmstr.T="almSV22_�X�g�b�p"
    Filewritestep=1
end if
if ldp(almSV23_���t�g) then
    adrset(almSV23_���t�g,WriteErrAddres)
    WriteAlmstr.T="almSV23_���t�g"
    Filewritestep=1
end if
if ldp(almMC14_�������[�^) then
    adrset(almMC14_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almMC14_�������[�^"
    Filewritestep=1
end if
if ldp(almMC15_�������[�^) then
    adrset(almMC15_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almMC15_�������[�^"
    Filewritestep=1
end if
if ldp(almMC34_���[�^���[��) then
    adrset(almMC34_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC34_���[�^���[��"
    Filewritestep=1
end if
if ldp(almSV24_�N�����v) then
    adrset(almSV24_�N�����v,WriteErrAddres)
    WriteAlmstr.T="almSV24_�N�����v"
    Filewritestep=1
end if
if ldp(almSV25_�X�g�b�p) then
    adrset(almSV25_�X�g�b�p,WriteErrAddres)
    WriteAlmstr.T="almSV25_�X�g�b�p"
    Filewritestep=1
end if
if ldp(almSV26_�N�����v) then
    adrset(almSV26_�N�����v,WriteErrAddres)
    WriteAlmstr.T="almSV26_�N�����v"
    Filewritestep=1
end if
if ldp(almSV27_�X�g�b�p) then
    adrset(almSV27_�X�g�b�p,WriteErrAddres)
    WriteAlmstr.T="almSV27_�X�g�b�p"
    Filewritestep=1
end if
if ldp(almSV28_���t�g) then
    adrset(almSV28_���t�g,WriteErrAddres)
    WriteAlmstr.T="almSV28_���t�g"
    Filewritestep=1
end if
if ldp(almXSW23_�X�g�b�p�㏸�[) then
    adrset(almXSW23_�X�g�b�p�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW23_�X�g�b�p�㏸�["
    Filewritestep=1
end if
if ldp(almXSW22_�X�g�b�p���~�[) then
    adrset(almXSW22_�X�g�b�p���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW22_�X�g�b�p���~�["
    Filewritestep=1
end if
if ldp(almXSW25_���t�g�㏸�[) then
    adrset(almXSW25_���t�g�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW25_���t�g�㏸�["
    Filewritestep=1
end if
if ldp(almXSW24_���t�g���~�[) then
    adrset(almXSW24_���t�g���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW24_���t�g���~�["
    Filewritestep=1
end if
if ldp(almRLY_����1�d���m�F) then
    adrset(almRLY_����1�d���m�F,WriteErrAddres)
    WriteAlmstr.T="almRLY_����1�d���m�F"
    Filewritestep=1
end if
if ldp(almTHR14_�������[�^) then
    adrset(almTHR14_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR14_�������[�^"
    Filewritestep=1
end if
if ldp(almTHR15_�������[�^) then
    adrset(almTHR15_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR15_�������[�^"
    Filewritestep=1
end if
if ldp(almTHR34_���[�^���[��) then
    adrset(almTHR34_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR34_���[�^���[��"
    Filewritestep=1
end if
if ldp(almPH17_�����m) then
    adrset(almPH17_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH17_�����m"
    Filewritestep=1
end if
if ldp(almPH18_�t�^���m) then
    adrset(almPH18_�t�^���m,WriteErrAddres)
    WriteAlmstr.T="almPH18_�t�^���m"
    Filewritestep=1
end if
if ldp(almPH19_�����m) then
    adrset(almPH19_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH19_�����m"
    Filewritestep=1
end if
if ldp(almPH20_�t�^���m) then
    adrset(almPH20_�t�^���m,WriteErrAddres)
    WriteAlmstr.T="almPH20_�t�^���m"
    Filewritestep=1
end if
if ldp(almPH21_�����m) then
    adrset(almPH21_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH21_�����m"
    Filewritestep=1
end if
if ldp(almPH22_�����m) then
    adrset(almPH22_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH22_�����m"
    Filewritestep=1
end if
if ldp(almXSW26_�N�����v���~�[) then
    adrset(almXSW26_�N�����v���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW26_�N�����v���~�["
    Filewritestep=1
end if
if ldp(almXSW27_�N�����v�㏸�[) then
    adrset(almXSW27_�N�����v�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW27_�N�����v�㏸�["
    Filewritestep=1
end if
if ldp(almSV29_�X�g�b�p) then
    adrset(almSV29_�X�g�b�p,WriteErrAddres)
    WriteAlmstr.T="almSV29_�X�g�b�p"
    Filewritestep=1
end if
if ldp(almMC40_�Ȃ炵���[�^) then
    adrset(almMC40_�Ȃ炵���[�^,WriteErrAddres)
    WriteAlmstr.T="almMC40_�Ȃ炵���[�^"
    Filewritestep=1
end if
if ldp(almSV26_�Ȃ炵�㏸) then
    adrset(almSV26_�Ȃ炵�㏸,WriteErrAddres)
    WriteAlmstr.T="almSV26_�Ȃ炵�㏸"
    Filewritestep=1
end if
if ldp(almSV25_�Ȃ炵���~) then
    adrset(almSV25_�Ȃ炵���~,WriteErrAddres)
    WriteAlmstr.T="almSV25_�Ȃ炵���~"
    Filewritestep=1
end if
if ldp(almSV23_�Ȃ炵�O�i) then
    adrset(almSV23_�Ȃ炵�O�i,WriteErrAddres)
    WriteAlmstr.T="almSV23_�Ȃ炵�O�i"
    Filewritestep=1
end if
if ldp(almSV24_�Ȃ炵���) then
    adrset(almSV24_�Ȃ炵���,WriteErrAddres)
    WriteAlmstr.T="almSV24_�Ȃ炵���"
    Filewritestep=1
end if
if ldp(almSV34_�V�����_�㏸A) then
    adrset(almSV34_�V�����_�㏸A,WriteErrAddres)
    WriteAlmstr.T="almSV34_�V�����_�㏸A"
    Filewritestep=1
end if
if ldp(almSV35_�V�����_���~A) then
    adrset(almSV35_�V�����_���~A,WriteErrAddres)
    WriteAlmstr.T="almSV35_�V�����_���~A"
    Filewritestep=1
end if
if ldp(almSV36_�V�����_�㏸B) then
    adrset(almSV36_�V�����_�㏸B,WriteErrAddres)
    WriteAlmstr.T="almSV36_�V�����_�㏸B"
    Filewritestep=1
end if
if ldp(almSV37_�V�����_���~B) then
    adrset(almSV37_�V�����_���~B,WriteErrAddres)
    WriteAlmstr.T="almSV37_�V�����_���~B"
    Filewritestep=1
end if
if ldp(almSV39_�A���N�����v) then
    adrset(almSV39_�A���N�����v,WriteErrAddres)
    WriteAlmstr.T="almSV39_�A���N�����v"
    Filewritestep=1
end if
if ldp(almSV38_�N�����v) then
    adrset(almSV38_�N�����v,WriteErrAddres)
    WriteAlmstr.T="almSV38_�N�����v"
    Filewritestep=1
end if
if ldp(almMC44_���[�^���[��) then
    adrset(almMC44_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC44_���[�^���[��"
    Filewritestep=1
end if
if ldp(almXSW28_�X�g�b�p���~�[) then
    adrset(almXSW28_�X�g�b�p���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW28_�X�g�b�p���~�["
    Filewritestep=1
end if
if ldp(almXSW29_�X�g�b�p�㏸�[) then
    adrset(almXSW29_�X�g�b�p�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW29_�X�g�b�p�㏸�["
    Filewritestep=1
end if
if ldp(almXSW30_�N�����v���~�[) then
    adrset(almXSW30_�N�����v���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW30_�N�����v���~�["
    Filewritestep=1
end if
if ldp(almXSW31_�N�����v�㏸�[) then
    adrset(almXSW31_�N�����v�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW31_�N�����v�㏸�["
    Filewritestep=1
end if
if ldp(almXSW32_�X�g�b�p���~�[) then
    adrset(almXSW32_�X�g�b�p���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW32_�X�g�b�p���~�["
    Filewritestep=1
end if
if ldp(almXSW33_�X�g�b�p�㏸�[) then
    adrset(almXSW33_�X�g�b�p�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW33_�X�g�b�p�㏸�["
    Filewritestep=1
end if
if ldp(almXSW34_���t�g�㏸�[) then
    adrset(almXSW34_���t�g�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW34_���t�g�㏸�["
    Filewritestep=1
end if
if ldp(almXSW35_���t�g���~�[) then
    adrset(almXSW35_���t�g���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW35_���t�g���~�["
    Filewritestep=1
end if
if ldp(almXSW36_�X�g�b�p���~�[) then
    adrset(almXSW36_�X�g�b�p���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW36_�X�g�b�p���~�["
    Filewritestep=1
end if
if ldp(almXSW37_�X�g�b�p�㏸�[) then
    adrset(almXSW37_�X�g�b�p�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW37_�X�g�b�p�㏸�["
    Filewritestep=1
end if
if ldp(almPS2_�G�A�[����) then
    adrset(almPS2_�G�A�[����,WriteErrAddres)
    WriteAlmstr.T="almPS2_�G�A�[����"
    Filewritestep=1
end if
if ldp(almTHR44_���[�^���[��) then
    adrset(almTHR44_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR44_���[�^���[��"
    Filewritestep=1
end if
if ldp(almPH23_�����m) then
    adrset(almPH23_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH23_�����m"
    Filewritestep=1
end if
if ldp(almPS4_�G�A�[����) then
    adrset(almPS4_�G�A�[����,WriteErrAddres)
    WriteAlmstr.T="almPS4_�G�A�[����"
    Filewritestep=1
end if
if ldp(almMC45_�������[�^) then
    adrset(almMC45_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almMC45_�������[�^"
    Filewritestep=1
end if
if ldp(almMC46_���[�^���[��) then
    adrset(almMC46_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC46_���[�^���[��"
    Filewritestep=1
end if
if ldp(almSV42_�X�g�b�p) then
    adrset(almSV42_�X�g�b�p,WriteErrAddres)
    WriteAlmstr.T="almSV42_�X�g�b�p"
    Filewritestep=1
end if
if ldp(almSV43_���t�g) then
    adrset(almSV43_���t�g,WriteErrAddres)
    WriteAlmstr.T="almSV43_���t�g"
    Filewritestep=1
end if
if ldp(almRLY_���d�Z���T�d��OFF2) then
    adrset(almRLY_���d�Z���T�d��OFF2,WriteErrAddres)
    WriteAlmstr.T="almRLY_���d�Z���T�d��OFF2"
    Filewritestep=1
end if
if ldp(almTHR40_�Ȃ炵���[�^) then
    adrset(almTHR40_�Ȃ炵���[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR40_�Ȃ炵���[�^"
    Filewritestep=1
end if
if ldp(almXSW25_�Ȃ炵�㏸�[) then
    adrset(almXSW25_�Ȃ炵�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW25_�Ȃ炵�㏸�["
    Filewritestep=1
end if
if ldp(almXSW26_�Ȃ炵���~�[) then
    adrset(almXSW26_�Ȃ炵���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW26_�Ȃ炵���~�["
    Filewritestep=1
end if
if ldp(almXSW24_�Ȃ炵�O�i�[) then
    adrset(almXSW24_�Ȃ炵�O�i�[,WriteErrAddres)
    WriteAlmstr.T="almXSW24_�Ȃ炵�O�i�["
    Filewritestep=1
end if
if ldp(almXSW23_�Ȃ炵��ޒ[) then
    adrset(almXSW23_�Ȃ炵��ޒ[,WriteErrAddres)
    WriteAlmstr.T="almXSW23_�Ȃ炵��ޒ["
    Filewritestep=1
end if
if ldp(almXSW44_�Ȃ炵���_�Z���T) then
    adrset(almXSW44_�Ȃ炵���_�Z���T,WriteErrAddres)
    WriteAlmstr.T="almXSW44_�Ȃ炵���_�Z���T"
    Filewritestep=1
end if
if ldp(almXSW39_�V�����_�㏸�[A) then
    adrset(almXSW39_�V�����_�㏸�[A,WriteErrAddres)
    WriteAlmstr.T="almXSW39_�V�����_�㏸�[A"
    Filewritestep=1
end if
if ldp(almXSW40_�V�����_���~�[A) then
    adrset(almXSW40_�V�����_���~�[A,WriteErrAddres)
    WriteAlmstr.T="almXSW40_�V�����_���~�[A"
    Filewritestep=1
end if
if ldp(almXSW41_�V�����_�㏸�[B) then
    adrset(almXSW41_�V�����_�㏸�[B,WriteErrAddres)
    WriteAlmstr.T="almXSW41_�V�����_�㏸�[B"
    Filewritestep=1
end if
if ldp(almXSW42_�V�����_���~�[B) then
    adrset(almXSW42_�V�����_���~�[B,WriteErrAddres)
    WriteAlmstr.T="almXSW42_�V�����_���~�[B"
    Filewritestep=1
end if
if ldp(almXSW44_�A���N�����v) then
    adrset(almXSW44_�A���N�����v,WriteErrAddres)
    WriteAlmstr.T="almXSW44_�A���N�����v"
    Filewritestep=1
end if
if ldp(almXSW43_�N�����v) then
    adrset(almXSW43_�N�����v,WriteErrAddres)
    WriteAlmstr.T="almXSW43_�N�����v"
    Filewritestep=1
end if
if ldp(almTHR45_�������[�^) then
    adrset(almTHR45_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR45_�������[�^"
    Filewritestep=1
end if
if ldp(almTHR46_���[�^���[��) then
    adrset(almTHR46_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR46_���[�^���[��"
    Filewritestep=1
end if
if ldp(almXSW51_�X�g�b�p�㏸�[) then
    adrset(almXSW51_�X�g�b�p�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW51_�X�g�b�p�㏸�["
    Filewritestep=1
end if
if ldp(almXSW52_�X�g�b�p���~�[) then
    adrset(almXSW52_�X�g�b�p���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW52_�X�g�b�p���~�["
    Filewritestep=1
end if
if ldp(almXSW53_���t�g�㏸�[) then
    adrset(almXSW53_���t�g�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW53_���t�g�㏸�["
    Filewritestep=1
end if
if ldp(almXSW54_���t�g���~�[) then
    adrset(almXSW54_���t�g���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW54_���t�g���~�["
    Filewritestep=1
end if
if ldp(almPH24_�����m) then
    adrset(almPH24_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH24_�����m"
    Filewritestep=1
end if
if ldp(almIH���ы@A) then
    adrset(almIH���ы@A,WriteErrAddres)
    WriteAlmstr.T="almIH���ы@A"
    Filewritestep=1
end if
if ldp(almIH���ы@B) then
    adrset(almIH���ы@B,WriteErrAddres)
    WriteAlmstr.T="almIH���ы@B"
    Filewritestep=1
end if
if ldp(almTHR17_���[�^���[��) then
    adrset(almTHR17_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR17_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR18_���[�^���[��) then
    adrset(almTHR18_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR18_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR19_���[�^���[��) then
    adrset(almTHR19_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR19_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR20_���[�^���[��) then
    adrset(almTHR20_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR20_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR21_���[�^���[��) then
    adrset(almTHR21_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR21_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR22_���[�^���[��) then
    adrset(almTHR22_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR22_���[�^���[��"
    Filewritestep=1
end if
if ldp(almPH25_�����m) then
    adrset(almPH25_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH25_�����m"
    Filewritestep=1
end if
if ldp(almPH26_�����m) then
    adrset(almPH26_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH26_�����m"
    Filewritestep=1
end if
if ldp(almPH27_�����m) then
    adrset(almPH27_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH27_�����m"
    Filewritestep=1
end if
if ldp(almPH28_�����m) then
    adrset(almPH28_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH28_�����m"
    Filewritestep=1
end if
if ldp(almPH29_�����m) then
    adrset(almPH29_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH29_�����m"
    Filewritestep=1
end if
if ldp(almPH30_�����m) then
    adrset(almPH30_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH30_�����m"
    Filewritestep=1
end if
if ldp(almRLY_F1A�d���m�F) then
    adrset(almRLY_F1A�d���m�F,WriteErrAddres)
    WriteAlmstr.T="almRLY_F1A�d���m�F"
    Filewritestep=1
end if
if ldp(almMC17_���[�^���[��) then
    adrset(almMC17_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC17_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC18_���[�^���[��) then
    adrset(almMC18_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC18_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC19_���[�^���[��) then
    adrset(almMC19_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC19_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC20_���[�^���[��) then
    adrset(almMC20_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC20_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC21_���[�^���[��) then
    adrset(almMC21_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC21_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC22_���[�^���[��) then
    adrset(almMC22_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC22_���[�^���[��"
    Filewritestep=1
end if
if ldp(almRLY_���d�Z���T�d��OFF3) then
    adrset(almRLY_���d�Z���T�d��OFF3,WriteErrAddres)
    WriteAlmstr.T="almRLY_���d�Z���T�d��OFF3"
    Filewritestep=1
end if
if ldp(almTHR23_���[�^���[��) then
    adrset(almTHR23_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR23_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR24_���[�^���[��) then
    adrset(almTHR24_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR24_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR25_���[�^���[��) then
    adrset(almTHR25_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR25_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR26_���[�^���[��) then
    adrset(almTHR26_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR26_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR27_���[�^���[��) then
    adrset(almTHR27_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR27_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR28_���[�^���[��) then
    adrset(almTHR28_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR28_���[�^���[��"
    Filewritestep=1
end if
if ldp(almPH31_�����m) then
    adrset(almPH31_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH31_�����m"
    Filewritestep=1
end if
if ldp(almPH32_�����m) then
    adrset(almPH32_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH32_�����m"
    Filewritestep=1
end if
if ldp(almPH33_�����m) then
    adrset(almPH33_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH33_�����m"
    Filewritestep=1
end if
if ldp(almPH34_�����m) then
    adrset(almPH34_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH34_�����m"
    Filewritestep=1
end if
if ldp(almPH35_�����m) then
    adrset(almPH35_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH35_�����m"
    Filewritestep=1
end if
if ldp(almPH36_�����m) then
    adrset(almPH36_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH36_�����m"
    Filewritestep=1
end if
if ldp(almRLY_F1B�d���m�F) then
    adrset(almRLY_F1B�d���m�F,WriteErrAddres)
    WriteAlmstr.T="almRLY_F1B�d���m�F"
    Filewritestep=1
end if
if ldp(almMC23_���[�^���[��) then
    adrset(almMC23_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC23_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC24_���[�^���[��) then
    adrset(almMC24_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC24_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC25_���[�^���[��) then
    adrset(almMC25_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC25_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC26_���[�^���[��) then
    adrset(almMC26_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC26_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC27_���[�^���[��) then
    adrset(almMC27_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC27_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC28_���[�^���[��) then
    adrset(almMC28_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC28_���[�^���[��"
    Filewritestep=1
end if
if ldp(almRLY_���d�Z���T�d��OFF4) then
    adrset(almRLY_���d�Z���T�d��OFF4,WriteErrAddres)
    WriteAlmstr.T="almRLY_���d�Z���T�d��OFF4"
    Filewritestep=1
end if
if ldp(almTHR29_���[�^���[��) then
    adrset(almTHR29_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR29_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR30_���[�^���[��) then
    adrset(almTHR30_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR30_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR31_���[�^���[��) then
    adrset(almTHR31_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR31_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR32_���[�^���[��) then
    adrset(almTHR32_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR32_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR33_���[�^���[��) then
    adrset(almTHR33_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR33_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR47_���[�^���[��) then
    adrset(almTHR47_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR47_���[�^���[��"
    Filewritestep=1
end if
if ldp(almPH37_�����m) then
    adrset(almPH37_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH37_�����m"
    Filewritestep=1
end if
if ldp(almPH38_�����m) then
    adrset(almPH38_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH38_�����m"
    Filewritestep=1
end if
if ldp(almPH39_�����m) then
    adrset(almPH39_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH39_�����m"
    Filewritestep=1
end if
if ldp(almPH40_�����m) then
    adrset(almPH40_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH40_�����m"
    Filewritestep=1
end if
if ldp(almPH41_�����m) then
    adrset(almPH41_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH41_�����m"
    Filewritestep=1
end if
if ldp(almPH42_�����m) then
    adrset(almPH42_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH42_�����m"
    Filewritestep=1
end if
if ldp(almRLY_F2A�d���m�F) then
    adrset(almRLY_F2A�d���m�F,WriteErrAddres)
    WriteAlmstr.T="almRLY_F2A�d���m�F"
    Filewritestep=1
end if
if ldp(almMC29_���[�^���[��) then
    adrset(almMC29_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC29_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC30_���[�^���[��) then
    adrset(almMC30_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC30_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC31_���[�^���[��) then
    adrset(almMC31_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC31_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC32_���[�^���[��) then
    adrset(almMC32_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC32_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC33_���[�^���[��) then
    adrset(almMC33_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC33_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC47_���[�^���[��) then
    adrset(almMC47_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC47_���[�^���[��"
    Filewritestep=1
end if
if ldp(almRLY_���d�Z���T�d��OFF5) then
    adrset(almRLY_���d�Z���T�d��OFF5,WriteErrAddres)
    WriteAlmstr.T="almRLY_���d�Z���T�d��OFF5"
    Filewritestep=1
end if
if ldp(almTHR48_���[�^���[��) then
    adrset(almTHR48_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR48_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR49_���[�^���[��) then
    adrset(almTHR49_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR49_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR50_���[�^���[��) then
    adrset(almTHR50_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR50_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR51_���[�^���[��) then
    adrset(almTHR51_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR51_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR52_���[�^���[��) then
    adrset(almTHR52_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR52_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR53_���[�^���[��) then
    adrset(almTHR53_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR53_���[�^���[��"
    Filewritestep=1
end if
if ldp(almPH43_�����m) then
    adrset(almPH43_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH43_�����m"
    Filewritestep=1
end if
if ldp(almPH44_�����m) then
    adrset(almPH44_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH44_�����m"
    Filewritestep=1
end if
if ldp(almPH45_�����m) then
    adrset(almPH45_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH45_�����m"
    Filewritestep=1
end if
if ldp(almPH46_�����m) then
    adrset(almPH46_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH46_�����m"
    Filewritestep=1
end if
if ldp(almPH47_�����m) then
    adrset(almPH47_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH47_�����m"
    Filewritestep=1
end if
if ldp(almPH48_�����m) then
    adrset(almPH48_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH48_�����m"
    Filewritestep=1
end if
if ldp(almRLY_F2B�d���m�F) then
    adrset(almRLY_F2B�d���m�F,WriteErrAddres)
    WriteAlmstr.T="almRLY_F2B�d���m�F"
    Filewritestep=1
end if
if ldp(almMC48_���[�^���[��) then
    adrset(almMC48_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC48_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC49_���[�^���[��) then
    adrset(almMC49_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC49_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC50_���[�^���[��) then
    adrset(almMC50_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC50_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC51_���[�^���[��) then
    adrset(almMC51_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC51_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC52_���[�^���[��) then
    adrset(almMC52_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC52_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC53_���[�^���[��) then
    adrset(almMC53_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC53_���[�^���[��"
    Filewritestep=1
end if
if ldp(almRLY_���d�Z���T�d��OFF6) then
    adrset(almRLY_���d�Z���T�d��OFF6,WriteErrAddres)
    WriteAlmstr.T="almRLY_���d�Z���T�d��OFF6"
    Filewritestep=1
end if
if ldp(almTHR41_���[�^���[��) then
    adrset(almTHR41_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR41_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR42_���[�^���[��) then
    adrset(almTHR42_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR42_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR43_�������[�^) then
    adrset(almTHR43_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR43_�������[�^"
    Filewritestep=1
end if
if ldp(almPH49_�����m) then
    adrset(almPH49_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH49_�����m"
    Filewritestep=1
end if
if ldp(almPH50_�����m) then
    adrset(almPH50_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH50_�����m"
    Filewritestep=1
end if
if ldp(almPH51_�����m) then
    adrset(almPH51_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH51_�����m"
    Filewritestep=1
end if
if ldp(almPH52_�t�^���m) then
    adrset(almPH52_�t�^���m,WriteErrAddres)
    WriteAlmstr.T="almPH52_�t�^���m"
    Filewritestep=1
end if
if ldp(almXSW55_���t�g�㏸�[) then
    adrset(almXSW55_���t�g�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW55_���t�g�㏸�["
    Filewritestep=1
end if
if ldp(almXSW56_���t�g���~�[) then
    adrset(almXSW56_���t�g���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW56_���t�g���~�["
    Filewritestep=1
end if
if ldp(almXSW57_���t�g�㏸�[) then
    adrset(almXSW57_���t�g�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW57_���t�g�㏸�["
    Filewritestep=1
end if
if ldp(almXSW58_���t�g���~�[) then
    adrset(almXSW58_���t�g���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW58_���t�g���~�["
    Filewritestep=1
end if
if ldp(almXSW59_�X�g�b�p�㏸�[) then
    adrset(almXSW59_�X�g�b�p�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW59_�X�g�b�p�㏸�["
    Filewritestep=1
end if
if ldp(almXSW60_�X�g�b�p���~�[) then
    adrset(almXSW60_�X�g�b�p���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW60_�X�g�b�p���~�["
    Filewritestep=1
end if
if ldp(almXSW61_�X�g�b�p�㏸�[) then
    adrset(almXSW61_�X�g�b�p�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW61_�X�g�b�p�㏸�["
    Filewritestep=1
end if
if ldp(almXSW62_�X�g�b�p���~�[) then
    adrset(almXSW62_�X�g�b�p���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW62_�X�g�b�p���~�["
    Filewritestep=1
end if
if ldp(almXSW63_�X�g�b�p�㏸�[) then
    adrset(almXSW63_�X�g�b�p�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW63_�X�g�b�p�㏸�["
    Filewritestep=1
end if
if ldp(almMC41_���[�^���[��) then
    adrset(almMC41_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC41_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC42_���[�^���[��) then
    adrset(almMC42_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC42_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC43_�������[�^) then
    adrset(almMC43_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almMC43_�������[�^"
    Filewritestep=1
end if
if ldp(almSV44_�X�g�b�p) then
    adrset(almSV44_�X�g�b�p,WriteErrAddres)
    WriteAlmstr.T="almSV44_�X�g�b�p"
    Filewritestep=1
end if
if ldp(almSV45_�X�g�b�p) then
    adrset(almSV45_�X�g�b�p,WriteErrAddres)
    WriteAlmstr.T="almSV45_�X�g�b�p"
    Filewritestep=1
end if
if ldp(almSV46_�X�g�b�p) then
    adrset(almSV46_�X�g�b�p,WriteErrAddres)
    WriteAlmstr.T="almSV46_�X�g�b�p"
    Filewritestep=1
end if
if ldp(almSV47_���t�g) then
    adrset(almSV47_���t�g,WriteErrAddres)
    WriteAlmstr.T="almSV47_���t�g"
    Filewritestep=1
end if
if ldp(almSV48_���t�g) then
    adrset(almSV48_���t�g,WriteErrAddres)
    WriteAlmstr.T="almSV48_���t�g"
    Filewritestep=1
end if
if ldp(almMC54_���[�^���[��) then
    adrset(almMC54_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almMC54_���[�^���[��"
    Filewritestep=1
end if
if ldp(almMC10_�������[�^���]) then
    adrset(almMC10_�������[�^���],WriteErrAddres)
    WriteAlmstr.T="almMC10_�������[�^���]"
    Filewritestep=1
end if
if ldp(almMC10_�������[�^�t�]) then
    adrset(almMC10_�������[�^�t�],WriteErrAddres)
    WriteAlmstr.T="almMC10_�������[�^�t�]"
    Filewritestep=1
end if
if ldp(almMC55_�������[�^) then
    adrset(almMC55_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almMC55_�������[�^"
    Filewritestep=1
end if
if ldp(almSV49_�X�g�b�p) then
    adrset(almSV49_�X�g�b�p,WriteErrAddres)
    WriteAlmstr.T="almSV49_�X�g�b�p"
    Filewritestep=1
end if
if ldp(almSV50_���t�g) then
    adrset(almSV50_���t�g,WriteErrAddres)
    WriteAlmstr.T="almSV50_���t�g"
    Filewritestep=1
end if
if ldp(almXSW64_�X�g�b�p���~�[) then
    adrset(almXSW64_�X�g�b�p���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW64_�X�g�b�p���~�["
    Filewritestep=1
end if
if ldp(almPS3_�G�A�[����) then
    adrset(almPS3_�G�A�[����,WriteErrAddres)
    WriteAlmstr.T="almPS3_�G�A�[����"
    Filewritestep=1
end if
if ldp(almTHR54_���[�^���[��) then
    adrset(almTHR54_���[�^���[��,WriteErrAddres)
    WriteAlmstr.T="almTHR54_���[�^���[��"
    Filewritestep=1
end if
if ldp(almTHR10_�������[�^) then
    adrset(almTHR10_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR10_�������[�^"
    Filewritestep=1
end if
if ldp(almTHR55_�������[�^) then
    adrset(almTHR55_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR55_�������[�^"
    Filewritestep=1
end if
if ldp(almPH53_�����m) then
    adrset(almPH53_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH53_�����m"
    Filewritestep=1
end if
if ldp(almPH54_�t�^���m) then
    adrset(almPH54_�t�^���m,WriteErrAddres)
    WriteAlmstr.T="almPH54_�t�^���m"
    Filewritestep=1
end if
if ldp(almXSW65_�X�g�b�p�㏸�[) then
    adrset(almXSW65_�X�g�b�p�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW65_�X�g�b�p�㏸�["
    Filewritestep=1
end if
if ldp(almXSW66_�X�g�b�p���~�[) then
    adrset(almXSW66_�X�g�b�p���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW66_�X�g�b�p���~�["
    Filewritestep=1
end if
if ldp(almXSW67_���t�g�㏸�[) then
    adrset(almXSW67_���t�g�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW67_���t�g�㏸�["
    Filewritestep=1
end if
if ldp(almXSW68_���t�g���~�[) then
    adrset(almXSW68_���t�g���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW68_���t�g���~�["
    Filewritestep=1
end if
if ldp(almRLY_����2�d���m�F) then
    adrset(almRLY_����2�d���m�F,WriteErrAddres)
    WriteAlmstr.T="almRLY_����2�d���m�F"
    Filewritestep=1
end if
if ldp(almTHR56_�u���V�T�[�}��) then
    adrset(almTHR56_�u���V�T�[�}��,WriteErrAddres)
    WriteAlmstr.T="almTHR56_�u���V�T�[�}��"
    Filewritestep=1
end if
if ldp(almXSW69_�u���V�㏸�[) then
    adrset(almXSW69_�u���V�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW69_�u���V�㏸�["
    Filewritestep=1
end if
if ldp(almXSW70_�u���V���~�[) then
    adrset(almXSW70_�u���V���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW70_�u���V���~�["
    Filewritestep=1
end if
if ldp(almSV45_�V�����_�㏸A) then
    adrset(almSV45_�V�����_�㏸A,WriteErrAddres)
    WriteAlmstr.T="almSV45_�V�����_�㏸A"
    Filewritestep=1
end if
if ldp(almSV46_�V�����_���~A) then
    adrset(almSV46_�V�����_���~A,WriteErrAddres)
    WriteAlmstr.T="almSV46_�V�����_���~A"
    Filewritestep=1
end if
if ldp(almSV47_�V�����_�㏸B) then
    adrset(almSV47_�V�����_�㏸B,WriteErrAddres)
    WriteAlmstr.T="almSV47_�V�����_�㏸B"
    Filewritestep=1
end if
if ldp(almSV48_�V�����_���~B) then
    adrset(almSV48_�V�����_���~B,WriteErrAddres)
    WriteAlmstr.T="almSV48_�V�����_���~B"
    Filewritestep=1
end if
if ldp(almSV49_�A���N�����v) then
    adrset(almSV49_�A���N�����v,WriteErrAddres)
    WriteAlmstr.T="almSV49_�A���N�����v"
    Filewritestep=1
end if
if ldp(almSV50_�N�����v) then
    adrset(almSV50_�N�����v,WriteErrAddres)
    WriteAlmstr.T="almSV50_�N�����v"
    Filewritestep=1
end if
if ldp(almMC57_�������[�^) then
    adrset(almMC57_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almMC57_�������[�^"
    Filewritestep=1
end if
if ldp(almSV59_���t�g�㏸) then
    adrset(almSV59_���t�g�㏸,WriteErrAddres)
    WriteAlmstr.T="almSV59_���t�g�㏸"
    Filewritestep=1
end if
if ldp(almMC56_�u���V���[�^) then
    adrset(almMC56_�u���V���[�^,WriteErrAddres)
    WriteAlmstr.T="almMC56_�u���V���[�^"
    Filewritestep=1
end if
if ldp(almSV65_�V�����_�㏸) then
    adrset(almSV65_�V�����_�㏸,WriteErrAddres)
    WriteAlmstr.T="almSV65_�V�����_�㏸"
    Filewritestep=1
end if
if ldp(almSV66_�V�����_���~) then
    adrset(almSV66_�V�����_���~,WriteErrAddres)
    WriteAlmstr.T="almSV66_�V�����_���~"
    Filewritestep=1
end if
if ldp(almSV76_���t�g���~) then
    adrset(almSV76_���t�g���~,WriteErrAddres)
    WriteAlmstr.T="almSV76_���t�g���~"
    Filewritestep=1
end if
if ldp(almRLY_���d�Z���T�d��OFF7) then
    adrset(almRLY_���d�Z���T�d��OFF7,WriteErrAddres)
    WriteAlmstr.T="almRLY_���d�Z���T�d��OFF7"
    Filewritestep=1
end if
if ldp(almXSW55_�V�����_�㏸�[A) then
    adrset(almXSW55_�V�����_�㏸�[A,WriteErrAddres)
    WriteAlmstr.T="almXSW55_�V�����_�㏸�[A"
    Filewritestep=1
end if
if ldp(almXSW56_�V�����_���~�[A) then
    adrset(almXSW56_�V�����_���~�[A,WriteErrAddres)
    WriteAlmstr.T="almXSW56_�V�����_���~�[A"
    Filewritestep=1
end if
if ldp(almXSW57_�V�����_�㏸�[B) then
    adrset(almXSW57_�V�����_�㏸�[B,WriteErrAddres)
    WriteAlmstr.T="almXSW57_�V�����_�㏸�[B"
    Filewritestep=1
end if
if ldp(almXSW58_�V�����_���~�[B) then
    adrset(almXSW58_�V�����_���~�[B,WriteErrAddres)
    WriteAlmstr.T="almXSW58_�V�����_���~�[B"
    Filewritestep=1
end if
if ldp(almXSW59_�A���N�����v) then
    adrset(almXSW59_�A���N�����v,WriteErrAddres)
    WriteAlmstr.T="almXSW59_�A���N�����v"
    Filewritestep=1
end if
if ldp(almXSW60_�N�����v) then
    adrset(almXSW60_�N�����v,WriteErrAddres)
    WriteAlmstr.T="almXSW60_�N�����v"
    Filewritestep=1
end if
if ldp(almTHR57_�������[�^) then
    adrset(almTHR57_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR57_�������[�^"
    Filewritestep=1
end if
if ldp(almXSW80_���t�g�㏸�[) then
    adrset(almXSW80_���t�g�㏸�[,WriteErrAddres)
    WriteAlmstr.T="almXSW80_���t�g�㏸�["
    Filewritestep=1
end if
if ldp(almXSW81_���t�g���~�[) then
    adrset(almXSW81_���t�g���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW81_���t�g���~�["
    Filewritestep=1
end if
if ldp(almPH55_�����m) then
    adrset(almPH55_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH55_�����m"
    Filewritestep=1
end if
if ldp(almPH56_�t�^���m) then
    adrset(almPH56_�t�^���m,WriteErrAddres)
    WriteAlmstr.T="almPH56_�t�^���m"
    Filewritestep=1
end if
if ldp(almPH67_�����m) then
    adrset(almPH67_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH67_�����m"
    Filewritestep=1
end if
if ldp(almPH68_�����m) then
    adrset(almPH68_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH68_�����m"
    Filewritestep=1
end if
if ldp(almPH69_�t�^���m) then
    adrset(almPH69_�t�^���m,WriteErrAddres)
    WriteAlmstr.T="almPH69_�t�^���m"
    Filewritestep=1
end if
if ldp(almRLY_���]�@�d���m�F) then
    adrset(almRLY_���]�@�d���m�F,WriteErrAddres)
    WriteAlmstr.T="almRLY_���]�@�d���m�F"
    Filewritestep=1
end if
if ldp(alm�������\�M��_A) then
    adrset(alm�������\�M��_A,WriteErrAddres)
    WriteAlmstr.T="alm�������\�M��_A"
    Filewritestep=1
end if
if ldp(alm���]�@���]�����M��_A) then
    adrset(alm���]�@���]�����M��_A,WriteErrAddres)
    WriteAlmstr.T="alm���]�@���]�����M��_A"
    Filewritestep=1
end if
if ldp(alm���]�@�ُ�M��_A) then
    adrset(alm���]�@�ُ�M��_A,WriteErrAddres)
    WriteAlmstr.T="alm���]�@�ُ�M��_A"
    Filewritestep=1
end if
if ldp(alm���]�@�^�]�w��_A) then
    adrset(alm���]�@�^�]�w��_A,WriteErrAddres)
    WriteAlmstr.T="alm���]�@�^�]�w��_A"
    Filewritestep=1
end if
if ldp(alm���]�@��~�w��_A) then
    adrset(alm���]�@��~�w��_A,WriteErrAddres)
    WriteAlmstr.T="alm���]�@��~�w��_A"
    Filewritestep=1
end if
if ldp(almRLY_�T�u1�d���m�F) then
    adrset(almRLY_�T�u1�d���m�F,WriteErrAddres)
    WriteAlmstr.T="almRLY_�T�u1�d���m�F"
    Filewritestep=1
end if
if ldp(almPTL3_�p�g���C�g��) then
    adrset(almPTL3_�p�g���C�g��,WriteErrAddres)
    WriteAlmstr.T="almPTL3_�p�g���C�g��"
    Filewritestep=1
end if
if ldp(almPTL3_�p�g���C�g��) then
    adrset(almPTL3_�p�g���C�g��,WriteErrAddres)
    WriteAlmstr.T="almPTL3_�p�g���C�g��"
    Filewritestep=1
end if
if ldp(almPTL3_�p�g���C�g��) then
    adrset(almPTL3_�p�g���C�g��,WriteErrAddres)
    WriteAlmstr.T="almPTL3_�p�g���C�g��"
    Filewritestep=1
end if
if ldp(almPTL3_�p�g���C�g�u�U�[) then
    adrset(almPTL3_�p�g���C�g�u�U�[,WriteErrAddres)
    WriteAlmstr.T="almPTL3_�p�g���C�g�u�U�["
    Filewritestep=1
end if
if ldp(almRLY_�T�u2�d���m�F) then
    adrset(almRLY_�T�u2�d���m�F,WriteErrAddres)
    WriteAlmstr.T="almRLY_�T�u2�d���m�F"
    Filewritestep=1
end if
if ldp(almPTL4_�p�g���C�g��) then
    adrset(almPTL4_�p�g���C�g��,WriteErrAddres)
    WriteAlmstr.T="almPTL4_�p�g���C�g��"
    Filewritestep=1
end if
if ldp(almPTL4_�p�g���C�g��) then
    adrset(almPTL4_�p�g���C�g��,WriteErrAddres)
    WriteAlmstr.T="almPTL4_�p�g���C�g��"
    Filewritestep=1
end if
if ldp(almPTL4_�p�g���C�g��) then
    adrset(almPTL4_�p�g���C�g��,WriteErrAddres)
    WriteAlmstr.T="almPTL4_�p�g���C�g��"
    Filewritestep=1
end if
if ldp(almPTL4_�p�g���C�g�u�U�[) then
    adrset(almPTL4_�p�g���C�g�u�U�[,WriteErrAddres)
    WriteAlmstr.T="almPTL4_�p�g���C�g�u�U�["
    Filewritestep=1
end if
if ldp(almSEL2_1_�^�]�؊��i�P���j) then
    adrset(almSEL2_1_�^�]�؊��i�P���j,WriteErrAddres)
    WriteAlmstr.T="almSEL2_1_�^�]�؊��i�P���j"
    Filewritestep=1
end if
if ldp(almSEL2_2_�^�]�؊��i�A���j) then
    adrset(almSEL2_2_�^�]�؊��i�A���j,WriteErrAddres)
    WriteAlmstr.T="almSEL2_2_�^�]�؊��i�A���j"
    Filewritestep=1
end if
if ldp(almTHR35_�������[�^) then
    adrset(almTHR35_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR35_�������[�^"
    Filewritestep=1
end if
if ldp(almTHR36_���]���[�^) then
    adrset(almTHR36_���]���[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR36_���]���[�^"
    Filewritestep=1
end if
if ldp(almPS5_�G�A�[����) then
    adrset(almPS5_�G�A�[����,WriteErrAddres)
    WriteAlmstr.T="almPS5_�G�A�[����"
    Filewritestep=1
end if
if ldp(almTHR58_���|���vA) then
    adrset(almTHR58_���|���vA,WriteErrAddres)
    WriteAlmstr.T="almTHR58_���|���vA"
    Filewritestep=1
end if
if ldp(almTHR59_���|���vB) then
    adrset(almTHR59_���|���vB,WriteErrAddres)
    WriteAlmstr.T="almTHR59_���|���vB"
    Filewritestep=1
end if
if ldp(almTHR60_���|���vC) then
    adrset(almTHR60_���|���vC,WriteErrAddres)
    WriteAlmstr.T="almTHR60_���|���vC"
    Filewritestep=1
end if
if ldp(almTHR61_���|���vD) then
    adrset(almTHR61_���|���vD,WriteErrAddres)
    WriteAlmstr.T="almTHR61_���|���vD"
    Filewritestep=1
end if
if ldp(almMC1_�C���o�[�^�p�d��) then
    adrset(almMC1_�C���o�[�^�p�d��,WriteErrAddres)
    WriteAlmstr.T="almMC1_�C���o�[�^�p�d��"
    Filewritestep=1
end if
if ldp(almMC35_�������[�^) then
    adrset(almMC35_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almMC35_�������[�^"
    Filewritestep=1
end if
if ldp(almMC36_���]���[�^���]) then
    adrset(almMC36_���]���[�^���],WriteErrAddres)
    WriteAlmstr.T="almMC36_���]���[�^���]"
    Filewritestep=1
end if
if ldp(almMC36_���]���[�^�t�]) then
    adrset(almMC36_���]���[�^�t�],WriteErrAddres)
    WriteAlmstr.T="almMC36_���]���[�^�t�]"
    Filewritestep=1
end if
if ldp(almINV1_�R���x�A���[�^���]) then
    adrset(almINV1_�R���x�A���[�^���],WriteErrAddres)
    WriteAlmstr.T="almINV1_�R���x�A���[�^���]"
    Filewritestep=1
end if
if ldp(almINV2_�R���x�A���[�^���]) then
    adrset(almINV2_�R���x�A���[�^���],WriteErrAddres)
    WriteAlmstr.T="almINV2_�R���x�A���[�^���]"
    Filewritestep=1
end if
if ldp(almINV3_�R���x�A���[�^���]) then
    adrset(almINV3_�R���x�A���[�^���],WriteErrAddres)
    WriteAlmstr.T="almINV3_�R���x�A���[�^���]"
    Filewritestep=1
end if
if ldp(almMC58_���|���vA) then
    adrset(almMC58_���|���vA,WriteErrAddres)
    WriteAlmstr.T="almMC58_���|���vA"
    Filewritestep=1
end if
if ldp(almMC59_���|���vB) then
    adrset(almMC59_���|���vB,WriteErrAddres)
    WriteAlmstr.T="almMC59_���|���vB"
    Filewritestep=1
end if
if ldp(almMC60_���|���vC) then
    adrset(almMC60_���|���vC,WriteErrAddres)
    WriteAlmstr.T="almMC60_���|���vC"
    Filewritestep=1
end if
if ldp(almMC61_���|���vD) then
    adrset(almMC61_���|���vD,WriteErrAddres)
    WriteAlmstr.T="almMC61_���|���vD"
    Filewritestep=1
end if
if ldp(almTHR38_�������[�^) then
    adrset(almTHR38_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR38_�������[�^"
    Filewritestep=1
end if
if ldp(almTHR37_���]���[�^) then
    adrset(almTHR37_���]���[�^,WriteErrAddres)
    WriteAlmstr.T="almTHR37_���]���[�^"
    Filewritestep=1
end if
if ldp(almRLY_���@�d���m�F) then
    adrset(almRLY_���@�d���m�F,WriteErrAddres)
    WriteAlmstr.T="almRLY_���@�d���m�F"
    Filewritestep=1
end if
if ldp(almPH57_�����m) then
    adrset(almPH57_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH57_�����m"
    Filewritestep=1
end if
if ldp(almPH58_�t�^���m) then
    adrset(almPH58_�t�^���m,WriteErrAddres)
    WriteAlmstr.T="almPH58_�t�^���m"
    Filewritestep=1
end if
if ldp(almLS7_�����]�@���_�ʒu) then
    adrset(almLS7_�����]�@���_�ʒu,WriteErrAddres)
    WriteAlmstr.T="almLS7_�����]�@���_�ʒu"
    Filewritestep=1
end if
if ldp(almLS8_�����]�@���]�ʒu) then
    adrset(almLS8_�����]�@���]�ʒu,WriteErrAddres)
    WriteAlmstr.T="almLS8_�����]�@���]�ʒu"
    Filewritestep=1
end if
if ldp(almPH59_�����m) then
    adrset(almPH59_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH59_�����m"
    Filewritestep=1
end if
if ldp(almPH62_�t�^���m) then
    adrset(almPH62_�t�^���m,WriteErrAddres)
    WriteAlmstr.T="almPH62_�t�^���m"
    Filewritestep=1
end if
if ldp(almPH63_�����m) then
    adrset(almPH63_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH63_�����m"
    Filewritestep=1
end if
if ldp(almPH64_�t�^���m) then
    adrset(almPH64_�t�^���m,WriteErrAddres)
    WriteAlmstr.T="almPH64_�t�^���m"
    Filewritestep=1
end if
if ldp(almMC37_���]���[�^�t�]) then
    adrset(almMC37_���]���[�^�t�],WriteErrAddres)
    WriteAlmstr.T="almMC37_���]���[�^�t�]"
    Filewritestep=1
end if
if ldp(almMC37_���]���[�^���]) then
    adrset(almMC37_���]���[�^���],WriteErrAddres)
    WriteAlmstr.T="almMC37_���]���[�^���]"
    Filewritestep=1
end if
if ldp(almMC38_�������[�^) then
    adrset(almMC38_�������[�^,WriteErrAddres)
    WriteAlmstr.T="almMC38_�������[�^"
    Filewritestep=1
end if
if ldp(almSV97_�������d����) then
    adrset(almSV97_�������d����,WriteErrAddres)
    WriteAlmstr.T="almSV97_�������d����"
    Filewritestep=1
end if
if ldp(almSV98_�d�グ�d����) then
    adrset(almSV98_�d�グ�d����,WriteErrAddres)
    WriteAlmstr.T="almSV98_�d�グ�d����"
    Filewritestep=1
end if
if ldp(almPTL5_�p�g���C�g��) then
    adrset(almPTL5_�p�g���C�g��,WriteErrAddres)
    WriteAlmstr.T="almPTL5_�p�g���C�g��"
    Filewritestep=1
end if
if ldp(almPTL5_�p�g���C�g��) then
    adrset(almPTL5_�p�g���C�g��,WriteErrAddres)
    WriteAlmstr.T="almPTL5_�p�g���C�g��"
    Filewritestep=1
end if
if ldp(almPTL5_�p�g���C�g��) then
    adrset(almPTL5_�p�g���C�g��,WriteErrAddres)
    WriteAlmstr.T="almPTL5_�p�g���C�g��"
    Filewritestep=1
end if
if ldp(almPTL5_�p�g���C�g�u�U�[) then
    adrset(almPTL5_�p�g���C�g�u�U�[,WriteErrAddres)
    WriteAlmstr.T="almPTL5_�p�g���C�g�u�U�["
    Filewritestep=1
end if
if ldp(almSV69_�����d����) then
    adrset(almSV69_�����d����,WriteErrAddres)
    WriteAlmstr.T="almSV69_�����d����"
    Filewritestep=1
end if
if ldp(almSV75_�����d����) then
    adrset(almSV75_�����d����,WriteErrAddres)
    WriteAlmstr.T="almSV75_�����d����"
    Filewritestep=1
end if
if ldp(almMC_HT1_�^���N�q�[�^) then
    adrset(almMC_HT1_�^���N�q�[�^,WriteErrAddres)
    WriteAlmstr.T="almMC_HT1_�^���N�q�[�^"
    Filewritestep=1
end if
if ldp(almMC_HT2_�^���N�q�[�^) then
    adrset(almMC_HT2_�^���N�q�[�^,WriteErrAddres)
    WriteAlmstr.T="almMC_HT2_�^���N�q�[�^"
    Filewritestep=1
end if
if ldp(almMC_HT3_�^���N�q�[�^) then
    adrset(almMC_HT3_�^���N�q�[�^,WriteErrAddres)
    WriteAlmstr.T="almMC_HT3_�^���N�q�[�^"
    Filewritestep=1
end if
if ldp(almMC_HT4_�^���N�q�[�^) then
    adrset(almMC_HT4_�^���N�q�[�^,WriteErrAddres)
    WriteAlmstr.T="almMC_HT4_�^���N�q�[�^"
    Filewritestep=1
end if
if ldp(almLS5_�󊘔��]���_�ʒu) then
    adrset(almLS5_�󊘔��]���_�ʒu,WriteErrAddres)
    WriteAlmstr.T="almLS5_�󊘔��]���_�ʒu"
    Filewritestep=1
end if
if ldp(almLS6_�󊘔��]���]�ʒu) then
    adrset(almLS6_�󊘔��]���]�ʒu,WriteErrAddres)
    WriteAlmstr.T="almLS6_�󊘔��]���]�ʒu"
    Filewritestep=1
end if
if ldp(almPH65_�����m) then
    adrset(almPH65_�����m,WriteErrAddres)
    WriteAlmstr.T="almPH65_�����m"
    Filewritestep=1
end if
if ldp(almPH66_�t�^���m) then
    adrset(almPH66_�t�^���m,WriteErrAddres)
    WriteAlmstr.T="almPH66_�t�^���m"
    Filewritestep=1
end if
if ldp(almXSW81_���t�^�������㏸�[A) then
    adrset(almXSW81_���t�^�������㏸�[A,WriteErrAddres)
    WriteAlmstr.T="almXSW81_���t�^�������㏸�[A"
    Filewritestep=1
end if
if ldp(almXSW82_���t�^���������~�[A) then
    adrset(almXSW82_���t�^���������~�[A,WriteErrAddres)
    WriteAlmstr.T="almXSW82_���t�^���������~�[A"
    Filewritestep=1
end if
if ldp(almXSW83_���t�^�������㏸�[B) then
    adrset(almXSW83_���t�^�������㏸�[B,WriteErrAddres)
    WriteAlmstr.T="almXSW83_���t�^�������㏸�[B"
    Filewritestep=1
end if
if ldp(almXSW84_���t�^���������~�[B) then
    adrset(almXSW84_���t�^���������~�[B,WriteErrAddres)
    WriteAlmstr.T="almXSW84_���t�^���������~�[B"
    Filewritestep=1
end if
if ldp(almXSW85_���t�^�X�g�b�p���~�[) then
    adrset(almXSW85_���t�^�X�g�b�p���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW85_���t�^�X�g�b�p���~�["
    Filewritestep=1
end if
if ldp(almINV10_���|���vA�ُ�) then
    adrset(almINV10_���|���vA�ُ�,WriteErrAddres)
    WriteAlmstr.T="almINV10_���|���vA�ُ�"
    Filewritestep=1
end if
if ldp(almFLT1_�^���N���) then
    adrset(almFLT1_�^���N���,WriteErrAddres)
    WriteAlmstr.T="almFLT1_�^���N���"
    Filewritestep=1
end if
if ldp(almFLT2_�^���N����) then
    adrset(almFLT2_�^���N����,WriteErrAddres)
    WriteAlmstr.T="almFLT2_�^���N����"
    Filewritestep=1
end if
if ldp(almXSW86_���t�^�������㏸�[A) then
    adrset(almXSW86_���t�^�������㏸�[A,WriteErrAddres)
    WriteAlmstr.T="almXSW86_���t�^�������㏸�[A"
    Filewritestep=1
end if
if ldp(almXSW87_���t�^���������~�[A) then
    adrset(almXSW87_���t�^���������~�[A,WriteErrAddres)
    WriteAlmstr.T="almXSW87_���t�^���������~�[A"
    Filewritestep=1
end if
if ldp(almXSW88_���t�^�������㏸�[B) then
    adrset(almXSW88_���t�^�������㏸�[B,WriteErrAddres)
    WriteAlmstr.T="almXSW88_���t�^�������㏸�[B"
    Filewritestep=1
end if
if ldp(almXSW89_���t�^���������~�[B) then
    adrset(almXSW89_���t�^���������~�[B,WriteErrAddres)
    WriteAlmstr.T="almXSW89_���t�^���������~�[B"
    Filewritestep=1
end if
if ldp(almSV81_�����d����) then
    adrset(almSV81_�����d����,WriteErrAddres)
    WriteAlmstr.T="almSV81_�����d����"
    Filewritestep=1
end if
if ldp(almSV87_�����d����) then
    adrset(almSV87_�����d����,WriteErrAddres)
    WriteAlmstr.T="almSV87_�����d����"
    Filewritestep=1
end if
if ldp(almSV72_�����d����) then
    adrset(almSV72_�����d����,WriteErrAddres)
    WriteAlmstr.T="almSV72_�����d����"
    Filewritestep=1
end if
if ldp(almSV78_�����d����) then
    adrset(almSV78_�����d����,WriteErrAddres)
    WriteAlmstr.T="almSV78_�����d����"
    Filewritestep=1
end if
if ldp(almSV84_�����d����) then
    adrset(almSV84_�����d����,WriteErrAddres)
    WriteAlmstr.T="almSV84_�����d����"
    Filewritestep=1
end if
if ldp(almSV90_�����d����) then
    adrset(almSV90_�����d����,WriteErrAddres)
    WriteAlmstr.T="almSV90_�����d����"
    Filewritestep=1
end if
if ldp(almSV67_���t�^���������~A) then
    adrset(almSV67_���t�^���������~A,WriteErrAddres)
    WriteAlmstr.T="almSV67_���t�^���������~A"
    Filewritestep=1
end if
if ldp(almSV68_���t�^���������~B) then
    adrset(almSV68_���t�^���������~B,WriteErrAddres)
    WriteAlmstr.T="almSV68_���t�^���������~B"
    Filewritestep=1
end if
if ldp(almSV71_���t�^�X�g�b�p) then
    adrset(almSV71_���t�^�X�g�b�p,WriteErrAddres)
    WriteAlmstr.T="almSV71_���t�^�X�g�b�p"
    Filewritestep=1
end if
if ldp(almSV73_���t�^���������~A) then
    adrset(almSV73_���t�^���������~A,WriteErrAddres)
    WriteAlmstr.T="almSV73_���t�^���������~A"
    Filewritestep=1
end if
if ldp(almSV74_���t�^���������~B) then
    adrset(almSV74_���t�^���������~B,WriteErrAddres)
    WriteAlmstr.T="almSV74_���t�^���������~B"
    Filewritestep=1
end if
if ldp(almSV77_���t�^�X�g�b�p) then
    adrset(almSV77_���t�^�X�g�b�p,WriteErrAddres)
    WriteAlmstr.T="almSV77_���t�^�X�g�b�p"
    Filewritestep=1
end if
if ldp(almSV79_���t�^���������~A) then
    adrset(almSV79_���t�^���������~A,WriteErrAddres)
    WriteAlmstr.T="almSV79_���t�^���������~A"
    Filewritestep=1
end if
if ldp(almSV80_���t�^���������~B) then
    adrset(almSV80_���t�^���������~B,WriteErrAddres)
    WriteAlmstr.T="almSV80_���t�^���������~B"
    Filewritestep=1
end if
if ldp(almSV83_���t�^�X�g�b�p) then
    adrset(almSV83_���t�^�X�g�b�p,WriteErrAddres)
    WriteAlmstr.T="almSV83_���t�^�X�g�b�p"
    Filewritestep=1
end if
if ldp(almSV85_���t�^���������~A) then
    adrset(almSV85_���t�^���������~A,WriteErrAddres)
    WriteAlmstr.T="almSV85_���t�^���������~A"
    Filewritestep=1
end if
if ldp(almXSW90_���t�^�X�g�b�p���~�[) then
    adrset(almXSW90_���t�^�X�g�b�p���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW90_���t�^�X�g�b�p���~�["
    Filewritestep=1
end if
if ldp(almINV11_���|���vB�ُ�) then
    adrset(almINV11_���|���vB�ُ�,WriteErrAddres)
    WriteAlmstr.T="almINV11_���|���vB�ُ�"
    Filewritestep=1
end if
if ldp(almFLT3_�^���N���) then
    adrset(almFLT3_�^���N���,WriteErrAddres)
    WriteAlmstr.T="almFLT3_�^���N���"
    Filewritestep=1
end if
if ldp(almFLT4_�^���N����) then
    adrset(almFLT4_�^���N����,WriteErrAddres)
    WriteAlmstr.T="almFLT4_�^���N����"
    Filewritestep=1
end if
if ldp(almXSW91_���t�^�������㏸�[A) then
    adrset(almXSW91_���t�^�������㏸�[A,WriteErrAddres)
    WriteAlmstr.T="almXSW91_���t�^�������㏸�[A"
    Filewritestep=1
end if
if ldp(almXSW92_���t�^���������~�[A) then
    adrset(almXSW92_���t�^���������~�[A,WriteErrAddres)
    WriteAlmstr.T="almXSW92_���t�^���������~�[A"
    Filewritestep=1
end if
if ldp(almXSW93_���t�^�������㏸�[B) then
    adrset(almXSW93_���t�^�������㏸�[B,WriteErrAddres)
    WriteAlmstr.T="almXSW93_���t�^�������㏸�[B"
    Filewritestep=1
end if
if ldp(almXSW94_���t�^���������~�[B) then
    adrset(almXSW94_���t�^���������~�[B,WriteErrAddres)
    WriteAlmstr.T="almXSW94_���t�^���������~�[B"
    Filewritestep=1
end if
if ldp(almXSW95_���t�^�X�g�b�p���~�[) then
    adrset(almXSW95_���t�^�X�g�b�p���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW95_���t�^�X�g�b�p���~�["
    Filewritestep=1
end if
if ldp(almINV12_���|���vC�ُ�) then
    adrset(almINV12_���|���vC�ُ�,WriteErrAddres)
    WriteAlmstr.T="almINV12_���|���vC�ُ�"
    Filewritestep=1
end if
if ldp(almFLT5_�^���N���) then
    adrset(almFLT5_�^���N���,WriteErrAddres)
    WriteAlmstr.T="almFLT5_�^���N���"
    Filewritestep=1
end if
if ldp(almFLT6_�^���N����) then
    adrset(almFLT6_�^���N����,WriteErrAddres)
    WriteAlmstr.T="almFLT6_�^���N����"
    Filewritestep=1
end if
if ldp(almXSW96_���t�^�������㏸�[A) then
    adrset(almXSW96_���t�^�������㏸�[A,WriteErrAddres)
    WriteAlmstr.T="almXSW96_���t�^�������㏸�[A"
    Filewritestep=1
end if
if ldp(almXSW97_���t�^���������~�[A) then
    adrset(almXSW97_���t�^���������~�[A,WriteErrAddres)
    WriteAlmstr.T="almXSW97_���t�^���������~�[A"
    Filewritestep=1
end if
if ldp(almXSW98_���t�^�������㏸�[B) then
    adrset(almXSW98_���t�^�������㏸�[B,WriteErrAddres)
    WriteAlmstr.T="almXSW98_���t�^�������㏸�[B"
    Filewritestep=1
end if
if ldp(almXSW99_���t�^���������~�[B) then
    adrset(almXSW99_���t�^���������~�[B,WriteErrAddres)
    WriteAlmstr.T="almXSW99_���t�^���������~�[B"
    Filewritestep=1
end if
if ldp(almSV86_���t�^���������~B) then
    adrset(almSV86_���t�^���������~B,WriteErrAddres)
    WriteAlmstr.T="almSV86_���t�^���������~B"
    Filewritestep=1
end if
if ldp(almSV89_���t�^�X�g�b�p) then
    adrset(almSV89_���t�^�X�g�b�p,WriteErrAddres)
    WriteAlmstr.T="almSV89_���t�^�X�g�b�p"
    Filewritestep=1
end if
if ldp(alm���ܓ����@) then
    adrset(alm���ܓ����@,WriteErrAddres)
    WriteAlmstr.T="alm���ܓ����@"
    Filewritestep=1
end if
if ldp(almINV10_���|���vA�^�]) then
    adrset(almINV10_���|���vA�^�],WriteErrAddres)
    WriteAlmstr.T="almINV10_���|���vA�^�]"
    Filewritestep=1
end if
if ldp(almINV11_���|���vB�^�]) then
    adrset(almINV11_���|���vB�^�],WriteErrAddres)
    WriteAlmstr.T="almINV11_���|���vB�^�]"
    Filewritestep=1
end if
if ldp(almINV12_���|���vC�^�]) then
    adrset(almINV12_���|���vC�^�],WriteErrAddres)
    WriteAlmstr.T="almINV12_���|���vC�^�]"
    Filewritestep=1
end if
if ldp(almINV13_���|���vD�^�]) then
    adrset(almINV13_���|���vD�^�],WriteErrAddres)
    WriteAlmstr.T="almINV13_���|���vD�^�]"
    Filewritestep=1
end if
if ldp(almXSW100_���t�^�X�g�b�p���~�[) then
    adrset(almXSW100_���t�^�X�g�b�p���~�[,WriteErrAddres)
    WriteAlmstr.T="almXSW100_���t�^�X�g�b�p���~�["
    Filewritestep=1
end if
if ldp(almINV13_���|���vD�ُ�) then
    adrset(almINV13_���|���vD�ُ�,WriteErrAddres)
    WriteAlmstr.T="almINV13_���|���vD�ُ�"
    Filewritestep=1
end if
if ldp(almFLT7_�^���N���) then
    adrset(almFLT7_�^���N���,WriteErrAddres)
    WriteAlmstr.T="almFLT7_�^���N���"
    Filewritestep=1
end if
if ldp(almFLT8_�^���N����) then
    adrset(almFLT8_�^���N����,WriteErrAddres)
    WriteAlmstr.T="almFLT8_�^���N����"
    Filewritestep=1
end if
if ldp(almRLY_SCR1_MC36_���]���[�^) then
    adrset(almRLY_SCR1_MC36_���]���[�^,WriteErrAddres)
    WriteAlmstr.T="almRLY_SCR1_MC36_���]���[�^"
    Filewritestep=1
end if
if ldp(almRLY_SCR2_MC37_���]���[�^) then
    adrset(almRLY_SCR2_MC37_���]���[�^,WriteErrAddres)
    WriteAlmstr.T="almRLY_SCR2_MC37_���]���[�^"
    Filewritestep=1
end if
if ldp(almINV1_�R���x�A�ُ�) then
    adrset(almINV1_�R���x�A�ُ�,WriteErrAddres)
    WriteAlmstr.T="almINV1_�R���x�A�ُ�"
    Filewritestep=1
end if
if ldp(almINV2_�R���x�A�ُ�) then
    adrset(almINV2_�R���x�A�ُ�,WriteErrAddres)
    WriteAlmstr.T="almINV2_�R���x�A�ُ�"
    Filewritestep=1
end if
if ldp(almINV3_�R���x�A�ُ�) then
    adrset(almINV3_�R���x�A�ُ�,WriteErrAddres)
    WriteAlmstr.T="almINV3_�R���x�A�ُ�"
    Filewritestep=1
end if
'-----------------------------------------------------------------------------------------------------------------------------
