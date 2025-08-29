'入出力ユーティリティモジュール
'===================================================================================================================
'【 初期化処理 】

if CR2008 then '電源ON時初期化処理
end if
'===================================================================================================================
' inRegxxx outRegxxx
'	---------------------------------------------------------------------------------------
'	0: $1		
'	1: $2
'	2: $4
'	3: $8					加工パターン(ItemAddress)
'	4: $10
'	5: $20
'	6: $40
'	7: $80
'	----------------------------------------------------------------------------------------
'	9: $100
'	9: $200
'	10:$400					ステータスビット
'	11:$800
'	12:$1000
'	13:$2000 ほぐしA釜
'	14:$4000 ほぐしB釜
'	15:$8000 ごはん有
'	----------------------------------------------------------------------------------------
'出力コマンド	'A00000
MC5_洗米羽根=(mMC5_洗米羽根 or ejectMC5_洗米羽根 or extMC5_洗米羽根) and not(pauseMC5_洗米羽根)	'A00027
MC4_送米ポンプ=(mMC4_送米ポンプ or ejectMC4_送米ポンプ or extMC4_送米ポンプ) and not(pauseMC4_送米ポンプ)	'A00028
SV1_給水電磁弁=(mSV1_給水電磁弁 or ejectSV1_給水電磁弁 or extSV1_給水電磁弁) and not(pauseSV1_給水電磁弁)	'A00029
SV58_洗米バルブA=(mSV58_洗米バルブA or ejectSV58_洗米バルブA or extSV58_洗米バルブA) and not(pauseSV58_洗米バルブA)	'A00030
MC1_張込用昇降機=(mMC1_張込用昇降機 or ejectMC1_張込用昇降機 or extMC1_張込用昇降機) and not(pauseMC1_張込用昇降機)	'A00054
MC2_排出用昇降機=(mMC2_排出用昇降機 or ejectMC2_排出用昇降機 or extMC2_排出用昇降機) and not(pauseMC2_排出用昇降機)	'A00055
MC3_計量機=(mMC3_計量機 or ejectMC3_計量機 or extMC3_計量機) and not(pauseMC3_計量機)	'A00056
SV12_送米切換バルブA側=(mSV12_送米切換バルブA側 or ejectSV12_送米切換バルブA側 or extSV12_送米切換バルブA側) and not(pauseSV12_送米切換バルブA側)	'A00114
SV13_送米切換バルブB側=(mSV13_送米切換バルブB側 or ejectSV13_送米切換バルブB側 or extSV13_送米切換バルブB側) and not(pauseSV13_送米切換バルブB側)	'A00115
SV2_充填バルブ開A=(mSV2_充填バルブ開A or ejectSV2_充填バルブ開A or extSV2_充填バルブ開A) and not(pauseSV2_充填バルブ開A)	'A00117
SV3_充填バルブ閉A=(mSV3_充填バルブ閉A or ejectSV3_充填バルブ閉A or extSV3_充填バルブ閉A) and not(pauseSV3_充填バルブ閉A)	'A00118
SV4_水切りシャッター開A=(mSV4_水切りシャッター開A or ejectSV4_水切りシャッター開A or extSV4_水切りシャッター開A) and not(pauseSV4_水切りシャッター開A)	'A00119
SV5_水切りシャッター閉A=(mSV5_水切りシャッター閉A or ejectSV5_水切りシャッター閉A or extSV5_水切りシャッター閉A) and not(pauseSV5_水切りシャッター閉A)	'A00120
SV60_排水バルブ開A=(mSV60_排水バルブ開A or ejectSV60_排水バルブ開A or extSV60_排水バルブ開A) and not(pauseSV60_排水バルブ開A)	'A00121
SV61_排水バルブ閉A=(mSV61_排水バルブ閉A or ejectSV61_排水バルブ閉A or extSV61_排水バルブ閉A) and not(pauseSV61_排水バルブ閉A)	'A00122
SV7_充填バルブ開B=(mSV7_充填バルブ開B or ejectSV7_充填バルブ開B or extSV7_充填バルブ開B) and not(pauseSV7_充填バルブ開B)	'A00123
SV8_充填バルブ閉B=(mSV8_充填バルブ閉B or ejectSV8_充填バルブ閉B or extSV8_充填バルブ閉B) and not(pauseSV8_充填バルブ閉B)	'A00124
SV9_水切りシャッター開B=(mSV9_水切りシャッター開B or ejectSV9_水切りシャッター開B or extSV9_水切りシャッター開B) and not(pauseSV9_水切りシャッター開B)	'A00125
SV10_水切りシャッター閉B=(mSV10_水切りシャッター閉B or ejectSV10_水切りシャッター閉B or extSV10_水切りシャッター閉B) and not(pauseSV10_水切りシャッター閉B)	'A00126
SV62_排水バルブ開B=(mSV62_排水バルブ開B or ejectSV62_排水バルブ開B or extSV62_排水バルブ開B) and not(pauseSV62_排水バルブ開B)	'A00127
SV63_排水バルブ閉B=(mSV63_排水バルブ閉B or ejectSV63_排水バルブ閉B or extSV63_排水バルブ閉B) and not(pauseSV63_排水バルブ閉B)	'A00128
SV6_給水電磁弁A=(mSV6_給水電磁弁A or ejectSV6_給水電磁弁A or extSV6_給水電磁弁A) and not(pauseSV6_給水電磁弁A)	'A00151
SV11_給水電磁弁B=(mSV11_給水電磁弁B or ejectSV11_給水電磁弁B or extSV11_給水電磁弁B) and not(pauseSV11_給水電磁弁B)	'A00152
SV17_計水タンク給水（大）=(mSV17_計水タンク給水（大） or ejectSV17_計水タンク給水（大） or extSV17_計水タンク給水（大）) and not(pauseSV17_計水タンク給水（大）)	'A00154
SV18_計水タンク給水（小）=(mSV18_計水タンク給水（小） or ejectSV18_計水タンク給水（小） or extSV18_計水タンク給水（小）) and not(pauseSV18_計水タンク給水（小）)	'A00155
SV19_計水電磁弁_A=(mSV19_計水電磁弁_A or ejectSV19_計水電磁弁_A or extSV19_計水電磁弁_A) and not(pauseSV19_計水電磁弁_A)	'A00156
SV64_計水電磁弁_B=(mSV64_計水電磁弁_B or ejectSV64_計水電磁弁_B or extSV64_計水電磁弁_B) and not(pauseSV64_計水電磁弁_B)	'A00157
MC6_搬送モータ=(mMC6_搬送モータ or ejectMC6_搬送モータ or extMC6_搬送モータ) and not(pauseMC6_搬送モータ)	'A00177
MC7_搬送モータ=(mMC7_搬送モータ or ejectMC7_搬送モータ or extMC7_搬送モータ) and not(pauseMC7_搬送モータ)	'A00178
MC8_搬送モータ=(mMC8_搬送モータ or ejectMC8_搬送モータ or extMC8_搬送モータ) and not(pauseMC8_搬送モータ)	'A00179
SV14_ストッパ上昇=(mSV14_ストッパ上昇 or ejectSV14_ストッパ上昇 or extSV14_ストッパ上昇) and not(pauseSV14_ストッパ上昇)	'A00180
SV15_ストッパ下降=(mSV15_ストッパ下降 or ejectSV15_ストッパ下降 or extSV15_ストッパ下降) and not(pauseSV15_ストッパ下降)	'A00181
SV64_ストッパ上昇=(mSV64_ストッパ上昇 or ejectSV64_ストッパ上昇 or extSV64_ストッパ上昇) and not(pauseSV64_ストッパ上昇)	'A00182
SV70_ストッパ下降=(mSV70_ストッパ下降 or ejectSV70_ストッパ下降 or extSV70_ストッパ下降) and not(pauseSV70_ストッパ下降)	'A00183
SV20_リフト上昇=(mSV20_リフト上昇 or ejectSV20_リフト上昇 or extSV20_リフト上昇) and not(pauseSV20_リフト上昇)	'A00184
MC11_搬送モータ=(mMC11_搬送モータ or ejectMC11_搬送モータ or extMC11_搬送モータ) and not(pauseMC11_搬送モータ)	'A00185
SV32_リフト下降=(mSV32_リフト下降 or ejectSV32_リフト下降 or extSV32_リフト下降) and not(pauseSV32_リフト下降)	'A00186
MC9_モータローラ=(mMC9_モータローラ or ejectMC9_モータローラ or extMC9_モータローラ) and not(pauseMC9_モータローラ)	'A00209
MC12_搬送モータ=(mMC12_搬送モータ or ejectMC12_搬送モータ or extMC12_搬送モータ) and not(pauseMC12_搬送モータ)	'A00210
MC13_搬送モータ=(mMC13_搬送モータ or ejectMC13_搬送モータ or extMC13_搬送モータ) and not(pauseMC13_搬送モータ)	'A00211
MC16_モータローラ=(mMC16_モータローラ or ejectMC16_モータローラ or extMC16_モータローラ) and not(pauseMC16_モータローラ)	'A00212
SV21_リフト=(mSV21_リフト or ejectSV21_リフト or extSV21_リフト) and not(pauseSV21_リフト)	'A00213
SV51_ストッパ=(mSV51_ストッパ or ejectSV51_ストッパ or extSV51_ストッパ) and not(pauseSV51_ストッパ)	'A00214
SV22_ストッパ=(mSV22_ストッパ or ejectSV22_ストッパ or extSV22_ストッパ) and not(pauseSV22_ストッパ)	'A00215
SV23_リフト=(mSV23_リフト or ejectSV23_リフト or extSV23_リフト) and not(pauseSV23_リフト)	'A00216
MC14_搬送モータ=(mMC14_搬送モータ or ejectMC14_搬送モータ or extMC14_搬送モータ) and not(pauseMC14_搬送モータ)	'A00217
MC15_搬送モータ=(mMC15_搬送モータ or ejectMC15_搬送モータ or extMC15_搬送モータ) and not(pauseMC15_搬送モータ)	'A00218
MC34_モータローラ=(mMC34_モータローラ or ejectMC34_モータローラ or extMC34_モータローラ) and not(pauseMC34_モータローラ)	'A00219
SV24_クランプ=(mSV24_クランプ or ejectSV24_クランプ or extSV24_クランプ) and not(pauseSV24_クランプ)	'A00220
SV25_ストッパ=(mSV25_ストッパ or ejectSV25_ストッパ or extSV25_ストッパ) and not(pauseSV25_ストッパ)	'A00221
SV26_クランプ=(mSV26_クランプ or ejectSV26_クランプ or extSV26_クランプ) and not(pauseSV26_クランプ)	'A00222
SV27_ストッパ=(mSV27_ストッパ or ejectSV27_ストッパ or extSV27_ストッパ) and not(pauseSV27_ストッパ)	'A00223
SV28_リフト=(mSV28_リフト or ejectSV28_リフト or extSV28_リフト) and not(pauseSV28_リフト)	'A00224
SV29_ストッパ=(mSV29_ストッパ or ejectSV29_ストッパ or extSV29_ストッパ) and not(pauseSV29_ストッパ)	'A00241
MC40_ならしモータ=(mMC40_ならしモータ or ejectMC40_ならしモータ or extMC40_ならしモータ) and not(pauseMC40_ならしモータ)	'A00242
SV26_ならし上昇=(mSV26_ならし上昇 or ejectSV26_ならし上昇 or extSV26_ならし上昇) and not(pauseSV26_ならし上昇)	'A00245
SV25_ならし下降=(mSV25_ならし下降 or ejectSV25_ならし下降 or extSV25_ならし下降) and not(pauseSV25_ならし下降)	'A00246
SV23_ならし前進=(mSV23_ならし前進 or ejectSV23_ならし前進 or extSV23_ならし前進) and not(pauseSV23_ならし前進)	'A00247
SV24_ならし後退=(mSV24_ならし後退 or ejectSV24_ならし後退 or extSV24_ならし後退) and not(pauseSV24_ならし後退)	'A00248
SV34_シリンダ上昇A=(mSV34_シリンダ上昇A or ejectSV34_シリンダ上昇A or extSV34_シリンダ上昇A) and not(pauseSV34_シリンダ上昇A)	'A00249
SV35_シリンダ下降A=(mSV35_シリンダ下降A or ejectSV35_シリンダ下降A or extSV35_シリンダ下降A) and not(pauseSV35_シリンダ下降A)	'A00250
SV36_シリンダ上昇B=(mSV36_シリンダ上昇B or ejectSV36_シリンダ上昇B or extSV36_シリンダ上昇B) and not(pauseSV36_シリンダ上昇B)	'A00251
SV37_シリンダ下降B=(mSV37_シリンダ下降B or ejectSV37_シリンダ下降B or extSV37_シリンダ下降B) and not(pauseSV37_シリンダ下降B)	'A00252
SV39_アンクランプ=(mSV39_アンクランプ or ejectSV39_アンクランプ or extSV39_アンクランプ) and not(pauseSV39_アンクランプ)	'A00253
SV38_クランプ=(mSV38_クランプ or ejectSV38_クランプ or extSV38_クランプ) and not(pauseSV38_クランプ)	'A00254
MC44_モータローラ=(mMC44_モータローラ or ejectMC44_モータローラ or extMC44_モータローラ) and not(pauseMC44_モータローラ)	'A00255
MC45_搬送モータ=(mMC45_搬送モータ or ejectMC45_搬送モータ or extMC45_搬送モータ) and not(pauseMC45_搬送モータ)	'A00273
MC46_モータローラ=(mMC46_モータローラ or ejectMC46_モータローラ or extMC46_モータローラ) and not(pauseMC46_モータローラ)	'A00274
SV42_ストッパ=(mSV42_ストッパ or ejectSV42_ストッパ or extSV42_ストッパ) and not(pauseSV42_ストッパ)	'A00275
SV43_リフト=(mSV43_リフト or ejectSV43_リフト or extSV43_リフト) and not(pauseSV43_リフト)	'A00276
MC17_モータローラ=(mMC17_モータローラ or ejectMC17_モータローラ or extMC17_モータローラ) and not(pauseMC17_モータローラ)	'A00337
MC18_モータローラ=(mMC18_モータローラ or ejectMC18_モータローラ or extMC18_モータローラ) and not(pauseMC18_モータローラ)	'A00338
MC19_モータローラ=(mMC19_モータローラ or ejectMC19_モータローラ or extMC19_モータローラ) and not(pauseMC19_モータローラ)	'A00339
MC20_モータローラ=(mMC20_モータローラ or ejectMC20_モータローラ or extMC20_モータローラ) and not(pauseMC20_モータローラ)	'A00340
MC21_モータローラ=(mMC21_モータローラ or ejectMC21_モータローラ or extMC21_モータローラ) and not(pauseMC21_モータローラ)	'A00341
MC22_モータローラ=(mMC22_モータローラ or ejectMC22_モータローラ or extMC22_モータローラ) and not(pauseMC22_モータローラ)	'A00342
MC23_モータローラ=(mMC23_モータローラ or ejectMC23_モータローラ or extMC23_モータローラ) and not(pauseMC23_モータローラ)	'A00369
MC24_モータローラ=(mMC24_モータローラ or ejectMC24_モータローラ or extMC24_モータローラ) and not(pauseMC24_モータローラ)	'A00370
MC25_モータローラ=(mMC25_モータローラ or ejectMC25_モータローラ or extMC25_モータローラ) and not(pauseMC25_モータローラ)	'A00371
MC26_モータローラ=(mMC26_モータローラ or ejectMC26_モータローラ or extMC26_モータローラ) and not(pauseMC26_モータローラ)	'A00372
MC27_モータローラ=(mMC27_モータローラ or ejectMC27_モータローラ or extMC27_モータローラ) and not(pauseMC27_モータローラ)	'A00373
MC28_モータローラ=(mMC28_モータローラ or ejectMC28_モータローラ or extMC28_モータローラ) and not(pauseMC28_モータローラ)	'A00374
MC29_モータローラ=(mMC29_モータローラ or ejectMC29_モータローラ or extMC29_モータローラ) and not(pauseMC29_モータローラ)	'A00401
MC30_モータローラ=(mMC30_モータローラ or ejectMC30_モータローラ or extMC30_モータローラ) and not(pauseMC30_モータローラ)	'A00402
MC31_モータローラ=(mMC31_モータローラ or ejectMC31_モータローラ or extMC31_モータローラ) and not(pauseMC31_モータローラ)	'A00403
MC32_モータローラ=(mMC32_モータローラ or ejectMC32_モータローラ or extMC32_モータローラ) and not(pauseMC32_モータローラ)	'A00404
MC33_モータローラ=(mMC33_モータローラ or ejectMC33_モータローラ or extMC33_モータローラ) and not(pauseMC33_モータローラ)	'A00405
MC47_モータローラ=(mMC47_モータローラ or ejectMC47_モータローラ or extMC47_モータローラ) and not(pauseMC47_モータローラ)	'A00406
MC48_モータローラ=(mMC48_モータローラ or ejectMC48_モータローラ or extMC48_モータローラ) and not(pauseMC48_モータローラ)	'A00433
MC49_モータローラ=(mMC49_モータローラ or ejectMC49_モータローラ or extMC49_モータローラ) and not(pauseMC49_モータローラ)	'A00434
MC50_モータローラ=(mMC50_モータローラ or ejectMC50_モータローラ or extMC50_モータローラ) and not(pauseMC50_モータローラ)	'A00435
MC51_モータローラ=(mMC51_モータローラ or ejectMC51_モータローラ or extMC51_モータローラ) and not(pauseMC51_モータローラ)	'A00436
MC52_モータローラ=(mMC52_モータローラ or ejectMC52_モータローラ or extMC52_モータローラ) and not(pauseMC52_モータローラ)	'A00437
MC53_モータローラ=(mMC53_モータローラ or ejectMC53_モータローラ or extMC53_モータローラ) and not(pauseMC53_モータローラ)	'A00438
MC41_モータローラ=(mMC41_モータローラ or ejectMC41_モータローラ or extMC41_モータローラ) and not(pauseMC41_モータローラ)	'A00465
MC42_モータローラ=(mMC42_モータローラ or ejectMC42_モータローラ or extMC42_モータローラ) and not(pauseMC42_モータローラ)	'A00466
MC43_搬送モータ=(mMC43_搬送モータ or ejectMC43_搬送モータ or extMC43_搬送モータ) and not(pauseMC43_搬送モータ)	'A00467
SV44_ストッパ=(mSV44_ストッパ or ejectSV44_ストッパ or extSV44_ストッパ) and not(pauseSV44_ストッパ)	'A00468
SV45_ストッパ=(mSV45_ストッパ or ejectSV45_ストッパ or extSV45_ストッパ) and not(pauseSV45_ストッパ)	'A00469
SV46_ストッパ=(mSV46_ストッパ or ejectSV46_ストッパ or extSV46_ストッパ) and not(pauseSV46_ストッパ)	'A00470
SV47_リフト=(mSV47_リフト or ejectSV47_リフト or extSV47_リフト) and not(pauseSV47_リフト)	'A00471
SV48_リフト=(mSV48_リフト or ejectSV48_リフト or extSV48_リフト) and not(pauseSV48_リフト)	'A00472
MC54_モータローラ=(mMC54_モータローラ or ejectMC54_モータローラ or extMC54_モータローラ) and not(pauseMC54_モータローラ)	'A00473
MC10_搬送モータ正転=(mMC10_搬送モータ正転 or ejectMC10_搬送モータ正転 or extMC10_搬送モータ正転) and not(pauseMC10_搬送モータ正転)	'A00474
MC10_搬送モータ逆転=(mMC10_搬送モータ逆転 or ejectMC10_搬送モータ逆転 or extMC10_搬送モータ逆転) and not(pauseMC10_搬送モータ逆転)	'A00475
MC55_搬送モータ=(mMC55_搬送モータ or ejectMC55_搬送モータ or extMC55_搬送モータ) and not(pauseMC55_搬送モータ)	'A00476
SV49_ストッパ=(mSV49_ストッパ or ejectSV49_ストッパ or extSV49_ストッパ) and not(pauseSV49_ストッパ)	'A00477
SV50_リフト=(mSV50_リフト or ejectSV50_リフト or extSV50_リフト) and not(pauseSV50_リフト)	'A00478
SV45_シリンダ上昇A=(mSV45_シリンダ上昇A or ejectSV45_シリンダ上昇A or extSV45_シリンダ上昇A) and not(pauseSV45_シリンダ上昇A)	'A00497
SV46_シリンダ下降A=(mSV46_シリンダ下降A or ejectSV46_シリンダ下降A or extSV46_シリンダ下降A) and not(pauseSV46_シリンダ下降A)	'A00498
SV47_シリンダ上昇B=(mSV47_シリンダ上昇B or ejectSV47_シリンダ上昇B or extSV47_シリンダ上昇B) and not(pauseSV47_シリンダ上昇B)	'A00499
SV48_シリンダ下降B=(mSV48_シリンダ下降B or ejectSV48_シリンダ下降B or extSV48_シリンダ下降B) and not(pauseSV48_シリンダ下降B)	'A00500
SV49_アンクランプ=(mSV49_アンクランプ or ejectSV49_アンクランプ or extSV49_アンクランプ) and not(pauseSV49_アンクランプ)	'A00501
SV50_クランプ=(mSV50_クランプ or ejectSV50_クランプ or extSV50_クランプ) and not(pauseSV50_クランプ)	'A00502
MC57_搬送モータ=(mMC57_搬送モータ or ejectMC57_搬送モータ or extMC57_搬送モータ) and not(pauseMC57_搬送モータ)	'A00504
SV59_リフト上昇=(mSV59_リフト上昇 or ejectSV59_リフト上昇 or extSV59_リフト上昇) and not(pauseSV59_リフト上昇)	'A00505
'MC56_ブラシモータ=(mMC56_ブラシモータ or ejectMC56_ブラシモータ or extMC56_ブラシモータ) and not(pauseMC56_ブラシモータ)	'A00506
SV65_シリンダ上昇=(mSV65_シリンダ上昇 or ejectSV65_シリンダ上昇 or extSV65_シリンダ上昇) and not(pauseSV65_シリンダ上昇)	'A00507
SV66_シリンダ下降=(mSV66_シリンダ下降 or ejectSV66_シリンダ下降 or extSV66_シリンダ下降) and not(pauseSV66_シリンダ下降)	'A00508
SV76_リフト下降=(mSV76_リフト下降 or ejectSV76_リフト下降 or extSV76_リフト下降) and not(pauseSV76_リフト下降)	'A00509
MC1_インバータ用電源=(mMC1_インバータ用電源 or ejectMC1_インバータ用電源 or extMC1_インバータ用電源) and not(pauseMC1_インバータ用電源)	'A00593
MC35_搬送モータ=(mMC35_搬送モータ or ejectMC35_搬送モータ or extMC35_搬送モータ) and not(pauseMC35_搬送モータ)	'A00599
MC36_反転モータ正転=(mMC36_反転モータ正転 or ejectMC36_反転モータ正転 or extMC36_反転モータ正転) and not(pauseMC36_反転モータ正転)	'A00600
MC36_反転モータ逆転=(mMC36_反転モータ逆転 or ejectMC36_反転モータ逆転 or extMC36_反転モータ逆転) and not(pauseMC36_反転モータ逆転)	'A00601
INV1_コンベアモータ正転=(mINV1_コンベアモータ正転 or ejectINV1_コンベアモータ正転 or extINV1_コンベアモータ正転) and not(pauseINV1_コンベアモータ正転)	'A00602
INV2_コンベアモータ正転=(mINV2_コンベアモータ正転 or ejectINV2_コンベアモータ正転 or extINV2_コンベアモータ正転) and not(pauseINV2_コンベアモータ正転)	'A00603
INV3_コンベアモータ正転=(mINV3_コンベアモータ正転 or ejectINV3_コンベアモータ正転 or extINV3_コンベアモータ正転) and not(pauseINV3_コンベアモータ正転)	'A00604
MC58_洗浄ポンプA=(mMC58_洗浄ポンプA or ejectMC58_洗浄ポンプA or extMC58_洗浄ポンプA) and not(pauseMC58_洗浄ポンプA)	'A00605
MC59_洗浄ポンプB=(mMC59_洗浄ポンプB or ejectMC59_洗浄ポンプB or extMC59_洗浄ポンプB) and not(pauseMC59_洗浄ポンプB)	'A00606
MC60_洗浄ポンプC=(mMC60_洗浄ポンプC or ejectMC60_洗浄ポンプC or extMC60_洗浄ポンプC) and not(pauseMC60_洗浄ポンプC)	'A00607
MC61_洗浄ポンプD=(mMC61_洗浄ポンプD or ejectMC61_洗浄ポンプD or extMC61_洗浄ポンプD) and not(pauseMC61_洗浄ポンプD)	'A00608
MC37_反転モータ逆転=(mMC37_反転モータ逆転 or ejectMC37_反転モータ逆転 or extMC37_反転モータ逆転) and not(pauseMC37_反転モータ逆転)	'A00625
MC37_反転モータ正転=(mMC37_反転モータ正転 or ejectMC37_反転モータ正転 or extMC37_反転モータ正転) and not(pauseMC37_反転モータ正転)	'A00626
MC38_搬送モータ=(mMC38_搬送モータ or ejectMC38_搬送モータ or extMC38_搬送モータ) and not(pauseMC38_搬送モータ)	'A00627
SV97_すすぎ電磁弁=(mSV97_すすぎ電磁弁 or ejectSV97_すすぎ電磁弁 or extSV97_すすぎ電磁弁) and not(pauseSV97_すすぎ電磁弁)	'A00628
SV98_仕上げ電磁弁=(mSV98_仕上げ電磁弁 or ejectSV98_仕上げ電磁弁 or extSV98_仕上げ電磁弁) and not(pauseSV98_仕上げ電磁弁)	'A00629
SV69_給湯電磁弁=(mSV69_給湯電磁弁 or ejectSV69_給湯電磁弁 or extSV69_給湯電磁弁) and not(pauseSV69_給湯電磁弁)	'A00635
SV75_給湯電磁弁=(mSV75_給湯電磁弁 or ejectSV75_給湯電磁弁 or extSV75_給湯電磁弁) and not(pauseSV75_給湯電磁弁)	'A00636
MC_HT1_タンクヒータ=(mMC_HT1_タンクヒータ or ejectMC_HT1_タンクヒータ or extMC_HT1_タンクヒータ) and not(pauseMC_HT1_タンクヒータ)	'A00637
MC_HT2_タンクヒータ=(mMC_HT2_タンクヒータ or ejectMC_HT2_タンクヒータ or extMC_HT2_タンクヒータ) and not(pauseMC_HT2_タンクヒータ)	'A00638
MC_HT3_タンクヒータ=(mMC_HT3_タンクヒータ or ejectMC_HT3_タンクヒータ or extMC_HT3_タンクヒータ) and not(pauseMC_HT3_タンクヒータ)	'A00639
MC_HT4_タンクヒータ=(mMC_HT4_タンクヒータ or ejectMC_HT4_タンクヒータ or extMC_HT4_タンクヒータ) and not(pauseMC_HT4_タンクヒータ)	'A00640
SV81_給湯電磁弁=(mSV81_給湯電磁弁 or ejectSV81_給湯電磁弁 or extSV81_給湯電磁弁) and not(pauseSV81_給湯電磁弁)	'A00657
SV87_給湯電磁弁=(mSV87_給湯電磁弁 or ejectSV87_給湯電磁弁 or extSV87_給湯電磁弁) and not(pauseSV87_給湯電磁弁)	'A00658
'SV72_下洗浄電磁弁=(mSV72_下洗浄電磁弁 or ejectSV72_下洗浄電磁弁 or extSV72_下洗浄電磁弁) and not(pauseSV72_下洗浄電磁弁)	'A00659
SV72_下洗浄電磁弁=ON
'SV78_下洗浄電磁弁=(mSV78_下洗浄電磁弁 or ejectSV78_下洗浄電磁弁 or extSV78_下洗浄電磁弁) and not(pauseSV78_下洗浄電磁弁)	'A00660
SV78_下洗浄電磁弁=ON
'SV84_下洗浄電磁弁=(mSV84_下洗浄電磁弁 or ejectSV84_下洗浄電磁弁 or extSV84_下洗浄電磁弁) and not(pauseSV84_下洗浄電磁弁)	'A00661
SV84_下洗浄電磁弁=ON
'SV90_下洗浄電磁弁=(mSV90_下洗浄電磁弁 or ejectSV90_下洗浄電磁弁 or extSV90_下洗浄電磁弁) and not(pauseSV90_下洗浄電磁弁)	'A00662
SV90_下洗浄電磁弁=ON
SV67_釜フタ押さえ下降A=(mSV67_釜フタ押さえ下降A or ejectSV67_釜フタ押さえ下降A or extSV67_釜フタ押さえ下降A) and not(pauseSV67_釜フタ押さえ下降A)	'A00663
SV68_釜フタ押さえ下降B=(mSV68_釜フタ押さえ下降B or ejectSV68_釜フタ押さえ下降B or extSV68_釜フタ押さえ下降B) and not(pauseSV68_釜フタ押さえ下降B)	'A00664
SV71_釜フタストッパ=(mSV71_釜フタストッパ or ejectSV71_釜フタストッパ or extSV71_釜フタストッパ) and not(pauseSV71_釜フタストッパ)	'A00665
SV73_釜フタ押さえ下降A=(mSV73_釜フタ押さえ下降A or ejectSV73_釜フタ押さえ下降A or extSV73_釜フタ押さえ下降A) and not(pauseSV73_釜フタ押さえ下降A)	'A00666
SV74_釜フタ押さえ下降B=(mSV74_釜フタ押さえ下降B or ejectSV74_釜フタ押さえ下降B or extSV74_釜フタ押さえ下降B) and not(pauseSV74_釜フタ押さえ下降B)	'A00667
SV77_釜フタストッパ=(mSV77_釜フタストッパ or ejectSV77_釜フタストッパ or extSV77_釜フタストッパ) and not(pauseSV77_釜フタストッパ)	'A00668
SV79_釜フタ押さえ下降A=(mSV79_釜フタ押さえ下降A or ejectSV79_釜フタ押さえ下降A or extSV79_釜フタ押さえ下降A) and not(pauseSV79_釜フタ押さえ下降A)	'A00669
SV80_釜フタ押さえ下降B=(mSV80_釜フタ押さえ下降B or ejectSV80_釜フタ押さえ下降B or extSV80_釜フタ押さえ下降B) and not(pauseSV80_釜フタ押さえ下降B)	'A00670
SV83_釜フタストッパ=(mSV83_釜フタストッパ or ejectSV83_釜フタストッパ or extSV83_釜フタストッパ) and not(pauseSV83_釜フタストッパ)	'A00671
SV85_釜フタ押さえ下降A=(mSV85_釜フタ押さえ下降A or ejectSV85_釜フタ押さえ下降A or extSV85_釜フタ押さえ下降A) and not(pauseSV85_釜フタ押さえ下降A)	'A00672
SV86_釜フタ押さえ下降B=(mSV86_釜フタ押さえ下降B or ejectSV86_釜フタ押さえ下降B or extSV86_釜フタ押さえ下降B) and not(pauseSV86_釜フタ押さえ下降B)	'A00689
SV89_釜フタストッパ=(mSV89_釜フタストッパ or ejectSV89_釜フタストッパ or extSV89_釜フタストッパ) and not(pauseSV89_釜フタストッパ)	'A00690

'passリレーコマンド	'B00000
passFLOS2_洗米無洗米切換検知=pnlPBFLOS2_洗米無洗米切換検知 and passtimFLOS2_洗米無洗米切換検知.B	'B00040
passFLOS1_計量機近接センサー=pnlPBFLOS1_計量機近接センサー and passtimFLOS1_計量機近接センサー.B	'B00041
passXSW9_送米切換A側=pnlPBXSW9_送米切換A側 and passtimXSW9_送米切換A側.B	'B00078
passXSW10_送米切換B側=pnlPBXSW10_送米切換B側 and passtimXSW10_送米切換B側.B	'B00079
passPDL1_パドルセンサー上限A=pnlPBPDL1_パドルセンサー上限A and passtimPDL1_パドルセンサー上限A.B	'B00080
passPDL2_パドルセンサー下限A=pnlPBPDL2_パドルセンサー下限A and passtimPDL2_パドルセンサー下限A.B	'B00097
passXSW1_充填バルブ開A=pnlPBXSW1_充填バルブ開A and passtimXSW1_充填バルブ開A.B	'B00099
passXSW2_充填バルブ閉A=pnlPBXSW2_充填バルブ閉A and passtimXSW2_充填バルブ閉A.B	'B00100
passXSW3_水切りシャッター開A=pnlPBXSW3_水切りシャッター開A and passtimXSW3_水切りシャッター開A.B	'B00101
passXSW4_水切りシャッター閉A=pnlPBXSW4_水切りシャッター閉A and passtimXSW4_水切りシャッター閉A.B	'B00102
passXSW76_排水バルブ開A=pnlPBXSW76_排水バルブ開A and passtimXSW76_排水バルブ開A.B	'B00103
passXSW77_排水バルブ閉A=pnlPBXSW77_排水バルブ閉A and passtimXSW77_排水バルブ閉A.B	'B00104
passPDL3_パドルセンサー上限B=pnlPBPDL3_パドルセンサー上限B and passtimPDL3_パドルセンサー上限B.B	'B00105
passPDL4_パドルセンサー下限B=pnlPBPDL4_パドルセンサー下限B and passtimPDL4_パドルセンサー下限B.B	'B00106
passXSW5_充填バルブ開B=pnlPBXSW5_充填バルブ開B and passtimXSW5_充填バルブ開B.B	'B00108
passXSW6_充填バルブ閉B=pnlPBXSW6_充填バルブ閉B and passtimXSW6_充填バルブ閉B.B	'B00109
passXSW7_水切りシャッター開B=pnlPBXSW7_水切りシャッター開B and passtimXSW7_水切りシャッター開B.B	'B00110
passXSW8_水切りシャッター閉B=pnlPBXSW8_水切りシャッター閉B and passtimXSW8_水切りシャッター閉B.B	'B00111
passXSW78_排水バルブ開B=pnlPBXSW78_排水バルブ開B and passtimXSW78_排水バルブ開B.B	'B00112
passXSW79_排水バルブ閉B=pnlPBXSW79_排水バルブ閉B and passtimXSW79_排水バルブ閉B.B	'B00129
passFLOS3_LMT121ALM=pnlPBFLOS3_LMT121ALM and passtimFLOS3_LMT121ALM.B	'B00130
passFLOS4_LMT121ALM=pnlPBFLOS4_LMT121ALM and passtimFLOS4_LMT121ALM.B	'B00131
passFLOS3_LMT121=pnlPBFLOS3_LMT121 and passtimFLOS3_LMT121.B	'B00132
passFLOS4_LMT121=pnlPBFLOS4_LMT121 and passtimFLOS4_LMT121.B	'B00133
passXSW18_リフト上昇端=pnlPBXSW18_リフト上昇端 and passtimXSW18_リフト上昇端.B	'B00138
passXSW17_リフト下降端=pnlPBXSW17_リフト下降端 and passtimXSW17_リフト下降端.B	'B00139
passPH60_釜検知=pnlPBPH60_釜検知 and passtimPH60_釜検知.B	'B00140
passPH61_フタ検知=pnlPBPH61_フタ検知 and passtimPH61_フタ検知.B	'B00141
passPH1_釜検知=pnlPBPH1_釜検知 and passtimPH1_釜検知.B	'B00164
passPH2_フタ検知=pnlPBPH2_フタ検知 and passtimPH2_フタ検知.B	'B00165
passPH3_釜検知=pnlPBPH3_釜検知 and passtimPH3_釜検知.B	'B00166
passPH4_フタ検知=pnlPBPH4_フタ検知 and passtimPH4_フタ検知.B	'B00167
passPH5_釜検知=pnlPBPH5_釜検知 and passtimPH5_釜検知.B	'B00168
passPH6_フタ検知=pnlPBPH6_フタ検知 and passtimPH6_フタ検知.B	'B00169
passPH7_釜検知=pnlPBPH7_釜検知 and passtimPH7_釜検知.B	'B00170
passPH8_フタ検知=pnlPBPH8_フタ検知 and passtimPH8_フタ検知.B	'B00171
passXSW14_ストッパ上昇端=pnlPBXSW14_ストッパ上昇端 and passtimXSW14_ストッパ上昇端.B	'B00172
passXSW15_ストッパ下降端=pnlPBXSW15_ストッパ下降端 and passtimXSW15_ストッパ下降端.B	'B00173
passXSW16_ストッパ上昇端=pnlPBXSW16_ストッパ上昇端 and passtimXSW16_ストッパ上昇端.B	'B00174
passXSW17_ストッパ下降端=pnlPBXSW17_ストッパ下降端 and passtimXSW17_ストッパ下降端.B	'B00175
passPH9_釜検知=pnlPBPH9_釜検知 and passtimPH9_釜検知.B	'B00197
passPH10_フタ検知=pnlPBPH10_フタ検知 and passtimPH10_フタ検知.B	'B00198
passPH11_釜検知=pnlPBPH11_釜検知 and passtimPH11_釜検知.B	'B00199
passPH12_フタ検知=pnlPBPH12_フタ検知 and passtimPH12_フタ検知.B	'B00200
passPH13_釜検知=pnlPBPH13_釜検知 and passtimPH13_釜検知.B	'B00201
passPH14_フタ検知=pnlPBPH14_フタ検知 and passtimPH14_フタ検知.B	'B00202
passPH16_フタ検知=pnlPBPH16_フタ検知 and passtimPH16_フタ検知.B	'B00203
passPH15_釜検知=pnlPBPH15_釜検知 and passtimPH15_釜検知.B	'B00204
passXSW18_ストッパ上昇端=pnlPBXSW18_ストッパ上昇端 and passtimXSW18_ストッパ上昇端.B	'B00205
passXSW19_ストッパ下降端=pnlPBXSW19_ストッパ下降端 and passtimXSW19_ストッパ下降端.B	'B00206
passXSW21_リフト上昇端=pnlPBXSW21_リフト上昇端 and passtimXSW21_リフト上昇端.B	'B00207
passXSW20_リフト下降端=pnlPBXSW20_リフト下降端 and passtimXSW20_リフト下降端.B	'B00208
passXSW23_ストッパ上昇端=pnlPBXSW23_ストッパ上昇端 and passtimXSW23_ストッパ上昇端.B	'B00225
passXSW22_ストッパ下降端=pnlPBXSW22_ストッパ下降端 and passtimXSW22_ストッパ下降端.B	'B00226
passXSW25_リフト上昇端=pnlPBXSW25_リフト上昇端 and passtimXSW25_リフト上昇端.B	'B00227
passXSW24_リフト下降端=pnlPBXSW24_リフト下降端 and passtimXSW24_リフト下降端.B	'B00228
passPH17_釜検知=pnlPBPH17_釜検知 and passtimPH17_釜検知.B	'B00233
passPH18_フタ検知=pnlPBPH18_フタ検知 and passtimPH18_フタ検知.B	'B00234
passPH19_釜検知=pnlPBPH19_釜検知 and passtimPH19_釜検知.B	'B00235
passPH20_フタ検知=pnlPBPH20_フタ検知 and passtimPH20_フタ検知.B	'B00236
passPH21_釜検知=pnlPBPH21_釜検知 and passtimPH21_釜検知.B	'B00237
passPH22_釜検知=pnlPBPH22_釜検知 and passtimPH22_釜検知.B	'B00238
passXSW26_クランプ下降端=pnlPBXSW26_クランプ下降端 and passtimXSW26_クランプ下降端.B	'B00239
passXSW27_クランプ上昇端=pnlPBXSW27_クランプ上昇端 and passtimXSW27_クランプ上昇端.B	'B00240
passXSW28_ストッパ下降端=pnlPBXSW28_ストッパ下降端 and passtimXSW28_ストッパ下降端.B	'B00257
passXSW29_ストッパ上昇端=pnlPBXSW29_ストッパ上昇端 and passtimXSW29_ストッパ上昇端.B	'B00258
passXSW30_クランプ下降端=pnlPBXSW30_クランプ下降端 and passtimXSW30_クランプ下降端.B	'B00259
passXSW31_クランプ上昇端=pnlPBXSW31_クランプ上昇端 and passtimXSW31_クランプ上昇端.B	'B00260
passXSW32_ストッパ下降端=pnlPBXSW32_ストッパ下降端 and passtimXSW32_ストッパ下降端.B	'B00261
passXSW33_ストッパ上昇端=pnlPBXSW33_ストッパ上昇端 and passtimXSW33_ストッパ上昇端.B	'B00262
passXSW34_リフト上昇端=pnlPBXSW34_リフト上昇端 and passtimXSW34_リフト上昇端.B	'B00263
passXSW35_リフト下降端=pnlPBXSW35_リフト下降端 and passtimXSW35_リフト下降端.B	'B00264
passXSW36_ストッパ下降端=pnlPBXSW36_ストッパ下降端 and passtimXSW36_ストッパ下降端.B	'B00265
passXSW37_ストッパ上昇端=pnlPBXSW37_ストッパ上昇端 and passtimXSW37_ストッパ上昇端.B	'B00266
passPH23_釜検知=pnlPBPH23_釜検知 and passtimPH23_釜検知.B	'B00269
passXSW25_ならし上昇端=pnlPBXSW25_ならし上昇端 and passtimXSW25_ならし上昇端.B	'B00292
passXSW26_ならし下降端=pnlPBXSW26_ならし下降端 and passtimXSW26_ならし下降端.B	'B00293
passXSW24_ならし前進端=pnlPBXSW24_ならし前進端 and passtimXSW24_ならし前進端.B	'B00294
passXSW23_ならし後退端=pnlPBXSW23_ならし後退端 and passtimXSW23_ならし後退端.B	'B00295
passXSW44_ならし原点センサ=pnlPBXSW44_ならし原点センサ and passtimXSW44_ならし原点センサ.B	'B00296
passXSW39_シリンダ上昇端A=pnlPBXSW39_シリンダ上昇端A and passtimXSW39_シリンダ上昇端A.B	'B00297
passXSW40_シリンダ下降端A=pnlPBXSW40_シリンダ下降端A and passtimXSW40_シリンダ下降端A.B	'B00298
passXSW41_シリンダ上昇端B=pnlPBXSW41_シリンダ上昇端B and passtimXSW41_シリンダ上昇端B.B	'B00299
passXSW42_シリンダ下降端B=pnlPBXSW42_シリンダ下降端B and passtimXSW42_シリンダ下降端B.B	'B00300
passXSW44_アンクランプ=pnlPBXSW44_アンクランプ and passtimXSW44_アンクランプ.B	'B00301
passXSW43_クランプ=pnlPBXSW43_クランプ and passtimXSW43_クランプ.B	'B00302
passXSW51_ストッパ上昇端=pnlPBXSW51_ストッパ上昇端 and passtimXSW51_ストッパ上昇端.B	'B00307
passXSW52_ストッパ下降端=pnlPBXSW52_ストッパ下降端 and passtimXSW52_ストッパ下降端.B	'B00308
passXSW53_リフト上昇端=pnlPBXSW53_リフト上昇端 and passtimXSW53_リフト上昇端.B	'B00309
passXSW54_リフト下降端=pnlPBXSW54_リフト下降端 and passtimXSW54_リフト下降端.B	'B00310
passPH24_釜検知=pnlPBPH24_釜検知 and passtimPH24_釜検知.B	'B00311
passPH25_釜検知=pnlPBPH25_釜検知 and passtimPH25_釜検知.B	'B00328
passPH26_釜検知=pnlPBPH26_釜検知 and passtimPH26_釜検知.B	'B00329
passPH27_釜検知=pnlPBPH27_釜検知 and passtimPH27_釜検知.B	'B00330
passPH28_釜検知=pnlPBPH28_釜検知 and passtimPH28_釜検知.B	'B00331
passPH29_釜検知=pnlPBPH29_釜検知 and passtimPH29_釜検知.B	'B00332
passPH30_釜検知=pnlPBPH30_釜検知 and passtimPH30_釜検知.B	'B00333
passPH31_釜検知=pnlPBPH31_釜検知 and passtimPH31_釜検知.B	'B00360
passPH32_釜検知=pnlPBPH32_釜検知 and passtimPH32_釜検知.B	'B00361
passPH33_釜検知=pnlPBPH33_釜検知 and passtimPH33_釜検知.B	'B00362
passPH34_釜検知=pnlPBPH34_釜検知 and passtimPH34_釜検知.B	'B00363
passPH35_釜検知=pnlPBPH35_釜検知 and passtimPH35_釜検知.B	'B00364
passPH36_釜検知=pnlPBPH36_釜検知 and passtimPH36_釜検知.B	'B00365
passPH37_釜検知=pnlPBPH37_釜検知 and passtimPH37_釜検知.B	'B00392
passPH38_釜検知=pnlPBPH38_釜検知 and passtimPH38_釜検知.B	'B00393
passPH39_釜検知=pnlPBPH39_釜検知 and passtimPH39_釜検知.B	'B00394
passPH40_釜検知=pnlPBPH40_釜検知 and passtimPH40_釜検知.B	'B00395
passPH41_釜検知=pnlPBPH41_釜検知 and passtimPH41_釜検知.B	'B00396
passPH42_釜検知=pnlPBPH42_釜検知 and passtimPH42_釜検知.B	'B00397
passPH43_釜検知=pnlPBPH43_釜検知 and passtimPH43_釜検知.B	'B00424
passPH44_釜検知=pnlPBPH44_釜検知 and passtimPH44_釜検知.B	'B00425
passPH45_釜検知=pnlPBPH45_釜検知 and passtimPH45_釜検知.B	'B00426
passPH46_釜検知=pnlPBPH46_釜検知 and passtimPH46_釜検知.B	'B00427
passPH47_釜検知=pnlPBPH47_釜検知 and passtimPH47_釜検知.B	'B00428
passPH48_釜検知=pnlPBPH48_釜検知 and passtimPH48_釜検知.B	'B00429
passPH49_釜検知=pnlPBPH49_釜検知 and passtimPH49_釜検知.B	'B00452
passPH50_釜検知=pnlPBPH50_釜検知 and passtimPH50_釜検知.B	'B00453
passPH51_釜検知=pnlPBPH51_釜検知 and passtimPH51_釜検知.B	'B00454
passPH52_フタ検知=pnlPBPH52_フタ検知 and passtimPH52_フタ検知.B	'B00455
passXSW55_リフト上昇端=pnlPBXSW55_リフト上昇端 and passtimXSW55_リフト上昇端.B	'B00456
passXSW56_リフト下降端=pnlPBXSW56_リフト下降端 and passtimXSW56_リフト下降端.B	'B00457
passXSW57_リフト上昇端=pnlPBXSW57_リフト上昇端 and passtimXSW57_リフト上昇端.B	'B00458
passXSW58_リフト下降端=pnlPBXSW58_リフト下降端 and passtimXSW58_リフト下降端.B	'B00459
passXSW59_ストッパ上昇端=pnlPBXSW59_ストッパ上昇端 and passtimXSW59_ストッパ上昇端.B	'B00460
passXSW60_ストッパ下降端=pnlPBXSW60_ストッパ下降端 and passtimXSW60_ストッパ下降端.B	'B00461
passXSW61_ストッパ上昇端=pnlPBXSW61_ストッパ上昇端 and passtimXSW61_ストッパ上昇端.B	'B00462
passXSW62_ストッパ下降端=pnlPBXSW62_ストッパ下降端 and passtimXSW62_ストッパ下降端.B	'B00463
passXSW63_ストッパ上昇端=pnlPBXSW63_ストッパ上昇端 and passtimXSW63_ストッパ上昇端.B	'B00464
passXSW64_ストッパ下降端=pnlPBXSW64_ストッパ下降端 and passtimXSW64_ストッパ下降端.B	'B00481
passPH53_釜検知=pnlPBPH53_釜検知 and passtimPH53_釜検知.B	'B00486
passPH54_フタ検知=pnlPBPH54_フタ検知 and passtimPH54_フタ検知.B	'B00487
passXSW65_ストッパ上昇端=pnlPBXSW65_ストッパ上昇端 and passtimXSW65_ストッパ上昇端.B	'B00488
passXSW66_ストッパ下降端=pnlPBXSW66_ストッパ下降端 and passtimXSW66_ストッパ下降端.B	'B00489
passXSW67_リフト上昇端=pnlPBXSW67_リフト上昇端 and passtimXSW67_リフト上昇端.B	'B00490
passXSW68_リフト下降端=pnlPBXSW68_リフト下降端 and passtimXSW68_リフト下降端.B	'B00491
passXSW69_ブラシ上昇端=pnlPBXSW69_ブラシ上昇端 and passtimXSW69_ブラシ上昇端.B	'B00494
passXSW70_ブラシ下降端=pnlPBXSW70_ブラシ下降端 and passtimXSW70_ブラシ下降端.B	'B00495
passXSW55_シリンダ上昇端A=pnlPBXSW55_シリンダ上昇端A and passtimXSW55_シリンダ上昇端A.B	'B00513
passXSW56_シリンダ下降端A=pnlPBXSW56_シリンダ下降端A and passtimXSW56_シリンダ下降端A.B	'B00514
passXSW57_シリンダ上昇端B=pnlPBXSW57_シリンダ上昇端B and passtimXSW57_シリンダ上昇端B.B	'B00515
passXSW58_シリンダ下降端B=pnlPBXSW58_シリンダ下降端B and passtimXSW58_シリンダ下降端B.B	'B00516
passXSW59_アンクランプ=pnlPBXSW59_アンクランプ and passtimXSW59_アンクランプ.B	'B00517
passXSW60_クランプ=pnlPBXSW60_クランプ and passtimXSW60_クランプ.B	'B00518
passXSW80_リフト上昇端=pnlPBXSW80_リフト上昇端 and passtimXSW80_リフト上昇端.B	'B00521
passXSW81_リフト下降端=pnlPBXSW81_リフト下降端 and passtimXSW81_リフト下降端.B	'B00522
passPH55_釜検知=pnlPBPH55_釜検知 and passtimPH55_釜検知.B	'B00523
passPH56_フタ検知=pnlPBPH56_フタ検知 and passtimPH56_フタ検知.B	'B00524
passPH67_釜検知=pnlPBPH67_釜検知 and passtimPH67_釜検知.B	'B00525
passPH68_釜検知=pnlPBPH68_釜検知 and passtimPH68_釜検知.B	'B00526
passPH69_フタ検知=pnlPBPH69_フタ検知 and passtimPH69_フタ検知.B	'B00527
passPH57_釜検知=pnlPBPH57_釜検知 and passtimPH57_釜検知.B	'B00617
passPH58_フタ検知=pnlPBPH58_フタ検知 and passtimPH58_フタ検知.B	'B00618
passLS7_釜反転機原点位置=pnlPBLS7_釜反転機原点位置 and passtimLS7_釜反転機原点位置.B	'B00619
passLS8_釜反転機反転位置=pnlPBLS8_釜反転機反転位置 and passtimLS8_釜反転機反転位置.B	'B00620
passPH59_釜検知=pnlPBPH59_釜検知 and passtimPH59_釜検知.B	'B00621
passPH62_フタ検知=pnlPBPH62_フタ検知 and passtimPH62_フタ検知.B	'B00622
passPH63_釜検知=pnlPBPH63_釜検知 and passtimPH63_釜検知.B	'B00623
passPH64_フタ検知=pnlPBPH64_フタ検知 and passtimPH64_フタ検知.B	'B00624
passLS5_空釜反転原点位置=pnlPBLS5_空釜反転原点位置 and passtimLS5_空釜反転原点位置.B	'B00641
passLS6_空釜反転反転位置=pnlPBLS6_空釜反転反転位置 and passtimLS6_空釜反転反転位置.B	'B00642
passPH65_釜検知=pnlPBPH65_釜検知 and passtimPH65_釜検知.B	'B00643
passPH66_フタ検知=pnlPBPH66_フタ検知 and passtimPH66_フタ検知.B	'B00644
passXSW81_釜フタ押さえ上昇端A=pnlPBXSW81_釜フタ押さえ上昇端A and passtimXSW81_釜フタ押さえ上昇端A.B	'B00645
passXSW82_釜フタ押さえ下降端A=pnlPBXSW82_釜フタ押さえ下降端A and passtimXSW82_釜フタ押さえ下降端A.B	'B00646
passXSW83_釜フタ押さえ上昇端B=pnlPBXSW83_釜フタ押さえ上昇端B and passtimXSW83_釜フタ押さえ上昇端B.B	'B00647
passXSW84_釜フタ押さえ下降端B=pnlPBXSW84_釜フタ押さえ下降端B and passtimXSW84_釜フタ押さえ下降端B.B	'B00648
passXSW85_釜フタストッパ下降端=pnlPBXSW85_釜フタストッパ下降端 and passtimXSW85_釜フタストッパ下降端.B	'B00649
'passLS11_釜フタ検知=pnlPBLS11_釜フタ検知 and passtimLS11_釜フタ検知.B	'B00650
passFLT1_タンク上限=pnlPBFLT1_タンク上限 and passtimFLT1_タンク上限.B	'B00651
passFLT2_タンク下限=pnlPBFLT2_タンク下限 and passtimFLT2_タンク下限.B	'B00652
passXSW86_釜フタ押さえ上昇端A=pnlPBXSW86_釜フタ押さえ上昇端A and passtimXSW86_釜フタ押さえ上昇端A.B	'B00653
passXSW87_釜フタ押さえ下降端A=pnlPBXSW87_釜フタ押さえ下降端A and passtimXSW87_釜フタ押さえ下降端A.B	'B00654
passXSW88_釜フタ押さえ上昇端B=pnlPBXSW88_釜フタ押さえ上昇端B and passtimXSW88_釜フタ押さえ上昇端B.B	'B00655
passXSW89_釜フタ押さえ下降端B=pnlPBXSW89_釜フタ押さえ下降端B and passtimXSW89_釜フタ押さえ下降端B.B	'B00656
passXSW90_釜フタストッパ下降端=pnlPBXSW90_釜フタストッパ下降端 and passtimXSW90_釜フタストッパ下降端.B	'B00673
'passLS12_釜フタ検知=pnlPBLS12_釜フタ検知 and passtimLS12_釜フタ検知.B	'B00674
passFLT3_タンク上限=pnlPBFLT3_タンク上限 and passtimFLT3_タンク上限.B	'B00675
passFLT4_タンク下限=pnlPBFLT4_タンク下限 and passtimFLT4_タンク下限.B	'B00676
passXSW91_釜フタ押さえ上昇端A=pnlPBXSW91_釜フタ押さえ上昇端A and passtimXSW91_釜フタ押さえ上昇端A.B	'B00677
passXSW92_釜フタ押さえ下降端A=pnlPBXSW92_釜フタ押さえ下降端A and passtimXSW92_釜フタ押さえ下降端A.B	'B00678
passXSW93_釜フタ押さえ上昇端B=pnlPBXSW93_釜フタ押さえ上昇端B and passtimXSW93_釜フタ押さえ上昇端B.B	'B00679
passXSW94_釜フタ押さえ下降端B=pnlPBXSW94_釜フタ押さえ下降端B and passtimXSW94_釜フタ押さえ下降端B.B	'B00680
passXSW95_釜フタストッパ下降端=pnlPBXSW95_釜フタストッパ下降端 and passtimXSW95_釜フタストッパ下降端.B	'B00681
'passLS13_釜フタ検知=pnlPBLS13_釜フタ検知 and passtimLS13_釜フタ検知.B	'B00682
passFLT5_タンク上限=pnlPBFLT5_タンク上限 and passtimFLT5_タンク上限.B	'B00683
passFLT6_タンク下限=pnlPBFLT6_タンク下限 and passtimFLT6_タンク下限.B	'B00684
passXSW96_釜フタ押さえ上昇端A=pnlPBXSW96_釜フタ押さえ上昇端A and passtimXSW96_釜フタ押さえ上昇端A.B	'B00685
passXSW97_釜フタ押さえ下降端A=pnlPBXSW97_釜フタ押さえ下降端A and passtimXSW97_釜フタ押さえ下降端A.B	'B00686
passXSW98_釜フタ押さえ上昇端B=pnlPBXSW98_釜フタ押さえ上昇端B and passtimXSW98_釜フタ押さえ上昇端B.B	'B00687
passXSW99_釜フタ押さえ下降端B=pnlPBXSW99_釜フタ押さえ下降端B and passtimXSW99_釜フタ押さえ下降端B.B	'B00688
passXSW100_釜フタストッパ下降端=pnlPBXSW100_釜フタストッパ下降端 and passtimXSW100_釜フタストッパ下降端.B	'B00705
'passLS14_釜フタ検知=pnlPBLS14_釜フタ検知 and passtimLS14_釜フタ検知.B	'B00706
passFLT7_タンク上限=pnlPBFLT7_タンク上限 and passtimFLT7_タンク上限.B	'B00707
passFLT8_タンク下限=pnlPBFLT8_タンク下限 and passtimFLT8_タンク下限.B	'B00708
'Latchリレーコマンド	'C00000
LatchFLOS2_洗米無洗米切換検知=LatchFLOS2_洗米無洗米切換検知 or FLOS2_洗米無洗米切換検知	'C00040
LatchFLOS1_計量機近接センサー=LatchFLOS1_計量機近接センサー or FLOS1_計量機近接センサー	'C00041
LatchXSW9_送米切換A側=LatchXSW9_送米切換A側 or XSW9_送米切換A側	'C00078
LatchXSW10_送米切換B側=LatchXSW10_送米切換B側 or XSW10_送米切換B側	'C00079
LatchPDL1_パドルセンサー上限A=LatchPDL1_パドルセンサー上限A or PDL1_パドルセンサー上限A	'C00080
LatchPDL2_パドルセンサー下限A=LatchPDL2_パドルセンサー下限A or PDL2_パドルセンサー下限A	'C00097
LatchXSW1_充填バルブ開A=LatchXSW1_充填バルブ開A or XSW1_充填バルブ開A	'C00099
LatchXSW2_充填バルブ閉A=LatchXSW2_充填バルブ閉A or XSW2_充填バルブ閉A	'C00100
LatchXSW3_水切りシャッター開A=LatchXSW3_水切りシャッター開A or XSW3_水切りシャッター開A	'C00101
LatchXSW4_水切りシャッター閉A=LatchXSW4_水切りシャッター閉A or XSW4_水切りシャッター閉A	'C00102
LatchXSW76_排水バルブ開A=LatchXSW76_排水バルブ開A or XSW76_排水バルブ開A	'C00103
LatchXSW77_排水バルブ閉A=LatchXSW77_排水バルブ閉A or XSW77_排水バルブ閉A	'C00104
LatchPDL3_パドルセンサー上限B=LatchPDL3_パドルセンサー上限B or PDL3_パドルセンサー上限B	'C00105
LatchPDL4_パドルセンサー下限B=LatchPDL4_パドルセンサー下限B or PDL4_パドルセンサー下限B	'C00106
LatchXSW5_充填バルブ開B=LatchXSW5_充填バルブ開B or XSW5_充填バルブ開B	'C00108
LatchXSW6_充填バルブ閉B=LatchXSW6_充填バルブ閉B or XSW6_充填バルブ閉B	'C00109
LatchXSW7_水切りシャッター開B=LatchXSW7_水切りシャッター開B or XSW7_水切りシャッター開B	'C00110
LatchXSW8_水切りシャッター閉B=LatchXSW8_水切りシャッター閉B or XSW8_水切りシャッター閉B	'C00111
LatchXSW78_排水バルブ開B=LatchXSW78_排水バルブ開B or XSW78_排水バルブ開B	'C00112
LatchXSW79_排水バルブ閉B=LatchXSW79_排水バルブ閉B or XSW79_排水バルブ閉B	'C00129
LatchFLOS3_LMT121ALM=LatchFLOS3_LMT121ALM or FLOS3_LMT121ALM	'C00130
LatchFLOS4_LMT121ALM=LatchFLOS4_LMT121ALM or FLOS4_LMT121ALM	'C00131
LatchFLOS3_LMT121=LatchFLOS3_LMT121 or FLOS3_LMT121	'C00132
LatchFLOS4_LMT121=LatchFLOS4_LMT121 or FLOS4_LMT121	'C00133
LatchXSW18_リフト上昇端=LatchXSW18_リフト上昇端 or XSW18_リフト上昇端	'C00138
LatchXSW17_リフト下降端=LatchXSW17_リフト下降端 or XSW17_リフト下降端	'C00139
LatchPH60_釜検知=LatchPH60_釜検知 or PH60_釜検知	'C00140
LatchPH61_フタ検知=LatchPH61_フタ検知 or PH61_フタ検知	'C00141
LatchPH1_釜検知=LatchPH1_釜検知 or PH1_釜検知	'C00164
LatchPH2_フタ検知=LatchPH2_フタ検知 or PH2_フタ検知	'C00165
LatchPH3_釜検知=LatchPH3_釜検知 or PH3_釜検知	'C00166
LatchPH4_フタ検知=LatchPH4_フタ検知 or PH4_フタ検知	'C00167
LatchPH5_釜検知=LatchPH5_釜検知 or PH5_釜検知	'C00168
LatchPH6_フタ検知=LatchPH6_フタ検知 or PH6_フタ検知	'C00169
LatchPH7_釜検知=LatchPH7_釜検知 or PH7_釜検知	'C00170
LatchPH8_フタ検知=LatchPH8_フタ検知 or PH8_フタ検知	'C00171
LatchXSW14_ストッパ上昇端=LatchXSW14_ストッパ上昇端 or XSW14_ストッパ上昇端	'C00172
LatchXSW15_ストッパ下降端=LatchXSW15_ストッパ下降端 or XSW15_ストッパ下降端	'C00173
LatchXSW16_ストッパ上昇端=LatchXSW16_ストッパ上昇端 or XSW16_ストッパ上昇端	'C00174
LatchXSW17_ストッパ下降端=LatchXSW17_ストッパ下降端 or XSW17_ストッパ下降端	'C00175
LatchPH9_釜検知=LatchPH9_釜検知 or PH9_釜検知	'C00197
LatchPH10_フタ検知=LatchPH10_フタ検知 or PH10_フタ検知	'C00198
LatchPH11_釜検知=LatchPH11_釜検知 or PH11_釜検知	'C00199
LatchPH12_フタ検知=LatchPH12_フタ検知 or PH12_フタ検知	'C00200
LatchPH13_釜検知=LatchPH13_釜検知 or PH13_釜検知	'C00201
LatchPH14_フタ検知=LatchPH14_フタ検知 or PH14_フタ検知	'C00202
LatchPH16_フタ検知=LatchPH16_フタ検知 or PH16_フタ検知	'C00203
LatchPH15_釜検知=LatchPH15_釜検知 or PH15_釜検知	'C00204
LatchXSW18_ストッパ上昇端=LatchXSW18_ストッパ上昇端 or XSW18_ストッパ上昇端	'C00205
LatchXSW19_ストッパ下降端=LatchXSW19_ストッパ下降端 or XSW19_ストッパ下降端	'C00206
LatchXSW21_リフト上昇端=LatchXSW21_リフト上昇端 or XSW21_リフト上昇端	'C00207
LatchXSW20_リフト下降端=LatchXSW20_リフト下降端 or XSW20_リフト下降端	'C00208
LatchXSW23_ストッパ上昇端=LatchXSW23_ストッパ上昇端 or XSW23_ストッパ上昇端	'C00225
LatchXSW22_ストッパ下降端=LatchXSW22_ストッパ下降端 or XSW22_ストッパ下降端	'C00226
LatchXSW25_リフト上昇端=LatchXSW25_リフト上昇端 or XSW25_リフト上昇端	'C00227
LatchXSW24_リフト下降端=LatchXSW24_リフト下降端 or XSW24_リフト下降端	'C00228
LatchPH17_釜検知=LatchPH17_釜検知 or PH17_釜検知	'C00233
LatchPH18_フタ検知=LatchPH18_フタ検知 or PH18_フタ検知	'C00234
LatchPH19_釜検知=LatchPH19_釜検知 or PH19_釜検知	'C00235
LatchPH20_フタ検知=LatchPH20_フタ検知 or PH20_フタ検知	'C00236
LatchPH21_釜検知=LatchPH21_釜検知 or PH21_釜検知	'C00237
LatchPH22_釜検知=LatchPH22_釜検知 or PH22_釜検知	'C00238
LatchXSW26_クランプ下降端=LatchXSW26_クランプ下降端 or XSW26_クランプ下降端	'C00239
LatchXSW27_クランプ上昇端=LatchXSW27_クランプ上昇端 or XSW27_クランプ上昇端	'C00240
LatchXSW28_ストッパ下降端=LatchXSW28_ストッパ下降端 or XSW28_ストッパ下降端	'C00257
LatchXSW29_ストッパ上昇端=LatchXSW29_ストッパ上昇端 or XSW29_ストッパ上昇端	'C00258
LatchXSW30_クランプ下降端=LatchXSW30_クランプ下降端 or XSW30_クランプ下降端	'C00259
LatchXSW31_クランプ上昇端=LatchXSW31_クランプ上昇端 or XSW31_クランプ上昇端	'C00260
LatchXSW32_ストッパ下降端=LatchXSW32_ストッパ下降端 or XSW32_ストッパ下降端	'C00261
LatchXSW33_ストッパ上昇端=LatchXSW33_ストッパ上昇端 or XSW33_ストッパ上昇端	'C00262
LatchXSW34_リフト上昇端=LatchXSW34_リフト上昇端 or XSW34_リフト上昇端	'C00263
LatchXSW35_リフト下降端=LatchXSW35_リフト下降端 or XSW35_リフト下降端	'C00264
LatchXSW36_ストッパ下降端=LatchXSW36_ストッパ下降端 or XSW36_ストッパ下降端	'C00265
LatchXSW37_ストッパ上昇端=LatchXSW37_ストッパ上昇端 or XSW37_ストッパ上昇端	'C00266
LatchPH23_釜検知=LatchPH23_釜検知 or PH23_釜検知	'C00269
LatchXSW25_ならし上昇端=LatchXSW25_ならし上昇端 or XSW25_ならし上昇端	'C00292
LatchXSW26_ならし下降端=LatchXSW26_ならし下降端 or XSW26_ならし下降端	'C00293
LatchXSW24_ならし前進端=LatchXSW24_ならし前進端 or XSW24_ならし前進端	'C00294
LatchXSW23_ならし後退端=LatchXSW23_ならし後退端 or XSW23_ならし後退端	'C00295
LatchXSW44_ならし原点センサ=LatchXSW44_ならし原点センサ or XSW44_ならし原点センサ	'C00296
LatchXSW39_シリンダ上昇端A=LatchXSW39_シリンダ上昇端A or XSW39_シリンダ上昇端A	'C00297
LatchXSW40_シリンダ下降端A=LatchXSW40_シリンダ下降端A or XSW40_シリンダ下降端A	'C00298
LatchXSW41_シリンダ上昇端B=LatchXSW41_シリンダ上昇端B or XSW41_シリンダ上昇端B	'C00299
LatchXSW42_シリンダ下降端B=LatchXSW42_シリンダ下降端B or XSW42_シリンダ下降端B	'C00300
LatchXSW44_アンクランプ=LatchXSW44_アンクランプ or XSW44_アンクランプ	'C00301
LatchXSW43_クランプ=LatchXSW43_クランプ or XSW43_クランプ	'C00302
LatchXSW51_ストッパ上昇端=LatchXSW51_ストッパ上昇端 or XSW51_ストッパ上昇端	'C00307
LatchXSW52_ストッパ下降端=LatchXSW52_ストッパ下降端 or XSW52_ストッパ下降端	'C00308
LatchXSW53_リフト上昇端=LatchXSW53_リフト上昇端 or XSW53_リフト上昇端	'C00309
LatchXSW54_リフト下降端=LatchXSW54_リフト下降端 or XSW54_リフト下降端	'C00310
LatchPH24_釜検知=LatchPH24_釜検知 or PH24_釜検知	'C00311
LatchPH25_釜検知=LatchPH25_釜検知 or PH25_釜検知	'C00328
LatchPH26_釜検知=LatchPH26_釜検知 or PH26_釜検知	'C00329
LatchPH27_釜検知=LatchPH27_釜検知 or PH27_釜検知	'C00330
LatchPH28_釜検知=LatchPH28_釜検知 or PH28_釜検知	'C00331
LatchPH29_釜検知=LatchPH29_釜検知 or PH29_釜検知	'C00332
LatchPH30_釜検知=LatchPH30_釜検知 or PH30_釜検知	'C00333
LatchPH31_釜検知=LatchPH31_釜検知 or PH31_釜検知	'C00360
LatchPH32_釜検知=LatchPH32_釜検知 or PH32_釜検知	'C00361
LatchPH33_釜検知=LatchPH33_釜検知 or PH33_釜検知	'C00362
LatchPH34_釜検知=LatchPH34_釜検知 or PH34_釜検知	'C00363
LatchPH35_釜検知=LatchPH35_釜検知 or PH35_釜検知	'C00364
LatchPH36_釜検知=LatchPH36_釜検知 or PH36_釜検知	'C00365
LatchPH37_釜検知=LatchPH37_釜検知 or PH37_釜検知	'C00392
LatchPH38_釜検知=LatchPH38_釜検知 or PH38_釜検知	'C00393
LatchPH39_釜検知=LatchPH39_釜検知 or PH39_釜検知	'C00394
LatchPH40_釜検知=LatchPH40_釜検知 or PH40_釜検知	'C00395
LatchPH41_釜検知=LatchPH41_釜検知 or PH41_釜検知	'C00396
LatchPH42_釜検知=LatchPH42_釜検知 or PH42_釜検知	'C00397
LatchPH43_釜検知=LatchPH43_釜検知 or PH43_釜検知	'C00424
LatchPH44_釜検知=LatchPH44_釜検知 or PH44_釜検知	'C00425
LatchPH45_釜検知=LatchPH45_釜検知 or PH45_釜検知	'C00426
LatchPH46_釜検知=LatchPH46_釜検知 or PH46_釜検知	'C00427
LatchPH47_釜検知=LatchPH47_釜検知 or PH47_釜検知	'C00428
LatchPH48_釜検知=LatchPH48_釜検知 or PH48_釜検知	'C00429
LatchPH49_釜検知=LatchPH49_釜検知 or PH49_釜検知	'C00452
LatchPH50_釜検知=LatchPH50_釜検知 or PH50_釜検知	'C00453
LatchPH51_釜検知=LatchPH51_釜検知 or PH51_釜検知	'C00454
LatchPH52_フタ検知=LatchPH52_フタ検知 or PH52_フタ検知	'C00455
LatchXSW55_リフト上昇端=LatchXSW55_リフト上昇端 or XSW55_リフト上昇端	'C00456
LatchXSW56_リフト下降端=LatchXSW56_リフト下降端 or XSW56_リフト下降端	'C00457
LatchXSW57_リフト上昇端=LatchXSW57_リフト上昇端 or XSW57_リフト上昇端	'C00458
LatchXSW58_リフト下降端=LatchXSW58_リフト下降端 or XSW58_リフト下降端	'C00459
LatchXSW59_ストッパ上昇端=LatchXSW59_ストッパ上昇端 or XSW59_ストッパ上昇端	'C00460
LatchXSW60_ストッパ下降端=LatchXSW60_ストッパ下降端 or XSW60_ストッパ下降端	'C00461
LatchXSW61_ストッパ上昇端=LatchXSW61_ストッパ上昇端 or XSW61_ストッパ上昇端	'C00462
LatchXSW62_ストッパ下降端=LatchXSW62_ストッパ下降端 or XSW62_ストッパ下降端	'C00463
LatchXSW63_ストッパ上昇端=LatchXSW63_ストッパ上昇端 or XSW63_ストッパ上昇端	'C00464
LatchXSW64_ストッパ下降端=LatchXSW64_ストッパ下降端 or XSW64_ストッパ下降端	'C00481
LatchPH53_釜検知=LatchPH53_釜検知 or PH53_釜検知	'C00486
LatchPH54_フタ検知=LatchPH54_フタ検知 or PH54_フタ検知	'C00487
LatchXSW65_ストッパ上昇端=LatchXSW65_ストッパ上昇端 or XSW65_ストッパ上昇端	'C00488
LatchXSW66_ストッパ下降端=LatchXSW66_ストッパ下降端 or XSW66_ストッパ下降端	'C00489
LatchXSW67_リフト上昇端=LatchXSW67_リフト上昇端 or XSW67_リフト上昇端	'C00490
LatchXSW68_リフト下降端=LatchXSW68_リフト下降端 or XSW68_リフト下降端	'C00491
LatchXSW69_ブラシ上昇端=LatchXSW69_ブラシ上昇端 or XSW69_ブラシ上昇端	'C00494
LatchXSW70_ブラシ下降端=LatchXSW70_ブラシ下降端 or XSW70_ブラシ下降端	'C00495
LatchXSW55_シリンダ上昇端A=LatchXSW55_シリンダ上昇端A or XSW55_シリンダ上昇端A	'C00513
LatchXSW56_シリンダ下降端A=LatchXSW56_シリンダ下降端A or XSW56_シリンダ下降端A	'C00514
LatchXSW57_シリンダ上昇端B=LatchXSW57_シリンダ上昇端B or XSW57_シリンダ上昇端B	'C00515
LatchXSW58_シリンダ下降端B=LatchXSW58_シリンダ下降端B or XSW58_シリンダ下降端B	'C00516
LatchXSW59_アンクランプ=LatchXSW59_アンクランプ or XSW59_アンクランプ	'C00517
LatchXSW60_クランプ=LatchXSW60_クランプ or XSW60_クランプ	'C00518
LatchXSW80_リフト上昇端=LatchXSW80_リフト上昇端 or XSW80_リフト上昇端	'C00521
LatchXSW81_リフト下降端=LatchXSW81_リフト下降端 or XSW81_リフト下降端	'C00522
LatchPH55_釜検知=LatchPH55_釜検知 or PH55_釜検知	'C00523
LatchPH56_フタ検知=LatchPH56_フタ検知 or PH56_フタ検知	'C00524
LatchPH67_釜検知=LatchPH67_釜検知 or PH67_釜検知	'C00525
LatchPH68_釜検知=LatchPH68_釜検知 or PH68_釜検知	'C00526
LatchPH69_フタ検知=LatchPH69_フタ検知 or PH69_フタ検知	'C00527
LatchPH57_釜検知=LatchPH57_釜検知 or PH57_釜検知	'C00617
LatchPH58_フタ検知=LatchPH58_フタ検知 or PH58_フタ検知	'C00618
LatchLS7_釜反転機原点位置=LatchLS7_釜反転機原点位置 or LS7_釜反転機原点位置	'C00619
LatchLS8_釜反転機反転位置=LatchLS8_釜反転機反転位置 or LS8_釜反転機反転位置	'C00620
LatchPH59_釜検知=LatchPH59_釜検知 or PH59_釜検知	'C00621
LatchPH62_フタ検知=LatchPH62_フタ検知 or PH62_フタ検知	'C00622
LatchPH63_釜検知=LatchPH63_釜検知 or PH63_釜検知	'C00623
LatchPH64_フタ検知=LatchPH64_フタ検知 or PH64_フタ検知	'C00624
LatchLS5_空釜反転原点位置=LatchLS5_空釜反転原点位置 or LS5_空釜反転原点位置	'C00641
LatchLS6_空釜反転反転位置=LatchLS6_空釜反転反転位置 or LS6_空釜反転反転位置	'C00642
LatchPH65_釜検知=LatchPH65_釜検知 or PH65_釜検知	'C00643
LatchPH66_フタ検知=LatchPH66_フタ検知 or PH66_フタ検知	'C00644
LatchXSW81_釜フタ押さえ上昇端A=LatchXSW81_釜フタ押さえ上昇端A or XSW81_釜フタ押さえ上昇端A	'C00645
LatchXSW82_釜フタ押さえ下降端A=LatchXSW82_釜フタ押さえ下降端A or XSW82_釜フタ押さえ下降端A	'C00646
LatchXSW83_釜フタ押さえ上昇端B=LatchXSW83_釜フタ押さえ上昇端B or XSW83_釜フタ押さえ上昇端B	'C00647
LatchXSW84_釜フタ押さえ下降端B=LatchXSW84_釜フタ押さえ下降端B or XSW84_釜フタ押さえ下降端B	'C00648
LatchXSW85_釜フタストッパ下降端=LatchXSW85_釜フタストッパ下降端 or XSW85_釜フタストッパ下降端	'C00649
'LatchLS11_釜フタ検知=LatchLS11_釜フタ検知 or LS11_釜フタ検知	'C00650
LatchFLT1_タンク上限=LatchFLT1_タンク上限 or FLT1_タンク上限	'C00651
LatchFLT2_タンク下限=LatchFLT2_タンク下限 or FLT2_タンク下限	'C00652
LatchXSW86_釜フタ押さえ上昇端A=LatchXSW86_釜フタ押さえ上昇端A or XSW86_釜フタ押さえ上昇端A	'C00653
LatchXSW87_釜フタ押さえ下降端A=LatchXSW87_釜フタ押さえ下降端A or XSW87_釜フタ押さえ下降端A	'C00654
LatchXSW88_釜フタ押さえ上昇端B=LatchXSW88_釜フタ押さえ上昇端B or XSW88_釜フタ押さえ上昇端B	'C00655
LatchXSW89_釜フタ押さえ下降端B=LatchXSW89_釜フタ押さえ下降端B or XSW89_釜フタ押さえ下降端B	'C00656
LatchXSW90_釜フタストッパ下降端=LatchXSW90_釜フタストッパ下降端 or XSW90_釜フタストッパ下降端	'C00673
'LatchLS12_釜フタ検知=LatchLS12_釜フタ検知 or LS12_釜フタ検知	'C00674
LatchFLT3_タンク上限=LatchFLT3_タンク上限 or FLT3_タンク上限	'C00675
LatchFLT4_タンク下限=LatchFLT4_タンク下限 or FLT4_タンク下限	'C00676
LatchXSW91_釜フタ押さえ上昇端A=LatchXSW91_釜フタ押さえ上昇端A or XSW91_釜フタ押さえ上昇端A	'C00677
LatchXSW92_釜フタ押さえ下降端A=LatchXSW92_釜フタ押さえ下降端A or XSW92_釜フタ押さえ下降端A	'C00678
LatchXSW93_釜フタ押さえ上昇端B=LatchXSW93_釜フタ押さえ上昇端B or XSW93_釜フタ押さえ上昇端B	'C00679
LatchXSW94_釜フタ押さえ下降端B=LatchXSW94_釜フタ押さえ下降端B or XSW94_釜フタ押さえ下降端B	'C00680
LatchXSW95_釜フタストッパ下降端=LatchXSW95_釜フタストッパ下降端 or XSW95_釜フタストッパ下降端	'C00681
'LatchLS13_釜フタ検知=LatchLS13_釜フタ検知 or LS13_釜フタ検知	'C00682
LatchFLT5_タンク上限=LatchFLT5_タンク上限 or FLT5_タンク上限	'C00683
LatchFLT6_タンク下限=LatchFLT6_タンク下限 or FLT6_タンク下限	'C00684
LatchXSW96_釜フタ押さえ上昇端A=LatchXSW96_釜フタ押さえ上昇端A or XSW96_釜フタ押さえ上昇端A	'C00685
LatchXSW97_釜フタ押さえ下降端A=LatchXSW97_釜フタ押さえ下降端A or XSW97_釜フタ押さえ下降端A	'C00686
LatchXSW98_釜フタ押さえ上昇端B=LatchXSW98_釜フタ押さえ上昇端B or XSW98_釜フタ押さえ上昇端B	'C00687
LatchXSW99_釜フタ押さえ下降端B=LatchXSW99_釜フタ押さえ下降端B or XSW99_釜フタ押さえ下降端B	'C00688
LatchXSW100_釜フタストッパ下降端=LatchXSW100_釜フタストッパ下降端 or XSW100_釜フタストッパ下降端	'C00705
'LatchLS14_釜フタ検知=LatchLS14_釜フタ検知 or LS14_釜フタ検知	'C00706
LatchFLT7_タンク上限=LatchFLT7_タンク上限 or FLT7_タンク上限	'C00707
LatchFLT8_タンク下限=LatchFLT8_タンク下限 or FLT8_タンク下限	'C00708
notFLOS2_洗米無洗米切換検知=not(FLOS2_洗米無洗米切換検知)	'C10040
notFLOS1_計量機近接センサー=not(FLOS1_計量機近接センサー)	'C10041
notXSW9_送米切換A側=not(XSW9_送米切換A側)	'C10078
notXSW10_送米切換B側=not(XSW10_送米切換B側)	'C10079
notPDL1_パドルセンサー上限A=not(PDL1_パドルセンサー上限A)	'C10080
notPDL2_パドルセンサー下限A=not(PDL2_パドルセンサー下限A)	'C10097
notXSW1_充填バルブ開A=not(XSW1_充填バルブ開A)	'C10099
notXSW2_充填バルブ閉A=not(XSW2_充填バルブ閉A)	'C10100
notXSW3_水切りシャッター開A=not(XSW3_水切りシャッター開A)	'C10101
notXSW4_水切りシャッター閉A=not(XSW4_水切りシャッター閉A)	'C10102
notXSW76_排水バルブ開A=not(XSW76_排水バルブ開A)	'C10103
notXSW77_排水バルブ閉A=not(XSW77_排水バルブ閉A)	'C10104
notPDL3_パドルセンサー上限B=not(PDL3_パドルセンサー上限B)	'C10105
notPDL4_パドルセンサー下限B=not(PDL4_パドルセンサー下限B)	'C10106
notXSW5_充填バルブ開B=not(XSW5_充填バルブ開B)	'C10108
notXSW6_充填バルブ閉B=not(XSW6_充填バルブ閉B)	'C10109
notXSW7_水切りシャッター開B=not(XSW7_水切りシャッター開B)	'C10110
notXSW8_水切りシャッター閉B=not(XSW8_水切りシャッター閉B)	'C10111
notXSW78_排水バルブ開B=not(XSW78_排水バルブ開B)	'C10112
notXSW79_排水バルブ閉B=not(XSW79_排水バルブ閉B)	'C10129
notFLOS3_LMT121ALM=not(FLOS3_LMT121ALM)	'C10130
notFLOS4_LMT121ALM=not(FLOS4_LMT121ALM)	'C10131
notFLOS3_LMT121=not(FLOS3_LMT121)	'C10132
notFLOS4_LMT121=not(FLOS4_LMT121)	'C10133
notXSW18_リフト上昇端=not(XSW18_リフト上昇端)	'C10138
notXSW17_リフト下降端=not(XSW17_リフト下降端)	'C10139
notPH60_釜検知=not(PH60_釜検知)	'C10140
notPH61_フタ検知=not(PH61_フタ検知)	'C10141
notPH1_釜検知=not(PH1_釜検知)	'C10164
notPH2_フタ検知=not(PH2_フタ検知)	'C10165
notPH3_釜検知=not(PH3_釜検知)	'C10166
notPH4_フタ検知=not(PH4_フタ検知)	'C10167
notPH5_釜検知=not(PH5_釜検知)	'C10168
notPH6_フタ検知=not(PH6_フタ検知)	'C10169
notPH7_釜検知=not(PH7_釜検知)	'C10170
notPH8_フタ検知=not(PH8_フタ検知)	'C10171
notXSW14_ストッパ上昇端=not(XSW14_ストッパ上昇端)	'C10172
notXSW15_ストッパ下降端=not(XSW15_ストッパ下降端)	'C10173
notXSW16_ストッパ上昇端=not(XSW16_ストッパ上昇端)	'C10174
notXSW17_ストッパ下降端=not(XSW17_ストッパ下降端)	'C10175
notPH9_釜検知=not(PH9_釜検知)	'C10197
notPH10_フタ検知=not(PH10_フタ検知)	'C10198
notPH11_釜検知=not(PH11_釜検知)	'C10199
notPH12_フタ検知=not(PH12_フタ検知)	'C10200
notPH13_釜検知=not(PH13_釜検知)	'C10201
notPH14_フタ検知=not(PH14_フタ検知)	'C10202
notPH16_フタ検知=not(PH16_フタ検知)	'C10203
notPH15_釜検知=not(PH15_釜検知)	'C10204
notXSW18_ストッパ上昇端=not(XSW18_ストッパ上昇端)	'C10205
notXSW19_ストッパ下降端=not(XSW19_ストッパ下降端)	'C10206
notXSW21_リフト上昇端=not(XSW21_リフト上昇端)	'C10207
notXSW20_リフト下降端=not(XSW20_リフト下降端)	'C10208
notXSW23_ストッパ上昇端=not(XSW23_ストッパ上昇端)	'C10225
notXSW22_ストッパ下降端=not(XSW22_ストッパ下降端)	'C10226
notXSW25_リフト上昇端=not(XSW25_リフト上昇端)	'C10227
notXSW24_リフト下降端=not(XSW24_リフト下降端)	'C10228
notPH17_釜検知=not(PH17_釜検知)	'C10233
notPH18_フタ検知=not(PH18_フタ検知)	'C10234
notPH19_釜検知=not(PH19_釜検知)	'C10235
notPH20_フタ検知=not(PH20_フタ検知)	'C10236
notPH21_釜検知=not(PH21_釜検知)	'C10237
notPH22_釜検知=not(PH22_釜検知)	'C10238
notXSW26_クランプ下降端=not(XSW26_クランプ下降端)	'C10239
notXSW27_クランプ上昇端=not(XSW27_クランプ上昇端)	'C10240
notXSW28_ストッパ下降端=not(XSW28_ストッパ下降端)	'C10257
notXSW29_ストッパ上昇端=not(XSW29_ストッパ上昇端)	'C10258
notXSW30_クランプ下降端=not(XSW30_クランプ下降端)	'C10259
notXSW31_クランプ上昇端=not(XSW31_クランプ上昇端)	'C10260
notXSW32_ストッパ下降端=not(XSW32_ストッパ下降端)	'C10261
notXSW33_ストッパ上昇端=not(XSW33_ストッパ上昇端)	'C10262
notXSW34_リフト上昇端=not(XSW34_リフト上昇端)	'C10263
notXSW35_リフト下降端=not(XSW35_リフト下降端)	'C10264
notXSW36_ストッパ下降端=not(XSW36_ストッパ下降端)	'C10265
notXSW37_ストッパ上昇端=not(XSW37_ストッパ上昇端)	'C10266
notPH23_釜検知=not(PH23_釜検知)	'C10269
notXSW25_ならし上昇端=not(XSW25_ならし上昇端)	'C10292
notXSW26_ならし下降端=not(XSW26_ならし下降端)	'C10293
notXSW24_ならし前進端=not(XSW24_ならし前進端)	'C10294
notXSW23_ならし後退端=not(XSW23_ならし後退端)	'C10295
notXSW44_ならし原点センサ=not(XSW44_ならし原点センサ)	'C10296
notXSW39_シリンダ上昇端A=not(XSW39_シリンダ上昇端A)	'C10297
notXSW40_シリンダ下降端A=not(XSW40_シリンダ下降端A)	'C10298
notXSW41_シリンダ上昇端B=not(XSW41_シリンダ上昇端B)	'C10299
notXSW42_シリンダ下降端B=not(XSW42_シリンダ下降端B)	'C10300
notXSW44_アンクランプ=not(XSW44_アンクランプ)	'C10301
notXSW43_クランプ=not(XSW43_クランプ)	'C10302
notXSW51_ストッパ上昇端=not(XSW51_ストッパ上昇端)	'C10307
notXSW52_ストッパ下降端=not(XSW52_ストッパ下降端)	'C10308
notXSW53_リフト上昇端=not(XSW53_リフト上昇端)	'C10309
notXSW54_リフト下降端=not(XSW54_リフト下降端)	'C10310
notPH24_釜検知=not(PH24_釜検知)	'C10311
notPH25_釜検知=not(PH25_釜検知)	'C10328
notPH26_釜検知=not(PH26_釜検知)	'C10329
notPH27_釜検知=not(PH27_釜検知)	'C10330
notPH28_釜検知=not(PH28_釜検知)	'C10331
notPH29_釜検知=not(PH29_釜検知)	'C10332
notPH30_釜検知=not(PH30_釜検知)	'C10333
notPH31_釜検知=not(PH31_釜検知)	'C10360
notPH32_釜検知=not(PH32_釜検知)	'C10361
notPH33_釜検知=not(PH33_釜検知)	'C10362
notPH34_釜検知=not(PH34_釜検知)	'C10363
notPH35_釜検知=not(PH35_釜検知)	'C10364
notPH36_釜検知=not(PH36_釜検知)	'C10365
notPH37_釜検知=not(PH37_釜検知)	'C10392
notPH38_釜検知=not(PH38_釜検知)	'C10393
notPH39_釜検知=not(PH39_釜検知)	'C10394
notPH40_釜検知=not(PH40_釜検知)	'C10395
notPH41_釜検知=not(PH41_釜検知)	'C10396
notPH42_釜検知=not(PH42_釜検知)	'C10397
notPH43_釜検知=not(PH43_釜検知)	'C10424
notPH44_釜検知=not(PH44_釜検知)	'C10425
notPH45_釜検知=not(PH45_釜検知)	'C10426
notPH46_釜検知=not(PH46_釜検知)	'C10427
notPH47_釜検知=not(PH47_釜検知)	'C10428
notPH48_釜検知=not(PH48_釜検知)	'C10429
notPH49_釜検知=not(PH49_釜検知)	'C10452
notPH50_釜検知=not(PH50_釜検知)	'C10453
notPH51_釜検知=not(PH51_釜検知)	'C10454
notPH52_フタ検知=not(PH52_フタ検知)	'C10455
notXSW55_リフト上昇端=not(XSW55_リフト上昇端)	'C10456
notXSW56_リフト下降端=not(XSW56_リフト下降端)	'C10457
notXSW57_リフト上昇端=not(XSW57_リフト上昇端)	'C10458
notXSW58_リフト下降端=not(XSW58_リフト下降端)	'C10459
notXSW59_ストッパ上昇端=not(XSW59_ストッパ上昇端)	'C10460
notXSW60_ストッパ下降端=not(XSW60_ストッパ下降端)	'C10461
notXSW61_ストッパ上昇端=not(XSW61_ストッパ上昇端)	'C10462
notXSW62_ストッパ下降端=not(XSW62_ストッパ下降端)	'C10463
notXSW63_ストッパ上昇端=not(XSW63_ストッパ上昇端)	'C10464
notXSW64_ストッパ下降端=not(XSW64_ストッパ下降端)	'C10481
notPH53_釜検知=not(PH53_釜検知)	'C10486
notPH54_フタ検知=not(PH54_フタ検知)	'C10487
notXSW65_ストッパ上昇端=not(XSW65_ストッパ上昇端)	'C10488
notXSW66_ストッパ下降端=not(XSW66_ストッパ下降端)	'C10489
notXSW67_リフト上昇端=not(XSW67_リフト上昇端)	'C10490
notXSW68_リフト下降端=not(XSW68_リフト下降端)	'C10491
notXSW69_ブラシ上昇端=not(XSW69_ブラシ上昇端)	'C10494
notXSW70_ブラシ下降端=not(XSW70_ブラシ下降端)	'C10495
notXSW55_シリンダ上昇端A=not(XSW55_シリンダ上昇端A)	'C10513
notXSW56_シリンダ下降端A=not(XSW56_シリンダ下降端A)	'C10514
notXSW57_シリンダ上昇端B=not(XSW57_シリンダ上昇端B)	'C10515
notXSW58_シリンダ下降端B=not(XSW58_シリンダ下降端B)	'C10516
notXSW59_アンクランプ=not(XSW59_アンクランプ)	'C10517
notXSW60_クランプ=not(XSW60_クランプ)	'C10518
notXSW80_リフト上昇端=not(XSW80_リフト上昇端)	'C10521
notXSW81_リフト下降端=not(XSW81_リフト下降端)	'C10522
notPH55_釜検知=not(PH55_釜検知)	'C10523
notPH56_フタ検知=not(PH56_フタ検知)	'C10524
notPH67_釜検知=not(PH67_釜検知)	'C10525
notPH68_釜検知=not(PH68_釜検知)	'C10526
notPH69_フタ検知=not(PH69_フタ検知)	'C10527
notPH57_釜検知=not(PH57_釜検知)	'C10617
notPH58_フタ検知=not(PH58_フタ検知)	'C10618
notLS7_釜反転機原点位置=not(LS7_釜反転機原点位置)	'C10619
notLS8_釜反転機反転位置=not(LS8_釜反転機反転位置)	'C10620
notPH59_釜検知=not(PH59_釜検知)	'C10621
notPH62_フタ検知=not(PH62_フタ検知)	'C10622
notPH63_釜検知=not(PH63_釜検知)	'C10623
notPH64_フタ検知=not(PH64_フタ検知)	'C10624
notLS5_空釜反転原点位置=not(LS5_空釜反転原点位置)	'C10641
notLS6_空釜反転反転位置=not(LS6_空釜反転反転位置)	'C10642
notPH65_釜検知=not(PH65_釜検知)	'C10643
notPH66_フタ検知=not(PH66_フタ検知)	'C10644
notXSW81_釜フタ押さえ上昇端A=not(XSW81_釜フタ押さえ上昇端A)	'C10645
notXSW82_釜フタ押さえ下降端A=not(XSW82_釜フタ押さえ下降端A)	'C10646
notXSW83_釜フタ押さえ上昇端B=not(XSW83_釜フタ押さえ上昇端B)	'C10647
notXSW84_釜フタ押さえ下降端B=not(XSW84_釜フタ押さえ下降端B)	'C10648
notXSW85_釜フタストッパ下降端=not(XSW85_釜フタストッパ下降端)	'C10649
'notLS11_釜フタ検知=not(LS11_釜フタ検知)	'C10650
notFLT1_タンク上限=not(FLT1_タンク上限)	'C10651
notFLT2_タンク下限=not(FLT2_タンク下限)	'C10652
notXSW86_釜フタ押さえ上昇端A=not(XSW86_釜フタ押さえ上昇端A)	'C10653
notXSW87_釜フタ押さえ下降端A=not(XSW87_釜フタ押さえ下降端A)	'C10654
notXSW88_釜フタ押さえ上昇端B=not(XSW88_釜フタ押さえ上昇端B)	'C10655
notXSW89_釜フタ押さえ下降端B=not(XSW89_釜フタ押さえ下降端B)	'C10656
notXSW90_釜フタストッパ下降端=not(XSW90_釜フタストッパ下降端)	'C10673
'notLS12_釜フタ検知=not(LS12_釜フタ検知)	'C10674
notFLT3_タンク上限=not(FLT3_タンク上限)	'C10675
notFLT4_タンク下限=not(FLT4_タンク下限)	'C10676
notXSW91_釜フタ押さえ上昇端A=not(XSW91_釜フタ押さえ上昇端A)	'C10677
notXSW92_釜フタ押さえ下降端A=not(XSW92_釜フタ押さえ下降端A)	'C10678
notXSW93_釜フタ押さえ上昇端B=not(XSW93_釜フタ押さえ上昇端B)	'C10679
notXSW94_釜フタ押さえ下降端B=not(XSW94_釜フタ押さえ下降端B)	'C10680
notXSW95_釜フタストッパ下降端=not(XSW95_釜フタストッパ下降端)	'C10681
'notLS13_釜フタ検知=not(LS13_釜フタ検知)	'C10682
notFLT5_タンク上限=not(FLT5_タンク上限)	'C10683
notFLT6_タンク下限=not(FLT6_タンク下限)	'C10684
notXSW96_釜フタ押さえ上昇端A=not(XSW96_釜フタ押さえ上昇端A)	'C10685
notXSW97_釜フタ押さえ下降端A=not(XSW97_釜フタ押さえ下降端A)	'C10686
notXSW98_釜フタ押さえ上昇端B=not(XSW98_釜フタ押さえ上昇端B)	'C10687
notXSW99_釜フタ押さえ下降端B=not(XSW99_釜フタ押さえ下降端B)	'C10688
notXSW100_釜フタストッパ下降端=not(XSW100_釜フタストッパ下降端)	'C10705
'notLS14_釜フタ検知=not(LS14_釜フタ検知)	'C10706
notFLT7_タンク上限=not(FLT7_タンク上限)	'C10707
notFLT8_タンク下限=not(FLT8_タンク下限)	'C10708
tmr(FLOS2_洗米無洗米切換検知,timFLOS2_洗米無洗米切換検知,#10)	'D00040
tmr(FLOS1_計量機近接センサー,timFLOS1_計量機近接センサー,#10)	'D00041
tmr(XSW9_送米切換A側,timXSW9_送米切換A側,#10)	'D00078
tmr(XSW10_送米切換B側,timXSW10_送米切換B側,#10)	'D00079
'tmr(PDL1_パドルセンサー上限A,timPDL1_パドルセンサー上限A,#10)	'D00080
tmr(PDL2_パドルセンサー下限A,timPDL2_パドルセンサー下限A,#10)	'D00097
tmr(XSW1_充填バルブ開A,timXSW1_充填バルブ開A,#10)	'D00099
tmr(XSW2_充填バルブ閉A,timXSW2_充填バルブ閉A,#10)	'D00100
tmr(XSW3_水切りシャッター開A,timXSW3_水切りシャッター開A,#10)	'D00101
tmr(XSW4_水切りシャッター閉A,timXSW4_水切りシャッター閉A,#10)	'D00102
tmr(XSW76_排水バルブ開A,timXSW76_排水バルブ開A,#10)	'D00103
tmr(XSW77_排水バルブ閉A,timXSW77_排水バルブ閉A,#10)	'D00104
'tmr(PDL3_パドルセンサー上限B,timPDL3_パドルセンサー上限B,#10)	'D00105
tmr(PDL4_パドルセンサー下限B,timPDL4_パドルセンサー下限B,#10)	'D00106
tmr(XSW5_充填バルブ開B,timXSW5_充填バルブ開B,#10)	'D00108
tmr(XSW6_充填バルブ閉B,timXSW6_充填バルブ閉B,#10)	'D00109
tmr(XSW7_水切りシャッター開B,timXSW7_水切りシャッター開B,#10)	'D00110
tmr(XSW8_水切りシャッター閉B,timXSW8_水切りシャッター閉B,#10)	'D00111
tmr(XSW78_排水バルブ開B,timXSW78_排水バルブ開B,#10)	'D00112
tmr(XSW79_排水バルブ閉B,timXSW79_排水バルブ閉B,#10)	'D00129
tmr(FLOS3_LMT121ALM,timFLOS3_LMT121ALM,#10)	'D00130
tmr(FLOS4_LMT121ALM,timFLOS4_LMT121ALM,#10)	'D00131
tmr(FLOS3_LMT121,timFLOS3_LMT121,#10)	'D00132
tmr(FLOS4_LMT121,timFLOS4_LMT121,#10)	'D00133
tmr(XSW18_リフト上昇端,timXSW18_リフト上昇端,#10)	'D00138
tmr(XSW17_リフト下降端,timXSW17_リフト下降端,#10)	'D00139
tmr(PH60_釜検知,timPH60_釜検知,#10)	'D00140
tmr(PH61_フタ検知,timPH61_フタ検知,#10)	'D00141
tmr(PH1_釜検知,timPH1_釜検知,#10)	'D00164
tmr(PH2_フタ検知,timPH2_フタ検知,#10)	'D00165
tmr(PH3_釜検知,timPH3_釜検知,#10)	'D00166
tmr(PH4_フタ検知,timPH4_フタ検知,#10)	'D00167
tmr(PH5_釜検知,timPH5_釜検知,#10)	'D00168
tmr(PH6_フタ検知,timPH6_フタ検知,#10)	'D00169
tmr(PH7_釜検知,timPH7_釜検知,#10)	'D00170
tmr(PH8_フタ検知,timPH8_フタ検知,#10)	'D00171
tmr(XSW14_ストッパ上昇端,timXSW14_ストッパ上昇端,#10)	'D00172
tmr(XSW15_ストッパ下降端,timXSW15_ストッパ下降端,#10)	'D00173
tmr(XSW16_ストッパ上昇端,timXSW16_ストッパ上昇端,#10)	'D00174
tmr(XSW17_ストッパ下降端,timXSW17_ストッパ下降端,#10)	'D00175
tmr(PH9_釜検知,timPH9_釜検知,#10)	'D00197
tmr(PH10_フタ検知,timPH10_フタ検知,#10)	'D00198
tmr(PH11_釜検知,timPH11_釜検知,#10)	'D00199
tmr(PH12_フタ検知,timPH12_フタ検知,#10)	'D00200
tmr(PH13_釜検知,timPH13_釜検知,#10)	'D00201
tmr(PH14_フタ検知,timPH14_フタ検知,#10)	'D00202
tmr(PH16_フタ検知,timPH16_フタ検知,#10)	'D00203
tmr(PH15_釜検知,timPH15_釜検知,#10)	'D00204
tmr(XSW18_ストッパ上昇端,timXSW18_ストッパ上昇端,#10)	'D00205
tmr(XSW19_ストッパ下降端,timXSW19_ストッパ下降端,#10)	'D00206
tmr(XSW21_リフト上昇端,timXSW21_リフト上昇端,#10)	'D00207
tmr(XSW20_リフト下降端,timXSW20_リフト下降端,#10)	'D00208
tmr(XSW23_ストッパ上昇端,timXSW23_ストッパ上昇端,#10)	'D00225
tmr(XSW22_ストッパ下降端,timXSW22_ストッパ下降端,#10)	'D00226
tmr(XSW25_リフト上昇端,timXSW25_リフト上昇端,#10)	'D00227
tmr(XSW24_リフト下降端,timXSW24_リフト下降端,#10)	'D00228
tmr(PH17_釜検知,timPH17_釜検知,#10)	'D00233
tmr(PH18_フタ検知,timPH18_フタ検知,#10)	'D00234
tmr(PH19_釜検知,timPH19_釜検知,#10)	'D00235
tmr(PH20_フタ検知,timPH20_フタ検知,#10)	'D00236
tmr(PH21_釜検知,timPH21_釜検知,#10)	'D00237
tmr(PH22_釜検知,timPH22_釜検知,#10)	'D00238
tmr(XSW26_クランプ下降端,timXSW26_クランプ下降端,#10)	'D00239
tmr(XSW27_クランプ上昇端,timXSW27_クランプ上昇端,#10)	'D00240
tmr(XSW28_ストッパ下降端,timXSW28_ストッパ下降端,#10)	'D00257
tmr(XSW29_ストッパ上昇端,timXSW29_ストッパ上昇端,#10)	'D00258
tmr(XSW30_クランプ下降端,timXSW30_クランプ下降端,#10)	'D00259
tmr(XSW31_クランプ上昇端,timXSW31_クランプ上昇端,#10)	'D00260
tmr(XSW32_ストッパ下降端,timXSW32_ストッパ下降端,#10)	'D00261
tmr(XSW33_ストッパ上昇端,timXSW33_ストッパ上昇端,#10)	'D00262
tmr(XSW34_リフト上昇端,timXSW34_リフト上昇端,#10)	'D00263
tmr(XSW35_リフト下降端,timXSW35_リフト下降端,#10)	'D00264
tmr(XSW36_ストッパ下降端,timXSW36_ストッパ下降端,#10)	'D00265
tmr(XSW37_ストッパ上昇端,timXSW37_ストッパ上昇端,#10)	'D00266
tmr(PH23_釜検知,timPH23_釜検知,#10)	'D00269
tmr(XSW25_ならし上昇端,timXSW25_ならし上昇端,#10)	'D00292
tmr(XSW26_ならし下降端,timXSW26_ならし下降端,#10)	'D00293
tmr(XSW24_ならし前進端,timXSW24_ならし前進端,#10)	'D00294
tmr(XSW23_ならし後退端,timXSW23_ならし後退端,#10)	'D00295
tmr(XSW44_ならし原点センサ,timXSW44_ならし原点センサ,#10)	'D00296
tmr(XSW39_シリンダ上昇端A,timXSW39_シリンダ上昇端A,#10)	'D00297
tmr(XSW40_シリンダ下降端A,timXSW40_シリンダ下降端A,#10)	'D00298
tmr(XSW41_シリンダ上昇端B,timXSW41_シリンダ上昇端B,#10)	'D00299
tmr(XSW42_シリンダ下降端B,timXSW42_シリンダ下降端B,#10)	'D00300
tmr(XSW44_アンクランプ,timXSW44_アンクランプ,#10)	'D00301
tmr(XSW43_クランプ,timXSW43_クランプ,#10)	'D00302
tmr(XSW51_ストッパ上昇端,timXSW51_ストッパ上昇端,#10)	'D00307
tmr(XSW52_ストッパ下降端,timXSW52_ストッパ下降端,#10)	'D00308
tmr(XSW53_リフト上昇端,timXSW53_リフト上昇端,#10)	'D00309
tmr(XSW54_リフト下降端,timXSW54_リフト下降端,#10)	'D00310
tmr(PH24_釜検知,timPH24_釜検知,#10)	'D00311
tmr(PH25_釜検知,timPH25_釜検知,#10)	'D00328
tmr(PH26_釜検知,timPH26_釜検知,#10)	'D00329
tmr(PH27_釜検知,timPH27_釜検知,#10)	'D00330
tmr(PH28_釜検知,timPH28_釜検知,#10)	'D00331
tmr(PH29_釜検知,timPH29_釜検知,#10)	'D00332
tmr(PH30_釜検知,timPH30_釜検知,#10)	'D00333
tmr(PH31_釜検知,timPH31_釜検知,#10)	'D00360
tmr(PH32_釜検知,timPH32_釜検知,#10)	'D00361
tmr(PH33_釜検知,timPH33_釜検知,#10)	'D00362
tmr(PH34_釜検知,timPH34_釜検知,#10)	'D00363
tmr(PH35_釜検知,timPH35_釜検知,#10)	'D00364
tmr(PH36_釜検知,timPH36_釜検知,#10)	'D00365
tmr(PH37_釜検知,timPH37_釜検知,#10)	'D00392
tmr(PH38_釜検知,timPH38_釜検知,#10)	'D00393
tmr(PH39_釜検知,timPH39_釜検知,#10)	'D00394
tmr(PH40_釜検知,timPH40_釜検知,#10)	'D00395
tmr(PH41_釜検知,timPH41_釜検知,#10)	'D00396
tmr(PH42_釜検知,timPH42_釜検知,#10)	'D00397
tmr(PH43_釜検知,timPH43_釜検知,#10)	'D00424
tmr(PH44_釜検知,timPH44_釜検知,#10)	'D00425
tmr(PH45_釜検知,timPH45_釜検知,#10)	'D00426
tmr(PH46_釜検知,timPH46_釜検知,#10)	'D00427
tmr(PH47_釜検知,timPH47_釜検知,#10)	'D00428
tmr(PH48_釜検知,timPH48_釜検知,#10)	'D00429
tmr(PH49_釜検知,timPH49_釜検知,#10)	'D00452
tmr(PH50_釜検知,timPH50_釜検知,#10)	'D00453
tmr(PH51_釜検知,timPH51_釜検知,#10)	'D00454
tmr(PH52_フタ検知,timPH52_フタ検知,#10)	'D00455
tmr(XSW55_リフト上昇端,timXSW55_リフト上昇端,#10)	'D00456
tmr(XSW56_リフト下降端,timXSW56_リフト下降端,#10)	'D00457
tmr(XSW57_リフト上昇端,timXSW57_リフト上昇端,#10)	'D00458
tmr(XSW58_リフト下降端,timXSW58_リフト下降端,#10)	'D00459
tmr(XSW59_ストッパ上昇端,timXSW59_ストッパ上昇端,#10)	'D00460
tmr(XSW60_ストッパ下降端,timXSW60_ストッパ下降端,#10)	'D00461
tmr(XSW61_ストッパ上昇端,timXSW61_ストッパ上昇端,#10)	'D00462
tmr(XSW62_ストッパ下降端,timXSW62_ストッパ下降端,#10)	'D00463
tmr(XSW63_ストッパ上昇端,timXSW63_ストッパ上昇端,#10)	'D00464
tmr(XSW64_ストッパ下降端,timXSW64_ストッパ下降端,#10)	'D00481
tmr(PH53_釜検知,timPH53_釜検知,#10)	'D00486
tmr(PH54_フタ検知,timPH54_フタ検知,#10)	'D00487
tmr(XSW65_ストッパ上昇端,timXSW65_ストッパ上昇端,#10)	'D00488
tmr(XSW66_ストッパ下降端,timXSW66_ストッパ下降端,#10)	'D00489
tmr(XSW67_リフト上昇端,timXSW67_リフト上昇端,#10)	'D00490
tmr(XSW68_リフト下降端,timXSW68_リフト下降端,#10)	'D00491
tmr(XSW69_ブラシ上昇端,timXSW69_ブラシ上昇端,#10)	'D00494
tmr(XSW70_ブラシ下降端,timXSW70_ブラシ下降端,#10)	'D00495
tmr(XSW55_シリンダ上昇端A,timXSW55_シリンダ上昇端A,#10)	'D00513
tmr(XSW56_シリンダ下降端A,timXSW56_シリンダ下降端A,#10)	'D00514
tmr(XSW57_シリンダ上昇端B,timXSW57_シリンダ上昇端B,#10)	'D00515
tmr(XSW58_シリンダ下降端B,timXSW58_シリンダ下降端B,#10)	'D00516
tmr(XSW59_アンクランプ,timXSW59_アンクランプ,#10)	'D00517
tmr(XSW60_クランプ,timXSW60_クランプ,#10)	'D00518
tmr(XSW80_リフト上昇端,timXSW80_リフト上昇端,#10)	'D00521
tmr(XSW81_リフト下降端,timXSW81_リフト下降端,#10)	'D00522
tmr(PH55_釜検知,timPH55_釜検知,#10)	'D00523
tmr(PH56_フタ検知,timPH56_フタ検知,#10)	'D00524
tmr(PH67_釜検知,timPH67_釜検知,#10)	'D00525
tmr(PH68_釜検知,timPH68_釜検知,#10)	'D00526
tmr(PH69_フタ検知,timPH69_フタ検知,#10)	'D00527
tmr(PH57_釜検知,timPH57_釜検知,#10)	'D00617
tmr(PH58_フタ検知,timPH58_フタ検知,#10)	'D00618
tmr(LS7_釜反転機原点位置,timLS7_釜反転機原点位置,#10)	'D00619
tmr(LS8_釜反転機反転位置,timLS8_釜反転機反転位置,#10)	'D00620
tmr(PH59_釜検知,timPH59_釜検知,#10)	'D00621
tmr(PH62_フタ検知,timPH62_フタ検知,#10)	'D00622
tmr(PH63_釜検知,timPH63_釜検知,#10)	'D00623
tmr(PH64_フタ検知,timPH64_フタ検知,#10)	'D00624
tmr(LS5_空釜反転原点位置,timLS5_空釜反転原点位置,#10)	'D00641
tmr(LS6_空釜反転反転位置,timLS6_空釜反転反転位置,#10)	'D00642
tmr(PH65_釜検知,timPH65_釜検知,#10)	'D00643
tmr(PH66_フタ検知,timPH66_フタ検知,#10)	'D00644
tmr(XSW81_釜フタ押さえ上昇端A,timXSW81_釜フタ押さえ上昇端A,#10)	'D00645
tmr(XSW82_釜フタ押さえ下降端A,timXSW82_釜フタ押さえ下降端A,#10)	'D00646
tmr(XSW83_釜フタ押さえ上昇端B,timXSW83_釜フタ押さえ上昇端B,#10)	'D00647
tmr(XSW84_釜フタ押さえ下降端B,timXSW84_釜フタ押さえ下降端B,#10)	'D00648
tmr(XSW85_釜フタストッパ下降端,timXSW85_釜フタストッパ下降端,#10)	'D00649
'tmr(LS11_釜フタ検知,timLS11_釜フタ検知,#10)	'D00650
tmr(FLT1_タンク上限,timFLT1_タンク上限,#10)	'D00651
tmr(FLT2_タンク下限,timFLT2_タンク下限,#10)	'D00652
tmr(XSW86_釜フタ押さえ上昇端A,timXSW86_釜フタ押さえ上昇端A,#10)	'D00653
tmr(XSW87_釜フタ押さえ下降端A,timXSW87_釜フタ押さえ下降端A,#10)	'D00654
tmr(XSW88_釜フタ押さえ上昇端B,timXSW88_釜フタ押さえ上昇端B,#10)	'D00655
tmr(XSW89_釜フタ押さえ下降端B,timXSW89_釜フタ押さえ下降端B,#10)	'D00656
tmr(XSW90_釜フタストッパ下降端,timXSW90_釜フタストッパ下降端,#10)	'D00673
'tmr(LS12_釜フタ検知,timLS12_釜フタ検知,#10)	'D00674
tmr(FLT3_タンク上限,timFLT3_タンク上限,#10)	'D00675
tmr(FLT4_タンク下限,timFLT4_タンク下限,#10)	'D00676
tmr(XSW91_釜フタ押さえ上昇端A,timXSW91_釜フタ押さえ上昇端A,#10)	'D00677
tmr(XSW92_釜フタ押さえ下降端A,timXSW92_釜フタ押さえ下降端A,#10)	'D00678
tmr(XSW93_釜フタ押さえ上昇端B,timXSW93_釜フタ押さえ上昇端B,#10)	'D00679
tmr(XSW94_釜フタ押さえ下降端B,timXSW94_釜フタ押さえ下降端B,#10)	'D00680
tmr(XSW95_釜フタストッパ下降端,timXSW95_釜フタストッパ下降端,#10)	'D00681
'tmr(LS13_釜フタ検知,timLS13_釜フタ検知,#10)	'D00682
tmr(FLT5_タンク上限,timFLT5_タンク上限,#10)	'D00683
tmr(FLT6_タンク下限,timFLT6_タンク下限,#10)	'D00684
tmr(XSW96_釜フタ押さえ上昇端A,timXSW96_釜フタ押さえ上昇端A,#10)	'D00685
tmr(XSW97_釜フタ押さえ下降端A,timXSW97_釜フタ押さえ下降端A,#10)	'D00686
tmr(XSW98_釜フタ押さえ上昇端B,timXSW98_釜フタ押さえ上昇端B,#10)	'D00687
tmr(XSW99_釜フタ押さえ下降端B,timXSW99_釜フタ押さえ下降端B,#10)	'D00688
tmr(XSW100_釜フタストッパ下降端,timXSW100_釜フタストッパ下降端,#10)	'D00705
'tmr(LS14_釜フタ検知,timLS14_釜フタ検知,#10)	'D00706
tmr(FLT7_タンク上限,timFLT7_タンク上限,#10)	'D00707
tmr(FLT8_タンク下限,timFLT8_タンク下限,#10)	'D00708
cnt(CNT_MC5_洗米羽根,1000000,MC5_洗米羽根)	'F00027
cnt(CNT_MC4_送米ポンプ,1000000,MC4_送米ポンプ)	'F00028
cnt(CNT_SV1_給水電磁弁,1000000,SV1_給水電磁弁)	'F00029
cnt(CNT_SV58_洗米バルブA,1000000,SV58_洗米バルブA)	'F00030
cnt(CNT_MC1_張込用昇降機,1000000,MC1_張込用昇降機)	'F00054
cnt(CNT_MC2_排出用昇降機,1000000,MC2_排出用昇降機)	'F00055
cnt(CNT_MC3_計量機,1000000,MC3_計量機)	'F00056
cnt(CNT_SV12_送米切換バルブA側,1000000,SV12_送米切換バルブA側)	'F00114
cnt(CNT_SV13_送米切換バルブB側,1000000,SV13_送米切換バルブB側)	'F00115
cnt(CNT_SV2_充填バルブ開A,1000000,SV2_充填バルブ開A)	'F00117
cnt(CNT_SV3_充填バルブ閉A,1000000,SV3_充填バルブ閉A)	'F00118
cnt(CNT_SV4_水切りシャッター開A,1000000,SV4_水切りシャッター開A)	'F00119
cnt(CNT_SV5_水切りシャッター閉A,1000000,SV5_水切りシャッター閉A)	'F00120
cnt(CNT_SV60_排水バルブ開A,1000000,SV60_排水バルブ開A)	'F00121
cnt(CNT_SV61_排水バルブ閉A,1000000,SV61_排水バルブ閉A)	'F00122
cnt(CNT_SV7_充填バルブ開B,1000000,SV7_充填バルブ開B)	'F00123
cnt(CNT_SV8_充填バルブ閉B,1000000,SV8_充填バルブ閉B)	'F00124
cnt(CNT_SV9_水切りシャッター開B,1000000,SV9_水切りシャッター開B)	'F00125
cnt(CNT_SV10_水切りシャッター閉B,1000000,SV10_水切りシャッター閉B)	'F00126
cnt(CNT_SV62_排水バルブ開B,1000000,SV62_排水バルブ開B)	'F00127
cnt(CNT_SV63_排水バルブ閉B,1000000,SV63_排水バルブ閉B)	'F00128
cnt(CNT_SV6_給水電磁弁A,1000000,SV6_給水電磁弁A)	'F00151
cnt(CNT_SV11_給水電磁弁B,1000000,SV11_給水電磁弁B)	'F00152
cnt(CNT_SV17_計水タンク給水（大）,1000000,SV17_計水タンク給水（大）)	'F00154
cnt(CNT_SV18_計水タンク給水（小）,1000000,SV18_計水タンク給水（小）)	'F00155
cnt(CNT_SV19_計水電磁弁_A,1000000,SV19_計水電磁弁_A)	'F00156
cnt(CNT_SV64_計水電磁弁_B,1000000,SV64_計水電磁弁_B)	'F00157
cnt(CNT_MC6_搬送モータ,1000000,MC6_搬送モータ)	'F00177
cnt(CNT_MC7_搬送モータ,1000000,MC7_搬送モータ)	'F00178
cnt(CNT_MC8_搬送モータ,1000000,MC8_搬送モータ)	'F00179
cnt(CNT_SV14_ストッパ上昇,1000000,SV14_ストッパ上昇)	'F00180
cnt(CNT_SV15_ストッパ下降,1000000,SV15_ストッパ下降)	'F00181
cnt(CNT_SV64_ストッパ上昇,1000000,SV64_ストッパ上昇)	'F00182
cnt(CNT_SV70_ストッパ下降,1000000,SV70_ストッパ下降)	'F00183
cnt(CNT_SV20_リフト上昇,1000000,SV20_リフト上昇)	'F00184
cnt(CNT_MC11_搬送モータ,1000000,MC11_搬送モータ)	'F00185
cnt(CNT_SV32_リフト下降,1000000,SV32_リフト下降)	'F00186
cnt(CNT_MC9_モータローラ,1000000,MC9_モータローラ)	'F00209
cnt(CNT_MC12_搬送モータ,1000000,MC12_搬送モータ)	'F00210
cnt(CNT_MC13_搬送モータ,1000000,MC13_搬送モータ)	'F00211
cnt(CNT_MC16_モータローラ,1000000,MC16_モータローラ)	'F00212
cnt(CNT_SV21_リフト,1000000,SV21_リフト)	'F00213
cnt(CNT_SV51_ストッパ,1000000,SV51_ストッパ)	'F00214
cnt(CNT_SV22_ストッパ,1000000,SV22_ストッパ)	'F00215
cnt(CNT_SV23_リフト,1000000,SV23_リフト)	'F00216
cnt(CNT_MC14_搬送モータ,1000000,MC14_搬送モータ)	'F00217
cnt(CNT_MC15_搬送モータ,1000000,MC15_搬送モータ)	'F00218
cnt(CNT_MC34_モータローラ,1000000,MC34_モータローラ)	'F00219
cnt(CNT_SV24_クランプ,1000000,SV24_クランプ)	'F00220
cnt(CNT_SV25_ストッパ,1000000,SV25_ストッパ)	'F00221
cnt(CNT_SV26_クランプ,1000000,SV26_クランプ)	'F00222
cnt(CNT_SV27_ストッパ,1000000,SV27_ストッパ)	'F00223
cnt(CNT_SV28_リフト,1000000,SV28_リフト)	'F00224
cnt(CNT_SV29_ストッパ,1000000,SV29_ストッパ)	'F00241
cnt(CNT_MC40_ならしモータ,1000000,MC40_ならしモータ)	'F00242
cnt(CNT_SV26_ならし上昇,1000000,SV26_ならし上昇)	'F00245
cnt(CNT_SV25_ならし下降,1000000,SV25_ならし下降)	'F00246
cnt(CNT_SV23_ならし前進,1000000,SV23_ならし前進)	'F00247
cnt(CNT_SV24_ならし後退,1000000,SV24_ならし後退)	'F00248
cnt(CNT_SV34_シリンダ上昇A,1000000,SV34_シリンダ上昇A)	'F00249
cnt(CNT_SV35_シリンダ下降A,1000000,SV35_シリンダ下降A)	'F00250
cnt(CNT_SV36_シリンダ上昇B,1000000,SV36_シリンダ上昇B)	'F00251
cnt(CNT_SV37_シリンダ下降B,1000000,SV37_シリンダ下降B)	'F00252
cnt(CNT_SV39_アンクランプ,1000000,SV39_アンクランプ)	'F00253
cnt(CNT_SV38_クランプ,1000000,SV38_クランプ)	'F00254
cnt(CNT_MC44_モータローラ,1000000,MC44_モータローラ)	'F00255
cnt(CNT_MC45_搬送モータ,1000000,MC45_搬送モータ)	'F00273
cnt(CNT_MC46_モータローラ,1000000,MC46_モータローラ)	'F00274
cnt(CNT_SV42_ストッパ,1000000,SV42_ストッパ)	'F00275
cnt(CNT_SV43_リフト,1000000,SV43_リフト)	'F00276
cnt(CNT_MC17_モータローラ,1000000,MC17_モータローラ)	'F00337
cnt(CNT_MC18_モータローラ,1000000,MC18_モータローラ)	'F00338
cnt(CNT_MC19_モータローラ,1000000,MC19_モータローラ)	'F00339
cnt(CNT_MC20_モータローラ,1000000,MC20_モータローラ)	'F00340
cnt(CNT_MC21_モータローラ,1000000,MC21_モータローラ)	'F00341
cnt(CNT_MC22_モータローラ,1000000,MC22_モータローラ)	'F00342
cnt(CNT_MC23_モータローラ,1000000,MC23_モータローラ)	'F00369
cnt(CNT_MC24_モータローラ,1000000,MC24_モータローラ)	'F00370
cnt(CNT_MC25_モータローラ,1000000,MC25_モータローラ)	'F00371
cnt(CNT_MC26_モータローラ,1000000,MC26_モータローラ)	'F00372
cnt(CNT_MC27_モータローラ,1000000,MC27_モータローラ)	'F00373
cnt(CNT_MC28_モータローラ,1000000,MC28_モータローラ)	'F00374
cnt(CNT_MC29_モータローラ,1000000,MC29_モータローラ)	'F00401
cnt(CNT_MC30_モータローラ,1000000,MC30_モータローラ)	'F00402
cnt(CNT_MC31_モータローラ,1000000,MC31_モータローラ)	'F00403
cnt(CNT_MC32_モータローラ,1000000,MC32_モータローラ)	'F00404
cnt(CNT_MC33_モータローラ,1000000,MC33_モータローラ)	'F00405
cnt(CNT_MC47_モータローラ,1000000,MC47_モータローラ)	'F00406
cnt(CNT_MC48_モータローラ,1000000,MC48_モータローラ)	'F00433
cnt(CNT_MC49_モータローラ,1000000,MC49_モータローラ)	'F00434
cnt(CNT_MC50_モータローラ,1000000,MC50_モータローラ)	'F00435
cnt(CNT_MC51_モータローラ,1000000,MC51_モータローラ)	'F00436
cnt(CNT_MC52_モータローラ,1000000,MC52_モータローラ)	'F00437
cnt(CNT_MC53_モータローラ,1000000,MC53_モータローラ)	'F00438
cnt(CNT_MC41_モータローラ,1000000,MC41_モータローラ)	'F00465
cnt(CNT_MC42_モータローラ,1000000,MC42_モータローラ)	'F00466
cnt(CNT_MC43_搬送モータ,1000000,MC43_搬送モータ)	'F00467
cnt(CNT_SV44_ストッパ,1000000,SV44_ストッパ)	'F00468
cnt(CNT_SV45_ストッパ,1000000,SV45_ストッパ)	'F00469
cnt(CNT_SV46_ストッパ,1000000,SV46_ストッパ)	'F00470
cnt(CNT_SV47_リフト,1000000,SV47_リフト)	'F00471
cnt(CNT_SV48_リフト,1000000,SV48_リフト)	'F00472
cnt(CNT_MC54_モータローラ,1000000,MC54_モータローラ)	'F00473
cnt(CNT_MC10_搬送モータ正転,1000000,MC10_搬送モータ正転)	'F00474
cnt(CNT_MC10_搬送モータ逆転,1000000,MC10_搬送モータ逆転)	'F00475
cnt(CNT_MC55_搬送モータ,1000000,MC55_搬送モータ)	'F00476
cnt(CNT_SV49_ストッパ,1000000,SV49_ストッパ)	'F00477
cnt(CNT_SV50_リフト,1000000,SV50_リフト)	'F00478
cnt(CNT_SV45_シリンダ上昇A,1000000,SV45_シリンダ上昇A)	'F00497
cnt(CNT_SV46_シリンダ下降A,1000000,SV46_シリンダ下降A)	'F00498
cnt(CNT_SV47_シリンダ上昇B,1000000,SV47_シリンダ上昇B)	'F00499
cnt(CNT_SV48_シリンダ下降B,1000000,SV48_シリンダ下降B)	'F00500
cnt(CNT_SV49_アンクランプ,1000000,SV49_アンクランプ)	'F00501
cnt(CNT_SV50_クランプ,1000000,SV50_クランプ)	'F00502
cnt(CNT_MC57_搬送モータ,1000000,MC57_搬送モータ)	'F00504
cnt(CNT_SV59_リフト上昇,1000000,SV59_リフト上昇)	'F00505
'cnt(CNT_MC56_ブラシモータ,1000000,MC56_ブラシモータ)	'F00506
cnt(CNT_SV65_シリンダ上昇,1000000,SV65_シリンダ上昇)	'F00507
cnt(CNT_SV66_シリンダ下降,1000000,SV66_シリンダ下降)	'F00508
cnt(CNT_SV76_リフト下降,1000000,SV76_リフト下降)	'F00509
cnt(CNT_MC1_インバータ用電源,1000000,MC1_インバータ用電源)	'F00593
cnt(CNT_MC35_搬送モータ,1000000,MC35_搬送モータ)	'F00599
cnt(CNT_MC36_反転モータ正転,1000000,MC36_反転モータ正転)	'F00600
cnt(CNT_MC36_反転モータ逆転,1000000,MC36_反転モータ逆転)	'F00601
cnt(CNT_INV1_コンベアモータ正転,1000000,INV1_コンベアモータ正転)	'F00602
cnt(CNT_INV2_コンベアモータ正転,1000000,INV2_コンベアモータ正転)	'F00603
cnt(CNT_INV3_コンベアモータ正転,1000000,INV3_コンベアモータ正転)	'F00604
cnt(CNT_MC58_洗浄ポンプA,1000000,MC58_洗浄ポンプA)	'F00605
cnt(CNT_MC59_洗浄ポンプB,1000000,MC59_洗浄ポンプB)	'F00606
cnt(CNT_MC60_洗浄ポンプC,1000000,MC60_洗浄ポンプC)	'F00607
cnt(CNT_MC61_洗浄ポンプD,1000000,MC61_洗浄ポンプD)	'F00608
cnt(CNT_MC37_反転モータ逆転,1000000,MC37_反転モータ逆転)	'F00625
cnt(CNT_MC37_反転モータ正転,1000000,MC37_反転モータ正転)	'F00626
cnt(CNT_MC38_搬送モータ,1000000,MC38_搬送モータ)	'F00627
cnt(CNT_SV97_すすぎ電磁弁,1000000,SV97_すすぎ電磁弁)	'F00628
cnt(CNT_SV98_仕上げ電磁弁,1000000,SV98_仕上げ電磁弁)	'F00629
cnt(CNT_SV69_給湯電磁弁,1000000,SV69_給湯電磁弁)	'F00635
cnt(CNT_SV75_給湯電磁弁,1000000,SV75_給湯電磁弁)	'F00636
cnt(CNT_MC_HT1_タンクヒータ,1000000,MC_HT1_タンクヒータ)	'F00637
cnt(CNT_MC_HT2_タンクヒータ,1000000,MC_HT2_タンクヒータ)	'F00638
cnt(CNT_MC_HT3_タンクヒータ,1000000,MC_HT3_タンクヒータ)	'F00639
cnt(CNT_MC_HT4_タンクヒータ,1000000,MC_HT4_タンクヒータ)	'F00640
cnt(CNT_SV81_給湯電磁弁,1000000,SV81_給湯電磁弁)	'F00657
cnt(CNT_SV87_給湯電磁弁,1000000,SV87_給湯電磁弁)	'F00658
cnt(CNT_SV72_下洗浄電磁弁,1000000,SV72_下洗浄電磁弁)	'F00659
cnt(CNT_SV78_下洗浄電磁弁,1000000,SV78_下洗浄電磁弁)	'F00660
cnt(CNT_SV84_下洗浄電磁弁,1000000,SV84_下洗浄電磁弁)	'F00661
cnt(CNT_SV90_下洗浄電磁弁,1000000,SV90_下洗浄電磁弁)	'F00662
cnt(CNT_SV67_釜フタ押さえ下降A,1000000,SV67_釜フタ押さえ下降A)	'F00663
cnt(CNT_SV68_釜フタ押さえ下降B,1000000,SV68_釜フタ押さえ下降B)	'F00664
cnt(CNT_SV71_釜フタストッパ,1000000,SV71_釜フタストッパ)	'F00665
cnt(CNT_SV73_釜フタ押さえ下降A,1000000,SV73_釜フタ押さえ下降A)	'F00666
cnt(CNT_SV74_釜フタ押さえ下降B,1000000,SV74_釜フタ押さえ下降B)	'F00667
cnt(CNT_SV77_釜フタストッパ,1000000,SV77_釜フタストッパ)	'F00668
cnt(CNT_SV79_釜フタ押さえ下降A,1000000,SV79_釜フタ押さえ下降A)	'F00669
cnt(CNT_SV80_釜フタ押さえ下降B,1000000,SV80_釜フタ押さえ下降B)	'F00670
cnt(CNT_SV83_釜フタストッパ,1000000,SV83_釜フタストッパ)	'F00671
cnt(CNT_SV85_釜フタ押さえ下降A,1000000,SV85_釜フタ押さえ下降A)	'F00672
cnt(CNT_SV86_釜フタ押さえ下降B,1000000,SV86_釜フタ押さえ下降B)	'F00689
cnt(CNT_SV89_釜フタストッパ,1000000,SV89_釜フタストッパ)	'F00690
cnt(CNT_INV1_コンベア異常,1000000,INV1_コンベア異常)	'F00716
cnt(CNT_INV2_コンベア異常,1000000,INV2_コンベア異常)	'F00717
cnt(CNT_INV3_コンベア異常,1000000,INV3_コンベア異常)	'F00718
if ldp(clrPBMC5_洗米羽根) then
    res(CNT_MC5_洗米羽根)
end if	'G00027
if ldp(clrPBMC4_送米ポンプ) then
    res(CNT_MC4_送米ポンプ)
end if	'G00028
if ldp(clrPBSV1_給水電磁弁) then
    res(CNT_SV1_給水電磁弁)
end if	'G00029
if ldp(clrPBSV58_洗米バルブA) then
    res(CNT_SV58_洗米バルブA)
end if	'G00030
if ldp(clrPBMC1_張込用昇降機) then
    res(CNT_MC1_張込用昇降機)
end if	'G00054
if ldp(clrPBMC2_排出用昇降機) then
    res(CNT_MC2_排出用昇降機)
end if	'G00055
if ldp(clrPBMC3_計量機) then
    res(CNT_MC3_計量機)
end if	'G00056
if ldp(clrPBSV12_送米切換バルブA側) then
    res(CNT_SV12_送米切換バルブA側)
end if	'G00114
if ldp(clrPBSV13_送米切換バルブB側) then
    res(CNT_SV13_送米切換バルブB側)
end if	'G00115
if ldp(clrPBSV2_充填バルブ開A) then
    res(CNT_SV2_充填バルブ開A)
end if	'G00117
if ldp(clrPBSV3_充填バルブ閉A) then
    res(CNT_SV3_充填バルブ閉A)
end if	'G00118
if ldp(clrPBSV4_水切りシャッター開A) then
    res(CNT_SV4_水切りシャッター開A)
end if	'G00119
if ldp(clrPBSV5_水切りシャッター閉A) then
    res(CNT_SV5_水切りシャッター閉A)
end if	'G00120
if ldp(clrPBSV60_排水バルブ開A) then
    res(CNT_SV60_排水バルブ開A)
end if	'G00121
if ldp(clrPBSV61_排水バルブ閉A) then
    res(CNT_SV61_排水バルブ閉A)
end if	'G00122
if ldp(clrPBSV7_充填バルブ開B) then
    res(CNT_SV7_充填バルブ開B)
end if	'G00123
if ldp(clrPBSV8_充填バルブ閉B) then
    res(CNT_SV8_充填バルブ閉B)
end if	'G00124
if ldp(clrPBSV9_水切りシャッター開B) then
    res(CNT_SV9_水切りシャッター開B)
end if	'G00125
if ldp(clrPBSV10_水切りシャッター閉B) then
    res(CNT_SV10_水切りシャッター閉B)
end if	'G00126
if ldp(clrPBSV62_排水バルブ開B) then
    res(CNT_SV62_排水バルブ開B)
end if	'G00127
if ldp(clrPBSV63_排水バルブ閉B) then
    res(CNT_SV63_排水バルブ閉B)
end if	'G00128
if ldp(clrPBSV6_給水電磁弁A) then
    res(CNT_SV6_給水電磁弁A)
end if	'G00151
if ldp(clrPBSV11_給水電磁弁B) then
    res(CNT_SV11_給水電磁弁B)
end if	'G00152
if ldp(clrPBSV17_計水タンク給水（大）) then
    res(CNT_SV17_計水タンク給水（大）)
end if	'G00154
if ldp(clrPBSV18_計水タンク給水（小）) then
    res(CNT_SV18_計水タンク給水（小）)
end if	'G00155
if ldp(clrPBSV19_計水電磁弁_A) then
    res(CNT_SV19_計水電磁弁_A)
end if	'G00156
if ldp(clrPBSV64_計水電磁弁_B) then
    res(CNT_SV64_計水電磁弁_B)
end if	'G00157
if ldp(clrPBMC6_搬送モータ) then
    res(CNT_MC6_搬送モータ)
end if	'G00177
if ldp(clrPBMC7_搬送モータ) then
    res(CNT_MC7_搬送モータ)
end if	'G00178
if ldp(clrPBMC8_搬送モータ) then
    res(CNT_MC8_搬送モータ)
end if	'G00179
if ldp(clrPBSV14_ストッパ上昇) then
    res(CNT_SV14_ストッパ上昇)
end if	'G00180
if ldp(clrPBSV15_ストッパ下降) then
    res(CNT_SV15_ストッパ下降)
end if	'G00181
if ldp(clrPBSV64_ストッパ上昇) then
    res(CNT_SV64_ストッパ上昇)
end if	'G00182
if ldp(clrPBSV70_ストッパ下降) then
    res(CNT_SV70_ストッパ下降)
end if	'G00183
if ldp(clrPBSV20_リフト上昇) then
    res(CNT_SV20_リフト上昇)
end if	'G00184
if ldp(clrPBMC11_搬送モータ) then
    res(CNT_MC11_搬送モータ)
end if	'G00185
if ldp(clrPBSV32_リフト下降) then
    res(CNT_SV32_リフト下降)
end if	'G00186
if ldp(clrPBMC9_モータローラ) then
    res(CNT_MC9_モータローラ)
end if	'G00209
if ldp(clrPBMC12_搬送モータ) then
    res(CNT_MC12_搬送モータ)
end if	'G00210
if ldp(clrPBMC13_搬送モータ) then
    res(CNT_MC13_搬送モータ)
end if	'G00211
if ldp(clrPBMC16_モータローラ) then
    res(CNT_MC16_モータローラ)
end if	'G00212
if ldp(clrPBSV21_リフト) then
    res(CNT_SV21_リフト)
end if	'G00213
if ldp(clrPBSV51_ストッパ) then
    res(CNT_SV51_ストッパ)
end if	'G00214
if ldp(clrPBSV22_ストッパ) then
    res(CNT_SV22_ストッパ)
end if	'G00215
if ldp(clrPBSV23_リフト) then
    res(CNT_SV23_リフト)
end if	'G00216
if ldp(clrPBMC14_搬送モータ) then
    res(CNT_MC14_搬送モータ)
end if	'G00217
if ldp(clrPBMC15_搬送モータ) then
    res(CNT_MC15_搬送モータ)
end if	'G00218
if ldp(clrPBMC34_モータローラ) then
    res(CNT_MC34_モータローラ)
end if	'G00219
if ldp(clrPBSV24_クランプ) then
    res(CNT_SV24_クランプ)
end if	'G00220
if ldp(clrPBSV25_ストッパ) then
    res(CNT_SV25_ストッパ)
end if	'G00221
if ldp(clrPBSV26_クランプ) then
    res(CNT_SV26_クランプ)
end if	'G00222
if ldp(clrPBSV27_ストッパ) then
    res(CNT_SV27_ストッパ)
end if	'G00223
if ldp(clrPBSV28_リフト) then
    res(CNT_SV28_リフト)
end if	'G00224
if ldp(clrPBSV29_ストッパ) then
    res(CNT_SV29_ストッパ)
end if	'G00241
if ldp(clrPBMC40_ならしモータ) then
    res(CNT_MC40_ならしモータ)
end if	'G00242
if ldp(clrPBSV26_ならし上昇) then
    res(CNT_SV26_ならし上昇)
end if	'G00245
if ldp(clrPBSV25_ならし下降) then
    res(CNT_SV25_ならし下降)
end if	'G00246
if ldp(clrPBSV23_ならし前進) then
    res(CNT_SV23_ならし前進)
end if	'G00247
if ldp(clrPBSV24_ならし後退) then
    res(CNT_SV24_ならし後退)
end if	'G00248
if ldp(clrPBSV34_シリンダ上昇A) then
    res(CNT_SV34_シリンダ上昇A)
end if	'G00249
if ldp(clrPBSV35_シリンダ下降A) then
    res(CNT_SV35_シリンダ下降A)
end if	'G00250
if ldp(clrPBSV36_シリンダ上昇B) then
    res(CNT_SV36_シリンダ上昇B)
end if	'G00251
if ldp(clrPBSV37_シリンダ下降B) then
    res(CNT_SV37_シリンダ下降B)
end if	'G00252
if ldp(clrPBSV39_アンクランプ) then
    res(CNT_SV39_アンクランプ)
end if	'G00253
if ldp(clrPBSV38_クランプ) then
    res(CNT_SV38_クランプ)
end if	'G00254
if ldp(clrPBMC44_モータローラ) then
    res(CNT_MC44_モータローラ)
end if	'G00255
if ldp(clrPBMC45_搬送モータ) then
    res(CNT_MC45_搬送モータ)
end if	'G00273
if ldp(clrPBMC46_モータローラ) then
    res(CNT_MC46_モータローラ)
end if	'G00274
if ldp(clrPBSV42_ストッパ) then
    res(CNT_SV42_ストッパ)
end if	'G00275
if ldp(clrPBSV43_リフト) then
    res(CNT_SV43_リフト)
end if	'G00276
if ldp(clrPBMC17_モータローラ) then
    res(CNT_MC17_モータローラ)
end if	'G00337
if ldp(clrPBMC18_モータローラ) then
    res(CNT_MC18_モータローラ)
end if	'G00338
if ldp(clrPBMC19_モータローラ) then
    res(CNT_MC19_モータローラ)
end if	'G00339
if ldp(clrPBMC20_モータローラ) then
    res(CNT_MC20_モータローラ)
end if	'G00340
if ldp(clrPBMC21_モータローラ) then
    res(CNT_MC21_モータローラ)
end if	'G00341
if ldp(clrPBMC22_モータローラ) then
    res(CNT_MC22_モータローラ)
end if	'G00342
if ldp(clrPBMC23_モータローラ) then
    res(CNT_MC23_モータローラ)
end if	'G00369
if ldp(clrPBMC24_モータローラ) then
    res(CNT_MC24_モータローラ)
end if	'G00370
if ldp(clrPBMC25_モータローラ) then
    res(CNT_MC25_モータローラ)
end if	'G00371
if ldp(clrPBMC26_モータローラ) then
    res(CNT_MC26_モータローラ)
end if	'G00372
if ldp(clrPBMC27_モータローラ) then
    res(CNT_MC27_モータローラ)
end if	'G00373
if ldp(clrPBMC28_モータローラ) then
    res(CNT_MC28_モータローラ)
end if	'G00374
if ldp(clrPBMC29_モータローラ) then
    res(CNT_MC29_モータローラ)
end if	'G00401
if ldp(clrPBMC30_モータローラ) then
    res(CNT_MC30_モータローラ)
end if	'G00402
if ldp(clrPBMC31_モータローラ) then
    res(CNT_MC31_モータローラ)
end if	'G00403
if ldp(clrPBMC32_モータローラ) then
    res(CNT_MC32_モータローラ)
end if	'G00404
if ldp(clrPBMC33_モータローラ) then
    res(CNT_MC33_モータローラ)
end if	'G00405
if ldp(clrPBMC47_モータローラ) then
    res(CNT_MC47_モータローラ)
end if	'G00406
if ldp(clrPBMC48_モータローラ) then
    res(CNT_MC48_モータローラ)
end if	'G00433
if ldp(clrPBMC49_モータローラ) then
    res(CNT_MC49_モータローラ)
end if	'G00434
if ldp(clrPBMC50_モータローラ) then
    res(CNT_MC50_モータローラ)
end if	'G00435
if ldp(clrPBMC51_モータローラ) then
    res(CNT_MC51_モータローラ)
end if	'G00436
if ldp(clrPBMC52_モータローラ) then
    res(CNT_MC52_モータローラ)
end if	'G00437
if ldp(clrPBMC53_モータローラ) then
    res(CNT_MC53_モータローラ)
end if	'G00438
if ldp(clrPBMC41_モータローラ) then
    res(CNT_MC41_モータローラ)
end if	'G00465
if ldp(clrPBMC42_モータローラ) then
    res(CNT_MC42_モータローラ)
end if	'G00466
if ldp(clrPBMC43_搬送モータ) then
    res(CNT_MC43_搬送モータ)
end if	'G00467
if ldp(clrPBSV44_ストッパ) then
    res(CNT_SV44_ストッパ)
end if	'G00468
if ldp(clrPBSV45_ストッパ) then
    res(CNT_SV45_ストッパ)
end if	'G00469
if ldp(clrPBSV46_ストッパ) then
    res(CNT_SV46_ストッパ)
end if	'G00470
if ldp(clrPBSV47_リフト) then
    res(CNT_SV47_リフト)
end if	'G00471
if ldp(clrPBSV48_リフト) then
    res(CNT_SV48_リフト)
end if	'G00472
if ldp(clrPBMC54_モータローラ) then
    res(CNT_MC54_モータローラ)
end if	'G00473
if ldp(clrPBMC10_搬送モータ正転) then
    res(CNT_MC10_搬送モータ正転)
end if	'G00474
if ldp(clrPBMC10_搬送モータ逆転) then
    res(CNT_MC10_搬送モータ逆転)
end if	'G00475
if ldp(clrPBMC55_搬送モータ) then
    res(CNT_MC55_搬送モータ)
end if	'G00476
if ldp(clrPBSV49_ストッパ) then
    res(CNT_SV49_ストッパ)
end if	'G00477
if ldp(clrPBSV50_リフト) then
    res(CNT_SV50_リフト)
end if	'G00478
if ldp(clrPBSV45_シリンダ上昇A) then
    res(CNT_SV45_シリンダ上昇A)
end if	'G00497
if ldp(clrPBSV46_シリンダ下降A) then
    res(CNT_SV46_シリンダ下降A)
end if	'G00498
if ldp(clrPBSV47_シリンダ上昇B) then
    res(CNT_SV47_シリンダ上昇B)
end if	'G00499
if ldp(clrPBSV48_シリンダ下降B) then
    res(CNT_SV48_シリンダ下降B)
end if	'G00500
if ldp(clrPBSV49_アンクランプ) then
    res(CNT_SV49_アンクランプ)
end if	'G00501
if ldp(clrPBSV50_クランプ) then
    res(CNT_SV50_クランプ)
end if	'G00502
if ldp(clrPBMC57_搬送モータ) then
    res(CNT_MC57_搬送モータ)
end if	'G00504
if ldp(clrPBSV59_リフト上昇) then
    res(CNT_SV59_リフト上昇)
end if	'G00505
if ldp(clrPBMC56_ブラシモータ) then
    res(CNT_MC56_ブラシモータ)
end if	'G00506
if ldp(clrPBSV65_シリンダ上昇) then
    res(CNT_SV65_シリンダ上昇)
end if	'G00507
if ldp(clrPBSV66_シリンダ下降) then
    res(CNT_SV66_シリンダ下降)
end if	'G00508
if ldp(clrPBSV76_リフト下降) then
    res(CNT_SV76_リフト下降)
end if	'G00509
if ldp(clrPBMC1_インバータ用電源) then
    res(CNT_MC1_インバータ用電源)
end if	'G00593
if ldp(clrPBMC35_搬送モータ) then
    res(CNT_MC35_搬送モータ)
end if	'G00599
if ldp(clrPBMC36_反転モータ正転) then
    res(CNT_MC36_反転モータ正転)
end if	'G00600
if ldp(clrPBMC36_反転モータ逆転) then
    res(CNT_MC36_反転モータ逆転)
end if	'G00601
if ldp(clrPBINV1_コンベアモータ正転) then
    res(CNT_INV1_コンベアモータ正転)
end if	'G00602
if ldp(clrPBINV2_コンベアモータ正転) then
    res(CNT_INV2_コンベアモータ正転)
end if	'G00603
if ldp(clrPBINV3_コンベアモータ正転) then
    res(CNT_INV3_コンベアモータ正転)
end if	'G00604
if ldp(clrPBMC58_洗浄ポンプA) then
    res(CNT_MC58_洗浄ポンプA)
end if	'G00605
if ldp(clrPBMC59_洗浄ポンプB) then
    res(CNT_MC59_洗浄ポンプB)
end if	'G00606
if ldp(clrPBMC60_洗浄ポンプC) then
    res(CNT_MC60_洗浄ポンプC)
end if	'G00607
if ldp(clrPBMC61_洗浄ポンプD) then
    res(CNT_MC61_洗浄ポンプD)
end if	'G00608
if ldp(clrPBMC37_反転モータ逆転) then
    res(CNT_MC37_反転モータ逆転)
end if	'G00625
if ldp(clrPBMC37_反転モータ正転) then
    res(CNT_MC37_反転モータ正転)
end if	'G00626
if ldp(clrPBMC38_搬送モータ) then
    res(CNT_MC38_搬送モータ)
end if	'G00627
if ldp(clrPBSV97_すすぎ電磁弁) then
    res(CNT_SV97_すすぎ電磁弁)
end if	'G00628
if ldp(clrPBSV98_仕上げ電磁弁) then
    res(CNT_SV98_仕上げ電磁弁)
end if	'G00629
if ldp(clrPBSV69_給湯電磁弁) then
    res(CNT_SV69_給湯電磁弁)
end if	'G00635
if ldp(clrPBSV75_給湯電磁弁) then
    res(CNT_SV75_給湯電磁弁)
end if	'G00636
if ldp(clrPBMC_HT1_タンクヒータ) then
    res(CNT_MC_HT1_タンクヒータ)
end if	'G00637
if ldp(clrPBMC_HT2_タンクヒータ) then
    res(CNT_MC_HT2_タンクヒータ)
end if	'G00638
if ldp(clrPBMC_HT3_タンクヒータ) then
    res(CNT_MC_HT3_タンクヒータ)
end if	'G00639
if ldp(clrPBMC_HT4_タンクヒータ) then
    res(CNT_MC_HT4_タンクヒータ)
end if	'G00640
if ldp(clrPBSV81_給湯電磁弁) then
    res(CNT_SV81_給湯電磁弁)
end if	'G00657
if ldp(clrPBSV87_給湯電磁弁) then
    res(CNT_SV87_給湯電磁弁)
end if	'G00658
if ldp(clrPBSV72_下洗浄電磁弁) then
    res(CNT_SV72_下洗浄電磁弁)
end if	'G00659
if ldp(clrPBSV78_下洗浄電磁弁) then
    res(CNT_SV78_下洗浄電磁弁)
end if	'G00660
if ldp(clrPBSV84_下洗浄電磁弁) then
    res(CNT_SV84_下洗浄電磁弁)
end if	'G00661
if ldp(clrPBSV90_下洗浄電磁弁) then
    res(CNT_SV90_下洗浄電磁弁)
end if	'G00662
if ldp(clrPBSV67_釜フタ押さえ下降A) then
    res(CNT_SV67_釜フタ押さえ下降A)
end if	'G00663
if ldp(clrPBSV68_釜フタ押さえ下降B) then
    res(CNT_SV68_釜フタ押さえ下降B)
end if	'G00664
if ldp(clrPBSV71_釜フタストッパ) then
    res(CNT_SV71_釜フタストッパ)
end if	'G00665
if ldp(clrPBSV73_釜フタ押さえ下降A) then
    res(CNT_SV73_釜フタ押さえ下降A)
end if	'G00666
if ldp(clrPBSV74_釜フタ押さえ下降B) then
    res(CNT_SV74_釜フタ押さえ下降B)
end if	'G00667
if ldp(clrPBSV77_釜フタストッパ) then
    res(CNT_SV77_釜フタストッパ)
end if	'G00668
if ldp(clrPBSV79_釜フタ押さえ下降A) then
    res(CNT_SV79_釜フタ押さえ下降A)
end if	'G00669
if ldp(clrPBSV80_釜フタ押さえ下降B) then
    res(CNT_SV80_釜フタ押さえ下降B)
end if	'G00670
if ldp(clrPBSV83_釜フタストッパ) then
    res(CNT_SV83_釜フタストッパ)
end if	'G00671
if ldp(clrPBSV85_釜フタ押さえ下降A) then
    res(CNT_SV85_釜フタ押さえ下降A)
end if	'G00672
if ldp(clrPBSV86_釜フタ押さえ下降B) then
    res(CNT_SV86_釜フタ押さえ下降B)
end if	'G00689
if ldp(clrPBSV89_釜フタストッパ) then
    res(CNT_SV89_釜フタストッパ)
end if	'G00690
