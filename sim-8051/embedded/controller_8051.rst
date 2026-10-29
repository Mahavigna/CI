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
                                    135 	.globl _fuzzy_sugeno_weighted_average
                                    136 	.globl _fuzzy_sugeno_weighted_sum
                                    137 	.globl _fuzzy_ramp
                                    138 	.globl _fuzzy_rules_create
                                    139 	.globl _fuzzy_rules_add
                                    140 	.globl _fuzzy_rules_cog
                                    141 	.globl _fuzzy_rules_free
                                    142 ;--------------------------------------------------------
                                    143 ; special function registers
                                    144 ;--------------------------------------------------------
                                    145 	.area RSEG    (ABS,DATA)
      000000                        146 	.org 0x0000
                           000080   147 G$P0$0_0$0 == 0x0080
                           000080   148 _P0	=	0x0080
                           000081   149 G$SP$0_0$0 == 0x0081
                           000081   150 _SP	=	0x0081
                           000082   151 G$DPL$0_0$0 == 0x0082
                           000082   152 _DPL	=	0x0082
                           000083   153 G$DPH$0_0$0 == 0x0083
                           000083   154 _DPH	=	0x0083
                           000087   155 G$PCON$0_0$0 == 0x0087
                           000087   156 _PCON	=	0x0087
                           000088   157 G$TCON$0_0$0 == 0x0088
                           000088   158 _TCON	=	0x0088
                           000089   159 G$TMOD$0_0$0 == 0x0089
                           000089   160 _TMOD	=	0x0089
                           00008A   161 G$TL0$0_0$0 == 0x008a
                           00008A   162 _TL0	=	0x008a
                           00008B   163 G$TL1$0_0$0 == 0x008b
                           00008B   164 _TL1	=	0x008b
                           00008C   165 G$TH0$0_0$0 == 0x008c
                           00008C   166 _TH0	=	0x008c
                           00008D   167 G$TH1$0_0$0 == 0x008d
                           00008D   168 _TH1	=	0x008d
                           000090   169 G$P1$0_0$0 == 0x0090
                           000090   170 _P1	=	0x0090
                           000098   171 G$SCON$0_0$0 == 0x0098
                           000098   172 _SCON	=	0x0098
                           000099   173 G$SBUF$0_0$0 == 0x0099
                           000099   174 _SBUF	=	0x0099
                           0000A0   175 G$P2$0_0$0 == 0x00a0
                           0000A0   176 _P2	=	0x00a0
                           0000A8   177 G$IE$0_0$0 == 0x00a8
                           0000A8   178 _IE	=	0x00a8
                           0000B0   179 G$P3$0_0$0 == 0x00b0
                           0000B0   180 _P3	=	0x00b0
                           0000B8   181 G$IP$0_0$0 == 0x00b8
                           0000B8   182 _IP	=	0x00b8
                           0000D0   183 G$PSW$0_0$0 == 0x00d0
                           0000D0   184 _PSW	=	0x00d0
                           0000E0   185 G$ACC$0_0$0 == 0x00e0
                           0000E0   186 _ACC	=	0x00e0
                           0000F0   187 G$B$0_0$0 == 0x00f0
                           0000F0   188 _B	=	0x00f0
                           0000C8   189 G$T2CON$0_0$0 == 0x00c8
                           0000C8   190 _T2CON	=	0x00c8
                           0000CA   191 G$RCAP2L$0_0$0 == 0x00ca
                           0000CA   192 _RCAP2L	=	0x00ca
                           0000CB   193 G$RCAP2H$0_0$0 == 0x00cb
                           0000CB   194 _RCAP2H	=	0x00cb
                           0000CC   195 G$TL2$0_0$0 == 0x00cc
                           0000CC   196 _TL2	=	0x00cc
                           0000CD   197 G$TH2$0_0$0 == 0x00cd
                           0000CD   198 _TH2	=	0x00cd
                                    199 ;--------------------------------------------------------
                                    200 ; special function bits
                                    201 ;--------------------------------------------------------
                                    202 	.area RSEG    (ABS,DATA)
      000000                        203 	.org 0x0000
                           000080   204 G$P0_0$0_0$0 == 0x0080
                           000080   205 _P0_0	=	0x0080
                           000081   206 G$P0_1$0_0$0 == 0x0081
                           000081   207 _P0_1	=	0x0081
                           000082   208 G$P0_2$0_0$0 == 0x0082
                           000082   209 _P0_2	=	0x0082
                           000083   210 G$P0_3$0_0$0 == 0x0083
                           000083   211 _P0_3	=	0x0083
                           000084   212 G$P0_4$0_0$0 == 0x0084
                           000084   213 _P0_4	=	0x0084
                           000085   214 G$P0_5$0_0$0 == 0x0085
                           000085   215 _P0_5	=	0x0085
                           000086   216 G$P0_6$0_0$0 == 0x0086
                           000086   217 _P0_6	=	0x0086
                           000087   218 G$P0_7$0_0$0 == 0x0087
                           000087   219 _P0_7	=	0x0087
                           000088   220 G$IT0$0_0$0 == 0x0088
                           000088   221 _IT0	=	0x0088
                           000089   222 G$IE0$0_0$0 == 0x0089
                           000089   223 _IE0	=	0x0089
                           00008A   224 G$IT1$0_0$0 == 0x008a
                           00008A   225 _IT1	=	0x008a
                           00008B   226 G$IE1$0_0$0 == 0x008b
                           00008B   227 _IE1	=	0x008b
                           00008C   228 G$TR0$0_0$0 == 0x008c
                           00008C   229 _TR0	=	0x008c
                           00008D   230 G$TF0$0_0$0 == 0x008d
                           00008D   231 _TF0	=	0x008d
                           00008E   232 G$TR1$0_0$0 == 0x008e
                           00008E   233 _TR1	=	0x008e
                           00008F   234 G$TF1$0_0$0 == 0x008f
                           00008F   235 _TF1	=	0x008f
                           000090   236 G$P1_0$0_0$0 == 0x0090
                           000090   237 _P1_0	=	0x0090
                           000091   238 G$P1_1$0_0$0 == 0x0091
                           000091   239 _P1_1	=	0x0091
                           000092   240 G$P1_2$0_0$0 == 0x0092
                           000092   241 _P1_2	=	0x0092
                           000093   242 G$P1_3$0_0$0 == 0x0093
                           000093   243 _P1_3	=	0x0093
                           000094   244 G$P1_4$0_0$0 == 0x0094
                           000094   245 _P1_4	=	0x0094
                           000095   246 G$P1_5$0_0$0 == 0x0095
                           000095   247 _P1_5	=	0x0095
                           000096   248 G$P1_6$0_0$0 == 0x0096
                           000096   249 _P1_6	=	0x0096
                           000097   250 G$P1_7$0_0$0 == 0x0097
                           000097   251 _P1_7	=	0x0097
                           000098   252 G$RI$0_0$0 == 0x0098
                           000098   253 _RI	=	0x0098
                           000099   254 G$TI$0_0$0 == 0x0099
                           000099   255 _TI	=	0x0099
                           00009A   256 G$RB8$0_0$0 == 0x009a
                           00009A   257 _RB8	=	0x009a
                           00009B   258 G$TB8$0_0$0 == 0x009b
                           00009B   259 _TB8	=	0x009b
                           00009C   260 G$REN$0_0$0 == 0x009c
                           00009C   261 _REN	=	0x009c
                           00009D   262 G$SM2$0_0$0 == 0x009d
                           00009D   263 _SM2	=	0x009d
                           00009E   264 G$SM1$0_0$0 == 0x009e
                           00009E   265 _SM1	=	0x009e
                           00009F   266 G$SM0$0_0$0 == 0x009f
                           00009F   267 _SM0	=	0x009f
                           0000A0   268 G$P2_0$0_0$0 == 0x00a0
                           0000A0   269 _P2_0	=	0x00a0
                           0000A1   270 G$P2_1$0_0$0 == 0x00a1
                           0000A1   271 _P2_1	=	0x00a1
                           0000A2   272 G$P2_2$0_0$0 == 0x00a2
                           0000A2   273 _P2_2	=	0x00a2
                           0000A3   274 G$P2_3$0_0$0 == 0x00a3
                           0000A3   275 _P2_3	=	0x00a3
                           0000A4   276 G$P2_4$0_0$0 == 0x00a4
                           0000A4   277 _P2_4	=	0x00a4
                           0000A5   278 G$P2_5$0_0$0 == 0x00a5
                           0000A5   279 _P2_5	=	0x00a5
                           0000A6   280 G$P2_6$0_0$0 == 0x00a6
                           0000A6   281 _P2_6	=	0x00a6
                           0000A7   282 G$P2_7$0_0$0 == 0x00a7
                           0000A7   283 _P2_7	=	0x00a7
                           0000A8   284 G$EX0$0_0$0 == 0x00a8
                           0000A8   285 _EX0	=	0x00a8
                           0000A9   286 G$ET0$0_0$0 == 0x00a9
                           0000A9   287 _ET0	=	0x00a9
                           0000AA   288 G$EX1$0_0$0 == 0x00aa
                           0000AA   289 _EX1	=	0x00aa
                           0000AB   290 G$ET1$0_0$0 == 0x00ab
                           0000AB   291 _ET1	=	0x00ab
                           0000AC   292 G$ES$0_0$0 == 0x00ac
                           0000AC   293 _ES	=	0x00ac
                           0000AF   294 G$EA$0_0$0 == 0x00af
                           0000AF   295 _EA	=	0x00af
                           0000B0   296 G$P3_0$0_0$0 == 0x00b0
                           0000B0   297 _P3_0	=	0x00b0
                           0000B1   298 G$P3_1$0_0$0 == 0x00b1
                           0000B1   299 _P3_1	=	0x00b1
                           0000B2   300 G$P3_2$0_0$0 == 0x00b2
                           0000B2   301 _P3_2	=	0x00b2
                           0000B3   302 G$P3_3$0_0$0 == 0x00b3
                           0000B3   303 _P3_3	=	0x00b3
                           0000B4   304 G$P3_4$0_0$0 == 0x00b4
                           0000B4   305 _P3_4	=	0x00b4
                           0000B5   306 G$P3_5$0_0$0 == 0x00b5
                           0000B5   307 _P3_5	=	0x00b5
                           0000B6   308 G$P3_6$0_0$0 == 0x00b6
                           0000B6   309 _P3_6	=	0x00b6
                           0000B7   310 G$P3_7$0_0$0 == 0x00b7
                           0000B7   311 _P3_7	=	0x00b7
                           0000B0   312 G$RXD$0_0$0 == 0x00b0
                           0000B0   313 _RXD	=	0x00b0
                           0000B1   314 G$TXD$0_0$0 == 0x00b1
                           0000B1   315 _TXD	=	0x00b1
                           0000B2   316 G$INT0$0_0$0 == 0x00b2
                           0000B2   317 _INT0	=	0x00b2
                           0000B3   318 G$INT1$0_0$0 == 0x00b3
                           0000B3   319 _INT1	=	0x00b3
                           0000B4   320 G$T0$0_0$0 == 0x00b4
                           0000B4   321 _T0	=	0x00b4
                           0000B5   322 G$T1$0_0$0 == 0x00b5
                           0000B5   323 _T1	=	0x00b5
                           0000B6   324 G$WR$0_0$0 == 0x00b6
                           0000B6   325 _WR	=	0x00b6
                           0000B7   326 G$RD$0_0$0 == 0x00b7
                           0000B7   327 _RD	=	0x00b7
                           0000B8   328 G$PX0$0_0$0 == 0x00b8
                           0000B8   329 _PX0	=	0x00b8
                           0000B9   330 G$PT0$0_0$0 == 0x00b9
                           0000B9   331 _PT0	=	0x00b9
                           0000BA   332 G$PX1$0_0$0 == 0x00ba
                           0000BA   333 _PX1	=	0x00ba
                           0000BB   334 G$PT1$0_0$0 == 0x00bb
                           0000BB   335 _PT1	=	0x00bb
                           0000BC   336 G$PS$0_0$0 == 0x00bc
                           0000BC   337 _PS	=	0x00bc
                           0000D0   338 G$P$0_0$0 == 0x00d0
                           0000D0   339 _P	=	0x00d0
                           0000D1   340 G$F1$0_0$0 == 0x00d1
                           0000D1   341 _F1	=	0x00d1
                           0000D2   342 G$OV$0_0$0 == 0x00d2
                           0000D2   343 _OV	=	0x00d2
                           0000D3   344 G$RS0$0_0$0 == 0x00d3
                           0000D3   345 _RS0	=	0x00d3
                           0000D4   346 G$RS1$0_0$0 == 0x00d4
                           0000D4   347 _RS1	=	0x00d4
                           0000D5   348 G$F0$0_0$0 == 0x00d5
                           0000D5   349 _F0	=	0x00d5
                           0000D6   350 G$AC$0_0$0 == 0x00d6
                           0000D6   351 _AC	=	0x00d6
                           0000D7   352 G$CY$0_0$0 == 0x00d7
                           0000D7   353 _CY	=	0x00d7
                           0000AD   354 G$ET2$0_0$0 == 0x00ad
                           0000AD   355 _ET2	=	0x00ad
                           0000BD   356 G$PT2$0_0$0 == 0x00bd
                           0000BD   357 _PT2	=	0x00bd
                           0000C8   358 G$T2CON_0$0_0$0 == 0x00c8
                           0000C8   359 _T2CON_0	=	0x00c8
                           0000C9   360 G$T2CON_1$0_0$0 == 0x00c9
                           0000C9   361 _T2CON_1	=	0x00c9
                           0000CA   362 G$T2CON_2$0_0$0 == 0x00ca
                           0000CA   363 _T2CON_2	=	0x00ca
                           0000CB   364 G$T2CON_3$0_0$0 == 0x00cb
                           0000CB   365 _T2CON_3	=	0x00cb
                           0000CC   366 G$T2CON_4$0_0$0 == 0x00cc
                           0000CC   367 _T2CON_4	=	0x00cc
                           0000CD   368 G$T2CON_5$0_0$0 == 0x00cd
                           0000CD   369 _T2CON_5	=	0x00cd
                           0000CE   370 G$T2CON_6$0_0$0 == 0x00ce
                           0000CE   371 _T2CON_6	=	0x00ce
                           0000CF   372 G$T2CON_7$0_0$0 == 0x00cf
                           0000CF   373 _T2CON_7	=	0x00cf
                           0000C8   374 G$CP_RL2$0_0$0 == 0x00c8
                           0000C8   375 _CP_RL2	=	0x00c8
                           0000C9   376 G$C_T2$0_0$0 == 0x00c9
                           0000C9   377 _C_T2	=	0x00c9
                           0000CA   378 G$TR2$0_0$0 == 0x00ca
                           0000CA   379 _TR2	=	0x00ca
                           0000CB   380 G$EXEN2$0_0$0 == 0x00cb
                           0000CB   381 _EXEN2	=	0x00cb
                           0000CC   382 G$TCLK$0_0$0 == 0x00cc
                           0000CC   383 _TCLK	=	0x00cc
                           0000CD   384 G$RCLK$0_0$0 == 0x00cd
                           0000CD   385 _RCLK	=	0x00cd
                           0000CE   386 G$EXF2$0_0$0 == 0x00ce
                           0000CE   387 _EXF2	=	0x00ce
                           0000CF   388 G$TF2$0_0$0 == 0x00cf
                           0000CF   389 _TF2	=	0x00cf
                                    390 ;--------------------------------------------------------
                                    391 ; overlayable register banks
                                    392 ;--------------------------------------------------------
                                    393 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        394 	.ds 8
                                    395 ;--------------------------------------------------------
                                    396 ; overlayable bit register bank
                                    397 ;--------------------------------------------------------
                                    398 	.area BIT_BANK	(REL,OVR,DATA)
      000020                        399 bits:
      000020                        400 	.ds 1
                           008000   401 	b0 = bits[0]
                           008100   402 	b1 = bits[1]
                           008200   403 	b2 = bits[2]
                           008300   404 	b3 = bits[3]
                           008400   405 	b4 = bits[4]
                           008500   406 	b5 = bits[5]
                           008600   407 	b6 = bits[6]
                           008700   408 	b7 = bits[7]
                                    409 ;--------------------------------------------------------
                                    410 ; internal ram data
                                    411 ;--------------------------------------------------------
                                    412 	.area DSEG    (DATA)
                           000000   413 G$test_temperature$0_0$0==.
      000008                        414 _test_temperature::
      000008                        415 	.ds 1
                           000001   416 G$test_pwm$0_0$0==.
      000009                        417 _test_pwm::
      000009                        418 	.ds 1
                           000002   419 G$test_fan_speed$0_0$0==.
      00000A                        420 _test_fan_speed::
      00000A                        421 	.ds 4
                                    422 ;--------------------------------------------------------
                                    423 ; overlayable items in internal ram
                                    424 ;--------------------------------------------------------
                                    425 ;--------------------------------------------------------
                                    426 ; Stack segment in internal ram
                                    427 ;--------------------------------------------------------
                                    428 	.area SSEG
      000021                        429 __start__stack:
      000021                        430 	.ds	1
                                    431 
                                    432 ;--------------------------------------------------------
                                    433 ; indirectly addressable internal ram data
                                    434 ;--------------------------------------------------------
                                    435 	.area ISEG    (DATA)
                                    436 ;--------------------------------------------------------
                                    437 ; absolute internal ram data
                                    438 ;--------------------------------------------------------
                                    439 	.area IABS    (ABS,DATA)
                                    440 	.area IABS    (ABS,DATA)
                                    441 ;--------------------------------------------------------
                                    442 ; bit data
                                    443 ;--------------------------------------------------------
                                    444 	.area BSEG    (BIT)
                                    445 ;--------------------------------------------------------
                                    446 ; paged external ram data
                                    447 ;--------------------------------------------------------
                                    448 	.area PSEG    (PAG,XDATA)
                                    449 ;--------------------------------------------------------
                                    450 ; uninitialized external ram data
                                    451 ;--------------------------------------------------------
                                    452 	.area XSEG    (XDATA)
                                    453 ;--------------------------------------------------------
                                    454 ; absolute external ram data
                                    455 ;--------------------------------------------------------
                                    456 	.area XABS    (ABS,XDATA)
                                    457 ;--------------------------------------------------------
                                    458 ; initialized external ram data
                                    459 ;--------------------------------------------------------
                                    460 	.area XISEG   (XDATA)
                                    461 	.area HOME    (CODE)
                                    462 	.area GSINIT0 (CODE)
                                    463 	.area GSINIT1 (CODE)
                                    464 	.area GSINIT2 (CODE)
                                    465 	.area GSINIT3 (CODE)
                                    466 	.area GSINIT4 (CODE)
                                    467 	.area GSINIT5 (CODE)
                                    468 	.area GSINIT  (CODE)
                                    469 	.area GSFINAL (CODE)
                                    470 	.area CSEG    (CODE)
                                    471 ;--------------------------------------------------------
                                    472 ; interrupt vector
                                    473 ;--------------------------------------------------------
                                    474 	.area HOME    (CODE)
      000000                        475 __interrupt_vect:
      000000 02 00 4C         [24]  476 	ljmp	__sdcc_gsinit_startup
                                    477 ; restartable atomic support routines
      000003                        478 	.ds	5
      000008                        479 sdcc_atomic_exchange_rollback_start::
      000008 00               [12]  480 	nop
      000009 00               [12]  481 	nop
      00000A                        482 sdcc_atomic_exchange_pdata_impl:
      00000A E2               [24]  483 	movx	a, @r0
      00000B FB               [12]  484 	mov	r3, a
      00000C EA               [12]  485 	mov	a, r2
      00000D F2               [24]  486 	movx	@r0, a
      00000E 80 2C            [24]  487 	sjmp	sdcc_atomic_exchange_exit
      000010 00               [12]  488 	nop
      000011 00               [12]  489 	nop
      000012                        490 sdcc_atomic_exchange_xdata_impl:
      000012 E0               [24]  491 	movx	a, @dptr
      000013 FB               [12]  492 	mov	r3, a
      000014 EA               [12]  493 	mov	a, r2
      000015 F0               [24]  494 	movx	@dptr, a
      000016 80 24            [24]  495 	sjmp	sdcc_atomic_exchange_exit
      000018                        496 sdcc_atomic_compare_exchange_idata_impl:
      000018 E6               [12]  497 	mov	a, @r0
      000019 B5 02 02         [24]  498 	cjne	a, ar2, .+#5
      00001C EB               [12]  499 	mov	a, r3
      00001D F6               [12]  500 	mov	@r0, a
      00001E 22               [24]  501 	ret
      00001F 00               [12]  502 	nop
      000020                        503 sdcc_atomic_compare_exchange_pdata_impl:
      000020 E2               [24]  504 	movx	a, @r0
      000021 B5 02 02         [24]  505 	cjne	a, ar2, .+#5
      000024 EB               [12]  506 	mov	a, r3
      000025 F2               [24]  507 	movx	@r0, a
      000026 22               [24]  508 	ret
      000027 00               [12]  509 	nop
      000028                        510 sdcc_atomic_compare_exchange_xdata_impl:
      000028 E0               [24]  511 	movx	a, @dptr
      000029 B5 02 02         [24]  512 	cjne	a, ar2, .+#5
      00002C EB               [12]  513 	mov	a, r3
      00002D F0               [24]  514 	movx	@dptr, a
      00002E 22               [24]  515 	ret
      00002F                        516 sdcc_atomic_exchange_rollback_end::
                                    517 
      00002F                        518 sdcc_atomic_exchange_gptr_impl::
      00002F 30 F6 E0         [24]  519 	jnb	b.6, sdcc_atomic_exchange_xdata_impl
      000032 A8 82            [24]  520 	mov	r0, dpl
      000034 20 F5 D3         [24]  521 	jb	b.5, sdcc_atomic_exchange_pdata_impl
      000037                        522 sdcc_atomic_exchange_idata_impl:
      000037 EA               [12]  523 	mov	a, r2
      000038 C6               [12]  524 	xch	a, @r0
      000039 F5 82            [12]  525 	mov	dpl, a
      00003B 22               [24]  526 	ret
      00003C                        527 sdcc_atomic_exchange_exit:
      00003C 8B 82            [24]  528 	mov	dpl, r3
      00003E 22               [24]  529 	ret
      00003F                        530 sdcc_atomic_compare_exchange_gptr_impl::
      00003F 30 F6 E6         [24]  531 	jnb	b.6, sdcc_atomic_compare_exchange_xdata_impl
      000042 A8 82            [24]  532 	mov	r0, dpl
      000044 20 F5 D9         [24]  533 	jb	b.5, sdcc_atomic_compare_exchange_pdata_impl
      000047 80 CF            [24]  534 	sjmp	sdcc_atomic_compare_exchange_idata_impl
                                    535 ;--------------------------------------------------------
                                    536 ; global & static initialisations
                                    537 ;--------------------------------------------------------
                                    538 	.area HOME    (CODE)
                                    539 	.area GSINIT  (CODE)
                                    540 	.area GSFINAL (CODE)
                                    541 	.area GSINIT  (CODE)
                                    542 	.globl __sdcc_gsinit_startup
                                    543 	.globl __sdcc_program_startup
                                    544 	.globl __start__stack
                                    545 	.globl __mcs51_genXINIT
                                    546 	.globl __mcs51_genXRAMCLEAR
                                    547 	.globl __mcs51_genRAMCLEAR
                           000000   548 	C$controller_8051.c$29$2_0$103 ==.
                                    549 ;	/home/mahavigna/CI/controller_8051.c:29: volatile unsigned char test_temperature = 0u;
      0000A5 75 08 00         [24]  550 	mov	_test_temperature,#0x00
                           000003   551 	C$controller_8051.c$30$2_0$103 ==.
                                    552 ;	/home/mahavigna/CI/controller_8051.c:30: volatile unsigned char test_pwm = 0u;
      0000A8 75 09 00         [24]  553 	mov	_test_pwm,#0x00
                           000006   554 	C$controller_8051.c$31$2_0$103 ==.
                                    555 ;	/home/mahavigna/CI/controller_8051.c:31: volatile float test_fan_speed = 0.0f;
      0000AB E4               [12]  556 	clr	a
      0000AC F5 0A            [12]  557 	mov	_test_fan_speed,a
      0000AE F5 0B            [12]  558 	mov	(_test_fan_speed + 1),a
      0000B0 F5 0C            [12]  559 	mov	(_test_fan_speed + 2),a
      0000B2 F5 0D            [12]  560 	mov	(_test_fan_speed + 3),a
                                    561 	.area GSFINAL (CODE)
      0000B4 02 00 49         [24]  562 	ljmp	__sdcc_program_startup
                                    563 ;--------------------------------------------------------
                                    564 ; Home
                                    565 ;--------------------------------------------------------
                                    566 	.area HOME    (CODE)
                                    567 	.area HOME    (CODE)
      000049                        568 __sdcc_program_startup:
      000049 02 10 07         [24]  569 	ljmp	_main
                                    570 ;	return from main will return to caller
                                    571 ;--------------------------------------------------------
                                    572 ; code
                                    573 ;--------------------------------------------------------
                                    574 	.area CSEG    (CODE)
                                    575 ;------------------------------------------------------------
                                    576 ;Allocation info for local variables in function 'fuzzy_clamp'
                                    577 ;------------------------------------------------------------
                                    578 ;value         Allocated to registers r4 r5 r6 r7 
                                    579 ;------------------------------------------------------------
                           000000   580 	Fcontroller_8051$fuzzy_clamp$0$0 ==.
                           000000   581 	C$fuzzy.h$494$0_0$38 ==.
                                    582 ;	/home/mahavigna/CI/fuzzy.h:494: static float fuzzy_clamp(float value)
                                    583 ;	-----------------------------------------
                                    584 ;	 function fuzzy_clamp
                                    585 ;	-----------------------------------------
      0000B7                        586 _fuzzy_clamp:
                           000007   587 	ar7 = 0x07
                           000006   588 	ar6 = 0x06
                           000005   589 	ar5 = 0x05
                           000004   590 	ar4 = 0x04
                           000003   591 	ar3 = 0x03
                           000002   592 	ar2 = 0x02
                           000001   593 	ar1 = 0x01
                           000000   594 	ar0 = 0x00
      0000B7 AC 82            [24]  595 	mov	r4,dpl
      0000B9 AD 83            [24]  596 	mov	r5,dph
      0000BB AE F0            [24]  597 	mov	r6,b
      0000BD FF               [12]  598 	mov	r7,a
                           000007   599 	C$fuzzy.h$496$1_0$38 ==.
                                    600 ;	/home/mahavigna/CI/fuzzy.h:496: if (value < LEVEL_LO) {
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
      0000D6 12 11 6B         [24]  614 	lcall	___fslt
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
                           000035   625 	C$fuzzy.h$497$2_0$39 ==.
                                    626 ;	/home/mahavigna/CI/fuzzy.h:497: return LEVEL_LO;
      0000EC 90 00 00         [24]  627 	mov	dptr,#0x0000
      0000EF E4               [12]  628 	clr	a
      0000F0 F5 F0            [12]  629 	mov	b,a
      0000F2 80 3F            [24]  630 	sjmp	00105$
      0000F4                        631 00102$:
                           00003D   632 	C$fuzzy.h$500$1_0$38 ==.
                                    633 ;	/home/mahavigna/CI/fuzzy.h:500: if (value > LEVEL_HI) {
      0000F4 C0 07            [24]  634 	push	ar7
      0000F6 C0 06            [24]  635 	push	ar6
      0000F8 C0 05            [24]  636 	push	ar5
      0000FA C0 04            [24]  637 	push	ar4
      0000FC C0 04            [24]  638 	push	ar4
      0000FE C0 05            [24]  639 	push	ar5
      000100 C0 06            [24]  640 	push	ar6
      000102 C0 07            [24]  641 	push	ar7
      000104 90 00 00         [24]  642 	mov	dptr,#0x0000
      000107 75 F0 80         [24]  643 	mov	b, #0x80
      00010A 74 3F            [12]  644 	mov	a, #0x3f
      00010C 12 11 6B         [24]  645 	lcall	___fslt
      00010F AB 82            [24]  646 	mov	r3, dpl
      000111 E5 81            [12]  647 	mov	a,sp
      000113 24 FC            [12]  648 	add	a,#0xfc
      000115 F5 81            [12]  649 	mov	sp,a
      000117 D0 04            [24]  650 	pop	ar4
      000119 D0 05            [24]  651 	pop	ar5
      00011B D0 06            [24]  652 	pop	ar6
      00011D D0 07            [24]  653 	pop	ar7
      00011F EB               [12]  654 	mov	a,r3
      000120 60 0A            [24]  655 	jz	00104$
                           00006B   656 	C$fuzzy.h$501$2_0$40 ==.
                                    657 ;	/home/mahavigna/CI/fuzzy.h:501: return LEVEL_HI;
      000122 90 00 00         [24]  658 	mov	dptr,#0x0000
      000125 75 F0 80         [24]  659 	mov	b, #0x80
      000128 74 3F            [12]  660 	mov	a, #0x3f
      00012A 80 07            [24]  661 	sjmp	00105$
      00012C                        662 00104$:
                           000075   663 	C$fuzzy.h$504$1_0$38 ==.
                                    664 ;	/home/mahavigna/CI/fuzzy.h:504: return value;
      00012C 8C 82            [24]  665 	mov	dpl, r4
      00012E 8D 83            [24]  666 	mov	dph, r5
      000130 8E F0            [24]  667 	mov	b, r6
      000132 EF               [12]  668 	mov	a, r7
      000133                        669 00105$:
                           00007C   670 	C$fuzzy.h$505$1_0$38 ==.
                                    671 ;	/home/mahavigna/CI/fuzzy.h:505: }
                           00007C   672 	C$fuzzy.h$505$1_0$38 ==.
                           00007C   673 	XFcontroller_8051$fuzzy_clamp$0$0 ==.
      000133 22               [24]  674 	ret
                                    675 ;------------------------------------------------------------
                                    676 ;Allocation info for local variables in function 'fuzzy_not'
                                    677 ;------------------------------------------------------------
                                    678 ;membership    Allocated to registers r4 r5 r6 r7 
                                    679 ;------------------------------------------------------------
                           00007D   680 	G$fuzzy_not$0$0 ==.
                           00007D   681 	C$fuzzy.h$510$1_0$42 ==.
                                    682 ;	/home/mahavigna/CI/fuzzy.h:510: float fuzzy_not(
                                    683 ;	-----------------------------------------
                                    684 ;	 function fuzzy_not
                                    685 ;	-----------------------------------------
      000134                        686 _fuzzy_not:
                           00007D   687 	C$fuzzy.h$516$1_0$42 ==.
                                    688 ;	/home/mahavigna/CI/fuzzy.h:516: membership
      000134 12 00 B7         [24]  689 	lcall	_fuzzy_clamp
      000137 AC 82            [24]  690 	mov	r4, dpl
      000139 AD 83            [24]  691 	mov	r5, dph
      00013B AE F0            [24]  692 	mov	r6, b
      00013D FF               [12]  693 	mov	r7, a
      00013E C0 04            [24]  694 	push	ar4
      000140 C0 05            [24]  695 	push	ar5
      000142 C0 06            [24]  696 	push	ar6
      000144 C0 07            [24]  697 	push	ar7
      000146 90 00 00         [24]  698 	mov	dptr,#0x0000
      000149 75 F0 80         [24]  699 	mov	b, #0x80
      00014C 74 3F            [12]  700 	mov	a, #0x3f
      00014E 12 10 41         [24]  701 	lcall	___fssub
      000151 AC 82            [24]  702 	mov	r4, dpl
      000153 AD 83            [24]  703 	mov	r5, dph
      000155 AE F0            [24]  704 	mov	r6, b
      000157 FF               [12]  705 	mov	r7, a
      000158 E5 81            [12]  706 	mov	a,sp
      00015A 24 FC            [12]  707 	add	a,#0xfc
      00015C F5 81            [12]  708 	mov	sp,a
      00015E 8C 82            [24]  709 	mov	dpl, r4
      000160 8D 83            [24]  710 	mov	dph, r5
      000162 8E F0            [24]  711 	mov	b, r6
      000164 EF               [12]  712 	mov	a, r7
                           0000AE   713 	C$fuzzy.h$518$1_0$42 ==.
                                    714 ;	/home/mahavigna/CI/fuzzy.h:518: }
                           0000AE   715 	C$fuzzy.h$518$1_0$42 ==.
                           0000AE   716 	XG$fuzzy_not$0$0 ==.
      000165 22               [24]  717 	ret
                                    718 ;------------------------------------------------------------
                                    719 ;Allocation info for local variables in function 'fuzzy_apply_hedge'
                                    720 ;------------------------------------------------------------
                                    721 ;hedge         Allocated to stack - _bp -3 +1 
                                    722 ;membership    Allocated to stack - _bp +1 +4 
                                    723 ;result        Allocated to registers r2 r3 r6 r7 
                                    724 ;------------------------------------------------------------
                           0000AF   725 	Fcontroller_8051$fuzzy_apply_hedge$0$0 ==.
                           0000AF   726 	C$fuzzy.h$528$1_0$44 ==.
                                    727 ;	/home/mahavigna/CI/fuzzy.h:528: static float fuzzy_apply_hedge(
                                    728 ;	-----------------------------------------
                                    729 ;	 function fuzzy_apply_hedge
                                    730 ;	-----------------------------------------
      000166                        731 _fuzzy_apply_hedge:
      000166 C0 0E            [24]  732 	push	_bp
      000168 85 81 0E         [24]  733 	mov	_bp,sp
      00016B AC 82            [24]  734 	mov	r4,dpl
      00016D AD 83            [24]  735 	mov	r5,dph
      00016F AE F0            [24]  736 	mov	r6,b
      000171 FF               [12]  737 	mov	r7,a
      000172 E5 81            [12]  738 	mov	a,sp
      000174 24 04            [12]  739 	add	a,#0x04
      000176 F5 81            [12]  740 	mov	sp,a
                           0000C1   741 	C$fuzzy.h$540$1_0$44 ==.
                                    742 ;	/home/mahavigna/CI/fuzzy.h:540: fuzzy_clamp(membership);
      000178 8C 82            [24]  743 	mov	dpl, r4
      00017A 8D 83            [24]  744 	mov	dph, r5
      00017C 8E F0            [24]  745 	mov	b, r6
      00017E EF               [12]  746 	mov	a, r7
      00017F 12 00 B7         [24]  747 	lcall	_fuzzy_clamp
      000182 A8 0E            [24]  748 	mov	r0,_bp
      000184 08               [12]  749 	inc	r0
      000185 A6 82            [24]  750 	mov	@r0, dpl
      000187 08               [12]  751 	inc	r0
      000188 A6 83            [24]  752 	mov	@r0, dph
      00018A 08               [12]  753 	inc	r0
      00018B A6 F0            [24]  754 	mov	@r0, b
      00018D 08               [12]  755 	inc	r0
      00018E F6               [12]  756 	mov	@r0,a
                           0000D8   757 	C$fuzzy.h$555$1_0$44 ==.
                                    758 ;	/home/mahavigna/CI/fuzzy.h:555: if (hedge == 0u) {
      00018F E5 0E            [12]  759 	mov	a,_bp
      000191 24 FD            [12]  760 	add	a,#0xfd
      000193 F8               [12]  761 	mov	r0,a
      000194 E6               [12]  762 	mov	a,@r0
      000195 70 07            [24]  763 	jnz	00102$
                           0000E0   764 	C$fuzzy.h$556$2_0$45 ==.
                                    765 ;	/home/mahavigna/CI/fuzzy.h:556: hedge = 1u;
      000197 E5 0E            [12]  766 	mov	a,_bp
      000199 24 FD            [12]  767 	add	a,#0xfd
      00019B F8               [12]  768 	mov	r0,a
      00019C 76 01            [12]  769 	mov	@r0,#0x01
      00019E                        770 00102$:
                           0000E7   771 	C$fuzzy.h$559$1_0$44 ==.
                                    772 ;	/home/mahavigna/CI/fuzzy.h:559: result = LEVEL_HI;
      00019E 7A 00            [12]  773 	mov	r2,#0x00
      0001A0 7B 00            [12]  774 	mov	r3,#0x00
      0001A2 7E 80            [12]  775 	mov	r6,#0x80
      0001A4 7F 3F            [12]  776 	mov	r7,#0x3f
                           0000EF   777 	C$fuzzy.h$561$1_0$44 ==.
                                    778 ;	/home/mahavigna/CI/fuzzy.h:561: while (hedge > 0u) {
      0001A6 E5 0E            [12]  779 	mov	a,_bp
      0001A8 24 FD            [12]  780 	add	a,#0xfd
      0001AA F8               [12]  781 	mov	r0,a
      0001AB 86 05            [24]  782 	mov	ar5,@r0
      0001AD                        783 00103$:
      0001AD ED               [12]  784 	mov	a,r5
      0001AE 60 30            [24]  785 	jz	00105$
                           0000F9   786 	C$fuzzy.h$562$1_0$44 ==.
                                    787 ;	/home/mahavigna/CI/fuzzy.h:562: result *= membership;
      0001B0 C0 05            [24]  788 	push	ar5
      0001B2 A8 0E            [24]  789 	mov	r0,_bp
      0001B4 08               [12]  790 	inc	r0
      0001B5 E6               [12]  791 	mov	a,@r0
      0001B6 C0 E0            [24]  792 	push	acc
      0001B8 08               [12]  793 	inc	r0
      0001B9 E6               [12]  794 	mov	a,@r0
      0001BA C0 E0            [24]  795 	push	acc
      0001BC 08               [12]  796 	inc	r0
      0001BD E6               [12]  797 	mov	a,@r0
      0001BE C0 E0            [24]  798 	push	acc
      0001C0 08               [12]  799 	inc	r0
      0001C1 E6               [12]  800 	mov	a,@r0
      0001C2 C0 E0            [24]  801 	push	acc
                           00010D   802 	C$fuzzy.h$563$1_0$44 ==.
                                    803 ;	/home/mahavigna/CI/fuzzy.h:563: hedge--;
      0001C4 8A 82            [24]  804 	mov	dpl, r2
      0001C6 8B 83            [24]  805 	mov	dph, r3
      0001C8 8E F0            [24]  806 	mov	b, r6
      0001CA EF               [12]  807 	mov	a, r7
      0001CB 12 10 4C         [24]  808 	lcall	___fsmul
      0001CE AA 82            [24]  809 	mov	r2, dpl
      0001D0 AB 83            [24]  810 	mov	r3, dph
      0001D2 AE F0            [24]  811 	mov	r6, b
      0001D4 FF               [12]  812 	mov	r7, a
      0001D5 E5 81            [12]  813 	mov	a,sp
      0001D7 24 FC            [12]  814 	add	a,#0xfc
      0001D9 F5 81            [12]  815 	mov	sp,a
      0001DB D0 05            [24]  816 	pop	ar5
      0001DD 1D               [12]  817 	dec	r5
      0001DE 80 CD            [24]  818 	sjmp	00103$
      0001E0                        819 00105$:
                           000129   820 	C$fuzzy.h$567$1_0$44 ==.
                                    821 ;	/home/mahavigna/CI/fuzzy.h:567: result
      0001E0 8A 82            [24]  822 	mov	dpl, r2
      0001E2 8B 83            [24]  823 	mov	dph, r3
      0001E4 8E F0            [24]  824 	mov	b, r6
      0001E6 EF               [12]  825 	mov	a, r7
      0001E7 12 00 B7         [24]  826 	lcall	_fuzzy_clamp
                           000133   827 	C$fuzzy.h$571$1_0$44 ==.
                                    828 ;	/home/mahavigna/CI/fuzzy.h:571: }
      0001EA 85 0E 81         [24]  829 	mov	sp,_bp
      0001ED D0 0E            [24]  830 	pop	_bp
                           000138   831 	C$fuzzy.h$571$1_0$44 ==.
                           000138   832 	XFcontroller_8051$fuzzy_apply_hedge$0$0 ==.
      0001EF 22               [24]  833 	ret
                                    834 ;------------------------------------------------------------
                                    835 ;Allocation info for local variables in function 'fuzzy_sugeno_weighted_average'
                                    836 ;------------------------------------------------------------
                                    837 ;rule_count    Allocated to stack - _bp -4 +2 
                                    838 ;args          Allocated to registers 
                                    839 ;weighted_sum  Allocated to stack - _bp +6 +4 
                                    840 ;firing_sum    Allocated to stack - _bp +10 +4 
                                    841 ;firing_strength Allocated to stack - _bp +14 +4 
                                    842 ;consequent    Allocated to registers r7 r6 r5 r4 
                                    843 ;i             Allocated to registers r3 r2 
                                    844 ;sloc0         Allocated to stack - _bp +1 +1 
                                    845 ;sloc1         Allocated to stack - _bp +2 +4 
                                    846 ;------------------------------------------------------------
                           000139   847 	G$fuzzy_sugeno_weighted_average$0$0 ==.
                           000139   848 	C$fuzzy.h$659$1_0$48 ==.
                                    849 ;	/home/mahavigna/CI/fuzzy.h:659: float fuzzy_sugeno_weighted_average(
                                    850 ;	-----------------------------------------
                                    851 ;	 function fuzzy_sugeno_weighted_average
                                    852 ;	-----------------------------------------
      0001F0                        853 _fuzzy_sugeno_weighted_average:
      0001F0 C0 0E            [24]  854 	push	_bp
      0001F2 E5 81            [12]  855 	mov	a,sp
      0001F4 F5 0E            [12]  856 	mov	_bp,a
      0001F6 24 11            [12]  857 	add	a,#0x11
      0001F8 F5 81            [12]  858 	mov	sp,a
                           000143   859 	C$fuzzy.h$671$1_0$48 ==.
                                    860 ;	/home/mahavigna/CI/fuzzy.h:671: if (rule_count <= 0) {
      0001FA E5 0E            [12]  861 	mov	a,_bp
      0001FC 24 FC            [12]  862 	add	a,#0xfc
      0001FE F8               [12]  863 	mov	r0,a
      0001FF C3               [12]  864 	clr	c
      000200 E4               [12]  865 	clr	a
      000201 96               [12]  866 	subb	a,@r0
      000202 74 80            [12]  867 	mov	a,#(0x00 ^ 0x80)
      000204 08               [12]  868 	inc	r0
      000205 86 F0            [24]  869 	mov	b,@r0
      000207 63 F0 80         [24]  870 	xrl	b,#0x80
      00020A 95 F0            [12]  871 	subb	a,b
      00020C 40 09            [24]  872 	jc	00102$
                           000157   873 	C$fuzzy.h$672$2_0$49 ==.
                                    874 ;	/home/mahavigna/CI/fuzzy.h:672: return 0.0f;
      00020E 90 00 00         [24]  875 	mov	dptr,#0x0000
      000211 E4               [12]  876 	clr	a
      000212 F5 F0            [12]  877 	mov	b,a
      000214 02 03 D4         [24]  878 	ljmp	00109$
      000217                        879 00102$:
                           000160   880 	C$fuzzy.h$676$1_0$48 ==.
                                    881 ;	/home/mahavigna/CI/fuzzy.h:676: 0.0f;
      000217 E5 0E            [12]  882 	mov	a,_bp
      000219 24 06            [12]  883 	add	a,#0x06
      00021B F8               [12]  884 	mov	r0,a
      00021C E4               [12]  885 	clr	a
      00021D F6               [12]  886 	mov	@r0,a
      00021E 08               [12]  887 	inc	r0
      00021F F6               [12]  888 	mov	@r0,a
      000220 08               [12]  889 	inc	r0
      000221 F6               [12]  890 	mov	@r0,a
      000222 08               [12]  891 	inc	r0
      000223 F6               [12]  892 	mov	@r0,a
                           00016D   893 	C$fuzzy.h$679$1_0$48 ==.
                                    894 ;	/home/mahavigna/CI/fuzzy.h:679: 0.0f;
      000224 E5 0E            [12]  895 	mov	a,_bp
      000226 24 0A            [12]  896 	add	a,#0x0a
      000228 F8               [12]  897 	mov	r0,a
      000229 E4               [12]  898 	clr	a
      00022A F6               [12]  899 	mov	@r0,a
      00022B 08               [12]  900 	inc	r0
      00022C F6               [12]  901 	mov	@r0,a
      00022D 08               [12]  902 	inc	r0
      00022E F6               [12]  903 	mov	@r0,a
      00022F 08               [12]  904 	inc	r0
      000230 F6               [12]  905 	mov	@r0,a
                           00017A   906 	C$fuzzy.h$681$2_0$50 ==.
                                    907 ;	/home/mahavigna/CI/fuzzy.h:681: va_start(
      000231 A8 0E            [24]  908 	mov	r0,_bp
      000233 08               [12]  909 	inc	r0
      000234 E5 0E            [12]  910 	mov	a,_bp
      000236 24 FC            [12]  911 	add	a,#0xfc
      000238 F6               [12]  912 	mov	@r0,a
                           000182   913 	C$fuzzy.h$687$1_0$48 ==.
                                    914 ;	/home/mahavigna/CI/fuzzy.h:687: i = 0;
      000239 7B 00            [12]  915 	mov	r3,#0x00
      00023B 7A 00            [12]  916 	mov	r2,#0x00
      00023D                        917 00107$:
                           000186   918 	C$fuzzy.h$688$2_0$51 ==.
                                    919 ;	/home/mahavigna/CI/fuzzy.h:688: i < rule_count;
      00023D E5 0E            [12]  920 	mov	a,_bp
      00023F 24 FC            [12]  921 	add	a,#0xfc
      000241 F8               [12]  922 	mov	r0,a
      000242 C3               [12]  923 	clr	c
      000243 EB               [12]  924 	mov	a,r3
      000244 96               [12]  925 	subb	a,@r0
      000245 EA               [12]  926 	mov	a,r2
      000246 64 80            [12]  927 	xrl	a,#0x80
      000248 08               [12]  928 	inc	r0
      000249 86 F0            [24]  929 	mov	b,@r0
      00024B 63 F0 80         [24]  930 	xrl	b,#0x80
      00024E 95 F0            [12]  931 	subb	a,b
      000250 40 03            [24]  932 	jc	00141$
      000252 02 03 67         [24]  933 	ljmp	00103$
      000255                        934 00141$:
                           00019E   935 	C$fuzzy.h$692$3_0$52 ==.
                                    936 ;	/home/mahavigna/CI/fuzzy.h:692: (float)va_arg(
      000255 A8 0E            [24]  937 	mov	r0,_bp
      000257 08               [12]  938 	inc	r0
      000258 E6               [12]  939 	mov	a,@r0
      000259 24 FC            [12]  940 	add	a,#0xfc
      00025B FE               [12]  941 	mov	r6,a
      00025C F9               [12]  942 	mov	r1,a
      00025D A8 0E            [24]  943 	mov	r0,_bp
      00025F 08               [12]  944 	inc	r0
      000260 08               [12]  945 	inc	r0
      000261 E7               [12]  946 	mov	a,@r1
      000262 F6               [12]  947 	mov	@r0,a
      000263 09               [12]  948 	inc	r1
      000264 E7               [12]  949 	mov	a,@r1
      000265 08               [12]  950 	inc	r0
      000266 F6               [12]  951 	mov	@r0,a
      000267 09               [12]  952 	inc	r1
      000268 E7               [12]  953 	mov	a,@r1
      000269 08               [12]  954 	inc	r0
      00026A F6               [12]  955 	mov	@r0,a
      00026B 09               [12]  956 	inc	r1
      00026C E7               [12]  957 	mov	a,@r1
      00026D 08               [12]  958 	inc	r0
      00026E F6               [12]  959 	mov	@r0,a
      00026F 19               [12]  960 	dec	r1
      000270 19               [12]  961 	dec	r1
      000271 19               [12]  962 	dec	r1
                           0001BB   963 	C$fuzzy.h$698$3_0$52 ==.
                                    964 ;	/home/mahavigna/CI/fuzzy.h:698: (float)va_arg(
      000272 1E               [12]  965 	dec	r6
      000273 1E               [12]  966 	dec	r6
      000274 1E               [12]  967 	dec	r6
      000275 1E               [12]  968 	dec	r6
      000276 A8 0E            [24]  969 	mov	r0,_bp
      000278 08               [12]  970 	inc	r0
      000279 A6 06            [24]  971 	mov	@r0,ar6
      00027B 8E 01            [24]  972 	mov	ar1,r6
      00027D 87 07            [24]  973 	mov	ar7,@r1
      00027F 09               [12]  974 	inc	r1
      000280 87 06            [24]  975 	mov	ar6,@r1
      000282 09               [12]  976 	inc	r1
      000283 87 05            [24]  977 	mov	ar5,@r1
      000285 09               [12]  978 	inc	r1
      000286 87 04            [24]  979 	mov	ar4,@r1
      000288 19               [12]  980 	dec	r1
      000289 19               [12]  981 	dec	r1
      00028A 19               [12]  982 	dec	r1
                           0001D4   983 	C$fuzzy.h$705$3_0$52 ==.
                                    984 ;	/home/mahavigna/CI/fuzzy.h:705: firing_strength
      00028B A8 0E            [24]  985 	mov	r0,_bp
      00028D 08               [12]  986 	inc	r0
      00028E 08               [12]  987 	inc	r0
      00028F 86 82            [24]  988 	mov	dpl, @r0
      000291 08               [12]  989 	inc	r0
      000292 86 83            [24]  990 	mov	dph, @r0
      000294 08               [12]  991 	inc	r0
      000295 86 F0            [24]  992 	mov	b, @r0
      000297 08               [12]  993 	inc	r0
      000298 E6               [12]  994 	mov	a, @r0
      000299 C0 07            [24]  995 	push	ar7
      00029B C0 06            [24]  996 	push	ar6
      00029D C0 05            [24]  997 	push	ar5
      00029F C0 04            [24]  998 	push	ar4
      0002A1 C0 03            [24]  999 	push	ar3
      0002A3 C0 02            [24] 1000 	push	ar2
      0002A5 12 00 B7         [24] 1001 	lcall	_fuzzy_clamp
      0002A8 C8               [12] 1002 	xch	a,r0
      0002A9 E5 0E            [12] 1003 	mov	a,_bp
      0002AB 24 0E            [12] 1004 	add	a,#0x0e
      0002AD C8               [12] 1005 	xch	a,r0
      0002AE A6 82            [24] 1006 	mov	@r0, dpl
      0002B0 08               [12] 1007 	inc	r0
      0002B1 A6 83            [24] 1008 	mov	@r0, dph
      0002B3 08               [12] 1009 	inc	r0
      0002B4 A6 F0            [24] 1010 	mov	@r0, b
      0002B6 08               [12] 1011 	inc	r0
      0002B7 F6               [12] 1012 	mov	@r0,a
      0002B8 D0 02            [24] 1013 	pop	ar2
      0002BA D0 03            [24] 1014 	pop	ar3
      0002BC D0 04            [24] 1015 	pop	ar4
      0002BE D0 05            [24] 1016 	pop	ar5
      0002C0 D0 06            [24] 1017 	pop	ar6
      0002C2 D0 07            [24] 1018 	pop	ar7
                           00020D  1019 	C$fuzzy.h$718$1_0$48 ==.
                                   1020 ;	/home/mahavigna/CI/fuzzy.h:718: consequent;
      0002C4 C0 03            [24] 1021 	push	ar3
      0002C6 C0 02            [24] 1022 	push	ar2
      0002C8 C0 07            [24] 1023 	push	ar7
      0002CA C0 06            [24] 1024 	push	ar6
      0002CC C0 05            [24] 1025 	push	ar5
      0002CE C0 04            [24] 1026 	push	ar4
      0002D0 E5 0E            [12] 1027 	mov	a,_bp
      0002D2 24 0E            [12] 1028 	add	a,#0x0e
      0002D4 F8               [12] 1029 	mov	r0,a
      0002D5 86 82            [24] 1030 	mov	dpl, @r0
      0002D7 08               [12] 1031 	inc	r0
      0002D8 86 83            [24] 1032 	mov	dph, @r0
      0002DA 08               [12] 1033 	inc	r0
      0002DB 86 F0            [24] 1034 	mov	b, @r0
      0002DD 08               [12] 1035 	inc	r0
      0002DE E6               [12] 1036 	mov	a, @r0
      0002DF 12 10 4C         [24] 1037 	lcall	___fsmul
      0002E2 AC 82            [24] 1038 	mov	r4, dpl
      0002E4 AD 83            [24] 1039 	mov	r5, dph
      0002E6 AE F0            [24] 1040 	mov	r6, b
      0002E8 FF               [12] 1041 	mov	r7, a
      0002E9 E5 81            [12] 1042 	mov	a,sp
      0002EB 24 FC            [12] 1043 	add	a,#0xfc
      0002ED F5 81            [12] 1044 	mov	sp,a
      0002EF C0 04            [24] 1045 	push	ar4
      0002F1 C0 05            [24] 1046 	push	ar5
      0002F3 C0 06            [24] 1047 	push	ar6
      0002F5 C0 07            [24] 1048 	push	ar7
                           000240  1049 	C$fuzzy.h$721$1_0$48 ==.
                                   1050 ;	/home/mahavigna/CI/fuzzy.h:721: firing_strength;
      0002F7 E5 0E            [12] 1051 	mov	a,_bp
      0002F9 24 06            [12] 1052 	add	a,#0x06
      0002FB F8               [12] 1053 	mov	r0,a
      0002FC 86 82            [24] 1054 	mov	dpl, @r0
      0002FE 08               [12] 1055 	inc	r0
      0002FF 86 83            [24] 1056 	mov	dph, @r0
      000301 08               [12] 1057 	inc	r0
      000302 86 F0            [24] 1058 	mov	b, @r0
      000304 08               [12] 1059 	inc	r0
      000305 E6               [12] 1060 	mov	a, @r0
      000306 12 11 BD         [24] 1061 	lcall	___fsadd
      000309 C8               [12] 1062 	xch	a,r0
      00030A E5 0E            [12] 1063 	mov	a,_bp
      00030C 24 06            [12] 1064 	add	a,#0x06
      00030E C8               [12] 1065 	xch	a,r0
      00030F A6 82            [24] 1066 	mov	@r0, dpl
      000311 08               [12] 1067 	inc	r0
      000312 A6 83            [24] 1068 	mov	@r0, dph
      000314 08               [12] 1069 	inc	r0
      000315 A6 F0            [24] 1070 	mov	@r0, b
      000317 08               [12] 1071 	inc	r0
      000318 F6               [12] 1072 	mov	@r0,a
      000319 E5 81            [12] 1073 	mov	a,sp
      00031B 24 FC            [12] 1074 	add	a,#0xfc
      00031D F5 81            [12] 1075 	mov	sp,a
      00031F E5 0E            [12] 1076 	mov	a,_bp
      000321 24 0E            [12] 1077 	add	a,#0x0e
      000323 F8               [12] 1078 	mov	r0,a
      000324 E6               [12] 1079 	mov	a,@r0
      000325 C0 E0            [24] 1080 	push	acc
      000327 08               [12] 1081 	inc	r0
      000328 E6               [12] 1082 	mov	a,@r0
      000329 C0 E0            [24] 1083 	push	acc
      00032B 08               [12] 1084 	inc	r0
      00032C E6               [12] 1085 	mov	a,@r0
      00032D C0 E0            [24] 1086 	push	acc
      00032F 08               [12] 1087 	inc	r0
      000330 E6               [12] 1088 	mov	a,@r0
      000331 C0 E0            [24] 1089 	push	acc
                           00027C  1090 	C$fuzzy.h$689$1_0$48 ==.
                                   1091 ;	/home/mahavigna/CI/fuzzy.h:689: i++
      000333 E5 0E            [12] 1092 	mov	a,_bp
      000335 24 0A            [12] 1093 	add	a,#0x0a
      000337 F8               [12] 1094 	mov	r0,a
      000338 86 82            [24] 1095 	mov	dpl, @r0
      00033A 08               [12] 1096 	inc	r0
      00033B 86 83            [24] 1097 	mov	dph, @r0
      00033D 08               [12] 1098 	inc	r0
      00033E 86 F0            [24] 1099 	mov	b, @r0
      000340 08               [12] 1100 	inc	r0
      000341 E6               [12] 1101 	mov	a, @r0
      000342 12 11 BD         [24] 1102 	lcall	___fsadd
      000345 C8               [12] 1103 	xch	a,r0
      000346 E5 0E            [12] 1104 	mov	a,_bp
      000348 24 0A            [12] 1105 	add	a,#0x0a
      00034A C8               [12] 1106 	xch	a,r0
      00034B A6 82            [24] 1107 	mov	@r0, dpl
      00034D 08               [12] 1108 	inc	r0
      00034E A6 83            [24] 1109 	mov	@r0, dph
      000350 08               [12] 1110 	inc	r0
      000351 A6 F0            [24] 1111 	mov	@r0, b
      000353 08               [12] 1112 	inc	r0
      000354 F6               [12] 1113 	mov	@r0,a
      000355 E5 81            [12] 1114 	mov	a,sp
      000357 24 FC            [12] 1115 	add	a,#0xfc
      000359 F5 81            [12] 1116 	mov	sp,a
      00035B D0 02            [24] 1117 	pop	ar2
      00035D D0 03            [24] 1118 	pop	ar3
      00035F 0B               [12] 1119 	inc	r3
      000360 BB 00 01         [24] 1120 	cjne	r3,#0x00,00142$
      000363 0A               [12] 1121 	inc	r2
      000364                       1122 00142$:
      000364 02 02 3D         [24] 1123 	ljmp	00107$
      000367                       1124 00103$:
                           0002B0  1125 	C$fuzzy.h$726$1_0$48 ==.
                                   1126 ;	/home/mahavigna/CI/fuzzy.h:726: if (firing_sum <= LEVEL_LO) {
      000367 E5 0E            [12] 1127 	mov	a,_bp
      000369 24 0A            [12] 1128 	add	a,#0x0a
      00036B F8               [12] 1129 	mov	r0,a
      00036C E6               [12] 1130 	mov	a,@r0
      00036D C0 E0            [24] 1131 	push	acc
      00036F 08               [12] 1132 	inc	r0
      000370 E6               [12] 1133 	mov	a,@r0
      000371 C0 E0            [24] 1134 	push	acc
      000373 08               [12] 1135 	inc	r0
      000374 E6               [12] 1136 	mov	a,@r0
      000375 C0 E0            [24] 1137 	push	acc
      000377 08               [12] 1138 	inc	r0
      000378 E6               [12] 1139 	mov	a,@r0
      000379 C0 E0            [24] 1140 	push	acc
      00037B 90 00 00         [24] 1141 	mov	dptr,#0x0000
      00037E E4               [12] 1142 	clr	a
      00037F F5 F0            [12] 1143 	mov	b,a
      000381 12 11 6B         [24] 1144 	lcall	___fslt
      000384 E5 81            [12] 1145 	mov	a,sp
      000386 24 FC            [12] 1146 	add	a,#0xfc
      000388 F5 81            [12] 1147 	mov	sp,a
      00038A E5 82            [12] 1148 	mov	a, dpl
      00038C 24 FF            [12] 1149 	add	a,#0xff
      00038E 92 00            [24] 1150 	mov	b0,c
      000390 40 08            [24] 1151 	jc	00105$
                           0002DB  1152 	C$fuzzy.h$727$2_0$54 ==.
                                   1153 ;	/home/mahavigna/CI/fuzzy.h:727: return 0.0f;
      000392 90 00 00         [24] 1154 	mov	dptr,#0x0000
      000395 E4               [12] 1155 	clr	a
      000396 F5 F0            [12] 1156 	mov	b,a
      000398 80 3A            [24] 1157 	sjmp	00109$
      00039A                       1158 00105$:
                           0002E3  1159 	C$fuzzy.h$731$1_0$48 ==.
                                   1160 ;	/home/mahavigna/CI/fuzzy.h:731: firing_sum;
      00039A E5 0E            [12] 1161 	mov	a,_bp
      00039C 24 0A            [12] 1162 	add	a,#0x0a
      00039E F8               [12] 1163 	mov	r0,a
      00039F E6               [12] 1164 	mov	a,@r0
      0003A0 C0 E0            [24] 1165 	push	acc
      0003A2 08               [12] 1166 	inc	r0
      0003A3 E6               [12] 1167 	mov	a,@r0
      0003A4 C0 E0            [24] 1168 	push	acc
      0003A6 08               [12] 1169 	inc	r0
      0003A7 E6               [12] 1170 	mov	a,@r0
      0003A8 C0 E0            [24] 1171 	push	acc
      0003AA 08               [12] 1172 	inc	r0
      0003AB E6               [12] 1173 	mov	a,@r0
      0003AC C0 E0            [24] 1174 	push	acc
      0003AE E5 0E            [12] 1175 	mov	a,_bp
      0003B0 24 06            [12] 1176 	add	a,#0x06
      0003B2 F8               [12] 1177 	mov	r0,a
      0003B3 86 82            [24] 1178 	mov	dpl, @r0
      0003B5 08               [12] 1179 	inc	r0
      0003B6 86 83            [24] 1180 	mov	dph, @r0
      0003B8 08               [12] 1181 	inc	r0
      0003B9 86 F0            [24] 1182 	mov	b, @r0
      0003BB 08               [12] 1183 	inc	r0
      0003BC E6               [12] 1184 	mov	a, @r0
      0003BD 12 12 C8         [24] 1185 	lcall	___fsdiv
      0003C0 AC 82            [24] 1186 	mov	r4, dpl
      0003C2 AD 83            [24] 1187 	mov	r5, dph
      0003C4 AE F0            [24] 1188 	mov	r6, b
      0003C6 FF               [12] 1189 	mov	r7, a
      0003C7 E5 81            [12] 1190 	mov	a,sp
      0003C9 24 FC            [12] 1191 	add	a,#0xfc
      0003CB F5 81            [12] 1192 	mov	sp,a
      0003CD 8C 82            [24] 1193 	mov	dpl, r4
      0003CF 8D 83            [24] 1194 	mov	dph, r5
      0003D1 8E F0            [24] 1195 	mov	b, r6
      0003D3 EF               [12] 1196 	mov	a, r7
      0003D4                       1197 00109$:
                           00031D  1198 	C$fuzzy.h$732$1_0$48 ==.
                                   1199 ;	/home/mahavigna/CI/fuzzy.h:732: }
      0003D4 85 0E 81         [24] 1200 	mov	sp,_bp
      0003D7 D0 0E            [24] 1201 	pop	_bp
                           000322  1202 	C$fuzzy.h$732$1_0$48 ==.
                           000322  1203 	XG$fuzzy_sugeno_weighted_average$0$0 ==.
      0003D9 22               [24] 1204 	ret
                                   1205 ;------------------------------------------------------------
                                   1206 ;Allocation info for local variables in function 'fuzzy_sugeno_weighted_sum'
                                   1207 ;------------------------------------------------------------
                                   1208 ;rule_count    Allocated to stack - _bp -4 +2 
                                   1209 ;args          Allocated to registers 
                                   1210 ;weighted_sum  Allocated to stack - _bp +1 +4 
                                   1211 ;firing_strength Allocated to registers r2 r4 r6 r7 
                                   1212 ;consequent    Allocated to stack - _bp +5 +4 
                                   1213 ;i             Allocated to stack - _bp +9 +2 
                                   1214 ;sloc0         Allocated to stack - _bp +16 +1 
                                   1215 ;sloc1         Allocated to stack - _bp +17 +4 
                                   1216 ;------------------------------------------------------------
                           000323  1217 	G$fuzzy_sugeno_weighted_sum$0$0 ==.
                           000323  1218 	C$fuzzy.h$738$1_0$56 ==.
                                   1219 ;	/home/mahavigna/CI/fuzzy.h:738: float fuzzy_sugeno_weighted_sum(
                                   1220 ;	-----------------------------------------
                                   1221 ;	 function fuzzy_sugeno_weighted_sum
                                   1222 ;	-----------------------------------------
      0003DA                       1223 _fuzzy_sugeno_weighted_sum:
      0003DA C0 0E            [24] 1224 	push	_bp
      0003DC E5 81            [12] 1225 	mov	a,sp
      0003DE F5 0E            [12] 1226 	mov	_bp,a
      0003E0 24 0A            [12] 1227 	add	a,#0x0a
      0003E2 F5 81            [12] 1228 	mov	sp,a
                           00032D  1229 	C$fuzzy.h$749$1_0$56 ==.
                                   1230 ;	/home/mahavigna/CI/fuzzy.h:749: if (rule_count <= 0) {
      0003E4 E5 0E            [12] 1231 	mov	a,_bp
      0003E6 24 FC            [12] 1232 	add	a,#0xfc
      0003E8 F8               [12] 1233 	mov	r0,a
      0003E9 C3               [12] 1234 	clr	c
      0003EA E4               [12] 1235 	clr	a
      0003EB 96               [12] 1236 	subb	a,@r0
      0003EC 74 80            [12] 1237 	mov	a,#(0x00 ^ 0x80)
      0003EE 08               [12] 1238 	inc	r0
      0003EF 86 F0            [24] 1239 	mov	b,@r0
      0003F1 63 F0 80         [24] 1240 	xrl	b,#0x80
      0003F4 95 F0            [12] 1241 	subb	a,b
      0003F6 40 09            [24] 1242 	jc	00102$
                           000341  1243 	C$fuzzy.h$750$2_0$57 ==.
                                   1244 ;	/home/mahavigna/CI/fuzzy.h:750: return 0.0f;
      0003F8 90 00 00         [24] 1245 	mov	dptr,#0x0000
      0003FB E4               [12] 1246 	clr	a
      0003FC F5 F0            [12] 1247 	mov	b,a
      0003FE 02 04 EF         [24] 1248 	ljmp	00107$
      000401                       1249 00102$:
                           00034A  1250 	C$fuzzy.h$754$1_0$56 ==.
                                   1251 ;	/home/mahavigna/CI/fuzzy.h:754: 0.0f;
      000401 A8 0E            [24] 1252 	mov	r0,_bp
      000403 08               [12] 1253 	inc	r0
      000404 E4               [12] 1254 	clr	a
      000405 F6               [12] 1255 	mov	@r0,a
      000406 08               [12] 1256 	inc	r0
      000407 F6               [12] 1257 	mov	@r0,a
      000408 08               [12] 1258 	inc	r0
      000409 F6               [12] 1259 	mov	@r0,a
      00040A 08               [12] 1260 	inc	r0
      00040B F6               [12] 1261 	mov	@r0,a
                           000355  1262 	C$fuzzy.h$756$2_0$58 ==.
                                   1263 ;	/home/mahavigna/CI/fuzzy.h:756: va_start(
      00040C E5 0E            [12] 1264 	mov	a,_bp
      00040E 24 FC            [12] 1265 	add	a,#0xfc
      000410 FB               [12] 1266 	mov	r3,a
                           00035A  1267 	C$fuzzy.h$762$1_0$56 ==.
                                   1268 ;	/home/mahavigna/CI/fuzzy.h:762: i = 0;
      000411 E5 0E            [12] 1269 	mov	a,_bp
      000413 24 09            [12] 1270 	add	a,#0x09
      000415 F8               [12] 1271 	mov	r0,a
      000416 E4               [12] 1272 	clr	a
      000417 F6               [12] 1273 	mov	@r0,a
      000418 08               [12] 1274 	inc	r0
      000419 F6               [12] 1275 	mov	@r0,a
      00041A                       1276 00105$:
                           000363  1277 	C$fuzzy.h$763$2_0$59 ==.
                                   1278 ;	/home/mahavigna/CI/fuzzy.h:763: i < rule_count;
      00041A E5 0E            [12] 1279 	mov	a,_bp
      00041C 24 09            [12] 1280 	add	a,#0x09
      00041E F8               [12] 1281 	mov	r0,a
      00041F E5 0E            [12] 1282 	mov	a,_bp
      000421 24 FC            [12] 1283 	add	a,#0xfc
      000423 F9               [12] 1284 	mov	r1,a
      000424 C3               [12] 1285 	clr	c
      000425 E6               [12] 1286 	mov	a,@r0
      000426 97               [12] 1287 	subb	a,@r1
      000427 08               [12] 1288 	inc	r0
      000428 E6               [12] 1289 	mov	a,@r0
      000429 64 80            [12] 1290 	xrl	a,#0x80
      00042B 09               [12] 1291 	inc	r1
      00042C 87 F0            [24] 1292 	mov	b,@r1
      00042E 63 F0 80         [24] 1293 	xrl	b,#0x80
      000431 95 F0            [12] 1294 	subb	a,b
      000433 40 03            [24] 1295 	jc	00132$
      000435 02 04 E2         [24] 1296 	ljmp	00103$
      000438                       1297 00132$:
                           000381  1298 	C$fuzzy.h$767$3_0$60 ==.
                                   1299 ;	/home/mahavigna/CI/fuzzy.h:767: (float)va_arg(
      000438 EB               [12] 1300 	mov	a,r3
      000439 24 FC            [12] 1301 	add	a,#0xfc
      00043B FE               [12] 1302 	mov	r6,a
      00043C F9               [12] 1303 	mov	r1,a
      00043D 87 07            [24] 1304 	mov	ar7,@r1
      00043F 09               [12] 1305 	inc	r1
      000440 87 05            [24] 1306 	mov	ar5,@r1
      000442 09               [12] 1307 	inc	r1
      000443 87 04            [24] 1308 	mov	ar4,@r1
      000445 09               [12] 1309 	inc	r1
      000446 87 02            [24] 1310 	mov	ar2,@r1
      000448 19               [12] 1311 	dec	r1
      000449 19               [12] 1312 	dec	r1
      00044A 19               [12] 1313 	dec	r1
                           000394  1314 	C$fuzzy.h$773$3_0$60 ==.
                                   1315 ;	/home/mahavigna/CI/fuzzy.h:773: (float)va_arg(
      00044B 1E               [12] 1316 	dec	r6
      00044C 1E               [12] 1317 	dec	r6
      00044D 1E               [12] 1318 	dec	r6
      00044E 1E               [12] 1319 	dec	r6
      00044F 8E 03            [24] 1320 	mov	ar3,r6
      000451 8E 01            [24] 1321 	mov	ar1,r6
      000453 E5 0E            [12] 1322 	mov	a,_bp
      000455 24 05            [12] 1323 	add	a,#0x05
      000457 F8               [12] 1324 	mov	r0,a
      000458 E7               [12] 1325 	mov	a,@r1
      000459 F6               [12] 1326 	mov	@r0,a
      00045A 09               [12] 1327 	inc	r1
      00045B E7               [12] 1328 	mov	a,@r1
      00045C 08               [12] 1329 	inc	r0
      00045D F6               [12] 1330 	mov	@r0,a
      00045E 09               [12] 1331 	inc	r1
      00045F E7               [12] 1332 	mov	a,@r1
      000460 08               [12] 1333 	inc	r0
      000461 F6               [12] 1334 	mov	@r0,a
      000462 09               [12] 1335 	inc	r1
      000463 E7               [12] 1336 	mov	a,@r1
      000464 08               [12] 1337 	inc	r0
      000465 F6               [12] 1338 	mov	@r0,a
      000466 19               [12] 1339 	dec	r1
      000467 19               [12] 1340 	dec	r1
      000468 19               [12] 1341 	dec	r1
                           0003B2  1342 	C$fuzzy.h$780$3_0$60 ==.
                                   1343 ;	/home/mahavigna/CI/fuzzy.h:780: firing_strength
      000469 8F 82            [24] 1344 	mov	dpl, r7
      00046B 8D 83            [24] 1345 	mov	dph, r5
      00046D 8C F0            [24] 1346 	mov	b, r4
      00046F EA               [12] 1347 	mov	a, r2
      000470 C0 03            [24] 1348 	push	ar3
      000472 12 00 B7         [24] 1349 	lcall	_fuzzy_clamp
      000475 AA 82            [24] 1350 	mov	r2, dpl
      000477 AC 83            [24] 1351 	mov	r4, dph
      000479 AE F0            [24] 1352 	mov	r6, b
      00047B FF               [12] 1353 	mov	r7, a
                           0003C5  1354 	C$fuzzy.h$793$1_0$56 ==.
                                   1355 ;	/home/mahavigna/CI/fuzzy.h:793: consequent;
      00047C E5 0E            [12] 1356 	mov	a,_bp
      00047E 24 05            [12] 1357 	add	a,#0x05
      000480 F8               [12] 1358 	mov	r0,a
      000481 E6               [12] 1359 	mov	a,@r0
      000482 C0 E0            [24] 1360 	push	acc
      000484 08               [12] 1361 	inc	r0
      000485 E6               [12] 1362 	mov	a,@r0
      000486 C0 E0            [24] 1363 	push	acc
      000488 08               [12] 1364 	inc	r0
      000489 E6               [12] 1365 	mov	a,@r0
      00048A C0 E0            [24] 1366 	push	acc
      00048C 08               [12] 1367 	inc	r0
      00048D E6               [12] 1368 	mov	a,@r0
      00048E C0 E0            [24] 1369 	push	acc
      000490 8A 82            [24] 1370 	mov	dpl, r2
      000492 8C 83            [24] 1371 	mov	dph, r4
      000494 8E F0            [24] 1372 	mov	b, r6
      000496 EF               [12] 1373 	mov	a, r7
      000497 12 10 4C         [24] 1374 	lcall	___fsmul
      00049A AC 82            [24] 1375 	mov	r4, dpl
      00049C AD 83            [24] 1376 	mov	r5, dph
      00049E AE F0            [24] 1377 	mov	r6, b
      0004A0 FF               [12] 1378 	mov	r7, a
      0004A1 E5 81            [12] 1379 	mov	a,sp
      0004A3 24 FC            [12] 1380 	add	a,#0xfc
      0004A5 F5 81            [12] 1381 	mov	sp,a
      0004A7 C0 04            [24] 1382 	push	ar4
      0004A9 C0 05            [24] 1383 	push	ar5
      0004AB C0 06            [24] 1384 	push	ar6
      0004AD C0 07            [24] 1385 	push	ar7
                           0003F8  1386 	C$fuzzy.h$764$1_0$56 ==.
                                   1387 ;	/home/mahavigna/CI/fuzzy.h:764: i++
      0004AF A8 0E            [24] 1388 	mov	r0,_bp
      0004B1 08               [12] 1389 	inc	r0
      0004B2 86 82            [24] 1390 	mov	dpl, @r0
      0004B4 08               [12] 1391 	inc	r0
      0004B5 86 83            [24] 1392 	mov	dph, @r0
      0004B7 08               [12] 1393 	inc	r0
      0004B8 86 F0            [24] 1394 	mov	b, @r0
      0004BA 08               [12] 1395 	inc	r0
      0004BB E6               [12] 1396 	mov	a, @r0
      0004BC 12 11 BD         [24] 1397 	lcall	___fsadd
      0004BF A8 0E            [24] 1398 	mov	r0,_bp
      0004C1 08               [12] 1399 	inc	r0
      0004C2 A6 82            [24] 1400 	mov	@r0, dpl
      0004C4 08               [12] 1401 	inc	r0
      0004C5 A6 83            [24] 1402 	mov	@r0, dph
      0004C7 08               [12] 1403 	inc	r0
      0004C8 A6 F0            [24] 1404 	mov	@r0, b
      0004CA 08               [12] 1405 	inc	r0
      0004CB F6               [12] 1406 	mov	@r0,a
      0004CC E5 81            [12] 1407 	mov	a,sp
      0004CE 24 FC            [12] 1408 	add	a,#0xfc
      0004D0 F5 81            [12] 1409 	mov	sp,a
      0004D2 D0 03            [24] 1410 	pop	ar3
      0004D4 E5 0E            [12] 1411 	mov	a,_bp
      0004D6 24 09            [12] 1412 	add	a,#0x09
      0004D8 F8               [12] 1413 	mov	r0,a
      0004D9 06               [12] 1414 	inc	@r0
      0004DA B6 00 02         [24] 1415 	cjne	@r0,#0x00,00133$
      0004DD 08               [12] 1416 	inc	r0
      0004DE 06               [12] 1417 	inc	@r0
      0004DF                       1418 00133$:
      0004DF 02 04 1A         [24] 1419 	ljmp	00105$
      0004E2                       1420 00103$:
                           00042B  1421 	C$fuzzy.h$798$1_0$56 ==.
                                   1422 ;	/home/mahavigna/CI/fuzzy.h:798: return weighted_sum;
      0004E2 A8 0E            [24] 1423 	mov	r0,_bp
      0004E4 08               [12] 1424 	inc	r0
      0004E5 86 82            [24] 1425 	mov	dpl, @r0
      0004E7 08               [12] 1426 	inc	r0
      0004E8 86 83            [24] 1427 	mov	dph, @r0
      0004EA 08               [12] 1428 	inc	r0
      0004EB 86 F0            [24] 1429 	mov	b, @r0
      0004ED 08               [12] 1430 	inc	r0
      0004EE E6               [12] 1431 	mov	a, @r0
      0004EF                       1432 00107$:
                           000438  1433 	C$fuzzy.h$799$1_0$56 ==.
                                   1434 ;	/home/mahavigna/CI/fuzzy.h:799: }
      0004EF 85 0E 81         [24] 1435 	mov	sp,_bp
      0004F2 D0 0E            [24] 1436 	pop	_bp
                           00043D  1437 	C$fuzzy.h$799$1_0$56 ==.
                           00043D  1438 	XG$fuzzy_sugeno_weighted_sum$0$0 ==.
      0004F4 22               [24] 1439 	ret
                                   1440 ;------------------------------------------------------------
                                   1441 ;Allocation info for local variables in function 'fuzzy_ramp'
                                   1442 ;------------------------------------------------------------
                                   1443 ;lower_boundary Allocated to stack - _bp -6 +4 
                                   1444 ;upper_boundary Allocated to stack - _bp -10 +4 
                                   1445 ;value         Allocated to stack - _bp -14 +4 
                                   1446 ;ramp_up       Allocated to stack - _bp -15 +1 
                                   1447 ;hedge         Allocated to stack - _bp -16 +1 
                                   1448 ;name          Allocated to registers 
                                   1449 ;result        Allocated to stack - _bp +5 +4 
                                   1450 ;normalized    Allocated to registers r7 r6 r5 r4 
                                   1451 ;sloc0         Allocated to stack - _bp +12 +4 
                                   1452 ;sloc1         Allocated to stack - _bp +1 +4 
                                   1453 ;------------------------------------------------------------
                           00043E  1454 	G$fuzzy_ramp$0$0 ==.
                           00043E  1455 	C$fuzzy.h$804$1_0$63 ==.
                                   1456 ;	/home/mahavigna/CI/fuzzy.h:804: float fuzzy_ramp(
                                   1457 ;	-----------------------------------------
                                   1458 ;	 function fuzzy_ramp
                                   1459 ;	-----------------------------------------
      0004F5                       1460 _fuzzy_ramp:
      0004F5 C0 0E            [24] 1461 	push	_bp
      0004F7 E5 81            [12] 1462 	mov	a,sp
      0004F9 F5 0E            [12] 1463 	mov	_bp,a
      0004FB 24 08            [12] 1464 	add	a,#0x08
      0004FD F5 81            [12] 1465 	mov	sp,a
                           000448  1466 	C$fuzzy.h$818$1_0$63 ==.
                                   1467 ;	/home/mahavigna/CI/fuzzy.h:818: if (lower_boundary >= upper_boundary) {
      0004FF E5 0E            [12] 1468 	mov	a,_bp
      000501 24 F6            [12] 1469 	add	a,#0xf6
      000503 F8               [12] 1470 	mov	r0,a
      000504 E6               [12] 1471 	mov	a,@r0
      000505 C0 E0            [24] 1472 	push	acc
      000507 08               [12] 1473 	inc	r0
      000508 E6               [12] 1474 	mov	a,@r0
      000509 C0 E0            [24] 1475 	push	acc
      00050B 08               [12] 1476 	inc	r0
      00050C E6               [12] 1477 	mov	a,@r0
      00050D C0 E0            [24] 1478 	push	acc
      00050F 08               [12] 1479 	inc	r0
      000510 E6               [12] 1480 	mov	a,@r0
      000511 C0 E0            [24] 1481 	push	acc
      000513 E5 0E            [12] 1482 	mov	a,_bp
      000515 24 FA            [12] 1483 	add	a,#0xfa
      000517 F8               [12] 1484 	mov	r0,a
      000518 86 82            [24] 1485 	mov	dpl, @r0
      00051A 08               [12] 1486 	inc	r0
      00051B 86 83            [24] 1487 	mov	dph, @r0
      00051D 08               [12] 1488 	inc	r0
      00051E 86 F0            [24] 1489 	mov	b, @r0
      000520 08               [12] 1490 	inc	r0
      000521 E6               [12] 1491 	mov	a, @r0
      000522 12 11 6B         [24] 1492 	lcall	___fslt
      000525 E5 81            [12] 1493 	mov	a,sp
      000527 24 FC            [12] 1494 	add	a,#0xfc
      000529 F5 81            [12] 1495 	mov	sp,a
      00052B E5 82            [12] 1496 	mov	a, dpl
      00052D 24 FF            [12] 1497 	add	a,#0xff
      00052F 92 00            [24] 1498 	mov	b0,c
      000531 40 09            [24] 1499 	jc	00102$
                           00047C  1500 	C$fuzzy.h$819$2_0$64 ==.
                                   1501 ;	/home/mahavigna/CI/fuzzy.h:819: return LEVEL_LO;
      000533 90 00 00         [24] 1502 	mov	dptr,#0x0000
      000536 E4               [12] 1503 	clr	a
      000537 F5 F0            [12] 1504 	mov	b,a
      000539 02 07 14         [24] 1505 	ljmp	00109$
      00053C                       1506 00102$:
                           000485  1507 	C$fuzzy.h$822$1_0$63 ==.
                                   1508 ;	/home/mahavigna/CI/fuzzy.h:822: if (value <= lower_boundary) {
      00053C E5 0E            [12] 1509 	mov	a,_bp
      00053E 24 F2            [12] 1510 	add	a,#0xf2
      000540 F8               [12] 1511 	mov	r0,a
      000541 E6               [12] 1512 	mov	a,@r0
      000542 C0 E0            [24] 1513 	push	acc
      000544 08               [12] 1514 	inc	r0
      000545 E6               [12] 1515 	mov	a,@r0
      000546 C0 E0            [24] 1516 	push	acc
      000548 08               [12] 1517 	inc	r0
      000549 E6               [12] 1518 	mov	a,@r0
      00054A C0 E0            [24] 1519 	push	acc
      00054C 08               [12] 1520 	inc	r0
      00054D E6               [12] 1521 	mov	a,@r0
      00054E C0 E0            [24] 1522 	push	acc
      000550 E5 0E            [12] 1523 	mov	a,_bp
      000552 24 FA            [12] 1524 	add	a,#0xfa
      000554 F8               [12] 1525 	mov	r0,a
      000555 86 82            [24] 1526 	mov	dpl, @r0
      000557 08               [12] 1527 	inc	r0
      000558 86 83            [24] 1528 	mov	dph, @r0
      00055A 08               [12] 1529 	inc	r0
      00055B 86 F0            [24] 1530 	mov	b, @r0
      00055D 08               [12] 1531 	inc	r0
      00055E E6               [12] 1532 	mov	a, @r0
      00055F 12 11 6B         [24] 1533 	lcall	___fslt
      000562 E5 81            [12] 1534 	mov	a,sp
      000564 24 FC            [12] 1535 	add	a,#0xfc
      000566 F5 81            [12] 1536 	mov	sp,a
      000568 E5 82            [12] 1537 	mov	a, dpl
      00056A 24 FF            [12] 1538 	add	a,#0xff
      00056C 92 00            [24] 1539 	mov	b0,c
      00056E 40 1D            [24] 1540 	jc	00107$
                           0004B9  1541 	C$fuzzy.h$824$2_0$65 ==.
                                   1542 ;	/home/mahavigna/CI/fuzzy.h:824: ramp_up
      000570 E5 0E            [12] 1543 	mov	a,_bp
      000572 24 F1            [12] 1544 	add	a,#0xf1
      000574 F8               [12] 1545 	mov	r0,a
      000575 E6               [12] 1546 	mov	a,@r0
      000576 60 0A            [24] 1547 	jz	00111$
                           0004C1  1548 	C$fuzzy.h$825$2_0$65 ==.
                                   1549 ;	/home/mahavigna/CI/fuzzy.h:825: ? LEVEL_LO
      000578 7C 00            [12] 1550 	mov	r4,#0x00
      00057A 7D 00            [12] 1551 	mov	r5,#0x00
      00057C 7E 00            [12] 1552 	mov	r6,#0x00
      00057E 7F 00            [12] 1553 	mov	r7,#0x00
      000580 80 08            [24] 1554 	sjmp	00112$
      000582                       1555 00111$:
                           0004CB  1556 	C$fuzzy.h$826$2_0$65 ==.
                                   1557 ;	/home/mahavigna/CI/fuzzy.h:826: : LEVEL_HI;
      000582 7C 00            [12] 1558 	mov	r4,#0x00
      000584 7D 00            [12] 1559 	mov	r5,#0x00
      000586 7E 80            [12] 1560 	mov	r6,#0x80
      000588 7F 3F            [12] 1561 	mov	r7,#0x3f
      00058A                       1562 00112$:
      00058A 02 06 F2         [24] 1563 	ljmp	00108$
      00058D                       1564 00107$:
                           0004D6  1565 	C$fuzzy.h$828$1_0$63 ==.
                                   1566 ;	/home/mahavigna/CI/fuzzy.h:828: else if (value >= upper_boundary) {
      00058D E5 0E            [12] 1567 	mov	a,_bp
      00058F 24 F6            [12] 1568 	add	a,#0xf6
      000591 F8               [12] 1569 	mov	r0,a
      000592 E6               [12] 1570 	mov	a,@r0
      000593 C0 E0            [24] 1571 	push	acc
      000595 08               [12] 1572 	inc	r0
      000596 E6               [12] 1573 	mov	a,@r0
      000597 C0 E0            [24] 1574 	push	acc
      000599 08               [12] 1575 	inc	r0
      00059A E6               [12] 1576 	mov	a,@r0
      00059B C0 E0            [24] 1577 	push	acc
      00059D 08               [12] 1578 	inc	r0
      00059E E6               [12] 1579 	mov	a,@r0
      00059F C0 E0            [24] 1580 	push	acc
      0005A1 E5 0E            [12] 1581 	mov	a,_bp
      0005A3 24 F2            [12] 1582 	add	a,#0xf2
      0005A5 F8               [12] 1583 	mov	r0,a
      0005A6 86 82            [24] 1584 	mov	dpl, @r0
      0005A8 08               [12] 1585 	inc	r0
      0005A9 86 83            [24] 1586 	mov	dph, @r0
      0005AB 08               [12] 1587 	inc	r0
      0005AC 86 F0            [24] 1588 	mov	b, @r0
      0005AE 08               [12] 1589 	inc	r0
      0005AF E6               [12] 1590 	mov	a, @r0
      0005B0 12 11 6B         [24] 1591 	lcall	___fslt
      0005B3 E5 81            [12] 1592 	mov	a,sp
      0005B5 24 FC            [12] 1593 	add	a,#0xfc
      0005B7 F5 81            [12] 1594 	mov	sp,a
      0005B9 E5 82            [12] 1595 	mov	a, dpl
      0005BB 24 FF            [12] 1596 	add	a,#0xff
      0005BD 92 00            [24] 1597 	mov	b0,c
      0005BF 40 39            [24] 1598 	jc	00104$
                           00050A  1599 	C$fuzzy.h$830$2_0$66 ==.
                                   1600 ;	/home/mahavigna/CI/fuzzy.h:830: ramp_up
      0005C1 E5 0E            [12] 1601 	mov	a,_bp
      0005C3 24 F1            [12] 1602 	add	a,#0xf1
      0005C5 F8               [12] 1603 	mov	r0,a
      0005C6 E6               [12] 1604 	mov	a,@r0
      0005C7 60 11            [24] 1605 	jz	00113$
                           000512  1606 	C$fuzzy.h$831$2_0$66 ==.
                                   1607 ;	/home/mahavigna/CI/fuzzy.h:831: ? LEVEL_HI
      0005C9 E5 0E            [12] 1608 	mov	a,_bp
      0005CB 24 05            [12] 1609 	add	a,#0x05
      0005CD F8               [12] 1610 	mov	r0,a
      0005CE E4               [12] 1611 	clr	a
      0005CF F6               [12] 1612 	mov	@r0,a
      0005D0 08               [12] 1613 	inc	r0
      0005D1 F6               [12] 1614 	mov	@r0,a
      0005D2 08               [12] 1615 	inc	r0
      0005D3 76 80            [12] 1616 	mov	@r0,#0x80
      0005D5 08               [12] 1617 	inc	r0
      0005D6 76 3F            [12] 1618 	mov	@r0,#0x3f
      0005D8 80 0D            [24] 1619 	sjmp	00114$
      0005DA                       1620 00113$:
                           000523  1621 	C$fuzzy.h$832$2_0$66 ==.
                                   1622 ;	/home/mahavigna/CI/fuzzy.h:832: : LEVEL_LO;
      0005DA E5 0E            [12] 1623 	mov	a,_bp
      0005DC 24 05            [12] 1624 	add	a,#0x05
      0005DE F8               [12] 1625 	mov	r0,a
      0005DF E4               [12] 1626 	clr	a
      0005E0 F6               [12] 1627 	mov	@r0,a
      0005E1 08               [12] 1628 	inc	r0
      0005E2 F6               [12] 1629 	mov	@r0,a
      0005E3 08               [12] 1630 	inc	r0
      0005E4 F6               [12] 1631 	mov	@r0,a
      0005E5 08               [12] 1632 	inc	r0
      0005E6 F6               [12] 1633 	mov	@r0,a
      0005E7                       1634 00114$:
      0005E7 E5 0E            [12] 1635 	mov	a,_bp
      0005E9 24 05            [12] 1636 	add	a,#0x05
      0005EB F8               [12] 1637 	mov	r0,a
      0005EC 86 04            [24] 1638 	mov	ar4,@r0
      0005EE 08               [12] 1639 	inc	r0
      0005EF 86 05            [24] 1640 	mov	ar5,@r0
      0005F1 08               [12] 1641 	inc	r0
      0005F2 86 06            [24] 1642 	mov	ar6,@r0
      0005F4 08               [12] 1643 	inc	r0
      0005F5 86 07            [24] 1644 	mov	ar7,@r0
      0005F7 02 06 F2         [24] 1645 	ljmp	00108$
      0005FA                       1646 00104$:
                           000543  1647 	C$fuzzy.h$836$1_0$63 ==.
                                   1648 ;	/home/mahavigna/CI/fuzzy.h:836: (value - lower_boundary) /
      0005FA E5 0E            [12] 1649 	mov	a,_bp
      0005FC 24 FA            [12] 1650 	add	a,#0xfa
      0005FE F8               [12] 1651 	mov	r0,a
      0005FF E6               [12] 1652 	mov	a,@r0
      000600 C0 E0            [24] 1653 	push	acc
      000602 08               [12] 1654 	inc	r0
      000603 E6               [12] 1655 	mov	a,@r0
      000604 C0 E0            [24] 1656 	push	acc
      000606 08               [12] 1657 	inc	r0
      000607 E6               [12] 1658 	mov	a,@r0
      000608 C0 E0            [24] 1659 	push	acc
      00060A 08               [12] 1660 	inc	r0
      00060B E6               [12] 1661 	mov	a,@r0
      00060C C0 E0            [24] 1662 	push	acc
                           000557  1663 	C$fuzzy.h$837$1_0$63 ==.
                                   1664 ;	/home/mahavigna/CI/fuzzy.h:837: (upper_boundary - lower_boundary);
      00060E E5 0E            [12] 1665 	mov	a,_bp
      000610 24 F2            [12] 1666 	add	a,#0xf2
      000612 F8               [12] 1667 	mov	r0,a
      000613 86 82            [24] 1668 	mov	dpl, @r0
      000615 08               [12] 1669 	inc	r0
      000616 86 83            [24] 1670 	mov	dph, @r0
      000618 08               [12] 1671 	inc	r0
      000619 86 F0            [24] 1672 	mov	b, @r0
      00061B 08               [12] 1673 	inc	r0
      00061C E6               [12] 1674 	mov	a, @r0
      00061D 12 10 41         [24] 1675 	lcall	___fssub
      000620 AF 82            [24] 1676 	mov	r7, dpl
      000622 AE 83            [24] 1677 	mov	r6, dph
      000624 AD F0            [24] 1678 	mov	r5, b
      000626 FC               [12] 1679 	mov	r4, a
      000627 E5 81            [12] 1680 	mov	a,sp
      000629 24 FC            [12] 1681 	add	a,#0xfc
      00062B F5 81            [12] 1682 	mov	sp,a
      00062D C0 07            [24] 1683 	push	ar7
      00062F C0 06            [24] 1684 	push	ar6
      000631 C0 05            [24] 1685 	push	ar5
      000633 C0 04            [24] 1686 	push	ar4
      000635 E5 0E            [12] 1687 	mov	a,_bp
      000637 24 FA            [12] 1688 	add	a,#0xfa
      000639 F8               [12] 1689 	mov	r0,a
      00063A E6               [12] 1690 	mov	a,@r0
      00063B C0 E0            [24] 1691 	push	acc
      00063D 08               [12] 1692 	inc	r0
      00063E E6               [12] 1693 	mov	a,@r0
      00063F C0 E0            [24] 1694 	push	acc
      000641 08               [12] 1695 	inc	r0
      000642 E6               [12] 1696 	mov	a,@r0
      000643 C0 E0            [24] 1697 	push	acc
      000645 08               [12] 1698 	inc	r0
      000646 E6               [12] 1699 	mov	a,@r0
      000647 C0 E0            [24] 1700 	push	acc
      000649 E5 0E            [12] 1701 	mov	a,_bp
      00064B 24 F6            [12] 1702 	add	a,#0xf6
      00064D F8               [12] 1703 	mov	r0,a
      00064E 86 82            [24] 1704 	mov	dpl, @r0
      000650 08               [12] 1705 	inc	r0
      000651 86 83            [24] 1706 	mov	dph, @r0
      000653 08               [12] 1707 	inc	r0
      000654 86 F0            [24] 1708 	mov	b, @r0
      000656 08               [12] 1709 	inc	r0
      000657 E6               [12] 1710 	mov	a, @r0
      000658 12 10 41         [24] 1711 	lcall	___fssub
      00065B A8 0E            [24] 1712 	mov	r0,_bp
      00065D 08               [12] 1713 	inc	r0
      00065E A6 82            [24] 1714 	mov	@r0, dpl
      000660 08               [12] 1715 	inc	r0
      000661 A6 83            [24] 1716 	mov	@r0, dph
      000663 08               [12] 1717 	inc	r0
      000664 A6 F0            [24] 1718 	mov	@r0, b
      000666 08               [12] 1719 	inc	r0
      000667 F6               [12] 1720 	mov	@r0,a
      000668 E5 81            [12] 1721 	mov	a,sp
      00066A 24 FC            [12] 1722 	add	a,#0xfc
      00066C F5 81            [12] 1723 	mov	sp,a
      00066E D0 04            [24] 1724 	pop	ar4
      000670 D0 05            [24] 1725 	pop	ar5
      000672 D0 06            [24] 1726 	pop	ar6
      000674 D0 07            [24] 1727 	pop	ar7
      000676 A8 0E            [24] 1728 	mov	r0,_bp
      000678 08               [12] 1729 	inc	r0
      000679 E6               [12] 1730 	mov	a,@r0
      00067A C0 E0            [24] 1731 	push	acc
      00067C 08               [12] 1732 	inc	r0
      00067D E6               [12] 1733 	mov	a,@r0
      00067E C0 E0            [24] 1734 	push	acc
      000680 08               [12] 1735 	inc	r0
      000681 E6               [12] 1736 	mov	a,@r0
      000682 C0 E0            [24] 1737 	push	acc
      000684 08               [12] 1738 	inc	r0
      000685 E6               [12] 1739 	mov	a,@r0
      000686 C0 E0            [24] 1740 	push	acc
                           0005D1  1741 	C$fuzzy.h$840$1_0$63 ==.
                                   1742 ;	/home/mahavigna/CI/fuzzy.h:840: ramp_up
      000688 8F 82            [24] 1743 	mov	dpl, r7
      00068A 8E 83            [24] 1744 	mov	dph, r6
      00068C 8D F0            [24] 1745 	mov	b, r5
      00068E EC               [12] 1746 	mov	a, r4
      00068F 12 12 C8         [24] 1747 	lcall	___fsdiv
      000692 AF 82            [24] 1748 	mov	r7, dpl
      000694 AE 83            [24] 1749 	mov	r6, dph
      000696 AD F0            [24] 1750 	mov	r5, b
      000698 FC               [12] 1751 	mov	r4, a
      000699 E5 81            [12] 1752 	mov	a,sp
      00069B 24 FC            [12] 1753 	add	a,#0xfc
      00069D F5 81            [12] 1754 	mov	sp,a
      00069F E5 0E            [12] 1755 	mov	a,_bp
      0006A1 24 F1            [12] 1756 	add	a,#0xf1
      0006A3 F8               [12] 1757 	mov	r0,a
      0006A4 E6               [12] 1758 	mov	a,@r0
      0006A5 60 12            [24] 1759 	jz	00115$
                           0005F0  1760 	C$fuzzy.h$841$2_0$67 ==.
                                   1761 ;	/home/mahavigna/CI/fuzzy.h:841: ? normalized
      0006A7 E5 0E            [12] 1762 	mov	a,_bp
      0006A9 24 05            [12] 1763 	add	a,#0x05
      0006AB F8               [12] 1764 	mov	r0,a
      0006AC A6 07            [24] 1765 	mov	@r0,ar7
      0006AE 08               [12] 1766 	inc	r0
      0006AF A6 06            [24] 1767 	mov	@r0,ar6
      0006B1 08               [12] 1768 	inc	r0
      0006B2 A6 05            [24] 1769 	mov	@r0,ar5
      0006B4 08               [12] 1770 	inc	r0
      0006B5 A6 04            [24] 1771 	mov	@r0,ar4
      0006B7 80 29            [24] 1772 	sjmp	00116$
      0006B9                       1773 00115$:
                           000602  1774 	C$fuzzy.h$842$1_0$63 ==.
                                   1775 ;	/home/mahavigna/CI/fuzzy.h:842: : LEVEL_HI - normalized;
      0006B9 C0 07            [24] 1776 	push	ar7
      0006BB C0 06            [24] 1777 	push	ar6
      0006BD C0 05            [24] 1778 	push	ar5
      0006BF C0 04            [24] 1779 	push	ar4
      0006C1 90 00 00         [24] 1780 	mov	dptr,#0x0000
      0006C4 75 F0 80         [24] 1781 	mov	b, #0x80
      0006C7 74 3F            [12] 1782 	mov	a, #0x3f
      0006C9 12 10 41         [24] 1783 	lcall	___fssub
      0006CC C8               [12] 1784 	xch	a,r0
      0006CD E5 0E            [12] 1785 	mov	a,_bp
      0006CF 24 05            [12] 1786 	add	a,#0x05
      0006D1 C8               [12] 1787 	xch	a,r0
      0006D2 A6 82            [24] 1788 	mov	@r0, dpl
      0006D4 08               [12] 1789 	inc	r0
      0006D5 A6 83            [24] 1790 	mov	@r0, dph
      0006D7 08               [12] 1791 	inc	r0
      0006D8 A6 F0            [24] 1792 	mov	@r0, b
      0006DA 08               [12] 1793 	inc	r0
      0006DB F6               [12] 1794 	mov	@r0,a
      0006DC E5 81            [12] 1795 	mov	a,sp
      0006DE 24 FC            [12] 1796 	add	a,#0xfc
      0006E0 F5 81            [12] 1797 	mov	sp,a
      0006E2                       1798 00116$:
      0006E2 E5 0E            [12] 1799 	mov	a,_bp
      0006E4 24 05            [12] 1800 	add	a,#0x05
      0006E6 F8               [12] 1801 	mov	r0,a
      0006E7 86 04            [24] 1802 	mov	ar4,@r0
      0006E9 08               [12] 1803 	inc	r0
      0006EA 86 05            [24] 1804 	mov	ar5,@r0
      0006EC 08               [12] 1805 	inc	r0
      0006ED 86 06            [24] 1806 	mov	ar6,@r0
      0006EF 08               [12] 1807 	inc	r0
      0006F0 86 07            [24] 1808 	mov	ar7,@r0
      0006F2                       1809 00108$:
                           00063B  1810 	C$fuzzy.h$846$1_0$63 ==.
                                   1811 ;	/home/mahavigna/CI/fuzzy.h:846: result,
      0006F2 E5 0E            [12] 1812 	mov	a,_bp
      0006F4 24 F0            [12] 1813 	add	a,#0xf0
      0006F6 F8               [12] 1814 	mov	r0,a
      0006F7 E6               [12] 1815 	mov	a,@r0
      0006F8 C0 E0            [24] 1816 	push	acc
      0006FA 8C 82            [24] 1817 	mov	dpl, r4
      0006FC 8D 83            [24] 1818 	mov	dph, r5
      0006FE 8E F0            [24] 1819 	mov	b, r6
      000700 EF               [12] 1820 	mov	a, r7
      000701 12 01 66         [24] 1821 	lcall	_fuzzy_apply_hedge
      000704 AC 82            [24] 1822 	mov	r4, dpl
      000706 AD 83            [24] 1823 	mov	r5, dph
      000708 AE F0            [24] 1824 	mov	r6, b
      00070A FF               [12] 1825 	mov	r7, a
      00070B 15 81            [12] 1826 	dec	sp
      00070D 8C 82            [24] 1827 	mov	dpl, r4
      00070F 8D 83            [24] 1828 	mov	dph, r5
      000711 8E F0            [24] 1829 	mov	b, r6
      000713 EF               [12] 1830 	mov	a, r7
      000714                       1831 00109$:
                           00065D  1832 	C$fuzzy.h$849$1_0$63 ==.
                                   1833 ;	/home/mahavigna/CI/fuzzy.h:849: }
      000714 85 0E 81         [24] 1834 	mov	sp,_bp
      000717 D0 0E            [24] 1835 	pop	_bp
                           000662  1836 	C$fuzzy.h$849$1_0$63 ==.
                           000662  1837 	XG$fuzzy_ramp$0$0 ==.
      000719 22               [24] 1838 	ret
                                   1839 ;------------------------------------------------------------
                                   1840 ;Allocation info for local variables in function 'fuzzy_rules_create'
                                   1841 ;------------------------------------------------------------
                                   1842 ;rules         Allocated to registers r5 r6 r7 
                                   1843 ;------------------------------------------------------------
                           000663  1844 	G$fuzzy_rules_create$0$0 ==.
                           000663  1845 	C$fuzzy.h$1267$1_0$69 ==.
                                   1846 ;	/home/mahavigna/CI/fuzzy.h:1267: void fuzzy_rules_create(
                                   1847 ;	-----------------------------------------
                                   1848 ;	 function fuzzy_rules_create
                                   1849 ;	-----------------------------------------
      00071A                       1850 _fuzzy_rules_create:
      00071A AD 82            [24] 1851 	mov	r5, dpl
      00071C AE 83            [24] 1852 	mov	r6, dph
      00071E AF F0            [24] 1853 	mov	r7, b
                           000669  1854 	C$fuzzy.h$1271$1_0$69 ==.
                                   1855 ;	/home/mahavigna/CI/fuzzy.h:1271: if (rules == NULL) {
      000720 ED               [12] 1856 	mov	a,r5
      000721 4E               [12] 1857 	orl	a,r6
      000722 70 02            [24] 1858 	jnz	00102$
                           00066D  1859 	C$fuzzy.h$1272$2_0$70 ==.
                                   1860 ;	/home/mahavigna/CI/fuzzy.h:1272: return;
      000724 80 15            [24] 1861 	sjmp	00103$
      000726                       1862 00102$:
                           00066F  1863 	C$fuzzy.h$1275$1_0$69 ==.
                                   1864 ;	/home/mahavigna/CI/fuzzy.h:1275: rules->count = 0;
      000726 74 0C            [12] 1865 	mov	a,#0x0c
      000728 2D               [12] 1866 	add	a, r5
      000729 FD               [12] 1867 	mov	r5,a
      00072A E4               [12] 1868 	clr	a
      00072B 3E               [12] 1869 	addc	a, r6
      00072C FE               [12] 1870 	mov	r6,a
      00072D 8D 82            [24] 1871 	mov	dpl,r5
      00072F 8E 83            [24] 1872 	mov	dph,r6
      000731 8F F0            [24] 1873 	mov	b,r7
      000733 E4               [12] 1874 	clr	a
      000734 12 11 50         [24] 1875 	lcall	__gptrput
      000737 A3               [24] 1876 	inc	dptr
      000738 12 11 50         [24] 1877 	lcall	__gptrput
      00073B                       1878 00103$:
                           000684  1879 	C$fuzzy.h$1276$1_0$69 ==.
                                   1880 ;	/home/mahavigna/CI/fuzzy.h:1276: }
                           000684  1881 	C$fuzzy.h$1276$1_0$69 ==.
                           000684  1882 	XG$fuzzy_rules_create$0$0 ==.
      00073B 22               [24] 1883 	ret
                                   1884 ;------------------------------------------------------------
                                   1885 ;Allocation info for local variables in function 'fuzzy_rules_add'
                                   1886 ;------------------------------------------------------------
                                   1887 ;name          Allocated to stack - _bp -5 +3 
                                   1888 ;value         Allocated to stack - _bp -9 +4 
                                   1889 ;output_function Allocated to stack - _bp -11 +2 
                                   1890 ;rules         Allocated to stack - _bp +1 +3 
                                   1891 ;index         Allocated to registers 
                                   1892 ;sloc0         Allocated to stack - _bp +6 +2 
                                   1893 ;sloc1         Allocated to stack - _bp +4 +3 
                                   1894 ;sloc2         Allocated to stack - _bp +7 +3 
                                   1895 ;------------------------------------------------------------
                           000685  1896 	G$fuzzy_rules_add$0$0 ==.
                           000685  1897 	C$fuzzy.h$1279$1_0$72 ==.
                                   1898 ;	/home/mahavigna/CI/fuzzy.h:1279: bool fuzzy_rules_add(
                                   1899 ;	-----------------------------------------
                                   1900 ;	 function fuzzy_rules_add
                                   1901 ;	-----------------------------------------
      00073C                       1902 _fuzzy_rules_add:
      00073C C0 0E            [24] 1903 	push	_bp
      00073E 85 81 0E         [24] 1904 	mov	_bp,sp
      000741 C0 82            [24] 1905 	push	dpl
      000743 C0 83            [24] 1906 	push	dph
      000745 C0 F0            [24] 1907 	push	b
      000747 E5 81            [12] 1908 	mov	a,sp
      000749 24 06            [12] 1909 	add	a,#0x06
      00074B F5 81            [12] 1910 	mov	sp,a
                           000696  1911 	C$fuzzy.h$1289$1_0$72 ==.
                                   1912 ;	/home/mahavigna/CI/fuzzy.h:1289: rules == NULL ||
      00074D A8 0E            [24] 1913 	mov	r0,_bp
      00074F 08               [12] 1914 	inc	r0
      000750 E6               [12] 1915 	mov	a,@r0
      000751 08               [12] 1916 	inc	r0
      000752 46               [12] 1917 	orl	a,@r0
      000753 60 0A            [24] 1918 	jz	00101$
                           00069E  1919 	C$fuzzy.h$1290$1_0$72 ==.
                                   1920 ;	/home/mahavigna/CI/fuzzy.h:1290: output_function == NULL
      000755 E5 0E            [12] 1921 	mov	a,_bp
      000757 24 F5            [12] 1922 	add	a,#0xf5
      000759 F8               [12] 1923 	mov	r0,a
      00075A E6               [12] 1924 	mov	a,@r0
      00075B 08               [12] 1925 	inc	r0
      00075C 46               [12] 1926 	orl	a,@r0
      00075D 70 06            [24] 1927 	jnz	00102$
      00075F                       1928 00101$:
                           0006A8  1929 	C$fuzzy.h$1292$2_0$73 ==.
                                   1930 ;	/home/mahavigna/CI/fuzzy.h:1292: return false;
      00075F 75 82 00         [24] 1931 	mov	dpl, #0x00
      000762 02 08 63         [24] 1932 	ljmp	00106$
      000765                       1933 00102$:
                           0006AE  1934 	C$fuzzy.h$1295$1_0$72 ==.
                                   1935 ;	/home/mahavigna/CI/fuzzy.h:1295: if (rules->count >= FUZZY_MAX_RULES) {
      000765 A8 0E            [24] 1936 	mov	r0,_bp
      000767 08               [12] 1937 	inc	r0
      000768 E5 0E            [12] 1938 	mov	a,_bp
      00076A 24 07            [12] 1939 	add	a,#0x07
      00076C F9               [12] 1940 	mov	r1,a
      00076D 74 0C            [12] 1941 	mov	a,#0x0c
      00076F 26               [12] 1942 	add	a, @r0
      000770 F7               [12] 1943 	mov	@r1,a
      000771 E4               [12] 1944 	clr	a
      000772 08               [12] 1945 	inc	r0
      000773 36               [12] 1946 	addc	a, @r0
      000774 09               [12] 1947 	inc	r1
      000775 F7               [12] 1948 	mov	@r1,a
      000776 08               [12] 1949 	inc	r0
      000777 E6               [12] 1950 	mov	a,@r0
      000778 09               [12] 1951 	inc	r1
      000779 F7               [12] 1952 	mov	@r1,a
      00077A E5 0E            [12] 1953 	mov	a,_bp
      00077C 24 07            [12] 1954 	add	a,#0x07
      00077E F8               [12] 1955 	mov	r0,a
      00077F 86 82            [24] 1956 	mov	dpl,@r0
      000781 08               [12] 1957 	inc	r0
      000782 86 83            [24] 1958 	mov	dph,@r0
      000784 08               [12] 1959 	inc	r0
      000785 86 F0            [24] 1960 	mov	b,@r0
      000787 12 13 8B         [24] 1961 	lcall	__gptrget
      00078A FF               [12] 1962 	mov	r7,a
      00078B A3               [24] 1963 	inc	dptr
      00078C 12 13 8B         [24] 1964 	lcall	__gptrget
      00078F FE               [12] 1965 	mov	r6,a
      000790 C3               [12] 1966 	clr	c
      000791 EF               [12] 1967 	mov	a,r7
      000792 94 02            [12] 1968 	subb	a,#0x02
      000794 EE               [12] 1969 	mov	a,r6
      000795 94 00            [12] 1970 	subb	a,#0x00
      000797 40 06            [24] 1971 	jc	00105$
                           0006E2  1972 	C$fuzzy.h$1304$2_0$74 ==.
                                   1973 ;	/home/mahavigna/CI/fuzzy.h:1304: return false;
      000799 75 82 00         [24] 1974 	mov	dpl, #0x00
      00079C 02 08 63         [24] 1975 	ljmp	00106$
      00079F                       1976 00105$:
                           0006E8  1977 	C$fuzzy.h$1321$1_0$72 ==.
                                   1978 ;	/home/mahavigna/CI/fuzzy.h:1321: rules->rules[index].value =
      00079F C0 07            [24] 1979 	push	ar7
      0007A1 C0 06            [24] 1980 	push	ar6
      0007A3 90 00 06         [24] 1981 	mov	dptr,#0x0006
      0007A6 12 11 9B         [24] 1982 	lcall	__mulint
      0007A9 AB 82            [24] 1983 	mov	r3, dpl
      0007AB AA 83            [24] 1984 	mov	r2, dph
      0007AD 15 81            [12] 1985 	dec	sp
      0007AF 15 81            [12] 1986 	dec	sp
      0007B1 A8 0E            [24] 1987 	mov	r0,_bp
      0007B3 08               [12] 1988 	inc	r0
      0007B4 E5 0E            [12] 1989 	mov	a,_bp
      0007B6 24 04            [12] 1990 	add	a,#0x04
      0007B8 F9               [12] 1991 	mov	r1,a
      0007B9 EB               [12] 1992 	mov	a,r3
      0007BA 26               [12] 1993 	add	a, @r0
      0007BB F7               [12] 1994 	mov	@r1,a
      0007BC EA               [12] 1995 	mov	a,r2
      0007BD 08               [12] 1996 	inc	r0
      0007BE 36               [12] 1997 	addc	a, @r0
      0007BF 09               [12] 1998 	inc	r1
      0007C0 F7               [12] 1999 	mov	@r1,a
      0007C1 08               [12] 2000 	inc	r0
      0007C2 E6               [12] 2001 	mov	a,@r0
      0007C3 09               [12] 2002 	inc	r1
      0007C4 F7               [12] 2003 	mov	@r1,a
                           00070E  2004 	C$fuzzy.h$1322$1_0$72 ==.
                                   2005 ;	/home/mahavigna/CI/fuzzy.h:1322: fuzzy_clamp(value);
      0007C5 E5 0E            [12] 2006 	mov	a,_bp
      0007C7 24 F7            [12] 2007 	add	a,#0xf7
      0007C9 F8               [12] 2008 	mov	r0,a
      0007CA 86 82            [24] 2009 	mov	dpl, @r0
      0007CC 08               [12] 2010 	inc	r0
      0007CD 86 83            [24] 2011 	mov	dph, @r0
      0007CF 08               [12] 2012 	inc	r0
      0007D0 86 F0            [24] 2013 	mov	b, @r0
      0007D2 08               [12] 2014 	inc	r0
      0007D3 E6               [12] 2015 	mov	a, @r0
      0007D4 C0 03            [24] 2016 	push	ar3
      0007D6 C0 02            [24] 2017 	push	ar2
      0007D8 12 00 B7         [24] 2018 	lcall	_fuzzy_clamp
      0007DB AD 82            [24] 2019 	mov	r5, dpl
      0007DD AE 83            [24] 2020 	mov	r6, dph
      0007DF AC F0            [24] 2021 	mov	r4, b
      0007E1 FF               [12] 2022 	mov	r7, a
      0007E2 D0 02            [24] 2023 	pop	ar2
      0007E4 D0 03            [24] 2024 	pop	ar3
      0007E6 E5 0E            [12] 2025 	mov	a,_bp
      0007E8 24 04            [12] 2026 	add	a,#0x04
      0007EA F8               [12] 2027 	mov	r0,a
      0007EB 86 82            [24] 2028 	mov	dpl,@r0
      0007ED 08               [12] 2029 	inc	r0
      0007EE 86 83            [24] 2030 	mov	dph,@r0
      0007F0 08               [12] 2031 	inc	r0
      0007F1 86 F0            [24] 2032 	mov	b,@r0
      0007F3 ED               [12] 2033 	mov	a,r5
      0007F4 12 11 50         [24] 2034 	lcall	__gptrput
      0007F7 A3               [24] 2035 	inc	dptr
      0007F8 EE               [12] 2036 	mov	a,r6
      0007F9 12 11 50         [24] 2037 	lcall	__gptrput
      0007FC A3               [24] 2038 	inc	dptr
      0007FD EC               [12] 2039 	mov	a,r4
      0007FE 12 11 50         [24] 2040 	lcall	__gptrput
      000801 A3               [24] 2041 	inc	dptr
      000802 EF               [12] 2042 	mov	a,r7
      000803 12 11 50         [24] 2043 	lcall	__gptrput
                           00074F  2044 	C$fuzzy.h$1324$1_0$72 ==.
                                   2045 ;	/home/mahavigna/CI/fuzzy.h:1324: rules->rules[index].output_function =
      000806 A8 0E            [24] 2046 	mov	r0,_bp
      000808 08               [12] 2047 	inc	r0
      000809 EB               [12] 2048 	mov	a,r3
      00080A 26               [12] 2049 	add	a, @r0
      00080B FD               [12] 2050 	mov	r5,a
      00080C EA               [12] 2051 	mov	a,r2
      00080D 08               [12] 2052 	inc	r0
      00080E 36               [12] 2053 	addc	a, @r0
      00080F FE               [12] 2054 	mov	r6,a
      000810 08               [12] 2055 	inc	r0
      000811 86 07            [24] 2056 	mov	ar7,@r0
      000813 74 04            [12] 2057 	mov	a,#0x04
      000815 2D               [12] 2058 	add	a, r5
      000816 FD               [12] 2059 	mov	r5,a
      000817 E4               [12] 2060 	clr	a
      000818 3E               [12] 2061 	addc	a, r6
      000819 FE               [12] 2062 	mov	r6,a
      00081A 8D 82            [24] 2063 	mov	dpl,r5
      00081C 8E 83            [24] 2064 	mov	dph,r6
      00081E 8F F0            [24] 2065 	mov	b,r7
      000820 E5 0E            [12] 2066 	mov	a,_bp
      000822 24 F5            [12] 2067 	add	a,#0xf5
      000824 F8               [12] 2068 	mov	r0,a
      000825 E6               [12] 2069 	mov	a,@r0
      000826 12 11 50         [24] 2070 	lcall	__gptrput
      000829 A3               [24] 2071 	inc	dptr
      00082A 08               [12] 2072 	inc	r0
      00082B E6               [12] 2073 	mov	a,@r0
      00082C 12 11 50         [24] 2074 	lcall	__gptrput
                           000778  2075 	C$fuzzy.h$1327$1_0$72 ==.
                                   2076 ;	/home/mahavigna/CI/fuzzy.h:1327: rules->count++;
      00082F E5 0E            [12] 2077 	mov	a,_bp
      000831 24 07            [12] 2078 	add	a,#0x07
      000833 F8               [12] 2079 	mov	r0,a
      000834 86 82            [24] 2080 	mov	dpl,@r0
      000836 08               [12] 2081 	inc	r0
      000837 86 83            [24] 2082 	mov	dph,@r0
      000839 08               [12] 2083 	inc	r0
      00083A 86 F0            [24] 2084 	mov	b,@r0
      00083C 12 13 8B         [24] 2085 	lcall	__gptrget
      00083F FE               [12] 2086 	mov	r6,a
      000840 A3               [24] 2087 	inc	dptr
      000841 12 13 8B         [24] 2088 	lcall	__gptrget
      000844 FF               [12] 2089 	mov	r7,a
      000845 0E               [12] 2090 	inc	r6
      000846 BE 00 01         [24] 2091 	cjne	r6,#0x00,00123$
      000849 0F               [12] 2092 	inc	r7
      00084A                       2093 00123$:
      00084A E5 0E            [12] 2094 	mov	a,_bp
      00084C 24 07            [12] 2095 	add	a,#0x07
      00084E F8               [12] 2096 	mov	r0,a
      00084F 86 82            [24] 2097 	mov	dpl,@r0
      000851 08               [12] 2098 	inc	r0
      000852 86 83            [24] 2099 	mov	dph,@r0
      000854 08               [12] 2100 	inc	r0
      000855 86 F0            [24] 2101 	mov	b,@r0
      000857 EE               [12] 2102 	mov	a,r6
      000858 12 11 50         [24] 2103 	lcall	__gptrput
      00085B A3               [24] 2104 	inc	dptr
      00085C EF               [12] 2105 	mov	a,r7
      00085D 12 11 50         [24] 2106 	lcall	__gptrput
                           0007A9  2107 	C$fuzzy.h$1329$1_0$72 ==.
                                   2108 ;	/home/mahavigna/CI/fuzzy.h:1329: return true;
      000860 75 82 01         [24] 2109 	mov	dpl, #0x01
      000863                       2110 00106$:
                           0007AC  2111 	C$fuzzy.h$1330$1_0$72 ==.
                                   2112 ;	/home/mahavigna/CI/fuzzy.h:1330: }
      000863 85 0E 81         [24] 2113 	mov	sp,_bp
      000866 D0 0E            [24] 2114 	pop	_bp
                           0007B1  2115 	C$fuzzy.h$1330$1_0$72 ==.
                           0007B1  2116 	XG$fuzzy_rules_add$0$0 ==.
      000868 22               [24] 2117 	ret
                                   2118 ;------------------------------------------------------------
                                   2119 ;Allocation info for local variables in function 'fuzzy_rules_cog'
                                   2120 ;------------------------------------------------------------
                                   2121 ;lower         Allocated to stack - _bp -6 +4 
                                   2122 ;upper         Allocated to stack - _bp -10 +4 
                                   2123 ;step          Allocated to stack - _bp -14 +4 
                                   2124 ;rules         Allocated to stack - _bp +1 +3 
                                   2125 ;weighted_sum  Allocated to stack - _bp +14 +4 
                                   2126 ;height_sum    Allocated to stack - _bp +18 +4 
                                   2127 ;value         Allocated to stack - _bp +22 +4 
                                   2128 ;aggregated_height Allocated to stack - _bp +26 +4 
                                   2129 ;output_membership Allocated to stack - _bp +30 +4 
                                   2130 ;clipped_height Allocated to stack - _bp +34 +4 
                                   2131 ;i             Allocated to stack - _bp +38 +2 
                                   2132 ;sloc0         Allocated to stack - _bp +4 +3 
                                   2133 ;sloc1         Allocated to stack - _bp +7 +3 
                                   2134 ;sloc2         Allocated to stack - _bp +10 +4 
                                   2135 ;------------------------------------------------------------
                           0007B2  2136 	G$fuzzy_rules_cog$0$0 ==.
                           0007B2  2137 	C$fuzzy.h$1363$1_0$76 ==.
                                   2138 ;	/home/mahavigna/CI/fuzzy.h:1363: float fuzzy_rules_cog(
                                   2139 ;	-----------------------------------------
                                   2140 ;	 function fuzzy_rules_cog
                                   2141 ;	-----------------------------------------
      000869                       2142 _fuzzy_rules_cog:
      000869 C0 0E            [24] 2143 	push	_bp
      00086B 85 81 0E         [24] 2144 	mov	_bp,sp
      00086E C0 82            [24] 2145 	push	dpl
      000870 C0 83            [24] 2146 	push	dph
      000872 C0 F0            [24] 2147 	push	b
      000874 E5 81            [12] 2148 	mov	a,sp
      000876 24 24            [12] 2149 	add	a,#0x24
      000878 F5 81            [12] 2150 	mov	sp,a
                           0007C3  2151 	C$fuzzy.h$1379$1_0$76 ==.
                                   2152 ;	/home/mahavigna/CI/fuzzy.h:1379: rules == NULL ||
      00087A A8 0E            [24] 2153 	mov	r0,_bp
      00087C 08               [12] 2154 	inc	r0
      00087D E6               [12] 2155 	mov	a,@r0
      00087E 08               [12] 2156 	inc	r0
      00087F 46               [12] 2157 	orl	a,@r0
      000880 70 03            [24] 2158 	jnz	00183$
      000882 02 09 0E         [24] 2159 	ljmp	00101$
      000885                       2160 00183$:
                           0007CE  2161 	C$fuzzy.h$1380$1_0$76 ==.
                                   2162 ;	/home/mahavigna/CI/fuzzy.h:1380: rules->count == 0 ||
      000885 A8 0E            [24] 2163 	mov	r0,_bp
      000887 08               [12] 2164 	inc	r0
      000888 E5 0E            [12] 2165 	mov	a,_bp
      00088A 24 04            [12] 2166 	add	a,#0x04
      00088C F9               [12] 2167 	mov	r1,a
      00088D 74 0C            [12] 2168 	mov	a,#0x0c
      00088F 26               [12] 2169 	add	a, @r0
      000890 F7               [12] 2170 	mov	@r1,a
      000891 E4               [12] 2171 	clr	a
      000892 08               [12] 2172 	inc	r0
      000893 36               [12] 2173 	addc	a, @r0
      000894 09               [12] 2174 	inc	r1
      000895 F7               [12] 2175 	mov	@r1,a
      000896 08               [12] 2176 	inc	r0
      000897 E6               [12] 2177 	mov	a,@r0
      000898 09               [12] 2178 	inc	r1
      000899 F7               [12] 2179 	mov	@r1,a
      00089A E5 0E            [12] 2180 	mov	a,_bp
      00089C 24 04            [12] 2181 	add	a,#0x04
      00089E F8               [12] 2182 	mov	r0,a
      00089F 86 82            [24] 2183 	mov	dpl,@r0
      0008A1 08               [12] 2184 	inc	r0
      0008A2 86 83            [24] 2185 	mov	dph,@r0
      0008A4 08               [12] 2186 	inc	r0
      0008A5 86 F0            [24] 2187 	mov	b,@r0
      0008A7 12 13 8B         [24] 2188 	lcall	__gptrget
      0008AA FE               [12] 2189 	mov	r6,a
      0008AB A3               [24] 2190 	inc	dptr
      0008AC 12 13 8B         [24] 2191 	lcall	__gptrget
      0008AF 4E               [12] 2192 	orl	a,r6
      0008B0 60 5C            [24] 2193 	jz	00101$
                           0007FB  2194 	C$fuzzy.h$1381$1_0$76 ==.
                                   2195 ;	/home/mahavigna/CI/fuzzy.h:1381: lower > upper ||
      0008B2 E5 0E            [12] 2196 	mov	a,_bp
      0008B4 24 FA            [12] 2197 	add	a,#0xfa
      0008B6 F8               [12] 2198 	mov	r0,a
      0008B7 E6               [12] 2199 	mov	a,@r0
      0008B8 C0 E0            [24] 2200 	push	acc
      0008BA 08               [12] 2201 	inc	r0
      0008BB E6               [12] 2202 	mov	a,@r0
      0008BC C0 E0            [24] 2203 	push	acc
      0008BE 08               [12] 2204 	inc	r0
      0008BF E6               [12] 2205 	mov	a,@r0
      0008C0 C0 E0            [24] 2206 	push	acc
      0008C2 08               [12] 2207 	inc	r0
      0008C3 E6               [12] 2208 	mov	a,@r0
      0008C4 C0 E0            [24] 2209 	push	acc
      0008C6 E5 0E            [12] 2210 	mov	a,_bp
      0008C8 24 F6            [12] 2211 	add	a,#0xf6
      0008CA F8               [12] 2212 	mov	r0,a
      0008CB 86 82            [24] 2213 	mov	dpl, @r0
      0008CD 08               [12] 2214 	inc	r0
      0008CE 86 83            [24] 2215 	mov	dph, @r0
      0008D0 08               [12] 2216 	inc	r0
      0008D1 86 F0            [24] 2217 	mov	b, @r0
      0008D3 08               [12] 2218 	inc	r0
      0008D4 E6               [12] 2219 	mov	a, @r0
      0008D5 12 11 6B         [24] 2220 	lcall	___fslt
      0008D8 AF 82            [24] 2221 	mov	r7, dpl
      0008DA E5 81            [12] 2222 	mov	a,sp
      0008DC 24 FC            [12] 2223 	add	a,#0xfc
      0008DE F5 81            [12] 2224 	mov	sp,a
      0008E0 EF               [12] 2225 	mov	a,r7
      0008E1 70 2B            [24] 2226 	jnz	00101$
                           00082C  2227 	C$fuzzy.h$1383$1_0$76 ==.
                                   2228 ;	/home/mahavigna/CI/fuzzy.h:1383: ) {
      0008E3 E5 0E            [12] 2229 	mov	a,_bp
      0008E5 24 F2            [12] 2230 	add	a,#0xf2
      0008E7 F8               [12] 2231 	mov	r0,a
      0008E8 E6               [12] 2232 	mov	a,@r0
      0008E9 C0 E0            [24] 2233 	push	acc
      0008EB 08               [12] 2234 	inc	r0
      0008EC E6               [12] 2235 	mov	a,@r0
      0008ED C0 E0            [24] 2236 	push	acc
      0008EF 08               [12] 2237 	inc	r0
      0008F0 E6               [12] 2238 	mov	a,@r0
      0008F1 C0 E0            [24] 2239 	push	acc
      0008F3 08               [12] 2240 	inc	r0
      0008F4 E6               [12] 2241 	mov	a,@r0
      0008F5 C0 E0            [24] 2242 	push	acc
      0008F7 90 00 00         [24] 2243 	mov	dptr,#0x0000
      0008FA E4               [12] 2244 	clr	a
      0008FB F5 F0            [12] 2245 	mov	b,a
      0008FD 12 11 6B         [24] 2246 	lcall	___fslt
      000900 E5 81            [12] 2247 	mov	a,sp
      000902 24 FC            [12] 2248 	add	a,#0xfc
      000904 F5 81            [12] 2249 	mov	sp,a
      000906 E5 82            [12] 2250 	mov	a, dpl
      000908 24 FF            [12] 2251 	add	a,#0xff
      00090A 92 00            [24] 2252 	mov	b0,c
      00090C 40 09            [24] 2253 	jc	00102$
      00090E                       2254 00101$:
                           000857  2255 	C$fuzzy.h$1384$2_0$77 ==.
                                   2256 ;	/home/mahavigna/CI/fuzzy.h:1384: return 0.0f;
      00090E 90 00 00         [24] 2257 	mov	dptr,#0x0000
      000911 E4               [12] 2258 	clr	a
      000912 F5 F0            [12] 2259 	mov	b,a
      000914 02 0C 86         [24] 2260 	ljmp	00116$
      000917                       2261 00102$:
                           000860  2262 	C$fuzzy.h$1387$1_0$76 ==.
                                   2263 ;	/home/mahavigna/CI/fuzzy.h:1387: weighted_sum = 0.0f;
      000917 E5 0E            [12] 2264 	mov	a,_bp
      000919 24 0E            [12] 2265 	add	a,#0x0e
      00091B F8               [12] 2266 	mov	r0,a
      00091C E4               [12] 2267 	clr	a
      00091D F6               [12] 2268 	mov	@r0,a
      00091E 08               [12] 2269 	inc	r0
      00091F F6               [12] 2270 	mov	@r0,a
      000920 08               [12] 2271 	inc	r0
      000921 F6               [12] 2272 	mov	@r0,a
      000922 08               [12] 2273 	inc	r0
      000923 F6               [12] 2274 	mov	@r0,a
                           00086D  2275 	C$fuzzy.h$1388$1_0$76 ==.
                                   2276 ;	/home/mahavigna/CI/fuzzy.h:1388: height_sum = 0.0f;
      000924 E5 0E            [12] 2277 	mov	a,_bp
      000926 24 12            [12] 2278 	add	a,#0x12
      000928 F8               [12] 2279 	mov	r0,a
      000929 E4               [12] 2280 	clr	a
      00092A F6               [12] 2281 	mov	@r0,a
      00092B 08               [12] 2282 	inc	r0
      00092C F6               [12] 2283 	mov	@r0,a
      00092D 08               [12] 2284 	inc	r0
      00092E F6               [12] 2285 	mov	@r0,a
      00092F 08               [12] 2286 	inc	r0
      000930 F6               [12] 2287 	mov	@r0,a
                           00087A  2288 	C$fuzzy.h$1391$2_0$78 ==.
                                   2289 ;	/home/mahavigna/CI/fuzzy.h:1391: value = lower;
      000931 E5 0E            [12] 2290 	mov	a,_bp
      000933 24 FA            [12] 2291 	add	a,#0xfa
      000935 F8               [12] 2292 	mov	r0,a
      000936 E5 0E            [12] 2293 	mov	a,_bp
      000938 24 16            [12] 2294 	add	a,#0x16
      00093A F9               [12] 2295 	mov	r1,a
      00093B E6               [12] 2296 	mov	a,@r0
      00093C F7               [12] 2297 	mov	@r1,a
      00093D 08               [12] 2298 	inc	r0
      00093E E6               [12] 2299 	mov	a,@r0
      00093F 09               [12] 2300 	inc	r1
      000940 F7               [12] 2301 	mov	@r1,a
      000941 08               [12] 2302 	inc	r0
      000942 E6               [12] 2303 	mov	a,@r0
      000943 09               [12] 2304 	inc	r1
      000944 F7               [12] 2305 	mov	@r1,a
      000945 08               [12] 2306 	inc	r0
      000946 E6               [12] 2307 	mov	a,@r0
      000947 09               [12] 2308 	inc	r1
      000948 F7               [12] 2309 	mov	@r1,a
      000949 A8 0E            [24] 2310 	mov	r0,_bp
      00094B 08               [12] 2311 	inc	r0
      00094C E5 0E            [12] 2312 	mov	a,_bp
      00094E 24 07            [12] 2313 	add	a,#0x07
      000950 F9               [12] 2314 	mov	r1,a
      000951 E6               [12] 2315 	mov	a,@r0
      000952 F7               [12] 2316 	mov	@r1,a
      000953 08               [12] 2317 	inc	r0
      000954 E6               [12] 2318 	mov	a,@r0
      000955 09               [12] 2319 	inc	r1
      000956 F7               [12] 2320 	mov	@r1,a
      000957 08               [12] 2321 	inc	r0
      000958 E6               [12] 2322 	mov	a,@r0
      000959 09               [12] 2323 	inc	r1
      00095A F7               [12] 2324 	mov	@r1,a
      00095B                       2325 00114$:
                           0008A4  2326 	C$fuzzy.h$1392$1_0$76 ==.
                                   2327 ;	/home/mahavigna/CI/fuzzy.h:1392: value <= upper;
      00095B E5 0E            [12] 2328 	mov	a,_bp
      00095D 24 16            [12] 2329 	add	a,#0x16
      00095F F8               [12] 2330 	mov	r0,a
      000960 E6               [12] 2331 	mov	a,@r0
      000961 C0 E0            [24] 2332 	push	acc
      000963 08               [12] 2333 	inc	r0
      000964 E6               [12] 2334 	mov	a,@r0
      000965 C0 E0            [24] 2335 	push	acc
      000967 08               [12] 2336 	inc	r0
      000968 E6               [12] 2337 	mov	a,@r0
      000969 C0 E0            [24] 2338 	push	acc
      00096B 08               [12] 2339 	inc	r0
      00096C E6               [12] 2340 	mov	a,@r0
      00096D C0 E0            [24] 2341 	push	acc
      00096F E5 0E            [12] 2342 	mov	a,_bp
      000971 24 F6            [12] 2343 	add	a,#0xf6
      000973 F8               [12] 2344 	mov	r0,a
      000974 86 82            [24] 2345 	mov	dpl, @r0
      000976 08               [12] 2346 	inc	r0
      000977 86 83            [24] 2347 	mov	dph, @r0
      000979 08               [12] 2348 	inc	r0
      00097A 86 F0            [24] 2349 	mov	b, @r0
      00097C 08               [12] 2350 	inc	r0
      00097D E6               [12] 2351 	mov	a, @r0
      00097E 12 11 6B         [24] 2352 	lcall	___fslt
      000981 E5 81            [12] 2353 	mov	a,sp
      000983 24 FC            [12] 2354 	add	a,#0xfc
      000985 F5 81            [12] 2355 	mov	sp,a
      000987 E5 82            [12] 2356 	mov	a, dpl
      000989 24 FF            [12] 2357 	add	a,#0xff
      00098B 92 00            [24] 2358 	mov	b0,c
      00098D 50 03            [24] 2359 	jnc	00187$
      00098F 02 0C 2D         [24] 2360 	ljmp	00107$
      000992                       2361 00187$:
                           0008DB  2362 	C$fuzzy.h$1396$3_0$79 ==.
                                   2363 ;	/home/mahavigna/CI/fuzzy.h:1396: LEVEL_LO;
      000992 E5 0E            [12] 2364 	mov	a,_bp
      000994 24 1A            [12] 2365 	add	a,#0x1a
      000996 F8               [12] 2366 	mov	r0,a
      000997 E4               [12] 2367 	clr	a
      000998 F6               [12] 2368 	mov	@r0,a
      000999 08               [12] 2369 	inc	r0
      00099A F6               [12] 2370 	mov	@r0,a
      00099B 08               [12] 2371 	inc	r0
      00099C F6               [12] 2372 	mov	@r0,a
      00099D 08               [12] 2373 	inc	r0
      00099E F6               [12] 2374 	mov	@r0,a
                           0008E8  2375 	C$fuzzy.h$1399$1_0$76 ==.
                                   2376 ;	/home/mahavigna/CI/fuzzy.h:1399: i = 0;
      00099F E5 0E            [12] 2377 	mov	a,_bp
      0009A1 24 26            [12] 2378 	add	a,#0x26
      0009A3 F8               [12] 2379 	mov	r0,a
      0009A4 E4               [12] 2380 	clr	a
      0009A5 F6               [12] 2381 	mov	@r0,a
      0009A6 08               [12] 2382 	inc	r0
      0009A7 F6               [12] 2383 	mov	@r0,a
      0009A8 FA               [12] 2384 	mov	r2,a
      0009A9 FB               [12] 2385 	mov	r3,a
      0009AA                       2386 00111$:
                           0008F3  2387 	C$fuzzy.h$1400$1_0$76 ==.
                                   2388 ;	/home/mahavigna/CI/fuzzy.h:1400: i < rules->count;
      0009AA C0 02            [24] 2389 	push	ar2
      0009AC C0 03            [24] 2390 	push	ar3
      0009AE E5 0E            [12] 2391 	mov	a,_bp
      0009B0 24 04            [12] 2392 	add	a,#0x04
      0009B2 F8               [12] 2393 	mov	r0,a
      0009B3 86 82            [24] 2394 	mov	dpl,@r0
      0009B5 08               [12] 2395 	inc	r0
      0009B6 86 83            [24] 2396 	mov	dph,@r0
      0009B8 08               [12] 2397 	inc	r0
      0009B9 86 F0            [24] 2398 	mov	b,@r0
      0009BB 12 13 8B         [24] 2399 	lcall	__gptrget
      0009BE FA               [12] 2400 	mov	r2,a
      0009BF A3               [24] 2401 	inc	dptr
      0009C0 12 13 8B         [24] 2402 	lcall	__gptrget
      0009C3 FB               [12] 2403 	mov	r3,a
      0009C4 E5 0E            [12] 2404 	mov	a,_bp
      0009C6 24 26            [12] 2405 	add	a,#0x26
      0009C8 F8               [12] 2406 	mov	r0,a
      0009C9 C3               [12] 2407 	clr	c
      0009CA E6               [12] 2408 	mov	a,@r0
      0009CB 9A               [12] 2409 	subb	a,r2
      0009CC 08               [12] 2410 	inc	r0
      0009CD E6               [12] 2411 	mov	a,@r0
      0009CE 9B               [12] 2412 	subb	a,r3
      0009CF D0 03            [24] 2413 	pop	ar3
      0009D1 D0 02            [24] 2414 	pop	ar2
      0009D3 40 03            [24] 2415 	jc	00188$
      0009D5 02 0B 4F         [24] 2416 	ljmp	00106$
      0009D8                       2417 00188$:
                           000921  2418 	C$fuzzy.h$1404$1_0$76 ==.
                                   2419 ;	/home/mahavigna/CI/fuzzy.h:1404: rules->rules[i]
      0009D8 E5 0E            [12] 2420 	mov	a,_bp
      0009DA 24 07            [12] 2421 	add	a,#0x07
      0009DC F8               [12] 2422 	mov	r0,a
      0009DD EA               [12] 2423 	mov	a,r2
      0009DE 26               [12] 2424 	add	a, @r0
      0009DF FD               [12] 2425 	mov	r5,a
      0009E0 EB               [12] 2426 	mov	a,r3
      0009E1 08               [12] 2427 	inc	r0
      0009E2 36               [12] 2428 	addc	a, @r0
      0009E3 FE               [12] 2429 	mov	r6,a
      0009E4 08               [12] 2430 	inc	r0
      0009E5 86 07            [24] 2431 	mov	ar7,@r0
      0009E7 74 04            [12] 2432 	mov	a,#0x04
      0009E9 2D               [12] 2433 	add	a, r5
      0009EA FD               [12] 2434 	mov	r5,a
      0009EB E4               [12] 2435 	clr	a
      0009EC 3E               [12] 2436 	addc	a, r6
      0009ED FE               [12] 2437 	mov	r6,a
      0009EE 8D 82            [24] 2438 	mov	dpl,r5
      0009F0 8E 83            [24] 2439 	mov	dph,r6
      0009F2 8F F0            [24] 2440 	mov	b,r7
      0009F4 12 13 8B         [24] 2441 	lcall	__gptrget
      0009F7 FD               [12] 2442 	mov	r5,a
      0009F8 A3               [24] 2443 	inc	dptr
      0009F9 12 13 8B         [24] 2444 	lcall	__gptrget
      0009FC FE               [12] 2445 	mov	r6,a
                           000946  2446 	C$fuzzy.h$1405$5_0$81 ==.
                                   2447 ;	/home/mahavigna/CI/fuzzy.h:1405: .output_function(value);
      0009FD C0 06            [24] 2448 	push	ar6
      0009FF C0 05            [24] 2449 	push	ar5
      000A01 C0 03            [24] 2450 	push	ar3
      000A03 C0 02            [24] 2451 	push	ar2
      000A05 12 0A 0A         [24] 2452 	lcall	00189$
      000A08 80 14            [24] 2453 	sjmp	00190$
      000A0A                       2454 00189$:
      000A0A C0 05            [24] 2455 	push	ar5
      000A0C C0 06            [24] 2456 	push	ar6
      000A0E E5 0E            [12] 2457 	mov	a,_bp
      000A10 24 16            [12] 2458 	add	a,#0x16
      000A12 F8               [12] 2459 	mov	r0,a
      000A13 86 82            [24] 2460 	mov	dpl, @r0
      000A15 08               [12] 2461 	inc	r0
      000A16 86 83            [24] 2462 	mov	dph, @r0
      000A18 08               [12] 2463 	inc	r0
      000A19 86 F0            [24] 2464 	mov	b, @r0
      000A1B 08               [12] 2465 	inc	r0
      000A1C E6               [12] 2466 	mov	a, @r0
      000A1D 22               [24] 2467 	ret
      000A1E                       2468 00190$:
      000A1E C8               [12] 2469 	xch	a,r0
      000A1F E5 0E            [12] 2470 	mov	a,_bp
      000A21 24 1E            [12] 2471 	add	a,#0x1e
      000A23 C8               [12] 2472 	xch	a,r0
      000A24 A6 82            [24] 2473 	mov	@r0, dpl
      000A26 08               [12] 2474 	inc	r0
      000A27 A6 83            [24] 2475 	mov	@r0, dph
      000A29 08               [12] 2476 	inc	r0
      000A2A A6 F0            [24] 2477 	mov	@r0, b
      000A2C 08               [12] 2478 	inc	r0
      000A2D F6               [12] 2479 	mov	@r0,a
      000A2E D0 02            [24] 2480 	pop	ar2
      000A30 D0 03            [24] 2481 	pop	ar3
      000A32 D0 05            [24] 2482 	pop	ar5
      000A34 D0 06            [24] 2483 	pop	ar6
                           00097F  2484 	C$fuzzy.h$1408$5_0$81 ==.
                                   2485 ;	/home/mahavigna/CI/fuzzy.h:1408: rules->rules[i].value <
      000A36 A8 0E            [24] 2486 	mov	r0,_bp
      000A38 08               [12] 2487 	inc	r0
      000A39 EA               [12] 2488 	mov	a,r2
      000A3A 26               [12] 2489 	add	a, @r0
      000A3B FD               [12] 2490 	mov	r5,a
      000A3C EB               [12] 2491 	mov	a,r3
      000A3D 08               [12] 2492 	inc	r0
      000A3E 36               [12] 2493 	addc	a, @r0
      000A3F FE               [12] 2494 	mov	r6,a
      000A40 08               [12] 2495 	inc	r0
      000A41 86 07            [24] 2496 	mov	ar7,@r0
      000A43 8D 82            [24] 2497 	mov	dpl,r5
      000A45 8E 83            [24] 2498 	mov	dph,r6
      000A47 8F F0            [24] 2499 	mov	b,r7
      000A49 E5 0E            [12] 2500 	mov	a,_bp
      000A4B 24 0A            [12] 2501 	add	a,#0x0a
      000A4D F8               [12] 2502 	mov	r0,a
      000A4E 12 13 8B         [24] 2503 	lcall	__gptrget
      000A51 F6               [12] 2504 	mov	@r0,a
      000A52 A3               [24] 2505 	inc	dptr
      000A53 12 13 8B         [24] 2506 	lcall	__gptrget
      000A56 08               [12] 2507 	inc	r0
      000A57 F6               [12] 2508 	mov	@r0,a
      000A58 A3               [24] 2509 	inc	dptr
      000A59 12 13 8B         [24] 2510 	lcall	__gptrget
      000A5C 08               [12] 2511 	inc	r0
      000A5D F6               [12] 2512 	mov	@r0,a
      000A5E A3               [24] 2513 	inc	dptr
      000A5F 12 13 8B         [24] 2514 	lcall	__gptrget
      000A62 08               [12] 2515 	inc	r0
      000A63 F6               [12] 2516 	mov	@r0,a
      000A64 C0 03            [24] 2517 	push	ar3
      000A66 C0 02            [24] 2518 	push	ar2
      000A68 E5 0E            [12] 2519 	mov	a,_bp
      000A6A 24 1E            [12] 2520 	add	a,#0x1e
      000A6C F8               [12] 2521 	mov	r0,a
      000A6D E6               [12] 2522 	mov	a,@r0
      000A6E C0 E0            [24] 2523 	push	acc
      000A70 08               [12] 2524 	inc	r0
      000A71 E6               [12] 2525 	mov	a,@r0
      000A72 C0 E0            [24] 2526 	push	acc
      000A74 08               [12] 2527 	inc	r0
      000A75 E6               [12] 2528 	mov	a,@r0
      000A76 C0 E0            [24] 2529 	push	acc
      000A78 08               [12] 2530 	inc	r0
      000A79 E6               [12] 2531 	mov	a,@r0
      000A7A C0 E0            [24] 2532 	push	acc
      000A7C E5 0E            [12] 2533 	mov	a,_bp
      000A7E 24 0A            [12] 2534 	add	a,#0x0a
      000A80 F8               [12] 2535 	mov	r0,a
      000A81 86 82            [24] 2536 	mov	dpl, @r0
      000A83 08               [12] 2537 	inc	r0
      000A84 86 83            [24] 2538 	mov	dph, @r0
      000A86 08               [12] 2539 	inc	r0
      000A87 86 F0            [24] 2540 	mov	b, @r0
      000A89 08               [12] 2541 	inc	r0
      000A8A E6               [12] 2542 	mov	a, @r0
      000A8B 12 11 6B         [24] 2543 	lcall	___fslt
      000A8E AF 82            [24] 2544 	mov	r7, dpl
      000A90 E5 81            [12] 2545 	mov	a,sp
      000A92 24 FC            [12] 2546 	add	a,#0xfc
      000A94 F5 81            [12] 2547 	mov	sp,a
      000A96 D0 02            [24] 2548 	pop	ar2
      000A98 D0 03            [24] 2549 	pop	ar3
      000A9A EF               [12] 2550 	mov	a,r7
      000A9B 60 12            [24] 2551 	jz	00118$
                           0009E6  2552 	C$fuzzy.h$1410$5_0$81 ==.
                                   2553 ;	/home/mahavigna/CI/fuzzy.h:1410: ? rules->rules[i].value
      000A9D E5 0E            [12] 2554 	mov	a,_bp
      000A9F 24 0A            [12] 2555 	add	a,#0x0a
      000AA1 F8               [12] 2556 	mov	r0,a
      000AA2 86 07            [24] 2557 	mov	ar7,@r0
      000AA4 08               [12] 2558 	inc	r0
      000AA5 86 06            [24] 2559 	mov	ar6,@r0
      000AA7 08               [12] 2560 	inc	r0
      000AA8 86 05            [24] 2561 	mov	ar5,@r0
      000AAA 08               [12] 2562 	inc	r0
      000AAB 86 04            [24] 2563 	mov	ar4,@r0
      000AAD 80 10            [24] 2564 	sjmp	00119$
      000AAF                       2565 00118$:
                           0009F8  2566 	C$fuzzy.h$1411$5_0$81 ==.
                                   2567 ;	/home/mahavigna/CI/fuzzy.h:1411: : output_membership;
      000AAF E5 0E            [12] 2568 	mov	a,_bp
      000AB1 24 1E            [12] 2569 	add	a,#0x1e
      000AB3 F8               [12] 2570 	mov	r0,a
      000AB4 86 07            [24] 2571 	mov	ar7,@r0
      000AB6 08               [12] 2572 	inc	r0
      000AB7 86 06            [24] 2573 	mov	ar6,@r0
      000AB9 08               [12] 2574 	inc	r0
      000ABA 86 05            [24] 2575 	mov	ar5,@r0
      000ABC 08               [12] 2576 	inc	r0
      000ABD 86 04            [24] 2577 	mov	ar4,@r0
      000ABF                       2578 00119$:
      000ABF E5 0E            [12] 2579 	mov	a,_bp
      000AC1 24 22            [12] 2580 	add	a,#0x22
      000AC3 F8               [12] 2581 	mov	r0,a
      000AC4 A6 07            [24] 2582 	mov	@r0,ar7
      000AC6 08               [12] 2583 	inc	r0
      000AC7 A6 06            [24] 2584 	mov	@r0,ar6
      000AC9 08               [12] 2585 	inc	r0
      000ACA A6 05            [24] 2586 	mov	@r0,ar5
      000ACC 08               [12] 2587 	inc	r0
      000ACD A6 04            [24] 2588 	mov	@r0,ar4
                           000A18  2589 	C$fuzzy.h$1416$1_0$76 ==.
                                   2590 ;	/home/mahavigna/CI/fuzzy.h:1416: ? aggregated_height
      000ACF C0 03            [24] 2591 	push	ar3
      000AD1 C0 02            [24] 2592 	push	ar2
      000AD3 E5 0E            [12] 2593 	mov	a,_bp
      000AD5 24 1A            [12] 2594 	add	a,#0x1a
      000AD7 F8               [12] 2595 	mov	r0,a
      000AD8 E6               [12] 2596 	mov	a,@r0
      000AD9 C0 E0            [24] 2597 	push	acc
      000ADB 08               [12] 2598 	inc	r0
      000ADC E6               [12] 2599 	mov	a,@r0
      000ADD C0 E0            [24] 2600 	push	acc
      000ADF 08               [12] 2601 	inc	r0
      000AE0 E6               [12] 2602 	mov	a,@r0
      000AE1 C0 E0            [24] 2603 	push	acc
      000AE3 08               [12] 2604 	inc	r0
      000AE4 E6               [12] 2605 	mov	a,@r0
      000AE5 C0 E0            [24] 2606 	push	acc
      000AE7 E5 0E            [12] 2607 	mov	a,_bp
      000AE9 24 22            [12] 2608 	add	a,#0x22
      000AEB F8               [12] 2609 	mov	r0,a
      000AEC 86 82            [24] 2610 	mov	dpl, @r0
      000AEE 08               [12] 2611 	inc	r0
      000AEF 86 83            [24] 2612 	mov	dph, @r0
      000AF1 08               [12] 2613 	inc	r0
      000AF2 86 F0            [24] 2614 	mov	b, @r0
      000AF4 08               [12] 2615 	inc	r0
      000AF5 E6               [12] 2616 	mov	a, @r0
      000AF6 12 11 6B         [24] 2617 	lcall	___fslt
      000AF9 AF 82            [24] 2618 	mov	r7, dpl
      000AFB E5 81            [12] 2619 	mov	a,sp
      000AFD 24 FC            [12] 2620 	add	a,#0xfc
      000AFF F5 81            [12] 2621 	mov	sp,a
      000B01 D0 02            [24] 2622 	pop	ar2
      000B03 D0 03            [24] 2623 	pop	ar3
      000B05 EF               [12] 2624 	mov	a,r7
      000B06 60 12            [24] 2625 	jz	00120$
      000B08 E5 0E            [12] 2626 	mov	a,_bp
      000B0A 24 1A            [12] 2627 	add	a,#0x1a
      000B0C F8               [12] 2628 	mov	r0,a
      000B0D 86 04            [24] 2629 	mov	ar4,@r0
      000B0F 08               [12] 2630 	inc	r0
      000B10 86 05            [24] 2631 	mov	ar5,@r0
      000B12 08               [12] 2632 	inc	r0
      000B13 86 06            [24] 2633 	mov	ar6,@r0
      000B15 08               [12] 2634 	inc	r0
      000B16 86 07            [24] 2635 	mov	ar7,@r0
      000B18 80 10            [24] 2636 	sjmp	00121$
      000B1A                       2637 00120$:
                           000A63  2638 	C$fuzzy.h$1417$5_0$81 ==.
                                   2639 ;	/home/mahavigna/CI/fuzzy.h:1417: : clipped_height;
      000B1A E5 0E            [12] 2640 	mov	a,_bp
      000B1C 24 22            [12] 2641 	add	a,#0x22
      000B1E F8               [12] 2642 	mov	r0,a
      000B1F 86 04            [24] 2643 	mov	ar4,@r0
      000B21 08               [12] 2644 	inc	r0
      000B22 86 05            [24] 2645 	mov	ar5,@r0
      000B24 08               [12] 2646 	inc	r0
      000B25 86 06            [24] 2647 	mov	ar6,@r0
      000B27 08               [12] 2648 	inc	r0
      000B28 86 07            [24] 2649 	mov	ar7,@r0
      000B2A                       2650 00121$:
      000B2A E5 0E            [12] 2651 	mov	a,_bp
      000B2C 24 1A            [12] 2652 	add	a,#0x1a
      000B2E F8               [12] 2653 	mov	r0,a
      000B2F A6 04            [24] 2654 	mov	@r0,ar4
      000B31 08               [12] 2655 	inc	r0
      000B32 A6 05            [24] 2656 	mov	@r0,ar5
      000B34 08               [12] 2657 	inc	r0
      000B35 A6 06            [24] 2658 	mov	@r0,ar6
      000B37 08               [12] 2659 	inc	r0
      000B38 A6 07            [24] 2660 	mov	@r0,ar7
                           000A83  2661 	C$fuzzy.h$1401$1_0$76 ==.
                                   2662 ;	/home/mahavigna/CI/fuzzy.h:1401: i++
      000B3A 74 06            [12] 2663 	mov	a,#0x06
      000B3C 2A               [12] 2664 	add	a, r2
      000B3D FA               [12] 2665 	mov	r2,a
      000B3E E4               [12] 2666 	clr	a
      000B3F 3B               [12] 2667 	addc	a, r3
      000B40 FB               [12] 2668 	mov	r3,a
      000B41 E5 0E            [12] 2669 	mov	a,_bp
      000B43 24 26            [12] 2670 	add	a,#0x26
      000B45 F8               [12] 2671 	mov	r0,a
      000B46 06               [12] 2672 	inc	@r0
      000B47 B6 00 02         [24] 2673 	cjne	@r0,#0x00,00193$
      000B4A 08               [12] 2674 	inc	r0
      000B4B 06               [12] 2675 	inc	@r0
      000B4C                       2676 00193$:
      000B4C 02 09 AA         [24] 2677 	ljmp	00111$
      000B4F                       2678 00106$:
                           000A98  2679 	C$fuzzy.h$1422$1_0$76 ==.
                                   2680 ;	/home/mahavigna/CI/fuzzy.h:1422: aggregated_height;
      000B4F E5 0E            [12] 2681 	mov	a,_bp
      000B51 24 1A            [12] 2682 	add	a,#0x1a
      000B53 F8               [12] 2683 	mov	r0,a
      000B54 E6               [12] 2684 	mov	a,@r0
      000B55 C0 E0            [24] 2685 	push	acc
      000B57 08               [12] 2686 	inc	r0
      000B58 E6               [12] 2687 	mov	a,@r0
      000B59 C0 E0            [24] 2688 	push	acc
      000B5B 08               [12] 2689 	inc	r0
      000B5C E6               [12] 2690 	mov	a,@r0
      000B5D C0 E0            [24] 2691 	push	acc
      000B5F 08               [12] 2692 	inc	r0
      000B60 E6               [12] 2693 	mov	a,@r0
      000B61 C0 E0            [24] 2694 	push	acc
      000B63 E5 0E            [12] 2695 	mov	a,_bp
      000B65 24 16            [12] 2696 	add	a,#0x16
      000B67 F8               [12] 2697 	mov	r0,a
      000B68 86 82            [24] 2698 	mov	dpl, @r0
      000B6A 08               [12] 2699 	inc	r0
      000B6B 86 83            [24] 2700 	mov	dph, @r0
      000B6D 08               [12] 2701 	inc	r0
      000B6E 86 F0            [24] 2702 	mov	b, @r0
      000B70 08               [12] 2703 	inc	r0
      000B71 E6               [12] 2704 	mov	a, @r0
      000B72 12 10 4C         [24] 2705 	lcall	___fsmul
      000B75 AC 82            [24] 2706 	mov	r4, dpl
      000B77 AD 83            [24] 2707 	mov	r5, dph
      000B79 AE F0            [24] 2708 	mov	r6, b
      000B7B FF               [12] 2709 	mov	r7, a
      000B7C E5 81            [12] 2710 	mov	a,sp
      000B7E 24 FC            [12] 2711 	add	a,#0xfc
      000B80 F5 81            [12] 2712 	mov	sp,a
      000B82 C0 04            [24] 2713 	push	ar4
      000B84 C0 05            [24] 2714 	push	ar5
      000B86 C0 06            [24] 2715 	push	ar6
      000B88 C0 07            [24] 2716 	push	ar7
                           000AD3  2717 	C$fuzzy.h$1425$1_0$76 ==.
                                   2718 ;	/home/mahavigna/CI/fuzzy.h:1425: aggregated_height;
      000B8A E5 0E            [12] 2719 	mov	a,_bp
      000B8C 24 0E            [12] 2720 	add	a,#0x0e
      000B8E F8               [12] 2721 	mov	r0,a
      000B8F 86 82            [24] 2722 	mov	dpl, @r0
      000B91 08               [12] 2723 	inc	r0
      000B92 86 83            [24] 2724 	mov	dph, @r0
      000B94 08               [12] 2725 	inc	r0
      000B95 86 F0            [24] 2726 	mov	b, @r0
      000B97 08               [12] 2727 	inc	r0
      000B98 E6               [12] 2728 	mov	a, @r0
      000B99 12 11 BD         [24] 2729 	lcall	___fsadd
      000B9C C8               [12] 2730 	xch	a,r0
      000B9D E5 0E            [12] 2731 	mov	a,_bp
      000B9F 24 0E            [12] 2732 	add	a,#0x0e
      000BA1 C8               [12] 2733 	xch	a,r0
      000BA2 A6 82            [24] 2734 	mov	@r0, dpl
      000BA4 08               [12] 2735 	inc	r0
      000BA5 A6 83            [24] 2736 	mov	@r0, dph
      000BA7 08               [12] 2737 	inc	r0
      000BA8 A6 F0            [24] 2738 	mov	@r0, b
      000BAA 08               [12] 2739 	inc	r0
      000BAB F6               [12] 2740 	mov	@r0,a
      000BAC E5 81            [12] 2741 	mov	a,sp
      000BAE 24 FC            [12] 2742 	add	a,#0xfc
      000BB0 F5 81            [12] 2743 	mov	sp,a
      000BB2 E5 0E            [12] 2744 	mov	a,_bp
      000BB4 24 1A            [12] 2745 	add	a,#0x1a
      000BB6 F8               [12] 2746 	mov	r0,a
      000BB7 E6               [12] 2747 	mov	a,@r0
      000BB8 C0 E0            [24] 2748 	push	acc
      000BBA 08               [12] 2749 	inc	r0
      000BBB E6               [12] 2750 	mov	a,@r0
      000BBC C0 E0            [24] 2751 	push	acc
      000BBE 08               [12] 2752 	inc	r0
      000BBF E6               [12] 2753 	mov	a,@r0
      000BC0 C0 E0            [24] 2754 	push	acc
      000BC2 08               [12] 2755 	inc	r0
      000BC3 E6               [12] 2756 	mov	a,@r0
      000BC4 C0 E0            [24] 2757 	push	acc
                           000B0F  2758 	C$fuzzy.h$1394$1_0$76 ==.
                                   2759 ;	/home/mahavigna/CI/fuzzy.h:1394: ) {
      000BC6 E5 0E            [12] 2760 	mov	a,_bp
      000BC8 24 12            [12] 2761 	add	a,#0x12
      000BCA F8               [12] 2762 	mov	r0,a
      000BCB 86 82            [24] 2763 	mov	dpl, @r0
      000BCD 08               [12] 2764 	inc	r0
      000BCE 86 83            [24] 2765 	mov	dph, @r0
      000BD0 08               [12] 2766 	inc	r0
      000BD1 86 F0            [24] 2767 	mov	b, @r0
      000BD3 08               [12] 2768 	inc	r0
      000BD4 E6               [12] 2769 	mov	a, @r0
      000BD5 12 11 BD         [24] 2770 	lcall	___fsadd
      000BD8 C8               [12] 2771 	xch	a,r0
      000BD9 E5 0E            [12] 2772 	mov	a,_bp
      000BDB 24 12            [12] 2773 	add	a,#0x12
      000BDD C8               [12] 2774 	xch	a,r0
      000BDE A6 82            [24] 2775 	mov	@r0, dpl
      000BE0 08               [12] 2776 	inc	r0
      000BE1 A6 83            [24] 2777 	mov	@r0, dph
      000BE3 08               [12] 2778 	inc	r0
      000BE4 A6 F0            [24] 2779 	mov	@r0, b
      000BE6 08               [12] 2780 	inc	r0
      000BE7 F6               [12] 2781 	mov	@r0,a
      000BE8 E5 81            [12] 2782 	mov	a,sp
      000BEA 24 FC            [12] 2783 	add	a,#0xfc
      000BEC F5 81            [12] 2784 	mov	sp,a
      000BEE E5 0E            [12] 2785 	mov	a,_bp
      000BF0 24 F2            [12] 2786 	add	a,#0xf2
      000BF2 F8               [12] 2787 	mov	r0,a
      000BF3 E6               [12] 2788 	mov	a,@r0
      000BF4 C0 E0            [24] 2789 	push	acc
      000BF6 08               [12] 2790 	inc	r0
      000BF7 E6               [12] 2791 	mov	a,@r0
      000BF8 C0 E0            [24] 2792 	push	acc
      000BFA 08               [12] 2793 	inc	r0
      000BFB E6               [12] 2794 	mov	a,@r0
      000BFC C0 E0            [24] 2795 	push	acc
      000BFE 08               [12] 2796 	inc	r0
      000BFF E6               [12] 2797 	mov	a,@r0
      000C00 C0 E0            [24] 2798 	push	acc
      000C02 E5 0E            [12] 2799 	mov	a,_bp
      000C04 24 16            [12] 2800 	add	a,#0x16
      000C06 F8               [12] 2801 	mov	r0,a
      000C07 86 82            [24] 2802 	mov	dpl, @r0
      000C09 08               [12] 2803 	inc	r0
      000C0A 86 83            [24] 2804 	mov	dph, @r0
      000C0C 08               [12] 2805 	inc	r0
      000C0D 86 F0            [24] 2806 	mov	b, @r0
      000C0F 08               [12] 2807 	inc	r0
      000C10 E6               [12] 2808 	mov	a, @r0
      000C11 12 11 BD         [24] 2809 	lcall	___fsadd
      000C14 C8               [12] 2810 	xch	a,r0
      000C15 E5 0E            [12] 2811 	mov	a,_bp
      000C17 24 16            [12] 2812 	add	a,#0x16
      000C19 C8               [12] 2813 	xch	a,r0
      000C1A A6 82            [24] 2814 	mov	@r0, dpl
      000C1C 08               [12] 2815 	inc	r0
      000C1D A6 83            [24] 2816 	mov	@r0, dph
      000C1F 08               [12] 2817 	inc	r0
      000C20 A6 F0            [24] 2818 	mov	@r0, b
      000C22 08               [12] 2819 	inc	r0
      000C23 F6               [12] 2820 	mov	@r0,a
      000C24 E5 81            [12] 2821 	mov	a,sp
      000C26 24 FC            [12] 2822 	add	a,#0xfc
      000C28 F5 81            [12] 2823 	mov	sp,a
      000C2A 02 09 5B         [24] 2824 	ljmp	00114$
      000C2D                       2825 00107$:
                           000B76  2826 	C$fuzzy.h$1428$1_0$76 ==.
                                   2827 ;	/home/mahavigna/CI/fuzzy.h:1428: if (height_sum == 0.0f) {
      000C2D E5 0E            [12] 2828 	mov	a,_bp
      000C2F 24 12            [12] 2829 	add	a,#0x12
      000C31 F8               [12] 2830 	mov	r0,a
      000C32 86 F0            [24] 2831 	mov	b,@r0
      000C34 08               [12] 2832 	inc	r0
      000C35 E6               [12] 2833 	mov	a,@r0
      000C36 42 F0            [12] 2834 	orl	b,a
      000C38 08               [12] 2835 	inc	r0
      000C39 E6               [12] 2836 	mov	a,@r0
      000C3A 42 F0            [12] 2837 	orl	b,a
      000C3C 08               [12] 2838 	inc	r0
      000C3D E6               [12] 2839 	mov	a,@r0
      000C3E 54 7F            [12] 2840 	anl	a,#0x7F
      000C40 45 F0            [12] 2841 	orl	a,b
      000C42 70 08            [24] 2842 	jnz	00109$
                           000B8D  2843 	C$fuzzy.h$1429$2_0$82 ==.
                                   2844 ;	/home/mahavigna/CI/fuzzy.h:1429: return 0.0f;
      000C44 90 00 00         [24] 2845 	mov	dptr,#0x0000
      000C47 E4               [12] 2846 	clr	a
      000C48 F5 F0            [12] 2847 	mov	b,a
      000C4A 80 3A            [24] 2848 	sjmp	00116$
      000C4C                       2849 00109$:
                           000B95  2850 	C$fuzzy.h$1433$1_0$76 ==.
                                   2851 ;	/home/mahavigna/CI/fuzzy.h:1433: height_sum;
      000C4C E5 0E            [12] 2852 	mov	a,_bp
      000C4E 24 12            [12] 2853 	add	a,#0x12
      000C50 F8               [12] 2854 	mov	r0,a
      000C51 E6               [12] 2855 	mov	a,@r0
      000C52 C0 E0            [24] 2856 	push	acc
      000C54 08               [12] 2857 	inc	r0
      000C55 E6               [12] 2858 	mov	a,@r0
      000C56 C0 E0            [24] 2859 	push	acc
      000C58 08               [12] 2860 	inc	r0
      000C59 E6               [12] 2861 	mov	a,@r0
      000C5A C0 E0            [24] 2862 	push	acc
      000C5C 08               [12] 2863 	inc	r0
      000C5D E6               [12] 2864 	mov	a,@r0
      000C5E C0 E0            [24] 2865 	push	acc
      000C60 E5 0E            [12] 2866 	mov	a,_bp
      000C62 24 0E            [12] 2867 	add	a,#0x0e
      000C64 F8               [12] 2868 	mov	r0,a
      000C65 86 82            [24] 2869 	mov	dpl, @r0
      000C67 08               [12] 2870 	inc	r0
      000C68 86 83            [24] 2871 	mov	dph, @r0
      000C6A 08               [12] 2872 	inc	r0
      000C6B 86 F0            [24] 2873 	mov	b, @r0
      000C6D 08               [12] 2874 	inc	r0
      000C6E E6               [12] 2875 	mov	a, @r0
      000C6F 12 12 C8         [24] 2876 	lcall	___fsdiv
      000C72 AC 82            [24] 2877 	mov	r4, dpl
      000C74 AD 83            [24] 2878 	mov	r5, dph
      000C76 AE F0            [24] 2879 	mov	r6, b
      000C78 FF               [12] 2880 	mov	r7, a
      000C79 E5 81            [12] 2881 	mov	a,sp
      000C7B 24 FC            [12] 2882 	add	a,#0xfc
      000C7D F5 81            [12] 2883 	mov	sp,a
      000C7F 8C 82            [24] 2884 	mov	dpl, r4
      000C81 8D 83            [24] 2885 	mov	dph, r5
      000C83 8E F0            [24] 2886 	mov	b, r6
      000C85 EF               [12] 2887 	mov	a, r7
      000C86                       2888 00116$:
                           000BCF  2889 	C$fuzzy.h$1434$1_0$76 ==.
                                   2890 ;	/home/mahavigna/CI/fuzzy.h:1434: }
      000C86 85 0E 81         [24] 2891 	mov	sp,_bp
      000C89 D0 0E            [24] 2892 	pop	_bp
                           000BD4  2893 	C$fuzzy.h$1434$1_0$76 ==.
                           000BD4  2894 	XG$fuzzy_rules_cog$0$0 ==.
      000C8B 22               [24] 2895 	ret
                                   2896 ;------------------------------------------------------------
                                   2897 ;Allocation info for local variables in function 'fuzzy_rules_free'
                                   2898 ;------------------------------------------------------------
                                   2899 ;rules         Allocated to registers r5 r6 r7 
                                   2900 ;------------------------------------------------------------
                           000BD5  2901 	G$fuzzy_rules_free$0$0 ==.
                           000BD5  2902 	C$fuzzy.h$1436$1_0$84 ==.
                                   2903 ;	/home/mahavigna/CI/fuzzy.h:1436: void fuzzy_rules_free(
                                   2904 ;	-----------------------------------------
                                   2905 ;	 function fuzzy_rules_free
                                   2906 ;	-----------------------------------------
      000C8C                       2907 _fuzzy_rules_free:
      000C8C AD 82            [24] 2908 	mov	r5, dpl
      000C8E AE 83            [24] 2909 	mov	r6, dph
      000C90 AF F0            [24] 2910 	mov	r7, b
                           000BDB  2911 	C$fuzzy.h$1440$1_0$84 ==.
                                   2912 ;	/home/mahavigna/CI/fuzzy.h:1440: if (rules == NULL) {
      000C92 ED               [12] 2913 	mov	a,r5
      000C93 4E               [12] 2914 	orl	a,r6
      000C94 70 02            [24] 2915 	jnz	00102$
                           000BDF  2916 	C$fuzzy.h$1441$2_0$85 ==.
                                   2917 ;	/home/mahavigna/CI/fuzzy.h:1441: return;
      000C96 80 15            [24] 2918 	sjmp	00103$
      000C98                       2919 00102$:
                           000BE1  2920 	C$fuzzy.h$1449$1_0$84 ==.
                                   2921 ;	/home/mahavigna/CI/fuzzy.h:1449: rules->count = 0;
      000C98 74 0C            [12] 2922 	mov	a,#0x0c
      000C9A 2D               [12] 2923 	add	a, r5
      000C9B FD               [12] 2924 	mov	r5,a
      000C9C E4               [12] 2925 	clr	a
      000C9D 3E               [12] 2926 	addc	a, r6
      000C9E FE               [12] 2927 	mov	r6,a
      000C9F 8D 82            [24] 2928 	mov	dpl,r5
      000CA1 8E 83            [24] 2929 	mov	dph,r6
      000CA3 8F F0            [24] 2930 	mov	b,r7
      000CA5 E4               [12] 2931 	clr	a
      000CA6 12 11 50         [24] 2932 	lcall	__gptrput
      000CA9 A3               [24] 2933 	inc	dptr
      000CAA 12 11 50         [24] 2934 	lcall	__gptrput
      000CAD                       2935 00103$:
                           000BF6  2936 	C$fuzzy.h$1450$1_0$84 ==.
                                   2937 ;	/home/mahavigna/CI/fuzzy.h:1450: }
                           000BF6  2938 	C$fuzzy.h$1450$1_0$84 ==.
                           000BF6  2939 	XG$fuzzy_rules_free$0$0 ==.
      000CAD 22               [24] 2940 	ret
                                   2941 ;------------------------------------------------------------
                                   2942 ;Allocation info for local variables in function 'temperature_low'
                                   2943 ;------------------------------------------------------------
                                   2944 ;value         Allocated to registers r4 r5 r6 r7 
                                   2945 ;------------------------------------------------------------
                           000BF7  2946 	Fcontroller_8051$temperature_low$0$0 ==.
                           000BF7  2947 	C$controller_8051.c$63$1_0$87 ==.
                                   2948 ;	/home/mahavigna/CI/controller_8051.c:63: static float temperature_low(
                                   2949 ;	-----------------------------------------
                                   2950 ;	 function temperature_low
                                   2951 ;	-----------------------------------------
      000CAE                       2952 _temperature_low:
      000CAE AC 82            [24] 2953 	mov	r4,dpl
      000CB0 AD 83            [24] 2954 	mov	r5,dph
      000CB2 AE F0            [24] 2955 	mov	r6,b
      000CB4 FF               [12] 2956 	mov	r7,a
                           000BFE  2957 	C$controller_8051.c$73$1_0$87 ==.
                                   2958 ;	/home/mahavigna/CI/controller_8051.c:73: hedges.none
      000CB5 90 14 4D         [24] 2959 	mov	dptr,#_hedges
      000CB8 E4               [12] 2960 	clr	a
      000CB9 93               [24] 2961 	movc	a,@a+dptr
      000CBA FB               [12] 2962 	mov	r3,a
                           000C04  2963 	C$controller_8051.c$68$1_0$87 ==.
                                   2964 ;	/home/mahavigna/CI/controller_8051.c:68: NULL,
      000CBB C0 03            [24] 2965 	push	ar3
      000CBD E4               [12] 2966 	clr	a
      000CBE C0 E0            [24] 2967 	push	acc
      000CC0 C0 04            [24] 2968 	push	ar4
      000CC2 C0 05            [24] 2969 	push	ar5
      000CC4 C0 06            [24] 2970 	push	ar6
      000CC6 C0 07            [24] 2971 	push	ar7
      000CC8 C0 E0            [24] 2972 	push	acc
      000CCA C0 E0            [24] 2973 	push	acc
      000CCC 74 20            [12] 2974 	mov	a,#0x20
      000CCE C0 E0            [24] 2975 	push	acc
      000CD0 74 42            [12] 2976 	mov	a,#0x42
      000CD2 C0 E0            [24] 2977 	push	acc
      000CD4 E4               [12] 2978 	clr	a
      000CD5 C0 E0            [24] 2979 	push	acc
      000CD7 C0 E0            [24] 2980 	push	acc
      000CD9 74 A0            [12] 2981 	mov	a,#0xa0
      000CDB C0 E0            [24] 2982 	push	acc
      000CDD 23               [12] 2983 	rl	a
      000CDE C0 E0            [24] 2984 	push	acc
      000CE0 90 00 00         [24] 2985 	mov	dptr,#0x0000
      000CE3 75 F0 00         [24] 2986 	mov	b, #0x00
      000CE6 12 04 F5         [24] 2987 	lcall	_fuzzy_ramp
      000CE9 AC 82            [24] 2988 	mov	r4, dpl
      000CEB AD 83            [24] 2989 	mov	r5, dph
      000CED AE F0            [24] 2990 	mov	r6, b
      000CEF FF               [12] 2991 	mov	r7, a
      000CF0 E5 81            [12] 2992 	mov	a,sp
      000CF2 24 F2            [12] 2993 	add	a,#0xf2
      000CF4 F5 81            [12] 2994 	mov	sp,a
      000CF6 8C 82            [24] 2995 	mov	dpl, r4
      000CF8 8D 83            [24] 2996 	mov	dph, r5
      000CFA 8E F0            [24] 2997 	mov	b, r6
      000CFC EF               [12] 2998 	mov	a, r7
                           000C46  2999 	C$controller_8051.c$75$1_0$87 ==.
                                   3000 ;	/home/mahavigna/CI/controller_8051.c:75: }
                           000C46  3001 	C$controller_8051.c$75$1_0$87 ==.
                           000C46  3002 	XFcontroller_8051$temperature_low$0$0 ==.
      000CFD 22               [24] 3003 	ret
                                   3004 ;------------------------------------------------------------
                                   3005 ;Allocation info for local variables in function 'temperature_high'
                                   3006 ;------------------------------------------------------------
                                   3007 ;value         Allocated to registers r4 r5 r6 r7 
                                   3008 ;------------------------------------------------------------
                           000C47  3009 	Fcontroller_8051$temperature_high$0$0 ==.
                           000C47  3010 	C$controller_8051.c$78$1_0$89 ==.
                                   3011 ;	/home/mahavigna/CI/controller_8051.c:78: static float temperature_high(
                                   3012 ;	-----------------------------------------
                                   3013 ;	 function temperature_high
                                   3014 ;	-----------------------------------------
      000CFE                       3015 _temperature_high:
      000CFE AC 82            [24] 3016 	mov	r4,dpl
      000D00 AD 83            [24] 3017 	mov	r5,dph
      000D02 AE F0            [24] 3018 	mov	r6,b
      000D04 FF               [12] 3019 	mov	r7,a
                           000C4E  3020 	C$controller_8051.c$88$1_0$89 ==.
                                   3021 ;	/home/mahavigna/CI/controller_8051.c:88: hedges.none
      000D05 90 14 4D         [24] 3022 	mov	dptr,#_hedges
      000D08 E4               [12] 3023 	clr	a
      000D09 93               [24] 3024 	movc	a,@a+dptr
      000D0A FB               [12] 3025 	mov	r3,a
                           000C54  3026 	C$controller_8051.c$83$1_0$89 ==.
                                   3027 ;	/home/mahavigna/CI/controller_8051.c:83: NULL,
      000D0B C0 03            [24] 3028 	push	ar3
      000D0D 74 01            [12] 3029 	mov	a,#0x01
      000D0F C0 E0            [24] 3030 	push	acc
      000D11 C0 04            [24] 3031 	push	ar4
      000D13 C0 05            [24] 3032 	push	ar5
      000D15 C0 06            [24] 3033 	push	ar6
      000D17 C0 07            [24] 3034 	push	ar7
      000D19 E4               [12] 3035 	clr	a
      000D1A C0 E0            [24] 3036 	push	acc
      000D1C C0 E0            [24] 3037 	push	acc
      000D1E 74 70            [12] 3038 	mov	a,#0x70
      000D20 C0 E0            [24] 3039 	push	acc
      000D22 74 42            [12] 3040 	mov	a,#0x42
      000D24 C0 E0            [24] 3041 	push	acc
      000D26 E4               [12] 3042 	clr	a
      000D27 C0 E0            [24] 3043 	push	acc
      000D29 C0 E0            [24] 3044 	push	acc
      000D2B 74 F0            [12] 3045 	mov	a,#0xf0
      000D2D C0 E0            [24] 3046 	push	acc
      000D2F 74 41            [12] 3047 	mov	a,#0x41
      000D31 C0 E0            [24] 3048 	push	acc
      000D33 90 00 00         [24] 3049 	mov	dptr,#0x0000
      000D36 75 F0 00         [24] 3050 	mov	b, #0x00
      000D39 12 04 F5         [24] 3051 	lcall	_fuzzy_ramp
      000D3C AC 82            [24] 3052 	mov	r4, dpl
      000D3E AD 83            [24] 3053 	mov	r5, dph
      000D40 AE F0            [24] 3054 	mov	r6, b
      000D42 FF               [12] 3055 	mov	r7, a
      000D43 E5 81            [12] 3056 	mov	a,sp
      000D45 24 F2            [12] 3057 	add	a,#0xf2
      000D47 F5 81            [12] 3058 	mov	sp,a
      000D49 8C 82            [24] 3059 	mov	dpl, r4
      000D4B 8D 83            [24] 3060 	mov	dph, r5
      000D4D 8E F0            [24] 3061 	mov	b, r6
      000D4F EF               [12] 3062 	mov	a, r7
                           000C99  3063 	C$controller_8051.c$90$1_0$89 ==.
                                   3064 ;	/home/mahavigna/CI/controller_8051.c:90: }
                           000C99  3065 	C$controller_8051.c$90$1_0$89 ==.
                           000C99  3066 	XFcontroller_8051$temperature_high$0$0 ==.
      000D50 22               [24] 3067 	ret
                                   3068 ;------------------------------------------------------------
                                   3069 ;Allocation info for local variables in function 'fan_slow'
                                   3070 ;------------------------------------------------------------
                                   3071 ;value         Allocated to registers r4 r5 r6 r7 
                                   3072 ;------------------------------------------------------------
                           000C9A  3073 	Fcontroller_8051$fan_slow$0$0 ==.
                           000C9A  3074 	C$controller_8051.c$97$1_0$91 ==.
                                   3075 ;	/home/mahavigna/CI/controller_8051.c:97: static float fan_slow(
                                   3076 ;	-----------------------------------------
                                   3077 ;	 function fan_slow
                                   3078 ;	-----------------------------------------
      000D51                       3079 _fan_slow:
      000D51 AC 82            [24] 3080 	mov	r4,dpl
      000D53 AD 83            [24] 3081 	mov	r5,dph
      000D55 AE F0            [24] 3082 	mov	r6,b
      000D57 FF               [12] 3083 	mov	r7,a
                           000CA1  3084 	C$controller_8051.c$107$1_0$91 ==.
                                   3085 ;	/home/mahavigna/CI/controller_8051.c:107: hedges.none
      000D58 90 14 4D         [24] 3086 	mov	dptr,#_hedges
      000D5B E4               [12] 3087 	clr	a
      000D5C 93               [24] 3088 	movc	a,@a+dptr
      000D5D FB               [12] 3089 	mov	r3,a
                           000CA7  3090 	C$controller_8051.c$102$1_0$91 ==.
                                   3091 ;	/home/mahavigna/CI/controller_8051.c:102: NULL,
      000D5E C0 03            [24] 3092 	push	ar3
      000D60 E4               [12] 3093 	clr	a
      000D61 C0 E0            [24] 3094 	push	acc
      000D63 C0 04            [24] 3095 	push	ar4
      000D65 C0 05            [24] 3096 	push	ar5
      000D67 C0 06            [24] 3097 	push	ar6
      000D69 C0 07            [24] 3098 	push	ar7
      000D6B C0 E0            [24] 3099 	push	acc
      000D6D C0 E0            [24] 3100 	push	acc
      000D6F 74 48            [12] 3101 	mov	a,#0x48
      000D71 C0 E0            [24] 3102 	push	acc
      000D73 74 42            [12] 3103 	mov	a,#0x42
      000D75 C0 E0            [24] 3104 	push	acc
      000D77 E4               [12] 3105 	clr	a
      000D78 C0 E0            [24] 3106 	push	acc
      000D7A C0 E0            [24] 3107 	push	acc
      000D7C 74 A0            [12] 3108 	mov	a,#0xa0
      000D7E C0 E0            [24] 3109 	push	acc
      000D80 23               [12] 3110 	rl	a
      000D81 C0 E0            [24] 3111 	push	acc
      000D83 90 00 00         [24] 3112 	mov	dptr,#0x0000
      000D86 75 F0 00         [24] 3113 	mov	b, #0x00
      000D89 12 04 F5         [24] 3114 	lcall	_fuzzy_ramp
      000D8C AC 82            [24] 3115 	mov	r4, dpl
      000D8E AD 83            [24] 3116 	mov	r5, dph
      000D90 AE F0            [24] 3117 	mov	r6, b
      000D92 FF               [12] 3118 	mov	r7, a
      000D93 E5 81            [12] 3119 	mov	a,sp
      000D95 24 F2            [12] 3120 	add	a,#0xf2
      000D97 F5 81            [12] 3121 	mov	sp,a
      000D99 8C 82            [24] 3122 	mov	dpl, r4
      000D9B 8D 83            [24] 3123 	mov	dph, r5
      000D9D 8E F0            [24] 3124 	mov	b, r6
      000D9F EF               [12] 3125 	mov	a, r7
                           000CE9  3126 	C$controller_8051.c$109$1_0$91 ==.
                                   3127 ;	/home/mahavigna/CI/controller_8051.c:109: }
                           000CE9  3128 	C$controller_8051.c$109$1_0$91 ==.
                           000CE9  3129 	XFcontroller_8051$fan_slow$0$0 ==.
      000DA0 22               [24] 3130 	ret
                                   3131 ;------------------------------------------------------------
                                   3132 ;Allocation info for local variables in function 'fan_fast'
                                   3133 ;------------------------------------------------------------
                                   3134 ;value         Allocated to registers r4 r5 r6 r7 
                                   3135 ;------------------------------------------------------------
                           000CEA  3136 	Fcontroller_8051$fan_fast$0$0 ==.
                           000CEA  3137 	C$controller_8051.c$112$1_0$93 ==.
                                   3138 ;	/home/mahavigna/CI/controller_8051.c:112: static float fan_fast(
                                   3139 ;	-----------------------------------------
                                   3140 ;	 function fan_fast
                                   3141 ;	-----------------------------------------
      000DA1                       3142 _fan_fast:
      000DA1 AC 82            [24] 3143 	mov	r4,dpl
      000DA3 AD 83            [24] 3144 	mov	r5,dph
      000DA5 AE F0            [24] 3145 	mov	r6,b
      000DA7 FF               [12] 3146 	mov	r7,a
                           000CF1  3147 	C$controller_8051.c$122$1_0$93 ==.
                                   3148 ;	/home/mahavigna/CI/controller_8051.c:122: hedges.none
      000DA8 90 14 4D         [24] 3149 	mov	dptr,#_hedges
      000DAB E4               [12] 3150 	clr	a
      000DAC 93               [24] 3151 	movc	a,@a+dptr
      000DAD FB               [12] 3152 	mov	r3,a
                           000CF7  3153 	C$controller_8051.c$117$1_0$93 ==.
                                   3154 ;	/home/mahavigna/CI/controller_8051.c:117: NULL,
      000DAE C0 03            [24] 3155 	push	ar3
      000DB0 74 01            [12] 3156 	mov	a,#0x01
      000DB2 C0 E0            [24] 3157 	push	acc
      000DB4 C0 04            [24] 3158 	push	ar4
      000DB6 C0 05            [24] 3159 	push	ar5
      000DB8 C0 06            [24] 3160 	push	ar6
      000DBA C0 07            [24] 3161 	push	ar7
      000DBC E4               [12] 3162 	clr	a
      000DBD C0 E0            [24] 3163 	push	acc
      000DBF C0 E0            [24] 3164 	push	acc
      000DC1 74 A0            [12] 3165 	mov	a,#0xa0
      000DC3 C0 E0            [24] 3166 	push	acc
      000DC5 74 42            [12] 3167 	mov	a,#0x42
      000DC7 C0 E0            [24] 3168 	push	acc
      000DC9 E4               [12] 3169 	clr	a
      000DCA C0 E0            [24] 3170 	push	acc
      000DCC C0 E0            [24] 3171 	push	acc
      000DCE 74 20            [12] 3172 	mov	a,#0x20
      000DD0 C0 E0            [24] 3173 	push	acc
      000DD2 74 42            [12] 3174 	mov	a,#0x42
      000DD4 C0 E0            [24] 3175 	push	acc
      000DD6 90 00 00         [24] 3176 	mov	dptr,#0x0000
      000DD9 75 F0 00         [24] 3177 	mov	b, #0x00
      000DDC 12 04 F5         [24] 3178 	lcall	_fuzzy_ramp
      000DDF AC 82            [24] 3179 	mov	r4, dpl
      000DE1 AD 83            [24] 3180 	mov	r5, dph
      000DE3 AE F0            [24] 3181 	mov	r6, b
      000DE5 FF               [12] 3182 	mov	r7, a
      000DE6 E5 81            [12] 3183 	mov	a,sp
      000DE8 24 F2            [12] 3184 	add	a,#0xf2
      000DEA F5 81            [12] 3185 	mov	sp,a
      000DEC 8C 82            [24] 3186 	mov	dpl, r4
      000DEE 8D 83            [24] 3187 	mov	dph, r5
      000DF0 8E F0            [24] 3188 	mov	b, r6
      000DF2 EF               [12] 3189 	mov	a, r7
                           000D3C  3190 	C$controller_8051.c$124$1_0$93 ==.
                                   3191 ;	/home/mahavigna/CI/controller_8051.c:124: }
                           000D3C  3192 	C$controller_8051.c$124$1_0$93 ==.
                           000D3C  3193 	XFcontroller_8051$fan_fast$0$0 ==.
      000DF3 22               [24] 3194 	ret
                                   3195 ;------------------------------------------------------------
                                   3196 ;Allocation info for local variables in function 'calculate_fan_speed'
                                   3197 ;------------------------------------------------------------
                                   3198 ;temperature   Allocated to stack - _bp +1 +4 
                                   3199 ;rules         Allocated to stack - _bp +9 +14 
                                   3200 ;result        Allocated to stack - _bp +23 +4 
                                   3201 ;sloc0         Allocated to stack - _bp +5 +4 
                                   3202 ;------------------------------------------------------------
                           000D3D  3203 	Fcontroller_8051$calculate_fan_speed$0$0 ==.
                           000D3D  3204 	C$controller_8051.c$131$1_0$95 ==.
                                   3205 ;	/home/mahavigna/CI/controller_8051.c:131: static float calculate_fan_speed(
                                   3206 ;	-----------------------------------------
                                   3207 ;	 function calculate_fan_speed
                                   3208 ;	-----------------------------------------
      000DF4                       3209 _calculate_fan_speed:
      000DF4 C0 0E            [24] 3210 	push	_bp
      000DF6 85 81 0E         [24] 3211 	mov	_bp,sp
      000DF9 C0 82            [24] 3212 	push	dpl
      000DFB C0 83            [24] 3213 	push	dph
      000DFD C0 F0            [24] 3214 	push	b
      000DFF C0 E0            [24] 3215 	push	acc
      000E01 E5 81            [12] 3216 	mov	a,sp
      000E03 24 16            [12] 3217 	add	a,#0x16
      000E05 F5 81            [12] 3218 	mov	sp,a
                           000D50  3219 	C$controller_8051.c$140$1_0$95 ==.
                                   3220 ;	/home/mahavigna/CI/controller_8051.c:140: );
      000E07 E5 0E            [12] 3221 	mov	a,_bp
      000E09 24 09            [12] 3222 	add	a,#0x09
      000E0B FB               [12] 3223 	mov	r3,a
      000E0C FA               [12] 3224 	mov	r2,a
      000E0D 7E 00            [12] 3225 	mov	r6,#0x00
      000E0F 7F 40            [12] 3226 	mov	r7,#0x40
      000E11 8A 82            [24] 3227 	mov	dpl, r2
      000E13 8E 83            [24] 3228 	mov	dph, r6
      000E15 8F F0            [24] 3229 	mov	b, r7
      000E17 C0 03            [24] 3230 	push	ar3
      000E19 12 07 1A         [24] 3231 	lcall	_fuzzy_rules_create
                           000D65  3232 	C$controller_8051.c$142$1_0$95 ==.
                                   3233 ;	/home/mahavigna/CI/controller_8051.c:142: if (!FUZZY_RULE_ADD(
      000E1C A8 0E            [24] 3234 	mov	r0,_bp
      000E1E 08               [12] 3235 	inc	r0
      000E1F 86 82            [24] 3236 	mov	dpl, @r0
      000E21 08               [12] 3237 	inc	r0
      000E22 86 83            [24] 3238 	mov	dph, @r0
      000E24 08               [12] 3239 	inc	r0
      000E25 86 F0            [24] 3240 	mov	b, @r0
      000E27 08               [12] 3241 	inc	r0
      000E28 E6               [12] 3242 	mov	a, @r0
      000E29 12 0C AE         [24] 3243 	lcall	_temperature_low
      000E2C C8               [12] 3244 	xch	a,r0
      000E2D E5 0E            [12] 3245 	mov	a,_bp
      000E2F 24 05            [12] 3246 	add	a,#0x05
      000E31 C8               [12] 3247 	xch	a,r0
      000E32 A6 82            [24] 3248 	mov	@r0, dpl
      000E34 08               [12] 3249 	inc	r0
      000E35 A6 83            [24] 3250 	mov	@r0, dph
      000E37 08               [12] 3251 	inc	r0
      000E38 A6 F0            [24] 3252 	mov	@r0, b
      000E3A 08               [12] 3253 	inc	r0
      000E3B F6               [12] 3254 	mov	@r0,a
      000E3C D0 03            [24] 3255 	pop	ar3
      000E3E 8B 02            [24] 3256 	mov	ar2,r3
      000E40 7E 00            [12] 3257 	mov	r6,#0x00
      000E42 7F 40            [12] 3258 	mov	r7,#0x40
      000E44 C0 03            [24] 3259 	push	ar3
      000E46 74 51            [12] 3260 	mov	a,#_fan_slow
      000E48 C0 E0            [24] 3261 	push	acc
      000E4A 74 0D            [12] 3262 	mov	a,#(_fan_slow >> 8)
      000E4C C0 E0            [24] 3263 	push	acc
      000E4E E5 0E            [12] 3264 	mov	a,_bp
      000E50 24 05            [12] 3265 	add	a,#0x05
      000E52 F8               [12] 3266 	mov	r0,a
      000E53 E6               [12] 3267 	mov	a,@r0
      000E54 C0 E0            [24] 3268 	push	acc
      000E56 08               [12] 3269 	inc	r0
      000E57 E6               [12] 3270 	mov	a,@r0
      000E58 C0 E0            [24] 3271 	push	acc
      000E5A 08               [12] 3272 	inc	r0
      000E5B E6               [12] 3273 	mov	a,@r0
      000E5C C0 E0            [24] 3274 	push	acc
      000E5E 08               [12] 3275 	inc	r0
      000E5F E6               [12] 3276 	mov	a,@r0
      000E60 C0 E0            [24] 3277 	push	acc
      000E62 E4               [12] 3278 	clr	a
      000E63 C0 E0            [24] 3279 	push	acc
      000E65 C0 E0            [24] 3280 	push	acc
      000E67 C0 E0            [24] 3281 	push	acc
      000E69 8A 82            [24] 3282 	mov	dpl, r2
      000E6B 8E 83            [24] 3283 	mov	dph, r6
      000E6D 8F F0            [24] 3284 	mov	b, r7
      000E6F 12 07 3C         [24] 3285 	lcall	_fuzzy_rules_add
      000E72 AF 82            [24] 3286 	mov	r7, dpl
      000E74 E5 81            [12] 3287 	mov	a,sp
      000E76 24 F7            [12] 3288 	add	a,#0xf7
      000E78 F5 81            [12] 3289 	mov	sp,a
      000E7A D0 03            [24] 3290 	pop	ar3
      000E7C EF               [12] 3291 	mov	a,r7
      000E7D 70 09            [24] 3292 	jnz	00102$
                           000DC8  3293 	C$controller_8051.c$147$2_0$96 ==.
                                   3294 ;	/home/mahavigna/CI/controller_8051.c:147: return 0.0f;
      000E7F 90 00 00         [24] 3295 	mov	dptr,#0x0000
      000E82 E4               [12] 3296 	clr	a
      000E83 F5 F0            [12] 3297 	mov	b,a
      000E85 02 0F 5F         [24] 3298 	ljmp	00105$
      000E88                       3299 00102$:
                           000DD1  3300 	C$controller_8051.c$150$1_0$95 ==.
                                   3301 ;	/home/mahavigna/CI/controller_8051.c:150: if (!FUZZY_RULE_ADD(
      000E88 A8 0E            [24] 3302 	mov	r0,_bp
      000E8A 08               [12] 3303 	inc	r0
      000E8B 86 82            [24] 3304 	mov	dpl, @r0
      000E8D 08               [12] 3305 	inc	r0
      000E8E 86 83            [24] 3306 	mov	dph, @r0
      000E90 08               [12] 3307 	inc	r0
      000E91 86 F0            [24] 3308 	mov	b, @r0
      000E93 08               [12] 3309 	inc	r0
      000E94 E6               [12] 3310 	mov	a, @r0
      000E95 C0 03            [24] 3311 	push	ar3
      000E97 12 0C FE         [24] 3312 	lcall	_temperature_high
      000E9A C8               [12] 3313 	xch	a,r0
      000E9B E5 0E            [12] 3314 	mov	a,_bp
      000E9D 24 05            [12] 3315 	add	a,#0x05
      000E9F C8               [12] 3316 	xch	a,r0
      000EA0 A6 82            [24] 3317 	mov	@r0, dpl
      000EA2 08               [12] 3318 	inc	r0
      000EA3 A6 83            [24] 3319 	mov	@r0, dph
      000EA5 08               [12] 3320 	inc	r0
      000EA6 A6 F0            [24] 3321 	mov	@r0, b
      000EA8 08               [12] 3322 	inc	r0
      000EA9 F6               [12] 3323 	mov	@r0,a
      000EAA D0 03            [24] 3324 	pop	ar3
      000EAC 8B 02            [24] 3325 	mov	ar2,r3
      000EAE 7E 00            [12] 3326 	mov	r6,#0x00
      000EB0 7F 40            [12] 3327 	mov	r7,#0x40
      000EB2 C0 03            [24] 3328 	push	ar3
      000EB4 74 A1            [12] 3329 	mov	a,#_fan_fast
      000EB6 C0 E0            [24] 3330 	push	acc
      000EB8 74 0D            [12] 3331 	mov	a,#(_fan_fast >> 8)
      000EBA C0 E0            [24] 3332 	push	acc
      000EBC E5 0E            [12] 3333 	mov	a,_bp
      000EBE 24 05            [12] 3334 	add	a,#0x05
      000EC0 F8               [12] 3335 	mov	r0,a
      000EC1 E6               [12] 3336 	mov	a,@r0
      000EC2 C0 E0            [24] 3337 	push	acc
      000EC4 08               [12] 3338 	inc	r0
      000EC5 E6               [12] 3339 	mov	a,@r0
      000EC6 C0 E0            [24] 3340 	push	acc
      000EC8 08               [12] 3341 	inc	r0
      000EC9 E6               [12] 3342 	mov	a,@r0
      000ECA C0 E0            [24] 3343 	push	acc
      000ECC 08               [12] 3344 	inc	r0
      000ECD E6               [12] 3345 	mov	a,@r0
      000ECE C0 E0            [24] 3346 	push	acc
      000ED0 E4               [12] 3347 	clr	a
      000ED1 C0 E0            [24] 3348 	push	acc
      000ED3 C0 E0            [24] 3349 	push	acc
      000ED5 C0 E0            [24] 3350 	push	acc
      000ED7 8A 82            [24] 3351 	mov	dpl, r2
      000ED9 8E 83            [24] 3352 	mov	dph, r6
      000EDB 8F F0            [24] 3353 	mov	b, r7
      000EDD 12 07 3C         [24] 3354 	lcall	_fuzzy_rules_add
      000EE0 AF 82            [24] 3355 	mov	r7, dpl
      000EE2 E5 81            [12] 3356 	mov	a,sp
      000EE4 24 F7            [12] 3357 	add	a,#0xf7
      000EE6 F5 81            [12] 3358 	mov	sp,a
      000EE8 D0 03            [24] 3359 	pop	ar3
      000EEA EF               [12] 3360 	mov	a,r7
      000EEB 70 08            [24] 3361 	jnz	00104$
                           000E36  3362 	C$controller_8051.c$155$2_0$97 ==.
                                   3363 ;	/home/mahavigna/CI/controller_8051.c:155: return 0.0f;
      000EED 90 00 00         [24] 3364 	mov	dptr,#0x0000
      000EF0 E4               [12] 3365 	clr	a
      000EF1 F5 F0            [12] 3366 	mov	b,a
      000EF3 80 6A            [24] 3367 	sjmp	00105$
      000EF5                       3368 00104$:
                           000E3E  3369 	C$controller_8051.c$160$1_0$95 ==.
                                   3370 ;	/home/mahavigna/CI/controller_8051.c:160: &rules,
      000EF5 8B 05            [24] 3371 	mov	ar5,r3
      000EF7 7E 00            [12] 3372 	mov	r6,#0x00
      000EF9 7F 40            [12] 3373 	mov	r7,#0x40
      000EFB C0 03            [24] 3374 	push	ar3
      000EFD E4               [12] 3375 	clr	a
      000EFE C0 E0            [24] 3376 	push	acc
      000F00 C0 E0            [24] 3377 	push	acc
      000F02 74 20            [12] 3378 	mov	a,#0x20
      000F04 C0 E0            [24] 3379 	push	acc
      000F06 74 41            [12] 3380 	mov	a,#0x41
      000F08 C0 E0            [24] 3381 	push	acc
      000F0A E4               [12] 3382 	clr	a
      000F0B C0 E0            [24] 3383 	push	acc
      000F0D C0 E0            [24] 3384 	push	acc
      000F0F 74 C8            [12] 3385 	mov	a,#0xc8
      000F11 C0 E0            [24] 3386 	push	acc
      000F13 74 42            [12] 3387 	mov	a,#0x42
      000F15 C0 E0            [24] 3388 	push	acc
      000F17 E4               [12] 3389 	clr	a
      000F18 C0 E0            [24] 3390 	push	acc
      000F1A C0 E0            [24] 3391 	push	acc
      000F1C C0 E0            [24] 3392 	push	acc
      000F1E C0 E0            [24] 3393 	push	acc
      000F20 8D 82            [24] 3394 	mov	dpl, r5
      000F22 8E 83            [24] 3395 	mov	dph, r6
      000F24 8F F0            [24] 3396 	mov	b, r7
      000F26 12 08 69         [24] 3397 	lcall	_fuzzy_rules_cog
      000F29 C8               [12] 3398 	xch	a,r0
      000F2A E5 0E            [12] 3399 	mov	a,_bp
      000F2C 24 17            [12] 3400 	add	a,#0x17
      000F2E C8               [12] 3401 	xch	a,r0
      000F2F A6 82            [24] 3402 	mov	@r0, dpl
      000F31 08               [12] 3403 	inc	r0
      000F32 A6 83            [24] 3404 	mov	@r0, dph
      000F34 08               [12] 3405 	inc	r0
      000F35 A6 F0            [24] 3406 	mov	@r0, b
      000F37 08               [12] 3407 	inc	r0
      000F38 F6               [12] 3408 	mov	@r0,a
      000F39 E5 81            [12] 3409 	mov	a,sp
      000F3B 24 F4            [12] 3410 	add	a,#0xf4
      000F3D F5 81            [12] 3411 	mov	sp,a
      000F3F D0 03            [24] 3412 	pop	ar3
                           000E8A  3413 	C$controller_8051.c$168$1_0$95 ==.
                                   3414 ;	/home/mahavigna/CI/controller_8051.c:168: );
      000F41 8B 02            [24] 3415 	mov	ar2,r3
      000F43 7B 00            [12] 3416 	mov	r3,#0x00
      000F45 7F 40            [12] 3417 	mov	r7,#0x40
      000F47 8A 82            [24] 3418 	mov	dpl, r2
      000F49 8B 83            [24] 3419 	mov	dph, r3
      000F4B 8F F0            [24] 3420 	mov	b, r7
      000F4D 12 0C 8C         [24] 3421 	lcall	_fuzzy_rules_free
                           000E99  3422 	C$controller_8051.c$170$1_0$95 ==.
                                   3423 ;	/home/mahavigna/CI/controller_8051.c:170: return result;
      000F50 E5 0E            [12] 3424 	mov	a,_bp
      000F52 24 17            [12] 3425 	add	a,#0x17
      000F54 F8               [12] 3426 	mov	r0,a
      000F55 86 82            [24] 3427 	mov	dpl, @r0
      000F57 08               [12] 3428 	inc	r0
      000F58 86 83            [24] 3429 	mov	dph, @r0
      000F5A 08               [12] 3430 	inc	r0
      000F5B 86 F0            [24] 3431 	mov	b, @r0
      000F5D 08               [12] 3432 	inc	r0
      000F5E E6               [12] 3433 	mov	a, @r0
      000F5F                       3434 00105$:
                           000EA8  3435 	C$controller_8051.c$171$1_0$95 ==.
                                   3436 ;	/home/mahavigna/CI/controller_8051.c:171: }
      000F5F 85 0E 81         [24] 3437 	mov	sp,_bp
      000F62 D0 0E            [24] 3438 	pop	_bp
                           000EAD  3439 	C$controller_8051.c$171$1_0$95 ==.
                           000EAD  3440 	XFcontroller_8051$calculate_fan_speed$0$0 ==.
      000F64 22               [24] 3441 	ret
                                   3442 ;------------------------------------------------------------
                                   3443 ;Allocation info for local variables in function 'fan_speed_to_pwm'
                                   3444 ;------------------------------------------------------------
                                   3445 ;fan_speed     Allocated to registers r4 r5 r6 r7 
                                   3446 ;------------------------------------------------------------
                           000EAE  3447 	Fcontroller_8051$fan_speed_to_pwm$0$0 ==.
                           000EAE  3448 	C$controller_8051.c$178$1_0$99 ==.
                                   3449 ;	/home/mahavigna/CI/controller_8051.c:178: static unsigned char fan_speed_to_pwm(
                                   3450 ;	-----------------------------------------
                                   3451 ;	 function fan_speed_to_pwm
                                   3452 ;	-----------------------------------------
      000F65                       3453 _fan_speed_to_pwm:
      000F65 AC 82            [24] 3454 	mov	r4,dpl
      000F67 AD 83            [24] 3455 	mov	r5,dph
      000F69 AE F0            [24] 3456 	mov	r6,b
      000F6B FF               [12] 3457 	mov	r7,a
                           000EB5  3458 	C$controller_8051.c$182$1_0$99 ==.
                                   3459 ;	/home/mahavigna/CI/controller_8051.c:182: if (fan_speed <= 0.0f) {
      000F6C C0 07            [24] 3460 	push	ar7
      000F6E C0 06            [24] 3461 	push	ar6
      000F70 C0 05            [24] 3462 	push	ar5
      000F72 C0 04            [24] 3463 	push	ar4
      000F74 C0 04            [24] 3464 	push	ar4
      000F76 C0 05            [24] 3465 	push	ar5
      000F78 C0 06            [24] 3466 	push	ar6
      000F7A C0 07            [24] 3467 	push	ar7
      000F7C 90 00 00         [24] 3468 	mov	dptr,#0x0000
      000F7F E4               [12] 3469 	clr	a
      000F80 F5 F0            [12] 3470 	mov	b,a
      000F82 12 11 6B         [24] 3471 	lcall	___fslt
      000F85 E5 81            [12] 3472 	mov	a,sp
      000F87 24 FC            [12] 3473 	add	a,#0xfc
      000F89 F5 81            [12] 3474 	mov	sp,a
      000F8B D0 04            [24] 3475 	pop	ar4
      000F8D D0 05            [24] 3476 	pop	ar5
      000F8F D0 06            [24] 3477 	pop	ar6
      000F91 D0 07            [24] 3478 	pop	ar7
      000F93 E5 82            [12] 3479 	mov	a, dpl
      000F95 24 FF            [12] 3480 	add	a,#0xff
      000F97 92 00            [24] 3481 	mov	b0,c
      000F99 40 05            [24] 3482 	jc	00102$
                           000EE4  3483 	C$controller_8051.c$183$2_0$100 ==.
                                   3484 ;	/home/mahavigna/CI/controller_8051.c:183: return 0u;
      000F9B 75 82 00         [24] 3485 	mov	dpl, #0x00
      000F9E 80 66            [24] 3486 	sjmp	00105$
      000FA0                       3487 00102$:
                           000EE9  3488 	C$controller_8051.c$186$1_0$99 ==.
                                   3489 ;	/home/mahavigna/CI/controller_8051.c:186: if (fan_speed >= 100.0f) {
      000FA0 C0 07            [24] 3490 	push	ar7
      000FA2 C0 06            [24] 3491 	push	ar6
      000FA4 C0 05            [24] 3492 	push	ar5
      000FA6 C0 04            [24] 3493 	push	ar4
      000FA8 E4               [12] 3494 	clr	a
      000FA9 C0 E0            [24] 3495 	push	acc
      000FAB C0 E0            [24] 3496 	push	acc
      000FAD 74 C8            [12] 3497 	mov	a,#0xc8
      000FAF C0 E0            [24] 3498 	push	acc
      000FB1 74 42            [12] 3499 	mov	a,#0x42
      000FB3 C0 E0            [24] 3500 	push	acc
      000FB5 8C 82            [24] 3501 	mov	dpl, r4
      000FB7 8D 83            [24] 3502 	mov	dph, r5
      000FB9 8E F0            [24] 3503 	mov	b, r6
      000FBB EF               [12] 3504 	mov	a, r7
      000FBC 12 11 6B         [24] 3505 	lcall	___fslt
      000FBF E5 81            [12] 3506 	mov	a,sp
      000FC1 24 FC            [12] 3507 	add	a,#0xfc
      000FC3 F5 81            [12] 3508 	mov	sp,a
      000FC5 D0 04            [24] 3509 	pop	ar4
      000FC7 D0 05            [24] 3510 	pop	ar5
      000FC9 D0 06            [24] 3511 	pop	ar6
      000FCB D0 07            [24] 3512 	pop	ar7
      000FCD E5 82            [12] 3513 	mov	a, dpl
      000FCF 24 FF            [12] 3514 	add	a,#0xff
      000FD1 92 00            [24] 3515 	mov	b0,c
      000FD3 40 05            [24] 3516 	jc	00104$
                           000F1E  3517 	C$controller_8051.c$187$2_0$101 ==.
                                   3518 ;	/home/mahavigna/CI/controller_8051.c:187: return 100u;
      000FD5 75 82 64         [24] 3519 	mov	dpl, #0x64
      000FD8 80 2C            [24] 3520 	sjmp	00105$
      000FDA                       3521 00104$:
                           000F23  3522 	C$controller_8051.c$192$1_0$99 ==.
                                   3523 ;	/home/mahavigna/CI/controller_8051.c:192: );
      000FDA E4               [12] 3524 	clr	a
      000FDB C0 E0            [24] 3525 	push	acc
      000FDD C0 E0            [24] 3526 	push	acc
      000FDF C0 E0            [24] 3527 	push	acc
      000FE1 74 3F            [12] 3528 	mov	a,#0x3f
      000FE3 C0 E0            [24] 3529 	push	acc
      000FE5 8C 82            [24] 3530 	mov	dpl, r4
      000FE7 8D 83            [24] 3531 	mov	dph, r5
      000FE9 8E F0            [24] 3532 	mov	b, r6
      000FEB EF               [12] 3533 	mov	a, r7
      000FEC 12 11 BD         [24] 3534 	lcall	___fsadd
      000FEF AC 82            [24] 3535 	mov	r4, dpl
      000FF1 AD 83            [24] 3536 	mov	r5, dph
      000FF3 AE F0            [24] 3537 	mov	r6, b
      000FF5 FF               [12] 3538 	mov	r7, a
      000FF6 E5 81            [12] 3539 	mov	a,sp
      000FF8 24 FC            [12] 3540 	add	a,#0xfc
      000FFA F5 81            [12] 3541 	mov	sp,a
      000FFC 8C 82            [24] 3542 	mov	dpl, r4
      000FFE 8D 83            [24] 3543 	mov	dph, r5
      001000 8E F0            [24] 3544 	mov	b, r6
      001002 EF               [12] 3545 	mov	a, r7
      001003 12 13 A7         [24] 3546 	lcall	___fs2uchar
      001006                       3547 00105$:
                           000F4F  3548 	C$controller_8051.c$193$1_0$99 ==.
                                   3549 ;	/home/mahavigna/CI/controller_8051.c:193: }
                           000F4F  3550 	C$controller_8051.c$193$1_0$99 ==.
                           000F4F  3551 	XFcontroller_8051$fan_speed_to_pwm$0$0 ==.
      001006 22               [24] 3552 	ret
                                   3553 ;------------------------------------------------------------
                                   3554 ;Allocation info for local variables in function 'main'
                                   3555 ;------------------------------------------------------------
                           000F50  3556 	G$main$0$0 ==.
                           000F50  3557 	C$controller_8051.c$210$1_0$103 ==.
                                   3558 ;	/home/mahavigna/CI/controller_8051.c:210: void main(void)
                                   3559 ;	-----------------------------------------
                                   3560 ;	 function main
                                   3561 ;	-----------------------------------------
      001007                       3562 _main:
                           000F50  3563 	C$controller_8051.c$218$1_0$103 ==.
                                   3564 ;	/home/mahavigna/CI/controller_8051.c:218: 42u;
      001007 75 08 2A         [24] 3565 	mov	_test_temperature,#0x2a
                           000F53  3566 	C$controller_8051.c$224$1_0$103 ==.
                                   3567 ;	/home/mahavigna/CI/controller_8051.c:224: 0x55u;
      00100A 75 80 55         [24] 3568 	mov	_P0,#0x55
                           000F56  3569 	C$controller_8051.c$227$1_0$103 ==.
                                   3570 ;	/home/mahavigna/CI/controller_8051.c:227: 0x00u;
      00100D 75 90 00         [24] 3571 	mov	_P1,#0x00
                           000F59  3572 	C$controller_8051.c$233$1_0$103 ==.
                                   3573 ;	/home/mahavigna/CI/controller_8051.c:233: test_temperature = P2;
      001010 85 A0 08         [24] 3574 	mov	_test_temperature,_P2
                           000F5C  3575 	C$controller_8051.c$238$2_0$103 ==.
                                   3576 ;	/home/mahavigna/CI/controller_8051.c:238: );
      001013 85 08 82         [24] 3577 	mov	dpl, _test_temperature
      001016 12 13 AF         [24] 3578 	lcall	___uchar2fs
      001019 12 0D F4         [24] 3579 	lcall	_calculate_fan_speed
      00101C 85 82 0A         [24] 3580 	mov	_test_fan_speed,dpl
      00101F 85 83 0B         [24] 3581 	mov	(_test_fan_speed + 1),dph
      001022 85 F0 0C         [24] 3582 	mov	(_test_fan_speed + 2),b
      001025 F5 0D            [12] 3583 	mov	(_test_fan_speed + 3),a
                           000F70  3584 	C$controller_8051.c$242$1_0$103 ==.
                                   3585 ;	/home/mahavigna/CI/controller_8051.c:242: test_fan_speed
      001027 85 0A 82         [24] 3586 	mov	dpl, _test_fan_speed
      00102A 85 0B 83         [24] 3587 	mov	dph, (_test_fan_speed + 1)
      00102D 85 0C F0         [24] 3588 	mov	b, (_test_fan_speed + 2)
      001030 E5 0D            [12] 3589 	mov	a, (_test_fan_speed + 3)
      001032 12 0F 65         [24] 3590 	lcall	_fan_speed_to_pwm
      001035 85 82 09         [24] 3591 	mov	_test_pwm,dpl
                           000F81  3592 	C$controller_8051.c$249$1_0$103 ==.
                                   3593 ;	/home/mahavigna/CI/controller_8051.c:249: test_pwm;
      001038 85 09 90         [24] 3594 	mov	_P1,_test_pwm
                           000F84  3595 	C$controller_8051.c$255$1_0$103 ==.
                                   3596 ;	/home/mahavigna/CI/controller_8051.c:255: 0xAAu;
      00103B 75 80 AA         [24] 3597 	mov	_P0,#0xaa
      00103E                       3598 00103$:
      00103E 80 FE            [24] 3599 	sjmp	00103$
                           000F89  3600 	C$controller_8051.c$260$2_0$103 ==.
                                   3601 ;	/home/mahavigna/CI/controller_8051.c:260: }
                           000F89  3602 	C$controller_8051.c$260$2_0$103 ==.
                           000F89  3603 	XG$main$0$0 ==.
      001040 22               [24] 3604 	ret
                                   3605 	.area CSEG    (CODE)
                                   3606 	.area CONST   (CODE)
                                   3607 	.area CONST   (CODE)
                           000000  3608 Fcontroller_8051$hedges$0_0$0 == .
      00144D                       3609 _hedges:
      00144D 01                    3610 	.db #0x01	; 1
      00144E 02                    3611 	.db #0x02	; 2
      00144F 03                    3612 	.db #0x03	; 3
                                   3613 	.area CSEG    (CODE)
                                   3614 	.area XINIT   (CODE)
                                   3615 	.area CABS    (ABS,CODE)
