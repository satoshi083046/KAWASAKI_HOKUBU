'IH���у��j�b�gA�����񑀍�
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'
'	�󊘔����� �A�C�e��NO=99
'
'===================================================================================================================
'IH���у��j�b�gA
' [Rx ]---------------------------------
adrset(R47600,pinB�I�����C��.D)
adrset(R47601,pinB�ُ�.D)
adrset(R47602,pinB���쒆.D)
adrset(R47603,pinB�����R�}���h��t�\.D)
adrset(R47604,pinB������t�\.D)
adrset(R47605,pinB���o�v��.D)
adrset(R47606,pinB�������Z���T.D)
adrset(R47607,pinB���o���Z���T.D)
adrset(R47608,pinB���o�R�}���h��t�\.D)

adrset(R47700,pinB�R�}���h��������.D)
adrset(R47701,pinB�Ǐo�����ݒ�.D)
' [Ry ]---------------------------------
adrset(R51600,poutB����~�w��.D)
adrset(R51601,poutB�����w��.D)
adrset(R51602,poutB���o�w��.D)

adrset(R51700,poutB�R�}���h�����v��.D)
adrset(R51701,poutB�Ǐo�����ݒ�.D)
' [Wr ]---------------------------------
adrset(DM12100,pinU���o�A�C�e��NO.D)
adrset(DM12101,pinU���o��NO.D)
adrset(DM12102,pinU�ʂ�No.D)
adrset(DM12103,pinD�|�d��.D)

adrset(DM12105,pinD���f�[�^.D)


adrset(DM12108,pinU�A�C�e���o�^CH1.D)
adrset(DM12109,pinU�A�C�e���o�^CH2.D)
adrset(DM12110,pinU�A�C�e���o�^CH3.D)
adrset(DM12111,pinU�A�C�e���o�^CH4.D)
adrset(DM12112,pinU�A�C�e���o�^CH5.D)
adrset(DM12113,pinU�A�C�e���o�^CH6.D)
adrset(DM12114,pinU�A�C�e���o�^CH7.D)
adrset(DM12115,pinU�R�}���hNo����.D)
adrset(DM12116,pinU�R�}���h�f�[�^0.D)
adrset(DM12117,pinU�R�}���h�f�[�^1.D)
adrset(DM12118,pinU�R�}���h�f�[�^2.D)
adrset(DM12119,pinU�R�}���h�f�[�^3.D)
adrset(DM12120,pinU�R�}���h�f�[�^4.D)
adrset(DM12121,pinU�R�}���h�f�[�^5.D)
adrset(DM12122,pinU�R�}���h�f�[�^6.D)
adrset(DM12123,pinU�R�}���h�f�[�^7.D)
adrset(DM12124,pinU�R�}���h�f�[�^8.D)
adrset(DM12125,pinU�R�}���h�f�[�^9.D)
adrset(DM12126,pinU�R�}���h�f�[�^10.D)
adrset(DM12127,pinU�R�}���h�f�[�^11.D)

adrset(DM12128,pinU�R�}���h�f�[�^12.D)
adrset(DM12129,pinU�R�}���h�f�[�^13.D)
adrset(DM12130,pinU�R�}���h�f�[�^14.D)
adrset(DM12131,pinU�R�}���h�f�[�^15.D)
' [Ww ]---------------------------------
adrset(DM12612,poutU�����A�C�e��NO.D)
adrset(DM12613,poutU������NO.D)
adrset(DM12614,poutU�ʂ�No.D)
adrset(DM12615,poutD�|�d��.D)

adrset(DM12617,poutD���f�[�^.D)


adrset(DM12627,poutU�R�}���hNo.D)
adrset(DM12628,poutU�R�}���h�f�[�^0.D)
adrset(DM12629,poutU�R�}���h�f�[�^1.D)
adrset(DM12630,poutU�R�}���h�f�[�^2.D)
adrset(DM12631,poutU�R�}���h�f�[�^3.D)
adrset(DM12632,poutU�R�}���h�f�[�^4.D)
adrset(DM12633,poutU�R�}���h�f�[�^5.D)
adrset(DM12634,poutU�R�}���h�f�[�^6.D)
adrset(DM12635,poutU�R�}���h�f�[�^7.D)
adrset(DM12636,poutU�R�}���h�f�[�^8.D)
adrset(DM12637,poutU�R�}���h�f�[�^9.D)
adrset(DM12638,poutU�R�}���h�f�[�^10.D)
adrset(DM12639,poutU�R�}���h�f�[�^11.D)
adrset(DM12640,poutU�R�}���h�f�[�^12.D)
adrset(DM12641,poutU�R�}���h�f�[�^13.D)
adrset(DM12642,poutU�R�}���h�f�[�^14.D)
adrset(DM12643,poutU�R�}���h�f�[�^15.D)
' --------------------------------------
'�y ���������� �z
if CR2008 then

	�t�@�C���Ǎ�step=0
	�t�@�C��������step=0
	�ꊇ�]��step=0
	�ꊇ�Ǎ�step=0
	�p�����[�^������step=0
	�p�����[�^�Ǎ���step=0

end if
'===================================================================================================================
' �C���f�b�N�X
	OffsetAdr=0
'------------------------------------------------------------------
' �t�@�C���Ǎ� 	FR001.fru => ZF0 - ZF32767 => IH���ъ�A
'------------------------------------------------------------------
if LDP(pnlPBIH������X�V) and not(�t�@�C���Ǎ��ݒ�)then
	�t�@�C���Ǎ�step=1
end if

tmr(tim_�t�@�C���Ǎ�,tim_�t�@�C���Ǎ�_val)
select case �t�@�C���Ǎ�step
case 0
case 1
	�t�@�C���Ǎ��ݒ�=ON
	inc(�t�@�C���Ǎ�step)

case 2
	�t�@�C���Ǎ��݊���=OFF
	�t�@�C���Ǎ���ERR=OFF
	�h���C�u�ԍ�=0
	�o���N�ԍ�=0
	�t�@�C���ԍ�=1
	FRLDM(�h���C�u�ԍ�,�o���N�ԍ�,�t�@�C���ԍ�,�t�@�C���Ǎ��݊���)
	inc(�t�@�C���Ǎ�step)

case 3
	if �t�@�C���Ǎ��݊��� or �t�@�C���Ǎ���ERR then
		inc(�t�@�C���Ǎ�step)
	end if
	
case 4
	if �t�@�C���Ǎ���ERR then
		inc(�t�@�C���Ǎ�step)
	else
		if �ꊇ�]��step=0 then
			�ꊇ�]��step=1
			inc(�t�@�C���Ǎ�step)
		end if
	end if
	
case 5
	if �ꊇ�]��step=0 then
		inc(�t�@�C���Ǎ�step)
	end if

case 6
	�t�@�C���Ǎ��ݒ�=OFF
	�t�@�C���Ǎ�step=0

end select


'------------------------------------------------------------------
' �t�@�C�������� IH���ъ�A => ZF0 - ZF32767 => FR000.fru
'------------------------------------------------------------------
if LDP(pnlPBIH������ۑ�) and not(�t�@�C�������ݒ�) then
	�t�@�C��������step=1
end if

tmr(tim_�t�@�C��������,tim_�t�@�C��������_val)
select case �t�@�C��������step
case 0
case 1
	�t�@�C�������ݒ�=ON
	inc(�t�@�C��������step)

case 2
	if �ꊇ�Ǎ�step=0 then
		�ꊇ�Ǎ�step=1
		inc(�t�@�C��������step)
	end if

case 3
	if �ꊇ�Ǎ�step=0 then
		inc(�t�@�C��������step)
	end if

case 4
	'�^�C���X�^���v
	ZF0.T=STR(CM700.U)
	ZF1=$2F
	ZF2.T=STR(CM701.U)
	ZF3=$2F
	ZF4.T=STR(CM702.U)
	ZF5=$2F
	ZF6.T=STR(CM703.U)
	ZF7=$3A
	ZF8.T=STR(CM704.U)

	�h���C�u�ԍ�=0
	�o���N�ԍ�=0
	�t�@�C���ԍ�=0
	FRSTM(�h���C�u�ԍ�,�o���N�ԍ�,�t�@�C���ԍ�,�t�@�C�������݊���)
	inc(�t�@�C��������step)

case 5
	if �t�@�C�������݊��� or �t�@�C��������ERR then
		inc(�t�@�C��������step)
	end if	
 
case 6
	�t�@�C�������ݒ�=OFF
	�t�@�C��������step=0

end select


'------------------------------------------------------------------
' �p�����[�^�ꊇ�]��
'------------------------------------------------------------------
if ldp(pnlPB�ꊇ�]��) and �ꊇ�]��step=0 and not(�p�����[�^�]����) then
	�ꊇ�]��step=1
end if

tmr(tim_�ꊇ�]��,tim_�ꊇ�]��_val)

select case �ꊇ�]��step
case 0
case 1
	�p�����[�^�]����=ON
	par�A�C�e��NO=0
	inc(�ꊇ�]��step)

case 2
	par�A�C�e��NO=par�A�C�e��NO+1
	if par�A�C�e��NO < 100 then
		inc(�ꊇ�]��step)
	else
		�ꊇ�]��step=99
	end if
	
case 3
	'������̓ǂݏo��
	ADRSET(ZF0.U,SourceAdr) ' �o���N�擪�A�h���X
	SourceAdr=SourceAdr+10*par�A�C�e��NO
	ADRSET(���x��������.U,DestAdr)
	for loop=0 to 9 step 1
		*DestAdr.U=*SourceAdr.U
		inc(DestAdr)
		inc(SourceAdr)
	next
	inc(�ꊇ�]��step)

case 4 '---------------------------------------------
	if �p�����[�^������step=0 then		
		�p�����[�^������step=1
		inc(�ꊇ�]��step)
	end if

case 5
	if �p�����[�^������step=0 then
		inc(�ꊇ�]��step)
	end if


	�ꊇ�]��step=2
	
case 99
	�p�����[�^�]����=OFF
	�ꊇ�]��step=0
	

end select

'------------------------------------------------------------------

'------------------------------------------------------------------
' �p�����[�^�ꊇ�Ǎ�
'------------------------------------------------------------------
if ldp(pnlPB�ꊇ�Ǐo��) and �ꊇ�]��step=0 and not(�p�����[�^�]����) then
	�ꊇ�Ǎ�step=1
end if

tmr( tim_�ꊇ�Ǎ�,tim_�ꊇ�Ǎ�_val)

select case �ꊇ�Ǎ�step
case 0
case 1
	�p�����[�^�]����=ON
	par�A�C�e��NO=0
	inc(�ꊇ�Ǎ�step)

case 2
	par�A�C�e��NO=par�A�C�e��NO+1
	if par�A�C�e��NO < 100 then
		inc(�ꊇ�Ǎ�step)
	else
		�ꊇ�Ǎ�step=99
	end if
	
case 3 '---------------------------------------------
	if �p�����[�^�Ǎ���step=0 then
		*poutU�R�}���hNo.U=1
		*poutU�R�}���h�f�[�^0.U=par�A�C�e��NO
		�p�����[�^�Ǎ���step=1
	end if
	inc(�ꊇ�Ǎ�step)

case 4
	if �p�����[�^�Ǎ���step=0 then
		inc(�ꊇ�Ǎ�step)
	end if

case 5
	
	par�A�C�e��NO	=*pinU�R�}���h�f�[�^0.U
	���x��������=*pinU�R�}���h�f�[�^1.U
	���x��������1=*pinU�R�}���h�f�[�^2.U
	���x��������2=*pinU�R�}���h�f�[�^3.U
	���x��������3=*pinU�R�}���h�f�[�^4.U
	���x��������4=*pinU�R�}���h�f�[�^5.U
	���x��������5=*pinU�R�}���h�f�[�^6.U
	���x��������6=*pinU�R�}���h�f�[�^7.U
	���x��������7=*pinU�R�}���h�f�[�^8.U
	
	���x��������=swap(���x��������)
	���x��������1=swap(���x��������1)
	���x��������2=swap(���x��������2)
	���x��������3=swap(���x��������3)
	���x��������4=swap(���x��������4)
	���x��������5=swap(���x��������5)
	���x��������6=swap(���x��������6)
	���x��������7=swap(���x��������7)
	
	
	ADRSET(���x��������.U,SourceAdr)
	ADRSET(ZF0.U,DestAdr) ' �o���N�擪�A�h���X
	DestAdr=DestAdr+10*par�A�C�e��NO
	for loop=0 to 9 step 1
		*DestAdr.U=*SourceAdr.U
		inc(DestAdr)
		inc(SourceAdr)
	next

	�ꊇ�Ǎ�step=2
	
case 99
	�p�����[�^�]����=OFF
	�ꊇ�Ǎ�step=0
	

end select

'------------------------------------------------------------------
' �p�����[�^�e�[�u���������݃^�C�~���O
'------------------------------------------------------------------
tmr(tim_�p�����[�^������,tim_�p�����[�^������_val)
select case �p�����[�^������step
case 0
case 1
	if *pinB�R�}���h��������.B then
		*poutU�R�}���hNo.U=1
		*poutU�R�}���h�f�[�^0.U=par�A�C�e��NO
		*poutU�R�}���h�f�[�^1.U=swap(���x��������)
		*poutU�R�}���h�f�[�^2.U=swap(���x��������1)
		*poutU�R�}���h�f�[�^3.U=swap(���x��������2)
		*poutU�R�}���h�f�[�^4.U=swap(���x��������3)
		*poutU�R�}���h�f�[�^5.U=swap(���x��������4)
		*poutU�R�}���h�f�[�^6.U=swap(���x��������5)
		*poutU�R�}���h�f�[�^7.U=swap(���x��������6)
		*poutU�R�}���h�f�[�^8.U=swap(���x��������7)
		inc(�p�����[�^������step)
	end if

case 2
	*poutB�Ǐo�����ݒ�.B=ON  '�����݃��[�h
	inc(�p�����[�^������step)

case 3
	tim_�p�����[�^������_val=1
	res(tim_�p�����[�^������)
	inc(�p�����[�^������step)

case 4
	*poutB�R�}���h�����v��.B=ON
	inc(�p�����[�^������step)

case 5
	if *pinB�R�}���h��������.B=OFF then
		*poutB�R�}���h�����v��.B=OFF
		*poutB�Ǐo�����ݒ�.B=OFF
		inc(�p�����[�^������step)
	end if

case 6
	if *pinB�R�}���h��������.B then
		inc(�p�����[�^������step)
	end if

case 7
	tim_�p�����[�^������_val=1
	res(tim_�p�����[�^������)
	inc(�p�����[�^������step)

case 8
	if tim_�p�����[�^������.B then
		inc(�p�����[�^������step)
	end if
	
case 9
	�p�����[�^������step=0
	
end select
'------------------------------------------------------------------
' �p�����[�^�e�[�u���Ǎ��݃^�C�~���O
'------------------------------------------------------------------
tmr(tim_�p�����[�^�Ǎ���,tim_�p�����[�^�Ǎ���_val)
select case �p�����[�^�Ǎ���step
case 0
case 1
	if  *pinB�R�}���h��������.B then
		inc(�p�����[�^�Ǎ���step)
	else
		�p�����[�^�Ǎ���step=0
	end if

case 2
	*poutU�R�}���h�f�[�^0.U=par�A�C�e��NO

	*poutB�Ǐo�����ݒ�.B=OFF '�Ǎ����[�h
	inc(�p�����[�^�Ǎ���step)


case 3
	tim_�p�����[�^�Ǎ���_val=1
	res(tim_�p�����[�^�Ǎ���)
	inc(�p�����[�^�Ǎ���step)

case 4
	if tim_�p�����[�^�Ǎ���.B then
		*poutB�R�}���h�����v��.B=ON
		inc(�p�����[�^�Ǎ���step)
	end if
	
case 5
	if *pinB�R�}���h��������.B=OFF then
		*poutB�R�}���h�����v��.B=OFF
		*poutB�Ǐo�����ݒ�.B=OFF
		inc(�p�����[�^�Ǎ���step)
	end if

case 6
	if *pinB�R�}���h��������.B then
		inc(�p�����[�^�Ǎ���step)
	end if

case 7
	tim_�p�����[�^�Ǎ���_val=0
	res(tim_�p�����[�^�Ǎ���)
	inc(�p�����[�^�Ǎ���step)

case 8
	if tim_�p�����[�^�Ǎ���.B then
		inc(�p�����[�^�Ǎ���step)
	end if
	
case 9
	par�A�C�e��NO	=*pinU�R�}���h�f�[�^0.U
	���x��������=*pinU�R�}���h�f�[�^1.U
	���x��������1=*pinU�R�}���h�f�[�^2.U
	���x��������2=*pinU�R�}���h�f�[�^3.U
	���x��������3=*pinU�R�}���h�f�[�^4.U
	���x��������4=*pinU�R�}���h�f�[�^5.U
	���x��������5=*pinU�R�}���h�f�[�^6.U
	���x��������6=*pinU�R�}���h�f�[�^7.U
	���x��������7=*pinU�R�}���h�f�[�^8.U
	
	���x��������=swap(���x��������)
	���x��������1=swap(���x��������1)
	���x��������2=swap(���x��������2)
	���x��������3=swap(���x��������3)
	���x��������4=swap(���x��������4)
	���x��������5=swap(���x��������5)
	���x��������6=swap(���x��������6)
	���x��������7=swap(���x��������7)

	inc(�p�����[�^�Ǎ���step)

case 10
	�p�����[�^�Ǎ���step=0
end select


