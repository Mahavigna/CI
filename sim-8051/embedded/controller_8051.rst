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
                           000000   550 	C$controller_8051.c$36$2_0$119 ==.
                                    551 ;	../../controller_8051.c:36: volatile unsigned char test_temperature = 0u;
      0000A5 75 17 00         [24]  552 	mov	_test_temperature,#0x00
                           000003   553 	C$controller_8051.c$37$2_0$119 ==.
                                    554 ;	../../controller_8051.c:37: volatile unsigned char test_pwm = 0u;
      0000A8 75 18 00         [24]  555 	mov	_test_pwm,#0x00
                           000006   556 	C$controller_8051.c$38$2_0$119 ==.
                                    557 ;	../../controller_8051.c:38: volatile float test_fan_speed = 0.0f;
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
      000049 02 1C A3         [24]  571 	ljmp	_main
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
                           000000   586 	C$fuzzy.h$116$0_0$35 ==.
                                    587 ;	../../fuzzy.h:116: static float fuzzy_8051_and2(fuzzy_logic_method_t method, float a, float b)
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
                           000007   603 	C$fuzzy.h$118$1_0$35 ==.
                                    604 ;	../../fuzzy.h:118: if (method == FUZZY_LOGIC_ALGEBRAIC) {
      0000BE BF 01 3D         [24]  605 	cjne	r7,#0x01,00102$
                           00000A   606 	C$fuzzy.h$119$1_0$35 ==.
                                    607 ;	../../fuzzy.h:119: return a * b;
      0000C1 E5 1D            [12]  608 	mov	a,_bp
      0000C3 24 F6            [12]  609 	add	a,#0xf6
      0000C5 F8               [12]  610 	mov	r0,a
      0000C6 E6               [12]  611 	mov	a,@r0
      0000C7 C0 E0            [24]  612 	push	acc
      0000C9 08               [12]  613 	inc	r0
      0000CA E6               [12]  614 	mov	a,@r0
      0000CB C0 E0            [24]  615 	push	acc
      0000CD 08               [12]  616 	inc	r0
      0000CE E6               [12]  617 	mov	a,@r0
      0000CF C0 E0            [24]  618 	push	acc
      0000D1 08               [12]  619 	inc	r0
      0000D2 E6               [12]  620 	mov	a,@r0
      0000D3 C0 E0            [24]  621 	push	acc
      0000D5 E5 1D            [12]  622 	mov	a,_bp
      0000D7 24 FA            [12]  623 	add	a,#0xfa
      0000D9 F8               [12]  624 	mov	r0,a
      0000DA 86 82            [24]  625 	mov	dpl, @r0
      0000DC 08               [12]  626 	inc	r0
      0000DD 86 83            [24]  627 	mov	dph, @r0
      0000DF 08               [12]  628 	inc	r0
      0000E0 86 F0            [24]  629 	mov	b, @r0
      0000E2 08               [12]  630 	inc	r0
      0000E3 E6               [12]  631 	mov	a, @r0
      0000E4 12 1C DD         [24]  632 	lcall	___fsmul
      0000E7 AB 82            [24]  633 	mov	r3, dpl
      0000E9 AC 83            [24]  634 	mov	r4, dph
      0000EB AD F0            [24]  635 	mov	r5, b
      0000ED FE               [12]  636 	mov	r6, a
      0000EE E5 81            [12]  637 	mov	a,sp
      0000F0 24 FC            [12]  638 	add	a,#0xfc
      0000F2 F5 81            [12]  639 	mov	sp,a
      0000F4 8B 82            [24]  640 	mov	dpl, r3
      0000F6 8C 83            [24]  641 	mov	dph, r4
      0000F8 8D F0            [24]  642 	mov	b, r5
      0000FA EE               [12]  643 	mov	a, r6
      0000FB 02 01 F0         [24]  644 	ljmp	00105$
      0000FE                        645 00102$:
                           000047   646 	C$fuzzy.h$122$1_0$35 ==.
                                    647 ;	../../fuzzy.h:122: if (method == FUZZY_LOGIC_BOUNDED) {
      0000FE BF 02 02         [24]  648 	cjne	r7,#0x02,00137$
      000101 80 03            [24]  649 	sjmp	00138$
      000103                        650 00137$:
      000103 02 01 96         [24]  651 	ljmp	00104$
      000106                        652 00138$:
                           00004F   653 	C$fuzzy.h$123$1_0$35 ==.
                                    654 ;	../../fuzzy.h:123: float value = a + b - 1.0f;
      000106 E5 1D            [12]  655 	mov	a,_bp
      000108 24 F6            [12]  656 	add	a,#0xf6
      00010A F8               [12]  657 	mov	r0,a
      00010B E6               [12]  658 	mov	a,@r0
      00010C C0 E0            [24]  659 	push	acc
      00010E 08               [12]  660 	inc	r0
      00010F E6               [12]  661 	mov	a,@r0
      000110 C0 E0            [24]  662 	push	acc
      000112 08               [12]  663 	inc	r0
      000113 E6               [12]  664 	mov	a,@r0
      000114 C0 E0            [24]  665 	push	acc
      000116 08               [12]  666 	inc	r0
      000117 E6               [12]  667 	mov	a,@r0
      000118 C0 E0            [24]  668 	push	acc
      00011A E5 1D            [12]  669 	mov	a,_bp
      00011C 24 FA            [12]  670 	add	a,#0xfa
      00011E F8               [12]  671 	mov	r0,a
      00011F 86 82            [24]  672 	mov	dpl, @r0
      000121 08               [12]  673 	inc	r0
      000122 86 83            [24]  674 	mov	dph, @r0
      000124 08               [12]  675 	inc	r0
      000125 86 F0            [24]  676 	mov	b, @r0
      000127 08               [12]  677 	inc	r0
      000128 E6               [12]  678 	mov	a, @r0
      000129 12 1E 3D         [24]  679 	lcall	___fsadd
      00012C AC 82            [24]  680 	mov	r4, dpl
      00012E AD 83            [24]  681 	mov	r5, dph
      000130 AE F0            [24]  682 	mov	r6, b
      000132 FF               [12]  683 	mov	r7, a
      000133 E5 81            [12]  684 	mov	a,sp
      000135 24 FC            [12]  685 	add	a,#0xfc
      000137 F5 81            [12]  686 	mov	sp,a
      000139 E4               [12]  687 	clr	a
      00013A C0 E0            [24]  688 	push	acc
      00013C C0 E0            [24]  689 	push	acc
      00013E 74 80            [12]  690 	mov	a,#0x80
      000140 C0 E0            [24]  691 	push	acc
      000142 74 3F            [12]  692 	mov	a,#0x3f
      000144 C0 E0            [24]  693 	push	acc
                           00008F   694 	C$fuzzy.h$124$1_0$35 ==.
                                    695 ;	../../fuzzy.h:124: return value > 0.0f ? value : 0.0f;
      000146 8C 82            [24]  696 	mov	dpl, r4
      000148 8D 83            [24]  697 	mov	dph, r5
      00014A 8E F0            [24]  698 	mov	b, r6
      00014C EF               [12]  699 	mov	a, r7
      00014D 12 1C D2         [24]  700 	lcall	___fssub
      000150 AC 82            [24]  701 	mov	r4, dpl
      000152 AD 83            [24]  702 	mov	r5, dph
      000154 AE F0            [24]  703 	mov	r6, b
      000156 FF               [12]  704 	mov	r7, a
      000157 E5 81            [12]  705 	mov	a,sp
      000159 24 FC            [12]  706 	add	a,#0xfc
      00015B F5 81            [12]  707 	mov	sp,a
      00015D C0 07            [24]  708 	push	ar7
      00015F C0 06            [24]  709 	push	ar6
      000161 C0 05            [24]  710 	push	ar5
      000163 C0 04            [24]  711 	push	ar4
      000165 C0 04            [24]  712 	push	ar4
      000167 C0 05            [24]  713 	push	ar5
      000169 C0 06            [24]  714 	push	ar6
      00016B C0 07            [24]  715 	push	ar7
      00016D 90 00 00         [24]  716 	mov	dptr,#0x0000
      000170 E4               [12]  717 	clr	a
      000171 F5 F0            [12]  718 	mov	b,a
      000173 12 1E 0D         [24]  719 	lcall	___fslt
      000176 AB 82            [24]  720 	mov	r3, dpl
      000178 E5 81            [12]  721 	mov	a,sp
      00017A 24 FC            [12]  722 	add	a,#0xfc
      00017C F5 81            [12]  723 	mov	sp,a
      00017E D0 04            [24]  724 	pop	ar4
      000180 D0 05            [24]  725 	pop	ar5
      000182 D0 06            [24]  726 	pop	ar6
      000184 D0 07            [24]  727 	pop	ar7
      000186 EB               [12]  728 	mov	a,r3
      000187 70 04            [24]  729 	jnz	00108$
      000189 FC               [12]  730 	mov	r4,a
      00018A FD               [12]  731 	mov	r5,a
      00018B FE               [12]  732 	mov	r6,a
      00018C FF               [12]  733 	mov	r7,a
      00018D                        734 00108$:
      00018D 8C 82            [24]  735 	mov	dpl, r4
      00018F 8D 83            [24]  736 	mov	dph, r5
      000191 8E F0            [24]  737 	mov	b, r6
      000193 EF               [12]  738 	mov	a, r7
      000194 80 5A            [24]  739 	sjmp	00105$
      000196                        740 00104$:
                           0000DF   741 	C$fuzzy.h$127$1_0$35 ==.
                                    742 ;	../../fuzzy.h:127: return a < b ? a : b;
      000196 E5 1D            [12]  743 	mov	a,_bp
      000198 24 F6            [12]  744 	add	a,#0xf6
      00019A F8               [12]  745 	mov	r0,a
      00019B E6               [12]  746 	mov	a,@r0
      00019C C0 E0            [24]  747 	push	acc
      00019E 08               [12]  748 	inc	r0
      00019F E6               [12]  749 	mov	a,@r0
      0001A0 C0 E0            [24]  750 	push	acc
      0001A2 08               [12]  751 	inc	r0
      0001A3 E6               [12]  752 	mov	a,@r0
      0001A4 C0 E0            [24]  753 	push	acc
      0001A6 08               [12]  754 	inc	r0
      0001A7 E6               [12]  755 	mov	a,@r0
      0001A8 C0 E0            [24]  756 	push	acc
      0001AA E5 1D            [12]  757 	mov	a,_bp
      0001AC 24 FA            [12]  758 	add	a,#0xfa
      0001AE F8               [12]  759 	mov	r0,a
      0001AF 86 82            [24]  760 	mov	dpl, @r0
      0001B1 08               [12]  761 	inc	r0
      0001B2 86 83            [24]  762 	mov	dph, @r0
      0001B4 08               [12]  763 	inc	r0
      0001B5 86 F0            [24]  764 	mov	b, @r0
      0001B7 08               [12]  765 	inc	r0
      0001B8 E6               [12]  766 	mov	a, @r0
      0001B9 12 1E 0D         [24]  767 	lcall	___fslt
      0001BC AF 82            [24]  768 	mov	r7, dpl
      0001BE E5 81            [12]  769 	mov	a,sp
      0001C0 24 FC            [12]  770 	add	a,#0xfc
      0001C2 F5 81            [12]  771 	mov	sp,a
      0001C4 EF               [12]  772 	mov	a,r7
      0001C5 60 12            [24]  773 	jz	00109$
      0001C7 E5 1D            [12]  774 	mov	a,_bp
      0001C9 24 FA            [12]  775 	add	a,#0xfa
      0001CB F8               [12]  776 	mov	r0,a
      0001CC 86 04            [24]  777 	mov	ar4,@r0
      0001CE 08               [12]  778 	inc	r0
      0001CF 86 05            [24]  779 	mov	ar5,@r0
      0001D1 08               [12]  780 	inc	r0
      0001D2 86 06            [24]  781 	mov	ar6,@r0
      0001D4 08               [12]  782 	inc	r0
      0001D5 86 07            [24]  783 	mov	ar7,@r0
      0001D7 80 10            [24]  784 	sjmp	00110$
      0001D9                        785 00109$:
      0001D9 E5 1D            [12]  786 	mov	a,_bp
      0001DB 24 F6            [12]  787 	add	a,#0xf6
      0001DD F8               [12]  788 	mov	r0,a
      0001DE 86 04            [24]  789 	mov	ar4,@r0
      0001E0 08               [12]  790 	inc	r0
      0001E1 86 05            [24]  791 	mov	ar5,@r0
      0001E3 08               [12]  792 	inc	r0
      0001E4 86 06            [24]  793 	mov	ar6,@r0
      0001E6 08               [12]  794 	inc	r0
      0001E7 86 07            [24]  795 	mov	ar7,@r0
      0001E9                        796 00110$:
      0001E9 8C 82            [24]  797 	mov	dpl, r4
      0001EB 8D 83            [24]  798 	mov	dph, r5
      0001ED 8E F0            [24]  799 	mov	b, r6
      0001EF EF               [12]  800 	mov	a, r7
      0001F0                        801 00105$:
                           000139   802 	C$fuzzy.h$128$1_0$35 ==.
                                    803 ;	../../fuzzy.h:128: }
      0001F0 D0 1D            [24]  804 	pop	_bp
                           00013B   805 	C$fuzzy.h$128$1_0$35 ==.
                           00013B   806 	XFcontroller_8051$fuzzy_8051_and2$0$0 ==.
      0001F2 22               [24]  807 	ret
                                    808 ;------------------------------------------------------------
                                    809 ;Allocation info for local variables in function 'fuzzy_8051_and3'
                                    810 ;------------------------------------------------------------
                                    811 ;a             Allocated to stack - _bp -6 +4 
                                    812 ;b             Allocated to stack - _bp -10 +4 
                                    813 ;c             Allocated to stack - _bp -14 +4 
                                    814 ;method        Allocated to registers r7 
                                    815 ;------------------------------------------------------------
                           00013C   816 	Fcontroller_8051$fuzzy_8051_and3$0$0 ==.
                           00013C   817 	C$fuzzy.h$130$1_0$39 ==.
                                    818 ;	../../fuzzy.h:130: static float fuzzy_8051_and3(fuzzy_logic_method_t method, float a, float b, float c)
                                    819 ;	-----------------------------------------
                                    820 ;	 function fuzzy_8051_and3
                                    821 ;	-----------------------------------------
      0001F3                        822 _fuzzy_8051_and3:
      0001F3 C0 1D            [24]  823 	push	_bp
      0001F5 85 81 1D         [24]  824 	mov	_bp,sp
      0001F8 AF 82            [24]  825 	mov	r7, dpl
                           000143   826 	C$fuzzy.h$132$1_0$39 ==.
                                    827 ;	../../fuzzy.h:132: return fuzzy_8051_and2(method, fuzzy_8051_and2(method, a, b), c);
      0001FA C0 07            [24]  828 	push	ar7
      0001FC E5 1D            [12]  829 	mov	a,_bp
      0001FE 24 F6            [12]  830 	add	a,#0xf6
      000200 F8               [12]  831 	mov	r0,a
      000201 E6               [12]  832 	mov	a,@r0
      000202 C0 E0            [24]  833 	push	acc
      000204 08               [12]  834 	inc	r0
      000205 E6               [12]  835 	mov	a,@r0
      000206 C0 E0            [24]  836 	push	acc
      000208 08               [12]  837 	inc	r0
      000209 E6               [12]  838 	mov	a,@r0
      00020A C0 E0            [24]  839 	push	acc
      00020C 08               [12]  840 	inc	r0
      00020D E6               [12]  841 	mov	a,@r0
      00020E C0 E0            [24]  842 	push	acc
      000210 E5 1D            [12]  843 	mov	a,_bp
      000212 24 FA            [12]  844 	add	a,#0xfa
      000214 F8               [12]  845 	mov	r0,a
      000215 E6               [12]  846 	mov	a,@r0
      000216 C0 E0            [24]  847 	push	acc
      000218 08               [12]  848 	inc	r0
      000219 E6               [12]  849 	mov	a,@r0
      00021A C0 E0            [24]  850 	push	acc
      00021C 08               [12]  851 	inc	r0
      00021D E6               [12]  852 	mov	a,@r0
      00021E C0 E0            [24]  853 	push	acc
      000220 08               [12]  854 	inc	r0
      000221 E6               [12]  855 	mov	a,@r0
      000222 C0 E0            [24]  856 	push	acc
      000224 8F 82            [24]  857 	mov	dpl, r7
      000226 12 00 B7         [24]  858 	lcall	_fuzzy_8051_and2
      000229 AB 82            [24]  859 	mov	r3, dpl
      00022B AC 83            [24]  860 	mov	r4, dph
      00022D AD F0            [24]  861 	mov	r5, b
      00022F FE               [12]  862 	mov	r6, a
      000230 E5 81            [12]  863 	mov	a,sp
      000232 24 F8            [12]  864 	add	a,#0xf8
      000234 F5 81            [12]  865 	mov	sp,a
      000236 D0 07            [24]  866 	pop	ar7
      000238 E5 1D            [12]  867 	mov	a,_bp
      00023A 24 F2            [12]  868 	add	a,#0xf2
      00023C F8               [12]  869 	mov	r0,a
      00023D E6               [12]  870 	mov	a,@r0
      00023E C0 E0            [24]  871 	push	acc
      000240 08               [12]  872 	inc	r0
      000241 E6               [12]  873 	mov	a,@r0
      000242 C0 E0            [24]  874 	push	acc
      000244 08               [12]  875 	inc	r0
      000245 E6               [12]  876 	mov	a,@r0
      000246 C0 E0            [24]  877 	push	acc
      000248 08               [12]  878 	inc	r0
      000249 E6               [12]  879 	mov	a,@r0
      00024A C0 E0            [24]  880 	push	acc
      00024C C0 03            [24]  881 	push	ar3
      00024E C0 04            [24]  882 	push	ar4
      000250 C0 05            [24]  883 	push	ar5
      000252 C0 06            [24]  884 	push	ar6
      000254 8F 82            [24]  885 	mov	dpl, r7
      000256 12 00 B7         [24]  886 	lcall	_fuzzy_8051_and2
      000259 AC 82            [24]  887 	mov	r4, dpl
      00025B AD 83            [24]  888 	mov	r5, dph
      00025D AE F0            [24]  889 	mov	r6, b
      00025F FF               [12]  890 	mov	r7, a
      000260 E5 81            [12]  891 	mov	a,sp
      000262 24 F8            [12]  892 	add	a,#0xf8
      000264 F5 81            [12]  893 	mov	sp,a
      000266 8C 82            [24]  894 	mov	dpl, r4
      000268 8D 83            [24]  895 	mov	dph, r5
      00026A 8E F0            [24]  896 	mov	b, r6
      00026C EF               [12]  897 	mov	a, r7
                           0001B6   898 	C$fuzzy.h$133$1_0$39 ==.
                                    899 ;	../../fuzzy.h:133: }
      00026D D0 1D            [24]  900 	pop	_bp
                           0001B8   901 	C$fuzzy.h$133$1_0$39 ==.
                           0001B8   902 	XFcontroller_8051$fuzzy_8051_and3$0$0 ==.
      00026F 22               [24]  903 	ret
                                    904 ;------------------------------------------------------------
                                    905 ;Allocation info for local variables in function 'fuzzy_8051_or2'
                                    906 ;------------------------------------------------------------
                                    907 ;a             Allocated to stack - _bp -6 +4 
                                    908 ;b             Allocated to stack - _bp -10 +4 
                                    909 ;method        Allocated to registers r7 
                                    910 ;value         Allocated to registers r4 r5 r6 r7 
                                    911 ;sloc0         Allocated to stack - _bp +1 +4 
                                    912 ;------------------------------------------------------------
                           0001B9   913 	Fcontroller_8051$fuzzy_8051_or2$0$0 ==.
                           0001B9   914 	C$fuzzy.h$135$1_0$41 ==.
                                    915 ;	../../fuzzy.h:135: static float fuzzy_8051_or2(fuzzy_logic_method_t method, float a, float b)
                                    916 ;	-----------------------------------------
                                    917 ;	 function fuzzy_8051_or2
                                    918 ;	-----------------------------------------
      000270                        919 _fuzzy_8051_or2:
      000270 C0 1D            [24]  920 	push	_bp
      000272 E5 81            [12]  921 	mov	a,sp
      000274 F5 1D            [12]  922 	mov	_bp,a
      000276 24 04            [12]  923 	add	a,#0x04
      000278 F5 81            [12]  924 	mov	sp,a
      00027A AF 82            [24]  925 	mov	r7, dpl
                           0001C5   926 	C$fuzzy.h$137$1_0$41 ==.
                                    927 ;	../../fuzzy.h:137: if (method == FUZZY_LOGIC_ALGEBRAIC) {
      00027C BF 01 02         [24]  928 	cjne	r7,#0x01,00135$
      00027F 80 03            [24]  929 	sjmp	00136$
      000281                        930 00135$:
      000281 02 03 1F         [24]  931 	ljmp	00102$
      000284                        932 00136$:
                           0001CD   933 	C$fuzzy.h$138$1_0$41 ==.
                                    934 ;	../../fuzzy.h:138: return a + b - a * b;
      000284 E5 1D            [12]  935 	mov	a,_bp
      000286 24 F6            [12]  936 	add	a,#0xf6
      000288 F8               [12]  937 	mov	r0,a
      000289 E6               [12]  938 	mov	a,@r0
      00028A C0 E0            [24]  939 	push	acc
      00028C 08               [12]  940 	inc	r0
      00028D E6               [12]  941 	mov	a,@r0
      00028E C0 E0            [24]  942 	push	acc
      000290 08               [12]  943 	inc	r0
      000291 E6               [12]  944 	mov	a,@r0
      000292 C0 E0            [24]  945 	push	acc
      000294 08               [12]  946 	inc	r0
      000295 E6               [12]  947 	mov	a,@r0
      000296 C0 E0            [24]  948 	push	acc
      000298 E5 1D            [12]  949 	mov	a,_bp
      00029A 24 FA            [12]  950 	add	a,#0xfa
      00029C F8               [12]  951 	mov	r0,a
      00029D 86 82            [24]  952 	mov	dpl, @r0
      00029F 08               [12]  953 	inc	r0
      0002A0 86 83            [24]  954 	mov	dph, @r0
      0002A2 08               [12]  955 	inc	r0
      0002A3 86 F0            [24]  956 	mov	b, @r0
      0002A5 08               [12]  957 	inc	r0
      0002A6 E6               [12]  958 	mov	a, @r0
      0002A7 12 1E 3D         [24]  959 	lcall	___fsadd
      0002AA A8 1D            [24]  960 	mov	r0,_bp
      0002AC 08               [12]  961 	inc	r0
      0002AD A6 82            [24]  962 	mov	@r0, dpl
      0002AF 08               [12]  963 	inc	r0
      0002B0 A6 83            [24]  964 	mov	@r0, dph
      0002B2 08               [12]  965 	inc	r0
      0002B3 A6 F0            [24]  966 	mov	@r0, b
      0002B5 08               [12]  967 	inc	r0
      0002B6 F6               [12]  968 	mov	@r0,a
      0002B7 E5 81            [12]  969 	mov	a,sp
      0002B9 24 FC            [12]  970 	add	a,#0xfc
      0002BB F5 81            [12]  971 	mov	sp,a
      0002BD E5 1D            [12]  972 	mov	a,_bp
      0002BF 24 F6            [12]  973 	add	a,#0xf6
      0002C1 F8               [12]  974 	mov	r0,a
      0002C2 E6               [12]  975 	mov	a,@r0
      0002C3 C0 E0            [24]  976 	push	acc
      0002C5 08               [12]  977 	inc	r0
      0002C6 E6               [12]  978 	mov	a,@r0
      0002C7 C0 E0            [24]  979 	push	acc
      0002C9 08               [12]  980 	inc	r0
      0002CA E6               [12]  981 	mov	a,@r0
      0002CB C0 E0            [24]  982 	push	acc
      0002CD 08               [12]  983 	inc	r0
      0002CE E6               [12]  984 	mov	a,@r0
      0002CF C0 E0            [24]  985 	push	acc
      0002D1 E5 1D            [12]  986 	mov	a,_bp
      0002D3 24 FA            [12]  987 	add	a,#0xfa
      0002D5 F8               [12]  988 	mov	r0,a
      0002D6 86 82            [24]  989 	mov	dpl, @r0
      0002D8 08               [12]  990 	inc	r0
      0002D9 86 83            [24]  991 	mov	dph, @r0
      0002DB 08               [12]  992 	inc	r0
      0002DC 86 F0            [24]  993 	mov	b, @r0
      0002DE 08               [12]  994 	inc	r0
      0002DF E6               [12]  995 	mov	a, @r0
      0002E0 12 1C DD         [24]  996 	lcall	___fsmul
      0002E3 AA 82            [24]  997 	mov	r2, dpl
      0002E5 AC 83            [24]  998 	mov	r4, dph
      0002E7 AD F0            [24]  999 	mov	r5, b
      0002E9 FE               [12] 1000 	mov	r6, a
      0002EA E5 81            [12] 1001 	mov	a,sp
      0002EC 24 FC            [12] 1002 	add	a,#0xfc
      0002EE F5 81            [12] 1003 	mov	sp,a
      0002F0 C0 02            [24] 1004 	push	ar2
      0002F2 C0 04            [24] 1005 	push	ar4
      0002F4 C0 05            [24] 1006 	push	ar5
      0002F6 C0 06            [24] 1007 	push	ar6
      0002F8 A8 1D            [24] 1008 	mov	r0,_bp
      0002FA 08               [12] 1009 	inc	r0
      0002FB 86 82            [24] 1010 	mov	dpl, @r0
      0002FD 08               [12] 1011 	inc	r0
      0002FE 86 83            [24] 1012 	mov	dph, @r0
      000300 08               [12] 1013 	inc	r0
      000301 86 F0            [24] 1014 	mov	b, @r0
      000303 08               [12] 1015 	inc	r0
      000304 E6               [12] 1016 	mov	a, @r0
      000305 12 1C D2         [24] 1017 	lcall	___fssub
      000308 AB 82            [24] 1018 	mov	r3, dpl
      00030A AC 83            [24] 1019 	mov	r4, dph
      00030C AD F0            [24] 1020 	mov	r5, b
      00030E FE               [12] 1021 	mov	r6, a
      00030F E5 81            [12] 1022 	mov	a,sp
      000311 24 FC            [12] 1023 	add	a,#0xfc
      000313 F5 81            [12] 1024 	mov	sp,a
      000315 8B 82            [24] 1025 	mov	dpl, r3
      000317 8C 83            [24] 1026 	mov	dph, r4
      000319 8D F0            [24] 1027 	mov	b, r5
      00031B EE               [12] 1028 	mov	a, r6
      00031C 02 03 F4         [24] 1029 	ljmp	00105$
      00031F                       1030 00102$:
                           000268  1031 	C$fuzzy.h$141$1_0$41 ==.
                                   1032 ;	../../fuzzy.h:141: if (method == FUZZY_LOGIC_BOUNDED) {
      00031F BF 02 78         [24] 1033 	cjne	r7,#0x02,00104$
                           00026B  1034 	C$fuzzy.h$142$1_0$41 ==.
                                   1035 ;	../../fuzzy.h:142: float value = a + b;
      000322 E5 1D            [12] 1036 	mov	a,_bp
      000324 24 F6            [12] 1037 	add	a,#0xf6
      000326 F8               [12] 1038 	mov	r0,a
      000327 E6               [12] 1039 	mov	a,@r0
      000328 C0 E0            [24] 1040 	push	acc
      00032A 08               [12] 1041 	inc	r0
      00032B E6               [12] 1042 	mov	a,@r0
      00032C C0 E0            [24] 1043 	push	acc
      00032E 08               [12] 1044 	inc	r0
      00032F E6               [12] 1045 	mov	a,@r0
      000330 C0 E0            [24] 1046 	push	acc
      000332 08               [12] 1047 	inc	r0
      000333 E6               [12] 1048 	mov	a,@r0
      000334 C0 E0            [24] 1049 	push	acc
                           00027F  1050 	C$fuzzy.h$143$1_0$41 ==.
                                   1051 ;	../../fuzzy.h:143: return value < 1.0f ? value : 1.0f;
      000336 E5 1D            [12] 1052 	mov	a,_bp
      000338 24 FA            [12] 1053 	add	a,#0xfa
      00033A F8               [12] 1054 	mov	r0,a
      00033B 86 82            [24] 1055 	mov	dpl, @r0
      00033D 08               [12] 1056 	inc	r0
      00033E 86 83            [24] 1057 	mov	dph, @r0
      000340 08               [12] 1058 	inc	r0
      000341 86 F0            [24] 1059 	mov	b, @r0
      000343 08               [12] 1060 	inc	r0
      000344 E6               [12] 1061 	mov	a, @r0
      000345 12 1E 3D         [24] 1062 	lcall	___fsadd
      000348 AC 82            [24] 1063 	mov	r4, dpl
      00034A AD 83            [24] 1064 	mov	r5, dph
      00034C AE F0            [24] 1065 	mov	r6, b
      00034E FF               [12] 1066 	mov	r7, a
      00034F E5 81            [12] 1067 	mov	a,sp
      000351 24 FC            [12] 1068 	add	a,#0xfc
      000353 F5 81            [12] 1069 	mov	sp,a
      000355 C0 07            [24] 1070 	push	ar7
      000357 C0 06            [24] 1071 	push	ar6
      000359 C0 05            [24] 1072 	push	ar5
      00035B C0 04            [24] 1073 	push	ar4
      00035D E4               [12] 1074 	clr	a
      00035E C0 E0            [24] 1075 	push	acc
      000360 C0 E0            [24] 1076 	push	acc
      000362 74 80            [12] 1077 	mov	a,#0x80
      000364 C0 E0            [24] 1078 	push	acc
      000366 74 3F            [12] 1079 	mov	a,#0x3f
      000368 C0 E0            [24] 1080 	push	acc
      00036A 8C 82            [24] 1081 	mov	dpl, r4
      00036C 8D 83            [24] 1082 	mov	dph, r5
      00036E 8E F0            [24] 1083 	mov	b, r6
      000370 EF               [12] 1084 	mov	a, r7
      000371 12 1E 0D         [24] 1085 	lcall	___fslt
      000374 AB 82            [24] 1086 	mov	r3, dpl
      000376 E5 81            [12] 1087 	mov	a,sp
      000378 24 FC            [12] 1088 	add	a,#0xfc
      00037A F5 81            [12] 1089 	mov	sp,a
      00037C D0 04            [24] 1090 	pop	ar4
      00037E D0 05            [24] 1091 	pop	ar5
      000380 D0 06            [24] 1092 	pop	ar6
      000382 D0 07            [24] 1093 	pop	ar7
      000384 EB               [12] 1094 	mov	a,r3
      000385 60 02            [24] 1095 	jz	00107$
      000387 80 08            [24] 1096 	sjmp	00108$
      000389                       1097 00107$:
      000389 7C 00            [12] 1098 	mov	r4,#0x00
      00038B 7D 00            [12] 1099 	mov	r5,#0x00
      00038D 7E 80            [12] 1100 	mov	r6,#0x80
      00038F 7F 3F            [12] 1101 	mov	r7,#0x3f
      000391                       1102 00108$:
      000391 8C 82            [24] 1103 	mov	dpl, r4
      000393 8D 83            [24] 1104 	mov	dph, r5
      000395 8E F0            [24] 1105 	mov	b, r6
      000397 EF               [12] 1106 	mov	a, r7
      000398 80 5A            [24] 1107 	sjmp	00105$
      00039A                       1108 00104$:
                           0002E3  1109 	C$fuzzy.h$146$1_0$41 ==.
                                   1110 ;	../../fuzzy.h:146: return a > b ? a : b;
      00039A E5 1D            [12] 1111 	mov	a,_bp
      00039C 24 FA            [12] 1112 	add	a,#0xfa
      00039E F8               [12] 1113 	mov	r0,a
      00039F E6               [12] 1114 	mov	a,@r0
      0003A0 C0 E0            [24] 1115 	push	acc
      0003A2 08               [12] 1116 	inc	r0
      0003A3 E6               [12] 1117 	mov	a,@r0
      0003A4 C0 E0            [24] 1118 	push	acc
      0003A6 08               [12] 1119 	inc	r0
      0003A7 E6               [12] 1120 	mov	a,@r0
      0003A8 C0 E0            [24] 1121 	push	acc
      0003AA 08               [12] 1122 	inc	r0
      0003AB E6               [12] 1123 	mov	a,@r0
      0003AC C0 E0            [24] 1124 	push	acc
      0003AE E5 1D            [12] 1125 	mov	a,_bp
      0003B0 24 F6            [12] 1126 	add	a,#0xf6
      0003B2 F8               [12] 1127 	mov	r0,a
      0003B3 86 82            [24] 1128 	mov	dpl, @r0
      0003B5 08               [12] 1129 	inc	r0
      0003B6 86 83            [24] 1130 	mov	dph, @r0
      0003B8 08               [12] 1131 	inc	r0
      0003B9 86 F0            [24] 1132 	mov	b, @r0
      0003BB 08               [12] 1133 	inc	r0
      0003BC E6               [12] 1134 	mov	a, @r0
      0003BD 12 1E 0D         [24] 1135 	lcall	___fslt
      0003C0 AF 82            [24] 1136 	mov	r7, dpl
      0003C2 E5 81            [12] 1137 	mov	a,sp
      0003C4 24 FC            [12] 1138 	add	a,#0xfc
      0003C6 F5 81            [12] 1139 	mov	sp,a
      0003C8 EF               [12] 1140 	mov	a,r7
      0003C9 60 12            [24] 1141 	jz	00109$
      0003CB E5 1D            [12] 1142 	mov	a,_bp
      0003CD 24 FA            [12] 1143 	add	a,#0xfa
      0003CF F8               [12] 1144 	mov	r0,a
      0003D0 86 04            [24] 1145 	mov	ar4,@r0
      0003D2 08               [12] 1146 	inc	r0
      0003D3 86 05            [24] 1147 	mov	ar5,@r0
      0003D5 08               [12] 1148 	inc	r0
      0003D6 86 06            [24] 1149 	mov	ar6,@r0
      0003D8 08               [12] 1150 	inc	r0
      0003D9 86 07            [24] 1151 	mov	ar7,@r0
      0003DB 80 10            [24] 1152 	sjmp	00110$
      0003DD                       1153 00109$:
      0003DD E5 1D            [12] 1154 	mov	a,_bp
      0003DF 24 F6            [12] 1155 	add	a,#0xf6
      0003E1 F8               [12] 1156 	mov	r0,a
      0003E2 86 04            [24] 1157 	mov	ar4,@r0
      0003E4 08               [12] 1158 	inc	r0
      0003E5 86 05            [24] 1159 	mov	ar5,@r0
      0003E7 08               [12] 1160 	inc	r0
      0003E8 86 06            [24] 1161 	mov	ar6,@r0
      0003EA 08               [12] 1162 	inc	r0
      0003EB 86 07            [24] 1163 	mov	ar7,@r0
      0003ED                       1164 00110$:
      0003ED 8C 82            [24] 1165 	mov	dpl, r4
      0003EF 8D 83            [24] 1166 	mov	dph, r5
      0003F1 8E F0            [24] 1167 	mov	b, r6
      0003F3 EF               [12] 1168 	mov	a, r7
      0003F4                       1169 00105$:
                           00033D  1170 	C$fuzzy.h$147$1_0$41 ==.
                                   1171 ;	../../fuzzy.h:147: }
      0003F4 85 1D 81         [24] 1172 	mov	sp,_bp
      0003F7 D0 1D            [24] 1173 	pop	_bp
                           000342  1174 	C$fuzzy.h$147$1_0$41 ==.
                           000342  1175 	XFcontroller_8051$fuzzy_8051_or2$0$0 ==.
      0003F9 22               [24] 1176 	ret
                                   1177 ;------------------------------------------------------------
                                   1178 ;Allocation info for local variables in function 'fuzzy_8051_or3'
                                   1179 ;------------------------------------------------------------
                                   1180 ;a             Allocated to stack - _bp -6 +4 
                                   1181 ;b             Allocated to stack - _bp -10 +4 
                                   1182 ;c             Allocated to stack - _bp -14 +4 
                                   1183 ;method        Allocated to registers r7 
                                   1184 ;------------------------------------------------------------
                           000343  1185 	Fcontroller_8051$fuzzy_8051_or3$0$0 ==.
                           000343  1186 	C$fuzzy.h$149$1_0$45 ==.
                                   1187 ;	../../fuzzy.h:149: static float fuzzy_8051_or3(fuzzy_logic_method_t method, float a, float b, float c)
                                   1188 ;	-----------------------------------------
                                   1189 ;	 function fuzzy_8051_or3
                                   1190 ;	-----------------------------------------
      0003FA                       1191 _fuzzy_8051_or3:
      0003FA C0 1D            [24] 1192 	push	_bp
      0003FC 85 81 1D         [24] 1193 	mov	_bp,sp
      0003FF AF 82            [24] 1194 	mov	r7, dpl
                           00034A  1195 	C$fuzzy.h$151$1_0$45 ==.
                                   1196 ;	../../fuzzy.h:151: return fuzzy_8051_or2(method, fuzzy_8051_or2(method, a, b), c);
      000401 C0 07            [24] 1197 	push	ar7
      000403 E5 1D            [12] 1198 	mov	a,_bp
      000405 24 F6            [12] 1199 	add	a,#0xf6
      000407 F8               [12] 1200 	mov	r0,a
      000408 E6               [12] 1201 	mov	a,@r0
      000409 C0 E0            [24] 1202 	push	acc
      00040B 08               [12] 1203 	inc	r0
      00040C E6               [12] 1204 	mov	a,@r0
      00040D C0 E0            [24] 1205 	push	acc
      00040F 08               [12] 1206 	inc	r0
      000410 E6               [12] 1207 	mov	a,@r0
      000411 C0 E0            [24] 1208 	push	acc
      000413 08               [12] 1209 	inc	r0
      000414 E6               [12] 1210 	mov	a,@r0
      000415 C0 E0            [24] 1211 	push	acc
      000417 E5 1D            [12] 1212 	mov	a,_bp
      000419 24 FA            [12] 1213 	add	a,#0xfa
      00041B F8               [12] 1214 	mov	r0,a
      00041C E6               [12] 1215 	mov	a,@r0
      00041D C0 E0            [24] 1216 	push	acc
      00041F 08               [12] 1217 	inc	r0
      000420 E6               [12] 1218 	mov	a,@r0
      000421 C0 E0            [24] 1219 	push	acc
      000423 08               [12] 1220 	inc	r0
      000424 E6               [12] 1221 	mov	a,@r0
      000425 C0 E0            [24] 1222 	push	acc
      000427 08               [12] 1223 	inc	r0
      000428 E6               [12] 1224 	mov	a,@r0
      000429 C0 E0            [24] 1225 	push	acc
      00042B 8F 82            [24] 1226 	mov	dpl, r7
      00042D 12 02 70         [24] 1227 	lcall	_fuzzy_8051_or2
      000430 AB 82            [24] 1228 	mov	r3, dpl
      000432 AC 83            [24] 1229 	mov	r4, dph
      000434 AD F0            [24] 1230 	mov	r5, b
      000436 FE               [12] 1231 	mov	r6, a
      000437 E5 81            [12] 1232 	mov	a,sp
      000439 24 F8            [12] 1233 	add	a,#0xf8
      00043B F5 81            [12] 1234 	mov	sp,a
      00043D D0 07            [24] 1235 	pop	ar7
      00043F E5 1D            [12] 1236 	mov	a,_bp
      000441 24 F2            [12] 1237 	add	a,#0xf2
      000443 F8               [12] 1238 	mov	r0,a
      000444 E6               [12] 1239 	mov	a,@r0
      000445 C0 E0            [24] 1240 	push	acc
      000447 08               [12] 1241 	inc	r0
      000448 E6               [12] 1242 	mov	a,@r0
      000449 C0 E0            [24] 1243 	push	acc
      00044B 08               [12] 1244 	inc	r0
      00044C E6               [12] 1245 	mov	a,@r0
      00044D C0 E0            [24] 1246 	push	acc
      00044F 08               [12] 1247 	inc	r0
      000450 E6               [12] 1248 	mov	a,@r0
      000451 C0 E0            [24] 1249 	push	acc
      000453 C0 03            [24] 1250 	push	ar3
      000455 C0 04            [24] 1251 	push	ar4
      000457 C0 05            [24] 1252 	push	ar5
      000459 C0 06            [24] 1253 	push	ar6
      00045B 8F 82            [24] 1254 	mov	dpl, r7
      00045D 12 02 70         [24] 1255 	lcall	_fuzzy_8051_or2
      000460 AC 82            [24] 1256 	mov	r4, dpl
      000462 AD 83            [24] 1257 	mov	r5, dph
      000464 AE F0            [24] 1258 	mov	r6, b
      000466 FF               [12] 1259 	mov	r7, a
      000467 E5 81            [12] 1260 	mov	a,sp
      000469 24 F8            [12] 1261 	add	a,#0xf8
      00046B F5 81            [12] 1262 	mov	sp,a
      00046D 8C 82            [24] 1263 	mov	dpl, r4
      00046F 8D 83            [24] 1264 	mov	dph, r5
      000471 8E F0            [24] 1265 	mov	b, r6
      000473 EF               [12] 1266 	mov	a, r7
                           0003BD  1267 	C$fuzzy.h$152$1_0$45 ==.
                                   1268 ;	../../fuzzy.h:152: }
      000474 D0 1D            [24] 1269 	pop	_bp
                           0003BF  1270 	C$fuzzy.h$152$1_0$45 ==.
                           0003BF  1271 	XFcontroller_8051$fuzzy_8051_or3$0$0 ==.
      000476 22               [24] 1272 	ret
                                   1273 ;------------------------------------------------------------
                                   1274 ;Allocation info for local variables in function 'fuzzy_8051_clamp'
                                   1275 ;------------------------------------------------------------
                                   1276 ;value         Allocated to registers r4 r5 r6 r7 
                                   1277 ;------------------------------------------------------------
                           0003C0  1278 	Fcontroller_8051$fuzzy_8051_clamp$0$0 ==.
                           0003C0  1279 	C$fuzzy.h$162$1_0$47 ==.
                                   1280 ;	../../fuzzy.h:162: static float fuzzy_8051_clamp(float value)
                                   1281 ;	-----------------------------------------
                                   1282 ;	 function fuzzy_8051_clamp
                                   1283 ;	-----------------------------------------
      000477                       1284 _fuzzy_8051_clamp:
      000477 AC 82            [24] 1285 	mov	r4,dpl
      000479 AD 83            [24] 1286 	mov	r5,dph
      00047B AE F0            [24] 1287 	mov	r6,b
      00047D FF               [12] 1288 	mov	r7,a
                           0003C7  1289 	C$fuzzy.h$164$1_0$47 ==.
                                   1290 ;	../../fuzzy.h:164: if (value < 0.0f) {
      00047E C0 07            [24] 1291 	push	ar7
      000480 C0 06            [24] 1292 	push	ar6
      000482 C0 05            [24] 1293 	push	ar5
      000484 C0 04            [24] 1294 	push	ar4
      000486 E4               [12] 1295 	clr	a
      000487 C0 E0            [24] 1296 	push	acc
      000489 C0 E0            [24] 1297 	push	acc
      00048B C0 E0            [24] 1298 	push	acc
      00048D C0 E0            [24] 1299 	push	acc
      00048F 8C 82            [24] 1300 	mov	dpl, r4
      000491 8D 83            [24] 1301 	mov	dph, r5
      000493 8E F0            [24] 1302 	mov	b, r6
      000495 EF               [12] 1303 	mov	a, r7
      000496 12 1E 0D         [24] 1304 	lcall	___fslt
      000499 AB 82            [24] 1305 	mov	r3, dpl
      00049B E5 81            [12] 1306 	mov	a,sp
      00049D 24 FC            [12] 1307 	add	a,#0xfc
      00049F F5 81            [12] 1308 	mov	sp,a
      0004A1 D0 04            [24] 1309 	pop	ar4
      0004A3 D0 05            [24] 1310 	pop	ar5
      0004A5 D0 06            [24] 1311 	pop	ar6
      0004A7 D0 07            [24] 1312 	pop	ar7
      0004A9 EB               [12] 1313 	mov	a,r3
      0004AA 60 08            [24] 1314 	jz	00102$
                           0003F5  1315 	C$fuzzy.h$165$2_0$48 ==.
                                   1316 ;	../../fuzzy.h:165: return 0.0f;
      0004AC 90 00 00         [24] 1317 	mov	dptr,#0x0000
      0004AF E4               [12] 1318 	clr	a
      0004B0 F5 F0            [12] 1319 	mov	b,a
      0004B2 80 3F            [24] 1320 	sjmp	00105$
      0004B4                       1321 00102$:
                           0003FD  1322 	C$fuzzy.h$168$1_0$47 ==.
                                   1323 ;	../../fuzzy.h:168: if (value > 1.0f) {
      0004B4 C0 07            [24] 1324 	push	ar7
      0004B6 C0 06            [24] 1325 	push	ar6
      0004B8 C0 05            [24] 1326 	push	ar5
      0004BA C0 04            [24] 1327 	push	ar4
      0004BC C0 04            [24] 1328 	push	ar4
      0004BE C0 05            [24] 1329 	push	ar5
      0004C0 C0 06            [24] 1330 	push	ar6
      0004C2 C0 07            [24] 1331 	push	ar7
      0004C4 90 00 00         [24] 1332 	mov	dptr,#0x0000
      0004C7 75 F0 80         [24] 1333 	mov	b, #0x80
      0004CA 74 3F            [12] 1334 	mov	a, #0x3f
      0004CC 12 1E 0D         [24] 1335 	lcall	___fslt
      0004CF AB 82            [24] 1336 	mov	r3, dpl
      0004D1 E5 81            [12] 1337 	mov	a,sp
      0004D3 24 FC            [12] 1338 	add	a,#0xfc
      0004D5 F5 81            [12] 1339 	mov	sp,a
      0004D7 D0 04            [24] 1340 	pop	ar4
      0004D9 D0 05            [24] 1341 	pop	ar5
      0004DB D0 06            [24] 1342 	pop	ar6
      0004DD D0 07            [24] 1343 	pop	ar7
      0004DF EB               [12] 1344 	mov	a,r3
      0004E0 60 0A            [24] 1345 	jz	00104$
                           00042B  1346 	C$fuzzy.h$169$2_0$49 ==.
                                   1347 ;	../../fuzzy.h:169: return 1.0f;
      0004E2 90 00 00         [24] 1348 	mov	dptr,#0x0000
      0004E5 75 F0 80         [24] 1349 	mov	b, #0x80
      0004E8 74 3F            [12] 1350 	mov	a, #0x3f
      0004EA 80 07            [24] 1351 	sjmp	00105$
      0004EC                       1352 00104$:
                           000435  1353 	C$fuzzy.h$172$1_0$47 ==.
                                   1354 ;	../../fuzzy.h:172: return value;
      0004EC 8C 82            [24] 1355 	mov	dpl, r4
      0004EE 8D 83            [24] 1356 	mov	dph, r5
      0004F0 8E F0            [24] 1357 	mov	b, r6
      0004F2 EF               [12] 1358 	mov	a, r7
      0004F3                       1359 00105$:
                           00043C  1360 	C$fuzzy.h$173$1_0$47 ==.
                                   1361 ;	../../fuzzy.h:173: }
                           00043C  1362 	C$fuzzy.h$173$1_0$47 ==.
                           00043C  1363 	XFcontroller_8051$fuzzy_8051_clamp$0$0 ==.
      0004F3 22               [24] 1364 	ret
                                   1365 ;------------------------------------------------------------
                                   1366 ;Allocation info for local variables in function 'fuzzy_8051_hedge'
                                   1367 ;------------------------------------------------------------
                                   1368 ;hedge         Allocated to stack - _bp -3 +1 
                                   1369 ;value         Allocated to stack - _bp +1 +4 
                                   1370 ;result        Allocated to registers r2 r3 r6 r7 
                                   1371 ;------------------------------------------------------------
                           00043D  1372 	Fcontroller_8051$fuzzy_8051_hedge$0$0 ==.
                           00043D  1373 	C$fuzzy.h$175$1_0$51 ==.
                                   1374 ;	../../fuzzy.h:175: static float fuzzy_8051_hedge(float value, fuzzy_hedge_t hedge)
                                   1375 ;	-----------------------------------------
                                   1376 ;	 function fuzzy_8051_hedge
                                   1377 ;	-----------------------------------------
      0004F4                       1378 _fuzzy_8051_hedge:
      0004F4 C0 1D            [24] 1379 	push	_bp
      0004F6 85 81 1D         [24] 1380 	mov	_bp,sp
      0004F9 AC 82            [24] 1381 	mov	r4,dpl
      0004FB AD 83            [24] 1382 	mov	r5,dph
      0004FD AE F0            [24] 1383 	mov	r6,b
      0004FF FF               [12] 1384 	mov	r7,a
      000500 E5 81            [12] 1385 	mov	a,sp
      000502 24 04            [12] 1386 	add	a,#0x04
      000504 F5 81            [12] 1387 	mov	sp,a
                           00044F  1388 	C$fuzzy.h$179$1_0$51 ==.
                                   1389 ;	../../fuzzy.h:179: value = fuzzy_8051_clamp(value);
      000506 8C 82            [24] 1390 	mov	dpl, r4
      000508 8D 83            [24] 1391 	mov	dph, r5
      00050A 8E F0            [24] 1392 	mov	b, r6
      00050C EF               [12] 1393 	mov	a, r7
      00050D 12 04 77         [24] 1394 	lcall	_fuzzy_8051_clamp
      000510 A8 1D            [24] 1395 	mov	r0,_bp
      000512 08               [12] 1396 	inc	r0
      000513 A6 82            [24] 1397 	mov	@r0, dpl
      000515 08               [12] 1398 	inc	r0
      000516 A6 83            [24] 1399 	mov	@r0, dph
      000518 08               [12] 1400 	inc	r0
      000519 A6 F0            [24] 1401 	mov	@r0, b
      00051B 08               [12] 1402 	inc	r0
      00051C F6               [12] 1403 	mov	@r0,a
                           000466  1404 	C$fuzzy.h$181$1_0$51 ==.
                                   1405 ;	../../fuzzy.h:181: if (hedge == 0u) {
      00051D E5 1D            [12] 1406 	mov	a,_bp
      00051F 24 FD            [12] 1407 	add	a,#0xfd
      000521 F8               [12] 1408 	mov	r0,a
      000522 E6               [12] 1409 	mov	a,@r0
      000523 70 07            [24] 1410 	jnz	00102$
                           00046E  1411 	C$fuzzy.h$182$2_0$52 ==.
                                   1412 ;	../../fuzzy.h:182: hedge = 1u;
      000525 E5 1D            [12] 1413 	mov	a,_bp
      000527 24 FD            [12] 1414 	add	a,#0xfd
      000529 F8               [12] 1415 	mov	r0,a
      00052A 76 01            [12] 1416 	mov	@r0,#0x01
      00052C                       1417 00102$:
                           000475  1418 	C$fuzzy.h$185$1_0$51 ==.
                                   1419 ;	../../fuzzy.h:185: result = 1.0f;
      00052C 7A 00            [12] 1420 	mov	r2,#0x00
      00052E 7B 00            [12] 1421 	mov	r3,#0x00
      000530 7E 80            [12] 1422 	mov	r6,#0x80
      000532 7F 3F            [12] 1423 	mov	r7,#0x3f
                           00047D  1424 	C$fuzzy.h$187$1_0$51 ==.
                                   1425 ;	../../fuzzy.h:187: while (hedge != 0u) {
      000534 E5 1D            [12] 1426 	mov	a,_bp
      000536 24 FD            [12] 1427 	add	a,#0xfd
      000538 F8               [12] 1428 	mov	r0,a
      000539 86 05            [24] 1429 	mov	ar5,@r0
      00053B                       1430 00103$:
      00053B ED               [12] 1431 	mov	a,r5
      00053C 60 30            [24] 1432 	jz	00105$
                           000487  1433 	C$fuzzy.h$188$1_0$51 ==.
                                   1434 ;	../../fuzzy.h:188: result *= value;
      00053E C0 05            [24] 1435 	push	ar5
      000540 A8 1D            [24] 1436 	mov	r0,_bp
      000542 08               [12] 1437 	inc	r0
      000543 E6               [12] 1438 	mov	a,@r0
      000544 C0 E0            [24] 1439 	push	acc
      000546 08               [12] 1440 	inc	r0
      000547 E6               [12] 1441 	mov	a,@r0
      000548 C0 E0            [24] 1442 	push	acc
      00054A 08               [12] 1443 	inc	r0
      00054B E6               [12] 1444 	mov	a,@r0
      00054C C0 E0            [24] 1445 	push	acc
      00054E 08               [12] 1446 	inc	r0
      00054F E6               [12] 1447 	mov	a,@r0
      000550 C0 E0            [24] 1448 	push	acc
                           00049B  1449 	C$fuzzy.h$189$1_0$51 ==.
                                   1450 ;	../../fuzzy.h:189: --hedge;
      000552 8A 82            [24] 1451 	mov	dpl, r2
      000554 8B 83            [24] 1452 	mov	dph, r3
      000556 8E F0            [24] 1453 	mov	b, r6
      000558 EF               [12] 1454 	mov	a, r7
      000559 12 1C DD         [24] 1455 	lcall	___fsmul
      00055C AA 82            [24] 1456 	mov	r2, dpl
      00055E AB 83            [24] 1457 	mov	r3, dph
      000560 AE F0            [24] 1458 	mov	r6, b
      000562 FF               [12] 1459 	mov	r7, a
      000563 E5 81            [12] 1460 	mov	a,sp
      000565 24 FC            [12] 1461 	add	a,#0xfc
      000567 F5 81            [12] 1462 	mov	sp,a
      000569 D0 05            [24] 1463 	pop	ar5
      00056B 1D               [12] 1464 	dec	r5
      00056C 80 CD            [24] 1465 	sjmp	00103$
      00056E                       1466 00105$:
                           0004B7  1467 	C$fuzzy.h$192$1_0$51 ==.
                                   1468 ;	../../fuzzy.h:192: return fuzzy_8051_clamp(result);
      00056E 8A 82            [24] 1469 	mov	dpl, r2
      000570 8B 83            [24] 1470 	mov	dph, r3
      000572 8E F0            [24] 1471 	mov	b, r6
      000574 EF               [12] 1472 	mov	a, r7
      000575 12 04 77         [24] 1473 	lcall	_fuzzy_8051_clamp
                           0004C1  1474 	C$fuzzy.h$193$1_0$51 ==.
                                   1475 ;	../../fuzzy.h:193: }
      000578 85 1D 81         [24] 1476 	mov	sp,_bp
      00057B D0 1D            [24] 1477 	pop	_bp
                           0004C6  1478 	C$fuzzy.h$193$1_0$51 ==.
                           0004C6  1479 	XFcontroller_8051$fuzzy_8051_hedge$0$0 ==.
      00057D 22               [24] 1480 	ret
                                   1481 ;------------------------------------------------------------
                                   1482 ;Allocation info for local variables in function 'fuzzy_not'
                                   1483 ;------------------------------------------------------------
                                   1484 ;membership    Allocated to registers r4 r5 r6 r7 
                                   1485 ;------------------------------------------------------------
                           0004C7  1486 	G$fuzzy_not$0$0 ==.
                           0004C7  1487 	C$fuzzy.h$195$1_0$55 ==.
                                   1488 ;	../../fuzzy.h:195: float fuzzy_not(float membership)
                                   1489 ;	-----------------------------------------
                                   1490 ;	 function fuzzy_not
                                   1491 ;	-----------------------------------------
      00057E                       1492 _fuzzy_not:
                           0004C7  1493 	C$fuzzy.h$197$1_0$55 ==.
                                   1494 ;	../../fuzzy.h:197: return 1.0f - fuzzy_8051_clamp(membership);
      00057E 12 04 77         [24] 1495 	lcall	_fuzzy_8051_clamp
      000581 AC 82            [24] 1496 	mov	r4, dpl
      000583 AD 83            [24] 1497 	mov	r5, dph
      000585 AE F0            [24] 1498 	mov	r6, b
      000587 FF               [12] 1499 	mov	r7, a
      000588 C0 04            [24] 1500 	push	ar4
      00058A C0 05            [24] 1501 	push	ar5
      00058C C0 06            [24] 1502 	push	ar6
      00058E C0 07            [24] 1503 	push	ar7
      000590 90 00 00         [24] 1504 	mov	dptr,#0x0000
      000593 75 F0 80         [24] 1505 	mov	b, #0x80
      000596 74 3F            [12] 1506 	mov	a, #0x3f
      000598 12 1C D2         [24] 1507 	lcall	___fssub
      00059B AC 82            [24] 1508 	mov	r4, dpl
      00059D AD 83            [24] 1509 	mov	r5, dph
      00059F AE F0            [24] 1510 	mov	r6, b
      0005A1 FF               [12] 1511 	mov	r7, a
      0005A2 E5 81            [12] 1512 	mov	a,sp
      0005A4 24 FC            [12] 1513 	add	a,#0xfc
      0005A6 F5 81            [12] 1514 	mov	sp,a
      0005A8 8C 82            [24] 1515 	mov	dpl, r4
      0005AA 8D 83            [24] 1516 	mov	dph, r5
      0005AC 8E F0            [24] 1517 	mov	b, r6
      0005AE EF               [12] 1518 	mov	a, r7
                           0004F8  1519 	C$fuzzy.h$198$1_0$55 ==.
                                   1520 ;	../../fuzzy.h:198: }
                           0004F8  1521 	C$fuzzy.h$198$1_0$55 ==.
                           0004F8  1522 	XG$fuzzy_not$0$0 ==.
      0005AF 22               [24] 1523 	ret
                                   1524 ;------------------------------------------------------------
                                   1525 ;Allocation info for local variables in function 'fuzzy_ramp'
                                   1526 ;------------------------------------------------------------
                                   1527 ;b             Allocated to stack - _bp -6 +4 
                                   1528 ;x             Allocated to stack - _bp -10 +4 
                                   1529 ;up            Allocated to stack - _bp -11 +1 
                                   1530 ;hedge         Allocated to stack - _bp -12 +1 
                                   1531 ;a             Allocated to registers r7 r6 r5 r4 
                                   1532 ;result        Allocated to stack - _bp +5 +4 
                                   1533 ;sloc0         Allocated to stack - _bp +1 +4 
                                   1534 ;------------------------------------------------------------
                           0004F9  1535 	G$fuzzy_ramp$0$0 ==.
                           0004F9  1536 	C$fuzzy.h$200$1_0$57 ==.
                                   1537 ;	../../fuzzy.h:200: float fuzzy_ramp(float a, float b, float x, bool up, fuzzy_hedge_t hedge)
                                   1538 ;	-----------------------------------------
                                   1539 ;	 function fuzzy_ramp
                                   1540 ;	-----------------------------------------
      0005B0                       1541 _fuzzy_ramp:
      0005B0 C0 1D            [24] 1542 	push	_bp
      0005B2 85 81 1D         [24] 1543 	mov	_bp,sp
      0005B5 AF 82            [24] 1544 	mov	r7,dpl
      0005B7 AE 83            [24] 1545 	mov	r6,dph
      0005B9 AD F0            [24] 1546 	mov	r5,b
      0005BB FC               [12] 1547 	mov	r4,a
      0005BC E5 81            [12] 1548 	mov	a,sp
      0005BE 24 08            [12] 1549 	add	a,#0x08
      0005C0 F5 81            [12] 1550 	mov	sp,a
                           00050B  1551 	C$fuzzy.h$204$1_0$57 ==.
                                   1552 ;	../../fuzzy.h:204: if (a >= b) {
      0005C2 C0 07            [24] 1553 	push	ar7
      0005C4 C0 06            [24] 1554 	push	ar6
      0005C6 C0 05            [24] 1555 	push	ar5
      0005C8 C0 04            [24] 1556 	push	ar4
      0005CA E5 1D            [12] 1557 	mov	a,_bp
      0005CC 24 FA            [12] 1558 	add	a,#0xfa
      0005CE F8               [12] 1559 	mov	r0,a
      0005CF E6               [12] 1560 	mov	a,@r0
      0005D0 C0 E0            [24] 1561 	push	acc
      0005D2 08               [12] 1562 	inc	r0
      0005D3 E6               [12] 1563 	mov	a,@r0
      0005D4 C0 E0            [24] 1564 	push	acc
      0005D6 08               [12] 1565 	inc	r0
      0005D7 E6               [12] 1566 	mov	a,@r0
      0005D8 C0 E0            [24] 1567 	push	acc
      0005DA 08               [12] 1568 	inc	r0
      0005DB E6               [12] 1569 	mov	a,@r0
      0005DC C0 E0            [24] 1570 	push	acc
      0005DE 8F 82            [24] 1571 	mov	dpl, r7
      0005E0 8E 83            [24] 1572 	mov	dph, r6
      0005E2 8D F0            [24] 1573 	mov	b, r5
      0005E4 EC               [12] 1574 	mov	a, r4
      0005E5 12 1E 0D         [24] 1575 	lcall	___fslt
      0005E8 E5 81            [12] 1576 	mov	a,sp
      0005EA 24 FC            [12] 1577 	add	a,#0xfc
      0005EC F5 81            [12] 1578 	mov	sp,a
      0005EE D0 04            [24] 1579 	pop	ar4
      0005F0 D0 05            [24] 1580 	pop	ar5
      0005F2 D0 06            [24] 1581 	pop	ar6
      0005F4 D0 07            [24] 1582 	pop	ar7
      0005F6 E5 82            [12] 1583 	mov	a, dpl
      0005F8 24 FF            [12] 1584 	add	a,#0xff
      0005FA 92 00            [24] 1585 	mov	b0,c
      0005FC 40 09            [24] 1586 	jc	00102$
                           000547  1587 	C$fuzzy.h$205$2_0$58 ==.
                                   1588 ;	../../fuzzy.h:205: return 0.0f;
      0005FE 90 00 00         [24] 1589 	mov	dptr,#0x0000
      000601 E4               [12] 1590 	clr	a
      000602 F5 F0            [12] 1591 	mov	b,a
      000604 02 07 B6         [24] 1592 	ljmp	00111$
      000607                       1593 00102$:
                           000550  1594 	C$fuzzy.h$208$1_0$57 ==.
                                   1595 ;	../../fuzzy.h:208: if (x <= a) {
      000607 C0 07            [24] 1596 	push	ar7
      000609 C0 06            [24] 1597 	push	ar6
      00060B C0 05            [24] 1598 	push	ar5
      00060D C0 04            [24] 1599 	push	ar4
      00060F E5 1D            [12] 1600 	mov	a,_bp
      000611 24 F6            [12] 1601 	add	a,#0xf6
      000613 F8               [12] 1602 	mov	r0,a
      000614 E6               [12] 1603 	mov	a,@r0
      000615 C0 E0            [24] 1604 	push	acc
      000617 08               [12] 1605 	inc	r0
      000618 E6               [12] 1606 	mov	a,@r0
      000619 C0 E0            [24] 1607 	push	acc
      00061B 08               [12] 1608 	inc	r0
      00061C E6               [12] 1609 	mov	a,@r0
      00061D C0 E0            [24] 1610 	push	acc
      00061F 08               [12] 1611 	inc	r0
      000620 E6               [12] 1612 	mov	a,@r0
      000621 C0 E0            [24] 1613 	push	acc
      000623 8F 82            [24] 1614 	mov	dpl, r7
      000625 8E 83            [24] 1615 	mov	dph, r6
      000627 8D F0            [24] 1616 	mov	b, r5
      000629 EC               [12] 1617 	mov	a, r4
      00062A 12 1E 0D         [24] 1618 	lcall	___fslt
      00062D E5 81            [12] 1619 	mov	a,sp
      00062F 24 FC            [12] 1620 	add	a,#0xfc
      000631 F5 81            [12] 1621 	mov	sp,a
      000633 D0 04            [24] 1622 	pop	ar4
      000635 D0 05            [24] 1623 	pop	ar5
      000637 D0 06            [24] 1624 	pop	ar6
      000639 D0 07            [24] 1625 	pop	ar7
      00063B E5 82            [12] 1626 	mov	a, dpl
      00063D 24 FF            [12] 1627 	add	a,#0xff
      00063F 92 00            [24] 1628 	mov	b0,c
      000641 40 39            [24] 1629 	jc	00109$
                           00058C  1630 	C$fuzzy.h$209$2_0$59 ==.
                                   1631 ;	../../fuzzy.h:209: result = up ? 0.0f : 1.0f;
      000643 E5 1D            [12] 1632 	mov	a,_bp
      000645 24 F5            [12] 1633 	add	a,#0xf5
      000647 F8               [12] 1634 	mov	r0,a
      000648 E6               [12] 1635 	mov	a,@r0
      000649 60 0F            [24] 1636 	jz	00113$
      00064B E5 1D            [12] 1637 	mov	a,_bp
      00064D 24 05            [12] 1638 	add	a,#0x05
      00064F F8               [12] 1639 	mov	r0,a
      000650 E4               [12] 1640 	clr	a
      000651 F6               [12] 1641 	mov	@r0,a
      000652 08               [12] 1642 	inc	r0
      000653 F6               [12] 1643 	mov	@r0,a
      000654 08               [12] 1644 	inc	r0
      000655 F6               [12] 1645 	mov	@r0,a
      000656 08               [12] 1646 	inc	r0
      000657 F6               [12] 1647 	mov	@r0,a
      000658 80 0F            [24] 1648 	sjmp	00114$
      00065A                       1649 00113$:
      00065A E5 1D            [12] 1650 	mov	a,_bp
      00065C 24 05            [12] 1651 	add	a,#0x05
      00065E F8               [12] 1652 	mov	r0,a
      00065F E4               [12] 1653 	clr	a
      000660 F6               [12] 1654 	mov	@r0,a
      000661 08               [12] 1655 	inc	r0
      000662 F6               [12] 1656 	mov	@r0,a
      000663 08               [12] 1657 	inc	r0
      000664 76 80            [12] 1658 	mov	@r0,#0x80
      000666 08               [12] 1659 	inc	r0
      000667 76 3F            [12] 1660 	mov	@r0,#0x3f
      000669                       1661 00114$:
      000669 E5 1D            [12] 1662 	mov	a,_bp
      00066B 24 05            [12] 1663 	add	a,#0x05
      00066D F8               [12] 1664 	mov	r0,a
      00066E 86 07            [24] 1665 	mov	ar7,@r0
      000670 08               [12] 1666 	inc	r0
      000671 86 06            [24] 1667 	mov	ar6,@r0
      000673 08               [12] 1668 	inc	r0
      000674 86 05            [24] 1669 	mov	ar5,@r0
      000676 08               [12] 1670 	inc	r0
      000677 86 04            [24] 1671 	mov	ar4,@r0
      000679 02 07 94         [24] 1672 	ljmp	00110$
      00067C                       1673 00109$:
                           0005C5  1674 	C$fuzzy.h$211$1_0$57 ==.
                                   1675 ;	../../fuzzy.h:211: else if (x >= b) {
      00067C C0 07            [24] 1676 	push	ar7
      00067E C0 06            [24] 1677 	push	ar6
      000680 C0 05            [24] 1678 	push	ar5
      000682 C0 04            [24] 1679 	push	ar4
      000684 E5 1D            [12] 1680 	mov	a,_bp
      000686 24 FA            [12] 1681 	add	a,#0xfa
      000688 F8               [12] 1682 	mov	r0,a
      000689 E6               [12] 1683 	mov	a,@r0
      00068A C0 E0            [24] 1684 	push	acc
      00068C 08               [12] 1685 	inc	r0
      00068D E6               [12] 1686 	mov	a,@r0
      00068E C0 E0            [24] 1687 	push	acc
      000690 08               [12] 1688 	inc	r0
      000691 E6               [12] 1689 	mov	a,@r0
      000692 C0 E0            [24] 1690 	push	acc
      000694 08               [12] 1691 	inc	r0
      000695 E6               [12] 1692 	mov	a,@r0
      000696 C0 E0            [24] 1693 	push	acc
      000698 E5 1D            [12] 1694 	mov	a,_bp
      00069A 24 F6            [12] 1695 	add	a,#0xf6
      00069C F8               [12] 1696 	mov	r0,a
      00069D 86 82            [24] 1697 	mov	dpl, @r0
      00069F 08               [12] 1698 	inc	r0
      0006A0 86 83            [24] 1699 	mov	dph, @r0
      0006A2 08               [12] 1700 	inc	r0
      0006A3 86 F0            [24] 1701 	mov	b, @r0
      0006A5 08               [12] 1702 	inc	r0
      0006A6 E6               [12] 1703 	mov	a, @r0
      0006A7 12 1E 0D         [24] 1704 	lcall	___fslt
      0006AA E5 81            [12] 1705 	mov	a,sp
      0006AC 24 FC            [12] 1706 	add	a,#0xfc
      0006AE F5 81            [12] 1707 	mov	sp,a
      0006B0 D0 04            [24] 1708 	pop	ar4
      0006B2 D0 05            [24] 1709 	pop	ar5
      0006B4 D0 06            [24] 1710 	pop	ar6
      0006B6 D0 07            [24] 1711 	pop	ar7
      0006B8 E5 82            [12] 1712 	mov	a, dpl
      0006BA 24 FF            [12] 1713 	add	a,#0xff
      0006BC 92 00            [24] 1714 	mov	b0,c
      0006BE 40 33            [24] 1715 	jc	00106$
                           000609  1716 	C$fuzzy.h$212$2_0$60 ==.
                                   1717 ;	../../fuzzy.h:212: result = up ? 1.0f : 0.0f;
      0006C0 E5 1D            [12] 1718 	mov	a,_bp
      0006C2 24 F5            [12] 1719 	add	a,#0xf5
      0006C4 F8               [12] 1720 	mov	r0,a
      0006C5 E6               [12] 1721 	mov	a,@r0
      0006C6 60 0F            [24] 1722 	jz	00115$
      0006C8 A8 1D            [24] 1723 	mov	r0,_bp
      0006CA 08               [12] 1724 	inc	r0
      0006CB E4               [12] 1725 	clr	a
      0006CC F6               [12] 1726 	mov	@r0,a
      0006CD 08               [12] 1727 	inc	r0
      0006CE F6               [12] 1728 	mov	@r0,a
      0006CF 08               [12] 1729 	inc	r0
      0006D0 76 80            [12] 1730 	mov	@r0,#0x80
      0006D2 08               [12] 1731 	inc	r0
      0006D3 76 3F            [12] 1732 	mov	@r0,#0x3f
      0006D5 80 0B            [24] 1733 	sjmp	00116$
      0006D7                       1734 00115$:
      0006D7 A8 1D            [24] 1735 	mov	r0,_bp
      0006D9 08               [12] 1736 	inc	r0
      0006DA E4               [12] 1737 	clr	a
      0006DB F6               [12] 1738 	mov	@r0,a
      0006DC 08               [12] 1739 	inc	r0
      0006DD F6               [12] 1740 	mov	@r0,a
      0006DE 08               [12] 1741 	inc	r0
      0006DF F6               [12] 1742 	mov	@r0,a
      0006E0 08               [12] 1743 	inc	r0
      0006E1 F6               [12] 1744 	mov	@r0,a
      0006E2                       1745 00116$:
      0006E2 A8 1D            [24] 1746 	mov	r0,_bp
      0006E4 08               [12] 1747 	inc	r0
      0006E5 86 07            [24] 1748 	mov	ar7,@r0
      0006E7 08               [12] 1749 	inc	r0
      0006E8 86 06            [24] 1750 	mov	ar6,@r0
      0006EA 08               [12] 1751 	inc	r0
      0006EB 86 05            [24] 1752 	mov	ar5,@r0
      0006ED 08               [12] 1753 	inc	r0
      0006EE 86 04            [24] 1754 	mov	ar4,@r0
      0006F0 02 07 94         [24] 1755 	ljmp	00110$
      0006F3                       1756 00106$:
                           00063C  1757 	C$fuzzy.h$215$1_0$57 ==.
                                   1758 ;	../../fuzzy.h:215: result = (x - a) / (b - a);
      0006F3 C0 07            [24] 1759 	push	ar7
      0006F5 C0 06            [24] 1760 	push	ar6
      0006F7 C0 05            [24] 1761 	push	ar5
      0006F9 C0 04            [24] 1762 	push	ar4
      0006FB C0 07            [24] 1763 	push	ar7
      0006FD C0 06            [24] 1764 	push	ar6
      0006FF C0 05            [24] 1765 	push	ar5
      000701 C0 04            [24] 1766 	push	ar4
      000703 E5 1D            [12] 1767 	mov	a,_bp
      000705 24 F6            [12] 1768 	add	a,#0xf6
      000707 F8               [12] 1769 	mov	r0,a
      000708 86 82            [24] 1770 	mov	dpl, @r0
      00070A 08               [12] 1771 	inc	r0
      00070B 86 83            [24] 1772 	mov	dph, @r0
      00070D 08               [12] 1773 	inc	r0
      00070E 86 F0            [24] 1774 	mov	b, @r0
      000710 08               [12] 1775 	inc	r0
      000711 E6               [12] 1776 	mov	a, @r0
      000712 12 1C D2         [24] 1777 	lcall	___fssub
      000715 A8 1D            [24] 1778 	mov	r0,_bp
      000717 08               [12] 1779 	inc	r0
      000718 A6 82            [24] 1780 	mov	@r0, dpl
      00071A 08               [12] 1781 	inc	r0
      00071B A6 83            [24] 1782 	mov	@r0, dph
      00071D 08               [12] 1783 	inc	r0
      00071E A6 F0            [24] 1784 	mov	@r0, b
      000720 08               [12] 1785 	inc	r0
      000721 F6               [12] 1786 	mov	@r0,a
      000722 E5 81            [12] 1787 	mov	a,sp
      000724 24 FC            [12] 1788 	add	a,#0xfc
      000726 F5 81            [12] 1789 	mov	sp,a
      000728 E5 1D            [12] 1790 	mov	a,_bp
      00072A 24 FA            [12] 1791 	add	a,#0xfa
      00072C F8               [12] 1792 	mov	r0,a
      00072D 86 82            [24] 1793 	mov	dpl, @r0
      00072F 08               [12] 1794 	inc	r0
      000730 86 83            [24] 1795 	mov	dph, @r0
      000732 08               [12] 1796 	inc	r0
      000733 86 F0            [24] 1797 	mov	b, @r0
      000735 08               [12] 1798 	inc	r0
      000736 E6               [12] 1799 	mov	a, @r0
      000737 12 1C D2         [24] 1800 	lcall	___fssub
      00073A AC 82            [24] 1801 	mov	r4, dpl
      00073C AD 83            [24] 1802 	mov	r5, dph
      00073E AE F0            [24] 1803 	mov	r6, b
      000740 FF               [12] 1804 	mov	r7, a
      000741 E5 81            [12] 1805 	mov	a,sp
      000743 24 FC            [12] 1806 	add	a,#0xfc
      000745 F5 81            [12] 1807 	mov	sp,a
      000747 C0 04            [24] 1808 	push	ar4
      000749 C0 05            [24] 1809 	push	ar5
      00074B C0 06            [24] 1810 	push	ar6
      00074D C0 07            [24] 1811 	push	ar7
                           000698  1812 	C$fuzzy.h$217$1_0$57 ==.
                                   1813 ;	../../fuzzy.h:217: if (!up) {
      00074F A8 1D            [24] 1814 	mov	r0,_bp
      000751 08               [12] 1815 	inc	r0
      000752 86 82            [24] 1816 	mov	dpl, @r0
      000754 08               [12] 1817 	inc	r0
      000755 86 83            [24] 1818 	mov	dph, @r0
      000757 08               [12] 1819 	inc	r0
      000758 86 F0            [24] 1820 	mov	b, @r0
      00075A 08               [12] 1821 	inc	r0
      00075B E6               [12] 1822 	mov	a, @r0
      00075C 12 1F 54         [24] 1823 	lcall	___fsdiv
      00075F AF 82            [24] 1824 	mov	r7, dpl
      000761 AE 83            [24] 1825 	mov	r6, dph
      000763 AD F0            [24] 1826 	mov	r5, b
      000765 FC               [12] 1827 	mov	r4, a
      000766 E5 81            [12] 1828 	mov	a,sp
      000768 24 FC            [12] 1829 	add	a,#0xfc
      00076A F5 81            [12] 1830 	mov	sp,a
      00076C E5 1D            [12] 1831 	mov	a,_bp
      00076E 24 F5            [12] 1832 	add	a,#0xf5
      000770 F8               [12] 1833 	mov	r0,a
      000771 E6               [12] 1834 	mov	a,@r0
      000772 70 20            [24] 1835 	jnz	00110$
                           0006BD  1836 	C$fuzzy.h$218$1_0$57 ==.
                                   1837 ;	../../fuzzy.h:218: result = 1.0f - result;
      000774 C0 07            [24] 1838 	push	ar7
      000776 C0 06            [24] 1839 	push	ar6
      000778 C0 05            [24] 1840 	push	ar5
      00077A C0 04            [24] 1841 	push	ar4
      00077C 90 00 00         [24] 1842 	mov	dptr,#0x0000
      00077F 75 F0 80         [24] 1843 	mov	b, #0x80
      000782 74 3F            [12] 1844 	mov	a, #0x3f
      000784 12 1C D2         [24] 1845 	lcall	___fssub
      000787 AF 82            [24] 1846 	mov	r7, dpl
      000789 AE 83            [24] 1847 	mov	r6, dph
      00078B AD F0            [24] 1848 	mov	r5, b
      00078D FC               [12] 1849 	mov	r4, a
      00078E E5 81            [12] 1850 	mov	a,sp
      000790 24 FC            [12] 1851 	add	a,#0xfc
      000792 F5 81            [12] 1852 	mov	sp,a
      000794                       1853 00110$:
                           0006DD  1854 	C$fuzzy.h$222$1_0$57 ==.
                                   1855 ;	../../fuzzy.h:222: return fuzzy_8051_hedge(result, hedge);
      000794 E5 1D            [12] 1856 	mov	a,_bp
      000796 24 F4            [12] 1857 	add	a,#0xf4
      000798 F8               [12] 1858 	mov	r0,a
      000799 E6               [12] 1859 	mov	a,@r0
      00079A C0 E0            [24] 1860 	push	acc
      00079C 8F 82            [24] 1861 	mov	dpl, r7
      00079E 8E 83            [24] 1862 	mov	dph, r6
      0007A0 8D F0            [24] 1863 	mov	b, r5
      0007A2 EC               [12] 1864 	mov	a, r4
      0007A3 12 04 F4         [24] 1865 	lcall	_fuzzy_8051_hedge
      0007A6 AC 82            [24] 1866 	mov	r4, dpl
      0007A8 AD 83            [24] 1867 	mov	r5, dph
      0007AA AE F0            [24] 1868 	mov	r6, b
      0007AC FF               [12] 1869 	mov	r7, a
      0007AD 15 81            [12] 1870 	dec	sp
      0007AF 8C 82            [24] 1871 	mov	dpl, r4
      0007B1 8D 83            [24] 1872 	mov	dph, r5
      0007B3 8E F0            [24] 1873 	mov	b, r6
      0007B5 EF               [12] 1874 	mov	a, r7
      0007B6                       1875 00111$:
                           0006FF  1876 	C$fuzzy.h$223$1_0$57 ==.
                                   1877 ;	../../fuzzy.h:223: }
      0007B6 85 1D 81         [24] 1878 	mov	sp,_bp
      0007B9 D0 1D            [24] 1879 	pop	_bp
                           000704  1880 	C$fuzzy.h$223$1_0$57 ==.
                           000704  1881 	XG$fuzzy_ramp$0$0 ==.
      0007BB 22               [24] 1882 	ret
                                   1883 ;------------------------------------------------------------
                                   1884 ;Allocation info for local variables in function 'fuzzy_triangle'
                                   1885 ;------------------------------------------------------------
                                   1886 ;b             Allocated to stack - _bp -6 +4 
                                   1887 ;c             Allocated to stack - _bp -10 +4 
                                   1888 ;x             Allocated to stack - _bp -14 +4 
                                   1889 ;hedge         Allocated to stack - _bp -15 +1 
                                   1890 ;a             Allocated to registers r7 r6 r5 r4 
                                   1891 ;result        Allocated to stack - _bp +1 +4 
                                   1892 ;sloc0         Allocated to stack - _bp +1 +4 
                                   1893 ;sloc1         Allocated to stack - _bp +5 +4 
                                   1894 ;------------------------------------------------------------
                           000705  1895 	G$fuzzy_triangle$0$0 ==.
                           000705  1896 	C$fuzzy.h$225$1_0$64 ==.
                                   1897 ;	../../fuzzy.h:225: float fuzzy_triangle(float a, float b, float c, float x, fuzzy_hedge_t hedge)
                                   1898 ;	-----------------------------------------
                                   1899 ;	 function fuzzy_triangle
                                   1900 ;	-----------------------------------------
      0007BC                       1901 _fuzzy_triangle:
      0007BC C0 1D            [24] 1902 	push	_bp
      0007BE 85 81 1D         [24] 1903 	mov	_bp,sp
      0007C1 AF 82            [24] 1904 	mov	r7,dpl
      0007C3 AE 83            [24] 1905 	mov	r6,dph
      0007C5 AD F0            [24] 1906 	mov	r5,b
      0007C7 FC               [12] 1907 	mov	r4,a
      0007C8 E5 81            [12] 1908 	mov	a,sp
      0007CA 24 08            [12] 1909 	add	a,#0x08
      0007CC F5 81            [12] 1910 	mov	sp,a
                           000717  1911 	C$fuzzy.h$229$1_0$64 ==.
                                   1912 ;	../../fuzzy.h:229: if (a >= b || b >= c || x <= a || x >= c) {
      0007CE C0 07            [24] 1913 	push	ar7
      0007D0 C0 06            [24] 1914 	push	ar6
      0007D2 C0 05            [24] 1915 	push	ar5
      0007D4 C0 04            [24] 1916 	push	ar4
      0007D6 E5 1D            [12] 1917 	mov	a,_bp
      0007D8 24 FA            [12] 1918 	add	a,#0xfa
      0007DA F8               [12] 1919 	mov	r0,a
      0007DB E6               [12] 1920 	mov	a,@r0
      0007DC C0 E0            [24] 1921 	push	acc
      0007DE 08               [12] 1922 	inc	r0
      0007DF E6               [12] 1923 	mov	a,@r0
      0007E0 C0 E0            [24] 1924 	push	acc
      0007E2 08               [12] 1925 	inc	r0
      0007E3 E6               [12] 1926 	mov	a,@r0
      0007E4 C0 E0            [24] 1927 	push	acc
      0007E6 08               [12] 1928 	inc	r0
      0007E7 E6               [12] 1929 	mov	a,@r0
      0007E8 C0 E0            [24] 1930 	push	acc
      0007EA 8F 82            [24] 1931 	mov	dpl, r7
      0007EC 8E 83            [24] 1932 	mov	dph, r6
      0007EE 8D F0            [24] 1933 	mov	b, r5
      0007F0 EC               [12] 1934 	mov	a, r4
      0007F1 12 1E 0D         [24] 1935 	lcall	___fslt
      0007F4 E5 81            [12] 1936 	mov	a,sp
      0007F6 24 FC            [12] 1937 	add	a,#0xfc
      0007F8 F5 81            [12] 1938 	mov	sp,a
      0007FA D0 04            [24] 1939 	pop	ar4
      0007FC D0 05            [24] 1940 	pop	ar5
      0007FE D0 06            [24] 1941 	pop	ar6
      000800 D0 07            [24] 1942 	pop	ar7
      000802 E5 82            [12] 1943 	mov	a, dpl
      000804 24 FF            [12] 1944 	add	a,#0xff
      000806 92 00            [24] 1945 	mov	b0,c
      000808 40 03            [24] 1946 	jc	00145$
      00080A 02 08 D4         [24] 1947 	ljmp	00107$
      00080D                       1948 00145$:
      00080D C0 07            [24] 1949 	push	ar7
      00080F C0 06            [24] 1950 	push	ar6
      000811 C0 05            [24] 1951 	push	ar5
      000813 C0 04            [24] 1952 	push	ar4
      000815 E5 1D            [12] 1953 	mov	a,_bp
      000817 24 F6            [12] 1954 	add	a,#0xf6
      000819 F8               [12] 1955 	mov	r0,a
      00081A E6               [12] 1956 	mov	a,@r0
      00081B C0 E0            [24] 1957 	push	acc
      00081D 08               [12] 1958 	inc	r0
      00081E E6               [12] 1959 	mov	a,@r0
      00081F C0 E0            [24] 1960 	push	acc
      000821 08               [12] 1961 	inc	r0
      000822 E6               [12] 1962 	mov	a,@r0
      000823 C0 E0            [24] 1963 	push	acc
      000825 08               [12] 1964 	inc	r0
      000826 E6               [12] 1965 	mov	a,@r0
      000827 C0 E0            [24] 1966 	push	acc
      000829 E5 1D            [12] 1967 	mov	a,_bp
      00082B 24 FA            [12] 1968 	add	a,#0xfa
      00082D F8               [12] 1969 	mov	r0,a
      00082E 86 82            [24] 1970 	mov	dpl, @r0
      000830 08               [12] 1971 	inc	r0
      000831 86 83            [24] 1972 	mov	dph, @r0
      000833 08               [12] 1973 	inc	r0
      000834 86 F0            [24] 1974 	mov	b, @r0
      000836 08               [12] 1975 	inc	r0
      000837 E6               [12] 1976 	mov	a, @r0
      000838 12 1E 0D         [24] 1977 	lcall	___fslt
      00083B E5 81            [12] 1978 	mov	a,sp
      00083D 24 FC            [12] 1979 	add	a,#0xfc
      00083F F5 81            [12] 1980 	mov	sp,a
      000841 D0 04            [24] 1981 	pop	ar4
      000843 D0 05            [24] 1982 	pop	ar5
      000845 D0 06            [24] 1983 	pop	ar6
      000847 D0 07            [24] 1984 	pop	ar7
      000849 E5 82            [12] 1985 	mov	a, dpl
      00084B 24 FF            [12] 1986 	add	a,#0xff
      00084D 92 00            [24] 1987 	mov	b0,c
      00084F 40 03            [24] 1988 	jc	00146$
      000851 02 08 D4         [24] 1989 	ljmp	00107$
      000854                       1990 00146$:
      000854 C0 07            [24] 1991 	push	ar7
      000856 C0 06            [24] 1992 	push	ar6
      000858 C0 05            [24] 1993 	push	ar5
      00085A C0 04            [24] 1994 	push	ar4
      00085C E5 1D            [12] 1995 	mov	a,_bp
      00085E 24 F2            [12] 1996 	add	a,#0xf2
      000860 F8               [12] 1997 	mov	r0,a
      000861 E6               [12] 1998 	mov	a,@r0
      000862 C0 E0            [24] 1999 	push	acc
      000864 08               [12] 2000 	inc	r0
      000865 E6               [12] 2001 	mov	a,@r0
      000866 C0 E0            [24] 2002 	push	acc
      000868 08               [12] 2003 	inc	r0
      000869 E6               [12] 2004 	mov	a,@r0
      00086A C0 E0            [24] 2005 	push	acc
      00086C 08               [12] 2006 	inc	r0
      00086D E6               [12] 2007 	mov	a,@r0
      00086E C0 E0            [24] 2008 	push	acc
      000870 8F 82            [24] 2009 	mov	dpl, r7
      000872 8E 83            [24] 2010 	mov	dph, r6
      000874 8D F0            [24] 2011 	mov	b, r5
      000876 EC               [12] 2012 	mov	a, r4
      000877 12 1E 0D         [24] 2013 	lcall	___fslt
      00087A E5 81            [12] 2014 	mov	a,sp
      00087C 24 FC            [12] 2015 	add	a,#0xfc
      00087E F5 81            [12] 2016 	mov	sp,a
      000880 D0 04            [24] 2017 	pop	ar4
      000882 D0 05            [24] 2018 	pop	ar5
      000884 D0 06            [24] 2019 	pop	ar6
      000886 D0 07            [24] 2020 	pop	ar7
      000888 E5 82            [12] 2021 	mov	a, dpl
      00088A 24 FF            [12] 2022 	add	a,#0xff
      00088C 92 00            [24] 2023 	mov	b0,c
      00088E 50 44            [24] 2024 	jnc	00107$
      000890 C0 07            [24] 2025 	push	ar7
      000892 C0 06            [24] 2026 	push	ar6
      000894 C0 05            [24] 2027 	push	ar5
      000896 C0 04            [24] 2028 	push	ar4
      000898 E5 1D            [12] 2029 	mov	a,_bp
      00089A 24 F6            [12] 2030 	add	a,#0xf6
      00089C F8               [12] 2031 	mov	r0,a
      00089D E6               [12] 2032 	mov	a,@r0
      00089E C0 E0            [24] 2033 	push	acc
      0008A0 08               [12] 2034 	inc	r0
      0008A1 E6               [12] 2035 	mov	a,@r0
      0008A2 C0 E0            [24] 2036 	push	acc
      0008A4 08               [12] 2037 	inc	r0
      0008A5 E6               [12] 2038 	mov	a,@r0
      0008A6 C0 E0            [24] 2039 	push	acc
      0008A8 08               [12] 2040 	inc	r0
      0008A9 E6               [12] 2041 	mov	a,@r0
      0008AA C0 E0            [24] 2042 	push	acc
      0008AC E5 1D            [12] 2043 	mov	a,_bp
      0008AE 24 F2            [12] 2044 	add	a,#0xf2
      0008B0 F8               [12] 2045 	mov	r0,a
      0008B1 86 82            [24] 2046 	mov	dpl, @r0
      0008B3 08               [12] 2047 	inc	r0
      0008B4 86 83            [24] 2048 	mov	dph, @r0
      0008B6 08               [12] 2049 	inc	r0
      0008B7 86 F0            [24] 2050 	mov	b, @r0
      0008B9 08               [12] 2051 	inc	r0
      0008BA E6               [12] 2052 	mov	a, @r0
      0008BB 12 1E 0D         [24] 2053 	lcall	___fslt
      0008BE E5 81            [12] 2054 	mov	a,sp
      0008C0 24 FC            [12] 2055 	add	a,#0xfc
      0008C2 F5 81            [12] 2056 	mov	sp,a
      0008C4 D0 04            [24] 2057 	pop	ar4
      0008C6 D0 05            [24] 2058 	pop	ar5
      0008C8 D0 06            [24] 2059 	pop	ar6
      0008CA D0 07            [24] 2060 	pop	ar7
      0008CC E5 82            [12] 2061 	mov	a, dpl
      0008CE 24 FF            [12] 2062 	add	a,#0xff
      0008D0 92 00            [24] 2063 	mov	b0,c
      0008D2 40 0E            [24] 2064 	jc	00108$
      0008D4                       2065 00107$:
                           00081D  2066 	C$fuzzy.h$230$2_0$65 ==.
                                   2067 ;	../../fuzzy.h:230: result = 0.0f;
      0008D4 A8 1D            [24] 2068 	mov	r0,_bp
      0008D6 08               [12] 2069 	inc	r0
      0008D7 E4               [12] 2070 	clr	a
      0008D8 F6               [12] 2071 	mov	@r0,a
      0008D9 08               [12] 2072 	inc	r0
      0008DA F6               [12] 2073 	mov	@r0,a
      0008DB 08               [12] 2074 	inc	r0
      0008DC F6               [12] 2075 	mov	@r0,a
      0008DD 08               [12] 2076 	inc	r0
      0008DE F6               [12] 2077 	mov	@r0,a
      0008DF 02 0A 9A         [24] 2078 	ljmp	00109$
      0008E2                       2079 00108$:
                           00082B  2080 	C$fuzzy.h$232$1_0$64 ==.
                                   2081 ;	../../fuzzy.h:232: else if (x == b) {
      0008E2 C0 07            [24] 2082 	push	ar7
      0008E4 C0 06            [24] 2083 	push	ar6
      0008E6 C0 05            [24] 2084 	push	ar5
      0008E8 C0 04            [24] 2085 	push	ar4
      0008EA E5 1D            [12] 2086 	mov	a,_bp
      0008EC 24 FA            [12] 2087 	add	a,#0xfa
      0008EE F8               [12] 2088 	mov	r0,a
      0008EF E6               [12] 2089 	mov	a,@r0
      0008F0 C0 E0            [24] 2090 	push	acc
      0008F2 08               [12] 2091 	inc	r0
      0008F3 E6               [12] 2092 	mov	a,@r0
      0008F4 C0 E0            [24] 2093 	push	acc
      0008F6 08               [12] 2094 	inc	r0
      0008F7 E6               [12] 2095 	mov	a,@r0
      0008F8 C0 E0            [24] 2096 	push	acc
      0008FA 08               [12] 2097 	inc	r0
      0008FB E6               [12] 2098 	mov	a,@r0
      0008FC C0 E0            [24] 2099 	push	acc
      0008FE E5 1D            [12] 2100 	mov	a,_bp
      000900 24 F2            [12] 2101 	add	a,#0xf2
      000902 F8               [12] 2102 	mov	r0,a
      000903 86 82            [24] 2103 	mov	dpl, @r0
      000905 08               [12] 2104 	inc	r0
      000906 86 83            [24] 2105 	mov	dph, @r0
      000908 08               [12] 2106 	inc	r0
      000909 86 F0            [24] 2107 	mov	b, @r0
      00090B 08               [12] 2108 	inc	r0
      00090C E6               [12] 2109 	mov	a, @r0
      00090D 12 1D E1         [24] 2110 	lcall	___fseq
      000910 AB 82            [24] 2111 	mov	r3, dpl
      000912 E5 81            [12] 2112 	mov	a,sp
      000914 24 FC            [12] 2113 	add	a,#0xfc
      000916 F5 81            [12] 2114 	mov	sp,a
      000918 D0 04            [24] 2115 	pop	ar4
      00091A D0 05            [24] 2116 	pop	ar5
      00091C D0 06            [24] 2117 	pop	ar6
      00091E D0 07            [24] 2118 	pop	ar7
      000920 EB               [12] 2119 	mov	a,r3
      000921 60 10            [24] 2120 	jz	00105$
                           00086C  2121 	C$fuzzy.h$233$2_0$66 ==.
                                   2122 ;	../../fuzzy.h:233: result = 1.0f;
      000923 A8 1D            [24] 2123 	mov	r0,_bp
      000925 08               [12] 2124 	inc	r0
      000926 E4               [12] 2125 	clr	a
      000927 F6               [12] 2126 	mov	@r0,a
      000928 08               [12] 2127 	inc	r0
      000929 F6               [12] 2128 	mov	@r0,a
      00092A 08               [12] 2129 	inc	r0
      00092B 76 80            [12] 2130 	mov	@r0,#0x80
      00092D 08               [12] 2131 	inc	r0
      00092E 76 3F            [12] 2132 	mov	@r0,#0x3f
      000930 02 0A 9A         [24] 2133 	ljmp	00109$
      000933                       2134 00105$:
                           00087C  2135 	C$fuzzy.h$235$1_0$64 ==.
                                   2136 ;	../../fuzzy.h:235: else if (x < b) {
      000933 C0 07            [24] 2137 	push	ar7
      000935 C0 06            [24] 2138 	push	ar6
      000937 C0 05            [24] 2139 	push	ar5
      000939 C0 04            [24] 2140 	push	ar4
      00093B E5 1D            [12] 2141 	mov	a,_bp
      00093D 24 FA            [12] 2142 	add	a,#0xfa
      00093F F8               [12] 2143 	mov	r0,a
      000940 E6               [12] 2144 	mov	a,@r0
      000941 C0 E0            [24] 2145 	push	acc
      000943 08               [12] 2146 	inc	r0
      000944 E6               [12] 2147 	mov	a,@r0
      000945 C0 E0            [24] 2148 	push	acc
      000947 08               [12] 2149 	inc	r0
      000948 E6               [12] 2150 	mov	a,@r0
      000949 C0 E0            [24] 2151 	push	acc
      00094B 08               [12] 2152 	inc	r0
      00094C E6               [12] 2153 	mov	a,@r0
      00094D C0 E0            [24] 2154 	push	acc
      00094F E5 1D            [12] 2155 	mov	a,_bp
      000951 24 F2            [12] 2156 	add	a,#0xf2
      000953 F8               [12] 2157 	mov	r0,a
      000954 86 82            [24] 2158 	mov	dpl, @r0
      000956 08               [12] 2159 	inc	r0
      000957 86 83            [24] 2160 	mov	dph, @r0
      000959 08               [12] 2161 	inc	r0
      00095A 86 F0            [24] 2162 	mov	b, @r0
      00095C 08               [12] 2163 	inc	r0
      00095D E6               [12] 2164 	mov	a, @r0
      00095E 12 1E 0D         [24] 2165 	lcall	___fslt
      000961 AB 82            [24] 2166 	mov	r3, dpl
      000963 E5 81            [12] 2167 	mov	a,sp
      000965 24 FC            [12] 2168 	add	a,#0xfc
      000967 F5 81            [12] 2169 	mov	sp,a
      000969 D0 04            [24] 2170 	pop	ar4
      00096B D0 05            [24] 2171 	pop	ar5
      00096D D0 06            [24] 2172 	pop	ar6
      00096F D0 07            [24] 2173 	pop	ar7
      000971 EB               [12] 2174 	mov	a,r3
      000972 70 03            [24] 2175 	jnz	00150$
      000974 02 09 FE         [24] 2176 	ljmp	00102$
      000977                       2177 00150$:
                           0008C0  2178 	C$fuzzy.h$236$1_0$64 ==.
                                   2179 ;	../../fuzzy.h:236: result = (x - a) / (b - a);
      000977 C0 07            [24] 2180 	push	ar7
      000979 C0 06            [24] 2181 	push	ar6
      00097B C0 05            [24] 2182 	push	ar5
      00097D C0 04            [24] 2183 	push	ar4
      00097F C0 07            [24] 2184 	push	ar7
      000981 C0 06            [24] 2185 	push	ar6
      000983 C0 05            [24] 2186 	push	ar5
      000985 C0 04            [24] 2187 	push	ar4
      000987 E5 1D            [12] 2188 	mov	a,_bp
      000989 24 F2            [12] 2189 	add	a,#0xf2
      00098B F8               [12] 2190 	mov	r0,a
      00098C 86 82            [24] 2191 	mov	dpl, @r0
      00098E 08               [12] 2192 	inc	r0
      00098F 86 83            [24] 2193 	mov	dph, @r0
      000991 08               [12] 2194 	inc	r0
      000992 86 F0            [24] 2195 	mov	b, @r0
      000994 08               [12] 2196 	inc	r0
      000995 E6               [12] 2197 	mov	a, @r0
      000996 12 1C D2         [24] 2198 	lcall	___fssub
      000999 C8               [12] 2199 	xch	a,r0
      00099A E5 1D            [12] 2200 	mov	a,_bp
      00099C 24 05            [12] 2201 	add	a,#0x05
      00099E C8               [12] 2202 	xch	a,r0
      00099F A6 82            [24] 2203 	mov	@r0, dpl
      0009A1 08               [12] 2204 	inc	r0
      0009A2 A6 83            [24] 2205 	mov	@r0, dph
      0009A4 08               [12] 2206 	inc	r0
      0009A5 A6 F0            [24] 2207 	mov	@r0, b
      0009A7 08               [12] 2208 	inc	r0
      0009A8 F6               [12] 2209 	mov	@r0,a
      0009A9 E5 81            [12] 2210 	mov	a,sp
      0009AB 24 FC            [12] 2211 	add	a,#0xfc
      0009AD F5 81            [12] 2212 	mov	sp,a
      0009AF E5 1D            [12] 2213 	mov	a,_bp
      0009B1 24 FA            [12] 2214 	add	a,#0xfa
      0009B3 F8               [12] 2215 	mov	r0,a
      0009B4 86 82            [24] 2216 	mov	dpl, @r0
      0009B6 08               [12] 2217 	inc	r0
      0009B7 86 83            [24] 2218 	mov	dph, @r0
      0009B9 08               [12] 2219 	inc	r0
      0009BA 86 F0            [24] 2220 	mov	b, @r0
      0009BC 08               [12] 2221 	inc	r0
      0009BD E6               [12] 2222 	mov	a, @r0
      0009BE 12 1C D2         [24] 2223 	lcall	___fssub
      0009C1 AC 82            [24] 2224 	mov	r4, dpl
      0009C3 AD 83            [24] 2225 	mov	r5, dph
      0009C5 AE F0            [24] 2226 	mov	r6, b
      0009C7 FF               [12] 2227 	mov	r7, a
      0009C8 E5 81            [12] 2228 	mov	a,sp
      0009CA 24 FC            [12] 2229 	add	a,#0xfc
      0009CC F5 81            [12] 2230 	mov	sp,a
      0009CE C0 04            [24] 2231 	push	ar4
      0009D0 C0 05            [24] 2232 	push	ar5
      0009D2 C0 06            [24] 2233 	push	ar6
      0009D4 C0 07            [24] 2234 	push	ar7
      0009D6 E5 1D            [12] 2235 	mov	a,_bp
      0009D8 24 05            [12] 2236 	add	a,#0x05
      0009DA F8               [12] 2237 	mov	r0,a
      0009DB 86 82            [24] 2238 	mov	dpl, @r0
      0009DD 08               [12] 2239 	inc	r0
      0009DE 86 83            [24] 2240 	mov	dph, @r0
      0009E0 08               [12] 2241 	inc	r0
      0009E1 86 F0            [24] 2242 	mov	b, @r0
      0009E3 08               [12] 2243 	inc	r0
      0009E4 E6               [12] 2244 	mov	a, @r0
      0009E5 12 1F 54         [24] 2245 	lcall	___fsdiv
      0009E8 A8 1D            [24] 2246 	mov	r0,_bp
      0009EA 08               [12] 2247 	inc	r0
      0009EB A6 82            [24] 2248 	mov	@r0, dpl
      0009ED 08               [12] 2249 	inc	r0
      0009EE A6 83            [24] 2250 	mov	@r0, dph
      0009F0 08               [12] 2251 	inc	r0
      0009F1 A6 F0            [24] 2252 	mov	@r0, b
      0009F3 08               [12] 2253 	inc	r0
      0009F4 F6               [12] 2254 	mov	@r0,a
      0009F5 E5 81            [12] 2255 	mov	a,sp
      0009F7 24 FC            [12] 2256 	add	a,#0xfc
      0009F9 F5 81            [12] 2257 	mov	sp,a
      0009FB 02 0A 9A         [24] 2258 	ljmp	00109$
      0009FE                       2259 00102$:
                           000947  2260 	C$fuzzy.h$239$1_0$64 ==.
                                   2261 ;	../../fuzzy.h:239: result = (c - x) / (c - b);
      0009FE E5 1D            [12] 2262 	mov	a,_bp
      000A00 24 F2            [12] 2263 	add	a,#0xf2
      000A02 F8               [12] 2264 	mov	r0,a
      000A03 E6               [12] 2265 	mov	a,@r0
      000A04 C0 E0            [24] 2266 	push	acc
      000A06 08               [12] 2267 	inc	r0
      000A07 E6               [12] 2268 	mov	a,@r0
      000A08 C0 E0            [24] 2269 	push	acc
      000A0A 08               [12] 2270 	inc	r0
      000A0B E6               [12] 2271 	mov	a,@r0
      000A0C C0 E0            [24] 2272 	push	acc
      000A0E 08               [12] 2273 	inc	r0
      000A0F E6               [12] 2274 	mov	a,@r0
      000A10 C0 E0            [24] 2275 	push	acc
      000A12 E5 1D            [12] 2276 	mov	a,_bp
      000A14 24 F6            [12] 2277 	add	a,#0xf6
      000A16 F8               [12] 2278 	mov	r0,a
      000A17 86 82            [24] 2279 	mov	dpl, @r0
      000A19 08               [12] 2280 	inc	r0
      000A1A 86 83            [24] 2281 	mov	dph, @r0
      000A1C 08               [12] 2282 	inc	r0
      000A1D 86 F0            [24] 2283 	mov	b, @r0
      000A1F 08               [12] 2284 	inc	r0
      000A20 E6               [12] 2285 	mov	a, @r0
      000A21 12 1C D2         [24] 2286 	lcall	___fssub
      000A24 C8               [12] 2287 	xch	a,r0
      000A25 E5 1D            [12] 2288 	mov	a,_bp
      000A27 24 05            [12] 2289 	add	a,#0x05
      000A29 C8               [12] 2290 	xch	a,r0
      000A2A A6 82            [24] 2291 	mov	@r0, dpl
      000A2C 08               [12] 2292 	inc	r0
      000A2D A6 83            [24] 2293 	mov	@r0, dph
      000A2F 08               [12] 2294 	inc	r0
      000A30 A6 F0            [24] 2295 	mov	@r0, b
      000A32 08               [12] 2296 	inc	r0
      000A33 F6               [12] 2297 	mov	@r0,a
      000A34 E5 81            [12] 2298 	mov	a,sp
      000A36 24 FC            [12] 2299 	add	a,#0xfc
      000A38 F5 81            [12] 2300 	mov	sp,a
      000A3A E5 1D            [12] 2301 	mov	a,_bp
      000A3C 24 FA            [12] 2302 	add	a,#0xfa
      000A3E F8               [12] 2303 	mov	r0,a
      000A3F E6               [12] 2304 	mov	a,@r0
      000A40 C0 E0            [24] 2305 	push	acc
      000A42 08               [12] 2306 	inc	r0
      000A43 E6               [12] 2307 	mov	a,@r0
      000A44 C0 E0            [24] 2308 	push	acc
      000A46 08               [12] 2309 	inc	r0
      000A47 E6               [12] 2310 	mov	a,@r0
      000A48 C0 E0            [24] 2311 	push	acc
      000A4A 08               [12] 2312 	inc	r0
      000A4B E6               [12] 2313 	mov	a,@r0
      000A4C C0 E0            [24] 2314 	push	acc
      000A4E E5 1D            [12] 2315 	mov	a,_bp
      000A50 24 F6            [12] 2316 	add	a,#0xf6
      000A52 F8               [12] 2317 	mov	r0,a
      000A53 86 82            [24] 2318 	mov	dpl, @r0
      000A55 08               [12] 2319 	inc	r0
      000A56 86 83            [24] 2320 	mov	dph, @r0
      000A58 08               [12] 2321 	inc	r0
      000A59 86 F0            [24] 2322 	mov	b, @r0
      000A5B 08               [12] 2323 	inc	r0
      000A5C E6               [12] 2324 	mov	a, @r0
      000A5D 12 1C D2         [24] 2325 	lcall	___fssub
      000A60 AA 82            [24] 2326 	mov	r2, dpl
      000A62 AB 83            [24] 2327 	mov	r3, dph
      000A64 AE F0            [24] 2328 	mov	r6, b
      000A66 FF               [12] 2329 	mov	r7, a
      000A67 E5 81            [12] 2330 	mov	a,sp
      000A69 24 FC            [12] 2331 	add	a,#0xfc
      000A6B F5 81            [12] 2332 	mov	sp,a
      000A6D C0 02            [24] 2333 	push	ar2
      000A6F C0 03            [24] 2334 	push	ar3
      000A71 C0 06            [24] 2335 	push	ar6
      000A73 C0 07            [24] 2336 	push	ar7
      000A75 E5 1D            [12] 2337 	mov	a,_bp
      000A77 24 05            [12] 2338 	add	a,#0x05
      000A79 F8               [12] 2339 	mov	r0,a
      000A7A 86 82            [24] 2340 	mov	dpl, @r0
      000A7C 08               [12] 2341 	inc	r0
      000A7D 86 83            [24] 2342 	mov	dph, @r0
      000A7F 08               [12] 2343 	inc	r0
      000A80 86 F0            [24] 2344 	mov	b, @r0
      000A82 08               [12] 2345 	inc	r0
      000A83 E6               [12] 2346 	mov	a, @r0
      000A84 12 1F 54         [24] 2347 	lcall	___fsdiv
      000A87 A8 1D            [24] 2348 	mov	r0,_bp
      000A89 08               [12] 2349 	inc	r0
      000A8A A6 82            [24] 2350 	mov	@r0, dpl
      000A8C 08               [12] 2351 	inc	r0
      000A8D A6 83            [24] 2352 	mov	@r0, dph
      000A8F 08               [12] 2353 	inc	r0
      000A90 A6 F0            [24] 2354 	mov	@r0, b
      000A92 08               [12] 2355 	inc	r0
      000A93 F6               [12] 2356 	mov	@r0,a
      000A94 E5 81            [12] 2357 	mov	a,sp
      000A96 24 FC            [12] 2358 	add	a,#0xfc
      000A98 F5 81            [12] 2359 	mov	sp,a
      000A9A                       2360 00109$:
                           0009E3  2361 	C$fuzzy.h$242$1_0$64 ==.
                                   2362 ;	../../fuzzy.h:242: return fuzzy_8051_hedge(result, hedge);
      000A9A E5 1D            [12] 2363 	mov	a,_bp
      000A9C 24 F1            [12] 2364 	add	a,#0xf1
      000A9E F8               [12] 2365 	mov	r0,a
      000A9F E6               [12] 2366 	mov	a,@r0
      000AA0 C0 E0            [24] 2367 	push	acc
      000AA2 A8 1D            [24] 2368 	mov	r0,_bp
      000AA4 08               [12] 2369 	inc	r0
      000AA5 86 82            [24] 2370 	mov	dpl, @r0
      000AA7 08               [12] 2371 	inc	r0
      000AA8 86 83            [24] 2372 	mov	dph, @r0
      000AAA 08               [12] 2373 	inc	r0
      000AAB 86 F0            [24] 2374 	mov	b, @r0
      000AAD 08               [12] 2375 	inc	r0
      000AAE E6               [12] 2376 	mov	a, @r0
      000AAF 12 04 F4         [24] 2377 	lcall	_fuzzy_8051_hedge
      000AB2 AC 82            [24] 2378 	mov	r4, dpl
      000AB4 AD 83            [24] 2379 	mov	r5, dph
      000AB6 AE F0            [24] 2380 	mov	r6, b
      000AB8 FF               [12] 2381 	mov	r7, a
      000AB9 15 81            [12] 2382 	dec	sp
      000ABB 8C 82            [24] 2383 	mov	dpl, r4
      000ABD 8D 83            [24] 2384 	mov	dph, r5
      000ABF 8E F0            [24] 2385 	mov	b, r6
      000AC1 EF               [12] 2386 	mov	a, r7
                           000A0B  2387 	C$fuzzy.h$243$1_0$64 ==.
                                   2388 ;	../../fuzzy.h:243: }
      000AC2 85 1D 81         [24] 2389 	mov	sp,_bp
      000AC5 D0 1D            [24] 2390 	pop	_bp
                           000A10  2391 	C$fuzzy.h$243$1_0$64 ==.
                           000A10  2392 	XG$fuzzy_triangle$0$0 ==.
      000AC7 22               [24] 2393 	ret
                                   2394 ;------------------------------------------------------------
                                   2395 ;Allocation info for local variables in function 'fuzzy_trapezoid'
                                   2396 ;------------------------------------------------------------
                                   2397 ;b             Allocated to stack - _bp -6 +4 
                                   2398 ;c             Allocated to stack - _bp -10 +4 
                                   2399 ;d             Allocated to stack - _bp -14 +4 
                                   2400 ;x             Allocated to stack - _bp -18 +4 
                                   2401 ;hedge         Allocated to stack - _bp -19 +1 
                                   2402 ;a             Allocated to registers r7 r6 r5 r4 
                                   2403 ;result        Allocated to stack - _bp +1 +4 
                                   2404 ;sloc0         Allocated to stack - _bp +1 +4 
                                   2405 ;sloc1         Allocated to stack - _bp +5 +4 
                                   2406 ;------------------------------------------------------------
                           000A11  2407 	G$fuzzy_trapezoid$0$0 ==.
                           000A11  2408 	C$fuzzy.h$245$1_0$70 ==.
                                   2409 ;	../../fuzzy.h:245: float fuzzy_trapezoid(float a, float b, float c, float d, float x, fuzzy_hedge_t hedge)
                                   2410 ;	-----------------------------------------
                                   2411 ;	 function fuzzy_trapezoid
                                   2412 ;	-----------------------------------------
      000AC8                       2413 _fuzzy_trapezoid:
      000AC8 C0 1D            [24] 2414 	push	_bp
      000ACA 85 81 1D         [24] 2415 	mov	_bp,sp
      000ACD AF 82            [24] 2416 	mov	r7,dpl
      000ACF AE 83            [24] 2417 	mov	r6,dph
      000AD1 AD F0            [24] 2418 	mov	r5,b
      000AD3 FC               [12] 2419 	mov	r4,a
      000AD4 E5 81            [12] 2420 	mov	a,sp
      000AD6 24 08            [12] 2421 	add	a,#0x08
      000AD8 F5 81            [12] 2422 	mov	sp,a
                           000A23  2423 	C$fuzzy.h$249$1_0$70 ==.
                                   2424 ;	../../fuzzy.h:249: if (a >= b || b > c || c >= d || x <= a || x >= d) {
      000ADA C0 07            [24] 2425 	push	ar7
      000ADC C0 06            [24] 2426 	push	ar6
      000ADE C0 05            [24] 2427 	push	ar5
      000AE0 C0 04            [24] 2428 	push	ar4
      000AE2 E5 1D            [12] 2429 	mov	a,_bp
      000AE4 24 FA            [12] 2430 	add	a,#0xfa
      000AE6 F8               [12] 2431 	mov	r0,a
      000AE7 E6               [12] 2432 	mov	a,@r0
      000AE8 C0 E0            [24] 2433 	push	acc
      000AEA 08               [12] 2434 	inc	r0
      000AEB E6               [12] 2435 	mov	a,@r0
      000AEC C0 E0            [24] 2436 	push	acc
      000AEE 08               [12] 2437 	inc	r0
      000AEF E6               [12] 2438 	mov	a,@r0
      000AF0 C0 E0            [24] 2439 	push	acc
      000AF2 08               [12] 2440 	inc	r0
      000AF3 E6               [12] 2441 	mov	a,@r0
      000AF4 C0 E0            [24] 2442 	push	acc
      000AF6 8F 82            [24] 2443 	mov	dpl, r7
      000AF8 8E 83            [24] 2444 	mov	dph, r6
      000AFA 8D F0            [24] 2445 	mov	b, r5
      000AFC EC               [12] 2446 	mov	a, r4
      000AFD 12 1E 0D         [24] 2447 	lcall	___fslt
      000B00 E5 81            [12] 2448 	mov	a,sp
      000B02 24 FC            [12] 2449 	add	a,#0xfc
      000B04 F5 81            [12] 2450 	mov	sp,a
      000B06 D0 04            [24] 2451 	pop	ar4
      000B08 D0 05            [24] 2452 	pop	ar5
      000B0A D0 06            [24] 2453 	pop	ar6
      000B0C D0 07            [24] 2454 	pop	ar7
      000B0E E5 82            [12] 2455 	mov	a, dpl
      000B10 24 FF            [12] 2456 	add	a,#0xff
      000B12 92 00            [24] 2457 	mov	b0,c
      000B14 40 03            [24] 2458 	jc	00159$
      000B16 02 0C 24         [24] 2459 	ljmp	00108$
      000B19                       2460 00159$:
      000B19 C0 07            [24] 2461 	push	ar7
      000B1B C0 06            [24] 2462 	push	ar6
      000B1D C0 05            [24] 2463 	push	ar5
      000B1F C0 04            [24] 2464 	push	ar4
      000B21 E5 1D            [12] 2465 	mov	a,_bp
      000B23 24 FA            [12] 2466 	add	a,#0xfa
      000B25 F8               [12] 2467 	mov	r0,a
      000B26 E6               [12] 2468 	mov	a,@r0
      000B27 C0 E0            [24] 2469 	push	acc
      000B29 08               [12] 2470 	inc	r0
      000B2A E6               [12] 2471 	mov	a,@r0
      000B2B C0 E0            [24] 2472 	push	acc
      000B2D 08               [12] 2473 	inc	r0
      000B2E E6               [12] 2474 	mov	a,@r0
      000B2F C0 E0            [24] 2475 	push	acc
      000B31 08               [12] 2476 	inc	r0
      000B32 E6               [12] 2477 	mov	a,@r0
      000B33 C0 E0            [24] 2478 	push	acc
      000B35 E5 1D            [12] 2479 	mov	a,_bp
      000B37 24 F6            [12] 2480 	add	a,#0xf6
      000B39 F8               [12] 2481 	mov	r0,a
      000B3A 86 82            [24] 2482 	mov	dpl, @r0
      000B3C 08               [12] 2483 	inc	r0
      000B3D 86 83            [24] 2484 	mov	dph, @r0
      000B3F 08               [12] 2485 	inc	r0
      000B40 86 F0            [24] 2486 	mov	b, @r0
      000B42 08               [12] 2487 	inc	r0
      000B43 E6               [12] 2488 	mov	a, @r0
      000B44 12 1E 0D         [24] 2489 	lcall	___fslt
      000B47 AB 82            [24] 2490 	mov	r3, dpl
      000B49 E5 81            [12] 2491 	mov	a,sp
      000B4B 24 FC            [12] 2492 	add	a,#0xfc
      000B4D F5 81            [12] 2493 	mov	sp,a
      000B4F D0 04            [24] 2494 	pop	ar4
      000B51 D0 05            [24] 2495 	pop	ar5
      000B53 D0 06            [24] 2496 	pop	ar6
      000B55 D0 07            [24] 2497 	pop	ar7
      000B57 EB               [12] 2498 	mov	a,r3
      000B58 60 03            [24] 2499 	jz	00160$
      000B5A 02 0C 24         [24] 2500 	ljmp	00108$
      000B5D                       2501 00160$:
      000B5D C0 07            [24] 2502 	push	ar7
      000B5F C0 06            [24] 2503 	push	ar6
      000B61 C0 05            [24] 2504 	push	ar5
      000B63 C0 04            [24] 2505 	push	ar4
      000B65 E5 1D            [12] 2506 	mov	a,_bp
      000B67 24 F2            [12] 2507 	add	a,#0xf2
      000B69 F8               [12] 2508 	mov	r0,a
      000B6A E6               [12] 2509 	mov	a,@r0
      000B6B C0 E0            [24] 2510 	push	acc
      000B6D 08               [12] 2511 	inc	r0
      000B6E E6               [12] 2512 	mov	a,@r0
      000B6F C0 E0            [24] 2513 	push	acc
      000B71 08               [12] 2514 	inc	r0
      000B72 E6               [12] 2515 	mov	a,@r0
      000B73 C0 E0            [24] 2516 	push	acc
      000B75 08               [12] 2517 	inc	r0
      000B76 E6               [12] 2518 	mov	a,@r0
      000B77 C0 E0            [24] 2519 	push	acc
      000B79 E5 1D            [12] 2520 	mov	a,_bp
      000B7B 24 F6            [12] 2521 	add	a,#0xf6
      000B7D F8               [12] 2522 	mov	r0,a
      000B7E 86 82            [24] 2523 	mov	dpl, @r0
      000B80 08               [12] 2524 	inc	r0
      000B81 86 83            [24] 2525 	mov	dph, @r0
      000B83 08               [12] 2526 	inc	r0
      000B84 86 F0            [24] 2527 	mov	b, @r0
      000B86 08               [12] 2528 	inc	r0
      000B87 E6               [12] 2529 	mov	a, @r0
      000B88 12 1E 0D         [24] 2530 	lcall	___fslt
      000B8B E5 81            [12] 2531 	mov	a,sp
      000B8D 24 FC            [12] 2532 	add	a,#0xfc
      000B8F F5 81            [12] 2533 	mov	sp,a
      000B91 D0 04            [24] 2534 	pop	ar4
      000B93 D0 05            [24] 2535 	pop	ar5
      000B95 D0 06            [24] 2536 	pop	ar6
      000B97 D0 07            [24] 2537 	pop	ar7
      000B99 E5 82            [12] 2538 	mov	a, dpl
      000B9B 24 FF            [12] 2539 	add	a,#0xff
      000B9D 92 00            [24] 2540 	mov	b0,c
      000B9F 40 03            [24] 2541 	jc	00161$
      000BA1 02 0C 24         [24] 2542 	ljmp	00108$
      000BA4                       2543 00161$:
      000BA4 C0 07            [24] 2544 	push	ar7
      000BA6 C0 06            [24] 2545 	push	ar6
      000BA8 C0 05            [24] 2546 	push	ar5
      000BAA C0 04            [24] 2547 	push	ar4
      000BAC E5 1D            [12] 2548 	mov	a,_bp
      000BAE 24 EE            [12] 2549 	add	a,#0xee
      000BB0 F8               [12] 2550 	mov	r0,a
      000BB1 E6               [12] 2551 	mov	a,@r0
      000BB2 C0 E0            [24] 2552 	push	acc
      000BB4 08               [12] 2553 	inc	r0
      000BB5 E6               [12] 2554 	mov	a,@r0
      000BB6 C0 E0            [24] 2555 	push	acc
      000BB8 08               [12] 2556 	inc	r0
      000BB9 E6               [12] 2557 	mov	a,@r0
      000BBA C0 E0            [24] 2558 	push	acc
      000BBC 08               [12] 2559 	inc	r0
      000BBD E6               [12] 2560 	mov	a,@r0
      000BBE C0 E0            [24] 2561 	push	acc
      000BC0 8F 82            [24] 2562 	mov	dpl, r7
      000BC2 8E 83            [24] 2563 	mov	dph, r6
      000BC4 8D F0            [24] 2564 	mov	b, r5
      000BC6 EC               [12] 2565 	mov	a, r4
      000BC7 12 1E 0D         [24] 2566 	lcall	___fslt
      000BCA E5 81            [12] 2567 	mov	a,sp
      000BCC 24 FC            [12] 2568 	add	a,#0xfc
      000BCE F5 81            [12] 2569 	mov	sp,a
      000BD0 D0 04            [24] 2570 	pop	ar4
      000BD2 D0 05            [24] 2571 	pop	ar5
      000BD4 D0 06            [24] 2572 	pop	ar6
      000BD6 D0 07            [24] 2573 	pop	ar7
      000BD8 E5 82            [12] 2574 	mov	a, dpl
      000BDA 24 FF            [12] 2575 	add	a,#0xff
      000BDC 92 00            [24] 2576 	mov	b0,c
      000BDE 50 44            [24] 2577 	jnc	00108$
      000BE0 C0 07            [24] 2578 	push	ar7
      000BE2 C0 06            [24] 2579 	push	ar6
      000BE4 C0 05            [24] 2580 	push	ar5
      000BE6 C0 04            [24] 2581 	push	ar4
      000BE8 E5 1D            [12] 2582 	mov	a,_bp
      000BEA 24 F2            [12] 2583 	add	a,#0xf2
      000BEC F8               [12] 2584 	mov	r0,a
      000BED E6               [12] 2585 	mov	a,@r0
      000BEE C0 E0            [24] 2586 	push	acc
      000BF0 08               [12] 2587 	inc	r0
      000BF1 E6               [12] 2588 	mov	a,@r0
      000BF2 C0 E0            [24] 2589 	push	acc
      000BF4 08               [12] 2590 	inc	r0
      000BF5 E6               [12] 2591 	mov	a,@r0
      000BF6 C0 E0            [24] 2592 	push	acc
      000BF8 08               [12] 2593 	inc	r0
      000BF9 E6               [12] 2594 	mov	a,@r0
      000BFA C0 E0            [24] 2595 	push	acc
      000BFC E5 1D            [12] 2596 	mov	a,_bp
      000BFE 24 EE            [12] 2597 	add	a,#0xee
      000C00 F8               [12] 2598 	mov	r0,a
      000C01 86 82            [24] 2599 	mov	dpl, @r0
      000C03 08               [12] 2600 	inc	r0
      000C04 86 83            [24] 2601 	mov	dph, @r0
      000C06 08               [12] 2602 	inc	r0
      000C07 86 F0            [24] 2603 	mov	b, @r0
      000C09 08               [12] 2604 	inc	r0
      000C0A E6               [12] 2605 	mov	a, @r0
      000C0B 12 1E 0D         [24] 2606 	lcall	___fslt
      000C0E E5 81            [12] 2607 	mov	a,sp
      000C10 24 FC            [12] 2608 	add	a,#0xfc
      000C12 F5 81            [12] 2609 	mov	sp,a
      000C14 D0 04            [24] 2610 	pop	ar4
      000C16 D0 05            [24] 2611 	pop	ar5
      000C18 D0 06            [24] 2612 	pop	ar6
      000C1A D0 07            [24] 2613 	pop	ar7
      000C1C E5 82            [12] 2614 	mov	a, dpl
      000C1E 24 FF            [12] 2615 	add	a,#0xff
      000C20 92 00            [24] 2616 	mov	b0,c
      000C22 40 0E            [24] 2617 	jc	00109$
      000C24                       2618 00108$:
                           000B6D  2619 	C$fuzzy.h$250$2_0$71 ==.
                                   2620 ;	../../fuzzy.h:250: result = 0.0f;
      000C24 A8 1D            [24] 2621 	mov	r0,_bp
      000C26 08               [12] 2622 	inc	r0
      000C27 E4               [12] 2623 	clr	a
      000C28 F6               [12] 2624 	mov	@r0,a
      000C29 08               [12] 2625 	inc	r0
      000C2A F6               [12] 2626 	mov	@r0,a
      000C2B 08               [12] 2627 	inc	r0
      000C2C F6               [12] 2628 	mov	@r0,a
      000C2D 08               [12] 2629 	inc	r0
      000C2E F6               [12] 2630 	mov	@r0,a
      000C2F 02 0E 31         [24] 2631 	ljmp	00110$
      000C32                       2632 00109$:
                           000B7B  2633 	C$fuzzy.h$252$1_0$70 ==.
                                   2634 ;	../../fuzzy.h:252: else if (x >= b && x <= c) {
      000C32 C0 07            [24] 2635 	push	ar7
      000C34 C0 06            [24] 2636 	push	ar6
      000C36 C0 05            [24] 2637 	push	ar5
      000C38 C0 04            [24] 2638 	push	ar4
      000C3A E5 1D            [12] 2639 	mov	a,_bp
      000C3C 24 FA            [12] 2640 	add	a,#0xfa
      000C3E F8               [12] 2641 	mov	r0,a
      000C3F E6               [12] 2642 	mov	a,@r0
      000C40 C0 E0            [24] 2643 	push	acc
      000C42 08               [12] 2644 	inc	r0
      000C43 E6               [12] 2645 	mov	a,@r0
      000C44 C0 E0            [24] 2646 	push	acc
      000C46 08               [12] 2647 	inc	r0
      000C47 E6               [12] 2648 	mov	a,@r0
      000C48 C0 E0            [24] 2649 	push	acc
      000C4A 08               [12] 2650 	inc	r0
      000C4B E6               [12] 2651 	mov	a,@r0
      000C4C C0 E0            [24] 2652 	push	acc
      000C4E E5 1D            [12] 2653 	mov	a,_bp
      000C50 24 EE            [12] 2654 	add	a,#0xee
      000C52 F8               [12] 2655 	mov	r0,a
      000C53 86 82            [24] 2656 	mov	dpl, @r0
      000C55 08               [12] 2657 	inc	r0
      000C56 86 83            [24] 2658 	mov	dph, @r0
      000C58 08               [12] 2659 	inc	r0
      000C59 86 F0            [24] 2660 	mov	b, @r0
      000C5B 08               [12] 2661 	inc	r0
      000C5C E6               [12] 2662 	mov	a, @r0
      000C5D 12 1E 0D         [24] 2663 	lcall	___fslt
      000C60 E5 81            [12] 2664 	mov	a,sp
      000C62 24 FC            [12] 2665 	add	a,#0xfc
      000C64 F5 81            [12] 2666 	mov	sp,a
      000C66 D0 04            [24] 2667 	pop	ar4
      000C68 D0 05            [24] 2668 	pop	ar5
      000C6A D0 06            [24] 2669 	pop	ar6
      000C6C D0 07            [24] 2670 	pop	ar7
      000C6E E5 82            [12] 2671 	mov	a, dpl
      000C70 24 FF            [12] 2672 	add	a,#0xff
      000C72 92 00            [24] 2673 	mov	b0,c
      000C74 40 54            [24] 2674 	jc	00105$
      000C76 C0 07            [24] 2675 	push	ar7
      000C78 C0 06            [24] 2676 	push	ar6
      000C7A C0 05            [24] 2677 	push	ar5
      000C7C C0 04            [24] 2678 	push	ar4
      000C7E E5 1D            [12] 2679 	mov	a,_bp
      000C80 24 EE            [12] 2680 	add	a,#0xee
      000C82 F8               [12] 2681 	mov	r0,a
      000C83 E6               [12] 2682 	mov	a,@r0
      000C84 C0 E0            [24] 2683 	push	acc
      000C86 08               [12] 2684 	inc	r0
      000C87 E6               [12] 2685 	mov	a,@r0
      000C88 C0 E0            [24] 2686 	push	acc
      000C8A 08               [12] 2687 	inc	r0
      000C8B E6               [12] 2688 	mov	a,@r0
      000C8C C0 E0            [24] 2689 	push	acc
      000C8E 08               [12] 2690 	inc	r0
      000C8F E6               [12] 2691 	mov	a,@r0
      000C90 C0 E0            [24] 2692 	push	acc
      000C92 E5 1D            [12] 2693 	mov	a,_bp
      000C94 24 F6            [12] 2694 	add	a,#0xf6
      000C96 F8               [12] 2695 	mov	r0,a
      000C97 86 82            [24] 2696 	mov	dpl, @r0
      000C99 08               [12] 2697 	inc	r0
      000C9A 86 83            [24] 2698 	mov	dph, @r0
      000C9C 08               [12] 2699 	inc	r0
      000C9D 86 F0            [24] 2700 	mov	b, @r0
      000C9F 08               [12] 2701 	inc	r0
      000CA0 E6               [12] 2702 	mov	a, @r0
      000CA1 12 1E 0D         [24] 2703 	lcall	___fslt
      000CA4 E5 81            [12] 2704 	mov	a,sp
      000CA6 24 FC            [12] 2705 	add	a,#0xfc
      000CA8 F5 81            [12] 2706 	mov	sp,a
      000CAA D0 04            [24] 2707 	pop	ar4
      000CAC D0 05            [24] 2708 	pop	ar5
      000CAE D0 06            [24] 2709 	pop	ar6
      000CB0 D0 07            [24] 2710 	pop	ar7
      000CB2 E5 82            [12] 2711 	mov	a, dpl
      000CB4 24 FF            [12] 2712 	add	a,#0xff
      000CB6 92 00            [24] 2713 	mov	b0,c
      000CB8 40 10            [24] 2714 	jc	00105$
                           000C03  2715 	C$fuzzy.h$253$2_0$72 ==.
                                   2716 ;	../../fuzzy.h:253: result = 1.0f;
      000CBA A8 1D            [24] 2717 	mov	r0,_bp
      000CBC 08               [12] 2718 	inc	r0
      000CBD E4               [12] 2719 	clr	a
      000CBE F6               [12] 2720 	mov	@r0,a
      000CBF 08               [12] 2721 	inc	r0
      000CC0 F6               [12] 2722 	mov	@r0,a
      000CC1 08               [12] 2723 	inc	r0
      000CC2 76 80            [12] 2724 	mov	@r0,#0x80
      000CC4 08               [12] 2725 	inc	r0
      000CC5 76 3F            [12] 2726 	mov	@r0,#0x3f
      000CC7 02 0E 31         [24] 2727 	ljmp	00110$
      000CCA                       2728 00105$:
                           000C13  2729 	C$fuzzy.h$255$1_0$70 ==.
                                   2730 ;	../../fuzzy.h:255: else if (x < b) {
      000CCA C0 07            [24] 2731 	push	ar7
      000CCC C0 06            [24] 2732 	push	ar6
      000CCE C0 05            [24] 2733 	push	ar5
      000CD0 C0 04            [24] 2734 	push	ar4
      000CD2 E5 1D            [12] 2735 	mov	a,_bp
      000CD4 24 FA            [12] 2736 	add	a,#0xfa
      000CD6 F8               [12] 2737 	mov	r0,a
      000CD7 E6               [12] 2738 	mov	a,@r0
      000CD8 C0 E0            [24] 2739 	push	acc
      000CDA 08               [12] 2740 	inc	r0
      000CDB E6               [12] 2741 	mov	a,@r0
      000CDC C0 E0            [24] 2742 	push	acc
      000CDE 08               [12] 2743 	inc	r0
      000CDF E6               [12] 2744 	mov	a,@r0
      000CE0 C0 E0            [24] 2745 	push	acc
      000CE2 08               [12] 2746 	inc	r0
      000CE3 E6               [12] 2747 	mov	a,@r0
      000CE4 C0 E0            [24] 2748 	push	acc
      000CE6 E5 1D            [12] 2749 	mov	a,_bp
      000CE8 24 EE            [12] 2750 	add	a,#0xee
      000CEA F8               [12] 2751 	mov	r0,a
      000CEB 86 82            [24] 2752 	mov	dpl, @r0
      000CED 08               [12] 2753 	inc	r0
      000CEE 86 83            [24] 2754 	mov	dph, @r0
      000CF0 08               [12] 2755 	inc	r0
      000CF1 86 F0            [24] 2756 	mov	b, @r0
      000CF3 08               [12] 2757 	inc	r0
      000CF4 E6               [12] 2758 	mov	a, @r0
      000CF5 12 1E 0D         [24] 2759 	lcall	___fslt
      000CF8 AB 82            [24] 2760 	mov	r3, dpl
      000CFA E5 81            [12] 2761 	mov	a,sp
      000CFC 24 FC            [12] 2762 	add	a,#0xfc
      000CFE F5 81            [12] 2763 	mov	sp,a
      000D00 D0 04            [24] 2764 	pop	ar4
      000D02 D0 05            [24] 2765 	pop	ar5
      000D04 D0 06            [24] 2766 	pop	ar6
      000D06 D0 07            [24] 2767 	pop	ar7
      000D08 EB               [12] 2768 	mov	a,r3
      000D09 70 03            [24] 2769 	jnz	00166$
      000D0B 02 0D 95         [24] 2770 	ljmp	00102$
      000D0E                       2771 00166$:
                           000C57  2772 	C$fuzzy.h$256$1_0$70 ==.
                                   2773 ;	../../fuzzy.h:256: result = (x - a) / (b - a);
      000D0E C0 07            [24] 2774 	push	ar7
      000D10 C0 06            [24] 2775 	push	ar6
      000D12 C0 05            [24] 2776 	push	ar5
      000D14 C0 04            [24] 2777 	push	ar4
      000D16 C0 07            [24] 2778 	push	ar7
      000D18 C0 06            [24] 2779 	push	ar6
      000D1A C0 05            [24] 2780 	push	ar5
      000D1C C0 04            [24] 2781 	push	ar4
      000D1E E5 1D            [12] 2782 	mov	a,_bp
      000D20 24 EE            [12] 2783 	add	a,#0xee
      000D22 F8               [12] 2784 	mov	r0,a
      000D23 86 82            [24] 2785 	mov	dpl, @r0
      000D25 08               [12] 2786 	inc	r0
      000D26 86 83            [24] 2787 	mov	dph, @r0
      000D28 08               [12] 2788 	inc	r0
      000D29 86 F0            [24] 2789 	mov	b, @r0
      000D2B 08               [12] 2790 	inc	r0
      000D2C E6               [12] 2791 	mov	a, @r0
      000D2D 12 1C D2         [24] 2792 	lcall	___fssub
      000D30 C8               [12] 2793 	xch	a,r0
      000D31 E5 1D            [12] 2794 	mov	a,_bp
      000D33 24 05            [12] 2795 	add	a,#0x05
      000D35 C8               [12] 2796 	xch	a,r0
      000D36 A6 82            [24] 2797 	mov	@r0, dpl
      000D38 08               [12] 2798 	inc	r0
      000D39 A6 83            [24] 2799 	mov	@r0, dph
      000D3B 08               [12] 2800 	inc	r0
      000D3C A6 F0            [24] 2801 	mov	@r0, b
      000D3E 08               [12] 2802 	inc	r0
      000D3F F6               [12] 2803 	mov	@r0,a
      000D40 E5 81            [12] 2804 	mov	a,sp
      000D42 24 FC            [12] 2805 	add	a,#0xfc
      000D44 F5 81            [12] 2806 	mov	sp,a
      000D46 E5 1D            [12] 2807 	mov	a,_bp
      000D48 24 FA            [12] 2808 	add	a,#0xfa
      000D4A F8               [12] 2809 	mov	r0,a
      000D4B 86 82            [24] 2810 	mov	dpl, @r0
      000D4D 08               [12] 2811 	inc	r0
      000D4E 86 83            [24] 2812 	mov	dph, @r0
      000D50 08               [12] 2813 	inc	r0
      000D51 86 F0            [24] 2814 	mov	b, @r0
      000D53 08               [12] 2815 	inc	r0
      000D54 E6               [12] 2816 	mov	a, @r0
      000D55 12 1C D2         [24] 2817 	lcall	___fssub
      000D58 AC 82            [24] 2818 	mov	r4, dpl
      000D5A AD 83            [24] 2819 	mov	r5, dph
      000D5C AE F0            [24] 2820 	mov	r6, b
      000D5E FF               [12] 2821 	mov	r7, a
      000D5F E5 81            [12] 2822 	mov	a,sp
      000D61 24 FC            [12] 2823 	add	a,#0xfc
      000D63 F5 81            [12] 2824 	mov	sp,a
      000D65 C0 04            [24] 2825 	push	ar4
      000D67 C0 05            [24] 2826 	push	ar5
      000D69 C0 06            [24] 2827 	push	ar6
      000D6B C0 07            [24] 2828 	push	ar7
      000D6D E5 1D            [12] 2829 	mov	a,_bp
      000D6F 24 05            [12] 2830 	add	a,#0x05
      000D71 F8               [12] 2831 	mov	r0,a
      000D72 86 82            [24] 2832 	mov	dpl, @r0
      000D74 08               [12] 2833 	inc	r0
      000D75 86 83            [24] 2834 	mov	dph, @r0
      000D77 08               [12] 2835 	inc	r0
      000D78 86 F0            [24] 2836 	mov	b, @r0
      000D7A 08               [12] 2837 	inc	r0
      000D7B E6               [12] 2838 	mov	a, @r0
      000D7C 12 1F 54         [24] 2839 	lcall	___fsdiv
      000D7F A8 1D            [24] 2840 	mov	r0,_bp
      000D81 08               [12] 2841 	inc	r0
      000D82 A6 82            [24] 2842 	mov	@r0, dpl
      000D84 08               [12] 2843 	inc	r0
      000D85 A6 83            [24] 2844 	mov	@r0, dph
      000D87 08               [12] 2845 	inc	r0
      000D88 A6 F0            [24] 2846 	mov	@r0, b
      000D8A 08               [12] 2847 	inc	r0
      000D8B F6               [12] 2848 	mov	@r0,a
      000D8C E5 81            [12] 2849 	mov	a,sp
      000D8E 24 FC            [12] 2850 	add	a,#0xfc
      000D90 F5 81            [12] 2851 	mov	sp,a
      000D92 02 0E 31         [24] 2852 	ljmp	00110$
      000D95                       2853 00102$:
                           000CDE  2854 	C$fuzzy.h$259$1_0$70 ==.
                                   2855 ;	../../fuzzy.h:259: result = (d - x) / (d - c);
      000D95 E5 1D            [12] 2856 	mov	a,_bp
      000D97 24 EE            [12] 2857 	add	a,#0xee
      000D99 F8               [12] 2858 	mov	r0,a
      000D9A E6               [12] 2859 	mov	a,@r0
      000D9B C0 E0            [24] 2860 	push	acc
      000D9D 08               [12] 2861 	inc	r0
      000D9E E6               [12] 2862 	mov	a,@r0
      000D9F C0 E0            [24] 2863 	push	acc
      000DA1 08               [12] 2864 	inc	r0
      000DA2 E6               [12] 2865 	mov	a,@r0
      000DA3 C0 E0            [24] 2866 	push	acc
      000DA5 08               [12] 2867 	inc	r0
      000DA6 E6               [12] 2868 	mov	a,@r0
      000DA7 C0 E0            [24] 2869 	push	acc
      000DA9 E5 1D            [12] 2870 	mov	a,_bp
      000DAB 24 F2            [12] 2871 	add	a,#0xf2
      000DAD F8               [12] 2872 	mov	r0,a
      000DAE 86 82            [24] 2873 	mov	dpl, @r0
      000DB0 08               [12] 2874 	inc	r0
      000DB1 86 83            [24] 2875 	mov	dph, @r0
      000DB3 08               [12] 2876 	inc	r0
      000DB4 86 F0            [24] 2877 	mov	b, @r0
      000DB6 08               [12] 2878 	inc	r0
      000DB7 E6               [12] 2879 	mov	a, @r0
      000DB8 12 1C D2         [24] 2880 	lcall	___fssub
      000DBB C8               [12] 2881 	xch	a,r0
      000DBC E5 1D            [12] 2882 	mov	a,_bp
      000DBE 24 05            [12] 2883 	add	a,#0x05
      000DC0 C8               [12] 2884 	xch	a,r0
      000DC1 A6 82            [24] 2885 	mov	@r0, dpl
      000DC3 08               [12] 2886 	inc	r0
      000DC4 A6 83            [24] 2887 	mov	@r0, dph
      000DC6 08               [12] 2888 	inc	r0
      000DC7 A6 F0            [24] 2889 	mov	@r0, b
      000DC9 08               [12] 2890 	inc	r0
      000DCA F6               [12] 2891 	mov	@r0,a
      000DCB E5 81            [12] 2892 	mov	a,sp
      000DCD 24 FC            [12] 2893 	add	a,#0xfc
      000DCF F5 81            [12] 2894 	mov	sp,a
      000DD1 E5 1D            [12] 2895 	mov	a,_bp
      000DD3 24 F6            [12] 2896 	add	a,#0xf6
      000DD5 F8               [12] 2897 	mov	r0,a
      000DD6 E6               [12] 2898 	mov	a,@r0
      000DD7 C0 E0            [24] 2899 	push	acc
      000DD9 08               [12] 2900 	inc	r0
      000DDA E6               [12] 2901 	mov	a,@r0
      000DDB C0 E0            [24] 2902 	push	acc
      000DDD 08               [12] 2903 	inc	r0
      000DDE E6               [12] 2904 	mov	a,@r0
      000DDF C0 E0            [24] 2905 	push	acc
      000DE1 08               [12] 2906 	inc	r0
      000DE2 E6               [12] 2907 	mov	a,@r0
      000DE3 C0 E0            [24] 2908 	push	acc
      000DE5 E5 1D            [12] 2909 	mov	a,_bp
      000DE7 24 F2            [12] 2910 	add	a,#0xf2
      000DE9 F8               [12] 2911 	mov	r0,a
      000DEA 86 82            [24] 2912 	mov	dpl, @r0
      000DEC 08               [12] 2913 	inc	r0
      000DED 86 83            [24] 2914 	mov	dph, @r0
      000DEF 08               [12] 2915 	inc	r0
      000DF0 86 F0            [24] 2916 	mov	b, @r0
      000DF2 08               [12] 2917 	inc	r0
      000DF3 E6               [12] 2918 	mov	a, @r0
      000DF4 12 1C D2         [24] 2919 	lcall	___fssub
      000DF7 AA 82            [24] 2920 	mov	r2, dpl
      000DF9 AB 83            [24] 2921 	mov	r3, dph
      000DFB AE F0            [24] 2922 	mov	r6, b
      000DFD FF               [12] 2923 	mov	r7, a
      000DFE E5 81            [12] 2924 	mov	a,sp
      000E00 24 FC            [12] 2925 	add	a,#0xfc
      000E02 F5 81            [12] 2926 	mov	sp,a
      000E04 C0 02            [24] 2927 	push	ar2
      000E06 C0 03            [24] 2928 	push	ar3
      000E08 C0 06            [24] 2929 	push	ar6
      000E0A C0 07            [24] 2930 	push	ar7
      000E0C E5 1D            [12] 2931 	mov	a,_bp
      000E0E 24 05            [12] 2932 	add	a,#0x05
      000E10 F8               [12] 2933 	mov	r0,a
      000E11 86 82            [24] 2934 	mov	dpl, @r0
      000E13 08               [12] 2935 	inc	r0
      000E14 86 83            [24] 2936 	mov	dph, @r0
      000E16 08               [12] 2937 	inc	r0
      000E17 86 F0            [24] 2938 	mov	b, @r0
      000E19 08               [12] 2939 	inc	r0
      000E1A E6               [12] 2940 	mov	a, @r0
      000E1B 12 1F 54         [24] 2941 	lcall	___fsdiv
      000E1E A8 1D            [24] 2942 	mov	r0,_bp
      000E20 08               [12] 2943 	inc	r0
      000E21 A6 82            [24] 2944 	mov	@r0, dpl
      000E23 08               [12] 2945 	inc	r0
      000E24 A6 83            [24] 2946 	mov	@r0, dph
      000E26 08               [12] 2947 	inc	r0
      000E27 A6 F0            [24] 2948 	mov	@r0, b
      000E29 08               [12] 2949 	inc	r0
      000E2A F6               [12] 2950 	mov	@r0,a
      000E2B E5 81            [12] 2951 	mov	a,sp
      000E2D 24 FC            [12] 2952 	add	a,#0xfc
      000E2F F5 81            [12] 2953 	mov	sp,a
      000E31                       2954 00110$:
                           000D7A  2955 	C$fuzzy.h$262$1_0$70 ==.
                                   2956 ;	../../fuzzy.h:262: return fuzzy_8051_hedge(result, hedge);
      000E31 E5 1D            [12] 2957 	mov	a,_bp
      000E33 24 ED            [12] 2958 	add	a,#0xed
      000E35 F8               [12] 2959 	mov	r0,a
      000E36 E6               [12] 2960 	mov	a,@r0
      000E37 C0 E0            [24] 2961 	push	acc
      000E39 A8 1D            [24] 2962 	mov	r0,_bp
      000E3B 08               [12] 2963 	inc	r0
      000E3C 86 82            [24] 2964 	mov	dpl, @r0
      000E3E 08               [12] 2965 	inc	r0
      000E3F 86 83            [24] 2966 	mov	dph, @r0
      000E41 08               [12] 2967 	inc	r0
      000E42 86 F0            [24] 2968 	mov	b, @r0
      000E44 08               [12] 2969 	inc	r0
      000E45 E6               [12] 2970 	mov	a, @r0
      000E46 12 04 F4         [24] 2971 	lcall	_fuzzy_8051_hedge
      000E49 AC 82            [24] 2972 	mov	r4, dpl
      000E4B AD 83            [24] 2973 	mov	r5, dph
      000E4D AE F0            [24] 2974 	mov	r6, b
      000E4F FF               [12] 2975 	mov	r7, a
      000E50 15 81            [12] 2976 	dec	sp
      000E52 8C 82            [24] 2977 	mov	dpl, r4
      000E54 8D 83            [24] 2978 	mov	dph, r5
      000E56 8E F0            [24] 2979 	mov	b, r6
      000E58 EF               [12] 2980 	mov	a, r7
                           000DA2  2981 	C$fuzzy.h$263$1_0$70 ==.
                                   2982 ;	../../fuzzy.h:263: }
      000E59 85 1D 81         [24] 2983 	mov	sp,_bp
      000E5C D0 1D            [24] 2984 	pop	_bp
                           000DA7  2985 	C$fuzzy.h$263$1_0$70 ==.
                           000DA7  2986 	XG$fuzzy_trapezoid$0$0 ==.
      000E5E 22               [24] 2987 	ret
                                   2988 ;------------------------------------------------------------
                                   2989 ;Allocation info for local variables in function 'fuzzy_8051_eval'
                                   2990 ;------------------------------------------------------------
                                   2991 ;value         Allocated to stack - _bp -6 +4 
                                   2992 ;variable      Allocated to stack - _bp +1 +3 
                                   2993 ;sloc0         Allocated to stack - _bp +4 +1 
                                   2994 ;sloc1         Allocated to stack - _bp +5 +1 
                                   2995 ;sloc2         Allocated to stack - _bp +5 +4 
                                   2996 ;sloc3         Allocated to stack - _bp +9 +4 
                                   2997 ;sloc4         Allocated to stack - _bp +13 +4 
                                   2998 ;sloc5         Allocated to stack - _bp +17 +4 
                                   2999 ;------------------------------------------------------------
                           000DA8  3000 	Fcontroller_8051$fuzzy_8051_eval$0$0 ==.
                           000DA8  3001 	C$fuzzy.h$265$1_0$76 ==.
                                   3002 ;	../../fuzzy.h:265: static float fuzzy_8051_eval(const fuzzy_variable_8051_t *variable, float value)
                                   3003 ;	-----------------------------------------
                                   3004 ;	 function fuzzy_8051_eval
                                   3005 ;	-----------------------------------------
      000E5F                       3006 _fuzzy_8051_eval:
      000E5F C0 1D            [24] 3007 	push	_bp
      000E61 85 81 1D         [24] 3008 	mov	_bp,sp
      000E64 C0 82            [24] 3009 	push	dpl
      000E66 C0 83            [24] 3010 	push	dph
      000E68 C0 F0            [24] 3011 	push	b
      000E6A E5 81            [12] 3012 	mov	a,sp
      000E6C 24 11            [12] 3013 	add	a,#0x11
      000E6E F5 81            [12] 3014 	mov	sp,a
                           000DB9  3015 	C$fuzzy.h$267$1_0$76 ==.
                                   3016 ;	../../fuzzy.h:267: if (variable->shape == FUZZY_SHAPE_RAMP) {
      000E70 A8 1D            [24] 3017 	mov	r0,_bp
      000E72 08               [12] 3018 	inc	r0
      000E73 86 02            [24] 3019 	mov	ar2,@r0
      000E75 08               [12] 3020 	inc	r0
      000E76 86 03            [24] 3021 	mov	ar3,@r0
      000E78 08               [12] 3022 	inc	r0
      000E79 86 04            [24] 3023 	mov	ar4,@r0
      000E7B 8A 82            [24] 3024 	mov	dpl,r2
      000E7D 8B 83            [24] 3025 	mov	dph,r3
      000E7F 8C F0            [24] 3026 	mov	b,r4
      000E81 12 20 17         [24] 3027 	lcall	__gptrget
      000E84 FC               [12] 3028 	mov	r4,a
      000E85 60 03            [24] 3029 	jz	00127$
      000E87 02 0F 8F         [24] 3030 	ljmp	00102$
      000E8A                       3031 00127$:
                           000DD3  3032 	C$fuzzy.h$268$2_0$77 ==.
                                   3033 ;	../../fuzzy.h:268: return fuzzy_ramp(variable->parameters[0], variable->parameters[1], value, variable->parameters[2] != 0.0f, variable->hedge);
      000E8A A8 1D            [24] 3034 	mov	r0,_bp
      000E8C 08               [12] 3035 	inc	r0
      000E8D 74 01            [12] 3036 	mov	a,#0x01
      000E8F 26               [12] 3037 	add	a, @r0
      000E90 FA               [12] 3038 	mov	r2,a
      000E91 E4               [12] 3039 	clr	a
      000E92 08               [12] 3040 	inc	r0
      000E93 36               [12] 3041 	addc	a, @r0
      000E94 FB               [12] 3042 	mov	r3,a
      000E95 08               [12] 3043 	inc	r0
      000E96 86 07            [24] 3044 	mov	ar7,@r0
      000E98 8A 82            [24] 3045 	mov	dpl,r2
      000E9A 8B 83            [24] 3046 	mov	dph,r3
      000E9C 8F F0            [24] 3047 	mov	b,r7
      000E9E 12 20 17         [24] 3048 	lcall	__gptrget
      000EA1 FC               [12] 3049 	mov	r4,a
      000EA2 A8 1D            [24] 3050 	mov	r0,_bp
      000EA4 08               [12] 3051 	inc	r0
      000EA5 74 0A            [12] 3052 	mov	a,#0x0a
      000EA7 26               [12] 3053 	add	a, @r0
      000EA8 FD               [12] 3054 	mov	r5,a
      000EA9 E4               [12] 3055 	clr	a
      000EAA 08               [12] 3056 	inc	r0
      000EAB 36               [12] 3057 	addc	a, @r0
      000EAC FE               [12] 3058 	mov	r6,a
      000EAD 08               [12] 3059 	inc	r0
      000EAE 86 07            [24] 3060 	mov	ar7,@r0
      000EB0 8D 82            [24] 3061 	mov	dpl,r5
      000EB2 8E 83            [24] 3062 	mov	dph,r6
      000EB4 8F F0            [24] 3063 	mov	b,r7
      000EB6 12 20 17         [24] 3064 	lcall	__gptrget
      000EB9 FD               [12] 3065 	mov	r5,a
      000EBA A3               [24] 3066 	inc	dptr
      000EBB 12 20 17         [24] 3067 	lcall	__gptrget
      000EBE FE               [12] 3068 	mov	r6,a
      000EBF A3               [24] 3069 	inc	dptr
      000EC0 12 20 17         [24] 3070 	lcall	__gptrget
      000EC3 FF               [12] 3071 	mov	r7,a
      000EC4 A3               [24] 3072 	inc	dptr
      000EC5 12 20 17         [24] 3073 	lcall	__gptrget
      000EC8 FB               [12] 3074 	mov	r3,a
      000EC9 8D F0            [24] 3075 	mov	b,r5
      000ECB EE               [12] 3076 	mov	a,r6
      000ECC 42 F0            [12] 3077 	orl	b,a
      000ECE EF               [12] 3078 	mov	a,r7
      000ECF 42 F0            [12] 3079 	orl	b,a
      000ED1 EB               [12] 3080 	mov	a,r3
      000ED2 54 7F            [12] 3081 	anl	a,#0x7F
      000ED4 45 F0            [12] 3082 	orl	a,b
      000ED6 B4 01 00         [24] 3083 	cjne	a,#0x01,00128$
      000ED9                       3084 00128$:
      000ED9 B3               [12] 3085 	cpl	c
      000EDA 92 00            [24] 3086 	mov	b0,c
      000EDC E5 1D            [12] 3087 	mov	a,_bp
      000EDE 24 04            [12] 3088 	add	a,#0x04
      000EE0 F8               [12] 3089 	mov	r0,a
      000EE1 A2 00            [12] 3090 	mov	c,b0
      000EE3 E4               [12] 3091 	clr	a
      000EE4 33               [12] 3092 	rlc	a
      000EE5 F6               [12] 3093 	mov	@r0,a
      000EE6 A8 1D            [24] 3094 	mov	r0,_bp
      000EE8 08               [12] 3095 	inc	r0
      000EE9 74 06            [12] 3096 	mov	a,#0x06
      000EEB 26               [12] 3097 	add	a, @r0
      000EEC FB               [12] 3098 	mov	r3,a
      000EED E4               [12] 3099 	clr	a
      000EEE 08               [12] 3100 	inc	r0
      000EEF 36               [12] 3101 	addc	a, @r0
      000EF0 FD               [12] 3102 	mov	r5,a
      000EF1 08               [12] 3103 	inc	r0
      000EF2 86 06            [24] 3104 	mov	ar6,@r0
      000EF4 8B 82            [24] 3105 	mov	dpl,r3
      000EF6 8D 83            [24] 3106 	mov	dph,r5
      000EF8 8E F0            [24] 3107 	mov	b,r6
      000EFA E5 1D            [12] 3108 	mov	a,_bp
      000EFC 24 05            [12] 3109 	add	a,#0x05
      000EFE F8               [12] 3110 	mov	r0,a
      000EFF 12 20 17         [24] 3111 	lcall	__gptrget
      000F02 F6               [12] 3112 	mov	@r0,a
      000F03 A3               [24] 3113 	inc	dptr
      000F04 12 20 17         [24] 3114 	lcall	__gptrget
      000F07 08               [12] 3115 	inc	r0
      000F08 F6               [12] 3116 	mov	@r0,a
      000F09 A3               [24] 3117 	inc	dptr
      000F0A 12 20 17         [24] 3118 	lcall	__gptrget
      000F0D 08               [12] 3119 	inc	r0
      000F0E F6               [12] 3120 	mov	@r0,a
      000F0F A3               [24] 3121 	inc	dptr
      000F10 12 20 17         [24] 3122 	lcall	__gptrget
      000F13 08               [12] 3123 	inc	r0
      000F14 F6               [12] 3124 	mov	@r0,a
      000F15 A8 1D            [24] 3125 	mov	r0,_bp
      000F17 08               [12] 3126 	inc	r0
      000F18 74 02            [12] 3127 	mov	a,#0x02
      000F1A 26               [12] 3128 	add	a, @r0
      000F1B FA               [12] 3129 	mov	r2,a
      000F1C E4               [12] 3130 	clr	a
      000F1D 08               [12] 3131 	inc	r0
      000F1E 36               [12] 3132 	addc	a, @r0
      000F1F FE               [12] 3133 	mov	r6,a
      000F20 08               [12] 3134 	inc	r0
      000F21 86 07            [24] 3135 	mov	ar7,@r0
      000F23 8A 82            [24] 3136 	mov	dpl,r2
      000F25 8E 83            [24] 3137 	mov	dph,r6
      000F27 8F F0            [24] 3138 	mov	b,r7
      000F29 12 20 17         [24] 3139 	lcall	__gptrget
      000F2C FA               [12] 3140 	mov	r2,a
      000F2D A3               [24] 3141 	inc	dptr
      000F2E 12 20 17         [24] 3142 	lcall	__gptrget
      000F31 FE               [12] 3143 	mov	r6,a
      000F32 A3               [24] 3144 	inc	dptr
      000F33 12 20 17         [24] 3145 	lcall	__gptrget
      000F36 FF               [12] 3146 	mov	r7,a
      000F37 A3               [24] 3147 	inc	dptr
      000F38 12 20 17         [24] 3148 	lcall	__gptrget
      000F3B FD               [12] 3149 	mov	r5,a
      000F3C C0 04            [24] 3150 	push	ar4
      000F3E E5 1D            [12] 3151 	mov	a,_bp
      000F40 24 04            [12] 3152 	add	a,#0x04
      000F42 F8               [12] 3153 	mov	r0,a
      000F43 E6               [12] 3154 	mov	a,@r0
      000F44 C0 E0            [24] 3155 	push	acc
      000F46 E5 1D            [12] 3156 	mov	a,_bp
      000F48 24 FA            [12] 3157 	add	a,#0xfa
      000F4A F8               [12] 3158 	mov	r0,a
      000F4B E6               [12] 3159 	mov	a,@r0
      000F4C C0 E0            [24] 3160 	push	acc
      000F4E 08               [12] 3161 	inc	r0
      000F4F E6               [12] 3162 	mov	a,@r0
      000F50 C0 E0            [24] 3163 	push	acc
      000F52 08               [12] 3164 	inc	r0
      000F53 E6               [12] 3165 	mov	a,@r0
      000F54 C0 E0            [24] 3166 	push	acc
      000F56 08               [12] 3167 	inc	r0
      000F57 E6               [12] 3168 	mov	a,@r0
      000F58 C0 E0            [24] 3169 	push	acc
      000F5A E5 1D            [12] 3170 	mov	a,_bp
      000F5C 24 05            [12] 3171 	add	a,#0x05
      000F5E F8               [12] 3172 	mov	r0,a
      000F5F E6               [12] 3173 	mov	a,@r0
      000F60 C0 E0            [24] 3174 	push	acc
      000F62 08               [12] 3175 	inc	r0
      000F63 E6               [12] 3176 	mov	a,@r0
      000F64 C0 E0            [24] 3177 	push	acc
      000F66 08               [12] 3178 	inc	r0
      000F67 E6               [12] 3179 	mov	a,@r0
      000F68 C0 E0            [24] 3180 	push	acc
      000F6A 08               [12] 3181 	inc	r0
      000F6B E6               [12] 3182 	mov	a,@r0
      000F6C C0 E0            [24] 3183 	push	acc
      000F6E 8A 82            [24] 3184 	mov	dpl, r2
      000F70 8E 83            [24] 3185 	mov	dph, r6
      000F72 8F F0            [24] 3186 	mov	b, r7
      000F74 ED               [12] 3187 	mov	a, r5
      000F75 12 05 B0         [24] 3188 	lcall	_fuzzy_ramp
      000F78 AB 82            [24] 3189 	mov	r3, dpl
      000F7A AD 83            [24] 3190 	mov	r5, dph
      000F7C AE F0            [24] 3191 	mov	r6, b
      000F7E FF               [12] 3192 	mov	r7, a
      000F7F E5 81            [12] 3193 	mov	a,sp
      000F81 24 F6            [12] 3194 	add	a,#0xf6
      000F83 F5 81            [12] 3195 	mov	sp,a
      000F85 8B 82            [24] 3196 	mov	dpl, r3
      000F87 8D 83            [24] 3197 	mov	dph, r5
      000F89 8E F0            [24] 3198 	mov	b, r6
      000F8B EF               [12] 3199 	mov	a, r7
      000F8C 02 11 EA         [24] 3200 	ljmp	00107$
      000F8F                       3201 00102$:
                           000ED8  3202 	C$fuzzy.h$271$1_0$76 ==.
                                   3203 ;	../../fuzzy.h:271: if (variable->shape == FUZZY_SHAPE_TRIANGLE) {
      000F8F BC 01 02         [24] 3204 	cjne	r4,#0x01,00129$
      000F92 80 03            [24] 3205 	sjmp	00130$
      000F94                       3206 00129$:
      000F94 02 10 93         [24] 3207 	ljmp	00104$
      000F97                       3208 00130$:
                           000EE0  3209 	C$fuzzy.h$272$2_0$78 ==.
                                   3210 ;	../../fuzzy.h:272: return fuzzy_triangle(variable->parameters[0], variable->parameters[1], variable->parameters[2], value, variable->hedge);
      000F97 A8 1D            [24] 3211 	mov	r0,_bp
      000F99 08               [12] 3212 	inc	r0
      000F9A 74 01            [12] 3213 	mov	a,#0x01
      000F9C 26               [12] 3214 	add	a, @r0
      000F9D FD               [12] 3215 	mov	r5,a
      000F9E E4               [12] 3216 	clr	a
      000F9F 08               [12] 3217 	inc	r0
      000FA0 36               [12] 3218 	addc	a, @r0
      000FA1 FE               [12] 3219 	mov	r6,a
      000FA2 08               [12] 3220 	inc	r0
      000FA3 86 07            [24] 3221 	mov	ar7,@r0
      000FA5 8D 82            [24] 3222 	mov	dpl,r5
      000FA7 8E 83            [24] 3223 	mov	dph,r6
      000FA9 8F F0            [24] 3224 	mov	b,r7
      000FAB 12 20 17         [24] 3225 	lcall	__gptrget
      000FAE FC               [12] 3226 	mov	r4,a
      000FAF A8 1D            [24] 3227 	mov	r0,_bp
      000FB1 08               [12] 3228 	inc	r0
      000FB2 74 0A            [12] 3229 	mov	a,#0x0a
      000FB4 26               [12] 3230 	add	a, @r0
      000FB5 FB               [12] 3231 	mov	r3,a
      000FB6 E4               [12] 3232 	clr	a
      000FB7 08               [12] 3233 	inc	r0
      000FB8 36               [12] 3234 	addc	a, @r0
      000FB9 FE               [12] 3235 	mov	r6,a
      000FBA 08               [12] 3236 	inc	r0
      000FBB 86 07            [24] 3237 	mov	ar7,@r0
      000FBD 8B 82            [24] 3238 	mov	dpl,r3
      000FBF 8E 83            [24] 3239 	mov	dph,r6
      000FC1 8F F0            [24] 3240 	mov	b,r7
      000FC3 E5 1D            [12] 3241 	mov	a,_bp
      000FC5 24 09            [12] 3242 	add	a,#0x09
      000FC7 F8               [12] 3243 	mov	r0,a
      000FC8 12 20 17         [24] 3244 	lcall	__gptrget
      000FCB F6               [12] 3245 	mov	@r0,a
      000FCC A3               [24] 3246 	inc	dptr
      000FCD 12 20 17         [24] 3247 	lcall	__gptrget
      000FD0 08               [12] 3248 	inc	r0
      000FD1 F6               [12] 3249 	mov	@r0,a
      000FD2 A3               [24] 3250 	inc	dptr
      000FD3 12 20 17         [24] 3251 	lcall	__gptrget
      000FD6 08               [12] 3252 	inc	r0
      000FD7 F6               [12] 3253 	mov	@r0,a
      000FD8 A3               [24] 3254 	inc	dptr
      000FD9 12 20 17         [24] 3255 	lcall	__gptrget
      000FDC 08               [12] 3256 	inc	r0
      000FDD F6               [12] 3257 	mov	@r0,a
      000FDE A8 1D            [24] 3258 	mov	r0,_bp
      000FE0 08               [12] 3259 	inc	r0
      000FE1 74 06            [12] 3260 	mov	a,#0x06
      000FE3 26               [12] 3261 	add	a, @r0
      000FE4 FD               [12] 3262 	mov	r5,a
      000FE5 E4               [12] 3263 	clr	a
      000FE6 08               [12] 3264 	inc	r0
      000FE7 36               [12] 3265 	addc	a, @r0
      000FE8 FE               [12] 3266 	mov	r6,a
      000FE9 08               [12] 3267 	inc	r0
      000FEA 86 07            [24] 3268 	mov	ar7,@r0
      000FEC 8D 82            [24] 3269 	mov	dpl,r5
      000FEE 8E 83            [24] 3270 	mov	dph,r6
      000FF0 8F F0            [24] 3271 	mov	b,r7
      000FF2 E5 1D            [12] 3272 	mov	a,_bp
      000FF4 24 0D            [12] 3273 	add	a,#0x0d
      000FF6 F8               [12] 3274 	mov	r0,a
      000FF7 12 20 17         [24] 3275 	lcall	__gptrget
      000FFA F6               [12] 3276 	mov	@r0,a
      000FFB A3               [24] 3277 	inc	dptr
      000FFC 12 20 17         [24] 3278 	lcall	__gptrget
      000FFF 08               [12] 3279 	inc	r0
      001000 F6               [12] 3280 	mov	@r0,a
      001001 A3               [24] 3281 	inc	dptr
      001002 12 20 17         [24] 3282 	lcall	__gptrget
      001005 08               [12] 3283 	inc	r0
      001006 F6               [12] 3284 	mov	@r0,a
      001007 A3               [24] 3285 	inc	dptr
      001008 12 20 17         [24] 3286 	lcall	__gptrget
      00100B 08               [12] 3287 	inc	r0
      00100C F6               [12] 3288 	mov	@r0,a
      00100D A8 1D            [24] 3289 	mov	r0,_bp
      00100F 08               [12] 3290 	inc	r0
      001010 74 02            [12] 3291 	mov	a,#0x02
      001012 26               [12] 3292 	add	a, @r0
      001013 FA               [12] 3293 	mov	r2,a
      001014 E4               [12] 3294 	clr	a
      001015 08               [12] 3295 	inc	r0
      001016 36               [12] 3296 	addc	a, @r0
      001017 FE               [12] 3297 	mov	r6,a
      001018 08               [12] 3298 	inc	r0
      001019 86 07            [24] 3299 	mov	ar7,@r0
      00101B 8A 82            [24] 3300 	mov	dpl,r2
      00101D 8E 83            [24] 3301 	mov	dph,r6
      00101F 8F F0            [24] 3302 	mov	b,r7
      001021 12 20 17         [24] 3303 	lcall	__gptrget
      001024 FA               [12] 3304 	mov	r2,a
      001025 A3               [24] 3305 	inc	dptr
      001026 12 20 17         [24] 3306 	lcall	__gptrget
      001029 FE               [12] 3307 	mov	r6,a
      00102A A3               [24] 3308 	inc	dptr
      00102B 12 20 17         [24] 3309 	lcall	__gptrget
      00102E FF               [12] 3310 	mov	r7,a
      00102F A3               [24] 3311 	inc	dptr
      001030 12 20 17         [24] 3312 	lcall	__gptrget
      001033 FD               [12] 3313 	mov	r5,a
      001034 C0 04            [24] 3314 	push	ar4
      001036 E5 1D            [12] 3315 	mov	a,_bp
      001038 24 FA            [12] 3316 	add	a,#0xfa
      00103A F8               [12] 3317 	mov	r0,a
      00103B E6               [12] 3318 	mov	a,@r0
      00103C C0 E0            [24] 3319 	push	acc
      00103E 08               [12] 3320 	inc	r0
      00103F E6               [12] 3321 	mov	a,@r0
      001040 C0 E0            [24] 3322 	push	acc
      001042 08               [12] 3323 	inc	r0
      001043 E6               [12] 3324 	mov	a,@r0
      001044 C0 E0            [24] 3325 	push	acc
      001046 08               [12] 3326 	inc	r0
      001047 E6               [12] 3327 	mov	a,@r0
      001048 C0 E0            [24] 3328 	push	acc
      00104A E5 1D            [12] 3329 	mov	a,_bp
      00104C 24 09            [12] 3330 	add	a,#0x09
      00104E F8               [12] 3331 	mov	r0,a
      00104F E6               [12] 3332 	mov	a,@r0
      001050 C0 E0            [24] 3333 	push	acc
      001052 08               [12] 3334 	inc	r0
      001053 E6               [12] 3335 	mov	a,@r0
      001054 C0 E0            [24] 3336 	push	acc
      001056 08               [12] 3337 	inc	r0
      001057 E6               [12] 3338 	mov	a,@r0
      001058 C0 E0            [24] 3339 	push	acc
      00105A 08               [12] 3340 	inc	r0
      00105B E6               [12] 3341 	mov	a,@r0
      00105C C0 E0            [24] 3342 	push	acc
      00105E E5 1D            [12] 3343 	mov	a,_bp
      001060 24 0D            [12] 3344 	add	a,#0x0d
      001062 F8               [12] 3345 	mov	r0,a
      001063 E6               [12] 3346 	mov	a,@r0
      001064 C0 E0            [24] 3347 	push	acc
      001066 08               [12] 3348 	inc	r0
      001067 E6               [12] 3349 	mov	a,@r0
      001068 C0 E0            [24] 3350 	push	acc
      00106A 08               [12] 3351 	inc	r0
      00106B E6               [12] 3352 	mov	a,@r0
      00106C C0 E0            [24] 3353 	push	acc
      00106E 08               [12] 3354 	inc	r0
      00106F E6               [12] 3355 	mov	a,@r0
      001070 C0 E0            [24] 3356 	push	acc
      001072 8A 82            [24] 3357 	mov	dpl, r2
      001074 8E 83            [24] 3358 	mov	dph, r6
      001076 8F F0            [24] 3359 	mov	b, r7
      001078 ED               [12] 3360 	mov	a, r5
      001079 12 07 BC         [24] 3361 	lcall	_fuzzy_triangle
      00107C AB 82            [24] 3362 	mov	r3, dpl
      00107E AD 83            [24] 3363 	mov	r5, dph
      001080 AE F0            [24] 3364 	mov	r6, b
      001082 FF               [12] 3365 	mov	r7, a
      001083 E5 81            [12] 3366 	mov	a,sp
      001085 24 F3            [12] 3367 	add	a,#0xf3
      001087 F5 81            [12] 3368 	mov	sp,a
      001089 8B 82            [24] 3369 	mov	dpl, r3
      00108B 8D 83            [24] 3370 	mov	dph, r5
      00108D 8E F0            [24] 3371 	mov	b, r6
      00108F EF               [12] 3372 	mov	a, r7
      001090 02 11 EA         [24] 3373 	ljmp	00107$
      001093                       3374 00104$:
                           000FDC  3375 	C$fuzzy.h$275$1_0$76 ==.
                                   3376 ;	../../fuzzy.h:275: if (variable->shape == FUZZY_SHAPE_TRAPEZOID) {
      001093 BC 02 02         [24] 3377 	cjne	r4,#0x02,00131$
      001096 80 03            [24] 3378 	sjmp	00132$
      001098                       3379 00131$:
      001098 02 11 E4         [24] 3380 	ljmp	00106$
      00109B                       3381 00132$:
                           000FE4  3382 	C$fuzzy.h$276$2_0$79 ==.
                                   3383 ;	../../fuzzy.h:276: return fuzzy_trapezoid(variable->parameters[0], variable->parameters[1], variable->parameters[2], variable->parameters[3], value, variable->hedge);
      00109B A8 1D            [24] 3384 	mov	r0,_bp
      00109D 08               [12] 3385 	inc	r0
      00109E 74 01            [12] 3386 	mov	a,#0x01
      0010A0 26               [12] 3387 	add	a, @r0
      0010A1 FD               [12] 3388 	mov	r5,a
      0010A2 E4               [12] 3389 	clr	a
      0010A3 08               [12] 3390 	inc	r0
      0010A4 36               [12] 3391 	addc	a, @r0
      0010A5 FE               [12] 3392 	mov	r6,a
      0010A6 08               [12] 3393 	inc	r0
      0010A7 86 07            [24] 3394 	mov	ar7,@r0
      0010A9 8D 82            [24] 3395 	mov	dpl,r5
      0010AB 8E 83            [24] 3396 	mov	dph,r6
      0010AD 8F F0            [24] 3397 	mov	b,r7
      0010AF E5 1D            [12] 3398 	mov	a,_bp
      0010B1 24 0D            [12] 3399 	add	a,#0x0d
      0010B3 F8               [12] 3400 	mov	r0,a
      0010B4 12 20 17         [24] 3401 	lcall	__gptrget
      0010B7 F6               [12] 3402 	mov	@r0,a
      0010B8 A8 1D            [24] 3403 	mov	r0,_bp
      0010BA 08               [12] 3404 	inc	r0
      0010BB 74 0E            [12] 3405 	mov	a,#0x0e
      0010BD 26               [12] 3406 	add	a, @r0
      0010BE FC               [12] 3407 	mov	r4,a
      0010BF E4               [12] 3408 	clr	a
      0010C0 08               [12] 3409 	inc	r0
      0010C1 36               [12] 3410 	addc	a, @r0
      0010C2 FE               [12] 3411 	mov	r6,a
      0010C3 08               [12] 3412 	inc	r0
      0010C4 86 07            [24] 3413 	mov	ar7,@r0
      0010C6 8C 82            [24] 3414 	mov	dpl,r4
      0010C8 8E 83            [24] 3415 	mov	dph,r6
      0010CA 8F F0            [24] 3416 	mov	b,r7
      0010CC E5 1D            [12] 3417 	mov	a,_bp
      0010CE 24 09            [12] 3418 	add	a,#0x09
      0010D0 F8               [12] 3419 	mov	r0,a
      0010D1 12 20 17         [24] 3420 	lcall	__gptrget
      0010D4 F6               [12] 3421 	mov	@r0,a
      0010D5 A3               [24] 3422 	inc	dptr
      0010D6 12 20 17         [24] 3423 	lcall	__gptrget
      0010D9 08               [12] 3424 	inc	r0
      0010DA F6               [12] 3425 	mov	@r0,a
      0010DB A3               [24] 3426 	inc	dptr
      0010DC 12 20 17         [24] 3427 	lcall	__gptrget
      0010DF 08               [12] 3428 	inc	r0
      0010E0 F6               [12] 3429 	mov	@r0,a
      0010E1 A3               [24] 3430 	inc	dptr
      0010E2 12 20 17         [24] 3431 	lcall	__gptrget
      0010E5 08               [12] 3432 	inc	r0
      0010E6 F6               [12] 3433 	mov	@r0,a
      0010E7 A8 1D            [24] 3434 	mov	r0,_bp
      0010E9 08               [12] 3435 	inc	r0
      0010EA 74 0A            [12] 3436 	mov	a,#0x0a
      0010EC 26               [12] 3437 	add	a, @r0
      0010ED FA               [12] 3438 	mov	r2,a
      0010EE E4               [12] 3439 	clr	a
      0010EF 08               [12] 3440 	inc	r0
      0010F0 36               [12] 3441 	addc	a, @r0
      0010F1 FD               [12] 3442 	mov	r5,a
      0010F2 08               [12] 3443 	inc	r0
      0010F3 86 07            [24] 3444 	mov	ar7,@r0
      0010F5 8A 82            [24] 3445 	mov	dpl,r2
      0010F7 8D 83            [24] 3446 	mov	dph,r5
      0010F9 8F F0            [24] 3447 	mov	b,r7
      0010FB E5 1D            [12] 3448 	mov	a,_bp
      0010FD 24 05            [12] 3449 	add	a,#0x05
      0010FF F8               [12] 3450 	mov	r0,a
      001100 12 20 17         [24] 3451 	lcall	__gptrget
      001103 F6               [12] 3452 	mov	@r0,a
      001104 A3               [24] 3453 	inc	dptr
      001105 12 20 17         [24] 3454 	lcall	__gptrget
      001108 08               [12] 3455 	inc	r0
      001109 F6               [12] 3456 	mov	@r0,a
      00110A A3               [24] 3457 	inc	dptr
      00110B 12 20 17         [24] 3458 	lcall	__gptrget
      00110E 08               [12] 3459 	inc	r0
      00110F F6               [12] 3460 	mov	@r0,a
      001110 A3               [24] 3461 	inc	dptr
      001111 12 20 17         [24] 3462 	lcall	__gptrget
      001114 08               [12] 3463 	inc	r0
      001115 F6               [12] 3464 	mov	@r0,a
      001116 A8 1D            [24] 3465 	mov	r0,_bp
      001118 08               [12] 3466 	inc	r0
      001119 74 06            [12] 3467 	mov	a,#0x06
      00111B 26               [12] 3468 	add	a, @r0
      00111C FB               [12] 3469 	mov	r3,a
      00111D E4               [12] 3470 	clr	a
      00111E 08               [12] 3471 	inc	r0
      00111F 36               [12] 3472 	addc	a, @r0
      001120 FC               [12] 3473 	mov	r4,a
      001121 08               [12] 3474 	inc	r0
      001122 86 07            [24] 3475 	mov	ar7,@r0
      001124 8B 82            [24] 3476 	mov	dpl,r3
      001126 8C 83            [24] 3477 	mov	dph,r4
      001128 8F F0            [24] 3478 	mov	b,r7
      00112A E5 1D            [12] 3479 	mov	a,_bp
      00112C 24 11            [12] 3480 	add	a,#0x11
      00112E F8               [12] 3481 	mov	r0,a
      00112F 12 20 17         [24] 3482 	lcall	__gptrget
      001132 F6               [12] 3483 	mov	@r0,a
      001133 A3               [24] 3484 	inc	dptr
      001134 12 20 17         [24] 3485 	lcall	__gptrget
      001137 08               [12] 3486 	inc	r0
      001138 F6               [12] 3487 	mov	@r0,a
      001139 A3               [24] 3488 	inc	dptr
      00113A 12 20 17         [24] 3489 	lcall	__gptrget
      00113D 08               [12] 3490 	inc	r0
      00113E F6               [12] 3491 	mov	@r0,a
      00113F A3               [24] 3492 	inc	dptr
      001140 12 20 17         [24] 3493 	lcall	__gptrget
      001143 08               [12] 3494 	inc	r0
      001144 F6               [12] 3495 	mov	@r0,a
      001145 A8 1D            [24] 3496 	mov	r0,_bp
      001147 08               [12] 3497 	inc	r0
      001148 74 02            [12] 3498 	mov	a,#0x02
      00114A 26               [12] 3499 	add	a, @r0
      00114B FA               [12] 3500 	mov	r2,a
      00114C E4               [12] 3501 	clr	a
      00114D 08               [12] 3502 	inc	r0
      00114E 36               [12] 3503 	addc	a, @r0
      00114F FD               [12] 3504 	mov	r5,a
      001150 08               [12] 3505 	inc	r0
      001151 86 07            [24] 3506 	mov	ar7,@r0
      001153 8A 82            [24] 3507 	mov	dpl,r2
      001155 8D 83            [24] 3508 	mov	dph,r5
      001157 8F F0            [24] 3509 	mov	b,r7
      001159 12 20 17         [24] 3510 	lcall	__gptrget
      00115C FA               [12] 3511 	mov	r2,a
      00115D A3               [24] 3512 	inc	dptr
      00115E 12 20 17         [24] 3513 	lcall	__gptrget
      001161 FD               [12] 3514 	mov	r5,a
      001162 A3               [24] 3515 	inc	dptr
      001163 12 20 17         [24] 3516 	lcall	__gptrget
      001166 FF               [12] 3517 	mov	r7,a
      001167 A3               [24] 3518 	inc	dptr
      001168 12 20 17         [24] 3519 	lcall	__gptrget
      00116B FE               [12] 3520 	mov	r6,a
      00116C E5 1D            [12] 3521 	mov	a,_bp
      00116E 24 0D            [12] 3522 	add	a,#0x0d
      001170 F8               [12] 3523 	mov	r0,a
      001171 E6               [12] 3524 	mov	a,@r0
      001172 C0 E0            [24] 3525 	push	acc
      001174 E5 1D            [12] 3526 	mov	a,_bp
      001176 24 FA            [12] 3527 	add	a,#0xfa
      001178 F8               [12] 3528 	mov	r0,a
      001179 E6               [12] 3529 	mov	a,@r0
      00117A C0 E0            [24] 3530 	push	acc
      00117C 08               [12] 3531 	inc	r0
      00117D E6               [12] 3532 	mov	a,@r0
      00117E C0 E0            [24] 3533 	push	acc
      001180 08               [12] 3534 	inc	r0
      001181 E6               [12] 3535 	mov	a,@r0
      001182 C0 E0            [24] 3536 	push	acc
      001184 08               [12] 3537 	inc	r0
      001185 E6               [12] 3538 	mov	a,@r0
      001186 C0 E0            [24] 3539 	push	acc
      001188 E5 1D            [12] 3540 	mov	a,_bp
      00118A 24 09            [12] 3541 	add	a,#0x09
      00118C F8               [12] 3542 	mov	r0,a
      00118D E6               [12] 3543 	mov	a,@r0
      00118E C0 E0            [24] 3544 	push	acc
      001190 08               [12] 3545 	inc	r0
      001191 E6               [12] 3546 	mov	a,@r0
      001192 C0 E0            [24] 3547 	push	acc
      001194 08               [12] 3548 	inc	r0
      001195 E6               [12] 3549 	mov	a,@r0
      001196 C0 E0            [24] 3550 	push	acc
      001198 08               [12] 3551 	inc	r0
      001199 E6               [12] 3552 	mov	a,@r0
      00119A C0 E0            [24] 3553 	push	acc
      00119C E5 1D            [12] 3554 	mov	a,_bp
      00119E 24 05            [12] 3555 	add	a,#0x05
      0011A0 F8               [12] 3556 	mov	r0,a
      0011A1 E6               [12] 3557 	mov	a,@r0
      0011A2 C0 E0            [24] 3558 	push	acc
      0011A4 08               [12] 3559 	inc	r0
      0011A5 E6               [12] 3560 	mov	a,@r0
      0011A6 C0 E0            [24] 3561 	push	acc
      0011A8 08               [12] 3562 	inc	r0
      0011A9 E6               [12] 3563 	mov	a,@r0
      0011AA C0 E0            [24] 3564 	push	acc
      0011AC 08               [12] 3565 	inc	r0
      0011AD E6               [12] 3566 	mov	a,@r0
      0011AE C0 E0            [24] 3567 	push	acc
      0011B0 E5 1D            [12] 3568 	mov	a,_bp
      0011B2 24 11            [12] 3569 	add	a,#0x11
      0011B4 F8               [12] 3570 	mov	r0,a
      0011B5 E6               [12] 3571 	mov	a,@r0
      0011B6 C0 E0            [24] 3572 	push	acc
      0011B8 08               [12] 3573 	inc	r0
      0011B9 E6               [12] 3574 	mov	a,@r0
      0011BA C0 E0            [24] 3575 	push	acc
      0011BC 08               [12] 3576 	inc	r0
      0011BD E6               [12] 3577 	mov	a,@r0
      0011BE C0 E0            [24] 3578 	push	acc
      0011C0 08               [12] 3579 	inc	r0
      0011C1 E6               [12] 3580 	mov	a,@r0
      0011C2 C0 E0            [24] 3581 	push	acc
      0011C4 8A 82            [24] 3582 	mov	dpl, r2
      0011C6 8D 83            [24] 3583 	mov	dph, r5
      0011C8 8F F0            [24] 3584 	mov	b, r7
      0011CA EE               [12] 3585 	mov	a, r6
      0011CB 12 0A C8         [24] 3586 	lcall	_fuzzy_trapezoid
      0011CE AC 82            [24] 3587 	mov	r4, dpl
      0011D0 AD 83            [24] 3588 	mov	r5, dph
      0011D2 AE F0            [24] 3589 	mov	r6, b
      0011D4 FF               [12] 3590 	mov	r7, a
      0011D5 E5 81            [12] 3591 	mov	a,sp
      0011D7 24 EF            [12] 3592 	add	a,#0xef
      0011D9 F5 81            [12] 3593 	mov	sp,a
      0011DB 8C 82            [24] 3594 	mov	dpl, r4
      0011DD 8D 83            [24] 3595 	mov	dph, r5
      0011DF 8E F0            [24] 3596 	mov	b, r6
      0011E1 EF               [12] 3597 	mov	a, r7
      0011E2 80 06            [24] 3598 	sjmp	00107$
      0011E4                       3599 00106$:
                           00112D  3600 	C$fuzzy.h$279$1_0$76 ==.
                                   3601 ;	../../fuzzy.h:279: return 0.0f;
      0011E4 90 00 00         [24] 3602 	mov	dptr,#0x0000
      0011E7 E4               [12] 3603 	clr	a
      0011E8 F5 F0            [12] 3604 	mov	b,a
      0011EA                       3605 00107$:
                           001133  3606 	C$fuzzy.h$280$1_0$76 ==.
                                   3607 ;	../../fuzzy.h:280: }
      0011EA 85 1D 81         [24] 3608 	mov	sp,_bp
      0011ED D0 1D            [24] 3609 	pop	_bp
                           001138  3610 	C$fuzzy.h$280$1_0$76 ==.
                           001138  3611 	XFcontroller_8051$fuzzy_8051_eval$0$0 ==.
      0011EF 22               [24] 3612 	ret
                                   3613 ;------------------------------------------------------------
                                   3614 ;Allocation info for local variables in function 'fuzzy_rules_add_8051'
                                   3615 ;------------------------------------------------------------
                                   3616 ;value         Allocated to stack - _bp -6 +4 
                                   3617 ;output        Allocated to stack - _bp -9 +3 
                                   3618 ;rules         Allocated to stack - _bp +1 +3 
                                   3619 ;index         Allocated to registers r3 
                                   3620 ;sloc0         Allocated to stack - _bp +5 +1 
                                   3621 ;sloc1         Allocated to stack - _bp +4 +3 
                                   3622 ;sloc2         Allocated to stack - _bp +7 +3 
                                   3623 ;------------------------------------------------------------
                           001139  3624 	G$fuzzy_rules_add_8051$0$0 ==.
                           001139  3625 	C$fuzzy.h$282$1_0$81 ==.
                                   3626 ;	../../fuzzy.h:282: bool fuzzy_rules_add_8051(fuzzy_rules_t *rules, float value, const fuzzy_variable_8051_t *output)
                                   3627 ;	-----------------------------------------
                                   3628 ;	 function fuzzy_rules_add_8051
                                   3629 ;	-----------------------------------------
      0011F0                       3630 _fuzzy_rules_add_8051:
      0011F0 C0 1D            [24] 3631 	push	_bp
      0011F2 85 81 1D         [24] 3632 	mov	_bp,sp
      0011F5 C0 82            [24] 3633 	push	dpl
      0011F7 C0 83            [24] 3634 	push	dph
      0011F9 C0 F0            [24] 3635 	push	b
      0011FB E5 81            [12] 3636 	mov	a,sp
      0011FD 24 06            [12] 3637 	add	a,#0x06
      0011FF F5 81            [12] 3638 	mov	sp,a
                           00114A  3639 	C$fuzzy.h$286$1_0$81 ==.
                                   3640 ;	../../fuzzy.h:286: if (rules->count >= FUZZY_MAX_RULES) {
      001201 A8 1D            [24] 3641 	mov	r0,_bp
      001203 08               [12] 3642 	inc	r0
      001204 E5 1D            [12] 3643 	mov	a,_bp
      001206 24 07            [12] 3644 	add	a,#0x07
      001208 F9               [12] 3645 	mov	r1,a
      001209 74 0E            [12] 3646 	mov	a,#0x0e
      00120B 26               [12] 3647 	add	a, @r0
      00120C F7               [12] 3648 	mov	@r1,a
      00120D E4               [12] 3649 	clr	a
      00120E 08               [12] 3650 	inc	r0
      00120F 36               [12] 3651 	addc	a, @r0
      001210 09               [12] 3652 	inc	r1
      001211 F7               [12] 3653 	mov	@r1,a
      001212 08               [12] 3654 	inc	r0
      001213 E6               [12] 3655 	mov	a,@r0
      001214 09               [12] 3656 	inc	r1
      001215 F7               [12] 3657 	mov	@r1,a
      001216 E5 1D            [12] 3658 	mov	a,_bp
      001218 24 07            [12] 3659 	add	a,#0x07
      00121A F8               [12] 3660 	mov	r0,a
      00121B 86 82            [24] 3661 	mov	dpl,@r0
      00121D 08               [12] 3662 	inc	r0
      00121E 86 83            [24] 3663 	mov	dph,@r0
      001220 08               [12] 3664 	inc	r0
      001221 86 F0            [24] 3665 	mov	b,@r0
      001223 12 20 17         [24] 3666 	lcall	__gptrget
      001226 FF               [12] 3667 	mov	r7,a
      001227 BF 02 00         [24] 3668 	cjne	r7,#0x02,00111$
      00122A                       3669 00111$:
      00122A 40 06            [24] 3670 	jc	00102$
                           001175  3671 	C$fuzzy.h$287$2_0$82 ==.
                                   3672 ;	../../fuzzy.h:287: return false;
      00122C 75 82 00         [24] 3673 	mov	dpl, #0x00
      00122F 02 12 D5         [24] 3674 	ljmp	00103$
      001232                       3675 00102$:
                           00117B  3676 	C$fuzzy.h$290$1_0$81 ==.
                                   3677 ;	../../fuzzy.h:290: index = rules->count;
      001232 8F 03            [24] 3678 	mov	ar3,r7
                           00117D  3679 	C$fuzzy.h$291$1_0$81 ==.
                                   3680 ;	../../fuzzy.h:291: rules->rules[index].value = fuzzy_8051_clamp(value);
      001234 EB               [12] 3681 	mov	a,r3
      001235 75 F0 07         [24] 3682 	mov	b,#0x07
      001238 A4               [48] 3683 	mul	ab
      001239 FA               [12] 3684 	mov	r2,a
      00123A A8 1D            [24] 3685 	mov	r0,_bp
      00123C 08               [12] 3686 	inc	r0
      00123D E5 1D            [12] 3687 	mov	a,_bp
      00123F 24 04            [12] 3688 	add	a,#0x04
      001241 F9               [12] 3689 	mov	r1,a
      001242 EA               [12] 3690 	mov	a,r2
      001243 26               [12] 3691 	add	a, @r0
      001244 F7               [12] 3692 	mov	@r1,a
      001245 E4               [12] 3693 	clr	a
      001246 08               [12] 3694 	inc	r0
      001247 36               [12] 3695 	addc	a, @r0
      001248 09               [12] 3696 	inc	r1
      001249 F7               [12] 3697 	mov	@r1,a
      00124A 08               [12] 3698 	inc	r0
      00124B E6               [12] 3699 	mov	a,@r0
      00124C 09               [12] 3700 	inc	r1
      00124D F7               [12] 3701 	mov	@r1,a
      00124E E5 1D            [12] 3702 	mov	a,_bp
      001250 24 FA            [12] 3703 	add	a,#0xfa
      001252 F8               [12] 3704 	mov	r0,a
      001253 86 82            [24] 3705 	mov	dpl, @r0
      001255 08               [12] 3706 	inc	r0
      001256 86 83            [24] 3707 	mov	dph, @r0
      001258 08               [12] 3708 	inc	r0
      001259 86 F0            [24] 3709 	mov	b, @r0
      00125B 08               [12] 3710 	inc	r0
      00125C E6               [12] 3711 	mov	a, @r0
      00125D C0 03            [24] 3712 	push	ar3
      00125F C0 02            [24] 3713 	push	ar2
      001261 12 04 77         [24] 3714 	lcall	_fuzzy_8051_clamp
      001264 AD 82            [24] 3715 	mov	r5, dpl
      001266 AE 83            [24] 3716 	mov	r6, dph
      001268 AC F0            [24] 3717 	mov	r4, b
      00126A FF               [12] 3718 	mov	r7, a
      00126B D0 02            [24] 3719 	pop	ar2
      00126D D0 03            [24] 3720 	pop	ar3
      00126F E5 1D            [12] 3721 	mov	a,_bp
      001271 24 04            [12] 3722 	add	a,#0x04
      001273 F8               [12] 3723 	mov	r0,a
      001274 86 82            [24] 3724 	mov	dpl,@r0
      001276 08               [12] 3725 	inc	r0
      001277 86 83            [24] 3726 	mov	dph,@r0
      001279 08               [12] 3727 	inc	r0
      00127A 86 F0            [24] 3728 	mov	b,@r0
      00127C ED               [12] 3729 	mov	a,r5
      00127D 12 1D F2         [24] 3730 	lcall	__gptrput
      001280 A3               [24] 3731 	inc	dptr
      001281 EE               [12] 3732 	mov	a,r6
      001282 12 1D F2         [24] 3733 	lcall	__gptrput
      001285 A3               [24] 3734 	inc	dptr
      001286 EC               [12] 3735 	mov	a,r4
      001287 12 1D F2         [24] 3736 	lcall	__gptrput
      00128A A3               [24] 3737 	inc	dptr
      00128B EF               [12] 3738 	mov	a,r7
      00128C 12 1D F2         [24] 3739 	lcall	__gptrput
                           0011D8  3740 	C$fuzzy.h$292$1_0$81 ==.
                                   3741 ;	../../fuzzy.h:292: rules->rules[index].output = output;
      00128F A8 1D            [24] 3742 	mov	r0,_bp
      001291 08               [12] 3743 	inc	r0
      001292 EA               [12] 3744 	mov	a,r2
      001293 26               [12] 3745 	add	a, @r0
      001294 FD               [12] 3746 	mov	r5,a
      001295 E4               [12] 3747 	clr	a
      001296 08               [12] 3748 	inc	r0
      001297 36               [12] 3749 	addc	a, @r0
      001298 FE               [12] 3750 	mov	r6,a
      001299 08               [12] 3751 	inc	r0
      00129A 86 07            [24] 3752 	mov	ar7,@r0
      00129C 74 04            [12] 3753 	mov	a,#0x04
      00129E 2D               [12] 3754 	add	a, r5
      00129F FD               [12] 3755 	mov	r5,a
      0012A0 E4               [12] 3756 	clr	a
      0012A1 3E               [12] 3757 	addc	a, r6
      0012A2 FE               [12] 3758 	mov	r6,a
      0012A3 8D 82            [24] 3759 	mov	dpl,r5
      0012A5 8E 83            [24] 3760 	mov	dph,r6
      0012A7 8F F0            [24] 3761 	mov	b,r7
      0012A9 E5 1D            [12] 3762 	mov	a,_bp
      0012AB 24 F7            [12] 3763 	add	a,#0xf7
      0012AD F8               [12] 3764 	mov	r0,a
      0012AE E6               [12] 3765 	mov	a,@r0
      0012AF 12 1D F2         [24] 3766 	lcall	__gptrput
      0012B2 A3               [24] 3767 	inc	dptr
      0012B3 08               [12] 3768 	inc	r0
      0012B4 E6               [12] 3769 	mov	a,@r0
      0012B5 12 1D F2         [24] 3770 	lcall	__gptrput
      0012B8 A3               [24] 3771 	inc	dptr
      0012B9 08               [12] 3772 	inc	r0
      0012BA E6               [12] 3773 	mov	a,@r0
      0012BB 12 1D F2         [24] 3774 	lcall	__gptrput
                           001207  3775 	C$fuzzy.h$293$1_0$81 ==.
                                   3776 ;	../../fuzzy.h:293: rules->count = index + 1u;
      0012BE EB               [12] 3777 	mov	a,r3
      0012BF 04               [12] 3778 	inc	a
      0012C0 FF               [12] 3779 	mov	r7,a
      0012C1 E5 1D            [12] 3780 	mov	a,_bp
      0012C3 24 07            [12] 3781 	add	a,#0x07
      0012C5 F8               [12] 3782 	mov	r0,a
      0012C6 86 82            [24] 3783 	mov	dpl,@r0
      0012C8 08               [12] 3784 	inc	r0
      0012C9 86 83            [24] 3785 	mov	dph,@r0
      0012CB 08               [12] 3786 	inc	r0
      0012CC 86 F0            [24] 3787 	mov	b,@r0
      0012CE EF               [12] 3788 	mov	a,r7
      0012CF 12 1D F2         [24] 3789 	lcall	__gptrput
                           00121B  3790 	C$fuzzy.h$295$1_0$81 ==.
                                   3791 ;	../../fuzzy.h:295: return true;
      0012D2 75 82 01         [24] 3792 	mov	dpl, #0x01
      0012D5                       3793 00103$:
                           00121E  3794 	C$fuzzy.h$296$1_0$81 ==.
                                   3795 ;	../../fuzzy.h:296: }
      0012D5 85 1D 81         [24] 3796 	mov	sp,_bp
      0012D8 D0 1D            [24] 3797 	pop	_bp
                           001223  3798 	C$fuzzy.h$296$1_0$81 ==.
                           001223  3799 	XG$fuzzy_rules_add_8051$0$0 ==.
      0012DA 22               [24] 3800 	ret
                                   3801 ;------------------------------------------------------------
                                   3802 ;Allocation info for local variables in function 'fuzzy_8051_height'
                                   3803 ;------------------------------------------------------------
                                   3804 ;x             Allocated to stack - _bp -6 +4 
                                   3805 ;rules         Allocated to stack - _bp +1 +3 
                                   3806 ;index         Allocated to registers r7 
                                   3807 ;aggregate     Allocated to stack - _bp +14 +4 
                                   3808 ;membership    Allocated to stack - _bp +18 +4 
                                   3809 ;implied       Allocated to registers r3 r4 r5 r6 
                                   3810 ;sloc0         Allocated to stack - _bp +4 +3 
                                   3811 ;sloc1         Allocated to stack - _bp +7 +3 
                                   3812 ;sloc2         Allocated to stack - _bp +10 +4 
                                   3813 ;------------------------------------------------------------
                           001224  3814 	Fcontroller_8051$fuzzy_8051_height$0$0 ==.
                           001224  3815 	C$fuzzy.h$298$1_0$84 ==.
                                   3816 ;	../../fuzzy.h:298: static float fuzzy_8051_height(const fuzzy_rules_t *rules, float x)
                                   3817 ;	-----------------------------------------
                                   3818 ;	 function fuzzy_8051_height
                                   3819 ;	-----------------------------------------
      0012DB                       3820 _fuzzy_8051_height:
      0012DB C0 1D            [24] 3821 	push	_bp
      0012DD 85 81 1D         [24] 3822 	mov	_bp,sp
      0012E0 C0 82            [24] 3823 	push	dpl
      0012E2 C0 83            [24] 3824 	push	dph
      0012E4 C0 F0            [24] 3825 	push	b
      0012E6 E5 81            [12] 3826 	mov	a,sp
      0012E8 24 12            [12] 3827 	add	a,#0x12
      0012EA F5 81            [12] 3828 	mov	sp,a
                           001235  3829 	C$fuzzy.h$305$1_0$84 ==.
                                   3830 ;	../../fuzzy.h:305: aggregate = 0.0f;
      0012EC E5 1D            [12] 3831 	mov	a,_bp
      0012EE 24 0E            [12] 3832 	add	a,#0x0e
      0012F0 F8               [12] 3833 	mov	r0,a
      0012F1 E4               [12] 3834 	clr	a
      0012F2 F6               [12] 3835 	mov	@r0,a
      0012F3 08               [12] 3836 	inc	r0
      0012F4 F6               [12] 3837 	mov	@r0,a
      0012F5 08               [12] 3838 	inc	r0
      0012F6 F6               [12] 3839 	mov	@r0,a
      0012F7 08               [12] 3840 	inc	r0
      0012F8 F6               [12] 3841 	mov	@r0,a
                           001242  3842 	C$fuzzy.h$307$3_0$86 ==.
                                   3843 ;	../../fuzzy.h:307: for (index = 0u; index < rules->count; ++index) {
      0012F9 A8 1D            [24] 3844 	mov	r0,_bp
      0012FB 08               [12] 3845 	inc	r0
      0012FC E5 1D            [12] 3846 	mov	a,_bp
      0012FE 24 07            [12] 3847 	add	a,#0x07
      001300 F9               [12] 3848 	mov	r1,a
      001301 E6               [12] 3849 	mov	a,@r0
      001302 F7               [12] 3850 	mov	@r1,a
      001303 08               [12] 3851 	inc	r0
      001304 E6               [12] 3852 	mov	a,@r0
      001305 09               [12] 3853 	inc	r1
      001306 F7               [12] 3854 	mov	@r1,a
      001307 08               [12] 3855 	inc	r0
      001308 E6               [12] 3856 	mov	a,@r0
      001309 09               [12] 3857 	inc	r1
      00130A F7               [12] 3858 	mov	@r1,a
      00130B A8 1D            [24] 3859 	mov	r0,_bp
      00130D 08               [12] 3860 	inc	r0
      00130E E5 1D            [12] 3861 	mov	a,_bp
      001310 24 04            [12] 3862 	add	a,#0x04
      001312 F9               [12] 3863 	mov	r1,a
      001313 74 0E            [12] 3864 	mov	a,#0x0e
      001315 26               [12] 3865 	add	a, @r0
      001316 F7               [12] 3866 	mov	@r1,a
      001317 E4               [12] 3867 	clr	a
      001318 08               [12] 3868 	inc	r0
      001319 36               [12] 3869 	addc	a, @r0
      00131A 09               [12] 3870 	inc	r1
      00131B F7               [12] 3871 	mov	@r1,a
      00131C 08               [12] 3872 	inc	r0
      00131D E6               [12] 3873 	mov	a,@r0
      00131E 09               [12] 3874 	inc	r1
      00131F F7               [12] 3875 	mov	@r1,a
      001320 7F 00            [12] 3876 	mov	r7,#0x00
      001322                       3877 00105$:
      001322 E5 1D            [12] 3878 	mov	a,_bp
      001324 24 04            [12] 3879 	add	a,#0x04
      001326 F8               [12] 3880 	mov	r0,a
      001327 86 82            [24] 3881 	mov	dpl,@r0
      001329 08               [12] 3882 	inc	r0
      00132A 86 83            [24] 3883 	mov	dph,@r0
      00132C 08               [12] 3884 	inc	r0
      00132D 86 F0            [24] 3885 	mov	b,@r0
      00132F 12 20 17         [24] 3886 	lcall	__gptrget
      001332 FE               [12] 3887 	mov	r6,a
      001333 C3               [12] 3888 	clr	c
      001334 EF               [12] 3889 	mov	a,r7
      001335 9E               [12] 3890 	subb	a,r6
      001336 40 03            [24] 3891 	jc	00136$
      001338 02 14 78         [24] 3892 	ljmp	00103$
      00133B                       3893 00136$:
                           001284  3894 	C$fuzzy.h$308$3_0$86 ==.
                                   3895 ;	../../fuzzy.h:308: membership = fuzzy_8051_eval(rules->rules[index].output, x);
      00133B EF               [12] 3896 	mov	a,r7
      00133C 75 F0 07         [24] 3897 	mov	b,#0x07
      00133F A4               [48] 3898 	mul	ab
      001340 FE               [12] 3899 	mov	r6,a
      001341 C0 07            [24] 3900 	push	ar7
      001343 E5 1D            [12] 3901 	mov	a,_bp
      001345 24 07            [12] 3902 	add	a,#0x07
      001347 F8               [12] 3903 	mov	r0,a
      001348 EE               [12] 3904 	mov	a,r6
      001349 26               [12] 3905 	add	a, @r0
      00134A FC               [12] 3906 	mov	r4,a
      00134B E4               [12] 3907 	clr	a
      00134C 08               [12] 3908 	inc	r0
      00134D 36               [12] 3909 	addc	a, @r0
      00134E FD               [12] 3910 	mov	r5,a
      00134F 08               [12] 3911 	inc	r0
      001350 86 07            [24] 3912 	mov	ar7,@r0
      001352 74 04            [12] 3913 	mov	a,#0x04
      001354 2C               [12] 3914 	add	a, r4
      001355 FC               [12] 3915 	mov	r4,a
      001356 E4               [12] 3916 	clr	a
      001357 3D               [12] 3917 	addc	a, r5
      001358 FD               [12] 3918 	mov	r5,a
      001359 8C 82            [24] 3919 	mov	dpl,r4
      00135B 8D 83            [24] 3920 	mov	dph,r5
      00135D 8F F0            [24] 3921 	mov	b,r7
      00135F 12 20 17         [24] 3922 	lcall	__gptrget
      001362 FC               [12] 3923 	mov	r4,a
      001363 A3               [24] 3924 	inc	dptr
      001364 12 20 17         [24] 3925 	lcall	__gptrget
      001367 FD               [12] 3926 	mov	r5,a
      001368 A3               [24] 3927 	inc	dptr
      001369 12 20 17         [24] 3928 	lcall	__gptrget
      00136C FF               [12] 3929 	mov	r7,a
      00136D C0 07            [24] 3930 	push	ar7
      00136F C0 06            [24] 3931 	push	ar6
      001371 E5 1D            [12] 3932 	mov	a,_bp
      001373 24 FA            [12] 3933 	add	a,#0xfa
      001375 F8               [12] 3934 	mov	r0,a
      001376 E6               [12] 3935 	mov	a,@r0
      001377 C0 E0            [24] 3936 	push	acc
      001379 08               [12] 3937 	inc	r0
      00137A E6               [12] 3938 	mov	a,@r0
      00137B C0 E0            [24] 3939 	push	acc
      00137D 08               [12] 3940 	inc	r0
      00137E E6               [12] 3941 	mov	a,@r0
      00137F C0 E0            [24] 3942 	push	acc
      001381 08               [12] 3943 	inc	r0
      001382 E6               [12] 3944 	mov	a,@r0
      001383 C0 E0            [24] 3945 	push	acc
      001385 8C 82            [24] 3946 	mov	dpl, r4
      001387 8D 83            [24] 3947 	mov	dph, r5
      001389 8F F0            [24] 3948 	mov	b, r7
      00138B 12 0E 5F         [24] 3949 	lcall	_fuzzy_8051_eval
      00138E C8               [12] 3950 	xch	a,r0
      00138F E5 1D            [12] 3951 	mov	a,_bp
      001391 24 12            [12] 3952 	add	a,#0x12
      001393 C8               [12] 3953 	xch	a,r0
      001394 A6 82            [24] 3954 	mov	@r0, dpl
      001396 08               [12] 3955 	inc	r0
      001397 A6 83            [24] 3956 	mov	@r0, dph
      001399 08               [12] 3957 	inc	r0
      00139A A6 F0            [24] 3958 	mov	@r0, b
      00139C 08               [12] 3959 	inc	r0
      00139D F6               [12] 3960 	mov	@r0,a
      00139E E5 81            [12] 3961 	mov	a,sp
      0013A0 24 FC            [12] 3962 	add	a,#0xfc
      0013A2 F5 81            [12] 3963 	mov	sp,a
      0013A4 D0 06            [24] 3964 	pop	ar6
      0013A6 D0 07            [24] 3965 	pop	ar7
                           0012F1  3966 	C$fuzzy.h$309$3_0$86 ==.
                                   3967 ;	../../fuzzy.h:309: implied = rules->rules[index].value < membership ? rules->rules[index].value : membership;
      0013A8 A8 1D            [24] 3968 	mov	r0,_bp
      0013AA 08               [12] 3969 	inc	r0
      0013AB EE               [12] 3970 	mov	a,r6
      0013AC 26               [12] 3971 	add	a, @r0
      0013AD FE               [12] 3972 	mov	r6,a
      0013AE E4               [12] 3973 	clr	a
      0013AF 08               [12] 3974 	inc	r0
      0013B0 36               [12] 3975 	addc	a, @r0
      0013B1 FF               [12] 3976 	mov	r7,a
      0013B2 08               [12] 3977 	inc	r0
      0013B3 86 05            [24] 3978 	mov	ar5,@r0
      0013B5 8E 82            [24] 3979 	mov	dpl,r6
      0013B7 8F 83            [24] 3980 	mov	dph,r7
      0013B9 8D F0            [24] 3981 	mov	b,r5
      0013BB E5 1D            [12] 3982 	mov	a,_bp
      0013BD 24 0A            [12] 3983 	add	a,#0x0a
      0013BF F8               [12] 3984 	mov	r0,a
      0013C0 12 20 17         [24] 3985 	lcall	__gptrget
      0013C3 F6               [12] 3986 	mov	@r0,a
      0013C4 A3               [24] 3987 	inc	dptr
      0013C5 12 20 17         [24] 3988 	lcall	__gptrget
      0013C8 08               [12] 3989 	inc	r0
      0013C9 F6               [12] 3990 	mov	@r0,a
      0013CA A3               [24] 3991 	inc	dptr
      0013CB 12 20 17         [24] 3992 	lcall	__gptrget
      0013CE 08               [12] 3993 	inc	r0
      0013CF F6               [12] 3994 	mov	@r0,a
      0013D0 A3               [24] 3995 	inc	dptr
      0013D1 12 20 17         [24] 3996 	lcall	__gptrget
      0013D4 08               [12] 3997 	inc	r0
      0013D5 F6               [12] 3998 	mov	@r0,a
      0013D6 E5 1D            [12] 3999 	mov	a,_bp
      0013D8 24 12            [12] 4000 	add	a,#0x12
      0013DA F8               [12] 4001 	mov	r0,a
      0013DB E6               [12] 4002 	mov	a,@r0
      0013DC C0 E0            [24] 4003 	push	acc
      0013DE 08               [12] 4004 	inc	r0
      0013DF E6               [12] 4005 	mov	a,@r0
      0013E0 C0 E0            [24] 4006 	push	acc
      0013E2 08               [12] 4007 	inc	r0
      0013E3 E6               [12] 4008 	mov	a,@r0
      0013E4 C0 E0            [24] 4009 	push	acc
      0013E6 08               [12] 4010 	inc	r0
      0013E7 E6               [12] 4011 	mov	a,@r0
      0013E8 C0 E0            [24] 4012 	push	acc
      0013EA E5 1D            [12] 4013 	mov	a,_bp
      0013EC 24 0A            [12] 4014 	add	a,#0x0a
      0013EE F8               [12] 4015 	mov	r0,a
      0013EF 86 82            [24] 4016 	mov	dpl, @r0
      0013F1 08               [12] 4017 	inc	r0
      0013F2 86 83            [24] 4018 	mov	dph, @r0
      0013F4 08               [12] 4019 	inc	r0
      0013F5 86 F0            [24] 4020 	mov	b, @r0
      0013F7 08               [12] 4021 	inc	r0
      0013F8 E6               [12] 4022 	mov	a, @r0
      0013F9 12 1E 0D         [24] 4023 	lcall	___fslt
      0013FC AF 82            [24] 4024 	mov	r7, dpl
      0013FE E5 81            [12] 4025 	mov	a,sp
      001400 24 FC            [12] 4026 	add	a,#0xfc
      001402 F5 81            [12] 4027 	mov	sp,a
      001404 EF               [12] 4028 	mov	a,r7
      001405 D0 07            [24] 4029 	pop	ar7
      001407 60 12            [24] 4030 	jz	00109$
      001409 E5 1D            [12] 4031 	mov	a,_bp
      00140B 24 0A            [12] 4032 	add	a,#0x0a
      00140D F8               [12] 4033 	mov	r0,a
      00140E 86 03            [24] 4034 	mov	ar3,@r0
      001410 08               [12] 4035 	inc	r0
      001411 86 04            [24] 4036 	mov	ar4,@r0
      001413 08               [12] 4037 	inc	r0
      001414 86 05            [24] 4038 	mov	ar5,@r0
      001416 08               [12] 4039 	inc	r0
      001417 86 06            [24] 4040 	mov	ar6,@r0
      001419 80 10            [24] 4041 	sjmp	00110$
      00141B                       4042 00109$:
      00141B E5 1D            [12] 4043 	mov	a,_bp
      00141D 24 12            [12] 4044 	add	a,#0x12
      00141F F8               [12] 4045 	mov	r0,a
      001420 86 03            [24] 4046 	mov	ar3,@r0
      001422 08               [12] 4047 	inc	r0
      001423 86 04            [24] 4048 	mov	ar4,@r0
      001425 08               [12] 4049 	inc	r0
      001426 86 05            [24] 4050 	mov	ar5,@r0
      001428 08               [12] 4051 	inc	r0
      001429 86 06            [24] 4052 	mov	ar6,@r0
      00142B                       4053 00110$:
                           001374  4054 	C$fuzzy.h$311$1_0$84 ==.
                                   4055 ;	../../fuzzy.h:311: if (implied > aggregate) {
      00142B C0 07            [24] 4056 	push	ar7
      00142D C0 06            [24] 4057 	push	ar6
      00142F C0 05            [24] 4058 	push	ar5
      001431 C0 04            [24] 4059 	push	ar4
      001433 C0 03            [24] 4060 	push	ar3
      001435 C0 03            [24] 4061 	push	ar3
      001437 C0 04            [24] 4062 	push	ar4
      001439 C0 05            [24] 4063 	push	ar5
      00143B C0 06            [24] 4064 	push	ar6
      00143D E5 1D            [12] 4065 	mov	a,_bp
      00143F 24 0E            [12] 4066 	add	a,#0x0e
      001441 F8               [12] 4067 	mov	r0,a
      001442 86 82            [24] 4068 	mov	dpl, @r0
      001444 08               [12] 4069 	inc	r0
      001445 86 83            [24] 4070 	mov	dph, @r0
      001447 08               [12] 4071 	inc	r0
      001448 86 F0            [24] 4072 	mov	b, @r0
      00144A 08               [12] 4073 	inc	r0
      00144B E6               [12] 4074 	mov	a, @r0
      00144C 12 1E 0D         [24] 4075 	lcall	___fslt
      00144F AA 82            [24] 4076 	mov	r2, dpl
      001451 E5 81            [12] 4077 	mov	a,sp
      001453 24 FC            [12] 4078 	add	a,#0xfc
      001455 F5 81            [12] 4079 	mov	sp,a
      001457 D0 03            [24] 4080 	pop	ar3
      001459 D0 04            [24] 4081 	pop	ar4
      00145B D0 05            [24] 4082 	pop	ar5
      00145D D0 06            [24] 4083 	pop	ar6
      00145F D0 07            [24] 4084 	pop	ar7
      001461 EA               [12] 4085 	mov	a,r2
      001462 60 10            [24] 4086 	jz	00106$
                           0013AD  4087 	C$fuzzy.h$312$4_0$87 ==.
                                   4088 ;	../../fuzzy.h:312: aggregate = implied;
      001464 E5 1D            [12] 4089 	mov	a,_bp
      001466 24 0E            [12] 4090 	add	a,#0x0e
      001468 F8               [12] 4091 	mov	r0,a
      001469 A6 03            [24] 4092 	mov	@r0,ar3
      00146B 08               [12] 4093 	inc	r0
      00146C A6 04            [24] 4094 	mov	@r0,ar4
      00146E 08               [12] 4095 	inc	r0
      00146F A6 05            [24] 4096 	mov	@r0,ar5
      001471 08               [12] 4097 	inc	r0
      001472 A6 06            [24] 4098 	mov	@r0,ar6
      001474                       4099 00106$:
                           0013BD  4100 	C$fuzzy.h$307$2_0$85 ==.
                                   4101 ;	../../fuzzy.h:307: for (index = 0u; index < rules->count; ++index) {
      001474 0F               [12] 4102 	inc	r7
      001475 02 13 22         [24] 4103 	ljmp	00105$
      001478                       4104 00103$:
                           0013C1  4105 	C$fuzzy.h$316$1_0$84 ==.
                                   4106 ;	../../fuzzy.h:316: return aggregate;
      001478 E5 1D            [12] 4107 	mov	a,_bp
      00147A 24 0E            [12] 4108 	add	a,#0x0e
      00147C F8               [12] 4109 	mov	r0,a
      00147D 86 82            [24] 4110 	mov	dpl, @r0
      00147F 08               [12] 4111 	inc	r0
      001480 86 83            [24] 4112 	mov	dph, @r0
      001482 08               [12] 4113 	inc	r0
      001483 86 F0            [24] 4114 	mov	b, @r0
      001485 08               [12] 4115 	inc	r0
      001486 E6               [12] 4116 	mov	a, @r0
                           0013D0  4117 	C$fuzzy.h$317$1_0$84 ==.
                                   4118 ;	../../fuzzy.h:317: }
      001487 85 1D 81         [24] 4119 	mov	sp,_bp
      00148A D0 1D            [24] 4120 	pop	_bp
                           0013D5  4121 	C$fuzzy.h$317$1_0$84 ==.
                           0013D5  4122 	XFcontroller_8051$fuzzy_8051_height$0$0 ==.
      00148C 22               [24] 4123 	ret
                                   4124 ;------------------------------------------------------------
                                   4125 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify'
                                   4126 ;------------------------------------------------------------
                                   4127 ;lower         Allocated to stack - _bp -6 +4 
                                   4128 ;upper         Allocated to stack - _bp -10 +4 
                                   4129 ;step          Allocated to stack - _bp -14 +4 
                                   4130 ;method        Allocated to stack - _bp -15 +1 
                                   4131 ;rules         Allocated to stack - _bp +1 +3 
                                   4132 ;x             Allocated to stack - _bp +4 +4 
                                   4133 ;height        Allocated to stack - _bp +8 +4 
                                   4134 ;weighted      Allocated to stack - _bp +12 +4 
                                   4135 ;sum           Allocated to stack - _bp +16 +4 
                                   4136 ;maximum       Allocated to stack - _bp +20 +4 
                                   4137 ;maximum_sum   Allocated to stack - _bp +24 +4 
                                   4138 ;smallest      Allocated to stack - _bp +28 +4 
                                   4139 ;largest       Allocated to stack - _bp +32 +4 
                                   4140 ;maximum_count Allocated to registers r5 r4 
                                   4141 ;------------------------------------------------------------
                           0013D6  4142 	G$fuzzy_rules_defuzzify$0$0 ==.
                           0013D6  4143 	C$fuzzy.h$319$1_0$89 ==.
                                   4144 ;	../../fuzzy.h:319: float fuzzy_rules_defuzzify(const fuzzy_rules_t *rules, float lower, float upper, float step, fuzzy_defuzz_method_t method)
                                   4145 ;	-----------------------------------------
                                   4146 ;	 function fuzzy_rules_defuzzify
                                   4147 ;	-----------------------------------------
      00148D                       4148 _fuzzy_rules_defuzzify:
      00148D C0 1D            [24] 4149 	push	_bp
      00148F 85 81 1D         [24] 4150 	mov	_bp,sp
      001492 C0 82            [24] 4151 	push	dpl
      001494 C0 83            [24] 4152 	push	dph
      001496 C0 F0            [24] 4153 	push	b
      001498 E5 81            [12] 4154 	mov	a,sp
      00149A 24 20            [12] 4155 	add	a,#0x20
      00149C F5 81            [12] 4156 	mov	sp,a
                           0013E7  4157 	C$fuzzy.h$331$1_0$89 ==.
                                   4158 ;	../../fuzzy.h:331: if (rules->count == 0u || lower > upper || step <= 0.0f) {
      00149E A8 1D            [24] 4159 	mov	r0,_bp
      0014A0 08               [12] 4160 	inc	r0
      0014A1 74 0E            [12] 4161 	mov	a,#0x0e
      0014A3 26               [12] 4162 	add	a, @r0
      0014A4 FA               [12] 4163 	mov	r2,a
      0014A5 E4               [12] 4164 	clr	a
      0014A6 08               [12] 4165 	inc	r0
      0014A7 36               [12] 4166 	addc	a, @r0
      0014A8 FB               [12] 4167 	mov	r3,a
      0014A9 08               [12] 4168 	inc	r0
      0014AA 86 04            [24] 4169 	mov	ar4,@r0
      0014AC 8A 82            [24] 4170 	mov	dpl,r2
      0014AE 8B 83            [24] 4171 	mov	dph,r3
      0014B0 8C F0            [24] 4172 	mov	b,r4
      0014B2 12 20 17         [24] 4173 	lcall	__gptrget
      0014B5 60 5C            [24] 4174 	jz	00101$
      0014B7 E5 1D            [12] 4175 	mov	a,_bp
      0014B9 24 FA            [12] 4176 	add	a,#0xfa
      0014BB F8               [12] 4177 	mov	r0,a
      0014BC E6               [12] 4178 	mov	a,@r0
      0014BD C0 E0            [24] 4179 	push	acc
      0014BF 08               [12] 4180 	inc	r0
      0014C0 E6               [12] 4181 	mov	a,@r0
      0014C1 C0 E0            [24] 4182 	push	acc
      0014C3 08               [12] 4183 	inc	r0
      0014C4 E6               [12] 4184 	mov	a,@r0
      0014C5 C0 E0            [24] 4185 	push	acc
      0014C7 08               [12] 4186 	inc	r0
      0014C8 E6               [12] 4187 	mov	a,@r0
      0014C9 C0 E0            [24] 4188 	push	acc
      0014CB E5 1D            [12] 4189 	mov	a,_bp
      0014CD 24 F6            [12] 4190 	add	a,#0xf6
      0014CF F8               [12] 4191 	mov	r0,a
      0014D0 86 82            [24] 4192 	mov	dpl, @r0
      0014D2 08               [12] 4193 	inc	r0
      0014D3 86 83            [24] 4194 	mov	dph, @r0
      0014D5 08               [12] 4195 	inc	r0
      0014D6 86 F0            [24] 4196 	mov	b, @r0
      0014D8 08               [12] 4197 	inc	r0
      0014D9 E6               [12] 4198 	mov	a, @r0
      0014DA 12 1E 0D         [24] 4199 	lcall	___fslt
      0014DD AC 82            [24] 4200 	mov	r4, dpl
      0014DF E5 81            [12] 4201 	mov	a,sp
      0014E1 24 FC            [12] 4202 	add	a,#0xfc
      0014E3 F5 81            [12] 4203 	mov	sp,a
      0014E5 EC               [12] 4204 	mov	a,r4
      0014E6 70 2B            [24] 4205 	jnz	00101$
      0014E8 E5 1D            [12] 4206 	mov	a,_bp
      0014EA 24 F2            [12] 4207 	add	a,#0xf2
      0014EC F8               [12] 4208 	mov	r0,a
      0014ED E6               [12] 4209 	mov	a,@r0
      0014EE C0 E0            [24] 4210 	push	acc
      0014F0 08               [12] 4211 	inc	r0
      0014F1 E6               [12] 4212 	mov	a,@r0
      0014F2 C0 E0            [24] 4213 	push	acc
      0014F4 08               [12] 4214 	inc	r0
      0014F5 E6               [12] 4215 	mov	a,@r0
      0014F6 C0 E0            [24] 4216 	push	acc
      0014F8 08               [12] 4217 	inc	r0
      0014F9 E6               [12] 4218 	mov	a,@r0
      0014FA C0 E0            [24] 4219 	push	acc
      0014FC 90 00 00         [24] 4220 	mov	dptr,#0x0000
      0014FF E4               [12] 4221 	clr	a
      001500 F5 F0            [12] 4222 	mov	b,a
      001502 12 1E 0D         [24] 4223 	lcall	___fslt
      001505 E5 81            [12] 4224 	mov	a,sp
      001507 24 FC            [12] 4225 	add	a,#0xfc
      001509 F5 81            [12] 4226 	mov	sp,a
      00150B E5 82            [12] 4227 	mov	a, dpl
      00150D 24 FF            [12] 4228 	add	a,#0xff
      00150F 92 00            [24] 4229 	mov	b0,c
      001511 40 09            [24] 4230 	jc	00102$
      001513                       4231 00101$:
                           00145C  4232 	C$fuzzy.h$332$2_0$90 ==.
                                   4233 ;	../../fuzzy.h:332: return 0.0f;
      001513 90 00 00         [24] 4234 	mov	dptr,#0x0000
      001516 E4               [12] 4235 	clr	a
      001517 F5 F0            [12] 4236 	mov	b,a
      001519 02 19 CB         [24] 4237 	ljmp	00120$
      00151C                       4238 00102$:
                           001465  4239 	C$fuzzy.h$335$1_0$89 ==.
                                   4240 ;	../../fuzzy.h:335: weighted = 0.0f;
      00151C E5 1D            [12] 4241 	mov	a,_bp
      00151E 24 0C            [12] 4242 	add	a,#0x0c
      001520 F8               [12] 4243 	mov	r0,a
      001521 E4               [12] 4244 	clr	a
      001522 F6               [12] 4245 	mov	@r0,a
      001523 08               [12] 4246 	inc	r0
      001524 F6               [12] 4247 	mov	@r0,a
      001525 08               [12] 4248 	inc	r0
      001526 F6               [12] 4249 	mov	@r0,a
      001527 08               [12] 4250 	inc	r0
      001528 F6               [12] 4251 	mov	@r0,a
                           001472  4252 	C$fuzzy.h$336$1_0$89 ==.
                                   4253 ;	../../fuzzy.h:336: sum = 0.0f;
      001529 E5 1D            [12] 4254 	mov	a,_bp
      00152B 24 10            [12] 4255 	add	a,#0x10
      00152D F8               [12] 4256 	mov	r0,a
      00152E E4               [12] 4257 	clr	a
      00152F F6               [12] 4258 	mov	@r0,a
      001530 08               [12] 4259 	inc	r0
      001531 F6               [12] 4260 	mov	@r0,a
      001532 08               [12] 4261 	inc	r0
      001533 F6               [12] 4262 	mov	@r0,a
      001534 08               [12] 4263 	inc	r0
      001535 F6               [12] 4264 	mov	@r0,a
                           00147F  4265 	C$fuzzy.h$337$1_0$89 ==.
                                   4266 ;	../../fuzzy.h:337: maximum = -1.0f;
      001536 E5 1D            [12] 4267 	mov	a,_bp
      001538 24 14            [12] 4268 	add	a,#0x14
      00153A F8               [12] 4269 	mov	r0,a
      00153B E4               [12] 4270 	clr	a
      00153C F6               [12] 4271 	mov	@r0,a
      00153D 08               [12] 4272 	inc	r0
      00153E F6               [12] 4273 	mov	@r0,a
      00153F 08               [12] 4274 	inc	r0
      001540 76 80            [12] 4275 	mov	@r0,#0x80
      001542 08               [12] 4276 	inc	r0
      001543 76 BF            [12] 4277 	mov	@r0,#0xbf
                           00148E  4278 	C$fuzzy.h$338$1_0$89 ==.
                                   4279 ;	../../fuzzy.h:338: maximum_sum = 0.0f;
      001545 E5 1D            [12] 4280 	mov	a,_bp
      001547 24 18            [12] 4281 	add	a,#0x18
      001549 F8               [12] 4282 	mov	r0,a
      00154A E4               [12] 4283 	clr	a
      00154B F6               [12] 4284 	mov	@r0,a
      00154C 08               [12] 4285 	inc	r0
      00154D F6               [12] 4286 	mov	@r0,a
      00154E 08               [12] 4287 	inc	r0
      00154F F6               [12] 4288 	mov	@r0,a
      001550 08               [12] 4289 	inc	r0
      001551 F6               [12] 4290 	mov	@r0,a
                           00149B  4291 	C$fuzzy.h$339$1_0$89 ==.
                                   4292 ;	../../fuzzy.h:339: maximum_count = 0u;
      001552 FD               [12] 4293 	mov	r5,a
      001553 FC               [12] 4294 	mov	r4,a
                           00149D  4295 	C$fuzzy.h$340$1_0$89 ==.
                                   4296 ;	../../fuzzy.h:340: smallest = lower;
      001554 E5 1D            [12] 4297 	mov	a,_bp
      001556 24 FA            [12] 4298 	add	a,#0xfa
      001558 F8               [12] 4299 	mov	r0,a
      001559 E5 1D            [12] 4300 	mov	a,_bp
      00155B 24 1C            [12] 4301 	add	a,#0x1c
      00155D F9               [12] 4302 	mov	r1,a
      00155E E6               [12] 4303 	mov	a,@r0
      00155F F7               [12] 4304 	mov	@r1,a
      001560 08               [12] 4305 	inc	r0
      001561 E6               [12] 4306 	mov	a,@r0
      001562 09               [12] 4307 	inc	r1
      001563 F7               [12] 4308 	mov	@r1,a
      001564 08               [12] 4309 	inc	r0
      001565 E6               [12] 4310 	mov	a,@r0
      001566 09               [12] 4311 	inc	r1
      001567 F7               [12] 4312 	mov	@r1,a
      001568 08               [12] 4313 	inc	r0
      001569 E6               [12] 4314 	mov	a,@r0
      00156A 09               [12] 4315 	inc	r1
      00156B F7               [12] 4316 	mov	@r1,a
                           0014B5  4317 	C$fuzzy.h$341$1_0$89 ==.
                                   4318 ;	../../fuzzy.h:341: largest = lower;
      00156C E5 1D            [12] 4319 	mov	a,_bp
      00156E 24 1C            [12] 4320 	add	a,#0x1c
      001570 F8               [12] 4321 	mov	r0,a
      001571 E5 1D            [12] 4322 	mov	a,_bp
      001573 24 20            [12] 4323 	add	a,#0x20
      001575 F9               [12] 4324 	mov	r1,a
      001576 E6               [12] 4325 	mov	a,@r0
      001577 F7               [12] 4326 	mov	@r1,a
      001578 08               [12] 4327 	inc	r0
      001579 E6               [12] 4328 	mov	a,@r0
      00157A 09               [12] 4329 	inc	r1
      00157B F7               [12] 4330 	mov	@r1,a
      00157C 08               [12] 4331 	inc	r0
      00157D E6               [12] 4332 	mov	a,@r0
      00157E 09               [12] 4333 	inc	r1
      00157F F7               [12] 4334 	mov	@r1,a
      001580 08               [12] 4335 	inc	r0
      001581 E6               [12] 4336 	mov	a,@r0
      001582 09               [12] 4337 	inc	r1
      001583 F7               [12] 4338 	mov	@r1,a
                           0014CD  4339 	C$fuzzy.h$343$2_0$91 ==.
                                   4340 ;	../../fuzzy.h:343: for (x = lower; x <= upper; x += step) {
      001584 E5 1D            [12] 4341 	mov	a,_bp
      001586 24 1C            [12] 4342 	add	a,#0x1c
      001588 F8               [12] 4343 	mov	r0,a
      001589 E5 1D            [12] 4344 	mov	a,_bp
      00158B 24 04            [12] 4345 	add	a,#0x04
      00158D F9               [12] 4346 	mov	r1,a
      00158E E6               [12] 4347 	mov	a,@r0
      00158F F7               [12] 4348 	mov	@r1,a
      001590 08               [12] 4349 	inc	r0
      001591 E6               [12] 4350 	mov	a,@r0
      001592 09               [12] 4351 	inc	r1
      001593 F7               [12] 4352 	mov	@r1,a
      001594 08               [12] 4353 	inc	r0
      001595 E6               [12] 4354 	mov	a,@r0
      001596 09               [12] 4355 	inc	r1
      001597 F7               [12] 4356 	mov	@r1,a
      001598 08               [12] 4357 	inc	r0
      001599 E6               [12] 4358 	mov	a,@r0
      00159A 09               [12] 4359 	inc	r1
      00159B F7               [12] 4360 	mov	@r1,a
      00159C                       4361 00118$:
      00159C C0 05            [24] 4362 	push	ar5
      00159E C0 04            [24] 4363 	push	ar4
      0015A0 E5 1D            [12] 4364 	mov	a,_bp
      0015A2 24 04            [12] 4365 	add	a,#0x04
      0015A4 F8               [12] 4366 	mov	r0,a
      0015A5 E6               [12] 4367 	mov	a,@r0
      0015A6 C0 E0            [24] 4368 	push	acc
      0015A8 08               [12] 4369 	inc	r0
      0015A9 E6               [12] 4370 	mov	a,@r0
      0015AA C0 E0            [24] 4371 	push	acc
      0015AC 08               [12] 4372 	inc	r0
      0015AD E6               [12] 4373 	mov	a,@r0
      0015AE C0 E0            [24] 4374 	push	acc
      0015B0 08               [12] 4375 	inc	r0
      0015B1 E6               [12] 4376 	mov	a,@r0
      0015B2 C0 E0            [24] 4377 	push	acc
      0015B4 E5 1D            [12] 4378 	mov	a,_bp
      0015B6 24 F6            [12] 4379 	add	a,#0xf6
      0015B8 F8               [12] 4380 	mov	r0,a
      0015B9 86 82            [24] 4381 	mov	dpl, @r0
      0015BB 08               [12] 4382 	inc	r0
      0015BC 86 83            [24] 4383 	mov	dph, @r0
      0015BE 08               [12] 4384 	inc	r0
      0015BF 86 F0            [24] 4385 	mov	b, @r0
      0015C1 08               [12] 4386 	inc	r0
      0015C2 E6               [12] 4387 	mov	a, @r0
      0015C3 12 1E 0D         [24] 4388 	lcall	___fslt
      0015C6 E5 81            [12] 4389 	mov	a,sp
      0015C8 24 FC            [12] 4390 	add	a,#0xfc
      0015CA F5 81            [12] 4391 	mov	sp,a
      0015CC D0 04            [24] 4392 	pop	ar4
      0015CE D0 05            [24] 4393 	pop	ar5
      0015D0 E5 82            [12] 4394 	mov	a, dpl
      0015D2 24 FF            [12] 4395 	add	a,#0xff
      0015D4 92 00            [24] 4396 	mov	b0,c
      0015D6 50 03            [24] 4397 	jnc	00211$
      0015D8 02 18 33         [24] 4398 	ljmp	00110$
      0015DB                       4399 00211$:
                           001524  4400 	C$fuzzy.h$344$3_0$92 ==.
                                   4401 ;	../../fuzzy.h:344: height = fuzzy_8051_height(rules, x);
      0015DB C0 05            [24] 4402 	push	ar5
      0015DD C0 04            [24] 4403 	push	ar4
      0015DF E5 1D            [12] 4404 	mov	a,_bp
      0015E1 24 04            [12] 4405 	add	a,#0x04
      0015E3 F8               [12] 4406 	mov	r0,a
      0015E4 E6               [12] 4407 	mov	a,@r0
      0015E5 C0 E0            [24] 4408 	push	acc
      0015E7 08               [12] 4409 	inc	r0
      0015E8 E6               [12] 4410 	mov	a,@r0
      0015E9 C0 E0            [24] 4411 	push	acc
      0015EB 08               [12] 4412 	inc	r0
      0015EC E6               [12] 4413 	mov	a,@r0
      0015ED C0 E0            [24] 4414 	push	acc
      0015EF 08               [12] 4415 	inc	r0
      0015F0 E6               [12] 4416 	mov	a,@r0
      0015F1 C0 E0            [24] 4417 	push	acc
      0015F3 A8 1D            [24] 4418 	mov	r0,_bp
      0015F5 08               [12] 4419 	inc	r0
      0015F6 86 82            [24] 4420 	mov	dpl, @r0
      0015F8 08               [12] 4421 	inc	r0
      0015F9 86 83            [24] 4422 	mov	dph, @r0
      0015FB 08               [12] 4423 	inc	r0
      0015FC 86 F0            [24] 4424 	mov	b, @r0
      0015FE 12 12 DB         [24] 4425 	lcall	_fuzzy_8051_height
      001601 C8               [12] 4426 	xch	a,r0
      001602 E5 1D            [12] 4427 	mov	a,_bp
      001604 24 08            [12] 4428 	add	a,#0x08
      001606 C8               [12] 4429 	xch	a,r0
      001607 A6 82            [24] 4430 	mov	@r0, dpl
      001609 08               [12] 4431 	inc	r0
      00160A A6 83            [24] 4432 	mov	@r0, dph
      00160C 08               [12] 4433 	inc	r0
      00160D A6 F0            [24] 4434 	mov	@r0, b
      00160F 08               [12] 4435 	inc	r0
      001610 F6               [12] 4436 	mov	@r0,a
      001611 E5 81            [12] 4437 	mov	a,sp
      001613 24 FC            [12] 4438 	add	a,#0xfc
      001615 F5 81            [12] 4439 	mov	sp,a
                           001560  4440 	C$fuzzy.h$346$1_0$89 ==.
                                   4441 ;	../../fuzzy.h:346: weighted += x * height;
      001617 E5 1D            [12] 4442 	mov	a,_bp
      001619 24 08            [12] 4443 	add	a,#0x08
      00161B F8               [12] 4444 	mov	r0,a
      00161C E6               [12] 4445 	mov	a,@r0
      00161D C0 E0            [24] 4446 	push	acc
      00161F 08               [12] 4447 	inc	r0
      001620 E6               [12] 4448 	mov	a,@r0
      001621 C0 E0            [24] 4449 	push	acc
      001623 08               [12] 4450 	inc	r0
      001624 E6               [12] 4451 	mov	a,@r0
      001625 C0 E0            [24] 4452 	push	acc
      001627 08               [12] 4453 	inc	r0
      001628 E6               [12] 4454 	mov	a,@r0
      001629 C0 E0            [24] 4455 	push	acc
      00162B E5 1D            [12] 4456 	mov	a,_bp
      00162D 24 04            [12] 4457 	add	a,#0x04
      00162F F8               [12] 4458 	mov	r0,a
      001630 86 82            [24] 4459 	mov	dpl, @r0
      001632 08               [12] 4460 	inc	r0
      001633 86 83            [24] 4461 	mov	dph, @r0
      001635 08               [12] 4462 	inc	r0
      001636 86 F0            [24] 4463 	mov	b, @r0
      001638 08               [12] 4464 	inc	r0
      001639 E6               [12] 4465 	mov	a, @r0
      00163A 12 1C DD         [24] 4466 	lcall	___fsmul
      00163D AA 82            [24] 4467 	mov	r2, dpl
      00163F AB 83            [24] 4468 	mov	r3, dph
      001641 AE F0            [24] 4469 	mov	r6, b
      001643 FF               [12] 4470 	mov	r7, a
      001644 E5 81            [12] 4471 	mov	a,sp
      001646 24 FC            [12] 4472 	add	a,#0xfc
      001648 F5 81            [12] 4473 	mov	sp,a
      00164A C0 02            [24] 4474 	push	ar2
      00164C C0 03            [24] 4475 	push	ar3
      00164E C0 06            [24] 4476 	push	ar6
      001650 C0 07            [24] 4477 	push	ar7
                           00159B  4478 	C$fuzzy.h$347$1_0$89 ==.
                                   4479 ;	../../fuzzy.h:347: sum += height;
      001652 E5 1D            [12] 4480 	mov	a,_bp
      001654 24 0C            [12] 4481 	add	a,#0x0c
      001656 F8               [12] 4482 	mov	r0,a
      001657 86 82            [24] 4483 	mov	dpl, @r0
      001659 08               [12] 4484 	inc	r0
      00165A 86 83            [24] 4485 	mov	dph, @r0
      00165C 08               [12] 4486 	inc	r0
      00165D 86 F0            [24] 4487 	mov	b, @r0
      00165F 08               [12] 4488 	inc	r0
      001660 E6               [12] 4489 	mov	a, @r0
      001661 12 1E 3D         [24] 4490 	lcall	___fsadd
      001664 C8               [12] 4491 	xch	a,r0
      001665 E5 1D            [12] 4492 	mov	a,_bp
      001667 24 0C            [12] 4493 	add	a,#0x0c
      001669 C8               [12] 4494 	xch	a,r0
      00166A A6 82            [24] 4495 	mov	@r0, dpl
      00166C 08               [12] 4496 	inc	r0
      00166D A6 83            [24] 4497 	mov	@r0, dph
      00166F 08               [12] 4498 	inc	r0
      001670 A6 F0            [24] 4499 	mov	@r0, b
      001672 08               [12] 4500 	inc	r0
      001673 F6               [12] 4501 	mov	@r0,a
      001674 E5 81            [12] 4502 	mov	a,sp
      001676 24 FC            [12] 4503 	add	a,#0xfc
      001678 F5 81            [12] 4504 	mov	sp,a
      00167A E5 1D            [12] 4505 	mov	a,_bp
      00167C 24 08            [12] 4506 	add	a,#0x08
      00167E F8               [12] 4507 	mov	r0,a
      00167F E6               [12] 4508 	mov	a,@r0
      001680 C0 E0            [24] 4509 	push	acc
      001682 08               [12] 4510 	inc	r0
      001683 E6               [12] 4511 	mov	a,@r0
      001684 C0 E0            [24] 4512 	push	acc
      001686 08               [12] 4513 	inc	r0
      001687 E6               [12] 4514 	mov	a,@r0
      001688 C0 E0            [24] 4515 	push	acc
      00168A 08               [12] 4516 	inc	r0
      00168B E6               [12] 4517 	mov	a,@r0
      00168C C0 E0            [24] 4518 	push	acc
                           0015D7  4519 	C$fuzzy.h$349$1_0$89 ==.
                                   4520 ;	../../fuzzy.h:349: if (height > maximum) {
      00168E E5 1D            [12] 4521 	mov	a,_bp
      001690 24 10            [12] 4522 	add	a,#0x10
      001692 F8               [12] 4523 	mov	r0,a
      001693 86 82            [24] 4524 	mov	dpl, @r0
      001695 08               [12] 4525 	inc	r0
      001696 86 83            [24] 4526 	mov	dph, @r0
      001698 08               [12] 4527 	inc	r0
      001699 86 F0            [24] 4528 	mov	b, @r0
      00169B 08               [12] 4529 	inc	r0
      00169C E6               [12] 4530 	mov	a, @r0
      00169D 12 1E 3D         [24] 4531 	lcall	___fsadd
      0016A0 C8               [12] 4532 	xch	a,r0
      0016A1 E5 1D            [12] 4533 	mov	a,_bp
      0016A3 24 10            [12] 4534 	add	a,#0x10
      0016A5 C8               [12] 4535 	xch	a,r0
      0016A6 A6 82            [24] 4536 	mov	@r0, dpl
      0016A8 08               [12] 4537 	inc	r0
      0016A9 A6 83            [24] 4538 	mov	@r0, dph
      0016AB 08               [12] 4539 	inc	r0
      0016AC A6 F0            [24] 4540 	mov	@r0, b
      0016AE 08               [12] 4541 	inc	r0
      0016AF F6               [12] 4542 	mov	@r0,a
      0016B0 E5 81            [12] 4543 	mov	a,sp
      0016B2 24 FC            [12] 4544 	add	a,#0xfc
      0016B4 F5 81            [12] 4545 	mov	sp,a
      0016B6 E5 1D            [12] 4546 	mov	a,_bp
      0016B8 24 08            [12] 4547 	add	a,#0x08
      0016BA F8               [12] 4548 	mov	r0,a
      0016BB E6               [12] 4549 	mov	a,@r0
      0016BC C0 E0            [24] 4550 	push	acc
      0016BE 08               [12] 4551 	inc	r0
      0016BF E6               [12] 4552 	mov	a,@r0
      0016C0 C0 E0            [24] 4553 	push	acc
      0016C2 08               [12] 4554 	inc	r0
      0016C3 E6               [12] 4555 	mov	a,@r0
      0016C4 C0 E0            [24] 4556 	push	acc
      0016C6 08               [12] 4557 	inc	r0
      0016C7 E6               [12] 4558 	mov	a,@r0
      0016C8 C0 E0            [24] 4559 	push	acc
      0016CA E5 1D            [12] 4560 	mov	a,_bp
      0016CC 24 14            [12] 4561 	add	a,#0x14
      0016CE F8               [12] 4562 	mov	r0,a
      0016CF 86 82            [24] 4563 	mov	dpl, @r0
      0016D1 08               [12] 4564 	inc	r0
      0016D2 86 83            [24] 4565 	mov	dph, @r0
      0016D4 08               [12] 4566 	inc	r0
      0016D5 86 F0            [24] 4567 	mov	b, @r0
      0016D7 08               [12] 4568 	inc	r0
      0016D8 E6               [12] 4569 	mov	a, @r0
      0016D9 12 1E 0D         [24] 4570 	lcall	___fslt
      0016DC AF 82            [24] 4571 	mov	r7, dpl
      0016DE E5 81            [12] 4572 	mov	a,sp
      0016E0 24 FC            [12] 4573 	add	a,#0xfc
      0016E2 F5 81            [12] 4574 	mov	sp,a
      0016E4 D0 04            [24] 4575 	pop	ar4
      0016E6 D0 05            [24] 4576 	pop	ar5
      0016E8 EF               [12] 4577 	mov	a,r7
      0016E9 60 67            [24] 4578 	jz	00108$
                           001634  4579 	C$fuzzy.h$350$4_0$93 ==.
                                   4580 ;	../../fuzzy.h:350: maximum = height;
      0016EB E5 1D            [12] 4581 	mov	a,_bp
      0016ED 24 08            [12] 4582 	add	a,#0x08
      0016EF F8               [12] 4583 	mov	r0,a
      0016F0 E5 1D            [12] 4584 	mov	a,_bp
      0016F2 24 14            [12] 4585 	add	a,#0x14
      0016F4 F9               [12] 4586 	mov	r1,a
      0016F5 E6               [12] 4587 	mov	a,@r0
      0016F6 F7               [12] 4588 	mov	@r1,a
      0016F7 08               [12] 4589 	inc	r0
      0016F8 E6               [12] 4590 	mov	a,@r0
      0016F9 09               [12] 4591 	inc	r1
      0016FA F7               [12] 4592 	mov	@r1,a
      0016FB 08               [12] 4593 	inc	r0
      0016FC E6               [12] 4594 	mov	a,@r0
      0016FD 09               [12] 4595 	inc	r1
      0016FE F7               [12] 4596 	mov	@r1,a
      0016FF 08               [12] 4597 	inc	r0
      001700 E6               [12] 4598 	mov	a,@r0
      001701 09               [12] 4599 	inc	r1
      001702 F7               [12] 4600 	mov	@r1,a
                           00164C  4601 	C$fuzzy.h$351$4_0$93 ==.
                                   4602 ;	../../fuzzy.h:351: maximum_sum = x;
      001703 E5 1D            [12] 4603 	mov	a,_bp
      001705 24 04            [12] 4604 	add	a,#0x04
      001707 F8               [12] 4605 	mov	r0,a
      001708 E5 1D            [12] 4606 	mov	a,_bp
      00170A 24 18            [12] 4607 	add	a,#0x18
      00170C F9               [12] 4608 	mov	r1,a
      00170D E6               [12] 4609 	mov	a,@r0
      00170E F7               [12] 4610 	mov	@r1,a
      00170F 08               [12] 4611 	inc	r0
      001710 E6               [12] 4612 	mov	a,@r0
      001711 09               [12] 4613 	inc	r1
      001712 F7               [12] 4614 	mov	@r1,a
      001713 08               [12] 4615 	inc	r0
      001714 E6               [12] 4616 	mov	a,@r0
      001715 09               [12] 4617 	inc	r1
      001716 F7               [12] 4618 	mov	@r1,a
      001717 08               [12] 4619 	inc	r0
      001718 E6               [12] 4620 	mov	a,@r0
      001719 09               [12] 4621 	inc	r1
      00171A F7               [12] 4622 	mov	@r1,a
                           001664  4623 	C$fuzzy.h$352$4_0$93 ==.
                                   4624 ;	../../fuzzy.h:352: maximum_count = 1u;
      00171B 7D 01            [12] 4625 	mov	r5,#0x01
      00171D 7C 00            [12] 4626 	mov	r4,#0x00
                           001668  4627 	C$fuzzy.h$353$4_0$93 ==.
                                   4628 ;	../../fuzzy.h:353: smallest = x;
      00171F E5 1D            [12] 4629 	mov	a,_bp
      001721 24 04            [12] 4630 	add	a,#0x04
      001723 F8               [12] 4631 	mov	r0,a
      001724 E5 1D            [12] 4632 	mov	a,_bp
      001726 24 1C            [12] 4633 	add	a,#0x1c
      001728 F9               [12] 4634 	mov	r1,a
      001729 E6               [12] 4635 	mov	a,@r0
      00172A F7               [12] 4636 	mov	@r1,a
      00172B 08               [12] 4637 	inc	r0
      00172C E6               [12] 4638 	mov	a,@r0
      00172D 09               [12] 4639 	inc	r1
      00172E F7               [12] 4640 	mov	@r1,a
      00172F 08               [12] 4641 	inc	r0
      001730 E6               [12] 4642 	mov	a,@r0
      001731 09               [12] 4643 	inc	r1
      001732 F7               [12] 4644 	mov	@r1,a
      001733 08               [12] 4645 	inc	r0
      001734 E6               [12] 4646 	mov	a,@r0
      001735 09               [12] 4647 	inc	r1
      001736 F7               [12] 4648 	mov	@r1,a
                           001680  4649 	C$fuzzy.h$354$4_0$93 ==.
                                   4650 ;	../../fuzzy.h:354: largest = x;
      001737 E5 1D            [12] 4651 	mov	a,_bp
      001739 24 04            [12] 4652 	add	a,#0x04
      00173B F8               [12] 4653 	mov	r0,a
      00173C E5 1D            [12] 4654 	mov	a,_bp
      00173E 24 20            [12] 4655 	add	a,#0x20
      001740 F9               [12] 4656 	mov	r1,a
      001741 E6               [12] 4657 	mov	a,@r0
      001742 F7               [12] 4658 	mov	@r1,a
      001743 08               [12] 4659 	inc	r0
      001744 E6               [12] 4660 	mov	a,@r0
      001745 09               [12] 4661 	inc	r1
      001746 F7               [12] 4662 	mov	@r1,a
      001747 08               [12] 4663 	inc	r0
      001748 E6               [12] 4664 	mov	a,@r0
      001749 09               [12] 4665 	inc	r1
      00174A F7               [12] 4666 	mov	@r1,a
      00174B 08               [12] 4667 	inc	r0
      00174C E6               [12] 4668 	mov	a,@r0
      00174D 09               [12] 4669 	inc	r1
      00174E F7               [12] 4670 	mov	@r1,a
      00174F 02 17 EC         [24] 4671 	ljmp	00119$
      001752                       4672 00108$:
                           00169B  4673 	C$fuzzy.h$356$1_0$89 ==.
                                   4674 ;	../../fuzzy.h:356: else if (height == maximum) {
      001752 C0 05            [24] 4675 	push	ar5
      001754 C0 04            [24] 4676 	push	ar4
      001756 E5 1D            [12] 4677 	mov	a,_bp
      001758 24 14            [12] 4678 	add	a,#0x14
      00175A F8               [12] 4679 	mov	r0,a
      00175B E6               [12] 4680 	mov	a,@r0
      00175C C0 E0            [24] 4681 	push	acc
      00175E 08               [12] 4682 	inc	r0
      00175F E6               [12] 4683 	mov	a,@r0
      001760 C0 E0            [24] 4684 	push	acc
      001762 08               [12] 4685 	inc	r0
      001763 E6               [12] 4686 	mov	a,@r0
      001764 C0 E0            [24] 4687 	push	acc
      001766 08               [12] 4688 	inc	r0
      001767 E6               [12] 4689 	mov	a,@r0
      001768 C0 E0            [24] 4690 	push	acc
      00176A E5 1D            [12] 4691 	mov	a,_bp
      00176C 24 08            [12] 4692 	add	a,#0x08
      00176E F8               [12] 4693 	mov	r0,a
      00176F 86 82            [24] 4694 	mov	dpl, @r0
      001771 08               [12] 4695 	inc	r0
      001772 86 83            [24] 4696 	mov	dph, @r0
      001774 08               [12] 4697 	inc	r0
      001775 86 F0            [24] 4698 	mov	b, @r0
      001777 08               [12] 4699 	inc	r0
      001778 E6               [12] 4700 	mov	a, @r0
      001779 12 1D E1         [24] 4701 	lcall	___fseq
      00177C AF 82            [24] 4702 	mov	r7, dpl
      00177E E5 81            [12] 4703 	mov	a,sp
      001780 24 FC            [12] 4704 	add	a,#0xfc
      001782 F5 81            [12] 4705 	mov	sp,a
      001784 D0 04            [24] 4706 	pop	ar4
      001786 D0 05            [24] 4707 	pop	ar5
      001788 EF               [12] 4708 	mov	a,r7
      001789 60 61            [24] 4709 	jz	00119$
                           0016D4  4710 	C$fuzzy.h$357$1_0$89 ==.
                                   4711 ;	../../fuzzy.h:357: maximum_sum += x;
      00178B C0 05            [24] 4712 	push	ar5
      00178D C0 04            [24] 4713 	push	ar4
      00178F E5 1D            [12] 4714 	mov	a,_bp
      001791 24 04            [12] 4715 	add	a,#0x04
      001793 F8               [12] 4716 	mov	r0,a
      001794 E6               [12] 4717 	mov	a,@r0
      001795 C0 E0            [24] 4718 	push	acc
      001797 08               [12] 4719 	inc	r0
      001798 E6               [12] 4720 	mov	a,@r0
      001799 C0 E0            [24] 4721 	push	acc
      00179B 08               [12] 4722 	inc	r0
      00179C E6               [12] 4723 	mov	a,@r0
      00179D C0 E0            [24] 4724 	push	acc
      00179F 08               [12] 4725 	inc	r0
      0017A0 E6               [12] 4726 	mov	a,@r0
      0017A1 C0 E0            [24] 4727 	push	acc
                           0016EC  4728 	C$fuzzy.h$358$1_0$89 ==.
                                   4729 ;	../../fuzzy.h:358: ++maximum_count;
      0017A3 E5 1D            [12] 4730 	mov	a,_bp
      0017A5 24 18            [12] 4731 	add	a,#0x18
      0017A7 F8               [12] 4732 	mov	r0,a
      0017A8 86 82            [24] 4733 	mov	dpl, @r0
      0017AA 08               [12] 4734 	inc	r0
      0017AB 86 83            [24] 4735 	mov	dph, @r0
      0017AD 08               [12] 4736 	inc	r0
      0017AE 86 F0            [24] 4737 	mov	b, @r0
      0017B0 08               [12] 4738 	inc	r0
      0017B1 E6               [12] 4739 	mov	a, @r0
      0017B2 12 1E 3D         [24] 4740 	lcall	___fsadd
      0017B5 C8               [12] 4741 	xch	a,r0
      0017B6 E5 1D            [12] 4742 	mov	a,_bp
      0017B8 24 18            [12] 4743 	add	a,#0x18
      0017BA C8               [12] 4744 	xch	a,r0
      0017BB A6 82            [24] 4745 	mov	@r0, dpl
      0017BD 08               [12] 4746 	inc	r0
      0017BE A6 83            [24] 4747 	mov	@r0, dph
      0017C0 08               [12] 4748 	inc	r0
      0017C1 A6 F0            [24] 4749 	mov	@r0, b
      0017C3 08               [12] 4750 	inc	r0
      0017C4 F6               [12] 4751 	mov	@r0,a
      0017C5 E5 81            [12] 4752 	mov	a,sp
      0017C7 24 FC            [12] 4753 	add	a,#0xfc
      0017C9 F5 81            [12] 4754 	mov	sp,a
      0017CB D0 04            [24] 4755 	pop	ar4
      0017CD D0 05            [24] 4756 	pop	ar5
      0017CF 0D               [12] 4757 	inc	r5
      0017D0 BD 00 01         [24] 4758 	cjne	r5,#0x00,00214$
      0017D3 0C               [12] 4759 	inc	r4
      0017D4                       4760 00214$:
                           00171D  4761 	C$fuzzy.h$359$4_0$94 ==.
                                   4762 ;	../../fuzzy.h:359: largest = x;
      0017D4 E5 1D            [12] 4763 	mov	a,_bp
      0017D6 24 04            [12] 4764 	add	a,#0x04
      0017D8 F8               [12] 4765 	mov	r0,a
      0017D9 E5 1D            [12] 4766 	mov	a,_bp
      0017DB 24 20            [12] 4767 	add	a,#0x20
      0017DD F9               [12] 4768 	mov	r1,a
      0017DE E6               [12] 4769 	mov	a,@r0
      0017DF F7               [12] 4770 	mov	@r1,a
      0017E0 08               [12] 4771 	inc	r0
      0017E1 E6               [12] 4772 	mov	a,@r0
      0017E2 09               [12] 4773 	inc	r1
      0017E3 F7               [12] 4774 	mov	@r1,a
      0017E4 08               [12] 4775 	inc	r0
      0017E5 E6               [12] 4776 	mov	a,@r0
      0017E6 09               [12] 4777 	inc	r1
      0017E7 F7               [12] 4778 	mov	@r1,a
      0017E8 08               [12] 4779 	inc	r0
      0017E9 E6               [12] 4780 	mov	a,@r0
      0017EA 09               [12] 4781 	inc	r1
      0017EB F7               [12] 4782 	mov	@r1,a
      0017EC                       4783 00119$:
                           001735  4784 	C$fuzzy.h$343$1_0$89 ==.
                                   4785 ;	../../fuzzy.h:343: for (x = lower; x <= upper; x += step) {
      0017EC C0 05            [24] 4786 	push	ar5
      0017EE C0 04            [24] 4787 	push	ar4
      0017F0 E5 1D            [12] 4788 	mov	a,_bp
      0017F2 24 F2            [12] 4789 	add	a,#0xf2
      0017F4 F8               [12] 4790 	mov	r0,a
      0017F5 E6               [12] 4791 	mov	a,@r0
      0017F6 C0 E0            [24] 4792 	push	acc
      0017F8 08               [12] 4793 	inc	r0
      0017F9 E6               [12] 4794 	mov	a,@r0
      0017FA C0 E0            [24] 4795 	push	acc
      0017FC 08               [12] 4796 	inc	r0
      0017FD E6               [12] 4797 	mov	a,@r0
      0017FE C0 E0            [24] 4798 	push	acc
      001800 08               [12] 4799 	inc	r0
      001801 E6               [12] 4800 	mov	a,@r0
      001802 C0 E0            [24] 4801 	push	acc
      001804 E5 1D            [12] 4802 	mov	a,_bp
      001806 24 04            [12] 4803 	add	a,#0x04
      001808 F8               [12] 4804 	mov	r0,a
      001809 86 82            [24] 4805 	mov	dpl, @r0
      00180B 08               [12] 4806 	inc	r0
      00180C 86 83            [24] 4807 	mov	dph, @r0
      00180E 08               [12] 4808 	inc	r0
      00180F 86 F0            [24] 4809 	mov	b, @r0
      001811 08               [12] 4810 	inc	r0
      001812 E6               [12] 4811 	mov	a, @r0
      001813 12 1E 3D         [24] 4812 	lcall	___fsadd
      001816 C8               [12] 4813 	xch	a,r0
      001817 E5 1D            [12] 4814 	mov	a,_bp
      001819 24 04            [12] 4815 	add	a,#0x04
      00181B C8               [12] 4816 	xch	a,r0
      00181C A6 82            [24] 4817 	mov	@r0, dpl
      00181E 08               [12] 4818 	inc	r0
      00181F A6 83            [24] 4819 	mov	@r0, dph
      001821 08               [12] 4820 	inc	r0
      001822 A6 F0            [24] 4821 	mov	@r0, b
      001824 08               [12] 4822 	inc	r0
      001825 F6               [12] 4823 	mov	@r0,a
      001826 E5 81            [12] 4824 	mov	a,sp
      001828 24 FC            [12] 4825 	add	a,#0xfc
      00182A F5 81            [12] 4826 	mov	sp,a
      00182C D0 04            [24] 4827 	pop	ar4
      00182E D0 05            [24] 4828 	pop	ar5
      001830 02 15 9C         [24] 4829 	ljmp	00118$
      001833                       4830 00110$:
                           00177C  4831 	C$fuzzy.h$363$1_0$89 ==.
                                   4832 ;	../../fuzzy.h:363: if (method == FUZZY_DEFUZZ_MOM) {
      001833 E5 1D            [12] 4833 	mov	a,_bp
      001835 24 F1            [12] 4834 	add	a,#0xf1
      001837 F8               [12] 4835 	mov	r0,a
      001838 B6 03 02         [24] 4836 	cjne	@r0,#0x03,00215$
      00183B 80 02            [24] 4837 	sjmp	00216$
      00183D                       4838 00215$:
      00183D 80 79            [24] 4839 	sjmp	00112$
      00183F                       4840 00216$:
                           001788  4841 	C$fuzzy.h$364$1_0$89 ==.
                                   4842 ;	../../fuzzy.h:364: return maximum > 0.0f ? maximum_sum / (float)maximum_count : 0.0f;
      00183F C0 05            [24] 4843 	push	ar5
      001841 C0 04            [24] 4844 	push	ar4
      001843 E5 1D            [12] 4845 	mov	a,_bp
      001845 24 14            [12] 4846 	add	a,#0x14
      001847 F8               [12] 4847 	mov	r0,a
      001848 E6               [12] 4848 	mov	a,@r0
      001849 C0 E0            [24] 4849 	push	acc
      00184B 08               [12] 4850 	inc	r0
      00184C E6               [12] 4851 	mov	a,@r0
      00184D C0 E0            [24] 4852 	push	acc
      00184F 08               [12] 4853 	inc	r0
      001850 E6               [12] 4854 	mov	a,@r0
      001851 C0 E0            [24] 4855 	push	acc
      001853 08               [12] 4856 	inc	r0
      001854 E6               [12] 4857 	mov	a,@r0
      001855 C0 E0            [24] 4858 	push	acc
      001857 90 00 00         [24] 4859 	mov	dptr,#0x0000
      00185A E4               [12] 4860 	clr	a
      00185B F5 F0            [12] 4861 	mov	b,a
      00185D 12 1E 0D         [24] 4862 	lcall	___fslt
      001860 AF 82            [24] 4863 	mov	r7, dpl
      001862 E5 81            [12] 4864 	mov	a,sp
      001864 24 FC            [12] 4865 	add	a,#0xfc
      001866 F5 81            [12] 4866 	mov	sp,a
      001868 D0 04            [24] 4867 	pop	ar4
      00186A D0 05            [24] 4868 	pop	ar5
      00186C EF               [12] 4869 	mov	a,r7
      00186D 60 37            [24] 4870 	jz	00122$
      00186F 8D 82            [24] 4871 	mov	dpl, r5
      001871 8C 83            [24] 4872 	mov	dph, r4
      001873 12 1E DF         [24] 4873 	lcall	___uint2fs
      001876 AC 82            [24] 4874 	mov	r4, dpl
      001878 AD 83            [24] 4875 	mov	r5, dph
      00187A AE F0            [24] 4876 	mov	r6, b
      00187C FF               [12] 4877 	mov	r7, a
      00187D C0 04            [24] 4878 	push	ar4
      00187F C0 05            [24] 4879 	push	ar5
      001881 C0 06            [24] 4880 	push	ar6
      001883 C0 07            [24] 4881 	push	ar7
      001885 E5 1D            [12] 4882 	mov	a,_bp
      001887 24 18            [12] 4883 	add	a,#0x18
      001889 F8               [12] 4884 	mov	r0,a
      00188A 86 82            [24] 4885 	mov	dpl, @r0
      00188C 08               [12] 4886 	inc	r0
      00188D 86 83            [24] 4887 	mov	dph, @r0
      00188F 08               [12] 4888 	inc	r0
      001890 86 F0            [24] 4889 	mov	b, @r0
      001892 08               [12] 4890 	inc	r0
      001893 E6               [12] 4891 	mov	a, @r0
      001894 12 1F 54         [24] 4892 	lcall	___fsdiv
      001897 AC 82            [24] 4893 	mov	r4, dpl
      001899 AD 83            [24] 4894 	mov	r5, dph
      00189B AE F0            [24] 4895 	mov	r6, b
      00189D FF               [12] 4896 	mov	r7, a
      00189E E5 81            [12] 4897 	mov	a,sp
      0018A0 24 FC            [12] 4898 	add	a,#0xfc
      0018A2 F5 81            [12] 4899 	mov	sp,a
      0018A4 80 08            [24] 4900 	sjmp	00123$
      0018A6                       4901 00122$:
      0018A6 7C 00            [12] 4902 	mov	r4,#0x00
      0018A8 7D 00            [12] 4903 	mov	r5,#0x00
      0018AA 7E 00            [12] 4904 	mov	r6,#0x00
      0018AC 7F 00            [12] 4905 	mov	r7,#0x00
      0018AE                       4906 00123$:
      0018AE 8C 82            [24] 4907 	mov	dpl, r4
      0018B0 8D 83            [24] 4908 	mov	dph, r5
      0018B2 8E F0            [24] 4909 	mov	b, r6
      0018B4 EF               [12] 4910 	mov	a, r7
      0018B5 02 19 CB         [24] 4911 	ljmp	00120$
      0018B8                       4912 00112$:
                           001801  4913 	C$fuzzy.h$367$1_0$89 ==.
                                   4914 ;	../../fuzzy.h:367: if (method == FUZZY_DEFUZZ_SOM) {
      0018B8 E5 1D            [12] 4915 	mov	a,_bp
      0018BA 24 F1            [12] 4916 	add	a,#0xf1
      0018BC F8               [12] 4917 	mov	r0,a
      0018BD B6 04 4C         [24] 4918 	cjne	@r0,#0x04,00114$
                           001809  4919 	C$fuzzy.h$368$1_0$89 ==.
                                   4920 ;	../../fuzzy.h:368: return maximum > 0.0f ? smallest : 0.0f;
      0018C0 E5 1D            [12] 4921 	mov	a,_bp
      0018C2 24 14            [12] 4922 	add	a,#0x14
      0018C4 F8               [12] 4923 	mov	r0,a
      0018C5 E6               [12] 4924 	mov	a,@r0
      0018C6 C0 E0            [24] 4925 	push	acc
      0018C8 08               [12] 4926 	inc	r0
      0018C9 E6               [12] 4927 	mov	a,@r0
      0018CA C0 E0            [24] 4928 	push	acc
      0018CC 08               [12] 4929 	inc	r0
      0018CD E6               [12] 4930 	mov	a,@r0
      0018CE C0 E0            [24] 4931 	push	acc
      0018D0 08               [12] 4932 	inc	r0
      0018D1 E6               [12] 4933 	mov	a,@r0
      0018D2 C0 E0            [24] 4934 	push	acc
      0018D4 90 00 00         [24] 4935 	mov	dptr,#0x0000
      0018D7 E4               [12] 4936 	clr	a
      0018D8 F5 F0            [12] 4937 	mov	b,a
      0018DA 12 1E 0D         [24] 4938 	lcall	___fslt
      0018DD AF 82            [24] 4939 	mov	r7, dpl
      0018DF E5 81            [12] 4940 	mov	a,sp
      0018E1 24 FC            [12] 4941 	add	a,#0xfc
      0018E3 F5 81            [12] 4942 	mov	sp,a
      0018E5 EF               [12] 4943 	mov	a,r7
      0018E6 60 12            [24] 4944 	jz	00124$
      0018E8 E5 1D            [12] 4945 	mov	a,_bp
      0018EA 24 1C            [12] 4946 	add	a,#0x1c
      0018EC F8               [12] 4947 	mov	r0,a
      0018ED 86 04            [24] 4948 	mov	ar4,@r0
      0018EF 08               [12] 4949 	inc	r0
      0018F0 86 05            [24] 4950 	mov	ar5,@r0
      0018F2 08               [12] 4951 	inc	r0
      0018F3 86 06            [24] 4952 	mov	ar6,@r0
      0018F5 08               [12] 4953 	inc	r0
      0018F6 86 07            [24] 4954 	mov	ar7,@r0
      0018F8 80 08            [24] 4955 	sjmp	00125$
      0018FA                       4956 00124$:
      0018FA 7C 00            [12] 4957 	mov	r4,#0x00
      0018FC 7D 00            [12] 4958 	mov	r5,#0x00
      0018FE 7E 00            [12] 4959 	mov	r6,#0x00
      001900 7F 00            [12] 4960 	mov	r7,#0x00
      001902                       4961 00125$:
      001902 8C 82            [24] 4962 	mov	dpl, r4
      001904 8D 83            [24] 4963 	mov	dph, r5
      001906 8E F0            [24] 4964 	mov	b, r6
      001908 EF               [12] 4965 	mov	a, r7
      001909 02 19 CB         [24] 4966 	ljmp	00120$
      00190C                       4967 00114$:
                           001855  4968 	C$fuzzy.h$371$1_0$89 ==.
                                   4969 ;	../../fuzzy.h:371: if (method == FUZZY_DEFUZZ_LOM) {
      00190C E5 1D            [12] 4970 	mov	a,_bp
      00190E 24 F1            [12] 4971 	add	a,#0xf1
      001910 F8               [12] 4972 	mov	r0,a
      001911 B6 05 4B         [24] 4973 	cjne	@r0,#0x05,00116$
                           00185D  4974 	C$fuzzy.h$372$1_0$89 ==.
                                   4975 ;	../../fuzzy.h:372: return maximum > 0.0f ? largest : 0.0f;
      001914 E5 1D            [12] 4976 	mov	a,_bp
      001916 24 14            [12] 4977 	add	a,#0x14
      001918 F8               [12] 4978 	mov	r0,a
      001919 E6               [12] 4979 	mov	a,@r0
      00191A C0 E0            [24] 4980 	push	acc
      00191C 08               [12] 4981 	inc	r0
      00191D E6               [12] 4982 	mov	a,@r0
      00191E C0 E0            [24] 4983 	push	acc
      001920 08               [12] 4984 	inc	r0
      001921 E6               [12] 4985 	mov	a,@r0
      001922 C0 E0            [24] 4986 	push	acc
      001924 08               [12] 4987 	inc	r0
      001925 E6               [12] 4988 	mov	a,@r0
      001926 C0 E0            [24] 4989 	push	acc
      001928 90 00 00         [24] 4990 	mov	dptr,#0x0000
      00192B E4               [12] 4991 	clr	a
      00192C F5 F0            [12] 4992 	mov	b,a
      00192E 12 1E 0D         [24] 4993 	lcall	___fslt
      001931 AF 82            [24] 4994 	mov	r7, dpl
      001933 E5 81            [12] 4995 	mov	a,sp
      001935 24 FC            [12] 4996 	add	a,#0xfc
      001937 F5 81            [12] 4997 	mov	sp,a
      001939 EF               [12] 4998 	mov	a,r7
      00193A 60 12            [24] 4999 	jz	00126$
      00193C E5 1D            [12] 5000 	mov	a,_bp
      00193E 24 20            [12] 5001 	add	a,#0x20
      001940 F8               [12] 5002 	mov	r0,a
      001941 86 04            [24] 5003 	mov	ar4,@r0
      001943 08               [12] 5004 	inc	r0
      001944 86 05            [24] 5005 	mov	ar5,@r0
      001946 08               [12] 5006 	inc	r0
      001947 86 06            [24] 5007 	mov	ar6,@r0
      001949 08               [12] 5008 	inc	r0
      00194A 86 07            [24] 5009 	mov	ar7,@r0
      00194C 80 08            [24] 5010 	sjmp	00127$
      00194E                       5011 00126$:
      00194E 7C 00            [12] 5012 	mov	r4,#0x00
      001950 7D 00            [12] 5013 	mov	r5,#0x00
      001952 7E 00            [12] 5014 	mov	r6,#0x00
      001954 7F 00            [12] 5015 	mov	r7,#0x00
      001956                       5016 00127$:
      001956 8C 82            [24] 5017 	mov	dpl, r4
      001958 8D 83            [24] 5018 	mov	dph, r5
      00195A 8E F0            [24] 5019 	mov	b, r6
      00195C EF               [12] 5020 	mov	a, r7
      00195D 80 6C            [24] 5021 	sjmp	00120$
      00195F                       5022 00116$:
                           0018A8  5023 	C$fuzzy.h$375$1_0$89 ==.
                                   5024 ;	../../fuzzy.h:375: return sum > 0.0f ? weighted / sum : 0.0f;
      00195F E5 1D            [12] 5025 	mov	a,_bp
      001961 24 10            [12] 5026 	add	a,#0x10
      001963 F8               [12] 5027 	mov	r0,a
      001964 E6               [12] 5028 	mov	a,@r0
      001965 C0 E0            [24] 5029 	push	acc
      001967 08               [12] 5030 	inc	r0
      001968 E6               [12] 5031 	mov	a,@r0
      001969 C0 E0            [24] 5032 	push	acc
      00196B 08               [12] 5033 	inc	r0
      00196C E6               [12] 5034 	mov	a,@r0
      00196D C0 E0            [24] 5035 	push	acc
      00196F 08               [12] 5036 	inc	r0
      001970 E6               [12] 5037 	mov	a,@r0
      001971 C0 E0            [24] 5038 	push	acc
      001973 90 00 00         [24] 5039 	mov	dptr,#0x0000
      001976 E4               [12] 5040 	clr	a
      001977 F5 F0            [12] 5041 	mov	b,a
      001979 12 1E 0D         [24] 5042 	lcall	___fslt
      00197C AF 82            [24] 5043 	mov	r7, dpl
      00197E E5 81            [12] 5044 	mov	a,sp
      001980 24 FC            [12] 5045 	add	a,#0xfc
      001982 F5 81            [12] 5046 	mov	sp,a
      001984 EF               [12] 5047 	mov	a,r7
      001985 60 35            [24] 5048 	jz	00128$
      001987 E5 1D            [12] 5049 	mov	a,_bp
      001989 24 10            [12] 5050 	add	a,#0x10
      00198B F8               [12] 5051 	mov	r0,a
      00198C E6               [12] 5052 	mov	a,@r0
      00198D C0 E0            [24] 5053 	push	acc
      00198F 08               [12] 5054 	inc	r0
      001990 E6               [12] 5055 	mov	a,@r0
      001991 C0 E0            [24] 5056 	push	acc
      001993 08               [12] 5057 	inc	r0
      001994 E6               [12] 5058 	mov	a,@r0
      001995 C0 E0            [24] 5059 	push	acc
      001997 08               [12] 5060 	inc	r0
      001998 E6               [12] 5061 	mov	a,@r0
      001999 C0 E0            [24] 5062 	push	acc
      00199B E5 1D            [12] 5063 	mov	a,_bp
      00199D 24 0C            [12] 5064 	add	a,#0x0c
      00199F F8               [12] 5065 	mov	r0,a
      0019A0 86 82            [24] 5066 	mov	dpl, @r0
      0019A2 08               [12] 5067 	inc	r0
      0019A3 86 83            [24] 5068 	mov	dph, @r0
      0019A5 08               [12] 5069 	inc	r0
      0019A6 86 F0            [24] 5070 	mov	b, @r0
      0019A8 08               [12] 5071 	inc	r0
      0019A9 E6               [12] 5072 	mov	a, @r0
      0019AA 12 1F 54         [24] 5073 	lcall	___fsdiv
      0019AD AC 82            [24] 5074 	mov	r4, dpl
      0019AF AD 83            [24] 5075 	mov	r5, dph
      0019B1 AE F0            [24] 5076 	mov	r6, b
      0019B3 FF               [12] 5077 	mov	r7, a
      0019B4 E5 81            [12] 5078 	mov	a,sp
      0019B6 24 FC            [12] 5079 	add	a,#0xfc
      0019B8 F5 81            [12] 5080 	mov	sp,a
      0019BA 80 08            [24] 5081 	sjmp	00129$
      0019BC                       5082 00128$:
      0019BC 7C 00            [12] 5083 	mov	r4,#0x00
      0019BE 7D 00            [12] 5084 	mov	r5,#0x00
      0019C0 7E 00            [12] 5085 	mov	r6,#0x00
      0019C2 7F 00            [12] 5086 	mov	r7,#0x00
      0019C4                       5087 00129$:
      0019C4 8C 82            [24] 5088 	mov	dpl, r4
      0019C6 8D 83            [24] 5089 	mov	dph, r5
      0019C8 8E F0            [24] 5090 	mov	b, r6
      0019CA EF               [12] 5091 	mov	a, r7
      0019CB                       5092 00120$:
                           001914  5093 	C$fuzzy.h$376$1_0$89 ==.
                                   5094 ;	../../fuzzy.h:376: }
      0019CB 85 1D 81         [24] 5095 	mov	sp,_bp
      0019CE D0 1D            [24] 5096 	pop	_bp
                           001919  5097 	C$fuzzy.h$376$1_0$89 ==.
                           001919  5098 	XG$fuzzy_rules_defuzzify$0$0 ==.
      0019D0 22               [24] 5099 	ret
                                   5100 ;------------------------------------------------------------
                                   5101 ;Allocation info for local variables in function 'fuzzy_rules_cog'
                                   5102 ;------------------------------------------------------------
                                   5103 ;lower         Allocated to stack - _bp -6 +4 
                                   5104 ;upper         Allocated to stack - _bp -10 +4 
                                   5105 ;step          Allocated to stack - _bp -14 +4 
                                   5106 ;rules         Allocated to registers r5 r6 r7 
                                   5107 ;------------------------------------------------------------
                           00191A  5108 	G$fuzzy_rules_cog$0$0 ==.
                           00191A  5109 	C$fuzzy.h$378$1_0$99 ==.
                                   5110 ;	../../fuzzy.h:378: float fuzzy_rules_cog(const fuzzy_rules_t *rules, float lower, float upper, float step)
                                   5111 ;	-----------------------------------------
                                   5112 ;	 function fuzzy_rules_cog
                                   5113 ;	-----------------------------------------
      0019D1                       5114 _fuzzy_rules_cog:
      0019D1 C0 1D            [24] 5115 	push	_bp
      0019D3 85 81 1D         [24] 5116 	mov	_bp,sp
      0019D6 AD 82            [24] 5117 	mov	r5, dpl
      0019D8 AE 83            [24] 5118 	mov	r6, dph
      0019DA AF F0            [24] 5119 	mov	r7, b
                           001925  5120 	C$fuzzy.h$380$1_0$99 ==.
                                   5121 ;	../../fuzzy.h:380: return fuzzy_rules_defuzzify(rules, lower, upper, step, FUZZY_DEFUZZ_COG);
      0019DC E4               [12] 5122 	clr	a
      0019DD C0 E0            [24] 5123 	push	acc
      0019DF E5 1D            [12] 5124 	mov	a,_bp
      0019E1 24 F2            [12] 5125 	add	a,#0xf2
      0019E3 F8               [12] 5126 	mov	r0,a
      0019E4 E6               [12] 5127 	mov	a,@r0
      0019E5 C0 E0            [24] 5128 	push	acc
      0019E7 08               [12] 5129 	inc	r0
      0019E8 E6               [12] 5130 	mov	a,@r0
      0019E9 C0 E0            [24] 5131 	push	acc
      0019EB 08               [12] 5132 	inc	r0
      0019EC E6               [12] 5133 	mov	a,@r0
      0019ED C0 E0            [24] 5134 	push	acc
      0019EF 08               [12] 5135 	inc	r0
      0019F0 E6               [12] 5136 	mov	a,@r0
      0019F1 C0 E0            [24] 5137 	push	acc
      0019F3 E5 1D            [12] 5138 	mov	a,_bp
      0019F5 24 F6            [12] 5139 	add	a,#0xf6
      0019F7 F8               [12] 5140 	mov	r0,a
      0019F8 E6               [12] 5141 	mov	a,@r0
      0019F9 C0 E0            [24] 5142 	push	acc
      0019FB 08               [12] 5143 	inc	r0
      0019FC E6               [12] 5144 	mov	a,@r0
      0019FD C0 E0            [24] 5145 	push	acc
      0019FF 08               [12] 5146 	inc	r0
      001A00 E6               [12] 5147 	mov	a,@r0
      001A01 C0 E0            [24] 5148 	push	acc
      001A03 08               [12] 5149 	inc	r0
      001A04 E6               [12] 5150 	mov	a,@r0
      001A05 C0 E0            [24] 5151 	push	acc
      001A07 E5 1D            [12] 5152 	mov	a,_bp
      001A09 24 FA            [12] 5153 	add	a,#0xfa
      001A0B F8               [12] 5154 	mov	r0,a
      001A0C E6               [12] 5155 	mov	a,@r0
      001A0D C0 E0            [24] 5156 	push	acc
      001A0F 08               [12] 5157 	inc	r0
      001A10 E6               [12] 5158 	mov	a,@r0
      001A11 C0 E0            [24] 5159 	push	acc
      001A13 08               [12] 5160 	inc	r0
      001A14 E6               [12] 5161 	mov	a,@r0
      001A15 C0 E0            [24] 5162 	push	acc
      001A17 08               [12] 5163 	inc	r0
      001A18 E6               [12] 5164 	mov	a,@r0
      001A19 C0 E0            [24] 5165 	push	acc
      001A1B 8D 82            [24] 5166 	mov	dpl, r5
      001A1D 8E 83            [24] 5167 	mov	dph, r6
      001A1F 8F F0            [24] 5168 	mov	b, r7
      001A21 12 14 8D         [24] 5169 	lcall	_fuzzy_rules_defuzzify
      001A24 AC 82            [24] 5170 	mov	r4, dpl
      001A26 AD 83            [24] 5171 	mov	r5, dph
      001A28 AE F0            [24] 5172 	mov	r6, b
      001A2A FF               [12] 5173 	mov	r7, a
      001A2B E5 81            [12] 5174 	mov	a,sp
      001A2D 24 F3            [12] 5175 	add	a,#0xf3
      001A2F F5 81            [12] 5176 	mov	sp,a
      001A31 8C 82            [24] 5177 	mov	dpl, r4
      001A33 8D 83            [24] 5178 	mov	dph, r5
      001A35 8E F0            [24] 5179 	mov	b, r6
      001A37 EF               [12] 5180 	mov	a, r7
                           001981  5181 	C$fuzzy.h$381$1_0$99 ==.
                                   5182 ;	../../fuzzy.h:381: }
      001A38 D0 1D            [24] 5183 	pop	_bp
                           001983  5184 	C$fuzzy.h$381$1_0$99 ==.
                           001983  5185 	XG$fuzzy_rules_cog$0$0 ==.
      001A3A 22               [24] 5186 	ret
                                   5187 ;------------------------------------------------------------
                                   5188 ;Allocation info for local variables in function 'temperature_low'
                                   5189 ;------------------------------------------------------------
                                   5190 ;x             Allocated to registers r4 r5 r6 r7 
                                   5191 ;------------------------------------------------------------
                           001984  5192 	Fcontroller_8051$temperature_low$0$0 ==.
                           001984  5193 	C$controller_8051.c$29$1_0$101 ==.
                                   5194 ;	../../controller_8051.c:29: FUZZY_VAR(temperature_low, FUZZY_SHAPE_RAMP, HEDGE_NONE, 20.0f, 40.0f, false)
                                   5195 ;	-----------------------------------------
                                   5196 ;	 function temperature_low
                                   5197 ;	-----------------------------------------
      001A3B                       5198 _temperature_low:
      001A3B AC 82            [24] 5199 	mov	r4,dpl
      001A3D AD 83            [24] 5200 	mov	r5,dph
      001A3F AE F0            [24] 5201 	mov	r6,b
      001A41 FF               [12] 5202 	mov	r7,a
      001A42 C0 04            [24] 5203 	push	ar4
      001A44 C0 05            [24] 5204 	push	ar5
      001A46 C0 06            [24] 5205 	push	ar6
      001A48 C0 07            [24] 5206 	push	ar7
      001A4A 90 20 D9         [24] 5207 	mov	dptr,#_temperature_low_fuzzy_variable
      001A4D 75 F0 80         [24] 5208 	mov	b, #0x80
      001A50 12 0E 5F         [24] 5209 	lcall	_fuzzy_8051_eval
      001A53 AC 82            [24] 5210 	mov	r4, dpl
      001A55 AD 83            [24] 5211 	mov	r5, dph
      001A57 AE F0            [24] 5212 	mov	r6, b
      001A59 FF               [12] 5213 	mov	r7, a
      001A5A E5 81            [12] 5214 	mov	a,sp
      001A5C 24 FC            [12] 5215 	add	a,#0xfc
      001A5E F5 81            [12] 5216 	mov	sp,a
      001A60 8C 82            [24] 5217 	mov	dpl, r4
      001A62 8D 83            [24] 5218 	mov	dph, r5
      001A64 8E F0            [24] 5219 	mov	b, r6
      001A66 EF               [12] 5220 	mov	a, r7
                           0019B0  5221 	C$controller_8051.c$29$1_0$101 ==.
                           0019B0  5222 	XFcontroller_8051$temperature_low$0$0 ==.
      001A67 22               [24] 5223 	ret
                                   5224 ;------------------------------------------------------------
                                   5225 ;Allocation info for local variables in function 'temperature_high'
                                   5226 ;------------------------------------------------------------
                                   5227 ;x             Allocated to registers r4 r5 r6 r7 
                                   5228 ;------------------------------------------------------------
                           0019B1  5229 	Fcontroller_8051$temperature_high$0$0 ==.
                           0019B1  5230 	C$controller_8051.c$30$1_0$103 ==.
                                   5231 ;	../../controller_8051.c:30: FUZZY_VAR(temperature_high, FUZZY_SHAPE_RAMP, HEDGE_NONE, 30.0f, 60.0f, true)
                                   5232 ;	-----------------------------------------
                                   5233 ;	 function temperature_high
                                   5234 ;	-----------------------------------------
      001A68                       5235 _temperature_high:
      001A68 AC 82            [24] 5236 	mov	r4,dpl
      001A6A AD 83            [24] 5237 	mov	r5,dph
      001A6C AE F0            [24] 5238 	mov	r6,b
      001A6E FF               [12] 5239 	mov	r7,a
      001A6F C0 04            [24] 5240 	push	ar4
      001A71 C0 05            [24] 5241 	push	ar5
      001A73 C0 06            [24] 5242 	push	ar6
      001A75 C0 07            [24] 5243 	push	ar7
      001A77 90 20 EB         [24] 5244 	mov	dptr,#_temperature_high_fuzzy_variable
      001A7A 75 F0 80         [24] 5245 	mov	b, #0x80
      001A7D 12 0E 5F         [24] 5246 	lcall	_fuzzy_8051_eval
      001A80 AC 82            [24] 5247 	mov	r4, dpl
      001A82 AD 83            [24] 5248 	mov	r5, dph
      001A84 AE F0            [24] 5249 	mov	r6, b
      001A86 FF               [12] 5250 	mov	r7, a
      001A87 E5 81            [12] 5251 	mov	a,sp
      001A89 24 FC            [12] 5252 	add	a,#0xfc
      001A8B F5 81            [12] 5253 	mov	sp,a
      001A8D 8C 82            [24] 5254 	mov	dpl, r4
      001A8F 8D 83            [24] 5255 	mov	dph, r5
      001A91 8E F0            [24] 5256 	mov	b, r6
      001A93 EF               [12] 5257 	mov	a, r7
                           0019DD  5258 	C$controller_8051.c$30$1_0$103 ==.
                           0019DD  5259 	XFcontroller_8051$temperature_high$0$0 ==.
      001A94 22               [24] 5260 	ret
                                   5261 ;------------------------------------------------------------
                                   5262 ;Allocation info for local variables in function 'fan_slow'
                                   5263 ;------------------------------------------------------------
                                   5264 ;x             Allocated to registers r4 r5 r6 r7 
                                   5265 ;------------------------------------------------------------
                           0019DE  5266 	Fcontroller_8051$fan_slow$0$0 ==.
                           0019DE  5267 	C$controller_8051.c$31$1_0$105 ==.
                                   5268 ;	../../controller_8051.c:31: FUZZY_VAR(fan_slow, FUZZY_SHAPE_RAMP, HEDGE_NONE, 20.0f, 50.0f, false)
                                   5269 ;	-----------------------------------------
                                   5270 ;	 function fan_slow
                                   5271 ;	-----------------------------------------
      001A95                       5272 _fan_slow:
      001A95 AC 82            [24] 5273 	mov	r4,dpl
      001A97 AD 83            [24] 5274 	mov	r5,dph
      001A99 AE F0            [24] 5275 	mov	r6,b
      001A9B FF               [12] 5276 	mov	r7,a
      001A9C C0 04            [24] 5277 	push	ar4
      001A9E C0 05            [24] 5278 	push	ar5
      001AA0 C0 06            [24] 5279 	push	ar6
      001AA2 C0 07            [24] 5280 	push	ar7
      001AA4 90 20 FD         [24] 5281 	mov	dptr,#_fan_slow_fuzzy_variable
      001AA7 75 F0 80         [24] 5282 	mov	b, #0x80
      001AAA 12 0E 5F         [24] 5283 	lcall	_fuzzy_8051_eval
      001AAD AC 82            [24] 5284 	mov	r4, dpl
      001AAF AD 83            [24] 5285 	mov	r5, dph
      001AB1 AE F0            [24] 5286 	mov	r6, b
      001AB3 FF               [12] 5287 	mov	r7, a
      001AB4 E5 81            [12] 5288 	mov	a,sp
      001AB6 24 FC            [12] 5289 	add	a,#0xfc
      001AB8 F5 81            [12] 5290 	mov	sp,a
      001ABA 8C 82            [24] 5291 	mov	dpl, r4
      001ABC 8D 83            [24] 5292 	mov	dph, r5
      001ABE 8E F0            [24] 5293 	mov	b, r6
      001AC0 EF               [12] 5294 	mov	a, r7
                           001A0A  5295 	C$controller_8051.c$31$1_0$105 ==.
                           001A0A  5296 	XFcontroller_8051$fan_slow$0$0 ==.
      001AC1 22               [24] 5297 	ret
                                   5298 ;------------------------------------------------------------
                                   5299 ;Allocation info for local variables in function 'fan_fast'
                                   5300 ;------------------------------------------------------------
                                   5301 ;x             Allocated to registers r4 r5 r6 r7 
                                   5302 ;------------------------------------------------------------
                           001A0B  5303 	Fcontroller_8051$fan_fast$0$0 ==.
                           001A0B  5304 	C$controller_8051.c$32$1_0$107 ==.
                                   5305 ;	../../controller_8051.c:32: FUZZY_VAR(fan_fast, FUZZY_SHAPE_RAMP, HEDGE_NONE, 40.0f, 80.0f, true)
                                   5306 ;	-----------------------------------------
                                   5307 ;	 function fan_fast
                                   5308 ;	-----------------------------------------
      001AC2                       5309 _fan_fast:
      001AC2 AC 82            [24] 5310 	mov	r4,dpl
      001AC4 AD 83            [24] 5311 	mov	r5,dph
      001AC6 AE F0            [24] 5312 	mov	r6,b
      001AC8 FF               [12] 5313 	mov	r7,a
      001AC9 C0 04            [24] 5314 	push	ar4
      001ACB C0 05            [24] 5315 	push	ar5
      001ACD C0 06            [24] 5316 	push	ar6
      001ACF C0 07            [24] 5317 	push	ar7
      001AD1 90 21 0F         [24] 5318 	mov	dptr,#_fan_fast_fuzzy_variable
      001AD4 75 F0 80         [24] 5319 	mov	b, #0x80
      001AD7 12 0E 5F         [24] 5320 	lcall	_fuzzy_8051_eval
      001ADA AC 82            [24] 5321 	mov	r4, dpl
      001ADC AD 83            [24] 5322 	mov	r5, dph
      001ADE AE F0            [24] 5323 	mov	r6, b
      001AE0 FF               [12] 5324 	mov	r7, a
      001AE1 E5 81            [12] 5325 	mov	a,sp
      001AE3 24 FC            [12] 5326 	add	a,#0xfc
      001AE5 F5 81            [12] 5327 	mov	sp,a
      001AE7 8C 82            [24] 5328 	mov	dpl, r4
      001AE9 8D 83            [24] 5329 	mov	dph, r5
      001AEB 8E F0            [24] 5330 	mov	b, r6
      001AED EF               [12] 5331 	mov	a, r7
                           001A37  5332 	C$controller_8051.c$32$1_0$107 ==.
                           001A37  5333 	XFcontroller_8051$fan_fast$0$0 ==.
      001AEE 22               [24] 5334 	ret
                                   5335 ;------------------------------------------------------------
                                   5336 ;Allocation info for local variables in function 'calculate_fan_speed'
                                   5337 ;------------------------------------------------------------
                                   5338 ;temperature   Allocated to stack - _bp +1 +4 
                                   5339 ;------------------------------------------------------------
                           001A38  5340 	Fcontroller_8051$calculate_fan_speed$0$0 ==.
                           001A38  5341 	C$controller_8051.c$40$1_0$109 ==.
                                   5342 ;	../../controller_8051.c:40: static float calculate_fan_speed(float temperature)
                                   5343 ;	-----------------------------------------
                                   5344 ;	 function calculate_fan_speed
                                   5345 ;	-----------------------------------------
      001AEF                       5346 _calculate_fan_speed:
      001AEF C0 1D            [24] 5347 	push	_bp
      001AF1 85 81 1D         [24] 5348 	mov	_bp,sp
      001AF4 C0 82            [24] 5349 	push	dpl
      001AF6 C0 83            [24] 5350 	push	dph
      001AF8 C0 F0            [24] 5351 	push	b
      001AFA C0 E0            [24] 5352 	push	acc
                           001A45  5353 	C$controller_8051.c$42$1_0$109 ==.
                                   5354 ;	../../controller_8051.c:42: rules.count = 0u;
      001AFC 75 16 00         [24] 5355 	mov	(_rules + 0x000e),#0x00
                           001A48  5356 	C$controller_8051.c$44$1_0$109 ==.
                                   5357 ;	../../controller_8051.c:44: if (!RULE(rules, "Low temperature produces slow fan", temperature_low(temperature), fan_slow))
      001AFF A8 1D            [24] 5358 	mov	r0,_bp
      001B01 08               [12] 5359 	inc	r0
      001B02 86 82            [24] 5360 	mov	dpl, @r0
      001B04 08               [12] 5361 	inc	r0
      001B05 86 83            [24] 5362 	mov	dph, @r0
      001B07 08               [12] 5363 	inc	r0
      001B08 86 F0            [24] 5364 	mov	b, @r0
      001B0A 08               [12] 5365 	inc	r0
      001B0B E6               [12] 5366 	mov	a, @r0
      001B0C 12 1A 3B         [24] 5367 	lcall	_temperature_low
      001B0F AA 82            [24] 5368 	mov	r2, dpl
      001B11 AB 83            [24] 5369 	mov	r3, dph
      001B13 AE F0            [24] 5370 	mov	r6, b
      001B15 FF               [12] 5371 	mov	r7, a
      001B16 74 FD            [12] 5372 	mov	a,#_fan_slow_fuzzy_variable
      001B18 C0 E0            [24] 5373 	push	acc
      001B1A 74 20            [12] 5374 	mov	a,#(_fan_slow_fuzzy_variable >> 8)
      001B1C C0 E0            [24] 5375 	push	acc
      001B1E 74 80            [12] 5376 	mov	a,#0x80
      001B20 C0 E0            [24] 5377 	push	acc
      001B22 C0 02            [24] 5378 	push	ar2
      001B24 C0 03            [24] 5379 	push	ar3
      001B26 C0 06            [24] 5380 	push	ar6
      001B28 C0 07            [24] 5381 	push	ar7
      001B2A 90 00 08         [24] 5382 	mov	dptr,#_rules
      001B2D 75 F0 40         [24] 5383 	mov	b, #0x40
      001B30 12 11 F0         [24] 5384 	lcall	_fuzzy_rules_add_8051
      001B33 AF 82            [24] 5385 	mov	r7, dpl
      001B35 E5 81            [12] 5386 	mov	a,sp
      001B37 24 F9            [12] 5387 	add	a,#0xf9
      001B39 F5 81            [12] 5388 	mov	sp,a
      001B3B EF               [12] 5389 	mov	a,r7
      001B3C 70 09            [24] 5390 	jnz	00102$
                           001A87  5391 	C$controller_8051.c$46$2_0$110 ==.
                                   5392 ;	../../controller_8051.c:46: return 0.0f;
      001B3E 90 00 00         [24] 5393 	mov	dptr,#0x0000
      001B41 E4               [12] 5394 	clr	a
      001B42 F5 F0            [12] 5395 	mov	b,a
      001B44 02 1B D2         [24] 5396 	ljmp	00105$
      001B47                       5397 00102$:
                           001A90  5398 	C$controller_8051.c$49$1_0$109 ==.
                                   5399 ;	../../controller_8051.c:49: if (!RULE(rules, "High temperature produces fast fan", temperature_high(temperature), fan_fast))
      001B47 A8 1D            [24] 5400 	mov	r0,_bp
      001B49 08               [12] 5401 	inc	r0
      001B4A 86 82            [24] 5402 	mov	dpl, @r0
      001B4C 08               [12] 5403 	inc	r0
      001B4D 86 83            [24] 5404 	mov	dph, @r0
      001B4F 08               [12] 5405 	inc	r0
      001B50 86 F0            [24] 5406 	mov	b, @r0
      001B52 08               [12] 5407 	inc	r0
      001B53 E6               [12] 5408 	mov	a, @r0
      001B54 12 1A 68         [24] 5409 	lcall	_temperature_high
      001B57 AC 82            [24] 5410 	mov	r4, dpl
      001B59 AD 83            [24] 5411 	mov	r5, dph
      001B5B AE F0            [24] 5412 	mov	r6, b
      001B5D FF               [12] 5413 	mov	r7, a
      001B5E 74 0F            [12] 5414 	mov	a,#_fan_fast_fuzzy_variable
      001B60 C0 E0            [24] 5415 	push	acc
      001B62 74 21            [12] 5416 	mov	a,#(_fan_fast_fuzzy_variable >> 8)
      001B64 C0 E0            [24] 5417 	push	acc
      001B66 74 80            [12] 5418 	mov	a,#0x80
      001B68 C0 E0            [24] 5419 	push	acc
      001B6A C0 04            [24] 5420 	push	ar4
      001B6C C0 05            [24] 5421 	push	ar5
      001B6E C0 06            [24] 5422 	push	ar6
      001B70 C0 07            [24] 5423 	push	ar7
      001B72 90 00 08         [24] 5424 	mov	dptr,#_rules
      001B75 75 F0 40         [24] 5425 	mov	b, #0x40
      001B78 12 11 F0         [24] 5426 	lcall	_fuzzy_rules_add_8051
      001B7B AF 82            [24] 5427 	mov	r7, dpl
      001B7D E5 81            [12] 5428 	mov	a,sp
      001B7F 24 F9            [12] 5429 	add	a,#0xf9
      001B81 F5 81            [12] 5430 	mov	sp,a
      001B83 EF               [12] 5431 	mov	a,r7
      001B84 70 08            [24] 5432 	jnz	00104$
                           001ACF  5433 	C$controller_8051.c$51$2_0$111 ==.
                                   5434 ;	../../controller_8051.c:51: return 0.0f;
      001B86 90 00 00         [24] 5435 	mov	dptr,#0x0000
      001B89 E4               [12] 5436 	clr	a
      001B8A F5 F0            [12] 5437 	mov	b,a
      001B8C 80 44            [24] 5438 	sjmp	00105$
      001B8E                       5439 00104$:
                           001AD7  5440 	C$controller_8051.c$54$1_0$109 ==.
                                   5441 ;	../../controller_8051.c:54: return fuzzy_rules_defuzzify(&rules, 0.0f, 100.0f, 10.0f, FUZZY_DEFUZZ_BOA);
      001B8E 74 01            [12] 5442 	mov	a,#0x01
      001B90 C0 E0            [24] 5443 	push	acc
      001B92 E4               [12] 5444 	clr	a
      001B93 C0 E0            [24] 5445 	push	acc
      001B95 C0 E0            [24] 5446 	push	acc
      001B97 74 20            [12] 5447 	mov	a,#0x20
      001B99 C0 E0            [24] 5448 	push	acc
      001B9B 74 41            [12] 5449 	mov	a,#0x41
      001B9D C0 E0            [24] 5450 	push	acc
      001B9F E4               [12] 5451 	clr	a
      001BA0 C0 E0            [24] 5452 	push	acc
      001BA2 C0 E0            [24] 5453 	push	acc
      001BA4 74 C8            [12] 5454 	mov	a,#0xc8
      001BA6 C0 E0            [24] 5455 	push	acc
      001BA8 74 42            [12] 5456 	mov	a,#0x42
      001BAA C0 E0            [24] 5457 	push	acc
      001BAC E4               [12] 5458 	clr	a
      001BAD C0 E0            [24] 5459 	push	acc
      001BAF C0 E0            [24] 5460 	push	acc
      001BB1 C0 E0            [24] 5461 	push	acc
      001BB3 C0 E0            [24] 5462 	push	acc
      001BB5 90 00 08         [24] 5463 	mov	dptr,#_rules
      001BB8 75 F0 40         [24] 5464 	mov	b, #0x40
      001BBB 12 14 8D         [24] 5465 	lcall	_fuzzy_rules_defuzzify
      001BBE AC 82            [24] 5466 	mov	r4, dpl
      001BC0 AD 83            [24] 5467 	mov	r5, dph
      001BC2 AE F0            [24] 5468 	mov	r6, b
      001BC4 FF               [12] 5469 	mov	r7, a
      001BC5 E5 81            [12] 5470 	mov	a,sp
      001BC7 24 F3            [12] 5471 	add	a,#0xf3
      001BC9 F5 81            [12] 5472 	mov	sp,a
      001BCB 8C 82            [24] 5473 	mov	dpl, r4
      001BCD 8D 83            [24] 5474 	mov	dph, r5
      001BCF 8E F0            [24] 5475 	mov	b, r6
      001BD1 EF               [12] 5476 	mov	a, r7
      001BD2                       5477 00105$:
                           001B1B  5478 	C$controller_8051.c$55$1_0$109 ==.
                                   5479 ;	../../controller_8051.c:55: }
      001BD2 85 1D 81         [24] 5480 	mov	sp,_bp
      001BD5 D0 1D            [24] 5481 	pop	_bp
                           001B20  5482 	C$controller_8051.c$55$1_0$109 ==.
                           001B20  5483 	XFcontroller_8051$calculate_fan_speed$0$0 ==.
      001BD7 22               [24] 5484 	ret
                                   5485 ;------------------------------------------------------------
                                   5486 ;Allocation info for local variables in function 'fan_speed_to_pwm'
                                   5487 ;------------------------------------------------------------
                                   5488 ;fan_speed     Allocated to registers r4 r5 r6 r7 
                                   5489 ;------------------------------------------------------------
                           001B21  5490 	Fcontroller_8051$fan_speed_to_pwm$0$0 ==.
                           001B21  5491 	C$controller_8051.c$57$1_0$113 ==.
                                   5492 ;	../../controller_8051.c:57: static unsigned char fan_speed_to_pwm(float fan_speed)
                                   5493 ;	-----------------------------------------
                                   5494 ;	 function fan_speed_to_pwm
                                   5495 ;	-----------------------------------------
      001BD8                       5496 _fan_speed_to_pwm:
      001BD8 AC 82            [24] 5497 	mov	r4,dpl
      001BDA AD 83            [24] 5498 	mov	r5,dph
      001BDC AE F0            [24] 5499 	mov	r6,b
      001BDE FF               [12] 5500 	mov	r7,a
                           001B28  5501 	C$controller_8051.c$59$1_0$113 ==.
                                   5502 ;	../../controller_8051.c:59: if (fan_speed <= 0.0f)
      001BDF C0 07            [24] 5503 	push	ar7
      001BE1 C0 06            [24] 5504 	push	ar6
      001BE3 C0 05            [24] 5505 	push	ar5
      001BE5 C0 04            [24] 5506 	push	ar4
      001BE7 C0 04            [24] 5507 	push	ar4
      001BE9 C0 05            [24] 5508 	push	ar5
      001BEB C0 06            [24] 5509 	push	ar6
      001BED C0 07            [24] 5510 	push	ar7
      001BEF 90 00 00         [24] 5511 	mov	dptr,#0x0000
      001BF2 E4               [12] 5512 	clr	a
      001BF3 F5 F0            [12] 5513 	mov	b,a
      001BF5 12 1E 0D         [24] 5514 	lcall	___fslt
      001BF8 E5 81            [12] 5515 	mov	a,sp
      001BFA 24 FC            [12] 5516 	add	a,#0xfc
      001BFC F5 81            [12] 5517 	mov	sp,a
      001BFE D0 04            [24] 5518 	pop	ar4
      001C00 D0 05            [24] 5519 	pop	ar5
      001C02 D0 06            [24] 5520 	pop	ar6
      001C04 D0 07            [24] 5521 	pop	ar7
      001C06 E5 82            [12] 5522 	mov	a, dpl
      001C08 24 FF            [12] 5523 	add	a,#0xff
      001C0A 92 00            [24] 5524 	mov	b0,c
      001C0C 40 05            [24] 5525 	jc	00102$
                           001B57  5526 	C$controller_8051.c$61$2_0$114 ==.
                                   5527 ;	../../controller_8051.c:61: return 0u;
      001C0E 75 82 00         [24] 5528 	mov	dpl, #0x00
      001C11 80 66            [24] 5529 	sjmp	00105$
      001C13                       5530 00102$:
                           001B5C  5531 	C$controller_8051.c$64$1_0$113 ==.
                                   5532 ;	../../controller_8051.c:64: if (fan_speed >= 100.0f)
      001C13 C0 07            [24] 5533 	push	ar7
      001C15 C0 06            [24] 5534 	push	ar6
      001C17 C0 05            [24] 5535 	push	ar5
      001C19 C0 04            [24] 5536 	push	ar4
      001C1B E4               [12] 5537 	clr	a
      001C1C C0 E0            [24] 5538 	push	acc
      001C1E C0 E0            [24] 5539 	push	acc
      001C20 74 C8            [12] 5540 	mov	a,#0xc8
      001C22 C0 E0            [24] 5541 	push	acc
      001C24 74 42            [12] 5542 	mov	a,#0x42
      001C26 C0 E0            [24] 5543 	push	acc
      001C28 8C 82            [24] 5544 	mov	dpl, r4
      001C2A 8D 83            [24] 5545 	mov	dph, r5
      001C2C 8E F0            [24] 5546 	mov	b, r6
      001C2E EF               [12] 5547 	mov	a, r7
      001C2F 12 1E 0D         [24] 5548 	lcall	___fslt
      001C32 E5 81            [12] 5549 	mov	a,sp
      001C34 24 FC            [12] 5550 	add	a,#0xfc
      001C36 F5 81            [12] 5551 	mov	sp,a
      001C38 D0 04            [24] 5552 	pop	ar4
      001C3A D0 05            [24] 5553 	pop	ar5
      001C3C D0 06            [24] 5554 	pop	ar6
      001C3E D0 07            [24] 5555 	pop	ar7
      001C40 E5 82            [12] 5556 	mov	a, dpl
      001C42 24 FF            [12] 5557 	add	a,#0xff
      001C44 92 00            [24] 5558 	mov	b0,c
      001C46 40 05            [24] 5559 	jc	00104$
                           001B91  5560 	C$controller_8051.c$66$2_0$115 ==.
                                   5561 ;	../../controller_8051.c:66: return 100u;
      001C48 75 82 64         [24] 5562 	mov	dpl, #0x64
      001C4B 80 2C            [24] 5563 	sjmp	00105$
      001C4D                       5564 00104$:
                           001B96  5565 	C$controller_8051.c$69$1_0$113 ==.
                                   5566 ;	../../controller_8051.c:69: return (unsigned char)(fan_speed + 0.5f);
      001C4D E4               [12] 5567 	clr	a
      001C4E C0 E0            [24] 5568 	push	acc
      001C50 C0 E0            [24] 5569 	push	acc
      001C52 C0 E0            [24] 5570 	push	acc
      001C54 74 3F            [12] 5571 	mov	a,#0x3f
      001C56 C0 E0            [24] 5572 	push	acc
      001C58 8C 82            [24] 5573 	mov	dpl, r4
      001C5A 8D 83            [24] 5574 	mov	dph, r5
      001C5C 8E F0            [24] 5575 	mov	b, r6
      001C5E EF               [12] 5576 	mov	a, r7
      001C5F 12 1E 3D         [24] 5577 	lcall	___fsadd
      001C62 AC 82            [24] 5578 	mov	r4, dpl
      001C64 AD 83            [24] 5579 	mov	r5, dph
      001C66 AE F0            [24] 5580 	mov	r6, b
      001C68 FF               [12] 5581 	mov	r7, a
      001C69 E5 81            [12] 5582 	mov	a,sp
      001C6B 24 FC            [12] 5583 	add	a,#0xfc
      001C6D F5 81            [12] 5584 	mov	sp,a
      001C6F 8C 82            [24] 5585 	mov	dpl, r4
      001C71 8D 83            [24] 5586 	mov	dph, r5
      001C73 8E F0            [24] 5587 	mov	b, r6
      001C75 EF               [12] 5588 	mov	a, r7
      001C76 12 20 33         [24] 5589 	lcall	___fs2uchar
      001C79                       5590 00105$:
                           001BC2  5591 	C$controller_8051.c$70$1_0$113 ==.
                                   5592 ;	../../controller_8051.c:70: }
                           001BC2  5593 	C$controller_8051.c$70$1_0$113 ==.
                           001BC2  5594 	XFcontroller_8051$fan_speed_to_pwm$0$0 ==.
      001C79 22               [24] 5595 	ret
                                   5596 ;------------------------------------------------------------
                                   5597 ;Allocation info for local variables in function 'update_controller'
                                   5598 ;------------------------------------------------------------
                                   5599 ;temperature   Allocated to registers 
                                   5600 ;------------------------------------------------------------
                           001BC3  5601 	Fcontroller_8051$update_controller$0$0 ==.
                           001BC3  5602 	C$controller_8051.c$72$1_0$117 ==.
                                   5603 ;	../../controller_8051.c:72: static void update_controller(unsigned char temperature)
                                   5604 ;	-----------------------------------------
                                   5605 ;	 function update_controller
                                   5606 ;	-----------------------------------------
      001C7A                       5607 _update_controller:
      001C7A 85 82 17         [24] 5608 	mov	_test_temperature,dpl
                           001BC6  5609 	C$controller_8051.c$75$1_0$117 ==.
                                   5610 ;	../../controller_8051.c:75: test_fan_speed = calculate_fan_speed((float)test_temperature);
      001C7D 85 17 82         [24] 5611 	mov	dpl, _test_temperature
      001C80 12 20 3B         [24] 5612 	lcall	___uchar2fs
      001C83 12 1A EF         [24] 5613 	lcall	_calculate_fan_speed
      001C86 85 82 19         [24] 5614 	mov	_test_fan_speed,dpl
      001C89 85 83 1A         [24] 5615 	mov	(_test_fan_speed + 1),dph
      001C8C 85 F0 1B         [24] 5616 	mov	(_test_fan_speed + 2),b
      001C8F F5 1C            [12] 5617 	mov	(_test_fan_speed + 3),a
                           001BDA  5618 	C$controller_8051.c$76$1_0$117 ==.
                                   5619 ;	../../controller_8051.c:76: test_pwm = fan_speed_to_pwm(test_fan_speed);
      001C91 85 19 82         [24] 5620 	mov	dpl, _test_fan_speed
      001C94 85 1A 83         [24] 5621 	mov	dph, (_test_fan_speed + 1)
      001C97 85 1B F0         [24] 5622 	mov	b, (_test_fan_speed + 2)
      001C9A E5 1C            [12] 5623 	mov	a, (_test_fan_speed + 3)
      001C9C 12 1B D8         [24] 5624 	lcall	_fan_speed_to_pwm
      001C9F 85 82 18         [24] 5625 	mov	_test_pwm,dpl
                           001BEB  5626 	C$controller_8051.c$77$1_0$117 ==.
                                   5627 ;	../../controller_8051.c:77: }
                           001BEB  5628 	C$controller_8051.c$77$1_0$117 ==.
                           001BEB  5629 	XFcontroller_8051$update_controller$0$0 ==.
      001CA2 22               [24] 5630 	ret
                                   5631 ;------------------------------------------------------------
                                   5632 ;Allocation info for local variables in function 'main'
                                   5633 ;------------------------------------------------------------
                           001BEC  5634 	G$main$0$0 ==.
                           001BEC  5635 	C$controller_8051.c$81$1_0$119 ==.
                                   5636 ;	../../controller_8051.c:81: void main(void)
                                   5637 ;	-----------------------------------------
                                   5638 ;	 function main
                                   5639 ;	-----------------------------------------
      001CA3                       5640 _main:
                           001BEC  5641 	C$controller_8051.c$83$1_0$119 ==.
                                   5642 ;	../../controller_8051.c:83: P0 = 0x00u;
      001CA3 75 80 00         [24] 5643 	mov	_P0,#0x00
                           001BEF  5644 	C$controller_8051.c$84$1_0$119 ==.
                                   5645 ;	../../controller_8051.c:84: P1 = 0x00u;
      001CA6 75 90 00         [24] 5646 	mov	_P1,#0x00
      001CA9                       5647 00105$:
                           001BF2  5648 	C$controller_8051.c$88$3_0$121 ==.
                                   5649 ;	../../controller_8051.c:88: P0 = 0x55u;
      001CA9 75 80 55         [24] 5650 	mov	_P0,#0x55
                           001BF5  5651 	C$controller_8051.c$89$3_0$121 ==.
                                   5652 ;	../../controller_8051.c:89: test_temperature = P2;
      001CAC 85 A0 17         [24] 5653 	mov	_test_temperature,_P2
                           001BF8  5654 	C$controller_8051.c$91$3_0$121 ==.
                                   5655 ;	../../controller_8051.c:91: if (test_temperature > 100u)
      001CAF E5 17            [12] 5656 	mov	a,_test_temperature
      001CB1 24 9B            [12] 5657 	add	a,#0xff - 0x64
      001CB3 50 08            [24] 5658 	jnc	00102$
                           001BFE  5659 	C$controller_8051.c$93$4_0$122 ==.
                                   5660 ;	../../controller_8051.c:93: P1 = 0x00u;
      001CB5 75 90 00         [24] 5661 	mov	_P1,#0x00
                           001C01  5662 	C$controller_8051.c$94$4_0$122 ==.
                                   5663 ;	../../controller_8051.c:94: P0 = 0xF0u;
      001CB8 75 80 F0         [24] 5664 	mov	_P0,#0xf0
                           001C04  5665 	C$controller_8051.c$95$4_0$122 ==.
                                   5666 ;	../../controller_8051.c:95: continue;
      001CBB 80 EC            [24] 5667 	sjmp	00105$
      001CBD                       5668 00102$:
                           001C06  5669 	C$controller_8051.c$98$3_0$121 ==.
                                   5670 ;	../../controller_8051.c:98: P0 = 0x60u;
      001CBD 75 80 60         [24] 5671 	mov	_P0,#0x60
                           001C09  5672 	C$controller_8051.c$99$3_0$121 ==.
                                   5673 ;	../../controller_8051.c:99: update_controller(test_temperature);
      001CC0 85 17 82         [24] 5674 	mov	dpl, _test_temperature
      001CC3 12 1C 7A         [24] 5675 	lcall	_update_controller
                           001C0F  5676 	C$controller_8051.c$101$3_0$121 ==.
                                   5677 ;	../../controller_8051.c:101: P0 = 0x70u;
      001CC6 75 80 70         [24] 5678 	mov	_P0,#0x70
                           001C12  5679 	C$controller_8051.c$102$3_0$121 ==.
                                   5680 ;	../../controller_8051.c:102: P1 = test_pwm;
      001CC9 85 18 90         [24] 5681 	mov	_P1,_test_pwm
                           001C15  5682 	C$controller_8051.c$104$3_0$121 ==.
                                   5683 ;	../../controller_8051.c:104: P0 = 0xAAu;
      001CCC 75 80 AA         [24] 5684 	mov	_P0,#0xaa
      001CCF 80 D8            [24] 5685 	sjmp	00105$
                           001C1A  5686 	C$controller_8051.c$106$2_0$119 ==.
                                   5687 ;	../../controller_8051.c:106: }
                           001C1A  5688 	C$controller_8051.c$106$2_0$119 ==.
                           001C1A  5689 	XG$main$0$0 ==.
      001CD1 22               [24] 5690 	ret
                                   5691 	.area CSEG    (CODE)
                                   5692 	.area CONST   (CODE)
                                   5693 	.area CONST   (CODE)
                           000000  5694 Fcontroller_8051$temperature_low_fuzzy_variable$0_0$0 == .
      0020D9                       5695 _temperature_low_fuzzy_variable:
      0020D9 00                    5696 	.db #0x00	; 0
      0020DA 01                    5697 	.db #0x01	; 1
      0020DB 00 00 A0 41           5698 	.byte #0x00, #0x00, #0xa0, #0x41	;  2.000000e+01
      0020DF 00 00 20 42           5699 	.byte #0x00, #0x00, #0x20, #0x42	;  4.000000e+01
      0020E3 00 00 00 00           5700 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
      0020E7 00 00 00 00           5701 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   5702 	.area CSEG    (CODE)
                                   5703 	.area CONST   (CODE)
                           000012  5704 Fcontroller_8051$temperature_high_fuzzy_variable$0_0$0 == .
      0020EB                       5705 _temperature_high_fuzzy_variable:
      0020EB 00                    5706 	.db #0x00	; 0
      0020EC 01                    5707 	.db #0x01	; 1
      0020ED 00 00 F0 41           5708 	.byte #0x00, #0x00, #0xf0, #0x41	;  3.000000e+01
      0020F1 00 00 70 42           5709 	.byte #0x00, #0x00, #0x70, #0x42	;  6.000000e+01
      0020F5 00 00 80 3F           5710 	.byte #0x00, #0x00, #0x80, #0x3f	;  1.000000e+00
      0020F9 00 00 00 00           5711 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   5712 	.area CSEG    (CODE)
                                   5713 	.area CONST   (CODE)
                           000024  5714 Fcontroller_8051$fan_slow_fuzzy_variable$0_0$0 == .
      0020FD                       5715 _fan_slow_fuzzy_variable:
      0020FD 00                    5716 	.db #0x00	; 0
      0020FE 01                    5717 	.db #0x01	; 1
      0020FF 00 00 A0 41           5718 	.byte #0x00, #0x00, #0xa0, #0x41	;  2.000000e+01
      002103 00 00 48 42           5719 	.byte #0x00, #0x00, #0x48, #0x42	;  5.000000e+01
      002107 00 00 00 00           5720 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
      00210B 00 00 00 00           5721 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   5722 	.area CSEG    (CODE)
                                   5723 	.area CONST   (CODE)
                           000036  5724 Fcontroller_8051$fan_fast_fuzzy_variable$0_0$0 == .
      00210F                       5725 _fan_fast_fuzzy_variable:
      00210F 00                    5726 	.db #0x00	; 0
      002110 01                    5727 	.db #0x01	; 1
      002111 00 00 20 42           5728 	.byte #0x00, #0x00, #0x20, #0x42	;  4.000000e+01
      002115 00 00 A0 42           5729 	.byte #0x00, #0x00, #0xa0, #0x42	;  8.000000e+01
      002119 00 00 80 3F           5730 	.byte #0x00, #0x00, #0x80, #0x3f	;  1.000000e+00
      00211D 00 00 00 00           5731 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   5732 	.area CSEG    (CODE)
                                   5733 	.area XINIT   (CODE)
                                   5734 	.area CABS    (ABS,CODE)
