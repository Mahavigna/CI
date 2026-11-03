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
                                    135 	.globl _fuzzy_ramp
                                    136 	.globl _fuzzy_triangle
                                    137 	.globl _fuzzy_trapezoid
                                    138 	.globl _fuzzy_rules_add_8051
                                    139 	.globl _fuzzy_rules_defuzzify
                                    140 	.globl _fuzzy_rules_cog
                                    141 ;--------------------------------------------------------
                                    142 ; special function registers
                                    143 ;--------------------------------------------------------
                                    144 	.area RSEG    (ABS,DATA)
      000000                        145 	.org 0x0000
                           000080   146 G$P0$0_0$0 == 0x0080
                           000080   147 _P0	=	0x0080
                           000081   148 G$SP$0_0$0 == 0x0081
                           000081   149 _SP	=	0x0081
                           000082   150 G$DPL$0_0$0 == 0x0082
                           000082   151 _DPL	=	0x0082
                           000083   152 G$DPH$0_0$0 == 0x0083
                           000083   153 _DPH	=	0x0083
                           000087   154 G$PCON$0_0$0 == 0x0087
                           000087   155 _PCON	=	0x0087
                           000088   156 G$TCON$0_0$0 == 0x0088
                           000088   157 _TCON	=	0x0088
                           000089   158 G$TMOD$0_0$0 == 0x0089
                           000089   159 _TMOD	=	0x0089
                           00008A   160 G$TL0$0_0$0 == 0x008a
                           00008A   161 _TL0	=	0x008a
                           00008B   162 G$TL1$0_0$0 == 0x008b
                           00008B   163 _TL1	=	0x008b
                           00008C   164 G$TH0$0_0$0 == 0x008c
                           00008C   165 _TH0	=	0x008c
                           00008D   166 G$TH1$0_0$0 == 0x008d
                           00008D   167 _TH1	=	0x008d
                           000090   168 G$P1$0_0$0 == 0x0090
                           000090   169 _P1	=	0x0090
                           000098   170 G$SCON$0_0$0 == 0x0098
                           000098   171 _SCON	=	0x0098
                           000099   172 G$SBUF$0_0$0 == 0x0099
                           000099   173 _SBUF	=	0x0099
                           0000A0   174 G$P2$0_0$0 == 0x00a0
                           0000A0   175 _P2	=	0x00a0
                           0000A8   176 G$IE$0_0$0 == 0x00a8
                           0000A8   177 _IE	=	0x00a8
                           0000B0   178 G$P3$0_0$0 == 0x00b0
                           0000B0   179 _P3	=	0x00b0
                           0000B8   180 G$IP$0_0$0 == 0x00b8
                           0000B8   181 _IP	=	0x00b8
                           0000D0   182 G$PSW$0_0$0 == 0x00d0
                           0000D0   183 _PSW	=	0x00d0
                           0000E0   184 G$ACC$0_0$0 == 0x00e0
                           0000E0   185 _ACC	=	0x00e0
                           0000F0   186 G$B$0_0$0 == 0x00f0
                           0000F0   187 _B	=	0x00f0
                           0000C8   188 G$T2CON$0_0$0 == 0x00c8
                           0000C8   189 _T2CON	=	0x00c8
                           0000CA   190 G$RCAP2L$0_0$0 == 0x00ca
                           0000CA   191 _RCAP2L	=	0x00ca
                           0000CB   192 G$RCAP2H$0_0$0 == 0x00cb
                           0000CB   193 _RCAP2H	=	0x00cb
                           0000CC   194 G$TL2$0_0$0 == 0x00cc
                           0000CC   195 _TL2	=	0x00cc
                           0000CD   196 G$TH2$0_0$0 == 0x00cd
                           0000CD   197 _TH2	=	0x00cd
                                    198 ;--------------------------------------------------------
                                    199 ; special function bits
                                    200 ;--------------------------------------------------------
                                    201 	.area RSEG    (ABS,DATA)
      000000                        202 	.org 0x0000
                           000080   203 G$P0_0$0_0$0 == 0x0080
                           000080   204 _P0_0	=	0x0080
                           000081   205 G$P0_1$0_0$0 == 0x0081
                           000081   206 _P0_1	=	0x0081
                           000082   207 G$P0_2$0_0$0 == 0x0082
                           000082   208 _P0_2	=	0x0082
                           000083   209 G$P0_3$0_0$0 == 0x0083
                           000083   210 _P0_3	=	0x0083
                           000084   211 G$P0_4$0_0$0 == 0x0084
                           000084   212 _P0_4	=	0x0084
                           000085   213 G$P0_5$0_0$0 == 0x0085
                           000085   214 _P0_5	=	0x0085
                           000086   215 G$P0_6$0_0$0 == 0x0086
                           000086   216 _P0_6	=	0x0086
                           000087   217 G$P0_7$0_0$0 == 0x0087
                           000087   218 _P0_7	=	0x0087
                           000088   219 G$IT0$0_0$0 == 0x0088
                           000088   220 _IT0	=	0x0088
                           000089   221 G$IE0$0_0$0 == 0x0089
                           000089   222 _IE0	=	0x0089
                           00008A   223 G$IT1$0_0$0 == 0x008a
                           00008A   224 _IT1	=	0x008a
                           00008B   225 G$IE1$0_0$0 == 0x008b
                           00008B   226 _IE1	=	0x008b
                           00008C   227 G$TR0$0_0$0 == 0x008c
                           00008C   228 _TR0	=	0x008c
                           00008D   229 G$TF0$0_0$0 == 0x008d
                           00008D   230 _TF0	=	0x008d
                           00008E   231 G$TR1$0_0$0 == 0x008e
                           00008E   232 _TR1	=	0x008e
                           00008F   233 G$TF1$0_0$0 == 0x008f
                           00008F   234 _TF1	=	0x008f
                           000090   235 G$P1_0$0_0$0 == 0x0090
                           000090   236 _P1_0	=	0x0090
                           000091   237 G$P1_1$0_0$0 == 0x0091
                           000091   238 _P1_1	=	0x0091
                           000092   239 G$P1_2$0_0$0 == 0x0092
                           000092   240 _P1_2	=	0x0092
                           000093   241 G$P1_3$0_0$0 == 0x0093
                           000093   242 _P1_3	=	0x0093
                           000094   243 G$P1_4$0_0$0 == 0x0094
                           000094   244 _P1_4	=	0x0094
                           000095   245 G$P1_5$0_0$0 == 0x0095
                           000095   246 _P1_5	=	0x0095
                           000096   247 G$P1_6$0_0$0 == 0x0096
                           000096   248 _P1_6	=	0x0096
                           000097   249 G$P1_7$0_0$0 == 0x0097
                           000097   250 _P1_7	=	0x0097
                           000098   251 G$RI$0_0$0 == 0x0098
                           000098   252 _RI	=	0x0098
                           000099   253 G$TI$0_0$0 == 0x0099
                           000099   254 _TI	=	0x0099
                           00009A   255 G$RB8$0_0$0 == 0x009a
                           00009A   256 _RB8	=	0x009a
                           00009B   257 G$TB8$0_0$0 == 0x009b
                           00009B   258 _TB8	=	0x009b
                           00009C   259 G$REN$0_0$0 == 0x009c
                           00009C   260 _REN	=	0x009c
                           00009D   261 G$SM2$0_0$0 == 0x009d
                           00009D   262 _SM2	=	0x009d
                           00009E   263 G$SM1$0_0$0 == 0x009e
                           00009E   264 _SM1	=	0x009e
                           00009F   265 G$SM0$0_0$0 == 0x009f
                           00009F   266 _SM0	=	0x009f
                           0000A0   267 G$P2_0$0_0$0 == 0x00a0
                           0000A0   268 _P2_0	=	0x00a0
                           0000A1   269 G$P2_1$0_0$0 == 0x00a1
                           0000A1   270 _P2_1	=	0x00a1
                           0000A2   271 G$P2_2$0_0$0 == 0x00a2
                           0000A2   272 _P2_2	=	0x00a2
                           0000A3   273 G$P2_3$0_0$0 == 0x00a3
                           0000A3   274 _P2_3	=	0x00a3
                           0000A4   275 G$P2_4$0_0$0 == 0x00a4
                           0000A4   276 _P2_4	=	0x00a4
                           0000A5   277 G$P2_5$0_0$0 == 0x00a5
                           0000A5   278 _P2_5	=	0x00a5
                           0000A6   279 G$P2_6$0_0$0 == 0x00a6
                           0000A6   280 _P2_6	=	0x00a6
                           0000A7   281 G$P2_7$0_0$0 == 0x00a7
                           0000A7   282 _P2_7	=	0x00a7
                           0000A8   283 G$EX0$0_0$0 == 0x00a8
                           0000A8   284 _EX0	=	0x00a8
                           0000A9   285 G$ET0$0_0$0 == 0x00a9
                           0000A9   286 _ET0	=	0x00a9
                           0000AA   287 G$EX1$0_0$0 == 0x00aa
                           0000AA   288 _EX1	=	0x00aa
                           0000AB   289 G$ET1$0_0$0 == 0x00ab
                           0000AB   290 _ET1	=	0x00ab
                           0000AC   291 G$ES$0_0$0 == 0x00ac
                           0000AC   292 _ES	=	0x00ac
                           0000AF   293 G$EA$0_0$0 == 0x00af
                           0000AF   294 _EA	=	0x00af
                           0000B0   295 G$P3_0$0_0$0 == 0x00b0
                           0000B0   296 _P3_0	=	0x00b0
                           0000B1   297 G$P3_1$0_0$0 == 0x00b1
                           0000B1   298 _P3_1	=	0x00b1
                           0000B2   299 G$P3_2$0_0$0 == 0x00b2
                           0000B2   300 _P3_2	=	0x00b2
                           0000B3   301 G$P3_3$0_0$0 == 0x00b3
                           0000B3   302 _P3_3	=	0x00b3
                           0000B4   303 G$P3_4$0_0$0 == 0x00b4
                           0000B4   304 _P3_4	=	0x00b4
                           0000B5   305 G$P3_5$0_0$0 == 0x00b5
                           0000B5   306 _P3_5	=	0x00b5
                           0000B6   307 G$P3_6$0_0$0 == 0x00b6
                           0000B6   308 _P3_6	=	0x00b6
                           0000B7   309 G$P3_7$0_0$0 == 0x00b7
                           0000B7   310 _P3_7	=	0x00b7
                           0000B0   311 G$RXD$0_0$0 == 0x00b0
                           0000B0   312 _RXD	=	0x00b0
                           0000B1   313 G$TXD$0_0$0 == 0x00b1
                           0000B1   314 _TXD	=	0x00b1
                           0000B2   315 G$INT0$0_0$0 == 0x00b2
                           0000B2   316 _INT0	=	0x00b2
                           0000B3   317 G$INT1$0_0$0 == 0x00b3
                           0000B3   318 _INT1	=	0x00b3
                           0000B4   319 G$T0$0_0$0 == 0x00b4
                           0000B4   320 _T0	=	0x00b4
                           0000B5   321 G$T1$0_0$0 == 0x00b5
                           0000B5   322 _T1	=	0x00b5
                           0000B6   323 G$WR$0_0$0 == 0x00b6
                           0000B6   324 _WR	=	0x00b6
                           0000B7   325 G$RD$0_0$0 == 0x00b7
                           0000B7   326 _RD	=	0x00b7
                           0000B8   327 G$PX0$0_0$0 == 0x00b8
                           0000B8   328 _PX0	=	0x00b8
                           0000B9   329 G$PT0$0_0$0 == 0x00b9
                           0000B9   330 _PT0	=	0x00b9
                           0000BA   331 G$PX1$0_0$0 == 0x00ba
                           0000BA   332 _PX1	=	0x00ba
                           0000BB   333 G$PT1$0_0$0 == 0x00bb
                           0000BB   334 _PT1	=	0x00bb
                           0000BC   335 G$PS$0_0$0 == 0x00bc
                           0000BC   336 _PS	=	0x00bc
                           0000D0   337 G$P$0_0$0 == 0x00d0
                           0000D0   338 _P	=	0x00d0
                           0000D1   339 G$F1$0_0$0 == 0x00d1
                           0000D1   340 _F1	=	0x00d1
                           0000D2   341 G$OV$0_0$0 == 0x00d2
                           0000D2   342 _OV	=	0x00d2
                           0000D3   343 G$RS0$0_0$0 == 0x00d3
                           0000D3   344 _RS0	=	0x00d3
                           0000D4   345 G$RS1$0_0$0 == 0x00d4
                           0000D4   346 _RS1	=	0x00d4
                           0000D5   347 G$F0$0_0$0 == 0x00d5
                           0000D5   348 _F0	=	0x00d5
                           0000D6   349 G$AC$0_0$0 == 0x00d6
                           0000D6   350 _AC	=	0x00d6
                           0000D7   351 G$CY$0_0$0 == 0x00d7
                           0000D7   352 _CY	=	0x00d7
                           0000AD   353 G$ET2$0_0$0 == 0x00ad
                           0000AD   354 _ET2	=	0x00ad
                           0000BD   355 G$PT2$0_0$0 == 0x00bd
                           0000BD   356 _PT2	=	0x00bd
                           0000C8   357 G$T2CON_0$0_0$0 == 0x00c8
                           0000C8   358 _T2CON_0	=	0x00c8
                           0000C9   359 G$T2CON_1$0_0$0 == 0x00c9
                           0000C9   360 _T2CON_1	=	0x00c9
                           0000CA   361 G$T2CON_2$0_0$0 == 0x00ca
                           0000CA   362 _T2CON_2	=	0x00ca
                           0000CB   363 G$T2CON_3$0_0$0 == 0x00cb
                           0000CB   364 _T2CON_3	=	0x00cb
                           0000CC   365 G$T2CON_4$0_0$0 == 0x00cc
                           0000CC   366 _T2CON_4	=	0x00cc
                           0000CD   367 G$T2CON_5$0_0$0 == 0x00cd
                           0000CD   368 _T2CON_5	=	0x00cd
                           0000CE   369 G$T2CON_6$0_0$0 == 0x00ce
                           0000CE   370 _T2CON_6	=	0x00ce
                           0000CF   371 G$T2CON_7$0_0$0 == 0x00cf
                           0000CF   372 _T2CON_7	=	0x00cf
                           0000C8   373 G$CP_RL2$0_0$0 == 0x00c8
                           0000C8   374 _CP_RL2	=	0x00c8
                           0000C9   375 G$C_T2$0_0$0 == 0x00c9
                           0000C9   376 _C_T2	=	0x00c9
                           0000CA   377 G$TR2$0_0$0 == 0x00ca
                           0000CA   378 _TR2	=	0x00ca
                           0000CB   379 G$EXEN2$0_0$0 == 0x00cb
                           0000CB   380 _EXEN2	=	0x00cb
                           0000CC   381 G$TCLK$0_0$0 == 0x00cc
                           0000CC   382 _TCLK	=	0x00cc
                           0000CD   383 G$RCLK$0_0$0 == 0x00cd
                           0000CD   384 _RCLK	=	0x00cd
                           0000CE   385 G$EXF2$0_0$0 == 0x00ce
                           0000CE   386 _EXF2	=	0x00ce
                           0000CF   387 G$TF2$0_0$0 == 0x00cf
                           0000CF   388 _TF2	=	0x00cf
                                    389 ;--------------------------------------------------------
                                    390 ; overlayable register banks
                                    391 ;--------------------------------------------------------
                                    392 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        393 	.ds 8
                                    394 ;--------------------------------------------------------
                                    395 ; overlayable bit register bank
                                    396 ;--------------------------------------------------------
                                    397 	.area BIT_BANK	(REL,OVR,DATA)
      000020                        398 bits:
      000020                        399 	.ds 1
                           008000   400 	b0 = bits[0]
                           008100   401 	b1 = bits[1]
                           008200   402 	b2 = bits[2]
                           008300   403 	b3 = bits[3]
                           008400   404 	b4 = bits[4]
                           008500   405 	b5 = bits[5]
                           008600   406 	b6 = bits[6]
                           008700   407 	b7 = bits[7]
                                    408 ;--------------------------------------------------------
                                    409 ; internal ram data
                                    410 ;--------------------------------------------------------
                                    411 	.area DSEG    (DATA)
                           000000   412 Fcontroller_8051$rules$0_0$0==.
      000008                        413 _rules:
      000008                        414 	.ds 15
                           00000F   415 G$test_temperature$0_0$0==.
      000017                        416 _test_temperature::
      000017                        417 	.ds 1
                           000010   418 G$test_pwm$0_0$0==.
      000018                        419 _test_pwm::
      000018                        420 	.ds 1
                           000011   421 G$test_fan_speed$0_0$0==.
      000019                        422 _test_fan_speed::
      000019                        423 	.ds 4
                                    424 ;--------------------------------------------------------
                                    425 ; overlayable items in internal ram
                                    426 ;--------------------------------------------------------
                                    427 ;--------------------------------------------------------
                                    428 ; Stack segment in internal ram
                                    429 ;--------------------------------------------------------
                                    430 	.area SSEG
      000021                        431 __start__stack:
      000021                        432 	.ds	1
                                    433 
                                    434 ;--------------------------------------------------------
                                    435 ; indirectly addressable internal ram data
                                    436 ;--------------------------------------------------------
                                    437 	.area ISEG    (DATA)
                                    438 ;--------------------------------------------------------
                                    439 ; absolute internal ram data
                                    440 ;--------------------------------------------------------
                                    441 	.area IABS    (ABS,DATA)
                                    442 	.area IABS    (ABS,DATA)
                                    443 ;--------------------------------------------------------
                                    444 ; bit data
                                    445 ;--------------------------------------------------------
                                    446 	.area BSEG    (BIT)
                                    447 ;--------------------------------------------------------
                                    448 ; paged external ram data
                                    449 ;--------------------------------------------------------
                                    450 	.area PSEG    (PAG,XDATA)
                                    451 ;--------------------------------------------------------
                                    452 ; uninitialized external ram data
                                    453 ;--------------------------------------------------------
                                    454 	.area XSEG    (XDATA)
                                    455 ;--------------------------------------------------------
                                    456 ; absolute external ram data
                                    457 ;--------------------------------------------------------
                                    458 	.area XABS    (ABS,XDATA)
                                    459 ;--------------------------------------------------------
                                    460 ; initialized external ram data
                                    461 ;--------------------------------------------------------
                                    462 	.area XISEG   (XDATA)
                                    463 	.area HOME    (CODE)
                                    464 	.area GSINIT0 (CODE)
                                    465 	.area GSINIT1 (CODE)
                                    466 	.area GSINIT2 (CODE)
                                    467 	.area GSINIT3 (CODE)
                                    468 	.area GSINIT4 (CODE)
                                    469 	.area GSINIT5 (CODE)
                                    470 	.area GSINIT  (CODE)
                                    471 	.area GSFINAL (CODE)
                                    472 	.area CSEG    (CODE)
                                    473 ;--------------------------------------------------------
                                    474 ; interrupt vector
                                    475 ;--------------------------------------------------------
                                    476 	.area HOME    (CODE)
      000000                        477 __interrupt_vect:
      000000 02 00 4C         [24]  478 	ljmp	__sdcc_gsinit_startup
                                    479 ; restartable atomic support routines
      000003                        480 	.ds	5
      000008                        481 sdcc_atomic_exchange_rollback_start::
      000008 00               [12]  482 	nop
      000009 00               [12]  483 	nop
      00000A                        484 sdcc_atomic_exchange_pdata_impl:
      00000A E2               [24]  485 	movx	a, @r0
      00000B FB               [12]  486 	mov	r3, a
      00000C EA               [12]  487 	mov	a, r2
      00000D F2               [24]  488 	movx	@r0, a
      00000E 80 2C            [24]  489 	sjmp	sdcc_atomic_exchange_exit
      000010 00               [12]  490 	nop
      000011 00               [12]  491 	nop
      000012                        492 sdcc_atomic_exchange_xdata_impl:
      000012 E0               [24]  493 	movx	a, @dptr
      000013 FB               [12]  494 	mov	r3, a
      000014 EA               [12]  495 	mov	a, r2
      000015 F0               [24]  496 	movx	@dptr, a
      000016 80 24            [24]  497 	sjmp	sdcc_atomic_exchange_exit
      000018                        498 sdcc_atomic_compare_exchange_idata_impl:
      000018 E6               [12]  499 	mov	a, @r0
      000019 B5 02 02         [24]  500 	cjne	a, ar2, .+#5
      00001C EB               [12]  501 	mov	a, r3
      00001D F6               [12]  502 	mov	@r0, a
      00001E 22               [24]  503 	ret
      00001F 00               [12]  504 	nop
      000020                        505 sdcc_atomic_compare_exchange_pdata_impl:
      000020 E2               [24]  506 	movx	a, @r0
      000021 B5 02 02         [24]  507 	cjne	a, ar2, .+#5
      000024 EB               [12]  508 	mov	a, r3
      000025 F2               [24]  509 	movx	@r0, a
      000026 22               [24]  510 	ret
      000027 00               [12]  511 	nop
      000028                        512 sdcc_atomic_compare_exchange_xdata_impl:
      000028 E0               [24]  513 	movx	a, @dptr
      000029 B5 02 02         [24]  514 	cjne	a, ar2, .+#5
      00002C EB               [12]  515 	mov	a, r3
      00002D F0               [24]  516 	movx	@dptr, a
      00002E 22               [24]  517 	ret
      00002F                        518 sdcc_atomic_exchange_rollback_end::
                                    519 
      00002F                        520 sdcc_atomic_exchange_gptr_impl::
      00002F 30 F6 E0         [24]  521 	jnb	b.6, sdcc_atomic_exchange_xdata_impl
      000032 A8 82            [24]  522 	mov	r0, dpl
      000034 20 F5 D3         [24]  523 	jb	b.5, sdcc_atomic_exchange_pdata_impl
      000037                        524 sdcc_atomic_exchange_idata_impl:
      000037 EA               [12]  525 	mov	a, r2
      000038 C6               [12]  526 	xch	a, @r0
      000039 F5 82            [12]  527 	mov	dpl, a
      00003B 22               [24]  528 	ret
      00003C                        529 sdcc_atomic_exchange_exit:
      00003C 8B 82            [24]  530 	mov	dpl, r3
      00003E 22               [24]  531 	ret
      00003F                        532 sdcc_atomic_compare_exchange_gptr_impl::
      00003F 30 F6 E6         [24]  533 	jnb	b.6, sdcc_atomic_compare_exchange_xdata_impl
      000042 A8 82            [24]  534 	mov	r0, dpl
      000044 20 F5 D9         [24]  535 	jb	b.5, sdcc_atomic_compare_exchange_pdata_impl
      000047 80 CF            [24]  536 	sjmp	sdcc_atomic_compare_exchange_idata_impl
                                    537 ;--------------------------------------------------------
                                    538 ; global & static initialisations
                                    539 ;--------------------------------------------------------
                                    540 	.area HOME    (CODE)
                                    541 	.area GSINIT  (CODE)
                                    542 	.area GSFINAL (CODE)
                                    543 	.area GSINIT  (CODE)
                                    544 	.globl __sdcc_gsinit_startup
                                    545 	.globl __sdcc_program_startup
                                    546 	.globl __start__stack
                                    547 	.globl __mcs51_genXINIT
                                    548 	.globl __mcs51_genXRAMCLEAR
                                    549 	.globl __mcs51_genRAMCLEAR
                           000000   550 	C$controller_8051.c$20$2_0$65 ==.
                                    551 ;	../../controller_8051.c:20: volatile unsigned char test_temperature = 0u;
      0000A5 75 17 00         [24]  552 	mov	_test_temperature,#0x00
                           000003   553 	C$controller_8051.c$21$2_0$65 ==.
                                    554 ;	../../controller_8051.c:21: volatile unsigned char test_pwm = 0u;
      0000A8 75 18 00         [24]  555 	mov	_test_pwm,#0x00
                           000006   556 	C$controller_8051.c$22$2_0$65 ==.
                                    557 ;	../../controller_8051.c:22: volatile float test_fan_speed = 0.0f;
      0000AB E4               [12]  558 	clr	a
      0000AC F5 19            [12]  559 	mov	_test_fan_speed,a
      0000AE F5 1A            [12]  560 	mov	(_test_fan_speed + 1),a
      0000B0 F5 1B            [12]  561 	mov	(_test_fan_speed + 2),a
      0000B2 F5 1C            [12]  562 	mov	(_test_fan_speed + 3),a
                                    563 	.area GSFINAL (CODE)
      0000B4 02 00 49         [24]  564 	ljmp	__sdcc_program_startup
                                    565 ;--------------------------------------------------------
                                    566 ; Home
                                    567 ;--------------------------------------------------------
                                    568 	.area HOME    (CODE)
                                    569 	.area HOME    (CODE)
      000049                        570 __sdcc_program_startup:
      000049 02 1C 88         [24]  571 	ljmp	_main
                                    572 ;	return from main will return to caller
                                    573 ;--------------------------------------------------------
                                    574 ; code
                                    575 ;--------------------------------------------------------
                                    576 	.area CSEG    (CODE)
                                    577 ;------------------------------------------------------------
                                    578 ;Allocation info for local variables in function 'fuzzy_8051_and2'
                                    579 ;------------------------------------------------------------
                                    580 ;a             Allocated to stack - _bp -6 +4 
                                    581 ;b             Allocated to stack - _bp -10 +4 
                                    582 ;method        Allocated to registers r7 
                                    583 ;value         Allocated to registers r4 r5 r6 r7 
                                    584 ;------------------------------------------------------------
                           000000   585 	Fcontroller_8051$fuzzy_8051_and2$0$0 ==.
                           000000   586 	C$fuzzy.h$55$0_0$11 ==.
                                    587 ;	../../fuzzy.h:55: static float fuzzy_8051_and2(fuzzy_logic_method_t method, float a, float b) { if (method == FUZZY_LOGIC_ALGEBRAIC) return a * b; if (method == FUZZY_LOGIC_BOUNDED) { float value = a + b - 1.0f; return value > 0.0f ? value : 0.0f; } return a < b ? a : b; }
                                    588 ;	-----------------------------------------
                                    589 ;	 function fuzzy_8051_and2
                                    590 ;	-----------------------------------------
      0000B7                        591 _fuzzy_8051_and2:
                           000007   592 	ar7 = 0x07
                           000006   593 	ar6 = 0x06
                           000005   594 	ar5 = 0x05
                           000004   595 	ar4 = 0x04
                           000003   596 	ar3 = 0x03
                           000002   597 	ar2 = 0x02
                           000001   598 	ar1 = 0x01
                           000000   599 	ar0 = 0x00
      0000B7 C0 1D            [24]  600 	push	_bp
      0000B9 85 81 1D         [24]  601 	mov	_bp,sp
      0000BC AF 82            [24]  602 	mov	r7, dpl
      0000BE BF 01 3D         [24]  603 	cjne	r7,#0x01,00102$
      0000C1 E5 1D            [12]  604 	mov	a,_bp
      0000C3 24 F6            [12]  605 	add	a,#0xf6
      0000C5 F8               [12]  606 	mov	r0,a
      0000C6 E6               [12]  607 	mov	a,@r0
      0000C7 C0 E0            [24]  608 	push	acc
      0000C9 08               [12]  609 	inc	r0
      0000CA E6               [12]  610 	mov	a,@r0
      0000CB C0 E0            [24]  611 	push	acc
      0000CD 08               [12]  612 	inc	r0
      0000CE E6               [12]  613 	mov	a,@r0
      0000CF C0 E0            [24]  614 	push	acc
      0000D1 08               [12]  615 	inc	r0
      0000D2 E6               [12]  616 	mov	a,@r0
      0000D3 C0 E0            [24]  617 	push	acc
      0000D5 E5 1D            [12]  618 	mov	a,_bp
      0000D7 24 FA            [12]  619 	add	a,#0xfa
      0000D9 F8               [12]  620 	mov	r0,a
      0000DA 86 82            [24]  621 	mov	dpl, @r0
      0000DC 08               [12]  622 	inc	r0
      0000DD 86 83            [24]  623 	mov	dph, @r0
      0000DF 08               [12]  624 	inc	r0
      0000E0 86 F0            [24]  625 	mov	b, @r0
      0000E2 08               [12]  626 	inc	r0
      0000E3 E6               [12]  627 	mov	a, @r0
      0000E4 12 1C C2         [24]  628 	lcall	___fsmul
      0000E7 AB 82            [24]  629 	mov	r3, dpl
      0000E9 AC 83            [24]  630 	mov	r4, dph
      0000EB AD F0            [24]  631 	mov	r5, b
      0000ED FE               [12]  632 	mov	r6, a
      0000EE E5 81            [12]  633 	mov	a,sp
      0000F0 24 FC            [12]  634 	add	a,#0xfc
      0000F2 F5 81            [12]  635 	mov	sp,a
      0000F4 8B 82            [24]  636 	mov	dpl, r3
      0000F6 8C 83            [24]  637 	mov	dph, r4
      0000F8 8D F0            [24]  638 	mov	b, r5
      0000FA EE               [12]  639 	mov	a, r6
      0000FB 02 01 F0         [24]  640 	ljmp	00105$
      0000FE                        641 00102$:
      0000FE BF 02 02         [24]  642 	cjne	r7,#0x02,00137$
      000101 80 03            [24]  643 	sjmp	00138$
      000103                        644 00137$:
      000103 02 01 96         [24]  645 	ljmp	00104$
      000106                        646 00138$:
      000106 E5 1D            [12]  647 	mov	a,_bp
      000108 24 F6            [12]  648 	add	a,#0xf6
      00010A F8               [12]  649 	mov	r0,a
      00010B E6               [12]  650 	mov	a,@r0
      00010C C0 E0            [24]  651 	push	acc
      00010E 08               [12]  652 	inc	r0
      00010F E6               [12]  653 	mov	a,@r0
      000110 C0 E0            [24]  654 	push	acc
      000112 08               [12]  655 	inc	r0
      000113 E6               [12]  656 	mov	a,@r0
      000114 C0 E0            [24]  657 	push	acc
      000116 08               [12]  658 	inc	r0
      000117 E6               [12]  659 	mov	a,@r0
      000118 C0 E0            [24]  660 	push	acc
      00011A E5 1D            [12]  661 	mov	a,_bp
      00011C 24 FA            [12]  662 	add	a,#0xfa
      00011E F8               [12]  663 	mov	r0,a
      00011F 86 82            [24]  664 	mov	dpl, @r0
      000121 08               [12]  665 	inc	r0
      000122 86 83            [24]  666 	mov	dph, @r0
      000124 08               [12]  667 	inc	r0
      000125 86 F0            [24]  668 	mov	b, @r0
      000127 08               [12]  669 	inc	r0
      000128 E6               [12]  670 	mov	a, @r0
      000129 12 1E 22         [24]  671 	lcall	___fsadd
      00012C AC 82            [24]  672 	mov	r4, dpl
      00012E AD 83            [24]  673 	mov	r5, dph
      000130 AE F0            [24]  674 	mov	r6, b
      000132 FF               [12]  675 	mov	r7, a
      000133 E5 81            [12]  676 	mov	a,sp
      000135 24 FC            [12]  677 	add	a,#0xfc
      000137 F5 81            [12]  678 	mov	sp,a
      000139 E4               [12]  679 	clr	a
      00013A C0 E0            [24]  680 	push	acc
      00013C C0 E0            [24]  681 	push	acc
      00013E 74 80            [12]  682 	mov	a,#0x80
      000140 C0 E0            [24]  683 	push	acc
      000142 74 3F            [12]  684 	mov	a,#0x3f
      000144 C0 E0            [24]  685 	push	acc
      000146 8C 82            [24]  686 	mov	dpl, r4
      000148 8D 83            [24]  687 	mov	dph, r5
      00014A 8E F0            [24]  688 	mov	b, r6
      00014C EF               [12]  689 	mov	a, r7
      00014D 12 1C B7         [24]  690 	lcall	___fssub
      000150 AC 82            [24]  691 	mov	r4, dpl
      000152 AD 83            [24]  692 	mov	r5, dph
      000154 AE F0            [24]  693 	mov	r6, b
      000156 FF               [12]  694 	mov	r7, a
      000157 E5 81            [12]  695 	mov	a,sp
      000159 24 FC            [12]  696 	add	a,#0xfc
      00015B F5 81            [12]  697 	mov	sp,a
      00015D C0 07            [24]  698 	push	ar7
      00015F C0 06            [24]  699 	push	ar6
      000161 C0 05            [24]  700 	push	ar5
      000163 C0 04            [24]  701 	push	ar4
      000165 C0 04            [24]  702 	push	ar4
      000167 C0 05            [24]  703 	push	ar5
      000169 C0 06            [24]  704 	push	ar6
      00016B C0 07            [24]  705 	push	ar7
      00016D 90 00 00         [24]  706 	mov	dptr,#0x0000
      000170 E4               [12]  707 	clr	a
      000171 F5 F0            [12]  708 	mov	b,a
      000173 12 1D F2         [24]  709 	lcall	___fslt
      000176 AB 82            [24]  710 	mov	r3, dpl
      000178 E5 81            [12]  711 	mov	a,sp
      00017A 24 FC            [12]  712 	add	a,#0xfc
      00017C F5 81            [12]  713 	mov	sp,a
      00017E D0 04            [24]  714 	pop	ar4
      000180 D0 05            [24]  715 	pop	ar5
      000182 D0 06            [24]  716 	pop	ar6
      000184 D0 07            [24]  717 	pop	ar7
      000186 EB               [12]  718 	mov	a,r3
      000187 70 04            [24]  719 	jnz	00108$
      000189 FC               [12]  720 	mov	r4,a
      00018A FD               [12]  721 	mov	r5,a
      00018B FE               [12]  722 	mov	r6,a
      00018C FF               [12]  723 	mov	r7,a
      00018D                        724 00108$:
      00018D 8C 82            [24]  725 	mov	dpl, r4
      00018F 8D 83            [24]  726 	mov	dph, r5
      000191 8E F0            [24]  727 	mov	b, r6
      000193 EF               [12]  728 	mov	a, r7
      000194 80 5A            [24]  729 	sjmp	00105$
      000196                        730 00104$:
      000196 E5 1D            [12]  731 	mov	a,_bp
      000198 24 F6            [12]  732 	add	a,#0xf6
      00019A F8               [12]  733 	mov	r0,a
      00019B E6               [12]  734 	mov	a,@r0
      00019C C0 E0            [24]  735 	push	acc
      00019E 08               [12]  736 	inc	r0
      00019F E6               [12]  737 	mov	a,@r0
      0001A0 C0 E0            [24]  738 	push	acc
      0001A2 08               [12]  739 	inc	r0
      0001A3 E6               [12]  740 	mov	a,@r0
      0001A4 C0 E0            [24]  741 	push	acc
      0001A6 08               [12]  742 	inc	r0
      0001A7 E6               [12]  743 	mov	a,@r0
      0001A8 C0 E0            [24]  744 	push	acc
      0001AA E5 1D            [12]  745 	mov	a,_bp
      0001AC 24 FA            [12]  746 	add	a,#0xfa
      0001AE F8               [12]  747 	mov	r0,a
      0001AF 86 82            [24]  748 	mov	dpl, @r0
      0001B1 08               [12]  749 	inc	r0
      0001B2 86 83            [24]  750 	mov	dph, @r0
      0001B4 08               [12]  751 	inc	r0
      0001B5 86 F0            [24]  752 	mov	b, @r0
      0001B7 08               [12]  753 	inc	r0
      0001B8 E6               [12]  754 	mov	a, @r0
      0001B9 12 1D F2         [24]  755 	lcall	___fslt
      0001BC AF 82            [24]  756 	mov	r7, dpl
      0001BE E5 81            [12]  757 	mov	a,sp
      0001C0 24 FC            [12]  758 	add	a,#0xfc
      0001C2 F5 81            [12]  759 	mov	sp,a
      0001C4 EF               [12]  760 	mov	a,r7
      0001C5 60 12            [24]  761 	jz	00109$
      0001C7 E5 1D            [12]  762 	mov	a,_bp
      0001C9 24 FA            [12]  763 	add	a,#0xfa
      0001CB F8               [12]  764 	mov	r0,a
      0001CC 86 04            [24]  765 	mov	ar4,@r0
      0001CE 08               [12]  766 	inc	r0
      0001CF 86 05            [24]  767 	mov	ar5,@r0
      0001D1 08               [12]  768 	inc	r0
      0001D2 86 06            [24]  769 	mov	ar6,@r0
      0001D4 08               [12]  770 	inc	r0
      0001D5 86 07            [24]  771 	mov	ar7,@r0
      0001D7 80 10            [24]  772 	sjmp	00110$
      0001D9                        773 00109$:
      0001D9 E5 1D            [12]  774 	mov	a,_bp
      0001DB 24 F6            [12]  775 	add	a,#0xf6
      0001DD F8               [12]  776 	mov	r0,a
      0001DE 86 04            [24]  777 	mov	ar4,@r0
      0001E0 08               [12]  778 	inc	r0
      0001E1 86 05            [24]  779 	mov	ar5,@r0
      0001E3 08               [12]  780 	inc	r0
      0001E4 86 06            [24]  781 	mov	ar6,@r0
      0001E6 08               [12]  782 	inc	r0
      0001E7 86 07            [24]  783 	mov	ar7,@r0
      0001E9                        784 00110$:
      0001E9 8C 82            [24]  785 	mov	dpl, r4
      0001EB 8D 83            [24]  786 	mov	dph, r5
      0001ED 8E F0            [24]  787 	mov	b, r6
      0001EF EF               [12]  788 	mov	a, r7
      0001F0                        789 00105$:
      0001F0 D0 1D            [24]  790 	pop	_bp
                           00013B   791 	C$fuzzy.h$55$1_0$11 ==.
                           00013B   792 	XFcontroller_8051$fuzzy_8051_and2$0$0 ==.
      0001F2 22               [24]  793 	ret
                                    794 ;------------------------------------------------------------
                                    795 ;Allocation info for local variables in function 'fuzzy_8051_and3'
                                    796 ;------------------------------------------------------------
                                    797 ;a             Allocated to stack - _bp -6 +4 
                                    798 ;b             Allocated to stack - _bp -10 +4 
                                    799 ;c             Allocated to stack - _bp -14 +4 
                                    800 ;method        Allocated to registers r7 
                                    801 ;------------------------------------------------------------
                           00013C   802 	Fcontroller_8051$fuzzy_8051_and3$0$0 ==.
                           00013C   803 	C$fuzzy.h$56$1_0$14 ==.
                                    804 ;	../../fuzzy.h:56: static float fuzzy_8051_and3(fuzzy_logic_method_t method, float a, float b, float c) { return fuzzy_8051_and2(method, fuzzy_8051_and2(method, a, b), c); }
                                    805 ;	-----------------------------------------
                                    806 ;	 function fuzzy_8051_and3
                                    807 ;	-----------------------------------------
      0001F3                        808 _fuzzy_8051_and3:
      0001F3 C0 1D            [24]  809 	push	_bp
      0001F5 85 81 1D         [24]  810 	mov	_bp,sp
      0001F8 AF 82            [24]  811 	mov	r7, dpl
      0001FA C0 07            [24]  812 	push	ar7
      0001FC E5 1D            [12]  813 	mov	a,_bp
      0001FE 24 F6            [12]  814 	add	a,#0xf6
      000200 F8               [12]  815 	mov	r0,a
      000201 E6               [12]  816 	mov	a,@r0
      000202 C0 E0            [24]  817 	push	acc
      000204 08               [12]  818 	inc	r0
      000205 E6               [12]  819 	mov	a,@r0
      000206 C0 E0            [24]  820 	push	acc
      000208 08               [12]  821 	inc	r0
      000209 E6               [12]  822 	mov	a,@r0
      00020A C0 E0            [24]  823 	push	acc
      00020C 08               [12]  824 	inc	r0
      00020D E6               [12]  825 	mov	a,@r0
      00020E C0 E0            [24]  826 	push	acc
      000210 E5 1D            [12]  827 	mov	a,_bp
      000212 24 FA            [12]  828 	add	a,#0xfa
      000214 F8               [12]  829 	mov	r0,a
      000215 E6               [12]  830 	mov	a,@r0
      000216 C0 E0            [24]  831 	push	acc
      000218 08               [12]  832 	inc	r0
      000219 E6               [12]  833 	mov	a,@r0
      00021A C0 E0            [24]  834 	push	acc
      00021C 08               [12]  835 	inc	r0
      00021D E6               [12]  836 	mov	a,@r0
      00021E C0 E0            [24]  837 	push	acc
      000220 08               [12]  838 	inc	r0
      000221 E6               [12]  839 	mov	a,@r0
      000222 C0 E0            [24]  840 	push	acc
      000224 8F 82            [24]  841 	mov	dpl, r7
      000226 12 00 B7         [24]  842 	lcall	_fuzzy_8051_and2
      000229 AB 82            [24]  843 	mov	r3, dpl
      00022B AC 83            [24]  844 	mov	r4, dph
      00022D AD F0            [24]  845 	mov	r5, b
      00022F FE               [12]  846 	mov	r6, a
      000230 E5 81            [12]  847 	mov	a,sp
      000232 24 F8            [12]  848 	add	a,#0xf8
      000234 F5 81            [12]  849 	mov	sp,a
      000236 D0 07            [24]  850 	pop	ar7
      000238 E5 1D            [12]  851 	mov	a,_bp
      00023A 24 F2            [12]  852 	add	a,#0xf2
      00023C F8               [12]  853 	mov	r0,a
      00023D E6               [12]  854 	mov	a,@r0
      00023E C0 E0            [24]  855 	push	acc
      000240 08               [12]  856 	inc	r0
      000241 E6               [12]  857 	mov	a,@r0
      000242 C0 E0            [24]  858 	push	acc
      000244 08               [12]  859 	inc	r0
      000245 E6               [12]  860 	mov	a,@r0
      000246 C0 E0            [24]  861 	push	acc
      000248 08               [12]  862 	inc	r0
      000249 E6               [12]  863 	mov	a,@r0
      00024A C0 E0            [24]  864 	push	acc
      00024C C0 03            [24]  865 	push	ar3
      00024E C0 04            [24]  866 	push	ar4
      000250 C0 05            [24]  867 	push	ar5
      000252 C0 06            [24]  868 	push	ar6
      000254 8F 82            [24]  869 	mov	dpl, r7
      000256 12 00 B7         [24]  870 	lcall	_fuzzy_8051_and2
      000259 AC 82            [24]  871 	mov	r4, dpl
      00025B AD 83            [24]  872 	mov	r5, dph
      00025D AE F0            [24]  873 	mov	r6, b
      00025F FF               [12]  874 	mov	r7, a
      000260 E5 81            [12]  875 	mov	a,sp
      000262 24 F8            [12]  876 	add	a,#0xf8
      000264 F5 81            [12]  877 	mov	sp,a
      000266 8C 82            [24]  878 	mov	dpl, r4
      000268 8D 83            [24]  879 	mov	dph, r5
      00026A 8E F0            [24]  880 	mov	b, r6
      00026C EF               [12]  881 	mov	a, r7
      00026D D0 1D            [24]  882 	pop	_bp
                           0001B8   883 	C$fuzzy.h$56$1_0$14 ==.
                           0001B8   884 	XFcontroller_8051$fuzzy_8051_and3$0$0 ==.
      00026F 22               [24]  885 	ret
                                    886 ;------------------------------------------------------------
                                    887 ;Allocation info for local variables in function 'fuzzy_8051_or2'
                                    888 ;------------------------------------------------------------
                                    889 ;a             Allocated to stack - _bp -6 +4 
                                    890 ;b             Allocated to stack - _bp -10 +4 
                                    891 ;method        Allocated to registers r7 
                                    892 ;value         Allocated to registers r4 r5 r6 r7 
                                    893 ;sloc0         Allocated to stack - _bp +1 +4 
                                    894 ;------------------------------------------------------------
                           0001B9   895 	Fcontroller_8051$fuzzy_8051_or2$0$0 ==.
                           0001B9   896 	C$fuzzy.h$57$1_0$16 ==.
                                    897 ;	../../fuzzy.h:57: static float fuzzy_8051_or2(fuzzy_logic_method_t method, float a, float b) { if (method == FUZZY_LOGIC_ALGEBRAIC) return a + b - a * b; if (method == FUZZY_LOGIC_BOUNDED) { float value = a + b; return value < 1.0f ? value : 1.0f; } return a > b ? a : b; }
                                    898 ;	-----------------------------------------
                                    899 ;	 function fuzzy_8051_or2
                                    900 ;	-----------------------------------------
      000270                        901 _fuzzy_8051_or2:
      000270 C0 1D            [24]  902 	push	_bp
      000272 E5 81            [12]  903 	mov	a,sp
      000274 F5 1D            [12]  904 	mov	_bp,a
      000276 24 04            [12]  905 	add	a,#0x04
      000278 F5 81            [12]  906 	mov	sp,a
      00027A AF 82            [24]  907 	mov	r7, dpl
      00027C BF 01 02         [24]  908 	cjne	r7,#0x01,00135$
      00027F 80 03            [24]  909 	sjmp	00136$
      000281                        910 00135$:
      000281 02 03 1F         [24]  911 	ljmp	00102$
      000284                        912 00136$:
      000284 E5 1D            [12]  913 	mov	a,_bp
      000286 24 F6            [12]  914 	add	a,#0xf6
      000288 F8               [12]  915 	mov	r0,a
      000289 E6               [12]  916 	mov	a,@r0
      00028A C0 E0            [24]  917 	push	acc
      00028C 08               [12]  918 	inc	r0
      00028D E6               [12]  919 	mov	a,@r0
      00028E C0 E0            [24]  920 	push	acc
      000290 08               [12]  921 	inc	r0
      000291 E6               [12]  922 	mov	a,@r0
      000292 C0 E0            [24]  923 	push	acc
      000294 08               [12]  924 	inc	r0
      000295 E6               [12]  925 	mov	a,@r0
      000296 C0 E0            [24]  926 	push	acc
      000298 E5 1D            [12]  927 	mov	a,_bp
      00029A 24 FA            [12]  928 	add	a,#0xfa
      00029C F8               [12]  929 	mov	r0,a
      00029D 86 82            [24]  930 	mov	dpl, @r0
      00029F 08               [12]  931 	inc	r0
      0002A0 86 83            [24]  932 	mov	dph, @r0
      0002A2 08               [12]  933 	inc	r0
      0002A3 86 F0            [24]  934 	mov	b, @r0
      0002A5 08               [12]  935 	inc	r0
      0002A6 E6               [12]  936 	mov	a, @r0
      0002A7 12 1E 22         [24]  937 	lcall	___fsadd
      0002AA A8 1D            [24]  938 	mov	r0,_bp
      0002AC 08               [12]  939 	inc	r0
      0002AD A6 82            [24]  940 	mov	@r0, dpl
      0002AF 08               [12]  941 	inc	r0
      0002B0 A6 83            [24]  942 	mov	@r0, dph
      0002B2 08               [12]  943 	inc	r0
      0002B3 A6 F0            [24]  944 	mov	@r0, b
      0002B5 08               [12]  945 	inc	r0
      0002B6 F6               [12]  946 	mov	@r0,a
      0002B7 E5 81            [12]  947 	mov	a,sp
      0002B9 24 FC            [12]  948 	add	a,#0xfc
      0002BB F5 81            [12]  949 	mov	sp,a
      0002BD E5 1D            [12]  950 	mov	a,_bp
      0002BF 24 F6            [12]  951 	add	a,#0xf6
      0002C1 F8               [12]  952 	mov	r0,a
      0002C2 E6               [12]  953 	mov	a,@r0
      0002C3 C0 E0            [24]  954 	push	acc
      0002C5 08               [12]  955 	inc	r0
      0002C6 E6               [12]  956 	mov	a,@r0
      0002C7 C0 E0            [24]  957 	push	acc
      0002C9 08               [12]  958 	inc	r0
      0002CA E6               [12]  959 	mov	a,@r0
      0002CB C0 E0            [24]  960 	push	acc
      0002CD 08               [12]  961 	inc	r0
      0002CE E6               [12]  962 	mov	a,@r0
      0002CF C0 E0            [24]  963 	push	acc
      0002D1 E5 1D            [12]  964 	mov	a,_bp
      0002D3 24 FA            [12]  965 	add	a,#0xfa
      0002D5 F8               [12]  966 	mov	r0,a
      0002D6 86 82            [24]  967 	mov	dpl, @r0
      0002D8 08               [12]  968 	inc	r0
      0002D9 86 83            [24]  969 	mov	dph, @r0
      0002DB 08               [12]  970 	inc	r0
      0002DC 86 F0            [24]  971 	mov	b, @r0
      0002DE 08               [12]  972 	inc	r0
      0002DF E6               [12]  973 	mov	a, @r0
      0002E0 12 1C C2         [24]  974 	lcall	___fsmul
      0002E3 AA 82            [24]  975 	mov	r2, dpl
      0002E5 AC 83            [24]  976 	mov	r4, dph
      0002E7 AD F0            [24]  977 	mov	r5, b
      0002E9 FE               [12]  978 	mov	r6, a
      0002EA E5 81            [12]  979 	mov	a,sp
      0002EC 24 FC            [12]  980 	add	a,#0xfc
      0002EE F5 81            [12]  981 	mov	sp,a
      0002F0 C0 02            [24]  982 	push	ar2
      0002F2 C0 04            [24]  983 	push	ar4
      0002F4 C0 05            [24]  984 	push	ar5
      0002F6 C0 06            [24]  985 	push	ar6
      0002F8 A8 1D            [24]  986 	mov	r0,_bp
      0002FA 08               [12]  987 	inc	r0
      0002FB 86 82            [24]  988 	mov	dpl, @r0
      0002FD 08               [12]  989 	inc	r0
      0002FE 86 83            [24]  990 	mov	dph, @r0
      000300 08               [12]  991 	inc	r0
      000301 86 F0            [24]  992 	mov	b, @r0
      000303 08               [12]  993 	inc	r0
      000304 E6               [12]  994 	mov	a, @r0
      000305 12 1C B7         [24]  995 	lcall	___fssub
      000308 AB 82            [24]  996 	mov	r3, dpl
      00030A AC 83            [24]  997 	mov	r4, dph
      00030C AD F0            [24]  998 	mov	r5, b
      00030E FE               [12]  999 	mov	r6, a
      00030F E5 81            [12] 1000 	mov	a,sp
      000311 24 FC            [12] 1001 	add	a,#0xfc
      000313 F5 81            [12] 1002 	mov	sp,a
      000315 8B 82            [24] 1003 	mov	dpl, r3
      000317 8C 83            [24] 1004 	mov	dph, r4
      000319 8D F0            [24] 1005 	mov	b, r5
      00031B EE               [12] 1006 	mov	a, r6
      00031C 02 03 F4         [24] 1007 	ljmp	00105$
      00031F                       1008 00102$:
      00031F BF 02 78         [24] 1009 	cjne	r7,#0x02,00104$
      000322 E5 1D            [12] 1010 	mov	a,_bp
      000324 24 F6            [12] 1011 	add	a,#0xf6
      000326 F8               [12] 1012 	mov	r0,a
      000327 E6               [12] 1013 	mov	a,@r0
      000328 C0 E0            [24] 1014 	push	acc
      00032A 08               [12] 1015 	inc	r0
      00032B E6               [12] 1016 	mov	a,@r0
      00032C C0 E0            [24] 1017 	push	acc
      00032E 08               [12] 1018 	inc	r0
      00032F E6               [12] 1019 	mov	a,@r0
      000330 C0 E0            [24] 1020 	push	acc
      000332 08               [12] 1021 	inc	r0
      000333 E6               [12] 1022 	mov	a,@r0
      000334 C0 E0            [24] 1023 	push	acc
      000336 E5 1D            [12] 1024 	mov	a,_bp
      000338 24 FA            [12] 1025 	add	a,#0xfa
      00033A F8               [12] 1026 	mov	r0,a
      00033B 86 82            [24] 1027 	mov	dpl, @r0
      00033D 08               [12] 1028 	inc	r0
      00033E 86 83            [24] 1029 	mov	dph, @r0
      000340 08               [12] 1030 	inc	r0
      000341 86 F0            [24] 1031 	mov	b, @r0
      000343 08               [12] 1032 	inc	r0
      000344 E6               [12] 1033 	mov	a, @r0
      000345 12 1E 22         [24] 1034 	lcall	___fsadd
      000348 AC 82            [24] 1035 	mov	r4, dpl
      00034A AD 83            [24] 1036 	mov	r5, dph
      00034C AE F0            [24] 1037 	mov	r6, b
      00034E FF               [12] 1038 	mov	r7, a
      00034F E5 81            [12] 1039 	mov	a,sp
      000351 24 FC            [12] 1040 	add	a,#0xfc
      000353 F5 81            [12] 1041 	mov	sp,a
      000355 C0 07            [24] 1042 	push	ar7
      000357 C0 06            [24] 1043 	push	ar6
      000359 C0 05            [24] 1044 	push	ar5
      00035B C0 04            [24] 1045 	push	ar4
      00035D E4               [12] 1046 	clr	a
      00035E C0 E0            [24] 1047 	push	acc
      000360 C0 E0            [24] 1048 	push	acc
      000362 74 80            [12] 1049 	mov	a,#0x80
      000364 C0 E0            [24] 1050 	push	acc
      000366 74 3F            [12] 1051 	mov	a,#0x3f
      000368 C0 E0            [24] 1052 	push	acc
      00036A 8C 82            [24] 1053 	mov	dpl, r4
      00036C 8D 83            [24] 1054 	mov	dph, r5
      00036E 8E F0            [24] 1055 	mov	b, r6
      000370 EF               [12] 1056 	mov	a, r7
      000371 12 1D F2         [24] 1057 	lcall	___fslt
      000374 AB 82            [24] 1058 	mov	r3, dpl
      000376 E5 81            [12] 1059 	mov	a,sp
      000378 24 FC            [12] 1060 	add	a,#0xfc
      00037A F5 81            [12] 1061 	mov	sp,a
      00037C D0 04            [24] 1062 	pop	ar4
      00037E D0 05            [24] 1063 	pop	ar5
      000380 D0 06            [24] 1064 	pop	ar6
      000382 D0 07            [24] 1065 	pop	ar7
      000384 EB               [12] 1066 	mov	a,r3
      000385 60 02            [24] 1067 	jz	00107$
      000387 80 08            [24] 1068 	sjmp	00108$
      000389                       1069 00107$:
      000389 7C 00            [12] 1070 	mov	r4,#0x00
      00038B 7D 00            [12] 1071 	mov	r5,#0x00
      00038D 7E 80            [12] 1072 	mov	r6,#0x80
      00038F 7F 3F            [12] 1073 	mov	r7,#0x3f
      000391                       1074 00108$:
      000391 8C 82            [24] 1075 	mov	dpl, r4
      000393 8D 83            [24] 1076 	mov	dph, r5
      000395 8E F0            [24] 1077 	mov	b, r6
      000397 EF               [12] 1078 	mov	a, r7
      000398 80 5A            [24] 1079 	sjmp	00105$
      00039A                       1080 00104$:
      00039A E5 1D            [12] 1081 	mov	a,_bp
      00039C 24 FA            [12] 1082 	add	a,#0xfa
      00039E F8               [12] 1083 	mov	r0,a
      00039F E6               [12] 1084 	mov	a,@r0
      0003A0 C0 E0            [24] 1085 	push	acc
      0003A2 08               [12] 1086 	inc	r0
      0003A3 E6               [12] 1087 	mov	a,@r0
      0003A4 C0 E0            [24] 1088 	push	acc
      0003A6 08               [12] 1089 	inc	r0
      0003A7 E6               [12] 1090 	mov	a,@r0
      0003A8 C0 E0            [24] 1091 	push	acc
      0003AA 08               [12] 1092 	inc	r0
      0003AB E6               [12] 1093 	mov	a,@r0
      0003AC C0 E0            [24] 1094 	push	acc
      0003AE E5 1D            [12] 1095 	mov	a,_bp
      0003B0 24 F6            [12] 1096 	add	a,#0xf6
      0003B2 F8               [12] 1097 	mov	r0,a
      0003B3 86 82            [24] 1098 	mov	dpl, @r0
      0003B5 08               [12] 1099 	inc	r0
      0003B6 86 83            [24] 1100 	mov	dph, @r0
      0003B8 08               [12] 1101 	inc	r0
      0003B9 86 F0            [24] 1102 	mov	b, @r0
      0003BB 08               [12] 1103 	inc	r0
      0003BC E6               [12] 1104 	mov	a, @r0
      0003BD 12 1D F2         [24] 1105 	lcall	___fslt
      0003C0 AF 82            [24] 1106 	mov	r7, dpl
      0003C2 E5 81            [12] 1107 	mov	a,sp
      0003C4 24 FC            [12] 1108 	add	a,#0xfc
      0003C6 F5 81            [12] 1109 	mov	sp,a
      0003C8 EF               [12] 1110 	mov	a,r7
      0003C9 60 12            [24] 1111 	jz	00109$
      0003CB E5 1D            [12] 1112 	mov	a,_bp
      0003CD 24 FA            [12] 1113 	add	a,#0xfa
      0003CF F8               [12] 1114 	mov	r0,a
      0003D0 86 04            [24] 1115 	mov	ar4,@r0
      0003D2 08               [12] 1116 	inc	r0
      0003D3 86 05            [24] 1117 	mov	ar5,@r0
      0003D5 08               [12] 1118 	inc	r0
      0003D6 86 06            [24] 1119 	mov	ar6,@r0
      0003D8 08               [12] 1120 	inc	r0
      0003D9 86 07            [24] 1121 	mov	ar7,@r0
      0003DB 80 10            [24] 1122 	sjmp	00110$
      0003DD                       1123 00109$:
      0003DD E5 1D            [12] 1124 	mov	a,_bp
      0003DF 24 F6            [12] 1125 	add	a,#0xf6
      0003E1 F8               [12] 1126 	mov	r0,a
      0003E2 86 04            [24] 1127 	mov	ar4,@r0
      0003E4 08               [12] 1128 	inc	r0
      0003E5 86 05            [24] 1129 	mov	ar5,@r0
      0003E7 08               [12] 1130 	inc	r0
      0003E8 86 06            [24] 1131 	mov	ar6,@r0
      0003EA 08               [12] 1132 	inc	r0
      0003EB 86 07            [24] 1133 	mov	ar7,@r0
      0003ED                       1134 00110$:
      0003ED 8C 82            [24] 1135 	mov	dpl, r4
      0003EF 8D 83            [24] 1136 	mov	dph, r5
      0003F1 8E F0            [24] 1137 	mov	b, r6
      0003F3 EF               [12] 1138 	mov	a, r7
      0003F4                       1139 00105$:
      0003F4 85 1D 81         [24] 1140 	mov	sp,_bp
      0003F7 D0 1D            [24] 1141 	pop	_bp
                           000342  1142 	C$fuzzy.h$57$1_0$16 ==.
                           000342  1143 	XFcontroller_8051$fuzzy_8051_or2$0$0 ==.
      0003F9 22               [24] 1144 	ret
                                   1145 ;------------------------------------------------------------
                                   1146 ;Allocation info for local variables in function 'fuzzy_8051_or3'
                                   1147 ;------------------------------------------------------------
                                   1148 ;a             Allocated to stack - _bp -6 +4 
                                   1149 ;b             Allocated to stack - _bp -10 +4 
                                   1150 ;c             Allocated to stack - _bp -14 +4 
                                   1151 ;method        Allocated to registers r7 
                                   1152 ;------------------------------------------------------------
                           000343  1153 	Fcontroller_8051$fuzzy_8051_or3$0$0 ==.
                           000343  1154 	C$fuzzy.h$58$1_0$19 ==.
                                   1155 ;	../../fuzzy.h:58: static float fuzzy_8051_or3(fuzzy_logic_method_t method, float a, float b, float c) { return fuzzy_8051_or2(method, fuzzy_8051_or2(method, a, b), c); }
                                   1156 ;	-----------------------------------------
                                   1157 ;	 function fuzzy_8051_or3
                                   1158 ;	-----------------------------------------
      0003FA                       1159 _fuzzy_8051_or3:
      0003FA C0 1D            [24] 1160 	push	_bp
      0003FC 85 81 1D         [24] 1161 	mov	_bp,sp
      0003FF AF 82            [24] 1162 	mov	r7, dpl
      000401 C0 07            [24] 1163 	push	ar7
      000403 E5 1D            [12] 1164 	mov	a,_bp
      000405 24 F6            [12] 1165 	add	a,#0xf6
      000407 F8               [12] 1166 	mov	r0,a
      000408 E6               [12] 1167 	mov	a,@r0
      000409 C0 E0            [24] 1168 	push	acc
      00040B 08               [12] 1169 	inc	r0
      00040C E6               [12] 1170 	mov	a,@r0
      00040D C0 E0            [24] 1171 	push	acc
      00040F 08               [12] 1172 	inc	r0
      000410 E6               [12] 1173 	mov	a,@r0
      000411 C0 E0            [24] 1174 	push	acc
      000413 08               [12] 1175 	inc	r0
      000414 E6               [12] 1176 	mov	a,@r0
      000415 C0 E0            [24] 1177 	push	acc
      000417 E5 1D            [12] 1178 	mov	a,_bp
      000419 24 FA            [12] 1179 	add	a,#0xfa
      00041B F8               [12] 1180 	mov	r0,a
      00041C E6               [12] 1181 	mov	a,@r0
      00041D C0 E0            [24] 1182 	push	acc
      00041F 08               [12] 1183 	inc	r0
      000420 E6               [12] 1184 	mov	a,@r0
      000421 C0 E0            [24] 1185 	push	acc
      000423 08               [12] 1186 	inc	r0
      000424 E6               [12] 1187 	mov	a,@r0
      000425 C0 E0            [24] 1188 	push	acc
      000427 08               [12] 1189 	inc	r0
      000428 E6               [12] 1190 	mov	a,@r0
      000429 C0 E0            [24] 1191 	push	acc
      00042B 8F 82            [24] 1192 	mov	dpl, r7
      00042D 12 02 70         [24] 1193 	lcall	_fuzzy_8051_or2
      000430 AB 82            [24] 1194 	mov	r3, dpl
      000432 AC 83            [24] 1195 	mov	r4, dph
      000434 AD F0            [24] 1196 	mov	r5, b
      000436 FE               [12] 1197 	mov	r6, a
      000437 E5 81            [12] 1198 	mov	a,sp
      000439 24 F8            [12] 1199 	add	a,#0xf8
      00043B F5 81            [12] 1200 	mov	sp,a
      00043D D0 07            [24] 1201 	pop	ar7
      00043F E5 1D            [12] 1202 	mov	a,_bp
      000441 24 F2            [12] 1203 	add	a,#0xf2
      000443 F8               [12] 1204 	mov	r0,a
      000444 E6               [12] 1205 	mov	a,@r0
      000445 C0 E0            [24] 1206 	push	acc
      000447 08               [12] 1207 	inc	r0
      000448 E6               [12] 1208 	mov	a,@r0
      000449 C0 E0            [24] 1209 	push	acc
      00044B 08               [12] 1210 	inc	r0
      00044C E6               [12] 1211 	mov	a,@r0
      00044D C0 E0            [24] 1212 	push	acc
      00044F 08               [12] 1213 	inc	r0
      000450 E6               [12] 1214 	mov	a,@r0
      000451 C0 E0            [24] 1215 	push	acc
      000453 C0 03            [24] 1216 	push	ar3
      000455 C0 04            [24] 1217 	push	ar4
      000457 C0 05            [24] 1218 	push	ar5
      000459 C0 06            [24] 1219 	push	ar6
      00045B 8F 82            [24] 1220 	mov	dpl, r7
      00045D 12 02 70         [24] 1221 	lcall	_fuzzy_8051_or2
      000460 AC 82            [24] 1222 	mov	r4, dpl
      000462 AD 83            [24] 1223 	mov	r5, dph
      000464 AE F0            [24] 1224 	mov	r6, b
      000466 FF               [12] 1225 	mov	r7, a
      000467 E5 81            [12] 1226 	mov	a,sp
      000469 24 F8            [12] 1227 	add	a,#0xf8
      00046B F5 81            [12] 1228 	mov	sp,a
      00046D 8C 82            [24] 1229 	mov	dpl, r4
      00046F 8D 83            [24] 1230 	mov	dph, r5
      000471 8E F0            [24] 1231 	mov	b, r6
      000473 EF               [12] 1232 	mov	a, r7
      000474 D0 1D            [24] 1233 	pop	_bp
                           0003BF  1234 	C$fuzzy.h$58$1_0$19 ==.
                           0003BF  1235 	XFcontroller_8051$fuzzy_8051_or3$0$0 ==.
      000476 22               [24] 1236 	ret
                                   1237 ;------------------------------------------------------------
                                   1238 ;Allocation info for local variables in function 'fuzzy_8051_clamp'
                                   1239 ;------------------------------------------------------------
                                   1240 ;value         Allocated to registers r4 r5 r6 r7 
                                   1241 ;------------------------------------------------------------
                           0003C0  1242 	Fcontroller_8051$fuzzy_8051_clamp$0$0 ==.
                           0003C0  1243 	C$fuzzy.h$66$1_0$21 ==.
                                   1244 ;	../../fuzzy.h:66: static float fuzzy_8051_clamp(float value) { if (value < 0.0f) return 0.0f; if (value > 1.0f) return 1.0f; return value; }
                                   1245 ;	-----------------------------------------
                                   1246 ;	 function fuzzy_8051_clamp
                                   1247 ;	-----------------------------------------
      000477                       1248 _fuzzy_8051_clamp:
      000477 AC 82            [24] 1249 	mov	r4,dpl
      000479 AD 83            [24] 1250 	mov	r5,dph
      00047B AE F0            [24] 1251 	mov	r6,b
      00047D FF               [12] 1252 	mov	r7,a
      00047E C0 07            [24] 1253 	push	ar7
      000480 C0 06            [24] 1254 	push	ar6
      000482 C0 05            [24] 1255 	push	ar5
      000484 C0 04            [24] 1256 	push	ar4
      000486 E4               [12] 1257 	clr	a
      000487 C0 E0            [24] 1258 	push	acc
      000489 C0 E0            [24] 1259 	push	acc
      00048B C0 E0            [24] 1260 	push	acc
      00048D C0 E0            [24] 1261 	push	acc
      00048F 8C 82            [24] 1262 	mov	dpl, r4
      000491 8D 83            [24] 1263 	mov	dph, r5
      000493 8E F0            [24] 1264 	mov	b, r6
      000495 EF               [12] 1265 	mov	a, r7
      000496 12 1D F2         [24] 1266 	lcall	___fslt
      000499 AB 82            [24] 1267 	mov	r3, dpl
      00049B E5 81            [12] 1268 	mov	a,sp
      00049D 24 FC            [12] 1269 	add	a,#0xfc
      00049F F5 81            [12] 1270 	mov	sp,a
      0004A1 D0 04            [24] 1271 	pop	ar4
      0004A3 D0 05            [24] 1272 	pop	ar5
      0004A5 D0 06            [24] 1273 	pop	ar6
      0004A7 D0 07            [24] 1274 	pop	ar7
      0004A9 EB               [12] 1275 	mov	a,r3
      0004AA 60 08            [24] 1276 	jz	00102$
      0004AC 90 00 00         [24] 1277 	mov	dptr,#0x0000
      0004AF E4               [12] 1278 	clr	a
      0004B0 F5 F0            [12] 1279 	mov	b,a
      0004B2 80 3F            [24] 1280 	sjmp	00105$
      0004B4                       1281 00102$:
      0004B4 C0 07            [24] 1282 	push	ar7
      0004B6 C0 06            [24] 1283 	push	ar6
      0004B8 C0 05            [24] 1284 	push	ar5
      0004BA C0 04            [24] 1285 	push	ar4
      0004BC C0 04            [24] 1286 	push	ar4
      0004BE C0 05            [24] 1287 	push	ar5
      0004C0 C0 06            [24] 1288 	push	ar6
      0004C2 C0 07            [24] 1289 	push	ar7
      0004C4 90 00 00         [24] 1290 	mov	dptr,#0x0000
      0004C7 75 F0 80         [24] 1291 	mov	b, #0x80
      0004CA 74 3F            [12] 1292 	mov	a, #0x3f
      0004CC 12 1D F2         [24] 1293 	lcall	___fslt
      0004CF AB 82            [24] 1294 	mov	r3, dpl
      0004D1 E5 81            [12] 1295 	mov	a,sp
      0004D3 24 FC            [12] 1296 	add	a,#0xfc
      0004D5 F5 81            [12] 1297 	mov	sp,a
      0004D7 D0 04            [24] 1298 	pop	ar4
      0004D9 D0 05            [24] 1299 	pop	ar5
      0004DB D0 06            [24] 1300 	pop	ar6
      0004DD D0 07            [24] 1301 	pop	ar7
      0004DF EB               [12] 1302 	mov	a,r3
      0004E0 60 0A            [24] 1303 	jz	00104$
      0004E2 90 00 00         [24] 1304 	mov	dptr,#0x0000
      0004E5 75 F0 80         [24] 1305 	mov	b, #0x80
      0004E8 74 3F            [12] 1306 	mov	a, #0x3f
      0004EA 80 07            [24] 1307 	sjmp	00105$
      0004EC                       1308 00104$:
      0004EC 8C 82            [24] 1309 	mov	dpl, r4
      0004EE 8D 83            [24] 1310 	mov	dph, r5
      0004F0 8E F0            [24] 1311 	mov	b, r6
      0004F2 EF               [12] 1312 	mov	a, r7
      0004F3                       1313 00105$:
                           00043C  1314 	C$fuzzy.h$66$1_0$21 ==.
                           00043C  1315 	XFcontroller_8051$fuzzy_8051_clamp$0$0 ==.
      0004F3 22               [24] 1316 	ret
                                   1317 ;------------------------------------------------------------
                                   1318 ;Allocation info for local variables in function 'fuzzy_8051_hedge'
                                   1319 ;------------------------------------------------------------
                                   1320 ;hedge         Allocated to stack - _bp -3 +1 
                                   1321 ;value         Allocated to stack - _bp +1 +4 
                                   1322 ;result        Allocated to registers r2 r3 r6 r7 
                                   1323 ;------------------------------------------------------------
                           00043D  1324 	Fcontroller_8051$fuzzy_8051_hedge$0$0 ==.
                           00043D  1325 	C$fuzzy.h$67$1_0$23 ==.
                                   1326 ;	../../fuzzy.h:67: static float fuzzy_8051_hedge(float value, fuzzy_hedge_t hedge) { float result; value = fuzzy_8051_clamp(value); if (hedge == 0u) hedge = 1u; result = 1.0f; while (hedge != 0u) { result *= value; --hedge; } return fuzzy_8051_clamp(result); }
                                   1327 ;	-----------------------------------------
                                   1328 ;	 function fuzzy_8051_hedge
                                   1329 ;	-----------------------------------------
      0004F4                       1330 _fuzzy_8051_hedge:
      0004F4 C0 1D            [24] 1331 	push	_bp
      0004F6 85 81 1D         [24] 1332 	mov	_bp,sp
      0004F9 AC 82            [24] 1333 	mov	r4,dpl
      0004FB AD 83            [24] 1334 	mov	r5,dph
      0004FD AE F0            [24] 1335 	mov	r6,b
      0004FF FF               [12] 1336 	mov	r7,a
      000500 E5 81            [12] 1337 	mov	a,sp
      000502 24 04            [12] 1338 	add	a,#0x04
      000504 F5 81            [12] 1339 	mov	sp,a
      000506 8C 82            [24] 1340 	mov	dpl, r4
      000508 8D 83            [24] 1341 	mov	dph, r5
      00050A 8E F0            [24] 1342 	mov	b, r6
      00050C EF               [12] 1343 	mov	a, r7
      00050D 12 04 77         [24] 1344 	lcall	_fuzzy_8051_clamp
      000510 A8 1D            [24] 1345 	mov	r0,_bp
      000512 08               [12] 1346 	inc	r0
      000513 A6 82            [24] 1347 	mov	@r0, dpl
      000515 08               [12] 1348 	inc	r0
      000516 A6 83            [24] 1349 	mov	@r0, dph
      000518 08               [12] 1350 	inc	r0
      000519 A6 F0            [24] 1351 	mov	@r0, b
      00051B 08               [12] 1352 	inc	r0
      00051C F6               [12] 1353 	mov	@r0,a
      00051D E5 1D            [12] 1354 	mov	a,_bp
      00051F 24 FD            [12] 1355 	add	a,#0xfd
      000521 F8               [12] 1356 	mov	r0,a
      000522 E6               [12] 1357 	mov	a,@r0
      000523 70 07            [24] 1358 	jnz	00102$
      000525 E5 1D            [12] 1359 	mov	a,_bp
      000527 24 FD            [12] 1360 	add	a,#0xfd
      000529 F8               [12] 1361 	mov	r0,a
      00052A 76 01            [12] 1362 	mov	@r0,#0x01
      00052C                       1363 00102$:
      00052C 7A 00            [12] 1364 	mov	r2,#0x00
      00052E 7B 00            [12] 1365 	mov	r3,#0x00
      000530 7E 80            [12] 1366 	mov	r6,#0x80
      000532 7F 3F            [12] 1367 	mov	r7,#0x3f
      000534 E5 1D            [12] 1368 	mov	a,_bp
      000536 24 FD            [12] 1369 	add	a,#0xfd
      000538 F8               [12] 1370 	mov	r0,a
      000539 86 05            [24] 1371 	mov	ar5,@r0
      00053B                       1372 00103$:
      00053B ED               [12] 1373 	mov	a,r5
      00053C 60 30            [24] 1374 	jz	00105$
      00053E C0 05            [24] 1375 	push	ar5
      000540 A8 1D            [24] 1376 	mov	r0,_bp
      000542 08               [12] 1377 	inc	r0
      000543 E6               [12] 1378 	mov	a,@r0
      000544 C0 E0            [24] 1379 	push	acc
      000546 08               [12] 1380 	inc	r0
      000547 E6               [12] 1381 	mov	a,@r0
      000548 C0 E0            [24] 1382 	push	acc
      00054A 08               [12] 1383 	inc	r0
      00054B E6               [12] 1384 	mov	a,@r0
      00054C C0 E0            [24] 1385 	push	acc
      00054E 08               [12] 1386 	inc	r0
      00054F E6               [12] 1387 	mov	a,@r0
      000550 C0 E0            [24] 1388 	push	acc
      000552 8A 82            [24] 1389 	mov	dpl, r2
      000554 8B 83            [24] 1390 	mov	dph, r3
      000556 8E F0            [24] 1391 	mov	b, r6
      000558 EF               [12] 1392 	mov	a, r7
      000559 12 1C C2         [24] 1393 	lcall	___fsmul
      00055C AA 82            [24] 1394 	mov	r2, dpl
      00055E AB 83            [24] 1395 	mov	r3, dph
      000560 AE F0            [24] 1396 	mov	r6, b
      000562 FF               [12] 1397 	mov	r7, a
      000563 E5 81            [12] 1398 	mov	a,sp
      000565 24 FC            [12] 1399 	add	a,#0xfc
      000567 F5 81            [12] 1400 	mov	sp,a
      000569 D0 05            [24] 1401 	pop	ar5
      00056B 1D               [12] 1402 	dec	r5
      00056C 80 CD            [24] 1403 	sjmp	00103$
      00056E                       1404 00105$:
      00056E 8A 82            [24] 1405 	mov	dpl, r2
      000570 8B 83            [24] 1406 	mov	dph, r3
      000572 8E F0            [24] 1407 	mov	b, r6
      000574 EF               [12] 1408 	mov	a, r7
      000575 12 04 77         [24] 1409 	lcall	_fuzzy_8051_clamp
      000578 85 1D 81         [24] 1410 	mov	sp,_bp
      00057B D0 1D            [24] 1411 	pop	_bp
                           0004C6  1412 	C$fuzzy.h$67$1_0$23 ==.
                           0004C6  1413 	XFcontroller_8051$fuzzy_8051_hedge$0$0 ==.
      00057D 22               [24] 1414 	ret
                                   1415 ;------------------------------------------------------------
                                   1416 ;Allocation info for local variables in function 'fuzzy_not'
                                   1417 ;------------------------------------------------------------
                                   1418 ;membership    Allocated to registers r4 r5 r6 r7 
                                   1419 ;------------------------------------------------------------
                           0004C7  1420 	G$fuzzy_not$0$0 ==.
                           0004C7  1421 	C$fuzzy.h$68$1_0$26 ==.
                                   1422 ;	../../fuzzy.h:68: float fuzzy_not(float membership) { return 1.0f - fuzzy_8051_clamp(membership); }
                                   1423 ;	-----------------------------------------
                                   1424 ;	 function fuzzy_not
                                   1425 ;	-----------------------------------------
      00057E                       1426 _fuzzy_not:
      00057E 12 04 77         [24] 1427 	lcall	_fuzzy_8051_clamp
      000581 AC 82            [24] 1428 	mov	r4, dpl
      000583 AD 83            [24] 1429 	mov	r5, dph
      000585 AE F0            [24] 1430 	mov	r6, b
      000587 FF               [12] 1431 	mov	r7, a
      000588 C0 04            [24] 1432 	push	ar4
      00058A C0 05            [24] 1433 	push	ar5
      00058C C0 06            [24] 1434 	push	ar6
      00058E C0 07            [24] 1435 	push	ar7
      000590 90 00 00         [24] 1436 	mov	dptr,#0x0000
      000593 75 F0 80         [24] 1437 	mov	b, #0x80
      000596 74 3F            [12] 1438 	mov	a, #0x3f
      000598 12 1C B7         [24] 1439 	lcall	___fssub
      00059B AC 82            [24] 1440 	mov	r4, dpl
      00059D AD 83            [24] 1441 	mov	r5, dph
      00059F AE F0            [24] 1442 	mov	r6, b
      0005A1 FF               [12] 1443 	mov	r7, a
      0005A2 E5 81            [12] 1444 	mov	a,sp
      0005A4 24 FC            [12] 1445 	add	a,#0xfc
      0005A6 F5 81            [12] 1446 	mov	sp,a
      0005A8 8C 82            [24] 1447 	mov	dpl, r4
      0005AA 8D 83            [24] 1448 	mov	dph, r5
      0005AC 8E F0            [24] 1449 	mov	b, r6
      0005AE EF               [12] 1450 	mov	a, r7
                           0004F8  1451 	C$fuzzy.h$68$1_0$26 ==.
                           0004F8  1452 	XG$fuzzy_not$0$0 ==.
      0005AF 22               [24] 1453 	ret
                                   1454 ;------------------------------------------------------------
                                   1455 ;Allocation info for local variables in function 'fuzzy_ramp'
                                   1456 ;------------------------------------------------------------
                                   1457 ;b             Allocated to stack - _bp -6 +4 
                                   1458 ;x             Allocated to stack - _bp -10 +4 
                                   1459 ;up            Allocated to stack - _bp -11 +1 
                                   1460 ;hedge         Allocated to stack - _bp -12 +1 
                                   1461 ;a             Allocated to registers r7 r6 r5 r4 
                                   1462 ;result        Allocated to stack - _bp +5 +4 
                                   1463 ;sloc0         Allocated to stack - _bp +1 +4 
                                   1464 ;------------------------------------------------------------
                           0004F9  1465 	G$fuzzy_ramp$0$0 ==.
                           0004F9  1466 	C$fuzzy.h$69$1_0$28 ==.
                                   1467 ;	../../fuzzy.h:69: float fuzzy_ramp(float a, float b, float x, bool up, fuzzy_hedge_t hedge) { float result; if (a >= b) return 0.0f; if (x <= a) result = up ? 0.0f : 1.0f; else if (x >= b) result = up ? 1.0f : 0.0f; else { result = (x - a) / (b - a); if (!up) result = 1.0f - result; } return fuzzy_8051_hedge(result, hedge); }
                                   1468 ;	-----------------------------------------
                                   1469 ;	 function fuzzy_ramp
                                   1470 ;	-----------------------------------------
      0005B0                       1471 _fuzzy_ramp:
      0005B0 C0 1D            [24] 1472 	push	_bp
      0005B2 85 81 1D         [24] 1473 	mov	_bp,sp
      0005B5 AF 82            [24] 1474 	mov	r7,dpl
      0005B7 AE 83            [24] 1475 	mov	r6,dph
      0005B9 AD F0            [24] 1476 	mov	r5,b
      0005BB FC               [12] 1477 	mov	r4,a
      0005BC E5 81            [12] 1478 	mov	a,sp
      0005BE 24 08            [12] 1479 	add	a,#0x08
      0005C0 F5 81            [12] 1480 	mov	sp,a
      0005C2 C0 07            [24] 1481 	push	ar7
      0005C4 C0 06            [24] 1482 	push	ar6
      0005C6 C0 05            [24] 1483 	push	ar5
      0005C8 C0 04            [24] 1484 	push	ar4
      0005CA E5 1D            [12] 1485 	mov	a,_bp
      0005CC 24 FA            [12] 1486 	add	a,#0xfa
      0005CE F8               [12] 1487 	mov	r0,a
      0005CF E6               [12] 1488 	mov	a,@r0
      0005D0 C0 E0            [24] 1489 	push	acc
      0005D2 08               [12] 1490 	inc	r0
      0005D3 E6               [12] 1491 	mov	a,@r0
      0005D4 C0 E0            [24] 1492 	push	acc
      0005D6 08               [12] 1493 	inc	r0
      0005D7 E6               [12] 1494 	mov	a,@r0
      0005D8 C0 E0            [24] 1495 	push	acc
      0005DA 08               [12] 1496 	inc	r0
      0005DB E6               [12] 1497 	mov	a,@r0
      0005DC C0 E0            [24] 1498 	push	acc
      0005DE 8F 82            [24] 1499 	mov	dpl, r7
      0005E0 8E 83            [24] 1500 	mov	dph, r6
      0005E2 8D F0            [24] 1501 	mov	b, r5
      0005E4 EC               [12] 1502 	mov	a, r4
      0005E5 12 1D F2         [24] 1503 	lcall	___fslt
      0005E8 E5 81            [12] 1504 	mov	a,sp
      0005EA 24 FC            [12] 1505 	add	a,#0xfc
      0005EC F5 81            [12] 1506 	mov	sp,a
      0005EE D0 04            [24] 1507 	pop	ar4
      0005F0 D0 05            [24] 1508 	pop	ar5
      0005F2 D0 06            [24] 1509 	pop	ar6
      0005F4 D0 07            [24] 1510 	pop	ar7
      0005F6 E5 82            [12] 1511 	mov	a, dpl
      0005F8 24 FF            [12] 1512 	add	a,#0xff
      0005FA 92 00            [24] 1513 	mov	b0,c
      0005FC 40 09            [24] 1514 	jc	00102$
      0005FE 90 00 00         [24] 1515 	mov	dptr,#0x0000
      000601 E4               [12] 1516 	clr	a
      000602 F5 F0            [12] 1517 	mov	b,a
      000604 02 07 B6         [24] 1518 	ljmp	00111$
      000607                       1519 00102$:
      000607 C0 07            [24] 1520 	push	ar7
      000609 C0 06            [24] 1521 	push	ar6
      00060B C0 05            [24] 1522 	push	ar5
      00060D C0 04            [24] 1523 	push	ar4
      00060F E5 1D            [12] 1524 	mov	a,_bp
      000611 24 F6            [12] 1525 	add	a,#0xf6
      000613 F8               [12] 1526 	mov	r0,a
      000614 E6               [12] 1527 	mov	a,@r0
      000615 C0 E0            [24] 1528 	push	acc
      000617 08               [12] 1529 	inc	r0
      000618 E6               [12] 1530 	mov	a,@r0
      000619 C0 E0            [24] 1531 	push	acc
      00061B 08               [12] 1532 	inc	r0
      00061C E6               [12] 1533 	mov	a,@r0
      00061D C0 E0            [24] 1534 	push	acc
      00061F 08               [12] 1535 	inc	r0
      000620 E6               [12] 1536 	mov	a,@r0
      000621 C0 E0            [24] 1537 	push	acc
      000623 8F 82            [24] 1538 	mov	dpl, r7
      000625 8E 83            [24] 1539 	mov	dph, r6
      000627 8D F0            [24] 1540 	mov	b, r5
      000629 EC               [12] 1541 	mov	a, r4
      00062A 12 1D F2         [24] 1542 	lcall	___fslt
      00062D E5 81            [12] 1543 	mov	a,sp
      00062F 24 FC            [12] 1544 	add	a,#0xfc
      000631 F5 81            [12] 1545 	mov	sp,a
      000633 D0 04            [24] 1546 	pop	ar4
      000635 D0 05            [24] 1547 	pop	ar5
      000637 D0 06            [24] 1548 	pop	ar6
      000639 D0 07            [24] 1549 	pop	ar7
      00063B E5 82            [12] 1550 	mov	a, dpl
      00063D 24 FF            [12] 1551 	add	a,#0xff
      00063F 92 00            [24] 1552 	mov	b0,c
      000641 40 39            [24] 1553 	jc	00109$
      000643 E5 1D            [12] 1554 	mov	a,_bp
      000645 24 F5            [12] 1555 	add	a,#0xf5
      000647 F8               [12] 1556 	mov	r0,a
      000648 E6               [12] 1557 	mov	a,@r0
      000649 60 0F            [24] 1558 	jz	00113$
      00064B E5 1D            [12] 1559 	mov	a,_bp
      00064D 24 05            [12] 1560 	add	a,#0x05
      00064F F8               [12] 1561 	mov	r0,a
      000650 E4               [12] 1562 	clr	a
      000651 F6               [12] 1563 	mov	@r0,a
      000652 08               [12] 1564 	inc	r0
      000653 F6               [12] 1565 	mov	@r0,a
      000654 08               [12] 1566 	inc	r0
      000655 F6               [12] 1567 	mov	@r0,a
      000656 08               [12] 1568 	inc	r0
      000657 F6               [12] 1569 	mov	@r0,a
      000658 80 0F            [24] 1570 	sjmp	00114$
      00065A                       1571 00113$:
      00065A E5 1D            [12] 1572 	mov	a,_bp
      00065C 24 05            [12] 1573 	add	a,#0x05
      00065E F8               [12] 1574 	mov	r0,a
      00065F E4               [12] 1575 	clr	a
      000660 F6               [12] 1576 	mov	@r0,a
      000661 08               [12] 1577 	inc	r0
      000662 F6               [12] 1578 	mov	@r0,a
      000663 08               [12] 1579 	inc	r0
      000664 76 80            [12] 1580 	mov	@r0,#0x80
      000666 08               [12] 1581 	inc	r0
      000667 76 3F            [12] 1582 	mov	@r0,#0x3f
      000669                       1583 00114$:
      000669 E5 1D            [12] 1584 	mov	a,_bp
      00066B 24 05            [12] 1585 	add	a,#0x05
      00066D F8               [12] 1586 	mov	r0,a
      00066E 86 07            [24] 1587 	mov	ar7,@r0
      000670 08               [12] 1588 	inc	r0
      000671 86 06            [24] 1589 	mov	ar6,@r0
      000673 08               [12] 1590 	inc	r0
      000674 86 05            [24] 1591 	mov	ar5,@r0
      000676 08               [12] 1592 	inc	r0
      000677 86 04            [24] 1593 	mov	ar4,@r0
      000679 02 07 94         [24] 1594 	ljmp	00110$
      00067C                       1595 00109$:
      00067C C0 07            [24] 1596 	push	ar7
      00067E C0 06            [24] 1597 	push	ar6
      000680 C0 05            [24] 1598 	push	ar5
      000682 C0 04            [24] 1599 	push	ar4
      000684 E5 1D            [12] 1600 	mov	a,_bp
      000686 24 FA            [12] 1601 	add	a,#0xfa
      000688 F8               [12] 1602 	mov	r0,a
      000689 E6               [12] 1603 	mov	a,@r0
      00068A C0 E0            [24] 1604 	push	acc
      00068C 08               [12] 1605 	inc	r0
      00068D E6               [12] 1606 	mov	a,@r0
      00068E C0 E0            [24] 1607 	push	acc
      000690 08               [12] 1608 	inc	r0
      000691 E6               [12] 1609 	mov	a,@r0
      000692 C0 E0            [24] 1610 	push	acc
      000694 08               [12] 1611 	inc	r0
      000695 E6               [12] 1612 	mov	a,@r0
      000696 C0 E0            [24] 1613 	push	acc
      000698 E5 1D            [12] 1614 	mov	a,_bp
      00069A 24 F6            [12] 1615 	add	a,#0xf6
      00069C F8               [12] 1616 	mov	r0,a
      00069D 86 82            [24] 1617 	mov	dpl, @r0
      00069F 08               [12] 1618 	inc	r0
      0006A0 86 83            [24] 1619 	mov	dph, @r0
      0006A2 08               [12] 1620 	inc	r0
      0006A3 86 F0            [24] 1621 	mov	b, @r0
      0006A5 08               [12] 1622 	inc	r0
      0006A6 E6               [12] 1623 	mov	a, @r0
      0006A7 12 1D F2         [24] 1624 	lcall	___fslt
      0006AA E5 81            [12] 1625 	mov	a,sp
      0006AC 24 FC            [12] 1626 	add	a,#0xfc
      0006AE F5 81            [12] 1627 	mov	sp,a
      0006B0 D0 04            [24] 1628 	pop	ar4
      0006B2 D0 05            [24] 1629 	pop	ar5
      0006B4 D0 06            [24] 1630 	pop	ar6
      0006B6 D0 07            [24] 1631 	pop	ar7
      0006B8 E5 82            [12] 1632 	mov	a, dpl
      0006BA 24 FF            [12] 1633 	add	a,#0xff
      0006BC 92 00            [24] 1634 	mov	b0,c
      0006BE 40 33            [24] 1635 	jc	00106$
      0006C0 E5 1D            [12] 1636 	mov	a,_bp
      0006C2 24 F5            [12] 1637 	add	a,#0xf5
      0006C4 F8               [12] 1638 	mov	r0,a
      0006C5 E6               [12] 1639 	mov	a,@r0
      0006C6 60 0F            [24] 1640 	jz	00115$
      0006C8 A8 1D            [24] 1641 	mov	r0,_bp
      0006CA 08               [12] 1642 	inc	r0
      0006CB E4               [12] 1643 	clr	a
      0006CC F6               [12] 1644 	mov	@r0,a
      0006CD 08               [12] 1645 	inc	r0
      0006CE F6               [12] 1646 	mov	@r0,a
      0006CF 08               [12] 1647 	inc	r0
      0006D0 76 80            [12] 1648 	mov	@r0,#0x80
      0006D2 08               [12] 1649 	inc	r0
      0006D3 76 3F            [12] 1650 	mov	@r0,#0x3f
      0006D5 80 0B            [24] 1651 	sjmp	00116$
      0006D7                       1652 00115$:
      0006D7 A8 1D            [24] 1653 	mov	r0,_bp
      0006D9 08               [12] 1654 	inc	r0
      0006DA E4               [12] 1655 	clr	a
      0006DB F6               [12] 1656 	mov	@r0,a
      0006DC 08               [12] 1657 	inc	r0
      0006DD F6               [12] 1658 	mov	@r0,a
      0006DE 08               [12] 1659 	inc	r0
      0006DF F6               [12] 1660 	mov	@r0,a
      0006E0 08               [12] 1661 	inc	r0
      0006E1 F6               [12] 1662 	mov	@r0,a
      0006E2                       1663 00116$:
      0006E2 A8 1D            [24] 1664 	mov	r0,_bp
      0006E4 08               [12] 1665 	inc	r0
      0006E5 86 07            [24] 1666 	mov	ar7,@r0
      0006E7 08               [12] 1667 	inc	r0
      0006E8 86 06            [24] 1668 	mov	ar6,@r0
      0006EA 08               [12] 1669 	inc	r0
      0006EB 86 05            [24] 1670 	mov	ar5,@r0
      0006ED 08               [12] 1671 	inc	r0
      0006EE 86 04            [24] 1672 	mov	ar4,@r0
      0006F0 02 07 94         [24] 1673 	ljmp	00110$
      0006F3                       1674 00106$:
      0006F3 C0 07            [24] 1675 	push	ar7
      0006F5 C0 06            [24] 1676 	push	ar6
      0006F7 C0 05            [24] 1677 	push	ar5
      0006F9 C0 04            [24] 1678 	push	ar4
      0006FB C0 07            [24] 1679 	push	ar7
      0006FD C0 06            [24] 1680 	push	ar6
      0006FF C0 05            [24] 1681 	push	ar5
      000701 C0 04            [24] 1682 	push	ar4
      000703 E5 1D            [12] 1683 	mov	a,_bp
      000705 24 F6            [12] 1684 	add	a,#0xf6
      000707 F8               [12] 1685 	mov	r0,a
      000708 86 82            [24] 1686 	mov	dpl, @r0
      00070A 08               [12] 1687 	inc	r0
      00070B 86 83            [24] 1688 	mov	dph, @r0
      00070D 08               [12] 1689 	inc	r0
      00070E 86 F0            [24] 1690 	mov	b, @r0
      000710 08               [12] 1691 	inc	r0
      000711 E6               [12] 1692 	mov	a, @r0
      000712 12 1C B7         [24] 1693 	lcall	___fssub
      000715 A8 1D            [24] 1694 	mov	r0,_bp
      000717 08               [12] 1695 	inc	r0
      000718 A6 82            [24] 1696 	mov	@r0, dpl
      00071A 08               [12] 1697 	inc	r0
      00071B A6 83            [24] 1698 	mov	@r0, dph
      00071D 08               [12] 1699 	inc	r0
      00071E A6 F0            [24] 1700 	mov	@r0, b
      000720 08               [12] 1701 	inc	r0
      000721 F6               [12] 1702 	mov	@r0,a
      000722 E5 81            [12] 1703 	mov	a,sp
      000724 24 FC            [12] 1704 	add	a,#0xfc
      000726 F5 81            [12] 1705 	mov	sp,a
      000728 E5 1D            [12] 1706 	mov	a,_bp
      00072A 24 FA            [12] 1707 	add	a,#0xfa
      00072C F8               [12] 1708 	mov	r0,a
      00072D 86 82            [24] 1709 	mov	dpl, @r0
      00072F 08               [12] 1710 	inc	r0
      000730 86 83            [24] 1711 	mov	dph, @r0
      000732 08               [12] 1712 	inc	r0
      000733 86 F0            [24] 1713 	mov	b, @r0
      000735 08               [12] 1714 	inc	r0
      000736 E6               [12] 1715 	mov	a, @r0
      000737 12 1C B7         [24] 1716 	lcall	___fssub
      00073A AC 82            [24] 1717 	mov	r4, dpl
      00073C AD 83            [24] 1718 	mov	r5, dph
      00073E AE F0            [24] 1719 	mov	r6, b
      000740 FF               [12] 1720 	mov	r7, a
      000741 E5 81            [12] 1721 	mov	a,sp
      000743 24 FC            [12] 1722 	add	a,#0xfc
      000745 F5 81            [12] 1723 	mov	sp,a
      000747 C0 04            [24] 1724 	push	ar4
      000749 C0 05            [24] 1725 	push	ar5
      00074B C0 06            [24] 1726 	push	ar6
      00074D C0 07            [24] 1727 	push	ar7
      00074F A8 1D            [24] 1728 	mov	r0,_bp
      000751 08               [12] 1729 	inc	r0
      000752 86 82            [24] 1730 	mov	dpl, @r0
      000754 08               [12] 1731 	inc	r0
      000755 86 83            [24] 1732 	mov	dph, @r0
      000757 08               [12] 1733 	inc	r0
      000758 86 F0            [24] 1734 	mov	b, @r0
      00075A 08               [12] 1735 	inc	r0
      00075B E6               [12] 1736 	mov	a, @r0
      00075C 12 1F 39         [24] 1737 	lcall	___fsdiv
      00075F AF 82            [24] 1738 	mov	r7, dpl
      000761 AE 83            [24] 1739 	mov	r6, dph
      000763 AD F0            [24] 1740 	mov	r5, b
      000765 FC               [12] 1741 	mov	r4, a
      000766 E5 81            [12] 1742 	mov	a,sp
      000768 24 FC            [12] 1743 	add	a,#0xfc
      00076A F5 81            [12] 1744 	mov	sp,a
      00076C E5 1D            [12] 1745 	mov	a,_bp
      00076E 24 F5            [12] 1746 	add	a,#0xf5
      000770 F8               [12] 1747 	mov	r0,a
      000771 E6               [12] 1748 	mov	a,@r0
      000772 70 20            [24] 1749 	jnz	00110$
      000774 C0 07            [24] 1750 	push	ar7
      000776 C0 06            [24] 1751 	push	ar6
      000778 C0 05            [24] 1752 	push	ar5
      00077A C0 04            [24] 1753 	push	ar4
      00077C 90 00 00         [24] 1754 	mov	dptr,#0x0000
      00077F 75 F0 80         [24] 1755 	mov	b, #0x80
      000782 74 3F            [12] 1756 	mov	a, #0x3f
      000784 12 1C B7         [24] 1757 	lcall	___fssub
      000787 AF 82            [24] 1758 	mov	r7, dpl
      000789 AE 83            [24] 1759 	mov	r6, dph
      00078B AD F0            [24] 1760 	mov	r5, b
      00078D FC               [12] 1761 	mov	r4, a
      00078E E5 81            [12] 1762 	mov	a,sp
      000790 24 FC            [12] 1763 	add	a,#0xfc
      000792 F5 81            [12] 1764 	mov	sp,a
      000794                       1765 00110$:
      000794 E5 1D            [12] 1766 	mov	a,_bp
      000796 24 F4            [12] 1767 	add	a,#0xf4
      000798 F8               [12] 1768 	mov	r0,a
      000799 E6               [12] 1769 	mov	a,@r0
      00079A C0 E0            [24] 1770 	push	acc
      00079C 8F 82            [24] 1771 	mov	dpl, r7
      00079E 8E 83            [24] 1772 	mov	dph, r6
      0007A0 8D F0            [24] 1773 	mov	b, r5
      0007A2 EC               [12] 1774 	mov	a, r4
      0007A3 12 04 F4         [24] 1775 	lcall	_fuzzy_8051_hedge
      0007A6 AC 82            [24] 1776 	mov	r4, dpl
      0007A8 AD 83            [24] 1777 	mov	r5, dph
      0007AA AE F0            [24] 1778 	mov	r6, b
      0007AC FF               [12] 1779 	mov	r7, a
      0007AD 15 81            [12] 1780 	dec	sp
      0007AF 8C 82            [24] 1781 	mov	dpl, r4
      0007B1 8D 83            [24] 1782 	mov	dph, r5
      0007B3 8E F0            [24] 1783 	mov	b, r6
      0007B5 EF               [12] 1784 	mov	a, r7
      0007B6                       1785 00111$:
      0007B6 85 1D 81         [24] 1786 	mov	sp,_bp
      0007B9 D0 1D            [24] 1787 	pop	_bp
                           000704  1788 	C$fuzzy.h$69$1_0$28 ==.
                           000704  1789 	XG$fuzzy_ramp$0$0 ==.
      0007BB 22               [24] 1790 	ret
                                   1791 ;------------------------------------------------------------
                                   1792 ;Allocation info for local variables in function 'fuzzy_triangle'
                                   1793 ;------------------------------------------------------------
                                   1794 ;b             Allocated to stack - _bp -6 +4 
                                   1795 ;c             Allocated to stack - _bp -10 +4 
                                   1796 ;x             Allocated to stack - _bp -14 +4 
                                   1797 ;hedge         Allocated to stack - _bp -15 +1 
                                   1798 ;a             Allocated to registers r7 r6 r5 r4 
                                   1799 ;result        Allocated to stack - _bp +1 +4 
                                   1800 ;sloc0         Allocated to stack - _bp +1 +4 
                                   1801 ;sloc1         Allocated to stack - _bp +5 +4 
                                   1802 ;------------------------------------------------------------
                           000705  1803 	G$fuzzy_triangle$0$0 ==.
                           000705  1804 	C$fuzzy.h$70$1_0$31 ==.
                                   1805 ;	../../fuzzy.h:70: float fuzzy_triangle(float a, float b, float c, float x, fuzzy_hedge_t hedge) { float result; if (a >= b || b >= c || x <= a || x >= c) result = 0.0f; else if (x == b) result = 1.0f; else if (x < b) result = (x - a) / (b - a); else result = (c - x) / (c - b); return fuzzy_8051_hedge(result, hedge); }
                                   1806 ;	-----------------------------------------
                                   1807 ;	 function fuzzy_triangle
                                   1808 ;	-----------------------------------------
      0007BC                       1809 _fuzzy_triangle:
      0007BC C0 1D            [24] 1810 	push	_bp
      0007BE 85 81 1D         [24] 1811 	mov	_bp,sp
      0007C1 AF 82            [24] 1812 	mov	r7,dpl
      0007C3 AE 83            [24] 1813 	mov	r6,dph
      0007C5 AD F0            [24] 1814 	mov	r5,b
      0007C7 FC               [12] 1815 	mov	r4,a
      0007C8 E5 81            [12] 1816 	mov	a,sp
      0007CA 24 08            [12] 1817 	add	a,#0x08
      0007CC F5 81            [12] 1818 	mov	sp,a
      0007CE C0 07            [24] 1819 	push	ar7
      0007D0 C0 06            [24] 1820 	push	ar6
      0007D2 C0 05            [24] 1821 	push	ar5
      0007D4 C0 04            [24] 1822 	push	ar4
      0007D6 E5 1D            [12] 1823 	mov	a,_bp
      0007D8 24 FA            [12] 1824 	add	a,#0xfa
      0007DA F8               [12] 1825 	mov	r0,a
      0007DB E6               [12] 1826 	mov	a,@r0
      0007DC C0 E0            [24] 1827 	push	acc
      0007DE 08               [12] 1828 	inc	r0
      0007DF E6               [12] 1829 	mov	a,@r0
      0007E0 C0 E0            [24] 1830 	push	acc
      0007E2 08               [12] 1831 	inc	r0
      0007E3 E6               [12] 1832 	mov	a,@r0
      0007E4 C0 E0            [24] 1833 	push	acc
      0007E6 08               [12] 1834 	inc	r0
      0007E7 E6               [12] 1835 	mov	a,@r0
      0007E8 C0 E0            [24] 1836 	push	acc
      0007EA 8F 82            [24] 1837 	mov	dpl, r7
      0007EC 8E 83            [24] 1838 	mov	dph, r6
      0007EE 8D F0            [24] 1839 	mov	b, r5
      0007F0 EC               [12] 1840 	mov	a, r4
      0007F1 12 1D F2         [24] 1841 	lcall	___fslt
      0007F4 E5 81            [12] 1842 	mov	a,sp
      0007F6 24 FC            [12] 1843 	add	a,#0xfc
      0007F8 F5 81            [12] 1844 	mov	sp,a
      0007FA D0 04            [24] 1845 	pop	ar4
      0007FC D0 05            [24] 1846 	pop	ar5
      0007FE D0 06            [24] 1847 	pop	ar6
      000800 D0 07            [24] 1848 	pop	ar7
      000802 E5 82            [12] 1849 	mov	a, dpl
      000804 24 FF            [12] 1850 	add	a,#0xff
      000806 92 00            [24] 1851 	mov	b0,c
      000808 40 03            [24] 1852 	jc	00145$
      00080A 02 08 D4         [24] 1853 	ljmp	00107$
      00080D                       1854 00145$:
      00080D C0 07            [24] 1855 	push	ar7
      00080F C0 06            [24] 1856 	push	ar6
      000811 C0 05            [24] 1857 	push	ar5
      000813 C0 04            [24] 1858 	push	ar4
      000815 E5 1D            [12] 1859 	mov	a,_bp
      000817 24 F6            [12] 1860 	add	a,#0xf6
      000819 F8               [12] 1861 	mov	r0,a
      00081A E6               [12] 1862 	mov	a,@r0
      00081B C0 E0            [24] 1863 	push	acc
      00081D 08               [12] 1864 	inc	r0
      00081E E6               [12] 1865 	mov	a,@r0
      00081F C0 E0            [24] 1866 	push	acc
      000821 08               [12] 1867 	inc	r0
      000822 E6               [12] 1868 	mov	a,@r0
      000823 C0 E0            [24] 1869 	push	acc
      000825 08               [12] 1870 	inc	r0
      000826 E6               [12] 1871 	mov	a,@r0
      000827 C0 E0            [24] 1872 	push	acc
      000829 E5 1D            [12] 1873 	mov	a,_bp
      00082B 24 FA            [12] 1874 	add	a,#0xfa
      00082D F8               [12] 1875 	mov	r0,a
      00082E 86 82            [24] 1876 	mov	dpl, @r0
      000830 08               [12] 1877 	inc	r0
      000831 86 83            [24] 1878 	mov	dph, @r0
      000833 08               [12] 1879 	inc	r0
      000834 86 F0            [24] 1880 	mov	b, @r0
      000836 08               [12] 1881 	inc	r0
      000837 E6               [12] 1882 	mov	a, @r0
      000838 12 1D F2         [24] 1883 	lcall	___fslt
      00083B E5 81            [12] 1884 	mov	a,sp
      00083D 24 FC            [12] 1885 	add	a,#0xfc
      00083F F5 81            [12] 1886 	mov	sp,a
      000841 D0 04            [24] 1887 	pop	ar4
      000843 D0 05            [24] 1888 	pop	ar5
      000845 D0 06            [24] 1889 	pop	ar6
      000847 D0 07            [24] 1890 	pop	ar7
      000849 E5 82            [12] 1891 	mov	a, dpl
      00084B 24 FF            [12] 1892 	add	a,#0xff
      00084D 92 00            [24] 1893 	mov	b0,c
      00084F 40 03            [24] 1894 	jc	00146$
      000851 02 08 D4         [24] 1895 	ljmp	00107$
      000854                       1896 00146$:
      000854 C0 07            [24] 1897 	push	ar7
      000856 C0 06            [24] 1898 	push	ar6
      000858 C0 05            [24] 1899 	push	ar5
      00085A C0 04            [24] 1900 	push	ar4
      00085C E5 1D            [12] 1901 	mov	a,_bp
      00085E 24 F2            [12] 1902 	add	a,#0xf2
      000860 F8               [12] 1903 	mov	r0,a
      000861 E6               [12] 1904 	mov	a,@r0
      000862 C0 E0            [24] 1905 	push	acc
      000864 08               [12] 1906 	inc	r0
      000865 E6               [12] 1907 	mov	a,@r0
      000866 C0 E0            [24] 1908 	push	acc
      000868 08               [12] 1909 	inc	r0
      000869 E6               [12] 1910 	mov	a,@r0
      00086A C0 E0            [24] 1911 	push	acc
      00086C 08               [12] 1912 	inc	r0
      00086D E6               [12] 1913 	mov	a,@r0
      00086E C0 E0            [24] 1914 	push	acc
      000870 8F 82            [24] 1915 	mov	dpl, r7
      000872 8E 83            [24] 1916 	mov	dph, r6
      000874 8D F0            [24] 1917 	mov	b, r5
      000876 EC               [12] 1918 	mov	a, r4
      000877 12 1D F2         [24] 1919 	lcall	___fslt
      00087A E5 81            [12] 1920 	mov	a,sp
      00087C 24 FC            [12] 1921 	add	a,#0xfc
      00087E F5 81            [12] 1922 	mov	sp,a
      000880 D0 04            [24] 1923 	pop	ar4
      000882 D0 05            [24] 1924 	pop	ar5
      000884 D0 06            [24] 1925 	pop	ar6
      000886 D0 07            [24] 1926 	pop	ar7
      000888 E5 82            [12] 1927 	mov	a, dpl
      00088A 24 FF            [12] 1928 	add	a,#0xff
      00088C 92 00            [24] 1929 	mov	b0,c
      00088E 50 44            [24] 1930 	jnc	00107$
      000890 C0 07            [24] 1931 	push	ar7
      000892 C0 06            [24] 1932 	push	ar6
      000894 C0 05            [24] 1933 	push	ar5
      000896 C0 04            [24] 1934 	push	ar4
      000898 E5 1D            [12] 1935 	mov	a,_bp
      00089A 24 F6            [12] 1936 	add	a,#0xf6
      00089C F8               [12] 1937 	mov	r0,a
      00089D E6               [12] 1938 	mov	a,@r0
      00089E C0 E0            [24] 1939 	push	acc
      0008A0 08               [12] 1940 	inc	r0
      0008A1 E6               [12] 1941 	mov	a,@r0
      0008A2 C0 E0            [24] 1942 	push	acc
      0008A4 08               [12] 1943 	inc	r0
      0008A5 E6               [12] 1944 	mov	a,@r0
      0008A6 C0 E0            [24] 1945 	push	acc
      0008A8 08               [12] 1946 	inc	r0
      0008A9 E6               [12] 1947 	mov	a,@r0
      0008AA C0 E0            [24] 1948 	push	acc
      0008AC E5 1D            [12] 1949 	mov	a,_bp
      0008AE 24 F2            [12] 1950 	add	a,#0xf2
      0008B0 F8               [12] 1951 	mov	r0,a
      0008B1 86 82            [24] 1952 	mov	dpl, @r0
      0008B3 08               [12] 1953 	inc	r0
      0008B4 86 83            [24] 1954 	mov	dph, @r0
      0008B6 08               [12] 1955 	inc	r0
      0008B7 86 F0            [24] 1956 	mov	b, @r0
      0008B9 08               [12] 1957 	inc	r0
      0008BA E6               [12] 1958 	mov	a, @r0
      0008BB 12 1D F2         [24] 1959 	lcall	___fslt
      0008BE E5 81            [12] 1960 	mov	a,sp
      0008C0 24 FC            [12] 1961 	add	a,#0xfc
      0008C2 F5 81            [12] 1962 	mov	sp,a
      0008C4 D0 04            [24] 1963 	pop	ar4
      0008C6 D0 05            [24] 1964 	pop	ar5
      0008C8 D0 06            [24] 1965 	pop	ar6
      0008CA D0 07            [24] 1966 	pop	ar7
      0008CC E5 82            [12] 1967 	mov	a, dpl
      0008CE 24 FF            [12] 1968 	add	a,#0xff
      0008D0 92 00            [24] 1969 	mov	b0,c
      0008D2 40 0E            [24] 1970 	jc	00108$
      0008D4                       1971 00107$:
      0008D4 A8 1D            [24] 1972 	mov	r0,_bp
      0008D6 08               [12] 1973 	inc	r0
      0008D7 E4               [12] 1974 	clr	a
      0008D8 F6               [12] 1975 	mov	@r0,a
      0008D9 08               [12] 1976 	inc	r0
      0008DA F6               [12] 1977 	mov	@r0,a
      0008DB 08               [12] 1978 	inc	r0
      0008DC F6               [12] 1979 	mov	@r0,a
      0008DD 08               [12] 1980 	inc	r0
      0008DE F6               [12] 1981 	mov	@r0,a
      0008DF 02 0A 9A         [24] 1982 	ljmp	00109$
      0008E2                       1983 00108$:
      0008E2 C0 07            [24] 1984 	push	ar7
      0008E4 C0 06            [24] 1985 	push	ar6
      0008E6 C0 05            [24] 1986 	push	ar5
      0008E8 C0 04            [24] 1987 	push	ar4
      0008EA E5 1D            [12] 1988 	mov	a,_bp
      0008EC 24 FA            [12] 1989 	add	a,#0xfa
      0008EE F8               [12] 1990 	mov	r0,a
      0008EF E6               [12] 1991 	mov	a,@r0
      0008F0 C0 E0            [24] 1992 	push	acc
      0008F2 08               [12] 1993 	inc	r0
      0008F3 E6               [12] 1994 	mov	a,@r0
      0008F4 C0 E0            [24] 1995 	push	acc
      0008F6 08               [12] 1996 	inc	r0
      0008F7 E6               [12] 1997 	mov	a,@r0
      0008F8 C0 E0            [24] 1998 	push	acc
      0008FA 08               [12] 1999 	inc	r0
      0008FB E6               [12] 2000 	mov	a,@r0
      0008FC C0 E0            [24] 2001 	push	acc
      0008FE E5 1D            [12] 2002 	mov	a,_bp
      000900 24 F2            [12] 2003 	add	a,#0xf2
      000902 F8               [12] 2004 	mov	r0,a
      000903 86 82            [24] 2005 	mov	dpl, @r0
      000905 08               [12] 2006 	inc	r0
      000906 86 83            [24] 2007 	mov	dph, @r0
      000908 08               [12] 2008 	inc	r0
      000909 86 F0            [24] 2009 	mov	b, @r0
      00090B 08               [12] 2010 	inc	r0
      00090C E6               [12] 2011 	mov	a, @r0
      00090D 12 1D C6         [24] 2012 	lcall	___fseq
      000910 AB 82            [24] 2013 	mov	r3, dpl
      000912 E5 81            [12] 2014 	mov	a,sp
      000914 24 FC            [12] 2015 	add	a,#0xfc
      000916 F5 81            [12] 2016 	mov	sp,a
      000918 D0 04            [24] 2017 	pop	ar4
      00091A D0 05            [24] 2018 	pop	ar5
      00091C D0 06            [24] 2019 	pop	ar6
      00091E D0 07            [24] 2020 	pop	ar7
      000920 EB               [12] 2021 	mov	a,r3
      000921 60 10            [24] 2022 	jz	00105$
      000923 A8 1D            [24] 2023 	mov	r0,_bp
      000925 08               [12] 2024 	inc	r0
      000926 E4               [12] 2025 	clr	a
      000927 F6               [12] 2026 	mov	@r0,a
      000928 08               [12] 2027 	inc	r0
      000929 F6               [12] 2028 	mov	@r0,a
      00092A 08               [12] 2029 	inc	r0
      00092B 76 80            [12] 2030 	mov	@r0,#0x80
      00092D 08               [12] 2031 	inc	r0
      00092E 76 3F            [12] 2032 	mov	@r0,#0x3f
      000930 02 0A 9A         [24] 2033 	ljmp	00109$
      000933                       2034 00105$:
      000933 C0 07            [24] 2035 	push	ar7
      000935 C0 06            [24] 2036 	push	ar6
      000937 C0 05            [24] 2037 	push	ar5
      000939 C0 04            [24] 2038 	push	ar4
      00093B E5 1D            [12] 2039 	mov	a,_bp
      00093D 24 FA            [12] 2040 	add	a,#0xfa
      00093F F8               [12] 2041 	mov	r0,a
      000940 E6               [12] 2042 	mov	a,@r0
      000941 C0 E0            [24] 2043 	push	acc
      000943 08               [12] 2044 	inc	r0
      000944 E6               [12] 2045 	mov	a,@r0
      000945 C0 E0            [24] 2046 	push	acc
      000947 08               [12] 2047 	inc	r0
      000948 E6               [12] 2048 	mov	a,@r0
      000949 C0 E0            [24] 2049 	push	acc
      00094B 08               [12] 2050 	inc	r0
      00094C E6               [12] 2051 	mov	a,@r0
      00094D C0 E0            [24] 2052 	push	acc
      00094F E5 1D            [12] 2053 	mov	a,_bp
      000951 24 F2            [12] 2054 	add	a,#0xf2
      000953 F8               [12] 2055 	mov	r0,a
      000954 86 82            [24] 2056 	mov	dpl, @r0
      000956 08               [12] 2057 	inc	r0
      000957 86 83            [24] 2058 	mov	dph, @r0
      000959 08               [12] 2059 	inc	r0
      00095A 86 F0            [24] 2060 	mov	b, @r0
      00095C 08               [12] 2061 	inc	r0
      00095D E6               [12] 2062 	mov	a, @r0
      00095E 12 1D F2         [24] 2063 	lcall	___fslt
      000961 AB 82            [24] 2064 	mov	r3, dpl
      000963 E5 81            [12] 2065 	mov	a,sp
      000965 24 FC            [12] 2066 	add	a,#0xfc
      000967 F5 81            [12] 2067 	mov	sp,a
      000969 D0 04            [24] 2068 	pop	ar4
      00096B D0 05            [24] 2069 	pop	ar5
      00096D D0 06            [24] 2070 	pop	ar6
      00096F D0 07            [24] 2071 	pop	ar7
      000971 EB               [12] 2072 	mov	a,r3
      000972 70 03            [24] 2073 	jnz	00150$
      000974 02 09 FE         [24] 2074 	ljmp	00102$
      000977                       2075 00150$:
      000977 C0 07            [24] 2076 	push	ar7
      000979 C0 06            [24] 2077 	push	ar6
      00097B C0 05            [24] 2078 	push	ar5
      00097D C0 04            [24] 2079 	push	ar4
      00097F C0 07            [24] 2080 	push	ar7
      000981 C0 06            [24] 2081 	push	ar6
      000983 C0 05            [24] 2082 	push	ar5
      000985 C0 04            [24] 2083 	push	ar4
      000987 E5 1D            [12] 2084 	mov	a,_bp
      000989 24 F2            [12] 2085 	add	a,#0xf2
      00098B F8               [12] 2086 	mov	r0,a
      00098C 86 82            [24] 2087 	mov	dpl, @r0
      00098E 08               [12] 2088 	inc	r0
      00098F 86 83            [24] 2089 	mov	dph, @r0
      000991 08               [12] 2090 	inc	r0
      000992 86 F0            [24] 2091 	mov	b, @r0
      000994 08               [12] 2092 	inc	r0
      000995 E6               [12] 2093 	mov	a, @r0
      000996 12 1C B7         [24] 2094 	lcall	___fssub
      000999 C8               [12] 2095 	xch	a,r0
      00099A E5 1D            [12] 2096 	mov	a,_bp
      00099C 24 05            [12] 2097 	add	a,#0x05
      00099E C8               [12] 2098 	xch	a,r0
      00099F A6 82            [24] 2099 	mov	@r0, dpl
      0009A1 08               [12] 2100 	inc	r0
      0009A2 A6 83            [24] 2101 	mov	@r0, dph
      0009A4 08               [12] 2102 	inc	r0
      0009A5 A6 F0            [24] 2103 	mov	@r0, b
      0009A7 08               [12] 2104 	inc	r0
      0009A8 F6               [12] 2105 	mov	@r0,a
      0009A9 E5 81            [12] 2106 	mov	a,sp
      0009AB 24 FC            [12] 2107 	add	a,#0xfc
      0009AD F5 81            [12] 2108 	mov	sp,a
      0009AF E5 1D            [12] 2109 	mov	a,_bp
      0009B1 24 FA            [12] 2110 	add	a,#0xfa
      0009B3 F8               [12] 2111 	mov	r0,a
      0009B4 86 82            [24] 2112 	mov	dpl, @r0
      0009B6 08               [12] 2113 	inc	r0
      0009B7 86 83            [24] 2114 	mov	dph, @r0
      0009B9 08               [12] 2115 	inc	r0
      0009BA 86 F0            [24] 2116 	mov	b, @r0
      0009BC 08               [12] 2117 	inc	r0
      0009BD E6               [12] 2118 	mov	a, @r0
      0009BE 12 1C B7         [24] 2119 	lcall	___fssub
      0009C1 AC 82            [24] 2120 	mov	r4, dpl
      0009C3 AD 83            [24] 2121 	mov	r5, dph
      0009C5 AE F0            [24] 2122 	mov	r6, b
      0009C7 FF               [12] 2123 	mov	r7, a
      0009C8 E5 81            [12] 2124 	mov	a,sp
      0009CA 24 FC            [12] 2125 	add	a,#0xfc
      0009CC F5 81            [12] 2126 	mov	sp,a
      0009CE C0 04            [24] 2127 	push	ar4
      0009D0 C0 05            [24] 2128 	push	ar5
      0009D2 C0 06            [24] 2129 	push	ar6
      0009D4 C0 07            [24] 2130 	push	ar7
      0009D6 E5 1D            [12] 2131 	mov	a,_bp
      0009D8 24 05            [12] 2132 	add	a,#0x05
      0009DA F8               [12] 2133 	mov	r0,a
      0009DB 86 82            [24] 2134 	mov	dpl, @r0
      0009DD 08               [12] 2135 	inc	r0
      0009DE 86 83            [24] 2136 	mov	dph, @r0
      0009E0 08               [12] 2137 	inc	r0
      0009E1 86 F0            [24] 2138 	mov	b, @r0
      0009E3 08               [12] 2139 	inc	r0
      0009E4 E6               [12] 2140 	mov	a, @r0
      0009E5 12 1F 39         [24] 2141 	lcall	___fsdiv
      0009E8 A8 1D            [24] 2142 	mov	r0,_bp
      0009EA 08               [12] 2143 	inc	r0
      0009EB A6 82            [24] 2144 	mov	@r0, dpl
      0009ED 08               [12] 2145 	inc	r0
      0009EE A6 83            [24] 2146 	mov	@r0, dph
      0009F0 08               [12] 2147 	inc	r0
      0009F1 A6 F0            [24] 2148 	mov	@r0, b
      0009F3 08               [12] 2149 	inc	r0
      0009F4 F6               [12] 2150 	mov	@r0,a
      0009F5 E5 81            [12] 2151 	mov	a,sp
      0009F7 24 FC            [12] 2152 	add	a,#0xfc
      0009F9 F5 81            [12] 2153 	mov	sp,a
      0009FB 02 0A 9A         [24] 2154 	ljmp	00109$
      0009FE                       2155 00102$:
      0009FE E5 1D            [12] 2156 	mov	a,_bp
      000A00 24 F2            [12] 2157 	add	a,#0xf2
      000A02 F8               [12] 2158 	mov	r0,a
      000A03 E6               [12] 2159 	mov	a,@r0
      000A04 C0 E0            [24] 2160 	push	acc
      000A06 08               [12] 2161 	inc	r0
      000A07 E6               [12] 2162 	mov	a,@r0
      000A08 C0 E0            [24] 2163 	push	acc
      000A0A 08               [12] 2164 	inc	r0
      000A0B E6               [12] 2165 	mov	a,@r0
      000A0C C0 E0            [24] 2166 	push	acc
      000A0E 08               [12] 2167 	inc	r0
      000A0F E6               [12] 2168 	mov	a,@r0
      000A10 C0 E0            [24] 2169 	push	acc
      000A12 E5 1D            [12] 2170 	mov	a,_bp
      000A14 24 F6            [12] 2171 	add	a,#0xf6
      000A16 F8               [12] 2172 	mov	r0,a
      000A17 86 82            [24] 2173 	mov	dpl, @r0
      000A19 08               [12] 2174 	inc	r0
      000A1A 86 83            [24] 2175 	mov	dph, @r0
      000A1C 08               [12] 2176 	inc	r0
      000A1D 86 F0            [24] 2177 	mov	b, @r0
      000A1F 08               [12] 2178 	inc	r0
      000A20 E6               [12] 2179 	mov	a, @r0
      000A21 12 1C B7         [24] 2180 	lcall	___fssub
      000A24 C8               [12] 2181 	xch	a,r0
      000A25 E5 1D            [12] 2182 	mov	a,_bp
      000A27 24 05            [12] 2183 	add	a,#0x05
      000A29 C8               [12] 2184 	xch	a,r0
      000A2A A6 82            [24] 2185 	mov	@r0, dpl
      000A2C 08               [12] 2186 	inc	r0
      000A2D A6 83            [24] 2187 	mov	@r0, dph
      000A2F 08               [12] 2188 	inc	r0
      000A30 A6 F0            [24] 2189 	mov	@r0, b
      000A32 08               [12] 2190 	inc	r0
      000A33 F6               [12] 2191 	mov	@r0,a
      000A34 E5 81            [12] 2192 	mov	a,sp
      000A36 24 FC            [12] 2193 	add	a,#0xfc
      000A38 F5 81            [12] 2194 	mov	sp,a
      000A3A E5 1D            [12] 2195 	mov	a,_bp
      000A3C 24 FA            [12] 2196 	add	a,#0xfa
      000A3E F8               [12] 2197 	mov	r0,a
      000A3F E6               [12] 2198 	mov	a,@r0
      000A40 C0 E0            [24] 2199 	push	acc
      000A42 08               [12] 2200 	inc	r0
      000A43 E6               [12] 2201 	mov	a,@r0
      000A44 C0 E0            [24] 2202 	push	acc
      000A46 08               [12] 2203 	inc	r0
      000A47 E6               [12] 2204 	mov	a,@r0
      000A48 C0 E0            [24] 2205 	push	acc
      000A4A 08               [12] 2206 	inc	r0
      000A4B E6               [12] 2207 	mov	a,@r0
      000A4C C0 E0            [24] 2208 	push	acc
      000A4E E5 1D            [12] 2209 	mov	a,_bp
      000A50 24 F6            [12] 2210 	add	a,#0xf6
      000A52 F8               [12] 2211 	mov	r0,a
      000A53 86 82            [24] 2212 	mov	dpl, @r0
      000A55 08               [12] 2213 	inc	r0
      000A56 86 83            [24] 2214 	mov	dph, @r0
      000A58 08               [12] 2215 	inc	r0
      000A59 86 F0            [24] 2216 	mov	b, @r0
      000A5B 08               [12] 2217 	inc	r0
      000A5C E6               [12] 2218 	mov	a, @r0
      000A5D 12 1C B7         [24] 2219 	lcall	___fssub
      000A60 AA 82            [24] 2220 	mov	r2, dpl
      000A62 AB 83            [24] 2221 	mov	r3, dph
      000A64 AE F0            [24] 2222 	mov	r6, b
      000A66 FF               [12] 2223 	mov	r7, a
      000A67 E5 81            [12] 2224 	mov	a,sp
      000A69 24 FC            [12] 2225 	add	a,#0xfc
      000A6B F5 81            [12] 2226 	mov	sp,a
      000A6D C0 02            [24] 2227 	push	ar2
      000A6F C0 03            [24] 2228 	push	ar3
      000A71 C0 06            [24] 2229 	push	ar6
      000A73 C0 07            [24] 2230 	push	ar7
      000A75 E5 1D            [12] 2231 	mov	a,_bp
      000A77 24 05            [12] 2232 	add	a,#0x05
      000A79 F8               [12] 2233 	mov	r0,a
      000A7A 86 82            [24] 2234 	mov	dpl, @r0
      000A7C 08               [12] 2235 	inc	r0
      000A7D 86 83            [24] 2236 	mov	dph, @r0
      000A7F 08               [12] 2237 	inc	r0
      000A80 86 F0            [24] 2238 	mov	b, @r0
      000A82 08               [12] 2239 	inc	r0
      000A83 E6               [12] 2240 	mov	a, @r0
      000A84 12 1F 39         [24] 2241 	lcall	___fsdiv
      000A87 A8 1D            [24] 2242 	mov	r0,_bp
      000A89 08               [12] 2243 	inc	r0
      000A8A A6 82            [24] 2244 	mov	@r0, dpl
      000A8C 08               [12] 2245 	inc	r0
      000A8D A6 83            [24] 2246 	mov	@r0, dph
      000A8F 08               [12] 2247 	inc	r0
      000A90 A6 F0            [24] 2248 	mov	@r0, b
      000A92 08               [12] 2249 	inc	r0
      000A93 F6               [12] 2250 	mov	@r0,a
      000A94 E5 81            [12] 2251 	mov	a,sp
      000A96 24 FC            [12] 2252 	add	a,#0xfc
      000A98 F5 81            [12] 2253 	mov	sp,a
      000A9A                       2254 00109$:
      000A9A E5 1D            [12] 2255 	mov	a,_bp
      000A9C 24 F1            [12] 2256 	add	a,#0xf1
      000A9E F8               [12] 2257 	mov	r0,a
      000A9F E6               [12] 2258 	mov	a,@r0
      000AA0 C0 E0            [24] 2259 	push	acc
      000AA2 A8 1D            [24] 2260 	mov	r0,_bp
      000AA4 08               [12] 2261 	inc	r0
      000AA5 86 82            [24] 2262 	mov	dpl, @r0
      000AA7 08               [12] 2263 	inc	r0
      000AA8 86 83            [24] 2264 	mov	dph, @r0
      000AAA 08               [12] 2265 	inc	r0
      000AAB 86 F0            [24] 2266 	mov	b, @r0
      000AAD 08               [12] 2267 	inc	r0
      000AAE E6               [12] 2268 	mov	a, @r0
      000AAF 12 04 F4         [24] 2269 	lcall	_fuzzy_8051_hedge
      000AB2 AC 82            [24] 2270 	mov	r4, dpl
      000AB4 AD 83            [24] 2271 	mov	r5, dph
      000AB6 AE F0            [24] 2272 	mov	r6, b
      000AB8 FF               [12] 2273 	mov	r7, a
      000AB9 15 81            [12] 2274 	dec	sp
      000ABB 8C 82            [24] 2275 	mov	dpl, r4
      000ABD 8D 83            [24] 2276 	mov	dph, r5
      000ABF 8E F0            [24] 2277 	mov	b, r6
      000AC1 EF               [12] 2278 	mov	a, r7
      000AC2 85 1D 81         [24] 2279 	mov	sp,_bp
      000AC5 D0 1D            [24] 2280 	pop	_bp
                           000A10  2281 	C$fuzzy.h$70$1_0$31 ==.
                           000A10  2282 	XG$fuzzy_triangle$0$0 ==.
      000AC7 22               [24] 2283 	ret
                                   2284 ;------------------------------------------------------------
                                   2285 ;Allocation info for local variables in function 'fuzzy_trapezoid'
                                   2286 ;------------------------------------------------------------
                                   2287 ;b             Allocated to stack - _bp -6 +4 
                                   2288 ;c             Allocated to stack - _bp -10 +4 
                                   2289 ;d             Allocated to stack - _bp -14 +4 
                                   2290 ;x             Allocated to stack - _bp -18 +4 
                                   2291 ;hedge         Allocated to stack - _bp -19 +1 
                                   2292 ;a             Allocated to registers r7 r6 r5 r4 
                                   2293 ;result        Allocated to stack - _bp +1 +4 
                                   2294 ;sloc0         Allocated to stack - _bp +1 +4 
                                   2295 ;sloc1         Allocated to stack - _bp +5 +4 
                                   2296 ;------------------------------------------------------------
                           000A11  2297 	G$fuzzy_trapezoid$0$0 ==.
                           000A11  2298 	C$fuzzy.h$71$1_0$33 ==.
                                   2299 ;	../../fuzzy.h:71: float fuzzy_trapezoid(float a, float b, float c, float d, float x, fuzzy_hedge_t hedge) { float result; if (a >= b || b > c || c >= d || x <= a || x >= d) result = 0.0f; else if (x >= b && x <= c) result = 1.0f; else if (x < b) result = (x - a) / (b - a); else result = (d - x) / (d - c); return fuzzy_8051_hedge(result, hedge); }
                                   2300 ;	-----------------------------------------
                                   2301 ;	 function fuzzy_trapezoid
                                   2302 ;	-----------------------------------------
      000AC8                       2303 _fuzzy_trapezoid:
      000AC8 C0 1D            [24] 2304 	push	_bp
      000ACA 85 81 1D         [24] 2305 	mov	_bp,sp
      000ACD AF 82            [24] 2306 	mov	r7,dpl
      000ACF AE 83            [24] 2307 	mov	r6,dph
      000AD1 AD F0            [24] 2308 	mov	r5,b
      000AD3 FC               [12] 2309 	mov	r4,a
      000AD4 E5 81            [12] 2310 	mov	a,sp
      000AD6 24 08            [12] 2311 	add	a,#0x08
      000AD8 F5 81            [12] 2312 	mov	sp,a
      000ADA C0 07            [24] 2313 	push	ar7
      000ADC C0 06            [24] 2314 	push	ar6
      000ADE C0 05            [24] 2315 	push	ar5
      000AE0 C0 04            [24] 2316 	push	ar4
      000AE2 E5 1D            [12] 2317 	mov	a,_bp
      000AE4 24 FA            [12] 2318 	add	a,#0xfa
      000AE6 F8               [12] 2319 	mov	r0,a
      000AE7 E6               [12] 2320 	mov	a,@r0
      000AE8 C0 E0            [24] 2321 	push	acc
      000AEA 08               [12] 2322 	inc	r0
      000AEB E6               [12] 2323 	mov	a,@r0
      000AEC C0 E0            [24] 2324 	push	acc
      000AEE 08               [12] 2325 	inc	r0
      000AEF E6               [12] 2326 	mov	a,@r0
      000AF0 C0 E0            [24] 2327 	push	acc
      000AF2 08               [12] 2328 	inc	r0
      000AF3 E6               [12] 2329 	mov	a,@r0
      000AF4 C0 E0            [24] 2330 	push	acc
      000AF6 8F 82            [24] 2331 	mov	dpl, r7
      000AF8 8E 83            [24] 2332 	mov	dph, r6
      000AFA 8D F0            [24] 2333 	mov	b, r5
      000AFC EC               [12] 2334 	mov	a, r4
      000AFD 12 1D F2         [24] 2335 	lcall	___fslt
      000B00 E5 81            [12] 2336 	mov	a,sp
      000B02 24 FC            [12] 2337 	add	a,#0xfc
      000B04 F5 81            [12] 2338 	mov	sp,a
      000B06 D0 04            [24] 2339 	pop	ar4
      000B08 D0 05            [24] 2340 	pop	ar5
      000B0A D0 06            [24] 2341 	pop	ar6
      000B0C D0 07            [24] 2342 	pop	ar7
      000B0E E5 82            [12] 2343 	mov	a, dpl
      000B10 24 FF            [12] 2344 	add	a,#0xff
      000B12 92 00            [24] 2345 	mov	b0,c
      000B14 40 03            [24] 2346 	jc	00159$
      000B16 02 0C 24         [24] 2347 	ljmp	00108$
      000B19                       2348 00159$:
      000B19 C0 07            [24] 2349 	push	ar7
      000B1B C0 06            [24] 2350 	push	ar6
      000B1D C0 05            [24] 2351 	push	ar5
      000B1F C0 04            [24] 2352 	push	ar4
      000B21 E5 1D            [12] 2353 	mov	a,_bp
      000B23 24 FA            [12] 2354 	add	a,#0xfa
      000B25 F8               [12] 2355 	mov	r0,a
      000B26 E6               [12] 2356 	mov	a,@r0
      000B27 C0 E0            [24] 2357 	push	acc
      000B29 08               [12] 2358 	inc	r0
      000B2A E6               [12] 2359 	mov	a,@r0
      000B2B C0 E0            [24] 2360 	push	acc
      000B2D 08               [12] 2361 	inc	r0
      000B2E E6               [12] 2362 	mov	a,@r0
      000B2F C0 E0            [24] 2363 	push	acc
      000B31 08               [12] 2364 	inc	r0
      000B32 E6               [12] 2365 	mov	a,@r0
      000B33 C0 E0            [24] 2366 	push	acc
      000B35 E5 1D            [12] 2367 	mov	a,_bp
      000B37 24 F6            [12] 2368 	add	a,#0xf6
      000B39 F8               [12] 2369 	mov	r0,a
      000B3A 86 82            [24] 2370 	mov	dpl, @r0
      000B3C 08               [12] 2371 	inc	r0
      000B3D 86 83            [24] 2372 	mov	dph, @r0
      000B3F 08               [12] 2373 	inc	r0
      000B40 86 F0            [24] 2374 	mov	b, @r0
      000B42 08               [12] 2375 	inc	r0
      000B43 E6               [12] 2376 	mov	a, @r0
      000B44 12 1D F2         [24] 2377 	lcall	___fslt
      000B47 AB 82            [24] 2378 	mov	r3, dpl
      000B49 E5 81            [12] 2379 	mov	a,sp
      000B4B 24 FC            [12] 2380 	add	a,#0xfc
      000B4D F5 81            [12] 2381 	mov	sp,a
      000B4F D0 04            [24] 2382 	pop	ar4
      000B51 D0 05            [24] 2383 	pop	ar5
      000B53 D0 06            [24] 2384 	pop	ar6
      000B55 D0 07            [24] 2385 	pop	ar7
      000B57 EB               [12] 2386 	mov	a,r3
      000B58 60 03            [24] 2387 	jz	00160$
      000B5A 02 0C 24         [24] 2388 	ljmp	00108$
      000B5D                       2389 00160$:
      000B5D C0 07            [24] 2390 	push	ar7
      000B5F C0 06            [24] 2391 	push	ar6
      000B61 C0 05            [24] 2392 	push	ar5
      000B63 C0 04            [24] 2393 	push	ar4
      000B65 E5 1D            [12] 2394 	mov	a,_bp
      000B67 24 F2            [12] 2395 	add	a,#0xf2
      000B69 F8               [12] 2396 	mov	r0,a
      000B6A E6               [12] 2397 	mov	a,@r0
      000B6B C0 E0            [24] 2398 	push	acc
      000B6D 08               [12] 2399 	inc	r0
      000B6E E6               [12] 2400 	mov	a,@r0
      000B6F C0 E0            [24] 2401 	push	acc
      000B71 08               [12] 2402 	inc	r0
      000B72 E6               [12] 2403 	mov	a,@r0
      000B73 C0 E0            [24] 2404 	push	acc
      000B75 08               [12] 2405 	inc	r0
      000B76 E6               [12] 2406 	mov	a,@r0
      000B77 C0 E0            [24] 2407 	push	acc
      000B79 E5 1D            [12] 2408 	mov	a,_bp
      000B7B 24 F6            [12] 2409 	add	a,#0xf6
      000B7D F8               [12] 2410 	mov	r0,a
      000B7E 86 82            [24] 2411 	mov	dpl, @r0
      000B80 08               [12] 2412 	inc	r0
      000B81 86 83            [24] 2413 	mov	dph, @r0
      000B83 08               [12] 2414 	inc	r0
      000B84 86 F0            [24] 2415 	mov	b, @r0
      000B86 08               [12] 2416 	inc	r0
      000B87 E6               [12] 2417 	mov	a, @r0
      000B88 12 1D F2         [24] 2418 	lcall	___fslt
      000B8B E5 81            [12] 2419 	mov	a,sp
      000B8D 24 FC            [12] 2420 	add	a,#0xfc
      000B8F F5 81            [12] 2421 	mov	sp,a
      000B91 D0 04            [24] 2422 	pop	ar4
      000B93 D0 05            [24] 2423 	pop	ar5
      000B95 D0 06            [24] 2424 	pop	ar6
      000B97 D0 07            [24] 2425 	pop	ar7
      000B99 E5 82            [12] 2426 	mov	a, dpl
      000B9B 24 FF            [12] 2427 	add	a,#0xff
      000B9D 92 00            [24] 2428 	mov	b0,c
      000B9F 40 03            [24] 2429 	jc	00161$
      000BA1 02 0C 24         [24] 2430 	ljmp	00108$
      000BA4                       2431 00161$:
      000BA4 C0 07            [24] 2432 	push	ar7
      000BA6 C0 06            [24] 2433 	push	ar6
      000BA8 C0 05            [24] 2434 	push	ar5
      000BAA C0 04            [24] 2435 	push	ar4
      000BAC E5 1D            [12] 2436 	mov	a,_bp
      000BAE 24 EE            [12] 2437 	add	a,#0xee
      000BB0 F8               [12] 2438 	mov	r0,a
      000BB1 E6               [12] 2439 	mov	a,@r0
      000BB2 C0 E0            [24] 2440 	push	acc
      000BB4 08               [12] 2441 	inc	r0
      000BB5 E6               [12] 2442 	mov	a,@r0
      000BB6 C0 E0            [24] 2443 	push	acc
      000BB8 08               [12] 2444 	inc	r0
      000BB9 E6               [12] 2445 	mov	a,@r0
      000BBA C0 E0            [24] 2446 	push	acc
      000BBC 08               [12] 2447 	inc	r0
      000BBD E6               [12] 2448 	mov	a,@r0
      000BBE C0 E0            [24] 2449 	push	acc
      000BC0 8F 82            [24] 2450 	mov	dpl, r7
      000BC2 8E 83            [24] 2451 	mov	dph, r6
      000BC4 8D F0            [24] 2452 	mov	b, r5
      000BC6 EC               [12] 2453 	mov	a, r4
      000BC7 12 1D F2         [24] 2454 	lcall	___fslt
      000BCA E5 81            [12] 2455 	mov	a,sp
      000BCC 24 FC            [12] 2456 	add	a,#0xfc
      000BCE F5 81            [12] 2457 	mov	sp,a
      000BD0 D0 04            [24] 2458 	pop	ar4
      000BD2 D0 05            [24] 2459 	pop	ar5
      000BD4 D0 06            [24] 2460 	pop	ar6
      000BD6 D0 07            [24] 2461 	pop	ar7
      000BD8 E5 82            [12] 2462 	mov	a, dpl
      000BDA 24 FF            [12] 2463 	add	a,#0xff
      000BDC 92 00            [24] 2464 	mov	b0,c
      000BDE 50 44            [24] 2465 	jnc	00108$
      000BE0 C0 07            [24] 2466 	push	ar7
      000BE2 C0 06            [24] 2467 	push	ar6
      000BE4 C0 05            [24] 2468 	push	ar5
      000BE6 C0 04            [24] 2469 	push	ar4
      000BE8 E5 1D            [12] 2470 	mov	a,_bp
      000BEA 24 F2            [12] 2471 	add	a,#0xf2
      000BEC F8               [12] 2472 	mov	r0,a
      000BED E6               [12] 2473 	mov	a,@r0
      000BEE C0 E0            [24] 2474 	push	acc
      000BF0 08               [12] 2475 	inc	r0
      000BF1 E6               [12] 2476 	mov	a,@r0
      000BF2 C0 E0            [24] 2477 	push	acc
      000BF4 08               [12] 2478 	inc	r0
      000BF5 E6               [12] 2479 	mov	a,@r0
      000BF6 C0 E0            [24] 2480 	push	acc
      000BF8 08               [12] 2481 	inc	r0
      000BF9 E6               [12] 2482 	mov	a,@r0
      000BFA C0 E0            [24] 2483 	push	acc
      000BFC E5 1D            [12] 2484 	mov	a,_bp
      000BFE 24 EE            [12] 2485 	add	a,#0xee
      000C00 F8               [12] 2486 	mov	r0,a
      000C01 86 82            [24] 2487 	mov	dpl, @r0
      000C03 08               [12] 2488 	inc	r0
      000C04 86 83            [24] 2489 	mov	dph, @r0
      000C06 08               [12] 2490 	inc	r0
      000C07 86 F0            [24] 2491 	mov	b, @r0
      000C09 08               [12] 2492 	inc	r0
      000C0A E6               [12] 2493 	mov	a, @r0
      000C0B 12 1D F2         [24] 2494 	lcall	___fslt
      000C0E E5 81            [12] 2495 	mov	a,sp
      000C10 24 FC            [12] 2496 	add	a,#0xfc
      000C12 F5 81            [12] 2497 	mov	sp,a
      000C14 D0 04            [24] 2498 	pop	ar4
      000C16 D0 05            [24] 2499 	pop	ar5
      000C18 D0 06            [24] 2500 	pop	ar6
      000C1A D0 07            [24] 2501 	pop	ar7
      000C1C E5 82            [12] 2502 	mov	a, dpl
      000C1E 24 FF            [12] 2503 	add	a,#0xff
      000C20 92 00            [24] 2504 	mov	b0,c
      000C22 40 0E            [24] 2505 	jc	00109$
      000C24                       2506 00108$:
      000C24 A8 1D            [24] 2507 	mov	r0,_bp
      000C26 08               [12] 2508 	inc	r0
      000C27 E4               [12] 2509 	clr	a
      000C28 F6               [12] 2510 	mov	@r0,a
      000C29 08               [12] 2511 	inc	r0
      000C2A F6               [12] 2512 	mov	@r0,a
      000C2B 08               [12] 2513 	inc	r0
      000C2C F6               [12] 2514 	mov	@r0,a
      000C2D 08               [12] 2515 	inc	r0
      000C2E F6               [12] 2516 	mov	@r0,a
      000C2F 02 0E 31         [24] 2517 	ljmp	00110$
      000C32                       2518 00109$:
      000C32 C0 07            [24] 2519 	push	ar7
      000C34 C0 06            [24] 2520 	push	ar6
      000C36 C0 05            [24] 2521 	push	ar5
      000C38 C0 04            [24] 2522 	push	ar4
      000C3A E5 1D            [12] 2523 	mov	a,_bp
      000C3C 24 FA            [12] 2524 	add	a,#0xfa
      000C3E F8               [12] 2525 	mov	r0,a
      000C3F E6               [12] 2526 	mov	a,@r0
      000C40 C0 E0            [24] 2527 	push	acc
      000C42 08               [12] 2528 	inc	r0
      000C43 E6               [12] 2529 	mov	a,@r0
      000C44 C0 E0            [24] 2530 	push	acc
      000C46 08               [12] 2531 	inc	r0
      000C47 E6               [12] 2532 	mov	a,@r0
      000C48 C0 E0            [24] 2533 	push	acc
      000C4A 08               [12] 2534 	inc	r0
      000C4B E6               [12] 2535 	mov	a,@r0
      000C4C C0 E0            [24] 2536 	push	acc
      000C4E E5 1D            [12] 2537 	mov	a,_bp
      000C50 24 EE            [12] 2538 	add	a,#0xee
      000C52 F8               [12] 2539 	mov	r0,a
      000C53 86 82            [24] 2540 	mov	dpl, @r0
      000C55 08               [12] 2541 	inc	r0
      000C56 86 83            [24] 2542 	mov	dph, @r0
      000C58 08               [12] 2543 	inc	r0
      000C59 86 F0            [24] 2544 	mov	b, @r0
      000C5B 08               [12] 2545 	inc	r0
      000C5C E6               [12] 2546 	mov	a, @r0
      000C5D 12 1D F2         [24] 2547 	lcall	___fslt
      000C60 E5 81            [12] 2548 	mov	a,sp
      000C62 24 FC            [12] 2549 	add	a,#0xfc
      000C64 F5 81            [12] 2550 	mov	sp,a
      000C66 D0 04            [24] 2551 	pop	ar4
      000C68 D0 05            [24] 2552 	pop	ar5
      000C6A D0 06            [24] 2553 	pop	ar6
      000C6C D0 07            [24] 2554 	pop	ar7
      000C6E E5 82            [12] 2555 	mov	a, dpl
      000C70 24 FF            [12] 2556 	add	a,#0xff
      000C72 92 00            [24] 2557 	mov	b0,c
      000C74 40 54            [24] 2558 	jc	00105$
      000C76 C0 07            [24] 2559 	push	ar7
      000C78 C0 06            [24] 2560 	push	ar6
      000C7A C0 05            [24] 2561 	push	ar5
      000C7C C0 04            [24] 2562 	push	ar4
      000C7E E5 1D            [12] 2563 	mov	a,_bp
      000C80 24 EE            [12] 2564 	add	a,#0xee
      000C82 F8               [12] 2565 	mov	r0,a
      000C83 E6               [12] 2566 	mov	a,@r0
      000C84 C0 E0            [24] 2567 	push	acc
      000C86 08               [12] 2568 	inc	r0
      000C87 E6               [12] 2569 	mov	a,@r0
      000C88 C0 E0            [24] 2570 	push	acc
      000C8A 08               [12] 2571 	inc	r0
      000C8B E6               [12] 2572 	mov	a,@r0
      000C8C C0 E0            [24] 2573 	push	acc
      000C8E 08               [12] 2574 	inc	r0
      000C8F E6               [12] 2575 	mov	a,@r0
      000C90 C0 E0            [24] 2576 	push	acc
      000C92 E5 1D            [12] 2577 	mov	a,_bp
      000C94 24 F6            [12] 2578 	add	a,#0xf6
      000C96 F8               [12] 2579 	mov	r0,a
      000C97 86 82            [24] 2580 	mov	dpl, @r0
      000C99 08               [12] 2581 	inc	r0
      000C9A 86 83            [24] 2582 	mov	dph, @r0
      000C9C 08               [12] 2583 	inc	r0
      000C9D 86 F0            [24] 2584 	mov	b, @r0
      000C9F 08               [12] 2585 	inc	r0
      000CA0 E6               [12] 2586 	mov	a, @r0
      000CA1 12 1D F2         [24] 2587 	lcall	___fslt
      000CA4 E5 81            [12] 2588 	mov	a,sp
      000CA6 24 FC            [12] 2589 	add	a,#0xfc
      000CA8 F5 81            [12] 2590 	mov	sp,a
      000CAA D0 04            [24] 2591 	pop	ar4
      000CAC D0 05            [24] 2592 	pop	ar5
      000CAE D0 06            [24] 2593 	pop	ar6
      000CB0 D0 07            [24] 2594 	pop	ar7
      000CB2 E5 82            [12] 2595 	mov	a, dpl
      000CB4 24 FF            [12] 2596 	add	a,#0xff
      000CB6 92 00            [24] 2597 	mov	b0,c
      000CB8 40 10            [24] 2598 	jc	00105$
      000CBA A8 1D            [24] 2599 	mov	r0,_bp
      000CBC 08               [12] 2600 	inc	r0
      000CBD E4               [12] 2601 	clr	a
      000CBE F6               [12] 2602 	mov	@r0,a
      000CBF 08               [12] 2603 	inc	r0
      000CC0 F6               [12] 2604 	mov	@r0,a
      000CC1 08               [12] 2605 	inc	r0
      000CC2 76 80            [12] 2606 	mov	@r0,#0x80
      000CC4 08               [12] 2607 	inc	r0
      000CC5 76 3F            [12] 2608 	mov	@r0,#0x3f
      000CC7 02 0E 31         [24] 2609 	ljmp	00110$
      000CCA                       2610 00105$:
      000CCA C0 07            [24] 2611 	push	ar7
      000CCC C0 06            [24] 2612 	push	ar6
      000CCE C0 05            [24] 2613 	push	ar5
      000CD0 C0 04            [24] 2614 	push	ar4
      000CD2 E5 1D            [12] 2615 	mov	a,_bp
      000CD4 24 FA            [12] 2616 	add	a,#0xfa
      000CD6 F8               [12] 2617 	mov	r0,a
      000CD7 E6               [12] 2618 	mov	a,@r0
      000CD8 C0 E0            [24] 2619 	push	acc
      000CDA 08               [12] 2620 	inc	r0
      000CDB E6               [12] 2621 	mov	a,@r0
      000CDC C0 E0            [24] 2622 	push	acc
      000CDE 08               [12] 2623 	inc	r0
      000CDF E6               [12] 2624 	mov	a,@r0
      000CE0 C0 E0            [24] 2625 	push	acc
      000CE2 08               [12] 2626 	inc	r0
      000CE3 E6               [12] 2627 	mov	a,@r0
      000CE4 C0 E0            [24] 2628 	push	acc
      000CE6 E5 1D            [12] 2629 	mov	a,_bp
      000CE8 24 EE            [12] 2630 	add	a,#0xee
      000CEA F8               [12] 2631 	mov	r0,a
      000CEB 86 82            [24] 2632 	mov	dpl, @r0
      000CED 08               [12] 2633 	inc	r0
      000CEE 86 83            [24] 2634 	mov	dph, @r0
      000CF0 08               [12] 2635 	inc	r0
      000CF1 86 F0            [24] 2636 	mov	b, @r0
      000CF3 08               [12] 2637 	inc	r0
      000CF4 E6               [12] 2638 	mov	a, @r0
      000CF5 12 1D F2         [24] 2639 	lcall	___fslt
      000CF8 AB 82            [24] 2640 	mov	r3, dpl
      000CFA E5 81            [12] 2641 	mov	a,sp
      000CFC 24 FC            [12] 2642 	add	a,#0xfc
      000CFE F5 81            [12] 2643 	mov	sp,a
      000D00 D0 04            [24] 2644 	pop	ar4
      000D02 D0 05            [24] 2645 	pop	ar5
      000D04 D0 06            [24] 2646 	pop	ar6
      000D06 D0 07            [24] 2647 	pop	ar7
      000D08 EB               [12] 2648 	mov	a,r3
      000D09 70 03            [24] 2649 	jnz	00166$
      000D0B 02 0D 95         [24] 2650 	ljmp	00102$
      000D0E                       2651 00166$:
      000D0E C0 07            [24] 2652 	push	ar7
      000D10 C0 06            [24] 2653 	push	ar6
      000D12 C0 05            [24] 2654 	push	ar5
      000D14 C0 04            [24] 2655 	push	ar4
      000D16 C0 07            [24] 2656 	push	ar7
      000D18 C0 06            [24] 2657 	push	ar6
      000D1A C0 05            [24] 2658 	push	ar5
      000D1C C0 04            [24] 2659 	push	ar4
      000D1E E5 1D            [12] 2660 	mov	a,_bp
      000D20 24 EE            [12] 2661 	add	a,#0xee
      000D22 F8               [12] 2662 	mov	r0,a
      000D23 86 82            [24] 2663 	mov	dpl, @r0
      000D25 08               [12] 2664 	inc	r0
      000D26 86 83            [24] 2665 	mov	dph, @r0
      000D28 08               [12] 2666 	inc	r0
      000D29 86 F0            [24] 2667 	mov	b, @r0
      000D2B 08               [12] 2668 	inc	r0
      000D2C E6               [12] 2669 	mov	a, @r0
      000D2D 12 1C B7         [24] 2670 	lcall	___fssub
      000D30 C8               [12] 2671 	xch	a,r0
      000D31 E5 1D            [12] 2672 	mov	a,_bp
      000D33 24 05            [12] 2673 	add	a,#0x05
      000D35 C8               [12] 2674 	xch	a,r0
      000D36 A6 82            [24] 2675 	mov	@r0, dpl
      000D38 08               [12] 2676 	inc	r0
      000D39 A6 83            [24] 2677 	mov	@r0, dph
      000D3B 08               [12] 2678 	inc	r0
      000D3C A6 F0            [24] 2679 	mov	@r0, b
      000D3E 08               [12] 2680 	inc	r0
      000D3F F6               [12] 2681 	mov	@r0,a
      000D40 E5 81            [12] 2682 	mov	a,sp
      000D42 24 FC            [12] 2683 	add	a,#0xfc
      000D44 F5 81            [12] 2684 	mov	sp,a
      000D46 E5 1D            [12] 2685 	mov	a,_bp
      000D48 24 FA            [12] 2686 	add	a,#0xfa
      000D4A F8               [12] 2687 	mov	r0,a
      000D4B 86 82            [24] 2688 	mov	dpl, @r0
      000D4D 08               [12] 2689 	inc	r0
      000D4E 86 83            [24] 2690 	mov	dph, @r0
      000D50 08               [12] 2691 	inc	r0
      000D51 86 F0            [24] 2692 	mov	b, @r0
      000D53 08               [12] 2693 	inc	r0
      000D54 E6               [12] 2694 	mov	a, @r0
      000D55 12 1C B7         [24] 2695 	lcall	___fssub
      000D58 AC 82            [24] 2696 	mov	r4, dpl
      000D5A AD 83            [24] 2697 	mov	r5, dph
      000D5C AE F0            [24] 2698 	mov	r6, b
      000D5E FF               [12] 2699 	mov	r7, a
      000D5F E5 81            [12] 2700 	mov	a,sp
      000D61 24 FC            [12] 2701 	add	a,#0xfc
      000D63 F5 81            [12] 2702 	mov	sp,a
      000D65 C0 04            [24] 2703 	push	ar4
      000D67 C0 05            [24] 2704 	push	ar5
      000D69 C0 06            [24] 2705 	push	ar6
      000D6B C0 07            [24] 2706 	push	ar7
      000D6D E5 1D            [12] 2707 	mov	a,_bp
      000D6F 24 05            [12] 2708 	add	a,#0x05
      000D71 F8               [12] 2709 	mov	r0,a
      000D72 86 82            [24] 2710 	mov	dpl, @r0
      000D74 08               [12] 2711 	inc	r0
      000D75 86 83            [24] 2712 	mov	dph, @r0
      000D77 08               [12] 2713 	inc	r0
      000D78 86 F0            [24] 2714 	mov	b, @r0
      000D7A 08               [12] 2715 	inc	r0
      000D7B E6               [12] 2716 	mov	a, @r0
      000D7C 12 1F 39         [24] 2717 	lcall	___fsdiv
      000D7F A8 1D            [24] 2718 	mov	r0,_bp
      000D81 08               [12] 2719 	inc	r0
      000D82 A6 82            [24] 2720 	mov	@r0, dpl
      000D84 08               [12] 2721 	inc	r0
      000D85 A6 83            [24] 2722 	mov	@r0, dph
      000D87 08               [12] 2723 	inc	r0
      000D88 A6 F0            [24] 2724 	mov	@r0, b
      000D8A 08               [12] 2725 	inc	r0
      000D8B F6               [12] 2726 	mov	@r0,a
      000D8C E5 81            [12] 2727 	mov	a,sp
      000D8E 24 FC            [12] 2728 	add	a,#0xfc
      000D90 F5 81            [12] 2729 	mov	sp,a
      000D92 02 0E 31         [24] 2730 	ljmp	00110$
      000D95                       2731 00102$:
      000D95 E5 1D            [12] 2732 	mov	a,_bp
      000D97 24 EE            [12] 2733 	add	a,#0xee
      000D99 F8               [12] 2734 	mov	r0,a
      000D9A E6               [12] 2735 	mov	a,@r0
      000D9B C0 E0            [24] 2736 	push	acc
      000D9D 08               [12] 2737 	inc	r0
      000D9E E6               [12] 2738 	mov	a,@r0
      000D9F C0 E0            [24] 2739 	push	acc
      000DA1 08               [12] 2740 	inc	r0
      000DA2 E6               [12] 2741 	mov	a,@r0
      000DA3 C0 E0            [24] 2742 	push	acc
      000DA5 08               [12] 2743 	inc	r0
      000DA6 E6               [12] 2744 	mov	a,@r0
      000DA7 C0 E0            [24] 2745 	push	acc
      000DA9 E5 1D            [12] 2746 	mov	a,_bp
      000DAB 24 F2            [12] 2747 	add	a,#0xf2
      000DAD F8               [12] 2748 	mov	r0,a
      000DAE 86 82            [24] 2749 	mov	dpl, @r0
      000DB0 08               [12] 2750 	inc	r0
      000DB1 86 83            [24] 2751 	mov	dph, @r0
      000DB3 08               [12] 2752 	inc	r0
      000DB4 86 F0            [24] 2753 	mov	b, @r0
      000DB6 08               [12] 2754 	inc	r0
      000DB7 E6               [12] 2755 	mov	a, @r0
      000DB8 12 1C B7         [24] 2756 	lcall	___fssub
      000DBB C8               [12] 2757 	xch	a,r0
      000DBC E5 1D            [12] 2758 	mov	a,_bp
      000DBE 24 05            [12] 2759 	add	a,#0x05
      000DC0 C8               [12] 2760 	xch	a,r0
      000DC1 A6 82            [24] 2761 	mov	@r0, dpl
      000DC3 08               [12] 2762 	inc	r0
      000DC4 A6 83            [24] 2763 	mov	@r0, dph
      000DC6 08               [12] 2764 	inc	r0
      000DC7 A6 F0            [24] 2765 	mov	@r0, b
      000DC9 08               [12] 2766 	inc	r0
      000DCA F6               [12] 2767 	mov	@r0,a
      000DCB E5 81            [12] 2768 	mov	a,sp
      000DCD 24 FC            [12] 2769 	add	a,#0xfc
      000DCF F5 81            [12] 2770 	mov	sp,a
      000DD1 E5 1D            [12] 2771 	mov	a,_bp
      000DD3 24 F6            [12] 2772 	add	a,#0xf6
      000DD5 F8               [12] 2773 	mov	r0,a
      000DD6 E6               [12] 2774 	mov	a,@r0
      000DD7 C0 E0            [24] 2775 	push	acc
      000DD9 08               [12] 2776 	inc	r0
      000DDA E6               [12] 2777 	mov	a,@r0
      000DDB C0 E0            [24] 2778 	push	acc
      000DDD 08               [12] 2779 	inc	r0
      000DDE E6               [12] 2780 	mov	a,@r0
      000DDF C0 E0            [24] 2781 	push	acc
      000DE1 08               [12] 2782 	inc	r0
      000DE2 E6               [12] 2783 	mov	a,@r0
      000DE3 C0 E0            [24] 2784 	push	acc
      000DE5 E5 1D            [12] 2785 	mov	a,_bp
      000DE7 24 F2            [12] 2786 	add	a,#0xf2
      000DE9 F8               [12] 2787 	mov	r0,a
      000DEA 86 82            [24] 2788 	mov	dpl, @r0
      000DEC 08               [12] 2789 	inc	r0
      000DED 86 83            [24] 2790 	mov	dph, @r0
      000DEF 08               [12] 2791 	inc	r0
      000DF0 86 F0            [24] 2792 	mov	b, @r0
      000DF2 08               [12] 2793 	inc	r0
      000DF3 E6               [12] 2794 	mov	a, @r0
      000DF4 12 1C B7         [24] 2795 	lcall	___fssub
      000DF7 AA 82            [24] 2796 	mov	r2, dpl
      000DF9 AB 83            [24] 2797 	mov	r3, dph
      000DFB AE F0            [24] 2798 	mov	r6, b
      000DFD FF               [12] 2799 	mov	r7, a
      000DFE E5 81            [12] 2800 	mov	a,sp
      000E00 24 FC            [12] 2801 	add	a,#0xfc
      000E02 F5 81            [12] 2802 	mov	sp,a
      000E04 C0 02            [24] 2803 	push	ar2
      000E06 C0 03            [24] 2804 	push	ar3
      000E08 C0 06            [24] 2805 	push	ar6
      000E0A C0 07            [24] 2806 	push	ar7
      000E0C E5 1D            [12] 2807 	mov	a,_bp
      000E0E 24 05            [12] 2808 	add	a,#0x05
      000E10 F8               [12] 2809 	mov	r0,a
      000E11 86 82            [24] 2810 	mov	dpl, @r0
      000E13 08               [12] 2811 	inc	r0
      000E14 86 83            [24] 2812 	mov	dph, @r0
      000E16 08               [12] 2813 	inc	r0
      000E17 86 F0            [24] 2814 	mov	b, @r0
      000E19 08               [12] 2815 	inc	r0
      000E1A E6               [12] 2816 	mov	a, @r0
      000E1B 12 1F 39         [24] 2817 	lcall	___fsdiv
      000E1E A8 1D            [24] 2818 	mov	r0,_bp
      000E20 08               [12] 2819 	inc	r0
      000E21 A6 82            [24] 2820 	mov	@r0, dpl
      000E23 08               [12] 2821 	inc	r0
      000E24 A6 83            [24] 2822 	mov	@r0, dph
      000E26 08               [12] 2823 	inc	r0
      000E27 A6 F0            [24] 2824 	mov	@r0, b
      000E29 08               [12] 2825 	inc	r0
      000E2A F6               [12] 2826 	mov	@r0,a
      000E2B E5 81            [12] 2827 	mov	a,sp
      000E2D 24 FC            [12] 2828 	add	a,#0xfc
      000E2F F5 81            [12] 2829 	mov	sp,a
      000E31                       2830 00110$:
      000E31 E5 1D            [12] 2831 	mov	a,_bp
      000E33 24 ED            [12] 2832 	add	a,#0xed
      000E35 F8               [12] 2833 	mov	r0,a
      000E36 E6               [12] 2834 	mov	a,@r0
      000E37 C0 E0            [24] 2835 	push	acc
      000E39 A8 1D            [24] 2836 	mov	r0,_bp
      000E3B 08               [12] 2837 	inc	r0
      000E3C 86 82            [24] 2838 	mov	dpl, @r0
      000E3E 08               [12] 2839 	inc	r0
      000E3F 86 83            [24] 2840 	mov	dph, @r0
      000E41 08               [12] 2841 	inc	r0
      000E42 86 F0            [24] 2842 	mov	b, @r0
      000E44 08               [12] 2843 	inc	r0
      000E45 E6               [12] 2844 	mov	a, @r0
      000E46 12 04 F4         [24] 2845 	lcall	_fuzzy_8051_hedge
      000E49 AC 82            [24] 2846 	mov	r4, dpl
      000E4B AD 83            [24] 2847 	mov	r5, dph
      000E4D AE F0            [24] 2848 	mov	r6, b
      000E4F FF               [12] 2849 	mov	r7, a
      000E50 15 81            [12] 2850 	dec	sp
      000E52 8C 82            [24] 2851 	mov	dpl, r4
      000E54 8D 83            [24] 2852 	mov	dph, r5
      000E56 8E F0            [24] 2853 	mov	b, r6
      000E58 EF               [12] 2854 	mov	a, r7
      000E59 85 1D 81         [24] 2855 	mov	sp,_bp
      000E5C D0 1D            [24] 2856 	pop	_bp
                           000DA7  2857 	C$fuzzy.h$71$1_0$33 ==.
                           000DA7  2858 	XG$fuzzy_trapezoid$0$0 ==.
      000E5E 22               [24] 2859 	ret
                                   2860 ;------------------------------------------------------------
                                   2861 ;Allocation info for local variables in function 'fuzzy_8051_eval'
                                   2862 ;------------------------------------------------------------
                                   2863 ;x             Allocated to stack - _bp -6 +4 
                                   2864 ;v             Allocated to stack - _bp +1 +3 
                                   2865 ;sloc0         Allocated to stack - _bp +4 +1 
                                   2866 ;sloc1         Allocated to stack - _bp +5 +1 
                                   2867 ;sloc2         Allocated to stack - _bp +5 +4 
                                   2868 ;sloc3         Allocated to stack - _bp +9 +4 
                                   2869 ;sloc4         Allocated to stack - _bp +13 +4 
                                   2870 ;sloc5         Allocated to stack - _bp +17 +4 
                                   2871 ;------------------------------------------------------------
                           000DA8  2872 	Fcontroller_8051$fuzzy_8051_eval$0$0 ==.
                           000DA8  2873 	C$fuzzy.h$72$1_0$35 ==.
                                   2874 ;	../../fuzzy.h:72: static float fuzzy_8051_eval(const fuzzy_variable_8051_t *v, float x) { if (v->shape == FUZZY_SHAPE_RAMP) return fuzzy_ramp(v->parameters[0], v->parameters[1], x, v->parameters[2] != 0.0f, v->hedge); if (v->shape == FUZZY_SHAPE_TRIANGLE) return fuzzy_triangle(v->parameters[0], v->parameters[1], v->parameters[2], x, v->hedge); if (v->shape == FUZZY_SHAPE_TRAPEZOID) return fuzzy_trapezoid(v->parameters[0], v->parameters[1], v->parameters[2], v->parameters[3], x, v->hedge); return 0.0f; }
                                   2875 ;	-----------------------------------------
                                   2876 ;	 function fuzzy_8051_eval
                                   2877 ;	-----------------------------------------
      000E5F                       2878 _fuzzy_8051_eval:
      000E5F C0 1D            [24] 2879 	push	_bp
      000E61 85 81 1D         [24] 2880 	mov	_bp,sp
      000E64 C0 82            [24] 2881 	push	dpl
      000E66 C0 83            [24] 2882 	push	dph
      000E68 C0 F0            [24] 2883 	push	b
      000E6A E5 81            [12] 2884 	mov	a,sp
      000E6C 24 11            [12] 2885 	add	a,#0x11
      000E6E F5 81            [12] 2886 	mov	sp,a
      000E70 A8 1D            [24] 2887 	mov	r0,_bp
      000E72 08               [12] 2888 	inc	r0
      000E73 86 02            [24] 2889 	mov	ar2,@r0
      000E75 08               [12] 2890 	inc	r0
      000E76 86 03            [24] 2891 	mov	ar3,@r0
      000E78 08               [12] 2892 	inc	r0
      000E79 86 04            [24] 2893 	mov	ar4,@r0
      000E7B 8A 82            [24] 2894 	mov	dpl,r2
      000E7D 8B 83            [24] 2895 	mov	dph,r3
      000E7F 8C F0            [24] 2896 	mov	b,r4
      000E81 12 1F FC         [24] 2897 	lcall	__gptrget
      000E84 FC               [12] 2898 	mov	r4,a
      000E85 60 03            [24] 2899 	jz	00127$
      000E87 02 0F 8F         [24] 2900 	ljmp	00102$
      000E8A                       2901 00127$:
      000E8A A8 1D            [24] 2902 	mov	r0,_bp
      000E8C 08               [12] 2903 	inc	r0
      000E8D 74 01            [12] 2904 	mov	a,#0x01
      000E8F 26               [12] 2905 	add	a, @r0
      000E90 FA               [12] 2906 	mov	r2,a
      000E91 E4               [12] 2907 	clr	a
      000E92 08               [12] 2908 	inc	r0
      000E93 36               [12] 2909 	addc	a, @r0
      000E94 FB               [12] 2910 	mov	r3,a
      000E95 08               [12] 2911 	inc	r0
      000E96 86 07            [24] 2912 	mov	ar7,@r0
      000E98 8A 82            [24] 2913 	mov	dpl,r2
      000E9A 8B 83            [24] 2914 	mov	dph,r3
      000E9C 8F F0            [24] 2915 	mov	b,r7
      000E9E 12 1F FC         [24] 2916 	lcall	__gptrget
      000EA1 FC               [12] 2917 	mov	r4,a
      000EA2 A8 1D            [24] 2918 	mov	r0,_bp
      000EA4 08               [12] 2919 	inc	r0
      000EA5 74 0A            [12] 2920 	mov	a,#0x0a
      000EA7 26               [12] 2921 	add	a, @r0
      000EA8 FD               [12] 2922 	mov	r5,a
      000EA9 E4               [12] 2923 	clr	a
      000EAA 08               [12] 2924 	inc	r0
      000EAB 36               [12] 2925 	addc	a, @r0
      000EAC FE               [12] 2926 	mov	r6,a
      000EAD 08               [12] 2927 	inc	r0
      000EAE 86 07            [24] 2928 	mov	ar7,@r0
      000EB0 8D 82            [24] 2929 	mov	dpl,r5
      000EB2 8E 83            [24] 2930 	mov	dph,r6
      000EB4 8F F0            [24] 2931 	mov	b,r7
      000EB6 12 1F FC         [24] 2932 	lcall	__gptrget
      000EB9 FD               [12] 2933 	mov	r5,a
      000EBA A3               [24] 2934 	inc	dptr
      000EBB 12 1F FC         [24] 2935 	lcall	__gptrget
      000EBE FE               [12] 2936 	mov	r6,a
      000EBF A3               [24] 2937 	inc	dptr
      000EC0 12 1F FC         [24] 2938 	lcall	__gptrget
      000EC3 FF               [12] 2939 	mov	r7,a
      000EC4 A3               [24] 2940 	inc	dptr
      000EC5 12 1F FC         [24] 2941 	lcall	__gptrget
      000EC8 FB               [12] 2942 	mov	r3,a
      000EC9 8D F0            [24] 2943 	mov	b,r5
      000ECB EE               [12] 2944 	mov	a,r6
      000ECC 42 F0            [12] 2945 	orl	b,a
      000ECE EF               [12] 2946 	mov	a,r7
      000ECF 42 F0            [12] 2947 	orl	b,a
      000ED1 EB               [12] 2948 	mov	a,r3
      000ED2 54 7F            [12] 2949 	anl	a,#0x7F
      000ED4 45 F0            [12] 2950 	orl	a,b
      000ED6 B4 01 00         [24] 2951 	cjne	a,#0x01,00128$
      000ED9                       2952 00128$:
      000ED9 B3               [12] 2953 	cpl	c
      000EDA 92 00            [24] 2954 	mov	b0,c
      000EDC E5 1D            [12] 2955 	mov	a,_bp
      000EDE 24 04            [12] 2956 	add	a,#0x04
      000EE0 F8               [12] 2957 	mov	r0,a
      000EE1 A2 00            [12] 2958 	mov	c,b0
      000EE3 E4               [12] 2959 	clr	a
      000EE4 33               [12] 2960 	rlc	a
      000EE5 F6               [12] 2961 	mov	@r0,a
      000EE6 A8 1D            [24] 2962 	mov	r0,_bp
      000EE8 08               [12] 2963 	inc	r0
      000EE9 74 06            [12] 2964 	mov	a,#0x06
      000EEB 26               [12] 2965 	add	a, @r0
      000EEC FB               [12] 2966 	mov	r3,a
      000EED E4               [12] 2967 	clr	a
      000EEE 08               [12] 2968 	inc	r0
      000EEF 36               [12] 2969 	addc	a, @r0
      000EF0 FD               [12] 2970 	mov	r5,a
      000EF1 08               [12] 2971 	inc	r0
      000EF2 86 06            [24] 2972 	mov	ar6,@r0
      000EF4 8B 82            [24] 2973 	mov	dpl,r3
      000EF6 8D 83            [24] 2974 	mov	dph,r5
      000EF8 8E F0            [24] 2975 	mov	b,r6
      000EFA E5 1D            [12] 2976 	mov	a,_bp
      000EFC 24 05            [12] 2977 	add	a,#0x05
      000EFE F8               [12] 2978 	mov	r0,a
      000EFF 12 1F FC         [24] 2979 	lcall	__gptrget
      000F02 F6               [12] 2980 	mov	@r0,a
      000F03 A3               [24] 2981 	inc	dptr
      000F04 12 1F FC         [24] 2982 	lcall	__gptrget
      000F07 08               [12] 2983 	inc	r0
      000F08 F6               [12] 2984 	mov	@r0,a
      000F09 A3               [24] 2985 	inc	dptr
      000F0A 12 1F FC         [24] 2986 	lcall	__gptrget
      000F0D 08               [12] 2987 	inc	r0
      000F0E F6               [12] 2988 	mov	@r0,a
      000F0F A3               [24] 2989 	inc	dptr
      000F10 12 1F FC         [24] 2990 	lcall	__gptrget
      000F13 08               [12] 2991 	inc	r0
      000F14 F6               [12] 2992 	mov	@r0,a
      000F15 A8 1D            [24] 2993 	mov	r0,_bp
      000F17 08               [12] 2994 	inc	r0
      000F18 74 02            [12] 2995 	mov	a,#0x02
      000F1A 26               [12] 2996 	add	a, @r0
      000F1B FA               [12] 2997 	mov	r2,a
      000F1C E4               [12] 2998 	clr	a
      000F1D 08               [12] 2999 	inc	r0
      000F1E 36               [12] 3000 	addc	a, @r0
      000F1F FE               [12] 3001 	mov	r6,a
      000F20 08               [12] 3002 	inc	r0
      000F21 86 07            [24] 3003 	mov	ar7,@r0
      000F23 8A 82            [24] 3004 	mov	dpl,r2
      000F25 8E 83            [24] 3005 	mov	dph,r6
      000F27 8F F0            [24] 3006 	mov	b,r7
      000F29 12 1F FC         [24] 3007 	lcall	__gptrget
      000F2C FA               [12] 3008 	mov	r2,a
      000F2D A3               [24] 3009 	inc	dptr
      000F2E 12 1F FC         [24] 3010 	lcall	__gptrget
      000F31 FE               [12] 3011 	mov	r6,a
      000F32 A3               [24] 3012 	inc	dptr
      000F33 12 1F FC         [24] 3013 	lcall	__gptrget
      000F36 FF               [12] 3014 	mov	r7,a
      000F37 A3               [24] 3015 	inc	dptr
      000F38 12 1F FC         [24] 3016 	lcall	__gptrget
      000F3B FD               [12] 3017 	mov	r5,a
      000F3C C0 04            [24] 3018 	push	ar4
      000F3E E5 1D            [12] 3019 	mov	a,_bp
      000F40 24 04            [12] 3020 	add	a,#0x04
      000F42 F8               [12] 3021 	mov	r0,a
      000F43 E6               [12] 3022 	mov	a,@r0
      000F44 C0 E0            [24] 3023 	push	acc
      000F46 E5 1D            [12] 3024 	mov	a,_bp
      000F48 24 FA            [12] 3025 	add	a,#0xfa
      000F4A F8               [12] 3026 	mov	r0,a
      000F4B E6               [12] 3027 	mov	a,@r0
      000F4C C0 E0            [24] 3028 	push	acc
      000F4E 08               [12] 3029 	inc	r0
      000F4F E6               [12] 3030 	mov	a,@r0
      000F50 C0 E0            [24] 3031 	push	acc
      000F52 08               [12] 3032 	inc	r0
      000F53 E6               [12] 3033 	mov	a,@r0
      000F54 C0 E0            [24] 3034 	push	acc
      000F56 08               [12] 3035 	inc	r0
      000F57 E6               [12] 3036 	mov	a,@r0
      000F58 C0 E0            [24] 3037 	push	acc
      000F5A E5 1D            [12] 3038 	mov	a,_bp
      000F5C 24 05            [12] 3039 	add	a,#0x05
      000F5E F8               [12] 3040 	mov	r0,a
      000F5F E6               [12] 3041 	mov	a,@r0
      000F60 C0 E0            [24] 3042 	push	acc
      000F62 08               [12] 3043 	inc	r0
      000F63 E6               [12] 3044 	mov	a,@r0
      000F64 C0 E0            [24] 3045 	push	acc
      000F66 08               [12] 3046 	inc	r0
      000F67 E6               [12] 3047 	mov	a,@r0
      000F68 C0 E0            [24] 3048 	push	acc
      000F6A 08               [12] 3049 	inc	r0
      000F6B E6               [12] 3050 	mov	a,@r0
      000F6C C0 E0            [24] 3051 	push	acc
      000F6E 8A 82            [24] 3052 	mov	dpl, r2
      000F70 8E 83            [24] 3053 	mov	dph, r6
      000F72 8F F0            [24] 3054 	mov	b, r7
      000F74 ED               [12] 3055 	mov	a, r5
      000F75 12 05 B0         [24] 3056 	lcall	_fuzzy_ramp
      000F78 AB 82            [24] 3057 	mov	r3, dpl
      000F7A AD 83            [24] 3058 	mov	r5, dph
      000F7C AE F0            [24] 3059 	mov	r6, b
      000F7E FF               [12] 3060 	mov	r7, a
      000F7F E5 81            [12] 3061 	mov	a,sp
      000F81 24 F6            [12] 3062 	add	a,#0xf6
      000F83 F5 81            [12] 3063 	mov	sp,a
      000F85 8B 82            [24] 3064 	mov	dpl, r3
      000F87 8D 83            [24] 3065 	mov	dph, r5
      000F89 8E F0            [24] 3066 	mov	b, r6
      000F8B EF               [12] 3067 	mov	a, r7
      000F8C 02 11 EA         [24] 3068 	ljmp	00107$
      000F8F                       3069 00102$:
      000F8F BC 01 02         [24] 3070 	cjne	r4,#0x01,00129$
      000F92 80 03            [24] 3071 	sjmp	00130$
      000F94                       3072 00129$:
      000F94 02 10 93         [24] 3073 	ljmp	00104$
      000F97                       3074 00130$:
      000F97 A8 1D            [24] 3075 	mov	r0,_bp
      000F99 08               [12] 3076 	inc	r0
      000F9A 74 01            [12] 3077 	mov	a,#0x01
      000F9C 26               [12] 3078 	add	a, @r0
      000F9D FD               [12] 3079 	mov	r5,a
      000F9E E4               [12] 3080 	clr	a
      000F9F 08               [12] 3081 	inc	r0
      000FA0 36               [12] 3082 	addc	a, @r0
      000FA1 FE               [12] 3083 	mov	r6,a
      000FA2 08               [12] 3084 	inc	r0
      000FA3 86 07            [24] 3085 	mov	ar7,@r0
      000FA5 8D 82            [24] 3086 	mov	dpl,r5
      000FA7 8E 83            [24] 3087 	mov	dph,r6
      000FA9 8F F0            [24] 3088 	mov	b,r7
      000FAB 12 1F FC         [24] 3089 	lcall	__gptrget
      000FAE FC               [12] 3090 	mov	r4,a
      000FAF A8 1D            [24] 3091 	mov	r0,_bp
      000FB1 08               [12] 3092 	inc	r0
      000FB2 74 0A            [12] 3093 	mov	a,#0x0a
      000FB4 26               [12] 3094 	add	a, @r0
      000FB5 FB               [12] 3095 	mov	r3,a
      000FB6 E4               [12] 3096 	clr	a
      000FB7 08               [12] 3097 	inc	r0
      000FB8 36               [12] 3098 	addc	a, @r0
      000FB9 FE               [12] 3099 	mov	r6,a
      000FBA 08               [12] 3100 	inc	r0
      000FBB 86 07            [24] 3101 	mov	ar7,@r0
      000FBD 8B 82            [24] 3102 	mov	dpl,r3
      000FBF 8E 83            [24] 3103 	mov	dph,r6
      000FC1 8F F0            [24] 3104 	mov	b,r7
      000FC3 E5 1D            [12] 3105 	mov	a,_bp
      000FC5 24 09            [12] 3106 	add	a,#0x09
      000FC7 F8               [12] 3107 	mov	r0,a
      000FC8 12 1F FC         [24] 3108 	lcall	__gptrget
      000FCB F6               [12] 3109 	mov	@r0,a
      000FCC A3               [24] 3110 	inc	dptr
      000FCD 12 1F FC         [24] 3111 	lcall	__gptrget
      000FD0 08               [12] 3112 	inc	r0
      000FD1 F6               [12] 3113 	mov	@r0,a
      000FD2 A3               [24] 3114 	inc	dptr
      000FD3 12 1F FC         [24] 3115 	lcall	__gptrget
      000FD6 08               [12] 3116 	inc	r0
      000FD7 F6               [12] 3117 	mov	@r0,a
      000FD8 A3               [24] 3118 	inc	dptr
      000FD9 12 1F FC         [24] 3119 	lcall	__gptrget
      000FDC 08               [12] 3120 	inc	r0
      000FDD F6               [12] 3121 	mov	@r0,a
      000FDE A8 1D            [24] 3122 	mov	r0,_bp
      000FE0 08               [12] 3123 	inc	r0
      000FE1 74 06            [12] 3124 	mov	a,#0x06
      000FE3 26               [12] 3125 	add	a, @r0
      000FE4 FD               [12] 3126 	mov	r5,a
      000FE5 E4               [12] 3127 	clr	a
      000FE6 08               [12] 3128 	inc	r0
      000FE7 36               [12] 3129 	addc	a, @r0
      000FE8 FE               [12] 3130 	mov	r6,a
      000FE9 08               [12] 3131 	inc	r0
      000FEA 86 07            [24] 3132 	mov	ar7,@r0
      000FEC 8D 82            [24] 3133 	mov	dpl,r5
      000FEE 8E 83            [24] 3134 	mov	dph,r6
      000FF0 8F F0            [24] 3135 	mov	b,r7
      000FF2 E5 1D            [12] 3136 	mov	a,_bp
      000FF4 24 0D            [12] 3137 	add	a,#0x0d
      000FF6 F8               [12] 3138 	mov	r0,a
      000FF7 12 1F FC         [24] 3139 	lcall	__gptrget
      000FFA F6               [12] 3140 	mov	@r0,a
      000FFB A3               [24] 3141 	inc	dptr
      000FFC 12 1F FC         [24] 3142 	lcall	__gptrget
      000FFF 08               [12] 3143 	inc	r0
      001000 F6               [12] 3144 	mov	@r0,a
      001001 A3               [24] 3145 	inc	dptr
      001002 12 1F FC         [24] 3146 	lcall	__gptrget
      001005 08               [12] 3147 	inc	r0
      001006 F6               [12] 3148 	mov	@r0,a
      001007 A3               [24] 3149 	inc	dptr
      001008 12 1F FC         [24] 3150 	lcall	__gptrget
      00100B 08               [12] 3151 	inc	r0
      00100C F6               [12] 3152 	mov	@r0,a
      00100D A8 1D            [24] 3153 	mov	r0,_bp
      00100F 08               [12] 3154 	inc	r0
      001010 74 02            [12] 3155 	mov	a,#0x02
      001012 26               [12] 3156 	add	a, @r0
      001013 FA               [12] 3157 	mov	r2,a
      001014 E4               [12] 3158 	clr	a
      001015 08               [12] 3159 	inc	r0
      001016 36               [12] 3160 	addc	a, @r0
      001017 FE               [12] 3161 	mov	r6,a
      001018 08               [12] 3162 	inc	r0
      001019 86 07            [24] 3163 	mov	ar7,@r0
      00101B 8A 82            [24] 3164 	mov	dpl,r2
      00101D 8E 83            [24] 3165 	mov	dph,r6
      00101F 8F F0            [24] 3166 	mov	b,r7
      001021 12 1F FC         [24] 3167 	lcall	__gptrget
      001024 FA               [12] 3168 	mov	r2,a
      001025 A3               [24] 3169 	inc	dptr
      001026 12 1F FC         [24] 3170 	lcall	__gptrget
      001029 FE               [12] 3171 	mov	r6,a
      00102A A3               [24] 3172 	inc	dptr
      00102B 12 1F FC         [24] 3173 	lcall	__gptrget
      00102E FF               [12] 3174 	mov	r7,a
      00102F A3               [24] 3175 	inc	dptr
      001030 12 1F FC         [24] 3176 	lcall	__gptrget
      001033 FD               [12] 3177 	mov	r5,a
      001034 C0 04            [24] 3178 	push	ar4
      001036 E5 1D            [12] 3179 	mov	a,_bp
      001038 24 FA            [12] 3180 	add	a,#0xfa
      00103A F8               [12] 3181 	mov	r0,a
      00103B E6               [12] 3182 	mov	a,@r0
      00103C C0 E0            [24] 3183 	push	acc
      00103E 08               [12] 3184 	inc	r0
      00103F E6               [12] 3185 	mov	a,@r0
      001040 C0 E0            [24] 3186 	push	acc
      001042 08               [12] 3187 	inc	r0
      001043 E6               [12] 3188 	mov	a,@r0
      001044 C0 E0            [24] 3189 	push	acc
      001046 08               [12] 3190 	inc	r0
      001047 E6               [12] 3191 	mov	a,@r0
      001048 C0 E0            [24] 3192 	push	acc
      00104A E5 1D            [12] 3193 	mov	a,_bp
      00104C 24 09            [12] 3194 	add	a,#0x09
      00104E F8               [12] 3195 	mov	r0,a
      00104F E6               [12] 3196 	mov	a,@r0
      001050 C0 E0            [24] 3197 	push	acc
      001052 08               [12] 3198 	inc	r0
      001053 E6               [12] 3199 	mov	a,@r0
      001054 C0 E0            [24] 3200 	push	acc
      001056 08               [12] 3201 	inc	r0
      001057 E6               [12] 3202 	mov	a,@r0
      001058 C0 E0            [24] 3203 	push	acc
      00105A 08               [12] 3204 	inc	r0
      00105B E6               [12] 3205 	mov	a,@r0
      00105C C0 E0            [24] 3206 	push	acc
      00105E E5 1D            [12] 3207 	mov	a,_bp
      001060 24 0D            [12] 3208 	add	a,#0x0d
      001062 F8               [12] 3209 	mov	r0,a
      001063 E6               [12] 3210 	mov	a,@r0
      001064 C0 E0            [24] 3211 	push	acc
      001066 08               [12] 3212 	inc	r0
      001067 E6               [12] 3213 	mov	a,@r0
      001068 C0 E0            [24] 3214 	push	acc
      00106A 08               [12] 3215 	inc	r0
      00106B E6               [12] 3216 	mov	a,@r0
      00106C C0 E0            [24] 3217 	push	acc
      00106E 08               [12] 3218 	inc	r0
      00106F E6               [12] 3219 	mov	a,@r0
      001070 C0 E0            [24] 3220 	push	acc
      001072 8A 82            [24] 3221 	mov	dpl, r2
      001074 8E 83            [24] 3222 	mov	dph, r6
      001076 8F F0            [24] 3223 	mov	b, r7
      001078 ED               [12] 3224 	mov	a, r5
      001079 12 07 BC         [24] 3225 	lcall	_fuzzy_triangle
      00107C AB 82            [24] 3226 	mov	r3, dpl
      00107E AD 83            [24] 3227 	mov	r5, dph
      001080 AE F0            [24] 3228 	mov	r6, b
      001082 FF               [12] 3229 	mov	r7, a
      001083 E5 81            [12] 3230 	mov	a,sp
      001085 24 F3            [12] 3231 	add	a,#0xf3
      001087 F5 81            [12] 3232 	mov	sp,a
      001089 8B 82            [24] 3233 	mov	dpl, r3
      00108B 8D 83            [24] 3234 	mov	dph, r5
      00108D 8E F0            [24] 3235 	mov	b, r6
      00108F EF               [12] 3236 	mov	a, r7
      001090 02 11 EA         [24] 3237 	ljmp	00107$
      001093                       3238 00104$:
      001093 BC 02 02         [24] 3239 	cjne	r4,#0x02,00131$
      001096 80 03            [24] 3240 	sjmp	00132$
      001098                       3241 00131$:
      001098 02 11 E4         [24] 3242 	ljmp	00106$
      00109B                       3243 00132$:
      00109B A8 1D            [24] 3244 	mov	r0,_bp
      00109D 08               [12] 3245 	inc	r0
      00109E 74 01            [12] 3246 	mov	a,#0x01
      0010A0 26               [12] 3247 	add	a, @r0
      0010A1 FD               [12] 3248 	mov	r5,a
      0010A2 E4               [12] 3249 	clr	a
      0010A3 08               [12] 3250 	inc	r0
      0010A4 36               [12] 3251 	addc	a, @r0
      0010A5 FE               [12] 3252 	mov	r6,a
      0010A6 08               [12] 3253 	inc	r0
      0010A7 86 07            [24] 3254 	mov	ar7,@r0
      0010A9 8D 82            [24] 3255 	mov	dpl,r5
      0010AB 8E 83            [24] 3256 	mov	dph,r6
      0010AD 8F F0            [24] 3257 	mov	b,r7
      0010AF E5 1D            [12] 3258 	mov	a,_bp
      0010B1 24 0D            [12] 3259 	add	a,#0x0d
      0010B3 F8               [12] 3260 	mov	r0,a
      0010B4 12 1F FC         [24] 3261 	lcall	__gptrget
      0010B7 F6               [12] 3262 	mov	@r0,a
      0010B8 A8 1D            [24] 3263 	mov	r0,_bp
      0010BA 08               [12] 3264 	inc	r0
      0010BB 74 0E            [12] 3265 	mov	a,#0x0e
      0010BD 26               [12] 3266 	add	a, @r0
      0010BE FC               [12] 3267 	mov	r4,a
      0010BF E4               [12] 3268 	clr	a
      0010C0 08               [12] 3269 	inc	r0
      0010C1 36               [12] 3270 	addc	a, @r0
      0010C2 FE               [12] 3271 	mov	r6,a
      0010C3 08               [12] 3272 	inc	r0
      0010C4 86 07            [24] 3273 	mov	ar7,@r0
      0010C6 8C 82            [24] 3274 	mov	dpl,r4
      0010C8 8E 83            [24] 3275 	mov	dph,r6
      0010CA 8F F0            [24] 3276 	mov	b,r7
      0010CC E5 1D            [12] 3277 	mov	a,_bp
      0010CE 24 09            [12] 3278 	add	a,#0x09
      0010D0 F8               [12] 3279 	mov	r0,a
      0010D1 12 1F FC         [24] 3280 	lcall	__gptrget
      0010D4 F6               [12] 3281 	mov	@r0,a
      0010D5 A3               [24] 3282 	inc	dptr
      0010D6 12 1F FC         [24] 3283 	lcall	__gptrget
      0010D9 08               [12] 3284 	inc	r0
      0010DA F6               [12] 3285 	mov	@r0,a
      0010DB A3               [24] 3286 	inc	dptr
      0010DC 12 1F FC         [24] 3287 	lcall	__gptrget
      0010DF 08               [12] 3288 	inc	r0
      0010E0 F6               [12] 3289 	mov	@r0,a
      0010E1 A3               [24] 3290 	inc	dptr
      0010E2 12 1F FC         [24] 3291 	lcall	__gptrget
      0010E5 08               [12] 3292 	inc	r0
      0010E6 F6               [12] 3293 	mov	@r0,a
      0010E7 A8 1D            [24] 3294 	mov	r0,_bp
      0010E9 08               [12] 3295 	inc	r0
      0010EA 74 0A            [12] 3296 	mov	a,#0x0a
      0010EC 26               [12] 3297 	add	a, @r0
      0010ED FA               [12] 3298 	mov	r2,a
      0010EE E4               [12] 3299 	clr	a
      0010EF 08               [12] 3300 	inc	r0
      0010F0 36               [12] 3301 	addc	a, @r0
      0010F1 FD               [12] 3302 	mov	r5,a
      0010F2 08               [12] 3303 	inc	r0
      0010F3 86 07            [24] 3304 	mov	ar7,@r0
      0010F5 8A 82            [24] 3305 	mov	dpl,r2
      0010F7 8D 83            [24] 3306 	mov	dph,r5
      0010F9 8F F0            [24] 3307 	mov	b,r7
      0010FB E5 1D            [12] 3308 	mov	a,_bp
      0010FD 24 05            [12] 3309 	add	a,#0x05
      0010FF F8               [12] 3310 	mov	r0,a
      001100 12 1F FC         [24] 3311 	lcall	__gptrget
      001103 F6               [12] 3312 	mov	@r0,a
      001104 A3               [24] 3313 	inc	dptr
      001105 12 1F FC         [24] 3314 	lcall	__gptrget
      001108 08               [12] 3315 	inc	r0
      001109 F6               [12] 3316 	mov	@r0,a
      00110A A3               [24] 3317 	inc	dptr
      00110B 12 1F FC         [24] 3318 	lcall	__gptrget
      00110E 08               [12] 3319 	inc	r0
      00110F F6               [12] 3320 	mov	@r0,a
      001110 A3               [24] 3321 	inc	dptr
      001111 12 1F FC         [24] 3322 	lcall	__gptrget
      001114 08               [12] 3323 	inc	r0
      001115 F6               [12] 3324 	mov	@r0,a
      001116 A8 1D            [24] 3325 	mov	r0,_bp
      001118 08               [12] 3326 	inc	r0
      001119 74 06            [12] 3327 	mov	a,#0x06
      00111B 26               [12] 3328 	add	a, @r0
      00111C FB               [12] 3329 	mov	r3,a
      00111D E4               [12] 3330 	clr	a
      00111E 08               [12] 3331 	inc	r0
      00111F 36               [12] 3332 	addc	a, @r0
      001120 FC               [12] 3333 	mov	r4,a
      001121 08               [12] 3334 	inc	r0
      001122 86 07            [24] 3335 	mov	ar7,@r0
      001124 8B 82            [24] 3336 	mov	dpl,r3
      001126 8C 83            [24] 3337 	mov	dph,r4
      001128 8F F0            [24] 3338 	mov	b,r7
      00112A E5 1D            [12] 3339 	mov	a,_bp
      00112C 24 11            [12] 3340 	add	a,#0x11
      00112E F8               [12] 3341 	mov	r0,a
      00112F 12 1F FC         [24] 3342 	lcall	__gptrget
      001132 F6               [12] 3343 	mov	@r0,a
      001133 A3               [24] 3344 	inc	dptr
      001134 12 1F FC         [24] 3345 	lcall	__gptrget
      001137 08               [12] 3346 	inc	r0
      001138 F6               [12] 3347 	mov	@r0,a
      001139 A3               [24] 3348 	inc	dptr
      00113A 12 1F FC         [24] 3349 	lcall	__gptrget
      00113D 08               [12] 3350 	inc	r0
      00113E F6               [12] 3351 	mov	@r0,a
      00113F A3               [24] 3352 	inc	dptr
      001140 12 1F FC         [24] 3353 	lcall	__gptrget
      001143 08               [12] 3354 	inc	r0
      001144 F6               [12] 3355 	mov	@r0,a
      001145 A8 1D            [24] 3356 	mov	r0,_bp
      001147 08               [12] 3357 	inc	r0
      001148 74 02            [12] 3358 	mov	a,#0x02
      00114A 26               [12] 3359 	add	a, @r0
      00114B FA               [12] 3360 	mov	r2,a
      00114C E4               [12] 3361 	clr	a
      00114D 08               [12] 3362 	inc	r0
      00114E 36               [12] 3363 	addc	a, @r0
      00114F FD               [12] 3364 	mov	r5,a
      001150 08               [12] 3365 	inc	r0
      001151 86 07            [24] 3366 	mov	ar7,@r0
      001153 8A 82            [24] 3367 	mov	dpl,r2
      001155 8D 83            [24] 3368 	mov	dph,r5
      001157 8F F0            [24] 3369 	mov	b,r7
      001159 12 1F FC         [24] 3370 	lcall	__gptrget
      00115C FA               [12] 3371 	mov	r2,a
      00115D A3               [24] 3372 	inc	dptr
      00115E 12 1F FC         [24] 3373 	lcall	__gptrget
      001161 FD               [12] 3374 	mov	r5,a
      001162 A3               [24] 3375 	inc	dptr
      001163 12 1F FC         [24] 3376 	lcall	__gptrget
      001166 FF               [12] 3377 	mov	r7,a
      001167 A3               [24] 3378 	inc	dptr
      001168 12 1F FC         [24] 3379 	lcall	__gptrget
      00116B FE               [12] 3380 	mov	r6,a
      00116C E5 1D            [12] 3381 	mov	a,_bp
      00116E 24 0D            [12] 3382 	add	a,#0x0d
      001170 F8               [12] 3383 	mov	r0,a
      001171 E6               [12] 3384 	mov	a,@r0
      001172 C0 E0            [24] 3385 	push	acc
      001174 E5 1D            [12] 3386 	mov	a,_bp
      001176 24 FA            [12] 3387 	add	a,#0xfa
      001178 F8               [12] 3388 	mov	r0,a
      001179 E6               [12] 3389 	mov	a,@r0
      00117A C0 E0            [24] 3390 	push	acc
      00117C 08               [12] 3391 	inc	r0
      00117D E6               [12] 3392 	mov	a,@r0
      00117E C0 E0            [24] 3393 	push	acc
      001180 08               [12] 3394 	inc	r0
      001181 E6               [12] 3395 	mov	a,@r0
      001182 C0 E0            [24] 3396 	push	acc
      001184 08               [12] 3397 	inc	r0
      001185 E6               [12] 3398 	mov	a,@r0
      001186 C0 E0            [24] 3399 	push	acc
      001188 E5 1D            [12] 3400 	mov	a,_bp
      00118A 24 09            [12] 3401 	add	a,#0x09
      00118C F8               [12] 3402 	mov	r0,a
      00118D E6               [12] 3403 	mov	a,@r0
      00118E C0 E0            [24] 3404 	push	acc
      001190 08               [12] 3405 	inc	r0
      001191 E6               [12] 3406 	mov	a,@r0
      001192 C0 E0            [24] 3407 	push	acc
      001194 08               [12] 3408 	inc	r0
      001195 E6               [12] 3409 	mov	a,@r0
      001196 C0 E0            [24] 3410 	push	acc
      001198 08               [12] 3411 	inc	r0
      001199 E6               [12] 3412 	mov	a,@r0
      00119A C0 E0            [24] 3413 	push	acc
      00119C E5 1D            [12] 3414 	mov	a,_bp
      00119E 24 05            [12] 3415 	add	a,#0x05
      0011A0 F8               [12] 3416 	mov	r0,a
      0011A1 E6               [12] 3417 	mov	a,@r0
      0011A2 C0 E0            [24] 3418 	push	acc
      0011A4 08               [12] 3419 	inc	r0
      0011A5 E6               [12] 3420 	mov	a,@r0
      0011A6 C0 E0            [24] 3421 	push	acc
      0011A8 08               [12] 3422 	inc	r0
      0011A9 E6               [12] 3423 	mov	a,@r0
      0011AA C0 E0            [24] 3424 	push	acc
      0011AC 08               [12] 3425 	inc	r0
      0011AD E6               [12] 3426 	mov	a,@r0
      0011AE C0 E0            [24] 3427 	push	acc
      0011B0 E5 1D            [12] 3428 	mov	a,_bp
      0011B2 24 11            [12] 3429 	add	a,#0x11
      0011B4 F8               [12] 3430 	mov	r0,a
      0011B5 E6               [12] 3431 	mov	a,@r0
      0011B6 C0 E0            [24] 3432 	push	acc
      0011B8 08               [12] 3433 	inc	r0
      0011B9 E6               [12] 3434 	mov	a,@r0
      0011BA C0 E0            [24] 3435 	push	acc
      0011BC 08               [12] 3436 	inc	r0
      0011BD E6               [12] 3437 	mov	a,@r0
      0011BE C0 E0            [24] 3438 	push	acc
      0011C0 08               [12] 3439 	inc	r0
      0011C1 E6               [12] 3440 	mov	a,@r0
      0011C2 C0 E0            [24] 3441 	push	acc
      0011C4 8A 82            [24] 3442 	mov	dpl, r2
      0011C6 8D 83            [24] 3443 	mov	dph, r5
      0011C8 8F F0            [24] 3444 	mov	b, r7
      0011CA EE               [12] 3445 	mov	a, r6
      0011CB 12 0A C8         [24] 3446 	lcall	_fuzzy_trapezoid
      0011CE AC 82            [24] 3447 	mov	r4, dpl
      0011D0 AD 83            [24] 3448 	mov	r5, dph
      0011D2 AE F0            [24] 3449 	mov	r6, b
      0011D4 FF               [12] 3450 	mov	r7, a
      0011D5 E5 81            [12] 3451 	mov	a,sp
      0011D7 24 EF            [12] 3452 	add	a,#0xef
      0011D9 F5 81            [12] 3453 	mov	sp,a
      0011DB 8C 82            [24] 3454 	mov	dpl, r4
      0011DD 8D 83            [24] 3455 	mov	dph, r5
      0011DF 8E F0            [24] 3456 	mov	b, r6
      0011E1 EF               [12] 3457 	mov	a, r7
      0011E2 80 06            [24] 3458 	sjmp	00107$
      0011E4                       3459 00106$:
      0011E4 90 00 00         [24] 3460 	mov	dptr,#0x0000
      0011E7 E4               [12] 3461 	clr	a
      0011E8 F5 F0            [12] 3462 	mov	b,a
      0011EA                       3463 00107$:
      0011EA 85 1D 81         [24] 3464 	mov	sp,_bp
      0011ED D0 1D            [24] 3465 	pop	_bp
                           001138  3466 	C$fuzzy.h$72$1_0$35 ==.
                           001138  3467 	XFcontroller_8051$fuzzy_8051_eval$0$0 ==.
      0011EF 22               [24] 3468 	ret
                                   3469 ;------------------------------------------------------------
                                   3470 ;Allocation info for local variables in function 'fuzzy_rules_add_8051'
                                   3471 ;------------------------------------------------------------
                                   3472 ;value         Allocated to stack - _bp -6 +4 
                                   3473 ;output        Allocated to stack - _bp -9 +3 
                                   3474 ;rules         Allocated to stack - _bp +1 +3 
                                   3475 ;index         Allocated to registers r3 
                                   3476 ;sloc0         Allocated to stack - _bp +5 +1 
                                   3477 ;sloc1         Allocated to stack - _bp +4 +3 
                                   3478 ;sloc2         Allocated to stack - _bp +7 +3 
                                   3479 ;------------------------------------------------------------
                           001139  3480 	G$fuzzy_rules_add_8051$0$0 ==.
                           001139  3481 	C$fuzzy.h$73$1_0$37 ==.
                                   3482 ;	../../fuzzy.h:73: bool fuzzy_rules_add_8051(fuzzy_rules_t *rules, float value, const fuzzy_variable_8051_t *output) { uint8_t index; if (rules->count >= FUZZY_MAX_RULES) return false; index = rules->count; rules->rules[index].value = fuzzy_8051_clamp(value); rules->rules[index].output = output; rules->count = index + 1u; return true; }
                                   3483 ;	-----------------------------------------
                                   3484 ;	 function fuzzy_rules_add_8051
                                   3485 ;	-----------------------------------------
      0011F0                       3486 _fuzzy_rules_add_8051:
      0011F0 C0 1D            [24] 3487 	push	_bp
      0011F2 85 81 1D         [24] 3488 	mov	_bp,sp
      0011F5 C0 82            [24] 3489 	push	dpl
      0011F7 C0 83            [24] 3490 	push	dph
      0011F9 C0 F0            [24] 3491 	push	b
      0011FB E5 81            [12] 3492 	mov	a,sp
      0011FD 24 06            [12] 3493 	add	a,#0x06
      0011FF F5 81            [12] 3494 	mov	sp,a
      001201 A8 1D            [24] 3495 	mov	r0,_bp
      001203 08               [12] 3496 	inc	r0
      001204 E5 1D            [12] 3497 	mov	a,_bp
      001206 24 07            [12] 3498 	add	a,#0x07
      001208 F9               [12] 3499 	mov	r1,a
      001209 74 0E            [12] 3500 	mov	a,#0x0e
      00120B 26               [12] 3501 	add	a, @r0
      00120C F7               [12] 3502 	mov	@r1,a
      00120D E4               [12] 3503 	clr	a
      00120E 08               [12] 3504 	inc	r0
      00120F 36               [12] 3505 	addc	a, @r0
      001210 09               [12] 3506 	inc	r1
      001211 F7               [12] 3507 	mov	@r1,a
      001212 08               [12] 3508 	inc	r0
      001213 E6               [12] 3509 	mov	a,@r0
      001214 09               [12] 3510 	inc	r1
      001215 F7               [12] 3511 	mov	@r1,a
      001216 E5 1D            [12] 3512 	mov	a,_bp
      001218 24 07            [12] 3513 	add	a,#0x07
      00121A F8               [12] 3514 	mov	r0,a
      00121B 86 82            [24] 3515 	mov	dpl,@r0
      00121D 08               [12] 3516 	inc	r0
      00121E 86 83            [24] 3517 	mov	dph,@r0
      001220 08               [12] 3518 	inc	r0
      001221 86 F0            [24] 3519 	mov	b,@r0
      001223 12 1F FC         [24] 3520 	lcall	__gptrget
      001226 FF               [12] 3521 	mov	r7,a
      001227 BF 02 00         [24] 3522 	cjne	r7,#0x02,00111$
      00122A                       3523 00111$:
      00122A 40 06            [24] 3524 	jc	00102$
      00122C 75 82 00         [24] 3525 	mov	dpl, #0x00
      00122F 02 12 D5         [24] 3526 	ljmp	00103$
      001232                       3527 00102$:
      001232 8F 03            [24] 3528 	mov	ar3,r7
      001234 EB               [12] 3529 	mov	a,r3
      001235 75 F0 07         [24] 3530 	mov	b,#0x07
      001238 A4               [48] 3531 	mul	ab
      001239 FA               [12] 3532 	mov	r2,a
      00123A A8 1D            [24] 3533 	mov	r0,_bp
      00123C 08               [12] 3534 	inc	r0
      00123D E5 1D            [12] 3535 	mov	a,_bp
      00123F 24 04            [12] 3536 	add	a,#0x04
      001241 F9               [12] 3537 	mov	r1,a
      001242 EA               [12] 3538 	mov	a,r2
      001243 26               [12] 3539 	add	a, @r0
      001244 F7               [12] 3540 	mov	@r1,a
      001245 E4               [12] 3541 	clr	a
      001246 08               [12] 3542 	inc	r0
      001247 36               [12] 3543 	addc	a, @r0
      001248 09               [12] 3544 	inc	r1
      001249 F7               [12] 3545 	mov	@r1,a
      00124A 08               [12] 3546 	inc	r0
      00124B E6               [12] 3547 	mov	a,@r0
      00124C 09               [12] 3548 	inc	r1
      00124D F7               [12] 3549 	mov	@r1,a
      00124E E5 1D            [12] 3550 	mov	a,_bp
      001250 24 FA            [12] 3551 	add	a,#0xfa
      001252 F8               [12] 3552 	mov	r0,a
      001253 86 82            [24] 3553 	mov	dpl, @r0
      001255 08               [12] 3554 	inc	r0
      001256 86 83            [24] 3555 	mov	dph, @r0
      001258 08               [12] 3556 	inc	r0
      001259 86 F0            [24] 3557 	mov	b, @r0
      00125B 08               [12] 3558 	inc	r0
      00125C E6               [12] 3559 	mov	a, @r0
      00125D C0 03            [24] 3560 	push	ar3
      00125F C0 02            [24] 3561 	push	ar2
      001261 12 04 77         [24] 3562 	lcall	_fuzzy_8051_clamp
      001264 AD 82            [24] 3563 	mov	r5, dpl
      001266 AE 83            [24] 3564 	mov	r6, dph
      001268 AC F0            [24] 3565 	mov	r4, b
      00126A FF               [12] 3566 	mov	r7, a
      00126B D0 02            [24] 3567 	pop	ar2
      00126D D0 03            [24] 3568 	pop	ar3
      00126F E5 1D            [12] 3569 	mov	a,_bp
      001271 24 04            [12] 3570 	add	a,#0x04
      001273 F8               [12] 3571 	mov	r0,a
      001274 86 82            [24] 3572 	mov	dpl,@r0
      001276 08               [12] 3573 	inc	r0
      001277 86 83            [24] 3574 	mov	dph,@r0
      001279 08               [12] 3575 	inc	r0
      00127A 86 F0            [24] 3576 	mov	b,@r0
      00127C ED               [12] 3577 	mov	a,r5
      00127D 12 1D D7         [24] 3578 	lcall	__gptrput
      001280 A3               [24] 3579 	inc	dptr
      001281 EE               [12] 3580 	mov	a,r6
      001282 12 1D D7         [24] 3581 	lcall	__gptrput
      001285 A3               [24] 3582 	inc	dptr
      001286 EC               [12] 3583 	mov	a,r4
      001287 12 1D D7         [24] 3584 	lcall	__gptrput
      00128A A3               [24] 3585 	inc	dptr
      00128B EF               [12] 3586 	mov	a,r7
      00128C 12 1D D7         [24] 3587 	lcall	__gptrput
      00128F A8 1D            [24] 3588 	mov	r0,_bp
      001291 08               [12] 3589 	inc	r0
      001292 EA               [12] 3590 	mov	a,r2
      001293 26               [12] 3591 	add	a, @r0
      001294 FD               [12] 3592 	mov	r5,a
      001295 E4               [12] 3593 	clr	a
      001296 08               [12] 3594 	inc	r0
      001297 36               [12] 3595 	addc	a, @r0
      001298 FE               [12] 3596 	mov	r6,a
      001299 08               [12] 3597 	inc	r0
      00129A 86 07            [24] 3598 	mov	ar7,@r0
      00129C 74 04            [12] 3599 	mov	a,#0x04
      00129E 2D               [12] 3600 	add	a, r5
      00129F FD               [12] 3601 	mov	r5,a
      0012A0 E4               [12] 3602 	clr	a
      0012A1 3E               [12] 3603 	addc	a, r6
      0012A2 FE               [12] 3604 	mov	r6,a
      0012A3 8D 82            [24] 3605 	mov	dpl,r5
      0012A5 8E 83            [24] 3606 	mov	dph,r6
      0012A7 8F F0            [24] 3607 	mov	b,r7
      0012A9 E5 1D            [12] 3608 	mov	a,_bp
      0012AB 24 F7            [12] 3609 	add	a,#0xf7
      0012AD F8               [12] 3610 	mov	r0,a
      0012AE E6               [12] 3611 	mov	a,@r0
      0012AF 12 1D D7         [24] 3612 	lcall	__gptrput
      0012B2 A3               [24] 3613 	inc	dptr
      0012B3 08               [12] 3614 	inc	r0
      0012B4 E6               [12] 3615 	mov	a,@r0
      0012B5 12 1D D7         [24] 3616 	lcall	__gptrput
      0012B8 A3               [24] 3617 	inc	dptr
      0012B9 08               [12] 3618 	inc	r0
      0012BA E6               [12] 3619 	mov	a,@r0
      0012BB 12 1D D7         [24] 3620 	lcall	__gptrput
      0012BE EB               [12] 3621 	mov	a,r3
      0012BF 04               [12] 3622 	inc	a
      0012C0 FF               [12] 3623 	mov	r7,a
      0012C1 E5 1D            [12] 3624 	mov	a,_bp
      0012C3 24 07            [12] 3625 	add	a,#0x07
      0012C5 F8               [12] 3626 	mov	r0,a
      0012C6 86 82            [24] 3627 	mov	dpl,@r0
      0012C8 08               [12] 3628 	inc	r0
      0012C9 86 83            [24] 3629 	mov	dph,@r0
      0012CB 08               [12] 3630 	inc	r0
      0012CC 86 F0            [24] 3631 	mov	b,@r0
      0012CE EF               [12] 3632 	mov	a,r7
      0012CF 12 1D D7         [24] 3633 	lcall	__gptrput
      0012D2 75 82 01         [24] 3634 	mov	dpl, #0x01
      0012D5                       3635 00103$:
      0012D5 85 1D 81         [24] 3636 	mov	sp,_bp
      0012D8 D0 1D            [24] 3637 	pop	_bp
                           001223  3638 	C$fuzzy.h$73$1_0$37 ==.
                           001223  3639 	XG$fuzzy_rules_add_8051$0$0 ==.
      0012DA 22               [24] 3640 	ret
                                   3641 ;------------------------------------------------------------
                                   3642 ;Allocation info for local variables in function 'fuzzy_8051_height'
                                   3643 ;------------------------------------------------------------
                                   3644 ;x             Allocated to stack - _bp -6 +4 
                                   3645 ;rules         Allocated to stack - _bp +1 +3 
                                   3646 ;i             Allocated to registers r7 
                                   3647 ;aggregate     Allocated to stack - _bp +14 +4 
                                   3648 ;membership    Allocated to stack - _bp +18 +4 
                                   3649 ;implied       Allocated to registers r3 r4 r5 r6 
                                   3650 ;sloc0         Allocated to stack - _bp +4 +3 
                                   3651 ;sloc1         Allocated to stack - _bp +7 +3 
                                   3652 ;sloc2         Allocated to stack - _bp +10 +4 
                                   3653 ;------------------------------------------------------------
                           001224  3654 	Fcontroller_8051$fuzzy_8051_height$0$0 ==.
                           001224  3655 	C$fuzzy.h$74$1_0$39 ==.
                                   3656 ;	../../fuzzy.h:74: static float fuzzy_8051_height(const fuzzy_rules_t *rules, float x) { uint8_t i; float aggregate; float membership; float implied; aggregate = 0.0f; for (i = 0u; i < rules->count; ++i) { membership = fuzzy_8051_eval(rules->rules[i].output, x); implied = rules->rules[i].value < membership ? rules->rules[i].value : membership; if (implied > aggregate) aggregate = implied; } return aggregate; }
                                   3657 ;	-----------------------------------------
                                   3658 ;	 function fuzzy_8051_height
                                   3659 ;	-----------------------------------------
      0012DB                       3660 _fuzzy_8051_height:
      0012DB C0 1D            [24] 3661 	push	_bp
      0012DD 85 81 1D         [24] 3662 	mov	_bp,sp
      0012E0 C0 82            [24] 3663 	push	dpl
      0012E2 C0 83            [24] 3664 	push	dph
      0012E4 C0 F0            [24] 3665 	push	b
      0012E6 E5 81            [12] 3666 	mov	a,sp
      0012E8 24 12            [12] 3667 	add	a,#0x12
      0012EA F5 81            [12] 3668 	mov	sp,a
      0012EC E5 1D            [12] 3669 	mov	a,_bp
      0012EE 24 0E            [12] 3670 	add	a,#0x0e
      0012F0 F8               [12] 3671 	mov	r0,a
      0012F1 E4               [12] 3672 	clr	a
      0012F2 F6               [12] 3673 	mov	@r0,a
      0012F3 08               [12] 3674 	inc	r0
      0012F4 F6               [12] 3675 	mov	@r0,a
      0012F5 08               [12] 3676 	inc	r0
      0012F6 F6               [12] 3677 	mov	@r0,a
      0012F7 08               [12] 3678 	inc	r0
      0012F8 F6               [12] 3679 	mov	@r0,a
      0012F9 A8 1D            [24] 3680 	mov	r0,_bp
      0012FB 08               [12] 3681 	inc	r0
      0012FC E5 1D            [12] 3682 	mov	a,_bp
      0012FE 24 07            [12] 3683 	add	a,#0x07
      001300 F9               [12] 3684 	mov	r1,a
      001301 E6               [12] 3685 	mov	a,@r0
      001302 F7               [12] 3686 	mov	@r1,a
      001303 08               [12] 3687 	inc	r0
      001304 E6               [12] 3688 	mov	a,@r0
      001305 09               [12] 3689 	inc	r1
      001306 F7               [12] 3690 	mov	@r1,a
      001307 08               [12] 3691 	inc	r0
      001308 E6               [12] 3692 	mov	a,@r0
      001309 09               [12] 3693 	inc	r1
      00130A F7               [12] 3694 	mov	@r1,a
      00130B A8 1D            [24] 3695 	mov	r0,_bp
      00130D 08               [12] 3696 	inc	r0
      00130E E5 1D            [12] 3697 	mov	a,_bp
      001310 24 04            [12] 3698 	add	a,#0x04
      001312 F9               [12] 3699 	mov	r1,a
      001313 74 0E            [12] 3700 	mov	a,#0x0e
      001315 26               [12] 3701 	add	a, @r0
      001316 F7               [12] 3702 	mov	@r1,a
      001317 E4               [12] 3703 	clr	a
      001318 08               [12] 3704 	inc	r0
      001319 36               [12] 3705 	addc	a, @r0
      00131A 09               [12] 3706 	inc	r1
      00131B F7               [12] 3707 	mov	@r1,a
      00131C 08               [12] 3708 	inc	r0
      00131D E6               [12] 3709 	mov	a,@r0
      00131E 09               [12] 3710 	inc	r1
      00131F F7               [12] 3711 	mov	@r1,a
      001320 7F 00            [12] 3712 	mov	r7,#0x00
      001322                       3713 00105$:
      001322 E5 1D            [12] 3714 	mov	a,_bp
      001324 24 04            [12] 3715 	add	a,#0x04
      001326 F8               [12] 3716 	mov	r0,a
      001327 86 82            [24] 3717 	mov	dpl,@r0
      001329 08               [12] 3718 	inc	r0
      00132A 86 83            [24] 3719 	mov	dph,@r0
      00132C 08               [12] 3720 	inc	r0
      00132D 86 F0            [24] 3721 	mov	b,@r0
      00132F 12 1F FC         [24] 3722 	lcall	__gptrget
      001332 FE               [12] 3723 	mov	r6,a
      001333 C3               [12] 3724 	clr	c
      001334 EF               [12] 3725 	mov	a,r7
      001335 9E               [12] 3726 	subb	a,r6
      001336 40 03            [24] 3727 	jc	00136$
      001338 02 14 78         [24] 3728 	ljmp	00103$
      00133B                       3729 00136$:
      00133B EF               [12] 3730 	mov	a,r7
      00133C 75 F0 07         [24] 3731 	mov	b,#0x07
      00133F A4               [48] 3732 	mul	ab
      001340 FE               [12] 3733 	mov	r6,a
      001341 C0 07            [24] 3734 	push	ar7
      001343 E5 1D            [12] 3735 	mov	a,_bp
      001345 24 07            [12] 3736 	add	a,#0x07
      001347 F8               [12] 3737 	mov	r0,a
      001348 EE               [12] 3738 	mov	a,r6
      001349 26               [12] 3739 	add	a, @r0
      00134A FC               [12] 3740 	mov	r4,a
      00134B E4               [12] 3741 	clr	a
      00134C 08               [12] 3742 	inc	r0
      00134D 36               [12] 3743 	addc	a, @r0
      00134E FD               [12] 3744 	mov	r5,a
      00134F 08               [12] 3745 	inc	r0
      001350 86 07            [24] 3746 	mov	ar7,@r0
      001352 74 04            [12] 3747 	mov	a,#0x04
      001354 2C               [12] 3748 	add	a, r4
      001355 FC               [12] 3749 	mov	r4,a
      001356 E4               [12] 3750 	clr	a
      001357 3D               [12] 3751 	addc	a, r5
      001358 FD               [12] 3752 	mov	r5,a
      001359 8C 82            [24] 3753 	mov	dpl,r4
      00135B 8D 83            [24] 3754 	mov	dph,r5
      00135D 8F F0            [24] 3755 	mov	b,r7
      00135F 12 1F FC         [24] 3756 	lcall	__gptrget
      001362 FC               [12] 3757 	mov	r4,a
      001363 A3               [24] 3758 	inc	dptr
      001364 12 1F FC         [24] 3759 	lcall	__gptrget
      001367 FD               [12] 3760 	mov	r5,a
      001368 A3               [24] 3761 	inc	dptr
      001369 12 1F FC         [24] 3762 	lcall	__gptrget
      00136C FF               [12] 3763 	mov	r7,a
      00136D C0 07            [24] 3764 	push	ar7
      00136F C0 06            [24] 3765 	push	ar6
      001371 E5 1D            [12] 3766 	mov	a,_bp
      001373 24 FA            [12] 3767 	add	a,#0xfa
      001375 F8               [12] 3768 	mov	r0,a
      001376 E6               [12] 3769 	mov	a,@r0
      001377 C0 E0            [24] 3770 	push	acc
      001379 08               [12] 3771 	inc	r0
      00137A E6               [12] 3772 	mov	a,@r0
      00137B C0 E0            [24] 3773 	push	acc
      00137D 08               [12] 3774 	inc	r0
      00137E E6               [12] 3775 	mov	a,@r0
      00137F C0 E0            [24] 3776 	push	acc
      001381 08               [12] 3777 	inc	r0
      001382 E6               [12] 3778 	mov	a,@r0
      001383 C0 E0            [24] 3779 	push	acc
      001385 8C 82            [24] 3780 	mov	dpl, r4
      001387 8D 83            [24] 3781 	mov	dph, r5
      001389 8F F0            [24] 3782 	mov	b, r7
      00138B 12 0E 5F         [24] 3783 	lcall	_fuzzy_8051_eval
      00138E C8               [12] 3784 	xch	a,r0
      00138F E5 1D            [12] 3785 	mov	a,_bp
      001391 24 12            [12] 3786 	add	a,#0x12
      001393 C8               [12] 3787 	xch	a,r0
      001394 A6 82            [24] 3788 	mov	@r0, dpl
      001396 08               [12] 3789 	inc	r0
      001397 A6 83            [24] 3790 	mov	@r0, dph
      001399 08               [12] 3791 	inc	r0
      00139A A6 F0            [24] 3792 	mov	@r0, b
      00139C 08               [12] 3793 	inc	r0
      00139D F6               [12] 3794 	mov	@r0,a
      00139E E5 81            [12] 3795 	mov	a,sp
      0013A0 24 FC            [12] 3796 	add	a,#0xfc
      0013A2 F5 81            [12] 3797 	mov	sp,a
      0013A4 D0 06            [24] 3798 	pop	ar6
      0013A6 D0 07            [24] 3799 	pop	ar7
      0013A8 A8 1D            [24] 3800 	mov	r0,_bp
      0013AA 08               [12] 3801 	inc	r0
      0013AB EE               [12] 3802 	mov	a,r6
      0013AC 26               [12] 3803 	add	a, @r0
      0013AD FE               [12] 3804 	mov	r6,a
      0013AE E4               [12] 3805 	clr	a
      0013AF 08               [12] 3806 	inc	r0
      0013B0 36               [12] 3807 	addc	a, @r0
      0013B1 FF               [12] 3808 	mov	r7,a
      0013B2 08               [12] 3809 	inc	r0
      0013B3 86 05            [24] 3810 	mov	ar5,@r0
      0013B5 8E 82            [24] 3811 	mov	dpl,r6
      0013B7 8F 83            [24] 3812 	mov	dph,r7
      0013B9 8D F0            [24] 3813 	mov	b,r5
      0013BB E5 1D            [12] 3814 	mov	a,_bp
      0013BD 24 0A            [12] 3815 	add	a,#0x0a
      0013BF F8               [12] 3816 	mov	r0,a
      0013C0 12 1F FC         [24] 3817 	lcall	__gptrget
      0013C3 F6               [12] 3818 	mov	@r0,a
      0013C4 A3               [24] 3819 	inc	dptr
      0013C5 12 1F FC         [24] 3820 	lcall	__gptrget
      0013C8 08               [12] 3821 	inc	r0
      0013C9 F6               [12] 3822 	mov	@r0,a
      0013CA A3               [24] 3823 	inc	dptr
      0013CB 12 1F FC         [24] 3824 	lcall	__gptrget
      0013CE 08               [12] 3825 	inc	r0
      0013CF F6               [12] 3826 	mov	@r0,a
      0013D0 A3               [24] 3827 	inc	dptr
      0013D1 12 1F FC         [24] 3828 	lcall	__gptrget
      0013D4 08               [12] 3829 	inc	r0
      0013D5 F6               [12] 3830 	mov	@r0,a
      0013D6 E5 1D            [12] 3831 	mov	a,_bp
      0013D8 24 12            [12] 3832 	add	a,#0x12
      0013DA F8               [12] 3833 	mov	r0,a
      0013DB E6               [12] 3834 	mov	a,@r0
      0013DC C0 E0            [24] 3835 	push	acc
      0013DE 08               [12] 3836 	inc	r0
      0013DF E6               [12] 3837 	mov	a,@r0
      0013E0 C0 E0            [24] 3838 	push	acc
      0013E2 08               [12] 3839 	inc	r0
      0013E3 E6               [12] 3840 	mov	a,@r0
      0013E4 C0 E0            [24] 3841 	push	acc
      0013E6 08               [12] 3842 	inc	r0
      0013E7 E6               [12] 3843 	mov	a,@r0
      0013E8 C0 E0            [24] 3844 	push	acc
      0013EA E5 1D            [12] 3845 	mov	a,_bp
      0013EC 24 0A            [12] 3846 	add	a,#0x0a
      0013EE F8               [12] 3847 	mov	r0,a
      0013EF 86 82            [24] 3848 	mov	dpl, @r0
      0013F1 08               [12] 3849 	inc	r0
      0013F2 86 83            [24] 3850 	mov	dph, @r0
      0013F4 08               [12] 3851 	inc	r0
      0013F5 86 F0            [24] 3852 	mov	b, @r0
      0013F7 08               [12] 3853 	inc	r0
      0013F8 E6               [12] 3854 	mov	a, @r0
      0013F9 12 1D F2         [24] 3855 	lcall	___fslt
      0013FC AF 82            [24] 3856 	mov	r7, dpl
      0013FE E5 81            [12] 3857 	mov	a,sp
      001400 24 FC            [12] 3858 	add	a,#0xfc
      001402 F5 81            [12] 3859 	mov	sp,a
      001404 EF               [12] 3860 	mov	a,r7
      001405 D0 07            [24] 3861 	pop	ar7
      001407 60 12            [24] 3862 	jz	00109$
      001409 E5 1D            [12] 3863 	mov	a,_bp
      00140B 24 0A            [12] 3864 	add	a,#0x0a
      00140D F8               [12] 3865 	mov	r0,a
      00140E 86 03            [24] 3866 	mov	ar3,@r0
      001410 08               [12] 3867 	inc	r0
      001411 86 04            [24] 3868 	mov	ar4,@r0
      001413 08               [12] 3869 	inc	r0
      001414 86 05            [24] 3870 	mov	ar5,@r0
      001416 08               [12] 3871 	inc	r0
      001417 86 06            [24] 3872 	mov	ar6,@r0
      001419 80 10            [24] 3873 	sjmp	00110$
      00141B                       3874 00109$:
      00141B E5 1D            [12] 3875 	mov	a,_bp
      00141D 24 12            [12] 3876 	add	a,#0x12
      00141F F8               [12] 3877 	mov	r0,a
      001420 86 03            [24] 3878 	mov	ar3,@r0
      001422 08               [12] 3879 	inc	r0
      001423 86 04            [24] 3880 	mov	ar4,@r0
      001425 08               [12] 3881 	inc	r0
      001426 86 05            [24] 3882 	mov	ar5,@r0
      001428 08               [12] 3883 	inc	r0
      001429 86 06            [24] 3884 	mov	ar6,@r0
      00142B                       3885 00110$:
      00142B C0 07            [24] 3886 	push	ar7
      00142D C0 06            [24] 3887 	push	ar6
      00142F C0 05            [24] 3888 	push	ar5
      001431 C0 04            [24] 3889 	push	ar4
      001433 C0 03            [24] 3890 	push	ar3
      001435 C0 03            [24] 3891 	push	ar3
      001437 C0 04            [24] 3892 	push	ar4
      001439 C0 05            [24] 3893 	push	ar5
      00143B C0 06            [24] 3894 	push	ar6
      00143D E5 1D            [12] 3895 	mov	a,_bp
      00143F 24 0E            [12] 3896 	add	a,#0x0e
      001441 F8               [12] 3897 	mov	r0,a
      001442 86 82            [24] 3898 	mov	dpl, @r0
      001444 08               [12] 3899 	inc	r0
      001445 86 83            [24] 3900 	mov	dph, @r0
      001447 08               [12] 3901 	inc	r0
      001448 86 F0            [24] 3902 	mov	b, @r0
      00144A 08               [12] 3903 	inc	r0
      00144B E6               [12] 3904 	mov	a, @r0
      00144C 12 1D F2         [24] 3905 	lcall	___fslt
      00144F AA 82            [24] 3906 	mov	r2, dpl
      001451 E5 81            [12] 3907 	mov	a,sp
      001453 24 FC            [12] 3908 	add	a,#0xfc
      001455 F5 81            [12] 3909 	mov	sp,a
      001457 D0 03            [24] 3910 	pop	ar3
      001459 D0 04            [24] 3911 	pop	ar4
      00145B D0 05            [24] 3912 	pop	ar5
      00145D D0 06            [24] 3913 	pop	ar6
      00145F D0 07            [24] 3914 	pop	ar7
      001461 EA               [12] 3915 	mov	a,r2
      001462 60 10            [24] 3916 	jz	00106$
      001464 E5 1D            [12] 3917 	mov	a,_bp
      001466 24 0E            [12] 3918 	add	a,#0x0e
      001468 F8               [12] 3919 	mov	r0,a
      001469 A6 03            [24] 3920 	mov	@r0,ar3
      00146B 08               [12] 3921 	inc	r0
      00146C A6 04            [24] 3922 	mov	@r0,ar4
      00146E 08               [12] 3923 	inc	r0
      00146F A6 05            [24] 3924 	mov	@r0,ar5
      001471 08               [12] 3925 	inc	r0
      001472 A6 06            [24] 3926 	mov	@r0,ar6
      001474                       3927 00106$:
      001474 0F               [12] 3928 	inc	r7
      001475 02 13 22         [24] 3929 	ljmp	00105$
      001478                       3930 00103$:
      001478 E5 1D            [12] 3931 	mov	a,_bp
      00147A 24 0E            [12] 3932 	add	a,#0x0e
      00147C F8               [12] 3933 	mov	r0,a
      00147D 86 82            [24] 3934 	mov	dpl, @r0
      00147F 08               [12] 3935 	inc	r0
      001480 86 83            [24] 3936 	mov	dph, @r0
      001482 08               [12] 3937 	inc	r0
      001483 86 F0            [24] 3938 	mov	b, @r0
      001485 08               [12] 3939 	inc	r0
      001486 E6               [12] 3940 	mov	a, @r0
      001487 85 1D 81         [24] 3941 	mov	sp,_bp
      00148A D0 1D            [24] 3942 	pop	_bp
                           0013D5  3943 	C$fuzzy.h$74$1_0$39 ==.
                           0013D5  3944 	XFcontroller_8051$fuzzy_8051_height$0$0 ==.
      00148C 22               [24] 3945 	ret
                                   3946 ;------------------------------------------------------------
                                   3947 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify'
                                   3948 ;------------------------------------------------------------
                                   3949 ;lower         Allocated to stack - _bp -6 +4 
                                   3950 ;upper         Allocated to stack - _bp -10 +4 
                                   3951 ;step          Allocated to stack - _bp -14 +4 
                                   3952 ;method        Allocated to stack - _bp -15 +1 
                                   3953 ;rules         Allocated to stack - _bp +1 +3 
                                   3954 ;x             Allocated to stack - _bp +4 +4 
                                   3955 ;h             Allocated to stack - _bp +8 +4 
                                   3956 ;weighted      Allocated to stack - _bp +12 +4 
                                   3957 ;sum           Allocated to stack - _bp +16 +4 
                                   3958 ;maximum       Allocated to stack - _bp +20 +4 
                                   3959 ;maximum_sum   Allocated to stack - _bp +24 +4 
                                   3960 ;smallest      Allocated to stack - _bp +28 +4 
                                   3961 ;largest       Allocated to stack - _bp +32 +4 
                                   3962 ;maximum_count Allocated to registers r5 r4 
                                   3963 ;------------------------------------------------------------
                           0013D6  3964 	G$fuzzy_rules_defuzzify$0$0 ==.
                           0013D6  3965 	C$fuzzy.h$75$1_0$43 ==.
                                   3966 ;	../../fuzzy.h:75: float fuzzy_rules_defuzzify(const fuzzy_rules_t *rules, float lower, float upper, float step, fuzzy_defuzz_method_t method) { float x; float h; float weighted; float sum; float maximum; float maximum_sum; float smallest; float largest; unsigned int maximum_count; if (rules->count == 0u || lower > upper || step <= 0.0f) return 0.0f; weighted = 0.0f; sum = 0.0f; maximum = -1.0f; maximum_sum = 0.0f; maximum_count = 0u; smallest = lower; largest = lower; for (x = lower; x <= upper; x += step) { h = fuzzy_8051_height(rules, x); weighted += x * h; sum += h; if (h > maximum) { maximum = h; maximum_sum = x; maximum_count = 1u; smallest = x; largest = x; } else if (h == maximum) { maximum_sum += x; ++maximum_count; largest = x; } } if (method == FUZZY_DEFUZZ_MOM) return maximum > 0.0f ? maximum_sum / (float)maximum_count : 0.0f; if (method == FUZZY_DEFUZZ_SOM) return maximum > 0.0f ? smallest : 0.0f; if (method == FUZZY_DEFUZZ_LOM) return maximum > 0.0f ? largest : 0.0f; return sum > 0.0f ? weighted / sum : 0.0f; }
                                   3967 ;	-----------------------------------------
                                   3968 ;	 function fuzzy_rules_defuzzify
                                   3969 ;	-----------------------------------------
      00148D                       3970 _fuzzy_rules_defuzzify:
      00148D C0 1D            [24] 3971 	push	_bp
      00148F 85 81 1D         [24] 3972 	mov	_bp,sp
      001492 C0 82            [24] 3973 	push	dpl
      001494 C0 83            [24] 3974 	push	dph
      001496 C0 F0            [24] 3975 	push	b
      001498 E5 81            [12] 3976 	mov	a,sp
      00149A 24 20            [12] 3977 	add	a,#0x20
      00149C F5 81            [12] 3978 	mov	sp,a
      00149E A8 1D            [24] 3979 	mov	r0,_bp
      0014A0 08               [12] 3980 	inc	r0
      0014A1 74 0E            [12] 3981 	mov	a,#0x0e
      0014A3 26               [12] 3982 	add	a, @r0
      0014A4 FA               [12] 3983 	mov	r2,a
      0014A5 E4               [12] 3984 	clr	a
      0014A6 08               [12] 3985 	inc	r0
      0014A7 36               [12] 3986 	addc	a, @r0
      0014A8 FB               [12] 3987 	mov	r3,a
      0014A9 08               [12] 3988 	inc	r0
      0014AA 86 04            [24] 3989 	mov	ar4,@r0
      0014AC 8A 82            [24] 3990 	mov	dpl,r2
      0014AE 8B 83            [24] 3991 	mov	dph,r3
      0014B0 8C F0            [24] 3992 	mov	b,r4
      0014B2 12 1F FC         [24] 3993 	lcall	__gptrget
      0014B5 60 5C            [24] 3994 	jz	00101$
      0014B7 E5 1D            [12] 3995 	mov	a,_bp
      0014B9 24 FA            [12] 3996 	add	a,#0xfa
      0014BB F8               [12] 3997 	mov	r0,a
      0014BC E6               [12] 3998 	mov	a,@r0
      0014BD C0 E0            [24] 3999 	push	acc
      0014BF 08               [12] 4000 	inc	r0
      0014C0 E6               [12] 4001 	mov	a,@r0
      0014C1 C0 E0            [24] 4002 	push	acc
      0014C3 08               [12] 4003 	inc	r0
      0014C4 E6               [12] 4004 	mov	a,@r0
      0014C5 C0 E0            [24] 4005 	push	acc
      0014C7 08               [12] 4006 	inc	r0
      0014C8 E6               [12] 4007 	mov	a,@r0
      0014C9 C0 E0            [24] 4008 	push	acc
      0014CB E5 1D            [12] 4009 	mov	a,_bp
      0014CD 24 F6            [12] 4010 	add	a,#0xf6
      0014CF F8               [12] 4011 	mov	r0,a
      0014D0 86 82            [24] 4012 	mov	dpl, @r0
      0014D2 08               [12] 4013 	inc	r0
      0014D3 86 83            [24] 4014 	mov	dph, @r0
      0014D5 08               [12] 4015 	inc	r0
      0014D6 86 F0            [24] 4016 	mov	b, @r0
      0014D8 08               [12] 4017 	inc	r0
      0014D9 E6               [12] 4018 	mov	a, @r0
      0014DA 12 1D F2         [24] 4019 	lcall	___fslt
      0014DD AC 82            [24] 4020 	mov	r4, dpl
      0014DF E5 81            [12] 4021 	mov	a,sp
      0014E1 24 FC            [12] 4022 	add	a,#0xfc
      0014E3 F5 81            [12] 4023 	mov	sp,a
      0014E5 EC               [12] 4024 	mov	a,r4
      0014E6 70 2B            [24] 4025 	jnz	00101$
      0014E8 E5 1D            [12] 4026 	mov	a,_bp
      0014EA 24 F2            [12] 4027 	add	a,#0xf2
      0014EC F8               [12] 4028 	mov	r0,a
      0014ED E6               [12] 4029 	mov	a,@r0
      0014EE C0 E0            [24] 4030 	push	acc
      0014F0 08               [12] 4031 	inc	r0
      0014F1 E6               [12] 4032 	mov	a,@r0
      0014F2 C0 E0            [24] 4033 	push	acc
      0014F4 08               [12] 4034 	inc	r0
      0014F5 E6               [12] 4035 	mov	a,@r0
      0014F6 C0 E0            [24] 4036 	push	acc
      0014F8 08               [12] 4037 	inc	r0
      0014F9 E6               [12] 4038 	mov	a,@r0
      0014FA C0 E0            [24] 4039 	push	acc
      0014FC 90 00 00         [24] 4040 	mov	dptr,#0x0000
      0014FF E4               [12] 4041 	clr	a
      001500 F5 F0            [12] 4042 	mov	b,a
      001502 12 1D F2         [24] 4043 	lcall	___fslt
      001505 E5 81            [12] 4044 	mov	a,sp
      001507 24 FC            [12] 4045 	add	a,#0xfc
      001509 F5 81            [12] 4046 	mov	sp,a
      00150B E5 82            [12] 4047 	mov	a, dpl
      00150D 24 FF            [12] 4048 	add	a,#0xff
      00150F 92 00            [24] 4049 	mov	b0,c
      001511 40 09            [24] 4050 	jc	00102$
      001513                       4051 00101$:
      001513 90 00 00         [24] 4052 	mov	dptr,#0x0000
      001516 E4               [12] 4053 	clr	a
      001517 F5 F0            [12] 4054 	mov	b,a
      001519 02 19 CB         [24] 4055 	ljmp	00120$
      00151C                       4056 00102$:
      00151C E5 1D            [12] 4057 	mov	a,_bp
      00151E 24 0C            [12] 4058 	add	a,#0x0c
      001520 F8               [12] 4059 	mov	r0,a
      001521 E4               [12] 4060 	clr	a
      001522 F6               [12] 4061 	mov	@r0,a
      001523 08               [12] 4062 	inc	r0
      001524 F6               [12] 4063 	mov	@r0,a
      001525 08               [12] 4064 	inc	r0
      001526 F6               [12] 4065 	mov	@r0,a
      001527 08               [12] 4066 	inc	r0
      001528 F6               [12] 4067 	mov	@r0,a
      001529 E5 1D            [12] 4068 	mov	a,_bp
      00152B 24 10            [12] 4069 	add	a,#0x10
      00152D F8               [12] 4070 	mov	r0,a
      00152E E4               [12] 4071 	clr	a
      00152F F6               [12] 4072 	mov	@r0,a
      001530 08               [12] 4073 	inc	r0
      001531 F6               [12] 4074 	mov	@r0,a
      001532 08               [12] 4075 	inc	r0
      001533 F6               [12] 4076 	mov	@r0,a
      001534 08               [12] 4077 	inc	r0
      001535 F6               [12] 4078 	mov	@r0,a
      001536 E5 1D            [12] 4079 	mov	a,_bp
      001538 24 14            [12] 4080 	add	a,#0x14
      00153A F8               [12] 4081 	mov	r0,a
      00153B E4               [12] 4082 	clr	a
      00153C F6               [12] 4083 	mov	@r0,a
      00153D 08               [12] 4084 	inc	r0
      00153E F6               [12] 4085 	mov	@r0,a
      00153F 08               [12] 4086 	inc	r0
      001540 76 80            [12] 4087 	mov	@r0,#0x80
      001542 08               [12] 4088 	inc	r0
      001543 76 BF            [12] 4089 	mov	@r0,#0xbf
      001545 E5 1D            [12] 4090 	mov	a,_bp
      001547 24 18            [12] 4091 	add	a,#0x18
      001549 F8               [12] 4092 	mov	r0,a
      00154A E4               [12] 4093 	clr	a
      00154B F6               [12] 4094 	mov	@r0,a
      00154C 08               [12] 4095 	inc	r0
      00154D F6               [12] 4096 	mov	@r0,a
      00154E 08               [12] 4097 	inc	r0
      00154F F6               [12] 4098 	mov	@r0,a
      001550 08               [12] 4099 	inc	r0
      001551 F6               [12] 4100 	mov	@r0,a
      001552 FD               [12] 4101 	mov	r5,a
      001553 FC               [12] 4102 	mov	r4,a
      001554 E5 1D            [12] 4103 	mov	a,_bp
      001556 24 FA            [12] 4104 	add	a,#0xfa
      001558 F8               [12] 4105 	mov	r0,a
      001559 E5 1D            [12] 4106 	mov	a,_bp
      00155B 24 1C            [12] 4107 	add	a,#0x1c
      00155D F9               [12] 4108 	mov	r1,a
      00155E E6               [12] 4109 	mov	a,@r0
      00155F F7               [12] 4110 	mov	@r1,a
      001560 08               [12] 4111 	inc	r0
      001561 E6               [12] 4112 	mov	a,@r0
      001562 09               [12] 4113 	inc	r1
      001563 F7               [12] 4114 	mov	@r1,a
      001564 08               [12] 4115 	inc	r0
      001565 E6               [12] 4116 	mov	a,@r0
      001566 09               [12] 4117 	inc	r1
      001567 F7               [12] 4118 	mov	@r1,a
      001568 08               [12] 4119 	inc	r0
      001569 E6               [12] 4120 	mov	a,@r0
      00156A 09               [12] 4121 	inc	r1
      00156B F7               [12] 4122 	mov	@r1,a
      00156C E5 1D            [12] 4123 	mov	a,_bp
      00156E 24 1C            [12] 4124 	add	a,#0x1c
      001570 F8               [12] 4125 	mov	r0,a
      001571 E5 1D            [12] 4126 	mov	a,_bp
      001573 24 20            [12] 4127 	add	a,#0x20
      001575 F9               [12] 4128 	mov	r1,a
      001576 E6               [12] 4129 	mov	a,@r0
      001577 F7               [12] 4130 	mov	@r1,a
      001578 08               [12] 4131 	inc	r0
      001579 E6               [12] 4132 	mov	a,@r0
      00157A 09               [12] 4133 	inc	r1
      00157B F7               [12] 4134 	mov	@r1,a
      00157C 08               [12] 4135 	inc	r0
      00157D E6               [12] 4136 	mov	a,@r0
      00157E 09               [12] 4137 	inc	r1
      00157F F7               [12] 4138 	mov	@r1,a
      001580 08               [12] 4139 	inc	r0
      001581 E6               [12] 4140 	mov	a,@r0
      001582 09               [12] 4141 	inc	r1
      001583 F7               [12] 4142 	mov	@r1,a
      001584 E5 1D            [12] 4143 	mov	a,_bp
      001586 24 1C            [12] 4144 	add	a,#0x1c
      001588 F8               [12] 4145 	mov	r0,a
      001589 E5 1D            [12] 4146 	mov	a,_bp
      00158B 24 04            [12] 4147 	add	a,#0x04
      00158D F9               [12] 4148 	mov	r1,a
      00158E E6               [12] 4149 	mov	a,@r0
      00158F F7               [12] 4150 	mov	@r1,a
      001590 08               [12] 4151 	inc	r0
      001591 E6               [12] 4152 	mov	a,@r0
      001592 09               [12] 4153 	inc	r1
      001593 F7               [12] 4154 	mov	@r1,a
      001594 08               [12] 4155 	inc	r0
      001595 E6               [12] 4156 	mov	a,@r0
      001596 09               [12] 4157 	inc	r1
      001597 F7               [12] 4158 	mov	@r1,a
      001598 08               [12] 4159 	inc	r0
      001599 E6               [12] 4160 	mov	a,@r0
      00159A 09               [12] 4161 	inc	r1
      00159B F7               [12] 4162 	mov	@r1,a
      00159C                       4163 00118$:
      00159C C0 05            [24] 4164 	push	ar5
      00159E C0 04            [24] 4165 	push	ar4
      0015A0 E5 1D            [12] 4166 	mov	a,_bp
      0015A2 24 04            [12] 4167 	add	a,#0x04
      0015A4 F8               [12] 4168 	mov	r0,a
      0015A5 E6               [12] 4169 	mov	a,@r0
      0015A6 C0 E0            [24] 4170 	push	acc
      0015A8 08               [12] 4171 	inc	r0
      0015A9 E6               [12] 4172 	mov	a,@r0
      0015AA C0 E0            [24] 4173 	push	acc
      0015AC 08               [12] 4174 	inc	r0
      0015AD E6               [12] 4175 	mov	a,@r0
      0015AE C0 E0            [24] 4176 	push	acc
      0015B0 08               [12] 4177 	inc	r0
      0015B1 E6               [12] 4178 	mov	a,@r0
      0015B2 C0 E0            [24] 4179 	push	acc
      0015B4 E5 1D            [12] 4180 	mov	a,_bp
      0015B6 24 F6            [12] 4181 	add	a,#0xf6
      0015B8 F8               [12] 4182 	mov	r0,a
      0015B9 86 82            [24] 4183 	mov	dpl, @r0
      0015BB 08               [12] 4184 	inc	r0
      0015BC 86 83            [24] 4185 	mov	dph, @r0
      0015BE 08               [12] 4186 	inc	r0
      0015BF 86 F0            [24] 4187 	mov	b, @r0
      0015C1 08               [12] 4188 	inc	r0
      0015C2 E6               [12] 4189 	mov	a, @r0
      0015C3 12 1D F2         [24] 4190 	lcall	___fslt
      0015C6 E5 81            [12] 4191 	mov	a,sp
      0015C8 24 FC            [12] 4192 	add	a,#0xfc
      0015CA F5 81            [12] 4193 	mov	sp,a
      0015CC D0 04            [24] 4194 	pop	ar4
      0015CE D0 05            [24] 4195 	pop	ar5
      0015D0 E5 82            [12] 4196 	mov	a, dpl
      0015D2 24 FF            [12] 4197 	add	a,#0xff
      0015D4 92 00            [24] 4198 	mov	b0,c
      0015D6 50 03            [24] 4199 	jnc	00211$
      0015D8 02 18 33         [24] 4200 	ljmp	00110$
      0015DB                       4201 00211$:
      0015DB C0 05            [24] 4202 	push	ar5
      0015DD C0 04            [24] 4203 	push	ar4
      0015DF E5 1D            [12] 4204 	mov	a,_bp
      0015E1 24 04            [12] 4205 	add	a,#0x04
      0015E3 F8               [12] 4206 	mov	r0,a
      0015E4 E6               [12] 4207 	mov	a,@r0
      0015E5 C0 E0            [24] 4208 	push	acc
      0015E7 08               [12] 4209 	inc	r0
      0015E8 E6               [12] 4210 	mov	a,@r0
      0015E9 C0 E0            [24] 4211 	push	acc
      0015EB 08               [12] 4212 	inc	r0
      0015EC E6               [12] 4213 	mov	a,@r0
      0015ED C0 E0            [24] 4214 	push	acc
      0015EF 08               [12] 4215 	inc	r0
      0015F0 E6               [12] 4216 	mov	a,@r0
      0015F1 C0 E0            [24] 4217 	push	acc
      0015F3 A8 1D            [24] 4218 	mov	r0,_bp
      0015F5 08               [12] 4219 	inc	r0
      0015F6 86 82            [24] 4220 	mov	dpl, @r0
      0015F8 08               [12] 4221 	inc	r0
      0015F9 86 83            [24] 4222 	mov	dph, @r0
      0015FB 08               [12] 4223 	inc	r0
      0015FC 86 F0            [24] 4224 	mov	b, @r0
      0015FE 12 12 DB         [24] 4225 	lcall	_fuzzy_8051_height
      001601 C8               [12] 4226 	xch	a,r0
      001602 E5 1D            [12] 4227 	mov	a,_bp
      001604 24 08            [12] 4228 	add	a,#0x08
      001606 C8               [12] 4229 	xch	a,r0
      001607 A6 82            [24] 4230 	mov	@r0, dpl
      001609 08               [12] 4231 	inc	r0
      00160A A6 83            [24] 4232 	mov	@r0, dph
      00160C 08               [12] 4233 	inc	r0
      00160D A6 F0            [24] 4234 	mov	@r0, b
      00160F 08               [12] 4235 	inc	r0
      001610 F6               [12] 4236 	mov	@r0,a
      001611 E5 81            [12] 4237 	mov	a,sp
      001613 24 FC            [12] 4238 	add	a,#0xfc
      001615 F5 81            [12] 4239 	mov	sp,a
      001617 E5 1D            [12] 4240 	mov	a,_bp
      001619 24 08            [12] 4241 	add	a,#0x08
      00161B F8               [12] 4242 	mov	r0,a
      00161C E6               [12] 4243 	mov	a,@r0
      00161D C0 E0            [24] 4244 	push	acc
      00161F 08               [12] 4245 	inc	r0
      001620 E6               [12] 4246 	mov	a,@r0
      001621 C0 E0            [24] 4247 	push	acc
      001623 08               [12] 4248 	inc	r0
      001624 E6               [12] 4249 	mov	a,@r0
      001625 C0 E0            [24] 4250 	push	acc
      001627 08               [12] 4251 	inc	r0
      001628 E6               [12] 4252 	mov	a,@r0
      001629 C0 E0            [24] 4253 	push	acc
      00162B E5 1D            [12] 4254 	mov	a,_bp
      00162D 24 04            [12] 4255 	add	a,#0x04
      00162F F8               [12] 4256 	mov	r0,a
      001630 86 82            [24] 4257 	mov	dpl, @r0
      001632 08               [12] 4258 	inc	r0
      001633 86 83            [24] 4259 	mov	dph, @r0
      001635 08               [12] 4260 	inc	r0
      001636 86 F0            [24] 4261 	mov	b, @r0
      001638 08               [12] 4262 	inc	r0
      001639 E6               [12] 4263 	mov	a, @r0
      00163A 12 1C C2         [24] 4264 	lcall	___fsmul
      00163D AA 82            [24] 4265 	mov	r2, dpl
      00163F AB 83            [24] 4266 	mov	r3, dph
      001641 AE F0            [24] 4267 	mov	r6, b
      001643 FF               [12] 4268 	mov	r7, a
      001644 E5 81            [12] 4269 	mov	a,sp
      001646 24 FC            [12] 4270 	add	a,#0xfc
      001648 F5 81            [12] 4271 	mov	sp,a
      00164A C0 02            [24] 4272 	push	ar2
      00164C C0 03            [24] 4273 	push	ar3
      00164E C0 06            [24] 4274 	push	ar6
      001650 C0 07            [24] 4275 	push	ar7
      001652 E5 1D            [12] 4276 	mov	a,_bp
      001654 24 0C            [12] 4277 	add	a,#0x0c
      001656 F8               [12] 4278 	mov	r0,a
      001657 86 82            [24] 4279 	mov	dpl, @r0
      001659 08               [12] 4280 	inc	r0
      00165A 86 83            [24] 4281 	mov	dph, @r0
      00165C 08               [12] 4282 	inc	r0
      00165D 86 F0            [24] 4283 	mov	b, @r0
      00165F 08               [12] 4284 	inc	r0
      001660 E6               [12] 4285 	mov	a, @r0
      001661 12 1E 22         [24] 4286 	lcall	___fsadd
      001664 C8               [12] 4287 	xch	a,r0
      001665 E5 1D            [12] 4288 	mov	a,_bp
      001667 24 0C            [12] 4289 	add	a,#0x0c
      001669 C8               [12] 4290 	xch	a,r0
      00166A A6 82            [24] 4291 	mov	@r0, dpl
      00166C 08               [12] 4292 	inc	r0
      00166D A6 83            [24] 4293 	mov	@r0, dph
      00166F 08               [12] 4294 	inc	r0
      001670 A6 F0            [24] 4295 	mov	@r0, b
      001672 08               [12] 4296 	inc	r0
      001673 F6               [12] 4297 	mov	@r0,a
      001674 E5 81            [12] 4298 	mov	a,sp
      001676 24 FC            [12] 4299 	add	a,#0xfc
      001678 F5 81            [12] 4300 	mov	sp,a
      00167A E5 1D            [12] 4301 	mov	a,_bp
      00167C 24 08            [12] 4302 	add	a,#0x08
      00167E F8               [12] 4303 	mov	r0,a
      00167F E6               [12] 4304 	mov	a,@r0
      001680 C0 E0            [24] 4305 	push	acc
      001682 08               [12] 4306 	inc	r0
      001683 E6               [12] 4307 	mov	a,@r0
      001684 C0 E0            [24] 4308 	push	acc
      001686 08               [12] 4309 	inc	r0
      001687 E6               [12] 4310 	mov	a,@r0
      001688 C0 E0            [24] 4311 	push	acc
      00168A 08               [12] 4312 	inc	r0
      00168B E6               [12] 4313 	mov	a,@r0
      00168C C0 E0            [24] 4314 	push	acc
      00168E E5 1D            [12] 4315 	mov	a,_bp
      001690 24 10            [12] 4316 	add	a,#0x10
      001692 F8               [12] 4317 	mov	r0,a
      001693 86 82            [24] 4318 	mov	dpl, @r0
      001695 08               [12] 4319 	inc	r0
      001696 86 83            [24] 4320 	mov	dph, @r0
      001698 08               [12] 4321 	inc	r0
      001699 86 F0            [24] 4322 	mov	b, @r0
      00169B 08               [12] 4323 	inc	r0
      00169C E6               [12] 4324 	mov	a, @r0
      00169D 12 1E 22         [24] 4325 	lcall	___fsadd
      0016A0 C8               [12] 4326 	xch	a,r0
      0016A1 E5 1D            [12] 4327 	mov	a,_bp
      0016A3 24 10            [12] 4328 	add	a,#0x10
      0016A5 C8               [12] 4329 	xch	a,r0
      0016A6 A6 82            [24] 4330 	mov	@r0, dpl
      0016A8 08               [12] 4331 	inc	r0
      0016A9 A6 83            [24] 4332 	mov	@r0, dph
      0016AB 08               [12] 4333 	inc	r0
      0016AC A6 F0            [24] 4334 	mov	@r0, b
      0016AE 08               [12] 4335 	inc	r0
      0016AF F6               [12] 4336 	mov	@r0,a
      0016B0 E5 81            [12] 4337 	mov	a,sp
      0016B2 24 FC            [12] 4338 	add	a,#0xfc
      0016B4 F5 81            [12] 4339 	mov	sp,a
      0016B6 E5 1D            [12] 4340 	mov	a,_bp
      0016B8 24 08            [12] 4341 	add	a,#0x08
      0016BA F8               [12] 4342 	mov	r0,a
      0016BB E6               [12] 4343 	mov	a,@r0
      0016BC C0 E0            [24] 4344 	push	acc
      0016BE 08               [12] 4345 	inc	r0
      0016BF E6               [12] 4346 	mov	a,@r0
      0016C0 C0 E0            [24] 4347 	push	acc
      0016C2 08               [12] 4348 	inc	r0
      0016C3 E6               [12] 4349 	mov	a,@r0
      0016C4 C0 E0            [24] 4350 	push	acc
      0016C6 08               [12] 4351 	inc	r0
      0016C7 E6               [12] 4352 	mov	a,@r0
      0016C8 C0 E0            [24] 4353 	push	acc
      0016CA E5 1D            [12] 4354 	mov	a,_bp
      0016CC 24 14            [12] 4355 	add	a,#0x14
      0016CE F8               [12] 4356 	mov	r0,a
      0016CF 86 82            [24] 4357 	mov	dpl, @r0
      0016D1 08               [12] 4358 	inc	r0
      0016D2 86 83            [24] 4359 	mov	dph, @r0
      0016D4 08               [12] 4360 	inc	r0
      0016D5 86 F0            [24] 4361 	mov	b, @r0
      0016D7 08               [12] 4362 	inc	r0
      0016D8 E6               [12] 4363 	mov	a, @r0
      0016D9 12 1D F2         [24] 4364 	lcall	___fslt
      0016DC AF 82            [24] 4365 	mov	r7, dpl
      0016DE E5 81            [12] 4366 	mov	a,sp
      0016E0 24 FC            [12] 4367 	add	a,#0xfc
      0016E2 F5 81            [12] 4368 	mov	sp,a
      0016E4 D0 04            [24] 4369 	pop	ar4
      0016E6 D0 05            [24] 4370 	pop	ar5
      0016E8 EF               [12] 4371 	mov	a,r7
      0016E9 60 67            [24] 4372 	jz	00108$
      0016EB E5 1D            [12] 4373 	mov	a,_bp
      0016ED 24 08            [12] 4374 	add	a,#0x08
      0016EF F8               [12] 4375 	mov	r0,a
      0016F0 E5 1D            [12] 4376 	mov	a,_bp
      0016F2 24 14            [12] 4377 	add	a,#0x14
      0016F4 F9               [12] 4378 	mov	r1,a
      0016F5 E6               [12] 4379 	mov	a,@r0
      0016F6 F7               [12] 4380 	mov	@r1,a
      0016F7 08               [12] 4381 	inc	r0
      0016F8 E6               [12] 4382 	mov	a,@r0
      0016F9 09               [12] 4383 	inc	r1
      0016FA F7               [12] 4384 	mov	@r1,a
      0016FB 08               [12] 4385 	inc	r0
      0016FC E6               [12] 4386 	mov	a,@r0
      0016FD 09               [12] 4387 	inc	r1
      0016FE F7               [12] 4388 	mov	@r1,a
      0016FF 08               [12] 4389 	inc	r0
      001700 E6               [12] 4390 	mov	a,@r0
      001701 09               [12] 4391 	inc	r1
      001702 F7               [12] 4392 	mov	@r1,a
      001703 E5 1D            [12] 4393 	mov	a,_bp
      001705 24 04            [12] 4394 	add	a,#0x04
      001707 F8               [12] 4395 	mov	r0,a
      001708 E5 1D            [12] 4396 	mov	a,_bp
      00170A 24 18            [12] 4397 	add	a,#0x18
      00170C F9               [12] 4398 	mov	r1,a
      00170D E6               [12] 4399 	mov	a,@r0
      00170E F7               [12] 4400 	mov	@r1,a
      00170F 08               [12] 4401 	inc	r0
      001710 E6               [12] 4402 	mov	a,@r0
      001711 09               [12] 4403 	inc	r1
      001712 F7               [12] 4404 	mov	@r1,a
      001713 08               [12] 4405 	inc	r0
      001714 E6               [12] 4406 	mov	a,@r0
      001715 09               [12] 4407 	inc	r1
      001716 F7               [12] 4408 	mov	@r1,a
      001717 08               [12] 4409 	inc	r0
      001718 E6               [12] 4410 	mov	a,@r0
      001719 09               [12] 4411 	inc	r1
      00171A F7               [12] 4412 	mov	@r1,a
      00171B 7D 01            [12] 4413 	mov	r5,#0x01
      00171D 7C 00            [12] 4414 	mov	r4,#0x00
      00171F E5 1D            [12] 4415 	mov	a,_bp
      001721 24 04            [12] 4416 	add	a,#0x04
      001723 F8               [12] 4417 	mov	r0,a
      001724 E5 1D            [12] 4418 	mov	a,_bp
      001726 24 1C            [12] 4419 	add	a,#0x1c
      001728 F9               [12] 4420 	mov	r1,a
      001729 E6               [12] 4421 	mov	a,@r0
      00172A F7               [12] 4422 	mov	@r1,a
      00172B 08               [12] 4423 	inc	r0
      00172C E6               [12] 4424 	mov	a,@r0
      00172D 09               [12] 4425 	inc	r1
      00172E F7               [12] 4426 	mov	@r1,a
      00172F 08               [12] 4427 	inc	r0
      001730 E6               [12] 4428 	mov	a,@r0
      001731 09               [12] 4429 	inc	r1
      001732 F7               [12] 4430 	mov	@r1,a
      001733 08               [12] 4431 	inc	r0
      001734 E6               [12] 4432 	mov	a,@r0
      001735 09               [12] 4433 	inc	r1
      001736 F7               [12] 4434 	mov	@r1,a
      001737 E5 1D            [12] 4435 	mov	a,_bp
      001739 24 04            [12] 4436 	add	a,#0x04
      00173B F8               [12] 4437 	mov	r0,a
      00173C E5 1D            [12] 4438 	mov	a,_bp
      00173E 24 20            [12] 4439 	add	a,#0x20
      001740 F9               [12] 4440 	mov	r1,a
      001741 E6               [12] 4441 	mov	a,@r0
      001742 F7               [12] 4442 	mov	@r1,a
      001743 08               [12] 4443 	inc	r0
      001744 E6               [12] 4444 	mov	a,@r0
      001745 09               [12] 4445 	inc	r1
      001746 F7               [12] 4446 	mov	@r1,a
      001747 08               [12] 4447 	inc	r0
      001748 E6               [12] 4448 	mov	a,@r0
      001749 09               [12] 4449 	inc	r1
      00174A F7               [12] 4450 	mov	@r1,a
      00174B 08               [12] 4451 	inc	r0
      00174C E6               [12] 4452 	mov	a,@r0
      00174D 09               [12] 4453 	inc	r1
      00174E F7               [12] 4454 	mov	@r1,a
      00174F 02 17 EC         [24] 4455 	ljmp	00119$
      001752                       4456 00108$:
      001752 C0 05            [24] 4457 	push	ar5
      001754 C0 04            [24] 4458 	push	ar4
      001756 E5 1D            [12] 4459 	mov	a,_bp
      001758 24 14            [12] 4460 	add	a,#0x14
      00175A F8               [12] 4461 	mov	r0,a
      00175B E6               [12] 4462 	mov	a,@r0
      00175C C0 E0            [24] 4463 	push	acc
      00175E 08               [12] 4464 	inc	r0
      00175F E6               [12] 4465 	mov	a,@r0
      001760 C0 E0            [24] 4466 	push	acc
      001762 08               [12] 4467 	inc	r0
      001763 E6               [12] 4468 	mov	a,@r0
      001764 C0 E0            [24] 4469 	push	acc
      001766 08               [12] 4470 	inc	r0
      001767 E6               [12] 4471 	mov	a,@r0
      001768 C0 E0            [24] 4472 	push	acc
      00176A E5 1D            [12] 4473 	mov	a,_bp
      00176C 24 08            [12] 4474 	add	a,#0x08
      00176E F8               [12] 4475 	mov	r0,a
      00176F 86 82            [24] 4476 	mov	dpl, @r0
      001771 08               [12] 4477 	inc	r0
      001772 86 83            [24] 4478 	mov	dph, @r0
      001774 08               [12] 4479 	inc	r0
      001775 86 F0            [24] 4480 	mov	b, @r0
      001777 08               [12] 4481 	inc	r0
      001778 E6               [12] 4482 	mov	a, @r0
      001779 12 1D C6         [24] 4483 	lcall	___fseq
      00177C AF 82            [24] 4484 	mov	r7, dpl
      00177E E5 81            [12] 4485 	mov	a,sp
      001780 24 FC            [12] 4486 	add	a,#0xfc
      001782 F5 81            [12] 4487 	mov	sp,a
      001784 D0 04            [24] 4488 	pop	ar4
      001786 D0 05            [24] 4489 	pop	ar5
      001788 EF               [12] 4490 	mov	a,r7
      001789 60 61            [24] 4491 	jz	00119$
      00178B C0 05            [24] 4492 	push	ar5
      00178D C0 04            [24] 4493 	push	ar4
      00178F E5 1D            [12] 4494 	mov	a,_bp
      001791 24 04            [12] 4495 	add	a,#0x04
      001793 F8               [12] 4496 	mov	r0,a
      001794 E6               [12] 4497 	mov	a,@r0
      001795 C0 E0            [24] 4498 	push	acc
      001797 08               [12] 4499 	inc	r0
      001798 E6               [12] 4500 	mov	a,@r0
      001799 C0 E0            [24] 4501 	push	acc
      00179B 08               [12] 4502 	inc	r0
      00179C E6               [12] 4503 	mov	a,@r0
      00179D C0 E0            [24] 4504 	push	acc
      00179F 08               [12] 4505 	inc	r0
      0017A0 E6               [12] 4506 	mov	a,@r0
      0017A1 C0 E0            [24] 4507 	push	acc
      0017A3 E5 1D            [12] 4508 	mov	a,_bp
      0017A5 24 18            [12] 4509 	add	a,#0x18
      0017A7 F8               [12] 4510 	mov	r0,a
      0017A8 86 82            [24] 4511 	mov	dpl, @r0
      0017AA 08               [12] 4512 	inc	r0
      0017AB 86 83            [24] 4513 	mov	dph, @r0
      0017AD 08               [12] 4514 	inc	r0
      0017AE 86 F0            [24] 4515 	mov	b, @r0
      0017B0 08               [12] 4516 	inc	r0
      0017B1 E6               [12] 4517 	mov	a, @r0
      0017B2 12 1E 22         [24] 4518 	lcall	___fsadd
      0017B5 C8               [12] 4519 	xch	a,r0
      0017B6 E5 1D            [12] 4520 	mov	a,_bp
      0017B8 24 18            [12] 4521 	add	a,#0x18
      0017BA C8               [12] 4522 	xch	a,r0
      0017BB A6 82            [24] 4523 	mov	@r0, dpl
      0017BD 08               [12] 4524 	inc	r0
      0017BE A6 83            [24] 4525 	mov	@r0, dph
      0017C0 08               [12] 4526 	inc	r0
      0017C1 A6 F0            [24] 4527 	mov	@r0, b
      0017C3 08               [12] 4528 	inc	r0
      0017C4 F6               [12] 4529 	mov	@r0,a
      0017C5 E5 81            [12] 4530 	mov	a,sp
      0017C7 24 FC            [12] 4531 	add	a,#0xfc
      0017C9 F5 81            [12] 4532 	mov	sp,a
      0017CB D0 04            [24] 4533 	pop	ar4
      0017CD D0 05            [24] 4534 	pop	ar5
      0017CF 0D               [12] 4535 	inc	r5
      0017D0 BD 00 01         [24] 4536 	cjne	r5,#0x00,00214$
      0017D3 0C               [12] 4537 	inc	r4
      0017D4                       4538 00214$:
      0017D4 E5 1D            [12] 4539 	mov	a,_bp
      0017D6 24 04            [12] 4540 	add	a,#0x04
      0017D8 F8               [12] 4541 	mov	r0,a
      0017D9 E5 1D            [12] 4542 	mov	a,_bp
      0017DB 24 20            [12] 4543 	add	a,#0x20
      0017DD F9               [12] 4544 	mov	r1,a
      0017DE E6               [12] 4545 	mov	a,@r0
      0017DF F7               [12] 4546 	mov	@r1,a
      0017E0 08               [12] 4547 	inc	r0
      0017E1 E6               [12] 4548 	mov	a,@r0
      0017E2 09               [12] 4549 	inc	r1
      0017E3 F7               [12] 4550 	mov	@r1,a
      0017E4 08               [12] 4551 	inc	r0
      0017E5 E6               [12] 4552 	mov	a,@r0
      0017E6 09               [12] 4553 	inc	r1
      0017E7 F7               [12] 4554 	mov	@r1,a
      0017E8 08               [12] 4555 	inc	r0
      0017E9 E6               [12] 4556 	mov	a,@r0
      0017EA 09               [12] 4557 	inc	r1
      0017EB F7               [12] 4558 	mov	@r1,a
      0017EC                       4559 00119$:
      0017EC C0 05            [24] 4560 	push	ar5
      0017EE C0 04            [24] 4561 	push	ar4
      0017F0 E5 1D            [12] 4562 	mov	a,_bp
      0017F2 24 F2            [12] 4563 	add	a,#0xf2
      0017F4 F8               [12] 4564 	mov	r0,a
      0017F5 E6               [12] 4565 	mov	a,@r0
      0017F6 C0 E0            [24] 4566 	push	acc
      0017F8 08               [12] 4567 	inc	r0
      0017F9 E6               [12] 4568 	mov	a,@r0
      0017FA C0 E0            [24] 4569 	push	acc
      0017FC 08               [12] 4570 	inc	r0
      0017FD E6               [12] 4571 	mov	a,@r0
      0017FE C0 E0            [24] 4572 	push	acc
      001800 08               [12] 4573 	inc	r0
      001801 E6               [12] 4574 	mov	a,@r0
      001802 C0 E0            [24] 4575 	push	acc
      001804 E5 1D            [12] 4576 	mov	a,_bp
      001806 24 04            [12] 4577 	add	a,#0x04
      001808 F8               [12] 4578 	mov	r0,a
      001809 86 82            [24] 4579 	mov	dpl, @r0
      00180B 08               [12] 4580 	inc	r0
      00180C 86 83            [24] 4581 	mov	dph, @r0
      00180E 08               [12] 4582 	inc	r0
      00180F 86 F0            [24] 4583 	mov	b, @r0
      001811 08               [12] 4584 	inc	r0
      001812 E6               [12] 4585 	mov	a, @r0
      001813 12 1E 22         [24] 4586 	lcall	___fsadd
      001816 C8               [12] 4587 	xch	a,r0
      001817 E5 1D            [12] 4588 	mov	a,_bp
      001819 24 04            [12] 4589 	add	a,#0x04
      00181B C8               [12] 4590 	xch	a,r0
      00181C A6 82            [24] 4591 	mov	@r0, dpl
      00181E 08               [12] 4592 	inc	r0
      00181F A6 83            [24] 4593 	mov	@r0, dph
      001821 08               [12] 4594 	inc	r0
      001822 A6 F0            [24] 4595 	mov	@r0, b
      001824 08               [12] 4596 	inc	r0
      001825 F6               [12] 4597 	mov	@r0,a
      001826 E5 81            [12] 4598 	mov	a,sp
      001828 24 FC            [12] 4599 	add	a,#0xfc
      00182A F5 81            [12] 4600 	mov	sp,a
      00182C D0 04            [24] 4601 	pop	ar4
      00182E D0 05            [24] 4602 	pop	ar5
      001830 02 15 9C         [24] 4603 	ljmp	00118$
      001833                       4604 00110$:
      001833 E5 1D            [12] 4605 	mov	a,_bp
      001835 24 F1            [12] 4606 	add	a,#0xf1
      001837 F8               [12] 4607 	mov	r0,a
      001838 B6 03 02         [24] 4608 	cjne	@r0,#0x03,00215$
      00183B 80 02            [24] 4609 	sjmp	00216$
      00183D                       4610 00215$:
      00183D 80 79            [24] 4611 	sjmp	00112$
      00183F                       4612 00216$:
      00183F C0 05            [24] 4613 	push	ar5
      001841 C0 04            [24] 4614 	push	ar4
      001843 E5 1D            [12] 4615 	mov	a,_bp
      001845 24 14            [12] 4616 	add	a,#0x14
      001847 F8               [12] 4617 	mov	r0,a
      001848 E6               [12] 4618 	mov	a,@r0
      001849 C0 E0            [24] 4619 	push	acc
      00184B 08               [12] 4620 	inc	r0
      00184C E6               [12] 4621 	mov	a,@r0
      00184D C0 E0            [24] 4622 	push	acc
      00184F 08               [12] 4623 	inc	r0
      001850 E6               [12] 4624 	mov	a,@r0
      001851 C0 E0            [24] 4625 	push	acc
      001853 08               [12] 4626 	inc	r0
      001854 E6               [12] 4627 	mov	a,@r0
      001855 C0 E0            [24] 4628 	push	acc
      001857 90 00 00         [24] 4629 	mov	dptr,#0x0000
      00185A E4               [12] 4630 	clr	a
      00185B F5 F0            [12] 4631 	mov	b,a
      00185D 12 1D F2         [24] 4632 	lcall	___fslt
      001860 AF 82            [24] 4633 	mov	r7, dpl
      001862 E5 81            [12] 4634 	mov	a,sp
      001864 24 FC            [12] 4635 	add	a,#0xfc
      001866 F5 81            [12] 4636 	mov	sp,a
      001868 D0 04            [24] 4637 	pop	ar4
      00186A D0 05            [24] 4638 	pop	ar5
      00186C EF               [12] 4639 	mov	a,r7
      00186D 60 37            [24] 4640 	jz	00122$
      00186F 8D 82            [24] 4641 	mov	dpl, r5
      001871 8C 83            [24] 4642 	mov	dph, r4
      001873 12 1E C4         [24] 4643 	lcall	___uint2fs
      001876 AC 82            [24] 4644 	mov	r4, dpl
      001878 AD 83            [24] 4645 	mov	r5, dph
      00187A AE F0            [24] 4646 	mov	r6, b
      00187C FF               [12] 4647 	mov	r7, a
      00187D C0 04            [24] 4648 	push	ar4
      00187F C0 05            [24] 4649 	push	ar5
      001881 C0 06            [24] 4650 	push	ar6
      001883 C0 07            [24] 4651 	push	ar7
      001885 E5 1D            [12] 4652 	mov	a,_bp
      001887 24 18            [12] 4653 	add	a,#0x18
      001889 F8               [12] 4654 	mov	r0,a
      00188A 86 82            [24] 4655 	mov	dpl, @r0
      00188C 08               [12] 4656 	inc	r0
      00188D 86 83            [24] 4657 	mov	dph, @r0
      00188F 08               [12] 4658 	inc	r0
      001890 86 F0            [24] 4659 	mov	b, @r0
      001892 08               [12] 4660 	inc	r0
      001893 E6               [12] 4661 	mov	a, @r0
      001894 12 1F 39         [24] 4662 	lcall	___fsdiv
      001897 AC 82            [24] 4663 	mov	r4, dpl
      001899 AD 83            [24] 4664 	mov	r5, dph
      00189B AE F0            [24] 4665 	mov	r6, b
      00189D FF               [12] 4666 	mov	r7, a
      00189E E5 81            [12] 4667 	mov	a,sp
      0018A0 24 FC            [12] 4668 	add	a,#0xfc
      0018A2 F5 81            [12] 4669 	mov	sp,a
      0018A4 80 08            [24] 4670 	sjmp	00123$
      0018A6                       4671 00122$:
      0018A6 7C 00            [12] 4672 	mov	r4,#0x00
      0018A8 7D 00            [12] 4673 	mov	r5,#0x00
      0018AA 7E 00            [12] 4674 	mov	r6,#0x00
      0018AC 7F 00            [12] 4675 	mov	r7,#0x00
      0018AE                       4676 00123$:
      0018AE 8C 82            [24] 4677 	mov	dpl, r4
      0018B0 8D 83            [24] 4678 	mov	dph, r5
      0018B2 8E F0            [24] 4679 	mov	b, r6
      0018B4 EF               [12] 4680 	mov	a, r7
      0018B5 02 19 CB         [24] 4681 	ljmp	00120$
      0018B8                       4682 00112$:
      0018B8 E5 1D            [12] 4683 	mov	a,_bp
      0018BA 24 F1            [12] 4684 	add	a,#0xf1
      0018BC F8               [12] 4685 	mov	r0,a
      0018BD B6 04 4C         [24] 4686 	cjne	@r0,#0x04,00114$
      0018C0 E5 1D            [12] 4687 	mov	a,_bp
      0018C2 24 14            [12] 4688 	add	a,#0x14
      0018C4 F8               [12] 4689 	mov	r0,a
      0018C5 E6               [12] 4690 	mov	a,@r0
      0018C6 C0 E0            [24] 4691 	push	acc
      0018C8 08               [12] 4692 	inc	r0
      0018C9 E6               [12] 4693 	mov	a,@r0
      0018CA C0 E0            [24] 4694 	push	acc
      0018CC 08               [12] 4695 	inc	r0
      0018CD E6               [12] 4696 	mov	a,@r0
      0018CE C0 E0            [24] 4697 	push	acc
      0018D0 08               [12] 4698 	inc	r0
      0018D1 E6               [12] 4699 	mov	a,@r0
      0018D2 C0 E0            [24] 4700 	push	acc
      0018D4 90 00 00         [24] 4701 	mov	dptr,#0x0000
      0018D7 E4               [12] 4702 	clr	a
      0018D8 F5 F0            [12] 4703 	mov	b,a
      0018DA 12 1D F2         [24] 4704 	lcall	___fslt
      0018DD AF 82            [24] 4705 	mov	r7, dpl
      0018DF E5 81            [12] 4706 	mov	a,sp
      0018E1 24 FC            [12] 4707 	add	a,#0xfc
      0018E3 F5 81            [12] 4708 	mov	sp,a
      0018E5 EF               [12] 4709 	mov	a,r7
      0018E6 60 12            [24] 4710 	jz	00124$
      0018E8 E5 1D            [12] 4711 	mov	a,_bp
      0018EA 24 1C            [12] 4712 	add	a,#0x1c
      0018EC F8               [12] 4713 	mov	r0,a
      0018ED 86 04            [24] 4714 	mov	ar4,@r0
      0018EF 08               [12] 4715 	inc	r0
      0018F0 86 05            [24] 4716 	mov	ar5,@r0
      0018F2 08               [12] 4717 	inc	r0
      0018F3 86 06            [24] 4718 	mov	ar6,@r0
      0018F5 08               [12] 4719 	inc	r0
      0018F6 86 07            [24] 4720 	mov	ar7,@r0
      0018F8 80 08            [24] 4721 	sjmp	00125$
      0018FA                       4722 00124$:
      0018FA 7C 00            [12] 4723 	mov	r4,#0x00
      0018FC 7D 00            [12] 4724 	mov	r5,#0x00
      0018FE 7E 00            [12] 4725 	mov	r6,#0x00
      001900 7F 00            [12] 4726 	mov	r7,#0x00
      001902                       4727 00125$:
      001902 8C 82            [24] 4728 	mov	dpl, r4
      001904 8D 83            [24] 4729 	mov	dph, r5
      001906 8E F0            [24] 4730 	mov	b, r6
      001908 EF               [12] 4731 	mov	a, r7
      001909 02 19 CB         [24] 4732 	ljmp	00120$
      00190C                       4733 00114$:
      00190C E5 1D            [12] 4734 	mov	a,_bp
      00190E 24 F1            [12] 4735 	add	a,#0xf1
      001910 F8               [12] 4736 	mov	r0,a
      001911 B6 05 4B         [24] 4737 	cjne	@r0,#0x05,00116$
      001914 E5 1D            [12] 4738 	mov	a,_bp
      001916 24 14            [12] 4739 	add	a,#0x14
      001918 F8               [12] 4740 	mov	r0,a
      001919 E6               [12] 4741 	mov	a,@r0
      00191A C0 E0            [24] 4742 	push	acc
      00191C 08               [12] 4743 	inc	r0
      00191D E6               [12] 4744 	mov	a,@r0
      00191E C0 E0            [24] 4745 	push	acc
      001920 08               [12] 4746 	inc	r0
      001921 E6               [12] 4747 	mov	a,@r0
      001922 C0 E0            [24] 4748 	push	acc
      001924 08               [12] 4749 	inc	r0
      001925 E6               [12] 4750 	mov	a,@r0
      001926 C0 E0            [24] 4751 	push	acc
      001928 90 00 00         [24] 4752 	mov	dptr,#0x0000
      00192B E4               [12] 4753 	clr	a
      00192C F5 F0            [12] 4754 	mov	b,a
      00192E 12 1D F2         [24] 4755 	lcall	___fslt
      001931 AF 82            [24] 4756 	mov	r7, dpl
      001933 E5 81            [12] 4757 	mov	a,sp
      001935 24 FC            [12] 4758 	add	a,#0xfc
      001937 F5 81            [12] 4759 	mov	sp,a
      001939 EF               [12] 4760 	mov	a,r7
      00193A 60 12            [24] 4761 	jz	00126$
      00193C E5 1D            [12] 4762 	mov	a,_bp
      00193E 24 20            [12] 4763 	add	a,#0x20
      001940 F8               [12] 4764 	mov	r0,a
      001941 86 04            [24] 4765 	mov	ar4,@r0
      001943 08               [12] 4766 	inc	r0
      001944 86 05            [24] 4767 	mov	ar5,@r0
      001946 08               [12] 4768 	inc	r0
      001947 86 06            [24] 4769 	mov	ar6,@r0
      001949 08               [12] 4770 	inc	r0
      00194A 86 07            [24] 4771 	mov	ar7,@r0
      00194C 80 08            [24] 4772 	sjmp	00127$
      00194E                       4773 00126$:
      00194E 7C 00            [12] 4774 	mov	r4,#0x00
      001950 7D 00            [12] 4775 	mov	r5,#0x00
      001952 7E 00            [12] 4776 	mov	r6,#0x00
      001954 7F 00            [12] 4777 	mov	r7,#0x00
      001956                       4778 00127$:
      001956 8C 82            [24] 4779 	mov	dpl, r4
      001958 8D 83            [24] 4780 	mov	dph, r5
      00195A 8E F0            [24] 4781 	mov	b, r6
      00195C EF               [12] 4782 	mov	a, r7
      00195D 80 6C            [24] 4783 	sjmp	00120$
      00195F                       4784 00116$:
      00195F E5 1D            [12] 4785 	mov	a,_bp
      001961 24 10            [12] 4786 	add	a,#0x10
      001963 F8               [12] 4787 	mov	r0,a
      001964 E6               [12] 4788 	mov	a,@r0
      001965 C0 E0            [24] 4789 	push	acc
      001967 08               [12] 4790 	inc	r0
      001968 E6               [12] 4791 	mov	a,@r0
      001969 C0 E0            [24] 4792 	push	acc
      00196B 08               [12] 4793 	inc	r0
      00196C E6               [12] 4794 	mov	a,@r0
      00196D C0 E0            [24] 4795 	push	acc
      00196F 08               [12] 4796 	inc	r0
      001970 E6               [12] 4797 	mov	a,@r0
      001971 C0 E0            [24] 4798 	push	acc
      001973 90 00 00         [24] 4799 	mov	dptr,#0x0000
      001976 E4               [12] 4800 	clr	a
      001977 F5 F0            [12] 4801 	mov	b,a
      001979 12 1D F2         [24] 4802 	lcall	___fslt
      00197C AF 82            [24] 4803 	mov	r7, dpl
      00197E E5 81            [12] 4804 	mov	a,sp
      001980 24 FC            [12] 4805 	add	a,#0xfc
      001982 F5 81            [12] 4806 	mov	sp,a
      001984 EF               [12] 4807 	mov	a,r7
      001985 60 35            [24] 4808 	jz	00128$
      001987 E5 1D            [12] 4809 	mov	a,_bp
      001989 24 10            [12] 4810 	add	a,#0x10
      00198B F8               [12] 4811 	mov	r0,a
      00198C E6               [12] 4812 	mov	a,@r0
      00198D C0 E0            [24] 4813 	push	acc
      00198F 08               [12] 4814 	inc	r0
      001990 E6               [12] 4815 	mov	a,@r0
      001991 C0 E0            [24] 4816 	push	acc
      001993 08               [12] 4817 	inc	r0
      001994 E6               [12] 4818 	mov	a,@r0
      001995 C0 E0            [24] 4819 	push	acc
      001997 08               [12] 4820 	inc	r0
      001998 E6               [12] 4821 	mov	a,@r0
      001999 C0 E0            [24] 4822 	push	acc
      00199B E5 1D            [12] 4823 	mov	a,_bp
      00199D 24 0C            [12] 4824 	add	a,#0x0c
      00199F F8               [12] 4825 	mov	r0,a
      0019A0 86 82            [24] 4826 	mov	dpl, @r0
      0019A2 08               [12] 4827 	inc	r0
      0019A3 86 83            [24] 4828 	mov	dph, @r0
      0019A5 08               [12] 4829 	inc	r0
      0019A6 86 F0            [24] 4830 	mov	b, @r0
      0019A8 08               [12] 4831 	inc	r0
      0019A9 E6               [12] 4832 	mov	a, @r0
      0019AA 12 1F 39         [24] 4833 	lcall	___fsdiv
      0019AD AC 82            [24] 4834 	mov	r4, dpl
      0019AF AD 83            [24] 4835 	mov	r5, dph
      0019B1 AE F0            [24] 4836 	mov	r6, b
      0019B3 FF               [12] 4837 	mov	r7, a
      0019B4 E5 81            [12] 4838 	mov	a,sp
      0019B6 24 FC            [12] 4839 	add	a,#0xfc
      0019B8 F5 81            [12] 4840 	mov	sp,a
      0019BA 80 08            [24] 4841 	sjmp	00129$
      0019BC                       4842 00128$:
      0019BC 7C 00            [12] 4843 	mov	r4,#0x00
      0019BE 7D 00            [12] 4844 	mov	r5,#0x00
      0019C0 7E 00            [12] 4845 	mov	r6,#0x00
      0019C2 7F 00            [12] 4846 	mov	r7,#0x00
      0019C4                       4847 00129$:
      0019C4 8C 82            [24] 4848 	mov	dpl, r4
      0019C6 8D 83            [24] 4849 	mov	dph, r5
      0019C8 8E F0            [24] 4850 	mov	b, r6
      0019CA EF               [12] 4851 	mov	a, r7
      0019CB                       4852 00120$:
      0019CB 85 1D 81         [24] 4853 	mov	sp,_bp
      0019CE D0 1D            [24] 4854 	pop	_bp
                           001919  4855 	C$fuzzy.h$75$1_0$43 ==.
                           001919  4856 	XG$fuzzy_rules_defuzzify$0$0 ==.
      0019D0 22               [24] 4857 	ret
                                   4858 ;------------------------------------------------------------
                                   4859 ;Allocation info for local variables in function 'fuzzy_rules_cog'
                                   4860 ;------------------------------------------------------------
                                   4861 ;lower         Allocated to stack - _bp -6 +4 
                                   4862 ;upper         Allocated to stack - _bp -10 +4 
                                   4863 ;step          Allocated to stack - _bp -14 +4 
                                   4864 ;rules         Allocated to registers r5 r6 r7 
                                   4865 ;------------------------------------------------------------
                           00191A  4866 	G$fuzzy_rules_cog$0$0 ==.
                           00191A  4867 	C$fuzzy.h$76$1_0$49 ==.
                                   4868 ;	../../fuzzy.h:76: float fuzzy_rules_cog(const fuzzy_rules_t *rules, float lower, float upper, float step) { return fuzzy_rules_defuzzify(rules, lower, upper, step, FUZZY_DEFUZZ_COG); }
                                   4869 ;	-----------------------------------------
                                   4870 ;	 function fuzzy_rules_cog
                                   4871 ;	-----------------------------------------
      0019D1                       4872 _fuzzy_rules_cog:
      0019D1 C0 1D            [24] 4873 	push	_bp
      0019D3 85 81 1D         [24] 4874 	mov	_bp,sp
      0019D6 AD 82            [24] 4875 	mov	r5, dpl
      0019D8 AE 83            [24] 4876 	mov	r6, dph
      0019DA AF F0            [24] 4877 	mov	r7, b
      0019DC E4               [12] 4878 	clr	a
      0019DD C0 E0            [24] 4879 	push	acc
      0019DF E5 1D            [12] 4880 	mov	a,_bp
      0019E1 24 F2            [12] 4881 	add	a,#0xf2
      0019E3 F8               [12] 4882 	mov	r0,a
      0019E4 E6               [12] 4883 	mov	a,@r0
      0019E5 C0 E0            [24] 4884 	push	acc
      0019E7 08               [12] 4885 	inc	r0
      0019E8 E6               [12] 4886 	mov	a,@r0
      0019E9 C0 E0            [24] 4887 	push	acc
      0019EB 08               [12] 4888 	inc	r0
      0019EC E6               [12] 4889 	mov	a,@r0
      0019ED C0 E0            [24] 4890 	push	acc
      0019EF 08               [12] 4891 	inc	r0
      0019F0 E6               [12] 4892 	mov	a,@r0
      0019F1 C0 E0            [24] 4893 	push	acc
      0019F3 E5 1D            [12] 4894 	mov	a,_bp
      0019F5 24 F6            [12] 4895 	add	a,#0xf6
      0019F7 F8               [12] 4896 	mov	r0,a
      0019F8 E6               [12] 4897 	mov	a,@r0
      0019F9 C0 E0            [24] 4898 	push	acc
      0019FB 08               [12] 4899 	inc	r0
      0019FC E6               [12] 4900 	mov	a,@r0
      0019FD C0 E0            [24] 4901 	push	acc
      0019FF 08               [12] 4902 	inc	r0
      001A00 E6               [12] 4903 	mov	a,@r0
      001A01 C0 E0            [24] 4904 	push	acc
      001A03 08               [12] 4905 	inc	r0
      001A04 E6               [12] 4906 	mov	a,@r0
      001A05 C0 E0            [24] 4907 	push	acc
      001A07 E5 1D            [12] 4908 	mov	a,_bp
      001A09 24 FA            [12] 4909 	add	a,#0xfa
      001A0B F8               [12] 4910 	mov	r0,a
      001A0C E6               [12] 4911 	mov	a,@r0
      001A0D C0 E0            [24] 4912 	push	acc
      001A0F 08               [12] 4913 	inc	r0
      001A10 E6               [12] 4914 	mov	a,@r0
      001A11 C0 E0            [24] 4915 	push	acc
      001A13 08               [12] 4916 	inc	r0
      001A14 E6               [12] 4917 	mov	a,@r0
      001A15 C0 E0            [24] 4918 	push	acc
      001A17 08               [12] 4919 	inc	r0
      001A18 E6               [12] 4920 	mov	a,@r0
      001A19 C0 E0            [24] 4921 	push	acc
      001A1B 8D 82            [24] 4922 	mov	dpl, r5
      001A1D 8E 83            [24] 4923 	mov	dph, r6
      001A1F 8F F0            [24] 4924 	mov	b, r7
      001A21 12 14 8D         [24] 4925 	lcall	_fuzzy_rules_defuzzify
      001A24 AC 82            [24] 4926 	mov	r4, dpl
      001A26 AD 83            [24] 4927 	mov	r5, dph
      001A28 AE F0            [24] 4928 	mov	r6, b
      001A2A FF               [12] 4929 	mov	r7, a
      001A2B E5 81            [12] 4930 	mov	a,sp
      001A2D 24 F3            [12] 4931 	add	a,#0xf3
      001A2F F5 81            [12] 4932 	mov	sp,a
      001A31 8C 82            [24] 4933 	mov	dpl, r4
      001A33 8D 83            [24] 4934 	mov	dph, r5
      001A35 8E F0            [24] 4935 	mov	b, r6
      001A37 EF               [12] 4936 	mov	a, r7
      001A38 D0 1D            [24] 4937 	pop	_bp
                           001983  4938 	C$fuzzy.h$76$1_0$49 ==.
                           001983  4939 	XG$fuzzy_rules_cog$0$0 ==.
      001A3A 22               [24] 4940 	ret
                                   4941 ;------------------------------------------------------------
                                   4942 ;Allocation info for local variables in function 'temperature_low'
                                   4943 ;------------------------------------------------------------
                                   4944 ;x             Allocated to registers r4 r5 r6 r7 
                                   4945 ;------------------------------------------------------------
                           001984  4946 	Fcontroller_8051$temperature_low$0$0 ==.
                           001984  4947 	C$controller_8051.c$30$1_0$51 ==.
                                   4948 ;	../../controller_8051.c:30: FUZZY_VAR(temperature_low,  FUZZY_SHAPE_RAMP, HEDGE_NONE, 20.0f, 40.0f, false)
                                   4949 ;	-----------------------------------------
                                   4950 ;	 function temperature_low
                                   4951 ;	-----------------------------------------
      001A3B                       4952 _temperature_low:
      001A3B AC 82            [24] 4953 	mov	r4,dpl
      001A3D AD 83            [24] 4954 	mov	r5,dph
      001A3F AE F0            [24] 4955 	mov	r6,b
      001A41 FF               [12] 4956 	mov	r7,a
      001A42 C0 04            [24] 4957 	push	ar4
      001A44 C0 05            [24] 4958 	push	ar5
      001A46 C0 06            [24] 4959 	push	ar6
      001A48 C0 07            [24] 4960 	push	ar7
      001A4A 90 20 BE         [24] 4961 	mov	dptr,#_temperature_low_fuzzy_variable
      001A4D 75 F0 80         [24] 4962 	mov	b, #0x80
      001A50 12 0E 5F         [24] 4963 	lcall	_fuzzy_8051_eval
      001A53 AC 82            [24] 4964 	mov	r4, dpl
      001A55 AD 83            [24] 4965 	mov	r5, dph
      001A57 AE F0            [24] 4966 	mov	r6, b
      001A59 FF               [12] 4967 	mov	r7, a
      001A5A E5 81            [12] 4968 	mov	a,sp
      001A5C 24 FC            [12] 4969 	add	a,#0xfc
      001A5E F5 81            [12] 4970 	mov	sp,a
      001A60 8C 82            [24] 4971 	mov	dpl, r4
      001A62 8D 83            [24] 4972 	mov	dph, r5
      001A64 8E F0            [24] 4973 	mov	b, r6
      001A66 EF               [12] 4974 	mov	a, r7
                           0019B0  4975 	C$controller_8051.c$30$1_0$51 ==.
                           0019B0  4976 	XFcontroller_8051$temperature_low$0$0 ==.
      001A67 22               [24] 4977 	ret
                                   4978 ;------------------------------------------------------------
                                   4979 ;Allocation info for local variables in function 'temperature_high'
                                   4980 ;------------------------------------------------------------
                                   4981 ;x             Allocated to registers r4 r5 r6 r7 
                                   4982 ;------------------------------------------------------------
                           0019B1  4983 	Fcontroller_8051$temperature_high$0$0 ==.
                           0019B1  4984 	C$controller_8051.c$31$1_0$53 ==.
                                   4985 ;	../../controller_8051.c:31: FUZZY_VAR(temperature_high, FUZZY_SHAPE_RAMP, HEDGE_NONE, 30.0f, 60.0f, true)
                                   4986 ;	-----------------------------------------
                                   4987 ;	 function temperature_high
                                   4988 ;	-----------------------------------------
      001A68                       4989 _temperature_high:
      001A68 AC 82            [24] 4990 	mov	r4,dpl
      001A6A AD 83            [24] 4991 	mov	r5,dph
      001A6C AE F0            [24] 4992 	mov	r6,b
      001A6E FF               [12] 4993 	mov	r7,a
      001A6F C0 04            [24] 4994 	push	ar4
      001A71 C0 05            [24] 4995 	push	ar5
      001A73 C0 06            [24] 4996 	push	ar6
      001A75 C0 07            [24] 4997 	push	ar7
      001A77 90 20 D0         [24] 4998 	mov	dptr,#_temperature_high_fuzzy_variable
      001A7A 75 F0 80         [24] 4999 	mov	b, #0x80
      001A7D 12 0E 5F         [24] 5000 	lcall	_fuzzy_8051_eval
      001A80 AC 82            [24] 5001 	mov	r4, dpl
      001A82 AD 83            [24] 5002 	mov	r5, dph
      001A84 AE F0            [24] 5003 	mov	r6, b
      001A86 FF               [12] 5004 	mov	r7, a
      001A87 E5 81            [12] 5005 	mov	a,sp
      001A89 24 FC            [12] 5006 	add	a,#0xfc
      001A8B F5 81            [12] 5007 	mov	sp,a
      001A8D 8C 82            [24] 5008 	mov	dpl, r4
      001A8F 8D 83            [24] 5009 	mov	dph, r5
      001A91 8E F0            [24] 5010 	mov	b, r6
      001A93 EF               [12] 5011 	mov	a, r7
                           0019DD  5012 	C$controller_8051.c$31$1_0$53 ==.
                           0019DD  5013 	XFcontroller_8051$temperature_high$0$0 ==.
      001A94 22               [24] 5014 	ret
                                   5015 ;------------------------------------------------------------
                                   5016 ;Allocation info for local variables in function 'fan_slow'
                                   5017 ;------------------------------------------------------------
                                   5018 ;x             Allocated to registers r4 r5 r6 r7 
                                   5019 ;------------------------------------------------------------
                           0019DE  5020 	Fcontroller_8051$fan_slow$0$0 ==.
                           0019DE  5021 	C$controller_8051.c$32$1_0$55 ==.
                                   5022 ;	../../controller_8051.c:32: FUZZY_VAR(fan_slow,         FUZZY_SHAPE_RAMP, HEDGE_NONE, 20.0f, 50.0f, false)
                                   5023 ;	-----------------------------------------
                                   5024 ;	 function fan_slow
                                   5025 ;	-----------------------------------------
      001A95                       5026 _fan_slow:
      001A95 AC 82            [24] 5027 	mov	r4,dpl
      001A97 AD 83            [24] 5028 	mov	r5,dph
      001A99 AE F0            [24] 5029 	mov	r6,b
      001A9B FF               [12] 5030 	mov	r7,a
      001A9C C0 04            [24] 5031 	push	ar4
      001A9E C0 05            [24] 5032 	push	ar5
      001AA0 C0 06            [24] 5033 	push	ar6
      001AA2 C0 07            [24] 5034 	push	ar7
      001AA4 90 20 E2         [24] 5035 	mov	dptr,#_fan_slow_fuzzy_variable
      001AA7 75 F0 80         [24] 5036 	mov	b, #0x80
      001AAA 12 0E 5F         [24] 5037 	lcall	_fuzzy_8051_eval
      001AAD AC 82            [24] 5038 	mov	r4, dpl
      001AAF AD 83            [24] 5039 	mov	r5, dph
      001AB1 AE F0            [24] 5040 	mov	r6, b
      001AB3 FF               [12] 5041 	mov	r7, a
      001AB4 E5 81            [12] 5042 	mov	a,sp
      001AB6 24 FC            [12] 5043 	add	a,#0xfc
      001AB8 F5 81            [12] 5044 	mov	sp,a
      001ABA 8C 82            [24] 5045 	mov	dpl, r4
      001ABC 8D 83            [24] 5046 	mov	dph, r5
      001ABE 8E F0            [24] 5047 	mov	b, r6
      001AC0 EF               [12] 5048 	mov	a, r7
                           001A0A  5049 	C$controller_8051.c$32$1_0$55 ==.
                           001A0A  5050 	XFcontroller_8051$fan_slow$0$0 ==.
      001AC1 22               [24] 5051 	ret
                                   5052 ;------------------------------------------------------------
                                   5053 ;Allocation info for local variables in function 'fan_fast'
                                   5054 ;------------------------------------------------------------
                                   5055 ;x             Allocated to registers r4 r5 r6 r7 
                                   5056 ;------------------------------------------------------------
                           001A0B  5057 	Fcontroller_8051$fan_fast$0$0 ==.
                           001A0B  5058 	C$controller_8051.c$33$1_0$57 ==.
                                   5059 ;	../../controller_8051.c:33: FUZZY_VAR(fan_fast,         FUZZY_SHAPE_RAMP, HEDGE_NONE, 40.0f, 80.0f, true)
                                   5060 ;	-----------------------------------------
                                   5061 ;	 function fan_fast
                                   5062 ;	-----------------------------------------
      001AC2                       5063 _fan_fast:
      001AC2 AC 82            [24] 5064 	mov	r4,dpl
      001AC4 AD 83            [24] 5065 	mov	r5,dph
      001AC6 AE F0            [24] 5066 	mov	r6,b
      001AC8 FF               [12] 5067 	mov	r7,a
      001AC9 C0 04            [24] 5068 	push	ar4
      001ACB C0 05            [24] 5069 	push	ar5
      001ACD C0 06            [24] 5070 	push	ar6
      001ACF C0 07            [24] 5071 	push	ar7
      001AD1 90 20 F4         [24] 5072 	mov	dptr,#_fan_fast_fuzzy_variable
      001AD4 75 F0 80         [24] 5073 	mov	b, #0x80
      001AD7 12 0E 5F         [24] 5074 	lcall	_fuzzy_8051_eval
      001ADA AC 82            [24] 5075 	mov	r4, dpl
      001ADC AD 83            [24] 5076 	mov	r5, dph
      001ADE AE F0            [24] 5077 	mov	r6, b
      001AE0 FF               [12] 5078 	mov	r7, a
      001AE1 E5 81            [12] 5079 	mov	a,sp
      001AE3 24 FC            [12] 5080 	add	a,#0xfc
      001AE5 F5 81            [12] 5081 	mov	sp,a
      001AE7 8C 82            [24] 5082 	mov	dpl, r4
      001AE9 8D 83            [24] 5083 	mov	dph, r5
      001AEB 8E F0            [24] 5084 	mov	b, r6
      001AED EF               [12] 5085 	mov	a, r7
                           001A37  5086 	C$controller_8051.c$33$1_0$57 ==.
                           001A37  5087 	XFcontroller_8051$fan_fast$0$0 ==.
      001AEE 22               [24] 5088 	ret
                                   5089 ;------------------------------------------------------------
                                   5090 ;Allocation info for local variables in function 'calculate_fan_speed'
                                   5091 ;------------------------------------------------------------
                                   5092 ;temperature   Allocated to stack - _bp +1 +4 
                                   5093 ;------------------------------------------------------------
                           001A38  5094 	Fcontroller_8051$calculate_fan_speed$0$0 ==.
                           001A38  5095 	C$controller_8051.c$35$1_0$59 ==.
                                   5096 ;	../../controller_8051.c:35: static float calculate_fan_speed(float temperature)
                                   5097 ;	-----------------------------------------
                                   5098 ;	 function calculate_fan_speed
                                   5099 ;	-----------------------------------------
      001AEF                       5100 _calculate_fan_speed:
      001AEF C0 1D            [24] 5101 	push	_bp
      001AF1 85 81 1D         [24] 5102 	mov	_bp,sp
      001AF4 C0 82            [24] 5103 	push	dpl
      001AF6 C0 83            [24] 5104 	push	dph
      001AF8 C0 F0            [24] 5105 	push	b
      001AFA C0 E0            [24] 5106 	push	acc
                           001A45  5107 	C$controller_8051.c$37$1_0$59 ==.
                                   5108 ;	../../controller_8051.c:37: rules.count = 0u;
      001AFC 75 16 00         [24] 5109 	mov	(_rules + 0x000e),#0x00
                           001A48  5110 	C$controller_8051.c$39$1_0$59 ==.
                                   5111 ;	../../controller_8051.c:39: RULE(rules, "Low temperature produces slow fan", temperature_low(temperature), fan_slow);
      001AFF A8 1D            [24] 5112 	mov	r0,_bp
      001B01 08               [12] 5113 	inc	r0
      001B02 86 82            [24] 5114 	mov	dpl, @r0
      001B04 08               [12] 5115 	inc	r0
      001B05 86 83            [24] 5116 	mov	dph, @r0
      001B07 08               [12] 5117 	inc	r0
      001B08 86 F0            [24] 5118 	mov	b, @r0
      001B0A 08               [12] 5119 	inc	r0
      001B0B E6               [12] 5120 	mov	a, @r0
      001B0C 12 1A 3B         [24] 5121 	lcall	_temperature_low
      001B0F AA 82            [24] 5122 	mov	r2, dpl
      001B11 AB 83            [24] 5123 	mov	r3, dph
      001B13 AE F0            [24] 5124 	mov	r6, b
      001B15 FF               [12] 5125 	mov	r7, a
      001B16 74 E2            [12] 5126 	mov	a,#_fan_slow_fuzzy_variable
      001B18 C0 E0            [24] 5127 	push	acc
      001B1A 74 20            [12] 5128 	mov	a,#(_fan_slow_fuzzy_variable >> 8)
      001B1C C0 E0            [24] 5129 	push	acc
      001B1E 74 80            [12] 5130 	mov	a,#0x80
      001B20 C0 E0            [24] 5131 	push	acc
      001B22 C0 02            [24] 5132 	push	ar2
      001B24 C0 03            [24] 5133 	push	ar3
      001B26 C0 06            [24] 5134 	push	ar6
      001B28 C0 07            [24] 5135 	push	ar7
      001B2A 90 00 08         [24] 5136 	mov	dptr,#_rules
      001B2D 75 F0 40         [24] 5137 	mov	b, #0x40
      001B30 12 11 F0         [24] 5138 	lcall	_fuzzy_rules_add_8051
      001B33 E5 81            [12] 5139 	mov	a,sp
      001B35 24 F9            [12] 5140 	add	a,#0xf9
      001B37 F5 81            [12] 5141 	mov	sp,a
                           001A82  5142 	C$controller_8051.c$41$1_0$59 ==.
                                   5143 ;	../../controller_8051.c:41: RULE(rules, "High temperature produces fast fan", temperature_high(temperature), fan_fast);
      001B39 A8 1D            [24] 5144 	mov	r0,_bp
      001B3B 08               [12] 5145 	inc	r0
      001B3C 86 82            [24] 5146 	mov	dpl, @r0
      001B3E 08               [12] 5147 	inc	r0
      001B3F 86 83            [24] 5148 	mov	dph, @r0
      001B41 08               [12] 5149 	inc	r0
      001B42 86 F0            [24] 5150 	mov	b, @r0
      001B44 08               [12] 5151 	inc	r0
      001B45 E6               [12] 5152 	mov	a, @r0
      001B46 12 1A 68         [24] 5153 	lcall	_temperature_high
      001B49 AC 82            [24] 5154 	mov	r4, dpl
      001B4B AD 83            [24] 5155 	mov	r5, dph
      001B4D AE F0            [24] 5156 	mov	r6, b
      001B4F FF               [12] 5157 	mov	r7, a
      001B50 74 F4            [12] 5158 	mov	a,#_fan_fast_fuzzy_variable
      001B52 C0 E0            [24] 5159 	push	acc
      001B54 74 20            [12] 5160 	mov	a,#(_fan_fast_fuzzy_variable >> 8)
      001B56 C0 E0            [24] 5161 	push	acc
      001B58 74 80            [12] 5162 	mov	a,#0x80
      001B5A C0 E0            [24] 5163 	push	acc
      001B5C C0 04            [24] 5164 	push	ar4
      001B5E C0 05            [24] 5165 	push	ar5
      001B60 C0 06            [24] 5166 	push	ar6
      001B62 C0 07            [24] 5167 	push	ar7
      001B64 90 00 08         [24] 5168 	mov	dptr,#_rules
      001B67 75 F0 40         [24] 5169 	mov	b, #0x40
      001B6A 12 11 F0         [24] 5170 	lcall	_fuzzy_rules_add_8051
      001B6D E5 81            [12] 5171 	mov	a,sp
      001B6F 24 F9            [12] 5172 	add	a,#0xf9
      001B71 F5 81            [12] 5173 	mov	sp,a
                           001ABC  5174 	C$controller_8051.c$43$1_0$59 ==.
                                   5175 ;	../../controller_8051.c:43: return fuzzy_rules_defuzzify(&rules, 0.0f, 100.0f, 10.0f, FUZZY_DEFUZZ_BOA);
      001B73 74 01            [12] 5176 	mov	a,#0x01
      001B75 C0 E0            [24] 5177 	push	acc
      001B77 E4               [12] 5178 	clr	a
      001B78 C0 E0            [24] 5179 	push	acc
      001B7A C0 E0            [24] 5180 	push	acc
      001B7C 74 20            [12] 5181 	mov	a,#0x20
      001B7E C0 E0            [24] 5182 	push	acc
      001B80 74 41            [12] 5183 	mov	a,#0x41
      001B82 C0 E0            [24] 5184 	push	acc
      001B84 E4               [12] 5185 	clr	a
      001B85 C0 E0            [24] 5186 	push	acc
      001B87 C0 E0            [24] 5187 	push	acc
      001B89 74 C8            [12] 5188 	mov	a,#0xc8
      001B8B C0 E0            [24] 5189 	push	acc
      001B8D 74 42            [12] 5190 	mov	a,#0x42
      001B8F C0 E0            [24] 5191 	push	acc
      001B91 E4               [12] 5192 	clr	a
      001B92 C0 E0            [24] 5193 	push	acc
      001B94 C0 E0            [24] 5194 	push	acc
      001B96 C0 E0            [24] 5195 	push	acc
      001B98 C0 E0            [24] 5196 	push	acc
      001B9A 90 00 08         [24] 5197 	mov	dptr,#_rules
      001B9D 75 F0 40         [24] 5198 	mov	b, #0x40
      001BA0 12 14 8D         [24] 5199 	lcall	_fuzzy_rules_defuzzify
      001BA3 AC 82            [24] 5200 	mov	r4, dpl
      001BA5 AD 83            [24] 5201 	mov	r5, dph
      001BA7 AE F0            [24] 5202 	mov	r6, b
      001BA9 FF               [12] 5203 	mov	r7, a
      001BAA E5 81            [12] 5204 	mov	a,sp
      001BAC 24 F3            [12] 5205 	add	a,#0xf3
      001BAE F5 81            [12] 5206 	mov	sp,a
      001BB0 8C 82            [24] 5207 	mov	dpl, r4
      001BB2 8D 83            [24] 5208 	mov	dph, r5
      001BB4 8E F0            [24] 5209 	mov	b, r6
      001BB6 EF               [12] 5210 	mov	a, r7
                           001B00  5211 	C$controller_8051.c$44$1_0$59 ==.
                                   5212 ;	../../controller_8051.c:44: }
      001BB7 85 1D 81         [24] 5213 	mov	sp,_bp
      001BBA D0 1D            [24] 5214 	pop	_bp
                           001B05  5215 	C$controller_8051.c$44$1_0$59 ==.
                           001B05  5216 	XFcontroller_8051$calculate_fan_speed$0$0 ==.
      001BBC 22               [24] 5217 	ret
                                   5218 ;------------------------------------------------------------
                                   5219 ;Allocation info for local variables in function 'fan_speed_to_pwm'
                                   5220 ;------------------------------------------------------------
                                   5221 ;fan_speed     Allocated to registers r4 r5 r6 r7 
                                   5222 ;------------------------------------------------------------
                           001B06  5223 	Fcontroller_8051$fan_speed_to_pwm$0$0 ==.
                           001B06  5224 	C$controller_8051.c$46$1_0$61 ==.
                                   5225 ;	../../controller_8051.c:46: static unsigned char fan_speed_to_pwm(float fan_speed)
                                   5226 ;	-----------------------------------------
                                   5227 ;	 function fan_speed_to_pwm
                                   5228 ;	-----------------------------------------
      001BBD                       5229 _fan_speed_to_pwm:
      001BBD AC 82            [24] 5230 	mov	r4,dpl
      001BBF AD 83            [24] 5231 	mov	r5,dph
      001BC1 AE F0            [24] 5232 	mov	r6,b
      001BC3 FF               [12] 5233 	mov	r7,a
                           001B0D  5234 	C$controller_8051.c$48$1_0$61 ==.
                                   5235 ;	../../controller_8051.c:48: if (fan_speed <= 0.0f)
      001BC4 C0 07            [24] 5236 	push	ar7
      001BC6 C0 06            [24] 5237 	push	ar6
      001BC8 C0 05            [24] 5238 	push	ar5
      001BCA C0 04            [24] 5239 	push	ar4
      001BCC C0 04            [24] 5240 	push	ar4
      001BCE C0 05            [24] 5241 	push	ar5
      001BD0 C0 06            [24] 5242 	push	ar6
      001BD2 C0 07            [24] 5243 	push	ar7
      001BD4 90 00 00         [24] 5244 	mov	dptr,#0x0000
      001BD7 E4               [12] 5245 	clr	a
      001BD8 F5 F0            [12] 5246 	mov	b,a
      001BDA 12 1D F2         [24] 5247 	lcall	___fslt
      001BDD E5 81            [12] 5248 	mov	a,sp
      001BDF 24 FC            [12] 5249 	add	a,#0xfc
      001BE1 F5 81            [12] 5250 	mov	sp,a
      001BE3 D0 04            [24] 5251 	pop	ar4
      001BE5 D0 05            [24] 5252 	pop	ar5
      001BE7 D0 06            [24] 5253 	pop	ar6
      001BE9 D0 07            [24] 5254 	pop	ar7
      001BEB E5 82            [12] 5255 	mov	a, dpl
      001BED 24 FF            [12] 5256 	add	a,#0xff
      001BEF 92 00            [24] 5257 	mov	b0,c
      001BF1 40 05            [24] 5258 	jc	00102$
                           001B3C  5259 	C$controller_8051.c$49$1_0$61 ==.
                                   5260 ;	../../controller_8051.c:49: return 0u;
      001BF3 75 82 00         [24] 5261 	mov	dpl, #0x00
      001BF6 80 66            [24] 5262 	sjmp	00105$
      001BF8                       5263 00102$:
                           001B41  5264 	C$controller_8051.c$51$1_0$61 ==.
                                   5265 ;	../../controller_8051.c:51: if (fan_speed >= 100.0f)
      001BF8 C0 07            [24] 5266 	push	ar7
      001BFA C0 06            [24] 5267 	push	ar6
      001BFC C0 05            [24] 5268 	push	ar5
      001BFE C0 04            [24] 5269 	push	ar4
      001C00 E4               [12] 5270 	clr	a
      001C01 C0 E0            [24] 5271 	push	acc
      001C03 C0 E0            [24] 5272 	push	acc
      001C05 74 C8            [12] 5273 	mov	a,#0xc8
      001C07 C0 E0            [24] 5274 	push	acc
      001C09 74 42            [12] 5275 	mov	a,#0x42
      001C0B C0 E0            [24] 5276 	push	acc
      001C0D 8C 82            [24] 5277 	mov	dpl, r4
      001C0F 8D 83            [24] 5278 	mov	dph, r5
      001C11 8E F0            [24] 5279 	mov	b, r6
      001C13 EF               [12] 5280 	mov	a, r7
      001C14 12 1D F2         [24] 5281 	lcall	___fslt
      001C17 E5 81            [12] 5282 	mov	a,sp
      001C19 24 FC            [12] 5283 	add	a,#0xfc
      001C1B F5 81            [12] 5284 	mov	sp,a
      001C1D D0 04            [24] 5285 	pop	ar4
      001C1F D0 05            [24] 5286 	pop	ar5
      001C21 D0 06            [24] 5287 	pop	ar6
      001C23 D0 07            [24] 5288 	pop	ar7
      001C25 E5 82            [12] 5289 	mov	a, dpl
      001C27 24 FF            [12] 5290 	add	a,#0xff
      001C29 92 00            [24] 5291 	mov	b0,c
      001C2B 40 05            [24] 5292 	jc	00104$
                           001B76  5293 	C$controller_8051.c$52$1_0$61 ==.
                                   5294 ;	../../controller_8051.c:52: return 100u;
      001C2D 75 82 64         [24] 5295 	mov	dpl, #0x64
      001C30 80 2C            [24] 5296 	sjmp	00105$
      001C32                       5297 00104$:
                           001B7B  5298 	C$controller_8051.c$54$1_0$61 ==.
                                   5299 ;	../../controller_8051.c:54: return (unsigned char)(fan_speed + 0.5f);
      001C32 E4               [12] 5300 	clr	a
      001C33 C0 E0            [24] 5301 	push	acc
      001C35 C0 E0            [24] 5302 	push	acc
      001C37 C0 E0            [24] 5303 	push	acc
      001C39 74 3F            [12] 5304 	mov	a,#0x3f
      001C3B C0 E0            [24] 5305 	push	acc
      001C3D 8C 82            [24] 5306 	mov	dpl, r4
      001C3F 8D 83            [24] 5307 	mov	dph, r5
      001C41 8E F0            [24] 5308 	mov	b, r6
      001C43 EF               [12] 5309 	mov	a, r7
      001C44 12 1E 22         [24] 5310 	lcall	___fsadd
      001C47 AC 82            [24] 5311 	mov	r4, dpl
      001C49 AD 83            [24] 5312 	mov	r5, dph
      001C4B AE F0            [24] 5313 	mov	r6, b
      001C4D FF               [12] 5314 	mov	r7, a
      001C4E E5 81            [12] 5315 	mov	a,sp
      001C50 24 FC            [12] 5316 	add	a,#0xfc
      001C52 F5 81            [12] 5317 	mov	sp,a
      001C54 8C 82            [24] 5318 	mov	dpl, r4
      001C56 8D 83            [24] 5319 	mov	dph, r5
      001C58 8E F0            [24] 5320 	mov	b, r6
      001C5A EF               [12] 5321 	mov	a, r7
      001C5B 12 20 18         [24] 5322 	lcall	___fs2uchar
      001C5E                       5323 00105$:
                           001BA7  5324 	C$controller_8051.c$55$1_0$61 ==.
                                   5325 ;	../../controller_8051.c:55: }
                           001BA7  5326 	C$controller_8051.c$55$1_0$61 ==.
                           001BA7  5327 	XFcontroller_8051$fan_speed_to_pwm$0$0 ==.
      001C5E 22               [24] 5328 	ret
                                   5329 ;------------------------------------------------------------
                                   5330 ;Allocation info for local variables in function 'update_controller'
                                   5331 ;------------------------------------------------------------
                                   5332 ;temperature   Allocated to registers 
                                   5333 ;------------------------------------------------------------
                           001BA8  5334 	Fcontroller_8051$update_controller$0$0 ==.
                           001BA8  5335 	C$controller_8051.c$57$1_0$63 ==.
                                   5336 ;	../../controller_8051.c:57: static void update_controller(unsigned char temperature)
                                   5337 ;	-----------------------------------------
                                   5338 ;	 function update_controller
                                   5339 ;	-----------------------------------------
      001C5F                       5340 _update_controller:
      001C5F 85 82 17         [24] 5341 	mov	_test_temperature,dpl
                           001BAB  5342 	C$controller_8051.c$60$1_0$63 ==.
                                   5343 ;	../../controller_8051.c:60: test_fan_speed = calculate_fan_speed((float)test_temperature);
      001C62 85 17 82         [24] 5344 	mov	dpl, _test_temperature
      001C65 12 20 20         [24] 5345 	lcall	___uchar2fs
      001C68 12 1A EF         [24] 5346 	lcall	_calculate_fan_speed
      001C6B 85 82 19         [24] 5347 	mov	_test_fan_speed,dpl
      001C6E 85 83 1A         [24] 5348 	mov	(_test_fan_speed + 1),dph
      001C71 85 F0 1B         [24] 5349 	mov	(_test_fan_speed + 2),b
      001C74 F5 1C            [12] 5350 	mov	(_test_fan_speed + 3),a
                           001BBF  5351 	C$controller_8051.c$61$1_0$63 ==.
                                   5352 ;	../../controller_8051.c:61: test_pwm = fan_speed_to_pwm(test_fan_speed);
      001C76 85 19 82         [24] 5353 	mov	dpl, _test_fan_speed
      001C79 85 1A 83         [24] 5354 	mov	dph, (_test_fan_speed + 1)
      001C7C 85 1B F0         [24] 5355 	mov	b, (_test_fan_speed + 2)
      001C7F E5 1C            [12] 5356 	mov	a, (_test_fan_speed + 3)
      001C81 12 1B BD         [24] 5357 	lcall	_fan_speed_to_pwm
      001C84 85 82 18         [24] 5358 	mov	_test_pwm,dpl
                           001BD0  5359 	C$controller_8051.c$62$1_0$63 ==.
                                   5360 ;	../../controller_8051.c:62: }
                           001BD0  5361 	C$controller_8051.c$62$1_0$63 ==.
                           001BD0  5362 	XFcontroller_8051$update_controller$0$0 ==.
      001C87 22               [24] 5363 	ret
                                   5364 ;------------------------------------------------------------
                                   5365 ;Allocation info for local variables in function 'main'
                                   5366 ;------------------------------------------------------------
                           001BD1  5367 	G$main$0$0 ==.
                           001BD1  5368 	C$controller_8051.c$66$1_0$65 ==.
                                   5369 ;	../../controller_8051.c:66: void main(void)
                                   5370 ;	-----------------------------------------
                                   5371 ;	 function main
                                   5372 ;	-----------------------------------------
      001C88                       5373 _main:
                           001BD1  5374 	C$controller_8051.c$68$1_0$65 ==.
                                   5375 ;	../../controller_8051.c:68: P0 = 0x00u;
      001C88 75 80 00         [24] 5376 	mov	_P0,#0x00
                           001BD4  5377 	C$controller_8051.c$69$1_0$65 ==.
                                   5378 ;	../../controller_8051.c:69: P1 = 0x00u;
      001C8B 75 90 00         [24] 5379 	mov	_P1,#0x00
      001C8E                       5380 00105$:
                           001BD7  5381 	C$controller_8051.c$72$3_0$67 ==.
                                   5382 ;	../../controller_8051.c:72: P0 = 0x55u;
      001C8E 75 80 55         [24] 5383 	mov	_P0,#0x55
                           001BDA  5384 	C$controller_8051.c$74$3_0$67 ==.
                                   5385 ;	../../controller_8051.c:74: test_temperature = P2;
      001C91 85 A0 17         [24] 5386 	mov	_test_temperature,_P2
                           001BDD  5387 	C$controller_8051.c$76$3_0$67 ==.
                                   5388 ;	../../controller_8051.c:76: if (test_temperature > 100u) {
      001C94 E5 17            [12] 5389 	mov	a,_test_temperature
      001C96 24 9B            [12] 5390 	add	a,#0xff - 0x64
      001C98 50 08            [24] 5391 	jnc	00102$
                           001BE3  5392 	C$controller_8051.c$77$4_0$68 ==.
                                   5393 ;	../../controller_8051.c:77: P1 = 0x00u;
      001C9A 75 90 00         [24] 5394 	mov	_P1,#0x00
                           001BE6  5395 	C$controller_8051.c$78$4_0$68 ==.
                                   5396 ;	../../controller_8051.c:78: P0 = 0xF0u;
      001C9D 75 80 F0         [24] 5397 	mov	_P0,#0xf0
                           001BE9  5398 	C$controller_8051.c$79$4_0$68 ==.
                                   5399 ;	../../controller_8051.c:79: continue;
      001CA0 80 EC            [24] 5400 	sjmp	00105$
      001CA2                       5401 00102$:
                           001BEB  5402 	C$controller_8051.c$82$3_0$67 ==.
                                   5403 ;	../../controller_8051.c:82: P0 = 0x60u;
      001CA2 75 80 60         [24] 5404 	mov	_P0,#0x60
                           001BEE  5405 	C$controller_8051.c$83$3_0$67 ==.
                                   5406 ;	../../controller_8051.c:83: update_controller(test_temperature);
      001CA5 85 17 82         [24] 5407 	mov	dpl, _test_temperature
      001CA8 12 1C 5F         [24] 5408 	lcall	_update_controller
                           001BF4  5409 	C$controller_8051.c$84$3_0$67 ==.
                                   5410 ;	../../controller_8051.c:84: P0 = 0x70u;
      001CAB 75 80 70         [24] 5411 	mov	_P0,#0x70
                           001BF7  5412 	C$controller_8051.c$85$3_0$67 ==.
                                   5413 ;	../../controller_8051.c:85: P1 = test_pwm;
      001CAE 85 18 90         [24] 5414 	mov	_P1,_test_pwm
                           001BFA  5415 	C$controller_8051.c$86$3_0$67 ==.
                                   5416 ;	../../controller_8051.c:86: P0 = 0xAAu;
      001CB1 75 80 AA         [24] 5417 	mov	_P0,#0xaa
      001CB4 80 D8            [24] 5418 	sjmp	00105$
                           001BFF  5419 	C$controller_8051.c$88$2_0$65 ==.
                                   5420 ;	../../controller_8051.c:88: }
                           001BFF  5421 	C$controller_8051.c$88$2_0$65 ==.
                           001BFF  5422 	XG$main$0$0 ==.
      001CB6 22               [24] 5423 	ret
                                   5424 	.area CSEG    (CODE)
                                   5425 	.area CONST   (CODE)
                                   5426 	.area CONST   (CODE)
                           000000  5427 Fcontroller_8051$temperature_low_fuzzy_variable$0_0$0 == .
      0020BE                       5428 _temperature_low_fuzzy_variable:
      0020BE 00                    5429 	.db #0x00	; 0
      0020BF 01                    5430 	.db #0x01	; 1
      0020C0 00 00 A0 41           5431 	.byte #0x00, #0x00, #0xa0, #0x41	;  2.000000e+01
      0020C4 00 00 20 42           5432 	.byte #0x00, #0x00, #0x20, #0x42	;  4.000000e+01
      0020C8 00 00 00 00           5433 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
      0020CC 00 00 00 00           5434 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   5435 	.area CSEG    (CODE)
                                   5436 	.area CONST   (CODE)
                           000012  5437 Fcontroller_8051$temperature_high_fuzzy_variable$0_0$0 == .
      0020D0                       5438 _temperature_high_fuzzy_variable:
      0020D0 00                    5439 	.db #0x00	; 0
      0020D1 01                    5440 	.db #0x01	; 1
      0020D2 00 00 F0 41           5441 	.byte #0x00, #0x00, #0xf0, #0x41	;  3.000000e+01
      0020D6 00 00 70 42           5442 	.byte #0x00, #0x00, #0x70, #0x42	;  6.000000e+01
      0020DA 00 00 80 3F           5443 	.byte #0x00, #0x00, #0x80, #0x3f	;  1.000000e+00
      0020DE 00 00 00 00           5444 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   5445 	.area CSEG    (CODE)
                                   5446 	.area CONST   (CODE)
                           000024  5447 Fcontroller_8051$fan_slow_fuzzy_variable$0_0$0 == .
      0020E2                       5448 _fan_slow_fuzzy_variable:
      0020E2 00                    5449 	.db #0x00	; 0
      0020E3 01                    5450 	.db #0x01	; 1
      0020E4 00 00 A0 41           5451 	.byte #0x00, #0x00, #0xa0, #0x41	;  2.000000e+01
      0020E8 00 00 48 42           5452 	.byte #0x00, #0x00, #0x48, #0x42	;  5.000000e+01
      0020EC 00 00 00 00           5453 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
      0020F0 00 00 00 00           5454 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   5455 	.area CSEG    (CODE)
                                   5456 	.area CONST   (CODE)
                           000036  5457 Fcontroller_8051$fan_fast_fuzzy_variable$0_0$0 == .
      0020F4                       5458 _fan_fast_fuzzy_variable:
      0020F4 00                    5459 	.db #0x00	; 0
      0020F5 01                    5460 	.db #0x01	; 1
      0020F6 00 00 20 42           5461 	.byte #0x00, #0x00, #0x20, #0x42	;  4.000000e+01
      0020FA 00 00 A0 42           5462 	.byte #0x00, #0x00, #0xa0, #0x42	;  8.000000e+01
      0020FE 00 00 80 3F           5463 	.byte #0x00, #0x00, #0x80, #0x3f	;  1.000000e+00
      002102 00 00 00 00           5464 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   5465 	.area CSEG    (CODE)
                                   5466 	.area XINIT   (CODE)
                                   5467 	.area CABS    (ABS,CODE)
