                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler
                                      3 ; Version 4.5.0 #15242 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module controller_8051
                                      6 	
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _TF2
                                     13 	.globl _EXF2
                                     14 	.globl _RCLK
                                     15 	.globl _TCLK
                                     16 	.globl _EXEN2
                                     17 	.globl _TR2
                                     18 	.globl _C_T2
                                     19 	.globl _CP_RL2
                                     20 	.globl _T2CON_7
                                     21 	.globl _T2CON_6
                                     22 	.globl _T2CON_5
                                     23 	.globl _T2CON_4
                                     24 	.globl _T2CON_3
                                     25 	.globl _T2CON_2
                                     26 	.globl _T2CON_1
                                     27 	.globl _T2CON_0
                                     28 	.globl _PT2
                                     29 	.globl _ET2
                                     30 	.globl _CY
                                     31 	.globl _AC
                                     32 	.globl _F0
                                     33 	.globl _RS1
                                     34 	.globl _RS0
                                     35 	.globl _OV
                                     36 	.globl _F1
                                     37 	.globl _P
                                     38 	.globl _PS
                                     39 	.globl _PT1
                                     40 	.globl _PX1
                                     41 	.globl _PT0
                                     42 	.globl _PX0
                                     43 	.globl _RD
                                     44 	.globl _WR
                                     45 	.globl _T1
                                     46 	.globl _T0
                                     47 	.globl _INT1
                                     48 	.globl _INT0
                                     49 	.globl _TXD
                                     50 	.globl _RXD
                                     51 	.globl _P3_7
                                     52 	.globl _P3_6
                                     53 	.globl _P3_5
                                     54 	.globl _P3_4
                                     55 	.globl _P3_3
                                     56 	.globl _P3_2
                                     57 	.globl _P3_1
                                     58 	.globl _P3_0
                                     59 	.globl _EA
                                     60 	.globl _ES
                                     61 	.globl _ET1
                                     62 	.globl _EX1
                                     63 	.globl _ET0
                                     64 	.globl _EX0
                                     65 	.globl _P2_7
                                     66 	.globl _P2_6
                                     67 	.globl _P2_5
                                     68 	.globl _P2_4
                                     69 	.globl _P2_3
                                     70 	.globl _P2_2
                                     71 	.globl _P2_1
                                     72 	.globl _P2_0
                                     73 	.globl _SM0
                                     74 	.globl _SM1
                                     75 	.globl _SM2
                                     76 	.globl _REN
                                     77 	.globl _TB8
                                     78 	.globl _RB8
                                     79 	.globl _TI
                                     80 	.globl _RI
                                     81 	.globl _P1_7
                                     82 	.globl _P1_6
                                     83 	.globl _P1_5
                                     84 	.globl _P1_4
                                     85 	.globl _P1_3
                                     86 	.globl _P1_2
                                     87 	.globl _P1_1
                                     88 	.globl _P1_0
                                     89 	.globl _TF1
                                     90 	.globl _TR1
                                     91 	.globl _TF0
                                     92 	.globl _TR0
                                     93 	.globl _IE1
                                     94 	.globl _IT1
                                     95 	.globl _IE0
                                     96 	.globl _IT0
                                     97 	.globl _P0_7
                                     98 	.globl _P0_6
                                     99 	.globl _P0_5
                                    100 	.globl _P0_4
                                    101 	.globl _P0_3
                                    102 	.globl _P0_2
                                    103 	.globl _P0_1
                                    104 	.globl _P0_0
                                    105 	.globl _TH2
                                    106 	.globl _TL2
                                    107 	.globl _RCAP2H
                                    108 	.globl _RCAP2L
                                    109 	.globl _T2CON
                                    110 	.globl _B
                                    111 	.globl _ACC
                                    112 	.globl _PSW
                                    113 	.globl _IP
                                    114 	.globl _P3
                                    115 	.globl _IE
                                    116 	.globl _P2
                                    117 	.globl _SBUF
                                    118 	.globl _SCON
                                    119 	.globl _P1
                                    120 	.globl _TH1
                                    121 	.globl _TH0
                                    122 	.globl _TL1
                                    123 	.globl _TL0
                                    124 	.globl _TMOD
                                    125 	.globl _TCON
                                    126 	.globl _PCON
                                    127 	.globl _DPH
                                    128 	.globl _DPL
                                    129 	.globl _SP
                                    130 	.globl _P0
                                    131 	.globl _test_fan_speed
                                    132 	.globl _test_pwm
                                    133 	.globl _test_temperature
                                    134 	.globl _fuzzy_not
                                    135 	.globl _fuzzy_and_array
                                    136 	.globl _fuzzy_or_array
                                    137 	.globl _fuzzy_sugeno_weighted_average_array
                                    138 	.globl _fuzzy_sugeno_weighted_sum_array
                                    139 	.globl _fuzzy_ramp
                                    140 	.globl _fuzzy_function_array
                                    141 	.globl _fuzzy_rules_create
                                    142 	.globl _fuzzy_rules_add
                                    143 	.globl _fuzzy_rules_defuzzify
                                    144 	.globl _fuzzy_rules_cog
                                    145 	.globl _fuzzy_rules_free
                                    146 ;--------------------------------------------------------
                                    147 ; special function registers
                                    148 ;--------------------------------------------------------
                                    149 	.area RSEG    (ABS,DATA)
      000000                        150 	.org 0x0000
                           000080   151 G$P0$0_0$0 == 0x0080
                           000080   152 _P0	=	0x0080
                           000081   153 G$SP$0_0$0 == 0x0081
                           000081   154 _SP	=	0x0081
                           000082   155 G$DPL$0_0$0 == 0x0082
                           000082   156 _DPL	=	0x0082
                           000083   157 G$DPH$0_0$0 == 0x0083
                           000083   158 _DPH	=	0x0083
                           000087   159 G$PCON$0_0$0 == 0x0087
                           000087   160 _PCON	=	0x0087
                           000088   161 G$TCON$0_0$0 == 0x0088
                           000088   162 _TCON	=	0x0088
                           000089   163 G$TMOD$0_0$0 == 0x0089
                           000089   164 _TMOD	=	0x0089
                           00008A   165 G$TL0$0_0$0 == 0x008a
                           00008A   166 _TL0	=	0x008a
                           00008B   167 G$TL1$0_0$0 == 0x008b
                           00008B   168 _TL1	=	0x008b
                           00008C   169 G$TH0$0_0$0 == 0x008c
                           00008C   170 _TH0	=	0x008c
                           00008D   171 G$TH1$0_0$0 == 0x008d
                           00008D   172 _TH1	=	0x008d
                           000090   173 G$P1$0_0$0 == 0x0090
                           000090   174 _P1	=	0x0090
                           000098   175 G$SCON$0_0$0 == 0x0098
                           000098   176 _SCON	=	0x0098
                           000099   177 G$SBUF$0_0$0 == 0x0099
                           000099   178 _SBUF	=	0x0099
                           0000A0   179 G$P2$0_0$0 == 0x00a0
                           0000A0   180 _P2	=	0x00a0
                           0000A8   181 G$IE$0_0$0 == 0x00a8
                           0000A8   182 _IE	=	0x00a8
                           0000B0   183 G$P3$0_0$0 == 0x00b0
                           0000B0   184 _P3	=	0x00b0
                           0000B8   185 G$IP$0_0$0 == 0x00b8
                           0000B8   186 _IP	=	0x00b8
                           0000D0   187 G$PSW$0_0$0 == 0x00d0
                           0000D0   188 _PSW	=	0x00d0
                           0000E0   189 G$ACC$0_0$0 == 0x00e0
                           0000E0   190 _ACC	=	0x00e0
                           0000F0   191 G$B$0_0$0 == 0x00f0
                           0000F0   192 _B	=	0x00f0
                           0000C8   193 G$T2CON$0_0$0 == 0x00c8
                           0000C8   194 _T2CON	=	0x00c8
                           0000CA   195 G$RCAP2L$0_0$0 == 0x00ca
                           0000CA   196 _RCAP2L	=	0x00ca
                           0000CB   197 G$RCAP2H$0_0$0 == 0x00cb
                           0000CB   198 _RCAP2H	=	0x00cb
                           0000CC   199 G$TL2$0_0$0 == 0x00cc
                           0000CC   200 _TL2	=	0x00cc
                           0000CD   201 G$TH2$0_0$0 == 0x00cd
                           0000CD   202 _TH2	=	0x00cd
                                    203 ;--------------------------------------------------------
                                    204 ; special function bits
                                    205 ;--------------------------------------------------------
                                    206 	.area RSEG    (ABS,DATA)
      000000                        207 	.org 0x0000
                           000080   208 G$P0_0$0_0$0 == 0x0080
                           000080   209 _P0_0	=	0x0080
                           000081   210 G$P0_1$0_0$0 == 0x0081
                           000081   211 _P0_1	=	0x0081
                           000082   212 G$P0_2$0_0$0 == 0x0082
                           000082   213 _P0_2	=	0x0082
                           000083   214 G$P0_3$0_0$0 == 0x0083
                           000083   215 _P0_3	=	0x0083
                           000084   216 G$P0_4$0_0$0 == 0x0084
                           000084   217 _P0_4	=	0x0084
                           000085   218 G$P0_5$0_0$0 == 0x0085
                           000085   219 _P0_5	=	0x0085
                           000086   220 G$P0_6$0_0$0 == 0x0086
                           000086   221 _P0_6	=	0x0086
                           000087   222 G$P0_7$0_0$0 == 0x0087
                           000087   223 _P0_7	=	0x0087
                           000088   224 G$IT0$0_0$0 == 0x0088
                           000088   225 _IT0	=	0x0088
                           000089   226 G$IE0$0_0$0 == 0x0089
                           000089   227 _IE0	=	0x0089
                           00008A   228 G$IT1$0_0$0 == 0x008a
                           00008A   229 _IT1	=	0x008a
                           00008B   230 G$IE1$0_0$0 == 0x008b
                           00008B   231 _IE1	=	0x008b
                           00008C   232 G$TR0$0_0$0 == 0x008c
                           00008C   233 _TR0	=	0x008c
                           00008D   234 G$TF0$0_0$0 == 0x008d
                           00008D   235 _TF0	=	0x008d
                           00008E   236 G$TR1$0_0$0 == 0x008e
                           00008E   237 _TR1	=	0x008e
                           00008F   238 G$TF1$0_0$0 == 0x008f
                           00008F   239 _TF1	=	0x008f
                           000090   240 G$P1_0$0_0$0 == 0x0090
                           000090   241 _P1_0	=	0x0090
                           000091   242 G$P1_1$0_0$0 == 0x0091
                           000091   243 _P1_1	=	0x0091
                           000092   244 G$P1_2$0_0$0 == 0x0092
                           000092   245 _P1_2	=	0x0092
                           000093   246 G$P1_3$0_0$0 == 0x0093
                           000093   247 _P1_3	=	0x0093
                           000094   248 G$P1_4$0_0$0 == 0x0094
                           000094   249 _P1_4	=	0x0094
                           000095   250 G$P1_5$0_0$0 == 0x0095
                           000095   251 _P1_5	=	0x0095
                           000096   252 G$P1_6$0_0$0 == 0x0096
                           000096   253 _P1_6	=	0x0096
                           000097   254 G$P1_7$0_0$0 == 0x0097
                           000097   255 _P1_7	=	0x0097
                           000098   256 G$RI$0_0$0 == 0x0098
                           000098   257 _RI	=	0x0098
                           000099   258 G$TI$0_0$0 == 0x0099
                           000099   259 _TI	=	0x0099
                           00009A   260 G$RB8$0_0$0 == 0x009a
                           00009A   261 _RB8	=	0x009a
                           00009B   262 G$TB8$0_0$0 == 0x009b
                           00009B   263 _TB8	=	0x009b
                           00009C   264 G$REN$0_0$0 == 0x009c
                           00009C   265 _REN	=	0x009c
                           00009D   266 G$SM2$0_0$0 == 0x009d
                           00009D   267 _SM2	=	0x009d
                           00009E   268 G$SM1$0_0$0 == 0x009e
                           00009E   269 _SM1	=	0x009e
                           00009F   270 G$SM0$0_0$0 == 0x009f
                           00009F   271 _SM0	=	0x009f
                           0000A0   272 G$P2_0$0_0$0 == 0x00a0
                           0000A0   273 _P2_0	=	0x00a0
                           0000A1   274 G$P2_1$0_0$0 == 0x00a1
                           0000A1   275 _P2_1	=	0x00a1
                           0000A2   276 G$P2_2$0_0$0 == 0x00a2
                           0000A2   277 _P2_2	=	0x00a2
                           0000A3   278 G$P2_3$0_0$0 == 0x00a3
                           0000A3   279 _P2_3	=	0x00a3
                           0000A4   280 G$P2_4$0_0$0 == 0x00a4
                           0000A4   281 _P2_4	=	0x00a4
                           0000A5   282 G$P2_5$0_0$0 == 0x00a5
                           0000A5   283 _P2_5	=	0x00a5
                           0000A6   284 G$P2_6$0_0$0 == 0x00a6
                           0000A6   285 _P2_6	=	0x00a6
                           0000A7   286 G$P2_7$0_0$0 == 0x00a7
                           0000A7   287 _P2_7	=	0x00a7
                           0000A8   288 G$EX0$0_0$0 == 0x00a8
                           0000A8   289 _EX0	=	0x00a8
                           0000A9   290 G$ET0$0_0$0 == 0x00a9
                           0000A9   291 _ET0	=	0x00a9
                           0000AA   292 G$EX1$0_0$0 == 0x00aa
                           0000AA   293 _EX1	=	0x00aa
                           0000AB   294 G$ET1$0_0$0 == 0x00ab
                           0000AB   295 _ET1	=	0x00ab
                           0000AC   296 G$ES$0_0$0 == 0x00ac
                           0000AC   297 _ES	=	0x00ac
                           0000AF   298 G$EA$0_0$0 == 0x00af
                           0000AF   299 _EA	=	0x00af
                           0000B0   300 G$P3_0$0_0$0 == 0x00b0
                           0000B0   301 _P3_0	=	0x00b0
                           0000B1   302 G$P3_1$0_0$0 == 0x00b1
                           0000B1   303 _P3_1	=	0x00b1
                           0000B2   304 G$P3_2$0_0$0 == 0x00b2
                           0000B2   305 _P3_2	=	0x00b2
                           0000B3   306 G$P3_3$0_0$0 == 0x00b3
                           0000B3   307 _P3_3	=	0x00b3
                           0000B4   308 G$P3_4$0_0$0 == 0x00b4
                           0000B4   309 _P3_4	=	0x00b4
                           0000B5   310 G$P3_5$0_0$0 == 0x00b5
                           0000B5   311 _P3_5	=	0x00b5
                           0000B6   312 G$P3_6$0_0$0 == 0x00b6
                           0000B6   313 _P3_6	=	0x00b6
                           0000B7   314 G$P3_7$0_0$0 == 0x00b7
                           0000B7   315 _P3_7	=	0x00b7
                           0000B0   316 G$RXD$0_0$0 == 0x00b0
                           0000B0   317 _RXD	=	0x00b0
                           0000B1   318 G$TXD$0_0$0 == 0x00b1
                           0000B1   319 _TXD	=	0x00b1
                           0000B2   320 G$INT0$0_0$0 == 0x00b2
                           0000B2   321 _INT0	=	0x00b2
                           0000B3   322 G$INT1$0_0$0 == 0x00b3
                           0000B3   323 _INT1	=	0x00b3
                           0000B4   324 G$T0$0_0$0 == 0x00b4
                           0000B4   325 _T0	=	0x00b4
                           0000B5   326 G$T1$0_0$0 == 0x00b5
                           0000B5   327 _T1	=	0x00b5
                           0000B6   328 G$WR$0_0$0 == 0x00b6
                           0000B6   329 _WR	=	0x00b6
                           0000B7   330 G$RD$0_0$0 == 0x00b7
                           0000B7   331 _RD	=	0x00b7
                           0000B8   332 G$PX0$0_0$0 == 0x00b8
                           0000B8   333 _PX0	=	0x00b8
                           0000B9   334 G$PT0$0_0$0 == 0x00b9
                           0000B9   335 _PT0	=	0x00b9
                           0000BA   336 G$PX1$0_0$0 == 0x00ba
                           0000BA   337 _PX1	=	0x00ba
                           0000BB   338 G$PT1$0_0$0 == 0x00bb
                           0000BB   339 _PT1	=	0x00bb
                           0000BC   340 G$PS$0_0$0 == 0x00bc
                           0000BC   341 _PS	=	0x00bc
                           0000D0   342 G$P$0_0$0 == 0x00d0
                           0000D0   343 _P	=	0x00d0
                           0000D1   344 G$F1$0_0$0 == 0x00d1
                           0000D1   345 _F1	=	0x00d1
                           0000D2   346 G$OV$0_0$0 == 0x00d2
                           0000D2   347 _OV	=	0x00d2
                           0000D3   348 G$RS0$0_0$0 == 0x00d3
                           0000D3   349 _RS0	=	0x00d3
                           0000D4   350 G$RS1$0_0$0 == 0x00d4
                           0000D4   351 _RS1	=	0x00d4
                           0000D5   352 G$F0$0_0$0 == 0x00d5
                           0000D5   353 _F0	=	0x00d5
                           0000D6   354 G$AC$0_0$0 == 0x00d6
                           0000D6   355 _AC	=	0x00d6
                           0000D7   356 G$CY$0_0$0 == 0x00d7
                           0000D7   357 _CY	=	0x00d7
                           0000AD   358 G$ET2$0_0$0 == 0x00ad
                           0000AD   359 _ET2	=	0x00ad
                           0000BD   360 G$PT2$0_0$0 == 0x00bd
                           0000BD   361 _PT2	=	0x00bd
                           0000C8   362 G$T2CON_0$0_0$0 == 0x00c8
                           0000C8   363 _T2CON_0	=	0x00c8
                           0000C9   364 G$T2CON_1$0_0$0 == 0x00c9
                           0000C9   365 _T2CON_1	=	0x00c9
                           0000CA   366 G$T2CON_2$0_0$0 == 0x00ca
                           0000CA   367 _T2CON_2	=	0x00ca
                           0000CB   368 G$T2CON_3$0_0$0 == 0x00cb
                           0000CB   369 _T2CON_3	=	0x00cb
                           0000CC   370 G$T2CON_4$0_0$0 == 0x00cc
                           0000CC   371 _T2CON_4	=	0x00cc
                           0000CD   372 G$T2CON_5$0_0$0 == 0x00cd
                           0000CD   373 _T2CON_5	=	0x00cd
                           0000CE   374 G$T2CON_6$0_0$0 == 0x00ce
                           0000CE   375 _T2CON_6	=	0x00ce
                           0000CF   376 G$T2CON_7$0_0$0 == 0x00cf
                           0000CF   377 _T2CON_7	=	0x00cf
                           0000C8   378 G$CP_RL2$0_0$0 == 0x00c8
                           0000C8   379 _CP_RL2	=	0x00c8
                           0000C9   380 G$C_T2$0_0$0 == 0x00c9
                           0000C9   381 _C_T2	=	0x00c9
                           0000CA   382 G$TR2$0_0$0 == 0x00ca
                           0000CA   383 _TR2	=	0x00ca
                           0000CB   384 G$EXEN2$0_0$0 == 0x00cb
                           0000CB   385 _EXEN2	=	0x00cb
                           0000CC   386 G$TCLK$0_0$0 == 0x00cc
                           0000CC   387 _TCLK	=	0x00cc
                           0000CD   388 G$RCLK$0_0$0 == 0x00cd
                           0000CD   389 _RCLK	=	0x00cd
                           0000CE   390 G$EXF2$0_0$0 == 0x00ce
                           0000CE   391 _EXF2	=	0x00ce
                           0000CF   392 G$TF2$0_0$0 == 0x00cf
                           0000CF   393 _TF2	=	0x00cf
                                    394 ;--------------------------------------------------------
                                    395 ; overlayable register banks
                                    396 ;--------------------------------------------------------
                                    397 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        398 	.ds 8
                                    399 ;--------------------------------------------------------
                                    400 ; overlayable bit register bank
                                    401 ;--------------------------------------------------------
                                    402 	.area BIT_BANK	(REL,OVR,DATA)
      000020                        403 bits:
      000020                        404 	.ds 1
                           008000   405 	b0 = bits[0]
                           008100   406 	b1 = bits[1]
                           008200   407 	b2 = bits[2]
                           008300   408 	b3 = bits[3]
                           008400   409 	b4 = bits[4]
                           008500   410 	b5 = bits[5]
                           008600   411 	b6 = bits[6]
                           008700   412 	b7 = bits[7]
                                    413 ;--------------------------------------------------------
                                    414 ; internal ram data
                                    415 ;--------------------------------------------------------
                                    416 	.area DSEG    (DATA)
                           000000   417 G$test_temperature$0_0$0==.
      000008                        418 _test_temperature::
      000008                        419 	.ds 1
                           000001   420 G$test_pwm$0_0$0==.
      000009                        421 _test_pwm::
      000009                        422 	.ds 1
                           000002   423 G$test_fan_speed$0_0$0==.
      00000A                        424 _test_fan_speed::
      00000A                        425 	.ds 4
                                    426 ;--------------------------------------------------------
                                    427 ; overlayable items in internal ram
                                    428 ;--------------------------------------------------------
                                    429 ;--------------------------------------------------------
                                    430 ; Stack segment in internal ram
                                    431 ;--------------------------------------------------------
                                    432 	.area SSEG
      000021                        433 __start__stack:
      000021                        434 	.ds	1
                                    435 
                                    436 ;--------------------------------------------------------
                                    437 ; indirectly addressable internal ram data
                                    438 ;--------------------------------------------------------
                                    439 	.area ISEG    (DATA)
                                    440 ;--------------------------------------------------------
                                    441 ; absolute internal ram data
                                    442 ;--------------------------------------------------------
                                    443 	.area IABS    (ABS,DATA)
                                    444 	.area IABS    (ABS,DATA)
                                    445 ;--------------------------------------------------------
                                    446 ; bit data
                                    447 ;--------------------------------------------------------
                                    448 	.area BSEG    (BIT)
                                    449 ;--------------------------------------------------------
                                    450 ; paged external ram data
                                    451 ;--------------------------------------------------------
                                    452 	.area PSEG    (PAG,XDATA)
                                    453 ;--------------------------------------------------------
                                    454 ; uninitialized external ram data
                                    455 ;--------------------------------------------------------
                                    456 	.area XSEG    (XDATA)
                                    457 ;--------------------------------------------------------
                                    458 ; absolute external ram data
                                    459 ;--------------------------------------------------------
                                    460 	.area XABS    (ABS,XDATA)
                                    461 ;--------------------------------------------------------
                                    462 ; initialized external ram data
                                    463 ;--------------------------------------------------------
                                    464 	.area XISEG   (XDATA)
                                    465 	.area HOME    (CODE)
                                    466 	.area GSINIT0 (CODE)
                                    467 	.area GSINIT1 (CODE)
                                    468 	.area GSINIT2 (CODE)
                                    469 	.area GSINIT3 (CODE)
                                    470 	.area GSINIT4 (CODE)
                                    471 	.area GSINIT5 (CODE)
                                    472 	.area GSINIT  (CODE)
                                    473 	.area GSFINAL (CODE)
                                    474 	.area CSEG    (CODE)
                                    475 ;--------------------------------------------------------
                                    476 ; interrupt vector
                                    477 ;--------------------------------------------------------
                                    478 	.area HOME    (CODE)
      000000                        479 __interrupt_vect:
      000000 02 00 4C         [24]  480 	ljmp	__sdcc_gsinit_startup
                                    481 ; restartable atomic support routines
      000003                        482 	.ds	5
      000008                        483 sdcc_atomic_exchange_rollback_start::
      000008 00               [12]  484 	nop
      000009 00               [12]  485 	nop
      00000A                        486 sdcc_atomic_exchange_pdata_impl:
      00000A E2               [24]  487 	movx	a, @r0
      00000B FB               [12]  488 	mov	r3, a
      00000C EA               [12]  489 	mov	a, r2
      00000D F2               [24]  490 	movx	@r0, a
      00000E 80 2C            [24]  491 	sjmp	sdcc_atomic_exchange_exit
      000010 00               [12]  492 	nop
      000011 00               [12]  493 	nop
      000012                        494 sdcc_atomic_exchange_xdata_impl:
      000012 E0               [24]  495 	movx	a, @dptr
      000013 FB               [12]  496 	mov	r3, a
      000014 EA               [12]  497 	mov	a, r2
      000015 F0               [24]  498 	movx	@dptr, a
      000016 80 24            [24]  499 	sjmp	sdcc_atomic_exchange_exit
      000018                        500 sdcc_atomic_compare_exchange_idata_impl:
      000018 E6               [12]  501 	mov	a, @r0
      000019 B5 02 02         [24]  502 	cjne	a, ar2, .+#5
      00001C EB               [12]  503 	mov	a, r3
      00001D F6               [12]  504 	mov	@r0, a
      00001E 22               [24]  505 	ret
      00001F 00               [12]  506 	nop
      000020                        507 sdcc_atomic_compare_exchange_pdata_impl:
      000020 E2               [24]  508 	movx	a, @r0
      000021 B5 02 02         [24]  509 	cjne	a, ar2, .+#5
      000024 EB               [12]  510 	mov	a, r3
      000025 F2               [24]  511 	movx	@r0, a
      000026 22               [24]  512 	ret
      000027 00               [12]  513 	nop
      000028                        514 sdcc_atomic_compare_exchange_xdata_impl:
      000028 E0               [24]  515 	movx	a, @dptr
      000029 B5 02 02         [24]  516 	cjne	a, ar2, .+#5
      00002C EB               [12]  517 	mov	a, r3
      00002D F0               [24]  518 	movx	@dptr, a
      00002E 22               [24]  519 	ret
      00002F                        520 sdcc_atomic_exchange_rollback_end::
                                    521 
      00002F                        522 sdcc_atomic_exchange_gptr_impl::
      00002F 30 F6 E0         [24]  523 	jnb	b.6, sdcc_atomic_exchange_xdata_impl
      000032 A8 82            [24]  524 	mov	r0, dpl
      000034 20 F5 D3         [24]  525 	jb	b.5, sdcc_atomic_exchange_pdata_impl
      000037                        526 sdcc_atomic_exchange_idata_impl:
      000037 EA               [12]  527 	mov	a, r2
      000038 C6               [12]  528 	xch	a, @r0
      000039 F5 82            [12]  529 	mov	dpl, a
      00003B 22               [24]  530 	ret
      00003C                        531 sdcc_atomic_exchange_exit:
      00003C 8B 82            [24]  532 	mov	dpl, r3
      00003E 22               [24]  533 	ret
      00003F                        534 sdcc_atomic_compare_exchange_gptr_impl::
      00003F 30 F6 E6         [24]  535 	jnb	b.6, sdcc_atomic_compare_exchange_xdata_impl
      000042 A8 82            [24]  536 	mov	r0, dpl
      000044 20 F5 D9         [24]  537 	jb	b.5, sdcc_atomic_compare_exchange_pdata_impl
      000047 80 CF            [24]  538 	sjmp	sdcc_atomic_compare_exchange_idata_impl
                                    539 ;--------------------------------------------------------
                                    540 ; global & static initialisations
                                    541 ;--------------------------------------------------------
                                    542 	.area HOME    (CODE)
                                    543 	.area GSINIT  (CODE)
                                    544 	.area GSFINAL (CODE)
                                    545 	.area GSINIT  (CODE)
                                    546 	.globl __sdcc_gsinit_startup
                                    547 	.globl __sdcc_program_startup
                                    548 	.globl __start__stack
                                    549 	.globl __mcs51_genXINIT
                                    550 	.globl __mcs51_genXRAMCLEAR
                                    551 	.globl __mcs51_genRAMCLEAR
                           000000   552 	C$controller_8051.c$25$2_0$118 ==.
                                    553 ;	../../controller_8051.c:25: volatile unsigned char test_temperature = 0u;
      0000A5 75 08 00         [24]  554 	mov	_test_temperature,#0x00
                           000003   555 	C$controller_8051.c$26$2_0$118 ==.
                                    556 ;	../../controller_8051.c:26: volatile unsigned char test_pwm = 0u;
      0000A8 75 09 00         [24]  557 	mov	_test_pwm,#0x00
                           000006   558 	C$controller_8051.c$27$2_0$118 ==.
                                    559 ;	../../controller_8051.c:27: volatile float test_fan_speed = 0.0f;
      0000AB E4               [12]  560 	clr	a
      0000AC F5 0A            [12]  561 	mov	_test_fan_speed,a
      0000AE F5 0B            [12]  562 	mov	(_test_fan_speed + 1),a
      0000B0 F5 0C            [12]  563 	mov	(_test_fan_speed + 2),a
      0000B2 F5 0D            [12]  564 	mov	(_test_fan_speed + 3),a
                                    565 	.area GSFINAL (CODE)
      0000B4 02 00 49         [24]  566 	ljmp	__sdcc_program_startup
                                    567 ;--------------------------------------------------------
                                    568 ; Home
                                    569 ;--------------------------------------------------------
                                    570 	.area HOME    (CODE)
                                    571 	.area HOME    (CODE)
      000049                        572 __sdcc_program_startup:
      000049 02 22 92         [24]  573 	ljmp	_main
                                    574 ;	return from main will return to caller
                                    575 ;--------------------------------------------------------
                                    576 ; code
                                    577 ;--------------------------------------------------------
                                    578 	.area CSEG    (CODE)
                                    579 ;------------------------------------------------------------
                                    580 ;Allocation info for local variables in function 'fuzzy_clamp'
                                    581 ;------------------------------------------------------------
                                    582 ;value         Allocated to registers r4 r5 r6 r7 
                                    583 ;------------------------------------------------------------
                           000000   584 	Fcontroller_8051$fuzzy_clamp$0$0 ==.
                           000000   585 	C$fuzzy.h$521$0_0$16 ==.
                                    586 ;	../../fuzzy.h:521: static float fuzzy_clamp(float value)
                                    587 ;	-----------------------------------------
                                    588 ;	 function fuzzy_clamp
                                    589 ;	-----------------------------------------
      0000B7                        590 _fuzzy_clamp:
                           000007   591 	ar7 = 0x07
                           000006   592 	ar6 = 0x06
                           000005   593 	ar5 = 0x05
                           000004   594 	ar4 = 0x04
                           000003   595 	ar3 = 0x03
                           000002   596 	ar2 = 0x02
                           000001   597 	ar1 = 0x01
                           000000   598 	ar0 = 0x00
      0000B7 AC 82            [24]  599 	mov	r4,dpl
      0000B9 AD 83            [24]  600 	mov	r5,dph
      0000BB AE F0            [24]  601 	mov	r6,b
      0000BD FF               [12]  602 	mov	r7,a
                           000007   603 	C$fuzzy.h$523$1_0$16 ==.
                                    604 ;	../../fuzzy.h:523: if (value < LEVEL_LO) {
      0000BE C0 07            [24]  605 	push	ar7
      0000C0 C0 06            [24]  606 	push	ar6
      0000C2 C0 05            [24]  607 	push	ar5
      0000C4 C0 04            [24]  608 	push	ar4
      0000C6 E4               [12]  609 	clr	a
      0000C7 C0 E0            [24]  610 	push	acc
      0000C9 C0 E0            [24]  611 	push	acc
      0000CB C0 E0            [24]  612 	push	acc
      0000CD C0 E0            [24]  613 	push	acc
      0000CF 8C 82            [24]  614 	mov	dpl, r4
      0000D1 8D 83            [24]  615 	mov	dph, r5
      0000D3 8E F0            [24]  616 	mov	b, r6
      0000D5 EF               [12]  617 	mov	a, r7
      0000D6 12 24 07         [24]  618 	lcall	___fslt
      0000D9 AB 82            [24]  619 	mov	r3, dpl
      0000DB E5 81            [12]  620 	mov	a,sp
      0000DD 24 FC            [12]  621 	add	a,#0xfc
      0000DF F5 81            [12]  622 	mov	sp,a
      0000E1 D0 04            [24]  623 	pop	ar4
      0000E3 D0 05            [24]  624 	pop	ar5
      0000E5 D0 06            [24]  625 	pop	ar6
      0000E7 D0 07            [24]  626 	pop	ar7
      0000E9 EB               [12]  627 	mov	a,r3
      0000EA 60 08            [24]  628 	jz	00102$
                           000035   629 	C$fuzzy.h$524$2_0$17 ==.
                                    630 ;	../../fuzzy.h:524: return LEVEL_LO;
      0000EC 90 00 00         [24]  631 	mov	dptr,#0x0000
      0000EF E4               [12]  632 	clr	a
      0000F0 F5 F0            [12]  633 	mov	b,a
      0000F2 80 3F            [24]  634 	sjmp	00105$
      0000F4                        635 00102$:
                           00003D   636 	C$fuzzy.h$527$1_0$16 ==.
                                    637 ;	../../fuzzy.h:527: if (value > LEVEL_HI) {
      0000F4 C0 07            [24]  638 	push	ar7
      0000F6 C0 06            [24]  639 	push	ar6
      0000F8 C0 05            [24]  640 	push	ar5
      0000FA C0 04            [24]  641 	push	ar4
      0000FC C0 04            [24]  642 	push	ar4
      0000FE C0 05            [24]  643 	push	ar5
      000100 C0 06            [24]  644 	push	ar6
      000102 C0 07            [24]  645 	push	ar7
      000104 90 00 00         [24]  646 	mov	dptr,#0x0000
      000107 75 F0 80         [24]  647 	mov	b, #0x80
      00010A 74 3F            [12]  648 	mov	a, #0x3f
      00010C 12 24 07         [24]  649 	lcall	___fslt
      00010F AB 82            [24]  650 	mov	r3, dpl
      000111 E5 81            [12]  651 	mov	a,sp
      000113 24 FC            [12]  652 	add	a,#0xfc
      000115 F5 81            [12]  653 	mov	sp,a
      000117 D0 04            [24]  654 	pop	ar4
      000119 D0 05            [24]  655 	pop	ar5
      00011B D0 06            [24]  656 	pop	ar6
      00011D D0 07            [24]  657 	pop	ar7
      00011F EB               [12]  658 	mov	a,r3
      000120 60 0A            [24]  659 	jz	00104$
                           00006B   660 	C$fuzzy.h$528$2_0$18 ==.
                                    661 ;	../../fuzzy.h:528: return LEVEL_HI;
      000122 90 00 00         [24]  662 	mov	dptr,#0x0000
      000125 75 F0 80         [24]  663 	mov	b, #0x80
      000128 74 3F            [12]  664 	mov	a, #0x3f
      00012A 80 07            [24]  665 	sjmp	00105$
      00012C                        666 00104$:
                           000075   667 	C$fuzzy.h$531$1_0$16 ==.
                                    668 ;	../../fuzzy.h:531: return value;
      00012C 8C 82            [24]  669 	mov	dpl, r4
      00012E 8D 83            [24]  670 	mov	dph, r5
      000130 8E F0            [24]  671 	mov	b, r6
      000132 EF               [12]  672 	mov	a, r7
      000133                        673 00105$:
                           00007C   674 	C$fuzzy.h$532$1_0$16 ==.
                                    675 ;	../../fuzzy.h:532: }
                           00007C   676 	C$fuzzy.h$532$1_0$16 ==.
                           00007C   677 	XFcontroller_8051$fuzzy_clamp$0$0 ==.
      000133 22               [24]  678 	ret
                                    679 ;------------------------------------------------------------
                                    680 ;Allocation info for local variables in function 'fuzzy_not'
                                    681 ;------------------------------------------------------------
                                    682 ;membership    Allocated to registers r4 r5 r6 r7 
                                    683 ;------------------------------------------------------------
                           00007D   684 	G$fuzzy_not$0$0 ==.
                           00007D   685 	C$fuzzy.h$537$1_0$20 ==.
                                    686 ;	../../fuzzy.h:537: float fuzzy_not(
                                    687 ;	-----------------------------------------
                                    688 ;	 function fuzzy_not
                                    689 ;	-----------------------------------------
      000134                        690 _fuzzy_not:
                           00007D   691 	C$fuzzy.h$543$1_0$20 ==.
                                    692 ;	../../fuzzy.h:543: membership
      000134 12 00 B7         [24]  693 	lcall	_fuzzy_clamp
      000137 AC 82            [24]  694 	mov	r4, dpl
      000139 AD 83            [24]  695 	mov	r5, dph
      00013B AE F0            [24]  696 	mov	r6, b
      00013D FF               [12]  697 	mov	r7, a
      00013E C0 04            [24]  698 	push	ar4
      000140 C0 05            [24]  699 	push	ar5
      000142 C0 06            [24]  700 	push	ar6
      000144 C0 07            [24]  701 	push	ar7
      000146 90 00 00         [24]  702 	mov	dptr,#0x0000
      000149 75 F0 80         [24]  703 	mov	b, #0x80
      00014C 74 3F            [12]  704 	mov	a, #0x3f
      00014E 12 22 CC         [24]  705 	lcall	___fssub
      000151 AC 82            [24]  706 	mov	r4, dpl
      000153 AD 83            [24]  707 	mov	r5, dph
      000155 AE F0            [24]  708 	mov	r6, b
      000157 FF               [12]  709 	mov	r7, a
      000158 E5 81            [12]  710 	mov	a,sp
      00015A 24 FC            [12]  711 	add	a,#0xfc
      00015C F5 81            [12]  712 	mov	sp,a
      00015E 8C 82            [24]  713 	mov	dpl, r4
      000160 8D 83            [24]  714 	mov	dph, r5
      000162 8E F0            [24]  715 	mov	b, r6
      000164 EF               [12]  716 	mov	a, r7
                           0000AE   717 	C$fuzzy.h$545$1_0$20 ==.
                                    718 ;	../../fuzzy.h:545: }
                           0000AE   719 	C$fuzzy.h$545$1_0$20 ==.
                           0000AE   720 	XG$fuzzy_not$0$0 ==.
      000165 22               [24]  721 	ret
                                    722 ;------------------------------------------------------------
                                    723 ;Allocation info for local variables in function 'fuzzy_apply_hedge'
                                    724 ;------------------------------------------------------------
                                    725 ;hedge         Allocated to stack - _bp -3 +1 
                                    726 ;membership    Allocated to stack - _bp +1 +4 
                                    727 ;result        Allocated to registers r2 r3 r6 r7 
                                    728 ;------------------------------------------------------------
                           0000AF   729 	Fcontroller_8051$fuzzy_apply_hedge$0$0 ==.
                           0000AF   730 	C$fuzzy.h$555$1_0$22 ==.
                                    731 ;	../../fuzzy.h:555: static float fuzzy_apply_hedge(
                                    732 ;	-----------------------------------------
                                    733 ;	 function fuzzy_apply_hedge
                                    734 ;	-----------------------------------------
      000166                        735 _fuzzy_apply_hedge:
      000166 C0 0E            [24]  736 	push	_bp
      000168 85 81 0E         [24]  737 	mov	_bp,sp
      00016B AC 82            [24]  738 	mov	r4,dpl
      00016D AD 83            [24]  739 	mov	r5,dph
      00016F AE F0            [24]  740 	mov	r6,b
      000171 FF               [12]  741 	mov	r7,a
      000172 E5 81            [12]  742 	mov	a,sp
      000174 24 04            [12]  743 	add	a,#0x04
      000176 F5 81            [12]  744 	mov	sp,a
                           0000C1   745 	C$fuzzy.h$562$1_0$22 ==.
                                    746 ;	../../fuzzy.h:562: membership
      000178 8C 82            [24]  747 	mov	dpl, r4
      00017A 8D 83            [24]  748 	mov	dph, r5
      00017C 8E F0            [24]  749 	mov	b, r6
      00017E EF               [12]  750 	mov	a, r7
      00017F 12 00 B7         [24]  751 	lcall	_fuzzy_clamp
      000182 A8 0E            [24]  752 	mov	r0,_bp
      000184 08               [12]  753 	inc	r0
      000185 A6 82            [24]  754 	mov	@r0, dpl
      000187 08               [12]  755 	inc	r0
      000188 A6 83            [24]  756 	mov	@r0, dph
      00018A 08               [12]  757 	inc	r0
      00018B A6 F0            [24]  758 	mov	@r0, b
      00018D 08               [12]  759 	inc	r0
      00018E F6               [12]  760 	mov	@r0,a
                           0000D8   761 	C$fuzzy.h$567$2_0$23 ==.
                                    762 ;	../../fuzzy.h:567: float result =
      00018F 7A 00            [12]  763 	mov	r2,#0x00
      000191 7B 00            [12]  764 	mov	r3,#0x00
      000193 7E 80            [12]  765 	mov	r6,#0x80
      000195 7F 3F            [12]  766 	mov	r7,#0x3f
                           0000E0   767 	C$fuzzy.h$570$1_1$23 ==.
                                    768 ;	../../fuzzy.h:570: if (hedge == 0u) {
      000197 E5 0E            [12]  769 	mov	a,_bp
      000199 24 FD            [12]  770 	add	a,#0xfd
      00019B F8               [12]  771 	mov	r0,a
      00019C E6               [12]  772 	mov	a,@r0
      00019D 70 07            [24]  773 	jnz	00110$
                           0000E8   774 	C$fuzzy.h$572$2_1$24 ==.
                                    775 ;	../../fuzzy.h:572: 1u;
      00019F E5 0E            [12]  776 	mov	a,_bp
      0001A1 24 FD            [12]  777 	add	a,#0xfd
      0001A3 F8               [12]  778 	mov	r0,a
      0001A4 76 01            [12]  779 	mov	@r0,#0x01
                           0000EF   780 	C$fuzzy.h$575$1_1$22 ==.
                                    781 ;	../../fuzzy.h:575: while (hedge > 0u) {
      0001A6                        782 00110$:
      0001A6 E5 0E            [12]  783 	mov	a,_bp
      0001A8 24 FD            [12]  784 	add	a,#0xfd
      0001AA F8               [12]  785 	mov	r0,a
      0001AB 86 05            [24]  786 	mov	ar5,@r0
      0001AD                        787 00103$:
      0001AD ED               [12]  788 	mov	a,r5
      0001AE 60 30            [24]  789 	jz	00105$
                           0000F9   790 	C$fuzzy.h$577$1_1$22 ==.
                                    791 ;	../../fuzzy.h:577: membership;
      0001B0 C0 05            [24]  792 	push	ar5
      0001B2 A8 0E            [24]  793 	mov	r0,_bp
      0001B4 08               [12]  794 	inc	r0
      0001B5 E6               [12]  795 	mov	a,@r0
      0001B6 C0 E0            [24]  796 	push	acc
      0001B8 08               [12]  797 	inc	r0
      0001B9 E6               [12]  798 	mov	a,@r0
      0001BA C0 E0            [24]  799 	push	acc
      0001BC 08               [12]  800 	inc	r0
      0001BD E6               [12]  801 	mov	a,@r0
      0001BE C0 E0            [24]  802 	push	acc
      0001C0 08               [12]  803 	inc	r0
      0001C1 E6               [12]  804 	mov	a,@r0
      0001C2 C0 E0            [24]  805 	push	acc
                           00010D   806 	C$fuzzy.h$579$1_1$22 ==.
                                    807 ;	../../fuzzy.h:579: hedge--;
      0001C4 8A 82            [24]  808 	mov	dpl, r2
      0001C6 8B 83            [24]  809 	mov	dph, r3
      0001C8 8E F0            [24]  810 	mov	b, r6
      0001CA EF               [12]  811 	mov	a, r7
      0001CB 12 22 D7         [24]  812 	lcall	___fsmul
      0001CE AA 82            [24]  813 	mov	r2, dpl
      0001D0 AB 83            [24]  814 	mov	r3, dph
      0001D2 AE F0            [24]  815 	mov	r6, b
      0001D4 FF               [12]  816 	mov	r7, a
      0001D5 E5 81            [12]  817 	mov	a,sp
      0001D7 24 FC            [12]  818 	add	a,#0xfc
      0001D9 F5 81            [12]  819 	mov	sp,a
      0001DB D0 05            [24]  820 	pop	ar5
      0001DD 1D               [12]  821 	dec	r5
      0001DE 80 CD            [24]  822 	sjmp	00103$
      0001E0                        823 00105$:
                           000129   824 	C$fuzzy.h$583$1_1$23 ==.
                                    825 ;	../../fuzzy.h:583: result
      0001E0 8A 82            [24]  826 	mov	dpl, r2
      0001E2 8B 83            [24]  827 	mov	dph, r3
      0001E4 8E F0            [24]  828 	mov	b, r6
      0001E6 EF               [12]  829 	mov	a, r7
      0001E7 12 00 B7         [24]  830 	lcall	_fuzzy_clamp
                           000133   831 	C$fuzzy.h$599$1_1$22 ==.
                                    832 ;	../../fuzzy.h:599: }
      0001EA 85 0E 81         [24]  833 	mov	sp,_bp
      0001ED D0 0E            [24]  834 	pop	_bp
                           000138   835 	C$fuzzy.h$599$1_1$22 ==.
                           000138   836 	XFcontroller_8051$fuzzy_apply_hedge$0$0 ==.
      0001EF 22               [24]  837 	ret
                                    838 ;------------------------------------------------------------
                                    839 ;Allocation info for local variables in function 'fuzzy_and_array'
                                    840 ;------------------------------------------------------------
                                    841 ;count         Allocated to stack - _bp -4 +2 
                                    842 ;args          Allocated to stack - _bp -7 +3 
                                    843 ;method        Allocated to registers r5 
                                    844 ;result        Allocated to stack - _bp +5 +4 
                                    845 ;next          Allocated to stack - _bp +9 +4 
                                    846 ;index         Allocated to stack - _bp +13 +2 
                                    847 ;sloc0         Allocated to stack - _bp +1 +3 
                                    848 ;sloc1         Allocated to stack - _bp +4 +1 
                                    849 ;------------------------------------------------------------
                           000139   850 	G$fuzzy_and_array$0$0 ==.
                           000139   851 	C$fuzzy.h$614$1_1$27 ==.
                                    852 ;	../../fuzzy.h:614: float fuzzy_and_array(
                                    853 ;	-----------------------------------------
                                    854 ;	 function fuzzy_and_array
                                    855 ;	-----------------------------------------
      0001F0                        856 _fuzzy_and_array:
      0001F0 C0 0E            [24]  857 	push	_bp
      0001F2 E5 81            [12]  858 	mov	a,sp
      0001F4 F5 0E            [12]  859 	mov	_bp,a
      0001F6 24 0E            [12]  860 	add	a,#0x0e
      0001F8 F5 81            [12]  861 	mov	sp,a
      0001FA AD 82            [24]  862 	mov	r5, dpl
                           000145   863 	C$fuzzy.h$625$1_0$27 ==.
                                    864 ;	../../fuzzy.h:625: args == NULL ||
      0001FC E5 0E            [12]  865 	mov	a,_bp
      0001FE 24 F9            [12]  866 	add	a,#0xf9
      000200 F8               [12]  867 	mov	r0,a
      000201 E6               [12]  868 	mov	a,@r0
      000202 08               [12]  869 	inc	r0
      000203 46               [12]  870 	orl	a,@r0
      000204 60 0A            [24]  871 	jz	00101$
                           00014F   872 	C$fuzzy.h$626$1_0$27 ==.
                                    873 ;	../../fuzzy.h:626: count == 0u
      000206 E5 0E            [12]  874 	mov	a,_bp
      000208 24 FC            [12]  875 	add	a,#0xfc
      00020A F8               [12]  876 	mov	r0,a
      00020B E6               [12]  877 	mov	a,@r0
      00020C 08               [12]  878 	inc	r0
      00020D 46               [12]  879 	orl	a,@r0
      00020E 70 0B            [24]  880 	jnz	00102$
      000210                        881 00101$:
                           000159   882 	C$fuzzy.h$628$2_0$28 ==.
                                    883 ;	../../fuzzy.h:628: return LEVEL_HI;
      000210 90 00 00         [24]  884 	mov	dptr,#0x0000
      000213 75 F0 80         [24]  885 	mov	b, #0x80
      000216 74 3F            [12]  886 	mov	a, #0x3f
      000218 02 04 89         [24]  887 	ljmp	00121$
      00021B                        888 00102$:
                           000164   889 	C$fuzzy.h$632$1_0$27 ==.
                                    890 ;	../../fuzzy.h:632: method != FUZZY_LOGIC_STANDARD &&
      00021B ED               [12]  891 	mov	a,r5
      00021C 60 13            [24]  892 	jz	00105$
                           000167   893 	C$fuzzy.h$633$1_0$27 ==.
                                    894 ;	../../fuzzy.h:633: method != FUZZY_LOGIC_ALGEBRAIC &&
      00021E BD 01 02         [24]  895 	cjne	r5,#0x01,00192$
      000221 80 0E            [24]  896 	sjmp	00105$
      000223                        897 00192$:
                           00016C   898 	C$fuzzy.h$635$1_0$27 ==.
                                    899 ;	../../fuzzy.h:635: ) {
      000223 BD 02 02         [24]  900 	cjne	r5,#0x02,00193$
      000226 80 09            [24]  901 	sjmp	00105$
      000228                        902 00193$:
                           000171   903 	C$fuzzy.h$636$2_0$29 ==.
                                    904 ;	../../fuzzy.h:636: return LEVEL_LO;
      000228 90 00 00         [24]  905 	mov	dptr,#0x0000
      00022B E4               [12]  906 	clr	a
      00022C F5 F0            [12]  907 	mov	b,a
      00022E 02 04 89         [24]  908 	ljmp	00121$
      000231                        909 00105$:
                           00017A   910 	C$fuzzy.h$641$1_0$27 ==.
                                    911 ;	../../fuzzy.h:641: args[0]
      000231 E5 0E            [12]  912 	mov	a,_bp
      000233 24 F9            [12]  913 	add	a,#0xf9
      000235 F8               [12]  914 	mov	r0,a
      000236 A9 0E            [24]  915 	mov	r1,_bp
      000238 09               [12]  916 	inc	r1
      000239 E6               [12]  917 	mov	a,@r0
      00023A F7               [12]  918 	mov	@r1,a
      00023B 08               [12]  919 	inc	r0
      00023C E6               [12]  920 	mov	a,@r0
      00023D 09               [12]  921 	inc	r1
      00023E F7               [12]  922 	mov	@r1,a
      00023F 08               [12]  923 	inc	r0
      000240 E6               [12]  924 	mov	a,@r0
      000241 09               [12]  925 	inc	r1
      000242 F7               [12]  926 	mov	@r1,a
      000243 A8 0E            [24]  927 	mov	r0,_bp
      000245 08               [12]  928 	inc	r0
      000246 86 82            [24]  929 	mov	dpl,@r0
      000248 08               [12]  930 	inc	r0
      000249 86 83            [24]  931 	mov	dph,@r0
      00024B 08               [12]  932 	inc	r0
      00024C 86 F0            [24]  933 	mov	b,@r0
      00024E 12 26 33         [24]  934 	lcall	__gptrget
      000251 FA               [12]  935 	mov	r2,a
      000252 A3               [24]  936 	inc	dptr
      000253 12 26 33         [24]  937 	lcall	__gptrget
      000256 FB               [12]  938 	mov	r3,a
      000257 A3               [24]  939 	inc	dptr
      000258 12 26 33         [24]  940 	lcall	__gptrget
      00025B FE               [12]  941 	mov	r6,a
      00025C A3               [24]  942 	inc	dptr
      00025D 12 26 33         [24]  943 	lcall	__gptrget
      000260 8A 82            [24]  944 	mov	dpl,r2
      000262 8B 83            [24]  945 	mov	dph,r3
      000264 8E F0            [24]  946 	mov	b,r6
      000266 C0 05            [24]  947 	push	ar5
      000268 12 00 B7         [24]  948 	lcall	_fuzzy_clamp
      00026B C8               [12]  949 	xch	a,r0
      00026C E5 0E            [12]  950 	mov	a,_bp
      00026E 24 05            [12]  951 	add	a,#0x05
      000270 C8               [12]  952 	xch	a,r0
      000271 A6 82            [24]  953 	mov	@r0, dpl
      000273 08               [12]  954 	inc	r0
      000274 A6 83            [24]  955 	mov	@r0, dph
      000276 08               [12]  956 	inc	r0
      000277 A6 F0            [24]  957 	mov	@r0, b
      000279 08               [12]  958 	inc	r0
      00027A F6               [12]  959 	mov	@r0,a
      00027B D0 05            [24]  960 	pop	ar5
                           0001C6   961 	C$fuzzy.h$645$3_0$31 ==.
                                    962 ;	../../fuzzy.h:645: index = 1u;
      00027D E4               [12]  963 	clr	a
      00027E BD 00 01         [24]  964 	cjne	r5,#0x00,00194$
      000281 04               [12]  965 	inc	a
      000282                        966 00194$:
      000282 FB               [12]  967 	mov	r3,a
      000283 BD 01 03         [24]  968 	cjne	r5,#0x01,00196$
      000286 ED               [12]  969 	mov	a,r5
      000287 80 01            [24]  970 	sjmp	00197$
      000289                        971 00196$:
      000289 E4               [12]  972 	clr	a
      00028A                        973 00197$:
      00028A FA               [12]  974 	mov	r2,a
      00028B E5 0E            [12]  975 	mov	a,_bp
      00028D 24 04            [12]  976 	add	a,#0x04
      00028F F8               [12]  977 	mov	r0,a
      000290 E4               [12]  978 	clr	a
      000291 BD 02 01         [24]  979 	cjne	r5,#0x02,00198$
      000294 04               [12]  980 	inc	a
      000295                        981 00198$:
      000295 F6               [12]  982 	mov	@r0,a
      000296 E5 0E            [12]  983 	mov	a,_bp
      000298 24 0D            [12]  984 	add	a,#0x0d
      00029A F8               [12]  985 	mov	r0,a
      00029B 76 01            [12]  986 	mov	@r0,#0x01
      00029D 08               [12]  987 	inc	r0
      00029E 76 00            [12]  988 	mov	@r0,#0x00
      0002A0                        989 00119$:
                           0001E9   990 	C$fuzzy.h$646$2_0$30 ==.
                                    991 ;	../../fuzzy.h:646: index < count;
      0002A0 E5 0E            [12]  992 	mov	a,_bp
      0002A2 24 0D            [12]  993 	add	a,#0x0d
      0002A4 F8               [12]  994 	mov	r0,a
      0002A5 E5 0E            [12]  995 	mov	a,_bp
      0002A7 24 FC            [12]  996 	add	a,#0xfc
      0002A9 F9               [12]  997 	mov	r1,a
      0002AA C3               [12]  998 	clr	c
      0002AB E6               [12]  999 	mov	a,@r0
      0002AC 97               [12] 1000 	subb	a,@r1
      0002AD 08               [12] 1001 	inc	r0
      0002AE E6               [12] 1002 	mov	a,@r0
      0002AF 09               [12] 1003 	inc	r1
      0002B0 97               [12] 1004 	subb	a,@r1
      0002B1 40 03            [24] 1005 	jc	00200$
      0002B3 02 04 77         [24] 1006 	ljmp	00117$
      0002B6                       1007 00200$:
                           0001FF  1008 	C$fuzzy.h$651$1_0$27 ==.
                                   1009 ;	../../fuzzy.h:651: args[index]
      0002B6 C0 02            [24] 1010 	push	ar2
      0002B8 E5 0E            [12] 1011 	mov	a,_bp
      0002BA 24 0D            [12] 1012 	add	a,#0x0d
      0002BC F8               [12] 1013 	mov	r0,a
      0002BD E6               [12] 1014 	mov	a,@r0
      0002BE 26               [12] 1015 	add	a,@r0
      0002BF FD               [12] 1016 	mov	r5,a
      0002C0 08               [12] 1017 	inc	r0
      0002C1 E6               [12] 1018 	mov	a,@r0
      0002C2 33               [12] 1019 	rlc	a
      0002C3 FC               [12] 1020 	mov	r4,a
      0002C4 ED               [12] 1021 	mov	a,r5
      0002C5 2D               [12] 1022 	add	a,r5
      0002C6 FD               [12] 1023 	mov	r5,a
      0002C7 EC               [12] 1024 	mov	a,r4
      0002C8 33               [12] 1025 	rlc	a
      0002C9 FC               [12] 1026 	mov	r4,a
      0002CA A8 0E            [24] 1027 	mov	r0,_bp
      0002CC 08               [12] 1028 	inc	r0
      0002CD ED               [12] 1029 	mov	a,r5
      0002CE 26               [12] 1030 	add	a, @r0
      0002CF FA               [12] 1031 	mov	r2,a
      0002D0 EC               [12] 1032 	mov	a,r4
      0002D1 08               [12] 1033 	inc	r0
      0002D2 36               [12] 1034 	addc	a, @r0
      0002D3 FC               [12] 1035 	mov	r4,a
      0002D4 08               [12] 1036 	inc	r0
      0002D5 86 05            [24] 1037 	mov	ar5,@r0
      0002D7 8A 82            [24] 1038 	mov	dpl,r2
      0002D9 8C 83            [24] 1039 	mov	dph,r4
      0002DB 8D F0            [24] 1040 	mov	b,r5
      0002DD 12 26 33         [24] 1041 	lcall	__gptrget
      0002E0 FA               [12] 1042 	mov	r2,a
      0002E1 A3               [24] 1043 	inc	dptr
      0002E2 12 26 33         [24] 1044 	lcall	__gptrget
      0002E5 FC               [12] 1045 	mov	r4,a
      0002E6 A3               [24] 1046 	inc	dptr
      0002E7 12 26 33         [24] 1047 	lcall	__gptrget
      0002EA FD               [12] 1048 	mov	r5,a
      0002EB A3               [24] 1049 	inc	dptr
      0002EC 12 26 33         [24] 1050 	lcall	__gptrget
      0002EF 8A 82            [24] 1051 	mov	dpl,r2
      0002F1 8C 83            [24] 1052 	mov	dph,r4
      0002F3 8D F0            [24] 1053 	mov	b,r5
      0002F5 C0 03            [24] 1054 	push	ar3
      0002F7 C0 02            [24] 1055 	push	ar2
      0002F9 12 00 B7         [24] 1056 	lcall	_fuzzy_clamp
      0002FC C8               [12] 1057 	xch	a,r0
      0002FD E5 0E            [12] 1058 	mov	a,_bp
      0002FF 24 09            [12] 1059 	add	a,#0x09
      000301 C8               [12] 1060 	xch	a,r0
      000302 A6 82            [24] 1061 	mov	@r0, dpl
      000304 08               [12] 1062 	inc	r0
      000305 A6 83            [24] 1063 	mov	@r0, dph
      000307 08               [12] 1064 	inc	r0
      000308 A6 F0            [24] 1065 	mov	@r0, b
      00030A 08               [12] 1066 	inc	r0
      00030B F6               [12] 1067 	mov	@r0,a
      00030C D0 02            [24] 1068 	pop	ar2
      00030E D0 03            [24] 1069 	pop	ar3
                           000259  1070 	C$fuzzy.h$654$1_0$27 ==.
                                   1071 ;	../../fuzzy.h:654: switch (method) {
      000310 D0 02            [24] 1072 	pop	ar2
      000312 EB               [12] 1073 	mov	a,r3
      000313 70 11            [24] 1074 	jnz	00108$
      000315 EA               [12] 1075 	mov	a,r2
      000316 70 65            [24] 1076 	jnz	00111$
      000318 E5 0E            [12] 1077 	mov	a,_bp
      00031A 24 04            [12] 1078 	add	a,#0x04
      00031C F8               [12] 1079 	mov	r0,a
      00031D E6               [12] 1080 	mov	a,@r0
      00031E 60 03            [24] 1081 	jz	00203$
      000320 02 03 C4         [24] 1082 	ljmp	00112$
      000323                       1083 00203$:
      000323 02 04 61         [24] 1084 	ljmp	00115$
                           00026F  1085 	C$fuzzy.h$655$4_0$32 ==.
                                   1086 ;	../../fuzzy.h:655: case FUZZY_LOGIC_STANDARD:
      000326                       1087 00108$:
                           00026F  1088 	C$fuzzy.h$656$1_0$27 ==.
                                   1089 ;	../../fuzzy.h:656: if (next < result) {
      000326 C0 03            [24] 1090 	push	ar3
      000328 C0 02            [24] 1091 	push	ar2
      00032A E5 0E            [12] 1092 	mov	a,_bp
      00032C 24 05            [12] 1093 	add	a,#0x05
      00032E F8               [12] 1094 	mov	r0,a
      00032F E6               [12] 1095 	mov	a,@r0
      000330 C0 E0            [24] 1096 	push	acc
      000332 08               [12] 1097 	inc	r0
      000333 E6               [12] 1098 	mov	a,@r0
      000334 C0 E0            [24] 1099 	push	acc
      000336 08               [12] 1100 	inc	r0
      000337 E6               [12] 1101 	mov	a,@r0
      000338 C0 E0            [24] 1102 	push	acc
      00033A 08               [12] 1103 	inc	r0
      00033B E6               [12] 1104 	mov	a,@r0
      00033C C0 E0            [24] 1105 	push	acc
      00033E E5 0E            [12] 1106 	mov	a,_bp
      000340 24 09            [12] 1107 	add	a,#0x09
      000342 F8               [12] 1108 	mov	r0,a
      000343 86 82            [24] 1109 	mov	dpl, @r0
      000345 08               [12] 1110 	inc	r0
      000346 86 83            [24] 1111 	mov	dph, @r0
      000348 08               [12] 1112 	inc	r0
      000349 86 F0            [24] 1113 	mov	b, @r0
      00034B 08               [12] 1114 	inc	r0
      00034C E6               [12] 1115 	mov	a, @r0
      00034D 12 24 07         [24] 1116 	lcall	___fslt
      000350 AF 82            [24] 1117 	mov	r7, dpl
      000352 E5 81            [12] 1118 	mov	a,sp
      000354 24 FC            [12] 1119 	add	a,#0xfc
      000356 F5 81            [12] 1120 	mov	sp,a
      000358 D0 02            [24] 1121 	pop	ar2
      00035A D0 03            [24] 1122 	pop	ar3
      00035C EF               [12] 1123 	mov	a,r7
      00035D 70 03            [24] 1124 	jnz	00204$
      00035F 02 04 69         [24] 1125 	ljmp	00120$
      000362                       1126 00204$:
                           0002AB  1127 	C$fuzzy.h$657$5_0$33 ==.
                                   1128 ;	../../fuzzy.h:657: result = next;
      000362 E5 0E            [12] 1129 	mov	a,_bp
      000364 24 09            [12] 1130 	add	a,#0x09
      000366 F8               [12] 1131 	mov	r0,a
      000367 E5 0E            [12] 1132 	mov	a,_bp
      000369 24 05            [12] 1133 	add	a,#0x05
      00036B F9               [12] 1134 	mov	r1,a
      00036C E6               [12] 1135 	mov	a,@r0
      00036D F7               [12] 1136 	mov	@r1,a
      00036E 08               [12] 1137 	inc	r0
      00036F E6               [12] 1138 	mov	a,@r0
      000370 09               [12] 1139 	inc	r1
      000371 F7               [12] 1140 	mov	@r1,a
      000372 08               [12] 1141 	inc	r0
      000373 E6               [12] 1142 	mov	a,@r0
      000374 09               [12] 1143 	inc	r1
      000375 F7               [12] 1144 	mov	@r1,a
      000376 08               [12] 1145 	inc	r0
      000377 E6               [12] 1146 	mov	a,@r0
      000378 09               [12] 1147 	inc	r1
      000379 F7               [12] 1148 	mov	@r1,a
                           0002C3  1149 	C$fuzzy.h$659$4_0$32 ==.
                                   1150 ;	../../fuzzy.h:659: break;
      00037A 02 04 69         [24] 1151 	ljmp	00120$
                           0002C6  1152 	C$fuzzy.h$661$4_0$32 ==.
                                   1153 ;	../../fuzzy.h:661: case FUZZY_LOGIC_ALGEBRAIC:
      00037D                       1154 00111$:
                           0002C6  1155 	C$fuzzy.h$663$1_0$27 ==.
                                   1156 ;	../../fuzzy.h:663: next;
      00037D C0 03            [24] 1157 	push	ar3
      00037F C0 02            [24] 1158 	push	ar2
      000381 E5 0E            [12] 1159 	mov	a,_bp
      000383 24 09            [12] 1160 	add	a,#0x09
      000385 F8               [12] 1161 	mov	r0,a
      000386 E6               [12] 1162 	mov	a,@r0
      000387 C0 E0            [24] 1163 	push	acc
      000389 08               [12] 1164 	inc	r0
      00038A E6               [12] 1165 	mov	a,@r0
      00038B C0 E0            [24] 1166 	push	acc
      00038D 08               [12] 1167 	inc	r0
      00038E E6               [12] 1168 	mov	a,@r0
      00038F C0 E0            [24] 1169 	push	acc
      000391 08               [12] 1170 	inc	r0
      000392 E6               [12] 1171 	mov	a,@r0
      000393 C0 E0            [24] 1172 	push	acc
                           0002DE  1173 	C$fuzzy.h$664$1_0$27 ==.
                                   1174 ;	../../fuzzy.h:664: break;
      000395 E5 0E            [12] 1175 	mov	a,_bp
      000397 24 05            [12] 1176 	add	a,#0x05
      000399 F8               [12] 1177 	mov	r0,a
      00039A 86 82            [24] 1178 	mov	dpl, @r0
      00039C 08               [12] 1179 	inc	r0
      00039D 86 83            [24] 1180 	mov	dph, @r0
      00039F 08               [12] 1181 	inc	r0
      0003A0 86 F0            [24] 1182 	mov	b, @r0
      0003A2 08               [12] 1183 	inc	r0
      0003A3 E6               [12] 1184 	mov	a, @r0
      0003A4 12 22 D7         [24] 1185 	lcall	___fsmul
      0003A7 C8               [12] 1186 	xch	a,r0
      0003A8 E5 0E            [12] 1187 	mov	a,_bp
      0003AA 24 05            [12] 1188 	add	a,#0x05
      0003AC C8               [12] 1189 	xch	a,r0
      0003AD A6 82            [24] 1190 	mov	@r0, dpl
      0003AF 08               [12] 1191 	inc	r0
      0003B0 A6 83            [24] 1192 	mov	@r0, dph
      0003B2 08               [12] 1193 	inc	r0
      0003B3 A6 F0            [24] 1194 	mov	@r0, b
      0003B5 08               [12] 1195 	inc	r0
      0003B6 F6               [12] 1196 	mov	@r0,a
      0003B7 E5 81            [12] 1197 	mov	a,sp
      0003B9 24 FC            [12] 1198 	add	a,#0xfc
      0003BB F5 81            [12] 1199 	mov	sp,a
      0003BD D0 02            [24] 1200 	pop	ar2
      0003BF D0 03            [24] 1201 	pop	ar3
      0003C1 02 04 69         [24] 1202 	ljmp	00120$
                           00030D  1203 	C$fuzzy.h$666$4_0$32 ==.
                                   1204 ;	../../fuzzy.h:666: case FUZZY_LOGIC_BOUNDED:
      0003C4                       1205 00112$:
                           00030D  1206 	C$fuzzy.h$669$1_0$27 ==.
                                   1207 ;	../../fuzzy.h:669: next -
      0003C4 C0 03            [24] 1208 	push	ar3
      0003C6 C0 02            [24] 1209 	push	ar2
      0003C8 E5 0E            [12] 1210 	mov	a,_bp
      0003CA 24 09            [12] 1211 	add	a,#0x09
      0003CC F8               [12] 1212 	mov	r0,a
      0003CD E6               [12] 1213 	mov	a,@r0
      0003CE C0 E0            [24] 1214 	push	acc
      0003D0 08               [12] 1215 	inc	r0
      0003D1 E6               [12] 1216 	mov	a,@r0
      0003D2 C0 E0            [24] 1217 	push	acc
      0003D4 08               [12] 1218 	inc	r0
      0003D5 E6               [12] 1219 	mov	a,@r0
      0003D6 C0 E0            [24] 1220 	push	acc
      0003D8 08               [12] 1221 	inc	r0
      0003D9 E6               [12] 1222 	mov	a,@r0
      0003DA C0 E0            [24] 1223 	push	acc
      0003DC E5 0E            [12] 1224 	mov	a,_bp
      0003DE 24 05            [12] 1225 	add	a,#0x05
      0003E0 F8               [12] 1226 	mov	r0,a
      0003E1 86 82            [24] 1227 	mov	dpl, @r0
      0003E3 08               [12] 1228 	inc	r0
      0003E4 86 83            [24] 1229 	mov	dph, @r0
      0003E6 08               [12] 1230 	inc	r0
      0003E7 86 F0            [24] 1231 	mov	b, @r0
      0003E9 08               [12] 1232 	inc	r0
      0003EA E6               [12] 1233 	mov	a, @r0
      0003EB 12 24 59         [24] 1234 	lcall	___fsadd
      0003EE AC 82            [24] 1235 	mov	r4, dpl
      0003F0 AD 83            [24] 1236 	mov	r5, dph
      0003F2 AE F0            [24] 1237 	mov	r6, b
      0003F4 FF               [12] 1238 	mov	r7, a
      0003F5 E5 81            [12] 1239 	mov	a,sp
      0003F7 24 FC            [12] 1240 	add	a,#0xfc
      0003F9 F5 81            [12] 1241 	mov	sp,a
      0003FB E4               [12] 1242 	clr	a
      0003FC C0 E0            [24] 1243 	push	acc
      0003FE C0 E0            [24] 1244 	push	acc
      000400 74 80            [12] 1245 	mov	a,#0x80
      000402 C0 E0            [24] 1246 	push	acc
      000404 74 3F            [12] 1247 	mov	a,#0x3f
      000406 C0 E0            [24] 1248 	push	acc
                           000351  1249 	C$fuzzy.h$672$1_0$27 ==.
                                   1250 ;	../../fuzzy.h:672: if (result < LEVEL_LO) {
      000408 8C 82            [24] 1251 	mov	dpl, r4
      00040A 8D 83            [24] 1252 	mov	dph, r5
      00040C 8E F0            [24] 1253 	mov	b, r6
      00040E EF               [12] 1254 	mov	a, r7
      00040F 12 22 CC         [24] 1255 	lcall	___fssub
      000412 C8               [12] 1256 	xch	a,r0
      000413 E5 0E            [12] 1257 	mov	a,_bp
      000415 24 05            [12] 1258 	add	a,#0x05
      000417 C8               [12] 1259 	xch	a,r0
      000418 A6 82            [24] 1260 	mov	@r0, dpl
      00041A 08               [12] 1261 	inc	r0
      00041B A6 83            [24] 1262 	mov	@r0, dph
      00041D 08               [12] 1263 	inc	r0
      00041E A6 F0            [24] 1264 	mov	@r0, b
      000420 08               [12] 1265 	inc	r0
      000421 F6               [12] 1266 	mov	@r0,a
      000422 E5 81            [12] 1267 	mov	a,sp
      000424 24 FC            [12] 1268 	add	a,#0xfc
      000426 F5 81            [12] 1269 	mov	sp,a
      000428 E4               [12] 1270 	clr	a
      000429 C0 E0            [24] 1271 	push	acc
      00042B C0 E0            [24] 1272 	push	acc
      00042D C0 E0            [24] 1273 	push	acc
      00042F C0 E0            [24] 1274 	push	acc
      000431 E5 0E            [12] 1275 	mov	a,_bp
      000433 24 05            [12] 1276 	add	a,#0x05
      000435 F8               [12] 1277 	mov	r0,a
      000436 86 82            [24] 1278 	mov	dpl, @r0
      000438 08               [12] 1279 	inc	r0
      000439 86 83            [24] 1280 	mov	dph, @r0
      00043B 08               [12] 1281 	inc	r0
      00043C 86 F0            [24] 1282 	mov	b, @r0
      00043E 08               [12] 1283 	inc	r0
      00043F E6               [12] 1284 	mov	a, @r0
      000440 12 24 07         [24] 1285 	lcall	___fslt
      000443 AF 82            [24] 1286 	mov	r7, dpl
      000445 E5 81            [12] 1287 	mov	a,sp
      000447 24 FC            [12] 1288 	add	a,#0xfc
      000449 F5 81            [12] 1289 	mov	sp,a
      00044B D0 02            [24] 1290 	pop	ar2
      00044D D0 03            [24] 1291 	pop	ar3
      00044F EF               [12] 1292 	mov	a,r7
      000450 60 17            [24] 1293 	jz	00120$
                           00039B  1294 	C$fuzzy.h$673$5_0$34 ==.
                                   1295 ;	../../fuzzy.h:673: result = LEVEL_LO;
      000452 E5 0E            [12] 1296 	mov	a,_bp
      000454 24 05            [12] 1297 	add	a,#0x05
      000456 F8               [12] 1298 	mov	r0,a
      000457 E4               [12] 1299 	clr	a
      000458 F6               [12] 1300 	mov	@r0,a
      000459 08               [12] 1301 	inc	r0
      00045A F6               [12] 1302 	mov	@r0,a
      00045B 08               [12] 1303 	inc	r0
      00045C F6               [12] 1304 	mov	@r0,a
      00045D 08               [12] 1305 	inc	r0
      00045E F6               [12] 1306 	mov	@r0,a
                           0003A8  1307 	C$fuzzy.h$675$4_0$32 ==.
                                   1308 ;	../../fuzzy.h:675: break;
                           0003A8  1309 	C$fuzzy.h$677$4_0$32 ==.
                                   1310 ;	../../fuzzy.h:677: default:
      00045F 80 08            [24] 1311 	sjmp	00120$
      000461                       1312 00115$:
                           0003AA  1313 	C$fuzzy.h$678$4_0$32 ==.
                                   1314 ;	../../fuzzy.h:678: return LEVEL_LO;
      000461 90 00 00         [24] 1315 	mov	dptr,#0x0000
      000464 E4               [12] 1316 	clr	a
      000465 F5 F0            [12] 1317 	mov	b,a
                           0003B0  1318 	C$fuzzy.h$679$3_0$31 ==.
                                   1319 ;	../../fuzzy.h:679: }
      000467 80 20            [24] 1320 	sjmp	00121$
      000469                       1321 00120$:
                           0003B2  1322 	C$fuzzy.h$647$2_0$30 ==.
                                   1323 ;	../../fuzzy.h:647: index++
      000469 E5 0E            [12] 1324 	mov	a,_bp
      00046B 24 0D            [12] 1325 	add	a,#0x0d
      00046D F8               [12] 1326 	mov	r0,a
      00046E 06               [12] 1327 	inc	@r0
      00046F B6 00 02         [24] 1328 	cjne	@r0,#0x00,00206$
      000472 08               [12] 1329 	inc	r0
      000473 06               [12] 1330 	inc	@r0
      000474                       1331 00206$:
      000474 02 02 A0         [24] 1332 	ljmp	00119$
      000477                       1333 00117$:
                           0003C0  1334 	C$fuzzy.h$683$1_0$27 ==.
                                   1335 ;	../../fuzzy.h:683: result
      000477 E5 0E            [12] 1336 	mov	a,_bp
      000479 24 05            [12] 1337 	add	a,#0x05
      00047B F8               [12] 1338 	mov	r0,a
      00047C 86 82            [24] 1339 	mov	dpl, @r0
      00047E 08               [12] 1340 	inc	r0
      00047F 86 83            [24] 1341 	mov	dph, @r0
      000481 08               [12] 1342 	inc	r0
      000482 86 F0            [24] 1343 	mov	b, @r0
      000484 08               [12] 1344 	inc	r0
      000485 E6               [12] 1345 	mov	a, @r0
      000486 12 00 B7         [24] 1346 	lcall	_fuzzy_clamp
      000489                       1347 00121$:
                           0003D2  1348 	C$fuzzy.h$685$1_0$27 ==.
                                   1349 ;	../../fuzzy.h:685: }
      000489 85 0E 81         [24] 1350 	mov	sp,_bp
      00048C D0 0E            [24] 1351 	pop	_bp
                           0003D7  1352 	C$fuzzy.h$685$1_0$27 ==.
                           0003D7  1353 	XG$fuzzy_and_array$0$0 ==.
      00048E 22               [24] 1354 	ret
                                   1355 ;------------------------------------------------------------
                                   1356 ;Allocation info for local variables in function 'fuzzy_or_array'
                                   1357 ;------------------------------------------------------------
                                   1358 ;count         Allocated to stack - _bp -4 +2 
                                   1359 ;args          Allocated to stack - _bp -7 +3 
                                   1360 ;method        Allocated to registers r5 
                                   1361 ;result        Allocated to stack - _bp +10 +4 
                                   1362 ;next          Allocated to registers r4 r5 r6 r3 
                                   1363 ;index         Allocated to stack - _bp +14 +2 
                                   1364 ;sloc0         Allocated to stack - _bp +1 +3 
                                   1365 ;sloc1         Allocated to stack - _bp +4 +1 
                                   1366 ;sloc2         Allocated to stack - _bp +5 +1 
                                   1367 ;sloc3         Allocated to stack - _bp +6 +4 
                                   1368 ;------------------------------------------------------------
                           0003D8  1369 	G$fuzzy_or_array$0$0 ==.
                           0003D8  1370 	C$fuzzy.h$700$1_0$36 ==.
                                   1371 ;	../../fuzzy.h:700: float fuzzy_or_array(
                                   1372 ;	-----------------------------------------
                                   1373 ;	 function fuzzy_or_array
                                   1374 ;	-----------------------------------------
      00048F                       1375 _fuzzy_or_array:
      00048F C0 0E            [24] 1376 	push	_bp
      000491 E5 81            [12] 1377 	mov	a,sp
      000493 F5 0E            [12] 1378 	mov	_bp,a
      000495 24 0F            [12] 1379 	add	a,#0x0f
      000497 F5 81            [12] 1380 	mov	sp,a
      000499 AD 82            [24] 1381 	mov	r5, dpl
                           0003E4  1382 	C$fuzzy.h$711$1_0$36 ==.
                                   1383 ;	../../fuzzy.h:711: args == NULL ||
      00049B E5 0E            [12] 1384 	mov	a,_bp
      00049D 24 F9            [12] 1385 	add	a,#0xf9
      00049F F8               [12] 1386 	mov	r0,a
      0004A0 E6               [12] 1387 	mov	a,@r0
      0004A1 08               [12] 1388 	inc	r0
      0004A2 46               [12] 1389 	orl	a,@r0
      0004A3 60 0A            [24] 1390 	jz	00101$
                           0003EE  1391 	C$fuzzy.h$712$1_0$36 ==.
                                   1392 ;	../../fuzzy.h:712: count == 0u
      0004A5 E5 0E            [12] 1393 	mov	a,_bp
      0004A7 24 FC            [12] 1394 	add	a,#0xfc
      0004A9 F8               [12] 1395 	mov	r0,a
      0004AA E6               [12] 1396 	mov	a,@r0
      0004AB 08               [12] 1397 	inc	r0
      0004AC 46               [12] 1398 	orl	a,@r0
      0004AD 70 09            [24] 1399 	jnz	00102$
      0004AF                       1400 00101$:
                           0003F8  1401 	C$fuzzy.h$714$2_0$37 ==.
                                   1402 ;	../../fuzzy.h:714: return LEVEL_LO;
      0004AF 90 00 00         [24] 1403 	mov	dptr,#0x0000
      0004B2 E4               [12] 1404 	clr	a
      0004B3 F5 F0            [12] 1405 	mov	b,a
      0004B5 02 07 4B         [24] 1406 	ljmp	00121$
      0004B8                       1407 00102$:
                           000401  1408 	C$fuzzy.h$718$1_0$36 ==.
                                   1409 ;	../../fuzzy.h:718: method != FUZZY_LOGIC_STANDARD &&
      0004B8 ED               [12] 1410 	mov	a,r5
      0004B9 60 13            [24] 1411 	jz	00105$
                           000404  1412 	C$fuzzy.h$719$1_0$36 ==.
                                   1413 ;	../../fuzzy.h:719: method != FUZZY_LOGIC_ALGEBRAIC &&
      0004BB BD 01 02         [24] 1414 	cjne	r5,#0x01,00192$
      0004BE 80 0E            [24] 1415 	sjmp	00105$
      0004C0                       1416 00192$:
                           000409  1417 	C$fuzzy.h$721$1_0$36 ==.
                                   1418 ;	../../fuzzy.h:721: ) {
      0004C0 BD 02 02         [24] 1419 	cjne	r5,#0x02,00193$
      0004C3 80 09            [24] 1420 	sjmp	00105$
      0004C5                       1421 00193$:
                           00040E  1422 	C$fuzzy.h$722$2_0$38 ==.
                                   1423 ;	../../fuzzy.h:722: return LEVEL_LO;
      0004C5 90 00 00         [24] 1424 	mov	dptr,#0x0000
      0004C8 E4               [12] 1425 	clr	a
      0004C9 F5 F0            [12] 1426 	mov	b,a
      0004CB 02 07 4B         [24] 1427 	ljmp	00121$
      0004CE                       1428 00105$:
                           000417  1429 	C$fuzzy.h$727$1_0$36 ==.
                                   1430 ;	../../fuzzy.h:727: args[0]
      0004CE E5 0E            [12] 1431 	mov	a,_bp
      0004D0 24 F9            [12] 1432 	add	a,#0xf9
      0004D2 F8               [12] 1433 	mov	r0,a
      0004D3 A9 0E            [24] 1434 	mov	r1,_bp
      0004D5 09               [12] 1435 	inc	r1
      0004D6 E6               [12] 1436 	mov	a,@r0
      0004D7 F7               [12] 1437 	mov	@r1,a
      0004D8 08               [12] 1438 	inc	r0
      0004D9 E6               [12] 1439 	mov	a,@r0
      0004DA 09               [12] 1440 	inc	r1
      0004DB F7               [12] 1441 	mov	@r1,a
      0004DC 08               [12] 1442 	inc	r0
      0004DD E6               [12] 1443 	mov	a,@r0
      0004DE 09               [12] 1444 	inc	r1
      0004DF F7               [12] 1445 	mov	@r1,a
      0004E0 A8 0E            [24] 1446 	mov	r0,_bp
      0004E2 08               [12] 1447 	inc	r0
      0004E3 86 82            [24] 1448 	mov	dpl,@r0
      0004E5 08               [12] 1449 	inc	r0
      0004E6 86 83            [24] 1450 	mov	dph,@r0
      0004E8 08               [12] 1451 	inc	r0
      0004E9 86 F0            [24] 1452 	mov	b,@r0
      0004EB 12 26 33         [24] 1453 	lcall	__gptrget
      0004EE FA               [12] 1454 	mov	r2,a
      0004EF A3               [24] 1455 	inc	dptr
      0004F0 12 26 33         [24] 1456 	lcall	__gptrget
      0004F3 FB               [12] 1457 	mov	r3,a
      0004F4 A3               [24] 1458 	inc	dptr
      0004F5 12 26 33         [24] 1459 	lcall	__gptrget
      0004F8 FE               [12] 1460 	mov	r6,a
      0004F9 A3               [24] 1461 	inc	dptr
      0004FA 12 26 33         [24] 1462 	lcall	__gptrget
      0004FD 8A 82            [24] 1463 	mov	dpl,r2
      0004FF 8B 83            [24] 1464 	mov	dph,r3
      000501 8E F0            [24] 1465 	mov	b,r6
      000503 C0 05            [24] 1466 	push	ar5
      000505 12 00 B7         [24] 1467 	lcall	_fuzzy_clamp
      000508 C8               [12] 1468 	xch	a,r0
      000509 E5 0E            [12] 1469 	mov	a,_bp
      00050B 24 0A            [12] 1470 	add	a,#0x0a
      00050D C8               [12] 1471 	xch	a,r0
      00050E A6 82            [24] 1472 	mov	@r0, dpl
      000510 08               [12] 1473 	inc	r0
      000511 A6 83            [24] 1474 	mov	@r0, dph
      000513 08               [12] 1475 	inc	r0
      000514 A6 F0            [24] 1476 	mov	@r0, b
      000516 08               [12] 1477 	inc	r0
      000517 F6               [12] 1478 	mov	@r0,a
      000518 D0 05            [24] 1479 	pop	ar5
                           000463  1480 	C$fuzzy.h$731$3_0$40 ==.
                                   1481 ;	../../fuzzy.h:731: index = 1u;
      00051A E5 0E            [12] 1482 	mov	a,_bp
      00051C 24 05            [12] 1483 	add	a,#0x05
      00051E F8               [12] 1484 	mov	r0,a
      00051F E4               [12] 1485 	clr	a
      000520 BD 00 01         [24] 1486 	cjne	r5,#0x00,00194$
      000523 04               [12] 1487 	inc	a
      000524                       1488 00194$:
      000524 F6               [12] 1489 	mov	@r0,a
      000525 BD 01 03         [24] 1490 	cjne	r5,#0x01,00196$
      000528 ED               [12] 1491 	mov	a,r5
      000529 80 01            [24] 1492 	sjmp	00197$
      00052B                       1493 00196$:
      00052B E4               [12] 1494 	clr	a
      00052C                       1495 00197$:
      00052C FA               [12] 1496 	mov	r2,a
      00052D E5 0E            [12] 1497 	mov	a,_bp
      00052F 24 04            [12] 1498 	add	a,#0x04
      000531 F8               [12] 1499 	mov	r0,a
      000532 E4               [12] 1500 	clr	a
      000533 BD 02 01         [24] 1501 	cjne	r5,#0x02,00198$
      000536 04               [12] 1502 	inc	a
      000537                       1503 00198$:
      000537 F6               [12] 1504 	mov	@r0,a
      000538 E5 0E            [12] 1505 	mov	a,_bp
      00053A 24 0E            [12] 1506 	add	a,#0x0e
      00053C F8               [12] 1507 	mov	r0,a
      00053D 76 01            [12] 1508 	mov	@r0,#0x01
      00053F 08               [12] 1509 	inc	r0
      000540 76 00            [12] 1510 	mov	@r0,#0x00
      000542                       1511 00119$:
                           00048B  1512 	C$fuzzy.h$732$2_0$39 ==.
                                   1513 ;	../../fuzzy.h:732: index < count;
      000542 E5 0E            [12] 1514 	mov	a,_bp
      000544 24 0E            [12] 1515 	add	a,#0x0e
      000546 F8               [12] 1516 	mov	r0,a
      000547 E5 0E            [12] 1517 	mov	a,_bp
      000549 24 FC            [12] 1518 	add	a,#0xfc
      00054B F9               [12] 1519 	mov	r1,a
      00054C C3               [12] 1520 	clr	c
      00054D E6               [12] 1521 	mov	a,@r0
      00054E 97               [12] 1522 	subb	a,@r1
      00054F 08               [12] 1523 	inc	r0
      000550 E6               [12] 1524 	mov	a,@r0
      000551 09               [12] 1525 	inc	r1
      000552 97               [12] 1526 	subb	a,@r1
      000553 40 03            [24] 1527 	jc	00200$
      000555 02 07 39         [24] 1528 	ljmp	00117$
      000558                       1529 00200$:
                           0004A1  1530 	C$fuzzy.h$737$1_0$36 ==.
                                   1531 ;	../../fuzzy.h:737: args[index]
      000558 C0 02            [24] 1532 	push	ar2
      00055A E5 0E            [12] 1533 	mov	a,_bp
      00055C 24 0E            [12] 1534 	add	a,#0x0e
      00055E F8               [12] 1535 	mov	r0,a
      00055F E6               [12] 1536 	mov	a,@r0
      000560 26               [12] 1537 	add	a,@r0
      000561 FD               [12] 1538 	mov	r5,a
      000562 08               [12] 1539 	inc	r0
      000563 E6               [12] 1540 	mov	a,@r0
      000564 33               [12] 1541 	rlc	a
      000565 FC               [12] 1542 	mov	r4,a
      000566 ED               [12] 1543 	mov	a,r5
      000567 2D               [12] 1544 	add	a,r5
      000568 FD               [12] 1545 	mov	r5,a
      000569 EC               [12] 1546 	mov	a,r4
      00056A 33               [12] 1547 	rlc	a
      00056B FC               [12] 1548 	mov	r4,a
      00056C A8 0E            [24] 1549 	mov	r0,_bp
      00056E 08               [12] 1550 	inc	r0
      00056F ED               [12] 1551 	mov	a,r5
      000570 26               [12] 1552 	add	a, @r0
      000571 FA               [12] 1553 	mov	r2,a
      000572 EC               [12] 1554 	mov	a,r4
      000573 08               [12] 1555 	inc	r0
      000574 36               [12] 1556 	addc	a, @r0
      000575 FC               [12] 1557 	mov	r4,a
      000576 08               [12] 1558 	inc	r0
      000577 86 05            [24] 1559 	mov	ar5,@r0
      000579 8A 82            [24] 1560 	mov	dpl,r2
      00057B 8C 83            [24] 1561 	mov	dph,r4
      00057D 8D F0            [24] 1562 	mov	b,r5
      00057F 12 26 33         [24] 1563 	lcall	__gptrget
      000582 FA               [12] 1564 	mov	r2,a
      000583 A3               [24] 1565 	inc	dptr
      000584 12 26 33         [24] 1566 	lcall	__gptrget
      000587 FC               [12] 1567 	mov	r4,a
      000588 A3               [24] 1568 	inc	dptr
      000589 12 26 33         [24] 1569 	lcall	__gptrget
      00058C FD               [12] 1570 	mov	r5,a
      00058D A3               [24] 1571 	inc	dptr
      00058E 12 26 33         [24] 1572 	lcall	__gptrget
      000591 8A 82            [24] 1573 	mov	dpl,r2
      000593 8C 83            [24] 1574 	mov	dph,r4
      000595 8D F0            [24] 1575 	mov	b,r5
      000597 C0 02            [24] 1576 	push	ar2
      000599 12 00 B7         [24] 1577 	lcall	_fuzzy_clamp
      00059C AC 82            [24] 1578 	mov	r4, dpl
      00059E AD 83            [24] 1579 	mov	r5, dph
      0005A0 AE F0            [24] 1580 	mov	r6, b
      0005A2 FB               [12] 1581 	mov	r3, a
      0005A3 D0 02            [24] 1582 	pop	ar2
                           0004EE  1583 	C$fuzzy.h$740$1_0$36 ==.
                                   1584 ;	../../fuzzy.h:740: switch (method) {
      0005A5 D0 02            [24] 1585 	pop	ar2
      0005A7 E5 0E            [12] 1586 	mov	a,_bp
      0005A9 24 05            [12] 1587 	add	a,#0x05
      0005AB F8               [12] 1588 	mov	r0,a
      0005AC E6               [12] 1589 	mov	a,@r0
      0005AD 70 11            [24] 1590 	jnz	00108$
      0005AF EA               [12] 1591 	mov	a,r2
      0005B0 70 5D            [24] 1592 	jnz	00111$
      0005B2 E5 0E            [12] 1593 	mov	a,_bp
      0005B4 24 04            [12] 1594 	add	a,#0x04
      0005B6 F8               [12] 1595 	mov	r0,a
      0005B7 E6               [12] 1596 	mov	a,@r0
      0005B8 60 03            [24] 1597 	jz	00203$
      0005BA 02 06 B4         [24] 1598 	ljmp	00112$
      0005BD                       1599 00203$:
      0005BD 02 07 23         [24] 1600 	ljmp	00115$
                           000509  1601 	C$fuzzy.h$741$4_0$41 ==.
                                   1602 ;	../../fuzzy.h:741: case FUZZY_LOGIC_STANDARD:
      0005C0                       1603 00108$:
                           000509  1604 	C$fuzzy.h$742$1_0$36 ==.
                                   1605 ;	../../fuzzy.h:742: if (next > result) {
      0005C0 C0 06            [24] 1606 	push	ar6
      0005C2 C0 05            [24] 1607 	push	ar5
      0005C4 C0 04            [24] 1608 	push	ar4
      0005C6 C0 03            [24] 1609 	push	ar3
      0005C8 C0 02            [24] 1610 	push	ar2
      0005CA C0 04            [24] 1611 	push	ar4
      0005CC C0 05            [24] 1612 	push	ar5
      0005CE C0 06            [24] 1613 	push	ar6
      0005D0 C0 03            [24] 1614 	push	ar3
      0005D2 E5 0E            [12] 1615 	mov	a,_bp
      0005D4 24 0A            [12] 1616 	add	a,#0x0a
      0005D6 F8               [12] 1617 	mov	r0,a
      0005D7 86 82            [24] 1618 	mov	dpl, @r0
      0005D9 08               [12] 1619 	inc	r0
      0005DA 86 83            [24] 1620 	mov	dph, @r0
      0005DC 08               [12] 1621 	inc	r0
      0005DD 86 F0            [24] 1622 	mov	b, @r0
      0005DF 08               [12] 1623 	inc	r0
      0005E0 E6               [12] 1624 	mov	a, @r0
      0005E1 12 24 07         [24] 1625 	lcall	___fslt
      0005E4 AF 82            [24] 1626 	mov	r7, dpl
      0005E6 E5 81            [12] 1627 	mov	a,sp
      0005E8 24 FC            [12] 1628 	add	a,#0xfc
      0005EA F5 81            [12] 1629 	mov	sp,a
      0005EC D0 02            [24] 1630 	pop	ar2
      0005EE D0 03            [24] 1631 	pop	ar3
      0005F0 D0 04            [24] 1632 	pop	ar4
      0005F2 D0 05            [24] 1633 	pop	ar5
      0005F4 D0 06            [24] 1634 	pop	ar6
      0005F6 EF               [12] 1635 	mov	a,r7
      0005F7 70 03            [24] 1636 	jnz	00204$
      0005F9 02 07 2B         [24] 1637 	ljmp	00120$
      0005FC                       1638 00204$:
                           000545  1639 	C$fuzzy.h$743$5_0$42 ==.
                                   1640 ;	../../fuzzy.h:743: result = next;
      0005FC E5 0E            [12] 1641 	mov	a,_bp
      0005FE 24 0A            [12] 1642 	add	a,#0x0a
      000600 F8               [12] 1643 	mov	r0,a
      000601 A6 04            [24] 1644 	mov	@r0,ar4
      000603 08               [12] 1645 	inc	r0
      000604 A6 05            [24] 1646 	mov	@r0,ar5
      000606 08               [12] 1647 	inc	r0
      000607 A6 06            [24] 1648 	mov	@r0,ar6
      000609 08               [12] 1649 	inc	r0
      00060A A6 03            [24] 1650 	mov	@r0,ar3
                           000555  1651 	C$fuzzy.h$745$4_0$41 ==.
                                   1652 ;	../../fuzzy.h:745: break;
      00060C 02 07 2B         [24] 1653 	ljmp	00120$
                           000558  1654 	C$fuzzy.h$747$4_0$41 ==.
                                   1655 ;	../../fuzzy.h:747: case FUZZY_LOGIC_ALGEBRAIC:
      00060F                       1656 00111$:
                           000558  1657 	C$fuzzy.h$750$1_0$36 ==.
                                   1658 ;	../../fuzzy.h:750: next -
      00060F C0 02            [24] 1659 	push	ar2
      000611 C0 06            [24] 1660 	push	ar6
      000613 C0 05            [24] 1661 	push	ar5
      000615 C0 04            [24] 1662 	push	ar4
      000617 C0 03            [24] 1663 	push	ar3
      000619 C0 02            [24] 1664 	push	ar2
      00061B C0 04            [24] 1665 	push	ar4
      00061D C0 05            [24] 1666 	push	ar5
      00061F C0 06            [24] 1667 	push	ar6
      000621 C0 03            [24] 1668 	push	ar3
                           00056C  1669 	C$fuzzy.h$751$1_0$36 ==.
                                   1670 ;	../../fuzzy.h:751: result * next;
      000623 E5 0E            [12] 1671 	mov	a,_bp
      000625 24 0A            [12] 1672 	add	a,#0x0a
      000627 F8               [12] 1673 	mov	r0,a
      000628 86 82            [24] 1674 	mov	dpl, @r0
      00062A 08               [12] 1675 	inc	r0
      00062B 86 83            [24] 1676 	mov	dph, @r0
      00062D 08               [12] 1677 	inc	r0
      00062E 86 F0            [24] 1678 	mov	b, @r0
      000630 08               [12] 1679 	inc	r0
      000631 E6               [12] 1680 	mov	a, @r0
      000632 12 24 59         [24] 1681 	lcall	___fsadd
      000635 C8               [12] 1682 	xch	a,r0
      000636 E5 0E            [12] 1683 	mov	a,_bp
      000638 24 06            [12] 1684 	add	a,#0x06
      00063A C8               [12] 1685 	xch	a,r0
      00063B A6 82            [24] 1686 	mov	@r0, dpl
      00063D 08               [12] 1687 	inc	r0
      00063E A6 83            [24] 1688 	mov	@r0, dph
      000640 08               [12] 1689 	inc	r0
      000641 A6 F0            [24] 1690 	mov	@r0, b
      000643 08               [12] 1691 	inc	r0
      000644 F6               [12] 1692 	mov	@r0,a
      000645 E5 81            [12] 1693 	mov	a,sp
      000647 24 FC            [12] 1694 	add	a,#0xfc
      000649 F5 81            [12] 1695 	mov	sp,a
      00064B D0 02            [24] 1696 	pop	ar2
      00064D D0 03            [24] 1697 	pop	ar3
      00064F D0 04            [24] 1698 	pop	ar4
      000651 D0 05            [24] 1699 	pop	ar5
      000653 D0 06            [24] 1700 	pop	ar6
      000655 C0 04            [24] 1701 	push	ar4
      000657 C0 05            [24] 1702 	push	ar5
      000659 C0 06            [24] 1703 	push	ar6
      00065B C0 03            [24] 1704 	push	ar3
      00065D E5 0E            [12] 1705 	mov	a,_bp
      00065F 24 0A            [12] 1706 	add	a,#0x0a
      000661 F8               [12] 1707 	mov	r0,a
      000662 86 82            [24] 1708 	mov	dpl, @r0
      000664 08               [12] 1709 	inc	r0
      000665 86 83            [24] 1710 	mov	dph, @r0
      000667 08               [12] 1711 	inc	r0
      000668 86 F0            [24] 1712 	mov	b, @r0
      00066A 08               [12] 1713 	inc	r0
      00066B E6               [12] 1714 	mov	a, @r0
      00066C 12 22 D7         [24] 1715 	lcall	___fsmul
      00066F AA 82            [24] 1716 	mov	r2, dpl
      000671 AB 83            [24] 1717 	mov	r3, dph
      000673 AE F0            [24] 1718 	mov	r6, b
      000675 FF               [12] 1719 	mov	r7, a
      000676 E5 81            [12] 1720 	mov	a,sp
      000678 24 FC            [12] 1721 	add	a,#0xfc
      00067A F5 81            [12] 1722 	mov	sp,a
      00067C C0 02            [24] 1723 	push	ar2
      00067E C0 02            [24] 1724 	push	ar2
      000680 C0 03            [24] 1725 	push	ar3
      000682 C0 06            [24] 1726 	push	ar6
      000684 C0 07            [24] 1727 	push	ar7
                           0005CF  1728 	C$fuzzy.h$752$1_0$36 ==.
                                   1729 ;	../../fuzzy.h:752: break;
      000686 E5 0E            [12] 1730 	mov	a,_bp
      000688 24 06            [12] 1731 	add	a,#0x06
      00068A F8               [12] 1732 	mov	r0,a
      00068B 86 82            [24] 1733 	mov	dpl, @r0
      00068D 08               [12] 1734 	inc	r0
      00068E 86 83            [24] 1735 	mov	dph, @r0
      000690 08               [12] 1736 	inc	r0
      000691 86 F0            [24] 1737 	mov	b, @r0
      000693 08               [12] 1738 	inc	r0
      000694 E6               [12] 1739 	mov	a, @r0
      000695 12 22 CC         [24] 1740 	lcall	___fssub
      000698 C8               [12] 1741 	xch	a,r0
      000699 E5 0E            [12] 1742 	mov	a,_bp
      00069B 24 0A            [12] 1743 	add	a,#0x0a
      00069D C8               [12] 1744 	xch	a,r0
      00069E A6 82            [24] 1745 	mov	@r0, dpl
      0006A0 08               [12] 1746 	inc	r0
      0006A1 A6 83            [24] 1747 	mov	@r0, dph
      0006A3 08               [12] 1748 	inc	r0
      0006A4 A6 F0            [24] 1749 	mov	@r0, b
      0006A6 08               [12] 1750 	inc	r0
      0006A7 F6               [12] 1751 	mov	@r0,a
      0006A8 E5 81            [12] 1752 	mov	a,sp
      0006AA 24 FC            [12] 1753 	add	a,#0xfc
      0006AC F5 81            [12] 1754 	mov	sp,a
      0006AE D0 02            [24] 1755 	pop	ar2
      0006B0 D0 02            [24] 1756 	pop	ar2
                           0005FB  1757 	C$fuzzy.h$754$4_0$41 ==.
                                   1758 ;	../../fuzzy.h:754: case FUZZY_LOGIC_BOUNDED:
      0006B2 80 77            [24] 1759 	sjmp	00120$
      0006B4                       1760 00112$:
                           0005FD  1761 	C$fuzzy.h$756$1_0$36 ==.
                                   1762 ;	../../fuzzy.h:756: next;
      0006B4 C0 02            [24] 1763 	push	ar2
      0006B6 C0 04            [24] 1764 	push	ar4
      0006B8 C0 05            [24] 1765 	push	ar5
      0006BA C0 06            [24] 1766 	push	ar6
      0006BC C0 03            [24] 1767 	push	ar3
                           000607  1768 	C$fuzzy.h$758$1_0$36 ==.
                                   1769 ;	../../fuzzy.h:758: if (result > LEVEL_HI) {
      0006BE E5 0E            [12] 1770 	mov	a,_bp
      0006C0 24 0A            [12] 1771 	add	a,#0x0a
      0006C2 F8               [12] 1772 	mov	r0,a
      0006C3 86 82            [24] 1773 	mov	dpl, @r0
      0006C5 08               [12] 1774 	inc	r0
      0006C6 86 83            [24] 1775 	mov	dph, @r0
      0006C8 08               [12] 1776 	inc	r0
      0006C9 86 F0            [24] 1777 	mov	b, @r0
      0006CB 08               [12] 1778 	inc	r0
      0006CC E6               [12] 1779 	mov	a, @r0
      0006CD 12 24 59         [24] 1780 	lcall	___fsadd
      0006D0 C8               [12] 1781 	xch	a,r0
      0006D1 E5 0E            [12] 1782 	mov	a,_bp
      0006D3 24 0A            [12] 1783 	add	a,#0x0a
      0006D5 C8               [12] 1784 	xch	a,r0
      0006D6 A6 82            [24] 1785 	mov	@r0, dpl
      0006D8 08               [12] 1786 	inc	r0
      0006D9 A6 83            [24] 1787 	mov	@r0, dph
      0006DB 08               [12] 1788 	inc	r0
      0006DC A6 F0            [24] 1789 	mov	@r0, b
      0006DE 08               [12] 1790 	inc	r0
      0006DF F6               [12] 1791 	mov	@r0,a
      0006E0 E5 81            [12] 1792 	mov	a,sp
      0006E2 24 FC            [12] 1793 	add	a,#0xfc
      0006E4 F5 81            [12] 1794 	mov	sp,a
      0006E6 E5 0E            [12] 1795 	mov	a,_bp
      0006E8 24 0A            [12] 1796 	add	a,#0x0a
      0006EA F8               [12] 1797 	mov	r0,a
      0006EB E6               [12] 1798 	mov	a,@r0
      0006EC C0 E0            [24] 1799 	push	acc
      0006EE 08               [12] 1800 	inc	r0
      0006EF E6               [12] 1801 	mov	a,@r0
      0006F0 C0 E0            [24] 1802 	push	acc
      0006F2 08               [12] 1803 	inc	r0
      0006F3 E6               [12] 1804 	mov	a,@r0
      0006F4 C0 E0            [24] 1805 	push	acc
      0006F6 08               [12] 1806 	inc	r0
      0006F7 E6               [12] 1807 	mov	a,@r0
      0006F8 C0 E0            [24] 1808 	push	acc
      0006FA 90 00 00         [24] 1809 	mov	dptr,#0x0000
      0006FD 75 F0 80         [24] 1810 	mov	b, #0x80
      000700 74 3F            [12] 1811 	mov	a, #0x3f
      000702 12 24 07         [24] 1812 	lcall	___fslt
      000705 AF 82            [24] 1813 	mov	r7, dpl
      000707 E5 81            [12] 1814 	mov	a,sp
      000709 24 FC            [12] 1815 	add	a,#0xfc
      00070B F5 81            [12] 1816 	mov	sp,a
      00070D D0 02            [24] 1817 	pop	ar2
      00070F EF               [12] 1818 	mov	a,r7
      000710 60 19            [24] 1819 	jz	00120$
                           00065B  1820 	C$fuzzy.h$759$5_0$43 ==.
                                   1821 ;	../../fuzzy.h:759: result = LEVEL_HI;
      000712 E5 0E            [12] 1822 	mov	a,_bp
      000714 24 0A            [12] 1823 	add	a,#0x0a
      000716 F8               [12] 1824 	mov	r0,a
      000717 E4               [12] 1825 	clr	a
      000718 F6               [12] 1826 	mov	@r0,a
      000719 08               [12] 1827 	inc	r0
      00071A F6               [12] 1828 	mov	@r0,a
      00071B 08               [12] 1829 	inc	r0
      00071C 76 80            [12] 1830 	mov	@r0,#0x80
      00071E 08               [12] 1831 	inc	r0
      00071F 76 3F            [12] 1832 	mov	@r0,#0x3f
                           00066A  1833 	C$fuzzy.h$761$4_0$41 ==.
                                   1834 ;	../../fuzzy.h:761: break;
                           00066A  1835 	C$fuzzy.h$763$4_0$41 ==.
                                   1836 ;	../../fuzzy.h:763: default:
      000721 80 08            [24] 1837 	sjmp	00120$
      000723                       1838 00115$:
                           00066C  1839 	C$fuzzy.h$764$4_0$41 ==.
                                   1840 ;	../../fuzzy.h:764: return LEVEL_LO;
      000723 90 00 00         [24] 1841 	mov	dptr,#0x0000
      000726 E4               [12] 1842 	clr	a
      000727 F5 F0            [12] 1843 	mov	b,a
                           000672  1844 	C$fuzzy.h$765$3_0$40 ==.
                                   1845 ;	../../fuzzy.h:765: }
      000729 80 20            [24] 1846 	sjmp	00121$
      00072B                       1847 00120$:
                           000674  1848 	C$fuzzy.h$733$2_0$39 ==.
                                   1849 ;	../../fuzzy.h:733: index++
      00072B E5 0E            [12] 1850 	mov	a,_bp
      00072D 24 0E            [12] 1851 	add	a,#0x0e
      00072F F8               [12] 1852 	mov	r0,a
      000730 06               [12] 1853 	inc	@r0
      000731 B6 00 02         [24] 1854 	cjne	@r0,#0x00,00206$
      000734 08               [12] 1855 	inc	r0
      000735 06               [12] 1856 	inc	@r0
      000736                       1857 00206$:
      000736 02 05 42         [24] 1858 	ljmp	00119$
      000739                       1859 00117$:
                           000682  1860 	C$fuzzy.h$769$1_0$36 ==.
                                   1861 ;	../../fuzzy.h:769: result
      000739 E5 0E            [12] 1862 	mov	a,_bp
      00073B 24 0A            [12] 1863 	add	a,#0x0a
      00073D F8               [12] 1864 	mov	r0,a
      00073E 86 82            [24] 1865 	mov	dpl, @r0
      000740 08               [12] 1866 	inc	r0
      000741 86 83            [24] 1867 	mov	dph, @r0
      000743 08               [12] 1868 	inc	r0
      000744 86 F0            [24] 1869 	mov	b, @r0
      000746 08               [12] 1870 	inc	r0
      000747 E6               [12] 1871 	mov	a, @r0
      000748 12 00 B7         [24] 1872 	lcall	_fuzzy_clamp
      00074B                       1873 00121$:
                           000694  1874 	C$fuzzy.h$771$1_0$36 ==.
                                   1875 ;	../../fuzzy.h:771: }
      00074B 85 0E 81         [24] 1876 	mov	sp,_bp
      00074E D0 0E            [24] 1877 	pop	_bp
                           000699  1878 	C$fuzzy.h$771$1_0$36 ==.
                           000699  1879 	XG$fuzzy_or_array$0$0 ==.
      000750 22               [24] 1880 	ret
                                   1881 ;------------------------------------------------------------
                                   1882 ;Allocation info for local variables in function 'fuzzy_sugeno_weighted_average_array'
                                   1883 ;------------------------------------------------------------
                                   1884 ;values        Allocated to stack - _bp -5 +3 
                                   1885 ;value_count   Allocated to stack - _bp +1 +2 
                                   1886 ;weighted_sum  Allocated to stack - _bp +3 +4 
                                   1887 ;firing_sum    Allocated to stack - _bp +7 +4 
                                   1888 ;firing_strength Allocated to stack - _bp +11 +4 
                                   1889 ;consequent    Allocated to registers r4 r5 r3 r2 
                                   1890 ;index         Allocated to registers r6 r7 
                                   1891 ;------------------------------------------------------------
                           00069A  1892 	G$fuzzy_sugeno_weighted_average_array$0$0 ==.
                           00069A  1893 	C$fuzzy.h$782$1_0$45 ==.
                                   1894 ;	../../fuzzy.h:782: float fuzzy_sugeno_weighted_average_array(
                                   1895 ;	-----------------------------------------
                                   1896 ;	 function fuzzy_sugeno_weighted_average_array
                                   1897 ;	-----------------------------------------
      000751                       1898 _fuzzy_sugeno_weighted_average_array:
      000751 C0 0E            [24] 1899 	push	_bp
      000753 85 81 0E         [24] 1900 	mov	_bp,sp
      000756 C0 82            [24] 1901 	push	dpl
      000758 C0 83            [24] 1902 	push	dph
      00075A E5 81            [12] 1903 	mov	a,sp
      00075C 24 0C            [12] 1904 	add	a,#0x0c
      00075E F5 81            [12] 1905 	mov	sp,a
                           0006A9  1906 	C$fuzzy.h$795$1_0$45 ==.
                                   1907 ;	../../fuzzy.h:795: values == NULL ||
      000760 E5 0E            [12] 1908 	mov	a,_bp
      000762 24 FB            [12] 1909 	add	a,#0xfb
      000764 F8               [12] 1910 	mov	r0,a
      000765 E6               [12] 1911 	mov	a,@r0
      000766 08               [12] 1912 	inc	r0
      000767 46               [12] 1913 	orl	a,@r0
      000768 60 0F            [24] 1914 	jz	00101$
                           0006B3  1915 	C$fuzzy.h$796$1_0$45 ==.
                                   1916 ;	../../fuzzy.h:796: value_count == 0u ||
      00076A A8 0E            [24] 1917 	mov	r0,_bp
      00076C 08               [12] 1918 	inc	r0
      00076D E6               [12] 1919 	mov	a,@r0
      00076E 08               [12] 1920 	inc	r0
      00076F 46               [12] 1921 	orl	a,@r0
      000770 60 07            [24] 1922 	jz	00101$
                           0006BB  1923 	C$fuzzy.h$797$1_0$45 ==.
                                   1924 ;	../../fuzzy.h:797: value_count % 2u != 0u
      000772 A8 0E            [24] 1925 	mov	r0,_bp
      000774 08               [12] 1926 	inc	r0
      000775 E6               [12] 1927 	mov	a,@r0
      000776 30 E0 09         [24] 1928 	jnb	acc.0,00102$
      000779                       1929 00101$:
                           0006C2  1930 	C$fuzzy.h$799$2_0$46 ==.
                                   1931 ;	../../fuzzy.h:799: return 0.0f;
      000779 90 00 00         [24] 1932 	mov	dptr,#0x0000
      00077C E4               [12] 1933 	clr	a
      00077D F5 F0            [12] 1934 	mov	b,a
      00077F 02 09 4C         [24] 1935 	ljmp	00111$
      000782                       1936 00102$:
                           0006CB  1937 	C$fuzzy.h$803$1_0$45 ==.
                                   1938 ;	../../fuzzy.h:803: 0.0f;
      000782 E5 0E            [12] 1939 	mov	a,_bp
      000784 24 03            [12] 1940 	add	a,#0x03
      000786 F8               [12] 1941 	mov	r0,a
      000787 E4               [12] 1942 	clr	a
      000788 F6               [12] 1943 	mov	@r0,a
      000789 08               [12] 1944 	inc	r0
      00078A F6               [12] 1945 	mov	@r0,a
      00078B 08               [12] 1946 	inc	r0
      00078C F6               [12] 1947 	mov	@r0,a
      00078D 08               [12] 1948 	inc	r0
      00078E F6               [12] 1949 	mov	@r0,a
                           0006D8  1950 	C$fuzzy.h$806$1_0$45 ==.
                                   1951 ;	../../fuzzy.h:806: 0.0f;
      00078F E5 0E            [12] 1952 	mov	a,_bp
      000791 24 07            [12] 1953 	add	a,#0x07
      000793 F8               [12] 1954 	mov	r0,a
      000794 E4               [12] 1955 	clr	a
      000795 F6               [12] 1956 	mov	@r0,a
      000796 08               [12] 1957 	inc	r0
      000797 F6               [12] 1958 	mov	@r0,a
      000798 08               [12] 1959 	inc	r0
      000799 F6               [12] 1960 	mov	@r0,a
      00079A 08               [12] 1961 	inc	r0
      00079B F6               [12] 1962 	mov	@r0,a
                           0006E5  1963 	C$fuzzy.h$809$1_0$45 ==.
                                   1964 ;	../../fuzzy.h:809: index = 0u;
      00079C FE               [12] 1965 	mov	r6,a
      00079D FF               [12] 1966 	mov	r7,a
      00079E                       1967 00109$:
                           0006E7  1968 	C$fuzzy.h$810$2_0$47 ==.
                                   1969 ;	../../fuzzy.h:810: index < value_count;
      00079E A8 0E            [24] 1970 	mov	r0,_bp
      0007A0 08               [12] 1971 	inc	r0
      0007A1 C3               [12] 1972 	clr	c
      0007A2 EE               [12] 1973 	mov	a,r6
      0007A3 96               [12] 1974 	subb	a,@r0
      0007A4 EF               [12] 1975 	mov	a,r7
      0007A5 08               [12] 1976 	inc	r0
      0007A6 96               [12] 1977 	subb	a,@r0
      0007A7 40 03            [24] 1978 	jc	00147$
      0007A9 02 08 DF         [24] 1979 	ljmp	00105$
      0007AC                       1980 00147$:
                           0006F5  1981 	C$fuzzy.h$815$3_0$48 ==.
                                   1982 ;	../../fuzzy.h:815: values[index]
      0007AC EE               [12] 1983 	mov	a,r6
      0007AD 2E               [12] 1984 	add	a,r6
      0007AE FC               [12] 1985 	mov	r4,a
      0007AF EF               [12] 1986 	mov	a,r7
      0007B0 33               [12] 1987 	rlc	a
      0007B1 FD               [12] 1988 	mov	r5,a
      0007B2 EC               [12] 1989 	mov	a,r4
      0007B3 2C               [12] 1990 	add	a,r4
      0007B4 FC               [12] 1991 	mov	r4,a
      0007B5 ED               [12] 1992 	mov	a,r5
      0007B6 33               [12] 1993 	rlc	a
      0007B7 FD               [12] 1994 	mov	r5,a
      0007B8 E5 0E            [12] 1995 	mov	a,_bp
      0007BA 24 FB            [12] 1996 	add	a,#0xfb
      0007BC F8               [12] 1997 	mov	r0,a
      0007BD EC               [12] 1998 	mov	a,r4
      0007BE 26               [12] 1999 	add	a, @r0
      0007BF FC               [12] 2000 	mov	r4,a
      0007C0 ED               [12] 2001 	mov	a,r5
      0007C1 08               [12] 2002 	inc	r0
      0007C2 36               [12] 2003 	addc	a, @r0
      0007C3 FD               [12] 2004 	mov	r5,a
      0007C4 08               [12] 2005 	inc	r0
      0007C5 86 03            [24] 2006 	mov	ar3,@r0
      0007C7 8C 82            [24] 2007 	mov	dpl,r4
      0007C9 8D 83            [24] 2008 	mov	dph,r5
      0007CB 8B F0            [24] 2009 	mov	b,r3
      0007CD 12 26 33         [24] 2010 	lcall	__gptrget
      0007D0 FC               [12] 2011 	mov	r4,a
      0007D1 A3               [24] 2012 	inc	dptr
      0007D2 12 26 33         [24] 2013 	lcall	__gptrget
      0007D5 FD               [12] 2014 	mov	r5,a
      0007D6 A3               [24] 2015 	inc	dptr
      0007D7 12 26 33         [24] 2016 	lcall	__gptrget
      0007DA FB               [12] 2017 	mov	r3,a
      0007DB A3               [24] 2018 	inc	dptr
      0007DC 12 26 33         [24] 2019 	lcall	__gptrget
      0007DF 8C 82            [24] 2020 	mov	dpl,r4
      0007E1 8D 83            [24] 2021 	mov	dph,r5
      0007E3 8B F0            [24] 2022 	mov	b,r3
      0007E5 C0 07            [24] 2023 	push	ar7
      0007E7 C0 06            [24] 2024 	push	ar6
      0007E9 12 00 B7         [24] 2025 	lcall	_fuzzy_clamp
      0007EC C8               [12] 2026 	xch	a,r0
      0007ED E5 0E            [12] 2027 	mov	a,_bp
      0007EF 24 0B            [12] 2028 	add	a,#0x0b
      0007F1 C8               [12] 2029 	xch	a,r0
      0007F2 A6 82            [24] 2030 	mov	@r0, dpl
      0007F4 08               [12] 2031 	inc	r0
      0007F5 A6 83            [24] 2032 	mov	@r0, dph
      0007F7 08               [12] 2033 	inc	r0
      0007F8 A6 F0            [24] 2034 	mov	@r0, b
      0007FA 08               [12] 2035 	inc	r0
      0007FB F6               [12] 2036 	mov	@r0,a
      0007FC D0 06            [24] 2037 	pop	ar6
      0007FE D0 07            [24] 2038 	pop	ar7
                           000749  2039 	C$fuzzy.h$819$3_0$48 ==.
                                   2040 ;	../../fuzzy.h:819: values[index + 1u];
      000800 74 01            [12] 2041 	mov	a,#0x01
      000802 2E               [12] 2042 	add	a, r6
      000803 FC               [12] 2043 	mov	r4,a
      000804 E4               [12] 2044 	clr	a
      000805 3F               [12] 2045 	addc	a, r7
      000806 FD               [12] 2046 	mov	r5,a
      000807 EC               [12] 2047 	mov	a,r4
      000808 2C               [12] 2048 	add	a,r4
      000809 FC               [12] 2049 	mov	r4,a
      00080A ED               [12] 2050 	mov	a,r5
      00080B 33               [12] 2051 	rlc	a
      00080C FD               [12] 2052 	mov	r5,a
      00080D EC               [12] 2053 	mov	a,r4
      00080E 2C               [12] 2054 	add	a,r4
      00080F FC               [12] 2055 	mov	r4,a
      000810 ED               [12] 2056 	mov	a,r5
      000811 33               [12] 2057 	rlc	a
      000812 FD               [12] 2058 	mov	r5,a
      000813 E5 0E            [12] 2059 	mov	a,_bp
      000815 24 FB            [12] 2060 	add	a,#0xfb
      000817 F8               [12] 2061 	mov	r0,a
      000818 EC               [12] 2062 	mov	a,r4
      000819 26               [12] 2063 	add	a, @r0
      00081A FC               [12] 2064 	mov	r4,a
      00081B ED               [12] 2065 	mov	a,r5
      00081C 08               [12] 2066 	inc	r0
      00081D 36               [12] 2067 	addc	a, @r0
      00081E FD               [12] 2068 	mov	r5,a
      00081F 08               [12] 2069 	inc	r0
      000820 86 03            [24] 2070 	mov	ar3,@r0
      000822 8C 82            [24] 2071 	mov	dpl,r4
      000824 8D 83            [24] 2072 	mov	dph,r5
      000826 8B F0            [24] 2073 	mov	b,r3
      000828 12 26 33         [24] 2074 	lcall	__gptrget
      00082B FC               [12] 2075 	mov	r4,a
      00082C A3               [24] 2076 	inc	dptr
      00082D 12 26 33         [24] 2077 	lcall	__gptrget
      000830 FD               [12] 2078 	mov	r5,a
      000831 A3               [24] 2079 	inc	dptr
      000832 12 26 33         [24] 2080 	lcall	__gptrget
      000835 FB               [12] 2081 	mov	r3,a
      000836 A3               [24] 2082 	inc	dptr
      000837 12 26 33         [24] 2083 	lcall	__gptrget
      00083A FA               [12] 2084 	mov	r2,a
                           000784  2085 	C$fuzzy.h$824$1_0$45 ==.
                                   2086 ;	../../fuzzy.h:824: consequent;
      00083B C0 07            [24] 2087 	push	ar7
      00083D C0 06            [24] 2088 	push	ar6
      00083F C0 04            [24] 2089 	push	ar4
      000841 C0 05            [24] 2090 	push	ar5
      000843 C0 03            [24] 2091 	push	ar3
      000845 C0 02            [24] 2092 	push	ar2
      000847 E5 0E            [12] 2093 	mov	a,_bp
      000849 24 0B            [12] 2094 	add	a,#0x0b
      00084B F8               [12] 2095 	mov	r0,a
      00084C 86 82            [24] 2096 	mov	dpl, @r0
      00084E 08               [12] 2097 	inc	r0
      00084F 86 83            [24] 2098 	mov	dph, @r0
      000851 08               [12] 2099 	inc	r0
      000852 86 F0            [24] 2100 	mov	b, @r0
      000854 08               [12] 2101 	inc	r0
      000855 E6               [12] 2102 	mov	a, @r0
      000856 12 22 D7         [24] 2103 	lcall	___fsmul
      000859 AA 82            [24] 2104 	mov	r2, dpl
      00085B AB 83            [24] 2105 	mov	r3, dph
      00085D AC F0            [24] 2106 	mov	r4, b
      00085F FD               [12] 2107 	mov	r5, a
      000860 E5 81            [12] 2108 	mov	a,sp
      000862 24 FC            [12] 2109 	add	a,#0xfc
      000864 F5 81            [12] 2110 	mov	sp,a
      000866 C0 02            [24] 2111 	push	ar2
      000868 C0 03            [24] 2112 	push	ar3
      00086A C0 04            [24] 2113 	push	ar4
      00086C C0 05            [24] 2114 	push	ar5
                           0007B7  2115 	C$fuzzy.h$827$1_0$45 ==.
                                   2116 ;	../../fuzzy.h:827: firing_strength;
      00086E E5 0E            [12] 2117 	mov	a,_bp
      000870 24 03            [12] 2118 	add	a,#0x03
      000872 F8               [12] 2119 	mov	r0,a
      000873 86 82            [24] 2120 	mov	dpl, @r0
      000875 08               [12] 2121 	inc	r0
      000876 86 83            [24] 2122 	mov	dph, @r0
      000878 08               [12] 2123 	inc	r0
      000879 86 F0            [24] 2124 	mov	b, @r0
      00087B 08               [12] 2125 	inc	r0
      00087C E6               [12] 2126 	mov	a, @r0
      00087D 12 24 59         [24] 2127 	lcall	___fsadd
      000880 A8 0E            [24] 2128 	mov	r0,_bp
      000882 08               [12] 2129 	inc	r0
      000883 08               [12] 2130 	inc	r0
      000884 08               [12] 2131 	inc	r0
      000885 A6 82            [24] 2132 	mov	@r0, dpl
      000887 08               [12] 2133 	inc	r0
      000888 A6 83            [24] 2134 	mov	@r0, dph
      00088A 08               [12] 2135 	inc	r0
      00088B A6 F0            [24] 2136 	mov	@r0, b
      00088D 08               [12] 2137 	inc	r0
      00088E F6               [12] 2138 	mov	@r0,a
      00088F E5 81            [12] 2139 	mov	a,sp
      000891 24 FC            [12] 2140 	add	a,#0xfc
      000893 F5 81            [12] 2141 	mov	sp,a
      000895 E5 0E            [12] 2142 	mov	a,_bp
      000897 24 0B            [12] 2143 	add	a,#0x0b
      000899 F8               [12] 2144 	mov	r0,a
      00089A E6               [12] 2145 	mov	a,@r0
      00089B C0 E0            [24] 2146 	push	acc
      00089D 08               [12] 2147 	inc	r0
      00089E E6               [12] 2148 	mov	a,@r0
      00089F C0 E0            [24] 2149 	push	acc
      0008A1 08               [12] 2150 	inc	r0
      0008A2 E6               [12] 2151 	mov	a,@r0
      0008A3 C0 E0            [24] 2152 	push	acc
      0008A5 08               [12] 2153 	inc	r0
      0008A6 E6               [12] 2154 	mov	a,@r0
      0008A7 C0 E0            [24] 2155 	push	acc
                           0007F2  2156 	C$fuzzy.h$812$1_0$45 ==.
                                   2157 ;	../../fuzzy.h:812: ) {
      0008A9 E5 0E            [12] 2158 	mov	a,_bp
      0008AB 24 07            [12] 2159 	add	a,#0x07
      0008AD F8               [12] 2160 	mov	r0,a
      0008AE 86 82            [24] 2161 	mov	dpl, @r0
      0008B0 08               [12] 2162 	inc	r0
      0008B1 86 83            [24] 2163 	mov	dph, @r0
      0008B3 08               [12] 2164 	inc	r0
      0008B4 86 F0            [24] 2165 	mov	b, @r0
      0008B6 08               [12] 2166 	inc	r0
      0008B7 E6               [12] 2167 	mov	a, @r0
      0008B8 12 24 59         [24] 2168 	lcall	___fsadd
      0008BB C8               [12] 2169 	xch	a,r0
      0008BC E5 0E            [12] 2170 	mov	a,_bp
      0008BE 24 07            [12] 2171 	add	a,#0x07
      0008C0 C8               [12] 2172 	xch	a,r0
      0008C1 A6 82            [24] 2173 	mov	@r0, dpl
      0008C3 08               [12] 2174 	inc	r0
      0008C4 A6 83            [24] 2175 	mov	@r0, dph
      0008C6 08               [12] 2176 	inc	r0
      0008C7 A6 F0            [24] 2177 	mov	@r0, b
      0008C9 08               [12] 2178 	inc	r0
      0008CA F6               [12] 2179 	mov	@r0,a
      0008CB E5 81            [12] 2180 	mov	a,sp
      0008CD 24 FC            [12] 2181 	add	a,#0xfc
      0008CF F5 81            [12] 2182 	mov	sp,a
      0008D1 D0 06            [24] 2183 	pop	ar6
      0008D3 D0 07            [24] 2184 	pop	ar7
      0008D5 74 02            [12] 2185 	mov	a,#0x02
      0008D7 2E               [12] 2186 	add	a, r6
      0008D8 FE               [12] 2187 	mov	r6,a
      0008D9 E4               [12] 2188 	clr	a
      0008DA 3F               [12] 2189 	addc	a, r7
      0008DB FF               [12] 2190 	mov	r7,a
      0008DC 02 07 9E         [24] 2191 	ljmp	00109$
      0008DF                       2192 00105$:
                           000828  2193 	C$fuzzy.h$830$1_0$45 ==.
                                   2194 ;	../../fuzzy.h:830: if (firing_sum <= LEVEL_LO) {
      0008DF E5 0E            [12] 2195 	mov	a,_bp
      0008E1 24 07            [12] 2196 	add	a,#0x07
      0008E3 F8               [12] 2197 	mov	r0,a
      0008E4 E6               [12] 2198 	mov	a,@r0
      0008E5 C0 E0            [24] 2199 	push	acc
      0008E7 08               [12] 2200 	inc	r0
      0008E8 E6               [12] 2201 	mov	a,@r0
      0008E9 C0 E0            [24] 2202 	push	acc
      0008EB 08               [12] 2203 	inc	r0
      0008EC E6               [12] 2204 	mov	a,@r0
      0008ED C0 E0            [24] 2205 	push	acc
      0008EF 08               [12] 2206 	inc	r0
      0008F0 E6               [12] 2207 	mov	a,@r0
      0008F1 C0 E0            [24] 2208 	push	acc
      0008F3 90 00 00         [24] 2209 	mov	dptr,#0x0000
      0008F6 E4               [12] 2210 	clr	a
      0008F7 F5 F0            [12] 2211 	mov	b,a
      0008F9 12 24 07         [24] 2212 	lcall	___fslt
      0008FC E5 81            [12] 2213 	mov	a,sp
      0008FE 24 FC            [12] 2214 	add	a,#0xfc
      000900 F5 81            [12] 2215 	mov	sp,a
      000902 E5 82            [12] 2216 	mov	a, dpl
      000904 24 FF            [12] 2217 	add	a,#0xff
      000906 92 00            [24] 2218 	mov	b0,c
      000908 40 08            [24] 2219 	jc	00107$
                           000853  2220 	C$fuzzy.h$831$2_0$49 ==.
                                   2221 ;	../../fuzzy.h:831: return 0.0f;
      00090A 90 00 00         [24] 2222 	mov	dptr,#0x0000
      00090D E4               [12] 2223 	clr	a
      00090E F5 F0            [12] 2224 	mov	b,a
      000910 80 3A            [24] 2225 	sjmp	00111$
      000912                       2226 00107$:
                           00085B  2227 	C$fuzzy.h$835$1_0$45 ==.
                                   2228 ;	../../fuzzy.h:835: firing_sum;
      000912 E5 0E            [12] 2229 	mov	a,_bp
      000914 24 07            [12] 2230 	add	a,#0x07
      000916 F8               [12] 2231 	mov	r0,a
      000917 E6               [12] 2232 	mov	a,@r0
      000918 C0 E0            [24] 2233 	push	acc
      00091A 08               [12] 2234 	inc	r0
      00091B E6               [12] 2235 	mov	a,@r0
      00091C C0 E0            [24] 2236 	push	acc
      00091E 08               [12] 2237 	inc	r0
      00091F E6               [12] 2238 	mov	a,@r0
      000920 C0 E0            [24] 2239 	push	acc
      000922 08               [12] 2240 	inc	r0
      000923 E6               [12] 2241 	mov	a,@r0
      000924 C0 E0            [24] 2242 	push	acc
      000926 E5 0E            [12] 2243 	mov	a,_bp
      000928 24 03            [12] 2244 	add	a,#0x03
      00092A F8               [12] 2245 	mov	r0,a
      00092B 86 82            [24] 2246 	mov	dpl, @r0
      00092D 08               [12] 2247 	inc	r0
      00092E 86 83            [24] 2248 	mov	dph, @r0
      000930 08               [12] 2249 	inc	r0
      000931 86 F0            [24] 2250 	mov	b, @r0
      000933 08               [12] 2251 	inc	r0
      000934 E6               [12] 2252 	mov	a, @r0
      000935 12 25 70         [24] 2253 	lcall	___fsdiv
      000938 AC 82            [24] 2254 	mov	r4, dpl
      00093A AD 83            [24] 2255 	mov	r5, dph
      00093C AE F0            [24] 2256 	mov	r6, b
      00093E FF               [12] 2257 	mov	r7, a
      00093F E5 81            [12] 2258 	mov	a,sp
      000941 24 FC            [12] 2259 	add	a,#0xfc
      000943 F5 81            [12] 2260 	mov	sp,a
      000945 8C 82            [24] 2261 	mov	dpl, r4
      000947 8D 83            [24] 2262 	mov	dph, r5
      000949 8E F0            [24] 2263 	mov	b, r6
      00094B EF               [12] 2264 	mov	a, r7
      00094C                       2265 00111$:
                           000895  2266 	C$fuzzy.h$836$1_0$45 ==.
                                   2267 ;	../../fuzzy.h:836: }
      00094C 85 0E 81         [24] 2268 	mov	sp,_bp
      00094F D0 0E            [24] 2269 	pop	_bp
                           00089A  2270 	C$fuzzy.h$836$1_0$45 ==.
                           00089A  2271 	XG$fuzzy_sugeno_weighted_average_array$0$0 ==.
      000951 22               [24] 2272 	ret
                                   2273 ;------------------------------------------------------------
                                   2274 ;Allocation info for local variables in function 'fuzzy_sugeno_weighted_sum_array'
                                   2275 ;------------------------------------------------------------
                                   2276 ;values        Allocated to stack - _bp -5 +3 
                                   2277 ;value_count   Allocated to registers r6 r7 
                                   2278 ;weighted_sum  Allocated to stack - _bp +1 +4 
                                   2279 ;firing_strength Allocated to stack - _bp +5 +4 
                                   2280 ;consequent    Allocated to registers r6 r7 r3 r2 
                                   2281 ;index         Allocated to registers r4 r5 
                                   2282 ;------------------------------------------------------------
                           00089B  2283 	G$fuzzy_sugeno_weighted_sum_array$0$0 ==.
                           00089B  2284 	C$fuzzy.h$846$1_0$51 ==.
                                   2285 ;	../../fuzzy.h:846: float fuzzy_sugeno_weighted_sum_array(
                                   2286 ;	-----------------------------------------
                                   2287 ;	 function fuzzy_sugeno_weighted_sum_array
                                   2288 ;	-----------------------------------------
      000952                       2289 _fuzzy_sugeno_weighted_sum_array:
      000952 C0 0E            [24] 2290 	push	_bp
      000954 E5 81            [12] 2291 	mov	a,sp
      000956 F5 0E            [12] 2292 	mov	_bp,a
      000958 24 08            [12] 2293 	add	a,#0x08
      00095A F5 81            [12] 2294 	mov	sp,a
      00095C AE 82            [24] 2295 	mov	r6, dpl
      00095E AF 83            [24] 2296 	mov	r7, dph
                           0008A9  2297 	C$fuzzy.h$858$1_0$51 ==.
                                   2298 ;	../../fuzzy.h:858: values == NULL ||
      000960 E5 0E            [12] 2299 	mov	a,_bp
      000962 24 FB            [12] 2300 	add	a,#0xfb
      000964 F8               [12] 2301 	mov	r0,a
      000965 E6               [12] 2302 	mov	a,@r0
      000966 08               [12] 2303 	inc	r0
      000967 46               [12] 2304 	orl	a,@r0
      000968 60 08            [24] 2305 	jz	00101$
                           0008B3  2306 	C$fuzzy.h$859$1_0$51 ==.
                                   2307 ;	../../fuzzy.h:859: value_count == 0u ||
      00096A EE               [12] 2308 	mov	a,r6
      00096B 4F               [12] 2309 	orl	a,r7
      00096C 60 04            [24] 2310 	jz	00101$
                           0008B7  2311 	C$fuzzy.h$860$1_0$51 ==.
                                   2312 ;	../../fuzzy.h:860: value_count % 2u != 0u
      00096E EE               [12] 2313 	mov	a,r6
      00096F 30 E0 09         [24] 2314 	jnb	acc.0,00102$
      000972                       2315 00101$:
                           0008BB  2316 	C$fuzzy.h$862$2_0$52 ==.
                                   2317 ;	../../fuzzy.h:862: return 0.0f;
      000972 90 00 00         [24] 2318 	mov	dptr,#0x0000
      000975 E4               [12] 2319 	clr	a
      000976 F5 F0            [12] 2320 	mov	b,a
      000978 02 0A B3         [24] 2321 	ljmp	00109$
      00097B                       2322 00102$:
                           0008C4  2323 	C$fuzzy.h$866$1_0$51 ==.
                                   2324 ;	../../fuzzy.h:866: 0.0f;
      00097B A8 0E            [24] 2325 	mov	r0,_bp
      00097D 08               [12] 2326 	inc	r0
      00097E E4               [12] 2327 	clr	a
      00097F F6               [12] 2328 	mov	@r0,a
      000980 08               [12] 2329 	inc	r0
      000981 F6               [12] 2330 	mov	@r0,a
      000982 08               [12] 2331 	inc	r0
      000983 F6               [12] 2332 	mov	@r0,a
      000984 08               [12] 2333 	inc	r0
      000985 F6               [12] 2334 	mov	@r0,a
                           0008CF  2335 	C$fuzzy.h$869$1_0$51 ==.
                                   2336 ;	../../fuzzy.h:869: index = 0u;
      000986 FC               [12] 2337 	mov	r4,a
      000987 FD               [12] 2338 	mov	r5,a
      000988                       2339 00107$:
                           0008D1  2340 	C$fuzzy.h$870$2_0$53 ==.
                                   2341 ;	../../fuzzy.h:870: index < value_count;
      000988 C3               [12] 2342 	clr	c
      000989 EC               [12] 2343 	mov	a,r4
      00098A 9E               [12] 2344 	subb	a,r6
      00098B ED               [12] 2345 	mov	a,r5
      00098C 9F               [12] 2346 	subb	a,r7
      00098D 40 03            [24] 2347 	jc	00139$
      00098F 02 0A A6         [24] 2348 	ljmp	00105$
      000992                       2349 00139$:
                           0008DB  2350 	C$fuzzy.h$875$1_0$51 ==.
                                   2351 ;	../../fuzzy.h:875: values[index]
      000992 C0 06            [24] 2352 	push	ar6
      000994 C0 07            [24] 2353 	push	ar7
      000996 EC               [12] 2354 	mov	a,r4
      000997 2C               [12] 2355 	add	a,r4
      000998 FA               [12] 2356 	mov	r2,a
      000999 ED               [12] 2357 	mov	a,r5
      00099A 33               [12] 2358 	rlc	a
      00099B FB               [12] 2359 	mov	r3,a
      00099C EA               [12] 2360 	mov	a,r2
      00099D 2A               [12] 2361 	add	a,r2
      00099E FA               [12] 2362 	mov	r2,a
      00099F EB               [12] 2363 	mov	a,r3
      0009A0 33               [12] 2364 	rlc	a
      0009A1 FB               [12] 2365 	mov	r3,a
      0009A2 E5 0E            [12] 2366 	mov	a,_bp
      0009A4 24 FB            [12] 2367 	add	a,#0xfb
      0009A6 F8               [12] 2368 	mov	r0,a
      0009A7 EA               [12] 2369 	mov	a,r2
      0009A8 26               [12] 2370 	add	a, @r0
      0009A9 FA               [12] 2371 	mov	r2,a
      0009AA EB               [12] 2372 	mov	a,r3
      0009AB 08               [12] 2373 	inc	r0
      0009AC 36               [12] 2374 	addc	a, @r0
      0009AD FB               [12] 2375 	mov	r3,a
      0009AE 08               [12] 2376 	inc	r0
      0009AF 86 07            [24] 2377 	mov	ar7,@r0
      0009B1 8A 82            [24] 2378 	mov	dpl,r2
      0009B3 8B 83            [24] 2379 	mov	dph,r3
      0009B5 8F F0            [24] 2380 	mov	b,r7
      0009B7 12 26 33         [24] 2381 	lcall	__gptrget
      0009BA FA               [12] 2382 	mov	r2,a
      0009BB A3               [24] 2383 	inc	dptr
      0009BC 12 26 33         [24] 2384 	lcall	__gptrget
      0009BF FB               [12] 2385 	mov	r3,a
      0009C0 A3               [24] 2386 	inc	dptr
      0009C1 12 26 33         [24] 2387 	lcall	__gptrget
      0009C4 FF               [12] 2388 	mov	r7,a
      0009C5 A3               [24] 2389 	inc	dptr
      0009C6 12 26 33         [24] 2390 	lcall	__gptrget
      0009C9 FE               [12] 2391 	mov	r6,a
      0009CA 8A 82            [24] 2392 	mov	dpl,r2
      0009CC 8B 83            [24] 2393 	mov	dph,r3
      0009CE 8F F0            [24] 2394 	mov	b,r7
      0009D0 C0 07            [24] 2395 	push	ar7
      0009D2 C0 06            [24] 2396 	push	ar6
      0009D4 C0 05            [24] 2397 	push	ar5
      0009D6 C0 04            [24] 2398 	push	ar4
      0009D8 12 00 B7         [24] 2399 	lcall	_fuzzy_clamp
      0009DB C8               [12] 2400 	xch	a,r0
      0009DC E5 0E            [12] 2401 	mov	a,_bp
      0009DE 24 05            [12] 2402 	add	a,#0x05
      0009E0 C8               [12] 2403 	xch	a,r0
      0009E1 A6 82            [24] 2404 	mov	@r0, dpl
      0009E3 08               [12] 2405 	inc	r0
      0009E4 A6 83            [24] 2406 	mov	@r0, dph
      0009E6 08               [12] 2407 	inc	r0
      0009E7 A6 F0            [24] 2408 	mov	@r0, b
      0009E9 08               [12] 2409 	inc	r0
      0009EA F6               [12] 2410 	mov	@r0,a
      0009EB D0 04            [24] 2411 	pop	ar4
      0009ED D0 05            [24] 2412 	pop	ar5
      0009EF D0 06            [24] 2413 	pop	ar6
      0009F1 D0 07            [24] 2414 	pop	ar7
                           00093C  2415 	C$fuzzy.h$879$3_0$54 ==.
                                   2416 ;	../../fuzzy.h:879: values[index + 1u];
      0009F3 74 01            [12] 2417 	mov	a,#0x01
      0009F5 2C               [12] 2418 	add	a, r4
      0009F6 FE               [12] 2419 	mov	r6,a
      0009F7 E4               [12] 2420 	clr	a
      0009F8 3D               [12] 2421 	addc	a, r5
      0009F9 FF               [12] 2422 	mov	r7,a
      0009FA EE               [12] 2423 	mov	a,r6
      0009FB 2E               [12] 2424 	add	a,r6
      0009FC FE               [12] 2425 	mov	r6,a
      0009FD EF               [12] 2426 	mov	a,r7
      0009FE 33               [12] 2427 	rlc	a
      0009FF FF               [12] 2428 	mov	r7,a
      000A00 EE               [12] 2429 	mov	a,r6
      000A01 2E               [12] 2430 	add	a,r6
      000A02 FE               [12] 2431 	mov	r6,a
      000A03 EF               [12] 2432 	mov	a,r7
      000A04 33               [12] 2433 	rlc	a
      000A05 FF               [12] 2434 	mov	r7,a
      000A06 E5 0E            [12] 2435 	mov	a,_bp
      000A08 24 FB            [12] 2436 	add	a,#0xfb
      000A0A F8               [12] 2437 	mov	r0,a
      000A0B EE               [12] 2438 	mov	a,r6
      000A0C 26               [12] 2439 	add	a, @r0
      000A0D FE               [12] 2440 	mov	r6,a
      000A0E EF               [12] 2441 	mov	a,r7
      000A0F 08               [12] 2442 	inc	r0
      000A10 36               [12] 2443 	addc	a, @r0
      000A11 FF               [12] 2444 	mov	r7,a
      000A12 08               [12] 2445 	inc	r0
      000A13 86 03            [24] 2446 	mov	ar3,@r0
      000A15 8E 82            [24] 2447 	mov	dpl,r6
      000A17 8F 83            [24] 2448 	mov	dph,r7
      000A19 8B F0            [24] 2449 	mov	b,r3
      000A1B 12 26 33         [24] 2450 	lcall	__gptrget
      000A1E FE               [12] 2451 	mov	r6,a
      000A1F A3               [24] 2452 	inc	dptr
      000A20 12 26 33         [24] 2453 	lcall	__gptrget
      000A23 FF               [12] 2454 	mov	r7,a
      000A24 A3               [24] 2455 	inc	dptr
      000A25 12 26 33         [24] 2456 	lcall	__gptrget
      000A28 FB               [12] 2457 	mov	r3,a
      000A29 A3               [24] 2458 	inc	dptr
      000A2A 12 26 33         [24] 2459 	lcall	__gptrget
      000A2D FA               [12] 2460 	mov	r2,a
                           000977  2461 	C$fuzzy.h$884$1_0$51 ==.
                                   2462 ;	../../fuzzy.h:884: consequent;
      000A2E C0 05            [24] 2463 	push	ar5
      000A30 C0 04            [24] 2464 	push	ar4
      000A32 C0 06            [24] 2465 	push	ar6
      000A34 C0 07            [24] 2466 	push	ar7
      000A36 C0 03            [24] 2467 	push	ar3
      000A38 C0 02            [24] 2468 	push	ar2
      000A3A E5 0E            [12] 2469 	mov	a,_bp
      000A3C 24 05            [12] 2470 	add	a,#0x05
      000A3E F8               [12] 2471 	mov	r0,a
      000A3F 86 82            [24] 2472 	mov	dpl, @r0
      000A41 08               [12] 2473 	inc	r0
      000A42 86 83            [24] 2474 	mov	dph, @r0
      000A44 08               [12] 2475 	inc	r0
      000A45 86 F0            [24] 2476 	mov	b, @r0
      000A47 08               [12] 2477 	inc	r0
      000A48 E6               [12] 2478 	mov	a, @r0
      000A49 12 22 D7         [24] 2479 	lcall	___fsmul
      000A4C AA 82            [24] 2480 	mov	r2, dpl
      000A4E AB 83            [24] 2481 	mov	r3, dph
      000A50 AE F0            [24] 2482 	mov	r6, b
      000A52 FF               [12] 2483 	mov	r7, a
      000A53 E5 81            [12] 2484 	mov	a,sp
      000A55 24 FC            [12] 2485 	add	a,#0xfc
      000A57 F5 81            [12] 2486 	mov	sp,a
      000A59 D0 04            [24] 2487 	pop	ar4
      000A5B D0 05            [24] 2488 	pop	ar5
      000A5D C0 07            [24] 2489 	push	ar7
      000A5F C0 06            [24] 2490 	push	ar6
      000A61 C0 05            [24] 2491 	push	ar5
      000A63 C0 04            [24] 2492 	push	ar4
      000A65 C0 02            [24] 2493 	push	ar2
      000A67 C0 03            [24] 2494 	push	ar3
      000A69 C0 06            [24] 2495 	push	ar6
      000A6B C0 07            [24] 2496 	push	ar7
                           0009B6  2497 	C$fuzzy.h$872$1_0$51 ==.
                                   2498 ;	../../fuzzy.h:872: ) {
      000A6D A8 0E            [24] 2499 	mov	r0,_bp
      000A6F 08               [12] 2500 	inc	r0
      000A70 86 82            [24] 2501 	mov	dpl, @r0
      000A72 08               [12] 2502 	inc	r0
      000A73 86 83            [24] 2503 	mov	dph, @r0
      000A75 08               [12] 2504 	inc	r0
      000A76 86 F0            [24] 2505 	mov	b, @r0
      000A78 08               [12] 2506 	inc	r0
      000A79 E6               [12] 2507 	mov	a, @r0
      000A7A 12 24 59         [24] 2508 	lcall	___fsadd
      000A7D A8 0E            [24] 2509 	mov	r0,_bp
      000A7F 08               [12] 2510 	inc	r0
      000A80 A6 82            [24] 2511 	mov	@r0, dpl
      000A82 08               [12] 2512 	inc	r0
      000A83 A6 83            [24] 2513 	mov	@r0, dph
      000A85 08               [12] 2514 	inc	r0
      000A86 A6 F0            [24] 2515 	mov	@r0, b
      000A88 08               [12] 2516 	inc	r0
      000A89 F6               [12] 2517 	mov	@r0,a
      000A8A E5 81            [12] 2518 	mov	a,sp
      000A8C 24 FC            [12] 2519 	add	a,#0xfc
      000A8E F5 81            [12] 2520 	mov	sp,a
      000A90 D0 04            [24] 2521 	pop	ar4
      000A92 D0 05            [24] 2522 	pop	ar5
      000A94 D0 06            [24] 2523 	pop	ar6
      000A96 D0 07            [24] 2524 	pop	ar7
      000A98 74 02            [12] 2525 	mov	a,#0x02
      000A9A 2C               [12] 2526 	add	a, r4
      000A9B FC               [12] 2527 	mov	r4,a
      000A9C E4               [12] 2528 	clr	a
      000A9D 3D               [12] 2529 	addc	a, r5
      000A9E FD               [12] 2530 	mov	r5,a
      000A9F D0 07            [24] 2531 	pop	ar7
      000AA1 D0 06            [24] 2532 	pop	ar6
      000AA3 02 09 88         [24] 2533 	ljmp	00107$
      000AA6                       2534 00105$:
                           0009EF  2535 	C$fuzzy.h$887$1_0$51 ==.
                                   2536 ;	../../fuzzy.h:887: return weighted_sum;
      000AA6 A8 0E            [24] 2537 	mov	r0,_bp
      000AA8 08               [12] 2538 	inc	r0
      000AA9 86 82            [24] 2539 	mov	dpl, @r0
      000AAB 08               [12] 2540 	inc	r0
      000AAC 86 83            [24] 2541 	mov	dph, @r0
      000AAE 08               [12] 2542 	inc	r0
      000AAF 86 F0            [24] 2543 	mov	b, @r0
      000AB1 08               [12] 2544 	inc	r0
      000AB2 E6               [12] 2545 	mov	a, @r0
      000AB3                       2546 00109$:
                           0009FC  2547 	C$fuzzy.h$888$1_0$51 ==.
                                   2548 ;	../../fuzzy.h:888: }
      000AB3 85 0E 81         [24] 2549 	mov	sp,_bp
      000AB6 D0 0E            [24] 2550 	pop	_bp
                           000A01  2551 	C$fuzzy.h$888$1_0$51 ==.
                           000A01  2552 	XG$fuzzy_sugeno_weighted_sum_array$0$0 ==.
      000AB8 22               [24] 2553 	ret
                                   2554 ;------------------------------------------------------------
                                   2555 ;Allocation info for local variables in function 'fuzzy_ramp'
                                   2556 ;------------------------------------------------------------
                                   2557 ;upper_boundary Allocated to stack - _bp -6 +4 
                                   2558 ;value         Allocated to stack - _bp -10 +4 
                                   2559 ;ramp_up       Allocated to stack - _bp -11 +1 
                                   2560 ;hedge         Allocated to stack - _bp -12 +1 
                                   2561 ;lower_boundary Allocated to registers r7 r6 r5 r4 
                                   2562 ;result        Allocated to stack - _bp +5 +4 
                                   2563 ;normalized    Allocated to registers r4 r5 r6 r7 
                                   2564 ;sloc0         Allocated to stack - _bp +13 +4 
                                   2565 ;sloc1         Allocated to stack - _bp +1 +4 
                                   2566 ;------------------------------------------------------------
                           000A02  2567 	G$fuzzy_ramp$0$0 ==.
                           000A02  2568 	C$fuzzy.h$894$1_0$56 ==.
                                   2569 ;	../../fuzzy.h:894: float fuzzy_ramp(
                                   2570 ;	-----------------------------------------
                                   2571 ;	 function fuzzy_ramp
                                   2572 ;	-----------------------------------------
      000AB9                       2573 _fuzzy_ramp:
      000AB9 C0 0E            [24] 2574 	push	_bp
      000ABB 85 81 0E         [24] 2575 	mov	_bp,sp
      000ABE AF 82            [24] 2576 	mov	r7,dpl
      000AC0 AE 83            [24] 2577 	mov	r6,dph
      000AC2 AD F0            [24] 2578 	mov	r5,b
      000AC4 FC               [12] 2579 	mov	r4,a
      000AC5 E5 81            [12] 2580 	mov	a,sp
      000AC7 24 08            [12] 2581 	add	a,#0x08
      000AC9 F5 81            [12] 2582 	mov	sp,a
                           000A14  2583 	C$fuzzy.h$905$1_0$56 ==.
                                   2584 ;	../../fuzzy.h:905: if (lower_boundary >= upper_boundary) {
      000ACB C0 07            [24] 2585 	push	ar7
      000ACD C0 06            [24] 2586 	push	ar6
      000ACF C0 05            [24] 2587 	push	ar5
      000AD1 C0 04            [24] 2588 	push	ar4
      000AD3 E5 0E            [12] 2589 	mov	a,_bp
      000AD5 24 FA            [12] 2590 	add	a,#0xfa
      000AD7 F8               [12] 2591 	mov	r0,a
      000AD8 E6               [12] 2592 	mov	a,@r0
      000AD9 C0 E0            [24] 2593 	push	acc
      000ADB 08               [12] 2594 	inc	r0
      000ADC E6               [12] 2595 	mov	a,@r0
      000ADD C0 E0            [24] 2596 	push	acc
      000ADF 08               [12] 2597 	inc	r0
      000AE0 E6               [12] 2598 	mov	a,@r0
      000AE1 C0 E0            [24] 2599 	push	acc
      000AE3 08               [12] 2600 	inc	r0
      000AE4 E6               [12] 2601 	mov	a,@r0
      000AE5 C0 E0            [24] 2602 	push	acc
      000AE7 8F 82            [24] 2603 	mov	dpl, r7
      000AE9 8E 83            [24] 2604 	mov	dph, r6
      000AEB 8D F0            [24] 2605 	mov	b, r5
      000AED EC               [12] 2606 	mov	a, r4
      000AEE 12 24 07         [24] 2607 	lcall	___fslt
      000AF1 E5 81            [12] 2608 	mov	a,sp
      000AF3 24 FC            [12] 2609 	add	a,#0xfc
      000AF5 F5 81            [12] 2610 	mov	sp,a
      000AF7 D0 04            [24] 2611 	pop	ar4
      000AF9 D0 05            [24] 2612 	pop	ar5
      000AFB D0 06            [24] 2613 	pop	ar6
      000AFD D0 07            [24] 2614 	pop	ar7
      000AFF E5 82            [12] 2615 	mov	a, dpl
      000B01 24 FF            [12] 2616 	add	a,#0xff
      000B03 92 00            [24] 2617 	mov	b0,c
      000B05 40 09            [24] 2618 	jc	00102$
                           000A50  2619 	C$fuzzy.h$906$2_0$57 ==.
                                   2620 ;	../../fuzzy.h:906: return LEVEL_LO;
      000B07 90 00 00         [24] 2621 	mov	dptr,#0x0000
      000B0A E4               [12] 2622 	clr	a
      000B0B F5 F0            [12] 2623 	mov	b,a
      000B0D 02 0C F0         [24] 2624 	ljmp	00109$
      000B10                       2625 00102$:
                           000A59  2626 	C$fuzzy.h$909$1_0$56 ==.
                                   2627 ;	../../fuzzy.h:909: if (value <= lower_boundary) {
      000B10 C0 07            [24] 2628 	push	ar7
      000B12 C0 06            [24] 2629 	push	ar6
      000B14 C0 05            [24] 2630 	push	ar5
      000B16 C0 04            [24] 2631 	push	ar4
      000B18 E5 0E            [12] 2632 	mov	a,_bp
      000B1A 24 F6            [12] 2633 	add	a,#0xf6
      000B1C F8               [12] 2634 	mov	r0,a
      000B1D E6               [12] 2635 	mov	a,@r0
      000B1E C0 E0            [24] 2636 	push	acc
      000B20 08               [12] 2637 	inc	r0
      000B21 E6               [12] 2638 	mov	a,@r0
      000B22 C0 E0            [24] 2639 	push	acc
      000B24 08               [12] 2640 	inc	r0
      000B25 E6               [12] 2641 	mov	a,@r0
      000B26 C0 E0            [24] 2642 	push	acc
      000B28 08               [12] 2643 	inc	r0
      000B29 E6               [12] 2644 	mov	a,@r0
      000B2A C0 E0            [24] 2645 	push	acc
      000B2C 8F 82            [24] 2646 	mov	dpl, r7
      000B2E 8E 83            [24] 2647 	mov	dph, r6
      000B30 8D F0            [24] 2648 	mov	b, r5
      000B32 EC               [12] 2649 	mov	a, r4
      000B33 12 24 07         [24] 2650 	lcall	___fslt
      000B36 E5 81            [12] 2651 	mov	a,sp
      000B38 24 FC            [12] 2652 	add	a,#0xfc
      000B3A F5 81            [12] 2653 	mov	sp,a
      000B3C D0 04            [24] 2654 	pop	ar4
      000B3E D0 05            [24] 2655 	pop	ar5
      000B40 D0 06            [24] 2656 	pop	ar6
      000B42 D0 07            [24] 2657 	pop	ar7
      000B44 E5 82            [12] 2658 	mov	a, dpl
      000B46 24 FF            [12] 2659 	add	a,#0xff
      000B48 92 00            [24] 2660 	mov	b0,c
      000B4A 40 39            [24] 2661 	jc	00107$
                           000A95  2662 	C$fuzzy.h$911$2_0$58 ==.
                                   2663 ;	../../fuzzy.h:911: ramp_up
      000B4C E5 0E            [12] 2664 	mov	a,_bp
      000B4E 24 F5            [12] 2665 	add	a,#0xf5
      000B50 F8               [12] 2666 	mov	r0,a
      000B51 E6               [12] 2667 	mov	a,@r0
      000B52 60 0F            [24] 2668 	jz	00111$
                           000A9D  2669 	C$fuzzy.h$912$2_0$58 ==.
                                   2670 ;	../../fuzzy.h:912: ? LEVEL_LO
      000B54 E5 0E            [12] 2671 	mov	a,_bp
      000B56 24 05            [12] 2672 	add	a,#0x05
      000B58 F8               [12] 2673 	mov	r0,a
      000B59 E4               [12] 2674 	clr	a
      000B5A F6               [12] 2675 	mov	@r0,a
      000B5B 08               [12] 2676 	inc	r0
      000B5C F6               [12] 2677 	mov	@r0,a
      000B5D 08               [12] 2678 	inc	r0
      000B5E F6               [12] 2679 	mov	@r0,a
      000B5F 08               [12] 2680 	inc	r0
      000B60 F6               [12] 2681 	mov	@r0,a
      000B61 80 0F            [24] 2682 	sjmp	00112$
      000B63                       2683 00111$:
                           000AAC  2684 	C$fuzzy.h$913$2_0$58 ==.
                                   2685 ;	../../fuzzy.h:913: : LEVEL_HI;
      000B63 E5 0E            [12] 2686 	mov	a,_bp
      000B65 24 05            [12] 2687 	add	a,#0x05
      000B67 F8               [12] 2688 	mov	r0,a
      000B68 E4               [12] 2689 	clr	a
      000B69 F6               [12] 2690 	mov	@r0,a
      000B6A 08               [12] 2691 	inc	r0
      000B6B F6               [12] 2692 	mov	@r0,a
      000B6C 08               [12] 2693 	inc	r0
      000B6D 76 80            [12] 2694 	mov	@r0,#0x80
      000B6F 08               [12] 2695 	inc	r0
      000B70 76 3F            [12] 2696 	mov	@r0,#0x3f
      000B72                       2697 00112$:
      000B72 E5 0E            [12] 2698 	mov	a,_bp
      000B74 24 05            [12] 2699 	add	a,#0x05
      000B76 F8               [12] 2700 	mov	r0,a
      000B77 86 07            [24] 2701 	mov	ar7,@r0
      000B79 08               [12] 2702 	inc	r0
      000B7A 86 06            [24] 2703 	mov	ar6,@r0
      000B7C 08               [12] 2704 	inc	r0
      000B7D 86 05            [24] 2705 	mov	ar5,@r0
      000B7F 08               [12] 2706 	inc	r0
      000B80 86 04            [24] 2707 	mov	ar4,@r0
      000B82 02 0C CE         [24] 2708 	ljmp	00108$
      000B85                       2709 00107$:
                           000ACE  2710 	C$fuzzy.h$915$1_0$56 ==.
                                   2711 ;	../../fuzzy.h:915: else if (value >= upper_boundary) {
      000B85 C0 07            [24] 2712 	push	ar7
      000B87 C0 06            [24] 2713 	push	ar6
      000B89 C0 05            [24] 2714 	push	ar5
      000B8B C0 04            [24] 2715 	push	ar4
      000B8D E5 0E            [12] 2716 	mov	a,_bp
      000B8F 24 FA            [12] 2717 	add	a,#0xfa
      000B91 F8               [12] 2718 	mov	r0,a
      000B92 E6               [12] 2719 	mov	a,@r0
      000B93 C0 E0            [24] 2720 	push	acc
      000B95 08               [12] 2721 	inc	r0
      000B96 E6               [12] 2722 	mov	a,@r0
      000B97 C0 E0            [24] 2723 	push	acc
      000B99 08               [12] 2724 	inc	r0
      000B9A E6               [12] 2725 	mov	a,@r0
      000B9B C0 E0            [24] 2726 	push	acc
      000B9D 08               [12] 2727 	inc	r0
      000B9E E6               [12] 2728 	mov	a,@r0
      000B9F C0 E0            [24] 2729 	push	acc
      000BA1 E5 0E            [12] 2730 	mov	a,_bp
      000BA3 24 F6            [12] 2731 	add	a,#0xf6
      000BA5 F8               [12] 2732 	mov	r0,a
      000BA6 86 82            [24] 2733 	mov	dpl, @r0
      000BA8 08               [12] 2734 	inc	r0
      000BA9 86 83            [24] 2735 	mov	dph, @r0
      000BAB 08               [12] 2736 	inc	r0
      000BAC 86 F0            [24] 2737 	mov	b, @r0
      000BAE 08               [12] 2738 	inc	r0
      000BAF E6               [12] 2739 	mov	a, @r0
      000BB0 12 24 07         [24] 2740 	lcall	___fslt
      000BB3 E5 81            [12] 2741 	mov	a,sp
      000BB5 24 FC            [12] 2742 	add	a,#0xfc
      000BB7 F5 81            [12] 2743 	mov	sp,a
      000BB9 D0 04            [24] 2744 	pop	ar4
      000BBB D0 05            [24] 2745 	pop	ar5
      000BBD D0 06            [24] 2746 	pop	ar6
      000BBF D0 07            [24] 2747 	pop	ar7
      000BC1 E5 82            [12] 2748 	mov	a, dpl
      000BC3 24 FF            [12] 2749 	add	a,#0xff
      000BC5 92 00            [24] 2750 	mov	b0,c
      000BC7 40 39            [24] 2751 	jc	00104$
                           000B12  2752 	C$fuzzy.h$917$2_0$59 ==.
                                   2753 ;	../../fuzzy.h:917: ramp_up
      000BC9 E5 0E            [12] 2754 	mov	a,_bp
      000BCB 24 F5            [12] 2755 	add	a,#0xf5
      000BCD F8               [12] 2756 	mov	r0,a
      000BCE E6               [12] 2757 	mov	a,@r0
      000BCF 60 11            [24] 2758 	jz	00113$
                           000B1A  2759 	C$fuzzy.h$918$2_0$59 ==.
                                   2760 ;	../../fuzzy.h:918: ? LEVEL_HI
      000BD1 E5 0E            [12] 2761 	mov	a,_bp
      000BD3 24 05            [12] 2762 	add	a,#0x05
      000BD5 F8               [12] 2763 	mov	r0,a
      000BD6 E4               [12] 2764 	clr	a
      000BD7 F6               [12] 2765 	mov	@r0,a
      000BD8 08               [12] 2766 	inc	r0
      000BD9 F6               [12] 2767 	mov	@r0,a
      000BDA 08               [12] 2768 	inc	r0
      000BDB 76 80            [12] 2769 	mov	@r0,#0x80
      000BDD 08               [12] 2770 	inc	r0
      000BDE 76 3F            [12] 2771 	mov	@r0,#0x3f
      000BE0 80 0D            [24] 2772 	sjmp	00114$
      000BE2                       2773 00113$:
                           000B2B  2774 	C$fuzzy.h$919$2_0$59 ==.
                                   2775 ;	../../fuzzy.h:919: : LEVEL_LO;
      000BE2 E5 0E            [12] 2776 	mov	a,_bp
      000BE4 24 05            [12] 2777 	add	a,#0x05
      000BE6 F8               [12] 2778 	mov	r0,a
      000BE7 E4               [12] 2779 	clr	a
      000BE8 F6               [12] 2780 	mov	@r0,a
      000BE9 08               [12] 2781 	inc	r0
      000BEA F6               [12] 2782 	mov	@r0,a
      000BEB 08               [12] 2783 	inc	r0
      000BEC F6               [12] 2784 	mov	@r0,a
      000BED 08               [12] 2785 	inc	r0
      000BEE F6               [12] 2786 	mov	@r0,a
      000BEF                       2787 00114$:
      000BEF E5 0E            [12] 2788 	mov	a,_bp
      000BF1 24 05            [12] 2789 	add	a,#0x05
      000BF3 F8               [12] 2790 	mov	r0,a
      000BF4 86 07            [24] 2791 	mov	ar7,@r0
      000BF6 08               [12] 2792 	inc	r0
      000BF7 86 06            [24] 2793 	mov	ar6,@r0
      000BF9 08               [12] 2794 	inc	r0
      000BFA 86 05            [24] 2795 	mov	ar5,@r0
      000BFC 08               [12] 2796 	inc	r0
      000BFD 86 04            [24] 2797 	mov	ar4,@r0
      000BFF 02 0C CE         [24] 2798 	ljmp	00108$
      000C02                       2799 00104$:
                           000B4B  2800 	C$fuzzy.h$923$1_0$56 ==.
                                   2801 ;	../../fuzzy.h:923: (value - lower_boundary) /
      000C02 C0 07            [24] 2802 	push	ar7
      000C04 C0 06            [24] 2803 	push	ar6
      000C06 C0 05            [24] 2804 	push	ar5
      000C08 C0 04            [24] 2805 	push	ar4
      000C0A C0 07            [24] 2806 	push	ar7
      000C0C C0 06            [24] 2807 	push	ar6
      000C0E C0 05            [24] 2808 	push	ar5
      000C10 C0 04            [24] 2809 	push	ar4
                           000B5B  2810 	C$fuzzy.h$924$1_0$56 ==.
                                   2811 ;	../../fuzzy.h:924: (upper_boundary - lower_boundary);
      000C12 E5 0E            [12] 2812 	mov	a,_bp
      000C14 24 F6            [12] 2813 	add	a,#0xf6
      000C16 F8               [12] 2814 	mov	r0,a
      000C17 86 82            [24] 2815 	mov	dpl, @r0
      000C19 08               [12] 2816 	inc	r0
      000C1A 86 83            [24] 2817 	mov	dph, @r0
      000C1C 08               [12] 2818 	inc	r0
      000C1D 86 F0            [24] 2819 	mov	b, @r0
      000C1F 08               [12] 2820 	inc	r0
      000C20 E6               [12] 2821 	mov	a, @r0
      000C21 12 22 CC         [24] 2822 	lcall	___fssub
      000C24 A8 0E            [24] 2823 	mov	r0,_bp
      000C26 08               [12] 2824 	inc	r0
      000C27 A6 82            [24] 2825 	mov	@r0, dpl
      000C29 08               [12] 2826 	inc	r0
      000C2A A6 83            [24] 2827 	mov	@r0, dph
      000C2C 08               [12] 2828 	inc	r0
      000C2D A6 F0            [24] 2829 	mov	@r0, b
      000C2F 08               [12] 2830 	inc	r0
      000C30 F6               [12] 2831 	mov	@r0,a
      000C31 E5 81            [12] 2832 	mov	a,sp
      000C33 24 FC            [12] 2833 	add	a,#0xfc
      000C35 F5 81            [12] 2834 	mov	sp,a
      000C37 E5 0E            [12] 2835 	mov	a,_bp
      000C39 24 FA            [12] 2836 	add	a,#0xfa
      000C3B F8               [12] 2837 	mov	r0,a
      000C3C 86 82            [24] 2838 	mov	dpl, @r0
      000C3E 08               [12] 2839 	inc	r0
      000C3F 86 83            [24] 2840 	mov	dph, @r0
      000C41 08               [12] 2841 	inc	r0
      000C42 86 F0            [24] 2842 	mov	b, @r0
      000C44 08               [12] 2843 	inc	r0
      000C45 E6               [12] 2844 	mov	a, @r0
      000C46 12 22 CC         [24] 2845 	lcall	___fssub
      000C49 AC 82            [24] 2846 	mov	r4, dpl
      000C4B AD 83            [24] 2847 	mov	r5, dph
      000C4D AE F0            [24] 2848 	mov	r6, b
      000C4F FF               [12] 2849 	mov	r7, a
      000C50 E5 81            [12] 2850 	mov	a,sp
      000C52 24 FC            [12] 2851 	add	a,#0xfc
      000C54 F5 81            [12] 2852 	mov	sp,a
      000C56 C0 04            [24] 2853 	push	ar4
      000C58 C0 05            [24] 2854 	push	ar5
      000C5A C0 06            [24] 2855 	push	ar6
      000C5C C0 07            [24] 2856 	push	ar7
                           000BA7  2857 	C$fuzzy.h$927$1_0$56 ==.
                                   2858 ;	../../fuzzy.h:927: ramp_up
      000C5E A8 0E            [24] 2859 	mov	r0,_bp
      000C60 08               [12] 2860 	inc	r0
      000C61 86 82            [24] 2861 	mov	dpl, @r0
      000C63 08               [12] 2862 	inc	r0
      000C64 86 83            [24] 2863 	mov	dph, @r0
      000C66 08               [12] 2864 	inc	r0
      000C67 86 F0            [24] 2865 	mov	b, @r0
      000C69 08               [12] 2866 	inc	r0
      000C6A E6               [12] 2867 	mov	a, @r0
      000C6B 12 25 70         [24] 2868 	lcall	___fsdiv
      000C6E AC 82            [24] 2869 	mov	r4, dpl
      000C70 AD 83            [24] 2870 	mov	r5, dph
      000C72 AE F0            [24] 2871 	mov	r6, b
      000C74 FF               [12] 2872 	mov	r7, a
      000C75 E5 81            [12] 2873 	mov	a,sp
      000C77 24 FC            [12] 2874 	add	a,#0xfc
      000C79 F5 81            [12] 2875 	mov	sp,a
      000C7B E5 0E            [12] 2876 	mov	a,_bp
      000C7D 24 F5            [12] 2877 	add	a,#0xf5
      000C7F F8               [12] 2878 	mov	r0,a
      000C80 E6               [12] 2879 	mov	a,@r0
      000C81 60 12            [24] 2880 	jz	00115$
                           000BCC  2881 	C$fuzzy.h$928$2_0$60 ==.
                                   2882 ;	../../fuzzy.h:928: ? normalized
      000C83 E5 0E            [12] 2883 	mov	a,_bp
      000C85 24 05            [12] 2884 	add	a,#0x05
      000C87 F8               [12] 2885 	mov	r0,a
      000C88 A6 04            [24] 2886 	mov	@r0,ar4
      000C8A 08               [12] 2887 	inc	r0
      000C8B A6 05            [24] 2888 	mov	@r0,ar5
      000C8D 08               [12] 2889 	inc	r0
      000C8E A6 06            [24] 2890 	mov	@r0,ar6
      000C90 08               [12] 2891 	inc	r0
      000C91 A6 07            [24] 2892 	mov	@r0,ar7
      000C93 80 29            [24] 2893 	sjmp	00116$
      000C95                       2894 00115$:
                           000BDE  2895 	C$fuzzy.h$929$1_0$56 ==.
                                   2896 ;	../../fuzzy.h:929: : LEVEL_HI - normalized;
      000C95 C0 04            [24] 2897 	push	ar4
      000C97 C0 05            [24] 2898 	push	ar5
      000C99 C0 06            [24] 2899 	push	ar6
      000C9B C0 07            [24] 2900 	push	ar7
      000C9D 90 00 00         [24] 2901 	mov	dptr,#0x0000
      000CA0 75 F0 80         [24] 2902 	mov	b, #0x80
      000CA3 74 3F            [12] 2903 	mov	a, #0x3f
      000CA5 12 22 CC         [24] 2904 	lcall	___fssub
      000CA8 C8               [12] 2905 	xch	a,r0
      000CA9 E5 0E            [12] 2906 	mov	a,_bp
      000CAB 24 05            [12] 2907 	add	a,#0x05
      000CAD C8               [12] 2908 	xch	a,r0
      000CAE A6 82            [24] 2909 	mov	@r0, dpl
      000CB0 08               [12] 2910 	inc	r0
      000CB1 A6 83            [24] 2911 	mov	@r0, dph
      000CB3 08               [12] 2912 	inc	r0
      000CB4 A6 F0            [24] 2913 	mov	@r0, b
      000CB6 08               [12] 2914 	inc	r0
      000CB7 F6               [12] 2915 	mov	@r0,a
      000CB8 E5 81            [12] 2916 	mov	a,sp
      000CBA 24 FC            [12] 2917 	add	a,#0xfc
      000CBC F5 81            [12] 2918 	mov	sp,a
      000CBE                       2919 00116$:
      000CBE E5 0E            [12] 2920 	mov	a,_bp
      000CC0 24 05            [12] 2921 	add	a,#0x05
      000CC2 F8               [12] 2922 	mov	r0,a
      000CC3 86 07            [24] 2923 	mov	ar7,@r0
      000CC5 08               [12] 2924 	inc	r0
      000CC6 86 06            [24] 2925 	mov	ar6,@r0
      000CC8 08               [12] 2926 	inc	r0
      000CC9 86 05            [24] 2927 	mov	ar5,@r0
      000CCB 08               [12] 2928 	inc	r0
      000CCC 86 04            [24] 2929 	mov	ar4,@r0
      000CCE                       2930 00108$:
                           000C17  2931 	C$fuzzy.h$933$1_0$56 ==.
                                   2932 ;	../../fuzzy.h:933: result,
      000CCE E5 0E            [12] 2933 	mov	a,_bp
      000CD0 24 F4            [12] 2934 	add	a,#0xf4
      000CD2 F8               [12] 2935 	mov	r0,a
      000CD3 E6               [12] 2936 	mov	a,@r0
      000CD4 C0 E0            [24] 2937 	push	acc
      000CD6 8F 82            [24] 2938 	mov	dpl, r7
      000CD8 8E 83            [24] 2939 	mov	dph, r6
      000CDA 8D F0            [24] 2940 	mov	b, r5
      000CDC EC               [12] 2941 	mov	a, r4
      000CDD 12 01 66         [24] 2942 	lcall	_fuzzy_apply_hedge
      000CE0 AC 82            [24] 2943 	mov	r4, dpl
      000CE2 AD 83            [24] 2944 	mov	r5, dph
      000CE4 AE F0            [24] 2945 	mov	r6, b
      000CE6 FF               [12] 2946 	mov	r7, a
      000CE7 15 81            [12] 2947 	dec	sp
      000CE9 8C 82            [24] 2948 	mov	dpl, r4
      000CEB 8D 83            [24] 2949 	mov	dph, r5
      000CED 8E F0            [24] 2950 	mov	b, r6
      000CEF EF               [12] 2951 	mov	a, r7
      000CF0                       2952 00109$:
                           000C39  2953 	C$fuzzy.h$936$1_0$56 ==.
                                   2954 ;	../../fuzzy.h:936: }
      000CF0 85 0E 81         [24] 2955 	mov	sp,_bp
      000CF3 D0 0E            [24] 2956 	pop	_bp
                           000C3E  2957 	C$fuzzy.h$936$1_0$56 ==.
                           000C3E  2958 	XG$fuzzy_ramp$0$0 ==.
      000CF5 22               [24] 2959 	ret
                                   2960 ;------------------------------------------------------------
                                   2961 ;Allocation info for local variables in function 'fuzzy_function_array'
                                   2962 ;------------------------------------------------------------
                                   2963 ;value         Allocated to stack - _bp -6 +4 
                                   2964 ;hedge         Allocated to stack - _bp -7 +1 
                                   2965 ;parameter_count Allocated to stack - _bp -9 +2 
                                   2966 ;parameters    Allocated to stack - _bp -12 +3 
                                   2967 ;shape         Allocated to registers r7 
                                   2968 ;result        Allocated to stack - _bp +5 +4 
                                   2969 ;parameter_1   Allocated to stack - _bp +17 +4 
                                   2970 ;parameter_2   Allocated to stack - _bp +21 +4 
                                   2971 ;parameter_3   Allocated to stack - _bp +25 +4 
                                   2972 ;parameter_4   Allocated to registers r5 r6 r7 r4 
                                   2973 ;ramp_up       Allocated to registers r7 
                                   2974 ;sloc0         Allocated to stack - _bp +23 +3 
                                   2975 ;sloc1         Allocated to stack - _bp +1 +4 
                                   2976 ;sloc2         Allocated to stack - _bp +5 +4 
                                   2977 ;sloc3         Allocated to stack - _bp +9 +4 
                                   2978 ;sloc4         Allocated to stack - _bp +13 +4 
                                   2979 ;------------------------------------------------------------
                           000C3F  2980 	G$fuzzy_function_array$0$0 ==.
                           000C3F  2981 	C$fuzzy.h$973$1_0$62 ==.
                                   2982 ;	../../fuzzy.h:973: float fuzzy_function_array(
                                   2983 ;	-----------------------------------------
                                   2984 ;	 function fuzzy_function_array
                                   2985 ;	-----------------------------------------
      000CF6                       2986 _fuzzy_function_array:
      000CF6 C0 0E            [24] 2987 	push	_bp
      000CF8 E5 81            [12] 2988 	mov	a,sp
      000CFA F5 0E            [12] 2989 	mov	_bp,a
      000CFC 24 1C            [12] 2990 	add	a,#0x1c
      000CFE F5 81            [12] 2991 	mov	sp,a
      000D00 AF 82            [24] 2992 	mov	r7, dpl
                           000C4B  2993 	C$fuzzy.h$995$1_0$62 ==.
                                   2994 ;	../../fuzzy.h:995: if (parameters == NULL) {
      000D02 E5 0E            [12] 2995 	mov	a,_bp
      000D04 24 F4            [12] 2996 	add	a,#0xf4
      000D06 F8               [12] 2997 	mov	r0,a
      000D07 E6               [12] 2998 	mov	a,@r0
      000D08 08               [12] 2999 	inc	r0
      000D09 46               [12] 3000 	orl	a,@r0
      000D0A 70 09            [24] 3001 	jnz	00102$
                           000C55  3002 	C$fuzzy.h$996$2_0$63 ==.
                                   3003 ;	../../fuzzy.h:996: return LEVEL_LO;
      000D0C 90 00 00         [24] 3004 	mov	dptr,#0x0000
      000D0F E4               [12] 3005 	clr	a
      000D10 F5 F0            [12] 3006 	mov	b,a
      000D12 02 16 2A         [24] 3007 	ljmp	00145$
      000D15                       3008 00102$:
                           000C5E  3009 	C$fuzzy.h$999$1_0$62 ==.
                                   3010 ;	../../fuzzy.h:999: switch (shape) {
      000D15 EF               [12] 3011 	mov	a,r7
      000D16 24 F8            [12] 3012 	add	a,#0xff - 0x07
      000D18 50 03            [24] 3013 	jnc	00267$
      000D1A 02 15 F8         [24] 3014 	ljmp	00143$
      000D1D                       3015 00267$:
      000D1D EF               [12] 3016 	mov	a,r7
      000D1E 24 0A            [12] 3017 	add	a,#(00268$-3-.)
      000D20 83               [24] 3018 	movc	a,@a+pc
      000D21 F5 82            [12] 3019 	mov	dpl,a
      000D23 EF               [12] 3020 	mov	a,r7
      000D24 24 0C            [12] 3021 	add	a,#(00269$-3-.)
      000D26 83               [24] 3022 	movc	a,@a+pc
      000D27 F5 83            [12] 3023 	mov	dph,a
      000D29 E4               [12] 3024 	clr	a
      000D2A 73               [24] 3025 	jmp	@a+dptr
      000D2B                       3026 00268$:
      000D2B 3B                    3027 	.db	00103$
      000D2C 39                    3028 	.db	00106$
      000D2D BF                    3029 	.db	00121$
      000D2E F0                    3030 	.db	00142$
      000D2F F0                    3031 	.db	00142$
      000D30 F0                    3032 	.db	00142$
      000D31 F0                    3033 	.db	00142$
      000D32 F0                    3034 	.db	00142$
      000D33                       3035 00269$:
      000D33 0D                    3036 	.db	00103$>>8
      000D34 0E                    3037 	.db	00106$>>8
      000D35 11                    3038 	.db	00121$>>8
      000D36 15                    3039 	.db	00142$>>8
      000D37 15                    3040 	.db	00142$>>8
      000D38 15                    3041 	.db	00142$>>8
      000D39 15                    3042 	.db	00142$>>8
      000D3A 15                    3043 	.db	00142$>>8
                           000C84  3044 	C$fuzzy.h$1000$2_0$64 ==.
                                   3045 ;	../../fuzzy.h:1000: case FUZZY_SHAPE_RAMP:
      000D3B                       3046 00103$:
                           000C84  3047 	C$fuzzy.h$1001$2_0$64 ==.
                                   3048 ;	../../fuzzy.h:1001: if (parameter_count != 3u) {
      000D3B E5 0E            [12] 3049 	mov	a,_bp
      000D3D 24 F7            [12] 3050 	add	a,#0xf7
      000D3F F8               [12] 3051 	mov	r0,a
      000D40 B6 03 06         [24] 3052 	cjne	@r0,#0x03,00270$
      000D43 08               [12] 3053 	inc	r0
      000D44 B6 00 02         [24] 3054 	cjne	@r0,#0x00,00270$
      000D47 80 09            [24] 3055 	sjmp	00105$
      000D49                       3056 00270$:
                           000C92  3057 	C$fuzzy.h$1002$3_0$65 ==.
                                   3058 ;	../../fuzzy.h:1002: return LEVEL_LO;
      000D49 90 00 00         [24] 3059 	mov	dptr,#0x0000
      000D4C E4               [12] 3060 	clr	a
      000D4D F5 F0            [12] 3061 	mov	b,a
      000D4F 02 16 2A         [24] 3062 	ljmp	00145$
      000D52                       3063 00105$:
                           000C9B  3064 	C$fuzzy.h$1005$2_0$64 ==.
                                   3065 ;	../../fuzzy.h:1005: parameter_1 = parameters[0];
      000D52 E5 0E            [12] 3066 	mov	a,_bp
      000D54 24 F4            [12] 3067 	add	a,#0xf4
      000D56 F8               [12] 3068 	mov	r0,a
      000D57 86 02            [24] 3069 	mov	ar2,@r0
      000D59 08               [12] 3070 	inc	r0
      000D5A 86 03            [24] 3071 	mov	ar3,@r0
      000D5C 08               [12] 3072 	inc	r0
      000D5D 86 04            [24] 3073 	mov	ar4,@r0
      000D5F 8A 82            [24] 3074 	mov	dpl,r2
      000D61 8B 83            [24] 3075 	mov	dph,r3
      000D63 8C F0            [24] 3076 	mov	b,r4
      000D65 A8 0E            [24] 3077 	mov	r0,_bp
      000D67 08               [12] 3078 	inc	r0
      000D68 12 26 33         [24] 3079 	lcall	__gptrget
      000D6B F6               [12] 3080 	mov	@r0,a
      000D6C A3               [24] 3081 	inc	dptr
      000D6D 12 26 33         [24] 3082 	lcall	__gptrget
      000D70 08               [12] 3083 	inc	r0
      000D71 F6               [12] 3084 	mov	@r0,a
      000D72 A3               [24] 3085 	inc	dptr
      000D73 12 26 33         [24] 3086 	lcall	__gptrget
      000D76 08               [12] 3087 	inc	r0
      000D77 F6               [12] 3088 	mov	@r0,a
      000D78 A3               [24] 3089 	inc	dptr
      000D79 12 26 33         [24] 3090 	lcall	__gptrget
      000D7C 08               [12] 3091 	inc	r0
      000D7D F6               [12] 3092 	mov	@r0,a
                           000CC7  3093 	C$fuzzy.h$1006$2_0$64 ==.
                                   3094 ;	../../fuzzy.h:1006: parameter_2 = parameters[1];
      000D7E 74 04            [12] 3095 	mov	a,#0x04
      000D80 2A               [12] 3096 	add	a, r2
      000D81 FD               [12] 3097 	mov	r5,a
      000D82 E4               [12] 3098 	clr	a
      000D83 3B               [12] 3099 	addc	a, r3
      000D84 FE               [12] 3100 	mov	r6,a
      000D85 8C 07            [24] 3101 	mov	ar7,r4
      000D87 8D 82            [24] 3102 	mov	dpl,r5
      000D89 8E 83            [24] 3103 	mov	dph,r6
      000D8B 8F F0            [24] 3104 	mov	b,r7
      000D8D E5 0E            [12] 3105 	mov	a,_bp
      000D8F 24 05            [12] 3106 	add	a,#0x05
      000D91 F8               [12] 3107 	mov	r0,a
      000D92 12 26 33         [24] 3108 	lcall	__gptrget
      000D95 F6               [12] 3109 	mov	@r0,a
      000D96 A3               [24] 3110 	inc	dptr
      000D97 12 26 33         [24] 3111 	lcall	__gptrget
      000D9A 08               [12] 3112 	inc	r0
      000D9B F6               [12] 3113 	mov	@r0,a
      000D9C A3               [24] 3114 	inc	dptr
      000D9D 12 26 33         [24] 3115 	lcall	__gptrget
      000DA0 08               [12] 3116 	inc	r0
      000DA1 F6               [12] 3117 	mov	@r0,a
      000DA2 A3               [24] 3118 	inc	dptr
      000DA3 12 26 33         [24] 3119 	lcall	__gptrget
      000DA6 08               [12] 3120 	inc	r0
      000DA7 F6               [12] 3121 	mov	@r0,a
                           000CF1  3122 	C$fuzzy.h$1007$2_0$64 ==.
                                   3123 ;	../../fuzzy.h:1007: ramp_up = parameters[2] != 0.0f;
      000DA8 74 08            [12] 3124 	mov	a,#0x08
      000DAA 2A               [12] 3125 	add	a, r2
      000DAB FA               [12] 3126 	mov	r2,a
      000DAC E4               [12] 3127 	clr	a
      000DAD 3B               [12] 3128 	addc	a, r3
      000DAE FB               [12] 3129 	mov	r3,a
      000DAF 8C 07            [24] 3130 	mov	ar7,r4
      000DB1 8A 82            [24] 3131 	mov	dpl,r2
      000DB3 8B 83            [24] 3132 	mov	dph,r3
      000DB5 8F F0            [24] 3133 	mov	b,r7
      000DB7 12 26 33         [24] 3134 	lcall	__gptrget
      000DBA FA               [12] 3135 	mov	r2,a
      000DBB A3               [24] 3136 	inc	dptr
      000DBC 12 26 33         [24] 3137 	lcall	__gptrget
      000DBF FB               [12] 3138 	mov	r3,a
      000DC0 A3               [24] 3139 	inc	dptr
      000DC1 12 26 33         [24] 3140 	lcall	__gptrget
      000DC4 FF               [12] 3141 	mov	r7,a
      000DC5 A3               [24] 3142 	inc	dptr
      000DC6 12 26 33         [24] 3143 	lcall	__gptrget
      000DC9 FE               [12] 3144 	mov	r6,a
      000DCA 8A F0            [24] 3145 	mov	b,r2
      000DCC EB               [12] 3146 	mov	a,r3
      000DCD 42 F0            [12] 3147 	orl	b,a
      000DCF EF               [12] 3148 	mov	a,r7
      000DD0 42 F0            [12] 3149 	orl	b,a
      000DD2 EE               [12] 3150 	mov	a,r6
      000DD3 54 7F            [12] 3151 	anl	a,#0x7F
      000DD5 45 F0            [12] 3152 	orl	a,b
      000DD7 B4 01 00         [24] 3153 	cjne	a,#0x01,00271$
      000DDA                       3154 00271$:
      000DDA B3               [12] 3155 	cpl	c
      000DDB 92 00            [24] 3156 	mov	b0,c
      000DDD E4               [12] 3157 	clr	a
      000DDE 33               [12] 3158 	rlc	a
      000DDF FF               [12] 3159 	mov	r7,a
                           000D29  3160 	C$fuzzy.h$1010$2_0$64 ==.
                                   3161 ;	../../fuzzy.h:1010: parameter_1,
      000DE0 E5 0E            [12] 3162 	mov	a,_bp
      000DE2 24 F9            [12] 3163 	add	a,#0xf9
      000DE4 F8               [12] 3164 	mov	r0,a
      000DE5 E6               [12] 3165 	mov	a,@r0
      000DE6 C0 E0            [24] 3166 	push	acc
      000DE8 C0 07            [24] 3167 	push	ar7
      000DEA E5 0E            [12] 3168 	mov	a,_bp
      000DEC 24 FA            [12] 3169 	add	a,#0xfa
      000DEE F8               [12] 3170 	mov	r0,a
      000DEF E6               [12] 3171 	mov	a,@r0
      000DF0 C0 E0            [24] 3172 	push	acc
      000DF2 08               [12] 3173 	inc	r0
      000DF3 E6               [12] 3174 	mov	a,@r0
      000DF4 C0 E0            [24] 3175 	push	acc
      000DF6 08               [12] 3176 	inc	r0
      000DF7 E6               [12] 3177 	mov	a,@r0
      000DF8 C0 E0            [24] 3178 	push	acc
      000DFA 08               [12] 3179 	inc	r0
      000DFB E6               [12] 3180 	mov	a,@r0
      000DFC C0 E0            [24] 3181 	push	acc
      000DFE E5 0E            [12] 3182 	mov	a,_bp
      000E00 24 05            [12] 3183 	add	a,#0x05
      000E02 F8               [12] 3184 	mov	r0,a
      000E03 E6               [12] 3185 	mov	a,@r0
      000E04 C0 E0            [24] 3186 	push	acc
      000E06 08               [12] 3187 	inc	r0
      000E07 E6               [12] 3188 	mov	a,@r0
      000E08 C0 E0            [24] 3189 	push	acc
      000E0A 08               [12] 3190 	inc	r0
      000E0B E6               [12] 3191 	mov	a,@r0
      000E0C C0 E0            [24] 3192 	push	acc
      000E0E 08               [12] 3193 	inc	r0
      000E0F E6               [12] 3194 	mov	a,@r0
      000E10 C0 E0            [24] 3195 	push	acc
      000E12 A8 0E            [24] 3196 	mov	r0,_bp
      000E14 08               [12] 3197 	inc	r0
      000E15 86 82            [24] 3198 	mov	dpl, @r0
      000E17 08               [12] 3199 	inc	r0
      000E18 86 83            [24] 3200 	mov	dph, @r0
      000E1A 08               [12] 3201 	inc	r0
      000E1B 86 F0            [24] 3202 	mov	b, @r0
      000E1D 08               [12] 3203 	inc	r0
      000E1E E6               [12] 3204 	mov	a, @r0
      000E1F 12 0A B9         [24] 3205 	lcall	_fuzzy_ramp
      000E22 AC 82            [24] 3206 	mov	r4, dpl
      000E24 AD 83            [24] 3207 	mov	r5, dph
      000E26 AE F0            [24] 3208 	mov	r6, b
      000E28 FF               [12] 3209 	mov	r7, a
      000E29 E5 81            [12] 3210 	mov	a,sp
      000E2B 24 F6            [12] 3211 	add	a,#0xf6
      000E2D F5 81            [12] 3212 	mov	sp,a
      000E2F 8C 82            [24] 3213 	mov	dpl, r4
      000E31 8D 83            [24] 3214 	mov	dph, r5
      000E33 8E F0            [24] 3215 	mov	b, r6
      000E35 EF               [12] 3216 	mov	a, r7
      000E36 02 16 2A         [24] 3217 	ljmp	00145$
                           000D82  3218 	C$fuzzy.h$1017$2_0$64 ==.
                                   3219 ;	../../fuzzy.h:1017: case FUZZY_SHAPE_TRIANGLE:
      000E39                       3220 00106$:
                           000D82  3221 	C$fuzzy.h$1018$2_0$64 ==.
                                   3222 ;	../../fuzzy.h:1018: if (parameter_count != 3u) {
      000E39 E5 0E            [12] 3223 	mov	a,_bp
      000E3B 24 F7            [12] 3224 	add	a,#0xf7
      000E3D F8               [12] 3225 	mov	r0,a
      000E3E B6 03 06         [24] 3226 	cjne	@r0,#0x03,00272$
      000E41 08               [12] 3227 	inc	r0
      000E42 B6 00 02         [24] 3228 	cjne	@r0,#0x00,00272$
      000E45 80 09            [24] 3229 	sjmp	00108$
      000E47                       3230 00272$:
                           000D90  3231 	C$fuzzy.h$1019$3_0$66 ==.
                                   3232 ;	../../fuzzy.h:1019: return LEVEL_LO;
      000E47 90 00 00         [24] 3233 	mov	dptr,#0x0000
      000E4A E4               [12] 3234 	clr	a
      000E4B F5 F0            [12] 3235 	mov	b,a
      000E4D 02 16 2A         [24] 3236 	ljmp	00145$
      000E50                       3237 00108$:
                           000D99  3238 	C$fuzzy.h$1022$2_0$64 ==.
                                   3239 ;	../../fuzzy.h:1022: parameter_1 = parameters[0];
      000E50 E5 0E            [12] 3240 	mov	a,_bp
      000E52 24 F4            [12] 3241 	add	a,#0xf4
      000E54 F8               [12] 3242 	mov	r0,a
      000E55 86 02            [24] 3243 	mov	ar2,@r0
      000E57 08               [12] 3244 	inc	r0
      000E58 86 03            [24] 3245 	mov	ar3,@r0
      000E5A 08               [12] 3246 	inc	r0
      000E5B 86 04            [24] 3247 	mov	ar4,@r0
      000E5D 8A 82            [24] 3248 	mov	dpl,r2
      000E5F 8B 83            [24] 3249 	mov	dph,r3
      000E61 8C F0            [24] 3250 	mov	b,r4
      000E63 E5 0E            [12] 3251 	mov	a,_bp
      000E65 24 11            [12] 3252 	add	a,#0x11
      000E67 F8               [12] 3253 	mov	r0,a
      000E68 12 26 33         [24] 3254 	lcall	__gptrget
      000E6B F6               [12] 3255 	mov	@r0,a
      000E6C A3               [24] 3256 	inc	dptr
      000E6D 12 26 33         [24] 3257 	lcall	__gptrget
      000E70 08               [12] 3258 	inc	r0
      000E71 F6               [12] 3259 	mov	@r0,a
      000E72 A3               [24] 3260 	inc	dptr
      000E73 12 26 33         [24] 3261 	lcall	__gptrget
      000E76 08               [12] 3262 	inc	r0
      000E77 F6               [12] 3263 	mov	@r0,a
      000E78 A3               [24] 3264 	inc	dptr
      000E79 12 26 33         [24] 3265 	lcall	__gptrget
      000E7C 08               [12] 3266 	inc	r0
      000E7D F6               [12] 3267 	mov	@r0,a
                           000DC7  3268 	C$fuzzy.h$1023$2_0$64 ==.
                                   3269 ;	../../fuzzy.h:1023: parameter_2 = parameters[1];
      000E7E 74 04            [12] 3270 	mov	a,#0x04
      000E80 2A               [12] 3271 	add	a, r2
      000E81 FF               [12] 3272 	mov	r7,a
      000E82 E4               [12] 3273 	clr	a
      000E83 3B               [12] 3274 	addc	a, r3
      000E84 FD               [12] 3275 	mov	r5,a
      000E85 8C 06            [24] 3276 	mov	ar6,r4
      000E87 8F 82            [24] 3277 	mov	dpl,r7
      000E89 8D 83            [24] 3278 	mov	dph,r5
      000E8B 8E F0            [24] 3279 	mov	b,r6
      000E8D E5 0E            [12] 3280 	mov	a,_bp
      000E8F 24 15            [12] 3281 	add	a,#0x15
      000E91 F8               [12] 3282 	mov	r0,a
      000E92 12 26 33         [24] 3283 	lcall	__gptrget
      000E95 F6               [12] 3284 	mov	@r0,a
      000E96 A3               [24] 3285 	inc	dptr
      000E97 12 26 33         [24] 3286 	lcall	__gptrget
      000E9A 08               [12] 3287 	inc	r0
      000E9B F6               [12] 3288 	mov	@r0,a
      000E9C A3               [24] 3289 	inc	dptr
      000E9D 12 26 33         [24] 3290 	lcall	__gptrget
      000EA0 08               [12] 3291 	inc	r0
      000EA1 F6               [12] 3292 	mov	@r0,a
      000EA2 A3               [24] 3293 	inc	dptr
      000EA3 12 26 33         [24] 3294 	lcall	__gptrget
      000EA6 08               [12] 3295 	inc	r0
      000EA7 F6               [12] 3296 	mov	@r0,a
                           000DF1  3297 	C$fuzzy.h$1024$2_0$64 ==.
                                   3298 ;	../../fuzzy.h:1024: parameter_3 = parameters[2];
      000EA8 74 08            [12] 3299 	mov	a,#0x08
      000EAA 2A               [12] 3300 	add	a, r2
      000EAB FA               [12] 3301 	mov	r2,a
      000EAC E4               [12] 3302 	clr	a
      000EAD 3B               [12] 3303 	addc	a, r3
      000EAE FB               [12] 3304 	mov	r3,a
      000EAF 8C 07            [24] 3305 	mov	ar7,r4
      000EB1 8A 82            [24] 3306 	mov	dpl,r2
      000EB3 8B 83            [24] 3307 	mov	dph,r3
      000EB5 8F F0            [24] 3308 	mov	b,r7
      000EB7 12 26 33         [24] 3309 	lcall	__gptrget
      000EBA FD               [12] 3310 	mov	r5,a
      000EBB A3               [24] 3311 	inc	dptr
      000EBC 12 26 33         [24] 3312 	lcall	__gptrget
      000EBF FE               [12] 3313 	mov	r6,a
      000EC0 A3               [24] 3314 	inc	dptr
      000EC1 12 26 33         [24] 3315 	lcall	__gptrget
      000EC4 FF               [12] 3316 	mov	r7,a
      000EC5 A3               [24] 3317 	inc	dptr
      000EC6 12 26 33         [24] 3318 	lcall	__gptrget
      000EC9 FC               [12] 3319 	mov	r4,a
                           000E13  3320 	C$fuzzy.h$1027$1_0$62 ==.
                                   3321 ;	../../fuzzy.h:1027: parameter_1 >= parameter_2 ||
      000ECA C0 07            [24] 3322 	push	ar7
      000ECC C0 06            [24] 3323 	push	ar6
      000ECE C0 05            [24] 3324 	push	ar5
      000ED0 C0 04            [24] 3325 	push	ar4
      000ED2 E5 0E            [12] 3326 	mov	a,_bp
      000ED4 24 15            [12] 3327 	add	a,#0x15
      000ED6 F8               [12] 3328 	mov	r0,a
      000ED7 E6               [12] 3329 	mov	a,@r0
      000ED8 C0 E0            [24] 3330 	push	acc
      000EDA 08               [12] 3331 	inc	r0
      000EDB E6               [12] 3332 	mov	a,@r0
      000EDC C0 E0            [24] 3333 	push	acc
      000EDE 08               [12] 3334 	inc	r0
      000EDF E6               [12] 3335 	mov	a,@r0
      000EE0 C0 E0            [24] 3336 	push	acc
      000EE2 08               [12] 3337 	inc	r0
      000EE3 E6               [12] 3338 	mov	a,@r0
      000EE4 C0 E0            [24] 3339 	push	acc
      000EE6 E5 0E            [12] 3340 	mov	a,_bp
      000EE8 24 11            [12] 3341 	add	a,#0x11
      000EEA F8               [12] 3342 	mov	r0,a
      000EEB 86 82            [24] 3343 	mov	dpl, @r0
      000EED 08               [12] 3344 	inc	r0
      000EEE 86 83            [24] 3345 	mov	dph, @r0
      000EF0 08               [12] 3346 	inc	r0
      000EF1 86 F0            [24] 3347 	mov	b, @r0
      000EF3 08               [12] 3348 	inc	r0
      000EF4 E6               [12] 3349 	mov	a, @r0
      000EF5 12 24 07         [24] 3350 	lcall	___fslt
      000EF8 E5 81            [12] 3351 	mov	a,sp
      000EFA 24 FC            [12] 3352 	add	a,#0xfc
      000EFC F5 81            [12] 3353 	mov	sp,a
      000EFE D0 04            [24] 3354 	pop	ar4
      000F00 D0 05            [24] 3355 	pop	ar5
      000F02 D0 06            [24] 3356 	pop	ar6
      000F04 D0 07            [24] 3357 	pop	ar7
      000F06 E5 82            [12] 3358 	mov	a, dpl
      000F08 24 FF            [12] 3359 	add	a,#0xff
      000F0A 92 00            [24] 3360 	mov	b0,c
      000F0C 40 03            [24] 3361 	jc	00273$
      000F0E 02 0F C5         [24] 3362 	ljmp	00115$
      000F11                       3363 00273$:
                           000E5A  3364 	C$fuzzy.h$1028$1_0$62 ==.
                                   3365 ;	../../fuzzy.h:1028: parameter_2 >= parameter_3 ||
      000F11 C0 07            [24] 3366 	push	ar7
      000F13 C0 06            [24] 3367 	push	ar6
      000F15 C0 05            [24] 3368 	push	ar5
      000F17 C0 04            [24] 3369 	push	ar4
      000F19 C0 05            [24] 3370 	push	ar5
      000F1B C0 06            [24] 3371 	push	ar6
      000F1D C0 07            [24] 3372 	push	ar7
      000F1F C0 04            [24] 3373 	push	ar4
      000F21 E5 0E            [12] 3374 	mov	a,_bp
      000F23 24 15            [12] 3375 	add	a,#0x15
      000F25 F8               [12] 3376 	mov	r0,a
      000F26 86 82            [24] 3377 	mov	dpl, @r0
      000F28 08               [12] 3378 	inc	r0
      000F29 86 83            [24] 3379 	mov	dph, @r0
      000F2B 08               [12] 3380 	inc	r0
      000F2C 86 F0            [24] 3381 	mov	b, @r0
      000F2E 08               [12] 3382 	inc	r0
      000F2F E6               [12] 3383 	mov	a, @r0
      000F30 12 24 07         [24] 3384 	lcall	___fslt
      000F33 E5 81            [12] 3385 	mov	a,sp
      000F35 24 FC            [12] 3386 	add	a,#0xfc
      000F37 F5 81            [12] 3387 	mov	sp,a
      000F39 D0 04            [24] 3388 	pop	ar4
      000F3B D0 05            [24] 3389 	pop	ar5
      000F3D D0 06            [24] 3390 	pop	ar6
      000F3F D0 07            [24] 3391 	pop	ar7
      000F41 E5 82            [12] 3392 	mov	a, dpl
      000F43 24 FF            [12] 3393 	add	a,#0xff
      000F45 92 00            [24] 3394 	mov	b0,c
      000F47 50 7C            [24] 3395 	jnc	00115$
                           000E92  3396 	C$fuzzy.h$1029$1_0$62 ==.
                                   3397 ;	../../fuzzy.h:1029: value <= parameter_1 ||
      000F49 C0 07            [24] 3398 	push	ar7
      000F4B C0 06            [24] 3399 	push	ar6
      000F4D C0 05            [24] 3400 	push	ar5
      000F4F C0 04            [24] 3401 	push	ar4
      000F51 E5 0E            [12] 3402 	mov	a,_bp
      000F53 24 FA            [12] 3403 	add	a,#0xfa
      000F55 F8               [12] 3404 	mov	r0,a
      000F56 E6               [12] 3405 	mov	a,@r0
      000F57 C0 E0            [24] 3406 	push	acc
      000F59 08               [12] 3407 	inc	r0
      000F5A E6               [12] 3408 	mov	a,@r0
      000F5B C0 E0            [24] 3409 	push	acc
      000F5D 08               [12] 3410 	inc	r0
      000F5E E6               [12] 3411 	mov	a,@r0
      000F5F C0 E0            [24] 3412 	push	acc
      000F61 08               [12] 3413 	inc	r0
      000F62 E6               [12] 3414 	mov	a,@r0
      000F63 C0 E0            [24] 3415 	push	acc
      000F65 E5 0E            [12] 3416 	mov	a,_bp
      000F67 24 11            [12] 3417 	add	a,#0x11
      000F69 F8               [12] 3418 	mov	r0,a
      000F6A 86 82            [24] 3419 	mov	dpl, @r0
      000F6C 08               [12] 3420 	inc	r0
      000F6D 86 83            [24] 3421 	mov	dph, @r0
      000F6F 08               [12] 3422 	inc	r0
      000F70 86 F0            [24] 3423 	mov	b, @r0
      000F72 08               [12] 3424 	inc	r0
      000F73 E6               [12] 3425 	mov	a, @r0
      000F74 12 24 07         [24] 3426 	lcall	___fslt
      000F77 E5 81            [12] 3427 	mov	a,sp
      000F79 24 FC            [12] 3428 	add	a,#0xfc
      000F7B F5 81            [12] 3429 	mov	sp,a
      000F7D D0 04            [24] 3430 	pop	ar4
      000F7F D0 05            [24] 3431 	pop	ar5
      000F81 D0 06            [24] 3432 	pop	ar6
      000F83 D0 07            [24] 3433 	pop	ar7
      000F85 E5 82            [12] 3434 	mov	a, dpl
      000F87 24 FF            [12] 3435 	add	a,#0xff
      000F89 92 00            [24] 3436 	mov	b0,c
      000F8B 50 38            [24] 3437 	jnc	00115$
                           000ED6  3438 	C$fuzzy.h$1031$1_0$62 ==.
                                   3439 ;	../../fuzzy.h:1031: ) {
      000F8D C0 07            [24] 3440 	push	ar7
      000F8F C0 06            [24] 3441 	push	ar6
      000F91 C0 05            [24] 3442 	push	ar5
      000F93 C0 04            [24] 3443 	push	ar4
      000F95 C0 05            [24] 3444 	push	ar5
      000F97 C0 06            [24] 3445 	push	ar6
      000F99 C0 07            [24] 3446 	push	ar7
      000F9B C0 04            [24] 3447 	push	ar4
      000F9D E5 0E            [12] 3448 	mov	a,_bp
      000F9F 24 FA            [12] 3449 	add	a,#0xfa
      000FA1 F8               [12] 3450 	mov	r0,a
      000FA2 86 82            [24] 3451 	mov	dpl, @r0
      000FA4 08               [12] 3452 	inc	r0
      000FA5 86 83            [24] 3453 	mov	dph, @r0
      000FA7 08               [12] 3454 	inc	r0
      000FA8 86 F0            [24] 3455 	mov	b, @r0
      000FAA 08               [12] 3456 	inc	r0
      000FAB E6               [12] 3457 	mov	a, @r0
      000FAC 12 24 07         [24] 3458 	lcall	___fslt
      000FAF E5 81            [12] 3459 	mov	a,sp
      000FB1 24 FC            [12] 3460 	add	a,#0xfc
      000FB3 F5 81            [12] 3461 	mov	sp,a
      000FB5 D0 04            [24] 3462 	pop	ar4
      000FB7 D0 05            [24] 3463 	pop	ar5
      000FB9 D0 06            [24] 3464 	pop	ar6
      000FBB D0 07            [24] 3465 	pop	ar7
      000FBD E5 82            [12] 3466 	mov	a, dpl
      000FBF 24 FF            [12] 3467 	add	a,#0xff
      000FC1 92 00            [24] 3468 	mov	b0,c
      000FC3 40 10            [24] 3469 	jc	00116$
      000FC5                       3470 00115$:
                           000F0E  3471 	C$fuzzy.h$1032$3_0$67 ==.
                                   3472 ;	../../fuzzy.h:1032: result = LEVEL_LO;
      000FC5 E5 0E            [12] 3473 	mov	a,_bp
      000FC7 24 05            [12] 3474 	add	a,#0x05
      000FC9 F8               [12] 3475 	mov	r0,a
      000FCA E4               [12] 3476 	clr	a
      000FCB F6               [12] 3477 	mov	@r0,a
      000FCC 08               [12] 3478 	inc	r0
      000FCD F6               [12] 3479 	mov	@r0,a
      000FCE 08               [12] 3480 	inc	r0
      000FCF F6               [12] 3481 	mov	@r0,a
      000FD0 08               [12] 3482 	inc	r0
      000FD1 F6               [12] 3483 	mov	@r0,a
      000FD2 02 16 00         [24] 3484 	ljmp	00144$
      000FD5                       3485 00116$:
                           000F1E  3486 	C$fuzzy.h$1034$1_0$62 ==.
                                   3487 ;	../../fuzzy.h:1034: else if (value == parameter_2) {
      000FD5 C0 07            [24] 3488 	push	ar7
      000FD7 C0 06            [24] 3489 	push	ar6
      000FD9 C0 05            [24] 3490 	push	ar5
      000FDB C0 04            [24] 3491 	push	ar4
      000FDD E5 0E            [12] 3492 	mov	a,_bp
      000FDF 24 15            [12] 3493 	add	a,#0x15
      000FE1 F8               [12] 3494 	mov	r0,a
      000FE2 E6               [12] 3495 	mov	a,@r0
      000FE3 C0 E0            [24] 3496 	push	acc
      000FE5 08               [12] 3497 	inc	r0
      000FE6 E6               [12] 3498 	mov	a,@r0
      000FE7 C0 E0            [24] 3499 	push	acc
      000FE9 08               [12] 3500 	inc	r0
      000FEA E6               [12] 3501 	mov	a,@r0
      000FEB C0 E0            [24] 3502 	push	acc
      000FED 08               [12] 3503 	inc	r0
      000FEE E6               [12] 3504 	mov	a,@r0
      000FEF C0 E0            [24] 3505 	push	acc
      000FF1 E5 0E            [12] 3506 	mov	a,_bp
      000FF3 24 FA            [12] 3507 	add	a,#0xfa
      000FF5 F8               [12] 3508 	mov	r0,a
      000FF6 86 82            [24] 3509 	mov	dpl, @r0
      000FF8 08               [12] 3510 	inc	r0
      000FF9 86 83            [24] 3511 	mov	dph, @r0
      000FFB 08               [12] 3512 	inc	r0
      000FFC 86 F0            [24] 3513 	mov	b, @r0
      000FFE 08               [12] 3514 	inc	r0
      000FFF E6               [12] 3515 	mov	a, @r0
      001000 12 23 DB         [24] 3516 	lcall	___fseq
      001003 AB 82            [24] 3517 	mov	r3, dpl
      001005 E5 81            [12] 3518 	mov	a,sp
      001007 24 FC            [12] 3519 	add	a,#0xfc
      001009 F5 81            [12] 3520 	mov	sp,a
      00100B D0 04            [24] 3521 	pop	ar4
      00100D D0 05            [24] 3522 	pop	ar5
      00100F D0 06            [24] 3523 	pop	ar6
      001011 D0 07            [24] 3524 	pop	ar7
      001013 EB               [12] 3525 	mov	a,r3
      001014 60 12            [24] 3526 	jz	00113$
                           000F5F  3527 	C$fuzzy.h$1035$3_0$68 ==.
                                   3528 ;	../../fuzzy.h:1035: result = LEVEL_HI;
      001016 E5 0E            [12] 3529 	mov	a,_bp
      001018 24 05            [12] 3530 	add	a,#0x05
      00101A F8               [12] 3531 	mov	r0,a
      00101B E4               [12] 3532 	clr	a
      00101C F6               [12] 3533 	mov	@r0,a
      00101D 08               [12] 3534 	inc	r0
      00101E F6               [12] 3535 	mov	@r0,a
      00101F 08               [12] 3536 	inc	r0
      001020 76 80            [12] 3537 	mov	@r0,#0x80
      001022 08               [12] 3538 	inc	r0
      001023 76 3F            [12] 3539 	mov	@r0,#0x3f
      001025 02 16 00         [24] 3540 	ljmp	00144$
      001028                       3541 00113$:
                           000F71  3542 	C$fuzzy.h$1037$1_0$62 ==.
                                   3543 ;	../../fuzzy.h:1037: else if (value < parameter_2) {
      001028 C0 07            [24] 3544 	push	ar7
      00102A C0 06            [24] 3545 	push	ar6
      00102C C0 05            [24] 3546 	push	ar5
      00102E C0 04            [24] 3547 	push	ar4
      001030 E5 0E            [12] 3548 	mov	a,_bp
      001032 24 15            [12] 3549 	add	a,#0x15
      001034 F8               [12] 3550 	mov	r0,a
      001035 E6               [12] 3551 	mov	a,@r0
      001036 C0 E0            [24] 3552 	push	acc
      001038 08               [12] 3553 	inc	r0
      001039 E6               [12] 3554 	mov	a,@r0
      00103A C0 E0            [24] 3555 	push	acc
      00103C 08               [12] 3556 	inc	r0
      00103D E6               [12] 3557 	mov	a,@r0
      00103E C0 E0            [24] 3558 	push	acc
      001040 08               [12] 3559 	inc	r0
      001041 E6               [12] 3560 	mov	a,@r0
      001042 C0 E0            [24] 3561 	push	acc
      001044 E5 0E            [12] 3562 	mov	a,_bp
      001046 24 FA            [12] 3563 	add	a,#0xfa
      001048 F8               [12] 3564 	mov	r0,a
      001049 86 82            [24] 3565 	mov	dpl, @r0
      00104B 08               [12] 3566 	inc	r0
      00104C 86 83            [24] 3567 	mov	dph, @r0
      00104E 08               [12] 3568 	inc	r0
      00104F 86 F0            [24] 3569 	mov	b, @r0
      001051 08               [12] 3570 	inc	r0
      001052 E6               [12] 3571 	mov	a, @r0
      001053 12 24 07         [24] 3572 	lcall	___fslt
      001056 AB 82            [24] 3573 	mov	r3, dpl
      001058 E5 81            [12] 3574 	mov	a,sp
      00105A 24 FC            [12] 3575 	add	a,#0xfc
      00105C F5 81            [12] 3576 	mov	sp,a
      00105E D0 04            [24] 3577 	pop	ar4
      001060 D0 05            [24] 3578 	pop	ar5
      001062 D0 06            [24] 3579 	pop	ar6
      001064 D0 07            [24] 3580 	pop	ar7
      001066 EB               [12] 3581 	mov	a,r3
      001067 70 03            [24] 3582 	jnz	00278$
      001069 02 11 22         [24] 3583 	ljmp	00110$
      00106C                       3584 00278$:
                           000FB5  3585 	C$fuzzy.h$1039$1_0$62 ==.
                                   3586 ;	../../fuzzy.h:1039: (value - parameter_1) /
      00106C E5 0E            [12] 3587 	mov	a,_bp
      00106E 24 11            [12] 3588 	add	a,#0x11
      001070 F8               [12] 3589 	mov	r0,a
      001071 E6               [12] 3590 	mov	a,@r0
      001072 C0 E0            [24] 3591 	push	acc
      001074 08               [12] 3592 	inc	r0
      001075 E6               [12] 3593 	mov	a,@r0
      001076 C0 E0            [24] 3594 	push	acc
      001078 08               [12] 3595 	inc	r0
      001079 E6               [12] 3596 	mov	a,@r0
      00107A C0 E0            [24] 3597 	push	acc
      00107C 08               [12] 3598 	inc	r0
      00107D E6               [12] 3599 	mov	a,@r0
      00107E C0 E0            [24] 3600 	push	acc
                           000FC9  3601 	C$fuzzy.h$1040$1_0$62 ==.
                                   3602 ;	../../fuzzy.h:1040: (parameter_2 - parameter_1);
      001080 E5 0E            [12] 3603 	mov	a,_bp
      001082 24 FA            [12] 3604 	add	a,#0xfa
      001084 F8               [12] 3605 	mov	r0,a
      001085 86 82            [24] 3606 	mov	dpl, @r0
      001087 08               [12] 3607 	inc	r0
      001088 86 83            [24] 3608 	mov	dph, @r0
      00108A 08               [12] 3609 	inc	r0
      00108B 86 F0            [24] 3610 	mov	b, @r0
      00108D 08               [12] 3611 	inc	r0
      00108E E6               [12] 3612 	mov	a, @r0
      00108F 12 22 CC         [24] 3613 	lcall	___fssub
      001092 AF 82            [24] 3614 	mov	r7, dpl
      001094 AE 83            [24] 3615 	mov	r6, dph
      001096 AD F0            [24] 3616 	mov	r5, b
      001098 FC               [12] 3617 	mov	r4, a
      001099 E5 81            [12] 3618 	mov	a,sp
      00109B 24 FC            [12] 3619 	add	a,#0xfc
      00109D F5 81            [12] 3620 	mov	sp,a
      00109F C0 07            [24] 3621 	push	ar7
      0010A1 C0 06            [24] 3622 	push	ar6
      0010A3 C0 05            [24] 3623 	push	ar5
      0010A5 C0 04            [24] 3624 	push	ar4
      0010A7 E5 0E            [12] 3625 	mov	a,_bp
      0010A9 24 11            [12] 3626 	add	a,#0x11
      0010AB F8               [12] 3627 	mov	r0,a
      0010AC E6               [12] 3628 	mov	a,@r0
      0010AD C0 E0            [24] 3629 	push	acc
      0010AF 08               [12] 3630 	inc	r0
      0010B0 E6               [12] 3631 	mov	a,@r0
      0010B1 C0 E0            [24] 3632 	push	acc
      0010B3 08               [12] 3633 	inc	r0
      0010B4 E6               [12] 3634 	mov	a,@r0
      0010B5 C0 E0            [24] 3635 	push	acc
      0010B7 08               [12] 3636 	inc	r0
      0010B8 E6               [12] 3637 	mov	a,@r0
      0010B9 C0 E0            [24] 3638 	push	acc
      0010BB E5 0E            [12] 3639 	mov	a,_bp
      0010BD 24 15            [12] 3640 	add	a,#0x15
      0010BF F8               [12] 3641 	mov	r0,a
      0010C0 86 82            [24] 3642 	mov	dpl, @r0
      0010C2 08               [12] 3643 	inc	r0
      0010C3 86 83            [24] 3644 	mov	dph, @r0
      0010C5 08               [12] 3645 	inc	r0
      0010C6 86 F0            [24] 3646 	mov	b, @r0
      0010C8 08               [12] 3647 	inc	r0
      0010C9 E6               [12] 3648 	mov	a, @r0
      0010CA 12 22 CC         [24] 3649 	lcall	___fssub
      0010CD C8               [12] 3650 	xch	a,r0
      0010CE E5 0E            [12] 3651 	mov	a,_bp
      0010D0 24 09            [12] 3652 	add	a,#0x09
      0010D2 C8               [12] 3653 	xch	a,r0
      0010D3 A6 82            [24] 3654 	mov	@r0, dpl
      0010D5 08               [12] 3655 	inc	r0
      0010D6 A6 83            [24] 3656 	mov	@r0, dph
      0010D8 08               [12] 3657 	inc	r0
      0010D9 A6 F0            [24] 3658 	mov	@r0, b
      0010DB 08               [12] 3659 	inc	r0
      0010DC F6               [12] 3660 	mov	@r0,a
      0010DD E5 81            [12] 3661 	mov	a,sp
      0010DF 24 FC            [12] 3662 	add	a,#0xfc
      0010E1 F5 81            [12] 3663 	mov	sp,a
      0010E3 D0 04            [24] 3664 	pop	ar4
      0010E5 D0 05            [24] 3665 	pop	ar5
      0010E7 D0 06            [24] 3666 	pop	ar6
      0010E9 D0 07            [24] 3667 	pop	ar7
      0010EB E5 0E            [12] 3668 	mov	a,_bp
      0010ED 24 09            [12] 3669 	add	a,#0x09
      0010EF F8               [12] 3670 	mov	r0,a
      0010F0 E6               [12] 3671 	mov	a,@r0
      0010F1 C0 E0            [24] 3672 	push	acc
      0010F3 08               [12] 3673 	inc	r0
      0010F4 E6               [12] 3674 	mov	a,@r0
      0010F5 C0 E0            [24] 3675 	push	acc
      0010F7 08               [12] 3676 	inc	r0
      0010F8 E6               [12] 3677 	mov	a,@r0
      0010F9 C0 E0            [24] 3678 	push	acc
      0010FB 08               [12] 3679 	inc	r0
      0010FC E6               [12] 3680 	mov	a,@r0
      0010FD C0 E0            [24] 3681 	push	acc
      0010FF 8F 82            [24] 3682 	mov	dpl, r7
      001101 8E 83            [24] 3683 	mov	dph, r6
      001103 8D F0            [24] 3684 	mov	b, r5
      001105 EC               [12] 3685 	mov	a, r4
      001106 12 25 70         [24] 3686 	lcall	___fsdiv
      001109 C8               [12] 3687 	xch	a,r0
      00110A E5 0E            [12] 3688 	mov	a,_bp
      00110C 24 05            [12] 3689 	add	a,#0x05
      00110E C8               [12] 3690 	xch	a,r0
      00110F A6 82            [24] 3691 	mov	@r0, dpl
      001111 08               [12] 3692 	inc	r0
      001112 A6 83            [24] 3693 	mov	@r0, dph
      001114 08               [12] 3694 	inc	r0
      001115 A6 F0            [24] 3695 	mov	@r0, b
      001117 08               [12] 3696 	inc	r0
      001118 F6               [12] 3697 	mov	@r0,a
      001119 E5 81            [12] 3698 	mov	a,sp
      00111B 24 FC            [12] 3699 	add	a,#0xfc
      00111D F5 81            [12] 3700 	mov	sp,a
      00111F 02 16 00         [24] 3701 	ljmp	00144$
      001122                       3702 00110$:
                           00106B  3703 	C$fuzzy.h$1044$1_0$62 ==.
                                   3704 ;	../../fuzzy.h:1044: (parameter_3 - value) /
      001122 C0 07            [24] 3705 	push	ar7
      001124 C0 06            [24] 3706 	push	ar6
      001126 C0 05            [24] 3707 	push	ar5
      001128 C0 04            [24] 3708 	push	ar4
      00112A E5 0E            [12] 3709 	mov	a,_bp
      00112C 24 FA            [12] 3710 	add	a,#0xfa
      00112E F8               [12] 3711 	mov	r0,a
      00112F E6               [12] 3712 	mov	a,@r0
      001130 C0 E0            [24] 3713 	push	acc
      001132 08               [12] 3714 	inc	r0
      001133 E6               [12] 3715 	mov	a,@r0
      001134 C0 E0            [24] 3716 	push	acc
      001136 08               [12] 3717 	inc	r0
      001137 E6               [12] 3718 	mov	a,@r0
      001138 C0 E0            [24] 3719 	push	acc
      00113A 08               [12] 3720 	inc	r0
      00113B E6               [12] 3721 	mov	a,@r0
      00113C C0 E0            [24] 3722 	push	acc
                           001087  3723 	C$fuzzy.h$1045$1_0$62 ==.
                                   3724 ;	../../fuzzy.h:1045: (parameter_3 - parameter_2);
      00113E 8D 82            [24] 3725 	mov	dpl, r5
      001140 8E 83            [24] 3726 	mov	dph, r6
      001142 8F F0            [24] 3727 	mov	b, r7
      001144 EC               [12] 3728 	mov	a, r4
      001145 12 22 CC         [24] 3729 	lcall	___fssub
      001148 A8 0E            [24] 3730 	mov	r0,_bp
      00114A 08               [12] 3731 	inc	r0
      00114B A6 82            [24] 3732 	mov	@r0, dpl
      00114D 08               [12] 3733 	inc	r0
      00114E A6 83            [24] 3734 	mov	@r0, dph
      001150 08               [12] 3735 	inc	r0
      001151 A6 F0            [24] 3736 	mov	@r0, b
      001153 08               [12] 3737 	inc	r0
      001154 F6               [12] 3738 	mov	@r0,a
      001155 E5 81            [12] 3739 	mov	a,sp
      001157 24 FC            [12] 3740 	add	a,#0xfc
      001159 F5 81            [12] 3741 	mov	sp,a
      00115B D0 04            [24] 3742 	pop	ar4
      00115D D0 05            [24] 3743 	pop	ar5
      00115F D0 06            [24] 3744 	pop	ar6
      001161 D0 07            [24] 3745 	pop	ar7
      001163 E5 0E            [12] 3746 	mov	a,_bp
      001165 24 15            [12] 3747 	add	a,#0x15
      001167 F8               [12] 3748 	mov	r0,a
      001168 E6               [12] 3749 	mov	a,@r0
      001169 C0 E0            [24] 3750 	push	acc
      00116B 08               [12] 3751 	inc	r0
      00116C E6               [12] 3752 	mov	a,@r0
      00116D C0 E0            [24] 3753 	push	acc
      00116F 08               [12] 3754 	inc	r0
      001170 E6               [12] 3755 	mov	a,@r0
      001171 C0 E0            [24] 3756 	push	acc
      001173 08               [12] 3757 	inc	r0
      001174 E6               [12] 3758 	mov	a,@r0
      001175 C0 E0            [24] 3759 	push	acc
      001177 8D 82            [24] 3760 	mov	dpl, r5
      001179 8E 83            [24] 3761 	mov	dph, r6
      00117B 8F F0            [24] 3762 	mov	b, r7
      00117D EC               [12] 3763 	mov	a, r4
      00117E 12 22 CC         [24] 3764 	lcall	___fssub
      001181 AC 82            [24] 3765 	mov	r4, dpl
      001183 AD 83            [24] 3766 	mov	r5, dph
      001185 AE F0            [24] 3767 	mov	r6, b
      001187 FF               [12] 3768 	mov	r7, a
      001188 E5 81            [12] 3769 	mov	a,sp
      00118A 24 FC            [12] 3770 	add	a,#0xfc
      00118C F5 81            [12] 3771 	mov	sp,a
      00118E C0 04            [24] 3772 	push	ar4
      001190 C0 05            [24] 3773 	push	ar5
      001192 C0 06            [24] 3774 	push	ar6
      001194 C0 07            [24] 3775 	push	ar7
                           0010DF  3776 	C$fuzzy.h$1047$1_0$62 ==.
                                   3777 ;	../../fuzzy.h:1047: break;
      001196 A8 0E            [24] 3778 	mov	r0,_bp
      001198 08               [12] 3779 	inc	r0
      001199 86 82            [24] 3780 	mov	dpl, @r0
      00119B 08               [12] 3781 	inc	r0
      00119C 86 83            [24] 3782 	mov	dph, @r0
      00119E 08               [12] 3783 	inc	r0
      00119F 86 F0            [24] 3784 	mov	b, @r0
      0011A1 08               [12] 3785 	inc	r0
      0011A2 E6               [12] 3786 	mov	a, @r0
      0011A3 12 25 70         [24] 3787 	lcall	___fsdiv
      0011A6 C8               [12] 3788 	xch	a,r0
      0011A7 E5 0E            [12] 3789 	mov	a,_bp
      0011A9 24 05            [12] 3790 	add	a,#0x05
      0011AB C8               [12] 3791 	xch	a,r0
      0011AC A6 82            [24] 3792 	mov	@r0, dpl
      0011AE 08               [12] 3793 	inc	r0
      0011AF A6 83            [24] 3794 	mov	@r0, dph
      0011B1 08               [12] 3795 	inc	r0
      0011B2 A6 F0            [24] 3796 	mov	@r0, b
      0011B4 08               [12] 3797 	inc	r0
      0011B5 F6               [12] 3798 	mov	@r0,a
      0011B6 E5 81            [12] 3799 	mov	a,sp
      0011B8 24 FC            [12] 3800 	add	a,#0xfc
      0011BA F5 81            [12] 3801 	mov	sp,a
      0011BC 02 16 00         [24] 3802 	ljmp	00144$
                           001108  3803 	C$fuzzy.h$1049$2_0$64 ==.
                                   3804 ;	../../fuzzy.h:1049: case FUZZY_SHAPE_TRAPEZOID:
      0011BF                       3805 00121$:
                           001108  3806 	C$fuzzy.h$1050$2_0$64 ==.
                                   3807 ;	../../fuzzy.h:1050: if (parameter_count != 4u) {
      0011BF E5 0E            [12] 3808 	mov	a,_bp
      0011C1 24 F7            [12] 3809 	add	a,#0xf7
      0011C3 F8               [12] 3810 	mov	r0,a
      0011C4 B6 04 06         [24] 3811 	cjne	@r0,#0x04,00279$
      0011C7 08               [12] 3812 	inc	r0
      0011C8 B6 00 02         [24] 3813 	cjne	@r0,#0x00,00279$
      0011CB 80 09            [24] 3814 	sjmp	00123$
      0011CD                       3815 00279$:
                           001116  3816 	C$fuzzy.h$1051$3_0$71 ==.
                                   3817 ;	../../fuzzy.h:1051: return LEVEL_LO;
      0011CD 90 00 00         [24] 3818 	mov	dptr,#0x0000
      0011D0 E4               [12] 3819 	clr	a
      0011D1 F5 F0            [12] 3820 	mov	b,a
      0011D3 02 16 2A         [24] 3821 	ljmp	00145$
      0011D6                       3822 00123$:
                           00111F  3823 	C$fuzzy.h$1054$2_0$64 ==.
                                   3824 ;	../../fuzzy.h:1054: parameter_1 = parameters[0];
      0011D6 E5 0E            [12] 3825 	mov	a,_bp
      0011D8 24 F4            [12] 3826 	add	a,#0xf4
      0011DA F8               [12] 3827 	mov	r0,a
      0011DB 86 05            [24] 3828 	mov	ar5,@r0
      0011DD 08               [12] 3829 	inc	r0
      0011DE 86 06            [24] 3830 	mov	ar6,@r0
      0011E0 08               [12] 3831 	inc	r0
      0011E1 86 07            [24] 3832 	mov	ar7,@r0
      0011E3 8D 82            [24] 3833 	mov	dpl,r5
      0011E5 8E 83            [24] 3834 	mov	dph,r6
      0011E7 8F F0            [24] 3835 	mov	b,r7
      0011E9 E5 0E            [12] 3836 	mov	a,_bp
      0011EB 24 09            [12] 3837 	add	a,#0x09
      0011ED F8               [12] 3838 	mov	r0,a
      0011EE 12 26 33         [24] 3839 	lcall	__gptrget
      0011F1 F6               [12] 3840 	mov	@r0,a
      0011F2 A3               [24] 3841 	inc	dptr
      0011F3 12 26 33         [24] 3842 	lcall	__gptrget
      0011F6 08               [12] 3843 	inc	r0
      0011F7 F6               [12] 3844 	mov	@r0,a
      0011F8 A3               [24] 3845 	inc	dptr
      0011F9 12 26 33         [24] 3846 	lcall	__gptrget
      0011FC 08               [12] 3847 	inc	r0
      0011FD F6               [12] 3848 	mov	@r0,a
      0011FE A3               [24] 3849 	inc	dptr
      0011FF 12 26 33         [24] 3850 	lcall	__gptrget
      001202 08               [12] 3851 	inc	r0
      001203 F6               [12] 3852 	mov	@r0,a
                           00114D  3853 	C$fuzzy.h$1055$2_0$64 ==.
                                   3854 ;	../../fuzzy.h:1055: parameter_2 = parameters[1];
      001204 74 04            [12] 3855 	mov	a,#0x04
      001206 2D               [12] 3856 	add	a, r5
      001207 FA               [12] 3857 	mov	r2,a
      001208 E4               [12] 3858 	clr	a
      001209 3E               [12] 3859 	addc	a, r6
      00120A FB               [12] 3860 	mov	r3,a
      00120B 8F 04            [24] 3861 	mov	ar4,r7
      00120D 8A 82            [24] 3862 	mov	dpl,r2
      00120F 8B 83            [24] 3863 	mov	dph,r3
      001211 8C F0            [24] 3864 	mov	b,r4
      001213 A8 0E            [24] 3865 	mov	r0,_bp
      001215 08               [12] 3866 	inc	r0
      001216 12 26 33         [24] 3867 	lcall	__gptrget
      001219 F6               [12] 3868 	mov	@r0,a
      00121A A3               [24] 3869 	inc	dptr
      00121B 12 26 33         [24] 3870 	lcall	__gptrget
      00121E 08               [12] 3871 	inc	r0
      00121F F6               [12] 3872 	mov	@r0,a
      001220 A3               [24] 3873 	inc	dptr
      001221 12 26 33         [24] 3874 	lcall	__gptrget
      001224 08               [12] 3875 	inc	r0
      001225 F6               [12] 3876 	mov	@r0,a
      001226 A3               [24] 3877 	inc	dptr
      001227 12 26 33         [24] 3878 	lcall	__gptrget
      00122A 08               [12] 3879 	inc	r0
      00122B F6               [12] 3880 	mov	@r0,a
                           001175  3881 	C$fuzzy.h$1056$2_0$64 ==.
                                   3882 ;	../../fuzzy.h:1056: parameter_3 = parameters[2];
      00122C 74 08            [12] 3883 	mov	a,#0x08
      00122E 2D               [12] 3884 	add	a, r5
      00122F FA               [12] 3885 	mov	r2,a
      001230 E4               [12] 3886 	clr	a
      001231 3E               [12] 3887 	addc	a, r6
      001232 FB               [12] 3888 	mov	r3,a
      001233 8F 04            [24] 3889 	mov	ar4,r7
      001235 8A 82            [24] 3890 	mov	dpl,r2
      001237 8B 83            [24] 3891 	mov	dph,r3
      001239 8C F0            [24] 3892 	mov	b,r4
      00123B E5 0E            [12] 3893 	mov	a,_bp
      00123D 24 19            [12] 3894 	add	a,#0x19
      00123F F8               [12] 3895 	mov	r0,a
      001240 12 26 33         [24] 3896 	lcall	__gptrget
      001243 F6               [12] 3897 	mov	@r0,a
      001244 A3               [24] 3898 	inc	dptr
      001245 12 26 33         [24] 3899 	lcall	__gptrget
      001248 08               [12] 3900 	inc	r0
      001249 F6               [12] 3901 	mov	@r0,a
      00124A A3               [24] 3902 	inc	dptr
      00124B 12 26 33         [24] 3903 	lcall	__gptrget
      00124E 08               [12] 3904 	inc	r0
      00124F F6               [12] 3905 	mov	@r0,a
      001250 A3               [24] 3906 	inc	dptr
      001251 12 26 33         [24] 3907 	lcall	__gptrget
      001254 08               [12] 3908 	inc	r0
      001255 F6               [12] 3909 	mov	@r0,a
                           00119F  3910 	C$fuzzy.h$1057$2_0$64 ==.
                                   3911 ;	../../fuzzy.h:1057: parameter_4 = parameters[3];
      001256 74 0C            [12] 3912 	mov	a,#0x0c
      001258 2D               [12] 3913 	add	a, r5
      001259 FD               [12] 3914 	mov	r5,a
      00125A E4               [12] 3915 	clr	a
      00125B 3E               [12] 3916 	addc	a, r6
      00125C FE               [12] 3917 	mov	r6,a
      00125D 8D 82            [24] 3918 	mov	dpl,r5
      00125F 8E 83            [24] 3919 	mov	dph,r6
      001261 8F F0            [24] 3920 	mov	b,r7
      001263 12 26 33         [24] 3921 	lcall	__gptrget
      001266 FD               [12] 3922 	mov	r5,a
      001267 A3               [24] 3923 	inc	dptr
      001268 12 26 33         [24] 3924 	lcall	__gptrget
      00126B FE               [12] 3925 	mov	r6,a
      00126C A3               [24] 3926 	inc	dptr
      00126D 12 26 33         [24] 3927 	lcall	__gptrget
      001270 FF               [12] 3928 	mov	r7,a
      001271 A3               [24] 3929 	inc	dptr
      001272 12 26 33         [24] 3930 	lcall	__gptrget
      001275 FC               [12] 3931 	mov	r4,a
                           0011BF  3932 	C$fuzzy.h$1060$1_0$62 ==.
                                   3933 ;	../../fuzzy.h:1060: parameter_1 >= parameter_2 ||
      001276 C0 07            [24] 3934 	push	ar7
      001278 C0 06            [24] 3935 	push	ar6
      00127A C0 05            [24] 3936 	push	ar5
      00127C C0 04            [24] 3937 	push	ar4
      00127E A8 0E            [24] 3938 	mov	r0,_bp
      001280 08               [12] 3939 	inc	r0
      001281 E6               [12] 3940 	mov	a,@r0
      001282 C0 E0            [24] 3941 	push	acc
      001284 08               [12] 3942 	inc	r0
      001285 E6               [12] 3943 	mov	a,@r0
      001286 C0 E0            [24] 3944 	push	acc
      001288 08               [12] 3945 	inc	r0
      001289 E6               [12] 3946 	mov	a,@r0
      00128A C0 E0            [24] 3947 	push	acc
      00128C 08               [12] 3948 	inc	r0
      00128D E6               [12] 3949 	mov	a,@r0
      00128E C0 E0            [24] 3950 	push	acc
      001290 E5 0E            [12] 3951 	mov	a,_bp
      001292 24 09            [12] 3952 	add	a,#0x09
      001294 F8               [12] 3953 	mov	r0,a
      001295 86 82            [24] 3954 	mov	dpl, @r0
      001297 08               [12] 3955 	inc	r0
      001298 86 83            [24] 3956 	mov	dph, @r0
      00129A 08               [12] 3957 	inc	r0
      00129B 86 F0            [24] 3958 	mov	b, @r0
      00129D 08               [12] 3959 	inc	r0
      00129E E6               [12] 3960 	mov	a, @r0
      00129F 12 24 07         [24] 3961 	lcall	___fslt
      0012A2 E5 81            [12] 3962 	mov	a,sp
      0012A4 24 FC            [12] 3963 	add	a,#0xfc
      0012A6 F5 81            [12] 3964 	mov	sp,a
      0012A8 D0 04            [24] 3965 	pop	ar4
      0012AA D0 05            [24] 3966 	pop	ar5
      0012AC D0 06            [24] 3967 	pop	ar6
      0012AE D0 07            [24] 3968 	pop	ar7
      0012B0 E5 82            [12] 3969 	mov	a, dpl
      0012B2 24 FF            [12] 3970 	add	a,#0xff
      0012B4 92 00            [24] 3971 	mov	b0,c
      0012B6 40 03            [24] 3972 	jc	00280$
      0012B8 02 13 B1         [24] 3973 	ljmp	00131$
      0012BB                       3974 00280$:
                           001204  3975 	C$fuzzy.h$1061$1_0$62 ==.
                                   3976 ;	../../fuzzy.h:1061: parameter_2 > parameter_3 ||
      0012BB C0 07            [24] 3977 	push	ar7
      0012BD C0 06            [24] 3978 	push	ar6
      0012BF C0 05            [24] 3979 	push	ar5
      0012C1 C0 04            [24] 3980 	push	ar4
      0012C3 A8 0E            [24] 3981 	mov	r0,_bp
      0012C5 08               [12] 3982 	inc	r0
      0012C6 E6               [12] 3983 	mov	a,@r0
      0012C7 C0 E0            [24] 3984 	push	acc
      0012C9 08               [12] 3985 	inc	r0
      0012CA E6               [12] 3986 	mov	a,@r0
      0012CB C0 E0            [24] 3987 	push	acc
      0012CD 08               [12] 3988 	inc	r0
      0012CE E6               [12] 3989 	mov	a,@r0
      0012CF C0 E0            [24] 3990 	push	acc
      0012D1 08               [12] 3991 	inc	r0
      0012D2 E6               [12] 3992 	mov	a,@r0
      0012D3 C0 E0            [24] 3993 	push	acc
      0012D5 E5 0E            [12] 3994 	mov	a,_bp
      0012D7 24 19            [12] 3995 	add	a,#0x19
      0012D9 F8               [12] 3996 	mov	r0,a
      0012DA 86 82            [24] 3997 	mov	dpl, @r0
      0012DC 08               [12] 3998 	inc	r0
      0012DD 86 83            [24] 3999 	mov	dph, @r0
      0012DF 08               [12] 4000 	inc	r0
      0012E0 86 F0            [24] 4001 	mov	b, @r0
      0012E2 08               [12] 4002 	inc	r0
      0012E3 E6               [12] 4003 	mov	a, @r0
      0012E4 12 24 07         [24] 4004 	lcall	___fslt
      0012E7 AB 82            [24] 4005 	mov	r3, dpl
      0012E9 E5 81            [12] 4006 	mov	a,sp
      0012EB 24 FC            [12] 4007 	add	a,#0xfc
      0012ED F5 81            [12] 4008 	mov	sp,a
      0012EF D0 04            [24] 4009 	pop	ar4
      0012F1 D0 05            [24] 4010 	pop	ar5
      0012F3 D0 06            [24] 4011 	pop	ar6
      0012F5 D0 07            [24] 4012 	pop	ar7
      0012F7 EB               [12] 4013 	mov	a,r3
      0012F8 60 03            [24] 4014 	jz	00281$
      0012FA 02 13 B1         [24] 4015 	ljmp	00131$
      0012FD                       4016 00281$:
                           001246  4017 	C$fuzzy.h$1062$1_0$62 ==.
                                   4018 ;	../../fuzzy.h:1062: parameter_3 >= parameter_4 ||
      0012FD C0 07            [24] 4019 	push	ar7
      0012FF C0 06            [24] 4020 	push	ar6
      001301 C0 05            [24] 4021 	push	ar5
      001303 C0 04            [24] 4022 	push	ar4
      001305 C0 05            [24] 4023 	push	ar5
      001307 C0 06            [24] 4024 	push	ar6
      001309 C0 07            [24] 4025 	push	ar7
      00130B C0 04            [24] 4026 	push	ar4
      00130D E5 0E            [12] 4027 	mov	a,_bp
      00130F 24 19            [12] 4028 	add	a,#0x19
      001311 F8               [12] 4029 	mov	r0,a
      001312 86 82            [24] 4030 	mov	dpl, @r0
      001314 08               [12] 4031 	inc	r0
      001315 86 83            [24] 4032 	mov	dph, @r0
      001317 08               [12] 4033 	inc	r0
      001318 86 F0            [24] 4034 	mov	b, @r0
      00131A 08               [12] 4035 	inc	r0
      00131B E6               [12] 4036 	mov	a, @r0
      00131C 12 24 07         [24] 4037 	lcall	___fslt
      00131F E5 81            [12] 4038 	mov	a,sp
      001321 24 FC            [12] 4039 	add	a,#0xfc
      001323 F5 81            [12] 4040 	mov	sp,a
      001325 D0 04            [24] 4041 	pop	ar4
      001327 D0 05            [24] 4042 	pop	ar5
      001329 D0 06            [24] 4043 	pop	ar6
      00132B D0 07            [24] 4044 	pop	ar7
      00132D E5 82            [12] 4045 	mov	a, dpl
      00132F 24 FF            [12] 4046 	add	a,#0xff
      001331 92 00            [24] 4047 	mov	b0,c
      001333 50 7C            [24] 4048 	jnc	00131$
                           00127E  4049 	C$fuzzy.h$1063$1_0$62 ==.
                                   4050 ;	../../fuzzy.h:1063: value <= parameter_1 ||
      001335 C0 07            [24] 4051 	push	ar7
      001337 C0 06            [24] 4052 	push	ar6
      001339 C0 05            [24] 4053 	push	ar5
      00133B C0 04            [24] 4054 	push	ar4
      00133D E5 0E            [12] 4055 	mov	a,_bp
      00133F 24 FA            [12] 4056 	add	a,#0xfa
      001341 F8               [12] 4057 	mov	r0,a
      001342 E6               [12] 4058 	mov	a,@r0
      001343 C0 E0            [24] 4059 	push	acc
      001345 08               [12] 4060 	inc	r0
      001346 E6               [12] 4061 	mov	a,@r0
      001347 C0 E0            [24] 4062 	push	acc
      001349 08               [12] 4063 	inc	r0
      00134A E6               [12] 4064 	mov	a,@r0
      00134B C0 E0            [24] 4065 	push	acc
      00134D 08               [12] 4066 	inc	r0
      00134E E6               [12] 4067 	mov	a,@r0
      00134F C0 E0            [24] 4068 	push	acc
      001351 E5 0E            [12] 4069 	mov	a,_bp
      001353 24 09            [12] 4070 	add	a,#0x09
      001355 F8               [12] 4071 	mov	r0,a
      001356 86 82            [24] 4072 	mov	dpl, @r0
      001358 08               [12] 4073 	inc	r0
      001359 86 83            [24] 4074 	mov	dph, @r0
      00135B 08               [12] 4075 	inc	r0
      00135C 86 F0            [24] 4076 	mov	b, @r0
      00135E 08               [12] 4077 	inc	r0
      00135F E6               [12] 4078 	mov	a, @r0
      001360 12 24 07         [24] 4079 	lcall	___fslt
      001363 E5 81            [12] 4080 	mov	a,sp
      001365 24 FC            [12] 4081 	add	a,#0xfc
      001367 F5 81            [12] 4082 	mov	sp,a
      001369 D0 04            [24] 4083 	pop	ar4
      00136B D0 05            [24] 4084 	pop	ar5
      00136D D0 06            [24] 4085 	pop	ar6
      00136F D0 07            [24] 4086 	pop	ar7
      001371 E5 82            [12] 4087 	mov	a, dpl
      001373 24 FF            [12] 4088 	add	a,#0xff
      001375 92 00            [24] 4089 	mov	b0,c
      001377 50 38            [24] 4090 	jnc	00131$
                           0012C2  4091 	C$fuzzy.h$1065$1_0$62 ==.
                                   4092 ;	../../fuzzy.h:1065: ) {
      001379 C0 07            [24] 4093 	push	ar7
      00137B C0 06            [24] 4094 	push	ar6
      00137D C0 05            [24] 4095 	push	ar5
      00137F C0 04            [24] 4096 	push	ar4
      001381 C0 05            [24] 4097 	push	ar5
      001383 C0 06            [24] 4098 	push	ar6
      001385 C0 07            [24] 4099 	push	ar7
      001387 C0 04            [24] 4100 	push	ar4
      001389 E5 0E            [12] 4101 	mov	a,_bp
      00138B 24 FA            [12] 4102 	add	a,#0xfa
      00138D F8               [12] 4103 	mov	r0,a
      00138E 86 82            [24] 4104 	mov	dpl, @r0
      001390 08               [12] 4105 	inc	r0
      001391 86 83            [24] 4106 	mov	dph, @r0
      001393 08               [12] 4107 	inc	r0
      001394 86 F0            [24] 4108 	mov	b, @r0
      001396 08               [12] 4109 	inc	r0
      001397 E6               [12] 4110 	mov	a, @r0
      001398 12 24 07         [24] 4111 	lcall	___fslt
      00139B E5 81            [12] 4112 	mov	a,sp
      00139D 24 FC            [12] 4113 	add	a,#0xfc
      00139F F5 81            [12] 4114 	mov	sp,a
      0013A1 D0 04            [24] 4115 	pop	ar4
      0013A3 D0 05            [24] 4116 	pop	ar5
      0013A5 D0 06            [24] 4117 	pop	ar6
      0013A7 D0 07            [24] 4118 	pop	ar7
      0013A9 E5 82            [12] 4119 	mov	a, dpl
      0013AB 24 FF            [12] 4120 	add	a,#0xff
      0013AD 92 00            [24] 4121 	mov	b0,c
      0013AF 40 10            [24] 4122 	jc	00132$
      0013B1                       4123 00131$:
                           0012FA  4124 	C$fuzzy.h$1066$3_0$72 ==.
                                   4125 ;	../../fuzzy.h:1066: result = LEVEL_LO;
      0013B1 E5 0E            [12] 4126 	mov	a,_bp
      0013B3 24 05            [12] 4127 	add	a,#0x05
      0013B5 F8               [12] 4128 	mov	r0,a
      0013B6 E4               [12] 4129 	clr	a
      0013B7 F6               [12] 4130 	mov	@r0,a
      0013B8 08               [12] 4131 	inc	r0
      0013B9 F6               [12] 4132 	mov	@r0,a
      0013BA 08               [12] 4133 	inc	r0
      0013BB F6               [12] 4134 	mov	@r0,a
      0013BC 08               [12] 4135 	inc	r0
      0013BD F6               [12] 4136 	mov	@r0,a
      0013BE 02 16 00         [24] 4137 	ljmp	00144$
      0013C1                       4138 00132$:
                           00130A  4139 	C$fuzzy.h$1069$1_0$62 ==.
                                   4140 ;	../../fuzzy.h:1069: value >= parameter_2 &&
      0013C1 C0 07            [24] 4141 	push	ar7
      0013C3 C0 06            [24] 4142 	push	ar6
      0013C5 C0 05            [24] 4143 	push	ar5
      0013C7 C0 04            [24] 4144 	push	ar4
      0013C9 A8 0E            [24] 4145 	mov	r0,_bp
      0013CB 08               [12] 4146 	inc	r0
      0013CC E6               [12] 4147 	mov	a,@r0
      0013CD C0 E0            [24] 4148 	push	acc
      0013CF 08               [12] 4149 	inc	r0
      0013D0 E6               [12] 4150 	mov	a,@r0
      0013D1 C0 E0            [24] 4151 	push	acc
      0013D3 08               [12] 4152 	inc	r0
      0013D4 E6               [12] 4153 	mov	a,@r0
      0013D5 C0 E0            [24] 4154 	push	acc
      0013D7 08               [12] 4155 	inc	r0
      0013D8 E6               [12] 4156 	mov	a,@r0
      0013D9 C0 E0            [24] 4157 	push	acc
      0013DB E5 0E            [12] 4158 	mov	a,_bp
      0013DD 24 FA            [12] 4159 	add	a,#0xfa
      0013DF F8               [12] 4160 	mov	r0,a
      0013E0 86 82            [24] 4161 	mov	dpl, @r0
      0013E2 08               [12] 4162 	inc	r0
      0013E3 86 83            [24] 4163 	mov	dph, @r0
      0013E5 08               [12] 4164 	inc	r0
      0013E6 86 F0            [24] 4165 	mov	b, @r0
      0013E8 08               [12] 4166 	inc	r0
      0013E9 E6               [12] 4167 	mov	a, @r0
      0013EA 12 24 07         [24] 4168 	lcall	___fslt
      0013ED E5 81            [12] 4169 	mov	a,sp
      0013EF 24 FC            [12] 4170 	add	a,#0xfc
      0013F1 F5 81            [12] 4171 	mov	sp,a
      0013F3 D0 04            [24] 4172 	pop	ar4
      0013F5 D0 05            [24] 4173 	pop	ar5
      0013F7 D0 06            [24] 4174 	pop	ar6
      0013F9 D0 07            [24] 4175 	pop	ar7
      0013FB E5 82            [12] 4176 	mov	a, dpl
      0013FD 24 FF            [12] 4177 	add	a,#0xff
      0013FF 92 00            [24] 4178 	mov	b0,c
      001401 40 56            [24] 4179 	jc	00128$
                           00134C  4180 	C$fuzzy.h$1071$1_0$62 ==.
                                   4181 ;	../../fuzzy.h:1071: ) {
      001403 C0 07            [24] 4182 	push	ar7
      001405 C0 06            [24] 4183 	push	ar6
      001407 C0 05            [24] 4184 	push	ar5
      001409 C0 04            [24] 4185 	push	ar4
      00140B E5 0E            [12] 4186 	mov	a,_bp
      00140D 24 FA            [12] 4187 	add	a,#0xfa
      00140F F8               [12] 4188 	mov	r0,a
      001410 E6               [12] 4189 	mov	a,@r0
      001411 C0 E0            [24] 4190 	push	acc
      001413 08               [12] 4191 	inc	r0
      001414 E6               [12] 4192 	mov	a,@r0
      001415 C0 E0            [24] 4193 	push	acc
      001417 08               [12] 4194 	inc	r0
      001418 E6               [12] 4195 	mov	a,@r0
      001419 C0 E0            [24] 4196 	push	acc
      00141B 08               [12] 4197 	inc	r0
      00141C E6               [12] 4198 	mov	a,@r0
      00141D C0 E0            [24] 4199 	push	acc
      00141F E5 0E            [12] 4200 	mov	a,_bp
      001421 24 19            [12] 4201 	add	a,#0x19
      001423 F8               [12] 4202 	mov	r0,a
      001424 86 82            [24] 4203 	mov	dpl, @r0
      001426 08               [12] 4204 	inc	r0
      001427 86 83            [24] 4205 	mov	dph, @r0
      001429 08               [12] 4206 	inc	r0
      00142A 86 F0            [24] 4207 	mov	b, @r0
      00142C 08               [12] 4208 	inc	r0
      00142D E6               [12] 4209 	mov	a, @r0
      00142E 12 24 07         [24] 4210 	lcall	___fslt
      001431 E5 81            [12] 4211 	mov	a,sp
      001433 24 FC            [12] 4212 	add	a,#0xfc
      001435 F5 81            [12] 4213 	mov	sp,a
      001437 D0 04            [24] 4214 	pop	ar4
      001439 D0 05            [24] 4215 	pop	ar5
      00143B D0 06            [24] 4216 	pop	ar6
      00143D D0 07            [24] 4217 	pop	ar7
      00143F E5 82            [12] 4218 	mov	a, dpl
      001441 24 FF            [12] 4219 	add	a,#0xff
      001443 92 00            [24] 4220 	mov	b0,c
      001445 40 12            [24] 4221 	jc	00128$
                           001390  4222 	C$fuzzy.h$1072$3_0$73 ==.
                                   4223 ;	../../fuzzy.h:1072: result = LEVEL_HI;
      001447 E5 0E            [12] 4224 	mov	a,_bp
      001449 24 05            [12] 4225 	add	a,#0x05
      00144B F8               [12] 4226 	mov	r0,a
      00144C E4               [12] 4227 	clr	a
      00144D F6               [12] 4228 	mov	@r0,a
      00144E 08               [12] 4229 	inc	r0
      00144F F6               [12] 4230 	mov	@r0,a
      001450 08               [12] 4231 	inc	r0
      001451 76 80            [12] 4232 	mov	@r0,#0x80
      001453 08               [12] 4233 	inc	r0
      001454 76 3F            [12] 4234 	mov	@r0,#0x3f
      001456 02 16 00         [24] 4235 	ljmp	00144$
      001459                       4236 00128$:
                           0013A2  4237 	C$fuzzy.h$1074$1_0$62 ==.
                                   4238 ;	../../fuzzy.h:1074: else if (value < parameter_2) {
      001459 C0 07            [24] 4239 	push	ar7
      00145B C0 06            [24] 4240 	push	ar6
      00145D C0 05            [24] 4241 	push	ar5
      00145F C0 04            [24] 4242 	push	ar4
      001461 A8 0E            [24] 4243 	mov	r0,_bp
      001463 08               [12] 4244 	inc	r0
      001464 E6               [12] 4245 	mov	a,@r0
      001465 C0 E0            [24] 4246 	push	acc
      001467 08               [12] 4247 	inc	r0
      001468 E6               [12] 4248 	mov	a,@r0
      001469 C0 E0            [24] 4249 	push	acc
      00146B 08               [12] 4250 	inc	r0
      00146C E6               [12] 4251 	mov	a,@r0
      00146D C0 E0            [24] 4252 	push	acc
      00146F 08               [12] 4253 	inc	r0
      001470 E6               [12] 4254 	mov	a,@r0
      001471 C0 E0            [24] 4255 	push	acc
      001473 E5 0E            [12] 4256 	mov	a,_bp
      001475 24 FA            [12] 4257 	add	a,#0xfa
      001477 F8               [12] 4258 	mov	r0,a
      001478 86 82            [24] 4259 	mov	dpl, @r0
      00147A 08               [12] 4260 	inc	r0
      00147B 86 83            [24] 4261 	mov	dph, @r0
      00147D 08               [12] 4262 	inc	r0
      00147E 86 F0            [24] 4263 	mov	b, @r0
      001480 08               [12] 4264 	inc	r0
      001481 E6               [12] 4265 	mov	a, @r0
      001482 12 24 07         [24] 4266 	lcall	___fslt
      001485 AB 82            [24] 4267 	mov	r3, dpl
      001487 E5 81            [12] 4268 	mov	a,sp
      001489 24 FC            [12] 4269 	add	a,#0xfc
      00148B F5 81            [12] 4270 	mov	sp,a
      00148D D0 04            [24] 4271 	pop	ar4
      00148F D0 05            [24] 4272 	pop	ar5
      001491 D0 06            [24] 4273 	pop	ar6
      001493 D0 07            [24] 4274 	pop	ar7
      001495 EB               [12] 4275 	mov	a,r3
      001496 70 03            [24] 4276 	jnz	00287$
      001498 02 15 4F         [24] 4277 	ljmp	00125$
      00149B                       4278 00287$:
                           0013E4  4279 	C$fuzzy.h$1076$1_0$62 ==.
                                   4280 ;	../../fuzzy.h:1076: (value - parameter_1) /
      00149B E5 0E            [12] 4281 	mov	a,_bp
      00149D 24 09            [12] 4282 	add	a,#0x09
      00149F F8               [12] 4283 	mov	r0,a
      0014A0 E6               [12] 4284 	mov	a,@r0
      0014A1 C0 E0            [24] 4285 	push	acc
      0014A3 08               [12] 4286 	inc	r0
      0014A4 E6               [12] 4287 	mov	a,@r0
      0014A5 C0 E0            [24] 4288 	push	acc
      0014A7 08               [12] 4289 	inc	r0
      0014A8 E6               [12] 4290 	mov	a,@r0
      0014A9 C0 E0            [24] 4291 	push	acc
      0014AB 08               [12] 4292 	inc	r0
      0014AC E6               [12] 4293 	mov	a,@r0
      0014AD C0 E0            [24] 4294 	push	acc
                           0013F8  4295 	C$fuzzy.h$1077$1_0$62 ==.
                                   4296 ;	../../fuzzy.h:1077: (parameter_2 - parameter_1);
      0014AF E5 0E            [12] 4297 	mov	a,_bp
      0014B1 24 FA            [12] 4298 	add	a,#0xfa
      0014B3 F8               [12] 4299 	mov	r0,a
      0014B4 86 82            [24] 4300 	mov	dpl, @r0
      0014B6 08               [12] 4301 	inc	r0
      0014B7 86 83            [24] 4302 	mov	dph, @r0
      0014B9 08               [12] 4303 	inc	r0
      0014BA 86 F0            [24] 4304 	mov	b, @r0
      0014BC 08               [12] 4305 	inc	r0
      0014BD E6               [12] 4306 	mov	a, @r0
      0014BE 12 22 CC         [24] 4307 	lcall	___fssub
      0014C1 AF 82            [24] 4308 	mov	r7, dpl
      0014C3 AE 83            [24] 4309 	mov	r6, dph
      0014C5 AD F0            [24] 4310 	mov	r5, b
      0014C7 FC               [12] 4311 	mov	r4, a
      0014C8 E5 81            [12] 4312 	mov	a,sp
      0014CA 24 FC            [12] 4313 	add	a,#0xfc
      0014CC F5 81            [12] 4314 	mov	sp,a
      0014CE C0 07            [24] 4315 	push	ar7
      0014D0 C0 06            [24] 4316 	push	ar6
      0014D2 C0 05            [24] 4317 	push	ar5
      0014D4 C0 04            [24] 4318 	push	ar4
      0014D6 E5 0E            [12] 4319 	mov	a,_bp
      0014D8 24 09            [12] 4320 	add	a,#0x09
      0014DA F8               [12] 4321 	mov	r0,a
      0014DB E6               [12] 4322 	mov	a,@r0
      0014DC C0 E0            [24] 4323 	push	acc
      0014DE 08               [12] 4324 	inc	r0
      0014DF E6               [12] 4325 	mov	a,@r0
      0014E0 C0 E0            [24] 4326 	push	acc
      0014E2 08               [12] 4327 	inc	r0
      0014E3 E6               [12] 4328 	mov	a,@r0
      0014E4 C0 E0            [24] 4329 	push	acc
      0014E6 08               [12] 4330 	inc	r0
      0014E7 E6               [12] 4331 	mov	a,@r0
      0014E8 C0 E0            [24] 4332 	push	acc
      0014EA A8 0E            [24] 4333 	mov	r0,_bp
      0014EC 08               [12] 4334 	inc	r0
      0014ED 86 82            [24] 4335 	mov	dpl, @r0
      0014EF 08               [12] 4336 	inc	r0
      0014F0 86 83            [24] 4337 	mov	dph, @r0
      0014F2 08               [12] 4338 	inc	r0
      0014F3 86 F0            [24] 4339 	mov	b, @r0
      0014F5 08               [12] 4340 	inc	r0
      0014F6 E6               [12] 4341 	mov	a, @r0
      0014F7 12 22 CC         [24] 4342 	lcall	___fssub
      0014FA C8               [12] 4343 	xch	a,r0
      0014FB E5 0E            [12] 4344 	mov	a,_bp
      0014FD 24 09            [12] 4345 	add	a,#0x09
      0014FF C8               [12] 4346 	xch	a,r0
      001500 A6 82            [24] 4347 	mov	@r0, dpl
      001502 08               [12] 4348 	inc	r0
      001503 A6 83            [24] 4349 	mov	@r0, dph
      001505 08               [12] 4350 	inc	r0
      001506 A6 F0            [24] 4351 	mov	@r0, b
      001508 08               [12] 4352 	inc	r0
      001509 F6               [12] 4353 	mov	@r0,a
      00150A E5 81            [12] 4354 	mov	a,sp
      00150C 24 FC            [12] 4355 	add	a,#0xfc
      00150E F5 81            [12] 4356 	mov	sp,a
      001510 D0 04            [24] 4357 	pop	ar4
      001512 D0 05            [24] 4358 	pop	ar5
      001514 D0 06            [24] 4359 	pop	ar6
      001516 D0 07            [24] 4360 	pop	ar7
      001518 E5 0E            [12] 4361 	mov	a,_bp
      00151A 24 09            [12] 4362 	add	a,#0x09
      00151C F8               [12] 4363 	mov	r0,a
      00151D E6               [12] 4364 	mov	a,@r0
      00151E C0 E0            [24] 4365 	push	acc
      001520 08               [12] 4366 	inc	r0
      001521 E6               [12] 4367 	mov	a,@r0
      001522 C0 E0            [24] 4368 	push	acc
      001524 08               [12] 4369 	inc	r0
      001525 E6               [12] 4370 	mov	a,@r0
      001526 C0 E0            [24] 4371 	push	acc
      001528 08               [12] 4372 	inc	r0
      001529 E6               [12] 4373 	mov	a,@r0
      00152A C0 E0            [24] 4374 	push	acc
      00152C 8F 82            [24] 4375 	mov	dpl, r7
      00152E 8E 83            [24] 4376 	mov	dph, r6
      001530 8D F0            [24] 4377 	mov	b, r5
      001532 EC               [12] 4378 	mov	a, r4
      001533 12 25 70         [24] 4379 	lcall	___fsdiv
      001536 C8               [12] 4380 	xch	a,r0
      001537 E5 0E            [12] 4381 	mov	a,_bp
      001539 24 05            [12] 4382 	add	a,#0x05
      00153B C8               [12] 4383 	xch	a,r0
      00153C A6 82            [24] 4384 	mov	@r0, dpl
      00153E 08               [12] 4385 	inc	r0
      00153F A6 83            [24] 4386 	mov	@r0, dph
      001541 08               [12] 4387 	inc	r0
      001542 A6 F0            [24] 4388 	mov	@r0, b
      001544 08               [12] 4389 	inc	r0
      001545 F6               [12] 4390 	mov	@r0,a
      001546 E5 81            [12] 4391 	mov	a,sp
      001548 24 FC            [12] 4392 	add	a,#0xfc
      00154A F5 81            [12] 4393 	mov	sp,a
      00154C 02 16 00         [24] 4394 	ljmp	00144$
      00154F                       4395 00125$:
                           001498  4396 	C$fuzzy.h$1081$1_0$62 ==.
                                   4397 ;	../../fuzzy.h:1081: (parameter_4 - value) /
      00154F C0 07            [24] 4398 	push	ar7
      001551 C0 06            [24] 4399 	push	ar6
      001553 C0 05            [24] 4400 	push	ar5
      001555 C0 04            [24] 4401 	push	ar4
      001557 E5 0E            [12] 4402 	mov	a,_bp
      001559 24 FA            [12] 4403 	add	a,#0xfa
      00155B F8               [12] 4404 	mov	r0,a
      00155C E6               [12] 4405 	mov	a,@r0
      00155D C0 E0            [24] 4406 	push	acc
      00155F 08               [12] 4407 	inc	r0
      001560 E6               [12] 4408 	mov	a,@r0
      001561 C0 E0            [24] 4409 	push	acc
      001563 08               [12] 4410 	inc	r0
      001564 E6               [12] 4411 	mov	a,@r0
      001565 C0 E0            [24] 4412 	push	acc
      001567 08               [12] 4413 	inc	r0
      001568 E6               [12] 4414 	mov	a,@r0
      001569 C0 E0            [24] 4415 	push	acc
                           0014B4  4416 	C$fuzzy.h$1082$1_0$62 ==.
                                   4417 ;	../../fuzzy.h:1082: (parameter_4 - parameter_3);
      00156B 8D 82            [24] 4418 	mov	dpl, r5
      00156D 8E 83            [24] 4419 	mov	dph, r6
      00156F 8F F0            [24] 4420 	mov	b, r7
      001571 EC               [12] 4421 	mov	a, r4
      001572 12 22 CC         [24] 4422 	lcall	___fssub
      001575 C8               [12] 4423 	xch	a,r0
      001576 E5 0E            [12] 4424 	mov	a,_bp
      001578 24 0D            [12] 4425 	add	a,#0x0d
      00157A C8               [12] 4426 	xch	a,r0
      00157B A6 82            [24] 4427 	mov	@r0, dpl
      00157D 08               [12] 4428 	inc	r0
      00157E A6 83            [24] 4429 	mov	@r0, dph
      001580 08               [12] 4430 	inc	r0
      001581 A6 F0            [24] 4431 	mov	@r0, b
      001583 08               [12] 4432 	inc	r0
      001584 F6               [12] 4433 	mov	@r0,a
      001585 E5 81            [12] 4434 	mov	a,sp
      001587 24 FC            [12] 4435 	add	a,#0xfc
      001589 F5 81            [12] 4436 	mov	sp,a
      00158B D0 04            [24] 4437 	pop	ar4
      00158D D0 05            [24] 4438 	pop	ar5
      00158F D0 06            [24] 4439 	pop	ar6
      001591 D0 07            [24] 4440 	pop	ar7
      001593 E5 0E            [12] 4441 	mov	a,_bp
      001595 24 19            [12] 4442 	add	a,#0x19
      001597 F8               [12] 4443 	mov	r0,a
      001598 E6               [12] 4444 	mov	a,@r0
      001599 C0 E0            [24] 4445 	push	acc
      00159B 08               [12] 4446 	inc	r0
      00159C E6               [12] 4447 	mov	a,@r0
      00159D C0 E0            [24] 4448 	push	acc
      00159F 08               [12] 4449 	inc	r0
      0015A0 E6               [12] 4450 	mov	a,@r0
      0015A1 C0 E0            [24] 4451 	push	acc
      0015A3 08               [12] 4452 	inc	r0
      0015A4 E6               [12] 4453 	mov	a,@r0
      0015A5 C0 E0            [24] 4454 	push	acc
      0015A7 8D 82            [24] 4455 	mov	dpl, r5
      0015A9 8E 83            [24] 4456 	mov	dph, r6
      0015AB 8F F0            [24] 4457 	mov	b, r7
      0015AD EC               [12] 4458 	mov	a, r4
      0015AE 12 22 CC         [24] 4459 	lcall	___fssub
      0015B1 AC 82            [24] 4460 	mov	r4, dpl
      0015B3 AD 83            [24] 4461 	mov	r5, dph
      0015B5 AE F0            [24] 4462 	mov	r6, b
      0015B7 FF               [12] 4463 	mov	r7, a
      0015B8 E5 81            [12] 4464 	mov	a,sp
      0015BA 24 FC            [12] 4465 	add	a,#0xfc
      0015BC F5 81            [12] 4466 	mov	sp,a
      0015BE C0 04            [24] 4467 	push	ar4
      0015C0 C0 05            [24] 4468 	push	ar5
      0015C2 C0 06            [24] 4469 	push	ar6
      0015C4 C0 07            [24] 4470 	push	ar7
                           00150F  4471 	C$fuzzy.h$1084$1_0$62 ==.
                                   4472 ;	../../fuzzy.h:1084: break;
      0015C6 E5 0E            [12] 4473 	mov	a,_bp
      0015C8 24 0D            [12] 4474 	add	a,#0x0d
      0015CA F8               [12] 4475 	mov	r0,a
      0015CB 86 82            [24] 4476 	mov	dpl, @r0
      0015CD 08               [12] 4477 	inc	r0
      0015CE 86 83            [24] 4478 	mov	dph, @r0
      0015D0 08               [12] 4479 	inc	r0
      0015D1 86 F0            [24] 4480 	mov	b, @r0
      0015D3 08               [12] 4481 	inc	r0
      0015D4 E6               [12] 4482 	mov	a, @r0
      0015D5 12 25 70         [24] 4483 	lcall	___fsdiv
      0015D8 C8               [12] 4484 	xch	a,r0
      0015D9 E5 0E            [12] 4485 	mov	a,_bp
      0015DB 24 05            [12] 4486 	add	a,#0x05
      0015DD C8               [12] 4487 	xch	a,r0
      0015DE A6 82            [24] 4488 	mov	@r0, dpl
      0015E0 08               [12] 4489 	inc	r0
      0015E1 A6 83            [24] 4490 	mov	@r0, dph
      0015E3 08               [12] 4491 	inc	r0
      0015E4 A6 F0            [24] 4492 	mov	@r0, b
      0015E6 08               [12] 4493 	inc	r0
      0015E7 F6               [12] 4494 	mov	@r0,a
      0015E8 E5 81            [12] 4495 	mov	a,sp
      0015EA 24 FC            [12] 4496 	add	a,#0xfc
      0015EC F5 81            [12] 4497 	mov	sp,a
                           001537  4498 	C$fuzzy.h$1230$2_0$64 ==.
                                   4499 ;	../../fuzzy.h:1230: case FUZZY_SHAPE_SIGMOID:
      0015EE 80 10            [24] 4500 	sjmp	00144$
      0015F0                       4501 00142$:
                           001539  4502 	C$fuzzy.h$1231$2_0$64 ==.
                                   4503 ;	../../fuzzy.h:1231: return LEVEL_LO;
      0015F0 90 00 00         [24] 4504 	mov	dptr,#0x0000
      0015F3 E4               [12] 4505 	clr	a
      0015F4 F5 F0            [12] 4506 	mov	b,a
                           00153F  4507 	C$fuzzy.h$1235$2_0$64 ==.
                                   4508 ;	../../fuzzy.h:1235: default:
      0015F6 80 32            [24] 4509 	sjmp	00145$
      0015F8                       4510 00143$:
                           001541  4511 	C$fuzzy.h$1236$2_0$64 ==.
                                   4512 ;	../../fuzzy.h:1236: return LEVEL_LO;
      0015F8 90 00 00         [24] 4513 	mov	dptr,#0x0000
      0015FB E4               [12] 4514 	clr	a
      0015FC F5 F0            [12] 4515 	mov	b,a
                           001547  4516 	C$fuzzy.h$1237$1_0$62 ==.
                                   4517 ;	../../fuzzy.h:1237: }
      0015FE 80 2A            [24] 4518 	sjmp	00145$
      001600                       4519 00144$:
                           001549  4520 	C$fuzzy.h$1240$1_0$62 ==.
                                   4521 ;	../../fuzzy.h:1240: result,
      001600 E5 0E            [12] 4522 	mov	a,_bp
      001602 24 F9            [12] 4523 	add	a,#0xf9
      001604 F8               [12] 4524 	mov	r0,a
      001605 E6               [12] 4525 	mov	a,@r0
      001606 C0 E0            [24] 4526 	push	acc
      001608 E5 0E            [12] 4527 	mov	a,_bp
      00160A 24 05            [12] 4528 	add	a,#0x05
      00160C F8               [12] 4529 	mov	r0,a
      00160D 86 82            [24] 4530 	mov	dpl, @r0
      00160F 08               [12] 4531 	inc	r0
      001610 86 83            [24] 4532 	mov	dph, @r0
      001612 08               [12] 4533 	inc	r0
      001613 86 F0            [24] 4534 	mov	b, @r0
      001615 08               [12] 4535 	inc	r0
      001616 E6               [12] 4536 	mov	a, @r0
      001617 12 01 66         [24] 4537 	lcall	_fuzzy_apply_hedge
      00161A AC 82            [24] 4538 	mov	r4, dpl
      00161C AD 83            [24] 4539 	mov	r5, dph
      00161E AE F0            [24] 4540 	mov	r6, b
      001620 FF               [12] 4541 	mov	r7, a
      001621 15 81            [12] 4542 	dec	sp
      001623 8C 82            [24] 4543 	mov	dpl, r4
      001625 8D 83            [24] 4544 	mov	dph, r5
      001627 8E F0            [24] 4545 	mov	b, r6
      001629 EF               [12] 4546 	mov	a, r7
      00162A                       4547 00145$:
                           001573  4548 	C$fuzzy.h$1243$1_0$62 ==.
                                   4549 ;	../../fuzzy.h:1243: }
      00162A 85 0E 81         [24] 4550 	mov	sp,_bp
      00162D D0 0E            [24] 4551 	pop	_bp
                           001578  4552 	C$fuzzy.h$1243$1_0$62 ==.
                           001578  4553 	XG$fuzzy_function_array$0$0 ==.
      00162F 22               [24] 4554 	ret
                                   4555 ;------------------------------------------------------------
                                   4556 ;Allocation info for local variables in function 'fuzzy_rules_create'
                                   4557 ;------------------------------------------------------------
                                   4558 ;rules         Allocated to registers r5 r6 r7 
                                   4559 ;------------------------------------------------------------
                           001579  4560 	G$fuzzy_rules_create$0$0 ==.
                           001579  4561 	C$fuzzy.h$1246$1_0$77 ==.
                                   4562 ;	../../fuzzy.h:1246: void fuzzy_rules_create(
                                   4563 ;	-----------------------------------------
                                   4564 ;	 function fuzzy_rules_create
                                   4565 ;	-----------------------------------------
      001630                       4566 _fuzzy_rules_create:
      001630 AD 82            [24] 4567 	mov	r5, dpl
      001632 AE 83            [24] 4568 	mov	r6, dph
      001634 AF F0            [24] 4569 	mov	r7, b
                           00157F  4570 	C$fuzzy.h$1250$1_0$77 ==.
                                   4571 ;	../../fuzzy.h:1250: if (rules == NULL) {
      001636 ED               [12] 4572 	mov	a,r5
      001637 4E               [12] 4573 	orl	a,r6
      001638 70 02            [24] 4574 	jnz	00102$
                           001583  4575 	C$fuzzy.h$1251$2_0$78 ==.
                                   4576 ;	../../fuzzy.h:1251: return;
      00163A 80 15            [24] 4577 	sjmp	00103$
      00163C                       4578 00102$:
                           001585  4579 	C$fuzzy.h$1254$1_0$77 ==.
                                   4580 ;	../../fuzzy.h:1254: rules->count = 0;
      00163C 74 48            [12] 4581 	mov	a,#0x48
      00163E 2D               [12] 4582 	add	a, r5
      00163F FD               [12] 4583 	mov	r5,a
      001640 E4               [12] 4584 	clr	a
      001641 3E               [12] 4585 	addc	a, r6
      001642 FE               [12] 4586 	mov	r6,a
      001643 8D 82            [24] 4587 	mov	dpl,r5
      001645 8E 83            [24] 4588 	mov	dph,r6
      001647 8F F0            [24] 4589 	mov	b,r7
      001649 E4               [12] 4590 	clr	a
      00164A 12 23 EC         [24] 4591 	lcall	__gptrput
      00164D A3               [24] 4592 	inc	dptr
      00164E 12 23 EC         [24] 4593 	lcall	__gptrput
      001651                       4594 00103$:
                           00159A  4595 	C$fuzzy.h$1255$1_0$77 ==.
                                   4596 ;	../../fuzzy.h:1255: }
                           00159A  4597 	C$fuzzy.h$1255$1_0$77 ==.
                           00159A  4598 	XG$fuzzy_rules_create$0$0 ==.
      001651 22               [24] 4599 	ret
                                   4600 ;------------------------------------------------------------
                                   4601 ;Allocation info for local variables in function 'fuzzy_rules_add'
                                   4602 ;------------------------------------------------------------
                                   4603 ;name          Allocated to stack - _bp -5 +3 
                                   4604 ;value         Allocated to stack - _bp -9 +4 
                                   4605 ;output_function Allocated to stack - _bp -11 +2 
                                   4606 ;rules         Allocated to registers r2 r3 r4 
                                   4607 ;index         Allocated to registers 
                                   4608 ;sloc0         Allocated to stack - _bp +1 +2 
                                   4609 ;sloc1         Allocated to stack - _bp +3 +3 
                                   4610 ;sloc2         Allocated to stack - _bp +6 +3 
                                   4611 ;sloc3         Allocated to stack - _bp +9 +3 
                                   4612 ;------------------------------------------------------------
                           00159B  4613 	G$fuzzy_rules_add$0$0 ==.
                           00159B  4614 	C$fuzzy.h$1258$1_0$80 ==.
                                   4615 ;	../../fuzzy.h:1258: bool fuzzy_rules_add(
                                   4616 ;	-----------------------------------------
                                   4617 ;	 function fuzzy_rules_add
                                   4618 ;	-----------------------------------------
      001652                       4619 _fuzzy_rules_add:
      001652 C0 0E            [24] 4620 	push	_bp
      001654 E5 81            [12] 4621 	mov	a,sp
      001656 F5 0E            [12] 4622 	mov	_bp,a
      001658 24 0B            [12] 4623 	add	a,#0x0b
      00165A F5 81            [12] 4624 	mov	sp,a
      00165C AA 82            [24] 4625 	mov	r2, dpl
      00165E AB 83            [24] 4626 	mov	r3, dph
      001660 AC F0            [24] 4627 	mov	r4, b
                           0015AB  4628 	C$fuzzy.h$1268$1_0$80 ==.
                                   4629 ;	../../fuzzy.h:1268: rules == NULL ||
      001662 EA               [12] 4630 	mov	a,r2
      001663 4B               [12] 4631 	orl	a,r3
      001664 60 0A            [24] 4632 	jz	00101$
                           0015AF  4633 	C$fuzzy.h$1269$1_0$80 ==.
                                   4634 ;	../../fuzzy.h:1269: output_function == NULL
      001666 E5 0E            [12] 4635 	mov	a,_bp
      001668 24 F5            [12] 4636 	add	a,#0xf5
      00166A F8               [12] 4637 	mov	r0,a
      00166B E6               [12] 4638 	mov	a,@r0
      00166C 08               [12] 4639 	inc	r0
      00166D 46               [12] 4640 	orl	a,@r0
      00166E 70 06            [24] 4641 	jnz	00102$
      001670                       4642 00101$:
                           0015B9  4643 	C$fuzzy.h$1271$2_0$81 ==.
                                   4644 ;	../../fuzzy.h:1271: return false;
      001670 75 82 00         [24] 4645 	mov	dpl, #0x00
      001673 02 17 B0         [24] 4646 	ljmp	00106$
      001676                       4647 00102$:
                           0015BF  4648 	C$fuzzy.h$1274$1_0$80 ==.
                                   4649 ;	../../fuzzy.h:1274: if (rules->count >= FUZZY_MAX_RULES) {
      001676 E5 0E            [12] 4650 	mov	a,_bp
      001678 24 09            [12] 4651 	add	a,#0x09
      00167A F8               [12] 4652 	mov	r0,a
      00167B 74 48            [12] 4653 	mov	a,#0x48
      00167D 2A               [12] 4654 	add	a, r2
      00167E F6               [12] 4655 	mov	@r0,a
      00167F E4               [12] 4656 	clr	a
      001680 3B               [12] 4657 	addc	a, r3
      001681 08               [12] 4658 	inc	r0
      001682 F6               [12] 4659 	mov	@r0,a
      001683 08               [12] 4660 	inc	r0
      001684 A6 04            [24] 4661 	mov	@r0,ar4
      001686 E5 0E            [12] 4662 	mov	a,_bp
      001688 24 09            [12] 4663 	add	a,#0x09
      00168A F8               [12] 4664 	mov	r0,a
      00168B 86 82            [24] 4665 	mov	dpl,@r0
      00168D 08               [12] 4666 	inc	r0
      00168E 86 83            [24] 4667 	mov	dph,@r0
      001690 08               [12] 4668 	inc	r0
      001691 86 F0            [24] 4669 	mov	b,@r0
      001693 12 26 33         [24] 4670 	lcall	__gptrget
      001696 FF               [12] 4671 	mov	r7,a
      001697 A3               [24] 4672 	inc	dptr
      001698 12 26 33         [24] 4673 	lcall	__gptrget
      00169B FE               [12] 4674 	mov	r6,a
      00169C C3               [12] 4675 	clr	c
      00169D EF               [12] 4676 	mov	a,r7
      00169E 94 08            [12] 4677 	subb	a,#0x08
      0016A0 EE               [12] 4678 	mov	a,r6
      0016A1 94 00            [12] 4679 	subb	a,#0x00
      0016A3 40 06            [24] 4680 	jc	00105$
                           0015EE  4681 	C$fuzzy.h$1275$2_0$82 ==.
                                   4682 ;	../../fuzzy.h:1275: return false;
      0016A5 75 82 00         [24] 4683 	mov	dpl, #0x00
      0016A8 02 17 B0         [24] 4684 	ljmp	00106$
      0016AB                       4685 00105$:
                           0015F4  4686 	C$fuzzy.h$1281$1_0$80 ==.
                                   4687 ;	../../fuzzy.h:1281: rules->rules[index].name =
      0016AB C0 04            [24] 4688 	push	ar4
      0016AD C0 03            [24] 4689 	push	ar3
      0016AF C0 02            [24] 4690 	push	ar2
      0016B1 C0 07            [24] 4691 	push	ar7
      0016B3 C0 06            [24] 4692 	push	ar6
      0016B5 90 00 09         [24] 4693 	mov	dptr,#0x0009
      0016B8 12 24 37         [24] 4694 	lcall	__mulint
      0016BB A8 0E            [24] 4695 	mov	r0,_bp
      0016BD 08               [12] 4696 	inc	r0
      0016BE A6 82            [24] 4697 	mov	@r0, dpl
      0016C0 08               [12] 4698 	inc	r0
      0016C1 A6 83            [24] 4699 	mov	@r0, dph
      0016C3 15 81            [12] 4700 	dec	sp
      0016C5 15 81            [12] 4701 	dec	sp
      0016C7 D0 02            [24] 4702 	pop	ar2
      0016C9 D0 03            [24] 4703 	pop	ar3
      0016CB D0 04            [24] 4704 	pop	ar4
      0016CD A8 0E            [24] 4705 	mov	r0,_bp
      0016CF 08               [12] 4706 	inc	r0
      0016D0 E6               [12] 4707 	mov	a,@r0
      0016D1 2A               [12] 4708 	add	a, r2
      0016D2 FD               [12] 4709 	mov	r5,a
      0016D3 08               [12] 4710 	inc	r0
      0016D4 E6               [12] 4711 	mov	a,@r0
      0016D5 3B               [12] 4712 	addc	a, r3
      0016D6 FE               [12] 4713 	mov	r6,a
      0016D7 8C 07            [24] 4714 	mov	ar7,r4
      0016D9 8D 82            [24] 4715 	mov	dpl,r5
      0016DB 8E 83            [24] 4716 	mov	dph,r6
      0016DD 8F F0            [24] 4717 	mov	b,r7
      0016DF E5 0E            [12] 4718 	mov	a,_bp
      0016E1 24 FB            [12] 4719 	add	a,#0xfb
      0016E3 F8               [12] 4720 	mov	r0,a
      0016E4 E6               [12] 4721 	mov	a,@r0
      0016E5 12 23 EC         [24] 4722 	lcall	__gptrput
      0016E8 A3               [24] 4723 	inc	dptr
      0016E9 08               [12] 4724 	inc	r0
      0016EA E6               [12] 4725 	mov	a,@r0
      0016EB 12 23 EC         [24] 4726 	lcall	__gptrput
      0016EE A3               [24] 4727 	inc	dptr
      0016EF 08               [12] 4728 	inc	r0
      0016F0 E6               [12] 4729 	mov	a,@r0
      0016F1 12 23 EC         [24] 4730 	lcall	__gptrput
                           00163D  4731 	C$fuzzy.h$1284$1_0$80 ==.
                                   4732 ;	../../fuzzy.h:1284: rules->rules[index].value =
      0016F4 A8 0E            [24] 4733 	mov	r0,_bp
      0016F6 08               [12] 4734 	inc	r0
      0016F7 E5 0E            [12] 4735 	mov	a,_bp
      0016F9 24 03            [12] 4736 	add	a,#0x03
      0016FB F9               [12] 4737 	mov	r1,a
      0016FC E6               [12] 4738 	mov	a,@r0
      0016FD 2A               [12] 4739 	add	a, r2
      0016FE F7               [12] 4740 	mov	@r1,a
      0016FF 08               [12] 4741 	inc	r0
      001700 E6               [12] 4742 	mov	a,@r0
      001701 3B               [12] 4743 	addc	a, r3
      001702 09               [12] 4744 	inc	r1
      001703 F7               [12] 4745 	mov	@r1,a
      001704 09               [12] 4746 	inc	r1
      001705 A7 04            [24] 4747 	mov	@r1,ar4
      001707 E5 0E            [12] 4748 	mov	a,_bp
      001709 24 03            [12] 4749 	add	a,#0x03
      00170B F8               [12] 4750 	mov	r0,a
      00170C E5 0E            [12] 4751 	mov	a,_bp
      00170E 24 06            [12] 4752 	add	a,#0x06
      001710 F9               [12] 4753 	mov	r1,a
      001711 74 03            [12] 4754 	mov	a,#0x03
      001713 26               [12] 4755 	add	a, @r0
      001714 F7               [12] 4756 	mov	@r1,a
      001715 E4               [12] 4757 	clr	a
      001716 08               [12] 4758 	inc	r0
      001717 36               [12] 4759 	addc	a, @r0
      001718 09               [12] 4760 	inc	r1
      001719 F7               [12] 4761 	mov	@r1,a
      00171A 08               [12] 4762 	inc	r0
      00171B E6               [12] 4763 	mov	a,@r0
      00171C 09               [12] 4764 	inc	r1
      00171D F7               [12] 4765 	mov	@r1,a
                           001667  4766 	C$fuzzy.h$1285$1_0$80 ==.
                                   4767 ;	../../fuzzy.h:1285: fuzzy_clamp(value);
      00171E E5 0E            [12] 4768 	mov	a,_bp
      001720 24 F7            [12] 4769 	add	a,#0xf7
      001722 F8               [12] 4770 	mov	r0,a
      001723 86 82            [24] 4771 	mov	dpl, @r0
      001725 08               [12] 4772 	inc	r0
      001726 86 83            [24] 4773 	mov	dph, @r0
      001728 08               [12] 4774 	inc	r0
      001729 86 F0            [24] 4775 	mov	b, @r0
      00172B 08               [12] 4776 	inc	r0
      00172C E6               [12] 4777 	mov	a, @r0
      00172D 12 00 B7         [24] 4778 	lcall	_fuzzy_clamp
      001730 AD 82            [24] 4779 	mov	r5, dpl
      001732 AE 83            [24] 4780 	mov	r6, dph
      001734 AC F0            [24] 4781 	mov	r4, b
      001736 FF               [12] 4782 	mov	r7, a
      001737 E5 0E            [12] 4783 	mov	a,_bp
      001739 24 06            [12] 4784 	add	a,#0x06
      00173B F8               [12] 4785 	mov	r0,a
      00173C 86 82            [24] 4786 	mov	dpl,@r0
      00173E 08               [12] 4787 	inc	r0
      00173F 86 83            [24] 4788 	mov	dph,@r0
      001741 08               [12] 4789 	inc	r0
      001742 86 F0            [24] 4790 	mov	b,@r0
      001744 ED               [12] 4791 	mov	a,r5
      001745 12 23 EC         [24] 4792 	lcall	__gptrput
      001748 A3               [24] 4793 	inc	dptr
      001749 EE               [12] 4794 	mov	a,r6
      00174A 12 23 EC         [24] 4795 	lcall	__gptrput
      00174D A3               [24] 4796 	inc	dptr
      00174E EC               [12] 4797 	mov	a,r4
      00174F 12 23 EC         [24] 4798 	lcall	__gptrput
      001752 A3               [24] 4799 	inc	dptr
      001753 EF               [12] 4800 	mov	a,r7
      001754 12 23 EC         [24] 4801 	lcall	__gptrput
                           0016A0  4802 	C$fuzzy.h$1287$1_0$80 ==.
                                   4803 ;	../../fuzzy.h:1287: rules->rules[index].output_function =
      001757 E5 0E            [12] 4804 	mov	a,_bp
      001759 24 03            [12] 4805 	add	a,#0x03
      00175B F8               [12] 4806 	mov	r0,a
      00175C 74 07            [12] 4807 	mov	a,#0x07
      00175E 26               [12] 4808 	add	a, @r0
      00175F FD               [12] 4809 	mov	r5,a
      001760 E4               [12] 4810 	clr	a
      001761 08               [12] 4811 	inc	r0
      001762 36               [12] 4812 	addc	a, @r0
      001763 FE               [12] 4813 	mov	r6,a
      001764 08               [12] 4814 	inc	r0
      001765 86 07            [24] 4815 	mov	ar7,@r0
      001767 8D 82            [24] 4816 	mov	dpl,r5
      001769 8E 83            [24] 4817 	mov	dph,r6
      00176B 8F F0            [24] 4818 	mov	b,r7
      00176D E5 0E            [12] 4819 	mov	a,_bp
      00176F 24 F5            [12] 4820 	add	a,#0xf5
      001771 F8               [12] 4821 	mov	r0,a
      001772 E6               [12] 4822 	mov	a,@r0
      001773 12 23 EC         [24] 4823 	lcall	__gptrput
      001776 A3               [24] 4824 	inc	dptr
      001777 08               [12] 4825 	inc	r0
      001778 E6               [12] 4826 	mov	a,@r0
      001779 12 23 EC         [24] 4827 	lcall	__gptrput
                           0016C5  4828 	C$fuzzy.h$1290$1_0$80 ==.
                                   4829 ;	../../fuzzy.h:1290: rules->count++;
      00177C E5 0E            [12] 4830 	mov	a,_bp
      00177E 24 09            [12] 4831 	add	a,#0x09
      001780 F8               [12] 4832 	mov	r0,a
      001781 86 82            [24] 4833 	mov	dpl,@r0
      001783 08               [12] 4834 	inc	r0
      001784 86 83            [24] 4835 	mov	dph,@r0
      001786 08               [12] 4836 	inc	r0
      001787 86 F0            [24] 4837 	mov	b,@r0
      001789 12 26 33         [24] 4838 	lcall	__gptrget
      00178C FE               [12] 4839 	mov	r6,a
      00178D A3               [24] 4840 	inc	dptr
      00178E 12 26 33         [24] 4841 	lcall	__gptrget
      001791 FF               [12] 4842 	mov	r7,a
      001792 0E               [12] 4843 	inc	r6
      001793 BE 00 01         [24] 4844 	cjne	r6,#0x00,00123$
      001796 0F               [12] 4845 	inc	r7
      001797                       4846 00123$:
      001797 E5 0E            [12] 4847 	mov	a,_bp
      001799 24 09            [12] 4848 	add	a,#0x09
      00179B F8               [12] 4849 	mov	r0,a
      00179C 86 82            [24] 4850 	mov	dpl,@r0
      00179E 08               [12] 4851 	inc	r0
      00179F 86 83            [24] 4852 	mov	dph,@r0
      0017A1 08               [12] 4853 	inc	r0
      0017A2 86 F0            [24] 4854 	mov	b,@r0
      0017A4 EE               [12] 4855 	mov	a,r6
      0017A5 12 23 EC         [24] 4856 	lcall	__gptrput
      0017A8 A3               [24] 4857 	inc	dptr
      0017A9 EF               [12] 4858 	mov	a,r7
      0017AA 12 23 EC         [24] 4859 	lcall	__gptrput
                           0016F6  4860 	C$fuzzy.h$1292$1_0$80 ==.
                                   4861 ;	../../fuzzy.h:1292: return true;
      0017AD 75 82 01         [24] 4862 	mov	dpl, #0x01
      0017B0                       4863 00106$:
                           0016F9  4864 	C$fuzzy.h$1293$1_0$80 ==.
                                   4865 ;	../../fuzzy.h:1293: }
      0017B0 85 0E 81         [24] 4866 	mov	sp,_bp
      0017B3 D0 0E            [24] 4867 	pop	_bp
                           0016FE  4868 	C$fuzzy.h$1293$1_0$80 ==.
                           0016FE  4869 	XG$fuzzy_rules_add$0$0 ==.
      0017B5 22               [24] 4870 	ret
                                   4871 ;------------------------------------------------------------
                                   4872 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify'
                                   4873 ;------------------------------------------------------------
                                   4874 ;lower         Allocated to stack - _bp -6 +4 
                                   4875 ;upper         Allocated to stack - _bp -10 +4 
                                   4876 ;step          Allocated to stack - _bp -14 +4 
                                   4877 ;method        Allocated to stack - _bp -15 +1 
                                   4878 ;rules         Allocated to stack - _bp +1 +3 
                                   4879 ;weighted_sum  Allocated to stack - _bp +20 +4 
                                   4880 ;height_sum    Allocated to stack - _bp +24 +4 
                                   4881 ;maximum_height Allocated to stack - _bp +28 +4 
                                   4882 ;maximum_position_sum Allocated to stack - _bp +32 +4 
                                   4883 ;smallest_maximum Allocated to stack - _bp +36 +4 
                                   4884 ;largest_maximum Allocated to stack - _bp +40 +4 
                                   4885 ;value         Allocated to stack - _bp +44 +4 
                                   4886 ;aggregated_height Allocated to stack - _bp +48 +4 
                                   4887 ;output_membership Allocated to stack - _bp +52 +4 
                                   4888 ;clipped_height Allocated to registers r2 r4 r5 r7 
                                   4889 ;maximum_count Allocated to stack - _bp +56 +2 
                                   4890 ;i             Allocated to stack - _bp +58 +2 
                                   4891 ;maximum_found Allocated to stack - _bp +60 +1 
                                   4892 ;sloc0         Allocated to stack - _bp +4 +3 
                                   4893 ;sloc1         Allocated to stack - _bp +7 +4 
                                   4894 ;sloc2         Allocated to stack - _bp +11 +2 
                                   4895 ;sloc3         Allocated to stack - _bp +13 +3 
                                   4896 ;sloc4         Allocated to stack - _bp +16 +4 
                                   4897 ;------------------------------------------------------------
                           0016FF  4898 	G$fuzzy_rules_defuzzify$0$0 ==.
                           0016FF  4899 	C$fuzzy.h$1341$1_0$84 ==.
                                   4900 ;	../../fuzzy.h:1341: float fuzzy_rules_defuzzify(
                                   4901 ;	-----------------------------------------
                                   4902 ;	 function fuzzy_rules_defuzzify
                                   4903 ;	-----------------------------------------
      0017B6                       4904 _fuzzy_rules_defuzzify:
      0017B6 C0 0E            [24] 4905 	push	_bp
      0017B8 85 81 0E         [24] 4906 	mov	_bp,sp
      0017BB C0 82            [24] 4907 	push	dpl
      0017BD C0 83            [24] 4908 	push	dph
      0017BF C0 F0            [24] 4909 	push	b
      0017C1 E5 81            [12] 4910 	mov	a,sp
      0017C3 24 39            [12] 4911 	add	a,#0x39
      0017C5 F5 81            [12] 4912 	mov	sp,a
                           001710  4913 	C$fuzzy.h$1369$1_0$84 ==.
                                   4914 ;	../../fuzzy.h:1369: rules == NULL ||
      0017C7 A8 0E            [24] 4915 	mov	r0,_bp
      0017C9 08               [12] 4916 	inc	r0
      0017CA E6               [12] 4917 	mov	a,@r0
      0017CB 08               [12] 4918 	inc	r0
      0017CC 46               [12] 4919 	orl	a,@r0
      0017CD 70 03            [24] 4920 	jnz	00277$
      0017CF 02 18 5B         [24] 4921 	ljmp	00101$
      0017D2                       4922 00277$:
                           00171B  4923 	C$fuzzy.h$1370$1_0$84 ==.
                                   4924 ;	../../fuzzy.h:1370: rules->count == 0 ||
      0017D2 A8 0E            [24] 4925 	mov	r0,_bp
      0017D4 08               [12] 4926 	inc	r0
      0017D5 E5 0E            [12] 4927 	mov	a,_bp
      0017D7 24 04            [12] 4928 	add	a,#0x04
      0017D9 F9               [12] 4929 	mov	r1,a
      0017DA 74 48            [12] 4930 	mov	a,#0x48
      0017DC 26               [12] 4931 	add	a, @r0
      0017DD F7               [12] 4932 	mov	@r1,a
      0017DE E4               [12] 4933 	clr	a
      0017DF 08               [12] 4934 	inc	r0
      0017E0 36               [12] 4935 	addc	a, @r0
      0017E1 09               [12] 4936 	inc	r1
      0017E2 F7               [12] 4937 	mov	@r1,a
      0017E3 08               [12] 4938 	inc	r0
      0017E4 E6               [12] 4939 	mov	a,@r0
      0017E5 09               [12] 4940 	inc	r1
      0017E6 F7               [12] 4941 	mov	@r1,a
      0017E7 E5 0E            [12] 4942 	mov	a,_bp
      0017E9 24 04            [12] 4943 	add	a,#0x04
      0017EB F8               [12] 4944 	mov	r0,a
      0017EC 86 82            [24] 4945 	mov	dpl,@r0
      0017EE 08               [12] 4946 	inc	r0
      0017EF 86 83            [24] 4947 	mov	dph,@r0
      0017F1 08               [12] 4948 	inc	r0
      0017F2 86 F0            [24] 4949 	mov	b,@r0
      0017F4 12 26 33         [24] 4950 	lcall	__gptrget
      0017F7 FE               [12] 4951 	mov	r6,a
      0017F8 A3               [24] 4952 	inc	dptr
      0017F9 12 26 33         [24] 4953 	lcall	__gptrget
      0017FC 4E               [12] 4954 	orl	a,r6
      0017FD 60 5C            [24] 4955 	jz	00101$
                           001748  4956 	C$fuzzy.h$1371$1_0$84 ==.
                                   4957 ;	../../fuzzy.h:1371: lower > upper ||
      0017FF E5 0E            [12] 4958 	mov	a,_bp
      001801 24 FA            [12] 4959 	add	a,#0xfa
      001803 F8               [12] 4960 	mov	r0,a
      001804 E6               [12] 4961 	mov	a,@r0
      001805 C0 E0            [24] 4962 	push	acc
      001807 08               [12] 4963 	inc	r0
      001808 E6               [12] 4964 	mov	a,@r0
      001809 C0 E0            [24] 4965 	push	acc
      00180B 08               [12] 4966 	inc	r0
      00180C E6               [12] 4967 	mov	a,@r0
      00180D C0 E0            [24] 4968 	push	acc
      00180F 08               [12] 4969 	inc	r0
      001810 E6               [12] 4970 	mov	a,@r0
      001811 C0 E0            [24] 4971 	push	acc
      001813 E5 0E            [12] 4972 	mov	a,_bp
      001815 24 F6            [12] 4973 	add	a,#0xf6
      001817 F8               [12] 4974 	mov	r0,a
      001818 86 82            [24] 4975 	mov	dpl, @r0
      00181A 08               [12] 4976 	inc	r0
      00181B 86 83            [24] 4977 	mov	dph, @r0
      00181D 08               [12] 4978 	inc	r0
      00181E 86 F0            [24] 4979 	mov	b, @r0
      001820 08               [12] 4980 	inc	r0
      001821 E6               [12] 4981 	mov	a, @r0
      001822 12 24 07         [24] 4982 	lcall	___fslt
      001825 AF 82            [24] 4983 	mov	r7, dpl
      001827 E5 81            [12] 4984 	mov	a,sp
      001829 24 FC            [12] 4985 	add	a,#0xfc
      00182B F5 81            [12] 4986 	mov	sp,a
      00182D EF               [12] 4987 	mov	a,r7
      00182E 70 2B            [24] 4988 	jnz	00101$
                           001779  4989 	C$fuzzy.h$1373$1_0$84 ==.
                                   4990 ;	../../fuzzy.h:1373: ) {
      001830 E5 0E            [12] 4991 	mov	a,_bp
      001832 24 F2            [12] 4992 	add	a,#0xf2
      001834 F8               [12] 4993 	mov	r0,a
      001835 E6               [12] 4994 	mov	a,@r0
      001836 C0 E0            [24] 4995 	push	acc
      001838 08               [12] 4996 	inc	r0
      001839 E6               [12] 4997 	mov	a,@r0
      00183A C0 E0            [24] 4998 	push	acc
      00183C 08               [12] 4999 	inc	r0
      00183D E6               [12] 5000 	mov	a,@r0
      00183E C0 E0            [24] 5001 	push	acc
      001840 08               [12] 5002 	inc	r0
      001841 E6               [12] 5003 	mov	a,@r0
      001842 C0 E0            [24] 5004 	push	acc
      001844 90 00 00         [24] 5005 	mov	dptr,#0x0000
      001847 E4               [12] 5006 	clr	a
      001848 F5 F0            [12] 5007 	mov	b,a
      00184A 12 24 07         [24] 5008 	lcall	___fslt
      00184D E5 81            [12] 5009 	mov	a,sp
      00184F 24 FC            [12] 5010 	add	a,#0xfc
      001851 F5 81            [12] 5011 	mov	sp,a
      001853 E5 82            [12] 5012 	mov	a, dpl
      001855 24 FF            [12] 5013 	add	a,#0xff
      001857 92 00            [24] 5014 	mov	b0,c
      001859 40 09            [24] 5015 	jc	00102$
      00185B                       5016 00101$:
                           0017A4  5017 	C$fuzzy.h$1374$2_0$85 ==.
                                   5018 ;	../../fuzzy.h:1374: return 0.0f;
      00185B 90 00 00         [24] 5019 	mov	dptr,#0x0000
      00185E E4               [12] 5020 	clr	a
      00185F F5 F0            [12] 5021 	mov	b,a
      001861 02 1E AC         [24] 5022 	ljmp	00137$
      001864                       5023 00102$:
                           0017AD  5024 	C$fuzzy.h$1378$1_0$84 ==.
                                   5025 ;	../../fuzzy.h:1378: method != FUZZY_DEFUZZ_COG &&
      001864 E5 0E            [12] 5026 	mov	a,_bp
      001866 24 F1            [12] 5027 	add	a,#0xf1
      001868 F8               [12] 5028 	mov	r0,a
      001869 E6               [12] 5029 	mov	a,@r0
      00186A 60 27            [24] 5030 	jz	00107$
                           0017B5  5031 	C$fuzzy.h$1379$1_0$84 ==.
                                   5032 ;	../../fuzzy.h:1379: method != FUZZY_DEFUZZ_MOM &&
      00186C E5 0E            [12] 5033 	mov	a,_bp
      00186E 24 F1            [12] 5034 	add	a,#0xf1
      001870 F8               [12] 5035 	mov	r0,a
      001871 B6 01 02         [24] 5036 	cjne	@r0,#0x01,00282$
      001874 80 1D            [24] 5037 	sjmp	00107$
      001876                       5038 00282$:
                           0017BF  5039 	C$fuzzy.h$1380$1_0$84 ==.
                                   5040 ;	../../fuzzy.h:1380: method != FUZZY_DEFUZZ_SOM &&
      001876 E5 0E            [12] 5041 	mov	a,_bp
      001878 24 F1            [12] 5042 	add	a,#0xf1
      00187A F8               [12] 5043 	mov	r0,a
      00187B B6 02 02         [24] 5044 	cjne	@r0,#0x02,00283$
      00187E 80 13            [24] 5045 	sjmp	00107$
      001880                       5046 00283$:
                           0017C9  5047 	C$fuzzy.h$1382$1_0$84 ==.
                                   5048 ;	../../fuzzy.h:1382: ) {
      001880 E5 0E            [12] 5049 	mov	a,_bp
      001882 24 F1            [12] 5050 	add	a,#0xf1
      001884 F8               [12] 5051 	mov	r0,a
      001885 B6 03 02         [24] 5052 	cjne	@r0,#0x03,00284$
      001888 80 09            [24] 5053 	sjmp	00107$
      00188A                       5054 00284$:
                           0017D3  5055 	C$fuzzy.h$1383$2_0$86 ==.
                                   5056 ;	../../fuzzy.h:1383: return 0.0f;
      00188A 90 00 00         [24] 5057 	mov	dptr,#0x0000
      00188D E4               [12] 5058 	clr	a
      00188E F5 F0            [12] 5059 	mov	b,a
      001890 02 1E AC         [24] 5060 	ljmp	00137$
      001893                       5061 00107$:
                           0017DC  5062 	C$fuzzy.h$1387$1_0$84 ==.
                                   5063 ;	../../fuzzy.h:1387: 0.0f;
      001893 E5 0E            [12] 5064 	mov	a,_bp
      001895 24 14            [12] 5065 	add	a,#0x14
      001897 F8               [12] 5066 	mov	r0,a
      001898 E4               [12] 5067 	clr	a
      001899 F6               [12] 5068 	mov	@r0,a
      00189A 08               [12] 5069 	inc	r0
      00189B F6               [12] 5070 	mov	@r0,a
      00189C 08               [12] 5071 	inc	r0
      00189D F6               [12] 5072 	mov	@r0,a
      00189E 08               [12] 5073 	inc	r0
      00189F F6               [12] 5074 	mov	@r0,a
                           0017E9  5075 	C$fuzzy.h$1390$1_0$84 ==.
                                   5076 ;	../../fuzzy.h:1390: 0.0f;
      0018A0 E5 0E            [12] 5077 	mov	a,_bp
      0018A2 24 18            [12] 5078 	add	a,#0x18
      0018A4 F8               [12] 5079 	mov	r0,a
      0018A5 E4               [12] 5080 	clr	a
      0018A6 F6               [12] 5081 	mov	@r0,a
      0018A7 08               [12] 5082 	inc	r0
      0018A8 F6               [12] 5083 	mov	@r0,a
      0018A9 08               [12] 5084 	inc	r0
      0018AA F6               [12] 5085 	mov	@r0,a
      0018AB 08               [12] 5086 	inc	r0
      0018AC F6               [12] 5087 	mov	@r0,a
                           0017F6  5088 	C$fuzzy.h$1393$1_0$84 ==.
                                   5089 ;	../../fuzzy.h:1393: LEVEL_LO;
      0018AD E5 0E            [12] 5090 	mov	a,_bp
      0018AF 24 1C            [12] 5091 	add	a,#0x1c
      0018B1 F8               [12] 5092 	mov	r0,a
      0018B2 E4               [12] 5093 	clr	a
      0018B3 F6               [12] 5094 	mov	@r0,a
      0018B4 08               [12] 5095 	inc	r0
      0018B5 F6               [12] 5096 	mov	@r0,a
      0018B6 08               [12] 5097 	inc	r0
      0018B7 F6               [12] 5098 	mov	@r0,a
      0018B8 08               [12] 5099 	inc	r0
      0018B9 F6               [12] 5100 	mov	@r0,a
                           001803  5101 	C$fuzzy.h$1396$1_0$84 ==.
                                   5102 ;	../../fuzzy.h:1396: 0.0f;
      0018BA E5 0E            [12] 5103 	mov	a,_bp
      0018BC 24 20            [12] 5104 	add	a,#0x20
      0018BE F8               [12] 5105 	mov	r0,a
      0018BF E4               [12] 5106 	clr	a
      0018C0 F6               [12] 5107 	mov	@r0,a
      0018C1 08               [12] 5108 	inc	r0
      0018C2 F6               [12] 5109 	mov	@r0,a
      0018C3 08               [12] 5110 	inc	r0
      0018C4 F6               [12] 5111 	mov	@r0,a
      0018C5 08               [12] 5112 	inc	r0
      0018C6 F6               [12] 5113 	mov	@r0,a
                           001810  5114 	C$fuzzy.h$1399$1_0$84 ==.
                                   5115 ;	../../fuzzy.h:1399: lower;
      0018C7 E5 0E            [12] 5116 	mov	a,_bp
      0018C9 24 FA            [12] 5117 	add	a,#0xfa
      0018CB F8               [12] 5118 	mov	r0,a
      0018CC E5 0E            [12] 5119 	mov	a,_bp
      0018CE 24 24            [12] 5120 	add	a,#0x24
      0018D0 F9               [12] 5121 	mov	r1,a
      0018D1 E6               [12] 5122 	mov	a,@r0
      0018D2 F7               [12] 5123 	mov	@r1,a
      0018D3 08               [12] 5124 	inc	r0
      0018D4 E6               [12] 5125 	mov	a,@r0
      0018D5 09               [12] 5126 	inc	r1
      0018D6 F7               [12] 5127 	mov	@r1,a
      0018D7 08               [12] 5128 	inc	r0
      0018D8 E6               [12] 5129 	mov	a,@r0
      0018D9 09               [12] 5130 	inc	r1
      0018DA F7               [12] 5131 	mov	@r1,a
      0018DB 08               [12] 5132 	inc	r0
      0018DC E6               [12] 5133 	mov	a,@r0
      0018DD 09               [12] 5134 	inc	r1
      0018DE F7               [12] 5135 	mov	@r1,a
                           001828  5136 	C$fuzzy.h$1402$1_0$84 ==.
                                   5137 ;	../../fuzzy.h:1402: lower;
      0018DF E5 0E            [12] 5138 	mov	a,_bp
      0018E1 24 24            [12] 5139 	add	a,#0x24
      0018E3 F8               [12] 5140 	mov	r0,a
      0018E4 E5 0E            [12] 5141 	mov	a,_bp
      0018E6 24 28            [12] 5142 	add	a,#0x28
      0018E8 F9               [12] 5143 	mov	r1,a
      0018E9 E6               [12] 5144 	mov	a,@r0
      0018EA F7               [12] 5145 	mov	@r1,a
      0018EB 08               [12] 5146 	inc	r0
      0018EC E6               [12] 5147 	mov	a,@r0
      0018ED 09               [12] 5148 	inc	r1
      0018EE F7               [12] 5149 	mov	@r1,a
      0018EF 08               [12] 5150 	inc	r0
      0018F0 E6               [12] 5151 	mov	a,@r0
      0018F1 09               [12] 5152 	inc	r1
      0018F2 F7               [12] 5153 	mov	@r1,a
      0018F3 08               [12] 5154 	inc	r0
      0018F4 E6               [12] 5155 	mov	a,@r0
      0018F5 09               [12] 5156 	inc	r1
      0018F6 F7               [12] 5157 	mov	@r1,a
                           001840  5158 	C$fuzzy.h$1405$1_0$84 ==.
                                   5159 ;	../../fuzzy.h:1405: 0u;
      0018F7 E5 0E            [12] 5160 	mov	a,_bp
      0018F9 24 38            [12] 5161 	add	a,#0x38
      0018FB F8               [12] 5162 	mov	r0,a
      0018FC E4               [12] 5163 	clr	a
      0018FD F6               [12] 5164 	mov	@r0,a
      0018FE 08               [12] 5165 	inc	r0
      0018FF F6               [12] 5166 	mov	@r0,a
                           001849  5167 	C$fuzzy.h$1408$1_0$84 ==.
                                   5168 ;	../../fuzzy.h:1408: false;
      001900 E5 0E            [12] 5169 	mov	a,_bp
      001902 24 3C            [12] 5170 	add	a,#0x3c
      001904 F8               [12] 5171 	mov	r0,a
      001905 76 00            [12] 5172 	mov	@r0,#0x00
                           001850  5173 	C$fuzzy.h$1411$2_0$87 ==.
                                   5174 ;	../../fuzzy.h:1411: value = lower;
      001907 E5 0E            [12] 5175 	mov	a,_bp
      001909 24 24            [12] 5176 	add	a,#0x24
      00190B F8               [12] 5177 	mov	r0,a
      00190C E5 0E            [12] 5178 	mov	a,_bp
      00190E 24 2C            [12] 5179 	add	a,#0x2c
      001910 F9               [12] 5180 	mov	r1,a
      001911 E6               [12] 5181 	mov	a,@r0
      001912 F7               [12] 5182 	mov	@r1,a
      001913 08               [12] 5183 	inc	r0
      001914 E6               [12] 5184 	mov	a,@r0
      001915 09               [12] 5185 	inc	r1
      001916 F7               [12] 5186 	mov	@r1,a
      001917 08               [12] 5187 	inc	r0
      001918 E6               [12] 5188 	mov	a,@r0
      001919 09               [12] 5189 	inc	r1
      00191A F7               [12] 5190 	mov	@r1,a
      00191B 08               [12] 5191 	inc	r0
      00191C E6               [12] 5192 	mov	a,@r0
      00191D 09               [12] 5193 	inc	r1
      00191E F7               [12] 5194 	mov	@r1,a
      00191F A8 0E            [24] 5195 	mov	r0,_bp
      001921 08               [12] 5196 	inc	r0
      001922 E5 0E            [12] 5197 	mov	a,_bp
      001924 24 0D            [12] 5198 	add	a,#0x0d
      001926 F9               [12] 5199 	mov	r1,a
      001927 E6               [12] 5200 	mov	a,@r0
      001928 F7               [12] 5201 	mov	@r1,a
      001929 08               [12] 5202 	inc	r0
      00192A E6               [12] 5203 	mov	a,@r0
      00192B 09               [12] 5204 	inc	r1
      00192C F7               [12] 5205 	mov	@r1,a
      00192D 08               [12] 5206 	inc	r0
      00192E E6               [12] 5207 	mov	a,@r0
      00192F 09               [12] 5208 	inc	r1
      001930 F7               [12] 5209 	mov	@r1,a
      001931                       5210 00135$:
                           00187A  5211 	C$fuzzy.h$1412$1_0$84 ==.
                                   5212 ;	../../fuzzy.h:1412: value <= upper;
      001931 E5 0E            [12] 5213 	mov	a,_bp
      001933 24 2C            [12] 5214 	add	a,#0x2c
      001935 F8               [12] 5215 	mov	r0,a
      001936 E6               [12] 5216 	mov	a,@r0
      001937 C0 E0            [24] 5217 	push	acc
      001939 08               [12] 5218 	inc	r0
      00193A E6               [12] 5219 	mov	a,@r0
      00193B C0 E0            [24] 5220 	push	acc
      00193D 08               [12] 5221 	inc	r0
      00193E E6               [12] 5222 	mov	a,@r0
      00193F C0 E0            [24] 5223 	push	acc
      001941 08               [12] 5224 	inc	r0
      001942 E6               [12] 5225 	mov	a,@r0
      001943 C0 E0            [24] 5226 	push	acc
      001945 E5 0E            [12] 5227 	mov	a,_bp
      001947 24 F6            [12] 5228 	add	a,#0xf6
      001949 F8               [12] 5229 	mov	r0,a
      00194A 86 82            [24] 5230 	mov	dpl, @r0
      00194C 08               [12] 5231 	inc	r0
      00194D 86 83            [24] 5232 	mov	dph, @r0
      00194F 08               [12] 5233 	inc	r0
      001950 86 F0            [24] 5234 	mov	b, @r0
      001952 08               [12] 5235 	inc	r0
      001953 E6               [12] 5236 	mov	a, @r0
      001954 12 24 07         [24] 5237 	lcall	___fslt
      001957 E5 81            [12] 5238 	mov	a,sp
      001959 24 FC            [12] 5239 	add	a,#0xfc
      00195B F5 81            [12] 5240 	mov	sp,a
      00195D E5 82            [12] 5241 	mov	a, dpl
      00195F 24 FF            [12] 5242 	add	a,#0xff
      001961 92 00            [24] 5243 	mov	b0,c
      001963 50 03            [24] 5244 	jnc	00285$
      001965 02 1D 65         [24] 5245 	ljmp	00118$
      001968                       5246 00285$:
                           0018B1  5247 	C$fuzzy.h$1416$3_0$88 ==.
                                   5248 ;	../../fuzzy.h:1416: LEVEL_LO;
      001968 E5 0E            [12] 5249 	mov	a,_bp
      00196A 24 07            [12] 5250 	add	a,#0x07
      00196C F8               [12] 5251 	mov	r0,a
      00196D E4               [12] 5252 	clr	a
      00196E F6               [12] 5253 	mov	@r0,a
      00196F 08               [12] 5254 	inc	r0
      001970 F6               [12] 5255 	mov	@r0,a
      001971 08               [12] 5256 	inc	r0
      001972 F6               [12] 5257 	mov	@r0,a
      001973 08               [12] 5258 	inc	r0
      001974 F6               [12] 5259 	mov	@r0,a
                           0018BE  5260 	C$fuzzy.h$1425$1_0$84 ==.
                                   5261 ;	../../fuzzy.h:1425: i = 0;
      001975 E5 0E            [12] 5262 	mov	a,_bp
      001977 24 3A            [12] 5263 	add	a,#0x3a
      001979 F8               [12] 5264 	mov	r0,a
      00197A E4               [12] 5265 	clr	a
      00197B F6               [12] 5266 	mov	@r0,a
      00197C 08               [12] 5267 	inc	r0
      00197D F6               [12] 5268 	mov	@r0,a
      00197E E5 0E            [12] 5269 	mov	a,_bp
      001980 24 0B            [12] 5270 	add	a,#0x0b
      001982 F8               [12] 5271 	mov	r0,a
      001983 E4               [12] 5272 	clr	a
      001984 F6               [12] 5273 	mov	@r0,a
      001985 08               [12] 5274 	inc	r0
      001986 F6               [12] 5275 	mov	@r0,a
      001987                       5276 00132$:
                           0018D0  5277 	C$fuzzy.h$1426$1_0$84 ==.
                                   5278 ;	../../fuzzy.h:1426: i < rules->count;
      001987 E5 0E            [12] 5279 	mov	a,_bp
      001989 24 04            [12] 5280 	add	a,#0x04
      00198B F8               [12] 5281 	mov	r0,a
      00198C 86 82            [24] 5282 	mov	dpl,@r0
      00198E 08               [12] 5283 	inc	r0
      00198F 86 83            [24] 5284 	mov	dph,@r0
      001991 08               [12] 5285 	inc	r0
      001992 86 F0            [24] 5286 	mov	b,@r0
      001994 12 26 33         [24] 5287 	lcall	__gptrget
      001997 FA               [12] 5288 	mov	r2,a
      001998 A3               [24] 5289 	inc	dptr
      001999 12 26 33         [24] 5290 	lcall	__gptrget
      00199C FF               [12] 5291 	mov	r7,a
      00199D E5 0E            [12] 5292 	mov	a,_bp
      00199F 24 3A            [12] 5293 	add	a,#0x3a
      0019A1 F8               [12] 5294 	mov	r0,a
      0019A2 C3               [12] 5295 	clr	c
      0019A3 E6               [12] 5296 	mov	a,@r0
      0019A4 9A               [12] 5297 	subb	a,r2
      0019A5 08               [12] 5298 	inc	r0
      0019A6 E6               [12] 5299 	mov	a,@r0
      0019A7 9F               [12] 5300 	subb	a,r7
      0019A8 40 03            [24] 5301 	jc	00286$
      0019AA 02 1B 28         [24] 5302 	ljmp	00111$
      0019AD                       5303 00286$:
                           0018F6  5304 	C$fuzzy.h$1430$1_0$84 ==.
                                   5305 ;	../../fuzzy.h:1430: rules->rules[i]
      0019AD E5 0E            [12] 5306 	mov	a,_bp
      0019AF 24 0D            [12] 5307 	add	a,#0x0d
      0019B1 F8               [12] 5308 	mov	r0,a
      0019B2 E5 0E            [12] 5309 	mov	a,_bp
      0019B4 24 0B            [12] 5310 	add	a,#0x0b
      0019B6 F9               [12] 5311 	mov	r1,a
      0019B7 E7               [12] 5312 	mov	a,@r1
      0019B8 26               [12] 5313 	add	a, @r0
      0019B9 FA               [12] 5314 	mov	r2,a
      0019BA 09               [12] 5315 	inc	r1
      0019BB E7               [12] 5316 	mov	a,@r1
      0019BC 08               [12] 5317 	inc	r0
      0019BD 36               [12] 5318 	addc	a, @r0
      0019BE FB               [12] 5319 	mov	r3,a
      0019BF 08               [12] 5320 	inc	r0
      0019C0 86 06            [24] 5321 	mov	ar6,@r0
      0019C2 74 07            [12] 5322 	mov	a,#0x07
      0019C4 2A               [12] 5323 	add	a, r2
      0019C5 FA               [12] 5324 	mov	r2,a
      0019C6 E4               [12] 5325 	clr	a
      0019C7 3B               [12] 5326 	addc	a, r3
      0019C8 FB               [12] 5327 	mov	r3,a
      0019C9 8A 82            [24] 5328 	mov	dpl,r2
      0019CB 8B 83            [24] 5329 	mov	dph,r3
      0019CD 8E F0            [24] 5330 	mov	b,r6
      0019CF 12 26 33         [24] 5331 	lcall	__gptrget
      0019D2 FA               [12] 5332 	mov	r2,a
      0019D3 A3               [24] 5333 	inc	dptr
      0019D4 12 26 33         [24] 5334 	lcall	__gptrget
      0019D7 FB               [12] 5335 	mov	r3,a
                           001921  5336 	C$fuzzy.h$1432$5_0$90 ==.
                                   5337 ;	../../fuzzy.h:1432: value
      0019D8 12 19 DD         [24] 5338 	lcall	00287$
      0019DB 80 14            [24] 5339 	sjmp	00288$
      0019DD                       5340 00287$:
      0019DD C0 02            [24] 5341 	push	ar2
      0019DF C0 03            [24] 5342 	push	ar3
      0019E1 E5 0E            [12] 5343 	mov	a,_bp
      0019E3 24 2C            [12] 5344 	add	a,#0x2c
      0019E5 F8               [12] 5345 	mov	r0,a
      0019E6 86 82            [24] 5346 	mov	dpl, @r0
      0019E8 08               [12] 5347 	inc	r0
      0019E9 86 83            [24] 5348 	mov	dph, @r0
      0019EB 08               [12] 5349 	inc	r0
      0019EC 86 F0            [24] 5350 	mov	b, @r0
      0019EE 08               [12] 5351 	inc	r0
      0019EF E6               [12] 5352 	mov	a, @r0
      0019F0 22               [24] 5353 	ret
      0019F1                       5354 00288$:
                           00193A  5355 	C$fuzzy.h$1437$5_0$90 ==.
                                   5356 ;	../../fuzzy.h:1437: output_membership
      0019F1 12 00 B7         [24] 5357 	lcall	_fuzzy_clamp
      0019F4 C8               [12] 5358 	xch	a,r0
      0019F5 E5 0E            [12] 5359 	mov	a,_bp
      0019F7 24 34            [12] 5360 	add	a,#0x34
      0019F9 C8               [12] 5361 	xch	a,r0
      0019FA A6 82            [24] 5362 	mov	@r0, dpl
      0019FC 08               [12] 5363 	inc	r0
      0019FD A6 83            [24] 5364 	mov	@r0, dph
      0019FF 08               [12] 5365 	inc	r0
      001A00 A6 F0            [24] 5366 	mov	@r0, b
      001A02 08               [12] 5367 	inc	r0
      001A03 F6               [12] 5368 	mov	@r0,a
                           00194D  5369 	C$fuzzy.h$1441$5_0$90 ==.
                                   5370 ;	../../fuzzy.h:1441: rules->rules[i].value <
      001A04 A8 0E            [24] 5371 	mov	r0,_bp
      001A06 08               [12] 5372 	inc	r0
      001A07 E5 0E            [12] 5373 	mov	a,_bp
      001A09 24 0B            [12] 5374 	add	a,#0x0b
      001A0B F9               [12] 5375 	mov	r1,a
      001A0C E7               [12] 5376 	mov	a,@r1
      001A0D 26               [12] 5377 	add	a, @r0
      001A0E FD               [12] 5378 	mov	r5,a
      001A0F 09               [12] 5379 	inc	r1
      001A10 E7               [12] 5380 	mov	a,@r1
      001A11 08               [12] 5381 	inc	r0
      001A12 36               [12] 5382 	addc	a, @r0
      001A13 FE               [12] 5383 	mov	r6,a
      001A14 08               [12] 5384 	inc	r0
      001A15 86 07            [24] 5385 	mov	ar7,@r0
      001A17 74 03            [12] 5386 	mov	a,#0x03
      001A19 2D               [12] 5387 	add	a, r5
      001A1A FD               [12] 5388 	mov	r5,a
      001A1B E4               [12] 5389 	clr	a
      001A1C 3E               [12] 5390 	addc	a, r6
      001A1D FE               [12] 5391 	mov	r6,a
      001A1E 8D 82            [24] 5392 	mov	dpl,r5
      001A20 8E 83            [24] 5393 	mov	dph,r6
      001A22 8F F0            [24] 5394 	mov	b,r7
      001A24 E5 0E            [12] 5395 	mov	a,_bp
      001A26 24 10            [12] 5396 	add	a,#0x10
      001A28 F8               [12] 5397 	mov	r0,a
      001A29 12 26 33         [24] 5398 	lcall	__gptrget
      001A2C F6               [12] 5399 	mov	@r0,a
      001A2D A3               [24] 5400 	inc	dptr
      001A2E 12 26 33         [24] 5401 	lcall	__gptrget
      001A31 08               [12] 5402 	inc	r0
      001A32 F6               [12] 5403 	mov	@r0,a
      001A33 A3               [24] 5404 	inc	dptr
      001A34 12 26 33         [24] 5405 	lcall	__gptrget
      001A37 08               [12] 5406 	inc	r0
      001A38 F6               [12] 5407 	mov	@r0,a
      001A39 A3               [24] 5408 	inc	dptr
      001A3A 12 26 33         [24] 5409 	lcall	__gptrget
      001A3D 08               [12] 5410 	inc	r0
      001A3E F6               [12] 5411 	mov	@r0,a
      001A3F E5 0E            [12] 5412 	mov	a,_bp
      001A41 24 34            [12] 5413 	add	a,#0x34
      001A43 F8               [12] 5414 	mov	r0,a
      001A44 E6               [12] 5415 	mov	a,@r0
      001A45 C0 E0            [24] 5416 	push	acc
      001A47 08               [12] 5417 	inc	r0
      001A48 E6               [12] 5418 	mov	a,@r0
      001A49 C0 E0            [24] 5419 	push	acc
      001A4B 08               [12] 5420 	inc	r0
      001A4C E6               [12] 5421 	mov	a,@r0
      001A4D C0 E0            [24] 5422 	push	acc
      001A4F 08               [12] 5423 	inc	r0
      001A50 E6               [12] 5424 	mov	a,@r0
      001A51 C0 E0            [24] 5425 	push	acc
      001A53 E5 0E            [12] 5426 	mov	a,_bp
      001A55 24 10            [12] 5427 	add	a,#0x10
      001A57 F8               [12] 5428 	mov	r0,a
      001A58 86 82            [24] 5429 	mov	dpl, @r0
      001A5A 08               [12] 5430 	inc	r0
      001A5B 86 83            [24] 5431 	mov	dph, @r0
      001A5D 08               [12] 5432 	inc	r0
      001A5E 86 F0            [24] 5433 	mov	b, @r0
      001A60 08               [12] 5434 	inc	r0
      001A61 E6               [12] 5435 	mov	a, @r0
      001A62 12 24 07         [24] 5436 	lcall	___fslt
      001A65 AF 82            [24] 5437 	mov	r7, dpl
      001A67 E5 81            [12] 5438 	mov	a,sp
      001A69 24 FC            [12] 5439 	add	a,#0xfc
      001A6B F5 81            [12] 5440 	mov	sp,a
      001A6D EF               [12] 5441 	mov	a,r7
      001A6E 60 12            [24] 5442 	jz	00139$
                           0019B9  5443 	C$fuzzy.h$1443$5_0$90 ==.
                                   5444 ;	../../fuzzy.h:1443: ? rules->rules[i].value
      001A70 E5 0E            [12] 5445 	mov	a,_bp
      001A72 24 10            [12] 5446 	add	a,#0x10
      001A74 F8               [12] 5447 	mov	r0,a
      001A75 86 02            [24] 5448 	mov	ar2,@r0
      001A77 08               [12] 5449 	inc	r0
      001A78 86 04            [24] 5450 	mov	ar4,@r0
      001A7A 08               [12] 5451 	inc	r0
      001A7B 86 05            [24] 5452 	mov	ar5,@r0
      001A7D 08               [12] 5453 	inc	r0
      001A7E 86 07            [24] 5454 	mov	ar7,@r0
      001A80 80 10            [24] 5455 	sjmp	00140$
      001A82                       5456 00139$:
                           0019CB  5457 	C$fuzzy.h$1444$5_0$90 ==.
                                   5458 ;	../../fuzzy.h:1444: : output_membership;
      001A82 E5 0E            [12] 5459 	mov	a,_bp
      001A84 24 34            [12] 5460 	add	a,#0x34
      001A86 F8               [12] 5461 	mov	r0,a
      001A87 86 02            [24] 5462 	mov	ar2,@r0
      001A89 08               [12] 5463 	inc	r0
      001A8A 86 04            [24] 5464 	mov	ar4,@r0
      001A8C 08               [12] 5465 	inc	r0
      001A8D 86 05            [24] 5466 	mov	ar5,@r0
      001A8F 08               [12] 5467 	inc	r0
      001A90 86 07            [24] 5468 	mov	ar7,@r0
      001A92                       5469 00140$:
                           0019DB  5470 	C$fuzzy.h$1449$1_0$84 ==.
                                   5471 ;	../../fuzzy.h:1449: ? aggregated_height
      001A92 C0 07            [24] 5472 	push	ar7
      001A94 C0 05            [24] 5473 	push	ar5
      001A96 C0 04            [24] 5474 	push	ar4
      001A98 C0 02            [24] 5475 	push	ar2
      001A9A E5 0E            [12] 5476 	mov	a,_bp
      001A9C 24 07            [12] 5477 	add	a,#0x07
      001A9E F8               [12] 5478 	mov	r0,a
      001A9F E6               [12] 5479 	mov	a,@r0
      001AA0 C0 E0            [24] 5480 	push	acc
      001AA2 08               [12] 5481 	inc	r0
      001AA3 E6               [12] 5482 	mov	a,@r0
      001AA4 C0 E0            [24] 5483 	push	acc
      001AA6 08               [12] 5484 	inc	r0
      001AA7 E6               [12] 5485 	mov	a,@r0
      001AA8 C0 E0            [24] 5486 	push	acc
      001AAA 08               [12] 5487 	inc	r0
      001AAB E6               [12] 5488 	mov	a,@r0
      001AAC C0 E0            [24] 5489 	push	acc
      001AAE 8A 82            [24] 5490 	mov	dpl, r2
      001AB0 8C 83            [24] 5491 	mov	dph, r4
      001AB2 8D F0            [24] 5492 	mov	b, r5
      001AB4 EF               [12] 5493 	mov	a, r7
      001AB5 12 24 07         [24] 5494 	lcall	___fslt
      001AB8 AE 82            [24] 5495 	mov	r6, dpl
      001ABA E5 81            [12] 5496 	mov	a,sp
      001ABC 24 FC            [12] 5497 	add	a,#0xfc
      001ABE F5 81            [12] 5498 	mov	sp,a
      001AC0 D0 02            [24] 5499 	pop	ar2
      001AC2 D0 04            [24] 5500 	pop	ar4
      001AC4 D0 05            [24] 5501 	pop	ar5
      001AC6 D0 07            [24] 5502 	pop	ar7
      001AC8 EE               [12] 5503 	mov	a,r6
      001AC9 60 1A            [24] 5504 	jz	00141$
      001ACB E5 0E            [12] 5505 	mov	a,_bp
      001ACD 24 07            [12] 5506 	add	a,#0x07
      001ACF F8               [12] 5507 	mov	r0,a
      001AD0 E5 0E            [12] 5508 	mov	a,_bp
      001AD2 24 10            [12] 5509 	add	a,#0x10
      001AD4 F9               [12] 5510 	mov	r1,a
      001AD5 E6               [12] 5511 	mov	a,@r0
      001AD6 F7               [12] 5512 	mov	@r1,a
      001AD7 08               [12] 5513 	inc	r0
      001AD8 E6               [12] 5514 	mov	a,@r0
      001AD9 09               [12] 5515 	inc	r1
      001ADA F7               [12] 5516 	mov	@r1,a
      001ADB 08               [12] 5517 	inc	r0
      001ADC E6               [12] 5518 	mov	a,@r0
      001ADD 09               [12] 5519 	inc	r1
      001ADE F7               [12] 5520 	mov	@r1,a
      001ADF 08               [12] 5521 	inc	r0
      001AE0 E6               [12] 5522 	mov	a,@r0
      001AE1 09               [12] 5523 	inc	r1
      001AE2 F7               [12] 5524 	mov	@r1,a
      001AE3 80 10            [24] 5525 	sjmp	00142$
      001AE5                       5526 00141$:
                           001A2E  5527 	C$fuzzy.h$1450$5_0$90 ==.
                                   5528 ;	../../fuzzy.h:1450: : clipped_height;
      001AE5 E5 0E            [12] 5529 	mov	a,_bp
      001AE7 24 10            [12] 5530 	add	a,#0x10
      001AE9 F8               [12] 5531 	mov	r0,a
      001AEA A6 02            [24] 5532 	mov	@r0,ar2
      001AEC 08               [12] 5533 	inc	r0
      001AED A6 04            [24] 5534 	mov	@r0,ar4
      001AEF 08               [12] 5535 	inc	r0
      001AF0 A6 05            [24] 5536 	mov	@r0,ar5
      001AF2 08               [12] 5537 	inc	r0
      001AF3 A6 07            [24] 5538 	mov	@r0,ar7
      001AF5                       5539 00142$:
      001AF5 E5 0E            [12] 5540 	mov	a,_bp
      001AF7 24 10            [12] 5541 	add	a,#0x10
      001AF9 F8               [12] 5542 	mov	r0,a
      001AFA E5 0E            [12] 5543 	mov	a,_bp
      001AFC 24 07            [12] 5544 	add	a,#0x07
      001AFE F9               [12] 5545 	mov	r1,a
      001AFF E6               [12] 5546 	mov	a,@r0
      001B00 F7               [12] 5547 	mov	@r1,a
      001B01 08               [12] 5548 	inc	r0
      001B02 E6               [12] 5549 	mov	a,@r0
      001B03 09               [12] 5550 	inc	r1
      001B04 F7               [12] 5551 	mov	@r1,a
      001B05 08               [12] 5552 	inc	r0
      001B06 E6               [12] 5553 	mov	a,@r0
      001B07 09               [12] 5554 	inc	r1
      001B08 F7               [12] 5555 	mov	@r1,a
      001B09 08               [12] 5556 	inc	r0
      001B0A E6               [12] 5557 	mov	a,@r0
      001B0B 09               [12] 5558 	inc	r1
      001B0C F7               [12] 5559 	mov	@r1,a
                           001A56  5560 	C$fuzzy.h$1427$1_0$84 ==.
                                   5561 ;	../../fuzzy.h:1427: i++
      001B0D E5 0E            [12] 5562 	mov	a,_bp
      001B0F 24 0B            [12] 5563 	add	a,#0x0b
      001B11 F8               [12] 5564 	mov	r0,a
      001B12 74 09            [12] 5565 	mov	a,#0x09
      001B14 26               [12] 5566 	add	a, @r0
      001B15 F6               [12] 5567 	mov	@r0,a
      001B16 E4               [12] 5568 	clr	a
      001B17 08               [12] 5569 	inc	r0
      001B18 36               [12] 5570 	addc	a, @r0
      001B19 F6               [12] 5571 	mov	@r0,a
      001B1A E5 0E            [12] 5572 	mov	a,_bp
      001B1C 24 3A            [12] 5573 	add	a,#0x3a
      001B1E F8               [12] 5574 	mov	r0,a
      001B1F 06               [12] 5575 	inc	@r0
      001B20 B6 00 02         [24] 5576 	cjne	@r0,#0x00,00291$
      001B23 08               [12] 5577 	inc	r0
      001B24 06               [12] 5578 	inc	@r0
      001B25                       5579 00291$:
      001B25 02 19 87         [24] 5580 	ljmp	00132$
      001B28                       5581 00111$:
                           001A71  5582 	C$fuzzy.h$1455$3_0$88 ==.
                                   5583 ;	../../fuzzy.h:1455: aggregated_height
      001B28 E5 0E            [12] 5584 	mov	a,_bp
      001B2A 24 07            [12] 5585 	add	a,#0x07
      001B2C F8               [12] 5586 	mov	r0,a
      001B2D 86 82            [24] 5587 	mov	dpl, @r0
      001B2F 08               [12] 5588 	inc	r0
      001B30 86 83            [24] 5589 	mov	dph, @r0
      001B32 08               [12] 5590 	inc	r0
      001B33 86 F0            [24] 5591 	mov	b, @r0
      001B35 08               [12] 5592 	inc	r0
      001B36 E6               [12] 5593 	mov	a, @r0
      001B37 12 00 B7         [24] 5594 	lcall	_fuzzy_clamp
      001B3A C8               [12] 5595 	xch	a,r0
      001B3B E5 0E            [12] 5596 	mov	a,_bp
      001B3D 24 30            [12] 5597 	add	a,#0x30
      001B3F C8               [12] 5598 	xch	a,r0
      001B40 A6 82            [24] 5599 	mov	@r0, dpl
      001B42 08               [12] 5600 	inc	r0
      001B43 A6 83            [24] 5601 	mov	@r0, dph
      001B45 08               [12] 5602 	inc	r0
      001B46 A6 F0            [24] 5603 	mov	@r0, b
      001B48 08               [12] 5604 	inc	r0
      001B49 F6               [12] 5605 	mov	@r0,a
                           001A93  5606 	C$fuzzy.h$1463$1_0$84 ==.
                                   5607 ;	../../fuzzy.h:1463: aggregated_height;
      001B4A E5 0E            [12] 5608 	mov	a,_bp
      001B4C 24 30            [12] 5609 	add	a,#0x30
      001B4E F8               [12] 5610 	mov	r0,a
      001B4F E6               [12] 5611 	mov	a,@r0
      001B50 C0 E0            [24] 5612 	push	acc
      001B52 08               [12] 5613 	inc	r0
      001B53 E6               [12] 5614 	mov	a,@r0
      001B54 C0 E0            [24] 5615 	push	acc
      001B56 08               [12] 5616 	inc	r0
      001B57 E6               [12] 5617 	mov	a,@r0
      001B58 C0 E0            [24] 5618 	push	acc
      001B5A 08               [12] 5619 	inc	r0
      001B5B E6               [12] 5620 	mov	a,@r0
      001B5C C0 E0            [24] 5621 	push	acc
      001B5E E5 0E            [12] 5622 	mov	a,_bp
      001B60 24 2C            [12] 5623 	add	a,#0x2c
      001B62 F8               [12] 5624 	mov	r0,a
      001B63 86 82            [24] 5625 	mov	dpl, @r0
      001B65 08               [12] 5626 	inc	r0
      001B66 86 83            [24] 5627 	mov	dph, @r0
      001B68 08               [12] 5628 	inc	r0
      001B69 86 F0            [24] 5629 	mov	b, @r0
      001B6B 08               [12] 5630 	inc	r0
      001B6C E6               [12] 5631 	mov	a, @r0
      001B6D 12 22 D7         [24] 5632 	lcall	___fsmul
      001B70 AA 82            [24] 5633 	mov	r2, dpl
      001B72 AB 83            [24] 5634 	mov	r3, dph
      001B74 AE F0            [24] 5635 	mov	r6, b
      001B76 FF               [12] 5636 	mov	r7, a
      001B77 E5 81            [12] 5637 	mov	a,sp
      001B79 24 FC            [12] 5638 	add	a,#0xfc
      001B7B F5 81            [12] 5639 	mov	sp,a
      001B7D C0 02            [24] 5640 	push	ar2
      001B7F C0 03            [24] 5641 	push	ar3
      001B81 C0 06            [24] 5642 	push	ar6
      001B83 C0 07            [24] 5643 	push	ar7
                           001ACE  5644 	C$fuzzy.h$1466$1_0$84 ==.
                                   5645 ;	../../fuzzy.h:1466: aggregated_height;
      001B85 E5 0E            [12] 5646 	mov	a,_bp
      001B87 24 14            [12] 5647 	add	a,#0x14
      001B89 F8               [12] 5648 	mov	r0,a
      001B8A 86 82            [24] 5649 	mov	dpl, @r0
      001B8C 08               [12] 5650 	inc	r0
      001B8D 86 83            [24] 5651 	mov	dph, @r0
      001B8F 08               [12] 5652 	inc	r0
      001B90 86 F0            [24] 5653 	mov	b, @r0
      001B92 08               [12] 5654 	inc	r0
      001B93 E6               [12] 5655 	mov	a, @r0
      001B94 12 24 59         [24] 5656 	lcall	___fsadd
      001B97 C8               [12] 5657 	xch	a,r0
      001B98 E5 0E            [12] 5658 	mov	a,_bp
      001B9A 24 14            [12] 5659 	add	a,#0x14
      001B9C C8               [12] 5660 	xch	a,r0
      001B9D A6 82            [24] 5661 	mov	@r0, dpl
      001B9F 08               [12] 5662 	inc	r0
      001BA0 A6 83            [24] 5663 	mov	@r0, dph
      001BA2 08               [12] 5664 	inc	r0
      001BA3 A6 F0            [24] 5665 	mov	@r0, b
      001BA5 08               [12] 5666 	inc	r0
      001BA6 F6               [12] 5667 	mov	@r0,a
      001BA7 E5 81            [12] 5668 	mov	a,sp
      001BA9 24 FC            [12] 5669 	add	a,#0xfc
      001BAB F5 81            [12] 5670 	mov	sp,a
      001BAD E5 0E            [12] 5671 	mov	a,_bp
      001BAF 24 30            [12] 5672 	add	a,#0x30
      001BB1 F8               [12] 5673 	mov	r0,a
      001BB2 E6               [12] 5674 	mov	a,@r0
      001BB3 C0 E0            [24] 5675 	push	acc
      001BB5 08               [12] 5676 	inc	r0
      001BB6 E6               [12] 5677 	mov	a,@r0
      001BB7 C0 E0            [24] 5678 	push	acc
      001BB9 08               [12] 5679 	inc	r0
      001BBA E6               [12] 5680 	mov	a,@r0
      001BBB C0 E0            [24] 5681 	push	acc
      001BBD 08               [12] 5682 	inc	r0
      001BBE E6               [12] 5683 	mov	a,@r0
      001BBF C0 E0            [24] 5684 	push	acc
                           001B0A  5685 	C$fuzzy.h$1474$1_0$84 ==.
                                   5686 ;	../../fuzzy.h:1474: !maximum_found ||
      001BC1 E5 0E            [12] 5687 	mov	a,_bp
      001BC3 24 18            [12] 5688 	add	a,#0x18
      001BC5 F8               [12] 5689 	mov	r0,a
      001BC6 86 82            [24] 5690 	mov	dpl, @r0
      001BC8 08               [12] 5691 	inc	r0
      001BC9 86 83            [24] 5692 	mov	dph, @r0
      001BCB 08               [12] 5693 	inc	r0
      001BCC 86 F0            [24] 5694 	mov	b, @r0
      001BCE 08               [12] 5695 	inc	r0
      001BCF E6               [12] 5696 	mov	a, @r0
      001BD0 12 24 59         [24] 5697 	lcall	___fsadd
      001BD3 C8               [12] 5698 	xch	a,r0
      001BD4 E5 0E            [12] 5699 	mov	a,_bp
      001BD6 24 18            [12] 5700 	add	a,#0x18
      001BD8 C8               [12] 5701 	xch	a,r0
      001BD9 A6 82            [24] 5702 	mov	@r0, dpl
      001BDB 08               [12] 5703 	inc	r0
      001BDC A6 83            [24] 5704 	mov	@r0, dph
      001BDE 08               [12] 5705 	inc	r0
      001BDF A6 F0            [24] 5706 	mov	@r0, b
      001BE1 08               [12] 5707 	inc	r0
      001BE2 F6               [12] 5708 	mov	@r0,a
      001BE3 E5 81            [12] 5709 	mov	a,sp
      001BE5 24 FC            [12] 5710 	add	a,#0xfc
      001BE7 F5 81            [12] 5711 	mov	sp,a
      001BE9 E5 0E            [12] 5712 	mov	a,_bp
      001BEB 24 3C            [12] 5713 	add	a,#0x3c
      001BED F8               [12] 5714 	mov	r0,a
      001BEE E6               [12] 5715 	mov	a,@r0
      001BEF 60 31            [24] 5716 	jz	00114$
                           001B3A  5717 	C$fuzzy.h$1476$1_0$84 ==.
                                   5718 ;	../../fuzzy.h:1476: ) {
      001BF1 E5 0E            [12] 5719 	mov	a,_bp
      001BF3 24 30            [12] 5720 	add	a,#0x30
      001BF5 F8               [12] 5721 	mov	r0,a
      001BF6 E6               [12] 5722 	mov	a,@r0
      001BF7 C0 E0            [24] 5723 	push	acc
      001BF9 08               [12] 5724 	inc	r0
      001BFA E6               [12] 5725 	mov	a,@r0
      001BFB C0 E0            [24] 5726 	push	acc
      001BFD 08               [12] 5727 	inc	r0
      001BFE E6               [12] 5728 	mov	a,@r0
      001BFF C0 E0            [24] 5729 	push	acc
      001C01 08               [12] 5730 	inc	r0
      001C02 E6               [12] 5731 	mov	a,@r0
      001C03 C0 E0            [24] 5732 	push	acc
      001C05 E5 0E            [12] 5733 	mov	a,_bp
      001C07 24 1C            [12] 5734 	add	a,#0x1c
      001C09 F8               [12] 5735 	mov	r0,a
      001C0A 86 82            [24] 5736 	mov	dpl, @r0
      001C0C 08               [12] 5737 	inc	r0
      001C0D 86 83            [24] 5738 	mov	dph, @r0
      001C0F 08               [12] 5739 	inc	r0
      001C10 86 F0            [24] 5740 	mov	b, @r0
      001C12 08               [12] 5741 	inc	r0
      001C13 E6               [12] 5742 	mov	a, @r0
      001C14 12 24 07         [24] 5743 	lcall	___fslt
      001C17 AF 82            [24] 5744 	mov	r7, dpl
      001C19 E5 81            [12] 5745 	mov	a,sp
      001C1B 24 FC            [12] 5746 	add	a,#0xfc
      001C1D F5 81            [12] 5747 	mov	sp,a
      001C1F EF               [12] 5748 	mov	a,r7
      001C20 60 74            [24] 5749 	jz	00115$
      001C22                       5750 00114$:
                           001B6B  5751 	C$fuzzy.h$1478$4_0$91 ==.
                                   5752 ;	../../fuzzy.h:1478: aggregated_height;
      001C22 E5 0E            [12] 5753 	mov	a,_bp
      001C24 24 30            [12] 5754 	add	a,#0x30
      001C26 F8               [12] 5755 	mov	r0,a
      001C27 E5 0E            [12] 5756 	mov	a,_bp
      001C29 24 1C            [12] 5757 	add	a,#0x1c
      001C2B F9               [12] 5758 	mov	r1,a
      001C2C E6               [12] 5759 	mov	a,@r0
      001C2D F7               [12] 5760 	mov	@r1,a
      001C2E 08               [12] 5761 	inc	r0
      001C2F E6               [12] 5762 	mov	a,@r0
      001C30 09               [12] 5763 	inc	r1
      001C31 F7               [12] 5764 	mov	@r1,a
      001C32 08               [12] 5765 	inc	r0
      001C33 E6               [12] 5766 	mov	a,@r0
      001C34 09               [12] 5767 	inc	r1
      001C35 F7               [12] 5768 	mov	@r1,a
      001C36 08               [12] 5769 	inc	r0
      001C37 E6               [12] 5770 	mov	a,@r0
      001C38 09               [12] 5771 	inc	r1
      001C39 F7               [12] 5772 	mov	@r1,a
                           001B83  5773 	C$fuzzy.h$1481$4_0$91 ==.
                                   5774 ;	../../fuzzy.h:1481: value;
      001C3A E5 0E            [12] 5775 	mov	a,_bp
      001C3C 24 2C            [12] 5776 	add	a,#0x2c
      001C3E F8               [12] 5777 	mov	r0,a
      001C3F E5 0E            [12] 5778 	mov	a,_bp
      001C41 24 24            [12] 5779 	add	a,#0x24
      001C43 F9               [12] 5780 	mov	r1,a
      001C44 E6               [12] 5781 	mov	a,@r0
      001C45 F7               [12] 5782 	mov	@r1,a
      001C46 08               [12] 5783 	inc	r0
      001C47 E6               [12] 5784 	mov	a,@r0
      001C48 09               [12] 5785 	inc	r1
      001C49 F7               [12] 5786 	mov	@r1,a
      001C4A 08               [12] 5787 	inc	r0
      001C4B E6               [12] 5788 	mov	a,@r0
      001C4C 09               [12] 5789 	inc	r1
      001C4D F7               [12] 5790 	mov	@r1,a
      001C4E 08               [12] 5791 	inc	r0
      001C4F E6               [12] 5792 	mov	a,@r0
      001C50 09               [12] 5793 	inc	r1
      001C51 F7               [12] 5794 	mov	@r1,a
                           001B9B  5795 	C$fuzzy.h$1484$4_0$91 ==.
                                   5796 ;	../../fuzzy.h:1484: value;
      001C52 E5 0E            [12] 5797 	mov	a,_bp
      001C54 24 2C            [12] 5798 	add	a,#0x2c
      001C56 F8               [12] 5799 	mov	r0,a
      001C57 E5 0E            [12] 5800 	mov	a,_bp
      001C59 24 28            [12] 5801 	add	a,#0x28
      001C5B F9               [12] 5802 	mov	r1,a
      001C5C E6               [12] 5803 	mov	a,@r0
      001C5D F7               [12] 5804 	mov	@r1,a
      001C5E 08               [12] 5805 	inc	r0
      001C5F E6               [12] 5806 	mov	a,@r0
      001C60 09               [12] 5807 	inc	r1
      001C61 F7               [12] 5808 	mov	@r1,a
      001C62 08               [12] 5809 	inc	r0
      001C63 E6               [12] 5810 	mov	a,@r0
      001C64 09               [12] 5811 	inc	r1
      001C65 F7               [12] 5812 	mov	@r1,a
      001C66 08               [12] 5813 	inc	r0
      001C67 E6               [12] 5814 	mov	a,@r0
      001C68 09               [12] 5815 	inc	r1
      001C69 F7               [12] 5816 	mov	@r1,a
                           001BB3  5817 	C$fuzzy.h$1487$4_0$91 ==.
                                   5818 ;	../../fuzzy.h:1487: value;
      001C6A E5 0E            [12] 5819 	mov	a,_bp
      001C6C 24 2C            [12] 5820 	add	a,#0x2c
      001C6E F8               [12] 5821 	mov	r0,a
      001C6F E5 0E            [12] 5822 	mov	a,_bp
      001C71 24 20            [12] 5823 	add	a,#0x20
      001C73 F9               [12] 5824 	mov	r1,a
      001C74 E6               [12] 5825 	mov	a,@r0
      001C75 F7               [12] 5826 	mov	@r1,a
      001C76 08               [12] 5827 	inc	r0
      001C77 E6               [12] 5828 	mov	a,@r0
      001C78 09               [12] 5829 	inc	r1
      001C79 F7               [12] 5830 	mov	@r1,a
      001C7A 08               [12] 5831 	inc	r0
      001C7B E6               [12] 5832 	mov	a,@r0
      001C7C 09               [12] 5833 	inc	r1
      001C7D F7               [12] 5834 	mov	@r1,a
      001C7E 08               [12] 5835 	inc	r0
      001C7F E6               [12] 5836 	mov	a,@r0
      001C80 09               [12] 5837 	inc	r1
      001C81 F7               [12] 5838 	mov	@r1,a
                           001BCB  5839 	C$fuzzy.h$1490$4_0$91 ==.
                                   5840 ;	../../fuzzy.h:1490: 1u;
      001C82 E5 0E            [12] 5841 	mov	a,_bp
      001C84 24 38            [12] 5842 	add	a,#0x38
      001C86 F8               [12] 5843 	mov	r0,a
      001C87 76 01            [12] 5844 	mov	@r0,#0x01
      001C89 08               [12] 5845 	inc	r0
      001C8A 76 00            [12] 5846 	mov	@r0,#0x00
                           001BD5  5847 	C$fuzzy.h$1493$4_0$91 ==.
                                   5848 ;	../../fuzzy.h:1493: true;
      001C8C E5 0E            [12] 5849 	mov	a,_bp
      001C8E 24 3C            [12] 5850 	add	a,#0x3c
      001C90 F8               [12] 5851 	mov	r0,a
      001C91 76 01            [12] 5852 	mov	@r0,#0x01
      001C93 02 1D 26         [24] 5853 	ljmp	00136$
      001C96                       5854 00115$:
                           001BDF  5855 	C$fuzzy.h$1497$1_0$84 ==.
                                   5856 ;	../../fuzzy.h:1497: ) {
      001C96 E5 0E            [12] 5857 	mov	a,_bp
      001C98 24 1C            [12] 5858 	add	a,#0x1c
      001C9A F8               [12] 5859 	mov	r0,a
      001C9B E6               [12] 5860 	mov	a,@r0
      001C9C C0 E0            [24] 5861 	push	acc
      001C9E 08               [12] 5862 	inc	r0
      001C9F E6               [12] 5863 	mov	a,@r0
      001CA0 C0 E0            [24] 5864 	push	acc
      001CA2 08               [12] 5865 	inc	r0
      001CA3 E6               [12] 5866 	mov	a,@r0
      001CA4 C0 E0            [24] 5867 	push	acc
      001CA6 08               [12] 5868 	inc	r0
      001CA7 E6               [12] 5869 	mov	a,@r0
      001CA8 C0 E0            [24] 5870 	push	acc
      001CAA E5 0E            [12] 5871 	mov	a,_bp
      001CAC 24 30            [12] 5872 	add	a,#0x30
      001CAE F8               [12] 5873 	mov	r0,a
      001CAF 86 82            [24] 5874 	mov	dpl, @r0
      001CB1 08               [12] 5875 	inc	r0
      001CB2 86 83            [24] 5876 	mov	dph, @r0
      001CB4 08               [12] 5877 	inc	r0
      001CB5 86 F0            [24] 5878 	mov	b, @r0
      001CB7 08               [12] 5879 	inc	r0
      001CB8 E6               [12] 5880 	mov	a, @r0
      001CB9 12 23 DB         [24] 5881 	lcall	___fseq
      001CBC AF 82            [24] 5882 	mov	r7, dpl
      001CBE E5 81            [12] 5883 	mov	a,sp
      001CC0 24 FC            [12] 5884 	add	a,#0xfc
      001CC2 F5 81            [12] 5885 	mov	sp,a
      001CC4 EF               [12] 5886 	mov	a,r7
      001CC5 60 5F            [24] 5887 	jz	00136$
                           001C10  5888 	C$fuzzy.h$1499$4_0$92 ==.
                                   5889 ;	../../fuzzy.h:1499: value;
      001CC7 E5 0E            [12] 5890 	mov	a,_bp
      001CC9 24 2C            [12] 5891 	add	a,#0x2c
      001CCB F8               [12] 5892 	mov	r0,a
      001CCC E5 0E            [12] 5893 	mov	a,_bp
      001CCE 24 28            [12] 5894 	add	a,#0x28
      001CD0 F9               [12] 5895 	mov	r1,a
      001CD1 E6               [12] 5896 	mov	a,@r0
      001CD2 F7               [12] 5897 	mov	@r1,a
      001CD3 08               [12] 5898 	inc	r0
      001CD4 E6               [12] 5899 	mov	a,@r0
      001CD5 09               [12] 5900 	inc	r1
      001CD6 F7               [12] 5901 	mov	@r1,a
      001CD7 08               [12] 5902 	inc	r0
      001CD8 E6               [12] 5903 	mov	a,@r0
      001CD9 09               [12] 5904 	inc	r1
      001CDA F7               [12] 5905 	mov	@r1,a
      001CDB 08               [12] 5906 	inc	r0
      001CDC E6               [12] 5907 	mov	a,@r0
      001CDD 09               [12] 5908 	inc	r1
      001CDE F7               [12] 5909 	mov	@r1,a
                           001C28  5910 	C$fuzzy.h$1502$1_0$84 ==.
                                   5911 ;	../../fuzzy.h:1502: value;
      001CDF E5 0E            [12] 5912 	mov	a,_bp
      001CE1 24 2C            [12] 5913 	add	a,#0x2c
      001CE3 F8               [12] 5914 	mov	r0,a
      001CE4 E6               [12] 5915 	mov	a,@r0
      001CE5 C0 E0            [24] 5916 	push	acc
      001CE7 08               [12] 5917 	inc	r0
      001CE8 E6               [12] 5918 	mov	a,@r0
      001CE9 C0 E0            [24] 5919 	push	acc
      001CEB 08               [12] 5920 	inc	r0
      001CEC E6               [12] 5921 	mov	a,@r0
      001CED C0 E0            [24] 5922 	push	acc
      001CEF 08               [12] 5923 	inc	r0
      001CF0 E6               [12] 5924 	mov	a,@r0
      001CF1 C0 E0            [24] 5925 	push	acc
                           001C3C  5926 	C$fuzzy.h$1504$1_0$84 ==.
                                   5927 ;	../../fuzzy.h:1504: maximum_count++;
      001CF3 E5 0E            [12] 5928 	mov	a,_bp
      001CF5 24 20            [12] 5929 	add	a,#0x20
      001CF7 F8               [12] 5930 	mov	r0,a
      001CF8 86 82            [24] 5931 	mov	dpl, @r0
      001CFA 08               [12] 5932 	inc	r0
      001CFB 86 83            [24] 5933 	mov	dph, @r0
      001CFD 08               [12] 5934 	inc	r0
      001CFE 86 F0            [24] 5935 	mov	b, @r0
      001D00 08               [12] 5936 	inc	r0
      001D01 E6               [12] 5937 	mov	a, @r0
      001D02 12 24 59         [24] 5938 	lcall	___fsadd
      001D05 C8               [12] 5939 	xch	a,r0
      001D06 E5 0E            [12] 5940 	mov	a,_bp
      001D08 24 20            [12] 5941 	add	a,#0x20
      001D0A C8               [12] 5942 	xch	a,r0
      001D0B A6 82            [24] 5943 	mov	@r0, dpl
      001D0D 08               [12] 5944 	inc	r0
      001D0E A6 83            [24] 5945 	mov	@r0, dph
      001D10 08               [12] 5946 	inc	r0
      001D11 A6 F0            [24] 5947 	mov	@r0, b
      001D13 08               [12] 5948 	inc	r0
      001D14 F6               [12] 5949 	mov	@r0,a
      001D15 E5 81            [12] 5950 	mov	a,sp
      001D17 24 FC            [12] 5951 	add	a,#0xfc
      001D19 F5 81            [12] 5952 	mov	sp,a
      001D1B E5 0E            [12] 5953 	mov	a,_bp
      001D1D 24 38            [12] 5954 	add	a,#0x38
      001D1F F8               [12] 5955 	mov	r0,a
      001D20 06               [12] 5956 	inc	@r0
      001D21 B6 00 02         [24] 5957 	cjne	@r0,#0x00,00295$
      001D24 08               [12] 5958 	inc	r0
      001D25 06               [12] 5959 	inc	@r0
      001D26                       5960 00295$:
      001D26                       5961 00136$:
                           001C6F  5962 	C$fuzzy.h$1414$1_0$84 ==.
                                   5963 ;	../../fuzzy.h:1414: ) {
      001D26 E5 0E            [12] 5964 	mov	a,_bp
      001D28 24 F2            [12] 5965 	add	a,#0xf2
      001D2A F8               [12] 5966 	mov	r0,a
      001D2B E6               [12] 5967 	mov	a,@r0
      001D2C C0 E0            [24] 5968 	push	acc
      001D2E 08               [12] 5969 	inc	r0
      001D2F E6               [12] 5970 	mov	a,@r0
      001D30 C0 E0            [24] 5971 	push	acc
      001D32 08               [12] 5972 	inc	r0
      001D33 E6               [12] 5973 	mov	a,@r0
      001D34 C0 E0            [24] 5974 	push	acc
      001D36 08               [12] 5975 	inc	r0
      001D37 E6               [12] 5976 	mov	a,@r0
      001D38 C0 E0            [24] 5977 	push	acc
      001D3A E5 0E            [12] 5978 	mov	a,_bp
      001D3C 24 2C            [12] 5979 	add	a,#0x2c
      001D3E F8               [12] 5980 	mov	r0,a
      001D3F 86 82            [24] 5981 	mov	dpl, @r0
      001D41 08               [12] 5982 	inc	r0
      001D42 86 83            [24] 5983 	mov	dph, @r0
      001D44 08               [12] 5984 	inc	r0
      001D45 86 F0            [24] 5985 	mov	b, @r0
      001D47 08               [12] 5986 	inc	r0
      001D48 E6               [12] 5987 	mov	a, @r0
      001D49 12 24 59         [24] 5988 	lcall	___fsadd
      001D4C C8               [12] 5989 	xch	a,r0
      001D4D E5 0E            [12] 5990 	mov	a,_bp
      001D4F 24 2C            [12] 5991 	add	a,#0x2c
      001D51 C8               [12] 5992 	xch	a,r0
      001D52 A6 82            [24] 5993 	mov	@r0, dpl
      001D54 08               [12] 5994 	inc	r0
      001D55 A6 83            [24] 5995 	mov	@r0, dph
      001D57 08               [12] 5996 	inc	r0
      001D58 A6 F0            [24] 5997 	mov	@r0, b
      001D5A 08               [12] 5998 	inc	r0
      001D5B F6               [12] 5999 	mov	@r0,a
      001D5C E5 81            [12] 6000 	mov	a,sp
      001D5E 24 FC            [12] 6001 	add	a,#0xfc
      001D60 F5 81            [12] 6002 	mov	sp,a
      001D62 02 19 31         [24] 6003 	ljmp	00135$
      001D65                       6004 00118$:
                           001CAE  6005 	C$fuzzy.h$1512$1_0$84 ==.
                                   6006 ;	../../fuzzy.h:1512: !maximum_found ||
      001D65 E5 0E            [12] 6007 	mov	a,_bp
      001D67 24 3C            [12] 6008 	add	a,#0x3c
      001D69 F8               [12] 6009 	mov	r0,a
      001D6A E6               [12] 6010 	mov	a,@r0
      001D6B 60 56            [24] 6011 	jz	00119$
                           001CB6  6012 	C$fuzzy.h$1513$1_0$84 ==.
                                   6013 ;	../../fuzzy.h:1513: maximum_height <= LEVEL_LO ||
      001D6D E5 0E            [12] 6014 	mov	a,_bp
      001D6F 24 1C            [12] 6015 	add	a,#0x1c
      001D71 F8               [12] 6016 	mov	r0,a
      001D72 E6               [12] 6017 	mov	a,@r0
      001D73 C0 E0            [24] 6018 	push	acc
      001D75 08               [12] 6019 	inc	r0
      001D76 E6               [12] 6020 	mov	a,@r0
      001D77 C0 E0            [24] 6021 	push	acc
      001D79 08               [12] 6022 	inc	r0
      001D7A E6               [12] 6023 	mov	a,@r0
      001D7B C0 E0            [24] 6024 	push	acc
      001D7D 08               [12] 6025 	inc	r0
      001D7E E6               [12] 6026 	mov	a,@r0
      001D7F C0 E0            [24] 6027 	push	acc
      001D81 90 00 00         [24] 6028 	mov	dptr,#0x0000
      001D84 E4               [12] 6029 	clr	a
      001D85 F5 F0            [12] 6030 	mov	b,a
      001D87 12 24 07         [24] 6031 	lcall	___fslt
      001D8A E5 81            [12] 6032 	mov	a,sp
      001D8C 24 FC            [12] 6033 	add	a,#0xfc
      001D8E F5 81            [12] 6034 	mov	sp,a
      001D90 E5 82            [12] 6035 	mov	a, dpl
      001D92 24 FF            [12] 6036 	add	a,#0xff
      001D94 92 00            [24] 6037 	mov	b0,c
      001D96 50 2B            [24] 6038 	jnc	00119$
                           001CE1  6039 	C$fuzzy.h$1515$1_0$84 ==.
                                   6040 ;	../../fuzzy.h:1515: ) {
      001D98 E5 0E            [12] 6041 	mov	a,_bp
      001D9A 24 18            [12] 6042 	add	a,#0x18
      001D9C F8               [12] 6043 	mov	r0,a
      001D9D E6               [12] 6044 	mov	a,@r0
      001D9E C0 E0            [24] 6045 	push	acc
      001DA0 08               [12] 6046 	inc	r0
      001DA1 E6               [12] 6047 	mov	a,@r0
      001DA2 C0 E0            [24] 6048 	push	acc
      001DA4 08               [12] 6049 	inc	r0
      001DA5 E6               [12] 6050 	mov	a,@r0
      001DA6 C0 E0            [24] 6051 	push	acc
      001DA8 08               [12] 6052 	inc	r0
      001DA9 E6               [12] 6053 	mov	a,@r0
      001DAA C0 E0            [24] 6054 	push	acc
      001DAC 90 00 00         [24] 6055 	mov	dptr,#0x0000
      001DAF E4               [12] 6056 	clr	a
      001DB0 F5 F0            [12] 6057 	mov	b,a
      001DB2 12 24 07         [24] 6058 	lcall	___fslt
      001DB5 E5 81            [12] 6059 	mov	a,sp
      001DB7 24 FC            [12] 6060 	add	a,#0xfc
      001DB9 F5 81            [12] 6061 	mov	sp,a
      001DBB E5 82            [12] 6062 	mov	a, dpl
      001DBD 24 FF            [12] 6063 	add	a,#0xff
      001DBF 92 00            [24] 6064 	mov	b0,c
      001DC1 40 09            [24] 6065 	jc	00120$
      001DC3                       6066 00119$:
                           001D0C  6067 	C$fuzzy.h$1516$2_0$93 ==.
                                   6068 ;	../../fuzzy.h:1516: return 0.0f;
      001DC3 90 00 00         [24] 6069 	mov	dptr,#0x0000
      001DC6 E4               [12] 6070 	clr	a
      001DC7 F5 F0            [12] 6071 	mov	b,a
      001DC9 02 1E AC         [24] 6072 	ljmp	00137$
      001DCC                       6073 00120$:
                           001D15  6074 	C$fuzzy.h$1519$1_0$84 ==.
                                   6075 ;	../../fuzzy.h:1519: switch (method) {
      001DCC E5 0E            [12] 6076 	mov	a,_bp
      001DCE 24 F1            [12] 6077 	add	a,#0xf1
      001DD0 F8               [12] 6078 	mov	r0,a
      001DD1 E6               [12] 6079 	mov	a,@r0
      001DD2 24 FC            [12] 6080 	add	a,#0xff - 0x03
      001DD4 50 03            [24] 6081 	jnc	00299$
      001DD6 02 1E A6         [24] 6082 	ljmp	00129$
      001DD9                       6083 00299$:
      001DD9 E5 0E            [12] 6084 	mov	a,_bp
      001DDB 24 F1            [12] 6085 	add	a,#0xf1
      001DDD F8               [12] 6086 	mov	r0,a
      001DDE E6               [12] 6087 	mov	a,@r0
      001DDF 26               [12] 6088 	add	a,@r0
      001DE0 26               [12] 6089 	add	a,@r0
      001DE1 90 1D E5         [24] 6090 	mov	dptr,#00300$
      001DE4 73               [24] 6091 	jmp	@a+dptr
      001DE5                       6092 00300$:
      001DE5 02 1D F1         [24] 6093 	ljmp	00123$
      001DE8 02 1E 2E         [24] 6094 	ljmp	00124$
      001DEB 02 1E 84         [24] 6095 	ljmp	00127$
      001DEE 02 1E 95         [24] 6096 	ljmp	00128$
                           001D3A  6097 	C$fuzzy.h$1520$2_0$94 ==.
                                   6098 ;	../../fuzzy.h:1520: case FUZZY_DEFUZZ_COG:
      001DF1                       6099 00123$:
                           001D3A  6100 	C$fuzzy.h$1522$1_0$84 ==.
                                   6101 ;	../../fuzzy.h:1522: height_sum;
      001DF1 E5 0E            [12] 6102 	mov	a,_bp
      001DF3 24 18            [12] 6103 	add	a,#0x18
      001DF5 F8               [12] 6104 	mov	r0,a
      001DF6 E6               [12] 6105 	mov	a,@r0
      001DF7 C0 E0            [24] 6106 	push	acc
      001DF9 08               [12] 6107 	inc	r0
      001DFA E6               [12] 6108 	mov	a,@r0
      001DFB C0 E0            [24] 6109 	push	acc
      001DFD 08               [12] 6110 	inc	r0
      001DFE E6               [12] 6111 	mov	a,@r0
      001DFF C0 E0            [24] 6112 	push	acc
      001E01 08               [12] 6113 	inc	r0
      001E02 E6               [12] 6114 	mov	a,@r0
      001E03 C0 E0            [24] 6115 	push	acc
      001E05 E5 0E            [12] 6116 	mov	a,_bp
      001E07 24 14            [12] 6117 	add	a,#0x14
      001E09 F8               [12] 6118 	mov	r0,a
      001E0A 86 82            [24] 6119 	mov	dpl, @r0
      001E0C 08               [12] 6120 	inc	r0
      001E0D 86 83            [24] 6121 	mov	dph, @r0
      001E0F 08               [12] 6122 	inc	r0
      001E10 86 F0            [24] 6123 	mov	b, @r0
      001E12 08               [12] 6124 	inc	r0
      001E13 E6               [12] 6125 	mov	a, @r0
      001E14 12 25 70         [24] 6126 	lcall	___fsdiv
      001E17 AC 82            [24] 6127 	mov	r4, dpl
      001E19 AD 83            [24] 6128 	mov	r5, dph
      001E1B AE F0            [24] 6129 	mov	r6, b
      001E1D FF               [12] 6130 	mov	r7, a
      001E1E E5 81            [12] 6131 	mov	a,sp
      001E20 24 FC            [12] 6132 	add	a,#0xfc
      001E22 F5 81            [12] 6133 	mov	sp,a
      001E24 8C 82            [24] 6134 	mov	dpl, r4
      001E26 8D 83            [24] 6135 	mov	dph, r5
      001E28 8E F0            [24] 6136 	mov	b, r6
      001E2A EF               [12] 6137 	mov	a, r7
      001E2B 02 1E AC         [24] 6138 	ljmp	00137$
                           001D77  6139 	C$fuzzy.h$1524$2_0$94 ==.
                                   6140 ;	../../fuzzy.h:1524: case FUZZY_DEFUZZ_MOM:
      001E2E                       6141 00124$:
                           001D77  6142 	C$fuzzy.h$1525$2_0$94 ==.
                                   6143 ;	../../fuzzy.h:1525: if (maximum_count == 0u) {
      001E2E E5 0E            [12] 6144 	mov	a,_bp
      001E30 24 38            [12] 6145 	add	a,#0x38
      001E32 F8               [12] 6146 	mov	r0,a
      001E33 E6               [12] 6147 	mov	a,@r0
      001E34 08               [12] 6148 	inc	r0
      001E35 46               [12] 6149 	orl	a,@r0
      001E36 70 08            [24] 6150 	jnz	00126$
                           001D81  6151 	C$fuzzy.h$1526$3_0$95 ==.
                                   6152 ;	../../fuzzy.h:1526: return 0.0f;
      001E38 90 00 00         [24] 6153 	mov	dptr,#0x0000
      001E3B E4               [12] 6154 	clr	a
      001E3C F5 F0            [12] 6155 	mov	b,a
      001E3E 80 6C            [24] 6156 	sjmp	00137$
      001E40                       6157 00126$:
                           001D89  6158 	C$fuzzy.h$1530$1_0$84 ==.
                                   6159 ;	../../fuzzy.h:1530: (float)maximum_count;
      001E40 E5 0E            [12] 6160 	mov	a,_bp
      001E42 24 38            [12] 6161 	add	a,#0x38
      001E44 F8               [12] 6162 	mov	r0,a
      001E45 86 82            [24] 6163 	mov	dpl, @r0
      001E47 08               [12] 6164 	inc	r0
      001E48 86 83            [24] 6165 	mov	dph, @r0
      001E4A 12 24 FB         [24] 6166 	lcall	___uint2fs
      001E4D AC 82            [24] 6167 	mov	r4, dpl
      001E4F AD 83            [24] 6168 	mov	r5, dph
      001E51 AE F0            [24] 6169 	mov	r6, b
      001E53 FF               [12] 6170 	mov	r7, a
      001E54 C0 04            [24] 6171 	push	ar4
      001E56 C0 05            [24] 6172 	push	ar5
      001E58 C0 06            [24] 6173 	push	ar6
      001E5A C0 07            [24] 6174 	push	ar7
      001E5C E5 0E            [12] 6175 	mov	a,_bp
      001E5E 24 20            [12] 6176 	add	a,#0x20
      001E60 F8               [12] 6177 	mov	r0,a
      001E61 86 82            [24] 6178 	mov	dpl, @r0
      001E63 08               [12] 6179 	inc	r0
      001E64 86 83            [24] 6180 	mov	dph, @r0
      001E66 08               [12] 6181 	inc	r0
      001E67 86 F0            [24] 6182 	mov	b, @r0
      001E69 08               [12] 6183 	inc	r0
      001E6A E6               [12] 6184 	mov	a, @r0
      001E6B 12 25 70         [24] 6185 	lcall	___fsdiv
      001E6E AC 82            [24] 6186 	mov	r4, dpl
      001E70 AD 83            [24] 6187 	mov	r5, dph
      001E72 AE F0            [24] 6188 	mov	r6, b
      001E74 FF               [12] 6189 	mov	r7, a
      001E75 E5 81            [12] 6190 	mov	a,sp
      001E77 24 FC            [12] 6191 	add	a,#0xfc
      001E79 F5 81            [12] 6192 	mov	sp,a
      001E7B 8C 82            [24] 6193 	mov	dpl, r4
      001E7D 8D 83            [24] 6194 	mov	dph, r5
      001E7F 8E F0            [24] 6195 	mov	b, r6
      001E81 EF               [12] 6196 	mov	a, r7
                           001DCB  6197 	C$fuzzy.h$1532$2_0$94 ==.
                                   6198 ;	../../fuzzy.h:1532: case FUZZY_DEFUZZ_SOM:
      001E82 80 28            [24] 6199 	sjmp	00137$
      001E84                       6200 00127$:
                           001DCD  6201 	C$fuzzy.h$1533$2_0$94 ==.
                                   6202 ;	../../fuzzy.h:1533: return smallest_maximum;
      001E84 E5 0E            [12] 6203 	mov	a,_bp
      001E86 24 24            [12] 6204 	add	a,#0x24
      001E88 F8               [12] 6205 	mov	r0,a
      001E89 86 82            [24] 6206 	mov	dpl, @r0
      001E8B 08               [12] 6207 	inc	r0
      001E8C 86 83            [24] 6208 	mov	dph, @r0
      001E8E 08               [12] 6209 	inc	r0
      001E8F 86 F0            [24] 6210 	mov	b, @r0
      001E91 08               [12] 6211 	inc	r0
      001E92 E6               [12] 6212 	mov	a, @r0
                           001DDC  6213 	C$fuzzy.h$1535$2_0$94 ==.
                                   6214 ;	../../fuzzy.h:1535: case FUZZY_DEFUZZ_LOM:
      001E93 80 17            [24] 6215 	sjmp	00137$
      001E95                       6216 00128$:
                           001DDE  6217 	C$fuzzy.h$1536$2_0$94 ==.
                                   6218 ;	../../fuzzy.h:1536: return largest_maximum;
      001E95 E5 0E            [12] 6219 	mov	a,_bp
      001E97 24 28            [12] 6220 	add	a,#0x28
      001E99 F8               [12] 6221 	mov	r0,a
      001E9A 86 82            [24] 6222 	mov	dpl, @r0
      001E9C 08               [12] 6223 	inc	r0
      001E9D 86 83            [24] 6224 	mov	dph, @r0
      001E9F 08               [12] 6225 	inc	r0
      001EA0 86 F0            [24] 6226 	mov	b, @r0
      001EA2 08               [12] 6227 	inc	r0
      001EA3 E6               [12] 6228 	mov	a, @r0
                           001DED  6229 	C$fuzzy.h$1538$2_0$94 ==.
                                   6230 ;	../../fuzzy.h:1538: default:
      001EA4 80 06            [24] 6231 	sjmp	00137$
      001EA6                       6232 00129$:
                           001DEF  6233 	C$fuzzy.h$1539$2_0$94 ==.
                                   6234 ;	../../fuzzy.h:1539: return 0.0f;
      001EA6 90 00 00         [24] 6235 	mov	dptr,#0x0000
      001EA9 E4               [12] 6236 	clr	a
      001EAA F5 F0            [12] 6237 	mov	b,a
                           001DF5  6238 	C$fuzzy.h$1540$1_0$84 ==.
                                   6239 ;	../../fuzzy.h:1540: }
      001EAC                       6240 00137$:
                           001DF5  6241 	C$fuzzy.h$1541$1_0$84 ==.
                                   6242 ;	../../fuzzy.h:1541: }
      001EAC 85 0E 81         [24] 6243 	mov	sp,_bp
      001EAF D0 0E            [24] 6244 	pop	_bp
                           001DFA  6245 	C$fuzzy.h$1541$1_0$84 ==.
                           001DFA  6246 	XG$fuzzy_rules_defuzzify$0$0 ==.
      001EB1 22               [24] 6247 	ret
                                   6248 ;------------------------------------------------------------
                                   6249 ;Allocation info for local variables in function 'fuzzy_rules_cog'
                                   6250 ;------------------------------------------------------------
                                   6251 ;lower         Allocated to stack - _bp -6 +4 
                                   6252 ;upper         Allocated to stack - _bp -10 +4 
                                   6253 ;step          Allocated to stack - _bp -14 +4 
                                   6254 ;rules         Allocated to registers r5 r6 r7 
                                   6255 ;------------------------------------------------------------
                           001DFB  6256 	G$fuzzy_rules_cog$0$0 ==.
                           001DFB  6257 	C$fuzzy.h$1547$1_0$97 ==.
                                   6258 ;	../../fuzzy.h:1547: float fuzzy_rules_cog(
                                   6259 ;	-----------------------------------------
                                   6260 ;	 function fuzzy_rules_cog
                                   6261 ;	-----------------------------------------
      001EB2                       6262 _fuzzy_rules_cog:
      001EB2 C0 0E            [24] 6263 	push	_bp
      001EB4 85 81 0E         [24] 6264 	mov	_bp,sp
      001EB7 AD 82            [24] 6265 	mov	r5, dpl
      001EB9 AE 83            [24] 6266 	mov	r6, dph
      001EBB AF F0            [24] 6267 	mov	r7, b
                           001E06  6268 	C$fuzzy.h$1555$1_0$97 ==.
                                   6269 ;	../../fuzzy.h:1555: rules,
      001EBD E4               [12] 6270 	clr	a
      001EBE C0 E0            [24] 6271 	push	acc
      001EC0 E5 0E            [12] 6272 	mov	a,_bp
      001EC2 24 F2            [12] 6273 	add	a,#0xf2
      001EC4 F8               [12] 6274 	mov	r0,a
      001EC5 E6               [12] 6275 	mov	a,@r0
      001EC6 C0 E0            [24] 6276 	push	acc
      001EC8 08               [12] 6277 	inc	r0
      001EC9 E6               [12] 6278 	mov	a,@r0
      001ECA C0 E0            [24] 6279 	push	acc
      001ECC 08               [12] 6280 	inc	r0
      001ECD E6               [12] 6281 	mov	a,@r0
      001ECE C0 E0            [24] 6282 	push	acc
      001ED0 08               [12] 6283 	inc	r0
      001ED1 E6               [12] 6284 	mov	a,@r0
      001ED2 C0 E0            [24] 6285 	push	acc
      001ED4 E5 0E            [12] 6286 	mov	a,_bp
      001ED6 24 F6            [12] 6287 	add	a,#0xf6
      001ED8 F8               [12] 6288 	mov	r0,a
      001ED9 E6               [12] 6289 	mov	a,@r0
      001EDA C0 E0            [24] 6290 	push	acc
      001EDC 08               [12] 6291 	inc	r0
      001EDD E6               [12] 6292 	mov	a,@r0
      001EDE C0 E0            [24] 6293 	push	acc
      001EE0 08               [12] 6294 	inc	r0
      001EE1 E6               [12] 6295 	mov	a,@r0
      001EE2 C0 E0            [24] 6296 	push	acc
      001EE4 08               [12] 6297 	inc	r0
      001EE5 E6               [12] 6298 	mov	a,@r0
      001EE6 C0 E0            [24] 6299 	push	acc
      001EE8 E5 0E            [12] 6300 	mov	a,_bp
      001EEA 24 FA            [12] 6301 	add	a,#0xfa
      001EEC F8               [12] 6302 	mov	r0,a
      001EED E6               [12] 6303 	mov	a,@r0
      001EEE C0 E0            [24] 6304 	push	acc
      001EF0 08               [12] 6305 	inc	r0
      001EF1 E6               [12] 6306 	mov	a,@r0
      001EF2 C0 E0            [24] 6307 	push	acc
      001EF4 08               [12] 6308 	inc	r0
      001EF5 E6               [12] 6309 	mov	a,@r0
      001EF6 C0 E0            [24] 6310 	push	acc
      001EF8 08               [12] 6311 	inc	r0
      001EF9 E6               [12] 6312 	mov	a,@r0
      001EFA C0 E0            [24] 6313 	push	acc
      001EFC 8D 82            [24] 6314 	mov	dpl, r5
      001EFE 8E 83            [24] 6315 	mov	dph, r6
      001F00 8F F0            [24] 6316 	mov	b, r7
      001F02 12 17 B6         [24] 6317 	lcall	_fuzzy_rules_defuzzify
      001F05 AC 82            [24] 6318 	mov	r4, dpl
      001F07 AD 83            [24] 6319 	mov	r5, dph
      001F09 AE F0            [24] 6320 	mov	r6, b
      001F0B FF               [12] 6321 	mov	r7, a
      001F0C E5 81            [12] 6322 	mov	a,sp
      001F0E 24 F3            [12] 6323 	add	a,#0xf3
      001F10 F5 81            [12] 6324 	mov	sp,a
      001F12 8C 82            [24] 6325 	mov	dpl, r4
      001F14 8D 83            [24] 6326 	mov	dph, r5
      001F16 8E F0            [24] 6327 	mov	b, r6
      001F18 EF               [12] 6328 	mov	a, r7
                           001E62  6329 	C$fuzzy.h$1561$1_0$97 ==.
                                   6330 ;	../../fuzzy.h:1561: }
      001F19 D0 0E            [24] 6331 	pop	_bp
                           001E64  6332 	C$fuzzy.h$1561$1_0$97 ==.
                           001E64  6333 	XG$fuzzy_rules_cog$0$0 ==.
      001F1B 22               [24] 6334 	ret
                                   6335 ;------------------------------------------------------------
                                   6336 ;Allocation info for local variables in function 'fuzzy_rules_free'
                                   6337 ;------------------------------------------------------------
                                   6338 ;rules         Allocated to registers r5 r6 r7 
                                   6339 ;------------------------------------------------------------
                           001E65  6340 	G$fuzzy_rules_free$0$0 ==.
                           001E65  6341 	C$fuzzy.h$1563$1_0$99 ==.
                                   6342 ;	../../fuzzy.h:1563: void fuzzy_rules_free(
                                   6343 ;	-----------------------------------------
                                   6344 ;	 function fuzzy_rules_free
                                   6345 ;	-----------------------------------------
      001F1C                       6346 _fuzzy_rules_free:
      001F1C AD 82            [24] 6347 	mov	r5, dpl
      001F1E AE 83            [24] 6348 	mov	r6, dph
      001F20 AF F0            [24] 6349 	mov	r7, b
                           001E6B  6350 	C$fuzzy.h$1567$1_0$99 ==.
                                   6351 ;	../../fuzzy.h:1567: if (rules == NULL) {
      001F22 ED               [12] 6352 	mov	a,r5
      001F23 4E               [12] 6353 	orl	a,r6
      001F24 70 02            [24] 6354 	jnz	00102$
                           001E6F  6355 	C$fuzzy.h$1568$2_0$100 ==.
                                   6356 ;	../../fuzzy.h:1568: return;
      001F26 80 15            [24] 6357 	sjmp	00103$
      001F28                       6358 00102$:
                           001E71  6359 	C$fuzzy.h$1576$1_0$99 ==.
                                   6360 ;	../../fuzzy.h:1576: rules->count = 0;
      001F28 74 48            [12] 6361 	mov	a,#0x48
      001F2A 2D               [12] 6362 	add	a, r5
      001F2B FD               [12] 6363 	mov	r5,a
      001F2C E4               [12] 6364 	clr	a
      001F2D 3E               [12] 6365 	addc	a, r6
      001F2E FE               [12] 6366 	mov	r6,a
      001F2F 8D 82            [24] 6367 	mov	dpl,r5
      001F31 8E 83            [24] 6368 	mov	dph,r6
      001F33 8F F0            [24] 6369 	mov	b,r7
      001F35 E4               [12] 6370 	clr	a
      001F36 12 23 EC         [24] 6371 	lcall	__gptrput
      001F39 A3               [24] 6372 	inc	dptr
      001F3A 12 23 EC         [24] 6373 	lcall	__gptrput
      001F3D                       6374 00103$:
                           001E86  6375 	C$fuzzy.h$1577$1_0$99 ==.
                                   6376 ;	../../fuzzy.h:1577: }
                           001E86  6377 	C$fuzzy.h$1577$1_0$99 ==.
                           001E86  6378 	XG$fuzzy_rules_free$0$0 ==.
      001F3D 22               [24] 6379 	ret
                                   6380 ;------------------------------------------------------------
                                   6381 ;Allocation info for local variables in function 'temperature_low'
                                   6382 ;------------------------------------------------------------
                                   6383 ;value         Allocated to registers r4 r5 r6 r7 
                                   6384 ;------------------------------------------------------------
                           001E87  6385 	Fcontroller_8051$temperature_low$0$0 ==.
                           001E87  6386 	C$controller_8051.c$59$1_0$102 ==.
                                   6387 ;	../../controller_8051.c:59: static float temperature_low(
                                   6388 ;	-----------------------------------------
                                   6389 ;	 function temperature_low
                                   6390 ;	-----------------------------------------
      001F3E                       6391 _temperature_low:
      001F3E AC 82            [24] 6392 	mov	r4,dpl
      001F40 AD 83            [24] 6393 	mov	r5,dph
      001F42 AE F0            [24] 6394 	mov	r6,b
      001F44 FF               [12] 6395 	mov	r7,a
                           001E8E  6396 	C$controller_8051.c$68$1_0$102 ==.
                                   6397 ;	../../controller_8051.c:68: hedges.none
      001F45 90 26 F5         [24] 6398 	mov	dptr,#_hedges
      001F48 E4               [12] 6399 	clr	a
      001F49 93               [24] 6400 	movc	a,@a+dptr
      001F4A FB               [12] 6401 	mov	r3,a
                           001E94  6402 	C$controller_8051.c$64$1_0$102 ==.
                                   6403 ;	../../controller_8051.c:64: 20.0f,
      001F4B C0 03            [24] 6404 	push	ar3
      001F4D E4               [12] 6405 	clr	a
      001F4E C0 E0            [24] 6406 	push	acc
      001F50 C0 04            [24] 6407 	push	ar4
      001F52 C0 05            [24] 6408 	push	ar5
      001F54 C0 06            [24] 6409 	push	ar6
      001F56 C0 07            [24] 6410 	push	ar7
      001F58 C0 E0            [24] 6411 	push	acc
      001F5A C0 E0            [24] 6412 	push	acc
      001F5C 74 20            [12] 6413 	mov	a,#0x20
      001F5E C0 E0            [24] 6414 	push	acc
      001F60 74 42            [12] 6415 	mov	a,#0x42
      001F62 C0 E0            [24] 6416 	push	acc
      001F64 90 00 00         [24] 6417 	mov	dptr,#0x0000
      001F67 75 F0 A0         [24] 6418 	mov	b, #0xa0
      001F6A 14               [12] 6419 	dec	a
      001F6B 12 0A B9         [24] 6420 	lcall	_fuzzy_ramp
      001F6E AC 82            [24] 6421 	mov	r4, dpl
      001F70 AD 83            [24] 6422 	mov	r5, dph
      001F72 AE F0            [24] 6423 	mov	r6, b
      001F74 FF               [12] 6424 	mov	r7, a
      001F75 E5 81            [12] 6425 	mov	a,sp
      001F77 24 F6            [12] 6426 	add	a,#0xf6
      001F79 F5 81            [12] 6427 	mov	sp,a
      001F7B 8C 82            [24] 6428 	mov	dpl, r4
      001F7D 8D 83            [24] 6429 	mov	dph, r5
      001F7F 8E F0            [24] 6430 	mov	b, r6
      001F81 EF               [12] 6431 	mov	a, r7
                           001ECB  6432 	C$controller_8051.c$70$1_0$102 ==.
                                   6433 ;	../../controller_8051.c:70: }
                           001ECB  6434 	C$controller_8051.c$70$1_0$102 ==.
                           001ECB  6435 	XFcontroller_8051$temperature_low$0$0 ==.
      001F82 22               [24] 6436 	ret
                                   6437 ;------------------------------------------------------------
                                   6438 ;Allocation info for local variables in function 'temperature_high'
                                   6439 ;------------------------------------------------------------
                                   6440 ;value         Allocated to registers r4 r5 r6 r7 
                                   6441 ;------------------------------------------------------------
                           001ECC  6442 	Fcontroller_8051$temperature_high$0$0 ==.
                           001ECC  6443 	C$controller_8051.c$73$1_0$104 ==.
                                   6444 ;	../../controller_8051.c:73: static float temperature_high(
                                   6445 ;	-----------------------------------------
                                   6446 ;	 function temperature_high
                                   6447 ;	-----------------------------------------
      001F83                       6448 _temperature_high:
      001F83 AC 82            [24] 6449 	mov	r4,dpl
      001F85 AD 83            [24] 6450 	mov	r5,dph
      001F87 AE F0            [24] 6451 	mov	r6,b
      001F89 FF               [12] 6452 	mov	r7,a
                           001ED3  6453 	C$controller_8051.c$82$1_0$104 ==.
                                   6454 ;	../../controller_8051.c:82: hedges.none
      001F8A 90 26 F5         [24] 6455 	mov	dptr,#_hedges
      001F8D E4               [12] 6456 	clr	a
      001F8E 93               [24] 6457 	movc	a,@a+dptr
      001F8F FB               [12] 6458 	mov	r3,a
                           001ED9  6459 	C$controller_8051.c$78$1_0$104 ==.
                                   6460 ;	../../controller_8051.c:78: 30.0f,
      001F90 C0 03            [24] 6461 	push	ar3
      001F92 74 01            [12] 6462 	mov	a,#0x01
      001F94 C0 E0            [24] 6463 	push	acc
      001F96 C0 04            [24] 6464 	push	ar4
      001F98 C0 05            [24] 6465 	push	ar5
      001F9A C0 06            [24] 6466 	push	ar6
      001F9C C0 07            [24] 6467 	push	ar7
      001F9E E4               [12] 6468 	clr	a
      001F9F C0 E0            [24] 6469 	push	acc
      001FA1 C0 E0            [24] 6470 	push	acc
      001FA3 74 70            [12] 6471 	mov	a,#0x70
      001FA5 C0 E0            [24] 6472 	push	acc
      001FA7 74 42            [12] 6473 	mov	a,#0x42
      001FA9 C0 E0            [24] 6474 	push	acc
      001FAB 90 00 00         [24] 6475 	mov	dptr,#0x0000
      001FAE 75 F0 F0         [24] 6476 	mov	b, #0xf0
      001FB1 14               [12] 6477 	dec	a
      001FB2 12 0A B9         [24] 6478 	lcall	_fuzzy_ramp
      001FB5 AC 82            [24] 6479 	mov	r4, dpl
      001FB7 AD 83            [24] 6480 	mov	r5, dph
      001FB9 AE F0            [24] 6481 	mov	r6, b
      001FBB FF               [12] 6482 	mov	r7, a
      001FBC E5 81            [12] 6483 	mov	a,sp
      001FBE 24 F6            [12] 6484 	add	a,#0xf6
      001FC0 F5 81            [12] 6485 	mov	sp,a
      001FC2 8C 82            [24] 6486 	mov	dpl, r4
      001FC4 8D 83            [24] 6487 	mov	dph, r5
      001FC6 8E F0            [24] 6488 	mov	b, r6
      001FC8 EF               [12] 6489 	mov	a, r7
                           001F12  6490 	C$controller_8051.c$84$1_0$104 ==.
                                   6491 ;	../../controller_8051.c:84: }
                           001F12  6492 	C$controller_8051.c$84$1_0$104 ==.
                           001F12  6493 	XFcontroller_8051$temperature_high$0$0 ==.
      001FC9 22               [24] 6494 	ret
                                   6495 ;------------------------------------------------------------
                                   6496 ;Allocation info for local variables in function 'fan_slow'
                                   6497 ;------------------------------------------------------------
                                   6498 ;value         Allocated to registers r4 r5 r6 r7 
                                   6499 ;------------------------------------------------------------
                           001F13  6500 	Fcontroller_8051$fan_slow$0$0 ==.
                           001F13  6501 	C$controller_8051.c$91$1_0$106 ==.
                                   6502 ;	../../controller_8051.c:91: static float fan_slow(
                                   6503 ;	-----------------------------------------
                                   6504 ;	 function fan_slow
                                   6505 ;	-----------------------------------------
      001FCA                       6506 _fan_slow:
      001FCA AC 82            [24] 6507 	mov	r4,dpl
      001FCC AD 83            [24] 6508 	mov	r5,dph
      001FCE AE F0            [24] 6509 	mov	r6,b
      001FD0 FF               [12] 6510 	mov	r7,a
                           001F1A  6511 	C$controller_8051.c$100$1_0$106 ==.
                                   6512 ;	../../controller_8051.c:100: hedges.none
      001FD1 90 26 F5         [24] 6513 	mov	dptr,#_hedges
      001FD4 E4               [12] 6514 	clr	a
      001FD5 93               [24] 6515 	movc	a,@a+dptr
      001FD6 FB               [12] 6516 	mov	r3,a
                           001F20  6517 	C$controller_8051.c$96$1_0$106 ==.
                                   6518 ;	../../controller_8051.c:96: 20.0f,
      001FD7 C0 03            [24] 6519 	push	ar3
      001FD9 E4               [12] 6520 	clr	a
      001FDA C0 E0            [24] 6521 	push	acc
      001FDC C0 04            [24] 6522 	push	ar4
      001FDE C0 05            [24] 6523 	push	ar5
      001FE0 C0 06            [24] 6524 	push	ar6
      001FE2 C0 07            [24] 6525 	push	ar7
      001FE4 C0 E0            [24] 6526 	push	acc
      001FE6 C0 E0            [24] 6527 	push	acc
      001FE8 74 48            [12] 6528 	mov	a,#0x48
      001FEA C0 E0            [24] 6529 	push	acc
      001FEC 74 42            [12] 6530 	mov	a,#0x42
      001FEE C0 E0            [24] 6531 	push	acc
      001FF0 90 00 00         [24] 6532 	mov	dptr,#0x0000
      001FF3 75 F0 A0         [24] 6533 	mov	b, #0xa0
      001FF6 14               [12] 6534 	dec	a
      001FF7 12 0A B9         [24] 6535 	lcall	_fuzzy_ramp
      001FFA AC 82            [24] 6536 	mov	r4, dpl
      001FFC AD 83            [24] 6537 	mov	r5, dph
      001FFE AE F0            [24] 6538 	mov	r6, b
      002000 FF               [12] 6539 	mov	r7, a
      002001 E5 81            [12] 6540 	mov	a,sp
      002003 24 F6            [12] 6541 	add	a,#0xf6
      002005 F5 81            [12] 6542 	mov	sp,a
      002007 8C 82            [24] 6543 	mov	dpl, r4
      002009 8D 83            [24] 6544 	mov	dph, r5
      00200B 8E F0            [24] 6545 	mov	b, r6
      00200D EF               [12] 6546 	mov	a, r7
                           001F57  6547 	C$controller_8051.c$102$1_0$106 ==.
                                   6548 ;	../../controller_8051.c:102: }
                           001F57  6549 	C$controller_8051.c$102$1_0$106 ==.
                           001F57  6550 	XFcontroller_8051$fan_slow$0$0 ==.
      00200E 22               [24] 6551 	ret
                                   6552 ;------------------------------------------------------------
                                   6553 ;Allocation info for local variables in function 'fan_fast'
                                   6554 ;------------------------------------------------------------
                                   6555 ;value         Allocated to registers r4 r5 r6 r7 
                                   6556 ;------------------------------------------------------------
                           001F58  6557 	Fcontroller_8051$fan_fast$0$0 ==.
                           001F58  6558 	C$controller_8051.c$105$1_0$108 ==.
                                   6559 ;	../../controller_8051.c:105: static float fan_fast(
                                   6560 ;	-----------------------------------------
                                   6561 ;	 function fan_fast
                                   6562 ;	-----------------------------------------
      00200F                       6563 _fan_fast:
      00200F AC 82            [24] 6564 	mov	r4,dpl
      002011 AD 83            [24] 6565 	mov	r5,dph
      002013 AE F0            [24] 6566 	mov	r6,b
      002015 FF               [12] 6567 	mov	r7,a
                           001F5F  6568 	C$controller_8051.c$114$1_0$108 ==.
                                   6569 ;	../../controller_8051.c:114: hedges.none
      002016 90 26 F5         [24] 6570 	mov	dptr,#_hedges
      002019 E4               [12] 6571 	clr	a
      00201A 93               [24] 6572 	movc	a,@a+dptr
      00201B FB               [12] 6573 	mov	r3,a
                           001F65  6574 	C$controller_8051.c$110$1_0$108 ==.
                                   6575 ;	../../controller_8051.c:110: 40.0f,
      00201C C0 03            [24] 6576 	push	ar3
      00201E 74 01            [12] 6577 	mov	a,#0x01
      002020 C0 E0            [24] 6578 	push	acc
      002022 C0 04            [24] 6579 	push	ar4
      002024 C0 05            [24] 6580 	push	ar5
      002026 C0 06            [24] 6581 	push	ar6
      002028 C0 07            [24] 6582 	push	ar7
      00202A E4               [12] 6583 	clr	a
      00202B C0 E0            [24] 6584 	push	acc
      00202D C0 E0            [24] 6585 	push	acc
      00202F 74 A0            [12] 6586 	mov	a,#0xa0
      002031 C0 E0            [24] 6587 	push	acc
      002033 74 42            [12] 6588 	mov	a,#0x42
      002035 C0 E0            [24] 6589 	push	acc
      002037 90 00 00         [24] 6590 	mov	dptr,#0x0000
      00203A 75 F0 20         [24] 6591 	mov	b, #0x20
      00203D 12 0A B9         [24] 6592 	lcall	_fuzzy_ramp
      002040 AC 82            [24] 6593 	mov	r4, dpl
      002042 AD 83            [24] 6594 	mov	r5, dph
      002044 AE F0            [24] 6595 	mov	r6, b
      002046 FF               [12] 6596 	mov	r7, a
      002047 E5 81            [12] 6597 	mov	a,sp
      002049 24 F6            [12] 6598 	add	a,#0xf6
      00204B F5 81            [12] 6599 	mov	sp,a
      00204D 8C 82            [24] 6600 	mov	dpl, r4
      00204F 8D 83            [24] 6601 	mov	dph, r5
      002051 8E F0            [24] 6602 	mov	b, r6
      002053 EF               [12] 6603 	mov	a, r7
                           001F9D  6604 	C$controller_8051.c$116$1_0$108 ==.
                                   6605 ;	../../controller_8051.c:116: }
                           001F9D  6606 	C$controller_8051.c$116$1_0$108 ==.
                           001F9D  6607 	XFcontroller_8051$fan_fast$0$0 ==.
      002054 22               [24] 6608 	ret
                                   6609 ;------------------------------------------------------------
                                   6610 ;Allocation info for local variables in function 'calculate_fan_speed'
                                   6611 ;------------------------------------------------------------
                                   6612 ;temperature   Allocated to stack - _bp +1 +4 
                                   6613 ;rules         Allocated to stack - _bp +9 +74 
                                   6614 ;result        Allocated to stack - _bp +83 +4 
                                   6615 ;sloc0         Allocated to stack - _bp +5 +4 
                                   6616 ;------------------------------------------------------------
                           001F9E  6617 	Fcontroller_8051$calculate_fan_speed$0$0 ==.
                           001F9E  6618 	C$controller_8051.c$123$1_0$110 ==.
                                   6619 ;	../../controller_8051.c:123: static float calculate_fan_speed(
                                   6620 ;	-----------------------------------------
                                   6621 ;	 function calculate_fan_speed
                                   6622 ;	-----------------------------------------
      002055                       6623 _calculate_fan_speed:
      002055 C0 0E            [24] 6624 	push	_bp
      002057 85 81 0E         [24] 6625 	mov	_bp,sp
      00205A C0 82            [24] 6626 	push	dpl
      00205C C0 83            [24] 6627 	push	dph
      00205E C0 F0            [24] 6628 	push	b
      002060 C0 E0            [24] 6629 	push	acc
      002062 E5 81            [12] 6630 	mov	a,sp
      002064 24 52            [12] 6631 	add	a,#0x52
      002066 F5 81            [12] 6632 	mov	sp,a
                           001FB1  6633 	C$controller_8051.c$132$1_0$110 ==.
                                   6634 ;	../../controller_8051.c:132: );
      002068 E5 0E            [12] 6635 	mov	a,_bp
      00206A 24 09            [12] 6636 	add	a,#0x09
      00206C FB               [12] 6637 	mov	r3,a
      00206D FA               [12] 6638 	mov	r2,a
      00206E 7E 00            [12] 6639 	mov	r6,#0x00
      002070 7F 40            [12] 6640 	mov	r7,#0x40
      002072 8A 82            [24] 6641 	mov	dpl, r2
      002074 8E 83            [24] 6642 	mov	dph, r6
      002076 8F F0            [24] 6643 	mov	b, r7
      002078 C0 03            [24] 6644 	push	ar3
      00207A 12 16 30         [24] 6645 	lcall	_fuzzy_rules_create
                           001FC6  6646 	C$controller_8051.c$134$1_0$110 ==.
                                   6647 ;	../../controller_8051.c:134: if (!FUZZY_RULE_ADD(
      00207D A8 0E            [24] 6648 	mov	r0,_bp
      00207F 08               [12] 6649 	inc	r0
      002080 86 82            [24] 6650 	mov	dpl, @r0
      002082 08               [12] 6651 	inc	r0
      002083 86 83            [24] 6652 	mov	dph, @r0
      002085 08               [12] 6653 	inc	r0
      002086 86 F0            [24] 6654 	mov	b, @r0
      002088 08               [12] 6655 	inc	r0
      002089 E6               [12] 6656 	mov	a, @r0
      00208A 12 1F 3E         [24] 6657 	lcall	_temperature_low
      00208D C8               [12] 6658 	xch	a,r0
      00208E E5 0E            [12] 6659 	mov	a,_bp
      002090 24 05            [12] 6660 	add	a,#0x05
      002092 C8               [12] 6661 	xch	a,r0
      002093 A6 82            [24] 6662 	mov	@r0, dpl
      002095 08               [12] 6663 	inc	r0
      002096 A6 83            [24] 6664 	mov	@r0, dph
      002098 08               [12] 6665 	inc	r0
      002099 A6 F0            [24] 6666 	mov	@r0, b
      00209B 08               [12] 6667 	inc	r0
      00209C F6               [12] 6668 	mov	@r0,a
      00209D D0 03            [24] 6669 	pop	ar3
      00209F 8B 02            [24] 6670 	mov	ar2,r3
      0020A1 7E 00            [12] 6671 	mov	r6,#0x00
      0020A3 7F 40            [12] 6672 	mov	r7,#0x40
      0020A5 C0 03            [24] 6673 	push	ar3
      0020A7 74 CA            [12] 6674 	mov	a,#_fan_slow
      0020A9 C0 E0            [24] 6675 	push	acc
      0020AB 74 1F            [12] 6676 	mov	a,#(_fan_slow >> 8)
      0020AD C0 E0            [24] 6677 	push	acc
      0020AF E5 0E            [12] 6678 	mov	a,_bp
      0020B1 24 05            [12] 6679 	add	a,#0x05
      0020B3 F8               [12] 6680 	mov	r0,a
      0020B4 E6               [12] 6681 	mov	a,@r0
      0020B5 C0 E0            [24] 6682 	push	acc
      0020B7 08               [12] 6683 	inc	r0
      0020B8 E6               [12] 6684 	mov	a,@r0
      0020B9 C0 E0            [24] 6685 	push	acc
      0020BB 08               [12] 6686 	inc	r0
      0020BC E6               [12] 6687 	mov	a,@r0
      0020BD C0 E0            [24] 6688 	push	acc
      0020BF 08               [12] 6689 	inc	r0
      0020C0 E6               [12] 6690 	mov	a,@r0
      0020C1 C0 E0            [24] 6691 	push	acc
      0020C3 74 F8            [12] 6692 	mov	a,#___str_0
      0020C5 C0 E0            [24] 6693 	push	acc
      0020C7 74 26            [12] 6694 	mov	a,#(___str_0 >> 8)
      0020C9 C0 E0            [24] 6695 	push	acc
      0020CB 74 80            [12] 6696 	mov	a,#0x80
      0020CD C0 E0            [24] 6697 	push	acc
      0020CF 8A 82            [24] 6698 	mov	dpl, r2
      0020D1 8E 83            [24] 6699 	mov	dph, r6
      0020D3 8F F0            [24] 6700 	mov	b, r7
      0020D5 12 16 52         [24] 6701 	lcall	_fuzzy_rules_add
      0020D8 AF 82            [24] 6702 	mov	r7, dpl
      0020DA E5 81            [12] 6703 	mov	a,sp
      0020DC 24 F7            [12] 6704 	add	a,#0xf7
      0020DE F5 81            [12] 6705 	mov	sp,a
      0020E0 D0 03            [24] 6706 	pop	ar3
      0020E2 EF               [12] 6707 	mov	a,r7
                           00202C  6708 	C$controller_8051.c$141$2_0$111 ==.
                                   6709 ;	../../controller_8051.c:141: );
      0020E3 70 17            [24] 6710 	jnz	00102$
      0020E5 8B 05            [24] 6711 	mov	ar5,r3
      0020E7 FE               [12] 6712 	mov	r6,a
      0020E8 7F 40            [12] 6713 	mov	r7,#0x40
      0020EA 8D 82            [24] 6714 	mov	dpl, r5
      0020EC 8E 83            [24] 6715 	mov	dph, r6
      0020EE 8F F0            [24] 6716 	mov	b, r7
      0020F0 12 1F 1C         [24] 6717 	lcall	_fuzzy_rules_free
                           00203C  6718 	C$controller_8051.c$143$2_0$111 ==.
                                   6719 ;	../../controller_8051.c:143: return 0.0f;
      0020F3 90 00 00         [24] 6720 	mov	dptr,#0x0000
      0020F6 E4               [12] 6721 	clr	a
      0020F7 F5 F0            [12] 6722 	mov	b,a
      0020F9 02 21 EA         [24] 6723 	ljmp	00105$
      0020FC                       6724 00102$:
                           002045  6725 	C$controller_8051.c$146$1_0$110 ==.
                                   6726 ;	../../controller_8051.c:146: if (!FUZZY_RULE_ADD(
      0020FC A8 0E            [24] 6727 	mov	r0,_bp
      0020FE 08               [12] 6728 	inc	r0
      0020FF 86 82            [24] 6729 	mov	dpl, @r0
      002101 08               [12] 6730 	inc	r0
      002102 86 83            [24] 6731 	mov	dph, @r0
      002104 08               [12] 6732 	inc	r0
      002105 86 F0            [24] 6733 	mov	b, @r0
      002107 08               [12] 6734 	inc	r0
      002108 E6               [12] 6735 	mov	a, @r0
      002109 C0 03            [24] 6736 	push	ar3
      00210B 12 1F 83         [24] 6737 	lcall	_temperature_high
      00210E C8               [12] 6738 	xch	a,r0
      00210F E5 0E            [12] 6739 	mov	a,_bp
      002111 24 05            [12] 6740 	add	a,#0x05
      002113 C8               [12] 6741 	xch	a,r0
      002114 A6 82            [24] 6742 	mov	@r0, dpl
      002116 08               [12] 6743 	inc	r0
      002117 A6 83            [24] 6744 	mov	@r0, dph
      002119 08               [12] 6745 	inc	r0
      00211A A6 F0            [24] 6746 	mov	@r0, b
      00211C 08               [12] 6747 	inc	r0
      00211D F6               [12] 6748 	mov	@r0,a
      00211E D0 03            [24] 6749 	pop	ar3
      002120 8B 02            [24] 6750 	mov	ar2,r3
      002122 7E 00            [12] 6751 	mov	r6,#0x00
      002124 7F 40            [12] 6752 	mov	r7,#0x40
      002126 C0 03            [24] 6753 	push	ar3
      002128 74 0F            [12] 6754 	mov	a,#_fan_fast
      00212A C0 E0            [24] 6755 	push	acc
      00212C 74 20            [12] 6756 	mov	a,#(_fan_fast >> 8)
      00212E C0 E0            [24] 6757 	push	acc
      002130 E5 0E            [12] 6758 	mov	a,_bp
      002132 24 05            [12] 6759 	add	a,#0x05
      002134 F8               [12] 6760 	mov	r0,a
      002135 E6               [12] 6761 	mov	a,@r0
      002136 C0 E0            [24] 6762 	push	acc
      002138 08               [12] 6763 	inc	r0
      002139 E6               [12] 6764 	mov	a,@r0
      00213A C0 E0            [24] 6765 	push	acc
      00213C 08               [12] 6766 	inc	r0
      00213D E6               [12] 6767 	mov	a,@r0
      00213E C0 E0            [24] 6768 	push	acc
      002140 08               [12] 6769 	inc	r0
      002141 E6               [12] 6770 	mov	a,@r0
      002142 C0 E0            [24] 6771 	push	acc
      002144 74 01            [12] 6772 	mov	a,#___str_1
      002146 C0 E0            [24] 6773 	push	acc
      002148 74 27            [12] 6774 	mov	a,#(___str_1 >> 8)
      00214A C0 E0            [24] 6775 	push	acc
      00214C 74 80            [12] 6776 	mov	a,#0x80
      00214E C0 E0            [24] 6777 	push	acc
      002150 8A 82            [24] 6778 	mov	dpl, r2
      002152 8E 83            [24] 6779 	mov	dph, r6
      002154 8F F0            [24] 6780 	mov	b, r7
      002156 12 16 52         [24] 6781 	lcall	_fuzzy_rules_add
      002159 AF 82            [24] 6782 	mov	r7, dpl
      00215B E5 81            [12] 6783 	mov	a,sp
      00215D 24 F7            [12] 6784 	add	a,#0xf7
      00215F F5 81            [12] 6785 	mov	sp,a
      002161 D0 03            [24] 6786 	pop	ar3
      002163 EF               [12] 6787 	mov	a,r7
                           0020AD  6788 	C$controller_8051.c$153$2_0$112 ==.
                                   6789 ;	../../controller_8051.c:153: );
      002164 70 16            [24] 6790 	jnz	00104$
      002166 8B 05            [24] 6791 	mov	ar5,r3
      002168 FE               [12] 6792 	mov	r6,a
      002169 7F 40            [12] 6793 	mov	r7,#0x40
      00216B 8D 82            [24] 6794 	mov	dpl, r5
      00216D 8E 83            [24] 6795 	mov	dph, r6
      00216F 8F F0            [24] 6796 	mov	b, r7
      002171 12 1F 1C         [24] 6797 	lcall	_fuzzy_rules_free
                           0020BD  6798 	C$controller_8051.c$155$2_0$112 ==.
                                   6799 ;	../../controller_8051.c:155: return 0.0f;
      002174 90 00 00         [24] 6800 	mov	dptr,#0x0000
      002177 E4               [12] 6801 	clr	a
      002178 F5 F0            [12] 6802 	mov	b,a
      00217A 80 6E            [24] 6803 	sjmp	00105$
      00217C                       6804 00104$:
                           0020C5  6805 	C$controller_8051.c$160$1_0$110 ==.
                                   6806 ;	../../controller_8051.c:160: &rules,
      00217C 8B 05            [24] 6807 	mov	ar5,r3
      00217E 7E 00            [12] 6808 	mov	r6,#0x00
      002180 7F 40            [12] 6809 	mov	r7,#0x40
      002182 C0 03            [24] 6810 	push	ar3
      002184 74 01            [12] 6811 	mov	a,#0x01
      002186 C0 E0            [24] 6812 	push	acc
      002188 E4               [12] 6813 	clr	a
      002189 C0 E0            [24] 6814 	push	acc
      00218B C0 E0            [24] 6815 	push	acc
      00218D 74 20            [12] 6816 	mov	a,#0x20
      00218F C0 E0            [24] 6817 	push	acc
      002191 74 41            [12] 6818 	mov	a,#0x41
      002193 C0 E0            [24] 6819 	push	acc
      002195 E4               [12] 6820 	clr	a
      002196 C0 E0            [24] 6821 	push	acc
      002198 C0 E0            [24] 6822 	push	acc
      00219A 74 C8            [12] 6823 	mov	a,#0xc8
      00219C C0 E0            [24] 6824 	push	acc
      00219E 74 42            [12] 6825 	mov	a,#0x42
      0021A0 C0 E0            [24] 6826 	push	acc
      0021A2 E4               [12] 6827 	clr	a
      0021A3 C0 E0            [24] 6828 	push	acc
      0021A5 C0 E0            [24] 6829 	push	acc
      0021A7 C0 E0            [24] 6830 	push	acc
      0021A9 C0 E0            [24] 6831 	push	acc
      0021AB 8D 82            [24] 6832 	mov	dpl, r5
      0021AD 8E 83            [24] 6833 	mov	dph, r6
      0021AF 8F F0            [24] 6834 	mov	b, r7
      0021B1 12 17 B6         [24] 6835 	lcall	_fuzzy_rules_defuzzify
      0021B4 C8               [12] 6836 	xch	a,r0
      0021B5 E5 0E            [12] 6837 	mov	a,_bp
      0021B7 24 53            [12] 6838 	add	a,#0x53
      0021B9 C8               [12] 6839 	xch	a,r0
      0021BA A6 82            [24] 6840 	mov	@r0, dpl
      0021BC 08               [12] 6841 	inc	r0
      0021BD A6 83            [24] 6842 	mov	@r0, dph
      0021BF 08               [12] 6843 	inc	r0
      0021C0 A6 F0            [24] 6844 	mov	@r0, b
      0021C2 08               [12] 6845 	inc	r0
      0021C3 F6               [12] 6846 	mov	@r0,a
      0021C4 E5 81            [12] 6847 	mov	a,sp
      0021C6 24 F3            [12] 6848 	add	a,#0xf3
      0021C8 F5 81            [12] 6849 	mov	sp,a
      0021CA D0 03            [24] 6850 	pop	ar3
                           002115  6851 	C$controller_8051.c$169$1_0$110 ==.
                                   6852 ;	../../controller_8051.c:169: );
      0021CC 8B 02            [24] 6853 	mov	ar2,r3
      0021CE 7B 00            [12] 6854 	mov	r3,#0x00
      0021D0 7F 40            [12] 6855 	mov	r7,#0x40
      0021D2 8A 82            [24] 6856 	mov	dpl, r2
      0021D4 8B 83            [24] 6857 	mov	dph, r3
      0021D6 8F F0            [24] 6858 	mov	b, r7
      0021D8 12 1F 1C         [24] 6859 	lcall	_fuzzy_rules_free
                           002124  6860 	C$controller_8051.c$171$1_0$110 ==.
                                   6861 ;	../../controller_8051.c:171: return result;
      0021DB E5 0E            [12] 6862 	mov	a,_bp
      0021DD 24 53            [12] 6863 	add	a,#0x53
      0021DF F8               [12] 6864 	mov	r0,a
      0021E0 86 82            [24] 6865 	mov	dpl, @r0
      0021E2 08               [12] 6866 	inc	r0
      0021E3 86 83            [24] 6867 	mov	dph, @r0
      0021E5 08               [12] 6868 	inc	r0
      0021E6 86 F0            [24] 6869 	mov	b, @r0
      0021E8 08               [12] 6870 	inc	r0
      0021E9 E6               [12] 6871 	mov	a, @r0
      0021EA                       6872 00105$:
                           002133  6873 	C$controller_8051.c$172$1_0$110 ==.
                                   6874 ;	../../controller_8051.c:172: }
      0021EA 85 0E 81         [24] 6875 	mov	sp,_bp
      0021ED D0 0E            [24] 6876 	pop	_bp
                           002138  6877 	C$controller_8051.c$172$1_0$110 ==.
                           002138  6878 	XFcontroller_8051$calculate_fan_speed$0$0 ==.
      0021EF 22               [24] 6879 	ret
                                   6880 ;------------------------------------------------------------
                                   6881 ;Allocation info for local variables in function 'fan_speed_to_pwm'
                                   6882 ;------------------------------------------------------------
                                   6883 ;fan_speed     Allocated to registers r4 r5 r6 r7 
                                   6884 ;------------------------------------------------------------
                           002139  6885 	Fcontroller_8051$fan_speed_to_pwm$0$0 ==.
                           002139  6886 	C$controller_8051.c$179$1_0$114 ==.
                                   6887 ;	../../controller_8051.c:179: static unsigned char fan_speed_to_pwm(
                                   6888 ;	-----------------------------------------
                                   6889 ;	 function fan_speed_to_pwm
                                   6890 ;	-----------------------------------------
      0021F0                       6891 _fan_speed_to_pwm:
      0021F0 AC 82            [24] 6892 	mov	r4,dpl
      0021F2 AD 83            [24] 6893 	mov	r5,dph
      0021F4 AE F0            [24] 6894 	mov	r6,b
      0021F6 FF               [12] 6895 	mov	r7,a
                           002140  6896 	C$controller_8051.c$183$1_0$114 ==.
                                   6897 ;	../../controller_8051.c:183: if (fan_speed <= 0.0f) {
      0021F7 C0 07            [24] 6898 	push	ar7
      0021F9 C0 06            [24] 6899 	push	ar6
      0021FB C0 05            [24] 6900 	push	ar5
      0021FD C0 04            [24] 6901 	push	ar4
      0021FF C0 04            [24] 6902 	push	ar4
      002201 C0 05            [24] 6903 	push	ar5
      002203 C0 06            [24] 6904 	push	ar6
      002205 C0 07            [24] 6905 	push	ar7
      002207 90 00 00         [24] 6906 	mov	dptr,#0x0000
      00220A E4               [12] 6907 	clr	a
      00220B F5 F0            [12] 6908 	mov	b,a
      00220D 12 24 07         [24] 6909 	lcall	___fslt
      002210 E5 81            [12] 6910 	mov	a,sp
      002212 24 FC            [12] 6911 	add	a,#0xfc
      002214 F5 81            [12] 6912 	mov	sp,a
      002216 D0 04            [24] 6913 	pop	ar4
      002218 D0 05            [24] 6914 	pop	ar5
      00221A D0 06            [24] 6915 	pop	ar6
      00221C D0 07            [24] 6916 	pop	ar7
      00221E E5 82            [12] 6917 	mov	a, dpl
      002220 24 FF            [12] 6918 	add	a,#0xff
      002222 92 00            [24] 6919 	mov	b0,c
      002224 40 05            [24] 6920 	jc	00102$
                           00216F  6921 	C$controller_8051.c$184$2_0$115 ==.
                                   6922 ;	../../controller_8051.c:184: return 0u;
      002226 75 82 00         [24] 6923 	mov	dpl, #0x00
      002229 80 66            [24] 6924 	sjmp	00105$
      00222B                       6925 00102$:
                           002174  6926 	C$controller_8051.c$187$1_0$114 ==.
                                   6927 ;	../../controller_8051.c:187: if (fan_speed >= 100.0f) {
      00222B C0 07            [24] 6928 	push	ar7
      00222D C0 06            [24] 6929 	push	ar6
      00222F C0 05            [24] 6930 	push	ar5
      002231 C0 04            [24] 6931 	push	ar4
      002233 E4               [12] 6932 	clr	a
      002234 C0 E0            [24] 6933 	push	acc
      002236 C0 E0            [24] 6934 	push	acc
      002238 74 C8            [12] 6935 	mov	a,#0xc8
      00223A C0 E0            [24] 6936 	push	acc
      00223C 74 42            [12] 6937 	mov	a,#0x42
      00223E C0 E0            [24] 6938 	push	acc
      002240 8C 82            [24] 6939 	mov	dpl, r4
      002242 8D 83            [24] 6940 	mov	dph, r5
      002244 8E F0            [24] 6941 	mov	b, r6
      002246 EF               [12] 6942 	mov	a, r7
      002247 12 24 07         [24] 6943 	lcall	___fslt
      00224A E5 81            [12] 6944 	mov	a,sp
      00224C 24 FC            [12] 6945 	add	a,#0xfc
      00224E F5 81            [12] 6946 	mov	sp,a
      002250 D0 04            [24] 6947 	pop	ar4
      002252 D0 05            [24] 6948 	pop	ar5
      002254 D0 06            [24] 6949 	pop	ar6
      002256 D0 07            [24] 6950 	pop	ar7
      002258 E5 82            [12] 6951 	mov	a, dpl
      00225A 24 FF            [12] 6952 	add	a,#0xff
      00225C 92 00            [24] 6953 	mov	b0,c
      00225E 40 05            [24] 6954 	jc	00104$
                           0021A9  6955 	C$controller_8051.c$188$2_0$116 ==.
                                   6956 ;	../../controller_8051.c:188: return 100u;
      002260 75 82 64         [24] 6957 	mov	dpl, #0x64
      002263 80 2C            [24] 6958 	sjmp	00105$
      002265                       6959 00104$:
                           0021AE  6960 	C$controller_8051.c$193$1_0$114 ==.
                                   6961 ;	../../controller_8051.c:193: );
      002265 E4               [12] 6962 	clr	a
      002266 C0 E0            [24] 6963 	push	acc
      002268 C0 E0            [24] 6964 	push	acc
      00226A C0 E0            [24] 6965 	push	acc
      00226C 74 3F            [12] 6966 	mov	a,#0x3f
      00226E C0 E0            [24] 6967 	push	acc
      002270 8C 82            [24] 6968 	mov	dpl, r4
      002272 8D 83            [24] 6969 	mov	dph, r5
      002274 8E F0            [24] 6970 	mov	b, r6
      002276 EF               [12] 6971 	mov	a, r7
      002277 12 24 59         [24] 6972 	lcall	___fsadd
      00227A AC 82            [24] 6973 	mov	r4, dpl
      00227C AD 83            [24] 6974 	mov	r5, dph
      00227E AE F0            [24] 6975 	mov	r6, b
      002280 FF               [12] 6976 	mov	r7, a
      002281 E5 81            [12] 6977 	mov	a,sp
      002283 24 FC            [12] 6978 	add	a,#0xfc
      002285 F5 81            [12] 6979 	mov	sp,a
      002287 8C 82            [24] 6980 	mov	dpl, r4
      002289 8D 83            [24] 6981 	mov	dph, r5
      00228B 8E F0            [24] 6982 	mov	b, r6
      00228D EF               [12] 6983 	mov	a, r7
      00228E 12 26 4F         [24] 6984 	lcall	___fs2uchar
      002291                       6985 00105$:
                           0021DA  6986 	C$controller_8051.c$194$1_0$114 ==.
                                   6987 ;	../../controller_8051.c:194: }
                           0021DA  6988 	C$controller_8051.c$194$1_0$114 ==.
                           0021DA  6989 	XFcontroller_8051$fan_speed_to_pwm$0$0 ==.
      002291 22               [24] 6990 	ret
                                   6991 ;------------------------------------------------------------
                                   6992 ;Allocation info for local variables in function 'main'
                                   6993 ;------------------------------------------------------------
                           0021DB  6994 	G$main$0$0 ==.
                           0021DB  6995 	C$controller_8051.c$211$1_0$118 ==.
                                   6996 ;	../../controller_8051.c:211: void main(void)
                                   6997 ;	-----------------------------------------
                                   6998 ;	 function main
                                   6999 ;	-----------------------------------------
      002292                       7000 _main:
                           0021DB  7001 	C$controller_8051.c$219$1_0$118 ==.
                                   7002 ;	../../controller_8051.c:219: 42u;
      002292 75 08 2A         [24] 7003 	mov	_test_temperature,#0x2a
                           0021DE  7004 	C$controller_8051.c$225$1_0$118 ==.
                                   7005 ;	../../controller_8051.c:225: 0x55u;
      002295 75 80 55         [24] 7006 	mov	_P0,#0x55
                           0021E1  7007 	C$controller_8051.c$228$1_0$118 ==.
                                   7008 ;	../../controller_8051.c:228: 0x00u;
      002298 75 90 00         [24] 7009 	mov	_P1,#0x00
                           0021E4  7010 	C$controller_8051.c$234$1_0$118 ==.
                                   7011 ;	../../controller_8051.c:234: test_temperature = P2;
      00229B 85 A0 08         [24] 7012 	mov	_test_temperature,_P2
                           0021E7  7013 	C$controller_8051.c$239$2_0$118 ==.
                                   7014 ;	../../controller_8051.c:239: );
      00229E 85 08 82         [24] 7015 	mov	dpl, _test_temperature
      0022A1 12 26 57         [24] 7016 	lcall	___uchar2fs
      0022A4 12 20 55         [24] 7017 	lcall	_calculate_fan_speed
      0022A7 85 82 0A         [24] 7018 	mov	_test_fan_speed,dpl
      0022AA 85 83 0B         [24] 7019 	mov	(_test_fan_speed + 1),dph
      0022AD 85 F0 0C         [24] 7020 	mov	(_test_fan_speed + 2),b
      0022B0 F5 0D            [12] 7021 	mov	(_test_fan_speed + 3),a
                           0021FB  7022 	C$controller_8051.c$243$1_0$118 ==.
                                   7023 ;	../../controller_8051.c:243: test_fan_speed
      0022B2 85 0A 82         [24] 7024 	mov	dpl, _test_fan_speed
      0022B5 85 0B 83         [24] 7025 	mov	dph, (_test_fan_speed + 1)
      0022B8 85 0C F0         [24] 7026 	mov	b, (_test_fan_speed + 2)
      0022BB E5 0D            [12] 7027 	mov	a, (_test_fan_speed + 3)
      0022BD 12 21 F0         [24] 7028 	lcall	_fan_speed_to_pwm
      0022C0 85 82 09         [24] 7029 	mov	_test_pwm,dpl
                           00220C  7030 	C$controller_8051.c$250$1_0$118 ==.
                                   7031 ;	../../controller_8051.c:250: test_pwm;
      0022C3 85 09 90         [24] 7032 	mov	_P1,_test_pwm
                           00220F  7033 	C$controller_8051.c$256$1_0$118 ==.
                                   7034 ;	../../controller_8051.c:256: 0xAAu;
      0022C6 75 80 AA         [24] 7035 	mov	_P0,#0xaa
      0022C9                       7036 00103$:
      0022C9 80 FE            [24] 7037 	sjmp	00103$
                           002214  7038 	C$controller_8051.c$261$2_0$118 ==.
                                   7039 ;	../../controller_8051.c:261: }
                           002214  7040 	C$controller_8051.c$261$2_0$118 ==.
                           002214  7041 	XG$main$0$0 ==.
      0022CB 22               [24] 7042 	ret
                                   7043 	.area CSEG    (CODE)
                                   7044 	.area CONST   (CODE)
                                   7045 	.area CONST   (CODE)
                           000000  7046 Fcontroller_8051$hedges$0_0$0 == .
      0026F5                       7047 _hedges:
      0026F5 01                    7048 	.db #0x01	; 1
      0026F6 02                    7049 	.db #0x02	; 2
      0026F7 03                    7050 	.db #0x03	; 3
                                   7051 	.area CSEG    (CODE)
                           002215  7052 Fcontroller_8051$__str_0$0_0$0 == .
                                   7053 	.area CONST   (CODE)
      0026F8                       7054 ___str_0:
      0026F8 66 61 6E 5F 73 6C 6F  7055 	.ascii "fan_slow"
             77
      002700 00                    7056 	.db 0x00
                                   7057 	.area CSEG    (CODE)
                           002215  7058 Fcontroller_8051$__str_1$0_0$0 == .
                                   7059 	.area CONST   (CODE)
      002701                       7060 ___str_1:
      002701 66 61 6E 5F 66 61 73  7061 	.ascii "fan_fast"
             74
      002709 00                    7062 	.db 0x00
                                   7063 	.area CSEG    (CODE)
                                   7064 	.area XINIT   (CODE)
                                   7065 	.area CABS    (ABS,CODE)
