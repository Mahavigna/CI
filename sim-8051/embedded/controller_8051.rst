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
                           000000   550 	C$controller_8051.c$20$2_0$55 ==.
                                    551 ;	../../controller_8051.c:20: volatile unsigned char test_temperature = 0u;
      0000A5 75 17 00         [24]  552 	mov	_test_temperature,#0x00
                           000003   553 	C$controller_8051.c$21$2_0$55 ==.
                                    554 ;	../../controller_8051.c:21: volatile unsigned char test_pwm = 0u;
      0000A8 75 18 00         [24]  555 	mov	_test_pwm,#0x00
                           000006   556 	C$controller_8051.c$22$2_0$55 ==.
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
      000049 02 18 C8         [24]  571 	ljmp	_main
                                    572 ;	return from main will return to caller
                                    573 ;--------------------------------------------------------
                                    574 ; code
                                    575 ;--------------------------------------------------------
                                    576 	.area CSEG    (CODE)
                                    577 ;------------------------------------------------------------
                                    578 ;Allocation info for local variables in function 'fuzzy_8051_clamp'
                                    579 ;------------------------------------------------------------
                                    580 ;value         Allocated to registers r4 r5 r6 r7 
                                    581 ;------------------------------------------------------------
                           000000   582 	Fcontroller_8051$fuzzy_8051_clamp$0$0 ==.
                           000000   583 	C$fuzzy.h$54$0_0$11 ==.
                                    584 ;	../../fuzzy.h:54: static float fuzzy_8051_clamp(float value) { if (value < 0.0f) return 0.0f; if (value > 1.0f) return 1.0f; return value; }
                                    585 ;	-----------------------------------------
                                    586 ;	 function fuzzy_8051_clamp
                                    587 ;	-----------------------------------------
      0000B7                        588 _fuzzy_8051_clamp:
                           000007   589 	ar7 = 0x07
                           000006   590 	ar6 = 0x06
                           000005   591 	ar5 = 0x05
                           000004   592 	ar4 = 0x04
                           000003   593 	ar3 = 0x03
                           000002   594 	ar2 = 0x02
                           000001   595 	ar1 = 0x01
                           000000   596 	ar0 = 0x00
      0000B7 AC 82            [24]  597 	mov	r4,dpl
      0000B9 AD 83            [24]  598 	mov	r5,dph
      0000BB AE F0            [24]  599 	mov	r6,b
      0000BD FF               [12]  600 	mov	r7,a
      0000BE C0 07            [24]  601 	push	ar7
      0000C0 C0 06            [24]  602 	push	ar6
      0000C2 C0 05            [24]  603 	push	ar5
      0000C4 C0 04            [24]  604 	push	ar4
      0000C6 E4               [12]  605 	clr	a
      0000C7 C0 E0            [24]  606 	push	acc
      0000C9 C0 E0            [24]  607 	push	acc
      0000CB C0 E0            [24]  608 	push	acc
      0000CD C0 E0            [24]  609 	push	acc
      0000CF 8C 82            [24]  610 	mov	dpl, r4
      0000D1 8D 83            [24]  611 	mov	dph, r5
      0000D3 8E F0            [24]  612 	mov	b, r6
      0000D5 EF               [12]  613 	mov	a, r7
      0000D6 12 1A 32         [24]  614 	lcall	___fslt
      0000D9 AB 82            [24]  615 	mov	r3, dpl
      0000DB E5 81            [12]  616 	mov	a,sp
      0000DD 24 FC            [12]  617 	add	a,#0xfc
      0000DF F5 81            [12]  618 	mov	sp,a
      0000E1 D0 04            [24]  619 	pop	ar4
      0000E3 D0 05            [24]  620 	pop	ar5
      0000E5 D0 06            [24]  621 	pop	ar6
      0000E7 D0 07            [24]  622 	pop	ar7
      0000E9 EB               [12]  623 	mov	a,r3
      0000EA 60 08            [24]  624 	jz	00102$
      0000EC 90 00 00         [24]  625 	mov	dptr,#0x0000
      0000EF E4               [12]  626 	clr	a
      0000F0 F5 F0            [12]  627 	mov	b,a
      0000F2 80 3F            [24]  628 	sjmp	00105$
      0000F4                        629 00102$:
      0000F4 C0 07            [24]  630 	push	ar7
      0000F6 C0 06            [24]  631 	push	ar6
      0000F8 C0 05            [24]  632 	push	ar5
      0000FA C0 04            [24]  633 	push	ar4
      0000FC C0 04            [24]  634 	push	ar4
      0000FE C0 05            [24]  635 	push	ar5
      000100 C0 06            [24]  636 	push	ar6
      000102 C0 07            [24]  637 	push	ar7
      000104 90 00 00         [24]  638 	mov	dptr,#0x0000
      000107 75 F0 80         [24]  639 	mov	b, #0x80
      00010A 74 3F            [12]  640 	mov	a, #0x3f
      00010C 12 1A 32         [24]  641 	lcall	___fslt
      00010F AB 82            [24]  642 	mov	r3, dpl
      000111 E5 81            [12]  643 	mov	a,sp
      000113 24 FC            [12]  644 	add	a,#0xfc
      000115 F5 81            [12]  645 	mov	sp,a
      000117 D0 04            [24]  646 	pop	ar4
      000119 D0 05            [24]  647 	pop	ar5
      00011B D0 06            [24]  648 	pop	ar6
      00011D D0 07            [24]  649 	pop	ar7
      00011F EB               [12]  650 	mov	a,r3
      000120 60 0A            [24]  651 	jz	00104$
      000122 90 00 00         [24]  652 	mov	dptr,#0x0000
      000125 75 F0 80         [24]  653 	mov	b, #0x80
      000128 74 3F            [12]  654 	mov	a, #0x3f
      00012A 80 07            [24]  655 	sjmp	00105$
      00012C                        656 00104$:
      00012C 8C 82            [24]  657 	mov	dpl, r4
      00012E 8D 83            [24]  658 	mov	dph, r5
      000130 8E F0            [24]  659 	mov	b, r6
      000132 EF               [12]  660 	mov	a, r7
      000133                        661 00105$:
                           00007C   662 	C$fuzzy.h$54$1_0$11 ==.
                           00007C   663 	XFcontroller_8051$fuzzy_8051_clamp$0$0 ==.
      000133 22               [24]  664 	ret
                                    665 ;------------------------------------------------------------
                                    666 ;Allocation info for local variables in function 'fuzzy_8051_hedge'
                                    667 ;------------------------------------------------------------
                                    668 ;hedge         Allocated to stack - _bp -3 +1 
                                    669 ;value         Allocated to stack - _bp +1 +4 
                                    670 ;result        Allocated to registers r2 r3 r6 r7 
                                    671 ;------------------------------------------------------------
                           00007D   672 	Fcontroller_8051$fuzzy_8051_hedge$0$0 ==.
                           00007D   673 	C$fuzzy.h$55$1_0$13 ==.
                                    674 ;	../../fuzzy.h:55: static float fuzzy_8051_hedge(float value, fuzzy_hedge_t hedge) { float result; value = fuzzy_8051_clamp(value); if (hedge == 0u) hedge = 1u; result = 1.0f; while (hedge != 0u) { result *= value; --hedge; } return fuzzy_8051_clamp(result); }
                                    675 ;	-----------------------------------------
                                    676 ;	 function fuzzy_8051_hedge
                                    677 ;	-----------------------------------------
      000134                        678 _fuzzy_8051_hedge:
      000134 C0 1D            [24]  679 	push	_bp
      000136 85 81 1D         [24]  680 	mov	_bp,sp
      000139 AC 82            [24]  681 	mov	r4,dpl
      00013B AD 83            [24]  682 	mov	r5,dph
      00013D AE F0            [24]  683 	mov	r6,b
      00013F FF               [12]  684 	mov	r7,a
      000140 E5 81            [12]  685 	mov	a,sp
      000142 24 04            [12]  686 	add	a,#0x04
      000144 F5 81            [12]  687 	mov	sp,a
      000146 8C 82            [24]  688 	mov	dpl, r4
      000148 8D 83            [24]  689 	mov	dph, r5
      00014A 8E F0            [24]  690 	mov	b, r6
      00014C EF               [12]  691 	mov	a, r7
      00014D 12 00 B7         [24]  692 	lcall	_fuzzy_8051_clamp
      000150 A8 1D            [24]  693 	mov	r0,_bp
      000152 08               [12]  694 	inc	r0
      000153 A6 82            [24]  695 	mov	@r0, dpl
      000155 08               [12]  696 	inc	r0
      000156 A6 83            [24]  697 	mov	@r0, dph
      000158 08               [12]  698 	inc	r0
      000159 A6 F0            [24]  699 	mov	@r0, b
      00015B 08               [12]  700 	inc	r0
      00015C F6               [12]  701 	mov	@r0,a
      00015D E5 1D            [12]  702 	mov	a,_bp
      00015F 24 FD            [12]  703 	add	a,#0xfd
      000161 F8               [12]  704 	mov	r0,a
      000162 E6               [12]  705 	mov	a,@r0
      000163 70 07            [24]  706 	jnz	00102$
      000165 E5 1D            [12]  707 	mov	a,_bp
      000167 24 FD            [12]  708 	add	a,#0xfd
      000169 F8               [12]  709 	mov	r0,a
      00016A 76 01            [12]  710 	mov	@r0,#0x01
      00016C                        711 00102$:
      00016C 7A 00            [12]  712 	mov	r2,#0x00
      00016E 7B 00            [12]  713 	mov	r3,#0x00
      000170 7E 80            [12]  714 	mov	r6,#0x80
      000172 7F 3F            [12]  715 	mov	r7,#0x3f
      000174 E5 1D            [12]  716 	mov	a,_bp
      000176 24 FD            [12]  717 	add	a,#0xfd
      000178 F8               [12]  718 	mov	r0,a
      000179 86 05            [24]  719 	mov	ar5,@r0
      00017B                        720 00103$:
      00017B ED               [12]  721 	mov	a,r5
      00017C 60 30            [24]  722 	jz	00105$
      00017E C0 05            [24]  723 	push	ar5
      000180 A8 1D            [24]  724 	mov	r0,_bp
      000182 08               [12]  725 	inc	r0
      000183 E6               [12]  726 	mov	a,@r0
      000184 C0 E0            [24]  727 	push	acc
      000186 08               [12]  728 	inc	r0
      000187 E6               [12]  729 	mov	a,@r0
      000188 C0 E0            [24]  730 	push	acc
      00018A 08               [12]  731 	inc	r0
      00018B E6               [12]  732 	mov	a,@r0
      00018C C0 E0            [24]  733 	push	acc
      00018E 08               [12]  734 	inc	r0
      00018F E6               [12]  735 	mov	a,@r0
      000190 C0 E0            [24]  736 	push	acc
      000192 8A 82            [24]  737 	mov	dpl, r2
      000194 8B 83            [24]  738 	mov	dph, r3
      000196 8E F0            [24]  739 	mov	b, r6
      000198 EF               [12]  740 	mov	a, r7
      000199 12 19 02         [24]  741 	lcall	___fsmul
      00019C AA 82            [24]  742 	mov	r2, dpl
      00019E AB 83            [24]  743 	mov	r3, dph
      0001A0 AE F0            [24]  744 	mov	r6, b
      0001A2 FF               [12]  745 	mov	r7, a
      0001A3 E5 81            [12]  746 	mov	a,sp
      0001A5 24 FC            [12]  747 	add	a,#0xfc
      0001A7 F5 81            [12]  748 	mov	sp,a
      0001A9 D0 05            [24]  749 	pop	ar5
      0001AB 1D               [12]  750 	dec	r5
      0001AC 80 CD            [24]  751 	sjmp	00103$
      0001AE                        752 00105$:
      0001AE 8A 82            [24]  753 	mov	dpl, r2
      0001B0 8B 83            [24]  754 	mov	dph, r3
      0001B2 8E F0            [24]  755 	mov	b, r6
      0001B4 EF               [12]  756 	mov	a, r7
      0001B5 12 00 B7         [24]  757 	lcall	_fuzzy_8051_clamp
      0001B8 85 1D 81         [24]  758 	mov	sp,_bp
      0001BB D0 1D            [24]  759 	pop	_bp
                           000106   760 	C$fuzzy.h$55$1_0$13 ==.
                           000106   761 	XFcontroller_8051$fuzzy_8051_hedge$0$0 ==.
      0001BD 22               [24]  762 	ret
                                    763 ;------------------------------------------------------------
                                    764 ;Allocation info for local variables in function 'fuzzy_not'
                                    765 ;------------------------------------------------------------
                                    766 ;membership    Allocated to registers r4 r5 r6 r7 
                                    767 ;------------------------------------------------------------
                           000107   768 	G$fuzzy_not$0$0 ==.
                           000107   769 	C$fuzzy.h$56$1_0$16 ==.
                                    770 ;	../../fuzzy.h:56: float fuzzy_not(float membership) { return 1.0f - fuzzy_8051_clamp(membership); }
                                    771 ;	-----------------------------------------
                                    772 ;	 function fuzzy_not
                                    773 ;	-----------------------------------------
      0001BE                        774 _fuzzy_not:
      0001BE 12 00 B7         [24]  775 	lcall	_fuzzy_8051_clamp
      0001C1 AC 82            [24]  776 	mov	r4, dpl
      0001C3 AD 83            [24]  777 	mov	r5, dph
      0001C5 AE F0            [24]  778 	mov	r6, b
      0001C7 FF               [12]  779 	mov	r7, a
      0001C8 C0 04            [24]  780 	push	ar4
      0001CA C0 05            [24]  781 	push	ar5
      0001CC C0 06            [24]  782 	push	ar6
      0001CE C0 07            [24]  783 	push	ar7
      0001D0 90 00 00         [24]  784 	mov	dptr,#0x0000
      0001D3 75 F0 80         [24]  785 	mov	b, #0x80
      0001D6 74 3F            [12]  786 	mov	a, #0x3f
      0001D8 12 18 F7         [24]  787 	lcall	___fssub
      0001DB AC 82            [24]  788 	mov	r4, dpl
      0001DD AD 83            [24]  789 	mov	r5, dph
      0001DF AE F0            [24]  790 	mov	r6, b
      0001E1 FF               [12]  791 	mov	r7, a
      0001E2 E5 81            [12]  792 	mov	a,sp
      0001E4 24 FC            [12]  793 	add	a,#0xfc
      0001E6 F5 81            [12]  794 	mov	sp,a
      0001E8 8C 82            [24]  795 	mov	dpl, r4
      0001EA 8D 83            [24]  796 	mov	dph, r5
      0001EC 8E F0            [24]  797 	mov	b, r6
      0001EE EF               [12]  798 	mov	a, r7
                           000138   799 	C$fuzzy.h$56$1_0$16 ==.
                           000138   800 	XG$fuzzy_not$0$0 ==.
      0001EF 22               [24]  801 	ret
                                    802 ;------------------------------------------------------------
                                    803 ;Allocation info for local variables in function 'fuzzy_ramp'
                                    804 ;------------------------------------------------------------
                                    805 ;b             Allocated to stack - _bp -6 +4 
                                    806 ;x             Allocated to stack - _bp -10 +4 
                                    807 ;up            Allocated to stack - _bp -11 +1 
                                    808 ;hedge         Allocated to stack - _bp -12 +1 
                                    809 ;a             Allocated to registers r7 r6 r5 r4 
                                    810 ;result        Allocated to stack - _bp +5 +4 
                                    811 ;sloc0         Allocated to stack - _bp +1 +4 
                                    812 ;------------------------------------------------------------
                           000139   813 	G$fuzzy_ramp$0$0 ==.
                           000139   814 	C$fuzzy.h$57$1_0$18 ==.
                                    815 ;	../../fuzzy.h:57: float fuzzy_ramp(float a, float b, float x, bool up, fuzzy_hedge_t hedge) { float result; if (a >= b) return 0.0f; if (x <= a) result = up ? 0.0f : 1.0f; else if (x >= b) result = up ? 1.0f : 0.0f; else { result = (x - a) / (b - a); if (!up) result = 1.0f - result; } return fuzzy_8051_hedge(result, hedge); }
                                    816 ;	-----------------------------------------
                                    817 ;	 function fuzzy_ramp
                                    818 ;	-----------------------------------------
      0001F0                        819 _fuzzy_ramp:
      0001F0 C0 1D            [24]  820 	push	_bp
      0001F2 85 81 1D         [24]  821 	mov	_bp,sp
      0001F5 AF 82            [24]  822 	mov	r7,dpl
      0001F7 AE 83            [24]  823 	mov	r6,dph
      0001F9 AD F0            [24]  824 	mov	r5,b
      0001FB FC               [12]  825 	mov	r4,a
      0001FC E5 81            [12]  826 	mov	a,sp
      0001FE 24 08            [12]  827 	add	a,#0x08
      000200 F5 81            [12]  828 	mov	sp,a
      000202 C0 07            [24]  829 	push	ar7
      000204 C0 06            [24]  830 	push	ar6
      000206 C0 05            [24]  831 	push	ar5
      000208 C0 04            [24]  832 	push	ar4
      00020A E5 1D            [12]  833 	mov	a,_bp
      00020C 24 FA            [12]  834 	add	a,#0xfa
      00020E F8               [12]  835 	mov	r0,a
      00020F E6               [12]  836 	mov	a,@r0
      000210 C0 E0            [24]  837 	push	acc
      000212 08               [12]  838 	inc	r0
      000213 E6               [12]  839 	mov	a,@r0
      000214 C0 E0            [24]  840 	push	acc
      000216 08               [12]  841 	inc	r0
      000217 E6               [12]  842 	mov	a,@r0
      000218 C0 E0            [24]  843 	push	acc
      00021A 08               [12]  844 	inc	r0
      00021B E6               [12]  845 	mov	a,@r0
      00021C C0 E0            [24]  846 	push	acc
      00021E 8F 82            [24]  847 	mov	dpl, r7
      000220 8E 83            [24]  848 	mov	dph, r6
      000222 8D F0            [24]  849 	mov	b, r5
      000224 EC               [12]  850 	mov	a, r4
      000225 12 1A 32         [24]  851 	lcall	___fslt
      000228 E5 81            [12]  852 	mov	a,sp
      00022A 24 FC            [12]  853 	add	a,#0xfc
      00022C F5 81            [12]  854 	mov	sp,a
      00022E D0 04            [24]  855 	pop	ar4
      000230 D0 05            [24]  856 	pop	ar5
      000232 D0 06            [24]  857 	pop	ar6
      000234 D0 07            [24]  858 	pop	ar7
      000236 E5 82            [12]  859 	mov	a, dpl
      000238 24 FF            [12]  860 	add	a,#0xff
      00023A 92 00            [24]  861 	mov	b0,c
      00023C 40 09            [24]  862 	jc	00102$
      00023E 90 00 00         [24]  863 	mov	dptr,#0x0000
      000241 E4               [12]  864 	clr	a
      000242 F5 F0            [12]  865 	mov	b,a
      000244 02 03 F6         [24]  866 	ljmp	00111$
      000247                        867 00102$:
      000247 C0 07            [24]  868 	push	ar7
      000249 C0 06            [24]  869 	push	ar6
      00024B C0 05            [24]  870 	push	ar5
      00024D C0 04            [24]  871 	push	ar4
      00024F E5 1D            [12]  872 	mov	a,_bp
      000251 24 F6            [12]  873 	add	a,#0xf6
      000253 F8               [12]  874 	mov	r0,a
      000254 E6               [12]  875 	mov	a,@r0
      000255 C0 E0            [24]  876 	push	acc
      000257 08               [12]  877 	inc	r0
      000258 E6               [12]  878 	mov	a,@r0
      000259 C0 E0            [24]  879 	push	acc
      00025B 08               [12]  880 	inc	r0
      00025C E6               [12]  881 	mov	a,@r0
      00025D C0 E0            [24]  882 	push	acc
      00025F 08               [12]  883 	inc	r0
      000260 E6               [12]  884 	mov	a,@r0
      000261 C0 E0            [24]  885 	push	acc
      000263 8F 82            [24]  886 	mov	dpl, r7
      000265 8E 83            [24]  887 	mov	dph, r6
      000267 8D F0            [24]  888 	mov	b, r5
      000269 EC               [12]  889 	mov	a, r4
      00026A 12 1A 32         [24]  890 	lcall	___fslt
      00026D E5 81            [12]  891 	mov	a,sp
      00026F 24 FC            [12]  892 	add	a,#0xfc
      000271 F5 81            [12]  893 	mov	sp,a
      000273 D0 04            [24]  894 	pop	ar4
      000275 D0 05            [24]  895 	pop	ar5
      000277 D0 06            [24]  896 	pop	ar6
      000279 D0 07            [24]  897 	pop	ar7
      00027B E5 82            [12]  898 	mov	a, dpl
      00027D 24 FF            [12]  899 	add	a,#0xff
      00027F 92 00            [24]  900 	mov	b0,c
      000281 40 39            [24]  901 	jc	00109$
      000283 E5 1D            [12]  902 	mov	a,_bp
      000285 24 F5            [12]  903 	add	a,#0xf5
      000287 F8               [12]  904 	mov	r0,a
      000288 E6               [12]  905 	mov	a,@r0
      000289 60 0F            [24]  906 	jz	00113$
      00028B E5 1D            [12]  907 	mov	a,_bp
      00028D 24 05            [12]  908 	add	a,#0x05
      00028F F8               [12]  909 	mov	r0,a
      000290 E4               [12]  910 	clr	a
      000291 F6               [12]  911 	mov	@r0,a
      000292 08               [12]  912 	inc	r0
      000293 F6               [12]  913 	mov	@r0,a
      000294 08               [12]  914 	inc	r0
      000295 F6               [12]  915 	mov	@r0,a
      000296 08               [12]  916 	inc	r0
      000297 F6               [12]  917 	mov	@r0,a
      000298 80 0F            [24]  918 	sjmp	00114$
      00029A                        919 00113$:
      00029A E5 1D            [12]  920 	mov	a,_bp
      00029C 24 05            [12]  921 	add	a,#0x05
      00029E F8               [12]  922 	mov	r0,a
      00029F E4               [12]  923 	clr	a
      0002A0 F6               [12]  924 	mov	@r0,a
      0002A1 08               [12]  925 	inc	r0
      0002A2 F6               [12]  926 	mov	@r0,a
      0002A3 08               [12]  927 	inc	r0
      0002A4 76 80            [12]  928 	mov	@r0,#0x80
      0002A6 08               [12]  929 	inc	r0
      0002A7 76 3F            [12]  930 	mov	@r0,#0x3f
      0002A9                        931 00114$:
      0002A9 E5 1D            [12]  932 	mov	a,_bp
      0002AB 24 05            [12]  933 	add	a,#0x05
      0002AD F8               [12]  934 	mov	r0,a
      0002AE 86 07            [24]  935 	mov	ar7,@r0
      0002B0 08               [12]  936 	inc	r0
      0002B1 86 06            [24]  937 	mov	ar6,@r0
      0002B3 08               [12]  938 	inc	r0
      0002B4 86 05            [24]  939 	mov	ar5,@r0
      0002B6 08               [12]  940 	inc	r0
      0002B7 86 04            [24]  941 	mov	ar4,@r0
      0002B9 02 03 D4         [24]  942 	ljmp	00110$
      0002BC                        943 00109$:
      0002BC C0 07            [24]  944 	push	ar7
      0002BE C0 06            [24]  945 	push	ar6
      0002C0 C0 05            [24]  946 	push	ar5
      0002C2 C0 04            [24]  947 	push	ar4
      0002C4 E5 1D            [12]  948 	mov	a,_bp
      0002C6 24 FA            [12]  949 	add	a,#0xfa
      0002C8 F8               [12]  950 	mov	r0,a
      0002C9 E6               [12]  951 	mov	a,@r0
      0002CA C0 E0            [24]  952 	push	acc
      0002CC 08               [12]  953 	inc	r0
      0002CD E6               [12]  954 	mov	a,@r0
      0002CE C0 E0            [24]  955 	push	acc
      0002D0 08               [12]  956 	inc	r0
      0002D1 E6               [12]  957 	mov	a,@r0
      0002D2 C0 E0            [24]  958 	push	acc
      0002D4 08               [12]  959 	inc	r0
      0002D5 E6               [12]  960 	mov	a,@r0
      0002D6 C0 E0            [24]  961 	push	acc
      0002D8 E5 1D            [12]  962 	mov	a,_bp
      0002DA 24 F6            [12]  963 	add	a,#0xf6
      0002DC F8               [12]  964 	mov	r0,a
      0002DD 86 82            [24]  965 	mov	dpl, @r0
      0002DF 08               [12]  966 	inc	r0
      0002E0 86 83            [24]  967 	mov	dph, @r0
      0002E2 08               [12]  968 	inc	r0
      0002E3 86 F0            [24]  969 	mov	b, @r0
      0002E5 08               [12]  970 	inc	r0
      0002E6 E6               [12]  971 	mov	a, @r0
      0002E7 12 1A 32         [24]  972 	lcall	___fslt
      0002EA E5 81            [12]  973 	mov	a,sp
      0002EC 24 FC            [12]  974 	add	a,#0xfc
      0002EE F5 81            [12]  975 	mov	sp,a
      0002F0 D0 04            [24]  976 	pop	ar4
      0002F2 D0 05            [24]  977 	pop	ar5
      0002F4 D0 06            [24]  978 	pop	ar6
      0002F6 D0 07            [24]  979 	pop	ar7
      0002F8 E5 82            [12]  980 	mov	a, dpl
      0002FA 24 FF            [12]  981 	add	a,#0xff
      0002FC 92 00            [24]  982 	mov	b0,c
      0002FE 40 33            [24]  983 	jc	00106$
      000300 E5 1D            [12]  984 	mov	a,_bp
      000302 24 F5            [12]  985 	add	a,#0xf5
      000304 F8               [12]  986 	mov	r0,a
      000305 E6               [12]  987 	mov	a,@r0
      000306 60 0F            [24]  988 	jz	00115$
      000308 A8 1D            [24]  989 	mov	r0,_bp
      00030A 08               [12]  990 	inc	r0
      00030B E4               [12]  991 	clr	a
      00030C F6               [12]  992 	mov	@r0,a
      00030D 08               [12]  993 	inc	r0
      00030E F6               [12]  994 	mov	@r0,a
      00030F 08               [12]  995 	inc	r0
      000310 76 80            [12]  996 	mov	@r0,#0x80
      000312 08               [12]  997 	inc	r0
      000313 76 3F            [12]  998 	mov	@r0,#0x3f
      000315 80 0B            [24]  999 	sjmp	00116$
      000317                       1000 00115$:
      000317 A8 1D            [24] 1001 	mov	r0,_bp
      000319 08               [12] 1002 	inc	r0
      00031A E4               [12] 1003 	clr	a
      00031B F6               [12] 1004 	mov	@r0,a
      00031C 08               [12] 1005 	inc	r0
      00031D F6               [12] 1006 	mov	@r0,a
      00031E 08               [12] 1007 	inc	r0
      00031F F6               [12] 1008 	mov	@r0,a
      000320 08               [12] 1009 	inc	r0
      000321 F6               [12] 1010 	mov	@r0,a
      000322                       1011 00116$:
      000322 A8 1D            [24] 1012 	mov	r0,_bp
      000324 08               [12] 1013 	inc	r0
      000325 86 07            [24] 1014 	mov	ar7,@r0
      000327 08               [12] 1015 	inc	r0
      000328 86 06            [24] 1016 	mov	ar6,@r0
      00032A 08               [12] 1017 	inc	r0
      00032B 86 05            [24] 1018 	mov	ar5,@r0
      00032D 08               [12] 1019 	inc	r0
      00032E 86 04            [24] 1020 	mov	ar4,@r0
      000330 02 03 D4         [24] 1021 	ljmp	00110$
      000333                       1022 00106$:
      000333 C0 07            [24] 1023 	push	ar7
      000335 C0 06            [24] 1024 	push	ar6
      000337 C0 05            [24] 1025 	push	ar5
      000339 C0 04            [24] 1026 	push	ar4
      00033B C0 07            [24] 1027 	push	ar7
      00033D C0 06            [24] 1028 	push	ar6
      00033F C0 05            [24] 1029 	push	ar5
      000341 C0 04            [24] 1030 	push	ar4
      000343 E5 1D            [12] 1031 	mov	a,_bp
      000345 24 F6            [12] 1032 	add	a,#0xf6
      000347 F8               [12] 1033 	mov	r0,a
      000348 86 82            [24] 1034 	mov	dpl, @r0
      00034A 08               [12] 1035 	inc	r0
      00034B 86 83            [24] 1036 	mov	dph, @r0
      00034D 08               [12] 1037 	inc	r0
      00034E 86 F0            [24] 1038 	mov	b, @r0
      000350 08               [12] 1039 	inc	r0
      000351 E6               [12] 1040 	mov	a, @r0
      000352 12 18 F7         [24] 1041 	lcall	___fssub
      000355 A8 1D            [24] 1042 	mov	r0,_bp
      000357 08               [12] 1043 	inc	r0
      000358 A6 82            [24] 1044 	mov	@r0, dpl
      00035A 08               [12] 1045 	inc	r0
      00035B A6 83            [24] 1046 	mov	@r0, dph
      00035D 08               [12] 1047 	inc	r0
      00035E A6 F0            [24] 1048 	mov	@r0, b
      000360 08               [12] 1049 	inc	r0
      000361 F6               [12] 1050 	mov	@r0,a
      000362 E5 81            [12] 1051 	mov	a,sp
      000364 24 FC            [12] 1052 	add	a,#0xfc
      000366 F5 81            [12] 1053 	mov	sp,a
      000368 E5 1D            [12] 1054 	mov	a,_bp
      00036A 24 FA            [12] 1055 	add	a,#0xfa
      00036C F8               [12] 1056 	mov	r0,a
      00036D 86 82            [24] 1057 	mov	dpl, @r0
      00036F 08               [12] 1058 	inc	r0
      000370 86 83            [24] 1059 	mov	dph, @r0
      000372 08               [12] 1060 	inc	r0
      000373 86 F0            [24] 1061 	mov	b, @r0
      000375 08               [12] 1062 	inc	r0
      000376 E6               [12] 1063 	mov	a, @r0
      000377 12 18 F7         [24] 1064 	lcall	___fssub
      00037A AC 82            [24] 1065 	mov	r4, dpl
      00037C AD 83            [24] 1066 	mov	r5, dph
      00037E AE F0            [24] 1067 	mov	r6, b
      000380 FF               [12] 1068 	mov	r7, a
      000381 E5 81            [12] 1069 	mov	a,sp
      000383 24 FC            [12] 1070 	add	a,#0xfc
      000385 F5 81            [12] 1071 	mov	sp,a
      000387 C0 04            [24] 1072 	push	ar4
      000389 C0 05            [24] 1073 	push	ar5
      00038B C0 06            [24] 1074 	push	ar6
      00038D C0 07            [24] 1075 	push	ar7
      00038F A8 1D            [24] 1076 	mov	r0,_bp
      000391 08               [12] 1077 	inc	r0
      000392 86 82            [24] 1078 	mov	dpl, @r0
      000394 08               [12] 1079 	inc	r0
      000395 86 83            [24] 1080 	mov	dph, @r0
      000397 08               [12] 1081 	inc	r0
      000398 86 F0            [24] 1082 	mov	b, @r0
      00039A 08               [12] 1083 	inc	r0
      00039B E6               [12] 1084 	mov	a, @r0
      00039C 12 1B 79         [24] 1085 	lcall	___fsdiv
      00039F AF 82            [24] 1086 	mov	r7, dpl
      0003A1 AE 83            [24] 1087 	mov	r6, dph
      0003A3 AD F0            [24] 1088 	mov	r5, b
      0003A5 FC               [12] 1089 	mov	r4, a
      0003A6 E5 81            [12] 1090 	mov	a,sp
      0003A8 24 FC            [12] 1091 	add	a,#0xfc
      0003AA F5 81            [12] 1092 	mov	sp,a
      0003AC E5 1D            [12] 1093 	mov	a,_bp
      0003AE 24 F5            [12] 1094 	add	a,#0xf5
      0003B0 F8               [12] 1095 	mov	r0,a
      0003B1 E6               [12] 1096 	mov	a,@r0
      0003B2 70 20            [24] 1097 	jnz	00110$
      0003B4 C0 07            [24] 1098 	push	ar7
      0003B6 C0 06            [24] 1099 	push	ar6
      0003B8 C0 05            [24] 1100 	push	ar5
      0003BA C0 04            [24] 1101 	push	ar4
      0003BC 90 00 00         [24] 1102 	mov	dptr,#0x0000
      0003BF 75 F0 80         [24] 1103 	mov	b, #0x80
      0003C2 74 3F            [12] 1104 	mov	a, #0x3f
      0003C4 12 18 F7         [24] 1105 	lcall	___fssub
      0003C7 AF 82            [24] 1106 	mov	r7, dpl
      0003C9 AE 83            [24] 1107 	mov	r6, dph
      0003CB AD F0            [24] 1108 	mov	r5, b
      0003CD FC               [12] 1109 	mov	r4, a
      0003CE E5 81            [12] 1110 	mov	a,sp
      0003D0 24 FC            [12] 1111 	add	a,#0xfc
      0003D2 F5 81            [12] 1112 	mov	sp,a
      0003D4                       1113 00110$:
      0003D4 E5 1D            [12] 1114 	mov	a,_bp
      0003D6 24 F4            [12] 1115 	add	a,#0xf4
      0003D8 F8               [12] 1116 	mov	r0,a
      0003D9 E6               [12] 1117 	mov	a,@r0
      0003DA C0 E0            [24] 1118 	push	acc
      0003DC 8F 82            [24] 1119 	mov	dpl, r7
      0003DE 8E 83            [24] 1120 	mov	dph, r6
      0003E0 8D F0            [24] 1121 	mov	b, r5
      0003E2 EC               [12] 1122 	mov	a, r4
      0003E3 12 01 34         [24] 1123 	lcall	_fuzzy_8051_hedge
      0003E6 AC 82            [24] 1124 	mov	r4, dpl
      0003E8 AD 83            [24] 1125 	mov	r5, dph
      0003EA AE F0            [24] 1126 	mov	r6, b
      0003EC FF               [12] 1127 	mov	r7, a
      0003ED 15 81            [12] 1128 	dec	sp
      0003EF 8C 82            [24] 1129 	mov	dpl, r4
      0003F1 8D 83            [24] 1130 	mov	dph, r5
      0003F3 8E F0            [24] 1131 	mov	b, r6
      0003F5 EF               [12] 1132 	mov	a, r7
      0003F6                       1133 00111$:
      0003F6 85 1D 81         [24] 1134 	mov	sp,_bp
      0003F9 D0 1D            [24] 1135 	pop	_bp
                           000344  1136 	C$fuzzy.h$57$1_0$18 ==.
                           000344  1137 	XG$fuzzy_ramp$0$0 ==.
      0003FB 22               [24] 1138 	ret
                                   1139 ;------------------------------------------------------------
                                   1140 ;Allocation info for local variables in function 'fuzzy_triangle'
                                   1141 ;------------------------------------------------------------
                                   1142 ;b             Allocated to stack - _bp -6 +4 
                                   1143 ;c             Allocated to stack - _bp -10 +4 
                                   1144 ;x             Allocated to stack - _bp -14 +4 
                                   1145 ;hedge         Allocated to stack - _bp -15 +1 
                                   1146 ;a             Allocated to registers r7 r6 r5 r4 
                                   1147 ;result        Allocated to stack - _bp +1 +4 
                                   1148 ;sloc0         Allocated to stack - _bp +1 +4 
                                   1149 ;sloc1         Allocated to stack - _bp +5 +4 
                                   1150 ;------------------------------------------------------------
                           000345  1151 	G$fuzzy_triangle$0$0 ==.
                           000345  1152 	C$fuzzy.h$58$1_0$21 ==.
                                   1153 ;	../../fuzzy.h:58: float fuzzy_triangle(float a, float b, float c, float x, fuzzy_hedge_t hedge) { float result; if (a >= b || b >= c || x <= a || x >= c) result = 0.0f; else if (x == b) result = 1.0f; else if (x < b) result = (x - a) / (b - a); else result = (c - x) / (c - b); return fuzzy_8051_hedge(result, hedge); }
                                   1154 ;	-----------------------------------------
                                   1155 ;	 function fuzzy_triangle
                                   1156 ;	-----------------------------------------
      0003FC                       1157 _fuzzy_triangle:
      0003FC C0 1D            [24] 1158 	push	_bp
      0003FE 85 81 1D         [24] 1159 	mov	_bp,sp
      000401 AF 82            [24] 1160 	mov	r7,dpl
      000403 AE 83            [24] 1161 	mov	r6,dph
      000405 AD F0            [24] 1162 	mov	r5,b
      000407 FC               [12] 1163 	mov	r4,a
      000408 E5 81            [12] 1164 	mov	a,sp
      00040A 24 08            [12] 1165 	add	a,#0x08
      00040C F5 81            [12] 1166 	mov	sp,a
      00040E C0 07            [24] 1167 	push	ar7
      000410 C0 06            [24] 1168 	push	ar6
      000412 C0 05            [24] 1169 	push	ar5
      000414 C0 04            [24] 1170 	push	ar4
      000416 E5 1D            [12] 1171 	mov	a,_bp
      000418 24 FA            [12] 1172 	add	a,#0xfa
      00041A F8               [12] 1173 	mov	r0,a
      00041B E6               [12] 1174 	mov	a,@r0
      00041C C0 E0            [24] 1175 	push	acc
      00041E 08               [12] 1176 	inc	r0
      00041F E6               [12] 1177 	mov	a,@r0
      000420 C0 E0            [24] 1178 	push	acc
      000422 08               [12] 1179 	inc	r0
      000423 E6               [12] 1180 	mov	a,@r0
      000424 C0 E0            [24] 1181 	push	acc
      000426 08               [12] 1182 	inc	r0
      000427 E6               [12] 1183 	mov	a,@r0
      000428 C0 E0            [24] 1184 	push	acc
      00042A 8F 82            [24] 1185 	mov	dpl, r7
      00042C 8E 83            [24] 1186 	mov	dph, r6
      00042E 8D F0            [24] 1187 	mov	b, r5
      000430 EC               [12] 1188 	mov	a, r4
      000431 12 1A 32         [24] 1189 	lcall	___fslt
      000434 E5 81            [12] 1190 	mov	a,sp
      000436 24 FC            [12] 1191 	add	a,#0xfc
      000438 F5 81            [12] 1192 	mov	sp,a
      00043A D0 04            [24] 1193 	pop	ar4
      00043C D0 05            [24] 1194 	pop	ar5
      00043E D0 06            [24] 1195 	pop	ar6
      000440 D0 07            [24] 1196 	pop	ar7
      000442 E5 82            [12] 1197 	mov	a, dpl
      000444 24 FF            [12] 1198 	add	a,#0xff
      000446 92 00            [24] 1199 	mov	b0,c
      000448 40 03            [24] 1200 	jc	00145$
      00044A 02 05 14         [24] 1201 	ljmp	00107$
      00044D                       1202 00145$:
      00044D C0 07            [24] 1203 	push	ar7
      00044F C0 06            [24] 1204 	push	ar6
      000451 C0 05            [24] 1205 	push	ar5
      000453 C0 04            [24] 1206 	push	ar4
      000455 E5 1D            [12] 1207 	mov	a,_bp
      000457 24 F6            [12] 1208 	add	a,#0xf6
      000459 F8               [12] 1209 	mov	r0,a
      00045A E6               [12] 1210 	mov	a,@r0
      00045B C0 E0            [24] 1211 	push	acc
      00045D 08               [12] 1212 	inc	r0
      00045E E6               [12] 1213 	mov	a,@r0
      00045F C0 E0            [24] 1214 	push	acc
      000461 08               [12] 1215 	inc	r0
      000462 E6               [12] 1216 	mov	a,@r0
      000463 C0 E0            [24] 1217 	push	acc
      000465 08               [12] 1218 	inc	r0
      000466 E6               [12] 1219 	mov	a,@r0
      000467 C0 E0            [24] 1220 	push	acc
      000469 E5 1D            [12] 1221 	mov	a,_bp
      00046B 24 FA            [12] 1222 	add	a,#0xfa
      00046D F8               [12] 1223 	mov	r0,a
      00046E 86 82            [24] 1224 	mov	dpl, @r0
      000470 08               [12] 1225 	inc	r0
      000471 86 83            [24] 1226 	mov	dph, @r0
      000473 08               [12] 1227 	inc	r0
      000474 86 F0            [24] 1228 	mov	b, @r0
      000476 08               [12] 1229 	inc	r0
      000477 E6               [12] 1230 	mov	a, @r0
      000478 12 1A 32         [24] 1231 	lcall	___fslt
      00047B E5 81            [12] 1232 	mov	a,sp
      00047D 24 FC            [12] 1233 	add	a,#0xfc
      00047F F5 81            [12] 1234 	mov	sp,a
      000481 D0 04            [24] 1235 	pop	ar4
      000483 D0 05            [24] 1236 	pop	ar5
      000485 D0 06            [24] 1237 	pop	ar6
      000487 D0 07            [24] 1238 	pop	ar7
      000489 E5 82            [12] 1239 	mov	a, dpl
      00048B 24 FF            [12] 1240 	add	a,#0xff
      00048D 92 00            [24] 1241 	mov	b0,c
      00048F 40 03            [24] 1242 	jc	00146$
      000491 02 05 14         [24] 1243 	ljmp	00107$
      000494                       1244 00146$:
      000494 C0 07            [24] 1245 	push	ar7
      000496 C0 06            [24] 1246 	push	ar6
      000498 C0 05            [24] 1247 	push	ar5
      00049A C0 04            [24] 1248 	push	ar4
      00049C E5 1D            [12] 1249 	mov	a,_bp
      00049E 24 F2            [12] 1250 	add	a,#0xf2
      0004A0 F8               [12] 1251 	mov	r0,a
      0004A1 E6               [12] 1252 	mov	a,@r0
      0004A2 C0 E0            [24] 1253 	push	acc
      0004A4 08               [12] 1254 	inc	r0
      0004A5 E6               [12] 1255 	mov	a,@r0
      0004A6 C0 E0            [24] 1256 	push	acc
      0004A8 08               [12] 1257 	inc	r0
      0004A9 E6               [12] 1258 	mov	a,@r0
      0004AA C0 E0            [24] 1259 	push	acc
      0004AC 08               [12] 1260 	inc	r0
      0004AD E6               [12] 1261 	mov	a,@r0
      0004AE C0 E0            [24] 1262 	push	acc
      0004B0 8F 82            [24] 1263 	mov	dpl, r7
      0004B2 8E 83            [24] 1264 	mov	dph, r6
      0004B4 8D F0            [24] 1265 	mov	b, r5
      0004B6 EC               [12] 1266 	mov	a, r4
      0004B7 12 1A 32         [24] 1267 	lcall	___fslt
      0004BA E5 81            [12] 1268 	mov	a,sp
      0004BC 24 FC            [12] 1269 	add	a,#0xfc
      0004BE F5 81            [12] 1270 	mov	sp,a
      0004C0 D0 04            [24] 1271 	pop	ar4
      0004C2 D0 05            [24] 1272 	pop	ar5
      0004C4 D0 06            [24] 1273 	pop	ar6
      0004C6 D0 07            [24] 1274 	pop	ar7
      0004C8 E5 82            [12] 1275 	mov	a, dpl
      0004CA 24 FF            [12] 1276 	add	a,#0xff
      0004CC 92 00            [24] 1277 	mov	b0,c
      0004CE 50 44            [24] 1278 	jnc	00107$
      0004D0 C0 07            [24] 1279 	push	ar7
      0004D2 C0 06            [24] 1280 	push	ar6
      0004D4 C0 05            [24] 1281 	push	ar5
      0004D6 C0 04            [24] 1282 	push	ar4
      0004D8 E5 1D            [12] 1283 	mov	a,_bp
      0004DA 24 F6            [12] 1284 	add	a,#0xf6
      0004DC F8               [12] 1285 	mov	r0,a
      0004DD E6               [12] 1286 	mov	a,@r0
      0004DE C0 E0            [24] 1287 	push	acc
      0004E0 08               [12] 1288 	inc	r0
      0004E1 E6               [12] 1289 	mov	a,@r0
      0004E2 C0 E0            [24] 1290 	push	acc
      0004E4 08               [12] 1291 	inc	r0
      0004E5 E6               [12] 1292 	mov	a,@r0
      0004E6 C0 E0            [24] 1293 	push	acc
      0004E8 08               [12] 1294 	inc	r0
      0004E9 E6               [12] 1295 	mov	a,@r0
      0004EA C0 E0            [24] 1296 	push	acc
      0004EC E5 1D            [12] 1297 	mov	a,_bp
      0004EE 24 F2            [12] 1298 	add	a,#0xf2
      0004F0 F8               [12] 1299 	mov	r0,a
      0004F1 86 82            [24] 1300 	mov	dpl, @r0
      0004F3 08               [12] 1301 	inc	r0
      0004F4 86 83            [24] 1302 	mov	dph, @r0
      0004F6 08               [12] 1303 	inc	r0
      0004F7 86 F0            [24] 1304 	mov	b, @r0
      0004F9 08               [12] 1305 	inc	r0
      0004FA E6               [12] 1306 	mov	a, @r0
      0004FB 12 1A 32         [24] 1307 	lcall	___fslt
      0004FE E5 81            [12] 1308 	mov	a,sp
      000500 24 FC            [12] 1309 	add	a,#0xfc
      000502 F5 81            [12] 1310 	mov	sp,a
      000504 D0 04            [24] 1311 	pop	ar4
      000506 D0 05            [24] 1312 	pop	ar5
      000508 D0 06            [24] 1313 	pop	ar6
      00050A D0 07            [24] 1314 	pop	ar7
      00050C E5 82            [12] 1315 	mov	a, dpl
      00050E 24 FF            [12] 1316 	add	a,#0xff
      000510 92 00            [24] 1317 	mov	b0,c
      000512 40 0E            [24] 1318 	jc	00108$
      000514                       1319 00107$:
      000514 A8 1D            [24] 1320 	mov	r0,_bp
      000516 08               [12] 1321 	inc	r0
      000517 E4               [12] 1322 	clr	a
      000518 F6               [12] 1323 	mov	@r0,a
      000519 08               [12] 1324 	inc	r0
      00051A F6               [12] 1325 	mov	@r0,a
      00051B 08               [12] 1326 	inc	r0
      00051C F6               [12] 1327 	mov	@r0,a
      00051D 08               [12] 1328 	inc	r0
      00051E F6               [12] 1329 	mov	@r0,a
      00051F 02 06 DA         [24] 1330 	ljmp	00109$
      000522                       1331 00108$:
      000522 C0 07            [24] 1332 	push	ar7
      000524 C0 06            [24] 1333 	push	ar6
      000526 C0 05            [24] 1334 	push	ar5
      000528 C0 04            [24] 1335 	push	ar4
      00052A E5 1D            [12] 1336 	mov	a,_bp
      00052C 24 FA            [12] 1337 	add	a,#0xfa
      00052E F8               [12] 1338 	mov	r0,a
      00052F E6               [12] 1339 	mov	a,@r0
      000530 C0 E0            [24] 1340 	push	acc
      000532 08               [12] 1341 	inc	r0
      000533 E6               [12] 1342 	mov	a,@r0
      000534 C0 E0            [24] 1343 	push	acc
      000536 08               [12] 1344 	inc	r0
      000537 E6               [12] 1345 	mov	a,@r0
      000538 C0 E0            [24] 1346 	push	acc
      00053A 08               [12] 1347 	inc	r0
      00053B E6               [12] 1348 	mov	a,@r0
      00053C C0 E0            [24] 1349 	push	acc
      00053E E5 1D            [12] 1350 	mov	a,_bp
      000540 24 F2            [12] 1351 	add	a,#0xf2
      000542 F8               [12] 1352 	mov	r0,a
      000543 86 82            [24] 1353 	mov	dpl, @r0
      000545 08               [12] 1354 	inc	r0
      000546 86 83            [24] 1355 	mov	dph, @r0
      000548 08               [12] 1356 	inc	r0
      000549 86 F0            [24] 1357 	mov	b, @r0
      00054B 08               [12] 1358 	inc	r0
      00054C E6               [12] 1359 	mov	a, @r0
      00054D 12 1A 06         [24] 1360 	lcall	___fseq
      000550 AB 82            [24] 1361 	mov	r3, dpl
      000552 E5 81            [12] 1362 	mov	a,sp
      000554 24 FC            [12] 1363 	add	a,#0xfc
      000556 F5 81            [12] 1364 	mov	sp,a
      000558 D0 04            [24] 1365 	pop	ar4
      00055A D0 05            [24] 1366 	pop	ar5
      00055C D0 06            [24] 1367 	pop	ar6
      00055E D0 07            [24] 1368 	pop	ar7
      000560 EB               [12] 1369 	mov	a,r3
      000561 60 10            [24] 1370 	jz	00105$
      000563 A8 1D            [24] 1371 	mov	r0,_bp
      000565 08               [12] 1372 	inc	r0
      000566 E4               [12] 1373 	clr	a
      000567 F6               [12] 1374 	mov	@r0,a
      000568 08               [12] 1375 	inc	r0
      000569 F6               [12] 1376 	mov	@r0,a
      00056A 08               [12] 1377 	inc	r0
      00056B 76 80            [12] 1378 	mov	@r0,#0x80
      00056D 08               [12] 1379 	inc	r0
      00056E 76 3F            [12] 1380 	mov	@r0,#0x3f
      000570 02 06 DA         [24] 1381 	ljmp	00109$
      000573                       1382 00105$:
      000573 C0 07            [24] 1383 	push	ar7
      000575 C0 06            [24] 1384 	push	ar6
      000577 C0 05            [24] 1385 	push	ar5
      000579 C0 04            [24] 1386 	push	ar4
      00057B E5 1D            [12] 1387 	mov	a,_bp
      00057D 24 FA            [12] 1388 	add	a,#0xfa
      00057F F8               [12] 1389 	mov	r0,a
      000580 E6               [12] 1390 	mov	a,@r0
      000581 C0 E0            [24] 1391 	push	acc
      000583 08               [12] 1392 	inc	r0
      000584 E6               [12] 1393 	mov	a,@r0
      000585 C0 E0            [24] 1394 	push	acc
      000587 08               [12] 1395 	inc	r0
      000588 E6               [12] 1396 	mov	a,@r0
      000589 C0 E0            [24] 1397 	push	acc
      00058B 08               [12] 1398 	inc	r0
      00058C E6               [12] 1399 	mov	a,@r0
      00058D C0 E0            [24] 1400 	push	acc
      00058F E5 1D            [12] 1401 	mov	a,_bp
      000591 24 F2            [12] 1402 	add	a,#0xf2
      000593 F8               [12] 1403 	mov	r0,a
      000594 86 82            [24] 1404 	mov	dpl, @r0
      000596 08               [12] 1405 	inc	r0
      000597 86 83            [24] 1406 	mov	dph, @r0
      000599 08               [12] 1407 	inc	r0
      00059A 86 F0            [24] 1408 	mov	b, @r0
      00059C 08               [12] 1409 	inc	r0
      00059D E6               [12] 1410 	mov	a, @r0
      00059E 12 1A 32         [24] 1411 	lcall	___fslt
      0005A1 AB 82            [24] 1412 	mov	r3, dpl
      0005A3 E5 81            [12] 1413 	mov	a,sp
      0005A5 24 FC            [12] 1414 	add	a,#0xfc
      0005A7 F5 81            [12] 1415 	mov	sp,a
      0005A9 D0 04            [24] 1416 	pop	ar4
      0005AB D0 05            [24] 1417 	pop	ar5
      0005AD D0 06            [24] 1418 	pop	ar6
      0005AF D0 07            [24] 1419 	pop	ar7
      0005B1 EB               [12] 1420 	mov	a,r3
      0005B2 70 03            [24] 1421 	jnz	00150$
      0005B4 02 06 3E         [24] 1422 	ljmp	00102$
      0005B7                       1423 00150$:
      0005B7 C0 07            [24] 1424 	push	ar7
      0005B9 C0 06            [24] 1425 	push	ar6
      0005BB C0 05            [24] 1426 	push	ar5
      0005BD C0 04            [24] 1427 	push	ar4
      0005BF C0 07            [24] 1428 	push	ar7
      0005C1 C0 06            [24] 1429 	push	ar6
      0005C3 C0 05            [24] 1430 	push	ar5
      0005C5 C0 04            [24] 1431 	push	ar4
      0005C7 E5 1D            [12] 1432 	mov	a,_bp
      0005C9 24 F2            [12] 1433 	add	a,#0xf2
      0005CB F8               [12] 1434 	mov	r0,a
      0005CC 86 82            [24] 1435 	mov	dpl, @r0
      0005CE 08               [12] 1436 	inc	r0
      0005CF 86 83            [24] 1437 	mov	dph, @r0
      0005D1 08               [12] 1438 	inc	r0
      0005D2 86 F0            [24] 1439 	mov	b, @r0
      0005D4 08               [12] 1440 	inc	r0
      0005D5 E6               [12] 1441 	mov	a, @r0
      0005D6 12 18 F7         [24] 1442 	lcall	___fssub
      0005D9 C8               [12] 1443 	xch	a,r0
      0005DA E5 1D            [12] 1444 	mov	a,_bp
      0005DC 24 05            [12] 1445 	add	a,#0x05
      0005DE C8               [12] 1446 	xch	a,r0
      0005DF A6 82            [24] 1447 	mov	@r0, dpl
      0005E1 08               [12] 1448 	inc	r0
      0005E2 A6 83            [24] 1449 	mov	@r0, dph
      0005E4 08               [12] 1450 	inc	r0
      0005E5 A6 F0            [24] 1451 	mov	@r0, b
      0005E7 08               [12] 1452 	inc	r0
      0005E8 F6               [12] 1453 	mov	@r0,a
      0005E9 E5 81            [12] 1454 	mov	a,sp
      0005EB 24 FC            [12] 1455 	add	a,#0xfc
      0005ED F5 81            [12] 1456 	mov	sp,a
      0005EF E5 1D            [12] 1457 	mov	a,_bp
      0005F1 24 FA            [12] 1458 	add	a,#0xfa
      0005F3 F8               [12] 1459 	mov	r0,a
      0005F4 86 82            [24] 1460 	mov	dpl, @r0
      0005F6 08               [12] 1461 	inc	r0
      0005F7 86 83            [24] 1462 	mov	dph, @r0
      0005F9 08               [12] 1463 	inc	r0
      0005FA 86 F0            [24] 1464 	mov	b, @r0
      0005FC 08               [12] 1465 	inc	r0
      0005FD E6               [12] 1466 	mov	a, @r0
      0005FE 12 18 F7         [24] 1467 	lcall	___fssub
      000601 AC 82            [24] 1468 	mov	r4, dpl
      000603 AD 83            [24] 1469 	mov	r5, dph
      000605 AE F0            [24] 1470 	mov	r6, b
      000607 FF               [12] 1471 	mov	r7, a
      000608 E5 81            [12] 1472 	mov	a,sp
      00060A 24 FC            [12] 1473 	add	a,#0xfc
      00060C F5 81            [12] 1474 	mov	sp,a
      00060E C0 04            [24] 1475 	push	ar4
      000610 C0 05            [24] 1476 	push	ar5
      000612 C0 06            [24] 1477 	push	ar6
      000614 C0 07            [24] 1478 	push	ar7
      000616 E5 1D            [12] 1479 	mov	a,_bp
      000618 24 05            [12] 1480 	add	a,#0x05
      00061A F8               [12] 1481 	mov	r0,a
      00061B 86 82            [24] 1482 	mov	dpl, @r0
      00061D 08               [12] 1483 	inc	r0
      00061E 86 83            [24] 1484 	mov	dph, @r0
      000620 08               [12] 1485 	inc	r0
      000621 86 F0            [24] 1486 	mov	b, @r0
      000623 08               [12] 1487 	inc	r0
      000624 E6               [12] 1488 	mov	a, @r0
      000625 12 1B 79         [24] 1489 	lcall	___fsdiv
      000628 A8 1D            [24] 1490 	mov	r0,_bp
      00062A 08               [12] 1491 	inc	r0
      00062B A6 82            [24] 1492 	mov	@r0, dpl
      00062D 08               [12] 1493 	inc	r0
      00062E A6 83            [24] 1494 	mov	@r0, dph
      000630 08               [12] 1495 	inc	r0
      000631 A6 F0            [24] 1496 	mov	@r0, b
      000633 08               [12] 1497 	inc	r0
      000634 F6               [12] 1498 	mov	@r0,a
      000635 E5 81            [12] 1499 	mov	a,sp
      000637 24 FC            [12] 1500 	add	a,#0xfc
      000639 F5 81            [12] 1501 	mov	sp,a
      00063B 02 06 DA         [24] 1502 	ljmp	00109$
      00063E                       1503 00102$:
      00063E E5 1D            [12] 1504 	mov	a,_bp
      000640 24 F2            [12] 1505 	add	a,#0xf2
      000642 F8               [12] 1506 	mov	r0,a
      000643 E6               [12] 1507 	mov	a,@r0
      000644 C0 E0            [24] 1508 	push	acc
      000646 08               [12] 1509 	inc	r0
      000647 E6               [12] 1510 	mov	a,@r0
      000648 C0 E0            [24] 1511 	push	acc
      00064A 08               [12] 1512 	inc	r0
      00064B E6               [12] 1513 	mov	a,@r0
      00064C C0 E0            [24] 1514 	push	acc
      00064E 08               [12] 1515 	inc	r0
      00064F E6               [12] 1516 	mov	a,@r0
      000650 C0 E0            [24] 1517 	push	acc
      000652 E5 1D            [12] 1518 	mov	a,_bp
      000654 24 F6            [12] 1519 	add	a,#0xf6
      000656 F8               [12] 1520 	mov	r0,a
      000657 86 82            [24] 1521 	mov	dpl, @r0
      000659 08               [12] 1522 	inc	r0
      00065A 86 83            [24] 1523 	mov	dph, @r0
      00065C 08               [12] 1524 	inc	r0
      00065D 86 F0            [24] 1525 	mov	b, @r0
      00065F 08               [12] 1526 	inc	r0
      000660 E6               [12] 1527 	mov	a, @r0
      000661 12 18 F7         [24] 1528 	lcall	___fssub
      000664 C8               [12] 1529 	xch	a,r0
      000665 E5 1D            [12] 1530 	mov	a,_bp
      000667 24 05            [12] 1531 	add	a,#0x05
      000669 C8               [12] 1532 	xch	a,r0
      00066A A6 82            [24] 1533 	mov	@r0, dpl
      00066C 08               [12] 1534 	inc	r0
      00066D A6 83            [24] 1535 	mov	@r0, dph
      00066F 08               [12] 1536 	inc	r0
      000670 A6 F0            [24] 1537 	mov	@r0, b
      000672 08               [12] 1538 	inc	r0
      000673 F6               [12] 1539 	mov	@r0,a
      000674 E5 81            [12] 1540 	mov	a,sp
      000676 24 FC            [12] 1541 	add	a,#0xfc
      000678 F5 81            [12] 1542 	mov	sp,a
      00067A E5 1D            [12] 1543 	mov	a,_bp
      00067C 24 FA            [12] 1544 	add	a,#0xfa
      00067E F8               [12] 1545 	mov	r0,a
      00067F E6               [12] 1546 	mov	a,@r0
      000680 C0 E0            [24] 1547 	push	acc
      000682 08               [12] 1548 	inc	r0
      000683 E6               [12] 1549 	mov	a,@r0
      000684 C0 E0            [24] 1550 	push	acc
      000686 08               [12] 1551 	inc	r0
      000687 E6               [12] 1552 	mov	a,@r0
      000688 C0 E0            [24] 1553 	push	acc
      00068A 08               [12] 1554 	inc	r0
      00068B E6               [12] 1555 	mov	a,@r0
      00068C C0 E0            [24] 1556 	push	acc
      00068E E5 1D            [12] 1557 	mov	a,_bp
      000690 24 F6            [12] 1558 	add	a,#0xf6
      000692 F8               [12] 1559 	mov	r0,a
      000693 86 82            [24] 1560 	mov	dpl, @r0
      000695 08               [12] 1561 	inc	r0
      000696 86 83            [24] 1562 	mov	dph, @r0
      000698 08               [12] 1563 	inc	r0
      000699 86 F0            [24] 1564 	mov	b, @r0
      00069B 08               [12] 1565 	inc	r0
      00069C E6               [12] 1566 	mov	a, @r0
      00069D 12 18 F7         [24] 1567 	lcall	___fssub
      0006A0 AA 82            [24] 1568 	mov	r2, dpl
      0006A2 AB 83            [24] 1569 	mov	r3, dph
      0006A4 AE F0            [24] 1570 	mov	r6, b
      0006A6 FF               [12] 1571 	mov	r7, a
      0006A7 E5 81            [12] 1572 	mov	a,sp
      0006A9 24 FC            [12] 1573 	add	a,#0xfc
      0006AB F5 81            [12] 1574 	mov	sp,a
      0006AD C0 02            [24] 1575 	push	ar2
      0006AF C0 03            [24] 1576 	push	ar3
      0006B1 C0 06            [24] 1577 	push	ar6
      0006B3 C0 07            [24] 1578 	push	ar7
      0006B5 E5 1D            [12] 1579 	mov	a,_bp
      0006B7 24 05            [12] 1580 	add	a,#0x05
      0006B9 F8               [12] 1581 	mov	r0,a
      0006BA 86 82            [24] 1582 	mov	dpl, @r0
      0006BC 08               [12] 1583 	inc	r0
      0006BD 86 83            [24] 1584 	mov	dph, @r0
      0006BF 08               [12] 1585 	inc	r0
      0006C0 86 F0            [24] 1586 	mov	b, @r0
      0006C2 08               [12] 1587 	inc	r0
      0006C3 E6               [12] 1588 	mov	a, @r0
      0006C4 12 1B 79         [24] 1589 	lcall	___fsdiv
      0006C7 A8 1D            [24] 1590 	mov	r0,_bp
      0006C9 08               [12] 1591 	inc	r0
      0006CA A6 82            [24] 1592 	mov	@r0, dpl
      0006CC 08               [12] 1593 	inc	r0
      0006CD A6 83            [24] 1594 	mov	@r0, dph
      0006CF 08               [12] 1595 	inc	r0
      0006D0 A6 F0            [24] 1596 	mov	@r0, b
      0006D2 08               [12] 1597 	inc	r0
      0006D3 F6               [12] 1598 	mov	@r0,a
      0006D4 E5 81            [12] 1599 	mov	a,sp
      0006D6 24 FC            [12] 1600 	add	a,#0xfc
      0006D8 F5 81            [12] 1601 	mov	sp,a
      0006DA                       1602 00109$:
      0006DA E5 1D            [12] 1603 	mov	a,_bp
      0006DC 24 F1            [12] 1604 	add	a,#0xf1
      0006DE F8               [12] 1605 	mov	r0,a
      0006DF E6               [12] 1606 	mov	a,@r0
      0006E0 C0 E0            [24] 1607 	push	acc
      0006E2 A8 1D            [24] 1608 	mov	r0,_bp
      0006E4 08               [12] 1609 	inc	r0
      0006E5 86 82            [24] 1610 	mov	dpl, @r0
      0006E7 08               [12] 1611 	inc	r0
      0006E8 86 83            [24] 1612 	mov	dph, @r0
      0006EA 08               [12] 1613 	inc	r0
      0006EB 86 F0            [24] 1614 	mov	b, @r0
      0006ED 08               [12] 1615 	inc	r0
      0006EE E6               [12] 1616 	mov	a, @r0
      0006EF 12 01 34         [24] 1617 	lcall	_fuzzy_8051_hedge
      0006F2 AC 82            [24] 1618 	mov	r4, dpl
      0006F4 AD 83            [24] 1619 	mov	r5, dph
      0006F6 AE F0            [24] 1620 	mov	r6, b
      0006F8 FF               [12] 1621 	mov	r7, a
      0006F9 15 81            [12] 1622 	dec	sp
      0006FB 8C 82            [24] 1623 	mov	dpl, r4
      0006FD 8D 83            [24] 1624 	mov	dph, r5
      0006FF 8E F0            [24] 1625 	mov	b, r6
      000701 EF               [12] 1626 	mov	a, r7
      000702 85 1D 81         [24] 1627 	mov	sp,_bp
      000705 D0 1D            [24] 1628 	pop	_bp
                           000650  1629 	C$fuzzy.h$58$1_0$21 ==.
                           000650  1630 	XG$fuzzy_triangle$0$0 ==.
      000707 22               [24] 1631 	ret
                                   1632 ;------------------------------------------------------------
                                   1633 ;Allocation info for local variables in function 'fuzzy_trapezoid'
                                   1634 ;------------------------------------------------------------
                                   1635 ;b             Allocated to stack - _bp -6 +4 
                                   1636 ;c             Allocated to stack - _bp -10 +4 
                                   1637 ;d             Allocated to stack - _bp -14 +4 
                                   1638 ;x             Allocated to stack - _bp -18 +4 
                                   1639 ;hedge         Allocated to stack - _bp -19 +1 
                                   1640 ;a             Allocated to registers r7 r6 r5 r4 
                                   1641 ;result        Allocated to stack - _bp +1 +4 
                                   1642 ;sloc0         Allocated to stack - _bp +1 +4 
                                   1643 ;sloc1         Allocated to stack - _bp +5 +4 
                                   1644 ;------------------------------------------------------------
                           000651  1645 	G$fuzzy_trapezoid$0$0 ==.
                           000651  1646 	C$fuzzy.h$59$1_0$23 ==.
                                   1647 ;	../../fuzzy.h:59: float fuzzy_trapezoid(float a, float b, float c, float d, float x, fuzzy_hedge_t hedge) { float result; if (a >= b || b > c || c >= d || x <= a || x >= d) result = 0.0f; else if (x >= b && x <= c) result = 1.0f; else if (x < b) result = (x - a) / (b - a); else result = (d - x) / (d - c); return fuzzy_8051_hedge(result, hedge); }
                                   1648 ;	-----------------------------------------
                                   1649 ;	 function fuzzy_trapezoid
                                   1650 ;	-----------------------------------------
      000708                       1651 _fuzzy_trapezoid:
      000708 C0 1D            [24] 1652 	push	_bp
      00070A 85 81 1D         [24] 1653 	mov	_bp,sp
      00070D AF 82            [24] 1654 	mov	r7,dpl
      00070F AE 83            [24] 1655 	mov	r6,dph
      000711 AD F0            [24] 1656 	mov	r5,b
      000713 FC               [12] 1657 	mov	r4,a
      000714 E5 81            [12] 1658 	mov	a,sp
      000716 24 08            [12] 1659 	add	a,#0x08
      000718 F5 81            [12] 1660 	mov	sp,a
      00071A C0 07            [24] 1661 	push	ar7
      00071C C0 06            [24] 1662 	push	ar6
      00071E C0 05            [24] 1663 	push	ar5
      000720 C0 04            [24] 1664 	push	ar4
      000722 E5 1D            [12] 1665 	mov	a,_bp
      000724 24 FA            [12] 1666 	add	a,#0xfa
      000726 F8               [12] 1667 	mov	r0,a
      000727 E6               [12] 1668 	mov	a,@r0
      000728 C0 E0            [24] 1669 	push	acc
      00072A 08               [12] 1670 	inc	r0
      00072B E6               [12] 1671 	mov	a,@r0
      00072C C0 E0            [24] 1672 	push	acc
      00072E 08               [12] 1673 	inc	r0
      00072F E6               [12] 1674 	mov	a,@r0
      000730 C0 E0            [24] 1675 	push	acc
      000732 08               [12] 1676 	inc	r0
      000733 E6               [12] 1677 	mov	a,@r0
      000734 C0 E0            [24] 1678 	push	acc
      000736 8F 82            [24] 1679 	mov	dpl, r7
      000738 8E 83            [24] 1680 	mov	dph, r6
      00073A 8D F0            [24] 1681 	mov	b, r5
      00073C EC               [12] 1682 	mov	a, r4
      00073D 12 1A 32         [24] 1683 	lcall	___fslt
      000740 E5 81            [12] 1684 	mov	a,sp
      000742 24 FC            [12] 1685 	add	a,#0xfc
      000744 F5 81            [12] 1686 	mov	sp,a
      000746 D0 04            [24] 1687 	pop	ar4
      000748 D0 05            [24] 1688 	pop	ar5
      00074A D0 06            [24] 1689 	pop	ar6
      00074C D0 07            [24] 1690 	pop	ar7
      00074E E5 82            [12] 1691 	mov	a, dpl
      000750 24 FF            [12] 1692 	add	a,#0xff
      000752 92 00            [24] 1693 	mov	b0,c
      000754 40 03            [24] 1694 	jc	00159$
      000756 02 08 64         [24] 1695 	ljmp	00108$
      000759                       1696 00159$:
      000759 C0 07            [24] 1697 	push	ar7
      00075B C0 06            [24] 1698 	push	ar6
      00075D C0 05            [24] 1699 	push	ar5
      00075F C0 04            [24] 1700 	push	ar4
      000761 E5 1D            [12] 1701 	mov	a,_bp
      000763 24 FA            [12] 1702 	add	a,#0xfa
      000765 F8               [12] 1703 	mov	r0,a
      000766 E6               [12] 1704 	mov	a,@r0
      000767 C0 E0            [24] 1705 	push	acc
      000769 08               [12] 1706 	inc	r0
      00076A E6               [12] 1707 	mov	a,@r0
      00076B C0 E0            [24] 1708 	push	acc
      00076D 08               [12] 1709 	inc	r0
      00076E E6               [12] 1710 	mov	a,@r0
      00076F C0 E0            [24] 1711 	push	acc
      000771 08               [12] 1712 	inc	r0
      000772 E6               [12] 1713 	mov	a,@r0
      000773 C0 E0            [24] 1714 	push	acc
      000775 E5 1D            [12] 1715 	mov	a,_bp
      000777 24 F6            [12] 1716 	add	a,#0xf6
      000779 F8               [12] 1717 	mov	r0,a
      00077A 86 82            [24] 1718 	mov	dpl, @r0
      00077C 08               [12] 1719 	inc	r0
      00077D 86 83            [24] 1720 	mov	dph, @r0
      00077F 08               [12] 1721 	inc	r0
      000780 86 F0            [24] 1722 	mov	b, @r0
      000782 08               [12] 1723 	inc	r0
      000783 E6               [12] 1724 	mov	a, @r0
      000784 12 1A 32         [24] 1725 	lcall	___fslt
      000787 AB 82            [24] 1726 	mov	r3, dpl
      000789 E5 81            [12] 1727 	mov	a,sp
      00078B 24 FC            [12] 1728 	add	a,#0xfc
      00078D F5 81            [12] 1729 	mov	sp,a
      00078F D0 04            [24] 1730 	pop	ar4
      000791 D0 05            [24] 1731 	pop	ar5
      000793 D0 06            [24] 1732 	pop	ar6
      000795 D0 07            [24] 1733 	pop	ar7
      000797 EB               [12] 1734 	mov	a,r3
      000798 60 03            [24] 1735 	jz	00160$
      00079A 02 08 64         [24] 1736 	ljmp	00108$
      00079D                       1737 00160$:
      00079D C0 07            [24] 1738 	push	ar7
      00079F C0 06            [24] 1739 	push	ar6
      0007A1 C0 05            [24] 1740 	push	ar5
      0007A3 C0 04            [24] 1741 	push	ar4
      0007A5 E5 1D            [12] 1742 	mov	a,_bp
      0007A7 24 F2            [12] 1743 	add	a,#0xf2
      0007A9 F8               [12] 1744 	mov	r0,a
      0007AA E6               [12] 1745 	mov	a,@r0
      0007AB C0 E0            [24] 1746 	push	acc
      0007AD 08               [12] 1747 	inc	r0
      0007AE E6               [12] 1748 	mov	a,@r0
      0007AF C0 E0            [24] 1749 	push	acc
      0007B1 08               [12] 1750 	inc	r0
      0007B2 E6               [12] 1751 	mov	a,@r0
      0007B3 C0 E0            [24] 1752 	push	acc
      0007B5 08               [12] 1753 	inc	r0
      0007B6 E6               [12] 1754 	mov	a,@r0
      0007B7 C0 E0            [24] 1755 	push	acc
      0007B9 E5 1D            [12] 1756 	mov	a,_bp
      0007BB 24 F6            [12] 1757 	add	a,#0xf6
      0007BD F8               [12] 1758 	mov	r0,a
      0007BE 86 82            [24] 1759 	mov	dpl, @r0
      0007C0 08               [12] 1760 	inc	r0
      0007C1 86 83            [24] 1761 	mov	dph, @r0
      0007C3 08               [12] 1762 	inc	r0
      0007C4 86 F0            [24] 1763 	mov	b, @r0
      0007C6 08               [12] 1764 	inc	r0
      0007C7 E6               [12] 1765 	mov	a, @r0
      0007C8 12 1A 32         [24] 1766 	lcall	___fslt
      0007CB E5 81            [12] 1767 	mov	a,sp
      0007CD 24 FC            [12] 1768 	add	a,#0xfc
      0007CF F5 81            [12] 1769 	mov	sp,a
      0007D1 D0 04            [24] 1770 	pop	ar4
      0007D3 D0 05            [24] 1771 	pop	ar5
      0007D5 D0 06            [24] 1772 	pop	ar6
      0007D7 D0 07            [24] 1773 	pop	ar7
      0007D9 E5 82            [12] 1774 	mov	a, dpl
      0007DB 24 FF            [12] 1775 	add	a,#0xff
      0007DD 92 00            [24] 1776 	mov	b0,c
      0007DF 40 03            [24] 1777 	jc	00161$
      0007E1 02 08 64         [24] 1778 	ljmp	00108$
      0007E4                       1779 00161$:
      0007E4 C0 07            [24] 1780 	push	ar7
      0007E6 C0 06            [24] 1781 	push	ar6
      0007E8 C0 05            [24] 1782 	push	ar5
      0007EA C0 04            [24] 1783 	push	ar4
      0007EC E5 1D            [12] 1784 	mov	a,_bp
      0007EE 24 EE            [12] 1785 	add	a,#0xee
      0007F0 F8               [12] 1786 	mov	r0,a
      0007F1 E6               [12] 1787 	mov	a,@r0
      0007F2 C0 E0            [24] 1788 	push	acc
      0007F4 08               [12] 1789 	inc	r0
      0007F5 E6               [12] 1790 	mov	a,@r0
      0007F6 C0 E0            [24] 1791 	push	acc
      0007F8 08               [12] 1792 	inc	r0
      0007F9 E6               [12] 1793 	mov	a,@r0
      0007FA C0 E0            [24] 1794 	push	acc
      0007FC 08               [12] 1795 	inc	r0
      0007FD E6               [12] 1796 	mov	a,@r0
      0007FE C0 E0            [24] 1797 	push	acc
      000800 8F 82            [24] 1798 	mov	dpl, r7
      000802 8E 83            [24] 1799 	mov	dph, r6
      000804 8D F0            [24] 1800 	mov	b, r5
      000806 EC               [12] 1801 	mov	a, r4
      000807 12 1A 32         [24] 1802 	lcall	___fslt
      00080A E5 81            [12] 1803 	mov	a,sp
      00080C 24 FC            [12] 1804 	add	a,#0xfc
      00080E F5 81            [12] 1805 	mov	sp,a
      000810 D0 04            [24] 1806 	pop	ar4
      000812 D0 05            [24] 1807 	pop	ar5
      000814 D0 06            [24] 1808 	pop	ar6
      000816 D0 07            [24] 1809 	pop	ar7
      000818 E5 82            [12] 1810 	mov	a, dpl
      00081A 24 FF            [12] 1811 	add	a,#0xff
      00081C 92 00            [24] 1812 	mov	b0,c
      00081E 50 44            [24] 1813 	jnc	00108$
      000820 C0 07            [24] 1814 	push	ar7
      000822 C0 06            [24] 1815 	push	ar6
      000824 C0 05            [24] 1816 	push	ar5
      000826 C0 04            [24] 1817 	push	ar4
      000828 E5 1D            [12] 1818 	mov	a,_bp
      00082A 24 F2            [12] 1819 	add	a,#0xf2
      00082C F8               [12] 1820 	mov	r0,a
      00082D E6               [12] 1821 	mov	a,@r0
      00082E C0 E0            [24] 1822 	push	acc
      000830 08               [12] 1823 	inc	r0
      000831 E6               [12] 1824 	mov	a,@r0
      000832 C0 E0            [24] 1825 	push	acc
      000834 08               [12] 1826 	inc	r0
      000835 E6               [12] 1827 	mov	a,@r0
      000836 C0 E0            [24] 1828 	push	acc
      000838 08               [12] 1829 	inc	r0
      000839 E6               [12] 1830 	mov	a,@r0
      00083A C0 E0            [24] 1831 	push	acc
      00083C E5 1D            [12] 1832 	mov	a,_bp
      00083E 24 EE            [12] 1833 	add	a,#0xee
      000840 F8               [12] 1834 	mov	r0,a
      000841 86 82            [24] 1835 	mov	dpl, @r0
      000843 08               [12] 1836 	inc	r0
      000844 86 83            [24] 1837 	mov	dph, @r0
      000846 08               [12] 1838 	inc	r0
      000847 86 F0            [24] 1839 	mov	b, @r0
      000849 08               [12] 1840 	inc	r0
      00084A E6               [12] 1841 	mov	a, @r0
      00084B 12 1A 32         [24] 1842 	lcall	___fslt
      00084E E5 81            [12] 1843 	mov	a,sp
      000850 24 FC            [12] 1844 	add	a,#0xfc
      000852 F5 81            [12] 1845 	mov	sp,a
      000854 D0 04            [24] 1846 	pop	ar4
      000856 D0 05            [24] 1847 	pop	ar5
      000858 D0 06            [24] 1848 	pop	ar6
      00085A D0 07            [24] 1849 	pop	ar7
      00085C E5 82            [12] 1850 	mov	a, dpl
      00085E 24 FF            [12] 1851 	add	a,#0xff
      000860 92 00            [24] 1852 	mov	b0,c
      000862 40 0E            [24] 1853 	jc	00109$
      000864                       1854 00108$:
      000864 A8 1D            [24] 1855 	mov	r0,_bp
      000866 08               [12] 1856 	inc	r0
      000867 E4               [12] 1857 	clr	a
      000868 F6               [12] 1858 	mov	@r0,a
      000869 08               [12] 1859 	inc	r0
      00086A F6               [12] 1860 	mov	@r0,a
      00086B 08               [12] 1861 	inc	r0
      00086C F6               [12] 1862 	mov	@r0,a
      00086D 08               [12] 1863 	inc	r0
      00086E F6               [12] 1864 	mov	@r0,a
      00086F 02 0A 71         [24] 1865 	ljmp	00110$
      000872                       1866 00109$:
      000872 C0 07            [24] 1867 	push	ar7
      000874 C0 06            [24] 1868 	push	ar6
      000876 C0 05            [24] 1869 	push	ar5
      000878 C0 04            [24] 1870 	push	ar4
      00087A E5 1D            [12] 1871 	mov	a,_bp
      00087C 24 FA            [12] 1872 	add	a,#0xfa
      00087E F8               [12] 1873 	mov	r0,a
      00087F E6               [12] 1874 	mov	a,@r0
      000880 C0 E0            [24] 1875 	push	acc
      000882 08               [12] 1876 	inc	r0
      000883 E6               [12] 1877 	mov	a,@r0
      000884 C0 E0            [24] 1878 	push	acc
      000886 08               [12] 1879 	inc	r0
      000887 E6               [12] 1880 	mov	a,@r0
      000888 C0 E0            [24] 1881 	push	acc
      00088A 08               [12] 1882 	inc	r0
      00088B E6               [12] 1883 	mov	a,@r0
      00088C C0 E0            [24] 1884 	push	acc
      00088E E5 1D            [12] 1885 	mov	a,_bp
      000890 24 EE            [12] 1886 	add	a,#0xee
      000892 F8               [12] 1887 	mov	r0,a
      000893 86 82            [24] 1888 	mov	dpl, @r0
      000895 08               [12] 1889 	inc	r0
      000896 86 83            [24] 1890 	mov	dph, @r0
      000898 08               [12] 1891 	inc	r0
      000899 86 F0            [24] 1892 	mov	b, @r0
      00089B 08               [12] 1893 	inc	r0
      00089C E6               [12] 1894 	mov	a, @r0
      00089D 12 1A 32         [24] 1895 	lcall	___fslt
      0008A0 E5 81            [12] 1896 	mov	a,sp
      0008A2 24 FC            [12] 1897 	add	a,#0xfc
      0008A4 F5 81            [12] 1898 	mov	sp,a
      0008A6 D0 04            [24] 1899 	pop	ar4
      0008A8 D0 05            [24] 1900 	pop	ar5
      0008AA D0 06            [24] 1901 	pop	ar6
      0008AC D0 07            [24] 1902 	pop	ar7
      0008AE E5 82            [12] 1903 	mov	a, dpl
      0008B0 24 FF            [12] 1904 	add	a,#0xff
      0008B2 92 00            [24] 1905 	mov	b0,c
      0008B4 40 54            [24] 1906 	jc	00105$
      0008B6 C0 07            [24] 1907 	push	ar7
      0008B8 C0 06            [24] 1908 	push	ar6
      0008BA C0 05            [24] 1909 	push	ar5
      0008BC C0 04            [24] 1910 	push	ar4
      0008BE E5 1D            [12] 1911 	mov	a,_bp
      0008C0 24 EE            [12] 1912 	add	a,#0xee
      0008C2 F8               [12] 1913 	mov	r0,a
      0008C3 E6               [12] 1914 	mov	a,@r0
      0008C4 C0 E0            [24] 1915 	push	acc
      0008C6 08               [12] 1916 	inc	r0
      0008C7 E6               [12] 1917 	mov	a,@r0
      0008C8 C0 E0            [24] 1918 	push	acc
      0008CA 08               [12] 1919 	inc	r0
      0008CB E6               [12] 1920 	mov	a,@r0
      0008CC C0 E0            [24] 1921 	push	acc
      0008CE 08               [12] 1922 	inc	r0
      0008CF E6               [12] 1923 	mov	a,@r0
      0008D0 C0 E0            [24] 1924 	push	acc
      0008D2 E5 1D            [12] 1925 	mov	a,_bp
      0008D4 24 F6            [12] 1926 	add	a,#0xf6
      0008D6 F8               [12] 1927 	mov	r0,a
      0008D7 86 82            [24] 1928 	mov	dpl, @r0
      0008D9 08               [12] 1929 	inc	r0
      0008DA 86 83            [24] 1930 	mov	dph, @r0
      0008DC 08               [12] 1931 	inc	r0
      0008DD 86 F0            [24] 1932 	mov	b, @r0
      0008DF 08               [12] 1933 	inc	r0
      0008E0 E6               [12] 1934 	mov	a, @r0
      0008E1 12 1A 32         [24] 1935 	lcall	___fslt
      0008E4 E5 81            [12] 1936 	mov	a,sp
      0008E6 24 FC            [12] 1937 	add	a,#0xfc
      0008E8 F5 81            [12] 1938 	mov	sp,a
      0008EA D0 04            [24] 1939 	pop	ar4
      0008EC D0 05            [24] 1940 	pop	ar5
      0008EE D0 06            [24] 1941 	pop	ar6
      0008F0 D0 07            [24] 1942 	pop	ar7
      0008F2 E5 82            [12] 1943 	mov	a, dpl
      0008F4 24 FF            [12] 1944 	add	a,#0xff
      0008F6 92 00            [24] 1945 	mov	b0,c
      0008F8 40 10            [24] 1946 	jc	00105$
      0008FA A8 1D            [24] 1947 	mov	r0,_bp
      0008FC 08               [12] 1948 	inc	r0
      0008FD E4               [12] 1949 	clr	a
      0008FE F6               [12] 1950 	mov	@r0,a
      0008FF 08               [12] 1951 	inc	r0
      000900 F6               [12] 1952 	mov	@r0,a
      000901 08               [12] 1953 	inc	r0
      000902 76 80            [12] 1954 	mov	@r0,#0x80
      000904 08               [12] 1955 	inc	r0
      000905 76 3F            [12] 1956 	mov	@r0,#0x3f
      000907 02 0A 71         [24] 1957 	ljmp	00110$
      00090A                       1958 00105$:
      00090A C0 07            [24] 1959 	push	ar7
      00090C C0 06            [24] 1960 	push	ar6
      00090E C0 05            [24] 1961 	push	ar5
      000910 C0 04            [24] 1962 	push	ar4
      000912 E5 1D            [12] 1963 	mov	a,_bp
      000914 24 FA            [12] 1964 	add	a,#0xfa
      000916 F8               [12] 1965 	mov	r0,a
      000917 E6               [12] 1966 	mov	a,@r0
      000918 C0 E0            [24] 1967 	push	acc
      00091A 08               [12] 1968 	inc	r0
      00091B E6               [12] 1969 	mov	a,@r0
      00091C C0 E0            [24] 1970 	push	acc
      00091E 08               [12] 1971 	inc	r0
      00091F E6               [12] 1972 	mov	a,@r0
      000920 C0 E0            [24] 1973 	push	acc
      000922 08               [12] 1974 	inc	r0
      000923 E6               [12] 1975 	mov	a,@r0
      000924 C0 E0            [24] 1976 	push	acc
      000926 E5 1D            [12] 1977 	mov	a,_bp
      000928 24 EE            [12] 1978 	add	a,#0xee
      00092A F8               [12] 1979 	mov	r0,a
      00092B 86 82            [24] 1980 	mov	dpl, @r0
      00092D 08               [12] 1981 	inc	r0
      00092E 86 83            [24] 1982 	mov	dph, @r0
      000930 08               [12] 1983 	inc	r0
      000931 86 F0            [24] 1984 	mov	b, @r0
      000933 08               [12] 1985 	inc	r0
      000934 E6               [12] 1986 	mov	a, @r0
      000935 12 1A 32         [24] 1987 	lcall	___fslt
      000938 AB 82            [24] 1988 	mov	r3, dpl
      00093A E5 81            [12] 1989 	mov	a,sp
      00093C 24 FC            [12] 1990 	add	a,#0xfc
      00093E F5 81            [12] 1991 	mov	sp,a
      000940 D0 04            [24] 1992 	pop	ar4
      000942 D0 05            [24] 1993 	pop	ar5
      000944 D0 06            [24] 1994 	pop	ar6
      000946 D0 07            [24] 1995 	pop	ar7
      000948 EB               [12] 1996 	mov	a,r3
      000949 70 03            [24] 1997 	jnz	00166$
      00094B 02 09 D5         [24] 1998 	ljmp	00102$
      00094E                       1999 00166$:
      00094E C0 07            [24] 2000 	push	ar7
      000950 C0 06            [24] 2001 	push	ar6
      000952 C0 05            [24] 2002 	push	ar5
      000954 C0 04            [24] 2003 	push	ar4
      000956 C0 07            [24] 2004 	push	ar7
      000958 C0 06            [24] 2005 	push	ar6
      00095A C0 05            [24] 2006 	push	ar5
      00095C C0 04            [24] 2007 	push	ar4
      00095E E5 1D            [12] 2008 	mov	a,_bp
      000960 24 EE            [12] 2009 	add	a,#0xee
      000962 F8               [12] 2010 	mov	r0,a
      000963 86 82            [24] 2011 	mov	dpl, @r0
      000965 08               [12] 2012 	inc	r0
      000966 86 83            [24] 2013 	mov	dph, @r0
      000968 08               [12] 2014 	inc	r0
      000969 86 F0            [24] 2015 	mov	b, @r0
      00096B 08               [12] 2016 	inc	r0
      00096C E6               [12] 2017 	mov	a, @r0
      00096D 12 18 F7         [24] 2018 	lcall	___fssub
      000970 C8               [12] 2019 	xch	a,r0
      000971 E5 1D            [12] 2020 	mov	a,_bp
      000973 24 05            [12] 2021 	add	a,#0x05
      000975 C8               [12] 2022 	xch	a,r0
      000976 A6 82            [24] 2023 	mov	@r0, dpl
      000978 08               [12] 2024 	inc	r0
      000979 A6 83            [24] 2025 	mov	@r0, dph
      00097B 08               [12] 2026 	inc	r0
      00097C A6 F0            [24] 2027 	mov	@r0, b
      00097E 08               [12] 2028 	inc	r0
      00097F F6               [12] 2029 	mov	@r0,a
      000980 E5 81            [12] 2030 	mov	a,sp
      000982 24 FC            [12] 2031 	add	a,#0xfc
      000984 F5 81            [12] 2032 	mov	sp,a
      000986 E5 1D            [12] 2033 	mov	a,_bp
      000988 24 FA            [12] 2034 	add	a,#0xfa
      00098A F8               [12] 2035 	mov	r0,a
      00098B 86 82            [24] 2036 	mov	dpl, @r0
      00098D 08               [12] 2037 	inc	r0
      00098E 86 83            [24] 2038 	mov	dph, @r0
      000990 08               [12] 2039 	inc	r0
      000991 86 F0            [24] 2040 	mov	b, @r0
      000993 08               [12] 2041 	inc	r0
      000994 E6               [12] 2042 	mov	a, @r0
      000995 12 18 F7         [24] 2043 	lcall	___fssub
      000998 AC 82            [24] 2044 	mov	r4, dpl
      00099A AD 83            [24] 2045 	mov	r5, dph
      00099C AE F0            [24] 2046 	mov	r6, b
      00099E FF               [12] 2047 	mov	r7, a
      00099F E5 81            [12] 2048 	mov	a,sp
      0009A1 24 FC            [12] 2049 	add	a,#0xfc
      0009A3 F5 81            [12] 2050 	mov	sp,a
      0009A5 C0 04            [24] 2051 	push	ar4
      0009A7 C0 05            [24] 2052 	push	ar5
      0009A9 C0 06            [24] 2053 	push	ar6
      0009AB C0 07            [24] 2054 	push	ar7
      0009AD E5 1D            [12] 2055 	mov	a,_bp
      0009AF 24 05            [12] 2056 	add	a,#0x05
      0009B1 F8               [12] 2057 	mov	r0,a
      0009B2 86 82            [24] 2058 	mov	dpl, @r0
      0009B4 08               [12] 2059 	inc	r0
      0009B5 86 83            [24] 2060 	mov	dph, @r0
      0009B7 08               [12] 2061 	inc	r0
      0009B8 86 F0            [24] 2062 	mov	b, @r0
      0009BA 08               [12] 2063 	inc	r0
      0009BB E6               [12] 2064 	mov	a, @r0
      0009BC 12 1B 79         [24] 2065 	lcall	___fsdiv
      0009BF A8 1D            [24] 2066 	mov	r0,_bp
      0009C1 08               [12] 2067 	inc	r0
      0009C2 A6 82            [24] 2068 	mov	@r0, dpl
      0009C4 08               [12] 2069 	inc	r0
      0009C5 A6 83            [24] 2070 	mov	@r0, dph
      0009C7 08               [12] 2071 	inc	r0
      0009C8 A6 F0            [24] 2072 	mov	@r0, b
      0009CA 08               [12] 2073 	inc	r0
      0009CB F6               [12] 2074 	mov	@r0,a
      0009CC E5 81            [12] 2075 	mov	a,sp
      0009CE 24 FC            [12] 2076 	add	a,#0xfc
      0009D0 F5 81            [12] 2077 	mov	sp,a
      0009D2 02 0A 71         [24] 2078 	ljmp	00110$
      0009D5                       2079 00102$:
      0009D5 E5 1D            [12] 2080 	mov	a,_bp
      0009D7 24 EE            [12] 2081 	add	a,#0xee
      0009D9 F8               [12] 2082 	mov	r0,a
      0009DA E6               [12] 2083 	mov	a,@r0
      0009DB C0 E0            [24] 2084 	push	acc
      0009DD 08               [12] 2085 	inc	r0
      0009DE E6               [12] 2086 	mov	a,@r0
      0009DF C0 E0            [24] 2087 	push	acc
      0009E1 08               [12] 2088 	inc	r0
      0009E2 E6               [12] 2089 	mov	a,@r0
      0009E3 C0 E0            [24] 2090 	push	acc
      0009E5 08               [12] 2091 	inc	r0
      0009E6 E6               [12] 2092 	mov	a,@r0
      0009E7 C0 E0            [24] 2093 	push	acc
      0009E9 E5 1D            [12] 2094 	mov	a,_bp
      0009EB 24 F2            [12] 2095 	add	a,#0xf2
      0009ED F8               [12] 2096 	mov	r0,a
      0009EE 86 82            [24] 2097 	mov	dpl, @r0
      0009F0 08               [12] 2098 	inc	r0
      0009F1 86 83            [24] 2099 	mov	dph, @r0
      0009F3 08               [12] 2100 	inc	r0
      0009F4 86 F0            [24] 2101 	mov	b, @r0
      0009F6 08               [12] 2102 	inc	r0
      0009F7 E6               [12] 2103 	mov	a, @r0
      0009F8 12 18 F7         [24] 2104 	lcall	___fssub
      0009FB C8               [12] 2105 	xch	a,r0
      0009FC E5 1D            [12] 2106 	mov	a,_bp
      0009FE 24 05            [12] 2107 	add	a,#0x05
      000A00 C8               [12] 2108 	xch	a,r0
      000A01 A6 82            [24] 2109 	mov	@r0, dpl
      000A03 08               [12] 2110 	inc	r0
      000A04 A6 83            [24] 2111 	mov	@r0, dph
      000A06 08               [12] 2112 	inc	r0
      000A07 A6 F0            [24] 2113 	mov	@r0, b
      000A09 08               [12] 2114 	inc	r0
      000A0A F6               [12] 2115 	mov	@r0,a
      000A0B E5 81            [12] 2116 	mov	a,sp
      000A0D 24 FC            [12] 2117 	add	a,#0xfc
      000A0F F5 81            [12] 2118 	mov	sp,a
      000A11 E5 1D            [12] 2119 	mov	a,_bp
      000A13 24 F6            [12] 2120 	add	a,#0xf6
      000A15 F8               [12] 2121 	mov	r0,a
      000A16 E6               [12] 2122 	mov	a,@r0
      000A17 C0 E0            [24] 2123 	push	acc
      000A19 08               [12] 2124 	inc	r0
      000A1A E6               [12] 2125 	mov	a,@r0
      000A1B C0 E0            [24] 2126 	push	acc
      000A1D 08               [12] 2127 	inc	r0
      000A1E E6               [12] 2128 	mov	a,@r0
      000A1F C0 E0            [24] 2129 	push	acc
      000A21 08               [12] 2130 	inc	r0
      000A22 E6               [12] 2131 	mov	a,@r0
      000A23 C0 E0            [24] 2132 	push	acc
      000A25 E5 1D            [12] 2133 	mov	a,_bp
      000A27 24 F2            [12] 2134 	add	a,#0xf2
      000A29 F8               [12] 2135 	mov	r0,a
      000A2A 86 82            [24] 2136 	mov	dpl, @r0
      000A2C 08               [12] 2137 	inc	r0
      000A2D 86 83            [24] 2138 	mov	dph, @r0
      000A2F 08               [12] 2139 	inc	r0
      000A30 86 F0            [24] 2140 	mov	b, @r0
      000A32 08               [12] 2141 	inc	r0
      000A33 E6               [12] 2142 	mov	a, @r0
      000A34 12 18 F7         [24] 2143 	lcall	___fssub
      000A37 AA 82            [24] 2144 	mov	r2, dpl
      000A39 AB 83            [24] 2145 	mov	r3, dph
      000A3B AE F0            [24] 2146 	mov	r6, b
      000A3D FF               [12] 2147 	mov	r7, a
      000A3E E5 81            [12] 2148 	mov	a,sp
      000A40 24 FC            [12] 2149 	add	a,#0xfc
      000A42 F5 81            [12] 2150 	mov	sp,a
      000A44 C0 02            [24] 2151 	push	ar2
      000A46 C0 03            [24] 2152 	push	ar3
      000A48 C0 06            [24] 2153 	push	ar6
      000A4A C0 07            [24] 2154 	push	ar7
      000A4C E5 1D            [12] 2155 	mov	a,_bp
      000A4E 24 05            [12] 2156 	add	a,#0x05
      000A50 F8               [12] 2157 	mov	r0,a
      000A51 86 82            [24] 2158 	mov	dpl, @r0
      000A53 08               [12] 2159 	inc	r0
      000A54 86 83            [24] 2160 	mov	dph, @r0
      000A56 08               [12] 2161 	inc	r0
      000A57 86 F0            [24] 2162 	mov	b, @r0
      000A59 08               [12] 2163 	inc	r0
      000A5A E6               [12] 2164 	mov	a, @r0
      000A5B 12 1B 79         [24] 2165 	lcall	___fsdiv
      000A5E A8 1D            [24] 2166 	mov	r0,_bp
      000A60 08               [12] 2167 	inc	r0
      000A61 A6 82            [24] 2168 	mov	@r0, dpl
      000A63 08               [12] 2169 	inc	r0
      000A64 A6 83            [24] 2170 	mov	@r0, dph
      000A66 08               [12] 2171 	inc	r0
      000A67 A6 F0            [24] 2172 	mov	@r0, b
      000A69 08               [12] 2173 	inc	r0
      000A6A F6               [12] 2174 	mov	@r0,a
      000A6B E5 81            [12] 2175 	mov	a,sp
      000A6D 24 FC            [12] 2176 	add	a,#0xfc
      000A6F F5 81            [12] 2177 	mov	sp,a
      000A71                       2178 00110$:
      000A71 E5 1D            [12] 2179 	mov	a,_bp
      000A73 24 ED            [12] 2180 	add	a,#0xed
      000A75 F8               [12] 2181 	mov	r0,a
      000A76 E6               [12] 2182 	mov	a,@r0
      000A77 C0 E0            [24] 2183 	push	acc
      000A79 A8 1D            [24] 2184 	mov	r0,_bp
      000A7B 08               [12] 2185 	inc	r0
      000A7C 86 82            [24] 2186 	mov	dpl, @r0
      000A7E 08               [12] 2187 	inc	r0
      000A7F 86 83            [24] 2188 	mov	dph, @r0
      000A81 08               [12] 2189 	inc	r0
      000A82 86 F0            [24] 2190 	mov	b, @r0
      000A84 08               [12] 2191 	inc	r0
      000A85 E6               [12] 2192 	mov	a, @r0
      000A86 12 01 34         [24] 2193 	lcall	_fuzzy_8051_hedge
      000A89 AC 82            [24] 2194 	mov	r4, dpl
      000A8B AD 83            [24] 2195 	mov	r5, dph
      000A8D AE F0            [24] 2196 	mov	r6, b
      000A8F FF               [12] 2197 	mov	r7, a
      000A90 15 81            [12] 2198 	dec	sp
      000A92 8C 82            [24] 2199 	mov	dpl, r4
      000A94 8D 83            [24] 2200 	mov	dph, r5
      000A96 8E F0            [24] 2201 	mov	b, r6
      000A98 EF               [12] 2202 	mov	a, r7
      000A99 85 1D 81         [24] 2203 	mov	sp,_bp
      000A9C D0 1D            [24] 2204 	pop	_bp
                           0009E7  2205 	C$fuzzy.h$59$1_0$23 ==.
                           0009E7  2206 	XG$fuzzy_trapezoid$0$0 ==.
      000A9E 22               [24] 2207 	ret
                                   2208 ;------------------------------------------------------------
                                   2209 ;Allocation info for local variables in function 'fuzzy_8051_eval'
                                   2210 ;------------------------------------------------------------
                                   2211 ;x             Allocated to stack - _bp -6 +4 
                                   2212 ;v             Allocated to stack - _bp +1 +3 
                                   2213 ;sloc0         Allocated to stack - _bp +4 +1 
                                   2214 ;sloc1         Allocated to stack - _bp +5 +1 
                                   2215 ;sloc2         Allocated to stack - _bp +5 +4 
                                   2216 ;sloc3         Allocated to stack - _bp +9 +4 
                                   2217 ;sloc4         Allocated to stack - _bp +13 +4 
                                   2218 ;sloc5         Allocated to stack - _bp +17 +4 
                                   2219 ;------------------------------------------------------------
                           0009E8  2220 	Fcontroller_8051$fuzzy_8051_eval$0$0 ==.
                           0009E8  2221 	C$fuzzy.h$60$1_0$25 ==.
                                   2222 ;	../../fuzzy.h:60: static float fuzzy_8051_eval(const fuzzy_variable_8051_t *v, float x) { if (v->shape == FUZZY_SHAPE_RAMP) return fuzzy_ramp(v->parameters[0], v->parameters[1], x, v->parameters[2] != 0.0f, v->hedge); if (v->shape == FUZZY_SHAPE_TRIANGLE) return fuzzy_triangle(v->parameters[0], v->parameters[1], v->parameters[2], x, v->hedge); if (v->shape == FUZZY_SHAPE_TRAPEZOID) return fuzzy_trapezoid(v->parameters[0], v->parameters[1], v->parameters[2], v->parameters[3], x, v->hedge); return 0.0f; }
                                   2223 ;	-----------------------------------------
                                   2224 ;	 function fuzzy_8051_eval
                                   2225 ;	-----------------------------------------
      000A9F                       2226 _fuzzy_8051_eval:
      000A9F C0 1D            [24] 2227 	push	_bp
      000AA1 85 81 1D         [24] 2228 	mov	_bp,sp
      000AA4 C0 82            [24] 2229 	push	dpl
      000AA6 C0 83            [24] 2230 	push	dph
      000AA8 C0 F0            [24] 2231 	push	b
      000AAA E5 81            [12] 2232 	mov	a,sp
      000AAC 24 11            [12] 2233 	add	a,#0x11
      000AAE F5 81            [12] 2234 	mov	sp,a
      000AB0 A8 1D            [24] 2235 	mov	r0,_bp
      000AB2 08               [12] 2236 	inc	r0
      000AB3 86 02            [24] 2237 	mov	ar2,@r0
      000AB5 08               [12] 2238 	inc	r0
      000AB6 86 03            [24] 2239 	mov	ar3,@r0
      000AB8 08               [12] 2240 	inc	r0
      000AB9 86 04            [24] 2241 	mov	ar4,@r0
      000ABB 8A 82            [24] 2242 	mov	dpl,r2
      000ABD 8B 83            [24] 2243 	mov	dph,r3
      000ABF 8C F0            [24] 2244 	mov	b,r4
      000AC1 12 1C 3C         [24] 2245 	lcall	__gptrget
      000AC4 FC               [12] 2246 	mov	r4,a
      000AC5 60 03            [24] 2247 	jz	00127$
      000AC7 02 0B CF         [24] 2248 	ljmp	00102$
      000ACA                       2249 00127$:
      000ACA A8 1D            [24] 2250 	mov	r0,_bp
      000ACC 08               [12] 2251 	inc	r0
      000ACD 74 01            [12] 2252 	mov	a,#0x01
      000ACF 26               [12] 2253 	add	a, @r0
      000AD0 FA               [12] 2254 	mov	r2,a
      000AD1 E4               [12] 2255 	clr	a
      000AD2 08               [12] 2256 	inc	r0
      000AD3 36               [12] 2257 	addc	a, @r0
      000AD4 FB               [12] 2258 	mov	r3,a
      000AD5 08               [12] 2259 	inc	r0
      000AD6 86 07            [24] 2260 	mov	ar7,@r0
      000AD8 8A 82            [24] 2261 	mov	dpl,r2
      000ADA 8B 83            [24] 2262 	mov	dph,r3
      000ADC 8F F0            [24] 2263 	mov	b,r7
      000ADE 12 1C 3C         [24] 2264 	lcall	__gptrget
      000AE1 FC               [12] 2265 	mov	r4,a
      000AE2 A8 1D            [24] 2266 	mov	r0,_bp
      000AE4 08               [12] 2267 	inc	r0
      000AE5 74 0A            [12] 2268 	mov	a,#0x0a
      000AE7 26               [12] 2269 	add	a, @r0
      000AE8 FD               [12] 2270 	mov	r5,a
      000AE9 E4               [12] 2271 	clr	a
      000AEA 08               [12] 2272 	inc	r0
      000AEB 36               [12] 2273 	addc	a, @r0
      000AEC FE               [12] 2274 	mov	r6,a
      000AED 08               [12] 2275 	inc	r0
      000AEE 86 07            [24] 2276 	mov	ar7,@r0
      000AF0 8D 82            [24] 2277 	mov	dpl,r5
      000AF2 8E 83            [24] 2278 	mov	dph,r6
      000AF4 8F F0            [24] 2279 	mov	b,r7
      000AF6 12 1C 3C         [24] 2280 	lcall	__gptrget
      000AF9 FD               [12] 2281 	mov	r5,a
      000AFA A3               [24] 2282 	inc	dptr
      000AFB 12 1C 3C         [24] 2283 	lcall	__gptrget
      000AFE FE               [12] 2284 	mov	r6,a
      000AFF A3               [24] 2285 	inc	dptr
      000B00 12 1C 3C         [24] 2286 	lcall	__gptrget
      000B03 FF               [12] 2287 	mov	r7,a
      000B04 A3               [24] 2288 	inc	dptr
      000B05 12 1C 3C         [24] 2289 	lcall	__gptrget
      000B08 FB               [12] 2290 	mov	r3,a
      000B09 8D F0            [24] 2291 	mov	b,r5
      000B0B EE               [12] 2292 	mov	a,r6
      000B0C 42 F0            [12] 2293 	orl	b,a
      000B0E EF               [12] 2294 	mov	a,r7
      000B0F 42 F0            [12] 2295 	orl	b,a
      000B11 EB               [12] 2296 	mov	a,r3
      000B12 54 7F            [12] 2297 	anl	a,#0x7F
      000B14 45 F0            [12] 2298 	orl	a,b
      000B16 B4 01 00         [24] 2299 	cjne	a,#0x01,00128$
      000B19                       2300 00128$:
      000B19 B3               [12] 2301 	cpl	c
      000B1A 92 00            [24] 2302 	mov	b0,c
      000B1C E5 1D            [12] 2303 	mov	a,_bp
      000B1E 24 04            [12] 2304 	add	a,#0x04
      000B20 F8               [12] 2305 	mov	r0,a
      000B21 A2 00            [12] 2306 	mov	c,b0
      000B23 E4               [12] 2307 	clr	a
      000B24 33               [12] 2308 	rlc	a
      000B25 F6               [12] 2309 	mov	@r0,a
      000B26 A8 1D            [24] 2310 	mov	r0,_bp
      000B28 08               [12] 2311 	inc	r0
      000B29 74 06            [12] 2312 	mov	a,#0x06
      000B2B 26               [12] 2313 	add	a, @r0
      000B2C FB               [12] 2314 	mov	r3,a
      000B2D E4               [12] 2315 	clr	a
      000B2E 08               [12] 2316 	inc	r0
      000B2F 36               [12] 2317 	addc	a, @r0
      000B30 FD               [12] 2318 	mov	r5,a
      000B31 08               [12] 2319 	inc	r0
      000B32 86 06            [24] 2320 	mov	ar6,@r0
      000B34 8B 82            [24] 2321 	mov	dpl,r3
      000B36 8D 83            [24] 2322 	mov	dph,r5
      000B38 8E F0            [24] 2323 	mov	b,r6
      000B3A E5 1D            [12] 2324 	mov	a,_bp
      000B3C 24 05            [12] 2325 	add	a,#0x05
      000B3E F8               [12] 2326 	mov	r0,a
      000B3F 12 1C 3C         [24] 2327 	lcall	__gptrget
      000B42 F6               [12] 2328 	mov	@r0,a
      000B43 A3               [24] 2329 	inc	dptr
      000B44 12 1C 3C         [24] 2330 	lcall	__gptrget
      000B47 08               [12] 2331 	inc	r0
      000B48 F6               [12] 2332 	mov	@r0,a
      000B49 A3               [24] 2333 	inc	dptr
      000B4A 12 1C 3C         [24] 2334 	lcall	__gptrget
      000B4D 08               [12] 2335 	inc	r0
      000B4E F6               [12] 2336 	mov	@r0,a
      000B4F A3               [24] 2337 	inc	dptr
      000B50 12 1C 3C         [24] 2338 	lcall	__gptrget
      000B53 08               [12] 2339 	inc	r0
      000B54 F6               [12] 2340 	mov	@r0,a
      000B55 A8 1D            [24] 2341 	mov	r0,_bp
      000B57 08               [12] 2342 	inc	r0
      000B58 74 02            [12] 2343 	mov	a,#0x02
      000B5A 26               [12] 2344 	add	a, @r0
      000B5B FA               [12] 2345 	mov	r2,a
      000B5C E4               [12] 2346 	clr	a
      000B5D 08               [12] 2347 	inc	r0
      000B5E 36               [12] 2348 	addc	a, @r0
      000B5F FE               [12] 2349 	mov	r6,a
      000B60 08               [12] 2350 	inc	r0
      000B61 86 07            [24] 2351 	mov	ar7,@r0
      000B63 8A 82            [24] 2352 	mov	dpl,r2
      000B65 8E 83            [24] 2353 	mov	dph,r6
      000B67 8F F0            [24] 2354 	mov	b,r7
      000B69 12 1C 3C         [24] 2355 	lcall	__gptrget
      000B6C FA               [12] 2356 	mov	r2,a
      000B6D A3               [24] 2357 	inc	dptr
      000B6E 12 1C 3C         [24] 2358 	lcall	__gptrget
      000B71 FE               [12] 2359 	mov	r6,a
      000B72 A3               [24] 2360 	inc	dptr
      000B73 12 1C 3C         [24] 2361 	lcall	__gptrget
      000B76 FF               [12] 2362 	mov	r7,a
      000B77 A3               [24] 2363 	inc	dptr
      000B78 12 1C 3C         [24] 2364 	lcall	__gptrget
      000B7B FD               [12] 2365 	mov	r5,a
      000B7C C0 04            [24] 2366 	push	ar4
      000B7E E5 1D            [12] 2367 	mov	a,_bp
      000B80 24 04            [12] 2368 	add	a,#0x04
      000B82 F8               [12] 2369 	mov	r0,a
      000B83 E6               [12] 2370 	mov	a,@r0
      000B84 C0 E0            [24] 2371 	push	acc
      000B86 E5 1D            [12] 2372 	mov	a,_bp
      000B88 24 FA            [12] 2373 	add	a,#0xfa
      000B8A F8               [12] 2374 	mov	r0,a
      000B8B E6               [12] 2375 	mov	a,@r0
      000B8C C0 E0            [24] 2376 	push	acc
      000B8E 08               [12] 2377 	inc	r0
      000B8F E6               [12] 2378 	mov	a,@r0
      000B90 C0 E0            [24] 2379 	push	acc
      000B92 08               [12] 2380 	inc	r0
      000B93 E6               [12] 2381 	mov	a,@r0
      000B94 C0 E0            [24] 2382 	push	acc
      000B96 08               [12] 2383 	inc	r0
      000B97 E6               [12] 2384 	mov	a,@r0
      000B98 C0 E0            [24] 2385 	push	acc
      000B9A E5 1D            [12] 2386 	mov	a,_bp
      000B9C 24 05            [12] 2387 	add	a,#0x05
      000B9E F8               [12] 2388 	mov	r0,a
      000B9F E6               [12] 2389 	mov	a,@r0
      000BA0 C0 E0            [24] 2390 	push	acc
      000BA2 08               [12] 2391 	inc	r0
      000BA3 E6               [12] 2392 	mov	a,@r0
      000BA4 C0 E0            [24] 2393 	push	acc
      000BA6 08               [12] 2394 	inc	r0
      000BA7 E6               [12] 2395 	mov	a,@r0
      000BA8 C0 E0            [24] 2396 	push	acc
      000BAA 08               [12] 2397 	inc	r0
      000BAB E6               [12] 2398 	mov	a,@r0
      000BAC C0 E0            [24] 2399 	push	acc
      000BAE 8A 82            [24] 2400 	mov	dpl, r2
      000BB0 8E 83            [24] 2401 	mov	dph, r6
      000BB2 8F F0            [24] 2402 	mov	b, r7
      000BB4 ED               [12] 2403 	mov	a, r5
      000BB5 12 01 F0         [24] 2404 	lcall	_fuzzy_ramp
      000BB8 AB 82            [24] 2405 	mov	r3, dpl
      000BBA AD 83            [24] 2406 	mov	r5, dph
      000BBC AE F0            [24] 2407 	mov	r6, b
      000BBE FF               [12] 2408 	mov	r7, a
      000BBF E5 81            [12] 2409 	mov	a,sp
      000BC1 24 F6            [12] 2410 	add	a,#0xf6
      000BC3 F5 81            [12] 2411 	mov	sp,a
      000BC5 8B 82            [24] 2412 	mov	dpl, r3
      000BC7 8D 83            [24] 2413 	mov	dph, r5
      000BC9 8E F0            [24] 2414 	mov	b, r6
      000BCB EF               [12] 2415 	mov	a, r7
      000BCC 02 0E 2A         [24] 2416 	ljmp	00107$
      000BCF                       2417 00102$:
      000BCF BC 01 02         [24] 2418 	cjne	r4,#0x01,00129$
      000BD2 80 03            [24] 2419 	sjmp	00130$
      000BD4                       2420 00129$:
      000BD4 02 0C D3         [24] 2421 	ljmp	00104$
      000BD7                       2422 00130$:
      000BD7 A8 1D            [24] 2423 	mov	r0,_bp
      000BD9 08               [12] 2424 	inc	r0
      000BDA 74 01            [12] 2425 	mov	a,#0x01
      000BDC 26               [12] 2426 	add	a, @r0
      000BDD FD               [12] 2427 	mov	r5,a
      000BDE E4               [12] 2428 	clr	a
      000BDF 08               [12] 2429 	inc	r0
      000BE0 36               [12] 2430 	addc	a, @r0
      000BE1 FE               [12] 2431 	mov	r6,a
      000BE2 08               [12] 2432 	inc	r0
      000BE3 86 07            [24] 2433 	mov	ar7,@r0
      000BE5 8D 82            [24] 2434 	mov	dpl,r5
      000BE7 8E 83            [24] 2435 	mov	dph,r6
      000BE9 8F F0            [24] 2436 	mov	b,r7
      000BEB 12 1C 3C         [24] 2437 	lcall	__gptrget
      000BEE FC               [12] 2438 	mov	r4,a
      000BEF A8 1D            [24] 2439 	mov	r0,_bp
      000BF1 08               [12] 2440 	inc	r0
      000BF2 74 0A            [12] 2441 	mov	a,#0x0a
      000BF4 26               [12] 2442 	add	a, @r0
      000BF5 FB               [12] 2443 	mov	r3,a
      000BF6 E4               [12] 2444 	clr	a
      000BF7 08               [12] 2445 	inc	r0
      000BF8 36               [12] 2446 	addc	a, @r0
      000BF9 FE               [12] 2447 	mov	r6,a
      000BFA 08               [12] 2448 	inc	r0
      000BFB 86 07            [24] 2449 	mov	ar7,@r0
      000BFD 8B 82            [24] 2450 	mov	dpl,r3
      000BFF 8E 83            [24] 2451 	mov	dph,r6
      000C01 8F F0            [24] 2452 	mov	b,r7
      000C03 E5 1D            [12] 2453 	mov	a,_bp
      000C05 24 09            [12] 2454 	add	a,#0x09
      000C07 F8               [12] 2455 	mov	r0,a
      000C08 12 1C 3C         [24] 2456 	lcall	__gptrget
      000C0B F6               [12] 2457 	mov	@r0,a
      000C0C A3               [24] 2458 	inc	dptr
      000C0D 12 1C 3C         [24] 2459 	lcall	__gptrget
      000C10 08               [12] 2460 	inc	r0
      000C11 F6               [12] 2461 	mov	@r0,a
      000C12 A3               [24] 2462 	inc	dptr
      000C13 12 1C 3C         [24] 2463 	lcall	__gptrget
      000C16 08               [12] 2464 	inc	r0
      000C17 F6               [12] 2465 	mov	@r0,a
      000C18 A3               [24] 2466 	inc	dptr
      000C19 12 1C 3C         [24] 2467 	lcall	__gptrget
      000C1C 08               [12] 2468 	inc	r0
      000C1D F6               [12] 2469 	mov	@r0,a
      000C1E A8 1D            [24] 2470 	mov	r0,_bp
      000C20 08               [12] 2471 	inc	r0
      000C21 74 06            [12] 2472 	mov	a,#0x06
      000C23 26               [12] 2473 	add	a, @r0
      000C24 FD               [12] 2474 	mov	r5,a
      000C25 E4               [12] 2475 	clr	a
      000C26 08               [12] 2476 	inc	r0
      000C27 36               [12] 2477 	addc	a, @r0
      000C28 FE               [12] 2478 	mov	r6,a
      000C29 08               [12] 2479 	inc	r0
      000C2A 86 07            [24] 2480 	mov	ar7,@r0
      000C2C 8D 82            [24] 2481 	mov	dpl,r5
      000C2E 8E 83            [24] 2482 	mov	dph,r6
      000C30 8F F0            [24] 2483 	mov	b,r7
      000C32 E5 1D            [12] 2484 	mov	a,_bp
      000C34 24 0D            [12] 2485 	add	a,#0x0d
      000C36 F8               [12] 2486 	mov	r0,a
      000C37 12 1C 3C         [24] 2487 	lcall	__gptrget
      000C3A F6               [12] 2488 	mov	@r0,a
      000C3B A3               [24] 2489 	inc	dptr
      000C3C 12 1C 3C         [24] 2490 	lcall	__gptrget
      000C3F 08               [12] 2491 	inc	r0
      000C40 F6               [12] 2492 	mov	@r0,a
      000C41 A3               [24] 2493 	inc	dptr
      000C42 12 1C 3C         [24] 2494 	lcall	__gptrget
      000C45 08               [12] 2495 	inc	r0
      000C46 F6               [12] 2496 	mov	@r0,a
      000C47 A3               [24] 2497 	inc	dptr
      000C48 12 1C 3C         [24] 2498 	lcall	__gptrget
      000C4B 08               [12] 2499 	inc	r0
      000C4C F6               [12] 2500 	mov	@r0,a
      000C4D A8 1D            [24] 2501 	mov	r0,_bp
      000C4F 08               [12] 2502 	inc	r0
      000C50 74 02            [12] 2503 	mov	a,#0x02
      000C52 26               [12] 2504 	add	a, @r0
      000C53 FA               [12] 2505 	mov	r2,a
      000C54 E4               [12] 2506 	clr	a
      000C55 08               [12] 2507 	inc	r0
      000C56 36               [12] 2508 	addc	a, @r0
      000C57 FE               [12] 2509 	mov	r6,a
      000C58 08               [12] 2510 	inc	r0
      000C59 86 07            [24] 2511 	mov	ar7,@r0
      000C5B 8A 82            [24] 2512 	mov	dpl,r2
      000C5D 8E 83            [24] 2513 	mov	dph,r6
      000C5F 8F F0            [24] 2514 	mov	b,r7
      000C61 12 1C 3C         [24] 2515 	lcall	__gptrget
      000C64 FA               [12] 2516 	mov	r2,a
      000C65 A3               [24] 2517 	inc	dptr
      000C66 12 1C 3C         [24] 2518 	lcall	__gptrget
      000C69 FE               [12] 2519 	mov	r6,a
      000C6A A3               [24] 2520 	inc	dptr
      000C6B 12 1C 3C         [24] 2521 	lcall	__gptrget
      000C6E FF               [12] 2522 	mov	r7,a
      000C6F A3               [24] 2523 	inc	dptr
      000C70 12 1C 3C         [24] 2524 	lcall	__gptrget
      000C73 FD               [12] 2525 	mov	r5,a
      000C74 C0 04            [24] 2526 	push	ar4
      000C76 E5 1D            [12] 2527 	mov	a,_bp
      000C78 24 FA            [12] 2528 	add	a,#0xfa
      000C7A F8               [12] 2529 	mov	r0,a
      000C7B E6               [12] 2530 	mov	a,@r0
      000C7C C0 E0            [24] 2531 	push	acc
      000C7E 08               [12] 2532 	inc	r0
      000C7F E6               [12] 2533 	mov	a,@r0
      000C80 C0 E0            [24] 2534 	push	acc
      000C82 08               [12] 2535 	inc	r0
      000C83 E6               [12] 2536 	mov	a,@r0
      000C84 C0 E0            [24] 2537 	push	acc
      000C86 08               [12] 2538 	inc	r0
      000C87 E6               [12] 2539 	mov	a,@r0
      000C88 C0 E0            [24] 2540 	push	acc
      000C8A E5 1D            [12] 2541 	mov	a,_bp
      000C8C 24 09            [12] 2542 	add	a,#0x09
      000C8E F8               [12] 2543 	mov	r0,a
      000C8F E6               [12] 2544 	mov	a,@r0
      000C90 C0 E0            [24] 2545 	push	acc
      000C92 08               [12] 2546 	inc	r0
      000C93 E6               [12] 2547 	mov	a,@r0
      000C94 C0 E0            [24] 2548 	push	acc
      000C96 08               [12] 2549 	inc	r0
      000C97 E6               [12] 2550 	mov	a,@r0
      000C98 C0 E0            [24] 2551 	push	acc
      000C9A 08               [12] 2552 	inc	r0
      000C9B E6               [12] 2553 	mov	a,@r0
      000C9C C0 E0            [24] 2554 	push	acc
      000C9E E5 1D            [12] 2555 	mov	a,_bp
      000CA0 24 0D            [12] 2556 	add	a,#0x0d
      000CA2 F8               [12] 2557 	mov	r0,a
      000CA3 E6               [12] 2558 	mov	a,@r0
      000CA4 C0 E0            [24] 2559 	push	acc
      000CA6 08               [12] 2560 	inc	r0
      000CA7 E6               [12] 2561 	mov	a,@r0
      000CA8 C0 E0            [24] 2562 	push	acc
      000CAA 08               [12] 2563 	inc	r0
      000CAB E6               [12] 2564 	mov	a,@r0
      000CAC C0 E0            [24] 2565 	push	acc
      000CAE 08               [12] 2566 	inc	r0
      000CAF E6               [12] 2567 	mov	a,@r0
      000CB0 C0 E0            [24] 2568 	push	acc
      000CB2 8A 82            [24] 2569 	mov	dpl, r2
      000CB4 8E 83            [24] 2570 	mov	dph, r6
      000CB6 8F F0            [24] 2571 	mov	b, r7
      000CB8 ED               [12] 2572 	mov	a, r5
      000CB9 12 03 FC         [24] 2573 	lcall	_fuzzy_triangle
      000CBC AB 82            [24] 2574 	mov	r3, dpl
      000CBE AD 83            [24] 2575 	mov	r5, dph
      000CC0 AE F0            [24] 2576 	mov	r6, b
      000CC2 FF               [12] 2577 	mov	r7, a
      000CC3 E5 81            [12] 2578 	mov	a,sp
      000CC5 24 F3            [12] 2579 	add	a,#0xf3
      000CC7 F5 81            [12] 2580 	mov	sp,a
      000CC9 8B 82            [24] 2581 	mov	dpl, r3
      000CCB 8D 83            [24] 2582 	mov	dph, r5
      000CCD 8E F0            [24] 2583 	mov	b, r6
      000CCF EF               [12] 2584 	mov	a, r7
      000CD0 02 0E 2A         [24] 2585 	ljmp	00107$
      000CD3                       2586 00104$:
      000CD3 BC 02 02         [24] 2587 	cjne	r4,#0x02,00131$
      000CD6 80 03            [24] 2588 	sjmp	00132$
      000CD8                       2589 00131$:
      000CD8 02 0E 24         [24] 2590 	ljmp	00106$
      000CDB                       2591 00132$:
      000CDB A8 1D            [24] 2592 	mov	r0,_bp
      000CDD 08               [12] 2593 	inc	r0
      000CDE 74 01            [12] 2594 	mov	a,#0x01
      000CE0 26               [12] 2595 	add	a, @r0
      000CE1 FD               [12] 2596 	mov	r5,a
      000CE2 E4               [12] 2597 	clr	a
      000CE3 08               [12] 2598 	inc	r0
      000CE4 36               [12] 2599 	addc	a, @r0
      000CE5 FE               [12] 2600 	mov	r6,a
      000CE6 08               [12] 2601 	inc	r0
      000CE7 86 07            [24] 2602 	mov	ar7,@r0
      000CE9 8D 82            [24] 2603 	mov	dpl,r5
      000CEB 8E 83            [24] 2604 	mov	dph,r6
      000CED 8F F0            [24] 2605 	mov	b,r7
      000CEF E5 1D            [12] 2606 	mov	a,_bp
      000CF1 24 0D            [12] 2607 	add	a,#0x0d
      000CF3 F8               [12] 2608 	mov	r0,a
      000CF4 12 1C 3C         [24] 2609 	lcall	__gptrget
      000CF7 F6               [12] 2610 	mov	@r0,a
      000CF8 A8 1D            [24] 2611 	mov	r0,_bp
      000CFA 08               [12] 2612 	inc	r0
      000CFB 74 0E            [12] 2613 	mov	a,#0x0e
      000CFD 26               [12] 2614 	add	a, @r0
      000CFE FC               [12] 2615 	mov	r4,a
      000CFF E4               [12] 2616 	clr	a
      000D00 08               [12] 2617 	inc	r0
      000D01 36               [12] 2618 	addc	a, @r0
      000D02 FE               [12] 2619 	mov	r6,a
      000D03 08               [12] 2620 	inc	r0
      000D04 86 07            [24] 2621 	mov	ar7,@r0
      000D06 8C 82            [24] 2622 	mov	dpl,r4
      000D08 8E 83            [24] 2623 	mov	dph,r6
      000D0A 8F F0            [24] 2624 	mov	b,r7
      000D0C E5 1D            [12] 2625 	mov	a,_bp
      000D0E 24 09            [12] 2626 	add	a,#0x09
      000D10 F8               [12] 2627 	mov	r0,a
      000D11 12 1C 3C         [24] 2628 	lcall	__gptrget
      000D14 F6               [12] 2629 	mov	@r0,a
      000D15 A3               [24] 2630 	inc	dptr
      000D16 12 1C 3C         [24] 2631 	lcall	__gptrget
      000D19 08               [12] 2632 	inc	r0
      000D1A F6               [12] 2633 	mov	@r0,a
      000D1B A3               [24] 2634 	inc	dptr
      000D1C 12 1C 3C         [24] 2635 	lcall	__gptrget
      000D1F 08               [12] 2636 	inc	r0
      000D20 F6               [12] 2637 	mov	@r0,a
      000D21 A3               [24] 2638 	inc	dptr
      000D22 12 1C 3C         [24] 2639 	lcall	__gptrget
      000D25 08               [12] 2640 	inc	r0
      000D26 F6               [12] 2641 	mov	@r0,a
      000D27 A8 1D            [24] 2642 	mov	r0,_bp
      000D29 08               [12] 2643 	inc	r0
      000D2A 74 0A            [12] 2644 	mov	a,#0x0a
      000D2C 26               [12] 2645 	add	a, @r0
      000D2D FA               [12] 2646 	mov	r2,a
      000D2E E4               [12] 2647 	clr	a
      000D2F 08               [12] 2648 	inc	r0
      000D30 36               [12] 2649 	addc	a, @r0
      000D31 FD               [12] 2650 	mov	r5,a
      000D32 08               [12] 2651 	inc	r0
      000D33 86 07            [24] 2652 	mov	ar7,@r0
      000D35 8A 82            [24] 2653 	mov	dpl,r2
      000D37 8D 83            [24] 2654 	mov	dph,r5
      000D39 8F F0            [24] 2655 	mov	b,r7
      000D3B E5 1D            [12] 2656 	mov	a,_bp
      000D3D 24 05            [12] 2657 	add	a,#0x05
      000D3F F8               [12] 2658 	mov	r0,a
      000D40 12 1C 3C         [24] 2659 	lcall	__gptrget
      000D43 F6               [12] 2660 	mov	@r0,a
      000D44 A3               [24] 2661 	inc	dptr
      000D45 12 1C 3C         [24] 2662 	lcall	__gptrget
      000D48 08               [12] 2663 	inc	r0
      000D49 F6               [12] 2664 	mov	@r0,a
      000D4A A3               [24] 2665 	inc	dptr
      000D4B 12 1C 3C         [24] 2666 	lcall	__gptrget
      000D4E 08               [12] 2667 	inc	r0
      000D4F F6               [12] 2668 	mov	@r0,a
      000D50 A3               [24] 2669 	inc	dptr
      000D51 12 1C 3C         [24] 2670 	lcall	__gptrget
      000D54 08               [12] 2671 	inc	r0
      000D55 F6               [12] 2672 	mov	@r0,a
      000D56 A8 1D            [24] 2673 	mov	r0,_bp
      000D58 08               [12] 2674 	inc	r0
      000D59 74 06            [12] 2675 	mov	a,#0x06
      000D5B 26               [12] 2676 	add	a, @r0
      000D5C FB               [12] 2677 	mov	r3,a
      000D5D E4               [12] 2678 	clr	a
      000D5E 08               [12] 2679 	inc	r0
      000D5F 36               [12] 2680 	addc	a, @r0
      000D60 FC               [12] 2681 	mov	r4,a
      000D61 08               [12] 2682 	inc	r0
      000D62 86 07            [24] 2683 	mov	ar7,@r0
      000D64 8B 82            [24] 2684 	mov	dpl,r3
      000D66 8C 83            [24] 2685 	mov	dph,r4
      000D68 8F F0            [24] 2686 	mov	b,r7
      000D6A E5 1D            [12] 2687 	mov	a,_bp
      000D6C 24 11            [12] 2688 	add	a,#0x11
      000D6E F8               [12] 2689 	mov	r0,a
      000D6F 12 1C 3C         [24] 2690 	lcall	__gptrget
      000D72 F6               [12] 2691 	mov	@r0,a
      000D73 A3               [24] 2692 	inc	dptr
      000D74 12 1C 3C         [24] 2693 	lcall	__gptrget
      000D77 08               [12] 2694 	inc	r0
      000D78 F6               [12] 2695 	mov	@r0,a
      000D79 A3               [24] 2696 	inc	dptr
      000D7A 12 1C 3C         [24] 2697 	lcall	__gptrget
      000D7D 08               [12] 2698 	inc	r0
      000D7E F6               [12] 2699 	mov	@r0,a
      000D7F A3               [24] 2700 	inc	dptr
      000D80 12 1C 3C         [24] 2701 	lcall	__gptrget
      000D83 08               [12] 2702 	inc	r0
      000D84 F6               [12] 2703 	mov	@r0,a
      000D85 A8 1D            [24] 2704 	mov	r0,_bp
      000D87 08               [12] 2705 	inc	r0
      000D88 74 02            [12] 2706 	mov	a,#0x02
      000D8A 26               [12] 2707 	add	a, @r0
      000D8B FA               [12] 2708 	mov	r2,a
      000D8C E4               [12] 2709 	clr	a
      000D8D 08               [12] 2710 	inc	r0
      000D8E 36               [12] 2711 	addc	a, @r0
      000D8F FD               [12] 2712 	mov	r5,a
      000D90 08               [12] 2713 	inc	r0
      000D91 86 07            [24] 2714 	mov	ar7,@r0
      000D93 8A 82            [24] 2715 	mov	dpl,r2
      000D95 8D 83            [24] 2716 	mov	dph,r5
      000D97 8F F0            [24] 2717 	mov	b,r7
      000D99 12 1C 3C         [24] 2718 	lcall	__gptrget
      000D9C FA               [12] 2719 	mov	r2,a
      000D9D A3               [24] 2720 	inc	dptr
      000D9E 12 1C 3C         [24] 2721 	lcall	__gptrget
      000DA1 FD               [12] 2722 	mov	r5,a
      000DA2 A3               [24] 2723 	inc	dptr
      000DA3 12 1C 3C         [24] 2724 	lcall	__gptrget
      000DA6 FF               [12] 2725 	mov	r7,a
      000DA7 A3               [24] 2726 	inc	dptr
      000DA8 12 1C 3C         [24] 2727 	lcall	__gptrget
      000DAB FE               [12] 2728 	mov	r6,a
      000DAC E5 1D            [12] 2729 	mov	a,_bp
      000DAE 24 0D            [12] 2730 	add	a,#0x0d
      000DB0 F8               [12] 2731 	mov	r0,a
      000DB1 E6               [12] 2732 	mov	a,@r0
      000DB2 C0 E0            [24] 2733 	push	acc
      000DB4 E5 1D            [12] 2734 	mov	a,_bp
      000DB6 24 FA            [12] 2735 	add	a,#0xfa
      000DB8 F8               [12] 2736 	mov	r0,a
      000DB9 E6               [12] 2737 	mov	a,@r0
      000DBA C0 E0            [24] 2738 	push	acc
      000DBC 08               [12] 2739 	inc	r0
      000DBD E6               [12] 2740 	mov	a,@r0
      000DBE C0 E0            [24] 2741 	push	acc
      000DC0 08               [12] 2742 	inc	r0
      000DC1 E6               [12] 2743 	mov	a,@r0
      000DC2 C0 E0            [24] 2744 	push	acc
      000DC4 08               [12] 2745 	inc	r0
      000DC5 E6               [12] 2746 	mov	a,@r0
      000DC6 C0 E0            [24] 2747 	push	acc
      000DC8 E5 1D            [12] 2748 	mov	a,_bp
      000DCA 24 09            [12] 2749 	add	a,#0x09
      000DCC F8               [12] 2750 	mov	r0,a
      000DCD E6               [12] 2751 	mov	a,@r0
      000DCE C0 E0            [24] 2752 	push	acc
      000DD0 08               [12] 2753 	inc	r0
      000DD1 E6               [12] 2754 	mov	a,@r0
      000DD2 C0 E0            [24] 2755 	push	acc
      000DD4 08               [12] 2756 	inc	r0
      000DD5 E6               [12] 2757 	mov	a,@r0
      000DD6 C0 E0            [24] 2758 	push	acc
      000DD8 08               [12] 2759 	inc	r0
      000DD9 E6               [12] 2760 	mov	a,@r0
      000DDA C0 E0            [24] 2761 	push	acc
      000DDC E5 1D            [12] 2762 	mov	a,_bp
      000DDE 24 05            [12] 2763 	add	a,#0x05
      000DE0 F8               [12] 2764 	mov	r0,a
      000DE1 E6               [12] 2765 	mov	a,@r0
      000DE2 C0 E0            [24] 2766 	push	acc
      000DE4 08               [12] 2767 	inc	r0
      000DE5 E6               [12] 2768 	mov	a,@r0
      000DE6 C0 E0            [24] 2769 	push	acc
      000DE8 08               [12] 2770 	inc	r0
      000DE9 E6               [12] 2771 	mov	a,@r0
      000DEA C0 E0            [24] 2772 	push	acc
      000DEC 08               [12] 2773 	inc	r0
      000DED E6               [12] 2774 	mov	a,@r0
      000DEE C0 E0            [24] 2775 	push	acc
      000DF0 E5 1D            [12] 2776 	mov	a,_bp
      000DF2 24 11            [12] 2777 	add	a,#0x11
      000DF4 F8               [12] 2778 	mov	r0,a
      000DF5 E6               [12] 2779 	mov	a,@r0
      000DF6 C0 E0            [24] 2780 	push	acc
      000DF8 08               [12] 2781 	inc	r0
      000DF9 E6               [12] 2782 	mov	a,@r0
      000DFA C0 E0            [24] 2783 	push	acc
      000DFC 08               [12] 2784 	inc	r0
      000DFD E6               [12] 2785 	mov	a,@r0
      000DFE C0 E0            [24] 2786 	push	acc
      000E00 08               [12] 2787 	inc	r0
      000E01 E6               [12] 2788 	mov	a,@r0
      000E02 C0 E0            [24] 2789 	push	acc
      000E04 8A 82            [24] 2790 	mov	dpl, r2
      000E06 8D 83            [24] 2791 	mov	dph, r5
      000E08 8F F0            [24] 2792 	mov	b, r7
      000E0A EE               [12] 2793 	mov	a, r6
      000E0B 12 07 08         [24] 2794 	lcall	_fuzzy_trapezoid
      000E0E AC 82            [24] 2795 	mov	r4, dpl
      000E10 AD 83            [24] 2796 	mov	r5, dph
      000E12 AE F0            [24] 2797 	mov	r6, b
      000E14 FF               [12] 2798 	mov	r7, a
      000E15 E5 81            [12] 2799 	mov	a,sp
      000E17 24 EF            [12] 2800 	add	a,#0xef
      000E19 F5 81            [12] 2801 	mov	sp,a
      000E1B 8C 82            [24] 2802 	mov	dpl, r4
      000E1D 8D 83            [24] 2803 	mov	dph, r5
      000E1F 8E F0            [24] 2804 	mov	b, r6
      000E21 EF               [12] 2805 	mov	a, r7
      000E22 80 06            [24] 2806 	sjmp	00107$
      000E24                       2807 00106$:
      000E24 90 00 00         [24] 2808 	mov	dptr,#0x0000
      000E27 E4               [12] 2809 	clr	a
      000E28 F5 F0            [12] 2810 	mov	b,a
      000E2A                       2811 00107$:
      000E2A 85 1D 81         [24] 2812 	mov	sp,_bp
      000E2D D0 1D            [24] 2813 	pop	_bp
                           000D78  2814 	C$fuzzy.h$60$1_0$25 ==.
                           000D78  2815 	XFcontroller_8051$fuzzy_8051_eval$0$0 ==.
      000E2F 22               [24] 2816 	ret
                                   2817 ;------------------------------------------------------------
                                   2818 ;Allocation info for local variables in function 'fuzzy_rules_add_8051'
                                   2819 ;------------------------------------------------------------
                                   2820 ;value         Allocated to stack - _bp -6 +4 
                                   2821 ;output        Allocated to stack - _bp -9 +3 
                                   2822 ;rules         Allocated to stack - _bp +1 +3 
                                   2823 ;index         Allocated to registers r3 
                                   2824 ;sloc0         Allocated to stack - _bp +5 +1 
                                   2825 ;sloc1         Allocated to stack - _bp +4 +3 
                                   2826 ;sloc2         Allocated to stack - _bp +7 +3 
                                   2827 ;------------------------------------------------------------
                           000D79  2828 	G$fuzzy_rules_add_8051$0$0 ==.
                           000D79  2829 	C$fuzzy.h$61$1_0$27 ==.
                                   2830 ;	../../fuzzy.h:61: bool fuzzy_rules_add_8051(fuzzy_rules_t *rules, float value, const fuzzy_variable_8051_t *output) { uint8_t index; if (rules->count >= FUZZY_MAX_RULES) return false; index = rules->count; rules->rules[index].value = fuzzy_8051_clamp(value); rules->rules[index].output = output; rules->count = index + 1u; return true; }
                                   2831 ;	-----------------------------------------
                                   2832 ;	 function fuzzy_rules_add_8051
                                   2833 ;	-----------------------------------------
      000E30                       2834 _fuzzy_rules_add_8051:
      000E30 C0 1D            [24] 2835 	push	_bp
      000E32 85 81 1D         [24] 2836 	mov	_bp,sp
      000E35 C0 82            [24] 2837 	push	dpl
      000E37 C0 83            [24] 2838 	push	dph
      000E39 C0 F0            [24] 2839 	push	b
      000E3B E5 81            [12] 2840 	mov	a,sp
      000E3D 24 06            [12] 2841 	add	a,#0x06
      000E3F F5 81            [12] 2842 	mov	sp,a
      000E41 A8 1D            [24] 2843 	mov	r0,_bp
      000E43 08               [12] 2844 	inc	r0
      000E44 E5 1D            [12] 2845 	mov	a,_bp
      000E46 24 07            [12] 2846 	add	a,#0x07
      000E48 F9               [12] 2847 	mov	r1,a
      000E49 74 0E            [12] 2848 	mov	a,#0x0e
      000E4B 26               [12] 2849 	add	a, @r0
      000E4C F7               [12] 2850 	mov	@r1,a
      000E4D E4               [12] 2851 	clr	a
      000E4E 08               [12] 2852 	inc	r0
      000E4F 36               [12] 2853 	addc	a, @r0
      000E50 09               [12] 2854 	inc	r1
      000E51 F7               [12] 2855 	mov	@r1,a
      000E52 08               [12] 2856 	inc	r0
      000E53 E6               [12] 2857 	mov	a,@r0
      000E54 09               [12] 2858 	inc	r1
      000E55 F7               [12] 2859 	mov	@r1,a
      000E56 E5 1D            [12] 2860 	mov	a,_bp
      000E58 24 07            [12] 2861 	add	a,#0x07
      000E5A F8               [12] 2862 	mov	r0,a
      000E5B 86 82            [24] 2863 	mov	dpl,@r0
      000E5D 08               [12] 2864 	inc	r0
      000E5E 86 83            [24] 2865 	mov	dph,@r0
      000E60 08               [12] 2866 	inc	r0
      000E61 86 F0            [24] 2867 	mov	b,@r0
      000E63 12 1C 3C         [24] 2868 	lcall	__gptrget
      000E66 FF               [12] 2869 	mov	r7,a
      000E67 BF 02 00         [24] 2870 	cjne	r7,#0x02,00111$
      000E6A                       2871 00111$:
      000E6A 40 06            [24] 2872 	jc	00102$
      000E6C 75 82 00         [24] 2873 	mov	dpl, #0x00
      000E6F 02 0F 15         [24] 2874 	ljmp	00103$
      000E72                       2875 00102$:
      000E72 8F 03            [24] 2876 	mov	ar3,r7
      000E74 EB               [12] 2877 	mov	a,r3
      000E75 75 F0 07         [24] 2878 	mov	b,#0x07
      000E78 A4               [48] 2879 	mul	ab
      000E79 FA               [12] 2880 	mov	r2,a
      000E7A A8 1D            [24] 2881 	mov	r0,_bp
      000E7C 08               [12] 2882 	inc	r0
      000E7D E5 1D            [12] 2883 	mov	a,_bp
      000E7F 24 04            [12] 2884 	add	a,#0x04
      000E81 F9               [12] 2885 	mov	r1,a
      000E82 EA               [12] 2886 	mov	a,r2
      000E83 26               [12] 2887 	add	a, @r0
      000E84 F7               [12] 2888 	mov	@r1,a
      000E85 E4               [12] 2889 	clr	a
      000E86 08               [12] 2890 	inc	r0
      000E87 36               [12] 2891 	addc	a, @r0
      000E88 09               [12] 2892 	inc	r1
      000E89 F7               [12] 2893 	mov	@r1,a
      000E8A 08               [12] 2894 	inc	r0
      000E8B E6               [12] 2895 	mov	a,@r0
      000E8C 09               [12] 2896 	inc	r1
      000E8D F7               [12] 2897 	mov	@r1,a
      000E8E E5 1D            [12] 2898 	mov	a,_bp
      000E90 24 FA            [12] 2899 	add	a,#0xfa
      000E92 F8               [12] 2900 	mov	r0,a
      000E93 86 82            [24] 2901 	mov	dpl, @r0
      000E95 08               [12] 2902 	inc	r0
      000E96 86 83            [24] 2903 	mov	dph, @r0
      000E98 08               [12] 2904 	inc	r0
      000E99 86 F0            [24] 2905 	mov	b, @r0
      000E9B 08               [12] 2906 	inc	r0
      000E9C E6               [12] 2907 	mov	a, @r0
      000E9D C0 03            [24] 2908 	push	ar3
      000E9F C0 02            [24] 2909 	push	ar2
      000EA1 12 00 B7         [24] 2910 	lcall	_fuzzy_8051_clamp
      000EA4 AD 82            [24] 2911 	mov	r5, dpl
      000EA6 AE 83            [24] 2912 	mov	r6, dph
      000EA8 AC F0            [24] 2913 	mov	r4, b
      000EAA FF               [12] 2914 	mov	r7, a
      000EAB D0 02            [24] 2915 	pop	ar2
      000EAD D0 03            [24] 2916 	pop	ar3
      000EAF E5 1D            [12] 2917 	mov	a,_bp
      000EB1 24 04            [12] 2918 	add	a,#0x04
      000EB3 F8               [12] 2919 	mov	r0,a
      000EB4 86 82            [24] 2920 	mov	dpl,@r0
      000EB6 08               [12] 2921 	inc	r0
      000EB7 86 83            [24] 2922 	mov	dph,@r0
      000EB9 08               [12] 2923 	inc	r0
      000EBA 86 F0            [24] 2924 	mov	b,@r0
      000EBC ED               [12] 2925 	mov	a,r5
      000EBD 12 1A 17         [24] 2926 	lcall	__gptrput
      000EC0 A3               [24] 2927 	inc	dptr
      000EC1 EE               [12] 2928 	mov	a,r6
      000EC2 12 1A 17         [24] 2929 	lcall	__gptrput
      000EC5 A3               [24] 2930 	inc	dptr
      000EC6 EC               [12] 2931 	mov	a,r4
      000EC7 12 1A 17         [24] 2932 	lcall	__gptrput
      000ECA A3               [24] 2933 	inc	dptr
      000ECB EF               [12] 2934 	mov	a,r7
      000ECC 12 1A 17         [24] 2935 	lcall	__gptrput
      000ECF A8 1D            [24] 2936 	mov	r0,_bp
      000ED1 08               [12] 2937 	inc	r0
      000ED2 EA               [12] 2938 	mov	a,r2
      000ED3 26               [12] 2939 	add	a, @r0
      000ED4 FD               [12] 2940 	mov	r5,a
      000ED5 E4               [12] 2941 	clr	a
      000ED6 08               [12] 2942 	inc	r0
      000ED7 36               [12] 2943 	addc	a, @r0
      000ED8 FE               [12] 2944 	mov	r6,a
      000ED9 08               [12] 2945 	inc	r0
      000EDA 86 07            [24] 2946 	mov	ar7,@r0
      000EDC 74 04            [12] 2947 	mov	a,#0x04
      000EDE 2D               [12] 2948 	add	a, r5
      000EDF FD               [12] 2949 	mov	r5,a
      000EE0 E4               [12] 2950 	clr	a
      000EE1 3E               [12] 2951 	addc	a, r6
      000EE2 FE               [12] 2952 	mov	r6,a
      000EE3 8D 82            [24] 2953 	mov	dpl,r5
      000EE5 8E 83            [24] 2954 	mov	dph,r6
      000EE7 8F F0            [24] 2955 	mov	b,r7
      000EE9 E5 1D            [12] 2956 	mov	a,_bp
      000EEB 24 F7            [12] 2957 	add	a,#0xf7
      000EED F8               [12] 2958 	mov	r0,a
      000EEE E6               [12] 2959 	mov	a,@r0
      000EEF 12 1A 17         [24] 2960 	lcall	__gptrput
      000EF2 A3               [24] 2961 	inc	dptr
      000EF3 08               [12] 2962 	inc	r0
      000EF4 E6               [12] 2963 	mov	a,@r0
      000EF5 12 1A 17         [24] 2964 	lcall	__gptrput
      000EF8 A3               [24] 2965 	inc	dptr
      000EF9 08               [12] 2966 	inc	r0
      000EFA E6               [12] 2967 	mov	a,@r0
      000EFB 12 1A 17         [24] 2968 	lcall	__gptrput
      000EFE EB               [12] 2969 	mov	a,r3
      000EFF 04               [12] 2970 	inc	a
      000F00 FF               [12] 2971 	mov	r7,a
      000F01 E5 1D            [12] 2972 	mov	a,_bp
      000F03 24 07            [12] 2973 	add	a,#0x07
      000F05 F8               [12] 2974 	mov	r0,a
      000F06 86 82            [24] 2975 	mov	dpl,@r0
      000F08 08               [12] 2976 	inc	r0
      000F09 86 83            [24] 2977 	mov	dph,@r0
      000F0B 08               [12] 2978 	inc	r0
      000F0C 86 F0            [24] 2979 	mov	b,@r0
      000F0E EF               [12] 2980 	mov	a,r7
      000F0F 12 1A 17         [24] 2981 	lcall	__gptrput
      000F12 75 82 01         [24] 2982 	mov	dpl, #0x01
      000F15                       2983 00103$:
      000F15 85 1D 81         [24] 2984 	mov	sp,_bp
      000F18 D0 1D            [24] 2985 	pop	_bp
                           000E63  2986 	C$fuzzy.h$61$1_0$27 ==.
                           000E63  2987 	XG$fuzzy_rules_add_8051$0$0 ==.
      000F1A 22               [24] 2988 	ret
                                   2989 ;------------------------------------------------------------
                                   2990 ;Allocation info for local variables in function 'fuzzy_8051_height'
                                   2991 ;------------------------------------------------------------
                                   2992 ;x             Allocated to stack - _bp -6 +4 
                                   2993 ;rules         Allocated to stack - _bp +1 +3 
                                   2994 ;i             Allocated to registers r7 
                                   2995 ;aggregate     Allocated to stack - _bp +14 +4 
                                   2996 ;membership    Allocated to stack - _bp +18 +4 
                                   2997 ;implied       Allocated to registers r3 r4 r5 r6 
                                   2998 ;sloc0         Allocated to stack - _bp +4 +3 
                                   2999 ;sloc1         Allocated to stack - _bp +7 +3 
                                   3000 ;sloc2         Allocated to stack - _bp +10 +4 
                                   3001 ;------------------------------------------------------------
                           000E64  3002 	Fcontroller_8051$fuzzy_8051_height$0$0 ==.
                           000E64  3003 	C$fuzzy.h$62$1_0$29 ==.
                                   3004 ;	../../fuzzy.h:62: static float fuzzy_8051_height(const fuzzy_rules_t *rules, float x) { uint8_t i; float aggregate; float membership; float implied; aggregate = 0.0f; for (i = 0u; i < rules->count; ++i) { membership = fuzzy_8051_eval(rules->rules[i].output, x); implied = rules->rules[i].value < membership ? rules->rules[i].value : membership; if (implied > aggregate) aggregate = implied; } return aggregate; }
                                   3005 ;	-----------------------------------------
                                   3006 ;	 function fuzzy_8051_height
                                   3007 ;	-----------------------------------------
      000F1B                       3008 _fuzzy_8051_height:
      000F1B C0 1D            [24] 3009 	push	_bp
      000F1D 85 81 1D         [24] 3010 	mov	_bp,sp
      000F20 C0 82            [24] 3011 	push	dpl
      000F22 C0 83            [24] 3012 	push	dph
      000F24 C0 F0            [24] 3013 	push	b
      000F26 E5 81            [12] 3014 	mov	a,sp
      000F28 24 12            [12] 3015 	add	a,#0x12
      000F2A F5 81            [12] 3016 	mov	sp,a
      000F2C E5 1D            [12] 3017 	mov	a,_bp
      000F2E 24 0E            [12] 3018 	add	a,#0x0e
      000F30 F8               [12] 3019 	mov	r0,a
      000F31 E4               [12] 3020 	clr	a
      000F32 F6               [12] 3021 	mov	@r0,a
      000F33 08               [12] 3022 	inc	r0
      000F34 F6               [12] 3023 	mov	@r0,a
      000F35 08               [12] 3024 	inc	r0
      000F36 F6               [12] 3025 	mov	@r0,a
      000F37 08               [12] 3026 	inc	r0
      000F38 F6               [12] 3027 	mov	@r0,a
      000F39 A8 1D            [24] 3028 	mov	r0,_bp
      000F3B 08               [12] 3029 	inc	r0
      000F3C E5 1D            [12] 3030 	mov	a,_bp
      000F3E 24 07            [12] 3031 	add	a,#0x07
      000F40 F9               [12] 3032 	mov	r1,a
      000F41 E6               [12] 3033 	mov	a,@r0
      000F42 F7               [12] 3034 	mov	@r1,a
      000F43 08               [12] 3035 	inc	r0
      000F44 E6               [12] 3036 	mov	a,@r0
      000F45 09               [12] 3037 	inc	r1
      000F46 F7               [12] 3038 	mov	@r1,a
      000F47 08               [12] 3039 	inc	r0
      000F48 E6               [12] 3040 	mov	a,@r0
      000F49 09               [12] 3041 	inc	r1
      000F4A F7               [12] 3042 	mov	@r1,a
      000F4B A8 1D            [24] 3043 	mov	r0,_bp
      000F4D 08               [12] 3044 	inc	r0
      000F4E E5 1D            [12] 3045 	mov	a,_bp
      000F50 24 04            [12] 3046 	add	a,#0x04
      000F52 F9               [12] 3047 	mov	r1,a
      000F53 74 0E            [12] 3048 	mov	a,#0x0e
      000F55 26               [12] 3049 	add	a, @r0
      000F56 F7               [12] 3050 	mov	@r1,a
      000F57 E4               [12] 3051 	clr	a
      000F58 08               [12] 3052 	inc	r0
      000F59 36               [12] 3053 	addc	a, @r0
      000F5A 09               [12] 3054 	inc	r1
      000F5B F7               [12] 3055 	mov	@r1,a
      000F5C 08               [12] 3056 	inc	r0
      000F5D E6               [12] 3057 	mov	a,@r0
      000F5E 09               [12] 3058 	inc	r1
      000F5F F7               [12] 3059 	mov	@r1,a
      000F60 7F 00            [12] 3060 	mov	r7,#0x00
      000F62                       3061 00105$:
      000F62 E5 1D            [12] 3062 	mov	a,_bp
      000F64 24 04            [12] 3063 	add	a,#0x04
      000F66 F8               [12] 3064 	mov	r0,a
      000F67 86 82            [24] 3065 	mov	dpl,@r0
      000F69 08               [12] 3066 	inc	r0
      000F6A 86 83            [24] 3067 	mov	dph,@r0
      000F6C 08               [12] 3068 	inc	r0
      000F6D 86 F0            [24] 3069 	mov	b,@r0
      000F6F 12 1C 3C         [24] 3070 	lcall	__gptrget
      000F72 FE               [12] 3071 	mov	r6,a
      000F73 C3               [12] 3072 	clr	c
      000F74 EF               [12] 3073 	mov	a,r7
      000F75 9E               [12] 3074 	subb	a,r6
      000F76 40 03            [24] 3075 	jc	00136$
      000F78 02 10 B8         [24] 3076 	ljmp	00103$
      000F7B                       3077 00136$:
      000F7B EF               [12] 3078 	mov	a,r7
      000F7C 75 F0 07         [24] 3079 	mov	b,#0x07
      000F7F A4               [48] 3080 	mul	ab
      000F80 FE               [12] 3081 	mov	r6,a
      000F81 C0 07            [24] 3082 	push	ar7
      000F83 E5 1D            [12] 3083 	mov	a,_bp
      000F85 24 07            [12] 3084 	add	a,#0x07
      000F87 F8               [12] 3085 	mov	r0,a
      000F88 EE               [12] 3086 	mov	a,r6
      000F89 26               [12] 3087 	add	a, @r0
      000F8A FC               [12] 3088 	mov	r4,a
      000F8B E4               [12] 3089 	clr	a
      000F8C 08               [12] 3090 	inc	r0
      000F8D 36               [12] 3091 	addc	a, @r0
      000F8E FD               [12] 3092 	mov	r5,a
      000F8F 08               [12] 3093 	inc	r0
      000F90 86 07            [24] 3094 	mov	ar7,@r0
      000F92 74 04            [12] 3095 	mov	a,#0x04
      000F94 2C               [12] 3096 	add	a, r4
      000F95 FC               [12] 3097 	mov	r4,a
      000F96 E4               [12] 3098 	clr	a
      000F97 3D               [12] 3099 	addc	a, r5
      000F98 FD               [12] 3100 	mov	r5,a
      000F99 8C 82            [24] 3101 	mov	dpl,r4
      000F9B 8D 83            [24] 3102 	mov	dph,r5
      000F9D 8F F0            [24] 3103 	mov	b,r7
      000F9F 12 1C 3C         [24] 3104 	lcall	__gptrget
      000FA2 FC               [12] 3105 	mov	r4,a
      000FA3 A3               [24] 3106 	inc	dptr
      000FA4 12 1C 3C         [24] 3107 	lcall	__gptrget
      000FA7 FD               [12] 3108 	mov	r5,a
      000FA8 A3               [24] 3109 	inc	dptr
      000FA9 12 1C 3C         [24] 3110 	lcall	__gptrget
      000FAC FF               [12] 3111 	mov	r7,a
      000FAD C0 07            [24] 3112 	push	ar7
      000FAF C0 06            [24] 3113 	push	ar6
      000FB1 E5 1D            [12] 3114 	mov	a,_bp
      000FB3 24 FA            [12] 3115 	add	a,#0xfa
      000FB5 F8               [12] 3116 	mov	r0,a
      000FB6 E6               [12] 3117 	mov	a,@r0
      000FB7 C0 E0            [24] 3118 	push	acc
      000FB9 08               [12] 3119 	inc	r0
      000FBA E6               [12] 3120 	mov	a,@r0
      000FBB C0 E0            [24] 3121 	push	acc
      000FBD 08               [12] 3122 	inc	r0
      000FBE E6               [12] 3123 	mov	a,@r0
      000FBF C0 E0            [24] 3124 	push	acc
      000FC1 08               [12] 3125 	inc	r0
      000FC2 E6               [12] 3126 	mov	a,@r0
      000FC3 C0 E0            [24] 3127 	push	acc
      000FC5 8C 82            [24] 3128 	mov	dpl, r4
      000FC7 8D 83            [24] 3129 	mov	dph, r5
      000FC9 8F F0            [24] 3130 	mov	b, r7
      000FCB 12 0A 9F         [24] 3131 	lcall	_fuzzy_8051_eval
      000FCE C8               [12] 3132 	xch	a,r0
      000FCF E5 1D            [12] 3133 	mov	a,_bp
      000FD1 24 12            [12] 3134 	add	a,#0x12
      000FD3 C8               [12] 3135 	xch	a,r0
      000FD4 A6 82            [24] 3136 	mov	@r0, dpl
      000FD6 08               [12] 3137 	inc	r0
      000FD7 A6 83            [24] 3138 	mov	@r0, dph
      000FD9 08               [12] 3139 	inc	r0
      000FDA A6 F0            [24] 3140 	mov	@r0, b
      000FDC 08               [12] 3141 	inc	r0
      000FDD F6               [12] 3142 	mov	@r0,a
      000FDE E5 81            [12] 3143 	mov	a,sp
      000FE0 24 FC            [12] 3144 	add	a,#0xfc
      000FE2 F5 81            [12] 3145 	mov	sp,a
      000FE4 D0 06            [24] 3146 	pop	ar6
      000FE6 D0 07            [24] 3147 	pop	ar7
      000FE8 A8 1D            [24] 3148 	mov	r0,_bp
      000FEA 08               [12] 3149 	inc	r0
      000FEB EE               [12] 3150 	mov	a,r6
      000FEC 26               [12] 3151 	add	a, @r0
      000FED FE               [12] 3152 	mov	r6,a
      000FEE E4               [12] 3153 	clr	a
      000FEF 08               [12] 3154 	inc	r0
      000FF0 36               [12] 3155 	addc	a, @r0
      000FF1 FF               [12] 3156 	mov	r7,a
      000FF2 08               [12] 3157 	inc	r0
      000FF3 86 05            [24] 3158 	mov	ar5,@r0
      000FF5 8E 82            [24] 3159 	mov	dpl,r6
      000FF7 8F 83            [24] 3160 	mov	dph,r7
      000FF9 8D F0            [24] 3161 	mov	b,r5
      000FFB E5 1D            [12] 3162 	mov	a,_bp
      000FFD 24 0A            [12] 3163 	add	a,#0x0a
      000FFF F8               [12] 3164 	mov	r0,a
      001000 12 1C 3C         [24] 3165 	lcall	__gptrget
      001003 F6               [12] 3166 	mov	@r0,a
      001004 A3               [24] 3167 	inc	dptr
      001005 12 1C 3C         [24] 3168 	lcall	__gptrget
      001008 08               [12] 3169 	inc	r0
      001009 F6               [12] 3170 	mov	@r0,a
      00100A A3               [24] 3171 	inc	dptr
      00100B 12 1C 3C         [24] 3172 	lcall	__gptrget
      00100E 08               [12] 3173 	inc	r0
      00100F F6               [12] 3174 	mov	@r0,a
      001010 A3               [24] 3175 	inc	dptr
      001011 12 1C 3C         [24] 3176 	lcall	__gptrget
      001014 08               [12] 3177 	inc	r0
      001015 F6               [12] 3178 	mov	@r0,a
      001016 E5 1D            [12] 3179 	mov	a,_bp
      001018 24 12            [12] 3180 	add	a,#0x12
      00101A F8               [12] 3181 	mov	r0,a
      00101B E6               [12] 3182 	mov	a,@r0
      00101C C0 E0            [24] 3183 	push	acc
      00101E 08               [12] 3184 	inc	r0
      00101F E6               [12] 3185 	mov	a,@r0
      001020 C0 E0            [24] 3186 	push	acc
      001022 08               [12] 3187 	inc	r0
      001023 E6               [12] 3188 	mov	a,@r0
      001024 C0 E0            [24] 3189 	push	acc
      001026 08               [12] 3190 	inc	r0
      001027 E6               [12] 3191 	mov	a,@r0
      001028 C0 E0            [24] 3192 	push	acc
      00102A E5 1D            [12] 3193 	mov	a,_bp
      00102C 24 0A            [12] 3194 	add	a,#0x0a
      00102E F8               [12] 3195 	mov	r0,a
      00102F 86 82            [24] 3196 	mov	dpl, @r0
      001031 08               [12] 3197 	inc	r0
      001032 86 83            [24] 3198 	mov	dph, @r0
      001034 08               [12] 3199 	inc	r0
      001035 86 F0            [24] 3200 	mov	b, @r0
      001037 08               [12] 3201 	inc	r0
      001038 E6               [12] 3202 	mov	a, @r0
      001039 12 1A 32         [24] 3203 	lcall	___fslt
      00103C AF 82            [24] 3204 	mov	r7, dpl
      00103E E5 81            [12] 3205 	mov	a,sp
      001040 24 FC            [12] 3206 	add	a,#0xfc
      001042 F5 81            [12] 3207 	mov	sp,a
      001044 EF               [12] 3208 	mov	a,r7
      001045 D0 07            [24] 3209 	pop	ar7
      001047 60 12            [24] 3210 	jz	00109$
      001049 E5 1D            [12] 3211 	mov	a,_bp
      00104B 24 0A            [12] 3212 	add	a,#0x0a
      00104D F8               [12] 3213 	mov	r0,a
      00104E 86 03            [24] 3214 	mov	ar3,@r0
      001050 08               [12] 3215 	inc	r0
      001051 86 04            [24] 3216 	mov	ar4,@r0
      001053 08               [12] 3217 	inc	r0
      001054 86 05            [24] 3218 	mov	ar5,@r0
      001056 08               [12] 3219 	inc	r0
      001057 86 06            [24] 3220 	mov	ar6,@r0
      001059 80 10            [24] 3221 	sjmp	00110$
      00105B                       3222 00109$:
      00105B E5 1D            [12] 3223 	mov	a,_bp
      00105D 24 12            [12] 3224 	add	a,#0x12
      00105F F8               [12] 3225 	mov	r0,a
      001060 86 03            [24] 3226 	mov	ar3,@r0
      001062 08               [12] 3227 	inc	r0
      001063 86 04            [24] 3228 	mov	ar4,@r0
      001065 08               [12] 3229 	inc	r0
      001066 86 05            [24] 3230 	mov	ar5,@r0
      001068 08               [12] 3231 	inc	r0
      001069 86 06            [24] 3232 	mov	ar6,@r0
      00106B                       3233 00110$:
      00106B C0 07            [24] 3234 	push	ar7
      00106D C0 06            [24] 3235 	push	ar6
      00106F C0 05            [24] 3236 	push	ar5
      001071 C0 04            [24] 3237 	push	ar4
      001073 C0 03            [24] 3238 	push	ar3
      001075 C0 03            [24] 3239 	push	ar3
      001077 C0 04            [24] 3240 	push	ar4
      001079 C0 05            [24] 3241 	push	ar5
      00107B C0 06            [24] 3242 	push	ar6
      00107D E5 1D            [12] 3243 	mov	a,_bp
      00107F 24 0E            [12] 3244 	add	a,#0x0e
      001081 F8               [12] 3245 	mov	r0,a
      001082 86 82            [24] 3246 	mov	dpl, @r0
      001084 08               [12] 3247 	inc	r0
      001085 86 83            [24] 3248 	mov	dph, @r0
      001087 08               [12] 3249 	inc	r0
      001088 86 F0            [24] 3250 	mov	b, @r0
      00108A 08               [12] 3251 	inc	r0
      00108B E6               [12] 3252 	mov	a, @r0
      00108C 12 1A 32         [24] 3253 	lcall	___fslt
      00108F AA 82            [24] 3254 	mov	r2, dpl
      001091 E5 81            [12] 3255 	mov	a,sp
      001093 24 FC            [12] 3256 	add	a,#0xfc
      001095 F5 81            [12] 3257 	mov	sp,a
      001097 D0 03            [24] 3258 	pop	ar3
      001099 D0 04            [24] 3259 	pop	ar4
      00109B D0 05            [24] 3260 	pop	ar5
      00109D D0 06            [24] 3261 	pop	ar6
      00109F D0 07            [24] 3262 	pop	ar7
      0010A1 EA               [12] 3263 	mov	a,r2
      0010A2 60 10            [24] 3264 	jz	00106$
      0010A4 E5 1D            [12] 3265 	mov	a,_bp
      0010A6 24 0E            [12] 3266 	add	a,#0x0e
      0010A8 F8               [12] 3267 	mov	r0,a
      0010A9 A6 03            [24] 3268 	mov	@r0,ar3
      0010AB 08               [12] 3269 	inc	r0
      0010AC A6 04            [24] 3270 	mov	@r0,ar4
      0010AE 08               [12] 3271 	inc	r0
      0010AF A6 05            [24] 3272 	mov	@r0,ar5
      0010B1 08               [12] 3273 	inc	r0
      0010B2 A6 06            [24] 3274 	mov	@r0,ar6
      0010B4                       3275 00106$:
      0010B4 0F               [12] 3276 	inc	r7
      0010B5 02 0F 62         [24] 3277 	ljmp	00105$
      0010B8                       3278 00103$:
      0010B8 E5 1D            [12] 3279 	mov	a,_bp
      0010BA 24 0E            [12] 3280 	add	a,#0x0e
      0010BC F8               [12] 3281 	mov	r0,a
      0010BD 86 82            [24] 3282 	mov	dpl, @r0
      0010BF 08               [12] 3283 	inc	r0
      0010C0 86 83            [24] 3284 	mov	dph, @r0
      0010C2 08               [12] 3285 	inc	r0
      0010C3 86 F0            [24] 3286 	mov	b, @r0
      0010C5 08               [12] 3287 	inc	r0
      0010C6 E6               [12] 3288 	mov	a, @r0
      0010C7 85 1D 81         [24] 3289 	mov	sp,_bp
      0010CA D0 1D            [24] 3290 	pop	_bp
                           001015  3291 	C$fuzzy.h$62$1_0$29 ==.
                           001015  3292 	XFcontroller_8051$fuzzy_8051_height$0$0 ==.
      0010CC 22               [24] 3293 	ret
                                   3294 ;------------------------------------------------------------
                                   3295 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify'
                                   3296 ;------------------------------------------------------------
                                   3297 ;lower         Allocated to stack - _bp -6 +4 
                                   3298 ;upper         Allocated to stack - _bp -10 +4 
                                   3299 ;step          Allocated to stack - _bp -14 +4 
                                   3300 ;method        Allocated to stack - _bp -15 +1 
                                   3301 ;rules         Allocated to stack - _bp +1 +3 
                                   3302 ;x             Allocated to stack - _bp +4 +4 
                                   3303 ;h             Allocated to stack - _bp +8 +4 
                                   3304 ;weighted      Allocated to stack - _bp +12 +4 
                                   3305 ;sum           Allocated to stack - _bp +16 +4 
                                   3306 ;maximum       Allocated to stack - _bp +20 +4 
                                   3307 ;maximum_sum   Allocated to stack - _bp +24 +4 
                                   3308 ;smallest      Allocated to stack - _bp +28 +4 
                                   3309 ;largest       Allocated to stack - _bp +32 +4 
                                   3310 ;maximum_count Allocated to registers r5 r4 
                                   3311 ;------------------------------------------------------------
                           001016  3312 	G$fuzzy_rules_defuzzify$0$0 ==.
                           001016  3313 	C$fuzzy.h$63$1_0$33 ==.
                                   3314 ;	../../fuzzy.h:63: float fuzzy_rules_defuzzify(const fuzzy_rules_t *rules, float lower, float upper, float step, fuzzy_defuzz_method_t method) { float x; float h; float weighted; float sum; float maximum; float maximum_sum; float smallest; float largest; unsigned int maximum_count; if (rules->count == 0u || lower > upper || step <= 0.0f) return 0.0f; weighted = 0.0f; sum = 0.0f; maximum = -1.0f; maximum_sum = 0.0f; maximum_count = 0u; smallest = lower; largest = lower; for (x = lower; x <= upper; x += step) { h = fuzzy_8051_height(rules, x); weighted += x * h; sum += h; if (h > maximum) { maximum = h; maximum_sum = x; maximum_count = 1u; smallest = x; largest = x; } else if (h == maximum) { maximum_sum += x; ++maximum_count; largest = x; } } if (method == FUZZY_DEFUZZ_MOM) return maximum > 0.0f ? maximum_sum / (float)maximum_count : 0.0f; if (method == FUZZY_DEFUZZ_SOM) return maximum > 0.0f ? smallest : 0.0f; if (method == FUZZY_DEFUZZ_LOM) return maximum > 0.0f ? largest : 0.0f; return sum > 0.0f ? weighted / sum : 0.0f; }
                                   3315 ;	-----------------------------------------
                                   3316 ;	 function fuzzy_rules_defuzzify
                                   3317 ;	-----------------------------------------
      0010CD                       3318 _fuzzy_rules_defuzzify:
      0010CD C0 1D            [24] 3319 	push	_bp
      0010CF 85 81 1D         [24] 3320 	mov	_bp,sp
      0010D2 C0 82            [24] 3321 	push	dpl
      0010D4 C0 83            [24] 3322 	push	dph
      0010D6 C0 F0            [24] 3323 	push	b
      0010D8 E5 81            [12] 3324 	mov	a,sp
      0010DA 24 20            [12] 3325 	add	a,#0x20
      0010DC F5 81            [12] 3326 	mov	sp,a
      0010DE A8 1D            [24] 3327 	mov	r0,_bp
      0010E0 08               [12] 3328 	inc	r0
      0010E1 74 0E            [12] 3329 	mov	a,#0x0e
      0010E3 26               [12] 3330 	add	a, @r0
      0010E4 FA               [12] 3331 	mov	r2,a
      0010E5 E4               [12] 3332 	clr	a
      0010E6 08               [12] 3333 	inc	r0
      0010E7 36               [12] 3334 	addc	a, @r0
      0010E8 FB               [12] 3335 	mov	r3,a
      0010E9 08               [12] 3336 	inc	r0
      0010EA 86 04            [24] 3337 	mov	ar4,@r0
      0010EC 8A 82            [24] 3338 	mov	dpl,r2
      0010EE 8B 83            [24] 3339 	mov	dph,r3
      0010F0 8C F0            [24] 3340 	mov	b,r4
      0010F2 12 1C 3C         [24] 3341 	lcall	__gptrget
      0010F5 60 5C            [24] 3342 	jz	00101$
      0010F7 E5 1D            [12] 3343 	mov	a,_bp
      0010F9 24 FA            [12] 3344 	add	a,#0xfa
      0010FB F8               [12] 3345 	mov	r0,a
      0010FC E6               [12] 3346 	mov	a,@r0
      0010FD C0 E0            [24] 3347 	push	acc
      0010FF 08               [12] 3348 	inc	r0
      001100 E6               [12] 3349 	mov	a,@r0
      001101 C0 E0            [24] 3350 	push	acc
      001103 08               [12] 3351 	inc	r0
      001104 E6               [12] 3352 	mov	a,@r0
      001105 C0 E0            [24] 3353 	push	acc
      001107 08               [12] 3354 	inc	r0
      001108 E6               [12] 3355 	mov	a,@r0
      001109 C0 E0            [24] 3356 	push	acc
      00110B E5 1D            [12] 3357 	mov	a,_bp
      00110D 24 F6            [12] 3358 	add	a,#0xf6
      00110F F8               [12] 3359 	mov	r0,a
      001110 86 82            [24] 3360 	mov	dpl, @r0
      001112 08               [12] 3361 	inc	r0
      001113 86 83            [24] 3362 	mov	dph, @r0
      001115 08               [12] 3363 	inc	r0
      001116 86 F0            [24] 3364 	mov	b, @r0
      001118 08               [12] 3365 	inc	r0
      001119 E6               [12] 3366 	mov	a, @r0
      00111A 12 1A 32         [24] 3367 	lcall	___fslt
      00111D AC 82            [24] 3368 	mov	r4, dpl
      00111F E5 81            [12] 3369 	mov	a,sp
      001121 24 FC            [12] 3370 	add	a,#0xfc
      001123 F5 81            [12] 3371 	mov	sp,a
      001125 EC               [12] 3372 	mov	a,r4
      001126 70 2B            [24] 3373 	jnz	00101$
      001128 E5 1D            [12] 3374 	mov	a,_bp
      00112A 24 F2            [12] 3375 	add	a,#0xf2
      00112C F8               [12] 3376 	mov	r0,a
      00112D E6               [12] 3377 	mov	a,@r0
      00112E C0 E0            [24] 3378 	push	acc
      001130 08               [12] 3379 	inc	r0
      001131 E6               [12] 3380 	mov	a,@r0
      001132 C0 E0            [24] 3381 	push	acc
      001134 08               [12] 3382 	inc	r0
      001135 E6               [12] 3383 	mov	a,@r0
      001136 C0 E0            [24] 3384 	push	acc
      001138 08               [12] 3385 	inc	r0
      001139 E6               [12] 3386 	mov	a,@r0
      00113A C0 E0            [24] 3387 	push	acc
      00113C 90 00 00         [24] 3388 	mov	dptr,#0x0000
      00113F E4               [12] 3389 	clr	a
      001140 F5 F0            [12] 3390 	mov	b,a
      001142 12 1A 32         [24] 3391 	lcall	___fslt
      001145 E5 81            [12] 3392 	mov	a,sp
      001147 24 FC            [12] 3393 	add	a,#0xfc
      001149 F5 81            [12] 3394 	mov	sp,a
      00114B E5 82            [12] 3395 	mov	a, dpl
      00114D 24 FF            [12] 3396 	add	a,#0xff
      00114F 92 00            [24] 3397 	mov	b0,c
      001151 40 09            [24] 3398 	jc	00102$
      001153                       3399 00101$:
      001153 90 00 00         [24] 3400 	mov	dptr,#0x0000
      001156 E4               [12] 3401 	clr	a
      001157 F5 F0            [12] 3402 	mov	b,a
      001159 02 16 0B         [24] 3403 	ljmp	00120$
      00115C                       3404 00102$:
      00115C E5 1D            [12] 3405 	mov	a,_bp
      00115E 24 0C            [12] 3406 	add	a,#0x0c
      001160 F8               [12] 3407 	mov	r0,a
      001161 E4               [12] 3408 	clr	a
      001162 F6               [12] 3409 	mov	@r0,a
      001163 08               [12] 3410 	inc	r0
      001164 F6               [12] 3411 	mov	@r0,a
      001165 08               [12] 3412 	inc	r0
      001166 F6               [12] 3413 	mov	@r0,a
      001167 08               [12] 3414 	inc	r0
      001168 F6               [12] 3415 	mov	@r0,a
      001169 E5 1D            [12] 3416 	mov	a,_bp
      00116B 24 10            [12] 3417 	add	a,#0x10
      00116D F8               [12] 3418 	mov	r0,a
      00116E E4               [12] 3419 	clr	a
      00116F F6               [12] 3420 	mov	@r0,a
      001170 08               [12] 3421 	inc	r0
      001171 F6               [12] 3422 	mov	@r0,a
      001172 08               [12] 3423 	inc	r0
      001173 F6               [12] 3424 	mov	@r0,a
      001174 08               [12] 3425 	inc	r0
      001175 F6               [12] 3426 	mov	@r0,a
      001176 E5 1D            [12] 3427 	mov	a,_bp
      001178 24 14            [12] 3428 	add	a,#0x14
      00117A F8               [12] 3429 	mov	r0,a
      00117B E4               [12] 3430 	clr	a
      00117C F6               [12] 3431 	mov	@r0,a
      00117D 08               [12] 3432 	inc	r0
      00117E F6               [12] 3433 	mov	@r0,a
      00117F 08               [12] 3434 	inc	r0
      001180 76 80            [12] 3435 	mov	@r0,#0x80
      001182 08               [12] 3436 	inc	r0
      001183 76 BF            [12] 3437 	mov	@r0,#0xbf
      001185 E5 1D            [12] 3438 	mov	a,_bp
      001187 24 18            [12] 3439 	add	a,#0x18
      001189 F8               [12] 3440 	mov	r0,a
      00118A E4               [12] 3441 	clr	a
      00118B F6               [12] 3442 	mov	@r0,a
      00118C 08               [12] 3443 	inc	r0
      00118D F6               [12] 3444 	mov	@r0,a
      00118E 08               [12] 3445 	inc	r0
      00118F F6               [12] 3446 	mov	@r0,a
      001190 08               [12] 3447 	inc	r0
      001191 F6               [12] 3448 	mov	@r0,a
      001192 FD               [12] 3449 	mov	r5,a
      001193 FC               [12] 3450 	mov	r4,a
      001194 E5 1D            [12] 3451 	mov	a,_bp
      001196 24 FA            [12] 3452 	add	a,#0xfa
      001198 F8               [12] 3453 	mov	r0,a
      001199 E5 1D            [12] 3454 	mov	a,_bp
      00119B 24 1C            [12] 3455 	add	a,#0x1c
      00119D F9               [12] 3456 	mov	r1,a
      00119E E6               [12] 3457 	mov	a,@r0
      00119F F7               [12] 3458 	mov	@r1,a
      0011A0 08               [12] 3459 	inc	r0
      0011A1 E6               [12] 3460 	mov	a,@r0
      0011A2 09               [12] 3461 	inc	r1
      0011A3 F7               [12] 3462 	mov	@r1,a
      0011A4 08               [12] 3463 	inc	r0
      0011A5 E6               [12] 3464 	mov	a,@r0
      0011A6 09               [12] 3465 	inc	r1
      0011A7 F7               [12] 3466 	mov	@r1,a
      0011A8 08               [12] 3467 	inc	r0
      0011A9 E6               [12] 3468 	mov	a,@r0
      0011AA 09               [12] 3469 	inc	r1
      0011AB F7               [12] 3470 	mov	@r1,a
      0011AC E5 1D            [12] 3471 	mov	a,_bp
      0011AE 24 1C            [12] 3472 	add	a,#0x1c
      0011B0 F8               [12] 3473 	mov	r0,a
      0011B1 E5 1D            [12] 3474 	mov	a,_bp
      0011B3 24 20            [12] 3475 	add	a,#0x20
      0011B5 F9               [12] 3476 	mov	r1,a
      0011B6 E6               [12] 3477 	mov	a,@r0
      0011B7 F7               [12] 3478 	mov	@r1,a
      0011B8 08               [12] 3479 	inc	r0
      0011B9 E6               [12] 3480 	mov	a,@r0
      0011BA 09               [12] 3481 	inc	r1
      0011BB F7               [12] 3482 	mov	@r1,a
      0011BC 08               [12] 3483 	inc	r0
      0011BD E6               [12] 3484 	mov	a,@r0
      0011BE 09               [12] 3485 	inc	r1
      0011BF F7               [12] 3486 	mov	@r1,a
      0011C0 08               [12] 3487 	inc	r0
      0011C1 E6               [12] 3488 	mov	a,@r0
      0011C2 09               [12] 3489 	inc	r1
      0011C3 F7               [12] 3490 	mov	@r1,a
      0011C4 E5 1D            [12] 3491 	mov	a,_bp
      0011C6 24 1C            [12] 3492 	add	a,#0x1c
      0011C8 F8               [12] 3493 	mov	r0,a
      0011C9 E5 1D            [12] 3494 	mov	a,_bp
      0011CB 24 04            [12] 3495 	add	a,#0x04
      0011CD F9               [12] 3496 	mov	r1,a
      0011CE E6               [12] 3497 	mov	a,@r0
      0011CF F7               [12] 3498 	mov	@r1,a
      0011D0 08               [12] 3499 	inc	r0
      0011D1 E6               [12] 3500 	mov	a,@r0
      0011D2 09               [12] 3501 	inc	r1
      0011D3 F7               [12] 3502 	mov	@r1,a
      0011D4 08               [12] 3503 	inc	r0
      0011D5 E6               [12] 3504 	mov	a,@r0
      0011D6 09               [12] 3505 	inc	r1
      0011D7 F7               [12] 3506 	mov	@r1,a
      0011D8 08               [12] 3507 	inc	r0
      0011D9 E6               [12] 3508 	mov	a,@r0
      0011DA 09               [12] 3509 	inc	r1
      0011DB F7               [12] 3510 	mov	@r1,a
      0011DC                       3511 00118$:
      0011DC C0 05            [24] 3512 	push	ar5
      0011DE C0 04            [24] 3513 	push	ar4
      0011E0 E5 1D            [12] 3514 	mov	a,_bp
      0011E2 24 04            [12] 3515 	add	a,#0x04
      0011E4 F8               [12] 3516 	mov	r0,a
      0011E5 E6               [12] 3517 	mov	a,@r0
      0011E6 C0 E0            [24] 3518 	push	acc
      0011E8 08               [12] 3519 	inc	r0
      0011E9 E6               [12] 3520 	mov	a,@r0
      0011EA C0 E0            [24] 3521 	push	acc
      0011EC 08               [12] 3522 	inc	r0
      0011ED E6               [12] 3523 	mov	a,@r0
      0011EE C0 E0            [24] 3524 	push	acc
      0011F0 08               [12] 3525 	inc	r0
      0011F1 E6               [12] 3526 	mov	a,@r0
      0011F2 C0 E0            [24] 3527 	push	acc
      0011F4 E5 1D            [12] 3528 	mov	a,_bp
      0011F6 24 F6            [12] 3529 	add	a,#0xf6
      0011F8 F8               [12] 3530 	mov	r0,a
      0011F9 86 82            [24] 3531 	mov	dpl, @r0
      0011FB 08               [12] 3532 	inc	r0
      0011FC 86 83            [24] 3533 	mov	dph, @r0
      0011FE 08               [12] 3534 	inc	r0
      0011FF 86 F0            [24] 3535 	mov	b, @r0
      001201 08               [12] 3536 	inc	r0
      001202 E6               [12] 3537 	mov	a, @r0
      001203 12 1A 32         [24] 3538 	lcall	___fslt
      001206 E5 81            [12] 3539 	mov	a,sp
      001208 24 FC            [12] 3540 	add	a,#0xfc
      00120A F5 81            [12] 3541 	mov	sp,a
      00120C D0 04            [24] 3542 	pop	ar4
      00120E D0 05            [24] 3543 	pop	ar5
      001210 E5 82            [12] 3544 	mov	a, dpl
      001212 24 FF            [12] 3545 	add	a,#0xff
      001214 92 00            [24] 3546 	mov	b0,c
      001216 50 03            [24] 3547 	jnc	00211$
      001218 02 14 73         [24] 3548 	ljmp	00110$
      00121B                       3549 00211$:
      00121B C0 05            [24] 3550 	push	ar5
      00121D C0 04            [24] 3551 	push	ar4
      00121F E5 1D            [12] 3552 	mov	a,_bp
      001221 24 04            [12] 3553 	add	a,#0x04
      001223 F8               [12] 3554 	mov	r0,a
      001224 E6               [12] 3555 	mov	a,@r0
      001225 C0 E0            [24] 3556 	push	acc
      001227 08               [12] 3557 	inc	r0
      001228 E6               [12] 3558 	mov	a,@r0
      001229 C0 E0            [24] 3559 	push	acc
      00122B 08               [12] 3560 	inc	r0
      00122C E6               [12] 3561 	mov	a,@r0
      00122D C0 E0            [24] 3562 	push	acc
      00122F 08               [12] 3563 	inc	r0
      001230 E6               [12] 3564 	mov	a,@r0
      001231 C0 E0            [24] 3565 	push	acc
      001233 A8 1D            [24] 3566 	mov	r0,_bp
      001235 08               [12] 3567 	inc	r0
      001236 86 82            [24] 3568 	mov	dpl, @r0
      001238 08               [12] 3569 	inc	r0
      001239 86 83            [24] 3570 	mov	dph, @r0
      00123B 08               [12] 3571 	inc	r0
      00123C 86 F0            [24] 3572 	mov	b, @r0
      00123E 12 0F 1B         [24] 3573 	lcall	_fuzzy_8051_height
      001241 C8               [12] 3574 	xch	a,r0
      001242 E5 1D            [12] 3575 	mov	a,_bp
      001244 24 08            [12] 3576 	add	a,#0x08
      001246 C8               [12] 3577 	xch	a,r0
      001247 A6 82            [24] 3578 	mov	@r0, dpl
      001249 08               [12] 3579 	inc	r0
      00124A A6 83            [24] 3580 	mov	@r0, dph
      00124C 08               [12] 3581 	inc	r0
      00124D A6 F0            [24] 3582 	mov	@r0, b
      00124F 08               [12] 3583 	inc	r0
      001250 F6               [12] 3584 	mov	@r0,a
      001251 E5 81            [12] 3585 	mov	a,sp
      001253 24 FC            [12] 3586 	add	a,#0xfc
      001255 F5 81            [12] 3587 	mov	sp,a
      001257 E5 1D            [12] 3588 	mov	a,_bp
      001259 24 08            [12] 3589 	add	a,#0x08
      00125B F8               [12] 3590 	mov	r0,a
      00125C E6               [12] 3591 	mov	a,@r0
      00125D C0 E0            [24] 3592 	push	acc
      00125F 08               [12] 3593 	inc	r0
      001260 E6               [12] 3594 	mov	a,@r0
      001261 C0 E0            [24] 3595 	push	acc
      001263 08               [12] 3596 	inc	r0
      001264 E6               [12] 3597 	mov	a,@r0
      001265 C0 E0            [24] 3598 	push	acc
      001267 08               [12] 3599 	inc	r0
      001268 E6               [12] 3600 	mov	a,@r0
      001269 C0 E0            [24] 3601 	push	acc
      00126B E5 1D            [12] 3602 	mov	a,_bp
      00126D 24 04            [12] 3603 	add	a,#0x04
      00126F F8               [12] 3604 	mov	r0,a
      001270 86 82            [24] 3605 	mov	dpl, @r0
      001272 08               [12] 3606 	inc	r0
      001273 86 83            [24] 3607 	mov	dph, @r0
      001275 08               [12] 3608 	inc	r0
      001276 86 F0            [24] 3609 	mov	b, @r0
      001278 08               [12] 3610 	inc	r0
      001279 E6               [12] 3611 	mov	a, @r0
      00127A 12 19 02         [24] 3612 	lcall	___fsmul
      00127D AA 82            [24] 3613 	mov	r2, dpl
      00127F AB 83            [24] 3614 	mov	r3, dph
      001281 AE F0            [24] 3615 	mov	r6, b
      001283 FF               [12] 3616 	mov	r7, a
      001284 E5 81            [12] 3617 	mov	a,sp
      001286 24 FC            [12] 3618 	add	a,#0xfc
      001288 F5 81            [12] 3619 	mov	sp,a
      00128A C0 02            [24] 3620 	push	ar2
      00128C C0 03            [24] 3621 	push	ar3
      00128E C0 06            [24] 3622 	push	ar6
      001290 C0 07            [24] 3623 	push	ar7
      001292 E5 1D            [12] 3624 	mov	a,_bp
      001294 24 0C            [12] 3625 	add	a,#0x0c
      001296 F8               [12] 3626 	mov	r0,a
      001297 86 82            [24] 3627 	mov	dpl, @r0
      001299 08               [12] 3628 	inc	r0
      00129A 86 83            [24] 3629 	mov	dph, @r0
      00129C 08               [12] 3630 	inc	r0
      00129D 86 F0            [24] 3631 	mov	b, @r0
      00129F 08               [12] 3632 	inc	r0
      0012A0 E6               [12] 3633 	mov	a, @r0
      0012A1 12 1A 62         [24] 3634 	lcall	___fsadd
      0012A4 C8               [12] 3635 	xch	a,r0
      0012A5 E5 1D            [12] 3636 	mov	a,_bp
      0012A7 24 0C            [12] 3637 	add	a,#0x0c
      0012A9 C8               [12] 3638 	xch	a,r0
      0012AA A6 82            [24] 3639 	mov	@r0, dpl
      0012AC 08               [12] 3640 	inc	r0
      0012AD A6 83            [24] 3641 	mov	@r0, dph
      0012AF 08               [12] 3642 	inc	r0
      0012B0 A6 F0            [24] 3643 	mov	@r0, b
      0012B2 08               [12] 3644 	inc	r0
      0012B3 F6               [12] 3645 	mov	@r0,a
      0012B4 E5 81            [12] 3646 	mov	a,sp
      0012B6 24 FC            [12] 3647 	add	a,#0xfc
      0012B8 F5 81            [12] 3648 	mov	sp,a
      0012BA E5 1D            [12] 3649 	mov	a,_bp
      0012BC 24 08            [12] 3650 	add	a,#0x08
      0012BE F8               [12] 3651 	mov	r0,a
      0012BF E6               [12] 3652 	mov	a,@r0
      0012C0 C0 E0            [24] 3653 	push	acc
      0012C2 08               [12] 3654 	inc	r0
      0012C3 E6               [12] 3655 	mov	a,@r0
      0012C4 C0 E0            [24] 3656 	push	acc
      0012C6 08               [12] 3657 	inc	r0
      0012C7 E6               [12] 3658 	mov	a,@r0
      0012C8 C0 E0            [24] 3659 	push	acc
      0012CA 08               [12] 3660 	inc	r0
      0012CB E6               [12] 3661 	mov	a,@r0
      0012CC C0 E0            [24] 3662 	push	acc
      0012CE E5 1D            [12] 3663 	mov	a,_bp
      0012D0 24 10            [12] 3664 	add	a,#0x10
      0012D2 F8               [12] 3665 	mov	r0,a
      0012D3 86 82            [24] 3666 	mov	dpl, @r0
      0012D5 08               [12] 3667 	inc	r0
      0012D6 86 83            [24] 3668 	mov	dph, @r0
      0012D8 08               [12] 3669 	inc	r0
      0012D9 86 F0            [24] 3670 	mov	b, @r0
      0012DB 08               [12] 3671 	inc	r0
      0012DC E6               [12] 3672 	mov	a, @r0
      0012DD 12 1A 62         [24] 3673 	lcall	___fsadd
      0012E0 C8               [12] 3674 	xch	a,r0
      0012E1 E5 1D            [12] 3675 	mov	a,_bp
      0012E3 24 10            [12] 3676 	add	a,#0x10
      0012E5 C8               [12] 3677 	xch	a,r0
      0012E6 A6 82            [24] 3678 	mov	@r0, dpl
      0012E8 08               [12] 3679 	inc	r0
      0012E9 A6 83            [24] 3680 	mov	@r0, dph
      0012EB 08               [12] 3681 	inc	r0
      0012EC A6 F0            [24] 3682 	mov	@r0, b
      0012EE 08               [12] 3683 	inc	r0
      0012EF F6               [12] 3684 	mov	@r0,a
      0012F0 E5 81            [12] 3685 	mov	a,sp
      0012F2 24 FC            [12] 3686 	add	a,#0xfc
      0012F4 F5 81            [12] 3687 	mov	sp,a
      0012F6 E5 1D            [12] 3688 	mov	a,_bp
      0012F8 24 08            [12] 3689 	add	a,#0x08
      0012FA F8               [12] 3690 	mov	r0,a
      0012FB E6               [12] 3691 	mov	a,@r0
      0012FC C0 E0            [24] 3692 	push	acc
      0012FE 08               [12] 3693 	inc	r0
      0012FF E6               [12] 3694 	mov	a,@r0
      001300 C0 E0            [24] 3695 	push	acc
      001302 08               [12] 3696 	inc	r0
      001303 E6               [12] 3697 	mov	a,@r0
      001304 C0 E0            [24] 3698 	push	acc
      001306 08               [12] 3699 	inc	r0
      001307 E6               [12] 3700 	mov	a,@r0
      001308 C0 E0            [24] 3701 	push	acc
      00130A E5 1D            [12] 3702 	mov	a,_bp
      00130C 24 14            [12] 3703 	add	a,#0x14
      00130E F8               [12] 3704 	mov	r0,a
      00130F 86 82            [24] 3705 	mov	dpl, @r0
      001311 08               [12] 3706 	inc	r0
      001312 86 83            [24] 3707 	mov	dph, @r0
      001314 08               [12] 3708 	inc	r0
      001315 86 F0            [24] 3709 	mov	b, @r0
      001317 08               [12] 3710 	inc	r0
      001318 E6               [12] 3711 	mov	a, @r0
      001319 12 1A 32         [24] 3712 	lcall	___fslt
      00131C AF 82            [24] 3713 	mov	r7, dpl
      00131E E5 81            [12] 3714 	mov	a,sp
      001320 24 FC            [12] 3715 	add	a,#0xfc
      001322 F5 81            [12] 3716 	mov	sp,a
      001324 D0 04            [24] 3717 	pop	ar4
      001326 D0 05            [24] 3718 	pop	ar5
      001328 EF               [12] 3719 	mov	a,r7
      001329 60 67            [24] 3720 	jz	00108$
      00132B E5 1D            [12] 3721 	mov	a,_bp
      00132D 24 08            [12] 3722 	add	a,#0x08
      00132F F8               [12] 3723 	mov	r0,a
      001330 E5 1D            [12] 3724 	mov	a,_bp
      001332 24 14            [12] 3725 	add	a,#0x14
      001334 F9               [12] 3726 	mov	r1,a
      001335 E6               [12] 3727 	mov	a,@r0
      001336 F7               [12] 3728 	mov	@r1,a
      001337 08               [12] 3729 	inc	r0
      001338 E6               [12] 3730 	mov	a,@r0
      001339 09               [12] 3731 	inc	r1
      00133A F7               [12] 3732 	mov	@r1,a
      00133B 08               [12] 3733 	inc	r0
      00133C E6               [12] 3734 	mov	a,@r0
      00133D 09               [12] 3735 	inc	r1
      00133E F7               [12] 3736 	mov	@r1,a
      00133F 08               [12] 3737 	inc	r0
      001340 E6               [12] 3738 	mov	a,@r0
      001341 09               [12] 3739 	inc	r1
      001342 F7               [12] 3740 	mov	@r1,a
      001343 E5 1D            [12] 3741 	mov	a,_bp
      001345 24 04            [12] 3742 	add	a,#0x04
      001347 F8               [12] 3743 	mov	r0,a
      001348 E5 1D            [12] 3744 	mov	a,_bp
      00134A 24 18            [12] 3745 	add	a,#0x18
      00134C F9               [12] 3746 	mov	r1,a
      00134D E6               [12] 3747 	mov	a,@r0
      00134E F7               [12] 3748 	mov	@r1,a
      00134F 08               [12] 3749 	inc	r0
      001350 E6               [12] 3750 	mov	a,@r0
      001351 09               [12] 3751 	inc	r1
      001352 F7               [12] 3752 	mov	@r1,a
      001353 08               [12] 3753 	inc	r0
      001354 E6               [12] 3754 	mov	a,@r0
      001355 09               [12] 3755 	inc	r1
      001356 F7               [12] 3756 	mov	@r1,a
      001357 08               [12] 3757 	inc	r0
      001358 E6               [12] 3758 	mov	a,@r0
      001359 09               [12] 3759 	inc	r1
      00135A F7               [12] 3760 	mov	@r1,a
      00135B 7D 01            [12] 3761 	mov	r5,#0x01
      00135D 7C 00            [12] 3762 	mov	r4,#0x00
      00135F E5 1D            [12] 3763 	mov	a,_bp
      001361 24 04            [12] 3764 	add	a,#0x04
      001363 F8               [12] 3765 	mov	r0,a
      001364 E5 1D            [12] 3766 	mov	a,_bp
      001366 24 1C            [12] 3767 	add	a,#0x1c
      001368 F9               [12] 3768 	mov	r1,a
      001369 E6               [12] 3769 	mov	a,@r0
      00136A F7               [12] 3770 	mov	@r1,a
      00136B 08               [12] 3771 	inc	r0
      00136C E6               [12] 3772 	mov	a,@r0
      00136D 09               [12] 3773 	inc	r1
      00136E F7               [12] 3774 	mov	@r1,a
      00136F 08               [12] 3775 	inc	r0
      001370 E6               [12] 3776 	mov	a,@r0
      001371 09               [12] 3777 	inc	r1
      001372 F7               [12] 3778 	mov	@r1,a
      001373 08               [12] 3779 	inc	r0
      001374 E6               [12] 3780 	mov	a,@r0
      001375 09               [12] 3781 	inc	r1
      001376 F7               [12] 3782 	mov	@r1,a
      001377 E5 1D            [12] 3783 	mov	a,_bp
      001379 24 04            [12] 3784 	add	a,#0x04
      00137B F8               [12] 3785 	mov	r0,a
      00137C E5 1D            [12] 3786 	mov	a,_bp
      00137E 24 20            [12] 3787 	add	a,#0x20
      001380 F9               [12] 3788 	mov	r1,a
      001381 E6               [12] 3789 	mov	a,@r0
      001382 F7               [12] 3790 	mov	@r1,a
      001383 08               [12] 3791 	inc	r0
      001384 E6               [12] 3792 	mov	a,@r0
      001385 09               [12] 3793 	inc	r1
      001386 F7               [12] 3794 	mov	@r1,a
      001387 08               [12] 3795 	inc	r0
      001388 E6               [12] 3796 	mov	a,@r0
      001389 09               [12] 3797 	inc	r1
      00138A F7               [12] 3798 	mov	@r1,a
      00138B 08               [12] 3799 	inc	r0
      00138C E6               [12] 3800 	mov	a,@r0
      00138D 09               [12] 3801 	inc	r1
      00138E F7               [12] 3802 	mov	@r1,a
      00138F 02 14 2C         [24] 3803 	ljmp	00119$
      001392                       3804 00108$:
      001392 C0 05            [24] 3805 	push	ar5
      001394 C0 04            [24] 3806 	push	ar4
      001396 E5 1D            [12] 3807 	mov	a,_bp
      001398 24 14            [12] 3808 	add	a,#0x14
      00139A F8               [12] 3809 	mov	r0,a
      00139B E6               [12] 3810 	mov	a,@r0
      00139C C0 E0            [24] 3811 	push	acc
      00139E 08               [12] 3812 	inc	r0
      00139F E6               [12] 3813 	mov	a,@r0
      0013A0 C0 E0            [24] 3814 	push	acc
      0013A2 08               [12] 3815 	inc	r0
      0013A3 E6               [12] 3816 	mov	a,@r0
      0013A4 C0 E0            [24] 3817 	push	acc
      0013A6 08               [12] 3818 	inc	r0
      0013A7 E6               [12] 3819 	mov	a,@r0
      0013A8 C0 E0            [24] 3820 	push	acc
      0013AA E5 1D            [12] 3821 	mov	a,_bp
      0013AC 24 08            [12] 3822 	add	a,#0x08
      0013AE F8               [12] 3823 	mov	r0,a
      0013AF 86 82            [24] 3824 	mov	dpl, @r0
      0013B1 08               [12] 3825 	inc	r0
      0013B2 86 83            [24] 3826 	mov	dph, @r0
      0013B4 08               [12] 3827 	inc	r0
      0013B5 86 F0            [24] 3828 	mov	b, @r0
      0013B7 08               [12] 3829 	inc	r0
      0013B8 E6               [12] 3830 	mov	a, @r0
      0013B9 12 1A 06         [24] 3831 	lcall	___fseq
      0013BC AF 82            [24] 3832 	mov	r7, dpl
      0013BE E5 81            [12] 3833 	mov	a,sp
      0013C0 24 FC            [12] 3834 	add	a,#0xfc
      0013C2 F5 81            [12] 3835 	mov	sp,a
      0013C4 D0 04            [24] 3836 	pop	ar4
      0013C6 D0 05            [24] 3837 	pop	ar5
      0013C8 EF               [12] 3838 	mov	a,r7
      0013C9 60 61            [24] 3839 	jz	00119$
      0013CB C0 05            [24] 3840 	push	ar5
      0013CD C0 04            [24] 3841 	push	ar4
      0013CF E5 1D            [12] 3842 	mov	a,_bp
      0013D1 24 04            [12] 3843 	add	a,#0x04
      0013D3 F8               [12] 3844 	mov	r0,a
      0013D4 E6               [12] 3845 	mov	a,@r0
      0013D5 C0 E0            [24] 3846 	push	acc
      0013D7 08               [12] 3847 	inc	r0
      0013D8 E6               [12] 3848 	mov	a,@r0
      0013D9 C0 E0            [24] 3849 	push	acc
      0013DB 08               [12] 3850 	inc	r0
      0013DC E6               [12] 3851 	mov	a,@r0
      0013DD C0 E0            [24] 3852 	push	acc
      0013DF 08               [12] 3853 	inc	r0
      0013E0 E6               [12] 3854 	mov	a,@r0
      0013E1 C0 E0            [24] 3855 	push	acc
      0013E3 E5 1D            [12] 3856 	mov	a,_bp
      0013E5 24 18            [12] 3857 	add	a,#0x18
      0013E7 F8               [12] 3858 	mov	r0,a
      0013E8 86 82            [24] 3859 	mov	dpl, @r0
      0013EA 08               [12] 3860 	inc	r0
      0013EB 86 83            [24] 3861 	mov	dph, @r0
      0013ED 08               [12] 3862 	inc	r0
      0013EE 86 F0            [24] 3863 	mov	b, @r0
      0013F0 08               [12] 3864 	inc	r0
      0013F1 E6               [12] 3865 	mov	a, @r0
      0013F2 12 1A 62         [24] 3866 	lcall	___fsadd
      0013F5 C8               [12] 3867 	xch	a,r0
      0013F6 E5 1D            [12] 3868 	mov	a,_bp
      0013F8 24 18            [12] 3869 	add	a,#0x18
      0013FA C8               [12] 3870 	xch	a,r0
      0013FB A6 82            [24] 3871 	mov	@r0, dpl
      0013FD 08               [12] 3872 	inc	r0
      0013FE A6 83            [24] 3873 	mov	@r0, dph
      001400 08               [12] 3874 	inc	r0
      001401 A6 F0            [24] 3875 	mov	@r0, b
      001403 08               [12] 3876 	inc	r0
      001404 F6               [12] 3877 	mov	@r0,a
      001405 E5 81            [12] 3878 	mov	a,sp
      001407 24 FC            [12] 3879 	add	a,#0xfc
      001409 F5 81            [12] 3880 	mov	sp,a
      00140B D0 04            [24] 3881 	pop	ar4
      00140D D0 05            [24] 3882 	pop	ar5
      00140F 0D               [12] 3883 	inc	r5
      001410 BD 00 01         [24] 3884 	cjne	r5,#0x00,00214$
      001413 0C               [12] 3885 	inc	r4
      001414                       3886 00214$:
      001414 E5 1D            [12] 3887 	mov	a,_bp
      001416 24 04            [12] 3888 	add	a,#0x04
      001418 F8               [12] 3889 	mov	r0,a
      001419 E5 1D            [12] 3890 	mov	a,_bp
      00141B 24 20            [12] 3891 	add	a,#0x20
      00141D F9               [12] 3892 	mov	r1,a
      00141E E6               [12] 3893 	mov	a,@r0
      00141F F7               [12] 3894 	mov	@r1,a
      001420 08               [12] 3895 	inc	r0
      001421 E6               [12] 3896 	mov	a,@r0
      001422 09               [12] 3897 	inc	r1
      001423 F7               [12] 3898 	mov	@r1,a
      001424 08               [12] 3899 	inc	r0
      001425 E6               [12] 3900 	mov	a,@r0
      001426 09               [12] 3901 	inc	r1
      001427 F7               [12] 3902 	mov	@r1,a
      001428 08               [12] 3903 	inc	r0
      001429 E6               [12] 3904 	mov	a,@r0
      00142A 09               [12] 3905 	inc	r1
      00142B F7               [12] 3906 	mov	@r1,a
      00142C                       3907 00119$:
      00142C C0 05            [24] 3908 	push	ar5
      00142E C0 04            [24] 3909 	push	ar4
      001430 E5 1D            [12] 3910 	mov	a,_bp
      001432 24 F2            [12] 3911 	add	a,#0xf2
      001434 F8               [12] 3912 	mov	r0,a
      001435 E6               [12] 3913 	mov	a,@r0
      001436 C0 E0            [24] 3914 	push	acc
      001438 08               [12] 3915 	inc	r0
      001439 E6               [12] 3916 	mov	a,@r0
      00143A C0 E0            [24] 3917 	push	acc
      00143C 08               [12] 3918 	inc	r0
      00143D E6               [12] 3919 	mov	a,@r0
      00143E C0 E0            [24] 3920 	push	acc
      001440 08               [12] 3921 	inc	r0
      001441 E6               [12] 3922 	mov	a,@r0
      001442 C0 E0            [24] 3923 	push	acc
      001444 E5 1D            [12] 3924 	mov	a,_bp
      001446 24 04            [12] 3925 	add	a,#0x04
      001448 F8               [12] 3926 	mov	r0,a
      001449 86 82            [24] 3927 	mov	dpl, @r0
      00144B 08               [12] 3928 	inc	r0
      00144C 86 83            [24] 3929 	mov	dph, @r0
      00144E 08               [12] 3930 	inc	r0
      00144F 86 F0            [24] 3931 	mov	b, @r0
      001451 08               [12] 3932 	inc	r0
      001452 E6               [12] 3933 	mov	a, @r0
      001453 12 1A 62         [24] 3934 	lcall	___fsadd
      001456 C8               [12] 3935 	xch	a,r0
      001457 E5 1D            [12] 3936 	mov	a,_bp
      001459 24 04            [12] 3937 	add	a,#0x04
      00145B C8               [12] 3938 	xch	a,r0
      00145C A6 82            [24] 3939 	mov	@r0, dpl
      00145E 08               [12] 3940 	inc	r0
      00145F A6 83            [24] 3941 	mov	@r0, dph
      001461 08               [12] 3942 	inc	r0
      001462 A6 F0            [24] 3943 	mov	@r0, b
      001464 08               [12] 3944 	inc	r0
      001465 F6               [12] 3945 	mov	@r0,a
      001466 E5 81            [12] 3946 	mov	a,sp
      001468 24 FC            [12] 3947 	add	a,#0xfc
      00146A F5 81            [12] 3948 	mov	sp,a
      00146C D0 04            [24] 3949 	pop	ar4
      00146E D0 05            [24] 3950 	pop	ar5
      001470 02 11 DC         [24] 3951 	ljmp	00118$
      001473                       3952 00110$:
      001473 E5 1D            [12] 3953 	mov	a,_bp
      001475 24 F1            [12] 3954 	add	a,#0xf1
      001477 F8               [12] 3955 	mov	r0,a
      001478 B6 03 02         [24] 3956 	cjne	@r0,#0x03,00215$
      00147B 80 02            [24] 3957 	sjmp	00216$
      00147D                       3958 00215$:
      00147D 80 79            [24] 3959 	sjmp	00112$
      00147F                       3960 00216$:
      00147F C0 05            [24] 3961 	push	ar5
      001481 C0 04            [24] 3962 	push	ar4
      001483 E5 1D            [12] 3963 	mov	a,_bp
      001485 24 14            [12] 3964 	add	a,#0x14
      001487 F8               [12] 3965 	mov	r0,a
      001488 E6               [12] 3966 	mov	a,@r0
      001489 C0 E0            [24] 3967 	push	acc
      00148B 08               [12] 3968 	inc	r0
      00148C E6               [12] 3969 	mov	a,@r0
      00148D C0 E0            [24] 3970 	push	acc
      00148F 08               [12] 3971 	inc	r0
      001490 E6               [12] 3972 	mov	a,@r0
      001491 C0 E0            [24] 3973 	push	acc
      001493 08               [12] 3974 	inc	r0
      001494 E6               [12] 3975 	mov	a,@r0
      001495 C0 E0            [24] 3976 	push	acc
      001497 90 00 00         [24] 3977 	mov	dptr,#0x0000
      00149A E4               [12] 3978 	clr	a
      00149B F5 F0            [12] 3979 	mov	b,a
      00149D 12 1A 32         [24] 3980 	lcall	___fslt
      0014A0 AF 82            [24] 3981 	mov	r7, dpl
      0014A2 E5 81            [12] 3982 	mov	a,sp
      0014A4 24 FC            [12] 3983 	add	a,#0xfc
      0014A6 F5 81            [12] 3984 	mov	sp,a
      0014A8 D0 04            [24] 3985 	pop	ar4
      0014AA D0 05            [24] 3986 	pop	ar5
      0014AC EF               [12] 3987 	mov	a,r7
      0014AD 60 37            [24] 3988 	jz	00122$
      0014AF 8D 82            [24] 3989 	mov	dpl, r5
      0014B1 8C 83            [24] 3990 	mov	dph, r4
      0014B3 12 1B 04         [24] 3991 	lcall	___uint2fs
      0014B6 AC 82            [24] 3992 	mov	r4, dpl
      0014B8 AD 83            [24] 3993 	mov	r5, dph
      0014BA AE F0            [24] 3994 	mov	r6, b
      0014BC FF               [12] 3995 	mov	r7, a
      0014BD C0 04            [24] 3996 	push	ar4
      0014BF C0 05            [24] 3997 	push	ar5
      0014C1 C0 06            [24] 3998 	push	ar6
      0014C3 C0 07            [24] 3999 	push	ar7
      0014C5 E5 1D            [12] 4000 	mov	a,_bp
      0014C7 24 18            [12] 4001 	add	a,#0x18
      0014C9 F8               [12] 4002 	mov	r0,a
      0014CA 86 82            [24] 4003 	mov	dpl, @r0
      0014CC 08               [12] 4004 	inc	r0
      0014CD 86 83            [24] 4005 	mov	dph, @r0
      0014CF 08               [12] 4006 	inc	r0
      0014D0 86 F0            [24] 4007 	mov	b, @r0
      0014D2 08               [12] 4008 	inc	r0
      0014D3 E6               [12] 4009 	mov	a, @r0
      0014D4 12 1B 79         [24] 4010 	lcall	___fsdiv
      0014D7 AC 82            [24] 4011 	mov	r4, dpl
      0014D9 AD 83            [24] 4012 	mov	r5, dph
      0014DB AE F0            [24] 4013 	mov	r6, b
      0014DD FF               [12] 4014 	mov	r7, a
      0014DE E5 81            [12] 4015 	mov	a,sp
      0014E0 24 FC            [12] 4016 	add	a,#0xfc
      0014E2 F5 81            [12] 4017 	mov	sp,a
      0014E4 80 08            [24] 4018 	sjmp	00123$
      0014E6                       4019 00122$:
      0014E6 7C 00            [12] 4020 	mov	r4,#0x00
      0014E8 7D 00            [12] 4021 	mov	r5,#0x00
      0014EA 7E 00            [12] 4022 	mov	r6,#0x00
      0014EC 7F 00            [12] 4023 	mov	r7,#0x00
      0014EE                       4024 00123$:
      0014EE 8C 82            [24] 4025 	mov	dpl, r4
      0014F0 8D 83            [24] 4026 	mov	dph, r5
      0014F2 8E F0            [24] 4027 	mov	b, r6
      0014F4 EF               [12] 4028 	mov	a, r7
      0014F5 02 16 0B         [24] 4029 	ljmp	00120$
      0014F8                       4030 00112$:
      0014F8 E5 1D            [12] 4031 	mov	a,_bp
      0014FA 24 F1            [12] 4032 	add	a,#0xf1
      0014FC F8               [12] 4033 	mov	r0,a
      0014FD B6 04 4C         [24] 4034 	cjne	@r0,#0x04,00114$
      001500 E5 1D            [12] 4035 	mov	a,_bp
      001502 24 14            [12] 4036 	add	a,#0x14
      001504 F8               [12] 4037 	mov	r0,a
      001505 E6               [12] 4038 	mov	a,@r0
      001506 C0 E0            [24] 4039 	push	acc
      001508 08               [12] 4040 	inc	r0
      001509 E6               [12] 4041 	mov	a,@r0
      00150A C0 E0            [24] 4042 	push	acc
      00150C 08               [12] 4043 	inc	r0
      00150D E6               [12] 4044 	mov	a,@r0
      00150E C0 E0            [24] 4045 	push	acc
      001510 08               [12] 4046 	inc	r0
      001511 E6               [12] 4047 	mov	a,@r0
      001512 C0 E0            [24] 4048 	push	acc
      001514 90 00 00         [24] 4049 	mov	dptr,#0x0000
      001517 E4               [12] 4050 	clr	a
      001518 F5 F0            [12] 4051 	mov	b,a
      00151A 12 1A 32         [24] 4052 	lcall	___fslt
      00151D AF 82            [24] 4053 	mov	r7, dpl
      00151F E5 81            [12] 4054 	mov	a,sp
      001521 24 FC            [12] 4055 	add	a,#0xfc
      001523 F5 81            [12] 4056 	mov	sp,a
      001525 EF               [12] 4057 	mov	a,r7
      001526 60 12            [24] 4058 	jz	00124$
      001528 E5 1D            [12] 4059 	mov	a,_bp
      00152A 24 1C            [12] 4060 	add	a,#0x1c
      00152C F8               [12] 4061 	mov	r0,a
      00152D 86 04            [24] 4062 	mov	ar4,@r0
      00152F 08               [12] 4063 	inc	r0
      001530 86 05            [24] 4064 	mov	ar5,@r0
      001532 08               [12] 4065 	inc	r0
      001533 86 06            [24] 4066 	mov	ar6,@r0
      001535 08               [12] 4067 	inc	r0
      001536 86 07            [24] 4068 	mov	ar7,@r0
      001538 80 08            [24] 4069 	sjmp	00125$
      00153A                       4070 00124$:
      00153A 7C 00            [12] 4071 	mov	r4,#0x00
      00153C 7D 00            [12] 4072 	mov	r5,#0x00
      00153E 7E 00            [12] 4073 	mov	r6,#0x00
      001540 7F 00            [12] 4074 	mov	r7,#0x00
      001542                       4075 00125$:
      001542 8C 82            [24] 4076 	mov	dpl, r4
      001544 8D 83            [24] 4077 	mov	dph, r5
      001546 8E F0            [24] 4078 	mov	b, r6
      001548 EF               [12] 4079 	mov	a, r7
      001549 02 16 0B         [24] 4080 	ljmp	00120$
      00154C                       4081 00114$:
      00154C E5 1D            [12] 4082 	mov	a,_bp
      00154E 24 F1            [12] 4083 	add	a,#0xf1
      001550 F8               [12] 4084 	mov	r0,a
      001551 B6 05 4B         [24] 4085 	cjne	@r0,#0x05,00116$
      001554 E5 1D            [12] 4086 	mov	a,_bp
      001556 24 14            [12] 4087 	add	a,#0x14
      001558 F8               [12] 4088 	mov	r0,a
      001559 E6               [12] 4089 	mov	a,@r0
      00155A C0 E0            [24] 4090 	push	acc
      00155C 08               [12] 4091 	inc	r0
      00155D E6               [12] 4092 	mov	a,@r0
      00155E C0 E0            [24] 4093 	push	acc
      001560 08               [12] 4094 	inc	r0
      001561 E6               [12] 4095 	mov	a,@r0
      001562 C0 E0            [24] 4096 	push	acc
      001564 08               [12] 4097 	inc	r0
      001565 E6               [12] 4098 	mov	a,@r0
      001566 C0 E0            [24] 4099 	push	acc
      001568 90 00 00         [24] 4100 	mov	dptr,#0x0000
      00156B E4               [12] 4101 	clr	a
      00156C F5 F0            [12] 4102 	mov	b,a
      00156E 12 1A 32         [24] 4103 	lcall	___fslt
      001571 AF 82            [24] 4104 	mov	r7, dpl
      001573 E5 81            [12] 4105 	mov	a,sp
      001575 24 FC            [12] 4106 	add	a,#0xfc
      001577 F5 81            [12] 4107 	mov	sp,a
      001579 EF               [12] 4108 	mov	a,r7
      00157A 60 12            [24] 4109 	jz	00126$
      00157C E5 1D            [12] 4110 	mov	a,_bp
      00157E 24 20            [12] 4111 	add	a,#0x20
      001580 F8               [12] 4112 	mov	r0,a
      001581 86 04            [24] 4113 	mov	ar4,@r0
      001583 08               [12] 4114 	inc	r0
      001584 86 05            [24] 4115 	mov	ar5,@r0
      001586 08               [12] 4116 	inc	r0
      001587 86 06            [24] 4117 	mov	ar6,@r0
      001589 08               [12] 4118 	inc	r0
      00158A 86 07            [24] 4119 	mov	ar7,@r0
      00158C 80 08            [24] 4120 	sjmp	00127$
      00158E                       4121 00126$:
      00158E 7C 00            [12] 4122 	mov	r4,#0x00
      001590 7D 00            [12] 4123 	mov	r5,#0x00
      001592 7E 00            [12] 4124 	mov	r6,#0x00
      001594 7F 00            [12] 4125 	mov	r7,#0x00
      001596                       4126 00127$:
      001596 8C 82            [24] 4127 	mov	dpl, r4
      001598 8D 83            [24] 4128 	mov	dph, r5
      00159A 8E F0            [24] 4129 	mov	b, r6
      00159C EF               [12] 4130 	mov	a, r7
      00159D 80 6C            [24] 4131 	sjmp	00120$
      00159F                       4132 00116$:
      00159F E5 1D            [12] 4133 	mov	a,_bp
      0015A1 24 10            [12] 4134 	add	a,#0x10
      0015A3 F8               [12] 4135 	mov	r0,a
      0015A4 E6               [12] 4136 	mov	a,@r0
      0015A5 C0 E0            [24] 4137 	push	acc
      0015A7 08               [12] 4138 	inc	r0
      0015A8 E6               [12] 4139 	mov	a,@r0
      0015A9 C0 E0            [24] 4140 	push	acc
      0015AB 08               [12] 4141 	inc	r0
      0015AC E6               [12] 4142 	mov	a,@r0
      0015AD C0 E0            [24] 4143 	push	acc
      0015AF 08               [12] 4144 	inc	r0
      0015B0 E6               [12] 4145 	mov	a,@r0
      0015B1 C0 E0            [24] 4146 	push	acc
      0015B3 90 00 00         [24] 4147 	mov	dptr,#0x0000
      0015B6 E4               [12] 4148 	clr	a
      0015B7 F5 F0            [12] 4149 	mov	b,a
      0015B9 12 1A 32         [24] 4150 	lcall	___fslt
      0015BC AF 82            [24] 4151 	mov	r7, dpl
      0015BE E5 81            [12] 4152 	mov	a,sp
      0015C0 24 FC            [12] 4153 	add	a,#0xfc
      0015C2 F5 81            [12] 4154 	mov	sp,a
      0015C4 EF               [12] 4155 	mov	a,r7
      0015C5 60 35            [24] 4156 	jz	00128$
      0015C7 E5 1D            [12] 4157 	mov	a,_bp
      0015C9 24 10            [12] 4158 	add	a,#0x10
      0015CB F8               [12] 4159 	mov	r0,a
      0015CC E6               [12] 4160 	mov	a,@r0
      0015CD C0 E0            [24] 4161 	push	acc
      0015CF 08               [12] 4162 	inc	r0
      0015D0 E6               [12] 4163 	mov	a,@r0
      0015D1 C0 E0            [24] 4164 	push	acc
      0015D3 08               [12] 4165 	inc	r0
      0015D4 E6               [12] 4166 	mov	a,@r0
      0015D5 C0 E0            [24] 4167 	push	acc
      0015D7 08               [12] 4168 	inc	r0
      0015D8 E6               [12] 4169 	mov	a,@r0
      0015D9 C0 E0            [24] 4170 	push	acc
      0015DB E5 1D            [12] 4171 	mov	a,_bp
      0015DD 24 0C            [12] 4172 	add	a,#0x0c
      0015DF F8               [12] 4173 	mov	r0,a
      0015E0 86 82            [24] 4174 	mov	dpl, @r0
      0015E2 08               [12] 4175 	inc	r0
      0015E3 86 83            [24] 4176 	mov	dph, @r0
      0015E5 08               [12] 4177 	inc	r0
      0015E6 86 F0            [24] 4178 	mov	b, @r0
      0015E8 08               [12] 4179 	inc	r0
      0015E9 E6               [12] 4180 	mov	a, @r0
      0015EA 12 1B 79         [24] 4181 	lcall	___fsdiv
      0015ED AC 82            [24] 4182 	mov	r4, dpl
      0015EF AD 83            [24] 4183 	mov	r5, dph
      0015F1 AE F0            [24] 4184 	mov	r6, b
      0015F3 FF               [12] 4185 	mov	r7, a
      0015F4 E5 81            [12] 4186 	mov	a,sp
      0015F6 24 FC            [12] 4187 	add	a,#0xfc
      0015F8 F5 81            [12] 4188 	mov	sp,a
      0015FA 80 08            [24] 4189 	sjmp	00129$
      0015FC                       4190 00128$:
      0015FC 7C 00            [12] 4191 	mov	r4,#0x00
      0015FE 7D 00            [12] 4192 	mov	r5,#0x00
      001600 7E 00            [12] 4193 	mov	r6,#0x00
      001602 7F 00            [12] 4194 	mov	r7,#0x00
      001604                       4195 00129$:
      001604 8C 82            [24] 4196 	mov	dpl, r4
      001606 8D 83            [24] 4197 	mov	dph, r5
      001608 8E F0            [24] 4198 	mov	b, r6
      00160A EF               [12] 4199 	mov	a, r7
      00160B                       4200 00120$:
      00160B 85 1D 81         [24] 4201 	mov	sp,_bp
      00160E D0 1D            [24] 4202 	pop	_bp
                           001559  4203 	C$fuzzy.h$63$1_0$33 ==.
                           001559  4204 	XG$fuzzy_rules_defuzzify$0$0 ==.
      001610 22               [24] 4205 	ret
                                   4206 ;------------------------------------------------------------
                                   4207 ;Allocation info for local variables in function 'fuzzy_rules_cog'
                                   4208 ;------------------------------------------------------------
                                   4209 ;lower         Allocated to stack - _bp -6 +4 
                                   4210 ;upper         Allocated to stack - _bp -10 +4 
                                   4211 ;step          Allocated to stack - _bp -14 +4 
                                   4212 ;rules         Allocated to registers r5 r6 r7 
                                   4213 ;------------------------------------------------------------
                           00155A  4214 	G$fuzzy_rules_cog$0$0 ==.
                           00155A  4215 	C$fuzzy.h$64$1_0$39 ==.
                                   4216 ;	../../fuzzy.h:64: float fuzzy_rules_cog(const fuzzy_rules_t *rules, float lower, float upper, float step) { return fuzzy_rules_defuzzify(rules, lower, upper, step, FUZZY_DEFUZZ_COG); }
                                   4217 ;	-----------------------------------------
                                   4218 ;	 function fuzzy_rules_cog
                                   4219 ;	-----------------------------------------
      001611                       4220 _fuzzy_rules_cog:
      001611 C0 1D            [24] 4221 	push	_bp
      001613 85 81 1D         [24] 4222 	mov	_bp,sp
      001616 AD 82            [24] 4223 	mov	r5, dpl
      001618 AE 83            [24] 4224 	mov	r6, dph
      00161A AF F0            [24] 4225 	mov	r7, b
      00161C E4               [12] 4226 	clr	a
      00161D C0 E0            [24] 4227 	push	acc
      00161F E5 1D            [12] 4228 	mov	a,_bp
      001621 24 F2            [12] 4229 	add	a,#0xf2
      001623 F8               [12] 4230 	mov	r0,a
      001624 E6               [12] 4231 	mov	a,@r0
      001625 C0 E0            [24] 4232 	push	acc
      001627 08               [12] 4233 	inc	r0
      001628 E6               [12] 4234 	mov	a,@r0
      001629 C0 E0            [24] 4235 	push	acc
      00162B 08               [12] 4236 	inc	r0
      00162C E6               [12] 4237 	mov	a,@r0
      00162D C0 E0            [24] 4238 	push	acc
      00162F 08               [12] 4239 	inc	r0
      001630 E6               [12] 4240 	mov	a,@r0
      001631 C0 E0            [24] 4241 	push	acc
      001633 E5 1D            [12] 4242 	mov	a,_bp
      001635 24 F6            [12] 4243 	add	a,#0xf6
      001637 F8               [12] 4244 	mov	r0,a
      001638 E6               [12] 4245 	mov	a,@r0
      001639 C0 E0            [24] 4246 	push	acc
      00163B 08               [12] 4247 	inc	r0
      00163C E6               [12] 4248 	mov	a,@r0
      00163D C0 E0            [24] 4249 	push	acc
      00163F 08               [12] 4250 	inc	r0
      001640 E6               [12] 4251 	mov	a,@r0
      001641 C0 E0            [24] 4252 	push	acc
      001643 08               [12] 4253 	inc	r0
      001644 E6               [12] 4254 	mov	a,@r0
      001645 C0 E0            [24] 4255 	push	acc
      001647 E5 1D            [12] 4256 	mov	a,_bp
      001649 24 FA            [12] 4257 	add	a,#0xfa
      00164B F8               [12] 4258 	mov	r0,a
      00164C E6               [12] 4259 	mov	a,@r0
      00164D C0 E0            [24] 4260 	push	acc
      00164F 08               [12] 4261 	inc	r0
      001650 E6               [12] 4262 	mov	a,@r0
      001651 C0 E0            [24] 4263 	push	acc
      001653 08               [12] 4264 	inc	r0
      001654 E6               [12] 4265 	mov	a,@r0
      001655 C0 E0            [24] 4266 	push	acc
      001657 08               [12] 4267 	inc	r0
      001658 E6               [12] 4268 	mov	a,@r0
      001659 C0 E0            [24] 4269 	push	acc
      00165B 8D 82            [24] 4270 	mov	dpl, r5
      00165D 8E 83            [24] 4271 	mov	dph, r6
      00165F 8F F0            [24] 4272 	mov	b, r7
      001661 12 10 CD         [24] 4273 	lcall	_fuzzy_rules_defuzzify
      001664 AC 82            [24] 4274 	mov	r4, dpl
      001666 AD 83            [24] 4275 	mov	r5, dph
      001668 AE F0            [24] 4276 	mov	r6, b
      00166A FF               [12] 4277 	mov	r7, a
      00166B E5 81            [12] 4278 	mov	a,sp
      00166D 24 F3            [12] 4279 	add	a,#0xf3
      00166F F5 81            [12] 4280 	mov	sp,a
      001671 8C 82            [24] 4281 	mov	dpl, r4
      001673 8D 83            [24] 4282 	mov	dph, r5
      001675 8E F0            [24] 4283 	mov	b, r6
      001677 EF               [12] 4284 	mov	a, r7
      001678 D0 1D            [24] 4285 	pop	_bp
                           0015C3  4286 	C$fuzzy.h$64$1_0$39 ==.
                           0015C3  4287 	XG$fuzzy_rules_cog$0$0 ==.
      00167A 22               [24] 4288 	ret
                                   4289 ;------------------------------------------------------------
                                   4290 ;Allocation info for local variables in function 'temperature_low'
                                   4291 ;------------------------------------------------------------
                                   4292 ;x             Allocated to registers r4 r5 r6 r7 
                                   4293 ;------------------------------------------------------------
                           0015C4  4294 	Fcontroller_8051$temperature_low$0$0 ==.
                           0015C4  4295 	C$controller_8051.c$30$1_0$41 ==.
                                   4296 ;	../../controller_8051.c:30: FUZZY_VAR(temperature_low,  FUZZY_SHAPE_RAMP, HEDGE_NONE, 20.0f, 40.0f, false)
                                   4297 ;	-----------------------------------------
                                   4298 ;	 function temperature_low
                                   4299 ;	-----------------------------------------
      00167B                       4300 _temperature_low:
      00167B AC 82            [24] 4301 	mov	r4,dpl
      00167D AD 83            [24] 4302 	mov	r5,dph
      00167F AE F0            [24] 4303 	mov	r6,b
      001681 FF               [12] 4304 	mov	r7,a
      001682 C0 04            [24] 4305 	push	ar4
      001684 C0 05            [24] 4306 	push	ar5
      001686 C0 06            [24] 4307 	push	ar6
      001688 C0 07            [24] 4308 	push	ar7
      00168A 90 1C FE         [24] 4309 	mov	dptr,#_temperature_low_fuzzy_variable
      00168D 75 F0 80         [24] 4310 	mov	b, #0x80
      001690 12 0A 9F         [24] 4311 	lcall	_fuzzy_8051_eval
      001693 AC 82            [24] 4312 	mov	r4, dpl
      001695 AD 83            [24] 4313 	mov	r5, dph
      001697 AE F0            [24] 4314 	mov	r6, b
      001699 FF               [12] 4315 	mov	r7, a
      00169A E5 81            [12] 4316 	mov	a,sp
      00169C 24 FC            [12] 4317 	add	a,#0xfc
      00169E F5 81            [12] 4318 	mov	sp,a
      0016A0 8C 82            [24] 4319 	mov	dpl, r4
      0016A2 8D 83            [24] 4320 	mov	dph, r5
      0016A4 8E F0            [24] 4321 	mov	b, r6
      0016A6 EF               [12] 4322 	mov	a, r7
                           0015F0  4323 	C$controller_8051.c$30$1_0$41 ==.
                           0015F0  4324 	XFcontroller_8051$temperature_low$0$0 ==.
      0016A7 22               [24] 4325 	ret
                                   4326 ;------------------------------------------------------------
                                   4327 ;Allocation info for local variables in function 'temperature_high'
                                   4328 ;------------------------------------------------------------
                                   4329 ;x             Allocated to registers r4 r5 r6 r7 
                                   4330 ;------------------------------------------------------------
                           0015F1  4331 	Fcontroller_8051$temperature_high$0$0 ==.
                           0015F1  4332 	C$controller_8051.c$31$1_0$43 ==.
                                   4333 ;	../../controller_8051.c:31: FUZZY_VAR(temperature_high, FUZZY_SHAPE_RAMP, HEDGE_NONE, 30.0f, 60.0f, true)
                                   4334 ;	-----------------------------------------
                                   4335 ;	 function temperature_high
                                   4336 ;	-----------------------------------------
      0016A8                       4337 _temperature_high:
      0016A8 AC 82            [24] 4338 	mov	r4,dpl
      0016AA AD 83            [24] 4339 	mov	r5,dph
      0016AC AE F0            [24] 4340 	mov	r6,b
      0016AE FF               [12] 4341 	mov	r7,a
      0016AF C0 04            [24] 4342 	push	ar4
      0016B1 C0 05            [24] 4343 	push	ar5
      0016B3 C0 06            [24] 4344 	push	ar6
      0016B5 C0 07            [24] 4345 	push	ar7
      0016B7 90 1D 10         [24] 4346 	mov	dptr,#_temperature_high_fuzzy_variable
      0016BA 75 F0 80         [24] 4347 	mov	b, #0x80
      0016BD 12 0A 9F         [24] 4348 	lcall	_fuzzy_8051_eval
      0016C0 AC 82            [24] 4349 	mov	r4, dpl
      0016C2 AD 83            [24] 4350 	mov	r5, dph
      0016C4 AE F0            [24] 4351 	mov	r6, b
      0016C6 FF               [12] 4352 	mov	r7, a
      0016C7 E5 81            [12] 4353 	mov	a,sp
      0016C9 24 FC            [12] 4354 	add	a,#0xfc
      0016CB F5 81            [12] 4355 	mov	sp,a
      0016CD 8C 82            [24] 4356 	mov	dpl, r4
      0016CF 8D 83            [24] 4357 	mov	dph, r5
      0016D1 8E F0            [24] 4358 	mov	b, r6
      0016D3 EF               [12] 4359 	mov	a, r7
                           00161D  4360 	C$controller_8051.c$31$1_0$43 ==.
                           00161D  4361 	XFcontroller_8051$temperature_high$0$0 ==.
      0016D4 22               [24] 4362 	ret
                                   4363 ;------------------------------------------------------------
                                   4364 ;Allocation info for local variables in function 'fan_slow'
                                   4365 ;------------------------------------------------------------
                                   4366 ;x             Allocated to registers r4 r5 r6 r7 
                                   4367 ;------------------------------------------------------------
                           00161E  4368 	Fcontroller_8051$fan_slow$0$0 ==.
                           00161E  4369 	C$controller_8051.c$32$1_0$45 ==.
                                   4370 ;	../../controller_8051.c:32: FUZZY_VAR(fan_slow,         FUZZY_SHAPE_RAMP, HEDGE_NONE, 20.0f, 50.0f, false)
                                   4371 ;	-----------------------------------------
                                   4372 ;	 function fan_slow
                                   4373 ;	-----------------------------------------
      0016D5                       4374 _fan_slow:
      0016D5 AC 82            [24] 4375 	mov	r4,dpl
      0016D7 AD 83            [24] 4376 	mov	r5,dph
      0016D9 AE F0            [24] 4377 	mov	r6,b
      0016DB FF               [12] 4378 	mov	r7,a
      0016DC C0 04            [24] 4379 	push	ar4
      0016DE C0 05            [24] 4380 	push	ar5
      0016E0 C0 06            [24] 4381 	push	ar6
      0016E2 C0 07            [24] 4382 	push	ar7
      0016E4 90 1D 22         [24] 4383 	mov	dptr,#_fan_slow_fuzzy_variable
      0016E7 75 F0 80         [24] 4384 	mov	b, #0x80
      0016EA 12 0A 9F         [24] 4385 	lcall	_fuzzy_8051_eval
      0016ED AC 82            [24] 4386 	mov	r4, dpl
      0016EF AD 83            [24] 4387 	mov	r5, dph
      0016F1 AE F0            [24] 4388 	mov	r6, b
      0016F3 FF               [12] 4389 	mov	r7, a
      0016F4 E5 81            [12] 4390 	mov	a,sp
      0016F6 24 FC            [12] 4391 	add	a,#0xfc
      0016F8 F5 81            [12] 4392 	mov	sp,a
      0016FA 8C 82            [24] 4393 	mov	dpl, r4
      0016FC 8D 83            [24] 4394 	mov	dph, r5
      0016FE 8E F0            [24] 4395 	mov	b, r6
      001700 EF               [12] 4396 	mov	a, r7
                           00164A  4397 	C$controller_8051.c$32$1_0$45 ==.
                           00164A  4398 	XFcontroller_8051$fan_slow$0$0 ==.
      001701 22               [24] 4399 	ret
                                   4400 ;------------------------------------------------------------
                                   4401 ;Allocation info for local variables in function 'fan_fast'
                                   4402 ;------------------------------------------------------------
                                   4403 ;x             Allocated to registers r4 r5 r6 r7 
                                   4404 ;------------------------------------------------------------
                           00164B  4405 	Fcontroller_8051$fan_fast$0$0 ==.
                           00164B  4406 	C$controller_8051.c$33$1_0$47 ==.
                                   4407 ;	../../controller_8051.c:33: FUZZY_VAR(fan_fast,         FUZZY_SHAPE_RAMP, HEDGE_NONE, 40.0f, 80.0f, true)
                                   4408 ;	-----------------------------------------
                                   4409 ;	 function fan_fast
                                   4410 ;	-----------------------------------------
      001702                       4411 _fan_fast:
      001702 AC 82            [24] 4412 	mov	r4,dpl
      001704 AD 83            [24] 4413 	mov	r5,dph
      001706 AE F0            [24] 4414 	mov	r6,b
      001708 FF               [12] 4415 	mov	r7,a
      001709 C0 04            [24] 4416 	push	ar4
      00170B C0 05            [24] 4417 	push	ar5
      00170D C0 06            [24] 4418 	push	ar6
      00170F C0 07            [24] 4419 	push	ar7
      001711 90 1D 34         [24] 4420 	mov	dptr,#_fan_fast_fuzzy_variable
      001714 75 F0 80         [24] 4421 	mov	b, #0x80
      001717 12 0A 9F         [24] 4422 	lcall	_fuzzy_8051_eval
      00171A AC 82            [24] 4423 	mov	r4, dpl
      00171C AD 83            [24] 4424 	mov	r5, dph
      00171E AE F0            [24] 4425 	mov	r6, b
      001720 FF               [12] 4426 	mov	r7, a
      001721 E5 81            [12] 4427 	mov	a,sp
      001723 24 FC            [12] 4428 	add	a,#0xfc
      001725 F5 81            [12] 4429 	mov	sp,a
      001727 8C 82            [24] 4430 	mov	dpl, r4
      001729 8D 83            [24] 4431 	mov	dph, r5
      00172B 8E F0            [24] 4432 	mov	b, r6
      00172D EF               [12] 4433 	mov	a, r7
                           001677  4434 	C$controller_8051.c$33$1_0$47 ==.
                           001677  4435 	XFcontroller_8051$fan_fast$0$0 ==.
      00172E 22               [24] 4436 	ret
                                   4437 ;------------------------------------------------------------
                                   4438 ;Allocation info for local variables in function 'calculate_fan_speed'
                                   4439 ;------------------------------------------------------------
                                   4440 ;temperature   Allocated to stack - _bp +1 +4 
                                   4441 ;------------------------------------------------------------
                           001678  4442 	Fcontroller_8051$calculate_fan_speed$0$0 ==.
                           001678  4443 	C$controller_8051.c$35$1_0$49 ==.
                                   4444 ;	../../controller_8051.c:35: static float calculate_fan_speed(float temperature)
                                   4445 ;	-----------------------------------------
                                   4446 ;	 function calculate_fan_speed
                                   4447 ;	-----------------------------------------
      00172F                       4448 _calculate_fan_speed:
      00172F C0 1D            [24] 4449 	push	_bp
      001731 85 81 1D         [24] 4450 	mov	_bp,sp
      001734 C0 82            [24] 4451 	push	dpl
      001736 C0 83            [24] 4452 	push	dph
      001738 C0 F0            [24] 4453 	push	b
      00173A C0 E0            [24] 4454 	push	acc
                           001685  4455 	C$controller_8051.c$37$1_0$49 ==.
                                   4456 ;	../../controller_8051.c:37: rules.count = 0u;
      00173C 75 16 00         [24] 4457 	mov	(_rules + 0x000e),#0x00
                           001688  4458 	C$controller_8051.c$39$1_0$49 ==.
                                   4459 ;	../../controller_8051.c:39: RULE(
      00173F A8 1D            [24] 4460 	mov	r0,_bp
      001741 08               [12] 4461 	inc	r0
      001742 86 82            [24] 4462 	mov	dpl, @r0
      001744 08               [12] 4463 	inc	r0
      001745 86 83            [24] 4464 	mov	dph, @r0
      001747 08               [12] 4465 	inc	r0
      001748 86 F0            [24] 4466 	mov	b, @r0
      00174A 08               [12] 4467 	inc	r0
      00174B E6               [12] 4468 	mov	a, @r0
      00174C 12 16 7B         [24] 4469 	lcall	_temperature_low
      00174F AA 82            [24] 4470 	mov	r2, dpl
      001751 AB 83            [24] 4471 	mov	r3, dph
      001753 AE F0            [24] 4472 	mov	r6, b
      001755 FF               [12] 4473 	mov	r7, a
      001756 74 22            [12] 4474 	mov	a,#_fan_slow_fuzzy_variable
      001758 C0 E0            [24] 4475 	push	acc
      00175A 74 1D            [12] 4476 	mov	a,#(_fan_slow_fuzzy_variable >> 8)
      00175C C0 E0            [24] 4477 	push	acc
      00175E 74 80            [12] 4478 	mov	a,#0x80
      001760 C0 E0            [24] 4479 	push	acc
      001762 C0 02            [24] 4480 	push	ar2
      001764 C0 03            [24] 4481 	push	ar3
      001766 C0 06            [24] 4482 	push	ar6
      001768 C0 07            [24] 4483 	push	ar7
      00176A 90 00 08         [24] 4484 	mov	dptr,#_rules
      00176D 75 F0 40         [24] 4485 	mov	b, #0x40
      001770 12 0E 30         [24] 4486 	lcall	_fuzzy_rules_add_8051
      001773 E5 81            [12] 4487 	mov	a,sp
      001775 24 F9            [12] 4488 	add	a,#0xf9
      001777 F5 81            [12] 4489 	mov	sp,a
                           0016C2  4490 	C$controller_8051.c$46$1_0$49 ==.
                                   4491 ;	../../controller_8051.c:46: RULE(
      001779 A8 1D            [24] 4492 	mov	r0,_bp
      00177B 08               [12] 4493 	inc	r0
      00177C 86 82            [24] 4494 	mov	dpl, @r0
      00177E 08               [12] 4495 	inc	r0
      00177F 86 83            [24] 4496 	mov	dph, @r0
      001781 08               [12] 4497 	inc	r0
      001782 86 F0            [24] 4498 	mov	b, @r0
      001784 08               [12] 4499 	inc	r0
      001785 E6               [12] 4500 	mov	a, @r0
      001786 12 16 A8         [24] 4501 	lcall	_temperature_high
      001789 AC 82            [24] 4502 	mov	r4, dpl
      00178B AD 83            [24] 4503 	mov	r5, dph
      00178D AE F0            [24] 4504 	mov	r6, b
      00178F FF               [12] 4505 	mov	r7, a
      001790 74 34            [12] 4506 	mov	a,#_fan_fast_fuzzy_variable
      001792 C0 E0            [24] 4507 	push	acc
      001794 74 1D            [12] 4508 	mov	a,#(_fan_fast_fuzzy_variable >> 8)
      001796 C0 E0            [24] 4509 	push	acc
      001798 74 80            [12] 4510 	mov	a,#0x80
      00179A C0 E0            [24] 4511 	push	acc
      00179C C0 04            [24] 4512 	push	ar4
      00179E C0 05            [24] 4513 	push	ar5
      0017A0 C0 06            [24] 4514 	push	ar6
      0017A2 C0 07            [24] 4515 	push	ar7
      0017A4 90 00 08         [24] 4516 	mov	dptr,#_rules
      0017A7 75 F0 40         [24] 4517 	mov	b, #0x40
      0017AA 12 0E 30         [24] 4518 	lcall	_fuzzy_rules_add_8051
      0017AD E5 81            [12] 4519 	mov	a,sp
      0017AF 24 F9            [12] 4520 	add	a,#0xf9
      0017B1 F5 81            [12] 4521 	mov	sp,a
                           0016FC  4522 	C$controller_8051.c$54$1_0$49 ==.
                                   4523 ;	../../controller_8051.c:54: &rules,
      0017B3 74 03            [12] 4524 	mov	a,#0x03
      0017B5 C0 E0            [24] 4525 	push	acc
      0017B7 E4               [12] 4526 	clr	a
      0017B8 C0 E0            [24] 4527 	push	acc
      0017BA C0 E0            [24] 4528 	push	acc
      0017BC 74 20            [12] 4529 	mov	a,#0x20
      0017BE C0 E0            [24] 4530 	push	acc
      0017C0 74 41            [12] 4531 	mov	a,#0x41
      0017C2 C0 E0            [24] 4532 	push	acc
      0017C4 E4               [12] 4533 	clr	a
      0017C5 C0 E0            [24] 4534 	push	acc
      0017C7 C0 E0            [24] 4535 	push	acc
      0017C9 74 C8            [12] 4536 	mov	a,#0xc8
      0017CB C0 E0            [24] 4537 	push	acc
      0017CD 74 42            [12] 4538 	mov	a,#0x42
      0017CF C0 E0            [24] 4539 	push	acc
      0017D1 E4               [12] 4540 	clr	a
      0017D2 C0 E0            [24] 4541 	push	acc
      0017D4 C0 E0            [24] 4542 	push	acc
      0017D6 C0 E0            [24] 4543 	push	acc
      0017D8 C0 E0            [24] 4544 	push	acc
      0017DA 90 00 08         [24] 4545 	mov	dptr,#_rules
      0017DD 75 F0 40         [24] 4546 	mov	b, #0x40
      0017E0 12 10 CD         [24] 4547 	lcall	_fuzzy_rules_defuzzify
      0017E3 AC 82            [24] 4548 	mov	r4, dpl
      0017E5 AD 83            [24] 4549 	mov	r5, dph
      0017E7 AE F0            [24] 4550 	mov	r6, b
      0017E9 FF               [12] 4551 	mov	r7, a
      0017EA E5 81            [12] 4552 	mov	a,sp
      0017EC 24 F3            [12] 4553 	add	a,#0xf3
      0017EE F5 81            [12] 4554 	mov	sp,a
      0017F0 8C 82            [24] 4555 	mov	dpl, r4
      0017F2 8D 83            [24] 4556 	mov	dph, r5
      0017F4 8E F0            [24] 4557 	mov	b, r6
      0017F6 EF               [12] 4558 	mov	a, r7
                           001740  4559 	C$controller_8051.c$60$1_0$49 ==.
                                   4560 ;	../../controller_8051.c:60: }
      0017F7 85 1D 81         [24] 4561 	mov	sp,_bp
      0017FA D0 1D            [24] 4562 	pop	_bp
                           001745  4563 	C$controller_8051.c$60$1_0$49 ==.
                           001745  4564 	XFcontroller_8051$calculate_fan_speed$0$0 ==.
      0017FC 22               [24] 4565 	ret
                                   4566 ;------------------------------------------------------------
                                   4567 ;Allocation info for local variables in function 'fan_speed_to_pwm'
                                   4568 ;------------------------------------------------------------
                                   4569 ;fan_speed     Allocated to registers r4 r5 r6 r7 
                                   4570 ;------------------------------------------------------------
                           001746  4571 	Fcontroller_8051$fan_speed_to_pwm$0$0 ==.
                           001746  4572 	C$controller_8051.c$62$1_0$51 ==.
                                   4573 ;	../../controller_8051.c:62: static unsigned char fan_speed_to_pwm(float fan_speed)
                                   4574 ;	-----------------------------------------
                                   4575 ;	 function fan_speed_to_pwm
                                   4576 ;	-----------------------------------------
      0017FD                       4577 _fan_speed_to_pwm:
      0017FD AC 82            [24] 4578 	mov	r4,dpl
      0017FF AD 83            [24] 4579 	mov	r5,dph
      001801 AE F0            [24] 4580 	mov	r6,b
      001803 FF               [12] 4581 	mov	r7,a
                           00174D  4582 	C$controller_8051.c$64$1_0$51 ==.
                                   4583 ;	../../controller_8051.c:64: if (fan_speed <= 0.0f)
      001804 C0 07            [24] 4584 	push	ar7
      001806 C0 06            [24] 4585 	push	ar6
      001808 C0 05            [24] 4586 	push	ar5
      00180A C0 04            [24] 4587 	push	ar4
      00180C C0 04            [24] 4588 	push	ar4
      00180E C0 05            [24] 4589 	push	ar5
      001810 C0 06            [24] 4590 	push	ar6
      001812 C0 07            [24] 4591 	push	ar7
      001814 90 00 00         [24] 4592 	mov	dptr,#0x0000
      001817 E4               [12] 4593 	clr	a
      001818 F5 F0            [12] 4594 	mov	b,a
      00181A 12 1A 32         [24] 4595 	lcall	___fslt
      00181D E5 81            [12] 4596 	mov	a,sp
      00181F 24 FC            [12] 4597 	add	a,#0xfc
      001821 F5 81            [12] 4598 	mov	sp,a
      001823 D0 04            [24] 4599 	pop	ar4
      001825 D0 05            [24] 4600 	pop	ar5
      001827 D0 06            [24] 4601 	pop	ar6
      001829 D0 07            [24] 4602 	pop	ar7
      00182B E5 82            [12] 4603 	mov	a, dpl
      00182D 24 FF            [12] 4604 	add	a,#0xff
      00182F 92 00            [24] 4605 	mov	b0,c
      001831 40 05            [24] 4606 	jc	00102$
                           00177C  4607 	C$controller_8051.c$65$1_0$51 ==.
                                   4608 ;	../../controller_8051.c:65: return 0u;
      001833 75 82 00         [24] 4609 	mov	dpl, #0x00
      001836 80 66            [24] 4610 	sjmp	00105$
      001838                       4611 00102$:
                           001781  4612 	C$controller_8051.c$67$1_0$51 ==.
                                   4613 ;	../../controller_8051.c:67: if (fan_speed >= 100.0f)
      001838 C0 07            [24] 4614 	push	ar7
      00183A C0 06            [24] 4615 	push	ar6
      00183C C0 05            [24] 4616 	push	ar5
      00183E C0 04            [24] 4617 	push	ar4
      001840 E4               [12] 4618 	clr	a
      001841 C0 E0            [24] 4619 	push	acc
      001843 C0 E0            [24] 4620 	push	acc
      001845 74 C8            [12] 4621 	mov	a,#0xc8
      001847 C0 E0            [24] 4622 	push	acc
      001849 74 42            [12] 4623 	mov	a,#0x42
      00184B C0 E0            [24] 4624 	push	acc
      00184D 8C 82            [24] 4625 	mov	dpl, r4
      00184F 8D 83            [24] 4626 	mov	dph, r5
      001851 8E F0            [24] 4627 	mov	b, r6
      001853 EF               [12] 4628 	mov	a, r7
      001854 12 1A 32         [24] 4629 	lcall	___fslt
      001857 E5 81            [12] 4630 	mov	a,sp
      001859 24 FC            [12] 4631 	add	a,#0xfc
      00185B F5 81            [12] 4632 	mov	sp,a
      00185D D0 04            [24] 4633 	pop	ar4
      00185F D0 05            [24] 4634 	pop	ar5
      001861 D0 06            [24] 4635 	pop	ar6
      001863 D0 07            [24] 4636 	pop	ar7
      001865 E5 82            [12] 4637 	mov	a, dpl
      001867 24 FF            [12] 4638 	add	a,#0xff
      001869 92 00            [24] 4639 	mov	b0,c
      00186B 40 05            [24] 4640 	jc	00104$
                           0017B6  4641 	C$controller_8051.c$68$1_0$51 ==.
                                   4642 ;	../../controller_8051.c:68: return 100u;
      00186D 75 82 64         [24] 4643 	mov	dpl, #0x64
      001870 80 2C            [24] 4644 	sjmp	00105$
      001872                       4645 00104$:
                           0017BB  4646 	C$controller_8051.c$70$1_0$51 ==.
                                   4647 ;	../../controller_8051.c:70: return (unsigned char)(fan_speed + 0.5f);
      001872 E4               [12] 4648 	clr	a
      001873 C0 E0            [24] 4649 	push	acc
      001875 C0 E0            [24] 4650 	push	acc
      001877 C0 E0            [24] 4651 	push	acc
      001879 74 3F            [12] 4652 	mov	a,#0x3f
      00187B C0 E0            [24] 4653 	push	acc
      00187D 8C 82            [24] 4654 	mov	dpl, r4
      00187F 8D 83            [24] 4655 	mov	dph, r5
      001881 8E F0            [24] 4656 	mov	b, r6
      001883 EF               [12] 4657 	mov	a, r7
      001884 12 1A 62         [24] 4658 	lcall	___fsadd
      001887 AC 82            [24] 4659 	mov	r4, dpl
      001889 AD 83            [24] 4660 	mov	r5, dph
      00188B AE F0            [24] 4661 	mov	r6, b
      00188D FF               [12] 4662 	mov	r7, a
      00188E E5 81            [12] 4663 	mov	a,sp
      001890 24 FC            [12] 4664 	add	a,#0xfc
      001892 F5 81            [12] 4665 	mov	sp,a
      001894 8C 82            [24] 4666 	mov	dpl, r4
      001896 8D 83            [24] 4667 	mov	dph, r5
      001898 8E F0            [24] 4668 	mov	b, r6
      00189A EF               [12] 4669 	mov	a, r7
      00189B 12 1C 58         [24] 4670 	lcall	___fs2uchar
      00189E                       4671 00105$:
                           0017E7  4672 	C$controller_8051.c$71$1_0$51 ==.
                                   4673 ;	../../controller_8051.c:71: }
                           0017E7  4674 	C$controller_8051.c$71$1_0$51 ==.
                           0017E7  4675 	XFcontroller_8051$fan_speed_to_pwm$0$0 ==.
      00189E 22               [24] 4676 	ret
                                   4677 ;------------------------------------------------------------
                                   4678 ;Allocation info for local variables in function 'update_controller'
                                   4679 ;------------------------------------------------------------
                                   4680 ;temperature   Allocated to registers 
                                   4681 ;------------------------------------------------------------
                           0017E8  4682 	Fcontroller_8051$update_controller$0$0 ==.
                           0017E8  4683 	C$controller_8051.c$73$1_0$53 ==.
                                   4684 ;	../../controller_8051.c:73: static void update_controller(unsigned char temperature)
                                   4685 ;	-----------------------------------------
                                   4686 ;	 function update_controller
                                   4687 ;	-----------------------------------------
      00189F                       4688 _update_controller:
      00189F 85 82 17         [24] 4689 	mov	_test_temperature,dpl
                           0017EB  4690 	C$controller_8051.c$76$1_0$53 ==.
                                   4691 ;	../../controller_8051.c:76: test_fan_speed = calculate_fan_speed((float)test_temperature);
      0018A2 85 17 82         [24] 4692 	mov	dpl, _test_temperature
      0018A5 12 1C 60         [24] 4693 	lcall	___uchar2fs
      0018A8 12 17 2F         [24] 4694 	lcall	_calculate_fan_speed
      0018AB 85 82 19         [24] 4695 	mov	_test_fan_speed,dpl
      0018AE 85 83 1A         [24] 4696 	mov	(_test_fan_speed + 1),dph
      0018B1 85 F0 1B         [24] 4697 	mov	(_test_fan_speed + 2),b
      0018B4 F5 1C            [12] 4698 	mov	(_test_fan_speed + 3),a
                           0017FF  4699 	C$controller_8051.c$77$1_0$53 ==.
                                   4700 ;	../../controller_8051.c:77: test_pwm = fan_speed_to_pwm(test_fan_speed);
      0018B6 85 19 82         [24] 4701 	mov	dpl, _test_fan_speed
      0018B9 85 1A 83         [24] 4702 	mov	dph, (_test_fan_speed + 1)
      0018BC 85 1B F0         [24] 4703 	mov	b, (_test_fan_speed + 2)
      0018BF E5 1C            [12] 4704 	mov	a, (_test_fan_speed + 3)
      0018C1 12 17 FD         [24] 4705 	lcall	_fan_speed_to_pwm
      0018C4 85 82 18         [24] 4706 	mov	_test_pwm,dpl
                           001810  4707 	C$controller_8051.c$78$1_0$53 ==.
                                   4708 ;	../../controller_8051.c:78: }
                           001810  4709 	C$controller_8051.c$78$1_0$53 ==.
                           001810  4710 	XFcontroller_8051$update_controller$0$0 ==.
      0018C7 22               [24] 4711 	ret
                                   4712 ;------------------------------------------------------------
                                   4713 ;Allocation info for local variables in function 'main'
                                   4714 ;------------------------------------------------------------
                           001811  4715 	G$main$0$0 ==.
                           001811  4716 	C$controller_8051.c$82$1_0$55 ==.
                                   4717 ;	../../controller_8051.c:82: void main(void)
                                   4718 ;	-----------------------------------------
                                   4719 ;	 function main
                                   4720 ;	-----------------------------------------
      0018C8                       4721 _main:
                           001811  4722 	C$controller_8051.c$84$1_0$55 ==.
                                   4723 ;	../../controller_8051.c:84: P0 = 0x00u;
      0018C8 75 80 00         [24] 4724 	mov	_P0,#0x00
                           001814  4725 	C$controller_8051.c$85$1_0$55 ==.
                                   4726 ;	../../controller_8051.c:85: P1 = 0x00u;
      0018CB 75 90 00         [24] 4727 	mov	_P1,#0x00
      0018CE                       4728 00105$:
                           001817  4729 	C$controller_8051.c$88$3_0$57 ==.
                                   4730 ;	../../controller_8051.c:88: P0 = 0x55u;
      0018CE 75 80 55         [24] 4731 	mov	_P0,#0x55
                           00181A  4732 	C$controller_8051.c$90$3_0$57 ==.
                                   4733 ;	../../controller_8051.c:90: test_temperature = P2;
      0018D1 85 A0 17         [24] 4734 	mov	_test_temperature,_P2
                           00181D  4735 	C$controller_8051.c$92$3_0$57 ==.
                                   4736 ;	../../controller_8051.c:92: if (test_temperature > 100u) {
      0018D4 E5 17            [12] 4737 	mov	a,_test_temperature
      0018D6 24 9B            [12] 4738 	add	a,#0xff - 0x64
      0018D8 50 08            [24] 4739 	jnc	00102$
                           001823  4740 	C$controller_8051.c$93$4_0$58 ==.
                                   4741 ;	../../controller_8051.c:93: P1 = 0x00u;
      0018DA 75 90 00         [24] 4742 	mov	_P1,#0x00
                           001826  4743 	C$controller_8051.c$94$4_0$58 ==.
                                   4744 ;	../../controller_8051.c:94: P0 = 0xF0u;
      0018DD 75 80 F0         [24] 4745 	mov	_P0,#0xf0
                           001829  4746 	C$controller_8051.c$95$4_0$58 ==.
                                   4747 ;	../../controller_8051.c:95: continue;
      0018E0 80 EC            [24] 4748 	sjmp	00105$
      0018E2                       4749 00102$:
                           00182B  4750 	C$controller_8051.c$98$3_0$57 ==.
                                   4751 ;	../../controller_8051.c:98: P0 = 0x60u;
      0018E2 75 80 60         [24] 4752 	mov	_P0,#0x60
                           00182E  4753 	C$controller_8051.c$99$3_0$57 ==.
                                   4754 ;	../../controller_8051.c:99: update_controller(test_temperature);
      0018E5 85 17 82         [24] 4755 	mov	dpl, _test_temperature
      0018E8 12 18 9F         [24] 4756 	lcall	_update_controller
                           001834  4757 	C$controller_8051.c$100$3_0$57 ==.
                                   4758 ;	../../controller_8051.c:100: P0 = 0x70u;
      0018EB 75 80 70         [24] 4759 	mov	_P0,#0x70
                           001837  4760 	C$controller_8051.c$101$3_0$57 ==.
                                   4761 ;	../../controller_8051.c:101: P1 = test_pwm;
      0018EE 85 18 90         [24] 4762 	mov	_P1,_test_pwm
                           00183A  4763 	C$controller_8051.c$102$3_0$57 ==.
                                   4764 ;	../../controller_8051.c:102: P0 = 0xAAu;
      0018F1 75 80 AA         [24] 4765 	mov	_P0,#0xaa
      0018F4 80 D8            [24] 4766 	sjmp	00105$
                           00183F  4767 	C$controller_8051.c$104$2_0$55 ==.
                                   4768 ;	../../controller_8051.c:104: }
                           00183F  4769 	C$controller_8051.c$104$2_0$55 ==.
                           00183F  4770 	XG$main$0$0 ==.
      0018F6 22               [24] 4771 	ret
                                   4772 	.area CSEG    (CODE)
                                   4773 	.area CONST   (CODE)
                                   4774 	.area CONST   (CODE)
                           000000  4775 Fcontroller_8051$temperature_low_fuzzy_variable$0_0$0 == .
      001CFE                       4776 _temperature_low_fuzzy_variable:
      001CFE 00                    4777 	.db #0x00	; 0
      001CFF 01                    4778 	.db #0x01	; 1
      001D00 00 00 A0 41           4779 	.byte #0x00, #0x00, #0xa0, #0x41	;  2.000000e+01
      001D04 00 00 20 42           4780 	.byte #0x00, #0x00, #0x20, #0x42	;  4.000000e+01
      001D08 00 00 00 00           4781 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
      001D0C 00 00 00 00           4782 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   4783 	.area CSEG    (CODE)
                                   4784 	.area CONST   (CODE)
                           000012  4785 Fcontroller_8051$temperature_high_fuzzy_variable$0_0$0 == .
      001D10                       4786 _temperature_high_fuzzy_variable:
      001D10 00                    4787 	.db #0x00	; 0
      001D11 01                    4788 	.db #0x01	; 1
      001D12 00 00 F0 41           4789 	.byte #0x00, #0x00, #0xf0, #0x41	;  3.000000e+01
      001D16 00 00 70 42           4790 	.byte #0x00, #0x00, #0x70, #0x42	;  6.000000e+01
      001D1A 00 00 80 3F           4791 	.byte #0x00, #0x00, #0x80, #0x3f	;  1.000000e+00
      001D1E 00 00 00 00           4792 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   4793 	.area CSEG    (CODE)
                                   4794 	.area CONST   (CODE)
                           000024  4795 Fcontroller_8051$fan_slow_fuzzy_variable$0_0$0 == .
      001D22                       4796 _fan_slow_fuzzy_variable:
      001D22 00                    4797 	.db #0x00	; 0
      001D23 01                    4798 	.db #0x01	; 1
      001D24 00 00 A0 41           4799 	.byte #0x00, #0x00, #0xa0, #0x41	;  2.000000e+01
      001D28 00 00 48 42           4800 	.byte #0x00, #0x00, #0x48, #0x42	;  5.000000e+01
      001D2C 00 00 00 00           4801 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
      001D30 00 00 00 00           4802 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   4803 	.area CSEG    (CODE)
                                   4804 	.area CONST   (CODE)
                           000036  4805 Fcontroller_8051$fan_fast_fuzzy_variable$0_0$0 == .
      001D34                       4806 _fan_fast_fuzzy_variable:
      001D34 00                    4807 	.db #0x00	; 0
      001D35 01                    4808 	.db #0x01	; 1
      001D36 00 00 20 42           4809 	.byte #0x00, #0x00, #0x20, #0x42	;  4.000000e+01
      001D3A 00 00 A0 42           4810 	.byte #0x00, #0x00, #0xa0, #0x42	;  8.000000e+01
      001D3E 00 00 80 3F           4811 	.byte #0x00, #0x00, #0x80, #0x3f	;  1.000000e+00
      001D42 00 00 00 00           4812 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   4813 	.area CSEG    (CODE)
                                   4814 	.area XINIT   (CODE)
                                   4815 	.area CABS    (ABS,CODE)
