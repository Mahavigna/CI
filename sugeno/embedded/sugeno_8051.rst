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
                           000000   555 	C$sugeno_demo.c$17$2_0$131 ==.
                                    556 ;	../../sugeno_demo.c:17: volatile unsigned char test_temperature = 0u;
      0000A5 75 08 00         [24]  557 	mov	_test_temperature,#0x00
                           000003   558 	C$sugeno_demo.c$18$2_0$131 ==.
                                    559 ;	../../sugeno_demo.c:18: volatile unsigned char test_load = 0u;
      0000A8 75 09 00         [24]  560 	mov	_test_load,#0x00
                           000006   561 	C$sugeno_demo.c$19$2_0$131 ==.
                                    562 ;	../../sugeno_demo.c:19: volatile unsigned char test_vibration = 0u;
      0000AB 75 0A 00         [24]  563 	mov	_test_vibration,#0x00
                           000009   564 	C$sugeno_demo.c$20$2_0$131 ==.
                                    565 ;	../../sugeno_demo.c:20: volatile unsigned char test_pwm = 0u;
      0000AE 75 0B 00         [24]  566 	mov	_test_pwm,#0x00
                           00000C   567 	C$sugeno_demo.c$21$2_0$131 ==.
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
                           000000   597 	C$fuzzy.h$116$0_0$35 ==.
                                    598 ;	../../fuzzy.h:116: static float fuzzy_8051_and2(fuzzy_logic_method_t method, float a, float b)
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
                           000007   614 	C$fuzzy.h$118$1_0$35 ==.
                                    615 ;	../../fuzzy.h:118: if (method == FUZZY_LOGIC_ALGEBRAIC) {
      0000C4 BF 01 3D         [24]  616 	cjne	r7,#0x01,00102$
                           00000A   617 	C$fuzzy.h$119$1_0$35 ==.
                                    618 ;	../../fuzzy.h:119: return a * b;
      0000C7 E5 10            [12]  619 	mov	a,_bp
      0000C9 24 F6            [12]  620 	add	a,#0xf6
      0000CB F8               [12]  621 	mov	r0,a
      0000CC E6               [12]  622 	mov	a,@r0
      0000CD C0 E0            [24]  623 	push	acc
      0000CF 08               [12]  624 	inc	r0
      0000D0 E6               [12]  625 	mov	a,@r0
      0000D1 C0 E0            [24]  626 	push	acc
      0000D3 08               [12]  627 	inc	r0
      0000D4 E6               [12]  628 	mov	a,@r0
      0000D5 C0 E0            [24]  629 	push	acc
      0000D7 08               [12]  630 	inc	r0
      0000D8 E6               [12]  631 	mov	a,@r0
      0000D9 C0 E0            [24]  632 	push	acc
      0000DB E5 10            [12]  633 	mov	a,_bp
      0000DD 24 FA            [12]  634 	add	a,#0xfa
      0000DF F8               [12]  635 	mov	r0,a
      0000E0 86 82            [24]  636 	mov	dpl, @r0
      0000E2 08               [12]  637 	inc	r0
      0000E3 86 83            [24]  638 	mov	dph, @r0
      0000E5 08               [12]  639 	inc	r0
      0000E6 86 F0            [24]  640 	mov	b, @r0
      0000E8 08               [12]  641 	inc	r0
      0000E9 E6               [12]  642 	mov	a, @r0
      0000EA 12 2A B5         [24]  643 	lcall	___fsmul
      0000ED AB 82            [24]  644 	mov	r3, dpl
      0000EF AC 83            [24]  645 	mov	r4, dph
      0000F1 AD F0            [24]  646 	mov	r5, b
      0000F3 FE               [12]  647 	mov	r6, a
      0000F4 E5 81            [12]  648 	mov	a,sp
      0000F6 24 FC            [12]  649 	add	a,#0xfc
      0000F8 F5 81            [12]  650 	mov	sp,a
      0000FA 8B 82            [24]  651 	mov	dpl, r3
      0000FC 8C 83            [24]  652 	mov	dph, r4
      0000FE 8D F0            [24]  653 	mov	b, r5
      000100 EE               [12]  654 	mov	a, r6
      000101 02 01 F6         [24]  655 	ljmp	00105$
      000104                        656 00102$:
                           000047   657 	C$fuzzy.h$122$1_0$35 ==.
                                    658 ;	../../fuzzy.h:122: if (method == FUZZY_LOGIC_BOUNDED) {
      000104 BF 02 02         [24]  659 	cjne	r7,#0x02,00137$
      000107 80 03            [24]  660 	sjmp	00138$
      000109                        661 00137$:
      000109 02 01 9C         [24]  662 	ljmp	00104$
      00010C                        663 00138$:
                           00004F   664 	C$fuzzy.h$123$1_0$35 ==.
                                    665 ;	../../fuzzy.h:123: float value = a + b - 1.0f;
      00010C E5 10            [12]  666 	mov	a,_bp
      00010E 24 F6            [12]  667 	add	a,#0xf6
      000110 F8               [12]  668 	mov	r0,a
      000111 E6               [12]  669 	mov	a,@r0
      000112 C0 E0            [24]  670 	push	acc
      000114 08               [12]  671 	inc	r0
      000115 E6               [12]  672 	mov	a,@r0
      000116 C0 E0            [24]  673 	push	acc
      000118 08               [12]  674 	inc	r0
      000119 E6               [12]  675 	mov	a,@r0
      00011A C0 E0            [24]  676 	push	acc
      00011C 08               [12]  677 	inc	r0
      00011D E6               [12]  678 	mov	a,@r0
      00011E C0 E0            [24]  679 	push	acc
      000120 E5 10            [12]  680 	mov	a,_bp
      000122 24 FA            [12]  681 	add	a,#0xfa
      000124 F8               [12]  682 	mov	r0,a
      000125 86 82            [24]  683 	mov	dpl, @r0
      000127 08               [12]  684 	inc	r0
      000128 86 83            [24]  685 	mov	dph, @r0
      00012A 08               [12]  686 	inc	r0
      00012B 86 F0            [24]  687 	mov	b, @r0
      00012D 08               [12]  688 	inc	r0
      00012E E6               [12]  689 	mov	a, @r0
      00012F 12 2C 15         [24]  690 	lcall	___fsadd
      000132 AC 82            [24]  691 	mov	r4, dpl
      000134 AD 83            [24]  692 	mov	r5, dph
      000136 AE F0            [24]  693 	mov	r6, b
      000138 FF               [12]  694 	mov	r7, a
      000139 E5 81            [12]  695 	mov	a,sp
      00013B 24 FC            [12]  696 	add	a,#0xfc
      00013D F5 81            [12]  697 	mov	sp,a
      00013F E4               [12]  698 	clr	a
      000140 C0 E0            [24]  699 	push	acc
      000142 C0 E0            [24]  700 	push	acc
      000144 74 80            [12]  701 	mov	a,#0x80
      000146 C0 E0            [24]  702 	push	acc
      000148 74 3F            [12]  703 	mov	a,#0x3f
      00014A C0 E0            [24]  704 	push	acc
                           00008F   705 	C$fuzzy.h$124$1_0$35 ==.
                                    706 ;	../../fuzzy.h:124: return value > 0.0f ? value : 0.0f;
      00014C 8C 82            [24]  707 	mov	dpl, r4
      00014E 8D 83            [24]  708 	mov	dph, r5
      000150 8E F0            [24]  709 	mov	b, r6
      000152 EF               [12]  710 	mov	a, r7
      000153 12 2A AA         [24]  711 	lcall	___fssub
      000156 AC 82            [24]  712 	mov	r4, dpl
      000158 AD 83            [24]  713 	mov	r5, dph
      00015A AE F0            [24]  714 	mov	r6, b
      00015C FF               [12]  715 	mov	r7, a
      00015D E5 81            [12]  716 	mov	a,sp
      00015F 24 FC            [12]  717 	add	a,#0xfc
      000161 F5 81            [12]  718 	mov	sp,a
      000163 C0 07            [24]  719 	push	ar7
      000165 C0 06            [24]  720 	push	ar6
      000167 C0 05            [24]  721 	push	ar5
      000169 C0 04            [24]  722 	push	ar4
      00016B C0 04            [24]  723 	push	ar4
      00016D C0 05            [24]  724 	push	ar5
      00016F C0 06            [24]  725 	push	ar6
      000171 C0 07            [24]  726 	push	ar7
      000173 90 00 00         [24]  727 	mov	dptr,#0x0000
      000176 E4               [12]  728 	clr	a
      000177 F5 F0            [12]  729 	mov	b,a
      000179 12 2B E5         [24]  730 	lcall	___fslt
      00017C AB 82            [24]  731 	mov	r3, dpl
      00017E E5 81            [12]  732 	mov	a,sp
      000180 24 FC            [12]  733 	add	a,#0xfc
      000182 F5 81            [12]  734 	mov	sp,a
      000184 D0 04            [24]  735 	pop	ar4
      000186 D0 05            [24]  736 	pop	ar5
      000188 D0 06            [24]  737 	pop	ar6
      00018A D0 07            [24]  738 	pop	ar7
      00018C EB               [12]  739 	mov	a,r3
      00018D 70 04            [24]  740 	jnz	00108$
      00018F FC               [12]  741 	mov	r4,a
      000190 FD               [12]  742 	mov	r5,a
      000191 FE               [12]  743 	mov	r6,a
      000192 FF               [12]  744 	mov	r7,a
      000193                        745 00108$:
      000193 8C 82            [24]  746 	mov	dpl, r4
      000195 8D 83            [24]  747 	mov	dph, r5
      000197 8E F0            [24]  748 	mov	b, r6
      000199 EF               [12]  749 	mov	a, r7
      00019A 80 5A            [24]  750 	sjmp	00105$
      00019C                        751 00104$:
                           0000DF   752 	C$fuzzy.h$127$1_0$35 ==.
                                    753 ;	../../fuzzy.h:127: return a < b ? a : b;
      00019C E5 10            [12]  754 	mov	a,_bp
      00019E 24 F6            [12]  755 	add	a,#0xf6
      0001A0 F8               [12]  756 	mov	r0,a
      0001A1 E6               [12]  757 	mov	a,@r0
      0001A2 C0 E0            [24]  758 	push	acc
      0001A4 08               [12]  759 	inc	r0
      0001A5 E6               [12]  760 	mov	a,@r0
      0001A6 C0 E0            [24]  761 	push	acc
      0001A8 08               [12]  762 	inc	r0
      0001A9 E6               [12]  763 	mov	a,@r0
      0001AA C0 E0            [24]  764 	push	acc
      0001AC 08               [12]  765 	inc	r0
      0001AD E6               [12]  766 	mov	a,@r0
      0001AE C0 E0            [24]  767 	push	acc
      0001B0 E5 10            [12]  768 	mov	a,_bp
      0001B2 24 FA            [12]  769 	add	a,#0xfa
      0001B4 F8               [12]  770 	mov	r0,a
      0001B5 86 82            [24]  771 	mov	dpl, @r0
      0001B7 08               [12]  772 	inc	r0
      0001B8 86 83            [24]  773 	mov	dph, @r0
      0001BA 08               [12]  774 	inc	r0
      0001BB 86 F0            [24]  775 	mov	b, @r0
      0001BD 08               [12]  776 	inc	r0
      0001BE E6               [12]  777 	mov	a, @r0
      0001BF 12 2B E5         [24]  778 	lcall	___fslt
      0001C2 AF 82            [24]  779 	mov	r7, dpl
      0001C4 E5 81            [12]  780 	mov	a,sp
      0001C6 24 FC            [12]  781 	add	a,#0xfc
      0001C8 F5 81            [12]  782 	mov	sp,a
      0001CA EF               [12]  783 	mov	a,r7
      0001CB 60 12            [24]  784 	jz	00109$
      0001CD E5 10            [12]  785 	mov	a,_bp
      0001CF 24 FA            [12]  786 	add	a,#0xfa
      0001D1 F8               [12]  787 	mov	r0,a
      0001D2 86 04            [24]  788 	mov	ar4,@r0
      0001D4 08               [12]  789 	inc	r0
      0001D5 86 05            [24]  790 	mov	ar5,@r0
      0001D7 08               [12]  791 	inc	r0
      0001D8 86 06            [24]  792 	mov	ar6,@r0
      0001DA 08               [12]  793 	inc	r0
      0001DB 86 07            [24]  794 	mov	ar7,@r0
      0001DD 80 10            [24]  795 	sjmp	00110$
      0001DF                        796 00109$:
      0001DF E5 10            [12]  797 	mov	a,_bp
      0001E1 24 F6            [12]  798 	add	a,#0xf6
      0001E3 F8               [12]  799 	mov	r0,a
      0001E4 86 04            [24]  800 	mov	ar4,@r0
      0001E6 08               [12]  801 	inc	r0
      0001E7 86 05            [24]  802 	mov	ar5,@r0
      0001E9 08               [12]  803 	inc	r0
      0001EA 86 06            [24]  804 	mov	ar6,@r0
      0001EC 08               [12]  805 	inc	r0
      0001ED 86 07            [24]  806 	mov	ar7,@r0
      0001EF                        807 00110$:
      0001EF 8C 82            [24]  808 	mov	dpl, r4
      0001F1 8D 83            [24]  809 	mov	dph, r5
      0001F3 8E F0            [24]  810 	mov	b, r6
      0001F5 EF               [12]  811 	mov	a, r7
      0001F6                        812 00105$:
                           000139   813 	C$fuzzy.h$128$1_0$35 ==.
                                    814 ;	../../fuzzy.h:128: }
      0001F6 D0 10            [24]  815 	pop	_bp
                           00013B   816 	C$fuzzy.h$128$1_0$35 ==.
                           00013B   817 	XFsugeno_demo$fuzzy_8051_and2$0$0 ==.
      0001F8 22               [24]  818 	ret
                                    819 ;------------------------------------------------------------
                                    820 ;Allocation info for local variables in function 'fuzzy_8051_and3'
                                    821 ;------------------------------------------------------------
                                    822 ;a             Allocated to stack - _bp -6 +4 
                                    823 ;b             Allocated to stack - _bp -10 +4 
                                    824 ;c             Allocated to stack - _bp -14 +4 
                                    825 ;method        Allocated to registers r7 
                                    826 ;------------------------------------------------------------
                           00013C   827 	Fsugeno_demo$fuzzy_8051_and3$0$0 ==.
                           00013C   828 	C$fuzzy.h$130$1_0$39 ==.
                                    829 ;	../../fuzzy.h:130: static float fuzzy_8051_and3(fuzzy_logic_method_t method, float a, float b, float c)
                                    830 ;	-----------------------------------------
                                    831 ;	 function fuzzy_8051_and3
                                    832 ;	-----------------------------------------
      0001F9                        833 _fuzzy_8051_and3:
      0001F9 C0 10            [24]  834 	push	_bp
      0001FB 85 81 10         [24]  835 	mov	_bp,sp
      0001FE AF 82            [24]  836 	mov	r7, dpl
                           000143   837 	C$fuzzy.h$132$1_0$39 ==.
                                    838 ;	../../fuzzy.h:132: return fuzzy_8051_and2(method, fuzzy_8051_and2(method, a, b), c);
      000200 C0 07            [24]  839 	push	ar7
      000202 E5 10            [12]  840 	mov	a,_bp
      000204 24 F6            [12]  841 	add	a,#0xf6
      000206 F8               [12]  842 	mov	r0,a
      000207 E6               [12]  843 	mov	a,@r0
      000208 C0 E0            [24]  844 	push	acc
      00020A 08               [12]  845 	inc	r0
      00020B E6               [12]  846 	mov	a,@r0
      00020C C0 E0            [24]  847 	push	acc
      00020E 08               [12]  848 	inc	r0
      00020F E6               [12]  849 	mov	a,@r0
      000210 C0 E0            [24]  850 	push	acc
      000212 08               [12]  851 	inc	r0
      000213 E6               [12]  852 	mov	a,@r0
      000214 C0 E0            [24]  853 	push	acc
      000216 E5 10            [12]  854 	mov	a,_bp
      000218 24 FA            [12]  855 	add	a,#0xfa
      00021A F8               [12]  856 	mov	r0,a
      00021B E6               [12]  857 	mov	a,@r0
      00021C C0 E0            [24]  858 	push	acc
      00021E 08               [12]  859 	inc	r0
      00021F E6               [12]  860 	mov	a,@r0
      000220 C0 E0            [24]  861 	push	acc
      000222 08               [12]  862 	inc	r0
      000223 E6               [12]  863 	mov	a,@r0
      000224 C0 E0            [24]  864 	push	acc
      000226 08               [12]  865 	inc	r0
      000227 E6               [12]  866 	mov	a,@r0
      000228 C0 E0            [24]  867 	push	acc
      00022A 8F 82            [24]  868 	mov	dpl, r7
      00022C 12 00 BD         [24]  869 	lcall	_fuzzy_8051_and2
      00022F AB 82            [24]  870 	mov	r3, dpl
      000231 AC 83            [24]  871 	mov	r4, dph
      000233 AD F0            [24]  872 	mov	r5, b
      000235 FE               [12]  873 	mov	r6, a
      000236 E5 81            [12]  874 	mov	a,sp
      000238 24 F8            [12]  875 	add	a,#0xf8
      00023A F5 81            [12]  876 	mov	sp,a
      00023C D0 07            [24]  877 	pop	ar7
      00023E E5 10            [12]  878 	mov	a,_bp
      000240 24 F2            [12]  879 	add	a,#0xf2
      000242 F8               [12]  880 	mov	r0,a
      000243 E6               [12]  881 	mov	a,@r0
      000244 C0 E0            [24]  882 	push	acc
      000246 08               [12]  883 	inc	r0
      000247 E6               [12]  884 	mov	a,@r0
      000248 C0 E0            [24]  885 	push	acc
      00024A 08               [12]  886 	inc	r0
      00024B E6               [12]  887 	mov	a,@r0
      00024C C0 E0            [24]  888 	push	acc
      00024E 08               [12]  889 	inc	r0
      00024F E6               [12]  890 	mov	a,@r0
      000250 C0 E0            [24]  891 	push	acc
      000252 C0 03            [24]  892 	push	ar3
      000254 C0 04            [24]  893 	push	ar4
      000256 C0 05            [24]  894 	push	ar5
      000258 C0 06            [24]  895 	push	ar6
      00025A 8F 82            [24]  896 	mov	dpl, r7
      00025C 12 00 BD         [24]  897 	lcall	_fuzzy_8051_and2
      00025F AC 82            [24]  898 	mov	r4, dpl
      000261 AD 83            [24]  899 	mov	r5, dph
      000263 AE F0            [24]  900 	mov	r6, b
      000265 FF               [12]  901 	mov	r7, a
      000266 E5 81            [12]  902 	mov	a,sp
      000268 24 F8            [12]  903 	add	a,#0xf8
      00026A F5 81            [12]  904 	mov	sp,a
      00026C 8C 82            [24]  905 	mov	dpl, r4
      00026E 8D 83            [24]  906 	mov	dph, r5
      000270 8E F0            [24]  907 	mov	b, r6
      000272 EF               [12]  908 	mov	a, r7
                           0001B6   909 	C$fuzzy.h$133$1_0$39 ==.
                                    910 ;	../../fuzzy.h:133: }
      000273 D0 10            [24]  911 	pop	_bp
                           0001B8   912 	C$fuzzy.h$133$1_0$39 ==.
                           0001B8   913 	XFsugeno_demo$fuzzy_8051_and3$0$0 ==.
      000275 22               [24]  914 	ret
                                    915 ;------------------------------------------------------------
                                    916 ;Allocation info for local variables in function 'fuzzy_8051_or2'
                                    917 ;------------------------------------------------------------
                                    918 ;a             Allocated to stack - _bp -6 +4 
                                    919 ;b             Allocated to stack - _bp -10 +4 
                                    920 ;method        Allocated to registers r7 
                                    921 ;value         Allocated to registers r4 r5 r6 r7 
                                    922 ;sloc0         Allocated to stack - _bp +1 +4 
                                    923 ;------------------------------------------------------------
                           0001B9   924 	Fsugeno_demo$fuzzy_8051_or2$0$0 ==.
                           0001B9   925 	C$fuzzy.h$135$1_0$41 ==.
                                    926 ;	../../fuzzy.h:135: static float fuzzy_8051_or2(fuzzy_logic_method_t method, float a, float b)
                                    927 ;	-----------------------------------------
                                    928 ;	 function fuzzy_8051_or2
                                    929 ;	-----------------------------------------
      000276                        930 _fuzzy_8051_or2:
      000276 C0 10            [24]  931 	push	_bp
      000278 E5 81            [12]  932 	mov	a,sp
      00027A F5 10            [12]  933 	mov	_bp,a
      00027C 24 04            [12]  934 	add	a,#0x04
      00027E F5 81            [12]  935 	mov	sp,a
      000280 AF 82            [24]  936 	mov	r7, dpl
                           0001C5   937 	C$fuzzy.h$137$1_0$41 ==.
                                    938 ;	../../fuzzy.h:137: if (method == FUZZY_LOGIC_ALGEBRAIC) {
      000282 BF 01 02         [24]  939 	cjne	r7,#0x01,00135$
      000285 80 03            [24]  940 	sjmp	00136$
      000287                        941 00135$:
      000287 02 03 25         [24]  942 	ljmp	00102$
      00028A                        943 00136$:
                           0001CD   944 	C$fuzzy.h$138$1_0$41 ==.
                                    945 ;	../../fuzzy.h:138: return a + b - a * b;
      00028A E5 10            [12]  946 	mov	a,_bp
      00028C 24 F6            [12]  947 	add	a,#0xf6
      00028E F8               [12]  948 	mov	r0,a
      00028F E6               [12]  949 	mov	a,@r0
      000290 C0 E0            [24]  950 	push	acc
      000292 08               [12]  951 	inc	r0
      000293 E6               [12]  952 	mov	a,@r0
      000294 C0 E0            [24]  953 	push	acc
      000296 08               [12]  954 	inc	r0
      000297 E6               [12]  955 	mov	a,@r0
      000298 C0 E0            [24]  956 	push	acc
      00029A 08               [12]  957 	inc	r0
      00029B E6               [12]  958 	mov	a,@r0
      00029C C0 E0            [24]  959 	push	acc
      00029E E5 10            [12]  960 	mov	a,_bp
      0002A0 24 FA            [12]  961 	add	a,#0xfa
      0002A2 F8               [12]  962 	mov	r0,a
      0002A3 86 82            [24]  963 	mov	dpl, @r0
      0002A5 08               [12]  964 	inc	r0
      0002A6 86 83            [24]  965 	mov	dph, @r0
      0002A8 08               [12]  966 	inc	r0
      0002A9 86 F0            [24]  967 	mov	b, @r0
      0002AB 08               [12]  968 	inc	r0
      0002AC E6               [12]  969 	mov	a, @r0
      0002AD 12 2C 15         [24]  970 	lcall	___fsadd
      0002B0 A8 10            [24]  971 	mov	r0,_bp
      0002B2 08               [12]  972 	inc	r0
      0002B3 A6 82            [24]  973 	mov	@r0, dpl
      0002B5 08               [12]  974 	inc	r0
      0002B6 A6 83            [24]  975 	mov	@r0, dph
      0002B8 08               [12]  976 	inc	r0
      0002B9 A6 F0            [24]  977 	mov	@r0, b
      0002BB 08               [12]  978 	inc	r0
      0002BC F6               [12]  979 	mov	@r0,a
      0002BD E5 81            [12]  980 	mov	a,sp
      0002BF 24 FC            [12]  981 	add	a,#0xfc
      0002C1 F5 81            [12]  982 	mov	sp,a
      0002C3 E5 10            [12]  983 	mov	a,_bp
      0002C5 24 F6            [12]  984 	add	a,#0xf6
      0002C7 F8               [12]  985 	mov	r0,a
      0002C8 E6               [12]  986 	mov	a,@r0
      0002C9 C0 E0            [24]  987 	push	acc
      0002CB 08               [12]  988 	inc	r0
      0002CC E6               [12]  989 	mov	a,@r0
      0002CD C0 E0            [24]  990 	push	acc
      0002CF 08               [12]  991 	inc	r0
      0002D0 E6               [12]  992 	mov	a,@r0
      0002D1 C0 E0            [24]  993 	push	acc
      0002D3 08               [12]  994 	inc	r0
      0002D4 E6               [12]  995 	mov	a,@r0
      0002D5 C0 E0            [24]  996 	push	acc
      0002D7 E5 10            [12]  997 	mov	a,_bp
      0002D9 24 FA            [12]  998 	add	a,#0xfa
      0002DB F8               [12]  999 	mov	r0,a
      0002DC 86 82            [24] 1000 	mov	dpl, @r0
      0002DE 08               [12] 1001 	inc	r0
      0002DF 86 83            [24] 1002 	mov	dph, @r0
      0002E1 08               [12] 1003 	inc	r0
      0002E2 86 F0            [24] 1004 	mov	b, @r0
      0002E4 08               [12] 1005 	inc	r0
      0002E5 E6               [12] 1006 	mov	a, @r0
      0002E6 12 2A B5         [24] 1007 	lcall	___fsmul
      0002E9 AA 82            [24] 1008 	mov	r2, dpl
      0002EB AC 83            [24] 1009 	mov	r4, dph
      0002ED AD F0            [24] 1010 	mov	r5, b
      0002EF FE               [12] 1011 	mov	r6, a
      0002F0 E5 81            [12] 1012 	mov	a,sp
      0002F2 24 FC            [12] 1013 	add	a,#0xfc
      0002F4 F5 81            [12] 1014 	mov	sp,a
      0002F6 C0 02            [24] 1015 	push	ar2
      0002F8 C0 04            [24] 1016 	push	ar4
      0002FA C0 05            [24] 1017 	push	ar5
      0002FC C0 06            [24] 1018 	push	ar6
      0002FE A8 10            [24] 1019 	mov	r0,_bp
      000300 08               [12] 1020 	inc	r0
      000301 86 82            [24] 1021 	mov	dpl, @r0
      000303 08               [12] 1022 	inc	r0
      000304 86 83            [24] 1023 	mov	dph, @r0
      000306 08               [12] 1024 	inc	r0
      000307 86 F0            [24] 1025 	mov	b, @r0
      000309 08               [12] 1026 	inc	r0
      00030A E6               [12] 1027 	mov	a, @r0
      00030B 12 2A AA         [24] 1028 	lcall	___fssub
      00030E AB 82            [24] 1029 	mov	r3, dpl
      000310 AC 83            [24] 1030 	mov	r4, dph
      000312 AD F0            [24] 1031 	mov	r5, b
      000314 FE               [12] 1032 	mov	r6, a
      000315 E5 81            [12] 1033 	mov	a,sp
      000317 24 FC            [12] 1034 	add	a,#0xfc
      000319 F5 81            [12] 1035 	mov	sp,a
      00031B 8B 82            [24] 1036 	mov	dpl, r3
      00031D 8C 83            [24] 1037 	mov	dph, r4
      00031F 8D F0            [24] 1038 	mov	b, r5
      000321 EE               [12] 1039 	mov	a, r6
      000322 02 03 FA         [24] 1040 	ljmp	00105$
      000325                       1041 00102$:
                           000268  1042 	C$fuzzy.h$141$1_0$41 ==.
                                   1043 ;	../../fuzzy.h:141: if (method == FUZZY_LOGIC_BOUNDED) {
      000325 BF 02 78         [24] 1044 	cjne	r7,#0x02,00104$
                           00026B  1045 	C$fuzzy.h$142$1_0$41 ==.
                                   1046 ;	../../fuzzy.h:142: float value = a + b;
      000328 E5 10            [12] 1047 	mov	a,_bp
      00032A 24 F6            [12] 1048 	add	a,#0xf6
      00032C F8               [12] 1049 	mov	r0,a
      00032D E6               [12] 1050 	mov	a,@r0
      00032E C0 E0            [24] 1051 	push	acc
      000330 08               [12] 1052 	inc	r0
      000331 E6               [12] 1053 	mov	a,@r0
      000332 C0 E0            [24] 1054 	push	acc
      000334 08               [12] 1055 	inc	r0
      000335 E6               [12] 1056 	mov	a,@r0
      000336 C0 E0            [24] 1057 	push	acc
      000338 08               [12] 1058 	inc	r0
      000339 E6               [12] 1059 	mov	a,@r0
      00033A C0 E0            [24] 1060 	push	acc
                           00027F  1061 	C$fuzzy.h$143$1_0$41 ==.
                                   1062 ;	../../fuzzy.h:143: return value < 1.0f ? value : 1.0f;
      00033C E5 10            [12] 1063 	mov	a,_bp
      00033E 24 FA            [12] 1064 	add	a,#0xfa
      000340 F8               [12] 1065 	mov	r0,a
      000341 86 82            [24] 1066 	mov	dpl, @r0
      000343 08               [12] 1067 	inc	r0
      000344 86 83            [24] 1068 	mov	dph, @r0
      000346 08               [12] 1069 	inc	r0
      000347 86 F0            [24] 1070 	mov	b, @r0
      000349 08               [12] 1071 	inc	r0
      00034A E6               [12] 1072 	mov	a, @r0
      00034B 12 2C 15         [24] 1073 	lcall	___fsadd
      00034E AC 82            [24] 1074 	mov	r4, dpl
      000350 AD 83            [24] 1075 	mov	r5, dph
      000352 AE F0            [24] 1076 	mov	r6, b
      000354 FF               [12] 1077 	mov	r7, a
      000355 E5 81            [12] 1078 	mov	a,sp
      000357 24 FC            [12] 1079 	add	a,#0xfc
      000359 F5 81            [12] 1080 	mov	sp,a
      00035B C0 07            [24] 1081 	push	ar7
      00035D C0 06            [24] 1082 	push	ar6
      00035F C0 05            [24] 1083 	push	ar5
      000361 C0 04            [24] 1084 	push	ar4
      000363 E4               [12] 1085 	clr	a
      000364 C0 E0            [24] 1086 	push	acc
      000366 C0 E0            [24] 1087 	push	acc
      000368 74 80            [12] 1088 	mov	a,#0x80
      00036A C0 E0            [24] 1089 	push	acc
      00036C 74 3F            [12] 1090 	mov	a,#0x3f
      00036E C0 E0            [24] 1091 	push	acc
      000370 8C 82            [24] 1092 	mov	dpl, r4
      000372 8D 83            [24] 1093 	mov	dph, r5
      000374 8E F0            [24] 1094 	mov	b, r6
      000376 EF               [12] 1095 	mov	a, r7
      000377 12 2B E5         [24] 1096 	lcall	___fslt
      00037A AB 82            [24] 1097 	mov	r3, dpl
      00037C E5 81            [12] 1098 	mov	a,sp
      00037E 24 FC            [12] 1099 	add	a,#0xfc
      000380 F5 81            [12] 1100 	mov	sp,a
      000382 D0 04            [24] 1101 	pop	ar4
      000384 D0 05            [24] 1102 	pop	ar5
      000386 D0 06            [24] 1103 	pop	ar6
      000388 D0 07            [24] 1104 	pop	ar7
      00038A EB               [12] 1105 	mov	a,r3
      00038B 60 02            [24] 1106 	jz	00107$
      00038D 80 08            [24] 1107 	sjmp	00108$
      00038F                       1108 00107$:
      00038F 7C 00            [12] 1109 	mov	r4,#0x00
      000391 7D 00            [12] 1110 	mov	r5,#0x00
      000393 7E 80            [12] 1111 	mov	r6,#0x80
      000395 7F 3F            [12] 1112 	mov	r7,#0x3f
      000397                       1113 00108$:
      000397 8C 82            [24] 1114 	mov	dpl, r4
      000399 8D 83            [24] 1115 	mov	dph, r5
      00039B 8E F0            [24] 1116 	mov	b, r6
      00039D EF               [12] 1117 	mov	a, r7
      00039E 80 5A            [24] 1118 	sjmp	00105$
      0003A0                       1119 00104$:
                           0002E3  1120 	C$fuzzy.h$146$1_0$41 ==.
                                   1121 ;	../../fuzzy.h:146: return a > b ? a : b;
      0003A0 E5 10            [12] 1122 	mov	a,_bp
      0003A2 24 FA            [12] 1123 	add	a,#0xfa
      0003A4 F8               [12] 1124 	mov	r0,a
      0003A5 E6               [12] 1125 	mov	a,@r0
      0003A6 C0 E0            [24] 1126 	push	acc
      0003A8 08               [12] 1127 	inc	r0
      0003A9 E6               [12] 1128 	mov	a,@r0
      0003AA C0 E0            [24] 1129 	push	acc
      0003AC 08               [12] 1130 	inc	r0
      0003AD E6               [12] 1131 	mov	a,@r0
      0003AE C0 E0            [24] 1132 	push	acc
      0003B0 08               [12] 1133 	inc	r0
      0003B1 E6               [12] 1134 	mov	a,@r0
      0003B2 C0 E0            [24] 1135 	push	acc
      0003B4 E5 10            [12] 1136 	mov	a,_bp
      0003B6 24 F6            [12] 1137 	add	a,#0xf6
      0003B8 F8               [12] 1138 	mov	r0,a
      0003B9 86 82            [24] 1139 	mov	dpl, @r0
      0003BB 08               [12] 1140 	inc	r0
      0003BC 86 83            [24] 1141 	mov	dph, @r0
      0003BE 08               [12] 1142 	inc	r0
      0003BF 86 F0            [24] 1143 	mov	b, @r0
      0003C1 08               [12] 1144 	inc	r0
      0003C2 E6               [12] 1145 	mov	a, @r0
      0003C3 12 2B E5         [24] 1146 	lcall	___fslt
      0003C6 AF 82            [24] 1147 	mov	r7, dpl
      0003C8 E5 81            [12] 1148 	mov	a,sp
      0003CA 24 FC            [12] 1149 	add	a,#0xfc
      0003CC F5 81            [12] 1150 	mov	sp,a
      0003CE EF               [12] 1151 	mov	a,r7
      0003CF 60 12            [24] 1152 	jz	00109$
      0003D1 E5 10            [12] 1153 	mov	a,_bp
      0003D3 24 FA            [12] 1154 	add	a,#0xfa
      0003D5 F8               [12] 1155 	mov	r0,a
      0003D6 86 04            [24] 1156 	mov	ar4,@r0
      0003D8 08               [12] 1157 	inc	r0
      0003D9 86 05            [24] 1158 	mov	ar5,@r0
      0003DB 08               [12] 1159 	inc	r0
      0003DC 86 06            [24] 1160 	mov	ar6,@r0
      0003DE 08               [12] 1161 	inc	r0
      0003DF 86 07            [24] 1162 	mov	ar7,@r0
      0003E1 80 10            [24] 1163 	sjmp	00110$
      0003E3                       1164 00109$:
      0003E3 E5 10            [12] 1165 	mov	a,_bp
      0003E5 24 F6            [12] 1166 	add	a,#0xf6
      0003E7 F8               [12] 1167 	mov	r0,a
      0003E8 86 04            [24] 1168 	mov	ar4,@r0
      0003EA 08               [12] 1169 	inc	r0
      0003EB 86 05            [24] 1170 	mov	ar5,@r0
      0003ED 08               [12] 1171 	inc	r0
      0003EE 86 06            [24] 1172 	mov	ar6,@r0
      0003F0 08               [12] 1173 	inc	r0
      0003F1 86 07            [24] 1174 	mov	ar7,@r0
      0003F3                       1175 00110$:
      0003F3 8C 82            [24] 1176 	mov	dpl, r4
      0003F5 8D 83            [24] 1177 	mov	dph, r5
      0003F7 8E F0            [24] 1178 	mov	b, r6
      0003F9 EF               [12] 1179 	mov	a, r7
      0003FA                       1180 00105$:
                           00033D  1181 	C$fuzzy.h$147$1_0$41 ==.
                                   1182 ;	../../fuzzy.h:147: }
      0003FA 85 10 81         [24] 1183 	mov	sp,_bp
      0003FD D0 10            [24] 1184 	pop	_bp
                           000342  1185 	C$fuzzy.h$147$1_0$41 ==.
                           000342  1186 	XFsugeno_demo$fuzzy_8051_or2$0$0 ==.
      0003FF 22               [24] 1187 	ret
                                   1188 ;------------------------------------------------------------
                                   1189 ;Allocation info for local variables in function 'fuzzy_8051_or3'
                                   1190 ;------------------------------------------------------------
                                   1191 ;a             Allocated to stack - _bp -6 +4 
                                   1192 ;b             Allocated to stack - _bp -10 +4 
                                   1193 ;c             Allocated to stack - _bp -14 +4 
                                   1194 ;method        Allocated to registers r7 
                                   1195 ;------------------------------------------------------------
                           000343  1196 	Fsugeno_demo$fuzzy_8051_or3$0$0 ==.
                           000343  1197 	C$fuzzy.h$149$1_0$45 ==.
                                   1198 ;	../../fuzzy.h:149: static float fuzzy_8051_or3(fuzzy_logic_method_t method, float a, float b, float c)
                                   1199 ;	-----------------------------------------
                                   1200 ;	 function fuzzy_8051_or3
                                   1201 ;	-----------------------------------------
      000400                       1202 _fuzzy_8051_or3:
      000400 C0 10            [24] 1203 	push	_bp
      000402 85 81 10         [24] 1204 	mov	_bp,sp
      000405 AF 82            [24] 1205 	mov	r7, dpl
                           00034A  1206 	C$fuzzy.h$151$1_0$45 ==.
                                   1207 ;	../../fuzzy.h:151: return fuzzy_8051_or2(method, fuzzy_8051_or2(method, a, b), c);
      000407 C0 07            [24] 1208 	push	ar7
      000409 E5 10            [12] 1209 	mov	a,_bp
      00040B 24 F6            [12] 1210 	add	a,#0xf6
      00040D F8               [12] 1211 	mov	r0,a
      00040E E6               [12] 1212 	mov	a,@r0
      00040F C0 E0            [24] 1213 	push	acc
      000411 08               [12] 1214 	inc	r0
      000412 E6               [12] 1215 	mov	a,@r0
      000413 C0 E0            [24] 1216 	push	acc
      000415 08               [12] 1217 	inc	r0
      000416 E6               [12] 1218 	mov	a,@r0
      000417 C0 E0            [24] 1219 	push	acc
      000419 08               [12] 1220 	inc	r0
      00041A E6               [12] 1221 	mov	a,@r0
      00041B C0 E0            [24] 1222 	push	acc
      00041D E5 10            [12] 1223 	mov	a,_bp
      00041F 24 FA            [12] 1224 	add	a,#0xfa
      000421 F8               [12] 1225 	mov	r0,a
      000422 E6               [12] 1226 	mov	a,@r0
      000423 C0 E0            [24] 1227 	push	acc
      000425 08               [12] 1228 	inc	r0
      000426 E6               [12] 1229 	mov	a,@r0
      000427 C0 E0            [24] 1230 	push	acc
      000429 08               [12] 1231 	inc	r0
      00042A E6               [12] 1232 	mov	a,@r0
      00042B C0 E0            [24] 1233 	push	acc
      00042D 08               [12] 1234 	inc	r0
      00042E E6               [12] 1235 	mov	a,@r0
      00042F C0 E0            [24] 1236 	push	acc
      000431 8F 82            [24] 1237 	mov	dpl, r7
      000433 12 02 76         [24] 1238 	lcall	_fuzzy_8051_or2
      000436 AB 82            [24] 1239 	mov	r3, dpl
      000438 AC 83            [24] 1240 	mov	r4, dph
      00043A AD F0            [24] 1241 	mov	r5, b
      00043C FE               [12] 1242 	mov	r6, a
      00043D E5 81            [12] 1243 	mov	a,sp
      00043F 24 F8            [12] 1244 	add	a,#0xf8
      000441 F5 81            [12] 1245 	mov	sp,a
      000443 D0 07            [24] 1246 	pop	ar7
      000445 E5 10            [12] 1247 	mov	a,_bp
      000447 24 F2            [12] 1248 	add	a,#0xf2
      000449 F8               [12] 1249 	mov	r0,a
      00044A E6               [12] 1250 	mov	a,@r0
      00044B C0 E0            [24] 1251 	push	acc
      00044D 08               [12] 1252 	inc	r0
      00044E E6               [12] 1253 	mov	a,@r0
      00044F C0 E0            [24] 1254 	push	acc
      000451 08               [12] 1255 	inc	r0
      000452 E6               [12] 1256 	mov	a,@r0
      000453 C0 E0            [24] 1257 	push	acc
      000455 08               [12] 1258 	inc	r0
      000456 E6               [12] 1259 	mov	a,@r0
      000457 C0 E0            [24] 1260 	push	acc
      000459 C0 03            [24] 1261 	push	ar3
      00045B C0 04            [24] 1262 	push	ar4
      00045D C0 05            [24] 1263 	push	ar5
      00045F C0 06            [24] 1264 	push	ar6
      000461 8F 82            [24] 1265 	mov	dpl, r7
      000463 12 02 76         [24] 1266 	lcall	_fuzzy_8051_or2
      000466 AC 82            [24] 1267 	mov	r4, dpl
      000468 AD 83            [24] 1268 	mov	r5, dph
      00046A AE F0            [24] 1269 	mov	r6, b
      00046C FF               [12] 1270 	mov	r7, a
      00046D E5 81            [12] 1271 	mov	a,sp
      00046F 24 F8            [12] 1272 	add	a,#0xf8
      000471 F5 81            [12] 1273 	mov	sp,a
      000473 8C 82            [24] 1274 	mov	dpl, r4
      000475 8D 83            [24] 1275 	mov	dph, r5
      000477 8E F0            [24] 1276 	mov	b, r6
      000479 EF               [12] 1277 	mov	a, r7
                           0003BD  1278 	C$fuzzy.h$152$1_0$45 ==.
                                   1279 ;	../../fuzzy.h:152: }
      00047A D0 10            [24] 1280 	pop	_bp
                           0003BF  1281 	C$fuzzy.h$152$1_0$45 ==.
                           0003BF  1282 	XFsugeno_demo$fuzzy_8051_or3$0$0 ==.
      00047C 22               [24] 1283 	ret
                                   1284 ;------------------------------------------------------------
                                   1285 ;Allocation info for local variables in function 'fuzzy_8051_clamp'
                                   1286 ;------------------------------------------------------------
                                   1287 ;value         Allocated to registers r4 r5 r6 r7 
                                   1288 ;------------------------------------------------------------
                           0003C0  1289 	Fsugeno_demo$fuzzy_8051_clamp$0$0 ==.
                           0003C0  1290 	C$fuzzy.h$162$1_0$47 ==.
                                   1291 ;	../../fuzzy.h:162: static float fuzzy_8051_clamp(float value)
                                   1292 ;	-----------------------------------------
                                   1293 ;	 function fuzzy_8051_clamp
                                   1294 ;	-----------------------------------------
      00047D                       1295 _fuzzy_8051_clamp:
      00047D AC 82            [24] 1296 	mov	r4,dpl
      00047F AD 83            [24] 1297 	mov	r5,dph
      000481 AE F0            [24] 1298 	mov	r6,b
      000483 FF               [12] 1299 	mov	r7,a
                           0003C7  1300 	C$fuzzy.h$164$1_0$47 ==.
                                   1301 ;	../../fuzzy.h:164: if (value < 0.0f) {
      000484 C0 07            [24] 1302 	push	ar7
      000486 C0 06            [24] 1303 	push	ar6
      000488 C0 05            [24] 1304 	push	ar5
      00048A C0 04            [24] 1305 	push	ar4
      00048C E4               [12] 1306 	clr	a
      00048D C0 E0            [24] 1307 	push	acc
      00048F C0 E0            [24] 1308 	push	acc
      000491 C0 E0            [24] 1309 	push	acc
      000493 C0 E0            [24] 1310 	push	acc
      000495 8C 82            [24] 1311 	mov	dpl, r4
      000497 8D 83            [24] 1312 	mov	dph, r5
      000499 8E F0            [24] 1313 	mov	b, r6
      00049B EF               [12] 1314 	mov	a, r7
      00049C 12 2B E5         [24] 1315 	lcall	___fslt
      00049F AB 82            [24] 1316 	mov	r3, dpl
      0004A1 E5 81            [12] 1317 	mov	a,sp
      0004A3 24 FC            [12] 1318 	add	a,#0xfc
      0004A5 F5 81            [12] 1319 	mov	sp,a
      0004A7 D0 04            [24] 1320 	pop	ar4
      0004A9 D0 05            [24] 1321 	pop	ar5
      0004AB D0 06            [24] 1322 	pop	ar6
      0004AD D0 07            [24] 1323 	pop	ar7
      0004AF EB               [12] 1324 	mov	a,r3
      0004B0 60 08            [24] 1325 	jz	00102$
                           0003F5  1326 	C$fuzzy.h$165$2_0$48 ==.
                                   1327 ;	../../fuzzy.h:165: return 0.0f;
      0004B2 90 00 00         [24] 1328 	mov	dptr,#0x0000
      0004B5 E4               [12] 1329 	clr	a
      0004B6 F5 F0            [12] 1330 	mov	b,a
      0004B8 80 3F            [24] 1331 	sjmp	00105$
      0004BA                       1332 00102$:
                           0003FD  1333 	C$fuzzy.h$168$1_0$47 ==.
                                   1334 ;	../../fuzzy.h:168: if (value > 1.0f) {
      0004BA C0 07            [24] 1335 	push	ar7
      0004BC C0 06            [24] 1336 	push	ar6
      0004BE C0 05            [24] 1337 	push	ar5
      0004C0 C0 04            [24] 1338 	push	ar4
      0004C2 C0 04            [24] 1339 	push	ar4
      0004C4 C0 05            [24] 1340 	push	ar5
      0004C6 C0 06            [24] 1341 	push	ar6
      0004C8 C0 07            [24] 1342 	push	ar7
      0004CA 90 00 00         [24] 1343 	mov	dptr,#0x0000
      0004CD 75 F0 80         [24] 1344 	mov	b, #0x80
      0004D0 74 3F            [12] 1345 	mov	a, #0x3f
      0004D2 12 2B E5         [24] 1346 	lcall	___fslt
      0004D5 AB 82            [24] 1347 	mov	r3, dpl
      0004D7 E5 81            [12] 1348 	mov	a,sp
      0004D9 24 FC            [12] 1349 	add	a,#0xfc
      0004DB F5 81            [12] 1350 	mov	sp,a
      0004DD D0 04            [24] 1351 	pop	ar4
      0004DF D0 05            [24] 1352 	pop	ar5
      0004E1 D0 06            [24] 1353 	pop	ar6
      0004E3 D0 07            [24] 1354 	pop	ar7
      0004E5 EB               [12] 1355 	mov	a,r3
      0004E6 60 0A            [24] 1356 	jz	00104$
                           00042B  1357 	C$fuzzy.h$169$2_0$49 ==.
                                   1358 ;	../../fuzzy.h:169: return 1.0f;
      0004E8 90 00 00         [24] 1359 	mov	dptr,#0x0000
      0004EB 75 F0 80         [24] 1360 	mov	b, #0x80
      0004EE 74 3F            [12] 1361 	mov	a, #0x3f
      0004F0 80 07            [24] 1362 	sjmp	00105$
      0004F2                       1363 00104$:
                           000435  1364 	C$fuzzy.h$172$1_0$47 ==.
                                   1365 ;	../../fuzzy.h:172: return value;
      0004F2 8C 82            [24] 1366 	mov	dpl, r4
      0004F4 8D 83            [24] 1367 	mov	dph, r5
      0004F6 8E F0            [24] 1368 	mov	b, r6
      0004F8 EF               [12] 1369 	mov	a, r7
      0004F9                       1370 00105$:
                           00043C  1371 	C$fuzzy.h$173$1_0$47 ==.
                                   1372 ;	../../fuzzy.h:173: }
                           00043C  1373 	C$fuzzy.h$173$1_0$47 ==.
                           00043C  1374 	XFsugeno_demo$fuzzy_8051_clamp$0$0 ==.
      0004F9 22               [24] 1375 	ret
                                   1376 ;------------------------------------------------------------
                                   1377 ;Allocation info for local variables in function 'fuzzy_8051_hedge'
                                   1378 ;------------------------------------------------------------
                                   1379 ;hedge         Allocated to stack - _bp -3 +1 
                                   1380 ;value         Allocated to stack - _bp +1 +4 
                                   1381 ;result        Allocated to registers r2 r3 r6 r7 
                                   1382 ;------------------------------------------------------------
                           00043D  1383 	Fsugeno_demo$fuzzy_8051_hedge$0$0 ==.
                           00043D  1384 	C$fuzzy.h$175$1_0$51 ==.
                                   1385 ;	../../fuzzy.h:175: static float fuzzy_8051_hedge(float value, fuzzy_hedge_t hedge)
                                   1386 ;	-----------------------------------------
                                   1387 ;	 function fuzzy_8051_hedge
                                   1388 ;	-----------------------------------------
      0004FA                       1389 _fuzzy_8051_hedge:
      0004FA C0 10            [24] 1390 	push	_bp
      0004FC 85 81 10         [24] 1391 	mov	_bp,sp
      0004FF AC 82            [24] 1392 	mov	r4,dpl
      000501 AD 83            [24] 1393 	mov	r5,dph
      000503 AE F0            [24] 1394 	mov	r6,b
      000505 FF               [12] 1395 	mov	r7,a
      000506 E5 81            [12] 1396 	mov	a,sp
      000508 24 04            [12] 1397 	add	a,#0x04
      00050A F5 81            [12] 1398 	mov	sp,a
                           00044F  1399 	C$fuzzy.h$179$1_0$51 ==.
                                   1400 ;	../../fuzzy.h:179: value = fuzzy_8051_clamp(value);
      00050C 8C 82            [24] 1401 	mov	dpl, r4
      00050E 8D 83            [24] 1402 	mov	dph, r5
      000510 8E F0            [24] 1403 	mov	b, r6
      000512 EF               [12] 1404 	mov	a, r7
      000513 12 04 7D         [24] 1405 	lcall	_fuzzy_8051_clamp
      000516 A8 10            [24] 1406 	mov	r0,_bp
      000518 08               [12] 1407 	inc	r0
      000519 A6 82            [24] 1408 	mov	@r0, dpl
      00051B 08               [12] 1409 	inc	r0
      00051C A6 83            [24] 1410 	mov	@r0, dph
      00051E 08               [12] 1411 	inc	r0
      00051F A6 F0            [24] 1412 	mov	@r0, b
      000521 08               [12] 1413 	inc	r0
      000522 F6               [12] 1414 	mov	@r0,a
                           000466  1415 	C$fuzzy.h$181$1_0$51 ==.
                                   1416 ;	../../fuzzy.h:181: if (hedge == 0u) {
      000523 E5 10            [12] 1417 	mov	a,_bp
      000525 24 FD            [12] 1418 	add	a,#0xfd
      000527 F8               [12] 1419 	mov	r0,a
      000528 E6               [12] 1420 	mov	a,@r0
      000529 70 07            [24] 1421 	jnz	00102$
                           00046E  1422 	C$fuzzy.h$182$2_0$52 ==.
                                   1423 ;	../../fuzzy.h:182: hedge = 1u;
      00052B E5 10            [12] 1424 	mov	a,_bp
      00052D 24 FD            [12] 1425 	add	a,#0xfd
      00052F F8               [12] 1426 	mov	r0,a
      000530 76 01            [12] 1427 	mov	@r0,#0x01
      000532                       1428 00102$:
                           000475  1429 	C$fuzzy.h$185$1_0$51 ==.
                                   1430 ;	../../fuzzy.h:185: result = 1.0f;
      000532 7A 00            [12] 1431 	mov	r2,#0x00
      000534 7B 00            [12] 1432 	mov	r3,#0x00
      000536 7E 80            [12] 1433 	mov	r6,#0x80
      000538 7F 3F            [12] 1434 	mov	r7,#0x3f
                           00047D  1435 	C$fuzzy.h$187$1_0$51 ==.
                                   1436 ;	../../fuzzy.h:187: while (hedge != 0u) {
      00053A E5 10            [12] 1437 	mov	a,_bp
      00053C 24 FD            [12] 1438 	add	a,#0xfd
      00053E F8               [12] 1439 	mov	r0,a
      00053F 86 05            [24] 1440 	mov	ar5,@r0
      000541                       1441 00103$:
      000541 ED               [12] 1442 	mov	a,r5
      000542 60 30            [24] 1443 	jz	00105$
                           000487  1444 	C$fuzzy.h$188$1_0$51 ==.
                                   1445 ;	../../fuzzy.h:188: result *= value;
      000544 C0 05            [24] 1446 	push	ar5
      000546 A8 10            [24] 1447 	mov	r0,_bp
      000548 08               [12] 1448 	inc	r0
      000549 E6               [12] 1449 	mov	a,@r0
      00054A C0 E0            [24] 1450 	push	acc
      00054C 08               [12] 1451 	inc	r0
      00054D E6               [12] 1452 	mov	a,@r0
      00054E C0 E0            [24] 1453 	push	acc
      000550 08               [12] 1454 	inc	r0
      000551 E6               [12] 1455 	mov	a,@r0
      000552 C0 E0            [24] 1456 	push	acc
      000554 08               [12] 1457 	inc	r0
      000555 E6               [12] 1458 	mov	a,@r0
      000556 C0 E0            [24] 1459 	push	acc
                           00049B  1460 	C$fuzzy.h$189$1_0$51 ==.
                                   1461 ;	../../fuzzy.h:189: --hedge;
      000558 8A 82            [24] 1462 	mov	dpl, r2
      00055A 8B 83            [24] 1463 	mov	dph, r3
      00055C 8E F0            [24] 1464 	mov	b, r6
      00055E EF               [12] 1465 	mov	a, r7
      00055F 12 2A B5         [24] 1466 	lcall	___fsmul
      000562 AA 82            [24] 1467 	mov	r2, dpl
      000564 AB 83            [24] 1468 	mov	r3, dph
      000566 AE F0            [24] 1469 	mov	r6, b
      000568 FF               [12] 1470 	mov	r7, a
      000569 E5 81            [12] 1471 	mov	a,sp
      00056B 24 FC            [12] 1472 	add	a,#0xfc
      00056D F5 81            [12] 1473 	mov	sp,a
      00056F D0 05            [24] 1474 	pop	ar5
      000571 1D               [12] 1475 	dec	r5
      000572 80 CD            [24] 1476 	sjmp	00103$
      000574                       1477 00105$:
                           0004B7  1478 	C$fuzzy.h$192$1_0$51 ==.
                                   1479 ;	../../fuzzy.h:192: return fuzzy_8051_clamp(result);
      000574 8A 82            [24] 1480 	mov	dpl, r2
      000576 8B 83            [24] 1481 	mov	dph, r3
      000578 8E F0            [24] 1482 	mov	b, r6
      00057A EF               [12] 1483 	mov	a, r7
      00057B 12 04 7D         [24] 1484 	lcall	_fuzzy_8051_clamp
                           0004C1  1485 	C$fuzzy.h$193$1_0$51 ==.
                                   1486 ;	../../fuzzy.h:193: }
      00057E 85 10 81         [24] 1487 	mov	sp,_bp
      000581 D0 10            [24] 1488 	pop	_bp
                           0004C6  1489 	C$fuzzy.h$193$1_0$51 ==.
                           0004C6  1490 	XFsugeno_demo$fuzzy_8051_hedge$0$0 ==.
      000583 22               [24] 1491 	ret
                                   1492 ;------------------------------------------------------------
                                   1493 ;Allocation info for local variables in function 'fuzzy_not'
                                   1494 ;------------------------------------------------------------
                                   1495 ;membership    Allocated to registers r4 r5 r6 r7 
                                   1496 ;------------------------------------------------------------
                           0004C7  1497 	G$fuzzy_not$0$0 ==.
                           0004C7  1498 	C$fuzzy.h$195$1_0$55 ==.
                                   1499 ;	../../fuzzy.h:195: float fuzzy_not(float membership)
                                   1500 ;	-----------------------------------------
                                   1501 ;	 function fuzzy_not
                                   1502 ;	-----------------------------------------
      000584                       1503 _fuzzy_not:
                           0004C7  1504 	C$fuzzy.h$197$1_0$55 ==.
                                   1505 ;	../../fuzzy.h:197: return 1.0f - fuzzy_8051_clamp(membership);
      000584 12 04 7D         [24] 1506 	lcall	_fuzzy_8051_clamp
      000587 AC 82            [24] 1507 	mov	r4, dpl
      000589 AD 83            [24] 1508 	mov	r5, dph
      00058B AE F0            [24] 1509 	mov	r6, b
      00058D FF               [12] 1510 	mov	r7, a
      00058E C0 04            [24] 1511 	push	ar4
      000590 C0 05            [24] 1512 	push	ar5
      000592 C0 06            [24] 1513 	push	ar6
      000594 C0 07            [24] 1514 	push	ar7
      000596 90 00 00         [24] 1515 	mov	dptr,#0x0000
      000599 75 F0 80         [24] 1516 	mov	b, #0x80
      00059C 74 3F            [12] 1517 	mov	a, #0x3f
      00059E 12 2A AA         [24] 1518 	lcall	___fssub
      0005A1 AC 82            [24] 1519 	mov	r4, dpl
      0005A3 AD 83            [24] 1520 	mov	r5, dph
      0005A5 AE F0            [24] 1521 	mov	r6, b
      0005A7 FF               [12] 1522 	mov	r7, a
      0005A8 E5 81            [12] 1523 	mov	a,sp
      0005AA 24 FC            [12] 1524 	add	a,#0xfc
      0005AC F5 81            [12] 1525 	mov	sp,a
      0005AE 8C 82            [24] 1526 	mov	dpl, r4
      0005B0 8D 83            [24] 1527 	mov	dph, r5
      0005B2 8E F0            [24] 1528 	mov	b, r6
      0005B4 EF               [12] 1529 	mov	a, r7
                           0004F8  1530 	C$fuzzy.h$198$1_0$55 ==.
                                   1531 ;	../../fuzzy.h:198: }
                           0004F8  1532 	C$fuzzy.h$198$1_0$55 ==.
                           0004F8  1533 	XG$fuzzy_not$0$0 ==.
      0005B5 22               [24] 1534 	ret
                                   1535 ;------------------------------------------------------------
                                   1536 ;Allocation info for local variables in function 'fuzzy_ramp'
                                   1537 ;------------------------------------------------------------
                                   1538 ;b             Allocated to stack - _bp -6 +4 
                                   1539 ;x             Allocated to stack - _bp -10 +4 
                                   1540 ;up            Allocated to stack - _bp -11 +1 
                                   1541 ;hedge         Allocated to stack - _bp -12 +1 
                                   1542 ;a             Allocated to registers r7 r6 r5 r4 
                                   1543 ;result        Allocated to stack - _bp +5 +4 
                                   1544 ;sloc0         Allocated to stack - _bp +1 +4 
                                   1545 ;------------------------------------------------------------
                           0004F9  1546 	G$fuzzy_ramp$0$0 ==.
                           0004F9  1547 	C$fuzzy.h$200$1_0$57 ==.
                                   1548 ;	../../fuzzy.h:200: float fuzzy_ramp(float a, float b, float x, bool up, fuzzy_hedge_t hedge)
                                   1549 ;	-----------------------------------------
                                   1550 ;	 function fuzzy_ramp
                                   1551 ;	-----------------------------------------
      0005B6                       1552 _fuzzy_ramp:
      0005B6 C0 10            [24] 1553 	push	_bp
      0005B8 85 81 10         [24] 1554 	mov	_bp,sp
      0005BB AF 82            [24] 1555 	mov	r7,dpl
      0005BD AE 83            [24] 1556 	mov	r6,dph
      0005BF AD F0            [24] 1557 	mov	r5,b
      0005C1 FC               [12] 1558 	mov	r4,a
      0005C2 E5 81            [12] 1559 	mov	a,sp
      0005C4 24 08            [12] 1560 	add	a,#0x08
      0005C6 F5 81            [12] 1561 	mov	sp,a
                           00050B  1562 	C$fuzzy.h$204$1_0$57 ==.
                                   1563 ;	../../fuzzy.h:204: if (a >= b) {
      0005C8 C0 07            [24] 1564 	push	ar7
      0005CA C0 06            [24] 1565 	push	ar6
      0005CC C0 05            [24] 1566 	push	ar5
      0005CE C0 04            [24] 1567 	push	ar4
      0005D0 E5 10            [12] 1568 	mov	a,_bp
      0005D2 24 FA            [12] 1569 	add	a,#0xfa
      0005D4 F8               [12] 1570 	mov	r0,a
      0005D5 E6               [12] 1571 	mov	a,@r0
      0005D6 C0 E0            [24] 1572 	push	acc
      0005D8 08               [12] 1573 	inc	r0
      0005D9 E6               [12] 1574 	mov	a,@r0
      0005DA C0 E0            [24] 1575 	push	acc
      0005DC 08               [12] 1576 	inc	r0
      0005DD E6               [12] 1577 	mov	a,@r0
      0005DE C0 E0            [24] 1578 	push	acc
      0005E0 08               [12] 1579 	inc	r0
      0005E1 E6               [12] 1580 	mov	a,@r0
      0005E2 C0 E0            [24] 1581 	push	acc
      0005E4 8F 82            [24] 1582 	mov	dpl, r7
      0005E6 8E 83            [24] 1583 	mov	dph, r6
      0005E8 8D F0            [24] 1584 	mov	b, r5
      0005EA EC               [12] 1585 	mov	a, r4
      0005EB 12 2B E5         [24] 1586 	lcall	___fslt
      0005EE E5 81            [12] 1587 	mov	a,sp
      0005F0 24 FC            [12] 1588 	add	a,#0xfc
      0005F2 F5 81            [12] 1589 	mov	sp,a
      0005F4 D0 04            [24] 1590 	pop	ar4
      0005F6 D0 05            [24] 1591 	pop	ar5
      0005F8 D0 06            [24] 1592 	pop	ar6
      0005FA D0 07            [24] 1593 	pop	ar7
      0005FC E5 82            [12] 1594 	mov	a, dpl
      0005FE 24 FF            [12] 1595 	add	a,#0xff
      000600 92 00            [24] 1596 	mov	b0,c
      000602 40 09            [24] 1597 	jc	00102$
                           000547  1598 	C$fuzzy.h$205$2_0$58 ==.
                                   1599 ;	../../fuzzy.h:205: return 0.0f;
      000604 90 00 00         [24] 1600 	mov	dptr,#0x0000
      000607 E4               [12] 1601 	clr	a
      000608 F5 F0            [12] 1602 	mov	b,a
      00060A 02 07 BC         [24] 1603 	ljmp	00111$
      00060D                       1604 00102$:
                           000550  1605 	C$fuzzy.h$208$1_0$57 ==.
                                   1606 ;	../../fuzzy.h:208: if (x <= a) {
      00060D C0 07            [24] 1607 	push	ar7
      00060F C0 06            [24] 1608 	push	ar6
      000611 C0 05            [24] 1609 	push	ar5
      000613 C0 04            [24] 1610 	push	ar4
      000615 E5 10            [12] 1611 	mov	a,_bp
      000617 24 F6            [12] 1612 	add	a,#0xf6
      000619 F8               [12] 1613 	mov	r0,a
      00061A E6               [12] 1614 	mov	a,@r0
      00061B C0 E0            [24] 1615 	push	acc
      00061D 08               [12] 1616 	inc	r0
      00061E E6               [12] 1617 	mov	a,@r0
      00061F C0 E0            [24] 1618 	push	acc
      000621 08               [12] 1619 	inc	r0
      000622 E6               [12] 1620 	mov	a,@r0
      000623 C0 E0            [24] 1621 	push	acc
      000625 08               [12] 1622 	inc	r0
      000626 E6               [12] 1623 	mov	a,@r0
      000627 C0 E0            [24] 1624 	push	acc
      000629 8F 82            [24] 1625 	mov	dpl, r7
      00062B 8E 83            [24] 1626 	mov	dph, r6
      00062D 8D F0            [24] 1627 	mov	b, r5
      00062F EC               [12] 1628 	mov	a, r4
      000630 12 2B E5         [24] 1629 	lcall	___fslt
      000633 E5 81            [12] 1630 	mov	a,sp
      000635 24 FC            [12] 1631 	add	a,#0xfc
      000637 F5 81            [12] 1632 	mov	sp,a
      000639 D0 04            [24] 1633 	pop	ar4
      00063B D0 05            [24] 1634 	pop	ar5
      00063D D0 06            [24] 1635 	pop	ar6
      00063F D0 07            [24] 1636 	pop	ar7
      000641 E5 82            [12] 1637 	mov	a, dpl
      000643 24 FF            [12] 1638 	add	a,#0xff
      000645 92 00            [24] 1639 	mov	b0,c
      000647 40 39            [24] 1640 	jc	00109$
                           00058C  1641 	C$fuzzy.h$209$2_0$59 ==.
                                   1642 ;	../../fuzzy.h:209: result = up ? 0.0f : 1.0f;
      000649 E5 10            [12] 1643 	mov	a,_bp
      00064B 24 F5            [12] 1644 	add	a,#0xf5
      00064D F8               [12] 1645 	mov	r0,a
      00064E E6               [12] 1646 	mov	a,@r0
      00064F 60 0F            [24] 1647 	jz	00113$
      000651 E5 10            [12] 1648 	mov	a,_bp
      000653 24 05            [12] 1649 	add	a,#0x05
      000655 F8               [12] 1650 	mov	r0,a
      000656 E4               [12] 1651 	clr	a
      000657 F6               [12] 1652 	mov	@r0,a
      000658 08               [12] 1653 	inc	r0
      000659 F6               [12] 1654 	mov	@r0,a
      00065A 08               [12] 1655 	inc	r0
      00065B F6               [12] 1656 	mov	@r0,a
      00065C 08               [12] 1657 	inc	r0
      00065D F6               [12] 1658 	mov	@r0,a
      00065E 80 0F            [24] 1659 	sjmp	00114$
      000660                       1660 00113$:
      000660 E5 10            [12] 1661 	mov	a,_bp
      000662 24 05            [12] 1662 	add	a,#0x05
      000664 F8               [12] 1663 	mov	r0,a
      000665 E4               [12] 1664 	clr	a
      000666 F6               [12] 1665 	mov	@r0,a
      000667 08               [12] 1666 	inc	r0
      000668 F6               [12] 1667 	mov	@r0,a
      000669 08               [12] 1668 	inc	r0
      00066A 76 80            [12] 1669 	mov	@r0,#0x80
      00066C 08               [12] 1670 	inc	r0
      00066D 76 3F            [12] 1671 	mov	@r0,#0x3f
      00066F                       1672 00114$:
      00066F E5 10            [12] 1673 	mov	a,_bp
      000671 24 05            [12] 1674 	add	a,#0x05
      000673 F8               [12] 1675 	mov	r0,a
      000674 86 07            [24] 1676 	mov	ar7,@r0
      000676 08               [12] 1677 	inc	r0
      000677 86 06            [24] 1678 	mov	ar6,@r0
      000679 08               [12] 1679 	inc	r0
      00067A 86 05            [24] 1680 	mov	ar5,@r0
      00067C 08               [12] 1681 	inc	r0
      00067D 86 04            [24] 1682 	mov	ar4,@r0
      00067F 02 07 9A         [24] 1683 	ljmp	00110$
      000682                       1684 00109$:
                           0005C5  1685 	C$fuzzy.h$211$1_0$57 ==.
                                   1686 ;	../../fuzzy.h:211: else if (x >= b) {
      000682 C0 07            [24] 1687 	push	ar7
      000684 C0 06            [24] 1688 	push	ar6
      000686 C0 05            [24] 1689 	push	ar5
      000688 C0 04            [24] 1690 	push	ar4
      00068A E5 10            [12] 1691 	mov	a,_bp
      00068C 24 FA            [12] 1692 	add	a,#0xfa
      00068E F8               [12] 1693 	mov	r0,a
      00068F E6               [12] 1694 	mov	a,@r0
      000690 C0 E0            [24] 1695 	push	acc
      000692 08               [12] 1696 	inc	r0
      000693 E6               [12] 1697 	mov	a,@r0
      000694 C0 E0            [24] 1698 	push	acc
      000696 08               [12] 1699 	inc	r0
      000697 E6               [12] 1700 	mov	a,@r0
      000698 C0 E0            [24] 1701 	push	acc
      00069A 08               [12] 1702 	inc	r0
      00069B E6               [12] 1703 	mov	a,@r0
      00069C C0 E0            [24] 1704 	push	acc
      00069E E5 10            [12] 1705 	mov	a,_bp
      0006A0 24 F6            [12] 1706 	add	a,#0xf6
      0006A2 F8               [12] 1707 	mov	r0,a
      0006A3 86 82            [24] 1708 	mov	dpl, @r0
      0006A5 08               [12] 1709 	inc	r0
      0006A6 86 83            [24] 1710 	mov	dph, @r0
      0006A8 08               [12] 1711 	inc	r0
      0006A9 86 F0            [24] 1712 	mov	b, @r0
      0006AB 08               [12] 1713 	inc	r0
      0006AC E6               [12] 1714 	mov	a, @r0
      0006AD 12 2B E5         [24] 1715 	lcall	___fslt
      0006B0 E5 81            [12] 1716 	mov	a,sp
      0006B2 24 FC            [12] 1717 	add	a,#0xfc
      0006B4 F5 81            [12] 1718 	mov	sp,a
      0006B6 D0 04            [24] 1719 	pop	ar4
      0006B8 D0 05            [24] 1720 	pop	ar5
      0006BA D0 06            [24] 1721 	pop	ar6
      0006BC D0 07            [24] 1722 	pop	ar7
      0006BE E5 82            [12] 1723 	mov	a, dpl
      0006C0 24 FF            [12] 1724 	add	a,#0xff
      0006C2 92 00            [24] 1725 	mov	b0,c
      0006C4 40 33            [24] 1726 	jc	00106$
                           000609  1727 	C$fuzzy.h$212$2_0$60 ==.
                                   1728 ;	../../fuzzy.h:212: result = up ? 1.0f : 0.0f;
      0006C6 E5 10            [12] 1729 	mov	a,_bp
      0006C8 24 F5            [12] 1730 	add	a,#0xf5
      0006CA F8               [12] 1731 	mov	r0,a
      0006CB E6               [12] 1732 	mov	a,@r0
      0006CC 60 0F            [24] 1733 	jz	00115$
      0006CE A8 10            [24] 1734 	mov	r0,_bp
      0006D0 08               [12] 1735 	inc	r0
      0006D1 E4               [12] 1736 	clr	a
      0006D2 F6               [12] 1737 	mov	@r0,a
      0006D3 08               [12] 1738 	inc	r0
      0006D4 F6               [12] 1739 	mov	@r0,a
      0006D5 08               [12] 1740 	inc	r0
      0006D6 76 80            [12] 1741 	mov	@r0,#0x80
      0006D8 08               [12] 1742 	inc	r0
      0006D9 76 3F            [12] 1743 	mov	@r0,#0x3f
      0006DB 80 0B            [24] 1744 	sjmp	00116$
      0006DD                       1745 00115$:
      0006DD A8 10            [24] 1746 	mov	r0,_bp
      0006DF 08               [12] 1747 	inc	r0
      0006E0 E4               [12] 1748 	clr	a
      0006E1 F6               [12] 1749 	mov	@r0,a
      0006E2 08               [12] 1750 	inc	r0
      0006E3 F6               [12] 1751 	mov	@r0,a
      0006E4 08               [12] 1752 	inc	r0
      0006E5 F6               [12] 1753 	mov	@r0,a
      0006E6 08               [12] 1754 	inc	r0
      0006E7 F6               [12] 1755 	mov	@r0,a
      0006E8                       1756 00116$:
      0006E8 A8 10            [24] 1757 	mov	r0,_bp
      0006EA 08               [12] 1758 	inc	r0
      0006EB 86 07            [24] 1759 	mov	ar7,@r0
      0006ED 08               [12] 1760 	inc	r0
      0006EE 86 06            [24] 1761 	mov	ar6,@r0
      0006F0 08               [12] 1762 	inc	r0
      0006F1 86 05            [24] 1763 	mov	ar5,@r0
      0006F3 08               [12] 1764 	inc	r0
      0006F4 86 04            [24] 1765 	mov	ar4,@r0
      0006F6 02 07 9A         [24] 1766 	ljmp	00110$
      0006F9                       1767 00106$:
                           00063C  1768 	C$fuzzy.h$215$1_0$57 ==.
                                   1769 ;	../../fuzzy.h:215: result = (x - a) / (b - a);
      0006F9 C0 07            [24] 1770 	push	ar7
      0006FB C0 06            [24] 1771 	push	ar6
      0006FD C0 05            [24] 1772 	push	ar5
      0006FF C0 04            [24] 1773 	push	ar4
      000701 C0 07            [24] 1774 	push	ar7
      000703 C0 06            [24] 1775 	push	ar6
      000705 C0 05            [24] 1776 	push	ar5
      000707 C0 04            [24] 1777 	push	ar4
      000709 E5 10            [12] 1778 	mov	a,_bp
      00070B 24 F6            [12] 1779 	add	a,#0xf6
      00070D F8               [12] 1780 	mov	r0,a
      00070E 86 82            [24] 1781 	mov	dpl, @r0
      000710 08               [12] 1782 	inc	r0
      000711 86 83            [24] 1783 	mov	dph, @r0
      000713 08               [12] 1784 	inc	r0
      000714 86 F0            [24] 1785 	mov	b, @r0
      000716 08               [12] 1786 	inc	r0
      000717 E6               [12] 1787 	mov	a, @r0
      000718 12 2A AA         [24] 1788 	lcall	___fssub
      00071B A8 10            [24] 1789 	mov	r0,_bp
      00071D 08               [12] 1790 	inc	r0
      00071E A6 82            [24] 1791 	mov	@r0, dpl
      000720 08               [12] 1792 	inc	r0
      000721 A6 83            [24] 1793 	mov	@r0, dph
      000723 08               [12] 1794 	inc	r0
      000724 A6 F0            [24] 1795 	mov	@r0, b
      000726 08               [12] 1796 	inc	r0
      000727 F6               [12] 1797 	mov	@r0,a
      000728 E5 81            [12] 1798 	mov	a,sp
      00072A 24 FC            [12] 1799 	add	a,#0xfc
      00072C F5 81            [12] 1800 	mov	sp,a
      00072E E5 10            [12] 1801 	mov	a,_bp
      000730 24 FA            [12] 1802 	add	a,#0xfa
      000732 F8               [12] 1803 	mov	r0,a
      000733 86 82            [24] 1804 	mov	dpl, @r0
      000735 08               [12] 1805 	inc	r0
      000736 86 83            [24] 1806 	mov	dph, @r0
      000738 08               [12] 1807 	inc	r0
      000739 86 F0            [24] 1808 	mov	b, @r0
      00073B 08               [12] 1809 	inc	r0
      00073C E6               [12] 1810 	mov	a, @r0
      00073D 12 2A AA         [24] 1811 	lcall	___fssub
      000740 AC 82            [24] 1812 	mov	r4, dpl
      000742 AD 83            [24] 1813 	mov	r5, dph
      000744 AE F0            [24] 1814 	mov	r6, b
      000746 FF               [12] 1815 	mov	r7, a
      000747 E5 81            [12] 1816 	mov	a,sp
      000749 24 FC            [12] 1817 	add	a,#0xfc
      00074B F5 81            [12] 1818 	mov	sp,a
      00074D C0 04            [24] 1819 	push	ar4
      00074F C0 05            [24] 1820 	push	ar5
      000751 C0 06            [24] 1821 	push	ar6
      000753 C0 07            [24] 1822 	push	ar7
                           000698  1823 	C$fuzzy.h$217$1_0$57 ==.
                                   1824 ;	../../fuzzy.h:217: if (!up) {
      000755 A8 10            [24] 1825 	mov	r0,_bp
      000757 08               [12] 1826 	inc	r0
      000758 86 82            [24] 1827 	mov	dpl, @r0
      00075A 08               [12] 1828 	inc	r0
      00075B 86 83            [24] 1829 	mov	dph, @r0
      00075D 08               [12] 1830 	inc	r0
      00075E 86 F0            [24] 1831 	mov	b, @r0
      000760 08               [12] 1832 	inc	r0
      000761 E6               [12] 1833 	mov	a, @r0
      000762 12 2D 2C         [24] 1834 	lcall	___fsdiv
      000765 AF 82            [24] 1835 	mov	r7, dpl
      000767 AE 83            [24] 1836 	mov	r6, dph
      000769 AD F0            [24] 1837 	mov	r5, b
      00076B FC               [12] 1838 	mov	r4, a
      00076C E5 81            [12] 1839 	mov	a,sp
      00076E 24 FC            [12] 1840 	add	a,#0xfc
      000770 F5 81            [12] 1841 	mov	sp,a
      000772 E5 10            [12] 1842 	mov	a,_bp
      000774 24 F5            [12] 1843 	add	a,#0xf5
      000776 F8               [12] 1844 	mov	r0,a
      000777 E6               [12] 1845 	mov	a,@r0
      000778 70 20            [24] 1846 	jnz	00110$
                           0006BD  1847 	C$fuzzy.h$218$1_0$57 ==.
                                   1848 ;	../../fuzzy.h:218: result = 1.0f - result;
      00077A C0 07            [24] 1849 	push	ar7
      00077C C0 06            [24] 1850 	push	ar6
      00077E C0 05            [24] 1851 	push	ar5
      000780 C0 04            [24] 1852 	push	ar4
      000782 90 00 00         [24] 1853 	mov	dptr,#0x0000
      000785 75 F0 80         [24] 1854 	mov	b, #0x80
      000788 74 3F            [12] 1855 	mov	a, #0x3f
      00078A 12 2A AA         [24] 1856 	lcall	___fssub
      00078D AF 82            [24] 1857 	mov	r7, dpl
      00078F AE 83            [24] 1858 	mov	r6, dph
      000791 AD F0            [24] 1859 	mov	r5, b
      000793 FC               [12] 1860 	mov	r4, a
      000794 E5 81            [12] 1861 	mov	a,sp
      000796 24 FC            [12] 1862 	add	a,#0xfc
      000798 F5 81            [12] 1863 	mov	sp,a
      00079A                       1864 00110$:
                           0006DD  1865 	C$fuzzy.h$222$1_0$57 ==.
                                   1866 ;	../../fuzzy.h:222: return fuzzy_8051_hedge(result, hedge);
      00079A E5 10            [12] 1867 	mov	a,_bp
      00079C 24 F4            [12] 1868 	add	a,#0xf4
      00079E F8               [12] 1869 	mov	r0,a
      00079F E6               [12] 1870 	mov	a,@r0
      0007A0 C0 E0            [24] 1871 	push	acc
      0007A2 8F 82            [24] 1872 	mov	dpl, r7
      0007A4 8E 83            [24] 1873 	mov	dph, r6
      0007A6 8D F0            [24] 1874 	mov	b, r5
      0007A8 EC               [12] 1875 	mov	a, r4
      0007A9 12 04 FA         [24] 1876 	lcall	_fuzzy_8051_hedge
      0007AC AC 82            [24] 1877 	mov	r4, dpl
      0007AE AD 83            [24] 1878 	mov	r5, dph
      0007B0 AE F0            [24] 1879 	mov	r6, b
      0007B2 FF               [12] 1880 	mov	r7, a
      0007B3 15 81            [12] 1881 	dec	sp
      0007B5 8C 82            [24] 1882 	mov	dpl, r4
      0007B7 8D 83            [24] 1883 	mov	dph, r5
      0007B9 8E F0            [24] 1884 	mov	b, r6
      0007BB EF               [12] 1885 	mov	a, r7
      0007BC                       1886 00111$:
                           0006FF  1887 	C$fuzzy.h$223$1_0$57 ==.
                                   1888 ;	../../fuzzy.h:223: }
      0007BC 85 10 81         [24] 1889 	mov	sp,_bp
      0007BF D0 10            [24] 1890 	pop	_bp
                           000704  1891 	C$fuzzy.h$223$1_0$57 ==.
                           000704  1892 	XG$fuzzy_ramp$0$0 ==.
      0007C1 22               [24] 1893 	ret
                                   1894 ;------------------------------------------------------------
                                   1895 ;Allocation info for local variables in function 'fuzzy_triangle'
                                   1896 ;------------------------------------------------------------
                                   1897 ;b             Allocated to stack - _bp -6 +4 
                                   1898 ;c             Allocated to stack - _bp -10 +4 
                                   1899 ;x             Allocated to stack - _bp -14 +4 
                                   1900 ;hedge         Allocated to stack - _bp -15 +1 
                                   1901 ;a             Allocated to registers r7 r6 r5 r4 
                                   1902 ;result        Allocated to stack - _bp +1 +4 
                                   1903 ;sloc0         Allocated to stack - _bp +1 +4 
                                   1904 ;sloc1         Allocated to stack - _bp +5 +4 
                                   1905 ;------------------------------------------------------------
                           000705  1906 	G$fuzzy_triangle$0$0 ==.
                           000705  1907 	C$fuzzy.h$225$1_0$64 ==.
                                   1908 ;	../../fuzzy.h:225: float fuzzy_triangle(float a, float b, float c, float x, fuzzy_hedge_t hedge)
                                   1909 ;	-----------------------------------------
                                   1910 ;	 function fuzzy_triangle
                                   1911 ;	-----------------------------------------
      0007C2                       1912 _fuzzy_triangle:
      0007C2 C0 10            [24] 1913 	push	_bp
      0007C4 85 81 10         [24] 1914 	mov	_bp,sp
      0007C7 AF 82            [24] 1915 	mov	r7,dpl
      0007C9 AE 83            [24] 1916 	mov	r6,dph
      0007CB AD F0            [24] 1917 	mov	r5,b
      0007CD FC               [12] 1918 	mov	r4,a
      0007CE E5 81            [12] 1919 	mov	a,sp
      0007D0 24 08            [12] 1920 	add	a,#0x08
      0007D2 F5 81            [12] 1921 	mov	sp,a
                           000717  1922 	C$fuzzy.h$229$1_0$64 ==.
                                   1923 ;	../../fuzzy.h:229: if (a >= b || b >= c || x <= a || x >= c) {
      0007D4 C0 07            [24] 1924 	push	ar7
      0007D6 C0 06            [24] 1925 	push	ar6
      0007D8 C0 05            [24] 1926 	push	ar5
      0007DA C0 04            [24] 1927 	push	ar4
      0007DC E5 10            [12] 1928 	mov	a,_bp
      0007DE 24 FA            [12] 1929 	add	a,#0xfa
      0007E0 F8               [12] 1930 	mov	r0,a
      0007E1 E6               [12] 1931 	mov	a,@r0
      0007E2 C0 E0            [24] 1932 	push	acc
      0007E4 08               [12] 1933 	inc	r0
      0007E5 E6               [12] 1934 	mov	a,@r0
      0007E6 C0 E0            [24] 1935 	push	acc
      0007E8 08               [12] 1936 	inc	r0
      0007E9 E6               [12] 1937 	mov	a,@r0
      0007EA C0 E0            [24] 1938 	push	acc
      0007EC 08               [12] 1939 	inc	r0
      0007ED E6               [12] 1940 	mov	a,@r0
      0007EE C0 E0            [24] 1941 	push	acc
      0007F0 8F 82            [24] 1942 	mov	dpl, r7
      0007F2 8E 83            [24] 1943 	mov	dph, r6
      0007F4 8D F0            [24] 1944 	mov	b, r5
      0007F6 EC               [12] 1945 	mov	a, r4
      0007F7 12 2B E5         [24] 1946 	lcall	___fslt
      0007FA E5 81            [12] 1947 	mov	a,sp
      0007FC 24 FC            [12] 1948 	add	a,#0xfc
      0007FE F5 81            [12] 1949 	mov	sp,a
      000800 D0 04            [24] 1950 	pop	ar4
      000802 D0 05            [24] 1951 	pop	ar5
      000804 D0 06            [24] 1952 	pop	ar6
      000806 D0 07            [24] 1953 	pop	ar7
      000808 E5 82            [12] 1954 	mov	a, dpl
      00080A 24 FF            [12] 1955 	add	a,#0xff
      00080C 92 00            [24] 1956 	mov	b0,c
      00080E 40 03            [24] 1957 	jc	00145$
      000810 02 08 DA         [24] 1958 	ljmp	00107$
      000813                       1959 00145$:
      000813 C0 07            [24] 1960 	push	ar7
      000815 C0 06            [24] 1961 	push	ar6
      000817 C0 05            [24] 1962 	push	ar5
      000819 C0 04            [24] 1963 	push	ar4
      00081B E5 10            [12] 1964 	mov	a,_bp
      00081D 24 F6            [12] 1965 	add	a,#0xf6
      00081F F8               [12] 1966 	mov	r0,a
      000820 E6               [12] 1967 	mov	a,@r0
      000821 C0 E0            [24] 1968 	push	acc
      000823 08               [12] 1969 	inc	r0
      000824 E6               [12] 1970 	mov	a,@r0
      000825 C0 E0            [24] 1971 	push	acc
      000827 08               [12] 1972 	inc	r0
      000828 E6               [12] 1973 	mov	a,@r0
      000829 C0 E0            [24] 1974 	push	acc
      00082B 08               [12] 1975 	inc	r0
      00082C E6               [12] 1976 	mov	a,@r0
      00082D C0 E0            [24] 1977 	push	acc
      00082F E5 10            [12] 1978 	mov	a,_bp
      000831 24 FA            [12] 1979 	add	a,#0xfa
      000833 F8               [12] 1980 	mov	r0,a
      000834 86 82            [24] 1981 	mov	dpl, @r0
      000836 08               [12] 1982 	inc	r0
      000837 86 83            [24] 1983 	mov	dph, @r0
      000839 08               [12] 1984 	inc	r0
      00083A 86 F0            [24] 1985 	mov	b, @r0
      00083C 08               [12] 1986 	inc	r0
      00083D E6               [12] 1987 	mov	a, @r0
      00083E 12 2B E5         [24] 1988 	lcall	___fslt
      000841 E5 81            [12] 1989 	mov	a,sp
      000843 24 FC            [12] 1990 	add	a,#0xfc
      000845 F5 81            [12] 1991 	mov	sp,a
      000847 D0 04            [24] 1992 	pop	ar4
      000849 D0 05            [24] 1993 	pop	ar5
      00084B D0 06            [24] 1994 	pop	ar6
      00084D D0 07            [24] 1995 	pop	ar7
      00084F E5 82            [12] 1996 	mov	a, dpl
      000851 24 FF            [12] 1997 	add	a,#0xff
      000853 92 00            [24] 1998 	mov	b0,c
      000855 40 03            [24] 1999 	jc	00146$
      000857 02 08 DA         [24] 2000 	ljmp	00107$
      00085A                       2001 00146$:
      00085A C0 07            [24] 2002 	push	ar7
      00085C C0 06            [24] 2003 	push	ar6
      00085E C0 05            [24] 2004 	push	ar5
      000860 C0 04            [24] 2005 	push	ar4
      000862 E5 10            [12] 2006 	mov	a,_bp
      000864 24 F2            [12] 2007 	add	a,#0xf2
      000866 F8               [12] 2008 	mov	r0,a
      000867 E6               [12] 2009 	mov	a,@r0
      000868 C0 E0            [24] 2010 	push	acc
      00086A 08               [12] 2011 	inc	r0
      00086B E6               [12] 2012 	mov	a,@r0
      00086C C0 E0            [24] 2013 	push	acc
      00086E 08               [12] 2014 	inc	r0
      00086F E6               [12] 2015 	mov	a,@r0
      000870 C0 E0            [24] 2016 	push	acc
      000872 08               [12] 2017 	inc	r0
      000873 E6               [12] 2018 	mov	a,@r0
      000874 C0 E0            [24] 2019 	push	acc
      000876 8F 82            [24] 2020 	mov	dpl, r7
      000878 8E 83            [24] 2021 	mov	dph, r6
      00087A 8D F0            [24] 2022 	mov	b, r5
      00087C EC               [12] 2023 	mov	a, r4
      00087D 12 2B E5         [24] 2024 	lcall	___fslt
      000880 E5 81            [12] 2025 	mov	a,sp
      000882 24 FC            [12] 2026 	add	a,#0xfc
      000884 F5 81            [12] 2027 	mov	sp,a
      000886 D0 04            [24] 2028 	pop	ar4
      000888 D0 05            [24] 2029 	pop	ar5
      00088A D0 06            [24] 2030 	pop	ar6
      00088C D0 07            [24] 2031 	pop	ar7
      00088E E5 82            [12] 2032 	mov	a, dpl
      000890 24 FF            [12] 2033 	add	a,#0xff
      000892 92 00            [24] 2034 	mov	b0,c
      000894 50 44            [24] 2035 	jnc	00107$
      000896 C0 07            [24] 2036 	push	ar7
      000898 C0 06            [24] 2037 	push	ar6
      00089A C0 05            [24] 2038 	push	ar5
      00089C C0 04            [24] 2039 	push	ar4
      00089E E5 10            [12] 2040 	mov	a,_bp
      0008A0 24 F6            [12] 2041 	add	a,#0xf6
      0008A2 F8               [12] 2042 	mov	r0,a
      0008A3 E6               [12] 2043 	mov	a,@r0
      0008A4 C0 E0            [24] 2044 	push	acc
      0008A6 08               [12] 2045 	inc	r0
      0008A7 E6               [12] 2046 	mov	a,@r0
      0008A8 C0 E0            [24] 2047 	push	acc
      0008AA 08               [12] 2048 	inc	r0
      0008AB E6               [12] 2049 	mov	a,@r0
      0008AC C0 E0            [24] 2050 	push	acc
      0008AE 08               [12] 2051 	inc	r0
      0008AF E6               [12] 2052 	mov	a,@r0
      0008B0 C0 E0            [24] 2053 	push	acc
      0008B2 E5 10            [12] 2054 	mov	a,_bp
      0008B4 24 F2            [12] 2055 	add	a,#0xf2
      0008B6 F8               [12] 2056 	mov	r0,a
      0008B7 86 82            [24] 2057 	mov	dpl, @r0
      0008B9 08               [12] 2058 	inc	r0
      0008BA 86 83            [24] 2059 	mov	dph, @r0
      0008BC 08               [12] 2060 	inc	r0
      0008BD 86 F0            [24] 2061 	mov	b, @r0
      0008BF 08               [12] 2062 	inc	r0
      0008C0 E6               [12] 2063 	mov	a, @r0
      0008C1 12 2B E5         [24] 2064 	lcall	___fslt
      0008C4 E5 81            [12] 2065 	mov	a,sp
      0008C6 24 FC            [12] 2066 	add	a,#0xfc
      0008C8 F5 81            [12] 2067 	mov	sp,a
      0008CA D0 04            [24] 2068 	pop	ar4
      0008CC D0 05            [24] 2069 	pop	ar5
      0008CE D0 06            [24] 2070 	pop	ar6
      0008D0 D0 07            [24] 2071 	pop	ar7
      0008D2 E5 82            [12] 2072 	mov	a, dpl
      0008D4 24 FF            [12] 2073 	add	a,#0xff
      0008D6 92 00            [24] 2074 	mov	b0,c
      0008D8 40 0E            [24] 2075 	jc	00108$
      0008DA                       2076 00107$:
                           00081D  2077 	C$fuzzy.h$230$2_0$65 ==.
                                   2078 ;	../../fuzzy.h:230: result = 0.0f;
      0008DA A8 10            [24] 2079 	mov	r0,_bp
      0008DC 08               [12] 2080 	inc	r0
      0008DD E4               [12] 2081 	clr	a
      0008DE F6               [12] 2082 	mov	@r0,a
      0008DF 08               [12] 2083 	inc	r0
      0008E0 F6               [12] 2084 	mov	@r0,a
      0008E1 08               [12] 2085 	inc	r0
      0008E2 F6               [12] 2086 	mov	@r0,a
      0008E3 08               [12] 2087 	inc	r0
      0008E4 F6               [12] 2088 	mov	@r0,a
      0008E5 02 0A A0         [24] 2089 	ljmp	00109$
      0008E8                       2090 00108$:
                           00082B  2091 	C$fuzzy.h$232$1_0$64 ==.
                                   2092 ;	../../fuzzy.h:232: else if (x == b) {
      0008E8 C0 07            [24] 2093 	push	ar7
      0008EA C0 06            [24] 2094 	push	ar6
      0008EC C0 05            [24] 2095 	push	ar5
      0008EE C0 04            [24] 2096 	push	ar4
      0008F0 E5 10            [12] 2097 	mov	a,_bp
      0008F2 24 FA            [12] 2098 	add	a,#0xfa
      0008F4 F8               [12] 2099 	mov	r0,a
      0008F5 E6               [12] 2100 	mov	a,@r0
      0008F6 C0 E0            [24] 2101 	push	acc
      0008F8 08               [12] 2102 	inc	r0
      0008F9 E6               [12] 2103 	mov	a,@r0
      0008FA C0 E0            [24] 2104 	push	acc
      0008FC 08               [12] 2105 	inc	r0
      0008FD E6               [12] 2106 	mov	a,@r0
      0008FE C0 E0            [24] 2107 	push	acc
      000900 08               [12] 2108 	inc	r0
      000901 E6               [12] 2109 	mov	a,@r0
      000902 C0 E0            [24] 2110 	push	acc
      000904 E5 10            [12] 2111 	mov	a,_bp
      000906 24 F2            [12] 2112 	add	a,#0xf2
      000908 F8               [12] 2113 	mov	r0,a
      000909 86 82            [24] 2114 	mov	dpl, @r0
      00090B 08               [12] 2115 	inc	r0
      00090C 86 83            [24] 2116 	mov	dph, @r0
      00090E 08               [12] 2117 	inc	r0
      00090F 86 F0            [24] 2118 	mov	b, @r0
      000911 08               [12] 2119 	inc	r0
      000912 E6               [12] 2120 	mov	a, @r0
      000913 12 2B B9         [24] 2121 	lcall	___fseq
      000916 AB 82            [24] 2122 	mov	r3, dpl
      000918 E5 81            [12] 2123 	mov	a,sp
      00091A 24 FC            [12] 2124 	add	a,#0xfc
      00091C F5 81            [12] 2125 	mov	sp,a
      00091E D0 04            [24] 2126 	pop	ar4
      000920 D0 05            [24] 2127 	pop	ar5
      000922 D0 06            [24] 2128 	pop	ar6
      000924 D0 07            [24] 2129 	pop	ar7
      000926 EB               [12] 2130 	mov	a,r3
      000927 60 10            [24] 2131 	jz	00105$
                           00086C  2132 	C$fuzzy.h$233$2_0$66 ==.
                                   2133 ;	../../fuzzy.h:233: result = 1.0f;
      000929 A8 10            [24] 2134 	mov	r0,_bp
      00092B 08               [12] 2135 	inc	r0
      00092C E4               [12] 2136 	clr	a
      00092D F6               [12] 2137 	mov	@r0,a
      00092E 08               [12] 2138 	inc	r0
      00092F F6               [12] 2139 	mov	@r0,a
      000930 08               [12] 2140 	inc	r0
      000931 76 80            [12] 2141 	mov	@r0,#0x80
      000933 08               [12] 2142 	inc	r0
      000934 76 3F            [12] 2143 	mov	@r0,#0x3f
      000936 02 0A A0         [24] 2144 	ljmp	00109$
      000939                       2145 00105$:
                           00087C  2146 	C$fuzzy.h$235$1_0$64 ==.
                                   2147 ;	../../fuzzy.h:235: else if (x < b) {
      000939 C0 07            [24] 2148 	push	ar7
      00093B C0 06            [24] 2149 	push	ar6
      00093D C0 05            [24] 2150 	push	ar5
      00093F C0 04            [24] 2151 	push	ar4
      000941 E5 10            [12] 2152 	mov	a,_bp
      000943 24 FA            [12] 2153 	add	a,#0xfa
      000945 F8               [12] 2154 	mov	r0,a
      000946 E6               [12] 2155 	mov	a,@r0
      000947 C0 E0            [24] 2156 	push	acc
      000949 08               [12] 2157 	inc	r0
      00094A E6               [12] 2158 	mov	a,@r0
      00094B C0 E0            [24] 2159 	push	acc
      00094D 08               [12] 2160 	inc	r0
      00094E E6               [12] 2161 	mov	a,@r0
      00094F C0 E0            [24] 2162 	push	acc
      000951 08               [12] 2163 	inc	r0
      000952 E6               [12] 2164 	mov	a,@r0
      000953 C0 E0            [24] 2165 	push	acc
      000955 E5 10            [12] 2166 	mov	a,_bp
      000957 24 F2            [12] 2167 	add	a,#0xf2
      000959 F8               [12] 2168 	mov	r0,a
      00095A 86 82            [24] 2169 	mov	dpl, @r0
      00095C 08               [12] 2170 	inc	r0
      00095D 86 83            [24] 2171 	mov	dph, @r0
      00095F 08               [12] 2172 	inc	r0
      000960 86 F0            [24] 2173 	mov	b, @r0
      000962 08               [12] 2174 	inc	r0
      000963 E6               [12] 2175 	mov	a, @r0
      000964 12 2B E5         [24] 2176 	lcall	___fslt
      000967 AB 82            [24] 2177 	mov	r3, dpl
      000969 E5 81            [12] 2178 	mov	a,sp
      00096B 24 FC            [12] 2179 	add	a,#0xfc
      00096D F5 81            [12] 2180 	mov	sp,a
      00096F D0 04            [24] 2181 	pop	ar4
      000971 D0 05            [24] 2182 	pop	ar5
      000973 D0 06            [24] 2183 	pop	ar6
      000975 D0 07            [24] 2184 	pop	ar7
      000977 EB               [12] 2185 	mov	a,r3
      000978 70 03            [24] 2186 	jnz	00150$
      00097A 02 0A 04         [24] 2187 	ljmp	00102$
      00097D                       2188 00150$:
                           0008C0  2189 	C$fuzzy.h$236$1_0$64 ==.
                                   2190 ;	../../fuzzy.h:236: result = (x - a) / (b - a);
      00097D C0 07            [24] 2191 	push	ar7
      00097F C0 06            [24] 2192 	push	ar6
      000981 C0 05            [24] 2193 	push	ar5
      000983 C0 04            [24] 2194 	push	ar4
      000985 C0 07            [24] 2195 	push	ar7
      000987 C0 06            [24] 2196 	push	ar6
      000989 C0 05            [24] 2197 	push	ar5
      00098B C0 04            [24] 2198 	push	ar4
      00098D E5 10            [12] 2199 	mov	a,_bp
      00098F 24 F2            [12] 2200 	add	a,#0xf2
      000991 F8               [12] 2201 	mov	r0,a
      000992 86 82            [24] 2202 	mov	dpl, @r0
      000994 08               [12] 2203 	inc	r0
      000995 86 83            [24] 2204 	mov	dph, @r0
      000997 08               [12] 2205 	inc	r0
      000998 86 F0            [24] 2206 	mov	b, @r0
      00099A 08               [12] 2207 	inc	r0
      00099B E6               [12] 2208 	mov	a, @r0
      00099C 12 2A AA         [24] 2209 	lcall	___fssub
      00099F C8               [12] 2210 	xch	a,r0
      0009A0 E5 10            [12] 2211 	mov	a,_bp
      0009A2 24 05            [12] 2212 	add	a,#0x05
      0009A4 C8               [12] 2213 	xch	a,r0
      0009A5 A6 82            [24] 2214 	mov	@r0, dpl
      0009A7 08               [12] 2215 	inc	r0
      0009A8 A6 83            [24] 2216 	mov	@r0, dph
      0009AA 08               [12] 2217 	inc	r0
      0009AB A6 F0            [24] 2218 	mov	@r0, b
      0009AD 08               [12] 2219 	inc	r0
      0009AE F6               [12] 2220 	mov	@r0,a
      0009AF E5 81            [12] 2221 	mov	a,sp
      0009B1 24 FC            [12] 2222 	add	a,#0xfc
      0009B3 F5 81            [12] 2223 	mov	sp,a
      0009B5 E5 10            [12] 2224 	mov	a,_bp
      0009B7 24 FA            [12] 2225 	add	a,#0xfa
      0009B9 F8               [12] 2226 	mov	r0,a
      0009BA 86 82            [24] 2227 	mov	dpl, @r0
      0009BC 08               [12] 2228 	inc	r0
      0009BD 86 83            [24] 2229 	mov	dph, @r0
      0009BF 08               [12] 2230 	inc	r0
      0009C0 86 F0            [24] 2231 	mov	b, @r0
      0009C2 08               [12] 2232 	inc	r0
      0009C3 E6               [12] 2233 	mov	a, @r0
      0009C4 12 2A AA         [24] 2234 	lcall	___fssub
      0009C7 AC 82            [24] 2235 	mov	r4, dpl
      0009C9 AD 83            [24] 2236 	mov	r5, dph
      0009CB AE F0            [24] 2237 	mov	r6, b
      0009CD FF               [12] 2238 	mov	r7, a
      0009CE E5 81            [12] 2239 	mov	a,sp
      0009D0 24 FC            [12] 2240 	add	a,#0xfc
      0009D2 F5 81            [12] 2241 	mov	sp,a
      0009D4 C0 04            [24] 2242 	push	ar4
      0009D6 C0 05            [24] 2243 	push	ar5
      0009D8 C0 06            [24] 2244 	push	ar6
      0009DA C0 07            [24] 2245 	push	ar7
      0009DC E5 10            [12] 2246 	mov	a,_bp
      0009DE 24 05            [12] 2247 	add	a,#0x05
      0009E0 F8               [12] 2248 	mov	r0,a
      0009E1 86 82            [24] 2249 	mov	dpl, @r0
      0009E3 08               [12] 2250 	inc	r0
      0009E4 86 83            [24] 2251 	mov	dph, @r0
      0009E6 08               [12] 2252 	inc	r0
      0009E7 86 F0            [24] 2253 	mov	b, @r0
      0009E9 08               [12] 2254 	inc	r0
      0009EA E6               [12] 2255 	mov	a, @r0
      0009EB 12 2D 2C         [24] 2256 	lcall	___fsdiv
      0009EE A8 10            [24] 2257 	mov	r0,_bp
      0009F0 08               [12] 2258 	inc	r0
      0009F1 A6 82            [24] 2259 	mov	@r0, dpl
      0009F3 08               [12] 2260 	inc	r0
      0009F4 A6 83            [24] 2261 	mov	@r0, dph
      0009F6 08               [12] 2262 	inc	r0
      0009F7 A6 F0            [24] 2263 	mov	@r0, b
      0009F9 08               [12] 2264 	inc	r0
      0009FA F6               [12] 2265 	mov	@r0,a
      0009FB E5 81            [12] 2266 	mov	a,sp
      0009FD 24 FC            [12] 2267 	add	a,#0xfc
      0009FF F5 81            [12] 2268 	mov	sp,a
      000A01 02 0A A0         [24] 2269 	ljmp	00109$
      000A04                       2270 00102$:
                           000947  2271 	C$fuzzy.h$239$1_0$64 ==.
                                   2272 ;	../../fuzzy.h:239: result = (c - x) / (c - b);
      000A04 E5 10            [12] 2273 	mov	a,_bp
      000A06 24 F2            [12] 2274 	add	a,#0xf2
      000A08 F8               [12] 2275 	mov	r0,a
      000A09 E6               [12] 2276 	mov	a,@r0
      000A0A C0 E0            [24] 2277 	push	acc
      000A0C 08               [12] 2278 	inc	r0
      000A0D E6               [12] 2279 	mov	a,@r0
      000A0E C0 E0            [24] 2280 	push	acc
      000A10 08               [12] 2281 	inc	r0
      000A11 E6               [12] 2282 	mov	a,@r0
      000A12 C0 E0            [24] 2283 	push	acc
      000A14 08               [12] 2284 	inc	r0
      000A15 E6               [12] 2285 	mov	a,@r0
      000A16 C0 E0            [24] 2286 	push	acc
      000A18 E5 10            [12] 2287 	mov	a,_bp
      000A1A 24 F6            [12] 2288 	add	a,#0xf6
      000A1C F8               [12] 2289 	mov	r0,a
      000A1D 86 82            [24] 2290 	mov	dpl, @r0
      000A1F 08               [12] 2291 	inc	r0
      000A20 86 83            [24] 2292 	mov	dph, @r0
      000A22 08               [12] 2293 	inc	r0
      000A23 86 F0            [24] 2294 	mov	b, @r0
      000A25 08               [12] 2295 	inc	r0
      000A26 E6               [12] 2296 	mov	a, @r0
      000A27 12 2A AA         [24] 2297 	lcall	___fssub
      000A2A C8               [12] 2298 	xch	a,r0
      000A2B E5 10            [12] 2299 	mov	a,_bp
      000A2D 24 05            [12] 2300 	add	a,#0x05
      000A2F C8               [12] 2301 	xch	a,r0
      000A30 A6 82            [24] 2302 	mov	@r0, dpl
      000A32 08               [12] 2303 	inc	r0
      000A33 A6 83            [24] 2304 	mov	@r0, dph
      000A35 08               [12] 2305 	inc	r0
      000A36 A6 F0            [24] 2306 	mov	@r0, b
      000A38 08               [12] 2307 	inc	r0
      000A39 F6               [12] 2308 	mov	@r0,a
      000A3A E5 81            [12] 2309 	mov	a,sp
      000A3C 24 FC            [12] 2310 	add	a,#0xfc
      000A3E F5 81            [12] 2311 	mov	sp,a
      000A40 E5 10            [12] 2312 	mov	a,_bp
      000A42 24 FA            [12] 2313 	add	a,#0xfa
      000A44 F8               [12] 2314 	mov	r0,a
      000A45 E6               [12] 2315 	mov	a,@r0
      000A46 C0 E0            [24] 2316 	push	acc
      000A48 08               [12] 2317 	inc	r0
      000A49 E6               [12] 2318 	mov	a,@r0
      000A4A C0 E0            [24] 2319 	push	acc
      000A4C 08               [12] 2320 	inc	r0
      000A4D E6               [12] 2321 	mov	a,@r0
      000A4E C0 E0            [24] 2322 	push	acc
      000A50 08               [12] 2323 	inc	r0
      000A51 E6               [12] 2324 	mov	a,@r0
      000A52 C0 E0            [24] 2325 	push	acc
      000A54 E5 10            [12] 2326 	mov	a,_bp
      000A56 24 F6            [12] 2327 	add	a,#0xf6
      000A58 F8               [12] 2328 	mov	r0,a
      000A59 86 82            [24] 2329 	mov	dpl, @r0
      000A5B 08               [12] 2330 	inc	r0
      000A5C 86 83            [24] 2331 	mov	dph, @r0
      000A5E 08               [12] 2332 	inc	r0
      000A5F 86 F0            [24] 2333 	mov	b, @r0
      000A61 08               [12] 2334 	inc	r0
      000A62 E6               [12] 2335 	mov	a, @r0
      000A63 12 2A AA         [24] 2336 	lcall	___fssub
      000A66 AA 82            [24] 2337 	mov	r2, dpl
      000A68 AB 83            [24] 2338 	mov	r3, dph
      000A6A AE F0            [24] 2339 	mov	r6, b
      000A6C FF               [12] 2340 	mov	r7, a
      000A6D E5 81            [12] 2341 	mov	a,sp
      000A6F 24 FC            [12] 2342 	add	a,#0xfc
      000A71 F5 81            [12] 2343 	mov	sp,a
      000A73 C0 02            [24] 2344 	push	ar2
      000A75 C0 03            [24] 2345 	push	ar3
      000A77 C0 06            [24] 2346 	push	ar6
      000A79 C0 07            [24] 2347 	push	ar7
      000A7B E5 10            [12] 2348 	mov	a,_bp
      000A7D 24 05            [12] 2349 	add	a,#0x05
      000A7F F8               [12] 2350 	mov	r0,a
      000A80 86 82            [24] 2351 	mov	dpl, @r0
      000A82 08               [12] 2352 	inc	r0
      000A83 86 83            [24] 2353 	mov	dph, @r0
      000A85 08               [12] 2354 	inc	r0
      000A86 86 F0            [24] 2355 	mov	b, @r0
      000A88 08               [12] 2356 	inc	r0
      000A89 E6               [12] 2357 	mov	a, @r0
      000A8A 12 2D 2C         [24] 2358 	lcall	___fsdiv
      000A8D A8 10            [24] 2359 	mov	r0,_bp
      000A8F 08               [12] 2360 	inc	r0
      000A90 A6 82            [24] 2361 	mov	@r0, dpl
      000A92 08               [12] 2362 	inc	r0
      000A93 A6 83            [24] 2363 	mov	@r0, dph
      000A95 08               [12] 2364 	inc	r0
      000A96 A6 F0            [24] 2365 	mov	@r0, b
      000A98 08               [12] 2366 	inc	r0
      000A99 F6               [12] 2367 	mov	@r0,a
      000A9A E5 81            [12] 2368 	mov	a,sp
      000A9C 24 FC            [12] 2369 	add	a,#0xfc
      000A9E F5 81            [12] 2370 	mov	sp,a
      000AA0                       2371 00109$:
                           0009E3  2372 	C$fuzzy.h$242$1_0$64 ==.
                                   2373 ;	../../fuzzy.h:242: return fuzzy_8051_hedge(result, hedge);
      000AA0 E5 10            [12] 2374 	mov	a,_bp
      000AA2 24 F1            [12] 2375 	add	a,#0xf1
      000AA4 F8               [12] 2376 	mov	r0,a
      000AA5 E6               [12] 2377 	mov	a,@r0
      000AA6 C0 E0            [24] 2378 	push	acc
      000AA8 A8 10            [24] 2379 	mov	r0,_bp
      000AAA 08               [12] 2380 	inc	r0
      000AAB 86 82            [24] 2381 	mov	dpl, @r0
      000AAD 08               [12] 2382 	inc	r0
      000AAE 86 83            [24] 2383 	mov	dph, @r0
      000AB0 08               [12] 2384 	inc	r0
      000AB1 86 F0            [24] 2385 	mov	b, @r0
      000AB3 08               [12] 2386 	inc	r0
      000AB4 E6               [12] 2387 	mov	a, @r0
      000AB5 12 04 FA         [24] 2388 	lcall	_fuzzy_8051_hedge
      000AB8 AC 82            [24] 2389 	mov	r4, dpl
      000ABA AD 83            [24] 2390 	mov	r5, dph
      000ABC AE F0            [24] 2391 	mov	r6, b
      000ABE FF               [12] 2392 	mov	r7, a
      000ABF 15 81            [12] 2393 	dec	sp
      000AC1 8C 82            [24] 2394 	mov	dpl, r4
      000AC3 8D 83            [24] 2395 	mov	dph, r5
      000AC5 8E F0            [24] 2396 	mov	b, r6
      000AC7 EF               [12] 2397 	mov	a, r7
                           000A0B  2398 	C$fuzzy.h$243$1_0$64 ==.
                                   2399 ;	../../fuzzy.h:243: }
      000AC8 85 10 81         [24] 2400 	mov	sp,_bp
      000ACB D0 10            [24] 2401 	pop	_bp
                           000A10  2402 	C$fuzzy.h$243$1_0$64 ==.
                           000A10  2403 	XG$fuzzy_triangle$0$0 ==.
      000ACD 22               [24] 2404 	ret
                                   2405 ;------------------------------------------------------------
                                   2406 ;Allocation info for local variables in function 'fuzzy_trapezoid'
                                   2407 ;------------------------------------------------------------
                                   2408 ;b             Allocated to stack - _bp -6 +4 
                                   2409 ;c             Allocated to stack - _bp -10 +4 
                                   2410 ;d             Allocated to stack - _bp -14 +4 
                                   2411 ;x             Allocated to stack - _bp -18 +4 
                                   2412 ;hedge         Allocated to stack - _bp -19 +1 
                                   2413 ;a             Allocated to registers r7 r6 r5 r4 
                                   2414 ;result        Allocated to stack - _bp +1 +4 
                                   2415 ;sloc0         Allocated to stack - _bp +1 +4 
                                   2416 ;sloc1         Allocated to stack - _bp +5 +4 
                                   2417 ;------------------------------------------------------------
                           000A11  2418 	G$fuzzy_trapezoid$0$0 ==.
                           000A11  2419 	C$fuzzy.h$245$1_0$70 ==.
                                   2420 ;	../../fuzzy.h:245: float fuzzy_trapezoid(float a, float b, float c, float d, float x, fuzzy_hedge_t hedge)
                                   2421 ;	-----------------------------------------
                                   2422 ;	 function fuzzy_trapezoid
                                   2423 ;	-----------------------------------------
      000ACE                       2424 _fuzzy_trapezoid:
      000ACE C0 10            [24] 2425 	push	_bp
      000AD0 85 81 10         [24] 2426 	mov	_bp,sp
      000AD3 AF 82            [24] 2427 	mov	r7,dpl
      000AD5 AE 83            [24] 2428 	mov	r6,dph
      000AD7 AD F0            [24] 2429 	mov	r5,b
      000AD9 FC               [12] 2430 	mov	r4,a
      000ADA E5 81            [12] 2431 	mov	a,sp
      000ADC 24 08            [12] 2432 	add	a,#0x08
      000ADE F5 81            [12] 2433 	mov	sp,a
                           000A23  2434 	C$fuzzy.h$249$1_0$70 ==.
                                   2435 ;	../../fuzzy.h:249: if (a >= b || b > c || c >= d || x <= a || x >= d) {
      000AE0 C0 07            [24] 2436 	push	ar7
      000AE2 C0 06            [24] 2437 	push	ar6
      000AE4 C0 05            [24] 2438 	push	ar5
      000AE6 C0 04            [24] 2439 	push	ar4
      000AE8 E5 10            [12] 2440 	mov	a,_bp
      000AEA 24 FA            [12] 2441 	add	a,#0xfa
      000AEC F8               [12] 2442 	mov	r0,a
      000AED E6               [12] 2443 	mov	a,@r0
      000AEE C0 E0            [24] 2444 	push	acc
      000AF0 08               [12] 2445 	inc	r0
      000AF1 E6               [12] 2446 	mov	a,@r0
      000AF2 C0 E0            [24] 2447 	push	acc
      000AF4 08               [12] 2448 	inc	r0
      000AF5 E6               [12] 2449 	mov	a,@r0
      000AF6 C0 E0            [24] 2450 	push	acc
      000AF8 08               [12] 2451 	inc	r0
      000AF9 E6               [12] 2452 	mov	a,@r0
      000AFA C0 E0            [24] 2453 	push	acc
      000AFC 8F 82            [24] 2454 	mov	dpl, r7
      000AFE 8E 83            [24] 2455 	mov	dph, r6
      000B00 8D F0            [24] 2456 	mov	b, r5
      000B02 EC               [12] 2457 	mov	a, r4
      000B03 12 2B E5         [24] 2458 	lcall	___fslt
      000B06 E5 81            [12] 2459 	mov	a,sp
      000B08 24 FC            [12] 2460 	add	a,#0xfc
      000B0A F5 81            [12] 2461 	mov	sp,a
      000B0C D0 04            [24] 2462 	pop	ar4
      000B0E D0 05            [24] 2463 	pop	ar5
      000B10 D0 06            [24] 2464 	pop	ar6
      000B12 D0 07            [24] 2465 	pop	ar7
      000B14 E5 82            [12] 2466 	mov	a, dpl
      000B16 24 FF            [12] 2467 	add	a,#0xff
      000B18 92 00            [24] 2468 	mov	b0,c
      000B1A 40 03            [24] 2469 	jc	00159$
      000B1C 02 0C 2A         [24] 2470 	ljmp	00108$
      000B1F                       2471 00159$:
      000B1F C0 07            [24] 2472 	push	ar7
      000B21 C0 06            [24] 2473 	push	ar6
      000B23 C0 05            [24] 2474 	push	ar5
      000B25 C0 04            [24] 2475 	push	ar4
      000B27 E5 10            [12] 2476 	mov	a,_bp
      000B29 24 FA            [12] 2477 	add	a,#0xfa
      000B2B F8               [12] 2478 	mov	r0,a
      000B2C E6               [12] 2479 	mov	a,@r0
      000B2D C0 E0            [24] 2480 	push	acc
      000B2F 08               [12] 2481 	inc	r0
      000B30 E6               [12] 2482 	mov	a,@r0
      000B31 C0 E0            [24] 2483 	push	acc
      000B33 08               [12] 2484 	inc	r0
      000B34 E6               [12] 2485 	mov	a,@r0
      000B35 C0 E0            [24] 2486 	push	acc
      000B37 08               [12] 2487 	inc	r0
      000B38 E6               [12] 2488 	mov	a,@r0
      000B39 C0 E0            [24] 2489 	push	acc
      000B3B E5 10            [12] 2490 	mov	a,_bp
      000B3D 24 F6            [12] 2491 	add	a,#0xf6
      000B3F F8               [12] 2492 	mov	r0,a
      000B40 86 82            [24] 2493 	mov	dpl, @r0
      000B42 08               [12] 2494 	inc	r0
      000B43 86 83            [24] 2495 	mov	dph, @r0
      000B45 08               [12] 2496 	inc	r0
      000B46 86 F0            [24] 2497 	mov	b, @r0
      000B48 08               [12] 2498 	inc	r0
      000B49 E6               [12] 2499 	mov	a, @r0
      000B4A 12 2B E5         [24] 2500 	lcall	___fslt
      000B4D AB 82            [24] 2501 	mov	r3, dpl
      000B4F E5 81            [12] 2502 	mov	a,sp
      000B51 24 FC            [12] 2503 	add	a,#0xfc
      000B53 F5 81            [12] 2504 	mov	sp,a
      000B55 D0 04            [24] 2505 	pop	ar4
      000B57 D0 05            [24] 2506 	pop	ar5
      000B59 D0 06            [24] 2507 	pop	ar6
      000B5B D0 07            [24] 2508 	pop	ar7
      000B5D EB               [12] 2509 	mov	a,r3
      000B5E 60 03            [24] 2510 	jz	00160$
      000B60 02 0C 2A         [24] 2511 	ljmp	00108$
      000B63                       2512 00160$:
      000B63 C0 07            [24] 2513 	push	ar7
      000B65 C0 06            [24] 2514 	push	ar6
      000B67 C0 05            [24] 2515 	push	ar5
      000B69 C0 04            [24] 2516 	push	ar4
      000B6B E5 10            [12] 2517 	mov	a,_bp
      000B6D 24 F2            [12] 2518 	add	a,#0xf2
      000B6F F8               [12] 2519 	mov	r0,a
      000B70 E6               [12] 2520 	mov	a,@r0
      000B71 C0 E0            [24] 2521 	push	acc
      000B73 08               [12] 2522 	inc	r0
      000B74 E6               [12] 2523 	mov	a,@r0
      000B75 C0 E0            [24] 2524 	push	acc
      000B77 08               [12] 2525 	inc	r0
      000B78 E6               [12] 2526 	mov	a,@r0
      000B79 C0 E0            [24] 2527 	push	acc
      000B7B 08               [12] 2528 	inc	r0
      000B7C E6               [12] 2529 	mov	a,@r0
      000B7D C0 E0            [24] 2530 	push	acc
      000B7F E5 10            [12] 2531 	mov	a,_bp
      000B81 24 F6            [12] 2532 	add	a,#0xf6
      000B83 F8               [12] 2533 	mov	r0,a
      000B84 86 82            [24] 2534 	mov	dpl, @r0
      000B86 08               [12] 2535 	inc	r0
      000B87 86 83            [24] 2536 	mov	dph, @r0
      000B89 08               [12] 2537 	inc	r0
      000B8A 86 F0            [24] 2538 	mov	b, @r0
      000B8C 08               [12] 2539 	inc	r0
      000B8D E6               [12] 2540 	mov	a, @r0
      000B8E 12 2B E5         [24] 2541 	lcall	___fslt
      000B91 E5 81            [12] 2542 	mov	a,sp
      000B93 24 FC            [12] 2543 	add	a,#0xfc
      000B95 F5 81            [12] 2544 	mov	sp,a
      000B97 D0 04            [24] 2545 	pop	ar4
      000B99 D0 05            [24] 2546 	pop	ar5
      000B9B D0 06            [24] 2547 	pop	ar6
      000B9D D0 07            [24] 2548 	pop	ar7
      000B9F E5 82            [12] 2549 	mov	a, dpl
      000BA1 24 FF            [12] 2550 	add	a,#0xff
      000BA3 92 00            [24] 2551 	mov	b0,c
      000BA5 40 03            [24] 2552 	jc	00161$
      000BA7 02 0C 2A         [24] 2553 	ljmp	00108$
      000BAA                       2554 00161$:
      000BAA C0 07            [24] 2555 	push	ar7
      000BAC C0 06            [24] 2556 	push	ar6
      000BAE C0 05            [24] 2557 	push	ar5
      000BB0 C0 04            [24] 2558 	push	ar4
      000BB2 E5 10            [12] 2559 	mov	a,_bp
      000BB4 24 EE            [12] 2560 	add	a,#0xee
      000BB6 F8               [12] 2561 	mov	r0,a
      000BB7 E6               [12] 2562 	mov	a,@r0
      000BB8 C0 E0            [24] 2563 	push	acc
      000BBA 08               [12] 2564 	inc	r0
      000BBB E6               [12] 2565 	mov	a,@r0
      000BBC C0 E0            [24] 2566 	push	acc
      000BBE 08               [12] 2567 	inc	r0
      000BBF E6               [12] 2568 	mov	a,@r0
      000BC0 C0 E0            [24] 2569 	push	acc
      000BC2 08               [12] 2570 	inc	r0
      000BC3 E6               [12] 2571 	mov	a,@r0
      000BC4 C0 E0            [24] 2572 	push	acc
      000BC6 8F 82            [24] 2573 	mov	dpl, r7
      000BC8 8E 83            [24] 2574 	mov	dph, r6
      000BCA 8D F0            [24] 2575 	mov	b, r5
      000BCC EC               [12] 2576 	mov	a, r4
      000BCD 12 2B E5         [24] 2577 	lcall	___fslt
      000BD0 E5 81            [12] 2578 	mov	a,sp
      000BD2 24 FC            [12] 2579 	add	a,#0xfc
      000BD4 F5 81            [12] 2580 	mov	sp,a
      000BD6 D0 04            [24] 2581 	pop	ar4
      000BD8 D0 05            [24] 2582 	pop	ar5
      000BDA D0 06            [24] 2583 	pop	ar6
      000BDC D0 07            [24] 2584 	pop	ar7
      000BDE E5 82            [12] 2585 	mov	a, dpl
      000BE0 24 FF            [12] 2586 	add	a,#0xff
      000BE2 92 00            [24] 2587 	mov	b0,c
      000BE4 50 44            [24] 2588 	jnc	00108$
      000BE6 C0 07            [24] 2589 	push	ar7
      000BE8 C0 06            [24] 2590 	push	ar6
      000BEA C0 05            [24] 2591 	push	ar5
      000BEC C0 04            [24] 2592 	push	ar4
      000BEE E5 10            [12] 2593 	mov	a,_bp
      000BF0 24 F2            [12] 2594 	add	a,#0xf2
      000BF2 F8               [12] 2595 	mov	r0,a
      000BF3 E6               [12] 2596 	mov	a,@r0
      000BF4 C0 E0            [24] 2597 	push	acc
      000BF6 08               [12] 2598 	inc	r0
      000BF7 E6               [12] 2599 	mov	a,@r0
      000BF8 C0 E0            [24] 2600 	push	acc
      000BFA 08               [12] 2601 	inc	r0
      000BFB E6               [12] 2602 	mov	a,@r0
      000BFC C0 E0            [24] 2603 	push	acc
      000BFE 08               [12] 2604 	inc	r0
      000BFF E6               [12] 2605 	mov	a,@r0
      000C00 C0 E0            [24] 2606 	push	acc
      000C02 E5 10            [12] 2607 	mov	a,_bp
      000C04 24 EE            [12] 2608 	add	a,#0xee
      000C06 F8               [12] 2609 	mov	r0,a
      000C07 86 82            [24] 2610 	mov	dpl, @r0
      000C09 08               [12] 2611 	inc	r0
      000C0A 86 83            [24] 2612 	mov	dph, @r0
      000C0C 08               [12] 2613 	inc	r0
      000C0D 86 F0            [24] 2614 	mov	b, @r0
      000C0F 08               [12] 2615 	inc	r0
      000C10 E6               [12] 2616 	mov	a, @r0
      000C11 12 2B E5         [24] 2617 	lcall	___fslt
      000C14 E5 81            [12] 2618 	mov	a,sp
      000C16 24 FC            [12] 2619 	add	a,#0xfc
      000C18 F5 81            [12] 2620 	mov	sp,a
      000C1A D0 04            [24] 2621 	pop	ar4
      000C1C D0 05            [24] 2622 	pop	ar5
      000C1E D0 06            [24] 2623 	pop	ar6
      000C20 D0 07            [24] 2624 	pop	ar7
      000C22 E5 82            [12] 2625 	mov	a, dpl
      000C24 24 FF            [12] 2626 	add	a,#0xff
      000C26 92 00            [24] 2627 	mov	b0,c
      000C28 40 0E            [24] 2628 	jc	00109$
      000C2A                       2629 00108$:
                           000B6D  2630 	C$fuzzy.h$250$2_0$71 ==.
                                   2631 ;	../../fuzzy.h:250: result = 0.0f;
      000C2A A8 10            [24] 2632 	mov	r0,_bp
      000C2C 08               [12] 2633 	inc	r0
      000C2D E4               [12] 2634 	clr	a
      000C2E F6               [12] 2635 	mov	@r0,a
      000C2F 08               [12] 2636 	inc	r0
      000C30 F6               [12] 2637 	mov	@r0,a
      000C31 08               [12] 2638 	inc	r0
      000C32 F6               [12] 2639 	mov	@r0,a
      000C33 08               [12] 2640 	inc	r0
      000C34 F6               [12] 2641 	mov	@r0,a
      000C35 02 0E 37         [24] 2642 	ljmp	00110$
      000C38                       2643 00109$:
                           000B7B  2644 	C$fuzzy.h$252$1_0$70 ==.
                                   2645 ;	../../fuzzy.h:252: else if (x >= b && x <= c) {
      000C38 C0 07            [24] 2646 	push	ar7
      000C3A C0 06            [24] 2647 	push	ar6
      000C3C C0 05            [24] 2648 	push	ar5
      000C3E C0 04            [24] 2649 	push	ar4
      000C40 E5 10            [12] 2650 	mov	a,_bp
      000C42 24 FA            [12] 2651 	add	a,#0xfa
      000C44 F8               [12] 2652 	mov	r0,a
      000C45 E6               [12] 2653 	mov	a,@r0
      000C46 C0 E0            [24] 2654 	push	acc
      000C48 08               [12] 2655 	inc	r0
      000C49 E6               [12] 2656 	mov	a,@r0
      000C4A C0 E0            [24] 2657 	push	acc
      000C4C 08               [12] 2658 	inc	r0
      000C4D E6               [12] 2659 	mov	a,@r0
      000C4E C0 E0            [24] 2660 	push	acc
      000C50 08               [12] 2661 	inc	r0
      000C51 E6               [12] 2662 	mov	a,@r0
      000C52 C0 E0            [24] 2663 	push	acc
      000C54 E5 10            [12] 2664 	mov	a,_bp
      000C56 24 EE            [12] 2665 	add	a,#0xee
      000C58 F8               [12] 2666 	mov	r0,a
      000C59 86 82            [24] 2667 	mov	dpl, @r0
      000C5B 08               [12] 2668 	inc	r0
      000C5C 86 83            [24] 2669 	mov	dph, @r0
      000C5E 08               [12] 2670 	inc	r0
      000C5F 86 F0            [24] 2671 	mov	b, @r0
      000C61 08               [12] 2672 	inc	r0
      000C62 E6               [12] 2673 	mov	a, @r0
      000C63 12 2B E5         [24] 2674 	lcall	___fslt
      000C66 E5 81            [12] 2675 	mov	a,sp
      000C68 24 FC            [12] 2676 	add	a,#0xfc
      000C6A F5 81            [12] 2677 	mov	sp,a
      000C6C D0 04            [24] 2678 	pop	ar4
      000C6E D0 05            [24] 2679 	pop	ar5
      000C70 D0 06            [24] 2680 	pop	ar6
      000C72 D0 07            [24] 2681 	pop	ar7
      000C74 E5 82            [12] 2682 	mov	a, dpl
      000C76 24 FF            [12] 2683 	add	a,#0xff
      000C78 92 00            [24] 2684 	mov	b0,c
      000C7A 40 54            [24] 2685 	jc	00105$
      000C7C C0 07            [24] 2686 	push	ar7
      000C7E C0 06            [24] 2687 	push	ar6
      000C80 C0 05            [24] 2688 	push	ar5
      000C82 C0 04            [24] 2689 	push	ar4
      000C84 E5 10            [12] 2690 	mov	a,_bp
      000C86 24 EE            [12] 2691 	add	a,#0xee
      000C88 F8               [12] 2692 	mov	r0,a
      000C89 E6               [12] 2693 	mov	a,@r0
      000C8A C0 E0            [24] 2694 	push	acc
      000C8C 08               [12] 2695 	inc	r0
      000C8D E6               [12] 2696 	mov	a,@r0
      000C8E C0 E0            [24] 2697 	push	acc
      000C90 08               [12] 2698 	inc	r0
      000C91 E6               [12] 2699 	mov	a,@r0
      000C92 C0 E0            [24] 2700 	push	acc
      000C94 08               [12] 2701 	inc	r0
      000C95 E6               [12] 2702 	mov	a,@r0
      000C96 C0 E0            [24] 2703 	push	acc
      000C98 E5 10            [12] 2704 	mov	a,_bp
      000C9A 24 F6            [12] 2705 	add	a,#0xf6
      000C9C F8               [12] 2706 	mov	r0,a
      000C9D 86 82            [24] 2707 	mov	dpl, @r0
      000C9F 08               [12] 2708 	inc	r0
      000CA0 86 83            [24] 2709 	mov	dph, @r0
      000CA2 08               [12] 2710 	inc	r0
      000CA3 86 F0            [24] 2711 	mov	b, @r0
      000CA5 08               [12] 2712 	inc	r0
      000CA6 E6               [12] 2713 	mov	a, @r0
      000CA7 12 2B E5         [24] 2714 	lcall	___fslt
      000CAA E5 81            [12] 2715 	mov	a,sp
      000CAC 24 FC            [12] 2716 	add	a,#0xfc
      000CAE F5 81            [12] 2717 	mov	sp,a
      000CB0 D0 04            [24] 2718 	pop	ar4
      000CB2 D0 05            [24] 2719 	pop	ar5
      000CB4 D0 06            [24] 2720 	pop	ar6
      000CB6 D0 07            [24] 2721 	pop	ar7
      000CB8 E5 82            [12] 2722 	mov	a, dpl
      000CBA 24 FF            [12] 2723 	add	a,#0xff
      000CBC 92 00            [24] 2724 	mov	b0,c
      000CBE 40 10            [24] 2725 	jc	00105$
                           000C03  2726 	C$fuzzy.h$253$2_0$72 ==.
                                   2727 ;	../../fuzzy.h:253: result = 1.0f;
      000CC0 A8 10            [24] 2728 	mov	r0,_bp
      000CC2 08               [12] 2729 	inc	r0
      000CC3 E4               [12] 2730 	clr	a
      000CC4 F6               [12] 2731 	mov	@r0,a
      000CC5 08               [12] 2732 	inc	r0
      000CC6 F6               [12] 2733 	mov	@r0,a
      000CC7 08               [12] 2734 	inc	r0
      000CC8 76 80            [12] 2735 	mov	@r0,#0x80
      000CCA 08               [12] 2736 	inc	r0
      000CCB 76 3F            [12] 2737 	mov	@r0,#0x3f
      000CCD 02 0E 37         [24] 2738 	ljmp	00110$
      000CD0                       2739 00105$:
                           000C13  2740 	C$fuzzy.h$255$1_0$70 ==.
                                   2741 ;	../../fuzzy.h:255: else if (x < b) {
      000CD0 C0 07            [24] 2742 	push	ar7
      000CD2 C0 06            [24] 2743 	push	ar6
      000CD4 C0 05            [24] 2744 	push	ar5
      000CD6 C0 04            [24] 2745 	push	ar4
      000CD8 E5 10            [12] 2746 	mov	a,_bp
      000CDA 24 FA            [12] 2747 	add	a,#0xfa
      000CDC F8               [12] 2748 	mov	r0,a
      000CDD E6               [12] 2749 	mov	a,@r0
      000CDE C0 E0            [24] 2750 	push	acc
      000CE0 08               [12] 2751 	inc	r0
      000CE1 E6               [12] 2752 	mov	a,@r0
      000CE2 C0 E0            [24] 2753 	push	acc
      000CE4 08               [12] 2754 	inc	r0
      000CE5 E6               [12] 2755 	mov	a,@r0
      000CE6 C0 E0            [24] 2756 	push	acc
      000CE8 08               [12] 2757 	inc	r0
      000CE9 E6               [12] 2758 	mov	a,@r0
      000CEA C0 E0            [24] 2759 	push	acc
      000CEC E5 10            [12] 2760 	mov	a,_bp
      000CEE 24 EE            [12] 2761 	add	a,#0xee
      000CF0 F8               [12] 2762 	mov	r0,a
      000CF1 86 82            [24] 2763 	mov	dpl, @r0
      000CF3 08               [12] 2764 	inc	r0
      000CF4 86 83            [24] 2765 	mov	dph, @r0
      000CF6 08               [12] 2766 	inc	r0
      000CF7 86 F0            [24] 2767 	mov	b, @r0
      000CF9 08               [12] 2768 	inc	r0
      000CFA E6               [12] 2769 	mov	a, @r0
      000CFB 12 2B E5         [24] 2770 	lcall	___fslt
      000CFE AB 82            [24] 2771 	mov	r3, dpl
      000D00 E5 81            [12] 2772 	mov	a,sp
      000D02 24 FC            [12] 2773 	add	a,#0xfc
      000D04 F5 81            [12] 2774 	mov	sp,a
      000D06 D0 04            [24] 2775 	pop	ar4
      000D08 D0 05            [24] 2776 	pop	ar5
      000D0A D0 06            [24] 2777 	pop	ar6
      000D0C D0 07            [24] 2778 	pop	ar7
      000D0E EB               [12] 2779 	mov	a,r3
      000D0F 70 03            [24] 2780 	jnz	00166$
      000D11 02 0D 9B         [24] 2781 	ljmp	00102$
      000D14                       2782 00166$:
                           000C57  2783 	C$fuzzy.h$256$1_0$70 ==.
                                   2784 ;	../../fuzzy.h:256: result = (x - a) / (b - a);
      000D14 C0 07            [24] 2785 	push	ar7
      000D16 C0 06            [24] 2786 	push	ar6
      000D18 C0 05            [24] 2787 	push	ar5
      000D1A C0 04            [24] 2788 	push	ar4
      000D1C C0 07            [24] 2789 	push	ar7
      000D1E C0 06            [24] 2790 	push	ar6
      000D20 C0 05            [24] 2791 	push	ar5
      000D22 C0 04            [24] 2792 	push	ar4
      000D24 E5 10            [12] 2793 	mov	a,_bp
      000D26 24 EE            [12] 2794 	add	a,#0xee
      000D28 F8               [12] 2795 	mov	r0,a
      000D29 86 82            [24] 2796 	mov	dpl, @r0
      000D2B 08               [12] 2797 	inc	r0
      000D2C 86 83            [24] 2798 	mov	dph, @r0
      000D2E 08               [12] 2799 	inc	r0
      000D2F 86 F0            [24] 2800 	mov	b, @r0
      000D31 08               [12] 2801 	inc	r0
      000D32 E6               [12] 2802 	mov	a, @r0
      000D33 12 2A AA         [24] 2803 	lcall	___fssub
      000D36 C8               [12] 2804 	xch	a,r0
      000D37 E5 10            [12] 2805 	mov	a,_bp
      000D39 24 05            [12] 2806 	add	a,#0x05
      000D3B C8               [12] 2807 	xch	a,r0
      000D3C A6 82            [24] 2808 	mov	@r0, dpl
      000D3E 08               [12] 2809 	inc	r0
      000D3F A6 83            [24] 2810 	mov	@r0, dph
      000D41 08               [12] 2811 	inc	r0
      000D42 A6 F0            [24] 2812 	mov	@r0, b
      000D44 08               [12] 2813 	inc	r0
      000D45 F6               [12] 2814 	mov	@r0,a
      000D46 E5 81            [12] 2815 	mov	a,sp
      000D48 24 FC            [12] 2816 	add	a,#0xfc
      000D4A F5 81            [12] 2817 	mov	sp,a
      000D4C E5 10            [12] 2818 	mov	a,_bp
      000D4E 24 FA            [12] 2819 	add	a,#0xfa
      000D50 F8               [12] 2820 	mov	r0,a
      000D51 86 82            [24] 2821 	mov	dpl, @r0
      000D53 08               [12] 2822 	inc	r0
      000D54 86 83            [24] 2823 	mov	dph, @r0
      000D56 08               [12] 2824 	inc	r0
      000D57 86 F0            [24] 2825 	mov	b, @r0
      000D59 08               [12] 2826 	inc	r0
      000D5A E6               [12] 2827 	mov	a, @r0
      000D5B 12 2A AA         [24] 2828 	lcall	___fssub
      000D5E AC 82            [24] 2829 	mov	r4, dpl
      000D60 AD 83            [24] 2830 	mov	r5, dph
      000D62 AE F0            [24] 2831 	mov	r6, b
      000D64 FF               [12] 2832 	mov	r7, a
      000D65 E5 81            [12] 2833 	mov	a,sp
      000D67 24 FC            [12] 2834 	add	a,#0xfc
      000D69 F5 81            [12] 2835 	mov	sp,a
      000D6B C0 04            [24] 2836 	push	ar4
      000D6D C0 05            [24] 2837 	push	ar5
      000D6F C0 06            [24] 2838 	push	ar6
      000D71 C0 07            [24] 2839 	push	ar7
      000D73 E5 10            [12] 2840 	mov	a,_bp
      000D75 24 05            [12] 2841 	add	a,#0x05
      000D77 F8               [12] 2842 	mov	r0,a
      000D78 86 82            [24] 2843 	mov	dpl, @r0
      000D7A 08               [12] 2844 	inc	r0
      000D7B 86 83            [24] 2845 	mov	dph, @r0
      000D7D 08               [12] 2846 	inc	r0
      000D7E 86 F0            [24] 2847 	mov	b, @r0
      000D80 08               [12] 2848 	inc	r0
      000D81 E6               [12] 2849 	mov	a, @r0
      000D82 12 2D 2C         [24] 2850 	lcall	___fsdiv
      000D85 A8 10            [24] 2851 	mov	r0,_bp
      000D87 08               [12] 2852 	inc	r0
      000D88 A6 82            [24] 2853 	mov	@r0, dpl
      000D8A 08               [12] 2854 	inc	r0
      000D8B A6 83            [24] 2855 	mov	@r0, dph
      000D8D 08               [12] 2856 	inc	r0
      000D8E A6 F0            [24] 2857 	mov	@r0, b
      000D90 08               [12] 2858 	inc	r0
      000D91 F6               [12] 2859 	mov	@r0,a
      000D92 E5 81            [12] 2860 	mov	a,sp
      000D94 24 FC            [12] 2861 	add	a,#0xfc
      000D96 F5 81            [12] 2862 	mov	sp,a
      000D98 02 0E 37         [24] 2863 	ljmp	00110$
      000D9B                       2864 00102$:
                           000CDE  2865 	C$fuzzy.h$259$1_0$70 ==.
                                   2866 ;	../../fuzzy.h:259: result = (d - x) / (d - c);
      000D9B E5 10            [12] 2867 	mov	a,_bp
      000D9D 24 EE            [12] 2868 	add	a,#0xee
      000D9F F8               [12] 2869 	mov	r0,a
      000DA0 E6               [12] 2870 	mov	a,@r0
      000DA1 C0 E0            [24] 2871 	push	acc
      000DA3 08               [12] 2872 	inc	r0
      000DA4 E6               [12] 2873 	mov	a,@r0
      000DA5 C0 E0            [24] 2874 	push	acc
      000DA7 08               [12] 2875 	inc	r0
      000DA8 E6               [12] 2876 	mov	a,@r0
      000DA9 C0 E0            [24] 2877 	push	acc
      000DAB 08               [12] 2878 	inc	r0
      000DAC E6               [12] 2879 	mov	a,@r0
      000DAD C0 E0            [24] 2880 	push	acc
      000DAF E5 10            [12] 2881 	mov	a,_bp
      000DB1 24 F2            [12] 2882 	add	a,#0xf2
      000DB3 F8               [12] 2883 	mov	r0,a
      000DB4 86 82            [24] 2884 	mov	dpl, @r0
      000DB6 08               [12] 2885 	inc	r0
      000DB7 86 83            [24] 2886 	mov	dph, @r0
      000DB9 08               [12] 2887 	inc	r0
      000DBA 86 F0            [24] 2888 	mov	b, @r0
      000DBC 08               [12] 2889 	inc	r0
      000DBD E6               [12] 2890 	mov	a, @r0
      000DBE 12 2A AA         [24] 2891 	lcall	___fssub
      000DC1 C8               [12] 2892 	xch	a,r0
      000DC2 E5 10            [12] 2893 	mov	a,_bp
      000DC4 24 05            [12] 2894 	add	a,#0x05
      000DC6 C8               [12] 2895 	xch	a,r0
      000DC7 A6 82            [24] 2896 	mov	@r0, dpl
      000DC9 08               [12] 2897 	inc	r0
      000DCA A6 83            [24] 2898 	mov	@r0, dph
      000DCC 08               [12] 2899 	inc	r0
      000DCD A6 F0            [24] 2900 	mov	@r0, b
      000DCF 08               [12] 2901 	inc	r0
      000DD0 F6               [12] 2902 	mov	@r0,a
      000DD1 E5 81            [12] 2903 	mov	a,sp
      000DD3 24 FC            [12] 2904 	add	a,#0xfc
      000DD5 F5 81            [12] 2905 	mov	sp,a
      000DD7 E5 10            [12] 2906 	mov	a,_bp
      000DD9 24 F6            [12] 2907 	add	a,#0xf6
      000DDB F8               [12] 2908 	mov	r0,a
      000DDC E6               [12] 2909 	mov	a,@r0
      000DDD C0 E0            [24] 2910 	push	acc
      000DDF 08               [12] 2911 	inc	r0
      000DE0 E6               [12] 2912 	mov	a,@r0
      000DE1 C0 E0            [24] 2913 	push	acc
      000DE3 08               [12] 2914 	inc	r0
      000DE4 E6               [12] 2915 	mov	a,@r0
      000DE5 C0 E0            [24] 2916 	push	acc
      000DE7 08               [12] 2917 	inc	r0
      000DE8 E6               [12] 2918 	mov	a,@r0
      000DE9 C0 E0            [24] 2919 	push	acc
      000DEB E5 10            [12] 2920 	mov	a,_bp
      000DED 24 F2            [12] 2921 	add	a,#0xf2
      000DEF F8               [12] 2922 	mov	r0,a
      000DF0 86 82            [24] 2923 	mov	dpl, @r0
      000DF2 08               [12] 2924 	inc	r0
      000DF3 86 83            [24] 2925 	mov	dph, @r0
      000DF5 08               [12] 2926 	inc	r0
      000DF6 86 F0            [24] 2927 	mov	b, @r0
      000DF8 08               [12] 2928 	inc	r0
      000DF9 E6               [12] 2929 	mov	a, @r0
      000DFA 12 2A AA         [24] 2930 	lcall	___fssub
      000DFD AA 82            [24] 2931 	mov	r2, dpl
      000DFF AB 83            [24] 2932 	mov	r3, dph
      000E01 AE F0            [24] 2933 	mov	r6, b
      000E03 FF               [12] 2934 	mov	r7, a
      000E04 E5 81            [12] 2935 	mov	a,sp
      000E06 24 FC            [12] 2936 	add	a,#0xfc
      000E08 F5 81            [12] 2937 	mov	sp,a
      000E0A C0 02            [24] 2938 	push	ar2
      000E0C C0 03            [24] 2939 	push	ar3
      000E0E C0 06            [24] 2940 	push	ar6
      000E10 C0 07            [24] 2941 	push	ar7
      000E12 E5 10            [12] 2942 	mov	a,_bp
      000E14 24 05            [12] 2943 	add	a,#0x05
      000E16 F8               [12] 2944 	mov	r0,a
      000E17 86 82            [24] 2945 	mov	dpl, @r0
      000E19 08               [12] 2946 	inc	r0
      000E1A 86 83            [24] 2947 	mov	dph, @r0
      000E1C 08               [12] 2948 	inc	r0
      000E1D 86 F0            [24] 2949 	mov	b, @r0
      000E1F 08               [12] 2950 	inc	r0
      000E20 E6               [12] 2951 	mov	a, @r0
      000E21 12 2D 2C         [24] 2952 	lcall	___fsdiv
      000E24 A8 10            [24] 2953 	mov	r0,_bp
      000E26 08               [12] 2954 	inc	r0
      000E27 A6 82            [24] 2955 	mov	@r0, dpl
      000E29 08               [12] 2956 	inc	r0
      000E2A A6 83            [24] 2957 	mov	@r0, dph
      000E2C 08               [12] 2958 	inc	r0
      000E2D A6 F0            [24] 2959 	mov	@r0, b
      000E2F 08               [12] 2960 	inc	r0
      000E30 F6               [12] 2961 	mov	@r0,a
      000E31 E5 81            [12] 2962 	mov	a,sp
      000E33 24 FC            [12] 2963 	add	a,#0xfc
      000E35 F5 81            [12] 2964 	mov	sp,a
      000E37                       2965 00110$:
                           000D7A  2966 	C$fuzzy.h$262$1_0$70 ==.
                                   2967 ;	../../fuzzy.h:262: return fuzzy_8051_hedge(result, hedge);
      000E37 E5 10            [12] 2968 	mov	a,_bp
      000E39 24 ED            [12] 2969 	add	a,#0xed
      000E3B F8               [12] 2970 	mov	r0,a
      000E3C E6               [12] 2971 	mov	a,@r0
      000E3D C0 E0            [24] 2972 	push	acc
      000E3F A8 10            [24] 2973 	mov	r0,_bp
      000E41 08               [12] 2974 	inc	r0
      000E42 86 82            [24] 2975 	mov	dpl, @r0
      000E44 08               [12] 2976 	inc	r0
      000E45 86 83            [24] 2977 	mov	dph, @r0
      000E47 08               [12] 2978 	inc	r0
      000E48 86 F0            [24] 2979 	mov	b, @r0
      000E4A 08               [12] 2980 	inc	r0
      000E4B E6               [12] 2981 	mov	a, @r0
      000E4C 12 04 FA         [24] 2982 	lcall	_fuzzy_8051_hedge
      000E4F AC 82            [24] 2983 	mov	r4, dpl
      000E51 AD 83            [24] 2984 	mov	r5, dph
      000E53 AE F0            [24] 2985 	mov	r6, b
      000E55 FF               [12] 2986 	mov	r7, a
      000E56 15 81            [12] 2987 	dec	sp
      000E58 8C 82            [24] 2988 	mov	dpl, r4
      000E5A 8D 83            [24] 2989 	mov	dph, r5
      000E5C 8E F0            [24] 2990 	mov	b, r6
      000E5E EF               [12] 2991 	mov	a, r7
                           000DA2  2992 	C$fuzzy.h$263$1_0$70 ==.
                                   2993 ;	../../fuzzy.h:263: }
      000E5F 85 10 81         [24] 2994 	mov	sp,_bp
      000E62 D0 10            [24] 2995 	pop	_bp
                           000DA7  2996 	C$fuzzy.h$263$1_0$70 ==.
                           000DA7  2997 	XG$fuzzy_trapezoid$0$0 ==.
      000E64 22               [24] 2998 	ret
                                   2999 ;------------------------------------------------------------
                                   3000 ;Allocation info for local variables in function 'fuzzy_8051_eval'
                                   3001 ;------------------------------------------------------------
                                   3002 ;value         Allocated to stack - _bp -6 +4 
                                   3003 ;variable      Allocated to stack - _bp +1 +3 
                                   3004 ;sloc0         Allocated to stack - _bp +4 +1 
                                   3005 ;sloc1         Allocated to stack - _bp +5 +1 
                                   3006 ;sloc2         Allocated to stack - _bp +5 +4 
                                   3007 ;sloc3         Allocated to stack - _bp +9 +4 
                                   3008 ;sloc4         Allocated to stack - _bp +13 +4 
                                   3009 ;sloc5         Allocated to stack - _bp +17 +4 
                                   3010 ;------------------------------------------------------------
                           000DA8  3011 	Fsugeno_demo$fuzzy_8051_eval$0$0 ==.
                           000DA8  3012 	C$fuzzy.h$265$1_0$76 ==.
                                   3013 ;	../../fuzzy.h:265: static float fuzzy_8051_eval(const fuzzy_variable_8051_t *variable, float value)
                                   3014 ;	-----------------------------------------
                                   3015 ;	 function fuzzy_8051_eval
                                   3016 ;	-----------------------------------------
      000E65                       3017 _fuzzy_8051_eval:
      000E65 C0 10            [24] 3018 	push	_bp
      000E67 85 81 10         [24] 3019 	mov	_bp,sp
      000E6A C0 82            [24] 3020 	push	dpl
      000E6C C0 83            [24] 3021 	push	dph
      000E6E C0 F0            [24] 3022 	push	b
      000E70 E5 81            [12] 3023 	mov	a,sp
      000E72 24 11            [12] 3024 	add	a,#0x11
      000E74 F5 81            [12] 3025 	mov	sp,a
                           000DB9  3026 	C$fuzzy.h$267$1_0$76 ==.
                                   3027 ;	../../fuzzy.h:267: if (variable->shape == FUZZY_SHAPE_RAMP) {
      000E76 A8 10            [24] 3028 	mov	r0,_bp
      000E78 08               [12] 3029 	inc	r0
      000E79 86 02            [24] 3030 	mov	ar2,@r0
      000E7B 08               [12] 3031 	inc	r0
      000E7C 86 03            [24] 3032 	mov	ar3,@r0
      000E7E 08               [12] 3033 	inc	r0
      000E7F 86 04            [24] 3034 	mov	ar4,@r0
      000E81 8A 82            [24] 3035 	mov	dpl,r2
      000E83 8B 83            [24] 3036 	mov	dph,r3
      000E85 8C F0            [24] 3037 	mov	b,r4
      000E87 12 2D EF         [24] 3038 	lcall	__gptrget
      000E8A FC               [12] 3039 	mov	r4,a
      000E8B 60 03            [24] 3040 	jz	00127$
      000E8D 02 0F 95         [24] 3041 	ljmp	00102$
      000E90                       3042 00127$:
                           000DD3  3043 	C$fuzzy.h$268$2_0$77 ==.
                                   3044 ;	../../fuzzy.h:268: return fuzzy_ramp(variable->parameters[0], variable->parameters[1], value, variable->parameters[2] != 0.0f, variable->hedge);
      000E90 A8 10            [24] 3045 	mov	r0,_bp
      000E92 08               [12] 3046 	inc	r0
      000E93 74 01            [12] 3047 	mov	a,#0x01
      000E95 26               [12] 3048 	add	a, @r0
      000E96 FA               [12] 3049 	mov	r2,a
      000E97 E4               [12] 3050 	clr	a
      000E98 08               [12] 3051 	inc	r0
      000E99 36               [12] 3052 	addc	a, @r0
      000E9A FB               [12] 3053 	mov	r3,a
      000E9B 08               [12] 3054 	inc	r0
      000E9C 86 07            [24] 3055 	mov	ar7,@r0
      000E9E 8A 82            [24] 3056 	mov	dpl,r2
      000EA0 8B 83            [24] 3057 	mov	dph,r3
      000EA2 8F F0            [24] 3058 	mov	b,r7
      000EA4 12 2D EF         [24] 3059 	lcall	__gptrget
      000EA7 FC               [12] 3060 	mov	r4,a
      000EA8 A8 10            [24] 3061 	mov	r0,_bp
      000EAA 08               [12] 3062 	inc	r0
      000EAB 74 0A            [12] 3063 	mov	a,#0x0a
      000EAD 26               [12] 3064 	add	a, @r0
      000EAE FD               [12] 3065 	mov	r5,a
      000EAF E4               [12] 3066 	clr	a
      000EB0 08               [12] 3067 	inc	r0
      000EB1 36               [12] 3068 	addc	a, @r0
      000EB2 FE               [12] 3069 	mov	r6,a
      000EB3 08               [12] 3070 	inc	r0
      000EB4 86 07            [24] 3071 	mov	ar7,@r0
      000EB6 8D 82            [24] 3072 	mov	dpl,r5
      000EB8 8E 83            [24] 3073 	mov	dph,r6
      000EBA 8F F0            [24] 3074 	mov	b,r7
      000EBC 12 2D EF         [24] 3075 	lcall	__gptrget
      000EBF FD               [12] 3076 	mov	r5,a
      000EC0 A3               [24] 3077 	inc	dptr
      000EC1 12 2D EF         [24] 3078 	lcall	__gptrget
      000EC4 FE               [12] 3079 	mov	r6,a
      000EC5 A3               [24] 3080 	inc	dptr
      000EC6 12 2D EF         [24] 3081 	lcall	__gptrget
      000EC9 FF               [12] 3082 	mov	r7,a
      000ECA A3               [24] 3083 	inc	dptr
      000ECB 12 2D EF         [24] 3084 	lcall	__gptrget
      000ECE FB               [12] 3085 	mov	r3,a
      000ECF 8D F0            [24] 3086 	mov	b,r5
      000ED1 EE               [12] 3087 	mov	a,r6
      000ED2 42 F0            [12] 3088 	orl	b,a
      000ED4 EF               [12] 3089 	mov	a,r7
      000ED5 42 F0            [12] 3090 	orl	b,a
      000ED7 EB               [12] 3091 	mov	a,r3
      000ED8 54 7F            [12] 3092 	anl	a,#0x7F
      000EDA 45 F0            [12] 3093 	orl	a,b
      000EDC B4 01 00         [24] 3094 	cjne	a,#0x01,00128$
      000EDF                       3095 00128$:
      000EDF B3               [12] 3096 	cpl	c
      000EE0 92 00            [24] 3097 	mov	b0,c
      000EE2 E5 10            [12] 3098 	mov	a,_bp
      000EE4 24 04            [12] 3099 	add	a,#0x04
      000EE6 F8               [12] 3100 	mov	r0,a
      000EE7 A2 00            [12] 3101 	mov	c,b0
      000EE9 E4               [12] 3102 	clr	a
      000EEA 33               [12] 3103 	rlc	a
      000EEB F6               [12] 3104 	mov	@r0,a
      000EEC A8 10            [24] 3105 	mov	r0,_bp
      000EEE 08               [12] 3106 	inc	r0
      000EEF 74 06            [12] 3107 	mov	a,#0x06
      000EF1 26               [12] 3108 	add	a, @r0
      000EF2 FB               [12] 3109 	mov	r3,a
      000EF3 E4               [12] 3110 	clr	a
      000EF4 08               [12] 3111 	inc	r0
      000EF5 36               [12] 3112 	addc	a, @r0
      000EF6 FD               [12] 3113 	mov	r5,a
      000EF7 08               [12] 3114 	inc	r0
      000EF8 86 06            [24] 3115 	mov	ar6,@r0
      000EFA 8B 82            [24] 3116 	mov	dpl,r3
      000EFC 8D 83            [24] 3117 	mov	dph,r5
      000EFE 8E F0            [24] 3118 	mov	b,r6
      000F00 E5 10            [12] 3119 	mov	a,_bp
      000F02 24 05            [12] 3120 	add	a,#0x05
      000F04 F8               [12] 3121 	mov	r0,a
      000F05 12 2D EF         [24] 3122 	lcall	__gptrget
      000F08 F6               [12] 3123 	mov	@r0,a
      000F09 A3               [24] 3124 	inc	dptr
      000F0A 12 2D EF         [24] 3125 	lcall	__gptrget
      000F0D 08               [12] 3126 	inc	r0
      000F0E F6               [12] 3127 	mov	@r0,a
      000F0F A3               [24] 3128 	inc	dptr
      000F10 12 2D EF         [24] 3129 	lcall	__gptrget
      000F13 08               [12] 3130 	inc	r0
      000F14 F6               [12] 3131 	mov	@r0,a
      000F15 A3               [24] 3132 	inc	dptr
      000F16 12 2D EF         [24] 3133 	lcall	__gptrget
      000F19 08               [12] 3134 	inc	r0
      000F1A F6               [12] 3135 	mov	@r0,a
      000F1B A8 10            [24] 3136 	mov	r0,_bp
      000F1D 08               [12] 3137 	inc	r0
      000F1E 74 02            [12] 3138 	mov	a,#0x02
      000F20 26               [12] 3139 	add	a, @r0
      000F21 FA               [12] 3140 	mov	r2,a
      000F22 E4               [12] 3141 	clr	a
      000F23 08               [12] 3142 	inc	r0
      000F24 36               [12] 3143 	addc	a, @r0
      000F25 FE               [12] 3144 	mov	r6,a
      000F26 08               [12] 3145 	inc	r0
      000F27 86 07            [24] 3146 	mov	ar7,@r0
      000F29 8A 82            [24] 3147 	mov	dpl,r2
      000F2B 8E 83            [24] 3148 	mov	dph,r6
      000F2D 8F F0            [24] 3149 	mov	b,r7
      000F2F 12 2D EF         [24] 3150 	lcall	__gptrget
      000F32 FA               [12] 3151 	mov	r2,a
      000F33 A3               [24] 3152 	inc	dptr
      000F34 12 2D EF         [24] 3153 	lcall	__gptrget
      000F37 FE               [12] 3154 	mov	r6,a
      000F38 A3               [24] 3155 	inc	dptr
      000F39 12 2D EF         [24] 3156 	lcall	__gptrget
      000F3C FF               [12] 3157 	mov	r7,a
      000F3D A3               [24] 3158 	inc	dptr
      000F3E 12 2D EF         [24] 3159 	lcall	__gptrget
      000F41 FD               [12] 3160 	mov	r5,a
      000F42 C0 04            [24] 3161 	push	ar4
      000F44 E5 10            [12] 3162 	mov	a,_bp
      000F46 24 04            [12] 3163 	add	a,#0x04
      000F48 F8               [12] 3164 	mov	r0,a
      000F49 E6               [12] 3165 	mov	a,@r0
      000F4A C0 E0            [24] 3166 	push	acc
      000F4C E5 10            [12] 3167 	mov	a,_bp
      000F4E 24 FA            [12] 3168 	add	a,#0xfa
      000F50 F8               [12] 3169 	mov	r0,a
      000F51 E6               [12] 3170 	mov	a,@r0
      000F52 C0 E0            [24] 3171 	push	acc
      000F54 08               [12] 3172 	inc	r0
      000F55 E6               [12] 3173 	mov	a,@r0
      000F56 C0 E0            [24] 3174 	push	acc
      000F58 08               [12] 3175 	inc	r0
      000F59 E6               [12] 3176 	mov	a,@r0
      000F5A C0 E0            [24] 3177 	push	acc
      000F5C 08               [12] 3178 	inc	r0
      000F5D E6               [12] 3179 	mov	a,@r0
      000F5E C0 E0            [24] 3180 	push	acc
      000F60 E5 10            [12] 3181 	mov	a,_bp
      000F62 24 05            [12] 3182 	add	a,#0x05
      000F64 F8               [12] 3183 	mov	r0,a
      000F65 E6               [12] 3184 	mov	a,@r0
      000F66 C0 E0            [24] 3185 	push	acc
      000F68 08               [12] 3186 	inc	r0
      000F69 E6               [12] 3187 	mov	a,@r0
      000F6A C0 E0            [24] 3188 	push	acc
      000F6C 08               [12] 3189 	inc	r0
      000F6D E6               [12] 3190 	mov	a,@r0
      000F6E C0 E0            [24] 3191 	push	acc
      000F70 08               [12] 3192 	inc	r0
      000F71 E6               [12] 3193 	mov	a,@r0
      000F72 C0 E0            [24] 3194 	push	acc
      000F74 8A 82            [24] 3195 	mov	dpl, r2
      000F76 8E 83            [24] 3196 	mov	dph, r6
      000F78 8F F0            [24] 3197 	mov	b, r7
      000F7A ED               [12] 3198 	mov	a, r5
      000F7B 12 05 B6         [24] 3199 	lcall	_fuzzy_ramp
      000F7E AB 82            [24] 3200 	mov	r3, dpl
      000F80 AD 83            [24] 3201 	mov	r5, dph
      000F82 AE F0            [24] 3202 	mov	r6, b
      000F84 FF               [12] 3203 	mov	r7, a
      000F85 E5 81            [12] 3204 	mov	a,sp
      000F87 24 F6            [12] 3205 	add	a,#0xf6
      000F89 F5 81            [12] 3206 	mov	sp,a
      000F8B 8B 82            [24] 3207 	mov	dpl, r3
      000F8D 8D 83            [24] 3208 	mov	dph, r5
      000F8F 8E F0            [24] 3209 	mov	b, r6
      000F91 EF               [12] 3210 	mov	a, r7
      000F92 02 11 F0         [24] 3211 	ljmp	00107$
      000F95                       3212 00102$:
                           000ED8  3213 	C$fuzzy.h$271$1_0$76 ==.
                                   3214 ;	../../fuzzy.h:271: if (variable->shape == FUZZY_SHAPE_TRIANGLE) {
      000F95 BC 01 02         [24] 3215 	cjne	r4,#0x01,00129$
      000F98 80 03            [24] 3216 	sjmp	00130$
      000F9A                       3217 00129$:
      000F9A 02 10 99         [24] 3218 	ljmp	00104$
      000F9D                       3219 00130$:
                           000EE0  3220 	C$fuzzy.h$272$2_0$78 ==.
                                   3221 ;	../../fuzzy.h:272: return fuzzy_triangle(variable->parameters[0], variable->parameters[1], variable->parameters[2], value, variable->hedge);
      000F9D A8 10            [24] 3222 	mov	r0,_bp
      000F9F 08               [12] 3223 	inc	r0
      000FA0 74 01            [12] 3224 	mov	a,#0x01
      000FA2 26               [12] 3225 	add	a, @r0
      000FA3 FD               [12] 3226 	mov	r5,a
      000FA4 E4               [12] 3227 	clr	a
      000FA5 08               [12] 3228 	inc	r0
      000FA6 36               [12] 3229 	addc	a, @r0
      000FA7 FE               [12] 3230 	mov	r6,a
      000FA8 08               [12] 3231 	inc	r0
      000FA9 86 07            [24] 3232 	mov	ar7,@r0
      000FAB 8D 82            [24] 3233 	mov	dpl,r5
      000FAD 8E 83            [24] 3234 	mov	dph,r6
      000FAF 8F F0            [24] 3235 	mov	b,r7
      000FB1 12 2D EF         [24] 3236 	lcall	__gptrget
      000FB4 FC               [12] 3237 	mov	r4,a
      000FB5 A8 10            [24] 3238 	mov	r0,_bp
      000FB7 08               [12] 3239 	inc	r0
      000FB8 74 0A            [12] 3240 	mov	a,#0x0a
      000FBA 26               [12] 3241 	add	a, @r0
      000FBB FB               [12] 3242 	mov	r3,a
      000FBC E4               [12] 3243 	clr	a
      000FBD 08               [12] 3244 	inc	r0
      000FBE 36               [12] 3245 	addc	a, @r0
      000FBF FE               [12] 3246 	mov	r6,a
      000FC0 08               [12] 3247 	inc	r0
      000FC1 86 07            [24] 3248 	mov	ar7,@r0
      000FC3 8B 82            [24] 3249 	mov	dpl,r3
      000FC5 8E 83            [24] 3250 	mov	dph,r6
      000FC7 8F F0            [24] 3251 	mov	b,r7
      000FC9 E5 10            [12] 3252 	mov	a,_bp
      000FCB 24 09            [12] 3253 	add	a,#0x09
      000FCD F8               [12] 3254 	mov	r0,a
      000FCE 12 2D EF         [24] 3255 	lcall	__gptrget
      000FD1 F6               [12] 3256 	mov	@r0,a
      000FD2 A3               [24] 3257 	inc	dptr
      000FD3 12 2D EF         [24] 3258 	lcall	__gptrget
      000FD6 08               [12] 3259 	inc	r0
      000FD7 F6               [12] 3260 	mov	@r0,a
      000FD8 A3               [24] 3261 	inc	dptr
      000FD9 12 2D EF         [24] 3262 	lcall	__gptrget
      000FDC 08               [12] 3263 	inc	r0
      000FDD F6               [12] 3264 	mov	@r0,a
      000FDE A3               [24] 3265 	inc	dptr
      000FDF 12 2D EF         [24] 3266 	lcall	__gptrget
      000FE2 08               [12] 3267 	inc	r0
      000FE3 F6               [12] 3268 	mov	@r0,a
      000FE4 A8 10            [24] 3269 	mov	r0,_bp
      000FE6 08               [12] 3270 	inc	r0
      000FE7 74 06            [12] 3271 	mov	a,#0x06
      000FE9 26               [12] 3272 	add	a, @r0
      000FEA FD               [12] 3273 	mov	r5,a
      000FEB E4               [12] 3274 	clr	a
      000FEC 08               [12] 3275 	inc	r0
      000FED 36               [12] 3276 	addc	a, @r0
      000FEE FE               [12] 3277 	mov	r6,a
      000FEF 08               [12] 3278 	inc	r0
      000FF0 86 07            [24] 3279 	mov	ar7,@r0
      000FF2 8D 82            [24] 3280 	mov	dpl,r5
      000FF4 8E 83            [24] 3281 	mov	dph,r6
      000FF6 8F F0            [24] 3282 	mov	b,r7
      000FF8 E5 10            [12] 3283 	mov	a,_bp
      000FFA 24 0D            [12] 3284 	add	a,#0x0d
      000FFC F8               [12] 3285 	mov	r0,a
      000FFD 12 2D EF         [24] 3286 	lcall	__gptrget
      001000 F6               [12] 3287 	mov	@r0,a
      001001 A3               [24] 3288 	inc	dptr
      001002 12 2D EF         [24] 3289 	lcall	__gptrget
      001005 08               [12] 3290 	inc	r0
      001006 F6               [12] 3291 	mov	@r0,a
      001007 A3               [24] 3292 	inc	dptr
      001008 12 2D EF         [24] 3293 	lcall	__gptrget
      00100B 08               [12] 3294 	inc	r0
      00100C F6               [12] 3295 	mov	@r0,a
      00100D A3               [24] 3296 	inc	dptr
      00100E 12 2D EF         [24] 3297 	lcall	__gptrget
      001011 08               [12] 3298 	inc	r0
      001012 F6               [12] 3299 	mov	@r0,a
      001013 A8 10            [24] 3300 	mov	r0,_bp
      001015 08               [12] 3301 	inc	r0
      001016 74 02            [12] 3302 	mov	a,#0x02
      001018 26               [12] 3303 	add	a, @r0
      001019 FA               [12] 3304 	mov	r2,a
      00101A E4               [12] 3305 	clr	a
      00101B 08               [12] 3306 	inc	r0
      00101C 36               [12] 3307 	addc	a, @r0
      00101D FE               [12] 3308 	mov	r6,a
      00101E 08               [12] 3309 	inc	r0
      00101F 86 07            [24] 3310 	mov	ar7,@r0
      001021 8A 82            [24] 3311 	mov	dpl,r2
      001023 8E 83            [24] 3312 	mov	dph,r6
      001025 8F F0            [24] 3313 	mov	b,r7
      001027 12 2D EF         [24] 3314 	lcall	__gptrget
      00102A FA               [12] 3315 	mov	r2,a
      00102B A3               [24] 3316 	inc	dptr
      00102C 12 2D EF         [24] 3317 	lcall	__gptrget
      00102F FE               [12] 3318 	mov	r6,a
      001030 A3               [24] 3319 	inc	dptr
      001031 12 2D EF         [24] 3320 	lcall	__gptrget
      001034 FF               [12] 3321 	mov	r7,a
      001035 A3               [24] 3322 	inc	dptr
      001036 12 2D EF         [24] 3323 	lcall	__gptrget
      001039 FD               [12] 3324 	mov	r5,a
      00103A C0 04            [24] 3325 	push	ar4
      00103C E5 10            [12] 3326 	mov	a,_bp
      00103E 24 FA            [12] 3327 	add	a,#0xfa
      001040 F8               [12] 3328 	mov	r0,a
      001041 E6               [12] 3329 	mov	a,@r0
      001042 C0 E0            [24] 3330 	push	acc
      001044 08               [12] 3331 	inc	r0
      001045 E6               [12] 3332 	mov	a,@r0
      001046 C0 E0            [24] 3333 	push	acc
      001048 08               [12] 3334 	inc	r0
      001049 E6               [12] 3335 	mov	a,@r0
      00104A C0 E0            [24] 3336 	push	acc
      00104C 08               [12] 3337 	inc	r0
      00104D E6               [12] 3338 	mov	a,@r0
      00104E C0 E0            [24] 3339 	push	acc
      001050 E5 10            [12] 3340 	mov	a,_bp
      001052 24 09            [12] 3341 	add	a,#0x09
      001054 F8               [12] 3342 	mov	r0,a
      001055 E6               [12] 3343 	mov	a,@r0
      001056 C0 E0            [24] 3344 	push	acc
      001058 08               [12] 3345 	inc	r0
      001059 E6               [12] 3346 	mov	a,@r0
      00105A C0 E0            [24] 3347 	push	acc
      00105C 08               [12] 3348 	inc	r0
      00105D E6               [12] 3349 	mov	a,@r0
      00105E C0 E0            [24] 3350 	push	acc
      001060 08               [12] 3351 	inc	r0
      001061 E6               [12] 3352 	mov	a,@r0
      001062 C0 E0            [24] 3353 	push	acc
      001064 E5 10            [12] 3354 	mov	a,_bp
      001066 24 0D            [12] 3355 	add	a,#0x0d
      001068 F8               [12] 3356 	mov	r0,a
      001069 E6               [12] 3357 	mov	a,@r0
      00106A C0 E0            [24] 3358 	push	acc
      00106C 08               [12] 3359 	inc	r0
      00106D E6               [12] 3360 	mov	a,@r0
      00106E C0 E0            [24] 3361 	push	acc
      001070 08               [12] 3362 	inc	r0
      001071 E6               [12] 3363 	mov	a,@r0
      001072 C0 E0            [24] 3364 	push	acc
      001074 08               [12] 3365 	inc	r0
      001075 E6               [12] 3366 	mov	a,@r0
      001076 C0 E0            [24] 3367 	push	acc
      001078 8A 82            [24] 3368 	mov	dpl, r2
      00107A 8E 83            [24] 3369 	mov	dph, r6
      00107C 8F F0            [24] 3370 	mov	b, r7
      00107E ED               [12] 3371 	mov	a, r5
      00107F 12 07 C2         [24] 3372 	lcall	_fuzzy_triangle
      001082 AB 82            [24] 3373 	mov	r3, dpl
      001084 AD 83            [24] 3374 	mov	r5, dph
      001086 AE F0            [24] 3375 	mov	r6, b
      001088 FF               [12] 3376 	mov	r7, a
      001089 E5 81            [12] 3377 	mov	a,sp
      00108B 24 F3            [12] 3378 	add	a,#0xf3
      00108D F5 81            [12] 3379 	mov	sp,a
      00108F 8B 82            [24] 3380 	mov	dpl, r3
      001091 8D 83            [24] 3381 	mov	dph, r5
      001093 8E F0            [24] 3382 	mov	b, r6
      001095 EF               [12] 3383 	mov	a, r7
      001096 02 11 F0         [24] 3384 	ljmp	00107$
      001099                       3385 00104$:
                           000FDC  3386 	C$fuzzy.h$275$1_0$76 ==.
                                   3387 ;	../../fuzzy.h:275: if (variable->shape == FUZZY_SHAPE_TRAPEZOID) {
      001099 BC 02 02         [24] 3388 	cjne	r4,#0x02,00131$
      00109C 80 03            [24] 3389 	sjmp	00132$
      00109E                       3390 00131$:
      00109E 02 11 EA         [24] 3391 	ljmp	00106$
      0010A1                       3392 00132$:
                           000FE4  3393 	C$fuzzy.h$276$2_0$79 ==.
                                   3394 ;	../../fuzzy.h:276: return fuzzy_trapezoid(variable->parameters[0], variable->parameters[1], variable->parameters[2], variable->parameters[3], value, variable->hedge);
      0010A1 A8 10            [24] 3395 	mov	r0,_bp
      0010A3 08               [12] 3396 	inc	r0
      0010A4 74 01            [12] 3397 	mov	a,#0x01
      0010A6 26               [12] 3398 	add	a, @r0
      0010A7 FD               [12] 3399 	mov	r5,a
      0010A8 E4               [12] 3400 	clr	a
      0010A9 08               [12] 3401 	inc	r0
      0010AA 36               [12] 3402 	addc	a, @r0
      0010AB FE               [12] 3403 	mov	r6,a
      0010AC 08               [12] 3404 	inc	r0
      0010AD 86 07            [24] 3405 	mov	ar7,@r0
      0010AF 8D 82            [24] 3406 	mov	dpl,r5
      0010B1 8E 83            [24] 3407 	mov	dph,r6
      0010B3 8F F0            [24] 3408 	mov	b,r7
      0010B5 E5 10            [12] 3409 	mov	a,_bp
      0010B7 24 0D            [12] 3410 	add	a,#0x0d
      0010B9 F8               [12] 3411 	mov	r0,a
      0010BA 12 2D EF         [24] 3412 	lcall	__gptrget
      0010BD F6               [12] 3413 	mov	@r0,a
      0010BE A8 10            [24] 3414 	mov	r0,_bp
      0010C0 08               [12] 3415 	inc	r0
      0010C1 74 0E            [12] 3416 	mov	a,#0x0e
      0010C3 26               [12] 3417 	add	a, @r0
      0010C4 FC               [12] 3418 	mov	r4,a
      0010C5 E4               [12] 3419 	clr	a
      0010C6 08               [12] 3420 	inc	r0
      0010C7 36               [12] 3421 	addc	a, @r0
      0010C8 FE               [12] 3422 	mov	r6,a
      0010C9 08               [12] 3423 	inc	r0
      0010CA 86 07            [24] 3424 	mov	ar7,@r0
      0010CC 8C 82            [24] 3425 	mov	dpl,r4
      0010CE 8E 83            [24] 3426 	mov	dph,r6
      0010D0 8F F0            [24] 3427 	mov	b,r7
      0010D2 E5 10            [12] 3428 	mov	a,_bp
      0010D4 24 09            [12] 3429 	add	a,#0x09
      0010D6 F8               [12] 3430 	mov	r0,a
      0010D7 12 2D EF         [24] 3431 	lcall	__gptrget
      0010DA F6               [12] 3432 	mov	@r0,a
      0010DB A3               [24] 3433 	inc	dptr
      0010DC 12 2D EF         [24] 3434 	lcall	__gptrget
      0010DF 08               [12] 3435 	inc	r0
      0010E0 F6               [12] 3436 	mov	@r0,a
      0010E1 A3               [24] 3437 	inc	dptr
      0010E2 12 2D EF         [24] 3438 	lcall	__gptrget
      0010E5 08               [12] 3439 	inc	r0
      0010E6 F6               [12] 3440 	mov	@r0,a
      0010E7 A3               [24] 3441 	inc	dptr
      0010E8 12 2D EF         [24] 3442 	lcall	__gptrget
      0010EB 08               [12] 3443 	inc	r0
      0010EC F6               [12] 3444 	mov	@r0,a
      0010ED A8 10            [24] 3445 	mov	r0,_bp
      0010EF 08               [12] 3446 	inc	r0
      0010F0 74 0A            [12] 3447 	mov	a,#0x0a
      0010F2 26               [12] 3448 	add	a, @r0
      0010F3 FA               [12] 3449 	mov	r2,a
      0010F4 E4               [12] 3450 	clr	a
      0010F5 08               [12] 3451 	inc	r0
      0010F6 36               [12] 3452 	addc	a, @r0
      0010F7 FD               [12] 3453 	mov	r5,a
      0010F8 08               [12] 3454 	inc	r0
      0010F9 86 07            [24] 3455 	mov	ar7,@r0
      0010FB 8A 82            [24] 3456 	mov	dpl,r2
      0010FD 8D 83            [24] 3457 	mov	dph,r5
      0010FF 8F F0            [24] 3458 	mov	b,r7
      001101 E5 10            [12] 3459 	mov	a,_bp
      001103 24 05            [12] 3460 	add	a,#0x05
      001105 F8               [12] 3461 	mov	r0,a
      001106 12 2D EF         [24] 3462 	lcall	__gptrget
      001109 F6               [12] 3463 	mov	@r0,a
      00110A A3               [24] 3464 	inc	dptr
      00110B 12 2D EF         [24] 3465 	lcall	__gptrget
      00110E 08               [12] 3466 	inc	r0
      00110F F6               [12] 3467 	mov	@r0,a
      001110 A3               [24] 3468 	inc	dptr
      001111 12 2D EF         [24] 3469 	lcall	__gptrget
      001114 08               [12] 3470 	inc	r0
      001115 F6               [12] 3471 	mov	@r0,a
      001116 A3               [24] 3472 	inc	dptr
      001117 12 2D EF         [24] 3473 	lcall	__gptrget
      00111A 08               [12] 3474 	inc	r0
      00111B F6               [12] 3475 	mov	@r0,a
      00111C A8 10            [24] 3476 	mov	r0,_bp
      00111E 08               [12] 3477 	inc	r0
      00111F 74 06            [12] 3478 	mov	a,#0x06
      001121 26               [12] 3479 	add	a, @r0
      001122 FB               [12] 3480 	mov	r3,a
      001123 E4               [12] 3481 	clr	a
      001124 08               [12] 3482 	inc	r0
      001125 36               [12] 3483 	addc	a, @r0
      001126 FC               [12] 3484 	mov	r4,a
      001127 08               [12] 3485 	inc	r0
      001128 86 07            [24] 3486 	mov	ar7,@r0
      00112A 8B 82            [24] 3487 	mov	dpl,r3
      00112C 8C 83            [24] 3488 	mov	dph,r4
      00112E 8F F0            [24] 3489 	mov	b,r7
      001130 E5 10            [12] 3490 	mov	a,_bp
      001132 24 11            [12] 3491 	add	a,#0x11
      001134 F8               [12] 3492 	mov	r0,a
      001135 12 2D EF         [24] 3493 	lcall	__gptrget
      001138 F6               [12] 3494 	mov	@r0,a
      001139 A3               [24] 3495 	inc	dptr
      00113A 12 2D EF         [24] 3496 	lcall	__gptrget
      00113D 08               [12] 3497 	inc	r0
      00113E F6               [12] 3498 	mov	@r0,a
      00113F A3               [24] 3499 	inc	dptr
      001140 12 2D EF         [24] 3500 	lcall	__gptrget
      001143 08               [12] 3501 	inc	r0
      001144 F6               [12] 3502 	mov	@r0,a
      001145 A3               [24] 3503 	inc	dptr
      001146 12 2D EF         [24] 3504 	lcall	__gptrget
      001149 08               [12] 3505 	inc	r0
      00114A F6               [12] 3506 	mov	@r0,a
      00114B A8 10            [24] 3507 	mov	r0,_bp
      00114D 08               [12] 3508 	inc	r0
      00114E 74 02            [12] 3509 	mov	a,#0x02
      001150 26               [12] 3510 	add	a, @r0
      001151 FA               [12] 3511 	mov	r2,a
      001152 E4               [12] 3512 	clr	a
      001153 08               [12] 3513 	inc	r0
      001154 36               [12] 3514 	addc	a, @r0
      001155 FD               [12] 3515 	mov	r5,a
      001156 08               [12] 3516 	inc	r0
      001157 86 07            [24] 3517 	mov	ar7,@r0
      001159 8A 82            [24] 3518 	mov	dpl,r2
      00115B 8D 83            [24] 3519 	mov	dph,r5
      00115D 8F F0            [24] 3520 	mov	b,r7
      00115F 12 2D EF         [24] 3521 	lcall	__gptrget
      001162 FA               [12] 3522 	mov	r2,a
      001163 A3               [24] 3523 	inc	dptr
      001164 12 2D EF         [24] 3524 	lcall	__gptrget
      001167 FD               [12] 3525 	mov	r5,a
      001168 A3               [24] 3526 	inc	dptr
      001169 12 2D EF         [24] 3527 	lcall	__gptrget
      00116C FF               [12] 3528 	mov	r7,a
      00116D A3               [24] 3529 	inc	dptr
      00116E 12 2D EF         [24] 3530 	lcall	__gptrget
      001171 FE               [12] 3531 	mov	r6,a
      001172 E5 10            [12] 3532 	mov	a,_bp
      001174 24 0D            [12] 3533 	add	a,#0x0d
      001176 F8               [12] 3534 	mov	r0,a
      001177 E6               [12] 3535 	mov	a,@r0
      001178 C0 E0            [24] 3536 	push	acc
      00117A E5 10            [12] 3537 	mov	a,_bp
      00117C 24 FA            [12] 3538 	add	a,#0xfa
      00117E F8               [12] 3539 	mov	r0,a
      00117F E6               [12] 3540 	mov	a,@r0
      001180 C0 E0            [24] 3541 	push	acc
      001182 08               [12] 3542 	inc	r0
      001183 E6               [12] 3543 	mov	a,@r0
      001184 C0 E0            [24] 3544 	push	acc
      001186 08               [12] 3545 	inc	r0
      001187 E6               [12] 3546 	mov	a,@r0
      001188 C0 E0            [24] 3547 	push	acc
      00118A 08               [12] 3548 	inc	r0
      00118B E6               [12] 3549 	mov	a,@r0
      00118C C0 E0            [24] 3550 	push	acc
      00118E E5 10            [12] 3551 	mov	a,_bp
      001190 24 09            [12] 3552 	add	a,#0x09
      001192 F8               [12] 3553 	mov	r0,a
      001193 E6               [12] 3554 	mov	a,@r0
      001194 C0 E0            [24] 3555 	push	acc
      001196 08               [12] 3556 	inc	r0
      001197 E6               [12] 3557 	mov	a,@r0
      001198 C0 E0            [24] 3558 	push	acc
      00119A 08               [12] 3559 	inc	r0
      00119B E6               [12] 3560 	mov	a,@r0
      00119C C0 E0            [24] 3561 	push	acc
      00119E 08               [12] 3562 	inc	r0
      00119F E6               [12] 3563 	mov	a,@r0
      0011A0 C0 E0            [24] 3564 	push	acc
      0011A2 E5 10            [12] 3565 	mov	a,_bp
      0011A4 24 05            [12] 3566 	add	a,#0x05
      0011A6 F8               [12] 3567 	mov	r0,a
      0011A7 E6               [12] 3568 	mov	a,@r0
      0011A8 C0 E0            [24] 3569 	push	acc
      0011AA 08               [12] 3570 	inc	r0
      0011AB E6               [12] 3571 	mov	a,@r0
      0011AC C0 E0            [24] 3572 	push	acc
      0011AE 08               [12] 3573 	inc	r0
      0011AF E6               [12] 3574 	mov	a,@r0
      0011B0 C0 E0            [24] 3575 	push	acc
      0011B2 08               [12] 3576 	inc	r0
      0011B3 E6               [12] 3577 	mov	a,@r0
      0011B4 C0 E0            [24] 3578 	push	acc
      0011B6 E5 10            [12] 3579 	mov	a,_bp
      0011B8 24 11            [12] 3580 	add	a,#0x11
      0011BA F8               [12] 3581 	mov	r0,a
      0011BB E6               [12] 3582 	mov	a,@r0
      0011BC C0 E0            [24] 3583 	push	acc
      0011BE 08               [12] 3584 	inc	r0
      0011BF E6               [12] 3585 	mov	a,@r0
      0011C0 C0 E0            [24] 3586 	push	acc
      0011C2 08               [12] 3587 	inc	r0
      0011C3 E6               [12] 3588 	mov	a,@r0
      0011C4 C0 E0            [24] 3589 	push	acc
      0011C6 08               [12] 3590 	inc	r0
      0011C7 E6               [12] 3591 	mov	a,@r0
      0011C8 C0 E0            [24] 3592 	push	acc
      0011CA 8A 82            [24] 3593 	mov	dpl, r2
      0011CC 8D 83            [24] 3594 	mov	dph, r5
      0011CE 8F F0            [24] 3595 	mov	b, r7
      0011D0 EE               [12] 3596 	mov	a, r6
      0011D1 12 0A CE         [24] 3597 	lcall	_fuzzy_trapezoid
      0011D4 AC 82            [24] 3598 	mov	r4, dpl
      0011D6 AD 83            [24] 3599 	mov	r5, dph
      0011D8 AE F0            [24] 3600 	mov	r6, b
      0011DA FF               [12] 3601 	mov	r7, a
      0011DB E5 81            [12] 3602 	mov	a,sp
      0011DD 24 EF            [12] 3603 	add	a,#0xef
      0011DF F5 81            [12] 3604 	mov	sp,a
      0011E1 8C 82            [24] 3605 	mov	dpl, r4
      0011E3 8D 83            [24] 3606 	mov	dph, r5
      0011E5 8E F0            [24] 3607 	mov	b, r6
      0011E7 EF               [12] 3608 	mov	a, r7
      0011E8 80 06            [24] 3609 	sjmp	00107$
      0011EA                       3610 00106$:
                           00112D  3611 	C$fuzzy.h$279$1_0$76 ==.
                                   3612 ;	../../fuzzy.h:279: return 0.0f;
      0011EA 90 00 00         [24] 3613 	mov	dptr,#0x0000
      0011ED E4               [12] 3614 	clr	a
      0011EE F5 F0            [12] 3615 	mov	b,a
      0011F0                       3616 00107$:
                           001133  3617 	C$fuzzy.h$280$1_0$76 ==.
                                   3618 ;	../../fuzzy.h:280: }
      0011F0 85 10 81         [24] 3619 	mov	sp,_bp
      0011F3 D0 10            [24] 3620 	pop	_bp
                           001138  3621 	C$fuzzy.h$280$1_0$76 ==.
                           001138  3622 	XFsugeno_demo$fuzzy_8051_eval$0$0 ==.
      0011F5 22               [24] 3623 	ret
                                   3624 ;------------------------------------------------------------
                                   3625 ;Allocation info for local variables in function 'fuzzy_rules_add_8051'
                                   3626 ;------------------------------------------------------------
                                   3627 ;value         Allocated to stack - _bp -6 +4 
                                   3628 ;output        Allocated to stack - _bp -9 +3 
                                   3629 ;rules         Allocated to stack - _bp +1 +3 
                                   3630 ;index         Allocated to registers r3 
                                   3631 ;sloc0         Allocated to stack - _bp +5 +1 
                                   3632 ;sloc1         Allocated to stack - _bp +4 +3 
                                   3633 ;sloc2         Allocated to stack - _bp +7 +3 
                                   3634 ;------------------------------------------------------------
                           001139  3635 	G$fuzzy_rules_add_8051$0$0 ==.
                           001139  3636 	C$fuzzy.h$282$1_0$81 ==.
                                   3637 ;	../../fuzzy.h:282: bool fuzzy_rules_add_8051(fuzzy_rules_t *rules, float value, const fuzzy_variable_8051_t *output)
                                   3638 ;	-----------------------------------------
                                   3639 ;	 function fuzzy_rules_add_8051
                                   3640 ;	-----------------------------------------
      0011F6                       3641 _fuzzy_rules_add_8051:
      0011F6 C0 10            [24] 3642 	push	_bp
      0011F8 85 81 10         [24] 3643 	mov	_bp,sp
      0011FB C0 82            [24] 3644 	push	dpl
      0011FD C0 83            [24] 3645 	push	dph
      0011FF C0 F0            [24] 3646 	push	b
      001201 E5 81            [12] 3647 	mov	a,sp
      001203 24 06            [12] 3648 	add	a,#0x06
      001205 F5 81            [12] 3649 	mov	sp,a
                           00114A  3650 	C$fuzzy.h$286$1_0$81 ==.
                                   3651 ;	../../fuzzy.h:286: if (rules->count >= FUZZY_MAX_RULES) {
      001207 A8 10            [24] 3652 	mov	r0,_bp
      001209 08               [12] 3653 	inc	r0
      00120A E5 10            [12] 3654 	mov	a,_bp
      00120C 24 07            [12] 3655 	add	a,#0x07
      00120E F9               [12] 3656 	mov	r1,a
      00120F 74 70            [12] 3657 	mov	a,#0x70
      001211 26               [12] 3658 	add	a, @r0
      001212 F7               [12] 3659 	mov	@r1,a
      001213 E4               [12] 3660 	clr	a
      001214 08               [12] 3661 	inc	r0
      001215 36               [12] 3662 	addc	a, @r0
      001216 09               [12] 3663 	inc	r1
      001217 F7               [12] 3664 	mov	@r1,a
      001218 08               [12] 3665 	inc	r0
      001219 E6               [12] 3666 	mov	a,@r0
      00121A 09               [12] 3667 	inc	r1
      00121B F7               [12] 3668 	mov	@r1,a
      00121C E5 10            [12] 3669 	mov	a,_bp
      00121E 24 07            [12] 3670 	add	a,#0x07
      001220 F8               [12] 3671 	mov	r0,a
      001221 86 82            [24] 3672 	mov	dpl,@r0
      001223 08               [12] 3673 	inc	r0
      001224 86 83            [24] 3674 	mov	dph,@r0
      001226 08               [12] 3675 	inc	r0
      001227 86 F0            [24] 3676 	mov	b,@r0
      001229 12 2D EF         [24] 3677 	lcall	__gptrget
      00122C FF               [12] 3678 	mov	r7,a
      00122D BF 10 00         [24] 3679 	cjne	r7,#0x10,00111$
      001230                       3680 00111$:
      001230 40 06            [24] 3681 	jc	00102$
                           001175  3682 	C$fuzzy.h$287$2_0$82 ==.
                                   3683 ;	../../fuzzy.h:287: return false;
      001232 75 82 00         [24] 3684 	mov	dpl, #0x00
      001235 02 12 DB         [24] 3685 	ljmp	00103$
      001238                       3686 00102$:
                           00117B  3687 	C$fuzzy.h$290$1_0$81 ==.
                                   3688 ;	../../fuzzy.h:290: index = rules->count;
      001238 8F 03            [24] 3689 	mov	ar3,r7
                           00117D  3690 	C$fuzzy.h$291$1_0$81 ==.
                                   3691 ;	../../fuzzy.h:291: rules->rules[index].value = fuzzy_8051_clamp(value);
      00123A EB               [12] 3692 	mov	a,r3
      00123B 75 F0 07         [24] 3693 	mov	b,#0x07
      00123E A4               [48] 3694 	mul	ab
      00123F FA               [12] 3695 	mov	r2,a
      001240 A8 10            [24] 3696 	mov	r0,_bp
      001242 08               [12] 3697 	inc	r0
      001243 E5 10            [12] 3698 	mov	a,_bp
      001245 24 04            [12] 3699 	add	a,#0x04
      001247 F9               [12] 3700 	mov	r1,a
      001248 EA               [12] 3701 	mov	a,r2
      001249 26               [12] 3702 	add	a, @r0
      00124A F7               [12] 3703 	mov	@r1,a
      00124B E4               [12] 3704 	clr	a
      00124C 08               [12] 3705 	inc	r0
      00124D 36               [12] 3706 	addc	a, @r0
      00124E 09               [12] 3707 	inc	r1
      00124F F7               [12] 3708 	mov	@r1,a
      001250 08               [12] 3709 	inc	r0
      001251 E6               [12] 3710 	mov	a,@r0
      001252 09               [12] 3711 	inc	r1
      001253 F7               [12] 3712 	mov	@r1,a
      001254 E5 10            [12] 3713 	mov	a,_bp
      001256 24 FA            [12] 3714 	add	a,#0xfa
      001258 F8               [12] 3715 	mov	r0,a
      001259 86 82            [24] 3716 	mov	dpl, @r0
      00125B 08               [12] 3717 	inc	r0
      00125C 86 83            [24] 3718 	mov	dph, @r0
      00125E 08               [12] 3719 	inc	r0
      00125F 86 F0            [24] 3720 	mov	b, @r0
      001261 08               [12] 3721 	inc	r0
      001262 E6               [12] 3722 	mov	a, @r0
      001263 C0 03            [24] 3723 	push	ar3
      001265 C0 02            [24] 3724 	push	ar2
      001267 12 04 7D         [24] 3725 	lcall	_fuzzy_8051_clamp
      00126A AD 82            [24] 3726 	mov	r5, dpl
      00126C AE 83            [24] 3727 	mov	r6, dph
      00126E AC F0            [24] 3728 	mov	r4, b
      001270 FF               [12] 3729 	mov	r7, a
      001271 D0 02            [24] 3730 	pop	ar2
      001273 D0 03            [24] 3731 	pop	ar3
      001275 E5 10            [12] 3732 	mov	a,_bp
      001277 24 04            [12] 3733 	add	a,#0x04
      001279 F8               [12] 3734 	mov	r0,a
      00127A 86 82            [24] 3735 	mov	dpl,@r0
      00127C 08               [12] 3736 	inc	r0
      00127D 86 83            [24] 3737 	mov	dph,@r0
      00127F 08               [12] 3738 	inc	r0
      001280 86 F0            [24] 3739 	mov	b,@r0
      001282 ED               [12] 3740 	mov	a,r5
      001283 12 2B CA         [24] 3741 	lcall	__gptrput
      001286 A3               [24] 3742 	inc	dptr
      001287 EE               [12] 3743 	mov	a,r6
      001288 12 2B CA         [24] 3744 	lcall	__gptrput
      00128B A3               [24] 3745 	inc	dptr
      00128C EC               [12] 3746 	mov	a,r4
      00128D 12 2B CA         [24] 3747 	lcall	__gptrput
      001290 A3               [24] 3748 	inc	dptr
      001291 EF               [12] 3749 	mov	a,r7
      001292 12 2B CA         [24] 3750 	lcall	__gptrput
                           0011D8  3751 	C$fuzzy.h$292$1_0$81 ==.
                                   3752 ;	../../fuzzy.h:292: rules->rules[index].output = output;
      001295 A8 10            [24] 3753 	mov	r0,_bp
      001297 08               [12] 3754 	inc	r0
      001298 EA               [12] 3755 	mov	a,r2
      001299 26               [12] 3756 	add	a, @r0
      00129A FD               [12] 3757 	mov	r5,a
      00129B E4               [12] 3758 	clr	a
      00129C 08               [12] 3759 	inc	r0
      00129D 36               [12] 3760 	addc	a, @r0
      00129E FE               [12] 3761 	mov	r6,a
      00129F 08               [12] 3762 	inc	r0
      0012A0 86 07            [24] 3763 	mov	ar7,@r0
      0012A2 74 04            [12] 3764 	mov	a,#0x04
      0012A4 2D               [12] 3765 	add	a, r5
      0012A5 FD               [12] 3766 	mov	r5,a
      0012A6 E4               [12] 3767 	clr	a
      0012A7 3E               [12] 3768 	addc	a, r6
      0012A8 FE               [12] 3769 	mov	r6,a
      0012A9 8D 82            [24] 3770 	mov	dpl,r5
      0012AB 8E 83            [24] 3771 	mov	dph,r6
      0012AD 8F F0            [24] 3772 	mov	b,r7
      0012AF E5 10            [12] 3773 	mov	a,_bp
      0012B1 24 F7            [12] 3774 	add	a,#0xf7
      0012B3 F8               [12] 3775 	mov	r0,a
      0012B4 E6               [12] 3776 	mov	a,@r0
      0012B5 12 2B CA         [24] 3777 	lcall	__gptrput
      0012B8 A3               [24] 3778 	inc	dptr
      0012B9 08               [12] 3779 	inc	r0
      0012BA E6               [12] 3780 	mov	a,@r0
      0012BB 12 2B CA         [24] 3781 	lcall	__gptrput
      0012BE A3               [24] 3782 	inc	dptr
      0012BF 08               [12] 3783 	inc	r0
      0012C0 E6               [12] 3784 	mov	a,@r0
      0012C1 12 2B CA         [24] 3785 	lcall	__gptrput
                           001207  3786 	C$fuzzy.h$293$1_0$81 ==.
                                   3787 ;	../../fuzzy.h:293: rules->count = index + 1u;
      0012C4 EB               [12] 3788 	mov	a,r3
      0012C5 04               [12] 3789 	inc	a
      0012C6 FF               [12] 3790 	mov	r7,a
      0012C7 E5 10            [12] 3791 	mov	a,_bp
      0012C9 24 07            [12] 3792 	add	a,#0x07
      0012CB F8               [12] 3793 	mov	r0,a
      0012CC 86 82            [24] 3794 	mov	dpl,@r0
      0012CE 08               [12] 3795 	inc	r0
      0012CF 86 83            [24] 3796 	mov	dph,@r0
      0012D1 08               [12] 3797 	inc	r0
      0012D2 86 F0            [24] 3798 	mov	b,@r0
      0012D4 EF               [12] 3799 	mov	a,r7
      0012D5 12 2B CA         [24] 3800 	lcall	__gptrput
                           00121B  3801 	C$fuzzy.h$295$1_0$81 ==.
                                   3802 ;	../../fuzzy.h:295: return true;
      0012D8 75 82 01         [24] 3803 	mov	dpl, #0x01
      0012DB                       3804 00103$:
                           00121E  3805 	C$fuzzy.h$296$1_0$81 ==.
                                   3806 ;	../../fuzzy.h:296: }
      0012DB 85 10 81         [24] 3807 	mov	sp,_bp
      0012DE D0 10            [24] 3808 	pop	_bp
                           001223  3809 	C$fuzzy.h$296$1_0$81 ==.
                           001223  3810 	XG$fuzzy_rules_add_8051$0$0 ==.
      0012E0 22               [24] 3811 	ret
                                   3812 ;------------------------------------------------------------
                                   3813 ;Allocation info for local variables in function 'fuzzy_8051_height'
                                   3814 ;------------------------------------------------------------
                                   3815 ;x             Allocated to stack - _bp -6 +4 
                                   3816 ;rules         Allocated to stack - _bp +1 +3 
                                   3817 ;index         Allocated to registers r7 
                                   3818 ;aggregate     Allocated to stack - _bp +14 +4 
                                   3819 ;membership    Allocated to stack - _bp +18 +4 
                                   3820 ;implied       Allocated to registers r3 r4 r5 r6 
                                   3821 ;sloc0         Allocated to stack - _bp +4 +3 
                                   3822 ;sloc1         Allocated to stack - _bp +7 +3 
                                   3823 ;sloc2         Allocated to stack - _bp +10 +4 
                                   3824 ;------------------------------------------------------------
                           001224  3825 	Fsugeno_demo$fuzzy_8051_height$0$0 ==.
                           001224  3826 	C$fuzzy.h$298$1_0$84 ==.
                                   3827 ;	../../fuzzy.h:298: static float fuzzy_8051_height(const fuzzy_rules_t *rules, float x)
                                   3828 ;	-----------------------------------------
                                   3829 ;	 function fuzzy_8051_height
                                   3830 ;	-----------------------------------------
      0012E1                       3831 _fuzzy_8051_height:
      0012E1 C0 10            [24] 3832 	push	_bp
      0012E3 85 81 10         [24] 3833 	mov	_bp,sp
      0012E6 C0 82            [24] 3834 	push	dpl
      0012E8 C0 83            [24] 3835 	push	dph
      0012EA C0 F0            [24] 3836 	push	b
      0012EC E5 81            [12] 3837 	mov	a,sp
      0012EE 24 12            [12] 3838 	add	a,#0x12
      0012F0 F5 81            [12] 3839 	mov	sp,a
                           001235  3840 	C$fuzzy.h$305$1_0$84 ==.
                                   3841 ;	../../fuzzy.h:305: aggregate = 0.0f;
      0012F2 E5 10            [12] 3842 	mov	a,_bp
      0012F4 24 0E            [12] 3843 	add	a,#0x0e
      0012F6 F8               [12] 3844 	mov	r0,a
      0012F7 E4               [12] 3845 	clr	a
      0012F8 F6               [12] 3846 	mov	@r0,a
      0012F9 08               [12] 3847 	inc	r0
      0012FA F6               [12] 3848 	mov	@r0,a
      0012FB 08               [12] 3849 	inc	r0
      0012FC F6               [12] 3850 	mov	@r0,a
      0012FD 08               [12] 3851 	inc	r0
      0012FE F6               [12] 3852 	mov	@r0,a
                           001242  3853 	C$fuzzy.h$307$3_0$86 ==.
                                   3854 ;	../../fuzzy.h:307: for (index = 0u; index < rules->count; ++index) {
      0012FF A8 10            [24] 3855 	mov	r0,_bp
      001301 08               [12] 3856 	inc	r0
      001302 E5 10            [12] 3857 	mov	a,_bp
      001304 24 07            [12] 3858 	add	a,#0x07
      001306 F9               [12] 3859 	mov	r1,a
      001307 E6               [12] 3860 	mov	a,@r0
      001308 F7               [12] 3861 	mov	@r1,a
      001309 08               [12] 3862 	inc	r0
      00130A E6               [12] 3863 	mov	a,@r0
      00130B 09               [12] 3864 	inc	r1
      00130C F7               [12] 3865 	mov	@r1,a
      00130D 08               [12] 3866 	inc	r0
      00130E E6               [12] 3867 	mov	a,@r0
      00130F 09               [12] 3868 	inc	r1
      001310 F7               [12] 3869 	mov	@r1,a
      001311 A8 10            [24] 3870 	mov	r0,_bp
      001313 08               [12] 3871 	inc	r0
      001314 E5 10            [12] 3872 	mov	a,_bp
      001316 24 04            [12] 3873 	add	a,#0x04
      001318 F9               [12] 3874 	mov	r1,a
      001319 74 70            [12] 3875 	mov	a,#0x70
      00131B 26               [12] 3876 	add	a, @r0
      00131C F7               [12] 3877 	mov	@r1,a
      00131D E4               [12] 3878 	clr	a
      00131E 08               [12] 3879 	inc	r0
      00131F 36               [12] 3880 	addc	a, @r0
      001320 09               [12] 3881 	inc	r1
      001321 F7               [12] 3882 	mov	@r1,a
      001322 08               [12] 3883 	inc	r0
      001323 E6               [12] 3884 	mov	a,@r0
      001324 09               [12] 3885 	inc	r1
      001325 F7               [12] 3886 	mov	@r1,a
      001326 7F 00            [12] 3887 	mov	r7,#0x00
      001328                       3888 00105$:
      001328 E5 10            [12] 3889 	mov	a,_bp
      00132A 24 04            [12] 3890 	add	a,#0x04
      00132C F8               [12] 3891 	mov	r0,a
      00132D 86 82            [24] 3892 	mov	dpl,@r0
      00132F 08               [12] 3893 	inc	r0
      001330 86 83            [24] 3894 	mov	dph,@r0
      001332 08               [12] 3895 	inc	r0
      001333 86 F0            [24] 3896 	mov	b,@r0
      001335 12 2D EF         [24] 3897 	lcall	__gptrget
      001338 FE               [12] 3898 	mov	r6,a
      001339 C3               [12] 3899 	clr	c
      00133A EF               [12] 3900 	mov	a,r7
      00133B 9E               [12] 3901 	subb	a,r6
      00133C 40 03            [24] 3902 	jc	00136$
      00133E 02 14 7E         [24] 3903 	ljmp	00103$
      001341                       3904 00136$:
                           001284  3905 	C$fuzzy.h$308$3_0$86 ==.
                                   3906 ;	../../fuzzy.h:308: membership = fuzzy_8051_eval(rules->rules[index].output, x);
      001341 EF               [12] 3907 	mov	a,r7
      001342 75 F0 07         [24] 3908 	mov	b,#0x07
      001345 A4               [48] 3909 	mul	ab
      001346 FE               [12] 3910 	mov	r6,a
      001347 C0 07            [24] 3911 	push	ar7
      001349 E5 10            [12] 3912 	mov	a,_bp
      00134B 24 07            [12] 3913 	add	a,#0x07
      00134D F8               [12] 3914 	mov	r0,a
      00134E EE               [12] 3915 	mov	a,r6
      00134F 26               [12] 3916 	add	a, @r0
      001350 FC               [12] 3917 	mov	r4,a
      001351 E4               [12] 3918 	clr	a
      001352 08               [12] 3919 	inc	r0
      001353 36               [12] 3920 	addc	a, @r0
      001354 FD               [12] 3921 	mov	r5,a
      001355 08               [12] 3922 	inc	r0
      001356 86 07            [24] 3923 	mov	ar7,@r0
      001358 74 04            [12] 3924 	mov	a,#0x04
      00135A 2C               [12] 3925 	add	a, r4
      00135B FC               [12] 3926 	mov	r4,a
      00135C E4               [12] 3927 	clr	a
      00135D 3D               [12] 3928 	addc	a, r5
      00135E FD               [12] 3929 	mov	r5,a
      00135F 8C 82            [24] 3930 	mov	dpl,r4
      001361 8D 83            [24] 3931 	mov	dph,r5
      001363 8F F0            [24] 3932 	mov	b,r7
      001365 12 2D EF         [24] 3933 	lcall	__gptrget
      001368 FC               [12] 3934 	mov	r4,a
      001369 A3               [24] 3935 	inc	dptr
      00136A 12 2D EF         [24] 3936 	lcall	__gptrget
      00136D FD               [12] 3937 	mov	r5,a
      00136E A3               [24] 3938 	inc	dptr
      00136F 12 2D EF         [24] 3939 	lcall	__gptrget
      001372 FF               [12] 3940 	mov	r7,a
      001373 C0 07            [24] 3941 	push	ar7
      001375 C0 06            [24] 3942 	push	ar6
      001377 E5 10            [12] 3943 	mov	a,_bp
      001379 24 FA            [12] 3944 	add	a,#0xfa
      00137B F8               [12] 3945 	mov	r0,a
      00137C E6               [12] 3946 	mov	a,@r0
      00137D C0 E0            [24] 3947 	push	acc
      00137F 08               [12] 3948 	inc	r0
      001380 E6               [12] 3949 	mov	a,@r0
      001381 C0 E0            [24] 3950 	push	acc
      001383 08               [12] 3951 	inc	r0
      001384 E6               [12] 3952 	mov	a,@r0
      001385 C0 E0            [24] 3953 	push	acc
      001387 08               [12] 3954 	inc	r0
      001388 E6               [12] 3955 	mov	a,@r0
      001389 C0 E0            [24] 3956 	push	acc
      00138B 8C 82            [24] 3957 	mov	dpl, r4
      00138D 8D 83            [24] 3958 	mov	dph, r5
      00138F 8F F0            [24] 3959 	mov	b, r7
      001391 12 0E 65         [24] 3960 	lcall	_fuzzy_8051_eval
      001394 C8               [12] 3961 	xch	a,r0
      001395 E5 10            [12] 3962 	mov	a,_bp
      001397 24 12            [12] 3963 	add	a,#0x12
      001399 C8               [12] 3964 	xch	a,r0
      00139A A6 82            [24] 3965 	mov	@r0, dpl
      00139C 08               [12] 3966 	inc	r0
      00139D A6 83            [24] 3967 	mov	@r0, dph
      00139F 08               [12] 3968 	inc	r0
      0013A0 A6 F0            [24] 3969 	mov	@r0, b
      0013A2 08               [12] 3970 	inc	r0
      0013A3 F6               [12] 3971 	mov	@r0,a
      0013A4 E5 81            [12] 3972 	mov	a,sp
      0013A6 24 FC            [12] 3973 	add	a,#0xfc
      0013A8 F5 81            [12] 3974 	mov	sp,a
      0013AA D0 06            [24] 3975 	pop	ar6
      0013AC D0 07            [24] 3976 	pop	ar7
                           0012F1  3977 	C$fuzzy.h$309$3_0$86 ==.
                                   3978 ;	../../fuzzy.h:309: implied = rules->rules[index].value < membership ? rules->rules[index].value : membership;
      0013AE A8 10            [24] 3979 	mov	r0,_bp
      0013B0 08               [12] 3980 	inc	r0
      0013B1 EE               [12] 3981 	mov	a,r6
      0013B2 26               [12] 3982 	add	a, @r0
      0013B3 FE               [12] 3983 	mov	r6,a
      0013B4 E4               [12] 3984 	clr	a
      0013B5 08               [12] 3985 	inc	r0
      0013B6 36               [12] 3986 	addc	a, @r0
      0013B7 FF               [12] 3987 	mov	r7,a
      0013B8 08               [12] 3988 	inc	r0
      0013B9 86 05            [24] 3989 	mov	ar5,@r0
      0013BB 8E 82            [24] 3990 	mov	dpl,r6
      0013BD 8F 83            [24] 3991 	mov	dph,r7
      0013BF 8D F0            [24] 3992 	mov	b,r5
      0013C1 E5 10            [12] 3993 	mov	a,_bp
      0013C3 24 0A            [12] 3994 	add	a,#0x0a
      0013C5 F8               [12] 3995 	mov	r0,a
      0013C6 12 2D EF         [24] 3996 	lcall	__gptrget
      0013C9 F6               [12] 3997 	mov	@r0,a
      0013CA A3               [24] 3998 	inc	dptr
      0013CB 12 2D EF         [24] 3999 	lcall	__gptrget
      0013CE 08               [12] 4000 	inc	r0
      0013CF F6               [12] 4001 	mov	@r0,a
      0013D0 A3               [24] 4002 	inc	dptr
      0013D1 12 2D EF         [24] 4003 	lcall	__gptrget
      0013D4 08               [12] 4004 	inc	r0
      0013D5 F6               [12] 4005 	mov	@r0,a
      0013D6 A3               [24] 4006 	inc	dptr
      0013D7 12 2D EF         [24] 4007 	lcall	__gptrget
      0013DA 08               [12] 4008 	inc	r0
      0013DB F6               [12] 4009 	mov	@r0,a
      0013DC E5 10            [12] 4010 	mov	a,_bp
      0013DE 24 12            [12] 4011 	add	a,#0x12
      0013E0 F8               [12] 4012 	mov	r0,a
      0013E1 E6               [12] 4013 	mov	a,@r0
      0013E2 C0 E0            [24] 4014 	push	acc
      0013E4 08               [12] 4015 	inc	r0
      0013E5 E6               [12] 4016 	mov	a,@r0
      0013E6 C0 E0            [24] 4017 	push	acc
      0013E8 08               [12] 4018 	inc	r0
      0013E9 E6               [12] 4019 	mov	a,@r0
      0013EA C0 E0            [24] 4020 	push	acc
      0013EC 08               [12] 4021 	inc	r0
      0013ED E6               [12] 4022 	mov	a,@r0
      0013EE C0 E0            [24] 4023 	push	acc
      0013F0 E5 10            [12] 4024 	mov	a,_bp
      0013F2 24 0A            [12] 4025 	add	a,#0x0a
      0013F4 F8               [12] 4026 	mov	r0,a
      0013F5 86 82            [24] 4027 	mov	dpl, @r0
      0013F7 08               [12] 4028 	inc	r0
      0013F8 86 83            [24] 4029 	mov	dph, @r0
      0013FA 08               [12] 4030 	inc	r0
      0013FB 86 F0            [24] 4031 	mov	b, @r0
      0013FD 08               [12] 4032 	inc	r0
      0013FE E6               [12] 4033 	mov	a, @r0
      0013FF 12 2B E5         [24] 4034 	lcall	___fslt
      001402 AF 82            [24] 4035 	mov	r7, dpl
      001404 E5 81            [12] 4036 	mov	a,sp
      001406 24 FC            [12] 4037 	add	a,#0xfc
      001408 F5 81            [12] 4038 	mov	sp,a
      00140A EF               [12] 4039 	mov	a,r7
      00140B D0 07            [24] 4040 	pop	ar7
      00140D 60 12            [24] 4041 	jz	00109$
      00140F E5 10            [12] 4042 	mov	a,_bp
      001411 24 0A            [12] 4043 	add	a,#0x0a
      001413 F8               [12] 4044 	mov	r0,a
      001414 86 03            [24] 4045 	mov	ar3,@r0
      001416 08               [12] 4046 	inc	r0
      001417 86 04            [24] 4047 	mov	ar4,@r0
      001419 08               [12] 4048 	inc	r0
      00141A 86 05            [24] 4049 	mov	ar5,@r0
      00141C 08               [12] 4050 	inc	r0
      00141D 86 06            [24] 4051 	mov	ar6,@r0
      00141F 80 10            [24] 4052 	sjmp	00110$
      001421                       4053 00109$:
      001421 E5 10            [12] 4054 	mov	a,_bp
      001423 24 12            [12] 4055 	add	a,#0x12
      001425 F8               [12] 4056 	mov	r0,a
      001426 86 03            [24] 4057 	mov	ar3,@r0
      001428 08               [12] 4058 	inc	r0
      001429 86 04            [24] 4059 	mov	ar4,@r0
      00142B 08               [12] 4060 	inc	r0
      00142C 86 05            [24] 4061 	mov	ar5,@r0
      00142E 08               [12] 4062 	inc	r0
      00142F 86 06            [24] 4063 	mov	ar6,@r0
      001431                       4064 00110$:
                           001374  4065 	C$fuzzy.h$311$1_0$84 ==.
                                   4066 ;	../../fuzzy.h:311: if (implied > aggregate) {
      001431 C0 07            [24] 4067 	push	ar7
      001433 C0 06            [24] 4068 	push	ar6
      001435 C0 05            [24] 4069 	push	ar5
      001437 C0 04            [24] 4070 	push	ar4
      001439 C0 03            [24] 4071 	push	ar3
      00143B C0 03            [24] 4072 	push	ar3
      00143D C0 04            [24] 4073 	push	ar4
      00143F C0 05            [24] 4074 	push	ar5
      001441 C0 06            [24] 4075 	push	ar6
      001443 E5 10            [12] 4076 	mov	a,_bp
      001445 24 0E            [12] 4077 	add	a,#0x0e
      001447 F8               [12] 4078 	mov	r0,a
      001448 86 82            [24] 4079 	mov	dpl, @r0
      00144A 08               [12] 4080 	inc	r0
      00144B 86 83            [24] 4081 	mov	dph, @r0
      00144D 08               [12] 4082 	inc	r0
      00144E 86 F0            [24] 4083 	mov	b, @r0
      001450 08               [12] 4084 	inc	r0
      001451 E6               [12] 4085 	mov	a, @r0
      001452 12 2B E5         [24] 4086 	lcall	___fslt
      001455 AA 82            [24] 4087 	mov	r2, dpl
      001457 E5 81            [12] 4088 	mov	a,sp
      001459 24 FC            [12] 4089 	add	a,#0xfc
      00145B F5 81            [12] 4090 	mov	sp,a
      00145D D0 03            [24] 4091 	pop	ar3
      00145F D0 04            [24] 4092 	pop	ar4
      001461 D0 05            [24] 4093 	pop	ar5
      001463 D0 06            [24] 4094 	pop	ar6
      001465 D0 07            [24] 4095 	pop	ar7
      001467 EA               [12] 4096 	mov	a,r2
      001468 60 10            [24] 4097 	jz	00106$
                           0013AD  4098 	C$fuzzy.h$312$4_0$87 ==.
                                   4099 ;	../../fuzzy.h:312: aggregate = implied;
      00146A E5 10            [12] 4100 	mov	a,_bp
      00146C 24 0E            [12] 4101 	add	a,#0x0e
      00146E F8               [12] 4102 	mov	r0,a
      00146F A6 03            [24] 4103 	mov	@r0,ar3
      001471 08               [12] 4104 	inc	r0
      001472 A6 04            [24] 4105 	mov	@r0,ar4
      001474 08               [12] 4106 	inc	r0
      001475 A6 05            [24] 4107 	mov	@r0,ar5
      001477 08               [12] 4108 	inc	r0
      001478 A6 06            [24] 4109 	mov	@r0,ar6
      00147A                       4110 00106$:
                           0013BD  4111 	C$fuzzy.h$307$2_0$85 ==.
                                   4112 ;	../../fuzzy.h:307: for (index = 0u; index < rules->count; ++index) {
      00147A 0F               [12] 4113 	inc	r7
      00147B 02 13 28         [24] 4114 	ljmp	00105$
      00147E                       4115 00103$:
                           0013C1  4116 	C$fuzzy.h$316$1_0$84 ==.
                                   4117 ;	../../fuzzy.h:316: return aggregate;
      00147E E5 10            [12] 4118 	mov	a,_bp
      001480 24 0E            [12] 4119 	add	a,#0x0e
      001482 F8               [12] 4120 	mov	r0,a
      001483 86 82            [24] 4121 	mov	dpl, @r0
      001485 08               [12] 4122 	inc	r0
      001486 86 83            [24] 4123 	mov	dph, @r0
      001488 08               [12] 4124 	inc	r0
      001489 86 F0            [24] 4125 	mov	b, @r0
      00148B 08               [12] 4126 	inc	r0
      00148C E6               [12] 4127 	mov	a, @r0
                           0013D0  4128 	C$fuzzy.h$317$1_0$84 ==.
                                   4129 ;	../../fuzzy.h:317: }
      00148D 85 10 81         [24] 4130 	mov	sp,_bp
      001490 D0 10            [24] 4131 	pop	_bp
                           0013D5  4132 	C$fuzzy.h$317$1_0$84 ==.
                           0013D5  4133 	XFsugeno_demo$fuzzy_8051_height$0$0 ==.
      001492 22               [24] 4134 	ret
                                   4135 ;------------------------------------------------------------
                                   4136 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify'
                                   4137 ;------------------------------------------------------------
                                   4138 ;lower         Allocated to stack - _bp -6 +4 
                                   4139 ;upper         Allocated to stack - _bp -10 +4 
                                   4140 ;step          Allocated to stack - _bp -14 +4 
                                   4141 ;method        Allocated to stack - _bp -15 +1 
                                   4142 ;rules         Allocated to stack - _bp +1 +3 
                                   4143 ;x             Allocated to stack - _bp +4 +4 
                                   4144 ;height        Allocated to stack - _bp +8 +4 
                                   4145 ;weighted      Allocated to stack - _bp +12 +4 
                                   4146 ;sum           Allocated to stack - _bp +16 +4 
                                   4147 ;maximum       Allocated to stack - _bp +20 +4 
                                   4148 ;maximum_sum   Allocated to stack - _bp +24 +4 
                                   4149 ;smallest      Allocated to stack - _bp +28 +4 
                                   4150 ;largest       Allocated to stack - _bp +32 +4 
                                   4151 ;maximum_count Allocated to registers r5 r4 
                                   4152 ;------------------------------------------------------------
                           0013D6  4153 	G$fuzzy_rules_defuzzify$0$0 ==.
                           0013D6  4154 	C$fuzzy.h$319$1_0$89 ==.
                                   4155 ;	../../fuzzy.h:319: float fuzzy_rules_defuzzify(const fuzzy_rules_t *rules, float lower, float upper, float step, fuzzy_defuzz_method_t method)
                                   4156 ;	-----------------------------------------
                                   4157 ;	 function fuzzy_rules_defuzzify
                                   4158 ;	-----------------------------------------
      001493                       4159 _fuzzy_rules_defuzzify:
      001493 C0 10            [24] 4160 	push	_bp
      001495 85 81 10         [24] 4161 	mov	_bp,sp
      001498 C0 82            [24] 4162 	push	dpl
      00149A C0 83            [24] 4163 	push	dph
      00149C C0 F0            [24] 4164 	push	b
      00149E E5 81            [12] 4165 	mov	a,sp
      0014A0 24 20            [12] 4166 	add	a,#0x20
      0014A2 F5 81            [12] 4167 	mov	sp,a
                           0013E7  4168 	C$fuzzy.h$331$1_0$89 ==.
                                   4169 ;	../../fuzzy.h:331: if (rules->count == 0u || lower > upper || step <= 0.0f) {
      0014A4 A8 10            [24] 4170 	mov	r0,_bp
      0014A6 08               [12] 4171 	inc	r0
      0014A7 74 70            [12] 4172 	mov	a,#0x70
      0014A9 26               [12] 4173 	add	a, @r0
      0014AA FA               [12] 4174 	mov	r2,a
      0014AB E4               [12] 4175 	clr	a
      0014AC 08               [12] 4176 	inc	r0
      0014AD 36               [12] 4177 	addc	a, @r0
      0014AE FB               [12] 4178 	mov	r3,a
      0014AF 08               [12] 4179 	inc	r0
      0014B0 86 04            [24] 4180 	mov	ar4,@r0
      0014B2 8A 82            [24] 4181 	mov	dpl,r2
      0014B4 8B 83            [24] 4182 	mov	dph,r3
      0014B6 8C F0            [24] 4183 	mov	b,r4
      0014B8 12 2D EF         [24] 4184 	lcall	__gptrget
      0014BB 60 5C            [24] 4185 	jz	00101$
      0014BD E5 10            [12] 4186 	mov	a,_bp
      0014BF 24 FA            [12] 4187 	add	a,#0xfa
      0014C1 F8               [12] 4188 	mov	r0,a
      0014C2 E6               [12] 4189 	mov	a,@r0
      0014C3 C0 E0            [24] 4190 	push	acc
      0014C5 08               [12] 4191 	inc	r0
      0014C6 E6               [12] 4192 	mov	a,@r0
      0014C7 C0 E0            [24] 4193 	push	acc
      0014C9 08               [12] 4194 	inc	r0
      0014CA E6               [12] 4195 	mov	a,@r0
      0014CB C0 E0            [24] 4196 	push	acc
      0014CD 08               [12] 4197 	inc	r0
      0014CE E6               [12] 4198 	mov	a,@r0
      0014CF C0 E0            [24] 4199 	push	acc
      0014D1 E5 10            [12] 4200 	mov	a,_bp
      0014D3 24 F6            [12] 4201 	add	a,#0xf6
      0014D5 F8               [12] 4202 	mov	r0,a
      0014D6 86 82            [24] 4203 	mov	dpl, @r0
      0014D8 08               [12] 4204 	inc	r0
      0014D9 86 83            [24] 4205 	mov	dph, @r0
      0014DB 08               [12] 4206 	inc	r0
      0014DC 86 F0            [24] 4207 	mov	b, @r0
      0014DE 08               [12] 4208 	inc	r0
      0014DF E6               [12] 4209 	mov	a, @r0
      0014E0 12 2B E5         [24] 4210 	lcall	___fslt
      0014E3 AC 82            [24] 4211 	mov	r4, dpl
      0014E5 E5 81            [12] 4212 	mov	a,sp
      0014E7 24 FC            [12] 4213 	add	a,#0xfc
      0014E9 F5 81            [12] 4214 	mov	sp,a
      0014EB EC               [12] 4215 	mov	a,r4
      0014EC 70 2B            [24] 4216 	jnz	00101$
      0014EE E5 10            [12] 4217 	mov	a,_bp
      0014F0 24 F2            [12] 4218 	add	a,#0xf2
      0014F2 F8               [12] 4219 	mov	r0,a
      0014F3 E6               [12] 4220 	mov	a,@r0
      0014F4 C0 E0            [24] 4221 	push	acc
      0014F6 08               [12] 4222 	inc	r0
      0014F7 E6               [12] 4223 	mov	a,@r0
      0014F8 C0 E0            [24] 4224 	push	acc
      0014FA 08               [12] 4225 	inc	r0
      0014FB E6               [12] 4226 	mov	a,@r0
      0014FC C0 E0            [24] 4227 	push	acc
      0014FE 08               [12] 4228 	inc	r0
      0014FF E6               [12] 4229 	mov	a,@r0
      001500 C0 E0            [24] 4230 	push	acc
      001502 90 00 00         [24] 4231 	mov	dptr,#0x0000
      001505 E4               [12] 4232 	clr	a
      001506 F5 F0            [12] 4233 	mov	b,a
      001508 12 2B E5         [24] 4234 	lcall	___fslt
      00150B E5 81            [12] 4235 	mov	a,sp
      00150D 24 FC            [12] 4236 	add	a,#0xfc
      00150F F5 81            [12] 4237 	mov	sp,a
      001511 E5 82            [12] 4238 	mov	a, dpl
      001513 24 FF            [12] 4239 	add	a,#0xff
      001515 92 00            [24] 4240 	mov	b0,c
      001517 40 09            [24] 4241 	jc	00102$
      001519                       4242 00101$:
                           00145C  4243 	C$fuzzy.h$332$2_0$90 ==.
                                   4244 ;	../../fuzzy.h:332: return 0.0f;
      001519 90 00 00         [24] 4245 	mov	dptr,#0x0000
      00151C E4               [12] 4246 	clr	a
      00151D F5 F0            [12] 4247 	mov	b,a
      00151F 02 19 D1         [24] 4248 	ljmp	00120$
      001522                       4249 00102$:
                           001465  4250 	C$fuzzy.h$335$1_0$89 ==.
                                   4251 ;	../../fuzzy.h:335: weighted = 0.0f;
      001522 E5 10            [12] 4252 	mov	a,_bp
      001524 24 0C            [12] 4253 	add	a,#0x0c
      001526 F8               [12] 4254 	mov	r0,a
      001527 E4               [12] 4255 	clr	a
      001528 F6               [12] 4256 	mov	@r0,a
      001529 08               [12] 4257 	inc	r0
      00152A F6               [12] 4258 	mov	@r0,a
      00152B 08               [12] 4259 	inc	r0
      00152C F6               [12] 4260 	mov	@r0,a
      00152D 08               [12] 4261 	inc	r0
      00152E F6               [12] 4262 	mov	@r0,a
                           001472  4263 	C$fuzzy.h$336$1_0$89 ==.
                                   4264 ;	../../fuzzy.h:336: sum = 0.0f;
      00152F E5 10            [12] 4265 	mov	a,_bp
      001531 24 10            [12] 4266 	add	a,#0x10
      001533 F8               [12] 4267 	mov	r0,a
      001534 E4               [12] 4268 	clr	a
      001535 F6               [12] 4269 	mov	@r0,a
      001536 08               [12] 4270 	inc	r0
      001537 F6               [12] 4271 	mov	@r0,a
      001538 08               [12] 4272 	inc	r0
      001539 F6               [12] 4273 	mov	@r0,a
      00153A 08               [12] 4274 	inc	r0
      00153B F6               [12] 4275 	mov	@r0,a
                           00147F  4276 	C$fuzzy.h$337$1_0$89 ==.
                                   4277 ;	../../fuzzy.h:337: maximum = -1.0f;
      00153C E5 10            [12] 4278 	mov	a,_bp
      00153E 24 14            [12] 4279 	add	a,#0x14
      001540 F8               [12] 4280 	mov	r0,a
      001541 E4               [12] 4281 	clr	a
      001542 F6               [12] 4282 	mov	@r0,a
      001543 08               [12] 4283 	inc	r0
      001544 F6               [12] 4284 	mov	@r0,a
      001545 08               [12] 4285 	inc	r0
      001546 76 80            [12] 4286 	mov	@r0,#0x80
      001548 08               [12] 4287 	inc	r0
      001549 76 BF            [12] 4288 	mov	@r0,#0xbf
                           00148E  4289 	C$fuzzy.h$338$1_0$89 ==.
                                   4290 ;	../../fuzzy.h:338: maximum_sum = 0.0f;
      00154B E5 10            [12] 4291 	mov	a,_bp
      00154D 24 18            [12] 4292 	add	a,#0x18
      00154F F8               [12] 4293 	mov	r0,a
      001550 E4               [12] 4294 	clr	a
      001551 F6               [12] 4295 	mov	@r0,a
      001552 08               [12] 4296 	inc	r0
      001553 F6               [12] 4297 	mov	@r0,a
      001554 08               [12] 4298 	inc	r0
      001555 F6               [12] 4299 	mov	@r0,a
      001556 08               [12] 4300 	inc	r0
      001557 F6               [12] 4301 	mov	@r0,a
                           00149B  4302 	C$fuzzy.h$339$1_0$89 ==.
                                   4303 ;	../../fuzzy.h:339: maximum_count = 0u;
      001558 FD               [12] 4304 	mov	r5,a
      001559 FC               [12] 4305 	mov	r4,a
                           00149D  4306 	C$fuzzy.h$340$1_0$89 ==.
                                   4307 ;	../../fuzzy.h:340: smallest = lower;
      00155A E5 10            [12] 4308 	mov	a,_bp
      00155C 24 FA            [12] 4309 	add	a,#0xfa
      00155E F8               [12] 4310 	mov	r0,a
      00155F E5 10            [12] 4311 	mov	a,_bp
      001561 24 1C            [12] 4312 	add	a,#0x1c
      001563 F9               [12] 4313 	mov	r1,a
      001564 E6               [12] 4314 	mov	a,@r0
      001565 F7               [12] 4315 	mov	@r1,a
      001566 08               [12] 4316 	inc	r0
      001567 E6               [12] 4317 	mov	a,@r0
      001568 09               [12] 4318 	inc	r1
      001569 F7               [12] 4319 	mov	@r1,a
      00156A 08               [12] 4320 	inc	r0
      00156B E6               [12] 4321 	mov	a,@r0
      00156C 09               [12] 4322 	inc	r1
      00156D F7               [12] 4323 	mov	@r1,a
      00156E 08               [12] 4324 	inc	r0
      00156F E6               [12] 4325 	mov	a,@r0
      001570 09               [12] 4326 	inc	r1
      001571 F7               [12] 4327 	mov	@r1,a
                           0014B5  4328 	C$fuzzy.h$341$1_0$89 ==.
                                   4329 ;	../../fuzzy.h:341: largest = lower;
      001572 E5 10            [12] 4330 	mov	a,_bp
      001574 24 1C            [12] 4331 	add	a,#0x1c
      001576 F8               [12] 4332 	mov	r0,a
      001577 E5 10            [12] 4333 	mov	a,_bp
      001579 24 20            [12] 4334 	add	a,#0x20
      00157B F9               [12] 4335 	mov	r1,a
      00157C E6               [12] 4336 	mov	a,@r0
      00157D F7               [12] 4337 	mov	@r1,a
      00157E 08               [12] 4338 	inc	r0
      00157F E6               [12] 4339 	mov	a,@r0
      001580 09               [12] 4340 	inc	r1
      001581 F7               [12] 4341 	mov	@r1,a
      001582 08               [12] 4342 	inc	r0
      001583 E6               [12] 4343 	mov	a,@r0
      001584 09               [12] 4344 	inc	r1
      001585 F7               [12] 4345 	mov	@r1,a
      001586 08               [12] 4346 	inc	r0
      001587 E6               [12] 4347 	mov	a,@r0
      001588 09               [12] 4348 	inc	r1
      001589 F7               [12] 4349 	mov	@r1,a
                           0014CD  4350 	C$fuzzy.h$343$2_0$91 ==.
                                   4351 ;	../../fuzzy.h:343: for (x = lower; x <= upper; x += step) {
      00158A E5 10            [12] 4352 	mov	a,_bp
      00158C 24 1C            [12] 4353 	add	a,#0x1c
      00158E F8               [12] 4354 	mov	r0,a
      00158F E5 10            [12] 4355 	mov	a,_bp
      001591 24 04            [12] 4356 	add	a,#0x04
      001593 F9               [12] 4357 	mov	r1,a
      001594 E6               [12] 4358 	mov	a,@r0
      001595 F7               [12] 4359 	mov	@r1,a
      001596 08               [12] 4360 	inc	r0
      001597 E6               [12] 4361 	mov	a,@r0
      001598 09               [12] 4362 	inc	r1
      001599 F7               [12] 4363 	mov	@r1,a
      00159A 08               [12] 4364 	inc	r0
      00159B E6               [12] 4365 	mov	a,@r0
      00159C 09               [12] 4366 	inc	r1
      00159D F7               [12] 4367 	mov	@r1,a
      00159E 08               [12] 4368 	inc	r0
      00159F E6               [12] 4369 	mov	a,@r0
      0015A0 09               [12] 4370 	inc	r1
      0015A1 F7               [12] 4371 	mov	@r1,a
      0015A2                       4372 00118$:
      0015A2 C0 05            [24] 4373 	push	ar5
      0015A4 C0 04            [24] 4374 	push	ar4
      0015A6 E5 10            [12] 4375 	mov	a,_bp
      0015A8 24 04            [12] 4376 	add	a,#0x04
      0015AA F8               [12] 4377 	mov	r0,a
      0015AB E6               [12] 4378 	mov	a,@r0
      0015AC C0 E0            [24] 4379 	push	acc
      0015AE 08               [12] 4380 	inc	r0
      0015AF E6               [12] 4381 	mov	a,@r0
      0015B0 C0 E0            [24] 4382 	push	acc
      0015B2 08               [12] 4383 	inc	r0
      0015B3 E6               [12] 4384 	mov	a,@r0
      0015B4 C0 E0            [24] 4385 	push	acc
      0015B6 08               [12] 4386 	inc	r0
      0015B7 E6               [12] 4387 	mov	a,@r0
      0015B8 C0 E0            [24] 4388 	push	acc
      0015BA E5 10            [12] 4389 	mov	a,_bp
      0015BC 24 F6            [12] 4390 	add	a,#0xf6
      0015BE F8               [12] 4391 	mov	r0,a
      0015BF 86 82            [24] 4392 	mov	dpl, @r0
      0015C1 08               [12] 4393 	inc	r0
      0015C2 86 83            [24] 4394 	mov	dph, @r0
      0015C4 08               [12] 4395 	inc	r0
      0015C5 86 F0            [24] 4396 	mov	b, @r0
      0015C7 08               [12] 4397 	inc	r0
      0015C8 E6               [12] 4398 	mov	a, @r0
      0015C9 12 2B E5         [24] 4399 	lcall	___fslt
      0015CC E5 81            [12] 4400 	mov	a,sp
      0015CE 24 FC            [12] 4401 	add	a,#0xfc
      0015D0 F5 81            [12] 4402 	mov	sp,a
      0015D2 D0 04            [24] 4403 	pop	ar4
      0015D4 D0 05            [24] 4404 	pop	ar5
      0015D6 E5 82            [12] 4405 	mov	a, dpl
      0015D8 24 FF            [12] 4406 	add	a,#0xff
      0015DA 92 00            [24] 4407 	mov	b0,c
      0015DC 50 03            [24] 4408 	jnc	00211$
      0015DE 02 18 39         [24] 4409 	ljmp	00110$
      0015E1                       4410 00211$:
                           001524  4411 	C$fuzzy.h$344$3_0$92 ==.
                                   4412 ;	../../fuzzy.h:344: height = fuzzy_8051_height(rules, x);
      0015E1 C0 05            [24] 4413 	push	ar5
      0015E3 C0 04            [24] 4414 	push	ar4
      0015E5 E5 10            [12] 4415 	mov	a,_bp
      0015E7 24 04            [12] 4416 	add	a,#0x04
      0015E9 F8               [12] 4417 	mov	r0,a
      0015EA E6               [12] 4418 	mov	a,@r0
      0015EB C0 E0            [24] 4419 	push	acc
      0015ED 08               [12] 4420 	inc	r0
      0015EE E6               [12] 4421 	mov	a,@r0
      0015EF C0 E0            [24] 4422 	push	acc
      0015F1 08               [12] 4423 	inc	r0
      0015F2 E6               [12] 4424 	mov	a,@r0
      0015F3 C0 E0            [24] 4425 	push	acc
      0015F5 08               [12] 4426 	inc	r0
      0015F6 E6               [12] 4427 	mov	a,@r0
      0015F7 C0 E0            [24] 4428 	push	acc
      0015F9 A8 10            [24] 4429 	mov	r0,_bp
      0015FB 08               [12] 4430 	inc	r0
      0015FC 86 82            [24] 4431 	mov	dpl, @r0
      0015FE 08               [12] 4432 	inc	r0
      0015FF 86 83            [24] 4433 	mov	dph, @r0
      001601 08               [12] 4434 	inc	r0
      001602 86 F0            [24] 4435 	mov	b, @r0
      001604 12 12 E1         [24] 4436 	lcall	_fuzzy_8051_height
      001607 C8               [12] 4437 	xch	a,r0
      001608 E5 10            [12] 4438 	mov	a,_bp
      00160A 24 08            [12] 4439 	add	a,#0x08
      00160C C8               [12] 4440 	xch	a,r0
      00160D A6 82            [24] 4441 	mov	@r0, dpl
      00160F 08               [12] 4442 	inc	r0
      001610 A6 83            [24] 4443 	mov	@r0, dph
      001612 08               [12] 4444 	inc	r0
      001613 A6 F0            [24] 4445 	mov	@r0, b
      001615 08               [12] 4446 	inc	r0
      001616 F6               [12] 4447 	mov	@r0,a
      001617 E5 81            [12] 4448 	mov	a,sp
      001619 24 FC            [12] 4449 	add	a,#0xfc
      00161B F5 81            [12] 4450 	mov	sp,a
                           001560  4451 	C$fuzzy.h$346$1_0$89 ==.
                                   4452 ;	../../fuzzy.h:346: weighted += x * height;
      00161D E5 10            [12] 4453 	mov	a,_bp
      00161F 24 08            [12] 4454 	add	a,#0x08
      001621 F8               [12] 4455 	mov	r0,a
      001622 E6               [12] 4456 	mov	a,@r0
      001623 C0 E0            [24] 4457 	push	acc
      001625 08               [12] 4458 	inc	r0
      001626 E6               [12] 4459 	mov	a,@r0
      001627 C0 E0            [24] 4460 	push	acc
      001629 08               [12] 4461 	inc	r0
      00162A E6               [12] 4462 	mov	a,@r0
      00162B C0 E0            [24] 4463 	push	acc
      00162D 08               [12] 4464 	inc	r0
      00162E E6               [12] 4465 	mov	a,@r0
      00162F C0 E0            [24] 4466 	push	acc
      001631 E5 10            [12] 4467 	mov	a,_bp
      001633 24 04            [12] 4468 	add	a,#0x04
      001635 F8               [12] 4469 	mov	r0,a
      001636 86 82            [24] 4470 	mov	dpl, @r0
      001638 08               [12] 4471 	inc	r0
      001639 86 83            [24] 4472 	mov	dph, @r0
      00163B 08               [12] 4473 	inc	r0
      00163C 86 F0            [24] 4474 	mov	b, @r0
      00163E 08               [12] 4475 	inc	r0
      00163F E6               [12] 4476 	mov	a, @r0
      001640 12 2A B5         [24] 4477 	lcall	___fsmul
      001643 AA 82            [24] 4478 	mov	r2, dpl
      001645 AB 83            [24] 4479 	mov	r3, dph
      001647 AE F0            [24] 4480 	mov	r6, b
      001649 FF               [12] 4481 	mov	r7, a
      00164A E5 81            [12] 4482 	mov	a,sp
      00164C 24 FC            [12] 4483 	add	a,#0xfc
      00164E F5 81            [12] 4484 	mov	sp,a
      001650 C0 02            [24] 4485 	push	ar2
      001652 C0 03            [24] 4486 	push	ar3
      001654 C0 06            [24] 4487 	push	ar6
      001656 C0 07            [24] 4488 	push	ar7
                           00159B  4489 	C$fuzzy.h$347$1_0$89 ==.
                                   4490 ;	../../fuzzy.h:347: sum += height;
      001658 E5 10            [12] 4491 	mov	a,_bp
      00165A 24 0C            [12] 4492 	add	a,#0x0c
      00165C F8               [12] 4493 	mov	r0,a
      00165D 86 82            [24] 4494 	mov	dpl, @r0
      00165F 08               [12] 4495 	inc	r0
      001660 86 83            [24] 4496 	mov	dph, @r0
      001662 08               [12] 4497 	inc	r0
      001663 86 F0            [24] 4498 	mov	b, @r0
      001665 08               [12] 4499 	inc	r0
      001666 E6               [12] 4500 	mov	a, @r0
      001667 12 2C 15         [24] 4501 	lcall	___fsadd
      00166A C8               [12] 4502 	xch	a,r0
      00166B E5 10            [12] 4503 	mov	a,_bp
      00166D 24 0C            [12] 4504 	add	a,#0x0c
      00166F C8               [12] 4505 	xch	a,r0
      001670 A6 82            [24] 4506 	mov	@r0, dpl
      001672 08               [12] 4507 	inc	r0
      001673 A6 83            [24] 4508 	mov	@r0, dph
      001675 08               [12] 4509 	inc	r0
      001676 A6 F0            [24] 4510 	mov	@r0, b
      001678 08               [12] 4511 	inc	r0
      001679 F6               [12] 4512 	mov	@r0,a
      00167A E5 81            [12] 4513 	mov	a,sp
      00167C 24 FC            [12] 4514 	add	a,#0xfc
      00167E F5 81            [12] 4515 	mov	sp,a
      001680 E5 10            [12] 4516 	mov	a,_bp
      001682 24 08            [12] 4517 	add	a,#0x08
      001684 F8               [12] 4518 	mov	r0,a
      001685 E6               [12] 4519 	mov	a,@r0
      001686 C0 E0            [24] 4520 	push	acc
      001688 08               [12] 4521 	inc	r0
      001689 E6               [12] 4522 	mov	a,@r0
      00168A C0 E0            [24] 4523 	push	acc
      00168C 08               [12] 4524 	inc	r0
      00168D E6               [12] 4525 	mov	a,@r0
      00168E C0 E0            [24] 4526 	push	acc
      001690 08               [12] 4527 	inc	r0
      001691 E6               [12] 4528 	mov	a,@r0
      001692 C0 E0            [24] 4529 	push	acc
                           0015D7  4530 	C$fuzzy.h$349$1_0$89 ==.
                                   4531 ;	../../fuzzy.h:349: if (height > maximum) {
      001694 E5 10            [12] 4532 	mov	a,_bp
      001696 24 10            [12] 4533 	add	a,#0x10
      001698 F8               [12] 4534 	mov	r0,a
      001699 86 82            [24] 4535 	mov	dpl, @r0
      00169B 08               [12] 4536 	inc	r0
      00169C 86 83            [24] 4537 	mov	dph, @r0
      00169E 08               [12] 4538 	inc	r0
      00169F 86 F0            [24] 4539 	mov	b, @r0
      0016A1 08               [12] 4540 	inc	r0
      0016A2 E6               [12] 4541 	mov	a, @r0
      0016A3 12 2C 15         [24] 4542 	lcall	___fsadd
      0016A6 C8               [12] 4543 	xch	a,r0
      0016A7 E5 10            [12] 4544 	mov	a,_bp
      0016A9 24 10            [12] 4545 	add	a,#0x10
      0016AB C8               [12] 4546 	xch	a,r0
      0016AC A6 82            [24] 4547 	mov	@r0, dpl
      0016AE 08               [12] 4548 	inc	r0
      0016AF A6 83            [24] 4549 	mov	@r0, dph
      0016B1 08               [12] 4550 	inc	r0
      0016B2 A6 F0            [24] 4551 	mov	@r0, b
      0016B4 08               [12] 4552 	inc	r0
      0016B5 F6               [12] 4553 	mov	@r0,a
      0016B6 E5 81            [12] 4554 	mov	a,sp
      0016B8 24 FC            [12] 4555 	add	a,#0xfc
      0016BA F5 81            [12] 4556 	mov	sp,a
      0016BC E5 10            [12] 4557 	mov	a,_bp
      0016BE 24 08            [12] 4558 	add	a,#0x08
      0016C0 F8               [12] 4559 	mov	r0,a
      0016C1 E6               [12] 4560 	mov	a,@r0
      0016C2 C0 E0            [24] 4561 	push	acc
      0016C4 08               [12] 4562 	inc	r0
      0016C5 E6               [12] 4563 	mov	a,@r0
      0016C6 C0 E0            [24] 4564 	push	acc
      0016C8 08               [12] 4565 	inc	r0
      0016C9 E6               [12] 4566 	mov	a,@r0
      0016CA C0 E0            [24] 4567 	push	acc
      0016CC 08               [12] 4568 	inc	r0
      0016CD E6               [12] 4569 	mov	a,@r0
      0016CE C0 E0            [24] 4570 	push	acc
      0016D0 E5 10            [12] 4571 	mov	a,_bp
      0016D2 24 14            [12] 4572 	add	a,#0x14
      0016D4 F8               [12] 4573 	mov	r0,a
      0016D5 86 82            [24] 4574 	mov	dpl, @r0
      0016D7 08               [12] 4575 	inc	r0
      0016D8 86 83            [24] 4576 	mov	dph, @r0
      0016DA 08               [12] 4577 	inc	r0
      0016DB 86 F0            [24] 4578 	mov	b, @r0
      0016DD 08               [12] 4579 	inc	r0
      0016DE E6               [12] 4580 	mov	a, @r0
      0016DF 12 2B E5         [24] 4581 	lcall	___fslt
      0016E2 AF 82            [24] 4582 	mov	r7, dpl
      0016E4 E5 81            [12] 4583 	mov	a,sp
      0016E6 24 FC            [12] 4584 	add	a,#0xfc
      0016E8 F5 81            [12] 4585 	mov	sp,a
      0016EA D0 04            [24] 4586 	pop	ar4
      0016EC D0 05            [24] 4587 	pop	ar5
      0016EE EF               [12] 4588 	mov	a,r7
      0016EF 60 67            [24] 4589 	jz	00108$
                           001634  4590 	C$fuzzy.h$350$4_0$93 ==.
                                   4591 ;	../../fuzzy.h:350: maximum = height;
      0016F1 E5 10            [12] 4592 	mov	a,_bp
      0016F3 24 08            [12] 4593 	add	a,#0x08
      0016F5 F8               [12] 4594 	mov	r0,a
      0016F6 E5 10            [12] 4595 	mov	a,_bp
      0016F8 24 14            [12] 4596 	add	a,#0x14
      0016FA F9               [12] 4597 	mov	r1,a
      0016FB E6               [12] 4598 	mov	a,@r0
      0016FC F7               [12] 4599 	mov	@r1,a
      0016FD 08               [12] 4600 	inc	r0
      0016FE E6               [12] 4601 	mov	a,@r0
      0016FF 09               [12] 4602 	inc	r1
      001700 F7               [12] 4603 	mov	@r1,a
      001701 08               [12] 4604 	inc	r0
      001702 E6               [12] 4605 	mov	a,@r0
      001703 09               [12] 4606 	inc	r1
      001704 F7               [12] 4607 	mov	@r1,a
      001705 08               [12] 4608 	inc	r0
      001706 E6               [12] 4609 	mov	a,@r0
      001707 09               [12] 4610 	inc	r1
      001708 F7               [12] 4611 	mov	@r1,a
                           00164C  4612 	C$fuzzy.h$351$4_0$93 ==.
                                   4613 ;	../../fuzzy.h:351: maximum_sum = x;
      001709 E5 10            [12] 4614 	mov	a,_bp
      00170B 24 04            [12] 4615 	add	a,#0x04
      00170D F8               [12] 4616 	mov	r0,a
      00170E E5 10            [12] 4617 	mov	a,_bp
      001710 24 18            [12] 4618 	add	a,#0x18
      001712 F9               [12] 4619 	mov	r1,a
      001713 E6               [12] 4620 	mov	a,@r0
      001714 F7               [12] 4621 	mov	@r1,a
      001715 08               [12] 4622 	inc	r0
      001716 E6               [12] 4623 	mov	a,@r0
      001717 09               [12] 4624 	inc	r1
      001718 F7               [12] 4625 	mov	@r1,a
      001719 08               [12] 4626 	inc	r0
      00171A E6               [12] 4627 	mov	a,@r0
      00171B 09               [12] 4628 	inc	r1
      00171C F7               [12] 4629 	mov	@r1,a
      00171D 08               [12] 4630 	inc	r0
      00171E E6               [12] 4631 	mov	a,@r0
      00171F 09               [12] 4632 	inc	r1
      001720 F7               [12] 4633 	mov	@r1,a
                           001664  4634 	C$fuzzy.h$352$4_0$93 ==.
                                   4635 ;	../../fuzzy.h:352: maximum_count = 1u;
      001721 7D 01            [12] 4636 	mov	r5,#0x01
      001723 7C 00            [12] 4637 	mov	r4,#0x00
                           001668  4638 	C$fuzzy.h$353$4_0$93 ==.
                                   4639 ;	../../fuzzy.h:353: smallest = x;
      001725 E5 10            [12] 4640 	mov	a,_bp
      001727 24 04            [12] 4641 	add	a,#0x04
      001729 F8               [12] 4642 	mov	r0,a
      00172A E5 10            [12] 4643 	mov	a,_bp
      00172C 24 1C            [12] 4644 	add	a,#0x1c
      00172E F9               [12] 4645 	mov	r1,a
      00172F E6               [12] 4646 	mov	a,@r0
      001730 F7               [12] 4647 	mov	@r1,a
      001731 08               [12] 4648 	inc	r0
      001732 E6               [12] 4649 	mov	a,@r0
      001733 09               [12] 4650 	inc	r1
      001734 F7               [12] 4651 	mov	@r1,a
      001735 08               [12] 4652 	inc	r0
      001736 E6               [12] 4653 	mov	a,@r0
      001737 09               [12] 4654 	inc	r1
      001738 F7               [12] 4655 	mov	@r1,a
      001739 08               [12] 4656 	inc	r0
      00173A E6               [12] 4657 	mov	a,@r0
      00173B 09               [12] 4658 	inc	r1
      00173C F7               [12] 4659 	mov	@r1,a
                           001680  4660 	C$fuzzy.h$354$4_0$93 ==.
                                   4661 ;	../../fuzzy.h:354: largest = x;
      00173D E5 10            [12] 4662 	mov	a,_bp
      00173F 24 04            [12] 4663 	add	a,#0x04
      001741 F8               [12] 4664 	mov	r0,a
      001742 E5 10            [12] 4665 	mov	a,_bp
      001744 24 20            [12] 4666 	add	a,#0x20
      001746 F9               [12] 4667 	mov	r1,a
      001747 E6               [12] 4668 	mov	a,@r0
      001748 F7               [12] 4669 	mov	@r1,a
      001749 08               [12] 4670 	inc	r0
      00174A E6               [12] 4671 	mov	a,@r0
      00174B 09               [12] 4672 	inc	r1
      00174C F7               [12] 4673 	mov	@r1,a
      00174D 08               [12] 4674 	inc	r0
      00174E E6               [12] 4675 	mov	a,@r0
      00174F 09               [12] 4676 	inc	r1
      001750 F7               [12] 4677 	mov	@r1,a
      001751 08               [12] 4678 	inc	r0
      001752 E6               [12] 4679 	mov	a,@r0
      001753 09               [12] 4680 	inc	r1
      001754 F7               [12] 4681 	mov	@r1,a
      001755 02 17 F2         [24] 4682 	ljmp	00119$
      001758                       4683 00108$:
                           00169B  4684 	C$fuzzy.h$356$1_0$89 ==.
                                   4685 ;	../../fuzzy.h:356: else if (height == maximum) {
      001758 C0 05            [24] 4686 	push	ar5
      00175A C0 04            [24] 4687 	push	ar4
      00175C E5 10            [12] 4688 	mov	a,_bp
      00175E 24 14            [12] 4689 	add	a,#0x14
      001760 F8               [12] 4690 	mov	r0,a
      001761 E6               [12] 4691 	mov	a,@r0
      001762 C0 E0            [24] 4692 	push	acc
      001764 08               [12] 4693 	inc	r0
      001765 E6               [12] 4694 	mov	a,@r0
      001766 C0 E0            [24] 4695 	push	acc
      001768 08               [12] 4696 	inc	r0
      001769 E6               [12] 4697 	mov	a,@r0
      00176A C0 E0            [24] 4698 	push	acc
      00176C 08               [12] 4699 	inc	r0
      00176D E6               [12] 4700 	mov	a,@r0
      00176E C0 E0            [24] 4701 	push	acc
      001770 E5 10            [12] 4702 	mov	a,_bp
      001772 24 08            [12] 4703 	add	a,#0x08
      001774 F8               [12] 4704 	mov	r0,a
      001775 86 82            [24] 4705 	mov	dpl, @r0
      001777 08               [12] 4706 	inc	r0
      001778 86 83            [24] 4707 	mov	dph, @r0
      00177A 08               [12] 4708 	inc	r0
      00177B 86 F0            [24] 4709 	mov	b, @r0
      00177D 08               [12] 4710 	inc	r0
      00177E E6               [12] 4711 	mov	a, @r0
      00177F 12 2B B9         [24] 4712 	lcall	___fseq
      001782 AF 82            [24] 4713 	mov	r7, dpl
      001784 E5 81            [12] 4714 	mov	a,sp
      001786 24 FC            [12] 4715 	add	a,#0xfc
      001788 F5 81            [12] 4716 	mov	sp,a
      00178A D0 04            [24] 4717 	pop	ar4
      00178C D0 05            [24] 4718 	pop	ar5
      00178E EF               [12] 4719 	mov	a,r7
      00178F 60 61            [24] 4720 	jz	00119$
                           0016D4  4721 	C$fuzzy.h$357$1_0$89 ==.
                                   4722 ;	../../fuzzy.h:357: maximum_sum += x;
      001791 C0 05            [24] 4723 	push	ar5
      001793 C0 04            [24] 4724 	push	ar4
      001795 E5 10            [12] 4725 	mov	a,_bp
      001797 24 04            [12] 4726 	add	a,#0x04
      001799 F8               [12] 4727 	mov	r0,a
      00179A E6               [12] 4728 	mov	a,@r0
      00179B C0 E0            [24] 4729 	push	acc
      00179D 08               [12] 4730 	inc	r0
      00179E E6               [12] 4731 	mov	a,@r0
      00179F C0 E0            [24] 4732 	push	acc
      0017A1 08               [12] 4733 	inc	r0
      0017A2 E6               [12] 4734 	mov	a,@r0
      0017A3 C0 E0            [24] 4735 	push	acc
      0017A5 08               [12] 4736 	inc	r0
      0017A6 E6               [12] 4737 	mov	a,@r0
      0017A7 C0 E0            [24] 4738 	push	acc
                           0016EC  4739 	C$fuzzy.h$358$1_0$89 ==.
                                   4740 ;	../../fuzzy.h:358: ++maximum_count;
      0017A9 E5 10            [12] 4741 	mov	a,_bp
      0017AB 24 18            [12] 4742 	add	a,#0x18
      0017AD F8               [12] 4743 	mov	r0,a
      0017AE 86 82            [24] 4744 	mov	dpl, @r0
      0017B0 08               [12] 4745 	inc	r0
      0017B1 86 83            [24] 4746 	mov	dph, @r0
      0017B3 08               [12] 4747 	inc	r0
      0017B4 86 F0            [24] 4748 	mov	b, @r0
      0017B6 08               [12] 4749 	inc	r0
      0017B7 E6               [12] 4750 	mov	a, @r0
      0017B8 12 2C 15         [24] 4751 	lcall	___fsadd
      0017BB C8               [12] 4752 	xch	a,r0
      0017BC E5 10            [12] 4753 	mov	a,_bp
      0017BE 24 18            [12] 4754 	add	a,#0x18
      0017C0 C8               [12] 4755 	xch	a,r0
      0017C1 A6 82            [24] 4756 	mov	@r0, dpl
      0017C3 08               [12] 4757 	inc	r0
      0017C4 A6 83            [24] 4758 	mov	@r0, dph
      0017C6 08               [12] 4759 	inc	r0
      0017C7 A6 F0            [24] 4760 	mov	@r0, b
      0017C9 08               [12] 4761 	inc	r0
      0017CA F6               [12] 4762 	mov	@r0,a
      0017CB E5 81            [12] 4763 	mov	a,sp
      0017CD 24 FC            [12] 4764 	add	a,#0xfc
      0017CF F5 81            [12] 4765 	mov	sp,a
      0017D1 D0 04            [24] 4766 	pop	ar4
      0017D3 D0 05            [24] 4767 	pop	ar5
      0017D5 0D               [12] 4768 	inc	r5
      0017D6 BD 00 01         [24] 4769 	cjne	r5,#0x00,00214$
      0017D9 0C               [12] 4770 	inc	r4
      0017DA                       4771 00214$:
                           00171D  4772 	C$fuzzy.h$359$4_0$94 ==.
                                   4773 ;	../../fuzzy.h:359: largest = x;
      0017DA E5 10            [12] 4774 	mov	a,_bp
      0017DC 24 04            [12] 4775 	add	a,#0x04
      0017DE F8               [12] 4776 	mov	r0,a
      0017DF E5 10            [12] 4777 	mov	a,_bp
      0017E1 24 20            [12] 4778 	add	a,#0x20
      0017E3 F9               [12] 4779 	mov	r1,a
      0017E4 E6               [12] 4780 	mov	a,@r0
      0017E5 F7               [12] 4781 	mov	@r1,a
      0017E6 08               [12] 4782 	inc	r0
      0017E7 E6               [12] 4783 	mov	a,@r0
      0017E8 09               [12] 4784 	inc	r1
      0017E9 F7               [12] 4785 	mov	@r1,a
      0017EA 08               [12] 4786 	inc	r0
      0017EB E6               [12] 4787 	mov	a,@r0
      0017EC 09               [12] 4788 	inc	r1
      0017ED F7               [12] 4789 	mov	@r1,a
      0017EE 08               [12] 4790 	inc	r0
      0017EF E6               [12] 4791 	mov	a,@r0
      0017F0 09               [12] 4792 	inc	r1
      0017F1 F7               [12] 4793 	mov	@r1,a
      0017F2                       4794 00119$:
                           001735  4795 	C$fuzzy.h$343$1_0$89 ==.
                                   4796 ;	../../fuzzy.h:343: for (x = lower; x <= upper; x += step) {
      0017F2 C0 05            [24] 4797 	push	ar5
      0017F4 C0 04            [24] 4798 	push	ar4
      0017F6 E5 10            [12] 4799 	mov	a,_bp
      0017F8 24 F2            [12] 4800 	add	a,#0xf2
      0017FA F8               [12] 4801 	mov	r0,a
      0017FB E6               [12] 4802 	mov	a,@r0
      0017FC C0 E0            [24] 4803 	push	acc
      0017FE 08               [12] 4804 	inc	r0
      0017FF E6               [12] 4805 	mov	a,@r0
      001800 C0 E0            [24] 4806 	push	acc
      001802 08               [12] 4807 	inc	r0
      001803 E6               [12] 4808 	mov	a,@r0
      001804 C0 E0            [24] 4809 	push	acc
      001806 08               [12] 4810 	inc	r0
      001807 E6               [12] 4811 	mov	a,@r0
      001808 C0 E0            [24] 4812 	push	acc
      00180A E5 10            [12] 4813 	mov	a,_bp
      00180C 24 04            [12] 4814 	add	a,#0x04
      00180E F8               [12] 4815 	mov	r0,a
      00180F 86 82            [24] 4816 	mov	dpl, @r0
      001811 08               [12] 4817 	inc	r0
      001812 86 83            [24] 4818 	mov	dph, @r0
      001814 08               [12] 4819 	inc	r0
      001815 86 F0            [24] 4820 	mov	b, @r0
      001817 08               [12] 4821 	inc	r0
      001818 E6               [12] 4822 	mov	a, @r0
      001819 12 2C 15         [24] 4823 	lcall	___fsadd
      00181C C8               [12] 4824 	xch	a,r0
      00181D E5 10            [12] 4825 	mov	a,_bp
      00181F 24 04            [12] 4826 	add	a,#0x04
      001821 C8               [12] 4827 	xch	a,r0
      001822 A6 82            [24] 4828 	mov	@r0, dpl
      001824 08               [12] 4829 	inc	r0
      001825 A6 83            [24] 4830 	mov	@r0, dph
      001827 08               [12] 4831 	inc	r0
      001828 A6 F0            [24] 4832 	mov	@r0, b
      00182A 08               [12] 4833 	inc	r0
      00182B F6               [12] 4834 	mov	@r0,a
      00182C E5 81            [12] 4835 	mov	a,sp
      00182E 24 FC            [12] 4836 	add	a,#0xfc
      001830 F5 81            [12] 4837 	mov	sp,a
      001832 D0 04            [24] 4838 	pop	ar4
      001834 D0 05            [24] 4839 	pop	ar5
      001836 02 15 A2         [24] 4840 	ljmp	00118$
      001839                       4841 00110$:
                           00177C  4842 	C$fuzzy.h$363$1_0$89 ==.
                                   4843 ;	../../fuzzy.h:363: if (method == FUZZY_DEFUZZ_MOM) {
      001839 E5 10            [12] 4844 	mov	a,_bp
      00183B 24 F1            [12] 4845 	add	a,#0xf1
      00183D F8               [12] 4846 	mov	r0,a
      00183E B6 03 02         [24] 4847 	cjne	@r0,#0x03,00215$
      001841 80 02            [24] 4848 	sjmp	00216$
      001843                       4849 00215$:
      001843 80 79            [24] 4850 	sjmp	00112$
      001845                       4851 00216$:
                           001788  4852 	C$fuzzy.h$364$1_0$89 ==.
                                   4853 ;	../../fuzzy.h:364: return maximum > 0.0f ? maximum_sum / (float)maximum_count : 0.0f;
      001845 C0 05            [24] 4854 	push	ar5
      001847 C0 04            [24] 4855 	push	ar4
      001849 E5 10            [12] 4856 	mov	a,_bp
      00184B 24 14            [12] 4857 	add	a,#0x14
      00184D F8               [12] 4858 	mov	r0,a
      00184E E6               [12] 4859 	mov	a,@r0
      00184F C0 E0            [24] 4860 	push	acc
      001851 08               [12] 4861 	inc	r0
      001852 E6               [12] 4862 	mov	a,@r0
      001853 C0 E0            [24] 4863 	push	acc
      001855 08               [12] 4864 	inc	r0
      001856 E6               [12] 4865 	mov	a,@r0
      001857 C0 E0            [24] 4866 	push	acc
      001859 08               [12] 4867 	inc	r0
      00185A E6               [12] 4868 	mov	a,@r0
      00185B C0 E0            [24] 4869 	push	acc
      00185D 90 00 00         [24] 4870 	mov	dptr,#0x0000
      001860 E4               [12] 4871 	clr	a
      001861 F5 F0            [12] 4872 	mov	b,a
      001863 12 2B E5         [24] 4873 	lcall	___fslt
      001866 AF 82            [24] 4874 	mov	r7, dpl
      001868 E5 81            [12] 4875 	mov	a,sp
      00186A 24 FC            [12] 4876 	add	a,#0xfc
      00186C F5 81            [12] 4877 	mov	sp,a
      00186E D0 04            [24] 4878 	pop	ar4
      001870 D0 05            [24] 4879 	pop	ar5
      001872 EF               [12] 4880 	mov	a,r7
      001873 60 37            [24] 4881 	jz	00122$
      001875 8D 82            [24] 4882 	mov	dpl, r5
      001877 8C 83            [24] 4883 	mov	dph, r4
      001879 12 2C B7         [24] 4884 	lcall	___uint2fs
      00187C AC 82            [24] 4885 	mov	r4, dpl
      00187E AD 83            [24] 4886 	mov	r5, dph
      001880 AE F0            [24] 4887 	mov	r6, b
      001882 FF               [12] 4888 	mov	r7, a
      001883 C0 04            [24] 4889 	push	ar4
      001885 C0 05            [24] 4890 	push	ar5
      001887 C0 06            [24] 4891 	push	ar6
      001889 C0 07            [24] 4892 	push	ar7
      00188B E5 10            [12] 4893 	mov	a,_bp
      00188D 24 18            [12] 4894 	add	a,#0x18
      00188F F8               [12] 4895 	mov	r0,a
      001890 86 82            [24] 4896 	mov	dpl, @r0
      001892 08               [12] 4897 	inc	r0
      001893 86 83            [24] 4898 	mov	dph, @r0
      001895 08               [12] 4899 	inc	r0
      001896 86 F0            [24] 4900 	mov	b, @r0
      001898 08               [12] 4901 	inc	r0
      001899 E6               [12] 4902 	mov	a, @r0
      00189A 12 2D 2C         [24] 4903 	lcall	___fsdiv
      00189D AC 82            [24] 4904 	mov	r4, dpl
      00189F AD 83            [24] 4905 	mov	r5, dph
      0018A1 AE F0            [24] 4906 	mov	r6, b
      0018A3 FF               [12] 4907 	mov	r7, a
      0018A4 E5 81            [12] 4908 	mov	a,sp
      0018A6 24 FC            [12] 4909 	add	a,#0xfc
      0018A8 F5 81            [12] 4910 	mov	sp,a
      0018AA 80 08            [24] 4911 	sjmp	00123$
      0018AC                       4912 00122$:
      0018AC 7C 00            [12] 4913 	mov	r4,#0x00
      0018AE 7D 00            [12] 4914 	mov	r5,#0x00
      0018B0 7E 00            [12] 4915 	mov	r6,#0x00
      0018B2 7F 00            [12] 4916 	mov	r7,#0x00
      0018B4                       4917 00123$:
      0018B4 8C 82            [24] 4918 	mov	dpl, r4
      0018B6 8D 83            [24] 4919 	mov	dph, r5
      0018B8 8E F0            [24] 4920 	mov	b, r6
      0018BA EF               [12] 4921 	mov	a, r7
      0018BB 02 19 D1         [24] 4922 	ljmp	00120$
      0018BE                       4923 00112$:
                           001801  4924 	C$fuzzy.h$367$1_0$89 ==.
                                   4925 ;	../../fuzzy.h:367: if (method == FUZZY_DEFUZZ_SOM) {
      0018BE E5 10            [12] 4926 	mov	a,_bp
      0018C0 24 F1            [12] 4927 	add	a,#0xf1
      0018C2 F8               [12] 4928 	mov	r0,a
      0018C3 B6 04 4C         [24] 4929 	cjne	@r0,#0x04,00114$
                           001809  4930 	C$fuzzy.h$368$1_0$89 ==.
                                   4931 ;	../../fuzzy.h:368: return maximum > 0.0f ? smallest : 0.0f;
      0018C6 E5 10            [12] 4932 	mov	a,_bp
      0018C8 24 14            [12] 4933 	add	a,#0x14
      0018CA F8               [12] 4934 	mov	r0,a
      0018CB E6               [12] 4935 	mov	a,@r0
      0018CC C0 E0            [24] 4936 	push	acc
      0018CE 08               [12] 4937 	inc	r0
      0018CF E6               [12] 4938 	mov	a,@r0
      0018D0 C0 E0            [24] 4939 	push	acc
      0018D2 08               [12] 4940 	inc	r0
      0018D3 E6               [12] 4941 	mov	a,@r0
      0018D4 C0 E0            [24] 4942 	push	acc
      0018D6 08               [12] 4943 	inc	r0
      0018D7 E6               [12] 4944 	mov	a,@r0
      0018D8 C0 E0            [24] 4945 	push	acc
      0018DA 90 00 00         [24] 4946 	mov	dptr,#0x0000
      0018DD E4               [12] 4947 	clr	a
      0018DE F5 F0            [12] 4948 	mov	b,a
      0018E0 12 2B E5         [24] 4949 	lcall	___fslt
      0018E3 AF 82            [24] 4950 	mov	r7, dpl
      0018E5 E5 81            [12] 4951 	mov	a,sp
      0018E7 24 FC            [12] 4952 	add	a,#0xfc
      0018E9 F5 81            [12] 4953 	mov	sp,a
      0018EB EF               [12] 4954 	mov	a,r7
      0018EC 60 12            [24] 4955 	jz	00124$
      0018EE E5 10            [12] 4956 	mov	a,_bp
      0018F0 24 1C            [12] 4957 	add	a,#0x1c
      0018F2 F8               [12] 4958 	mov	r0,a
      0018F3 86 04            [24] 4959 	mov	ar4,@r0
      0018F5 08               [12] 4960 	inc	r0
      0018F6 86 05            [24] 4961 	mov	ar5,@r0
      0018F8 08               [12] 4962 	inc	r0
      0018F9 86 06            [24] 4963 	mov	ar6,@r0
      0018FB 08               [12] 4964 	inc	r0
      0018FC 86 07            [24] 4965 	mov	ar7,@r0
      0018FE 80 08            [24] 4966 	sjmp	00125$
      001900                       4967 00124$:
      001900 7C 00            [12] 4968 	mov	r4,#0x00
      001902 7D 00            [12] 4969 	mov	r5,#0x00
      001904 7E 00            [12] 4970 	mov	r6,#0x00
      001906 7F 00            [12] 4971 	mov	r7,#0x00
      001908                       4972 00125$:
      001908 8C 82            [24] 4973 	mov	dpl, r4
      00190A 8D 83            [24] 4974 	mov	dph, r5
      00190C 8E F0            [24] 4975 	mov	b, r6
      00190E EF               [12] 4976 	mov	a, r7
      00190F 02 19 D1         [24] 4977 	ljmp	00120$
      001912                       4978 00114$:
                           001855  4979 	C$fuzzy.h$371$1_0$89 ==.
                                   4980 ;	../../fuzzy.h:371: if (method == FUZZY_DEFUZZ_LOM) {
      001912 E5 10            [12] 4981 	mov	a,_bp
      001914 24 F1            [12] 4982 	add	a,#0xf1
      001916 F8               [12] 4983 	mov	r0,a
      001917 B6 05 4B         [24] 4984 	cjne	@r0,#0x05,00116$
                           00185D  4985 	C$fuzzy.h$372$1_0$89 ==.
                                   4986 ;	../../fuzzy.h:372: return maximum > 0.0f ? largest : 0.0f;
      00191A E5 10            [12] 4987 	mov	a,_bp
      00191C 24 14            [12] 4988 	add	a,#0x14
      00191E F8               [12] 4989 	mov	r0,a
      00191F E6               [12] 4990 	mov	a,@r0
      001920 C0 E0            [24] 4991 	push	acc
      001922 08               [12] 4992 	inc	r0
      001923 E6               [12] 4993 	mov	a,@r0
      001924 C0 E0            [24] 4994 	push	acc
      001926 08               [12] 4995 	inc	r0
      001927 E6               [12] 4996 	mov	a,@r0
      001928 C0 E0            [24] 4997 	push	acc
      00192A 08               [12] 4998 	inc	r0
      00192B E6               [12] 4999 	mov	a,@r0
      00192C C0 E0            [24] 5000 	push	acc
      00192E 90 00 00         [24] 5001 	mov	dptr,#0x0000
      001931 E4               [12] 5002 	clr	a
      001932 F5 F0            [12] 5003 	mov	b,a
      001934 12 2B E5         [24] 5004 	lcall	___fslt
      001937 AF 82            [24] 5005 	mov	r7, dpl
      001939 E5 81            [12] 5006 	mov	a,sp
      00193B 24 FC            [12] 5007 	add	a,#0xfc
      00193D F5 81            [12] 5008 	mov	sp,a
      00193F EF               [12] 5009 	mov	a,r7
      001940 60 12            [24] 5010 	jz	00126$
      001942 E5 10            [12] 5011 	mov	a,_bp
      001944 24 20            [12] 5012 	add	a,#0x20
      001946 F8               [12] 5013 	mov	r0,a
      001947 86 04            [24] 5014 	mov	ar4,@r0
      001949 08               [12] 5015 	inc	r0
      00194A 86 05            [24] 5016 	mov	ar5,@r0
      00194C 08               [12] 5017 	inc	r0
      00194D 86 06            [24] 5018 	mov	ar6,@r0
      00194F 08               [12] 5019 	inc	r0
      001950 86 07            [24] 5020 	mov	ar7,@r0
      001952 80 08            [24] 5021 	sjmp	00127$
      001954                       5022 00126$:
      001954 7C 00            [12] 5023 	mov	r4,#0x00
      001956 7D 00            [12] 5024 	mov	r5,#0x00
      001958 7E 00            [12] 5025 	mov	r6,#0x00
      00195A 7F 00            [12] 5026 	mov	r7,#0x00
      00195C                       5027 00127$:
      00195C 8C 82            [24] 5028 	mov	dpl, r4
      00195E 8D 83            [24] 5029 	mov	dph, r5
      001960 8E F0            [24] 5030 	mov	b, r6
      001962 EF               [12] 5031 	mov	a, r7
      001963 80 6C            [24] 5032 	sjmp	00120$
      001965                       5033 00116$:
                           0018A8  5034 	C$fuzzy.h$375$1_0$89 ==.
                                   5035 ;	../../fuzzy.h:375: return sum > 0.0f ? weighted / sum : 0.0f;
      001965 E5 10            [12] 5036 	mov	a,_bp
      001967 24 10            [12] 5037 	add	a,#0x10
      001969 F8               [12] 5038 	mov	r0,a
      00196A E6               [12] 5039 	mov	a,@r0
      00196B C0 E0            [24] 5040 	push	acc
      00196D 08               [12] 5041 	inc	r0
      00196E E6               [12] 5042 	mov	a,@r0
      00196F C0 E0            [24] 5043 	push	acc
      001971 08               [12] 5044 	inc	r0
      001972 E6               [12] 5045 	mov	a,@r0
      001973 C0 E0            [24] 5046 	push	acc
      001975 08               [12] 5047 	inc	r0
      001976 E6               [12] 5048 	mov	a,@r0
      001977 C0 E0            [24] 5049 	push	acc
      001979 90 00 00         [24] 5050 	mov	dptr,#0x0000
      00197C E4               [12] 5051 	clr	a
      00197D F5 F0            [12] 5052 	mov	b,a
      00197F 12 2B E5         [24] 5053 	lcall	___fslt
      001982 AF 82            [24] 5054 	mov	r7, dpl
      001984 E5 81            [12] 5055 	mov	a,sp
      001986 24 FC            [12] 5056 	add	a,#0xfc
      001988 F5 81            [12] 5057 	mov	sp,a
      00198A EF               [12] 5058 	mov	a,r7
      00198B 60 35            [24] 5059 	jz	00128$
      00198D E5 10            [12] 5060 	mov	a,_bp
      00198F 24 10            [12] 5061 	add	a,#0x10
      001991 F8               [12] 5062 	mov	r0,a
      001992 E6               [12] 5063 	mov	a,@r0
      001993 C0 E0            [24] 5064 	push	acc
      001995 08               [12] 5065 	inc	r0
      001996 E6               [12] 5066 	mov	a,@r0
      001997 C0 E0            [24] 5067 	push	acc
      001999 08               [12] 5068 	inc	r0
      00199A E6               [12] 5069 	mov	a,@r0
      00199B C0 E0            [24] 5070 	push	acc
      00199D 08               [12] 5071 	inc	r0
      00199E E6               [12] 5072 	mov	a,@r0
      00199F C0 E0            [24] 5073 	push	acc
      0019A1 E5 10            [12] 5074 	mov	a,_bp
      0019A3 24 0C            [12] 5075 	add	a,#0x0c
      0019A5 F8               [12] 5076 	mov	r0,a
      0019A6 86 82            [24] 5077 	mov	dpl, @r0
      0019A8 08               [12] 5078 	inc	r0
      0019A9 86 83            [24] 5079 	mov	dph, @r0
      0019AB 08               [12] 5080 	inc	r0
      0019AC 86 F0            [24] 5081 	mov	b, @r0
      0019AE 08               [12] 5082 	inc	r0
      0019AF E6               [12] 5083 	mov	a, @r0
      0019B0 12 2D 2C         [24] 5084 	lcall	___fsdiv
      0019B3 AC 82            [24] 5085 	mov	r4, dpl
      0019B5 AD 83            [24] 5086 	mov	r5, dph
      0019B7 AE F0            [24] 5087 	mov	r6, b
      0019B9 FF               [12] 5088 	mov	r7, a
      0019BA E5 81            [12] 5089 	mov	a,sp
      0019BC 24 FC            [12] 5090 	add	a,#0xfc
      0019BE F5 81            [12] 5091 	mov	sp,a
      0019C0 80 08            [24] 5092 	sjmp	00129$
      0019C2                       5093 00128$:
      0019C2 7C 00            [12] 5094 	mov	r4,#0x00
      0019C4 7D 00            [12] 5095 	mov	r5,#0x00
      0019C6 7E 00            [12] 5096 	mov	r6,#0x00
      0019C8 7F 00            [12] 5097 	mov	r7,#0x00
      0019CA                       5098 00129$:
      0019CA 8C 82            [24] 5099 	mov	dpl, r4
      0019CC 8D 83            [24] 5100 	mov	dph, r5
      0019CE 8E F0            [24] 5101 	mov	b, r6
      0019D0 EF               [12] 5102 	mov	a, r7
      0019D1                       5103 00120$:
                           001914  5104 	C$fuzzy.h$376$1_0$89 ==.
                                   5105 ;	../../fuzzy.h:376: }
      0019D1 85 10 81         [24] 5106 	mov	sp,_bp
      0019D4 D0 10            [24] 5107 	pop	_bp
                           001919  5108 	C$fuzzy.h$376$1_0$89 ==.
                           001919  5109 	XG$fuzzy_rules_defuzzify$0$0 ==.
      0019D6 22               [24] 5110 	ret
                                   5111 ;------------------------------------------------------------
                                   5112 ;Allocation info for local variables in function 'fuzzy_rules_cog'
                                   5113 ;------------------------------------------------------------
                                   5114 ;lower         Allocated to stack - _bp -6 +4 
                                   5115 ;upper         Allocated to stack - _bp -10 +4 
                                   5116 ;step          Allocated to stack - _bp -14 +4 
                                   5117 ;rules         Allocated to registers r5 r6 r7 
                                   5118 ;------------------------------------------------------------
                           00191A  5119 	G$fuzzy_rules_cog$0$0 ==.
                           00191A  5120 	C$fuzzy.h$378$1_0$99 ==.
                                   5121 ;	../../fuzzy.h:378: float fuzzy_rules_cog(const fuzzy_rules_t *rules, float lower, float upper, float step)
                                   5122 ;	-----------------------------------------
                                   5123 ;	 function fuzzy_rules_cog
                                   5124 ;	-----------------------------------------
      0019D7                       5125 _fuzzy_rules_cog:
      0019D7 C0 10            [24] 5126 	push	_bp
      0019D9 85 81 10         [24] 5127 	mov	_bp,sp
      0019DC AD 82            [24] 5128 	mov	r5, dpl
      0019DE AE 83            [24] 5129 	mov	r6, dph
      0019E0 AF F0            [24] 5130 	mov	r7, b
                           001925  5131 	C$fuzzy.h$380$1_0$99 ==.
                                   5132 ;	../../fuzzy.h:380: return fuzzy_rules_defuzzify(rules, lower, upper, step, FUZZY_DEFUZZ_COG);
      0019E2 E4               [12] 5133 	clr	a
      0019E3 C0 E0            [24] 5134 	push	acc
      0019E5 E5 10            [12] 5135 	mov	a,_bp
      0019E7 24 F2            [12] 5136 	add	a,#0xf2
      0019E9 F8               [12] 5137 	mov	r0,a
      0019EA E6               [12] 5138 	mov	a,@r0
      0019EB C0 E0            [24] 5139 	push	acc
      0019ED 08               [12] 5140 	inc	r0
      0019EE E6               [12] 5141 	mov	a,@r0
      0019EF C0 E0            [24] 5142 	push	acc
      0019F1 08               [12] 5143 	inc	r0
      0019F2 E6               [12] 5144 	mov	a,@r0
      0019F3 C0 E0            [24] 5145 	push	acc
      0019F5 08               [12] 5146 	inc	r0
      0019F6 E6               [12] 5147 	mov	a,@r0
      0019F7 C0 E0            [24] 5148 	push	acc
      0019F9 E5 10            [12] 5149 	mov	a,_bp
      0019FB 24 F6            [12] 5150 	add	a,#0xf6
      0019FD F8               [12] 5151 	mov	r0,a
      0019FE E6               [12] 5152 	mov	a,@r0
      0019FF C0 E0            [24] 5153 	push	acc
      001A01 08               [12] 5154 	inc	r0
      001A02 E6               [12] 5155 	mov	a,@r0
      001A03 C0 E0            [24] 5156 	push	acc
      001A05 08               [12] 5157 	inc	r0
      001A06 E6               [12] 5158 	mov	a,@r0
      001A07 C0 E0            [24] 5159 	push	acc
      001A09 08               [12] 5160 	inc	r0
      001A0A E6               [12] 5161 	mov	a,@r0
      001A0B C0 E0            [24] 5162 	push	acc
      001A0D E5 10            [12] 5163 	mov	a,_bp
      001A0F 24 FA            [12] 5164 	add	a,#0xfa
      001A11 F8               [12] 5165 	mov	r0,a
      001A12 E6               [12] 5166 	mov	a,@r0
      001A13 C0 E0            [24] 5167 	push	acc
      001A15 08               [12] 5168 	inc	r0
      001A16 E6               [12] 5169 	mov	a,@r0
      001A17 C0 E0            [24] 5170 	push	acc
      001A19 08               [12] 5171 	inc	r0
      001A1A E6               [12] 5172 	mov	a,@r0
      001A1B C0 E0            [24] 5173 	push	acc
      001A1D 08               [12] 5174 	inc	r0
      001A1E E6               [12] 5175 	mov	a,@r0
      001A1F C0 E0            [24] 5176 	push	acc
      001A21 8D 82            [24] 5177 	mov	dpl, r5
      001A23 8E 83            [24] 5178 	mov	dph, r6
      001A25 8F F0            [24] 5179 	mov	b, r7
      001A27 12 14 93         [24] 5180 	lcall	_fuzzy_rules_defuzzify
      001A2A AC 82            [24] 5181 	mov	r4, dpl
      001A2C AD 83            [24] 5182 	mov	r5, dph
      001A2E AE F0            [24] 5183 	mov	r6, b
      001A30 FF               [12] 5184 	mov	r7, a
      001A31 E5 81            [12] 5185 	mov	a,sp
      001A33 24 F3            [12] 5186 	add	a,#0xf3
      001A35 F5 81            [12] 5187 	mov	sp,a
      001A37 8C 82            [24] 5188 	mov	dpl, r4
      001A39 8D 83            [24] 5189 	mov	dph, r5
      001A3B 8E F0            [24] 5190 	mov	b, r6
      001A3D EF               [12] 5191 	mov	a, r7
                           001981  5192 	C$fuzzy.h$381$1_0$99 ==.
                                   5193 ;	../../fuzzy.h:381: }
      001A3E D0 10            [24] 5194 	pop	_bp
                           001983  5195 	C$fuzzy.h$381$1_0$99 ==.
                           001983  5196 	XG$fuzzy_rules_cog$0$0 ==.
      001A40 22               [24] 5197 	ret
                                   5198 ;------------------------------------------------------------
                                   5199 ;Allocation info for local variables in function 'temperature_low'
                                   5200 ;------------------------------------------------------------
                                   5201 ;x             Allocated to registers r4 r5 r6 r7 
                                   5202 ;------------------------------------------------------------
                           001984  5203 	Fsugeno_demo$temperature_low$0$0 ==.
                           001984  5204 	C$sugeno_demo.c$29$1_0$101 ==.
                                   5205 ;	../../sugeno_demo.c:29: FUZZY_VAR(temperature_low, FUZZY_SHAPE_RAMP, HEDGE_NONE, 15.0f, 40.0f, false)
                                   5206 ;	-----------------------------------------
                                   5207 ;	 function temperature_low
                                   5208 ;	-----------------------------------------
      001A41                       5209 _temperature_low:
      001A41 AC 82            [24] 5210 	mov	r4,dpl
      001A43 AD 83            [24] 5211 	mov	r5,dph
      001A45 AE F0            [24] 5212 	mov	r6,b
      001A47 FF               [12] 5213 	mov	r7,a
      001A48 C0 04            [24] 5214 	push	ar4
      001A4A C0 05            [24] 5215 	push	ar5
      001A4C C0 06            [24] 5216 	push	ar6
      001A4E C0 07            [24] 5217 	push	ar7
      001A50 90 2E B1         [24] 5218 	mov	dptr,#_temperature_low_fuzzy_variable
      001A53 75 F0 80         [24] 5219 	mov	b, #0x80
      001A56 12 0E 65         [24] 5220 	lcall	_fuzzy_8051_eval
      001A59 AC 82            [24] 5221 	mov	r4, dpl
      001A5B AD 83            [24] 5222 	mov	r5, dph
      001A5D AE F0            [24] 5223 	mov	r6, b
      001A5F FF               [12] 5224 	mov	r7, a
      001A60 E5 81            [12] 5225 	mov	a,sp
      001A62 24 FC            [12] 5226 	add	a,#0xfc
      001A64 F5 81            [12] 5227 	mov	sp,a
      001A66 8C 82            [24] 5228 	mov	dpl, r4
      001A68 8D 83            [24] 5229 	mov	dph, r5
      001A6A 8E F0            [24] 5230 	mov	b, r6
      001A6C EF               [12] 5231 	mov	a, r7
                           0019B0  5232 	C$sugeno_demo.c$29$1_0$101 ==.
                           0019B0  5233 	XFsugeno_demo$temperature_low$0$0 ==.
      001A6D 22               [24] 5234 	ret
                                   5235 ;------------------------------------------------------------
                                   5236 ;Allocation info for local variables in function 'temperature_high'
                                   5237 ;------------------------------------------------------------
                                   5238 ;x             Allocated to registers r4 r5 r6 r7 
                                   5239 ;------------------------------------------------------------
                           0019B1  5240 	Fsugeno_demo$temperature_high$0$0 ==.
                           0019B1  5241 	C$sugeno_demo.c$30$1_0$103 ==.
                                   5242 ;	../../sugeno_demo.c:30: FUZZY_VAR(temperature_high, FUZZY_SHAPE_RAMP, HEDGE_NONE, 35.0f, 75.0f, true)
                                   5243 ;	-----------------------------------------
                                   5244 ;	 function temperature_high
                                   5245 ;	-----------------------------------------
      001A6E                       5246 _temperature_high:
      001A6E AC 82            [24] 5247 	mov	r4,dpl
      001A70 AD 83            [24] 5248 	mov	r5,dph
      001A72 AE F0            [24] 5249 	mov	r6,b
      001A74 FF               [12] 5250 	mov	r7,a
      001A75 C0 04            [24] 5251 	push	ar4
      001A77 C0 05            [24] 5252 	push	ar5
      001A79 C0 06            [24] 5253 	push	ar6
      001A7B C0 07            [24] 5254 	push	ar7
      001A7D 90 2E C3         [24] 5255 	mov	dptr,#_temperature_high_fuzzy_variable
      001A80 75 F0 80         [24] 5256 	mov	b, #0x80
      001A83 12 0E 65         [24] 5257 	lcall	_fuzzy_8051_eval
      001A86 AC 82            [24] 5258 	mov	r4, dpl
      001A88 AD 83            [24] 5259 	mov	r5, dph
      001A8A AE F0            [24] 5260 	mov	r6, b
      001A8C FF               [12] 5261 	mov	r7, a
      001A8D E5 81            [12] 5262 	mov	a,sp
      001A8F 24 FC            [12] 5263 	add	a,#0xfc
      001A91 F5 81            [12] 5264 	mov	sp,a
      001A93 8C 82            [24] 5265 	mov	dpl, r4
      001A95 8D 83            [24] 5266 	mov	dph, r5
      001A97 8E F0            [24] 5267 	mov	b, r6
      001A99 EF               [12] 5268 	mov	a, r7
                           0019DD  5269 	C$sugeno_demo.c$30$1_0$103 ==.
                           0019DD  5270 	XFsugeno_demo$temperature_high$0$0 ==.
      001A9A 22               [24] 5271 	ret
                                   5272 ;------------------------------------------------------------
                                   5273 ;Allocation info for local variables in function 'load_low'
                                   5274 ;------------------------------------------------------------
                                   5275 ;x             Allocated to registers r4 r5 r6 r7 
                                   5276 ;------------------------------------------------------------
                           0019DE  5277 	Fsugeno_demo$load_low$0$0 ==.
                           0019DE  5278 	C$sugeno_demo.c$31$1_0$105 ==.
                                   5279 ;	../../sugeno_demo.c:31: FUZZY_VAR(load_low, FUZZY_SHAPE_RAMP, HEDGE_NONE, 20.0f, 50.0f, false)
                                   5280 ;	-----------------------------------------
                                   5281 ;	 function load_low
                                   5282 ;	-----------------------------------------
      001A9B                       5283 _load_low:
      001A9B AC 82            [24] 5284 	mov	r4,dpl
      001A9D AD 83            [24] 5285 	mov	r5,dph
      001A9F AE F0            [24] 5286 	mov	r6,b
      001AA1 FF               [12] 5287 	mov	r7,a
      001AA2 C0 04            [24] 5288 	push	ar4
      001AA4 C0 05            [24] 5289 	push	ar5
      001AA6 C0 06            [24] 5290 	push	ar6
      001AA8 C0 07            [24] 5291 	push	ar7
      001AAA 90 2E D5         [24] 5292 	mov	dptr,#_load_low_fuzzy_variable
      001AAD 75 F0 80         [24] 5293 	mov	b, #0x80
      001AB0 12 0E 65         [24] 5294 	lcall	_fuzzy_8051_eval
      001AB3 AC 82            [24] 5295 	mov	r4, dpl
      001AB5 AD 83            [24] 5296 	mov	r5, dph
      001AB7 AE F0            [24] 5297 	mov	r6, b
      001AB9 FF               [12] 5298 	mov	r7, a
      001ABA E5 81            [12] 5299 	mov	a,sp
      001ABC 24 FC            [12] 5300 	add	a,#0xfc
      001ABE F5 81            [12] 5301 	mov	sp,a
      001AC0 8C 82            [24] 5302 	mov	dpl, r4
      001AC2 8D 83            [24] 5303 	mov	dph, r5
      001AC4 8E F0            [24] 5304 	mov	b, r6
      001AC6 EF               [12] 5305 	mov	a, r7
                           001A0A  5306 	C$sugeno_demo.c$31$1_0$105 ==.
                           001A0A  5307 	XFsugeno_demo$load_low$0$0 ==.
      001AC7 22               [24] 5308 	ret
                                   5309 ;------------------------------------------------------------
                                   5310 ;Allocation info for local variables in function 'load_high'
                                   5311 ;------------------------------------------------------------
                                   5312 ;x             Allocated to registers r4 r5 r6 r7 
                                   5313 ;------------------------------------------------------------
                           001A0B  5314 	Fsugeno_demo$load_high$0$0 ==.
                           001A0B  5315 	C$sugeno_demo.c$32$1_0$107 ==.
                                   5316 ;	../../sugeno_demo.c:32: FUZZY_VAR(load_high, FUZZY_SHAPE_RAMP, HEDGE_NONE, 45.0f, 85.0f, true)
                                   5317 ;	-----------------------------------------
                                   5318 ;	 function load_high
                                   5319 ;	-----------------------------------------
      001AC8                       5320 _load_high:
      001AC8 AC 82            [24] 5321 	mov	r4,dpl
      001ACA AD 83            [24] 5322 	mov	r5,dph
      001ACC AE F0            [24] 5323 	mov	r6,b
      001ACE FF               [12] 5324 	mov	r7,a
      001ACF C0 04            [24] 5325 	push	ar4
      001AD1 C0 05            [24] 5326 	push	ar5
      001AD3 C0 06            [24] 5327 	push	ar6
      001AD5 C0 07            [24] 5328 	push	ar7
      001AD7 90 2E E7         [24] 5329 	mov	dptr,#_load_high_fuzzy_variable
      001ADA 75 F0 80         [24] 5330 	mov	b, #0x80
      001ADD 12 0E 65         [24] 5331 	lcall	_fuzzy_8051_eval
      001AE0 AC 82            [24] 5332 	mov	r4, dpl
      001AE2 AD 83            [24] 5333 	mov	r5, dph
      001AE4 AE F0            [24] 5334 	mov	r6, b
      001AE6 FF               [12] 5335 	mov	r7, a
      001AE7 E5 81            [12] 5336 	mov	a,sp
      001AE9 24 FC            [12] 5337 	add	a,#0xfc
      001AEB F5 81            [12] 5338 	mov	sp,a
      001AED 8C 82            [24] 5339 	mov	dpl, r4
      001AEF 8D 83            [24] 5340 	mov	dph, r5
      001AF1 8E F0            [24] 5341 	mov	b, r6
      001AF3 EF               [12] 5342 	mov	a, r7
                           001A37  5343 	C$sugeno_demo.c$32$1_0$107 ==.
                           001A37  5344 	XFsugeno_demo$load_high$0$0 ==.
      001AF4 22               [24] 5345 	ret
                                   5346 ;------------------------------------------------------------
                                   5347 ;Allocation info for local variables in function 'vibration_low'
                                   5348 ;------------------------------------------------------------
                                   5349 ;x             Allocated to registers r4 r5 r6 r7 
                                   5350 ;------------------------------------------------------------
                           001A38  5351 	Fsugeno_demo$vibration_low$0$0 ==.
                           001A38  5352 	C$sugeno_demo.c$33$1_0$109 ==.
                                   5353 ;	../../sugeno_demo.c:33: FUZZY_VAR(vibration_low, FUZZY_SHAPE_RAMP, HEDGE_NONE, 1.0f, 4.0f, false)
                                   5354 ;	-----------------------------------------
                                   5355 ;	 function vibration_low
                                   5356 ;	-----------------------------------------
      001AF5                       5357 _vibration_low:
      001AF5 AC 82            [24] 5358 	mov	r4,dpl
      001AF7 AD 83            [24] 5359 	mov	r5,dph
      001AF9 AE F0            [24] 5360 	mov	r6,b
      001AFB FF               [12] 5361 	mov	r7,a
      001AFC C0 04            [24] 5362 	push	ar4
      001AFE C0 05            [24] 5363 	push	ar5
      001B00 C0 06            [24] 5364 	push	ar6
      001B02 C0 07            [24] 5365 	push	ar7
      001B04 90 2E F9         [24] 5366 	mov	dptr,#_vibration_low_fuzzy_variable
      001B07 75 F0 80         [24] 5367 	mov	b, #0x80
      001B0A 12 0E 65         [24] 5368 	lcall	_fuzzy_8051_eval
      001B0D AC 82            [24] 5369 	mov	r4, dpl
      001B0F AD 83            [24] 5370 	mov	r5, dph
      001B11 AE F0            [24] 5371 	mov	r6, b
      001B13 FF               [12] 5372 	mov	r7, a
      001B14 E5 81            [12] 5373 	mov	a,sp
      001B16 24 FC            [12] 5374 	add	a,#0xfc
      001B18 F5 81            [12] 5375 	mov	sp,a
      001B1A 8C 82            [24] 5376 	mov	dpl, r4
      001B1C 8D 83            [24] 5377 	mov	dph, r5
      001B1E 8E F0            [24] 5378 	mov	b, r6
      001B20 EF               [12] 5379 	mov	a, r7
                           001A64  5380 	C$sugeno_demo.c$33$1_0$109 ==.
                           001A64  5381 	XFsugeno_demo$vibration_low$0$0 ==.
      001B21 22               [24] 5382 	ret
                                   5383 ;------------------------------------------------------------
                                   5384 ;Allocation info for local variables in function 'vibration_high'
                                   5385 ;------------------------------------------------------------
                                   5386 ;x             Allocated to registers r4 r5 r6 r7 
                                   5387 ;------------------------------------------------------------
                           001A65  5388 	Fsugeno_demo$vibration_high$0$0 ==.
                           001A65  5389 	C$sugeno_demo.c$34$1_0$111 ==.
                                   5390 ;	../../sugeno_demo.c:34: FUZZY_VAR(vibration_high, FUZZY_SHAPE_RAMP, HEDGE_NONE, 3.0f, 8.0f, true)
                                   5391 ;	-----------------------------------------
                                   5392 ;	 function vibration_high
                                   5393 ;	-----------------------------------------
      001B22                       5394 _vibration_high:
      001B22 AC 82            [24] 5395 	mov	r4,dpl
      001B24 AD 83            [24] 5396 	mov	r5,dph
      001B26 AE F0            [24] 5397 	mov	r6,b
      001B28 FF               [12] 5398 	mov	r7,a
      001B29 C0 04            [24] 5399 	push	ar4
      001B2B C0 05            [24] 5400 	push	ar5
      001B2D C0 06            [24] 5401 	push	ar6
      001B2F C0 07            [24] 5402 	push	ar7
      001B31 90 2F 0B         [24] 5403 	mov	dptr,#_vibration_high_fuzzy_variable
      001B34 75 F0 80         [24] 5404 	mov	b, #0x80
      001B37 12 0E 65         [24] 5405 	lcall	_fuzzy_8051_eval
      001B3A AC 82            [24] 5406 	mov	r4, dpl
      001B3C AD 83            [24] 5407 	mov	r5, dph
      001B3E AE F0            [24] 5408 	mov	r6, b
      001B40 FF               [12] 5409 	mov	r7, a
      001B41 E5 81            [12] 5410 	mov	a,sp
      001B43 24 FC            [12] 5411 	add	a,#0xfc
      001B45 F5 81            [12] 5412 	mov	sp,a
      001B47 8C 82            [24] 5413 	mov	dpl, r4
      001B49 8D 83            [24] 5414 	mov	dph, r5
      001B4B 8E F0            [24] 5415 	mov	b, r6
      001B4D EF               [12] 5416 	mov	a, r7
                           001A91  5417 	C$sugeno_demo.c$34$1_0$111 ==.
                           001A91  5418 	XFsugeno_demo$vibration_high$0$0 ==.
      001B4E 22               [24] 5419 	ret
                                   5420 ;------------------------------------------------------------
                                   5421 ;Allocation info for local variables in function 'response_idle'
                                   5422 ;------------------------------------------------------------
                                   5423 ;load          Allocated to stack - _bp -6 +4 
                                   5424 ;vibration     Allocated to stack - _bp -10 +4 
                                   5425 ;temperature   Allocated to registers r4 r5 r6 r7 
                                   5426 ;sloc0         Allocated to stack - _bp +1 +4 
                                   5427 ;------------------------------------------------------------
                           001A92  5428 	Fsugeno_demo$response_idle$0$0 ==.
                           001A92  5429 	C$sugeno_demo.c$36$1_0$113 ==.
                                   5430 ;	../../sugeno_demo.c:36: static float response_idle(float temperature, float load, float vibration) { return 8.0f + 0.20f * temperature + 0.08f * load + 0.50f * vibration; }
                                   5431 ;	-----------------------------------------
                                   5432 ;	 function response_idle
                                   5433 ;	-----------------------------------------
      001B4F                       5434 _response_idle:
      001B4F C0 10            [24] 5435 	push	_bp
      001B51 85 81 10         [24] 5436 	mov	_bp,sp
      001B54 AC 82            [24] 5437 	mov	r4,dpl
      001B56 AD 83            [24] 5438 	mov	r5,dph
      001B58 AE F0            [24] 5439 	mov	r6,b
      001B5A FF               [12] 5440 	mov	r7,a
      001B5B E5 81            [12] 5441 	mov	a,sp
      001B5D 24 04            [12] 5442 	add	a,#0x04
      001B5F F5 81            [12] 5443 	mov	sp,a
      001B61 C0 04            [24] 5444 	push	ar4
      001B63 C0 05            [24] 5445 	push	ar5
      001B65 C0 06            [24] 5446 	push	ar6
      001B67 C0 07            [24] 5447 	push	ar7
      001B69 90 CC CD         [24] 5448 	mov	dptr,#0xcccd
      001B6C 75 F0 4C         [24] 5449 	mov	b, #0x4c
      001B6F 74 3E            [12] 5450 	mov	a, #0x3e
      001B71 12 2A B5         [24] 5451 	lcall	___fsmul
      001B74 AC 82            [24] 5452 	mov	r4, dpl
      001B76 AD 83            [24] 5453 	mov	r5, dph
      001B78 AE F0            [24] 5454 	mov	r6, b
      001B7A FF               [12] 5455 	mov	r7, a
      001B7B E5 81            [12] 5456 	mov	a,sp
      001B7D 24 FC            [12] 5457 	add	a,#0xfc
      001B7F F5 81            [12] 5458 	mov	sp,a
      001B81 E4               [12] 5459 	clr	a
      001B82 C0 E0            [24] 5460 	push	acc
      001B84 C0 E0            [24] 5461 	push	acc
      001B86 C0 E0            [24] 5462 	push	acc
      001B88 74 41            [12] 5463 	mov	a,#0x41
      001B8A C0 E0            [24] 5464 	push	acc
      001B8C 8C 82            [24] 5465 	mov	dpl, r4
      001B8E 8D 83            [24] 5466 	mov	dph, r5
      001B90 8E F0            [24] 5467 	mov	b, r6
      001B92 EF               [12] 5468 	mov	a, r7
      001B93 12 2C 15         [24] 5469 	lcall	___fsadd
      001B96 A8 10            [24] 5470 	mov	r0,_bp
      001B98 08               [12] 5471 	inc	r0
      001B99 A6 82            [24] 5472 	mov	@r0, dpl
      001B9B 08               [12] 5473 	inc	r0
      001B9C A6 83            [24] 5474 	mov	@r0, dph
      001B9E 08               [12] 5475 	inc	r0
      001B9F A6 F0            [24] 5476 	mov	@r0, b
      001BA1 08               [12] 5477 	inc	r0
      001BA2 F6               [12] 5478 	mov	@r0,a
      001BA3 E5 81            [12] 5479 	mov	a,sp
      001BA5 24 FC            [12] 5480 	add	a,#0xfc
      001BA7 F5 81            [12] 5481 	mov	sp,a
      001BA9 E5 10            [12] 5482 	mov	a,_bp
      001BAB 24 FA            [12] 5483 	add	a,#0xfa
      001BAD F8               [12] 5484 	mov	r0,a
      001BAE E6               [12] 5485 	mov	a,@r0
      001BAF C0 E0            [24] 5486 	push	acc
      001BB1 08               [12] 5487 	inc	r0
      001BB2 E6               [12] 5488 	mov	a,@r0
      001BB3 C0 E0            [24] 5489 	push	acc
      001BB5 08               [12] 5490 	inc	r0
      001BB6 E6               [12] 5491 	mov	a,@r0
      001BB7 C0 E0            [24] 5492 	push	acc
      001BB9 08               [12] 5493 	inc	r0
      001BBA E6               [12] 5494 	mov	a,@r0
      001BBB C0 E0            [24] 5495 	push	acc
      001BBD 90 D7 0A         [24] 5496 	mov	dptr,#0xd70a
      001BC0 75 F0 A3         [24] 5497 	mov	b, #0xa3
      001BC3 74 3D            [12] 5498 	mov	a, #0x3d
      001BC5 12 2A B5         [24] 5499 	lcall	___fsmul
      001BC8 AA 82            [24] 5500 	mov	r2, dpl
      001BCA AB 83            [24] 5501 	mov	r3, dph
      001BCC AE F0            [24] 5502 	mov	r6, b
      001BCE FF               [12] 5503 	mov	r7, a
      001BCF E5 81            [12] 5504 	mov	a,sp
      001BD1 24 FC            [12] 5505 	add	a,#0xfc
      001BD3 F5 81            [12] 5506 	mov	sp,a
      001BD5 C0 02            [24] 5507 	push	ar2
      001BD7 C0 03            [24] 5508 	push	ar3
      001BD9 C0 06            [24] 5509 	push	ar6
      001BDB C0 07            [24] 5510 	push	ar7
      001BDD A8 10            [24] 5511 	mov	r0,_bp
      001BDF 08               [12] 5512 	inc	r0
      001BE0 86 82            [24] 5513 	mov	dpl, @r0
      001BE2 08               [12] 5514 	inc	r0
      001BE3 86 83            [24] 5515 	mov	dph, @r0
      001BE5 08               [12] 5516 	inc	r0
      001BE6 86 F0            [24] 5517 	mov	b, @r0
      001BE8 08               [12] 5518 	inc	r0
      001BE9 E6               [12] 5519 	mov	a, @r0
      001BEA 12 2C 15         [24] 5520 	lcall	___fsadd
      001BED A8 10            [24] 5521 	mov	r0,_bp
      001BEF 08               [12] 5522 	inc	r0
      001BF0 A6 82            [24] 5523 	mov	@r0, dpl
      001BF2 08               [12] 5524 	inc	r0
      001BF3 A6 83            [24] 5525 	mov	@r0, dph
      001BF5 08               [12] 5526 	inc	r0
      001BF6 A6 F0            [24] 5527 	mov	@r0, b
      001BF8 08               [12] 5528 	inc	r0
      001BF9 F6               [12] 5529 	mov	@r0,a
      001BFA E5 81            [12] 5530 	mov	a,sp
      001BFC 24 FC            [12] 5531 	add	a,#0xfc
      001BFE F5 81            [12] 5532 	mov	sp,a
      001C00 E5 10            [12] 5533 	mov	a,_bp
      001C02 24 F6            [12] 5534 	add	a,#0xf6
      001C04 F8               [12] 5535 	mov	r0,a
      001C05 E6               [12] 5536 	mov	a,@r0
      001C06 C0 E0            [24] 5537 	push	acc
      001C08 08               [12] 5538 	inc	r0
      001C09 E6               [12] 5539 	mov	a,@r0
      001C0A C0 E0            [24] 5540 	push	acc
      001C0C 08               [12] 5541 	inc	r0
      001C0D E6               [12] 5542 	mov	a,@r0
      001C0E C0 E0            [24] 5543 	push	acc
      001C10 08               [12] 5544 	inc	r0
      001C11 E6               [12] 5545 	mov	a,@r0
      001C12 C0 E0            [24] 5546 	push	acc
      001C14 90 00 00         [24] 5547 	mov	dptr,#(0x00&0x00ff)
      001C17 E4               [12] 5548 	clr	a
      001C18 F5 F0            [12] 5549 	mov	b,a
      001C1A 74 3F            [12] 5550 	mov	a,#0x3f
      001C1C 12 2A B5         [24] 5551 	lcall	___fsmul
      001C1F AA 82            [24] 5552 	mov	r2, dpl
      001C21 AB 83            [24] 5553 	mov	r3, dph
      001C23 AE F0            [24] 5554 	mov	r6, b
      001C25 FF               [12] 5555 	mov	r7, a
      001C26 E5 81            [12] 5556 	mov	a,sp
      001C28 24 FC            [12] 5557 	add	a,#0xfc
      001C2A F5 81            [12] 5558 	mov	sp,a
      001C2C C0 02            [24] 5559 	push	ar2
      001C2E C0 03            [24] 5560 	push	ar3
      001C30 C0 06            [24] 5561 	push	ar6
      001C32 C0 07            [24] 5562 	push	ar7
      001C34 A8 10            [24] 5563 	mov	r0,_bp
      001C36 08               [12] 5564 	inc	r0
      001C37 86 82            [24] 5565 	mov	dpl, @r0
      001C39 08               [12] 5566 	inc	r0
      001C3A 86 83            [24] 5567 	mov	dph, @r0
      001C3C 08               [12] 5568 	inc	r0
      001C3D 86 F0            [24] 5569 	mov	b, @r0
      001C3F 08               [12] 5570 	inc	r0
      001C40 E6               [12] 5571 	mov	a, @r0
      001C41 12 2C 15         [24] 5572 	lcall	___fsadd
      001C44 AC 82            [24] 5573 	mov	r4, dpl
      001C46 AD 83            [24] 5574 	mov	r5, dph
      001C48 AE F0            [24] 5575 	mov	r6, b
      001C4A FF               [12] 5576 	mov	r7, a
      001C4B E5 81            [12] 5577 	mov	a,sp
      001C4D 24 FC            [12] 5578 	add	a,#0xfc
      001C4F F5 81            [12] 5579 	mov	sp,a
      001C51 8C 82            [24] 5580 	mov	dpl, r4
      001C53 8D 83            [24] 5581 	mov	dph, r5
      001C55 8E F0            [24] 5582 	mov	b, r6
      001C57 EF               [12] 5583 	mov	a, r7
      001C58 85 10 81         [24] 5584 	mov	sp,_bp
      001C5B D0 10            [24] 5585 	pop	_bp
                           001BA0  5586 	C$sugeno_demo.c$36$1_0$113 ==.
                           001BA0  5587 	XFsugeno_demo$response_idle$0$0 ==.
      001C5D 22               [24] 5588 	ret
                                   5589 ;------------------------------------------------------------
                                   5590 ;Allocation info for local variables in function 'response_economy'
                                   5591 ;------------------------------------------------------------
                                   5592 ;load          Allocated to stack - _bp -6 +4 
                                   5593 ;vibration     Allocated to stack - _bp -10 +4 
                                   5594 ;temperature   Allocated to registers r4 r5 r6 r7 
                                   5595 ;sloc0         Allocated to stack - _bp +1 +4 
                                   5596 ;------------------------------------------------------------
                           001BA1  5597 	Fsugeno_demo$response_economy$0$0 ==.
                           001BA1  5598 	C$sugeno_demo.c$37$1_0$115 ==.
                                   5599 ;	../../sugeno_demo.c:37: static float response_economy(float temperature, float load, float vibration) { return 12.0f + 0.30f * temperature + 0.18f * load + 0.80f * vibration; }
                                   5600 ;	-----------------------------------------
                                   5601 ;	 function response_economy
                                   5602 ;	-----------------------------------------
      001C5E                       5603 _response_economy:
      001C5E C0 10            [24] 5604 	push	_bp
      001C60 85 81 10         [24] 5605 	mov	_bp,sp
      001C63 AC 82            [24] 5606 	mov	r4,dpl
      001C65 AD 83            [24] 5607 	mov	r5,dph
      001C67 AE F0            [24] 5608 	mov	r6,b
      001C69 FF               [12] 5609 	mov	r7,a
      001C6A E5 81            [12] 5610 	mov	a,sp
      001C6C 24 04            [12] 5611 	add	a,#0x04
      001C6E F5 81            [12] 5612 	mov	sp,a
      001C70 C0 04            [24] 5613 	push	ar4
      001C72 C0 05            [24] 5614 	push	ar5
      001C74 C0 06            [24] 5615 	push	ar6
      001C76 C0 07            [24] 5616 	push	ar7
      001C78 90 99 9A         [24] 5617 	mov	dptr,#0x999a
      001C7B 75 F0 99         [24] 5618 	mov	b, #0x99
      001C7E 74 3E            [12] 5619 	mov	a, #0x3e
      001C80 12 2A B5         [24] 5620 	lcall	___fsmul
      001C83 AC 82            [24] 5621 	mov	r4, dpl
      001C85 AD 83            [24] 5622 	mov	r5, dph
      001C87 AE F0            [24] 5623 	mov	r6, b
      001C89 FF               [12] 5624 	mov	r7, a
      001C8A E5 81            [12] 5625 	mov	a,sp
      001C8C 24 FC            [12] 5626 	add	a,#0xfc
      001C8E F5 81            [12] 5627 	mov	sp,a
      001C90 E4               [12] 5628 	clr	a
      001C91 C0 E0            [24] 5629 	push	acc
      001C93 C0 E0            [24] 5630 	push	acc
      001C95 74 40            [12] 5631 	mov	a,#0x40
      001C97 C0 E0            [24] 5632 	push	acc
      001C99 04               [12] 5633 	inc	a
      001C9A C0 E0            [24] 5634 	push	acc
      001C9C 8C 82            [24] 5635 	mov	dpl, r4
      001C9E 8D 83            [24] 5636 	mov	dph, r5
      001CA0 8E F0            [24] 5637 	mov	b, r6
      001CA2 EF               [12] 5638 	mov	a, r7
      001CA3 12 2C 15         [24] 5639 	lcall	___fsadd
      001CA6 A8 10            [24] 5640 	mov	r0,_bp
      001CA8 08               [12] 5641 	inc	r0
      001CA9 A6 82            [24] 5642 	mov	@r0, dpl
      001CAB 08               [12] 5643 	inc	r0
      001CAC A6 83            [24] 5644 	mov	@r0, dph
      001CAE 08               [12] 5645 	inc	r0
      001CAF A6 F0            [24] 5646 	mov	@r0, b
      001CB1 08               [12] 5647 	inc	r0
      001CB2 F6               [12] 5648 	mov	@r0,a
      001CB3 E5 81            [12] 5649 	mov	a,sp
      001CB5 24 FC            [12] 5650 	add	a,#0xfc
      001CB7 F5 81            [12] 5651 	mov	sp,a
      001CB9 E5 10            [12] 5652 	mov	a,_bp
      001CBB 24 FA            [12] 5653 	add	a,#0xfa
      001CBD F8               [12] 5654 	mov	r0,a
      001CBE E6               [12] 5655 	mov	a,@r0
      001CBF C0 E0            [24] 5656 	push	acc
      001CC1 08               [12] 5657 	inc	r0
      001CC2 E6               [12] 5658 	mov	a,@r0
      001CC3 C0 E0            [24] 5659 	push	acc
      001CC5 08               [12] 5660 	inc	r0
      001CC6 E6               [12] 5661 	mov	a,@r0
      001CC7 C0 E0            [24] 5662 	push	acc
      001CC9 08               [12] 5663 	inc	r0
      001CCA E6               [12] 5664 	mov	a,@r0
      001CCB C0 E0            [24] 5665 	push	acc
      001CCD 90 51 EC         [24] 5666 	mov	dptr,#0x51ec
      001CD0 75 F0 38         [24] 5667 	mov	b, #0x38
      001CD3 74 3E            [12] 5668 	mov	a, #0x3e
      001CD5 12 2A B5         [24] 5669 	lcall	___fsmul
      001CD8 AA 82            [24] 5670 	mov	r2, dpl
      001CDA AB 83            [24] 5671 	mov	r3, dph
      001CDC AE F0            [24] 5672 	mov	r6, b
      001CDE FF               [12] 5673 	mov	r7, a
      001CDF E5 81            [12] 5674 	mov	a,sp
      001CE1 24 FC            [12] 5675 	add	a,#0xfc
      001CE3 F5 81            [12] 5676 	mov	sp,a
      001CE5 C0 02            [24] 5677 	push	ar2
      001CE7 C0 03            [24] 5678 	push	ar3
      001CE9 C0 06            [24] 5679 	push	ar6
      001CEB C0 07            [24] 5680 	push	ar7
      001CED A8 10            [24] 5681 	mov	r0,_bp
      001CEF 08               [12] 5682 	inc	r0
      001CF0 86 82            [24] 5683 	mov	dpl, @r0
      001CF2 08               [12] 5684 	inc	r0
      001CF3 86 83            [24] 5685 	mov	dph, @r0
      001CF5 08               [12] 5686 	inc	r0
      001CF6 86 F0            [24] 5687 	mov	b, @r0
      001CF8 08               [12] 5688 	inc	r0
      001CF9 E6               [12] 5689 	mov	a, @r0
      001CFA 12 2C 15         [24] 5690 	lcall	___fsadd
      001CFD A8 10            [24] 5691 	mov	r0,_bp
      001CFF 08               [12] 5692 	inc	r0
      001D00 A6 82            [24] 5693 	mov	@r0, dpl
      001D02 08               [12] 5694 	inc	r0
      001D03 A6 83            [24] 5695 	mov	@r0, dph
      001D05 08               [12] 5696 	inc	r0
      001D06 A6 F0            [24] 5697 	mov	@r0, b
      001D08 08               [12] 5698 	inc	r0
      001D09 F6               [12] 5699 	mov	@r0,a
      001D0A E5 81            [12] 5700 	mov	a,sp
      001D0C 24 FC            [12] 5701 	add	a,#0xfc
      001D0E F5 81            [12] 5702 	mov	sp,a
      001D10 E5 10            [12] 5703 	mov	a,_bp
      001D12 24 F6            [12] 5704 	add	a,#0xf6
      001D14 F8               [12] 5705 	mov	r0,a
      001D15 E6               [12] 5706 	mov	a,@r0
      001D16 C0 E0            [24] 5707 	push	acc
      001D18 08               [12] 5708 	inc	r0
      001D19 E6               [12] 5709 	mov	a,@r0
      001D1A C0 E0            [24] 5710 	push	acc
      001D1C 08               [12] 5711 	inc	r0
      001D1D E6               [12] 5712 	mov	a,@r0
      001D1E C0 E0            [24] 5713 	push	acc
      001D20 08               [12] 5714 	inc	r0
      001D21 E6               [12] 5715 	mov	a,@r0
      001D22 C0 E0            [24] 5716 	push	acc
      001D24 90 CC CD         [24] 5717 	mov	dptr,#0xcccd
      001D27 75 F0 4C         [24] 5718 	mov	b, #0x4c
      001D2A 74 3F            [12] 5719 	mov	a, #0x3f
      001D2C 12 2A B5         [24] 5720 	lcall	___fsmul
      001D2F AA 82            [24] 5721 	mov	r2, dpl
      001D31 AB 83            [24] 5722 	mov	r3, dph
      001D33 AE F0            [24] 5723 	mov	r6, b
      001D35 FF               [12] 5724 	mov	r7, a
      001D36 E5 81            [12] 5725 	mov	a,sp
      001D38 24 FC            [12] 5726 	add	a,#0xfc
      001D3A F5 81            [12] 5727 	mov	sp,a
      001D3C C0 02            [24] 5728 	push	ar2
      001D3E C0 03            [24] 5729 	push	ar3
      001D40 C0 06            [24] 5730 	push	ar6
      001D42 C0 07            [24] 5731 	push	ar7
      001D44 A8 10            [24] 5732 	mov	r0,_bp
      001D46 08               [12] 5733 	inc	r0
      001D47 86 82            [24] 5734 	mov	dpl, @r0
      001D49 08               [12] 5735 	inc	r0
      001D4A 86 83            [24] 5736 	mov	dph, @r0
      001D4C 08               [12] 5737 	inc	r0
      001D4D 86 F0            [24] 5738 	mov	b, @r0
      001D4F 08               [12] 5739 	inc	r0
      001D50 E6               [12] 5740 	mov	a, @r0
      001D51 12 2C 15         [24] 5741 	lcall	___fsadd
      001D54 AC 82            [24] 5742 	mov	r4, dpl
      001D56 AD 83            [24] 5743 	mov	r5, dph
      001D58 AE F0            [24] 5744 	mov	r6, b
      001D5A FF               [12] 5745 	mov	r7, a
      001D5B E5 81            [12] 5746 	mov	a,sp
      001D5D 24 FC            [12] 5747 	add	a,#0xfc
      001D5F F5 81            [12] 5748 	mov	sp,a
      001D61 8C 82            [24] 5749 	mov	dpl, r4
      001D63 8D 83            [24] 5750 	mov	dph, r5
      001D65 8E F0            [24] 5751 	mov	b, r6
      001D67 EF               [12] 5752 	mov	a, r7
      001D68 85 10 81         [24] 5753 	mov	sp,_bp
      001D6B D0 10            [24] 5754 	pop	_bp
                           001CB0  5755 	C$sugeno_demo.c$37$1_0$115 ==.
                           001CB0  5756 	XFsugeno_demo$response_economy$0$0 ==.
      001D6D 22               [24] 5757 	ret
                                   5758 ;------------------------------------------------------------
                                   5759 ;Allocation info for local variables in function 'response_balanced'
                                   5760 ;------------------------------------------------------------
                                   5761 ;load          Allocated to stack - _bp -6 +4 
                                   5762 ;vibration     Allocated to stack - _bp -10 +4 
                                   5763 ;temperature   Allocated to registers r4 r5 r6 r7 
                                   5764 ;sloc0         Allocated to stack - _bp +1 +4 
                                   5765 ;------------------------------------------------------------
                           001CB1  5766 	Fsugeno_demo$response_balanced$0$0 ==.
                           001CB1  5767 	C$sugeno_demo.c$38$1_0$117 ==.
                                   5768 ;	../../sugeno_demo.c:38: static float response_balanced(float temperature, float load, float vibration) { return 15.0f + 0.42f * temperature + 0.25f * load + 1.20f * vibration; }
                                   5769 ;	-----------------------------------------
                                   5770 ;	 function response_balanced
                                   5771 ;	-----------------------------------------
      001D6E                       5772 _response_balanced:
      001D6E C0 10            [24] 5773 	push	_bp
      001D70 85 81 10         [24] 5774 	mov	_bp,sp
      001D73 AC 82            [24] 5775 	mov	r4,dpl
      001D75 AD 83            [24] 5776 	mov	r5,dph
      001D77 AE F0            [24] 5777 	mov	r6,b
      001D79 FF               [12] 5778 	mov	r7,a
      001D7A E5 81            [12] 5779 	mov	a,sp
      001D7C 24 04            [12] 5780 	add	a,#0x04
      001D7E F5 81            [12] 5781 	mov	sp,a
      001D80 C0 04            [24] 5782 	push	ar4
      001D82 C0 05            [24] 5783 	push	ar5
      001D84 C0 06            [24] 5784 	push	ar6
      001D86 C0 07            [24] 5785 	push	ar7
      001D88 90 0A 3D         [24] 5786 	mov	dptr,#0x0a3d
      001D8B 75 F0 D7         [24] 5787 	mov	b, #0xd7
      001D8E 74 3E            [12] 5788 	mov	a, #0x3e
      001D90 12 2A B5         [24] 5789 	lcall	___fsmul
      001D93 AC 82            [24] 5790 	mov	r4, dpl
      001D95 AD 83            [24] 5791 	mov	r5, dph
      001D97 AE F0            [24] 5792 	mov	r6, b
      001D99 FF               [12] 5793 	mov	r7, a
      001D9A E5 81            [12] 5794 	mov	a,sp
      001D9C 24 FC            [12] 5795 	add	a,#0xfc
      001D9E F5 81            [12] 5796 	mov	sp,a
      001DA0 E4               [12] 5797 	clr	a
      001DA1 C0 E0            [24] 5798 	push	acc
      001DA3 C0 E0            [24] 5799 	push	acc
      001DA5 74 70            [12] 5800 	mov	a,#0x70
      001DA7 C0 E0            [24] 5801 	push	acc
      001DA9 74 41            [12] 5802 	mov	a,#0x41
      001DAB C0 E0            [24] 5803 	push	acc
      001DAD 8C 82            [24] 5804 	mov	dpl, r4
      001DAF 8D 83            [24] 5805 	mov	dph, r5
      001DB1 8E F0            [24] 5806 	mov	b, r6
      001DB3 EF               [12] 5807 	mov	a, r7
      001DB4 12 2C 15         [24] 5808 	lcall	___fsadd
      001DB7 A8 10            [24] 5809 	mov	r0,_bp
      001DB9 08               [12] 5810 	inc	r0
      001DBA A6 82            [24] 5811 	mov	@r0, dpl
      001DBC 08               [12] 5812 	inc	r0
      001DBD A6 83            [24] 5813 	mov	@r0, dph
      001DBF 08               [12] 5814 	inc	r0
      001DC0 A6 F0            [24] 5815 	mov	@r0, b
      001DC2 08               [12] 5816 	inc	r0
      001DC3 F6               [12] 5817 	mov	@r0,a
      001DC4 E5 81            [12] 5818 	mov	a,sp
      001DC6 24 FC            [12] 5819 	add	a,#0xfc
      001DC8 F5 81            [12] 5820 	mov	sp,a
      001DCA E5 10            [12] 5821 	mov	a,_bp
      001DCC 24 FA            [12] 5822 	add	a,#0xfa
      001DCE F8               [12] 5823 	mov	r0,a
      001DCF E6               [12] 5824 	mov	a,@r0
      001DD0 C0 E0            [24] 5825 	push	acc
      001DD2 08               [12] 5826 	inc	r0
      001DD3 E6               [12] 5827 	mov	a,@r0
      001DD4 C0 E0            [24] 5828 	push	acc
      001DD6 08               [12] 5829 	inc	r0
      001DD7 E6               [12] 5830 	mov	a,@r0
      001DD8 C0 E0            [24] 5831 	push	acc
      001DDA 08               [12] 5832 	inc	r0
      001DDB E6               [12] 5833 	mov	a,@r0
      001DDC C0 E0            [24] 5834 	push	acc
      001DDE 90 00 00         [24] 5835 	mov	dptr,#0x0000
      001DE1 75 F0 80         [24] 5836 	mov	b, #0x80
      001DE4 74 3E            [12] 5837 	mov	a, #0x3e
      001DE6 12 2A B5         [24] 5838 	lcall	___fsmul
      001DE9 AA 82            [24] 5839 	mov	r2, dpl
      001DEB AB 83            [24] 5840 	mov	r3, dph
      001DED AE F0            [24] 5841 	mov	r6, b
      001DEF FF               [12] 5842 	mov	r7, a
      001DF0 E5 81            [12] 5843 	mov	a,sp
      001DF2 24 FC            [12] 5844 	add	a,#0xfc
      001DF4 F5 81            [12] 5845 	mov	sp,a
      001DF6 C0 02            [24] 5846 	push	ar2
      001DF8 C0 03            [24] 5847 	push	ar3
      001DFA C0 06            [24] 5848 	push	ar6
      001DFC C0 07            [24] 5849 	push	ar7
      001DFE A8 10            [24] 5850 	mov	r0,_bp
      001E00 08               [12] 5851 	inc	r0
      001E01 86 82            [24] 5852 	mov	dpl, @r0
      001E03 08               [12] 5853 	inc	r0
      001E04 86 83            [24] 5854 	mov	dph, @r0
      001E06 08               [12] 5855 	inc	r0
      001E07 86 F0            [24] 5856 	mov	b, @r0
      001E09 08               [12] 5857 	inc	r0
      001E0A E6               [12] 5858 	mov	a, @r0
      001E0B 12 2C 15         [24] 5859 	lcall	___fsadd
      001E0E A8 10            [24] 5860 	mov	r0,_bp
      001E10 08               [12] 5861 	inc	r0
      001E11 A6 82            [24] 5862 	mov	@r0, dpl
      001E13 08               [12] 5863 	inc	r0
      001E14 A6 83            [24] 5864 	mov	@r0, dph
      001E16 08               [12] 5865 	inc	r0
      001E17 A6 F0            [24] 5866 	mov	@r0, b
      001E19 08               [12] 5867 	inc	r0
      001E1A F6               [12] 5868 	mov	@r0,a
      001E1B E5 81            [12] 5869 	mov	a,sp
      001E1D 24 FC            [12] 5870 	add	a,#0xfc
      001E1F F5 81            [12] 5871 	mov	sp,a
      001E21 E5 10            [12] 5872 	mov	a,_bp
      001E23 24 F6            [12] 5873 	add	a,#0xf6
      001E25 F8               [12] 5874 	mov	r0,a
      001E26 E6               [12] 5875 	mov	a,@r0
      001E27 C0 E0            [24] 5876 	push	acc
      001E29 08               [12] 5877 	inc	r0
      001E2A E6               [12] 5878 	mov	a,@r0
      001E2B C0 E0            [24] 5879 	push	acc
      001E2D 08               [12] 5880 	inc	r0
      001E2E E6               [12] 5881 	mov	a,@r0
      001E2F C0 E0            [24] 5882 	push	acc
      001E31 08               [12] 5883 	inc	r0
      001E32 E6               [12] 5884 	mov	a,@r0
      001E33 C0 E0            [24] 5885 	push	acc
      001E35 90 99 9A         [24] 5886 	mov	dptr,#0x999a
      001E38 75 F0 99         [24] 5887 	mov	b, #0x99
      001E3B 74 3F            [12] 5888 	mov	a, #0x3f
      001E3D 12 2A B5         [24] 5889 	lcall	___fsmul
      001E40 AA 82            [24] 5890 	mov	r2, dpl
      001E42 AB 83            [24] 5891 	mov	r3, dph
      001E44 AE F0            [24] 5892 	mov	r6, b
      001E46 FF               [12] 5893 	mov	r7, a
      001E47 E5 81            [12] 5894 	mov	a,sp
      001E49 24 FC            [12] 5895 	add	a,#0xfc
      001E4B F5 81            [12] 5896 	mov	sp,a
      001E4D C0 02            [24] 5897 	push	ar2
      001E4F C0 03            [24] 5898 	push	ar3
      001E51 C0 06            [24] 5899 	push	ar6
      001E53 C0 07            [24] 5900 	push	ar7
      001E55 A8 10            [24] 5901 	mov	r0,_bp
      001E57 08               [12] 5902 	inc	r0
      001E58 86 82            [24] 5903 	mov	dpl, @r0
      001E5A 08               [12] 5904 	inc	r0
      001E5B 86 83            [24] 5905 	mov	dph, @r0
      001E5D 08               [12] 5906 	inc	r0
      001E5E 86 F0            [24] 5907 	mov	b, @r0
      001E60 08               [12] 5908 	inc	r0
      001E61 E6               [12] 5909 	mov	a, @r0
      001E62 12 2C 15         [24] 5910 	lcall	___fsadd
      001E65 AC 82            [24] 5911 	mov	r4, dpl
      001E67 AD 83            [24] 5912 	mov	r5, dph
      001E69 AE F0            [24] 5913 	mov	r6, b
      001E6B FF               [12] 5914 	mov	r7, a
      001E6C E5 81            [12] 5915 	mov	a,sp
      001E6E 24 FC            [12] 5916 	add	a,#0xfc
      001E70 F5 81            [12] 5917 	mov	sp,a
      001E72 8C 82            [24] 5918 	mov	dpl, r4
      001E74 8D 83            [24] 5919 	mov	dph, r5
      001E76 8E F0            [24] 5920 	mov	b, r6
      001E78 EF               [12] 5921 	mov	a, r7
      001E79 85 10 81         [24] 5922 	mov	sp,_bp
      001E7C D0 10            [24] 5923 	pop	_bp
                           001DC1  5924 	C$sugeno_demo.c$38$1_0$117 ==.
                           001DC1  5925 	XFsugeno_demo$response_balanced$0$0 ==.
      001E7E 22               [24] 5926 	ret
                                   5927 ;------------------------------------------------------------
                                   5928 ;Allocation info for local variables in function 'response_cooling'
                                   5929 ;------------------------------------------------------------
                                   5930 ;load          Allocated to stack - _bp -6 +4 
                                   5931 ;vibration     Allocated to stack - _bp -10 +4 
                                   5932 ;temperature   Allocated to registers r4 r5 r6 r7 
                                   5933 ;sloc0         Allocated to stack - _bp +1 +4 
                                   5934 ;------------------------------------------------------------
                           001DC2  5935 	Fsugeno_demo$response_cooling$0$0 ==.
                           001DC2  5936 	C$sugeno_demo.c$39$1_0$119 ==.
                                   5937 ;	../../sugeno_demo.c:39: static float response_cooling(float temperature, float load, float vibration) { return 20.0f + 0.65f * temperature + 0.12f * load + 1.50f * vibration; }
                                   5938 ;	-----------------------------------------
                                   5939 ;	 function response_cooling
                                   5940 ;	-----------------------------------------
      001E7F                       5941 _response_cooling:
      001E7F C0 10            [24] 5942 	push	_bp
      001E81 85 81 10         [24] 5943 	mov	_bp,sp
      001E84 AC 82            [24] 5944 	mov	r4,dpl
      001E86 AD 83            [24] 5945 	mov	r5,dph
      001E88 AE F0            [24] 5946 	mov	r6,b
      001E8A FF               [12] 5947 	mov	r7,a
      001E8B E5 81            [12] 5948 	mov	a,sp
      001E8D 24 04            [12] 5949 	add	a,#0x04
      001E8F F5 81            [12] 5950 	mov	sp,a
      001E91 C0 04            [24] 5951 	push	ar4
      001E93 C0 05            [24] 5952 	push	ar5
      001E95 C0 06            [24] 5953 	push	ar6
      001E97 C0 07            [24] 5954 	push	ar7
      001E99 90 66 66         [24] 5955 	mov	dptr,#0x6666
      001E9C 75 F0 26         [24] 5956 	mov	b, #0x26
      001E9F 74 3F            [12] 5957 	mov	a, #0x3f
      001EA1 12 2A B5         [24] 5958 	lcall	___fsmul
      001EA4 AC 82            [24] 5959 	mov	r4, dpl
      001EA6 AD 83            [24] 5960 	mov	r5, dph
      001EA8 AE F0            [24] 5961 	mov	r6, b
      001EAA FF               [12] 5962 	mov	r7, a
      001EAB E5 81            [12] 5963 	mov	a,sp
      001EAD 24 FC            [12] 5964 	add	a,#0xfc
      001EAF F5 81            [12] 5965 	mov	sp,a
      001EB1 E4               [12] 5966 	clr	a
      001EB2 C0 E0            [24] 5967 	push	acc
      001EB4 C0 E0            [24] 5968 	push	acc
      001EB6 74 A0            [12] 5969 	mov	a,#0xa0
      001EB8 C0 E0            [24] 5970 	push	acc
      001EBA 23               [12] 5971 	rl	a
      001EBB C0 E0            [24] 5972 	push	acc
      001EBD 8C 82            [24] 5973 	mov	dpl, r4
      001EBF 8D 83            [24] 5974 	mov	dph, r5
      001EC1 8E F0            [24] 5975 	mov	b, r6
      001EC3 EF               [12] 5976 	mov	a, r7
      001EC4 12 2C 15         [24] 5977 	lcall	___fsadd
      001EC7 A8 10            [24] 5978 	mov	r0,_bp
      001EC9 08               [12] 5979 	inc	r0
      001ECA A6 82            [24] 5980 	mov	@r0, dpl
      001ECC 08               [12] 5981 	inc	r0
      001ECD A6 83            [24] 5982 	mov	@r0, dph
      001ECF 08               [12] 5983 	inc	r0
      001ED0 A6 F0            [24] 5984 	mov	@r0, b
      001ED2 08               [12] 5985 	inc	r0
      001ED3 F6               [12] 5986 	mov	@r0,a
      001ED4 E5 81            [12] 5987 	mov	a,sp
      001ED6 24 FC            [12] 5988 	add	a,#0xfc
      001ED8 F5 81            [12] 5989 	mov	sp,a
      001EDA E5 10            [12] 5990 	mov	a,_bp
      001EDC 24 FA            [12] 5991 	add	a,#0xfa
      001EDE F8               [12] 5992 	mov	r0,a
      001EDF E6               [12] 5993 	mov	a,@r0
      001EE0 C0 E0            [24] 5994 	push	acc
      001EE2 08               [12] 5995 	inc	r0
      001EE3 E6               [12] 5996 	mov	a,@r0
      001EE4 C0 E0            [24] 5997 	push	acc
      001EE6 08               [12] 5998 	inc	r0
      001EE7 E6               [12] 5999 	mov	a,@r0
      001EE8 C0 E0            [24] 6000 	push	acc
      001EEA 08               [12] 6001 	inc	r0
      001EEB E6               [12] 6002 	mov	a,@r0
      001EEC C0 E0            [24] 6003 	push	acc
      001EEE 90 C2 8F         [24] 6004 	mov	dptr,#0xc28f
      001EF1 75 F0 F5         [24] 6005 	mov	b, #0xf5
      001EF4 74 3D            [12] 6006 	mov	a, #0x3d
      001EF6 12 2A B5         [24] 6007 	lcall	___fsmul
      001EF9 AA 82            [24] 6008 	mov	r2, dpl
      001EFB AB 83            [24] 6009 	mov	r3, dph
      001EFD AE F0            [24] 6010 	mov	r6, b
      001EFF FF               [12] 6011 	mov	r7, a
      001F00 E5 81            [12] 6012 	mov	a,sp
      001F02 24 FC            [12] 6013 	add	a,#0xfc
      001F04 F5 81            [12] 6014 	mov	sp,a
      001F06 C0 02            [24] 6015 	push	ar2
      001F08 C0 03            [24] 6016 	push	ar3
      001F0A C0 06            [24] 6017 	push	ar6
      001F0C C0 07            [24] 6018 	push	ar7
      001F0E A8 10            [24] 6019 	mov	r0,_bp
      001F10 08               [12] 6020 	inc	r0
      001F11 86 82            [24] 6021 	mov	dpl, @r0
      001F13 08               [12] 6022 	inc	r0
      001F14 86 83            [24] 6023 	mov	dph, @r0
      001F16 08               [12] 6024 	inc	r0
      001F17 86 F0            [24] 6025 	mov	b, @r0
      001F19 08               [12] 6026 	inc	r0
      001F1A E6               [12] 6027 	mov	a, @r0
      001F1B 12 2C 15         [24] 6028 	lcall	___fsadd
      001F1E A8 10            [24] 6029 	mov	r0,_bp
      001F20 08               [12] 6030 	inc	r0
      001F21 A6 82            [24] 6031 	mov	@r0, dpl
      001F23 08               [12] 6032 	inc	r0
      001F24 A6 83            [24] 6033 	mov	@r0, dph
      001F26 08               [12] 6034 	inc	r0
      001F27 A6 F0            [24] 6035 	mov	@r0, b
      001F29 08               [12] 6036 	inc	r0
      001F2A F6               [12] 6037 	mov	@r0,a
      001F2B E5 81            [12] 6038 	mov	a,sp
      001F2D 24 FC            [12] 6039 	add	a,#0xfc
      001F2F F5 81            [12] 6040 	mov	sp,a
      001F31 E5 10            [12] 6041 	mov	a,_bp
      001F33 24 F6            [12] 6042 	add	a,#0xf6
      001F35 F8               [12] 6043 	mov	r0,a
      001F36 E6               [12] 6044 	mov	a,@r0
      001F37 C0 E0            [24] 6045 	push	acc
      001F39 08               [12] 6046 	inc	r0
      001F3A E6               [12] 6047 	mov	a,@r0
      001F3B C0 E0            [24] 6048 	push	acc
      001F3D 08               [12] 6049 	inc	r0
      001F3E E6               [12] 6050 	mov	a,@r0
      001F3F C0 E0            [24] 6051 	push	acc
      001F41 08               [12] 6052 	inc	r0
      001F42 E6               [12] 6053 	mov	a,@r0
      001F43 C0 E0            [24] 6054 	push	acc
      001F45 90 00 00         [24] 6055 	mov	dptr,#0x0000
      001F48 75 F0 C0         [24] 6056 	mov	b, #0xc0
      001F4B 74 3F            [12] 6057 	mov	a, #0x3f
      001F4D 12 2A B5         [24] 6058 	lcall	___fsmul
      001F50 AA 82            [24] 6059 	mov	r2, dpl
      001F52 AB 83            [24] 6060 	mov	r3, dph
      001F54 AE F0            [24] 6061 	mov	r6, b
      001F56 FF               [12] 6062 	mov	r7, a
      001F57 E5 81            [12] 6063 	mov	a,sp
      001F59 24 FC            [12] 6064 	add	a,#0xfc
      001F5B F5 81            [12] 6065 	mov	sp,a
      001F5D C0 02            [24] 6066 	push	ar2
      001F5F C0 03            [24] 6067 	push	ar3
      001F61 C0 06            [24] 6068 	push	ar6
      001F63 C0 07            [24] 6069 	push	ar7
      001F65 A8 10            [24] 6070 	mov	r0,_bp
      001F67 08               [12] 6071 	inc	r0
      001F68 86 82            [24] 6072 	mov	dpl, @r0
      001F6A 08               [12] 6073 	inc	r0
      001F6B 86 83            [24] 6074 	mov	dph, @r0
      001F6D 08               [12] 6075 	inc	r0
      001F6E 86 F0            [24] 6076 	mov	b, @r0
      001F70 08               [12] 6077 	inc	r0
      001F71 E6               [12] 6078 	mov	a, @r0
      001F72 12 2C 15         [24] 6079 	lcall	___fsadd
      001F75 AC 82            [24] 6080 	mov	r4, dpl
      001F77 AD 83            [24] 6081 	mov	r5, dph
      001F79 AE F0            [24] 6082 	mov	r6, b
      001F7B FF               [12] 6083 	mov	r7, a
      001F7C E5 81            [12] 6084 	mov	a,sp
      001F7E 24 FC            [12] 6085 	add	a,#0xfc
      001F80 F5 81            [12] 6086 	mov	sp,a
      001F82 8C 82            [24] 6087 	mov	dpl, r4
      001F84 8D 83            [24] 6088 	mov	dph, r5
      001F86 8E F0            [24] 6089 	mov	b, r6
      001F88 EF               [12] 6090 	mov	a, r7
      001F89 85 10 81         [24] 6091 	mov	sp,_bp
      001F8C D0 10            [24] 6092 	pop	_bp
                           001ED1  6093 	C$sugeno_demo.c$39$1_0$119 ==.
                           001ED1  6094 	XFsugeno_demo$response_cooling$0$0 ==.
      001F8E 22               [24] 6095 	ret
                                   6096 ;------------------------------------------------------------
                                   6097 ;Allocation info for local variables in function 'response_heavy_load'
                                   6098 ;------------------------------------------------------------
                                   6099 ;load          Allocated to stack - _bp -6 +4 
                                   6100 ;vibration     Allocated to stack - _bp -10 +4 
                                   6101 ;temperature   Allocated to registers r4 r5 r6 r7 
                                   6102 ;sloc0         Allocated to stack - _bp +1 +4 
                                   6103 ;------------------------------------------------------------
                           001ED2  6104 	Fsugeno_demo$response_heavy_load$0$0 ==.
                           001ED2  6105 	C$sugeno_demo.c$40$1_0$121 ==.
                                   6106 ;	../../sugeno_demo.c:40: static float response_heavy_load(float temperature, float load, float vibration) { return 18.0f + 0.30f * temperature + 0.55f * load + 1.00f * vibration; }
                                   6107 ;	-----------------------------------------
                                   6108 ;	 function response_heavy_load
                                   6109 ;	-----------------------------------------
      001F8F                       6110 _response_heavy_load:
      001F8F C0 10            [24] 6111 	push	_bp
      001F91 85 81 10         [24] 6112 	mov	_bp,sp
      001F94 AC 82            [24] 6113 	mov	r4,dpl
      001F96 AD 83            [24] 6114 	mov	r5,dph
      001F98 AE F0            [24] 6115 	mov	r6,b
      001F9A FF               [12] 6116 	mov	r7,a
      001F9B E5 81            [12] 6117 	mov	a,sp
      001F9D 24 04            [12] 6118 	add	a,#0x04
      001F9F F5 81            [12] 6119 	mov	sp,a
      001FA1 C0 04            [24] 6120 	push	ar4
      001FA3 C0 05            [24] 6121 	push	ar5
      001FA5 C0 06            [24] 6122 	push	ar6
      001FA7 C0 07            [24] 6123 	push	ar7
      001FA9 90 99 9A         [24] 6124 	mov	dptr,#0x999a
      001FAC 75 F0 99         [24] 6125 	mov	b, #0x99
      001FAF 74 3E            [12] 6126 	mov	a, #0x3e
      001FB1 12 2A B5         [24] 6127 	lcall	___fsmul
      001FB4 AC 82            [24] 6128 	mov	r4, dpl
      001FB6 AD 83            [24] 6129 	mov	r5, dph
      001FB8 AE F0            [24] 6130 	mov	r6, b
      001FBA FF               [12] 6131 	mov	r7, a
      001FBB E5 81            [12] 6132 	mov	a,sp
      001FBD 24 FC            [12] 6133 	add	a,#0xfc
      001FBF F5 81            [12] 6134 	mov	sp,a
      001FC1 E4               [12] 6135 	clr	a
      001FC2 C0 E0            [24] 6136 	push	acc
      001FC4 C0 E0            [24] 6137 	push	acc
      001FC6 74 90            [12] 6138 	mov	a,#0x90
      001FC8 C0 E0            [24] 6139 	push	acc
      001FCA 74 41            [12] 6140 	mov	a,#0x41
      001FCC C0 E0            [24] 6141 	push	acc
      001FCE 8C 82            [24] 6142 	mov	dpl, r4
      001FD0 8D 83            [24] 6143 	mov	dph, r5
      001FD2 8E F0            [24] 6144 	mov	b, r6
      001FD4 EF               [12] 6145 	mov	a, r7
      001FD5 12 2C 15         [24] 6146 	lcall	___fsadd
      001FD8 A8 10            [24] 6147 	mov	r0,_bp
      001FDA 08               [12] 6148 	inc	r0
      001FDB A6 82            [24] 6149 	mov	@r0, dpl
      001FDD 08               [12] 6150 	inc	r0
      001FDE A6 83            [24] 6151 	mov	@r0, dph
      001FE0 08               [12] 6152 	inc	r0
      001FE1 A6 F0            [24] 6153 	mov	@r0, b
      001FE3 08               [12] 6154 	inc	r0
      001FE4 F6               [12] 6155 	mov	@r0,a
      001FE5 E5 81            [12] 6156 	mov	a,sp
      001FE7 24 FC            [12] 6157 	add	a,#0xfc
      001FE9 F5 81            [12] 6158 	mov	sp,a
      001FEB E5 10            [12] 6159 	mov	a,_bp
      001FED 24 FA            [12] 6160 	add	a,#0xfa
      001FEF F8               [12] 6161 	mov	r0,a
      001FF0 E6               [12] 6162 	mov	a,@r0
      001FF1 C0 E0            [24] 6163 	push	acc
      001FF3 08               [12] 6164 	inc	r0
      001FF4 E6               [12] 6165 	mov	a,@r0
      001FF5 C0 E0            [24] 6166 	push	acc
      001FF7 08               [12] 6167 	inc	r0
      001FF8 E6               [12] 6168 	mov	a,@r0
      001FF9 C0 E0            [24] 6169 	push	acc
      001FFB 08               [12] 6170 	inc	r0
      001FFC E6               [12] 6171 	mov	a,@r0
      001FFD C0 E0            [24] 6172 	push	acc
      001FFF 90 CC CD         [24] 6173 	mov	dptr,#0xcccd
      002002 75 F0 0C         [24] 6174 	mov	b, #0x0c
      002005 74 3F            [12] 6175 	mov	a, #0x3f
      002007 12 2A B5         [24] 6176 	lcall	___fsmul
      00200A AA 82            [24] 6177 	mov	r2, dpl
      00200C AB 83            [24] 6178 	mov	r3, dph
      00200E AE F0            [24] 6179 	mov	r6, b
      002010 FF               [12] 6180 	mov	r7, a
      002011 E5 81            [12] 6181 	mov	a,sp
      002013 24 FC            [12] 6182 	add	a,#0xfc
      002015 F5 81            [12] 6183 	mov	sp,a
      002017 C0 02            [24] 6184 	push	ar2
      002019 C0 03            [24] 6185 	push	ar3
      00201B C0 06            [24] 6186 	push	ar6
      00201D C0 07            [24] 6187 	push	ar7
      00201F A8 10            [24] 6188 	mov	r0,_bp
      002021 08               [12] 6189 	inc	r0
      002022 86 82            [24] 6190 	mov	dpl, @r0
      002024 08               [12] 6191 	inc	r0
      002025 86 83            [24] 6192 	mov	dph, @r0
      002027 08               [12] 6193 	inc	r0
      002028 86 F0            [24] 6194 	mov	b, @r0
      00202A 08               [12] 6195 	inc	r0
      00202B E6               [12] 6196 	mov	a, @r0
      00202C 12 2C 15         [24] 6197 	lcall	___fsadd
      00202F AC 82            [24] 6198 	mov	r4, dpl
      002031 AD 83            [24] 6199 	mov	r5, dph
      002033 AE F0            [24] 6200 	mov	r6, b
      002035 FF               [12] 6201 	mov	r7, a
      002036 E5 81            [12] 6202 	mov	a,sp
      002038 24 FC            [12] 6203 	add	a,#0xfc
      00203A F5 81            [12] 6204 	mov	sp,a
      00203C E5 10            [12] 6205 	mov	a,_bp
      00203E 24 F6            [12] 6206 	add	a,#0xf6
      002040 F8               [12] 6207 	mov	r0,a
      002041 E6               [12] 6208 	mov	a,@r0
      002042 C0 E0            [24] 6209 	push	acc
      002044 08               [12] 6210 	inc	r0
      002045 E6               [12] 6211 	mov	a,@r0
      002046 C0 E0            [24] 6212 	push	acc
      002048 08               [12] 6213 	inc	r0
      002049 E6               [12] 6214 	mov	a,@r0
      00204A C0 E0            [24] 6215 	push	acc
      00204C 08               [12] 6216 	inc	r0
      00204D E6               [12] 6217 	mov	a,@r0
      00204E C0 E0            [24] 6218 	push	acc
      002050 8C 82            [24] 6219 	mov	dpl, r4
      002052 8D 83            [24] 6220 	mov	dph, r5
      002054 8E F0            [24] 6221 	mov	b, r6
      002056 EF               [12] 6222 	mov	a, r7
      002057 12 2C 15         [24] 6223 	lcall	___fsadd
      00205A AC 82            [24] 6224 	mov	r4, dpl
      00205C AD 83            [24] 6225 	mov	r5, dph
      00205E AE F0            [24] 6226 	mov	r6, b
      002060 FF               [12] 6227 	mov	r7, a
      002061 E5 81            [12] 6228 	mov	a,sp
      002063 24 FC            [12] 6229 	add	a,#0xfc
      002065 F5 81            [12] 6230 	mov	sp,a
      002067 8C 82            [24] 6231 	mov	dpl, r4
      002069 8D 83            [24] 6232 	mov	dph, r5
      00206B 8E F0            [24] 6233 	mov	b, r6
      00206D EF               [12] 6234 	mov	a, r7
      00206E 85 10 81         [24] 6235 	mov	sp,_bp
      002071 D0 10            [24] 6236 	pop	_bp
                           001FB6  6237 	C$sugeno_demo.c$40$1_0$121 ==.
                           001FB6  6238 	XFsugeno_demo$response_heavy_load$0$0 ==.
      002073 22               [24] 6239 	ret
                                   6240 ;------------------------------------------------------------
                                   6241 ;Allocation info for local variables in function 'response_protection'
                                   6242 ;------------------------------------------------------------
                                   6243 ;load          Allocated to stack - _bp -6 +4 
                                   6244 ;vibration     Allocated to stack - _bp -10 +4 
                                   6245 ;temperature   Allocated to registers r4 r5 r6 r7 
                                   6246 ;sloc0         Allocated to stack - _bp +1 +4 
                                   6247 ;------------------------------------------------------------
                           001FB7  6248 	Fsugeno_demo$response_protection$0$0 ==.
                           001FB7  6249 	C$sugeno_demo.c$41$1_0$123 ==.
                                   6250 ;	../../sugeno_demo.c:41: static float response_protection(float temperature, float load, float vibration) { return 35.0f + 0.45f * temperature + 0.30f * load + 2.50f * vibration; }
                                   6251 ;	-----------------------------------------
                                   6252 ;	 function response_protection
                                   6253 ;	-----------------------------------------
      002074                       6254 _response_protection:
      002074 C0 10            [24] 6255 	push	_bp
      002076 85 81 10         [24] 6256 	mov	_bp,sp
      002079 AC 82            [24] 6257 	mov	r4,dpl
      00207B AD 83            [24] 6258 	mov	r5,dph
      00207D AE F0            [24] 6259 	mov	r6,b
      00207F FF               [12] 6260 	mov	r7,a
      002080 E5 81            [12] 6261 	mov	a,sp
      002082 24 04            [12] 6262 	add	a,#0x04
      002084 F5 81            [12] 6263 	mov	sp,a
      002086 C0 04            [24] 6264 	push	ar4
      002088 C0 05            [24] 6265 	push	ar5
      00208A C0 06            [24] 6266 	push	ar6
      00208C C0 07            [24] 6267 	push	ar7
      00208E 90 66 66         [24] 6268 	mov	dptr,#0x6666
      002091 75 F0 E6         [24] 6269 	mov	b, #0xe6
      002094 74 3E            [12] 6270 	mov	a, #0x3e
      002096 12 2A B5         [24] 6271 	lcall	___fsmul
      002099 AC 82            [24] 6272 	mov	r4, dpl
      00209B AD 83            [24] 6273 	mov	r5, dph
      00209D AE F0            [24] 6274 	mov	r6, b
      00209F FF               [12] 6275 	mov	r7, a
      0020A0 E5 81            [12] 6276 	mov	a,sp
      0020A2 24 FC            [12] 6277 	add	a,#0xfc
      0020A4 F5 81            [12] 6278 	mov	sp,a
      0020A6 E4               [12] 6279 	clr	a
      0020A7 C0 E0            [24] 6280 	push	acc
      0020A9 C0 E0            [24] 6281 	push	acc
      0020AB 74 0C            [12] 6282 	mov	a,#0x0c
      0020AD C0 E0            [24] 6283 	push	acc
      0020AF 74 42            [12] 6284 	mov	a,#0x42
      0020B1 C0 E0            [24] 6285 	push	acc
      0020B3 8C 82            [24] 6286 	mov	dpl, r4
      0020B5 8D 83            [24] 6287 	mov	dph, r5
      0020B7 8E F0            [24] 6288 	mov	b, r6
      0020B9 EF               [12] 6289 	mov	a, r7
      0020BA 12 2C 15         [24] 6290 	lcall	___fsadd
      0020BD A8 10            [24] 6291 	mov	r0,_bp
      0020BF 08               [12] 6292 	inc	r0
      0020C0 A6 82            [24] 6293 	mov	@r0, dpl
      0020C2 08               [12] 6294 	inc	r0
      0020C3 A6 83            [24] 6295 	mov	@r0, dph
      0020C5 08               [12] 6296 	inc	r0
      0020C6 A6 F0            [24] 6297 	mov	@r0, b
      0020C8 08               [12] 6298 	inc	r0
      0020C9 F6               [12] 6299 	mov	@r0,a
      0020CA E5 81            [12] 6300 	mov	a,sp
      0020CC 24 FC            [12] 6301 	add	a,#0xfc
      0020CE F5 81            [12] 6302 	mov	sp,a
      0020D0 E5 10            [12] 6303 	mov	a,_bp
      0020D2 24 FA            [12] 6304 	add	a,#0xfa
      0020D4 F8               [12] 6305 	mov	r0,a
      0020D5 E6               [12] 6306 	mov	a,@r0
      0020D6 C0 E0            [24] 6307 	push	acc
      0020D8 08               [12] 6308 	inc	r0
      0020D9 E6               [12] 6309 	mov	a,@r0
      0020DA C0 E0            [24] 6310 	push	acc
      0020DC 08               [12] 6311 	inc	r0
      0020DD E6               [12] 6312 	mov	a,@r0
      0020DE C0 E0            [24] 6313 	push	acc
      0020E0 08               [12] 6314 	inc	r0
      0020E1 E6               [12] 6315 	mov	a,@r0
      0020E2 C0 E0            [24] 6316 	push	acc
      0020E4 90 99 9A         [24] 6317 	mov	dptr,#0x999a
      0020E7 75 F0 99         [24] 6318 	mov	b, #0x99
      0020EA 74 3E            [12] 6319 	mov	a, #0x3e
      0020EC 12 2A B5         [24] 6320 	lcall	___fsmul
      0020EF AA 82            [24] 6321 	mov	r2, dpl
      0020F1 AB 83            [24] 6322 	mov	r3, dph
      0020F3 AE F0            [24] 6323 	mov	r6, b
      0020F5 FF               [12] 6324 	mov	r7, a
      0020F6 E5 81            [12] 6325 	mov	a,sp
      0020F8 24 FC            [12] 6326 	add	a,#0xfc
      0020FA F5 81            [12] 6327 	mov	sp,a
      0020FC C0 02            [24] 6328 	push	ar2
      0020FE C0 03            [24] 6329 	push	ar3
      002100 C0 06            [24] 6330 	push	ar6
      002102 C0 07            [24] 6331 	push	ar7
      002104 A8 10            [24] 6332 	mov	r0,_bp
      002106 08               [12] 6333 	inc	r0
      002107 86 82            [24] 6334 	mov	dpl, @r0
      002109 08               [12] 6335 	inc	r0
      00210A 86 83            [24] 6336 	mov	dph, @r0
      00210C 08               [12] 6337 	inc	r0
      00210D 86 F0            [24] 6338 	mov	b, @r0
      00210F 08               [12] 6339 	inc	r0
      002110 E6               [12] 6340 	mov	a, @r0
      002111 12 2C 15         [24] 6341 	lcall	___fsadd
      002114 A8 10            [24] 6342 	mov	r0,_bp
      002116 08               [12] 6343 	inc	r0
      002117 A6 82            [24] 6344 	mov	@r0, dpl
      002119 08               [12] 6345 	inc	r0
      00211A A6 83            [24] 6346 	mov	@r0, dph
      00211C 08               [12] 6347 	inc	r0
      00211D A6 F0            [24] 6348 	mov	@r0, b
      00211F 08               [12] 6349 	inc	r0
      002120 F6               [12] 6350 	mov	@r0,a
      002121 E5 81            [12] 6351 	mov	a,sp
      002123 24 FC            [12] 6352 	add	a,#0xfc
      002125 F5 81            [12] 6353 	mov	sp,a
      002127 E5 10            [12] 6354 	mov	a,_bp
      002129 24 F6            [12] 6355 	add	a,#0xf6
      00212B F8               [12] 6356 	mov	r0,a
      00212C E6               [12] 6357 	mov	a,@r0
      00212D C0 E0            [24] 6358 	push	acc
      00212F 08               [12] 6359 	inc	r0
      002130 E6               [12] 6360 	mov	a,@r0
      002131 C0 E0            [24] 6361 	push	acc
      002133 08               [12] 6362 	inc	r0
      002134 E6               [12] 6363 	mov	a,@r0
      002135 C0 E0            [24] 6364 	push	acc
      002137 08               [12] 6365 	inc	r0
      002138 E6               [12] 6366 	mov	a,@r0
      002139 C0 E0            [24] 6367 	push	acc
      00213B 90 00 00         [24] 6368 	mov	dptr,#0x0000
      00213E 75 F0 20         [24] 6369 	mov	b, #0x20
      002141 74 40            [12] 6370 	mov	a, #0x40
      002143 12 2A B5         [24] 6371 	lcall	___fsmul
      002146 AA 82            [24] 6372 	mov	r2, dpl
      002148 AB 83            [24] 6373 	mov	r3, dph
      00214A AE F0            [24] 6374 	mov	r6, b
      00214C FF               [12] 6375 	mov	r7, a
      00214D E5 81            [12] 6376 	mov	a,sp
      00214F 24 FC            [12] 6377 	add	a,#0xfc
      002151 F5 81            [12] 6378 	mov	sp,a
      002153 C0 02            [24] 6379 	push	ar2
      002155 C0 03            [24] 6380 	push	ar3
      002157 C0 06            [24] 6381 	push	ar6
      002159 C0 07            [24] 6382 	push	ar7
      00215B A8 10            [24] 6383 	mov	r0,_bp
      00215D 08               [12] 6384 	inc	r0
      00215E 86 82            [24] 6385 	mov	dpl, @r0
      002160 08               [12] 6386 	inc	r0
      002161 86 83            [24] 6387 	mov	dph, @r0
      002163 08               [12] 6388 	inc	r0
      002164 86 F0            [24] 6389 	mov	b, @r0
      002166 08               [12] 6390 	inc	r0
      002167 E6               [12] 6391 	mov	a, @r0
      002168 12 2C 15         [24] 6392 	lcall	___fsadd
      00216B AC 82            [24] 6393 	mov	r4, dpl
      00216D AD 83            [24] 6394 	mov	r5, dph
      00216F AE F0            [24] 6395 	mov	r6, b
      002171 FF               [12] 6396 	mov	r7, a
      002172 E5 81            [12] 6397 	mov	a,sp
      002174 24 FC            [12] 6398 	add	a,#0xfc
      002176 F5 81            [12] 6399 	mov	sp,a
      002178 8C 82            [24] 6400 	mov	dpl, r4
      00217A 8D 83            [24] 6401 	mov	dph, r5
      00217C 8E F0            [24] 6402 	mov	b, r6
      00217E EF               [12] 6403 	mov	a, r7
      00217F 85 10 81         [24] 6404 	mov	sp,_bp
      002182 D0 10            [24] 6405 	pop	_bp
                           0020C7  6406 	C$sugeno_demo.c$41$1_0$123 ==.
                           0020C7  6407 	XFsugeno_demo$response_protection$0$0 ==.
      002184 22               [24] 6408 	ret
                                   6409 ;------------------------------------------------------------
                                   6410 ;Allocation info for local variables in function 'calculate_fan_speed'
                                   6411 ;------------------------------------------------------------
                                   6412 ;load          Allocated to stack - _bp -6 +4 
                                   6413 ;vibration     Allocated to stack - _bp -10 +4 
                                   6414 ;temperature   Allocated to stack - _bp +1 +4 
                                   6415 ;temperature_low_value Allocated to registers r7 r6 r5 r4 
                                   6416 ;temperature_high_value Allocated to stack - _bp +9 +4 
                                   6417 ;load_low_value Allocated to stack - _bp +13 +4 
                                   6418 ;load_high_value Allocated to stack - _bp +17 +4 
                                   6419 ;vibration_low_value Allocated to stack - _bp +21 +4 
                                   6420 ;vibration_high_value Allocated to stack - _bp +25 +4 
                                   6421 ;rule1         Allocated to stack - _bp +29 +4 
                                   6422 ;rule2         Allocated to stack - _bp +33 +4 
                                   6423 ;rule3         Allocated to stack - _bp +37 +4 
                                   6424 ;rule4         Allocated to stack - _bp +41 +4 
                                   6425 ;rule5         Allocated to stack - _bp +45 +4 
                                   6426 ;rule6         Allocated to stack - _bp +49 +4 
                                   6427 ;sloc0         Allocated to stack - _bp +5 +4 
                                   6428 ;------------------------------------------------------------
                           0020C8  6429 	Fsugeno_demo$calculate_fan_speed$0$0 ==.
                           0020C8  6430 	C$sugeno_demo.c$43$1_0$125 ==.
                                   6431 ;	../../sugeno_demo.c:43: static float calculate_fan_speed(float temperature, float load, float vibration)
                                   6432 ;	-----------------------------------------
                                   6433 ;	 function calculate_fan_speed
                                   6434 ;	-----------------------------------------
      002185                       6435 _calculate_fan_speed:
      002185 C0 10            [24] 6436 	push	_bp
      002187 85 81 10         [24] 6437 	mov	_bp,sp
      00218A C0 82            [24] 6438 	push	dpl
      00218C C0 83            [24] 6439 	push	dph
      00218E C0 F0            [24] 6440 	push	b
      002190 C0 E0            [24] 6441 	push	acc
      002192 E5 81            [12] 6442 	mov	a,sp
      002194 24 30            [12] 6443 	add	a,#0x30
      002196 F5 81            [12] 6444 	mov	sp,a
                           0020DB  6445 	C$sugeno_demo.c$45$1_0$125 ==.
                                   6446 ;	../../sugeno_demo.c:45: float temperature_low_value = temperature_low(temperature);
      002198 A8 10            [24] 6447 	mov	r0,_bp
      00219A 08               [12] 6448 	inc	r0
      00219B 86 82            [24] 6449 	mov	dpl, @r0
      00219D 08               [12] 6450 	inc	r0
      00219E 86 83            [24] 6451 	mov	dph, @r0
      0021A0 08               [12] 6452 	inc	r0
      0021A1 86 F0            [24] 6453 	mov	b, @r0
      0021A3 08               [12] 6454 	inc	r0
      0021A4 E6               [12] 6455 	mov	a, @r0
      0021A5 12 1A 41         [24] 6456 	lcall	_temperature_low
      0021A8 AF 82            [24] 6457 	mov	r7, dpl
      0021AA AE 83            [24] 6458 	mov	r6, dph
      0021AC AD F0            [24] 6459 	mov	r5, b
      0021AE FC               [12] 6460 	mov	r4, a
                           0020F2  6461 	C$sugeno_demo.c$46$1_0$125 ==.
                                   6462 ;	../../sugeno_demo.c:46: float temperature_high_value = temperature_high(temperature);
      0021AF A8 10            [24] 6463 	mov	r0,_bp
      0021B1 08               [12] 6464 	inc	r0
      0021B2 86 82            [24] 6465 	mov	dpl, @r0
      0021B4 08               [12] 6466 	inc	r0
      0021B5 86 83            [24] 6467 	mov	dph, @r0
      0021B7 08               [12] 6468 	inc	r0
      0021B8 86 F0            [24] 6469 	mov	b, @r0
      0021BA 08               [12] 6470 	inc	r0
      0021BB E6               [12] 6471 	mov	a, @r0
      0021BC C0 07            [24] 6472 	push	ar7
      0021BE C0 06            [24] 6473 	push	ar6
      0021C0 C0 05            [24] 6474 	push	ar5
      0021C2 C0 04            [24] 6475 	push	ar4
      0021C4 12 1A 6E         [24] 6476 	lcall	_temperature_high
      0021C7 C8               [12] 6477 	xch	a,r0
      0021C8 E5 10            [12] 6478 	mov	a,_bp
      0021CA 24 09            [12] 6479 	add	a,#0x09
      0021CC C8               [12] 6480 	xch	a,r0
      0021CD A6 82            [24] 6481 	mov	@r0, dpl
      0021CF 08               [12] 6482 	inc	r0
      0021D0 A6 83            [24] 6483 	mov	@r0, dph
      0021D2 08               [12] 6484 	inc	r0
      0021D3 A6 F0            [24] 6485 	mov	@r0, b
      0021D5 08               [12] 6486 	inc	r0
      0021D6 F6               [12] 6487 	mov	@r0,a
                           00211A  6488 	C$sugeno_demo.c$47$1_0$125 ==.
                                   6489 ;	../../sugeno_demo.c:47: float load_low_value = load_low(load);
      0021D7 E5 10            [12] 6490 	mov	a,_bp
      0021D9 24 FA            [12] 6491 	add	a,#0xfa
      0021DB F8               [12] 6492 	mov	r0,a
      0021DC 86 82            [24] 6493 	mov	dpl, @r0
      0021DE 08               [12] 6494 	inc	r0
      0021DF 86 83            [24] 6495 	mov	dph, @r0
      0021E1 08               [12] 6496 	inc	r0
      0021E2 86 F0            [24] 6497 	mov	b, @r0
      0021E4 08               [12] 6498 	inc	r0
      0021E5 E6               [12] 6499 	mov	a, @r0
      0021E6 12 1A 9B         [24] 6500 	lcall	_load_low
      0021E9 C8               [12] 6501 	xch	a,r0
      0021EA E5 10            [12] 6502 	mov	a,_bp
      0021EC 24 0D            [12] 6503 	add	a,#0x0d
      0021EE C8               [12] 6504 	xch	a,r0
      0021EF A6 82            [24] 6505 	mov	@r0, dpl
      0021F1 08               [12] 6506 	inc	r0
      0021F2 A6 83            [24] 6507 	mov	@r0, dph
      0021F4 08               [12] 6508 	inc	r0
      0021F5 A6 F0            [24] 6509 	mov	@r0, b
      0021F7 08               [12] 6510 	inc	r0
      0021F8 F6               [12] 6511 	mov	@r0,a
                           00213C  6512 	C$sugeno_demo.c$48$1_0$125 ==.
                                   6513 ;	../../sugeno_demo.c:48: float load_high_value = load_high(load);
      0021F9 E5 10            [12] 6514 	mov	a,_bp
      0021FB 24 FA            [12] 6515 	add	a,#0xfa
      0021FD F8               [12] 6516 	mov	r0,a
      0021FE 86 82            [24] 6517 	mov	dpl, @r0
      002200 08               [12] 6518 	inc	r0
      002201 86 83            [24] 6519 	mov	dph, @r0
      002203 08               [12] 6520 	inc	r0
      002204 86 F0            [24] 6521 	mov	b, @r0
      002206 08               [12] 6522 	inc	r0
      002207 E6               [12] 6523 	mov	a, @r0
      002208 12 1A C8         [24] 6524 	lcall	_load_high
      00220B C8               [12] 6525 	xch	a,r0
      00220C E5 10            [12] 6526 	mov	a,_bp
      00220E 24 11            [12] 6527 	add	a,#0x11
      002210 C8               [12] 6528 	xch	a,r0
      002211 A6 82            [24] 6529 	mov	@r0, dpl
      002213 08               [12] 6530 	inc	r0
      002214 A6 83            [24] 6531 	mov	@r0, dph
      002216 08               [12] 6532 	inc	r0
      002217 A6 F0            [24] 6533 	mov	@r0, b
      002219 08               [12] 6534 	inc	r0
      00221A F6               [12] 6535 	mov	@r0,a
                           00215E  6536 	C$sugeno_demo.c$49$1_0$125 ==.
                                   6537 ;	../../sugeno_demo.c:49: float vibration_low_value = vibration_low(vibration);
      00221B E5 10            [12] 6538 	mov	a,_bp
      00221D 24 F6            [12] 6539 	add	a,#0xf6
      00221F F8               [12] 6540 	mov	r0,a
      002220 86 82            [24] 6541 	mov	dpl, @r0
      002222 08               [12] 6542 	inc	r0
      002223 86 83            [24] 6543 	mov	dph, @r0
      002225 08               [12] 6544 	inc	r0
      002226 86 F0            [24] 6545 	mov	b, @r0
      002228 08               [12] 6546 	inc	r0
      002229 E6               [12] 6547 	mov	a, @r0
      00222A 12 1A F5         [24] 6548 	lcall	_vibration_low
      00222D C8               [12] 6549 	xch	a,r0
      00222E E5 10            [12] 6550 	mov	a,_bp
      002230 24 15            [12] 6551 	add	a,#0x15
      002232 C8               [12] 6552 	xch	a,r0
      002233 A6 82            [24] 6553 	mov	@r0, dpl
      002235 08               [12] 6554 	inc	r0
      002236 A6 83            [24] 6555 	mov	@r0, dph
      002238 08               [12] 6556 	inc	r0
      002239 A6 F0            [24] 6557 	mov	@r0, b
      00223B 08               [12] 6558 	inc	r0
      00223C F6               [12] 6559 	mov	@r0,a
                           002180  6560 	C$sugeno_demo.c$50$1_0$125 ==.
                                   6561 ;	../../sugeno_demo.c:50: float vibration_high_value = vibration_high(vibration);
      00223D E5 10            [12] 6562 	mov	a,_bp
      00223F 24 F6            [12] 6563 	add	a,#0xf6
      002241 F8               [12] 6564 	mov	r0,a
      002242 86 82            [24] 6565 	mov	dpl, @r0
      002244 08               [12] 6566 	inc	r0
      002245 86 83            [24] 6567 	mov	dph, @r0
      002247 08               [12] 6568 	inc	r0
      002248 86 F0            [24] 6569 	mov	b, @r0
      00224A 08               [12] 6570 	inc	r0
      00224B E6               [12] 6571 	mov	a, @r0
      00224C 12 1B 22         [24] 6572 	lcall	_vibration_high
      00224F C8               [12] 6573 	xch	a,r0
      002250 E5 10            [12] 6574 	mov	a,_bp
      002252 24 19            [12] 6575 	add	a,#0x19
      002254 C8               [12] 6576 	xch	a,r0
      002255 A6 82            [24] 6577 	mov	@r0, dpl
      002257 08               [12] 6578 	inc	r0
      002258 A6 83            [24] 6579 	mov	@r0, dph
      00225A 08               [12] 6580 	inc	r0
      00225B A6 F0            [24] 6581 	mov	@r0, b
      00225D 08               [12] 6582 	inc	r0
      00225E F6               [12] 6583 	mov	@r0,a
      00225F D0 04            [24] 6584 	pop	ar4
      002261 D0 05            [24] 6585 	pop	ar5
      002263 D0 06            [24] 6586 	pop	ar6
      002265 D0 07            [24] 6587 	pop	ar7
                           0021AA  6588 	C$sugeno_demo.c$52$1_0$125 ==.
                                   6589 ;	../../sugeno_demo.c:52: float rule1 = fuzzy_and_method(FUZZY_LOGIC_STANDARD, temperature_low_value, load_low_value, vibration_low_value);
      002267 E5 10            [12] 6590 	mov	a,_bp
      002269 24 15            [12] 6591 	add	a,#0x15
      00226B F8               [12] 6592 	mov	r0,a
      00226C E6               [12] 6593 	mov	a,@r0
      00226D C0 E0            [24] 6594 	push	acc
      00226F 08               [12] 6595 	inc	r0
      002270 E6               [12] 6596 	mov	a,@r0
      002271 C0 E0            [24] 6597 	push	acc
      002273 08               [12] 6598 	inc	r0
      002274 E6               [12] 6599 	mov	a,@r0
      002275 C0 E0            [24] 6600 	push	acc
      002277 08               [12] 6601 	inc	r0
      002278 E6               [12] 6602 	mov	a,@r0
      002279 C0 E0            [24] 6603 	push	acc
      00227B E5 10            [12] 6604 	mov	a,_bp
      00227D 24 0D            [12] 6605 	add	a,#0x0d
      00227F F8               [12] 6606 	mov	r0,a
      002280 E6               [12] 6607 	mov	a,@r0
      002281 C0 E0            [24] 6608 	push	acc
      002283 08               [12] 6609 	inc	r0
      002284 E6               [12] 6610 	mov	a,@r0
      002285 C0 E0            [24] 6611 	push	acc
      002287 08               [12] 6612 	inc	r0
      002288 E6               [12] 6613 	mov	a,@r0
      002289 C0 E0            [24] 6614 	push	acc
      00228B 08               [12] 6615 	inc	r0
      00228C E6               [12] 6616 	mov	a,@r0
      00228D C0 E0            [24] 6617 	push	acc
      00228F C0 07            [24] 6618 	push	ar7
      002291 C0 06            [24] 6619 	push	ar6
      002293 C0 05            [24] 6620 	push	ar5
      002295 C0 04            [24] 6621 	push	ar4
      002297 75 82 00         [24] 6622 	mov	dpl, #0x00
      00229A 12 01 F9         [24] 6623 	lcall	_fuzzy_8051_and3
      00229D C8               [12] 6624 	xch	a,r0
      00229E E5 10            [12] 6625 	mov	a,_bp
      0022A0 24 1D            [12] 6626 	add	a,#0x1d
      0022A2 C8               [12] 6627 	xch	a,r0
      0022A3 A6 82            [24] 6628 	mov	@r0, dpl
      0022A5 08               [12] 6629 	inc	r0
      0022A6 A6 83            [24] 6630 	mov	@r0, dph
      0022A8 08               [12] 6631 	inc	r0
      0022A9 A6 F0            [24] 6632 	mov	@r0, b
      0022AB 08               [12] 6633 	inc	r0
      0022AC F6               [12] 6634 	mov	@r0,a
      0022AD E5 81            [12] 6635 	mov	a,sp
      0022AF 24 F4            [12] 6636 	add	a,#0xf4
      0022B1 F5 81            [12] 6637 	mov	sp,a
                           0021F6  6638 	C$sugeno_demo.c$53$1_0$125 ==.
                                   6639 ;	../../sugeno_demo.c:53: float rule2 = fuzzy_and_method(FUZZY_LOGIC_STANDARD, fuzzy_not(temperature_high_value), load_high_value);
      0022B3 E5 10            [12] 6640 	mov	a,_bp
      0022B5 24 09            [12] 6641 	add	a,#0x09
      0022B7 F8               [12] 6642 	mov	r0,a
      0022B8 86 82            [24] 6643 	mov	dpl, @r0
      0022BA 08               [12] 6644 	inc	r0
      0022BB 86 83            [24] 6645 	mov	dph, @r0
      0022BD 08               [12] 6646 	inc	r0
      0022BE 86 F0            [24] 6647 	mov	b, @r0
      0022C0 08               [12] 6648 	inc	r0
      0022C1 E6               [12] 6649 	mov	a, @r0
      0022C2 12 05 84         [24] 6650 	lcall	_fuzzy_not
      0022C5 AA 82            [24] 6651 	mov	r2, dpl
      0022C7 AB 83            [24] 6652 	mov	r3, dph
      0022C9 AE F0            [24] 6653 	mov	r6, b
      0022CB FF               [12] 6654 	mov	r7, a
      0022CC E5 10            [12] 6655 	mov	a,_bp
      0022CE 24 11            [12] 6656 	add	a,#0x11
      0022D0 F8               [12] 6657 	mov	r0,a
      0022D1 E6               [12] 6658 	mov	a,@r0
      0022D2 C0 E0            [24] 6659 	push	acc
      0022D4 08               [12] 6660 	inc	r0
      0022D5 E6               [12] 6661 	mov	a,@r0
      0022D6 C0 E0            [24] 6662 	push	acc
      0022D8 08               [12] 6663 	inc	r0
      0022D9 E6               [12] 6664 	mov	a,@r0
      0022DA C0 E0            [24] 6665 	push	acc
      0022DC 08               [12] 6666 	inc	r0
      0022DD E6               [12] 6667 	mov	a,@r0
      0022DE C0 E0            [24] 6668 	push	acc
      0022E0 C0 02            [24] 6669 	push	ar2
      0022E2 C0 03            [24] 6670 	push	ar3
      0022E4 C0 06            [24] 6671 	push	ar6
      0022E6 C0 07            [24] 6672 	push	ar7
      0022E8 75 82 00         [24] 6673 	mov	dpl, #0x00
      0022EB 12 00 BD         [24] 6674 	lcall	_fuzzy_8051_and2
      0022EE C8               [12] 6675 	xch	a,r0
      0022EF E5 10            [12] 6676 	mov	a,_bp
      0022F1 24 21            [12] 6677 	add	a,#0x21
      0022F3 C8               [12] 6678 	xch	a,r0
      0022F4 A6 82            [24] 6679 	mov	@r0, dpl
      0022F6 08               [12] 6680 	inc	r0
      0022F7 A6 83            [24] 6681 	mov	@r0, dph
      0022F9 08               [12] 6682 	inc	r0
      0022FA A6 F0            [24] 6683 	mov	@r0, b
      0022FC 08               [12] 6684 	inc	r0
      0022FD F6               [12] 6685 	mov	@r0,a
      0022FE E5 81            [12] 6686 	mov	a,sp
      002300 24 F8            [12] 6687 	add	a,#0xf8
      002302 F5 81            [12] 6688 	mov	sp,a
                           002247  6689 	C$sugeno_demo.c$54$1_0$125 ==.
                                   6690 ;	../../sugeno_demo.c:54: float rule3 = fuzzy_or_method(FUZZY_LOGIC_STANDARD, temperature_high_value, vibration_high_value);
      002304 E5 10            [12] 6691 	mov	a,_bp
      002306 24 19            [12] 6692 	add	a,#0x19
      002308 F8               [12] 6693 	mov	r0,a
      002309 E6               [12] 6694 	mov	a,@r0
      00230A C0 E0            [24] 6695 	push	acc
      00230C 08               [12] 6696 	inc	r0
      00230D E6               [12] 6697 	mov	a,@r0
      00230E C0 E0            [24] 6698 	push	acc
      002310 08               [12] 6699 	inc	r0
      002311 E6               [12] 6700 	mov	a,@r0
      002312 C0 E0            [24] 6701 	push	acc
      002314 08               [12] 6702 	inc	r0
      002315 E6               [12] 6703 	mov	a,@r0
      002316 C0 E0            [24] 6704 	push	acc
      002318 E5 10            [12] 6705 	mov	a,_bp
      00231A 24 09            [12] 6706 	add	a,#0x09
      00231C F8               [12] 6707 	mov	r0,a
      00231D E6               [12] 6708 	mov	a,@r0
      00231E C0 E0            [24] 6709 	push	acc
      002320 08               [12] 6710 	inc	r0
      002321 E6               [12] 6711 	mov	a,@r0
      002322 C0 E0            [24] 6712 	push	acc
      002324 08               [12] 6713 	inc	r0
      002325 E6               [12] 6714 	mov	a,@r0
      002326 C0 E0            [24] 6715 	push	acc
      002328 08               [12] 6716 	inc	r0
      002329 E6               [12] 6717 	mov	a,@r0
      00232A C0 E0            [24] 6718 	push	acc
      00232C 75 82 00         [24] 6719 	mov	dpl, #0x00
      00232F 12 02 76         [24] 6720 	lcall	_fuzzy_8051_or2
      002332 C8               [12] 6721 	xch	a,r0
      002333 E5 10            [12] 6722 	mov	a,_bp
      002335 24 25            [12] 6723 	add	a,#0x25
      002337 C8               [12] 6724 	xch	a,r0
      002338 A6 82            [24] 6725 	mov	@r0, dpl
      00233A 08               [12] 6726 	inc	r0
      00233B A6 83            [24] 6727 	mov	@r0, dph
      00233D 08               [12] 6728 	inc	r0
      00233E A6 F0            [24] 6729 	mov	@r0, b
      002340 08               [12] 6730 	inc	r0
      002341 F6               [12] 6731 	mov	@r0,a
      002342 E5 81            [12] 6732 	mov	a,sp
      002344 24 F8            [12] 6733 	add	a,#0xf8
      002346 F5 81            [12] 6734 	mov	sp,a
                           00228B  6735 	C$sugeno_demo.c$55$1_0$125 ==.
                                   6736 ;	../../sugeno_demo.c:55: float rule4 = fuzzy_and_method(FUZZY_LOGIC_STANDARD, temperature_high_value, load_high_value);
      002348 E5 10            [12] 6737 	mov	a,_bp
      00234A 24 11            [12] 6738 	add	a,#0x11
      00234C F8               [12] 6739 	mov	r0,a
      00234D E6               [12] 6740 	mov	a,@r0
      00234E C0 E0            [24] 6741 	push	acc
      002350 08               [12] 6742 	inc	r0
      002351 E6               [12] 6743 	mov	a,@r0
      002352 C0 E0            [24] 6744 	push	acc
      002354 08               [12] 6745 	inc	r0
      002355 E6               [12] 6746 	mov	a,@r0
      002356 C0 E0            [24] 6747 	push	acc
      002358 08               [12] 6748 	inc	r0
      002359 E6               [12] 6749 	mov	a,@r0
      00235A C0 E0            [24] 6750 	push	acc
      00235C E5 10            [12] 6751 	mov	a,_bp
      00235E 24 09            [12] 6752 	add	a,#0x09
      002360 F8               [12] 6753 	mov	r0,a
      002361 E6               [12] 6754 	mov	a,@r0
      002362 C0 E0            [24] 6755 	push	acc
      002364 08               [12] 6756 	inc	r0
      002365 E6               [12] 6757 	mov	a,@r0
      002366 C0 E0            [24] 6758 	push	acc
      002368 08               [12] 6759 	inc	r0
      002369 E6               [12] 6760 	mov	a,@r0
      00236A C0 E0            [24] 6761 	push	acc
      00236C 08               [12] 6762 	inc	r0
      00236D E6               [12] 6763 	mov	a,@r0
      00236E C0 E0            [24] 6764 	push	acc
      002370 75 82 00         [24] 6765 	mov	dpl, #0x00
      002373 12 00 BD         [24] 6766 	lcall	_fuzzy_8051_and2
      002376 C8               [12] 6767 	xch	a,r0
      002377 E5 10            [12] 6768 	mov	a,_bp
      002379 24 29            [12] 6769 	add	a,#0x29
      00237B C8               [12] 6770 	xch	a,r0
      00237C A6 82            [24] 6771 	mov	@r0, dpl
      00237E 08               [12] 6772 	inc	r0
      00237F A6 83            [24] 6773 	mov	@r0, dph
      002381 08               [12] 6774 	inc	r0
      002382 A6 F0            [24] 6775 	mov	@r0, b
      002384 08               [12] 6776 	inc	r0
      002385 F6               [12] 6777 	mov	@r0,a
      002386 E5 81            [12] 6778 	mov	a,sp
      002388 24 F8            [12] 6779 	add	a,#0xf8
      00238A F5 81            [12] 6780 	mov	sp,a
                           0022CF  6781 	C$sugeno_demo.c$56$1_0$125 ==.
                                   6782 ;	../../sugeno_demo.c:56: float rule5 = fuzzy_and_method(FUZZY_LOGIC_STANDARD, load_high_value, fuzzy_not(vibration_high_value));
      00238C E5 10            [12] 6783 	mov	a,_bp
      00238E 24 19            [12] 6784 	add	a,#0x19
      002390 F8               [12] 6785 	mov	r0,a
      002391 86 82            [24] 6786 	mov	dpl, @r0
      002393 08               [12] 6787 	inc	r0
      002394 86 83            [24] 6788 	mov	dph, @r0
      002396 08               [12] 6789 	inc	r0
      002397 86 F0            [24] 6790 	mov	b, @r0
      002399 08               [12] 6791 	inc	r0
      00239A E6               [12] 6792 	mov	a, @r0
      00239B 12 05 84         [24] 6793 	lcall	_fuzzy_not
      00239E AA 82            [24] 6794 	mov	r2, dpl
      0023A0 AB 83            [24] 6795 	mov	r3, dph
      0023A2 AE F0            [24] 6796 	mov	r6, b
      0023A4 FF               [12] 6797 	mov	r7, a
      0023A5 C0 02            [24] 6798 	push	ar2
      0023A7 C0 03            [24] 6799 	push	ar3
      0023A9 C0 06            [24] 6800 	push	ar6
      0023AB C0 07            [24] 6801 	push	ar7
      0023AD E5 10            [12] 6802 	mov	a,_bp
      0023AF 24 11            [12] 6803 	add	a,#0x11
      0023B1 F8               [12] 6804 	mov	r0,a
      0023B2 E6               [12] 6805 	mov	a,@r0
      0023B3 C0 E0            [24] 6806 	push	acc
      0023B5 08               [12] 6807 	inc	r0
      0023B6 E6               [12] 6808 	mov	a,@r0
      0023B7 C0 E0            [24] 6809 	push	acc
      0023B9 08               [12] 6810 	inc	r0
      0023BA E6               [12] 6811 	mov	a,@r0
      0023BB C0 E0            [24] 6812 	push	acc
      0023BD 08               [12] 6813 	inc	r0
      0023BE E6               [12] 6814 	mov	a,@r0
      0023BF C0 E0            [24] 6815 	push	acc
      0023C1 75 82 00         [24] 6816 	mov	dpl, #0x00
      0023C4 12 00 BD         [24] 6817 	lcall	_fuzzy_8051_and2
      0023C7 C8               [12] 6818 	xch	a,r0
      0023C8 E5 10            [12] 6819 	mov	a,_bp
      0023CA 24 2D            [12] 6820 	add	a,#0x2d
      0023CC C8               [12] 6821 	xch	a,r0
      0023CD A6 82            [24] 6822 	mov	@r0, dpl
      0023CF 08               [12] 6823 	inc	r0
      0023D0 A6 83            [24] 6824 	mov	@r0, dph
      0023D2 08               [12] 6825 	inc	r0
      0023D3 A6 F0            [24] 6826 	mov	@r0, b
      0023D5 08               [12] 6827 	inc	r0
      0023D6 F6               [12] 6828 	mov	@r0,a
      0023D7 E5 81            [12] 6829 	mov	a,sp
      0023D9 24 F8            [12] 6830 	add	a,#0xf8
      0023DB F5 81            [12] 6831 	mov	sp,a
                           002320  6832 	C$sugeno_demo.c$57$1_0$125 ==.
                                   6833 ;	../../sugeno_demo.c:57: float rule6 = fuzzy_or_method(FUZZY_LOGIC_STANDARD, fuzzy_and_method(FUZZY_LOGIC_STANDARD, temperature_high_value, vibration_high_value), fuzzy_and_method(FUZZY_LOGIC_STANDARD, load_high_value, vibration_high_value));
      0023DD E5 10            [12] 6834 	mov	a,_bp
      0023DF 24 19            [12] 6835 	add	a,#0x19
      0023E1 F8               [12] 6836 	mov	r0,a
      0023E2 E6               [12] 6837 	mov	a,@r0
      0023E3 C0 E0            [24] 6838 	push	acc
      0023E5 08               [12] 6839 	inc	r0
      0023E6 E6               [12] 6840 	mov	a,@r0
      0023E7 C0 E0            [24] 6841 	push	acc
      0023E9 08               [12] 6842 	inc	r0
      0023EA E6               [12] 6843 	mov	a,@r0
      0023EB C0 E0            [24] 6844 	push	acc
      0023ED 08               [12] 6845 	inc	r0
      0023EE E6               [12] 6846 	mov	a,@r0
      0023EF C0 E0            [24] 6847 	push	acc
      0023F1 E5 10            [12] 6848 	mov	a,_bp
      0023F3 24 11            [12] 6849 	add	a,#0x11
      0023F5 F8               [12] 6850 	mov	r0,a
      0023F6 E6               [12] 6851 	mov	a,@r0
      0023F7 C0 E0            [24] 6852 	push	acc
      0023F9 08               [12] 6853 	inc	r0
      0023FA E6               [12] 6854 	mov	a,@r0
      0023FB C0 E0            [24] 6855 	push	acc
      0023FD 08               [12] 6856 	inc	r0
      0023FE E6               [12] 6857 	mov	a,@r0
      0023FF C0 E0            [24] 6858 	push	acc
      002401 08               [12] 6859 	inc	r0
      002402 E6               [12] 6860 	mov	a,@r0
      002403 C0 E0            [24] 6861 	push	acc
      002405 75 82 00         [24] 6862 	mov	dpl, #0x00
      002408 12 00 BD         [24] 6863 	lcall	_fuzzy_8051_and2
      00240B C8               [12] 6864 	xch	a,r0
      00240C E5 10            [12] 6865 	mov	a,_bp
      00240E 24 05            [12] 6866 	add	a,#0x05
      002410 C8               [12] 6867 	xch	a,r0
      002411 A6 82            [24] 6868 	mov	@r0, dpl
      002413 08               [12] 6869 	inc	r0
      002414 A6 83            [24] 6870 	mov	@r0, dph
      002416 08               [12] 6871 	inc	r0
      002417 A6 F0            [24] 6872 	mov	@r0, b
      002419 08               [12] 6873 	inc	r0
      00241A F6               [12] 6874 	mov	@r0,a
      00241B E5 81            [12] 6875 	mov	a,sp
      00241D 24 F8            [12] 6876 	add	a,#0xf8
      00241F F5 81            [12] 6877 	mov	sp,a
      002421 E5 10            [12] 6878 	mov	a,_bp
      002423 24 19            [12] 6879 	add	a,#0x19
      002425 F8               [12] 6880 	mov	r0,a
      002426 E6               [12] 6881 	mov	a,@r0
      002427 C0 E0            [24] 6882 	push	acc
      002429 08               [12] 6883 	inc	r0
      00242A E6               [12] 6884 	mov	a,@r0
      00242B C0 E0            [24] 6885 	push	acc
      00242D 08               [12] 6886 	inc	r0
      00242E E6               [12] 6887 	mov	a,@r0
      00242F C0 E0            [24] 6888 	push	acc
      002431 08               [12] 6889 	inc	r0
      002432 E6               [12] 6890 	mov	a,@r0
      002433 C0 E0            [24] 6891 	push	acc
      002435 E5 10            [12] 6892 	mov	a,_bp
      002437 24 09            [12] 6893 	add	a,#0x09
      002439 F8               [12] 6894 	mov	r0,a
      00243A E6               [12] 6895 	mov	a,@r0
      00243B C0 E0            [24] 6896 	push	acc
      00243D 08               [12] 6897 	inc	r0
      00243E E6               [12] 6898 	mov	a,@r0
      00243F C0 E0            [24] 6899 	push	acc
      002441 08               [12] 6900 	inc	r0
      002442 E6               [12] 6901 	mov	a,@r0
      002443 C0 E0            [24] 6902 	push	acc
      002445 08               [12] 6903 	inc	r0
      002446 E6               [12] 6904 	mov	a,@r0
      002447 C0 E0            [24] 6905 	push	acc
      002449 75 82 00         [24] 6906 	mov	dpl, #0x00
      00244C 12 00 BD         [24] 6907 	lcall	_fuzzy_8051_and2
      00244F AC 82            [24] 6908 	mov	r4, dpl
      002451 AD 83            [24] 6909 	mov	r5, dph
      002453 AE F0            [24] 6910 	mov	r6, b
      002455 FF               [12] 6911 	mov	r7, a
      002456 E5 81            [12] 6912 	mov	a,sp
      002458 24 F8            [12] 6913 	add	a,#0xf8
      00245A F5 81            [12] 6914 	mov	sp,a
      00245C E5 10            [12] 6915 	mov	a,_bp
      00245E 24 05            [12] 6916 	add	a,#0x05
      002460 F8               [12] 6917 	mov	r0,a
      002461 E6               [12] 6918 	mov	a,@r0
      002462 C0 E0            [24] 6919 	push	acc
      002464 08               [12] 6920 	inc	r0
      002465 E6               [12] 6921 	mov	a,@r0
      002466 C0 E0            [24] 6922 	push	acc
      002468 08               [12] 6923 	inc	r0
      002469 E6               [12] 6924 	mov	a,@r0
      00246A C0 E0            [24] 6925 	push	acc
      00246C 08               [12] 6926 	inc	r0
      00246D E6               [12] 6927 	mov	a,@r0
      00246E C0 E0            [24] 6928 	push	acc
      002470 C0 04            [24] 6929 	push	ar4
      002472 C0 05            [24] 6930 	push	ar5
      002474 C0 06            [24] 6931 	push	ar6
      002476 C0 07            [24] 6932 	push	ar7
      002478 75 82 00         [24] 6933 	mov	dpl, #0x00
      00247B 12 02 76         [24] 6934 	lcall	_fuzzy_8051_or2
      00247E C8               [12] 6935 	xch	a,r0
      00247F E5 10            [12] 6936 	mov	a,_bp
      002481 24 31            [12] 6937 	add	a,#0x31
      002483 C8               [12] 6938 	xch	a,r0
      002484 A6 82            [24] 6939 	mov	@r0, dpl
      002486 08               [12] 6940 	inc	r0
      002487 A6 83            [24] 6941 	mov	@r0, dph
      002489 08               [12] 6942 	inc	r0
      00248A A6 F0            [24] 6943 	mov	@r0, b
      00248C 08               [12] 6944 	inc	r0
      00248D F6               [12] 6945 	mov	@r0,a
      00248E E5 81            [12] 6946 	mov	a,sp
      002490 24 F8            [12] 6947 	add	a,#0xf8
      002492 F5 81            [12] 6948 	mov	sp,a
                           0023D7  6949 	C$sugeno_demo.c$59$1_0$125 ==.
                                   6950 ;	../../sugeno_demo.c:59: return fuzzy_sugeno_weighted_average(rule1, response_idle(temperature, load, vibration), rule2, response_economy(temperature, load, vibration), rule3, response_balanced(temperature, load, vibration), rule4, response_cooling(temperature, load, vibration), rule5, response_heavy_load(temperature, load, vibration), rule6, response_protection(temperature, load, vibration));
      002494 E5 10            [12] 6951 	mov	a,_bp
      002496 24 F6            [12] 6952 	add	a,#0xf6
      002498 F8               [12] 6953 	mov	r0,a
      002499 E6               [12] 6954 	mov	a,@r0
      00249A C0 E0            [24] 6955 	push	acc
      00249C 08               [12] 6956 	inc	r0
      00249D E6               [12] 6957 	mov	a,@r0
      00249E C0 E0            [24] 6958 	push	acc
      0024A0 08               [12] 6959 	inc	r0
      0024A1 E6               [12] 6960 	mov	a,@r0
      0024A2 C0 E0            [24] 6961 	push	acc
      0024A4 08               [12] 6962 	inc	r0
      0024A5 E6               [12] 6963 	mov	a,@r0
      0024A6 C0 E0            [24] 6964 	push	acc
      0024A8 E5 10            [12] 6965 	mov	a,_bp
      0024AA 24 FA            [12] 6966 	add	a,#0xfa
      0024AC F8               [12] 6967 	mov	r0,a
      0024AD E6               [12] 6968 	mov	a,@r0
      0024AE C0 E0            [24] 6969 	push	acc
      0024B0 08               [12] 6970 	inc	r0
      0024B1 E6               [12] 6971 	mov	a,@r0
      0024B2 C0 E0            [24] 6972 	push	acc
      0024B4 08               [12] 6973 	inc	r0
      0024B5 E6               [12] 6974 	mov	a,@r0
      0024B6 C0 E0            [24] 6975 	push	acc
      0024B8 08               [12] 6976 	inc	r0
      0024B9 E6               [12] 6977 	mov	a,@r0
      0024BA C0 E0            [24] 6978 	push	acc
      0024BC A8 10            [24] 6979 	mov	r0,_bp
      0024BE 08               [12] 6980 	inc	r0
      0024BF 86 82            [24] 6981 	mov	dpl, @r0
      0024C1 08               [12] 6982 	inc	r0
      0024C2 86 83            [24] 6983 	mov	dph, @r0
      0024C4 08               [12] 6984 	inc	r0
      0024C5 86 F0            [24] 6985 	mov	b, @r0
      0024C7 08               [12] 6986 	inc	r0
      0024C8 E6               [12] 6987 	mov	a, @r0
      0024C9 12 1B 4F         [24] 6988 	lcall	_response_idle
      0024CC AA 82            [24] 6989 	mov	r2, dpl
      0024CE AB 83            [24] 6990 	mov	r3, dph
      0024D0 AE F0            [24] 6991 	mov	r6, b
      0024D2 FF               [12] 6992 	mov	r7, a
      0024D3 E5 81            [12] 6993 	mov	a,sp
      0024D5 24 F8            [12] 6994 	add	a,#0xf8
      0024D7 F5 81            [12] 6995 	mov	sp,a
      0024D9 C0 02            [24] 6996 	push	ar2
      0024DB C0 03            [24] 6997 	push	ar3
      0024DD C0 06            [24] 6998 	push	ar6
      0024DF C0 07            [24] 6999 	push	ar7
      0024E1 E5 10            [12] 7000 	mov	a,_bp
      0024E3 24 1D            [12] 7001 	add	a,#0x1d
      0024E5 F8               [12] 7002 	mov	r0,a
      0024E6 86 82            [24] 7003 	mov	dpl, @r0
      0024E8 08               [12] 7004 	inc	r0
      0024E9 86 83            [24] 7005 	mov	dph, @r0
      0024EB 08               [12] 7006 	inc	r0
      0024EC 86 F0            [24] 7007 	mov	b, @r0
      0024EE 08               [12] 7008 	inc	r0
      0024EF E6               [12] 7009 	mov	a, @r0
      0024F0 12 2A B5         [24] 7010 	lcall	___fsmul
      0024F3 C8               [12] 7011 	xch	a,r0
      0024F4 E5 10            [12] 7012 	mov	a,_bp
      0024F6 24 05            [12] 7013 	add	a,#0x05
      0024F8 C8               [12] 7014 	xch	a,r0
      0024F9 A6 82            [24] 7015 	mov	@r0, dpl
      0024FB 08               [12] 7016 	inc	r0
      0024FC A6 83            [24] 7017 	mov	@r0, dph
      0024FE 08               [12] 7018 	inc	r0
      0024FF A6 F0            [24] 7019 	mov	@r0, b
      002501 08               [12] 7020 	inc	r0
      002502 F6               [12] 7021 	mov	@r0,a
      002503 E5 81            [12] 7022 	mov	a,sp
      002505 24 FC            [12] 7023 	add	a,#0xfc
      002507 F5 81            [12] 7024 	mov	sp,a
      002509 E5 10            [12] 7025 	mov	a,_bp
      00250B 24 F6            [12] 7026 	add	a,#0xf6
      00250D F8               [12] 7027 	mov	r0,a
      00250E E6               [12] 7028 	mov	a,@r0
      00250F C0 E0            [24] 7029 	push	acc
      002511 08               [12] 7030 	inc	r0
      002512 E6               [12] 7031 	mov	a,@r0
      002513 C0 E0            [24] 7032 	push	acc
      002515 08               [12] 7033 	inc	r0
      002516 E6               [12] 7034 	mov	a,@r0
      002517 C0 E0            [24] 7035 	push	acc
      002519 08               [12] 7036 	inc	r0
      00251A E6               [12] 7037 	mov	a,@r0
      00251B C0 E0            [24] 7038 	push	acc
      00251D E5 10            [12] 7039 	mov	a,_bp
      00251F 24 FA            [12] 7040 	add	a,#0xfa
      002521 F8               [12] 7041 	mov	r0,a
      002522 E6               [12] 7042 	mov	a,@r0
      002523 C0 E0            [24] 7043 	push	acc
      002525 08               [12] 7044 	inc	r0
      002526 E6               [12] 7045 	mov	a,@r0
      002527 C0 E0            [24] 7046 	push	acc
      002529 08               [12] 7047 	inc	r0
      00252A E6               [12] 7048 	mov	a,@r0
      00252B C0 E0            [24] 7049 	push	acc
      00252D 08               [12] 7050 	inc	r0
      00252E E6               [12] 7051 	mov	a,@r0
      00252F C0 E0            [24] 7052 	push	acc
      002531 A8 10            [24] 7053 	mov	r0,_bp
      002533 08               [12] 7054 	inc	r0
      002534 86 82            [24] 7055 	mov	dpl, @r0
      002536 08               [12] 7056 	inc	r0
      002537 86 83            [24] 7057 	mov	dph, @r0
      002539 08               [12] 7058 	inc	r0
      00253A 86 F0            [24] 7059 	mov	b, @r0
      00253C 08               [12] 7060 	inc	r0
      00253D E6               [12] 7061 	mov	a, @r0
      00253E 12 1C 5E         [24] 7062 	lcall	_response_economy
      002541 AA 82            [24] 7063 	mov	r2, dpl
      002543 AB 83            [24] 7064 	mov	r3, dph
      002545 AE F0            [24] 7065 	mov	r6, b
      002547 FF               [12] 7066 	mov	r7, a
      002548 E5 81            [12] 7067 	mov	a,sp
      00254A 24 F8            [12] 7068 	add	a,#0xf8
      00254C F5 81            [12] 7069 	mov	sp,a
      00254E C0 02            [24] 7070 	push	ar2
      002550 C0 03            [24] 7071 	push	ar3
      002552 C0 06            [24] 7072 	push	ar6
      002554 C0 07            [24] 7073 	push	ar7
      002556 E5 10            [12] 7074 	mov	a,_bp
      002558 24 21            [12] 7075 	add	a,#0x21
      00255A F8               [12] 7076 	mov	r0,a
      00255B 86 82            [24] 7077 	mov	dpl, @r0
      00255D 08               [12] 7078 	inc	r0
      00255E 86 83            [24] 7079 	mov	dph, @r0
      002560 08               [12] 7080 	inc	r0
      002561 86 F0            [24] 7081 	mov	b, @r0
      002563 08               [12] 7082 	inc	r0
      002564 E6               [12] 7083 	mov	a, @r0
      002565 12 2A B5         [24] 7084 	lcall	___fsmul
      002568 AC 82            [24] 7085 	mov	r4, dpl
      00256A AD 83            [24] 7086 	mov	r5, dph
      00256C AE F0            [24] 7087 	mov	r6, b
      00256E FF               [12] 7088 	mov	r7, a
      00256F E5 81            [12] 7089 	mov	a,sp
      002571 24 FC            [12] 7090 	add	a,#0xfc
      002573 F5 81            [12] 7091 	mov	sp,a
      002575 C0 04            [24] 7092 	push	ar4
      002577 C0 05            [24] 7093 	push	ar5
      002579 C0 06            [24] 7094 	push	ar6
      00257B C0 07            [24] 7095 	push	ar7
      00257D E5 10            [12] 7096 	mov	a,_bp
      00257F 24 05            [12] 7097 	add	a,#0x05
      002581 F8               [12] 7098 	mov	r0,a
      002582 86 82            [24] 7099 	mov	dpl, @r0
      002584 08               [12] 7100 	inc	r0
      002585 86 83            [24] 7101 	mov	dph, @r0
      002587 08               [12] 7102 	inc	r0
      002588 86 F0            [24] 7103 	mov	b, @r0
      00258A 08               [12] 7104 	inc	r0
      00258B E6               [12] 7105 	mov	a, @r0
      00258C 12 2C 15         [24] 7106 	lcall	___fsadd
      00258F C8               [12] 7107 	xch	a,r0
      002590 E5 10            [12] 7108 	mov	a,_bp
      002592 24 05            [12] 7109 	add	a,#0x05
      002594 C8               [12] 7110 	xch	a,r0
      002595 A6 82            [24] 7111 	mov	@r0, dpl
      002597 08               [12] 7112 	inc	r0
      002598 A6 83            [24] 7113 	mov	@r0, dph
      00259A 08               [12] 7114 	inc	r0
      00259B A6 F0            [24] 7115 	mov	@r0, b
      00259D 08               [12] 7116 	inc	r0
      00259E F6               [12] 7117 	mov	@r0,a
      00259F E5 81            [12] 7118 	mov	a,sp
      0025A1 24 FC            [12] 7119 	add	a,#0xfc
      0025A3 F5 81            [12] 7120 	mov	sp,a
      0025A5 E5 10            [12] 7121 	mov	a,_bp
      0025A7 24 F6            [12] 7122 	add	a,#0xf6
      0025A9 F8               [12] 7123 	mov	r0,a
      0025AA E6               [12] 7124 	mov	a,@r0
      0025AB C0 E0            [24] 7125 	push	acc
      0025AD 08               [12] 7126 	inc	r0
      0025AE E6               [12] 7127 	mov	a,@r0
      0025AF C0 E0            [24] 7128 	push	acc
      0025B1 08               [12] 7129 	inc	r0
      0025B2 E6               [12] 7130 	mov	a,@r0
      0025B3 C0 E0            [24] 7131 	push	acc
      0025B5 08               [12] 7132 	inc	r0
      0025B6 E6               [12] 7133 	mov	a,@r0
      0025B7 C0 E0            [24] 7134 	push	acc
      0025B9 E5 10            [12] 7135 	mov	a,_bp
      0025BB 24 FA            [12] 7136 	add	a,#0xfa
      0025BD F8               [12] 7137 	mov	r0,a
      0025BE E6               [12] 7138 	mov	a,@r0
      0025BF C0 E0            [24] 7139 	push	acc
      0025C1 08               [12] 7140 	inc	r0
      0025C2 E6               [12] 7141 	mov	a,@r0
      0025C3 C0 E0            [24] 7142 	push	acc
      0025C5 08               [12] 7143 	inc	r0
      0025C6 E6               [12] 7144 	mov	a,@r0
      0025C7 C0 E0            [24] 7145 	push	acc
      0025C9 08               [12] 7146 	inc	r0
      0025CA E6               [12] 7147 	mov	a,@r0
      0025CB C0 E0            [24] 7148 	push	acc
      0025CD A8 10            [24] 7149 	mov	r0,_bp
      0025CF 08               [12] 7150 	inc	r0
      0025D0 86 82            [24] 7151 	mov	dpl, @r0
      0025D2 08               [12] 7152 	inc	r0
      0025D3 86 83            [24] 7153 	mov	dph, @r0
      0025D5 08               [12] 7154 	inc	r0
      0025D6 86 F0            [24] 7155 	mov	b, @r0
      0025D8 08               [12] 7156 	inc	r0
      0025D9 E6               [12] 7157 	mov	a, @r0
      0025DA 12 1D 6E         [24] 7158 	lcall	_response_balanced
      0025DD AA 82            [24] 7159 	mov	r2, dpl
      0025DF AB 83            [24] 7160 	mov	r3, dph
      0025E1 AE F0            [24] 7161 	mov	r6, b
      0025E3 FF               [12] 7162 	mov	r7, a
      0025E4 E5 81            [12] 7163 	mov	a,sp
      0025E6 24 F8            [12] 7164 	add	a,#0xf8
      0025E8 F5 81            [12] 7165 	mov	sp,a
      0025EA C0 02            [24] 7166 	push	ar2
      0025EC C0 03            [24] 7167 	push	ar3
      0025EE C0 06            [24] 7168 	push	ar6
      0025F0 C0 07            [24] 7169 	push	ar7
      0025F2 E5 10            [12] 7170 	mov	a,_bp
      0025F4 24 25            [12] 7171 	add	a,#0x25
      0025F6 F8               [12] 7172 	mov	r0,a
      0025F7 86 82            [24] 7173 	mov	dpl, @r0
      0025F9 08               [12] 7174 	inc	r0
      0025FA 86 83            [24] 7175 	mov	dph, @r0
      0025FC 08               [12] 7176 	inc	r0
      0025FD 86 F0            [24] 7177 	mov	b, @r0
      0025FF 08               [12] 7178 	inc	r0
      002600 E6               [12] 7179 	mov	a, @r0
      002601 12 2A B5         [24] 7180 	lcall	___fsmul
      002604 AC 82            [24] 7181 	mov	r4, dpl
      002606 AD 83            [24] 7182 	mov	r5, dph
      002608 AE F0            [24] 7183 	mov	r6, b
      00260A FF               [12] 7184 	mov	r7, a
      00260B E5 81            [12] 7185 	mov	a,sp
      00260D 24 FC            [12] 7186 	add	a,#0xfc
      00260F F5 81            [12] 7187 	mov	sp,a
      002611 C0 04            [24] 7188 	push	ar4
      002613 C0 05            [24] 7189 	push	ar5
      002615 C0 06            [24] 7190 	push	ar6
      002617 C0 07            [24] 7191 	push	ar7
      002619 E5 10            [12] 7192 	mov	a,_bp
      00261B 24 05            [12] 7193 	add	a,#0x05
      00261D F8               [12] 7194 	mov	r0,a
      00261E 86 82            [24] 7195 	mov	dpl, @r0
      002620 08               [12] 7196 	inc	r0
      002621 86 83            [24] 7197 	mov	dph, @r0
      002623 08               [12] 7198 	inc	r0
      002624 86 F0            [24] 7199 	mov	b, @r0
      002626 08               [12] 7200 	inc	r0
      002627 E6               [12] 7201 	mov	a, @r0
      002628 12 2C 15         [24] 7202 	lcall	___fsadd
      00262B C8               [12] 7203 	xch	a,r0
      00262C E5 10            [12] 7204 	mov	a,_bp
      00262E 24 05            [12] 7205 	add	a,#0x05
      002630 C8               [12] 7206 	xch	a,r0
      002631 A6 82            [24] 7207 	mov	@r0, dpl
      002633 08               [12] 7208 	inc	r0
      002634 A6 83            [24] 7209 	mov	@r0, dph
      002636 08               [12] 7210 	inc	r0
      002637 A6 F0            [24] 7211 	mov	@r0, b
      002639 08               [12] 7212 	inc	r0
      00263A F6               [12] 7213 	mov	@r0,a
      00263B E5 81            [12] 7214 	mov	a,sp
      00263D 24 FC            [12] 7215 	add	a,#0xfc
      00263F F5 81            [12] 7216 	mov	sp,a
      002641 E5 10            [12] 7217 	mov	a,_bp
      002643 24 F6            [12] 7218 	add	a,#0xf6
      002645 F8               [12] 7219 	mov	r0,a
      002646 E6               [12] 7220 	mov	a,@r0
      002647 C0 E0            [24] 7221 	push	acc
      002649 08               [12] 7222 	inc	r0
      00264A E6               [12] 7223 	mov	a,@r0
      00264B C0 E0            [24] 7224 	push	acc
      00264D 08               [12] 7225 	inc	r0
      00264E E6               [12] 7226 	mov	a,@r0
      00264F C0 E0            [24] 7227 	push	acc
      002651 08               [12] 7228 	inc	r0
      002652 E6               [12] 7229 	mov	a,@r0
      002653 C0 E0            [24] 7230 	push	acc
      002655 E5 10            [12] 7231 	mov	a,_bp
      002657 24 FA            [12] 7232 	add	a,#0xfa
      002659 F8               [12] 7233 	mov	r0,a
      00265A E6               [12] 7234 	mov	a,@r0
      00265B C0 E0            [24] 7235 	push	acc
      00265D 08               [12] 7236 	inc	r0
      00265E E6               [12] 7237 	mov	a,@r0
      00265F C0 E0            [24] 7238 	push	acc
      002661 08               [12] 7239 	inc	r0
      002662 E6               [12] 7240 	mov	a,@r0
      002663 C0 E0            [24] 7241 	push	acc
      002665 08               [12] 7242 	inc	r0
      002666 E6               [12] 7243 	mov	a,@r0
      002667 C0 E0            [24] 7244 	push	acc
      002669 A8 10            [24] 7245 	mov	r0,_bp
      00266B 08               [12] 7246 	inc	r0
      00266C 86 82            [24] 7247 	mov	dpl, @r0
      00266E 08               [12] 7248 	inc	r0
      00266F 86 83            [24] 7249 	mov	dph, @r0
      002671 08               [12] 7250 	inc	r0
      002672 86 F0            [24] 7251 	mov	b, @r0
      002674 08               [12] 7252 	inc	r0
      002675 E6               [12] 7253 	mov	a, @r0
      002676 12 1E 7F         [24] 7254 	lcall	_response_cooling
      002679 AA 82            [24] 7255 	mov	r2, dpl
      00267B AB 83            [24] 7256 	mov	r3, dph
      00267D AE F0            [24] 7257 	mov	r6, b
      00267F FF               [12] 7258 	mov	r7, a
      002680 E5 81            [12] 7259 	mov	a,sp
      002682 24 F8            [12] 7260 	add	a,#0xf8
      002684 F5 81            [12] 7261 	mov	sp,a
      002686 C0 02            [24] 7262 	push	ar2
      002688 C0 03            [24] 7263 	push	ar3
      00268A C0 06            [24] 7264 	push	ar6
      00268C C0 07            [24] 7265 	push	ar7
      00268E E5 10            [12] 7266 	mov	a,_bp
      002690 24 29            [12] 7267 	add	a,#0x29
      002692 F8               [12] 7268 	mov	r0,a
      002693 86 82            [24] 7269 	mov	dpl, @r0
      002695 08               [12] 7270 	inc	r0
      002696 86 83            [24] 7271 	mov	dph, @r0
      002698 08               [12] 7272 	inc	r0
      002699 86 F0            [24] 7273 	mov	b, @r0
      00269B 08               [12] 7274 	inc	r0
      00269C E6               [12] 7275 	mov	a, @r0
      00269D 12 2A B5         [24] 7276 	lcall	___fsmul
      0026A0 AC 82            [24] 7277 	mov	r4, dpl
      0026A2 AD 83            [24] 7278 	mov	r5, dph
      0026A4 AE F0            [24] 7279 	mov	r6, b
      0026A6 FF               [12] 7280 	mov	r7, a
      0026A7 E5 81            [12] 7281 	mov	a,sp
      0026A9 24 FC            [12] 7282 	add	a,#0xfc
      0026AB F5 81            [12] 7283 	mov	sp,a
      0026AD C0 04            [24] 7284 	push	ar4
      0026AF C0 05            [24] 7285 	push	ar5
      0026B1 C0 06            [24] 7286 	push	ar6
      0026B3 C0 07            [24] 7287 	push	ar7
      0026B5 E5 10            [12] 7288 	mov	a,_bp
      0026B7 24 05            [12] 7289 	add	a,#0x05
      0026B9 F8               [12] 7290 	mov	r0,a
      0026BA 86 82            [24] 7291 	mov	dpl, @r0
      0026BC 08               [12] 7292 	inc	r0
      0026BD 86 83            [24] 7293 	mov	dph, @r0
      0026BF 08               [12] 7294 	inc	r0
      0026C0 86 F0            [24] 7295 	mov	b, @r0
      0026C2 08               [12] 7296 	inc	r0
      0026C3 E6               [12] 7297 	mov	a, @r0
      0026C4 12 2C 15         [24] 7298 	lcall	___fsadd
      0026C7 C8               [12] 7299 	xch	a,r0
      0026C8 E5 10            [12] 7300 	mov	a,_bp
      0026CA 24 05            [12] 7301 	add	a,#0x05
      0026CC C8               [12] 7302 	xch	a,r0
      0026CD A6 82            [24] 7303 	mov	@r0, dpl
      0026CF 08               [12] 7304 	inc	r0
      0026D0 A6 83            [24] 7305 	mov	@r0, dph
      0026D2 08               [12] 7306 	inc	r0
      0026D3 A6 F0            [24] 7307 	mov	@r0, b
      0026D5 08               [12] 7308 	inc	r0
      0026D6 F6               [12] 7309 	mov	@r0,a
      0026D7 E5 81            [12] 7310 	mov	a,sp
      0026D9 24 FC            [12] 7311 	add	a,#0xfc
      0026DB F5 81            [12] 7312 	mov	sp,a
      0026DD E5 10            [12] 7313 	mov	a,_bp
      0026DF 24 F6            [12] 7314 	add	a,#0xf6
      0026E1 F8               [12] 7315 	mov	r0,a
      0026E2 E6               [12] 7316 	mov	a,@r0
      0026E3 C0 E0            [24] 7317 	push	acc
      0026E5 08               [12] 7318 	inc	r0
      0026E6 E6               [12] 7319 	mov	a,@r0
      0026E7 C0 E0            [24] 7320 	push	acc
      0026E9 08               [12] 7321 	inc	r0
      0026EA E6               [12] 7322 	mov	a,@r0
      0026EB C0 E0            [24] 7323 	push	acc
      0026ED 08               [12] 7324 	inc	r0
      0026EE E6               [12] 7325 	mov	a,@r0
      0026EF C0 E0            [24] 7326 	push	acc
      0026F1 E5 10            [12] 7327 	mov	a,_bp
      0026F3 24 FA            [12] 7328 	add	a,#0xfa
      0026F5 F8               [12] 7329 	mov	r0,a
      0026F6 E6               [12] 7330 	mov	a,@r0
      0026F7 C0 E0            [24] 7331 	push	acc
      0026F9 08               [12] 7332 	inc	r0
      0026FA E6               [12] 7333 	mov	a,@r0
      0026FB C0 E0            [24] 7334 	push	acc
      0026FD 08               [12] 7335 	inc	r0
      0026FE E6               [12] 7336 	mov	a,@r0
      0026FF C0 E0            [24] 7337 	push	acc
      002701 08               [12] 7338 	inc	r0
      002702 E6               [12] 7339 	mov	a,@r0
      002703 C0 E0            [24] 7340 	push	acc
      002705 A8 10            [24] 7341 	mov	r0,_bp
      002707 08               [12] 7342 	inc	r0
      002708 86 82            [24] 7343 	mov	dpl, @r0
      00270A 08               [12] 7344 	inc	r0
      00270B 86 83            [24] 7345 	mov	dph, @r0
      00270D 08               [12] 7346 	inc	r0
      00270E 86 F0            [24] 7347 	mov	b, @r0
      002710 08               [12] 7348 	inc	r0
      002711 E6               [12] 7349 	mov	a, @r0
      002712 12 1F 8F         [24] 7350 	lcall	_response_heavy_load
      002715 AA 82            [24] 7351 	mov	r2, dpl
      002717 AB 83            [24] 7352 	mov	r3, dph
      002719 AE F0            [24] 7353 	mov	r6, b
      00271B FF               [12] 7354 	mov	r7, a
      00271C E5 81            [12] 7355 	mov	a,sp
      00271E 24 F8            [12] 7356 	add	a,#0xf8
      002720 F5 81            [12] 7357 	mov	sp,a
      002722 C0 02            [24] 7358 	push	ar2
      002724 C0 03            [24] 7359 	push	ar3
      002726 C0 06            [24] 7360 	push	ar6
      002728 C0 07            [24] 7361 	push	ar7
      00272A E5 10            [12] 7362 	mov	a,_bp
      00272C 24 2D            [12] 7363 	add	a,#0x2d
      00272E F8               [12] 7364 	mov	r0,a
      00272F 86 82            [24] 7365 	mov	dpl, @r0
      002731 08               [12] 7366 	inc	r0
      002732 86 83            [24] 7367 	mov	dph, @r0
      002734 08               [12] 7368 	inc	r0
      002735 86 F0            [24] 7369 	mov	b, @r0
      002737 08               [12] 7370 	inc	r0
      002738 E6               [12] 7371 	mov	a, @r0
      002739 12 2A B5         [24] 7372 	lcall	___fsmul
      00273C AC 82            [24] 7373 	mov	r4, dpl
      00273E AD 83            [24] 7374 	mov	r5, dph
      002740 AE F0            [24] 7375 	mov	r6, b
      002742 FF               [12] 7376 	mov	r7, a
      002743 E5 81            [12] 7377 	mov	a,sp
      002745 24 FC            [12] 7378 	add	a,#0xfc
      002747 F5 81            [12] 7379 	mov	sp,a
      002749 C0 04            [24] 7380 	push	ar4
      00274B C0 05            [24] 7381 	push	ar5
      00274D C0 06            [24] 7382 	push	ar6
      00274F C0 07            [24] 7383 	push	ar7
      002751 E5 10            [12] 7384 	mov	a,_bp
      002753 24 05            [12] 7385 	add	a,#0x05
      002755 F8               [12] 7386 	mov	r0,a
      002756 86 82            [24] 7387 	mov	dpl, @r0
      002758 08               [12] 7388 	inc	r0
      002759 86 83            [24] 7389 	mov	dph, @r0
      00275B 08               [12] 7390 	inc	r0
      00275C 86 F0            [24] 7391 	mov	b, @r0
      00275E 08               [12] 7392 	inc	r0
      00275F E6               [12] 7393 	mov	a, @r0
      002760 12 2C 15         [24] 7394 	lcall	___fsadd
      002763 C8               [12] 7395 	xch	a,r0
      002764 E5 10            [12] 7396 	mov	a,_bp
      002766 24 05            [12] 7397 	add	a,#0x05
      002768 C8               [12] 7398 	xch	a,r0
      002769 A6 82            [24] 7399 	mov	@r0, dpl
      00276B 08               [12] 7400 	inc	r0
      00276C A6 83            [24] 7401 	mov	@r0, dph
      00276E 08               [12] 7402 	inc	r0
      00276F A6 F0            [24] 7403 	mov	@r0, b
      002771 08               [12] 7404 	inc	r0
      002772 F6               [12] 7405 	mov	@r0,a
      002773 E5 81            [12] 7406 	mov	a,sp
      002775 24 FC            [12] 7407 	add	a,#0xfc
      002777 F5 81            [12] 7408 	mov	sp,a
      002779 E5 10            [12] 7409 	mov	a,_bp
      00277B 24 F6            [12] 7410 	add	a,#0xf6
      00277D F8               [12] 7411 	mov	r0,a
      00277E E6               [12] 7412 	mov	a,@r0
      00277F C0 E0            [24] 7413 	push	acc
      002781 08               [12] 7414 	inc	r0
      002782 E6               [12] 7415 	mov	a,@r0
      002783 C0 E0            [24] 7416 	push	acc
      002785 08               [12] 7417 	inc	r0
      002786 E6               [12] 7418 	mov	a,@r0
      002787 C0 E0            [24] 7419 	push	acc
      002789 08               [12] 7420 	inc	r0
      00278A E6               [12] 7421 	mov	a,@r0
      00278B C0 E0            [24] 7422 	push	acc
      00278D E5 10            [12] 7423 	mov	a,_bp
      00278F 24 FA            [12] 7424 	add	a,#0xfa
      002791 F8               [12] 7425 	mov	r0,a
      002792 E6               [12] 7426 	mov	a,@r0
      002793 C0 E0            [24] 7427 	push	acc
      002795 08               [12] 7428 	inc	r0
      002796 E6               [12] 7429 	mov	a,@r0
      002797 C0 E0            [24] 7430 	push	acc
      002799 08               [12] 7431 	inc	r0
      00279A E6               [12] 7432 	mov	a,@r0
      00279B C0 E0            [24] 7433 	push	acc
      00279D 08               [12] 7434 	inc	r0
      00279E E6               [12] 7435 	mov	a,@r0
      00279F C0 E0            [24] 7436 	push	acc
      0027A1 A8 10            [24] 7437 	mov	r0,_bp
      0027A3 08               [12] 7438 	inc	r0
      0027A4 86 82            [24] 7439 	mov	dpl, @r0
      0027A6 08               [12] 7440 	inc	r0
      0027A7 86 83            [24] 7441 	mov	dph, @r0
      0027A9 08               [12] 7442 	inc	r0
      0027AA 86 F0            [24] 7443 	mov	b, @r0
      0027AC 08               [12] 7444 	inc	r0
      0027AD E6               [12] 7445 	mov	a, @r0
      0027AE 12 20 74         [24] 7446 	lcall	_response_protection
      0027B1 AA 82            [24] 7447 	mov	r2, dpl
      0027B3 AB 83            [24] 7448 	mov	r3, dph
      0027B5 AE F0            [24] 7449 	mov	r6, b
      0027B7 FF               [12] 7450 	mov	r7, a
      0027B8 E5 81            [12] 7451 	mov	a,sp
      0027BA 24 F8            [12] 7452 	add	a,#0xf8
      0027BC F5 81            [12] 7453 	mov	sp,a
      0027BE C0 02            [24] 7454 	push	ar2
      0027C0 C0 03            [24] 7455 	push	ar3
      0027C2 C0 06            [24] 7456 	push	ar6
      0027C4 C0 07            [24] 7457 	push	ar7
      0027C6 E5 10            [12] 7458 	mov	a,_bp
      0027C8 24 31            [12] 7459 	add	a,#0x31
      0027CA F8               [12] 7460 	mov	r0,a
      0027CB 86 82            [24] 7461 	mov	dpl, @r0
      0027CD 08               [12] 7462 	inc	r0
      0027CE 86 83            [24] 7463 	mov	dph, @r0
      0027D0 08               [12] 7464 	inc	r0
      0027D1 86 F0            [24] 7465 	mov	b, @r0
      0027D3 08               [12] 7466 	inc	r0
      0027D4 E6               [12] 7467 	mov	a, @r0
      0027D5 12 2A B5         [24] 7468 	lcall	___fsmul
      0027D8 AC 82            [24] 7469 	mov	r4, dpl
      0027DA AD 83            [24] 7470 	mov	r5, dph
      0027DC AE F0            [24] 7471 	mov	r6, b
      0027DE FF               [12] 7472 	mov	r7, a
      0027DF E5 81            [12] 7473 	mov	a,sp
      0027E1 24 FC            [12] 7474 	add	a,#0xfc
      0027E3 F5 81            [12] 7475 	mov	sp,a
      0027E5 C0 04            [24] 7476 	push	ar4
      0027E7 C0 05            [24] 7477 	push	ar5
      0027E9 C0 06            [24] 7478 	push	ar6
      0027EB C0 07            [24] 7479 	push	ar7
      0027ED E5 10            [12] 7480 	mov	a,_bp
      0027EF 24 05            [12] 7481 	add	a,#0x05
      0027F1 F8               [12] 7482 	mov	r0,a
      0027F2 86 82            [24] 7483 	mov	dpl, @r0
      0027F4 08               [12] 7484 	inc	r0
      0027F5 86 83            [24] 7485 	mov	dph, @r0
      0027F7 08               [12] 7486 	inc	r0
      0027F8 86 F0            [24] 7487 	mov	b, @r0
      0027FA 08               [12] 7488 	inc	r0
      0027FB E6               [12] 7489 	mov	a, @r0
      0027FC 12 2C 15         [24] 7490 	lcall	___fsadd
      0027FF C8               [12] 7491 	xch	a,r0
      002800 E5 10            [12] 7492 	mov	a,_bp
      002802 24 05            [12] 7493 	add	a,#0x05
      002804 C8               [12] 7494 	xch	a,r0
      002805 A6 82            [24] 7495 	mov	@r0, dpl
      002807 08               [12] 7496 	inc	r0
      002808 A6 83            [24] 7497 	mov	@r0, dph
      00280A 08               [12] 7498 	inc	r0
      00280B A6 F0            [24] 7499 	mov	@r0, b
      00280D 08               [12] 7500 	inc	r0
      00280E F6               [12] 7501 	mov	@r0,a
      00280F E5 81            [12] 7502 	mov	a,sp
      002811 24 FC            [12] 7503 	add	a,#0xfc
      002813 F5 81            [12] 7504 	mov	sp,a
      002815 E5 10            [12] 7505 	mov	a,_bp
      002817 24 21            [12] 7506 	add	a,#0x21
      002819 F8               [12] 7507 	mov	r0,a
      00281A E6               [12] 7508 	mov	a,@r0
      00281B C0 E0            [24] 7509 	push	acc
      00281D 08               [12] 7510 	inc	r0
      00281E E6               [12] 7511 	mov	a,@r0
      00281F C0 E0            [24] 7512 	push	acc
      002821 08               [12] 7513 	inc	r0
      002822 E6               [12] 7514 	mov	a,@r0
      002823 C0 E0            [24] 7515 	push	acc
      002825 08               [12] 7516 	inc	r0
      002826 E6               [12] 7517 	mov	a,@r0
      002827 C0 E0            [24] 7518 	push	acc
      002829 E5 10            [12] 7519 	mov	a,_bp
      00282B 24 1D            [12] 7520 	add	a,#0x1d
      00282D F8               [12] 7521 	mov	r0,a
      00282E 86 82            [24] 7522 	mov	dpl, @r0
      002830 08               [12] 7523 	inc	r0
      002831 86 83            [24] 7524 	mov	dph, @r0
      002833 08               [12] 7525 	inc	r0
      002834 86 F0            [24] 7526 	mov	b, @r0
      002836 08               [12] 7527 	inc	r0
      002837 E6               [12] 7528 	mov	a, @r0
      002838 12 2C 15         [24] 7529 	lcall	___fsadd
      00283B AA 82            [24] 7530 	mov	r2, dpl
      00283D AB 83            [24] 7531 	mov	r3, dph
      00283F AE F0            [24] 7532 	mov	r6, b
      002841 FF               [12] 7533 	mov	r7, a
      002842 E5 81            [12] 7534 	mov	a,sp
      002844 24 FC            [12] 7535 	add	a,#0xfc
      002846 F5 81            [12] 7536 	mov	sp,a
      002848 E5 10            [12] 7537 	mov	a,_bp
      00284A 24 25            [12] 7538 	add	a,#0x25
      00284C F8               [12] 7539 	mov	r0,a
      00284D E6               [12] 7540 	mov	a,@r0
      00284E C0 E0            [24] 7541 	push	acc
      002850 08               [12] 7542 	inc	r0
      002851 E6               [12] 7543 	mov	a,@r0
      002852 C0 E0            [24] 7544 	push	acc
      002854 08               [12] 7545 	inc	r0
      002855 E6               [12] 7546 	mov	a,@r0
      002856 C0 E0            [24] 7547 	push	acc
      002858 08               [12] 7548 	inc	r0
      002859 E6               [12] 7549 	mov	a,@r0
      00285A C0 E0            [24] 7550 	push	acc
      00285C 8A 82            [24] 7551 	mov	dpl, r2
      00285E 8B 83            [24] 7552 	mov	dph, r3
      002860 8E F0            [24] 7553 	mov	b, r6
      002862 EF               [12] 7554 	mov	a, r7
      002863 12 2C 15         [24] 7555 	lcall	___fsadd
      002866 AC 82            [24] 7556 	mov	r4, dpl
      002868 AD 83            [24] 7557 	mov	r5, dph
      00286A AE F0            [24] 7558 	mov	r6, b
      00286C FF               [12] 7559 	mov	r7, a
      00286D E5 81            [12] 7560 	mov	a,sp
      00286F 24 FC            [12] 7561 	add	a,#0xfc
      002871 F5 81            [12] 7562 	mov	sp,a
      002873 E5 10            [12] 7563 	mov	a,_bp
      002875 24 29            [12] 7564 	add	a,#0x29
      002877 F8               [12] 7565 	mov	r0,a
      002878 E6               [12] 7566 	mov	a,@r0
      002879 C0 E0            [24] 7567 	push	acc
      00287B 08               [12] 7568 	inc	r0
      00287C E6               [12] 7569 	mov	a,@r0
      00287D C0 E0            [24] 7570 	push	acc
      00287F 08               [12] 7571 	inc	r0
      002880 E6               [12] 7572 	mov	a,@r0
      002881 C0 E0            [24] 7573 	push	acc
      002883 08               [12] 7574 	inc	r0
      002884 E6               [12] 7575 	mov	a,@r0
      002885 C0 E0            [24] 7576 	push	acc
      002887 8C 82            [24] 7577 	mov	dpl, r4
      002889 8D 83            [24] 7578 	mov	dph, r5
      00288B 8E F0            [24] 7579 	mov	b, r6
      00288D EF               [12] 7580 	mov	a, r7
      00288E 12 2C 15         [24] 7581 	lcall	___fsadd
      002891 AC 82            [24] 7582 	mov	r4, dpl
      002893 AD 83            [24] 7583 	mov	r5, dph
      002895 AE F0            [24] 7584 	mov	r6, b
      002897 FF               [12] 7585 	mov	r7, a
      002898 E5 81            [12] 7586 	mov	a,sp
      00289A 24 FC            [12] 7587 	add	a,#0xfc
      00289C F5 81            [12] 7588 	mov	sp,a
      00289E E5 10            [12] 7589 	mov	a,_bp
      0028A0 24 2D            [12] 7590 	add	a,#0x2d
      0028A2 F8               [12] 7591 	mov	r0,a
      0028A3 E6               [12] 7592 	mov	a,@r0
      0028A4 C0 E0            [24] 7593 	push	acc
      0028A6 08               [12] 7594 	inc	r0
      0028A7 E6               [12] 7595 	mov	a,@r0
      0028A8 C0 E0            [24] 7596 	push	acc
      0028AA 08               [12] 7597 	inc	r0
      0028AB E6               [12] 7598 	mov	a,@r0
      0028AC C0 E0            [24] 7599 	push	acc
      0028AE 08               [12] 7600 	inc	r0
      0028AF E6               [12] 7601 	mov	a,@r0
      0028B0 C0 E0            [24] 7602 	push	acc
      0028B2 8C 82            [24] 7603 	mov	dpl, r4
      0028B4 8D 83            [24] 7604 	mov	dph, r5
      0028B6 8E F0            [24] 7605 	mov	b, r6
      0028B8 EF               [12] 7606 	mov	a, r7
      0028B9 12 2C 15         [24] 7607 	lcall	___fsadd
      0028BC AC 82            [24] 7608 	mov	r4, dpl
      0028BE AD 83            [24] 7609 	mov	r5, dph
      0028C0 AE F0            [24] 7610 	mov	r6, b
      0028C2 FF               [12] 7611 	mov	r7, a
      0028C3 E5 81            [12] 7612 	mov	a,sp
      0028C5 24 FC            [12] 7613 	add	a,#0xfc
      0028C7 F5 81            [12] 7614 	mov	sp,a
      0028C9 E5 10            [12] 7615 	mov	a,_bp
      0028CB 24 31            [12] 7616 	add	a,#0x31
      0028CD F8               [12] 7617 	mov	r0,a
      0028CE E6               [12] 7618 	mov	a,@r0
      0028CF C0 E0            [24] 7619 	push	acc
      0028D1 08               [12] 7620 	inc	r0
      0028D2 E6               [12] 7621 	mov	a,@r0
      0028D3 C0 E0            [24] 7622 	push	acc
      0028D5 08               [12] 7623 	inc	r0
      0028D6 E6               [12] 7624 	mov	a,@r0
      0028D7 C0 E0            [24] 7625 	push	acc
      0028D9 08               [12] 7626 	inc	r0
      0028DA E6               [12] 7627 	mov	a,@r0
      0028DB C0 E0            [24] 7628 	push	acc
      0028DD 8C 82            [24] 7629 	mov	dpl, r4
      0028DF 8D 83            [24] 7630 	mov	dph, r5
      0028E1 8E F0            [24] 7631 	mov	b, r6
      0028E3 EF               [12] 7632 	mov	a, r7
      0028E4 12 2C 15         [24] 7633 	lcall	___fsadd
      0028E7 AC 82            [24] 7634 	mov	r4, dpl
      0028E9 AD 83            [24] 7635 	mov	r5, dph
      0028EB AE F0            [24] 7636 	mov	r6, b
      0028ED FF               [12] 7637 	mov	r7, a
      0028EE E5 81            [12] 7638 	mov	a,sp
      0028F0 24 FC            [12] 7639 	add	a,#0xfc
      0028F2 F5 81            [12] 7640 	mov	sp,a
      0028F4 C0 04            [24] 7641 	push	ar4
      0028F6 C0 05            [24] 7642 	push	ar5
      0028F8 C0 06            [24] 7643 	push	ar6
      0028FA C0 07            [24] 7644 	push	ar7
      0028FC E5 10            [12] 7645 	mov	a,_bp
      0028FE 24 05            [12] 7646 	add	a,#0x05
      002900 F8               [12] 7647 	mov	r0,a
      002901 86 82            [24] 7648 	mov	dpl, @r0
      002903 08               [12] 7649 	inc	r0
      002904 86 83            [24] 7650 	mov	dph, @r0
      002906 08               [12] 7651 	inc	r0
      002907 86 F0            [24] 7652 	mov	b, @r0
      002909 08               [12] 7653 	inc	r0
      00290A E6               [12] 7654 	mov	a, @r0
      00290B 12 2D 2C         [24] 7655 	lcall	___fsdiv
      00290E AC 82            [24] 7656 	mov	r4, dpl
      002910 AD 83            [24] 7657 	mov	r5, dph
      002912 AE F0            [24] 7658 	mov	r6, b
      002914 FF               [12] 7659 	mov	r7, a
      002915 E5 81            [12] 7660 	mov	a,sp
      002917 24 FC            [12] 7661 	add	a,#0xfc
      002919 F5 81            [12] 7662 	mov	sp,a
      00291B 8C 82            [24] 7663 	mov	dpl, r4
      00291D 8D 83            [24] 7664 	mov	dph, r5
      00291F 8E F0            [24] 7665 	mov	b, r6
      002921 EF               [12] 7666 	mov	a, r7
                           002865  7667 	C$sugeno_demo.c$60$1_0$125 ==.
                                   7668 ;	../../sugeno_demo.c:60: }
      002922 85 10 81         [24] 7669 	mov	sp,_bp
      002925 D0 10            [24] 7670 	pop	_bp
                           00286A  7671 	C$sugeno_demo.c$60$1_0$125 ==.
                           00286A  7672 	XFsugeno_demo$calculate_fan_speed$0$0 ==.
      002927 22               [24] 7673 	ret
                                   7674 ;------------------------------------------------------------
                                   7675 ;Allocation info for local variables in function 'fan_speed_to_pwm'
                                   7676 ;------------------------------------------------------------
                                   7677 ;fan_speed     Allocated to registers r4 r5 r6 r7 
                                   7678 ;------------------------------------------------------------
                           00286B  7679 	Fsugeno_demo$fan_speed_to_pwm$0$0 ==.
                           00286B  7680 	C$sugeno_demo.c$62$1_0$127 ==.
                                   7681 ;	../../sugeno_demo.c:62: static unsigned char fan_speed_to_pwm(float fan_speed)
                                   7682 ;	-----------------------------------------
                                   7683 ;	 function fan_speed_to_pwm
                                   7684 ;	-----------------------------------------
      002928                       7685 _fan_speed_to_pwm:
      002928 AC 82            [24] 7686 	mov	r4,dpl
      00292A AD 83            [24] 7687 	mov	r5,dph
      00292C AE F0            [24] 7688 	mov	r6,b
      00292E FF               [12] 7689 	mov	r7,a
                           002872  7690 	C$sugeno_demo.c$64$1_0$127 ==.
                                   7691 ;	../../sugeno_demo.c:64: if (fan_speed <= 0.0f) return 0u;
      00292F C0 07            [24] 7692 	push	ar7
      002931 C0 06            [24] 7693 	push	ar6
      002933 C0 05            [24] 7694 	push	ar5
      002935 C0 04            [24] 7695 	push	ar4
      002937 C0 04            [24] 7696 	push	ar4
      002939 C0 05            [24] 7697 	push	ar5
      00293B C0 06            [24] 7698 	push	ar6
      00293D C0 07            [24] 7699 	push	ar7
      00293F 90 00 00         [24] 7700 	mov	dptr,#0x0000
      002942 E4               [12] 7701 	clr	a
      002943 F5 F0            [12] 7702 	mov	b,a
      002945 12 2B E5         [24] 7703 	lcall	___fslt
      002948 E5 81            [12] 7704 	mov	a,sp
      00294A 24 FC            [12] 7705 	add	a,#0xfc
      00294C F5 81            [12] 7706 	mov	sp,a
      00294E D0 04            [24] 7707 	pop	ar4
      002950 D0 05            [24] 7708 	pop	ar5
      002952 D0 06            [24] 7709 	pop	ar6
      002954 D0 07            [24] 7710 	pop	ar7
      002956 E5 82            [12] 7711 	mov	a, dpl
      002958 24 FF            [12] 7712 	add	a,#0xff
      00295A 92 00            [24] 7713 	mov	b0,c
      00295C 40 05            [24] 7714 	jc	00102$
      00295E 75 82 00         [24] 7715 	mov	dpl, #0x00
      002961 80 66            [24] 7716 	sjmp	00105$
      002963                       7717 00102$:
                           0028A6  7718 	C$sugeno_demo.c$65$1_0$127 ==.
                                   7719 ;	../../sugeno_demo.c:65: if (fan_speed >= 100.0f) return 100u;
      002963 C0 07            [24] 7720 	push	ar7
      002965 C0 06            [24] 7721 	push	ar6
      002967 C0 05            [24] 7722 	push	ar5
      002969 C0 04            [24] 7723 	push	ar4
      00296B E4               [12] 7724 	clr	a
      00296C C0 E0            [24] 7725 	push	acc
      00296E C0 E0            [24] 7726 	push	acc
      002970 74 C8            [12] 7727 	mov	a,#0xc8
      002972 C0 E0            [24] 7728 	push	acc
      002974 74 42            [12] 7729 	mov	a,#0x42
      002976 C0 E0            [24] 7730 	push	acc
      002978 8C 82            [24] 7731 	mov	dpl, r4
      00297A 8D 83            [24] 7732 	mov	dph, r5
      00297C 8E F0            [24] 7733 	mov	b, r6
      00297E EF               [12] 7734 	mov	a, r7
      00297F 12 2B E5         [24] 7735 	lcall	___fslt
      002982 E5 81            [12] 7736 	mov	a,sp
      002984 24 FC            [12] 7737 	add	a,#0xfc
      002986 F5 81            [12] 7738 	mov	sp,a
      002988 D0 04            [24] 7739 	pop	ar4
      00298A D0 05            [24] 7740 	pop	ar5
      00298C D0 06            [24] 7741 	pop	ar6
      00298E D0 07            [24] 7742 	pop	ar7
      002990 E5 82            [12] 7743 	mov	a, dpl
      002992 24 FF            [12] 7744 	add	a,#0xff
      002994 92 00            [24] 7745 	mov	b0,c
      002996 40 05            [24] 7746 	jc	00104$
      002998 75 82 64         [24] 7747 	mov	dpl, #0x64
      00299B 80 2C            [24] 7748 	sjmp	00105$
      00299D                       7749 00104$:
                           0028E0  7750 	C$sugeno_demo.c$66$1_0$127 ==.
                                   7751 ;	../../sugeno_demo.c:66: return (unsigned char)(fan_speed + 0.5f);
      00299D E4               [12] 7752 	clr	a
      00299E C0 E0            [24] 7753 	push	acc
      0029A0 C0 E0            [24] 7754 	push	acc
      0029A2 C0 E0            [24] 7755 	push	acc
      0029A4 74 3F            [12] 7756 	mov	a,#0x3f
      0029A6 C0 E0            [24] 7757 	push	acc
      0029A8 8C 82            [24] 7758 	mov	dpl, r4
      0029AA 8D 83            [24] 7759 	mov	dph, r5
      0029AC 8E F0            [24] 7760 	mov	b, r6
      0029AE EF               [12] 7761 	mov	a, r7
      0029AF 12 2C 15         [24] 7762 	lcall	___fsadd
      0029B2 AC 82            [24] 7763 	mov	r4, dpl
      0029B4 AD 83            [24] 7764 	mov	r5, dph
      0029B6 AE F0            [24] 7765 	mov	r6, b
      0029B8 FF               [12] 7766 	mov	r7, a
      0029B9 E5 81            [12] 7767 	mov	a,sp
      0029BB 24 FC            [12] 7768 	add	a,#0xfc
      0029BD F5 81            [12] 7769 	mov	sp,a
      0029BF 8C 82            [24] 7770 	mov	dpl, r4
      0029C1 8D 83            [24] 7771 	mov	dph, r5
      0029C3 8E F0            [24] 7772 	mov	b, r6
      0029C5 EF               [12] 7773 	mov	a, r7
      0029C6 12 2E 0B         [24] 7774 	lcall	___fs2uchar
      0029C9                       7775 00105$:
                           00290C  7776 	C$sugeno_demo.c$67$1_0$127 ==.
                                   7777 ;	../../sugeno_demo.c:67: }
                           00290C  7778 	C$sugeno_demo.c$67$1_0$127 ==.
                           00290C  7779 	XFsugeno_demo$fan_speed_to_pwm$0$0 ==.
      0029C9 22               [24] 7780 	ret
                                   7781 ;------------------------------------------------------------
                                   7782 ;Allocation info for local variables in function 'update_controller'
                                   7783 ;------------------------------------------------------------
                                   7784 ;load          Allocated to stack - _bp -3 +1 
                                   7785 ;vibration     Allocated to stack - _bp -4 +1 
                                   7786 ;temperature   Allocated to registers 
                                   7787 ;sloc0         Allocated to stack - _bp +1 +4 
                                   7788 ;sloc1         Allocated to stack - _bp +5 +4 
                                   7789 ;------------------------------------------------------------
                           00290D  7790 	Fsugeno_demo$update_controller$0$0 ==.
                           00290D  7791 	C$sugeno_demo.c$69$1_0$129 ==.
                                   7792 ;	../../sugeno_demo.c:69: static void update_controller(unsigned char temperature, unsigned char load, unsigned char vibration)
                                   7793 ;	-----------------------------------------
                                   7794 ;	 function update_controller
                                   7795 ;	-----------------------------------------
      0029CA                       7796 _update_controller:
      0029CA C0 10            [24] 7797 	push	_bp
      0029CC E5 81            [12] 7798 	mov	a,sp
      0029CE F5 10            [12] 7799 	mov	_bp,a
      0029D0 24 08            [12] 7800 	add	a,#0x08
      0029D2 F5 81            [12] 7801 	mov	sp,a
      0029D4 85 82 08         [24] 7802 	mov	_test_temperature,dpl
                           00291A  7803 	C$sugeno_demo.c$72$1_0$129 ==.
                                   7804 ;	../../sugeno_demo.c:72: test_load = load;
      0029D7 E5 10            [12] 7805 	mov	a,_bp
      0029D9 24 FD            [12] 7806 	add	a,#0xfd
      0029DB F8               [12] 7807 	mov	r0,a
      0029DC 86 09            [24] 7808 	mov	_test_load,@r0
                           002921  7809 	C$sugeno_demo.c$73$1_0$129 ==.
                                   7810 ;	../../sugeno_demo.c:73: test_vibration = vibration;
      0029DE E5 10            [12] 7811 	mov	a,_bp
      0029E0 24 FC            [12] 7812 	add	a,#0xfc
      0029E2 F8               [12] 7813 	mov	r0,a
      0029E3 86 0A            [24] 7814 	mov	_test_vibration,@r0
                           002928  7815 	C$sugeno_demo.c$74$1_0$129 ==.
                                   7816 ;	../../sugeno_demo.c:74: test_fan_speed = calculate_fan_speed((float)test_temperature, (float)test_load, (float)test_vibration);
      0029E5 85 0A 82         [24] 7817 	mov	dpl, _test_vibration
      0029E8 12 2E 13         [24] 7818 	lcall	___uchar2fs
      0029EB A8 10            [24] 7819 	mov	r0,_bp
      0029ED 08               [12] 7820 	inc	r0
      0029EE A6 82            [24] 7821 	mov	@r0, dpl
      0029F0 08               [12] 7822 	inc	r0
      0029F1 A6 83            [24] 7823 	mov	@r0, dph
      0029F3 08               [12] 7824 	inc	r0
      0029F4 A6 F0            [24] 7825 	mov	@r0, b
      0029F6 08               [12] 7826 	inc	r0
      0029F7 F6               [12] 7827 	mov	@r0,a
      0029F8 85 09 82         [24] 7828 	mov	dpl, _test_load
      0029FB 12 2E 13         [24] 7829 	lcall	___uchar2fs
      0029FE C8               [12] 7830 	xch	a,r0
      0029FF E5 10            [12] 7831 	mov	a,_bp
      002A01 24 05            [12] 7832 	add	a,#0x05
      002A03 C8               [12] 7833 	xch	a,r0
      002A04 A6 82            [24] 7834 	mov	@r0, dpl
      002A06 08               [12] 7835 	inc	r0
      002A07 A6 83            [24] 7836 	mov	@r0, dph
      002A09 08               [12] 7837 	inc	r0
      002A0A A6 F0            [24] 7838 	mov	@r0, b
      002A0C 08               [12] 7839 	inc	r0
      002A0D F6               [12] 7840 	mov	@r0,a
      002A0E 85 08 82         [24] 7841 	mov	dpl, _test_temperature
      002A11 12 2E 13         [24] 7842 	lcall	___uchar2fs
      002A14 AC 82            [24] 7843 	mov	r4, dpl
      002A16 AD 83            [24] 7844 	mov	r5, dph
      002A18 AE F0            [24] 7845 	mov	r6, b
      002A1A FF               [12] 7846 	mov	r7, a
      002A1B A8 10            [24] 7847 	mov	r0,_bp
      002A1D 08               [12] 7848 	inc	r0
      002A1E E6               [12] 7849 	mov	a,@r0
      002A1F C0 E0            [24] 7850 	push	acc
      002A21 08               [12] 7851 	inc	r0
      002A22 E6               [12] 7852 	mov	a,@r0
      002A23 C0 E0            [24] 7853 	push	acc
      002A25 08               [12] 7854 	inc	r0
      002A26 E6               [12] 7855 	mov	a,@r0
      002A27 C0 E0            [24] 7856 	push	acc
      002A29 08               [12] 7857 	inc	r0
      002A2A E6               [12] 7858 	mov	a,@r0
      002A2B C0 E0            [24] 7859 	push	acc
      002A2D E5 10            [12] 7860 	mov	a,_bp
      002A2F 24 05            [12] 7861 	add	a,#0x05
      002A31 F8               [12] 7862 	mov	r0,a
      002A32 E6               [12] 7863 	mov	a,@r0
      002A33 C0 E0            [24] 7864 	push	acc
      002A35 08               [12] 7865 	inc	r0
      002A36 E6               [12] 7866 	mov	a,@r0
      002A37 C0 E0            [24] 7867 	push	acc
      002A39 08               [12] 7868 	inc	r0
      002A3A E6               [12] 7869 	mov	a,@r0
      002A3B C0 E0            [24] 7870 	push	acc
      002A3D 08               [12] 7871 	inc	r0
      002A3E E6               [12] 7872 	mov	a,@r0
      002A3F C0 E0            [24] 7873 	push	acc
      002A41 8C 82            [24] 7874 	mov	dpl, r4
      002A43 8D 83            [24] 7875 	mov	dph, r5
      002A45 8E F0            [24] 7876 	mov	b, r6
      002A47 EF               [12] 7877 	mov	a, r7
      002A48 12 21 85         [24] 7878 	lcall	_calculate_fan_speed
      002A4B 85 82 0C         [24] 7879 	mov	_test_fan_speed,dpl
      002A4E 85 83 0D         [24] 7880 	mov	(_test_fan_speed + 1),dph
      002A51 85 F0 0E         [24] 7881 	mov	(_test_fan_speed + 2),b
      002A54 F5 0F            [12] 7882 	mov	(_test_fan_speed + 3),a
      002A56 E5 81            [12] 7883 	mov	a,sp
      002A58 24 F8            [12] 7884 	add	a,#0xf8
      002A5A F5 81            [12] 7885 	mov	sp,a
                           00299F  7886 	C$sugeno_demo.c$75$1_0$129 ==.
                                   7887 ;	../../sugeno_demo.c:75: test_pwm = fan_speed_to_pwm(test_fan_speed);
      002A5C 85 0C 82         [24] 7888 	mov	dpl, _test_fan_speed
      002A5F 85 0D 83         [24] 7889 	mov	dph, (_test_fan_speed + 1)
      002A62 85 0E F0         [24] 7890 	mov	b, (_test_fan_speed + 2)
      002A65 E5 0F            [12] 7891 	mov	a, (_test_fan_speed + 3)
      002A67 12 29 28         [24] 7892 	lcall	_fan_speed_to_pwm
      002A6A 85 82 0B         [24] 7893 	mov	_test_pwm,dpl
                           0029B0  7894 	C$sugeno_demo.c$76$1_0$129 ==.
                                   7895 ;	../../sugeno_demo.c:76: }
      002A6D 85 10 81         [24] 7896 	mov	sp,_bp
      002A70 D0 10            [24] 7897 	pop	_bp
                           0029B5  7898 	C$sugeno_demo.c$76$1_0$129 ==.
                           0029B5  7899 	XFsugeno_demo$update_controller$0$0 ==.
      002A72 22               [24] 7900 	ret
                                   7901 ;------------------------------------------------------------
                                   7902 ;Allocation info for local variables in function 'main'
                                   7903 ;------------------------------------------------------------
                           0029B6  7904 	G$main$0$0 ==.
                           0029B6  7905 	C$sugeno_demo.c$80$1_0$131 ==.
                                   7906 ;	../../sugeno_demo.c:80: void main(void)
                                   7907 ;	-----------------------------------------
                                   7908 ;	 function main
                                   7909 ;	-----------------------------------------
      002A73                       7910 _main:
                           0029B6  7911 	C$sugeno_demo.c$82$1_0$131 ==.
                                   7912 ;	../../sugeno_demo.c:82: P1 = 0x00u;
      002A73 75 90 00         [24] 7913 	mov	_P1,#0x00
      002A76                       7914 00107$:
                           0029B9  7915 	C$sugeno_demo.c$85$3_0$133 ==.
                                   7916 ;	../../sugeno_demo.c:85: test_vibration = P0;
      002A76 85 80 0A         [24] 7917 	mov	_test_vibration,_P0
                           0029BC  7918 	C$sugeno_demo.c$86$3_0$133 ==.
                                   7919 ;	../../sugeno_demo.c:86: test_temperature = P2;
      002A79 85 A0 08         [24] 7920 	mov	_test_temperature,_P2
                           0029BF  7921 	C$sugeno_demo.c$87$3_0$133 ==.
                                   7922 ;	../../sugeno_demo.c:87: test_load = P3;
      002A7C 85 B0 09         [24] 7923 	mov	_test_load,_P3
                           0029C2  7924 	C$sugeno_demo.c$89$3_0$133 ==.
                                   7925 ;	../../sugeno_demo.c:89: if (test_temperature > 100u || test_load > 100u || test_vibration > 10u) {
      002A7F E5 08            [12] 7926 	mov	a,_test_temperature
      002A81 24 9B            [12] 7927 	add	a,#0xff - 0x64
      002A83 40 0C            [24] 7928 	jc	00101$
      002A85 E5 09            [12] 7929 	mov	a,_test_load
      002A87 24 9B            [12] 7930 	add	a,#0xff - 0x64
      002A89 40 06            [24] 7931 	jc	00101$
      002A8B E5 0A            [12] 7932 	mov	a,_test_vibration
      002A8D 24 F5            [12] 7933 	add	a,#0xff - 0x0a
      002A8F 50 05            [24] 7934 	jnc	00102$
      002A91                       7935 00101$:
                           0029D4  7936 	C$sugeno_demo.c$90$4_0$134 ==.
                                   7937 ;	../../sugeno_demo.c:90: P1 = 0x00u;
      002A91 75 90 00         [24] 7938 	mov	_P1,#0x00
                           0029D7  7939 	C$sugeno_demo.c$91$4_0$134 ==.
                                   7940 ;	../../sugeno_demo.c:91: continue;
      002A94 80 E0            [24] 7941 	sjmp	00107$
      002A96                       7942 00102$:
                           0029D9  7943 	C$sugeno_demo.c$95$3_0$133 ==.
                                   7944 ;	../../sugeno_demo.c:95: test_temperature,
      002A96 C0 0A            [24] 7945 	push	_test_vibration
      002A98 C0 09            [24] 7946 	push	_test_load
      002A9A 85 08 82         [24] 7947 	mov	dpl, _test_temperature
      002A9D 12 29 CA         [24] 7948 	lcall	_update_controller
      002AA0 15 81            [12] 7949 	dec	sp
      002AA2 15 81            [12] 7950 	dec	sp
                           0029E7  7951 	C$sugeno_demo.c$100$3_0$133 ==.
                                   7952 ;	../../sugeno_demo.c:100: P1 = test_pwm;
      002AA4 85 0B 90         [24] 7953 	mov	_P1,_test_pwm
      002AA7 80 CD            [24] 7954 	sjmp	00107$
                           0029EC  7955 	C$sugeno_demo.c$102$2_0$131 ==.
                                   7956 ;	../../sugeno_demo.c:102: }
                           0029EC  7957 	C$sugeno_demo.c$102$2_0$131 ==.
                           0029EC  7958 	XG$main$0$0 ==.
      002AA9 22               [24] 7959 	ret
                                   7960 	.area CSEG    (CODE)
                                   7961 	.area CONST   (CODE)
                                   7962 	.area CONST   (CODE)
                           000000  7963 Fsugeno_demo$temperature_low_fuzzy_variable$0_0$0 == .
      002EB1                       7964 _temperature_low_fuzzy_variable:
      002EB1 00                    7965 	.db #0x00	; 0
      002EB2 01                    7966 	.db #0x01	; 1
      002EB3 00 00 70 41           7967 	.byte #0x00, #0x00, #0x70, #0x41	;  1.500000e+01
      002EB7 00 00 20 42           7968 	.byte #0x00, #0x00, #0x20, #0x42	;  4.000000e+01
      002EBB 00 00 00 00           7969 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
      002EBF 00 00 00 00           7970 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   7971 	.area CSEG    (CODE)
                                   7972 	.area CONST   (CODE)
                           000012  7973 Fsugeno_demo$temperature_high_fuzzy_variable$0_0$0 == .
      002EC3                       7974 _temperature_high_fuzzy_variable:
      002EC3 00                    7975 	.db #0x00	; 0
      002EC4 01                    7976 	.db #0x01	; 1
      002EC5 00 00 0C 42           7977 	.byte #0x00, #0x00, #0x0c, #0x42	;  3.500000e+01
      002EC9 00 00 96 42           7978 	.byte #0x00, #0x00, #0x96, #0x42	;  7.500000e+01
      002ECD 00 00 80 3F           7979 	.byte #0x00, #0x00, #0x80, #0x3f	;  1.000000e+00
      002ED1 00 00 00 00           7980 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   7981 	.area CSEG    (CODE)
                                   7982 	.area CONST   (CODE)
                           000024  7983 Fsugeno_demo$load_low_fuzzy_variable$0_0$0 == .
      002ED5                       7984 _load_low_fuzzy_variable:
      002ED5 00                    7985 	.db #0x00	; 0
      002ED6 01                    7986 	.db #0x01	; 1
      002ED7 00 00 A0 41           7987 	.byte #0x00, #0x00, #0xa0, #0x41	;  2.000000e+01
      002EDB 00 00 48 42           7988 	.byte #0x00, #0x00, #0x48, #0x42	;  5.000000e+01
      002EDF 00 00 00 00           7989 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
      002EE3 00 00 00 00           7990 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   7991 	.area CSEG    (CODE)
                                   7992 	.area CONST   (CODE)
                           000036  7993 Fsugeno_demo$load_high_fuzzy_variable$0_0$0 == .
      002EE7                       7994 _load_high_fuzzy_variable:
      002EE7 00                    7995 	.db #0x00	; 0
      002EE8 01                    7996 	.db #0x01	; 1
      002EE9 00 00 34 42           7997 	.byte #0x00, #0x00, #0x34, #0x42	;  4.500000e+01
      002EED 00 00 AA 42           7998 	.byte #0x00, #0x00, #0xaa, #0x42	;  8.500000e+01
      002EF1 00 00 80 3F           7999 	.byte #0x00, #0x00, #0x80, #0x3f	;  1.000000e+00
      002EF5 00 00 00 00           8000 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   8001 	.area CSEG    (CODE)
                                   8002 	.area CONST   (CODE)
                           000048  8003 Fsugeno_demo$vibration_low_fuzzy_variable$0_0$0 == .
      002EF9                       8004 _vibration_low_fuzzy_variable:
      002EF9 00                    8005 	.db #0x00	; 0
      002EFA 01                    8006 	.db #0x01	; 1
      002EFB 00 00 80 3F           8007 	.byte #0x00, #0x00, #0x80, #0x3f	;  1.000000e+00
      002EFF 00 00 80 40           8008 	.byte #0x00, #0x00, #0x80, #0x40	;  4.000000e+00
      002F03 00 00 00 00           8009 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
      002F07 00 00 00 00           8010 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   8011 	.area CSEG    (CODE)
                                   8012 	.area CONST   (CODE)
                           00005A  8013 Fsugeno_demo$vibration_high_fuzzy_variable$0_0$0 == .
      002F0B                       8014 _vibration_high_fuzzy_variable:
      002F0B 00                    8015 	.db #0x00	; 0
      002F0C 01                    8016 	.db #0x01	; 1
      002F0D 00 00 40 40           8017 	.byte #0x00, #0x00, #0x40, #0x40	;  3.000000e+00
      002F11 00 00 00 41           8018 	.byte #0x00, #0x00, #0x00, #0x41	;  8.000000e+00
      002F15 00 00 80 3F           8019 	.byte #0x00, #0x00, #0x80, #0x3f	;  1.000000e+00
      002F19 00 00 00 00           8020 	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
                                   8021 	.area CSEG    (CODE)
                                   8022 	.area XINIT   (CODE)
                                   8023 	.area CABS    (ABS,CODE)
