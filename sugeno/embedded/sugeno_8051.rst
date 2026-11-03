                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler
                                      3 ; Version 4.5.0 #15242 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module sugeno_demo
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
                                    133 	.globl _test_vibration
                                    134 	.globl _test_load
                                    135 	.globl _test_temperature
                                    136 	.globl _fuzzy_not
                                    137 	.globl _fuzzy_ramp
                                    138 	.globl _fuzzy_triangle
                                    139 	.globl _fuzzy_trapezoid
                                    140 	.globl _fuzzy_rules_add_8051
                                    141 	.globl _fuzzy_rules_defuzzify
                                    142 	.globl _fuzzy_rules_cog
                                    143 ;--------------------------------------------------------
                                    144 ; special function registers
                                    145 ;--------------------------------------------------------
                                    146 	.area RSEG    (ABS,DATA)
      000000                        147 	.org 0x0000
                           000080   148 G$P0$0_0$0 == 0x0080
                           000080   149 _P0	=	0x0080
                           000081   150 G$SP$0_0$0 == 0x0081
                           000081   151 _SP	=	0x0081
                           000082   152 G$DPL$0_0$0 == 0x0082
                           000082   153 _DPL	=	0x0082
                           000083   154 G$DPH$0_0$0 == 0x0083
                           000083   155 _DPH	=	0x0083
                           000087   156 G$PCON$0_0$0 == 0x0087
                           000087   157 _PCON	=	0x0087
                           000088   158 G$TCON$0_0$0 == 0x0088
                           000088   159 _TCON	=	0x0088
                           000089   160 G$TMOD$0_0$0 == 0x0089
                           000089   161 _TMOD	=	0x0089
                           00008A   162 G$TL0$0_0$0 == 0x008a
                           00008A   163 _TL0	=	0x008a
                           00008B   164 G$TL1$0_0$0 == 0x008b
                           00008B   165 _TL1	=	0x008b
                           00008C   166 G$TH0$0_0$0 == 0x008c
                           00008C   167 _TH0	=	0x008c
                           00008D   168 G$TH1$0_0$0 == 0x008d
                           00008D   169 _TH1	=	0x008d
                           000090   170 G$P1$0_0$0 == 0x0090
                           000090   171 _P1	=	0x0090
                           000098   172 G$SCON$0_0$0 == 0x0098
                           000098   173 _SCON	=	0x0098
                           000099   174 G$SBUF$0_0$0 == 0x0099
                           000099   175 _SBUF	=	0x0099
                           0000A0   176 G$P2$0_0$0 == 0x00a0
                           0000A0   177 _P2	=	0x00a0
                           0000A8   178 G$IE$0_0$0 == 0x00a8
                           0000A8   179 _IE	=	0x00a8
                           0000B0   180 G$P3$0_0$0 == 0x00b0
                           0000B0   181 _P3	=	0x00b0
                           0000B8   182 G$IP$0_0$0 == 0x00b8
                           0000B8   183 _IP	=	0x00b8
                           0000D0   184 G$PSW$0_0$0 == 0x00d0
                           0000D0   185 _PSW	=	0x00d0
                           0000E0   186 G$ACC$0_0$0 == 0x00e0
                           0000E0   187 _ACC	=	0x00e0
                           0000F0   188 G$B$0_0$0 == 0x00f0
                           0000F0   189 _B	=	0x00f0
                           0000C8   190 G$T2CON$0_0$0 == 0x00c8
                           0000C8   191 _T2CON	=	0x00c8
                           0000CA   192 G$RCAP2L$0_0$0 == 0x00ca
                           0000CA   193 _RCAP2L	=	0x00ca
                           0000CB   194 G$RCAP2H$0_0$0 == 0x00cb
                           0000CB   195 _RCAP2H	=	0x00cb
                           0000CC   196 G$TL2$0_0$0 == 0x00cc
                           0000CC   197 _TL2	=	0x00cc
                           0000CD   198 G$TH2$0_0$0 == 0x00cd
                           0000CD   199 _TH2	=	0x00cd
                                    200 ;--------------------------------------------------------
                                    201 ; special function bits
                                    202 ;--------------------------------------------------------
                                    203 	.area RSEG    (ABS,DATA)
      000000                        204 	.org 0x0000
                           000080   205 G$P0_0$0_0$0 == 0x0080
                           000080   206 _P0_0	=	0x0080
                           000081   207 G$P0_1$0_0$0 == 0x0081
                           000081   208 _P0_1	=	0x0081
                           000082   209 G$P0_2$0_0$0 == 0x0082
                           000082   210 _P0_2	=	0x0082
                           000083   211 G$P0_3$0_0$0 == 0x0083
                           000083   212 _P0_3	=	0x0083
                           000084   213 G$P0_4$0_0$0 == 0x0084
                           000084   214 _P0_4	=	0x0084
                           000085   215 G$P0_5$0_0$0 == 0x0085
                           000085   216 _P0_5	=	0x0085
                           000086   217 G$P0_6$0_0$0 == 0x0086
                           000086   218 _P0_6	=	0x0086
                           000087   219 G$P0_7$0_0$0 == 0x0087
                           000087   220 _P0_7	=	0x0087
                           000088   221 G$IT0$0_0$0 == 0x0088
                           000088   222 _IT0	=	0x0088
                           000089   223 G$IE0$0_0$0 == 0x0089
                           000089   224 _IE0	=	0x0089
                           00008A   225 G$IT1$0_0$0 == 0x008a
                           00008A   226 _IT1	=	0x008a
                           00008B   227 G$IE1$0_0$0 == 0x008b
                           00008B   228 _IE1	=	0x008b
                           00008C   229 G$TR0$0_0$0 == 0x008c
                           00008C   230 _TR0	=	0x008c
                           00008D   231 G$TF0$0_0$0 == 0x008d
                           00008D   232 _TF0	=	0x008d
                           00008E   233 G$TR1$0_0$0 == 0x008e
                           00008E   234 _TR1	=	0x008e
                           00008F   235 G$TF1$0_0$0 == 0x008f
                           00008F   236 _TF1	=	0x008f
                           000090   237 G$P1_0$0_0$0 == 0x0090
                           000090   238 _P1_0	=	0x0090
                           000091   239 G$P1_1$0_0$0 == 0x0091
                           000091   240 _P1_1	=	0x0091
                           000092   241 G$P1_2$0_0$0 == 0x0092
                           000092   242 _P1_2	=	0x0092
                           000093   243 G$P1_3$0_0$0 == 0x0093
                           000093   244 _P1_3	=	0x0093
                           000094   245 G$P1_4$0_0$0 == 0x0094
                           000094   246 _P1_4	=	0x0094
                           000095   247 G$P1_5$0_0$0 == 0x0095
                           000095   248 _P1_5	=	0x0095
                           000096   249 G$P1_6$0_0$0 == 0x0096
                           000096   250 _P1_6	=	0x0096
                           000097   251 G$P1_7$0_0$0 == 0x0097
                           000097   252 _P1_7	=	0x0097
                           000098   253 G$RI$0_0$0 == 0x0098
                           000098   254 _RI	=	0x0098
                           000099   255 G$TI$0_0$0 == 0x0099
                           000099   256 _TI	=	0x0099
                           00009A   257 G$RB8$0_0$0 == 0x009a
                           00009A   258 _RB8	=	0x009a
                           00009B   259 G$TB8$0_0$0 == 0x009b
                           00009B   260 _TB8	=	0x009b
                           00009C   261 G$REN$0_0$0 == 0x009c
                           00009C   262 _REN	=	0x009c
                           00009D   263 G$SM2$0_0$0 == 0x009d
                           00009D   264 _SM2	=	0x009d
                           00009E   265 G$SM1$0_0$0 == 0x009e
                           00009E   266 _SM1	=	0x009e
                           00009F   267 G$SM0$0_0$0 == 0x009f
                           00009F   268 _SM0	=	0x009f
                           0000A0   269 G$P2_0$0_0$0 == 0x00a0
                           0000A0   270 _P2_0	=	0x00a0
                           0000A1   271 G$P2_1$0_0$0 == 0x00a1
                           0000A1   272 _P2_1	=	0x00a1
                           0000A2   273 G$P2_2$0_0$0 == 0x00a2
                           0000A2   274 _P2_2	=	0x00a2
                           0000A3   275 G$P2_3$0_0$0 == 0x00a3
                           0000A3   276 _P2_3	=	0x00a3
                           0000A4   277 G$P2_4$0_0$0 == 0x00a4
                           0000A4   278 _P2_4	=	0x00a4
                           0000A5   279 G$P2_5$0_0$0 == 0x00a5
                           0000A5   280 _P2_5	=	0x00a5
                           0000A6   281 G$P2_6$0_0$0 == 0x00a6
                           0000A6   282 _P2_6	=	0x00a6
                           0000A7   283 G$P2_7$0_0$0 == 0x00a7
                           0000A7   284 _P2_7	=	0x00a7
                           0000A8   285 G$EX0$0_0$0 == 0x00a8
                           0000A8   286 _EX0	=	0x00a8
                           0000A9   287 G$ET0$0_0$0 == 0x00a9
                           0000A9   288 _ET0	=	0x00a9
                           0000AA   289 G$EX1$0_0$0 == 0x00aa
                           0000AA   290 _EX1	=	0x00aa
                           0000AB   291 G$ET1$0_0$0 == 0x00ab
                           0000AB   292 _ET1	=	0x00ab
                           0000AC   293 G$ES$0_0$0 == 0x00ac
                           0000AC   294 _ES	=	0x00ac
                           0000AF   295 G$EA$0_0$0 == 0x00af
                           0000AF   296 _EA	=	0x00af
                           0000B0   297 G$P3_0$0_0$0 == 0x00b0
                           0000B0   298 _P3_0	=	0x00b0
                           0000B1   299 G$P3_1$0_0$0 == 0x00b1
                           0000B1   300 _P3_1	=	0x00b1
                           0000B2   301 G$P3_2$0_0$0 == 0x00b2
                           0000B2   302 _P3_2	=	0x00b2
                           0000B3   303 G$P3_3$0_0$0 == 0x00b3
                           0000B3   304 _P3_3	=	0x00b3
                           0000B4   305 G$P3_4$0_0$0 == 0x00b4
                           0000B4   306 _P3_4	=	0x00b4
                           0000B5   307 G$P3_5$0_0$0 == 0x00b5
                           0000B5   308 _P3_5	=	0x00b5
                           0000B6   309 G$P3_6$0_0$0 == 0x00b6
                           0000B6   310 _P3_6	=	0x00b6
                           0000B7   311 G$P3_7$0_0$0 == 0x00b7
                           0000B7   312 _P3_7	=	0x00b7
                           0000B0   313 G$RXD$0_0$0 == 0x00b0
                           0000B0   314 _RXD	=	0x00b0
                           0000B1   315 G$TXD$0_0$0 == 0x00b1
                           0000B1   316 _TXD	=	0x00b1
                           0000B2   317 G$INT0$0_0$0 == 0x00b2
                           0000B2   318 _INT0	=	0x00b2
                           0000B3   319 G$INT1$0_0$0 == 0x00b3
                           0000B3   320 _INT1	=	0x00b3
                           0000B4   321 G$T0$0_0$0 == 0x00b4
                           0000B4   322 _T0	=	0x00b4
                           0000B5   323 G$T1$0_0$0 == 0x00b5
                           0000B5   324 _T1	=	0x00b5
                           0000B6   325 G$WR$0_0$0 == 0x00b6
                           0000B6   326 _WR	=	0x00b6
                           0000B7   327 G$RD$0_0$0 == 0x00b7
                           0000B7   328 _RD	=	0x00b7
                           0000B8   329 G$PX0$0_0$0 == 0x00b8
                           0000B8   330 _PX0	=	0x00b8
                           0000B9   331 G$PT0$0_0$0 == 0x00b9
                           0000B9   332 _PT0	=	0x00b9
                           0000BA   333 G$PX1$0_0$0 == 0x00ba
                           0000BA   334 _PX1	=	0x00ba
                           0000BB   335 G$PT1$0_0$0 == 0x00bb
                           0000BB   336 _PT1	=	0x00bb
                           0000BC   337 G$PS$0_0$0 == 0x00bc
                           0000BC   338 _PS	=	0x00bc
                           0000D0   339 G$P$0_0$0 == 0x00d0
                           0000D0   340 _P	=	0x00d0
                           0000D1   341 G$F1$0_0$0 == 0x00d1
                           0000D1   342 _F1	=	0x00d1
                           0000D2   343 G$OV$0_0$0 == 0x00d2
                           0000D2   344 _OV	=	0x00d2
                           0000D3   345 G$RS0$0_0$0 == 0x00d3
                           0000D3   346 _RS0	=	0x00d3
                           0000D4   347 G$RS1$0_0$0 == 0x00d4
                           0000D4   348 _RS1	=	0x00d4
                           0000D5   349 G$F0$0_0$0 == 0x00d5
                           0000D5   350 _F0	=	0x00d5
                           0000D6   351 G$AC$0_0$0 == 0x00d6
                           0000D6   352 _AC	=	0x00d6
                           0000D7   353 G$CY$0_0$0 == 0x00d7
                           0000D7   354 _CY	=	0x00d7
                           0000AD   355 G$ET2$0_0$0 == 0x00ad
                           0000AD   356 _ET2	=	0x00ad
                           0000BD   357 G$PT2$0_0$0 == 0x00bd
                           0000BD   358 _PT2	=	0x00bd
                           0000C8   359 G$T2CON_0$0_0$0 == 0x00c8
                           0000C8   360 _T2CON_0	=	0x00c8
                           0000C9   361 G$T2CON_1$0_0$0 == 0x00c9
                           0000C9   362 _T2CON_1	=	0x00c9
                           0000CA   363 G$T2CON_2$0_0$0 == 0x00ca
                           0000CA   364 _T2CON_2	=	0x00ca
                           0000CB   365 G$T2CON_3$0_0$0 == 0x00cb
                           0000CB   366 _T2CON_3	=	0x00cb
                           0000CC   367 G$T2CON_4$0_0$0 == 0x00cc
                           0000CC   368 _T2CON_4	=	0x00cc
                           0000CD   369 G$T2CON_5$0_0$0 == 0x00cd
                           0000CD   370 _T2CON_5	=	0x00cd
                           0000CE   371 G$T2CON_6$0_0$0 == 0x00ce
                           0000CE   372 _T2CON_6	=	0x00ce
                           0000CF   373 G$T2CON_7$0_0$0 == 0x00cf
                           0000CF   374 _T2CON_7	=	0x00cf
                           0000C8   375 G$CP_RL2$0_0$0 == 0x00c8
                           0000C8   376 _CP_RL2	=	0x00c8
                           0000C9   377 G$C_T2$0_0$0 == 0x00c9
                           0000C9   378 _C_T2	=	0x00c9
                           0000CA   379 G$TR2$0_0$0 == 0x00ca
                           0000CA   380 _TR2	=	0x00ca
                           0000CB   381 G$EXEN2$0_0$0 == 0x00cb
                           0000CB   382 _EXEN2	=	0x00cb
                           0000CC   383 G$TCLK$0_0$0 == 0x00cc
                           0000CC   384 _TCLK	=	0x00cc
                           0000CD   385 G$RCLK$0_0$0 == 0x00cd
                           0000CD   386 _RCLK	=	0x00cd
                           0000CE   387 G$EXF2$0_0$0 == 0x00ce
                           0000CE   388 _EXF2	=	0x00ce
                           0000CF   389 G$TF2$0_0$0 == 0x00cf
                           0000CF   390 _TF2	=	0x00cf
                                    391 ;--------------------------------------------------------
                                    392 ; overlayable register banks
                                    393 ;--------------------------------------------------------
                                    394 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        395 	.ds 8
                                    396 ;--------------------------------------------------------
                                    397 ; overlayable bit register bank
                                    398 ;--------------------------------------------------------
                                    399 	.area BIT_BANK	(REL,OVR,DATA)
      000020                        400 bits:
      000020                        401 	.ds 1
                           008000   402 	b0 = bits[0]
                           008100   403 	b1 = bits[1]
                           008200   404 	b2 = bits[2]
                           008300   405 	b3 = bits[3]
                           008400   406 	b4 = bits[4]
                           008500   407 	b5 = bits[5]
                           008600   408 	b6 = bits[6]
                           008700   409 	b7 = bits[7]
                                    410 ;--------------------------------------------------------
                                    411 ; internal ram data
                                    412 ;--------------------------------------------------------
                                    413 	.area DSEG    (DATA)
                           000000   414 G$test_temperature$0_0$0==.
      000008                        415 _test_temperature::
      000008                        416 	.ds 1
                           000001   417 G$test_load$0_0$0==.
      000009                        418 _test_load::
      000009                        419 	.ds 1
                           000002   420 G$test_vibration$0_0$0==.
      00000A                        421 _test_vibration::
      00000A                        422 	.ds 1
                           000003   423 G$test_pwm$0_0$0==.
      00000B                        424 _test_pwm::
      00000B                        425 	.ds 1
                           000004   426 G$test_fan_speed$0_0$0==.
      00000C                        427 _test_fan_speed::
      00000C                        428 	.ds 4
                                    429 ;--------------------------------------------------------
                                    430 ; overlayable items in internal ram
                                    431 ;--------------------------------------------------------
                                    432 ;--------------------------------------------------------
                                    433 ; Stack segment in internal ram
                                    434 ;--------------------------------------------------------
                                    435 	.area SSEG
      000021                        436 __start__stack:
      000021                        437 	.ds	1
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
                           000000   555 	C$sugeno_demo.c$17$2_0$81 ==.
                                    556 ;	../../sugeno_demo.c:17: volatile unsigned char test_temperature = 0u;
      0000A5 75 08 00         [24]  557 	mov	_test_temperature,#0x00
                           000003   558 	C$sugeno_demo.c$18$2_0$81 ==.
                                    559 ;	../../sugeno_demo.c:18: volatile unsigned char test_load = 0u;
      0000A8 75 09 00         [24]  560 	mov	_test_load,#0x00
                           000006   561 	C$sugeno_demo.c$19$2_0$81 ==.
                                    562 ;	../../sugeno_demo.c:19: volatile unsigned char test_vibration = 0u;
      0000AB 75 0A 00         [24]  563 	mov	_test_vibration,#0x00
                           000009   564 	C$sugeno_demo.c$20$2_0$81 ==.
                                    565 ;	../../sugeno_demo.c:20: volatile unsigned char test_pwm = 0u;
      0000AE 75 0B 00         [24]  566 	mov	_test_pwm,#0x00
                           00000C   567 	C$sugeno_demo.c$21$2_0$81 ==.
                                    568 ;	../../sugeno_demo.c:21: volatile float test_fan_speed = 0.0f;
      0000B1 E4               [12]  569 	clr	a
      0000B2 F5 0C            [12]  570 	mov	_test_fan_speed,a
      0000B4 F5 0D            [12]  571 	mov	(_test_fan_speed + 1),a
      0000B6 F5 0E            [12]  572 	mov	(_test_fan_speed + 2),a
      0000B8 F5 0F            [12]  573 	mov	(_test_fan_speed + 3),a
                                    574 	.area GSFINAL (CODE)
      0000BA 02 00 49         [24]  575 	ljmp	__sdcc_program_startup
                                    576 ;--------------------------------------------------------
                                    577 ; Home
                                    578 ;--------------------------------------------------------
                                    579 	.area HOME    (CODE)
                                    580 	.area HOME    (CODE)
      000049                        581 __sdcc_program_startup:
      000049 02 2A 73         [24]  582 	ljmp	_main
                                    583 ;	return from main will return to caller
                                    584 ;--------------------------------------------------------
                                    585 ; code
                                    586 ;--------------------------------------------------------
                                    587 	.area CSEG    (CODE)
                                    588 ;------------------------------------------------------------
                                    589 ;Allocation info for local variables in function 'fuzzy_8051_and2'
                                    590 ;------------------------------------------------------------
                                    591 ;a             Allocated to stack - _bp -6 +4 
                                    592 ;b             Allocated to stack - _bp -10 +4 
                                    593 ;method        Allocated to registers r7 
                                    594 ;value         Allocated to registers r4 r5 r6 r7 
                                    595 ;------------------------------------------------------------
                           000000   596 	Fsugeno_demo$fuzzy_8051_and2$0$0 ==.
                           000000   597 	C$fuzzy.h$55$0_0$11 ==.
                                    598 ;	../../fuzzy.h:55: static float fuzzy_8051_and2(fuzzy_logic_method_t method, float a, float b) { if (method == FUZZY_LOGIC_ALGEBRAIC) return a * b; if (method == FUZZY_LOGIC_BOUNDED) { float value = a + b - 1.0f; return value > 0.0f ? value : 0.0f; } return a < b ? a : b; }
                                    599 ;	-----------------------------------------
                                    600 ;	 function fuzzy_8051_and2
                                    601 ;	-----------------------------------------
      0000BD                        602 _fuzzy_8051_and2:
                           000007   603 	ar7 = 0x07
                           000006   604 	ar6 = 0x06
                           000005   605 	ar5 = 0x05
                           000004   606 	ar4 = 0x04
                           000003   607 	ar3 = 0x03
                           000002   608 	ar2 = 0x02
                           000001   609 	ar1 = 0x01
                           000000   610 	ar0 = 0x00
      0000BD C0 10            [24]  611 	push	_bp
      0000BF 85 81 10         [24]  612 	mov	_bp,sp
      0000C2 AF 82            [24]  613 	mov	r7, dpl
      0000C4 BF 01 3D         [24]  614 	cjne	r7,#0x01,00102$
      0000C7 E5 10            [12]  615 	mov	a,_bp
      0000C9 24 F6            [12]  616 	add	a,#0xf6
      0000CB F8               [12]  617 	mov	r0,a
      0000CC E6               [12]  618 	mov	a,@r0
      0000CD C0 E0            [24]  619 	push	acc
      0000CF 08               [12]  620 	inc	r0
      0000D0 E6               [12]  621 	mov	a,@r0
      0000D1 C0 E0            [24]  622 	push	acc
      0000D3 08               [12]  623 	inc	r0
      0000D4 E6               [12]  624 	mov	a,@r0
      0000D5 C0 E0            [24]  625 	push	acc
      0000D7 08               [12]  626 	inc	r0
      0000D8 E6               [12]  627 	mov	a,@r0
      0000D9 C0 E0            [24]  628 	push	acc
      0000DB E5 10            [12]  629 	mov	a,_bp
      0000DD 24 FA            [12]  630 	add	a,#0xfa
      0000DF F8               [12]  631 	mov	r0,a
      0000E0 86 82            [24]  632 	mov	dpl, @r0
      0000E2 08               [12]  633 	inc	r0
      0000E3 86 83            [24]  634 	mov	dph, @r0
      0000E5 08               [12]  635 	inc	r0
      0000E6 86 F0            [24]  636 	mov	b, @r0
      0000E8 08               [12]  637 	inc	r0
      0000E9 E6               [12]  638 	mov	a, @r0
      0000EA 12 2A B5         [24]  639 	lcall	___fsmul
      0000ED AB 82            [24]  640 	mov	r3, dpl
      0000EF AC 83            [24]  641 	mov	r4, dph
      0000F1 AD F0            [24]  642 	mov	r5, b
      0000F3 FE               [12]  643 	mov	r6, a
      0000F4 E5 81            [12]  644 	mov	a,sp
      0000F6 24 FC            [12]  645 	add	a,#0xfc
      0000F8 F5 81            [12]  646 	mov	sp,a
      0000FA 8B 82            [24]  647 	mov	dpl, r3
      0000FC 8C 83            [24]  648 	mov	dph, r4
      0000FE 8D F0            [24]  649 	mov	b, r5
      000100 EE               [12]  650 	mov	a, r6
      000101 02 01 F6         [24]  651 	ljmp	00105$
      000104                        652 00102$:
      000104 BF 02 02         [24]  653 	cjne	r7,#0x02,00137$
      000107 80 03            [24]  654 	sjmp	00138$
      000109                        655 00137$:
      000109 02 01 9C         [24]  656 	ljmp	00104$
      00010C                        657 00138$:
      00010C E5 10            [12]  658 	mov	a,_bp
      00010E 24 F6            [12]  659 	add	a,#0xf6
      000110 F8               [12]  660 	mov	r0,a
      000111 E6               [12]  661 	mov	a,@r0
      000112 C0 E0            [24]  662 	push	acc
      000114 08               [12]  663 	inc	r0
      000115 E6               [12]  664 	mov	a,@r0
      000116 C0 E0            [24]  665 	push	acc
      000118 08               [12]  666 	inc	r0
      000119 E6               [12]  667 	mov	a,@r0
      00011A C0 E0            [24]  668 	push	acc
      00011C 08               [12]  669 	inc	r0
      00011D E6               [12]  670 	mov	a,@r0
      00011E C0 E0            [24]  671 	push	acc
      000120 E5 10            [12]  672 	mov	a,_bp
      000122 24 FA            [12]  673 	add	a,#0xfa
      000124 F8               [12]  674 	mov	r0,a
      000125 86 82            [24]  675 	mov	dpl, @r0
      000127 08               [12]  676 	inc	r0
      000128 86 83            [24]  677 	mov	dph, @r0
      00012A 08               [12]  678 	inc	r0
      00012B 86 F0            [24]  679 	mov	b, @r0
      00012D 08               [12]  680 	inc	r0
      00012E E6               [12]  681 	mov	a, @r0
      00012F 12 2C 15         [24]  682 	lcall	___fsadd
      000132 AC 82            [24]  683 	mov	r4, dpl
      000134 AD 83            [24]  684 	mov	r5, dph
      000136 AE F0            [24]  685 	mov	r6, b
      000138 FF               [12]  686 	mov	r7, a
      000139 E5 81            [12]  687 	mov	a,sp
      00013B 24 FC            [12]  688 	add	a,#0xfc
      00013D F5 81            [12]  689 	mov	sp,a
      00013F E4               [12]  690 	clr	a
      000140 C0 E0            [24]  691 	push	acc
      000142 C0 E0            [24]  692 	push	acc
      000144 74 80            [12]  693 	mov	a,#0x80
      000146 C0 E0            [24]  694 	push	acc
      000148 74 3F            [12]  695 	mov	a,#0x3f
      00014A C0 E0            [24]  696 	push	acc
      00014C 8C 82            [24]  697 	mov	dpl, r4
      00014E 8D 83            [24]  698 	mov	dph, r5
      000150 8E F0            [24]  699 	mov	b, r6
      000152 EF               [12]  700 	mov	a, r7
      000153 12 2A AA         [24]  701 	lcall	___fssub
      000156 AC 82            [24]  702 	mov	r4, dpl
      000158 AD 83            [24]  703 	mov	r5, dph
      00015A AE F0            [24]  704 	mov	r6, b
      00015C FF               [12]  705 	mov	r7, a
      00015D E5 81            [12]  706 	mov	a,sp
      00015F 24 FC            [12]  707 	add	a,#0xfc
      000161 F5 81            [12]  708 	mov	sp,a
      000163 C0 07            [24]  709 	push	ar7
      000165 C0 06            [24]  710 	push	ar6
      000167 C0 05            [24]  711 	push	ar5
      000169 C0 04            [24]  712 	push	ar4
      00016B C0 04            [24]  713 	push	ar4
      00016D C0 05            [24]  714 	push	ar5
      00016F C0 06            [24]  715 	push	ar6
      000171 C0 07            [24]  716 	push	ar7
      000173 90 00 00         [24]  717 	mov	dptr,#0x0000
      000176 E4               [12]  718 	clr	a
      000177 F5 F0            [12]  719 	mov	b,a
      000179 12 2B E5         [24]  720 	lcall	___fslt
      00017C AB 82            [24]  721 	mov	r3, dpl
      00017E E5 81            [12]  722 	mov	a,sp
      000180 24 FC            [12]  723 	add	a,#0xfc
      000182 F5 81            [12]  724 	mov	sp,a
      000184 D0 04            [24]  725 	pop	ar4
      000186 D0 05            [24]  726 	pop	ar5
      000188 D0 06            [24]  727 	pop	ar6
      00018A D0 07            [24]  728 	pop	ar7
      00018C EB               [12]  729 	mov	a,r3
      00018D 70 04            [24]  730 	jnz	00108$
      00018F FC               [12]  731 	mov	r4,a
      000190 FD               [12]  732 	mov	r5,a
      000191 FE               [12]  733 	mov	r6,a
      000192 FF               [12]  734 	mov	r7,a
      000193                        735 00108$:
      000193 8C 82            [24]  736 	mov	dpl, r4
      000195 8D 83            [24]  737 	mov	dph, r5
      000197 8E F0            [24]  738 	mov	b, r6
      000199 EF               [12]  739 	mov	a, r7
      00019A 80 5A            [24]  740 	sjmp	00105$
      00019C                        741 00104$:
      00019C E5 10            [12]  742 	mov	a,_bp
      00019E 24 F6            [12]  743 	add	a,#0xf6
      0001A0 F8               [12]  744 	mov	r0,a
      0001A1 E6               [12]  745 	mov	a,@r0
      0001A2 C0 E0            [24]  746 	push	acc
      0001A4 08               [12]  747 	inc	r0
      0001A5 E6               [12]  748 	mov	a,@r0
      0001A6 C0 E0            [24]  749 	push	acc
      0001A8 08               [12]  750 	inc	r0
      0001A9 E6               [12]  751 	mov	a,@r0
      0001AA C0 E0            [24]  752 	push	acc
      0001AC 08               [12]  753 	inc	r0
      0001AD E6               [12]  754 	mov	a,@r0
      0001AE C0 E0            [24]  755 	push	acc
      0001B0 E5 10            [12]  756 	mov	a,_bp
      0001B2 24 FA            [12]  757 	add	a,#0xfa
      0001B4 F8               [12]  758 	mov	r0,a
      0001B5 86 82            [24]  759 	mov	dpl, @r0
      0001B7 08               [12]  760 	inc	r0
      0001B8 86 83            [24]  761 	mov	dph, @r0
      0001BA 08               [12]  762 	inc	r0
      0001BB 86 F0            [24]  763 	mov	b, @r0
      0001BD 08               [12]  764 	inc	r0
      0001BE E6               [12]  765 	mov	a, @r0
      0001BF 12 2B E5         [24]  766 	lcall	___fslt
      0001C2 AF 82            [24]  767 	mov	r7, dpl
      0001C4 E5 81            [12]  768 	mov	a,sp
      0001C6 24 FC            [12]  769 	add	a,#0xfc
      0001C8 F5 81            [12]  770 	mov	sp,a
      0001CA EF               [12]  771 	mov	a,r7
      0001CB 60 12            [24]  772 	jz	00109$
      0001CD E5 10            [12]  773 	mov	a,_bp
      0001CF 24 FA            [12]  774 	add	a,#0xfa
      0001D1 F8               [12]  775 	mov	r0,a
      0001D2 86 04            [24]  776 	mov	ar4,@r0
      0001D4 08               [12]  777 	inc	r0
      0001D5 86 05            [24]  778 	mov	ar5,@r0
      0001D7 08               [12]  779 	inc	r0
      0001D8 86 06            [24]  780 	mov	ar6,@r0
      0001DA 08               [12]  781 	inc	r0
      0001DB 86 07            [24]  782 	mov	ar7,@r0
      0001DD 80 10            [24]  783 	sjmp	00110$
      0001DF                        784 00109$:
      0001DF E5 10            [12]  785 	mov	a,_bp
      0001E1 24 F6            [12]  786 	add	a,#0xf6
      0001E3 F8               [12]  787 	mov	r0,a
      0001E4 86 04            [24]  788 	mov	ar4,@r0
      0001E6 08               [12]  789 	inc	r0
      0001E7 86 05            [24]  790 	mov	ar5,@r0
      0001E9 08               [12]  791 	inc	r0
      0001EA 86 06            [24]  792 	mov	ar6,@r0
      0001EC 08               [12]  793 	inc	r0
      0001ED 86 07            [24]  794 	mov	ar7,@r0
      0001EF                        795 00110$:
      0001EF 8C 82            [24]  796 	mov	dpl, r4
      0001F1 8D 83            [24]  797 	mov	dph, r5
      0001F3 8E F0            [24]  798 	mov	b, r6
      0001F5 EF               [12]  799 	mov	a, r7
      0001F6                        800 00105$:
      0001F6 D0 10            [24]  801 	pop	_bp
                           00013B   802 	C$fuzzy.h$55$1_0$11 ==.
                           00013B   803 	XFsugeno_demo$fuzzy_8051_and2$0$0 ==.
      0001F8 22               [24]  804 	ret
                                    805 ;------------------------------------------------------------
                                    806 ;Allocation info for local variables in function 'fuzzy_8051_and3'
                                    807 ;------------------------------------------------------------
                                    808 ;a             Allocated to stack - _bp -6 +4 
                                    809 ;b             Allocated to stack - _bp -10 +4 
                                    810 ;c             Allocated to stack - _bp -14 +4 
                                    811 ;method        Allocated to registers r7 
                                    812 ;------------------------------------------------------------
                           00013C   813 	Fsugeno_demo$fuzzy_8051_and3$0$0 ==.
                           00013C   814 	C$fuzzy.h$56$1_0$14 ==.
                                    815 ;	../../fuzzy.h:56: static float fuzzy_8051_and3(fuzzy_logic_method_t method, float a, float b, float c) { return fuzzy_8051_and2(method, fuzzy_8051_and2(method, a, b), c); }
                                    816 ;	-----------------------------------------
                                    817 ;	 function fuzzy_8051_and3
                                    818 ;	-----------------------------------------
      0001F9                        819 _fuzzy_8051_and3:
      0001F9 C0 10            [24]  820 	push	_bp
      0001FB 85 81 10         [24]  821 	mov	_bp,sp
      0001FE AF 82            [24]  822 	mov	r7, dpl
      000200 C0 07            [24]  823 	push	ar7
      000202 E5 10            [12]  824 	mov	a,_bp
      000204 24 F6            [12]  825 	add	a,#0xf6
      000206 F8               [12]  826 	mov	r0,a
      000207 E6               [12]  827 	mov	a,@r0
      000208 C0 E0            [24]  828 	push	acc
      00020A 08               [12]  829 	inc	r0
      00020B E6               [12]  830 	mov	a,@r0
      00020C C0 E0            [24]  831 	push	acc
      00020E 08               [12]  832 	inc	r0
      00020F E6               [12]  833 	mov	a,@r0
      000210 C0 E0            [24]  834 	push	acc
      000212 08               [12]  835 	inc	r0
      000213 E6               [12]  836 	mov	a,@r0
      000214 C0 E0            [24]  837 	push	acc
      000216 E5 10            [12]  838 	mov	a,_bp
      000218 24 FA            [12]  839 	add	a,#0xfa
      00021A F8               [12]  840 	mov	r0,a
      00021B E6               [12]  841 	mov	a,@r0
      00021C C0 E0            [24]  842 	push	acc
      00021E 08               [12]  843 	inc	r0
      00021F E6               [12]  844 	mov	a,@r0
      000220 C0 E0            [24]  845 	push	acc
      000222 08               [12]  846 	inc	r0
      000223 E6               [12]  847 	mov	a,@r0
      000224 C0 E0            [24]  848 	push	acc
      000226 08               [12]  849 	inc	r0
      000227 E6               [12]  850 	mov	a,@r0
      000228 C0 E0            [24]  851 	push	acc
      00022A 8F 82            [24]  852 	mov	dpl, r7
      00022C 12 00 BD         [24]  853 	lcall	_fuzzy_8051_and2
      00022F AB 82            [24]  854 	mov	r3, dpl
      000231 AC 83            [24]  855 	mov	r4, dph
      000233 AD F0            [24]  856 	mov	r5, b
      000235 FE               [12]  857 	mov	r6, a
      000236 E5 81            [12]  858 	mov	a,sp
      000238 24 F8            [12]  859 	add	a,#0xf8
      00023A F5 81            [12]  860 	mov	sp,a
      00023C D0 07            [24]  861 	pop	ar7
      00023E E5 10            [12]  862 	mov	a,_bp
      000240 24 F2            [12]  863 	add	a,#0xf2
      000242 F8               [12]  864 	mov	r0,a
      000243 E6               [12]  865 	mov	a,@r0
      000244 C0 E0            [24]  866 	push	acc
      000246 08               [12]  867 	inc	r0
      000247 E6               [12]  868 	mov	a,@r0
      000248 C0 E0            [24]  869 	push	acc
      00024A 08               [12]  870 	inc	r0
      00024B E6               [12]  871 	mov	a,@r0
      00024C C0 E0            [24]  872 	push	acc
      00024E 08               [12]  873 	inc	r0
      00024F E6               [12]  874 	mov	a,@r0
      000250 C0 E0            [24]  875 	push	acc
      000252 C0 03            [24]  876 	push	ar3
      000254 C0 04            [24]  877 	push	ar4
      000256 C0 05            [24]  878 	push	ar5
      000258 C0 06            [24]  879 	push	ar6
      00025A 8F 82            [24]  880 	mov	dpl, r7
      00025C 12 00 BD         [24]  881 	lcall	_fuzzy_8051_and2
      00025F AC 82            [24]  882 	mov	r4, dpl
      000261 AD 83            [24]  883 	mov	r5, dph
      000263 AE F0            [24]  884 	mov	r6, b
      000265 FF               [12]  885 	mov	r7, a
      000266 E5 81            [12]  886 	mov	a,sp
      000268 24 F8            [12]  887 	add	a,#0xf8
      00026A F5 81            [12]  888 	mov	sp,a
      00026C 8C 82            [24]  889 	mov	dpl, r4
      00026E 8D 83            [24]  890 	mov	dph, r5
      000270 8E F0            [24]  891 	mov	b, r6
      000272 EF               [12]  892 	mov	a, r7
      000273 D0 10            [24]  893 	pop	_bp
                           0001B8   894 	C$fuzzy.h$56$1_0$14 ==.
                           0001B8   895 	XFsugeno_demo$fuzzy_8051_and3$0$0 ==.
      000275 22               [24]  896 	ret
                                    897 ;------------------------------------------------------------
                                    898 ;Allocation info for local variables in function 'fuzzy_8051_or2'
                                    899 ;------------------------------------------------------------
                                    900 ;a             Allocated to stack - _bp -6 +4 
                                    901 ;b             Allocated to stack - _bp -10 +4 
                                    902 ;method        Allocated to registers r7 
                                    903 ;value         Allocated to registers r4 r5 r6 r7 
                                    904 ;sloc0         Allocated to stack - _bp +1 +4 
                                    905 ;------------------------------------------------------------
                           0001B9   906 	Fsugeno_demo$fuzzy_8051_or2$0$0 ==.
                           0001B9   907 	C$fuzzy.h$57$1_0$16 ==.
                                    908 ;	../../fuzzy.h:57: static float fuzzy_8051_or2(fuzzy_logic_method_t method, float a, float b) { if (method == FUZZY_LOGIC_ALGEBRAIC) return a + b - a * b; if (method == FUZZY_LOGIC_BOUNDED) { float value = a + b; return value < 1.0f ? value : 1.0f; } return a > b ? a : b; }
                                    909 ;	-----------------------------------------
                                    910 ;	 function fuzzy_8051_or2
                                    911 ;	-----------------------------------------
      000276                        912 _fuzzy_8051_or2:
      000276 C0 10            [24]  913 	push	_bp
      000278 E5 81            [12]  914 	mov	a,sp
      00027A F5 10            [12]  915 	mov	_bp,a
      00027C 24 04            [12]  916 	add	a,#0x04
      00027E F5 81            [12]  917 	mov	sp,a
      000280 AF 82            [24]  918 	mov	r7, dpl
      000282 BF 01 02         [24]  919 	cjne	r7,#0x01,00135$
      000285 80 03            [24]  920 	sjmp	00136$
      000287                        921 00135$:
      000287 02 03 25         [24]  922 	ljmp	00102$
      00028A                        923 00136$:
      00028A E5 10            [12]  924 	mov	a,_bp
      00028C 24 F6            [12]  925 	add	a,#0xf6
      00028E F8               [12]  926 	mov	r0,a
      00028F E6               [12]  927 	mov	a,@r0
      000290 C0 E0            [24]  928 	push	acc
      000292 08               [12]  929 	inc	r0
      000293 E6               [12]  930 	mov	a,@r0
      000294 C0 E0            [24]  931 	push	acc
      000296 08               [12]  932 	inc	r0
      000297 E6               [12]  933 	mov	a,@r0
      000298 C0 E0            [24]  934 	push	acc
      00029A 08               [12]  935 	inc	r0
      00029B E6               [12]  936 	mov	a,@r0
      00029C C0 E0            [24]  937 	push	acc
      00029E E5 10            [12]  938 	mov	a,_bp
      0002A0 24 FA            [12]  939 	add	a,#0xfa
      0002A2 F8               [12]  940 	mov	r0,a
      0002A3 86 82            [24]  941 	mov	dpl, @r0
      0002A5 08               [12]  942 	inc	r0
      0002A6 86 83            [24]  943 	mov	dph, @r0
      0002A8 08               [12]  944 	inc	r0
      0002A9 86 F0            [24]  945 	mov	b, @r0
      0002AB 08               [12]  946 	inc	r0
      0002AC E6               [12]  947 	mov	a, @r0
      0002AD 12 2C 15         [24]  948 	lcall	___fsadd
      0002B0 A8 10            [24]  949 	mov	r0,_bp
      0002B2 08               [12]  950 	inc	r0
      0002B3 A6 82            [24]  951 	mov	@r0, dpl
      0002B5 08               [12]  952 	inc	r0
      0002B6 A6 83            [24]  953 	mov	@r0, dph
      0002B8 08               [12]  954 	inc	r0
      0002B9 A6 F0            [24]  955 	mov	@r0, b
      0002BB 08               [12]  956 	inc	r0
      0002BC F6               [12]  957 	mov	@r0,a
      0002BD E5 81            [12]  958 	mov	a,sp
      0002BF 24 FC            [12]  959 	add	a,#0xfc
      0002C1 F5 81            [12]  960 	mov	sp,a
      0002C3 E5 10            [12]  961 	mov	a,_bp
      0002C5 24 F6            [12]  962 	add	a,#0xf6
      0002C7 F8               [12]  963 	mov	r0,a
      0002C8 E6               [12]  964 	mov	a,@r0
      0002C9 C0 E0            [24]  965 	push	acc
      0002CB 08               [12]  966 	inc	r0
      0002CC E6               [12]  967 	mov	a,@r0
      0002CD C0 E0            [24]  968 	push	acc
      0002CF 08               [12]  969 	inc	r0
      0002D0 E6               [12]  970 	mov	a,@r0
      0002D1 C0 E0            [24]  971 	push	acc
      0002D3 08               [12]  972 	inc	r0
      0002D4 E6               [12]  973 	mov	a,@r0
      0002D5 C0 E0            [24]  974 	push	acc
      0002D7 E5 10            [12]  975 	mov	a,_bp
      0002D9 24 FA            [12]  976 	add	a,#0xfa
      0002DB F8               [12]  977 	mov	r0,a
      0002DC 86 82            [24]  978 	mov	dpl, @r0
      0002DE 08               [12]  979 	inc	r0
      0002DF 86 83            [24]  980 	mov	dph, @r0
      0002E1 08               [12]  981 	inc	r0
      0002E2 86 F0            [24]  982 	mov	b, @r0
      0002E4 08               [12]  983 	inc	r0
      0002E5 E6               [12]  984 	mov	a, @r0
      0002E6 12 2A B5         [24]  985 	lcall	___fsmul
      0002E9 AA 82            [24]  986 	mov	r2, dpl
      0002EB AC 83            [24]  987 	mov	r4, dph
      0002ED AD F0            [24]  988 	mov	r5, b
      0002EF FE               [12]  989 	mov	r6, a
      0002F0 E5 81            [12]  990 	mov	a,sp
      0002F2 24 FC            [12]  991 	add	a,#0xfc
      0002F4 F5 81            [12]  992 	mov	sp,a
      0002F6 C0 02            [24]  993 	push	ar2
      0002F8 C0 04            [24]  994 	push	ar4
      0002FA C0 05            [24]  995 	push	ar5
      0002FC C0 06            [24]  996 	push	ar6
      0002FE A8 10            [24]  997 	mov	r0,_bp
      000300 08               [12]  998 	inc	r0
      000301 86 82            [24]  999 	mov	dpl, @r0
      000303 08               [12] 1000 	inc	r0
      000304 86 83            [24] 1001 	mov	dph, @r0
      000306 08               [12] 1002 	inc	r0
      000307 86 F0            [24] 1003 	mov	b, @r0
      000309 08               [12] 1004 	inc	r0
      00030A E6               [12] 1005 	mov	a, @r0
      00030B 12 2A AA         [24] 1006 	lcall	___fssub
      00030E AB 82            [24] 1007 	mov	r3, dpl
      000310 AC 83            [24] 1008 	mov	r4, dph
      000312 AD F0            [24] 1009 	mov	r5, b
      000314 FE               [12] 1010 	mov	r6, a
      000315 E5 81            [12] 1011 	mov	a,sp
      000317 24 FC            [12] 1012 	add	a,#0xfc
      000319 F5 81            [12] 1013 	mov	sp,a
      00031B 8B 82            [24] 1014 	mov	dpl, r3
      00031D 8C 83            [24] 1015 	mov	dph, r4
      00031F 8D F0            [24] 1016 	mov	b, r5
      000321 EE               [12] 1017 	mov	a, r6
      000322 02 03 FA         [24] 1018 	ljmp	00105$
      000325                       1019 00102$:
      000325 BF 02 78         [24] 1020 	cjne	r7,#0x02,00104$
      000328 E5 10            [12] 1021 	mov	a,_bp
      00032A 24 F6            [12] 1022 	add	a,#0xf6
      00032C F8               [12] 1023 	mov	r0,a
      00032D E6               [12] 1024 	mov	a,@r0
      00032E C0 E0            [24] 1025 	push	acc
      000330 08               [12] 1026 	inc	r0
      000331 E6               [12] 1027 	mov	a,@r0
      000332 C0 E0            [24] 1028 	push	acc
      000334 08               [12] 1029 	inc	r0
      000335 E6               [12] 1030 	mov	a,@r0
      000336 C0 E0            [24] 1031 	push	acc
      000338 08               [12] 1032 	inc	r0
      000339 E6               [12] 1033 	mov	a,@r0
      00033A C0 E0            [24] 1034 	push	acc
      00033C E5 10            [12] 1035 	mov	a,_bp
      00033E 24 FA            [12] 1036 	add	a,#0xfa
      000340 F8               [12] 1037 	mov	r0,a
      000341 86 82            [24] 1038 	mov	dpl, @r0
      000343 08               [12] 1039 	inc	r0
      000344 86 83            [24] 1040 	mov	dph, @r0
      000346 08               [12] 1041 	inc	r0
      000347 86 F0            [24] 1042 	mov	b, @r0
      000349 08               [12] 1043 	inc	r0
      00034A E6               [12] 1044 	mov	a, @r0
      00034B 12 2C 15         [24] 1045 	lcall	___fsadd
      00034E AC 82            [24] 1046 	mov	r4, dpl
      000350 AD 83            [24] 1047 	mov	r5, dph
      000352 AE F0            [24] 1048 	mov	r6, b
      000354 FF               [12] 1049 	mov	r7, a
      000355 E5 81            [12] 1050 	mov	a,sp
      000357 24 FC            [12] 1051 	add	a,#0xfc
      000359 F5 81            [12] 1052 	mov	sp,a
      00035B C0 07            [24] 1053 	push	ar7
      00035D C0 06            [24] 1054 	push	ar6
      00035F C0 05            [24] 1055 	push	ar5
      000361 C0 04            [24] 1056 	push	ar4
      000363 E4               [12] 1057 	clr	a
      000364 C0 E0            [24] 1058 	push	acc
      000366 C0 E0            [24] 1059 	push	acc
      000368 74 80            [12] 1060 	mov	a,#0x80
      00036A C0 E0            [24] 1061 	push	acc
      00036C 74 3F            [12] 1062 	mov	a,#0x3f
      00036E C0 E0            [24] 1063 	push	acc
      000370 8C 82            [24] 1064 	mov	dpl, r4
      000372 8D 83            [24] 1065 	mov	dph, r5
      000374 8E F0            [24] 1066 	mov	b, r6
      000376 EF               [12] 1067 	mov	a, r7
      000377 12 2B E5         [24] 1068 	lcall	___fslt
      00037A AB 82            [24] 1069 	mov	r3, dpl
      00037C E5 81            [12] 1070 	mov	a,sp
      00037E 24 FC            [12] 1071 	add	a,#0xfc
      000380 F5 81            [12] 1072 	mov	sp,a
      000382 D0 04            [24] 1073 	pop	ar4
      000384 D0 05            [24] 1074 	pop	ar5
      000386 D0 06            [24] 1075 	pop	ar6
      000388 D0 07            [24] 1076 	pop	ar7
      00038A EB               [12] 1077 	mov	a,r3
      00038B 60 02            [24] 1078 	jz	00107$
      00038D 80 08            [24] 1079 	sjmp	00108$
      00038F                       1080 00107$:
      00038F 7C 00            [12] 1081 	mov	r4,#0x00
      000391 7D 00            [12] 1082 	mov	r5,#0x00
      000393 7E 80            [12] 1083 	mov	r6,#0x80
      000395 7F 3F            [12] 1084 	mov	r7,#0x3f
      000397                       1085 00108$:
      000397 8C 82            [24] 1086 	mov	dpl, r4
      000399 8D 83            [24] 1087 	mov	dph, r5
      00039B 8E F0            [24] 1088 	mov	b, r6
      00039D EF               [12] 1089 	mov	a, r7
      00039E 80 5A            [24] 1090 	sjmp	00105$
      0003A0                       1091 00104$:
      0003A0 E5 10            [12] 1092 	mov	a,_bp
      0003A2 24 FA            [12] 1093 	add	a,#0xfa
      0003A4 F8               [12] 1094 	mov	r0,a
      0003A5 E6               [12] 1095 	mov	a,@r0
      0003A6 C0 E0            [24] 1096 	push	acc
      0003A8 08               [12] 1097 	inc	r0
      0003A9 E6               [12] 1098 	mov	a,@r0
      0003AA C0 E0            [24] 1099 	push	acc
      0003AC 08               [12] 1100 	inc	r0
      0003AD E6               [12] 1101 	mov	a,@r0
      0003AE C0 E0            [24] 1102 	push	acc
      0003B0 08               [12] 1103 	inc	r0
      0003B1 E6               [12] 1104 	mov	a,@r0
      0003B2 C0 E0            [24] 1105 	push	acc
      0003B4 E5 10            [12] 1106 	mov	a,_bp
      0003B6 24 F6            [12] 1107 	add	a,#0xf6
      0003B8 F8               [12] 1108 	mov	r0,a
      0003B9 86 82            [24] 1109 	mov	dpl, @r0
      0003BB 08               [12] 1110 	inc	r0
      0003BC 86 83            [24] 1111 	mov	dph, @r0
      0003BE 08               [12] 1112 	inc	r0
      0003BF 86 F0            [24] 1113 	mov	b, @r0
      0003C1 08               [12] 1114 	inc	r0
      0003C2 E6               [12] 1115 	mov	a, @r0
      0003C3 12 2B E5         [24] 1116 	lcall	___fslt
      0003C6 AF 82            [24] 1117 	mov	r7, dpl
      0003C8 E5 81            [12] 1118 	mov	a,sp
      0003CA 24 FC            [12] 1119 	add	a,#0xfc
      0003CC F5 81            [12] 1120 	mov	sp,a
      0003CE EF               [12] 1121 	mov	a,r7
      0003CF 60 12            [24] 1122 	jz	00109$
      0003D1 E5 10            [12] 1123 	mov	a,_bp
      0003D3 24 FA            [12] 1124 	add	a,#0xfa
      0003D5 F8               [12] 1125 	mov	r0,a
      0003D6 86 04            [24] 1126 	mov	ar4,@r0
      0003D8 08               [12] 1127 	inc	r0
      0003D9 86 05            [24] 1128 	mov	ar5,@r0
      0003DB 08               [12] 1129 	inc	r0
      0003DC 86 06            [24] 1130 	mov	ar6,@r0
      0003DE 08               [12] 1131 	inc	r0
      0003DF 86 07            [24] 1132 	mov	ar7,@r0
      0003E1 80 10            [24] 1133 	sjmp	00110$
      0003E3                       1134 00109$:
      0003E3 E5 10            [12] 1135 	mov	a,_bp
      0003E5 24 F6            [12] 1136 	add	a,#0xf6
      0003E7 F8               [12] 1137 	mov	r0,a
      0003E8 86 04            [24] 1138 	mov	ar4,@r0
      0003EA 08               [12] 1139 	inc	r0
      0003EB 86 05            [24] 1140 	mov	ar5,@r0
      0003ED 08               [12] 1141 	inc	r0
      0003EE 86 06            [24] 1142 	mov	ar6,@r0
      0003F0 08               [12] 1143 	inc	r0
      0003F1 86 07            [24] 1144 	mov	ar7,@r0
      0003F3                       1145 00110$:
      0003F3 8C 82            [24] 1146 	mov	dpl, r4
      0003F5 8D 83            [24] 1147 	mov	dph, r5
      0003F7 8E F0            [24] 1148 	mov	b, r6
      0003F9 EF               [12] 1149 	mov	a, r7
      0003FA                       1150 00105$:
      0003FA 85 10 81         [24] 1151 	mov	sp,_bp
      0003FD D0 10            [24] 1152 	pop	_bp
                           000342  1153 	C$fuzzy.h$57$1_0$16 ==.
                           000342  1154 	XFsugeno_demo$fuzzy_8051_or2$0$0 ==.
      0003FF 22               [24] 1155 	ret
                                   1156 ;------------------------------------------------------------
                                   1157 ;Allocation info for local variables in function 'fuzzy_8051_or3'
                                   1158 ;------------------------------------------------------------
                                   1159 ;a             Allocated to stack - _bp -6 +4 
                                   1160 ;b             Allocated to stack - _bp -10 +4 
                                   1161 ;c             Allocated to stack - _bp -14 +4 
                                   1162 ;method        Allocated to registers r7 
                                   1163 ;------------------------------------------------------------
                           000343  1164 	Fsugeno_demo$fuzzy_8051_or3$0$0 ==.
                           000343  1165 	C$fuzzy.h$58$1_0$19 ==.
                                   1166 ;	../../fuzzy.h:58: static float fuzzy_8051_or3(fuzzy_logic_method_t method, float a, float b, float c) { return fuzzy_8051_or2(method, fuzzy_8051_or2(method, a, b), c); }
                                   1167 ;	-----------------------------------------
                                   1168 ;	 function fuzzy_8051_or3
                                   1169 ;	-----------------------------------------
      000400                       1170 _fuzzy_8051_or3:
      000400 C0 10            [24] 1171 	push	_bp
      000402 85 81 10         [24] 1172 	mov	_bp,sp
      000405 AF 82            [24] 1173 	mov	r7, dpl
      000407 C0 07            [24] 1174 	push	ar7
      000409 E5 10            [12] 1175 	mov	a,_bp
      00040B 24 F6            [12] 1176 	add	a,#0xf6
      00040D F8               [12] 1177 	mov	r0,a
      00040E E6               [12] 1178 	mov	a,@r0
      00040F C0 E0            [24] 1179 	push	acc
      000411 08               [12] 1180 	inc	r0
      000412 E6               [12] 1181 	mov	a,@r0
      000413 C0 E0            [24] 1182 	push	acc
      000415 08               [12] 1183 	inc	r0
      000416 E6               [12] 1184 	mov	a,@r0
      000417 C0 E0            [24] 1185 	push	acc
      000419 08               [12] 1186 	inc	r0
      00041A E6               [12] 1187 	mov	a,@r0
      00041B C0 E0            [24] 1188 	push	acc
      00041D E5 10            [12] 1189 	mov	a,_bp
      00041F 24 FA            [12] 1190 	add	a,#0xfa
      000421 F8               [12] 1191 	mov	r0,a
      000422 E6               [12] 1192 	mov	a,@r0
      000423 C0 E0            [24] 1193 	push	acc
      000425 08               [12] 1194 	inc	r0
      000426 E6               [12] 1195 	mov	a,@r0
      000427 C0 E0            [24] 1196 	push	acc
      000429 08               [12] 1197 	inc	r0
      00042A E6               [12] 1198 	mov	a,@r0
      00042B C0 E0            [24] 1199 	push	acc
      00042D 08               [12] 1200 	inc	r0
      00042E E6               [12] 1201 	mov	a,@r0
      00042F C0 E0            [24] 1202 	push	acc
      000431 8F 82            [24] 1203 	mov	dpl, r7
      000433 12 02 76         [24] 1204 	lcall	_fuzzy_8051_or2
      000436 AB 82            [24] 1205 	mov	r3, dpl
      000438 AC 83            [24] 1206 	mov	r4, dph
      00043A AD F0            [24] 1207 	mov	r5, b
      00043C FE               [12] 1208 	mov	r6, a
      00043D E5 81            [12] 1209 	mov	a,sp
      00043F 24 F8            [12] 1210 	add	a,#0xf8
      000441 F5 81            [12] 1211 	mov	sp,a
      000443 D0 07            [24] 1212 	pop	ar7
      000445 E5 10            [12] 1213 	mov	a,_bp
      000447 24 F2            [12] 1214 	add	a,#0xf2
      000449 F8               [12] 1215 	mov	r0,a
      00044A E6               [12] 1216 	mov	a,@r0
      00044B C0 E0            [24] 1217 	push	acc
      00044D 08               [12] 1218 	inc	r0
      00044E E6               [12] 1219 	mov	a,@r0
      00044F C0 E0            [24] 1220 	push	acc
      000451 08               [12] 1221 	inc	r0
      000452 E6               [12] 1222 	mov	a,@r0
      000453 C0 E0            [24] 1223 	push	acc
      000455 08               [12] 1224 	inc	r0
      000456 E6               [12] 1225 	mov	a,@r0
      000457 C0 E0            [24] 1226 	push	acc
      000459 C0 03            [24] 1227 	push	ar3
      00045B C0 04            [24] 1228 	push	ar4
      00045D C0 05            [24] 1229 	push	ar5
      00045F C0 06            [24] 1230 	push	ar6
      000461 8F 82            [24] 1231 	mov	dpl, r7
      000463 12 02 76         [24] 1232 	lcall	_fuzzy_8051_or2
      000466 AC 82            [24] 1233 	mov	r4, dpl
      000468 AD 83            [24] 1234 	mov	r5, dph
      00046A AE F0            [24] 1235 	mov	r6, b
      00046C FF               [12] 1236 	mov	r7, a
      00046D E5 81            [12] 1237 	mov	a,sp
      00046F 24 F8            [12] 1238 	add	a,#0xf8
      000471 F5 81            [12] 1239 	mov	sp,a
      000473 8C 82            [24] 1240 	mov	dpl, r4
      000475 8D 83            [24] 1241 	mov	dph, r5
      000477 8E F0            [24] 1242 	mov	b, r6
      000479 EF               [12] 1243 	mov	a, r7
      00047A D0 10            [24] 1244 	pop	_bp
                           0003BF  1245 	C$fuzzy.h$58$1_0$19 ==.
                           0003BF  1246 	XFsugeno_demo$fuzzy_8051_or3$0$0 ==.
      00047C 22               [24] 1247 	ret
                                   1248 ;------------------------------------------------------------
                                   1249 ;Allocation info for local variables in function 'fuzzy_8051_clamp'
                                   1250 ;------------------------------------------------------------
                                   1251 ;value         Allocated to registers r4 r5 r6 r7 
                                   1252 ;------------------------------------------------------------
                           0003C0  1253 	Fsugeno_demo$fuzzy_8051_clamp$0$0 ==.
                           0003C0  1254 	C$fuzzy.h$66$1_0$21 ==.
                                   1255 ;	../../fuzzy.h:66: static float fuzzy_8051_clamp(float value) { if (value < 0.0f) return 0.0f; if (value > 1.0f) return 1.0f; return value; }
                                   1256 ;	-----------------------------------------
                                   1257 ;	 function fuzzy_8051_clamp
                                   1258 ;	-----------------------------------------
      00047D                       1259 _fuzzy_8051_clamp:
      00047D AC 82            [24] 1260 	mov	r4,dpl
      00047F AD 83            [24] 1261 	mov	r5,dph
      000481 AE F0            [24] 1262 	mov	r6,b
      000483 FF               [12] 1263 	mov	r7,a
      000484 C0 07            [24] 1264 	push	ar7
      000486 C0 06            [24] 1265 	push	ar6
      000488 C0 05            [24] 1266 	push	ar5
      00048A C0 04            [24] 1267 	push	ar4
      00048C E4               [12] 1268 	clr	a
      00048D C0 E0            [24] 1269 	push	acc
      00048F C0 E0            [24] 1270 	push	acc
      000491 C0 E0            [24] 1271 	push	acc
      000493 C0 E0            [24] 1272 	push	acc
      000495 8C 82            [24] 1273 	mov	dpl, r4
      000497 8D 83            [24] 1274 	mov	dph, r5
      000499 8E F0            [24] 1275 	mov	b, r6
      00049B EF               [12] 1276 	mov	a, r7
      00049C 12 2B E5         [24] 1277 	lcall	___fslt
      00049F AB 82            [24] 1278 	mov	r3, dpl
      0004A1 E5 81            [12] 1279 	mov	a,sp
      0004A3 24 FC            [12] 1280 	add	a,#0xfc
      0004A5 F5 81            [12] 1281 	mov	sp,a
      0004A7 D0 04            [24] 1282 	pop	ar4
      0004A9 D0 05            [24] 1283 	pop	ar5
      0004AB D0 06            [24] 1284 	pop	ar6
      0004AD D0 07            [24] 1285 	pop	ar7
      0004AF EB               [12] 1286 	mov	a,r3
      0004B0 60 08            [24] 1287 	jz	00102$
      0004B2 90 00 00         [24] 1288 	mov	dptr,#0x0000
      0004B5 E4               [12] 1289 	clr	a
      0004B6 F5 F0            [12] 1290 	mov	b,a
      0004B8 80 3F            [24] 1291 	sjmp	00105$
      0004BA                       1292 00102$:
      0004BA C0 07            [24] 1293 	push	ar7
      0004BC C0 06            [24] 1294 	push	ar6
      0004BE C0 05            [24] 1295 	push	ar5
      0004C0 C0 04            [24] 1296 	push	ar4
      0004C2 C0 04            [24] 1297 	push	ar4
      0004C4 C0 05            [24] 1298 	push	ar5
      0004C6 C0 06            [24] 1299 	push	ar6
      0004C8 C0 07            [24] 1300 	push	ar7
      0004CA 90 00 00         [24] 1301 	mov	dptr,#0x0000
      0004CD 75 F0 80         [24] 1302 	mov	b, #0x80
      0004D0 74 3F            [12] 1303 	mov	a, #0x3f
      0004D2 12 2B E5         [24] 1304 	lcall	___fslt
      0004D5 AB 82            [24] 1305 	mov	r3, dpl
      0004D7 E5 81            [12] 1306 	mov	a,sp
      0004D9 24 FC            [12] 1307 	add	a,#0xfc
      0004DB F5 81            [12] 1308 	mov	sp,a
      0004DD D0 04            [24] 1309 	pop	ar4
      0004DF D0 05            [24] 1310 	pop	ar5
      0004E1 D0 06            [24] 1311 	pop	ar6
      0004E3 D0 07            [24] 1312 	pop	ar7
      0004E5 EB               [12] 1313 	mov	a,r3
      0004E6 60 0A            [24] 1314 	jz	00104$
      0004E8 90 00 00         [24] 1315 	mov	dptr,#0x0000
      0004EB 75 F0 80         [24] 1316 	mov	b, #0x80
      0004EE 74 3F            [12] 1317 	mov	a, #0x3f
      0004F0 80 07            [24] 1318 	sjmp	00105$
      0004F2                       1319 00104$:
      0004F2 8C 82            [24] 1320 	mov	dpl, r4
      0004F4 8D 83            [24] 1321 	mov	dph, r5
      0004F6 8E F0            [24] 1322 	mov	b, r6
      0004F8 EF               [12] 1323 	mov	a, r7
      0004F9                       1324 00105$:
                           00043C  1325 	C$fuzzy.h$66$1_0$21 ==.
                           00043C  1326 	XFsugeno_demo$fuzzy_8051_clamp$0$0 ==.
      0004F9 22               [24] 1327 	ret
                                   1328 ;------------------------------------------------------------
                                   1329 ;Allocation info for local variables in function 'fuzzy_8051_hedge'
                                   1330 ;------------------------------------------------------------
                                   1331 ;hedge         Allocated to stack - _bp -3 +1 
                                   1332 ;value         Allocated to stack - _bp +1 +4 
                                   1333 ;result        Allocated to registers r2 r3 r6 r7 
                                   1334 ;------------------------------------------------------------
                           00043D  1335 	Fsugeno_demo$fuzzy_8051_hedge$0$0 ==.
                           00043D  1336 	C$fuzzy.h$67$1_0$23 ==.
                                   1337 ;	../../fuzzy.h:67: static float fuzzy_8051_hedge(float value, fuzzy_hedge_t hedge) { float result; value = fuzzy_8051_clamp(value); if (hedge == 0u) hedge = 1u; result = 1.0f; while (hedge != 0u) { result *= value; --hedge; } return fuzzy_8051_clamp(result); }
                                   1338 ;	-----------------------------------------
                                   1339 ;	 function fuzzy_8051_hedge
                                   1340 ;	-----------------------------------------
      0004FA                       1341 _fuzzy_8051_hedge:
      0004FA C0 10            [24] 1342 	push	_bp
      0004FC 85 81 10         [24] 1343 	mov	_bp,sp
      0004FF AC 82            [24] 1344 	mov	r4,dpl
      000501 AD 83            [24] 1345 	mov	r5,dph
      000503 AE F0            [24] 1346 	mov	r6,b
      000505 FF               [12] 1347 	mov	r7,a
      000506 E5 81            [12] 1348 	mov	a,sp
      000508 24 04            [12] 1349 	add	a,#0x04
      00050A F5 81            [12] 1350 	mov	sp,a
      00050C 8C 82            [24] 1351 	mov	dpl, r4
      00050E 8D 83            [24] 1352 	mov	dph, r5
      000510 8E F0            [24] 1353 	mov	b, r6
      000512 EF               [12] 1354 	mov	a, r7
      000513 12 04 7D         [24] 1355 	lcall	_fuzzy_8051_clamp
      000516 A8 10            [24] 1356 	mov	r0,_bp
      000518 08               [12] 1357 	inc	r0
      000519 A6 82            [24] 1358 	mov	@r0, dpl
      00051B 08               [12] 1359 	inc	r0
      00051C A6 83            [24] 1360 	mov	@r0, dph
      00051E 08               [12] 1361 	inc	r0
      00051F A6 F0            [24] 1362 	mov	@r0, b
      000521 08               [12] 1363 	inc	r0
      000522 F6               [12] 1364 	mov	@r0,a
      000523 E5 10            [12] 1365 	mov	a,_bp
      000525 24 FD            [12] 1366 	add	a,#0xfd
      000527 F8               [12] 1367 	mov	r0,a
      000528 E6               [12] 1368 	mov	a,@r0
      000529 70 07            [24] 1369 	jnz	00102$
      00052B E5 10            [12] 1370 	mov	a,_bp
      00052D 24 FD            [12] 1371 	add	a,#0xfd
      00052F F8               [12] 1372 	mov	r0,a
      000530 76 01            [12] 1373 	mov	@r0,#0x01
      000532                       1374 00102$:
      000532 7A 00            [12] 1375 	mov	r2,#0x00
      000534 7B 00            [12] 1376 	mov	r3,#0x00
      000536 7E 80            [12] 1377 	mov	r6,#0x80
      000538 7F 3F            [12] 1378 	mov	r7,#0x3f
      00053A E5 10            [12] 1379 	mov	a,_bp
      00053C 24 FD            [12] 1380 	add	a,#0xfd
      00053E F8               [12] 1381 	mov	r0,a
      00053F 86 05            [24] 1382 	mov	ar5,@r0
      000541                       1383 00103$:
      000541 ED               [12] 1384 	mov	a,r5
      000542 60 30            [24] 1385 	jz	00105$
      000544 C0 05            [24] 1386 	push	ar5
      000546 A8 10            [24] 1387 	mov	r0,_bp
      000548 08               [12] 1388 	inc	r0
      000549 E6               [12] 1389 	mov	a,@r0
      00054A C0 E0            [24] 1390 	push	acc
      00054C 08               [12] 1391 	inc	r0
      00054D E6               [12] 1392 	mov	a,@r0
      00054E C0 E0            [24] 1393 	push	acc
      000550 08               [12] 1394 	inc	r0
      000551 E6               [12] 1395 	mov	a,@r0
      000552 C0 E0            [24] 1396 	push	acc
      000554 08               [12] 1397 	inc	r0
      000555 E6               [12] 1398 	mov	a,@r0
      000556 C0 E0            [24] 1399 	push	acc
      000558 8A 82            [24] 1400 	mov	dpl, r2
      00055A 8B 83            [24] 1401 	mov	dph, r3
      00055C 8E F0            [24] 1402 	mov	b, r6
      00055E EF               [12] 1403 	mov	a, r7
      00055F 12 2A B5         [24] 1404 	lcall	___fsmul
      000562 AA 82            [24] 1405 	mov	r2, dpl
      000564 AB 83            [24] 1406 	mov	r3, dph
      000566 AE F0            [24] 1407 	mov	r6, b
      000568 FF               [12] 1408 	mov	r7, a
      000569 E5 81            [12] 1409 	mov	a,sp
      00056B 24 FC            [12] 1410 	add	a,#0xfc
      00056D F5 81            [12] 1411 	mov	sp,a
      00056F D0 05            [24] 1412 	pop	ar5
      000571 1D               [12] 1413 	dec	r5
      000572 80 CD            [24] 1414 	sjmp	00103$
      000574                       1415 00105$:
      000574 8A 82            [24] 1416 	mov	dpl, r2
      000576 8B 83            [24] 1417 	mov	dph, r3
      000578 8E F0            [24] 1418 	mov	b, r6
      00057A EF               [12] 1419 	mov	a, r7
      00057B 12 04 7D         [24] 1420 	lcall	_fuzzy_8051_clamp
      00057E 85 10 81         [24] 1421 	mov	sp,_bp
      000581 D0 10            [24] 1422 	pop	_bp
                           0004C6  1423 	C$fuzzy.h$67$1_0$23 ==.
                           0004C6  1424 	XFsugeno_demo$fuzzy_8051_hedge$0$0 ==.
      000583 22               [24] 1425 	ret
                                   1426 ;------------------------------------------------------------
                                   1427 ;Allocation info for local variables in function 'fuzzy_not'
                                   1428 ;------------------------------------------------------------
                                   1429 ;membership    Allocated to registers r4 r5 r6 r7 
                                   1430 ;------------------------------------------------------------
                           0004C7  1431 	G$fuzzy_not$0$0 ==.
                           0004C7  1432 	C$fuzzy.h$68$1_0$26 ==.
                                   1433 ;	../../fuzzy.h:68: float fuzzy_not(float membership) { return 1.0f - fuzzy_8051_clamp(membership); }
                                   1434 ;	-----------------------------------------
                                   1435 ;	 function fuzzy_not
                                   1436 ;	-----------------------------------------
      000584                       1437 _fuzzy_not:
      000584 12 04 7D         [24] 1438 	lcall	_fuzzy_8051_clamp
      000587 AC 82            [24] 1439 	mov	r4, dpl
      000589 AD 83            [24] 1440 	mov	r5, dph
      00058B AE F0            [24] 1441 	mov	r6, b
      00058D FF               [12] 1442 	mov	r7, a
      00058E C0 04            [24] 1443 	push	ar4
      000590 C0 05            [24] 1444 	push	ar5
      000592 C0 06            [24] 1445 	push	ar6
      000594 C0 07            [24] 1446 	push	ar7
      000596 90 00 00         [24] 1447 	mov	dptr,#0x0000
      000599 75 F0 80         [24] 1448 	mov	b, #0x80
      00059C 74 3F            [12] 1449 	mov	a, #0x3f
      00059E 12 2A AA         [24] 1450 	lcall	___fssub
      0005A1 AC 82            [24] 1451 	mov	r4, dpl
      0005A3 AD 83            [24] 1452 	mov	r5, dph
      0005A5 AE F0            [24] 1453 	mov	r6, b
      0005A7 FF               [12] 1454 	mov	r7, a
      0005A8 E5 81            [12] 1455 	mov	a,sp
      0005AA 24 FC            [12] 1456 	add	a,#0xfc
      0005AC F5 81            [12] 1457 	mov	sp,a
      0005AE 8C 82            [24] 1458 	mov	dpl, r4
      0005B0 8D 83            [24] 1459 	mov	dph, r5
      0005B2 8E F0            [24] 1460 	mov	b, r6
      0005B4 EF               [12] 1461 	mov	a, r7
                           0004F8  1462 	C$fuzzy.h$68$1_0$26 ==.
                           0004F8  1463 	XG$fuzzy_not$0$0 ==.
      0005B5 22               [24] 1464 	ret
                                   1465 ;------------------------------------------------------------
                                   1466 ;Allocation info for local variables in function 'fuzzy_ramp'
                                   1467 ;------------------------------------------------------------
                                   1468 ;b             Allocated to stack - _bp -6 +4 
                                   1469 ;x             Allocated to stack - _bp -10 +4 
                                   1470 ;up            Allocated to stack - _bp -11 +1 
                                   1471 ;hedge         Allocated to stack - _bp -12 +1 
                                   1472 ;a             Allocated to registers r7 r6 r5 r4 
                                   1473 ;result        Allocated to stack - _bp +5 +4 
                                   1474 ;sloc0         Allocated to stack - _bp +1 +4 
                                   1475 ;------------------------------------------------------------
                           0004F9  1476 	G$fuzzy_ramp$0$0 ==.
                           0004F9  1477 	C$fuzzy.h$69$1_0$28 ==.
                                   1478 ;	../../fuzzy.h:69: float fuzzy_ramp(float a, float b, float x, bool up, fuzzy_hedge_t hedge) { float result; if (a >= b) return 0.0f; if (x <= a) result = up ? 0.0f : 1.0f; else if (x >= b) result = up ? 1.0f : 0.0f; else { result = (x - a) / (b - a); if (!up) result = 1.0f - result; } return fuzzy_8051_hedge(result, hedge); }
                                   1479 ;	-----------------------------------------
                                   1480 ;	 function fuzzy_ramp
                                   1481 ;	-----------------------------------------
      0005B6                       1482 _fuzzy_ramp:
      0005B6 C0 10            [24] 1483 	push	_bp
      0005B8 85 81 10         [24] 1484 	mov	_bp,sp
      0005BB AF 82            [24] 1485 	mov	r7,dpl
      0005BD AE 83            [24] 1486 	mov	r6,dph
      0005BF AD F0            [24] 1487 	mov	r5,b
      0005C1 FC               [12] 1488 	mov	r4,a
      0005C2 E5 81            [12] 1489 	mov	a,sp
      0005C4 24 08            [12] 1490 	add	a,#0x08
      0005C6 F5 81            [12] 1491 	mov	sp,a
      0005C8 C0 07            [24] 1492 	push	ar7
      0005CA C0 06            [24] 1493 	push	ar6
      0005CC C0 05            [24] 1494 	push	ar5
      0005CE C0 04            [24] 1495 	push	ar4
      0005D0 E5 10            [12] 1496 	mov	a,_bp
      0005D2 24 FA            [12] 1497 	add	a,#0xfa
      0005D4 F8               [12] 1498 	mov	r0,a
      0005D5 E6               [12] 1499 	mov	a,@r0
      0005D6 C0 E0            [24] 1500 	push	acc
      0005D8 08               [12] 1501 	inc	r0
      0005D9 E6               [12] 1502 	mov	a,@r0
      0005DA C0 E0            [24] 1503 	push	acc
      0005DC 08               [12] 1504 	inc	r0
      0005DD E6               [12] 1505 	mov	a,@r0
      0005DE C0 E0            [24] 1506 	push	acc
      0005E0 08               [12] 1507 	inc	r0
      0005E1 E6               [12] 1508 	mov	a,@r0
      0005E2 C0 E0            [24] 1509 	push	acc
      0005E4 8F 82            [24] 1510 	mov	dpl, r7
      0005E6 8E 83            [24] 1511 	mov	dph, r6
      0005E8 8D F0            [24] 1512 	mov	b, r5
      0005EA EC               [12] 1513 	mov	a, r4
      0005EB 12 2B E5         [24] 1514 	lcall	___fslt
      0005EE E5 81            [12] 1515 	mov	a,sp
      0005F0 24 FC            [12] 1516 	add	a,#0xfc
      0005F2 F5 81            [12] 1517 	mov	sp,a
      0005F4 D0 04            [24] 1518 	pop	ar4
      0005F6 D0 05            [24] 1519 	pop	ar5
      0005F8 D0 06            [24] 1520 	pop	ar6
      0005FA D0 07            [24] 1521 	pop	ar7
      0005FC E5 82            [12] 1522 	mov	a, dpl
      0005FE 24 FF            [12] 1523 	add	a,#0xff
      000600 92 00            [24] 1524 	mov	b0,c
      000602 40 09            [24] 1525 	jc	00102$
      000604 90 00 00         [24] 1526 	mov	dptr,#0x0000
      000607 E4               [12] 1527 	clr	a
      000608 F5 F0            [12] 1528 	mov	b,a
      00060A 02 07 BC         [24] 1529 	ljmp	00111$
      00060D                       1530 00102$:
      00060D C0 07            [24] 1531 	push	ar7
      00060F C0 06            [24] 1532 	push	ar6
      000611 C0 05            [24] 1533 	push	ar5
      000613 C0 04            [24] 1534 	push	ar4
      000615 E5 10            [12] 1535 	mov	a,_bp
      000617 24 F6            [12] 1536 	add	a,#0xf6
      000619 F8               [12] 1537 	mov	r0,a
      00061A E6               [12] 1538 	mov	a,@r0
      00061B C0 E0            [24] 1539 	push	acc
      00061D 08               [12] 1540 	inc	r0
      00061E E6               [12] 1541 	mov	a,@r0
      00061F C0 E0            [24] 1542 	push	acc
      000621 08               [12] 1543 	inc	r0
      000622 E6               [12] 1544 	mov	a,@r0
      000623 C0 E0            [24] 1545 	push	acc
      000625 08               [12] 1546 	inc	r0
      000626 E6               [12] 1547 	mov	a,@r0
      000627 C0 E0            [24] 1548 	push	acc
      000629 8F 82            [24] 1549 	mov	dpl, r7
      00062B 8E 83            [24] 1550 	mov	dph, r6
      00062D 8D F0            [24] 1551 	mov	b, r5
      00062F EC               [12] 1552 	mov	a, r4
      000630 12 2B E5         [24] 1553 	lcall	___fslt
      000633 E5 81            [12] 1554 	mov	a,sp
      000635 24 FC            [12] 1555 	add	a,#0xfc
      000637 F5 81            [12] 1556 	mov	sp,a
      000639 D0 04            [24] 1557 	pop	ar4
      00063B D0 05            [24] 1558 	pop	ar5
      00063D D0 06            [24] 1559 	pop	ar6
      00063F D0 07            [24] 1560 	pop	ar7
      000641 E5 82            [12] 1561 	mov	a, dpl
      000643 24 FF            [12] 1562 	add	a,#0xff
      000645 92 00            [24] 1563 	mov	b0,c
      000647 40 39            [24] 1564 	jc	00109$
      000649 E5 10            [12] 1565 	mov	a,_bp
      00064B 24 F5            [12] 1566 	add	a,#0xf5
      00064D F8               [12] 1567 	mov	r0,a
      00064E E6               [12] 1568 	mov	a,@r0
      00064F 60 0F            [24] 1569 	jz	00113$
      000651 E5 10            [12] 1570 	mov	a,_bp
      000653 24 05            [12] 1571 	add	a,#0x05
      000655 F8               [12] 1572 	mov	r0,a
      000656 E4               [12] 1573 	clr	a
      000657 F6               [12] 1574 	mov	@r0,a
      000658 08               [12] 1575 	inc	r0
      000659 F6               [12] 1576 	mov	@r0,a
      00065A 08               [12] 1577 	inc	r0
      00065B F6               [12] 1578 	mov	@r0,a
      00065C 08               [12] 1579 	inc	r0
      00065D F6               [12] 1580 	mov	@r0,a
      00065E 80 0F            [24] 1581 	sjmp	00114$
      000660                       1582 00113$:
      000660 E5 10            [12] 1583 	mov	a,_bp
      000662 24 05            [12] 1584 	add	a,#0x05
      000664 F8               [12] 1585 	mov	r0,a
      000665 E4               [12] 1586 	clr	a
      000666 F6               [12] 1587 	mov	@r0,a
      000667 08               [12] 1588 	inc	r0
      000668 F6               [12] 1589 	mov	@r0,a
      000669 08               [12] 1590 	inc	r0
      00066A 76 80            [12] 1591 	mov	@r0,#0x80
      00066C 08               [12] 1592 	inc	r0
      00066D 76 3F            [12] 1593 	mov	@r0,#0x3f
      00066F                       1594 00114$:
      00066F E5 10            [12] 1595 	mov	a,_bp
      000671 24 05            [12] 1596 	add	a,#0x05
      000673 F8               [12] 1597 	mov	r0,a
      000674 86 07            [24] 1598 	mov	ar7,@r0
      000676 08               [12] 1599 	inc	r0
      000677 86 06            [24] 1600 	mov	ar6,@r0
      000679 08               [12] 1601 	inc	r0
      00067A 86 05            [24] 1602 	mov	ar5,@r0
      00067C 08               [12] 1603 	inc	r0
      00067D 86 04            [24] 1604 	mov	ar4,@r0
      00067F 02 07 9A         [24] 1605 	ljmp	00110$
      000682                       1606 00109$:
      000682 C0 07            [24] 1607 	push	ar7
      000684 C0 06            [24] 1608 	push	ar6
      000686 C0 05            [24] 1609 	push	ar5
      000688 C0 04            [24] 1610 	push	ar4
      00068A E5 10            [12] 1611 	mov	a,_bp
      00068C 24 FA            [12] 1612 	add	a,#0xfa
      00068E F8               [12] 1613 	mov	r0,a
      00068F E6               [12] 1614 	mov	a,@r0
      000690 C0 E0            [24] 1615 	push	acc
      000692 08               [12] 1616 	inc	r0
      000693 E6               [12] 1617 	mov	a,@r0
      000694 C0 E0            [24] 1618 	push	acc
      000696 08               [12] 1619 	inc	r0
      000697 E6               [12] 1620 	mov	a,@r0
      000698 C0 E0            [24] 1621 	push	acc
      00069A 08               [12] 1622 	inc	r0
      00069B E6               [12] 1623 	mov	a,@r0
      00069C C0 E0            [24] 1624 	push	acc
      00069E E5 10            [12] 1625 	mov	a,_bp
      0006A0 24 F6            [12] 1626 	add	a,#0xf6
      0006A2 F8               [12] 1627 	mov	r0,a
      0006A3 86 82            [24] 1628 	mov	dpl, @r0
      0006A5 08               [12] 1629 	inc	r0
      0006A6 86 83            [24] 1630 	mov	dph, @r0
      0006A8 08               [12] 1631 	inc	r0
      0006A9 86 F0            [24] 1632 	mov	b, @r0
      0006AB 08               [12] 1633 	inc	r0
      0006AC E6               [12] 1634 	mov	a, @r0
      0006AD 12 2B E5         [24] 1635 	lcall	___fslt
      0006B0 E5 81            [12] 1636 	mov	a,sp
      0006B2 24 FC            [12] 1637 	add	a,#0xfc
      0006B4 F5 81            [12] 1638 	mov	sp,a
      0006B6 D0 04            [24] 1639 	pop	ar4
      0006B8 D0 05            [24] 1640 	pop	ar5
      0006BA D0 06            [24] 1641 	pop	ar6
      0006BC D0 07            [24] 1642 	pop	ar7
      0006BE E5 82            [12] 1643 	mov	a, dpl
      0006C0 24 FF            [12] 1644 	add	a,#0xff
      0006C2 92 00            [24] 1645 	mov	b0,c
      0006C4 40 33            [24] 1646 	jc	00106$
      0006C6 E5 10            [12] 1647 	mov	a,_bp
      0006C8 24 F5            [12] 1648 	add	a,#0xf5
      0006CA F8               [12] 1649 	mov	r0,a
      0006CB E6               [12] 1650 	mov	a,@r0
      0006CC 60 0F            [24] 1651 	jz	00115$
      0006CE A8 10            [24] 1652 	mov	r0,_bp
      0006D0 08               [12] 1653 	inc	r0
      0006D1 E4               [12] 1654 	clr	a
      0006D2 F6               [12] 1655 	mov	@r0,a
      0006D3 08               [12] 1656 	inc	r0
      0006D4 F6               [12] 1657 	mov	@r0,a
      0006D5 08               [12] 1658 	inc	r0
      0006D6 76 80            [12] 1659 	mov	@r0,#0x80
      0006D8 08               [12] 1660 	inc	r0
      0006D9 76 3F            [12] 1661 	mov	@r0,#0x3f
      0006DB 80 0B            [24] 1662 	sjmp	00116$
      0006DD                       1663 00115$:
      0006DD A8 10            [24] 1664 	mov	r0,_bp
      0006DF 08               [12] 1665 	inc	r0
      0006E0 E4               [12] 1666 	clr	a
      0006E1 F6               [12] 1667 	mov	@r0,a
      0006E2 08               [12] 1668 	inc	r0
      0006E3 F6               [12] 1669 	mov	@r0,a
      0006E4 08               [12] 1670 	inc	r0
      0006E5 F6               [12] 1671 	mov	@r0,a
      0006E6 08               [12] 1672 	inc	r0
      0006E7 F6               [12] 1673 	mov	@r0,a
      0006E8                       1674 00116$:
      0006E8 A8 10            [24] 1675 	mov	r0,_bp
      0006EA 08               [12] 1676 	inc	r0
      0006EB 86 07            [24] 1677 	mov	ar7,@r0
      0006ED 08               [12] 1678 	inc	r0
      0006EE 86 06            [24] 1679 	mov	ar6,@r0
      0006F0 08               [12] 1680 	inc	r0
      0006F1 86 05            [24] 1681 	mov	ar5,@r0
      0006F3 08               [12] 1682 	inc	r0
      0006F4 86 04            [24] 1683 	mov	ar4,@r0
      0006F6 02 07 9A         [24] 1684 	ljmp	00110$
      0006F9                       1685 00106$:
      0006F9 C0 07            [24] 1686 	push	ar7
      0006FB C0 06            [24] 1687 	push	ar6
      0006FD C0 05            [24] 1688 	push	ar5
      0006FF C0 04            [24] 1689 	push	ar4
      000701 C0 07            [24] 1690 	push	ar7
      000703 C0 06            [24] 1691 	push	ar6
      000705 C0 05            [24] 1692 	push	ar5
      000707 C0 04            [24] 1693 	push	ar4
      000709 E5 10            [12] 1694 	mov	a,_bp
      00070B 24 F6            [12] 1695 	add	a,#0xf6
      00070D F8               [12] 1696 	mov	r0,a
      00070E 86 82            [24] 1697 	mov	dpl, @r0
      000710 08               [12] 1698 	inc	r0
      000711 86 83            [24] 1699 	mov	dph, @r0
      000713 08               [12] 1700 	inc	r0
      000714 86 F0            [24] 1701 	mov	b, @r0
      000716 08               [12] 1702 	inc	r0
      000717 E6               [12] 1703 	mov	a, @r0
      000718 12 2A AA         [24] 1704 	lcall	___fssub
      00071B A8 10            [24] 1705 	mov	r0,_bp
      00071D 08               [12] 1706 	inc	r0
      00071E A6 82            [24] 1707 	mov	@r0, dpl
      000720 08               [12] 1708 	inc	r0
      000721 A6 83            [24] 1709 	mov	@r0, dph
      000723 08               [12] 1710 	inc	r0
      000724 A6 F0            [24] 1711 	mov	@r0, b
      000726 08               [12] 1712 	inc	r0
      000727 F6               [12] 1713 	mov	@r0,a
      000728 E5 81            [12] 1714 	mov	a,sp
      00072A 24 FC            [12] 1715 	add	a,#0xfc
      00072C F5 81            [12] 1716 	mov	sp,a
      00072E E5 10            [12] 1717 	mov	a,_bp
      000730 24 FA            [12] 1718 	add	a,#0xfa
      000732 F8               [12] 1719 	mov	r0,a
      000733 86 82            [24] 1720 	mov	dpl, @r0
      000735 08               [12] 1721 	inc	r0
      000736 86 83            [24] 1722 	mov	dph, @r0
      000738 08               [12] 1723 	inc	r0
      000739 86 F0            [24] 1724 	mov	b, @r0
      00073B 08               [12] 1725 	inc	r0
      00073C E6               [12] 1726 	mov	a, @r0
      00073D 12 2A AA         [24] 1727 	lcall	___fssub
      000740 AC 82            [24] 1728 	mov	r4, dpl
      000742 AD 83            [24] 1729 	mov	r5, dph
      000744 AE F0            [24] 1730 	mov	r6, b
      000746 FF               [12] 1731 	mov	r7, a
      000747 E5 81            [12] 1732 	mov	a,sp
      000749 24 FC            [12] 1733 	add	a,#0xfc
      00074B F5 81            [12] 1734 	mov	sp,a
      00074D C0 04            [24] 1735 	push	ar4
      00074F C0 05            [24] 1736 	push	ar5
      000751 C0 06            [24] 1737 	push	ar6
      000753 C0 07            [24] 1738 	push	ar7
      000755 A8 10            [24] 1739 	mov	r0,_bp
      000757 08               [12] 1740 	inc	r0
      000758 86 82            [24] 1741 	mov	dpl, @r0
      00075A 08               [12] 1742 	inc	r0
      00075B 86 83            [24] 1743 	mov	dph, @r0
      00075D 08               [12] 1744 	inc	r0
      00075E 86 F0            [24] 1745 	mov	b, @r0
      000760 08               [12] 1746 	inc	r0
      000761 E6               [12] 1747 	mov	a, @r0
      000762 12 2D 2C         [24] 1748 	lcall	___fsdiv
      000765 AF 82            [24] 1749 	mov	r7, dpl
      000767 AE 83            [24] 1750 	mov	r6, dph
      000769 AD F0            [24] 1751 	mov	r5, b
      00076B FC               [12] 1752 	mov	r4, a
      00076C E5 81            [12] 1753 	mov	a,sp
      00076E 24 FC            [12] 1754 	add	a,#0xfc
      000770 F5 81            [12] 1755 	mov	sp,a
      000772 E5 10            [12] 1756 	mov	a,_bp
      000774 24 F5            [12] 1757 	add	a,#0xf5
      000776 F8               [12] 1758 	mov	r0,a
      000777 E6               [12] 1759 	mov	a,@r0
      000778 70 20            [24] 1760 	jnz	00110$
      00077A C0 07            [24] 1761 	push	ar7
      00077C C0 06            [24] 1762 	push	ar6
      00077E C0 05            [24] 1763 	push	ar5
      000780 C0 04            [24] 1764 	push	ar4
      000782 90 00 00         [24] 1765 	mov	dptr,#0x0000
      000785 75 F0 80         [24] 1766 	mov	b, #0x80
      000788 74 3F            [12] 1767 	mov	a, #0x3f
      00078A 12 2A AA         [24] 1768 	lcall	___fssub
      00078D AF 82            [24] 1769 	mov	r7, dpl
      00078F AE 83            [24] 1770 	mov	r6, dph
      000791 AD F0            [24] 1771 	mov	r5, b
      000793 FC               [12] 1772 	mov	r4, a
      000794 E5 81            [12] 1773 	mov	a,sp
      000796 24 FC            [12] 1774 	add	a,#0xfc
      000798 F5 81            [12] 1775 	mov	sp,a
      00079A                       1776 00110$:
      00079A E5 10            [12] 1777 	mov	a,_bp
      00079C 24 F4            [12] 1778 	add	a,#0xf4
      00079E F8               [12] 1779 	mov	r0,a
      00079F E6               [12] 1780 	mov	a,@r0
      0007A0 C0 E0            [24] 1781 	push	acc
      0007A2 8F 82            [24] 1782 	mov	dpl, r7
      0007A4 8E 83            [24] 1783 	mov	dph, r6
      0007A6 8D F0            [24] 1784 	mov	b, r5
      0007A8 EC               [12] 1785 	mov	a, r4
      0007A9 12 04 FA         [24] 1786 	lcall	_fuzzy_8051_hedge
      0007AC AC 82            [24] 1787 	mov	r4, dpl
      0007AE AD 83            [24] 1788 	mov	r5, dph
      0007B0 AE F0            [24] 1789 	mov	r6, b
      0007B2 FF               [12] 1790 	mov	r7, a
      0007B3 15 81            [12] 1791 	dec	sp
      0007B5 8C 82            [24] 1792 	mov	dpl, r4
      0007B7 8D 83            [24] 1793 	mov	dph, r5
      0007B9 8E F0            [24] 1794 	mov	b, r6
      0007BB EF               [12] 1795 	mov	a, r7
      0007BC                       1796 00111$:
      0007BC 85 10 81         [24] 1797 	mov	sp,_bp
      0007BF D0 10            [24] 1798 	pop	_bp
                           000704  1799 	C$fuzzy.h$69$1_0$28 ==.
                           000704  1800 	XG$fuzzy_ramp$0$0 ==.
      0007C1 22               [24] 1801 	ret
                                   1802 ;------------------------------------------------------------
                                   1803 ;Allocation info for local variables in function 'fuzzy_triangle'
                                   1804 ;------------------------------------------------------------
                                   1805 ;b             Allocated to stack - _bp -6 +4 
                                   1806 ;c             Allocated to stack - _bp -10 +4 
                                   1807 ;x             Allocated to stack - _bp -14 +4 
                                   1808 ;hedge         Allocated to stack - _bp -15 +1 
                                   1809 ;a             Allocated to registers r7 r6 r5 r4 
                                   1810 ;result        Allocated to stack - _bp +1 +4 
                                   1811 ;sloc0         Allocated to stack - _bp +1 +4 
                                   1812 ;sloc1         Allocated to stack - _bp +5 +4 
                                   1813 ;------------------------------------------------------------
                           000705  1814 	G$fuzzy_triangle$0$0 ==.
                           000705  1815 	C$fuzzy.h$70$1_0$31 ==.
                                   1816 ;	../../fuzzy.h:70: float fuzzy_triangle(float a, float b, float c, float x, fuzzy_hedge_t hedge) { float result; if (a >= b || b >= c || x <= a || x >= c) result = 0.0f; else if (x == b) result = 1.0f; else if (x < b) result = (x - a) / (b - a); else result = (c - x) / (c - b); return fuzzy_8051_hedge(result, hedge); }
                                   1817 ;	-----------------------------------------
                                   1818 ;	 function fuzzy_triangle
                                   1819 ;	-----------------------------------------
      0007C2                       1820 _fuzzy_triangle:
      0007C2 C0 10            [24] 1821 	push	_bp
      0007C4 85 81 10         [24] 1822 	mov	_bp,sp
      0007C7 AF 82            [24] 1823 	mov	r7,dpl
      0007C9 AE 83            [24] 1824 	mov	r6,dph
      0007CB AD F0            [24] 1825 	mov	r5,b
      0007CD FC               [12] 1826 	mov	r4,a
      0007CE E5 81            [12] 1827 	mov	a,sp
      0007D0 24 08            [12] 1828 	add	a,#0x08
      0007D2 F5 81            [12] 1829 	mov	sp,a
      0007D4 C0 07            [24] 1830 	push	ar7
      0007D6 C0 06            [24] 1831 	push	ar6
      0007D8 C0 05            [24] 1832 	push	ar5
      0007DA C0 04            [24] 1833 	push	ar4
      0007DC E5 10            [12] 1834 	mov	a,_bp
      0007DE 24 FA            [12] 1835 	add	a,#0xfa
      0007E0 F8               [12] 1836 	mov	r0,a
      0007E1 E6               [12] 1837 	mov	a,@r0
      0007E2 C0 E0            [24] 1838 	push	acc
      0007E4 08               [12] 1839 	inc	r0
      0007E5 E6               [12] 1840 	mov	a,@r0
      0007E6 C0 E0            [24] 1841 	push	acc
      0007E8 08               [12] 1842 	inc	r0
      0007E9 E6               [12] 1843 	mov	a,@r0
      0007EA C0 E0            [24] 1844 	push	acc
      0007EC 08               [12] 1845 	inc	r0
      0007ED E6               [12] 1846 	mov	a,@r0
      0007EE C0 E0            [24] 1847 	push	acc
      0007F0 8F 82            [24] 1848 	mov	dpl, r7
      0007F2 8E 83            [24] 1849 	mov	dph, r6
      0007F4 8D F0            [24] 1850 	mov	b, r5
      0007F6 EC               [12] 1851 	mov	a, r4
      0007F7 12 2B E5         [24] 1852 	lcall	___fslt
      0007FA E5 81            [12] 1853 	mov	a,sp
      0007FC 24 FC            [12] 1854 	add	a,#0xfc
      0007FE F5 81            [12] 1855 	mov	sp,a
      000800 D0 04            [24] 1856 	pop	ar4
      000802 D0 05            [24] 1857 	pop	ar5
      000804 D0 06            [24] 1858 	pop	ar6
      000806 D0 07            [24] 1859 	pop	ar7
      000808 E5 82            [12] 1860 	mov	a, dpl
      00080A 24 FF            [12] 1861 	add	a,#0xff
      00080C 92 00            [24] 1862 	mov	b0,c
      00080E 40 03            [24] 1863 	jc	00145$
      000810 02 08 DA         [24] 1864 	ljmp	00107$
      000813                       1865 00145$:
      000813 C0 07            [24] 1866 	push	ar7
      000815 C0 06            [24] 1867 	push	ar6
      000817 C0 05            [24] 1868 	push	ar5
      000819 C0 04            [24] 1869 	push	ar4
      00081B E5 10            [12] 1870 	mov	a,_bp
      00081D 24 F6            [12] 1871 	add	a,#0xf6
      00081F F8               [12] 1872 	mov	r0,a
      000820 E6               [12] 1873 	mov	a,@r0
      000821 C0 E0            [24] 1874 	push	acc
      000823 08               [12] 1875 	inc	r0
      000824 E6               [12] 1876 	mov	a,@r0
      000825 C0 E0            [24] 1877 	push	acc
      000827 08               [12] 1878 	inc	r0
      000828 E6               [12] 1879 	mov	a,@r0
      000829 C0 E0            [24] 1880 	push	acc
      00082B 08               [12] 1881 	inc	r0
      00082C E6               [12] 1882 	mov	a,@r0
      00082D C0 E0            [24] 1883 	push	acc
      00082F E5 10            [12] 1884 	mov	a,_bp
      000831 24 FA            [12] 1885 	add	a,#0xfa
      000833 F8               [12] 1886 	mov	r0,a
      000834 86 82            [24] 1887 	mov	dpl, @r0
      000836 08               [12] 1888 	inc	r0
      000837 86 83            [24] 1889 	mov	dph, @r0
      000839 08               [12] 1890 	inc	r0
      00083A 86 F0            [24] 1891 	mov	b, @r0
      00083C 08               [12] 1892 	inc	r0
      00083D E6               [12] 1893 	mov	a, @r0
      00083E 12 2B E5         [24] 1894 	lcall	___fslt
      000841 E5 81            [12] 1895 	mov	a,sp
      000843 24 FC            [12] 1896 	add	a,#0xfc
      000845 F5 81            [12] 1897 	mov	sp,a
      000847 D0 04            [24] 1898 	pop	ar4
      000849 D0 05            [24] 1899 	pop	ar5
      00084B D0 06            [24] 1900 	pop	ar6
      00084D D0 07            [24] 1901 	pop	ar7
      00084F E5 82            [12] 1902 	mov	a, dpl
      000851 24 FF            [12] 1903 	add	a,#0xff
      000853 92 00            [24] 1904 	mov	b0,c
      000855 40 03            [24] 1905 	jc	00146$
      000857 02 08 DA         [24] 1906 	ljmp	00107$
      00085A                       1907 00146$:
      00085A C0 07            [24] 1908 	push	ar7
      00085C C0 06            [24] 1909 	push	ar6
      00085E C0 05            [24] 1910 	push	ar5
      000860 C0 04            [24] 1911 	push	ar4
      000862 E5 10            [12] 1912 	mov	a,_bp
      000864 24 F2            [12] 1913 	add	a,#0xf2
      000866 F8               [12] 1914 	mov	r0,a
      000867 E6               [12] 1915 	mov	a,@r0
      000868 C0 E0            [24] 1916 	push	acc
      00086A 08               [12] 1917 	inc	r0
      00086B E6               [12] 1918 	mov	a,@r0
      00086C C0 E0            [24] 1919 	push	acc
      00086E 08               [12] 1920 	inc	r0
      00086F E6               [12] 1921 	mov	a,@r0
      000870 C0 E0            [24] 1922 	push	acc
      000872 08               [12] 1923 	inc	r0
      000873 E6               [12] 1924 	mov	a,@r0
      000874 C0 E0            [24] 1925 	push	acc
      000876 8F 82            [24] 1926 	mov	dpl, r7
      000878 8E 83            [24] 1927 	mov	dph, r6
      00087A 8D F0            [24] 1928 	mov	b, r5
      00087C EC               [12] 1929 	mov	a, r4
      00087D 12 2B E5         [24] 1930 	lcall	___fslt
      000880 E5 81            [12] 1931 	mov	a,sp
      000882 24 FC            [12] 1932 	add	a,#0xfc
      000884 F5 81            [12] 1933 	mov	sp,a
      000886 D0 04            [24] 1934 	pop	ar4
      000888 D0 05            [24] 1935 	pop	ar5
      00088A D0 06            [24] 1936 	pop	ar6
      00088C D0 07            [24] 1937 	pop	ar7
      00088E E5 82            [12] 1938 	mov	a, dpl
      000890 24 FF            [12] 1939 	add	a,#0xff
      000892 92 00            [24] 1940 	mov	b0,c
      000894 50 44            [24] 1941 	jnc	00107$
      000896 C0 07            [24] 1942 	push	ar7
      000898 C0 06            [24] 1943 	push	ar6
      00089A C0 05            [24] 1944 	push	ar5
      00089C C0 04            [24] 1945 	push	ar4
      00089E E5 10            [12] 1946 	mov	a,_bp
      0008A0 24 F6            [12] 1947 	add	a,#0xf6
      0008A2 F8               [12] 1948 	mov	r0,a
      0008A3 E6               [12] 1949 	mov	a,@r0
      0008A4 C0 E0            [24] 1950 	push	acc
      0008A6 08               [12] 1951 	inc	r0
      0008A7 E6               [12] 1952 	mov	a,@r0
      0008A8 C0 E0            [24] 1953 	push	acc
      0008AA 08               [12] 1954 	inc	r0
      0008AB E6               [12] 1955 	mov	a,@r0
      0008AC C0 E0            [24] 1956 	push	acc
      0008AE 08               [12] 1957 	inc	r0
      0008AF E6               [12] 1958 	mov	a,@r0
      0008B0 C0 E0            [24] 1959 	push	acc
      0008B2 E5 10            [12] 1960 	mov	a,_bp
      0008B4 24 F2            [12] 1961 	add	a,#0xf2
      0008B6 F8               [12] 1962 	mov	r0,a
      0008B7 86 82            [24] 1963 	mov	dpl, @r0
      0008B9 08               [12] 1964 	inc	r0
      0008BA 86 83            [24] 1965 	mov	dph, @r0
      0008BC 08               [12] 1966 	inc	r0
      0008BD 86 F0            [24] 1967 	mov	b, @r0
      0008BF 08               [12] 1968 	inc	r0
      0008C0 E6               [12] 1969 	mov	a, @r0
      0008C1 12 2B E5         [24] 1970 	lcall	___fslt
      0008C4 E5 81            [12] 1971 	mov	a,sp
      0008C6 24 FC            [12] 1972 	add	a,#0xfc
      0008C8 F5 81            [12] 1973 	mov	sp,a
      0008CA D0 04            [24] 1974 	pop	ar4
      0008CC D0 05            [24] 1975 	pop	ar5
      0008CE D0 06            [24] 1976 	pop	ar6
      0008D0 D0 07            [24] 1977 	pop	ar7
      0008D2 E5 82            [12] 1978 	mov	a, dpl
      0008D4 24 FF            [12] 1979 	add	a,#0xff
      0008D6 92 00            [24] 1980 	mov	b0,c
      0008D8 40 0E            [24] 1981 	jc	00108$
      0008DA                       1982 00107$:
      0008DA A8 10            [24] 1983 	mov	r0,_bp
      0008DC 08               [12] 1984 	inc	r0
      0008DD E4               [12] 1985 	clr	a
      0008DE F6               [12] 1986 	mov	@r0,a
      0008DF 08               [12] 1987 	inc	r0
      0008E0 F6               [12] 1988 	mov	@r0,a
      0008E1 08               [12] 1989 	inc	r0
      0008E2 F6               [12] 1990 	mov	@r0,a
      0008E3 08               [12] 1991 	inc	r0
      0008E4 F6               [12] 1992 	mov	@r0,a
      0008E5 02 0A A0         [24] 1993 	ljmp	00109$
      0008E8                       1994 00108$:
      0008E8 C0 07            [24] 1995 	push	ar7
      0008EA C0 06            [24] 1996 	push	ar6
      0008EC C0 05            [24] 1997 	push	ar5
      0008EE C0 04            [24] 1998 	push	ar4
      0008F0 E5 10            [12] 1999 	mov	a,_bp
      0008F2 24 FA            [12] 2000 	add	a,#0xfa
      0008F4 F8               [12] 2001 	mov	r0,a
      0008F5 E6               [12] 2002 	mov	a,@r0
      0008F6 C0 E0            [24] 2003 	push	acc
      0008F8 08               [12] 2004 	inc	r0
      0008F9 E6               [12] 2005 	mov	a,@r0
      0008FA C0 E0            [24] 2006 	push	acc
      0008FC 08               [12] 2007 	inc	r0
      0008FD E6               [12] 2008 	mov	a,@r0
      0008FE C0 E0            [24] 2009 	push	acc
      000900 08               [12] 2010 	inc	r0
      000901 E6               [12] 2011 	mov	a,@r0
      000902 C0 E0            [24] 2012 	push	acc
      000904 E5 10            [12] 2013 	mov	a,_bp
      000906 24 F2            [12] 2014 	add	a,#0xf2
      000908 F8               [12] 2015 	mov	r0,a
      000909 86 82            [24] 2016 	mov	dpl, @r0
      00090B 08               [12] 2017 	inc	r0
      00090C 86 83            [24] 2018 	mov	dph, @r0
      00090E 08               [12] 2019 	inc	r0
      00090F 86 F0            [24] 2020 	mov	b, @r0
      000911 08               [12] 2021 	inc	r0
      000912 E6               [12] 2022 	mov	a, @r0
      000913 12 2B B9         [24] 2023 	lcall	___fseq
      000916 AB 82            [24] 2024 	mov	r3, dpl
      000918 E5 81            [12] 2025 	mov	a,sp
      00091A 24 FC            [12] 2026 	add	a,#0xfc
      00091C F5 81            [12] 2027 	mov	sp,a
      00091E D0 04            [24] 2028 	pop	ar4
      000920 D0 05            [24] 2029 	pop	ar5
      000922 D0 06            [24] 2030 	pop	ar6
      000924 D0 07            [24] 2031 	pop	ar7
      000926 EB               [12] 2032 	mov	a,r3
      000927 60 10            [24] 2033 	jz	00105$
      000929 A8 10            [24] 2034 	mov	r0,_bp
      00092B 08               [12] 2035 	inc	r0
      00092C E4               [12] 2036 	clr	a
      00092D F6               [12] 2037 	mov	@r0,a
      00092E 08               [12] 2038 	inc	r0
      00092F F6               [12] 2039 	mov	@r0,a
      000930 08               [12] 2040 	inc	r0
      000931 76 80            [12] 2041 	mov	@r0,#0x80
      000933 08               [12] 2042 	inc	r0
      000934 76 3F            [12] 2043 	mov	@r0,#0x3f
      000936 02 0A A0         [24] 2044 	ljmp	00109$
      000939                       2045 00105$:
      000939 C0 07            [24] 2046 	push	ar7
      00093B C0 06            [24] 2047 	push	ar6
      00093D C0 05            [24] 2048 	push	ar5
      00093F C0 04            [24] 2049 	push	ar4
      000941 E5 10            [12] 2050 	mov	a,_bp
      000943 24 FA            [12] 2051 	add	a,#0xfa
      000945 F8               [12] 2052 	mov	r0,a
      000946 E6               [12] 2053 	mov	a,@r0
      000947 C0 E0            [24] 2054 	push	acc
      000949 08               [12] 2055 	inc	r0
      00094A E6               [12] 2056 	mov	a,@r0
      00094B C0 E0            [24] 2057 	push	acc
      00094D 08               [12] 2058 	inc	r0
      00094E E6               [12] 2059 	mov	a,@r0
      00094F C0 E0            [24] 2060 	push	acc
      000951 08               [12] 2061 	inc	r0
      000952 E6               [12] 2062 	mov	a,@r0
      000953 C0 E0            [24] 2063 	push	acc
      000955 E5 10            [12] 2064 	mov	a,_bp
      000957 24 F2            [12] 2065 	add	a,#0xf2
      000959 F8               [12] 2066 	mov	r0,a
      00095A 86 82            [24] 2067 	mov	dpl, @r0
      00095C 08               [12] 2068 	inc	r0
      00095D 86 83            [24] 2069 	mov	dph, @r0
      00095F 08               [12] 2070 	inc	r0
      000960 86 F0            [24] 2071 	mov	b, @r0
      000962 08               [12] 2072 	inc	r0
      000963 E6               [12] 2073 	mov	a, @r0
      000964 12 2B E5         [24] 2074 	lcall	___fslt
      000967 AB 82            [24] 2075 	mov	r3, dpl
      000969 E5 81            [12] 2076 	mov	a,sp
      00096B 24 FC            [12] 2077 	add	a,#0xfc
      00096D F5 81            [12] 2078 	mov	sp,a
      00096F D0 04            [24] 2079 	pop	ar4
      000971 D0 05            [24] 2080 	pop	ar5
      000973 D0 06            [24] 2081 	pop	ar6
      000975 D0 07            [24] 2082 	pop	ar7
      000977 EB               [12] 2083 	mov	a,r3
      000978 70 03            [24] 2084 	jnz	00150$
      00097A 02 0A 04         [24] 2085 	ljmp	00102$
      00097D                       2086 00150$:
      00097D C0 07            [24] 2087 	push	ar7
      00097F C0 06            [24] 2088 	push	ar6
      000981 C0 05            [24] 2089 	push	ar5
      000983 C0 04            [24] 2090 	push	ar4
      000985 C0 07            [24] 2091 	push	ar7
      000987 C0 06            [24] 2092 	push	ar6
      000989 C0 05            [24] 2093 	push	ar5
      00098B C0 04            [24] 2094 	push	ar4
      00098D E5 10            [12] 2095 	mov	a,_bp
      00098F 24 F2            [12] 2096 	add	a,#0xf2
      000991 F8               [12] 2097 	mov	r0,a
      000992 86 82            [24] 2098 	mov	dpl, @r0
      000994 08               [12] 2099 	inc	r0
      000995 86 83            [24] 2100 	mov	dph, @r0
      000997 08               [12] 2101 	inc	r0
      000998 86 F0            [24] 2102 	mov	b, @r0
      00099A 08               [12] 2103 	inc	r0
      00099B E6               [12] 2104 	mov	a, @r0
      00099C 12 2A AA         [24] 2105 	lcall	___fssub
      00099F C8               [12] 2106 	xch	a,r0
      0009A0 E5 10            [12] 2107 	mov	a,_bp
      0009A2 24 05            [12] 2108 	add	a,#0x05
      0009A4 C8               [12] 2109 	xch	a,r0
      0009A5 A6 82            [24] 2110 	mov	@r0, dpl
      0009A7 08               [12] 2111 	inc	r0
      0009A8 A6 83            [24] 2112 	mov	@r0, dph
      0009AA 08               [12] 2113 	inc	r0
      0009AB A6 F0            [24] 2114 	mov	@r0, b
      0009AD 08               [12] 2115 	inc	r0
      0009AE F6               [12] 2116 	mov	@r0,a
      0009AF E5 81            [12] 2117 	mov	a,sp
      0009B1 24 FC            [12] 2118 	add	a,#0xfc
      0009B3 F5 81            [12] 2119 	mov	sp,a
      0009B5 E5 10            [12] 2120 	mov	a,_bp
      0009B7 24 FA            [12] 2121 	add	a,#0xfa
      0009B9 F8               [12] 2122 	mov	r0,a
      0009BA 86 82            [24] 2123 	mov	dpl, @r0
      0009BC 08               [12] 2124 	inc	r0
      0009BD 86 83            [24] 2125 	mov	dph, @r0
      0009BF 08               [12] 2126 	inc	r0
      0009C0 86 F0            [24] 2127 	mov	b, @r0
      0009C2 08               [12] 2128 	inc	r0
      0009C3 E6               [12] 2129 	mov	a, @r0
      0009C4 12 2A AA         [24] 2130 	lcall	___fssub
      0009C7 AC 82            [24] 2131 	mov	r4, dpl
      0009C9 AD 83            [24] 2132 	mov	r5, dph
      0009CB AE F0            [24] 2133 	mov	r6, b
      0009CD FF               [12] 2134 	mov	r7, a
      0009CE E5 81            [12] 2135 	mov	a,sp
      0009D0 24 FC            [12] 2136 	add	a,#0xfc
      0009D2 F5 81            [12] 2137 	mov	sp,a
      0009D4 C0 04            [24] 2138 	push	ar4
      0009D6 C0 05            [24] 2139 	push	ar5
      0009D8 C0 06            [24] 2140 	push	ar6
      0009DA C0 07            [24] 2141 	push	ar7
      0009DC E5 10            [12] 2142 	mov	a,_bp
      0009DE 24 05            [12] 2143 	add	a,#0x05
      0009E0 F8               [12] 2144 	mov	r0,a
      0009E1 86 82            [24] 2145 	mov	dpl, @r0
      0009E3 08               [12] 2146 	inc	r0
      0009E4 86 83            [24] 2147 	mov	dph, @r0
      0009E6 08               [12] 2148 	inc	r0
      0009E7 86 F0            [24] 2149 	mov	b, @r0
      0009E9 08               [12] 2150 	inc	r0
      0009EA E6               [12] 2151 	mov	a, @r0
      0009EB 12 2D 2C         [24] 2152 	lcall	___fsdiv
      0009EE A8 10            [24] 2153 	mov	r0,_bp
      0009F0 08               [12] 2154 	inc	r0
      0009F1 A6 82            [24] 2155 	mov	@r0, dpl
      0009F3 08               [12] 2156 	inc	r0
      0009F4 A6 83            [24] 2157 	mov	@r0, dph
      0009F6 08               [12] 2158 	inc	r0
      0009F7 A6 F0            [24] 2159 	mov	@r0, b
      0009F9 08               [12] 2160 	inc	r0
      0009FA F6               [12] 2161 	mov	@r0,a
      0009FB E5 81            [12] 2162 	mov	a,sp
      0009FD 24 FC            [12] 2163 	add	a,#0xfc
      0009FF F5 81            [12] 2164 	mov	sp,a
      000A01 02 0A A0         [24] 2165 	ljmp	00109$
      000A04                       2166 00102$:
      000A04 E5 10            [12] 2167 	mov	a,_bp
      000A06 24 F2            [12] 2168 	add	a,#0xf2
      000A08 F8               [12] 2169 	mov	r0,a
      000A09 E6               [12] 2170 	mov	a,@r0
      000A0A C0 E0            [24] 2171 	push	acc
      000A0C 08               [12] 2172 	inc	r0
      000A0D E6               [12] 2173 	mov	a,@r0
      000A0E C0 E0            [24] 2174 	push	acc
      000A10 08               [12] 2175 	inc	r0
      000A11 E6               [12] 2176 	mov	a,@r0
      000A12 C0 E0            [24] 2177 	push	acc
      000A14 08               [12] 2178 	inc	r0
      000A15 E6               [12] 2179 	mov	a,@r0
      000A16 C0 E0            [24] 2180 	push	acc
      000A18 E5 10            [12] 2181 	mov	a,_bp
      000A1A 24 F6            [12] 2182 	add	a,#0xf6
      000A1C F8               [12] 2183 	mov	r0,a
      000A1D 86 82            [24] 2184 	mov	dpl, @r0
      000A1F 08               [12] 2185 	inc	r0
      000A20 86 83            [24] 2186 	mov	dph, @r0
      000A22 08               [12] 2187 	inc	r0
      000A23 86 F0            [24] 2188 	mov	b, @r0
      000A25 08               [12] 2189 	inc	r0
      000A26 E6               [12] 2190 	mov	a, @r0
      000A27 12 2A AA         [24] 2191 	lcall	___fssub
      000A2A C8               [12] 2192 	xch	a,r0
      000A2B E5 10            [12] 2193 	mov	a,_bp
      000A2D 24 05            [12] 2194 	add	a,#0x05
      000A2F C8               [12] 2195 	xch	a,r0
      000A30 A6 82            [24] 2196 	mov	@r0, dpl
      000A32 08               [12] 2197 	inc	r0
      000A33 A6 83            [24] 2198 	mov	@r0, dph
      000A35 08               [12] 2199 	inc	r0
      000A36 A6 F0            [24] 2200 	mov	@r0, b
      000A38 08               [12] 2201 	inc	r0
      000A39 F6               [12] 2202 	mov	@r0,a
      000A3A E5 81            [12] 2203 	mov	a,sp
      000A3C 24 FC            [12] 2204 	add	a,#0xfc
      000A3E F5 81            [12] 2205 	mov	sp,a
      000A40 E5 10            [12] 2206 	mov	a,_bp
      000A42 24 FA            [12] 2207 	add	a,#0xfa
      000A44 F8               [12] 2208 	mov	r0,a
      000A45 E6               [12] 2209 	mov	a,@r0
      000A46 C0 E0            [24] 2210 	push	acc
      000A48 08               [12] 2211 	inc	r0
      000A49 E6               [12] 2212 	mov	a,@r0
      000A4A C0 E0            [24] 2213 	push	acc
      000A4C 08               [12] 2214 	inc	r0
      000A4D E6               [12] 2215 	mov	a,@r0
      000A4E C0 E0            [24] 2216 	push	acc
      000A50 08               [12] 2217 	inc	r0
      000A51 E6               [12] 2218 	mov	a,@r0
      000A52 C0 E0            [24] 2219 	push	acc
      000A54 E5 10            [12] 2220 	mov	a,_bp
      000A56 24 F6            [12] 2221 	add	a,#0xf6
      000A58 F8               [12] 2222 	mov	r0,a
      000A59 86 82            [24] 2223 	mov	dpl, @r0
      000A5B 08               [12] 2224 	inc	r0
      000A5C 86 83            [24] 2225 	mov	dph, @r0
      000A5E 08               [12] 2226 	inc	r0
      000A5F 86 F0            [24] 2227 	mov	b, @r0
      000A61 08               [12] 2228 	inc	r0
      000A62 E6               [12] 2229 	mov	a, @r0
      000A63 12 2A AA         [24] 2230 	lcall	___fssub
      000A66 AA 82            [24] 2231 	mov	r2, dpl
      000A68 AB 83            [24] 2232 	mov	r3, dph
      000A6A AE F0            [24] 2233 	mov	r6, b
      000A6C FF               [12] 2234 	mov	r7, a
      000A6D E5 81            [12] 2235 	mov	a,sp
      000A6F 24 FC            [12] 2236 	add	a,#0xfc
      000A71 F5 81            [12] 2237 	mov	sp,a
      000A73 C0 02            [24] 2238 	push	ar2
      000A75 C0 03            [24] 2239 	push	ar3
      000A77 C0 06            [24] 2240 	push	ar6
      000A79 C0 07            [24] 2241 	push	ar7
      000A7B E5 10            [12] 2242 	mov	a,_bp
      000A7D 24 05            [12] 2243 	add	a,#0x05
      000A7F F8               [12] 2244 	mov	r0,a
      000A80 86 82            [24] 2245 	mov	dpl, @r0
      000A82 08               [12] 2246 	inc	r0
      000A83 86 83            [24] 2247 	mov	dph, @r0
      000A85 08               [12] 2248 	inc	r0
      000A86 86 F0            [24] 2249 	mov	b, @r0
      000A88 08               [12] 2250 	inc	r0
      000A89 E6               [12] 2251 	mov	a, @r0
      000A8A 12 2D 2C         [24] 2252 	lcall	___fsdiv
      000A8D A8 10            [24] 2253 	mov	r0,_bp
      000A8F 08               [12] 2254 	inc	r0
      000A90 A6 82            [24] 2255 	mov	@r0, dpl
      000A92 08               [12] 2256 	inc	r0
      000A93 A6 83            [24] 2257 	mov	@r0, dph
      000A95 08               [12] 2258 	inc	r0
      000A96 A6 F0            [24] 2259 	mov	@r0, b
      000A98 08               [12] 2260 	inc	r0
      000A99 F6               [12] 2261 	mov	@r0,a
      000A9A E5 81            [12] 2262 	mov	a,sp
      000A9C 24 FC            [12] 2263 	add	a,#0xfc
      000A9E F5 81            [12] 2264 	mov	sp,a
      000AA0                       2265 00109$:
      000AA0 E5 10            [12] 2266 	mov	a,_bp
      000AA2 24 F1            [12] 2267 	add	a,#0xf1
      000AA4 F8               [12] 2268 	mov	r0,a
      000AA5 E6               [12] 2269 	mov	a,@r0
      000AA6 C0 E0            [24] 2270 	push	acc
      000AA8 A8 10            [24] 2271 	mov	r0,_bp
      000AAA 08               [12] 2272 	inc	r0
      000AAB 86 82            [24] 2273 	mov	dpl, @r0
      000AAD 08               [12] 2274 	inc	r0
      000AAE 86 83            [24] 2275 	mov	dph, @r0
      000AB0 08               [12] 2276 	inc	r0
      000AB1 86 F0            [24] 2277 	mov	b, @r0
      000AB3 08               [12] 2278 	inc	r0
      000AB4 E6               [12] 2279 	mov	a, @r0
      000AB5 12 04 FA         [24] 2280 	lcall	_fuzzy_8051_hedge
      000AB8 AC 82            [24] 2281 	mov	r4, dpl
      000ABA AD 83            [24] 2282 	mov	r5, dph
      000ABC AE F0            [24] 2283 	mov	r6, b
      000ABE FF               [12] 2284 	mov	r7, a
      000ABF 15 81            [12] 2285 	dec	sp
      000AC1 8C 82            [24] 2286 	mov	dpl, r4
      000AC3 8D 83            [24] 2287 	mov	dph, r5
      000AC5 8E F0            [24] 2288 	mov	b, r6
      000AC7 EF               [12] 2289 	mov	a, r7
      000AC8 85 10 81         [24] 2290 	mov	sp,_bp
      000ACB D0 10            [24] 2291 	pop	_bp
                           000A10  2292 	C$fuzzy.h$70$1_0$31 ==.
                           000A10  2293 	XG$fuzzy_triangle$0$0 ==.
      000ACD 22               [24] 2294 	ret
                                   2295 ;------------------------------------------------------------
                                   2296 ;Allocation info for local variables in function 'fuzzy_trapezoid'
                                   2297 ;------------------------------------------------------------
                                   2298 ;b             Allocated to stack - _bp -6 +4 
                                   2299 ;c             Allocated to stack - _bp -10 +4 
                                   2300 ;d             Allocated to stack - _bp -14 +4 
                                   2301 ;x             Allocated to stack - _bp -18 +4 
                                   2302 ;hedge         Allocated to stack - _bp -19 +1 
                                   2303 ;a             Allocated to registers r7 r6 r5 r4 
                                   2304 ;result        Allocated to stack - _bp +1 +4 
                                   2305 ;sloc0         Allocated to stack - _bp +1 +4 
                                   2306 ;sloc1         Allocated to stack - _bp +5 +4 
                                   2307 ;------------------------------------------------------------
                           000A11  2308 	G$fuzzy_trapezoid$0$0 ==.
                           000A11  2309 	C$fuzzy.h$71$1_0$33 ==.
                                   2310 ;	../../fuzzy.h:71: float fuzzy_trapezoid(float a, float b, float c, float d, float x, fuzzy_hedge_t hedge) { float result; if (a >= b || b > c || c >= d || x <= a || x >= d) result = 0.0f; else if (x >= b && x <= c) result = 1.0f; else if (x < b) result = (x - a) / (b - a); else result = (d - x) / (d - c); return fuzzy_8051_hedge(result, hedge); }
                                   2311 ;	-----------------------------------------
                                   2312 ;	 function fuzzy_trapezoid
                                   2313 ;	-----------------------------------------
      000ACE                       2314 _fuzzy_trapezoid:
      000ACE C0 10            [24] 2315 	push	_bp
      000AD0 85 81 10         [24] 2316 	mov	_bp,sp
      000AD3 AF 82            [24] 2317 	mov	r7,dpl
      000AD5 AE 83            [24] 2318 	mov	r6,dph
      000AD7 AD F0            [24] 2319 	mov	r5,b
      000AD9 FC               [12] 2320 	mov	r4,a
      000ADA E5 81            [12] 2321 	mov	a,sp
      000ADC 24 08            [12] 2322 	add	a,#0x08
      000ADE F5 81            [12] 2323 	mov	sp,a
      000AE0 C0 07            [24] 2324 	push	ar7
      000AE2 C0 06            [24] 2325 	push	ar6
      000AE4 C0 05            [24] 2326 	push	ar5
      000AE6 C0 04            [24] 2327 	push	ar4
      000AE8 E5 10            [12] 2328 	mov	a,_bp
      000AEA 24 FA            [12] 2329 	add	a,#0xfa
      000AEC F8               [12] 2330 	mov	r0,a
      000AED E6               [12] 2331 	mov	a,@r0
      000AEE C0 E0            [24] 2332 	push	acc
      000AF0 08               [12] 2333 	inc	r0
      000AF1 E6               [12] 2334 	mov	a,@r0
      000AF2 C0 E0            [24] 2335 	push	acc
      000AF4 08               [12] 2336 	inc	r0
      000AF5 E6               [12] 2337 	mov	a,@r0
      000AF6 C0 E0            [24] 2338 	push	acc
      000AF8 08               [12] 2339 	inc	r0
      000AF9 E6               [12] 2340 	mov	a,@r0
      000AFA C0 E0            [24] 2341 	push	acc
      000AFC 8F 82            [24] 2342 	mov	dpl, r7
      000AFE 8E 83            [24] 2343 	mov	dph, r6
      000B00 8D F0            [24] 2344 	mov	b, r5
      000B02 EC               [12] 2345 	mov	a, r4
      000B03 12 2B E5         [24] 2346 	lcall	___fslt
      000B06 E5 81            [12] 2347 	mov	a,sp
      000B08 24 FC            [12] 2348 	add	a,#0xfc
      000B0A F5 81            [12] 2349 	mov	sp,a
      000B0C D0 04            [24] 2350 	pop	ar4
      000B0E D0 05            [24] 2351 	pop	ar5
      000B10 D0 06            [24] 2352 	pop	ar6
      000B12 D0 07            [24] 2353 	pop	ar7
      000B14 E5 82            [12] 2354 	mov	a, dpl
      000B16 24 FF            [12] 2355 	add	a,#0xff
      000B18 92 00            [24] 2356 	mov	b0,c
      000B1A 40 03            [24] 2357 	jc	00159$
      000B1C 02 0C 2A         [24] 2358 	ljmp	00108$
      000B1F                       2359 00159$:
      000B1F C0 07            [24] 2360 	push	ar7
      000B21 C0 06            [24] 2361 	push	ar6
      000B23 C0 05            [24] 2362 	push	ar5
      000B25 C0 04            [24] 2363 	push	ar4
      000B27 E5 10            [12] 2364 	mov	a,_bp
      000B29 24 FA            [12] 2365 	add	a,#0xfa
      000B2B F8               [12] 2366 	mov	r0,a
      000B2C E6               [12] 2367 	mov	a,@r0
      000B2D C0 E0            [24] 2368 	push	acc
      000B2F 08               [12] 2369 	inc	r0
      000B30 E6               [12] 2370 	mov	a,@r0
      000B31 C0 E0            [24] 2371 	push	acc
      000B33 08               [12] 2372 	inc	r0
      000B34 E6               [12] 2373 	mov	a,@r0
      000B35 C0 E0            [24] 2374 	push	acc
      000B37 08               [12] 2375 	inc	r0
      000B38 E6               [12] 2376 	mov	a,@r0
      000B39 C0 E0            [24] 2377 	push	acc
      000B3B E5 10            [12] 2378 	mov	a,_bp
      000B3D 24 F6            [12] 2379 	add	a,#0xf6
      000B3F F8               [12] 2380 	mov	r0,a
      000B40 86 82            [24] 2381 	mov	dpl, @r0
      000B42 08               [12] 2382 	inc	r0
      000B43 86 83            [24] 2383 	mov	dph, @r0
      000B45 08               [12] 2384 	inc	r0
      000B46 86 F0            [24] 2385 	mov	b, @r0
      000B48 08               [12] 2386 	inc	r0
      000B49 E6               [12] 2387 	mov	a, @r0
      000B4A 12 2B E5         [24] 2388 	lcall	___fslt
      000B4D AB 82            [24] 2389 	mov	r3, dpl
      000B4F E5 81            [12] 2390 	mov	a,sp
      000B51 24 FC            [12] 2391 	add	a,#0xfc
      000B53 F5 81            [12] 2392 	mov	sp,a
      000B55 D0 04            [24] 2393 	pop	ar4
      000B57 D0 05            [24] 2394 	pop	ar5
      000B59 D0 06            [24] 2395 	pop	ar6
      000B5B D0 07            [24] 2396 	pop	ar7
      000B5D EB               [12] 2397 	mov	a,r3
      000B5E 60 03            [24] 2398 	jz	00160$
      000B60 02 0C 2A         [24] 2399 	ljmp	00108$
      000B63                       2400 00160$:
      000B63 C0 07            [24] 2401 	push	ar7
      000B65 C0 06            [24] 2402 	push	ar6
      000B67 C0 05            [24] 2403 	push	ar5
      000B69 C0 04            [24] 2404 	push	ar4
      000B6B E5 10            [12] 2405 	mov	a,_bp
      000B6D 24 F2            [12] 2406 	add	a,#0xf2
      000B6F F8               [12] 2407 	mov	r0,a
      000B70 E6               [12] 2408 	mov	a,@r0
      000B71 C0 E0            [24] 2409 	push	acc
      000B73 08               [12] 2410 	inc	r0
      000B74 E6               [12] 2411 	mov	a,@r0
      000B75 C0 E0            [24] 2412 	push	acc
      000B77 08               [12] 2413 	inc	r0
      000B78 E6               [12] 2414 	mov	a,@r0
      000B79 C0 E0            [24] 2415 	push	acc
      000B7B 08               [12] 2416 	inc	r0
      000B7C E6               [12] 2417 	mov	a,@r0
      000B7D C0 E0            [24] 2418 	push	acc
      000B7F E5 10            [12] 2419 	mov	a,_bp
      000B81 24 F6            [12] 2420 	add	a,#0xf6
      000B83 F8               [12] 2421 	mov	r0,a
      000B84 86 82            [24] 2422 	mov	dpl, @r0
      000B86 08               [12] 2423 	inc	r0
      000B87 86 83            [24] 2424 	mov	dph, @r0
      000B89 08               [12] 2425 	inc	r0
      000B8A 86 F0            [24] 2426 	mov	b, @r0
      000B8C 08               [12] 2427 	inc	r0
      000B8D E6               [12] 2428 	mov	a, @r0
      000B8E 12 2B E5         [24] 2429 	lcall	___fslt
      000B91 E5 81            [12] 2430 	mov	a,sp
      000B93 24 FC            [12] 2431 	add	a,#0xfc
      000B95 F5 81            [12] 2432 	mov	sp,a
      000B97 D0 04            [24] 2433 	pop	ar4
      000B99 D0 05            [24] 2434 	pop	ar5
      000B9B D0 06            [24] 2435 	pop	ar6
      000B9D D0 07            [24] 2436 	pop	ar7
      000B9F E5 82            [12] 2437 	mov	a, dpl
      000BA1 24 FF            [12] 2438 	add	a,#0xff
      000BA3 92 00            [24] 2439 	mov	b0,c
      000BA5 40 03            [24] 2440 	jc	00161$
      000BA7 02 0C 2A         [24] 2441 	ljmp	00108$
      000BAA                       2442 00161$:
      000BAA C0 07            [24] 2443 	push	ar7
      000BAC C0 06            [24] 2444 	push	ar6
      000BAE C0 05            [24] 2445 	push	ar5
      000BB0 C0 04            [24] 2446 	push	ar4
      000BB2 E5 10            [12] 2447 	mov	a,_bp
      000BB4 24 EE            [12] 2448 	add	a,#0xee
      000BB6 F8               [12] 2449 	mov	r0,a
      000BB7 E6               [12] 2450 	mov	a,@r0
      000BB8 C0 E0            [24] 2451 	push	acc
      000BBA 08               [12] 2452 	inc	r0
      000BBB E6               [12] 2453 	mov	a,@r0
      000BBC C0 E0            [24] 2454 	push	acc
      000BBE 08               [12] 2455 	inc	r0
      000BBF E6               [12] 2456 	mov	a,@r0
      000BC0 C0 E0            [24] 2457 	push	acc
      000BC2 08               [12] 2458 	inc	r0
      000BC3 E6               [12] 2459 	mov	a,@r0
      000BC4 C0 E0            [24] 2460 	push	acc
      000BC6 8F 82            [24] 2461 	mov	dpl, r7
      000BC8 8E 83            [24] 2462 	mov	dph, r6
      000BCA 8D F0            [24] 2463 	mov	b, r5
      000BCC EC               [12] 2464 	mov	a, r4
      000BCD 12 2B E5         [24] 2465 	lcall	___fslt
      000BD0 E5 81            [12] 2466 	mov	a,sp
      000BD2 24 FC            [12] 2467 	add	a,#0xfc
      000BD4 F5 81            [12] 2468 	mov	sp,a
      000BD6 D0 04            [24] 2469 	pop	ar4
      000BD8 D0 05            [24] 2470 	pop	ar5
      000BDA D0 06            [24] 2471 	pop	ar6
      000BDC D0 07            [24] 2472 	pop	ar7
      000BDE E5 82            [12] 2473 	mov	a, dpl
      000BE0 24 FF            [12] 2474 	add	a,#0xff
      000BE2 92 00            [24] 2475 	mov	b0,c
      000BE4 50 44            [24] 2476 	jnc	00108$
      000BE6 C0 07            [24] 2477 	push	ar7
      000BE8 C0 06            [24] 2478 	push	ar6
      000BEA C0 05            [24] 2479 	push	ar5
      000BEC C0 04            [24] 2480 	push	ar4
      000BEE E5 10            [12] 2481 	mov	a,_bp
      000BF0 24 F2            [12] 2482 	add	a,#0xf2
      000BF2 F8               [12] 2483 	mov	r0,a
      000BF3 E6               [12] 2484 	mov	a,@r0
      000BF4 C0 E0            [24] 2485 	push	acc
      000BF6 08               [12] 2486 	inc	r0
      000BF7 E6               [12] 2487 	mov	a,@r0
      000BF8 C0 E0            [24] 2488 	push	acc
      000BFA 08               [12] 2489 	inc	r0
      000BFB E6               [12] 2490 	mov	a,@r0
      000BFC C0 E0            [24] 2491 	push	acc
      000BFE 08               [12] 2492 	inc	r0
      000BFF E6               [12] 2493 	mov	a,@r0
      000C00 C0 E0            [24] 2494 	push	acc
      000C02 E5 10            [12] 2495 	mov	a,_bp
      000C04 24 EE            [12] 2496 	add	a,#0xee
      000C06 F8               [12] 2497 	mov	r0,a
      000C07 86 82            [24] 2498 	mov	dpl, @r0
      000C09 08               [12] 2499 	inc	r0
      000C0A 86 83            [24] 2500 	mov	dph, @r0
      000C0C 08               [12] 2501 	inc	r0
      000C0D 86 F0            [24] 2502 	mov	b, @r0
      000C0F 08               [12] 2503 	inc	r0
      000C10 E6               [12] 2504 	mov	a, @r0
      000C11 12 2B E5         [24] 2505 	lcall	___fslt
      000C14 E5 81            [12] 2506 	mov	a,sp
      000C16 24 FC            [12] 2507 	add	a,#0xfc
      000C18 F5 81            [12] 2508 	mov	sp,a
      000C1A D0 04            [24] 2509 	pop	ar4
      000C1C D0 05            [24] 2510 	pop	ar5
      000C1E D0 06            [24] 2511 	pop	ar6
      000C20 D0 07            [24] 2512 	pop	ar7
      000C22 E5 82            [12] 2513 	mov	a, dpl
      000C24 24 FF            [12] 2514 	add	a,#0xff
      000C26 92 00            [24] 2515 	mov	b0,c
      000C28 40 0E            [24] 2516 	jc	00109$
      000C2A                       2517 00108$:
      000C2A A8 10            [24] 2518 	mov	r0,_bp
      000C2C 08               [12] 2519 	inc	r0
      000C2D E4               [12] 2520 	clr	a
      000C2E F6               [12] 2521 	mov	@r0,a
      000C2F 08               [12] 2522 	inc	r0
      000C30 F6               [12] 2523 	mov	@r0,a
      000C31 08               [12] 2524 	inc	r0
      000C32 F6               [12] 2525 	mov	@r0,a
      000C33 08               [12] 2526 	inc	r0
      000C34 F6               [12] 2527 	mov	@r0,a
      000C35 02 0E 37         [24] 2528 	ljmp	00110$
      000C38                       2529 00109$:
      000C38 C0 07            [24] 2530 	push	ar7
      000C3A C0 06            [24] 2531 	push	ar6
      000C3C C0 05            [24] 2532 	push	ar5
      000C3E C0 04            [24] 2533 	push	ar4
      000C40 E5 10            [12] 2534 	mov	a,_bp
      000C42 24 FA            [12] 2535 	add	a,#0xfa
      000C44 F8               [12] 2536 	mov	r0,a
      000C45 E6               [12] 2537 	mov	a,@r0
      000C46 C0 E0            [24] 2538 	push	acc
      000C48 08               [12] 2539 	inc	r0
      000C49 E6               [12] 2540 	mov	a,@r0
      000C4A C0 E0            [24] 2541 	push	acc
      000C4C 08               [12] 2542 	inc	r0
      000C4D E6               [12] 2543 	mov	a,@r0
      000C4E C0 E0            [24] 2544 	push	acc
      000C50 08               [12] 2545 	inc	r0
      000C51 E6               [12] 2546 	mov	a,@r0
      000C52 C0 E0            [24] 2547 	push	acc
      000C54 E5 10            [12] 2548 	mov	a,_bp
      000C56 24 EE            [12] 2549 	add	a,#0xee
      000C58 F8               [12] 2550 	mov	r0,a
      000C59 86 82            [24] 2551 	mov	dpl, @r0
      000C5B 08               [12] 2552 	inc	r0
      000C5C 86 83            [24] 2553 	mov	dph, @r0
      000C5E 08               [12] 2554 	inc	r0
      000C5F 86 F0            [24] 2555 	mov	b, @r0
      000C61 08               [12] 2556 	inc	r0
      000C62 E6               [12] 2557 	mov	a, @r0
      000C63 12 2B E5         [24] 2558 	lcall	___fslt
      000C66 E5 81            [12] 2559 	mov	a,sp
      000C68 24 FC            [12] 2560 	add	a,#0xfc
      000C6A F5 81            [12] 2561 	mov	sp,a
      000C6C D0 04            [24] 2562 	pop	ar4
      000C6E D0 05            [24] 2563 	pop	ar5
      000C70 D0 06            [24] 2564 	pop	ar6
      000C72 D0 07            [24] 2565 	pop	ar7
      000C74 E5 82            [12] 2566 	mov	a, dpl
      000C76 24 FF            [12] 2567 	add	a,#0xff
      000C78 92 00            [24] 2568 	mov	b0,c
      000C7A 40 54            [24] 2569 	jc	00105$
      000C7C C0 07            [24] 2570 	push	ar7
      000C7E C0 06            [24] 2571 	push	ar6
      000C80 C0 05            [24] 2572 	push	ar5
      000C82 C0 04            [24] 2573 	push	ar4
      000C84 E5 10            [12] 2574 	mov	a,_bp
      000C86 24 EE            [12] 2575 	add	a,#0xee
      000C88 F8               [12] 2576 	mov	r0,a
      000C89 E6               [12] 2577 	mov	a,@r0
      000C8A C0 E0            [24] 2578 	push	acc
      000C8C 08               [12] 2579 	inc	r0
      000C8D E6               [12] 2580 	mov	a,@r0
      000C8E C0 E0            [24] 2581 	push	acc
      000C90 08               [12] 2582 	inc	r0
      000C91 E6               [12] 2583 	mov	a,@r0
      000C92 C0 E0            [24] 2584 	push	acc
      000C94 08               [12] 2585 	inc	r0
      000C95 E6               [12] 2586 	mov	a,@r0
      000C96 C0 E0            [24] 2587 	push	acc
      000C98 E5 10            [12] 2588 	mov	a,_bp
      000C9A 24 F6            [12] 2589 	add	a,#0xf6
      000C9C F8               [12] 2590 	mov	r0,a
      000C9D 86 82            [24] 2591 	mov	dpl, @r0
      000C9F 08               [12] 2592 	inc	r0
      000CA0 86 83            [24] 2593 	mov	dph, @r0
      000CA2 08               [12] 2594 	inc	r0
      000CA3 86 F0            [24] 2595 	mov	b, @r0
      000CA5 08               [12] 2596 	inc	r0
      000CA6 E6               [12] 2597 	mov	a, @r0
      000CA7 12 2B E5         [24] 2598 	lcall	___fslt
      000CAA E5 81            [12] 2599 	mov	a,sp
      000CAC 24 FC            [12] 2600 	add	a,#0xfc
      000CAE F5 81            [12] 2601 	mov	sp,a
      000CB0 D0 04            [24] 2602 	pop	ar4
      000CB2 D0 05            [24] 2603 	pop	ar5
      000CB4 D0 06            [24] 2604 	pop	ar6
      000CB6 D0 07            [24] 2605 	pop	ar7
      000CB8 E5 82            [12] 2606 	mov	a, dpl
      000CBA 24 FF            [12] 2607 	add	a,#0xff
      000CBC 92 00            [24] 2608 	mov	b0,c
      000CBE 40 10            [24] 2609 	jc	00105$
      000CC0 A8 10            [24] 2610 	mov	r0,_bp
      000CC2 08               [12] 2611 	inc	r0
      000CC3 E4               [12] 2612 	clr	a
      000CC4 F6               [12] 2613 	mov	@r0,a
      000CC5 08               [12] 2614 	inc	r0
      000CC6 F6               [12] 2615 	mov	@r0,a
      000CC7 08               [12] 2616 	inc	r0
      000CC8 76 80            [12] 2617 	mov	@r0,#0x80
      000CCA 08               [12] 2618 	inc	r0
      000CCB 76 3F            [12] 2619 	mov	@r0,#0x3f
      000CCD 02 0E 37         [24] 2620 	ljmp	00110$
      000CD0                       2621 00105$:
      000CD0 C0 07            [24] 2622 	push	ar7
      000CD2 C0 06            [24] 2623 	push	ar6
      000CD4 C0 05            [24] 2624 	push	ar5
      000CD6 C0 04            [24] 2625 	push	ar4
      000CD8 E5 10            [12] 2626 	mov	a,_bp
      000CDA 24 FA            [12] 2627 	add	a,#0xfa
      000CDC F8               [12] 2628 	mov	r0,a
      000CDD E6               [12] 2629 	mov	a,@r0
      000CDE C0 E0            [24] 2630 	push	acc
      000CE0 08               [12] 2631 	inc	r0
      000CE1 E6               [12] 2632 	mov	a,@r0
      000CE2 C0 E0            [24] 2633 	push	acc
      000CE4 08               [12] 2634 	inc	r0
      000CE5 E6               [12] 2635 	mov	a,@r0
      000CE6 C0 E0            [24] 2636 	push	acc
      000CE8 08               [12] 2637 	inc	r0
      000CE9 E6               [12] 2638 	mov	a,@r0
      000CEA C0 E0            [24] 2639 	push	acc
      000CEC E5 10            [12] 2640 	mov	a,_bp
      000CEE 24 EE            [12] 2641 	add	a,#0xee
      000CF0 F8               [12] 2642 	mov	r0,a
      000CF1 86 82            [24] 2643 	mov	dpl, @r0
      000CF3 08               [12] 2644 	inc	r0
      000CF4 86 83            [24] 2645 	mov	dph, @r0
      000CF6 08               [12] 2646 	inc	r0
      000CF7 86 F0            [24] 2647 	mov	b, @r0
      000CF9 08               [12] 2648 	inc	r0
      000CFA E6               [12] 2649 	mov	a, @r0
      000CFB 12 2B E5         [24] 2650 	lcall	___fslt
      000CFE AB 82            [24] 2651 	mov	r3, dpl
      000D00 E5 81            [12] 2652 	mov	a,sp
      000D02 24 FC            [12] 2653 	add	a,#0xfc
      000D04 F5 81            [12] 2654 	mov	sp,a
      000D06 D0 04            [24] 2655 	pop	ar4
      000D08 D0 05            [24] 2656 	pop	ar5
      000D0A D0 06            [24] 2657 	pop	ar6
      000D0C D0 07            [24] 2658 	pop	ar7
      000D0E EB               [12] 2659 	mov	a,r3
      000D0F 70 03            [24] 2660 	jnz	00166$
      000D11 02 0D 9B         [24] 2661 	ljmp	00102$
      000D14                       2662 00166$:
      000D14 C0 07            [24] 2663 	push	ar7
      000D16 C0 06            [24] 2664 	push	ar6
      000D18 C0 05            [24] 2665 	push	ar5
      000D1A C0 04            [24] 2666 	push	ar4
      000D1C C0 07            [24] 2667 	push	ar7
      000D1E C0 06            [24] 2668 	push	ar6
      000D20 C0 05            [24] 2669 	push	ar5
      000D22 C0 04            [24] 2670 	push	ar4
      000D24 E5 10            [12] 2671 	mov	a,_bp
      000D26 24 EE            [12] 2672 	add	a,#0xee
      000D28 F8               [12] 2673 	mov	r0,a
      000D29 86 82            [24] 2674 	mov	dpl, @r0
      000D2B 08               [12] 2675 	inc	r0
      000D2C 86 83            [24] 2676 	mov	dph, @r0
      000D2E 08               [12] 2677 	inc	r0
      000D2F 86 F0            [24] 2678 	mov	b, @r0
      000D31 08               [12] 2679 	inc	r0
      000D32 E6               [12] 2680 	mov	a, @r0
      000D33 12 2A AA         [24] 2681 	lcall	___fssub
      000D36 C8               [12] 2682 	xch	a,r0
      000D37 E5 10            [12] 2683 	mov	a,_bp
      000D39 24 05            [12] 2684 	add	a,#0x05
      000D3B C8               [12] 2685 	xch	a,r0
      000D3C A6 82            [24] 2686 	mov	@r0, dpl
      000D3E 08               [12] 2687 	inc	r0
      000D3F A6 83            [24] 2688 	mov	@r0, dph
      000D41 08               [12] 2689 	inc	r0
      000D42 A6 F0            [24] 2690 	mov	@r0, b
      000D44 08               [12] 2691 	inc	r0
      000D45 F6               [12] 2692 	mov	@r0,a
      000D46 E5 81            [12] 2693 	mov	a,sp
      000D48 24 FC            [12] 2694 	add	a,#0xfc
      000D4A F5 81            [12] 2695 	mov	sp,a
      000D4C E5 10            [12] 2696 	mov	a,_bp
      000D4E 24 FA            [12] 2697 	add	a,#0xfa
      000D50 F8               [12] 2698 	mov	r0,a
      000D51 86 82            [24] 2699 	mov	dpl, @r0
      000D53 08               [12] 2700 	inc	r0
      000D54 86 83            [24] 2701 	mov	dph, @r0
      000D56 08               [12] 2702 	inc	r0
      000D57 86 F0            [24] 2703 	mov	b, @r0
      000D59 08               [12] 2704 	inc	r0
      000D5A E6               [12] 2705 	mov	a, @r0
      000D5B 12 2A AA         [24] 2706 	lcall	___fssub
      000D5E AC 82            [24] 2707 	mov	r4, dpl
      000D60 AD 83            [24] 2708 	mov	r5, dph
      000D62 AE F0            [24] 2709 	mov	r6, b
      000D64 FF               [12] 2710 	mov	r7, a
      000D65 E5 81            [12] 2711 	mov	a,sp
      000D67 24 FC            [12] 2712 	add	a,#0xfc
      000D69 F5 81            [12] 2713 	mov	sp,a
      000D6B C0 04            [24] 2714 	push	ar4
      000D6D C0 05            [24] 2715 	push	ar5
      000D6F C0 06            [24] 2716 	push	ar6
      000D71 C0 07            [24] 2717 	push	ar7
      000D73 E5 10            [12] 2718 	mov	a,_bp
      000D75 24 05            [12] 2719 	add	a,#0x05
      000D77 F8               [12] 2720 	mov	r0,a
      000D78 86 82            [24] 2721 	mov	dpl, @r0
      000D7A 08               [12] 2722 	inc	r0
      000D7B 86 83            [24] 2723 	mov	dph, @r0
      000D7D 08               [12] 2724 	inc	r0
      000D7E 86 F0            [24] 2725 	mov	b, @r0
      000D80 08               [12] 2726 	inc	r0
      000D81 E6               [12] 2727 	mov	a, @r0
      000D82 12 2D 2C         [24] 2728 	lcall	___fsdiv
      000D85 A8 10            [24] 2729 	mov	r0,_bp
      000D87 08               [12] 2730 	inc	r0
      000D88 A6 82            [24] 2731 	mov	@r0, dpl
      000D8A 08               [12] 2732 	inc	r0
      000D8B A6 83            [24] 2733 	mov	@r0, dph
      000D8D 08               [12] 2734 	inc	r0
      000D8E A6 F0            [24] 2735 	mov	@r0, b
      000D90 08               [12] 2736 	inc	r0
      000D91 F6               [12] 2737 	mov	@r0,a
      000D92 E5 81            [12] 2738 	mov	a,sp
      000D94 24 FC            [12] 2739 	add	a,#0xfc
      000D96 F5 81            [12] 2740 	mov	sp,a
      000D98 02 0E 37         [24] 2741 	ljmp	00110$
      000D9B                       2742 00102$:
      000D9B E5 10            [12] 2743 	mov	a,_bp
      000D9D 24 EE            [12] 2744 	add	a,#0xee
      000D9F F8               [12] 2745 	mov	r0,a
      000DA0 E6               [12] 2746 	mov	a,@r0
      000DA1 C0 E0            [24] 2747 	push	acc
      000DA3 08               [12] 2748 	inc	r0
      000DA4 E6               [12] 2749 	mov	a,@r0
      000DA5 C0 E0            [24] 2750 	push	acc
      000DA7 08               [12] 2751 	inc	r0
      000DA8 E6               [12] 2752 	mov	a,@r0
      000DA9 C0 E0            [24] 2753 	push	acc
      000DAB 08               [12] 2754 	inc	r0
      000DAC E6               [12] 2755 	mov	a,@r0
      000DAD C0 E0            [24] 2756 	push	acc
      000DAF E5 10            [12] 2757 	mov	a,_bp
      000DB1 24 F2            [12] 2758 	add	a,#0xf2
      000DB3 F8               [12] 2759 	mov	r0,a
      000DB4 86 82            [24] 2760 	mov	dpl, @r0
      000DB6 08               [12] 2761 	inc	r0
      000DB7 86 83            [24] 2762 	mov	dph, @r0
      000DB9 08               [12] 2763 	inc	r0
      000DBA 86 F0            [24] 2764 	mov	b, @r0
      000DBC 08               [12] 2765 	inc	r0
      000DBD E6               [12] 2766 	mov	a, @r0
      000DBE 12 2A AA         [24] 2767 	lcall	___fssub
      000DC1 C8               [12] 2768 	xch	a,r0
      000DC2 E5 10            [12] 2769 	mov	a,_bp
      000DC4 24 05            [12] 2770 	add	a,#0x05
      000DC6 C8               [12] 2771 	xch	a,r0
      000DC7 A6 82            [24] 2772 	mov	@r0, dpl
      000DC9 08               [12] 2773 	inc	r0
      000DCA A6 83            [24] 2774 	mov	@r0, dph
      000DCC 08               [12] 2775 	inc	r0
      000DCD A6 F0            [24] 2776 	mov	@r0, b
      000DCF 08               [12] 2777 	inc	r0
      000DD0 F6               [12] 2778 	mov	@r0,a
      000DD1 E5 81            [12] 2779 	mov	a,sp
      000DD3 24 FC            [12] 2780 	add	a,#0xfc
      000DD5 F5 81            [12] 2781 	mov	sp,a
      000DD7 E5 10            [12] 2782 	mov	a,_bp
      000DD9 24 F6            [12] 2783 	add	a,#0xf6
      000DDB F8               [12] 2784 	mov	r0,a
      000DDC E6               [12] 2785 	mov	a,@r0
      000DDD C0 E0            [24] 2786 	push	acc
      000DDF 08               [12] 2787 	inc	r0
      000DE0 E6               [12] 2788 	mov	a,@r0
      000DE1 C0 E0            [24] 2789 	push	acc
      000DE3 08               [12] 2790 	inc	r0
      000DE4 E6               [12] 2791 	mov	a,@r0
      000DE5 C0 E0            [24] 2792 	push	acc
      000DE7 08               [12] 2793 	inc	r0
      000DE8 E6               [12] 2794 	mov	a,@r0
      000DE9 C0 E0            [24] 2795 	push	acc
      000DEB E5 10            [12] 2796 	mov	a,_bp
      000DED 24 F2            [12] 2797 	add	a,#0xf2
      000DEF F8               [12] 2798 	mov	r0,a
      000DF0 86 82            [24] 2799 	mov	dpl, @r0
      000DF2 08               [12] 2800 	inc	r0
      000DF3 86 83            [24] 2801 	mov	dph, @r0
      000DF5 08               [12] 2802 	inc	r0
      000DF6 86 F0            [24] 2803 	mov	b, @r0
      000DF8 08               [12] 2804 	inc	r0
      000DF9 E6               [12] 2805 	mov	a, @r0
      000DFA 12 2A AA         [24] 2806 	lcall	___fssub
      000DFD AA 82            [24] 2807 	mov	r2, dpl
      000DFF AB 83            [24] 2808 	mov	r3, dph
      000E01 AE F0            [24] 2809 	mov	r6, b
      000E03 FF               [12] 2810 	mov	r7, a
      000E04 E5 81            [12] 2811 	mov	a,sp
      000E06 24 FC            [12] 2812 	add	a,#0xfc
      000E08 F5 81            [12] 2813 	mov	sp,a
      000E0A C0 02            [24] 2814 	push	ar2
      000E0C C0 03            [24] 2815 	push	ar3
      000E0E C0 06            [24] 2816 	push	ar6
      000E10 C0 07            [24] 2817 	push	ar7
      000E12 E5 10            [12] 2818 	mov	a,_bp
      000E14 24 05            [12] 2819 	add	a,#0x05
      000E16 F8               [12] 2820 	mov	r0,a
      000E17 86 82            [24] 2821 	mov	dpl, @r0
      000E19 08               [12] 2822 	inc	r0
      000E1A 86 83            [24] 2823 	mov	dph, @r0
      000E1C 08               [12] 2824 	inc	r0
      000E1D 86 F0            [24] 2825 	mov	b, @r0
      000E1F 08               [12] 2826 	inc	r0
      000E20 E6               [12] 2827 	mov	a, @r0
      000E21 12 2D 2C         [24] 2828 	lcall	___fsdiv
      000E24 A8 10            [24] 2829 	mov	r0,_bp
      000E26 08               [12] 2830 	inc	r0
      000E27 A6 82            [24] 2831 	mov	@r0, dpl
      000E29 08               [12] 2832 	inc	r0
      000E2A A6 83            [24] 2833 	mov	@r0, dph
      000E2C 08               [12] 2834 	inc	r0
      000E2D A6 F0            [24] 2835 	mov	@r0, b
      000E2F 08               [12] 2836 	inc	r0
      000E30 F6               [12] 2837 	mov	@r0,a
      000E31 E5 81            [12] 2838 	mov	a,sp
      000E33 24 FC            [12] 2839 	add	a,#0xfc
      000E35 F5 81            [12] 2840 	mov	sp,a
      000E37                       2841 00110$:
      000E37 E5 10            [12] 2842 	mov	a,_bp
      000E39 24 ED            [12] 2843 	add	a,#0xed
      000E3B F8               [12] 2844 	mov	r0,a
      000E3C E6               [12] 2845 	mov	a,@r0
      000E3D C0 E0            [24] 2846 	push	acc
      000E3F A8 10            [24] 2847 	mov	r0,_bp
      000E41 08               [12] 2848 	inc	r0
      000E42 86 82            [24] 2849 	mov	dpl, @r0
      000E44 08               [12] 2850 	inc	r0
      000E45 86 83            [24] 2851 	mov	dph, @r0
      000E47 08               [12] 2852 	inc	r0
      000E48 86 F0            [24] 2853 	mov	b, @r0
      000E4A 08               [12] 2854 	inc	r0
      000E4B E6               [12] 2855 	mov	a, @r0
      000E4C 12 04 FA         [24] 2856 	lcall	_fuzzy_8051_hedge
      000E4F AC 82            [24] 2857 	mov	r4, dpl
      000E51 AD 83            [24] 2858 	mov	r5, dph
      000E53 AE F0            [24] 2859 	mov	r6, b
      000E55 FF               [12] 2860 	mov	r7, a
      000E56 15 81            [12] 2861 	dec	sp
      000E58 8C 82            [24] 2862 	mov	dpl, r4
      000E5A 8D 83            [24] 2863 	mov	dph, r5
      000E5C 8E F0            [24] 2864 	mov	b, r6
      000E5E EF               [12] 2865 	mov	a, r7
      000E5F 85 10 81         [24] 2866 	mov	sp,_bp
      000E62 D0 10            [24] 2867 	pop	_bp
                           000DA7  2868 	C$fuzzy.h$71$1_0$33 ==.
                           000DA7  2869 	XG$fuzzy_trapezoid$0$0 ==.
      000E64 22               [24] 2870 	ret
                                   2871 ;------------------------------------------------------------
                                   2872 ;Allocation info for local variables in function 'fuzzy_8051_eval'
                                   2873 ;------------------------------------------------------------
                                   2874 ;x             Allocated to stack - _bp -6 +4 
                                   2875 ;v             Allocated to stack - _bp +1 +3 
                                   2876 ;sloc0         Allocated to stack - _bp +4 +1 
                                   2877 ;sloc1         Allocated to stack - _bp +5 +1 
                                   2878 ;sloc2         Allocated to stack - _bp +5 +4 
                                   2879 ;sloc3         Allocated to stack - _bp +9 +4 
                                   2880 ;sloc4         Allocated to stack - _bp +13 +4 
                                   2881 ;sloc5         Allocated to stack - _bp +17 +4 
                                   2882 ;------------------------------------------------------------
                           000DA8  2883 	Fsugeno_demo$fuzzy_8051_eval$0$0 ==.
                           000DA8  2884 	C$fuzzy.h$72$1_0$35 ==.
                                   2885 ;	../../fuzzy.h:72: static float fuzzy_8051_eval(const fuzzy_variable_8051_t *v, float x) { if (v->shape == FUZZY_SHAPE_RAMP) return fuzzy_ramp(v->parameters[0], v->parameters[1], x, v->parameters[2] != 0.0f, v->hedge); if (v->shape == FUZZY_SHAPE_TRIANGLE) return fuzzy_triangle(v->parameters[0], v->parameters[1], v->parameters[2], x, v->hedge); if (v->shape == FUZZY_SHAPE_TRAPEZOID) return fuzzy_trapezoid(v->parameters[0], v->parameters[1], v->parameters[2], v->parameters[3], x, v->hedge); return 0.0f; }
                                   2886 ;	-----------------------------------------
                                   2887 ;	 function fuzzy_8051_eval
                                   2888 ;	-----------------------------------------
      000E65                       2889 _fuzzy_8051_eval:
      000E65 C0 10            [24] 2890 	push	_bp
      000E67 85 81 10         [24] 2891 	mov	_bp,sp
      000E6A C0 82            [24] 2892 	push	dpl
      000E6C C0 83            [24] 2893 	push	dph
      000E6E C0 F0            [24] 2894 	push	b
      000E70 E5 81            [12] 2895 	mov	a,sp
      000E72 24 11            [12] 2896 	add	a,#0x11
      000E74 F5 81            [12] 2897 	mov	sp,a
      000E76 A8 10            [24] 2898 	mov	r0,_bp
      000E78 08               [12] 2899 	inc	r0
      000E79 86 02            [24] 2900 	mov	ar2,@r0
      000E7B 08               [12] 2901 	inc	r0
      000E7C 86 03            [24] 2902 	mov	ar3,@r0
      000E7E 08               [12] 2903 	inc	r0
      000E7F 86 04            [24] 2904 	mov	ar4,@r0
      000E81 8A 82            [24] 2905 	mov	dpl,r2
      000E83 8B 83            [24] 2906 	mov	dph,r3
      000E85 8C F0            [24] 2907 	mov	b,r4
      000E87 12 2D EF         [24] 2908 	lcall	__gptrget
      000E8A FC               [12] 2909 	mov	r4,a
      000E8B 60 03            [24] 2910 	jz	00127$
      000E8D 02 0F 95         [24] 2911 	ljmp	00102$
      000E90                       2912 00127$:
      000E90 A8 10            [24] 2913 	mov	r0,_bp
      000E92 08               [12] 2914 	inc	r0
      000E93 74 01            [12] 2915 	mov	a,#0x01
      000E95 26               [12] 2916 	add	a, @r0
      000E96 FA               [12] 2917 	mov	r2,a
      000E97 E4               [12] 2918 	clr	a
      000E98 08               [12] 2919 	inc	r0
      000E99 36               [12] 2920 	addc	a, @r0
      000E9A FB               [12] 2921 	mov	r3,a
      000E9B 08               [12] 2922 	inc	r0
      000E9C 86 07            [24] 2923 	mov	ar7,@r0
      000E9E 8A 82            [24] 2924 	mov	dpl,r2
      000EA0 8B 83            [24] 2925 	mov	dph,r3
      000EA2 8F F0            [24] 2926 	mov	b,r7
      000EA4 12 2D EF         [24] 2927 	lcall	__gptrget
      000EA7 FC               [12] 2928 	mov	r4,a
      000EA8 A8 10            [24] 2929 	mov	r0,_bp
      000EAA 08               [12] 2930 	inc	r0
      000EAB 74 0A            [12] 2931 	mov	a,#0x0a
      000EAD 26               [12] 2932 	add	a, @r0
      000EAE FD               [12] 2933 	mov	r5,a
      000EAF E4               [12] 2934 	clr	a
      000EB0 08               [12] 2935 	inc	r0
      000EB1 36               [12] 2936 	addc	a, @r0
      000EB2 FE               [12] 2937 	mov	r6,a
      000EB3 08               [12] 2938 	inc	r0
      000EB4 86 07            [24] 2939 	mov	ar7,@r0
      000EB6 8D 82            [24] 2940 	mov	dpl,r5
      000EB8 8E 83            [24] 2941 	mov	dph,r6
      000EBA 8F F0            [24] 2942 	mov	b,r7
      000EBC 12 2D EF         [24] 2943 	lcall	__gptrget
      000EBF FD               [12] 2944 	mov	r5,a
      000EC0 A3               [24] 2945 	inc	dptr
      000EC1 12 2D EF         [24] 2946 	lcall	__gptrget
      000EC4 FE               [12] 2947 	mov	r6,a
      000EC5 A3               [24] 2948 	inc	dptr
      000EC6 12 2D EF         [24] 2949 	lcall	__gptrget
      000EC9 FF               [12] 2950 	mov	r7,a
      000ECA A3               [24] 2951 	inc	dptr
      000ECB 12 2D EF         [24] 2952 	lcall	__gptrget
      000ECE FB               [12] 2953 	mov	r3,a
      000ECF 8D F0            [24] 2954 	mov	b,r5
      000ED1 EE               [12] 2955 	mov	a,r6
      000ED2 42 F0            [12] 2956 	orl	b,a
      000ED4 EF               [12] 2957 	mov	a,r7
      000ED5 42 F0            [12] 2958 	orl	b,a
      000ED7 EB               [12] 2959 	mov	a,r3
      000ED8 54 7F            [12] 2960 	anl	a,#0x7F
      000EDA 45 F0            [12] 2961 	orl	a,b
      000EDC B4 01 00         [24] 2962 	cjne	a,#0x01,00128$
      000EDF                       2963 00128$:
      000EDF B3               [12] 2964 	cpl	c
      000EE0 92 00            [24] 2965 	mov	b0,c
      000EE2 E5 10            [12] 2966 	mov	a,_bp
      000EE4 24 04            [12] 2967 	add	a,#0x04
      000EE6 F8               [12] 2968 	mov	r0,a
      000EE7 A2 00            [12] 2969 	mov	c,b0
      000EE9 E4               [12] 2970 	clr	a
      000EEA 33               [12] 2971 	rlc	a
      000EEB F6               [12] 2972 	mov	@r0,a
      000EEC A8 10            [24] 2973 	mov	r0,_bp
      000EEE 08               [12] 2974 	inc	r0
      000EEF 74 06            [12] 2975 	mov	a,#0x06
      000EF1 26               [12] 2976 	add	a, @r0
      000EF2 FB               [12] 2977 	mov	r3,a
      000EF3 E4               [12] 2978 	clr	a
      000EF4 08               [12] 2979 	inc	r0
      000EF5 36               [12] 2980 	addc	a, @r0
      000EF6 FD               [12] 2981 	mov	r5,a
      000EF7 08               [12] 2982 	inc	r0
      000EF8 86 06            [24] 2983 	mov	ar6,@r0
      000EFA 8B 82            [24] 2984 	mov	dpl,r3
      000EFC 8D 83            [24] 2985 	mov	dph,r5
      000EFE 8E F0            [24] 2986 	mov	b,r6
      000F00 E5 10            [12] 2987 	mov	a,_bp
      000F02 24 05            [12] 2988 	add	a,#0x05
      000F04 F8               [12] 2989 	mov	r0,a
      000F05 12 2D EF         [24] 2990 	lcall	__gptrget
      000F08 F6               [12] 2991 	mov	@r0,a
      000F09 A3               [24] 2992 	inc	dptr
      000F0A 12 2D EF         [24] 2993 	lcall	__gptrget
      000F0D 08               [12] 2994 	inc	r0
      000F0E F6               [12] 2995 	mov	@r0,a
      000F0F A3               [24] 2996 	inc	dptr
      000F10 12 2D EF         [24] 2997 	lcall	__gptrget
      000F13 08               [12] 2998 	inc	r0
      000F14 F6               [12] 2999 	mov	@r0,a
      000F15 A3               [24] 3000 	inc	dptr
      000F16 12 2D EF         [24] 3001 	lcall	__gptrget
      000F19 08               [12] 3002 	inc	r0
      000F1A F6               [12] 3003 	mov	@r0,a
      000F1B A8 10            [24] 3004 	mov	r0,_bp
      000F1D 08               [12] 3005 	inc	r0
      000F1E 74 02            [12] 3006 	mov	a,#0x02
      000F20 26               [12] 3007 	add	a, @r0
      000F21 FA               [12] 3008 	mov	r2,a
      000F22 E4               [12] 3009 	clr	a
      000F23 08               [12] 3010 	inc	r0
      000F24 36               [12] 3011 	addc	a, @r0
      000F25 FE               [12] 3012 	mov	r6,a
      000F26 08               [12] 3013 	inc	r0
      000F27 86 07            [24] 3014 	mov	ar7,@r0
      000F29 8A 82            [24] 3015 	mov	dpl,r2
      000F2B 8E 83            [24] 3016 	mov	dph,r6
      000F2D 8F F0            [24] 3017 	mov	b,r7
      000F2F 12 2D EF         [24] 3018 	lcall	__gptrget
      000F32 FA               [12] 3019 	mov	r2,a
      000F33 A3               [24] 3020 	inc	dptr
      000F34 12 2D EF         [24] 3021 	lcall	__gptrget
      000F37 FE               [12] 3022 	mov	r6,a
      000F38 A3               [24] 3023 	inc	dptr
      000F39 12 2D EF         [24] 3024 	lcall	__gptrget
      000F3C FF               [12] 3025 	mov	r7,a
      000F3D A3               [24] 3026 	inc	dptr
      000F3E 12 2D EF         [24] 3027 	lcall	__gptrget
      000F41 FD               [12] 3028 	mov	r5,a
      000F42 C0 04            [24] 3029 	push	ar4
      000F44 E5 10            [12] 3030 	mov	a,_bp
      000F46 24 04            [12] 3031 	add	a,#0x04
      000F48 F8               [12] 3032 	mov	r0,a
      000F49 E6               [12] 3033 	mov	a,@r0
      000F4A C0 E0            [24] 3034 	push	acc
      000F4C E5 10            [12] 3035 	mov	a,_bp
      000F4E 24 FA            [12] 3036 	add	a,#0xfa
      000F50 F8               [12] 3037 	mov	r0,a
      000F51 E6               [12] 3038 	mov	a,@r0
      000F52 C0 E0            [24] 3039 	push	acc
      000F54 08               [12] 3040 	inc	r0
      000F55 E6               [12] 3041 	mov	a,@r0
      000F56 C0 E0            [24] 3042 	push	acc
      000F58 08               [12] 3043 	inc	r0
      000F59 E6               [12] 3044 	mov	a,@r0
      000F5A C0 E0            [24] 3045 	push	acc
      000F5C 08               [12] 3046 	inc	r0
      000F5D E6               [12] 3047 	mov	a,@r0
      000F5E C0 E0            [24] 3048 	push	acc
      000F60 E5 10            [12] 3049 	mov	a,_bp
      000F62 24 05            [12] 3050 	add	a,#0x05
      000F64 F8               [12] 3051 	mov	r0,a
      000F65 E6               [12] 3052 	mov	a,@r0
      000F66 C0 E0            [24] 3053 	push	acc
      000F68 08               [12] 3054 	inc	r0
      000F69 E6               [12] 3055 	mov	a,@r0
      000F6A C0 E0            [24] 3056 	push	acc
      000F6C 08               [12] 3057 	inc	r0
      000F6D E6               [12] 3058 	mov	a,@r0
      000F6E C0 E0            [24] 3059 	push	acc
      000F70 08               [12] 3060 	inc	r0
      000F71 E6               [12] 3061 	mov	a,@r0
      000F72 C0 E0            [24] 3062 	push	acc
      000F74 8A 82            [24] 3063 	mov	dpl, r2
      000F76 8E 83            [24] 3064 	mov	dph, r6
      000F78 8F F0            [24] 3065 	mov	b, r7
      000F7A ED               [12] 3066 	mov	a, r5
      000F7B 12 05 B6         [24] 3067 	lcall	_fuzzy_ramp
      000F7E AB 82            [24] 3068 	mov	r3, dpl
      000F80 AD 83            [24] 3069 	mov	r5, dph
      000F82 AE F0            [24] 3070 	mov	r6, b
      000F84 FF               [12] 3071 	mov	r7, a
      000F85 E5 81            [12] 3072 	mov	a,sp
      000F87 24 F6            [12] 3073 	add	a,#0xf6
      000F89 F5 81            [12] 3074 	mov	sp,a
      000F8B 8B 82            [24] 3075 	mov	dpl, r3
      000F8D 8D 83            [24] 3076 	mov	dph, r5
      000F8F 8E F0            [24] 3077 	mov	b, r6
      000F91 EF               [12] 3078 	mov	a, r7
      000F92 02 11 F0         [24] 3079 	ljmp	00107$
      000F95                       3080 00102$:
      000F95 BC 01 02         [24] 3081 	cjne	r4,#0x01,00129$
      000F98 80 03            [24] 3082 	sjmp	00130$
      000F9A                       3083 00129$:
      000F9A 02 10 99         [24] 3084 	ljmp	00104$
      000F9D                       3085 00130$:
      000F9D A8 10            [24] 3086 	mov	r0,_bp
      000F9F 08               [12] 3087 	inc	r0
      000FA0 74 01            [12] 3088 	mov	a,#0x01
      000FA2 26               [12] 3089 	add	a, @r0
      000FA3 FD               [12] 3090 	mov	r5,a
      000FA4 E4               [12] 3091 	clr	a
      000FA5 08               [12] 3092 	inc	r0
      000FA6 36               [12] 3093 	addc	a, @r0
      000FA7 FE               [12] 3094 	mov	r6,a
      000FA8 08               [12] 3095 	inc	r0
      000FA9 86 07            [24] 3096 	mov	ar7,@r0
      000FAB 8D 82            [24] 3097 	mov	dpl,r5
      000FAD 8E 83            [24] 3098 	mov	dph,r6
      000FAF 8F F0            [24] 3099 	mov	b,r7
      000FB1 12 2D EF         [24] 3100 	lcall	__gptrget
      000FB4 FC               [12] 3101 	mov	r4,a
      000FB5 A8 10            [24] 3102 	mov	r0,_bp
      000FB7 08               [12] 3103 	inc	r0
      000FB8 74 0A            [12] 3104 	mov	a,#0x0a
      000FBA 26               [12] 3105 	add	a, @r0
      000FBB FB               [12] 3106 	mov	r3,a
      000FBC E4               [12] 3107 	clr	a
      000FBD 08               [12] 3108 	inc	r0
      000FBE 36               [12] 3109 	addc	a, @r0
      000FBF FE               [12] 3110 	mov	r6,a
      000FC0 08               [12] 3111 	inc	r0
      000FC1 86 07            [24] 3112 	mov	ar7,@r0
      000FC3 8B 82            [24] 3113 	mov	dpl,r3
      000FC5 8E 83            [24] 3114 	mov	dph,r6
      000FC7 8F F0            [24] 3115 	mov	b,r7
      000FC9 E5 10            [12] 3116 	mov	a,_bp
      000FCB 24 09            [12] 3117 	add	a,#0x09
      000FCD F8               [12] 3118 	mov	r0,a
      000FCE 12 2D EF         [24] 3119 	lcall	__gptrget
      000FD1 F6               [12] 3120 	mov	@r0,a
      000FD2 A3               [24] 3121 	inc	dptr
      000FD3 12 2D EF         [24] 3122 	lcall	__gptrget
      000FD6 08               [12] 3123 	inc	r0
      000FD7 F6               [12] 3124 	mov	@r0,a
      000FD8 A3               [24] 3125 	inc	dptr
      000FD9 12 2D EF         [24] 3126 	lcall	__gptrget
      000FDC 08               [12] 3127 	inc	r0
      000FDD F6               [12] 3128 	mov	@r0,a
      000FDE A3               [24] 3129 	inc	dptr
      000FDF 12 2D EF         [24] 3130 	lcall	__gptrget
      000FE2 08               [12] 3131 	inc	r0
      000FE3 F6               [12] 3132 	mov	@r0,a
      000FE4 A8 10            [24] 3133 	mov	r0,_bp
      000FE6 08               [12] 3134 	inc	r0
      000FE7 74 06            [12] 3135 	mov	a,#0x06
      000FE9 26               [12] 3136 	add	a, @r0
      000FEA FD               [12] 3137 	mov	r5,a
      000FEB E4               [12] 3138 	clr	a
      000FEC 08               [12] 3139 	inc	r0
      000FED 36               [12] 3140 	addc	a, @r0
      000FEE FE               [12] 3141 	mov	r6,a
      000FEF 08               [12] 3142 	inc	r0
      000FF0 86 07            [24] 3143 	mov	ar7,@r0
      000FF2 8D 82            [24] 3144 	mov	dpl,r5
      000FF4 8E 83            [24] 3145 	mov	dph,r6
      000FF6 8F F0            [24] 3146 	mov	b,r7
      000FF8 E5 10            [12] 3147 	mov	a,_bp
      000FFA 24 0D            [12] 3148 	add	a,#0x0d
      000FFC F8               [12] 3149 	mov	r0,a
      000FFD 12 2D EF         [24] 3150 	lcall	__gptrget
      001000 F6               [12] 3151 	mov	@r0,a
      001001 A3               [24] 3152 	inc	dptr
      001002 12 2D EF         [24] 3153 	lcall	__gptrget
      001005 08               [12] 3154 	inc	r0
      001006 F6               [12] 3155 	mov	@r0,a
      001007 A3               [24] 3156 	inc	dptr
      001008 12 2D EF         [24] 3157 	lcall	__gptrget
      00100B 08               [12] 3158 	inc	r0
      00100C F6               [12] 3159 	mov	@r0,a
      00100D A3               [24] 3160 	inc	dptr
      00100E 12 2D EF         [24] 3161 	lcall	__gptrget
      001011 08               [12] 3162 	inc	r0
      001012 F6               [12] 3163 	mov	@r0,a
      001013 A8 10            [24] 3164 	mov	r0,_bp
      001015 08               [12] 3165 	inc	r0
      001016 74 02            [12] 3166 	mov	a,#0x02
      001018 26               [12] 3167 	add	a, @r0
      001019 FA               [12] 3168 	mov	r2,a
      00101A E4               [12] 3169 	clr	a
      00101B 08               [12] 3170 	inc	r0
      00101C 36               [12] 3171 	addc	a, @r0
      00101D FE               [12] 3172 	mov	r6,a
      00101E 08               [12] 3173 	inc	r0
      00101F 86 07            [24] 3174 	mov	ar7,@r0
      001021 8A 82            [24] 3175 	mov	dpl,r2
      001023 8E 83            [24] 3176 	mov	dph,r6
      001025 8F F0            [24] 3177 	mov	b,r7
      001027 12 2D EF         [24] 3178 	lcall	__gptrget
      00102A FA               [12] 3179 	mov	r2,a
      00102B A3               [24] 3180 	inc	dptr
      00102C 12 2D EF         [24] 3181 	lcall	__gptrget
      00102F FE               [12] 3182 	mov	r6,a
      001030 A3               [24] 3183 	inc	dptr
      001031 12 2D EF         [24] 3184 	lcall	__gptrget
      001034 FF               [12] 3185 	mov	r7,a
      001035 A3               [24] 3186 	inc	dptr
      001036 12 2D EF         [24] 3187 	lcall	__gptrget
      001039 FD               [12] 3188 	mov	r5,a
      00103A C0 04            [24] 3189 	push	ar4
      00103C E5 10            [12] 3190 	mov	a,_bp
      00103E 24 FA            [12] 3191 	add	a,#0xfa
      001040 F8               [12] 3192 	mov	r0,a
      001041 E6               [12] 3193 	mov	a,@r0
      001042 C0 E0            [24] 3194 	push	acc
      001044 08               [12] 3195 	inc	r0
      001045 E6               [12] 3196 	mov	a,@r0
      001046 C0 E0            [24] 3197 	push	acc
      001048 08               [12] 3198 	inc	r0
      001049 E6               [12] 3199 	mov	a,@r0
      00104A C0 E0            [24] 3200 	push	acc
      00104C 08               [12] 3201 	inc	r0
      00104D E6               [12] 3202 	mov	a,@r0
      00104E C0 E0            [24] 3203 	push	acc
      001050 E5 10            [12] 3204 	mov	a,_bp
      001052 24 09            [12] 3205 	add	a,#0x09
      001054 F8               [12] 3206 	mov	r0,a
      001055 E6               [12] 3207 	mov	a,@r0
      001056 C0 E0            [24] 3208 	push	acc
      001058 08               [12] 3209 	inc	r0
      001059 E6               [12] 3210 	mov	a,@r0
      00105A C0 E0            [24] 3211 	push	acc
      00105C 08               [12] 3212 	inc	r0
      00105D E6               [12] 3213 	mov	a,@r0
      00105E C0 E0            [24] 3214 	push	acc
      001060 08               [12] 3215 	inc	r0
      001061 E6               [12] 3216 	mov	a,@r0
      001062 C0 E0            [24] 3217 	push	acc
      001064 E5 10            [12] 3218 	mov	a,_bp
      001066 24 0D            [12] 3219 	add	a,#0x0d
      001068 F8               [12] 3220 	mov	r0,a
      001069 E6               [12] 3221 	mov	a,@r0
      00106A C0 E0            [24] 3222 	push	acc
      00106C 08               [12] 3223 	inc	r0
      00106D E6               [12] 3224 	mov	a,@r0
      00106E C0 E0            [24] 3225 	push	acc
      001070 08               [12] 3226 	inc	r0
      001071 E6               [12] 3227 	mov	a,@r0
      001072 C0 E0            [24] 3228 	push	acc
      001074 08               [12] 3229 	inc	r0
      001075 E6               [12] 3230 	mov	a,@r0
      001076 C0 E0            [24] 3231 	push	acc
      001078 8A 82            [24] 3232 	mov	dpl, r2
      00107A 8E 83            [24] 3233 	mov	dph, r6
      00107C 8F F0            [24] 3234 	mov	b, r7
      00107E ED               [12] 3235 	mov	a, r5
      00107F 12 07 C2         [24] 3236 	lcall	_fuzzy_triangle
      001082 AB 82            [24] 3237 	mov	r3, dpl
      001084 AD 83            [24] 3238 	mov	r5, dph
      001086 AE F0            [24] 3239 	mov	r6, b
      001088 FF               [12] 3240 	mov	r7, a
      001089 E5 81            [12] 3241 	mov	a,sp
      00108B 24 F3            [12] 3242 	add	a,#0xf3
      00108D F5 81            [12] 3243 	mov	sp,a
      00108F 8B 82            [24] 3244 	mov	dpl, r3
      001091 8D 83            [24] 3245 	mov	dph, r5
      001093 8E F0            [24] 3246 	mov	b, r6
      001095 EF               [12] 3247 	mov	a, r7
      001096 02 11 F0         [24] 3248 	ljmp	00107$
      001099                       3249 00104$:
      001099 BC 02 02         [24] 3250 	cjne	r4,#0x02,00131$
      00109C 80 03            [24] 3251 	sjmp	00132$
      00109E                       3252 00131$:
      00109E 02 11 EA         [24] 3253 	ljmp	00106$
      0010A1                       3254 00132$:
      0010A1 A8 10            [24] 3255 	mov	r0,_bp
      0010A3 08               [12] 3256 	inc	r0
      0010A4 74 01            [12] 3257 	mov	a,#0x01
      0010A6 26               [12] 3258 	add	a, @r0
      0010A7 FD               [12] 3259 	mov	r5,a
      0010A8 E4               [12] 3260 	clr	a
      0010A9 08               [12] 3261 	inc	r0
      0010AA 36               [12] 3262 	addc	a, @r0
      0010AB FE               [12] 3263 	mov	r6,a
      0010AC 08               [12] 3264 	inc	r0
      0010AD 86 07            [24] 3265 	mov	ar7,@r0
      0010AF 8D 82            [24] 3266 	mov	dpl,r5
      0010B1 8E 83            [24] 3267 	mov	dph,r6
      0010B3 8F F0            [24] 3268 	mov	b,r7
      0010B5 E5 10            [12] 3269 	mov	a,_bp
      0010B7 24 0D            [12] 3270 	add	a,#0x0d
      0010B9 F8               [12] 3271 	mov	r0,a
      0010BA 12 2D EF         [24] 3272 	lcall	__gptrget
      0010BD F6               [12] 3273 	mov	@r0,a
      0010BE A8 10            [24] 3274 	mov	r0,_bp
      0010C0 08               [12] 3275 	inc	r0
      0010C1 74 0E            [12] 3276 	mov	a,#0x0e
      0010C3 26               [12] 3277 	add	a, @r0
      0010C4 FC               [12] 3278 	mov	r4,a
      0010C5 E4               [12] 3279 	clr	a
      0010C6 08               [12] 3280 	inc	r0
      0010C7 36               [12] 3281 	addc	a, @r0
      0010C8 FE               [12] 3282 	mov	r6,a
      0010C9 08               [12] 3283 	inc	r0
      0010CA 86 07            [24] 3284 	mov	ar7,@r0
      0010CC 8C 82            [24] 3285 	mov	dpl,r4
      0010CE 8E 83            [24] 3286 	mov	dph,r6
      0010D0 8F F0            [24] 3287 	mov	b,r7
      0010D2 E5 10            [12] 3288 	mov	a,_bp
      0010D4 24 09            [12] 3289 	add	a,#0x09
      0010D6 F8               [12] 3290 	mov	r0,a
      0010D7 12 2D EF         [24] 3291 	lcall	__gptrget
      0010DA F6               [12] 3292 	mov	@r0,a
      0010DB A3               [24] 3293 	inc	dptr
      0010DC 12 2D EF         [24] 3294 	lcall	__gptrget
      0010DF 08               [12] 3295 	inc	r0
      0010E0 F6               [12] 3296 	mov	@r0,a
      0010E1 A3               [24] 3297 	inc	dptr
      0010E2 12 2D EF         [24] 3298 	lcall	__gptrget
      0010E5 08               [12] 3299 	inc	r0
      0010E6 F6               [12] 3300 	mov	@r0,a
      0010E7 A3               [24] 3301 	inc	dptr
      0010E8 12 2D EF         [24] 3302 	lcall	__gptrget
      0010EB 08               [12] 3303 	inc	r0
      0010EC F6               [12] 3304 	mov	@r0,a
      0010ED A8 10            [24] 3305 	mov	r0,_bp
      0010EF 08               [12] 3306 	inc	r0
      0010F0 74 0A            [12] 3307 	mov	a,#0x0a
      0010F2 26               [12] 3308 	add	a, @r0
      0010F3 FA               [12] 3309 	mov	r2,a
      0010F4 E4               [12] 3310 	clr	a
      0010F5 08               [12] 3311 	inc	r0
      0010F6 36               [12] 3312 	addc	a, @r0
      0010F7 FD               [12] 3313 	mov	r5,a
      0010F8 08               [12] 3314 	inc	r0
      0010F9 86 07            [24] 3315 	mov	ar7,@r0
      0010FB 8A 82            [24] 3316 	mov	dpl,r2
      0010FD 8D 83            [24] 3317 	mov	dph,r5
      0010FF 8F F0            [24] 3318 	mov	b,r7
      001101 E5 10            [12] 3319 	mov	a,_bp
      001103 24 05            [12] 3320 	add	a,#0x05
      001105 F8               [12] 3321 	mov	r0,a
      001106 12 2D EF         [24] 3322 	lcall	__gptrget
      001109 F6               [12] 3323 	mov	@r0,a
      00110A A3               [24] 3324 	inc	dptr
      00110B 12 2D EF         [24] 3325 	lcall	__gptrget
      00110E 08               [12] 3326 	inc	r0
      00110F F6               [12] 3327 	mov	@r0,a
      001110 A3               [24] 3328 	inc	dptr
      001111 12 2D EF         [24] 3329 	lcall	__gptrget
      001114 08               [12] 3330 	inc	r0
      001115 F6               [12] 3331 	mov	@r0,a
      001116 A3               [24] 3332 	inc	dptr
      001117 12 2D EF         [24] 3333 	lcall	__gptrget
      00111A 08               [12] 3334 	inc	r0
      00111B F6               [12] 3335 	mov	@r0,a
      00111C A8 10            [24] 3336 	mov	r0,_bp
      00111E 08               [12] 3337 	inc	r0
      00111F 74 06            [12] 3338 	mov	a,#0x06
      001121 26               [12] 3339 	add	a, @r0
      001122 FB               [12] 3340 	mov	r3,a
      001123 E4               [12] 3341 	clr	a
      001124 08               [12] 3342 	inc	r0
      001125 36               [12] 3343 	addc	a, @r0
      001126 FC               [12] 3344 	mov	r4,a
      001127 08               [12] 3345 	inc	r0
      001128 86 07            [24] 3346 	mov	ar7,@r0
      00112A 8B 82            [24] 3347 	mov	dpl,r3
      00112C 8C 83            [24] 3348 	mov	dph,r4
      00112E 8F F0            [24] 3349 	mov	b,r7
      001130 E5 10            [12] 3350 	mov	a,_bp
      001132 24 11            [12] 3351 	add	a,#0x11
      001134 F8               [12] 3352 	mov	r0,a
      001135 12 2D EF         [24] 3353 	lcall	__gptrget
      001138 F6               [12] 3354 	mov	@r0,a
      001139 A3               [24] 3355 	inc	dptr
      00113A 12 2D EF         [24] 3356 	lcall	__gptrget
      00113D 08               [12] 3357 	inc	r0
      00113E F6               [12] 3358 	mov	@r0,a
      00113F A3               [24] 3359 	inc	dptr
      001140 12 2D EF         [24] 3360 	lcall	__gptrget
      001143 08               [12] 3361 	inc	r0
      001144 F6               [12] 3362 	mov	@r0,a
      001145 A3               [24] 3363 	inc	dptr
      001146 12 2D EF         [24] 3364 	lcall	__gptrget
      001149 08               [12] 3365 	inc	r0
      00114A F6               [12] 3366 	mov	@r0,a
      00114B A8 10            [24] 3367 	mov	r0,_bp
      00114D 08               [12] 3368 	inc	r0
      00114E 74 02            [12] 3369 	mov	a,#0x02
      001150 26               [12] 3370 	add	a, @r0
      001151 FA               [12] 3371 	mov	r2,a
      001152 E4               [12] 3372 	clr	a
      001153 08               [12] 3373 	inc	r0
      001154 36               [12] 3374 	addc	a, @r0
      001155 FD               [12] 3375 	mov	r5,a
      001156 08               [12] 3376 	inc	r0
      001157 86 07            [24] 3377 	mov	ar7,@r0
      001159 8A 82            [24] 3378 	mov	dpl,r2
      00115B 8D 83            [24] 3379 	mov	dph,r5
      00115D 8F F0            [24] 3380 	mov	b,r7
      00115F 12 2D EF         [24] 3381 	lcall	__gptrget
      001162 FA               [12] 3382 	mov	r2,a
      001163 A3               [24] 3383 	inc	dptr
      001164 12 2D EF         [24] 3384 	lcall	__gptrget
      001167 FD               [12] 3385 	mov	r5,a
      001168 A3               [24] 3386 	inc	dptr
      001169 12 2D EF         [24] 3387 	lcall	__gptrget
      00116C FF               [12] 3388 	mov	r7,a
      00116D A3               [24] 3389 	inc	dptr
      00116E 12 2D EF         [24] 3390 	lcall	__gptrget
      001171 FE               [12] 3391 	mov	r6,a
      001172 E5 10            [12] 3392 	mov	a,_bp
      001174 24 0D            [12] 3393 	add	a,#0x0d
      001176 F8               [12] 3394 	mov	r0,a
      001177 E6               [12] 3395 	mov	a,@r0
      001178 C0 E0            [24] 3396 	push	acc
      00117A E5 10            [12] 3397 	mov	a,_bp
      00117C 24 FA            [12] 3398 	add	a,#0xfa
      00117E F8               [12] 3399 	mov	r0,a
      00117F E6               [12] 3400 	mov	a,@r0
      001180 C0 E0            [24] 3401 	push	acc
      001182 08               [12] 3402 	inc	r0
      001183 E6               [12] 3403 	mov	a,@r0
      001184 C0 E0            [24] 3404 	push	acc
      001186 08               [12] 3405 	inc	r0
      001187 E6               [12] 3406 	mov	a,@r0
      001188 C0 E0            [24] 3407 	push	acc
      00118A 08               [12] 3408 	inc	r0
      00118B E6               [12] 3409 	mov	a,@r0
      00118C C0 E0            [24] 3410 	push	acc
      00118E E5 10            [12] 3411 	mov	a,_bp
      001190 24 09            [12] 3412 	add	a,#0x09
      001192 F8               [12] 3413 	mov	r0,a
      001193 E6               [12] 3414 	mov	a,@r0
      001194 C0 E0            [24] 3415 	push	acc
      001196 08               [12] 3416 	inc	r0
      001197 E6               [12] 3417 	mov	a,@r0
      001198 C0 E0            [24] 3418 	push	acc
      00119A 08               [12] 3419 	inc	r0
      00119B E6               [12] 3420 	mov	a,@r0
      00119C C0 E0            [24] 3421 	push	acc
      00119E 08               [12] 3422 	inc	r0
      00119F E6               [12] 3423 	mov	a,@r0
      0011A0 C0 E0            [24] 3424 	push	acc
      0011A2 E5 10            [12] 3425 	mov	a,_bp
      0011A4 24 05            [12] 3426 	add	a,#0x05
      0011A6 F8               [12] 3427 	mov	r0,a
      0011A7 E6               [12] 3428 	mov	a,@r0
      0011A8 C0 E0            [24] 3429 	push	acc
      0011AA 08               [12] 3430 	inc	r0
      0011AB E6               [12] 3431 	mov	a,@r0
      0011AC C0 E0            [24] 3432 	push	acc
      0011AE 08               [12] 3433 	inc	r0
      0011AF E6               [12] 3434 	mov	a,@r0
      0011B0 C0 E0            [24] 3435 	push	acc
      0011B2 08               [12] 3436 	inc	r0
      0011B3 E6               [12] 3437 	mov	a,@r0
      0011B4 C0 E0            [24] 3438 	push	acc
      0011B6 E5 10            [12] 3439 	mov	a,_bp
      0011B8 24 11            [12] 3440 	add	a,#0x11
      0011BA F8               [12] 3441 	mov	r0,a
      0011BB E6               [12] 3442 	mov	a,@r0
      0011BC C0 E0            [24] 3443 	push	acc
      0011BE 08               [12] 3444 	inc	r0
      0011BF E6               [12] 3445 	mov	a,@r0
      0011C0 C0 E0            [24] 3446 	push	acc
      0011C2 08               [12] 3447 	inc	r0
      0011C3 E6               [12] 3448 	mov	a,@r0
      0011C4 C0 E0            [24] 3449 	push	acc
      0011C6 08               [12] 3450 	inc	r0
      0011C7 E6               [12] 3451 	mov	a,@r0
      0011C8 C0 E0            [24] 3452 	push	acc
      0011CA 8A 82            [24] 3453 	mov	dpl, r2
      0011CC 8D 83            [24] 3454 	mov	dph, r5
      0011CE 8F F0            [24] 3455 	mov	b, r7
      0011D0 EE               [12] 3456 	mov	a, r6
      0011D1 12 0A CE         [24] 3457 	lcall	_fuzzy_trapezoid
      0011D4 AC 82            [24] 3458 	mov	r4, dpl
      0011D6 AD 83            [24] 3459 	mov	r5, dph
      0011D8 AE F0            [24] 3460 	mov	r6, b
      0011DA FF               [12] 3461 	mov	r7, a
      0011DB E5 81            [12] 3462 	mov	a,sp
      0011DD 24 EF            [12] 3463 	add	a,#0xef
      0011DF F5 81            [12] 3464 	mov	sp,a
      0011E1 8C 82            [24] 3465 	mov	dpl, r4
      0011E3 8D 83            [24] 3466 	mov	dph, r5
      0011E5 8E F0            [24] 3467 	mov	b, r6
      0011E7 EF               [12] 3468 	mov	a, r7
      0011E8 80 06            [24] 3469 	sjmp	00107$
      0011EA                       3470 00106$:
      0011EA 90 00 00         [24] 3471 	mov	dptr,#0x0000
      0011ED E4               [12] 3472 	clr	a
      0011EE F5 F0            [12] 3473 	mov	b,a
      0011F0                       3474 00107$:
      0011F0 85 10 81         [24] 3475 	mov	sp,_bp
      0011F3 D0 10            [24] 3476 	pop	_bp
                           001138  3477 	C$fuzzy.h$72$1_0$35 ==.
                           001138  3478 	XFsugeno_demo$fuzzy_8051_eval$0$0 ==.
      0011F5 22               [24] 3479 	ret
                                   3480 ;------------------------------------------------------------
                                   3481 ;Allocation info for local variables in function 'fuzzy_rules_add_8051'
                                   3482 ;------------------------------------------------------------
                                   3483 ;value         Allocated to stack - _bp -6 +4 
                                   3484 ;output        Allocated to stack - _bp -9 +3 
                                   3485 ;rules         Allocated to stack - _bp +1 +3 
                                   3486 ;index         Allocated to registers r3 
                                   3487 ;sloc0         Allocated to stack - _bp +5 +1 
                                   3488 ;sloc1         Allocated to stack - _bp +4 +3 
                                   3489 ;sloc2         Allocated to stack - _bp +7 +3 
                                   3490 ;------------------------------------------------------------
                           001139  3491 	G$fuzzy_rules_add_8051$0$0 ==.
                           001139  3492 	C$fuzzy.h$73$1_0$37 ==.
                                   3493 ;	../../fuzzy.h:73: bool fuzzy_rules_add_8051(fuzzy_rules_t *rules, float value, const fuzzy_variable_8051_t *output) { uint8_t index; if (rules->count >= FUZZY_MAX_RULES) return false; index = rules->count; rules->rules[index].value = fuzzy_8051_clamp(value); rules->rules[index].output = output; rules->count = index + 1u; return true; }
                                   3494 ;	-----------------------------------------
                                   3495 ;	 function fuzzy_rules_add_8051
                                   3496 ;	-----------------------------------------
      0011F6                       3497 _fuzzy_rules_add_8051:
      0011F6 C0 10            [24] 3498 	push	_bp
      0011F8 85 81 10         [24] 3499 	mov	_bp,sp
      0011FB C0 82            [24] 3500 	push	dpl
      0011FD C0 83            [24] 3501 	push	dph
      0011FF C0 F0            [24] 3502 	push	b
      001201 E5 81            [12] 3503 	mov	a,sp
      001203 24 06            [12] 3504 	add	a,#0x06
      001205 F5 81            [12] 3505 	mov	sp,a
      001207 A8 10            [24] 3506 	mov	r0,_bp
      001209 08               [12] 3507 	inc	r0
      00120A E5 10            [12] 3508 	mov	a,_bp
      00120C 24 07            [12] 3509 	add	a,#0x07
      00120E F9               [12] 3510 	mov	r1,a
      00120F 74 70            [12] 3511 	mov	a,#0x70
      001211 26               [12] 3512 	add	a, @r0
      001212 F7               [12] 3513 	mov	@r1,a
      001213 E4               [12] 3514 	clr	a
      001214 08               [12] 3515 	inc	r0
      001215 36               [12] 3516 	addc	a, @r0
      001216 09               [12] 3517 	inc	r1
      001217 F7               [12] 3518 	mov	@r1,a
      001218 08               [12] 3519 	inc	r0
      001219 E6               [12] 3520 	mov	a,@r0
      00121A 09               [12] 3521 	inc	r1
      00121B F7               [12] 3522 	mov	@r1,a
      00121C E5 10            [12] 3523 	mov	a,_bp
      00121E 24 07            [12] 3524 	add	a,#0x07
      001220 F8               [12] 3525 	mov	r0,a
      001221 86 82            [24] 3526 	mov	dpl,@r0
      001223 08               [12] 3527 	inc	r0
      001224 86 83            [24] 3528 	mov	dph,@r0
      001226 08               [12] 3529 	inc	r0
      001227 86 F0            [24] 3530 	mov	b,@r0
      001229 12 2D EF         [24] 3531 	lcall	__gptrget
      00122C FF               [12] 3532 	mov	r7,a
      00122D BF 10 00         [24] 3533 	cjne	r7,#0x10,00111$
      001230                       3534 00111$:
      001230 40 06            [24] 3535 	jc	00102$
      001232 75 82 00         [24] 3536 	mov	dpl, #0x00
      001235 02 12 DB         [24] 3537 	ljmp	00103$
      001238                       3538 00102$:
      001238 8F 03            [24] 3539 	mov	ar3,r7
      00123A EB               [12] 3540 	mov	a,r3
      00123B 75 F0 07         [24] 3541 	mov	b,#0x07
      00123E A4               [48] 3542 	mul	ab
      00123F FA               [12] 3543 	mov	r2,a
      001240 A8 10            [24] 3544 	mov	r0,_bp
      001242 08               [12] 3545 	inc	r0
      001243 E5 10            [12] 3546 	mov	a,_bp
      001245 24 04            [12] 3547 	add	a,#0x04
      001247 F9               [12] 3548 	mov	r1,a
      001248 EA               [12] 3549 	mov	a,r2
      001249 26               [12] 3550 	add	a, @r0
      00124A F7               [12] 3551 	mov	@r1,a
      00124B E4               [12] 3552 	clr	a
      00124C 08               [12] 3553 	inc	r0
      00124D 36               [12] 3554 	addc	a, @r0
      00124E 09               [12] 3555 	inc	r1
      00124F F7               [12] 3556 	mov	@r1,a
      001250 08               [12] 3557 	inc	r0
      001251 E6               [12] 3558 	mov	a,@r0
      001252 09               [12] 3559 	inc	r1
      001253 F7               [12] 3560 	mov	@r1,a
      001254 E5 10            [12] 3561 	mov	a,_bp
      001256 24 FA            [12] 3562 	add	a,#0xfa
      001258 F8               [12] 3563 	mov	r0,a
      001259 86 82            [24] 3564 	mov	dpl, @r0
      00125B 08               [12] 3565 	inc	r0
      00125C 86 83            [24] 3566 	mov	dph, @r0
      00125E 08               [12] 3567 	inc	r0
      00125F 86 F0            [24] 3568 	mov	b, @r0
      001261 08               [12] 3569 	inc	r0
      001262 E6               [12] 3570 	mov	a, @r0
      001263 C0 03            [24] 3571 	push	ar3
      001265 C0 02            [24] 3572 	push	ar2
      001267 12 04 7D         [24] 3573 	lcall	_fuzzy_8051_clamp
      00126A AD 82            [24] 3574 	mov	r5, dpl
      00126C AE 83            [24] 3575 	mov	r6, dph
      00126E AC F0            [24] 3576 	mov	r4, b
      001270 FF               [12] 3577 	mov	r7, a
      001271 D0 02            [24] 3578 	pop	ar2
      001273 D0 03            [24] 3579 	pop	ar3
      001275 E5 10            [12] 3580 	mov	a,_bp
      001277 24 04            [12] 3581 	add	a,#0x04
      001279 F8               [12] 3582 	mov	r0,a
      00127A 86 82            [24] 3583 	mov	dpl,@r0
      00127C 08               [12] 3584 	inc	r0
      00127D 86 83            [24] 3585 	mov	dph,@r0
      00127F 08               [12] 3586 	inc	r0
      001280 86 F0            [24] 3587 	mov	b,@r0
      001282 ED               [12] 3588 	mov	a,r5
      001283 12 2B CA         [24] 3589 	lcall	__gptrput
      001286 A3               [24] 3590 	inc	dptr
      001287 EE               [12] 3591 	mov	a,r6
      001288 12 2B CA         [24] 3592 	lcall	__gptrput
      00128B A3               [24] 3593 	inc	dptr
      00128C EC               [12] 3594 	mov	a,r4
      00128D 12 2B CA         [24] 3595 	lcall	__gptrput
      001290 A3               [24] 3596 	inc	dptr
      001291 EF               [12] 3597 	mov	a,r7
      001292 12 2B CA         [24] 3598 	lcall	__gptrput
      001295 A8 10            [24] 3599 	mov	r0,_bp
      001297 08               [12] 3600 	inc	r0
      001298 EA               [12] 3601 	mov	a,r2
      001299 26               [12] 3602 	add	a, @r0
      00129A FD               [12] 3603 	mov	r5,a
      00129B E4               [12] 3604 	clr	a
      00129C 08               [12] 3605 	inc	r0
      00129D 36               [12] 3606 	addc	a, @r0
      00129E FE               [12] 3607 	mov	r6,a
      00129F 08               [12] 3608 	inc	r0
      0012A0 86 07            [24] 3609 	mov	ar7,@r0
      0012A2 74 04            [12] 3610 	mov	a,#0x04
      0012A4 2D               [12] 3611 	add	a, r5
      0012A5 FD               [12] 3612 	mov	r5,a
      0012A6 E4               [12] 3613 	clr	a
      0012A7 3E               [12] 3614 	addc	a, r6
      0012A8 FE               [12] 3615 	mov	r6,a
      0012A9 8D 82            [24] 3616 	mov	dpl,r5
      0012AB 8E 83            [24] 3617 	mov	dph,r6
      0012AD 8F F0            [24] 3618 	mov	b,r7
      0012AF E5 10            [12] 3619 	mov	a,_bp
      0012B1 24 F7            [12] 3620 	add	a,#0xf7
      0012B3 F8               [12] 3621 	mov	r0,a
      0012B4 E6               [12] 3622 	mov	a,@r0
      0012B5 12 2B CA         [24] 3623 	lcall	__gptrput
      0012B8 A3               [24] 3624 	inc	dptr
      0012B9 08               [12] 3625 	inc	r0
      0012BA E6               [12] 3626 	mov	a,@r0
      0012BB 12 2B CA         [24] 3627 	lcall	__gptrput
      0012BE A3               [24] 3628 	inc	dptr
      0012BF 08               [12] 3629 	inc	r0
      0012C0 E6               [12] 3630 	mov	a,@r0
      0012C1 12 2B CA         [24] 3631 	lcall	__gptrput
      0012C4 EB               [12] 3632 	mov	a,r3
      0012C5 04               [12] 3633 	inc	a
      0012C6 FF               [12] 3634 	mov	r7,a
      0012C7 E5 10            [12] 3635 	mov	a,_bp
      0012C9 24 07            [12] 3636 	add	a,#0x07
      0012CB F8               [12] 3637 	mov	r0,a
      0012CC 86 82            [24] 3638 	mov	dpl,@r0
      0012CE 08               [12] 3639 	inc	r0
      0012CF 86 83            [24] 3640 	mov	dph,@r0
      0012D1 08               [12] 3641 	inc	r0
      0012D2 86 F0            [24] 3642 	mov	b,@r0
      0012D4 EF               [12] 3643 	mov	a,r7
      0012D5 12 2B CA         [24] 3644 	lcall	__gptrput
      0012D8 75 82 01         [24] 3645 	mov	dpl, #0x01
      0012DB                       3646 00103$:
      0012DB 85 10 81         [24] 3647 	mov	sp,_bp
      0012DE D0 10            [24] 3648 	pop	_bp
                           001223  3649 	C$fuzzy.h$73$1_0$37 ==.
                           001223  3650 	XG$fuzzy_rules_add_8051$0$0 ==.
      0012E0 22               [24] 3651 	ret
                                   3652 ;------------------------------------------------------------
                                   3653 ;Allocation info for local variables in function 'fuzzy_8051_height'
                                   3654 ;------------------------------------------------------------
                                   3655 ;x             Allocated to stack - _bp -6 +4 
                                   3656 ;rules         Allocated to stack - _bp +1 +3 
                                   3657 ;i             Allocated to registers r7 
                                   3658 ;aggregate     Allocated to stack - _bp +14 +4 
                                   3659 ;membership    Allocated to stack - _bp +18 +4 
                                   3660 ;implied       Allocated to registers r3 r4 r5 r6 
                                   3661 ;sloc0         Allocated to stack - _bp +4 +3 
                                   3662 ;sloc1         Allocated to stack - _bp +7 +3 
                                   3663 ;sloc2         Allocated to stack - _bp +10 +4 
                                   3664 ;------------------------------------------------------------
                           001224  3665 	Fsugeno_demo$fuzzy_8051_height$0$0 ==.
                           001224  3666 	C$fuzzy.h$74$1_0$39 ==.
                                   3667 ;	../../fuzzy.h:74: static float fuzzy_8051_height(const fuzzy_rules_t *rules, float x) { uint8_t i; float aggregate; float membership; float implied; aggregate = 0.0f; for (i = 0u; i < rules->count; ++i) { membership = fuzzy_8051_eval(rules->rules[i].output, x); implied = rules->rules[i].value < membership ? rules->rules[i].value : membership; if (implied > aggregate) aggregate = implied; } return aggregate; }
                                   3668 ;	-----------------------------------------
                                   3669 ;	 function fuzzy_8051_height
                                   3670 ;	-----------------------------------------
      0012E1                       3671 _fuzzy_8051_height:
      0012E1 C0 10            [24] 3672 	push	_bp
      0012E3 85 81 10         [24] 3673 	mov	_bp,sp
      0012E6 C0 82            [24] 3674 	push	dpl
      0012E8 C0 83            [24] 3675 	push	dph
      0012EA C0 F0            [24] 3676 	push	b
      0012EC E5 81            [12] 3677 	mov	a,sp
      0012EE 24 12            [12] 3678 	add	a,#0x12
      0012F0 F5 81            [12] 3679 	mov	sp,a
      0012F2 E5 10            [12] 3680 	mov	a,_bp
      0012F4 24 0E            [12] 3681 	add	a,#0x0e
      0012F6 F8               [12] 3682 	mov	r0,a
      0012F7 E4               [12] 3683 	clr	a
      0012F8 F6               [12] 3684 	mov	@r0,a
      0012F9 08               [12] 3685 	inc	r0
      0012FA F6               [12] 3686 	mov	@r0,a
      0012FB 08               [12] 3687 	inc	r0
      0012FC F6               [12] 3688 	mov	@r0,a
      0012FD 08               [12] 3689 	inc	r0
      0012FE F6               [12] 3690 	mov	@r0,a
      0012FF A8 10            [24] 3691 	mov	r0,_bp
      001301 08               [12] 3692 	inc	r0
      001302 E5 10            [12] 3693 	mov	a,_bp
      001304 24 07            [12] 3694 	add	a,#0x07
      001306 F9               [12] 3695 	mov	r1,a
      001307 E6               [12] 3696 	mov	a,@r0
      001308 F7               [12] 3697 	mov	@r1,a
      001309 08               [12] 3698 	inc	r0
      00130A E6               [12] 3699 	mov	a,@r0
      00130B 09               [12] 3700 	inc	r1
      00130C F7               [12] 3701 	mov	@r1,a
      00130D 08               [12] 3702 	inc	r0
      00130E E6               [12] 3703 	mov	a,@r0
      00130F 09               [12] 3704 	inc	r1
      001310 F7               [12] 3705 	mov	@r1,a
      001311 A8 10            [24] 3706 	mov	r0,_bp
      001313 08               [12] 3707 	inc	r0
      001314 E5 10            [12] 3708 	mov	a,_bp
      001316 24 04            [12] 3709 	add	a,#0x04
      001318 F9               [12] 3710 	mov	r1,a
      001319 74 70            [12] 3711 	mov	a,#0x70
      00131B 26               [12] 3712 	add	a, @r0
      00131C F7               [12] 3713 	mov	@r1,a
      00131D E4               [12] 3714 	clr	a
      00131E 08               [12] 3715 	inc	r0
      00131F 36               [12] 3716 	addc	a, @r0
      001320 09               [12] 3717 	inc	r1
      001321 F7               [12] 3718 	mov	@r1,a
      001322 08               [12] 3719 	inc	r0
      001323 E6               [12] 3720 	mov	a,@r0
      001324 09               [12] 3721 	inc	r1
      001325 F7               [12] 3722 	mov	@r1,a
      001326 7F 00            [12] 3723 	mov	r7,#0x00
      001328                       3724 00105$:
      001328 E5 10            [12] 3725 	mov	a,_bp
      00132A 24 04            [12] 3726 	add	a,#0x04
      00132C F8               [12] 3727 	mov	r0,a
      00132D 86 82            [24] 3728 	mov	dpl,@r0
      00132F 08               [12] 3729 	inc	r0
      001330 86 83            [24] 3730 	mov	dph,@r0
      001332 08               [12] 3731 	inc	r0
      001333 86 F0            [24] 3732 	mov	b,@r0
      001335 12 2D EF         [24] 3733 	lcall	__gptrget
      001338 FE               [12] 3734 	mov	r6,a
      001339 C3               [12] 3735 	clr	c
      00133A EF               [12] 3736 	mov	a,r7
      00133B 9E               [12] 3737 	subb	a,r6
      00133C 40 03            [24] 3738 	jc	00136$
      00133E 02 14 7E         [24] 3739 	ljmp	00103$
      001341                       3740 00136$:
      001341 EF               [12] 3741 	mov	a,r7
      001342 75 F0 07         [24] 3742 	mov	b,#0x07
      001345 A4               [48] 3743 	mul	ab
      001346 FE               [12] 3744 	mov	r6,a
      001347 C0 07            [24] 3745 	push	ar7
      001349 E5 10            [12] 3746 	mov	a,_bp
      00134B 24 07            [12] 3747 	add	a,#0x07
      00134D F8               [12] 3748 	mov	r0,a
      00134E EE               [12] 3749 	mov	a,r6
      00134F 26               [12] 3750 	add	a, @r0
      001350 FC               [12] 3751 	mov	r4,a
      001351 E4               [12] 3752 	clr	a
      001352 08               [12] 3753 	inc	r0
      001353 36               [12] 3754 	addc	a, @r0
      001354 FD               [12] 3755 	mov	r5,a
      001355 08               [12] 3756 	inc	r0
      001356 86 07            [24] 3757 	mov	ar7,@r0
      001358 74 04            [12] 3758 	mov	a,#0x04
      00135A 2C               [12] 3759 	add	a, r4
      00135B FC               [12] 3760 	mov	r4,a
      00135C E4               [12] 3761 	clr	a
      00135D 3D               [12] 3762 	addc	a, r5
      00135E FD               [12] 3763 	mov	r5,a
      00135F 8C 82            [24] 3764 	mov	dpl,r4
      001361 8D 83            [24] 3765 	mov	dph,r5
      001363 8F F0            [24] 3766 	mov	b,r7
      001365 12 2D EF         [24] 3767 	lcall	__gptrget
      001368 FC               [12] 3768 	mov	r4,a
      001369 A3               [24] 3769 	inc	dptr
      00136A 12 2D EF         [24] 3770 	lcall	__gptrget
      00136D FD               [12] 3771 	mov	r5,a
      00136E A3               [24] 3772 	inc	dptr
      00136F 12 2D EF         [24] 3773 	lcall	__gptrget
      001372 FF               [12] 3774 	mov	r7,a
      001373 C0 07            [24] 3775 	push	ar7
      001375 C0 06            [24] 3776 	push	ar6
      001377 E5 10            [12] 3777 	mov	a,_bp
      001379 24 FA            [12] 3778 	add	a,#0xfa
      00137B F8               [12] 3779 	mov	r0,a
      00137C E6               [12] 3780 	mov	a,@r0
      00137D C0 E0            [24] 3781 	push	acc
      00137F 08               [12] 3782 	inc	r0
      001380 E6               [12] 3783 	mov	a,@r0
      001381 C0 E0            [24] 3784 	push	acc
      001383 08               [12] 3785 	inc	r0
      001384 E6               [12] 3786 	mov	a,@r0
      001385 C0 E0            [24] 3787 	push	acc
      001387 08               [12] 3788 	inc	r0
      001388 E6               [12] 3789 	mov	a,@r0
      001389 C0 E0            [24] 3790 	push	acc
      00138B 8C 82            [24] 3791 	mov	dpl, r4
      00138D 8D 83            [24] 3792 	mov	dph, r5
      00138F 8F F0            [24] 3793 	mov	b, r7
      001391 12 0E 65         [24] 3794 	lcall	_fuzzy_8051_eval
      001394 C8               [12] 3795 	xch	a,r0
      001395 E5 10            [12] 3796 	mov	a,_bp
      001397 24 12            [12] 3797 	add	a,#0x12
      001399 C8               [12] 3798 	xch	a,r0
      00139A A6 82            [24] 3799 	mov	@r0, dpl
      00139C 08               [12] 3800 	inc	r0
      00139D A6 83            [24] 3801 	mov	@r0, dph
      00139F 08               [12] 3802 	inc	r0
      0013A0 A6 F0            [24] 3803 	mov	@r0, b
      0013A2 08               [12] 3804 	inc	r0
      0013A3 F6               [12] 3805 	mov	@r0,a
      0013A4 E5 81            [12] 3806 	mov	a,sp
      0013A6 24 FC            [12] 3807 	add	a,#0xfc
      0013A8 F5 81            [12] 3808 	mov	sp,a
      0013AA D0 06            [24] 3809 	pop	ar6
      0013AC D0 07            [24] 3810 	pop	ar7
      0013AE A8 10            [24] 3811 	mov	r0,_bp
      0013B0 08               [12] 3812 	inc	r0
      0013B1 EE               [12] 3813 	mov	a,r6
      0013B2 26               [12] 3814 	add	a, @r0
      0013B3 FE               [12] 3815 	mov	r6,a
      0013B4 E4               [12] 3816 	clr	a
      0013B5 08               [12] 3817 	inc	r0
      0013B6 36               [12] 3818 	addc	a, @r0
      0013B7 FF               [12] 3819 	mov	r7,a
      0013B8 08               [12] 3820 	inc	r0
      0013B9 86 05            [24] 3821 	mov	ar5,@r0
      0013BB 8E 82            [24] 3822 	mov	dpl,r6
      0013BD 8F 83            [24] 3823 	mov	dph,r7
      0013BF 8D F0            [24] 3824 	mov	b,r5
      0013C1 E5 10            [12] 3825 	mov	a,_bp
      0013C3 24 0A            [12] 3826 	add	a,#0x0a
      0013C5 F8               [12] 3827 	mov	r0,a
      0013C6 12 2D EF         [24] 3828 	lcall	__gptrget
      0013C9 F6               [12] 3829 	mov	@r0,a
      0013CA A3               [24] 3830 	inc	dptr
      0013CB 12 2D EF         [24] 3831 	lcall	__gptrget
      0013CE 08               [12] 3832 	inc	r0
      0013CF F6               [12] 3833 	mov	@r0,a
      0013D0 A3               [24] 3834 	inc	dptr
      0013D1 12 2D EF         [24] 3835 	lcall	__gptrget
      0013D4 08               [12] 3836 	inc	r0
      0013D5 F6               [12] 3837 	mov	@r0,a
      0013D6 A3               [24] 3838 	inc	dptr
      0013D7 12 2D EF         [24] 3839 	lcall	__gptrget
      0013DA 08               [12] 3840 	inc	r0
      0013DB F6               [12] 3841 	mov	@r0,a
      0013DC E5 10            [12] 3842 	mov	a,_bp
      0013DE 24 12            [12] 3843 	add	a,#0x12
      0013E0 F8               [12] 3844 	mov	r0,a
      0013E1 E6               [12] 3845 	mov	a,@r0
      0013E2 C0 E0            [24] 3846 	push	acc
      0013E4 08               [12] 3847 	inc	r0
      0013E5 E6               [12] 3848 	mov	a,@r0
      0013E6 C0 E0            [24] 3849 	push	acc
      0013E8 08               [12] 3850 	inc	r0
      0013E9 E6               [12] 3851 	mov	a,@r0
      0013EA C0 E0            [24] 3852 	push	acc
      0013EC 08               [12] 3853 	inc	r0
      0013ED E6               [12] 3854 	mov	a,@r0
      0013EE C0 E0            [24] 3855 	push	acc
      0013F0 E5 10            [12] 3856 	mov	a,_bp
      0013F2 24 0A            [12] 3857 	add	a,#0x0a
      0013F4 F8               [12] 3858 	mov	r0,a
      0013F5 86 82            [24] 3859 	mov	dpl, @r0
      0013F7 08               [12] 3860 	inc	r0
      0013F8 86 83            [24] 3861 	mov	dph, @r0
      0013FA 08               [12] 3862 	inc	r0
      0013FB 86 F0            [24] 3863 	mov	b, @r0
      0013FD 08               [12] 3864 	inc	r0
      0013FE E6               [12] 3865 	mov	a, @r0
      0013FF 12 2B E5         [24] 3866 	lcall	___fslt
      001402 AF 82            [24] 3867 	mov	r7, dpl
      001404 E5 81            [12] 3868 	mov	a,sp
      001406 24 FC            [12] 3869 	add	a,#0xfc
      001408 F5 81            [12] 3870 	mov	sp,a
      00140A EF               [12] 3871 	mov	a,r7
      00140B D0 07            [24] 3872 	pop	ar7
      00140D 60 12            [24] 3873 	jz	00109$
      00140F E5 10            [12] 3874 	mov	a,_bp
      001411 24 0A            [12] 3875 	add	a,#0x0a
      001413 F8               [12] 3876 	mov	r0,a
      001414 86 03            [24] 3877 	mov	ar3,@r0
      001416 08               [12] 3878 	inc	r0
      001417 86 04            [24] 3879 	mov	ar4,@r0
      001419 08               [12] 3880 	inc	r0
      00141A 86 05            [24] 3881 	mov	ar5,@r0
      00141C 08               [12] 3882 	inc	r0
      00141D 86 06            [24] 3883 	mov	ar6,@r0
      00141F 80 10            [24] 3884 	sjmp	00110$
      001421                       3885 00109$:
      001421 E5 10            [12] 3886 	mov	a,_bp
      001423 24 12            [12] 3887 	add	a,#0x12
      001425 F8               [12] 3888 	mov	r0,a
      001426 86 03            [24] 3889 	mov	ar3,@r0
      001428 08               [12] 3890 	inc	r0
      001429 86 04            [24] 3891 	mov	ar4,@r0
      00142B 08               [12] 3892 	inc	r0
      00142C 86 05            [24] 3893 	mov	ar5,@r0
      00142E 08               [12] 3894 	inc	r0
      00142F 86 06            [24] 3895 	mov	ar6,@r0
      001431                       3896 00110$:
      001431 C0 07            [24] 3897 	push	ar7
      001433 C0 06            [24] 3898 	push	ar6
      001435 C0 05            [24] 3899 	push	ar5
      001437 C0 04            [24] 3900 	push	ar4
      001439 C0 03            [24] 3901 	push	ar3
      00143B C0 03            [24] 3902 	push	ar3
      00143D C0 04            [24] 3903 	push	ar4
      00143F C0 05            [24] 3904 	push	ar5
      001441 C0 06            [24] 3905 	push	ar6
      001443 E5 10            [12] 3906 	mov	a,_bp
      001445 24 0E            [12] 3907 	add	a,#0x0e
      001447 F8               [12] 3908 	mov	r0,a
      001448 86 82            [24] 3909 	mov	dpl, @r0
      00144A 08               [12] 3910 	inc	r0
      00144B 86 83            [24] 3911 	mov	dph, @r0
      00144D 08               [12] 3912 	inc	r0
      00144E 86 F0            [24] 3913 	mov	b, @r0
      001450 08               [12] 3914 	inc	r0
      001451 E6               [12] 3915 	mov	a, @r0
      001452 12 2B E5         [24] 3916 	lcall	___fslt
      001455 AA 82            [24] 3917 	mov	r2, dpl
      001457 E5 81            [12] 3918 	mov	a,sp
      001459 24 FC            [12] 3919 	add	a,#0xfc
      00145B F5 81            [12] 3920 	mov	sp,a
      00145D D0 03            [24] 3921 	pop	ar3
      00145F D0 04            [24] 3922 	pop	ar4
      001461 D0 05            [24] 3923 	pop	ar5
      001463 D0 06            [24] 3924 	pop	ar6
      001465 D0 07            [24] 3925 	pop	ar7
      001467 EA               [12] 3926 	mov	a,r2
      001468 60 10            [24] 3927 	jz	00106$
      00146A E5 10            [12] 3928 	mov	a,_bp
      00146C 24 0E            [12] 3929 	add	a,#0x0e
      00146E F8               [12] 3930 	mov	r0,a
      00146F A6 03            [24] 3931 	mov	@r0,ar3
      001471 08               [12] 3932 	inc	r0
      001472 A6 04            [24] 3933 	mov	@r0,ar4
      001474 08               [12] 3934 	inc	r0
      001475 A6 05            [24] 3935 	mov	@r0,ar5
      001477 08               [12] 3936 	inc	r0
      001478 A6 06            [24] 3937 	mov	@r0,ar6
      00147A                       3938 00106$:
      00147A 0F               [12] 3939 	inc	r7
      00147B 02 13 28         [24] 3940 	ljmp	00105$
      00147E                       3941 00103$:
      00147E E5 10            [12] 3942 	mov	a,_bp
      001480 24 0E            [12] 3943 	add	a,#0x0e
      001482 F8               [12] 3944 	mov	r0,a
      001483 86 82            [24] 3945 	mov	dpl, @r0
      001485 08               [12] 3946 	inc	r0
      001486 86 83            [24] 3947 	mov	dph, @r0
      001488 08               [12] 3948 	inc	r0
      001489 86 F0            [24] 3949 	mov	b, @r0
      00148B 08               [12] 3950 	inc	r0
      00148C E6               [12] 3951 	mov	a, @r0
      00148D 85 10 81         [24] 3952 	mov	sp,_bp
      001490 D0 10            [24] 3953 	pop	_bp
                           0013D5  3954 	C$fuzzy.h$74$1_0$39 ==.
                           0013D5  3955 	XFsugeno_demo$fuzzy_8051_height$0$0 ==.
      001492 22               [24] 3956 	ret
                                   3957 ;------------------------------------------------------------
                                   3958 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify'
                                   3959 ;------------------------------------------------------------
                                   3960 ;lower         Allocated to stack - _bp -6 +4 
                                   3961 ;upper         Allocated to stack - _bp -10 +4 
                                   3962 ;step          Allocated to stack - _bp -14 +4 
                                   3963 ;method        Allocated to stack - _bp -15 +1 
                                   3964 ;rules         Allocated to stack - _bp +1 +3 
                                   3965 ;x             Allocated to stack - _bp +4 +4 
                                   3966 ;h             Allocated to stack - _bp +8 +4 
                                   3967 ;weighted      Allocated to stack - _bp +12 +4 
                                   3968 ;sum           Allocated to stack - _bp +16 +4 
                                   3969 ;maximum       Allocated to stack - _bp +20 +4 
                                   3970 ;maximum_sum   Allocated to stack - _bp +24 +4 
                                   3971 ;smallest      Allocated to stack - _bp +28 +4 
                                   3972 ;largest       Allocated to stack - _bp +32 +4 
                                   3973 ;maximum_count Allocated to registers r5 r4 
                                   3974 ;------------------------------------------------------------
                           0013D6  3975 	G$fuzzy_rules_defuzzify$0$0 ==.
                           0013D6  3976 	C$fuzzy.h$75$1_0$43 ==.
                                   3977 ;	../../fuzzy.h:75: float fuzzy_rules_defuzzify(const fuzzy_rules_t *rules, float lower, float upper, float step, fuzzy_defuzz_method_t method) { float x; float h; float weighted; float sum; float maximum; float maximum_sum; float smallest; float largest; unsigned int maximum_count; if (rules->count == 0u || lower > upper || step <= 0.0f) return 0.0f; weighted = 0.0f; sum = 0.0f; maximum = -1.0f; maximum_sum = 0.0f; maximum_count = 0u; smallest = lower; largest = lower; for (x = lower; x <= upper; x += step) { h = fuzzy_8051_height(rules, x); weighted += x * h; sum += h; if (h > maximum) { maximum = h; maximum_sum = x; maximum_count = 1u; smallest = x; largest = x; } else if (h == maximum) { maximum_sum += x; ++maximum_count; largest = x; } } if (method == FUZZY_DEFUZZ_MOM) return maximum > 0.0f ? maximum_sum / (float)maximum_count : 0.0f; if (method == FUZZY_DEFUZZ_SOM) return maximum > 0.0f ? smallest : 0.0f; if (method == FUZZY_DEFUZZ_LOM) return maximum > 0.0f ? largest : 0.0f; return sum > 0.0f ? weighted / sum : 0.0f; }
                                   3978 ;	-----------------------------------------
                                   3979 ;	 function fuzzy_rules_defuzzify
                                   3980 ;	-----------------------------------------
      001493                       3981 _fuzzy_rules_defuzzify:
      001493 C0 10            [24] 3982 	push	_bp
      001495 85 81 10         [24] 3983 	mov	_bp,sp
      001498 C0 82            [24] 3984 	push	dpl
      00149A C0 83            [24] 3985 	push	dph
      00149C C0 F0            [24] 3986 	push	b
      00149E E5 81            [12] 3987 	mov	a,sp
      0014A0 24 20            [12] 3988 	add	a,#0x20
      0014A2 F5 81            [12] 3989 	mov	sp,a
      0014A4 A8 10            [24] 3990 	mov	r0,_bp
      0014A6 08               [12] 3991 	inc	r0
      0014A7 74 70            [12] 3992 	mov	a,#0x70
      0014A9 26               [12] 3993 	add	a, @r0
      0014AA FA               [12] 3994 	mov	r2,a
      0014AB E4               [12] 3995 	clr	a
      0014AC 08               [12] 3996 	inc	r0
      0014AD 36               [12] 3997 	addc	a, @r0
      0014AE FB               [12] 3998 	mov	r3,a
      0014AF 08               [12] 3999 	inc	r0
      0014B0 86 04            [24] 4000 	mov	ar4,@r0
      0014B2 8A 82            [24] 4001 	mov	dpl,r2
      0014B4 8B 83            [24] 4002 	mov	dph,r3
      0014B6 8C F0            [24] 4003 	mov	b,r4
      0014B8 12 2D EF         [24] 4004 	lcall	__gptrget
      0014BB 60 5C            [24] 4005 	jz	00101$
      0014BD E5 10            [12] 4006 	mov	a,_bp
      0014BF 24 FA            [12] 4007 	add	a,#0xfa
      0014C1 F8               [12] 4008 	mov	r0,a
      0014C2 E6               [12] 4009 	mov	a,@r0
      0014C3 C0 E0            [24] 4010 	push	acc
      0014C5 08               [12] 4011 	inc	r0
      0014C6 E6               [12] 4012 	mov	a,@r0
      0014C7 C0 E0            [24] 4013 	push	acc
      0014C9 08               [12] 4014 	inc	r0
      0014CA E6               [12] 4015 	mov	a,@r0
      0014CB C0 E0            [24] 4016 	push	acc
      0014CD 08               [12] 4017 	inc	r0
      0014CE E6               [12] 4018 	mov	a,@r0
      0014CF C0 E0            [24] 4019 	push	acc
      0014D1 E5 10            [12] 4020 	mov	a,_bp
      0014D3 24 F6            [12] 4021 	add	a,#0xf6
      0014D5 F8               [12] 4022 	mov	r0,a
      0014D6 86 82            [24] 4023 	mov	dpl, @r0
      0014D8 08               [12] 4024 	inc	r0
      0014D9 86 83            [24] 4025 	mov	dph, @r0
      0014DB 08               [12] 4026 	inc	r0
      0014DC 86 F0            [24] 4027 	mov	b, @r0
      0014DE 08               [12] 4028 	inc	r0
      0014DF E6               [12] 4029 	mov	a, @r0
      0014E0 12 2B E5         [24] 4030 	lcall	___fslt
      0014E3 AC 82            [24] 4031 	mov	r4, dpl
      0014E5 E5 81            [12] 4032 	mov	a,sp
      0014E7 24 FC            [12] 4033 	add	a,#0xfc
      0014E9 F5 81            [12] 4034 	mov	sp,a
      0014EB EC               [12] 4035 	mov	a,r4
      0014EC 70 2B            [24] 4036 	jnz	00101$
      0014EE E5 10            [12] 4037 	mov	a,_bp
      0014F0 24 F2            [12] 4038 	add	a,#0xf2
      0014F2 F8               [12] 4039 	mov	r0,a
      0014F3 E6               [12] 4040 	mov	a,@r0
      0014F4 C0 E0            [24] 4041 	push	acc
      0014F6 08               [12] 4042 	inc	r0
      0014F7 E6               [12] 4043 	mov	a,@r0
      0014F8 C0 E0            [24] 4044 	push	acc
      0014FA 08               [12] 4045 	inc	r0
      0014FB E6               [12] 4046 	mov	a,@r0
      0014FC C0 E0            [24] 4047 	push	acc
      0014FE 08               [12] 4048 	inc	r0
      0014FF E6               [12] 4049 	mov	a,@r0
      001500 C0 E0            [24] 4050 	push	acc
      001502 90 00 00         [24] 4051 	mov	dptr,#0x0000
      001505 E4               [12] 4052 	clr	a
      001506 F5 F0            [12] 4053 	mov	b,a
      001508 12 2B E5         [24] 4054 	lcall	___fslt
      00150B E5 81            [12] 4055 	mov	a,sp
      00150D 24 FC            [12] 4056 	add	a,#0xfc
      00150F F5 81            [12] 4057 	mov	sp,a
      001511 E5 82            [12] 4058 	mov	a, dpl
      001513 24 FF            [12] 4059 	add	a,#0xff
      001515 92 00            [24] 4060 	mov	b0,c
      001517 40 09            [24] 4061 	jc	00102$
      001519                       4062 00101$:
      001519 90 00 00         [24] 4063 	mov	dptr,#0x0000
      00151C E4               [12] 4064 	clr	a
      00151D F5 F0            [12] 4065 	mov	b,a
      00151F 02 19 D1         [24] 4066 	ljmp	00120$
      001522                       4067 00102$:
      001522 E5 10            [12] 4068 	mov	a,_bp
      001524 24 0C            [12] 4069 	add	a,#0x0c
      001526 F8               [12] 4070 	mov	r0,a
      001527 E4               [12] 4071 	clr	a
      001528 F6               [12] 4072 	mov	@r0,a
      001529 08               [12] 4073 	inc	r0
      00152A F6               [12] 4074 	mov	@r0,a
      00152B 08               [12] 4075 	inc	r0
      00152C F6               [12] 4076 	mov	@r0,a
      00152D 08               [12] 4077 	inc	r0
      00152E F6               [12] 4078 	mov	@r0,a
      00152F E5 10            [12] 4079 	mov	a,_bp
      001531 24 10            [12] 4080 	add	a,#0x10
      001533 F8               [12] 4081 	mov	r0,a
      001534 E4               [12] 4082 	clr	a
      001535 F6               [12] 4083 	mov	@r0,a
      001536 08               [12] 4084 	inc	r0
      001537 F6               [12] 4085 	mov	@r0,a
      001538 08               [12] 4086 	inc	r0
      001539 F6               [12] 4087 	mov	@r0,a
      00153A 08               [12] 4088 	inc	r0
      00153B F6               [12] 4089 	mov	@r0,a
      00153C E5 10            [12] 4090 	mov	a,_bp
      00153E 24 14            [12] 4091 	add	a,#0x14
      001540 F8               [12] 4092 	mov	r0,a
      001541 E4               [12] 4093 	clr	a
      001542 F6               [12] 4094 	mov	@r0,a
      001543 08               [12] 4095 	inc	r0
      001544 F6               [12] 4096 	mov	@r0,a
      001545 08               [12] 4097 	inc	r0
      001546 76 80            [12] 4098 	mov	@r0,#0x80
      001548 08               [12] 4099 	inc	r0
      001549 76 BF            [12] 4100 	mov	@r0,#0xbf
      00154B E5 10            [12] 4101 	mov	a,_bp
      00154D 24 18            [12] 4102 	add	a,#0x18
      00154F F8               [12] 4103 	mov	r0,a
      001550 E4               [12] 4104 	clr	a
      001551 F6               [12] 4105 	mov	@r0,a
      001552 08               [12] 4106 	inc	r0
      001553 F6               [12] 4107 	mov	@r0,a
      001554 08               [12] 4108 	inc	r0
      001555 F6               [12] 4109 	mov	@r0,a
      001556 08               [12] 4110 	inc	r0
      001557 F6               [12] 4111 	mov	@r0,a
      001558 FD               [12] 4112 	mov	r5,a
      001559 FC               [12] 4113 	mov	r4,a
      00155A E5 10            [12] 4114 	mov	a,_bp
      00155C 24 FA            [12] 4115 	add	a,#0xfa
      00155E F8               [12] 4116 	mov	r0,a
      00155F E5 10            [12] 4117 	mov	a,_bp
      001561 24 1C            [12] 4118 	add	a,#0x1c
      001563 F9               [12] 4119 	mov	r1,a
      001564 E6               [12] 4120 	mov	a,@r0
      001565 F7               [12] 4121 	mov	@r1,a
      001566 08               [12] 4122 	inc	r0
      001567 E6               [12] 4123 	mov	a,@r0
      001568 09               [12] 4124 	inc	r1
      001569 F7               [12] 4125 	mov	@r1,a
      00156A 08               [12] 4126 	inc	r0
      00156B E6               [12] 4127 	mov	a,@r0
      00156C 09               [12] 4128 	inc	r1
      00156D F7               [12] 4129 	mov	@r1,a
      00156E 08               [12] 4130 	inc	r0
      00156F E6               [12] 4131 	mov	a,@r0
      001570 09               [12] 4132 	inc	r1
      001571 F7               [12] 4133 	mov	@r1,a
      001572 E5 10            [12] 4134 	mov	a,_bp
      001574 24 1C            [12] 4135 	add	a,#0x1c
      001576 F8               [12] 4136 	mov	r0,a
      001577 E5 10            [12] 4137 	mov	a,_bp
      001579 24 20            [12] 4138 	add	a,#0x20
      00157B F9               [12] 4139 	mov	r1,a
      00157C E6               [12] 4140 	mov	a,@r0
      00157D F7               [12] 4141 	mov	@r1,a
      00157E 08               [12] 4142 	inc	r0
      00157F E6               [12] 4143 	mov	a,@r0
      001580 09               [12] 4144 	inc	r1
      001581 F7               [12] 4145 	mov	@r1,a
      001582 08               [12] 4146 	inc	r0
      001583 E6               [12] 4147 	mov	a,@r0
      001584 09               [12] 4148 	inc	r1
      001585 F7               [12] 4149 	mov	@r1,a
      001586 08               [12] 4150 	inc	r0
      001587 E6               [12] 4151 	mov	a,@r0
      001588 09               [12] 4152 	inc	r1
      001589 F7               [12] 4153 	mov	@r1,a
      00158A E5 10            [12] 4154 	mov	a,_bp
      00158C 24 1C            [12] 4155 	add	a,#0x1c
      00158E F8               [12] 4156 	mov	r0,a
      00158F E5 10            [12] 4157 	mov	a,_bp
      001591 24 04            [12] 4158 	add	a,#0x04
      001593 F9               [12] 4159 	mov	r1,a
      001594 E6               [12] 4160 	mov	a,@r0
      001595 F7               [12] 4161 	mov	@r1,a
      001596 08               [12] 4162 	inc	r0
      001597 E6               [12] 4163 	mov	a,@r0
      001598 09               [12] 4164 	inc	r1
      001599 F7               [12] 4165 	mov	@r1,a
      00159A 08               [12] 4166 	inc	r0
      00159B E6               [12] 4167 	mov	a,@r0
      00159C 09               [12] 4168 	inc	r1
      00159D F7               [12] 4169 	mov	@r1,a
      00159E 08               [12] 4170 	inc	r0
      00159F E6               [12] 4171 	mov	a,@r0
      0015A0 09               [12] 4172 	inc	r1
      0015A1 F7               [12] 4173 	mov	@r1,a
      0015A2                       4174 00118$:
      0015A2 C0 05            [24] 4175 	push	ar5
      0015A4 C0 04            [24] 4176 	push	ar4
      0015A6 E5 10            [12] 4177 	mov	a,_bp
      0015A8 24 04            [12] 4178 	add	a,#0x04
      0015AA F8               [12] 4179 	mov	r0,a
      0015AB E6               [12] 4180 	mov	a,@r0
      0015AC C0 E0            [24] 4181 	push	acc
      0015AE 08               [12] 4182 	inc	r0
      0015AF E6               [12] 4183 	mov	a,@r0
      0015B0 C0 E0            [24] 4184 	push	acc
      0015B2 08               [12] 4185 	inc	r0
      0015B3 E6               [12] 4186 	mov	a,@r0
      0015B4 C0 E0            [24] 4187 	push	acc
      0015B6 08               [12] 4188 	inc	r0
      0015B7 E6               [12] 4189 	mov	a,@r0
      0015B8 C0 E0            [24] 4190 	push	acc
      0015BA E5 10            [12] 4191 	mov	a,_bp
      0015BC 24 F6            [12] 4192 	add	a,#0xf6
      0015BE F8               [12] 4193 	mov	r0,a
      0015BF 86 82            [24] 4194 	mov	dpl, @r0
      0015C1 08               [12] 4195 	inc	r0
      0015C2 86 83            [24] 4196 	mov	dph, @r0
      0015C4 08               [12] 4197 	inc	r0
      0015C5 86 F0            [24] 4198 	mov	b, @r0
      0015C7 08               [12] 4199 	inc	r0
      0015C8 E6               [12] 4200 	mov	a, @r0
      0015C9 12 2B E5         [24] 4201 	lcall	___fslt
      0015CC E5 81            [12] 4202 	mov	a,sp
      0015CE 24 FC            [12] 4203 	add	a,#0xfc
      0015D0 F5 81            [12] 4204 	mov	sp,a
      0015D2 D0 04            [24] 4205 	pop	ar4
      0015D4 D0 05            [24] 4206 	pop	ar5
      0015D6 E5 82            [12] 4207 	mov	a, dpl
      0015D8 24 FF            [12] 4208 	add	a,#0xff
      0015DA 92 00            [24] 4209 	mov	b0,c
      0015DC 50 03            [24] 4210 	jnc	00211$
      0015DE 02 18 39         [24] 4211 	ljmp	00110$
      0015E1                       4212 00211$:
      0015E1 C0 05            [24] 4213 	push	ar5
      0015E3 C0 04            [24] 4214 	push	ar4
      0015E5 E5 10            [12] 4215 	mov	a,_bp
      0015E7 24 04            [12] 4216 	add	a,#0x04
      0015E9 F8               [12] 4217 	mov	r0,a
      0015EA E6               [12] 4218 	mov	a,@r0
      0015EB C0 E0            [24] 4219 	push	acc
      0015ED 08               [12] 4220 	inc	r0
      0015EE E6               [12] 4221 	mov	a,@r0
      0015EF C0 E0            [24] 4222 	push	acc
      0015F1 08               [12] 4223 	inc	r0
      0015F2 E6               [12] 4224 	mov	a,@r0
      0015F3 C0 E0            [24] 4225 	push	acc
      0015F5 08               [12] 4226 	inc	r0
      0015F6 E6               [12] 4227 	mov	a,@r0
      0015F7 C0 E0            [24] 4228 	push	acc
      0015F9 A8 10            [24] 4229 	mov	r0,_bp
      0015FB 08               [12] 4230 	inc	r0
      0015FC 86 82            [24] 4231 	mov	dpl, @r0
      0015FE 08               [12] 4232 	inc	r0
      0015FF 86 83            [24] 4233 	mov	dph, @r0
      001601 08               [12] 4234 	inc	r0
      001602 86 F0            [24] 4235 	mov	b, @r0
      001604 12 12 E1         [24] 4236 	lcall	_fuzzy_8051_height
      001607 C8               [12] 4237 	xch	a,r0
      001608 E5 10            [12] 4238 	mov	a,_bp
      00160A 24 08            [12] 4239 	add	a,#0x08
      00160C C8               [12] 4240 	xch	a,r0
      00160D A6 82            [24] 4241 	mov	@r0, dpl
      00160F 08               [12] 4242 	inc	r0
      001610 A6 83            [24] 4243 	mov	@r0, dph
      001612 08               [12] 4244 	inc	r0
      001613 A6 F0            [24] 4245 	mov	@r0, b
      001615 08               [12] 4246 	inc	r0
      001616 F6               [12] 4247 	mov	@r0,a
      001617 E5 81            [12] 4248 	mov	a,sp
      001619 24 FC            [12] 4249 	add	a,#0xfc
      00161B F5 81            [12] 4250 	mov	sp,a
      00161D E5 10            [12] 4251 	mov	a,_bp
      00161F 24 08            [12] 4252 	add	a,#0x08
      001621 F8               [12] 4253 	mov	r0,a
      001622 E6               [12] 4254 	mov	a,@r0
      001623 C0 E0            [24] 4255 	push	acc
      001625 08               [12] 4256 	inc	r0
      001626 E6               [12] 4257 	mov	a,@r0
      001627 C0 E0            [24] 4258 	push	acc
      001629 08               [12] 4259 	inc	r0
      00162A E6               [12] 4260 	mov	a,@r0
      00162B C0 E0            [24] 4261 	push	acc
      00162D 08               [12] 4262 	inc	r0
      00162E E6               [12] 4263 	mov	a,@r0
      00162F C0 E0            [24] 4264 	push	acc
      001631 E5 10            [12] 4265 	mov	a,_bp
      001633 24 04            [12] 4266 	add	a,#0x04
      001635 F8               [12] 4267 	mov	r0,a
      001636 86 82            [24] 4268 	mov	dpl, @r0
      001638 08               [12] 4269 	inc	r0
      001639 86 83            [24] 4270 	mov	dph, @r0
      00163B 08               [12] 4271 	inc	r0
      00163C 86 F0            [24] 4272 	mov	b, @r0
      00163E 08               [12] 4273 	inc	r0
      00163F E6               [12] 4274 	mov	a, @r0
      001640 12 2A B5         [24] 4275 	lcall	___fsmul
      001643 AA 82            [24] 4276 	mov	r2, dpl
      001645 AB 83            [24] 4277 	mov	r3, dph
      001647 AE F0            [24] 4278 	mov	r6, b
      001649 FF               [12] 4279 	mov	r7, a
      00164A E5 81            [12] 4280 	mov	a,sp
      00164C 24 FC            [12] 4281 	add	a,#0xfc
      00164E F5 81            [12] 4282 	mov	sp,a
      001650 C0 02            [24] 4283 	push	ar2
      001652 C0 03            [24] 4284 	push	ar3
      001654 C0 06            [24] 4285 	push	ar6
      001656 C0 07            [24] 4286 	push	ar7
      001658 E5 10            [12] 4287 	mov	a,_bp
      00165A 24 0C            [12] 4288 	add	a,#0x0c
      00165C F8               [12] 4289 	mov	r0,a
      00165D 86 82            [24] 4290 	mov	dpl, @r0
      00165F 08               [12] 4291 	inc	r0
      001660 86 83            [24] 4292 	mov	dph, @r0
      001662 08               [12] 4293 	inc	r0
      001663 86 F0            [24] 4294 	mov	b, @r0
      001665 08               [12] 4295 	inc	r0
      001666 E6               [12] 4296 	mov	a, @r0
      001667 12 2C 15         [24] 4297 	lcall	___fsadd
      00166A C8               [12] 4298 	xch	a,r0
      00166B E5 10            [12] 4299 	mov	a,_bp
      00166D 24 0C            [12] 4300 	add	a,#0x0c
      00166F C8               [12] 4301 	xch	a,r0
      001670 A6 82            [24] 4302 	mov	@r0, dpl
      001672 08               [12] 4303 	inc	r0
      001673 A6 83            [24] 4304 	mov	@r0, dph
      001675 08               [12] 4305 	inc	r0
      001676 A6 F0            [24] 4306 	mov	@r0, b
      001678 08               [12] 4307 	inc	r0
      001679 F6               [12] 4308 	mov	@r0,a
      00167A E5 81            [12] 4309 	mov	a,sp
      00167C 24 FC            [12] 4310 	add	a,#0xfc
      00167E F5 81            [12] 4311 	mov	sp,a
      001680 E5 10            [12] 4312 	mov	a,_bp
      001682 24 08            [12] 4313 	add	a,#0x08
      001684 F8               [12] 4314 	mov	r0,a
      001685 E6               [12] 4315 	mov	a,@r0
      001686 C0 E0            [24] 4316 	push	acc
      001688 08               [12] 4317 	inc	r0
      001689 E6               [12] 4318 	mov	a,@r0
      00168A C0 E0            [24] 4319 	push	acc
      00168C 08               [12] 4320 	inc	r0
      00168D E6               [12] 4321 	mov	a,@r0
      00168E C0 E0            [24] 4322 	push	acc
      001690 08               [12] 4323 	inc	r0
      001691 E6               [12] 4324 	mov	a,@r0
      001692 C0 E0            [24] 4325 	push	acc
      001694 E5 10            [12] 4326 	mov	a,_bp
      001696 24 10            [12] 4327 	add	a,#0x10
      001698 F8               [12] 4328 	mov	r0,a
      001699 86 82            [24] 4329 	mov	dpl, @r0
      00169B 08               [12] 4330 	inc	r0
      00169C 86 83            [24] 4331 	mov	dph, @r0
      00169E 08               [12] 4332 	inc	r0
      00169F 86 F0            [24] 4333 	mov	b, @r0
      0016A1 08               [12] 4334 	inc	r0
      0016A2 E6               [12] 4335 	mov	a, @r0
      0016A3 12 2C 15         [24] 4336 	lcall	___fsadd
      0016A6 C8               [12] 4337 	xch	a,r0
      0016A7 E5 10            [12] 4338 	mov	a,_bp
      0016A9 24 10            [12] 4339 	add	a,#0x10
      0016AB C8               [12] 4340 	xch	a,r0
      0016AC A6 82            [24] 4341 	mov	@r0, dpl
      0016AE 08               [12] 4342 	inc	r0
      0016AF A6 83            [24] 4343 	mov	@r0, dph
      0016B1 08               [12] 4344 	inc	r0
      0016B2 A6 F0            [24] 4345 	mov	@r0, b
      0016B4 08               [12] 4346 	inc	r0
      0016B5 F6               [12] 4347 	mov	@r0,a
      0016B6 E5 81            [12] 4348 	mov	a,sp
      0016B8 24 FC            [12] 4349 	add	a,#0xfc
      0016BA F5 81            [12] 4350 	mov	sp,a
      0016BC E5 10            [12] 4351 	mov	a,_bp
      0016BE 24 08            [12] 4352 	add	a,#0x08
      0016C0 F8               [12] 4353 	mov	r0,a
      0016C1 E6               [12] 4354 	mov	a,@r0
      0016C2 C0 E0            [24] 4355 	push	acc
      0016C4 08               [12] 4356 	inc	r0
      0016C5 E6               [12] 4357 	mov	a,@r0
      0016C6 C0 E0            [24] 4358 	push	acc
      0016C8 08               [12] 4359 	inc	r0
      0016C9 E6               [12] 4360 	mov	a,@r0
      0016CA C0 E0            [24] 4361 	push	acc
      0016CC 08               [12] 4362 	inc	r0
      0016CD E6               [12] 4363 	mov	a,@r0
      0016CE C0 E0            [24] 4364 	push	acc
      0016D0 E5 10            [12] 4365 	mov	a,_bp
      0016D2 24 14            [12] 4366 	add	a,#0x14
      0016D4 F8               [12] 4367 	mov	r0,a
      0016D5 86 82            [24] 4368 	mov	dpl, @r0
      0016D7 08               [12] 4369 	inc	r0
      0016D8 86 83            [24] 4370 	mov	dph, @r0
      0016DA 08               [12] 4371 	inc	r0
      0016DB 86 F0            [24] 4372 	mov	b, @r0
      0016DD 08               [12] 4373 	inc	r0
      0016DE E6               [12] 4374 	mov	a, @r0
      0016DF 12 2B E5         [24] 4375 	lcall	___fslt
      0016E2 AF 82            [24] 4376 	mov	r7, dpl
      0016E4 E5 81            [12] 4377 	mov	a,sp
      0016E6 24 FC            [12] 4378 	add	a,#0xfc
      0016E8 F5 81            [12] 4379 	mov	sp,a
      0016EA D0 04            [24] 4380 	pop	ar4
      0016EC D0 05            [24] 4381 	pop	ar5
      0016EE EF               [12] 4382 	mov	a,r7
      0016EF 60 67            [24] 4383 	jz	00108$
      0016F1 E5 10            [12] 4384 	mov	a,_bp
      0016F3 24 08            [12] 4385 	add	a,#0x08
      0016F5 F8               [12] 4386 	mov	r0,a
      0016F6 E5 10            [12] 4387 	mov	a,_bp
      0016F8 24 14            [12] 4388 	add	a,#0x14
      0016FA F9               [12] 4389 	mov	r1,a
      0016FB E6               [12] 4390 	mov	a,@r0
      0016FC F7               [12] 4391 	mov	@r1,a
      0016FD 08               [12] 4392 	inc	r0
      0016FE E6               [12] 4393 	mov	a,@r0
      0016FF 09               [12] 4394 	inc	r1
      001700 F7               [12] 4395 	mov	@r1,a
      001701 08               [12] 4396 	inc	r0
      001702 E6               [12] 4397 	mov	a,@r0
      001703 09               [12] 4398 	inc	r1
      001704 F7               [12] 4399 	mov	@r1,a
      001705 08               [12] 4400 	inc	r0
      001706 E6               [12] 4401 	mov	a,@r0
      001707 09               [12] 4402 	inc	r1
      001708 F7               [12] 4403 	mov	@r1,a
      001709 E5 10            [12] 4404 	mov	a,_bp
      00170B 24 04            [12] 4405 	add	a,#0x04
      00170D F8               [12] 4406 	mov	r0,a
      00170E E5 10            [12] 4407 	mov	a,_bp
      001710 24 18            [12] 4408 	add	a,#0x18
      001712 F9               [12] 4409 	mov	r1,a
      001713 E6               [12] 4410 	mov	a,@r0
      001714 F7               [12] 4411 	mov	@r1,a
      001715 08               [12] 4412 	inc	r0
      001716 E6               [12] 4413 	mov	a,@r0
      001717 09               [12] 4414 	inc	r1
      001718 F7               [12] 4415 	mov	@r1,a
      001719 08               [12] 4416 	inc	r0
      00171A E6               [12] 4417 	mov	a,@r0
      00171B 09               [12] 4418 	inc	r1
      00171C F7               [12] 4419 	mov	@r1,a
      00171D 08               [12] 4420 	inc	r0
      00171E E6               [12] 4421 	mov	a,@r0
      00171F 09               [12] 4422 	inc	r1
      001720 F7               [12] 4423 	mov	@r1,a
      001721 7D 01            [12] 4424 	mov	r5,#0x01
      001723 7C 00            [12] 4425 	mov	r4,#0x00
      001725 E5 10            [12] 4426 	mov	a,_bp
      001727 24 04            [12] 4427 	add	a,#0x04
      001729 F8               [12] 4428 	mov	r0,a
      00172A E5 10            [12] 4429 	mov	a,_bp
      00172C 24 1C            [12] 4430 	add	a,#0x1c
      00172E F9               [12] 4431 	mov	r1,a
      00172F E6               [12] 4432 	mov	a,@r0
      001730 F7               [12] 4433 	mov	@r1,a
      001731 08               [12] 4434 	inc	r0
      001732 E6               [12] 4435 	mov	a,@r0
      001733 09               [12] 4436 	inc	r1
      001734 F7               [12] 4437 	mov	@r1,a
      001735 08               [12] 4438 	inc	r0
      001736 E6               [12] 4439 	mov	a,@r0
      001737 09               [12] 4440 	inc	r1
      001738 F7               [12] 4441 	mov	@r1,a
      001739 08               [12] 4442 	inc	r0
      00173A E6               [12] 4443 	mov	a,@r0
      00173B 09               [12] 4444 	inc	r1
      00173C F7               [12] 4445 	mov	@r1,a
      00173D E5 10            [12] 4446 	mov	a,_bp
      00173F 24 04            [12] 4447 	add	a,#0x04
      001741 F8               [12] 4448 	mov	r0,a
      001742 E5 10            [12] 4449 	mov	a,_bp
      001744 24 20            [12] 4450 	add	a,#0x20
      001746 F9               [12] 4451 	mov	r1,a
      001747 E6               [12] 4452 	mov	a,@r0
      001748 F7               [12] 4453 	mov	@r1,a
      001749 08               [12] 4454 	inc	r0
      00174A E6               [12] 4455 	mov	a,@r0
      00174B 09               [12] 4456 	inc	r1
      00174C F7               [12] 4457 	mov	@r1,a
      00174D 08               [12] 4458 	inc	r0
      00174E E6               [12] 4459 	mov	a,@r0
      00174F 09               [12] 4460 	inc	r1
      001750 F7               [12] 4461 	mov	@r1,a
      001751 08               [12] 4462 	inc	r0
      001752 E6               [12] 4463 	mov	a,@r0
      001753 09               [12] 4464 	inc	r1
      001754 F7               [12] 4465 	mov	@r1,a
      001755 02 17 F2         [24] 4466 	ljmp	00119$
      001758                       4467 00108$:
      001758 C0 05            [24] 4468 	push	ar5
      00175A C0 04            [24] 4469 	push	ar4
      00175C E5 10            [12] 4470 	mov	a,_bp
      00175E 24 14            [12] 4471 	add	a,#0x14
      001760 F8               [12] 4472 	mov	r0,a
      001761 E6               [12] 4473 	mov	a,@r0
      001762 C0 E0            [24] 4474 	push	acc
      001764 08               [12] 4475 	inc	r0
      001765 E6               [12] 4476 	mov	a,@r0
      001766 C0 E0            [24] 4477 	push	acc
      001768 08               [12] 4478 	inc	r0
      001769 E6               [12] 4479 	mov	a,@r0
      00176A C0 E0            [24] 4480 	push	acc
      00176C 08               [12] 4481 	inc	r0
      00176D E6               [12] 4482 	mov	a,@r0
      00176E C0 E0            [24] 4483 	push	acc
      001770 E5 10            [12] 4484 	mov	a,_bp
      001772 24 08            [12] 4485 	add	a,#0x08
      001774 F8               [12] 4486 	mov	r0,a
      001775 86 82            [24] 4487 	mov	dpl, @r0
      001777 08               [12] 4488 	inc	r0
      001778 86 83            [24] 4489 	mov	dph, @r0
      00177A 08               [12] 4490 	inc	r0
      00177B 86 F0            [24] 4491 	mov	b, @r0
      00177D 08               [12] 4492 	inc	r0
      00177E E6               [12] 4493 	mov	a, @r0
      00177F 12 2B B9         [24] 4494 	lcall	___fseq
      001782 AF 82            [24] 4495 	mov	r7, dpl
      001784 E5 81            [12] 4496 	mov	a,sp
      001786 24 FC            [12] 4497 	add	a,#0xfc
      001788 F5 81            [12] 4498 	mov	sp,a
      00178A D0 04            [24] 4499 	pop	ar4
      00178C D0 05            [24] 4500 	pop	ar5
      00178E EF               [12] 4501 	mov	a,r7
      00178F 60 61            [24] 4502 	jz	00119$
      001791 C0 05            [24] 4503 	push	ar5
      001793 C0 04            [24] 4504 	push	ar4
      001795 E5 10            [12] 4505 	mov	a,_bp
      001797 24 04            [12] 4506 	add	a,#0x04
      001799 F8               [12] 4507 	mov	r0,a
      00179A E6               [12] 4508 	mov	a,@r0
      00179B C0 E0            [24] 4509 	push	acc
      00179D 08               [12] 4510 	inc	r0
      00179E E6               [12] 4511 	mov	a,@r0
      00179F C0 E0            [24] 4512 	push	acc
      0017A1 08               [12] 4513 	inc	r0
      0017A2 E6               [12] 4514 	mov	a,@r0
      0017A3 C0 E0            [24] 4515 	push	acc
      0017A5 08               [12] 4516 	inc	r0
      0017A6 E6               [12] 4517 	mov	a,@r0
      0017A7 C0 E0            [24] 4518 	push	acc
      0017A9 E5 10            [12] 4519 	mov	a,_bp
      0017AB 24 18            [12] 4520 	add	a,#0x18
      0017AD F8               [12] 4521 	mov	r0,a
      0017AE 86 82            [24] 4522 	mov	dpl, @r0
      0017B0 08               [12] 4523 	inc	r0
      0017B1 86 83            [24] 4524 	mov	dph, @r0
      0017B3 08               [12] 4525 	inc	r0
      0017B4 86 F0            [24] 4526 	mov	b, @r0
      0017B6 08               [12] 4527 	inc	r0
      0017B7 E6               [12] 4528 	mov	a, @r0
      0017B8 12 2C 15         [24] 4529 	lcall	___fsadd
      0017BB C8               [12] 4530 	xch	a,r0
      0017BC E5 10            [12] 4531 	mov	a,_bp
      0017BE 24 18            [12] 4532 	add	a,#0x18
      0017C0 C8               [12] 4533 	xch	a,r0
      0017C1 A6 82            [24] 4534 	mov	@r0, dpl
      0017C3 08               [12] 4535 	inc	r0
      0017C4 A6 83            [24] 4536 	mov	@r0, dph
      0017C6 08               [12] 4537 	inc	r0
      0017C7 A6 F0            [24] 4538 	mov	@r0, b
      0017C9 08               [12] 4539 	inc	r0
      0017CA F6               [12] 4540 	mov	@r0,a
      0017CB E5 81            [12] 4541 	mov	a,sp
      0017CD 24 FC            [12] 4542 	add	a,#0xfc
      0017CF F5 81            [12] 4543 	mov	sp,a
      0017D1 D0 04            [24] 4544 	pop	ar4
      0017D3 D0 05            [24] 4545 	pop	ar5
      0017D5 0D               [12] 4546 	inc	r5
      0017D6 BD 00 01         [24] 4547 	cjne	r5,#0x00,00214$
      0017D9 0C               [12] 4548 	inc	r4
      0017DA                       4549 00214$:
      0017DA E5 10            [12] 4550 	mov	a,_bp
      0017DC 24 04            [12] 4551 	add	a,#0x04
      0017DE F8               [12] 4552 	mov	r0,a
      0017DF E5 10            [12] 4553 	mov	a,_bp
      0017E1 24 20            [12] 4554 	add	a,#0x20
      0017E3 F9               [12] 4555 	mov	r1,a
      0017E4 E6               [12] 4556 	mov	a,@r0
      0017E5 F7               [12] 4557 	mov	@r1,a
      0017E6 08               [12] 4558 	inc	r0
      0017E7 E6               [12] 4559 	mov	a,@r0
      0017E8 09               [12] 4560 	inc	r1
      0017E9 F7               [12] 4561 	mov	@r1,a
      0017EA 08               [12] 4562 	inc	r0
      0017EB E6               [12] 4563 	mov	a,@r0
      0017EC 09               [12] 4564 	inc	r1
      0017ED F7               [12] 4565 	mov	@r1,a
      0017EE 08               [12] 4566 	inc	r0
      0017EF E6               [12] 4567 	mov	a,@r0
      0017F0 09               [12] 4568 	inc	r1
      0017F1 F7               [12] 4569 	mov	@r1,a
      0017F2                       4570 00119$:
      0017F2 C0 05            [24] 4571 	push	ar5
      0017F4 C0 04            [24] 4572 	push	ar4
      0017F6 E5 10            [12] 4573 	mov	a,_bp
      0017F8 24 F2            [12] 4574 	add	a,#0xf2
      0017FA F8               [12] 4575 	mov	r0,a
      0017FB E6               [12] 4576 	mov	a,@r0
      0017FC C0 E0            [24] 4577 	push	acc
      0017FE 08               [12] 4578 	inc	r0
      0017FF E6               [12] 4579 	mov	a,@r0
      001800 C0 E0            [24] 4580 	push	acc
      001802 08               [12] 4581 	inc	r0
      001803 E6               [12] 4582 	mov	a,@r0
      001804 C0 E0            [24] 4583 	push	acc
      001806 08               [12] 4584 	inc	r0
      001807 E6               [12] 4585 	mov	a,@r0
      001808 C0 E0            [24] 4586 	push	acc
      00180A E5 10            [12] 4587 	mov	a,_bp
      00180C 24 04            [12] 4588 	add	a,#0x04
      00180E F8               [12] 4589 	mov	r0,a
      00180F 86 82            [24] 4590 	mov	dpl, @r0
      001811 08               [12] 4591 	inc	r0
      001812 86 83            [24] 4592 	mov	dph, @r0
      001814 08               [12] 4593 	inc	r0
      001815 86 F0            [24] 4594 	mov	b, @r0
      001817 08               [12] 4595 	inc	r0
      001818 E6               [12] 4596 	mov	a, @r0
      001819 12 2C 15         [24] 4597 	lcall	___fsadd
      00181C C8               [12] 4598 	xch	a,r0
      00181D E5 10            [12] 4599 	mov	a,_bp
      00181F 24 04            [12] 4600 	add	a,#0x04
      001821 C8               [12] 4601 	xch	a,r0
      001822 A6 82            [24] 4602 	mov	@r0, dpl
      001824 08               [12] 4603 	inc	r0
      001825 A6 83            [24] 4604 	mov	@r0, dph
      001827 08               [12] 4605 	inc	r0
      001828 A6 F0            [24] 4606 	mov	@r0, b
      00182A 08               [12] 4607 	inc	r0
      00182B F6               [12] 4608 	mov	@r0,a
      00182C E5 81            [12] 4609 	mov	a,sp
      00182E 24 FC            [12] 4610 	add	a,#0xfc
      001830 F5 81            [12] 4611 	mov	sp,a
      001832 D0 04            [24] 4612 	pop	ar4
      001834 D0 05            [24] 4613 	pop	ar5
      001836 02 15 A2         [24] 4614 	ljmp	00118$
      001839                       4615 00110$:
      001839 E5 10            [12] 4616 	mov	a,_bp
      00183B 24 F1            [12] 4617 	add	a,#0xf1
      00183D F8               [12] 4618 	mov	r0,a
      00183E B6 03 02         [24] 4619 	cjne	@r0,#0x03,00215$
      001841 80 02            [24] 4620 	sjmp	00216$
      001843                       4621 00215$:
      001843 80 79            [24] 4622 	sjmp	00112$
      001845                       4623 00216$:
      001845 C0 05            [24] 4624 	push	ar5
      001847 C0 04            [24] 4625 	push	ar4
      001849 E5 10            [12] 4626 	mov	a,_bp
      00184B 24 14            [12] 4627 	add	a,#0x14
      00184D F8               [12] 4628 	mov	r0,a
      00184E E6               [12] 4629 	mov	a,@r0
      00184F C0 E0            [24] 4630 	push	acc
      001851 08               [12] 4631 	inc	r0
      001852 E6               [12] 4632 	mov	a,@r0
      001853 C0 E0            [24] 4633 	push	acc
      001855 08               [12] 4634 	inc	r0
      001856 E6               [12] 4635 	mov	a,@r0
      001857 C0 E0            [24] 4636 	push	acc
      001859 08               [12] 4637 	inc	r0
      00185A E6               [12] 4638 	mov	a,@r0
      00185B C0 E0            [24] 4639 	push	acc
      00185D 90 00 00         [24] 4640 	mov	dptr,#0x0000
      001860 E4               [12] 4641 	clr	a
      001861 F5 F0            [12] 4642 	mov	b,a
      001863 12 2B E5         [24] 4643 	lcall	___fslt
      001866 AF 82            [24] 4644 	mov	r7, dpl
      001868 E5 81            [12] 4645 	mov	a,sp
      00186A 24 FC            [12] 4646 	add	a,#0xfc
      00186C F5 81            [12] 4647 	mov	sp,a
      00186E D0 04            [24] 4648 	pop	ar4
      001870 D0 05            [24] 4649 	pop	ar5
      001872 EF               [12] 4650 	mov	a,r7
      001873 60 37            [24] 4651 	jz	00122$
      001875 8D 82            [24] 4652 	mov	dpl, r5
      001877 8C 83            [24] 4653 	mov	dph, r4
      001879 12 2C B7         [24] 4654 	lcall	___uint2fs
      00187C AC 82            [24] 4655 	mov	r4, dpl
      00187E AD 83            [24] 4656 	mov	r5, dph
      001880 AE F0            [24] 4657 	mov	r6, b
      001882 FF               [12] 4658 	mov	r7, a
      001883 C0 04            [24] 4659 	push	ar4
      001885 C0 05            [24] 4660 	push	ar5
      001887 C0 06            [24] 4661 	push	ar6
      001889 C0 07            [24] 4662 	push	ar7
      00188B E5 10            [12] 4663 	mov	a,_bp
      00188D 24 18            [12] 4664 	add	a,#0x18
      00188F F8               [12] 4665 	mov	r0,a
      001890 86 82            [24] 4666 	mov	dpl, @r0
      001892 08               [12] 4667 	inc	r0
      001893 86 83            [24] 4668 	mov	dph, @r0
      001895 08               [12] 4669 	inc	r0
      001896 86 F0            [24] 4670 	mov	b, @r0
      001898 08               [12] 4671 	inc	r0
      001899 E6               [12] 4672 	mov	a, @r0
      00189A 12 2D 2C         [24] 4673 	lcall	___fsdiv
      00189D AC 82            [24] 4674 	mov	r4, dpl
      00189F AD 83            [24] 4675 	mov	r5, dph
      0018A1 AE F0            [24] 4676 	mov	r6, b
      0018A3 FF               [12] 4677 	mov	r7, a
      0018A4 E5 81            [12] 4678 	mov	a,sp
      0018A6 24 FC            [12] 4679 	add	a,#0xfc
      0018A8 F5 81            [12] 4680 	mov	sp,a
      0018AA 80 08            [24] 4681 	sjmp	00123$
      0018AC                       4682 00122$:
      0018AC 7C 00            [12] 4683 	mov	r4,#0x00
      0018AE 7D 00            [12] 4684 	mov	r5,#0x00
      0018B0 7E 00            [12] 4685 	mov	r6,#0x00
      0018B2 7F 00            [12] 4686 	mov	r7,#0x00
      0018B4                       4687 00123$:
      0018B4 8C 82            [24] 4688 	mov	dpl, r4
      0018B6 8D 83            [24] 4689 	mov	dph, r5
      0018B8 8E F0            [24] 4690 	mov	b, r6
      0018BA EF               [12] 4691 	mov	a, r7
      0018BB 02 19 D1         [24] 4692 	ljmp	00120$
      0018BE                       4693 00112$:
      0018BE E5 10            [12] 4694 	mov	a,_bp
      0018C0 24 F1            [12] 4695 	add	a,#0xf1
      0018C2 F8               [12] 4696 	mov	r0,a
      0018C3 B6 04 4C         [24] 4697 	cjne	@r0,#0x04,00114$
      0018C6 E5 10            [12] 4698 	mov	a,_bp
      0018C8 24 14            [12] 4699 	add	a,#0x14
      0018CA F8               [12] 4700 	mov	r0,a
      0018CB E6               [12] 4701 	mov	a,@r0
      0018CC C0 E0            [24] 4702 	push	acc
      0018CE 08               [12] 4703 	inc	r0
      0018CF E6               [12] 4704 	mov	a,@r0
      0018D0 C0 E0            [24] 4705 	push	acc
      0018D2 08               [12] 4706 	inc	r0
      0018D3 E6               [12] 4707 	mov	a,@r0
      0018D4 C0 E0            [24] 4708 	push	acc
      0018D6 08               [12] 4709 	inc	r0
      0018D7 E6               [12] 4710 	mov	a,@r0
      0018D8 C0 E0            [24] 4711 	push	acc
      0018DA 90 00 00         [24] 4712 	mov	dptr,#0x0000
      0018DD E4               [12] 4713 	clr	a
      0018DE F5 F0            [12] 4714 	mov	b,a
      0018E0 12 2B E5         [24] 4715 	lcall	___fslt
      0018E3 AF 82            [24] 4716 	mov	r7, dpl
      0018E5 E5 81            [12] 4717 	mov	a,sp
      0018E7 24 FC            [12] 4718 	add	a,#0xfc
      0018E9 F5 81            [12] 4719 	mov	sp,a
      0018EB EF               [12] 4720 	mov	a,r7
      0018EC 60 12            [24] 4721 	jz	00124$
      0018EE E5 10            [12] 4722 	mov	a,_bp
      0018F0 24 1C            [12] 4723 	add	a,#0x1c
      0018F2 F8               [12] 4724 	mov	r0,a
      0018F3 86 04            [24] 4725 	mov	ar4,@r0
      0018F5 08               [12] 4726 	inc	r0
      0018F6 86 05            [24] 4727 	mov	ar5,@r0
      0018F8 08               [12] 4728 	inc	r0
      0018F9 86 06            [24] 4729 	mov	ar6,@r0
      0018FB 08               [12] 4730 	inc	r0
      0018FC 86 07            [24] 4731 	mov	ar7,@r0
      0018FE 80 08            [24] 4732 	sjmp	00125$
      001900                       4733 00124$:
      001900 7C 00            [12] 4734 	mov	r4,#0x00
      001902 7D 00            [12] 4735 	mov	r5,#0x00
      001904 7E 00            [12] 4736 	mov	r6,#0x00
      001906 7F 00            [12] 4737 	mov	r7,#0x00
      001908                       4738 00125$:
      001908 8C 82            [24] 4739 	mov	dpl, r4
      00190A 8D 83            [24] 4740 	mov	dph, r5
      00190C 8E F0            [24] 4741 	mov	b, r6
      00190E EF               [12] 4742 	mov	a, r7
      00190F 02 19 D1         [24] 4743 	ljmp	00120$
      001912                       4744 00114$:
      001912 E5 10            [12] 4745 	mov	a,_bp
      001914 24 F1            [12] 4746 	add	a,#0xf1
      001916 F8               [12] 4747 	mov	r0,a
      001917 B6 05 4B         [24] 4748 	cjne	@r0,#0x05,00116$
      00191A E5 10            [12] 4749 	mov	a,_bp
      00191C 24 14            [12] 4750 	add	a,#0x14
      00191E F8               [12] 4751 	mov	r0,a
      00191F E6               [12] 4752 	mov	a,@r0
      001920 C0 E0            [24] 4753 	push	acc
      001922 08               [12] 4754 	inc	r0
      001923 E6               [12] 4755 	mov	a,@r0
      001924 C0 E0            [24] 4756 	push	acc
      001926 08               [12] 4757 	inc	r0
      001927 E6               [12] 4758 	mov	a,@r0
      001928 C0 E0            [24] 4759 	push	acc
      00192A 08               [12] 4760 	inc	r0
      00192B E6               [12] 4761 	mov	a,@r0
      00192C C0 E0            [24] 4762 	push	acc
      00192E 90 00 00         [24] 4763 	mov	dptr,#0x0000
      001931 E4               [12] 4764 	clr	a
      001932 F5 F0            [12] 4765 	mov	b,a
      001934 12 2B E5         [24] 4766 	lcall	___fslt
      001937 AF 82            [24] 4767 	mov	r7, dpl
      001939 E5 81            [12] 4768 	mov	a,sp
      00193B 24 FC            [12] 4769 	add	a,#0xfc
      00193D F5 81            [12] 4770 	mov	sp,a
      00193F EF               [12] 4771 	mov	a,r7
      001940 60 12            [24] 4772 	jz	00126$
      001942 E5 10            [12] 4773 	mov	a,_bp
      001944 24 20            [12] 4774 	add	a,#0x20
      001946 F8               [12] 4775 	mov	r0,a
      001947 86 04            [24] 4776 	mov	ar4,@r0
      001949 08               [12] 4777 	inc	r0
      00194A 86 05            [24] 4778 	mov	ar5,@r0
      00194C 08               [12] 4779 	inc	r0
      00194D 86 06            [24] 4780 	mov	ar6,@r0
      00194F 08               [12] 4781 	inc	r0
      001950 86 07            [24] 4782 	mov	ar7,@r0
      001952 80 08            [24] 4783 	sjmp	00127$
      001954                       4784 00126$:
      001954 7C 00            [12] 4785 	mov	r4,#0x00
      001956 7D 00            [12] 4786 	mov	r5,#0x00
      001958 7E 00            [12] 4787 	mov	r6,#0x00
      00195A 7F 00            [12] 4788 	mov	r7,#0x00
      00195C                       4789 00127$:
      00195C 8C 82            [24] 4790 	mov	dpl, r4
      00195E 8D 83            [24] 4791 	mov	dph, r5
      001960 8E F0            [24] 4792 	mov	b, r6
      001962 EF               [12] 4793 	mov	a, r7
      001963 80 6C            [24] 4794 	sjmp	00120$
      001965                       4795 00116$:
      001965 E5 10            [12] 4796 	mov	a,_bp
      001967 24 10            [12] 4797 	add	a,#0x10
      001969 F8               [12] 4798 	mov	r0,a
      00196A E6               [12] 4799 	mov	a,@r0
      00196B C0 E0            [24] 4800 	push	acc
      00196D 08               [12] 4801 	inc	r0
      00196E E6               [12] 4802 	mov	a,@r0
      00196F C0 E0            [24] 4803 	push	acc
      001971 08               [12] 4804 	inc	r0
      001972 E6               [12] 4805 	mov	a,@r0
      001973 C0 E0            [24] 4806 	push	acc
      001975 08               [12] 4807 	inc	r0
      001976 E6               [12] 4808 	mov	a,@r0
      001977 C0 E0            [24] 4809 	push	acc
      001979 90 00 00         [24] 4810 	mov	dptr,#0x0000
      00197C E4               [12] 4811 	clr	a
      00197D F5 F0            [12] 4812 	mov	b,a
      00197F 12 2B E5         [24] 4813 	lcall	___fslt
      001982 AF 82            [24] 4814 	mov	r7, dpl
      001984 E5 81            [12] 4815 	mov	a,sp
      001986 24 FC            [12] 4816 	add	a,#0xfc
      001988 F5 81            [12] 4817 	mov	sp,a
      00198A EF               [12] 4818 	mov	a,r7
      00198B 60 35            [24] 4819 	jz	00128$
      00198D E5 10            [12] 4820 	mov	a,_bp
      00198F 24 10            [12] 4821 	add	a,#0x10
      001991 F8               [12] 4822 	mov	r0,a
      001992 E6               [12] 4823 	mov	a,@r0
      001993 C0 E0            [24] 4824 	push	acc
      001995 08               [12] 4825 	inc	r0
      001996 E6               [12] 4826 	mov	a,@r0
      001997 C0 E0            [24] 4827 	push	acc
      001999 08               [12] 4828 	inc	r0
      00199A E6               [12] 4829 	mov	a,@r0
      00199B C0 E0            [24] 4830 	push	acc
      00199D 08               [12] 4831 	inc	r0
      00199E E6               [12] 4832 	mov	a,@r0
      00199F C0 E0            [24] 4833 	push	acc
      0019A1 E5 10            [12] 4834 	mov	a,_bp
      0019A3 24 0C            [12] 4835 	add	a,#0x0c
      0019A5 F8               [12] 4836 	mov	r0,a
      0019A6 86 82            [24] 4837 	mov	dpl, @r0
      0019A8 08               [12] 4838 	inc	r0
      0019A9 86 83            [24] 4839 	mov	dph, @r0
      0019AB 08               [12] 4840 	inc	r0
      0019AC 86 F0            [24] 4841 	mov	b, @r0
      0019AE 08               [12] 4842 	inc	r0
      0019AF E6               [12] 4843 	mov	a, @r0
      0019B0 12 2D 2C         [24] 4844 	lcall	___fsdiv
      0019B3 AC 82            [24] 4845 	mov	r4, dpl
      0019B5 AD 83            [24] 4846 	mov	r5, dph
      0019B7 AE F0            [24] 4847 	mov	r6, b
      0019B9 FF               [12] 4848 	mov	r7, a
      0019BA E5 81            [12] 4849 	mov	a,sp
      0019BC 24 FC            [12] 4850 	add	a,#0xfc
      0019BE F5 81            [12] 4851 	mov	sp,a
      0019C0 80 08            [24] 4852 	sjmp	00129$
      0019C2                       4853 00128$:
      0019C2 7C 00            [12] 4854 	mov	r4,#0x00
      0019C4 7D 00            [12] 4855 	mov	r5,#0x00
      0019C6 7E 00            [12] 4856 	mov	r6,#0x00
      0019C8 7F 00            [12] 4857 	mov	r7,#0x00
      0019CA                       4858 00129$:
      0019CA 8C 82            [24] 4859 	mov	dpl, r4
      0019CC 8D 83            [24] 4860 	mov	dph, r5
      0019CE 8E F0            [24] 4861 	mov	b, r6
      0019D0 EF               [12] 4862 	mov	a, r7
      0019D1                       4863 00120$:
      0019D1 85 10 81         [24] 4864 	mov	sp,_bp
      0019D4 D0 10            [24] 4865 	pop	_bp
                           001919  4866 	C$fuzzy.h$75$1_0$43 ==.
                           001919  4867 	XG$fuzzy_rules_defuzzify$0$0 ==.
      0019D6 22               [24] 4868 	ret
                                   4869 ;------------------------------------------------------------
                                   4870 ;Allocation info for local variables in function 'fuzzy_rules_cog'
                                   4871 ;------------------------------------------------------------
                                   4872 ;lower         Allocated to stack - _bp -6 +4 
                                   4873 ;upper         Allocated to stack - _bp -10 +4 
                                   4874 ;step          Allocated to stack - _bp -14 +4 
                                   4875 ;rules         Allocated to registers r5 r6 r7 
                                   4876 ;------------------------------------------------------------
                           00191A  4877 	G$fuzzy_rules_cog$0$0 ==.
                           00191A  4878 	C$fuzzy.h$76$1_0$49 ==.
                                   4879 ;	../../fuzzy.h:76: float fuzzy_rules_cog(const fuzzy_rules_t *rules, float lower, float upper, float step) { return fuzzy_rules_defuzzify(rules, lower, upper, step, FUZZY_DEFUZZ_COG); }
                                   4880 ;	-----------------------------------------
                                   4881 ;	 function fuzzy_rules_cog
                                   4882 ;	-----------------------------------------
      0019D7                       4883 _fuzzy_rules_cog:
      0019D7 C0 10            [24] 4884 	push	_bp
      0019D9 85 81 10         [24] 4885 	mov	_bp,sp
      0019DC AD 82            [24] 4886 	mov	r5, dpl
      0019DE AE 83            [24] 4887 	mov	r6, dph
      0019E0 AF F0            [24] 4888 	mov	r7, b
      0019E2 E4               [12] 4889 	clr	a
      0019E3 C0 E0            [24] 4890 	push	acc
      0019E5 E5 10            [12] 4891 	mov	a,_bp
      0019E7 24 F2            [12] 4892 	add	a,#0xf2
      0019E9 F8               [12] 4893 	mov	r0,a
      0019EA E6               [12] 4894 	mov	a,@r0
      0019EB C0 E0            [24] 4895 	push	acc
      0019ED 08               [12] 4896 	inc	r0
      0019EE E6               [12] 4897 	mov	a,@r0
      0019EF C0 E0            [24] 4898 	push	acc
      0019F1 08               [12] 4899 	inc	r0
      0019F2 E6               [12] 4900 	mov	a,@r0
      0019F3 C0 E0            [24] 4901 	push	acc
      0019F5 08               [12] 4902 	inc	r0
      0019F6 E6               [12] 4903 	mov	a,@r0
      0019F7 C0 E0            [24] 4904 	push	acc
      0019F9 E5 10            [12] 4905 	mov	a,_bp
      0019FB 24 F6            [12] 4906 	add	a,#0xf6
      0019FD F8               [12] 4907 	mov	r0,a
      0019FE E6               [12] 4908 	mov	a,@r0
      0019FF C0 E0            [24] 4909 	push	acc
      001A01 08               [12] 4910 	inc	r0
      001A02 E6               [12] 4911 	mov	a,@r0
      001A03 C0 E0            [24] 4912 	push	acc
      001A05 08               [12] 4913 	inc	r0
      001A06 E6               [12] 4914 	mov	a,@r0
      001A07 C0 E0            [24] 4915 	push	acc
      001A09 08               [12] 4916 	inc	r0
      001A0A E6               [12] 4917 	mov	a,@r0
      001A0B C0 E0            [24] 4918 	push	acc
      001A0D E5 10            [12] 4919 	mov	a,_bp
      001A0F 24 FA            [12] 4920 	add	a,#0xfa
      001A11 F8               [12] 4921 	mov	r0,a
      001A12 E6               [12] 4922 	mov	a,@r0
      001A13 C0 E0            [24] 4923 	push	acc
      001A15 08               [12] 4924 	inc	r0
      001A16 E6               [12] 4925 	mov	a,@r0
      001A17 C0 E0            [24] 4926 	push	acc
      001A19 08               [12] 4927 	inc	r0
      001A1A E6               [12] 4928 	mov	a,@r0
      001A1B C0 E0            [24] 4929 	push	acc
      001A1D 08               [12] 4930 	inc	r0
      001A1E E6               [12] 4931 	mov	a,@r0
      001A1F C0 E0            [24] 4932 	push	acc
      001A21 8D 82            [24] 4933 	mov	dpl, r5
      001A23 8E 83            [24] 4934 	mov	dph, r6
      001A25 8F F0            [24] 4935 	mov	b, r7
      001A27 12 14 93         [24] 4936 	lcall	_fuzzy_rules_defuzzify
      001A2A AC 82            [24] 4937 	mov	r4, dpl
      001A2C AD 83            [24] 4938 	mov	r5, dph
      001A2E AE F0            [24] 4939 	mov	r6, b
      001A30 FF               [12] 4940 	mov	r7, a
      001A31 E5 81            [12] 4941 	mov	a,sp
      001A33 24 F3            [12] 4942 	add	a,#0xf3
      001A35 F5 81            [12] 4943 	mov	sp,a
      001A37 8C 82            [24] 4944 	mov	dpl, r4
      001A39 8D 83            [24] 4945 	mov	dph, r5
      001A3B 8E F0            [24] 4946 	mov	b, r6
      001A3D EF               [12] 4947 	mov	a, r7
      001A3E D0 10            [24] 4948 	pop	_bp
                           001983  4949 	C$fuzzy.h$76$1_0$49 ==.
                           001983  4950 	XG$fuzzy_rules_cog$0$0 ==.
      001A40 22               [24] 4951 	ret
                                   4952 ;------------------------------------------------------------
                                   4953 ;Allocation info for local variables in function 'temperature_low'
                                   4954 ;------------------------------------------------------------
                                   4955 ;x             Allocated to registers r4 r5 r6 r7 
                                   4956 ;------------------------------------------------------------
                           001984  4957 	Fsugeno_demo$temperature_low$0$0 ==.
                           001984  4958 	C$sugeno_demo.c$29$1_0$51 ==.
                                   4959 ;	../../sugeno_demo.c:29: FUZZY_VAR(temperature_low, FUZZY_SHAPE_RAMP, HEDGE_NONE, 15.0f, 40.0f, false)
                                   4960 ;	-----------------------------------------
                                   4961 ;	 function temperature_low
                                   4962 ;	-----------------------------------------
      001A41                       4963 _temperature_low:
      001A41 AC 82            [24] 4964 	mov	r4,dpl
      001A43 AD 83            [24] 4965 	mov	r5,dph
      001A45 AE F0            [24] 4966 	mov	r6,b
      001A47 FF               [12] 4967 	mov	r7,a
      001A48 C0 04            [24] 4968 	push	ar4
      001A4A C0 05            [24] 4969 	push	ar5
      001A4C C0 06            [24] 4970 	push	ar6
      001A4E C0 07            [24] 4971 	push	ar7
      001A50 90 2E B1         [24] 4972 	mov	dptr,#_temperature_low_fuzzy_variable
      001A53 75 F0 80         [24] 4973 	mov	b, #0x80
      001A56 12 0E 65         [24] 4974 	lcall	_fuzzy_8051_eval
      001A59 AC 82            [24] 4975 	mov	r4, dpl
      001A5B AD 83            [24] 4976 	mov	r5, dph
      001A5D AE F0            [24] 4977 	mov	r6, b
      001A5F FF               [12] 4978 	mov	r7, a
      001A60 E5 81            [12] 4979 	mov	a,sp
      001A62 24 FC            [12] 4980 	add	a,#0xfc
      001A64 F5 81            [12] 4981 	mov	sp,a
      001A66 8C 82            [24] 4982 	mov	dpl, r4
      001A68 8D 83            [24] 4983 	mov	dph, r5
      001A6A 8E F0            [24] 4984 	mov	b, r6
      001A6C EF               [12] 4985 	mov	a, r7
                           0019B0  4986 	C$sugeno_demo.c$29$1_0$51 ==.
                           0019B0  4987 	XFsugeno_demo$temperature_low$0$0 ==.
      001A6D 22               [24] 4988 	ret
                                   4989 ;------------------------------------------------------------
                                   4990 ;Allocation info for local variables in function 'temperature_high'
                                   4991 ;------------------------------------------------------------
                                   4992 ;x             Allocated to registers r4 r5 r6 r7 
                                   4993 ;------------------------------------------------------------
                           0019B1  4994 	Fsugeno_demo$temperature_high$0$0 ==.
                           0019B1  4995 	C$sugeno_demo.c$30$1_0$53 ==.
                                   4996 ;	../../sugeno_demo.c:30: FUZZY_VAR(temperature_high, FUZZY_SHAPE_RAMP, HEDGE_NONE, 35.0f, 75.0f, true)
                                   4997 ;	-----------------------------------------
                                   4998 ;	 function temperature_high
                                   4999 ;	-----------------------------------------
      001A6E                       5000 _temperature_high:
      001A6E AC 82            [24] 5001 	mov	r4,dpl
      001A70 AD 83            [24] 5002 	mov	r5,dph
      001A72 AE F0            [24] 5003 	mov	r6,b
      001A74 FF               [12] 5004 	mov	r7,a
      001A75 C0 04            [24] 5005 	push	ar4
      001A77 C0 05            [24] 5006 	push	ar5
      001A79 C0 06            [24] 5007 	push	ar6
      001A7B C0 07            [24] 5008 	push	ar7
      001A7D 90 2E C3         [24] 5009 	mov	dptr,#_temperature_high_fuzzy_variable
      001A80 75 F0 80         [24] 5010 	mov	b, #0x80
      001A83 12 0E 65         [24] 5011 	lcall	_fuzzy_8051_eval
      001A86 AC 82            [24] 5012 	mov	r4, dpl
      001A88 AD 83            [24] 5013 	mov	r5, dph
      001A8A AE F0            [24] 5014 	mov	r6, b
      001A8C FF               [12] 5015 	mov	r7, a
      001A8D E5 81            [12] 5016 	mov	a,sp
      001A8F 24 FC            [12] 5017 	add	a,#0xfc
      001A91 F5 81            [12] 5018 	mov	sp,a
      001A93 8C 82            [24] 5019 	mov	dpl, r4
      001A95 8D 83            [24] 5020 	mov	dph, r5
      001A97 8E F0            [24] 5021 	mov	b, r6
      001A99 EF               [12] 5022 	mov	a, r7
                           0019DD  5023 	C$sugeno_demo.c$30$1_0$53 ==.
                           0019DD  5024 	XFsugeno_demo$temperature_high$0$0 ==.
      001A9A 22               [24] 5025 	ret
                                   5026 ;------------------------------------------------------------
                                   5027 ;Allocation info for local variables in function 'load_low'
                                   5028 ;------------------------------------------------------------
                                   5029 ;x             Allocated to registers r4 r5 r6 r7 
                                   5030 ;------------------------------------------------------------
                           0019DE  5031 	Fsugeno_demo$load_low$0$0 ==.
                           0019DE  5032 	C$sugeno_demo.c$31$1_0$55 ==.
                                   5033 ;	../../sugeno_demo.c:31: FUZZY_VAR(load_low, FUZZY_SHAPE_RAMP, HEDGE_NONE, 20.0f, 50.0f, false)
                                   5034 ;	-----------------------------------------
                                   5035 ;	 function load_low
                                   5036 ;	-----------------------------------------
      001A9B                       5037 _load_low:
      001A9B AC 82            [24] 5038 	mov	r4,dpl
      001A9D AD 83            [24] 5039 	mov	r5,dph
      001A9F AE F0            [24] 5040 	mov	r6,b
      001AA1 FF               [12] 5041 	mov	r7,a
      001AA2 C0 04            [24] 5042 	push	ar4
      001AA4 C0 05            [24] 5043 	push	ar5
      001AA6 C0 06            [24] 5044 	push	ar6
      001AA8 C0 07            [24] 5045 	push	ar7
      001AAA 90 2E D5         [24] 5046 	mov	dptr,#_load_low_fuzzy_variable
      001AAD 75 F0 80         [24] 5047 	mov	b, #0x80
      001AB0 12 0E 65         [24] 5048 	lcall	_fuzzy_8051_eval
      001AB3 AC 82            [24] 5049 	mov	r4, dpl
      001AB5 AD 83            [24] 5050 	mov	r5, dph
      001AB7 AE F0            [24] 5051 	mov	r6, b
      001AB9 FF               [12] 5052 	mov	r7, a
      001ABA E5 81            [12] 5053 	mov	a,sp
      001ABC 24 FC            [12] 5054 	add	a,#0xfc
      001ABE F5 81            [12] 5055 	mov	sp,a
      001AC0 8C 82            [24] 5056 	mov	dpl, r4
      001AC2 8D 83            [24] 5057 	mov	dph, r5
      001AC4 8E F0            [24] 5058 	mov	b, r6
      001AC6 EF               [12] 5059 	mov	a, r7
                           001A0A  5060 	C$sugeno_demo.c$31$1_0$55 ==.
                           001A0A  5061 	XFsugeno_demo$load_low$0$0 ==.
      001AC7 22               [24] 5062 	ret
                                   5063 ;------------------------------------------------------------
                                   5064 ;Allocation info for local variables in function 'load_high'
                                   5065 ;------------------------------------------------------------
                                   5066 ;x             Allocated to registers r4 r5 r6 r7 
                                   5067 ;------------------------------------------------------------
                           001A0B  5068 	Fsugeno_demo$load_high$0$0 ==.
                           001A0B  5069 	C$sugeno_demo.c$32$1_0$57 ==.
                                   5070 ;	../../sugeno_demo.c:32: FUZZY_VAR(load_high, FUZZY_SHAPE_RAMP, HEDGE_NONE, 45.0f, 85.0f, true)
                                   5071 ;	-----------------------------------------
                                   5072 ;	 function load_high
                                   5073 ;	-----------------------------------------
      001AC8                       5074 _load_high:
      001AC8 AC 82            [24] 5075 	mov	r4,dpl
      001ACA AD 83            [24] 5076 	mov	r5,dph
      001ACC AE F0            [24] 5077 	mov	r6,b
      001ACE FF               [12] 5078 	mov	r7,a
      001ACF C0 04            [24] 5079 	push	ar4
      001AD1 C0 05            [24] 5080 	push	ar5
      001AD3 C0 06            [24] 5081 	push	ar6
      001AD5 C0 07            [24] 5082 	push	ar7
      001AD7 90 2E E7         [24] 5083 	mov	dptr,#_load_high_fuzzy_variable
      001ADA 75 F0 80         [24] 5084 	mov	b, #0x80
      001ADD 12 0E 65         [24] 5085 	lcall	_fuzzy_8051_eval
      001AE0 AC 82            [24] 5086 	mov	r4, dpl
      001AE2 AD 83            [24] 5087 	mov	r5, dph
      001AE4 AE F0            [24] 5088 	mov	r6, b
      001AE6 FF               [12] 5089 	mov	r7, a
      001AE7 E5 81            [12] 5090 	mov	a,sp
      001AE9 24 FC            [12] 5091 	add	a,#0xfc
      001AEB F5 81            [12] 5092 	mov	sp,a
      001AED 8C 82            [24] 5093 	mov	dpl, r4
      001AEF 8D 83            [24] 5094 	mov	dph, r5
      001AF1 8E F0            [24] 5095 	mov	b, r6
      001AF3 EF               [12] 5096 	mov	a, r7
                           001A37  5097 	C$sugeno_demo.c$32$1_0$57 ==.
                           001A37  5098 	XFsugeno_demo$load_high$0$0 ==.
      001AF4 22               [24] 5099 	ret
                                   5100 ;------------------------------------------------------------
                                   5101 ;Allocation info for local variables in function 'vibration_low'
                                   5102 ;------------------------------------------------------------
                                   5103 ;x             Allocated to registers r4 r5 r6 r7 
                                   5104 ;------------------------------------------------------------
                           001A38  5105 	Fsugeno_demo$vibration_low$0$0 ==.
                           001A38  5106 	C$sugeno_demo.c$33$1_0$59 ==.
                                   5107 ;	../../sugeno_demo.c:33: FUZZY_VAR(vibration_low, FUZZY_SHAPE_RAMP, HEDGE_NONE, 1.0f, 4.0f, false)
                                   5108 ;	-----------------------------------------
                                   5109 ;	 function vibration_low
                                   5110 ;	-----------------------------------------
      001AF5                       5111 _vibration_low:
      001AF5 AC 82            [24] 5112 	mov	r4,dpl
      001AF7 AD 83            [24] 5113 	mov	r5,dph
      001AF9 AE F0            [24] 5114 	mov	r6,b
      001AFB FF               [12] 5115 	mov	r7,a
      001AFC C0 04            [24] 5116 	push	ar4
      001AFE C0 05            [24] 5117 	push	ar5
      001B00 C0 06            [24] 5118 	push	ar6
      001B02 C0 07            [24] 5119 	push	ar7
      001B04 90 2E F9         [24] 5120 	mov	dptr,#_vibration_low_fuzzy_variable
      001B07 75 F0 80         [24] 5121 	mov	b, #0x80
      001B0A 12 0E 65         [24] 5122 	lcall	_fuzzy_8051_eval
      001B0D AC 82            [24] 5123 	mov	r4, dpl
      001B0F AD 83            [24] 5124 	mov	r5, dph
      001B11 AE F0            [24] 5125 	mov	r6, b
      001B13 FF               [12] 5126 	mov	r7, a
      001B14 E5 81            [12] 5127 	mov	a,sp
      001B16 24 FC            [12] 5128 	add	a,#0xfc
      001B18 F5 81            [12] 5129 	mov	sp,a
      001B1A 8C 82            [24] 5130 	mov	dpl, r4
      001B1C 8D 83            [24] 5131 	mov	dph, r5
      001B1E 8E F0            [24] 5132 	mov	b, r6
      001B20 EF               [12] 5133 	mov	a, r7
                           001A64  5134 	C$sugeno_demo.c$33$1_0$59 ==.
                           001A64  5135 	XFsugeno_demo$vibration_low$0$0 ==.
      001B21 22               [24] 5136 	ret
                                   5137 ;------------------------------------------------------------
                                   5138 ;Allocation info for local variables in function 'vibration_high'
                                   5139 ;------------------------------------------------------------
                                   5140 ;x             Allocated to registers r4 r5 r6 r7 
                                   5141 ;------------------------------------------------------------
                           001A65  5142 	Fsugeno_demo$vibration_high$0$0 ==.
                           001A65  5143 	C$sugeno_demo.c$34$1_0$61 ==.
                                   5144 ;	../../sugeno_demo.c:34: FUZZY_VAR(vibration_high, FUZZY_SHAPE_RAMP, HEDGE_NONE, 3.0f, 8.0f, true)
                                   5145 ;	-----------------------------------------
                                   5146 ;	 function vibration_high
                                   5147 ;	-----------------------------------------
      001B22                       5148 _vibration_high:
      001B22 AC 82            [24] 5149 	mov	r4,dpl
      001B24 AD 83            [24] 5150 	mov	r5,dph
      001B26 AE F0            [24] 5151 	mov	r6,b
      001B28 FF               [12] 5152 	mov	r7,a
      001B29 C0 04            [24] 5153 	push	ar4
      001B2B C0 05            [24] 5154 	push	ar5
      001B2D C0 06            [24] 5155 	push	ar6
      001B2F C0 07            [24] 5156 	push	ar7
      001B31 90 2F 0B         [24] 5157 	mov	dptr,#_vibration_high_fuzzy_variable
      001B34 75 F0 80         [24] 5158 	mov	b, #0x80
      001B37 12 0E 65         [24] 5159 	lcall	_fuzzy_8051_eval
      001B3A AC 82            [24] 5160 	mov	r4, dpl
      001B3C AD 83            [24] 5161 	mov	r5, dph
      001B3E AE F0            [24] 5162 	mov	r6, b
      001B40 FF               [12] 5163 	mov	r7, a
      001B41 E5 81            [12] 5164 	mov	a,sp
      001B43 24 FC            [12] 5165 	add	a,#0xfc
      001B45 F5 81            [12] 5166 	mov	sp,a
      001B47 8C 82            [24] 5167 	mov	dpl, r4
      001B49 8D 83            [24] 5168 	mov	dph, r5
      001B4B 8E F0            [24] 5169 	mov	b, r6
      001B4D EF               [12] 5170 	mov	a, r7
                           001A91  5171 	C$sugeno_demo.c$34$1_0$61 ==.
                           001A91  5172 	XFsugeno_demo$vibration_high$0$0 ==.
      001B4E 22               [24] 5173 	ret
                                   5174 ;------------------------------------------------------------
                                   5175 ;Allocation info for local variables in function 'response_idle'
                                   5176 ;------------------------------------------------------------
                                   5177 ;load          Allocated to stack - _bp -6 +4 
                                   5178 ;vibration     Allocated to stack - _bp -10 +4 
                                   5179 ;temperature   Allocated to registers r4 r5 r6 r7 
                                   5180 ;sloc0         Allocated to stack - _bp +1 +4 
                                   5181 ;------------------------------------------------------------
                           001A92  5182 	Fsugeno_demo$response_idle$0$0 ==.
                           001A92  5183 	C$sugeno_demo.c$36$1_0$63 ==.
                                   5184 ;	../../sugeno_demo.c:36: static float response_idle(float temperature, float load, float vibration) { return 8.0f + 0.20f * temperature + 0.08f * load + 0.50f * vibration; }
                                   5185 ;	-----------------------------------------
                                   5186 ;	 function response_idle
                                   5187 ;	-----------------------------------------
      001B4F                       5188 _response_idle:
      001B4F C0 10            [24] 5189 	push	_bp
      001B51 85 81 10         [24] 5190 	mov	_bp,sp
      001B54 AC 82            [24] 5191 	mov	r4,dpl
      001B56 AD 83            [24] 5192 	mov	r5,dph
      001B58 AE F0            [24] 5193 	mov	r6,b
      001B5A FF               [12] 5194 	mov	r7,a
      001B5B E5 81            [12] 5195 	mov	a,sp
      001B5D 24 04            [12] 5196 	add	a,#0x04
      001B5F F5 81            [12] 5197 	mov	sp,a
      001B61 C0 04            [24] 5198 	push	ar4
      001B63 C0 05            [24] 5199 	push	ar5
      001B65 C0 06            [24] 5200 	push	ar6
      001B67 C0 07            [24] 5201 	push	ar7
      001B69 90 CC CD         [24] 5202 	mov	dptr,#0xcccd
      001B6C 75 F0 4C         [24] 5203 	mov	b, #0x4c
      001B6F 74 3E            [12] 5204 	mov	a, #0x3e
      001B71 12 2A B5         [24] 5205 	lcall	___fsmul
      001B74 AC 82            [24] 5206 	mov	r4, dpl
      001B76 AD 83            [24] 5207 	mov	r5, dph
      001B78 AE F0            [24] 5208 	mov	r6, b
      001B7A FF               [12] 5209 	mov	r7, a
      001B7B E5 81            [12] 5210 	mov	a,sp
      001B7D 24 FC            [12] 5211 	add	a,#0xfc
      001B7F F5 81            [12] 5212 	mov	sp,a
      001B81 E4               [12] 5213 	clr	a
      001B82 C0 E0            [24] 5214 	push	acc
      001B84 C0 E0            [24] 5215 	push	acc
      001B86 C0 E0            [24] 5216 	push	acc
      001B88 74 41            [12] 5217 	mov	a,#0x41
      001B8A C0 E0            [24] 5218 	push	acc
      001B8C 8C 82            [24] 5219 	mov	dpl, r4
      001B8E 8D 83            [24] 5220 	mov	dph, r5
      001B90 8E F0            [24] 5221 	mov	b, r6
      001B92 EF               [12] 5222 	mov	a, r7
      001B93 12 2C 15         [24] 5223 	lcall	___fsadd
      001B96 A8 10            [24] 5224 	mov	r0,_bp
      001B98 08               [12] 5225 	inc	r0
      001B99 A6 82            [24] 5226 	mov	@r0, dpl
      001B9B 08               [12] 5227 	inc	r0
      001B9C A6 83            [24] 5228 	mov	@r0, dph
      001B9E 08               [12] 5229 	inc	r0
      001B9F A6 F0            [24] 5230 	mov	@r0, b
      001BA1 08               [12] 5231 	inc	r0
      001BA2 F6               [12] 5232 	mov	@r0,a
      001BA3 E5 81            [12] 5233 	mov	a,sp
      001BA5 24 FC            [12] 5234 	add	a,#0xfc
      001BA7 F5 81            [12] 5235 	mov	sp,a
      001BA9 E5 10            [12] 5236 	mov	a,_bp
      001BAB 24 FA            [12] 5237 	add	a,#0xfa
      001BAD F8               [12] 5238 	mov	r0,a
      001BAE E6               [12] 5239 	mov	a,@r0
      001BAF C0 E0            [24] 5240 	push	acc
      001BB1 08               [12] 5241 	inc	r0
      001BB2 E6               [12] 5242 	mov	a,@r0
      001BB3 C0 E0            [24] 5243 	push	acc
      001BB5 08               [12] 5244 	inc	r0
      001BB6 E6               [12] 5245 	mov	a,@r0
      001BB7 C0 E0            [24] 5246 	push	acc
      001BB9 08               [12] 5247 	inc	r0
      001BBA E6               [12] 5248 	mov	a,@r0
      001BBB C0 E0            [24] 5249 	push	acc
      001BBD 90 D7 0A         [24] 5250 	mov	dptr,#0xd70a
      001BC0 75 F0 A3         [24] 5251 	mov	b, #0xa3
      001BC3 74 3D            [12] 5252 	mov	a, #0x3d
      001BC5 12 2A B5         [24] 5253 	lcall	___fsmul
      001BC8 AA 82            [24] 5254 	mov	r2, dpl
      001BCA AB 83            [24] 5255 	mov	r3, dph
      001BCC AE F0            [24] 5256 	mov	r6, b
      001BCE FF               [12] 5257 	mov	r7, a
      001BCF E5 81            [12] 5258 	mov	a,sp
      001BD1 24 FC            [12] 5259 	add	a,#0xfc
      001BD3 F5 81            [12] 5260 	mov	sp,a
      001BD5 C0 02            [24] 5261 	push	ar2
      001BD7 C0 03            [24] 5262 	push	ar3
      001BD9 C0 06            [24] 5263 	push	ar6
      001BDB C0 07            [24] 5264 	push	ar7
      001BDD A8 10            [24] 5265 	mov	r0,_bp
      001BDF 08               [12] 5266 	inc	r0
      001BE0 86 82            [24] 5267 	mov	dpl, @r0
      001BE2 08               [12] 5268 	inc	r0
      001BE3 86 83            [24] 5269 	mov	dph, @r0
      001BE5 08               [12] 5270 	inc	r0
      001BE6 86 F0            [24] 5271 	mov	b, @r0
      001BE8 08               [12] 5272 	inc	r0
      001BE9 E6               [12] 5273 	mov	a, @r0
      001BEA 12 2C 15         [24] 5274 	lcall	___fsadd
      001BED A8 10            [24] 5275 	mov	r0,_bp
      001BEF 08               [12] 5276 	inc	r0
      001BF0 A6 82            [24] 5277 	mov	@r0, dpl
      001BF2 08               [12] 5278 	inc	r0
      001BF3 A6 83            [24] 5279 	mov	@r0, dph
      001BF5 08               [12] 5280 	inc	r0
      001BF6 A6 F0            [24] 5281 	mov	@r0, b
      001BF8 08               [12] 5282 	inc	r0
      001BF9 F6               [12] 5283 	mov	@r0,a
      001BFA E5 81            [12] 5284 	mov	a,sp
      001BFC 24 FC            [12] 5285 	add	a,#0xfc
      001BFE F5 81            [12] 5286 	mov	sp,a
      001C00 E5 10            [12] 5287 	mov	a,_bp
      001C02 24 F6            [12] 5288 	add	a,#0xf6
      001C04 F8               [12] 5289 	mov	r0,a
      001C05 E6               [12] 5290 	mov	a,@r0
      001C06 C0 E0            [24] 5291 	push	acc
      001C08 08               [12] 5292 	inc	r0
      001C09 E6               [12] 5293 	mov	a,@r0
      001C0A C0 E0            [24] 5294 	push	acc
      001C0C 08               [12] 5295 	inc	r0
      001C0D E6               [12] 5296 	mov	a,@r0
      001C0E C0 E0            [24] 5297 	push	acc
      001C10 08               [12] 5298 	inc	r0
      001C11 E6               [12] 5299 	mov	a,@r0
      001C12 C0 E0            [24] 5300 	push	acc
      001C14 90 00 00         [24] 5301 	mov	dptr,#(0x00&0x00ff)
      001C17 E4               [12] 5302 	clr	a
      001C18 F5 F0            [12] 5303 	mov	b,a
      001C1A 74 3F            [12] 5304 	mov	a,#0x3f
      001C1C 12 2A B5         [24] 5305 	lcall	___fsmul
      001C1F AA 82            [24] 5306 	mov	r2, dpl
      001C21 AB 83            [24] 5307 	mov	r3, dph
      001C23 AE F0            [24] 5308 	mov	r6, b
      001C25 FF               [12] 5309 	mov	r7, a
      001C26 E5 81            [12] 5310 	mov	a,sp
      001C28 24 FC            [12] 5311 	add	a,#0xfc
      001C2A F5 81            [12] 5312 	mov	sp,a
      001C2C C0 02            [24] 5313 	push	ar2
      001C2E C0 03            [24] 5314 	push	ar3
      001C30 C0 06            [24] 5315 	push	ar6
      001C32 C0 07            [24] 5316 	push	ar7
      001C34 A8 10            [24] 5317 	mov	r0,_bp
      001C36 08               [12] 5318 	inc	r0
      001C37 86 82            [24] 5319 	mov	dpl, @r0
      001C39 08               [12] 5320 	inc	r0
      001C3A 86 83            [24] 5321 	mov	dph, @r0
      001C3C 08               [12] 5322 	inc	r0
      001C3D 86 F0            [24] 5323 	mov	b, @r0
      001C3F 08               [12] 5324 	inc	r0
      001C40 E6               [12] 5325 	mov	a, @r0
      001C41 12 2C 15         [24] 5326 	lcall	___fsadd
      001C44 AC 82            [24] 5327 	mov	r4, dpl
      001C46 AD 83            [24] 5328 	mov	r5, dph
      001C48 AE F0            [24] 5329 	mov	r6, b
      001C4A FF               [12] 5330 	mov	r7, a
      001C4B E5 81            [12] 5331 	mov	a,sp
      001C4D 24 FC            [12] 5332 	add	a,#0xfc
      001C4F F5 81            [12] 5333 	mov	sp,a
      001C51 8C 82            [24] 5334 	mov	dpl, r4
      001C53 8D 83            [24] 5335 	mov	dph, r5
      001C55 8E F0            [24] 5336 	mov	b, r6
      001C57 EF               [12] 5337 	mov	a, r7
      001C58 85 10 81         [24] 5338 	mov	sp,_bp
      001C5B D0 10            [24] 5339 	pop	_bp
                           001BA0  5340 	C$sugeno_demo.c$36$1_0$63 ==.
                           001BA0  5341 	XFsugeno_demo$response_idle$0$0 ==.
      001C5D 22               [24] 5342 	ret
                                   5343 ;------------------------------------------------------------
                                   5344 ;Allocation info for local variables in function 'response_economy'
                                   5345 ;------------------------------------------------------------
                                   5346 ;load          Allocated to stack - _bp -6 +4 
                                   5347 ;vibration     Allocated to stack - _bp -10 +4 
                                   5348 ;temperature   Allocated to registers r4 r5 r6 r7 
                                   5349 ;sloc0         Allocated to stack - _bp +1 +4 
                                   5350 ;------------------------------------------------------------
                           001BA1  5351 	Fsugeno_demo$response_economy$0$0 ==.
                           001BA1  5352 	C$sugeno_demo.c$37$1_0$65 ==.
                                   5353 ;	../../sugeno_demo.c:37: static float response_economy(float temperature, float load, float vibration) { return 12.0f + 0.30f * temperature + 0.18f * load + 0.80f * vibration; }
                                   5354 ;	-----------------------------------------
                                   5355 ;	 function response_economy
                                   5356 ;	-----------------------------------------
      001C5E                       5357 _response_economy:
      001C5E C0 10            [24] 5358 	push	_bp
      001C60 85 81 10         [24] 5359 	mov	_bp,sp
      001C63 AC 82            [24] 5360 	mov	r4,dpl
      001C65 AD 83            [24] 5361 	mov	r5,dph
      001C67 AE F0            [24] 5362 	mov	r6,b
      001C69 FF               [12] 5363 	mov	r7,a
      001C6A E5 81            [12] 5364 	mov	a,sp
      001C6C 24 04            [12] 5365 	add	a,#0x04
      001C6E F5 81            [12] 5366 	mov	sp,a
      001C70 C0 04            [24] 5367 	push	ar4
      001C72 C0 05            [24] 5368 	push	ar5
      001C74 C0 06            [24] 5369 	push	ar6
      001C76 C0 07            [24] 5370 	push	ar7
      001C78 90 99 9A         [24] 5371 	mov	dptr,#0x999a
      001C7B 75 F0 99         [24] 5372 	mov	b, #0x99
      001C7E 74 3E            [12] 5373 	mov	a, #0x3e
      001C80 12 2A B5         [24] 5374 	lcall	___fsmul
      001C83 AC 82            [24] 5375 	mov	r4, dpl
      001C85 AD 83            [24] 5376 	mov	r5, dph
      001C87 AE F0            [24] 5377 	mov	r6, b
      001C89 FF               [12] 5378 	mov	r7, a
      001C8A E5 81            [12] 5379 	mov	a,sp
      001C8C 24 FC            [12] 5380 	add	a,#0xfc
      001C8E F5 81            [12] 5381 	mov	sp,a
      001C90 E4               [12] 5382 	clr	a
      001C91 C0 E0            [24] 5383 	push	acc
      001C93 C0 E0            [24] 5384 	push	acc
      001C95 74 40            [12] 5385 	mov	a,#0x40
      001C97 C0 E0            [24] 5386 	push	acc
      001C99 04               [12] 5387 	inc	a
      001C9A C0 E0            [24] 5388 	push	acc
      001C9C 8C 82            [24] 5389 	mov	dpl, r4
      001C9E 8D 83            [24] 5390 	mov	dph, r5
      001CA0 8E F0            [24] 5391 	mov	b, r6
      001CA2 EF               [12] 5392 	mov	a, r7
      001CA3 12 2C 15         [24] 5393 	lcall	___fsadd
      001CA6 A8 10            [24] 5394 	mov	r0,_bp
      001CA8 08               [12] 5395 	inc	r0
      001CA9 A6 82            [24] 5396 	mov	@r0, dpl
      001CAB 08               [12] 5397 	inc	r0
      001CAC A6 83            [24] 5398 	mov	@r0, dph
      001CAE 08               [12] 5399 	inc	r0
      001CAF A6 F0            [24] 5400 	mov	@r0, b
      001CB1 08               [12] 5401 	inc	r0
      001CB2 F6               [12] 5402 	mov	@r0,a
      001CB3 E5 81            [12] 5403 	mov	a,sp
      001CB5 24 FC            [12] 5404 	add	a,#0xfc
      001CB7 F5 81            [12] 5405 	mov	sp,a
      001CB9 E5 10            [12] 5406 	mov	a,_bp
      001CBB 24 FA            [12] 5407 	add	a,#0xfa
      001CBD F8               [12] 5408 	mov	r0,a
      001CBE E6               [12] 5409 	mov	a,@r0
      001CBF C0 E0            [24] 5410 	push	acc
      001CC1 08               [12] 5411 	inc	r0
      001CC2 E6               [12] 5412 	mov	a,@r0
      001CC3 C0 E0            [24] 5413 	push	acc
      001CC5 08               [12] 5414 	inc	r0
      001CC6 E6               [12] 5415 	mov	a,@r0
      001CC7 C0 E0            [24] 5416 	push	acc
      001CC9 08               [12] 5417 	inc	r0
      001CCA E6               [12] 5418 	mov	a,@r0
      001CCB C0 E0            [24] 5419 	push	acc
      001CCD 90 51 EC         [24] 5420 	mov	dptr,#0x51ec
      001CD0 75 F0 38         [24] 5421 	mov	b, #0x38
      001CD3 74 3E            [12] 5422 	mov	a, #0x3e
      001CD5 12 2A B5         [24] 5423 	lcall	___fsmul
      001CD8 AA 82            [24] 5424 	mov	r2, dpl
      001CDA AB 83            [24] 5425 	mov	r3, dph
      001CDC AE F0            [24] 5426 	mov	r6, b
      001CDE FF               [12] 5427 	mov	r7, a
      001CDF E5 81            [12] 5428 	mov	a,sp
      001CE1 24 FC            [12] 5429 	add	a,#0xfc
      001CE3 F5 81            [12] 5430 	mov	sp,a
      001CE5 C0 02            [24] 5431 	push	ar2
      001CE7 C0 03            [24] 5432 	push	ar3
      001CE9 C0 06            [24] 5433 	push	ar6
      001CEB C0 07            [24] 5434 	push	ar7
      001CED A8 10            [24] 5435 	mov	r0,_bp
      001CEF 08               [12] 5436 	inc	r0
      001CF0 86 82            [24] 5437 	mov	dpl, @r0
      001CF2 08               [12] 5438 	inc	r0
      001CF3 86 83            [24] 5439 	mov	dph, @r0
      001CF5 08               [12] 5440 	inc	r0
      001CF6 86 F0            [24] 5441 	mov	b, @r0
      001CF8 08               [12] 5442 	inc	r0
      001CF9 E6               [12] 5443 	mov	a, @r0
      001CFA 12 2C 15         [24] 5444 	lcall	___fsadd
      001CFD A8 10            [24] 5445 	mov	r0,_bp
      001CFF 08               [12] 5446 	inc	r0
      001D00 A6 82            [24] 5447 	mov	@r0, dpl
      001D02 08               [12] 5448 	inc	r0
      001D03 A6 83            [24] 5449 	mov	@r0, dph
      001D05 08               [12] 5450 	inc	r0
      001D06 A6 F0            [24] 5451 	mov	@r0, b
      001D08 08               [12] 5452 	inc	r0
      001D09 F6               [12] 5453 	mov	@r0,a
      001D0A E5 81            [12] 5454 	mov	a,sp
      001D0C 24 FC            [12] 5455 	add	a,#0xfc
      001D0E F5 81            [12] 5456 	mov	sp,a
      001D10 E5 10            [12] 5457 	mov	a,_bp
      001D12 24 F6            [12] 5458 	add	a,#0xf6
      001D14 F8               [12] 5459 	mov	r0,a
      001D15 E6               [12] 5460 	mov	a,@r0
      001D16 C0 E0            [24] 5461 	push	acc
      001D18 08               [12] 5462 	inc	r0
      001D19 E6               [12] 5463 	mov	a,@r0
      001D1A C0 E0            [24] 5464 	push	acc
      001D1C 08               [12] 5465 	inc	r0
      001D1D E6               [12] 5466 	mov	a,@r0
      001D1E C0 E0            [24] 5467 	push	acc
      001D20 08               [12] 5468 	inc	r0
      001D21 E6               [12] 5469 	mov	a,@r0
      001D22 C0 E0            [24] 5470 	push	acc
      001D24 90 CC CD         [24] 5471 	mov	dptr,#0xcccd
      001D27 75 F0 4C         [24] 5472 	mov	b, #0x4c
      001D2A 74 3F            [12] 5473 	mov	a, #0x3f
      001D2C 12 2A B5         [24] 5474 	lcall	___fsmul
      001D2F AA 82            [24] 5475 	mov	r2, dpl
      001D31 AB 83            [24] 5476 	mov	r3, dph
      001D33 AE F0            [24] 5477 	mov	r6, b
      001D35 FF               [12] 5478 	mov	r7, a
      001D36 E5 81            [12] 5479 	mov	a,sp
      001D38 24 FC            [12] 5480 	add	a,#0xfc
      001D3A F5 81            [12] 5481 	mov	sp,a
      001D3C C0 02            [24] 5482 	push	ar2
      001D3E C0 03            [24] 5483 	push	ar3
      001D40 C0 06            [24] 5484 	push	ar6
      001D42 C0 07            [24] 5485 	push	ar7
      001D44 A8 10            [24] 5486 	mov	r0,_bp
      001D46 08               [12] 5487 	inc	r0
      001D47 86 82            [24] 5488 	mov	dpl, @r0
      001D49 08               [12] 5489 	inc	r0
      001D4A 86 83            [24] 5490 	mov	dph, @r0
      001D4C 08               [12] 5491 	inc	r0
      001D4D 86 F0            [24] 5492 	mov	b, @r0
      001D4F 08               [12] 5493 	inc	r0
      001D50 E6               [12] 5494 	mov	a, @r0
      001D51 12 2C 15         [24] 5495 	lcall	___fsadd
      001D54 AC 82            [24] 5496 	mov	r4, dpl
      001D56 AD 83            [24] 5497 	mov	r5, dph
      001D58 AE F0            [24] 5498 	mov	r6, b
      001D5A FF               [12] 5499 	mov	r7, a
      001D5B E5 81            [12] 5500 	mov	a,sp
      001D5D 24 FC            [12] 5501 	add	a,#0xfc
      001D5F F5 81            [12] 5502 	mov	sp,a
      001D61 8C 82            [24] 5503 	mov	dpl, r4
      001D63 8D 83            [24] 5504 	mov	dph, r5
      001D65 8E F0            [24] 5505 	mov	b, r6
      001D67 EF               [12] 5506 	mov	a, r7
      001D68 85 10 81         [24] 5507 	mov	sp,_bp
      001D6B D0 10            [24] 5508 	pop	_bp
                           001CB0  5509 	C$sugeno_demo.c$37$1_0$65 ==.
                           001CB0  5510 	XFsugeno_demo$response_economy$0$0 ==.
      001D6D 22               [24] 5511 	ret
                                   5512 ;------------------------------------------------------------
                                   5513 ;Allocation info for local variables in function 'response_balanced'
                                   5514 ;------------------------------------------------------------
                                   5515 ;load          Allocated to stack - _bp -6 +4 
                                   5516 ;vibration     Allocated to stack - _bp -10 +4 
                                   5517 ;temperature   Allocated to registers r4 r5 r6 r7 
                                   5518 ;sloc0         Allocated to stack - _bp +1 +4 
                                   5519 ;------------------------------------------------------------
                           001CB1  5520 	Fsugeno_demo$response_balanced$0$0 ==.
                           001CB1  5521 	C$sugeno_demo.c$38$1_0$67 ==.
                                   5522 ;	../../sugeno_demo.c:38: static float response_balanced(float temperature, float load, float vibration) { return 15.0f + 0.42f * temperature + 0.25f * load + 1.20f * vibration; }
                                   5523 ;	-----------------------------------------
                                   5524 ;	 function response_balanced
                                   5525 ;	-----------------------------------------
      001D6E                       5526 _response_balanced:
      001D6E C0 10            [24] 5527 	push	_bp
      001D70 85 81 10         [24] 5528 	mov	_bp,sp
      001D73 AC 82            [24] 5529 	mov	r4,dpl
      001D75 AD 83            [24] 5530 	mov	r5,dph
      001D77 AE F0            [24] 5531 	mov	r6,b
      001D79 FF               [12] 5532 	mov	r7,a
      001D7A E5 81            [12] 5533 	mov	a,sp
      001D7C 24 04            [12] 5534 	add	a,#0x04
      001D7E F5 81            [12] 5535 	mov	sp,a
      001D80 C0 04            [24] 5536 	push	ar4
      001D82 C0 05            [24] 5537 	push	ar5
      001D84 C0 06            [24] 5538 	push	ar6
      001D86 C0 07            [24] 5539 	push	ar7
      001D88 90 0A 3D         [24] 5540 	mov	dptr,#0x0a3d
      001D8B 75 F0 D7         [24] 5541 	mov	b, #0xd7
      001D8E 74 3E            [12] 5542 	mov	a, #0x3e
      001D90 12 2A B5         [24] 5543 	lcall	___fsmul
      001D93 AC 82            [24] 5544 	mov	r4, dpl
      001D95 AD 83            [24] 5545 	mov	r5, dph
      001D97 AE F0            [24] 5546 	mov	r6, b
      001D99 FF               [12] 5547 	mov	r7, a
      001D9A E5 81            [12] 5548 	mov	a,sp
      001D9C 24 FC            [12] 5549 	add	a,#0xfc
      001D9E F5 81            [12] 5550 	mov	sp,a
      001DA0 E4               [12] 5551 	clr	a
      001DA1 C0 E0            [24] 5552 	push	acc
      001DA3 C0 E0            [24] 5553 	push	acc
      001DA5 74 70            [12] 5554 	mov	a,#0x70
      001DA7 C0 E0            [24] 5555 	push	acc
      001DA9 74 41            [12] 5556 	mov	a,#0x41
      001DAB C0 E0            [24] 5557 	push	acc
      001DAD 8C 82            [24] 5558 	mov	dpl, r4
      001DAF 8D 83            [24] 5559 	mov	dph, r5
      001DB1 8E F0            [24] 5560 	mov	b, r6
      001DB3 EF               [12] 5561 	mov	a, r7
      001DB4 12 2C 15         [24] 5562 	lcall	___fsadd
      001DB7 A8 10            [24] 5563 	mov	r0,_bp
      001DB9 08               [12] 5564 	inc	r0
      001DBA A6 82            [24] 5565 	mov	@r0, dpl
      001DBC 08               [12] 5566 	inc	r0
      001DBD A6 83            [24] 5567 	mov	@r0, dph
      001DBF 08               [12] 5568 	inc	r0
      001DC0 A6 F0            [24] 5569 	mov	@r0, b
      001DC2 08               [12] 5570 	inc	r0
      001DC3 F6               [12] 5571 	mov	@r0,a
      001DC4 E5 81            [12] 5572 	mov	a,sp
      001DC6 24 FC            [12] 5573 	add	a,#0xfc
      001DC8 F5 81            [12] 5574 	mov	sp,a
      001DCA E5 10            [12] 5575 	mov	a,_bp
      001DCC 24 FA            [12] 5576 	add	a,#0xfa
      001DCE F8               [12] 5577 	mov	r0,a
      001DCF E6               [12] 5578 	mov	a,@r0
      001DD0 C0 E0            [24] 5579 	push	acc
      001DD2 08               [12] 5580 	inc	r0
      001DD3 E6               [12] 5581 	mov	a,@r0
      001DD4 C0 E0            [24] 5582 	push	acc
      001DD6 08               [12] 5583 	inc	r0
      001DD7 E6               [12] 5584 	mov	a,@r0
      001DD8 C0 E0            [24] 5585 	push	acc
      001DDA 08               [12] 5586 	inc	r0
      001DDB E6               [12] 5587 	mov	a,@r0
      001DDC C0 E0            [24] 5588 	push	acc
      001DDE 90 00 00         [24] 5589 	mov	dptr,#0x0000
      001DE1 75 F0 80         [24] 5590 	mov	b, #0x80
      001DE4 74 3E            [12] 5591 	mov	a, #0x3e
      001DE6 12 2A B5         [24] 5592 	lcall	___fsmul
      001DE9 AA 82            [24] 5593 	mov	r2, dpl
      001DEB AB 83            [24] 5594 	mov	r3, dph
      001DED AE F0            [24] 5595 	mov	r6, b
      001DEF FF               [12] 5596 	mov	r7, a
      001DF0 E5 81            [12] 5597 	mov	a,sp
      001DF2 24 FC            [12] 5598 	add	a,#0xfc
      001DF4 F5 81            [12] 5599 	mov	sp,a
      001DF6 C0 02            [24] 5600 	push	ar2
      001DF8 C0 03            [24] 5601 	push	ar3
      001DFA C0 06            [24] 5602 	push	ar6
      001DFC C0 07            [24] 5603 	push	ar7
      001DFE A8 10            [24] 5604 	mov	r0,_bp
      001E00 08               [12] 5605 	inc	r0
      001E01 86 82            [24] 5606 	mov	dpl, @r0
      001E03 08               [12] 5607 	inc	r0
      001E04 86 83            [24] 5608 	mov	dph, @r0
      001E06 08               [12] 5609 	inc	r0
      001E07 86 F0            [24] 5610 	mov	b, @r0
      001E09 08               [12] 5611 	inc	r0
      001E0A E6               [12] 5612 	mov	a, @r0
      001E0B 12 2C 15         [24] 5613 	lcall	___fsadd
      001E0E A8 10            [24] 5614 	mov	r0,_bp
      001E10 08               [12] 5615 	inc	r0
      001E11 A6 82            [24] 5616 	mov	@r0, dpl
      001E13 08               [12] 5617 	inc	r0
      001E14 A6 83            [24] 5618 	mov	@r0, dph
      001E16 08               [12] 5619 	inc	r0
      001E17 A6 F0            [24] 5620 	mov	@r0, b
      001E19 08               [12] 5621 	inc	r0
      001E1A F6               [12] 5622 	mov	@r0,a
      001E1B E5 81            [12] 5623 	mov	a,sp
      001E1D 24 FC            [12] 5624 	add	a,#0xfc
      001E1F F5 81            [12] 5625 	mov	sp,a
      001E21 E5 10            [12] 5626 	mov	a,_bp
      001E23 24 F6            [12] 5627 	add	a,#0xf6
      001E25 F8               [12] 5628 	mov	r0,a
      001E26 E6               [12] 5629 	mov	a,@r0
      001E27 C0 E0            [24] 5630 	push	acc
      001E29 08               [12] 5631 	inc	r0
      001E2A E6               [12] 5632 	mov	a,@r0
      001E2B C0 E0            [24] 5633 	push	acc
      001E2D 08               [12] 5634 	inc	r0
      001E2E E6               [12] 5635 	mov	a,@r0
      001E2F C0 E0            [24] 5636 	push	acc
      001E31 08               [12] 5637 	inc	r0
      001E32 E6               [12] 5638 	mov	a,@r0
      001E33 C0 E0            [24] 5639 	push	acc
      001E35 90 99 9A         [24] 5640 	mov	dptr,#0x999a
      001E38 75 F0 99         [24] 5641 	mov	b, #0x99
      001E3B 74 3F            [12] 5642 	mov	a, #0x3f
      001E3D 12 2A B5         [24] 5643 	lcall	___fsmul
      001E40 AA 82            [24] 5644 	mov	r2, dpl
      001E42 AB 83            [24] 5645 	mov	r3, dph
      001E44 AE F0            [24] 5646 	mov	r6, b
      001E46 FF               [12] 5647 	mov	r7, a
      001E47 E5 81            [12] 5648 	mov	a,sp
      001E49 24 FC            [12] 5649 	add	a,#0xfc
      001E4B F5 81            [12] 5650 	mov	sp,a
      001E4D C0 02            [24] 5651 	push	ar2
      001E4F C0 03            [24] 5652 	push	ar3
      001E51 C0 06            [24] 5653 	push	ar6
      001E53 C0 07            [24] 5654 	push	ar7
      001E55 A8 10            [24] 5655 	mov	r0,_bp
      001E57 08               [12] 5656 	inc	r0
      001E58 86 82            [24] 5657 	mov	dpl, @r0
      001E5A 08               [12] 5658 	inc	r0
      001E5B 86 83            [24] 5659 	mov	dph, @r0
      001E5D 08               [12] 5660 	inc	r0
      001E5E 86 F0            [24] 5661 	mov	b, @r0
      001E60 08               [12] 5662 	inc	r0
      001E61 E6               [12] 5663 	mov	a, @r0
      001E62 12 2C 15         [24] 5664 	lcall	___fsadd
      001E65 AC 82            [24] 5665 	mov	r4, dpl
      001E67 AD 83            [24] 5666 	mov	r5, dph
      001E69 AE F0            [24] 5667 	mov	r6, b
      001E6B FF               [12] 5668 	mov	r7, a
      001E6C E5 81            [12] 5669 	mov	a,sp
      001E6E 24 FC            [12] 5670 	add	a,#0xfc
      001E70 F5 81            [12] 5671 	mov	sp,a
      001E72 8C 82            [24] 5672 	mov	dpl, r4
      001E74 8D 83            [24] 5673 	mov	dph, r5
      001E76 8E F0            [24] 5674 	mov	b, r6
      001E78 EF               [12] 5675 	mov	a, r7
      001E79 85 10 81         [24] 5676 	mov	sp,_bp
      001E7C D0 10            [24] 5677 	pop	_bp
                           001DC1  5678 	C$sugeno_demo.c$38$1_0$67 ==.
                           001DC1  5679 	XFsugeno_demo$response_balanced$0$0 ==.
      001E7E 22               [24] 5680 	ret
                                   5681 ;------------------------------------------------------------
                                   5682 ;Allocation info for local variables in function 'response_cooling'
                                   5683 ;------------------------------------------------------------
                                   5684 ;load          Allocated to stack - _bp -6 +4 
                                   5685 ;vibration     Allocated to stack - _bp -10 +4 
                                   5686 ;temperature   Allocated to registers r4 r5 r6 r7 
                                   5687 ;sloc0         Allocated to stack - _bp +1 +4 
                                   5688 ;------------------------------------------------------------
                           001DC2  5689 	Fsugeno_demo$response_cooling$0$0 ==.
                           001DC2  5690 	C$sugeno_demo.c$39$1_0$69 ==.
                                   5691 ;	../../sugeno_demo.c:39: static float response_cooling(float temperature, float load, float vibration) { return 20.0f + 0.65f * temperature + 0.12f * load + 1.50f * vibration; }
                                   5692 ;	-----------------------------------------
                                   5693 ;	 function response_cooling
                                   5694 ;	-----------------------------------------
      001E7F                       5695 _response_cooling:
      001E7F C0 10            [24] 5696 	push	_bp
      001E81 85 81 10         [24] 5697 	mov	_bp,sp
      001E84 AC 82            [24] 5698 	mov	r4,dpl
      001E86 AD 83            [24] 5699 	mov	r5,dph
      001E88 AE F0            [24] 5700 	mov	r6,b
      001E8A FF               [12] 5701 	mov	r7,a
      001E8B E5 81            [12] 5702 	mov	a,sp
      001E8D 24 04            [12] 5703 	add	a,#0x04
      001E8F F5 81            [12] 5704 	mov	sp,a
      001E91 C0 04            [24] 5705 	push	ar4
      001E93 C0 05            [24] 5706 	push	ar5
      001E95 C0 06            [24] 5707 	push	ar6
      001E97 C0 07            [24] 5708 	push	ar7
      001E99 90 66 66         [24] 5709 	mov	dptr,#0x6666
      001E9C 75 F0 26         [24] 5710 	mov	b, #0x26
      001E9F 74 3F            [12] 5711 	mov	a, #0x3f
      001EA1 12 2A B5         [24] 5712 	lcall	___fsmul
      001EA4 AC 82            [24] 5713 	mov	r4, dpl
      001EA6 AD 83            [24] 5714 	mov	r5, dph
      001EA8 AE F0            [24] 5715 	mov	r6, b
      001EAA FF               [12] 5716 	mov	r7, a
      001EAB E5 81            [12] 5717 	mov	a,sp
      001EAD 24 FC            [12] 5718 	add	a,#0xfc
      001EAF F5 81            [12] 5719 	mov	sp,a
      001EB1 E4               [12] 5720 	clr	a
      001EB2 C0 E0            [24] 5721 	push	acc
      001EB4 C0 E0            [24] 5722 	push	acc
      001EB6 74 A0            [12] 5723 	mov	a,#0xa0
      001EB8 C0 E0            [24] 5724 	push	acc
      001EBA 23               [12] 5725 	rl	a
      001EBB C0 E0            [24] 5726 	push	acc
      001EBD 8C 82            [24] 5727 	mov	dpl, r4
      001EBF 8D 83            [24] 5728 	mov	dph, r5
      001EC1 8E F0            [24] 5729 	mov	b, r6
      001EC3 EF               [12] 5730 	mov	a, r7
      001EC4 12 2C 15         [24] 5731 	lcall	___fsadd
      001EC7 A8 10            [24] 5732 	mov	r0,_bp
      001EC9 08               [12] 5733 	inc	r0
      001ECA A6 82            [24] 5734 	mov	@r0, dpl
      001ECC 08               [12] 5735 	inc	r0
      001ECD A6 83            [24] 5736 	mov	@r0, dph
      001ECF 08               [12] 5737 	inc	r0
      001ED0 A6 F0            [24] 5738 	mov	@r0, b
      001ED2 08               [12] 5739 	inc	r0
      001ED3 F6               [12] 5740 	mov	@r0,a
      001ED4 E5 81            [12] 5741 	mov	a,sp
      001ED6 24 FC            [12] 5742 	add	a,#0xfc
      001ED8 F5 81            [12] 5743 	mov	sp,a
      001EDA E5 10            [12] 5744 	mov	a,_bp
      001EDC 24 FA            [12] 5745 	add	a,#0xfa
      001EDE F8               [12] 5746 	mov	r0,a
      001EDF E6               [12] 5747 	mov	a,@r0
      001EE0 C0 E0            [24] 5748 	push	acc
      001EE2 08               [12] 5749 	inc	r0
      001EE3 E6               [12] 5750 	mov	a,@r0
      001EE4 C0 E0            [24] 5751 	push	acc
      001EE6 08               [12] 5752 	inc	r0
      001EE7 E6               [12] 5753 	mov	a,@r0
      001EE8 C0 E0            [24] 5754 	push	acc
      001EEA 08               [12] 5755 	inc	r0
      001EEB E6               [12] 5756 	mov	a,@r0
      001EEC C0 E0            [24] 5757 	push	acc
      001EEE 90 C2 8F         [24] 5758 	mov	dptr,#0xc28f
      001EF1 75 F0 F5         [24] 5759 	mov	b, #0xf5
      001EF4 74 3D            [12] 5760 	mov	a, #0x3d
      001EF6 12 2A B5         [24] 5761 	lcall	___fsmul
      001EF9 AA 82            [24] 5762 	mov	r2, dpl
      001EFB AB 83            [24] 5763 	mov	r3, dph
      001EFD AE F0            [24] 5764 	mov	r6, b
      001EFF FF               [12] 5765 	mov	r7, a
      001F00 E5 81            [12] 5766 	mov	a,sp
      001F02 24 FC            [12] 5767 	add	a,#0xfc
      001F04 F5 81            [12] 5768 	mov	sp,a
      001F06 C0 02            [24] 5769 	push	ar2
      001F08 C0 03            [24] 5770 	push	ar3
      001F0A C0 06            [24] 5771 	push	ar6
      001F0C C0 07            [24] 5772 	push	ar7
      001F0E A8 10            [24] 5773 	mov	r0,_bp
      001F10 08               [12] 5774 	inc	r0
      001F11 86 82            [24] 5775 	mov	dpl, @r0
      001F13 08               [12] 5776 	inc	r0
      001F14 86 83            [24] 5777 	mov	dph, @r0
      001F16 08               [12] 5778 	inc	r0
      001F17 86 F0            [24] 5779 	mov	b, @r0
      001F19 08               [12] 5780 	inc	r0
      001F1A E6               [12] 5781 	mov	a, @r0
      001F1B 12 2C 15         [24] 5782 	lcall	___fsadd
      001F1E A8 10            [24] 5783 	mov	r0,_bp
      001F20 08               [12] 5784 	inc	r0
      001F21 A6 82            [24] 5785 	mov	@r0, dpl
      001F23 08               [12] 5786 	inc	r0
      001F24 A6 83            [24] 5787 	mov	@r0, dph
      001F26 08               [12] 5788 	inc	r0
      001F27 A6 F0            [24] 5789 	mov	@r0, b
      001F29 08               [12] 5790 	inc	r0
      001F2A F6               [12] 5791 	mov	@r0,a
      001F2B E5 81            [12] 5792 	mov	a,sp
      001F2D 24 FC            [12] 5793 	add	a,#0xfc
      001F2F F5 81            [12] 5794 	mov	sp,a
      001F31 E5 10            [12] 5795 	mov	a,_bp
      001F33 24 F6            [12] 5796 	add	a,#0xf6
      001F35 F8               [12] 5797 	mov	r0,a
      001F36 E6               [12] 5798 	mov	a,@r0
      001F37 C0 E0            [24] 5799 	push	acc
      001F39 08               [12] 5800 	inc	r0
      001F3A E6               [12] 5801 	mov	a,@r0
      001F3B C0 E0            [24] 5802 	push	acc
      001F3D 08               [12] 5803 	inc	r0
      001F3E E6               [12] 5804 	mov	a,@r0
      001F3F C0 E0            [24] 5805 	push	acc
      001F41 08               [12] 5806 	inc	r0
      001F42 E6               [12] 5807 	mov	a,@r0
      001F43 C0 E0            [24] 5808 	push	acc
      001F45 90 00 00         [24] 5809 	mov	dptr,#0x0000
      001F48 75 F0 C0         [24] 5810 	mov	b, #0xc0
      001F4B 74 3F            [12] 5811 	mov	a, #0x3f
      001F4D 12 2A B5         [24] 5812 	lcall	___fsmul
      001F50 AA 82            [24] 5813 	mov	r2, dpl
      001F52 AB 83            [24] 5814 	mov	r3, dph
      001F54 AE F0            [24] 5815 	mov	r6, b
      001F56 FF               [12] 5816 	mov	r7, a
      001F57 E5 81            [12] 5817 	mov	a,sp
      001F59 24 FC            [12] 5818 	add	a,#0xfc
      001F5B F5 81            [12] 5819 	mov	sp,a
      001F5D C0 02            [24] 5820 	push	ar2
      001F5F C0 03            [24] 5821 	push	ar3
      001F61 C0 06            [24] 5822 	push	ar6
      001F63 C0 07            [24] 5823 	push	ar7
      001F65 A8 10            [24] 5824 	mov	r0,_bp
      001F67 08               [12] 5825 	inc	r0
      001F68 86 82            [24] 5826 	mov	dpl, @r0
      001F6A 08               [12] 5827 	inc	r0
      001F6B 86 83            [24] 5828 	mov	dph, @r0
      001F6D 08               [12] 5829 	inc	r0
      001F6E 86 F0            [24] 5830 	mov	b, @r0
      001F70 08               [12] 5831 	inc	r0
      001F71 E6               [12] 5832 	mov	a, @r0
      001F72 12 2C 15         [24] 5833 	lcall	___fsadd
      001F75 AC 82            [24] 5834 	mov	r4, dpl
      001F77 AD 83            [24] 5835 	mov	r5, dph
      001F79 AE F0            [24] 5836 	mov	r6, b
      001F7B FF               [12] 5837 	mov	r7, a
      001F7C E5 81            [12] 5838 	mov	a,sp
      001F7E 24 FC            [12] 5839 	add	a,#0xfc
      001F80 F5 81            [12] 5840 	mov	sp,a
      001F82 8C 82            [24] 5841 	mov	dpl, r4
      001F84 8D 83            [24] 5842 	mov	dph, r5
      001F86 8E F0            [24] 5843 	mov	b, r6
      001F88 EF               [12] 5844 	mov	a, r7
      001F89 85 10 81         [24] 5845 	mov	sp,_bp
      001F8C D0 10            [24] 5846 	pop	_bp
                           001ED1  5847 	C$sugeno_demo.c$39$1_0$69 ==.
                           001ED1  5848 	XFsugeno_demo$response_cooling$0$0 ==.
      001F8E 22               [24] 5849 	ret
                                   5850 ;------------------------------------------------------------
                                   5851 ;Allocation info for local variables in function 'response_heavy_load'
                                   5852 ;------------------------------------------------------------
                                   5853 ;load          Allocated to stack - _bp -6 +4 
                                   5854 ;vibration     Allocated to stack - _bp -10 +4 
                                   5855 ;temperature   Allocated to registers r4 r5 r6 r7 
                                   5856 ;sloc0         Allocated to stack - _bp +1 +4 
                                   5857 ;------------------------------------------------------------
                           001ED2  5858 	Fsugeno_demo$response_heavy_load$0$0 ==.
                           001ED2  5859 	C$sugeno_demo.c$40$1_0$71 ==.
                                   5860 ;	../../sugeno_demo.c:40: static float response_heavy_load(float temperature, float load, float vibration) { return 18.0f + 0.30f * temperature + 0.55f * load + 1.00f * vibration; }
                                   5861 ;	-----------------------------------------
                                   5862 ;	 function response_heavy_load
                                   5863 ;	-----------------------------------------
      001F8F                       5864 _response_heavy_load:
      001F8F C0 10            [24] 5865 	push	_bp
      001F91 85 81 10         [24] 5866 	mov	_bp,sp
      001F94 AC 82            [24] 5867 	mov	r4,dpl
      001F96 AD 83            [24] 5868 	mov	r5,dph
      001F98 AE F0            [24] 5869 	mov	r6,b
      001F9A FF               [12] 5870 	mov	r7,a
      001F9B E5 81            [12] 5871 	mov	a,sp
      001F9D 24 04            [12] 5872 	add	a,#0x04
      001F9F F5 81            [12] 5873 	mov	sp,a
      001FA1 C0 04            [24] 5874 	push	ar4
      001FA3 C0 05            [24] 5875 	push	ar5
      001FA5 C0 06            [24] 5876 	push	ar6
      001FA7 C0 07            [24] 5877 	push	ar7
      001FA9 90 99 9A         [24] 5878 	mov	dptr,#0x999a
      001FAC 75 F0 99         [24] 5879 	mov	b, #0x99
      001FAF 74 3E            [12] 5880 	mov	a, #0x3e
      001FB1 12 2A B5         [24] 5881 	lcall	___fsmul
      001FB4 AC 82            [24] 5882 	mov	r4, dpl
      001FB6 AD 83            [24] 5883 	mov	r5, dph
      001FB8 AE F0            [24] 5884 	mov	r6, b
      001FBA FF               [12] 5885 	mov	r7, a
      001FBB E5 81            [12] 5886 	mov	a,sp
      001FBD 24 FC            [12] 5887 	add	a,#0xfc
      001FBF F5 81            [12] 5888 	mov	sp,a
      001FC1 E4               [12] 5889 	clr	a
      001FC2 C0 E0            [24] 5890 	push	acc
      001FC4 C0 E0            [24] 5891 	push	acc
      001FC6 74 90            [12] 5892 	mov	a,#0x90
      001FC8 C0 E0            [24] 5893 	push	acc
      001FCA 74 41            [12] 5894 	mov	a,#0x41
      001FCC C0 E0            [24] 5895 	push	acc
      001FCE 8C 82            [24] 5896 	mov	dpl, r4
      001FD0 8D 83            [24] 5897 	mov	dph, r5
      001FD2 8E F0            [24] 5898 	mov	b, r6
      001FD4 EF               [12] 5899 	mov	a, r7
      001FD5 12 2C 15         [24] 5900 	lcall	___fsadd
      001FD8 A8 10            [24] 5901 	mov	r0,_bp
      001FDA 08               [12] 5902 	inc	r0
      001FDB A6 82            [24] 5903 	mov	@r0, dpl
      001FDD 08               [12] 5904 	inc	r0
      001FDE A6 83            [24] 5905 	mov	@r0, dph
      001FE0 08               [12] 5906 	inc	r0
      001FE1 A6 F0            [24] 5907 	mov	@r0, b
      001FE3 08               [12] 5908 	inc	r0
      001FE4 F6               [12] 5909 	mov	@r0,a
      001FE5 E5 81            [12] 5910 	mov	a,sp
      001FE7 24 FC            [12] 5911 	add	a,#0xfc
      001FE9 F5 81            [12] 5912 	mov	sp,a
      001FEB E5 10            [12] 5913 	mov	a,_bp
      001FED 24 FA            [12] 5914 	add	a,#0xfa
      001FEF F8               [12] 5915 	mov	r0,a
      001FF0 E6               [12] 5916 	mov	a,@r0
      001FF1 C0 E0            [24] 5917 	push	acc
      001FF3 08               [12] 5918 	inc	r0
      001FF4 E6               [12] 5919 	mov	a,@r0
      001FF5 C0 E0            [24] 5920 	push	acc
      001FF7 08               [12] 5921 	inc	r0
      001FF8 E6               [12] 5922 	mov	a,@r0
      001FF9 C0 E0            [24] 5923 	push	acc
      001FFB 08               [12] 5924 	inc	r0
      001FFC E6               [12] 5925 	mov	a,@r0
      001FFD C0 E0            [24] 5926 	push	acc
      001FFF 90 CC CD         [24] 5927 	mov	dptr,#0xcccd
      002002 75 F0 0C         [24] 5928 	mov	b, #0x0c
      002005 74 3F            [12] 5929 	mov	a, #0x3f
      002007 12 2A B5         [24] 5930 	lcall	___fsmul
      00200A AA 82            [24] 5931 	mov	r2, dpl
      00200C AB 83            [24] 5932 	mov	r3, dph
      00200E AE F0            [24] 5933 	mov	r6, b
      002010 FF               [12] 5934 	mov	r7, a
      002011 E5 81            [12] 5935 	mov	a,sp
      002013 24 FC            [12] 5936 	add	a,#0xfc
      002015 F5 81            [12] 5937 	mov	sp,a
      002017 C0 02            [24] 5938 	push	ar2
      002019 C0 03            [24] 5939 	push	ar3
      00201B C0 06            [24] 5940 	push	ar6
      00201D C0 07            [24] 5941 	push	ar7
      00201F A8 10            [24] 5942 	mov	r0,_bp
      002021 08               [12] 5943 	inc	r0
      002022 86 82            [24] 5944 	mov	dpl, @r0
      002024 08               [12] 5945 	inc	r0
      002025 86 83            [24] 5946 	mov	dph, @r0
      002027 08               [12] 5947 	inc	r0
      002028 86 F0            [24] 5948 	mov	b, @r0
      00202A 08               [12] 5949 	inc	r0
      00202B E6               [12] 5950 	mov	a, @r0
      00202C 12 2C 15         [24] 5951 	lcall	___fsadd
      00202F AC 82            [24] 5952 	mov	r4, dpl
      002031 AD 83            [24] 5953 	mov	r5, dph
      002033 AE F0            [24] 5954 	mov	r6, b
      002035 FF               [12] 5955 	mov	r7, a
      002036 E5 81            [12] 5956 	mov	a,sp
      002038 24 FC            [12] 5957 	add	a,#0xfc
      00203A F5 81            [12] 5958 	mov	sp,a
      00203C E5 10            [12] 5959 	mov	a,_bp
      00203E 24 F6            [12] 5960 	add	a,#0xf6
      002040 F8               [12] 5961 	mov	r0,a
      002041 E6               [12] 5962 	mov	a,@r0
      002042 C0 E0            [24] 5963 	push	acc
      002044 08               [12] 5964 	inc	r0
      002045 E6               [12] 5965 	mov	a,@r0
      002046 C0 E0            [24] 5966 	push	acc
      002048 08               [12] 5967 	inc	r0
      002049 E6               [12] 5968 	mov	a,@r0
      00204A C0 E0            [24] 5969 	push	acc
      00204C 08               [12] 5970 	inc	r0
      00204D E6               [12] 5971 	mov	a,@r0
      00204E C0 E0            [24] 5972 	push	acc
      002050 8C 82            [24] 5973 	mov	dpl, r4
      002052 8D 83            [24] 5974 	mov	dph, r5
      002054 8E F0            [24] 5975 	mov	b, r6
      002056 EF               [12] 5976 	mov	a, r7
      002057 12 2C 15         [24] 5977 	lcall	___fsadd
      00205A AC 82            [24] 5978 	mov	r4, dpl
      00205C AD 83            [24] 5979 	mov	r5, dph
      00205E AE F0            [24] 5980 	mov	r6, b
      002060 FF               [12] 5981 	mov	r7, a
      002061 E5 81            [12] 5982 	mov	a,sp
      002063 24 FC            [12] 5983 	add	a,#0xfc
      002065 F5 81            [12] 5984 	mov	sp,a
      002067 8C 82            [24] 5985 	mov	dpl, r4
      002069 8D 83            [24] 5986 	mov	dph, r5
      00206B 8E F0            [24] 5987 	mov	b, r6
      00206D EF               [12] 5988 	mov	a, r7
      00206E 85 10 81         [24] 5989 	mov	sp,_bp
      002071 D0 10            [24] 5990 	pop	_bp
                           001FB6  5991 	C$sugeno_demo.c$40$1_0$71 ==.
                           001FB6  5992 	XFsugeno_demo$response_heavy_load$0$0 ==.
      002073 22               [24] 5993 	ret
                                   5994 ;------------------------------------------------------------
                                   5995 ;Allocation info for local variables in function 'response_protection'
                                   5996 ;------------------------------------------------------------
                                   5997 ;load          Allocated to stack - _bp -6 +4 
                                   5998 ;vibration     Allocated to stack - _bp -10 +4 
                                   5999 ;temperature   Allocated to registers r4 r5 r6 r7 
                                   6000 ;sloc0         Allocated to stack - _bp +1 +4 
                                   6001 ;------------------------------------------------------------
                           001FB7  6002 	Fsugeno_demo$response_protection$0$0 ==.
                           001FB7  6003 	C$sugeno_demo.c$41$1_0$73 ==.
                                   6004 ;	../../sugeno_demo.c:41: static float response_protection(float temperature, float load, float vibration) { return 35.0f + 0.45f * temperature + 0.30f * load + 2.50f * vibration; }
                                   6005 ;	-----------------------------------------
                                   6006 ;	 function response_protection
                                   6007 ;	-----------------------------------------
      002074                       6008 _response_protection:
      002074 C0 10            [24] 6009 	push	_bp
      002076 85 81 10         [24] 6010 	mov	_bp,sp
      002079 AC 82            [24] 6011 	mov	r4,dpl
      00207B AD 83            [24] 6012 	mov	r5,dph
      00207D AE F0            [24] 6013 	mov	r6,b
      00207F FF               [12] 6014 	mov	r7,a
      002080 E5 81            [12] 6015 	mov	a,sp
      002082 24 04            [12] 6016 	add	a,#0x04
      002084 F5 81            [12] 6017 	mov	sp,a
      002086 C0 04            [24] 6018 	push	ar4
      002088 C0 05            [24] 6019 	push	ar5
      00208A C0 06            [24] 6020 	push	ar6
      00208C C0 07            [24] 6021 	push	ar7
      00208E 90 66 66         [24] 6022 	mov	dptr,#0x6666
      002091 75 F0 E6         [24] 6023 	mov	b, #0xe6
      002094 74 3E            [12] 6024 	mov	a, #0x3e
      002096 12 2A B5         [24] 6025 	lcall	___fsmul
      002099 AC 82            [24] 6026 	mov	r4, dpl
      00209B AD 83            [24] 6027 	mov	r5, dph
      00209D AE F0            [24] 6028 	mov	r6, b
      00209F FF               [12] 6029 	mov	r7, a
      0020A0 E5 81            [12] 6030 	mov	a,sp
      0020A2 24 FC            [12] 6031 	add	a,#0xfc
      0020A4 F5 81            [12] 6032 	mov	sp,a
      0020A6 E4               [12] 6033 	clr	a
      0020A7 C0 E0            [24] 6034 	push	acc
      0020A9 C0 E0            [24] 6035 	push	acc
      0020AB 74 0C            [12] 6036 	mov	a,#0x0c
      0020AD C0 E0            [24] 6037 	push	acc
      0020AF 74 42            [12] 6038 	mov	a,#0x42
      0020B1 C0 E0            [24] 6039 	push	acc
      0020B3 8C 82            [24] 6040 	mov	dpl, r4
      0020B5 8D 83            [24] 6041 	mov	dph, r5
      0020B7 8E F0            [24] 6042 	mov	b, r6
      0020B9 EF               [12] 6043 	mov	a, r7
      0020BA 12 2C 15         [24] 6044 	lcall	___fsadd
      0020BD A8 10            [24] 6045 	mov	r0,_bp
      0020BF 08               [12] 6046 	inc	r0
      0020C0 A6 82            [24] 6047 	mov	@r0, dpl
      0020C2 08               [12] 6048 	inc	r0
      0020C3 A6 83            [24] 6049 	mov	@r0, dph
      0020C5 08               [12] 6050 	inc	r0
      0020C6 A6 F0            [24] 6051 	mov	@r0, b
      0020C8 08               [12] 6052 	inc	r0
      0020C9 F6               [12] 6053 	mov	@r0,a
      0020CA E5 81            [12] 6054 	mov	a,sp
      0020CC 24 FC            [12] 6055 	add	a,#0xfc
      0020CE F5 81            [12] 6056 	mov	sp,a
      0020D0 E5 10            [12] 6057 	mov	a,_bp
      0020D2 24 FA            [12] 6058 	add	a,#0xfa
      0020D4 F8               [12] 6059 	mov	r0,a
      0020D5 E6               [12] 6060 	mov	a,@r0
      0020D6 C0 E0            [24] 6061 	push	acc
      0020D8 08               [12] 6062 	inc	r0
      0020D9 E6               [12] 6063 	mov	a,@r0
      0020DA C0 E0            [24] 6064 	push	acc
      0020DC 08               [12] 6065 	inc	r0
      0020DD E6               [12] 6066 	mov	a,@r0
      0020DE C0 E0            [24] 6067 	push	acc
      0020E0 08               [12] 6068 	inc	r0
      0020E1 E6               [12] 6069 	mov	a,@r0
      0020E2 C0 E0            [24] 6070 	push	acc
      0020E4 90 99 9A         [24] 6071 	mov	dptr,#0x999a
      0020E7 75 F0 99         [24] 6072 	mov	b, #0x99
      0020EA 74 3E            [12] 6073 	mov	a, #0x3e
      0020EC 12 2A B5         [24] 6074 	lcall	___fsmul
      0020EF AA 82            [24] 6075 	mov	r2, dpl
      0020F1 AB 83            [24] 6076 	mov	r3, dph
      0020F3 AE F0            [24] 6077 	mov	r6, b
      0020F5 FF               [12] 6078 	mov	r7, a
      0020F6 E5 81            [12] 6079 	mov	a,sp
      0020F8 24 FC            [12] 6080 	add	a,#0xfc
      0020FA F5 81            [12] 6081 	mov	sp,a
      0020FC C0 02            [24] 6082 	push	ar2
      0020FE C0 03            [24] 6083 	push	ar3
      002100 C0 06            [24] 6084 	push	ar6
      002102 C0 07            [24] 6085 	push	ar7
      002104 A8 10            [24] 6086 	mov	r0,_bp
      002106 08               [12] 6087 	inc	r0
      002107 86 82            [24] 6088 	mov	dpl, @r0
      002109 08               [12] 6089 	inc	r0
      00210A 86 83            [24] 6090 	mov	dph, @r0
      00210C 08               [12] 6091 	inc	r0
      00210D 86 F0            [24] 6092 	mov	b, @r0
      00210F 08               [12] 6093 	inc	r0
      002110 E6               [12] 6094 	mov	a, @r0
      002111 12 2C 15         [24] 6095 	lcall	___fsadd
      002114 A8 10            [24] 6096 	mov	r0,_bp
      002116 08               [12] 6097 	inc	r0
      002117 A6 82            [24] 6098 	mov	@r0, dpl
      002119 08               [12] 6099 	inc	r0
      00211A A6 83            [24] 6100 	mov	@r0, dph
      00211C 08               [12] 6101 	inc	r0
      00211D A6 F0            [24] 6102 	mov	@r0, b
      00211F 08               [12] 6103 	inc	r0
      002120 F6               [12] 6104 	mov	@r0,a
      002121 E5 81            [12] 6105 	mov	a,sp
      002123 24 FC            [12] 6106 	add	a,#0xfc
      002125 F5 81            [12] 6107 	mov	sp,a
      002127 E5 10            [12] 6108 	mov	a,_bp
      002129 24 F6            [12] 6109 	add	a,#0xf6
      00212B F8               [12] 6110 	mov	r0,a
      00212C E6               [12] 6111 	mov	a,@r0
      00212D C0 E0            [24] 6112 	push	acc
      00212F 08               [12] 6113 	inc	r0
      002130 E6               [12] 6114 	mov	a,@r0
      002131 C0 E0            [24] 6115 	push	acc
      002133 08               [12] 6116 	inc	r0
      002134 E6               [12] 6117 	mov	a,@r0
      002135 C0 E0            [24] 6118 	push	acc
      002137 08               [12] 6119 	inc	r0
      002138 E6               [12] 6120 	mov	a,@r0
      002139 C0 E0            [24] 6121 	push	acc
      00213B 90 00 00         [24] 6122 	mov	dptr,#0x0000
      00213E 75 F0 20         [24] 6123 	mov	b, #0x20
      002141 74 40            [12] 6124 	mov	a, #0x40
      002143 12 2A B5         [24] 6125 	lcall	___fsmul
      002146 AA 82            [24] 6126 	mov	r2, dpl
      002148 AB 83            [24] 6127 	mov	r3, dph
      00214A AE F0            [24] 6128 	mov	r6, b
      00214C FF               [12] 6129 	mov	r7, a
      00214D E5 81            [12] 6130 	mov	a,sp
      00214F 24 FC            [12] 6131 	add	a,#0xfc
      002151 F5 81            [12] 6132 	mov	sp,a
      002153 C0 02            [24] 6133 	push	ar2
      002155 C0 03            [24] 6134 	push	ar3
      002157 C0 06            [24] 6135 	push	ar6
      002159 C0 07            [24] 6136 	push	ar7
      00215B A8 10            [24] 6137 	mov	r0,_bp
      00215D 08               [12] 6138 	inc	r0
      00215E 86 82            [24] 6139 	mov	dpl, @r0
      002160 08               [12] 6140 	inc	r0
      002161 86 83            [24] 6141 	mov	dph, @r0
      002163 08               [12] 6142 	inc	r0
      002164 86 F0            [24] 6143 	mov	b, @r0
      002166 08               [12] 6144 	inc	r0
      002167 E6               [12] 6145 	mov	a, @r0
      002168 12 2C 15         [24] 6146 	lcall	___fsadd
      00216B AC 82            [24] 6147 	mov	r4, dpl
      00216D AD 83            [24] 6148 	mov	r5, dph
      00216F AE F0            [24] 6149 	mov	r6, b
      002171 FF               [12] 6150 	mov	r7, a
      002172 E5 81            [12] 6151 	mov	a,sp
      002174 24 FC            [12] 6152 	add	a,#0xfc
      002176 F5 81            [12] 6153 	mov	sp,a
      002178 8C 82            [24] 6154 	mov	dpl, r4
      00217A 8D 83            [24] 6155 	mov	dph, r5
      00217C 8E F0            [24] 6156 	mov	b, r6
      00217E EF               [12] 6157 	mov	a, r7
      00217F 85 10 81         [24] 6158 	mov	sp,_bp
      002182 D0 10            [24] 6159 	pop	_bp
                           0020C7  6160 	C$sugeno_demo.c$41$1_0$73 ==.
                           0020C7  6161 	XFsugeno_demo$response_protection$0$0 ==.
      002184 22               [24] 6162 	ret
                                   6163 ;------------------------------------------------------------
                                   6164 ;Allocation info for local variables in function 'calculate_fan_speed'
                                   6165 ;------------------------------------------------------------
                                   6166 ;load          Allocated to stack - _bp -6 +4 
                                   6167 ;vibration     Allocated to stack - _bp -10 +4 
                                   6168 ;temperature   Allocated to stack - _bp +1 +4 
                                   6169 ;temperature_low_value Allocated to registers r7 r6 r5 r4 
                                   6170 ;temperature_high_value Allocated to stack - _bp +9 +4 
                                   6171 ;load_low_value Allocated to stack - _bp +13 +4 
                                   6172 ;load_high_value Allocated to stack - _bp +17 +4 
                                   6173 ;vibration_low_value Allocated to stack - _bp +21 +4 
                                   6174 ;vibration_high_value Allocated to stack - _bp +25 +4 
                                   6175 ;rule1         Allocated to stack - _bp +29 +4 
                                   6176 ;rule2         Allocated to stack - _bp +33 +4 
                                   6177 ;rule3         Allocated to stack - _bp +37 +4 
                                   6178 ;rule4         Allocated to stack - _bp +41 +4 
                                   6179 ;rule5         Allocated to stack - _bp +45 +4 
                                   6180 ;rule6         Allocated to stack - _bp +49 +4 
                                   6181 ;sloc0         Allocated to stack - _bp +5 +4 
                                   6182 ;------------------------------------------------------------
                           0020C8  6183 	Fsugeno_demo$calculate_fan_speed$0$0 ==.
                           0020C8  6184 	C$sugeno_demo.c$43$1_0$75 ==.
                                   6185 ;	../../sugeno_demo.c:43: static float calculate_fan_speed(float temperature, float load, float vibration)
                                   6186 ;	-----------------------------------------
                                   6187 ;	 function calculate_fan_speed
                                   6188 ;	-----------------------------------------
      002185                       6189 _calculate_fan_speed:
      002185 C0 10            [24] 6190 	push	_bp
      002187 85 81 10         [24] 6191 	mov	_bp,sp
      00218A C0 82            [24] 6192 	push	dpl
      00218C C0 83            [24] 6193 	push	dph
      00218E C0 F0            [24] 6194 	push	b
      002190 C0 E0            [24] 6195 	push	acc
      002192 E5 81            [12] 6196 	mov	a,sp
      002194 24 30            [12] 6197 	add	a,#0x30
      002196 F5 81            [12] 6198 	mov	sp,a
                           0020DB  6199 	C$sugeno_demo.c$45$1_0$75 ==.
                                   6200 ;	../../sugeno_demo.c:45: float temperature_low_value = temperature_low(temperature);
      002198 A8 10            [24] 6201 	mov	r0,_bp
      00219A 08               [12] 6202 	inc	r0
      00219B 86 82            [24] 6203 	mov	dpl, @r0
      00219D 08               [12] 6204 	inc	r0
      00219E 86 83            [24] 6205 	mov	dph, @r0
      0021A0 08               [12] 6206 	inc	r0
      0021A1 86 F0            [24] 6207 	mov	b, @r0
      0021A3 08               [12] 6208 	inc	r0
      0021A4 E6               [12] 6209 	mov	a, @r0
      0021A5 12 1A 41         [24] 6210 	lcall	_temperature_low
      0021A8 AF 82            [24] 6211 	mov	r7, dpl
      0021AA AE 83            [24] 6212 	mov	r6, dph
      0021AC AD F0            [24] 6213 	mov	r5, b
      0021AE FC               [12] 6214 	mov	r4, a
                           0020F2  6215 	C$sugeno_demo.c$46$1_0$75 ==.
                                   6216 ;	../../sugeno_demo.c:46: float temperature_high_value = temperature_high(temperature);
      0021AF A8 10            [24] 6217 	mov	r0,_bp
      0021B1 08               [12] 6218 	inc	r0
      0021B2 86 82            [24] 6219 	mov	dpl, @r0
      0021B4 08               [12] 6220 	inc	r0
      0021B5 86 83            [24] 6221 	mov	dph, @r0
      0021B7 08               [12] 6222 	inc	r0
      0021B8 86 F0            [24] 6223 	mov	b, @r0
      0021BA 08               [12] 6224 	inc	r0
      0021BB E6               [12] 6225 	mov	a, @r0
      0021BC C0 07            [24] 6226 	push	ar7
      0021BE C0 06            [24] 6227 	push	ar6
      0021C0 C0 05            [24] 6228 	push	ar5
      0021C2 C0 04            [24] 6229 	push	ar4
      0021C4 12 1A 6E         [24] 6230 	lcall	_temperature_high
      0021C7 C8               [12] 6231 	xch	a,r0
      0021C8 E5 10            [12] 6232 	mov	a,_bp
      0021CA 24 09            [12] 6233 	add	a,#0x09
      0021CC C8               [12] 6234 	xch	a,r0
      0021CD A6 82            [24] 6235 	mov	@r0, dpl
      0021CF 08               [12] 6236 	inc	r0
      0021D0 A6 83            [24] 6237 	mov	@r0, dph
      0021D2 08               [12] 6238 	inc	r0
      0021D3 A6 F0            [24] 6239 	mov	@r0, b
      0021D5 08               [12] 6240 	inc	r0
      0021D6 F6               [12] 6241 	mov	@r0,a
                           00211A  6242 	C$sugeno_demo.c$47$1_0$75 ==.
                                   6243 ;	../../sugeno_demo.c:47: float load_low_value = load_low(load);
      0021D7 E5 10            [12] 6244 	mov	a,_bp
      0021D9 24 FA            [12] 6245 	add	a,#0xfa
      0021DB F8               [12] 6246 	mov	r0,a
      0021DC 86 82            [24] 6247 	mov	dpl, @r0
      0021DE 08               [12] 6248 	inc	r0
      0021DF 86 83            [24] 6249 	mov	dph, @r0
      0021E1 08               [12] 6250 	inc	r0
      0021E2 86 F0            [24] 6251 	mov	b, @r0
      0021E4 08               [12] 6252 	inc	r0
      0021E5 E6               [12] 6253 	mov	a, @r0
      0021E6 12 1A 9B         [24] 6254 	lcall	_load_low
      0021E9 C8               [12] 6255 	xch	a,r0
      0021EA E5 10            [12] 6256 	mov	a,_bp
      0021EC 24 0D            [12] 6257 	add	a,#0x0d
      0021EE C8               [12] 6258 	xch	a,r0
      0021EF A6 82            [24] 6259 	mov	@r0, dpl
      0021F1 08               [12] 6260 	inc	r0
      0021F2 A6 83            [24] 6261 	mov	@r0, dph
      0021F4 08               [12] 6262 	inc	r0
      0021F5 A6 F0            [24] 6263 	mov	@r0, b
      0021F7 08               [12] 6264 	inc	r0
      0021F8 F6               [12] 6265 	mov	@r0,a
                           00213C  6266 	C$sugeno_demo.c$48$1_0$75 ==.
                                   6267 ;	../../sugeno_demo.c:48: float load_high_value = load_high(load);
      0021F9 E5 10            [12] 6268 	mov	a,_bp
      0021FB 24 FA            [12] 6269 	add	a,#0xfa
      0021FD F8               [12] 6270 	mov	r0,a
      0021FE 86 82            [24] 6271 	mov	dpl, @r0
      002200 08               [12] 6272 	inc	r0
      002201 86 83            [24] 6273 	mov	dph, @r0
      002203 08               [12] 6274 	inc	r0
      002204 86 F0            [24] 6275 	mov	b, @r0
      002206 08               [12] 6276 	inc	r0
      002207 E6               [12] 6277 	mov	a, @r0
      002208 12 1A C8         [24] 6278 	lcall	_load_high
      00220B C8               [12] 6279 	xch	a,r0
      00220C E5 10            [12] 6280 	mov	a,_bp
      00220E 24 11            [12] 6281 	add	a,#0x11
      002210 C8               [12] 6282 	xch	a,r0
      002211 A6 82            [24] 6283 	mov	@r0, dpl
      002213 08               [12] 6284 	inc	r0
      002214 A6 83            [24] 6285 	mov	@r0, dph
      002216 08               [12] 6286 	inc	r0
      002217 A6 F0            [24] 6287 	mov	@r0, b
      002219 08               [12] 6288 	inc	r0
      00221A F6               [12] 6289 	mov	@r0,a
                           00215E  6290 	C$sugeno_demo.c$49$1_0$75 ==.
                                   6291 ;	../../sugeno_demo.c:49: float vibration_low_value = vibration_low(vibration);
      00221B E5 10            [12] 6292 	mov	a,_bp
      00221D 24 F6            [12] 6293 	add	a,#0xf6
      00221F F8               [12] 6294 	mov	r0,a
      002220 86 82            [24] 6295 	mov	dpl, @r0
      002222 08               [12] 6296 	inc	r0
      002223 86 83            [24] 6297 	mov	dph, @r0
      002225 08               [12] 6298 	inc	r0
      002226 86 F0            [24] 6299 	mov	b, @r0
      002228 08               [12] 6300 	inc	r0
      002229 E6               [12] 6301 	mov	a, @r0
      00222A 12 1A F5         [24] 6302 	lcall	_vibration_low
      00222D C8               [12] 6303 	xch	a,r0
      00222E E5 10            [12] 6304 	mov	a,_bp
      002230 24 15            [12] 6305 	add	a,#0x15
      002232 C8               [12] 6306 	xch	a,r0
      002233 A6 82            [24] 6307 	mov	@r0, dpl
      002235 08               [12] 6308 	inc	r0
      002236 A6 83            [24] 6309 	mov	@r0, dph
      002238 08               [12] 6310 	inc	r0
      002239 A6 F0            [24] 6311 	mov	@r0, b
      00223B 08               [12] 6312 	inc	r0
      00223C F6               [12] 6313 	mov	@r0,a
                           002180  6314 	C$sugeno_demo.c$50$1_0$75 ==.
                                   6315 ;	../../sugeno_demo.c:50: float vibration_high_value = vibration_high(vibration);
      00223D E5 10            [12] 6316 	mov	a,_bp
      00223F 24 F6            [12] 6317 	add	a,#0xf6
      002241 F8               [12] 6318 	mov	r0,a
      002242 86 82            [24] 6319 	mov	dpl, @r0
      002244 08               [12] 6320 	inc	r0
      002245 86 83            [24] 6321 	mov	dph, @r0
      002247 08               [12] 6322 	inc	r0
      002248 86 F0            [24] 6323 	mov	b, @r0
      00224A 08               [12] 6324 	inc	r0
      00224B E6               [12] 6325 	mov	a, @r0
      00224C 12 1B 22         [24] 6326 	lcall	_vibration_high
      00224F C8               [12] 6327 	xch	a,r0
      002250 E5 10            [12] 6328 	mov	a,_bp
      002252 24 19            [12] 6329 	add	a,#0x19
      002254 C8               [12] 6330 	xch	a,r0
      002255 A6 82            [24] 6331 	mov	@r0, dpl
      002257 08               [12] 6332 	inc	r0
      002258 A6 83            [24] 6333 	mov	@r0, dph
      00225A 08               [12] 6334 	inc	r0
      00225B A6 F0            [24] 6335 	mov	@r0, b
      00225D 08               [12] 6336 	inc	r0
      00225E F6               [12] 6337 	mov	@r0,a
      00225F D0 04            [24] 6338 	pop	ar4
      002261 D0 05            [24] 6339 	pop	ar5
      002263 D0 06            [24] 6340 	pop	ar6
      002265 D0 07            [24] 6341 	pop	ar7
                           0021AA  6342 	C$sugeno_demo.c$52$1_0$75 ==.
                                   6343 ;	../../sugeno_demo.c:52: float rule1 = fuzzy_and_method(FUZZY_LOGIC_STANDARD, temperature_low_value, load_low_value, vibration_low_value);
      002267 E5 10            [12] 6344 	mov	a,_bp
      002269 24 15            [12] 6345 	add	a,#0x15
      00226B F8               [12] 6346 	mov	r0,a
      00226C E6               [12] 6347 	mov	a,@r0
      00226D C0 E0            [24] 6348 	push	acc
      00226F 08               [12] 6349 	inc	r0
      002270 E6               [12] 6350 	mov	a,@r0
      002271 C0 E0            [24] 6351 	push	acc
      002273 08               [12] 6352 	inc	r0
      002274 E6               [12] 6353 	mov	a,@r0
      002275 C0 E0            [24] 6354 	push	acc
      002277 08               [12] 6355 	inc	r0
      002278 E6               [12] 6356 	mov	a,@r0
      002279 C0 E0            [24] 6357 	push	acc
      00227B E5 10            [12] 6358 	mov	a,_bp
      00227D 24 0D            [12] 6359 	add	a,#0x0d
      00227F F8               [12] 6360 	mov	r0,a
      002280 E6               [12] 6361 	mov	a,@r0
      002281 C0 E0            [24] 6362 	push	acc
      002283 08               [12] 6363 	inc	r0
      002284 E6               [12] 6364 	mov	a,@r0
      002285 C0 E0            [24] 6365 	push	acc
      002287 08               [12] 6366 	inc	r0
      002288 E6               [12] 6367 	mov	a,@r0
      002289 C0 E0            [24] 6368 	push	acc
      00228B 08               [12] 6369 	inc	r0
      00228C E6               [12] 6370 	mov	a,@r0
      00228D C0 E0            [24] 6371 	push	acc
      00228F C0 07            [24] 6372 	push	ar7
      002291 C0 06            [24] 6373 	push	ar6
      002293 C0 05            [24] 6374 	push	ar5
      002295 C0 04            [24] 6375 	push	ar4
      002297 75 82 00         [24] 6376 	mov	dpl, #0x00
      00229A 12 01 F9         [24] 6377 	lcall	_fuzzy_8051_and3
      00229D C8               [12] 6378 	xch	a,r0
      00229E E5 10            [12] 6379 	mov	a,_bp
      0022A0 24 1D            [12] 6380 	add	a,#0x1d
      0022A2 C8               [12] 6381 	xch	a,r0
      0022A3 A6 82            [24] 6382 	mov	@r0, dpl
      0022A5 08               [12] 6383 	inc	r0
      0022A6 A6 83            [24] 6384 	mov	@r0, dph
      0022A8 08               [12] 6385 	inc	r0
      0022A9 A6 F0            [24] 6386 	mov	@r0, b
      0022AB 08               [12] 6387 	inc	r0
      0022AC F6               [12] 6388 	mov	@r0,a
      0022AD E5 81            [12] 6389 	mov	a,sp
      0022AF 24 F4            [12] 6390 	add	a,#0xf4
      0022B1 F5 81            [12] 6391 	mov	sp,a
                           0021F6  6392 	C$sugeno_demo.c$53$1_0$75 ==.
                                   6393 ;	../../sugeno_demo.c:53: float rule2 = fuzzy_and_method(FUZZY_LOGIC_STANDARD, fuzzy_not(temperature_high_value), load_high_value);
      0022B3 E5 10            [12] 6394 	mov	a,_bp
      0022B5 24 09            [12] 6395 	add	a,#0x09
      0022B7 F8               [12] 6396 	mov	r0,a
      0022B8 86 82            [24] 6397 	mov	dpl, @r0
      0022BA 08               [12] 6398 	inc	r0
      0022BB 86 83            [24] 6399 	mov	dph, @r0
      0022BD 08               [12] 6400 	inc	r0
      0022BE 86 F0            [24] 6401 	mov	b, @r0
      0022C0 08               [12] 6402 	inc	r0
      0022C1 E6               [12] 6403 	mov	a, @r0
      0022C2 12 05 84         [24] 6404 	lcall	_fuzzy_not
      0022C5 AA 82            [24] 6405 	mov	r2, dpl
      0022C7 AB 83            [24] 6406 	mov	r3, dph
      0022C9 AE F0            [24] 6407 	mov	r6, b
      0022CB FF               [12] 6408 	mov	r7, a
      0022CC E5 10            [12] 6409 	mov	a,_bp
      0022CE 24 11            [12] 6410 	add	a,#0x11
      0022D0 F8               [12] 6411 	mov	r0,a
      0022D1 E6               [12] 6412 	mov	a,@r0
      0022D2 C0 E0            [24] 6413 	push	acc
      0022D4 08               [12] 6414 	inc	r0
      0022D5 E6               [12] 6415 	mov	a,@r0
      0022D6 C0 E0            [24] 6416 	push	acc
      0022D8 08               [12] 6417 	inc	r0
      0022D9 E6               [12] 6418 	mov	a,@r0
      0022DA C0 E0            [24] 6419 	push	acc
      0022DC 08               [12] 6420 	inc	r0
      0022DD E6               [12] 6421 	mov	a,@r0
      0022DE C0 E0            [24] 6422 	push	acc
      0022E0 C0 02            [24] 6423 	push	ar2
      0022E2 C0 03            [24] 6424 	push	ar3
      0022E4 C0 06            [24] 6425 	push	ar6
      0022E6 C0 07            [24] 6426 	push	ar7
      0022E8 75 82 00         [24] 6427 	mov	dpl, #0x00
      0022EB 12 00 BD         [24] 6428 	lcall	_fuzzy_8051_and2
      0022EE C8               [12] 6429 	xch	a,r0
      0022EF E5 10            [12] 6430 	mov	a,_bp
      0022F1 24 21            [12] 6431 	add	a,#0x21
      0022F3 C8               [12] 6432 	xch	a,r0
      0022F4 A6 82            [24] 6433 	mov	@r0, dpl
      0022F6 08               [12] 6434 	inc	r0
      0022F7 A6 83            [24] 6435 	mov	@r0, dph
      0022F9 08               [12] 6436 	inc	r0
      0022FA A6 F0            [24] 6437 	mov	@r0, b
      0022FC 08               [12] 6438 	inc	r0
      0022FD F6               [12] 6439 	mov	@r0,a
      0022FE E5 81            [12] 6440 	mov	a,sp
      002300 24 F8            [12] 6441 	add	a,#0xf8
      002302 F5 81            [12] 6442 	mov	sp,a
                           002247  6443 	C$sugeno_demo.c$54$1_0$75 ==.
                                   6444 ;	../../sugeno_demo.c:54: float rule3 = fuzzy_or_method(FUZZY_LOGIC_STANDARD, temperature_high_value, vibration_high_value);
      002304 E5 10            [12] 6445 	mov	a,_bp
      002306 24 19            [12] 6446 	add	a,#0x19
      002308 F8               [12] 6447 	mov	r0,a
      002309 E6               [12] 6448 	mov	a,@r0
      00230A C0 E0            [24] 6449 	push	acc
      00230C 08               [12] 6450 	inc	r0
      00230D E6               [12] 6451 	mov	a,@r0
      00230E C0 E0            [24] 6452 	push	acc
      002310 08               [12] 6453 	inc	r0
      002311 E6               [12] 6454 	mov	a,@r0
      002312 C0 E0            [24] 6455 	push	acc
      002314 08               [12] 6456 	inc	r0
      002315 E6               [12] 6457 	mov	a,@r0
      002316 C0 E0            [24] 6458 	push	acc
      002318 E5 10            [12] 6459 	mov	a,_bp
      00231A 24 09            [12] 6460 	add	a,#0x09
      00231C F8               [12] 6461 	mov	r0,a
      00231D E6               [12] 6462 	mov	a,@r0
      00231E C0 E0            [24] 6463 	push	acc
      002320 08               [12] 6464 	inc	r0
      002321 E6               [12] 6465 	mov	a,@r0
      002322 C0 E0            [24] 6466 	push	acc
      002324 08               [12] 6467 	inc	r0
      002325 E6               [12] 6468 	mov	a,@r0
      002326 C0 E0            [24] 6469 	push	acc
      002328 08               [12] 6470 	inc	r0
      002329 E6               [12] 6471 	mov	a,@r0
      00232A C0 E0            [24] 6472 	push	acc
      00232C 75 82 00         [24] 6473 	mov	dpl, #0x00
      00232F 12 02 76         [24] 6474 	lcall	_fuzzy_8051_or2
      002332 C8               [12] 6475 	xch	a,r0
      002333 E5 10            [12] 6476 	mov	a,_bp
      002335 24 25            [12] 6477 	add	a,#0x25
      002337 C8               [12] 6478 	xch	a,r0
      002338 A6 82            [24] 6479 	mov	@r0, dpl
      00233A 08               [12] 6480 	inc	r0
      00233B A6 83            [24] 6481 	mov	@r0, dph
      00233D 08               [12] 6482 	inc	r0
      00233E A6 F0            [24] 6483 	mov	@r0, b
      002340 08               [12] 6484 	inc	r0
      002341 F6               [12] 6485 	mov	@r0,a
      002342 E5 81            [12] 6486 	mov	a,sp
      002344 24 F8            [12] 6487 	add	a,#0xf8
      002346 F5 81            [12] 6488 	mov	sp,a
                           00228B  6489 	C$sugeno_demo.c$55$1_0$75 ==.
                                   6490 ;	../../sugeno_demo.c:55: float rule4 = fuzzy_and_method(FUZZY_LOGIC_STANDARD, temperature_high_value, load_high_value);
      002348 E5 10            [12] 6491 	mov	a,_bp
      00234A 24 11            [12] 6492 	add	a,#0x11
      00234C F8               [12] 6493 	mov	r0,a
      00234D E6               [12] 6494 	mov	a,@r0
      00234E C0 E0            [24] 6495 	push	acc
      002350 08               [12] 6496 	inc	r0
      002351 E6               [12] 6497 	mov	a,@r0
      002352 C0 E0            [24] 6498 	push	acc
      002354 08               [12] 6499 	inc	r0
      002355 E6               [12] 6500 	mov	a,@r0
      002356 C0 E0            [24] 6501 	push	acc
      002358 08               [12] 6502 	inc	r0
      002359 E6               [12] 6503 	mov	a,@r0
      00235A C0 E0            [24] 6504 	push	acc
      00235C E5 10            [12] 6505 	mov	a,_bp
      00235E 24 09            [12] 6506 	add	a,#0x09
      002360 F8               [12] 6507 	mov	r0,a
      002361 E6               [12] 6508 	mov	a,@r0
      002362 C0 E0            [24] 6509 	push	acc
      002364 08               [12] 6510 	inc	r0
      002365 E6               [12] 6511 	mov	a,@r0
      002366 C0 E0            [24] 6512 	push	acc
      002368 08               [12] 6513 	inc	r0
      002369 E6               [12] 6514 	mov	a,@r0
      00236A C0 E0            [24] 6515 	push	acc
      00236C 08               [12] 6516 	inc	r0
      00236D E6               [12] 6517 	mov	a,@r0
      00236E C0 E0            [24] 6518 	push	acc
      002370 75 82 00         [24] 6519 	mov	dpl, #0x00
      002373 12 00 BD         [24] 6520 	lcall	_fuzzy_8051_and2
      002376 C8               [12] 6521 	xch	a,r0
      002377 E5 10            [12] 6522 	mov	a,_bp
      002379 24 29            [12] 6523 	add	a,#0x29
      00237B C8               [12] 6524 	xch	a,r0
      00237C A6 82            [24] 6525 	mov	@r0, dpl
      00237E 08               [12] 6526 	inc	r0
      00237F A6 83            [24] 6527 	mov	@r0, dph
      002381 08               [12] 6528 	inc	r0
      002382 A6 F0            [24] 6529 	mov	@r0, b
      002384 08               [12] 6530 	inc	r0
      002385 F6               [12] 6531 	mov	@r0,a
      002386 E5 81            [12] 6532 	mov	a,sp
      002388 24 F8            [12] 6533 	add	a,#0xf8
      00238A F5 81            [12] 6534 	mov	sp,a
                           0022CF  6535 	C$sugeno_demo.c$56$1_0$75 ==.
                                   6536 ;	../../sugeno_demo.c:56: float rule5 = fuzzy_and_method(FUZZY_LOGIC_STANDARD, load_high_value, fuzzy_not(vibration_high_value));
      00238C E5 10            [12] 6537 	mov	a,_bp
      00238E 24 19            [12] 6538 	add	a,#0x19
      002390 F8               [12] 6539 	mov	r0,a
      002391 86 82            [24] 6540 	mov	dpl, @r0
      002393 08               [12] 6541 	inc	r0
      002394 86 83            [24] 6542 	mov	dph, @r0
      002396 08               [12] 6543 	inc	r0
      002397 86 F0            [24] 6544 	mov	b, @r0
      002399 08               [12] 6545 	inc	r0
      00239A E6               [12] 6546 	mov	a, @r0
      00239B 12 05 84         [24] 6547 	lcall	_fuzzy_not
      00239E AA 82            [24] 6548 	mov	r2, dpl
      0023A0 AB 83            [24] 6549 	mov	r3, dph
      0023A2 AE F0            [24] 6550 	mov	r6, b
      0023A4 FF               [12] 6551 	mov	r7, a
      0023A5 C0 02            [24] 6552 	push	ar2
      0023A7 C0 03            [24] 6553 	push	ar3
      0023A9 C0 06            [24] 6554 	push	ar6
      0023AB C0 07            [24] 6555 	push	ar7
      0023AD E5 10            [12] 6556 	mov	a,_bp
      0023AF 24 11            [12] 6557 	add	a,#0x11
      0023B1 F8               [12] 6558 	mov	r0,a
      0023B2 E6               [12] 6559 	mov	a,@r0
      0023B3 C0 E0            [24] 6560 	push	acc
      0023B5 08               [12] 6561 	inc	r0
      0023B6 E6               [12] 6562 	mov	a,@r0
      0023B7 C0 E0            [24] 6563 	push	acc
      0023B9 08               [12] 6564 	inc	r0
      0023BA E6               [12] 6565 	mov	a,@r0
      0023BB C0 E0            [24] 6566 	push	acc
      0023BD 08               [12] 6567 	inc	r0
      0023BE E6               [12] 6568 	mov	a,@r0
      0023BF C0 E0            [24] 6569 	push	acc
      0023C1 75 82 00         [24] 6570 	mov	dpl, #0x00
      0023C4 12 00 BD         [24] 6571 	lcall	_fuzzy_8051_and2
      0023C7 C8               [12] 6572 	xch	a,r0
      0023C8 E5 10            [12] 6573 	mov	a,_bp
      0023CA 24 2D            [12] 6574 	add	a,#0x2d
      0023CC C8               [12] 6575 	xch	a,r0
      0023CD A6 82            [24] 6576 	mov	@r0, dpl
      0023CF 08               [12] 6577 	inc	r0
      0023D0 A6 83            [24] 6578 	mov	@r0, dph
      0023D2 08               [12] 6579 	inc	r0
      0023D3 A6 F0            [24] 6580 	mov	@r0, b
      0023D5 08               [12] 6581 	inc	r0
      0023D6 F6               [12] 6582 	mov	@r0,a
      0023D7 E5 81            [12] 6583 	mov	a,sp
      0023D9 24 F8            [12] 6584 	add	a,#0xf8
      0023DB F5 81            [12] 6585 	mov	sp,a
                           002320  6586 	C$sugeno_demo.c$57$1_0$75 ==.
                                   6587 ;	../../sugeno_demo.c:57: float rule6 = fuzzy_or_method(FUZZY_LOGIC_STANDARD, fuzzy_and_method(FUZZY_LOGIC_STANDARD, temperature_high_value, vibration_high_value), fuzzy_and_method(FUZZY_LOGIC_STANDARD, load_high_value, vibration_high_value));
      0023DD E5 10            [12] 6588 	mov	a,_bp
      0023DF 24 19            [12] 6589 	add	a,#0x19
      0023E1 F8               [12] 6590 	mov	r0,a
      0023E2 E6               [12] 6591 	mov	a,@r0
      0023E3 C0 E0            [24] 6592 	push	acc
      0023E5 08               [12] 6593 	inc	r0
      0023E6 E6               [12] 6594 	mov	a,@r0
      0023E7 C0 E0            [24] 6595 	push	acc
      0023E9 08               [12] 6596 	inc	r0
      0023EA E6               [12] 6597 	mov	a,@r0
      0023EB C0 E0            [24] 6598 	push	acc
      0023ED 08               [12] 6599 	inc	r0
      0023EE E6               [12] 6600 	mov	a,@r0
      0023EF C0 E0            [24] 6601 	push	acc
      0023F1 E5 10            [12] 6602 	mov	a,_bp
      0023F3 24 11            [12] 6603 	add	a,#0x11
      0023F5 F8               [12] 6604 	mov	r0,a
      0023F6 E6               [12] 6605 	mov	a,@r0
      0023F7 C0 E0            [24] 6606 	push	acc
      0023F9 08               [12] 6607 	inc	r0
      0023FA E6               [12] 6608 	mov	a,@r0
      0023FB C0 E0            [24] 6609 	push	acc
      0023FD 08               [12] 6610 	inc	r0
      0023FE E6               [12] 6611 	mov	a,@r0
      0023FF C0 E0            [24] 6612 	push	acc
      002401 08               [12] 6613 	inc	r0
      002402 E6               [12] 6614 	mov	a,@r0
      002403 C0 E0            [24] 6615 	push	acc
      002405 75 82 00         [24] 6616 	mov	dpl, #0x00
      002408 12 00 BD         [24] 6617 	lcall	_fuzzy_8051_and2
      00240B C8               [12] 6618 	xch	a,r0
      00240C E5 10            [12] 6619 	mov	a,_bp
      00240E 24 05            [12] 6620 	add	a,#0x05
      002410 C8               [12] 6621 	xch	a,r0
      002411 A6 82            [24] 6622 	mov	@r0, dpl
      002413 08               [12] 6623 	inc	r0
      002414 A6 83            [24] 6624 	mov	@r0, dph
      002416 08               [12] 6625 	inc	r0
      002417 A6 F0            [24] 6626 	mov	@r0, b
      002419 08               [12] 6627 	inc	r0
      00241A F6               [12] 6628 	mov	@r0,a
      00241B E5 81            [12] 6629 	mov	a,sp
      00241D 24 F8            [12] 6630 	add	a,#0xf8
      00241F F5 81            [12] 6631 	mov	sp,a
      002421 E5 10            [12] 6632 	mov	a,_bp
      002423 24 19            [12] 6633 	add	a,#0x19
      002425 F8               [12] 6634 	mov	r0,a
      002426 E6               [12] 6635 	mov	a,@r0
      002427 C0 E0            [24] 6636 	push	acc
      002429 08               [12] 6637 	inc	r0
      00242A E6               [12] 6638 	mov	a,@r0
      00242B C0 E0            [24] 6639 	push	acc
      00242D 08               [12] 6640 	inc	r0
      00242E E6               [12] 6641 	mov	a,@r0
      00242F C0 E0            [24] 6642 	push	acc
      002431 08               [12] 6643 	inc	r0
      002432 E6               [12] 6644 	mov	a,@r0
      002433 C0 E0            [24] 6645 	push	acc
      002435 E5 10            [12] 6646 	mov	a,_bp
      002437 24 09            [12] 6647 	add	a,#0x09
      002439 F8               [12] 6648 	mov	r0,a
      00243A E6               [12] 6649 	mov	a,@r0
      00243B C0 E0            [24] 6650 	push	acc
      00243D 08               [12] 6651 	inc	r0
      00243E E6               [12] 6652 	mov	a,@r0
      00243F C0 E0            [24] 6653 	push	acc
      002441 08               [12] 6654 	inc	r0
      002442 E6               [12] 6655 	mov	a,@r0
      002443 C0 E0            [24] 6656 	push	acc
      002445 08               [12] 6657 	inc	r0
      002446 E6               [12] 6658 	mov	a,@r0
      002447 C0 E0            [24] 6659 	push	acc
      002449 75 82 00         [24] 6660 	mov	dpl, #0x00
      00244C 12 00 BD         [24] 6661 	lcall	_fuzzy_8051_and2
      00244F AC 82            [24] 6662 	mov	r4, dpl
      002451 AD 83            [24] 6663 	mov	r5, dph
      002453 AE F0            [24] 6664 	mov	r6, b
      002455 FF               [12] 6665 	mov	r7, a
      002456 E5 81            [12] 6666 	mov	a,sp
      002458 24 F8            [12] 6667 	add	a,#0xf8
      00245A F5 81            [12] 6668 	mov	sp,a
      00245C E5 10            [12] 6669 	mov	a,_bp
      00245E 24 05            [12] 6670 	add	a,#0x05
      002460 F8               [12] 6671 	mov	r0,a
      002461 E6               [12] 6672 	mov	a,@r0
      002462 C0 E0            [24] 6673 	push	acc
      002464 08               [12] 6674 	inc	r0
      002465 E6               [12] 6675 	mov	a,@r0
      002466 C0 E0            [24] 6676 	push	acc
      002468 08               [12] 6677 	inc	r0
      002469 E6               [12] 6678 	mov	a,@r0
      00246A C0 E0            [24] 6679 	push	acc
      00246C 08               [12] 6680 	inc	r0
      00246D E6               [12] 6681 	mov	a,@r0
      00246E C0 E0            [24] 6682 	push	acc
      002470 C0 04            [24] 6683 	push	ar4
      002472 C0 05            [24] 6684 	push	ar5
      002474 C0 06            [24] 6685 	push	ar6
      002476 C0 07            [24] 6686 	push	ar7
      002478 75 82 00         [24] 6687 	mov	dpl, #0x00
      00247B 12 02 76         [24] 6688 	lcall	_fuzzy_8051_or2
      00247E C8               [12] 6689 	xch	a,r0
      00247F E5 10            [12] 6690 	mov	a,_bp
      002481 24 31            [12] 6691 	add	a,#0x31
      002483 C8               [12] 6692 	xch	a,r0
      002484 A6 82            [24] 6693 	mov	@r0, dpl
      002486 08               [12] 6694 	inc	r0
      002487 A6 83            [24] 6695 	mov	@r0, dph
      002489 08               [12] 6696 	inc	r0
      00248A A6 F0            [24] 6697 	mov	@r0, b
      00248C 08               [12] 6698 	inc	r0
      00248D F6               [12] 6699 	mov	@r0,a
      00248E E5 81            [12] 6700 	mov	a,sp
      002490 24 F8            [12] 6701 	add	a,#0xf8
      002492 F5 81            [12] 6702 	mov	sp,a
                           0023D7  6703 	C$sugeno_demo.c$59$1_0$75 ==.
                                   6704 ;	../../sugeno_demo.c:59: return fuzzy_sugeno_weighted_average(rule1, response_idle(temperature, load, vibration), rule2, response_economy(temperature, load, vibration), rule3, response_balanced(temperature, load, vibration), rule4, response_cooling(temperature, load, vibration), rule5, response_heavy_load(temperature, load, vibration), rule6, response_protection(temperature, load, vibration));
      002494 E5 10            [12] 6705 	mov	a,_bp
      002496 24 F6            [12] 6706 	add	a,#0xf6
      002498 F8               [12] 6707 	mov	r0,a
      002499 E6               [12] 6708 	mov	a,@r0
      00249A C0 E0            [24] 6709 	push	acc
      00249C 08               [12] 6710 	inc	r0
      00249D E6               [12] 6711 	mov	a,@r0
      00249E C0 E0            [24] 6712 	push	acc
      0024A0 08               [12] 6713 	inc	r0
      0024A1 E6               [12] 6714 	mov	a,@r0
      0024A2 C0 E0            [24] 6715 	push	acc
      0024A4 08               [12] 6716 	inc	r0
      0024A5 E6               [12] 6717 	mov	a,@r0
      0024A6 C0 E0            [24] 6718 	push	acc
      0024A8 E5 10            [12] 6719 	mov	a,_bp
      0024AA 24 FA            [12] 6720 	add	a,#0xfa
      0024AC F8               [12] 6721 	mov	r0,a
      0024AD E6               [12] 6722 	mov	a,@r0
      0024AE C0 E0            [24] 6723 	push	acc
      0024B0 08               [12] 6724 	inc	r0
      0024B1 E6               [12] 6725 	mov	a,@r0
      0024B2 C0 E0            [24] 6726 	push	acc
      0024B4 08               [12] 6727 	inc	r0
      0024B5 E6               [12] 6728 	mov	a,@r0
      0024B6 C0 E0            [24] 6729 	push	acc
      0024B8 08               [12] 6730 	inc	r0
      0024B9 E6               [12] 6731 	mov	a,@r0
      0024BA C0 E0            [24] 6732 	push	acc
      0024BC A8 10            [24] 6733 	mov	r0,_bp
      0024BE 08               [12] 6734 	inc	r0
      0024BF 86 82            [24] 6735 	mov	dpl, @r0
      0024C1 08               [12] 6736 	inc	r0
      0024C2 86 83            [24] 6737 	mov	dph, @r0
      0024C4 08               [12] 6738 	inc	r0
      0024C5 86 F0            [24] 6739 	mov	b, @r0
      0024C7 08               [12] 6740 	inc	r0
      0024C8 E6               [12] 6741 	mov	a, @r0
      0024C9 12 1B 4F         [24] 6742 	lcall	_response_idle
      0024CC AA 82            [24] 6743 	mov	r2, dpl
      0024CE AB 83            [24] 6744 	mov	r3, dph
      0024D0 AE F0            [24] 6745 	mov	r6, b
      0024D2 FF               [12] 6746 	mov	r7, a
      0024D3 E5 81            [12] 6747 	mov	a,sp
      0024D5 24 F8            [12] 6748 	add	a,#0xf8
      0024D7 F5 81            [12] 6749 	mov	sp,a
      0024D9 C0 02            [24] 6750 	push	ar2
      0024DB C0 03            [24] 6751 	push	ar3
      0024DD C0 06            [24] 6752 	push	ar6
      0024DF C0 07            [24] 6753 	push	ar7
      0024E1 E5 10            [12] 6754 	mov	a,_bp
      0024E3 24 1D            [12] 6755 	add	a,#0x1d
      0024E5 F8               [12] 6756 	mov	r0,a
      0024E6 86 82            [24] 6757 	mov	dpl, @r0
      0024E8 08               [12] 6758 	inc	r0
      0024E9 86 83            [24] 6759 	mov	dph, @r0
      0024EB 08               [12] 6760 	inc	r0
      0024EC 86 F0            [24] 6761 	mov	b, @r0
      0024EE 08               [12] 6762 	inc	r0
      0024EF E6               [12] 6763 	mov	a, @r0
      0024F0 12 2A B5         [24] 6764 	lcall	___fsmul
      0024F3 C8               [12] 6765 	xch	a,r0
      0024F4 E5 10            [12] 6766 	mov	a,_bp
      0024F6 24 05            [12] 6767 	add	a,#0x05
      0024F8 C8               [12] 6768 	xch	a,r0
      0024F9 A6 82            [24] 6769 	mov	@r0, dpl
      0024FB 08               [12] 6770 	inc	r0
      0024FC A6 83            [24] 6771 	mov	@r0, dph
      0024FE 08               [12] 6772 	inc	r0
      0024FF A6 F0            [24] 6773 	mov	@r0, b
      002501 08               [12] 6774 	inc	r0
      002502 F6               [12] 6775 	mov	@r0,a
      002503 E5 81            [12] 6776 	mov	a,sp
      002505 24 FC            [12] 6777 	add	a,#0xfc
      002507 F5 81            [12] 6778 	mov	sp,a
      002509 E5 10            [12] 6779 	mov	a,_bp
      00250B 24 F6            [12] 6780 	add	a,#0xf6
      00250D F8               [12] 6781 	mov	r0,a
      00250E E6               [12] 6782 	mov	a,@r0
      00250F C0 E0            [24] 6783 	push	acc
      002511 08               [12] 6784 	inc	r0
      002512 E6               [12] 6785 	mov	a,@r0
      002513 C0 E0            [24] 6786 	push	acc
      002515 08               [12] 6787 	inc	r0
      002516 E6               [12] 6788 	mov	a,@r0
      002517 C0 E0            [24] 6789 	push	acc
      002519 08               [12] 6790 	inc	r0
      00251A E6               [12] 6791 	mov	a,@r0
      00251B C0 E0            [24] 6792 	push	acc
      00251D E5 10            [12] 6793 	mov	a,_bp
      00251F 24 FA            [12] 6794 	add	a,#0xfa
      002521 F8               [12] 6795 	mov	r0,a
      002522 E6               [12] 6796 	mov	a,@r0
      002523 C0 E0            [24] 6797 	push	acc
      002525 08               [12] 6798 	inc	r0
      002526 E6               [12] 6799 	mov	a,@r0
      002527 C0 E0            [24] 6800 	push	acc
      002529 08               [12] 6801 	inc	r0
      00252A E6               [12] 6802 	mov	a,@r0
      00252B C0 E0            [24] 6803 	push	acc
      00252D 08               [12] 6804 	inc	r0
      00252E E6               [12] 6805 	mov	a,@r0
      00252F C0 E0            [24] 6806 	push	acc
      002531 A8 10            [24] 6807 	mov	r0,_bp
      002533 08               [12] 6808 	inc	r0
      002534 86 82            [24] 6809 	mov	dpl, @r0
      002536 08               [12] 6810 	inc	r0
      002537 86 83            [24] 6811 	mov	dph, @r0
      002539 08               [12] 6812 	inc	r0
      00253A 86 F0            [24] 6813 	mov	b, @r0
      00253C 08               [12] 6814 	inc	r0
      00253D E6               [12] 6815 	mov	a, @r0
      00253E 12 1C 5E         [24] 6816 	lcall	_response_economy
      002541 AA 82            [24] 6817 	mov	r2, dpl
      002543 AB 83            [24] 6818 	mov	r3, dph
      002545 AE F0            [24] 6819 	mov	r6, b
      002547 FF               [12] 6820 	mov	r7, a
      002548 E5 81            [12] 6821 	mov	a,sp
      00254A 24 F8            [12] 6822 	add	a,#0xf8
      00254C F5 81            [12] 6823 	mov	sp,a
      00254E C0 02            [24] 6824 	push	ar2
      002550 C0 03            [24] 6825 	push	ar3
      002552 C0 06            [24] 6826 	push	ar6
      002554 C0 07            [24] 6827 	push	ar7
      002556 E5 10            [12] 6828 	mov	a,_bp
      002558 24 21            [12] 6829 	add	a,#0x21
      00255A F8               [12] 6830 	mov	r0,a
      00255B 86 82            [24] 6831 	mov	dpl, @r0
      00255D 08               [12] 6832 	inc	r0
      00255E 86 83            [24] 6833 	mov	dph, @r0
      002560 08               [12] 6834 	inc	r0
      002561 86 F0            [24] 6835 	mov	b, @r0
      002563 08               [12] 6836 	inc	r0
      002564 E6               [12] 6837 	mov	a, @r0
      002565 12 2A B5         [24] 6838 	lcall	___fsmul
      002568 AC 82            [24] 6839 	mov	r4, dpl
      00256A AD 83            [24] 6840 	mov	r5, dph
      00256C AE F0            [24] 6841 	mov	r6, b
      00256E FF               [12] 6842 	mov	r7, a
      00256F E5 81            [12] 6843 	mov	a,sp
      002571 24 FC            [12] 6844 	add	a,#0xfc
      002573 F5 81            [12] 6845 	mov	sp,a
      002575 C0 04            [24] 6846 	push	ar4
      002577 C0 05            [24] 6847 	push	ar5
      002579 C0 06            [24] 6848 	push	ar6
      00257B C0 07            [24] 6849 	push	ar7
      00257D E5 10            [12] 6850 	mov	a,_bp
      00257F 24 05            [12] 6851 	add	a,#0x05
      002581 F8               [12] 6852 	mov	r0,a
      002582 86 82            [24] 6853 	mov	dpl, @r0
      002584 08               [12] 6854 	inc	r0
      002585 86 83            [24] 6855 	mov	dph, @r0
      002587 08               [12] 6856 	inc	r0
      002588 86 F0            [24] 6857 	mov	b, @r0
      00258A 08               [12] 6858 	inc	r0
      00258B E6               [12] 6859 	mov	a, @r0
      00258C 12 2C 15         [24] 6860 	lcall	___fsadd
      00258F C8               [12] 6861 	xch	a,r0
      002590 E5 10            [12] 6862 	mov	a,_bp
      002592 24 05            [12] 6863 	add	a,#0x05
      002594 C8               [12] 6864 	xch	a,r0
      002595 A6 82            [24] 6865 	mov	@r0, dpl
      002597 08               [12] 6866 	inc	r0
      002598 A6 83            [24] 6867 	mov	@r0, dph
      00259A 08               [12] 6868 	inc	r0
      00259B A6 F0            [24] 6869 	mov	@r0, b
      00259D 08               [12] 6870 	inc	r0
      00259E F6               [12] 6871 	mov	@r0,a
      00259F E5 81            [12] 6872 	mov	a,sp
      0025A1 24 FC            [12] 6873 	add	a,#0xfc
      0025A3 F5 81            [12] 6874 	mov	sp,a
      0025A5 E5 10            [12] 6875 	mov	a,_bp
      0025A7 24 F6            [12] 6876 	add	a,#0xf6
      0025A9 F8               [12] 6877 	mov	r0,a
      0025AA E6               [12] 6878 	mov	a,@r0
      0025AB C0 E0            [24] 6879 	push	acc
      0025AD 08               [12] 6880 	inc	r0
      0025AE E6               [12] 6881 	mov	a,@r0
      0025AF C0 E0            [24] 6882 	push	acc
      0025B1 08               [12] 6883 	inc	r0
      0025B2 E6               [12] 6884 	mov	a,@r0
      0025B3 C0 E0            [24] 6885 	push	acc
      0025B5 08               [12] 6886 	inc	r0
      0025B6 E6               [12] 6887 	mov	a,@r0
      0025B7 C0 E0            [24] 6888 	push	acc
      0025B9 E5 10            [12] 6889 	mov	a,_bp
      0025BB 24 FA            [12] 6890 	add	a,#0xfa
      0025BD F8               [12] 6891 	mov	r0,a
      0025BE E6               [12] 6892 	mov	a,@r0
      0025BF C0 E0            [24] 6893 	push	acc
      0025C1 08               [12] 6894 	inc	r0
      0025C2 E6               [12] 6895 	mov	a,@r0
      0025C3 C0 E0            [24] 6896 	push	acc
      0025C5 08               [12] 6897 	inc	r0
      0025C6 E6               [12] 6898 	mov	a,@r0
      0025C7 C0 E0            [24] 6899 	push	acc
      0025C9 08               [12] 6900 	inc	r0
      0025CA E6               [12] 6901 	mov	a,@r0
      0025CB C0 E0            [24] 6902 	push	acc
      0025CD A8 10            [24] 6903 	mov	r0,_bp
      0025CF 08               [12] 6904 	inc	r0
      0025D0 86 82            [24] 6905 	mov	dpl, @r0
      0025D2 08               [12] 6906 	inc	r0
      0025D3 86 83            [24] 6907 	mov	dph, @r0
      0025D5 08               [12] 6908 	inc	r0
      0025D6 86 F0            [24] 6909 	mov	b, @r0
      0025D8 08               [12] 6910 	inc	r0
      0025D9 E6               [12] 6911 	mov	a, @r0
      0025DA 12 1D 6E         [24] 6912 	lcall	_response_balanced
      0025DD AA 82            [24] 6913 	mov	r2, dpl
      0025DF AB 83            [24] 6914 	mov	r3, dph
      0025E1 AE F0            [24] 6915 	mov	r6, b
      0025E3 FF               [12] 6916 	mov	r7, a
      0025E4 E5 81            [12] 6917 	mov	a,sp
      0025E6 24 F8            [12] 6918 	add	a,#0xf8
      0025E8 F5 81            [12] 6919 	mov	sp,a
      0025EA C0 02            [24] 6920 	push	ar2
      0025EC C0 03            [24] 6921 	push	ar3
      0025EE C0 06            [24] 6922 	push	ar6
      0025F0 C0 07            [24] 6923 	push	ar7
      0025F2 E5 10            [12] 6924 	mov	a,_bp
      0025F4 24 25            [12] 6925 	add	a,#0x25
      0025F6 F8               [12] 6926 	mov	r0,a
      0025F7 86 82            [24] 6927 	mov	dpl, @r0
      0025F9 08               [12] 6928 	inc	r0
      0025FA 86 83            [24] 6929 	mov	dph, @r0
      0025FC 08               [12] 6930 	inc	r0
      0025FD 86 F0            [24] 6931 	mov	b, @r0
      0025FF 08               [12] 6932 	inc	r0
      002600 E6               [12] 6933 	mov	a, @r0
      002601 12 2A B5         [24] 6934 	lcall	___fsmul
      002604 AC 82            [24] 6935 	mov	r4, dpl
      002606 AD 83            [24] 6936 	mov	r5, dph
      002608 AE F0            [24] 6937 	mov	r6, b
      00260A FF               [12] 6938 	mov	r7, a
      00260B E5 81            [12] 6939 	mov	a,sp
      00260D 24 FC            [12] 6940 	add	a,#0xfc
      00260F F5 81            [12] 6941 	mov	sp,a
      002611 C0 04            [24] 6942 	push	ar4
      002613 C0 05            [24] 6943 	push	ar5
      002615 C0 06            [24] 6944 	push	ar6
      002617 C0 07            [24] 6945 	push	ar7
      002619 E5 10            [12] 6946 	mov	a,_bp
      00261B 24 05            [12] 6947 	add	a,#0x05
      00261D F8               [12] 6948 	mov	r0,a
      00261E 86 82            [24] 6949 	mov	dpl, @r0
      002620 08               [12] 6950 	inc	r0
      002621 86 83            [24] 6951 	mov	dph, @r0
      002623 08               [12] 6952 	inc	r0
      002624 86 F0            [24] 6953 	mov	b, @r0
      002626 08               [12] 6954 	inc	r0
      002627 E6               [12] 6955 	mov	a, @r0
      002628 12 2C 15         [24] 6956 	lcall	___fsadd
      00262B C8               [12] 6957 	xch	a,r0
      00262C E5 10            [12] 6958 	mov	a,_bp
      00262E 24 05            [12] 6959 	add	a,#0x05
      002630 C8               [12] 6960 	xch	a,r0
      002631 A6 82            [24] 6961 	mov	@r0, dpl
      002633 08               [12] 6962 	inc	r0
      002634 A6 83            [24] 6963 	mov	@r0, dph
      002636 08               [12] 6964 	inc	r0
      002637 A6 F0            [24] 6965 	mov	@r0, b
      002639 08               [12] 6966 	inc	r0
      00263A F6               [12] 6967 	mov	@r0,a
      00263B E5 81            [12] 6968 	mov	a,sp
      00263D 24 FC            [12] 6969 	add	a,#0xfc
      00263F F5 81            [12] 6970 	mov	sp,a
      002641 E5 10            [12] 6971 	mov	a,_bp
      002643 24 F6            [12] 6972 	add	a,#0xf6
      002645 F8               [12] 6973 	mov	r0,a
      002646 E6               [12] 6974 	mov	a,@r0
      002647 C0 E0            [24] 6975 	push	acc
      002649 08               [12] 6976 	inc	r0
      00264A E6               [12] 6977 	mov	a,@r0
      00264B C0 E0            [24] 6978 	push	acc
      00264D 08               [12] 6979 	inc	r0
      00264E E6               [12] 6980 	mov	a,@r0
      00264F C0 E0            [24] 6981 	push	acc
      002651 08               [12] 6982 	inc	r0
      002652 E6               [12] 6983 	mov	a,@r0
      002653 C0 E0            [24] 6984 	push	acc
      002655 E5 10            [12] 6985 	mov	a,_bp
      002657 24 FA            [12] 6986 	add	a,#0xfa
      002659 F8               [12] 6987 	mov	r0,a
      00265A E6               [12] 6988 	mov	a,@r0
      00265B C0 E0            [24] 6989 	push	acc
      00265D 08               [12] 6990 	inc	r0
      00265E E6               [12] 6991 	mov	a,@r0
      00265F C0 E0            [24] 6992 	push	acc
      002661 08               [12] 6993 	inc	r0
      002662 E6               [12] 6994 	mov	a,@r0
      002663 C0 E0            [24] 6995 	push	acc
      002665 08               [12] 6996 	inc	r0
      002666 E6               [12] 6997 	mov	a,@r0
      002667 C0 E0            [24] 6998 	push	acc
      002669 A8 10            [24] 6999 	mov	r0,_bp
      00266B 08               [12] 7000 	inc	r0
      00266C 86 82            [24] 7001 	mov	dpl, @r0
      00266E 08               [12] 7002 	inc	r0
      00266F 86 83            [24] 7003 	mov	dph, @r0
      002671 08               [12] 7004 	inc	r0
      002672 86 F0            [24] 7005 	mov	b, @r0
      002674 08               [12] 7006 	inc	r0
      002675 E6               [12] 7007 	mov	a, @r0
      002676 12 1E 7F         [24] 7008 	lcall	_response_cooling
      002679 AA 82            [24] 7009 	mov	r2, dpl
      00267B AB 83            [24] 7010 	mov	r3, dph
      00267D AE F0            [24] 7011 	mov	r6, b
      00267F FF               [12] 7012 	mov	r7, a
      002680 E5 81            [12] 7013 	mov	a,sp
      002682 24 F8            [12] 7014 	add	a,#0xf8
      002684 F5 81            [12] 7015 	mov	sp,a
      002686 C0 02            [24] 7016 	push	ar2
      002688 C0 03            [24] 7017 	push	ar3
      00268A C0 06            [24] 7018 	push	ar6
      00268C C0 07            [24] 7019 	push	ar7
      00268E E5 10            [12] 7020 	mov	a,_bp
      002690 24 29            [12] 7021 	add	a,#0x29
      002692 F8               [12] 7022 	mov	r0,a
      002693 86 82            [24] 7023 	mov	dpl, @r0
      002695 08               [12] 7024 	inc	r0
      002696 86 83            [24] 7025 	mov	dph, @r0
      002698 08               [12] 7026 	inc	r0
      002699 86 F0            [24] 7027 	mov	b, @r0
      00269B 08               [12] 7028 	inc	r0
      00269C E6               [12] 7029 	mov	a, @r0
      00269D 12 2A B5         [24] 7030 	lcall	___fsmul
      0026A0 AC 82            [24] 7031 	mov	r4, dpl
      0026A2 AD 83            [24] 7032 	mov	r5, dph
      0026A4 AE F0            [24] 7033 	mov	r6, b
      0026A6 FF               [12] 7034 	mov	r7, a
      0026A7 E5 81            [12] 7035 	mov	a,sp
      0026A9 24 FC            [12] 7036 	add	a,#0xfc
      0026AB F5 81            [12] 7037 	mov	sp,a
      0026AD C0 04            [24] 7038 	push	ar4
      0026AF C0 05            [24] 7039 	push	ar5
      0026B1 C0 06            [24] 7040 	push	ar6
      0026B3 C0 07            [24] 7041 	push	ar7
      0026B5 E5 10            [12] 7042 	mov	a,_bp
      0026B7 24 05            [12] 7043 	add	a,#0x05
      0026B9 F8               [12] 7044 	mov	r0,a
      0026BA 86 82            [24] 7045 	mov	dpl, @r0
      0026BC 08               [12] 7046 	inc	r0
      0026BD 86 83            [24] 7047 	mov	dph, @r0
      0026BF 08               [12] 7048 	inc	r0
      0026C0 86 F0            [24] 7049 	mov	b, @r0
      0026C2 08               [12] 7050 	inc	r0
      0026C3 E6               [12] 7051 	mov	a, @r0
      0026C4 12 2C 15         [24] 7052 	lcall	___fsadd
      0026C7 C8               [12] 7053 	xch	a,r0
      0026C8 E5 10            [12] 7054 	mov	a,_bp
      0026CA 24 05            [12] 7055 	add	a,#0x05
      0026CC C8               [12] 7056 	xch	a,r0
      0026CD A6 82            [24] 7057 	mov	@r0, dpl
      0026CF 08               [12] 7058 	inc	r0
      0026D0 A6 83            [24] 7059 	mov	@r0, dph
      0026D2 08               [12] 7060 	inc	r0
      0026D3 A6 F0            [24] 7061 	mov	@r0, b
      0026D5 08               [12] 7062 	inc	r0
      0026D6 F6               [12] 7063 	mov	@r0,a
      0026D7 E5 81            [12] 7064 	mov	a,sp
      0026D9 24 FC            [12] 7065 	add	a,#0xfc
      0026DB F5 81            [12] 7066 	mov	sp,a
      0026DD E5 10            [12] 7067 	mov	a,_bp
      0026DF 24 F6            [12] 7068 	add	a,#0xf6
      0026E1 F8               [12] 7069 	mov	r0,a
      0026E2 E6               [12] 7070 	mov	a,@r0
      0026E3 C0 E0            [24] 7071 	push	acc
      0026E5 08               [12] 7072 	inc	r0
      0026E6 E6               [12] 7073 	mov	a,@r0
      0026E7 C0 E0            [24] 7074 	push	acc
      0026E9 08               [12] 7075 	inc	r0
      0026EA E6               [12] 7076 	mov	a,@r0
      0026EB C0 E0            [24] 7077 	push	acc
      0026ED 08               [12] 7078 	inc	r0
      0026EE E6               [12] 7079 	mov	a,@r0
      0026EF C0 E0            [24] 7080 	push	acc
      0026F1 E5 10            [12] 7081 	mov	a,_bp
      0026F3 24 FA            [12] 7082 	add	a,#0xfa
      0026F5 F8               [12] 7083 	mov	r0,a
      0026F6 E6               [12] 7084 	mov	a,@r0
      0026F7 C0 E0            [24] 7085 	push	acc
      0026F9 08               [12] 7086 	inc	r0
      0026FA E6               [12] 7087 	mov	a,@r0
      0026FB C0 E0            [24] 7088 	push	acc
      0026FD 08               [12] 7089 	inc	r0
      0026FE E6               [12] 7090 	mov	a,@r0
      0026FF C0 E0            [24] 7091 	push	acc
      002701 08               [12] 7092 	inc	r0
      002702 E6               [12] 7093 	mov	a,@r0
      002703 C0 E0            [24] 7094 	push	acc
      002705 A8 10            [24] 7095 	mov	r0,_bp
      002707 08               [12] 7096 	inc	r0
      002708 86 82            [24] 7097 	mov	dpl, @r0
      00270A 08               [12] 7098 	inc	r0
      00270B 86 83            [24] 7099 	mov	dph, @r0
      00270D 08               [12] 7100 	inc	r0
      00270E 86 F0            [24] 7101 	mov	b, @r0
      002710 08               [12] 7102 	inc	r0
      002711 E6               [12] 7103 	mov	a, @r0
      002712 12 1F 8F         [24] 7104 	lcall	_response_heavy_load
      002715 AA 82            [24] 7105 	mov	r2, dpl
      002717 AB 83            [24] 7106 	mov	r3, dph
      002719 AE F0            [24] 7107 	mov	r6, b
      00271B FF               [12] 7108 	mov	r7, a
      00271C E5 81            [12] 7109 	mov	a,sp
      00271E 24 F8            [12] 7110 	add	a,#0xf8
      002720 F5 81            [12] 7111 	mov	sp,a
      002722 C0 02            [24] 7112 	push	ar2
      002724 C0 03            [24] 7113 	push	ar3
      002726 C0 06            [24] 7114 	push	ar6
      002728 C0 07            [24] 7115 	push	ar7
      00272A E5 10            [12] 7116 	mov	a,_bp
      00272C 24 2D            [12] 7117 	add	a,#0x2d
      00272E F8               [12] 7118 	mov	r0,a
      00272F 86 82            [24] 7119 	mov	dpl, @r0
      002731 08               [12] 7120 	inc	r0
      002732 86 83            [24] 7121 	mov	dph, @r0
      002734 08               [12] 7122 	inc	r0
      002735 86 F0            [24] 7123 	mov	b, @r0
      002737 08               [12] 7124 	inc	r0
      002738 E6               [12] 7125 	mov	a, @r0
      002739 12 2A B5         [24] 7126 	lcall	___fsmul
      00273C AC 82            [24] 7127 	mov	r4, dpl
      00273E AD 83            [24] 7128 	mov	r5, dph
      002740 AE F0            [24] 7129 	mov	r6, b
      002742 FF               [12] 7130 	mov	r7, a
      002743 E5 81            [12] 7131 	mov	a,sp
      002745 24 FC            [12] 7132 	add	a,#0xfc
      002747 F5 81            [12] 7133 	mov	sp,a
      002749 C0 04            [24] 7134 	push	ar4
      00274B C0 05            [24] 7135 	push	ar5
      00274D C0 06            [24] 7136 	push	ar6
      00274F C0 07            [24] 7137 	push	ar7
      002751 E5 10            [12] 7138 	mov	a,_bp
      002753 24 05            [12] 7139 	add	a,#0x05
      002755 F8               [12] 7140 	mov	r0,a
      002756 86 82            [24] 7141 	mov	dpl, @r0
      002758 08               [12] 7142 	inc	r0
      002759 86 83            [24] 7143 	mov	dph, @r0
      00275B 08               [12] 7144 	inc	r0
      00275C 86 F0            [24] 7145 	mov	b, @r0
      00275E 08               [12] 7146 	inc	r0
      00275F E6               [12] 7147 	mov	a, @r0
      002760 12 2C 15         [24] 7148 	lcall	___fsadd
      002763 C8               [12] 7149 	xch	a,r0
      002764 E5 10            [12] 7150 	mov	a,_bp
      002766 24 05            [12] 7151 	add	a,#0x05
      002768 C8               [12] 7152 	xch	a,r0
      002769 A6 82            [24] 7153 	mov	@r0, dpl
      00276B 08               [12] 7154 	inc	r0
      00276C A6 83            [24] 7155 	mov	@r0, dph
      00276E 08               [12] 7156 	inc	r0
      00276F A6 F0            [24] 7157 	mov	@r0, b
      002771 08               [12] 7158 	inc	r0
      002772 F6               [12] 7159 	mov	@r0,a
      002773 E5 81            [12] 7160 	mov	a,sp
      002775 24 FC            [12] 7161 	add	a,#0xfc
      002777 F5 81            [12] 7162 	mov	sp,a
      002779 E5 10            [12] 7163 	mov	a,_bp
      00277B 24 F6            [12] 7164 	add	a,#0xf6
      00277D F8               [12] 7165 	mov	r0,a
      00277E E6               [12] 7166 	mov	a,@r0
      00277F C0 E0            [24] 7167 	push	acc
      002781 08               [12] 7168 	inc	r0
      002782 E6               [12] 7169 	mov	a,@r0
      002783 C0 E0            [24] 7170 	push	acc
      002785 08               [12] 7171 	inc	r0
      002786 E6               [12] 7172 	mov	a,@r0
      002787 C0 E0            [24] 7173 	push	acc
      002789 08               [12] 7174 	inc	r0
      00278A E6               [12] 7175 	mov	a,@r0
      00278B C0 E0            [24] 7176 	push	acc
      00278D E5 10            [12] 7177 	mov	a,_bp
      00278F 24 FA            [12] 7178 	add	a,#0xfa
      002791 F8               [12] 7179 	mov	r0,a
      002792 E6               [12] 7180 	mov	a,@r0
      002793 C0 E0            [24] 7181 	push	acc
      002795 08               [12] 7182 	inc	r0
      002796 E6               [12] 7183 	mov	a,@r0
      002797 C0 E0            [24] 7184 	push	acc
      002799 08               [12] 7185 	inc	r0
      00279A E6               [12] 7186 	mov	a,@r0
      00279B C0 E0            [24] 7187 	push	acc
      00279D 08               [12] 7188 	inc	r0
      00279E E6               [12] 7189 	mov	a,@r0
      00279F C0 E0            [24] 7190 	push	acc
      0027A1 A8 10            [24] 7191 	mov	r0,_bp
      0027A3 08               [12] 7192 	inc	r0
      0027A4 86 82            [24] 7193 	mov	dpl, @r0
      0027A6 08               [12] 7194 	inc	r0
      0027A7 86 83            [24] 7195 	mov	dph, @r0
      0027A9 08               [12] 7196 	inc	r0
      0027AA 86 F0            [24] 7197 	mov	b, @r0
      0027AC 08               [12] 7198 	inc	r0
      0027AD E6               [12] 7199 	mov	a, @r0
      0027AE 12 20 74         [24] 7200 	lcall	_response_protection
      0027B1 AA 82            [24] 7201 	mov	r2, dpl
      0027B3 AB 83            [24] 7202 	mov	r3, dph
      0027B5 AE F0            [24] 7203 	mov	r6, b
      0027B7 FF               [12] 7204 	mov	r7, a
      0027B8 E5 81            [12] 7205 	mov	a,sp
      0027BA 24 F8            [12] 7206 	add	a,#0xf8
      0027BC F5 81            [12] 7207 	mov	sp,a
      0027BE C0 02            [24] 7208 	push	ar2
      0027C0 C0 03            [24] 7209 	push	ar3
      0027C2 C0 06            [24] 7210 	push	ar6
      0027C4 C0 07            [24] 7211 	push	ar7
      0027C6 E5 10            [12] 7212 	mov	a,_bp
      0027C8 24 31            [12] 7213 	add	a,#0x31
      0027CA F8               [12] 7214 	mov	r0,a
      0027CB 86 82            [24] 7215 	mov	dpl, @r0
      0027CD 08               [12] 7216 	inc	r0
      0027CE 86 83            [24] 7217 	mov	dph, @r0
      0027D0 08               [12] 7218 	inc	r0
      0027D1 86 F0            [24] 7219 	mov	b, @r0
      0027D3 08               [12] 7220 	inc	r0
      0027D4 E6               [12] 7221 	mov	a, @r0
      0027D5 12 2A B5         [24] 7222 	lcall	___fsmul
      0027D8 AC 82            [24] 7223 	mov	r4, dpl
      0027DA AD 83            [24] 7224 	mov	r5, dph
      0027DC AE F0            [24] 7225 	mov	r6, b
      0027DE FF               [12] 7226 	mov	r7, a
      0027DF E5 81            [12] 7227 	mov	a,sp
      0027E1 24 FC            [12] 7228 	add	a,#0xfc
      0027E3 F5 81            [12] 7229 	mov	sp,a
      0027E5 C0 04            [24] 7230 	push	ar4
      0027E7 C0 05            [24] 7231 	push	ar5
      0027E9 C0 06            [24] 7232 	push	ar6
      0027EB C0 07            [24] 7233 	push	ar7
      0027ED E5 10            [12] 7234 	mov	a,_bp
      0027EF 24 05            [12] 7235 	add	a,#0x05
      0027F1 F8               [12] 7236 	mov	r0,a
      0027F2 86 82            [24] 7237 	mov	dpl, @r0
      0027F4 08               [12] 7238 	inc	r0
      0027F5 86 83            [24] 7239 	mov	dph, @r0
      0027F7 08               [12] 7240 	inc	r0
      0027F8 86 F0            [24] 7241 	mov	b, @r0
      0027FA 08               [12] 7242 	inc	r0
      0027FB E6               [12] 7243 	mov	a, @r0
      0027FC 12 2C 15         [24] 7244 	lcall	___fsadd
      0027FF C8               [12] 7245 	xch	a,r0
      002800 E5 10            [12] 7246 	mov	a,_bp
      002802 24 05            [12] 7247 	add	a,#0x05
      002804 C8               [12] 7248 	xch	a,r0
      002805 A6 82            [24] 7249 	mov	@r0, dpl
      002807 08               [12] 7250 	inc	r0
      002808 A6 83            [24] 7251 	mov	@r0, dph
      00280A 08               [12] 7252 	inc	r0
      00280B A6 F0            [24] 7253 	mov	@r0, b
      00280D 08               [12] 7254 	inc	r0
      00280E F6               [12] 7255 	mov	@r0,a
      00280F E5 81            [12] 7256 	mov	a,sp
      002811 24 FC            [12] 7257 	add	a,#0xfc
      002813 F5 81            [12] 7258 	mov	sp,a
      002815 E5 10            [12] 7259 	mov	a,_bp
      002817 24 21            [12] 7260 	add	a,#0x21
      002819 F8               [12] 7261 	mov	r0,a
      00281A E6               [12] 7262 	mov	a,@r0
      00281B C0 E0            [24] 7263 	push	acc
      00281D 08               [12] 7264 	inc	r0
      00281E E6               [12] 7265 	mov	a,@r0
      00281F C0 E0            [24] 7266 	push	acc
      002821 08               [12] 7267 	inc	r0
      002822 E6               [12] 7268 	mov	a,@r0
      002823 C0 E0            [24] 7269 	push	acc
      002825 08               [12] 7270 	inc	r0
      002826 E6               [12] 7271 	mov	a,@r0
      002827 C0 E0            [24] 7272 	push	acc
      002829 E5 10            [12] 7273 	mov	a,_bp
      00282B 24 1D            [12] 7274 	add	a,#0x1d
      00282D F8               [12] 7275 	mov	r0,a
      00282E 86 82            [24] 7276 	mov	dpl, @r0
      002830 08               [12] 7277 	inc	r0
      002831 86 83            [24] 7278 	mov	dph, @r0
      002833 08               [12] 7279 	inc	r0
      002834 86 F0            [24] 7280 	mov	b, @r0
      002836 08               [12] 7281 	inc	r0
      002837 E6               [12] 7282 	mov	a, @r0
      002838 12 2C 15         [24] 7283 	lcall	___fsadd
      00283B AA 82            [24] 7284 	mov	r2, dpl
      00283D AB 83            [24] 7285 	mov	r3, dph
      00283F AE F0            [24] 7286 	mov	r6, b
      002841 FF               [12] 7287 	mov	r7, a
      002842 E5 81            [12] 7288 	mov	a,sp
      002844 24 FC            [12] 7289 	add	a,#0xfc
      002846 F5 81            [12] 7290 	mov	sp,a
      002848 E5 10            [12] 7291 	mov	a,_bp
      00284A 24 25            [12] 7292 	add	a,#0x25
      00284C F8               [12] 7293 	mov	r0,a
      00284D E6               [12] 7294 	mov	a,@r0
      00284E C0 E0            [24] 7295 	push	acc
      002850 08               [12] 7296 	inc	r0
      002851 E6               [12] 7297 	mov	a,@r0
      002852 C0 E0            [24] 7298 	push	acc
      002854 08               [12] 7299 	inc	r0
      002855 E6               [12] 7300 	mov	a,@r0
      002856 C0 E0            [24] 7301 	push	acc
      002858 08               [12] 7302 	inc	r0
      002859 E6               [12] 7303 	mov	a,@r0
      00285A C0 E0            [24] 7304 	push	acc
      00285C 8A 82            [24] 7305 	mov	dpl, r2
      00285E 8B 83            [24] 7306 	mov	dph, r3
      002860 8E F0            [24] 7307 	mov	b, r6
      002862 EF               [12] 7308 	mov	a, r7
      002863 12 2C 15         [24] 7309 	lcall	___fsadd
      002866 AC 82            [24] 7310 	mov	r4, dpl
      002868 AD 83            [24] 7311 	mov	r5, dph
      00286A AE F0            [24] 7312 	mov	r6, b
      00286C FF               [12] 7313 	mov	r7, a
      00286D E5 81            [12] 7314 	mov	a,sp
      00286F 24 FC            [12] 7315 	add	a,#0xfc
      002871 F5 81            [12] 7316 	mov	sp,a
      002873 E5 10            [12] 7317 	mov	a,_bp
      002875 24 29            [12] 7318 	add	a,#0x29
      002877 F8               [12] 7319 	mov	r0,a
      002878 E6               [12] 7320 	mov	a,@r0
      002879 C0 E0            [24] 7321 	push	acc
      00287B 08               [12] 7322 	inc	r0
      00287C E6               [12] 7323 	mov	a,@r0
      00287D C0 E0            [24] 7324 	push	acc
      00287F 08               [12] 7325 	inc	r0
      002880 E6               [12] 7326 	mov	a,@r0
      002881 C0 E0            [24] 7327 	push	acc
      002883 08               [12] 7328 	inc	r0
      002884 E6               [12] 7329 	mov	a,@r0
      002885 C0 E0            [24] 7330 	push	acc
      002887 8C 82            [24] 7331 	mov	dpl, r4
      002889 8D 83            [24] 7332 	mov	dph, r5
      00288B 8E F0            [24] 7333 	mov	b, r6
      00288D EF               [12] 7334 	mov	a, r7
      00288E 12 2C 15         [24] 7335 	lcall	___fsadd
      002891 AC 82            [24] 7336 	mov	r4, dpl
      002893 AD 83            [24] 7337 	mov	r5, dph
      002895 AE F0            [24] 7338 	mov	r6, b
      002897 FF               [12] 7339 	mov	r7, a
      002898 E5 81            [12] 7340 	mov	a,sp
      00289A 24 FC            [12] 7341 	add	a,#0xfc
      00289C F5 81            [12] 7342 	mov	sp,a
      00289E E5 10            [12] 7343 	mov	a,_bp
      0028A0 24 2D            [12] 7344 	add	a,#0x2d
      0028A2 F8               [12] 7345 	mov	r0,a
      0028A3 E6               [12] 7346 	mov	a,@r0
      0028A4 C0 E0            [24] 7347 	push	acc
      0028A6 08               [12] 7348 	inc	r0
      0028A7 E6               [12] 7349 	mov	a,@r0
      0028A8 C0 E0            [24] 7350 	push	acc
      0028AA 08               [12] 7351 	inc	r0
      0028AB E6               [12] 7352 	mov	a,@r0
      0028AC C0 E0            [24] 7353 	push	acc
      0028AE 08               [12] 7354 	inc	r0
      0028AF E6               [12] 7355 	mov	a,@r0
      0028B0 C0 E0            [24] 7356 	push	acc
      0028B2 8C 82            [24] 7357 	mov	dpl, r4
      0028B4 8D 83            [24] 7358 	mov	dph, r5
      0028B6 8E F0            [24] 7359 	mov	b, r6
      0028B8 EF               [12] 7360 	mov	a, r7
      0028B9 12 2C 15         [24] 7361 	lcall	___fsadd
      0028BC AC 82            [24] 7362 	mov	r4, dpl
      0028BE AD 83            [24] 7363 	mov	r5, dph
      0028C0 AE F0            [24] 7364 	mov	r6, b
      0028C2 FF               [12] 7365 	mov	r7, a
      0028C3 E5 81            [12] 7366 	mov	a,sp
      0028C5 24 FC            [12] 7367 	add	a,#0xfc
      0028C7 F5 81            [12] 7368 	mov	sp,a
      0028C9 E5 10            [12] 7369 	mov	a,_bp
      0028CB 24 31            [12] 7370 	add	a,#0x31
      0028CD F8               [12] 7371 	mov	r0,a
      0028CE E6               [12] 7372 	mov	a,@r0
      0028CF C0 E0            [24] 7373 	push	acc
      0028D1 08               [12] 7374 	inc	r0
      0028D2 E6               [12] 7375 	mov	a,@r0
      0028D3 C0 E0            [24] 7376 	push	acc
      0028D5 08               [12] 7377 	inc	r0
      0028D6 E6               [12] 7378 	mov	a,@r0
      0028D7 C0 E0            [24] 7379 	push	acc
      0028D9 08               [12] 7380 	inc	r0
      0028DA E6               [12] 7381 	mov	a,@r0
      0028DB C0 E0            [24] 7382 	push	acc
      0028DD 8C 82            [24] 7383 	mov	dpl, r4
      0028DF 8D 83            [24] 7384 	mov	dph, r5
      0028E1 8E F0            [24] 7385 	mov	b, r6
      0028E3 EF               [12] 7386 	mov	a, r7
      0028E4 12 2C 15         [24] 7387 	lcall	___fsadd
      0028E7 AC 82            [24] 7388 	mov	r4, dpl
      0028E9 AD 83            [24] 7389 	mov	r5, dph
      0028EB AE F0            [24] 7390 	mov	r6, b
      0028ED FF               [12] 7391 	mov	r7, a
      0028EE E5 81            [12] 7392 	mov	a,sp
      0028F0 24 FC            [12] 7393 	add	a,#0xfc
      0028F2 F5 81            [12] 7394 	mov	sp,a
      0028F4 C0 04            [24] 7395 	push	ar4
      0028F6 C0 05            [24] 7396 	push	ar5
      0028F8 C0 06            [24] 7397 	push	ar6
      0028FA C0 07            [24] 7398 	push	ar7
      0028FC E5 10            [12] 7399 	mov	a,_bp
      0028FE 24 05            [12] 7400 	add	a,#0x05
      002900 F8               [12] 7401 	mov	r0,a
      002901 86 82            [24] 7402 	mov	dpl, @r0
      002903 08               [12] 7403 	inc	r0
      002904 86 83            [24] 7404 	mov	dph, @r0
      002906 08               [12] 7405 	inc	r0
      002907 86 F0            [24] 7406 	mov	b, @r0
      002909 08               [12] 7407 	inc	r0
      00290A E6               [12] 7408 	mov	a, @r0
      00290B 12 2D 2C         [24] 7409 	lcall	___fsdiv
      00290E AC 82            [24] 7410 	mov	r4, dpl
      002910 AD 83            [24] 7411 	mov	r5, dph
      002912 AE F0            [24] 7412 	mov	r6, b
      002914 FF               [12] 7413 	mov	r7, a
      002915 E5 81            [12] 7414 	mov	a,sp
      002917 24 FC            [12] 7415 	add	a,#0xfc
      002919 F5 81            [12] 7416 	mov	sp,a
      00291B 8C 82            [24] 7417 	mov	dpl, r4
      00291D 8D 83            [24] 7418 	mov	dph, r5
      00291F 8E F0            [24] 7419 	mov	b, r6
      002921 EF               [12] 7420 	mov	a, r7
                           002865  7421 	C$sugeno_demo.c$60$1_0$75 ==.
                                   7422 ;	../../sugeno_demo.c:60: }
      002922 85 10 81         [24] 7423 	mov	sp,_bp
      002925 D0 10            [24] 7424 	pop	_bp
                           00286A  7425 	C$sugeno_demo.c$60$1_0$75 ==.
                           00286A  7426 	XFsugeno_demo$calculate_fan_speed$0$0 ==.
      002927 22               [24] 7427 	ret
                                   7428 ;------------------------------------------------------------
                                   7429 ;Allocation info for local variables in function 'fan_speed_to_pwm'
                                   7430 ;------------------------------------------------------------
                                   7431 ;fan_speed     Allocated to registers r4 r5 r6 r7 
                                   7432 ;------------------------------------------------------------
                           00286B  7433 	Fsugeno_demo$fan_speed_to_pwm$0$0 ==.
                           00286B  7434 	C$sugeno_demo.c$62$1_0$77 ==.
                                   7435 ;	../../sugeno_demo.c:62: static unsigned char fan_speed_to_pwm(float fan_speed)
                                   7436 ;	-----------------------------------------
                                   7437 ;	 function fan_speed_to_pwm
                                   7438 ;	-----------------------------------------
      002928                       7439 _fan_speed_to_pwm:
      002928 AC 82            [24] 7440 	mov	r4,dpl
      00292A AD 83            [24] 7441 	mov	r5,dph
      00292C AE F0            [24] 7442 	mov	r6,b
      00292E FF               [12] 7443 	mov	r7,a
                           002872  7444 	C$sugeno_demo.c$64$1_0$77 ==.
                                   7445 ;	../../sugeno_demo.c:64: if (fan_speed <= 0.0f) return 0u;
      00292F C0 07            [24] 7446 	push	ar7
      002931 C0 06            [24] 7447 	push	ar6
      002933 C0 05            [24] 7448 	push	ar5
      002935 C0 04            [24] 7449 	push	ar4
      002937 C0 04            [24] 7450 	push	ar4
      002939 C0 05            [24] 7451 	push	ar5
      00293B C0 06            [24] 7452 	push	ar6
      00293D C0 07            [24] 7453 	push	ar7
      00293F 90 00 00         [24] 7454 	mov	dptr,#0x0000
      002942 E4               [12] 7455 	clr	a
      002943 F5 F0            [12] 7456 	mov	b,a
      002945 12 2B E5         [24] 7457 	lcall	___fslt
      002948 E5 81            [12] 7458 	mov	a,sp
      00294A 24 FC            [12] 7459 	add	a,#0xfc
      00294C F5 81            [12] 7460 	mov	sp,a
      00294E D0 04            [24] 7461 	pop	ar4
      002950 D0 05            [24] 7462 	pop	ar5
      002952 D0 06            [24] 7463 	pop	ar6
      002954 D0 07            [24] 7464 	pop	ar7
      002956 E5 82            [12] 7465 	mov	a, dpl
      002958 24 FF            [12] 7466 	add	a,#0xff
      00295A 92 00            [24] 7467 	mov	b0,c
      00295C 40 05            [24] 7468 	jc	00102$
      00295E 75 82 00         [24] 7469 	mov	dpl, #0x00
      002961 80 66            [24] 7470 	sjmp	00105$
      002963                       7471 00102$:
                           0028A6  7472 	C$sugeno_demo.c$65$1_0$77 ==.
                                   7473 ;	../../sugeno_demo.c:65: if (fan_speed >= 100.0f) return 100u;
      002963 C0 07            [24] 7474 	push	ar7
      002965 C0 06            [24] 7475 	push	ar6
      002967 C0 05            [24] 7476 	push	ar5
      002969 C0 04            [24] 7477 	push	ar4
      00296B E4               [12] 7478 	clr	a
      00296C C0 E0            [24] 7479 	push	acc
      00296E C0 E0            [24] 7480 	push	acc
      002970 74 C8            [12] 7481 	mov	a,#0xc8
      002972 C0 E0            [24] 7482 	push	acc
      002974 74 42            [12] 7483 	mov	a,#0x42
      002976 C0 E0            [24] 7484 	push	acc
      002978 8C 82            [24] 7485 	mov	dpl, r4
      00297A 8D 83            [24] 7486 	mov	dph, r5
      00297C 8E F0            [24] 7487 	mov	b, r6
      00297E EF               [12] 7488 	mov	a, r7
      00297F 12 2B E5         [24] 7489 	lcall	___fslt
      002982 E5 81            [12] 7490 	mov	a,sp
      002984 24 FC            [12] 7491 	add	a,#0xfc
      002986 F5 81            [12] 7492 	mov	sp,a
      002988 D0 04            [24] 7493 	pop	ar4
      00298A D0 05            [24] 7494 	pop	ar5
      00298C D0 06            [24] 7495 	pop	ar6
      00298E D0 07            [24] 7496 	pop	ar7
      002990 E5 82            [12] 7497 	mov	a, dpl
      002992 24 FF            [12] 7498 	add	a,#0xff
      002994 92 00            [24] 7499 	mov	b0,c
      002996 40 05            [24] 7500 	jc	00104$
      002998 75 82 64         [24] 7501 	mov	dpl, #0x64
      00299B 80 2C            [24] 7502 	sjmp	00105$
      00299D                       7503 00104$:
                           0028E0  7504 	C$sugeno_demo.c$66$1_0$77 ==.
                                   7505 ;	../../sugeno_demo.c:66: return (unsigned char)(fan_speed + 0.5f);
      00299D E4               [12] 7506 	clr	a
      00299E C0 E0            [24] 7507 	push	acc
      0029A0 C0 E0            [24] 7508 	push	acc
      0029A2 C0 E0            [24] 7509 	push	acc
      0029A4 74 3F            [12] 7510 	mov	a,#0x3f
      0029A6 C0 E0            [24] 7511 	push	acc
      0029A8 8C 82            [24] 7512 	mov	dpl, r4
      0029AA 8D 83            [24] 7513 	mov	dph, r5
      0029AC 8E F0            [24] 7514 	mov	b, r6
      0029AE EF               [12] 7515 	mov	a, r7
      0029AF 12 2C 15         [24] 7516 	lcall	___fsadd
      0029B2 AC 82            [24] 7517 	mov	r4, dpl
      0029B4 AD 83            [24] 7518 	mov	r5, dph
      0029B6 AE F0            [24] 7519 	mov	r6, b
      0029B8 FF               [12] 7520 	mov	r7, a
      0029B9 E5 81            [12] 7521 	mov	a,sp
      0029BB 24 FC            [12] 7522 	add	a,#0xfc
      0029BD F5 81            [12] 7523 	mov	sp,a
      0029BF 8C 82            [24] 7524 	mov	dpl, r4
      0029C1 8D 83            [24] 7525 	mov	dph, r5
      0029C3 8E F0            [24] 7526 	mov	b, r6
      0029C5 EF               [12] 7527 	mov	a, r7
      0029C6 12 2E 0B         [24] 7528 	lcall	___fs2uchar
      0029C9                       7529 00105$:
                           00290C  7530 	C$sugeno_demo.c$67$1_0$77 ==.
                                   7531 ;	../../sugeno_demo.c:67: }
                           00290C  7532 	C$sugeno_demo.c$67$1_0$77 ==.
                           00290C  7533 	XFsugeno_demo$fan_speed_to_pwm$0$0 ==.
      0029C9 22               [24] 7534 	ret
                                   7535 ;------------------------------------------------------------
                                   7536 ;Allocation info for local variables in function 'update_controller'
                                   7537 ;------------------------------------------------------------
                                   7538 ;load          Allocated to stack - _bp -3 +1 
                                   7539 ;vibration     Allocated to stack - _bp -4 +1 
                                   7540 ;temperature   Allocated to registers 
                                   7541 ;sloc0         Allocated to stack - _bp +1 +4 
                                   7542 ;sloc1         Allocated to stack - _bp +5 +4 
                                   7543 ;------------------------------------------------------------
                           00290D  7544 	Fsugeno_demo$update_controller$0$0 ==.
                           00290D  7545 	C$sugeno_demo.c$69$1_0$79 ==.
                                   7546 ;	../../sugeno_demo.c:69: static void update_controller(unsigned char temperature, unsigned char load, unsigned char vibration)
                                   7547 ;	-----------------------------------------
                                   7548 ;	 function update_controller
                                   7549 ;	-----------------------------------------
      0029CA                       7550 _update_controller:
      0029CA C0 10            [24] 7551 	push	_bp
      0029CC E5 81            [12] 7552 	mov	a,sp
      0029CE F5 10            [12] 7553 	mov	_bp,a
      0029D0 24 08            [12] 7554 	add	a,#0x08
      0029D2 F5 81            [12] 7555 	mov	sp,a
      0029D4 85 82 08         [24] 7556 	mov	_test_temperature,dpl
                           00291A  7557 	C$sugeno_demo.c$72$1_0$79 ==.
                                   7558 ;	../../sugeno_demo.c:72: test_load = load;
      0029D7 E5 10            [12] 7559 	mov	a,_bp
      0029D9 24 FD            [12] 7560 	add	a,#0xfd
      0029DB F8               [12] 7561 	mov	r0,a
      0029DC 86 09            [24] 7562 	mov	_test_load,@r0
                           002921  7563 	C$sugeno_demo.c$73$1_0$79 ==.
                                   7564 ;	../../sugeno_demo.c:73: test_vibration = vibration;
      0029DE E5 10            [12] 7565 	mov	a,_bp
      0029E0 24 FC            [12] 7566 	add	a,#0xfc
      0029E2 F8               [12] 7567 	mov	r0,a
      0029E3 86 0A            [24] 7568 	mov	_test_vibration,@r0
                           002928  7569 	C$sugeno_demo.c$74$1_0$79 ==.
                                   7570 ;	../../sugeno_demo.c:74: test_fan_speed = calculate_fan_speed((float)test_temperature, (float)test_load, (float)test_vibration);
      0029E5 85 0A 82         [24] 7571 	mov	dpl, _test_vibration
      0029E8 12 2E 13         [24] 7572 	lcall	___uchar2fs
      0029EB A8 10            [24] 7573 	mov	r0,_bp
      0029ED 08               [12] 7574 	inc	r0
      0029EE A6 82            [24] 7575 	mov	@r0, dpl
      0029F0 08               [12] 7576 	inc	r0
      0029F1 A6 83            [24] 7577 	mov	@r0, dph
      0029F3 08               [12] 7578 	inc	r0
      0029F4 A6 F0            [24] 7579 	mov	@r0, b
      0029F6 08               [12] 7580 	inc	r0
      0029F7 F6               [12] 7581 	mov	@r0,a
      0029F8 85 09 82         [24] 7582 	mov	dpl, _test_load
      0029FB 12 2E 13         [24] 7583 	lcall	___uchar2fs
      0029FE C8               [12] 7584 	xch	a,r0
      0029FF E5 10            [12] 7585 	mov	a,_bp
      002A01 24 05            [12] 7586 	add	a,#0x05
      002A03 C8               [12] 7587 	xch	a,r0
      002A04 A6 82            [24] 7588 	mov	@r0, dpl
      002A06 08               [12] 7589 	inc	r0
      002A07 A6 83            [24] 7590 	mov	@r0, dph
      002A09 08               [12] 7591 	inc	r0
      002A0A A6 F0            [24] 7592 	mov	@r0, b
      002A0C 08               [12] 7593 	inc	r0
      002A0D F6               [12] 7594 	mov	@r0,a
      002A0E 85 08 82         [24] 7595 	mov	dpl, _test_temperature
      002A11 12 2E 13         [24] 7596 	lcall	___uchar2fs
      002A14 AC 82            [24] 7597 	mov	r4, dpl
      002A16 AD 83            [24] 7598 	mov	r5, dph
      002A18 AE F0            [24] 7599 	mov	r6, b
      002A1A FF               [12] 7600 	mov	r7, a
      002A1B A8 10            [24] 7601 	mov	r0,_bp
      002A1D 08               [12] 7602 	inc	r0
      002A1E E6               [12] 7603 	mov	a,@r0
      002A1F C0 E0            [24] 7604 	push	acc
      002A21 08               [12] 7605 	inc	r0
      002A22 E6               [12] 7606 	mov	a,@r0
      002A23 C0 E0            [24] 7607 	push	acc
      002A25 08               [12] 7608 	inc	r0
      002A26 E6               [12] 7609 	mov	a,@r0
      002A27 C0 E0            [24] 7610 	push	acc
      002A29 08               [12] 7611 	inc	r0
      002A2A E6               [12] 7612 	mov	a,@r0
      002A2B C0 E0            [24] 7613 	push	acc
      002A2D E5 10            [12] 7614 	mov	a,_bp
      002A2F 24 05            [12] 7615 	add	a,#0x05
      002A31 F8               [12] 7616 	mov	r0,a
      002A32 E6               [12] 7617 	mov	a,@r0
      002A33 C0 E0            [24] 7618 	push	acc
      002A35 08               [12] 7619 	inc	r0
      002A36 E6               [12] 7620 	mov	a,@r0
      002A37 C0 E0            [24] 7621 	push	acc
      002A39 08               [12] 7622 	inc	r0
      002A3A E6               [12] 7623 	mov	a,@r0
      002A3B C0 E0            [24] 7624 	push	acc
      002A3D 08               [12] 7625 	inc	r0
      002A3E E6               [12] 7626 	mov	a,@r0
      002A3F C0 E0            [24] 7627 	push	acc
      002A41 8C 82            [24] 7628 	mov	dpl, r4
      002A43 8D 83            [24] 7629 	mov	dph, r5
      002A45 8E F0            [24] 7630 	mov	b, r6
      002A47 EF               [12] 7631 	mov	a, r7
      002A48 12 21 85         [24] 7632 	lcall	_calculate_fan_speed
      002A4B 85 82 0C         [24] 7633 	mov	_test_fan_speed,dpl
      002A4E 85 83 0D         [24] 7634 	mov	(_test_fan_speed + 1),dph
      002A51 85 F0 0E         [24] 7635 	mov	(_test_fan_speed + 2),b
      002A54 F5 0F            [12] 7636 	mov	(_test_fan_speed + 3),a
      002A56 E5 81            [12] 7637 	mov	a,sp
      002A58 24 F8            [12] 7638 	add	a,#0xf8
      002A5A F5 81            [12] 7639 	mov	sp,a
                           00299F  7640 	C$sugeno_demo.c$75$1_0$79 ==.
                                   7641 ;	../../sugeno_demo.c:75: test_pwm = fan_speed_to_pwm(test_fan_speed);
      002A5C 85 0C 82         [24] 7642 	mov	dpl, _test_fan_speed
      002A5F 85 0D 83         [24] 7643 	mov	dph, (_test_fan_speed + 1)
      002A62 85 0E F0         [24] 7644 	mov	b, (_test_fan_speed + 2)
      002A65 E5 0F            [12] 7645 	mov	a, (_test_fan_speed + 3)
      002A67 12 29 28         [24] 7646 	lcall	_fan_speed_to_pwm
      002A6A 85 82 0B         [24] 7647 	mov	_test_pwm,dpl
                           0029B0  7648 	C$sugeno_demo.c$76$1_0$79 ==.
                                   7649 ;	../../sugeno_demo.c:76: }
      002A6D 85 10 81         [24] 7650 	mov	sp,_bp
      002A70 D0 10            [24] 7651 	pop	_bp
                           0029B5  7652 	C$sugeno_demo.c$76$1_0$79 ==.
                           0029B5  7653 	XFsugeno_demo$update_controller$0$0 ==.
      002A72 22               [24] 7654 	ret
                                   7655 ;------------------------------------------------------------
                                   7656 ;Allocation info for local variables in function 'main'
                                   7657 ;------------------------------------------------------------
                           0029B6  7658 	G$main$0$0 ==.
                           0029B6  7659 	C$sugeno_demo.c$80$1_0$81 ==.
                                   7660 ;	../../sugeno_demo.c:80: void main(void)
                                   7661 ;	-----------------------------------------
                                   7662 ;	 function main
                                   7663 ;	-----------------------------------------
      002A73                       7664 _main:
                           0029B6  7665 	C$sugeno_demo.c$82$1_0$81 ==.
                                   7666 ;	../../sugeno_demo.c:82: P1 = 0x00u;
      002A73 75 90 00         [24] 7667 	mov	_P1,#0x00
      002A76                       7668 00107$:
                           0029B9  7669 	C$sugeno_demo.c$85$3_0$83 ==.
                                   7670 ;	../../sugeno_demo.c:85: test_vibration = P0;
      002A76 85 80 0A         [24] 7671 	mov	_test_vibration,_P0
                           0029BC  7672 	C$sugeno_demo.c$86$3_0$83 ==.
                                   7673 ;	../../sugeno_demo.c:86: test_temperature = P2;
      002A79 85 A0 08         [24] 7674 	mov	_test_temperature,_P2
                           0029BF  7675 	C$sugeno_demo.c$87$3_0$83 ==.
                                   7676 ;	../../sugeno_demo.c:87: test_load = P3;
      002A7C 85 B0 09         [24] 7677 	mov	_test_load,_P3
                           0029C2  7678 	C$sugeno_demo.c$89$3_0$83 ==.
                                   7679 ;	../../sugeno_demo.c:89: if (test_temperature > 100u || test_load > 100u || test_vibration > 10u) {
      002A7F E5 08            [12] 7680 	mov	a,_test_temperature
      002A81 24 9B            [12] 7681 	add	a,#0xff - 0x64
      002A83 40 0C            [24] 7682 	jc	00101$
      002A85 E5 09            [12] 7683 	mov	a,_test_load
      002A87 24 9B            [12] 7684 	add	a,#0xff - 0x64
      002A89 40 06            [24] 7685 	jc	00101$
      002A8B E5 0A            [12] 7686 	mov	a,_test_vibration
      002A8D 24 F5            [12] 7687 	add	a,#0xff - 0x0a
      002A8F 50 05            [24] 7688 	jnc	00102$
      002A91                       7689 00101$:
                           0029D4  7690 	C$sugeno_demo.c$90$4_0$84 ==.
                                   7691 ;	../../sugeno_demo.c:90: P1 = 0x00u;
      002A91 75 90 00         [24] 7692 	mov	_P1,#0x00
                           0029D7  7693 	C$sugeno_demo.c$91$4_0$84 ==.
                                   7694 ;	../../sugeno_demo.c:91: continue;
      002A94 80 E0            [24] 7695 	sjmp	00107$
      002A96                       7696 00102$:
                           0029D9  7697 	C$sugeno_demo.c$95$3_0$83 ==.
                                   7698 ;	../../sugeno_demo.c:95: test_temperature,
      002A96 C0 0A            [24] 7699 	push	_test_vibration
      002A98 C0 09            [24] 7700 	push	_test_load
      002A9A 85 08 82         [24] 7701 	mov	dpl, _test_temperature
      002A9D 12 29 CA         [24] 7702 	lcall	_update_controller
      002AA0 15 81            [12] 7703 	dec	sp
      002AA2 15 81            [12] 7704 	dec	sp
                           0029E7  7705 	C$sugeno_demo.c$100$3_0$83 ==.
                                   7706 ;	../../sugeno_demo.c:100: P1 = test_pwm;
      002AA4 85 0B 90         [24] 7707 	mov	_P1,_test_pwm
      002AA7 80 CD            [24] 7708 	sjmp	00107$
                           0029EC  7709 	C$sugeno_demo.c$102$2_0$81 ==.
                                   7710 ;	../../sugeno_demo.c:102: }
                           0029EC  7711 	C$sugeno_demo.c$102$2_0$81 ==.
                           0029EC  7712 	XG$main$0$0 ==.
      002AA9 22               [24] 7713 	ret
                                   7714 	.area CSEG    (CODE)
                                   7715 	.area CONST   (CODE)
                                   7716 	.area CONST   (CODE)
                           000000  7717 Fsugeno_demo$temperature_low_fuzzy_variable$0_0$0 == .
      002EB1                       7718 _temperature_low_fuzzy_variable:
      002EB1 00                    7719 	.db #0x00	; 0
      002EB2 01                    7720 	.db #0x01	; 1
      002EB3 00 00 70 41           7721 	.byte #0x00, #0x00, #0x70, #0x41	;  1.500000e+01
      002EB7 00 00 20 42           7722 	.byte #0x00, #0x00, #0x20, #0x42	;  4.000000e+01
      002EBB 00 00 00 00           7723 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
      002EBF 00 00 00 00           7724 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   7725 	.area CSEG    (CODE)
                                   7726 	.area CONST   (CODE)
                           000012  7727 Fsugeno_demo$temperature_high_fuzzy_variable$0_0$0 == .
      002EC3                       7728 _temperature_high_fuzzy_variable:
      002EC3 00                    7729 	.db #0x00	; 0
      002EC4 01                    7730 	.db #0x01	; 1
      002EC5 00 00 0C 42           7731 	.byte #0x00, #0x00, #0x0c, #0x42	;  3.500000e+01
      002EC9 00 00 96 42           7732 	.byte #0x00, #0x00, #0x96, #0x42	;  7.500000e+01
      002ECD 00 00 80 3F           7733 	.byte #0x00, #0x00, #0x80, #0x3f	;  1.000000e+00
      002ED1 00 00 00 00           7734 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   7735 	.area CSEG    (CODE)
                                   7736 	.area CONST   (CODE)
                           000024  7737 Fsugeno_demo$load_low_fuzzy_variable$0_0$0 == .
      002ED5                       7738 _load_low_fuzzy_variable:
      002ED5 00                    7739 	.db #0x00	; 0
      002ED6 01                    7740 	.db #0x01	; 1
      002ED7 00 00 A0 41           7741 	.byte #0x00, #0x00, #0xa0, #0x41	;  2.000000e+01
      002EDB 00 00 48 42           7742 	.byte #0x00, #0x00, #0x48, #0x42	;  5.000000e+01
      002EDF 00 00 00 00           7743 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
      002EE3 00 00 00 00           7744 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   7745 	.area CSEG    (CODE)
                                   7746 	.area CONST   (CODE)
                           000036  7747 Fsugeno_demo$load_high_fuzzy_variable$0_0$0 == .
      002EE7                       7748 _load_high_fuzzy_variable:
      002EE7 00                    7749 	.db #0x00	; 0
      002EE8 01                    7750 	.db #0x01	; 1
      002EE9 00 00 34 42           7751 	.byte #0x00, #0x00, #0x34, #0x42	;  4.500000e+01
      002EED 00 00 AA 42           7752 	.byte #0x00, #0x00, #0xaa, #0x42	;  8.500000e+01
      002EF1 00 00 80 3F           7753 	.byte #0x00, #0x00, #0x80, #0x3f	;  1.000000e+00
      002EF5 00 00 00 00           7754 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   7755 	.area CSEG    (CODE)
                                   7756 	.area CONST   (CODE)
                           000048  7757 Fsugeno_demo$vibration_low_fuzzy_variable$0_0$0 == .
      002EF9                       7758 _vibration_low_fuzzy_variable:
      002EF9 00                    7759 	.db #0x00	; 0
      002EFA 01                    7760 	.db #0x01	; 1
      002EFB 00 00 80 3F           7761 	.byte #0x00, #0x00, #0x80, #0x3f	;  1.000000e+00
      002EFF 00 00 80 40           7762 	.byte #0x00, #0x00, #0x80, #0x40	;  4.000000e+00
      002F03 00 00 00 00           7763 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
      002F07 00 00 00 00           7764 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   7765 	.area CSEG    (CODE)
                                   7766 	.area CONST   (CODE)
                           00005A  7767 Fsugeno_demo$vibration_high_fuzzy_variable$0_0$0 == .
      002F0B                       7768 _vibration_high_fuzzy_variable:
      002F0B 00                    7769 	.db #0x00	; 0
      002F0C 01                    7770 	.db #0x01	; 1
      002F0D 00 00 40 40           7771 	.byte #0x00, #0x00, #0x40, #0x40	;  3.000000e+00
      002F11 00 00 00 41           7772 	.byte #0x00, #0x00, #0x00, #0x41	;  8.000000e+00
      002F15 00 00 80 3F           7773 	.byte #0x00, #0x00, #0x80, #0x3f	;  1.000000e+00
      002F19 00 00 00 00           7774 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   7775 	.area CSEG    (CODE)
                                   7776 	.area XINIT   (CODE)
                                   7777 	.area CABS    (ABS,CODE)
