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
                           000000   417 Fcontroller_8051$fuzzy_values_buffer$0_0$0==.
      000021                        418 _fuzzy_values_buffer:
      000021                        419 	.ds 64
                           000040   420 G$test_temperature$0_0$0==.
      000061                        421 _test_temperature::
      000061                        422 	.ds 1
                           000041   423 G$test_pwm$0_0$0==.
      000062                        424 _test_pwm::
      000062                        425 	.ds 1
                           000042   426 G$test_fan_speed$0_0$0==.
      000063                        427 _test_fan_speed::
      000063                        428 	.ds 4
                                    429 ;--------------------------------------------------------
                                    430 ; overlayable items in internal ram
                                    431 ;--------------------------------------------------------
                                    432 ;--------------------------------------------------------
                                    433 ; Stack segment in internal ram
                                    434 ;--------------------------------------------------------
                                    435 	.area SSEG
      000067                        436 __start__stack:
      000067                        437 	.ds	1
                                    438 
                                    439 ;--------------------------------------------------------
                                    440 ; indirectly addressable internal ram data
                                    441 ;--------------------------------------------------------
                                    442 	.area ISEG    (DATA)
                                    443 ;--------------------------------------------------------
                                    444 ; absolute internal ram data
                                    445 ;--------------------------------------------------------
                                    446 	.area IABS    (ABS,DATA)
                                    447 	.area IABS    (ABS,DATA)
                                    448 ;--------------------------------------------------------
                                    449 ; bit data
                                    450 ;--------------------------------------------------------
                                    451 	.area BSEG    (BIT)
                                    452 ;--------------------------------------------------------
                                    453 ; paged external ram data
                                    454 ;--------------------------------------------------------
                                    455 	.area PSEG    (PAG,XDATA)
                                    456 ;--------------------------------------------------------
                                    457 ; uninitialized external ram data
                                    458 ;--------------------------------------------------------
                                    459 	.area XSEG    (XDATA)
                                    460 ;--------------------------------------------------------
                                    461 ; absolute external ram data
                                    462 ;--------------------------------------------------------
                                    463 	.area XABS    (ABS,XDATA)
                                    464 ;--------------------------------------------------------
                                    465 ; initialized external ram data
                                    466 ;--------------------------------------------------------
                                    467 	.area XISEG   (XDATA)
                                    468 	.area HOME    (CODE)
                                    469 	.area GSINIT0 (CODE)
                                    470 	.area GSINIT1 (CODE)
                                    471 	.area GSINIT2 (CODE)
                                    472 	.area GSINIT3 (CODE)
                                    473 	.area GSINIT4 (CODE)
                                    474 	.area GSINIT5 (CODE)
                                    475 	.area GSINIT  (CODE)
                                    476 	.area GSFINAL (CODE)
                                    477 	.area CSEG    (CODE)
                                    478 ;--------------------------------------------------------
                                    479 ; interrupt vector
                                    480 ;--------------------------------------------------------
                                    481 	.area HOME    (CODE)
      000000                        482 __interrupt_vect:
      000000 02 00 4C         [24]  483 	ljmp	__sdcc_gsinit_startup
                                    484 ; restartable atomic support routines
      000003                        485 	.ds	5
      000008                        486 sdcc_atomic_exchange_rollback_start::
      000008 00               [12]  487 	nop
      000009 00               [12]  488 	nop
      00000A                        489 sdcc_atomic_exchange_pdata_impl:
      00000A E2               [24]  490 	movx	a, @r0
      00000B FB               [12]  491 	mov	r3, a
      00000C EA               [12]  492 	mov	a, r2
      00000D F2               [24]  493 	movx	@r0, a
      00000E 80 2C            [24]  494 	sjmp	sdcc_atomic_exchange_exit
      000010 00               [12]  495 	nop
      000011 00               [12]  496 	nop
      000012                        497 sdcc_atomic_exchange_xdata_impl:
      000012 E0               [24]  498 	movx	a, @dptr
      000013 FB               [12]  499 	mov	r3, a
      000014 EA               [12]  500 	mov	a, r2
      000015 F0               [24]  501 	movx	@dptr, a
      000016 80 24            [24]  502 	sjmp	sdcc_atomic_exchange_exit
      000018                        503 sdcc_atomic_compare_exchange_idata_impl:
      000018 E6               [12]  504 	mov	a, @r0
      000019 B5 02 02         [24]  505 	cjne	a, ar2, .+#5
      00001C EB               [12]  506 	mov	a, r3
      00001D F6               [12]  507 	mov	@r0, a
      00001E 22               [24]  508 	ret
      00001F 00               [12]  509 	nop
      000020                        510 sdcc_atomic_compare_exchange_pdata_impl:
      000020 E2               [24]  511 	movx	a, @r0
      000021 B5 02 02         [24]  512 	cjne	a, ar2, .+#5
      000024 EB               [12]  513 	mov	a, r3
      000025 F2               [24]  514 	movx	@r0, a
      000026 22               [24]  515 	ret
      000027 00               [12]  516 	nop
      000028                        517 sdcc_atomic_compare_exchange_xdata_impl:
      000028 E0               [24]  518 	movx	a, @dptr
      000029 B5 02 02         [24]  519 	cjne	a, ar2, .+#5
      00002C EB               [12]  520 	mov	a, r3
      00002D F0               [24]  521 	movx	@dptr, a
      00002E 22               [24]  522 	ret
      00002F                        523 sdcc_atomic_exchange_rollback_end::
                                    524 
      00002F                        525 sdcc_atomic_exchange_gptr_impl::
      00002F 30 F6 E0         [24]  526 	jnb	b.6, sdcc_atomic_exchange_xdata_impl
      000032 A8 82            [24]  527 	mov	r0, dpl
      000034 20 F5 D3         [24]  528 	jb	b.5, sdcc_atomic_exchange_pdata_impl
      000037                        529 sdcc_atomic_exchange_idata_impl:
      000037 EA               [12]  530 	mov	a, r2
      000038 C6               [12]  531 	xch	a, @r0
      000039 F5 82            [12]  532 	mov	dpl, a
      00003B 22               [24]  533 	ret
      00003C                        534 sdcc_atomic_exchange_exit:
      00003C 8B 82            [24]  535 	mov	dpl, r3
      00003E 22               [24]  536 	ret
      00003F                        537 sdcc_atomic_compare_exchange_gptr_impl::
      00003F 30 F6 E6         [24]  538 	jnb	b.6, sdcc_atomic_compare_exchange_xdata_impl
      000042 A8 82            [24]  539 	mov	r0, dpl
      000044 20 F5 D9         [24]  540 	jb	b.5, sdcc_atomic_compare_exchange_pdata_impl
      000047 80 CF            [24]  541 	sjmp	sdcc_atomic_compare_exchange_idata_impl
                                    542 ;--------------------------------------------------------
                                    543 ; global & static initialisations
                                    544 ;--------------------------------------------------------
                                    545 	.area HOME    (CODE)
                                    546 	.area GSINIT  (CODE)
                                    547 	.area GSFINAL (CODE)
                                    548 	.area GSINIT  (CODE)
                                    549 	.globl __sdcc_gsinit_startup
                                    550 	.globl __sdcc_program_startup
                                    551 	.globl __start__stack
                                    552 	.globl __mcs51_genXINIT
                                    553 	.globl __mcs51_genXRAMCLEAR
                                    554 	.globl __mcs51_genRAMCLEAR
                           000000   555 	C$controller_8051.c$25$2_0$122 ==.
                                    556 ;	../../controller_8051.c:25: volatile unsigned char test_temperature = 0u;
      0000A5 75 61 00         [24]  557 	mov	_test_temperature,#0x00
                           000003   558 	C$controller_8051.c$26$2_0$122 ==.
                                    559 ;	../../controller_8051.c:26: volatile unsigned char test_pwm = 0u;
      0000A8 75 62 00         [24]  560 	mov	_test_pwm,#0x00
                           000006   561 	C$controller_8051.c$27$2_0$122 ==.
                                    562 ;	../../controller_8051.c:27: volatile float test_fan_speed = 0.0f;
      0000AB E4               [12]  563 	clr	a
      0000AC F5 63            [12]  564 	mov	_test_fan_speed,a
      0000AE F5 64            [12]  565 	mov	(_test_fan_speed + 1),a
      0000B0 F5 65            [12]  566 	mov	(_test_fan_speed + 2),a
      0000B2 F5 66            [12]  567 	mov	(_test_fan_speed + 3),a
                                    568 	.area GSFINAL (CODE)
      0000B4 02 00 49         [24]  569 	ljmp	__sdcc_program_startup
                                    570 ;--------------------------------------------------------
                                    571 ; Home
                                    572 ;--------------------------------------------------------
                                    573 	.area HOME    (CODE)
                                    574 	.area HOME    (CODE)
      000049                        575 __sdcc_program_startup:
      000049 02 22 C5         [24]  576 	ljmp	_main
                                    577 ;	return from main will return to caller
                                    578 ;--------------------------------------------------------
                                    579 ; code
                                    580 ;--------------------------------------------------------
                                    581 	.area CSEG    (CODE)
                                    582 ;------------------------------------------------------------
                                    583 ;Allocation info for local variables in function 'fuzzy_values_initialize'
                                    584 ;------------------------------------------------------------
                                    585 ;index         Allocated to registers r6 r7 
                                    586 ;------------------------------------------------------------
                           000000   587 	Fcontroller_8051$fuzzy_values_initialize$0$0 ==.
                           000000   588 	C$fuzzy.h$102$0_0$3 ==.
                                    589 ;	../../fuzzy.h:102: static float *fuzzy_values_initialize(void)
                                    590 ;	-----------------------------------------
                                    591 ;	 function fuzzy_values_initialize
                                    592 ;	-----------------------------------------
      0000B7                        593 _fuzzy_values_initialize:
                           000007   594 	ar7 = 0x07
                           000006   595 	ar6 = 0x06
                           000005   596 	ar5 = 0x05
                           000004   597 	ar4 = 0x04
                           000003   598 	ar3 = 0x03
                           000002   599 	ar2 = 0x02
                           000001   600 	ar1 = 0x01
                           000000   601 	ar0 = 0x00
                           000000   602 	C$fuzzy.h$107$3_0$5 ==.
                                    603 ;	../../fuzzy.h:107: index = 0u;
      0000B7 7E 00            [12]  604 	mov	r6,#0x00
      0000B9 7F 00            [12]  605 	mov	r7,#0x00
      0000BB                        606 00102$:
                           000004   607 	C$fuzzy.h$111$3_0$5 ==.
                                    608 ;	../../fuzzy.h:111: fuzzy_values_buffer[index] =
      0000BB EE               [12]  609 	mov	a,r6
      0000BC 2E               [12]  610 	add	a,r6
      0000BD FC               [12]  611 	mov	r4,a
      0000BE EF               [12]  612 	mov	a,r7
      0000BF 33               [12]  613 	rlc	a
      0000C0 FD               [12]  614 	mov	r5,a
      0000C1 EC               [12]  615 	mov	a,r4
      0000C2 2C               [12]  616 	add	a,r4
      0000C3 FC               [12]  617 	mov	r4,a
      0000C4 ED               [12]  618 	mov	a,r5
      0000C5 33               [12]  619 	rlc	a
      0000C6 EC               [12]  620 	mov	a,r4
      0000C7 24 21            [12]  621 	add	a, #_fuzzy_values_buffer
      0000C9 F8               [12]  622 	mov	r0,a
      0000CA 76 00            [12]  623 	mov	@r0,#0x00
      0000CC 08               [12]  624 	inc	r0
      0000CD 76 00            [12]  625 	mov	@r0,#0x00
      0000CF 08               [12]  626 	inc	r0
      0000D0 76 00            [12]  627 	mov	@r0,#0x00
      0000D2 08               [12]  628 	inc	r0
      0000D3 76 00            [12]  629 	mov	@r0,#0x00
                           00001E   630 	C$fuzzy.h$109$2_0$4 ==.
                                    631 ;	../../fuzzy.h:109: index++
      0000D5 0E               [12]  632 	inc	r6
      0000D6 BE 00 01         [24]  633 	cjne	r6,#0x00,00119$
      0000D9 0F               [12]  634 	inc	r7
      0000DA                        635 00119$:
                           000023   636 	C$fuzzy.h$108$2_0$4 ==.
                                    637 ;	../../fuzzy.h:108: index < FUZZY_MAX_VALUES;
      0000DA C3               [12]  638 	clr	c
      0000DB EE               [12]  639 	mov	a,r6
      0000DC 94 10            [12]  640 	subb	a,#0x10
      0000DE EF               [12]  641 	mov	a,r7
      0000DF 94 00            [12]  642 	subb	a,#0x00
      0000E1 40 D8            [24]  643 	jc	00102$
                           00002C   644 	C$fuzzy.h$115$1_0$3 ==.
                                    645 ;	../../fuzzy.h:115: return fuzzy_values_buffer;
      0000E3 90 00 21         [24]  646 	mov	dptr,#_fuzzy_values_buffer
      0000E6 75 F0 40         [24]  647 	mov	b, #0x40
                           000032   648 	C$fuzzy.h$116$1_0$3 ==.
                                    649 ;	../../fuzzy.h:116: }
                           000032   650 	C$fuzzy.h$116$1_0$3 ==.
                           000032   651 	XFcontroller_8051$fuzzy_values_initialize$0$0 ==.
      0000E9 22               [24]  652 	ret
                                    653 ;------------------------------------------------------------
                                    654 ;Allocation info for local variables in function 'fuzzy_clamp'
                                    655 ;------------------------------------------------------------
                                    656 ;value         Allocated to registers r4 r5 r6 r7 
                                    657 ;------------------------------------------------------------
                           000033   658 	Fcontroller_8051$fuzzy_clamp$0$0 ==.
                           000033   659 	C$fuzzy.h$674$1_0$20 ==.
                                    660 ;	../../fuzzy.h:674: static float fuzzy_clamp(float value)
                                    661 ;	-----------------------------------------
                                    662 ;	 function fuzzy_clamp
                                    663 ;	-----------------------------------------
      0000EA                        664 _fuzzy_clamp:
      0000EA AC 82            [24]  665 	mov	r4,dpl
      0000EC AD 83            [24]  666 	mov	r5,dph
      0000EE AE F0            [24]  667 	mov	r6,b
      0000F0 FF               [12]  668 	mov	r7,a
                           00003A   669 	C$fuzzy.h$676$1_0$20 ==.
                                    670 ;	../../fuzzy.h:676: if (value < LEVEL_LO) {
      0000F1 C0 07            [24]  671 	push	ar7
      0000F3 C0 06            [24]  672 	push	ar6
      0000F5 C0 05            [24]  673 	push	ar5
      0000F7 C0 04            [24]  674 	push	ar4
      0000F9 E4               [12]  675 	clr	a
      0000FA C0 E0            [24]  676 	push	acc
      0000FC C0 E0            [24]  677 	push	acc
      0000FE C0 E0            [24]  678 	push	acc
      000100 C0 E0            [24]  679 	push	acc
      000102 8C 82            [24]  680 	mov	dpl, r4
      000104 8D 83            [24]  681 	mov	dph, r5
      000106 8E F0            [24]  682 	mov	b, r6
      000108 EF               [12]  683 	mov	a, r7
      000109 12 24 3A         [24]  684 	lcall	___fslt
      00010C AB 82            [24]  685 	mov	r3, dpl
      00010E E5 81            [12]  686 	mov	a,sp
      000110 24 FC            [12]  687 	add	a,#0xfc
      000112 F5 81            [12]  688 	mov	sp,a
      000114 D0 04            [24]  689 	pop	ar4
      000116 D0 05            [24]  690 	pop	ar5
      000118 D0 06            [24]  691 	pop	ar6
      00011A D0 07            [24]  692 	pop	ar7
      00011C EB               [12]  693 	mov	a,r3
      00011D 60 08            [24]  694 	jz	00102$
                           000068   695 	C$fuzzy.h$677$2_0$21 ==.
                                    696 ;	../../fuzzy.h:677: return LEVEL_LO;
      00011F 90 00 00         [24]  697 	mov	dptr,#0x0000
      000122 E4               [12]  698 	clr	a
      000123 F5 F0            [12]  699 	mov	b,a
      000125 80 3F            [24]  700 	sjmp	00105$
      000127                        701 00102$:
                           000070   702 	C$fuzzy.h$680$1_0$20 ==.
                                    703 ;	../../fuzzy.h:680: if (value > LEVEL_HI) {
      000127 C0 07            [24]  704 	push	ar7
      000129 C0 06            [24]  705 	push	ar6
      00012B C0 05            [24]  706 	push	ar5
      00012D C0 04            [24]  707 	push	ar4
      00012F C0 04            [24]  708 	push	ar4
      000131 C0 05            [24]  709 	push	ar5
      000133 C0 06            [24]  710 	push	ar6
      000135 C0 07            [24]  711 	push	ar7
      000137 90 00 00         [24]  712 	mov	dptr,#0x0000
      00013A 75 F0 80         [24]  713 	mov	b, #0x80
      00013D 74 3F            [12]  714 	mov	a, #0x3f
      00013F 12 24 3A         [24]  715 	lcall	___fslt
      000142 AB 82            [24]  716 	mov	r3, dpl
      000144 E5 81            [12]  717 	mov	a,sp
      000146 24 FC            [12]  718 	add	a,#0xfc
      000148 F5 81            [12]  719 	mov	sp,a
      00014A D0 04            [24]  720 	pop	ar4
      00014C D0 05            [24]  721 	pop	ar5
      00014E D0 06            [24]  722 	pop	ar6
      000150 D0 07            [24]  723 	pop	ar7
      000152 EB               [12]  724 	mov	a,r3
      000153 60 0A            [24]  725 	jz	00104$
                           00009E   726 	C$fuzzy.h$681$2_0$22 ==.
                                    727 ;	../../fuzzy.h:681: return LEVEL_HI;
      000155 90 00 00         [24]  728 	mov	dptr,#0x0000
      000158 75 F0 80         [24]  729 	mov	b, #0x80
      00015B 74 3F            [12]  730 	mov	a, #0x3f
      00015D 80 07            [24]  731 	sjmp	00105$
      00015F                        732 00104$:
                           0000A8   733 	C$fuzzy.h$684$1_0$20 ==.
                                    734 ;	../../fuzzy.h:684: return value;
      00015F 8C 82            [24]  735 	mov	dpl, r4
      000161 8D 83            [24]  736 	mov	dph, r5
      000163 8E F0            [24]  737 	mov	b, r6
      000165 EF               [12]  738 	mov	a, r7
      000166                        739 00105$:
                           0000AF   740 	C$fuzzy.h$685$1_0$20 ==.
                                    741 ;	../../fuzzy.h:685: }
                           0000AF   742 	C$fuzzy.h$685$1_0$20 ==.
                           0000AF   743 	XFcontroller_8051$fuzzy_clamp$0$0 ==.
      000166 22               [24]  744 	ret
                                    745 ;------------------------------------------------------------
                                    746 ;Allocation info for local variables in function 'fuzzy_not'
                                    747 ;------------------------------------------------------------
                                    748 ;membership    Allocated to registers r4 r5 r6 r7 
                                    749 ;------------------------------------------------------------
                           0000B0   750 	G$fuzzy_not$0$0 ==.
                           0000B0   751 	C$fuzzy.h$690$1_0$24 ==.
                                    752 ;	../../fuzzy.h:690: float fuzzy_not(
                                    753 ;	-----------------------------------------
                                    754 ;	 function fuzzy_not
                                    755 ;	-----------------------------------------
      000167                        756 _fuzzy_not:
                           0000B0   757 	C$fuzzy.h$696$1_0$24 ==.
                                    758 ;	../../fuzzy.h:696: membership
      000167 12 00 EA         [24]  759 	lcall	_fuzzy_clamp
      00016A AC 82            [24]  760 	mov	r4, dpl
      00016C AD 83            [24]  761 	mov	r5, dph
      00016E AE F0            [24]  762 	mov	r6, b
      000170 FF               [12]  763 	mov	r7, a
      000171 C0 04            [24]  764 	push	ar4
      000173 C0 05            [24]  765 	push	ar5
      000175 C0 06            [24]  766 	push	ar6
      000177 C0 07            [24]  767 	push	ar7
      000179 90 00 00         [24]  768 	mov	dptr,#0x0000
      00017C 75 F0 80         [24]  769 	mov	b, #0x80
      00017F 74 3F            [12]  770 	mov	a, #0x3f
      000181 12 22 FF         [24]  771 	lcall	___fssub
      000184 AC 82            [24]  772 	mov	r4, dpl
      000186 AD 83            [24]  773 	mov	r5, dph
      000188 AE F0            [24]  774 	mov	r6, b
      00018A FF               [12]  775 	mov	r7, a
      00018B E5 81            [12]  776 	mov	a,sp
      00018D 24 FC            [12]  777 	add	a,#0xfc
      00018F F5 81            [12]  778 	mov	sp,a
      000191 8C 82            [24]  779 	mov	dpl, r4
      000193 8D 83            [24]  780 	mov	dph, r5
      000195 8E F0            [24]  781 	mov	b, r6
      000197 EF               [12]  782 	mov	a, r7
                           0000E1   783 	C$fuzzy.h$698$1_0$24 ==.
                                    784 ;	../../fuzzy.h:698: }
                           0000E1   785 	C$fuzzy.h$698$1_0$24 ==.
                           0000E1   786 	XG$fuzzy_not$0$0 ==.
      000198 22               [24]  787 	ret
                                    788 ;------------------------------------------------------------
                                    789 ;Allocation info for local variables in function 'fuzzy_apply_hedge'
                                    790 ;------------------------------------------------------------
                                    791 ;hedge         Allocated to stack - _bp -3 +1 
                                    792 ;membership    Allocated to stack - _bp +1 +4 
                                    793 ;result        Allocated to registers r2 r3 r6 r7 
                                    794 ;------------------------------------------------------------
                           0000E2   795 	Fcontroller_8051$fuzzy_apply_hedge$0$0 ==.
                           0000E2   796 	C$fuzzy.h$708$1_0$26 ==.
                                    797 ;	../../fuzzy.h:708: static float fuzzy_apply_hedge(
                                    798 ;	-----------------------------------------
                                    799 ;	 function fuzzy_apply_hedge
                                    800 ;	-----------------------------------------
      000199                        801 _fuzzy_apply_hedge:
      000199 C0 08            [24]  802 	push	_bp
      00019B 85 81 08         [24]  803 	mov	_bp,sp
      00019E AC 82            [24]  804 	mov	r4,dpl
      0001A0 AD 83            [24]  805 	mov	r5,dph
      0001A2 AE F0            [24]  806 	mov	r6,b
      0001A4 FF               [12]  807 	mov	r7,a
      0001A5 E5 81            [12]  808 	mov	a,sp
      0001A7 24 04            [12]  809 	add	a,#0x04
      0001A9 F5 81            [12]  810 	mov	sp,a
                           0000F4   811 	C$fuzzy.h$715$1_0$26 ==.
                                    812 ;	../../fuzzy.h:715: membership
      0001AB 8C 82            [24]  813 	mov	dpl, r4
      0001AD 8D 83            [24]  814 	mov	dph, r5
      0001AF 8E F0            [24]  815 	mov	b, r6
      0001B1 EF               [12]  816 	mov	a, r7
      0001B2 12 00 EA         [24]  817 	lcall	_fuzzy_clamp
      0001B5 A8 08            [24]  818 	mov	r0,_bp
      0001B7 08               [12]  819 	inc	r0
      0001B8 A6 82            [24]  820 	mov	@r0, dpl
      0001BA 08               [12]  821 	inc	r0
      0001BB A6 83            [24]  822 	mov	@r0, dph
      0001BD 08               [12]  823 	inc	r0
      0001BE A6 F0            [24]  824 	mov	@r0, b
      0001C0 08               [12]  825 	inc	r0
      0001C1 F6               [12]  826 	mov	@r0,a
                           00010B   827 	C$fuzzy.h$720$2_0$27 ==.
                                    828 ;	../../fuzzy.h:720: float result =
      0001C2 7A 00            [12]  829 	mov	r2,#0x00
      0001C4 7B 00            [12]  830 	mov	r3,#0x00
      0001C6 7E 80            [12]  831 	mov	r6,#0x80
      0001C8 7F 3F            [12]  832 	mov	r7,#0x3f
                           000113   833 	C$fuzzy.h$723$1_1$27 ==.
                                    834 ;	../../fuzzy.h:723: if (hedge == 0u) {
      0001CA E5 08            [12]  835 	mov	a,_bp
      0001CC 24 FD            [12]  836 	add	a,#0xfd
      0001CE F8               [12]  837 	mov	r0,a
      0001CF E6               [12]  838 	mov	a,@r0
      0001D0 70 07            [24]  839 	jnz	00110$
                           00011B   840 	C$fuzzy.h$725$2_1$28 ==.
                                    841 ;	../../fuzzy.h:725: 1u;
      0001D2 E5 08            [12]  842 	mov	a,_bp
      0001D4 24 FD            [12]  843 	add	a,#0xfd
      0001D6 F8               [12]  844 	mov	r0,a
      0001D7 76 01            [12]  845 	mov	@r0,#0x01
                           000122   846 	C$fuzzy.h$728$1_1$26 ==.
                                    847 ;	../../fuzzy.h:728: while (hedge > 0u) {
      0001D9                        848 00110$:
      0001D9 E5 08            [12]  849 	mov	a,_bp
      0001DB 24 FD            [12]  850 	add	a,#0xfd
      0001DD F8               [12]  851 	mov	r0,a
      0001DE 86 05            [24]  852 	mov	ar5,@r0
      0001E0                        853 00103$:
      0001E0 ED               [12]  854 	mov	a,r5
      0001E1 60 30            [24]  855 	jz	00105$
                           00012C   856 	C$fuzzy.h$730$1_1$26 ==.
                                    857 ;	../../fuzzy.h:730: membership;
      0001E3 C0 05            [24]  858 	push	ar5
      0001E5 A8 08            [24]  859 	mov	r0,_bp
      0001E7 08               [12]  860 	inc	r0
      0001E8 E6               [12]  861 	mov	a,@r0
      0001E9 C0 E0            [24]  862 	push	acc
      0001EB 08               [12]  863 	inc	r0
      0001EC E6               [12]  864 	mov	a,@r0
      0001ED C0 E0            [24]  865 	push	acc
      0001EF 08               [12]  866 	inc	r0
      0001F0 E6               [12]  867 	mov	a,@r0
      0001F1 C0 E0            [24]  868 	push	acc
      0001F3 08               [12]  869 	inc	r0
      0001F4 E6               [12]  870 	mov	a,@r0
      0001F5 C0 E0            [24]  871 	push	acc
                           000140   872 	C$fuzzy.h$732$1_1$26 ==.
                                    873 ;	../../fuzzy.h:732: hedge--;
      0001F7 8A 82            [24]  874 	mov	dpl, r2
      0001F9 8B 83            [24]  875 	mov	dph, r3
      0001FB 8E F0            [24]  876 	mov	b, r6
      0001FD EF               [12]  877 	mov	a, r7
      0001FE 12 23 0A         [24]  878 	lcall	___fsmul
      000201 AA 82            [24]  879 	mov	r2, dpl
      000203 AB 83            [24]  880 	mov	r3, dph
      000205 AE F0            [24]  881 	mov	r6, b
      000207 FF               [12]  882 	mov	r7, a
      000208 E5 81            [12]  883 	mov	a,sp
      00020A 24 FC            [12]  884 	add	a,#0xfc
      00020C F5 81            [12]  885 	mov	sp,a
      00020E D0 05            [24]  886 	pop	ar5
      000210 1D               [12]  887 	dec	r5
      000211 80 CD            [24]  888 	sjmp	00103$
      000213                        889 00105$:
                           00015C   890 	C$fuzzy.h$736$1_1$27 ==.
                                    891 ;	../../fuzzy.h:736: result
      000213 8A 82            [24]  892 	mov	dpl, r2
      000215 8B 83            [24]  893 	mov	dph, r3
      000217 8E F0            [24]  894 	mov	b, r6
      000219 EF               [12]  895 	mov	a, r7
      00021A 12 00 EA         [24]  896 	lcall	_fuzzy_clamp
                           000166   897 	C$fuzzy.h$752$1_1$26 ==.
                                    898 ;	../../fuzzy.h:752: }
      00021D 85 08 81         [24]  899 	mov	sp,_bp
      000220 D0 08            [24]  900 	pop	_bp
                           00016B   901 	C$fuzzy.h$752$1_1$26 ==.
                           00016B   902 	XFcontroller_8051$fuzzy_apply_hedge$0$0 ==.
      000222 22               [24]  903 	ret
                                    904 ;------------------------------------------------------------
                                    905 ;Allocation info for local variables in function 'fuzzy_and_array'
                                    906 ;------------------------------------------------------------
                                    907 ;count         Allocated to stack - _bp -4 +2 
                                    908 ;args          Allocated to stack - _bp -7 +3 
                                    909 ;method        Allocated to registers r5 
                                    910 ;result        Allocated to stack - _bp +5 +4 
                                    911 ;next          Allocated to stack - _bp +9 +4 
                                    912 ;index         Allocated to stack - _bp +13 +2 
                                    913 ;sloc0         Allocated to stack - _bp +1 +3 
                                    914 ;sloc1         Allocated to stack - _bp +4 +1 
                                    915 ;------------------------------------------------------------
                           00016C   916 	G$fuzzy_and_array$0$0 ==.
                           00016C   917 	C$fuzzy.h$766$1_1$31 ==.
                                    918 ;	../../fuzzy.h:766: float fuzzy_and_array(
                                    919 ;	-----------------------------------------
                                    920 ;	 function fuzzy_and_array
                                    921 ;	-----------------------------------------
      000223                        922 _fuzzy_and_array:
      000223 C0 08            [24]  923 	push	_bp
      000225 E5 81            [12]  924 	mov	a,sp
      000227 F5 08            [12]  925 	mov	_bp,a
      000229 24 0E            [12]  926 	add	a,#0x0e
      00022B F5 81            [12]  927 	mov	sp,a
      00022D AD 82            [24]  928 	mov	r5, dpl
                           000178   929 	C$fuzzy.h$777$1_0$31 ==.
                                    930 ;	../../fuzzy.h:777: args == NULL ||
      00022F E5 08            [12]  931 	mov	a,_bp
      000231 24 F9            [12]  932 	add	a,#0xf9
      000233 F8               [12]  933 	mov	r0,a
      000234 E6               [12]  934 	mov	a,@r0
      000235 08               [12]  935 	inc	r0
      000236 46               [12]  936 	orl	a,@r0
      000237 60 0A            [24]  937 	jz	00101$
                           000182   938 	C$fuzzy.h$778$1_0$31 ==.
                                    939 ;	../../fuzzy.h:778: count == 0u
      000239 E5 08            [12]  940 	mov	a,_bp
      00023B 24 FC            [12]  941 	add	a,#0xfc
      00023D F8               [12]  942 	mov	r0,a
      00023E E6               [12]  943 	mov	a,@r0
      00023F 08               [12]  944 	inc	r0
      000240 46               [12]  945 	orl	a,@r0
      000241 70 0B            [24]  946 	jnz	00102$
      000243                        947 00101$:
                           00018C   948 	C$fuzzy.h$780$2_0$32 ==.
                                    949 ;	../../fuzzy.h:780: return LEVEL_HI;
      000243 90 00 00         [24]  950 	mov	dptr,#0x0000
      000246 75 F0 80         [24]  951 	mov	b, #0x80
      000249 74 3F            [12]  952 	mov	a, #0x3f
      00024B 02 04 BC         [24]  953 	ljmp	00121$
      00024E                        954 00102$:
                           000197   955 	C$fuzzy.h$784$1_0$31 ==.
                                    956 ;	../../fuzzy.h:784: method != FUZZY_LOGIC_STANDARD &&
      00024E ED               [12]  957 	mov	a,r5
      00024F 60 13            [24]  958 	jz	00105$
                           00019A   959 	C$fuzzy.h$785$1_0$31 ==.
                                    960 ;	../../fuzzy.h:785: method != FUZZY_LOGIC_ALGEBRAIC &&
      000251 BD 01 02         [24]  961 	cjne	r5,#0x01,00192$
      000254 80 0E            [24]  962 	sjmp	00105$
      000256                        963 00192$:
                           00019F   964 	C$fuzzy.h$787$1_0$31 ==.
                                    965 ;	../../fuzzy.h:787: ) {
      000256 BD 02 02         [24]  966 	cjne	r5,#0x02,00193$
      000259 80 09            [24]  967 	sjmp	00105$
      00025B                        968 00193$:
                           0001A4   969 	C$fuzzy.h$788$2_0$33 ==.
                                    970 ;	../../fuzzy.h:788: return LEVEL_LO;
      00025B 90 00 00         [24]  971 	mov	dptr,#0x0000
      00025E E4               [12]  972 	clr	a
      00025F F5 F0            [12]  973 	mov	b,a
      000261 02 04 BC         [24]  974 	ljmp	00121$
      000264                        975 00105$:
                           0001AD   976 	C$fuzzy.h$793$1_0$31 ==.
                                    977 ;	../../fuzzy.h:793: args[0]
      000264 E5 08            [12]  978 	mov	a,_bp
      000266 24 F9            [12]  979 	add	a,#0xf9
      000268 F8               [12]  980 	mov	r0,a
      000269 A9 08            [24]  981 	mov	r1,_bp
      00026B 09               [12]  982 	inc	r1
      00026C E6               [12]  983 	mov	a,@r0
      00026D F7               [12]  984 	mov	@r1,a
      00026E 08               [12]  985 	inc	r0
      00026F E6               [12]  986 	mov	a,@r0
      000270 09               [12]  987 	inc	r1
      000271 F7               [12]  988 	mov	@r1,a
      000272 08               [12]  989 	inc	r0
      000273 E6               [12]  990 	mov	a,@r0
      000274 09               [12]  991 	inc	r1
      000275 F7               [12]  992 	mov	@r1,a
      000276 A8 08            [24]  993 	mov	r0,_bp
      000278 08               [12]  994 	inc	r0
      000279 86 82            [24]  995 	mov	dpl,@r0
      00027B 08               [12]  996 	inc	r0
      00027C 86 83            [24]  997 	mov	dph,@r0
      00027E 08               [12]  998 	inc	r0
      00027F 86 F0            [24]  999 	mov	b,@r0
      000281 12 26 66         [24] 1000 	lcall	__gptrget
      000284 FA               [12] 1001 	mov	r2,a
      000285 A3               [24] 1002 	inc	dptr
      000286 12 26 66         [24] 1003 	lcall	__gptrget
      000289 FB               [12] 1004 	mov	r3,a
      00028A A3               [24] 1005 	inc	dptr
      00028B 12 26 66         [24] 1006 	lcall	__gptrget
      00028E FE               [12] 1007 	mov	r6,a
      00028F A3               [24] 1008 	inc	dptr
      000290 12 26 66         [24] 1009 	lcall	__gptrget
      000293 8A 82            [24] 1010 	mov	dpl,r2
      000295 8B 83            [24] 1011 	mov	dph,r3
      000297 8E F0            [24] 1012 	mov	b,r6
      000299 C0 05            [24] 1013 	push	ar5
      00029B 12 00 EA         [24] 1014 	lcall	_fuzzy_clamp
      00029E C8               [12] 1015 	xch	a,r0
      00029F E5 08            [12] 1016 	mov	a,_bp
      0002A1 24 05            [12] 1017 	add	a,#0x05
      0002A3 C8               [12] 1018 	xch	a,r0
      0002A4 A6 82            [24] 1019 	mov	@r0, dpl
      0002A6 08               [12] 1020 	inc	r0
      0002A7 A6 83            [24] 1021 	mov	@r0, dph
      0002A9 08               [12] 1022 	inc	r0
      0002AA A6 F0            [24] 1023 	mov	@r0, b
      0002AC 08               [12] 1024 	inc	r0
      0002AD F6               [12] 1025 	mov	@r0,a
      0002AE D0 05            [24] 1026 	pop	ar5
                           0001F9  1027 	C$fuzzy.h$797$3_0$35 ==.
                                   1028 ;	../../fuzzy.h:797: index = 1u;
      0002B0 E4               [12] 1029 	clr	a
      0002B1 BD 00 01         [24] 1030 	cjne	r5,#0x00,00194$
      0002B4 04               [12] 1031 	inc	a
      0002B5                       1032 00194$:
      0002B5 FB               [12] 1033 	mov	r3,a
      0002B6 BD 01 03         [24] 1034 	cjne	r5,#0x01,00196$
      0002B9 ED               [12] 1035 	mov	a,r5
      0002BA 80 01            [24] 1036 	sjmp	00197$
      0002BC                       1037 00196$:
      0002BC E4               [12] 1038 	clr	a
      0002BD                       1039 00197$:
      0002BD FA               [12] 1040 	mov	r2,a
      0002BE E5 08            [12] 1041 	mov	a,_bp
      0002C0 24 04            [12] 1042 	add	a,#0x04
      0002C2 F8               [12] 1043 	mov	r0,a
      0002C3 E4               [12] 1044 	clr	a
      0002C4 BD 02 01         [24] 1045 	cjne	r5,#0x02,00198$
      0002C7 04               [12] 1046 	inc	a
      0002C8                       1047 00198$:
      0002C8 F6               [12] 1048 	mov	@r0,a
      0002C9 E5 08            [12] 1049 	mov	a,_bp
      0002CB 24 0D            [12] 1050 	add	a,#0x0d
      0002CD F8               [12] 1051 	mov	r0,a
      0002CE 76 01            [12] 1052 	mov	@r0,#0x01
      0002D0 08               [12] 1053 	inc	r0
      0002D1 76 00            [12] 1054 	mov	@r0,#0x00
      0002D3                       1055 00119$:
                           00021C  1056 	C$fuzzy.h$798$2_0$34 ==.
                                   1057 ;	../../fuzzy.h:798: index < count;
      0002D3 E5 08            [12] 1058 	mov	a,_bp
      0002D5 24 0D            [12] 1059 	add	a,#0x0d
      0002D7 F8               [12] 1060 	mov	r0,a
      0002D8 E5 08            [12] 1061 	mov	a,_bp
      0002DA 24 FC            [12] 1062 	add	a,#0xfc
      0002DC F9               [12] 1063 	mov	r1,a
      0002DD C3               [12] 1064 	clr	c
      0002DE E6               [12] 1065 	mov	a,@r0
      0002DF 97               [12] 1066 	subb	a,@r1
      0002E0 08               [12] 1067 	inc	r0
      0002E1 E6               [12] 1068 	mov	a,@r0
      0002E2 09               [12] 1069 	inc	r1
      0002E3 97               [12] 1070 	subb	a,@r1
      0002E4 40 03            [24] 1071 	jc	00200$
      0002E6 02 04 AA         [24] 1072 	ljmp	00117$
      0002E9                       1073 00200$:
                           000232  1074 	C$fuzzy.h$803$1_0$31 ==.
                                   1075 ;	../../fuzzy.h:803: args[index]
      0002E9 C0 02            [24] 1076 	push	ar2
      0002EB E5 08            [12] 1077 	mov	a,_bp
      0002ED 24 0D            [12] 1078 	add	a,#0x0d
      0002EF F8               [12] 1079 	mov	r0,a
      0002F0 E6               [12] 1080 	mov	a,@r0
      0002F1 26               [12] 1081 	add	a,@r0
      0002F2 FD               [12] 1082 	mov	r5,a
      0002F3 08               [12] 1083 	inc	r0
      0002F4 E6               [12] 1084 	mov	a,@r0
      0002F5 33               [12] 1085 	rlc	a
      0002F6 FC               [12] 1086 	mov	r4,a
      0002F7 ED               [12] 1087 	mov	a,r5
      0002F8 2D               [12] 1088 	add	a,r5
      0002F9 FD               [12] 1089 	mov	r5,a
      0002FA EC               [12] 1090 	mov	a,r4
      0002FB 33               [12] 1091 	rlc	a
      0002FC FC               [12] 1092 	mov	r4,a
      0002FD A8 08            [24] 1093 	mov	r0,_bp
      0002FF 08               [12] 1094 	inc	r0
      000300 ED               [12] 1095 	mov	a,r5
      000301 26               [12] 1096 	add	a, @r0
      000302 FA               [12] 1097 	mov	r2,a
      000303 EC               [12] 1098 	mov	a,r4
      000304 08               [12] 1099 	inc	r0
      000305 36               [12] 1100 	addc	a, @r0
      000306 FC               [12] 1101 	mov	r4,a
      000307 08               [12] 1102 	inc	r0
      000308 86 05            [24] 1103 	mov	ar5,@r0
      00030A 8A 82            [24] 1104 	mov	dpl,r2
      00030C 8C 83            [24] 1105 	mov	dph,r4
      00030E 8D F0            [24] 1106 	mov	b,r5
      000310 12 26 66         [24] 1107 	lcall	__gptrget
      000313 FA               [12] 1108 	mov	r2,a
      000314 A3               [24] 1109 	inc	dptr
      000315 12 26 66         [24] 1110 	lcall	__gptrget
      000318 FC               [12] 1111 	mov	r4,a
      000319 A3               [24] 1112 	inc	dptr
      00031A 12 26 66         [24] 1113 	lcall	__gptrget
      00031D FD               [12] 1114 	mov	r5,a
      00031E A3               [24] 1115 	inc	dptr
      00031F 12 26 66         [24] 1116 	lcall	__gptrget
      000322 8A 82            [24] 1117 	mov	dpl,r2
      000324 8C 83            [24] 1118 	mov	dph,r4
      000326 8D F0            [24] 1119 	mov	b,r5
      000328 C0 03            [24] 1120 	push	ar3
      00032A C0 02            [24] 1121 	push	ar2
      00032C 12 00 EA         [24] 1122 	lcall	_fuzzy_clamp
      00032F C8               [12] 1123 	xch	a,r0
      000330 E5 08            [12] 1124 	mov	a,_bp
      000332 24 09            [12] 1125 	add	a,#0x09
      000334 C8               [12] 1126 	xch	a,r0
      000335 A6 82            [24] 1127 	mov	@r0, dpl
      000337 08               [12] 1128 	inc	r0
      000338 A6 83            [24] 1129 	mov	@r0, dph
      00033A 08               [12] 1130 	inc	r0
      00033B A6 F0            [24] 1131 	mov	@r0, b
      00033D 08               [12] 1132 	inc	r0
      00033E F6               [12] 1133 	mov	@r0,a
      00033F D0 02            [24] 1134 	pop	ar2
      000341 D0 03            [24] 1135 	pop	ar3
                           00028C  1136 	C$fuzzy.h$806$1_0$31 ==.
                                   1137 ;	../../fuzzy.h:806: switch (method) {
      000343 D0 02            [24] 1138 	pop	ar2
      000345 EB               [12] 1139 	mov	a,r3
      000346 70 11            [24] 1140 	jnz	00108$
      000348 EA               [12] 1141 	mov	a,r2
      000349 70 65            [24] 1142 	jnz	00111$
      00034B E5 08            [12] 1143 	mov	a,_bp
      00034D 24 04            [12] 1144 	add	a,#0x04
      00034F F8               [12] 1145 	mov	r0,a
      000350 E6               [12] 1146 	mov	a,@r0
      000351 60 03            [24] 1147 	jz	00203$
      000353 02 03 F7         [24] 1148 	ljmp	00112$
      000356                       1149 00203$:
      000356 02 04 94         [24] 1150 	ljmp	00115$
                           0002A2  1151 	C$fuzzy.h$807$4_0$36 ==.
                                   1152 ;	../../fuzzy.h:807: case FUZZY_LOGIC_STANDARD:
      000359                       1153 00108$:
                           0002A2  1154 	C$fuzzy.h$808$1_0$31 ==.
                                   1155 ;	../../fuzzy.h:808: if (next < result) {
      000359 C0 03            [24] 1156 	push	ar3
      00035B C0 02            [24] 1157 	push	ar2
      00035D E5 08            [12] 1158 	mov	a,_bp
      00035F 24 05            [12] 1159 	add	a,#0x05
      000361 F8               [12] 1160 	mov	r0,a
      000362 E6               [12] 1161 	mov	a,@r0
      000363 C0 E0            [24] 1162 	push	acc
      000365 08               [12] 1163 	inc	r0
      000366 E6               [12] 1164 	mov	a,@r0
      000367 C0 E0            [24] 1165 	push	acc
      000369 08               [12] 1166 	inc	r0
      00036A E6               [12] 1167 	mov	a,@r0
      00036B C0 E0            [24] 1168 	push	acc
      00036D 08               [12] 1169 	inc	r0
      00036E E6               [12] 1170 	mov	a,@r0
      00036F C0 E0            [24] 1171 	push	acc
      000371 E5 08            [12] 1172 	mov	a,_bp
      000373 24 09            [12] 1173 	add	a,#0x09
      000375 F8               [12] 1174 	mov	r0,a
      000376 86 82            [24] 1175 	mov	dpl, @r0
      000378 08               [12] 1176 	inc	r0
      000379 86 83            [24] 1177 	mov	dph, @r0
      00037B 08               [12] 1178 	inc	r0
      00037C 86 F0            [24] 1179 	mov	b, @r0
      00037E 08               [12] 1180 	inc	r0
      00037F E6               [12] 1181 	mov	a, @r0
      000380 12 24 3A         [24] 1182 	lcall	___fslt
      000383 AF 82            [24] 1183 	mov	r7, dpl
      000385 E5 81            [12] 1184 	mov	a,sp
      000387 24 FC            [12] 1185 	add	a,#0xfc
      000389 F5 81            [12] 1186 	mov	sp,a
      00038B D0 02            [24] 1187 	pop	ar2
      00038D D0 03            [24] 1188 	pop	ar3
      00038F EF               [12] 1189 	mov	a,r7
      000390 70 03            [24] 1190 	jnz	00204$
      000392 02 04 9C         [24] 1191 	ljmp	00120$
      000395                       1192 00204$:
                           0002DE  1193 	C$fuzzy.h$809$5_0$37 ==.
                                   1194 ;	../../fuzzy.h:809: result = next;
      000395 E5 08            [12] 1195 	mov	a,_bp
      000397 24 09            [12] 1196 	add	a,#0x09
      000399 F8               [12] 1197 	mov	r0,a
      00039A E5 08            [12] 1198 	mov	a,_bp
      00039C 24 05            [12] 1199 	add	a,#0x05
      00039E F9               [12] 1200 	mov	r1,a
      00039F E6               [12] 1201 	mov	a,@r0
      0003A0 F7               [12] 1202 	mov	@r1,a
      0003A1 08               [12] 1203 	inc	r0
      0003A2 E6               [12] 1204 	mov	a,@r0
      0003A3 09               [12] 1205 	inc	r1
      0003A4 F7               [12] 1206 	mov	@r1,a
      0003A5 08               [12] 1207 	inc	r0
      0003A6 E6               [12] 1208 	mov	a,@r0
      0003A7 09               [12] 1209 	inc	r1
      0003A8 F7               [12] 1210 	mov	@r1,a
      0003A9 08               [12] 1211 	inc	r0
      0003AA E6               [12] 1212 	mov	a,@r0
      0003AB 09               [12] 1213 	inc	r1
      0003AC F7               [12] 1214 	mov	@r1,a
                           0002F6  1215 	C$fuzzy.h$811$4_0$36 ==.
                                   1216 ;	../../fuzzy.h:811: break;
      0003AD 02 04 9C         [24] 1217 	ljmp	00120$
                           0002F9  1218 	C$fuzzy.h$813$4_0$36 ==.
                                   1219 ;	../../fuzzy.h:813: case FUZZY_LOGIC_ALGEBRAIC:
      0003B0                       1220 00111$:
                           0002F9  1221 	C$fuzzy.h$815$1_0$31 ==.
                                   1222 ;	../../fuzzy.h:815: next;
      0003B0 C0 03            [24] 1223 	push	ar3
      0003B2 C0 02            [24] 1224 	push	ar2
      0003B4 E5 08            [12] 1225 	mov	a,_bp
      0003B6 24 09            [12] 1226 	add	a,#0x09
      0003B8 F8               [12] 1227 	mov	r0,a
      0003B9 E6               [12] 1228 	mov	a,@r0
      0003BA C0 E0            [24] 1229 	push	acc
      0003BC 08               [12] 1230 	inc	r0
      0003BD E6               [12] 1231 	mov	a,@r0
      0003BE C0 E0            [24] 1232 	push	acc
      0003C0 08               [12] 1233 	inc	r0
      0003C1 E6               [12] 1234 	mov	a,@r0
      0003C2 C0 E0            [24] 1235 	push	acc
      0003C4 08               [12] 1236 	inc	r0
      0003C5 E6               [12] 1237 	mov	a,@r0
      0003C6 C0 E0            [24] 1238 	push	acc
                           000311  1239 	C$fuzzy.h$816$1_0$31 ==.
                                   1240 ;	../../fuzzy.h:816: break;
      0003C8 E5 08            [12] 1241 	mov	a,_bp
      0003CA 24 05            [12] 1242 	add	a,#0x05
      0003CC F8               [12] 1243 	mov	r0,a
      0003CD 86 82            [24] 1244 	mov	dpl, @r0
      0003CF 08               [12] 1245 	inc	r0
      0003D0 86 83            [24] 1246 	mov	dph, @r0
      0003D2 08               [12] 1247 	inc	r0
      0003D3 86 F0            [24] 1248 	mov	b, @r0
      0003D5 08               [12] 1249 	inc	r0
      0003D6 E6               [12] 1250 	mov	a, @r0
      0003D7 12 23 0A         [24] 1251 	lcall	___fsmul
      0003DA C8               [12] 1252 	xch	a,r0
      0003DB E5 08            [12] 1253 	mov	a,_bp
      0003DD 24 05            [12] 1254 	add	a,#0x05
      0003DF C8               [12] 1255 	xch	a,r0
      0003E0 A6 82            [24] 1256 	mov	@r0, dpl
      0003E2 08               [12] 1257 	inc	r0
      0003E3 A6 83            [24] 1258 	mov	@r0, dph
      0003E5 08               [12] 1259 	inc	r0
      0003E6 A6 F0            [24] 1260 	mov	@r0, b
      0003E8 08               [12] 1261 	inc	r0
      0003E9 F6               [12] 1262 	mov	@r0,a
      0003EA E5 81            [12] 1263 	mov	a,sp
      0003EC 24 FC            [12] 1264 	add	a,#0xfc
      0003EE F5 81            [12] 1265 	mov	sp,a
      0003F0 D0 02            [24] 1266 	pop	ar2
      0003F2 D0 03            [24] 1267 	pop	ar3
      0003F4 02 04 9C         [24] 1268 	ljmp	00120$
                           000340  1269 	C$fuzzy.h$818$4_0$36 ==.
                                   1270 ;	../../fuzzy.h:818: case FUZZY_LOGIC_BOUNDED:
      0003F7                       1271 00112$:
                           000340  1272 	C$fuzzy.h$821$1_0$31 ==.
                                   1273 ;	../../fuzzy.h:821: next -
      0003F7 C0 03            [24] 1274 	push	ar3
      0003F9 C0 02            [24] 1275 	push	ar2
      0003FB E5 08            [12] 1276 	mov	a,_bp
      0003FD 24 09            [12] 1277 	add	a,#0x09
      0003FF F8               [12] 1278 	mov	r0,a
      000400 E6               [12] 1279 	mov	a,@r0
      000401 C0 E0            [24] 1280 	push	acc
      000403 08               [12] 1281 	inc	r0
      000404 E6               [12] 1282 	mov	a,@r0
      000405 C0 E0            [24] 1283 	push	acc
      000407 08               [12] 1284 	inc	r0
      000408 E6               [12] 1285 	mov	a,@r0
      000409 C0 E0            [24] 1286 	push	acc
      00040B 08               [12] 1287 	inc	r0
      00040C E6               [12] 1288 	mov	a,@r0
      00040D C0 E0            [24] 1289 	push	acc
      00040F E5 08            [12] 1290 	mov	a,_bp
      000411 24 05            [12] 1291 	add	a,#0x05
      000413 F8               [12] 1292 	mov	r0,a
      000414 86 82            [24] 1293 	mov	dpl, @r0
      000416 08               [12] 1294 	inc	r0
      000417 86 83            [24] 1295 	mov	dph, @r0
      000419 08               [12] 1296 	inc	r0
      00041A 86 F0            [24] 1297 	mov	b, @r0
      00041C 08               [12] 1298 	inc	r0
      00041D E6               [12] 1299 	mov	a, @r0
      00041E 12 24 8C         [24] 1300 	lcall	___fsadd
      000421 AC 82            [24] 1301 	mov	r4, dpl
      000423 AD 83            [24] 1302 	mov	r5, dph
      000425 AE F0            [24] 1303 	mov	r6, b
      000427 FF               [12] 1304 	mov	r7, a
      000428 E5 81            [12] 1305 	mov	a,sp
      00042A 24 FC            [12] 1306 	add	a,#0xfc
      00042C F5 81            [12] 1307 	mov	sp,a
      00042E E4               [12] 1308 	clr	a
      00042F C0 E0            [24] 1309 	push	acc
      000431 C0 E0            [24] 1310 	push	acc
      000433 74 80            [12] 1311 	mov	a,#0x80
      000435 C0 E0            [24] 1312 	push	acc
      000437 74 3F            [12] 1313 	mov	a,#0x3f
      000439 C0 E0            [24] 1314 	push	acc
                           000384  1315 	C$fuzzy.h$824$1_0$31 ==.
                                   1316 ;	../../fuzzy.h:824: if (result < LEVEL_LO) {
      00043B 8C 82            [24] 1317 	mov	dpl, r4
      00043D 8D 83            [24] 1318 	mov	dph, r5
      00043F 8E F0            [24] 1319 	mov	b, r6
      000441 EF               [12] 1320 	mov	a, r7
      000442 12 22 FF         [24] 1321 	lcall	___fssub
      000445 C8               [12] 1322 	xch	a,r0
      000446 E5 08            [12] 1323 	mov	a,_bp
      000448 24 05            [12] 1324 	add	a,#0x05
      00044A C8               [12] 1325 	xch	a,r0
      00044B A6 82            [24] 1326 	mov	@r0, dpl
      00044D 08               [12] 1327 	inc	r0
      00044E A6 83            [24] 1328 	mov	@r0, dph
      000450 08               [12] 1329 	inc	r0
      000451 A6 F0            [24] 1330 	mov	@r0, b
      000453 08               [12] 1331 	inc	r0
      000454 F6               [12] 1332 	mov	@r0,a
      000455 E5 81            [12] 1333 	mov	a,sp
      000457 24 FC            [12] 1334 	add	a,#0xfc
      000459 F5 81            [12] 1335 	mov	sp,a
      00045B E4               [12] 1336 	clr	a
      00045C C0 E0            [24] 1337 	push	acc
      00045E C0 E0            [24] 1338 	push	acc
      000460 C0 E0            [24] 1339 	push	acc
      000462 C0 E0            [24] 1340 	push	acc
      000464 E5 08            [12] 1341 	mov	a,_bp
      000466 24 05            [12] 1342 	add	a,#0x05
      000468 F8               [12] 1343 	mov	r0,a
      000469 86 82            [24] 1344 	mov	dpl, @r0
      00046B 08               [12] 1345 	inc	r0
      00046C 86 83            [24] 1346 	mov	dph, @r0
      00046E 08               [12] 1347 	inc	r0
      00046F 86 F0            [24] 1348 	mov	b, @r0
      000471 08               [12] 1349 	inc	r0
      000472 E6               [12] 1350 	mov	a, @r0
      000473 12 24 3A         [24] 1351 	lcall	___fslt
      000476 AF 82            [24] 1352 	mov	r7, dpl
      000478 E5 81            [12] 1353 	mov	a,sp
      00047A 24 FC            [12] 1354 	add	a,#0xfc
      00047C F5 81            [12] 1355 	mov	sp,a
      00047E D0 02            [24] 1356 	pop	ar2
      000480 D0 03            [24] 1357 	pop	ar3
      000482 EF               [12] 1358 	mov	a,r7
      000483 60 17            [24] 1359 	jz	00120$
                           0003CE  1360 	C$fuzzy.h$825$5_0$38 ==.
                                   1361 ;	../../fuzzy.h:825: result = LEVEL_LO;
      000485 E5 08            [12] 1362 	mov	a,_bp
      000487 24 05            [12] 1363 	add	a,#0x05
      000489 F8               [12] 1364 	mov	r0,a
      00048A E4               [12] 1365 	clr	a
      00048B F6               [12] 1366 	mov	@r0,a
      00048C 08               [12] 1367 	inc	r0
      00048D F6               [12] 1368 	mov	@r0,a
      00048E 08               [12] 1369 	inc	r0
      00048F F6               [12] 1370 	mov	@r0,a
      000490 08               [12] 1371 	inc	r0
      000491 F6               [12] 1372 	mov	@r0,a
                           0003DB  1373 	C$fuzzy.h$827$4_0$36 ==.
                                   1374 ;	../../fuzzy.h:827: break;
                           0003DB  1375 	C$fuzzy.h$829$4_0$36 ==.
                                   1376 ;	../../fuzzy.h:829: default:
      000492 80 08            [24] 1377 	sjmp	00120$
      000494                       1378 00115$:
                           0003DD  1379 	C$fuzzy.h$830$4_0$36 ==.
                                   1380 ;	../../fuzzy.h:830: return LEVEL_LO;
      000494 90 00 00         [24] 1381 	mov	dptr,#0x0000
      000497 E4               [12] 1382 	clr	a
      000498 F5 F0            [12] 1383 	mov	b,a
                           0003E3  1384 	C$fuzzy.h$831$3_0$35 ==.
                                   1385 ;	../../fuzzy.h:831: }
      00049A 80 20            [24] 1386 	sjmp	00121$
      00049C                       1387 00120$:
                           0003E5  1388 	C$fuzzy.h$799$2_0$34 ==.
                                   1389 ;	../../fuzzy.h:799: index++
      00049C E5 08            [12] 1390 	mov	a,_bp
      00049E 24 0D            [12] 1391 	add	a,#0x0d
      0004A0 F8               [12] 1392 	mov	r0,a
      0004A1 06               [12] 1393 	inc	@r0
      0004A2 B6 00 02         [24] 1394 	cjne	@r0,#0x00,00206$
      0004A5 08               [12] 1395 	inc	r0
      0004A6 06               [12] 1396 	inc	@r0
      0004A7                       1397 00206$:
      0004A7 02 02 D3         [24] 1398 	ljmp	00119$
      0004AA                       1399 00117$:
                           0003F3  1400 	C$fuzzy.h$835$1_0$31 ==.
                                   1401 ;	../../fuzzy.h:835: result
      0004AA E5 08            [12] 1402 	mov	a,_bp
      0004AC 24 05            [12] 1403 	add	a,#0x05
      0004AE F8               [12] 1404 	mov	r0,a
      0004AF 86 82            [24] 1405 	mov	dpl, @r0
      0004B1 08               [12] 1406 	inc	r0
      0004B2 86 83            [24] 1407 	mov	dph, @r0
      0004B4 08               [12] 1408 	inc	r0
      0004B5 86 F0            [24] 1409 	mov	b, @r0
      0004B7 08               [12] 1410 	inc	r0
      0004B8 E6               [12] 1411 	mov	a, @r0
      0004B9 12 00 EA         [24] 1412 	lcall	_fuzzy_clamp
      0004BC                       1413 00121$:
                           000405  1414 	C$fuzzy.h$837$1_0$31 ==.
                                   1415 ;	../../fuzzy.h:837: }
      0004BC 85 08 81         [24] 1416 	mov	sp,_bp
      0004BF D0 08            [24] 1417 	pop	_bp
                           00040A  1418 	C$fuzzy.h$837$1_0$31 ==.
                           00040A  1419 	XG$fuzzy_and_array$0$0 ==.
      0004C1 22               [24] 1420 	ret
                                   1421 ;------------------------------------------------------------
                                   1422 ;Allocation info for local variables in function 'fuzzy_or_array'
                                   1423 ;------------------------------------------------------------
                                   1424 ;count         Allocated to stack - _bp -4 +2 
                                   1425 ;args          Allocated to stack - _bp -7 +3 
                                   1426 ;method        Allocated to registers r5 
                                   1427 ;result        Allocated to stack - _bp +10 +4 
                                   1428 ;next          Allocated to registers r4 r5 r6 r3 
                                   1429 ;index         Allocated to stack - _bp +14 +2 
                                   1430 ;sloc0         Allocated to stack - _bp +1 +3 
                                   1431 ;sloc1         Allocated to stack - _bp +4 +1 
                                   1432 ;sloc2         Allocated to stack - _bp +5 +1 
                                   1433 ;sloc3         Allocated to stack - _bp +6 +4 
                                   1434 ;------------------------------------------------------------
                           00040B  1435 	G$fuzzy_or_array$0$0 ==.
                           00040B  1436 	C$fuzzy.h$852$1_0$40 ==.
                                   1437 ;	../../fuzzy.h:852: float fuzzy_or_array(
                                   1438 ;	-----------------------------------------
                                   1439 ;	 function fuzzy_or_array
                                   1440 ;	-----------------------------------------
      0004C2                       1441 _fuzzy_or_array:
      0004C2 C0 08            [24] 1442 	push	_bp
      0004C4 E5 81            [12] 1443 	mov	a,sp
      0004C6 F5 08            [12] 1444 	mov	_bp,a
      0004C8 24 0F            [12] 1445 	add	a,#0x0f
      0004CA F5 81            [12] 1446 	mov	sp,a
      0004CC AD 82            [24] 1447 	mov	r5, dpl
                           000417  1448 	C$fuzzy.h$863$1_0$40 ==.
                                   1449 ;	../../fuzzy.h:863: args == NULL ||
      0004CE E5 08            [12] 1450 	mov	a,_bp
      0004D0 24 F9            [12] 1451 	add	a,#0xf9
      0004D2 F8               [12] 1452 	mov	r0,a
      0004D3 E6               [12] 1453 	mov	a,@r0
      0004D4 08               [12] 1454 	inc	r0
      0004D5 46               [12] 1455 	orl	a,@r0
      0004D6 60 0A            [24] 1456 	jz	00101$
                           000421  1457 	C$fuzzy.h$864$1_0$40 ==.
                                   1458 ;	../../fuzzy.h:864: count == 0u
      0004D8 E5 08            [12] 1459 	mov	a,_bp
      0004DA 24 FC            [12] 1460 	add	a,#0xfc
      0004DC F8               [12] 1461 	mov	r0,a
      0004DD E6               [12] 1462 	mov	a,@r0
      0004DE 08               [12] 1463 	inc	r0
      0004DF 46               [12] 1464 	orl	a,@r0
      0004E0 70 09            [24] 1465 	jnz	00102$
      0004E2                       1466 00101$:
                           00042B  1467 	C$fuzzy.h$866$2_0$41 ==.
                                   1468 ;	../../fuzzy.h:866: return LEVEL_LO;
      0004E2 90 00 00         [24] 1469 	mov	dptr,#0x0000
      0004E5 E4               [12] 1470 	clr	a
      0004E6 F5 F0            [12] 1471 	mov	b,a
      0004E8 02 07 7E         [24] 1472 	ljmp	00121$
      0004EB                       1473 00102$:
                           000434  1474 	C$fuzzy.h$870$1_0$40 ==.
                                   1475 ;	../../fuzzy.h:870: method != FUZZY_LOGIC_STANDARD &&
      0004EB ED               [12] 1476 	mov	a,r5
      0004EC 60 13            [24] 1477 	jz	00105$
                           000437  1478 	C$fuzzy.h$871$1_0$40 ==.
                                   1479 ;	../../fuzzy.h:871: method != FUZZY_LOGIC_ALGEBRAIC &&
      0004EE BD 01 02         [24] 1480 	cjne	r5,#0x01,00192$
      0004F1 80 0E            [24] 1481 	sjmp	00105$
      0004F3                       1482 00192$:
                           00043C  1483 	C$fuzzy.h$873$1_0$40 ==.
                                   1484 ;	../../fuzzy.h:873: ) {
      0004F3 BD 02 02         [24] 1485 	cjne	r5,#0x02,00193$
      0004F6 80 09            [24] 1486 	sjmp	00105$
      0004F8                       1487 00193$:
                           000441  1488 	C$fuzzy.h$874$2_0$42 ==.
                                   1489 ;	../../fuzzy.h:874: return LEVEL_LO;
      0004F8 90 00 00         [24] 1490 	mov	dptr,#0x0000
      0004FB E4               [12] 1491 	clr	a
      0004FC F5 F0            [12] 1492 	mov	b,a
      0004FE 02 07 7E         [24] 1493 	ljmp	00121$
      000501                       1494 00105$:
                           00044A  1495 	C$fuzzy.h$879$1_0$40 ==.
                                   1496 ;	../../fuzzy.h:879: args[0]
      000501 E5 08            [12] 1497 	mov	a,_bp
      000503 24 F9            [12] 1498 	add	a,#0xf9
      000505 F8               [12] 1499 	mov	r0,a
      000506 A9 08            [24] 1500 	mov	r1,_bp
      000508 09               [12] 1501 	inc	r1
      000509 E6               [12] 1502 	mov	a,@r0
      00050A F7               [12] 1503 	mov	@r1,a
      00050B 08               [12] 1504 	inc	r0
      00050C E6               [12] 1505 	mov	a,@r0
      00050D 09               [12] 1506 	inc	r1
      00050E F7               [12] 1507 	mov	@r1,a
      00050F 08               [12] 1508 	inc	r0
      000510 E6               [12] 1509 	mov	a,@r0
      000511 09               [12] 1510 	inc	r1
      000512 F7               [12] 1511 	mov	@r1,a
      000513 A8 08            [24] 1512 	mov	r0,_bp
      000515 08               [12] 1513 	inc	r0
      000516 86 82            [24] 1514 	mov	dpl,@r0
      000518 08               [12] 1515 	inc	r0
      000519 86 83            [24] 1516 	mov	dph,@r0
      00051B 08               [12] 1517 	inc	r0
      00051C 86 F0            [24] 1518 	mov	b,@r0
      00051E 12 26 66         [24] 1519 	lcall	__gptrget
      000521 FA               [12] 1520 	mov	r2,a
      000522 A3               [24] 1521 	inc	dptr
      000523 12 26 66         [24] 1522 	lcall	__gptrget
      000526 FB               [12] 1523 	mov	r3,a
      000527 A3               [24] 1524 	inc	dptr
      000528 12 26 66         [24] 1525 	lcall	__gptrget
      00052B FE               [12] 1526 	mov	r6,a
      00052C A3               [24] 1527 	inc	dptr
      00052D 12 26 66         [24] 1528 	lcall	__gptrget
      000530 8A 82            [24] 1529 	mov	dpl,r2
      000532 8B 83            [24] 1530 	mov	dph,r3
      000534 8E F0            [24] 1531 	mov	b,r6
      000536 C0 05            [24] 1532 	push	ar5
      000538 12 00 EA         [24] 1533 	lcall	_fuzzy_clamp
      00053B C8               [12] 1534 	xch	a,r0
      00053C E5 08            [12] 1535 	mov	a,_bp
      00053E 24 0A            [12] 1536 	add	a,#0x0a
      000540 C8               [12] 1537 	xch	a,r0
      000541 A6 82            [24] 1538 	mov	@r0, dpl
      000543 08               [12] 1539 	inc	r0
      000544 A6 83            [24] 1540 	mov	@r0, dph
      000546 08               [12] 1541 	inc	r0
      000547 A6 F0            [24] 1542 	mov	@r0, b
      000549 08               [12] 1543 	inc	r0
      00054A F6               [12] 1544 	mov	@r0,a
      00054B D0 05            [24] 1545 	pop	ar5
                           000496  1546 	C$fuzzy.h$883$3_0$44 ==.
                                   1547 ;	../../fuzzy.h:883: index = 1u;
      00054D E5 08            [12] 1548 	mov	a,_bp
      00054F 24 05            [12] 1549 	add	a,#0x05
      000551 F8               [12] 1550 	mov	r0,a
      000552 E4               [12] 1551 	clr	a
      000553 BD 00 01         [24] 1552 	cjne	r5,#0x00,00194$
      000556 04               [12] 1553 	inc	a
      000557                       1554 00194$:
      000557 F6               [12] 1555 	mov	@r0,a
      000558 BD 01 03         [24] 1556 	cjne	r5,#0x01,00196$
      00055B ED               [12] 1557 	mov	a,r5
      00055C 80 01            [24] 1558 	sjmp	00197$
      00055E                       1559 00196$:
      00055E E4               [12] 1560 	clr	a
      00055F                       1561 00197$:
      00055F FA               [12] 1562 	mov	r2,a
      000560 E5 08            [12] 1563 	mov	a,_bp
      000562 24 04            [12] 1564 	add	a,#0x04
      000564 F8               [12] 1565 	mov	r0,a
      000565 E4               [12] 1566 	clr	a
      000566 BD 02 01         [24] 1567 	cjne	r5,#0x02,00198$
      000569 04               [12] 1568 	inc	a
      00056A                       1569 00198$:
      00056A F6               [12] 1570 	mov	@r0,a
      00056B E5 08            [12] 1571 	mov	a,_bp
      00056D 24 0E            [12] 1572 	add	a,#0x0e
      00056F F8               [12] 1573 	mov	r0,a
      000570 76 01            [12] 1574 	mov	@r0,#0x01
      000572 08               [12] 1575 	inc	r0
      000573 76 00            [12] 1576 	mov	@r0,#0x00
      000575                       1577 00119$:
                           0004BE  1578 	C$fuzzy.h$884$2_0$43 ==.
                                   1579 ;	../../fuzzy.h:884: index < count;
      000575 E5 08            [12] 1580 	mov	a,_bp
      000577 24 0E            [12] 1581 	add	a,#0x0e
      000579 F8               [12] 1582 	mov	r0,a
      00057A E5 08            [12] 1583 	mov	a,_bp
      00057C 24 FC            [12] 1584 	add	a,#0xfc
      00057E F9               [12] 1585 	mov	r1,a
      00057F C3               [12] 1586 	clr	c
      000580 E6               [12] 1587 	mov	a,@r0
      000581 97               [12] 1588 	subb	a,@r1
      000582 08               [12] 1589 	inc	r0
      000583 E6               [12] 1590 	mov	a,@r0
      000584 09               [12] 1591 	inc	r1
      000585 97               [12] 1592 	subb	a,@r1
      000586 40 03            [24] 1593 	jc	00200$
      000588 02 07 6C         [24] 1594 	ljmp	00117$
      00058B                       1595 00200$:
                           0004D4  1596 	C$fuzzy.h$889$1_0$40 ==.
                                   1597 ;	../../fuzzy.h:889: args[index]
      00058B C0 02            [24] 1598 	push	ar2
      00058D E5 08            [12] 1599 	mov	a,_bp
      00058F 24 0E            [12] 1600 	add	a,#0x0e
      000591 F8               [12] 1601 	mov	r0,a
      000592 E6               [12] 1602 	mov	a,@r0
      000593 26               [12] 1603 	add	a,@r0
      000594 FD               [12] 1604 	mov	r5,a
      000595 08               [12] 1605 	inc	r0
      000596 E6               [12] 1606 	mov	a,@r0
      000597 33               [12] 1607 	rlc	a
      000598 FC               [12] 1608 	mov	r4,a
      000599 ED               [12] 1609 	mov	a,r5
      00059A 2D               [12] 1610 	add	a,r5
      00059B FD               [12] 1611 	mov	r5,a
      00059C EC               [12] 1612 	mov	a,r4
      00059D 33               [12] 1613 	rlc	a
      00059E FC               [12] 1614 	mov	r4,a
      00059F A8 08            [24] 1615 	mov	r0,_bp
      0005A1 08               [12] 1616 	inc	r0
      0005A2 ED               [12] 1617 	mov	a,r5
      0005A3 26               [12] 1618 	add	a, @r0
      0005A4 FA               [12] 1619 	mov	r2,a
      0005A5 EC               [12] 1620 	mov	a,r4
      0005A6 08               [12] 1621 	inc	r0
      0005A7 36               [12] 1622 	addc	a, @r0
      0005A8 FC               [12] 1623 	mov	r4,a
      0005A9 08               [12] 1624 	inc	r0
      0005AA 86 05            [24] 1625 	mov	ar5,@r0
      0005AC 8A 82            [24] 1626 	mov	dpl,r2
      0005AE 8C 83            [24] 1627 	mov	dph,r4
      0005B0 8D F0            [24] 1628 	mov	b,r5
      0005B2 12 26 66         [24] 1629 	lcall	__gptrget
      0005B5 FA               [12] 1630 	mov	r2,a
      0005B6 A3               [24] 1631 	inc	dptr
      0005B7 12 26 66         [24] 1632 	lcall	__gptrget
      0005BA FC               [12] 1633 	mov	r4,a
      0005BB A3               [24] 1634 	inc	dptr
      0005BC 12 26 66         [24] 1635 	lcall	__gptrget
      0005BF FD               [12] 1636 	mov	r5,a
      0005C0 A3               [24] 1637 	inc	dptr
      0005C1 12 26 66         [24] 1638 	lcall	__gptrget
      0005C4 8A 82            [24] 1639 	mov	dpl,r2
      0005C6 8C 83            [24] 1640 	mov	dph,r4
      0005C8 8D F0            [24] 1641 	mov	b,r5
      0005CA C0 02            [24] 1642 	push	ar2
      0005CC 12 00 EA         [24] 1643 	lcall	_fuzzy_clamp
      0005CF AC 82            [24] 1644 	mov	r4, dpl
      0005D1 AD 83            [24] 1645 	mov	r5, dph
      0005D3 AE F0            [24] 1646 	mov	r6, b
      0005D5 FB               [12] 1647 	mov	r3, a
      0005D6 D0 02            [24] 1648 	pop	ar2
                           000521  1649 	C$fuzzy.h$892$1_0$40 ==.
                                   1650 ;	../../fuzzy.h:892: switch (method) {
      0005D8 D0 02            [24] 1651 	pop	ar2
      0005DA E5 08            [12] 1652 	mov	a,_bp
      0005DC 24 05            [12] 1653 	add	a,#0x05
      0005DE F8               [12] 1654 	mov	r0,a
      0005DF E6               [12] 1655 	mov	a,@r0
      0005E0 70 11            [24] 1656 	jnz	00108$
      0005E2 EA               [12] 1657 	mov	a,r2
      0005E3 70 5D            [24] 1658 	jnz	00111$
      0005E5 E5 08            [12] 1659 	mov	a,_bp
      0005E7 24 04            [12] 1660 	add	a,#0x04
      0005E9 F8               [12] 1661 	mov	r0,a
      0005EA E6               [12] 1662 	mov	a,@r0
      0005EB 60 03            [24] 1663 	jz	00203$
      0005ED 02 06 E7         [24] 1664 	ljmp	00112$
      0005F0                       1665 00203$:
      0005F0 02 07 56         [24] 1666 	ljmp	00115$
                           00053C  1667 	C$fuzzy.h$893$4_0$45 ==.
                                   1668 ;	../../fuzzy.h:893: case FUZZY_LOGIC_STANDARD:
      0005F3                       1669 00108$:
                           00053C  1670 	C$fuzzy.h$894$1_0$40 ==.
                                   1671 ;	../../fuzzy.h:894: if (next > result) {
      0005F3 C0 06            [24] 1672 	push	ar6
      0005F5 C0 05            [24] 1673 	push	ar5
      0005F7 C0 04            [24] 1674 	push	ar4
      0005F9 C0 03            [24] 1675 	push	ar3
      0005FB C0 02            [24] 1676 	push	ar2
      0005FD C0 04            [24] 1677 	push	ar4
      0005FF C0 05            [24] 1678 	push	ar5
      000601 C0 06            [24] 1679 	push	ar6
      000603 C0 03            [24] 1680 	push	ar3
      000605 E5 08            [12] 1681 	mov	a,_bp
      000607 24 0A            [12] 1682 	add	a,#0x0a
      000609 F8               [12] 1683 	mov	r0,a
      00060A 86 82            [24] 1684 	mov	dpl, @r0
      00060C 08               [12] 1685 	inc	r0
      00060D 86 83            [24] 1686 	mov	dph, @r0
      00060F 08               [12] 1687 	inc	r0
      000610 86 F0            [24] 1688 	mov	b, @r0
      000612 08               [12] 1689 	inc	r0
      000613 E6               [12] 1690 	mov	a, @r0
      000614 12 24 3A         [24] 1691 	lcall	___fslt
      000617 AF 82            [24] 1692 	mov	r7, dpl
      000619 E5 81            [12] 1693 	mov	a,sp
      00061B 24 FC            [12] 1694 	add	a,#0xfc
      00061D F5 81            [12] 1695 	mov	sp,a
      00061F D0 02            [24] 1696 	pop	ar2
      000621 D0 03            [24] 1697 	pop	ar3
      000623 D0 04            [24] 1698 	pop	ar4
      000625 D0 05            [24] 1699 	pop	ar5
      000627 D0 06            [24] 1700 	pop	ar6
      000629 EF               [12] 1701 	mov	a,r7
      00062A 70 03            [24] 1702 	jnz	00204$
      00062C 02 07 5E         [24] 1703 	ljmp	00120$
      00062F                       1704 00204$:
                           000578  1705 	C$fuzzy.h$895$5_0$46 ==.
                                   1706 ;	../../fuzzy.h:895: result = next;
      00062F E5 08            [12] 1707 	mov	a,_bp
      000631 24 0A            [12] 1708 	add	a,#0x0a
      000633 F8               [12] 1709 	mov	r0,a
      000634 A6 04            [24] 1710 	mov	@r0,ar4
      000636 08               [12] 1711 	inc	r0
      000637 A6 05            [24] 1712 	mov	@r0,ar5
      000639 08               [12] 1713 	inc	r0
      00063A A6 06            [24] 1714 	mov	@r0,ar6
      00063C 08               [12] 1715 	inc	r0
      00063D A6 03            [24] 1716 	mov	@r0,ar3
                           000588  1717 	C$fuzzy.h$897$4_0$45 ==.
                                   1718 ;	../../fuzzy.h:897: break;
      00063F 02 07 5E         [24] 1719 	ljmp	00120$
                           00058B  1720 	C$fuzzy.h$899$4_0$45 ==.
                                   1721 ;	../../fuzzy.h:899: case FUZZY_LOGIC_ALGEBRAIC:
      000642                       1722 00111$:
                           00058B  1723 	C$fuzzy.h$902$1_0$40 ==.
                                   1724 ;	../../fuzzy.h:902: next -
      000642 C0 02            [24] 1725 	push	ar2
      000644 C0 06            [24] 1726 	push	ar6
      000646 C0 05            [24] 1727 	push	ar5
      000648 C0 04            [24] 1728 	push	ar4
      00064A C0 03            [24] 1729 	push	ar3
      00064C C0 02            [24] 1730 	push	ar2
      00064E C0 04            [24] 1731 	push	ar4
      000650 C0 05            [24] 1732 	push	ar5
      000652 C0 06            [24] 1733 	push	ar6
      000654 C0 03            [24] 1734 	push	ar3
                           00059F  1735 	C$fuzzy.h$903$1_0$40 ==.
                                   1736 ;	../../fuzzy.h:903: result * next;
      000656 E5 08            [12] 1737 	mov	a,_bp
      000658 24 0A            [12] 1738 	add	a,#0x0a
      00065A F8               [12] 1739 	mov	r0,a
      00065B 86 82            [24] 1740 	mov	dpl, @r0
      00065D 08               [12] 1741 	inc	r0
      00065E 86 83            [24] 1742 	mov	dph, @r0
      000660 08               [12] 1743 	inc	r0
      000661 86 F0            [24] 1744 	mov	b, @r0
      000663 08               [12] 1745 	inc	r0
      000664 E6               [12] 1746 	mov	a, @r0
      000665 12 24 8C         [24] 1747 	lcall	___fsadd
      000668 C8               [12] 1748 	xch	a,r0
      000669 E5 08            [12] 1749 	mov	a,_bp
      00066B 24 06            [12] 1750 	add	a,#0x06
      00066D C8               [12] 1751 	xch	a,r0
      00066E A6 82            [24] 1752 	mov	@r0, dpl
      000670 08               [12] 1753 	inc	r0
      000671 A6 83            [24] 1754 	mov	@r0, dph
      000673 08               [12] 1755 	inc	r0
      000674 A6 F0            [24] 1756 	mov	@r0, b
      000676 08               [12] 1757 	inc	r0
      000677 F6               [12] 1758 	mov	@r0,a
      000678 E5 81            [12] 1759 	mov	a,sp
      00067A 24 FC            [12] 1760 	add	a,#0xfc
      00067C F5 81            [12] 1761 	mov	sp,a
      00067E D0 02            [24] 1762 	pop	ar2
      000680 D0 03            [24] 1763 	pop	ar3
      000682 D0 04            [24] 1764 	pop	ar4
      000684 D0 05            [24] 1765 	pop	ar5
      000686 D0 06            [24] 1766 	pop	ar6
      000688 C0 04            [24] 1767 	push	ar4
      00068A C0 05            [24] 1768 	push	ar5
      00068C C0 06            [24] 1769 	push	ar6
      00068E C0 03            [24] 1770 	push	ar3
      000690 E5 08            [12] 1771 	mov	a,_bp
      000692 24 0A            [12] 1772 	add	a,#0x0a
      000694 F8               [12] 1773 	mov	r0,a
      000695 86 82            [24] 1774 	mov	dpl, @r0
      000697 08               [12] 1775 	inc	r0
      000698 86 83            [24] 1776 	mov	dph, @r0
      00069A 08               [12] 1777 	inc	r0
      00069B 86 F0            [24] 1778 	mov	b, @r0
      00069D 08               [12] 1779 	inc	r0
      00069E E6               [12] 1780 	mov	a, @r0
      00069F 12 23 0A         [24] 1781 	lcall	___fsmul
      0006A2 AA 82            [24] 1782 	mov	r2, dpl
      0006A4 AB 83            [24] 1783 	mov	r3, dph
      0006A6 AE F0            [24] 1784 	mov	r6, b
      0006A8 FF               [12] 1785 	mov	r7, a
      0006A9 E5 81            [12] 1786 	mov	a,sp
      0006AB 24 FC            [12] 1787 	add	a,#0xfc
      0006AD F5 81            [12] 1788 	mov	sp,a
      0006AF C0 02            [24] 1789 	push	ar2
      0006B1 C0 02            [24] 1790 	push	ar2
      0006B3 C0 03            [24] 1791 	push	ar3
      0006B5 C0 06            [24] 1792 	push	ar6
      0006B7 C0 07            [24] 1793 	push	ar7
                           000602  1794 	C$fuzzy.h$904$1_0$40 ==.
                                   1795 ;	../../fuzzy.h:904: break;
      0006B9 E5 08            [12] 1796 	mov	a,_bp
      0006BB 24 06            [12] 1797 	add	a,#0x06
      0006BD F8               [12] 1798 	mov	r0,a
      0006BE 86 82            [24] 1799 	mov	dpl, @r0
      0006C0 08               [12] 1800 	inc	r0
      0006C1 86 83            [24] 1801 	mov	dph, @r0
      0006C3 08               [12] 1802 	inc	r0
      0006C4 86 F0            [24] 1803 	mov	b, @r0
      0006C6 08               [12] 1804 	inc	r0
      0006C7 E6               [12] 1805 	mov	a, @r0
      0006C8 12 22 FF         [24] 1806 	lcall	___fssub
      0006CB C8               [12] 1807 	xch	a,r0
      0006CC E5 08            [12] 1808 	mov	a,_bp
      0006CE 24 0A            [12] 1809 	add	a,#0x0a
      0006D0 C8               [12] 1810 	xch	a,r0
      0006D1 A6 82            [24] 1811 	mov	@r0, dpl
      0006D3 08               [12] 1812 	inc	r0
      0006D4 A6 83            [24] 1813 	mov	@r0, dph
      0006D6 08               [12] 1814 	inc	r0
      0006D7 A6 F0            [24] 1815 	mov	@r0, b
      0006D9 08               [12] 1816 	inc	r0
      0006DA F6               [12] 1817 	mov	@r0,a
      0006DB E5 81            [12] 1818 	mov	a,sp
      0006DD 24 FC            [12] 1819 	add	a,#0xfc
      0006DF F5 81            [12] 1820 	mov	sp,a
      0006E1 D0 02            [24] 1821 	pop	ar2
      0006E3 D0 02            [24] 1822 	pop	ar2
                           00062E  1823 	C$fuzzy.h$906$4_0$45 ==.
                                   1824 ;	../../fuzzy.h:906: case FUZZY_LOGIC_BOUNDED:
      0006E5 80 77            [24] 1825 	sjmp	00120$
      0006E7                       1826 00112$:
                           000630  1827 	C$fuzzy.h$908$1_0$40 ==.
                                   1828 ;	../../fuzzy.h:908: next;
      0006E7 C0 02            [24] 1829 	push	ar2
      0006E9 C0 04            [24] 1830 	push	ar4
      0006EB C0 05            [24] 1831 	push	ar5
      0006ED C0 06            [24] 1832 	push	ar6
      0006EF C0 03            [24] 1833 	push	ar3
                           00063A  1834 	C$fuzzy.h$910$1_0$40 ==.
                                   1835 ;	../../fuzzy.h:910: if (result > LEVEL_HI) {
      0006F1 E5 08            [12] 1836 	mov	a,_bp
      0006F3 24 0A            [12] 1837 	add	a,#0x0a
      0006F5 F8               [12] 1838 	mov	r0,a
      0006F6 86 82            [24] 1839 	mov	dpl, @r0
      0006F8 08               [12] 1840 	inc	r0
      0006F9 86 83            [24] 1841 	mov	dph, @r0
      0006FB 08               [12] 1842 	inc	r0
      0006FC 86 F0            [24] 1843 	mov	b, @r0
      0006FE 08               [12] 1844 	inc	r0
      0006FF E6               [12] 1845 	mov	a, @r0
      000700 12 24 8C         [24] 1846 	lcall	___fsadd
      000703 C8               [12] 1847 	xch	a,r0
      000704 E5 08            [12] 1848 	mov	a,_bp
      000706 24 0A            [12] 1849 	add	a,#0x0a
      000708 C8               [12] 1850 	xch	a,r0
      000709 A6 82            [24] 1851 	mov	@r0, dpl
      00070B 08               [12] 1852 	inc	r0
      00070C A6 83            [24] 1853 	mov	@r0, dph
      00070E 08               [12] 1854 	inc	r0
      00070F A6 F0            [24] 1855 	mov	@r0, b
      000711 08               [12] 1856 	inc	r0
      000712 F6               [12] 1857 	mov	@r0,a
      000713 E5 81            [12] 1858 	mov	a,sp
      000715 24 FC            [12] 1859 	add	a,#0xfc
      000717 F5 81            [12] 1860 	mov	sp,a
      000719 E5 08            [12] 1861 	mov	a,_bp
      00071B 24 0A            [12] 1862 	add	a,#0x0a
      00071D F8               [12] 1863 	mov	r0,a
      00071E E6               [12] 1864 	mov	a,@r0
      00071F C0 E0            [24] 1865 	push	acc
      000721 08               [12] 1866 	inc	r0
      000722 E6               [12] 1867 	mov	a,@r0
      000723 C0 E0            [24] 1868 	push	acc
      000725 08               [12] 1869 	inc	r0
      000726 E6               [12] 1870 	mov	a,@r0
      000727 C0 E0            [24] 1871 	push	acc
      000729 08               [12] 1872 	inc	r0
      00072A E6               [12] 1873 	mov	a,@r0
      00072B C0 E0            [24] 1874 	push	acc
      00072D 90 00 00         [24] 1875 	mov	dptr,#0x0000
      000730 75 F0 80         [24] 1876 	mov	b, #0x80
      000733 74 3F            [12] 1877 	mov	a, #0x3f
      000735 12 24 3A         [24] 1878 	lcall	___fslt
      000738 AF 82            [24] 1879 	mov	r7, dpl
      00073A E5 81            [12] 1880 	mov	a,sp
      00073C 24 FC            [12] 1881 	add	a,#0xfc
      00073E F5 81            [12] 1882 	mov	sp,a
      000740 D0 02            [24] 1883 	pop	ar2
      000742 EF               [12] 1884 	mov	a,r7
      000743 60 19            [24] 1885 	jz	00120$
                           00068E  1886 	C$fuzzy.h$911$5_0$47 ==.
                                   1887 ;	../../fuzzy.h:911: result = LEVEL_HI;
      000745 E5 08            [12] 1888 	mov	a,_bp
      000747 24 0A            [12] 1889 	add	a,#0x0a
      000749 F8               [12] 1890 	mov	r0,a
      00074A E4               [12] 1891 	clr	a
      00074B F6               [12] 1892 	mov	@r0,a
      00074C 08               [12] 1893 	inc	r0
      00074D F6               [12] 1894 	mov	@r0,a
      00074E 08               [12] 1895 	inc	r0
      00074F 76 80            [12] 1896 	mov	@r0,#0x80
      000751 08               [12] 1897 	inc	r0
      000752 76 3F            [12] 1898 	mov	@r0,#0x3f
                           00069D  1899 	C$fuzzy.h$913$4_0$45 ==.
                                   1900 ;	../../fuzzy.h:913: break;
                           00069D  1901 	C$fuzzy.h$915$4_0$45 ==.
                                   1902 ;	../../fuzzy.h:915: default:
      000754 80 08            [24] 1903 	sjmp	00120$
      000756                       1904 00115$:
                           00069F  1905 	C$fuzzy.h$916$4_0$45 ==.
                                   1906 ;	../../fuzzy.h:916: return LEVEL_LO;
      000756 90 00 00         [24] 1907 	mov	dptr,#0x0000
      000759 E4               [12] 1908 	clr	a
      00075A F5 F0            [12] 1909 	mov	b,a
                           0006A5  1910 	C$fuzzy.h$917$3_0$44 ==.
                                   1911 ;	../../fuzzy.h:917: }
      00075C 80 20            [24] 1912 	sjmp	00121$
      00075E                       1913 00120$:
                           0006A7  1914 	C$fuzzy.h$885$2_0$43 ==.
                                   1915 ;	../../fuzzy.h:885: index++
      00075E E5 08            [12] 1916 	mov	a,_bp
      000760 24 0E            [12] 1917 	add	a,#0x0e
      000762 F8               [12] 1918 	mov	r0,a
      000763 06               [12] 1919 	inc	@r0
      000764 B6 00 02         [24] 1920 	cjne	@r0,#0x00,00206$
      000767 08               [12] 1921 	inc	r0
      000768 06               [12] 1922 	inc	@r0
      000769                       1923 00206$:
      000769 02 05 75         [24] 1924 	ljmp	00119$
      00076C                       1925 00117$:
                           0006B5  1926 	C$fuzzy.h$921$1_0$40 ==.
                                   1927 ;	../../fuzzy.h:921: result
      00076C E5 08            [12] 1928 	mov	a,_bp
      00076E 24 0A            [12] 1929 	add	a,#0x0a
      000770 F8               [12] 1930 	mov	r0,a
      000771 86 82            [24] 1931 	mov	dpl, @r0
      000773 08               [12] 1932 	inc	r0
      000774 86 83            [24] 1933 	mov	dph, @r0
      000776 08               [12] 1934 	inc	r0
      000777 86 F0            [24] 1935 	mov	b, @r0
      000779 08               [12] 1936 	inc	r0
      00077A E6               [12] 1937 	mov	a, @r0
      00077B 12 00 EA         [24] 1938 	lcall	_fuzzy_clamp
      00077E                       1939 00121$:
                           0006C7  1940 	C$fuzzy.h$923$1_0$40 ==.
                                   1941 ;	../../fuzzy.h:923: }
      00077E 85 08 81         [24] 1942 	mov	sp,_bp
      000781 D0 08            [24] 1943 	pop	_bp
                           0006CC  1944 	C$fuzzy.h$923$1_0$40 ==.
                           0006CC  1945 	XG$fuzzy_or_array$0$0 ==.
      000783 22               [24] 1946 	ret
                                   1947 ;------------------------------------------------------------
                                   1948 ;Allocation info for local variables in function 'fuzzy_sugeno_weighted_average_array'
                                   1949 ;------------------------------------------------------------
                                   1950 ;values        Allocated to stack - _bp -5 +3 
                                   1951 ;value_count   Allocated to stack - _bp +1 +2 
                                   1952 ;weighted_sum  Allocated to stack - _bp +3 +4 
                                   1953 ;firing_sum    Allocated to stack - _bp +7 +4 
                                   1954 ;firing_strength Allocated to stack - _bp +11 +4 
                                   1955 ;consequent    Allocated to registers r4 r5 r3 r2 
                                   1956 ;index         Allocated to registers r6 r7 
                                   1957 ;------------------------------------------------------------
                           0006CD  1958 	G$fuzzy_sugeno_weighted_average_array$0$0 ==.
                           0006CD  1959 	C$fuzzy.h$934$1_0$49 ==.
                                   1960 ;	../../fuzzy.h:934: float fuzzy_sugeno_weighted_average_array(
                                   1961 ;	-----------------------------------------
                                   1962 ;	 function fuzzy_sugeno_weighted_average_array
                                   1963 ;	-----------------------------------------
      000784                       1964 _fuzzy_sugeno_weighted_average_array:
      000784 C0 08            [24] 1965 	push	_bp
      000786 85 81 08         [24] 1966 	mov	_bp,sp
      000789 C0 82            [24] 1967 	push	dpl
      00078B C0 83            [24] 1968 	push	dph
      00078D E5 81            [12] 1969 	mov	a,sp
      00078F 24 0C            [12] 1970 	add	a,#0x0c
      000791 F5 81            [12] 1971 	mov	sp,a
                           0006DC  1972 	C$fuzzy.h$947$1_0$49 ==.
                                   1973 ;	../../fuzzy.h:947: values == NULL ||
      000793 E5 08            [12] 1974 	mov	a,_bp
      000795 24 FB            [12] 1975 	add	a,#0xfb
      000797 F8               [12] 1976 	mov	r0,a
      000798 E6               [12] 1977 	mov	a,@r0
      000799 08               [12] 1978 	inc	r0
      00079A 46               [12] 1979 	orl	a,@r0
      00079B 60 0F            [24] 1980 	jz	00101$
                           0006E6  1981 	C$fuzzy.h$948$1_0$49 ==.
                                   1982 ;	../../fuzzy.h:948: value_count == 0u ||
      00079D A8 08            [24] 1983 	mov	r0,_bp
      00079F 08               [12] 1984 	inc	r0
      0007A0 E6               [12] 1985 	mov	a,@r0
      0007A1 08               [12] 1986 	inc	r0
      0007A2 46               [12] 1987 	orl	a,@r0
      0007A3 60 07            [24] 1988 	jz	00101$
                           0006EE  1989 	C$fuzzy.h$949$1_0$49 ==.
                                   1990 ;	../../fuzzy.h:949: value_count % 2u != 0u
      0007A5 A8 08            [24] 1991 	mov	r0,_bp
      0007A7 08               [12] 1992 	inc	r0
      0007A8 E6               [12] 1993 	mov	a,@r0
      0007A9 30 E0 09         [24] 1994 	jnb	acc.0,00102$
      0007AC                       1995 00101$:
                           0006F5  1996 	C$fuzzy.h$951$2_0$50 ==.
                                   1997 ;	../../fuzzy.h:951: return 0.0f;
      0007AC 90 00 00         [24] 1998 	mov	dptr,#0x0000
      0007AF E4               [12] 1999 	clr	a
      0007B0 F5 F0            [12] 2000 	mov	b,a
      0007B2 02 09 7F         [24] 2001 	ljmp	00111$
      0007B5                       2002 00102$:
                           0006FE  2003 	C$fuzzy.h$955$1_0$49 ==.
                                   2004 ;	../../fuzzy.h:955: 0.0f;
      0007B5 E5 08            [12] 2005 	mov	a,_bp
      0007B7 24 03            [12] 2006 	add	a,#0x03
      0007B9 F8               [12] 2007 	mov	r0,a
      0007BA E4               [12] 2008 	clr	a
      0007BB F6               [12] 2009 	mov	@r0,a
      0007BC 08               [12] 2010 	inc	r0
      0007BD F6               [12] 2011 	mov	@r0,a
      0007BE 08               [12] 2012 	inc	r0
      0007BF F6               [12] 2013 	mov	@r0,a
      0007C0 08               [12] 2014 	inc	r0
      0007C1 F6               [12] 2015 	mov	@r0,a
                           00070B  2016 	C$fuzzy.h$958$1_0$49 ==.
                                   2017 ;	../../fuzzy.h:958: 0.0f;
      0007C2 E5 08            [12] 2018 	mov	a,_bp
      0007C4 24 07            [12] 2019 	add	a,#0x07
      0007C6 F8               [12] 2020 	mov	r0,a
      0007C7 E4               [12] 2021 	clr	a
      0007C8 F6               [12] 2022 	mov	@r0,a
      0007C9 08               [12] 2023 	inc	r0
      0007CA F6               [12] 2024 	mov	@r0,a
      0007CB 08               [12] 2025 	inc	r0
      0007CC F6               [12] 2026 	mov	@r0,a
      0007CD 08               [12] 2027 	inc	r0
      0007CE F6               [12] 2028 	mov	@r0,a
                           000718  2029 	C$fuzzy.h$961$1_0$49 ==.
                                   2030 ;	../../fuzzy.h:961: index = 0u;
      0007CF FE               [12] 2031 	mov	r6,a
      0007D0 FF               [12] 2032 	mov	r7,a
      0007D1                       2033 00109$:
                           00071A  2034 	C$fuzzy.h$962$2_0$51 ==.
                                   2035 ;	../../fuzzy.h:962: index < value_count;
      0007D1 A8 08            [24] 2036 	mov	r0,_bp
      0007D3 08               [12] 2037 	inc	r0
      0007D4 C3               [12] 2038 	clr	c
      0007D5 EE               [12] 2039 	mov	a,r6
      0007D6 96               [12] 2040 	subb	a,@r0
      0007D7 EF               [12] 2041 	mov	a,r7
      0007D8 08               [12] 2042 	inc	r0
      0007D9 96               [12] 2043 	subb	a,@r0
      0007DA 40 03            [24] 2044 	jc	00147$
      0007DC 02 09 12         [24] 2045 	ljmp	00105$
      0007DF                       2046 00147$:
                           000728  2047 	C$fuzzy.h$967$3_0$52 ==.
                                   2048 ;	../../fuzzy.h:967: values[index]
      0007DF EE               [12] 2049 	mov	a,r6
      0007E0 2E               [12] 2050 	add	a,r6
      0007E1 FC               [12] 2051 	mov	r4,a
      0007E2 EF               [12] 2052 	mov	a,r7
      0007E3 33               [12] 2053 	rlc	a
      0007E4 FD               [12] 2054 	mov	r5,a
      0007E5 EC               [12] 2055 	mov	a,r4
      0007E6 2C               [12] 2056 	add	a,r4
      0007E7 FC               [12] 2057 	mov	r4,a
      0007E8 ED               [12] 2058 	mov	a,r5
      0007E9 33               [12] 2059 	rlc	a
      0007EA FD               [12] 2060 	mov	r5,a
      0007EB E5 08            [12] 2061 	mov	a,_bp
      0007ED 24 FB            [12] 2062 	add	a,#0xfb
      0007EF F8               [12] 2063 	mov	r0,a
      0007F0 EC               [12] 2064 	mov	a,r4
      0007F1 26               [12] 2065 	add	a, @r0
      0007F2 FC               [12] 2066 	mov	r4,a
      0007F3 ED               [12] 2067 	mov	a,r5
      0007F4 08               [12] 2068 	inc	r0
      0007F5 36               [12] 2069 	addc	a, @r0
      0007F6 FD               [12] 2070 	mov	r5,a
      0007F7 08               [12] 2071 	inc	r0
      0007F8 86 03            [24] 2072 	mov	ar3,@r0
      0007FA 8C 82            [24] 2073 	mov	dpl,r4
      0007FC 8D 83            [24] 2074 	mov	dph,r5
      0007FE 8B F0            [24] 2075 	mov	b,r3
      000800 12 26 66         [24] 2076 	lcall	__gptrget
      000803 FC               [12] 2077 	mov	r4,a
      000804 A3               [24] 2078 	inc	dptr
      000805 12 26 66         [24] 2079 	lcall	__gptrget
      000808 FD               [12] 2080 	mov	r5,a
      000809 A3               [24] 2081 	inc	dptr
      00080A 12 26 66         [24] 2082 	lcall	__gptrget
      00080D FB               [12] 2083 	mov	r3,a
      00080E A3               [24] 2084 	inc	dptr
      00080F 12 26 66         [24] 2085 	lcall	__gptrget
      000812 8C 82            [24] 2086 	mov	dpl,r4
      000814 8D 83            [24] 2087 	mov	dph,r5
      000816 8B F0            [24] 2088 	mov	b,r3
      000818 C0 07            [24] 2089 	push	ar7
      00081A C0 06            [24] 2090 	push	ar6
      00081C 12 00 EA         [24] 2091 	lcall	_fuzzy_clamp
      00081F C8               [12] 2092 	xch	a,r0
      000820 E5 08            [12] 2093 	mov	a,_bp
      000822 24 0B            [12] 2094 	add	a,#0x0b
      000824 C8               [12] 2095 	xch	a,r0
      000825 A6 82            [24] 2096 	mov	@r0, dpl
      000827 08               [12] 2097 	inc	r0
      000828 A6 83            [24] 2098 	mov	@r0, dph
      00082A 08               [12] 2099 	inc	r0
      00082B A6 F0            [24] 2100 	mov	@r0, b
      00082D 08               [12] 2101 	inc	r0
      00082E F6               [12] 2102 	mov	@r0,a
      00082F D0 06            [24] 2103 	pop	ar6
      000831 D0 07            [24] 2104 	pop	ar7
                           00077C  2105 	C$fuzzy.h$971$3_0$52 ==.
                                   2106 ;	../../fuzzy.h:971: values[index + 1u];
      000833 74 01            [12] 2107 	mov	a,#0x01
      000835 2E               [12] 2108 	add	a, r6
      000836 FC               [12] 2109 	mov	r4,a
      000837 E4               [12] 2110 	clr	a
      000838 3F               [12] 2111 	addc	a, r7
      000839 FD               [12] 2112 	mov	r5,a
      00083A EC               [12] 2113 	mov	a,r4
      00083B 2C               [12] 2114 	add	a,r4
      00083C FC               [12] 2115 	mov	r4,a
      00083D ED               [12] 2116 	mov	a,r5
      00083E 33               [12] 2117 	rlc	a
      00083F FD               [12] 2118 	mov	r5,a
      000840 EC               [12] 2119 	mov	a,r4
      000841 2C               [12] 2120 	add	a,r4
      000842 FC               [12] 2121 	mov	r4,a
      000843 ED               [12] 2122 	mov	a,r5
      000844 33               [12] 2123 	rlc	a
      000845 FD               [12] 2124 	mov	r5,a
      000846 E5 08            [12] 2125 	mov	a,_bp
      000848 24 FB            [12] 2126 	add	a,#0xfb
      00084A F8               [12] 2127 	mov	r0,a
      00084B EC               [12] 2128 	mov	a,r4
      00084C 26               [12] 2129 	add	a, @r0
      00084D FC               [12] 2130 	mov	r4,a
      00084E ED               [12] 2131 	mov	a,r5
      00084F 08               [12] 2132 	inc	r0
      000850 36               [12] 2133 	addc	a, @r0
      000851 FD               [12] 2134 	mov	r5,a
      000852 08               [12] 2135 	inc	r0
      000853 86 03            [24] 2136 	mov	ar3,@r0
      000855 8C 82            [24] 2137 	mov	dpl,r4
      000857 8D 83            [24] 2138 	mov	dph,r5
      000859 8B F0            [24] 2139 	mov	b,r3
      00085B 12 26 66         [24] 2140 	lcall	__gptrget
      00085E FC               [12] 2141 	mov	r4,a
      00085F A3               [24] 2142 	inc	dptr
      000860 12 26 66         [24] 2143 	lcall	__gptrget
      000863 FD               [12] 2144 	mov	r5,a
      000864 A3               [24] 2145 	inc	dptr
      000865 12 26 66         [24] 2146 	lcall	__gptrget
      000868 FB               [12] 2147 	mov	r3,a
      000869 A3               [24] 2148 	inc	dptr
      00086A 12 26 66         [24] 2149 	lcall	__gptrget
      00086D FA               [12] 2150 	mov	r2,a
                           0007B7  2151 	C$fuzzy.h$976$1_0$49 ==.
                                   2152 ;	../../fuzzy.h:976: consequent;
      00086E C0 07            [24] 2153 	push	ar7
      000870 C0 06            [24] 2154 	push	ar6
      000872 C0 04            [24] 2155 	push	ar4
      000874 C0 05            [24] 2156 	push	ar5
      000876 C0 03            [24] 2157 	push	ar3
      000878 C0 02            [24] 2158 	push	ar2
      00087A E5 08            [12] 2159 	mov	a,_bp
      00087C 24 0B            [12] 2160 	add	a,#0x0b
      00087E F8               [12] 2161 	mov	r0,a
      00087F 86 82            [24] 2162 	mov	dpl, @r0
      000881 08               [12] 2163 	inc	r0
      000882 86 83            [24] 2164 	mov	dph, @r0
      000884 08               [12] 2165 	inc	r0
      000885 86 F0            [24] 2166 	mov	b, @r0
      000887 08               [12] 2167 	inc	r0
      000888 E6               [12] 2168 	mov	a, @r0
      000889 12 23 0A         [24] 2169 	lcall	___fsmul
      00088C AA 82            [24] 2170 	mov	r2, dpl
      00088E AB 83            [24] 2171 	mov	r3, dph
      000890 AC F0            [24] 2172 	mov	r4, b
      000892 FD               [12] 2173 	mov	r5, a
      000893 E5 81            [12] 2174 	mov	a,sp
      000895 24 FC            [12] 2175 	add	a,#0xfc
      000897 F5 81            [12] 2176 	mov	sp,a
      000899 C0 02            [24] 2177 	push	ar2
      00089B C0 03            [24] 2178 	push	ar3
      00089D C0 04            [24] 2179 	push	ar4
      00089F C0 05            [24] 2180 	push	ar5
                           0007EA  2181 	C$fuzzy.h$979$1_0$49 ==.
                                   2182 ;	../../fuzzy.h:979: firing_strength;
      0008A1 E5 08            [12] 2183 	mov	a,_bp
      0008A3 24 03            [12] 2184 	add	a,#0x03
      0008A5 F8               [12] 2185 	mov	r0,a
      0008A6 86 82            [24] 2186 	mov	dpl, @r0
      0008A8 08               [12] 2187 	inc	r0
      0008A9 86 83            [24] 2188 	mov	dph, @r0
      0008AB 08               [12] 2189 	inc	r0
      0008AC 86 F0            [24] 2190 	mov	b, @r0
      0008AE 08               [12] 2191 	inc	r0
      0008AF E6               [12] 2192 	mov	a, @r0
      0008B0 12 24 8C         [24] 2193 	lcall	___fsadd
      0008B3 A8 08            [24] 2194 	mov	r0,_bp
      0008B5 08               [12] 2195 	inc	r0
      0008B6 08               [12] 2196 	inc	r0
      0008B7 08               [12] 2197 	inc	r0
      0008B8 A6 82            [24] 2198 	mov	@r0, dpl
      0008BA 08               [12] 2199 	inc	r0
      0008BB A6 83            [24] 2200 	mov	@r0, dph
      0008BD 08               [12] 2201 	inc	r0
      0008BE A6 F0            [24] 2202 	mov	@r0, b
      0008C0 08               [12] 2203 	inc	r0
      0008C1 F6               [12] 2204 	mov	@r0,a
      0008C2 E5 81            [12] 2205 	mov	a,sp
      0008C4 24 FC            [12] 2206 	add	a,#0xfc
      0008C6 F5 81            [12] 2207 	mov	sp,a
      0008C8 E5 08            [12] 2208 	mov	a,_bp
      0008CA 24 0B            [12] 2209 	add	a,#0x0b
      0008CC F8               [12] 2210 	mov	r0,a
      0008CD E6               [12] 2211 	mov	a,@r0
      0008CE C0 E0            [24] 2212 	push	acc
      0008D0 08               [12] 2213 	inc	r0
      0008D1 E6               [12] 2214 	mov	a,@r0
      0008D2 C0 E0            [24] 2215 	push	acc
      0008D4 08               [12] 2216 	inc	r0
      0008D5 E6               [12] 2217 	mov	a,@r0
      0008D6 C0 E0            [24] 2218 	push	acc
      0008D8 08               [12] 2219 	inc	r0
      0008D9 E6               [12] 2220 	mov	a,@r0
      0008DA C0 E0            [24] 2221 	push	acc
                           000825  2222 	C$fuzzy.h$964$1_0$49 ==.
                                   2223 ;	../../fuzzy.h:964: ) {
      0008DC E5 08            [12] 2224 	mov	a,_bp
      0008DE 24 07            [12] 2225 	add	a,#0x07
      0008E0 F8               [12] 2226 	mov	r0,a
      0008E1 86 82            [24] 2227 	mov	dpl, @r0
      0008E3 08               [12] 2228 	inc	r0
      0008E4 86 83            [24] 2229 	mov	dph, @r0
      0008E6 08               [12] 2230 	inc	r0
      0008E7 86 F0            [24] 2231 	mov	b, @r0
      0008E9 08               [12] 2232 	inc	r0
      0008EA E6               [12] 2233 	mov	a, @r0
      0008EB 12 24 8C         [24] 2234 	lcall	___fsadd
      0008EE C8               [12] 2235 	xch	a,r0
      0008EF E5 08            [12] 2236 	mov	a,_bp
      0008F1 24 07            [12] 2237 	add	a,#0x07
      0008F3 C8               [12] 2238 	xch	a,r0
      0008F4 A6 82            [24] 2239 	mov	@r0, dpl
      0008F6 08               [12] 2240 	inc	r0
      0008F7 A6 83            [24] 2241 	mov	@r0, dph
      0008F9 08               [12] 2242 	inc	r0
      0008FA A6 F0            [24] 2243 	mov	@r0, b
      0008FC 08               [12] 2244 	inc	r0
      0008FD F6               [12] 2245 	mov	@r0,a
      0008FE E5 81            [12] 2246 	mov	a,sp
      000900 24 FC            [12] 2247 	add	a,#0xfc
      000902 F5 81            [12] 2248 	mov	sp,a
      000904 D0 06            [24] 2249 	pop	ar6
      000906 D0 07            [24] 2250 	pop	ar7
      000908 74 02            [12] 2251 	mov	a,#0x02
      00090A 2E               [12] 2252 	add	a, r6
      00090B FE               [12] 2253 	mov	r6,a
      00090C E4               [12] 2254 	clr	a
      00090D 3F               [12] 2255 	addc	a, r7
      00090E FF               [12] 2256 	mov	r7,a
      00090F 02 07 D1         [24] 2257 	ljmp	00109$
      000912                       2258 00105$:
                           00085B  2259 	C$fuzzy.h$982$1_0$49 ==.
                                   2260 ;	../../fuzzy.h:982: if (firing_sum <= LEVEL_LO) {
      000912 E5 08            [12] 2261 	mov	a,_bp
      000914 24 07            [12] 2262 	add	a,#0x07
      000916 F8               [12] 2263 	mov	r0,a
      000917 E6               [12] 2264 	mov	a,@r0
      000918 C0 E0            [24] 2265 	push	acc
      00091A 08               [12] 2266 	inc	r0
      00091B E6               [12] 2267 	mov	a,@r0
      00091C C0 E0            [24] 2268 	push	acc
      00091E 08               [12] 2269 	inc	r0
      00091F E6               [12] 2270 	mov	a,@r0
      000920 C0 E0            [24] 2271 	push	acc
      000922 08               [12] 2272 	inc	r0
      000923 E6               [12] 2273 	mov	a,@r0
      000924 C0 E0            [24] 2274 	push	acc
      000926 90 00 00         [24] 2275 	mov	dptr,#0x0000
      000929 E4               [12] 2276 	clr	a
      00092A F5 F0            [12] 2277 	mov	b,a
      00092C 12 24 3A         [24] 2278 	lcall	___fslt
      00092F E5 81            [12] 2279 	mov	a,sp
      000931 24 FC            [12] 2280 	add	a,#0xfc
      000933 F5 81            [12] 2281 	mov	sp,a
      000935 E5 82            [12] 2282 	mov	a, dpl
      000937 24 FF            [12] 2283 	add	a,#0xff
      000939 92 00            [24] 2284 	mov	b0,c
      00093B 40 08            [24] 2285 	jc	00107$
                           000886  2286 	C$fuzzy.h$983$2_0$53 ==.
                                   2287 ;	../../fuzzy.h:983: return 0.0f;
      00093D 90 00 00         [24] 2288 	mov	dptr,#0x0000
      000940 E4               [12] 2289 	clr	a
      000941 F5 F0            [12] 2290 	mov	b,a
      000943 80 3A            [24] 2291 	sjmp	00111$
      000945                       2292 00107$:
                           00088E  2293 	C$fuzzy.h$987$1_0$49 ==.
                                   2294 ;	../../fuzzy.h:987: firing_sum;
      000945 E5 08            [12] 2295 	mov	a,_bp
      000947 24 07            [12] 2296 	add	a,#0x07
      000949 F8               [12] 2297 	mov	r0,a
      00094A E6               [12] 2298 	mov	a,@r0
      00094B C0 E0            [24] 2299 	push	acc
      00094D 08               [12] 2300 	inc	r0
      00094E E6               [12] 2301 	mov	a,@r0
      00094F C0 E0            [24] 2302 	push	acc
      000951 08               [12] 2303 	inc	r0
      000952 E6               [12] 2304 	mov	a,@r0
      000953 C0 E0            [24] 2305 	push	acc
      000955 08               [12] 2306 	inc	r0
      000956 E6               [12] 2307 	mov	a,@r0
      000957 C0 E0            [24] 2308 	push	acc
      000959 E5 08            [12] 2309 	mov	a,_bp
      00095B 24 03            [12] 2310 	add	a,#0x03
      00095D F8               [12] 2311 	mov	r0,a
      00095E 86 82            [24] 2312 	mov	dpl, @r0
      000960 08               [12] 2313 	inc	r0
      000961 86 83            [24] 2314 	mov	dph, @r0
      000963 08               [12] 2315 	inc	r0
      000964 86 F0            [24] 2316 	mov	b, @r0
      000966 08               [12] 2317 	inc	r0
      000967 E6               [12] 2318 	mov	a, @r0
      000968 12 25 A3         [24] 2319 	lcall	___fsdiv
      00096B AC 82            [24] 2320 	mov	r4, dpl
      00096D AD 83            [24] 2321 	mov	r5, dph
      00096F AE F0            [24] 2322 	mov	r6, b
      000971 FF               [12] 2323 	mov	r7, a
      000972 E5 81            [12] 2324 	mov	a,sp
      000974 24 FC            [12] 2325 	add	a,#0xfc
      000976 F5 81            [12] 2326 	mov	sp,a
      000978 8C 82            [24] 2327 	mov	dpl, r4
      00097A 8D 83            [24] 2328 	mov	dph, r5
      00097C 8E F0            [24] 2329 	mov	b, r6
      00097E EF               [12] 2330 	mov	a, r7
      00097F                       2331 00111$:
                           0008C8  2332 	C$fuzzy.h$988$1_0$49 ==.
                                   2333 ;	../../fuzzy.h:988: }
      00097F 85 08 81         [24] 2334 	mov	sp,_bp
      000982 D0 08            [24] 2335 	pop	_bp
                           0008CD  2336 	C$fuzzy.h$988$1_0$49 ==.
                           0008CD  2337 	XG$fuzzy_sugeno_weighted_average_array$0$0 ==.
      000984 22               [24] 2338 	ret
                                   2339 ;------------------------------------------------------------
                                   2340 ;Allocation info for local variables in function 'fuzzy_sugeno_weighted_sum_array'
                                   2341 ;------------------------------------------------------------
                                   2342 ;values        Allocated to stack - _bp -5 +3 
                                   2343 ;value_count   Allocated to registers r6 r7 
                                   2344 ;weighted_sum  Allocated to stack - _bp +1 +4 
                                   2345 ;firing_strength Allocated to stack - _bp +5 +4 
                                   2346 ;consequent    Allocated to registers r6 r7 r3 r2 
                                   2347 ;index         Allocated to registers r4 r5 
                                   2348 ;------------------------------------------------------------
                           0008CE  2349 	G$fuzzy_sugeno_weighted_sum_array$0$0 ==.
                           0008CE  2350 	C$fuzzy.h$998$1_0$55 ==.
                                   2351 ;	../../fuzzy.h:998: float fuzzy_sugeno_weighted_sum_array(
                                   2352 ;	-----------------------------------------
                                   2353 ;	 function fuzzy_sugeno_weighted_sum_array
                                   2354 ;	-----------------------------------------
      000985                       2355 _fuzzy_sugeno_weighted_sum_array:
      000985 C0 08            [24] 2356 	push	_bp
      000987 E5 81            [12] 2357 	mov	a,sp
      000989 F5 08            [12] 2358 	mov	_bp,a
      00098B 24 08            [12] 2359 	add	a,#0x08
      00098D F5 81            [12] 2360 	mov	sp,a
      00098F AE 82            [24] 2361 	mov	r6, dpl
      000991 AF 83            [24] 2362 	mov	r7, dph
                           0008DC  2363 	C$fuzzy.h$1010$1_0$55 ==.
                                   2364 ;	../../fuzzy.h:1010: values == NULL ||
      000993 E5 08            [12] 2365 	mov	a,_bp
      000995 24 FB            [12] 2366 	add	a,#0xfb
      000997 F8               [12] 2367 	mov	r0,a
      000998 E6               [12] 2368 	mov	a,@r0
      000999 08               [12] 2369 	inc	r0
      00099A 46               [12] 2370 	orl	a,@r0
      00099B 60 08            [24] 2371 	jz	00101$
                           0008E6  2372 	C$fuzzy.h$1011$1_0$55 ==.
                                   2373 ;	../../fuzzy.h:1011: value_count == 0u ||
      00099D EE               [12] 2374 	mov	a,r6
      00099E 4F               [12] 2375 	orl	a,r7
      00099F 60 04            [24] 2376 	jz	00101$
                           0008EA  2377 	C$fuzzy.h$1012$1_0$55 ==.
                                   2378 ;	../../fuzzy.h:1012: value_count % 2u != 0u
      0009A1 EE               [12] 2379 	mov	a,r6
      0009A2 30 E0 09         [24] 2380 	jnb	acc.0,00102$
      0009A5                       2381 00101$:
                           0008EE  2382 	C$fuzzy.h$1014$2_0$56 ==.
                                   2383 ;	../../fuzzy.h:1014: return 0.0f;
      0009A5 90 00 00         [24] 2384 	mov	dptr,#0x0000
      0009A8 E4               [12] 2385 	clr	a
      0009A9 F5 F0            [12] 2386 	mov	b,a
      0009AB 02 0A E6         [24] 2387 	ljmp	00109$
      0009AE                       2388 00102$:
                           0008F7  2389 	C$fuzzy.h$1018$1_0$55 ==.
                                   2390 ;	../../fuzzy.h:1018: 0.0f;
      0009AE A8 08            [24] 2391 	mov	r0,_bp
      0009B0 08               [12] 2392 	inc	r0
      0009B1 E4               [12] 2393 	clr	a
      0009B2 F6               [12] 2394 	mov	@r0,a
      0009B3 08               [12] 2395 	inc	r0
      0009B4 F6               [12] 2396 	mov	@r0,a
      0009B5 08               [12] 2397 	inc	r0
      0009B6 F6               [12] 2398 	mov	@r0,a
      0009B7 08               [12] 2399 	inc	r0
      0009B8 F6               [12] 2400 	mov	@r0,a
                           000902  2401 	C$fuzzy.h$1021$1_0$55 ==.
                                   2402 ;	../../fuzzy.h:1021: index = 0u;
      0009B9 FC               [12] 2403 	mov	r4,a
      0009BA FD               [12] 2404 	mov	r5,a
      0009BB                       2405 00107$:
                           000904  2406 	C$fuzzy.h$1022$2_0$57 ==.
                                   2407 ;	../../fuzzy.h:1022: index < value_count;
      0009BB C3               [12] 2408 	clr	c
      0009BC EC               [12] 2409 	mov	a,r4
      0009BD 9E               [12] 2410 	subb	a,r6
      0009BE ED               [12] 2411 	mov	a,r5
      0009BF 9F               [12] 2412 	subb	a,r7
      0009C0 40 03            [24] 2413 	jc	00139$
      0009C2 02 0A D9         [24] 2414 	ljmp	00105$
      0009C5                       2415 00139$:
                           00090E  2416 	C$fuzzy.h$1027$1_0$55 ==.
                                   2417 ;	../../fuzzy.h:1027: values[index]
      0009C5 C0 06            [24] 2418 	push	ar6
      0009C7 C0 07            [24] 2419 	push	ar7
      0009C9 EC               [12] 2420 	mov	a,r4
      0009CA 2C               [12] 2421 	add	a,r4
      0009CB FA               [12] 2422 	mov	r2,a
      0009CC ED               [12] 2423 	mov	a,r5
      0009CD 33               [12] 2424 	rlc	a
      0009CE FB               [12] 2425 	mov	r3,a
      0009CF EA               [12] 2426 	mov	a,r2
      0009D0 2A               [12] 2427 	add	a,r2
      0009D1 FA               [12] 2428 	mov	r2,a
      0009D2 EB               [12] 2429 	mov	a,r3
      0009D3 33               [12] 2430 	rlc	a
      0009D4 FB               [12] 2431 	mov	r3,a
      0009D5 E5 08            [12] 2432 	mov	a,_bp
      0009D7 24 FB            [12] 2433 	add	a,#0xfb
      0009D9 F8               [12] 2434 	mov	r0,a
      0009DA EA               [12] 2435 	mov	a,r2
      0009DB 26               [12] 2436 	add	a, @r0
      0009DC FA               [12] 2437 	mov	r2,a
      0009DD EB               [12] 2438 	mov	a,r3
      0009DE 08               [12] 2439 	inc	r0
      0009DF 36               [12] 2440 	addc	a, @r0
      0009E0 FB               [12] 2441 	mov	r3,a
      0009E1 08               [12] 2442 	inc	r0
      0009E2 86 07            [24] 2443 	mov	ar7,@r0
      0009E4 8A 82            [24] 2444 	mov	dpl,r2
      0009E6 8B 83            [24] 2445 	mov	dph,r3
      0009E8 8F F0            [24] 2446 	mov	b,r7
      0009EA 12 26 66         [24] 2447 	lcall	__gptrget
      0009ED FA               [12] 2448 	mov	r2,a
      0009EE A3               [24] 2449 	inc	dptr
      0009EF 12 26 66         [24] 2450 	lcall	__gptrget
      0009F2 FB               [12] 2451 	mov	r3,a
      0009F3 A3               [24] 2452 	inc	dptr
      0009F4 12 26 66         [24] 2453 	lcall	__gptrget
      0009F7 FF               [12] 2454 	mov	r7,a
      0009F8 A3               [24] 2455 	inc	dptr
      0009F9 12 26 66         [24] 2456 	lcall	__gptrget
      0009FC FE               [12] 2457 	mov	r6,a
      0009FD 8A 82            [24] 2458 	mov	dpl,r2
      0009FF 8B 83            [24] 2459 	mov	dph,r3
      000A01 8F F0            [24] 2460 	mov	b,r7
      000A03 C0 07            [24] 2461 	push	ar7
      000A05 C0 06            [24] 2462 	push	ar6
      000A07 C0 05            [24] 2463 	push	ar5
      000A09 C0 04            [24] 2464 	push	ar4
      000A0B 12 00 EA         [24] 2465 	lcall	_fuzzy_clamp
      000A0E C8               [12] 2466 	xch	a,r0
      000A0F E5 08            [12] 2467 	mov	a,_bp
      000A11 24 05            [12] 2468 	add	a,#0x05
      000A13 C8               [12] 2469 	xch	a,r0
      000A14 A6 82            [24] 2470 	mov	@r0, dpl
      000A16 08               [12] 2471 	inc	r0
      000A17 A6 83            [24] 2472 	mov	@r0, dph
      000A19 08               [12] 2473 	inc	r0
      000A1A A6 F0            [24] 2474 	mov	@r0, b
      000A1C 08               [12] 2475 	inc	r0
      000A1D F6               [12] 2476 	mov	@r0,a
      000A1E D0 04            [24] 2477 	pop	ar4
      000A20 D0 05            [24] 2478 	pop	ar5
      000A22 D0 06            [24] 2479 	pop	ar6
      000A24 D0 07            [24] 2480 	pop	ar7
                           00096F  2481 	C$fuzzy.h$1031$3_0$58 ==.
                                   2482 ;	../../fuzzy.h:1031: values[index + 1u];
      000A26 74 01            [12] 2483 	mov	a,#0x01
      000A28 2C               [12] 2484 	add	a, r4
      000A29 FE               [12] 2485 	mov	r6,a
      000A2A E4               [12] 2486 	clr	a
      000A2B 3D               [12] 2487 	addc	a, r5
      000A2C FF               [12] 2488 	mov	r7,a
      000A2D EE               [12] 2489 	mov	a,r6
      000A2E 2E               [12] 2490 	add	a,r6
      000A2F FE               [12] 2491 	mov	r6,a
      000A30 EF               [12] 2492 	mov	a,r7
      000A31 33               [12] 2493 	rlc	a
      000A32 FF               [12] 2494 	mov	r7,a
      000A33 EE               [12] 2495 	mov	a,r6
      000A34 2E               [12] 2496 	add	a,r6
      000A35 FE               [12] 2497 	mov	r6,a
      000A36 EF               [12] 2498 	mov	a,r7
      000A37 33               [12] 2499 	rlc	a
      000A38 FF               [12] 2500 	mov	r7,a
      000A39 E5 08            [12] 2501 	mov	a,_bp
      000A3B 24 FB            [12] 2502 	add	a,#0xfb
      000A3D F8               [12] 2503 	mov	r0,a
      000A3E EE               [12] 2504 	mov	a,r6
      000A3F 26               [12] 2505 	add	a, @r0
      000A40 FE               [12] 2506 	mov	r6,a
      000A41 EF               [12] 2507 	mov	a,r7
      000A42 08               [12] 2508 	inc	r0
      000A43 36               [12] 2509 	addc	a, @r0
      000A44 FF               [12] 2510 	mov	r7,a
      000A45 08               [12] 2511 	inc	r0
      000A46 86 03            [24] 2512 	mov	ar3,@r0
      000A48 8E 82            [24] 2513 	mov	dpl,r6
      000A4A 8F 83            [24] 2514 	mov	dph,r7
      000A4C 8B F0            [24] 2515 	mov	b,r3
      000A4E 12 26 66         [24] 2516 	lcall	__gptrget
      000A51 FE               [12] 2517 	mov	r6,a
      000A52 A3               [24] 2518 	inc	dptr
      000A53 12 26 66         [24] 2519 	lcall	__gptrget
      000A56 FF               [12] 2520 	mov	r7,a
      000A57 A3               [24] 2521 	inc	dptr
      000A58 12 26 66         [24] 2522 	lcall	__gptrget
      000A5B FB               [12] 2523 	mov	r3,a
      000A5C A3               [24] 2524 	inc	dptr
      000A5D 12 26 66         [24] 2525 	lcall	__gptrget
      000A60 FA               [12] 2526 	mov	r2,a
                           0009AA  2527 	C$fuzzy.h$1036$1_0$55 ==.
                                   2528 ;	../../fuzzy.h:1036: consequent;
      000A61 C0 05            [24] 2529 	push	ar5
      000A63 C0 04            [24] 2530 	push	ar4
      000A65 C0 06            [24] 2531 	push	ar6
      000A67 C0 07            [24] 2532 	push	ar7
      000A69 C0 03            [24] 2533 	push	ar3
      000A6B C0 02            [24] 2534 	push	ar2
      000A6D E5 08            [12] 2535 	mov	a,_bp
      000A6F 24 05            [12] 2536 	add	a,#0x05
      000A71 F8               [12] 2537 	mov	r0,a
      000A72 86 82            [24] 2538 	mov	dpl, @r0
      000A74 08               [12] 2539 	inc	r0
      000A75 86 83            [24] 2540 	mov	dph, @r0
      000A77 08               [12] 2541 	inc	r0
      000A78 86 F0            [24] 2542 	mov	b, @r0
      000A7A 08               [12] 2543 	inc	r0
      000A7B E6               [12] 2544 	mov	a, @r0
      000A7C 12 23 0A         [24] 2545 	lcall	___fsmul
      000A7F AA 82            [24] 2546 	mov	r2, dpl
      000A81 AB 83            [24] 2547 	mov	r3, dph
      000A83 AE F0            [24] 2548 	mov	r6, b
      000A85 FF               [12] 2549 	mov	r7, a
      000A86 E5 81            [12] 2550 	mov	a,sp
      000A88 24 FC            [12] 2551 	add	a,#0xfc
      000A8A F5 81            [12] 2552 	mov	sp,a
      000A8C D0 04            [24] 2553 	pop	ar4
      000A8E D0 05            [24] 2554 	pop	ar5
      000A90 C0 07            [24] 2555 	push	ar7
      000A92 C0 06            [24] 2556 	push	ar6
      000A94 C0 05            [24] 2557 	push	ar5
      000A96 C0 04            [24] 2558 	push	ar4
      000A98 C0 02            [24] 2559 	push	ar2
      000A9A C0 03            [24] 2560 	push	ar3
      000A9C C0 06            [24] 2561 	push	ar6
      000A9E C0 07            [24] 2562 	push	ar7
                           0009E9  2563 	C$fuzzy.h$1024$1_0$55 ==.
                                   2564 ;	../../fuzzy.h:1024: ) {
      000AA0 A8 08            [24] 2565 	mov	r0,_bp
      000AA2 08               [12] 2566 	inc	r0
      000AA3 86 82            [24] 2567 	mov	dpl, @r0
      000AA5 08               [12] 2568 	inc	r0
      000AA6 86 83            [24] 2569 	mov	dph, @r0
      000AA8 08               [12] 2570 	inc	r0
      000AA9 86 F0            [24] 2571 	mov	b, @r0
      000AAB 08               [12] 2572 	inc	r0
      000AAC E6               [12] 2573 	mov	a, @r0
      000AAD 12 24 8C         [24] 2574 	lcall	___fsadd
      000AB0 A8 08            [24] 2575 	mov	r0,_bp
      000AB2 08               [12] 2576 	inc	r0
      000AB3 A6 82            [24] 2577 	mov	@r0, dpl
      000AB5 08               [12] 2578 	inc	r0
      000AB6 A6 83            [24] 2579 	mov	@r0, dph
      000AB8 08               [12] 2580 	inc	r0
      000AB9 A6 F0            [24] 2581 	mov	@r0, b
      000ABB 08               [12] 2582 	inc	r0
      000ABC F6               [12] 2583 	mov	@r0,a
      000ABD E5 81            [12] 2584 	mov	a,sp
      000ABF 24 FC            [12] 2585 	add	a,#0xfc
      000AC1 F5 81            [12] 2586 	mov	sp,a
      000AC3 D0 04            [24] 2587 	pop	ar4
      000AC5 D0 05            [24] 2588 	pop	ar5
      000AC7 D0 06            [24] 2589 	pop	ar6
      000AC9 D0 07            [24] 2590 	pop	ar7
      000ACB 74 02            [12] 2591 	mov	a,#0x02
      000ACD 2C               [12] 2592 	add	a, r4
      000ACE FC               [12] 2593 	mov	r4,a
      000ACF E4               [12] 2594 	clr	a
      000AD0 3D               [12] 2595 	addc	a, r5
      000AD1 FD               [12] 2596 	mov	r5,a
      000AD2 D0 07            [24] 2597 	pop	ar7
      000AD4 D0 06            [24] 2598 	pop	ar6
      000AD6 02 09 BB         [24] 2599 	ljmp	00107$
      000AD9                       2600 00105$:
                           000A22  2601 	C$fuzzy.h$1039$1_0$55 ==.
                                   2602 ;	../../fuzzy.h:1039: return weighted_sum;
      000AD9 A8 08            [24] 2603 	mov	r0,_bp
      000ADB 08               [12] 2604 	inc	r0
      000ADC 86 82            [24] 2605 	mov	dpl, @r0
      000ADE 08               [12] 2606 	inc	r0
      000ADF 86 83            [24] 2607 	mov	dph, @r0
      000AE1 08               [12] 2608 	inc	r0
      000AE2 86 F0            [24] 2609 	mov	b, @r0
      000AE4 08               [12] 2610 	inc	r0
      000AE5 E6               [12] 2611 	mov	a, @r0
      000AE6                       2612 00109$:
                           000A2F  2613 	C$fuzzy.h$1040$1_0$55 ==.
                                   2614 ;	../../fuzzy.h:1040: }
      000AE6 85 08 81         [24] 2615 	mov	sp,_bp
      000AE9 D0 08            [24] 2616 	pop	_bp
                           000A34  2617 	C$fuzzy.h$1040$1_0$55 ==.
                           000A34  2618 	XG$fuzzy_sugeno_weighted_sum_array$0$0 ==.
      000AEB 22               [24] 2619 	ret
                                   2620 ;------------------------------------------------------------
                                   2621 ;Allocation info for local variables in function 'fuzzy_ramp'
                                   2622 ;------------------------------------------------------------
                                   2623 ;upper_boundary Allocated to stack - _bp -6 +4 
                                   2624 ;value         Allocated to stack - _bp -10 +4 
                                   2625 ;ramp_up       Allocated to stack - _bp -11 +1 
                                   2626 ;hedge         Allocated to stack - _bp -12 +1 
                                   2627 ;lower_boundary Allocated to registers r7 r6 r5 r4 
                                   2628 ;result        Allocated to stack - _bp +5 +4 
                                   2629 ;normalized    Allocated to registers r4 r5 r6 r7 
                                   2630 ;sloc0         Allocated to stack - _bp +13 +4 
                                   2631 ;sloc1         Allocated to stack - _bp +1 +4 
                                   2632 ;------------------------------------------------------------
                           000A35  2633 	G$fuzzy_ramp$0$0 ==.
                           000A35  2634 	C$fuzzy.h$1046$1_0$60 ==.
                                   2635 ;	../../fuzzy.h:1046: float fuzzy_ramp(
                                   2636 ;	-----------------------------------------
                                   2637 ;	 function fuzzy_ramp
                                   2638 ;	-----------------------------------------
      000AEC                       2639 _fuzzy_ramp:
      000AEC C0 08            [24] 2640 	push	_bp
      000AEE 85 81 08         [24] 2641 	mov	_bp,sp
      000AF1 AF 82            [24] 2642 	mov	r7,dpl
      000AF3 AE 83            [24] 2643 	mov	r6,dph
      000AF5 AD F0            [24] 2644 	mov	r5,b
      000AF7 FC               [12] 2645 	mov	r4,a
      000AF8 E5 81            [12] 2646 	mov	a,sp
      000AFA 24 08            [12] 2647 	add	a,#0x08
      000AFC F5 81            [12] 2648 	mov	sp,a
                           000A47  2649 	C$fuzzy.h$1057$1_0$60 ==.
                                   2650 ;	../../fuzzy.h:1057: if (lower_boundary >= upper_boundary) {
      000AFE C0 07            [24] 2651 	push	ar7
      000B00 C0 06            [24] 2652 	push	ar6
      000B02 C0 05            [24] 2653 	push	ar5
      000B04 C0 04            [24] 2654 	push	ar4
      000B06 E5 08            [12] 2655 	mov	a,_bp
      000B08 24 FA            [12] 2656 	add	a,#0xfa
      000B0A F8               [12] 2657 	mov	r0,a
      000B0B E6               [12] 2658 	mov	a,@r0
      000B0C C0 E0            [24] 2659 	push	acc
      000B0E 08               [12] 2660 	inc	r0
      000B0F E6               [12] 2661 	mov	a,@r0
      000B10 C0 E0            [24] 2662 	push	acc
      000B12 08               [12] 2663 	inc	r0
      000B13 E6               [12] 2664 	mov	a,@r0
      000B14 C0 E0            [24] 2665 	push	acc
      000B16 08               [12] 2666 	inc	r0
      000B17 E6               [12] 2667 	mov	a,@r0
      000B18 C0 E0            [24] 2668 	push	acc
      000B1A 8F 82            [24] 2669 	mov	dpl, r7
      000B1C 8E 83            [24] 2670 	mov	dph, r6
      000B1E 8D F0            [24] 2671 	mov	b, r5
      000B20 EC               [12] 2672 	mov	a, r4
      000B21 12 24 3A         [24] 2673 	lcall	___fslt
      000B24 E5 81            [12] 2674 	mov	a,sp
      000B26 24 FC            [12] 2675 	add	a,#0xfc
      000B28 F5 81            [12] 2676 	mov	sp,a
      000B2A D0 04            [24] 2677 	pop	ar4
      000B2C D0 05            [24] 2678 	pop	ar5
      000B2E D0 06            [24] 2679 	pop	ar6
      000B30 D0 07            [24] 2680 	pop	ar7
      000B32 E5 82            [12] 2681 	mov	a, dpl
      000B34 24 FF            [12] 2682 	add	a,#0xff
      000B36 92 00            [24] 2683 	mov	b0,c
      000B38 40 09            [24] 2684 	jc	00102$
                           000A83  2685 	C$fuzzy.h$1058$2_0$61 ==.
                                   2686 ;	../../fuzzy.h:1058: return LEVEL_LO;
      000B3A 90 00 00         [24] 2687 	mov	dptr,#0x0000
      000B3D E4               [12] 2688 	clr	a
      000B3E F5 F0            [12] 2689 	mov	b,a
      000B40 02 0D 23         [24] 2690 	ljmp	00109$
      000B43                       2691 00102$:
                           000A8C  2692 	C$fuzzy.h$1061$1_0$60 ==.
                                   2693 ;	../../fuzzy.h:1061: if (value <= lower_boundary) {
      000B43 C0 07            [24] 2694 	push	ar7
      000B45 C0 06            [24] 2695 	push	ar6
      000B47 C0 05            [24] 2696 	push	ar5
      000B49 C0 04            [24] 2697 	push	ar4
      000B4B E5 08            [12] 2698 	mov	a,_bp
      000B4D 24 F6            [12] 2699 	add	a,#0xf6
      000B4F F8               [12] 2700 	mov	r0,a
      000B50 E6               [12] 2701 	mov	a,@r0
      000B51 C0 E0            [24] 2702 	push	acc
      000B53 08               [12] 2703 	inc	r0
      000B54 E6               [12] 2704 	mov	a,@r0
      000B55 C0 E0            [24] 2705 	push	acc
      000B57 08               [12] 2706 	inc	r0
      000B58 E6               [12] 2707 	mov	a,@r0
      000B59 C0 E0            [24] 2708 	push	acc
      000B5B 08               [12] 2709 	inc	r0
      000B5C E6               [12] 2710 	mov	a,@r0
      000B5D C0 E0            [24] 2711 	push	acc
      000B5F 8F 82            [24] 2712 	mov	dpl, r7
      000B61 8E 83            [24] 2713 	mov	dph, r6
      000B63 8D F0            [24] 2714 	mov	b, r5
      000B65 EC               [12] 2715 	mov	a, r4
      000B66 12 24 3A         [24] 2716 	lcall	___fslt
      000B69 E5 81            [12] 2717 	mov	a,sp
      000B6B 24 FC            [12] 2718 	add	a,#0xfc
      000B6D F5 81            [12] 2719 	mov	sp,a
      000B6F D0 04            [24] 2720 	pop	ar4
      000B71 D0 05            [24] 2721 	pop	ar5
      000B73 D0 06            [24] 2722 	pop	ar6
      000B75 D0 07            [24] 2723 	pop	ar7
      000B77 E5 82            [12] 2724 	mov	a, dpl
      000B79 24 FF            [12] 2725 	add	a,#0xff
      000B7B 92 00            [24] 2726 	mov	b0,c
      000B7D 40 39            [24] 2727 	jc	00107$
                           000AC8  2728 	C$fuzzy.h$1063$2_0$62 ==.
                                   2729 ;	../../fuzzy.h:1063: ramp_up
      000B7F E5 08            [12] 2730 	mov	a,_bp
      000B81 24 F5            [12] 2731 	add	a,#0xf5
      000B83 F8               [12] 2732 	mov	r0,a
      000B84 E6               [12] 2733 	mov	a,@r0
      000B85 60 0F            [24] 2734 	jz	00111$
                           000AD0  2735 	C$fuzzy.h$1064$2_0$62 ==.
                                   2736 ;	../../fuzzy.h:1064: ? LEVEL_LO
      000B87 E5 08            [12] 2737 	mov	a,_bp
      000B89 24 05            [12] 2738 	add	a,#0x05
      000B8B F8               [12] 2739 	mov	r0,a
      000B8C E4               [12] 2740 	clr	a
      000B8D F6               [12] 2741 	mov	@r0,a
      000B8E 08               [12] 2742 	inc	r0
      000B8F F6               [12] 2743 	mov	@r0,a
      000B90 08               [12] 2744 	inc	r0
      000B91 F6               [12] 2745 	mov	@r0,a
      000B92 08               [12] 2746 	inc	r0
      000B93 F6               [12] 2747 	mov	@r0,a
      000B94 80 0F            [24] 2748 	sjmp	00112$
      000B96                       2749 00111$:
                           000ADF  2750 	C$fuzzy.h$1065$2_0$62 ==.
                                   2751 ;	../../fuzzy.h:1065: : LEVEL_HI;
      000B96 E5 08            [12] 2752 	mov	a,_bp
      000B98 24 05            [12] 2753 	add	a,#0x05
      000B9A F8               [12] 2754 	mov	r0,a
      000B9B E4               [12] 2755 	clr	a
      000B9C F6               [12] 2756 	mov	@r0,a
      000B9D 08               [12] 2757 	inc	r0
      000B9E F6               [12] 2758 	mov	@r0,a
      000B9F 08               [12] 2759 	inc	r0
      000BA0 76 80            [12] 2760 	mov	@r0,#0x80
      000BA2 08               [12] 2761 	inc	r0
      000BA3 76 3F            [12] 2762 	mov	@r0,#0x3f
      000BA5                       2763 00112$:
      000BA5 E5 08            [12] 2764 	mov	a,_bp
      000BA7 24 05            [12] 2765 	add	a,#0x05
      000BA9 F8               [12] 2766 	mov	r0,a
      000BAA 86 07            [24] 2767 	mov	ar7,@r0
      000BAC 08               [12] 2768 	inc	r0
      000BAD 86 06            [24] 2769 	mov	ar6,@r0
      000BAF 08               [12] 2770 	inc	r0
      000BB0 86 05            [24] 2771 	mov	ar5,@r0
      000BB2 08               [12] 2772 	inc	r0
      000BB3 86 04            [24] 2773 	mov	ar4,@r0
      000BB5 02 0D 01         [24] 2774 	ljmp	00108$
      000BB8                       2775 00107$:
                           000B01  2776 	C$fuzzy.h$1067$1_0$60 ==.
                                   2777 ;	../../fuzzy.h:1067: else if (value >= upper_boundary) {
      000BB8 C0 07            [24] 2778 	push	ar7
      000BBA C0 06            [24] 2779 	push	ar6
      000BBC C0 05            [24] 2780 	push	ar5
      000BBE C0 04            [24] 2781 	push	ar4
      000BC0 E5 08            [12] 2782 	mov	a,_bp
      000BC2 24 FA            [12] 2783 	add	a,#0xfa
      000BC4 F8               [12] 2784 	mov	r0,a
      000BC5 E6               [12] 2785 	mov	a,@r0
      000BC6 C0 E0            [24] 2786 	push	acc
      000BC8 08               [12] 2787 	inc	r0
      000BC9 E6               [12] 2788 	mov	a,@r0
      000BCA C0 E0            [24] 2789 	push	acc
      000BCC 08               [12] 2790 	inc	r0
      000BCD E6               [12] 2791 	mov	a,@r0
      000BCE C0 E0            [24] 2792 	push	acc
      000BD0 08               [12] 2793 	inc	r0
      000BD1 E6               [12] 2794 	mov	a,@r0
      000BD2 C0 E0            [24] 2795 	push	acc
      000BD4 E5 08            [12] 2796 	mov	a,_bp
      000BD6 24 F6            [12] 2797 	add	a,#0xf6
      000BD8 F8               [12] 2798 	mov	r0,a
      000BD9 86 82            [24] 2799 	mov	dpl, @r0
      000BDB 08               [12] 2800 	inc	r0
      000BDC 86 83            [24] 2801 	mov	dph, @r0
      000BDE 08               [12] 2802 	inc	r0
      000BDF 86 F0            [24] 2803 	mov	b, @r0
      000BE1 08               [12] 2804 	inc	r0
      000BE2 E6               [12] 2805 	mov	a, @r0
      000BE3 12 24 3A         [24] 2806 	lcall	___fslt
      000BE6 E5 81            [12] 2807 	mov	a,sp
      000BE8 24 FC            [12] 2808 	add	a,#0xfc
      000BEA F5 81            [12] 2809 	mov	sp,a
      000BEC D0 04            [24] 2810 	pop	ar4
      000BEE D0 05            [24] 2811 	pop	ar5
      000BF0 D0 06            [24] 2812 	pop	ar6
      000BF2 D0 07            [24] 2813 	pop	ar7
      000BF4 E5 82            [12] 2814 	mov	a, dpl
      000BF6 24 FF            [12] 2815 	add	a,#0xff
      000BF8 92 00            [24] 2816 	mov	b0,c
      000BFA 40 39            [24] 2817 	jc	00104$
                           000B45  2818 	C$fuzzy.h$1069$2_0$63 ==.
                                   2819 ;	../../fuzzy.h:1069: ramp_up
      000BFC E5 08            [12] 2820 	mov	a,_bp
      000BFE 24 F5            [12] 2821 	add	a,#0xf5
      000C00 F8               [12] 2822 	mov	r0,a
      000C01 E6               [12] 2823 	mov	a,@r0
      000C02 60 11            [24] 2824 	jz	00113$
                           000B4D  2825 	C$fuzzy.h$1070$2_0$63 ==.
                                   2826 ;	../../fuzzy.h:1070: ? LEVEL_HI
      000C04 E5 08            [12] 2827 	mov	a,_bp
      000C06 24 05            [12] 2828 	add	a,#0x05
      000C08 F8               [12] 2829 	mov	r0,a
      000C09 E4               [12] 2830 	clr	a
      000C0A F6               [12] 2831 	mov	@r0,a
      000C0B 08               [12] 2832 	inc	r0
      000C0C F6               [12] 2833 	mov	@r0,a
      000C0D 08               [12] 2834 	inc	r0
      000C0E 76 80            [12] 2835 	mov	@r0,#0x80
      000C10 08               [12] 2836 	inc	r0
      000C11 76 3F            [12] 2837 	mov	@r0,#0x3f
      000C13 80 0D            [24] 2838 	sjmp	00114$
      000C15                       2839 00113$:
                           000B5E  2840 	C$fuzzy.h$1071$2_0$63 ==.
                                   2841 ;	../../fuzzy.h:1071: : LEVEL_LO;
      000C15 E5 08            [12] 2842 	mov	a,_bp
      000C17 24 05            [12] 2843 	add	a,#0x05
      000C19 F8               [12] 2844 	mov	r0,a
      000C1A E4               [12] 2845 	clr	a
      000C1B F6               [12] 2846 	mov	@r0,a
      000C1C 08               [12] 2847 	inc	r0
      000C1D F6               [12] 2848 	mov	@r0,a
      000C1E 08               [12] 2849 	inc	r0
      000C1F F6               [12] 2850 	mov	@r0,a
      000C20 08               [12] 2851 	inc	r0
      000C21 F6               [12] 2852 	mov	@r0,a
      000C22                       2853 00114$:
      000C22 E5 08            [12] 2854 	mov	a,_bp
      000C24 24 05            [12] 2855 	add	a,#0x05
      000C26 F8               [12] 2856 	mov	r0,a
      000C27 86 07            [24] 2857 	mov	ar7,@r0
      000C29 08               [12] 2858 	inc	r0
      000C2A 86 06            [24] 2859 	mov	ar6,@r0
      000C2C 08               [12] 2860 	inc	r0
      000C2D 86 05            [24] 2861 	mov	ar5,@r0
      000C2F 08               [12] 2862 	inc	r0
      000C30 86 04            [24] 2863 	mov	ar4,@r0
      000C32 02 0D 01         [24] 2864 	ljmp	00108$
      000C35                       2865 00104$:
                           000B7E  2866 	C$fuzzy.h$1075$1_0$60 ==.
                                   2867 ;	../../fuzzy.h:1075: (value - lower_boundary) /
      000C35 C0 07            [24] 2868 	push	ar7
      000C37 C0 06            [24] 2869 	push	ar6
      000C39 C0 05            [24] 2870 	push	ar5
      000C3B C0 04            [24] 2871 	push	ar4
      000C3D C0 07            [24] 2872 	push	ar7
      000C3F C0 06            [24] 2873 	push	ar6
      000C41 C0 05            [24] 2874 	push	ar5
      000C43 C0 04            [24] 2875 	push	ar4
                           000B8E  2876 	C$fuzzy.h$1076$1_0$60 ==.
                                   2877 ;	../../fuzzy.h:1076: (upper_boundary - lower_boundary);
      000C45 E5 08            [12] 2878 	mov	a,_bp
      000C47 24 F6            [12] 2879 	add	a,#0xf6
      000C49 F8               [12] 2880 	mov	r0,a
      000C4A 86 82            [24] 2881 	mov	dpl, @r0
      000C4C 08               [12] 2882 	inc	r0
      000C4D 86 83            [24] 2883 	mov	dph, @r0
      000C4F 08               [12] 2884 	inc	r0
      000C50 86 F0            [24] 2885 	mov	b, @r0
      000C52 08               [12] 2886 	inc	r0
      000C53 E6               [12] 2887 	mov	a, @r0
      000C54 12 22 FF         [24] 2888 	lcall	___fssub
      000C57 A8 08            [24] 2889 	mov	r0,_bp
      000C59 08               [12] 2890 	inc	r0
      000C5A A6 82            [24] 2891 	mov	@r0, dpl
      000C5C 08               [12] 2892 	inc	r0
      000C5D A6 83            [24] 2893 	mov	@r0, dph
      000C5F 08               [12] 2894 	inc	r0
      000C60 A6 F0            [24] 2895 	mov	@r0, b
      000C62 08               [12] 2896 	inc	r0
      000C63 F6               [12] 2897 	mov	@r0,a
      000C64 E5 81            [12] 2898 	mov	a,sp
      000C66 24 FC            [12] 2899 	add	a,#0xfc
      000C68 F5 81            [12] 2900 	mov	sp,a
      000C6A E5 08            [12] 2901 	mov	a,_bp
      000C6C 24 FA            [12] 2902 	add	a,#0xfa
      000C6E F8               [12] 2903 	mov	r0,a
      000C6F 86 82            [24] 2904 	mov	dpl, @r0
      000C71 08               [12] 2905 	inc	r0
      000C72 86 83            [24] 2906 	mov	dph, @r0
      000C74 08               [12] 2907 	inc	r0
      000C75 86 F0            [24] 2908 	mov	b, @r0
      000C77 08               [12] 2909 	inc	r0
      000C78 E6               [12] 2910 	mov	a, @r0
      000C79 12 22 FF         [24] 2911 	lcall	___fssub
      000C7C AC 82            [24] 2912 	mov	r4, dpl
      000C7E AD 83            [24] 2913 	mov	r5, dph
      000C80 AE F0            [24] 2914 	mov	r6, b
      000C82 FF               [12] 2915 	mov	r7, a
      000C83 E5 81            [12] 2916 	mov	a,sp
      000C85 24 FC            [12] 2917 	add	a,#0xfc
      000C87 F5 81            [12] 2918 	mov	sp,a
      000C89 C0 04            [24] 2919 	push	ar4
      000C8B C0 05            [24] 2920 	push	ar5
      000C8D C0 06            [24] 2921 	push	ar6
      000C8F C0 07            [24] 2922 	push	ar7
                           000BDA  2923 	C$fuzzy.h$1079$1_0$60 ==.
                                   2924 ;	../../fuzzy.h:1079: ramp_up
      000C91 A8 08            [24] 2925 	mov	r0,_bp
      000C93 08               [12] 2926 	inc	r0
      000C94 86 82            [24] 2927 	mov	dpl, @r0
      000C96 08               [12] 2928 	inc	r0
      000C97 86 83            [24] 2929 	mov	dph, @r0
      000C99 08               [12] 2930 	inc	r0
      000C9A 86 F0            [24] 2931 	mov	b, @r0
      000C9C 08               [12] 2932 	inc	r0
      000C9D E6               [12] 2933 	mov	a, @r0
      000C9E 12 25 A3         [24] 2934 	lcall	___fsdiv
      000CA1 AC 82            [24] 2935 	mov	r4, dpl
      000CA3 AD 83            [24] 2936 	mov	r5, dph
      000CA5 AE F0            [24] 2937 	mov	r6, b
      000CA7 FF               [12] 2938 	mov	r7, a
      000CA8 E5 81            [12] 2939 	mov	a,sp
      000CAA 24 FC            [12] 2940 	add	a,#0xfc
      000CAC F5 81            [12] 2941 	mov	sp,a
      000CAE E5 08            [12] 2942 	mov	a,_bp
      000CB0 24 F5            [12] 2943 	add	a,#0xf5
      000CB2 F8               [12] 2944 	mov	r0,a
      000CB3 E6               [12] 2945 	mov	a,@r0
      000CB4 60 12            [24] 2946 	jz	00115$
                           000BFF  2947 	C$fuzzy.h$1080$2_0$64 ==.
                                   2948 ;	../../fuzzy.h:1080: ? normalized
      000CB6 E5 08            [12] 2949 	mov	a,_bp
      000CB8 24 05            [12] 2950 	add	a,#0x05
      000CBA F8               [12] 2951 	mov	r0,a
      000CBB A6 04            [24] 2952 	mov	@r0,ar4
      000CBD 08               [12] 2953 	inc	r0
      000CBE A6 05            [24] 2954 	mov	@r0,ar5
      000CC0 08               [12] 2955 	inc	r0
      000CC1 A6 06            [24] 2956 	mov	@r0,ar6
      000CC3 08               [12] 2957 	inc	r0
      000CC4 A6 07            [24] 2958 	mov	@r0,ar7
      000CC6 80 29            [24] 2959 	sjmp	00116$
      000CC8                       2960 00115$:
                           000C11  2961 	C$fuzzy.h$1081$1_0$60 ==.
                                   2962 ;	../../fuzzy.h:1081: : LEVEL_HI - normalized;
      000CC8 C0 04            [24] 2963 	push	ar4
      000CCA C0 05            [24] 2964 	push	ar5
      000CCC C0 06            [24] 2965 	push	ar6
      000CCE C0 07            [24] 2966 	push	ar7
      000CD0 90 00 00         [24] 2967 	mov	dptr,#0x0000
      000CD3 75 F0 80         [24] 2968 	mov	b, #0x80
      000CD6 74 3F            [12] 2969 	mov	a, #0x3f
      000CD8 12 22 FF         [24] 2970 	lcall	___fssub
      000CDB C8               [12] 2971 	xch	a,r0
      000CDC E5 08            [12] 2972 	mov	a,_bp
      000CDE 24 05            [12] 2973 	add	a,#0x05
      000CE0 C8               [12] 2974 	xch	a,r0
      000CE1 A6 82            [24] 2975 	mov	@r0, dpl
      000CE3 08               [12] 2976 	inc	r0
      000CE4 A6 83            [24] 2977 	mov	@r0, dph
      000CE6 08               [12] 2978 	inc	r0
      000CE7 A6 F0            [24] 2979 	mov	@r0, b
      000CE9 08               [12] 2980 	inc	r0
      000CEA F6               [12] 2981 	mov	@r0,a
      000CEB E5 81            [12] 2982 	mov	a,sp
      000CED 24 FC            [12] 2983 	add	a,#0xfc
      000CEF F5 81            [12] 2984 	mov	sp,a
      000CF1                       2985 00116$:
      000CF1 E5 08            [12] 2986 	mov	a,_bp
      000CF3 24 05            [12] 2987 	add	a,#0x05
      000CF5 F8               [12] 2988 	mov	r0,a
      000CF6 86 07            [24] 2989 	mov	ar7,@r0
      000CF8 08               [12] 2990 	inc	r0
      000CF9 86 06            [24] 2991 	mov	ar6,@r0
      000CFB 08               [12] 2992 	inc	r0
      000CFC 86 05            [24] 2993 	mov	ar5,@r0
      000CFE 08               [12] 2994 	inc	r0
      000CFF 86 04            [24] 2995 	mov	ar4,@r0
      000D01                       2996 00108$:
                           000C4A  2997 	C$fuzzy.h$1085$1_0$60 ==.
                                   2998 ;	../../fuzzy.h:1085: result,
      000D01 E5 08            [12] 2999 	mov	a,_bp
      000D03 24 F4            [12] 3000 	add	a,#0xf4
      000D05 F8               [12] 3001 	mov	r0,a
      000D06 E6               [12] 3002 	mov	a,@r0
      000D07 C0 E0            [24] 3003 	push	acc
      000D09 8F 82            [24] 3004 	mov	dpl, r7
      000D0B 8E 83            [24] 3005 	mov	dph, r6
      000D0D 8D F0            [24] 3006 	mov	b, r5
      000D0F EC               [12] 3007 	mov	a, r4
      000D10 12 01 99         [24] 3008 	lcall	_fuzzy_apply_hedge
      000D13 AC 82            [24] 3009 	mov	r4, dpl
      000D15 AD 83            [24] 3010 	mov	r5, dph
      000D17 AE F0            [24] 3011 	mov	r6, b
      000D19 FF               [12] 3012 	mov	r7, a
      000D1A 15 81            [12] 3013 	dec	sp
      000D1C 8C 82            [24] 3014 	mov	dpl, r4
      000D1E 8D 83            [24] 3015 	mov	dph, r5
      000D20 8E F0            [24] 3016 	mov	b, r6
      000D22 EF               [12] 3017 	mov	a, r7
      000D23                       3018 00109$:
                           000C6C  3019 	C$fuzzy.h$1088$1_0$60 ==.
                                   3020 ;	../../fuzzy.h:1088: }
      000D23 85 08 81         [24] 3021 	mov	sp,_bp
      000D26 D0 08            [24] 3022 	pop	_bp
                           000C71  3023 	C$fuzzy.h$1088$1_0$60 ==.
                           000C71  3024 	XG$fuzzy_ramp$0$0 ==.
      000D28 22               [24] 3025 	ret
                                   3026 ;------------------------------------------------------------
                                   3027 ;Allocation info for local variables in function 'fuzzy_function_array'
                                   3028 ;------------------------------------------------------------
                                   3029 ;value         Allocated to stack - _bp -6 +4 
                                   3030 ;hedge         Allocated to stack - _bp -7 +1 
                                   3031 ;parameter_count Allocated to stack - _bp -9 +2 
                                   3032 ;parameters    Allocated to stack - _bp -12 +3 
                                   3033 ;shape         Allocated to registers r7 
                                   3034 ;result        Allocated to stack - _bp +5 +4 
                                   3035 ;parameter_1   Allocated to stack - _bp +17 +4 
                                   3036 ;parameter_2   Allocated to stack - _bp +21 +4 
                                   3037 ;parameter_3   Allocated to stack - _bp +25 +4 
                                   3038 ;parameter_4   Allocated to registers r5 r6 r7 r4 
                                   3039 ;ramp_up       Allocated to registers r7 
                                   3040 ;sloc0         Allocated to stack - _bp +23 +3 
                                   3041 ;sloc1         Allocated to stack - _bp +1 +4 
                                   3042 ;sloc2         Allocated to stack - _bp +5 +4 
                                   3043 ;sloc3         Allocated to stack - _bp +9 +4 
                                   3044 ;sloc4         Allocated to stack - _bp +13 +4 
                                   3045 ;------------------------------------------------------------
                           000C72  3046 	G$fuzzy_function_array$0$0 ==.
                           000C72  3047 	C$fuzzy.h$1128$1_0$66 ==.
                                   3048 ;	../../fuzzy.h:1128: float fuzzy_function_array(
                                   3049 ;	-----------------------------------------
                                   3050 ;	 function fuzzy_function_array
                                   3051 ;	-----------------------------------------
      000D29                       3052 _fuzzy_function_array:
      000D29 C0 08            [24] 3053 	push	_bp
      000D2B E5 81            [12] 3054 	mov	a,sp
      000D2D F5 08            [12] 3055 	mov	_bp,a
      000D2F 24 1C            [12] 3056 	add	a,#0x1c
      000D31 F5 81            [12] 3057 	mov	sp,a
      000D33 AF 82            [24] 3058 	mov	r7, dpl
                           000C7E  3059 	C$fuzzy.h$1150$1_0$66 ==.
                                   3060 ;	../../fuzzy.h:1150: if (parameters == NULL) {
      000D35 E5 08            [12] 3061 	mov	a,_bp
      000D37 24 F4            [12] 3062 	add	a,#0xf4
      000D39 F8               [12] 3063 	mov	r0,a
      000D3A E6               [12] 3064 	mov	a,@r0
      000D3B 08               [12] 3065 	inc	r0
      000D3C 46               [12] 3066 	orl	a,@r0
      000D3D 70 09            [24] 3067 	jnz	00102$
                           000C88  3068 	C$fuzzy.h$1151$2_0$67 ==.
                                   3069 ;	../../fuzzy.h:1151: return LEVEL_LO;
      000D3F 90 00 00         [24] 3070 	mov	dptr,#0x0000
      000D42 E4               [12] 3071 	clr	a
      000D43 F5 F0            [12] 3072 	mov	b,a
      000D45 02 16 5D         [24] 3073 	ljmp	00145$
      000D48                       3074 00102$:
                           000C91  3075 	C$fuzzy.h$1154$1_0$66 ==.
                                   3076 ;	../../fuzzy.h:1154: switch (shape) {
      000D48 EF               [12] 3077 	mov	a,r7
      000D49 24 F8            [12] 3078 	add	a,#0xff - 0x07
      000D4B 50 03            [24] 3079 	jnc	00267$
      000D4D 02 16 2B         [24] 3080 	ljmp	00143$
      000D50                       3081 00267$:
      000D50 EF               [12] 3082 	mov	a,r7
      000D51 24 0A            [12] 3083 	add	a,#(00268$-3-.)
      000D53 83               [24] 3084 	movc	a,@a+pc
      000D54 F5 82            [12] 3085 	mov	dpl,a
      000D56 EF               [12] 3086 	mov	a,r7
      000D57 24 0C            [12] 3087 	add	a,#(00269$-3-.)
      000D59 83               [24] 3088 	movc	a,@a+pc
      000D5A F5 83            [12] 3089 	mov	dph,a
      000D5C E4               [12] 3090 	clr	a
      000D5D 73               [24] 3091 	jmp	@a+dptr
      000D5E                       3092 00268$:
      000D5E 6E                    3093 	.db	00103$
      000D5F 6C                    3094 	.db	00106$
      000D60 F2                    3095 	.db	00121$
      000D61 23                    3096 	.db	00142$
      000D62 23                    3097 	.db	00142$
      000D63 23                    3098 	.db	00142$
      000D64 23                    3099 	.db	00142$
      000D65 23                    3100 	.db	00142$
      000D66                       3101 00269$:
      000D66 0D                    3102 	.db	00103$>>8
      000D67 0E                    3103 	.db	00106$>>8
      000D68 11                    3104 	.db	00121$>>8
      000D69 16                    3105 	.db	00142$>>8
      000D6A 16                    3106 	.db	00142$>>8
      000D6B 16                    3107 	.db	00142$>>8
      000D6C 16                    3108 	.db	00142$>>8
      000D6D 16                    3109 	.db	00142$>>8
                           000CB7  3110 	C$fuzzy.h$1155$2_0$68 ==.
                                   3111 ;	../../fuzzy.h:1155: case FUZZY_SHAPE_RAMP:
      000D6E                       3112 00103$:
                           000CB7  3113 	C$fuzzy.h$1156$2_0$68 ==.
                                   3114 ;	../../fuzzy.h:1156: if (parameter_count != 3u) {
      000D6E E5 08            [12] 3115 	mov	a,_bp
      000D70 24 F7            [12] 3116 	add	a,#0xf7
      000D72 F8               [12] 3117 	mov	r0,a
      000D73 B6 03 06         [24] 3118 	cjne	@r0,#0x03,00270$
      000D76 08               [12] 3119 	inc	r0
      000D77 B6 00 02         [24] 3120 	cjne	@r0,#0x00,00270$
      000D7A 80 09            [24] 3121 	sjmp	00105$
      000D7C                       3122 00270$:
                           000CC5  3123 	C$fuzzy.h$1157$3_0$69 ==.
                                   3124 ;	../../fuzzy.h:1157: return LEVEL_LO;
      000D7C 90 00 00         [24] 3125 	mov	dptr,#0x0000
      000D7F E4               [12] 3126 	clr	a
      000D80 F5 F0            [12] 3127 	mov	b,a
      000D82 02 16 5D         [24] 3128 	ljmp	00145$
      000D85                       3129 00105$:
                           000CCE  3130 	C$fuzzy.h$1160$2_0$68 ==.
                                   3131 ;	../../fuzzy.h:1160: parameter_1 = parameters[0];
      000D85 E5 08            [12] 3132 	mov	a,_bp
      000D87 24 F4            [12] 3133 	add	a,#0xf4
      000D89 F8               [12] 3134 	mov	r0,a
      000D8A 86 02            [24] 3135 	mov	ar2,@r0
      000D8C 08               [12] 3136 	inc	r0
      000D8D 86 03            [24] 3137 	mov	ar3,@r0
      000D8F 08               [12] 3138 	inc	r0
      000D90 86 04            [24] 3139 	mov	ar4,@r0
      000D92 8A 82            [24] 3140 	mov	dpl,r2
      000D94 8B 83            [24] 3141 	mov	dph,r3
      000D96 8C F0            [24] 3142 	mov	b,r4
      000D98 A8 08            [24] 3143 	mov	r0,_bp
      000D9A 08               [12] 3144 	inc	r0
      000D9B 12 26 66         [24] 3145 	lcall	__gptrget
      000D9E F6               [12] 3146 	mov	@r0,a
      000D9F A3               [24] 3147 	inc	dptr
      000DA0 12 26 66         [24] 3148 	lcall	__gptrget
      000DA3 08               [12] 3149 	inc	r0
      000DA4 F6               [12] 3150 	mov	@r0,a
      000DA5 A3               [24] 3151 	inc	dptr
      000DA6 12 26 66         [24] 3152 	lcall	__gptrget
      000DA9 08               [12] 3153 	inc	r0
      000DAA F6               [12] 3154 	mov	@r0,a
      000DAB A3               [24] 3155 	inc	dptr
      000DAC 12 26 66         [24] 3156 	lcall	__gptrget
      000DAF 08               [12] 3157 	inc	r0
      000DB0 F6               [12] 3158 	mov	@r0,a
                           000CFA  3159 	C$fuzzy.h$1161$2_0$68 ==.
                                   3160 ;	../../fuzzy.h:1161: parameter_2 = parameters[1];
      000DB1 74 04            [12] 3161 	mov	a,#0x04
      000DB3 2A               [12] 3162 	add	a, r2
      000DB4 FD               [12] 3163 	mov	r5,a
      000DB5 E4               [12] 3164 	clr	a
      000DB6 3B               [12] 3165 	addc	a, r3
      000DB7 FE               [12] 3166 	mov	r6,a
      000DB8 8C 07            [24] 3167 	mov	ar7,r4
      000DBA 8D 82            [24] 3168 	mov	dpl,r5
      000DBC 8E 83            [24] 3169 	mov	dph,r6
      000DBE 8F F0            [24] 3170 	mov	b,r7
      000DC0 E5 08            [12] 3171 	mov	a,_bp
      000DC2 24 05            [12] 3172 	add	a,#0x05
      000DC4 F8               [12] 3173 	mov	r0,a
      000DC5 12 26 66         [24] 3174 	lcall	__gptrget
      000DC8 F6               [12] 3175 	mov	@r0,a
      000DC9 A3               [24] 3176 	inc	dptr
      000DCA 12 26 66         [24] 3177 	lcall	__gptrget
      000DCD 08               [12] 3178 	inc	r0
      000DCE F6               [12] 3179 	mov	@r0,a
      000DCF A3               [24] 3180 	inc	dptr
      000DD0 12 26 66         [24] 3181 	lcall	__gptrget
      000DD3 08               [12] 3182 	inc	r0
      000DD4 F6               [12] 3183 	mov	@r0,a
      000DD5 A3               [24] 3184 	inc	dptr
      000DD6 12 26 66         [24] 3185 	lcall	__gptrget
      000DD9 08               [12] 3186 	inc	r0
      000DDA F6               [12] 3187 	mov	@r0,a
                           000D24  3188 	C$fuzzy.h$1162$2_0$68 ==.
                                   3189 ;	../../fuzzy.h:1162: ramp_up = parameters[2] != 0.0f;
      000DDB 74 08            [12] 3190 	mov	a,#0x08
      000DDD 2A               [12] 3191 	add	a, r2
      000DDE FA               [12] 3192 	mov	r2,a
      000DDF E4               [12] 3193 	clr	a
      000DE0 3B               [12] 3194 	addc	a, r3
      000DE1 FB               [12] 3195 	mov	r3,a
      000DE2 8C 07            [24] 3196 	mov	ar7,r4
      000DE4 8A 82            [24] 3197 	mov	dpl,r2
      000DE6 8B 83            [24] 3198 	mov	dph,r3
      000DE8 8F F0            [24] 3199 	mov	b,r7
      000DEA 12 26 66         [24] 3200 	lcall	__gptrget
      000DED FA               [12] 3201 	mov	r2,a
      000DEE A3               [24] 3202 	inc	dptr
      000DEF 12 26 66         [24] 3203 	lcall	__gptrget
      000DF2 FB               [12] 3204 	mov	r3,a
      000DF3 A3               [24] 3205 	inc	dptr
      000DF4 12 26 66         [24] 3206 	lcall	__gptrget
      000DF7 FF               [12] 3207 	mov	r7,a
      000DF8 A3               [24] 3208 	inc	dptr
      000DF9 12 26 66         [24] 3209 	lcall	__gptrget
      000DFC FE               [12] 3210 	mov	r6,a
      000DFD 8A F0            [24] 3211 	mov	b,r2
      000DFF EB               [12] 3212 	mov	a,r3
      000E00 42 F0            [12] 3213 	orl	b,a
      000E02 EF               [12] 3214 	mov	a,r7
      000E03 42 F0            [12] 3215 	orl	b,a
      000E05 EE               [12] 3216 	mov	a,r6
      000E06 54 7F            [12] 3217 	anl	a,#0x7F
      000E08 45 F0            [12] 3218 	orl	a,b
      000E0A B4 01 00         [24] 3219 	cjne	a,#0x01,00271$
      000E0D                       3220 00271$:
      000E0D B3               [12] 3221 	cpl	c
      000E0E 92 00            [24] 3222 	mov	b0,c
      000E10 E4               [12] 3223 	clr	a
      000E11 33               [12] 3224 	rlc	a
      000E12 FF               [12] 3225 	mov	r7,a
                           000D5C  3226 	C$fuzzy.h$1165$2_0$68 ==.
                                   3227 ;	../../fuzzy.h:1165: parameter_1,
      000E13 E5 08            [12] 3228 	mov	a,_bp
      000E15 24 F9            [12] 3229 	add	a,#0xf9
      000E17 F8               [12] 3230 	mov	r0,a
      000E18 E6               [12] 3231 	mov	a,@r0
      000E19 C0 E0            [24] 3232 	push	acc
      000E1B C0 07            [24] 3233 	push	ar7
      000E1D E5 08            [12] 3234 	mov	a,_bp
      000E1F 24 FA            [12] 3235 	add	a,#0xfa
      000E21 F8               [12] 3236 	mov	r0,a
      000E22 E6               [12] 3237 	mov	a,@r0
      000E23 C0 E0            [24] 3238 	push	acc
      000E25 08               [12] 3239 	inc	r0
      000E26 E6               [12] 3240 	mov	a,@r0
      000E27 C0 E0            [24] 3241 	push	acc
      000E29 08               [12] 3242 	inc	r0
      000E2A E6               [12] 3243 	mov	a,@r0
      000E2B C0 E0            [24] 3244 	push	acc
      000E2D 08               [12] 3245 	inc	r0
      000E2E E6               [12] 3246 	mov	a,@r0
      000E2F C0 E0            [24] 3247 	push	acc
      000E31 E5 08            [12] 3248 	mov	a,_bp
      000E33 24 05            [12] 3249 	add	a,#0x05
      000E35 F8               [12] 3250 	mov	r0,a
      000E36 E6               [12] 3251 	mov	a,@r0
      000E37 C0 E0            [24] 3252 	push	acc
      000E39 08               [12] 3253 	inc	r0
      000E3A E6               [12] 3254 	mov	a,@r0
      000E3B C0 E0            [24] 3255 	push	acc
      000E3D 08               [12] 3256 	inc	r0
      000E3E E6               [12] 3257 	mov	a,@r0
      000E3F C0 E0            [24] 3258 	push	acc
      000E41 08               [12] 3259 	inc	r0
      000E42 E6               [12] 3260 	mov	a,@r0
      000E43 C0 E0            [24] 3261 	push	acc
      000E45 A8 08            [24] 3262 	mov	r0,_bp
      000E47 08               [12] 3263 	inc	r0
      000E48 86 82            [24] 3264 	mov	dpl, @r0
      000E4A 08               [12] 3265 	inc	r0
      000E4B 86 83            [24] 3266 	mov	dph, @r0
      000E4D 08               [12] 3267 	inc	r0
      000E4E 86 F0            [24] 3268 	mov	b, @r0
      000E50 08               [12] 3269 	inc	r0
      000E51 E6               [12] 3270 	mov	a, @r0
      000E52 12 0A EC         [24] 3271 	lcall	_fuzzy_ramp
      000E55 AC 82            [24] 3272 	mov	r4, dpl
      000E57 AD 83            [24] 3273 	mov	r5, dph
      000E59 AE F0            [24] 3274 	mov	r6, b
      000E5B FF               [12] 3275 	mov	r7, a
      000E5C E5 81            [12] 3276 	mov	a,sp
      000E5E 24 F6            [12] 3277 	add	a,#0xf6
      000E60 F5 81            [12] 3278 	mov	sp,a
      000E62 8C 82            [24] 3279 	mov	dpl, r4
      000E64 8D 83            [24] 3280 	mov	dph, r5
      000E66 8E F0            [24] 3281 	mov	b, r6
      000E68 EF               [12] 3282 	mov	a, r7
      000E69 02 16 5D         [24] 3283 	ljmp	00145$
                           000DB5  3284 	C$fuzzy.h$1172$2_0$68 ==.
                                   3285 ;	../../fuzzy.h:1172: case FUZZY_SHAPE_TRIANGLE:
      000E6C                       3286 00106$:
                           000DB5  3287 	C$fuzzy.h$1173$2_0$68 ==.
                                   3288 ;	../../fuzzy.h:1173: if (parameter_count != 3u) {
      000E6C E5 08            [12] 3289 	mov	a,_bp
      000E6E 24 F7            [12] 3290 	add	a,#0xf7
      000E70 F8               [12] 3291 	mov	r0,a
      000E71 B6 03 06         [24] 3292 	cjne	@r0,#0x03,00272$
      000E74 08               [12] 3293 	inc	r0
      000E75 B6 00 02         [24] 3294 	cjne	@r0,#0x00,00272$
      000E78 80 09            [24] 3295 	sjmp	00108$
      000E7A                       3296 00272$:
                           000DC3  3297 	C$fuzzy.h$1174$3_0$70 ==.
                                   3298 ;	../../fuzzy.h:1174: return LEVEL_LO;
      000E7A 90 00 00         [24] 3299 	mov	dptr,#0x0000
      000E7D E4               [12] 3300 	clr	a
      000E7E F5 F0            [12] 3301 	mov	b,a
      000E80 02 16 5D         [24] 3302 	ljmp	00145$
      000E83                       3303 00108$:
                           000DCC  3304 	C$fuzzy.h$1177$2_0$68 ==.
                                   3305 ;	../../fuzzy.h:1177: parameter_1 = parameters[0];
      000E83 E5 08            [12] 3306 	mov	a,_bp
      000E85 24 F4            [12] 3307 	add	a,#0xf4
      000E87 F8               [12] 3308 	mov	r0,a
      000E88 86 02            [24] 3309 	mov	ar2,@r0
      000E8A 08               [12] 3310 	inc	r0
      000E8B 86 03            [24] 3311 	mov	ar3,@r0
      000E8D 08               [12] 3312 	inc	r0
      000E8E 86 04            [24] 3313 	mov	ar4,@r0
      000E90 8A 82            [24] 3314 	mov	dpl,r2
      000E92 8B 83            [24] 3315 	mov	dph,r3
      000E94 8C F0            [24] 3316 	mov	b,r4
      000E96 E5 08            [12] 3317 	mov	a,_bp
      000E98 24 11            [12] 3318 	add	a,#0x11
      000E9A F8               [12] 3319 	mov	r0,a
      000E9B 12 26 66         [24] 3320 	lcall	__gptrget
      000E9E F6               [12] 3321 	mov	@r0,a
      000E9F A3               [24] 3322 	inc	dptr
      000EA0 12 26 66         [24] 3323 	lcall	__gptrget
      000EA3 08               [12] 3324 	inc	r0
      000EA4 F6               [12] 3325 	mov	@r0,a
      000EA5 A3               [24] 3326 	inc	dptr
      000EA6 12 26 66         [24] 3327 	lcall	__gptrget
      000EA9 08               [12] 3328 	inc	r0
      000EAA F6               [12] 3329 	mov	@r0,a
      000EAB A3               [24] 3330 	inc	dptr
      000EAC 12 26 66         [24] 3331 	lcall	__gptrget
      000EAF 08               [12] 3332 	inc	r0
      000EB0 F6               [12] 3333 	mov	@r0,a
                           000DFA  3334 	C$fuzzy.h$1178$2_0$68 ==.
                                   3335 ;	../../fuzzy.h:1178: parameter_2 = parameters[1];
      000EB1 74 04            [12] 3336 	mov	a,#0x04
      000EB3 2A               [12] 3337 	add	a, r2
      000EB4 FF               [12] 3338 	mov	r7,a
      000EB5 E4               [12] 3339 	clr	a
      000EB6 3B               [12] 3340 	addc	a, r3
      000EB7 FD               [12] 3341 	mov	r5,a
      000EB8 8C 06            [24] 3342 	mov	ar6,r4
      000EBA 8F 82            [24] 3343 	mov	dpl,r7
      000EBC 8D 83            [24] 3344 	mov	dph,r5
      000EBE 8E F0            [24] 3345 	mov	b,r6
      000EC0 E5 08            [12] 3346 	mov	a,_bp
      000EC2 24 15            [12] 3347 	add	a,#0x15
      000EC4 F8               [12] 3348 	mov	r0,a
      000EC5 12 26 66         [24] 3349 	lcall	__gptrget
      000EC8 F6               [12] 3350 	mov	@r0,a
      000EC9 A3               [24] 3351 	inc	dptr
      000ECA 12 26 66         [24] 3352 	lcall	__gptrget
      000ECD 08               [12] 3353 	inc	r0
      000ECE F6               [12] 3354 	mov	@r0,a
      000ECF A3               [24] 3355 	inc	dptr
      000ED0 12 26 66         [24] 3356 	lcall	__gptrget
      000ED3 08               [12] 3357 	inc	r0
      000ED4 F6               [12] 3358 	mov	@r0,a
      000ED5 A3               [24] 3359 	inc	dptr
      000ED6 12 26 66         [24] 3360 	lcall	__gptrget
      000ED9 08               [12] 3361 	inc	r0
      000EDA F6               [12] 3362 	mov	@r0,a
                           000E24  3363 	C$fuzzy.h$1179$2_0$68 ==.
                                   3364 ;	../../fuzzy.h:1179: parameter_3 = parameters[2];
      000EDB 74 08            [12] 3365 	mov	a,#0x08
      000EDD 2A               [12] 3366 	add	a, r2
      000EDE FA               [12] 3367 	mov	r2,a
      000EDF E4               [12] 3368 	clr	a
      000EE0 3B               [12] 3369 	addc	a, r3
      000EE1 FB               [12] 3370 	mov	r3,a
      000EE2 8C 07            [24] 3371 	mov	ar7,r4
      000EE4 8A 82            [24] 3372 	mov	dpl,r2
      000EE6 8B 83            [24] 3373 	mov	dph,r3
      000EE8 8F F0            [24] 3374 	mov	b,r7
      000EEA 12 26 66         [24] 3375 	lcall	__gptrget
      000EED FD               [12] 3376 	mov	r5,a
      000EEE A3               [24] 3377 	inc	dptr
      000EEF 12 26 66         [24] 3378 	lcall	__gptrget
      000EF2 FE               [12] 3379 	mov	r6,a
      000EF3 A3               [24] 3380 	inc	dptr
      000EF4 12 26 66         [24] 3381 	lcall	__gptrget
      000EF7 FF               [12] 3382 	mov	r7,a
      000EF8 A3               [24] 3383 	inc	dptr
      000EF9 12 26 66         [24] 3384 	lcall	__gptrget
      000EFC FC               [12] 3385 	mov	r4,a
                           000E46  3386 	C$fuzzy.h$1182$1_0$66 ==.
                                   3387 ;	../../fuzzy.h:1182: parameter_1 >= parameter_2 ||
      000EFD C0 07            [24] 3388 	push	ar7
      000EFF C0 06            [24] 3389 	push	ar6
      000F01 C0 05            [24] 3390 	push	ar5
      000F03 C0 04            [24] 3391 	push	ar4
      000F05 E5 08            [12] 3392 	mov	a,_bp
      000F07 24 15            [12] 3393 	add	a,#0x15
      000F09 F8               [12] 3394 	mov	r0,a
      000F0A E6               [12] 3395 	mov	a,@r0
      000F0B C0 E0            [24] 3396 	push	acc
      000F0D 08               [12] 3397 	inc	r0
      000F0E E6               [12] 3398 	mov	a,@r0
      000F0F C0 E0            [24] 3399 	push	acc
      000F11 08               [12] 3400 	inc	r0
      000F12 E6               [12] 3401 	mov	a,@r0
      000F13 C0 E0            [24] 3402 	push	acc
      000F15 08               [12] 3403 	inc	r0
      000F16 E6               [12] 3404 	mov	a,@r0
      000F17 C0 E0            [24] 3405 	push	acc
      000F19 E5 08            [12] 3406 	mov	a,_bp
      000F1B 24 11            [12] 3407 	add	a,#0x11
      000F1D F8               [12] 3408 	mov	r0,a
      000F1E 86 82            [24] 3409 	mov	dpl, @r0
      000F20 08               [12] 3410 	inc	r0
      000F21 86 83            [24] 3411 	mov	dph, @r0
      000F23 08               [12] 3412 	inc	r0
      000F24 86 F0            [24] 3413 	mov	b, @r0
      000F26 08               [12] 3414 	inc	r0
      000F27 E6               [12] 3415 	mov	a, @r0
      000F28 12 24 3A         [24] 3416 	lcall	___fslt
      000F2B E5 81            [12] 3417 	mov	a,sp
      000F2D 24 FC            [12] 3418 	add	a,#0xfc
      000F2F F5 81            [12] 3419 	mov	sp,a
      000F31 D0 04            [24] 3420 	pop	ar4
      000F33 D0 05            [24] 3421 	pop	ar5
      000F35 D0 06            [24] 3422 	pop	ar6
      000F37 D0 07            [24] 3423 	pop	ar7
      000F39 E5 82            [12] 3424 	mov	a, dpl
      000F3B 24 FF            [12] 3425 	add	a,#0xff
      000F3D 92 00            [24] 3426 	mov	b0,c
      000F3F 40 03            [24] 3427 	jc	00273$
      000F41 02 0F F8         [24] 3428 	ljmp	00115$
      000F44                       3429 00273$:
                           000E8D  3430 	C$fuzzy.h$1183$1_0$66 ==.
                                   3431 ;	../../fuzzy.h:1183: parameter_2 >= parameter_3 ||
      000F44 C0 07            [24] 3432 	push	ar7
      000F46 C0 06            [24] 3433 	push	ar6
      000F48 C0 05            [24] 3434 	push	ar5
      000F4A C0 04            [24] 3435 	push	ar4
      000F4C C0 05            [24] 3436 	push	ar5
      000F4E C0 06            [24] 3437 	push	ar6
      000F50 C0 07            [24] 3438 	push	ar7
      000F52 C0 04            [24] 3439 	push	ar4
      000F54 E5 08            [12] 3440 	mov	a,_bp
      000F56 24 15            [12] 3441 	add	a,#0x15
      000F58 F8               [12] 3442 	mov	r0,a
      000F59 86 82            [24] 3443 	mov	dpl, @r0
      000F5B 08               [12] 3444 	inc	r0
      000F5C 86 83            [24] 3445 	mov	dph, @r0
      000F5E 08               [12] 3446 	inc	r0
      000F5F 86 F0            [24] 3447 	mov	b, @r0
      000F61 08               [12] 3448 	inc	r0
      000F62 E6               [12] 3449 	mov	a, @r0
      000F63 12 24 3A         [24] 3450 	lcall	___fslt
      000F66 E5 81            [12] 3451 	mov	a,sp
      000F68 24 FC            [12] 3452 	add	a,#0xfc
      000F6A F5 81            [12] 3453 	mov	sp,a
      000F6C D0 04            [24] 3454 	pop	ar4
      000F6E D0 05            [24] 3455 	pop	ar5
      000F70 D0 06            [24] 3456 	pop	ar6
      000F72 D0 07            [24] 3457 	pop	ar7
      000F74 E5 82            [12] 3458 	mov	a, dpl
      000F76 24 FF            [12] 3459 	add	a,#0xff
      000F78 92 00            [24] 3460 	mov	b0,c
      000F7A 50 7C            [24] 3461 	jnc	00115$
                           000EC5  3462 	C$fuzzy.h$1184$1_0$66 ==.
                                   3463 ;	../../fuzzy.h:1184: value <= parameter_1 ||
      000F7C C0 07            [24] 3464 	push	ar7
      000F7E C0 06            [24] 3465 	push	ar6
      000F80 C0 05            [24] 3466 	push	ar5
      000F82 C0 04            [24] 3467 	push	ar4
      000F84 E5 08            [12] 3468 	mov	a,_bp
      000F86 24 FA            [12] 3469 	add	a,#0xfa
      000F88 F8               [12] 3470 	mov	r0,a
      000F89 E6               [12] 3471 	mov	a,@r0
      000F8A C0 E0            [24] 3472 	push	acc
      000F8C 08               [12] 3473 	inc	r0
      000F8D E6               [12] 3474 	mov	a,@r0
      000F8E C0 E0            [24] 3475 	push	acc
      000F90 08               [12] 3476 	inc	r0
      000F91 E6               [12] 3477 	mov	a,@r0
      000F92 C0 E0            [24] 3478 	push	acc
      000F94 08               [12] 3479 	inc	r0
      000F95 E6               [12] 3480 	mov	a,@r0
      000F96 C0 E0            [24] 3481 	push	acc
      000F98 E5 08            [12] 3482 	mov	a,_bp
      000F9A 24 11            [12] 3483 	add	a,#0x11
      000F9C F8               [12] 3484 	mov	r0,a
      000F9D 86 82            [24] 3485 	mov	dpl, @r0
      000F9F 08               [12] 3486 	inc	r0
      000FA0 86 83            [24] 3487 	mov	dph, @r0
      000FA2 08               [12] 3488 	inc	r0
      000FA3 86 F0            [24] 3489 	mov	b, @r0
      000FA5 08               [12] 3490 	inc	r0
      000FA6 E6               [12] 3491 	mov	a, @r0
      000FA7 12 24 3A         [24] 3492 	lcall	___fslt
      000FAA E5 81            [12] 3493 	mov	a,sp
      000FAC 24 FC            [12] 3494 	add	a,#0xfc
      000FAE F5 81            [12] 3495 	mov	sp,a
      000FB0 D0 04            [24] 3496 	pop	ar4
      000FB2 D0 05            [24] 3497 	pop	ar5
      000FB4 D0 06            [24] 3498 	pop	ar6
      000FB6 D0 07            [24] 3499 	pop	ar7
      000FB8 E5 82            [12] 3500 	mov	a, dpl
      000FBA 24 FF            [12] 3501 	add	a,#0xff
      000FBC 92 00            [24] 3502 	mov	b0,c
      000FBE 50 38            [24] 3503 	jnc	00115$
                           000F09  3504 	C$fuzzy.h$1186$1_0$66 ==.
                                   3505 ;	../../fuzzy.h:1186: ) {
      000FC0 C0 07            [24] 3506 	push	ar7
      000FC2 C0 06            [24] 3507 	push	ar6
      000FC4 C0 05            [24] 3508 	push	ar5
      000FC6 C0 04            [24] 3509 	push	ar4
      000FC8 C0 05            [24] 3510 	push	ar5
      000FCA C0 06            [24] 3511 	push	ar6
      000FCC C0 07            [24] 3512 	push	ar7
      000FCE C0 04            [24] 3513 	push	ar4
      000FD0 E5 08            [12] 3514 	mov	a,_bp
      000FD2 24 FA            [12] 3515 	add	a,#0xfa
      000FD4 F8               [12] 3516 	mov	r0,a
      000FD5 86 82            [24] 3517 	mov	dpl, @r0
      000FD7 08               [12] 3518 	inc	r0
      000FD8 86 83            [24] 3519 	mov	dph, @r0
      000FDA 08               [12] 3520 	inc	r0
      000FDB 86 F0            [24] 3521 	mov	b, @r0
      000FDD 08               [12] 3522 	inc	r0
      000FDE E6               [12] 3523 	mov	a, @r0
      000FDF 12 24 3A         [24] 3524 	lcall	___fslt
      000FE2 E5 81            [12] 3525 	mov	a,sp
      000FE4 24 FC            [12] 3526 	add	a,#0xfc
      000FE6 F5 81            [12] 3527 	mov	sp,a
      000FE8 D0 04            [24] 3528 	pop	ar4
      000FEA D0 05            [24] 3529 	pop	ar5
      000FEC D0 06            [24] 3530 	pop	ar6
      000FEE D0 07            [24] 3531 	pop	ar7
      000FF0 E5 82            [12] 3532 	mov	a, dpl
      000FF2 24 FF            [12] 3533 	add	a,#0xff
      000FF4 92 00            [24] 3534 	mov	b0,c
      000FF6 40 10            [24] 3535 	jc	00116$
      000FF8                       3536 00115$:
                           000F41  3537 	C$fuzzy.h$1187$3_0$71 ==.
                                   3538 ;	../../fuzzy.h:1187: result = LEVEL_LO;
      000FF8 E5 08            [12] 3539 	mov	a,_bp
      000FFA 24 05            [12] 3540 	add	a,#0x05
      000FFC F8               [12] 3541 	mov	r0,a
      000FFD E4               [12] 3542 	clr	a
      000FFE F6               [12] 3543 	mov	@r0,a
      000FFF 08               [12] 3544 	inc	r0
      001000 F6               [12] 3545 	mov	@r0,a
      001001 08               [12] 3546 	inc	r0
      001002 F6               [12] 3547 	mov	@r0,a
      001003 08               [12] 3548 	inc	r0
      001004 F6               [12] 3549 	mov	@r0,a
      001005 02 16 33         [24] 3550 	ljmp	00144$
      001008                       3551 00116$:
                           000F51  3552 	C$fuzzy.h$1189$1_0$66 ==.
                                   3553 ;	../../fuzzy.h:1189: else if (value == parameter_2) {
      001008 C0 07            [24] 3554 	push	ar7
      00100A C0 06            [24] 3555 	push	ar6
      00100C C0 05            [24] 3556 	push	ar5
      00100E C0 04            [24] 3557 	push	ar4
      001010 E5 08            [12] 3558 	mov	a,_bp
      001012 24 15            [12] 3559 	add	a,#0x15
      001014 F8               [12] 3560 	mov	r0,a
      001015 E6               [12] 3561 	mov	a,@r0
      001016 C0 E0            [24] 3562 	push	acc
      001018 08               [12] 3563 	inc	r0
      001019 E6               [12] 3564 	mov	a,@r0
      00101A C0 E0            [24] 3565 	push	acc
      00101C 08               [12] 3566 	inc	r0
      00101D E6               [12] 3567 	mov	a,@r0
      00101E C0 E0            [24] 3568 	push	acc
      001020 08               [12] 3569 	inc	r0
      001021 E6               [12] 3570 	mov	a,@r0
      001022 C0 E0            [24] 3571 	push	acc
      001024 E5 08            [12] 3572 	mov	a,_bp
      001026 24 FA            [12] 3573 	add	a,#0xfa
      001028 F8               [12] 3574 	mov	r0,a
      001029 86 82            [24] 3575 	mov	dpl, @r0
      00102B 08               [12] 3576 	inc	r0
      00102C 86 83            [24] 3577 	mov	dph, @r0
      00102E 08               [12] 3578 	inc	r0
      00102F 86 F0            [24] 3579 	mov	b, @r0
      001031 08               [12] 3580 	inc	r0
      001032 E6               [12] 3581 	mov	a, @r0
      001033 12 24 0E         [24] 3582 	lcall	___fseq
      001036 AB 82            [24] 3583 	mov	r3, dpl
      001038 E5 81            [12] 3584 	mov	a,sp
      00103A 24 FC            [12] 3585 	add	a,#0xfc
      00103C F5 81            [12] 3586 	mov	sp,a
      00103E D0 04            [24] 3587 	pop	ar4
      001040 D0 05            [24] 3588 	pop	ar5
      001042 D0 06            [24] 3589 	pop	ar6
      001044 D0 07            [24] 3590 	pop	ar7
      001046 EB               [12] 3591 	mov	a,r3
      001047 60 12            [24] 3592 	jz	00113$
                           000F92  3593 	C$fuzzy.h$1190$3_0$72 ==.
                                   3594 ;	../../fuzzy.h:1190: result = LEVEL_HI;
      001049 E5 08            [12] 3595 	mov	a,_bp
      00104B 24 05            [12] 3596 	add	a,#0x05
      00104D F8               [12] 3597 	mov	r0,a
      00104E E4               [12] 3598 	clr	a
      00104F F6               [12] 3599 	mov	@r0,a
      001050 08               [12] 3600 	inc	r0
      001051 F6               [12] 3601 	mov	@r0,a
      001052 08               [12] 3602 	inc	r0
      001053 76 80            [12] 3603 	mov	@r0,#0x80
      001055 08               [12] 3604 	inc	r0
      001056 76 3F            [12] 3605 	mov	@r0,#0x3f
      001058 02 16 33         [24] 3606 	ljmp	00144$
      00105B                       3607 00113$:
                           000FA4  3608 	C$fuzzy.h$1192$1_0$66 ==.
                                   3609 ;	../../fuzzy.h:1192: else if (value < parameter_2) {
      00105B C0 07            [24] 3610 	push	ar7
      00105D C0 06            [24] 3611 	push	ar6
      00105F C0 05            [24] 3612 	push	ar5
      001061 C0 04            [24] 3613 	push	ar4
      001063 E5 08            [12] 3614 	mov	a,_bp
      001065 24 15            [12] 3615 	add	a,#0x15
      001067 F8               [12] 3616 	mov	r0,a
      001068 E6               [12] 3617 	mov	a,@r0
      001069 C0 E0            [24] 3618 	push	acc
      00106B 08               [12] 3619 	inc	r0
      00106C E6               [12] 3620 	mov	a,@r0
      00106D C0 E0            [24] 3621 	push	acc
      00106F 08               [12] 3622 	inc	r0
      001070 E6               [12] 3623 	mov	a,@r0
      001071 C0 E0            [24] 3624 	push	acc
      001073 08               [12] 3625 	inc	r0
      001074 E6               [12] 3626 	mov	a,@r0
      001075 C0 E0            [24] 3627 	push	acc
      001077 E5 08            [12] 3628 	mov	a,_bp
      001079 24 FA            [12] 3629 	add	a,#0xfa
      00107B F8               [12] 3630 	mov	r0,a
      00107C 86 82            [24] 3631 	mov	dpl, @r0
      00107E 08               [12] 3632 	inc	r0
      00107F 86 83            [24] 3633 	mov	dph, @r0
      001081 08               [12] 3634 	inc	r0
      001082 86 F0            [24] 3635 	mov	b, @r0
      001084 08               [12] 3636 	inc	r0
      001085 E6               [12] 3637 	mov	a, @r0
      001086 12 24 3A         [24] 3638 	lcall	___fslt
      001089 AB 82            [24] 3639 	mov	r3, dpl
      00108B E5 81            [12] 3640 	mov	a,sp
      00108D 24 FC            [12] 3641 	add	a,#0xfc
      00108F F5 81            [12] 3642 	mov	sp,a
      001091 D0 04            [24] 3643 	pop	ar4
      001093 D0 05            [24] 3644 	pop	ar5
      001095 D0 06            [24] 3645 	pop	ar6
      001097 D0 07            [24] 3646 	pop	ar7
      001099 EB               [12] 3647 	mov	a,r3
      00109A 70 03            [24] 3648 	jnz	00278$
      00109C 02 11 55         [24] 3649 	ljmp	00110$
      00109F                       3650 00278$:
                           000FE8  3651 	C$fuzzy.h$1194$1_0$66 ==.
                                   3652 ;	../../fuzzy.h:1194: (value - parameter_1) /
      00109F E5 08            [12] 3653 	mov	a,_bp
      0010A1 24 11            [12] 3654 	add	a,#0x11
      0010A3 F8               [12] 3655 	mov	r0,a
      0010A4 E6               [12] 3656 	mov	a,@r0
      0010A5 C0 E0            [24] 3657 	push	acc
      0010A7 08               [12] 3658 	inc	r0
      0010A8 E6               [12] 3659 	mov	a,@r0
      0010A9 C0 E0            [24] 3660 	push	acc
      0010AB 08               [12] 3661 	inc	r0
      0010AC E6               [12] 3662 	mov	a,@r0
      0010AD C0 E0            [24] 3663 	push	acc
      0010AF 08               [12] 3664 	inc	r0
      0010B0 E6               [12] 3665 	mov	a,@r0
      0010B1 C0 E0            [24] 3666 	push	acc
                           000FFC  3667 	C$fuzzy.h$1195$1_0$66 ==.
                                   3668 ;	../../fuzzy.h:1195: (parameter_2 - parameter_1);
      0010B3 E5 08            [12] 3669 	mov	a,_bp
      0010B5 24 FA            [12] 3670 	add	a,#0xfa
      0010B7 F8               [12] 3671 	mov	r0,a
      0010B8 86 82            [24] 3672 	mov	dpl, @r0
      0010BA 08               [12] 3673 	inc	r0
      0010BB 86 83            [24] 3674 	mov	dph, @r0
      0010BD 08               [12] 3675 	inc	r0
      0010BE 86 F0            [24] 3676 	mov	b, @r0
      0010C0 08               [12] 3677 	inc	r0
      0010C1 E6               [12] 3678 	mov	a, @r0
      0010C2 12 22 FF         [24] 3679 	lcall	___fssub
      0010C5 AF 82            [24] 3680 	mov	r7, dpl
      0010C7 AE 83            [24] 3681 	mov	r6, dph
      0010C9 AD F0            [24] 3682 	mov	r5, b
      0010CB FC               [12] 3683 	mov	r4, a
      0010CC E5 81            [12] 3684 	mov	a,sp
      0010CE 24 FC            [12] 3685 	add	a,#0xfc
      0010D0 F5 81            [12] 3686 	mov	sp,a
      0010D2 C0 07            [24] 3687 	push	ar7
      0010D4 C0 06            [24] 3688 	push	ar6
      0010D6 C0 05            [24] 3689 	push	ar5
      0010D8 C0 04            [24] 3690 	push	ar4
      0010DA E5 08            [12] 3691 	mov	a,_bp
      0010DC 24 11            [12] 3692 	add	a,#0x11
      0010DE F8               [12] 3693 	mov	r0,a
      0010DF E6               [12] 3694 	mov	a,@r0
      0010E0 C0 E0            [24] 3695 	push	acc
      0010E2 08               [12] 3696 	inc	r0
      0010E3 E6               [12] 3697 	mov	a,@r0
      0010E4 C0 E0            [24] 3698 	push	acc
      0010E6 08               [12] 3699 	inc	r0
      0010E7 E6               [12] 3700 	mov	a,@r0
      0010E8 C0 E0            [24] 3701 	push	acc
      0010EA 08               [12] 3702 	inc	r0
      0010EB E6               [12] 3703 	mov	a,@r0
      0010EC C0 E0            [24] 3704 	push	acc
      0010EE E5 08            [12] 3705 	mov	a,_bp
      0010F0 24 15            [12] 3706 	add	a,#0x15
      0010F2 F8               [12] 3707 	mov	r0,a
      0010F3 86 82            [24] 3708 	mov	dpl, @r0
      0010F5 08               [12] 3709 	inc	r0
      0010F6 86 83            [24] 3710 	mov	dph, @r0
      0010F8 08               [12] 3711 	inc	r0
      0010F9 86 F0            [24] 3712 	mov	b, @r0
      0010FB 08               [12] 3713 	inc	r0
      0010FC E6               [12] 3714 	mov	a, @r0
      0010FD 12 22 FF         [24] 3715 	lcall	___fssub
      001100 C8               [12] 3716 	xch	a,r0
      001101 E5 08            [12] 3717 	mov	a,_bp
      001103 24 09            [12] 3718 	add	a,#0x09
      001105 C8               [12] 3719 	xch	a,r0
      001106 A6 82            [24] 3720 	mov	@r0, dpl
      001108 08               [12] 3721 	inc	r0
      001109 A6 83            [24] 3722 	mov	@r0, dph
      00110B 08               [12] 3723 	inc	r0
      00110C A6 F0            [24] 3724 	mov	@r0, b
      00110E 08               [12] 3725 	inc	r0
      00110F F6               [12] 3726 	mov	@r0,a
      001110 E5 81            [12] 3727 	mov	a,sp
      001112 24 FC            [12] 3728 	add	a,#0xfc
      001114 F5 81            [12] 3729 	mov	sp,a
      001116 D0 04            [24] 3730 	pop	ar4
      001118 D0 05            [24] 3731 	pop	ar5
      00111A D0 06            [24] 3732 	pop	ar6
      00111C D0 07            [24] 3733 	pop	ar7
      00111E E5 08            [12] 3734 	mov	a,_bp
      001120 24 09            [12] 3735 	add	a,#0x09
      001122 F8               [12] 3736 	mov	r0,a
      001123 E6               [12] 3737 	mov	a,@r0
      001124 C0 E0            [24] 3738 	push	acc
      001126 08               [12] 3739 	inc	r0
      001127 E6               [12] 3740 	mov	a,@r0
      001128 C0 E0            [24] 3741 	push	acc
      00112A 08               [12] 3742 	inc	r0
      00112B E6               [12] 3743 	mov	a,@r0
      00112C C0 E0            [24] 3744 	push	acc
      00112E 08               [12] 3745 	inc	r0
      00112F E6               [12] 3746 	mov	a,@r0
      001130 C0 E0            [24] 3747 	push	acc
      001132 8F 82            [24] 3748 	mov	dpl, r7
      001134 8E 83            [24] 3749 	mov	dph, r6
      001136 8D F0            [24] 3750 	mov	b, r5
      001138 EC               [12] 3751 	mov	a, r4
      001139 12 25 A3         [24] 3752 	lcall	___fsdiv
      00113C C8               [12] 3753 	xch	a,r0
      00113D E5 08            [12] 3754 	mov	a,_bp
      00113F 24 05            [12] 3755 	add	a,#0x05
      001141 C8               [12] 3756 	xch	a,r0
      001142 A6 82            [24] 3757 	mov	@r0, dpl
      001144 08               [12] 3758 	inc	r0
      001145 A6 83            [24] 3759 	mov	@r0, dph
      001147 08               [12] 3760 	inc	r0
      001148 A6 F0            [24] 3761 	mov	@r0, b
      00114A 08               [12] 3762 	inc	r0
      00114B F6               [12] 3763 	mov	@r0,a
      00114C E5 81            [12] 3764 	mov	a,sp
      00114E 24 FC            [12] 3765 	add	a,#0xfc
      001150 F5 81            [12] 3766 	mov	sp,a
      001152 02 16 33         [24] 3767 	ljmp	00144$
      001155                       3768 00110$:
                           00109E  3769 	C$fuzzy.h$1199$1_0$66 ==.
                                   3770 ;	../../fuzzy.h:1199: (parameter_3 - value) /
      001155 C0 07            [24] 3771 	push	ar7
      001157 C0 06            [24] 3772 	push	ar6
      001159 C0 05            [24] 3773 	push	ar5
      00115B C0 04            [24] 3774 	push	ar4
      00115D E5 08            [12] 3775 	mov	a,_bp
      00115F 24 FA            [12] 3776 	add	a,#0xfa
      001161 F8               [12] 3777 	mov	r0,a
      001162 E6               [12] 3778 	mov	a,@r0
      001163 C0 E0            [24] 3779 	push	acc
      001165 08               [12] 3780 	inc	r0
      001166 E6               [12] 3781 	mov	a,@r0
      001167 C0 E0            [24] 3782 	push	acc
      001169 08               [12] 3783 	inc	r0
      00116A E6               [12] 3784 	mov	a,@r0
      00116B C0 E0            [24] 3785 	push	acc
      00116D 08               [12] 3786 	inc	r0
      00116E E6               [12] 3787 	mov	a,@r0
      00116F C0 E0            [24] 3788 	push	acc
                           0010BA  3789 	C$fuzzy.h$1200$1_0$66 ==.
                                   3790 ;	../../fuzzy.h:1200: (parameter_3 - parameter_2);
      001171 8D 82            [24] 3791 	mov	dpl, r5
      001173 8E 83            [24] 3792 	mov	dph, r6
      001175 8F F0            [24] 3793 	mov	b, r7
      001177 EC               [12] 3794 	mov	a, r4
      001178 12 22 FF         [24] 3795 	lcall	___fssub
      00117B A8 08            [24] 3796 	mov	r0,_bp
      00117D 08               [12] 3797 	inc	r0
      00117E A6 82            [24] 3798 	mov	@r0, dpl
      001180 08               [12] 3799 	inc	r0
      001181 A6 83            [24] 3800 	mov	@r0, dph
      001183 08               [12] 3801 	inc	r0
      001184 A6 F0            [24] 3802 	mov	@r0, b
      001186 08               [12] 3803 	inc	r0
      001187 F6               [12] 3804 	mov	@r0,a
      001188 E5 81            [12] 3805 	mov	a,sp
      00118A 24 FC            [12] 3806 	add	a,#0xfc
      00118C F5 81            [12] 3807 	mov	sp,a
      00118E D0 04            [24] 3808 	pop	ar4
      001190 D0 05            [24] 3809 	pop	ar5
      001192 D0 06            [24] 3810 	pop	ar6
      001194 D0 07            [24] 3811 	pop	ar7
      001196 E5 08            [12] 3812 	mov	a,_bp
      001198 24 15            [12] 3813 	add	a,#0x15
      00119A F8               [12] 3814 	mov	r0,a
      00119B E6               [12] 3815 	mov	a,@r0
      00119C C0 E0            [24] 3816 	push	acc
      00119E 08               [12] 3817 	inc	r0
      00119F E6               [12] 3818 	mov	a,@r0
      0011A0 C0 E0            [24] 3819 	push	acc
      0011A2 08               [12] 3820 	inc	r0
      0011A3 E6               [12] 3821 	mov	a,@r0
      0011A4 C0 E0            [24] 3822 	push	acc
      0011A6 08               [12] 3823 	inc	r0
      0011A7 E6               [12] 3824 	mov	a,@r0
      0011A8 C0 E0            [24] 3825 	push	acc
      0011AA 8D 82            [24] 3826 	mov	dpl, r5
      0011AC 8E 83            [24] 3827 	mov	dph, r6
      0011AE 8F F0            [24] 3828 	mov	b, r7
      0011B0 EC               [12] 3829 	mov	a, r4
      0011B1 12 22 FF         [24] 3830 	lcall	___fssub
      0011B4 AC 82            [24] 3831 	mov	r4, dpl
      0011B6 AD 83            [24] 3832 	mov	r5, dph
      0011B8 AE F0            [24] 3833 	mov	r6, b
      0011BA FF               [12] 3834 	mov	r7, a
      0011BB E5 81            [12] 3835 	mov	a,sp
      0011BD 24 FC            [12] 3836 	add	a,#0xfc
      0011BF F5 81            [12] 3837 	mov	sp,a
      0011C1 C0 04            [24] 3838 	push	ar4
      0011C3 C0 05            [24] 3839 	push	ar5
      0011C5 C0 06            [24] 3840 	push	ar6
      0011C7 C0 07            [24] 3841 	push	ar7
                           001112  3842 	C$fuzzy.h$1202$1_0$66 ==.
                                   3843 ;	../../fuzzy.h:1202: break;
      0011C9 A8 08            [24] 3844 	mov	r0,_bp
      0011CB 08               [12] 3845 	inc	r0
      0011CC 86 82            [24] 3846 	mov	dpl, @r0
      0011CE 08               [12] 3847 	inc	r0
      0011CF 86 83            [24] 3848 	mov	dph, @r0
      0011D1 08               [12] 3849 	inc	r0
      0011D2 86 F0            [24] 3850 	mov	b, @r0
      0011D4 08               [12] 3851 	inc	r0
      0011D5 E6               [12] 3852 	mov	a, @r0
      0011D6 12 25 A3         [24] 3853 	lcall	___fsdiv
      0011D9 C8               [12] 3854 	xch	a,r0
      0011DA E5 08            [12] 3855 	mov	a,_bp
      0011DC 24 05            [12] 3856 	add	a,#0x05
      0011DE C8               [12] 3857 	xch	a,r0
      0011DF A6 82            [24] 3858 	mov	@r0, dpl
      0011E1 08               [12] 3859 	inc	r0
      0011E2 A6 83            [24] 3860 	mov	@r0, dph
      0011E4 08               [12] 3861 	inc	r0
      0011E5 A6 F0            [24] 3862 	mov	@r0, b
      0011E7 08               [12] 3863 	inc	r0
      0011E8 F6               [12] 3864 	mov	@r0,a
      0011E9 E5 81            [12] 3865 	mov	a,sp
      0011EB 24 FC            [12] 3866 	add	a,#0xfc
      0011ED F5 81            [12] 3867 	mov	sp,a
      0011EF 02 16 33         [24] 3868 	ljmp	00144$
                           00113B  3869 	C$fuzzy.h$1204$2_0$68 ==.
                                   3870 ;	../../fuzzy.h:1204: case FUZZY_SHAPE_TRAPEZOID:
      0011F2                       3871 00121$:
                           00113B  3872 	C$fuzzy.h$1205$2_0$68 ==.
                                   3873 ;	../../fuzzy.h:1205: if (parameter_count != 4u) {
      0011F2 E5 08            [12] 3874 	mov	a,_bp
      0011F4 24 F7            [12] 3875 	add	a,#0xf7
      0011F6 F8               [12] 3876 	mov	r0,a
      0011F7 B6 04 06         [24] 3877 	cjne	@r0,#0x04,00279$
      0011FA 08               [12] 3878 	inc	r0
      0011FB B6 00 02         [24] 3879 	cjne	@r0,#0x00,00279$
      0011FE 80 09            [24] 3880 	sjmp	00123$
      001200                       3881 00279$:
                           001149  3882 	C$fuzzy.h$1206$3_0$75 ==.
                                   3883 ;	../../fuzzy.h:1206: return LEVEL_LO;
      001200 90 00 00         [24] 3884 	mov	dptr,#0x0000
      001203 E4               [12] 3885 	clr	a
      001204 F5 F0            [12] 3886 	mov	b,a
      001206 02 16 5D         [24] 3887 	ljmp	00145$
      001209                       3888 00123$:
                           001152  3889 	C$fuzzy.h$1209$2_0$68 ==.
                                   3890 ;	../../fuzzy.h:1209: parameter_1 = parameters[0];
      001209 E5 08            [12] 3891 	mov	a,_bp
      00120B 24 F4            [12] 3892 	add	a,#0xf4
      00120D F8               [12] 3893 	mov	r0,a
      00120E 86 05            [24] 3894 	mov	ar5,@r0
      001210 08               [12] 3895 	inc	r0
      001211 86 06            [24] 3896 	mov	ar6,@r0
      001213 08               [12] 3897 	inc	r0
      001214 86 07            [24] 3898 	mov	ar7,@r0
      001216 8D 82            [24] 3899 	mov	dpl,r5
      001218 8E 83            [24] 3900 	mov	dph,r6
      00121A 8F F0            [24] 3901 	mov	b,r7
      00121C E5 08            [12] 3902 	mov	a,_bp
      00121E 24 09            [12] 3903 	add	a,#0x09
      001220 F8               [12] 3904 	mov	r0,a
      001221 12 26 66         [24] 3905 	lcall	__gptrget
      001224 F6               [12] 3906 	mov	@r0,a
      001225 A3               [24] 3907 	inc	dptr
      001226 12 26 66         [24] 3908 	lcall	__gptrget
      001229 08               [12] 3909 	inc	r0
      00122A F6               [12] 3910 	mov	@r0,a
      00122B A3               [24] 3911 	inc	dptr
      00122C 12 26 66         [24] 3912 	lcall	__gptrget
      00122F 08               [12] 3913 	inc	r0
      001230 F6               [12] 3914 	mov	@r0,a
      001231 A3               [24] 3915 	inc	dptr
      001232 12 26 66         [24] 3916 	lcall	__gptrget
      001235 08               [12] 3917 	inc	r0
      001236 F6               [12] 3918 	mov	@r0,a
                           001180  3919 	C$fuzzy.h$1210$2_0$68 ==.
                                   3920 ;	../../fuzzy.h:1210: parameter_2 = parameters[1];
      001237 74 04            [12] 3921 	mov	a,#0x04
      001239 2D               [12] 3922 	add	a, r5
      00123A FA               [12] 3923 	mov	r2,a
      00123B E4               [12] 3924 	clr	a
      00123C 3E               [12] 3925 	addc	a, r6
      00123D FB               [12] 3926 	mov	r3,a
      00123E 8F 04            [24] 3927 	mov	ar4,r7
      001240 8A 82            [24] 3928 	mov	dpl,r2
      001242 8B 83            [24] 3929 	mov	dph,r3
      001244 8C F0            [24] 3930 	mov	b,r4
      001246 A8 08            [24] 3931 	mov	r0,_bp
      001248 08               [12] 3932 	inc	r0
      001249 12 26 66         [24] 3933 	lcall	__gptrget
      00124C F6               [12] 3934 	mov	@r0,a
      00124D A3               [24] 3935 	inc	dptr
      00124E 12 26 66         [24] 3936 	lcall	__gptrget
      001251 08               [12] 3937 	inc	r0
      001252 F6               [12] 3938 	mov	@r0,a
      001253 A3               [24] 3939 	inc	dptr
      001254 12 26 66         [24] 3940 	lcall	__gptrget
      001257 08               [12] 3941 	inc	r0
      001258 F6               [12] 3942 	mov	@r0,a
      001259 A3               [24] 3943 	inc	dptr
      00125A 12 26 66         [24] 3944 	lcall	__gptrget
      00125D 08               [12] 3945 	inc	r0
      00125E F6               [12] 3946 	mov	@r0,a
                           0011A8  3947 	C$fuzzy.h$1211$2_0$68 ==.
                                   3948 ;	../../fuzzy.h:1211: parameter_3 = parameters[2];
      00125F 74 08            [12] 3949 	mov	a,#0x08
      001261 2D               [12] 3950 	add	a, r5
      001262 FA               [12] 3951 	mov	r2,a
      001263 E4               [12] 3952 	clr	a
      001264 3E               [12] 3953 	addc	a, r6
      001265 FB               [12] 3954 	mov	r3,a
      001266 8F 04            [24] 3955 	mov	ar4,r7
      001268 8A 82            [24] 3956 	mov	dpl,r2
      00126A 8B 83            [24] 3957 	mov	dph,r3
      00126C 8C F0            [24] 3958 	mov	b,r4
      00126E E5 08            [12] 3959 	mov	a,_bp
      001270 24 19            [12] 3960 	add	a,#0x19
      001272 F8               [12] 3961 	mov	r0,a
      001273 12 26 66         [24] 3962 	lcall	__gptrget
      001276 F6               [12] 3963 	mov	@r0,a
      001277 A3               [24] 3964 	inc	dptr
      001278 12 26 66         [24] 3965 	lcall	__gptrget
      00127B 08               [12] 3966 	inc	r0
      00127C F6               [12] 3967 	mov	@r0,a
      00127D A3               [24] 3968 	inc	dptr
      00127E 12 26 66         [24] 3969 	lcall	__gptrget
      001281 08               [12] 3970 	inc	r0
      001282 F6               [12] 3971 	mov	@r0,a
      001283 A3               [24] 3972 	inc	dptr
      001284 12 26 66         [24] 3973 	lcall	__gptrget
      001287 08               [12] 3974 	inc	r0
      001288 F6               [12] 3975 	mov	@r0,a
                           0011D2  3976 	C$fuzzy.h$1212$2_0$68 ==.
                                   3977 ;	../../fuzzy.h:1212: parameter_4 = parameters[3];
      001289 74 0C            [12] 3978 	mov	a,#0x0c
      00128B 2D               [12] 3979 	add	a, r5
      00128C FD               [12] 3980 	mov	r5,a
      00128D E4               [12] 3981 	clr	a
      00128E 3E               [12] 3982 	addc	a, r6
      00128F FE               [12] 3983 	mov	r6,a
      001290 8D 82            [24] 3984 	mov	dpl,r5
      001292 8E 83            [24] 3985 	mov	dph,r6
      001294 8F F0            [24] 3986 	mov	b,r7
      001296 12 26 66         [24] 3987 	lcall	__gptrget
      001299 FD               [12] 3988 	mov	r5,a
      00129A A3               [24] 3989 	inc	dptr
      00129B 12 26 66         [24] 3990 	lcall	__gptrget
      00129E FE               [12] 3991 	mov	r6,a
      00129F A3               [24] 3992 	inc	dptr
      0012A0 12 26 66         [24] 3993 	lcall	__gptrget
      0012A3 FF               [12] 3994 	mov	r7,a
      0012A4 A3               [24] 3995 	inc	dptr
      0012A5 12 26 66         [24] 3996 	lcall	__gptrget
      0012A8 FC               [12] 3997 	mov	r4,a
                           0011F2  3998 	C$fuzzy.h$1215$1_0$66 ==.
                                   3999 ;	../../fuzzy.h:1215: parameter_1 >= parameter_2 ||
      0012A9 C0 07            [24] 4000 	push	ar7
      0012AB C0 06            [24] 4001 	push	ar6
      0012AD C0 05            [24] 4002 	push	ar5
      0012AF C0 04            [24] 4003 	push	ar4
      0012B1 A8 08            [24] 4004 	mov	r0,_bp
      0012B3 08               [12] 4005 	inc	r0
      0012B4 E6               [12] 4006 	mov	a,@r0
      0012B5 C0 E0            [24] 4007 	push	acc
      0012B7 08               [12] 4008 	inc	r0
      0012B8 E6               [12] 4009 	mov	a,@r0
      0012B9 C0 E0            [24] 4010 	push	acc
      0012BB 08               [12] 4011 	inc	r0
      0012BC E6               [12] 4012 	mov	a,@r0
      0012BD C0 E0            [24] 4013 	push	acc
      0012BF 08               [12] 4014 	inc	r0
      0012C0 E6               [12] 4015 	mov	a,@r0
      0012C1 C0 E0            [24] 4016 	push	acc
      0012C3 E5 08            [12] 4017 	mov	a,_bp
      0012C5 24 09            [12] 4018 	add	a,#0x09
      0012C7 F8               [12] 4019 	mov	r0,a
      0012C8 86 82            [24] 4020 	mov	dpl, @r0
      0012CA 08               [12] 4021 	inc	r0
      0012CB 86 83            [24] 4022 	mov	dph, @r0
      0012CD 08               [12] 4023 	inc	r0
      0012CE 86 F0            [24] 4024 	mov	b, @r0
      0012D0 08               [12] 4025 	inc	r0
      0012D1 E6               [12] 4026 	mov	a, @r0
      0012D2 12 24 3A         [24] 4027 	lcall	___fslt
      0012D5 E5 81            [12] 4028 	mov	a,sp
      0012D7 24 FC            [12] 4029 	add	a,#0xfc
      0012D9 F5 81            [12] 4030 	mov	sp,a
      0012DB D0 04            [24] 4031 	pop	ar4
      0012DD D0 05            [24] 4032 	pop	ar5
      0012DF D0 06            [24] 4033 	pop	ar6
      0012E1 D0 07            [24] 4034 	pop	ar7
      0012E3 E5 82            [12] 4035 	mov	a, dpl
      0012E5 24 FF            [12] 4036 	add	a,#0xff
      0012E7 92 00            [24] 4037 	mov	b0,c
      0012E9 40 03            [24] 4038 	jc	00280$
      0012EB 02 13 E4         [24] 4039 	ljmp	00131$
      0012EE                       4040 00280$:
                           001237  4041 	C$fuzzy.h$1216$1_0$66 ==.
                                   4042 ;	../../fuzzy.h:1216: parameter_2 > parameter_3 ||
      0012EE C0 07            [24] 4043 	push	ar7
      0012F0 C0 06            [24] 4044 	push	ar6
      0012F2 C0 05            [24] 4045 	push	ar5
      0012F4 C0 04            [24] 4046 	push	ar4
      0012F6 A8 08            [24] 4047 	mov	r0,_bp
      0012F8 08               [12] 4048 	inc	r0
      0012F9 E6               [12] 4049 	mov	a,@r0
      0012FA C0 E0            [24] 4050 	push	acc
      0012FC 08               [12] 4051 	inc	r0
      0012FD E6               [12] 4052 	mov	a,@r0
      0012FE C0 E0            [24] 4053 	push	acc
      001300 08               [12] 4054 	inc	r0
      001301 E6               [12] 4055 	mov	a,@r0
      001302 C0 E0            [24] 4056 	push	acc
      001304 08               [12] 4057 	inc	r0
      001305 E6               [12] 4058 	mov	a,@r0
      001306 C0 E0            [24] 4059 	push	acc
      001308 E5 08            [12] 4060 	mov	a,_bp
      00130A 24 19            [12] 4061 	add	a,#0x19
      00130C F8               [12] 4062 	mov	r0,a
      00130D 86 82            [24] 4063 	mov	dpl, @r0
      00130F 08               [12] 4064 	inc	r0
      001310 86 83            [24] 4065 	mov	dph, @r0
      001312 08               [12] 4066 	inc	r0
      001313 86 F0            [24] 4067 	mov	b, @r0
      001315 08               [12] 4068 	inc	r0
      001316 E6               [12] 4069 	mov	a, @r0
      001317 12 24 3A         [24] 4070 	lcall	___fslt
      00131A AB 82            [24] 4071 	mov	r3, dpl
      00131C E5 81            [12] 4072 	mov	a,sp
      00131E 24 FC            [12] 4073 	add	a,#0xfc
      001320 F5 81            [12] 4074 	mov	sp,a
      001322 D0 04            [24] 4075 	pop	ar4
      001324 D0 05            [24] 4076 	pop	ar5
      001326 D0 06            [24] 4077 	pop	ar6
      001328 D0 07            [24] 4078 	pop	ar7
      00132A EB               [12] 4079 	mov	a,r3
      00132B 60 03            [24] 4080 	jz	00281$
      00132D 02 13 E4         [24] 4081 	ljmp	00131$
      001330                       4082 00281$:
                           001279  4083 	C$fuzzy.h$1217$1_0$66 ==.
                                   4084 ;	../../fuzzy.h:1217: parameter_3 >= parameter_4 ||
      001330 C0 07            [24] 4085 	push	ar7
      001332 C0 06            [24] 4086 	push	ar6
      001334 C0 05            [24] 4087 	push	ar5
      001336 C0 04            [24] 4088 	push	ar4
      001338 C0 05            [24] 4089 	push	ar5
      00133A C0 06            [24] 4090 	push	ar6
      00133C C0 07            [24] 4091 	push	ar7
      00133E C0 04            [24] 4092 	push	ar4
      001340 E5 08            [12] 4093 	mov	a,_bp
      001342 24 19            [12] 4094 	add	a,#0x19
      001344 F8               [12] 4095 	mov	r0,a
      001345 86 82            [24] 4096 	mov	dpl, @r0
      001347 08               [12] 4097 	inc	r0
      001348 86 83            [24] 4098 	mov	dph, @r0
      00134A 08               [12] 4099 	inc	r0
      00134B 86 F0            [24] 4100 	mov	b, @r0
      00134D 08               [12] 4101 	inc	r0
      00134E E6               [12] 4102 	mov	a, @r0
      00134F 12 24 3A         [24] 4103 	lcall	___fslt
      001352 E5 81            [12] 4104 	mov	a,sp
      001354 24 FC            [12] 4105 	add	a,#0xfc
      001356 F5 81            [12] 4106 	mov	sp,a
      001358 D0 04            [24] 4107 	pop	ar4
      00135A D0 05            [24] 4108 	pop	ar5
      00135C D0 06            [24] 4109 	pop	ar6
      00135E D0 07            [24] 4110 	pop	ar7
      001360 E5 82            [12] 4111 	mov	a, dpl
      001362 24 FF            [12] 4112 	add	a,#0xff
      001364 92 00            [24] 4113 	mov	b0,c
      001366 50 7C            [24] 4114 	jnc	00131$
                           0012B1  4115 	C$fuzzy.h$1218$1_0$66 ==.
                                   4116 ;	../../fuzzy.h:1218: value <= parameter_1 ||
      001368 C0 07            [24] 4117 	push	ar7
      00136A C0 06            [24] 4118 	push	ar6
      00136C C0 05            [24] 4119 	push	ar5
      00136E C0 04            [24] 4120 	push	ar4
      001370 E5 08            [12] 4121 	mov	a,_bp
      001372 24 FA            [12] 4122 	add	a,#0xfa
      001374 F8               [12] 4123 	mov	r0,a
      001375 E6               [12] 4124 	mov	a,@r0
      001376 C0 E0            [24] 4125 	push	acc
      001378 08               [12] 4126 	inc	r0
      001379 E6               [12] 4127 	mov	a,@r0
      00137A C0 E0            [24] 4128 	push	acc
      00137C 08               [12] 4129 	inc	r0
      00137D E6               [12] 4130 	mov	a,@r0
      00137E C0 E0            [24] 4131 	push	acc
      001380 08               [12] 4132 	inc	r0
      001381 E6               [12] 4133 	mov	a,@r0
      001382 C0 E0            [24] 4134 	push	acc
      001384 E5 08            [12] 4135 	mov	a,_bp
      001386 24 09            [12] 4136 	add	a,#0x09
      001388 F8               [12] 4137 	mov	r0,a
      001389 86 82            [24] 4138 	mov	dpl, @r0
      00138B 08               [12] 4139 	inc	r0
      00138C 86 83            [24] 4140 	mov	dph, @r0
      00138E 08               [12] 4141 	inc	r0
      00138F 86 F0            [24] 4142 	mov	b, @r0
      001391 08               [12] 4143 	inc	r0
      001392 E6               [12] 4144 	mov	a, @r0
      001393 12 24 3A         [24] 4145 	lcall	___fslt
      001396 E5 81            [12] 4146 	mov	a,sp
      001398 24 FC            [12] 4147 	add	a,#0xfc
      00139A F5 81            [12] 4148 	mov	sp,a
      00139C D0 04            [24] 4149 	pop	ar4
      00139E D0 05            [24] 4150 	pop	ar5
      0013A0 D0 06            [24] 4151 	pop	ar6
      0013A2 D0 07            [24] 4152 	pop	ar7
      0013A4 E5 82            [12] 4153 	mov	a, dpl
      0013A6 24 FF            [12] 4154 	add	a,#0xff
      0013A8 92 00            [24] 4155 	mov	b0,c
      0013AA 50 38            [24] 4156 	jnc	00131$
                           0012F5  4157 	C$fuzzy.h$1220$1_0$66 ==.
                                   4158 ;	../../fuzzy.h:1220: ) {
      0013AC C0 07            [24] 4159 	push	ar7
      0013AE C0 06            [24] 4160 	push	ar6
      0013B0 C0 05            [24] 4161 	push	ar5
      0013B2 C0 04            [24] 4162 	push	ar4
      0013B4 C0 05            [24] 4163 	push	ar5
      0013B6 C0 06            [24] 4164 	push	ar6
      0013B8 C0 07            [24] 4165 	push	ar7
      0013BA C0 04            [24] 4166 	push	ar4
      0013BC E5 08            [12] 4167 	mov	a,_bp
      0013BE 24 FA            [12] 4168 	add	a,#0xfa
      0013C0 F8               [12] 4169 	mov	r0,a
      0013C1 86 82            [24] 4170 	mov	dpl, @r0
      0013C3 08               [12] 4171 	inc	r0
      0013C4 86 83            [24] 4172 	mov	dph, @r0
      0013C6 08               [12] 4173 	inc	r0
      0013C7 86 F0            [24] 4174 	mov	b, @r0
      0013C9 08               [12] 4175 	inc	r0
      0013CA E6               [12] 4176 	mov	a, @r0
      0013CB 12 24 3A         [24] 4177 	lcall	___fslt
      0013CE E5 81            [12] 4178 	mov	a,sp
      0013D0 24 FC            [12] 4179 	add	a,#0xfc
      0013D2 F5 81            [12] 4180 	mov	sp,a
      0013D4 D0 04            [24] 4181 	pop	ar4
      0013D6 D0 05            [24] 4182 	pop	ar5
      0013D8 D0 06            [24] 4183 	pop	ar6
      0013DA D0 07            [24] 4184 	pop	ar7
      0013DC E5 82            [12] 4185 	mov	a, dpl
      0013DE 24 FF            [12] 4186 	add	a,#0xff
      0013E0 92 00            [24] 4187 	mov	b0,c
      0013E2 40 10            [24] 4188 	jc	00132$
      0013E4                       4189 00131$:
                           00132D  4190 	C$fuzzy.h$1221$3_0$76 ==.
                                   4191 ;	../../fuzzy.h:1221: result = LEVEL_LO;
      0013E4 E5 08            [12] 4192 	mov	a,_bp
      0013E6 24 05            [12] 4193 	add	a,#0x05
      0013E8 F8               [12] 4194 	mov	r0,a
      0013E9 E4               [12] 4195 	clr	a
      0013EA F6               [12] 4196 	mov	@r0,a
      0013EB 08               [12] 4197 	inc	r0
      0013EC F6               [12] 4198 	mov	@r0,a
      0013ED 08               [12] 4199 	inc	r0
      0013EE F6               [12] 4200 	mov	@r0,a
      0013EF 08               [12] 4201 	inc	r0
      0013F0 F6               [12] 4202 	mov	@r0,a
      0013F1 02 16 33         [24] 4203 	ljmp	00144$
      0013F4                       4204 00132$:
                           00133D  4205 	C$fuzzy.h$1224$1_0$66 ==.
                                   4206 ;	../../fuzzy.h:1224: value >= parameter_2 &&
      0013F4 C0 07            [24] 4207 	push	ar7
      0013F6 C0 06            [24] 4208 	push	ar6
      0013F8 C0 05            [24] 4209 	push	ar5
      0013FA C0 04            [24] 4210 	push	ar4
      0013FC A8 08            [24] 4211 	mov	r0,_bp
      0013FE 08               [12] 4212 	inc	r0
      0013FF E6               [12] 4213 	mov	a,@r0
      001400 C0 E0            [24] 4214 	push	acc
      001402 08               [12] 4215 	inc	r0
      001403 E6               [12] 4216 	mov	a,@r0
      001404 C0 E0            [24] 4217 	push	acc
      001406 08               [12] 4218 	inc	r0
      001407 E6               [12] 4219 	mov	a,@r0
      001408 C0 E0            [24] 4220 	push	acc
      00140A 08               [12] 4221 	inc	r0
      00140B E6               [12] 4222 	mov	a,@r0
      00140C C0 E0            [24] 4223 	push	acc
      00140E E5 08            [12] 4224 	mov	a,_bp
      001410 24 FA            [12] 4225 	add	a,#0xfa
      001412 F8               [12] 4226 	mov	r0,a
      001413 86 82            [24] 4227 	mov	dpl, @r0
      001415 08               [12] 4228 	inc	r0
      001416 86 83            [24] 4229 	mov	dph, @r0
      001418 08               [12] 4230 	inc	r0
      001419 86 F0            [24] 4231 	mov	b, @r0
      00141B 08               [12] 4232 	inc	r0
      00141C E6               [12] 4233 	mov	a, @r0
      00141D 12 24 3A         [24] 4234 	lcall	___fslt
      001420 E5 81            [12] 4235 	mov	a,sp
      001422 24 FC            [12] 4236 	add	a,#0xfc
      001424 F5 81            [12] 4237 	mov	sp,a
      001426 D0 04            [24] 4238 	pop	ar4
      001428 D0 05            [24] 4239 	pop	ar5
      00142A D0 06            [24] 4240 	pop	ar6
      00142C D0 07            [24] 4241 	pop	ar7
      00142E E5 82            [12] 4242 	mov	a, dpl
      001430 24 FF            [12] 4243 	add	a,#0xff
      001432 92 00            [24] 4244 	mov	b0,c
      001434 40 56            [24] 4245 	jc	00128$
                           00137F  4246 	C$fuzzy.h$1226$1_0$66 ==.
                                   4247 ;	../../fuzzy.h:1226: ) {
      001436 C0 07            [24] 4248 	push	ar7
      001438 C0 06            [24] 4249 	push	ar6
      00143A C0 05            [24] 4250 	push	ar5
      00143C C0 04            [24] 4251 	push	ar4
      00143E E5 08            [12] 4252 	mov	a,_bp
      001440 24 FA            [12] 4253 	add	a,#0xfa
      001442 F8               [12] 4254 	mov	r0,a
      001443 E6               [12] 4255 	mov	a,@r0
      001444 C0 E0            [24] 4256 	push	acc
      001446 08               [12] 4257 	inc	r0
      001447 E6               [12] 4258 	mov	a,@r0
      001448 C0 E0            [24] 4259 	push	acc
      00144A 08               [12] 4260 	inc	r0
      00144B E6               [12] 4261 	mov	a,@r0
      00144C C0 E0            [24] 4262 	push	acc
      00144E 08               [12] 4263 	inc	r0
      00144F E6               [12] 4264 	mov	a,@r0
      001450 C0 E0            [24] 4265 	push	acc
      001452 E5 08            [12] 4266 	mov	a,_bp
      001454 24 19            [12] 4267 	add	a,#0x19
      001456 F8               [12] 4268 	mov	r0,a
      001457 86 82            [24] 4269 	mov	dpl, @r0
      001459 08               [12] 4270 	inc	r0
      00145A 86 83            [24] 4271 	mov	dph, @r0
      00145C 08               [12] 4272 	inc	r0
      00145D 86 F0            [24] 4273 	mov	b, @r0
      00145F 08               [12] 4274 	inc	r0
      001460 E6               [12] 4275 	mov	a, @r0
      001461 12 24 3A         [24] 4276 	lcall	___fslt
      001464 E5 81            [12] 4277 	mov	a,sp
      001466 24 FC            [12] 4278 	add	a,#0xfc
      001468 F5 81            [12] 4279 	mov	sp,a
      00146A D0 04            [24] 4280 	pop	ar4
      00146C D0 05            [24] 4281 	pop	ar5
      00146E D0 06            [24] 4282 	pop	ar6
      001470 D0 07            [24] 4283 	pop	ar7
      001472 E5 82            [12] 4284 	mov	a, dpl
      001474 24 FF            [12] 4285 	add	a,#0xff
      001476 92 00            [24] 4286 	mov	b0,c
      001478 40 12            [24] 4287 	jc	00128$
                           0013C3  4288 	C$fuzzy.h$1227$3_0$77 ==.
                                   4289 ;	../../fuzzy.h:1227: result = LEVEL_HI;
      00147A E5 08            [12] 4290 	mov	a,_bp
      00147C 24 05            [12] 4291 	add	a,#0x05
      00147E F8               [12] 4292 	mov	r0,a
      00147F E4               [12] 4293 	clr	a
      001480 F6               [12] 4294 	mov	@r0,a
      001481 08               [12] 4295 	inc	r0
      001482 F6               [12] 4296 	mov	@r0,a
      001483 08               [12] 4297 	inc	r0
      001484 76 80            [12] 4298 	mov	@r0,#0x80
      001486 08               [12] 4299 	inc	r0
      001487 76 3F            [12] 4300 	mov	@r0,#0x3f
      001489 02 16 33         [24] 4301 	ljmp	00144$
      00148C                       4302 00128$:
                           0013D5  4303 	C$fuzzy.h$1229$1_0$66 ==.
                                   4304 ;	../../fuzzy.h:1229: else if (value < parameter_2) {
      00148C C0 07            [24] 4305 	push	ar7
      00148E C0 06            [24] 4306 	push	ar6
      001490 C0 05            [24] 4307 	push	ar5
      001492 C0 04            [24] 4308 	push	ar4
      001494 A8 08            [24] 4309 	mov	r0,_bp
      001496 08               [12] 4310 	inc	r0
      001497 E6               [12] 4311 	mov	a,@r0
      001498 C0 E0            [24] 4312 	push	acc
      00149A 08               [12] 4313 	inc	r0
      00149B E6               [12] 4314 	mov	a,@r0
      00149C C0 E0            [24] 4315 	push	acc
      00149E 08               [12] 4316 	inc	r0
      00149F E6               [12] 4317 	mov	a,@r0
      0014A0 C0 E0            [24] 4318 	push	acc
      0014A2 08               [12] 4319 	inc	r0
      0014A3 E6               [12] 4320 	mov	a,@r0
      0014A4 C0 E0            [24] 4321 	push	acc
      0014A6 E5 08            [12] 4322 	mov	a,_bp
      0014A8 24 FA            [12] 4323 	add	a,#0xfa
      0014AA F8               [12] 4324 	mov	r0,a
      0014AB 86 82            [24] 4325 	mov	dpl, @r0
      0014AD 08               [12] 4326 	inc	r0
      0014AE 86 83            [24] 4327 	mov	dph, @r0
      0014B0 08               [12] 4328 	inc	r0
      0014B1 86 F0            [24] 4329 	mov	b, @r0
      0014B3 08               [12] 4330 	inc	r0
      0014B4 E6               [12] 4331 	mov	a, @r0
      0014B5 12 24 3A         [24] 4332 	lcall	___fslt
      0014B8 AB 82            [24] 4333 	mov	r3, dpl
      0014BA E5 81            [12] 4334 	mov	a,sp
      0014BC 24 FC            [12] 4335 	add	a,#0xfc
      0014BE F5 81            [12] 4336 	mov	sp,a
      0014C0 D0 04            [24] 4337 	pop	ar4
      0014C2 D0 05            [24] 4338 	pop	ar5
      0014C4 D0 06            [24] 4339 	pop	ar6
      0014C6 D0 07            [24] 4340 	pop	ar7
      0014C8 EB               [12] 4341 	mov	a,r3
      0014C9 70 03            [24] 4342 	jnz	00287$
      0014CB 02 15 82         [24] 4343 	ljmp	00125$
      0014CE                       4344 00287$:
                           001417  4345 	C$fuzzy.h$1231$1_0$66 ==.
                                   4346 ;	../../fuzzy.h:1231: (value - parameter_1) /
      0014CE E5 08            [12] 4347 	mov	a,_bp
      0014D0 24 09            [12] 4348 	add	a,#0x09
      0014D2 F8               [12] 4349 	mov	r0,a
      0014D3 E6               [12] 4350 	mov	a,@r0
      0014D4 C0 E0            [24] 4351 	push	acc
      0014D6 08               [12] 4352 	inc	r0
      0014D7 E6               [12] 4353 	mov	a,@r0
      0014D8 C0 E0            [24] 4354 	push	acc
      0014DA 08               [12] 4355 	inc	r0
      0014DB E6               [12] 4356 	mov	a,@r0
      0014DC C0 E0            [24] 4357 	push	acc
      0014DE 08               [12] 4358 	inc	r0
      0014DF E6               [12] 4359 	mov	a,@r0
      0014E0 C0 E0            [24] 4360 	push	acc
                           00142B  4361 	C$fuzzy.h$1232$1_0$66 ==.
                                   4362 ;	../../fuzzy.h:1232: (parameter_2 - parameter_1);
      0014E2 E5 08            [12] 4363 	mov	a,_bp
      0014E4 24 FA            [12] 4364 	add	a,#0xfa
      0014E6 F8               [12] 4365 	mov	r0,a
      0014E7 86 82            [24] 4366 	mov	dpl, @r0
      0014E9 08               [12] 4367 	inc	r0
      0014EA 86 83            [24] 4368 	mov	dph, @r0
      0014EC 08               [12] 4369 	inc	r0
      0014ED 86 F0            [24] 4370 	mov	b, @r0
      0014EF 08               [12] 4371 	inc	r0
      0014F0 E6               [12] 4372 	mov	a, @r0
      0014F1 12 22 FF         [24] 4373 	lcall	___fssub
      0014F4 AF 82            [24] 4374 	mov	r7, dpl
      0014F6 AE 83            [24] 4375 	mov	r6, dph
      0014F8 AD F0            [24] 4376 	mov	r5, b
      0014FA FC               [12] 4377 	mov	r4, a
      0014FB E5 81            [12] 4378 	mov	a,sp
      0014FD 24 FC            [12] 4379 	add	a,#0xfc
      0014FF F5 81            [12] 4380 	mov	sp,a
      001501 C0 07            [24] 4381 	push	ar7
      001503 C0 06            [24] 4382 	push	ar6
      001505 C0 05            [24] 4383 	push	ar5
      001507 C0 04            [24] 4384 	push	ar4
      001509 E5 08            [12] 4385 	mov	a,_bp
      00150B 24 09            [12] 4386 	add	a,#0x09
      00150D F8               [12] 4387 	mov	r0,a
      00150E E6               [12] 4388 	mov	a,@r0
      00150F C0 E0            [24] 4389 	push	acc
      001511 08               [12] 4390 	inc	r0
      001512 E6               [12] 4391 	mov	a,@r0
      001513 C0 E0            [24] 4392 	push	acc
      001515 08               [12] 4393 	inc	r0
      001516 E6               [12] 4394 	mov	a,@r0
      001517 C0 E0            [24] 4395 	push	acc
      001519 08               [12] 4396 	inc	r0
      00151A E6               [12] 4397 	mov	a,@r0
      00151B C0 E0            [24] 4398 	push	acc
      00151D A8 08            [24] 4399 	mov	r0,_bp
      00151F 08               [12] 4400 	inc	r0
      001520 86 82            [24] 4401 	mov	dpl, @r0
      001522 08               [12] 4402 	inc	r0
      001523 86 83            [24] 4403 	mov	dph, @r0
      001525 08               [12] 4404 	inc	r0
      001526 86 F0            [24] 4405 	mov	b, @r0
      001528 08               [12] 4406 	inc	r0
      001529 E6               [12] 4407 	mov	a, @r0
      00152A 12 22 FF         [24] 4408 	lcall	___fssub
      00152D C8               [12] 4409 	xch	a,r0
      00152E E5 08            [12] 4410 	mov	a,_bp
      001530 24 09            [12] 4411 	add	a,#0x09
      001532 C8               [12] 4412 	xch	a,r0
      001533 A6 82            [24] 4413 	mov	@r0, dpl
      001535 08               [12] 4414 	inc	r0
      001536 A6 83            [24] 4415 	mov	@r0, dph
      001538 08               [12] 4416 	inc	r0
      001539 A6 F0            [24] 4417 	mov	@r0, b
      00153B 08               [12] 4418 	inc	r0
      00153C F6               [12] 4419 	mov	@r0,a
      00153D E5 81            [12] 4420 	mov	a,sp
      00153F 24 FC            [12] 4421 	add	a,#0xfc
      001541 F5 81            [12] 4422 	mov	sp,a
      001543 D0 04            [24] 4423 	pop	ar4
      001545 D0 05            [24] 4424 	pop	ar5
      001547 D0 06            [24] 4425 	pop	ar6
      001549 D0 07            [24] 4426 	pop	ar7
      00154B E5 08            [12] 4427 	mov	a,_bp
      00154D 24 09            [12] 4428 	add	a,#0x09
      00154F F8               [12] 4429 	mov	r0,a
      001550 E6               [12] 4430 	mov	a,@r0
      001551 C0 E0            [24] 4431 	push	acc
      001553 08               [12] 4432 	inc	r0
      001554 E6               [12] 4433 	mov	a,@r0
      001555 C0 E0            [24] 4434 	push	acc
      001557 08               [12] 4435 	inc	r0
      001558 E6               [12] 4436 	mov	a,@r0
      001559 C0 E0            [24] 4437 	push	acc
      00155B 08               [12] 4438 	inc	r0
      00155C E6               [12] 4439 	mov	a,@r0
      00155D C0 E0            [24] 4440 	push	acc
      00155F 8F 82            [24] 4441 	mov	dpl, r7
      001561 8E 83            [24] 4442 	mov	dph, r6
      001563 8D F0            [24] 4443 	mov	b, r5
      001565 EC               [12] 4444 	mov	a, r4
      001566 12 25 A3         [24] 4445 	lcall	___fsdiv
      001569 C8               [12] 4446 	xch	a,r0
      00156A E5 08            [12] 4447 	mov	a,_bp
      00156C 24 05            [12] 4448 	add	a,#0x05
      00156E C8               [12] 4449 	xch	a,r0
      00156F A6 82            [24] 4450 	mov	@r0, dpl
      001571 08               [12] 4451 	inc	r0
      001572 A6 83            [24] 4452 	mov	@r0, dph
      001574 08               [12] 4453 	inc	r0
      001575 A6 F0            [24] 4454 	mov	@r0, b
      001577 08               [12] 4455 	inc	r0
      001578 F6               [12] 4456 	mov	@r0,a
      001579 E5 81            [12] 4457 	mov	a,sp
      00157B 24 FC            [12] 4458 	add	a,#0xfc
      00157D F5 81            [12] 4459 	mov	sp,a
      00157F 02 16 33         [24] 4460 	ljmp	00144$
      001582                       4461 00125$:
                           0014CB  4462 	C$fuzzy.h$1236$1_0$66 ==.
                                   4463 ;	../../fuzzy.h:1236: (parameter_4 - value) /
      001582 C0 07            [24] 4464 	push	ar7
      001584 C0 06            [24] 4465 	push	ar6
      001586 C0 05            [24] 4466 	push	ar5
      001588 C0 04            [24] 4467 	push	ar4
      00158A E5 08            [12] 4468 	mov	a,_bp
      00158C 24 FA            [12] 4469 	add	a,#0xfa
      00158E F8               [12] 4470 	mov	r0,a
      00158F E6               [12] 4471 	mov	a,@r0
      001590 C0 E0            [24] 4472 	push	acc
      001592 08               [12] 4473 	inc	r0
      001593 E6               [12] 4474 	mov	a,@r0
      001594 C0 E0            [24] 4475 	push	acc
      001596 08               [12] 4476 	inc	r0
      001597 E6               [12] 4477 	mov	a,@r0
      001598 C0 E0            [24] 4478 	push	acc
      00159A 08               [12] 4479 	inc	r0
      00159B E6               [12] 4480 	mov	a,@r0
      00159C C0 E0            [24] 4481 	push	acc
                           0014E7  4482 	C$fuzzy.h$1237$1_0$66 ==.
                                   4483 ;	../../fuzzy.h:1237: (parameter_4 - parameter_3);
      00159E 8D 82            [24] 4484 	mov	dpl, r5
      0015A0 8E 83            [24] 4485 	mov	dph, r6
      0015A2 8F F0            [24] 4486 	mov	b, r7
      0015A4 EC               [12] 4487 	mov	a, r4
      0015A5 12 22 FF         [24] 4488 	lcall	___fssub
      0015A8 C8               [12] 4489 	xch	a,r0
      0015A9 E5 08            [12] 4490 	mov	a,_bp
      0015AB 24 0D            [12] 4491 	add	a,#0x0d
      0015AD C8               [12] 4492 	xch	a,r0
      0015AE A6 82            [24] 4493 	mov	@r0, dpl
      0015B0 08               [12] 4494 	inc	r0
      0015B1 A6 83            [24] 4495 	mov	@r0, dph
      0015B3 08               [12] 4496 	inc	r0
      0015B4 A6 F0            [24] 4497 	mov	@r0, b
      0015B6 08               [12] 4498 	inc	r0
      0015B7 F6               [12] 4499 	mov	@r0,a
      0015B8 E5 81            [12] 4500 	mov	a,sp
      0015BA 24 FC            [12] 4501 	add	a,#0xfc
      0015BC F5 81            [12] 4502 	mov	sp,a
      0015BE D0 04            [24] 4503 	pop	ar4
      0015C0 D0 05            [24] 4504 	pop	ar5
      0015C2 D0 06            [24] 4505 	pop	ar6
      0015C4 D0 07            [24] 4506 	pop	ar7
      0015C6 E5 08            [12] 4507 	mov	a,_bp
      0015C8 24 19            [12] 4508 	add	a,#0x19
      0015CA F8               [12] 4509 	mov	r0,a
      0015CB E6               [12] 4510 	mov	a,@r0
      0015CC C0 E0            [24] 4511 	push	acc
      0015CE 08               [12] 4512 	inc	r0
      0015CF E6               [12] 4513 	mov	a,@r0
      0015D0 C0 E0            [24] 4514 	push	acc
      0015D2 08               [12] 4515 	inc	r0
      0015D3 E6               [12] 4516 	mov	a,@r0
      0015D4 C0 E0            [24] 4517 	push	acc
      0015D6 08               [12] 4518 	inc	r0
      0015D7 E6               [12] 4519 	mov	a,@r0
      0015D8 C0 E0            [24] 4520 	push	acc
      0015DA 8D 82            [24] 4521 	mov	dpl, r5
      0015DC 8E 83            [24] 4522 	mov	dph, r6
      0015DE 8F F0            [24] 4523 	mov	b, r7
      0015E0 EC               [12] 4524 	mov	a, r4
      0015E1 12 22 FF         [24] 4525 	lcall	___fssub
      0015E4 AC 82            [24] 4526 	mov	r4, dpl
      0015E6 AD 83            [24] 4527 	mov	r5, dph
      0015E8 AE F0            [24] 4528 	mov	r6, b
      0015EA FF               [12] 4529 	mov	r7, a
      0015EB E5 81            [12] 4530 	mov	a,sp
      0015ED 24 FC            [12] 4531 	add	a,#0xfc
      0015EF F5 81            [12] 4532 	mov	sp,a
      0015F1 C0 04            [24] 4533 	push	ar4
      0015F3 C0 05            [24] 4534 	push	ar5
      0015F5 C0 06            [24] 4535 	push	ar6
      0015F7 C0 07            [24] 4536 	push	ar7
                           001542  4537 	C$fuzzy.h$1239$1_0$66 ==.
                                   4538 ;	../../fuzzy.h:1239: break;
      0015F9 E5 08            [12] 4539 	mov	a,_bp
      0015FB 24 0D            [12] 4540 	add	a,#0x0d
      0015FD F8               [12] 4541 	mov	r0,a
      0015FE 86 82            [24] 4542 	mov	dpl, @r0
      001600 08               [12] 4543 	inc	r0
      001601 86 83            [24] 4544 	mov	dph, @r0
      001603 08               [12] 4545 	inc	r0
      001604 86 F0            [24] 4546 	mov	b, @r0
      001606 08               [12] 4547 	inc	r0
      001607 E6               [12] 4548 	mov	a, @r0
      001608 12 25 A3         [24] 4549 	lcall	___fsdiv
      00160B C8               [12] 4550 	xch	a,r0
      00160C E5 08            [12] 4551 	mov	a,_bp
      00160E 24 05            [12] 4552 	add	a,#0x05
      001610 C8               [12] 4553 	xch	a,r0
      001611 A6 82            [24] 4554 	mov	@r0, dpl
      001613 08               [12] 4555 	inc	r0
      001614 A6 83            [24] 4556 	mov	@r0, dph
      001616 08               [12] 4557 	inc	r0
      001617 A6 F0            [24] 4558 	mov	@r0, b
      001619 08               [12] 4559 	inc	r0
      00161A F6               [12] 4560 	mov	@r0,a
      00161B E5 81            [12] 4561 	mov	a,sp
      00161D 24 FC            [12] 4562 	add	a,#0xfc
      00161F F5 81            [12] 4563 	mov	sp,a
                           00156A  4564 	C$fuzzy.h$1385$2_0$68 ==.
                                   4565 ;	../../fuzzy.h:1385: case FUZZY_SHAPE_SIGMOID:
      001621 80 10            [24] 4566 	sjmp	00144$
      001623                       4567 00142$:
                           00156C  4568 	C$fuzzy.h$1386$2_0$68 ==.
                                   4569 ;	../../fuzzy.h:1386: return LEVEL_LO;
      001623 90 00 00         [24] 4570 	mov	dptr,#0x0000
      001626 E4               [12] 4571 	clr	a
      001627 F5 F0            [12] 4572 	mov	b,a
                           001572  4573 	C$fuzzy.h$1390$2_0$68 ==.
                                   4574 ;	../../fuzzy.h:1390: default:
      001629 80 32            [24] 4575 	sjmp	00145$
      00162B                       4576 00143$:
                           001574  4577 	C$fuzzy.h$1391$2_0$68 ==.
                                   4578 ;	../../fuzzy.h:1391: return LEVEL_LO;
      00162B 90 00 00         [24] 4579 	mov	dptr,#0x0000
      00162E E4               [12] 4580 	clr	a
      00162F F5 F0            [12] 4581 	mov	b,a
                           00157A  4582 	C$fuzzy.h$1392$1_0$66 ==.
                                   4583 ;	../../fuzzy.h:1392: }
      001631 80 2A            [24] 4584 	sjmp	00145$
      001633                       4585 00144$:
                           00157C  4586 	C$fuzzy.h$1395$1_0$66 ==.
                                   4587 ;	../../fuzzy.h:1395: result,
      001633 E5 08            [12] 4588 	mov	a,_bp
      001635 24 F9            [12] 4589 	add	a,#0xf9
      001637 F8               [12] 4590 	mov	r0,a
      001638 E6               [12] 4591 	mov	a,@r0
      001639 C0 E0            [24] 4592 	push	acc
      00163B E5 08            [12] 4593 	mov	a,_bp
      00163D 24 05            [12] 4594 	add	a,#0x05
      00163F F8               [12] 4595 	mov	r0,a
      001640 86 82            [24] 4596 	mov	dpl, @r0
      001642 08               [12] 4597 	inc	r0
      001643 86 83            [24] 4598 	mov	dph, @r0
      001645 08               [12] 4599 	inc	r0
      001646 86 F0            [24] 4600 	mov	b, @r0
      001648 08               [12] 4601 	inc	r0
      001649 E6               [12] 4602 	mov	a, @r0
      00164A 12 01 99         [24] 4603 	lcall	_fuzzy_apply_hedge
      00164D AC 82            [24] 4604 	mov	r4, dpl
      00164F AD 83            [24] 4605 	mov	r5, dph
      001651 AE F0            [24] 4606 	mov	r6, b
      001653 FF               [12] 4607 	mov	r7, a
      001654 15 81            [12] 4608 	dec	sp
      001656 8C 82            [24] 4609 	mov	dpl, r4
      001658 8D 83            [24] 4610 	mov	dph, r5
      00165A 8E F0            [24] 4611 	mov	b, r6
      00165C EF               [12] 4612 	mov	a, r7
      00165D                       4613 00145$:
                           0015A6  4614 	C$fuzzy.h$1398$1_0$66 ==.
                                   4615 ;	../../fuzzy.h:1398: }
      00165D 85 08 81         [24] 4616 	mov	sp,_bp
      001660 D0 08            [24] 4617 	pop	_bp
                           0015AB  4618 	C$fuzzy.h$1398$1_0$66 ==.
                           0015AB  4619 	XG$fuzzy_function_array$0$0 ==.
      001662 22               [24] 4620 	ret
                                   4621 ;------------------------------------------------------------
                                   4622 ;Allocation info for local variables in function 'fuzzy_rules_create'
                                   4623 ;------------------------------------------------------------
                                   4624 ;rules         Allocated to registers r5 r6 r7 
                                   4625 ;------------------------------------------------------------
                           0015AC  4626 	G$fuzzy_rules_create$0$0 ==.
                           0015AC  4627 	C$fuzzy.h$1401$1_0$81 ==.
                                   4628 ;	../../fuzzy.h:1401: void fuzzy_rules_create(
                                   4629 ;	-----------------------------------------
                                   4630 ;	 function fuzzy_rules_create
                                   4631 ;	-----------------------------------------
      001663                       4632 _fuzzy_rules_create:
      001663 AD 82            [24] 4633 	mov	r5, dpl
      001665 AE 83            [24] 4634 	mov	r6, dph
      001667 AF F0            [24] 4635 	mov	r7, b
                           0015B2  4636 	C$fuzzy.h$1405$1_0$81 ==.
                                   4637 ;	../../fuzzy.h:1405: if (rules == NULL) {
      001669 ED               [12] 4638 	mov	a,r5
      00166A 4E               [12] 4639 	orl	a,r6
      00166B 70 02            [24] 4640 	jnz	00102$
                           0015B6  4641 	C$fuzzy.h$1406$2_0$82 ==.
                                   4642 ;	../../fuzzy.h:1406: return;
      00166D 80 15            [24] 4643 	sjmp	00103$
      00166F                       4644 00102$:
                           0015B8  4645 	C$fuzzy.h$1409$1_0$81 ==.
                                   4646 ;	../../fuzzy.h:1409: rules->count = 0;
      00166F 74 90            [12] 4647 	mov	a,#0x90
      001671 2D               [12] 4648 	add	a, r5
      001672 FD               [12] 4649 	mov	r5,a
      001673 E4               [12] 4650 	clr	a
      001674 3E               [12] 4651 	addc	a, r6
      001675 FE               [12] 4652 	mov	r6,a
      001676 8D 82            [24] 4653 	mov	dpl,r5
      001678 8E 83            [24] 4654 	mov	dph,r6
      00167A 8F F0            [24] 4655 	mov	b,r7
      00167C E4               [12] 4656 	clr	a
      00167D 12 24 1F         [24] 4657 	lcall	__gptrput
      001680 A3               [24] 4658 	inc	dptr
      001681 12 24 1F         [24] 4659 	lcall	__gptrput
      001684                       4660 00103$:
                           0015CD  4661 	C$fuzzy.h$1410$1_0$81 ==.
                                   4662 ;	../../fuzzy.h:1410: }
                           0015CD  4663 	C$fuzzy.h$1410$1_0$81 ==.
                           0015CD  4664 	XG$fuzzy_rules_create$0$0 ==.
      001684 22               [24] 4665 	ret
                                   4666 ;------------------------------------------------------------
                                   4667 ;Allocation info for local variables in function 'fuzzy_rules_add'
                                   4668 ;------------------------------------------------------------
                                   4669 ;name          Allocated to stack - _bp -5 +3 
                                   4670 ;value         Allocated to stack - _bp -9 +4 
                                   4671 ;output_function Allocated to stack - _bp -11 +2 
                                   4672 ;rules         Allocated to registers r2 r3 r4 
                                   4673 ;index         Allocated to registers 
                                   4674 ;sloc0         Allocated to stack - _bp +1 +2 
                                   4675 ;sloc1         Allocated to stack - _bp +3 +3 
                                   4676 ;sloc2         Allocated to stack - _bp +6 +3 
                                   4677 ;sloc3         Allocated to stack - _bp +9 +3 
                                   4678 ;------------------------------------------------------------
                           0015CE  4679 	G$fuzzy_rules_add$0$0 ==.
                           0015CE  4680 	C$fuzzy.h$1413$1_0$84 ==.
                                   4681 ;	../../fuzzy.h:1413: bool fuzzy_rules_add(
                                   4682 ;	-----------------------------------------
                                   4683 ;	 function fuzzy_rules_add
                                   4684 ;	-----------------------------------------
      001685                       4685 _fuzzy_rules_add:
      001685 C0 08            [24] 4686 	push	_bp
      001687 E5 81            [12] 4687 	mov	a,sp
      001689 F5 08            [12] 4688 	mov	_bp,a
      00168B 24 0B            [12] 4689 	add	a,#0x0b
      00168D F5 81            [12] 4690 	mov	sp,a
      00168F AA 82            [24] 4691 	mov	r2, dpl
      001691 AB 83            [24] 4692 	mov	r3, dph
      001693 AC F0            [24] 4693 	mov	r4, b
                           0015DE  4694 	C$fuzzy.h$1423$1_0$84 ==.
                                   4695 ;	../../fuzzy.h:1423: rules == NULL ||
      001695 EA               [12] 4696 	mov	a,r2
      001696 4B               [12] 4697 	orl	a,r3
      001697 60 0A            [24] 4698 	jz	00101$
                           0015E2  4699 	C$fuzzy.h$1424$1_0$84 ==.
                                   4700 ;	../../fuzzy.h:1424: output_function == NULL
      001699 E5 08            [12] 4701 	mov	a,_bp
      00169B 24 F5            [12] 4702 	add	a,#0xf5
      00169D F8               [12] 4703 	mov	r0,a
      00169E E6               [12] 4704 	mov	a,@r0
      00169F 08               [12] 4705 	inc	r0
      0016A0 46               [12] 4706 	orl	a,@r0
      0016A1 70 06            [24] 4707 	jnz	00102$
      0016A3                       4708 00101$:
                           0015EC  4709 	C$fuzzy.h$1426$2_0$85 ==.
                                   4710 ;	../../fuzzy.h:1426: return false;
      0016A3 75 82 00         [24] 4711 	mov	dpl, #0x00
      0016A6 02 17 E3         [24] 4712 	ljmp	00106$
      0016A9                       4713 00102$:
                           0015F2  4714 	C$fuzzy.h$1429$1_0$84 ==.
                                   4715 ;	../../fuzzy.h:1429: if (rules->count >= FUZZY_MAX_RULES) {
      0016A9 E5 08            [12] 4716 	mov	a,_bp
      0016AB 24 09            [12] 4717 	add	a,#0x09
      0016AD F8               [12] 4718 	mov	r0,a
      0016AE 74 90            [12] 4719 	mov	a,#0x90
      0016B0 2A               [12] 4720 	add	a, r2
      0016B1 F6               [12] 4721 	mov	@r0,a
      0016B2 E4               [12] 4722 	clr	a
      0016B3 3B               [12] 4723 	addc	a, r3
      0016B4 08               [12] 4724 	inc	r0
      0016B5 F6               [12] 4725 	mov	@r0,a
      0016B6 08               [12] 4726 	inc	r0
      0016B7 A6 04            [24] 4727 	mov	@r0,ar4
      0016B9 E5 08            [12] 4728 	mov	a,_bp
      0016BB 24 09            [12] 4729 	add	a,#0x09
      0016BD F8               [12] 4730 	mov	r0,a
      0016BE 86 82            [24] 4731 	mov	dpl,@r0
      0016C0 08               [12] 4732 	inc	r0
      0016C1 86 83            [24] 4733 	mov	dph,@r0
      0016C3 08               [12] 4734 	inc	r0
      0016C4 86 F0            [24] 4735 	mov	b,@r0
      0016C6 12 26 66         [24] 4736 	lcall	__gptrget
      0016C9 FF               [12] 4737 	mov	r7,a
      0016CA A3               [24] 4738 	inc	dptr
      0016CB 12 26 66         [24] 4739 	lcall	__gptrget
      0016CE FE               [12] 4740 	mov	r6,a
      0016CF C3               [12] 4741 	clr	c
      0016D0 EF               [12] 4742 	mov	a,r7
      0016D1 94 10            [12] 4743 	subb	a,#0x10
      0016D3 EE               [12] 4744 	mov	a,r6
      0016D4 94 00            [12] 4745 	subb	a,#0x00
      0016D6 40 06            [24] 4746 	jc	00105$
                           001621  4747 	C$fuzzy.h$1430$2_0$86 ==.
                                   4748 ;	../../fuzzy.h:1430: return false;
      0016D8 75 82 00         [24] 4749 	mov	dpl, #0x00
      0016DB 02 17 E3         [24] 4750 	ljmp	00106$
      0016DE                       4751 00105$:
                           001627  4752 	C$fuzzy.h$1436$1_0$84 ==.
                                   4753 ;	../../fuzzy.h:1436: rules->rules[index].name =
      0016DE C0 04            [24] 4754 	push	ar4
      0016E0 C0 03            [24] 4755 	push	ar3
      0016E2 C0 02            [24] 4756 	push	ar2
      0016E4 C0 07            [24] 4757 	push	ar7
      0016E6 C0 06            [24] 4758 	push	ar6
      0016E8 90 00 09         [24] 4759 	mov	dptr,#0x0009
      0016EB 12 24 6A         [24] 4760 	lcall	__mulint
      0016EE A8 08            [24] 4761 	mov	r0,_bp
      0016F0 08               [12] 4762 	inc	r0
      0016F1 A6 82            [24] 4763 	mov	@r0, dpl
      0016F3 08               [12] 4764 	inc	r0
      0016F4 A6 83            [24] 4765 	mov	@r0, dph
      0016F6 15 81            [12] 4766 	dec	sp
      0016F8 15 81            [12] 4767 	dec	sp
      0016FA D0 02            [24] 4768 	pop	ar2
      0016FC D0 03            [24] 4769 	pop	ar3
      0016FE D0 04            [24] 4770 	pop	ar4
      001700 A8 08            [24] 4771 	mov	r0,_bp
      001702 08               [12] 4772 	inc	r0
      001703 E6               [12] 4773 	mov	a,@r0
      001704 2A               [12] 4774 	add	a, r2
      001705 FD               [12] 4775 	mov	r5,a
      001706 08               [12] 4776 	inc	r0
      001707 E6               [12] 4777 	mov	a,@r0
      001708 3B               [12] 4778 	addc	a, r3
      001709 FE               [12] 4779 	mov	r6,a
      00170A 8C 07            [24] 4780 	mov	ar7,r4
      00170C 8D 82            [24] 4781 	mov	dpl,r5
      00170E 8E 83            [24] 4782 	mov	dph,r6
      001710 8F F0            [24] 4783 	mov	b,r7
      001712 E5 08            [12] 4784 	mov	a,_bp
      001714 24 FB            [12] 4785 	add	a,#0xfb
      001716 F8               [12] 4786 	mov	r0,a
      001717 E6               [12] 4787 	mov	a,@r0
      001718 12 24 1F         [24] 4788 	lcall	__gptrput
      00171B A3               [24] 4789 	inc	dptr
      00171C 08               [12] 4790 	inc	r0
      00171D E6               [12] 4791 	mov	a,@r0
      00171E 12 24 1F         [24] 4792 	lcall	__gptrput
      001721 A3               [24] 4793 	inc	dptr
      001722 08               [12] 4794 	inc	r0
      001723 E6               [12] 4795 	mov	a,@r0
      001724 12 24 1F         [24] 4796 	lcall	__gptrput
                           001670  4797 	C$fuzzy.h$1439$1_0$84 ==.
                                   4798 ;	../../fuzzy.h:1439: rules->rules[index].value =
      001727 A8 08            [24] 4799 	mov	r0,_bp
      001729 08               [12] 4800 	inc	r0
      00172A E5 08            [12] 4801 	mov	a,_bp
      00172C 24 03            [12] 4802 	add	a,#0x03
      00172E F9               [12] 4803 	mov	r1,a
      00172F E6               [12] 4804 	mov	a,@r0
      001730 2A               [12] 4805 	add	a, r2
      001731 F7               [12] 4806 	mov	@r1,a
      001732 08               [12] 4807 	inc	r0
      001733 E6               [12] 4808 	mov	a,@r0
      001734 3B               [12] 4809 	addc	a, r3
      001735 09               [12] 4810 	inc	r1
      001736 F7               [12] 4811 	mov	@r1,a
      001737 09               [12] 4812 	inc	r1
      001738 A7 04            [24] 4813 	mov	@r1,ar4
      00173A E5 08            [12] 4814 	mov	a,_bp
      00173C 24 03            [12] 4815 	add	a,#0x03
      00173E F8               [12] 4816 	mov	r0,a
      00173F E5 08            [12] 4817 	mov	a,_bp
      001741 24 06            [12] 4818 	add	a,#0x06
      001743 F9               [12] 4819 	mov	r1,a
      001744 74 03            [12] 4820 	mov	a,#0x03
      001746 26               [12] 4821 	add	a, @r0
      001747 F7               [12] 4822 	mov	@r1,a
      001748 E4               [12] 4823 	clr	a
      001749 08               [12] 4824 	inc	r0
      00174A 36               [12] 4825 	addc	a, @r0
      00174B 09               [12] 4826 	inc	r1
      00174C F7               [12] 4827 	mov	@r1,a
      00174D 08               [12] 4828 	inc	r0
      00174E E6               [12] 4829 	mov	a,@r0
      00174F 09               [12] 4830 	inc	r1
      001750 F7               [12] 4831 	mov	@r1,a
                           00169A  4832 	C$fuzzy.h$1440$1_0$84 ==.
                                   4833 ;	../../fuzzy.h:1440: fuzzy_clamp(value);
      001751 E5 08            [12] 4834 	mov	a,_bp
      001753 24 F7            [12] 4835 	add	a,#0xf7
      001755 F8               [12] 4836 	mov	r0,a
      001756 86 82            [24] 4837 	mov	dpl, @r0
      001758 08               [12] 4838 	inc	r0
      001759 86 83            [24] 4839 	mov	dph, @r0
      00175B 08               [12] 4840 	inc	r0
      00175C 86 F0            [24] 4841 	mov	b, @r0
      00175E 08               [12] 4842 	inc	r0
      00175F E6               [12] 4843 	mov	a, @r0
      001760 12 00 EA         [24] 4844 	lcall	_fuzzy_clamp
      001763 AD 82            [24] 4845 	mov	r5, dpl
      001765 AE 83            [24] 4846 	mov	r6, dph
      001767 AC F0            [24] 4847 	mov	r4, b
      001769 FF               [12] 4848 	mov	r7, a
      00176A E5 08            [12] 4849 	mov	a,_bp
      00176C 24 06            [12] 4850 	add	a,#0x06
      00176E F8               [12] 4851 	mov	r0,a
      00176F 86 82            [24] 4852 	mov	dpl,@r0
      001771 08               [12] 4853 	inc	r0
      001772 86 83            [24] 4854 	mov	dph,@r0
      001774 08               [12] 4855 	inc	r0
      001775 86 F0            [24] 4856 	mov	b,@r0
      001777 ED               [12] 4857 	mov	a,r5
      001778 12 24 1F         [24] 4858 	lcall	__gptrput
      00177B A3               [24] 4859 	inc	dptr
      00177C EE               [12] 4860 	mov	a,r6
      00177D 12 24 1F         [24] 4861 	lcall	__gptrput
      001780 A3               [24] 4862 	inc	dptr
      001781 EC               [12] 4863 	mov	a,r4
      001782 12 24 1F         [24] 4864 	lcall	__gptrput
      001785 A3               [24] 4865 	inc	dptr
      001786 EF               [12] 4866 	mov	a,r7
      001787 12 24 1F         [24] 4867 	lcall	__gptrput
                           0016D3  4868 	C$fuzzy.h$1442$1_0$84 ==.
                                   4869 ;	../../fuzzy.h:1442: rules->rules[index].output_function =
      00178A E5 08            [12] 4870 	mov	a,_bp
      00178C 24 03            [12] 4871 	add	a,#0x03
      00178E F8               [12] 4872 	mov	r0,a
      00178F 74 07            [12] 4873 	mov	a,#0x07
      001791 26               [12] 4874 	add	a, @r0
      001792 FD               [12] 4875 	mov	r5,a
      001793 E4               [12] 4876 	clr	a
      001794 08               [12] 4877 	inc	r0
      001795 36               [12] 4878 	addc	a, @r0
      001796 FE               [12] 4879 	mov	r6,a
      001797 08               [12] 4880 	inc	r0
      001798 86 07            [24] 4881 	mov	ar7,@r0
      00179A 8D 82            [24] 4882 	mov	dpl,r5
      00179C 8E 83            [24] 4883 	mov	dph,r6
      00179E 8F F0            [24] 4884 	mov	b,r7
      0017A0 E5 08            [12] 4885 	mov	a,_bp
      0017A2 24 F5            [12] 4886 	add	a,#0xf5
      0017A4 F8               [12] 4887 	mov	r0,a
      0017A5 E6               [12] 4888 	mov	a,@r0
      0017A6 12 24 1F         [24] 4889 	lcall	__gptrput
      0017A9 A3               [24] 4890 	inc	dptr
      0017AA 08               [12] 4891 	inc	r0
      0017AB E6               [12] 4892 	mov	a,@r0
      0017AC 12 24 1F         [24] 4893 	lcall	__gptrput
                           0016F8  4894 	C$fuzzy.h$1445$1_0$84 ==.
                                   4895 ;	../../fuzzy.h:1445: rules->count++;
      0017AF E5 08            [12] 4896 	mov	a,_bp
      0017B1 24 09            [12] 4897 	add	a,#0x09
      0017B3 F8               [12] 4898 	mov	r0,a
      0017B4 86 82            [24] 4899 	mov	dpl,@r0
      0017B6 08               [12] 4900 	inc	r0
      0017B7 86 83            [24] 4901 	mov	dph,@r0
      0017B9 08               [12] 4902 	inc	r0
      0017BA 86 F0            [24] 4903 	mov	b,@r0
      0017BC 12 26 66         [24] 4904 	lcall	__gptrget
      0017BF FE               [12] 4905 	mov	r6,a
      0017C0 A3               [24] 4906 	inc	dptr
      0017C1 12 26 66         [24] 4907 	lcall	__gptrget
      0017C4 FF               [12] 4908 	mov	r7,a
      0017C5 0E               [12] 4909 	inc	r6
      0017C6 BE 00 01         [24] 4910 	cjne	r6,#0x00,00123$
      0017C9 0F               [12] 4911 	inc	r7
      0017CA                       4912 00123$:
      0017CA E5 08            [12] 4913 	mov	a,_bp
      0017CC 24 09            [12] 4914 	add	a,#0x09
      0017CE F8               [12] 4915 	mov	r0,a
      0017CF 86 82            [24] 4916 	mov	dpl,@r0
      0017D1 08               [12] 4917 	inc	r0
      0017D2 86 83            [24] 4918 	mov	dph,@r0
      0017D4 08               [12] 4919 	inc	r0
      0017D5 86 F0            [24] 4920 	mov	b,@r0
      0017D7 EE               [12] 4921 	mov	a,r6
      0017D8 12 24 1F         [24] 4922 	lcall	__gptrput
      0017DB A3               [24] 4923 	inc	dptr
      0017DC EF               [12] 4924 	mov	a,r7
      0017DD 12 24 1F         [24] 4925 	lcall	__gptrput
                           001729  4926 	C$fuzzy.h$1447$1_0$84 ==.
                                   4927 ;	../../fuzzy.h:1447: return true;
      0017E0 75 82 01         [24] 4928 	mov	dpl, #0x01
      0017E3                       4929 00106$:
                           00172C  4930 	C$fuzzy.h$1448$1_0$84 ==.
                                   4931 ;	../../fuzzy.h:1448: }
      0017E3 85 08 81         [24] 4932 	mov	sp,_bp
      0017E6 D0 08            [24] 4933 	pop	_bp
                           001731  4934 	C$fuzzy.h$1448$1_0$84 ==.
                           001731  4935 	XG$fuzzy_rules_add$0$0 ==.
      0017E8 22               [24] 4936 	ret
                                   4937 ;------------------------------------------------------------
                                   4938 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify'
                                   4939 ;------------------------------------------------------------
                                   4940 ;lower         Allocated to stack - _bp -6 +4 
                                   4941 ;upper         Allocated to stack - _bp -10 +4 
                                   4942 ;step          Allocated to stack - _bp -14 +4 
                                   4943 ;method        Allocated to stack - _bp -15 +1 
                                   4944 ;rules         Allocated to stack - _bp +1 +3 
                                   4945 ;weighted_sum  Allocated to stack - _bp +20 +4 
                                   4946 ;height_sum    Allocated to stack - _bp +24 +4 
                                   4947 ;maximum_height Allocated to stack - _bp +28 +4 
                                   4948 ;maximum_position_sum Allocated to stack - _bp +32 +4 
                                   4949 ;smallest_maximum Allocated to stack - _bp +36 +4 
                                   4950 ;largest_maximum Allocated to stack - _bp +40 +4 
                                   4951 ;value         Allocated to stack - _bp +44 +4 
                                   4952 ;aggregated_height Allocated to stack - _bp +48 +4 
                                   4953 ;output_membership Allocated to stack - _bp +52 +4 
                                   4954 ;clipped_height Allocated to registers r2 r4 r5 r7 
                                   4955 ;maximum_count Allocated to stack - _bp +56 +2 
                                   4956 ;i             Allocated to stack - _bp +58 +2 
                                   4957 ;maximum_found Allocated to stack - _bp +60 +1 
                                   4958 ;sloc0         Allocated to stack - _bp +4 +3 
                                   4959 ;sloc1         Allocated to stack - _bp +7 +4 
                                   4960 ;sloc2         Allocated to stack - _bp +11 +2 
                                   4961 ;sloc3         Allocated to stack - _bp +13 +3 
                                   4962 ;sloc4         Allocated to stack - _bp +16 +4 
                                   4963 ;------------------------------------------------------------
                           001732  4964 	G$fuzzy_rules_defuzzify$0$0 ==.
                           001732  4965 	C$fuzzy.h$1496$1_0$88 ==.
                                   4966 ;	../../fuzzy.h:1496: float fuzzy_rules_defuzzify(
                                   4967 ;	-----------------------------------------
                                   4968 ;	 function fuzzy_rules_defuzzify
                                   4969 ;	-----------------------------------------
      0017E9                       4970 _fuzzy_rules_defuzzify:
      0017E9 C0 08            [24] 4971 	push	_bp
      0017EB 85 81 08         [24] 4972 	mov	_bp,sp
      0017EE C0 82            [24] 4973 	push	dpl
      0017F0 C0 83            [24] 4974 	push	dph
      0017F2 C0 F0            [24] 4975 	push	b
      0017F4 E5 81            [12] 4976 	mov	a,sp
      0017F6 24 39            [12] 4977 	add	a,#0x39
      0017F8 F5 81            [12] 4978 	mov	sp,a
                           001743  4979 	C$fuzzy.h$1524$1_0$88 ==.
                                   4980 ;	../../fuzzy.h:1524: rules == NULL ||
      0017FA A8 08            [24] 4981 	mov	r0,_bp
      0017FC 08               [12] 4982 	inc	r0
      0017FD E6               [12] 4983 	mov	a,@r0
      0017FE 08               [12] 4984 	inc	r0
      0017FF 46               [12] 4985 	orl	a,@r0
      001800 70 03            [24] 4986 	jnz	00277$
      001802 02 18 8E         [24] 4987 	ljmp	00101$
      001805                       4988 00277$:
                           00174E  4989 	C$fuzzy.h$1525$1_0$88 ==.
                                   4990 ;	../../fuzzy.h:1525: rules->count == 0 ||
      001805 A8 08            [24] 4991 	mov	r0,_bp
      001807 08               [12] 4992 	inc	r0
      001808 E5 08            [12] 4993 	mov	a,_bp
      00180A 24 04            [12] 4994 	add	a,#0x04
      00180C F9               [12] 4995 	mov	r1,a
      00180D 74 90            [12] 4996 	mov	a,#0x90
      00180F 26               [12] 4997 	add	a, @r0
      001810 F7               [12] 4998 	mov	@r1,a
      001811 E4               [12] 4999 	clr	a
      001812 08               [12] 5000 	inc	r0
      001813 36               [12] 5001 	addc	a, @r0
      001814 09               [12] 5002 	inc	r1
      001815 F7               [12] 5003 	mov	@r1,a
      001816 08               [12] 5004 	inc	r0
      001817 E6               [12] 5005 	mov	a,@r0
      001818 09               [12] 5006 	inc	r1
      001819 F7               [12] 5007 	mov	@r1,a
      00181A E5 08            [12] 5008 	mov	a,_bp
      00181C 24 04            [12] 5009 	add	a,#0x04
      00181E F8               [12] 5010 	mov	r0,a
      00181F 86 82            [24] 5011 	mov	dpl,@r0
      001821 08               [12] 5012 	inc	r0
      001822 86 83            [24] 5013 	mov	dph,@r0
      001824 08               [12] 5014 	inc	r0
      001825 86 F0            [24] 5015 	mov	b,@r0
      001827 12 26 66         [24] 5016 	lcall	__gptrget
      00182A FE               [12] 5017 	mov	r6,a
      00182B A3               [24] 5018 	inc	dptr
      00182C 12 26 66         [24] 5019 	lcall	__gptrget
      00182F 4E               [12] 5020 	orl	a,r6
      001830 60 5C            [24] 5021 	jz	00101$
                           00177B  5022 	C$fuzzy.h$1526$1_0$88 ==.
                                   5023 ;	../../fuzzy.h:1526: lower > upper ||
      001832 E5 08            [12] 5024 	mov	a,_bp
      001834 24 FA            [12] 5025 	add	a,#0xfa
      001836 F8               [12] 5026 	mov	r0,a
      001837 E6               [12] 5027 	mov	a,@r0
      001838 C0 E0            [24] 5028 	push	acc
      00183A 08               [12] 5029 	inc	r0
      00183B E6               [12] 5030 	mov	a,@r0
      00183C C0 E0            [24] 5031 	push	acc
      00183E 08               [12] 5032 	inc	r0
      00183F E6               [12] 5033 	mov	a,@r0
      001840 C0 E0            [24] 5034 	push	acc
      001842 08               [12] 5035 	inc	r0
      001843 E6               [12] 5036 	mov	a,@r0
      001844 C0 E0            [24] 5037 	push	acc
      001846 E5 08            [12] 5038 	mov	a,_bp
      001848 24 F6            [12] 5039 	add	a,#0xf6
      00184A F8               [12] 5040 	mov	r0,a
      00184B 86 82            [24] 5041 	mov	dpl, @r0
      00184D 08               [12] 5042 	inc	r0
      00184E 86 83            [24] 5043 	mov	dph, @r0
      001850 08               [12] 5044 	inc	r0
      001851 86 F0            [24] 5045 	mov	b, @r0
      001853 08               [12] 5046 	inc	r0
      001854 E6               [12] 5047 	mov	a, @r0
      001855 12 24 3A         [24] 5048 	lcall	___fslt
      001858 AF 82            [24] 5049 	mov	r7, dpl
      00185A E5 81            [12] 5050 	mov	a,sp
      00185C 24 FC            [12] 5051 	add	a,#0xfc
      00185E F5 81            [12] 5052 	mov	sp,a
      001860 EF               [12] 5053 	mov	a,r7
      001861 70 2B            [24] 5054 	jnz	00101$
                           0017AC  5055 	C$fuzzy.h$1528$1_0$88 ==.
                                   5056 ;	../../fuzzy.h:1528: ) {
      001863 E5 08            [12] 5057 	mov	a,_bp
      001865 24 F2            [12] 5058 	add	a,#0xf2
      001867 F8               [12] 5059 	mov	r0,a
      001868 E6               [12] 5060 	mov	a,@r0
      001869 C0 E0            [24] 5061 	push	acc
      00186B 08               [12] 5062 	inc	r0
      00186C E6               [12] 5063 	mov	a,@r0
      00186D C0 E0            [24] 5064 	push	acc
      00186F 08               [12] 5065 	inc	r0
      001870 E6               [12] 5066 	mov	a,@r0
      001871 C0 E0            [24] 5067 	push	acc
      001873 08               [12] 5068 	inc	r0
      001874 E6               [12] 5069 	mov	a,@r0
      001875 C0 E0            [24] 5070 	push	acc
      001877 90 00 00         [24] 5071 	mov	dptr,#0x0000
      00187A E4               [12] 5072 	clr	a
      00187B F5 F0            [12] 5073 	mov	b,a
      00187D 12 24 3A         [24] 5074 	lcall	___fslt
      001880 E5 81            [12] 5075 	mov	a,sp
      001882 24 FC            [12] 5076 	add	a,#0xfc
      001884 F5 81            [12] 5077 	mov	sp,a
      001886 E5 82            [12] 5078 	mov	a, dpl
      001888 24 FF            [12] 5079 	add	a,#0xff
      00188A 92 00            [24] 5080 	mov	b0,c
      00188C 40 09            [24] 5081 	jc	00102$
      00188E                       5082 00101$:
                           0017D7  5083 	C$fuzzy.h$1529$2_0$89 ==.
                                   5084 ;	../../fuzzy.h:1529: return 0.0f;
      00188E 90 00 00         [24] 5085 	mov	dptr,#0x0000
      001891 E4               [12] 5086 	clr	a
      001892 F5 F0            [12] 5087 	mov	b,a
      001894 02 1E DF         [24] 5088 	ljmp	00137$
      001897                       5089 00102$:
                           0017E0  5090 	C$fuzzy.h$1533$1_0$88 ==.
                                   5091 ;	../../fuzzy.h:1533: method != FUZZY_DEFUZZ_COG &&
      001897 E5 08            [12] 5092 	mov	a,_bp
      001899 24 F1            [12] 5093 	add	a,#0xf1
      00189B F8               [12] 5094 	mov	r0,a
      00189C E6               [12] 5095 	mov	a,@r0
      00189D 60 27            [24] 5096 	jz	00107$
                           0017E8  5097 	C$fuzzy.h$1534$1_0$88 ==.
                                   5098 ;	../../fuzzy.h:1534: method != FUZZY_DEFUZZ_MOM &&
      00189F E5 08            [12] 5099 	mov	a,_bp
      0018A1 24 F1            [12] 5100 	add	a,#0xf1
      0018A3 F8               [12] 5101 	mov	r0,a
      0018A4 B6 01 02         [24] 5102 	cjne	@r0,#0x01,00282$
      0018A7 80 1D            [24] 5103 	sjmp	00107$
      0018A9                       5104 00282$:
                           0017F2  5105 	C$fuzzy.h$1535$1_0$88 ==.
                                   5106 ;	../../fuzzy.h:1535: method != FUZZY_DEFUZZ_SOM &&
      0018A9 E5 08            [12] 5107 	mov	a,_bp
      0018AB 24 F1            [12] 5108 	add	a,#0xf1
      0018AD F8               [12] 5109 	mov	r0,a
      0018AE B6 02 02         [24] 5110 	cjne	@r0,#0x02,00283$
      0018B1 80 13            [24] 5111 	sjmp	00107$
      0018B3                       5112 00283$:
                           0017FC  5113 	C$fuzzy.h$1537$1_0$88 ==.
                                   5114 ;	../../fuzzy.h:1537: ) {
      0018B3 E5 08            [12] 5115 	mov	a,_bp
      0018B5 24 F1            [12] 5116 	add	a,#0xf1
      0018B7 F8               [12] 5117 	mov	r0,a
      0018B8 B6 03 02         [24] 5118 	cjne	@r0,#0x03,00284$
      0018BB 80 09            [24] 5119 	sjmp	00107$
      0018BD                       5120 00284$:
                           001806  5121 	C$fuzzy.h$1538$2_0$90 ==.
                                   5122 ;	../../fuzzy.h:1538: return 0.0f;
      0018BD 90 00 00         [24] 5123 	mov	dptr,#0x0000
      0018C0 E4               [12] 5124 	clr	a
      0018C1 F5 F0            [12] 5125 	mov	b,a
      0018C3 02 1E DF         [24] 5126 	ljmp	00137$
      0018C6                       5127 00107$:
                           00180F  5128 	C$fuzzy.h$1542$1_0$88 ==.
                                   5129 ;	../../fuzzy.h:1542: 0.0f;
      0018C6 E5 08            [12] 5130 	mov	a,_bp
      0018C8 24 14            [12] 5131 	add	a,#0x14
      0018CA F8               [12] 5132 	mov	r0,a
      0018CB E4               [12] 5133 	clr	a
      0018CC F6               [12] 5134 	mov	@r0,a
      0018CD 08               [12] 5135 	inc	r0
      0018CE F6               [12] 5136 	mov	@r0,a
      0018CF 08               [12] 5137 	inc	r0
      0018D0 F6               [12] 5138 	mov	@r0,a
      0018D1 08               [12] 5139 	inc	r0
      0018D2 F6               [12] 5140 	mov	@r0,a
                           00181C  5141 	C$fuzzy.h$1545$1_0$88 ==.
                                   5142 ;	../../fuzzy.h:1545: 0.0f;
      0018D3 E5 08            [12] 5143 	mov	a,_bp
      0018D5 24 18            [12] 5144 	add	a,#0x18
      0018D7 F8               [12] 5145 	mov	r0,a
      0018D8 E4               [12] 5146 	clr	a
      0018D9 F6               [12] 5147 	mov	@r0,a
      0018DA 08               [12] 5148 	inc	r0
      0018DB F6               [12] 5149 	mov	@r0,a
      0018DC 08               [12] 5150 	inc	r0
      0018DD F6               [12] 5151 	mov	@r0,a
      0018DE 08               [12] 5152 	inc	r0
      0018DF F6               [12] 5153 	mov	@r0,a
                           001829  5154 	C$fuzzy.h$1548$1_0$88 ==.
                                   5155 ;	../../fuzzy.h:1548: LEVEL_LO;
      0018E0 E5 08            [12] 5156 	mov	a,_bp
      0018E2 24 1C            [12] 5157 	add	a,#0x1c
      0018E4 F8               [12] 5158 	mov	r0,a
      0018E5 E4               [12] 5159 	clr	a
      0018E6 F6               [12] 5160 	mov	@r0,a
      0018E7 08               [12] 5161 	inc	r0
      0018E8 F6               [12] 5162 	mov	@r0,a
      0018E9 08               [12] 5163 	inc	r0
      0018EA F6               [12] 5164 	mov	@r0,a
      0018EB 08               [12] 5165 	inc	r0
      0018EC F6               [12] 5166 	mov	@r0,a
                           001836  5167 	C$fuzzy.h$1551$1_0$88 ==.
                                   5168 ;	../../fuzzy.h:1551: 0.0f;
      0018ED E5 08            [12] 5169 	mov	a,_bp
      0018EF 24 20            [12] 5170 	add	a,#0x20
      0018F1 F8               [12] 5171 	mov	r0,a
      0018F2 E4               [12] 5172 	clr	a
      0018F3 F6               [12] 5173 	mov	@r0,a
      0018F4 08               [12] 5174 	inc	r0
      0018F5 F6               [12] 5175 	mov	@r0,a
      0018F6 08               [12] 5176 	inc	r0
      0018F7 F6               [12] 5177 	mov	@r0,a
      0018F8 08               [12] 5178 	inc	r0
      0018F9 F6               [12] 5179 	mov	@r0,a
                           001843  5180 	C$fuzzy.h$1554$1_0$88 ==.
                                   5181 ;	../../fuzzy.h:1554: lower;
      0018FA E5 08            [12] 5182 	mov	a,_bp
      0018FC 24 FA            [12] 5183 	add	a,#0xfa
      0018FE F8               [12] 5184 	mov	r0,a
      0018FF E5 08            [12] 5185 	mov	a,_bp
      001901 24 24            [12] 5186 	add	a,#0x24
      001903 F9               [12] 5187 	mov	r1,a
      001904 E6               [12] 5188 	mov	a,@r0
      001905 F7               [12] 5189 	mov	@r1,a
      001906 08               [12] 5190 	inc	r0
      001907 E6               [12] 5191 	mov	a,@r0
      001908 09               [12] 5192 	inc	r1
      001909 F7               [12] 5193 	mov	@r1,a
      00190A 08               [12] 5194 	inc	r0
      00190B E6               [12] 5195 	mov	a,@r0
      00190C 09               [12] 5196 	inc	r1
      00190D F7               [12] 5197 	mov	@r1,a
      00190E 08               [12] 5198 	inc	r0
      00190F E6               [12] 5199 	mov	a,@r0
      001910 09               [12] 5200 	inc	r1
      001911 F7               [12] 5201 	mov	@r1,a
                           00185B  5202 	C$fuzzy.h$1557$1_0$88 ==.
                                   5203 ;	../../fuzzy.h:1557: lower;
      001912 E5 08            [12] 5204 	mov	a,_bp
      001914 24 24            [12] 5205 	add	a,#0x24
      001916 F8               [12] 5206 	mov	r0,a
      001917 E5 08            [12] 5207 	mov	a,_bp
      001919 24 28            [12] 5208 	add	a,#0x28
      00191B F9               [12] 5209 	mov	r1,a
      00191C E6               [12] 5210 	mov	a,@r0
      00191D F7               [12] 5211 	mov	@r1,a
      00191E 08               [12] 5212 	inc	r0
      00191F E6               [12] 5213 	mov	a,@r0
      001920 09               [12] 5214 	inc	r1
      001921 F7               [12] 5215 	mov	@r1,a
      001922 08               [12] 5216 	inc	r0
      001923 E6               [12] 5217 	mov	a,@r0
      001924 09               [12] 5218 	inc	r1
      001925 F7               [12] 5219 	mov	@r1,a
      001926 08               [12] 5220 	inc	r0
      001927 E6               [12] 5221 	mov	a,@r0
      001928 09               [12] 5222 	inc	r1
      001929 F7               [12] 5223 	mov	@r1,a
                           001873  5224 	C$fuzzy.h$1560$1_0$88 ==.
                                   5225 ;	../../fuzzy.h:1560: 0u;
      00192A E5 08            [12] 5226 	mov	a,_bp
      00192C 24 38            [12] 5227 	add	a,#0x38
      00192E F8               [12] 5228 	mov	r0,a
      00192F E4               [12] 5229 	clr	a
      001930 F6               [12] 5230 	mov	@r0,a
      001931 08               [12] 5231 	inc	r0
      001932 F6               [12] 5232 	mov	@r0,a
                           00187C  5233 	C$fuzzy.h$1563$1_0$88 ==.
                                   5234 ;	../../fuzzy.h:1563: false;
      001933 E5 08            [12] 5235 	mov	a,_bp
      001935 24 3C            [12] 5236 	add	a,#0x3c
      001937 F8               [12] 5237 	mov	r0,a
      001938 76 00            [12] 5238 	mov	@r0,#0x00
                           001883  5239 	C$fuzzy.h$1566$2_0$91 ==.
                                   5240 ;	../../fuzzy.h:1566: value = lower;
      00193A E5 08            [12] 5241 	mov	a,_bp
      00193C 24 24            [12] 5242 	add	a,#0x24
      00193E F8               [12] 5243 	mov	r0,a
      00193F E5 08            [12] 5244 	mov	a,_bp
      001941 24 2C            [12] 5245 	add	a,#0x2c
      001943 F9               [12] 5246 	mov	r1,a
      001944 E6               [12] 5247 	mov	a,@r0
      001945 F7               [12] 5248 	mov	@r1,a
      001946 08               [12] 5249 	inc	r0
      001947 E6               [12] 5250 	mov	a,@r0
      001948 09               [12] 5251 	inc	r1
      001949 F7               [12] 5252 	mov	@r1,a
      00194A 08               [12] 5253 	inc	r0
      00194B E6               [12] 5254 	mov	a,@r0
      00194C 09               [12] 5255 	inc	r1
      00194D F7               [12] 5256 	mov	@r1,a
      00194E 08               [12] 5257 	inc	r0
      00194F E6               [12] 5258 	mov	a,@r0
      001950 09               [12] 5259 	inc	r1
      001951 F7               [12] 5260 	mov	@r1,a
      001952 A8 08            [24] 5261 	mov	r0,_bp
      001954 08               [12] 5262 	inc	r0
      001955 E5 08            [12] 5263 	mov	a,_bp
      001957 24 0D            [12] 5264 	add	a,#0x0d
      001959 F9               [12] 5265 	mov	r1,a
      00195A E6               [12] 5266 	mov	a,@r0
      00195B F7               [12] 5267 	mov	@r1,a
      00195C 08               [12] 5268 	inc	r0
      00195D E6               [12] 5269 	mov	a,@r0
      00195E 09               [12] 5270 	inc	r1
      00195F F7               [12] 5271 	mov	@r1,a
      001960 08               [12] 5272 	inc	r0
      001961 E6               [12] 5273 	mov	a,@r0
      001962 09               [12] 5274 	inc	r1
      001963 F7               [12] 5275 	mov	@r1,a
      001964                       5276 00135$:
                           0018AD  5277 	C$fuzzy.h$1567$1_0$88 ==.
                                   5278 ;	../../fuzzy.h:1567: value <= upper;
      001964 E5 08            [12] 5279 	mov	a,_bp
      001966 24 2C            [12] 5280 	add	a,#0x2c
      001968 F8               [12] 5281 	mov	r0,a
      001969 E6               [12] 5282 	mov	a,@r0
      00196A C0 E0            [24] 5283 	push	acc
      00196C 08               [12] 5284 	inc	r0
      00196D E6               [12] 5285 	mov	a,@r0
      00196E C0 E0            [24] 5286 	push	acc
      001970 08               [12] 5287 	inc	r0
      001971 E6               [12] 5288 	mov	a,@r0
      001972 C0 E0            [24] 5289 	push	acc
      001974 08               [12] 5290 	inc	r0
      001975 E6               [12] 5291 	mov	a,@r0
      001976 C0 E0            [24] 5292 	push	acc
      001978 E5 08            [12] 5293 	mov	a,_bp
      00197A 24 F6            [12] 5294 	add	a,#0xf6
      00197C F8               [12] 5295 	mov	r0,a
      00197D 86 82            [24] 5296 	mov	dpl, @r0
      00197F 08               [12] 5297 	inc	r0
      001980 86 83            [24] 5298 	mov	dph, @r0
      001982 08               [12] 5299 	inc	r0
      001983 86 F0            [24] 5300 	mov	b, @r0
      001985 08               [12] 5301 	inc	r0
      001986 E6               [12] 5302 	mov	a, @r0
      001987 12 24 3A         [24] 5303 	lcall	___fslt
      00198A E5 81            [12] 5304 	mov	a,sp
      00198C 24 FC            [12] 5305 	add	a,#0xfc
      00198E F5 81            [12] 5306 	mov	sp,a
      001990 E5 82            [12] 5307 	mov	a, dpl
      001992 24 FF            [12] 5308 	add	a,#0xff
      001994 92 00            [24] 5309 	mov	b0,c
      001996 50 03            [24] 5310 	jnc	00285$
      001998 02 1D 98         [24] 5311 	ljmp	00118$
      00199B                       5312 00285$:
                           0018E4  5313 	C$fuzzy.h$1571$3_0$92 ==.
                                   5314 ;	../../fuzzy.h:1571: LEVEL_LO;
      00199B E5 08            [12] 5315 	mov	a,_bp
      00199D 24 07            [12] 5316 	add	a,#0x07
      00199F F8               [12] 5317 	mov	r0,a
      0019A0 E4               [12] 5318 	clr	a
      0019A1 F6               [12] 5319 	mov	@r0,a
      0019A2 08               [12] 5320 	inc	r0
      0019A3 F6               [12] 5321 	mov	@r0,a
      0019A4 08               [12] 5322 	inc	r0
      0019A5 F6               [12] 5323 	mov	@r0,a
      0019A6 08               [12] 5324 	inc	r0
      0019A7 F6               [12] 5325 	mov	@r0,a
                           0018F1  5326 	C$fuzzy.h$1580$1_0$88 ==.
                                   5327 ;	../../fuzzy.h:1580: i = 0;
      0019A8 E5 08            [12] 5328 	mov	a,_bp
      0019AA 24 3A            [12] 5329 	add	a,#0x3a
      0019AC F8               [12] 5330 	mov	r0,a
      0019AD E4               [12] 5331 	clr	a
      0019AE F6               [12] 5332 	mov	@r0,a
      0019AF 08               [12] 5333 	inc	r0
      0019B0 F6               [12] 5334 	mov	@r0,a
      0019B1 E5 08            [12] 5335 	mov	a,_bp
      0019B3 24 0B            [12] 5336 	add	a,#0x0b
      0019B5 F8               [12] 5337 	mov	r0,a
      0019B6 E4               [12] 5338 	clr	a
      0019B7 F6               [12] 5339 	mov	@r0,a
      0019B8 08               [12] 5340 	inc	r0
      0019B9 F6               [12] 5341 	mov	@r0,a
      0019BA                       5342 00132$:
                           001903  5343 	C$fuzzy.h$1581$1_0$88 ==.
                                   5344 ;	../../fuzzy.h:1581: i < rules->count;
      0019BA E5 08            [12] 5345 	mov	a,_bp
      0019BC 24 04            [12] 5346 	add	a,#0x04
      0019BE F8               [12] 5347 	mov	r0,a
      0019BF 86 82            [24] 5348 	mov	dpl,@r0
      0019C1 08               [12] 5349 	inc	r0
      0019C2 86 83            [24] 5350 	mov	dph,@r0
      0019C4 08               [12] 5351 	inc	r0
      0019C5 86 F0            [24] 5352 	mov	b,@r0
      0019C7 12 26 66         [24] 5353 	lcall	__gptrget
      0019CA FA               [12] 5354 	mov	r2,a
      0019CB A3               [24] 5355 	inc	dptr
      0019CC 12 26 66         [24] 5356 	lcall	__gptrget
      0019CF FF               [12] 5357 	mov	r7,a
      0019D0 E5 08            [12] 5358 	mov	a,_bp
      0019D2 24 3A            [12] 5359 	add	a,#0x3a
      0019D4 F8               [12] 5360 	mov	r0,a
      0019D5 C3               [12] 5361 	clr	c
      0019D6 E6               [12] 5362 	mov	a,@r0
      0019D7 9A               [12] 5363 	subb	a,r2
      0019D8 08               [12] 5364 	inc	r0
      0019D9 E6               [12] 5365 	mov	a,@r0
      0019DA 9F               [12] 5366 	subb	a,r7
      0019DB 40 03            [24] 5367 	jc	00286$
      0019DD 02 1B 5B         [24] 5368 	ljmp	00111$
      0019E0                       5369 00286$:
                           001929  5370 	C$fuzzy.h$1585$1_0$88 ==.
                                   5371 ;	../../fuzzy.h:1585: rules->rules[i]
      0019E0 E5 08            [12] 5372 	mov	a,_bp
      0019E2 24 0D            [12] 5373 	add	a,#0x0d
      0019E4 F8               [12] 5374 	mov	r0,a
      0019E5 E5 08            [12] 5375 	mov	a,_bp
      0019E7 24 0B            [12] 5376 	add	a,#0x0b
      0019E9 F9               [12] 5377 	mov	r1,a
      0019EA E7               [12] 5378 	mov	a,@r1
      0019EB 26               [12] 5379 	add	a, @r0
      0019EC FA               [12] 5380 	mov	r2,a
      0019ED 09               [12] 5381 	inc	r1
      0019EE E7               [12] 5382 	mov	a,@r1
      0019EF 08               [12] 5383 	inc	r0
      0019F0 36               [12] 5384 	addc	a, @r0
      0019F1 FB               [12] 5385 	mov	r3,a
      0019F2 08               [12] 5386 	inc	r0
      0019F3 86 06            [24] 5387 	mov	ar6,@r0
      0019F5 74 07            [12] 5388 	mov	a,#0x07
      0019F7 2A               [12] 5389 	add	a, r2
      0019F8 FA               [12] 5390 	mov	r2,a
      0019F9 E4               [12] 5391 	clr	a
      0019FA 3B               [12] 5392 	addc	a, r3
      0019FB FB               [12] 5393 	mov	r3,a
      0019FC 8A 82            [24] 5394 	mov	dpl,r2
      0019FE 8B 83            [24] 5395 	mov	dph,r3
      001A00 8E F0            [24] 5396 	mov	b,r6
      001A02 12 26 66         [24] 5397 	lcall	__gptrget
      001A05 FA               [12] 5398 	mov	r2,a
      001A06 A3               [24] 5399 	inc	dptr
      001A07 12 26 66         [24] 5400 	lcall	__gptrget
      001A0A FB               [12] 5401 	mov	r3,a
                           001954  5402 	C$fuzzy.h$1587$5_0$94 ==.
                                   5403 ;	../../fuzzy.h:1587: value
      001A0B 12 1A 10         [24] 5404 	lcall	00287$
      001A0E 80 14            [24] 5405 	sjmp	00288$
      001A10                       5406 00287$:
      001A10 C0 02            [24] 5407 	push	ar2
      001A12 C0 03            [24] 5408 	push	ar3
      001A14 E5 08            [12] 5409 	mov	a,_bp
      001A16 24 2C            [12] 5410 	add	a,#0x2c
      001A18 F8               [12] 5411 	mov	r0,a
      001A19 86 82            [24] 5412 	mov	dpl, @r0
      001A1B 08               [12] 5413 	inc	r0
      001A1C 86 83            [24] 5414 	mov	dph, @r0
      001A1E 08               [12] 5415 	inc	r0
      001A1F 86 F0            [24] 5416 	mov	b, @r0
      001A21 08               [12] 5417 	inc	r0
      001A22 E6               [12] 5418 	mov	a, @r0
      001A23 22               [24] 5419 	ret
      001A24                       5420 00288$:
                           00196D  5421 	C$fuzzy.h$1592$5_0$94 ==.
                                   5422 ;	../../fuzzy.h:1592: output_membership
      001A24 12 00 EA         [24] 5423 	lcall	_fuzzy_clamp
      001A27 C8               [12] 5424 	xch	a,r0
      001A28 E5 08            [12] 5425 	mov	a,_bp
      001A2A 24 34            [12] 5426 	add	a,#0x34
      001A2C C8               [12] 5427 	xch	a,r0
      001A2D A6 82            [24] 5428 	mov	@r0, dpl
      001A2F 08               [12] 5429 	inc	r0
      001A30 A6 83            [24] 5430 	mov	@r0, dph
      001A32 08               [12] 5431 	inc	r0
      001A33 A6 F0            [24] 5432 	mov	@r0, b
      001A35 08               [12] 5433 	inc	r0
      001A36 F6               [12] 5434 	mov	@r0,a
                           001980  5435 	C$fuzzy.h$1596$5_0$94 ==.
                                   5436 ;	../../fuzzy.h:1596: rules->rules[i].value <
      001A37 A8 08            [24] 5437 	mov	r0,_bp
      001A39 08               [12] 5438 	inc	r0
      001A3A E5 08            [12] 5439 	mov	a,_bp
      001A3C 24 0B            [12] 5440 	add	a,#0x0b
      001A3E F9               [12] 5441 	mov	r1,a
      001A3F E7               [12] 5442 	mov	a,@r1
      001A40 26               [12] 5443 	add	a, @r0
      001A41 FD               [12] 5444 	mov	r5,a
      001A42 09               [12] 5445 	inc	r1
      001A43 E7               [12] 5446 	mov	a,@r1
      001A44 08               [12] 5447 	inc	r0
      001A45 36               [12] 5448 	addc	a, @r0
      001A46 FE               [12] 5449 	mov	r6,a
      001A47 08               [12] 5450 	inc	r0
      001A48 86 07            [24] 5451 	mov	ar7,@r0
      001A4A 74 03            [12] 5452 	mov	a,#0x03
      001A4C 2D               [12] 5453 	add	a, r5
      001A4D FD               [12] 5454 	mov	r5,a
      001A4E E4               [12] 5455 	clr	a
      001A4F 3E               [12] 5456 	addc	a, r6
      001A50 FE               [12] 5457 	mov	r6,a
      001A51 8D 82            [24] 5458 	mov	dpl,r5
      001A53 8E 83            [24] 5459 	mov	dph,r6
      001A55 8F F0            [24] 5460 	mov	b,r7
      001A57 E5 08            [12] 5461 	mov	a,_bp
      001A59 24 10            [12] 5462 	add	a,#0x10
      001A5B F8               [12] 5463 	mov	r0,a
      001A5C 12 26 66         [24] 5464 	lcall	__gptrget
      001A5F F6               [12] 5465 	mov	@r0,a
      001A60 A3               [24] 5466 	inc	dptr
      001A61 12 26 66         [24] 5467 	lcall	__gptrget
      001A64 08               [12] 5468 	inc	r0
      001A65 F6               [12] 5469 	mov	@r0,a
      001A66 A3               [24] 5470 	inc	dptr
      001A67 12 26 66         [24] 5471 	lcall	__gptrget
      001A6A 08               [12] 5472 	inc	r0
      001A6B F6               [12] 5473 	mov	@r0,a
      001A6C A3               [24] 5474 	inc	dptr
      001A6D 12 26 66         [24] 5475 	lcall	__gptrget
      001A70 08               [12] 5476 	inc	r0
      001A71 F6               [12] 5477 	mov	@r0,a
      001A72 E5 08            [12] 5478 	mov	a,_bp
      001A74 24 34            [12] 5479 	add	a,#0x34
      001A76 F8               [12] 5480 	mov	r0,a
      001A77 E6               [12] 5481 	mov	a,@r0
      001A78 C0 E0            [24] 5482 	push	acc
      001A7A 08               [12] 5483 	inc	r0
      001A7B E6               [12] 5484 	mov	a,@r0
      001A7C C0 E0            [24] 5485 	push	acc
      001A7E 08               [12] 5486 	inc	r0
      001A7F E6               [12] 5487 	mov	a,@r0
      001A80 C0 E0            [24] 5488 	push	acc
      001A82 08               [12] 5489 	inc	r0
      001A83 E6               [12] 5490 	mov	a,@r0
      001A84 C0 E0            [24] 5491 	push	acc
      001A86 E5 08            [12] 5492 	mov	a,_bp
      001A88 24 10            [12] 5493 	add	a,#0x10
      001A8A F8               [12] 5494 	mov	r0,a
      001A8B 86 82            [24] 5495 	mov	dpl, @r0
      001A8D 08               [12] 5496 	inc	r0
      001A8E 86 83            [24] 5497 	mov	dph, @r0
      001A90 08               [12] 5498 	inc	r0
      001A91 86 F0            [24] 5499 	mov	b, @r0
      001A93 08               [12] 5500 	inc	r0
      001A94 E6               [12] 5501 	mov	a, @r0
      001A95 12 24 3A         [24] 5502 	lcall	___fslt
      001A98 AF 82            [24] 5503 	mov	r7, dpl
      001A9A E5 81            [12] 5504 	mov	a,sp
      001A9C 24 FC            [12] 5505 	add	a,#0xfc
      001A9E F5 81            [12] 5506 	mov	sp,a
      001AA0 EF               [12] 5507 	mov	a,r7
      001AA1 60 12            [24] 5508 	jz	00139$
                           0019EC  5509 	C$fuzzy.h$1598$5_0$94 ==.
                                   5510 ;	../../fuzzy.h:1598: ? rules->rules[i].value
      001AA3 E5 08            [12] 5511 	mov	a,_bp
      001AA5 24 10            [12] 5512 	add	a,#0x10
      001AA7 F8               [12] 5513 	mov	r0,a
      001AA8 86 02            [24] 5514 	mov	ar2,@r0
      001AAA 08               [12] 5515 	inc	r0
      001AAB 86 04            [24] 5516 	mov	ar4,@r0
      001AAD 08               [12] 5517 	inc	r0
      001AAE 86 05            [24] 5518 	mov	ar5,@r0
      001AB0 08               [12] 5519 	inc	r0
      001AB1 86 07            [24] 5520 	mov	ar7,@r0
      001AB3 80 10            [24] 5521 	sjmp	00140$
      001AB5                       5522 00139$:
                           0019FE  5523 	C$fuzzy.h$1599$5_0$94 ==.
                                   5524 ;	../../fuzzy.h:1599: : output_membership;
      001AB5 E5 08            [12] 5525 	mov	a,_bp
      001AB7 24 34            [12] 5526 	add	a,#0x34
      001AB9 F8               [12] 5527 	mov	r0,a
      001ABA 86 02            [24] 5528 	mov	ar2,@r0
      001ABC 08               [12] 5529 	inc	r0
      001ABD 86 04            [24] 5530 	mov	ar4,@r0
      001ABF 08               [12] 5531 	inc	r0
      001AC0 86 05            [24] 5532 	mov	ar5,@r0
      001AC2 08               [12] 5533 	inc	r0
      001AC3 86 07            [24] 5534 	mov	ar7,@r0
      001AC5                       5535 00140$:
                           001A0E  5536 	C$fuzzy.h$1604$1_0$88 ==.
                                   5537 ;	../../fuzzy.h:1604: ? aggregated_height
      001AC5 C0 07            [24] 5538 	push	ar7
      001AC7 C0 05            [24] 5539 	push	ar5
      001AC9 C0 04            [24] 5540 	push	ar4
      001ACB C0 02            [24] 5541 	push	ar2
      001ACD E5 08            [12] 5542 	mov	a,_bp
      001ACF 24 07            [12] 5543 	add	a,#0x07
      001AD1 F8               [12] 5544 	mov	r0,a
      001AD2 E6               [12] 5545 	mov	a,@r0
      001AD3 C0 E0            [24] 5546 	push	acc
      001AD5 08               [12] 5547 	inc	r0
      001AD6 E6               [12] 5548 	mov	a,@r0
      001AD7 C0 E0            [24] 5549 	push	acc
      001AD9 08               [12] 5550 	inc	r0
      001ADA E6               [12] 5551 	mov	a,@r0
      001ADB C0 E0            [24] 5552 	push	acc
      001ADD 08               [12] 5553 	inc	r0
      001ADE E6               [12] 5554 	mov	a,@r0
      001ADF C0 E0            [24] 5555 	push	acc
      001AE1 8A 82            [24] 5556 	mov	dpl, r2
      001AE3 8C 83            [24] 5557 	mov	dph, r4
      001AE5 8D F0            [24] 5558 	mov	b, r5
      001AE7 EF               [12] 5559 	mov	a, r7
      001AE8 12 24 3A         [24] 5560 	lcall	___fslt
      001AEB AE 82            [24] 5561 	mov	r6, dpl
      001AED E5 81            [12] 5562 	mov	a,sp
      001AEF 24 FC            [12] 5563 	add	a,#0xfc
      001AF1 F5 81            [12] 5564 	mov	sp,a
      001AF3 D0 02            [24] 5565 	pop	ar2
      001AF5 D0 04            [24] 5566 	pop	ar4
      001AF7 D0 05            [24] 5567 	pop	ar5
      001AF9 D0 07            [24] 5568 	pop	ar7
      001AFB EE               [12] 5569 	mov	a,r6
      001AFC 60 1A            [24] 5570 	jz	00141$
      001AFE E5 08            [12] 5571 	mov	a,_bp
      001B00 24 07            [12] 5572 	add	a,#0x07
      001B02 F8               [12] 5573 	mov	r0,a
      001B03 E5 08            [12] 5574 	mov	a,_bp
      001B05 24 10            [12] 5575 	add	a,#0x10
      001B07 F9               [12] 5576 	mov	r1,a
      001B08 E6               [12] 5577 	mov	a,@r0
      001B09 F7               [12] 5578 	mov	@r1,a
      001B0A 08               [12] 5579 	inc	r0
      001B0B E6               [12] 5580 	mov	a,@r0
      001B0C 09               [12] 5581 	inc	r1
      001B0D F7               [12] 5582 	mov	@r1,a
      001B0E 08               [12] 5583 	inc	r0
      001B0F E6               [12] 5584 	mov	a,@r0
      001B10 09               [12] 5585 	inc	r1
      001B11 F7               [12] 5586 	mov	@r1,a
      001B12 08               [12] 5587 	inc	r0
      001B13 E6               [12] 5588 	mov	a,@r0
      001B14 09               [12] 5589 	inc	r1
      001B15 F7               [12] 5590 	mov	@r1,a
      001B16 80 10            [24] 5591 	sjmp	00142$
      001B18                       5592 00141$:
                           001A61  5593 	C$fuzzy.h$1605$5_0$94 ==.
                                   5594 ;	../../fuzzy.h:1605: : clipped_height;
      001B18 E5 08            [12] 5595 	mov	a,_bp
      001B1A 24 10            [12] 5596 	add	a,#0x10
      001B1C F8               [12] 5597 	mov	r0,a
      001B1D A6 02            [24] 5598 	mov	@r0,ar2
      001B1F 08               [12] 5599 	inc	r0
      001B20 A6 04            [24] 5600 	mov	@r0,ar4
      001B22 08               [12] 5601 	inc	r0
      001B23 A6 05            [24] 5602 	mov	@r0,ar5
      001B25 08               [12] 5603 	inc	r0
      001B26 A6 07            [24] 5604 	mov	@r0,ar7
      001B28                       5605 00142$:
      001B28 E5 08            [12] 5606 	mov	a,_bp
      001B2A 24 10            [12] 5607 	add	a,#0x10
      001B2C F8               [12] 5608 	mov	r0,a
      001B2D E5 08            [12] 5609 	mov	a,_bp
      001B2F 24 07            [12] 5610 	add	a,#0x07
      001B31 F9               [12] 5611 	mov	r1,a
      001B32 E6               [12] 5612 	mov	a,@r0
      001B33 F7               [12] 5613 	mov	@r1,a
      001B34 08               [12] 5614 	inc	r0
      001B35 E6               [12] 5615 	mov	a,@r0
      001B36 09               [12] 5616 	inc	r1
      001B37 F7               [12] 5617 	mov	@r1,a
      001B38 08               [12] 5618 	inc	r0
      001B39 E6               [12] 5619 	mov	a,@r0
      001B3A 09               [12] 5620 	inc	r1
      001B3B F7               [12] 5621 	mov	@r1,a
      001B3C 08               [12] 5622 	inc	r0
      001B3D E6               [12] 5623 	mov	a,@r0
      001B3E 09               [12] 5624 	inc	r1
      001B3F F7               [12] 5625 	mov	@r1,a
                           001A89  5626 	C$fuzzy.h$1582$1_0$88 ==.
                                   5627 ;	../../fuzzy.h:1582: i++
      001B40 E5 08            [12] 5628 	mov	a,_bp
      001B42 24 0B            [12] 5629 	add	a,#0x0b
      001B44 F8               [12] 5630 	mov	r0,a
      001B45 74 09            [12] 5631 	mov	a,#0x09
      001B47 26               [12] 5632 	add	a, @r0
      001B48 F6               [12] 5633 	mov	@r0,a
      001B49 E4               [12] 5634 	clr	a
      001B4A 08               [12] 5635 	inc	r0
      001B4B 36               [12] 5636 	addc	a, @r0
      001B4C F6               [12] 5637 	mov	@r0,a
      001B4D E5 08            [12] 5638 	mov	a,_bp
      001B4F 24 3A            [12] 5639 	add	a,#0x3a
      001B51 F8               [12] 5640 	mov	r0,a
      001B52 06               [12] 5641 	inc	@r0
      001B53 B6 00 02         [24] 5642 	cjne	@r0,#0x00,00291$
      001B56 08               [12] 5643 	inc	r0
      001B57 06               [12] 5644 	inc	@r0
      001B58                       5645 00291$:
      001B58 02 19 BA         [24] 5646 	ljmp	00132$
      001B5B                       5647 00111$:
                           001AA4  5648 	C$fuzzy.h$1610$3_0$92 ==.
                                   5649 ;	../../fuzzy.h:1610: aggregated_height
      001B5B E5 08            [12] 5650 	mov	a,_bp
      001B5D 24 07            [12] 5651 	add	a,#0x07
      001B5F F8               [12] 5652 	mov	r0,a
      001B60 86 82            [24] 5653 	mov	dpl, @r0
      001B62 08               [12] 5654 	inc	r0
      001B63 86 83            [24] 5655 	mov	dph, @r0
      001B65 08               [12] 5656 	inc	r0
      001B66 86 F0            [24] 5657 	mov	b, @r0
      001B68 08               [12] 5658 	inc	r0
      001B69 E6               [12] 5659 	mov	a, @r0
      001B6A 12 00 EA         [24] 5660 	lcall	_fuzzy_clamp
      001B6D C8               [12] 5661 	xch	a,r0
      001B6E E5 08            [12] 5662 	mov	a,_bp
      001B70 24 30            [12] 5663 	add	a,#0x30
      001B72 C8               [12] 5664 	xch	a,r0
      001B73 A6 82            [24] 5665 	mov	@r0, dpl
      001B75 08               [12] 5666 	inc	r0
      001B76 A6 83            [24] 5667 	mov	@r0, dph
      001B78 08               [12] 5668 	inc	r0
      001B79 A6 F0            [24] 5669 	mov	@r0, b
      001B7B 08               [12] 5670 	inc	r0
      001B7C F6               [12] 5671 	mov	@r0,a
                           001AC6  5672 	C$fuzzy.h$1618$1_0$88 ==.
                                   5673 ;	../../fuzzy.h:1618: aggregated_height;
      001B7D E5 08            [12] 5674 	mov	a,_bp
      001B7F 24 30            [12] 5675 	add	a,#0x30
      001B81 F8               [12] 5676 	mov	r0,a
      001B82 E6               [12] 5677 	mov	a,@r0
      001B83 C0 E0            [24] 5678 	push	acc
      001B85 08               [12] 5679 	inc	r0
      001B86 E6               [12] 5680 	mov	a,@r0
      001B87 C0 E0            [24] 5681 	push	acc
      001B89 08               [12] 5682 	inc	r0
      001B8A E6               [12] 5683 	mov	a,@r0
      001B8B C0 E0            [24] 5684 	push	acc
      001B8D 08               [12] 5685 	inc	r0
      001B8E E6               [12] 5686 	mov	a,@r0
      001B8F C0 E0            [24] 5687 	push	acc
      001B91 E5 08            [12] 5688 	mov	a,_bp
      001B93 24 2C            [12] 5689 	add	a,#0x2c
      001B95 F8               [12] 5690 	mov	r0,a
      001B96 86 82            [24] 5691 	mov	dpl, @r0
      001B98 08               [12] 5692 	inc	r0
      001B99 86 83            [24] 5693 	mov	dph, @r0
      001B9B 08               [12] 5694 	inc	r0
      001B9C 86 F0            [24] 5695 	mov	b, @r0
      001B9E 08               [12] 5696 	inc	r0
      001B9F E6               [12] 5697 	mov	a, @r0
      001BA0 12 23 0A         [24] 5698 	lcall	___fsmul
      001BA3 AA 82            [24] 5699 	mov	r2, dpl
      001BA5 AB 83            [24] 5700 	mov	r3, dph
      001BA7 AE F0            [24] 5701 	mov	r6, b
      001BA9 FF               [12] 5702 	mov	r7, a
      001BAA E5 81            [12] 5703 	mov	a,sp
      001BAC 24 FC            [12] 5704 	add	a,#0xfc
      001BAE F5 81            [12] 5705 	mov	sp,a
      001BB0 C0 02            [24] 5706 	push	ar2
      001BB2 C0 03            [24] 5707 	push	ar3
      001BB4 C0 06            [24] 5708 	push	ar6
      001BB6 C0 07            [24] 5709 	push	ar7
                           001B01  5710 	C$fuzzy.h$1621$1_0$88 ==.
                                   5711 ;	../../fuzzy.h:1621: aggregated_height;
      001BB8 E5 08            [12] 5712 	mov	a,_bp
      001BBA 24 14            [12] 5713 	add	a,#0x14
      001BBC F8               [12] 5714 	mov	r0,a
      001BBD 86 82            [24] 5715 	mov	dpl, @r0
      001BBF 08               [12] 5716 	inc	r0
      001BC0 86 83            [24] 5717 	mov	dph, @r0
      001BC2 08               [12] 5718 	inc	r0
      001BC3 86 F0            [24] 5719 	mov	b, @r0
      001BC5 08               [12] 5720 	inc	r0
      001BC6 E6               [12] 5721 	mov	a, @r0
      001BC7 12 24 8C         [24] 5722 	lcall	___fsadd
      001BCA C8               [12] 5723 	xch	a,r0
      001BCB E5 08            [12] 5724 	mov	a,_bp
      001BCD 24 14            [12] 5725 	add	a,#0x14
      001BCF C8               [12] 5726 	xch	a,r0
      001BD0 A6 82            [24] 5727 	mov	@r0, dpl
      001BD2 08               [12] 5728 	inc	r0
      001BD3 A6 83            [24] 5729 	mov	@r0, dph
      001BD5 08               [12] 5730 	inc	r0
      001BD6 A6 F0            [24] 5731 	mov	@r0, b
      001BD8 08               [12] 5732 	inc	r0
      001BD9 F6               [12] 5733 	mov	@r0,a
      001BDA E5 81            [12] 5734 	mov	a,sp
      001BDC 24 FC            [12] 5735 	add	a,#0xfc
      001BDE F5 81            [12] 5736 	mov	sp,a
      001BE0 E5 08            [12] 5737 	mov	a,_bp
      001BE2 24 30            [12] 5738 	add	a,#0x30
      001BE4 F8               [12] 5739 	mov	r0,a
      001BE5 E6               [12] 5740 	mov	a,@r0
      001BE6 C0 E0            [24] 5741 	push	acc
      001BE8 08               [12] 5742 	inc	r0
      001BE9 E6               [12] 5743 	mov	a,@r0
      001BEA C0 E0            [24] 5744 	push	acc
      001BEC 08               [12] 5745 	inc	r0
      001BED E6               [12] 5746 	mov	a,@r0
      001BEE C0 E0            [24] 5747 	push	acc
      001BF0 08               [12] 5748 	inc	r0
      001BF1 E6               [12] 5749 	mov	a,@r0
      001BF2 C0 E0            [24] 5750 	push	acc
                           001B3D  5751 	C$fuzzy.h$1629$1_0$88 ==.
                                   5752 ;	../../fuzzy.h:1629: !maximum_found ||
      001BF4 E5 08            [12] 5753 	mov	a,_bp
      001BF6 24 18            [12] 5754 	add	a,#0x18
      001BF8 F8               [12] 5755 	mov	r0,a
      001BF9 86 82            [24] 5756 	mov	dpl, @r0
      001BFB 08               [12] 5757 	inc	r0
      001BFC 86 83            [24] 5758 	mov	dph, @r0
      001BFE 08               [12] 5759 	inc	r0
      001BFF 86 F0            [24] 5760 	mov	b, @r0
      001C01 08               [12] 5761 	inc	r0
      001C02 E6               [12] 5762 	mov	a, @r0
      001C03 12 24 8C         [24] 5763 	lcall	___fsadd
      001C06 C8               [12] 5764 	xch	a,r0
      001C07 E5 08            [12] 5765 	mov	a,_bp
      001C09 24 18            [12] 5766 	add	a,#0x18
      001C0B C8               [12] 5767 	xch	a,r0
      001C0C A6 82            [24] 5768 	mov	@r0, dpl
      001C0E 08               [12] 5769 	inc	r0
      001C0F A6 83            [24] 5770 	mov	@r0, dph
      001C11 08               [12] 5771 	inc	r0
      001C12 A6 F0            [24] 5772 	mov	@r0, b
      001C14 08               [12] 5773 	inc	r0
      001C15 F6               [12] 5774 	mov	@r0,a
      001C16 E5 81            [12] 5775 	mov	a,sp
      001C18 24 FC            [12] 5776 	add	a,#0xfc
      001C1A F5 81            [12] 5777 	mov	sp,a
      001C1C E5 08            [12] 5778 	mov	a,_bp
      001C1E 24 3C            [12] 5779 	add	a,#0x3c
      001C20 F8               [12] 5780 	mov	r0,a
      001C21 E6               [12] 5781 	mov	a,@r0
      001C22 60 31            [24] 5782 	jz	00114$
                           001B6D  5783 	C$fuzzy.h$1631$1_0$88 ==.
                                   5784 ;	../../fuzzy.h:1631: ) {
      001C24 E5 08            [12] 5785 	mov	a,_bp
      001C26 24 30            [12] 5786 	add	a,#0x30
      001C28 F8               [12] 5787 	mov	r0,a
      001C29 E6               [12] 5788 	mov	a,@r0
      001C2A C0 E0            [24] 5789 	push	acc
      001C2C 08               [12] 5790 	inc	r0
      001C2D E6               [12] 5791 	mov	a,@r0
      001C2E C0 E0            [24] 5792 	push	acc
      001C30 08               [12] 5793 	inc	r0
      001C31 E6               [12] 5794 	mov	a,@r0
      001C32 C0 E0            [24] 5795 	push	acc
      001C34 08               [12] 5796 	inc	r0
      001C35 E6               [12] 5797 	mov	a,@r0
      001C36 C0 E0            [24] 5798 	push	acc
      001C38 E5 08            [12] 5799 	mov	a,_bp
      001C3A 24 1C            [12] 5800 	add	a,#0x1c
      001C3C F8               [12] 5801 	mov	r0,a
      001C3D 86 82            [24] 5802 	mov	dpl, @r0
      001C3F 08               [12] 5803 	inc	r0
      001C40 86 83            [24] 5804 	mov	dph, @r0
      001C42 08               [12] 5805 	inc	r0
      001C43 86 F0            [24] 5806 	mov	b, @r0
      001C45 08               [12] 5807 	inc	r0
      001C46 E6               [12] 5808 	mov	a, @r0
      001C47 12 24 3A         [24] 5809 	lcall	___fslt
      001C4A AF 82            [24] 5810 	mov	r7, dpl
      001C4C E5 81            [12] 5811 	mov	a,sp
      001C4E 24 FC            [12] 5812 	add	a,#0xfc
      001C50 F5 81            [12] 5813 	mov	sp,a
      001C52 EF               [12] 5814 	mov	a,r7
      001C53 60 74            [24] 5815 	jz	00115$
      001C55                       5816 00114$:
                           001B9E  5817 	C$fuzzy.h$1633$4_0$95 ==.
                                   5818 ;	../../fuzzy.h:1633: aggregated_height;
      001C55 E5 08            [12] 5819 	mov	a,_bp
      001C57 24 30            [12] 5820 	add	a,#0x30
      001C59 F8               [12] 5821 	mov	r0,a
      001C5A E5 08            [12] 5822 	mov	a,_bp
      001C5C 24 1C            [12] 5823 	add	a,#0x1c
      001C5E F9               [12] 5824 	mov	r1,a
      001C5F E6               [12] 5825 	mov	a,@r0
      001C60 F7               [12] 5826 	mov	@r1,a
      001C61 08               [12] 5827 	inc	r0
      001C62 E6               [12] 5828 	mov	a,@r0
      001C63 09               [12] 5829 	inc	r1
      001C64 F7               [12] 5830 	mov	@r1,a
      001C65 08               [12] 5831 	inc	r0
      001C66 E6               [12] 5832 	mov	a,@r0
      001C67 09               [12] 5833 	inc	r1
      001C68 F7               [12] 5834 	mov	@r1,a
      001C69 08               [12] 5835 	inc	r0
      001C6A E6               [12] 5836 	mov	a,@r0
      001C6B 09               [12] 5837 	inc	r1
      001C6C F7               [12] 5838 	mov	@r1,a
                           001BB6  5839 	C$fuzzy.h$1636$4_0$95 ==.
                                   5840 ;	../../fuzzy.h:1636: value;
      001C6D E5 08            [12] 5841 	mov	a,_bp
      001C6F 24 2C            [12] 5842 	add	a,#0x2c
      001C71 F8               [12] 5843 	mov	r0,a
      001C72 E5 08            [12] 5844 	mov	a,_bp
      001C74 24 24            [12] 5845 	add	a,#0x24
      001C76 F9               [12] 5846 	mov	r1,a
      001C77 E6               [12] 5847 	mov	a,@r0
      001C78 F7               [12] 5848 	mov	@r1,a
      001C79 08               [12] 5849 	inc	r0
      001C7A E6               [12] 5850 	mov	a,@r0
      001C7B 09               [12] 5851 	inc	r1
      001C7C F7               [12] 5852 	mov	@r1,a
      001C7D 08               [12] 5853 	inc	r0
      001C7E E6               [12] 5854 	mov	a,@r0
      001C7F 09               [12] 5855 	inc	r1
      001C80 F7               [12] 5856 	mov	@r1,a
      001C81 08               [12] 5857 	inc	r0
      001C82 E6               [12] 5858 	mov	a,@r0
      001C83 09               [12] 5859 	inc	r1
      001C84 F7               [12] 5860 	mov	@r1,a
                           001BCE  5861 	C$fuzzy.h$1639$4_0$95 ==.
                                   5862 ;	../../fuzzy.h:1639: value;
      001C85 E5 08            [12] 5863 	mov	a,_bp
      001C87 24 2C            [12] 5864 	add	a,#0x2c
      001C89 F8               [12] 5865 	mov	r0,a
      001C8A E5 08            [12] 5866 	mov	a,_bp
      001C8C 24 28            [12] 5867 	add	a,#0x28
      001C8E F9               [12] 5868 	mov	r1,a
      001C8F E6               [12] 5869 	mov	a,@r0
      001C90 F7               [12] 5870 	mov	@r1,a
      001C91 08               [12] 5871 	inc	r0
      001C92 E6               [12] 5872 	mov	a,@r0
      001C93 09               [12] 5873 	inc	r1
      001C94 F7               [12] 5874 	mov	@r1,a
      001C95 08               [12] 5875 	inc	r0
      001C96 E6               [12] 5876 	mov	a,@r0
      001C97 09               [12] 5877 	inc	r1
      001C98 F7               [12] 5878 	mov	@r1,a
      001C99 08               [12] 5879 	inc	r0
      001C9A E6               [12] 5880 	mov	a,@r0
      001C9B 09               [12] 5881 	inc	r1
      001C9C F7               [12] 5882 	mov	@r1,a
                           001BE6  5883 	C$fuzzy.h$1642$4_0$95 ==.
                                   5884 ;	../../fuzzy.h:1642: value;
      001C9D E5 08            [12] 5885 	mov	a,_bp
      001C9F 24 2C            [12] 5886 	add	a,#0x2c
      001CA1 F8               [12] 5887 	mov	r0,a
      001CA2 E5 08            [12] 5888 	mov	a,_bp
      001CA4 24 20            [12] 5889 	add	a,#0x20
      001CA6 F9               [12] 5890 	mov	r1,a
      001CA7 E6               [12] 5891 	mov	a,@r0
      001CA8 F7               [12] 5892 	mov	@r1,a
      001CA9 08               [12] 5893 	inc	r0
      001CAA E6               [12] 5894 	mov	a,@r0
      001CAB 09               [12] 5895 	inc	r1
      001CAC F7               [12] 5896 	mov	@r1,a
      001CAD 08               [12] 5897 	inc	r0
      001CAE E6               [12] 5898 	mov	a,@r0
      001CAF 09               [12] 5899 	inc	r1
      001CB0 F7               [12] 5900 	mov	@r1,a
      001CB1 08               [12] 5901 	inc	r0
      001CB2 E6               [12] 5902 	mov	a,@r0
      001CB3 09               [12] 5903 	inc	r1
      001CB4 F7               [12] 5904 	mov	@r1,a
                           001BFE  5905 	C$fuzzy.h$1645$4_0$95 ==.
                                   5906 ;	../../fuzzy.h:1645: 1u;
      001CB5 E5 08            [12] 5907 	mov	a,_bp
      001CB7 24 38            [12] 5908 	add	a,#0x38
      001CB9 F8               [12] 5909 	mov	r0,a
      001CBA 76 01            [12] 5910 	mov	@r0,#0x01
      001CBC 08               [12] 5911 	inc	r0
      001CBD 76 00            [12] 5912 	mov	@r0,#0x00
                           001C08  5913 	C$fuzzy.h$1648$4_0$95 ==.
                                   5914 ;	../../fuzzy.h:1648: true;
      001CBF E5 08            [12] 5915 	mov	a,_bp
      001CC1 24 3C            [12] 5916 	add	a,#0x3c
      001CC3 F8               [12] 5917 	mov	r0,a
      001CC4 76 01            [12] 5918 	mov	@r0,#0x01
      001CC6 02 1D 59         [24] 5919 	ljmp	00136$
      001CC9                       5920 00115$:
                           001C12  5921 	C$fuzzy.h$1652$1_0$88 ==.
                                   5922 ;	../../fuzzy.h:1652: ) {
      001CC9 E5 08            [12] 5923 	mov	a,_bp
      001CCB 24 1C            [12] 5924 	add	a,#0x1c
      001CCD F8               [12] 5925 	mov	r0,a
      001CCE E6               [12] 5926 	mov	a,@r0
      001CCF C0 E0            [24] 5927 	push	acc
      001CD1 08               [12] 5928 	inc	r0
      001CD2 E6               [12] 5929 	mov	a,@r0
      001CD3 C0 E0            [24] 5930 	push	acc
      001CD5 08               [12] 5931 	inc	r0
      001CD6 E6               [12] 5932 	mov	a,@r0
      001CD7 C0 E0            [24] 5933 	push	acc
      001CD9 08               [12] 5934 	inc	r0
      001CDA E6               [12] 5935 	mov	a,@r0
      001CDB C0 E0            [24] 5936 	push	acc
      001CDD E5 08            [12] 5937 	mov	a,_bp
      001CDF 24 30            [12] 5938 	add	a,#0x30
      001CE1 F8               [12] 5939 	mov	r0,a
      001CE2 86 82            [24] 5940 	mov	dpl, @r0
      001CE4 08               [12] 5941 	inc	r0
      001CE5 86 83            [24] 5942 	mov	dph, @r0
      001CE7 08               [12] 5943 	inc	r0
      001CE8 86 F0            [24] 5944 	mov	b, @r0
      001CEA 08               [12] 5945 	inc	r0
      001CEB E6               [12] 5946 	mov	a, @r0
      001CEC 12 24 0E         [24] 5947 	lcall	___fseq
      001CEF AF 82            [24] 5948 	mov	r7, dpl
      001CF1 E5 81            [12] 5949 	mov	a,sp
      001CF3 24 FC            [12] 5950 	add	a,#0xfc
      001CF5 F5 81            [12] 5951 	mov	sp,a
      001CF7 EF               [12] 5952 	mov	a,r7
      001CF8 60 5F            [24] 5953 	jz	00136$
                           001C43  5954 	C$fuzzy.h$1654$4_0$96 ==.
                                   5955 ;	../../fuzzy.h:1654: value;
      001CFA E5 08            [12] 5956 	mov	a,_bp
      001CFC 24 2C            [12] 5957 	add	a,#0x2c
      001CFE F8               [12] 5958 	mov	r0,a
      001CFF E5 08            [12] 5959 	mov	a,_bp
      001D01 24 28            [12] 5960 	add	a,#0x28
      001D03 F9               [12] 5961 	mov	r1,a
      001D04 E6               [12] 5962 	mov	a,@r0
      001D05 F7               [12] 5963 	mov	@r1,a
      001D06 08               [12] 5964 	inc	r0
      001D07 E6               [12] 5965 	mov	a,@r0
      001D08 09               [12] 5966 	inc	r1
      001D09 F7               [12] 5967 	mov	@r1,a
      001D0A 08               [12] 5968 	inc	r0
      001D0B E6               [12] 5969 	mov	a,@r0
      001D0C 09               [12] 5970 	inc	r1
      001D0D F7               [12] 5971 	mov	@r1,a
      001D0E 08               [12] 5972 	inc	r0
      001D0F E6               [12] 5973 	mov	a,@r0
      001D10 09               [12] 5974 	inc	r1
      001D11 F7               [12] 5975 	mov	@r1,a
                           001C5B  5976 	C$fuzzy.h$1657$1_0$88 ==.
                                   5977 ;	../../fuzzy.h:1657: value;
      001D12 E5 08            [12] 5978 	mov	a,_bp
      001D14 24 2C            [12] 5979 	add	a,#0x2c
      001D16 F8               [12] 5980 	mov	r0,a
      001D17 E6               [12] 5981 	mov	a,@r0
      001D18 C0 E0            [24] 5982 	push	acc
      001D1A 08               [12] 5983 	inc	r0
      001D1B E6               [12] 5984 	mov	a,@r0
      001D1C C0 E0            [24] 5985 	push	acc
      001D1E 08               [12] 5986 	inc	r0
      001D1F E6               [12] 5987 	mov	a,@r0
      001D20 C0 E0            [24] 5988 	push	acc
      001D22 08               [12] 5989 	inc	r0
      001D23 E6               [12] 5990 	mov	a,@r0
      001D24 C0 E0            [24] 5991 	push	acc
                           001C6F  5992 	C$fuzzy.h$1659$1_0$88 ==.
                                   5993 ;	../../fuzzy.h:1659: maximum_count++;
      001D26 E5 08            [12] 5994 	mov	a,_bp
      001D28 24 20            [12] 5995 	add	a,#0x20
      001D2A F8               [12] 5996 	mov	r0,a
      001D2B 86 82            [24] 5997 	mov	dpl, @r0
      001D2D 08               [12] 5998 	inc	r0
      001D2E 86 83            [24] 5999 	mov	dph, @r0
      001D30 08               [12] 6000 	inc	r0
      001D31 86 F0            [24] 6001 	mov	b, @r0
      001D33 08               [12] 6002 	inc	r0
      001D34 E6               [12] 6003 	mov	a, @r0
      001D35 12 24 8C         [24] 6004 	lcall	___fsadd
      001D38 C8               [12] 6005 	xch	a,r0
      001D39 E5 08            [12] 6006 	mov	a,_bp
      001D3B 24 20            [12] 6007 	add	a,#0x20
      001D3D C8               [12] 6008 	xch	a,r0
      001D3E A6 82            [24] 6009 	mov	@r0, dpl
      001D40 08               [12] 6010 	inc	r0
      001D41 A6 83            [24] 6011 	mov	@r0, dph
      001D43 08               [12] 6012 	inc	r0
      001D44 A6 F0            [24] 6013 	mov	@r0, b
      001D46 08               [12] 6014 	inc	r0
      001D47 F6               [12] 6015 	mov	@r0,a
      001D48 E5 81            [12] 6016 	mov	a,sp
      001D4A 24 FC            [12] 6017 	add	a,#0xfc
      001D4C F5 81            [12] 6018 	mov	sp,a
      001D4E E5 08            [12] 6019 	mov	a,_bp
      001D50 24 38            [12] 6020 	add	a,#0x38
      001D52 F8               [12] 6021 	mov	r0,a
      001D53 06               [12] 6022 	inc	@r0
      001D54 B6 00 02         [24] 6023 	cjne	@r0,#0x00,00295$
      001D57 08               [12] 6024 	inc	r0
      001D58 06               [12] 6025 	inc	@r0
      001D59                       6026 00295$:
      001D59                       6027 00136$:
                           001CA2  6028 	C$fuzzy.h$1569$1_0$88 ==.
                                   6029 ;	../../fuzzy.h:1569: ) {
      001D59 E5 08            [12] 6030 	mov	a,_bp
      001D5B 24 F2            [12] 6031 	add	a,#0xf2
      001D5D F8               [12] 6032 	mov	r0,a
      001D5E E6               [12] 6033 	mov	a,@r0
      001D5F C0 E0            [24] 6034 	push	acc
      001D61 08               [12] 6035 	inc	r0
      001D62 E6               [12] 6036 	mov	a,@r0
      001D63 C0 E0            [24] 6037 	push	acc
      001D65 08               [12] 6038 	inc	r0
      001D66 E6               [12] 6039 	mov	a,@r0
      001D67 C0 E0            [24] 6040 	push	acc
      001D69 08               [12] 6041 	inc	r0
      001D6A E6               [12] 6042 	mov	a,@r0
      001D6B C0 E0            [24] 6043 	push	acc
      001D6D E5 08            [12] 6044 	mov	a,_bp
      001D6F 24 2C            [12] 6045 	add	a,#0x2c
      001D71 F8               [12] 6046 	mov	r0,a
      001D72 86 82            [24] 6047 	mov	dpl, @r0
      001D74 08               [12] 6048 	inc	r0
      001D75 86 83            [24] 6049 	mov	dph, @r0
      001D77 08               [12] 6050 	inc	r0
      001D78 86 F0            [24] 6051 	mov	b, @r0
      001D7A 08               [12] 6052 	inc	r0
      001D7B E6               [12] 6053 	mov	a, @r0
      001D7C 12 24 8C         [24] 6054 	lcall	___fsadd
      001D7F C8               [12] 6055 	xch	a,r0
      001D80 E5 08            [12] 6056 	mov	a,_bp
      001D82 24 2C            [12] 6057 	add	a,#0x2c
      001D84 C8               [12] 6058 	xch	a,r0
      001D85 A6 82            [24] 6059 	mov	@r0, dpl
      001D87 08               [12] 6060 	inc	r0
      001D88 A6 83            [24] 6061 	mov	@r0, dph
      001D8A 08               [12] 6062 	inc	r0
      001D8B A6 F0            [24] 6063 	mov	@r0, b
      001D8D 08               [12] 6064 	inc	r0
      001D8E F6               [12] 6065 	mov	@r0,a
      001D8F E5 81            [12] 6066 	mov	a,sp
      001D91 24 FC            [12] 6067 	add	a,#0xfc
      001D93 F5 81            [12] 6068 	mov	sp,a
      001D95 02 19 64         [24] 6069 	ljmp	00135$
      001D98                       6070 00118$:
                           001CE1  6071 	C$fuzzy.h$1667$1_0$88 ==.
                                   6072 ;	../../fuzzy.h:1667: !maximum_found ||
      001D98 E5 08            [12] 6073 	mov	a,_bp
      001D9A 24 3C            [12] 6074 	add	a,#0x3c
      001D9C F8               [12] 6075 	mov	r0,a
      001D9D E6               [12] 6076 	mov	a,@r0
      001D9E 60 56            [24] 6077 	jz	00119$
                           001CE9  6078 	C$fuzzy.h$1668$1_0$88 ==.
                                   6079 ;	../../fuzzy.h:1668: maximum_height <= LEVEL_LO ||
      001DA0 E5 08            [12] 6080 	mov	a,_bp
      001DA2 24 1C            [12] 6081 	add	a,#0x1c
      001DA4 F8               [12] 6082 	mov	r0,a
      001DA5 E6               [12] 6083 	mov	a,@r0
      001DA6 C0 E0            [24] 6084 	push	acc
      001DA8 08               [12] 6085 	inc	r0
      001DA9 E6               [12] 6086 	mov	a,@r0
      001DAA C0 E0            [24] 6087 	push	acc
      001DAC 08               [12] 6088 	inc	r0
      001DAD E6               [12] 6089 	mov	a,@r0
      001DAE C0 E0            [24] 6090 	push	acc
      001DB0 08               [12] 6091 	inc	r0
      001DB1 E6               [12] 6092 	mov	a,@r0
      001DB2 C0 E0            [24] 6093 	push	acc
      001DB4 90 00 00         [24] 6094 	mov	dptr,#0x0000
      001DB7 E4               [12] 6095 	clr	a
      001DB8 F5 F0            [12] 6096 	mov	b,a
      001DBA 12 24 3A         [24] 6097 	lcall	___fslt
      001DBD E5 81            [12] 6098 	mov	a,sp
      001DBF 24 FC            [12] 6099 	add	a,#0xfc
      001DC1 F5 81            [12] 6100 	mov	sp,a
      001DC3 E5 82            [12] 6101 	mov	a, dpl
      001DC5 24 FF            [12] 6102 	add	a,#0xff
      001DC7 92 00            [24] 6103 	mov	b0,c
      001DC9 50 2B            [24] 6104 	jnc	00119$
                           001D14  6105 	C$fuzzy.h$1670$1_0$88 ==.
                                   6106 ;	../../fuzzy.h:1670: ) {
      001DCB E5 08            [12] 6107 	mov	a,_bp
      001DCD 24 18            [12] 6108 	add	a,#0x18
      001DCF F8               [12] 6109 	mov	r0,a
      001DD0 E6               [12] 6110 	mov	a,@r0
      001DD1 C0 E0            [24] 6111 	push	acc
      001DD3 08               [12] 6112 	inc	r0
      001DD4 E6               [12] 6113 	mov	a,@r0
      001DD5 C0 E0            [24] 6114 	push	acc
      001DD7 08               [12] 6115 	inc	r0
      001DD8 E6               [12] 6116 	mov	a,@r0
      001DD9 C0 E0            [24] 6117 	push	acc
      001DDB 08               [12] 6118 	inc	r0
      001DDC E6               [12] 6119 	mov	a,@r0
      001DDD C0 E0            [24] 6120 	push	acc
      001DDF 90 00 00         [24] 6121 	mov	dptr,#0x0000
      001DE2 E4               [12] 6122 	clr	a
      001DE3 F5 F0            [12] 6123 	mov	b,a
      001DE5 12 24 3A         [24] 6124 	lcall	___fslt
      001DE8 E5 81            [12] 6125 	mov	a,sp
      001DEA 24 FC            [12] 6126 	add	a,#0xfc
      001DEC F5 81            [12] 6127 	mov	sp,a
      001DEE E5 82            [12] 6128 	mov	a, dpl
      001DF0 24 FF            [12] 6129 	add	a,#0xff
      001DF2 92 00            [24] 6130 	mov	b0,c
      001DF4 40 09            [24] 6131 	jc	00120$
      001DF6                       6132 00119$:
                           001D3F  6133 	C$fuzzy.h$1671$2_0$97 ==.
                                   6134 ;	../../fuzzy.h:1671: return 0.0f;
      001DF6 90 00 00         [24] 6135 	mov	dptr,#0x0000
      001DF9 E4               [12] 6136 	clr	a
      001DFA F5 F0            [12] 6137 	mov	b,a
      001DFC 02 1E DF         [24] 6138 	ljmp	00137$
      001DFF                       6139 00120$:
                           001D48  6140 	C$fuzzy.h$1674$1_0$88 ==.
                                   6141 ;	../../fuzzy.h:1674: switch (method) {
      001DFF E5 08            [12] 6142 	mov	a,_bp
      001E01 24 F1            [12] 6143 	add	a,#0xf1
      001E03 F8               [12] 6144 	mov	r0,a
      001E04 E6               [12] 6145 	mov	a,@r0
      001E05 24 FC            [12] 6146 	add	a,#0xff - 0x03
      001E07 50 03            [24] 6147 	jnc	00299$
      001E09 02 1E D9         [24] 6148 	ljmp	00129$
      001E0C                       6149 00299$:
      001E0C E5 08            [12] 6150 	mov	a,_bp
      001E0E 24 F1            [12] 6151 	add	a,#0xf1
      001E10 F8               [12] 6152 	mov	r0,a
      001E11 E6               [12] 6153 	mov	a,@r0
      001E12 26               [12] 6154 	add	a,@r0
      001E13 26               [12] 6155 	add	a,@r0
      001E14 90 1E 18         [24] 6156 	mov	dptr,#00300$
      001E17 73               [24] 6157 	jmp	@a+dptr
      001E18                       6158 00300$:
      001E18 02 1E 24         [24] 6159 	ljmp	00123$
      001E1B 02 1E 61         [24] 6160 	ljmp	00124$
      001E1E 02 1E B7         [24] 6161 	ljmp	00127$
      001E21 02 1E C8         [24] 6162 	ljmp	00128$
                           001D6D  6163 	C$fuzzy.h$1675$2_0$98 ==.
                                   6164 ;	../../fuzzy.h:1675: case FUZZY_DEFUZZ_COG:
      001E24                       6165 00123$:
                           001D6D  6166 	C$fuzzy.h$1677$1_0$88 ==.
                                   6167 ;	../../fuzzy.h:1677: height_sum;
      001E24 E5 08            [12] 6168 	mov	a,_bp
      001E26 24 18            [12] 6169 	add	a,#0x18
      001E28 F8               [12] 6170 	mov	r0,a
      001E29 E6               [12] 6171 	mov	a,@r0
      001E2A C0 E0            [24] 6172 	push	acc
      001E2C 08               [12] 6173 	inc	r0
      001E2D E6               [12] 6174 	mov	a,@r0
      001E2E C0 E0            [24] 6175 	push	acc
      001E30 08               [12] 6176 	inc	r0
      001E31 E6               [12] 6177 	mov	a,@r0
      001E32 C0 E0            [24] 6178 	push	acc
      001E34 08               [12] 6179 	inc	r0
      001E35 E6               [12] 6180 	mov	a,@r0
      001E36 C0 E0            [24] 6181 	push	acc
      001E38 E5 08            [12] 6182 	mov	a,_bp
      001E3A 24 14            [12] 6183 	add	a,#0x14
      001E3C F8               [12] 6184 	mov	r0,a
      001E3D 86 82            [24] 6185 	mov	dpl, @r0
      001E3F 08               [12] 6186 	inc	r0
      001E40 86 83            [24] 6187 	mov	dph, @r0
      001E42 08               [12] 6188 	inc	r0
      001E43 86 F0            [24] 6189 	mov	b, @r0
      001E45 08               [12] 6190 	inc	r0
      001E46 E6               [12] 6191 	mov	a, @r0
      001E47 12 25 A3         [24] 6192 	lcall	___fsdiv
      001E4A AC 82            [24] 6193 	mov	r4, dpl
      001E4C AD 83            [24] 6194 	mov	r5, dph
      001E4E AE F0            [24] 6195 	mov	r6, b
      001E50 FF               [12] 6196 	mov	r7, a
      001E51 E5 81            [12] 6197 	mov	a,sp
      001E53 24 FC            [12] 6198 	add	a,#0xfc
      001E55 F5 81            [12] 6199 	mov	sp,a
      001E57 8C 82            [24] 6200 	mov	dpl, r4
      001E59 8D 83            [24] 6201 	mov	dph, r5
      001E5B 8E F0            [24] 6202 	mov	b, r6
      001E5D EF               [12] 6203 	mov	a, r7
      001E5E 02 1E DF         [24] 6204 	ljmp	00137$
                           001DAA  6205 	C$fuzzy.h$1679$2_0$98 ==.
                                   6206 ;	../../fuzzy.h:1679: case FUZZY_DEFUZZ_MOM:
      001E61                       6207 00124$:
                           001DAA  6208 	C$fuzzy.h$1680$2_0$98 ==.
                                   6209 ;	../../fuzzy.h:1680: if (maximum_count == 0u) {
      001E61 E5 08            [12] 6210 	mov	a,_bp
      001E63 24 38            [12] 6211 	add	a,#0x38
      001E65 F8               [12] 6212 	mov	r0,a
      001E66 E6               [12] 6213 	mov	a,@r0
      001E67 08               [12] 6214 	inc	r0
      001E68 46               [12] 6215 	orl	a,@r0
      001E69 70 08            [24] 6216 	jnz	00126$
                           001DB4  6217 	C$fuzzy.h$1681$3_0$99 ==.
                                   6218 ;	../../fuzzy.h:1681: return 0.0f;
      001E6B 90 00 00         [24] 6219 	mov	dptr,#0x0000
      001E6E E4               [12] 6220 	clr	a
      001E6F F5 F0            [12] 6221 	mov	b,a
      001E71 80 6C            [24] 6222 	sjmp	00137$
      001E73                       6223 00126$:
                           001DBC  6224 	C$fuzzy.h$1685$1_0$88 ==.
                                   6225 ;	../../fuzzy.h:1685: (float)maximum_count;
      001E73 E5 08            [12] 6226 	mov	a,_bp
      001E75 24 38            [12] 6227 	add	a,#0x38
      001E77 F8               [12] 6228 	mov	r0,a
      001E78 86 82            [24] 6229 	mov	dpl, @r0
      001E7A 08               [12] 6230 	inc	r0
      001E7B 86 83            [24] 6231 	mov	dph, @r0
      001E7D 12 25 2E         [24] 6232 	lcall	___uint2fs
      001E80 AC 82            [24] 6233 	mov	r4, dpl
      001E82 AD 83            [24] 6234 	mov	r5, dph
      001E84 AE F0            [24] 6235 	mov	r6, b
      001E86 FF               [12] 6236 	mov	r7, a
      001E87 C0 04            [24] 6237 	push	ar4
      001E89 C0 05            [24] 6238 	push	ar5
      001E8B C0 06            [24] 6239 	push	ar6
      001E8D C0 07            [24] 6240 	push	ar7
      001E8F E5 08            [12] 6241 	mov	a,_bp
      001E91 24 20            [12] 6242 	add	a,#0x20
      001E93 F8               [12] 6243 	mov	r0,a
      001E94 86 82            [24] 6244 	mov	dpl, @r0
      001E96 08               [12] 6245 	inc	r0
      001E97 86 83            [24] 6246 	mov	dph, @r0
      001E99 08               [12] 6247 	inc	r0
      001E9A 86 F0            [24] 6248 	mov	b, @r0
      001E9C 08               [12] 6249 	inc	r0
      001E9D E6               [12] 6250 	mov	a, @r0
      001E9E 12 25 A3         [24] 6251 	lcall	___fsdiv
      001EA1 AC 82            [24] 6252 	mov	r4, dpl
      001EA3 AD 83            [24] 6253 	mov	r5, dph
      001EA5 AE F0            [24] 6254 	mov	r6, b
      001EA7 FF               [12] 6255 	mov	r7, a
      001EA8 E5 81            [12] 6256 	mov	a,sp
      001EAA 24 FC            [12] 6257 	add	a,#0xfc
      001EAC F5 81            [12] 6258 	mov	sp,a
      001EAE 8C 82            [24] 6259 	mov	dpl, r4
      001EB0 8D 83            [24] 6260 	mov	dph, r5
      001EB2 8E F0            [24] 6261 	mov	b, r6
      001EB4 EF               [12] 6262 	mov	a, r7
                           001DFE  6263 	C$fuzzy.h$1687$2_0$98 ==.
                                   6264 ;	../../fuzzy.h:1687: case FUZZY_DEFUZZ_SOM:
      001EB5 80 28            [24] 6265 	sjmp	00137$
      001EB7                       6266 00127$:
                           001E00  6267 	C$fuzzy.h$1688$2_0$98 ==.
                                   6268 ;	../../fuzzy.h:1688: return smallest_maximum;
      001EB7 E5 08            [12] 6269 	mov	a,_bp
      001EB9 24 24            [12] 6270 	add	a,#0x24
      001EBB F8               [12] 6271 	mov	r0,a
      001EBC 86 82            [24] 6272 	mov	dpl, @r0
      001EBE 08               [12] 6273 	inc	r0
      001EBF 86 83            [24] 6274 	mov	dph, @r0
      001EC1 08               [12] 6275 	inc	r0
      001EC2 86 F0            [24] 6276 	mov	b, @r0
      001EC4 08               [12] 6277 	inc	r0
      001EC5 E6               [12] 6278 	mov	a, @r0
                           001E0F  6279 	C$fuzzy.h$1690$2_0$98 ==.
                                   6280 ;	../../fuzzy.h:1690: case FUZZY_DEFUZZ_LOM:
      001EC6 80 17            [24] 6281 	sjmp	00137$
      001EC8                       6282 00128$:
                           001E11  6283 	C$fuzzy.h$1691$2_0$98 ==.
                                   6284 ;	../../fuzzy.h:1691: return largest_maximum;
      001EC8 E5 08            [12] 6285 	mov	a,_bp
      001ECA 24 28            [12] 6286 	add	a,#0x28
      001ECC F8               [12] 6287 	mov	r0,a
      001ECD 86 82            [24] 6288 	mov	dpl, @r0
      001ECF 08               [12] 6289 	inc	r0
      001ED0 86 83            [24] 6290 	mov	dph, @r0
      001ED2 08               [12] 6291 	inc	r0
      001ED3 86 F0            [24] 6292 	mov	b, @r0
      001ED5 08               [12] 6293 	inc	r0
      001ED6 E6               [12] 6294 	mov	a, @r0
                           001E20  6295 	C$fuzzy.h$1693$2_0$98 ==.
                                   6296 ;	../../fuzzy.h:1693: default:
      001ED7 80 06            [24] 6297 	sjmp	00137$
      001ED9                       6298 00129$:
                           001E22  6299 	C$fuzzy.h$1694$2_0$98 ==.
                                   6300 ;	../../fuzzy.h:1694: return 0.0f;
      001ED9 90 00 00         [24] 6301 	mov	dptr,#0x0000
      001EDC E4               [12] 6302 	clr	a
      001EDD F5 F0            [12] 6303 	mov	b,a
                           001E28  6304 	C$fuzzy.h$1695$1_0$88 ==.
                                   6305 ;	../../fuzzy.h:1695: }
      001EDF                       6306 00137$:
                           001E28  6307 	C$fuzzy.h$1696$1_0$88 ==.
                                   6308 ;	../../fuzzy.h:1696: }
      001EDF 85 08 81         [24] 6309 	mov	sp,_bp
      001EE2 D0 08            [24] 6310 	pop	_bp
                           001E2D  6311 	C$fuzzy.h$1696$1_0$88 ==.
                           001E2D  6312 	XG$fuzzy_rules_defuzzify$0$0 ==.
      001EE4 22               [24] 6313 	ret
                                   6314 ;------------------------------------------------------------
                                   6315 ;Allocation info for local variables in function 'fuzzy_rules_cog'
                                   6316 ;------------------------------------------------------------
                                   6317 ;lower         Allocated to stack - _bp -6 +4 
                                   6318 ;upper         Allocated to stack - _bp -10 +4 
                                   6319 ;step          Allocated to stack - _bp -14 +4 
                                   6320 ;rules         Allocated to registers r5 r6 r7 
                                   6321 ;------------------------------------------------------------
                           001E2E  6322 	G$fuzzy_rules_cog$0$0 ==.
                           001E2E  6323 	C$fuzzy.h$1702$1_0$101 ==.
                                   6324 ;	../../fuzzy.h:1702: float fuzzy_rules_cog(
                                   6325 ;	-----------------------------------------
                                   6326 ;	 function fuzzy_rules_cog
                                   6327 ;	-----------------------------------------
      001EE5                       6328 _fuzzy_rules_cog:
      001EE5 C0 08            [24] 6329 	push	_bp
      001EE7 85 81 08         [24] 6330 	mov	_bp,sp
      001EEA AD 82            [24] 6331 	mov	r5, dpl
      001EEC AE 83            [24] 6332 	mov	r6, dph
      001EEE AF F0            [24] 6333 	mov	r7, b
                           001E39  6334 	C$fuzzy.h$1710$1_0$101 ==.
                                   6335 ;	../../fuzzy.h:1710: rules,
      001EF0 E4               [12] 6336 	clr	a
      001EF1 C0 E0            [24] 6337 	push	acc
      001EF3 E5 08            [12] 6338 	mov	a,_bp
      001EF5 24 F2            [12] 6339 	add	a,#0xf2
      001EF7 F8               [12] 6340 	mov	r0,a
      001EF8 E6               [12] 6341 	mov	a,@r0
      001EF9 C0 E0            [24] 6342 	push	acc
      001EFB 08               [12] 6343 	inc	r0
      001EFC E6               [12] 6344 	mov	a,@r0
      001EFD C0 E0            [24] 6345 	push	acc
      001EFF 08               [12] 6346 	inc	r0
      001F00 E6               [12] 6347 	mov	a,@r0
      001F01 C0 E0            [24] 6348 	push	acc
      001F03 08               [12] 6349 	inc	r0
      001F04 E6               [12] 6350 	mov	a,@r0
      001F05 C0 E0            [24] 6351 	push	acc
      001F07 E5 08            [12] 6352 	mov	a,_bp
      001F09 24 F6            [12] 6353 	add	a,#0xf6
      001F0B F8               [12] 6354 	mov	r0,a
      001F0C E6               [12] 6355 	mov	a,@r0
      001F0D C0 E0            [24] 6356 	push	acc
      001F0F 08               [12] 6357 	inc	r0
      001F10 E6               [12] 6358 	mov	a,@r0
      001F11 C0 E0            [24] 6359 	push	acc
      001F13 08               [12] 6360 	inc	r0
      001F14 E6               [12] 6361 	mov	a,@r0
      001F15 C0 E0            [24] 6362 	push	acc
      001F17 08               [12] 6363 	inc	r0
      001F18 E6               [12] 6364 	mov	a,@r0
      001F19 C0 E0            [24] 6365 	push	acc
      001F1B E5 08            [12] 6366 	mov	a,_bp
      001F1D 24 FA            [12] 6367 	add	a,#0xfa
      001F1F F8               [12] 6368 	mov	r0,a
      001F20 E6               [12] 6369 	mov	a,@r0
      001F21 C0 E0            [24] 6370 	push	acc
      001F23 08               [12] 6371 	inc	r0
      001F24 E6               [12] 6372 	mov	a,@r0
      001F25 C0 E0            [24] 6373 	push	acc
      001F27 08               [12] 6374 	inc	r0
      001F28 E6               [12] 6375 	mov	a,@r0
      001F29 C0 E0            [24] 6376 	push	acc
      001F2B 08               [12] 6377 	inc	r0
      001F2C E6               [12] 6378 	mov	a,@r0
      001F2D C0 E0            [24] 6379 	push	acc
      001F2F 8D 82            [24] 6380 	mov	dpl, r5
      001F31 8E 83            [24] 6381 	mov	dph, r6
      001F33 8F F0            [24] 6382 	mov	b, r7
      001F35 12 17 E9         [24] 6383 	lcall	_fuzzy_rules_defuzzify
      001F38 AC 82            [24] 6384 	mov	r4, dpl
      001F3A AD 83            [24] 6385 	mov	r5, dph
      001F3C AE F0            [24] 6386 	mov	r6, b
      001F3E FF               [12] 6387 	mov	r7, a
      001F3F E5 81            [12] 6388 	mov	a,sp
      001F41 24 F3            [12] 6389 	add	a,#0xf3
      001F43 F5 81            [12] 6390 	mov	sp,a
      001F45 8C 82            [24] 6391 	mov	dpl, r4
      001F47 8D 83            [24] 6392 	mov	dph, r5
      001F49 8E F0            [24] 6393 	mov	b, r6
      001F4B EF               [12] 6394 	mov	a, r7
                           001E95  6395 	C$fuzzy.h$1716$1_0$101 ==.
                                   6396 ;	../../fuzzy.h:1716: }
      001F4C D0 08            [24] 6397 	pop	_bp
                           001E97  6398 	C$fuzzy.h$1716$1_0$101 ==.
                           001E97  6399 	XG$fuzzy_rules_cog$0$0 ==.
      001F4E 22               [24] 6400 	ret
                                   6401 ;------------------------------------------------------------
                                   6402 ;Allocation info for local variables in function 'fuzzy_rules_free'
                                   6403 ;------------------------------------------------------------
                                   6404 ;rules         Allocated to registers r5 r6 r7 
                                   6405 ;------------------------------------------------------------
                           001E98  6406 	G$fuzzy_rules_free$0$0 ==.
                           001E98  6407 	C$fuzzy.h$1718$1_0$103 ==.
                                   6408 ;	../../fuzzy.h:1718: void fuzzy_rules_free(
                                   6409 ;	-----------------------------------------
                                   6410 ;	 function fuzzy_rules_free
                                   6411 ;	-----------------------------------------
      001F4F                       6412 _fuzzy_rules_free:
      001F4F AD 82            [24] 6413 	mov	r5, dpl
      001F51 AE 83            [24] 6414 	mov	r6, dph
      001F53 AF F0            [24] 6415 	mov	r7, b
                           001E9E  6416 	C$fuzzy.h$1722$1_0$103 ==.
                                   6417 ;	../../fuzzy.h:1722: if (rules == NULL) {
      001F55 ED               [12] 6418 	mov	a,r5
      001F56 4E               [12] 6419 	orl	a,r6
      001F57 70 02            [24] 6420 	jnz	00102$
                           001EA2  6421 	C$fuzzy.h$1723$2_0$104 ==.
                                   6422 ;	../../fuzzy.h:1723: return;
      001F59 80 15            [24] 6423 	sjmp	00103$
      001F5B                       6424 00102$:
                           001EA4  6425 	C$fuzzy.h$1731$1_0$103 ==.
                                   6426 ;	../../fuzzy.h:1731: rules->count = 0;
      001F5B 74 90            [12] 6427 	mov	a,#0x90
      001F5D 2D               [12] 6428 	add	a, r5
      001F5E FD               [12] 6429 	mov	r5,a
      001F5F E4               [12] 6430 	clr	a
      001F60 3E               [12] 6431 	addc	a, r6
      001F61 FE               [12] 6432 	mov	r6,a
      001F62 8D 82            [24] 6433 	mov	dpl,r5
      001F64 8E 83            [24] 6434 	mov	dph,r6
      001F66 8F F0            [24] 6435 	mov	b,r7
      001F68 E4               [12] 6436 	clr	a
      001F69 12 24 1F         [24] 6437 	lcall	__gptrput
      001F6C A3               [24] 6438 	inc	dptr
      001F6D 12 24 1F         [24] 6439 	lcall	__gptrput
      001F70                       6440 00103$:
                           001EB9  6441 	C$fuzzy.h$1732$1_0$103 ==.
                                   6442 ;	../../fuzzy.h:1732: }
                           001EB9  6443 	C$fuzzy.h$1732$1_0$103 ==.
                           001EB9  6444 	XG$fuzzy_rules_free$0$0 ==.
      001F70 22               [24] 6445 	ret
                                   6446 ;------------------------------------------------------------
                                   6447 ;Allocation info for local variables in function 'temperature_low'
                                   6448 ;------------------------------------------------------------
                                   6449 ;value         Allocated to registers r4 r5 r6 r7 
                                   6450 ;------------------------------------------------------------
                           001EBA  6451 	Fcontroller_8051$temperature_low$0$0 ==.
                           001EBA  6452 	C$controller_8051.c$59$1_0$106 ==.
                                   6453 ;	../../controller_8051.c:59: static float temperature_low(
                                   6454 ;	-----------------------------------------
                                   6455 ;	 function temperature_low
                                   6456 ;	-----------------------------------------
      001F71                       6457 _temperature_low:
      001F71 AC 82            [24] 6458 	mov	r4,dpl
      001F73 AD 83            [24] 6459 	mov	r5,dph
      001F75 AE F0            [24] 6460 	mov	r6,b
      001F77 FF               [12] 6461 	mov	r7,a
                           001EC1  6462 	C$controller_8051.c$68$1_0$106 ==.
                                   6463 ;	../../controller_8051.c:68: hedges.none
      001F78 90 27 28         [24] 6464 	mov	dptr,#_hedges
      001F7B E4               [12] 6465 	clr	a
      001F7C 93               [24] 6466 	movc	a,@a+dptr
      001F7D FB               [12] 6467 	mov	r3,a
                           001EC7  6468 	C$controller_8051.c$64$1_0$106 ==.
                                   6469 ;	../../controller_8051.c:64: 20.0f,
      001F7E C0 03            [24] 6470 	push	ar3
      001F80 E4               [12] 6471 	clr	a
      001F81 C0 E0            [24] 6472 	push	acc
      001F83 C0 04            [24] 6473 	push	ar4
      001F85 C0 05            [24] 6474 	push	ar5
      001F87 C0 06            [24] 6475 	push	ar6
      001F89 C0 07            [24] 6476 	push	ar7
      001F8B C0 E0            [24] 6477 	push	acc
      001F8D C0 E0            [24] 6478 	push	acc
      001F8F 74 20            [12] 6479 	mov	a,#0x20
      001F91 C0 E0            [24] 6480 	push	acc
      001F93 74 42            [12] 6481 	mov	a,#0x42
      001F95 C0 E0            [24] 6482 	push	acc
      001F97 90 00 00         [24] 6483 	mov	dptr,#0x0000
      001F9A 75 F0 A0         [24] 6484 	mov	b, #0xa0
      001F9D 14               [12] 6485 	dec	a
      001F9E 12 0A EC         [24] 6486 	lcall	_fuzzy_ramp
      001FA1 AC 82            [24] 6487 	mov	r4, dpl
      001FA3 AD 83            [24] 6488 	mov	r5, dph
      001FA5 AE F0            [24] 6489 	mov	r6, b
      001FA7 FF               [12] 6490 	mov	r7, a
      001FA8 E5 81            [12] 6491 	mov	a,sp
      001FAA 24 F6            [12] 6492 	add	a,#0xf6
      001FAC F5 81            [12] 6493 	mov	sp,a
      001FAE 8C 82            [24] 6494 	mov	dpl, r4
      001FB0 8D 83            [24] 6495 	mov	dph, r5
      001FB2 8E F0            [24] 6496 	mov	b, r6
      001FB4 EF               [12] 6497 	mov	a, r7
                           001EFE  6498 	C$controller_8051.c$70$1_0$106 ==.
                                   6499 ;	../../controller_8051.c:70: }
                           001EFE  6500 	C$controller_8051.c$70$1_0$106 ==.
                           001EFE  6501 	XFcontroller_8051$temperature_low$0$0 ==.
      001FB5 22               [24] 6502 	ret
                                   6503 ;------------------------------------------------------------
                                   6504 ;Allocation info for local variables in function 'temperature_high'
                                   6505 ;------------------------------------------------------------
                                   6506 ;value         Allocated to registers r4 r5 r6 r7 
                                   6507 ;------------------------------------------------------------
                           001EFF  6508 	Fcontroller_8051$temperature_high$0$0 ==.
                           001EFF  6509 	C$controller_8051.c$73$1_0$108 ==.
                                   6510 ;	../../controller_8051.c:73: static float temperature_high(
                                   6511 ;	-----------------------------------------
                                   6512 ;	 function temperature_high
                                   6513 ;	-----------------------------------------
      001FB6                       6514 _temperature_high:
      001FB6 AC 82            [24] 6515 	mov	r4,dpl
      001FB8 AD 83            [24] 6516 	mov	r5,dph
      001FBA AE F0            [24] 6517 	mov	r6,b
      001FBC FF               [12] 6518 	mov	r7,a
                           001F06  6519 	C$controller_8051.c$82$1_0$108 ==.
                                   6520 ;	../../controller_8051.c:82: hedges.none
      001FBD 90 27 28         [24] 6521 	mov	dptr,#_hedges
      001FC0 E4               [12] 6522 	clr	a
      001FC1 93               [24] 6523 	movc	a,@a+dptr
      001FC2 FB               [12] 6524 	mov	r3,a
                           001F0C  6525 	C$controller_8051.c$78$1_0$108 ==.
                                   6526 ;	../../controller_8051.c:78: 30.0f,
      001FC3 C0 03            [24] 6527 	push	ar3
      001FC5 74 01            [12] 6528 	mov	a,#0x01
      001FC7 C0 E0            [24] 6529 	push	acc
      001FC9 C0 04            [24] 6530 	push	ar4
      001FCB C0 05            [24] 6531 	push	ar5
      001FCD C0 06            [24] 6532 	push	ar6
      001FCF C0 07            [24] 6533 	push	ar7
      001FD1 E4               [12] 6534 	clr	a
      001FD2 C0 E0            [24] 6535 	push	acc
      001FD4 C0 E0            [24] 6536 	push	acc
      001FD6 74 70            [12] 6537 	mov	a,#0x70
      001FD8 C0 E0            [24] 6538 	push	acc
      001FDA 74 42            [12] 6539 	mov	a,#0x42
      001FDC C0 E0            [24] 6540 	push	acc
      001FDE 90 00 00         [24] 6541 	mov	dptr,#0x0000
      001FE1 75 F0 F0         [24] 6542 	mov	b, #0xf0
      001FE4 14               [12] 6543 	dec	a
      001FE5 12 0A EC         [24] 6544 	lcall	_fuzzy_ramp
      001FE8 AC 82            [24] 6545 	mov	r4, dpl
      001FEA AD 83            [24] 6546 	mov	r5, dph
      001FEC AE F0            [24] 6547 	mov	r6, b
      001FEE FF               [12] 6548 	mov	r7, a
      001FEF E5 81            [12] 6549 	mov	a,sp
      001FF1 24 F6            [12] 6550 	add	a,#0xf6
      001FF3 F5 81            [12] 6551 	mov	sp,a
      001FF5 8C 82            [24] 6552 	mov	dpl, r4
      001FF7 8D 83            [24] 6553 	mov	dph, r5
      001FF9 8E F0            [24] 6554 	mov	b, r6
      001FFB EF               [12] 6555 	mov	a, r7
                           001F45  6556 	C$controller_8051.c$84$1_0$108 ==.
                                   6557 ;	../../controller_8051.c:84: }
                           001F45  6558 	C$controller_8051.c$84$1_0$108 ==.
                           001F45  6559 	XFcontroller_8051$temperature_high$0$0 ==.
      001FFC 22               [24] 6560 	ret
                                   6561 ;------------------------------------------------------------
                                   6562 ;Allocation info for local variables in function 'fan_slow'
                                   6563 ;------------------------------------------------------------
                                   6564 ;value         Allocated to registers r4 r5 r6 r7 
                                   6565 ;------------------------------------------------------------
                           001F46  6566 	Fcontroller_8051$fan_slow$0$0 ==.
                           001F46  6567 	C$controller_8051.c$91$1_0$110 ==.
                                   6568 ;	../../controller_8051.c:91: static float fan_slow(
                                   6569 ;	-----------------------------------------
                                   6570 ;	 function fan_slow
                                   6571 ;	-----------------------------------------
      001FFD                       6572 _fan_slow:
      001FFD AC 82            [24] 6573 	mov	r4,dpl
      001FFF AD 83            [24] 6574 	mov	r5,dph
      002001 AE F0            [24] 6575 	mov	r6,b
      002003 FF               [12] 6576 	mov	r7,a
                           001F4D  6577 	C$controller_8051.c$100$1_0$110 ==.
                                   6578 ;	../../controller_8051.c:100: hedges.none
      002004 90 27 28         [24] 6579 	mov	dptr,#_hedges
      002007 E4               [12] 6580 	clr	a
      002008 93               [24] 6581 	movc	a,@a+dptr
      002009 FB               [12] 6582 	mov	r3,a
                           001F53  6583 	C$controller_8051.c$96$1_0$110 ==.
                                   6584 ;	../../controller_8051.c:96: 20.0f,
      00200A C0 03            [24] 6585 	push	ar3
      00200C E4               [12] 6586 	clr	a
      00200D C0 E0            [24] 6587 	push	acc
      00200F C0 04            [24] 6588 	push	ar4
      002011 C0 05            [24] 6589 	push	ar5
      002013 C0 06            [24] 6590 	push	ar6
      002015 C0 07            [24] 6591 	push	ar7
      002017 C0 E0            [24] 6592 	push	acc
      002019 C0 E0            [24] 6593 	push	acc
      00201B 74 48            [12] 6594 	mov	a,#0x48
      00201D C0 E0            [24] 6595 	push	acc
      00201F 74 42            [12] 6596 	mov	a,#0x42
      002021 C0 E0            [24] 6597 	push	acc
      002023 90 00 00         [24] 6598 	mov	dptr,#0x0000
      002026 75 F0 A0         [24] 6599 	mov	b, #0xa0
      002029 14               [12] 6600 	dec	a
      00202A 12 0A EC         [24] 6601 	lcall	_fuzzy_ramp
      00202D AC 82            [24] 6602 	mov	r4, dpl
      00202F AD 83            [24] 6603 	mov	r5, dph
      002031 AE F0            [24] 6604 	mov	r6, b
      002033 FF               [12] 6605 	mov	r7, a
      002034 E5 81            [12] 6606 	mov	a,sp
      002036 24 F6            [12] 6607 	add	a,#0xf6
      002038 F5 81            [12] 6608 	mov	sp,a
      00203A 8C 82            [24] 6609 	mov	dpl, r4
      00203C 8D 83            [24] 6610 	mov	dph, r5
      00203E 8E F0            [24] 6611 	mov	b, r6
      002040 EF               [12] 6612 	mov	a, r7
                           001F8A  6613 	C$controller_8051.c$102$1_0$110 ==.
                                   6614 ;	../../controller_8051.c:102: }
                           001F8A  6615 	C$controller_8051.c$102$1_0$110 ==.
                           001F8A  6616 	XFcontroller_8051$fan_slow$0$0 ==.
      002041 22               [24] 6617 	ret
                                   6618 ;------------------------------------------------------------
                                   6619 ;Allocation info for local variables in function 'fan_fast'
                                   6620 ;------------------------------------------------------------
                                   6621 ;value         Allocated to registers r4 r5 r6 r7 
                                   6622 ;------------------------------------------------------------
                           001F8B  6623 	Fcontroller_8051$fan_fast$0$0 ==.
                           001F8B  6624 	C$controller_8051.c$105$1_0$112 ==.
                                   6625 ;	../../controller_8051.c:105: static float fan_fast(
                                   6626 ;	-----------------------------------------
                                   6627 ;	 function fan_fast
                                   6628 ;	-----------------------------------------
      002042                       6629 _fan_fast:
      002042 AC 82            [24] 6630 	mov	r4,dpl
      002044 AD 83            [24] 6631 	mov	r5,dph
      002046 AE F0            [24] 6632 	mov	r6,b
      002048 FF               [12] 6633 	mov	r7,a
                           001F92  6634 	C$controller_8051.c$114$1_0$112 ==.
                                   6635 ;	../../controller_8051.c:114: hedges.none
      002049 90 27 28         [24] 6636 	mov	dptr,#_hedges
      00204C E4               [12] 6637 	clr	a
      00204D 93               [24] 6638 	movc	a,@a+dptr
      00204E FB               [12] 6639 	mov	r3,a
                           001F98  6640 	C$controller_8051.c$110$1_0$112 ==.
                                   6641 ;	../../controller_8051.c:110: 40.0f,
      00204F C0 03            [24] 6642 	push	ar3
      002051 74 01            [12] 6643 	mov	a,#0x01
      002053 C0 E0            [24] 6644 	push	acc
      002055 C0 04            [24] 6645 	push	ar4
      002057 C0 05            [24] 6646 	push	ar5
      002059 C0 06            [24] 6647 	push	ar6
      00205B C0 07            [24] 6648 	push	ar7
      00205D E4               [12] 6649 	clr	a
      00205E C0 E0            [24] 6650 	push	acc
      002060 C0 E0            [24] 6651 	push	acc
      002062 74 A0            [12] 6652 	mov	a,#0xa0
      002064 C0 E0            [24] 6653 	push	acc
      002066 74 42            [12] 6654 	mov	a,#0x42
      002068 C0 E0            [24] 6655 	push	acc
      00206A 90 00 00         [24] 6656 	mov	dptr,#0x0000
      00206D 75 F0 20         [24] 6657 	mov	b, #0x20
      002070 12 0A EC         [24] 6658 	lcall	_fuzzy_ramp
      002073 AC 82            [24] 6659 	mov	r4, dpl
      002075 AD 83            [24] 6660 	mov	r5, dph
      002077 AE F0            [24] 6661 	mov	r6, b
      002079 FF               [12] 6662 	mov	r7, a
      00207A E5 81            [12] 6663 	mov	a,sp
      00207C 24 F6            [12] 6664 	add	a,#0xf6
      00207E F5 81            [12] 6665 	mov	sp,a
      002080 8C 82            [24] 6666 	mov	dpl, r4
      002082 8D 83            [24] 6667 	mov	dph, r5
      002084 8E F0            [24] 6668 	mov	b, r6
      002086 EF               [12] 6669 	mov	a, r7
                           001FD0  6670 	C$controller_8051.c$116$1_0$112 ==.
                                   6671 ;	../../controller_8051.c:116: }
                           001FD0  6672 	C$controller_8051.c$116$1_0$112 ==.
                           001FD0  6673 	XFcontroller_8051$fan_fast$0$0 ==.
      002087 22               [24] 6674 	ret
                                   6675 ;------------------------------------------------------------
                                   6676 ;Allocation info for local variables in function 'calculate_fan_speed'
                                   6677 ;------------------------------------------------------------
                                   6678 ;temperature   Allocated to stack - _bp +1 +4 
                                   6679 ;rules         Allocated to stack - _bp +9 +146 
                                   6680 ;result        Allocated to stack - _bp +155 +4 
                                   6681 ;sloc0         Allocated to stack - _bp +5 +4 
                                   6682 ;------------------------------------------------------------
                           001FD1  6683 	Fcontroller_8051$calculate_fan_speed$0$0 ==.
                           001FD1  6684 	C$controller_8051.c$123$1_0$114 ==.
                                   6685 ;	../../controller_8051.c:123: static float calculate_fan_speed(
                                   6686 ;	-----------------------------------------
                                   6687 ;	 function calculate_fan_speed
                                   6688 ;	-----------------------------------------
      002088                       6689 _calculate_fan_speed:
      002088 C0 08            [24] 6690 	push	_bp
      00208A 85 81 08         [24] 6691 	mov	_bp,sp
      00208D C0 82            [24] 6692 	push	dpl
      00208F C0 83            [24] 6693 	push	dph
      002091 C0 F0            [24] 6694 	push	b
      002093 C0 E0            [24] 6695 	push	acc
      002095 E5 81            [12] 6696 	mov	a,sp
      002097 24 9A            [12] 6697 	add	a,#0x9a
      002099 F5 81            [12] 6698 	mov	sp,a
                           001FE4  6699 	C$controller_8051.c$132$1_0$114 ==.
                                   6700 ;	../../controller_8051.c:132: );
      00209B E5 08            [12] 6701 	mov	a,_bp
      00209D 24 09            [12] 6702 	add	a,#0x09
      00209F FB               [12] 6703 	mov	r3,a
      0020A0 FA               [12] 6704 	mov	r2,a
      0020A1 7E 00            [12] 6705 	mov	r6,#0x00
      0020A3 7F 40            [12] 6706 	mov	r7,#0x40
      0020A5 8A 82            [24] 6707 	mov	dpl, r2
      0020A7 8E 83            [24] 6708 	mov	dph, r6
      0020A9 8F F0            [24] 6709 	mov	b, r7
      0020AB C0 03            [24] 6710 	push	ar3
      0020AD 12 16 63         [24] 6711 	lcall	_fuzzy_rules_create
                           001FF9  6712 	C$controller_8051.c$134$1_0$114 ==.
                                   6713 ;	../../controller_8051.c:134: if (!FUZZY_RULE_ADD(
      0020B0 A8 08            [24] 6714 	mov	r0,_bp
      0020B2 08               [12] 6715 	inc	r0
      0020B3 86 82            [24] 6716 	mov	dpl, @r0
      0020B5 08               [12] 6717 	inc	r0
      0020B6 86 83            [24] 6718 	mov	dph, @r0
      0020B8 08               [12] 6719 	inc	r0
      0020B9 86 F0            [24] 6720 	mov	b, @r0
      0020BB 08               [12] 6721 	inc	r0
      0020BC E6               [12] 6722 	mov	a, @r0
      0020BD 12 1F 71         [24] 6723 	lcall	_temperature_low
      0020C0 C8               [12] 6724 	xch	a,r0
      0020C1 E5 08            [12] 6725 	mov	a,_bp
      0020C3 24 05            [12] 6726 	add	a,#0x05
      0020C5 C8               [12] 6727 	xch	a,r0
      0020C6 A6 82            [24] 6728 	mov	@r0, dpl
      0020C8 08               [12] 6729 	inc	r0
      0020C9 A6 83            [24] 6730 	mov	@r0, dph
      0020CB 08               [12] 6731 	inc	r0
      0020CC A6 F0            [24] 6732 	mov	@r0, b
      0020CE 08               [12] 6733 	inc	r0
      0020CF F6               [12] 6734 	mov	@r0,a
      0020D0 D0 03            [24] 6735 	pop	ar3
      0020D2 8B 02            [24] 6736 	mov	ar2,r3
      0020D4 7E 00            [12] 6737 	mov	r6,#0x00
      0020D6 7F 40            [12] 6738 	mov	r7,#0x40
      0020D8 C0 03            [24] 6739 	push	ar3
      0020DA 74 FD            [12] 6740 	mov	a,#_fan_slow
      0020DC C0 E0            [24] 6741 	push	acc
      0020DE 74 1F            [12] 6742 	mov	a,#(_fan_slow >> 8)
      0020E0 C0 E0            [24] 6743 	push	acc
      0020E2 E5 08            [12] 6744 	mov	a,_bp
      0020E4 24 05            [12] 6745 	add	a,#0x05
      0020E6 F8               [12] 6746 	mov	r0,a
      0020E7 E6               [12] 6747 	mov	a,@r0
      0020E8 C0 E0            [24] 6748 	push	acc
      0020EA 08               [12] 6749 	inc	r0
      0020EB E6               [12] 6750 	mov	a,@r0
      0020EC C0 E0            [24] 6751 	push	acc
      0020EE 08               [12] 6752 	inc	r0
      0020EF E6               [12] 6753 	mov	a,@r0
      0020F0 C0 E0            [24] 6754 	push	acc
      0020F2 08               [12] 6755 	inc	r0
      0020F3 E6               [12] 6756 	mov	a,@r0
      0020F4 C0 E0            [24] 6757 	push	acc
      0020F6 74 2B            [12] 6758 	mov	a,#___str_0
      0020F8 C0 E0            [24] 6759 	push	acc
      0020FA 74 27            [12] 6760 	mov	a,#(___str_0 >> 8)
      0020FC C0 E0            [24] 6761 	push	acc
      0020FE 74 80            [12] 6762 	mov	a,#0x80
      002100 C0 E0            [24] 6763 	push	acc
      002102 8A 82            [24] 6764 	mov	dpl, r2
      002104 8E 83            [24] 6765 	mov	dph, r6
      002106 8F F0            [24] 6766 	mov	b, r7
      002108 12 16 85         [24] 6767 	lcall	_fuzzy_rules_add
      00210B AF 82            [24] 6768 	mov	r7, dpl
      00210D E5 81            [12] 6769 	mov	a,sp
      00210F 24 F7            [12] 6770 	add	a,#0xf7
      002111 F5 81            [12] 6771 	mov	sp,a
      002113 D0 03            [24] 6772 	pop	ar3
      002115 EF               [12] 6773 	mov	a,r7
                           00205F  6774 	C$controller_8051.c$141$2_0$115 ==.
                                   6775 ;	../../controller_8051.c:141: );
      002116 70 17            [24] 6776 	jnz	00102$
      002118 8B 05            [24] 6777 	mov	ar5,r3
      00211A FE               [12] 6778 	mov	r6,a
      00211B 7F 40            [12] 6779 	mov	r7,#0x40
      00211D 8D 82            [24] 6780 	mov	dpl, r5
      00211F 8E 83            [24] 6781 	mov	dph, r6
      002121 8F F0            [24] 6782 	mov	b, r7
      002123 12 1F 4F         [24] 6783 	lcall	_fuzzy_rules_free
                           00206F  6784 	C$controller_8051.c$143$2_0$115 ==.
                                   6785 ;	../../controller_8051.c:143: return 0.0f;
      002126 90 00 00         [24] 6786 	mov	dptr,#0x0000
      002129 E4               [12] 6787 	clr	a
      00212A F5 F0            [12] 6788 	mov	b,a
      00212C 02 22 1D         [24] 6789 	ljmp	00105$
      00212F                       6790 00102$:
                           002078  6791 	C$controller_8051.c$146$1_0$114 ==.
                                   6792 ;	../../controller_8051.c:146: if (!FUZZY_RULE_ADD(
      00212F A8 08            [24] 6793 	mov	r0,_bp
      002131 08               [12] 6794 	inc	r0
      002132 86 82            [24] 6795 	mov	dpl, @r0
      002134 08               [12] 6796 	inc	r0
      002135 86 83            [24] 6797 	mov	dph, @r0
      002137 08               [12] 6798 	inc	r0
      002138 86 F0            [24] 6799 	mov	b, @r0
      00213A 08               [12] 6800 	inc	r0
      00213B E6               [12] 6801 	mov	a, @r0
      00213C C0 03            [24] 6802 	push	ar3
      00213E 12 1F B6         [24] 6803 	lcall	_temperature_high
      002141 C8               [12] 6804 	xch	a,r0
      002142 E5 08            [12] 6805 	mov	a,_bp
      002144 24 05            [12] 6806 	add	a,#0x05
      002146 C8               [12] 6807 	xch	a,r0
      002147 A6 82            [24] 6808 	mov	@r0, dpl
      002149 08               [12] 6809 	inc	r0
      00214A A6 83            [24] 6810 	mov	@r0, dph
      00214C 08               [12] 6811 	inc	r0
      00214D A6 F0            [24] 6812 	mov	@r0, b
      00214F 08               [12] 6813 	inc	r0
      002150 F6               [12] 6814 	mov	@r0,a
      002151 D0 03            [24] 6815 	pop	ar3
      002153 8B 02            [24] 6816 	mov	ar2,r3
      002155 7E 00            [12] 6817 	mov	r6,#0x00
      002157 7F 40            [12] 6818 	mov	r7,#0x40
      002159 C0 03            [24] 6819 	push	ar3
      00215B 74 42            [12] 6820 	mov	a,#_fan_fast
      00215D C0 E0            [24] 6821 	push	acc
      00215F 74 20            [12] 6822 	mov	a,#(_fan_fast >> 8)
      002161 C0 E0            [24] 6823 	push	acc
      002163 E5 08            [12] 6824 	mov	a,_bp
      002165 24 05            [12] 6825 	add	a,#0x05
      002167 F8               [12] 6826 	mov	r0,a
      002168 E6               [12] 6827 	mov	a,@r0
      002169 C0 E0            [24] 6828 	push	acc
      00216B 08               [12] 6829 	inc	r0
      00216C E6               [12] 6830 	mov	a,@r0
      00216D C0 E0            [24] 6831 	push	acc
      00216F 08               [12] 6832 	inc	r0
      002170 E6               [12] 6833 	mov	a,@r0
      002171 C0 E0            [24] 6834 	push	acc
      002173 08               [12] 6835 	inc	r0
      002174 E6               [12] 6836 	mov	a,@r0
      002175 C0 E0            [24] 6837 	push	acc
      002177 74 34            [12] 6838 	mov	a,#___str_1
      002179 C0 E0            [24] 6839 	push	acc
      00217B 74 27            [12] 6840 	mov	a,#(___str_1 >> 8)
      00217D C0 E0            [24] 6841 	push	acc
      00217F 74 80            [12] 6842 	mov	a,#0x80
      002181 C0 E0            [24] 6843 	push	acc
      002183 8A 82            [24] 6844 	mov	dpl, r2
      002185 8E 83            [24] 6845 	mov	dph, r6
      002187 8F F0            [24] 6846 	mov	b, r7
      002189 12 16 85         [24] 6847 	lcall	_fuzzy_rules_add
      00218C AF 82            [24] 6848 	mov	r7, dpl
      00218E E5 81            [12] 6849 	mov	a,sp
      002190 24 F7            [12] 6850 	add	a,#0xf7
      002192 F5 81            [12] 6851 	mov	sp,a
      002194 D0 03            [24] 6852 	pop	ar3
      002196 EF               [12] 6853 	mov	a,r7
                           0020E0  6854 	C$controller_8051.c$153$2_0$116 ==.
                                   6855 ;	../../controller_8051.c:153: );
      002197 70 16            [24] 6856 	jnz	00104$
      002199 8B 05            [24] 6857 	mov	ar5,r3
      00219B FE               [12] 6858 	mov	r6,a
      00219C 7F 40            [12] 6859 	mov	r7,#0x40
      00219E 8D 82            [24] 6860 	mov	dpl, r5
      0021A0 8E 83            [24] 6861 	mov	dph, r6
      0021A2 8F F0            [24] 6862 	mov	b, r7
      0021A4 12 1F 4F         [24] 6863 	lcall	_fuzzy_rules_free
                           0020F0  6864 	C$controller_8051.c$155$2_0$116 ==.
                                   6865 ;	../../controller_8051.c:155: return 0.0f;
      0021A7 90 00 00         [24] 6866 	mov	dptr,#0x0000
      0021AA E4               [12] 6867 	clr	a
      0021AB F5 F0            [12] 6868 	mov	b,a
      0021AD 80 6E            [24] 6869 	sjmp	00105$
      0021AF                       6870 00104$:
                           0020F8  6871 	C$controller_8051.c$160$1_0$114 ==.
                                   6872 ;	../../controller_8051.c:160: &rules,
      0021AF 8B 05            [24] 6873 	mov	ar5,r3
      0021B1 7E 00            [12] 6874 	mov	r6,#0x00
      0021B3 7F 40            [12] 6875 	mov	r7,#0x40
      0021B5 C0 03            [24] 6876 	push	ar3
      0021B7 74 01            [12] 6877 	mov	a,#0x01
      0021B9 C0 E0            [24] 6878 	push	acc
      0021BB E4               [12] 6879 	clr	a
      0021BC C0 E0            [24] 6880 	push	acc
      0021BE C0 E0            [24] 6881 	push	acc
      0021C0 74 20            [12] 6882 	mov	a,#0x20
      0021C2 C0 E0            [24] 6883 	push	acc
      0021C4 74 41            [12] 6884 	mov	a,#0x41
      0021C6 C0 E0            [24] 6885 	push	acc
      0021C8 E4               [12] 6886 	clr	a
      0021C9 C0 E0            [24] 6887 	push	acc
      0021CB C0 E0            [24] 6888 	push	acc
      0021CD 74 C8            [12] 6889 	mov	a,#0xc8
      0021CF C0 E0            [24] 6890 	push	acc
      0021D1 74 42            [12] 6891 	mov	a,#0x42
      0021D3 C0 E0            [24] 6892 	push	acc
      0021D5 E4               [12] 6893 	clr	a
      0021D6 C0 E0            [24] 6894 	push	acc
      0021D8 C0 E0            [24] 6895 	push	acc
      0021DA C0 E0            [24] 6896 	push	acc
      0021DC C0 E0            [24] 6897 	push	acc
      0021DE 8D 82            [24] 6898 	mov	dpl, r5
      0021E0 8E 83            [24] 6899 	mov	dph, r6
      0021E2 8F F0            [24] 6900 	mov	b, r7
      0021E4 12 17 E9         [24] 6901 	lcall	_fuzzy_rules_defuzzify
      0021E7 C8               [12] 6902 	xch	a,r0
      0021E8 E5 08            [12] 6903 	mov	a,_bp
      0021EA 24 9B            [12] 6904 	add	a,#0x9b
      0021EC C8               [12] 6905 	xch	a,r0
      0021ED A6 82            [24] 6906 	mov	@r0, dpl
      0021EF 08               [12] 6907 	inc	r0
      0021F0 A6 83            [24] 6908 	mov	@r0, dph
      0021F2 08               [12] 6909 	inc	r0
      0021F3 A6 F0            [24] 6910 	mov	@r0, b
      0021F5 08               [12] 6911 	inc	r0
      0021F6 F6               [12] 6912 	mov	@r0,a
      0021F7 E5 81            [12] 6913 	mov	a,sp
      0021F9 24 F3            [12] 6914 	add	a,#0xf3
      0021FB F5 81            [12] 6915 	mov	sp,a
      0021FD D0 03            [24] 6916 	pop	ar3
                           002148  6917 	C$controller_8051.c$169$1_0$114 ==.
                                   6918 ;	../../controller_8051.c:169: );
      0021FF 8B 02            [24] 6919 	mov	ar2,r3
      002201 7B 00            [12] 6920 	mov	r3,#0x00
      002203 7F 40            [12] 6921 	mov	r7,#0x40
      002205 8A 82            [24] 6922 	mov	dpl, r2
      002207 8B 83            [24] 6923 	mov	dph, r3
      002209 8F F0            [24] 6924 	mov	b, r7
      00220B 12 1F 4F         [24] 6925 	lcall	_fuzzy_rules_free
                           002157  6926 	C$controller_8051.c$171$1_0$114 ==.
                                   6927 ;	../../controller_8051.c:171: return result;
      00220E E5 08            [12] 6928 	mov	a,_bp
      002210 24 9B            [12] 6929 	add	a,#0x9b
      002212 F8               [12] 6930 	mov	r0,a
      002213 86 82            [24] 6931 	mov	dpl, @r0
      002215 08               [12] 6932 	inc	r0
      002216 86 83            [24] 6933 	mov	dph, @r0
      002218 08               [12] 6934 	inc	r0
      002219 86 F0            [24] 6935 	mov	b, @r0
      00221B 08               [12] 6936 	inc	r0
      00221C E6               [12] 6937 	mov	a, @r0
      00221D                       6938 00105$:
                           002166  6939 	C$controller_8051.c$172$1_0$114 ==.
                                   6940 ;	../../controller_8051.c:172: }
      00221D 85 08 81         [24] 6941 	mov	sp,_bp
      002220 D0 08            [24] 6942 	pop	_bp
                           00216B  6943 	C$controller_8051.c$172$1_0$114 ==.
                           00216B  6944 	XFcontroller_8051$calculate_fan_speed$0$0 ==.
      002222 22               [24] 6945 	ret
                                   6946 ;------------------------------------------------------------
                                   6947 ;Allocation info for local variables in function 'fan_speed_to_pwm'
                                   6948 ;------------------------------------------------------------
                                   6949 ;fan_speed     Allocated to registers r4 r5 r6 r7 
                                   6950 ;------------------------------------------------------------
                           00216C  6951 	Fcontroller_8051$fan_speed_to_pwm$0$0 ==.
                           00216C  6952 	C$controller_8051.c$179$1_0$118 ==.
                                   6953 ;	../../controller_8051.c:179: static unsigned char fan_speed_to_pwm(
                                   6954 ;	-----------------------------------------
                                   6955 ;	 function fan_speed_to_pwm
                                   6956 ;	-----------------------------------------
      002223                       6957 _fan_speed_to_pwm:
      002223 AC 82            [24] 6958 	mov	r4,dpl
      002225 AD 83            [24] 6959 	mov	r5,dph
      002227 AE F0            [24] 6960 	mov	r6,b
      002229 FF               [12] 6961 	mov	r7,a
                           002173  6962 	C$controller_8051.c$183$1_0$118 ==.
                                   6963 ;	../../controller_8051.c:183: if (fan_speed <= 0.0f) {
      00222A C0 07            [24] 6964 	push	ar7
      00222C C0 06            [24] 6965 	push	ar6
      00222E C0 05            [24] 6966 	push	ar5
      002230 C0 04            [24] 6967 	push	ar4
      002232 C0 04            [24] 6968 	push	ar4
      002234 C0 05            [24] 6969 	push	ar5
      002236 C0 06            [24] 6970 	push	ar6
      002238 C0 07            [24] 6971 	push	ar7
      00223A 90 00 00         [24] 6972 	mov	dptr,#0x0000
      00223D E4               [12] 6973 	clr	a
      00223E F5 F0            [12] 6974 	mov	b,a
      002240 12 24 3A         [24] 6975 	lcall	___fslt
      002243 E5 81            [12] 6976 	mov	a,sp
      002245 24 FC            [12] 6977 	add	a,#0xfc
      002247 F5 81            [12] 6978 	mov	sp,a
      002249 D0 04            [24] 6979 	pop	ar4
      00224B D0 05            [24] 6980 	pop	ar5
      00224D D0 06            [24] 6981 	pop	ar6
      00224F D0 07            [24] 6982 	pop	ar7
      002251 E5 82            [12] 6983 	mov	a, dpl
      002253 24 FF            [12] 6984 	add	a,#0xff
      002255 92 00            [24] 6985 	mov	b0,c
      002257 40 05            [24] 6986 	jc	00102$
                           0021A2  6987 	C$controller_8051.c$184$2_0$119 ==.
                                   6988 ;	../../controller_8051.c:184: return 0u;
      002259 75 82 00         [24] 6989 	mov	dpl, #0x00
      00225C 80 66            [24] 6990 	sjmp	00105$
      00225E                       6991 00102$:
                           0021A7  6992 	C$controller_8051.c$187$1_0$118 ==.
                                   6993 ;	../../controller_8051.c:187: if (fan_speed >= 100.0f) {
      00225E C0 07            [24] 6994 	push	ar7
      002260 C0 06            [24] 6995 	push	ar6
      002262 C0 05            [24] 6996 	push	ar5
      002264 C0 04            [24] 6997 	push	ar4
      002266 E4               [12] 6998 	clr	a
      002267 C0 E0            [24] 6999 	push	acc
      002269 C0 E0            [24] 7000 	push	acc
      00226B 74 C8            [12] 7001 	mov	a,#0xc8
      00226D C0 E0            [24] 7002 	push	acc
      00226F 74 42            [12] 7003 	mov	a,#0x42
      002271 C0 E0            [24] 7004 	push	acc
      002273 8C 82            [24] 7005 	mov	dpl, r4
      002275 8D 83            [24] 7006 	mov	dph, r5
      002277 8E F0            [24] 7007 	mov	b, r6
      002279 EF               [12] 7008 	mov	a, r7
      00227A 12 24 3A         [24] 7009 	lcall	___fslt
      00227D E5 81            [12] 7010 	mov	a,sp
      00227F 24 FC            [12] 7011 	add	a,#0xfc
      002281 F5 81            [12] 7012 	mov	sp,a
      002283 D0 04            [24] 7013 	pop	ar4
      002285 D0 05            [24] 7014 	pop	ar5
      002287 D0 06            [24] 7015 	pop	ar6
      002289 D0 07            [24] 7016 	pop	ar7
      00228B E5 82            [12] 7017 	mov	a, dpl
      00228D 24 FF            [12] 7018 	add	a,#0xff
      00228F 92 00            [24] 7019 	mov	b0,c
      002291 40 05            [24] 7020 	jc	00104$
                           0021DC  7021 	C$controller_8051.c$188$2_0$120 ==.
                                   7022 ;	../../controller_8051.c:188: return 100u;
      002293 75 82 64         [24] 7023 	mov	dpl, #0x64
      002296 80 2C            [24] 7024 	sjmp	00105$
      002298                       7025 00104$:
                           0021E1  7026 	C$controller_8051.c$193$1_0$118 ==.
                                   7027 ;	../../controller_8051.c:193: );
      002298 E4               [12] 7028 	clr	a
      002299 C0 E0            [24] 7029 	push	acc
      00229B C0 E0            [24] 7030 	push	acc
      00229D C0 E0            [24] 7031 	push	acc
      00229F 74 3F            [12] 7032 	mov	a,#0x3f
      0022A1 C0 E0            [24] 7033 	push	acc
      0022A3 8C 82            [24] 7034 	mov	dpl, r4
      0022A5 8D 83            [24] 7035 	mov	dph, r5
      0022A7 8E F0            [24] 7036 	mov	b, r6
      0022A9 EF               [12] 7037 	mov	a, r7
      0022AA 12 24 8C         [24] 7038 	lcall	___fsadd
      0022AD AC 82            [24] 7039 	mov	r4, dpl
      0022AF AD 83            [24] 7040 	mov	r5, dph
      0022B1 AE F0            [24] 7041 	mov	r6, b
      0022B3 FF               [12] 7042 	mov	r7, a
      0022B4 E5 81            [12] 7043 	mov	a,sp
      0022B6 24 FC            [12] 7044 	add	a,#0xfc
      0022B8 F5 81            [12] 7045 	mov	sp,a
      0022BA 8C 82            [24] 7046 	mov	dpl, r4
      0022BC 8D 83            [24] 7047 	mov	dph, r5
      0022BE 8E F0            [24] 7048 	mov	b, r6
      0022C0 EF               [12] 7049 	mov	a, r7
      0022C1 12 26 82         [24] 7050 	lcall	___fs2uchar
      0022C4                       7051 00105$:
                           00220D  7052 	C$controller_8051.c$194$1_0$118 ==.
                                   7053 ;	../../controller_8051.c:194: }
                           00220D  7054 	C$controller_8051.c$194$1_0$118 ==.
                           00220D  7055 	XFcontroller_8051$fan_speed_to_pwm$0$0 ==.
      0022C4 22               [24] 7056 	ret
                                   7057 ;------------------------------------------------------------
                                   7058 ;Allocation info for local variables in function 'main'
                                   7059 ;------------------------------------------------------------
                           00220E  7060 	G$main$0$0 ==.
                           00220E  7061 	C$controller_8051.c$211$1_0$122 ==.
                                   7062 ;	../../controller_8051.c:211: void main(void)
                                   7063 ;	-----------------------------------------
                                   7064 ;	 function main
                                   7065 ;	-----------------------------------------
      0022C5                       7066 _main:
                           00220E  7067 	C$controller_8051.c$219$1_0$122 ==.
                                   7068 ;	../../controller_8051.c:219: 42u;
      0022C5 75 61 2A         [24] 7069 	mov	_test_temperature,#0x2a
                           002211  7070 	C$controller_8051.c$225$1_0$122 ==.
                                   7071 ;	../../controller_8051.c:225: 0x55u;
      0022C8 75 80 55         [24] 7072 	mov	_P0,#0x55
                           002214  7073 	C$controller_8051.c$228$1_0$122 ==.
                                   7074 ;	../../controller_8051.c:228: 0x00u;
      0022CB 75 90 00         [24] 7075 	mov	_P1,#0x00
                           002217  7076 	C$controller_8051.c$234$1_0$122 ==.
                                   7077 ;	../../controller_8051.c:234: test_temperature = P2;
      0022CE 85 A0 61         [24] 7078 	mov	_test_temperature,_P2
                           00221A  7079 	C$controller_8051.c$239$2_0$122 ==.
                                   7080 ;	../../controller_8051.c:239: );
      0022D1 85 61 82         [24] 7081 	mov	dpl, _test_temperature
      0022D4 12 26 8A         [24] 7082 	lcall	___uchar2fs
      0022D7 12 20 88         [24] 7083 	lcall	_calculate_fan_speed
      0022DA 85 82 63         [24] 7084 	mov	_test_fan_speed,dpl
      0022DD 85 83 64         [24] 7085 	mov	(_test_fan_speed + 1),dph
      0022E0 85 F0 65         [24] 7086 	mov	(_test_fan_speed + 2),b
      0022E3 F5 66            [12] 7087 	mov	(_test_fan_speed + 3),a
                           00222E  7088 	C$controller_8051.c$243$1_0$122 ==.
                                   7089 ;	../../controller_8051.c:243: test_fan_speed
      0022E5 85 63 82         [24] 7090 	mov	dpl, _test_fan_speed
      0022E8 85 64 83         [24] 7091 	mov	dph, (_test_fan_speed + 1)
      0022EB 85 65 F0         [24] 7092 	mov	b, (_test_fan_speed + 2)
      0022EE E5 66            [12] 7093 	mov	a, (_test_fan_speed + 3)
      0022F0 12 22 23         [24] 7094 	lcall	_fan_speed_to_pwm
      0022F3 85 82 62         [24] 7095 	mov	_test_pwm,dpl
                           00223F  7096 	C$controller_8051.c$250$1_0$122 ==.
                                   7097 ;	../../controller_8051.c:250: test_pwm;
      0022F6 85 62 90         [24] 7098 	mov	_P1,_test_pwm
                           002242  7099 	C$controller_8051.c$256$1_0$122 ==.
                                   7100 ;	../../controller_8051.c:256: 0xAAu;
      0022F9 75 80 AA         [24] 7101 	mov	_P0,#0xaa
      0022FC                       7102 00103$:
      0022FC 80 FE            [24] 7103 	sjmp	00103$
                           002247  7104 	C$controller_8051.c$261$2_0$122 ==.
                                   7105 ;	../../controller_8051.c:261: }
                           002247  7106 	C$controller_8051.c$261$2_0$122 ==.
                           002247  7107 	XG$main$0$0 ==.
      0022FE 22               [24] 7108 	ret
                                   7109 	.area CSEG    (CODE)
                                   7110 	.area CONST   (CODE)
                                   7111 	.area CONST   (CODE)
                           000000  7112 Fcontroller_8051$hedges$0_0$0 == .
      002728                       7113 _hedges:
      002728 01                    7114 	.db #0x01	; 1
      002729 02                    7115 	.db #0x02	; 2
      00272A 03                    7116 	.db #0x03	; 3
                                   7117 	.area CSEG    (CODE)
                           002248  7118 Fcontroller_8051$__str_0$0_0$0 == .
                                   7119 	.area CONST   (CODE)
      00272B                       7120 ___str_0:
      00272B 66 61 6E 5F 73 6C 6F  7121 	.ascii "fan_slow"
             77
      002733 00                    7122 	.db 0x00
                                   7123 	.area CSEG    (CODE)
                           002248  7124 Fcontroller_8051$__str_1$0_0$0 == .
                                   7125 	.area CONST   (CODE)
      002734                       7126 ___str_1:
      002734 66 61 6E 5F 66 61 73  7127 	.ascii "fan_fast"
             74
      00273C 00                    7128 	.db 0x00
                                   7129 	.area CSEG    (CODE)
                                   7130 	.area XINIT   (CODE)
                                   7131 	.area CABS    (ABS,CODE)
