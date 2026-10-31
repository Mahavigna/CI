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
                                    140 	.globl _fuzzy_triangle
                                    141 	.globl _fuzzy_trapezoid
                                    142 	.globl _fuzzy_function_array
                                    143 	.globl _fuzzy_rules_add
                                    144 	.globl _fuzzy_rules_defuzzify_method
                                    145 	.globl _fuzzy_rules_defuzzify
                                    146 	.globl _fuzzy_rules_cog
                                    147 ;--------------------------------------------------------
                                    148 ; special function registers
                                    149 ;--------------------------------------------------------
                                    150 	.area RSEG    (ABS,DATA)
      000000                        151 	.org 0x0000
                           000080   152 G$P0$0_0$0 == 0x0080
                           000080   153 _P0	=	0x0080
                           000081   154 G$SP$0_0$0 == 0x0081
                           000081   155 _SP	=	0x0081
                           000082   156 G$DPL$0_0$0 == 0x0082
                           000082   157 _DPL	=	0x0082
                           000083   158 G$DPH$0_0$0 == 0x0083
                           000083   159 _DPH	=	0x0083
                           000087   160 G$PCON$0_0$0 == 0x0087
                           000087   161 _PCON	=	0x0087
                           000088   162 G$TCON$0_0$0 == 0x0088
                           000088   163 _TCON	=	0x0088
                           000089   164 G$TMOD$0_0$0 == 0x0089
                           000089   165 _TMOD	=	0x0089
                           00008A   166 G$TL0$0_0$0 == 0x008a
                           00008A   167 _TL0	=	0x008a
                           00008B   168 G$TL1$0_0$0 == 0x008b
                           00008B   169 _TL1	=	0x008b
                           00008C   170 G$TH0$0_0$0 == 0x008c
                           00008C   171 _TH0	=	0x008c
                           00008D   172 G$TH1$0_0$0 == 0x008d
                           00008D   173 _TH1	=	0x008d
                           000090   174 G$P1$0_0$0 == 0x0090
                           000090   175 _P1	=	0x0090
                           000098   176 G$SCON$0_0$0 == 0x0098
                           000098   177 _SCON	=	0x0098
                           000099   178 G$SBUF$0_0$0 == 0x0099
                           000099   179 _SBUF	=	0x0099
                           0000A0   180 G$P2$0_0$0 == 0x00a0
                           0000A0   181 _P2	=	0x00a0
                           0000A8   182 G$IE$0_0$0 == 0x00a8
                           0000A8   183 _IE	=	0x00a8
                           0000B0   184 G$P3$0_0$0 == 0x00b0
                           0000B0   185 _P3	=	0x00b0
                           0000B8   186 G$IP$0_0$0 == 0x00b8
                           0000B8   187 _IP	=	0x00b8
                           0000D0   188 G$PSW$0_0$0 == 0x00d0
                           0000D0   189 _PSW	=	0x00d0
                           0000E0   190 G$ACC$0_0$0 == 0x00e0
                           0000E0   191 _ACC	=	0x00e0
                           0000F0   192 G$B$0_0$0 == 0x00f0
                           0000F0   193 _B	=	0x00f0
                           0000C8   194 G$T2CON$0_0$0 == 0x00c8
                           0000C8   195 _T2CON	=	0x00c8
                           0000CA   196 G$RCAP2L$0_0$0 == 0x00ca
                           0000CA   197 _RCAP2L	=	0x00ca
                           0000CB   198 G$RCAP2H$0_0$0 == 0x00cb
                           0000CB   199 _RCAP2H	=	0x00cb
                           0000CC   200 G$TL2$0_0$0 == 0x00cc
                           0000CC   201 _TL2	=	0x00cc
                           0000CD   202 G$TH2$0_0$0 == 0x00cd
                           0000CD   203 _TH2	=	0x00cd
                                    204 ;--------------------------------------------------------
                                    205 ; special function bits
                                    206 ;--------------------------------------------------------
                                    207 	.area RSEG    (ABS,DATA)
      000000                        208 	.org 0x0000
                           000080   209 G$P0_0$0_0$0 == 0x0080
                           000080   210 _P0_0	=	0x0080
                           000081   211 G$P0_1$0_0$0 == 0x0081
                           000081   212 _P0_1	=	0x0081
                           000082   213 G$P0_2$0_0$0 == 0x0082
                           000082   214 _P0_2	=	0x0082
                           000083   215 G$P0_3$0_0$0 == 0x0083
                           000083   216 _P0_3	=	0x0083
                           000084   217 G$P0_4$0_0$0 == 0x0084
                           000084   218 _P0_4	=	0x0084
                           000085   219 G$P0_5$0_0$0 == 0x0085
                           000085   220 _P0_5	=	0x0085
                           000086   221 G$P0_6$0_0$0 == 0x0086
                           000086   222 _P0_6	=	0x0086
                           000087   223 G$P0_7$0_0$0 == 0x0087
                           000087   224 _P0_7	=	0x0087
                           000088   225 G$IT0$0_0$0 == 0x0088
                           000088   226 _IT0	=	0x0088
                           000089   227 G$IE0$0_0$0 == 0x0089
                           000089   228 _IE0	=	0x0089
                           00008A   229 G$IT1$0_0$0 == 0x008a
                           00008A   230 _IT1	=	0x008a
                           00008B   231 G$IE1$0_0$0 == 0x008b
                           00008B   232 _IE1	=	0x008b
                           00008C   233 G$TR0$0_0$0 == 0x008c
                           00008C   234 _TR0	=	0x008c
                           00008D   235 G$TF0$0_0$0 == 0x008d
                           00008D   236 _TF0	=	0x008d
                           00008E   237 G$TR1$0_0$0 == 0x008e
                           00008E   238 _TR1	=	0x008e
                           00008F   239 G$TF1$0_0$0 == 0x008f
                           00008F   240 _TF1	=	0x008f
                           000090   241 G$P1_0$0_0$0 == 0x0090
                           000090   242 _P1_0	=	0x0090
                           000091   243 G$P1_1$0_0$0 == 0x0091
                           000091   244 _P1_1	=	0x0091
                           000092   245 G$P1_2$0_0$0 == 0x0092
                           000092   246 _P1_2	=	0x0092
                           000093   247 G$P1_3$0_0$0 == 0x0093
                           000093   248 _P1_3	=	0x0093
                           000094   249 G$P1_4$0_0$0 == 0x0094
                           000094   250 _P1_4	=	0x0094
                           000095   251 G$P1_5$0_0$0 == 0x0095
                           000095   252 _P1_5	=	0x0095
                           000096   253 G$P1_6$0_0$0 == 0x0096
                           000096   254 _P1_6	=	0x0096
                           000097   255 G$P1_7$0_0$0 == 0x0097
                           000097   256 _P1_7	=	0x0097
                           000098   257 G$RI$0_0$0 == 0x0098
                           000098   258 _RI	=	0x0098
                           000099   259 G$TI$0_0$0 == 0x0099
                           000099   260 _TI	=	0x0099
                           00009A   261 G$RB8$0_0$0 == 0x009a
                           00009A   262 _RB8	=	0x009a
                           00009B   263 G$TB8$0_0$0 == 0x009b
                           00009B   264 _TB8	=	0x009b
                           00009C   265 G$REN$0_0$0 == 0x009c
                           00009C   266 _REN	=	0x009c
                           00009D   267 G$SM2$0_0$0 == 0x009d
                           00009D   268 _SM2	=	0x009d
                           00009E   269 G$SM1$0_0$0 == 0x009e
                           00009E   270 _SM1	=	0x009e
                           00009F   271 G$SM0$0_0$0 == 0x009f
                           00009F   272 _SM0	=	0x009f
                           0000A0   273 G$P2_0$0_0$0 == 0x00a0
                           0000A0   274 _P2_0	=	0x00a0
                           0000A1   275 G$P2_1$0_0$0 == 0x00a1
                           0000A1   276 _P2_1	=	0x00a1
                           0000A2   277 G$P2_2$0_0$0 == 0x00a2
                           0000A2   278 _P2_2	=	0x00a2
                           0000A3   279 G$P2_3$0_0$0 == 0x00a3
                           0000A3   280 _P2_3	=	0x00a3
                           0000A4   281 G$P2_4$0_0$0 == 0x00a4
                           0000A4   282 _P2_4	=	0x00a4
                           0000A5   283 G$P2_5$0_0$0 == 0x00a5
                           0000A5   284 _P2_5	=	0x00a5
                           0000A6   285 G$P2_6$0_0$0 == 0x00a6
                           0000A6   286 _P2_6	=	0x00a6
                           0000A7   287 G$P2_7$0_0$0 == 0x00a7
                           0000A7   288 _P2_7	=	0x00a7
                           0000A8   289 G$EX0$0_0$0 == 0x00a8
                           0000A8   290 _EX0	=	0x00a8
                           0000A9   291 G$ET0$0_0$0 == 0x00a9
                           0000A9   292 _ET0	=	0x00a9
                           0000AA   293 G$EX1$0_0$0 == 0x00aa
                           0000AA   294 _EX1	=	0x00aa
                           0000AB   295 G$ET1$0_0$0 == 0x00ab
                           0000AB   296 _ET1	=	0x00ab
                           0000AC   297 G$ES$0_0$0 == 0x00ac
                           0000AC   298 _ES	=	0x00ac
                           0000AF   299 G$EA$0_0$0 == 0x00af
                           0000AF   300 _EA	=	0x00af
                           0000B0   301 G$P3_0$0_0$0 == 0x00b0
                           0000B0   302 _P3_0	=	0x00b0
                           0000B1   303 G$P3_1$0_0$0 == 0x00b1
                           0000B1   304 _P3_1	=	0x00b1
                           0000B2   305 G$P3_2$0_0$0 == 0x00b2
                           0000B2   306 _P3_2	=	0x00b2
                           0000B3   307 G$P3_3$0_0$0 == 0x00b3
                           0000B3   308 _P3_3	=	0x00b3
                           0000B4   309 G$P3_4$0_0$0 == 0x00b4
                           0000B4   310 _P3_4	=	0x00b4
                           0000B5   311 G$P3_5$0_0$0 == 0x00b5
                           0000B5   312 _P3_5	=	0x00b5
                           0000B6   313 G$P3_6$0_0$0 == 0x00b6
                           0000B6   314 _P3_6	=	0x00b6
                           0000B7   315 G$P3_7$0_0$0 == 0x00b7
                           0000B7   316 _P3_7	=	0x00b7
                           0000B0   317 G$RXD$0_0$0 == 0x00b0
                           0000B0   318 _RXD	=	0x00b0
                           0000B1   319 G$TXD$0_0$0 == 0x00b1
                           0000B1   320 _TXD	=	0x00b1
                           0000B2   321 G$INT0$0_0$0 == 0x00b2
                           0000B2   322 _INT0	=	0x00b2
                           0000B3   323 G$INT1$0_0$0 == 0x00b3
                           0000B3   324 _INT1	=	0x00b3
                           0000B4   325 G$T0$0_0$0 == 0x00b4
                           0000B4   326 _T0	=	0x00b4
                           0000B5   327 G$T1$0_0$0 == 0x00b5
                           0000B5   328 _T1	=	0x00b5
                           0000B6   329 G$WR$0_0$0 == 0x00b6
                           0000B6   330 _WR	=	0x00b6
                           0000B7   331 G$RD$0_0$0 == 0x00b7
                           0000B7   332 _RD	=	0x00b7
                           0000B8   333 G$PX0$0_0$0 == 0x00b8
                           0000B8   334 _PX0	=	0x00b8
                           0000B9   335 G$PT0$0_0$0 == 0x00b9
                           0000B9   336 _PT0	=	0x00b9
                           0000BA   337 G$PX1$0_0$0 == 0x00ba
                           0000BA   338 _PX1	=	0x00ba
                           0000BB   339 G$PT1$0_0$0 == 0x00bb
                           0000BB   340 _PT1	=	0x00bb
                           0000BC   341 G$PS$0_0$0 == 0x00bc
                           0000BC   342 _PS	=	0x00bc
                           0000D0   343 G$P$0_0$0 == 0x00d0
                           0000D0   344 _P	=	0x00d0
                           0000D1   345 G$F1$0_0$0 == 0x00d1
                           0000D1   346 _F1	=	0x00d1
                           0000D2   347 G$OV$0_0$0 == 0x00d2
                           0000D2   348 _OV	=	0x00d2
                           0000D3   349 G$RS0$0_0$0 == 0x00d3
                           0000D3   350 _RS0	=	0x00d3
                           0000D4   351 G$RS1$0_0$0 == 0x00d4
                           0000D4   352 _RS1	=	0x00d4
                           0000D5   353 G$F0$0_0$0 == 0x00d5
                           0000D5   354 _F0	=	0x00d5
                           0000D6   355 G$AC$0_0$0 == 0x00d6
                           0000D6   356 _AC	=	0x00d6
                           0000D7   357 G$CY$0_0$0 == 0x00d7
                           0000D7   358 _CY	=	0x00d7
                           0000AD   359 G$ET2$0_0$0 == 0x00ad
                           0000AD   360 _ET2	=	0x00ad
                           0000BD   361 G$PT2$0_0$0 == 0x00bd
                           0000BD   362 _PT2	=	0x00bd
                           0000C8   363 G$T2CON_0$0_0$0 == 0x00c8
                           0000C8   364 _T2CON_0	=	0x00c8
                           0000C9   365 G$T2CON_1$0_0$0 == 0x00c9
                           0000C9   366 _T2CON_1	=	0x00c9
                           0000CA   367 G$T2CON_2$0_0$0 == 0x00ca
                           0000CA   368 _T2CON_2	=	0x00ca
                           0000CB   369 G$T2CON_3$0_0$0 == 0x00cb
                           0000CB   370 _T2CON_3	=	0x00cb
                           0000CC   371 G$T2CON_4$0_0$0 == 0x00cc
                           0000CC   372 _T2CON_4	=	0x00cc
                           0000CD   373 G$T2CON_5$0_0$0 == 0x00cd
                           0000CD   374 _T2CON_5	=	0x00cd
                           0000CE   375 G$T2CON_6$0_0$0 == 0x00ce
                           0000CE   376 _T2CON_6	=	0x00ce
                           0000CF   377 G$T2CON_7$0_0$0 == 0x00cf
                           0000CF   378 _T2CON_7	=	0x00cf
                           0000C8   379 G$CP_RL2$0_0$0 == 0x00c8
                           0000C8   380 _CP_RL2	=	0x00c8
                           0000C9   381 G$C_T2$0_0$0 == 0x00c9
                           0000C9   382 _C_T2	=	0x00c9
                           0000CA   383 G$TR2$0_0$0 == 0x00ca
                           0000CA   384 _TR2	=	0x00ca
                           0000CB   385 G$EXEN2$0_0$0 == 0x00cb
                           0000CB   386 _EXEN2	=	0x00cb
                           0000CC   387 G$TCLK$0_0$0 == 0x00cc
                           0000CC   388 _TCLK	=	0x00cc
                           0000CD   389 G$RCLK$0_0$0 == 0x00cd
                           0000CD   390 _RCLK	=	0x00cd
                           0000CE   391 G$EXF2$0_0$0 == 0x00ce
                           0000CE   392 _EXF2	=	0x00ce
                           0000CF   393 G$TF2$0_0$0 == 0x00cf
                           0000CF   394 _TF2	=	0x00cf
                                    395 ;--------------------------------------------------------
                                    396 ; overlayable register banks
                                    397 ;--------------------------------------------------------
                                    398 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        399 	.ds 8
                                    400 ;--------------------------------------------------------
                                    401 ; overlayable bit register bank
                                    402 ;--------------------------------------------------------
                                    403 	.area BIT_BANK	(REL,OVR,DATA)
      000020                        404 bits:
      000020                        405 	.ds 1
                           008000   406 	b0 = bits[0]
                           008100   407 	b1 = bits[1]
                           008200   408 	b2 = bits[2]
                           008300   409 	b3 = bits[3]
                           008400   410 	b4 = bits[4]
                           008500   411 	b5 = bits[5]
                           008600   412 	b6 = bits[6]
                           008700   413 	b7 = bits[7]
                                    414 ;--------------------------------------------------------
                                    415 ; internal ram data
                                    416 ;--------------------------------------------------------
                                    417 	.area DSEG    (DATA)
                           000000   418 Fcontroller_8051$fuzzy_values_buffer$0_0$0==.
      000021                        419 _fuzzy_values_buffer:
      000021                        420 	.ds 64
                           000040   421 G$test_temperature$0_0$0==.
      000061                        422 _test_temperature::
      000061                        423 	.ds 1
                           000041   424 G$test_pwm$0_0$0==.
      000062                        425 _test_pwm::
      000062                        426 	.ds 1
                           000042   427 G$test_fan_speed$0_0$0==.
      000063                        428 _test_fan_speed::
      000063                        429 	.ds 4
                                    430 ;--------------------------------------------------------
                                    431 ; overlayable items in internal ram
                                    432 ;--------------------------------------------------------
                                    433 ;--------------------------------------------------------
                                    434 ; Stack segment in internal ram
                                    435 ;--------------------------------------------------------
                                    436 	.area SSEG
      000067                        437 __start__stack:
      000067                        438 	.ds	1
                                    439 
                                    440 ;--------------------------------------------------------
                                    441 ; indirectly addressable internal ram data
                                    442 ;--------------------------------------------------------
                                    443 	.area ISEG    (DATA)
                                    444 ;--------------------------------------------------------
                                    445 ; absolute internal ram data
                                    446 ;--------------------------------------------------------
                                    447 	.area IABS    (ABS,DATA)
                                    448 	.area IABS    (ABS,DATA)
                                    449 ;--------------------------------------------------------
                                    450 ; bit data
                                    451 ;--------------------------------------------------------
                                    452 	.area BSEG    (BIT)
                                    453 ;--------------------------------------------------------
                                    454 ; paged external ram data
                                    455 ;--------------------------------------------------------
                                    456 	.area PSEG    (PAG,XDATA)
                                    457 ;--------------------------------------------------------
                                    458 ; uninitialized external ram data
                                    459 ;--------------------------------------------------------
                                    460 	.area XSEG    (XDATA)
                                    461 ;--------------------------------------------------------
                                    462 ; absolute external ram data
                                    463 ;--------------------------------------------------------
                                    464 	.area XABS    (ABS,XDATA)
                                    465 ;--------------------------------------------------------
                                    466 ; initialized external ram data
                                    467 ;--------------------------------------------------------
                                    468 	.area XISEG   (XDATA)
                                    469 	.area HOME    (CODE)
                                    470 	.area GSINIT0 (CODE)
                                    471 	.area GSINIT1 (CODE)
                                    472 	.area GSINIT2 (CODE)
                                    473 	.area GSINIT3 (CODE)
                                    474 	.area GSINIT4 (CODE)
                                    475 	.area GSINIT5 (CODE)
                                    476 	.area GSINIT  (CODE)
                                    477 	.area GSFINAL (CODE)
                                    478 	.area CSEG    (CODE)
                                    479 ;--------------------------------------------------------
                                    480 ; interrupt vector
                                    481 ;--------------------------------------------------------
                                    482 	.area HOME    (CODE)
      000000                        483 __interrupt_vect:
      000000 02 00 4C         [24]  484 	ljmp	__sdcc_gsinit_startup
                                    485 ; restartable atomic support routines
      000003                        486 	.ds	5
      000008                        487 sdcc_atomic_exchange_rollback_start::
      000008 00               [12]  488 	nop
      000009 00               [12]  489 	nop
      00000A                        490 sdcc_atomic_exchange_pdata_impl:
      00000A E2               [24]  491 	movx	a, @r0
      00000B FB               [12]  492 	mov	r3, a
      00000C EA               [12]  493 	mov	a, r2
      00000D F2               [24]  494 	movx	@r0, a
      00000E 80 2C            [24]  495 	sjmp	sdcc_atomic_exchange_exit
      000010 00               [12]  496 	nop
      000011 00               [12]  497 	nop
      000012                        498 sdcc_atomic_exchange_xdata_impl:
      000012 E0               [24]  499 	movx	a, @dptr
      000013 FB               [12]  500 	mov	r3, a
      000014 EA               [12]  501 	mov	a, r2
      000015 F0               [24]  502 	movx	@dptr, a
      000016 80 24            [24]  503 	sjmp	sdcc_atomic_exchange_exit
      000018                        504 sdcc_atomic_compare_exchange_idata_impl:
      000018 E6               [12]  505 	mov	a, @r0
      000019 B5 02 02         [24]  506 	cjne	a, ar2, .+#5
      00001C EB               [12]  507 	mov	a, r3
      00001D F6               [12]  508 	mov	@r0, a
      00001E 22               [24]  509 	ret
      00001F 00               [12]  510 	nop
      000020                        511 sdcc_atomic_compare_exchange_pdata_impl:
      000020 E2               [24]  512 	movx	a, @r0
      000021 B5 02 02         [24]  513 	cjne	a, ar2, .+#5
      000024 EB               [12]  514 	mov	a, r3
      000025 F2               [24]  515 	movx	@r0, a
      000026 22               [24]  516 	ret
      000027 00               [12]  517 	nop
      000028                        518 sdcc_atomic_compare_exchange_xdata_impl:
      000028 E0               [24]  519 	movx	a, @dptr
      000029 B5 02 02         [24]  520 	cjne	a, ar2, .+#5
      00002C EB               [12]  521 	mov	a, r3
      00002D F0               [24]  522 	movx	@dptr, a
      00002E 22               [24]  523 	ret
      00002F                        524 sdcc_atomic_exchange_rollback_end::
                                    525 
      00002F                        526 sdcc_atomic_exchange_gptr_impl::
      00002F 30 F6 E0         [24]  527 	jnb	b.6, sdcc_atomic_exchange_xdata_impl
      000032 A8 82            [24]  528 	mov	r0, dpl
      000034 20 F5 D3         [24]  529 	jb	b.5, sdcc_atomic_exchange_pdata_impl
      000037                        530 sdcc_atomic_exchange_idata_impl:
      000037 EA               [12]  531 	mov	a, r2
      000038 C6               [12]  532 	xch	a, @r0
      000039 F5 82            [12]  533 	mov	dpl, a
      00003B 22               [24]  534 	ret
      00003C                        535 sdcc_atomic_exchange_exit:
      00003C 8B 82            [24]  536 	mov	dpl, r3
      00003E 22               [24]  537 	ret
      00003F                        538 sdcc_atomic_compare_exchange_gptr_impl::
      00003F 30 F6 E6         [24]  539 	jnb	b.6, sdcc_atomic_compare_exchange_xdata_impl
      000042 A8 82            [24]  540 	mov	r0, dpl
      000044 20 F5 D9         [24]  541 	jb	b.5, sdcc_atomic_compare_exchange_pdata_impl
      000047 80 CF            [24]  542 	sjmp	sdcc_atomic_compare_exchange_idata_impl
                                    543 ;--------------------------------------------------------
                                    544 ; global & static initialisations
                                    545 ;--------------------------------------------------------
                                    546 	.area HOME    (CODE)
                                    547 	.area GSINIT  (CODE)
                                    548 	.area GSFINAL (CODE)
                                    549 	.area GSINIT  (CODE)
                                    550 	.globl __sdcc_gsinit_startup
                                    551 	.globl __sdcc_program_startup
                                    552 	.globl __start__stack
                                    553 	.globl __mcs51_genXINIT
                                    554 	.globl __mcs51_genXRAMCLEAR
                                    555 	.globl __mcs51_genRAMCLEAR
                           000000   556 	C$controller_8051.c$25$2_0$125 ==.
                                    557 ;	../../controller_8051.c:25: volatile unsigned char test_temperature = 0u;
      0000A5 75 61 00         [24]  558 	mov	_test_temperature,#0x00
                           000003   559 	C$controller_8051.c$26$2_0$125 ==.
                                    560 ;	../../controller_8051.c:26: volatile unsigned char test_pwm = 0u;
      0000A8 75 62 00         [24]  561 	mov	_test_pwm,#0x00
                           000006   562 	C$controller_8051.c$27$2_0$125 ==.
                                    563 ;	../../controller_8051.c:27: volatile float test_fan_speed = 0.0f;
      0000AB E4               [12]  564 	clr	a
      0000AC F5 63            [12]  565 	mov	_test_fan_speed,a
      0000AE F5 64            [12]  566 	mov	(_test_fan_speed + 1),a
      0000B0 F5 65            [12]  567 	mov	(_test_fan_speed + 2),a
      0000B2 F5 66            [12]  568 	mov	(_test_fan_speed + 3),a
                                    569 	.area GSFINAL (CODE)
      0000B4 02 00 49         [24]  570 	ljmp	__sdcc_program_startup
                                    571 ;--------------------------------------------------------
                                    572 ; Home
                                    573 ;--------------------------------------------------------
                                    574 	.area HOME    (CODE)
                                    575 	.area HOME    (CODE)
      000049                        576 __sdcc_program_startup:
      000049 02 25 F3         [24]  577 	ljmp	_main
                                    578 ;	return from main will return to caller
                                    579 ;--------------------------------------------------------
                                    580 ; code
                                    581 ;--------------------------------------------------------
                                    582 	.area CSEG    (CODE)
                                    583 ;------------------------------------------------------------
                                    584 ;Allocation info for local variables in function 'fuzzy_values_initialize'
                                    585 ;------------------------------------------------------------
                                    586 ;index         Allocated to registers r6 r7 
                                    587 ;------------------------------------------------------------
                           000000   588 	Fcontroller_8051$fuzzy_values_initialize$0$0 ==.
                           000000   589 	C$fuzzy.h$116$0_0$3 ==.
                                    590 ;	../../fuzzy.h:116: static float *fuzzy_values_initialize(void)
                                    591 ;	-----------------------------------------
                                    592 ;	 function fuzzy_values_initialize
                                    593 ;	-----------------------------------------
      0000B7                        594 _fuzzy_values_initialize:
                           000007   595 	ar7 = 0x07
                           000006   596 	ar6 = 0x06
                           000005   597 	ar5 = 0x05
                           000004   598 	ar4 = 0x04
                           000003   599 	ar3 = 0x03
                           000002   600 	ar2 = 0x02
                           000001   601 	ar1 = 0x01
                           000000   602 	ar0 = 0x00
                           000000   603 	C$fuzzy.h$121$3_0$5 ==.
                                    604 ;	../../fuzzy.h:121: index = 0u;
      0000B7 7E 00            [12]  605 	mov	r6,#0x00
      0000B9 7F 00            [12]  606 	mov	r7,#0x00
      0000BB                        607 00102$:
                           000004   608 	C$fuzzy.h$125$3_0$5 ==.
                                    609 ;	../../fuzzy.h:125: fuzzy_values_buffer[index] = 0.0f;
      0000BB EE               [12]  610 	mov	a,r6
      0000BC 2E               [12]  611 	add	a,r6
      0000BD FC               [12]  612 	mov	r4,a
      0000BE EF               [12]  613 	mov	a,r7
      0000BF 33               [12]  614 	rlc	a
      0000C0 FD               [12]  615 	mov	r5,a
      0000C1 EC               [12]  616 	mov	a,r4
      0000C2 2C               [12]  617 	add	a,r4
      0000C3 FC               [12]  618 	mov	r4,a
      0000C4 ED               [12]  619 	mov	a,r5
      0000C5 33               [12]  620 	rlc	a
      0000C6 EC               [12]  621 	mov	a,r4
      0000C7 24 21            [12]  622 	add	a, #_fuzzy_values_buffer
      0000C9 F8               [12]  623 	mov	r0,a
      0000CA 76 00            [12]  624 	mov	@r0,#0x00
      0000CC 08               [12]  625 	inc	r0
      0000CD 76 00            [12]  626 	mov	@r0,#0x00
      0000CF 08               [12]  627 	inc	r0
      0000D0 76 00            [12]  628 	mov	@r0,#0x00
      0000D2 08               [12]  629 	inc	r0
      0000D3 76 00            [12]  630 	mov	@r0,#0x00
                           00001E   631 	C$fuzzy.h$123$2_0$4 ==.
                                    632 ;	../../fuzzy.h:123: index++
      0000D5 0E               [12]  633 	inc	r6
      0000D6 BE 00 01         [24]  634 	cjne	r6,#0x00,00119$
      0000D9 0F               [12]  635 	inc	r7
      0000DA                        636 00119$:
                           000023   637 	C$fuzzy.h$122$2_0$4 ==.
                                    638 ;	../../fuzzy.h:122: index < FUZZY_MAX_VALUES;
      0000DA C3               [12]  639 	clr	c
      0000DB EE               [12]  640 	mov	a,r6
      0000DC 94 10            [12]  641 	subb	a,#0x10
      0000DE EF               [12]  642 	mov	a,r7
      0000DF 94 00            [12]  643 	subb	a,#0x00
      0000E1 40 D8            [24]  644 	jc	00102$
                           00002C   645 	C$fuzzy.h$128$1_0$3 ==.
                                    646 ;	../../fuzzy.h:128: return fuzzy_values_buffer;
      0000E3 90 00 21         [24]  647 	mov	dptr,#_fuzzy_values_buffer
      0000E6 75 F0 40         [24]  648 	mov	b, #0x40
                           000032   649 	C$fuzzy.h$129$1_0$3 ==.
                                    650 ;	../../fuzzy.h:129: }
                           000032   651 	C$fuzzy.h$129$1_0$3 ==.
                           000032   652 	XFcontroller_8051$fuzzy_values_initialize$0$0 ==.
      0000E9 22               [24]  653 	ret
                                    654 ;------------------------------------------------------------
                                    655 ;Allocation info for local variables in function 'fuzzy_clamp'
                                    656 ;------------------------------------------------------------
                                    657 ;value         Allocated to registers r4 r5 r6 r7 
                                    658 ;------------------------------------------------------------
                           000033   659 	Fcontroller_8051$fuzzy_clamp$0$0 ==.
                           000033   660 	C$fuzzy.h$847$1_0$21 ==.
                                    661 ;	../../fuzzy.h:847: static float fuzzy_clamp(float value)
                                    662 ;	-----------------------------------------
                                    663 ;	 function fuzzy_clamp
                                    664 ;	-----------------------------------------
      0000EA                        665 _fuzzy_clamp:
      0000EA AC 82            [24]  666 	mov	r4,dpl
      0000EC AD 83            [24]  667 	mov	r5,dph
      0000EE AE F0            [24]  668 	mov	r6,b
      0000F0 FF               [12]  669 	mov	r7,a
                           00003A   670 	C$fuzzy.h$849$1_0$21 ==.
                                    671 ;	../../fuzzy.h:849: if (value < LEVEL_LO) {
      0000F1 C0 07            [24]  672 	push	ar7
      0000F3 C0 06            [24]  673 	push	ar6
      0000F5 C0 05            [24]  674 	push	ar5
      0000F7 C0 04            [24]  675 	push	ar4
      0000F9 E4               [12]  676 	clr	a
      0000FA C0 E0            [24]  677 	push	acc
      0000FC C0 E0            [24]  678 	push	acc
      0000FE C0 E0            [24]  679 	push	acc
      000100 C0 E0            [24]  680 	push	acc
      000102 8C 82            [24]  681 	mov	dpl, r4
      000104 8D 83            [24]  682 	mov	dph, r5
      000106 8E F0            [24]  683 	mov	b, r6
      000108 EF               [12]  684 	mov	a, r7
      000109 12 27 68         [24]  685 	lcall	___fslt
      00010C AB 82            [24]  686 	mov	r3, dpl
      00010E E5 81            [12]  687 	mov	a,sp
      000110 24 FC            [12]  688 	add	a,#0xfc
      000112 F5 81            [12]  689 	mov	sp,a
      000114 D0 04            [24]  690 	pop	ar4
      000116 D0 05            [24]  691 	pop	ar5
      000118 D0 06            [24]  692 	pop	ar6
      00011A D0 07            [24]  693 	pop	ar7
      00011C EB               [12]  694 	mov	a,r3
      00011D 60 08            [24]  695 	jz	00102$
                           000068   696 	C$fuzzy.h$850$2_0$22 ==.
                                    697 ;	../../fuzzy.h:850: return LEVEL_LO;
      00011F 90 00 00         [24]  698 	mov	dptr,#0x0000
      000122 E4               [12]  699 	clr	a
      000123 F5 F0            [12]  700 	mov	b,a
      000125 80 3F            [24]  701 	sjmp	00105$
      000127                        702 00102$:
                           000070   703 	C$fuzzy.h$853$1_0$21 ==.
                                    704 ;	../../fuzzy.h:853: if (value > LEVEL_HI) {
      000127 C0 07            [24]  705 	push	ar7
      000129 C0 06            [24]  706 	push	ar6
      00012B C0 05            [24]  707 	push	ar5
      00012D C0 04            [24]  708 	push	ar4
      00012F C0 04            [24]  709 	push	ar4
      000131 C0 05            [24]  710 	push	ar5
      000133 C0 06            [24]  711 	push	ar6
      000135 C0 07            [24]  712 	push	ar7
      000137 90 00 00         [24]  713 	mov	dptr,#0x0000
      00013A 75 F0 80         [24]  714 	mov	b, #0x80
      00013D 74 3F            [12]  715 	mov	a, #0x3f
      00013F 12 27 68         [24]  716 	lcall	___fslt
      000142 AB 82            [24]  717 	mov	r3, dpl
      000144 E5 81            [12]  718 	mov	a,sp
      000146 24 FC            [12]  719 	add	a,#0xfc
      000148 F5 81            [12]  720 	mov	sp,a
      00014A D0 04            [24]  721 	pop	ar4
      00014C D0 05            [24]  722 	pop	ar5
      00014E D0 06            [24]  723 	pop	ar6
      000150 D0 07            [24]  724 	pop	ar7
      000152 EB               [12]  725 	mov	a,r3
      000153 60 0A            [24]  726 	jz	00104$
                           00009E   727 	C$fuzzy.h$854$2_0$23 ==.
                                    728 ;	../../fuzzy.h:854: return LEVEL_HI;
      000155 90 00 00         [24]  729 	mov	dptr,#0x0000
      000158 75 F0 80         [24]  730 	mov	b, #0x80
      00015B 74 3F            [12]  731 	mov	a, #0x3f
      00015D 80 07            [24]  732 	sjmp	00105$
      00015F                        733 00104$:
                           0000A8   734 	C$fuzzy.h$857$1_0$21 ==.
                                    735 ;	../../fuzzy.h:857: return value;
      00015F 8C 82            [24]  736 	mov	dpl, r4
      000161 8D 83            [24]  737 	mov	dph, r5
      000163 8E F0            [24]  738 	mov	b, r6
      000165 EF               [12]  739 	mov	a, r7
      000166                        740 00105$:
                           0000AF   741 	C$fuzzy.h$858$1_0$21 ==.
                                    742 ;	../../fuzzy.h:858: }
                           0000AF   743 	C$fuzzy.h$858$1_0$21 ==.
                           0000AF   744 	XFcontroller_8051$fuzzy_clamp$0$0 ==.
      000166 22               [24]  745 	ret
                                    746 ;------------------------------------------------------------
                                    747 ;Allocation info for local variables in function 'fuzzy_not'
                                    748 ;------------------------------------------------------------
                                    749 ;membership    Allocated to registers r4 r5 r6 r7 
                                    750 ;------------------------------------------------------------
                           0000B0   751 	G$fuzzy_not$0$0 ==.
                           0000B0   752 	C$fuzzy.h$863$1_0$25 ==.
                                    753 ;	../../fuzzy.h:863: float fuzzy_not(
                                    754 ;	-----------------------------------------
                                    755 ;	 function fuzzy_not
                                    756 ;	-----------------------------------------
      000167                        757 _fuzzy_not:
                           0000B0   758 	C$fuzzy.h$868$1_0$25 ==.
                                    759 ;	../../fuzzy.h:868: fuzzy_clamp( membership
      000167 12 00 EA         [24]  760 	lcall	_fuzzy_clamp
      00016A AC 82            [24]  761 	mov	r4, dpl
      00016C AD 83            [24]  762 	mov	r5, dph
      00016E AE F0            [24]  763 	mov	r6, b
      000170 FF               [12]  764 	mov	r7, a
      000171 C0 04            [24]  765 	push	ar4
      000173 C0 05            [24]  766 	push	ar5
      000175 C0 06            [24]  767 	push	ar6
      000177 C0 07            [24]  768 	push	ar7
      000179 90 00 00         [24]  769 	mov	dptr,#0x0000
      00017C 75 F0 80         [24]  770 	mov	b, #0x80
      00017F 74 3F            [12]  771 	mov	a, #0x3f
      000181 12 26 2D         [24]  772 	lcall	___fssub
      000184 AC 82            [24]  773 	mov	r4, dpl
      000186 AD 83            [24]  774 	mov	r5, dph
      000188 AE F0            [24]  775 	mov	r6, b
      00018A FF               [12]  776 	mov	r7, a
      00018B E5 81            [12]  777 	mov	a,sp
      00018D 24 FC            [12]  778 	add	a,#0xfc
      00018F F5 81            [12]  779 	mov	sp,a
      000191 8C 82            [24]  780 	mov	dpl, r4
      000193 8D 83            [24]  781 	mov	dph, r5
      000195 8E F0            [24]  782 	mov	b, r6
      000197 EF               [12]  783 	mov	a, r7
                           0000E1   784 	C$fuzzy.h$870$1_0$25 ==.
                                    785 ;	../../fuzzy.h:870: }
                           0000E1   786 	C$fuzzy.h$870$1_0$25 ==.
                           0000E1   787 	XG$fuzzy_not$0$0 ==.
      000198 22               [24]  788 	ret
                                    789 ;------------------------------------------------------------
                                    790 ;Allocation info for local variables in function 'fuzzy_apply_hedge'
                                    791 ;------------------------------------------------------------
                                    792 ;hedge         Allocated to stack - _bp -3 +1 
                                    793 ;membership    Allocated to stack - _bp +1 +4 
                                    794 ;result        Allocated to registers r2 r3 r6 r7 
                                    795 ;------------------------------------------------------------
                           0000E2   796 	Fcontroller_8051$fuzzy_apply_hedge$0$0 ==.
                           0000E2   797 	C$fuzzy.h$880$1_0$27 ==.
                                    798 ;	../../fuzzy.h:880: static float fuzzy_apply_hedge(
                                    799 ;	-----------------------------------------
                                    800 ;	 function fuzzy_apply_hedge
                                    801 ;	-----------------------------------------
      000199                        802 _fuzzy_apply_hedge:
      000199 C0 08            [24]  803 	push	_bp
      00019B 85 81 08         [24]  804 	mov	_bp,sp
      00019E AC 82            [24]  805 	mov	r4,dpl
      0001A0 AD 83            [24]  806 	mov	r5,dph
      0001A2 AE F0            [24]  807 	mov	r6,b
      0001A4 FF               [12]  808 	mov	r7,a
      0001A5 E5 81            [12]  809 	mov	a,sp
      0001A7 24 04            [12]  810 	add	a,#0x04
      0001A9 F5 81            [12]  811 	mov	sp,a
                           0000F4   812 	C$fuzzy.h$886$1_0$27 ==.
                                    813 ;	../../fuzzy.h:886: fuzzy_clamp( membership
      0001AB 8C 82            [24]  814 	mov	dpl, r4
      0001AD 8D 83            [24]  815 	mov	dph, r5
      0001AF 8E F0            [24]  816 	mov	b, r6
      0001B1 EF               [12]  817 	mov	a, r7
      0001B2 12 00 EA         [24]  818 	lcall	_fuzzy_clamp
      0001B5 A8 08            [24]  819 	mov	r0,_bp
      0001B7 08               [12]  820 	inc	r0
      0001B8 A6 82            [24]  821 	mov	@r0, dpl
      0001BA 08               [12]  822 	inc	r0
      0001BB A6 83            [24]  823 	mov	@r0, dph
      0001BD 08               [12]  824 	inc	r0
      0001BE A6 F0            [24]  825 	mov	@r0, b
      0001C0 08               [12]  826 	inc	r0
      0001C1 F6               [12]  827 	mov	@r0,a
                           00010B   828 	C$fuzzy.h$891$2_0$28 ==.
                                    829 ;	../../fuzzy.h:891: float result =
      0001C2 7A 00            [12]  830 	mov	r2,#0x00
      0001C4 7B 00            [12]  831 	mov	r3,#0x00
      0001C6 7E 80            [12]  832 	mov	r6,#0x80
      0001C8 7F 3F            [12]  833 	mov	r7,#0x3f
                           000113   834 	C$fuzzy.h$894$1_1$28 ==.
                                    835 ;	../../fuzzy.h:894: if (hedge == 0u) {
      0001CA E5 08            [12]  836 	mov	a,_bp
      0001CC 24 FD            [12]  837 	add	a,#0xfd
      0001CE F8               [12]  838 	mov	r0,a
      0001CF E6               [12]  839 	mov	a,@r0
      0001D0 70 07            [24]  840 	jnz	00110$
                           00011B   841 	C$fuzzy.h$895$2_1$29 ==.
                                    842 ;	../../fuzzy.h:895: hedge = 1u;
      0001D2 E5 08            [12]  843 	mov	a,_bp
      0001D4 24 FD            [12]  844 	add	a,#0xfd
      0001D6 F8               [12]  845 	mov	r0,a
      0001D7 76 01            [12]  846 	mov	@r0,#0x01
                           000122   847 	C$fuzzy.h$898$1_1$27 ==.
                                    848 ;	../../fuzzy.h:898: while (hedge > 0u) {
      0001D9                        849 00110$:
      0001D9 E5 08            [12]  850 	mov	a,_bp
      0001DB 24 FD            [12]  851 	add	a,#0xfd
      0001DD F8               [12]  852 	mov	r0,a
      0001DE 86 05            [24]  853 	mov	ar5,@r0
      0001E0                        854 00103$:
      0001E0 ED               [12]  855 	mov	a,r5
      0001E1 60 30            [24]  856 	jz	00105$
                           00012C   857 	C$fuzzy.h$899$1_1$27 ==.
                                    858 ;	../../fuzzy.h:899: result *= membership;
      0001E3 C0 05            [24]  859 	push	ar5
      0001E5 A8 08            [24]  860 	mov	r0,_bp
      0001E7 08               [12]  861 	inc	r0
      0001E8 E6               [12]  862 	mov	a,@r0
      0001E9 C0 E0            [24]  863 	push	acc
      0001EB 08               [12]  864 	inc	r0
      0001EC E6               [12]  865 	mov	a,@r0
      0001ED C0 E0            [24]  866 	push	acc
      0001EF 08               [12]  867 	inc	r0
      0001F0 E6               [12]  868 	mov	a,@r0
      0001F1 C0 E0            [24]  869 	push	acc
      0001F3 08               [12]  870 	inc	r0
      0001F4 E6               [12]  871 	mov	a,@r0
      0001F5 C0 E0            [24]  872 	push	acc
                           000140   873 	C$fuzzy.h$901$1_1$27 ==.
                                    874 ;	../../fuzzy.h:901: hedge--;
      0001F7 8A 82            [24]  875 	mov	dpl, r2
      0001F9 8B 83            [24]  876 	mov	dph, r3
      0001FB 8E F0            [24]  877 	mov	b, r6
      0001FD EF               [12]  878 	mov	a, r7
      0001FE 12 26 38         [24]  879 	lcall	___fsmul
      000201 AA 82            [24]  880 	mov	r2, dpl
      000203 AB 83            [24]  881 	mov	r3, dph
      000205 AE F0            [24]  882 	mov	r6, b
      000207 FF               [12]  883 	mov	r7, a
      000208 E5 81            [12]  884 	mov	a,sp
      00020A 24 FC            [12]  885 	add	a,#0xfc
      00020C F5 81            [12]  886 	mov	sp,a
      00020E D0 05            [24]  887 	pop	ar5
      000210 1D               [12]  888 	dec	r5
      000211 80 CD            [24]  889 	sjmp	00103$
      000213                        890 00105$:
                           00015C   891 	C$fuzzy.h$905$1_1$28 ==.
                                    892 ;	../../fuzzy.h:905: result
      000213 8A 82            [24]  893 	mov	dpl, r2
      000215 8B 83            [24]  894 	mov	dph, r3
      000217 8E F0            [24]  895 	mov	b, r6
      000219 EF               [12]  896 	mov	a, r7
      00021A 12 00 EA         [24]  897 	lcall	_fuzzy_clamp
                           000166   898 	C$fuzzy.h$921$1_1$27 ==.
                                    899 ;	../../fuzzy.h:921: }
      00021D 85 08 81         [24]  900 	mov	sp,_bp
      000220 D0 08            [24]  901 	pop	_bp
                           00016B   902 	C$fuzzy.h$921$1_1$27 ==.
                           00016B   903 	XFcontroller_8051$fuzzy_apply_hedge$0$0 ==.
      000222 22               [24]  904 	ret
                                    905 ;------------------------------------------------------------
                                    906 ;Allocation info for local variables in function 'fuzzy_and_array'
                                    907 ;------------------------------------------------------------
                                    908 ;count         Allocated to stack - _bp -4 +2 
                                    909 ;args          Allocated to stack - _bp -7 +3 
                                    910 ;method        Allocated to registers r5 
                                    911 ;result        Allocated to stack - _bp +5 +4 
                                    912 ;next          Allocated to stack - _bp +9 +4 
                                    913 ;index         Allocated to stack - _bp +13 +2 
                                    914 ;sloc0         Allocated to stack - _bp +1 +3 
                                    915 ;sloc1         Allocated to stack - _bp +4 +1 
                                    916 ;------------------------------------------------------------
                           00016C   917 	G$fuzzy_and_array$0$0 ==.
                           00016C   918 	C$fuzzy.h$935$1_1$32 ==.
                                    919 ;	../../fuzzy.h:935: float fuzzy_and_array(
                                    920 ;	-----------------------------------------
                                    921 ;	 function fuzzy_and_array
                                    922 ;	-----------------------------------------
      000223                        923 _fuzzy_and_array:
      000223 C0 08            [24]  924 	push	_bp
      000225 E5 81            [12]  925 	mov	a,sp
      000227 F5 08            [12]  926 	mov	_bp,a
      000229 24 0E            [12]  927 	add	a,#0x0e
      00022B F5 81            [12]  928 	mov	sp,a
      00022D AD 82            [24]  929 	mov	r5, dpl
                           000178   930 	C$fuzzy.h$946$1_0$32 ==.
                                    931 ;	../../fuzzy.h:946: args == NULL ||
      00022F E5 08            [12]  932 	mov	a,_bp
      000231 24 F9            [12]  933 	add	a,#0xf9
      000233 F8               [12]  934 	mov	r0,a
      000234 E6               [12]  935 	mov	a,@r0
      000235 08               [12]  936 	inc	r0
      000236 46               [12]  937 	orl	a,@r0
      000237 60 0A            [24]  938 	jz	00101$
                           000182   939 	C$fuzzy.h$947$1_0$32 ==.
                                    940 ;	../../fuzzy.h:947: count == 0u
      000239 E5 08            [12]  941 	mov	a,_bp
      00023B 24 FC            [12]  942 	add	a,#0xfc
      00023D F8               [12]  943 	mov	r0,a
      00023E E6               [12]  944 	mov	a,@r0
      00023F 08               [12]  945 	inc	r0
      000240 46               [12]  946 	orl	a,@r0
      000241 70 0B            [24]  947 	jnz	00102$
      000243                        948 00101$:
                           00018C   949 	C$fuzzy.h$949$2_0$33 ==.
                                    950 ;	../../fuzzy.h:949: return LEVEL_HI;
      000243 90 00 00         [24]  951 	mov	dptr,#0x0000
      000246 75 F0 80         [24]  952 	mov	b, #0x80
      000249 74 3F            [12]  953 	mov	a, #0x3f
      00024B 02 04 BC         [24]  954 	ljmp	00121$
      00024E                        955 00102$:
                           000197   956 	C$fuzzy.h$953$1_0$32 ==.
                                    957 ;	../../fuzzy.h:953: method != FUZZY_LOGIC_STANDARD &&
      00024E ED               [12]  958 	mov	a,r5
      00024F 60 13            [24]  959 	jz	00105$
                           00019A   960 	C$fuzzy.h$954$1_0$32 ==.
                                    961 ;	../../fuzzy.h:954: method != FUZZY_LOGIC_ALGEBRAIC &&
      000251 BD 01 02         [24]  962 	cjne	r5,#0x01,00192$
      000254 80 0E            [24]  963 	sjmp	00105$
      000256                        964 00192$:
                           00019F   965 	C$fuzzy.h$956$1_0$32 ==.
                                    966 ;	../../fuzzy.h:956: ) {
      000256 BD 02 02         [24]  967 	cjne	r5,#0x02,00193$
      000259 80 09            [24]  968 	sjmp	00105$
      00025B                        969 00193$:
                           0001A4   970 	C$fuzzy.h$957$2_0$34 ==.
                                    971 ;	../../fuzzy.h:957: return LEVEL_LO;
      00025B 90 00 00         [24]  972 	mov	dptr,#0x0000
      00025E E4               [12]  973 	clr	a
      00025F F5 F0            [12]  974 	mov	b,a
      000261 02 04 BC         [24]  975 	ljmp	00121$
      000264                        976 00105$:
                           0001AD   977 	C$fuzzy.h$962$1_0$32 ==.
                                    978 ;	../../fuzzy.h:962: args[0]
      000264 E5 08            [12]  979 	mov	a,_bp
      000266 24 F9            [12]  980 	add	a,#0xf9
      000268 F8               [12]  981 	mov	r0,a
      000269 A9 08            [24]  982 	mov	r1,_bp
      00026B 09               [12]  983 	inc	r1
      00026C E6               [12]  984 	mov	a,@r0
      00026D F7               [12]  985 	mov	@r1,a
      00026E 08               [12]  986 	inc	r0
      00026F E6               [12]  987 	mov	a,@r0
      000270 09               [12]  988 	inc	r1
      000271 F7               [12]  989 	mov	@r1,a
      000272 08               [12]  990 	inc	r0
      000273 E6               [12]  991 	mov	a,@r0
      000274 09               [12]  992 	inc	r1
      000275 F7               [12]  993 	mov	@r1,a
      000276 A8 08            [24]  994 	mov	r0,_bp
      000278 08               [12]  995 	inc	r0
      000279 86 82            [24]  996 	mov	dpl,@r0
      00027B 08               [12]  997 	inc	r0
      00027C 86 83            [24]  998 	mov	dph,@r0
      00027E 08               [12]  999 	inc	r0
      00027F 86 F0            [24] 1000 	mov	b,@r0
      000281 12 29 94         [24] 1001 	lcall	__gptrget
      000284 FA               [12] 1002 	mov	r2,a
      000285 A3               [24] 1003 	inc	dptr
      000286 12 29 94         [24] 1004 	lcall	__gptrget
      000289 FB               [12] 1005 	mov	r3,a
      00028A A3               [24] 1006 	inc	dptr
      00028B 12 29 94         [24] 1007 	lcall	__gptrget
      00028E FE               [12] 1008 	mov	r6,a
      00028F A3               [24] 1009 	inc	dptr
      000290 12 29 94         [24] 1010 	lcall	__gptrget
      000293 8A 82            [24] 1011 	mov	dpl,r2
      000295 8B 83            [24] 1012 	mov	dph,r3
      000297 8E F0            [24] 1013 	mov	b,r6
      000299 C0 05            [24] 1014 	push	ar5
      00029B 12 00 EA         [24] 1015 	lcall	_fuzzy_clamp
      00029E C8               [12] 1016 	xch	a,r0
      00029F E5 08            [12] 1017 	mov	a,_bp
      0002A1 24 05            [12] 1018 	add	a,#0x05
      0002A3 C8               [12] 1019 	xch	a,r0
      0002A4 A6 82            [24] 1020 	mov	@r0, dpl
      0002A6 08               [12] 1021 	inc	r0
      0002A7 A6 83            [24] 1022 	mov	@r0, dph
      0002A9 08               [12] 1023 	inc	r0
      0002AA A6 F0            [24] 1024 	mov	@r0, b
      0002AC 08               [12] 1025 	inc	r0
      0002AD F6               [12] 1026 	mov	@r0,a
      0002AE D0 05            [24] 1027 	pop	ar5
                           0001F9  1028 	C$fuzzy.h$966$3_0$36 ==.
                                   1029 ;	../../fuzzy.h:966: index = 1u;
      0002B0 E4               [12] 1030 	clr	a
      0002B1 BD 00 01         [24] 1031 	cjne	r5,#0x00,00194$
      0002B4 04               [12] 1032 	inc	a
      0002B5                       1033 00194$:
      0002B5 FB               [12] 1034 	mov	r3,a
      0002B6 BD 01 03         [24] 1035 	cjne	r5,#0x01,00196$
      0002B9 ED               [12] 1036 	mov	a,r5
      0002BA 80 01            [24] 1037 	sjmp	00197$
      0002BC                       1038 00196$:
      0002BC E4               [12] 1039 	clr	a
      0002BD                       1040 00197$:
      0002BD FA               [12] 1041 	mov	r2,a
      0002BE E5 08            [12] 1042 	mov	a,_bp
      0002C0 24 04            [12] 1043 	add	a,#0x04
      0002C2 F8               [12] 1044 	mov	r0,a
      0002C3 E4               [12] 1045 	clr	a
      0002C4 BD 02 01         [24] 1046 	cjne	r5,#0x02,00198$
      0002C7 04               [12] 1047 	inc	a
      0002C8                       1048 00198$:
      0002C8 F6               [12] 1049 	mov	@r0,a
      0002C9 E5 08            [12] 1050 	mov	a,_bp
      0002CB 24 0D            [12] 1051 	add	a,#0x0d
      0002CD F8               [12] 1052 	mov	r0,a
      0002CE 76 01            [12] 1053 	mov	@r0,#0x01
      0002D0 08               [12] 1054 	inc	r0
      0002D1 76 00            [12] 1055 	mov	@r0,#0x00
      0002D3                       1056 00119$:
                           00021C  1057 	C$fuzzy.h$967$2_0$35 ==.
                                   1058 ;	../../fuzzy.h:967: index < count;
      0002D3 E5 08            [12] 1059 	mov	a,_bp
      0002D5 24 0D            [12] 1060 	add	a,#0x0d
      0002D7 F8               [12] 1061 	mov	r0,a
      0002D8 E5 08            [12] 1062 	mov	a,_bp
      0002DA 24 FC            [12] 1063 	add	a,#0xfc
      0002DC F9               [12] 1064 	mov	r1,a
      0002DD C3               [12] 1065 	clr	c
      0002DE E6               [12] 1066 	mov	a,@r0
      0002DF 97               [12] 1067 	subb	a,@r1
      0002E0 08               [12] 1068 	inc	r0
      0002E1 E6               [12] 1069 	mov	a,@r0
      0002E2 09               [12] 1070 	inc	r1
      0002E3 97               [12] 1071 	subb	a,@r1
      0002E4 40 03            [24] 1072 	jc	00200$
      0002E6 02 04 AA         [24] 1073 	ljmp	00117$
      0002E9                       1074 00200$:
                           000232  1075 	C$fuzzy.h$972$1_0$32 ==.
                                   1076 ;	../../fuzzy.h:972: args[index]
      0002E9 C0 02            [24] 1077 	push	ar2
      0002EB E5 08            [12] 1078 	mov	a,_bp
      0002ED 24 0D            [12] 1079 	add	a,#0x0d
      0002EF F8               [12] 1080 	mov	r0,a
      0002F0 E6               [12] 1081 	mov	a,@r0
      0002F1 26               [12] 1082 	add	a,@r0
      0002F2 FD               [12] 1083 	mov	r5,a
      0002F3 08               [12] 1084 	inc	r0
      0002F4 E6               [12] 1085 	mov	a,@r0
      0002F5 33               [12] 1086 	rlc	a
      0002F6 FC               [12] 1087 	mov	r4,a
      0002F7 ED               [12] 1088 	mov	a,r5
      0002F8 2D               [12] 1089 	add	a,r5
      0002F9 FD               [12] 1090 	mov	r5,a
      0002FA EC               [12] 1091 	mov	a,r4
      0002FB 33               [12] 1092 	rlc	a
      0002FC FC               [12] 1093 	mov	r4,a
      0002FD A8 08            [24] 1094 	mov	r0,_bp
      0002FF 08               [12] 1095 	inc	r0
      000300 ED               [12] 1096 	mov	a,r5
      000301 26               [12] 1097 	add	a, @r0
      000302 FA               [12] 1098 	mov	r2,a
      000303 EC               [12] 1099 	mov	a,r4
      000304 08               [12] 1100 	inc	r0
      000305 36               [12] 1101 	addc	a, @r0
      000306 FC               [12] 1102 	mov	r4,a
      000307 08               [12] 1103 	inc	r0
      000308 86 05            [24] 1104 	mov	ar5,@r0
      00030A 8A 82            [24] 1105 	mov	dpl,r2
      00030C 8C 83            [24] 1106 	mov	dph,r4
      00030E 8D F0            [24] 1107 	mov	b,r5
      000310 12 29 94         [24] 1108 	lcall	__gptrget
      000313 FA               [12] 1109 	mov	r2,a
      000314 A3               [24] 1110 	inc	dptr
      000315 12 29 94         [24] 1111 	lcall	__gptrget
      000318 FC               [12] 1112 	mov	r4,a
      000319 A3               [24] 1113 	inc	dptr
      00031A 12 29 94         [24] 1114 	lcall	__gptrget
      00031D FD               [12] 1115 	mov	r5,a
      00031E A3               [24] 1116 	inc	dptr
      00031F 12 29 94         [24] 1117 	lcall	__gptrget
      000322 8A 82            [24] 1118 	mov	dpl,r2
      000324 8C 83            [24] 1119 	mov	dph,r4
      000326 8D F0            [24] 1120 	mov	b,r5
      000328 C0 03            [24] 1121 	push	ar3
      00032A C0 02            [24] 1122 	push	ar2
      00032C 12 00 EA         [24] 1123 	lcall	_fuzzy_clamp
      00032F C8               [12] 1124 	xch	a,r0
      000330 E5 08            [12] 1125 	mov	a,_bp
      000332 24 09            [12] 1126 	add	a,#0x09
      000334 C8               [12] 1127 	xch	a,r0
      000335 A6 82            [24] 1128 	mov	@r0, dpl
      000337 08               [12] 1129 	inc	r0
      000338 A6 83            [24] 1130 	mov	@r0, dph
      00033A 08               [12] 1131 	inc	r0
      00033B A6 F0            [24] 1132 	mov	@r0, b
      00033D 08               [12] 1133 	inc	r0
      00033E F6               [12] 1134 	mov	@r0,a
      00033F D0 02            [24] 1135 	pop	ar2
      000341 D0 03            [24] 1136 	pop	ar3
                           00028C  1137 	C$fuzzy.h$975$1_0$32 ==.
                                   1138 ;	../../fuzzy.h:975: switch (method) {
      000343 D0 02            [24] 1139 	pop	ar2
      000345 EB               [12] 1140 	mov	a,r3
      000346 70 11            [24] 1141 	jnz	00108$
      000348 EA               [12] 1142 	mov	a,r2
      000349 70 65            [24] 1143 	jnz	00111$
      00034B E5 08            [12] 1144 	mov	a,_bp
      00034D 24 04            [12] 1145 	add	a,#0x04
      00034F F8               [12] 1146 	mov	r0,a
      000350 E6               [12] 1147 	mov	a,@r0
      000351 60 03            [24] 1148 	jz	00203$
      000353 02 03 F7         [24] 1149 	ljmp	00112$
      000356                       1150 00203$:
      000356 02 04 94         [24] 1151 	ljmp	00115$
                           0002A2  1152 	C$fuzzy.h$976$4_0$37 ==.
                                   1153 ;	../../fuzzy.h:976: case FUZZY_LOGIC_STANDARD:
      000359                       1154 00108$:
                           0002A2  1155 	C$fuzzy.h$977$1_0$32 ==.
                                   1156 ;	../../fuzzy.h:977: if (next < result) {
      000359 C0 03            [24] 1157 	push	ar3
      00035B C0 02            [24] 1158 	push	ar2
      00035D E5 08            [12] 1159 	mov	a,_bp
      00035F 24 05            [12] 1160 	add	a,#0x05
      000361 F8               [12] 1161 	mov	r0,a
      000362 E6               [12] 1162 	mov	a,@r0
      000363 C0 E0            [24] 1163 	push	acc
      000365 08               [12] 1164 	inc	r0
      000366 E6               [12] 1165 	mov	a,@r0
      000367 C0 E0            [24] 1166 	push	acc
      000369 08               [12] 1167 	inc	r0
      00036A E6               [12] 1168 	mov	a,@r0
      00036B C0 E0            [24] 1169 	push	acc
      00036D 08               [12] 1170 	inc	r0
      00036E E6               [12] 1171 	mov	a,@r0
      00036F C0 E0            [24] 1172 	push	acc
      000371 E5 08            [12] 1173 	mov	a,_bp
      000373 24 09            [12] 1174 	add	a,#0x09
      000375 F8               [12] 1175 	mov	r0,a
      000376 86 82            [24] 1176 	mov	dpl, @r0
      000378 08               [12] 1177 	inc	r0
      000379 86 83            [24] 1178 	mov	dph, @r0
      00037B 08               [12] 1179 	inc	r0
      00037C 86 F0            [24] 1180 	mov	b, @r0
      00037E 08               [12] 1181 	inc	r0
      00037F E6               [12] 1182 	mov	a, @r0
      000380 12 27 68         [24] 1183 	lcall	___fslt
      000383 AF 82            [24] 1184 	mov	r7, dpl
      000385 E5 81            [12] 1185 	mov	a,sp
      000387 24 FC            [12] 1186 	add	a,#0xfc
      000389 F5 81            [12] 1187 	mov	sp,a
      00038B D0 02            [24] 1188 	pop	ar2
      00038D D0 03            [24] 1189 	pop	ar3
      00038F EF               [12] 1190 	mov	a,r7
      000390 70 03            [24] 1191 	jnz	00204$
      000392 02 04 9C         [24] 1192 	ljmp	00120$
      000395                       1193 00204$:
                           0002DE  1194 	C$fuzzy.h$978$5_0$38 ==.
                                   1195 ;	../../fuzzy.h:978: result = next;
      000395 E5 08            [12] 1196 	mov	a,_bp
      000397 24 09            [12] 1197 	add	a,#0x09
      000399 F8               [12] 1198 	mov	r0,a
      00039A E5 08            [12] 1199 	mov	a,_bp
      00039C 24 05            [12] 1200 	add	a,#0x05
      00039E F9               [12] 1201 	mov	r1,a
      00039F E6               [12] 1202 	mov	a,@r0
      0003A0 F7               [12] 1203 	mov	@r1,a
      0003A1 08               [12] 1204 	inc	r0
      0003A2 E6               [12] 1205 	mov	a,@r0
      0003A3 09               [12] 1206 	inc	r1
      0003A4 F7               [12] 1207 	mov	@r1,a
      0003A5 08               [12] 1208 	inc	r0
      0003A6 E6               [12] 1209 	mov	a,@r0
      0003A7 09               [12] 1210 	inc	r1
      0003A8 F7               [12] 1211 	mov	@r1,a
      0003A9 08               [12] 1212 	inc	r0
      0003AA E6               [12] 1213 	mov	a,@r0
      0003AB 09               [12] 1214 	inc	r1
      0003AC F7               [12] 1215 	mov	@r1,a
                           0002F6  1216 	C$fuzzy.h$980$4_0$37 ==.
                                   1217 ;	../../fuzzy.h:980: break;
      0003AD 02 04 9C         [24] 1218 	ljmp	00120$
                           0002F9  1219 	C$fuzzy.h$982$4_0$37 ==.
                                   1220 ;	../../fuzzy.h:982: case FUZZY_LOGIC_ALGEBRAIC:
      0003B0                       1221 00111$:
                           0002F9  1222 	C$fuzzy.h$984$1_0$32 ==.
                                   1223 ;	../../fuzzy.h:984: next;
      0003B0 C0 03            [24] 1224 	push	ar3
      0003B2 C0 02            [24] 1225 	push	ar2
      0003B4 E5 08            [12] 1226 	mov	a,_bp
      0003B6 24 09            [12] 1227 	add	a,#0x09
      0003B8 F8               [12] 1228 	mov	r0,a
      0003B9 E6               [12] 1229 	mov	a,@r0
      0003BA C0 E0            [24] 1230 	push	acc
      0003BC 08               [12] 1231 	inc	r0
      0003BD E6               [12] 1232 	mov	a,@r0
      0003BE C0 E0            [24] 1233 	push	acc
      0003C0 08               [12] 1234 	inc	r0
      0003C1 E6               [12] 1235 	mov	a,@r0
      0003C2 C0 E0            [24] 1236 	push	acc
      0003C4 08               [12] 1237 	inc	r0
      0003C5 E6               [12] 1238 	mov	a,@r0
      0003C6 C0 E0            [24] 1239 	push	acc
                           000311  1240 	C$fuzzy.h$985$1_0$32 ==.
                                   1241 ;	../../fuzzy.h:985: break;
      0003C8 E5 08            [12] 1242 	mov	a,_bp
      0003CA 24 05            [12] 1243 	add	a,#0x05
      0003CC F8               [12] 1244 	mov	r0,a
      0003CD 86 82            [24] 1245 	mov	dpl, @r0
      0003CF 08               [12] 1246 	inc	r0
      0003D0 86 83            [24] 1247 	mov	dph, @r0
      0003D2 08               [12] 1248 	inc	r0
      0003D3 86 F0            [24] 1249 	mov	b, @r0
      0003D5 08               [12] 1250 	inc	r0
      0003D6 E6               [12] 1251 	mov	a, @r0
      0003D7 12 26 38         [24] 1252 	lcall	___fsmul
      0003DA C8               [12] 1253 	xch	a,r0
      0003DB E5 08            [12] 1254 	mov	a,_bp
      0003DD 24 05            [12] 1255 	add	a,#0x05
      0003DF C8               [12] 1256 	xch	a,r0
      0003E0 A6 82            [24] 1257 	mov	@r0, dpl
      0003E2 08               [12] 1258 	inc	r0
      0003E3 A6 83            [24] 1259 	mov	@r0, dph
      0003E5 08               [12] 1260 	inc	r0
      0003E6 A6 F0            [24] 1261 	mov	@r0, b
      0003E8 08               [12] 1262 	inc	r0
      0003E9 F6               [12] 1263 	mov	@r0,a
      0003EA E5 81            [12] 1264 	mov	a,sp
      0003EC 24 FC            [12] 1265 	add	a,#0xfc
      0003EE F5 81            [12] 1266 	mov	sp,a
      0003F0 D0 02            [24] 1267 	pop	ar2
      0003F2 D0 03            [24] 1268 	pop	ar3
      0003F4 02 04 9C         [24] 1269 	ljmp	00120$
                           000340  1270 	C$fuzzy.h$987$4_0$37 ==.
                                   1271 ;	../../fuzzy.h:987: case FUZZY_LOGIC_BOUNDED:
      0003F7                       1272 00112$:
                           000340  1273 	C$fuzzy.h$990$1_0$32 ==.
                                   1274 ;	../../fuzzy.h:990: next -
      0003F7 C0 03            [24] 1275 	push	ar3
      0003F9 C0 02            [24] 1276 	push	ar2
      0003FB E5 08            [12] 1277 	mov	a,_bp
      0003FD 24 09            [12] 1278 	add	a,#0x09
      0003FF F8               [12] 1279 	mov	r0,a
      000400 E6               [12] 1280 	mov	a,@r0
      000401 C0 E0            [24] 1281 	push	acc
      000403 08               [12] 1282 	inc	r0
      000404 E6               [12] 1283 	mov	a,@r0
      000405 C0 E0            [24] 1284 	push	acc
      000407 08               [12] 1285 	inc	r0
      000408 E6               [12] 1286 	mov	a,@r0
      000409 C0 E0            [24] 1287 	push	acc
      00040B 08               [12] 1288 	inc	r0
      00040C E6               [12] 1289 	mov	a,@r0
      00040D C0 E0            [24] 1290 	push	acc
      00040F E5 08            [12] 1291 	mov	a,_bp
      000411 24 05            [12] 1292 	add	a,#0x05
      000413 F8               [12] 1293 	mov	r0,a
      000414 86 82            [24] 1294 	mov	dpl, @r0
      000416 08               [12] 1295 	inc	r0
      000417 86 83            [24] 1296 	mov	dph, @r0
      000419 08               [12] 1297 	inc	r0
      00041A 86 F0            [24] 1298 	mov	b, @r0
      00041C 08               [12] 1299 	inc	r0
      00041D E6               [12] 1300 	mov	a, @r0
      00041E 12 27 BA         [24] 1301 	lcall	___fsadd
      000421 AC 82            [24] 1302 	mov	r4, dpl
      000423 AD 83            [24] 1303 	mov	r5, dph
      000425 AE F0            [24] 1304 	mov	r6, b
      000427 FF               [12] 1305 	mov	r7, a
      000428 E5 81            [12] 1306 	mov	a,sp
      00042A 24 FC            [12] 1307 	add	a,#0xfc
      00042C F5 81            [12] 1308 	mov	sp,a
      00042E E4               [12] 1309 	clr	a
      00042F C0 E0            [24] 1310 	push	acc
      000431 C0 E0            [24] 1311 	push	acc
      000433 74 80            [12] 1312 	mov	a,#0x80
      000435 C0 E0            [24] 1313 	push	acc
      000437 74 3F            [12] 1314 	mov	a,#0x3f
      000439 C0 E0            [24] 1315 	push	acc
                           000384  1316 	C$fuzzy.h$993$1_0$32 ==.
                                   1317 ;	../../fuzzy.h:993: if (result < LEVEL_LO) {
      00043B 8C 82            [24] 1318 	mov	dpl, r4
      00043D 8D 83            [24] 1319 	mov	dph, r5
      00043F 8E F0            [24] 1320 	mov	b, r6
      000441 EF               [12] 1321 	mov	a, r7
      000442 12 26 2D         [24] 1322 	lcall	___fssub
      000445 C8               [12] 1323 	xch	a,r0
      000446 E5 08            [12] 1324 	mov	a,_bp
      000448 24 05            [12] 1325 	add	a,#0x05
      00044A C8               [12] 1326 	xch	a,r0
      00044B A6 82            [24] 1327 	mov	@r0, dpl
      00044D 08               [12] 1328 	inc	r0
      00044E A6 83            [24] 1329 	mov	@r0, dph
      000450 08               [12] 1330 	inc	r0
      000451 A6 F0            [24] 1331 	mov	@r0, b
      000453 08               [12] 1332 	inc	r0
      000454 F6               [12] 1333 	mov	@r0,a
      000455 E5 81            [12] 1334 	mov	a,sp
      000457 24 FC            [12] 1335 	add	a,#0xfc
      000459 F5 81            [12] 1336 	mov	sp,a
      00045B E4               [12] 1337 	clr	a
      00045C C0 E0            [24] 1338 	push	acc
      00045E C0 E0            [24] 1339 	push	acc
      000460 C0 E0            [24] 1340 	push	acc
      000462 C0 E0            [24] 1341 	push	acc
      000464 E5 08            [12] 1342 	mov	a,_bp
      000466 24 05            [12] 1343 	add	a,#0x05
      000468 F8               [12] 1344 	mov	r0,a
      000469 86 82            [24] 1345 	mov	dpl, @r0
      00046B 08               [12] 1346 	inc	r0
      00046C 86 83            [24] 1347 	mov	dph, @r0
      00046E 08               [12] 1348 	inc	r0
      00046F 86 F0            [24] 1349 	mov	b, @r0
      000471 08               [12] 1350 	inc	r0
      000472 E6               [12] 1351 	mov	a, @r0
      000473 12 27 68         [24] 1352 	lcall	___fslt
      000476 AF 82            [24] 1353 	mov	r7, dpl
      000478 E5 81            [12] 1354 	mov	a,sp
      00047A 24 FC            [12] 1355 	add	a,#0xfc
      00047C F5 81            [12] 1356 	mov	sp,a
      00047E D0 02            [24] 1357 	pop	ar2
      000480 D0 03            [24] 1358 	pop	ar3
      000482 EF               [12] 1359 	mov	a,r7
      000483 60 17            [24] 1360 	jz	00120$
                           0003CE  1361 	C$fuzzy.h$994$5_0$39 ==.
                                   1362 ;	../../fuzzy.h:994: result = LEVEL_LO;
      000485 E5 08            [12] 1363 	mov	a,_bp
      000487 24 05            [12] 1364 	add	a,#0x05
      000489 F8               [12] 1365 	mov	r0,a
      00048A E4               [12] 1366 	clr	a
      00048B F6               [12] 1367 	mov	@r0,a
      00048C 08               [12] 1368 	inc	r0
      00048D F6               [12] 1369 	mov	@r0,a
      00048E 08               [12] 1370 	inc	r0
      00048F F6               [12] 1371 	mov	@r0,a
      000490 08               [12] 1372 	inc	r0
      000491 F6               [12] 1373 	mov	@r0,a
                           0003DB  1374 	C$fuzzy.h$996$4_0$37 ==.
                                   1375 ;	../../fuzzy.h:996: break;
                           0003DB  1376 	C$fuzzy.h$998$4_0$37 ==.
                                   1377 ;	../../fuzzy.h:998: default:
      000492 80 08            [24] 1378 	sjmp	00120$
      000494                       1379 00115$:
                           0003DD  1380 	C$fuzzy.h$999$4_0$37 ==.
                                   1381 ;	../../fuzzy.h:999: return LEVEL_LO;
      000494 90 00 00         [24] 1382 	mov	dptr,#0x0000
      000497 E4               [12] 1383 	clr	a
      000498 F5 F0            [12] 1384 	mov	b,a
                           0003E3  1385 	C$fuzzy.h$1000$3_0$36 ==.
                                   1386 ;	../../fuzzy.h:1000: }
      00049A 80 20            [24] 1387 	sjmp	00121$
      00049C                       1388 00120$:
                           0003E5  1389 	C$fuzzy.h$968$2_0$35 ==.
                                   1390 ;	../../fuzzy.h:968: index++
      00049C E5 08            [12] 1391 	mov	a,_bp
      00049E 24 0D            [12] 1392 	add	a,#0x0d
      0004A0 F8               [12] 1393 	mov	r0,a
      0004A1 06               [12] 1394 	inc	@r0
      0004A2 B6 00 02         [24] 1395 	cjne	@r0,#0x00,00206$
      0004A5 08               [12] 1396 	inc	r0
      0004A6 06               [12] 1397 	inc	@r0
      0004A7                       1398 00206$:
      0004A7 02 02 D3         [24] 1399 	ljmp	00119$
      0004AA                       1400 00117$:
                           0003F3  1401 	C$fuzzy.h$1004$1_0$32 ==.
                                   1402 ;	../../fuzzy.h:1004: result
      0004AA E5 08            [12] 1403 	mov	a,_bp
      0004AC 24 05            [12] 1404 	add	a,#0x05
      0004AE F8               [12] 1405 	mov	r0,a
      0004AF 86 82            [24] 1406 	mov	dpl, @r0
      0004B1 08               [12] 1407 	inc	r0
      0004B2 86 83            [24] 1408 	mov	dph, @r0
      0004B4 08               [12] 1409 	inc	r0
      0004B5 86 F0            [24] 1410 	mov	b, @r0
      0004B7 08               [12] 1411 	inc	r0
      0004B8 E6               [12] 1412 	mov	a, @r0
      0004B9 12 00 EA         [24] 1413 	lcall	_fuzzy_clamp
      0004BC                       1414 00121$:
                           000405  1415 	C$fuzzy.h$1006$1_0$32 ==.
                                   1416 ;	../../fuzzy.h:1006: }
      0004BC 85 08 81         [24] 1417 	mov	sp,_bp
      0004BF D0 08            [24] 1418 	pop	_bp
                           00040A  1419 	C$fuzzy.h$1006$1_0$32 ==.
                           00040A  1420 	XG$fuzzy_and_array$0$0 ==.
      0004C1 22               [24] 1421 	ret
                                   1422 ;------------------------------------------------------------
                                   1423 ;Allocation info for local variables in function 'fuzzy_or_array'
                                   1424 ;------------------------------------------------------------
                                   1425 ;count         Allocated to stack - _bp -4 +2 
                                   1426 ;args          Allocated to stack - _bp -7 +3 
                                   1427 ;method        Allocated to registers r5 
                                   1428 ;result        Allocated to stack - _bp +10 +4 
                                   1429 ;next          Allocated to registers r4 r5 r6 r3 
                                   1430 ;index         Allocated to stack - _bp +14 +2 
                                   1431 ;sloc0         Allocated to stack - _bp +1 +3 
                                   1432 ;sloc1         Allocated to stack - _bp +4 +1 
                                   1433 ;sloc2         Allocated to stack - _bp +5 +1 
                                   1434 ;sloc3         Allocated to stack - _bp +6 +4 
                                   1435 ;------------------------------------------------------------
                           00040B  1436 	G$fuzzy_or_array$0$0 ==.
                           00040B  1437 	C$fuzzy.h$1021$1_0$41 ==.
                                   1438 ;	../../fuzzy.h:1021: float fuzzy_or_array(
                                   1439 ;	-----------------------------------------
                                   1440 ;	 function fuzzy_or_array
                                   1441 ;	-----------------------------------------
      0004C2                       1442 _fuzzy_or_array:
      0004C2 C0 08            [24] 1443 	push	_bp
      0004C4 E5 81            [12] 1444 	mov	a,sp
      0004C6 F5 08            [12] 1445 	mov	_bp,a
      0004C8 24 0F            [12] 1446 	add	a,#0x0f
      0004CA F5 81            [12] 1447 	mov	sp,a
      0004CC AD 82            [24] 1448 	mov	r5, dpl
                           000417  1449 	C$fuzzy.h$1032$1_0$41 ==.
                                   1450 ;	../../fuzzy.h:1032: args == NULL ||
      0004CE E5 08            [12] 1451 	mov	a,_bp
      0004D0 24 F9            [12] 1452 	add	a,#0xf9
      0004D2 F8               [12] 1453 	mov	r0,a
      0004D3 E6               [12] 1454 	mov	a,@r0
      0004D4 08               [12] 1455 	inc	r0
      0004D5 46               [12] 1456 	orl	a,@r0
      0004D6 60 0A            [24] 1457 	jz	00101$
                           000421  1458 	C$fuzzy.h$1033$1_0$41 ==.
                                   1459 ;	../../fuzzy.h:1033: count == 0u
      0004D8 E5 08            [12] 1460 	mov	a,_bp
      0004DA 24 FC            [12] 1461 	add	a,#0xfc
      0004DC F8               [12] 1462 	mov	r0,a
      0004DD E6               [12] 1463 	mov	a,@r0
      0004DE 08               [12] 1464 	inc	r0
      0004DF 46               [12] 1465 	orl	a,@r0
      0004E0 70 09            [24] 1466 	jnz	00102$
      0004E2                       1467 00101$:
                           00042B  1468 	C$fuzzy.h$1035$2_0$42 ==.
                                   1469 ;	../../fuzzy.h:1035: return LEVEL_LO;
      0004E2 90 00 00         [24] 1470 	mov	dptr,#0x0000
      0004E5 E4               [12] 1471 	clr	a
      0004E6 F5 F0            [12] 1472 	mov	b,a
      0004E8 02 07 7E         [24] 1473 	ljmp	00121$
      0004EB                       1474 00102$:
                           000434  1475 	C$fuzzy.h$1039$1_0$41 ==.
                                   1476 ;	../../fuzzy.h:1039: method != FUZZY_LOGIC_STANDARD &&
      0004EB ED               [12] 1477 	mov	a,r5
      0004EC 60 13            [24] 1478 	jz	00105$
                           000437  1479 	C$fuzzy.h$1040$1_0$41 ==.
                                   1480 ;	../../fuzzy.h:1040: method != FUZZY_LOGIC_ALGEBRAIC &&
      0004EE BD 01 02         [24] 1481 	cjne	r5,#0x01,00192$
      0004F1 80 0E            [24] 1482 	sjmp	00105$
      0004F3                       1483 00192$:
                           00043C  1484 	C$fuzzy.h$1042$1_0$41 ==.
                                   1485 ;	../../fuzzy.h:1042: ) {
      0004F3 BD 02 02         [24] 1486 	cjne	r5,#0x02,00193$
      0004F6 80 09            [24] 1487 	sjmp	00105$
      0004F8                       1488 00193$:
                           000441  1489 	C$fuzzy.h$1043$2_0$43 ==.
                                   1490 ;	../../fuzzy.h:1043: return LEVEL_LO;
      0004F8 90 00 00         [24] 1491 	mov	dptr,#0x0000
      0004FB E4               [12] 1492 	clr	a
      0004FC F5 F0            [12] 1493 	mov	b,a
      0004FE 02 07 7E         [24] 1494 	ljmp	00121$
      000501                       1495 00105$:
                           00044A  1496 	C$fuzzy.h$1048$1_0$41 ==.
                                   1497 ;	../../fuzzy.h:1048: args[0]
      000501 E5 08            [12] 1498 	mov	a,_bp
      000503 24 F9            [12] 1499 	add	a,#0xf9
      000505 F8               [12] 1500 	mov	r0,a
      000506 A9 08            [24] 1501 	mov	r1,_bp
      000508 09               [12] 1502 	inc	r1
      000509 E6               [12] 1503 	mov	a,@r0
      00050A F7               [12] 1504 	mov	@r1,a
      00050B 08               [12] 1505 	inc	r0
      00050C E6               [12] 1506 	mov	a,@r0
      00050D 09               [12] 1507 	inc	r1
      00050E F7               [12] 1508 	mov	@r1,a
      00050F 08               [12] 1509 	inc	r0
      000510 E6               [12] 1510 	mov	a,@r0
      000511 09               [12] 1511 	inc	r1
      000512 F7               [12] 1512 	mov	@r1,a
      000513 A8 08            [24] 1513 	mov	r0,_bp
      000515 08               [12] 1514 	inc	r0
      000516 86 82            [24] 1515 	mov	dpl,@r0
      000518 08               [12] 1516 	inc	r0
      000519 86 83            [24] 1517 	mov	dph,@r0
      00051B 08               [12] 1518 	inc	r0
      00051C 86 F0            [24] 1519 	mov	b,@r0
      00051E 12 29 94         [24] 1520 	lcall	__gptrget
      000521 FA               [12] 1521 	mov	r2,a
      000522 A3               [24] 1522 	inc	dptr
      000523 12 29 94         [24] 1523 	lcall	__gptrget
      000526 FB               [12] 1524 	mov	r3,a
      000527 A3               [24] 1525 	inc	dptr
      000528 12 29 94         [24] 1526 	lcall	__gptrget
      00052B FE               [12] 1527 	mov	r6,a
      00052C A3               [24] 1528 	inc	dptr
      00052D 12 29 94         [24] 1529 	lcall	__gptrget
      000530 8A 82            [24] 1530 	mov	dpl,r2
      000532 8B 83            [24] 1531 	mov	dph,r3
      000534 8E F0            [24] 1532 	mov	b,r6
      000536 C0 05            [24] 1533 	push	ar5
      000538 12 00 EA         [24] 1534 	lcall	_fuzzy_clamp
      00053B C8               [12] 1535 	xch	a,r0
      00053C E5 08            [12] 1536 	mov	a,_bp
      00053E 24 0A            [12] 1537 	add	a,#0x0a
      000540 C8               [12] 1538 	xch	a,r0
      000541 A6 82            [24] 1539 	mov	@r0, dpl
      000543 08               [12] 1540 	inc	r0
      000544 A6 83            [24] 1541 	mov	@r0, dph
      000546 08               [12] 1542 	inc	r0
      000547 A6 F0            [24] 1543 	mov	@r0, b
      000549 08               [12] 1544 	inc	r0
      00054A F6               [12] 1545 	mov	@r0,a
      00054B D0 05            [24] 1546 	pop	ar5
                           000496  1547 	C$fuzzy.h$1052$3_0$45 ==.
                                   1548 ;	../../fuzzy.h:1052: index = 1u;
      00054D E5 08            [12] 1549 	mov	a,_bp
      00054F 24 05            [12] 1550 	add	a,#0x05
      000551 F8               [12] 1551 	mov	r0,a
      000552 E4               [12] 1552 	clr	a
      000553 BD 00 01         [24] 1553 	cjne	r5,#0x00,00194$
      000556 04               [12] 1554 	inc	a
      000557                       1555 00194$:
      000557 F6               [12] 1556 	mov	@r0,a
      000558 BD 01 03         [24] 1557 	cjne	r5,#0x01,00196$
      00055B ED               [12] 1558 	mov	a,r5
      00055C 80 01            [24] 1559 	sjmp	00197$
      00055E                       1560 00196$:
      00055E E4               [12] 1561 	clr	a
      00055F                       1562 00197$:
      00055F FA               [12] 1563 	mov	r2,a
      000560 E5 08            [12] 1564 	mov	a,_bp
      000562 24 04            [12] 1565 	add	a,#0x04
      000564 F8               [12] 1566 	mov	r0,a
      000565 E4               [12] 1567 	clr	a
      000566 BD 02 01         [24] 1568 	cjne	r5,#0x02,00198$
      000569 04               [12] 1569 	inc	a
      00056A                       1570 00198$:
      00056A F6               [12] 1571 	mov	@r0,a
      00056B E5 08            [12] 1572 	mov	a,_bp
      00056D 24 0E            [12] 1573 	add	a,#0x0e
      00056F F8               [12] 1574 	mov	r0,a
      000570 76 01            [12] 1575 	mov	@r0,#0x01
      000572 08               [12] 1576 	inc	r0
      000573 76 00            [12] 1577 	mov	@r0,#0x00
      000575                       1578 00119$:
                           0004BE  1579 	C$fuzzy.h$1053$2_0$44 ==.
                                   1580 ;	../../fuzzy.h:1053: index < count;
      000575 E5 08            [12] 1581 	mov	a,_bp
      000577 24 0E            [12] 1582 	add	a,#0x0e
      000579 F8               [12] 1583 	mov	r0,a
      00057A E5 08            [12] 1584 	mov	a,_bp
      00057C 24 FC            [12] 1585 	add	a,#0xfc
      00057E F9               [12] 1586 	mov	r1,a
      00057F C3               [12] 1587 	clr	c
      000580 E6               [12] 1588 	mov	a,@r0
      000581 97               [12] 1589 	subb	a,@r1
      000582 08               [12] 1590 	inc	r0
      000583 E6               [12] 1591 	mov	a,@r0
      000584 09               [12] 1592 	inc	r1
      000585 97               [12] 1593 	subb	a,@r1
      000586 40 03            [24] 1594 	jc	00200$
      000588 02 07 6C         [24] 1595 	ljmp	00117$
      00058B                       1596 00200$:
                           0004D4  1597 	C$fuzzy.h$1058$1_0$41 ==.
                                   1598 ;	../../fuzzy.h:1058: args[index]
      00058B C0 02            [24] 1599 	push	ar2
      00058D E5 08            [12] 1600 	mov	a,_bp
      00058F 24 0E            [12] 1601 	add	a,#0x0e
      000591 F8               [12] 1602 	mov	r0,a
      000592 E6               [12] 1603 	mov	a,@r0
      000593 26               [12] 1604 	add	a,@r0
      000594 FD               [12] 1605 	mov	r5,a
      000595 08               [12] 1606 	inc	r0
      000596 E6               [12] 1607 	mov	a,@r0
      000597 33               [12] 1608 	rlc	a
      000598 FC               [12] 1609 	mov	r4,a
      000599 ED               [12] 1610 	mov	a,r5
      00059A 2D               [12] 1611 	add	a,r5
      00059B FD               [12] 1612 	mov	r5,a
      00059C EC               [12] 1613 	mov	a,r4
      00059D 33               [12] 1614 	rlc	a
      00059E FC               [12] 1615 	mov	r4,a
      00059F A8 08            [24] 1616 	mov	r0,_bp
      0005A1 08               [12] 1617 	inc	r0
      0005A2 ED               [12] 1618 	mov	a,r5
      0005A3 26               [12] 1619 	add	a, @r0
      0005A4 FA               [12] 1620 	mov	r2,a
      0005A5 EC               [12] 1621 	mov	a,r4
      0005A6 08               [12] 1622 	inc	r0
      0005A7 36               [12] 1623 	addc	a, @r0
      0005A8 FC               [12] 1624 	mov	r4,a
      0005A9 08               [12] 1625 	inc	r0
      0005AA 86 05            [24] 1626 	mov	ar5,@r0
      0005AC 8A 82            [24] 1627 	mov	dpl,r2
      0005AE 8C 83            [24] 1628 	mov	dph,r4
      0005B0 8D F0            [24] 1629 	mov	b,r5
      0005B2 12 29 94         [24] 1630 	lcall	__gptrget
      0005B5 FA               [12] 1631 	mov	r2,a
      0005B6 A3               [24] 1632 	inc	dptr
      0005B7 12 29 94         [24] 1633 	lcall	__gptrget
      0005BA FC               [12] 1634 	mov	r4,a
      0005BB A3               [24] 1635 	inc	dptr
      0005BC 12 29 94         [24] 1636 	lcall	__gptrget
      0005BF FD               [12] 1637 	mov	r5,a
      0005C0 A3               [24] 1638 	inc	dptr
      0005C1 12 29 94         [24] 1639 	lcall	__gptrget
      0005C4 8A 82            [24] 1640 	mov	dpl,r2
      0005C6 8C 83            [24] 1641 	mov	dph,r4
      0005C8 8D F0            [24] 1642 	mov	b,r5
      0005CA C0 02            [24] 1643 	push	ar2
      0005CC 12 00 EA         [24] 1644 	lcall	_fuzzy_clamp
      0005CF AC 82            [24] 1645 	mov	r4, dpl
      0005D1 AD 83            [24] 1646 	mov	r5, dph
      0005D3 AE F0            [24] 1647 	mov	r6, b
      0005D5 FB               [12] 1648 	mov	r3, a
      0005D6 D0 02            [24] 1649 	pop	ar2
                           000521  1650 	C$fuzzy.h$1061$1_0$41 ==.
                                   1651 ;	../../fuzzy.h:1061: switch (method) {
      0005D8 D0 02            [24] 1652 	pop	ar2
      0005DA E5 08            [12] 1653 	mov	a,_bp
      0005DC 24 05            [12] 1654 	add	a,#0x05
      0005DE F8               [12] 1655 	mov	r0,a
      0005DF E6               [12] 1656 	mov	a,@r0
      0005E0 70 11            [24] 1657 	jnz	00108$
      0005E2 EA               [12] 1658 	mov	a,r2
      0005E3 70 5D            [24] 1659 	jnz	00111$
      0005E5 E5 08            [12] 1660 	mov	a,_bp
      0005E7 24 04            [12] 1661 	add	a,#0x04
      0005E9 F8               [12] 1662 	mov	r0,a
      0005EA E6               [12] 1663 	mov	a,@r0
      0005EB 60 03            [24] 1664 	jz	00203$
      0005ED 02 06 E7         [24] 1665 	ljmp	00112$
      0005F0                       1666 00203$:
      0005F0 02 07 56         [24] 1667 	ljmp	00115$
                           00053C  1668 	C$fuzzy.h$1062$4_0$46 ==.
                                   1669 ;	../../fuzzy.h:1062: case FUZZY_LOGIC_STANDARD:
      0005F3                       1670 00108$:
                           00053C  1671 	C$fuzzy.h$1063$1_0$41 ==.
                                   1672 ;	../../fuzzy.h:1063: if (next > result) {
      0005F3 C0 06            [24] 1673 	push	ar6
      0005F5 C0 05            [24] 1674 	push	ar5
      0005F7 C0 04            [24] 1675 	push	ar4
      0005F9 C0 03            [24] 1676 	push	ar3
      0005FB C0 02            [24] 1677 	push	ar2
      0005FD C0 04            [24] 1678 	push	ar4
      0005FF C0 05            [24] 1679 	push	ar5
      000601 C0 06            [24] 1680 	push	ar6
      000603 C0 03            [24] 1681 	push	ar3
      000605 E5 08            [12] 1682 	mov	a,_bp
      000607 24 0A            [12] 1683 	add	a,#0x0a
      000609 F8               [12] 1684 	mov	r0,a
      00060A 86 82            [24] 1685 	mov	dpl, @r0
      00060C 08               [12] 1686 	inc	r0
      00060D 86 83            [24] 1687 	mov	dph, @r0
      00060F 08               [12] 1688 	inc	r0
      000610 86 F0            [24] 1689 	mov	b, @r0
      000612 08               [12] 1690 	inc	r0
      000613 E6               [12] 1691 	mov	a, @r0
      000614 12 27 68         [24] 1692 	lcall	___fslt
      000617 AF 82            [24] 1693 	mov	r7, dpl
      000619 E5 81            [12] 1694 	mov	a,sp
      00061B 24 FC            [12] 1695 	add	a,#0xfc
      00061D F5 81            [12] 1696 	mov	sp,a
      00061F D0 02            [24] 1697 	pop	ar2
      000621 D0 03            [24] 1698 	pop	ar3
      000623 D0 04            [24] 1699 	pop	ar4
      000625 D0 05            [24] 1700 	pop	ar5
      000627 D0 06            [24] 1701 	pop	ar6
      000629 EF               [12] 1702 	mov	a,r7
      00062A 70 03            [24] 1703 	jnz	00204$
      00062C 02 07 5E         [24] 1704 	ljmp	00120$
      00062F                       1705 00204$:
                           000578  1706 	C$fuzzy.h$1064$5_0$47 ==.
                                   1707 ;	../../fuzzy.h:1064: result = next;
      00062F E5 08            [12] 1708 	mov	a,_bp
      000631 24 0A            [12] 1709 	add	a,#0x0a
      000633 F8               [12] 1710 	mov	r0,a
      000634 A6 04            [24] 1711 	mov	@r0,ar4
      000636 08               [12] 1712 	inc	r0
      000637 A6 05            [24] 1713 	mov	@r0,ar5
      000639 08               [12] 1714 	inc	r0
      00063A A6 06            [24] 1715 	mov	@r0,ar6
      00063C 08               [12] 1716 	inc	r0
      00063D A6 03            [24] 1717 	mov	@r0,ar3
                           000588  1718 	C$fuzzy.h$1066$4_0$46 ==.
                                   1719 ;	../../fuzzy.h:1066: break;
      00063F 02 07 5E         [24] 1720 	ljmp	00120$
                           00058B  1721 	C$fuzzy.h$1068$4_0$46 ==.
                                   1722 ;	../../fuzzy.h:1068: case FUZZY_LOGIC_ALGEBRAIC:
      000642                       1723 00111$:
                           00058B  1724 	C$fuzzy.h$1071$1_0$41 ==.
                                   1725 ;	../../fuzzy.h:1071: next -
      000642 C0 02            [24] 1726 	push	ar2
      000644 C0 06            [24] 1727 	push	ar6
      000646 C0 05            [24] 1728 	push	ar5
      000648 C0 04            [24] 1729 	push	ar4
      00064A C0 03            [24] 1730 	push	ar3
      00064C C0 02            [24] 1731 	push	ar2
      00064E C0 04            [24] 1732 	push	ar4
      000650 C0 05            [24] 1733 	push	ar5
      000652 C0 06            [24] 1734 	push	ar6
      000654 C0 03            [24] 1735 	push	ar3
                           00059F  1736 	C$fuzzy.h$1072$1_0$41 ==.
                                   1737 ;	../../fuzzy.h:1072: result * next;
      000656 E5 08            [12] 1738 	mov	a,_bp
      000658 24 0A            [12] 1739 	add	a,#0x0a
      00065A F8               [12] 1740 	mov	r0,a
      00065B 86 82            [24] 1741 	mov	dpl, @r0
      00065D 08               [12] 1742 	inc	r0
      00065E 86 83            [24] 1743 	mov	dph, @r0
      000660 08               [12] 1744 	inc	r0
      000661 86 F0            [24] 1745 	mov	b, @r0
      000663 08               [12] 1746 	inc	r0
      000664 E6               [12] 1747 	mov	a, @r0
      000665 12 27 BA         [24] 1748 	lcall	___fsadd
      000668 C8               [12] 1749 	xch	a,r0
      000669 E5 08            [12] 1750 	mov	a,_bp
      00066B 24 06            [12] 1751 	add	a,#0x06
      00066D C8               [12] 1752 	xch	a,r0
      00066E A6 82            [24] 1753 	mov	@r0, dpl
      000670 08               [12] 1754 	inc	r0
      000671 A6 83            [24] 1755 	mov	@r0, dph
      000673 08               [12] 1756 	inc	r0
      000674 A6 F0            [24] 1757 	mov	@r0, b
      000676 08               [12] 1758 	inc	r0
      000677 F6               [12] 1759 	mov	@r0,a
      000678 E5 81            [12] 1760 	mov	a,sp
      00067A 24 FC            [12] 1761 	add	a,#0xfc
      00067C F5 81            [12] 1762 	mov	sp,a
      00067E D0 02            [24] 1763 	pop	ar2
      000680 D0 03            [24] 1764 	pop	ar3
      000682 D0 04            [24] 1765 	pop	ar4
      000684 D0 05            [24] 1766 	pop	ar5
      000686 D0 06            [24] 1767 	pop	ar6
      000688 C0 04            [24] 1768 	push	ar4
      00068A C0 05            [24] 1769 	push	ar5
      00068C C0 06            [24] 1770 	push	ar6
      00068E C0 03            [24] 1771 	push	ar3
      000690 E5 08            [12] 1772 	mov	a,_bp
      000692 24 0A            [12] 1773 	add	a,#0x0a
      000694 F8               [12] 1774 	mov	r0,a
      000695 86 82            [24] 1775 	mov	dpl, @r0
      000697 08               [12] 1776 	inc	r0
      000698 86 83            [24] 1777 	mov	dph, @r0
      00069A 08               [12] 1778 	inc	r0
      00069B 86 F0            [24] 1779 	mov	b, @r0
      00069D 08               [12] 1780 	inc	r0
      00069E E6               [12] 1781 	mov	a, @r0
      00069F 12 26 38         [24] 1782 	lcall	___fsmul
      0006A2 AA 82            [24] 1783 	mov	r2, dpl
      0006A4 AB 83            [24] 1784 	mov	r3, dph
      0006A6 AE F0            [24] 1785 	mov	r6, b
      0006A8 FF               [12] 1786 	mov	r7, a
      0006A9 E5 81            [12] 1787 	mov	a,sp
      0006AB 24 FC            [12] 1788 	add	a,#0xfc
      0006AD F5 81            [12] 1789 	mov	sp,a
      0006AF C0 02            [24] 1790 	push	ar2
      0006B1 C0 02            [24] 1791 	push	ar2
      0006B3 C0 03            [24] 1792 	push	ar3
      0006B5 C0 06            [24] 1793 	push	ar6
      0006B7 C0 07            [24] 1794 	push	ar7
                           000602  1795 	C$fuzzy.h$1073$1_0$41 ==.
                                   1796 ;	../../fuzzy.h:1073: break;
      0006B9 E5 08            [12] 1797 	mov	a,_bp
      0006BB 24 06            [12] 1798 	add	a,#0x06
      0006BD F8               [12] 1799 	mov	r0,a
      0006BE 86 82            [24] 1800 	mov	dpl, @r0
      0006C0 08               [12] 1801 	inc	r0
      0006C1 86 83            [24] 1802 	mov	dph, @r0
      0006C3 08               [12] 1803 	inc	r0
      0006C4 86 F0            [24] 1804 	mov	b, @r0
      0006C6 08               [12] 1805 	inc	r0
      0006C7 E6               [12] 1806 	mov	a, @r0
      0006C8 12 26 2D         [24] 1807 	lcall	___fssub
      0006CB C8               [12] 1808 	xch	a,r0
      0006CC E5 08            [12] 1809 	mov	a,_bp
      0006CE 24 0A            [12] 1810 	add	a,#0x0a
      0006D0 C8               [12] 1811 	xch	a,r0
      0006D1 A6 82            [24] 1812 	mov	@r0, dpl
      0006D3 08               [12] 1813 	inc	r0
      0006D4 A6 83            [24] 1814 	mov	@r0, dph
      0006D6 08               [12] 1815 	inc	r0
      0006D7 A6 F0            [24] 1816 	mov	@r0, b
      0006D9 08               [12] 1817 	inc	r0
      0006DA F6               [12] 1818 	mov	@r0,a
      0006DB E5 81            [12] 1819 	mov	a,sp
      0006DD 24 FC            [12] 1820 	add	a,#0xfc
      0006DF F5 81            [12] 1821 	mov	sp,a
      0006E1 D0 02            [24] 1822 	pop	ar2
      0006E3 D0 02            [24] 1823 	pop	ar2
                           00062E  1824 	C$fuzzy.h$1075$4_0$46 ==.
                                   1825 ;	../../fuzzy.h:1075: case FUZZY_LOGIC_BOUNDED:
      0006E5 80 77            [24] 1826 	sjmp	00120$
      0006E7                       1827 00112$:
                           000630  1828 	C$fuzzy.h$1077$1_0$41 ==.
                                   1829 ;	../../fuzzy.h:1077: next;
      0006E7 C0 02            [24] 1830 	push	ar2
      0006E9 C0 04            [24] 1831 	push	ar4
      0006EB C0 05            [24] 1832 	push	ar5
      0006ED C0 06            [24] 1833 	push	ar6
      0006EF C0 03            [24] 1834 	push	ar3
                           00063A  1835 	C$fuzzy.h$1079$1_0$41 ==.
                                   1836 ;	../../fuzzy.h:1079: if (result > LEVEL_HI) {
      0006F1 E5 08            [12] 1837 	mov	a,_bp
      0006F3 24 0A            [12] 1838 	add	a,#0x0a
      0006F5 F8               [12] 1839 	mov	r0,a
      0006F6 86 82            [24] 1840 	mov	dpl, @r0
      0006F8 08               [12] 1841 	inc	r0
      0006F9 86 83            [24] 1842 	mov	dph, @r0
      0006FB 08               [12] 1843 	inc	r0
      0006FC 86 F0            [24] 1844 	mov	b, @r0
      0006FE 08               [12] 1845 	inc	r0
      0006FF E6               [12] 1846 	mov	a, @r0
      000700 12 27 BA         [24] 1847 	lcall	___fsadd
      000703 C8               [12] 1848 	xch	a,r0
      000704 E5 08            [12] 1849 	mov	a,_bp
      000706 24 0A            [12] 1850 	add	a,#0x0a
      000708 C8               [12] 1851 	xch	a,r0
      000709 A6 82            [24] 1852 	mov	@r0, dpl
      00070B 08               [12] 1853 	inc	r0
      00070C A6 83            [24] 1854 	mov	@r0, dph
      00070E 08               [12] 1855 	inc	r0
      00070F A6 F0            [24] 1856 	mov	@r0, b
      000711 08               [12] 1857 	inc	r0
      000712 F6               [12] 1858 	mov	@r0,a
      000713 E5 81            [12] 1859 	mov	a,sp
      000715 24 FC            [12] 1860 	add	a,#0xfc
      000717 F5 81            [12] 1861 	mov	sp,a
      000719 E5 08            [12] 1862 	mov	a,_bp
      00071B 24 0A            [12] 1863 	add	a,#0x0a
      00071D F8               [12] 1864 	mov	r0,a
      00071E E6               [12] 1865 	mov	a,@r0
      00071F C0 E0            [24] 1866 	push	acc
      000721 08               [12] 1867 	inc	r0
      000722 E6               [12] 1868 	mov	a,@r0
      000723 C0 E0            [24] 1869 	push	acc
      000725 08               [12] 1870 	inc	r0
      000726 E6               [12] 1871 	mov	a,@r0
      000727 C0 E0            [24] 1872 	push	acc
      000729 08               [12] 1873 	inc	r0
      00072A E6               [12] 1874 	mov	a,@r0
      00072B C0 E0            [24] 1875 	push	acc
      00072D 90 00 00         [24] 1876 	mov	dptr,#0x0000
      000730 75 F0 80         [24] 1877 	mov	b, #0x80
      000733 74 3F            [12] 1878 	mov	a, #0x3f
      000735 12 27 68         [24] 1879 	lcall	___fslt
      000738 AF 82            [24] 1880 	mov	r7, dpl
      00073A E5 81            [12] 1881 	mov	a,sp
      00073C 24 FC            [12] 1882 	add	a,#0xfc
      00073E F5 81            [12] 1883 	mov	sp,a
      000740 D0 02            [24] 1884 	pop	ar2
      000742 EF               [12] 1885 	mov	a,r7
      000743 60 19            [24] 1886 	jz	00120$
                           00068E  1887 	C$fuzzy.h$1080$5_0$48 ==.
                                   1888 ;	../../fuzzy.h:1080: result = LEVEL_HI;
      000745 E5 08            [12] 1889 	mov	a,_bp
      000747 24 0A            [12] 1890 	add	a,#0x0a
      000749 F8               [12] 1891 	mov	r0,a
      00074A E4               [12] 1892 	clr	a
      00074B F6               [12] 1893 	mov	@r0,a
      00074C 08               [12] 1894 	inc	r0
      00074D F6               [12] 1895 	mov	@r0,a
      00074E 08               [12] 1896 	inc	r0
      00074F 76 80            [12] 1897 	mov	@r0,#0x80
      000751 08               [12] 1898 	inc	r0
      000752 76 3F            [12] 1899 	mov	@r0,#0x3f
                           00069D  1900 	C$fuzzy.h$1082$4_0$46 ==.
                                   1901 ;	../../fuzzy.h:1082: break;
                           00069D  1902 	C$fuzzy.h$1084$4_0$46 ==.
                                   1903 ;	../../fuzzy.h:1084: default:
      000754 80 08            [24] 1904 	sjmp	00120$
      000756                       1905 00115$:
                           00069F  1906 	C$fuzzy.h$1085$4_0$46 ==.
                                   1907 ;	../../fuzzy.h:1085: return LEVEL_LO;
      000756 90 00 00         [24] 1908 	mov	dptr,#0x0000
      000759 E4               [12] 1909 	clr	a
      00075A F5 F0            [12] 1910 	mov	b,a
                           0006A5  1911 	C$fuzzy.h$1086$3_0$45 ==.
                                   1912 ;	../../fuzzy.h:1086: }
      00075C 80 20            [24] 1913 	sjmp	00121$
      00075E                       1914 00120$:
                           0006A7  1915 	C$fuzzy.h$1054$2_0$44 ==.
                                   1916 ;	../../fuzzy.h:1054: index++
      00075E E5 08            [12] 1917 	mov	a,_bp
      000760 24 0E            [12] 1918 	add	a,#0x0e
      000762 F8               [12] 1919 	mov	r0,a
      000763 06               [12] 1920 	inc	@r0
      000764 B6 00 02         [24] 1921 	cjne	@r0,#0x00,00206$
      000767 08               [12] 1922 	inc	r0
      000768 06               [12] 1923 	inc	@r0
      000769                       1924 00206$:
      000769 02 05 75         [24] 1925 	ljmp	00119$
      00076C                       1926 00117$:
                           0006B5  1927 	C$fuzzy.h$1090$1_0$41 ==.
                                   1928 ;	../../fuzzy.h:1090: result
      00076C E5 08            [12] 1929 	mov	a,_bp
      00076E 24 0A            [12] 1930 	add	a,#0x0a
      000770 F8               [12] 1931 	mov	r0,a
      000771 86 82            [24] 1932 	mov	dpl, @r0
      000773 08               [12] 1933 	inc	r0
      000774 86 83            [24] 1934 	mov	dph, @r0
      000776 08               [12] 1935 	inc	r0
      000777 86 F0            [24] 1936 	mov	b, @r0
      000779 08               [12] 1937 	inc	r0
      00077A E6               [12] 1938 	mov	a, @r0
      00077B 12 00 EA         [24] 1939 	lcall	_fuzzy_clamp
      00077E                       1940 00121$:
                           0006C7  1941 	C$fuzzy.h$1092$1_0$41 ==.
                                   1942 ;	../../fuzzy.h:1092: }
      00077E 85 08 81         [24] 1943 	mov	sp,_bp
      000781 D0 08            [24] 1944 	pop	_bp
                           0006CC  1945 	C$fuzzy.h$1092$1_0$41 ==.
                           0006CC  1946 	XG$fuzzy_or_array$0$0 ==.
      000783 22               [24] 1947 	ret
                                   1948 ;------------------------------------------------------------
                                   1949 ;Allocation info for local variables in function 'fuzzy_sugeno_weighted_average_array'
                                   1950 ;------------------------------------------------------------
                                   1951 ;values        Allocated to stack - _bp -5 +3 
                                   1952 ;value_count   Allocated to stack - _bp +1 +2 
                                   1953 ;weighted_sum  Allocated to stack - _bp +3 +4 
                                   1954 ;firing_sum    Allocated to stack - _bp +7 +4 
                                   1955 ;firing_strength Allocated to stack - _bp +11 +4 
                                   1956 ;consequent    Allocated to registers r4 r5 r3 r2 
                                   1957 ;index         Allocated to registers r6 r7 
                                   1958 ;------------------------------------------------------------
                           0006CD  1959 	G$fuzzy_sugeno_weighted_average_array$0$0 ==.
                           0006CD  1960 	C$fuzzy.h$1103$1_0$50 ==.
                                   1961 ;	../../fuzzy.h:1103: float fuzzy_sugeno_weighted_average_array(
                                   1962 ;	-----------------------------------------
                                   1963 ;	 function fuzzy_sugeno_weighted_average_array
                                   1964 ;	-----------------------------------------
      000784                       1965 _fuzzy_sugeno_weighted_average_array:
      000784 C0 08            [24] 1966 	push	_bp
      000786 85 81 08         [24] 1967 	mov	_bp,sp
      000789 C0 82            [24] 1968 	push	dpl
      00078B C0 83            [24] 1969 	push	dph
      00078D E5 81            [12] 1970 	mov	a,sp
      00078F 24 0C            [12] 1971 	add	a,#0x0c
      000791 F5 81            [12] 1972 	mov	sp,a
                           0006DC  1973 	C$fuzzy.h$1116$1_0$50 ==.
                                   1974 ;	../../fuzzy.h:1116: values == NULL ||
      000793 E5 08            [12] 1975 	mov	a,_bp
      000795 24 FB            [12] 1976 	add	a,#0xfb
      000797 F8               [12] 1977 	mov	r0,a
      000798 E6               [12] 1978 	mov	a,@r0
      000799 08               [12] 1979 	inc	r0
      00079A 46               [12] 1980 	orl	a,@r0
      00079B 60 0F            [24] 1981 	jz	00101$
                           0006E6  1982 	C$fuzzy.h$1117$1_0$50 ==.
                                   1983 ;	../../fuzzy.h:1117: value_count == 0u ||
      00079D A8 08            [24] 1984 	mov	r0,_bp
      00079F 08               [12] 1985 	inc	r0
      0007A0 E6               [12] 1986 	mov	a,@r0
      0007A1 08               [12] 1987 	inc	r0
      0007A2 46               [12] 1988 	orl	a,@r0
      0007A3 60 07            [24] 1989 	jz	00101$
                           0006EE  1990 	C$fuzzy.h$1118$1_0$50 ==.
                                   1991 ;	../../fuzzy.h:1118: value_count % 2u != 0u
      0007A5 A8 08            [24] 1992 	mov	r0,_bp
      0007A7 08               [12] 1993 	inc	r0
      0007A8 E6               [12] 1994 	mov	a,@r0
      0007A9 30 E0 09         [24] 1995 	jnb	acc.0,00102$
      0007AC                       1996 00101$:
                           0006F5  1997 	C$fuzzy.h$1120$2_0$51 ==.
                                   1998 ;	../../fuzzy.h:1120: return 0.0f;
      0007AC 90 00 00         [24] 1999 	mov	dptr,#0x0000
      0007AF E4               [12] 2000 	clr	a
      0007B0 F5 F0            [12] 2001 	mov	b,a
      0007B2 02 09 7F         [24] 2002 	ljmp	00111$
      0007B5                       2003 00102$:
                           0006FE  2004 	C$fuzzy.h$1124$1_0$50 ==.
                                   2005 ;	../../fuzzy.h:1124: 0.0f;
      0007B5 E5 08            [12] 2006 	mov	a,_bp
      0007B7 24 03            [12] 2007 	add	a,#0x03
      0007B9 F8               [12] 2008 	mov	r0,a
      0007BA E4               [12] 2009 	clr	a
      0007BB F6               [12] 2010 	mov	@r0,a
      0007BC 08               [12] 2011 	inc	r0
      0007BD F6               [12] 2012 	mov	@r0,a
      0007BE 08               [12] 2013 	inc	r0
      0007BF F6               [12] 2014 	mov	@r0,a
      0007C0 08               [12] 2015 	inc	r0
      0007C1 F6               [12] 2016 	mov	@r0,a
                           00070B  2017 	C$fuzzy.h$1127$1_0$50 ==.
                                   2018 ;	../../fuzzy.h:1127: 0.0f;
      0007C2 E5 08            [12] 2019 	mov	a,_bp
      0007C4 24 07            [12] 2020 	add	a,#0x07
      0007C6 F8               [12] 2021 	mov	r0,a
      0007C7 E4               [12] 2022 	clr	a
      0007C8 F6               [12] 2023 	mov	@r0,a
      0007C9 08               [12] 2024 	inc	r0
      0007CA F6               [12] 2025 	mov	@r0,a
      0007CB 08               [12] 2026 	inc	r0
      0007CC F6               [12] 2027 	mov	@r0,a
      0007CD 08               [12] 2028 	inc	r0
      0007CE F6               [12] 2029 	mov	@r0,a
                           000718  2030 	C$fuzzy.h$1130$1_0$50 ==.
                                   2031 ;	../../fuzzy.h:1130: index = 0u;
      0007CF FE               [12] 2032 	mov	r6,a
      0007D0 FF               [12] 2033 	mov	r7,a
      0007D1                       2034 00109$:
                           00071A  2035 	C$fuzzy.h$1131$2_0$52 ==.
                                   2036 ;	../../fuzzy.h:1131: index < value_count;
      0007D1 A8 08            [24] 2037 	mov	r0,_bp
      0007D3 08               [12] 2038 	inc	r0
      0007D4 C3               [12] 2039 	clr	c
      0007D5 EE               [12] 2040 	mov	a,r6
      0007D6 96               [12] 2041 	subb	a,@r0
      0007D7 EF               [12] 2042 	mov	a,r7
      0007D8 08               [12] 2043 	inc	r0
      0007D9 96               [12] 2044 	subb	a,@r0
      0007DA 40 03            [24] 2045 	jc	00147$
      0007DC 02 09 12         [24] 2046 	ljmp	00105$
      0007DF                       2047 00147$:
                           000728  2048 	C$fuzzy.h$1136$3_0$53 ==.
                                   2049 ;	../../fuzzy.h:1136: values[index]
      0007DF EE               [12] 2050 	mov	a,r6
      0007E0 2E               [12] 2051 	add	a,r6
      0007E1 FC               [12] 2052 	mov	r4,a
      0007E2 EF               [12] 2053 	mov	a,r7
      0007E3 33               [12] 2054 	rlc	a
      0007E4 FD               [12] 2055 	mov	r5,a
      0007E5 EC               [12] 2056 	mov	a,r4
      0007E6 2C               [12] 2057 	add	a,r4
      0007E7 FC               [12] 2058 	mov	r4,a
      0007E8 ED               [12] 2059 	mov	a,r5
      0007E9 33               [12] 2060 	rlc	a
      0007EA FD               [12] 2061 	mov	r5,a
      0007EB E5 08            [12] 2062 	mov	a,_bp
      0007ED 24 FB            [12] 2063 	add	a,#0xfb
      0007EF F8               [12] 2064 	mov	r0,a
      0007F0 EC               [12] 2065 	mov	a,r4
      0007F1 26               [12] 2066 	add	a, @r0
      0007F2 FC               [12] 2067 	mov	r4,a
      0007F3 ED               [12] 2068 	mov	a,r5
      0007F4 08               [12] 2069 	inc	r0
      0007F5 36               [12] 2070 	addc	a, @r0
      0007F6 FD               [12] 2071 	mov	r5,a
      0007F7 08               [12] 2072 	inc	r0
      0007F8 86 03            [24] 2073 	mov	ar3,@r0
      0007FA 8C 82            [24] 2074 	mov	dpl,r4
      0007FC 8D 83            [24] 2075 	mov	dph,r5
      0007FE 8B F0            [24] 2076 	mov	b,r3
      000800 12 29 94         [24] 2077 	lcall	__gptrget
      000803 FC               [12] 2078 	mov	r4,a
      000804 A3               [24] 2079 	inc	dptr
      000805 12 29 94         [24] 2080 	lcall	__gptrget
      000808 FD               [12] 2081 	mov	r5,a
      000809 A3               [24] 2082 	inc	dptr
      00080A 12 29 94         [24] 2083 	lcall	__gptrget
      00080D FB               [12] 2084 	mov	r3,a
      00080E A3               [24] 2085 	inc	dptr
      00080F 12 29 94         [24] 2086 	lcall	__gptrget
      000812 8C 82            [24] 2087 	mov	dpl,r4
      000814 8D 83            [24] 2088 	mov	dph,r5
      000816 8B F0            [24] 2089 	mov	b,r3
      000818 C0 07            [24] 2090 	push	ar7
      00081A C0 06            [24] 2091 	push	ar6
      00081C 12 00 EA         [24] 2092 	lcall	_fuzzy_clamp
      00081F C8               [12] 2093 	xch	a,r0
      000820 E5 08            [12] 2094 	mov	a,_bp
      000822 24 0B            [12] 2095 	add	a,#0x0b
      000824 C8               [12] 2096 	xch	a,r0
      000825 A6 82            [24] 2097 	mov	@r0, dpl
      000827 08               [12] 2098 	inc	r0
      000828 A6 83            [24] 2099 	mov	@r0, dph
      00082A 08               [12] 2100 	inc	r0
      00082B A6 F0            [24] 2101 	mov	@r0, b
      00082D 08               [12] 2102 	inc	r0
      00082E F6               [12] 2103 	mov	@r0,a
      00082F D0 06            [24] 2104 	pop	ar6
      000831 D0 07            [24] 2105 	pop	ar7
                           00077C  2106 	C$fuzzy.h$1140$3_0$53 ==.
                                   2107 ;	../../fuzzy.h:1140: values[index + 1u];
      000833 74 01            [12] 2108 	mov	a,#0x01
      000835 2E               [12] 2109 	add	a, r6
      000836 FC               [12] 2110 	mov	r4,a
      000837 E4               [12] 2111 	clr	a
      000838 3F               [12] 2112 	addc	a, r7
      000839 FD               [12] 2113 	mov	r5,a
      00083A EC               [12] 2114 	mov	a,r4
      00083B 2C               [12] 2115 	add	a,r4
      00083C FC               [12] 2116 	mov	r4,a
      00083D ED               [12] 2117 	mov	a,r5
      00083E 33               [12] 2118 	rlc	a
      00083F FD               [12] 2119 	mov	r5,a
      000840 EC               [12] 2120 	mov	a,r4
      000841 2C               [12] 2121 	add	a,r4
      000842 FC               [12] 2122 	mov	r4,a
      000843 ED               [12] 2123 	mov	a,r5
      000844 33               [12] 2124 	rlc	a
      000845 FD               [12] 2125 	mov	r5,a
      000846 E5 08            [12] 2126 	mov	a,_bp
      000848 24 FB            [12] 2127 	add	a,#0xfb
      00084A F8               [12] 2128 	mov	r0,a
      00084B EC               [12] 2129 	mov	a,r4
      00084C 26               [12] 2130 	add	a, @r0
      00084D FC               [12] 2131 	mov	r4,a
      00084E ED               [12] 2132 	mov	a,r5
      00084F 08               [12] 2133 	inc	r0
      000850 36               [12] 2134 	addc	a, @r0
      000851 FD               [12] 2135 	mov	r5,a
      000852 08               [12] 2136 	inc	r0
      000853 86 03            [24] 2137 	mov	ar3,@r0
      000855 8C 82            [24] 2138 	mov	dpl,r4
      000857 8D 83            [24] 2139 	mov	dph,r5
      000859 8B F0            [24] 2140 	mov	b,r3
      00085B 12 29 94         [24] 2141 	lcall	__gptrget
      00085E FC               [12] 2142 	mov	r4,a
      00085F A3               [24] 2143 	inc	dptr
      000860 12 29 94         [24] 2144 	lcall	__gptrget
      000863 FD               [12] 2145 	mov	r5,a
      000864 A3               [24] 2146 	inc	dptr
      000865 12 29 94         [24] 2147 	lcall	__gptrget
      000868 FB               [12] 2148 	mov	r3,a
      000869 A3               [24] 2149 	inc	dptr
      00086A 12 29 94         [24] 2150 	lcall	__gptrget
      00086D FA               [12] 2151 	mov	r2,a
                           0007B7  2152 	C$fuzzy.h$1145$1_0$50 ==.
                                   2153 ;	../../fuzzy.h:1145: consequent;
      00086E C0 07            [24] 2154 	push	ar7
      000870 C0 06            [24] 2155 	push	ar6
      000872 C0 04            [24] 2156 	push	ar4
      000874 C0 05            [24] 2157 	push	ar5
      000876 C0 03            [24] 2158 	push	ar3
      000878 C0 02            [24] 2159 	push	ar2
      00087A E5 08            [12] 2160 	mov	a,_bp
      00087C 24 0B            [12] 2161 	add	a,#0x0b
      00087E F8               [12] 2162 	mov	r0,a
      00087F 86 82            [24] 2163 	mov	dpl, @r0
      000881 08               [12] 2164 	inc	r0
      000882 86 83            [24] 2165 	mov	dph, @r0
      000884 08               [12] 2166 	inc	r0
      000885 86 F0            [24] 2167 	mov	b, @r0
      000887 08               [12] 2168 	inc	r0
      000888 E6               [12] 2169 	mov	a, @r0
      000889 12 26 38         [24] 2170 	lcall	___fsmul
      00088C AA 82            [24] 2171 	mov	r2, dpl
      00088E AB 83            [24] 2172 	mov	r3, dph
      000890 AC F0            [24] 2173 	mov	r4, b
      000892 FD               [12] 2174 	mov	r5, a
      000893 E5 81            [12] 2175 	mov	a,sp
      000895 24 FC            [12] 2176 	add	a,#0xfc
      000897 F5 81            [12] 2177 	mov	sp,a
      000899 C0 02            [24] 2178 	push	ar2
      00089B C0 03            [24] 2179 	push	ar3
      00089D C0 04            [24] 2180 	push	ar4
      00089F C0 05            [24] 2181 	push	ar5
                           0007EA  2182 	C$fuzzy.h$1148$1_0$50 ==.
                                   2183 ;	../../fuzzy.h:1148: firing_strength;
      0008A1 E5 08            [12] 2184 	mov	a,_bp
      0008A3 24 03            [12] 2185 	add	a,#0x03
      0008A5 F8               [12] 2186 	mov	r0,a
      0008A6 86 82            [24] 2187 	mov	dpl, @r0
      0008A8 08               [12] 2188 	inc	r0
      0008A9 86 83            [24] 2189 	mov	dph, @r0
      0008AB 08               [12] 2190 	inc	r0
      0008AC 86 F0            [24] 2191 	mov	b, @r0
      0008AE 08               [12] 2192 	inc	r0
      0008AF E6               [12] 2193 	mov	a, @r0
      0008B0 12 27 BA         [24] 2194 	lcall	___fsadd
      0008B3 A8 08            [24] 2195 	mov	r0,_bp
      0008B5 08               [12] 2196 	inc	r0
      0008B6 08               [12] 2197 	inc	r0
      0008B7 08               [12] 2198 	inc	r0
      0008B8 A6 82            [24] 2199 	mov	@r0, dpl
      0008BA 08               [12] 2200 	inc	r0
      0008BB A6 83            [24] 2201 	mov	@r0, dph
      0008BD 08               [12] 2202 	inc	r0
      0008BE A6 F0            [24] 2203 	mov	@r0, b
      0008C0 08               [12] 2204 	inc	r0
      0008C1 F6               [12] 2205 	mov	@r0,a
      0008C2 E5 81            [12] 2206 	mov	a,sp
      0008C4 24 FC            [12] 2207 	add	a,#0xfc
      0008C6 F5 81            [12] 2208 	mov	sp,a
      0008C8 E5 08            [12] 2209 	mov	a,_bp
      0008CA 24 0B            [12] 2210 	add	a,#0x0b
      0008CC F8               [12] 2211 	mov	r0,a
      0008CD E6               [12] 2212 	mov	a,@r0
      0008CE C0 E0            [24] 2213 	push	acc
      0008D0 08               [12] 2214 	inc	r0
      0008D1 E6               [12] 2215 	mov	a,@r0
      0008D2 C0 E0            [24] 2216 	push	acc
      0008D4 08               [12] 2217 	inc	r0
      0008D5 E6               [12] 2218 	mov	a,@r0
      0008D6 C0 E0            [24] 2219 	push	acc
      0008D8 08               [12] 2220 	inc	r0
      0008D9 E6               [12] 2221 	mov	a,@r0
      0008DA C0 E0            [24] 2222 	push	acc
                           000825  2223 	C$fuzzy.h$1133$1_0$50 ==.
                                   2224 ;	../../fuzzy.h:1133: ) {
      0008DC E5 08            [12] 2225 	mov	a,_bp
      0008DE 24 07            [12] 2226 	add	a,#0x07
      0008E0 F8               [12] 2227 	mov	r0,a
      0008E1 86 82            [24] 2228 	mov	dpl, @r0
      0008E3 08               [12] 2229 	inc	r0
      0008E4 86 83            [24] 2230 	mov	dph, @r0
      0008E6 08               [12] 2231 	inc	r0
      0008E7 86 F0            [24] 2232 	mov	b, @r0
      0008E9 08               [12] 2233 	inc	r0
      0008EA E6               [12] 2234 	mov	a, @r0
      0008EB 12 27 BA         [24] 2235 	lcall	___fsadd
      0008EE C8               [12] 2236 	xch	a,r0
      0008EF E5 08            [12] 2237 	mov	a,_bp
      0008F1 24 07            [12] 2238 	add	a,#0x07
      0008F3 C8               [12] 2239 	xch	a,r0
      0008F4 A6 82            [24] 2240 	mov	@r0, dpl
      0008F6 08               [12] 2241 	inc	r0
      0008F7 A6 83            [24] 2242 	mov	@r0, dph
      0008F9 08               [12] 2243 	inc	r0
      0008FA A6 F0            [24] 2244 	mov	@r0, b
      0008FC 08               [12] 2245 	inc	r0
      0008FD F6               [12] 2246 	mov	@r0,a
      0008FE E5 81            [12] 2247 	mov	a,sp
      000900 24 FC            [12] 2248 	add	a,#0xfc
      000902 F5 81            [12] 2249 	mov	sp,a
      000904 D0 06            [24] 2250 	pop	ar6
      000906 D0 07            [24] 2251 	pop	ar7
      000908 74 02            [12] 2252 	mov	a,#0x02
      00090A 2E               [12] 2253 	add	a, r6
      00090B FE               [12] 2254 	mov	r6,a
      00090C E4               [12] 2255 	clr	a
      00090D 3F               [12] 2256 	addc	a, r7
      00090E FF               [12] 2257 	mov	r7,a
      00090F 02 07 D1         [24] 2258 	ljmp	00109$
      000912                       2259 00105$:
                           00085B  2260 	C$fuzzy.h$1151$1_0$50 ==.
                                   2261 ;	../../fuzzy.h:1151: if (firing_sum <= LEVEL_LO) {
      000912 E5 08            [12] 2262 	mov	a,_bp
      000914 24 07            [12] 2263 	add	a,#0x07
      000916 F8               [12] 2264 	mov	r0,a
      000917 E6               [12] 2265 	mov	a,@r0
      000918 C0 E0            [24] 2266 	push	acc
      00091A 08               [12] 2267 	inc	r0
      00091B E6               [12] 2268 	mov	a,@r0
      00091C C0 E0            [24] 2269 	push	acc
      00091E 08               [12] 2270 	inc	r0
      00091F E6               [12] 2271 	mov	a,@r0
      000920 C0 E0            [24] 2272 	push	acc
      000922 08               [12] 2273 	inc	r0
      000923 E6               [12] 2274 	mov	a,@r0
      000924 C0 E0            [24] 2275 	push	acc
      000926 90 00 00         [24] 2276 	mov	dptr,#0x0000
      000929 E4               [12] 2277 	clr	a
      00092A F5 F0            [12] 2278 	mov	b,a
      00092C 12 27 68         [24] 2279 	lcall	___fslt
      00092F E5 81            [12] 2280 	mov	a,sp
      000931 24 FC            [12] 2281 	add	a,#0xfc
      000933 F5 81            [12] 2282 	mov	sp,a
      000935 E5 82            [12] 2283 	mov	a, dpl
      000937 24 FF            [12] 2284 	add	a,#0xff
      000939 92 00            [24] 2285 	mov	b0,c
      00093B 40 08            [24] 2286 	jc	00107$
                           000886  2287 	C$fuzzy.h$1152$2_0$54 ==.
                                   2288 ;	../../fuzzy.h:1152: return 0.0f;
      00093D 90 00 00         [24] 2289 	mov	dptr,#0x0000
      000940 E4               [12] 2290 	clr	a
      000941 F5 F0            [12] 2291 	mov	b,a
      000943 80 3A            [24] 2292 	sjmp	00111$
      000945                       2293 00107$:
                           00088E  2294 	C$fuzzy.h$1156$1_0$50 ==.
                                   2295 ;	../../fuzzy.h:1156: firing_sum;
      000945 E5 08            [12] 2296 	mov	a,_bp
      000947 24 07            [12] 2297 	add	a,#0x07
      000949 F8               [12] 2298 	mov	r0,a
      00094A E6               [12] 2299 	mov	a,@r0
      00094B C0 E0            [24] 2300 	push	acc
      00094D 08               [12] 2301 	inc	r0
      00094E E6               [12] 2302 	mov	a,@r0
      00094F C0 E0            [24] 2303 	push	acc
      000951 08               [12] 2304 	inc	r0
      000952 E6               [12] 2305 	mov	a,@r0
      000953 C0 E0            [24] 2306 	push	acc
      000955 08               [12] 2307 	inc	r0
      000956 E6               [12] 2308 	mov	a,@r0
      000957 C0 E0            [24] 2309 	push	acc
      000959 E5 08            [12] 2310 	mov	a,_bp
      00095B 24 03            [12] 2311 	add	a,#0x03
      00095D F8               [12] 2312 	mov	r0,a
      00095E 86 82            [24] 2313 	mov	dpl, @r0
      000960 08               [12] 2314 	inc	r0
      000961 86 83            [24] 2315 	mov	dph, @r0
      000963 08               [12] 2316 	inc	r0
      000964 86 F0            [24] 2317 	mov	b, @r0
      000966 08               [12] 2318 	inc	r0
      000967 E6               [12] 2319 	mov	a, @r0
      000968 12 28 D1         [24] 2320 	lcall	___fsdiv
      00096B AC 82            [24] 2321 	mov	r4, dpl
      00096D AD 83            [24] 2322 	mov	r5, dph
      00096F AE F0            [24] 2323 	mov	r6, b
      000971 FF               [12] 2324 	mov	r7, a
      000972 E5 81            [12] 2325 	mov	a,sp
      000974 24 FC            [12] 2326 	add	a,#0xfc
      000976 F5 81            [12] 2327 	mov	sp,a
      000978 8C 82            [24] 2328 	mov	dpl, r4
      00097A 8D 83            [24] 2329 	mov	dph, r5
      00097C 8E F0            [24] 2330 	mov	b, r6
      00097E EF               [12] 2331 	mov	a, r7
      00097F                       2332 00111$:
                           0008C8  2333 	C$fuzzy.h$1157$1_0$50 ==.
                                   2334 ;	../../fuzzy.h:1157: }
      00097F 85 08 81         [24] 2335 	mov	sp,_bp
      000982 D0 08            [24] 2336 	pop	_bp
                           0008CD  2337 	C$fuzzy.h$1157$1_0$50 ==.
                           0008CD  2338 	XG$fuzzy_sugeno_weighted_average_array$0$0 ==.
      000984 22               [24] 2339 	ret
                                   2340 ;------------------------------------------------------------
                                   2341 ;Allocation info for local variables in function 'fuzzy_sugeno_weighted_sum_array'
                                   2342 ;------------------------------------------------------------
                                   2343 ;values        Allocated to stack - _bp -5 +3 
                                   2344 ;value_count   Allocated to registers r6 r7 
                                   2345 ;weighted_sum  Allocated to stack - _bp +1 +4 
                                   2346 ;firing_strength Allocated to stack - _bp +5 +4 
                                   2347 ;consequent    Allocated to registers r6 r7 r3 r2 
                                   2348 ;index         Allocated to registers r4 r5 
                                   2349 ;------------------------------------------------------------
                           0008CE  2350 	G$fuzzy_sugeno_weighted_sum_array$0$0 ==.
                           0008CE  2351 	C$fuzzy.h$1167$1_0$56 ==.
                                   2352 ;	../../fuzzy.h:1167: float fuzzy_sugeno_weighted_sum_array(
                                   2353 ;	-----------------------------------------
                                   2354 ;	 function fuzzy_sugeno_weighted_sum_array
                                   2355 ;	-----------------------------------------
      000985                       2356 _fuzzy_sugeno_weighted_sum_array:
      000985 C0 08            [24] 2357 	push	_bp
      000987 E5 81            [12] 2358 	mov	a,sp
      000989 F5 08            [12] 2359 	mov	_bp,a
      00098B 24 08            [12] 2360 	add	a,#0x08
      00098D F5 81            [12] 2361 	mov	sp,a
      00098F AE 82            [24] 2362 	mov	r6, dpl
      000991 AF 83            [24] 2363 	mov	r7, dph
                           0008DC  2364 	C$fuzzy.h$1179$1_0$56 ==.
                                   2365 ;	../../fuzzy.h:1179: values == NULL ||
      000993 E5 08            [12] 2366 	mov	a,_bp
      000995 24 FB            [12] 2367 	add	a,#0xfb
      000997 F8               [12] 2368 	mov	r0,a
      000998 E6               [12] 2369 	mov	a,@r0
      000999 08               [12] 2370 	inc	r0
      00099A 46               [12] 2371 	orl	a,@r0
      00099B 60 08            [24] 2372 	jz	00101$
                           0008E6  2373 	C$fuzzy.h$1180$1_0$56 ==.
                                   2374 ;	../../fuzzy.h:1180: value_count == 0u ||
      00099D EE               [12] 2375 	mov	a,r6
      00099E 4F               [12] 2376 	orl	a,r7
      00099F 60 04            [24] 2377 	jz	00101$
                           0008EA  2378 	C$fuzzy.h$1181$1_0$56 ==.
                                   2379 ;	../../fuzzy.h:1181: value_count % 2u != 0u
      0009A1 EE               [12] 2380 	mov	a,r6
      0009A2 30 E0 09         [24] 2381 	jnb	acc.0,00102$
      0009A5                       2382 00101$:
                           0008EE  2383 	C$fuzzy.h$1183$2_0$57 ==.
                                   2384 ;	../../fuzzy.h:1183: return 0.0f;
      0009A5 90 00 00         [24] 2385 	mov	dptr,#0x0000
      0009A8 E4               [12] 2386 	clr	a
      0009A9 F5 F0            [12] 2387 	mov	b,a
      0009AB 02 0A E6         [24] 2388 	ljmp	00109$
      0009AE                       2389 00102$:
                           0008F7  2390 	C$fuzzy.h$1187$1_0$56 ==.
                                   2391 ;	../../fuzzy.h:1187: 0.0f;
      0009AE A8 08            [24] 2392 	mov	r0,_bp
      0009B0 08               [12] 2393 	inc	r0
      0009B1 E4               [12] 2394 	clr	a
      0009B2 F6               [12] 2395 	mov	@r0,a
      0009B3 08               [12] 2396 	inc	r0
      0009B4 F6               [12] 2397 	mov	@r0,a
      0009B5 08               [12] 2398 	inc	r0
      0009B6 F6               [12] 2399 	mov	@r0,a
      0009B7 08               [12] 2400 	inc	r0
      0009B8 F6               [12] 2401 	mov	@r0,a
                           000902  2402 	C$fuzzy.h$1190$1_0$56 ==.
                                   2403 ;	../../fuzzy.h:1190: index = 0u;
      0009B9 FC               [12] 2404 	mov	r4,a
      0009BA FD               [12] 2405 	mov	r5,a
      0009BB                       2406 00107$:
                           000904  2407 	C$fuzzy.h$1191$2_0$58 ==.
                                   2408 ;	../../fuzzy.h:1191: index < value_count;
      0009BB C3               [12] 2409 	clr	c
      0009BC EC               [12] 2410 	mov	a,r4
      0009BD 9E               [12] 2411 	subb	a,r6
      0009BE ED               [12] 2412 	mov	a,r5
      0009BF 9F               [12] 2413 	subb	a,r7
      0009C0 40 03            [24] 2414 	jc	00139$
      0009C2 02 0A D9         [24] 2415 	ljmp	00105$
      0009C5                       2416 00139$:
                           00090E  2417 	C$fuzzy.h$1196$1_0$56 ==.
                                   2418 ;	../../fuzzy.h:1196: values[index]
      0009C5 C0 06            [24] 2419 	push	ar6
      0009C7 C0 07            [24] 2420 	push	ar7
      0009C9 EC               [12] 2421 	mov	a,r4
      0009CA 2C               [12] 2422 	add	a,r4
      0009CB FA               [12] 2423 	mov	r2,a
      0009CC ED               [12] 2424 	mov	a,r5
      0009CD 33               [12] 2425 	rlc	a
      0009CE FB               [12] 2426 	mov	r3,a
      0009CF EA               [12] 2427 	mov	a,r2
      0009D0 2A               [12] 2428 	add	a,r2
      0009D1 FA               [12] 2429 	mov	r2,a
      0009D2 EB               [12] 2430 	mov	a,r3
      0009D3 33               [12] 2431 	rlc	a
      0009D4 FB               [12] 2432 	mov	r3,a
      0009D5 E5 08            [12] 2433 	mov	a,_bp
      0009D7 24 FB            [12] 2434 	add	a,#0xfb
      0009D9 F8               [12] 2435 	mov	r0,a
      0009DA EA               [12] 2436 	mov	a,r2
      0009DB 26               [12] 2437 	add	a, @r0
      0009DC FA               [12] 2438 	mov	r2,a
      0009DD EB               [12] 2439 	mov	a,r3
      0009DE 08               [12] 2440 	inc	r0
      0009DF 36               [12] 2441 	addc	a, @r0
      0009E0 FB               [12] 2442 	mov	r3,a
      0009E1 08               [12] 2443 	inc	r0
      0009E2 86 07            [24] 2444 	mov	ar7,@r0
      0009E4 8A 82            [24] 2445 	mov	dpl,r2
      0009E6 8B 83            [24] 2446 	mov	dph,r3
      0009E8 8F F0            [24] 2447 	mov	b,r7
      0009EA 12 29 94         [24] 2448 	lcall	__gptrget
      0009ED FA               [12] 2449 	mov	r2,a
      0009EE A3               [24] 2450 	inc	dptr
      0009EF 12 29 94         [24] 2451 	lcall	__gptrget
      0009F2 FB               [12] 2452 	mov	r3,a
      0009F3 A3               [24] 2453 	inc	dptr
      0009F4 12 29 94         [24] 2454 	lcall	__gptrget
      0009F7 FF               [12] 2455 	mov	r7,a
      0009F8 A3               [24] 2456 	inc	dptr
      0009F9 12 29 94         [24] 2457 	lcall	__gptrget
      0009FC FE               [12] 2458 	mov	r6,a
      0009FD 8A 82            [24] 2459 	mov	dpl,r2
      0009FF 8B 83            [24] 2460 	mov	dph,r3
      000A01 8F F0            [24] 2461 	mov	b,r7
      000A03 C0 07            [24] 2462 	push	ar7
      000A05 C0 06            [24] 2463 	push	ar6
      000A07 C0 05            [24] 2464 	push	ar5
      000A09 C0 04            [24] 2465 	push	ar4
      000A0B 12 00 EA         [24] 2466 	lcall	_fuzzy_clamp
      000A0E C8               [12] 2467 	xch	a,r0
      000A0F E5 08            [12] 2468 	mov	a,_bp
      000A11 24 05            [12] 2469 	add	a,#0x05
      000A13 C8               [12] 2470 	xch	a,r0
      000A14 A6 82            [24] 2471 	mov	@r0, dpl
      000A16 08               [12] 2472 	inc	r0
      000A17 A6 83            [24] 2473 	mov	@r0, dph
      000A19 08               [12] 2474 	inc	r0
      000A1A A6 F0            [24] 2475 	mov	@r0, b
      000A1C 08               [12] 2476 	inc	r0
      000A1D F6               [12] 2477 	mov	@r0,a
      000A1E D0 04            [24] 2478 	pop	ar4
      000A20 D0 05            [24] 2479 	pop	ar5
      000A22 D0 06            [24] 2480 	pop	ar6
      000A24 D0 07            [24] 2481 	pop	ar7
                           00096F  2482 	C$fuzzy.h$1200$3_0$59 ==.
                                   2483 ;	../../fuzzy.h:1200: values[index + 1u];
      000A26 74 01            [12] 2484 	mov	a,#0x01
      000A28 2C               [12] 2485 	add	a, r4
      000A29 FE               [12] 2486 	mov	r6,a
      000A2A E4               [12] 2487 	clr	a
      000A2B 3D               [12] 2488 	addc	a, r5
      000A2C FF               [12] 2489 	mov	r7,a
      000A2D EE               [12] 2490 	mov	a,r6
      000A2E 2E               [12] 2491 	add	a,r6
      000A2F FE               [12] 2492 	mov	r6,a
      000A30 EF               [12] 2493 	mov	a,r7
      000A31 33               [12] 2494 	rlc	a
      000A32 FF               [12] 2495 	mov	r7,a
      000A33 EE               [12] 2496 	mov	a,r6
      000A34 2E               [12] 2497 	add	a,r6
      000A35 FE               [12] 2498 	mov	r6,a
      000A36 EF               [12] 2499 	mov	a,r7
      000A37 33               [12] 2500 	rlc	a
      000A38 FF               [12] 2501 	mov	r7,a
      000A39 E5 08            [12] 2502 	mov	a,_bp
      000A3B 24 FB            [12] 2503 	add	a,#0xfb
      000A3D F8               [12] 2504 	mov	r0,a
      000A3E EE               [12] 2505 	mov	a,r6
      000A3F 26               [12] 2506 	add	a, @r0
      000A40 FE               [12] 2507 	mov	r6,a
      000A41 EF               [12] 2508 	mov	a,r7
      000A42 08               [12] 2509 	inc	r0
      000A43 36               [12] 2510 	addc	a, @r0
      000A44 FF               [12] 2511 	mov	r7,a
      000A45 08               [12] 2512 	inc	r0
      000A46 86 03            [24] 2513 	mov	ar3,@r0
      000A48 8E 82            [24] 2514 	mov	dpl,r6
      000A4A 8F 83            [24] 2515 	mov	dph,r7
      000A4C 8B F0            [24] 2516 	mov	b,r3
      000A4E 12 29 94         [24] 2517 	lcall	__gptrget
      000A51 FE               [12] 2518 	mov	r6,a
      000A52 A3               [24] 2519 	inc	dptr
      000A53 12 29 94         [24] 2520 	lcall	__gptrget
      000A56 FF               [12] 2521 	mov	r7,a
      000A57 A3               [24] 2522 	inc	dptr
      000A58 12 29 94         [24] 2523 	lcall	__gptrget
      000A5B FB               [12] 2524 	mov	r3,a
      000A5C A3               [24] 2525 	inc	dptr
      000A5D 12 29 94         [24] 2526 	lcall	__gptrget
      000A60 FA               [12] 2527 	mov	r2,a
                           0009AA  2528 	C$fuzzy.h$1205$1_0$56 ==.
                                   2529 ;	../../fuzzy.h:1205: consequent;
      000A61 C0 05            [24] 2530 	push	ar5
      000A63 C0 04            [24] 2531 	push	ar4
      000A65 C0 06            [24] 2532 	push	ar6
      000A67 C0 07            [24] 2533 	push	ar7
      000A69 C0 03            [24] 2534 	push	ar3
      000A6B C0 02            [24] 2535 	push	ar2
      000A6D E5 08            [12] 2536 	mov	a,_bp
      000A6F 24 05            [12] 2537 	add	a,#0x05
      000A71 F8               [12] 2538 	mov	r0,a
      000A72 86 82            [24] 2539 	mov	dpl, @r0
      000A74 08               [12] 2540 	inc	r0
      000A75 86 83            [24] 2541 	mov	dph, @r0
      000A77 08               [12] 2542 	inc	r0
      000A78 86 F0            [24] 2543 	mov	b, @r0
      000A7A 08               [12] 2544 	inc	r0
      000A7B E6               [12] 2545 	mov	a, @r0
      000A7C 12 26 38         [24] 2546 	lcall	___fsmul
      000A7F AA 82            [24] 2547 	mov	r2, dpl
      000A81 AB 83            [24] 2548 	mov	r3, dph
      000A83 AE F0            [24] 2549 	mov	r6, b
      000A85 FF               [12] 2550 	mov	r7, a
      000A86 E5 81            [12] 2551 	mov	a,sp
      000A88 24 FC            [12] 2552 	add	a,#0xfc
      000A8A F5 81            [12] 2553 	mov	sp,a
      000A8C D0 04            [24] 2554 	pop	ar4
      000A8E D0 05            [24] 2555 	pop	ar5
      000A90 C0 07            [24] 2556 	push	ar7
      000A92 C0 06            [24] 2557 	push	ar6
      000A94 C0 05            [24] 2558 	push	ar5
      000A96 C0 04            [24] 2559 	push	ar4
      000A98 C0 02            [24] 2560 	push	ar2
      000A9A C0 03            [24] 2561 	push	ar3
      000A9C C0 06            [24] 2562 	push	ar6
      000A9E C0 07            [24] 2563 	push	ar7
                           0009E9  2564 	C$fuzzy.h$1193$1_0$56 ==.
                                   2565 ;	../../fuzzy.h:1193: ) {
      000AA0 A8 08            [24] 2566 	mov	r0,_bp
      000AA2 08               [12] 2567 	inc	r0
      000AA3 86 82            [24] 2568 	mov	dpl, @r0
      000AA5 08               [12] 2569 	inc	r0
      000AA6 86 83            [24] 2570 	mov	dph, @r0
      000AA8 08               [12] 2571 	inc	r0
      000AA9 86 F0            [24] 2572 	mov	b, @r0
      000AAB 08               [12] 2573 	inc	r0
      000AAC E6               [12] 2574 	mov	a, @r0
      000AAD 12 27 BA         [24] 2575 	lcall	___fsadd
      000AB0 A8 08            [24] 2576 	mov	r0,_bp
      000AB2 08               [12] 2577 	inc	r0
      000AB3 A6 82            [24] 2578 	mov	@r0, dpl
      000AB5 08               [12] 2579 	inc	r0
      000AB6 A6 83            [24] 2580 	mov	@r0, dph
      000AB8 08               [12] 2581 	inc	r0
      000AB9 A6 F0            [24] 2582 	mov	@r0, b
      000ABB 08               [12] 2583 	inc	r0
      000ABC F6               [12] 2584 	mov	@r0,a
      000ABD E5 81            [12] 2585 	mov	a,sp
      000ABF 24 FC            [12] 2586 	add	a,#0xfc
      000AC1 F5 81            [12] 2587 	mov	sp,a
      000AC3 D0 04            [24] 2588 	pop	ar4
      000AC5 D0 05            [24] 2589 	pop	ar5
      000AC7 D0 06            [24] 2590 	pop	ar6
      000AC9 D0 07            [24] 2591 	pop	ar7
      000ACB 74 02            [12] 2592 	mov	a,#0x02
      000ACD 2C               [12] 2593 	add	a, r4
      000ACE FC               [12] 2594 	mov	r4,a
      000ACF E4               [12] 2595 	clr	a
      000AD0 3D               [12] 2596 	addc	a, r5
      000AD1 FD               [12] 2597 	mov	r5,a
      000AD2 D0 07            [24] 2598 	pop	ar7
      000AD4 D0 06            [24] 2599 	pop	ar6
      000AD6 02 09 BB         [24] 2600 	ljmp	00107$
      000AD9                       2601 00105$:
                           000A22  2602 	C$fuzzy.h$1208$1_0$56 ==.
                                   2603 ;	../../fuzzy.h:1208: return weighted_sum;
      000AD9 A8 08            [24] 2604 	mov	r0,_bp
      000ADB 08               [12] 2605 	inc	r0
      000ADC 86 82            [24] 2606 	mov	dpl, @r0
      000ADE 08               [12] 2607 	inc	r0
      000ADF 86 83            [24] 2608 	mov	dph, @r0
      000AE1 08               [12] 2609 	inc	r0
      000AE2 86 F0            [24] 2610 	mov	b, @r0
      000AE4 08               [12] 2611 	inc	r0
      000AE5 E6               [12] 2612 	mov	a, @r0
      000AE6                       2613 00109$:
                           000A2F  2614 	C$fuzzy.h$1209$1_0$56 ==.
                                   2615 ;	../../fuzzy.h:1209: }
      000AE6 85 08 81         [24] 2616 	mov	sp,_bp
      000AE9 D0 08            [24] 2617 	pop	_bp
                           000A34  2618 	C$fuzzy.h$1209$1_0$56 ==.
                           000A34  2619 	XG$fuzzy_sugeno_weighted_sum_array$0$0 ==.
      000AEB 22               [24] 2620 	ret
                                   2621 ;------------------------------------------------------------
                                   2622 ;Allocation info for local variables in function 'fuzzy_ramp'
                                   2623 ;------------------------------------------------------------
                                   2624 ;upper_boundary Allocated to stack - _bp -6 +4 
                                   2625 ;value         Allocated to stack - _bp -10 +4 
                                   2626 ;ramp_up       Allocated to stack - _bp -11 +1 
                                   2627 ;hedge         Allocated to stack - _bp -12 +1 
                                   2628 ;lower_boundary Allocated to registers r7 r6 r5 r4 
                                   2629 ;result        Allocated to stack - _bp +5 +4 
                                   2630 ;normalized    Allocated to registers r4 r5 r6 r7 
                                   2631 ;sloc0         Allocated to stack - _bp +13 +4 
                                   2632 ;sloc1         Allocated to stack - _bp +1 +4 
                                   2633 ;------------------------------------------------------------
                           000A35  2634 	G$fuzzy_ramp$0$0 ==.
                           000A35  2635 	C$fuzzy.h$1215$1_0$61 ==.
                                   2636 ;	../../fuzzy.h:1215: float fuzzy_ramp(
                                   2637 ;	-----------------------------------------
                                   2638 ;	 function fuzzy_ramp
                                   2639 ;	-----------------------------------------
      000AEC                       2640 _fuzzy_ramp:
      000AEC C0 08            [24] 2641 	push	_bp
      000AEE 85 81 08         [24] 2642 	mov	_bp,sp
      000AF1 AF 82            [24] 2643 	mov	r7,dpl
      000AF3 AE 83            [24] 2644 	mov	r6,dph
      000AF5 AD F0            [24] 2645 	mov	r5,b
      000AF7 FC               [12] 2646 	mov	r4,a
      000AF8 E5 81            [12] 2647 	mov	a,sp
      000AFA 24 08            [12] 2648 	add	a,#0x08
      000AFC F5 81            [12] 2649 	mov	sp,a
                           000A47  2650 	C$fuzzy.h$1226$1_0$61 ==.
                                   2651 ;	../../fuzzy.h:1226: if (lower_boundary >= upper_boundary) {
      000AFE C0 07            [24] 2652 	push	ar7
      000B00 C0 06            [24] 2653 	push	ar6
      000B02 C0 05            [24] 2654 	push	ar5
      000B04 C0 04            [24] 2655 	push	ar4
      000B06 E5 08            [12] 2656 	mov	a,_bp
      000B08 24 FA            [12] 2657 	add	a,#0xfa
      000B0A F8               [12] 2658 	mov	r0,a
      000B0B E6               [12] 2659 	mov	a,@r0
      000B0C C0 E0            [24] 2660 	push	acc
      000B0E 08               [12] 2661 	inc	r0
      000B0F E6               [12] 2662 	mov	a,@r0
      000B10 C0 E0            [24] 2663 	push	acc
      000B12 08               [12] 2664 	inc	r0
      000B13 E6               [12] 2665 	mov	a,@r0
      000B14 C0 E0            [24] 2666 	push	acc
      000B16 08               [12] 2667 	inc	r0
      000B17 E6               [12] 2668 	mov	a,@r0
      000B18 C0 E0            [24] 2669 	push	acc
      000B1A 8F 82            [24] 2670 	mov	dpl, r7
      000B1C 8E 83            [24] 2671 	mov	dph, r6
      000B1E 8D F0            [24] 2672 	mov	b, r5
      000B20 EC               [12] 2673 	mov	a, r4
      000B21 12 27 68         [24] 2674 	lcall	___fslt
      000B24 E5 81            [12] 2675 	mov	a,sp
      000B26 24 FC            [12] 2676 	add	a,#0xfc
      000B28 F5 81            [12] 2677 	mov	sp,a
      000B2A D0 04            [24] 2678 	pop	ar4
      000B2C D0 05            [24] 2679 	pop	ar5
      000B2E D0 06            [24] 2680 	pop	ar6
      000B30 D0 07            [24] 2681 	pop	ar7
      000B32 E5 82            [12] 2682 	mov	a, dpl
      000B34 24 FF            [12] 2683 	add	a,#0xff
      000B36 92 00            [24] 2684 	mov	b0,c
      000B38 40 09            [24] 2685 	jc	00102$
                           000A83  2686 	C$fuzzy.h$1227$2_0$62 ==.
                                   2687 ;	../../fuzzy.h:1227: return LEVEL_LO;
      000B3A 90 00 00         [24] 2688 	mov	dptr,#0x0000
      000B3D E4               [12] 2689 	clr	a
      000B3E F5 F0            [12] 2690 	mov	b,a
      000B40 02 0D 23         [24] 2691 	ljmp	00109$
      000B43                       2692 00102$:
                           000A8C  2693 	C$fuzzy.h$1230$1_0$61 ==.
                                   2694 ;	../../fuzzy.h:1230: if (value <= lower_boundary) {
      000B43 C0 07            [24] 2695 	push	ar7
      000B45 C0 06            [24] 2696 	push	ar6
      000B47 C0 05            [24] 2697 	push	ar5
      000B49 C0 04            [24] 2698 	push	ar4
      000B4B E5 08            [12] 2699 	mov	a,_bp
      000B4D 24 F6            [12] 2700 	add	a,#0xf6
      000B4F F8               [12] 2701 	mov	r0,a
      000B50 E6               [12] 2702 	mov	a,@r0
      000B51 C0 E0            [24] 2703 	push	acc
      000B53 08               [12] 2704 	inc	r0
      000B54 E6               [12] 2705 	mov	a,@r0
      000B55 C0 E0            [24] 2706 	push	acc
      000B57 08               [12] 2707 	inc	r0
      000B58 E6               [12] 2708 	mov	a,@r0
      000B59 C0 E0            [24] 2709 	push	acc
      000B5B 08               [12] 2710 	inc	r0
      000B5C E6               [12] 2711 	mov	a,@r0
      000B5D C0 E0            [24] 2712 	push	acc
      000B5F 8F 82            [24] 2713 	mov	dpl, r7
      000B61 8E 83            [24] 2714 	mov	dph, r6
      000B63 8D F0            [24] 2715 	mov	b, r5
      000B65 EC               [12] 2716 	mov	a, r4
      000B66 12 27 68         [24] 2717 	lcall	___fslt
      000B69 E5 81            [12] 2718 	mov	a,sp
      000B6B 24 FC            [12] 2719 	add	a,#0xfc
      000B6D F5 81            [12] 2720 	mov	sp,a
      000B6F D0 04            [24] 2721 	pop	ar4
      000B71 D0 05            [24] 2722 	pop	ar5
      000B73 D0 06            [24] 2723 	pop	ar6
      000B75 D0 07            [24] 2724 	pop	ar7
      000B77 E5 82            [12] 2725 	mov	a, dpl
      000B79 24 FF            [12] 2726 	add	a,#0xff
      000B7B 92 00            [24] 2727 	mov	b0,c
      000B7D 40 39            [24] 2728 	jc	00107$
                           000AC8  2729 	C$fuzzy.h$1232$2_0$63 ==.
                                   2730 ;	../../fuzzy.h:1232: ramp_up
      000B7F E5 08            [12] 2731 	mov	a,_bp
      000B81 24 F5            [12] 2732 	add	a,#0xf5
      000B83 F8               [12] 2733 	mov	r0,a
      000B84 E6               [12] 2734 	mov	a,@r0
      000B85 60 0F            [24] 2735 	jz	00111$
                           000AD0  2736 	C$fuzzy.h$1233$2_0$63 ==.
                                   2737 ;	../../fuzzy.h:1233: ? LEVEL_LO
      000B87 E5 08            [12] 2738 	mov	a,_bp
      000B89 24 05            [12] 2739 	add	a,#0x05
      000B8B F8               [12] 2740 	mov	r0,a
      000B8C E4               [12] 2741 	clr	a
      000B8D F6               [12] 2742 	mov	@r0,a
      000B8E 08               [12] 2743 	inc	r0
      000B8F F6               [12] 2744 	mov	@r0,a
      000B90 08               [12] 2745 	inc	r0
      000B91 F6               [12] 2746 	mov	@r0,a
      000B92 08               [12] 2747 	inc	r0
      000B93 F6               [12] 2748 	mov	@r0,a
      000B94 80 0F            [24] 2749 	sjmp	00112$
      000B96                       2750 00111$:
                           000ADF  2751 	C$fuzzy.h$1234$2_0$63 ==.
                                   2752 ;	../../fuzzy.h:1234: : LEVEL_HI;
      000B96 E5 08            [12] 2753 	mov	a,_bp
      000B98 24 05            [12] 2754 	add	a,#0x05
      000B9A F8               [12] 2755 	mov	r0,a
      000B9B E4               [12] 2756 	clr	a
      000B9C F6               [12] 2757 	mov	@r0,a
      000B9D 08               [12] 2758 	inc	r0
      000B9E F6               [12] 2759 	mov	@r0,a
      000B9F 08               [12] 2760 	inc	r0
      000BA0 76 80            [12] 2761 	mov	@r0,#0x80
      000BA2 08               [12] 2762 	inc	r0
      000BA3 76 3F            [12] 2763 	mov	@r0,#0x3f
      000BA5                       2764 00112$:
      000BA5 E5 08            [12] 2765 	mov	a,_bp
      000BA7 24 05            [12] 2766 	add	a,#0x05
      000BA9 F8               [12] 2767 	mov	r0,a
      000BAA 86 07            [24] 2768 	mov	ar7,@r0
      000BAC 08               [12] 2769 	inc	r0
      000BAD 86 06            [24] 2770 	mov	ar6,@r0
      000BAF 08               [12] 2771 	inc	r0
      000BB0 86 05            [24] 2772 	mov	ar5,@r0
      000BB2 08               [12] 2773 	inc	r0
      000BB3 86 04            [24] 2774 	mov	ar4,@r0
      000BB5 02 0D 01         [24] 2775 	ljmp	00108$
      000BB8                       2776 00107$:
                           000B01  2777 	C$fuzzy.h$1236$1_0$61 ==.
                                   2778 ;	../../fuzzy.h:1236: else if (value >= upper_boundary) {
      000BB8 C0 07            [24] 2779 	push	ar7
      000BBA C0 06            [24] 2780 	push	ar6
      000BBC C0 05            [24] 2781 	push	ar5
      000BBE C0 04            [24] 2782 	push	ar4
      000BC0 E5 08            [12] 2783 	mov	a,_bp
      000BC2 24 FA            [12] 2784 	add	a,#0xfa
      000BC4 F8               [12] 2785 	mov	r0,a
      000BC5 E6               [12] 2786 	mov	a,@r0
      000BC6 C0 E0            [24] 2787 	push	acc
      000BC8 08               [12] 2788 	inc	r0
      000BC9 E6               [12] 2789 	mov	a,@r0
      000BCA C0 E0            [24] 2790 	push	acc
      000BCC 08               [12] 2791 	inc	r0
      000BCD E6               [12] 2792 	mov	a,@r0
      000BCE C0 E0            [24] 2793 	push	acc
      000BD0 08               [12] 2794 	inc	r0
      000BD1 E6               [12] 2795 	mov	a,@r0
      000BD2 C0 E0            [24] 2796 	push	acc
      000BD4 E5 08            [12] 2797 	mov	a,_bp
      000BD6 24 F6            [12] 2798 	add	a,#0xf6
      000BD8 F8               [12] 2799 	mov	r0,a
      000BD9 86 82            [24] 2800 	mov	dpl, @r0
      000BDB 08               [12] 2801 	inc	r0
      000BDC 86 83            [24] 2802 	mov	dph, @r0
      000BDE 08               [12] 2803 	inc	r0
      000BDF 86 F0            [24] 2804 	mov	b, @r0
      000BE1 08               [12] 2805 	inc	r0
      000BE2 E6               [12] 2806 	mov	a, @r0
      000BE3 12 27 68         [24] 2807 	lcall	___fslt
      000BE6 E5 81            [12] 2808 	mov	a,sp
      000BE8 24 FC            [12] 2809 	add	a,#0xfc
      000BEA F5 81            [12] 2810 	mov	sp,a
      000BEC D0 04            [24] 2811 	pop	ar4
      000BEE D0 05            [24] 2812 	pop	ar5
      000BF0 D0 06            [24] 2813 	pop	ar6
      000BF2 D0 07            [24] 2814 	pop	ar7
      000BF4 E5 82            [12] 2815 	mov	a, dpl
      000BF6 24 FF            [12] 2816 	add	a,#0xff
      000BF8 92 00            [24] 2817 	mov	b0,c
      000BFA 40 39            [24] 2818 	jc	00104$
                           000B45  2819 	C$fuzzy.h$1238$2_0$64 ==.
                                   2820 ;	../../fuzzy.h:1238: ramp_up
      000BFC E5 08            [12] 2821 	mov	a,_bp
      000BFE 24 F5            [12] 2822 	add	a,#0xf5
      000C00 F8               [12] 2823 	mov	r0,a
      000C01 E6               [12] 2824 	mov	a,@r0
      000C02 60 11            [24] 2825 	jz	00113$
                           000B4D  2826 	C$fuzzy.h$1239$2_0$64 ==.
                                   2827 ;	../../fuzzy.h:1239: ? LEVEL_HI
      000C04 E5 08            [12] 2828 	mov	a,_bp
      000C06 24 05            [12] 2829 	add	a,#0x05
      000C08 F8               [12] 2830 	mov	r0,a
      000C09 E4               [12] 2831 	clr	a
      000C0A F6               [12] 2832 	mov	@r0,a
      000C0B 08               [12] 2833 	inc	r0
      000C0C F6               [12] 2834 	mov	@r0,a
      000C0D 08               [12] 2835 	inc	r0
      000C0E 76 80            [12] 2836 	mov	@r0,#0x80
      000C10 08               [12] 2837 	inc	r0
      000C11 76 3F            [12] 2838 	mov	@r0,#0x3f
      000C13 80 0D            [24] 2839 	sjmp	00114$
      000C15                       2840 00113$:
                           000B5E  2841 	C$fuzzy.h$1240$2_0$64 ==.
                                   2842 ;	../../fuzzy.h:1240: : LEVEL_LO;
      000C15 E5 08            [12] 2843 	mov	a,_bp
      000C17 24 05            [12] 2844 	add	a,#0x05
      000C19 F8               [12] 2845 	mov	r0,a
      000C1A E4               [12] 2846 	clr	a
      000C1B F6               [12] 2847 	mov	@r0,a
      000C1C 08               [12] 2848 	inc	r0
      000C1D F6               [12] 2849 	mov	@r0,a
      000C1E 08               [12] 2850 	inc	r0
      000C1F F6               [12] 2851 	mov	@r0,a
      000C20 08               [12] 2852 	inc	r0
      000C21 F6               [12] 2853 	mov	@r0,a
      000C22                       2854 00114$:
      000C22 E5 08            [12] 2855 	mov	a,_bp
      000C24 24 05            [12] 2856 	add	a,#0x05
      000C26 F8               [12] 2857 	mov	r0,a
      000C27 86 07            [24] 2858 	mov	ar7,@r0
      000C29 08               [12] 2859 	inc	r0
      000C2A 86 06            [24] 2860 	mov	ar6,@r0
      000C2C 08               [12] 2861 	inc	r0
      000C2D 86 05            [24] 2862 	mov	ar5,@r0
      000C2F 08               [12] 2863 	inc	r0
      000C30 86 04            [24] 2864 	mov	ar4,@r0
      000C32 02 0D 01         [24] 2865 	ljmp	00108$
      000C35                       2866 00104$:
                           000B7E  2867 	C$fuzzy.h$1244$1_0$61 ==.
                                   2868 ;	../../fuzzy.h:1244: (value - lower_boundary) /
      000C35 C0 07            [24] 2869 	push	ar7
      000C37 C0 06            [24] 2870 	push	ar6
      000C39 C0 05            [24] 2871 	push	ar5
      000C3B C0 04            [24] 2872 	push	ar4
      000C3D C0 07            [24] 2873 	push	ar7
      000C3F C0 06            [24] 2874 	push	ar6
      000C41 C0 05            [24] 2875 	push	ar5
      000C43 C0 04            [24] 2876 	push	ar4
                           000B8E  2877 	C$fuzzy.h$1245$1_0$61 ==.
                                   2878 ;	../../fuzzy.h:1245: (upper_boundary - lower_boundary);
      000C45 E5 08            [12] 2879 	mov	a,_bp
      000C47 24 F6            [12] 2880 	add	a,#0xf6
      000C49 F8               [12] 2881 	mov	r0,a
      000C4A 86 82            [24] 2882 	mov	dpl, @r0
      000C4C 08               [12] 2883 	inc	r0
      000C4D 86 83            [24] 2884 	mov	dph, @r0
      000C4F 08               [12] 2885 	inc	r0
      000C50 86 F0            [24] 2886 	mov	b, @r0
      000C52 08               [12] 2887 	inc	r0
      000C53 E6               [12] 2888 	mov	a, @r0
      000C54 12 26 2D         [24] 2889 	lcall	___fssub
      000C57 A8 08            [24] 2890 	mov	r0,_bp
      000C59 08               [12] 2891 	inc	r0
      000C5A A6 82            [24] 2892 	mov	@r0, dpl
      000C5C 08               [12] 2893 	inc	r0
      000C5D A6 83            [24] 2894 	mov	@r0, dph
      000C5F 08               [12] 2895 	inc	r0
      000C60 A6 F0            [24] 2896 	mov	@r0, b
      000C62 08               [12] 2897 	inc	r0
      000C63 F6               [12] 2898 	mov	@r0,a
      000C64 E5 81            [12] 2899 	mov	a,sp
      000C66 24 FC            [12] 2900 	add	a,#0xfc
      000C68 F5 81            [12] 2901 	mov	sp,a
      000C6A E5 08            [12] 2902 	mov	a,_bp
      000C6C 24 FA            [12] 2903 	add	a,#0xfa
      000C6E F8               [12] 2904 	mov	r0,a
      000C6F 86 82            [24] 2905 	mov	dpl, @r0
      000C71 08               [12] 2906 	inc	r0
      000C72 86 83            [24] 2907 	mov	dph, @r0
      000C74 08               [12] 2908 	inc	r0
      000C75 86 F0            [24] 2909 	mov	b, @r0
      000C77 08               [12] 2910 	inc	r0
      000C78 E6               [12] 2911 	mov	a, @r0
      000C79 12 26 2D         [24] 2912 	lcall	___fssub
      000C7C AC 82            [24] 2913 	mov	r4, dpl
      000C7E AD 83            [24] 2914 	mov	r5, dph
      000C80 AE F0            [24] 2915 	mov	r6, b
      000C82 FF               [12] 2916 	mov	r7, a
      000C83 E5 81            [12] 2917 	mov	a,sp
      000C85 24 FC            [12] 2918 	add	a,#0xfc
      000C87 F5 81            [12] 2919 	mov	sp,a
      000C89 C0 04            [24] 2920 	push	ar4
      000C8B C0 05            [24] 2921 	push	ar5
      000C8D C0 06            [24] 2922 	push	ar6
      000C8F C0 07            [24] 2923 	push	ar7
                           000BDA  2924 	C$fuzzy.h$1248$1_0$61 ==.
                                   2925 ;	../../fuzzy.h:1248: ramp_up
      000C91 A8 08            [24] 2926 	mov	r0,_bp
      000C93 08               [12] 2927 	inc	r0
      000C94 86 82            [24] 2928 	mov	dpl, @r0
      000C96 08               [12] 2929 	inc	r0
      000C97 86 83            [24] 2930 	mov	dph, @r0
      000C99 08               [12] 2931 	inc	r0
      000C9A 86 F0            [24] 2932 	mov	b, @r0
      000C9C 08               [12] 2933 	inc	r0
      000C9D E6               [12] 2934 	mov	a, @r0
      000C9E 12 28 D1         [24] 2935 	lcall	___fsdiv
      000CA1 AC 82            [24] 2936 	mov	r4, dpl
      000CA3 AD 83            [24] 2937 	mov	r5, dph
      000CA5 AE F0            [24] 2938 	mov	r6, b
      000CA7 FF               [12] 2939 	mov	r7, a
      000CA8 E5 81            [12] 2940 	mov	a,sp
      000CAA 24 FC            [12] 2941 	add	a,#0xfc
      000CAC F5 81            [12] 2942 	mov	sp,a
      000CAE E5 08            [12] 2943 	mov	a,_bp
      000CB0 24 F5            [12] 2944 	add	a,#0xf5
      000CB2 F8               [12] 2945 	mov	r0,a
      000CB3 E6               [12] 2946 	mov	a,@r0
      000CB4 60 12            [24] 2947 	jz	00115$
                           000BFF  2948 	C$fuzzy.h$1249$2_0$65 ==.
                                   2949 ;	../../fuzzy.h:1249: ? normalized
      000CB6 E5 08            [12] 2950 	mov	a,_bp
      000CB8 24 05            [12] 2951 	add	a,#0x05
      000CBA F8               [12] 2952 	mov	r0,a
      000CBB A6 04            [24] 2953 	mov	@r0,ar4
      000CBD 08               [12] 2954 	inc	r0
      000CBE A6 05            [24] 2955 	mov	@r0,ar5
      000CC0 08               [12] 2956 	inc	r0
      000CC1 A6 06            [24] 2957 	mov	@r0,ar6
      000CC3 08               [12] 2958 	inc	r0
      000CC4 A6 07            [24] 2959 	mov	@r0,ar7
      000CC6 80 29            [24] 2960 	sjmp	00116$
      000CC8                       2961 00115$:
                           000C11  2962 	C$fuzzy.h$1250$1_0$61 ==.
                                   2963 ;	../../fuzzy.h:1250: : LEVEL_HI - normalized;
      000CC8 C0 04            [24] 2964 	push	ar4
      000CCA C0 05            [24] 2965 	push	ar5
      000CCC C0 06            [24] 2966 	push	ar6
      000CCE C0 07            [24] 2967 	push	ar7
      000CD0 90 00 00         [24] 2968 	mov	dptr,#0x0000
      000CD3 75 F0 80         [24] 2969 	mov	b, #0x80
      000CD6 74 3F            [12] 2970 	mov	a, #0x3f
      000CD8 12 26 2D         [24] 2971 	lcall	___fssub
      000CDB C8               [12] 2972 	xch	a,r0
      000CDC E5 08            [12] 2973 	mov	a,_bp
      000CDE 24 05            [12] 2974 	add	a,#0x05
      000CE0 C8               [12] 2975 	xch	a,r0
      000CE1 A6 82            [24] 2976 	mov	@r0, dpl
      000CE3 08               [12] 2977 	inc	r0
      000CE4 A6 83            [24] 2978 	mov	@r0, dph
      000CE6 08               [12] 2979 	inc	r0
      000CE7 A6 F0            [24] 2980 	mov	@r0, b
      000CE9 08               [12] 2981 	inc	r0
      000CEA F6               [12] 2982 	mov	@r0,a
      000CEB E5 81            [12] 2983 	mov	a,sp
      000CED 24 FC            [12] 2984 	add	a,#0xfc
      000CEF F5 81            [12] 2985 	mov	sp,a
      000CF1                       2986 00116$:
      000CF1 E5 08            [12] 2987 	mov	a,_bp
      000CF3 24 05            [12] 2988 	add	a,#0x05
      000CF5 F8               [12] 2989 	mov	r0,a
      000CF6 86 07            [24] 2990 	mov	ar7,@r0
      000CF8 08               [12] 2991 	inc	r0
      000CF9 86 06            [24] 2992 	mov	ar6,@r0
      000CFB 08               [12] 2993 	inc	r0
      000CFC 86 05            [24] 2994 	mov	ar5,@r0
      000CFE 08               [12] 2995 	inc	r0
      000CFF 86 04            [24] 2996 	mov	ar4,@r0
      000D01                       2997 00108$:
                           000C4A  2998 	C$fuzzy.h$1254$1_0$61 ==.
                                   2999 ;	../../fuzzy.h:1254: result,
      000D01 E5 08            [12] 3000 	mov	a,_bp
      000D03 24 F4            [12] 3001 	add	a,#0xf4
      000D05 F8               [12] 3002 	mov	r0,a
      000D06 E6               [12] 3003 	mov	a,@r0
      000D07 C0 E0            [24] 3004 	push	acc
      000D09 8F 82            [24] 3005 	mov	dpl, r7
      000D0B 8E 83            [24] 3006 	mov	dph, r6
      000D0D 8D F0            [24] 3007 	mov	b, r5
      000D0F EC               [12] 3008 	mov	a, r4
      000D10 12 01 99         [24] 3009 	lcall	_fuzzy_apply_hedge
      000D13 AC 82            [24] 3010 	mov	r4, dpl
      000D15 AD 83            [24] 3011 	mov	r5, dph
      000D17 AE F0            [24] 3012 	mov	r6, b
      000D19 FF               [12] 3013 	mov	r7, a
      000D1A 15 81            [12] 3014 	dec	sp
      000D1C 8C 82            [24] 3015 	mov	dpl, r4
      000D1E 8D 83            [24] 3016 	mov	dph, r5
      000D20 8E F0            [24] 3017 	mov	b, r6
      000D22 EF               [12] 3018 	mov	a, r7
      000D23                       3019 00109$:
                           000C6C  3020 	C$fuzzy.h$1257$1_0$61 ==.
                                   3021 ;	../../fuzzy.h:1257: }
      000D23 85 08 81         [24] 3022 	mov	sp,_bp
      000D26 D0 08            [24] 3023 	pop	_bp
                           000C71  3024 	C$fuzzy.h$1257$1_0$61 ==.
                           000C71  3025 	XG$fuzzy_ramp$0$0 ==.
      000D28 22               [24] 3026 	ret
                                   3027 ;------------------------------------------------------------
                                   3028 ;Allocation info for local variables in function 'fuzzy_triangle'
                                   3029 ;------------------------------------------------------------
                                   3030 ;b             Allocated to stack - _bp -6 +4 
                                   3031 ;c             Allocated to stack - _bp -10 +4 
                                   3032 ;value         Allocated to stack - _bp -14 +4 
                                   3033 ;hedge         Allocated to stack - _bp -15 +1 
                                   3034 ;a             Allocated to registers r7 r6 r5 r4 
                                   3035 ;result        Allocated to stack - _bp +1 +4 
                                   3036 ;sloc0         Allocated to stack - _bp +1 +4 
                                   3037 ;sloc1         Allocated to stack - _bp +5 +4 
                                   3038 ;------------------------------------------------------------
                           000C72  3039 	G$fuzzy_triangle$0$0 ==.
                           000C72  3040 	C$fuzzy.h$1301$1_0$67 ==.
                                   3041 ;	../../fuzzy.h:1301: float fuzzy_triangle(
                                   3042 ;	-----------------------------------------
                                   3043 ;	 function fuzzy_triangle
                                   3044 ;	-----------------------------------------
      000D29                       3045 _fuzzy_triangle:
      000D29 C0 08            [24] 3046 	push	_bp
      000D2B 85 81 08         [24] 3047 	mov	_bp,sp
      000D2E AF 82            [24] 3048 	mov	r7,dpl
      000D30 AE 83            [24] 3049 	mov	r6,dph
      000D32 AD F0            [24] 3050 	mov	r5,b
      000D34 FC               [12] 3051 	mov	r4,a
      000D35 E5 81            [12] 3052 	mov	a,sp
      000D37 24 08            [12] 3053 	add	a,#0x08
      000D39 F5 81            [12] 3054 	mov	sp,a
                           000C84  3055 	C$fuzzy.h$1312$1_0$67 ==.
                                   3056 ;	../../fuzzy.h:1312: a >= b ||
      000D3B C0 07            [24] 3057 	push	ar7
      000D3D C0 06            [24] 3058 	push	ar6
      000D3F C0 05            [24] 3059 	push	ar5
      000D41 C0 04            [24] 3060 	push	ar4
      000D43 E5 08            [12] 3061 	mov	a,_bp
      000D45 24 FA            [12] 3062 	add	a,#0xfa
      000D47 F8               [12] 3063 	mov	r0,a
      000D48 E6               [12] 3064 	mov	a,@r0
      000D49 C0 E0            [24] 3065 	push	acc
      000D4B 08               [12] 3066 	inc	r0
      000D4C E6               [12] 3067 	mov	a,@r0
      000D4D C0 E0            [24] 3068 	push	acc
      000D4F 08               [12] 3069 	inc	r0
      000D50 E6               [12] 3070 	mov	a,@r0
      000D51 C0 E0            [24] 3071 	push	acc
      000D53 08               [12] 3072 	inc	r0
      000D54 E6               [12] 3073 	mov	a,@r0
      000D55 C0 E0            [24] 3074 	push	acc
      000D57 8F 82            [24] 3075 	mov	dpl, r7
      000D59 8E 83            [24] 3076 	mov	dph, r6
      000D5B 8D F0            [24] 3077 	mov	b, r5
      000D5D EC               [12] 3078 	mov	a, r4
      000D5E 12 27 68         [24] 3079 	lcall	___fslt
      000D61 E5 81            [12] 3080 	mov	a,sp
      000D63 24 FC            [12] 3081 	add	a,#0xfc
      000D65 F5 81            [12] 3082 	mov	sp,a
      000D67 D0 04            [24] 3083 	pop	ar4
      000D69 D0 05            [24] 3084 	pop	ar5
      000D6B D0 06            [24] 3085 	pop	ar6
      000D6D D0 07            [24] 3086 	pop	ar7
      000D6F E5 82            [12] 3087 	mov	a, dpl
      000D71 24 FF            [12] 3088 	add	a,#0xff
      000D73 92 00            [24] 3089 	mov	b0,c
      000D75 40 03            [24] 3090 	jc	00145$
      000D77 02 0E 41         [24] 3091 	ljmp	00107$
      000D7A                       3092 00145$:
                           000CC3  3093 	C$fuzzy.h$1313$1_0$67 ==.
                                   3094 ;	../../fuzzy.h:1313: b >= c ||
      000D7A C0 07            [24] 3095 	push	ar7
      000D7C C0 06            [24] 3096 	push	ar6
      000D7E C0 05            [24] 3097 	push	ar5
      000D80 C0 04            [24] 3098 	push	ar4
      000D82 E5 08            [12] 3099 	mov	a,_bp
      000D84 24 F6            [12] 3100 	add	a,#0xf6
      000D86 F8               [12] 3101 	mov	r0,a
      000D87 E6               [12] 3102 	mov	a,@r0
      000D88 C0 E0            [24] 3103 	push	acc
      000D8A 08               [12] 3104 	inc	r0
      000D8B E6               [12] 3105 	mov	a,@r0
      000D8C C0 E0            [24] 3106 	push	acc
      000D8E 08               [12] 3107 	inc	r0
      000D8F E6               [12] 3108 	mov	a,@r0
      000D90 C0 E0            [24] 3109 	push	acc
      000D92 08               [12] 3110 	inc	r0
      000D93 E6               [12] 3111 	mov	a,@r0
      000D94 C0 E0            [24] 3112 	push	acc
      000D96 E5 08            [12] 3113 	mov	a,_bp
      000D98 24 FA            [12] 3114 	add	a,#0xfa
      000D9A F8               [12] 3115 	mov	r0,a
      000D9B 86 82            [24] 3116 	mov	dpl, @r0
      000D9D 08               [12] 3117 	inc	r0
      000D9E 86 83            [24] 3118 	mov	dph, @r0
      000DA0 08               [12] 3119 	inc	r0
      000DA1 86 F0            [24] 3120 	mov	b, @r0
      000DA3 08               [12] 3121 	inc	r0
      000DA4 E6               [12] 3122 	mov	a, @r0
      000DA5 12 27 68         [24] 3123 	lcall	___fslt
      000DA8 E5 81            [12] 3124 	mov	a,sp
      000DAA 24 FC            [12] 3125 	add	a,#0xfc
      000DAC F5 81            [12] 3126 	mov	sp,a
      000DAE D0 04            [24] 3127 	pop	ar4
      000DB0 D0 05            [24] 3128 	pop	ar5
      000DB2 D0 06            [24] 3129 	pop	ar6
      000DB4 D0 07            [24] 3130 	pop	ar7
      000DB6 E5 82            [12] 3131 	mov	a, dpl
      000DB8 24 FF            [12] 3132 	add	a,#0xff
      000DBA 92 00            [24] 3133 	mov	b0,c
      000DBC 40 03            [24] 3134 	jc	00146$
      000DBE 02 0E 41         [24] 3135 	ljmp	00107$
      000DC1                       3136 00146$:
                           000D0A  3137 	C$fuzzy.h$1314$1_0$67 ==.
                                   3138 ;	../../fuzzy.h:1314: value <= a ||
      000DC1 C0 07            [24] 3139 	push	ar7
      000DC3 C0 06            [24] 3140 	push	ar6
      000DC5 C0 05            [24] 3141 	push	ar5
      000DC7 C0 04            [24] 3142 	push	ar4
      000DC9 E5 08            [12] 3143 	mov	a,_bp
      000DCB 24 F2            [12] 3144 	add	a,#0xf2
      000DCD F8               [12] 3145 	mov	r0,a
      000DCE E6               [12] 3146 	mov	a,@r0
      000DCF C0 E0            [24] 3147 	push	acc
      000DD1 08               [12] 3148 	inc	r0
      000DD2 E6               [12] 3149 	mov	a,@r0
      000DD3 C0 E0            [24] 3150 	push	acc
      000DD5 08               [12] 3151 	inc	r0
      000DD6 E6               [12] 3152 	mov	a,@r0
      000DD7 C0 E0            [24] 3153 	push	acc
      000DD9 08               [12] 3154 	inc	r0
      000DDA E6               [12] 3155 	mov	a,@r0
      000DDB C0 E0            [24] 3156 	push	acc
      000DDD 8F 82            [24] 3157 	mov	dpl, r7
      000DDF 8E 83            [24] 3158 	mov	dph, r6
      000DE1 8D F0            [24] 3159 	mov	b, r5
      000DE3 EC               [12] 3160 	mov	a, r4
      000DE4 12 27 68         [24] 3161 	lcall	___fslt
      000DE7 E5 81            [12] 3162 	mov	a,sp
      000DE9 24 FC            [12] 3163 	add	a,#0xfc
      000DEB F5 81            [12] 3164 	mov	sp,a
      000DED D0 04            [24] 3165 	pop	ar4
      000DEF D0 05            [24] 3166 	pop	ar5
      000DF1 D0 06            [24] 3167 	pop	ar6
      000DF3 D0 07            [24] 3168 	pop	ar7
      000DF5 E5 82            [12] 3169 	mov	a, dpl
      000DF7 24 FF            [12] 3170 	add	a,#0xff
      000DF9 92 00            [24] 3171 	mov	b0,c
      000DFB 50 44            [24] 3172 	jnc	00107$
                           000D46  3173 	C$fuzzy.h$1316$1_0$67 ==.
                                   3174 ;	../../fuzzy.h:1316: ) {
      000DFD C0 07            [24] 3175 	push	ar7
      000DFF C0 06            [24] 3176 	push	ar6
      000E01 C0 05            [24] 3177 	push	ar5
      000E03 C0 04            [24] 3178 	push	ar4
      000E05 E5 08            [12] 3179 	mov	a,_bp
      000E07 24 F6            [12] 3180 	add	a,#0xf6
      000E09 F8               [12] 3181 	mov	r0,a
      000E0A E6               [12] 3182 	mov	a,@r0
      000E0B C0 E0            [24] 3183 	push	acc
      000E0D 08               [12] 3184 	inc	r0
      000E0E E6               [12] 3185 	mov	a,@r0
      000E0F C0 E0            [24] 3186 	push	acc
      000E11 08               [12] 3187 	inc	r0
      000E12 E6               [12] 3188 	mov	a,@r0
      000E13 C0 E0            [24] 3189 	push	acc
      000E15 08               [12] 3190 	inc	r0
      000E16 E6               [12] 3191 	mov	a,@r0
      000E17 C0 E0            [24] 3192 	push	acc
      000E19 E5 08            [12] 3193 	mov	a,_bp
      000E1B 24 F2            [12] 3194 	add	a,#0xf2
      000E1D F8               [12] 3195 	mov	r0,a
      000E1E 86 82            [24] 3196 	mov	dpl, @r0
      000E20 08               [12] 3197 	inc	r0
      000E21 86 83            [24] 3198 	mov	dph, @r0
      000E23 08               [12] 3199 	inc	r0
      000E24 86 F0            [24] 3200 	mov	b, @r0
      000E26 08               [12] 3201 	inc	r0
      000E27 E6               [12] 3202 	mov	a, @r0
      000E28 12 27 68         [24] 3203 	lcall	___fslt
      000E2B E5 81            [12] 3204 	mov	a,sp
      000E2D 24 FC            [12] 3205 	add	a,#0xfc
      000E2F F5 81            [12] 3206 	mov	sp,a
      000E31 D0 04            [24] 3207 	pop	ar4
      000E33 D0 05            [24] 3208 	pop	ar5
      000E35 D0 06            [24] 3209 	pop	ar6
      000E37 D0 07            [24] 3210 	pop	ar7
      000E39 E5 82            [12] 3211 	mov	a, dpl
      000E3B 24 FF            [12] 3212 	add	a,#0xff
      000E3D 92 00            [24] 3213 	mov	b0,c
      000E3F 40 0E            [24] 3214 	jc	00108$
      000E41                       3215 00107$:
                           000D8A  3216 	C$fuzzy.h$1317$2_0$68 ==.
                                   3217 ;	../../fuzzy.h:1317: result = LEVEL_LO;
      000E41 A8 08            [24] 3218 	mov	r0,_bp
      000E43 08               [12] 3219 	inc	r0
      000E44 E4               [12] 3220 	clr	a
      000E45 F6               [12] 3221 	mov	@r0,a
      000E46 08               [12] 3222 	inc	r0
      000E47 F6               [12] 3223 	mov	@r0,a
      000E48 08               [12] 3224 	inc	r0
      000E49 F6               [12] 3225 	mov	@r0,a
      000E4A 08               [12] 3226 	inc	r0
      000E4B F6               [12] 3227 	mov	@r0,a
      000E4C 02 10 07         [24] 3228 	ljmp	00109$
      000E4F                       3229 00108$:
                           000D98  3230 	C$fuzzy.h$1319$1_0$67 ==.
                                   3231 ;	../../fuzzy.h:1319: else if (value == b) {
      000E4F C0 07            [24] 3232 	push	ar7
      000E51 C0 06            [24] 3233 	push	ar6
      000E53 C0 05            [24] 3234 	push	ar5
      000E55 C0 04            [24] 3235 	push	ar4
      000E57 E5 08            [12] 3236 	mov	a,_bp
      000E59 24 FA            [12] 3237 	add	a,#0xfa
      000E5B F8               [12] 3238 	mov	r0,a
      000E5C E6               [12] 3239 	mov	a,@r0
      000E5D C0 E0            [24] 3240 	push	acc
      000E5F 08               [12] 3241 	inc	r0
      000E60 E6               [12] 3242 	mov	a,@r0
      000E61 C0 E0            [24] 3243 	push	acc
      000E63 08               [12] 3244 	inc	r0
      000E64 E6               [12] 3245 	mov	a,@r0
      000E65 C0 E0            [24] 3246 	push	acc
      000E67 08               [12] 3247 	inc	r0
      000E68 E6               [12] 3248 	mov	a,@r0
      000E69 C0 E0            [24] 3249 	push	acc
      000E6B E5 08            [12] 3250 	mov	a,_bp
      000E6D 24 F2            [12] 3251 	add	a,#0xf2
      000E6F F8               [12] 3252 	mov	r0,a
      000E70 86 82            [24] 3253 	mov	dpl, @r0
      000E72 08               [12] 3254 	inc	r0
      000E73 86 83            [24] 3255 	mov	dph, @r0
      000E75 08               [12] 3256 	inc	r0
      000E76 86 F0            [24] 3257 	mov	b, @r0
      000E78 08               [12] 3258 	inc	r0
      000E79 E6               [12] 3259 	mov	a, @r0
      000E7A 12 27 3C         [24] 3260 	lcall	___fseq
      000E7D AB 82            [24] 3261 	mov	r3, dpl
      000E7F E5 81            [12] 3262 	mov	a,sp
      000E81 24 FC            [12] 3263 	add	a,#0xfc
      000E83 F5 81            [12] 3264 	mov	sp,a
      000E85 D0 04            [24] 3265 	pop	ar4
      000E87 D0 05            [24] 3266 	pop	ar5
      000E89 D0 06            [24] 3267 	pop	ar6
      000E8B D0 07            [24] 3268 	pop	ar7
      000E8D EB               [12] 3269 	mov	a,r3
      000E8E 60 10            [24] 3270 	jz	00105$
                           000DD9  3271 	C$fuzzy.h$1320$2_0$69 ==.
                                   3272 ;	../../fuzzy.h:1320: result = LEVEL_HI;
      000E90 A8 08            [24] 3273 	mov	r0,_bp
      000E92 08               [12] 3274 	inc	r0
      000E93 E4               [12] 3275 	clr	a
      000E94 F6               [12] 3276 	mov	@r0,a
      000E95 08               [12] 3277 	inc	r0
      000E96 F6               [12] 3278 	mov	@r0,a
      000E97 08               [12] 3279 	inc	r0
      000E98 76 80            [12] 3280 	mov	@r0,#0x80
      000E9A 08               [12] 3281 	inc	r0
      000E9B 76 3F            [12] 3282 	mov	@r0,#0x3f
      000E9D 02 10 07         [24] 3283 	ljmp	00109$
      000EA0                       3284 00105$:
                           000DE9  3285 	C$fuzzy.h$1322$1_0$67 ==.
                                   3286 ;	../../fuzzy.h:1322: else if (value < b) {
      000EA0 C0 07            [24] 3287 	push	ar7
      000EA2 C0 06            [24] 3288 	push	ar6
      000EA4 C0 05            [24] 3289 	push	ar5
      000EA6 C0 04            [24] 3290 	push	ar4
      000EA8 E5 08            [12] 3291 	mov	a,_bp
      000EAA 24 FA            [12] 3292 	add	a,#0xfa
      000EAC F8               [12] 3293 	mov	r0,a
      000EAD E6               [12] 3294 	mov	a,@r0
      000EAE C0 E0            [24] 3295 	push	acc
      000EB0 08               [12] 3296 	inc	r0
      000EB1 E6               [12] 3297 	mov	a,@r0
      000EB2 C0 E0            [24] 3298 	push	acc
      000EB4 08               [12] 3299 	inc	r0
      000EB5 E6               [12] 3300 	mov	a,@r0
      000EB6 C0 E0            [24] 3301 	push	acc
      000EB8 08               [12] 3302 	inc	r0
      000EB9 E6               [12] 3303 	mov	a,@r0
      000EBA C0 E0            [24] 3304 	push	acc
      000EBC E5 08            [12] 3305 	mov	a,_bp
      000EBE 24 F2            [12] 3306 	add	a,#0xf2
      000EC0 F8               [12] 3307 	mov	r0,a
      000EC1 86 82            [24] 3308 	mov	dpl, @r0
      000EC3 08               [12] 3309 	inc	r0
      000EC4 86 83            [24] 3310 	mov	dph, @r0
      000EC6 08               [12] 3311 	inc	r0
      000EC7 86 F0            [24] 3312 	mov	b, @r0
      000EC9 08               [12] 3313 	inc	r0
      000ECA E6               [12] 3314 	mov	a, @r0
      000ECB 12 27 68         [24] 3315 	lcall	___fslt
      000ECE AB 82            [24] 3316 	mov	r3, dpl
      000ED0 E5 81            [12] 3317 	mov	a,sp
      000ED2 24 FC            [12] 3318 	add	a,#0xfc
      000ED4 F5 81            [12] 3319 	mov	sp,a
      000ED6 D0 04            [24] 3320 	pop	ar4
      000ED8 D0 05            [24] 3321 	pop	ar5
      000EDA D0 06            [24] 3322 	pop	ar6
      000EDC D0 07            [24] 3323 	pop	ar7
      000EDE EB               [12] 3324 	mov	a,r3
      000EDF 70 03            [24] 3325 	jnz	00150$
      000EE1 02 0F 6B         [24] 3326 	ljmp	00102$
      000EE4                       3327 00150$:
                           000E2D  3328 	C$fuzzy.h$1324$1_0$67 ==.
                                   3329 ;	../../fuzzy.h:1324: (value - a) /
      000EE4 C0 07            [24] 3330 	push	ar7
      000EE6 C0 06            [24] 3331 	push	ar6
      000EE8 C0 05            [24] 3332 	push	ar5
      000EEA C0 04            [24] 3333 	push	ar4
      000EEC C0 07            [24] 3334 	push	ar7
      000EEE C0 06            [24] 3335 	push	ar6
      000EF0 C0 05            [24] 3336 	push	ar5
      000EF2 C0 04            [24] 3337 	push	ar4
                           000E3D  3338 	C$fuzzy.h$1325$1_0$67 ==.
                                   3339 ;	../../fuzzy.h:1325: (b - a);
      000EF4 E5 08            [12] 3340 	mov	a,_bp
      000EF6 24 F2            [12] 3341 	add	a,#0xf2
      000EF8 F8               [12] 3342 	mov	r0,a
      000EF9 86 82            [24] 3343 	mov	dpl, @r0
      000EFB 08               [12] 3344 	inc	r0
      000EFC 86 83            [24] 3345 	mov	dph, @r0
      000EFE 08               [12] 3346 	inc	r0
      000EFF 86 F0            [24] 3347 	mov	b, @r0
      000F01 08               [12] 3348 	inc	r0
      000F02 E6               [12] 3349 	mov	a, @r0
      000F03 12 26 2D         [24] 3350 	lcall	___fssub
      000F06 C8               [12] 3351 	xch	a,r0
      000F07 E5 08            [12] 3352 	mov	a,_bp
      000F09 24 05            [12] 3353 	add	a,#0x05
      000F0B C8               [12] 3354 	xch	a,r0
      000F0C A6 82            [24] 3355 	mov	@r0, dpl
      000F0E 08               [12] 3356 	inc	r0
      000F0F A6 83            [24] 3357 	mov	@r0, dph
      000F11 08               [12] 3358 	inc	r0
      000F12 A6 F0            [24] 3359 	mov	@r0, b
      000F14 08               [12] 3360 	inc	r0
      000F15 F6               [12] 3361 	mov	@r0,a
      000F16 E5 81            [12] 3362 	mov	a,sp
      000F18 24 FC            [12] 3363 	add	a,#0xfc
      000F1A F5 81            [12] 3364 	mov	sp,a
      000F1C E5 08            [12] 3365 	mov	a,_bp
      000F1E 24 FA            [12] 3366 	add	a,#0xfa
      000F20 F8               [12] 3367 	mov	r0,a
      000F21 86 82            [24] 3368 	mov	dpl, @r0
      000F23 08               [12] 3369 	inc	r0
      000F24 86 83            [24] 3370 	mov	dph, @r0
      000F26 08               [12] 3371 	inc	r0
      000F27 86 F0            [24] 3372 	mov	b, @r0
      000F29 08               [12] 3373 	inc	r0
      000F2A E6               [12] 3374 	mov	a, @r0
      000F2B 12 26 2D         [24] 3375 	lcall	___fssub
      000F2E AC 82            [24] 3376 	mov	r4, dpl
      000F30 AD 83            [24] 3377 	mov	r5, dph
      000F32 AE F0            [24] 3378 	mov	r6, b
      000F34 FF               [12] 3379 	mov	r7, a
      000F35 E5 81            [12] 3380 	mov	a,sp
      000F37 24 FC            [12] 3381 	add	a,#0xfc
      000F39 F5 81            [12] 3382 	mov	sp,a
      000F3B C0 04            [24] 3383 	push	ar4
      000F3D C0 05            [24] 3384 	push	ar5
      000F3F C0 06            [24] 3385 	push	ar6
      000F41 C0 07            [24] 3386 	push	ar7
      000F43 E5 08            [12] 3387 	mov	a,_bp
      000F45 24 05            [12] 3388 	add	a,#0x05
      000F47 F8               [12] 3389 	mov	r0,a
      000F48 86 82            [24] 3390 	mov	dpl, @r0
      000F4A 08               [12] 3391 	inc	r0
      000F4B 86 83            [24] 3392 	mov	dph, @r0
      000F4D 08               [12] 3393 	inc	r0
      000F4E 86 F0            [24] 3394 	mov	b, @r0
      000F50 08               [12] 3395 	inc	r0
      000F51 E6               [12] 3396 	mov	a, @r0
      000F52 12 28 D1         [24] 3397 	lcall	___fsdiv
      000F55 A8 08            [24] 3398 	mov	r0,_bp
      000F57 08               [12] 3399 	inc	r0
      000F58 A6 82            [24] 3400 	mov	@r0, dpl
      000F5A 08               [12] 3401 	inc	r0
      000F5B A6 83            [24] 3402 	mov	@r0, dph
      000F5D 08               [12] 3403 	inc	r0
      000F5E A6 F0            [24] 3404 	mov	@r0, b
      000F60 08               [12] 3405 	inc	r0
      000F61 F6               [12] 3406 	mov	@r0,a
      000F62 E5 81            [12] 3407 	mov	a,sp
      000F64 24 FC            [12] 3408 	add	a,#0xfc
      000F66 F5 81            [12] 3409 	mov	sp,a
      000F68 02 10 07         [24] 3410 	ljmp	00109$
      000F6B                       3411 00102$:
                           000EB4  3412 	C$fuzzy.h$1329$1_0$67 ==.
                                   3413 ;	../../fuzzy.h:1329: (c - value) /
      000F6B E5 08            [12] 3414 	mov	a,_bp
      000F6D 24 F2            [12] 3415 	add	a,#0xf2
      000F6F F8               [12] 3416 	mov	r0,a
      000F70 E6               [12] 3417 	mov	a,@r0
      000F71 C0 E0            [24] 3418 	push	acc
      000F73 08               [12] 3419 	inc	r0
      000F74 E6               [12] 3420 	mov	a,@r0
      000F75 C0 E0            [24] 3421 	push	acc
      000F77 08               [12] 3422 	inc	r0
      000F78 E6               [12] 3423 	mov	a,@r0
      000F79 C0 E0            [24] 3424 	push	acc
      000F7B 08               [12] 3425 	inc	r0
      000F7C E6               [12] 3426 	mov	a,@r0
      000F7D C0 E0            [24] 3427 	push	acc
                           000EC8  3428 	C$fuzzy.h$1330$1_0$67 ==.
                                   3429 ;	../../fuzzy.h:1330: (c - b);
      000F7F E5 08            [12] 3430 	mov	a,_bp
      000F81 24 F6            [12] 3431 	add	a,#0xf6
      000F83 F8               [12] 3432 	mov	r0,a
      000F84 86 82            [24] 3433 	mov	dpl, @r0
      000F86 08               [12] 3434 	inc	r0
      000F87 86 83            [24] 3435 	mov	dph, @r0
      000F89 08               [12] 3436 	inc	r0
      000F8A 86 F0            [24] 3437 	mov	b, @r0
      000F8C 08               [12] 3438 	inc	r0
      000F8D E6               [12] 3439 	mov	a, @r0
      000F8E 12 26 2D         [24] 3440 	lcall	___fssub
      000F91 C8               [12] 3441 	xch	a,r0
      000F92 E5 08            [12] 3442 	mov	a,_bp
      000F94 24 05            [12] 3443 	add	a,#0x05
      000F96 C8               [12] 3444 	xch	a,r0
      000F97 A6 82            [24] 3445 	mov	@r0, dpl
      000F99 08               [12] 3446 	inc	r0
      000F9A A6 83            [24] 3447 	mov	@r0, dph
      000F9C 08               [12] 3448 	inc	r0
      000F9D A6 F0            [24] 3449 	mov	@r0, b
      000F9F 08               [12] 3450 	inc	r0
      000FA0 F6               [12] 3451 	mov	@r0,a
      000FA1 E5 81            [12] 3452 	mov	a,sp
      000FA3 24 FC            [12] 3453 	add	a,#0xfc
      000FA5 F5 81            [12] 3454 	mov	sp,a
      000FA7 E5 08            [12] 3455 	mov	a,_bp
      000FA9 24 FA            [12] 3456 	add	a,#0xfa
      000FAB F8               [12] 3457 	mov	r0,a
      000FAC E6               [12] 3458 	mov	a,@r0
      000FAD C0 E0            [24] 3459 	push	acc
      000FAF 08               [12] 3460 	inc	r0
      000FB0 E6               [12] 3461 	mov	a,@r0
      000FB1 C0 E0            [24] 3462 	push	acc
      000FB3 08               [12] 3463 	inc	r0
      000FB4 E6               [12] 3464 	mov	a,@r0
      000FB5 C0 E0            [24] 3465 	push	acc
      000FB7 08               [12] 3466 	inc	r0
      000FB8 E6               [12] 3467 	mov	a,@r0
      000FB9 C0 E0            [24] 3468 	push	acc
      000FBB E5 08            [12] 3469 	mov	a,_bp
      000FBD 24 F6            [12] 3470 	add	a,#0xf6
      000FBF F8               [12] 3471 	mov	r0,a
      000FC0 86 82            [24] 3472 	mov	dpl, @r0
      000FC2 08               [12] 3473 	inc	r0
      000FC3 86 83            [24] 3474 	mov	dph, @r0
      000FC5 08               [12] 3475 	inc	r0
      000FC6 86 F0            [24] 3476 	mov	b, @r0
      000FC8 08               [12] 3477 	inc	r0
      000FC9 E6               [12] 3478 	mov	a, @r0
      000FCA 12 26 2D         [24] 3479 	lcall	___fssub
      000FCD AA 82            [24] 3480 	mov	r2, dpl
      000FCF AB 83            [24] 3481 	mov	r3, dph
      000FD1 AE F0            [24] 3482 	mov	r6, b
      000FD3 FF               [12] 3483 	mov	r7, a
      000FD4 E5 81            [12] 3484 	mov	a,sp
      000FD6 24 FC            [12] 3485 	add	a,#0xfc
      000FD8 F5 81            [12] 3486 	mov	sp,a
      000FDA C0 02            [24] 3487 	push	ar2
      000FDC C0 03            [24] 3488 	push	ar3
      000FDE C0 06            [24] 3489 	push	ar6
      000FE0 C0 07            [24] 3490 	push	ar7
      000FE2 E5 08            [12] 3491 	mov	a,_bp
      000FE4 24 05            [12] 3492 	add	a,#0x05
      000FE6 F8               [12] 3493 	mov	r0,a
      000FE7 86 82            [24] 3494 	mov	dpl, @r0
      000FE9 08               [12] 3495 	inc	r0
      000FEA 86 83            [24] 3496 	mov	dph, @r0
      000FEC 08               [12] 3497 	inc	r0
      000FED 86 F0            [24] 3498 	mov	b, @r0
      000FEF 08               [12] 3499 	inc	r0
      000FF0 E6               [12] 3500 	mov	a, @r0
      000FF1 12 28 D1         [24] 3501 	lcall	___fsdiv
      000FF4 A8 08            [24] 3502 	mov	r0,_bp
      000FF6 08               [12] 3503 	inc	r0
      000FF7 A6 82            [24] 3504 	mov	@r0, dpl
      000FF9 08               [12] 3505 	inc	r0
      000FFA A6 83            [24] 3506 	mov	@r0, dph
      000FFC 08               [12] 3507 	inc	r0
      000FFD A6 F0            [24] 3508 	mov	@r0, b
      000FFF 08               [12] 3509 	inc	r0
      001000 F6               [12] 3510 	mov	@r0,a
      001001 E5 81            [12] 3511 	mov	a,sp
      001003 24 FC            [12] 3512 	add	a,#0xfc
      001005 F5 81            [12] 3513 	mov	sp,a
      001007                       3514 00109$:
                           000F50  3515 	C$fuzzy.h$1334$1_0$67 ==.
                                   3516 ;	../../fuzzy.h:1334: result,
      001007 E5 08            [12] 3517 	mov	a,_bp
      001009 24 F1            [12] 3518 	add	a,#0xf1
      00100B F8               [12] 3519 	mov	r0,a
      00100C E6               [12] 3520 	mov	a,@r0
      00100D C0 E0            [24] 3521 	push	acc
      00100F A8 08            [24] 3522 	mov	r0,_bp
      001011 08               [12] 3523 	inc	r0
      001012 86 82            [24] 3524 	mov	dpl, @r0
      001014 08               [12] 3525 	inc	r0
      001015 86 83            [24] 3526 	mov	dph, @r0
      001017 08               [12] 3527 	inc	r0
      001018 86 F0            [24] 3528 	mov	b, @r0
      00101A 08               [12] 3529 	inc	r0
      00101B E6               [12] 3530 	mov	a, @r0
      00101C 12 01 99         [24] 3531 	lcall	_fuzzy_apply_hedge
      00101F AC 82            [24] 3532 	mov	r4, dpl
      001021 AD 83            [24] 3533 	mov	r5, dph
      001023 AE F0            [24] 3534 	mov	r6, b
      001025 FF               [12] 3535 	mov	r7, a
      001026 15 81            [12] 3536 	dec	sp
      001028 8C 82            [24] 3537 	mov	dpl, r4
      00102A 8D 83            [24] 3538 	mov	dph, r5
      00102C 8E F0            [24] 3539 	mov	b, r6
      00102E EF               [12] 3540 	mov	a, r7
                           000F78  3541 	C$fuzzy.h$1337$1_0$67 ==.
                                   3542 ;	../../fuzzy.h:1337: }
      00102F 85 08 81         [24] 3543 	mov	sp,_bp
      001032 D0 08            [24] 3544 	pop	_bp
                           000F7D  3545 	C$fuzzy.h$1337$1_0$67 ==.
                           000F7D  3546 	XG$fuzzy_triangle$0$0 ==.
      001034 22               [24] 3547 	ret
                                   3548 ;------------------------------------------------------------
                                   3549 ;Allocation info for local variables in function 'fuzzy_trapezoid'
                                   3550 ;------------------------------------------------------------
                                   3551 ;b             Allocated to stack - _bp -6 +4 
                                   3552 ;c             Allocated to stack - _bp -10 +4 
                                   3553 ;d             Allocated to stack - _bp -14 +4 
                                   3554 ;value         Allocated to stack - _bp -18 +4 
                                   3555 ;hedge         Allocated to stack - _bp -19 +1 
                                   3556 ;a             Allocated to registers r7 r6 r5 r4 
                                   3557 ;result        Allocated to stack - _bp +1 +4 
                                   3558 ;sloc0         Allocated to stack - _bp +1 +4 
                                   3559 ;sloc1         Allocated to stack - _bp +5 +4 
                                   3560 ;------------------------------------------------------------
                           000F7E  3561 	G$fuzzy_trapezoid$0$0 ==.
                           000F7E  3562 	C$fuzzy.h$1339$1_0$73 ==.
                                   3563 ;	../../fuzzy.h:1339: float fuzzy_trapezoid(
                                   3564 ;	-----------------------------------------
                                   3565 ;	 function fuzzy_trapezoid
                                   3566 ;	-----------------------------------------
      001035                       3567 _fuzzy_trapezoid:
      001035 C0 08            [24] 3568 	push	_bp
      001037 85 81 08         [24] 3569 	mov	_bp,sp
      00103A AF 82            [24] 3570 	mov	r7,dpl
      00103C AE 83            [24] 3571 	mov	r6,dph
      00103E AD F0            [24] 3572 	mov	r5,b
      001040 FC               [12] 3573 	mov	r4,a
      001041 E5 81            [12] 3574 	mov	a,sp
      001043 24 08            [12] 3575 	add	a,#0x08
      001045 F5 81            [12] 3576 	mov	sp,a
                           000F90  3577 	C$fuzzy.h$1351$1_0$73 ==.
                                   3578 ;	../../fuzzy.h:1351: a >= b ||
      001047 C0 07            [24] 3579 	push	ar7
      001049 C0 06            [24] 3580 	push	ar6
      00104B C0 05            [24] 3581 	push	ar5
      00104D C0 04            [24] 3582 	push	ar4
      00104F E5 08            [12] 3583 	mov	a,_bp
      001051 24 FA            [12] 3584 	add	a,#0xfa
      001053 F8               [12] 3585 	mov	r0,a
      001054 E6               [12] 3586 	mov	a,@r0
      001055 C0 E0            [24] 3587 	push	acc
      001057 08               [12] 3588 	inc	r0
      001058 E6               [12] 3589 	mov	a,@r0
      001059 C0 E0            [24] 3590 	push	acc
      00105B 08               [12] 3591 	inc	r0
      00105C E6               [12] 3592 	mov	a,@r0
      00105D C0 E0            [24] 3593 	push	acc
      00105F 08               [12] 3594 	inc	r0
      001060 E6               [12] 3595 	mov	a,@r0
      001061 C0 E0            [24] 3596 	push	acc
      001063 8F 82            [24] 3597 	mov	dpl, r7
      001065 8E 83            [24] 3598 	mov	dph, r6
      001067 8D F0            [24] 3599 	mov	b, r5
      001069 EC               [12] 3600 	mov	a, r4
      00106A 12 27 68         [24] 3601 	lcall	___fslt
      00106D E5 81            [12] 3602 	mov	a,sp
      00106F 24 FC            [12] 3603 	add	a,#0xfc
      001071 F5 81            [12] 3604 	mov	sp,a
      001073 D0 04            [24] 3605 	pop	ar4
      001075 D0 05            [24] 3606 	pop	ar5
      001077 D0 06            [24] 3607 	pop	ar6
      001079 D0 07            [24] 3608 	pop	ar7
      00107B E5 82            [12] 3609 	mov	a, dpl
      00107D 24 FF            [12] 3610 	add	a,#0xff
      00107F 92 00            [24] 3611 	mov	b0,c
      001081 40 03            [24] 3612 	jc	00159$
      001083 02 11 91         [24] 3613 	ljmp	00108$
      001086                       3614 00159$:
                           000FCF  3615 	C$fuzzy.h$1352$1_0$73 ==.
                                   3616 ;	../../fuzzy.h:1352: b > c ||
      001086 C0 07            [24] 3617 	push	ar7
      001088 C0 06            [24] 3618 	push	ar6
      00108A C0 05            [24] 3619 	push	ar5
      00108C C0 04            [24] 3620 	push	ar4
      00108E E5 08            [12] 3621 	mov	a,_bp
      001090 24 FA            [12] 3622 	add	a,#0xfa
      001092 F8               [12] 3623 	mov	r0,a
      001093 E6               [12] 3624 	mov	a,@r0
      001094 C0 E0            [24] 3625 	push	acc
      001096 08               [12] 3626 	inc	r0
      001097 E6               [12] 3627 	mov	a,@r0
      001098 C0 E0            [24] 3628 	push	acc
      00109A 08               [12] 3629 	inc	r0
      00109B E6               [12] 3630 	mov	a,@r0
      00109C C0 E0            [24] 3631 	push	acc
      00109E 08               [12] 3632 	inc	r0
      00109F E6               [12] 3633 	mov	a,@r0
      0010A0 C0 E0            [24] 3634 	push	acc
      0010A2 E5 08            [12] 3635 	mov	a,_bp
      0010A4 24 F6            [12] 3636 	add	a,#0xf6
      0010A6 F8               [12] 3637 	mov	r0,a
      0010A7 86 82            [24] 3638 	mov	dpl, @r0
      0010A9 08               [12] 3639 	inc	r0
      0010AA 86 83            [24] 3640 	mov	dph, @r0
      0010AC 08               [12] 3641 	inc	r0
      0010AD 86 F0            [24] 3642 	mov	b, @r0
      0010AF 08               [12] 3643 	inc	r0
      0010B0 E6               [12] 3644 	mov	a, @r0
      0010B1 12 27 68         [24] 3645 	lcall	___fslt
      0010B4 AB 82            [24] 3646 	mov	r3, dpl
      0010B6 E5 81            [12] 3647 	mov	a,sp
      0010B8 24 FC            [12] 3648 	add	a,#0xfc
      0010BA F5 81            [12] 3649 	mov	sp,a
      0010BC D0 04            [24] 3650 	pop	ar4
      0010BE D0 05            [24] 3651 	pop	ar5
      0010C0 D0 06            [24] 3652 	pop	ar6
      0010C2 D0 07            [24] 3653 	pop	ar7
      0010C4 EB               [12] 3654 	mov	a,r3
      0010C5 60 03            [24] 3655 	jz	00160$
      0010C7 02 11 91         [24] 3656 	ljmp	00108$
      0010CA                       3657 00160$:
                           001013  3658 	C$fuzzy.h$1353$1_0$73 ==.
                                   3659 ;	../../fuzzy.h:1353: c >= d ||
      0010CA C0 07            [24] 3660 	push	ar7
      0010CC C0 06            [24] 3661 	push	ar6
      0010CE C0 05            [24] 3662 	push	ar5
      0010D0 C0 04            [24] 3663 	push	ar4
      0010D2 E5 08            [12] 3664 	mov	a,_bp
      0010D4 24 F2            [12] 3665 	add	a,#0xf2
      0010D6 F8               [12] 3666 	mov	r0,a
      0010D7 E6               [12] 3667 	mov	a,@r0
      0010D8 C0 E0            [24] 3668 	push	acc
      0010DA 08               [12] 3669 	inc	r0
      0010DB E6               [12] 3670 	mov	a,@r0
      0010DC C0 E0            [24] 3671 	push	acc
      0010DE 08               [12] 3672 	inc	r0
      0010DF E6               [12] 3673 	mov	a,@r0
      0010E0 C0 E0            [24] 3674 	push	acc
      0010E2 08               [12] 3675 	inc	r0
      0010E3 E6               [12] 3676 	mov	a,@r0
      0010E4 C0 E0            [24] 3677 	push	acc
      0010E6 E5 08            [12] 3678 	mov	a,_bp
      0010E8 24 F6            [12] 3679 	add	a,#0xf6
      0010EA F8               [12] 3680 	mov	r0,a
      0010EB 86 82            [24] 3681 	mov	dpl, @r0
      0010ED 08               [12] 3682 	inc	r0
      0010EE 86 83            [24] 3683 	mov	dph, @r0
      0010F0 08               [12] 3684 	inc	r0
      0010F1 86 F0            [24] 3685 	mov	b, @r0
      0010F3 08               [12] 3686 	inc	r0
      0010F4 E6               [12] 3687 	mov	a, @r0
      0010F5 12 27 68         [24] 3688 	lcall	___fslt
      0010F8 E5 81            [12] 3689 	mov	a,sp
      0010FA 24 FC            [12] 3690 	add	a,#0xfc
      0010FC F5 81            [12] 3691 	mov	sp,a
      0010FE D0 04            [24] 3692 	pop	ar4
      001100 D0 05            [24] 3693 	pop	ar5
      001102 D0 06            [24] 3694 	pop	ar6
      001104 D0 07            [24] 3695 	pop	ar7
      001106 E5 82            [12] 3696 	mov	a, dpl
      001108 24 FF            [12] 3697 	add	a,#0xff
      00110A 92 00            [24] 3698 	mov	b0,c
      00110C 40 03            [24] 3699 	jc	00161$
      00110E 02 11 91         [24] 3700 	ljmp	00108$
      001111                       3701 00161$:
                           00105A  3702 	C$fuzzy.h$1354$1_0$73 ==.
                                   3703 ;	../../fuzzy.h:1354: value <= a ||
      001111 C0 07            [24] 3704 	push	ar7
      001113 C0 06            [24] 3705 	push	ar6
      001115 C0 05            [24] 3706 	push	ar5
      001117 C0 04            [24] 3707 	push	ar4
      001119 E5 08            [12] 3708 	mov	a,_bp
      00111B 24 EE            [12] 3709 	add	a,#0xee
      00111D F8               [12] 3710 	mov	r0,a
      00111E E6               [12] 3711 	mov	a,@r0
      00111F C0 E0            [24] 3712 	push	acc
      001121 08               [12] 3713 	inc	r0
      001122 E6               [12] 3714 	mov	a,@r0
      001123 C0 E0            [24] 3715 	push	acc
      001125 08               [12] 3716 	inc	r0
      001126 E6               [12] 3717 	mov	a,@r0
      001127 C0 E0            [24] 3718 	push	acc
      001129 08               [12] 3719 	inc	r0
      00112A E6               [12] 3720 	mov	a,@r0
      00112B C0 E0            [24] 3721 	push	acc
      00112D 8F 82            [24] 3722 	mov	dpl, r7
      00112F 8E 83            [24] 3723 	mov	dph, r6
      001131 8D F0            [24] 3724 	mov	b, r5
      001133 EC               [12] 3725 	mov	a, r4
      001134 12 27 68         [24] 3726 	lcall	___fslt
      001137 E5 81            [12] 3727 	mov	a,sp
      001139 24 FC            [12] 3728 	add	a,#0xfc
      00113B F5 81            [12] 3729 	mov	sp,a
      00113D D0 04            [24] 3730 	pop	ar4
      00113F D0 05            [24] 3731 	pop	ar5
      001141 D0 06            [24] 3732 	pop	ar6
      001143 D0 07            [24] 3733 	pop	ar7
      001145 E5 82            [12] 3734 	mov	a, dpl
      001147 24 FF            [12] 3735 	add	a,#0xff
      001149 92 00            [24] 3736 	mov	b0,c
      00114B 50 44            [24] 3737 	jnc	00108$
                           001096  3738 	C$fuzzy.h$1356$1_0$73 ==.
                                   3739 ;	../../fuzzy.h:1356: ) {
      00114D C0 07            [24] 3740 	push	ar7
      00114F C0 06            [24] 3741 	push	ar6
      001151 C0 05            [24] 3742 	push	ar5
      001153 C0 04            [24] 3743 	push	ar4
      001155 E5 08            [12] 3744 	mov	a,_bp
      001157 24 F2            [12] 3745 	add	a,#0xf2
      001159 F8               [12] 3746 	mov	r0,a
      00115A E6               [12] 3747 	mov	a,@r0
      00115B C0 E0            [24] 3748 	push	acc
      00115D 08               [12] 3749 	inc	r0
      00115E E6               [12] 3750 	mov	a,@r0
      00115F C0 E0            [24] 3751 	push	acc
      001161 08               [12] 3752 	inc	r0
      001162 E6               [12] 3753 	mov	a,@r0
      001163 C0 E0            [24] 3754 	push	acc
      001165 08               [12] 3755 	inc	r0
      001166 E6               [12] 3756 	mov	a,@r0
      001167 C0 E0            [24] 3757 	push	acc
      001169 E5 08            [12] 3758 	mov	a,_bp
      00116B 24 EE            [12] 3759 	add	a,#0xee
      00116D F8               [12] 3760 	mov	r0,a
      00116E 86 82            [24] 3761 	mov	dpl, @r0
      001170 08               [12] 3762 	inc	r0
      001171 86 83            [24] 3763 	mov	dph, @r0
      001173 08               [12] 3764 	inc	r0
      001174 86 F0            [24] 3765 	mov	b, @r0
      001176 08               [12] 3766 	inc	r0
      001177 E6               [12] 3767 	mov	a, @r0
      001178 12 27 68         [24] 3768 	lcall	___fslt
      00117B E5 81            [12] 3769 	mov	a,sp
      00117D 24 FC            [12] 3770 	add	a,#0xfc
      00117F F5 81            [12] 3771 	mov	sp,a
      001181 D0 04            [24] 3772 	pop	ar4
      001183 D0 05            [24] 3773 	pop	ar5
      001185 D0 06            [24] 3774 	pop	ar6
      001187 D0 07            [24] 3775 	pop	ar7
      001189 E5 82            [12] 3776 	mov	a, dpl
      00118B 24 FF            [12] 3777 	add	a,#0xff
      00118D 92 00            [24] 3778 	mov	b0,c
      00118F 40 0E            [24] 3779 	jc	00109$
      001191                       3780 00108$:
                           0010DA  3781 	C$fuzzy.h$1357$2_0$74 ==.
                                   3782 ;	../../fuzzy.h:1357: result = LEVEL_LO;
      001191 A8 08            [24] 3783 	mov	r0,_bp
      001193 08               [12] 3784 	inc	r0
      001194 E4               [12] 3785 	clr	a
      001195 F6               [12] 3786 	mov	@r0,a
      001196 08               [12] 3787 	inc	r0
      001197 F6               [12] 3788 	mov	@r0,a
      001198 08               [12] 3789 	inc	r0
      001199 F6               [12] 3790 	mov	@r0,a
      00119A 08               [12] 3791 	inc	r0
      00119B F6               [12] 3792 	mov	@r0,a
      00119C 02 13 9E         [24] 3793 	ljmp	00110$
      00119F                       3794 00109$:
                           0010E8  3795 	C$fuzzy.h$1360$1_0$73 ==.
                                   3796 ;	../../fuzzy.h:1360: value >= b &&
      00119F C0 07            [24] 3797 	push	ar7
      0011A1 C0 06            [24] 3798 	push	ar6
      0011A3 C0 05            [24] 3799 	push	ar5
      0011A5 C0 04            [24] 3800 	push	ar4
      0011A7 E5 08            [12] 3801 	mov	a,_bp
      0011A9 24 FA            [12] 3802 	add	a,#0xfa
      0011AB F8               [12] 3803 	mov	r0,a
      0011AC E6               [12] 3804 	mov	a,@r0
      0011AD C0 E0            [24] 3805 	push	acc
      0011AF 08               [12] 3806 	inc	r0
      0011B0 E6               [12] 3807 	mov	a,@r0
      0011B1 C0 E0            [24] 3808 	push	acc
      0011B3 08               [12] 3809 	inc	r0
      0011B4 E6               [12] 3810 	mov	a,@r0
      0011B5 C0 E0            [24] 3811 	push	acc
      0011B7 08               [12] 3812 	inc	r0
      0011B8 E6               [12] 3813 	mov	a,@r0
      0011B9 C0 E0            [24] 3814 	push	acc
      0011BB E5 08            [12] 3815 	mov	a,_bp
      0011BD 24 EE            [12] 3816 	add	a,#0xee
      0011BF F8               [12] 3817 	mov	r0,a
      0011C0 86 82            [24] 3818 	mov	dpl, @r0
      0011C2 08               [12] 3819 	inc	r0
      0011C3 86 83            [24] 3820 	mov	dph, @r0
      0011C5 08               [12] 3821 	inc	r0
      0011C6 86 F0            [24] 3822 	mov	b, @r0
      0011C8 08               [12] 3823 	inc	r0
      0011C9 E6               [12] 3824 	mov	a, @r0
      0011CA 12 27 68         [24] 3825 	lcall	___fslt
      0011CD E5 81            [12] 3826 	mov	a,sp
      0011CF 24 FC            [12] 3827 	add	a,#0xfc
      0011D1 F5 81            [12] 3828 	mov	sp,a
      0011D3 D0 04            [24] 3829 	pop	ar4
      0011D5 D0 05            [24] 3830 	pop	ar5
      0011D7 D0 06            [24] 3831 	pop	ar6
      0011D9 D0 07            [24] 3832 	pop	ar7
      0011DB E5 82            [12] 3833 	mov	a, dpl
      0011DD 24 FF            [12] 3834 	add	a,#0xff
      0011DF 92 00            [24] 3835 	mov	b0,c
      0011E1 40 54            [24] 3836 	jc	00105$
                           00112C  3837 	C$fuzzy.h$1362$1_0$73 ==.
                                   3838 ;	../../fuzzy.h:1362: ) {
      0011E3 C0 07            [24] 3839 	push	ar7
      0011E5 C0 06            [24] 3840 	push	ar6
      0011E7 C0 05            [24] 3841 	push	ar5
      0011E9 C0 04            [24] 3842 	push	ar4
      0011EB E5 08            [12] 3843 	mov	a,_bp
      0011ED 24 EE            [12] 3844 	add	a,#0xee
      0011EF F8               [12] 3845 	mov	r0,a
      0011F0 E6               [12] 3846 	mov	a,@r0
      0011F1 C0 E0            [24] 3847 	push	acc
      0011F3 08               [12] 3848 	inc	r0
      0011F4 E6               [12] 3849 	mov	a,@r0
      0011F5 C0 E0            [24] 3850 	push	acc
      0011F7 08               [12] 3851 	inc	r0
      0011F8 E6               [12] 3852 	mov	a,@r0
      0011F9 C0 E0            [24] 3853 	push	acc
      0011FB 08               [12] 3854 	inc	r0
      0011FC E6               [12] 3855 	mov	a,@r0
      0011FD C0 E0            [24] 3856 	push	acc
      0011FF E5 08            [12] 3857 	mov	a,_bp
      001201 24 F6            [12] 3858 	add	a,#0xf6
      001203 F8               [12] 3859 	mov	r0,a
      001204 86 82            [24] 3860 	mov	dpl, @r0
      001206 08               [12] 3861 	inc	r0
      001207 86 83            [24] 3862 	mov	dph, @r0
      001209 08               [12] 3863 	inc	r0
      00120A 86 F0            [24] 3864 	mov	b, @r0
      00120C 08               [12] 3865 	inc	r0
      00120D E6               [12] 3866 	mov	a, @r0
      00120E 12 27 68         [24] 3867 	lcall	___fslt
      001211 E5 81            [12] 3868 	mov	a,sp
      001213 24 FC            [12] 3869 	add	a,#0xfc
      001215 F5 81            [12] 3870 	mov	sp,a
      001217 D0 04            [24] 3871 	pop	ar4
      001219 D0 05            [24] 3872 	pop	ar5
      00121B D0 06            [24] 3873 	pop	ar6
      00121D D0 07            [24] 3874 	pop	ar7
      00121F E5 82            [12] 3875 	mov	a, dpl
      001221 24 FF            [12] 3876 	add	a,#0xff
      001223 92 00            [24] 3877 	mov	b0,c
      001225 40 10            [24] 3878 	jc	00105$
                           001170  3879 	C$fuzzy.h$1363$2_0$75 ==.
                                   3880 ;	../../fuzzy.h:1363: result = LEVEL_HI;
      001227 A8 08            [24] 3881 	mov	r0,_bp
      001229 08               [12] 3882 	inc	r0
      00122A E4               [12] 3883 	clr	a
      00122B F6               [12] 3884 	mov	@r0,a
      00122C 08               [12] 3885 	inc	r0
      00122D F6               [12] 3886 	mov	@r0,a
      00122E 08               [12] 3887 	inc	r0
      00122F 76 80            [12] 3888 	mov	@r0,#0x80
      001231 08               [12] 3889 	inc	r0
      001232 76 3F            [12] 3890 	mov	@r0,#0x3f
      001234 02 13 9E         [24] 3891 	ljmp	00110$
      001237                       3892 00105$:
                           001180  3893 	C$fuzzy.h$1365$1_0$73 ==.
                                   3894 ;	../../fuzzy.h:1365: else if (value < b) {
      001237 C0 07            [24] 3895 	push	ar7
      001239 C0 06            [24] 3896 	push	ar6
      00123B C0 05            [24] 3897 	push	ar5
      00123D C0 04            [24] 3898 	push	ar4
      00123F E5 08            [12] 3899 	mov	a,_bp
      001241 24 FA            [12] 3900 	add	a,#0xfa
      001243 F8               [12] 3901 	mov	r0,a
      001244 E6               [12] 3902 	mov	a,@r0
      001245 C0 E0            [24] 3903 	push	acc
      001247 08               [12] 3904 	inc	r0
      001248 E6               [12] 3905 	mov	a,@r0
      001249 C0 E0            [24] 3906 	push	acc
      00124B 08               [12] 3907 	inc	r0
      00124C E6               [12] 3908 	mov	a,@r0
      00124D C0 E0            [24] 3909 	push	acc
      00124F 08               [12] 3910 	inc	r0
      001250 E6               [12] 3911 	mov	a,@r0
      001251 C0 E0            [24] 3912 	push	acc
      001253 E5 08            [12] 3913 	mov	a,_bp
      001255 24 EE            [12] 3914 	add	a,#0xee
      001257 F8               [12] 3915 	mov	r0,a
      001258 86 82            [24] 3916 	mov	dpl, @r0
      00125A 08               [12] 3917 	inc	r0
      00125B 86 83            [24] 3918 	mov	dph, @r0
      00125D 08               [12] 3919 	inc	r0
      00125E 86 F0            [24] 3920 	mov	b, @r0
      001260 08               [12] 3921 	inc	r0
      001261 E6               [12] 3922 	mov	a, @r0
      001262 12 27 68         [24] 3923 	lcall	___fslt
      001265 AB 82            [24] 3924 	mov	r3, dpl
      001267 E5 81            [12] 3925 	mov	a,sp
      001269 24 FC            [12] 3926 	add	a,#0xfc
      00126B F5 81            [12] 3927 	mov	sp,a
      00126D D0 04            [24] 3928 	pop	ar4
      00126F D0 05            [24] 3929 	pop	ar5
      001271 D0 06            [24] 3930 	pop	ar6
      001273 D0 07            [24] 3931 	pop	ar7
      001275 EB               [12] 3932 	mov	a,r3
      001276 70 03            [24] 3933 	jnz	00166$
      001278 02 13 02         [24] 3934 	ljmp	00102$
      00127B                       3935 00166$:
                           0011C4  3936 	C$fuzzy.h$1367$1_0$73 ==.
                                   3937 ;	../../fuzzy.h:1367: (value - a) /
      00127B C0 07            [24] 3938 	push	ar7
      00127D C0 06            [24] 3939 	push	ar6
      00127F C0 05            [24] 3940 	push	ar5
      001281 C0 04            [24] 3941 	push	ar4
      001283 C0 07            [24] 3942 	push	ar7
      001285 C0 06            [24] 3943 	push	ar6
      001287 C0 05            [24] 3944 	push	ar5
      001289 C0 04            [24] 3945 	push	ar4
                           0011D4  3946 	C$fuzzy.h$1368$1_0$73 ==.
                                   3947 ;	../../fuzzy.h:1368: (b - a);
      00128B E5 08            [12] 3948 	mov	a,_bp
      00128D 24 EE            [12] 3949 	add	a,#0xee
      00128F F8               [12] 3950 	mov	r0,a
      001290 86 82            [24] 3951 	mov	dpl, @r0
      001292 08               [12] 3952 	inc	r0
      001293 86 83            [24] 3953 	mov	dph, @r0
      001295 08               [12] 3954 	inc	r0
      001296 86 F0            [24] 3955 	mov	b, @r0
      001298 08               [12] 3956 	inc	r0
      001299 E6               [12] 3957 	mov	a, @r0
      00129A 12 26 2D         [24] 3958 	lcall	___fssub
      00129D C8               [12] 3959 	xch	a,r0
      00129E E5 08            [12] 3960 	mov	a,_bp
      0012A0 24 05            [12] 3961 	add	a,#0x05
      0012A2 C8               [12] 3962 	xch	a,r0
      0012A3 A6 82            [24] 3963 	mov	@r0, dpl
      0012A5 08               [12] 3964 	inc	r0
      0012A6 A6 83            [24] 3965 	mov	@r0, dph
      0012A8 08               [12] 3966 	inc	r0
      0012A9 A6 F0            [24] 3967 	mov	@r0, b
      0012AB 08               [12] 3968 	inc	r0
      0012AC F6               [12] 3969 	mov	@r0,a
      0012AD E5 81            [12] 3970 	mov	a,sp
      0012AF 24 FC            [12] 3971 	add	a,#0xfc
      0012B1 F5 81            [12] 3972 	mov	sp,a
      0012B3 E5 08            [12] 3973 	mov	a,_bp
      0012B5 24 FA            [12] 3974 	add	a,#0xfa
      0012B7 F8               [12] 3975 	mov	r0,a
      0012B8 86 82            [24] 3976 	mov	dpl, @r0
      0012BA 08               [12] 3977 	inc	r0
      0012BB 86 83            [24] 3978 	mov	dph, @r0
      0012BD 08               [12] 3979 	inc	r0
      0012BE 86 F0            [24] 3980 	mov	b, @r0
      0012C0 08               [12] 3981 	inc	r0
      0012C1 E6               [12] 3982 	mov	a, @r0
      0012C2 12 26 2D         [24] 3983 	lcall	___fssub
      0012C5 AC 82            [24] 3984 	mov	r4, dpl
      0012C7 AD 83            [24] 3985 	mov	r5, dph
      0012C9 AE F0            [24] 3986 	mov	r6, b
      0012CB FF               [12] 3987 	mov	r7, a
      0012CC E5 81            [12] 3988 	mov	a,sp
      0012CE 24 FC            [12] 3989 	add	a,#0xfc
      0012D0 F5 81            [12] 3990 	mov	sp,a
      0012D2 C0 04            [24] 3991 	push	ar4
      0012D4 C0 05            [24] 3992 	push	ar5
      0012D6 C0 06            [24] 3993 	push	ar6
      0012D8 C0 07            [24] 3994 	push	ar7
      0012DA E5 08            [12] 3995 	mov	a,_bp
      0012DC 24 05            [12] 3996 	add	a,#0x05
      0012DE F8               [12] 3997 	mov	r0,a
      0012DF 86 82            [24] 3998 	mov	dpl, @r0
      0012E1 08               [12] 3999 	inc	r0
      0012E2 86 83            [24] 4000 	mov	dph, @r0
      0012E4 08               [12] 4001 	inc	r0
      0012E5 86 F0            [24] 4002 	mov	b, @r0
      0012E7 08               [12] 4003 	inc	r0
      0012E8 E6               [12] 4004 	mov	a, @r0
      0012E9 12 28 D1         [24] 4005 	lcall	___fsdiv
      0012EC A8 08            [24] 4006 	mov	r0,_bp
      0012EE 08               [12] 4007 	inc	r0
      0012EF A6 82            [24] 4008 	mov	@r0, dpl
      0012F1 08               [12] 4009 	inc	r0
      0012F2 A6 83            [24] 4010 	mov	@r0, dph
      0012F4 08               [12] 4011 	inc	r0
      0012F5 A6 F0            [24] 4012 	mov	@r0, b
      0012F7 08               [12] 4013 	inc	r0
      0012F8 F6               [12] 4014 	mov	@r0,a
      0012F9 E5 81            [12] 4015 	mov	a,sp
      0012FB 24 FC            [12] 4016 	add	a,#0xfc
      0012FD F5 81            [12] 4017 	mov	sp,a
      0012FF 02 13 9E         [24] 4018 	ljmp	00110$
      001302                       4019 00102$:
                           00124B  4020 	C$fuzzy.h$1372$1_0$73 ==.
                                   4021 ;	../../fuzzy.h:1372: (d - value) /
      001302 E5 08            [12] 4022 	mov	a,_bp
      001304 24 EE            [12] 4023 	add	a,#0xee
      001306 F8               [12] 4024 	mov	r0,a
      001307 E6               [12] 4025 	mov	a,@r0
      001308 C0 E0            [24] 4026 	push	acc
      00130A 08               [12] 4027 	inc	r0
      00130B E6               [12] 4028 	mov	a,@r0
      00130C C0 E0            [24] 4029 	push	acc
      00130E 08               [12] 4030 	inc	r0
      00130F E6               [12] 4031 	mov	a,@r0
      001310 C0 E0            [24] 4032 	push	acc
      001312 08               [12] 4033 	inc	r0
      001313 E6               [12] 4034 	mov	a,@r0
      001314 C0 E0            [24] 4035 	push	acc
                           00125F  4036 	C$fuzzy.h$1373$1_0$73 ==.
                                   4037 ;	../../fuzzy.h:1373: (d - c);
      001316 E5 08            [12] 4038 	mov	a,_bp
      001318 24 F2            [12] 4039 	add	a,#0xf2
      00131A F8               [12] 4040 	mov	r0,a
      00131B 86 82            [24] 4041 	mov	dpl, @r0
      00131D 08               [12] 4042 	inc	r0
      00131E 86 83            [24] 4043 	mov	dph, @r0
      001320 08               [12] 4044 	inc	r0
      001321 86 F0            [24] 4045 	mov	b, @r0
      001323 08               [12] 4046 	inc	r0
      001324 E6               [12] 4047 	mov	a, @r0
      001325 12 26 2D         [24] 4048 	lcall	___fssub
      001328 C8               [12] 4049 	xch	a,r0
      001329 E5 08            [12] 4050 	mov	a,_bp
      00132B 24 05            [12] 4051 	add	a,#0x05
      00132D C8               [12] 4052 	xch	a,r0
      00132E A6 82            [24] 4053 	mov	@r0, dpl
      001330 08               [12] 4054 	inc	r0
      001331 A6 83            [24] 4055 	mov	@r0, dph
      001333 08               [12] 4056 	inc	r0
      001334 A6 F0            [24] 4057 	mov	@r0, b
      001336 08               [12] 4058 	inc	r0
      001337 F6               [12] 4059 	mov	@r0,a
      001338 E5 81            [12] 4060 	mov	a,sp
      00133A 24 FC            [12] 4061 	add	a,#0xfc
      00133C F5 81            [12] 4062 	mov	sp,a
      00133E E5 08            [12] 4063 	mov	a,_bp
      001340 24 F6            [12] 4064 	add	a,#0xf6
      001342 F8               [12] 4065 	mov	r0,a
      001343 E6               [12] 4066 	mov	a,@r0
      001344 C0 E0            [24] 4067 	push	acc
      001346 08               [12] 4068 	inc	r0
      001347 E6               [12] 4069 	mov	a,@r0
      001348 C0 E0            [24] 4070 	push	acc
      00134A 08               [12] 4071 	inc	r0
      00134B E6               [12] 4072 	mov	a,@r0
      00134C C0 E0            [24] 4073 	push	acc
      00134E 08               [12] 4074 	inc	r0
      00134F E6               [12] 4075 	mov	a,@r0
      001350 C0 E0            [24] 4076 	push	acc
      001352 E5 08            [12] 4077 	mov	a,_bp
      001354 24 F2            [12] 4078 	add	a,#0xf2
      001356 F8               [12] 4079 	mov	r0,a
      001357 86 82            [24] 4080 	mov	dpl, @r0
      001359 08               [12] 4081 	inc	r0
      00135A 86 83            [24] 4082 	mov	dph, @r0
      00135C 08               [12] 4083 	inc	r0
      00135D 86 F0            [24] 4084 	mov	b, @r0
      00135F 08               [12] 4085 	inc	r0
      001360 E6               [12] 4086 	mov	a, @r0
      001361 12 26 2D         [24] 4087 	lcall	___fssub
      001364 AA 82            [24] 4088 	mov	r2, dpl
      001366 AB 83            [24] 4089 	mov	r3, dph
      001368 AE F0            [24] 4090 	mov	r6, b
      00136A FF               [12] 4091 	mov	r7, a
      00136B E5 81            [12] 4092 	mov	a,sp
      00136D 24 FC            [12] 4093 	add	a,#0xfc
      00136F F5 81            [12] 4094 	mov	sp,a
      001371 C0 02            [24] 4095 	push	ar2
      001373 C0 03            [24] 4096 	push	ar3
      001375 C0 06            [24] 4097 	push	ar6
      001377 C0 07            [24] 4098 	push	ar7
      001379 E5 08            [12] 4099 	mov	a,_bp
      00137B 24 05            [12] 4100 	add	a,#0x05
      00137D F8               [12] 4101 	mov	r0,a
      00137E 86 82            [24] 4102 	mov	dpl, @r0
      001380 08               [12] 4103 	inc	r0
      001381 86 83            [24] 4104 	mov	dph, @r0
      001383 08               [12] 4105 	inc	r0
      001384 86 F0            [24] 4106 	mov	b, @r0
      001386 08               [12] 4107 	inc	r0
      001387 E6               [12] 4108 	mov	a, @r0
      001388 12 28 D1         [24] 4109 	lcall	___fsdiv
      00138B A8 08            [24] 4110 	mov	r0,_bp
      00138D 08               [12] 4111 	inc	r0
      00138E A6 82            [24] 4112 	mov	@r0, dpl
      001390 08               [12] 4113 	inc	r0
      001391 A6 83            [24] 4114 	mov	@r0, dph
      001393 08               [12] 4115 	inc	r0
      001394 A6 F0            [24] 4116 	mov	@r0, b
      001396 08               [12] 4117 	inc	r0
      001397 F6               [12] 4118 	mov	@r0,a
      001398 E5 81            [12] 4119 	mov	a,sp
      00139A 24 FC            [12] 4120 	add	a,#0xfc
      00139C F5 81            [12] 4121 	mov	sp,a
      00139E                       4122 00110$:
                           0012E7  4123 	C$fuzzy.h$1377$1_0$73 ==.
                                   4124 ;	../../fuzzy.h:1377: result,
      00139E E5 08            [12] 4125 	mov	a,_bp
      0013A0 24 ED            [12] 4126 	add	a,#0xed
      0013A2 F8               [12] 4127 	mov	r0,a
      0013A3 E6               [12] 4128 	mov	a,@r0
      0013A4 C0 E0            [24] 4129 	push	acc
      0013A6 A8 08            [24] 4130 	mov	r0,_bp
      0013A8 08               [12] 4131 	inc	r0
      0013A9 86 82            [24] 4132 	mov	dpl, @r0
      0013AB 08               [12] 4133 	inc	r0
      0013AC 86 83            [24] 4134 	mov	dph, @r0
      0013AE 08               [12] 4135 	inc	r0
      0013AF 86 F0            [24] 4136 	mov	b, @r0
      0013B1 08               [12] 4137 	inc	r0
      0013B2 E6               [12] 4138 	mov	a, @r0
      0013B3 12 01 99         [24] 4139 	lcall	_fuzzy_apply_hedge
      0013B6 AC 82            [24] 4140 	mov	r4, dpl
      0013B8 AD 83            [24] 4141 	mov	r5, dph
      0013BA AE F0            [24] 4142 	mov	r6, b
      0013BC FF               [12] 4143 	mov	r7, a
      0013BD 15 81            [12] 4144 	dec	sp
      0013BF 8C 82            [24] 4145 	mov	dpl, r4
      0013C1 8D 83            [24] 4146 	mov	dph, r5
      0013C3 8E F0            [24] 4147 	mov	b, r6
      0013C5 EF               [12] 4148 	mov	a, r7
                           00130F  4149 	C$fuzzy.h$1380$1_0$73 ==.
                                   4150 ;	../../fuzzy.h:1380: }
      0013C6 85 08 81         [24] 4151 	mov	sp,_bp
      0013C9 D0 08            [24] 4152 	pop	_bp
                           001314  4153 	C$fuzzy.h$1380$1_0$73 ==.
                           001314  4154 	XG$fuzzy_trapezoid$0$0 ==.
      0013CB 22               [24] 4155 	ret
                                   4156 ;------------------------------------------------------------
                                   4157 ;Allocation info for local variables in function 'fuzzy_function_array'
                                   4158 ;------------------------------------------------------------
                                   4159 ;value         Allocated to stack - _bp -6 +4 
                                   4160 ;hedge         Allocated to stack - _bp -7 +1 
                                   4161 ;parameter_count Allocated to stack - _bp -9 +2 
                                   4162 ;parameters    Allocated to stack - _bp -12 +3 
                                   4163 ;shape         Allocated to registers r7 
                                   4164 ;sloc0         Allocated to stack - _bp +2 +1 
                                   4165 ;sloc1         Allocated to stack - _bp +1 +4 
                                   4166 ;sloc2         Allocated to stack - _bp +5 +4 
                                   4167 ;sloc3         Allocated to stack - _bp +9 +4 
                                   4168 ;------------------------------------------------------------
                           001315  4169 	G$fuzzy_function_array$0$0 ==.
                           001315  4170 	C$fuzzy.h$1837$1_0$79 ==.
                                   4171 ;	../../fuzzy.h:1837: float fuzzy_function_array(
                                   4172 ;	-----------------------------------------
                                   4173 ;	 function fuzzy_function_array
                                   4174 ;	-----------------------------------------
      0013CC                       4175 _fuzzy_function_array:
      0013CC C0 08            [24] 4176 	push	_bp
      0013CE E5 81            [12] 4177 	mov	a,sp
      0013D0 F5 08            [12] 4178 	mov	_bp,a
      0013D2 24 0C            [12] 4179 	add	a,#0x0c
      0013D4 F5 81            [12] 4180 	mov	sp,a
      0013D6 AF 82            [24] 4181 	mov	r7, dpl
                           001321  4182 	C$fuzzy.h$1845$1_0$79 ==.
                                   4183 ;	../../fuzzy.h:1845: if (parameters == NULL) {
      0013D8 E5 08            [12] 4184 	mov	a,_bp
      0013DA 24 F4            [12] 4185 	add	a,#0xf4
      0013DC F8               [12] 4186 	mov	r0,a
      0013DD E6               [12] 4187 	mov	a,@r0
      0013DE 08               [12] 4188 	inc	r0
      0013DF 46               [12] 4189 	orl	a,@r0
      0013E0 70 09            [24] 4190 	jnz	00102$
                           00132B  4191 	C$fuzzy.h$1846$2_0$80 ==.
                                   4192 ;	../../fuzzy.h:1846: return LEVEL_LO;
      0013E2 90 00 00         [24] 4193 	mov	dptr,#0x0000
      0013E5 E4               [12] 4194 	clr	a
      0013E6 F5 F0            [12] 4195 	mov	b,a
      0013E8 02 17 67         [24] 4196 	ljmp	00123$
      0013EB                       4197 00102$:
                           001334  4198 	C$fuzzy.h$1849$1_0$79 ==.
                                   4199 ;	../../fuzzy.h:1849: switch (shape) {
      0013EB EF               [12] 4200 	mov	a,r7
      0013EC 24 F4            [12] 4201 	add	a,#0xff - 0x0b
      0013EE 50 03            [24] 4202 	jnc	00156$
      0013F0 02 17 61         [24] 4203 	ljmp	00121$
      0013F3                       4204 00156$:
      0013F3 EF               [12] 4205 	mov	a,r7
      0013F4 24 0A            [12] 4206 	add	a,#(00157$-3-.)
      0013F6 83               [24] 4207 	movc	a,@a+pc
      0013F7 F5 82            [12] 4208 	mov	dpl,a
      0013F9 EF               [12] 4209 	mov	a,r7
      0013FA 24 10            [12] 4210 	add	a,#(00158$-3-.)
      0013FC 83               [24] 4211 	movc	a,@a+pc
      0013FD F5 83            [12] 4212 	mov	dph,a
      0013FF E4               [12] 4213 	clr	a
      001400 73               [24] 4214 	jmp	@a+dptr
      001401                       4215 00157$:
      001401 19                    4216 	.db	00103$
      001402 15                    4217 	.db	00106$
      001403 15                    4218 	.db	00109$
      001404 59                    4219 	.db	00120$
      001405 59                    4220 	.db	00120$
      001406 59                    4221 	.db	00120$
      001407 59                    4222 	.db	00120$
      001408 59                    4223 	.db	00120$
      001409 59                    4224 	.db	00120$
      00140A 59                    4225 	.db	00120$
      00140B 59                    4226 	.db	00120$
      00140C 59                    4227 	.db	00120$
      00140D                       4228 00158$:
      00140D 14                    4229 	.db	00103$>>8
      00140E 15                    4230 	.db	00106$>>8
      00140F 16                    4231 	.db	00109$>>8
      001410 17                    4232 	.db	00120$>>8
      001411 17                    4233 	.db	00120$>>8
      001412 17                    4234 	.db	00120$>>8
      001413 17                    4235 	.db	00120$>>8
      001414 17                    4236 	.db	00120$>>8
      001415 17                    4237 	.db	00120$>>8
      001416 17                    4238 	.db	00120$>>8
      001417 17                    4239 	.db	00120$>>8
      001418 17                    4240 	.db	00120$>>8
                           001362  4241 	C$fuzzy.h$1850$2_0$81 ==.
                                   4242 ;	../../fuzzy.h:1850: case FUZZY_SHAPE_RAMP:
      001419                       4243 00103$:
                           001362  4244 	C$fuzzy.h$1851$2_0$81 ==.
                                   4245 ;	../../fuzzy.h:1851: if (parameter_count != 3u) {
      001419 E5 08            [12] 4246 	mov	a,_bp
      00141B 24 F7            [12] 4247 	add	a,#0xf7
      00141D F8               [12] 4248 	mov	r0,a
      00141E B6 03 06         [24] 4249 	cjne	@r0,#0x03,00159$
      001421 08               [12] 4250 	inc	r0
      001422 B6 00 02         [24] 4251 	cjne	@r0,#0x00,00159$
      001425 80 09            [24] 4252 	sjmp	00105$
      001427                       4253 00159$:
                           001370  4254 	C$fuzzy.h$1852$3_0$82 ==.
                                   4255 ;	../../fuzzy.h:1852: return LEVEL_LO;
      001427 90 00 00         [24] 4256 	mov	dptr,#0x0000
      00142A E4               [12] 4257 	clr	a
      00142B F5 F0            [12] 4258 	mov	b,a
      00142D 02 17 67         [24] 4259 	ljmp	00123$
      001430                       4260 00105$:
                           001379  4261 	C$fuzzy.h$1859$2_0$81 ==.
                                   4262 ;	../../fuzzy.h:1859: parameters[2] != 0.0f,
      001430 E5 08            [12] 4263 	mov	a,_bp
      001432 24 F4            [12] 4264 	add	a,#0xf4
      001434 F8               [12] 4265 	mov	r0,a
      001435 74 08            [12] 4266 	mov	a,#0x08
      001437 26               [12] 4267 	add	a, @r0
      001438 FD               [12] 4268 	mov	r5,a
      001439 E4               [12] 4269 	clr	a
      00143A 08               [12] 4270 	inc	r0
      00143B 36               [12] 4271 	addc	a, @r0
      00143C FE               [12] 4272 	mov	r6,a
      00143D 08               [12] 4273 	inc	r0
      00143E 86 07            [24] 4274 	mov	ar7,@r0
      001440 8D 82            [24] 4275 	mov	dpl,r5
      001442 8E 83            [24] 4276 	mov	dph,r6
      001444 8F F0            [24] 4277 	mov	b,r7
      001446 12 29 94         [24] 4278 	lcall	__gptrget
      001449 FD               [12] 4279 	mov	r5,a
      00144A A3               [24] 4280 	inc	dptr
      00144B 12 29 94         [24] 4281 	lcall	__gptrget
      00144E FE               [12] 4282 	mov	r6,a
      00144F A3               [24] 4283 	inc	dptr
      001450 12 29 94         [24] 4284 	lcall	__gptrget
      001453 FF               [12] 4285 	mov	r7,a
      001454 A3               [24] 4286 	inc	dptr
      001455 12 29 94         [24] 4287 	lcall	__gptrget
      001458 FC               [12] 4288 	mov	r4,a
      001459 8D F0            [24] 4289 	mov	b,r5
      00145B EE               [12] 4290 	mov	a,r6
      00145C 42 F0            [12] 4291 	orl	b,a
      00145E EF               [12] 4292 	mov	a,r7
      00145F 42 F0            [12] 4293 	orl	b,a
      001461 EC               [12] 4294 	mov	a,r4
      001462 54 7F            [12] 4295 	anl	a,#0x7F
      001464 45 F0            [12] 4296 	orl	a,b
      001466 B4 01 00         [24] 4297 	cjne	a,#0x01,00160$
      001469                       4298 00160$:
      001469 B3               [12] 4299 	cpl	c
      00146A 92 00            [24] 4300 	mov	b0,c
      00146C E4               [12] 4301 	clr	a
      00146D 33               [12] 4302 	rlc	a
      00146E FB               [12] 4303 	mov	r3,a
                           0013B8  4304 	C$fuzzy.h$1857$2_0$81 ==.
                                   4305 ;	../../fuzzy.h:1857: parameters[1],
      00146F E5 08            [12] 4306 	mov	a,_bp
      001471 24 F4            [12] 4307 	add	a,#0xf4
      001473 F8               [12] 4308 	mov	r0,a
      001474 74 04            [12] 4309 	mov	a,#0x04
      001476 26               [12] 4310 	add	a, @r0
      001477 FC               [12] 4311 	mov	r4,a
      001478 E4               [12] 4312 	clr	a
      001479 08               [12] 4313 	inc	r0
      00147A 36               [12] 4314 	addc	a, @r0
      00147B FD               [12] 4315 	mov	r5,a
      00147C 08               [12] 4316 	inc	r0
      00147D 86 06            [24] 4317 	mov	ar6,@r0
      00147F 8C 82            [24] 4318 	mov	dpl,r4
      001481 8D 83            [24] 4319 	mov	dph,r5
      001483 8E F0            [24] 4320 	mov	b,r6
      001485 A8 08            [24] 4321 	mov	r0,_bp
      001487 08               [12] 4322 	inc	r0
      001488 12 29 94         [24] 4323 	lcall	__gptrget
      00148B F6               [12] 4324 	mov	@r0,a
      00148C A3               [24] 4325 	inc	dptr
      00148D 12 29 94         [24] 4326 	lcall	__gptrget
      001490 08               [12] 4327 	inc	r0
      001491 F6               [12] 4328 	mov	@r0,a
      001492 A3               [24] 4329 	inc	dptr
      001493 12 29 94         [24] 4330 	lcall	__gptrget
      001496 08               [12] 4331 	inc	r0
      001497 F6               [12] 4332 	mov	@r0,a
      001498 A3               [24] 4333 	inc	dptr
      001499 12 29 94         [24] 4334 	lcall	__gptrget
      00149C 08               [12] 4335 	inc	r0
      00149D F6               [12] 4336 	mov	@r0,a
                           0013E7  4337 	C$fuzzy.h$1856$2_0$81 ==.
                                   4338 ;	../../fuzzy.h:1856: parameters[0],
      00149E E5 08            [12] 4339 	mov	a,_bp
      0014A0 24 F4            [12] 4340 	add	a,#0xf4
      0014A2 F8               [12] 4341 	mov	r0,a
      0014A3 86 02            [24] 4342 	mov	ar2,@r0
      0014A5 08               [12] 4343 	inc	r0
      0014A6 86 06            [24] 4344 	mov	ar6,@r0
      0014A8 08               [12] 4345 	inc	r0
      0014A9 86 07            [24] 4346 	mov	ar7,@r0
      0014AB 8A 82            [24] 4347 	mov	dpl,r2
      0014AD 8E 83            [24] 4348 	mov	dph,r6
      0014AF 8F F0            [24] 4349 	mov	b,r7
      0014B1 12 29 94         [24] 4350 	lcall	__gptrget
      0014B4 FA               [12] 4351 	mov	r2,a
      0014B5 A3               [24] 4352 	inc	dptr
      0014B6 12 29 94         [24] 4353 	lcall	__gptrget
      0014B9 FE               [12] 4354 	mov	r6,a
      0014BA A3               [24] 4355 	inc	dptr
      0014BB 12 29 94         [24] 4356 	lcall	__gptrget
      0014BE FF               [12] 4357 	mov	r7,a
      0014BF A3               [24] 4358 	inc	dptr
      0014C0 12 29 94         [24] 4359 	lcall	__gptrget
      0014C3 FD               [12] 4360 	mov	r5,a
      0014C4 E5 08            [12] 4361 	mov	a,_bp
      0014C6 24 F9            [12] 4362 	add	a,#0xf9
      0014C8 F8               [12] 4363 	mov	r0,a
      0014C9 E6               [12] 4364 	mov	a,@r0
      0014CA C0 E0            [24] 4365 	push	acc
      0014CC C0 03            [24] 4366 	push	ar3
      0014CE E5 08            [12] 4367 	mov	a,_bp
      0014D0 24 FA            [12] 4368 	add	a,#0xfa
      0014D2 F8               [12] 4369 	mov	r0,a
      0014D3 E6               [12] 4370 	mov	a,@r0
      0014D4 C0 E0            [24] 4371 	push	acc
      0014D6 08               [12] 4372 	inc	r0
      0014D7 E6               [12] 4373 	mov	a,@r0
      0014D8 C0 E0            [24] 4374 	push	acc
      0014DA 08               [12] 4375 	inc	r0
      0014DB E6               [12] 4376 	mov	a,@r0
      0014DC C0 E0            [24] 4377 	push	acc
      0014DE 08               [12] 4378 	inc	r0
      0014DF E6               [12] 4379 	mov	a,@r0
      0014E0 C0 E0            [24] 4380 	push	acc
      0014E2 A8 08            [24] 4381 	mov	r0,_bp
      0014E4 08               [12] 4382 	inc	r0
      0014E5 E6               [12] 4383 	mov	a,@r0
      0014E6 C0 E0            [24] 4384 	push	acc
      0014E8 08               [12] 4385 	inc	r0
      0014E9 E6               [12] 4386 	mov	a,@r0
      0014EA C0 E0            [24] 4387 	push	acc
      0014EC 08               [12] 4388 	inc	r0
      0014ED E6               [12] 4389 	mov	a,@r0
      0014EE C0 E0            [24] 4390 	push	acc
      0014F0 08               [12] 4391 	inc	r0
      0014F1 E6               [12] 4392 	mov	a,@r0
      0014F2 C0 E0            [24] 4393 	push	acc
      0014F4 8A 82            [24] 4394 	mov	dpl, r2
      0014F6 8E 83            [24] 4395 	mov	dph, r6
      0014F8 8F F0            [24] 4396 	mov	b, r7
      0014FA ED               [12] 4397 	mov	a, r5
      0014FB 12 0A EC         [24] 4398 	lcall	_fuzzy_ramp
      0014FE AC 82            [24] 4399 	mov	r4, dpl
      001500 AD 83            [24] 4400 	mov	r5, dph
      001502 AE F0            [24] 4401 	mov	r6, b
      001504 FF               [12] 4402 	mov	r7, a
      001505 E5 81            [12] 4403 	mov	a,sp
      001507 24 F6            [12] 4404 	add	a,#0xf6
      001509 F5 81            [12] 4405 	mov	sp,a
      00150B 8C 82            [24] 4406 	mov	dpl, r4
      00150D 8D 83            [24] 4407 	mov	dph, r5
      00150F 8E F0            [24] 4408 	mov	b, r6
      001511 EF               [12] 4409 	mov	a, r7
      001512 02 17 67         [24] 4410 	ljmp	00123$
                           00145E  4411 	C$fuzzy.h$1863$2_0$81 ==.
                                   4412 ;	../../fuzzy.h:1863: case FUZZY_SHAPE_TRIANGLE:
      001515                       4413 00106$:
                           00145E  4414 	C$fuzzy.h$1864$2_0$81 ==.
                                   4415 ;	../../fuzzy.h:1864: if (parameter_count != 3u) {
      001515 E5 08            [12] 4416 	mov	a,_bp
      001517 24 F7            [12] 4417 	add	a,#0xf7
      001519 F8               [12] 4418 	mov	r0,a
      00151A B6 03 06         [24] 4419 	cjne	@r0,#0x03,00161$
      00151D 08               [12] 4420 	inc	r0
      00151E B6 00 02         [24] 4421 	cjne	@r0,#0x00,00161$
      001521 80 09            [24] 4422 	sjmp	00108$
      001523                       4423 00161$:
                           00146C  4424 	C$fuzzy.h$1865$3_0$83 ==.
                                   4425 ;	../../fuzzy.h:1865: return LEVEL_LO;
      001523 90 00 00         [24] 4426 	mov	dptr,#0x0000
      001526 E4               [12] 4427 	clr	a
      001527 F5 F0            [12] 4428 	mov	b,a
      001529 02 17 67         [24] 4429 	ljmp	00123$
      00152C                       4430 00108$:
                           001475  4431 	C$fuzzy.h$1871$2_0$81 ==.
                                   4432 ;	../../fuzzy.h:1871: parameters[2],
      00152C E5 08            [12] 4433 	mov	a,_bp
      00152E 24 F4            [12] 4434 	add	a,#0xf4
      001530 F8               [12] 4435 	mov	r0,a
      001531 74 08            [12] 4436 	mov	a,#0x08
      001533 26               [12] 4437 	add	a, @r0
      001534 FD               [12] 4438 	mov	r5,a
      001535 E4               [12] 4439 	clr	a
      001536 08               [12] 4440 	inc	r0
      001537 36               [12] 4441 	addc	a, @r0
      001538 FE               [12] 4442 	mov	r6,a
      001539 08               [12] 4443 	inc	r0
      00153A 86 07            [24] 4444 	mov	ar7,@r0
      00153C 8D 82            [24] 4445 	mov	dpl,r5
      00153E 8E 83            [24] 4446 	mov	dph,r6
      001540 8F F0            [24] 4447 	mov	b,r7
      001542 A8 08            [24] 4448 	mov	r0,_bp
      001544 08               [12] 4449 	inc	r0
      001545 12 29 94         [24] 4450 	lcall	__gptrget
      001548 F6               [12] 4451 	mov	@r0,a
      001549 A3               [24] 4452 	inc	dptr
      00154A 12 29 94         [24] 4453 	lcall	__gptrget
      00154D 08               [12] 4454 	inc	r0
      00154E F6               [12] 4455 	mov	@r0,a
      00154F A3               [24] 4456 	inc	dptr
      001550 12 29 94         [24] 4457 	lcall	__gptrget
      001553 08               [12] 4458 	inc	r0
      001554 F6               [12] 4459 	mov	@r0,a
      001555 A3               [24] 4460 	inc	dptr
      001556 12 29 94         [24] 4461 	lcall	__gptrget
      001559 08               [12] 4462 	inc	r0
      00155A F6               [12] 4463 	mov	@r0,a
                           0014A4  4464 	C$fuzzy.h$1870$2_0$81 ==.
                                   4465 ;	../../fuzzy.h:1870: parameters[1],
      00155B E5 08            [12] 4466 	mov	a,_bp
      00155D 24 F4            [12] 4467 	add	a,#0xf4
      00155F F8               [12] 4468 	mov	r0,a
      001560 74 04            [12] 4469 	mov	a,#0x04
      001562 26               [12] 4470 	add	a, @r0
      001563 FA               [12] 4471 	mov	r2,a
      001564 E4               [12] 4472 	clr	a
      001565 08               [12] 4473 	inc	r0
      001566 36               [12] 4474 	addc	a, @r0
      001567 FB               [12] 4475 	mov	r3,a
      001568 08               [12] 4476 	inc	r0
      001569 86 07            [24] 4477 	mov	ar7,@r0
      00156B 8A 82            [24] 4478 	mov	dpl,r2
      00156D 8B 83            [24] 4479 	mov	dph,r3
      00156F 8F F0            [24] 4480 	mov	b,r7
      001571 E5 08            [12] 4481 	mov	a,_bp
      001573 24 05            [12] 4482 	add	a,#0x05
      001575 F8               [12] 4483 	mov	r0,a
      001576 12 29 94         [24] 4484 	lcall	__gptrget
      001579 F6               [12] 4485 	mov	@r0,a
      00157A A3               [24] 4486 	inc	dptr
      00157B 12 29 94         [24] 4487 	lcall	__gptrget
      00157E 08               [12] 4488 	inc	r0
      00157F F6               [12] 4489 	mov	@r0,a
      001580 A3               [24] 4490 	inc	dptr
      001581 12 29 94         [24] 4491 	lcall	__gptrget
      001584 08               [12] 4492 	inc	r0
      001585 F6               [12] 4493 	mov	@r0,a
      001586 A3               [24] 4494 	inc	dptr
      001587 12 29 94         [24] 4495 	lcall	__gptrget
      00158A 08               [12] 4496 	inc	r0
      00158B F6               [12] 4497 	mov	@r0,a
                           0014D5  4498 	C$fuzzy.h$1869$2_0$81 ==.
                                   4499 ;	../../fuzzy.h:1869: parameters[0],
      00158C E5 08            [12] 4500 	mov	a,_bp
      00158E 24 F4            [12] 4501 	add	a,#0xf4
      001590 F8               [12] 4502 	mov	r0,a
      001591 86 04            [24] 4503 	mov	ar4,@r0
      001593 08               [12] 4504 	inc	r0
      001594 86 05            [24] 4505 	mov	ar5,@r0
      001596 08               [12] 4506 	inc	r0
      001597 86 07            [24] 4507 	mov	ar7,@r0
      001599 8C 82            [24] 4508 	mov	dpl,r4
      00159B 8D 83            [24] 4509 	mov	dph,r5
      00159D 8F F0            [24] 4510 	mov	b,r7
      00159F 12 29 94         [24] 4511 	lcall	__gptrget
      0015A2 FC               [12] 4512 	mov	r4,a
      0015A3 A3               [24] 4513 	inc	dptr
      0015A4 12 29 94         [24] 4514 	lcall	__gptrget
      0015A7 FD               [12] 4515 	mov	r5,a
      0015A8 A3               [24] 4516 	inc	dptr
      0015A9 12 29 94         [24] 4517 	lcall	__gptrget
      0015AC FF               [12] 4518 	mov	r7,a
      0015AD A3               [24] 4519 	inc	dptr
      0015AE 12 29 94         [24] 4520 	lcall	__gptrget
      0015B1 FE               [12] 4521 	mov	r6,a
      0015B2 E5 08            [12] 4522 	mov	a,_bp
      0015B4 24 F9            [12] 4523 	add	a,#0xf9
      0015B6 F8               [12] 4524 	mov	r0,a
      0015B7 E6               [12] 4525 	mov	a,@r0
      0015B8 C0 E0            [24] 4526 	push	acc
      0015BA E5 08            [12] 4527 	mov	a,_bp
      0015BC 24 FA            [12] 4528 	add	a,#0xfa
      0015BE F8               [12] 4529 	mov	r0,a
      0015BF E6               [12] 4530 	mov	a,@r0
      0015C0 C0 E0            [24] 4531 	push	acc
      0015C2 08               [12] 4532 	inc	r0
      0015C3 E6               [12] 4533 	mov	a,@r0
      0015C4 C0 E0            [24] 4534 	push	acc
      0015C6 08               [12] 4535 	inc	r0
      0015C7 E6               [12] 4536 	mov	a,@r0
      0015C8 C0 E0            [24] 4537 	push	acc
      0015CA 08               [12] 4538 	inc	r0
      0015CB E6               [12] 4539 	mov	a,@r0
      0015CC C0 E0            [24] 4540 	push	acc
      0015CE A8 08            [24] 4541 	mov	r0,_bp
      0015D0 08               [12] 4542 	inc	r0
      0015D1 E6               [12] 4543 	mov	a,@r0
      0015D2 C0 E0            [24] 4544 	push	acc
      0015D4 08               [12] 4545 	inc	r0
      0015D5 E6               [12] 4546 	mov	a,@r0
      0015D6 C0 E0            [24] 4547 	push	acc
      0015D8 08               [12] 4548 	inc	r0
      0015D9 E6               [12] 4549 	mov	a,@r0
      0015DA C0 E0            [24] 4550 	push	acc
      0015DC 08               [12] 4551 	inc	r0
      0015DD E6               [12] 4552 	mov	a,@r0
      0015DE C0 E0            [24] 4553 	push	acc
      0015E0 E5 08            [12] 4554 	mov	a,_bp
      0015E2 24 05            [12] 4555 	add	a,#0x05
      0015E4 F8               [12] 4556 	mov	r0,a
      0015E5 E6               [12] 4557 	mov	a,@r0
      0015E6 C0 E0            [24] 4558 	push	acc
      0015E8 08               [12] 4559 	inc	r0
      0015E9 E6               [12] 4560 	mov	a,@r0
      0015EA C0 E0            [24] 4561 	push	acc
      0015EC 08               [12] 4562 	inc	r0
      0015ED E6               [12] 4563 	mov	a,@r0
      0015EE C0 E0            [24] 4564 	push	acc
      0015F0 08               [12] 4565 	inc	r0
      0015F1 E6               [12] 4566 	mov	a,@r0
      0015F2 C0 E0            [24] 4567 	push	acc
      0015F4 8C 82            [24] 4568 	mov	dpl, r4
      0015F6 8D 83            [24] 4569 	mov	dph, r5
      0015F8 8F F0            [24] 4570 	mov	b, r7
      0015FA EE               [12] 4571 	mov	a, r6
      0015FB 12 0D 29         [24] 4572 	lcall	_fuzzy_triangle
      0015FE AC 82            [24] 4573 	mov	r4, dpl
      001600 AD 83            [24] 4574 	mov	r5, dph
      001602 AE F0            [24] 4575 	mov	r6, b
      001604 FF               [12] 4576 	mov	r7, a
      001605 E5 81            [12] 4577 	mov	a,sp
      001607 24 F3            [12] 4578 	add	a,#0xf3
      001609 F5 81            [12] 4579 	mov	sp,a
      00160B 8C 82            [24] 4580 	mov	dpl, r4
      00160D 8D 83            [24] 4581 	mov	dph, r5
      00160F 8E F0            [24] 4582 	mov	b, r6
      001611 EF               [12] 4583 	mov	a, r7
      001612 02 17 67         [24] 4584 	ljmp	00123$
                           00155E  4585 	C$fuzzy.h$1876$2_0$81 ==.
                                   4586 ;	../../fuzzy.h:1876: case FUZZY_SHAPE_TRAPEZOID:
      001615                       4587 00109$:
                           00155E  4588 	C$fuzzy.h$1877$2_0$81 ==.
                                   4589 ;	../../fuzzy.h:1877: if (parameter_count != 4u) {
      001615 E5 08            [12] 4590 	mov	a,_bp
      001617 24 F7            [12] 4591 	add	a,#0xf7
      001619 F8               [12] 4592 	mov	r0,a
      00161A B6 04 06         [24] 4593 	cjne	@r0,#0x04,00162$
      00161D 08               [12] 4594 	inc	r0
      00161E B6 00 02         [24] 4595 	cjne	@r0,#0x00,00162$
      001621 80 09            [24] 4596 	sjmp	00111$
      001623                       4597 00162$:
                           00156C  4598 	C$fuzzy.h$1878$3_0$84 ==.
                                   4599 ;	../../fuzzy.h:1878: return LEVEL_LO;
      001623 90 00 00         [24] 4600 	mov	dptr,#0x0000
      001626 E4               [12] 4601 	clr	a
      001627 F5 F0            [12] 4602 	mov	b,a
      001629 02 17 67         [24] 4603 	ljmp	00123$
      00162C                       4604 00111$:
                           001575  4605 	C$fuzzy.h$1885$2_0$81 ==.
                                   4606 ;	../../fuzzy.h:1885: parameters[3],
      00162C E5 08            [12] 4607 	mov	a,_bp
      00162E 24 F4            [12] 4608 	add	a,#0xf4
      001630 F8               [12] 4609 	mov	r0,a
      001631 74 0C            [12] 4610 	mov	a,#0x0c
      001633 26               [12] 4611 	add	a, @r0
      001634 FD               [12] 4612 	mov	r5,a
      001635 E4               [12] 4613 	clr	a
      001636 08               [12] 4614 	inc	r0
      001637 36               [12] 4615 	addc	a, @r0
      001638 FE               [12] 4616 	mov	r6,a
      001639 08               [12] 4617 	inc	r0
      00163A 86 07            [24] 4618 	mov	ar7,@r0
      00163C 8D 82            [24] 4619 	mov	dpl,r5
      00163E 8E 83            [24] 4620 	mov	dph,r6
      001640 8F F0            [24] 4621 	mov	b,r7
      001642 E5 08            [12] 4622 	mov	a,_bp
      001644 24 05            [12] 4623 	add	a,#0x05
      001646 F8               [12] 4624 	mov	r0,a
      001647 12 29 94         [24] 4625 	lcall	__gptrget
      00164A F6               [12] 4626 	mov	@r0,a
      00164B A3               [24] 4627 	inc	dptr
      00164C 12 29 94         [24] 4628 	lcall	__gptrget
      00164F 08               [12] 4629 	inc	r0
      001650 F6               [12] 4630 	mov	@r0,a
      001651 A3               [24] 4631 	inc	dptr
      001652 12 29 94         [24] 4632 	lcall	__gptrget
      001655 08               [12] 4633 	inc	r0
      001656 F6               [12] 4634 	mov	@r0,a
      001657 A3               [24] 4635 	inc	dptr
      001658 12 29 94         [24] 4636 	lcall	__gptrget
      00165B 08               [12] 4637 	inc	r0
      00165C F6               [12] 4638 	mov	@r0,a
                           0015A6  4639 	C$fuzzy.h$1884$2_0$81 ==.
                                   4640 ;	../../fuzzy.h:1884: parameters[2],
      00165D E5 08            [12] 4641 	mov	a,_bp
      00165F 24 F4            [12] 4642 	add	a,#0xf4
      001661 F8               [12] 4643 	mov	r0,a
      001662 74 08            [12] 4644 	mov	a,#0x08
      001664 26               [12] 4645 	add	a, @r0
      001665 FA               [12] 4646 	mov	r2,a
      001666 E4               [12] 4647 	clr	a
      001667 08               [12] 4648 	inc	r0
      001668 36               [12] 4649 	addc	a, @r0
      001669 FB               [12] 4650 	mov	r3,a
      00166A 08               [12] 4651 	inc	r0
      00166B 86 07            [24] 4652 	mov	ar7,@r0
      00166D 8A 82            [24] 4653 	mov	dpl,r2
      00166F 8B 83            [24] 4654 	mov	dph,r3
      001671 8F F0            [24] 4655 	mov	b,r7
      001673 A8 08            [24] 4656 	mov	r0,_bp
      001675 08               [12] 4657 	inc	r0
      001676 12 29 94         [24] 4658 	lcall	__gptrget
      001679 F6               [12] 4659 	mov	@r0,a
      00167A A3               [24] 4660 	inc	dptr
      00167B 12 29 94         [24] 4661 	lcall	__gptrget
      00167E 08               [12] 4662 	inc	r0
      00167F F6               [12] 4663 	mov	@r0,a
      001680 A3               [24] 4664 	inc	dptr
      001681 12 29 94         [24] 4665 	lcall	__gptrget
      001684 08               [12] 4666 	inc	r0
      001685 F6               [12] 4667 	mov	@r0,a
      001686 A3               [24] 4668 	inc	dptr
      001687 12 29 94         [24] 4669 	lcall	__gptrget
      00168A 08               [12] 4670 	inc	r0
      00168B F6               [12] 4671 	mov	@r0,a
                           0015D5  4672 	C$fuzzy.h$1883$2_0$81 ==.
                                   4673 ;	../../fuzzy.h:1883: parameters[1],
      00168C E5 08            [12] 4674 	mov	a,_bp
      00168E 24 F4            [12] 4675 	add	a,#0xf4
      001690 F8               [12] 4676 	mov	r0,a
      001691 74 04            [12] 4677 	mov	a,#0x04
      001693 26               [12] 4678 	add	a, @r0
      001694 FC               [12] 4679 	mov	r4,a
      001695 E4               [12] 4680 	clr	a
      001696 08               [12] 4681 	inc	r0
      001697 36               [12] 4682 	addc	a, @r0
      001698 FD               [12] 4683 	mov	r5,a
      001699 08               [12] 4684 	inc	r0
      00169A 86 07            [24] 4685 	mov	ar7,@r0
      00169C 8C 82            [24] 4686 	mov	dpl,r4
      00169E 8D 83            [24] 4687 	mov	dph,r5
      0016A0 8F F0            [24] 4688 	mov	b,r7
      0016A2 E5 08            [12] 4689 	mov	a,_bp
      0016A4 24 09            [12] 4690 	add	a,#0x09
      0016A6 F8               [12] 4691 	mov	r0,a
      0016A7 12 29 94         [24] 4692 	lcall	__gptrget
      0016AA F6               [12] 4693 	mov	@r0,a
      0016AB A3               [24] 4694 	inc	dptr
      0016AC 12 29 94         [24] 4695 	lcall	__gptrget
      0016AF 08               [12] 4696 	inc	r0
      0016B0 F6               [12] 4697 	mov	@r0,a
      0016B1 A3               [24] 4698 	inc	dptr
      0016B2 12 29 94         [24] 4699 	lcall	__gptrget
      0016B5 08               [12] 4700 	inc	r0
      0016B6 F6               [12] 4701 	mov	@r0,a
      0016B7 A3               [24] 4702 	inc	dptr
      0016B8 12 29 94         [24] 4703 	lcall	__gptrget
      0016BB 08               [12] 4704 	inc	r0
      0016BC F6               [12] 4705 	mov	@r0,a
                           001606  4706 	C$fuzzy.h$1882$2_0$81 ==.
                                   4707 ;	../../fuzzy.h:1882: parameters[0],
      0016BD E5 08            [12] 4708 	mov	a,_bp
      0016BF 24 F4            [12] 4709 	add	a,#0xf4
      0016C1 F8               [12] 4710 	mov	r0,a
      0016C2 86 02            [24] 4711 	mov	ar2,@r0
      0016C4 08               [12] 4712 	inc	r0
      0016C5 86 03            [24] 4713 	mov	ar3,@r0
      0016C7 08               [12] 4714 	inc	r0
      0016C8 86 07            [24] 4715 	mov	ar7,@r0
      0016CA 8A 82            [24] 4716 	mov	dpl,r2
      0016CC 8B 83            [24] 4717 	mov	dph,r3
      0016CE 8F F0            [24] 4718 	mov	b,r7
      0016D0 12 29 94         [24] 4719 	lcall	__gptrget
      0016D3 FA               [12] 4720 	mov	r2,a
      0016D4 A3               [24] 4721 	inc	dptr
      0016D5 12 29 94         [24] 4722 	lcall	__gptrget
      0016D8 FB               [12] 4723 	mov	r3,a
      0016D9 A3               [24] 4724 	inc	dptr
      0016DA 12 29 94         [24] 4725 	lcall	__gptrget
      0016DD FF               [12] 4726 	mov	r7,a
      0016DE A3               [24] 4727 	inc	dptr
      0016DF 12 29 94         [24] 4728 	lcall	__gptrget
      0016E2 FE               [12] 4729 	mov	r6,a
      0016E3 E5 08            [12] 4730 	mov	a,_bp
      0016E5 24 F9            [12] 4731 	add	a,#0xf9
      0016E7 F8               [12] 4732 	mov	r0,a
      0016E8 E6               [12] 4733 	mov	a,@r0
      0016E9 C0 E0            [24] 4734 	push	acc
      0016EB E5 08            [12] 4735 	mov	a,_bp
      0016ED 24 FA            [12] 4736 	add	a,#0xfa
      0016EF F8               [12] 4737 	mov	r0,a
      0016F0 E6               [12] 4738 	mov	a,@r0
      0016F1 C0 E0            [24] 4739 	push	acc
      0016F3 08               [12] 4740 	inc	r0
      0016F4 E6               [12] 4741 	mov	a,@r0
      0016F5 C0 E0            [24] 4742 	push	acc
      0016F7 08               [12] 4743 	inc	r0
      0016F8 E6               [12] 4744 	mov	a,@r0
      0016F9 C0 E0            [24] 4745 	push	acc
      0016FB 08               [12] 4746 	inc	r0
      0016FC E6               [12] 4747 	mov	a,@r0
      0016FD C0 E0            [24] 4748 	push	acc
      0016FF E5 08            [12] 4749 	mov	a,_bp
      001701 24 05            [12] 4750 	add	a,#0x05
      001703 F8               [12] 4751 	mov	r0,a
      001704 E6               [12] 4752 	mov	a,@r0
      001705 C0 E0            [24] 4753 	push	acc
      001707 08               [12] 4754 	inc	r0
      001708 E6               [12] 4755 	mov	a,@r0
      001709 C0 E0            [24] 4756 	push	acc
      00170B 08               [12] 4757 	inc	r0
      00170C E6               [12] 4758 	mov	a,@r0
      00170D C0 E0            [24] 4759 	push	acc
      00170F 08               [12] 4760 	inc	r0
      001710 E6               [12] 4761 	mov	a,@r0
      001711 C0 E0            [24] 4762 	push	acc
      001713 A8 08            [24] 4763 	mov	r0,_bp
      001715 08               [12] 4764 	inc	r0
      001716 E6               [12] 4765 	mov	a,@r0
      001717 C0 E0            [24] 4766 	push	acc
      001719 08               [12] 4767 	inc	r0
      00171A E6               [12] 4768 	mov	a,@r0
      00171B C0 E0            [24] 4769 	push	acc
      00171D 08               [12] 4770 	inc	r0
      00171E E6               [12] 4771 	mov	a,@r0
      00171F C0 E0            [24] 4772 	push	acc
      001721 08               [12] 4773 	inc	r0
      001722 E6               [12] 4774 	mov	a,@r0
      001723 C0 E0            [24] 4775 	push	acc
      001725 E5 08            [12] 4776 	mov	a,_bp
      001727 24 09            [12] 4777 	add	a,#0x09
      001729 F8               [12] 4778 	mov	r0,a
      00172A E6               [12] 4779 	mov	a,@r0
      00172B C0 E0            [24] 4780 	push	acc
      00172D 08               [12] 4781 	inc	r0
      00172E E6               [12] 4782 	mov	a,@r0
      00172F C0 E0            [24] 4783 	push	acc
      001731 08               [12] 4784 	inc	r0
      001732 E6               [12] 4785 	mov	a,@r0
      001733 C0 E0            [24] 4786 	push	acc
      001735 08               [12] 4787 	inc	r0
      001736 E6               [12] 4788 	mov	a,@r0
      001737 C0 E0            [24] 4789 	push	acc
      001739 8A 82            [24] 4790 	mov	dpl, r2
      00173B 8B 83            [24] 4791 	mov	dph, r3
      00173D 8F F0            [24] 4792 	mov	b, r7
      00173F EE               [12] 4793 	mov	a, r6
      001740 12 10 35         [24] 4794 	lcall	_fuzzy_trapezoid
      001743 AC 82            [24] 4795 	mov	r4, dpl
      001745 AD 83            [24] 4796 	mov	r5, dph
      001747 AE F0            [24] 4797 	mov	r6, b
      001749 FF               [12] 4798 	mov	r7, a
      00174A E5 81            [12] 4799 	mov	a,sp
      00174C 24 EF            [12] 4800 	add	a,#0xef
      00174E F5 81            [12] 4801 	mov	sp,a
      001750 8C 82            [24] 4802 	mov	dpl, r4
      001752 8D 83            [24] 4803 	mov	dph, r5
      001754 8E F0            [24] 4804 	mov	b, r6
      001756 EF               [12] 4805 	mov	a, r7
                           0016A0  4806 	C$fuzzy.h$2019$2_0$81 ==.
                                   4807 ;	../../fuzzy.h:2019: case FUZZY_SHAPE_PSIGMOID:
      001757 80 0E            [24] 4808 	sjmp	00123$
      001759                       4809 00120$:
                           0016A2  4810 	C$fuzzy.h$2020$2_0$81 ==.
                                   4811 ;	../../fuzzy.h:2020: return LEVEL_LO;
      001759 90 00 00         [24] 4812 	mov	dptr,#0x0000
      00175C E4               [12] 4813 	clr	a
      00175D F5 F0            [12] 4814 	mov	b,a
                           0016A8  4815 	C$fuzzy.h$2024$2_0$81 ==.
                                   4816 ;	../../fuzzy.h:2024: default:
      00175F 80 06            [24] 4817 	sjmp	00123$
      001761                       4818 00121$:
                           0016AA  4819 	C$fuzzy.h$2025$2_0$81 ==.
                                   4820 ;	../../fuzzy.h:2025: return LEVEL_LO;
      001761 90 00 00         [24] 4821 	mov	dptr,#0x0000
      001764 E4               [12] 4822 	clr	a
      001765 F5 F0            [12] 4823 	mov	b,a
                           0016B0  4824 	C$fuzzy.h$2026$1_0$79 ==.
                                   4825 ;	../../fuzzy.h:2026: }
      001767                       4826 00123$:
                           0016B0  4827 	C$fuzzy.h$2027$1_0$79 ==.
                                   4828 ;	../../fuzzy.h:2027: }
      001767 85 08 81         [24] 4829 	mov	sp,_bp
      00176A D0 08            [24] 4830 	pop	_bp
                           0016B5  4831 	C$fuzzy.h$2027$1_0$79 ==.
                           0016B5  4832 	XG$fuzzy_function_array$0$0 ==.
      00176C 22               [24] 4833 	ret
                                   4834 ;------------------------------------------------------------
                                   4835 ;Allocation info for local variables in function 'fuzzy_rules_add'
                                   4836 ;------------------------------------------------------------
                                   4837 ;name          Allocated to stack - _bp -5 +3 
                                   4838 ;value         Allocated to stack - _bp -9 +4 
                                   4839 ;output_function Allocated to stack - _bp -11 +2 
                                   4840 ;rules         Allocated to registers r2 r3 r4 
                                   4841 ;index         Allocated to registers 
                                   4842 ;sloc0         Allocated to stack - _bp +1 +2 
                                   4843 ;sloc1         Allocated to stack - _bp +3 +3 
                                   4844 ;sloc2         Allocated to stack - _bp +6 +3 
                                   4845 ;sloc3         Allocated to stack - _bp +9 +3 
                                   4846 ;------------------------------------------------------------
                           0016B6  4847 	G$fuzzy_rules_add$0$0 ==.
                           0016B6  4848 	C$fuzzy.h$2029$1_0$86 ==.
                                   4849 ;	../../fuzzy.h:2029: bool fuzzy_rules_add(
                                   4850 ;	-----------------------------------------
                                   4851 ;	 function fuzzy_rules_add
                                   4852 ;	-----------------------------------------
      00176D                       4853 _fuzzy_rules_add:
      00176D C0 08            [24] 4854 	push	_bp
      00176F E5 81            [12] 4855 	mov	a,sp
      001771 F5 08            [12] 4856 	mov	_bp,a
      001773 24 0B            [12] 4857 	add	a,#0x0b
      001775 F5 81            [12] 4858 	mov	sp,a
      001777 AA 82            [24] 4859 	mov	r2, dpl
      001779 AB 83            [24] 4860 	mov	r3, dph
      00177B AC F0            [24] 4861 	mov	r4, b
                           0016C6  4862 	C$fuzzy.h$2039$1_0$86 ==.
                                   4863 ;	../../fuzzy.h:2039: rules == NULL ||
      00177D EA               [12] 4864 	mov	a,r2
      00177E 4B               [12] 4865 	orl	a,r3
      00177F 60 0A            [24] 4866 	jz	00101$
                           0016CA  4867 	C$fuzzy.h$2040$1_0$86 ==.
                                   4868 ;	../../fuzzy.h:2040: output_function == NULL
      001781 E5 08            [12] 4869 	mov	a,_bp
      001783 24 F5            [12] 4870 	add	a,#0xf5
      001785 F8               [12] 4871 	mov	r0,a
      001786 E6               [12] 4872 	mov	a,@r0
      001787 08               [12] 4873 	inc	r0
      001788 46               [12] 4874 	orl	a,@r0
      001789 70 06            [24] 4875 	jnz	00102$
      00178B                       4876 00101$:
                           0016D4  4877 	C$fuzzy.h$2042$2_0$87 ==.
                                   4878 ;	../../fuzzy.h:2042: return false;
      00178B 75 82 00         [24] 4879 	mov	dpl, #0x00
      00178E 02 18 CB         [24] 4880 	ljmp	00106$
      001791                       4881 00102$:
                           0016DA  4882 	C$fuzzy.h$2045$1_0$86 ==.
                                   4883 ;	../../fuzzy.h:2045: if (rules->count >= FUZZY_MAX_RULES) {
      001791 E5 08            [12] 4884 	mov	a,_bp
      001793 24 09            [12] 4885 	add	a,#0x09
      001795 F8               [12] 4886 	mov	r0,a
      001796 74 90            [12] 4887 	mov	a,#0x90
      001798 2A               [12] 4888 	add	a, r2
      001799 F6               [12] 4889 	mov	@r0,a
      00179A E4               [12] 4890 	clr	a
      00179B 3B               [12] 4891 	addc	a, r3
      00179C 08               [12] 4892 	inc	r0
      00179D F6               [12] 4893 	mov	@r0,a
      00179E 08               [12] 4894 	inc	r0
      00179F A6 04            [24] 4895 	mov	@r0,ar4
      0017A1 E5 08            [12] 4896 	mov	a,_bp
      0017A3 24 09            [12] 4897 	add	a,#0x09
      0017A5 F8               [12] 4898 	mov	r0,a
      0017A6 86 82            [24] 4899 	mov	dpl,@r0
      0017A8 08               [12] 4900 	inc	r0
      0017A9 86 83            [24] 4901 	mov	dph,@r0
      0017AB 08               [12] 4902 	inc	r0
      0017AC 86 F0            [24] 4903 	mov	b,@r0
      0017AE 12 29 94         [24] 4904 	lcall	__gptrget
      0017B1 FF               [12] 4905 	mov	r7,a
      0017B2 A3               [24] 4906 	inc	dptr
      0017B3 12 29 94         [24] 4907 	lcall	__gptrget
      0017B6 FE               [12] 4908 	mov	r6,a
      0017B7 C3               [12] 4909 	clr	c
      0017B8 EF               [12] 4910 	mov	a,r7
      0017B9 94 10            [12] 4911 	subb	a,#0x10
      0017BB EE               [12] 4912 	mov	a,r6
      0017BC 94 00            [12] 4913 	subb	a,#0x00
      0017BE 40 06            [24] 4914 	jc	00105$
                           001709  4915 	C$fuzzy.h$2046$2_0$88 ==.
                                   4916 ;	../../fuzzy.h:2046: return false;
      0017C0 75 82 00         [24] 4917 	mov	dpl, #0x00
      0017C3 02 18 CB         [24] 4918 	ljmp	00106$
      0017C6                       4919 00105$:
                           00170F  4920 	C$fuzzy.h$2052$1_0$86 ==.
                                   4921 ;	../../fuzzy.h:2052: rules->rules[index].name =
      0017C6 C0 04            [24] 4922 	push	ar4
      0017C8 C0 03            [24] 4923 	push	ar3
      0017CA C0 02            [24] 4924 	push	ar2
      0017CC C0 07            [24] 4925 	push	ar7
      0017CE C0 06            [24] 4926 	push	ar6
      0017D0 90 00 09         [24] 4927 	mov	dptr,#0x0009
      0017D3 12 27 98         [24] 4928 	lcall	__mulint
      0017D6 A8 08            [24] 4929 	mov	r0,_bp
      0017D8 08               [12] 4930 	inc	r0
      0017D9 A6 82            [24] 4931 	mov	@r0, dpl
      0017DB 08               [12] 4932 	inc	r0
      0017DC A6 83            [24] 4933 	mov	@r0, dph
      0017DE 15 81            [12] 4934 	dec	sp
      0017E0 15 81            [12] 4935 	dec	sp
      0017E2 D0 02            [24] 4936 	pop	ar2
      0017E4 D0 03            [24] 4937 	pop	ar3
      0017E6 D0 04            [24] 4938 	pop	ar4
      0017E8 A8 08            [24] 4939 	mov	r0,_bp
      0017EA 08               [12] 4940 	inc	r0
      0017EB E6               [12] 4941 	mov	a,@r0
      0017EC 2A               [12] 4942 	add	a, r2
      0017ED FD               [12] 4943 	mov	r5,a
      0017EE 08               [12] 4944 	inc	r0
      0017EF E6               [12] 4945 	mov	a,@r0
      0017F0 3B               [12] 4946 	addc	a, r3
      0017F1 FE               [12] 4947 	mov	r6,a
      0017F2 8C 07            [24] 4948 	mov	ar7,r4
      0017F4 8D 82            [24] 4949 	mov	dpl,r5
      0017F6 8E 83            [24] 4950 	mov	dph,r6
      0017F8 8F F0            [24] 4951 	mov	b,r7
      0017FA E5 08            [12] 4952 	mov	a,_bp
      0017FC 24 FB            [12] 4953 	add	a,#0xfb
      0017FE F8               [12] 4954 	mov	r0,a
      0017FF E6               [12] 4955 	mov	a,@r0
      001800 12 27 4D         [24] 4956 	lcall	__gptrput
      001803 A3               [24] 4957 	inc	dptr
      001804 08               [12] 4958 	inc	r0
      001805 E6               [12] 4959 	mov	a,@r0
      001806 12 27 4D         [24] 4960 	lcall	__gptrput
      001809 A3               [24] 4961 	inc	dptr
      00180A 08               [12] 4962 	inc	r0
      00180B E6               [12] 4963 	mov	a,@r0
      00180C 12 27 4D         [24] 4964 	lcall	__gptrput
                           001758  4965 	C$fuzzy.h$2055$1_0$86 ==.
                                   4966 ;	../../fuzzy.h:2055: rules->rules[index].value =
      00180F A8 08            [24] 4967 	mov	r0,_bp
      001811 08               [12] 4968 	inc	r0
      001812 E5 08            [12] 4969 	mov	a,_bp
      001814 24 03            [12] 4970 	add	a,#0x03
      001816 F9               [12] 4971 	mov	r1,a
      001817 E6               [12] 4972 	mov	a,@r0
      001818 2A               [12] 4973 	add	a, r2
      001819 F7               [12] 4974 	mov	@r1,a
      00181A 08               [12] 4975 	inc	r0
      00181B E6               [12] 4976 	mov	a,@r0
      00181C 3B               [12] 4977 	addc	a, r3
      00181D 09               [12] 4978 	inc	r1
      00181E F7               [12] 4979 	mov	@r1,a
      00181F 09               [12] 4980 	inc	r1
      001820 A7 04            [24] 4981 	mov	@r1,ar4
      001822 E5 08            [12] 4982 	mov	a,_bp
      001824 24 03            [12] 4983 	add	a,#0x03
      001826 F8               [12] 4984 	mov	r0,a
      001827 E5 08            [12] 4985 	mov	a,_bp
      001829 24 06            [12] 4986 	add	a,#0x06
      00182B F9               [12] 4987 	mov	r1,a
      00182C 74 03            [12] 4988 	mov	a,#0x03
      00182E 26               [12] 4989 	add	a, @r0
      00182F F7               [12] 4990 	mov	@r1,a
      001830 E4               [12] 4991 	clr	a
      001831 08               [12] 4992 	inc	r0
      001832 36               [12] 4993 	addc	a, @r0
      001833 09               [12] 4994 	inc	r1
      001834 F7               [12] 4995 	mov	@r1,a
      001835 08               [12] 4996 	inc	r0
      001836 E6               [12] 4997 	mov	a,@r0
      001837 09               [12] 4998 	inc	r1
      001838 F7               [12] 4999 	mov	@r1,a
                           001782  5000 	C$fuzzy.h$2056$1_0$86 ==.
                                   5001 ;	../../fuzzy.h:2056: fuzzy_clamp(value);
      001839 E5 08            [12] 5002 	mov	a,_bp
      00183B 24 F7            [12] 5003 	add	a,#0xf7
      00183D F8               [12] 5004 	mov	r0,a
      00183E 86 82            [24] 5005 	mov	dpl, @r0
      001840 08               [12] 5006 	inc	r0
      001841 86 83            [24] 5007 	mov	dph, @r0
      001843 08               [12] 5008 	inc	r0
      001844 86 F0            [24] 5009 	mov	b, @r0
      001846 08               [12] 5010 	inc	r0
      001847 E6               [12] 5011 	mov	a, @r0
      001848 12 00 EA         [24] 5012 	lcall	_fuzzy_clamp
      00184B AD 82            [24] 5013 	mov	r5, dpl
      00184D AE 83            [24] 5014 	mov	r6, dph
      00184F AC F0            [24] 5015 	mov	r4, b
      001851 FF               [12] 5016 	mov	r7, a
      001852 E5 08            [12] 5017 	mov	a,_bp
      001854 24 06            [12] 5018 	add	a,#0x06
      001856 F8               [12] 5019 	mov	r0,a
      001857 86 82            [24] 5020 	mov	dpl,@r0
      001859 08               [12] 5021 	inc	r0
      00185A 86 83            [24] 5022 	mov	dph,@r0
      00185C 08               [12] 5023 	inc	r0
      00185D 86 F0            [24] 5024 	mov	b,@r0
      00185F ED               [12] 5025 	mov	a,r5
      001860 12 27 4D         [24] 5026 	lcall	__gptrput
      001863 A3               [24] 5027 	inc	dptr
      001864 EE               [12] 5028 	mov	a,r6
      001865 12 27 4D         [24] 5029 	lcall	__gptrput
      001868 A3               [24] 5030 	inc	dptr
      001869 EC               [12] 5031 	mov	a,r4
      00186A 12 27 4D         [24] 5032 	lcall	__gptrput
      00186D A3               [24] 5033 	inc	dptr
      00186E EF               [12] 5034 	mov	a,r7
      00186F 12 27 4D         [24] 5035 	lcall	__gptrput
                           0017BB  5036 	C$fuzzy.h$2058$1_0$86 ==.
                                   5037 ;	../../fuzzy.h:2058: rules->rules[index].output_function =
      001872 E5 08            [12] 5038 	mov	a,_bp
      001874 24 03            [12] 5039 	add	a,#0x03
      001876 F8               [12] 5040 	mov	r0,a
      001877 74 07            [12] 5041 	mov	a,#0x07
      001879 26               [12] 5042 	add	a, @r0
      00187A FD               [12] 5043 	mov	r5,a
      00187B E4               [12] 5044 	clr	a
      00187C 08               [12] 5045 	inc	r0
      00187D 36               [12] 5046 	addc	a, @r0
      00187E FE               [12] 5047 	mov	r6,a
      00187F 08               [12] 5048 	inc	r0
      001880 86 07            [24] 5049 	mov	ar7,@r0
      001882 8D 82            [24] 5050 	mov	dpl,r5
      001884 8E 83            [24] 5051 	mov	dph,r6
      001886 8F F0            [24] 5052 	mov	b,r7
      001888 E5 08            [12] 5053 	mov	a,_bp
      00188A 24 F5            [12] 5054 	add	a,#0xf5
      00188C F8               [12] 5055 	mov	r0,a
      00188D E6               [12] 5056 	mov	a,@r0
      00188E 12 27 4D         [24] 5057 	lcall	__gptrput
      001891 A3               [24] 5058 	inc	dptr
      001892 08               [12] 5059 	inc	r0
      001893 E6               [12] 5060 	mov	a,@r0
      001894 12 27 4D         [24] 5061 	lcall	__gptrput
                           0017E0  5062 	C$fuzzy.h$2061$1_0$86 ==.
                                   5063 ;	../../fuzzy.h:2061: rules->count++;
      001897 E5 08            [12] 5064 	mov	a,_bp
      001899 24 09            [12] 5065 	add	a,#0x09
      00189B F8               [12] 5066 	mov	r0,a
      00189C 86 82            [24] 5067 	mov	dpl,@r0
      00189E 08               [12] 5068 	inc	r0
      00189F 86 83            [24] 5069 	mov	dph,@r0
      0018A1 08               [12] 5070 	inc	r0
      0018A2 86 F0            [24] 5071 	mov	b,@r0
      0018A4 12 29 94         [24] 5072 	lcall	__gptrget
      0018A7 FE               [12] 5073 	mov	r6,a
      0018A8 A3               [24] 5074 	inc	dptr
      0018A9 12 29 94         [24] 5075 	lcall	__gptrget
      0018AC FF               [12] 5076 	mov	r7,a
      0018AD 0E               [12] 5077 	inc	r6
      0018AE BE 00 01         [24] 5078 	cjne	r6,#0x00,00123$
      0018B1 0F               [12] 5079 	inc	r7
      0018B2                       5080 00123$:
      0018B2 E5 08            [12] 5081 	mov	a,_bp
      0018B4 24 09            [12] 5082 	add	a,#0x09
      0018B6 F8               [12] 5083 	mov	r0,a
      0018B7 86 82            [24] 5084 	mov	dpl,@r0
      0018B9 08               [12] 5085 	inc	r0
      0018BA 86 83            [24] 5086 	mov	dph,@r0
      0018BC 08               [12] 5087 	inc	r0
      0018BD 86 F0            [24] 5088 	mov	b,@r0
      0018BF EE               [12] 5089 	mov	a,r6
      0018C0 12 27 4D         [24] 5090 	lcall	__gptrput
      0018C3 A3               [24] 5091 	inc	dptr
      0018C4 EF               [12] 5092 	mov	a,r7
      0018C5 12 27 4D         [24] 5093 	lcall	__gptrput
                           001811  5094 	C$fuzzy.h$2063$1_0$86 ==.
                                   5095 ;	../../fuzzy.h:2063: return true;
      0018C8 75 82 01         [24] 5096 	mov	dpl, #0x01
      0018CB                       5097 00106$:
                           001814  5098 	C$fuzzy.h$2064$1_0$86 ==.
                                   5099 ;	../../fuzzy.h:2064: }
      0018CB 85 08 81         [24] 5100 	mov	sp,_bp
      0018CE D0 08            [24] 5101 	pop	_bp
                           001819  5102 	C$fuzzy.h$2064$1_0$86 ==.
                           001819  5103 	XG$fuzzy_rules_add$0$0 ==.
      0018D0 22               [24] 5104 	ret
                                   5105 ;------------------------------------------------------------
                                   5106 ;Allocation info for local variables in function 'fuzzy_implication'
                                   5107 ;------------------------------------------------------------
                                   5108 ;activation    Allocated to stack - _bp -6 +4 
                                   5109 ;membership    Allocated to stack - _bp -10 +4 
                                   5110 ;method        Allocated to registers r7 
                                   5111 ;sloc0         Allocated to stack - _bp +1 +4 
                                   5112 ;sloc1         Allocated to stack - _bp +5 +4 
                                   5113 ;------------------------------------------------------------
                           00181A  5114 	Fcontroller_8051$fuzzy_implication$0$0 ==.
                           00181A  5115 	C$fuzzy.h$2097$1_0$90 ==.
                                   5116 ;	../../fuzzy.h:2097: static float fuzzy_implication(
                                   5117 ;	-----------------------------------------
                                   5118 ;	 function fuzzy_implication
                                   5119 ;	-----------------------------------------
      0018D1                       5120 _fuzzy_implication:
      0018D1 C0 08            [24] 5121 	push	_bp
      0018D3 E5 81            [12] 5122 	mov	a,sp
      0018D5 F5 08            [12] 5123 	mov	_bp,a
      0018D7 24 08            [12] 5124 	add	a,#0x08
      0018D9 F5 81            [12] 5125 	mov	sp,a
      0018DB AF 82            [24] 5126 	mov	r7, dpl
                           001826  5127 	C$fuzzy.h$2103$1_0$90 ==.
                                   5128 ;	../../fuzzy.h:2103: activation = fuzzy_clamp(activation);
      0018DD E5 08            [12] 5129 	mov	a,_bp
      0018DF 24 FA            [12] 5130 	add	a,#0xfa
      0018E1 F8               [12] 5131 	mov	r0,a
      0018E2 86 82            [24] 5132 	mov	dpl, @r0
      0018E4 08               [12] 5133 	inc	r0
      0018E5 86 83            [24] 5134 	mov	dph, @r0
      0018E7 08               [12] 5135 	inc	r0
      0018E8 86 F0            [24] 5136 	mov	b, @r0
      0018EA 08               [12] 5137 	inc	r0
      0018EB E6               [12] 5138 	mov	a, @r0
      0018EC C0 07            [24] 5139 	push	ar7
      0018EE 12 00 EA         [24] 5140 	lcall	_fuzzy_clamp
      0018F1 AB 82            [24] 5141 	mov	r3, dpl
      0018F3 AC 83            [24] 5142 	mov	r4, dph
      0018F5 AD F0            [24] 5143 	mov	r5, b
      0018F7 FE               [12] 5144 	mov	r6, a
                           001841  5145 	C$fuzzy.h$2104$1_0$90 ==.
                                   5146 ;	../../fuzzy.h:2104: membership = fuzzy_clamp(membership);
      0018F8 E5 08            [12] 5147 	mov	a,_bp
      0018FA 24 F6            [12] 5148 	add	a,#0xf6
      0018FC F8               [12] 5149 	mov	r0,a
      0018FD 86 82            [24] 5150 	mov	dpl, @r0
      0018FF 08               [12] 5151 	inc	r0
      001900 86 83            [24] 5152 	mov	dph, @r0
      001902 08               [12] 5153 	inc	r0
      001903 86 F0            [24] 5154 	mov	b, @r0
      001905 08               [12] 5155 	inc	r0
      001906 E6               [12] 5156 	mov	a, @r0
      001907 C0 06            [24] 5157 	push	ar6
      001909 C0 05            [24] 5158 	push	ar5
      00190B C0 04            [24] 5159 	push	ar4
      00190D C0 03            [24] 5160 	push	ar3
      00190F 12 00 EA         [24] 5161 	lcall	_fuzzy_clamp
      001912 A8 08            [24] 5162 	mov	r0,_bp
      001914 08               [12] 5163 	inc	r0
      001915 A6 82            [24] 5164 	mov	@r0, dpl
      001917 08               [12] 5165 	inc	r0
      001918 A6 83            [24] 5166 	mov	@r0, dph
      00191A 08               [12] 5167 	inc	r0
      00191B A6 F0            [24] 5168 	mov	@r0, b
      00191D 08               [12] 5169 	inc	r0
      00191E F6               [12] 5170 	mov	@r0,a
      00191F D0 03            [24] 5171 	pop	ar3
      001921 D0 04            [24] 5172 	pop	ar4
      001923 D0 05            [24] 5173 	pop	ar5
      001925 D0 06            [24] 5174 	pop	ar6
      001927 D0 07            [24] 5175 	pop	ar7
                           001872  5176 	C$fuzzy.h$2106$1_0$90 ==.
                                   5177 ;	../../fuzzy.h:2106: switch (method) {
      001929 BF 00 02         [24] 5178 	cjne	r7,#0x00,00127$
      00192C 80 08            [24] 5179 	sjmp	00101$
      00192E                       5180 00127$:
      00192E BF 01 02         [24] 5181 	cjne	r7,#0x01,00128$
      001931 80 73            [24] 5182 	sjmp	00102$
      001933                       5183 00128$:
      001933 02 19 D8         [24] 5184 	ljmp	00103$
                           00187F  5185 	C$fuzzy.h$2107$2_0$91 ==.
                                   5186 ;	../../fuzzy.h:2107: case FUZZY_IMPLICATION_MIN:
      001936                       5187 00101$:
                           00187F  5188 	C$fuzzy.h$2109$1_0$90 ==.
                                   5189 ;	../../fuzzy.h:2109: ? activation
      001936 C0 06            [24] 5190 	push	ar6
      001938 C0 05            [24] 5191 	push	ar5
      00193A C0 04            [24] 5192 	push	ar4
      00193C C0 03            [24] 5193 	push	ar3
      00193E A8 08            [24] 5194 	mov	r0,_bp
      001940 08               [12] 5195 	inc	r0
      001941 E6               [12] 5196 	mov	a,@r0
      001942 C0 E0            [24] 5197 	push	acc
      001944 08               [12] 5198 	inc	r0
      001945 E6               [12] 5199 	mov	a,@r0
      001946 C0 E0            [24] 5200 	push	acc
      001948 08               [12] 5201 	inc	r0
      001949 E6               [12] 5202 	mov	a,@r0
      00194A C0 E0            [24] 5203 	push	acc
      00194C 08               [12] 5204 	inc	r0
      00194D E6               [12] 5205 	mov	a,@r0
      00194E C0 E0            [24] 5206 	push	acc
      001950 8B 82            [24] 5207 	mov	dpl, r3
      001952 8C 83            [24] 5208 	mov	dph, r4
      001954 8D F0            [24] 5209 	mov	b, r5
      001956 EE               [12] 5210 	mov	a, r6
      001957 12 27 68         [24] 5211 	lcall	___fslt
      00195A AF 82            [24] 5212 	mov	r7, dpl
      00195C E5 81            [12] 5213 	mov	a,sp
      00195E 24 FC            [12] 5214 	add	a,#0xfc
      001960 F5 81            [12] 5215 	mov	sp,a
      001962 D0 03            [24] 5216 	pop	ar3
      001964 D0 04            [24] 5217 	pop	ar4
      001966 D0 05            [24] 5218 	pop	ar5
      001968 D0 06            [24] 5219 	pop	ar6
      00196A EF               [12] 5220 	mov	a,r7
      00196B 60 12            [24] 5221 	jz	00107$
      00196D E5 08            [12] 5222 	mov	a,_bp
      00196F 24 05            [12] 5223 	add	a,#0x05
      001971 F8               [12] 5224 	mov	r0,a
      001972 A6 03            [24] 5225 	mov	@r0,ar3
      001974 08               [12] 5226 	inc	r0
      001975 A6 04            [24] 5227 	mov	@r0,ar4
      001977 08               [12] 5228 	inc	r0
      001978 A6 05            [24] 5229 	mov	@r0,ar5
      00197A 08               [12] 5230 	inc	r0
      00197B A6 06            [24] 5231 	mov	@r0,ar6
      00197D 80 16            [24] 5232 	sjmp	00108$
      00197F                       5233 00107$:
                           0018C8  5234 	C$fuzzy.h$2110$2_0$91 ==.
                                   5235 ;	../../fuzzy.h:2110: : membership;
      00197F A8 08            [24] 5236 	mov	r0,_bp
      001981 08               [12] 5237 	inc	r0
      001982 E5 08            [12] 5238 	mov	a,_bp
      001984 24 05            [12] 5239 	add	a,#0x05
      001986 F9               [12] 5240 	mov	r1,a
      001987 E6               [12] 5241 	mov	a,@r0
      001988 F7               [12] 5242 	mov	@r1,a
      001989 08               [12] 5243 	inc	r0
      00198A E6               [12] 5244 	mov	a,@r0
      00198B 09               [12] 5245 	inc	r1
      00198C F7               [12] 5246 	mov	@r1,a
      00198D 08               [12] 5247 	inc	r0
      00198E E6               [12] 5248 	mov	a,@r0
      00198F 09               [12] 5249 	inc	r1
      001990 F7               [12] 5250 	mov	@r1,a
      001991 08               [12] 5251 	inc	r0
      001992 E6               [12] 5252 	mov	a,@r0
      001993 09               [12] 5253 	inc	r1
      001994 F7               [12] 5254 	mov	@r1,a
      001995                       5255 00108$:
      001995 E5 08            [12] 5256 	mov	a,_bp
      001997 24 05            [12] 5257 	add	a,#0x05
      001999 F8               [12] 5258 	mov	r0,a
      00199A 86 82            [24] 5259 	mov	dpl, @r0
      00199C 08               [12] 5260 	inc	r0
      00199D 86 83            [24] 5261 	mov	dph, @r0
      00199F 08               [12] 5262 	inc	r0
      0019A0 86 F0            [24] 5263 	mov	b, @r0
      0019A2 08               [12] 5264 	inc	r0
      0019A3 E6               [12] 5265 	mov	a, @r0
                           0018ED  5266 	C$fuzzy.h$2112$2_0$91 ==.
                                   5267 ;	../../fuzzy.h:2112: case FUZZY_IMPLICATION_PRODUCT:
      0019A4 80 38            [24] 5268 	sjmp	00105$
      0019A6                       5269 00102$:
                           0018EF  5270 	C$fuzzy.h$2113$1_0$90 ==.
                                   5271 ;	../../fuzzy.h:2113: return activation * membership;
      0019A6 A8 08            [24] 5272 	mov	r0,_bp
      0019A8 08               [12] 5273 	inc	r0
      0019A9 E6               [12] 5274 	mov	a,@r0
      0019AA C0 E0            [24] 5275 	push	acc
      0019AC 08               [12] 5276 	inc	r0
      0019AD E6               [12] 5277 	mov	a,@r0
      0019AE C0 E0            [24] 5278 	push	acc
      0019B0 08               [12] 5279 	inc	r0
      0019B1 E6               [12] 5280 	mov	a,@r0
      0019B2 C0 E0            [24] 5281 	push	acc
      0019B4 08               [12] 5282 	inc	r0
      0019B5 E6               [12] 5283 	mov	a,@r0
      0019B6 C0 E0            [24] 5284 	push	acc
      0019B8 8B 82            [24] 5285 	mov	dpl, r3
      0019BA 8C 83            [24] 5286 	mov	dph, r4
      0019BC 8D F0            [24] 5287 	mov	b, r5
      0019BE EE               [12] 5288 	mov	a, r6
      0019BF 12 26 38         [24] 5289 	lcall	___fsmul
      0019C2 AC 82            [24] 5290 	mov	r4, dpl
      0019C4 AD 83            [24] 5291 	mov	r5, dph
      0019C6 AE F0            [24] 5292 	mov	r6, b
      0019C8 FF               [12] 5293 	mov	r7, a
      0019C9 E5 81            [12] 5294 	mov	a,sp
      0019CB 24 FC            [12] 5295 	add	a,#0xfc
      0019CD F5 81            [12] 5296 	mov	sp,a
      0019CF 8C 82            [24] 5297 	mov	dpl, r4
      0019D1 8D 83            [24] 5298 	mov	dph, r5
      0019D3 8E F0            [24] 5299 	mov	b, r6
      0019D5 EF               [12] 5300 	mov	a, r7
                           00191F  5301 	C$fuzzy.h$2115$2_0$91 ==.
                                   5302 ;	../../fuzzy.h:2115: default:
      0019D6 80 06            [24] 5303 	sjmp	00105$
      0019D8                       5304 00103$:
                           001921  5305 	C$fuzzy.h$2116$2_0$91 ==.
                                   5306 ;	../../fuzzy.h:2116: return LEVEL_LO;
      0019D8 90 00 00         [24] 5307 	mov	dptr,#0x0000
      0019DB E4               [12] 5308 	clr	a
      0019DC F5 F0            [12] 5309 	mov	b,a
                           001927  5310 	C$fuzzy.h$2117$1_0$90 ==.
                                   5311 ;	../../fuzzy.h:2117: }
      0019DE                       5312 00105$:
                           001927  5313 	C$fuzzy.h$2118$1_0$90 ==.
                                   5314 ;	../../fuzzy.h:2118: }
      0019DE 85 08 81         [24] 5315 	mov	sp,_bp
      0019E1 D0 08            [24] 5316 	pop	_bp
                           00192C  5317 	C$fuzzy.h$2118$1_0$90 ==.
                           00192C  5318 	XFcontroller_8051$fuzzy_implication$0$0 ==.
      0019E3 22               [24] 5319 	ret
                                   5320 ;------------------------------------------------------------
                                   5321 ;Allocation info for local variables in function 'fuzzy_aggregation'
                                   5322 ;------------------------------------------------------------
                                   5323 ;aggregated    Allocated to stack - _bp -6 +4 
                                   5324 ;implied       Allocated to stack - _bp -10 +4 
                                   5325 ;method        Allocated to registers r7 
                                   5326 ;sloc0         Allocated to stack - _bp +1 +4 
                                   5327 ;sloc1         Allocated to stack - _bp +5 +4 
                                   5328 ;sloc2         Allocated to stack - _bp +10 +4 
                                   5329 ;------------------------------------------------------------
                           00192D  5330 	Fcontroller_8051$fuzzy_aggregation$0$0 ==.
                           00192D  5331 	C$fuzzy.h$2120$1_0$93 ==.
                                   5332 ;	../../fuzzy.h:2120: static float fuzzy_aggregation(
                                   5333 ;	-----------------------------------------
                                   5334 ;	 function fuzzy_aggregation
                                   5335 ;	-----------------------------------------
      0019E4                       5336 _fuzzy_aggregation:
      0019E4 C0 08            [24] 5337 	push	_bp
      0019E6 E5 81            [12] 5338 	mov	a,sp
      0019E8 F5 08            [12] 5339 	mov	_bp,a
      0019EA 24 08            [12] 5340 	add	a,#0x08
      0019EC F5 81            [12] 5341 	mov	sp,a
      0019EE AF 82            [24] 5342 	mov	r7, dpl
                           001939  5343 	C$fuzzy.h$2126$1_0$93 ==.
                                   5344 ;	../../fuzzy.h:2126: aggregated = fuzzy_clamp(aggregated);
      0019F0 E5 08            [12] 5345 	mov	a,_bp
      0019F2 24 FA            [12] 5346 	add	a,#0xfa
      0019F4 F8               [12] 5347 	mov	r0,a
      0019F5 86 82            [24] 5348 	mov	dpl, @r0
      0019F7 08               [12] 5349 	inc	r0
      0019F8 86 83            [24] 5350 	mov	dph, @r0
      0019FA 08               [12] 5351 	inc	r0
      0019FB 86 F0            [24] 5352 	mov	b, @r0
      0019FD 08               [12] 5353 	inc	r0
      0019FE E6               [12] 5354 	mov	a, @r0
      0019FF C0 07            [24] 5355 	push	ar7
      001A01 12 00 EA         [24] 5356 	lcall	_fuzzy_clamp
      001A04 AE 82            [24] 5357 	mov	r6, dpl
      001A06 AD 83            [24] 5358 	mov	r5, dph
      001A08 AC F0            [24] 5359 	mov	r4, b
      001A0A FB               [12] 5360 	mov	r3, a
                           001954  5361 	C$fuzzy.h$2127$1_0$93 ==.
                                   5362 ;	../../fuzzy.h:2127: implied = fuzzy_clamp(implied);
      001A0B E5 08            [12] 5363 	mov	a,_bp
      001A0D 24 F6            [12] 5364 	add	a,#0xf6
      001A0F F8               [12] 5365 	mov	r0,a
      001A10 86 82            [24] 5366 	mov	dpl, @r0
      001A12 08               [12] 5367 	inc	r0
      001A13 86 83            [24] 5368 	mov	dph, @r0
      001A15 08               [12] 5369 	inc	r0
      001A16 86 F0            [24] 5370 	mov	b, @r0
      001A18 08               [12] 5371 	inc	r0
      001A19 E6               [12] 5372 	mov	a, @r0
      001A1A C0 06            [24] 5373 	push	ar6
      001A1C C0 05            [24] 5374 	push	ar5
      001A1E C0 04            [24] 5375 	push	ar4
      001A20 C0 03            [24] 5376 	push	ar3
      001A22 12 00 EA         [24] 5377 	lcall	_fuzzy_clamp
      001A25 A8 08            [24] 5378 	mov	r0,_bp
      001A27 08               [12] 5379 	inc	r0
      001A28 A6 82            [24] 5380 	mov	@r0, dpl
      001A2A 08               [12] 5381 	inc	r0
      001A2B A6 83            [24] 5382 	mov	@r0, dph
      001A2D 08               [12] 5383 	inc	r0
      001A2E A6 F0            [24] 5384 	mov	@r0, b
      001A30 08               [12] 5385 	inc	r0
      001A31 F6               [12] 5386 	mov	@r0,a
      001A32 D0 03            [24] 5387 	pop	ar3
      001A34 D0 04            [24] 5388 	pop	ar4
      001A36 D0 05            [24] 5389 	pop	ar5
      001A38 D0 06            [24] 5390 	pop	ar6
      001A3A D0 07            [24] 5391 	pop	ar7
                           001985  5392 	C$fuzzy.h$2129$1_0$93 ==.
                                   5393 ;	../../fuzzy.h:2129: switch (method) {
      001A3C BF 00 02         [24] 5394 	cjne	r7,#0x00,00134$
      001A3F 80 0E            [24] 5395 	sjmp	00101$
      001A41                       5396 00134$:
      001A41 BF 01 02         [24] 5397 	cjne	r7,#0x01,00135$
      001A44 80 76            [24] 5398 	sjmp	00102$
      001A46                       5399 00135$:
      001A46 BF 02 03         [24] 5400 	cjne	r7,#0x02,00136$
      001A49 02 1B 57         [24] 5401 	ljmp	00103$
      001A4C                       5402 00136$:
      001A4C 02 1B 8C         [24] 5403 	ljmp	00104$
                           001998  5404 	C$fuzzy.h$2130$2_0$94 ==.
                                   5405 ;	../../fuzzy.h:2130: case FUZZY_AGGREGATION_MAX:
      001A4F                       5406 00101$:
                           001998  5407 	C$fuzzy.h$2132$1_0$93 ==.
                                   5408 ;	../../fuzzy.h:2132: ? aggregated
      001A4F C0 06            [24] 5409 	push	ar6
      001A51 C0 05            [24] 5410 	push	ar5
      001A53 C0 04            [24] 5411 	push	ar4
      001A55 C0 03            [24] 5412 	push	ar3
      001A57 C0 06            [24] 5413 	push	ar6
      001A59 C0 05            [24] 5414 	push	ar5
      001A5B C0 04            [24] 5415 	push	ar4
      001A5D C0 03            [24] 5416 	push	ar3
      001A5F A8 08            [24] 5417 	mov	r0,_bp
      001A61 08               [12] 5418 	inc	r0
      001A62 86 82            [24] 5419 	mov	dpl, @r0
      001A64 08               [12] 5420 	inc	r0
      001A65 86 83            [24] 5421 	mov	dph, @r0
      001A67 08               [12] 5422 	inc	r0
      001A68 86 F0            [24] 5423 	mov	b, @r0
      001A6A 08               [12] 5424 	inc	r0
      001A6B E6               [12] 5425 	mov	a, @r0
      001A6C 12 27 68         [24] 5426 	lcall	___fslt
      001A6F AF 82            [24] 5427 	mov	r7, dpl
      001A71 E5 81            [12] 5428 	mov	a,sp
      001A73 24 FC            [12] 5429 	add	a,#0xfc
      001A75 F5 81            [12] 5430 	mov	sp,a
      001A77 D0 03            [24] 5431 	pop	ar3
      001A79 D0 04            [24] 5432 	pop	ar4
      001A7B D0 05            [24] 5433 	pop	ar5
      001A7D D0 06            [24] 5434 	pop	ar6
      001A7F EF               [12] 5435 	mov	a,r7
      001A80 60 12            [24] 5436 	jz	00108$
      001A82 E5 08            [12] 5437 	mov	a,_bp
      001A84 24 05            [12] 5438 	add	a,#0x05
      001A86 F8               [12] 5439 	mov	r0,a
      001A87 A6 06            [24] 5440 	mov	@r0,ar6
      001A89 08               [12] 5441 	inc	r0
      001A8A A6 05            [24] 5442 	mov	@r0,ar5
      001A8C 08               [12] 5443 	inc	r0
      001A8D A6 04            [24] 5444 	mov	@r0,ar4
      001A8F 08               [12] 5445 	inc	r0
      001A90 A6 03            [24] 5446 	mov	@r0,ar3
      001A92 80 16            [24] 5447 	sjmp	00109$
      001A94                       5448 00108$:
                           0019DD  5449 	C$fuzzy.h$2133$2_0$94 ==.
                                   5450 ;	../../fuzzy.h:2133: : implied;
      001A94 A8 08            [24] 5451 	mov	r0,_bp
      001A96 08               [12] 5452 	inc	r0
      001A97 E5 08            [12] 5453 	mov	a,_bp
      001A99 24 05            [12] 5454 	add	a,#0x05
      001A9B F9               [12] 5455 	mov	r1,a
      001A9C E6               [12] 5456 	mov	a,@r0
      001A9D F7               [12] 5457 	mov	@r1,a
      001A9E 08               [12] 5458 	inc	r0
      001A9F E6               [12] 5459 	mov	a,@r0
      001AA0 09               [12] 5460 	inc	r1
      001AA1 F7               [12] 5461 	mov	@r1,a
      001AA2 08               [12] 5462 	inc	r0
      001AA3 E6               [12] 5463 	mov	a,@r0
      001AA4 09               [12] 5464 	inc	r1
      001AA5 F7               [12] 5465 	mov	@r1,a
      001AA6 08               [12] 5466 	inc	r0
      001AA7 E6               [12] 5467 	mov	a,@r0
      001AA8 09               [12] 5468 	inc	r1
      001AA9 F7               [12] 5469 	mov	@r1,a
      001AAA                       5470 00109$:
      001AAA E5 08            [12] 5471 	mov	a,_bp
      001AAC 24 05            [12] 5472 	add	a,#0x05
      001AAE F8               [12] 5473 	mov	r0,a
      001AAF 86 82            [24] 5474 	mov	dpl, @r0
      001AB1 08               [12] 5475 	inc	r0
      001AB2 86 83            [24] 5476 	mov	dph, @r0
      001AB4 08               [12] 5477 	inc	r0
      001AB5 86 F0            [24] 5478 	mov	b, @r0
      001AB7 08               [12] 5479 	inc	r0
      001AB8 E6               [12] 5480 	mov	a, @r0
      001AB9 02 1B 92         [24] 5481 	ljmp	00106$
                           001A05  5482 	C$fuzzy.h$2135$2_0$94 ==.
                                   5483 ;	../../fuzzy.h:2135: case FUZZY_AGGREGATION_ALGEBRAIC:
      001ABC                       5484 00102$:
                           001A05  5485 	C$fuzzy.h$2137$1_0$93 ==.
                                   5486 ;	../../fuzzy.h:2137: implied -
      001ABC C0 06            [24] 5487 	push	ar6
      001ABE C0 05            [24] 5488 	push	ar5
      001AC0 C0 04            [24] 5489 	push	ar4
      001AC2 C0 03            [24] 5490 	push	ar3
      001AC4 A8 08            [24] 5491 	mov	r0,_bp
      001AC6 08               [12] 5492 	inc	r0
      001AC7 E6               [12] 5493 	mov	a,@r0
      001AC8 C0 E0            [24] 5494 	push	acc
      001ACA 08               [12] 5495 	inc	r0
      001ACB E6               [12] 5496 	mov	a,@r0
      001ACC C0 E0            [24] 5497 	push	acc
      001ACE 08               [12] 5498 	inc	r0
      001ACF E6               [12] 5499 	mov	a,@r0
      001AD0 C0 E0            [24] 5500 	push	acc
      001AD2 08               [12] 5501 	inc	r0
      001AD3 E6               [12] 5502 	mov	a,@r0
      001AD4 C0 E0            [24] 5503 	push	acc
                           001A1F  5504 	C$fuzzy.h$2138$1_0$93 ==.
                                   5505 ;	../../fuzzy.h:2138: aggregated * implied;
      001AD6 8E 82            [24] 5506 	mov	dpl, r6
      001AD8 8D 83            [24] 5507 	mov	dph, r5
      001ADA 8C F0            [24] 5508 	mov	b, r4
      001ADC EB               [12] 5509 	mov	a, r3
      001ADD 12 27 BA         [24] 5510 	lcall	___fsadd
      001AE0 C8               [12] 5511 	xch	a,r0
      001AE1 E5 08            [12] 5512 	mov	a,_bp
      001AE3 24 05            [12] 5513 	add	a,#0x05
      001AE5 C8               [12] 5514 	xch	a,r0
      001AE6 A6 82            [24] 5515 	mov	@r0, dpl
      001AE8 08               [12] 5516 	inc	r0
      001AE9 A6 83            [24] 5517 	mov	@r0, dph
      001AEB 08               [12] 5518 	inc	r0
      001AEC A6 F0            [24] 5519 	mov	@r0, b
      001AEE 08               [12] 5520 	inc	r0
      001AEF F6               [12] 5521 	mov	@r0,a
      001AF0 E5 81            [12] 5522 	mov	a,sp
      001AF2 24 FC            [12] 5523 	add	a,#0xfc
      001AF4 F5 81            [12] 5524 	mov	sp,a
      001AF6 D0 03            [24] 5525 	pop	ar3
      001AF8 D0 04            [24] 5526 	pop	ar4
      001AFA D0 05            [24] 5527 	pop	ar5
      001AFC D0 06            [24] 5528 	pop	ar6
      001AFE A8 08            [24] 5529 	mov	r0,_bp
      001B00 08               [12] 5530 	inc	r0
      001B01 E6               [12] 5531 	mov	a,@r0
      001B02 C0 E0            [24] 5532 	push	acc
      001B04 08               [12] 5533 	inc	r0
      001B05 E6               [12] 5534 	mov	a,@r0
      001B06 C0 E0            [24] 5535 	push	acc
      001B08 08               [12] 5536 	inc	r0
      001B09 E6               [12] 5537 	mov	a,@r0
      001B0A C0 E0            [24] 5538 	push	acc
      001B0C 08               [12] 5539 	inc	r0
      001B0D E6               [12] 5540 	mov	a,@r0
      001B0E C0 E0            [24] 5541 	push	acc
      001B10 8E 82            [24] 5542 	mov	dpl, r6
      001B12 8D 83            [24] 5543 	mov	dph, r5
      001B14 8C F0            [24] 5544 	mov	b, r4
      001B16 EB               [12] 5545 	mov	a, r3
      001B17 12 26 38         [24] 5546 	lcall	___fsmul
      001B1A AB 82            [24] 5547 	mov	r3, dpl
      001B1C AC 83            [24] 5548 	mov	r4, dph
      001B1E AE F0            [24] 5549 	mov	r6, b
      001B20 FF               [12] 5550 	mov	r7, a
      001B21 E5 81            [12] 5551 	mov	a,sp
      001B23 24 FC            [12] 5552 	add	a,#0xfc
      001B25 F5 81            [12] 5553 	mov	sp,a
      001B27 C0 03            [24] 5554 	push	ar3
      001B29 C0 04            [24] 5555 	push	ar4
      001B2B C0 06            [24] 5556 	push	ar6
      001B2D C0 07            [24] 5557 	push	ar7
      001B2F E5 08            [12] 5558 	mov	a,_bp
      001B31 24 05            [12] 5559 	add	a,#0x05
      001B33 F8               [12] 5560 	mov	r0,a
      001B34 86 82            [24] 5561 	mov	dpl, @r0
      001B36 08               [12] 5562 	inc	r0
      001B37 86 83            [24] 5563 	mov	dph, @r0
      001B39 08               [12] 5564 	inc	r0
      001B3A 86 F0            [24] 5565 	mov	b, @r0
      001B3C 08               [12] 5566 	inc	r0
      001B3D E6               [12] 5567 	mov	a, @r0
      001B3E 12 26 2D         [24] 5568 	lcall	___fssub
      001B41 AC 82            [24] 5569 	mov	r4, dpl
      001B43 AD 83            [24] 5570 	mov	r5, dph
      001B45 AE F0            [24] 5571 	mov	r6, b
      001B47 FF               [12] 5572 	mov	r7, a
      001B48 E5 81            [12] 5573 	mov	a,sp
      001B4A 24 FC            [12] 5574 	add	a,#0xfc
      001B4C F5 81            [12] 5575 	mov	sp,a
      001B4E 8C 82            [24] 5576 	mov	dpl, r4
      001B50 8D 83            [24] 5577 	mov	dph, r5
      001B52 8E F0            [24] 5578 	mov	b, r6
      001B54 EF               [12] 5579 	mov	a, r7
                           001A9E  5580 	C$fuzzy.h$2140$2_0$94 ==.
                                   5581 ;	../../fuzzy.h:2140: case FUZZY_AGGREGATION_BOUNDED:
      001B55 80 3B            [24] 5582 	sjmp	00106$
      001B57                       5583 00103$:
                           001AA0  5584 	C$fuzzy.h$2144$1_0$93 ==.
                                   5585 ;	../../fuzzy.h:2144: );
      001B57 A8 08            [24] 5586 	mov	r0,_bp
      001B59 08               [12] 5587 	inc	r0
      001B5A E6               [12] 5588 	mov	a,@r0
      001B5B C0 E0            [24] 5589 	push	acc
      001B5D 08               [12] 5590 	inc	r0
      001B5E E6               [12] 5591 	mov	a,@r0
      001B5F C0 E0            [24] 5592 	push	acc
      001B61 08               [12] 5593 	inc	r0
      001B62 E6               [12] 5594 	mov	a,@r0
      001B63 C0 E0            [24] 5595 	push	acc
      001B65 08               [12] 5596 	inc	r0
      001B66 E6               [12] 5597 	mov	a,@r0
      001B67 C0 E0            [24] 5598 	push	acc
      001B69 8E 82            [24] 5599 	mov	dpl, r6
      001B6B 8D 83            [24] 5600 	mov	dph, r5
      001B6D 8C F0            [24] 5601 	mov	b, r4
      001B6F EB               [12] 5602 	mov	a, r3
      001B70 12 27 BA         [24] 5603 	lcall	___fsadd
      001B73 AC 82            [24] 5604 	mov	r4, dpl
      001B75 AD 83            [24] 5605 	mov	r5, dph
      001B77 AE F0            [24] 5606 	mov	r6, b
      001B79 FF               [12] 5607 	mov	r7, a
      001B7A E5 81            [12] 5608 	mov	a,sp
      001B7C 24 FC            [12] 5609 	add	a,#0xfc
      001B7E F5 81            [12] 5610 	mov	sp,a
      001B80 8C 82            [24] 5611 	mov	dpl, r4
      001B82 8D 83            [24] 5612 	mov	dph, r5
      001B84 8E F0            [24] 5613 	mov	b, r6
      001B86 EF               [12] 5614 	mov	a, r7
      001B87 12 00 EA         [24] 5615 	lcall	_fuzzy_clamp
                           001AD3  5616 	C$fuzzy.h$2146$2_0$94 ==.
                                   5617 ;	../../fuzzy.h:2146: default:
      001B8A 80 06            [24] 5618 	sjmp	00106$
      001B8C                       5619 00104$:
                           001AD5  5620 	C$fuzzy.h$2147$2_0$94 ==.
                                   5621 ;	../../fuzzy.h:2147: return LEVEL_LO;
      001B8C 90 00 00         [24] 5622 	mov	dptr,#0x0000
      001B8F E4               [12] 5623 	clr	a
      001B90 F5 F0            [12] 5624 	mov	b,a
                           001ADB  5625 	C$fuzzy.h$2148$1_0$93 ==.
                                   5626 ;	../../fuzzy.h:2148: }
      001B92                       5627 00106$:
                           001ADB  5628 	C$fuzzy.h$2149$1_0$93 ==.
                                   5629 ;	../../fuzzy.h:2149: }
      001B92 85 08 81         [24] 5630 	mov	sp,_bp
      001B95 D0 08            [24] 5631 	pop	_bp
                           001AE0  5632 	C$fuzzy.h$2149$1_0$93 ==.
                           001AE0  5633 	XFcontroller_8051$fuzzy_aggregation$0$0 ==.
      001B97 22               [24] 5634 	ret
                                   5635 ;------------------------------------------------------------
                                   5636 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_method'
                                   5637 ;------------------------------------------------------------
                                   5638 ;lower         Allocated to stack - _bp -6 +4 
                                   5639 ;upper         Allocated to stack - _bp -10 +4 
                                   5640 ;step          Allocated to stack - _bp -14 +4 
                                   5641 ;defuzz_method Allocated to stack - _bp -15 +1 
                                   5642 ;implication_method Allocated to stack - _bp -16 +1 
                                   5643 ;aggregation_method Allocated to stack - _bp -17 +1 
                                   5644 ;rules         Allocated to stack - _bp +1 +3 
                                   5645 ;weighted_sum  Allocated to stack - _bp +16 +4 
                                   5646 ;height_sum    Allocated to stack - _bp +20 +4 
                                   5647 ;maximum_height Allocated to stack - _bp +24 +4 
                                   5648 ;maximum_position_sum Allocated to stack - _bp +28 +4 
                                   5649 ;smallest_maximum Allocated to stack - _bp +32 +4 
                                   5650 ;largest_maximum Allocated to stack - _bp +36 +4 
                                   5651 ;value         Allocated to stack - _bp +40 +4 
                                   5652 ;aggregated_height Allocated to stack - _bp +44 +4 
                                   5653 ;output_membership Allocated to stack - _bp +48 +4 
                                   5654 ;implied_height Allocated to registers r4 r5 r6 r7 
                                   5655 ;maximum_count Allocated to stack - _bp +52 +2 
                                   5656 ;index         Allocated to stack - _bp +54 +2 
                                   5657 ;maximum_found Allocated to stack - _bp +56 +1 
                                   5658 ;sloc0         Allocated to stack - _bp +4 +3 
                                   5659 ;sloc1         Allocated to stack - _bp +7 +4 
                                   5660 ;sloc2         Allocated to stack - _bp +11 +2 
                                   5661 ;sloc3         Allocated to stack - _bp +13 +3 
                                   5662 ;------------------------------------------------------------
                           001AE1  5663 	G$fuzzy_rules_defuzzify_method$0$0 ==.
                           001AE1  5664 	C$fuzzy.h$2166$1_0$96 ==.
                                   5665 ;	../../fuzzy.h:2166: float fuzzy_rules_defuzzify_method(
                                   5666 ;	-----------------------------------------
                                   5667 ;	 function fuzzy_rules_defuzzify_method
                                   5668 ;	-----------------------------------------
      001B98                       5669 _fuzzy_rules_defuzzify_method:
      001B98 C0 08            [24] 5670 	push	_bp
      001B9A 85 81 08         [24] 5671 	mov	_bp,sp
      001B9D C0 82            [24] 5672 	push	dpl
      001B9F C0 83            [24] 5673 	push	dph
      001BA1 C0 F0            [24] 5674 	push	b
      001BA3 E5 81            [12] 5675 	mov	a,sp
      001BA5 24 35            [12] 5676 	add	a,#0x35
      001BA7 F5 81            [12] 5677 	mov	sp,a
                           001AF2  5678 	C$fuzzy.h$2176$2_0$96 ==.
                                   5679 ;	../../fuzzy.h:2176: float weighted_sum = 0.0f;
      001BA9 E5 08            [12] 5680 	mov	a,_bp
      001BAB 24 10            [12] 5681 	add	a,#0x10
      001BAD F8               [12] 5682 	mov	r0,a
      001BAE E4               [12] 5683 	clr	a
      001BAF F6               [12] 5684 	mov	@r0,a
      001BB0 08               [12] 5685 	inc	r0
      001BB1 F6               [12] 5686 	mov	@r0,a
      001BB2 08               [12] 5687 	inc	r0
      001BB3 F6               [12] 5688 	mov	@r0,a
      001BB4 08               [12] 5689 	inc	r0
      001BB5 F6               [12] 5690 	mov	@r0,a
                           001AFF  5691 	C$fuzzy.h$2177$2_0$96 ==.
                                   5692 ;	../../fuzzy.h:2177: float height_sum = 0.0f;
      001BB6 E5 08            [12] 5693 	mov	a,_bp
      001BB8 24 14            [12] 5694 	add	a,#0x14
      001BBA F8               [12] 5695 	mov	r0,a
      001BBB E4               [12] 5696 	clr	a
      001BBC F6               [12] 5697 	mov	@r0,a
      001BBD 08               [12] 5698 	inc	r0
      001BBE F6               [12] 5699 	mov	@r0,a
      001BBF 08               [12] 5700 	inc	r0
      001BC0 F6               [12] 5701 	mov	@r0,a
      001BC1 08               [12] 5702 	inc	r0
      001BC2 F6               [12] 5703 	mov	@r0,a
                           001B0C  5704 	C$fuzzy.h$2178$2_0$96 ==.
                                   5705 ;	../../fuzzy.h:2178: float maximum_height = LEVEL_LO;
      001BC3 E5 08            [12] 5706 	mov	a,_bp
      001BC5 24 18            [12] 5707 	add	a,#0x18
      001BC7 F8               [12] 5708 	mov	r0,a
      001BC8 E4               [12] 5709 	clr	a
      001BC9 F6               [12] 5710 	mov	@r0,a
      001BCA 08               [12] 5711 	inc	r0
      001BCB F6               [12] 5712 	mov	@r0,a
      001BCC 08               [12] 5713 	inc	r0
      001BCD F6               [12] 5714 	mov	@r0,a
      001BCE 08               [12] 5715 	inc	r0
      001BCF F6               [12] 5716 	mov	@r0,a
                           001B19  5717 	C$fuzzy.h$2179$2_0$96 ==.
                                   5718 ;	../../fuzzy.h:2179: float maximum_position_sum = 0.0f;
      001BD0 E5 08            [12] 5719 	mov	a,_bp
      001BD2 24 1C            [12] 5720 	add	a,#0x1c
      001BD4 F8               [12] 5721 	mov	r0,a
      001BD5 E4               [12] 5722 	clr	a
      001BD6 F6               [12] 5723 	mov	@r0,a
      001BD7 08               [12] 5724 	inc	r0
      001BD8 F6               [12] 5725 	mov	@r0,a
      001BD9 08               [12] 5726 	inc	r0
      001BDA F6               [12] 5727 	mov	@r0,a
      001BDB 08               [12] 5728 	inc	r0
      001BDC F6               [12] 5729 	mov	@r0,a
                           001B26  5730 	C$fuzzy.h$2180$2_0$96 ==.
                                   5731 ;	../../fuzzy.h:2180: float smallest_maximum = lower;
      001BDD E5 08            [12] 5732 	mov	a,_bp
      001BDF 24 FA            [12] 5733 	add	a,#0xfa
      001BE1 F8               [12] 5734 	mov	r0,a
      001BE2 E5 08            [12] 5735 	mov	a,_bp
      001BE4 24 20            [12] 5736 	add	a,#0x20
      001BE6 F9               [12] 5737 	mov	r1,a
      001BE7 E6               [12] 5738 	mov	a,@r0
      001BE8 F7               [12] 5739 	mov	@r1,a
      001BE9 08               [12] 5740 	inc	r0
      001BEA E6               [12] 5741 	mov	a,@r0
      001BEB 09               [12] 5742 	inc	r1
      001BEC F7               [12] 5743 	mov	@r1,a
      001BED 08               [12] 5744 	inc	r0
      001BEE E6               [12] 5745 	mov	a,@r0
      001BEF 09               [12] 5746 	inc	r1
      001BF0 F7               [12] 5747 	mov	@r1,a
      001BF1 08               [12] 5748 	inc	r0
      001BF2 E6               [12] 5749 	mov	a,@r0
      001BF3 09               [12] 5750 	inc	r1
      001BF4 F7               [12] 5751 	mov	@r1,a
                           001B3E  5752 	C$fuzzy.h$2181$2_0$96 ==.
                                   5753 ;	../../fuzzy.h:2181: float largest_maximum = lower;
      001BF5 E5 08            [12] 5754 	mov	a,_bp
      001BF7 24 20            [12] 5755 	add	a,#0x20
      001BF9 F8               [12] 5756 	mov	r0,a
      001BFA E5 08            [12] 5757 	mov	a,_bp
      001BFC 24 24            [12] 5758 	add	a,#0x24
      001BFE F9               [12] 5759 	mov	r1,a
      001BFF E6               [12] 5760 	mov	a,@r0
      001C00 F7               [12] 5761 	mov	@r1,a
      001C01 08               [12] 5762 	inc	r0
      001C02 E6               [12] 5763 	mov	a,@r0
      001C03 09               [12] 5764 	inc	r1
      001C04 F7               [12] 5765 	mov	@r1,a
      001C05 08               [12] 5766 	inc	r0
      001C06 E6               [12] 5767 	mov	a,@r0
      001C07 09               [12] 5768 	inc	r1
      001C08 F7               [12] 5769 	mov	@r1,a
      001C09 08               [12] 5770 	inc	r0
      001C0A E6               [12] 5771 	mov	a,@r0
      001C0B 09               [12] 5772 	inc	r1
      001C0C F7               [12] 5773 	mov	@r1,a
                           001B56  5774 	C$fuzzy.h$2186$2_0$96 ==.
                                   5775 ;	../../fuzzy.h:2186: size_t maximum_count = 0u;
      001C0D E5 08            [12] 5776 	mov	a,_bp
      001C0F 24 34            [12] 5777 	add	a,#0x34
      001C11 F8               [12] 5778 	mov	r0,a
      001C12 E4               [12] 5779 	clr	a
      001C13 F6               [12] 5780 	mov	@r0,a
      001C14 08               [12] 5781 	inc	r0
      001C15 F6               [12] 5782 	mov	@r0,a
                           001B5F  5783 	C$fuzzy.h$2188$2_0$96 ==.
                                   5784 ;	../../fuzzy.h:2188: bool maximum_found = false;
      001C16 E5 08            [12] 5785 	mov	a,_bp
      001C18 24 38            [12] 5786 	add	a,#0x38
      001C1A F8               [12] 5787 	mov	r0,a
      001C1B 76 00            [12] 5788 	mov	@r0,#0x00
                           001B66  5789 	C$fuzzy.h$2191$1_0$96 ==.
                                   5790 ;	../../fuzzy.h:2191: rules == NULL ||
      001C1D A8 08            [24] 5791 	mov	r0,_bp
      001C1F 08               [12] 5792 	inc	r0
      001C20 E6               [12] 5793 	mov	a,@r0
      001C21 08               [12] 5794 	inc	r0
      001C22 46               [12] 5795 	orl	a,@r0
      001C23 70 03            [24] 5796 	jnz	00217$
      001C25 02 1C B1         [24] 5797 	ljmp	00101$
      001C28                       5798 00217$:
                           001B71  5799 	C$fuzzy.h$2192$1_0$96 ==.
                                   5800 ;	../../fuzzy.h:2192: rules->count == 0u ||
      001C28 A8 08            [24] 5801 	mov	r0,_bp
      001C2A 08               [12] 5802 	inc	r0
      001C2B E5 08            [12] 5803 	mov	a,_bp
      001C2D 24 04            [12] 5804 	add	a,#0x04
      001C2F F9               [12] 5805 	mov	r1,a
      001C30 74 90            [12] 5806 	mov	a,#0x90
      001C32 26               [12] 5807 	add	a, @r0
      001C33 F7               [12] 5808 	mov	@r1,a
      001C34 E4               [12] 5809 	clr	a
      001C35 08               [12] 5810 	inc	r0
      001C36 36               [12] 5811 	addc	a, @r0
      001C37 09               [12] 5812 	inc	r1
      001C38 F7               [12] 5813 	mov	@r1,a
      001C39 08               [12] 5814 	inc	r0
      001C3A E6               [12] 5815 	mov	a,@r0
      001C3B 09               [12] 5816 	inc	r1
      001C3C F7               [12] 5817 	mov	@r1,a
      001C3D E5 08            [12] 5818 	mov	a,_bp
      001C3F 24 04            [12] 5819 	add	a,#0x04
      001C41 F8               [12] 5820 	mov	r0,a
      001C42 86 82            [24] 5821 	mov	dpl,@r0
      001C44 08               [12] 5822 	inc	r0
      001C45 86 83            [24] 5823 	mov	dph,@r0
      001C47 08               [12] 5824 	inc	r0
      001C48 86 F0            [24] 5825 	mov	b,@r0
      001C4A 12 29 94         [24] 5826 	lcall	__gptrget
      001C4D FE               [12] 5827 	mov	r6,a
      001C4E A3               [24] 5828 	inc	dptr
      001C4F 12 29 94         [24] 5829 	lcall	__gptrget
      001C52 4E               [12] 5830 	orl	a,r6
      001C53 60 5C            [24] 5831 	jz	00101$
                           001B9E  5832 	C$fuzzy.h$2193$1_0$96 ==.
                                   5833 ;	../../fuzzy.h:2193: lower > upper ||
      001C55 E5 08            [12] 5834 	mov	a,_bp
      001C57 24 20            [12] 5835 	add	a,#0x20
      001C59 F8               [12] 5836 	mov	r0,a
      001C5A E6               [12] 5837 	mov	a,@r0
      001C5B C0 E0            [24] 5838 	push	acc
      001C5D 08               [12] 5839 	inc	r0
      001C5E E6               [12] 5840 	mov	a,@r0
      001C5F C0 E0            [24] 5841 	push	acc
      001C61 08               [12] 5842 	inc	r0
      001C62 E6               [12] 5843 	mov	a,@r0
      001C63 C0 E0            [24] 5844 	push	acc
      001C65 08               [12] 5845 	inc	r0
      001C66 E6               [12] 5846 	mov	a,@r0
      001C67 C0 E0            [24] 5847 	push	acc
      001C69 E5 08            [12] 5848 	mov	a,_bp
      001C6B 24 F6            [12] 5849 	add	a,#0xf6
      001C6D F8               [12] 5850 	mov	r0,a
      001C6E 86 82            [24] 5851 	mov	dpl, @r0
      001C70 08               [12] 5852 	inc	r0
      001C71 86 83            [24] 5853 	mov	dph, @r0
      001C73 08               [12] 5854 	inc	r0
      001C74 86 F0            [24] 5855 	mov	b, @r0
      001C76 08               [12] 5856 	inc	r0
      001C77 E6               [12] 5857 	mov	a, @r0
      001C78 12 27 68         [24] 5858 	lcall	___fslt
      001C7B AF 82            [24] 5859 	mov	r7, dpl
      001C7D E5 81            [12] 5860 	mov	a,sp
      001C7F 24 FC            [12] 5861 	add	a,#0xfc
      001C81 F5 81            [12] 5862 	mov	sp,a
      001C83 EF               [12] 5863 	mov	a,r7
      001C84 70 2B            [24] 5864 	jnz	00101$
                           001BCF  5865 	C$fuzzy.h$2195$1_0$96 ==.
                                   5866 ;	../../fuzzy.h:2195: ) {
      001C86 E5 08            [12] 5867 	mov	a,_bp
      001C88 24 F2            [12] 5868 	add	a,#0xf2
      001C8A F8               [12] 5869 	mov	r0,a
      001C8B E6               [12] 5870 	mov	a,@r0
      001C8C C0 E0            [24] 5871 	push	acc
      001C8E 08               [12] 5872 	inc	r0
      001C8F E6               [12] 5873 	mov	a,@r0
      001C90 C0 E0            [24] 5874 	push	acc
      001C92 08               [12] 5875 	inc	r0
      001C93 E6               [12] 5876 	mov	a,@r0
      001C94 C0 E0            [24] 5877 	push	acc
      001C96 08               [12] 5878 	inc	r0
      001C97 E6               [12] 5879 	mov	a,@r0
      001C98 C0 E0            [24] 5880 	push	acc
      001C9A 90 00 00         [24] 5881 	mov	dptr,#0x0000
      001C9D E4               [12] 5882 	clr	a
      001C9E F5 F0            [12] 5883 	mov	b,a
      001CA0 12 27 68         [24] 5884 	lcall	___fslt
      001CA3 E5 81            [12] 5885 	mov	a,sp
      001CA5 24 FC            [12] 5886 	add	a,#0xfc
      001CA7 F5 81            [12] 5887 	mov	sp,a
      001CA9 E5 82            [12] 5888 	mov	a, dpl
      001CAB 24 FF            [12] 5889 	add	a,#0xff
      001CAD 92 00            [24] 5890 	mov	b0,c
      001CAF 40 09            [24] 5891 	jc	00102$
      001CB1                       5892 00101$:
                           001BFA  5893 	C$fuzzy.h$2196$2_0$97 ==.
                                   5894 ;	../../fuzzy.h:2196: return 0.0f;
      001CB1 90 00 00         [24] 5895 	mov	dptr,#0x0000
      001CB4 E4               [12] 5896 	clr	a
      001CB5 F5 F0            [12] 5897 	mov	b,a
      001CB7 02 21 E5         [24] 5898 	ljmp	00130$
      001CBA                       5899 00102$:
                           001C03  5900 	C$fuzzy.h$2200$2_0$98 ==.
                                   5901 ;	../../fuzzy.h:2200: value = lower;
      001CBA E5 08            [12] 5902 	mov	a,_bp
      001CBC 24 20            [12] 5903 	add	a,#0x20
      001CBE F8               [12] 5904 	mov	r0,a
      001CBF E5 08            [12] 5905 	mov	a,_bp
      001CC1 24 28            [12] 5906 	add	a,#0x28
      001CC3 F9               [12] 5907 	mov	r1,a
      001CC4 E6               [12] 5908 	mov	a,@r0
      001CC5 F7               [12] 5909 	mov	@r1,a
      001CC6 08               [12] 5910 	inc	r0
      001CC7 E6               [12] 5911 	mov	a,@r0
      001CC8 09               [12] 5912 	inc	r1
      001CC9 F7               [12] 5913 	mov	@r1,a
      001CCA 08               [12] 5914 	inc	r0
      001CCB E6               [12] 5915 	mov	a,@r0
      001CCC 09               [12] 5916 	inc	r1
      001CCD F7               [12] 5917 	mov	@r1,a
      001CCE 08               [12] 5918 	inc	r0
      001CCF E6               [12] 5919 	mov	a,@r0
      001CD0 09               [12] 5920 	inc	r1
      001CD1 F7               [12] 5921 	mov	@r1,a
      001CD2 A8 08            [24] 5922 	mov	r0,_bp
      001CD4 08               [12] 5923 	inc	r0
      001CD5 E5 08            [12] 5924 	mov	a,_bp
      001CD7 24 0D            [12] 5925 	add	a,#0x0d
      001CD9 F9               [12] 5926 	mov	r1,a
      001CDA E6               [12] 5927 	mov	a,@r0
      001CDB F7               [12] 5928 	mov	@r1,a
      001CDC 08               [12] 5929 	inc	r0
      001CDD E6               [12] 5930 	mov	a,@r0
      001CDE 09               [12] 5931 	inc	r1
      001CDF F7               [12] 5932 	mov	@r1,a
      001CE0 08               [12] 5933 	inc	r0
      001CE1 E6               [12] 5934 	mov	a,@r0
      001CE2 09               [12] 5935 	inc	r1
      001CE3 F7               [12] 5936 	mov	@r1,a
      001CE4                       5937 00128$:
                           001C2D  5938 	C$fuzzy.h$2201$1_0$96 ==.
                                   5939 ;	../../fuzzy.h:2201: value <= upper;
      001CE4 E5 08            [12] 5940 	mov	a,_bp
      001CE6 24 28            [12] 5941 	add	a,#0x28
      001CE8 F8               [12] 5942 	mov	r0,a
      001CE9 E6               [12] 5943 	mov	a,@r0
      001CEA C0 E0            [24] 5944 	push	acc
      001CEC 08               [12] 5945 	inc	r0
      001CED E6               [12] 5946 	mov	a,@r0
      001CEE C0 E0            [24] 5947 	push	acc
      001CF0 08               [12] 5948 	inc	r0
      001CF1 E6               [12] 5949 	mov	a,@r0
      001CF2 C0 E0            [24] 5950 	push	acc
      001CF4 08               [12] 5951 	inc	r0
      001CF5 E6               [12] 5952 	mov	a,@r0
      001CF6 C0 E0            [24] 5953 	push	acc
      001CF8 E5 08            [12] 5954 	mov	a,_bp
      001CFA 24 F6            [12] 5955 	add	a,#0xf6
      001CFC F8               [12] 5956 	mov	r0,a
      001CFD 86 82            [24] 5957 	mov	dpl, @r0
      001CFF 08               [12] 5958 	inc	r0
      001D00 86 83            [24] 5959 	mov	dph, @r0
      001D02 08               [12] 5960 	inc	r0
      001D03 86 F0            [24] 5961 	mov	b, @r0
      001D05 08               [12] 5962 	inc	r0
      001D06 E6               [12] 5963 	mov	a, @r0
      001D07 12 27 68         [24] 5964 	lcall	___fslt
      001D0A E5 81            [12] 5965 	mov	a,sp
      001D0C 24 FC            [12] 5966 	add	a,#0xfc
      001D0E F5 81            [12] 5967 	mov	sp,a
      001D10 E5 82            [12] 5968 	mov	a, dpl
      001D12 24 FF            [12] 5969 	add	a,#0xff
      001D14 92 00            [24] 5970 	mov	b0,c
      001D16 50 03            [24] 5971 	jnc	00221$
      001D18 02 20 B1         [24] 5972 	ljmp	00113$
      001D1B                       5973 00221$:
                           001C64  5974 	C$fuzzy.h$2204$3_0$99 ==.
                                   5975 ;	../../fuzzy.h:2204: aggregated_height = LEVEL_LO;
      001D1B E5 08            [12] 5976 	mov	a,_bp
      001D1D 24 07            [12] 5977 	add	a,#0x07
      001D1F F8               [12] 5978 	mov	r0,a
      001D20 E4               [12] 5979 	clr	a
      001D21 F6               [12] 5980 	mov	@r0,a
      001D22 08               [12] 5981 	inc	r0
      001D23 F6               [12] 5982 	mov	@r0,a
      001D24 08               [12] 5983 	inc	r0
      001D25 F6               [12] 5984 	mov	@r0,a
      001D26 08               [12] 5985 	inc	r0
      001D27 F6               [12] 5986 	mov	@r0,a
                           001C71  5987 	C$fuzzy.h$2207$1_0$96 ==.
                                   5988 ;	../../fuzzy.h:2207: index = 0u;
      001D28 E5 08            [12] 5989 	mov	a,_bp
      001D2A 24 36            [12] 5990 	add	a,#0x36
      001D2C F8               [12] 5991 	mov	r0,a
      001D2D E4               [12] 5992 	clr	a
      001D2E F6               [12] 5993 	mov	@r0,a
      001D2F 08               [12] 5994 	inc	r0
      001D30 F6               [12] 5995 	mov	@r0,a
      001D31 E5 08            [12] 5996 	mov	a,_bp
      001D33 24 0B            [12] 5997 	add	a,#0x0b
      001D35 F8               [12] 5998 	mov	r0,a
      001D36 E4               [12] 5999 	clr	a
      001D37 F6               [12] 6000 	mov	@r0,a
      001D38 08               [12] 6001 	inc	r0
      001D39 F6               [12] 6002 	mov	@r0,a
      001D3A                       6003 00125$:
                           001C83  6004 	C$fuzzy.h$2208$1_0$96 ==.
                                   6005 ;	../../fuzzy.h:2208: index < rules->count;
      001D3A E5 08            [12] 6006 	mov	a,_bp
      001D3C 24 04            [12] 6007 	add	a,#0x04
      001D3E F8               [12] 6008 	mov	r0,a
      001D3F 86 82            [24] 6009 	mov	dpl,@r0
      001D41 08               [12] 6010 	inc	r0
      001D42 86 83            [24] 6011 	mov	dph,@r0
      001D44 08               [12] 6012 	inc	r0
      001D45 86 F0            [24] 6013 	mov	b,@r0
      001D47 12 29 94         [24] 6014 	lcall	__gptrget
      001D4A FC               [12] 6015 	mov	r4,a
      001D4B A3               [24] 6016 	inc	dptr
      001D4C 12 29 94         [24] 6017 	lcall	__gptrget
      001D4F FF               [12] 6018 	mov	r7,a
      001D50 E5 08            [12] 6019 	mov	a,_bp
      001D52 24 36            [12] 6020 	add	a,#0x36
      001D54 F8               [12] 6021 	mov	r0,a
      001D55 C3               [12] 6022 	clr	c
      001D56 E6               [12] 6023 	mov	a,@r0
      001D57 9C               [12] 6024 	subb	a,r4
      001D58 08               [12] 6025 	inc	r0
      001D59 E6               [12] 6026 	mov	a,@r0
      001D5A 9F               [12] 6027 	subb	a,r7
      001D5B 40 03            [24] 6028 	jc	00222$
      001D5D 02 1E 74         [24] 6029 	ljmp	00106$
      001D60                       6030 00222$:
                           001CA9  6031 	C$fuzzy.h$2212$5_0$101 ==.
                                   6032 ;	../../fuzzy.h:2212: rules->rules[index].output_function(value)
      001D60 E5 08            [12] 6033 	mov	a,_bp
      001D62 24 0D            [12] 6034 	add	a,#0x0d
      001D64 F8               [12] 6035 	mov	r0,a
      001D65 E5 08            [12] 6036 	mov	a,_bp
      001D67 24 0B            [12] 6037 	add	a,#0x0b
      001D69 F9               [12] 6038 	mov	r1,a
      001D6A E7               [12] 6039 	mov	a,@r1
      001D6B 26               [12] 6040 	add	a, @r0
      001D6C FC               [12] 6041 	mov	r4,a
      001D6D 09               [12] 6042 	inc	r1
      001D6E E7               [12] 6043 	mov	a,@r1
      001D6F 08               [12] 6044 	inc	r0
      001D70 36               [12] 6045 	addc	a, @r0
      001D71 FD               [12] 6046 	mov	r5,a
      001D72 08               [12] 6047 	inc	r0
      001D73 86 06            [24] 6048 	mov	ar6,@r0
      001D75 74 07            [12] 6049 	mov	a,#0x07
      001D77 2C               [12] 6050 	add	a, r4
      001D78 FC               [12] 6051 	mov	r4,a
      001D79 E4               [12] 6052 	clr	a
      001D7A 3D               [12] 6053 	addc	a, r5
      001D7B FD               [12] 6054 	mov	r5,a
      001D7C 8C 82            [24] 6055 	mov	dpl,r4
      001D7E 8D 83            [24] 6056 	mov	dph,r5
      001D80 8E F0            [24] 6057 	mov	b,r6
      001D82 12 29 94         [24] 6058 	lcall	__gptrget
      001D85 FC               [12] 6059 	mov	r4,a
      001D86 A3               [24] 6060 	inc	dptr
      001D87 12 29 94         [24] 6061 	lcall	__gptrget
      001D8A FD               [12] 6062 	mov	r5,a
      001D8B 12 1D 90         [24] 6063 	lcall	00223$
      001D8E 80 14            [24] 6064 	sjmp	00224$
      001D90                       6065 00223$:
      001D90 C0 04            [24] 6066 	push	ar4
      001D92 C0 05            [24] 6067 	push	ar5
      001D94 E5 08            [12] 6068 	mov	a,_bp
      001D96 24 28            [12] 6069 	add	a,#0x28
      001D98 F8               [12] 6070 	mov	r0,a
      001D99 86 82            [24] 6071 	mov	dpl, @r0
      001D9B 08               [12] 6072 	inc	r0
      001D9C 86 83            [24] 6073 	mov	dph, @r0
      001D9E 08               [12] 6074 	inc	r0
      001D9F 86 F0            [24] 6075 	mov	b, @r0
      001DA1 08               [12] 6076 	inc	r0
      001DA2 E6               [12] 6077 	mov	a, @r0
      001DA3 22               [24] 6078 	ret
      001DA4                       6079 00224$:
      001DA4 12 00 EA         [24] 6080 	lcall	_fuzzy_clamp
      001DA7 C8               [12] 6081 	xch	a,r0
      001DA8 E5 08            [12] 6082 	mov	a,_bp
      001DAA 24 30            [12] 6083 	add	a,#0x30
      001DAC C8               [12] 6084 	xch	a,r0
      001DAD A6 82            [24] 6085 	mov	@r0, dpl
      001DAF 08               [12] 6086 	inc	r0
      001DB0 A6 83            [24] 6087 	mov	@r0, dph
      001DB2 08               [12] 6088 	inc	r0
      001DB3 A6 F0            [24] 6089 	mov	@r0, b
      001DB5 08               [12] 6090 	inc	r0
      001DB6 F6               [12] 6091 	mov	@r0,a
                           001D00  6092 	C$fuzzy.h$2217$5_0$101 ==.
                                   6093 ;	../../fuzzy.h:2217: rules->rules[index].value,
      001DB7 A8 08            [24] 6094 	mov	r0,_bp
      001DB9 08               [12] 6095 	inc	r0
      001DBA E5 08            [12] 6096 	mov	a,_bp
      001DBC 24 0B            [12] 6097 	add	a,#0x0b
      001DBE F9               [12] 6098 	mov	r1,a
      001DBF E7               [12] 6099 	mov	a,@r1
      001DC0 26               [12] 6100 	add	a, @r0
      001DC1 FA               [12] 6101 	mov	r2,a
      001DC2 09               [12] 6102 	inc	r1
      001DC3 E7               [12] 6103 	mov	a,@r1
      001DC4 08               [12] 6104 	inc	r0
      001DC5 36               [12] 6105 	addc	a, @r0
      001DC6 FB               [12] 6106 	mov	r3,a
      001DC7 08               [12] 6107 	inc	r0
      001DC8 86 07            [24] 6108 	mov	ar7,@r0
      001DCA 74 03            [12] 6109 	mov	a,#0x03
      001DCC 2A               [12] 6110 	add	a, r2
      001DCD FA               [12] 6111 	mov	r2,a
      001DCE E4               [12] 6112 	clr	a
      001DCF 3B               [12] 6113 	addc	a, r3
      001DD0 FB               [12] 6114 	mov	r3,a
      001DD1 8A 82            [24] 6115 	mov	dpl,r2
      001DD3 8B 83            [24] 6116 	mov	dph,r3
      001DD5 8F F0            [24] 6117 	mov	b,r7
      001DD7 12 29 94         [24] 6118 	lcall	__gptrget
      001DDA FA               [12] 6119 	mov	r2,a
      001DDB A3               [24] 6120 	inc	dptr
      001DDC 12 29 94         [24] 6121 	lcall	__gptrget
      001DDF FB               [12] 6122 	mov	r3,a
      001DE0 A3               [24] 6123 	inc	dptr
      001DE1 12 29 94         [24] 6124 	lcall	__gptrget
      001DE4 FF               [12] 6125 	mov	r7,a
      001DE5 A3               [24] 6126 	inc	dptr
      001DE6 12 29 94         [24] 6127 	lcall	__gptrget
      001DE9 FE               [12] 6128 	mov	r6,a
                           001D33  6129 	C$fuzzy.h$2216$5_0$101 ==.
                                   6130 ;	../../fuzzy.h:2216: implication_method,
      001DEA E5 08            [12] 6131 	mov	a,_bp
      001DEC 24 30            [12] 6132 	add	a,#0x30
      001DEE F8               [12] 6133 	mov	r0,a
      001DEF E6               [12] 6134 	mov	a,@r0
      001DF0 C0 E0            [24] 6135 	push	acc
      001DF2 08               [12] 6136 	inc	r0
      001DF3 E6               [12] 6137 	mov	a,@r0
      001DF4 C0 E0            [24] 6138 	push	acc
      001DF6 08               [12] 6139 	inc	r0
      001DF7 E6               [12] 6140 	mov	a,@r0
      001DF8 C0 E0            [24] 6141 	push	acc
      001DFA 08               [12] 6142 	inc	r0
      001DFB E6               [12] 6143 	mov	a,@r0
      001DFC C0 E0            [24] 6144 	push	acc
      001DFE C0 02            [24] 6145 	push	ar2
      001E00 C0 03            [24] 6146 	push	ar3
      001E02 C0 07            [24] 6147 	push	ar7
      001E04 C0 06            [24] 6148 	push	ar6
      001E06 E5 08            [12] 6149 	mov	a,_bp
      001E08 24 F0            [12] 6150 	add	a,#0xf0
      001E0A F8               [12] 6151 	mov	r0,a
      001E0B 86 82            [24] 6152 	mov	dpl, @r0
      001E0D 12 18 D1         [24] 6153 	lcall	_fuzzy_implication
      001E10 AC 82            [24] 6154 	mov	r4, dpl
      001E12 AD 83            [24] 6155 	mov	r5, dph
      001E14 AE F0            [24] 6156 	mov	r6, b
      001E16 FF               [12] 6157 	mov	r7, a
      001E17 E5 81            [12] 6158 	mov	a,sp
      001E19 24 F8            [12] 6159 	add	a,#0xf8
      001E1B F5 81            [12] 6160 	mov	sp,a
                           001D66  6161 	C$fuzzy.h$2222$5_0$101 ==.
                                   6162 ;	../../fuzzy.h:2222: aggregation_method,
      001E1D C0 04            [24] 6163 	push	ar4
      001E1F C0 05            [24] 6164 	push	ar5
      001E21 C0 06            [24] 6165 	push	ar6
      001E23 C0 07            [24] 6166 	push	ar7
      001E25 E5 08            [12] 6167 	mov	a,_bp
      001E27 24 07            [12] 6168 	add	a,#0x07
      001E29 F8               [12] 6169 	mov	r0,a
      001E2A E6               [12] 6170 	mov	a,@r0
      001E2B C0 E0            [24] 6171 	push	acc
      001E2D 08               [12] 6172 	inc	r0
      001E2E E6               [12] 6173 	mov	a,@r0
      001E2F C0 E0            [24] 6174 	push	acc
      001E31 08               [12] 6175 	inc	r0
      001E32 E6               [12] 6176 	mov	a,@r0
      001E33 C0 E0            [24] 6177 	push	acc
      001E35 08               [12] 6178 	inc	r0
      001E36 E6               [12] 6179 	mov	a,@r0
      001E37 C0 E0            [24] 6180 	push	acc
      001E39 E5 08            [12] 6181 	mov	a,_bp
      001E3B 24 EF            [12] 6182 	add	a,#0xef
      001E3D F8               [12] 6183 	mov	r0,a
      001E3E 86 82            [24] 6184 	mov	dpl, @r0
      001E40 12 19 E4         [24] 6185 	lcall	_fuzzy_aggregation
      001E43 C8               [12] 6186 	xch	a,r0
      001E44 E5 08            [12] 6187 	mov	a,_bp
      001E46 24 07            [12] 6188 	add	a,#0x07
      001E48 C8               [12] 6189 	xch	a,r0
      001E49 A6 82            [24] 6190 	mov	@r0, dpl
      001E4B 08               [12] 6191 	inc	r0
      001E4C A6 83            [24] 6192 	mov	@r0, dph
      001E4E 08               [12] 6193 	inc	r0
      001E4F A6 F0            [24] 6194 	mov	@r0, b
      001E51 08               [12] 6195 	inc	r0
      001E52 F6               [12] 6196 	mov	@r0,a
      001E53 E5 81            [12] 6197 	mov	a,sp
      001E55 24 F8            [12] 6198 	add	a,#0xf8
      001E57 F5 81            [12] 6199 	mov	sp,a
                           001DA2  6200 	C$fuzzy.h$2209$1_0$96 ==.
                                   6201 ;	../../fuzzy.h:2209: index++
      001E59 E5 08            [12] 6202 	mov	a,_bp
      001E5B 24 0B            [12] 6203 	add	a,#0x0b
      001E5D F8               [12] 6204 	mov	r0,a
      001E5E 74 09            [12] 6205 	mov	a,#0x09
      001E60 26               [12] 6206 	add	a, @r0
      001E61 F6               [12] 6207 	mov	@r0,a
      001E62 E4               [12] 6208 	clr	a
      001E63 08               [12] 6209 	inc	r0
      001E64 36               [12] 6210 	addc	a, @r0
      001E65 F6               [12] 6211 	mov	@r0,a
      001E66 E5 08            [12] 6212 	mov	a,_bp
      001E68 24 36            [12] 6213 	add	a,#0x36
      001E6A F8               [12] 6214 	mov	r0,a
      001E6B 06               [12] 6215 	inc	@r0
      001E6C B6 00 02         [24] 6216 	cjne	@r0,#0x00,00225$
      001E6F 08               [12] 6217 	inc	r0
      001E70 06               [12] 6218 	inc	@r0
      001E71                       6219 00225$:
      001E71 02 1D 3A         [24] 6220 	ljmp	00125$
      001E74                       6221 00106$:
                           001DBD  6222 	C$fuzzy.h$2229$3_0$99 ==.
                                   6223 ;	../../fuzzy.h:2229: aggregated_height
      001E74 E5 08            [12] 6224 	mov	a,_bp
      001E76 24 07            [12] 6225 	add	a,#0x07
      001E78 F8               [12] 6226 	mov	r0,a
      001E79 86 82            [24] 6227 	mov	dpl, @r0
      001E7B 08               [12] 6228 	inc	r0
      001E7C 86 83            [24] 6229 	mov	dph, @r0
      001E7E 08               [12] 6230 	inc	r0
      001E7F 86 F0            [24] 6231 	mov	b, @r0
      001E81 08               [12] 6232 	inc	r0
      001E82 E6               [12] 6233 	mov	a, @r0
      001E83 12 00 EA         [24] 6234 	lcall	_fuzzy_clamp
      001E86 C8               [12] 6235 	xch	a,r0
      001E87 E5 08            [12] 6236 	mov	a,_bp
      001E89 24 2C            [12] 6237 	add	a,#0x2c
      001E8B C8               [12] 6238 	xch	a,r0
      001E8C A6 82            [24] 6239 	mov	@r0, dpl
      001E8E 08               [12] 6240 	inc	r0
      001E8F A6 83            [24] 6241 	mov	@r0, dph
      001E91 08               [12] 6242 	inc	r0
      001E92 A6 F0            [24] 6243 	mov	@r0, b
      001E94 08               [12] 6244 	inc	r0
      001E95 F6               [12] 6245 	mov	@r0,a
                           001DDF  6246 	C$fuzzy.h$2234$1_0$96 ==.
                                   6247 ;	../../fuzzy.h:2234: aggregated_height;
      001E96 E5 08            [12] 6248 	mov	a,_bp
      001E98 24 2C            [12] 6249 	add	a,#0x2c
      001E9A F8               [12] 6250 	mov	r0,a
      001E9B E6               [12] 6251 	mov	a,@r0
      001E9C C0 E0            [24] 6252 	push	acc
      001E9E 08               [12] 6253 	inc	r0
      001E9F E6               [12] 6254 	mov	a,@r0
      001EA0 C0 E0            [24] 6255 	push	acc
      001EA2 08               [12] 6256 	inc	r0
      001EA3 E6               [12] 6257 	mov	a,@r0
      001EA4 C0 E0            [24] 6258 	push	acc
      001EA6 08               [12] 6259 	inc	r0
      001EA7 E6               [12] 6260 	mov	a,@r0
      001EA8 C0 E0            [24] 6261 	push	acc
      001EAA E5 08            [12] 6262 	mov	a,_bp
      001EAC 24 28            [12] 6263 	add	a,#0x28
      001EAE F8               [12] 6264 	mov	r0,a
      001EAF 86 82            [24] 6265 	mov	dpl, @r0
      001EB1 08               [12] 6266 	inc	r0
      001EB2 86 83            [24] 6267 	mov	dph, @r0
      001EB4 08               [12] 6268 	inc	r0
      001EB5 86 F0            [24] 6269 	mov	b, @r0
      001EB7 08               [12] 6270 	inc	r0
      001EB8 E6               [12] 6271 	mov	a, @r0
      001EB9 12 26 38         [24] 6272 	lcall	___fsmul
      001EBC AA 82            [24] 6273 	mov	r2, dpl
      001EBE AB 83            [24] 6274 	mov	r3, dph
      001EC0 AE F0            [24] 6275 	mov	r6, b
      001EC2 FF               [12] 6276 	mov	r7, a
      001EC3 E5 81            [12] 6277 	mov	a,sp
      001EC5 24 FC            [12] 6278 	add	a,#0xfc
      001EC7 F5 81            [12] 6279 	mov	sp,a
      001EC9 C0 02            [24] 6280 	push	ar2
      001ECB C0 03            [24] 6281 	push	ar3
      001ECD C0 06            [24] 6282 	push	ar6
      001ECF C0 07            [24] 6283 	push	ar7
                           001E1A  6284 	C$fuzzy.h$2237$1_0$96 ==.
                                   6285 ;	../../fuzzy.h:2237: aggregated_height;
      001ED1 E5 08            [12] 6286 	mov	a,_bp
      001ED3 24 10            [12] 6287 	add	a,#0x10
      001ED5 F8               [12] 6288 	mov	r0,a
      001ED6 86 82            [24] 6289 	mov	dpl, @r0
      001ED8 08               [12] 6290 	inc	r0
      001ED9 86 83            [24] 6291 	mov	dph, @r0
      001EDB 08               [12] 6292 	inc	r0
      001EDC 86 F0            [24] 6293 	mov	b, @r0
      001EDE 08               [12] 6294 	inc	r0
      001EDF E6               [12] 6295 	mov	a, @r0
      001EE0 12 27 BA         [24] 6296 	lcall	___fsadd
      001EE3 C8               [12] 6297 	xch	a,r0
      001EE4 E5 08            [12] 6298 	mov	a,_bp
      001EE6 24 10            [12] 6299 	add	a,#0x10
      001EE8 C8               [12] 6300 	xch	a,r0
      001EE9 A6 82            [24] 6301 	mov	@r0, dpl
      001EEB 08               [12] 6302 	inc	r0
      001EEC A6 83            [24] 6303 	mov	@r0, dph
      001EEE 08               [12] 6304 	inc	r0
      001EEF A6 F0            [24] 6305 	mov	@r0, b
      001EF1 08               [12] 6306 	inc	r0
      001EF2 F6               [12] 6307 	mov	@r0,a
      001EF3 E5 81            [12] 6308 	mov	a,sp
      001EF5 24 FC            [12] 6309 	add	a,#0xfc
      001EF7 F5 81            [12] 6310 	mov	sp,a
      001EF9 E5 08            [12] 6311 	mov	a,_bp
      001EFB 24 2C            [12] 6312 	add	a,#0x2c
      001EFD F8               [12] 6313 	mov	r0,a
      001EFE E6               [12] 6314 	mov	a,@r0
      001EFF C0 E0            [24] 6315 	push	acc
      001F01 08               [12] 6316 	inc	r0
      001F02 E6               [12] 6317 	mov	a,@r0
      001F03 C0 E0            [24] 6318 	push	acc
      001F05 08               [12] 6319 	inc	r0
      001F06 E6               [12] 6320 	mov	a,@r0
      001F07 C0 E0            [24] 6321 	push	acc
      001F09 08               [12] 6322 	inc	r0
      001F0A E6               [12] 6323 	mov	a,@r0
      001F0B C0 E0            [24] 6324 	push	acc
                           001E56  6325 	C$fuzzy.h$2240$1_0$96 ==.
                                   6326 ;	../../fuzzy.h:2240: !maximum_found ||
      001F0D E5 08            [12] 6327 	mov	a,_bp
      001F0F 24 14            [12] 6328 	add	a,#0x14
      001F11 F8               [12] 6329 	mov	r0,a
      001F12 86 82            [24] 6330 	mov	dpl, @r0
      001F14 08               [12] 6331 	inc	r0
      001F15 86 83            [24] 6332 	mov	dph, @r0
      001F17 08               [12] 6333 	inc	r0
      001F18 86 F0            [24] 6334 	mov	b, @r0
      001F1A 08               [12] 6335 	inc	r0
      001F1B E6               [12] 6336 	mov	a, @r0
      001F1C 12 27 BA         [24] 6337 	lcall	___fsadd
      001F1F C8               [12] 6338 	xch	a,r0
      001F20 E5 08            [12] 6339 	mov	a,_bp
      001F22 24 14            [12] 6340 	add	a,#0x14
      001F24 C8               [12] 6341 	xch	a,r0
      001F25 A6 82            [24] 6342 	mov	@r0, dpl
      001F27 08               [12] 6343 	inc	r0
      001F28 A6 83            [24] 6344 	mov	@r0, dph
      001F2A 08               [12] 6345 	inc	r0
      001F2B A6 F0            [24] 6346 	mov	@r0, b
      001F2D 08               [12] 6347 	inc	r0
      001F2E F6               [12] 6348 	mov	@r0,a
      001F2F E5 81            [12] 6349 	mov	a,sp
      001F31 24 FC            [12] 6350 	add	a,#0xfc
      001F33 F5 81            [12] 6351 	mov	sp,a
      001F35 E5 08            [12] 6352 	mov	a,_bp
      001F37 24 38            [12] 6353 	add	a,#0x38
      001F39 F8               [12] 6354 	mov	r0,a
      001F3A E6               [12] 6355 	mov	a,@r0
      001F3B 60 31            [24] 6356 	jz	00109$
                           001E86  6357 	C$fuzzy.h$2242$1_0$96 ==.
                                   6358 ;	../../fuzzy.h:2242: ) {
      001F3D E5 08            [12] 6359 	mov	a,_bp
      001F3F 24 2C            [12] 6360 	add	a,#0x2c
      001F41 F8               [12] 6361 	mov	r0,a
      001F42 E6               [12] 6362 	mov	a,@r0
      001F43 C0 E0            [24] 6363 	push	acc
      001F45 08               [12] 6364 	inc	r0
      001F46 E6               [12] 6365 	mov	a,@r0
      001F47 C0 E0            [24] 6366 	push	acc
      001F49 08               [12] 6367 	inc	r0
      001F4A E6               [12] 6368 	mov	a,@r0
      001F4B C0 E0            [24] 6369 	push	acc
      001F4D 08               [12] 6370 	inc	r0
      001F4E E6               [12] 6371 	mov	a,@r0
      001F4F C0 E0            [24] 6372 	push	acc
      001F51 E5 08            [12] 6373 	mov	a,_bp
      001F53 24 18            [12] 6374 	add	a,#0x18
      001F55 F8               [12] 6375 	mov	r0,a
      001F56 86 82            [24] 6376 	mov	dpl, @r0
      001F58 08               [12] 6377 	inc	r0
      001F59 86 83            [24] 6378 	mov	dph, @r0
      001F5B 08               [12] 6379 	inc	r0
      001F5C 86 F0            [24] 6380 	mov	b, @r0
      001F5E 08               [12] 6381 	inc	r0
      001F5F E6               [12] 6382 	mov	a, @r0
      001F60 12 27 68         [24] 6383 	lcall	___fslt
      001F63 AF 82            [24] 6384 	mov	r7, dpl
      001F65 E5 81            [12] 6385 	mov	a,sp
      001F67 24 FC            [12] 6386 	add	a,#0xfc
      001F69 F5 81            [12] 6387 	mov	sp,a
      001F6B EF               [12] 6388 	mov	a,r7
      001F6C 60 74            [24] 6389 	jz	00110$
      001F6E                       6390 00109$:
                           001EB7  6391 	C$fuzzy.h$2243$4_0$102 ==.
                                   6392 ;	../../fuzzy.h:2243: maximum_height = aggregated_height;
      001F6E E5 08            [12] 6393 	mov	a,_bp
      001F70 24 2C            [12] 6394 	add	a,#0x2c
      001F72 F8               [12] 6395 	mov	r0,a
      001F73 E5 08            [12] 6396 	mov	a,_bp
      001F75 24 18            [12] 6397 	add	a,#0x18
      001F77 F9               [12] 6398 	mov	r1,a
      001F78 E6               [12] 6399 	mov	a,@r0
      001F79 F7               [12] 6400 	mov	@r1,a
      001F7A 08               [12] 6401 	inc	r0
      001F7B E6               [12] 6402 	mov	a,@r0
      001F7C 09               [12] 6403 	inc	r1
      001F7D F7               [12] 6404 	mov	@r1,a
      001F7E 08               [12] 6405 	inc	r0
      001F7F E6               [12] 6406 	mov	a,@r0
      001F80 09               [12] 6407 	inc	r1
      001F81 F7               [12] 6408 	mov	@r1,a
      001F82 08               [12] 6409 	inc	r0
      001F83 E6               [12] 6410 	mov	a,@r0
      001F84 09               [12] 6411 	inc	r1
      001F85 F7               [12] 6412 	mov	@r1,a
                           001ECF  6413 	C$fuzzy.h$2244$4_0$102 ==.
                                   6414 ;	../../fuzzy.h:2244: smallest_maximum = value;
      001F86 E5 08            [12] 6415 	mov	a,_bp
      001F88 24 28            [12] 6416 	add	a,#0x28
      001F8A F8               [12] 6417 	mov	r0,a
      001F8B E5 08            [12] 6418 	mov	a,_bp
      001F8D 24 20            [12] 6419 	add	a,#0x20
      001F8F F9               [12] 6420 	mov	r1,a
      001F90 E6               [12] 6421 	mov	a,@r0
      001F91 F7               [12] 6422 	mov	@r1,a
      001F92 08               [12] 6423 	inc	r0
      001F93 E6               [12] 6424 	mov	a,@r0
      001F94 09               [12] 6425 	inc	r1
      001F95 F7               [12] 6426 	mov	@r1,a
      001F96 08               [12] 6427 	inc	r0
      001F97 E6               [12] 6428 	mov	a,@r0
      001F98 09               [12] 6429 	inc	r1
      001F99 F7               [12] 6430 	mov	@r1,a
      001F9A 08               [12] 6431 	inc	r0
      001F9B E6               [12] 6432 	mov	a,@r0
      001F9C 09               [12] 6433 	inc	r1
      001F9D F7               [12] 6434 	mov	@r1,a
                           001EE7  6435 	C$fuzzy.h$2245$4_0$102 ==.
                                   6436 ;	../../fuzzy.h:2245: largest_maximum = value;
      001F9E E5 08            [12] 6437 	mov	a,_bp
      001FA0 24 28            [12] 6438 	add	a,#0x28
      001FA2 F8               [12] 6439 	mov	r0,a
      001FA3 E5 08            [12] 6440 	mov	a,_bp
      001FA5 24 24            [12] 6441 	add	a,#0x24
      001FA7 F9               [12] 6442 	mov	r1,a
      001FA8 E6               [12] 6443 	mov	a,@r0
      001FA9 F7               [12] 6444 	mov	@r1,a
      001FAA 08               [12] 6445 	inc	r0
      001FAB E6               [12] 6446 	mov	a,@r0
      001FAC 09               [12] 6447 	inc	r1
      001FAD F7               [12] 6448 	mov	@r1,a
      001FAE 08               [12] 6449 	inc	r0
      001FAF E6               [12] 6450 	mov	a,@r0
      001FB0 09               [12] 6451 	inc	r1
      001FB1 F7               [12] 6452 	mov	@r1,a
      001FB2 08               [12] 6453 	inc	r0
      001FB3 E6               [12] 6454 	mov	a,@r0
      001FB4 09               [12] 6455 	inc	r1
      001FB5 F7               [12] 6456 	mov	@r1,a
                           001EFF  6457 	C$fuzzy.h$2246$4_0$102 ==.
                                   6458 ;	../../fuzzy.h:2246: maximum_position_sum = value;
      001FB6 E5 08            [12] 6459 	mov	a,_bp
      001FB8 24 28            [12] 6460 	add	a,#0x28
      001FBA F8               [12] 6461 	mov	r0,a
      001FBB E5 08            [12] 6462 	mov	a,_bp
      001FBD 24 1C            [12] 6463 	add	a,#0x1c
      001FBF F9               [12] 6464 	mov	r1,a
      001FC0 E6               [12] 6465 	mov	a,@r0
      001FC1 F7               [12] 6466 	mov	@r1,a
      001FC2 08               [12] 6467 	inc	r0
      001FC3 E6               [12] 6468 	mov	a,@r0
      001FC4 09               [12] 6469 	inc	r1
      001FC5 F7               [12] 6470 	mov	@r1,a
      001FC6 08               [12] 6471 	inc	r0
      001FC7 E6               [12] 6472 	mov	a,@r0
      001FC8 09               [12] 6473 	inc	r1
      001FC9 F7               [12] 6474 	mov	@r1,a
      001FCA 08               [12] 6475 	inc	r0
      001FCB E6               [12] 6476 	mov	a,@r0
      001FCC 09               [12] 6477 	inc	r1
      001FCD F7               [12] 6478 	mov	@r1,a
                           001F17  6479 	C$fuzzy.h$2247$4_0$102 ==.
                                   6480 ;	../../fuzzy.h:2247: maximum_count = 1u;
      001FCE E5 08            [12] 6481 	mov	a,_bp
      001FD0 24 34            [12] 6482 	add	a,#0x34
      001FD2 F8               [12] 6483 	mov	r0,a
      001FD3 76 01            [12] 6484 	mov	@r0,#0x01
      001FD5 08               [12] 6485 	inc	r0
      001FD6 76 00            [12] 6486 	mov	@r0,#0x00
                           001F21  6487 	C$fuzzy.h$2248$4_0$102 ==.
                                   6488 ;	../../fuzzy.h:2248: maximum_found = true;
      001FD8 E5 08            [12] 6489 	mov	a,_bp
      001FDA 24 38            [12] 6490 	add	a,#0x38
      001FDC F8               [12] 6491 	mov	r0,a
      001FDD 76 01            [12] 6492 	mov	@r0,#0x01
      001FDF 02 20 72         [24] 6493 	ljmp	00129$
      001FE2                       6494 00110$:
                           001F2B  6495 	C$fuzzy.h$2250$1_0$96 ==.
                                   6496 ;	../../fuzzy.h:2250: else if (aggregated_height == maximum_height) {
      001FE2 E5 08            [12] 6497 	mov	a,_bp
      001FE4 24 18            [12] 6498 	add	a,#0x18
      001FE6 F8               [12] 6499 	mov	r0,a
      001FE7 E6               [12] 6500 	mov	a,@r0
      001FE8 C0 E0            [24] 6501 	push	acc
      001FEA 08               [12] 6502 	inc	r0
      001FEB E6               [12] 6503 	mov	a,@r0
      001FEC C0 E0            [24] 6504 	push	acc
      001FEE 08               [12] 6505 	inc	r0
      001FEF E6               [12] 6506 	mov	a,@r0
      001FF0 C0 E0            [24] 6507 	push	acc
      001FF2 08               [12] 6508 	inc	r0
      001FF3 E6               [12] 6509 	mov	a,@r0
      001FF4 C0 E0            [24] 6510 	push	acc
      001FF6 E5 08            [12] 6511 	mov	a,_bp
      001FF8 24 2C            [12] 6512 	add	a,#0x2c
      001FFA F8               [12] 6513 	mov	r0,a
      001FFB 86 82            [24] 6514 	mov	dpl, @r0
      001FFD 08               [12] 6515 	inc	r0
      001FFE 86 83            [24] 6516 	mov	dph, @r0
      002000 08               [12] 6517 	inc	r0
      002001 86 F0            [24] 6518 	mov	b, @r0
      002003 08               [12] 6519 	inc	r0
      002004 E6               [12] 6520 	mov	a, @r0
      002005 12 27 3C         [24] 6521 	lcall	___fseq
      002008 AF 82            [24] 6522 	mov	r7, dpl
      00200A E5 81            [12] 6523 	mov	a,sp
      00200C 24 FC            [12] 6524 	add	a,#0xfc
      00200E F5 81            [12] 6525 	mov	sp,a
      002010 EF               [12] 6526 	mov	a,r7
      002011 60 5F            [24] 6527 	jz	00129$
                           001F5C  6528 	C$fuzzy.h$2251$4_0$103 ==.
                                   6529 ;	../../fuzzy.h:2251: largest_maximum = value;
      002013 E5 08            [12] 6530 	mov	a,_bp
      002015 24 28            [12] 6531 	add	a,#0x28
      002017 F8               [12] 6532 	mov	r0,a
      002018 E5 08            [12] 6533 	mov	a,_bp
      00201A 24 24            [12] 6534 	add	a,#0x24
      00201C F9               [12] 6535 	mov	r1,a
      00201D E6               [12] 6536 	mov	a,@r0
      00201E F7               [12] 6537 	mov	@r1,a
      00201F 08               [12] 6538 	inc	r0
      002020 E6               [12] 6539 	mov	a,@r0
      002021 09               [12] 6540 	inc	r1
      002022 F7               [12] 6541 	mov	@r1,a
      002023 08               [12] 6542 	inc	r0
      002024 E6               [12] 6543 	mov	a,@r0
      002025 09               [12] 6544 	inc	r1
      002026 F7               [12] 6545 	mov	@r1,a
      002027 08               [12] 6546 	inc	r0
      002028 E6               [12] 6547 	mov	a,@r0
      002029 09               [12] 6548 	inc	r1
      00202A F7               [12] 6549 	mov	@r1,a
                           001F74  6550 	C$fuzzy.h$2252$1_0$96 ==.
                                   6551 ;	../../fuzzy.h:2252: maximum_position_sum += value;
      00202B E5 08            [12] 6552 	mov	a,_bp
      00202D 24 28            [12] 6553 	add	a,#0x28
      00202F F8               [12] 6554 	mov	r0,a
      002030 E6               [12] 6555 	mov	a,@r0
      002031 C0 E0            [24] 6556 	push	acc
      002033 08               [12] 6557 	inc	r0
      002034 E6               [12] 6558 	mov	a,@r0
      002035 C0 E0            [24] 6559 	push	acc
      002037 08               [12] 6560 	inc	r0
      002038 E6               [12] 6561 	mov	a,@r0
      002039 C0 E0            [24] 6562 	push	acc
      00203B 08               [12] 6563 	inc	r0
      00203C E6               [12] 6564 	mov	a,@r0
      00203D C0 E0            [24] 6565 	push	acc
                           001F88  6566 	C$fuzzy.h$2253$1_0$96 ==.
                                   6567 ;	../../fuzzy.h:2253: maximum_count++;
      00203F E5 08            [12] 6568 	mov	a,_bp
      002041 24 1C            [12] 6569 	add	a,#0x1c
      002043 F8               [12] 6570 	mov	r0,a
      002044 86 82            [24] 6571 	mov	dpl, @r0
      002046 08               [12] 6572 	inc	r0
      002047 86 83            [24] 6573 	mov	dph, @r0
      002049 08               [12] 6574 	inc	r0
      00204A 86 F0            [24] 6575 	mov	b, @r0
      00204C 08               [12] 6576 	inc	r0
      00204D E6               [12] 6577 	mov	a, @r0
      00204E 12 27 BA         [24] 6578 	lcall	___fsadd
      002051 C8               [12] 6579 	xch	a,r0
      002052 E5 08            [12] 6580 	mov	a,_bp
      002054 24 1C            [12] 6581 	add	a,#0x1c
      002056 C8               [12] 6582 	xch	a,r0
      002057 A6 82            [24] 6583 	mov	@r0, dpl
      002059 08               [12] 6584 	inc	r0
      00205A A6 83            [24] 6585 	mov	@r0, dph
      00205C 08               [12] 6586 	inc	r0
      00205D A6 F0            [24] 6587 	mov	@r0, b
      00205F 08               [12] 6588 	inc	r0
      002060 F6               [12] 6589 	mov	@r0,a
      002061 E5 81            [12] 6590 	mov	a,sp
      002063 24 FC            [12] 6591 	add	a,#0xfc
      002065 F5 81            [12] 6592 	mov	sp,a
      002067 E5 08            [12] 6593 	mov	a,_bp
      002069 24 34            [12] 6594 	add	a,#0x34
      00206B F8               [12] 6595 	mov	r0,a
      00206C 06               [12] 6596 	inc	@r0
      00206D B6 00 02         [24] 6597 	cjne	@r0,#0x00,00229$
      002070 08               [12] 6598 	inc	r0
      002071 06               [12] 6599 	inc	@r0
      002072                       6600 00229$:
      002072                       6601 00129$:
                           001FBB  6602 	C$fuzzy.h$2203$1_0$96 ==.
                                   6603 ;	../../fuzzy.h:2203: ) {
      002072 E5 08            [12] 6604 	mov	a,_bp
      002074 24 F2            [12] 6605 	add	a,#0xf2
      002076 F8               [12] 6606 	mov	r0,a
      002077 E6               [12] 6607 	mov	a,@r0
      002078 C0 E0            [24] 6608 	push	acc
      00207A 08               [12] 6609 	inc	r0
      00207B E6               [12] 6610 	mov	a,@r0
      00207C C0 E0            [24] 6611 	push	acc
      00207E 08               [12] 6612 	inc	r0
      00207F E6               [12] 6613 	mov	a,@r0
      002080 C0 E0            [24] 6614 	push	acc
      002082 08               [12] 6615 	inc	r0
      002083 E6               [12] 6616 	mov	a,@r0
      002084 C0 E0            [24] 6617 	push	acc
      002086 E5 08            [12] 6618 	mov	a,_bp
      002088 24 28            [12] 6619 	add	a,#0x28
      00208A F8               [12] 6620 	mov	r0,a
      00208B 86 82            [24] 6621 	mov	dpl, @r0
      00208D 08               [12] 6622 	inc	r0
      00208E 86 83            [24] 6623 	mov	dph, @r0
      002090 08               [12] 6624 	inc	r0
      002091 86 F0            [24] 6625 	mov	b, @r0
      002093 08               [12] 6626 	inc	r0
      002094 E6               [12] 6627 	mov	a, @r0
      002095 12 27 BA         [24] 6628 	lcall	___fsadd
      002098 C8               [12] 6629 	xch	a,r0
      002099 E5 08            [12] 6630 	mov	a,_bp
      00209B 24 28            [12] 6631 	add	a,#0x28
      00209D C8               [12] 6632 	xch	a,r0
      00209E A6 82            [24] 6633 	mov	@r0, dpl
      0020A0 08               [12] 6634 	inc	r0
      0020A1 A6 83            [24] 6635 	mov	@r0, dph
      0020A3 08               [12] 6636 	inc	r0
      0020A4 A6 F0            [24] 6637 	mov	@r0, b
      0020A6 08               [12] 6638 	inc	r0
      0020A7 F6               [12] 6639 	mov	@r0,a
      0020A8 E5 81            [12] 6640 	mov	a,sp
      0020AA 24 FC            [12] 6641 	add	a,#0xfc
      0020AC F5 81            [12] 6642 	mov	sp,a
      0020AE 02 1C E4         [24] 6643 	ljmp	00128$
      0020B1                       6644 00113$:
                           001FFA  6645 	C$fuzzy.h$2258$1_0$96 ==.
                                   6646 ;	../../fuzzy.h:2258: !maximum_found ||
      0020B1 E5 08            [12] 6647 	mov	a,_bp
      0020B3 24 38            [12] 6648 	add	a,#0x38
      0020B5 F8               [12] 6649 	mov	r0,a
      0020B6 E6               [12] 6650 	mov	a,@r0
      0020B7 60 56            [24] 6651 	jz	00114$
                           002002  6652 	C$fuzzy.h$2259$1_0$96 ==.
                                   6653 ;	../../fuzzy.h:2259: maximum_height <= LEVEL_LO ||
      0020B9 E5 08            [12] 6654 	mov	a,_bp
      0020BB 24 18            [12] 6655 	add	a,#0x18
      0020BD F8               [12] 6656 	mov	r0,a
      0020BE E6               [12] 6657 	mov	a,@r0
      0020BF C0 E0            [24] 6658 	push	acc
      0020C1 08               [12] 6659 	inc	r0
      0020C2 E6               [12] 6660 	mov	a,@r0
      0020C3 C0 E0            [24] 6661 	push	acc
      0020C5 08               [12] 6662 	inc	r0
      0020C6 E6               [12] 6663 	mov	a,@r0
      0020C7 C0 E0            [24] 6664 	push	acc
      0020C9 08               [12] 6665 	inc	r0
      0020CA E6               [12] 6666 	mov	a,@r0
      0020CB C0 E0            [24] 6667 	push	acc
      0020CD 90 00 00         [24] 6668 	mov	dptr,#0x0000
      0020D0 E4               [12] 6669 	clr	a
      0020D1 F5 F0            [12] 6670 	mov	b,a
      0020D3 12 27 68         [24] 6671 	lcall	___fslt
      0020D6 E5 81            [12] 6672 	mov	a,sp
      0020D8 24 FC            [12] 6673 	add	a,#0xfc
      0020DA F5 81            [12] 6674 	mov	sp,a
      0020DC E5 82            [12] 6675 	mov	a, dpl
      0020DE 24 FF            [12] 6676 	add	a,#0xff
      0020E0 92 00            [24] 6677 	mov	b0,c
      0020E2 50 2B            [24] 6678 	jnc	00114$
                           00202D  6679 	C$fuzzy.h$2261$1_0$96 ==.
                                   6680 ;	../../fuzzy.h:2261: ) {
      0020E4 E5 08            [12] 6681 	mov	a,_bp
      0020E6 24 14            [12] 6682 	add	a,#0x14
      0020E8 F8               [12] 6683 	mov	r0,a
      0020E9 E6               [12] 6684 	mov	a,@r0
      0020EA C0 E0            [24] 6685 	push	acc
      0020EC 08               [12] 6686 	inc	r0
      0020ED E6               [12] 6687 	mov	a,@r0
      0020EE C0 E0            [24] 6688 	push	acc
      0020F0 08               [12] 6689 	inc	r0
      0020F1 E6               [12] 6690 	mov	a,@r0
      0020F2 C0 E0            [24] 6691 	push	acc
      0020F4 08               [12] 6692 	inc	r0
      0020F5 E6               [12] 6693 	mov	a,@r0
      0020F6 C0 E0            [24] 6694 	push	acc
      0020F8 90 00 00         [24] 6695 	mov	dptr,#0x0000
      0020FB E4               [12] 6696 	clr	a
      0020FC F5 F0            [12] 6697 	mov	b,a
      0020FE 12 27 68         [24] 6698 	lcall	___fslt
      002101 E5 81            [12] 6699 	mov	a,sp
      002103 24 FC            [12] 6700 	add	a,#0xfc
      002105 F5 81            [12] 6701 	mov	sp,a
      002107 E5 82            [12] 6702 	mov	a, dpl
      002109 24 FF            [12] 6703 	add	a,#0xff
      00210B 92 00            [24] 6704 	mov	b0,c
      00210D 40 09            [24] 6705 	jc	00115$
      00210F                       6706 00114$:
                           002058  6707 	C$fuzzy.h$2262$2_0$104 ==.
                                   6708 ;	../../fuzzy.h:2262: return 0.0f;
      00210F 90 00 00         [24] 6709 	mov	dptr,#0x0000
      002112 E4               [12] 6710 	clr	a
      002113 F5 F0            [12] 6711 	mov	b,a
      002115 02 21 E5         [24] 6712 	ljmp	00130$
      002118                       6713 00115$:
                           002061  6714 	C$fuzzy.h$2265$1_0$96 ==.
                                   6715 ;	../../fuzzy.h:2265: switch (defuzz_method) {
      002118 E5 08            [12] 6716 	mov	a,_bp
      00211A 24 F1            [12] 6717 	add	a,#0xf1
      00211C F8               [12] 6718 	mov	r0,a
      00211D E6               [12] 6719 	mov	a,@r0
      00211E 24 FC            [12] 6720 	add	a,#0xff - 0x03
      002120 50 03            [24] 6721 	jnc	00233$
      002122 02 21 DF         [24] 6722 	ljmp	00122$
      002125                       6723 00233$:
      002125 E5 08            [12] 6724 	mov	a,_bp
      002127 24 F1            [12] 6725 	add	a,#0xf1
      002129 F8               [12] 6726 	mov	r0,a
      00212A E6               [12] 6727 	mov	a,@r0
      00212B 26               [12] 6728 	add	a,@r0
      00212C 26               [12] 6729 	add	a,@r0
      00212D 90 21 31         [24] 6730 	mov	dptr,#00234$
      002130 73               [24] 6731 	jmp	@a+dptr
      002131                       6732 00234$:
      002131 02 21 3D         [24] 6733 	ljmp	00118$
      002134 02 21 79         [24] 6734 	ljmp	00119$
      002137 02 21 BD         [24] 6735 	ljmp	00120$
      00213A 02 21 CE         [24] 6736 	ljmp	00121$
                           002086  6737 	C$fuzzy.h$2266$2_0$105 ==.
                                   6738 ;	../../fuzzy.h:2266: case FUZZY_DEFUZZ_COG:
      00213D                       6739 00118$:
                           002086  6740 	C$fuzzy.h$2268$1_0$96 ==.
                                   6741 ;	../../fuzzy.h:2268: height_sum;
      00213D E5 08            [12] 6742 	mov	a,_bp
      00213F 24 14            [12] 6743 	add	a,#0x14
      002141 F8               [12] 6744 	mov	r0,a
      002142 E6               [12] 6745 	mov	a,@r0
      002143 C0 E0            [24] 6746 	push	acc
      002145 08               [12] 6747 	inc	r0
      002146 E6               [12] 6748 	mov	a,@r0
      002147 C0 E0            [24] 6749 	push	acc
      002149 08               [12] 6750 	inc	r0
      00214A E6               [12] 6751 	mov	a,@r0
      00214B C0 E0            [24] 6752 	push	acc
      00214D 08               [12] 6753 	inc	r0
      00214E E6               [12] 6754 	mov	a,@r0
      00214F C0 E0            [24] 6755 	push	acc
      002151 E5 08            [12] 6756 	mov	a,_bp
      002153 24 10            [12] 6757 	add	a,#0x10
      002155 F8               [12] 6758 	mov	r0,a
      002156 86 82            [24] 6759 	mov	dpl, @r0
      002158 08               [12] 6760 	inc	r0
      002159 86 83            [24] 6761 	mov	dph, @r0
      00215B 08               [12] 6762 	inc	r0
      00215C 86 F0            [24] 6763 	mov	b, @r0
      00215E 08               [12] 6764 	inc	r0
      00215F E6               [12] 6765 	mov	a, @r0
      002160 12 28 D1         [24] 6766 	lcall	___fsdiv
      002163 AC 82            [24] 6767 	mov	r4, dpl
      002165 AD 83            [24] 6768 	mov	r5, dph
      002167 AE F0            [24] 6769 	mov	r6, b
      002169 FF               [12] 6770 	mov	r7, a
      00216A E5 81            [12] 6771 	mov	a,sp
      00216C 24 FC            [12] 6772 	add	a,#0xfc
      00216E F5 81            [12] 6773 	mov	sp,a
      002170 8C 82            [24] 6774 	mov	dpl, r4
      002172 8D 83            [24] 6775 	mov	dph, r5
      002174 8E F0            [24] 6776 	mov	b, r6
      002176 EF               [12] 6777 	mov	a, r7
                           0020C0  6778 	C$fuzzy.h$2270$2_0$105 ==.
                                   6779 ;	../../fuzzy.h:2270: case FUZZY_DEFUZZ_MOM:
      002177 80 6C            [24] 6780 	sjmp	00130$
      002179                       6781 00119$:
                           0020C2  6782 	C$fuzzy.h$2272$1_0$96 ==.
                                   6783 ;	../../fuzzy.h:2272: (float)maximum_count;
      002179 E5 08            [12] 6784 	mov	a,_bp
      00217B 24 34            [12] 6785 	add	a,#0x34
      00217D F8               [12] 6786 	mov	r0,a
      00217E 86 82            [24] 6787 	mov	dpl, @r0
      002180 08               [12] 6788 	inc	r0
      002181 86 83            [24] 6789 	mov	dph, @r0
      002183 12 28 5C         [24] 6790 	lcall	___uint2fs
      002186 AC 82            [24] 6791 	mov	r4, dpl
      002188 AD 83            [24] 6792 	mov	r5, dph
      00218A AE F0            [24] 6793 	mov	r6, b
      00218C FF               [12] 6794 	mov	r7, a
      00218D C0 04            [24] 6795 	push	ar4
      00218F C0 05            [24] 6796 	push	ar5
      002191 C0 06            [24] 6797 	push	ar6
      002193 C0 07            [24] 6798 	push	ar7
      002195 E5 08            [12] 6799 	mov	a,_bp
      002197 24 1C            [12] 6800 	add	a,#0x1c
      002199 F8               [12] 6801 	mov	r0,a
      00219A 86 82            [24] 6802 	mov	dpl, @r0
      00219C 08               [12] 6803 	inc	r0
      00219D 86 83            [24] 6804 	mov	dph, @r0
      00219F 08               [12] 6805 	inc	r0
      0021A0 86 F0            [24] 6806 	mov	b, @r0
      0021A2 08               [12] 6807 	inc	r0
      0021A3 E6               [12] 6808 	mov	a, @r0
      0021A4 12 28 D1         [24] 6809 	lcall	___fsdiv
      0021A7 AC 82            [24] 6810 	mov	r4, dpl
      0021A9 AD 83            [24] 6811 	mov	r5, dph
      0021AB AE F0            [24] 6812 	mov	r6, b
      0021AD FF               [12] 6813 	mov	r7, a
      0021AE E5 81            [12] 6814 	mov	a,sp
      0021B0 24 FC            [12] 6815 	add	a,#0xfc
      0021B2 F5 81            [12] 6816 	mov	sp,a
      0021B4 8C 82            [24] 6817 	mov	dpl, r4
      0021B6 8D 83            [24] 6818 	mov	dph, r5
      0021B8 8E F0            [24] 6819 	mov	b, r6
      0021BA EF               [12] 6820 	mov	a, r7
                           002104  6821 	C$fuzzy.h$2274$2_0$105 ==.
                                   6822 ;	../../fuzzy.h:2274: case FUZZY_DEFUZZ_SOM:
      0021BB 80 28            [24] 6823 	sjmp	00130$
      0021BD                       6824 00120$:
                           002106  6825 	C$fuzzy.h$2275$2_0$105 ==.
                                   6826 ;	../../fuzzy.h:2275: return smallest_maximum;
      0021BD E5 08            [12] 6827 	mov	a,_bp
      0021BF 24 20            [12] 6828 	add	a,#0x20
      0021C1 F8               [12] 6829 	mov	r0,a
      0021C2 86 82            [24] 6830 	mov	dpl, @r0
      0021C4 08               [12] 6831 	inc	r0
      0021C5 86 83            [24] 6832 	mov	dph, @r0
      0021C7 08               [12] 6833 	inc	r0
      0021C8 86 F0            [24] 6834 	mov	b, @r0
      0021CA 08               [12] 6835 	inc	r0
      0021CB E6               [12] 6836 	mov	a, @r0
                           002115  6837 	C$fuzzy.h$2277$2_0$105 ==.
                                   6838 ;	../../fuzzy.h:2277: case FUZZY_DEFUZZ_LOM:
      0021CC 80 17            [24] 6839 	sjmp	00130$
      0021CE                       6840 00121$:
                           002117  6841 	C$fuzzy.h$2278$2_0$105 ==.
                                   6842 ;	../../fuzzy.h:2278: return largest_maximum;
      0021CE E5 08            [12] 6843 	mov	a,_bp
      0021D0 24 24            [12] 6844 	add	a,#0x24
      0021D2 F8               [12] 6845 	mov	r0,a
      0021D3 86 82            [24] 6846 	mov	dpl, @r0
      0021D5 08               [12] 6847 	inc	r0
      0021D6 86 83            [24] 6848 	mov	dph, @r0
      0021D8 08               [12] 6849 	inc	r0
      0021D9 86 F0            [24] 6850 	mov	b, @r0
      0021DB 08               [12] 6851 	inc	r0
      0021DC E6               [12] 6852 	mov	a, @r0
                           002126  6853 	C$fuzzy.h$2280$2_0$105 ==.
                                   6854 ;	../../fuzzy.h:2280: default:
      0021DD 80 06            [24] 6855 	sjmp	00130$
      0021DF                       6856 00122$:
                           002128  6857 	C$fuzzy.h$2281$2_0$105 ==.
                                   6858 ;	../../fuzzy.h:2281: return 0.0f;
      0021DF 90 00 00         [24] 6859 	mov	dptr,#0x0000
      0021E2 E4               [12] 6860 	clr	a
      0021E3 F5 F0            [12] 6861 	mov	b,a
                           00212E  6862 	C$fuzzy.h$2282$1_0$96 ==.
                                   6863 ;	../../fuzzy.h:2282: }
      0021E5                       6864 00130$:
                           00212E  6865 	C$fuzzy.h$2283$1_0$96 ==.
                                   6866 ;	../../fuzzy.h:2283: }
      0021E5 85 08 81         [24] 6867 	mov	sp,_bp
      0021E8 D0 08            [24] 6868 	pop	_bp
                           002133  6869 	C$fuzzy.h$2283$1_0$96 ==.
                           002133  6870 	XG$fuzzy_rules_defuzzify_method$0$0 ==.
      0021EA 22               [24] 6871 	ret
                                   6872 ;------------------------------------------------------------
                                   6873 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify'
                                   6874 ;------------------------------------------------------------
                                   6875 ;lower         Allocated to stack - _bp -6 +4 
                                   6876 ;upper         Allocated to stack - _bp -10 +4 
                                   6877 ;step          Allocated to stack - _bp -14 +4 
                                   6878 ;method        Allocated to stack - _bp -15 +1 
                                   6879 ;rules         Allocated to registers r5 r6 r7 
                                   6880 ;------------------------------------------------------------
                           002134  6881 	G$fuzzy_rules_defuzzify$0$0 ==.
                           002134  6882 	C$fuzzy.h$2285$1_0$107 ==.
                                   6883 ;	../../fuzzy.h:2285: float fuzzy_rules_defuzzify(
                                   6884 ;	-----------------------------------------
                                   6885 ;	 function fuzzy_rules_defuzzify
                                   6886 ;	-----------------------------------------
      0021EB                       6887 _fuzzy_rules_defuzzify:
      0021EB C0 08            [24] 6888 	push	_bp
      0021ED 85 81 08         [24] 6889 	mov	_bp,sp
      0021F0 AD 82            [24] 6890 	mov	r5, dpl
      0021F2 AE 83            [24] 6891 	mov	r6, dph
      0021F4 AF F0            [24] 6892 	mov	r7, b
                           00213F  6893 	C$fuzzy.h$2294$1_0$107 ==.
                                   6894 ;	../../fuzzy.h:2294: rules,
      0021F6 E4               [12] 6895 	clr	a
      0021F7 C0 E0            [24] 6896 	push	acc
      0021F9 C0 E0            [24] 6897 	push	acc
      0021FB E5 08            [12] 6898 	mov	a,_bp
      0021FD 24 F1            [12] 6899 	add	a,#0xf1
      0021FF F8               [12] 6900 	mov	r0,a
      002200 E6               [12] 6901 	mov	a,@r0
      002201 C0 E0            [24] 6902 	push	acc
      002203 E5 08            [12] 6903 	mov	a,_bp
      002205 24 F2            [12] 6904 	add	a,#0xf2
      002207 F8               [12] 6905 	mov	r0,a
      002208 E6               [12] 6906 	mov	a,@r0
      002209 C0 E0            [24] 6907 	push	acc
      00220B 08               [12] 6908 	inc	r0
      00220C E6               [12] 6909 	mov	a,@r0
      00220D C0 E0            [24] 6910 	push	acc
      00220F 08               [12] 6911 	inc	r0
      002210 E6               [12] 6912 	mov	a,@r0
      002211 C0 E0            [24] 6913 	push	acc
      002213 08               [12] 6914 	inc	r0
      002214 E6               [12] 6915 	mov	a,@r0
      002215 C0 E0            [24] 6916 	push	acc
      002217 E5 08            [12] 6917 	mov	a,_bp
      002219 24 F6            [12] 6918 	add	a,#0xf6
      00221B F8               [12] 6919 	mov	r0,a
      00221C E6               [12] 6920 	mov	a,@r0
      00221D C0 E0            [24] 6921 	push	acc
      00221F 08               [12] 6922 	inc	r0
      002220 E6               [12] 6923 	mov	a,@r0
      002221 C0 E0            [24] 6924 	push	acc
      002223 08               [12] 6925 	inc	r0
      002224 E6               [12] 6926 	mov	a,@r0
      002225 C0 E0            [24] 6927 	push	acc
      002227 08               [12] 6928 	inc	r0
      002228 E6               [12] 6929 	mov	a,@r0
      002229 C0 E0            [24] 6930 	push	acc
      00222B E5 08            [12] 6931 	mov	a,_bp
      00222D 24 FA            [12] 6932 	add	a,#0xfa
      00222F F8               [12] 6933 	mov	r0,a
      002230 E6               [12] 6934 	mov	a,@r0
      002231 C0 E0            [24] 6935 	push	acc
      002233 08               [12] 6936 	inc	r0
      002234 E6               [12] 6937 	mov	a,@r0
      002235 C0 E0            [24] 6938 	push	acc
      002237 08               [12] 6939 	inc	r0
      002238 E6               [12] 6940 	mov	a,@r0
      002239 C0 E0            [24] 6941 	push	acc
      00223B 08               [12] 6942 	inc	r0
      00223C E6               [12] 6943 	mov	a,@r0
      00223D C0 E0            [24] 6944 	push	acc
      00223F 8D 82            [24] 6945 	mov	dpl, r5
      002241 8E 83            [24] 6946 	mov	dph, r6
      002243 8F F0            [24] 6947 	mov	b, r7
      002245 12 1B 98         [24] 6948 	lcall	_fuzzy_rules_defuzzify_method
      002248 AC 82            [24] 6949 	mov	r4, dpl
      00224A AD 83            [24] 6950 	mov	r5, dph
      00224C AE F0            [24] 6951 	mov	r6, b
      00224E FF               [12] 6952 	mov	r7, a
      00224F E5 81            [12] 6953 	mov	a,sp
      002251 24 F1            [12] 6954 	add	a,#0xf1
      002253 F5 81            [12] 6955 	mov	sp,a
      002255 8C 82            [24] 6956 	mov	dpl, r4
      002257 8D 83            [24] 6957 	mov	dph, r5
      002259 8E F0            [24] 6958 	mov	b, r6
      00225B EF               [12] 6959 	mov	a, r7
                           0021A5  6960 	C$fuzzy.h$2302$1_0$107 ==.
                                   6961 ;	../../fuzzy.h:2302: }
      00225C D0 08            [24] 6962 	pop	_bp
                           0021A7  6963 	C$fuzzy.h$2302$1_0$107 ==.
                           0021A7  6964 	XG$fuzzy_rules_defuzzify$0$0 ==.
      00225E 22               [24] 6965 	ret
                                   6966 ;------------------------------------------------------------
                                   6967 ;Allocation info for local variables in function 'fuzzy_rules_cog'
                                   6968 ;------------------------------------------------------------
                                   6969 ;lower         Allocated to stack - _bp -6 +4 
                                   6970 ;upper         Allocated to stack - _bp -10 +4 
                                   6971 ;step          Allocated to stack - _bp -14 +4 
                                   6972 ;rules         Allocated to registers r5 r6 r7 
                                   6973 ;------------------------------------------------------------
                           0021A8  6974 	G$fuzzy_rules_cog$0$0 ==.
                           0021A8  6975 	C$fuzzy.h$2307$1_0$109 ==.
                                   6976 ;	../../fuzzy.h:2307: float fuzzy_rules_cog(
                                   6977 ;	-----------------------------------------
                                   6978 ;	 function fuzzy_rules_cog
                                   6979 ;	-----------------------------------------
      00225F                       6980 _fuzzy_rules_cog:
      00225F C0 08            [24] 6981 	push	_bp
      002261 85 81 08         [24] 6982 	mov	_bp,sp
      002264 AD 82            [24] 6983 	mov	r5, dpl
      002266 AE 83            [24] 6984 	mov	r6, dph
      002268 AF F0            [24] 6985 	mov	r7, b
                           0021B3  6986 	C$fuzzy.h$2315$1_0$109 ==.
                                   6987 ;	../../fuzzy.h:2315: rules,
      00226A E4               [12] 6988 	clr	a
      00226B C0 E0            [24] 6989 	push	acc
      00226D E5 08            [12] 6990 	mov	a,_bp
      00226F 24 F2            [12] 6991 	add	a,#0xf2
      002271 F8               [12] 6992 	mov	r0,a
      002272 E6               [12] 6993 	mov	a,@r0
      002273 C0 E0            [24] 6994 	push	acc
      002275 08               [12] 6995 	inc	r0
      002276 E6               [12] 6996 	mov	a,@r0
      002277 C0 E0            [24] 6997 	push	acc
      002279 08               [12] 6998 	inc	r0
      00227A E6               [12] 6999 	mov	a,@r0
      00227B C0 E0            [24] 7000 	push	acc
      00227D 08               [12] 7001 	inc	r0
      00227E E6               [12] 7002 	mov	a,@r0
      00227F C0 E0            [24] 7003 	push	acc
      002281 E5 08            [12] 7004 	mov	a,_bp
      002283 24 F6            [12] 7005 	add	a,#0xf6
      002285 F8               [12] 7006 	mov	r0,a
      002286 E6               [12] 7007 	mov	a,@r0
      002287 C0 E0            [24] 7008 	push	acc
      002289 08               [12] 7009 	inc	r0
      00228A E6               [12] 7010 	mov	a,@r0
      00228B C0 E0            [24] 7011 	push	acc
      00228D 08               [12] 7012 	inc	r0
      00228E E6               [12] 7013 	mov	a,@r0
      00228F C0 E0            [24] 7014 	push	acc
      002291 08               [12] 7015 	inc	r0
      002292 E6               [12] 7016 	mov	a,@r0
      002293 C0 E0            [24] 7017 	push	acc
      002295 E5 08            [12] 7018 	mov	a,_bp
      002297 24 FA            [12] 7019 	add	a,#0xfa
      002299 F8               [12] 7020 	mov	r0,a
      00229A E6               [12] 7021 	mov	a,@r0
      00229B C0 E0            [24] 7022 	push	acc
      00229D 08               [12] 7023 	inc	r0
      00229E E6               [12] 7024 	mov	a,@r0
      00229F C0 E0            [24] 7025 	push	acc
      0022A1 08               [12] 7026 	inc	r0
      0022A2 E6               [12] 7027 	mov	a,@r0
      0022A3 C0 E0            [24] 7028 	push	acc
      0022A5 08               [12] 7029 	inc	r0
      0022A6 E6               [12] 7030 	mov	a,@r0
      0022A7 C0 E0            [24] 7031 	push	acc
      0022A9 8D 82            [24] 7032 	mov	dpl, r5
      0022AB 8E 83            [24] 7033 	mov	dph, r6
      0022AD 8F F0            [24] 7034 	mov	b, r7
      0022AF 12 21 EB         [24] 7035 	lcall	_fuzzy_rules_defuzzify
      0022B2 AC 82            [24] 7036 	mov	r4, dpl
      0022B4 AD 83            [24] 7037 	mov	r5, dph
      0022B6 AE F0            [24] 7038 	mov	r6, b
      0022B8 FF               [12] 7039 	mov	r7, a
      0022B9 E5 81            [12] 7040 	mov	a,sp
      0022BB 24 F3            [12] 7041 	add	a,#0xf3
      0022BD F5 81            [12] 7042 	mov	sp,a
      0022BF 8C 82            [24] 7043 	mov	dpl, r4
      0022C1 8D 83            [24] 7044 	mov	dph, r5
      0022C3 8E F0            [24] 7045 	mov	b, r6
      0022C5 EF               [12] 7046 	mov	a, r7
                           00220F  7047 	C$fuzzy.h$2321$1_0$109 ==.
                                   7048 ;	../../fuzzy.h:2321: }
      0022C6 D0 08            [24] 7049 	pop	_bp
                           002211  7050 	C$fuzzy.h$2321$1_0$109 ==.
                           002211  7051 	XG$fuzzy_rules_cog$0$0 ==.
      0022C8 22               [24] 7052 	ret
                                   7053 ;------------------------------------------------------------
                                   7054 ;Allocation info for local variables in function 'temperature_low'
                                   7055 ;------------------------------------------------------------
                                   7056 ;value         Allocated to registers r4 r5 r6 r7 
                                   7057 ;------------------------------------------------------------
                           002212  7058 	Fcontroller_8051$temperature_low$0$0 ==.
                           002212  7059 	C$controller_8051.c$59$1_0$111 ==.
                                   7060 ;	../../controller_8051.c:59: static float temperature_low(
                                   7061 ;	-----------------------------------------
                                   7062 ;	 function temperature_low
                                   7063 ;	-----------------------------------------
      0022C9                       7064 _temperature_low:
      0022C9 AC 82            [24] 7065 	mov	r4,dpl
      0022CB AD 83            [24] 7066 	mov	r5,dph
      0022CD AE F0            [24] 7067 	mov	r6,b
      0022CF FF               [12] 7068 	mov	r7,a
                           002219  7069 	C$controller_8051.c$68$1_0$111 ==.
                                   7070 ;	../../controller_8051.c:68: hedges.none
      0022D0 90 2A 56         [24] 7071 	mov	dptr,#_hedges
      0022D3 E4               [12] 7072 	clr	a
      0022D4 93               [24] 7073 	movc	a,@a+dptr
      0022D5 FB               [12] 7074 	mov	r3,a
                           00221F  7075 	C$controller_8051.c$64$1_0$111 ==.
                                   7076 ;	../../controller_8051.c:64: 20.0f,
      0022D6 C0 03            [24] 7077 	push	ar3
      0022D8 E4               [12] 7078 	clr	a
      0022D9 C0 E0            [24] 7079 	push	acc
      0022DB C0 04            [24] 7080 	push	ar4
      0022DD C0 05            [24] 7081 	push	ar5
      0022DF C0 06            [24] 7082 	push	ar6
      0022E1 C0 07            [24] 7083 	push	ar7
      0022E3 C0 E0            [24] 7084 	push	acc
      0022E5 C0 E0            [24] 7085 	push	acc
      0022E7 74 20            [12] 7086 	mov	a,#0x20
      0022E9 C0 E0            [24] 7087 	push	acc
      0022EB 74 42            [12] 7088 	mov	a,#0x42
      0022ED C0 E0            [24] 7089 	push	acc
      0022EF 90 00 00         [24] 7090 	mov	dptr,#0x0000
      0022F2 75 F0 A0         [24] 7091 	mov	b, #0xa0
      0022F5 14               [12] 7092 	dec	a
      0022F6 12 0A EC         [24] 7093 	lcall	_fuzzy_ramp
      0022F9 AC 82            [24] 7094 	mov	r4, dpl
      0022FB AD 83            [24] 7095 	mov	r5, dph
      0022FD AE F0            [24] 7096 	mov	r6, b
      0022FF FF               [12] 7097 	mov	r7, a
      002300 E5 81            [12] 7098 	mov	a,sp
      002302 24 F6            [12] 7099 	add	a,#0xf6
      002304 F5 81            [12] 7100 	mov	sp,a
      002306 8C 82            [24] 7101 	mov	dpl, r4
      002308 8D 83            [24] 7102 	mov	dph, r5
      00230A 8E F0            [24] 7103 	mov	b, r6
      00230C EF               [12] 7104 	mov	a, r7
                           002256  7105 	C$controller_8051.c$70$1_0$111 ==.
                                   7106 ;	../../controller_8051.c:70: }
                           002256  7107 	C$controller_8051.c$70$1_0$111 ==.
                           002256  7108 	XFcontroller_8051$temperature_low$0$0 ==.
      00230D 22               [24] 7109 	ret
                                   7110 ;------------------------------------------------------------
                                   7111 ;Allocation info for local variables in function 'temperature_high'
                                   7112 ;------------------------------------------------------------
                                   7113 ;value         Allocated to registers r4 r5 r6 r7 
                                   7114 ;------------------------------------------------------------
                           002257  7115 	Fcontroller_8051$temperature_high$0$0 ==.
                           002257  7116 	C$controller_8051.c$73$1_0$113 ==.
                                   7117 ;	../../controller_8051.c:73: static float temperature_high(
                                   7118 ;	-----------------------------------------
                                   7119 ;	 function temperature_high
                                   7120 ;	-----------------------------------------
      00230E                       7121 _temperature_high:
      00230E AC 82            [24] 7122 	mov	r4,dpl
      002310 AD 83            [24] 7123 	mov	r5,dph
      002312 AE F0            [24] 7124 	mov	r6,b
      002314 FF               [12] 7125 	mov	r7,a
                           00225E  7126 	C$controller_8051.c$82$1_0$113 ==.
                                   7127 ;	../../controller_8051.c:82: hedges.none
      002315 90 2A 56         [24] 7128 	mov	dptr,#_hedges
      002318 E4               [12] 7129 	clr	a
      002319 93               [24] 7130 	movc	a,@a+dptr
      00231A FB               [12] 7131 	mov	r3,a
                           002264  7132 	C$controller_8051.c$78$1_0$113 ==.
                                   7133 ;	../../controller_8051.c:78: 30.0f,
      00231B C0 03            [24] 7134 	push	ar3
      00231D 74 01            [12] 7135 	mov	a,#0x01
      00231F C0 E0            [24] 7136 	push	acc
      002321 C0 04            [24] 7137 	push	ar4
      002323 C0 05            [24] 7138 	push	ar5
      002325 C0 06            [24] 7139 	push	ar6
      002327 C0 07            [24] 7140 	push	ar7
      002329 E4               [12] 7141 	clr	a
      00232A C0 E0            [24] 7142 	push	acc
      00232C C0 E0            [24] 7143 	push	acc
      00232E 74 70            [12] 7144 	mov	a,#0x70
      002330 C0 E0            [24] 7145 	push	acc
      002332 74 42            [12] 7146 	mov	a,#0x42
      002334 C0 E0            [24] 7147 	push	acc
      002336 90 00 00         [24] 7148 	mov	dptr,#0x0000
      002339 75 F0 F0         [24] 7149 	mov	b, #0xf0
      00233C 14               [12] 7150 	dec	a
      00233D 12 0A EC         [24] 7151 	lcall	_fuzzy_ramp
      002340 AC 82            [24] 7152 	mov	r4, dpl
      002342 AD 83            [24] 7153 	mov	r5, dph
      002344 AE F0            [24] 7154 	mov	r6, b
      002346 FF               [12] 7155 	mov	r7, a
      002347 E5 81            [12] 7156 	mov	a,sp
      002349 24 F6            [12] 7157 	add	a,#0xf6
      00234B F5 81            [12] 7158 	mov	sp,a
      00234D 8C 82            [24] 7159 	mov	dpl, r4
      00234F 8D 83            [24] 7160 	mov	dph, r5
      002351 8E F0            [24] 7161 	mov	b, r6
      002353 EF               [12] 7162 	mov	a, r7
                           00229D  7163 	C$controller_8051.c$84$1_0$113 ==.
                                   7164 ;	../../controller_8051.c:84: }
                           00229D  7165 	C$controller_8051.c$84$1_0$113 ==.
                           00229D  7166 	XFcontroller_8051$temperature_high$0$0 ==.
      002354 22               [24] 7167 	ret
                                   7168 ;------------------------------------------------------------
                                   7169 ;Allocation info for local variables in function 'fan_slow'
                                   7170 ;------------------------------------------------------------
                                   7171 ;value         Allocated to registers r4 r5 r6 r7 
                                   7172 ;------------------------------------------------------------
                           00229E  7173 	Fcontroller_8051$fan_slow$0$0 ==.
                           00229E  7174 	C$controller_8051.c$91$1_0$115 ==.
                                   7175 ;	../../controller_8051.c:91: static float fan_slow(
                                   7176 ;	-----------------------------------------
                                   7177 ;	 function fan_slow
                                   7178 ;	-----------------------------------------
      002355                       7179 _fan_slow:
      002355 AC 82            [24] 7180 	mov	r4,dpl
      002357 AD 83            [24] 7181 	mov	r5,dph
      002359 AE F0            [24] 7182 	mov	r6,b
      00235B FF               [12] 7183 	mov	r7,a
                           0022A5  7184 	C$controller_8051.c$100$1_0$115 ==.
                                   7185 ;	../../controller_8051.c:100: hedges.none
      00235C 90 2A 56         [24] 7186 	mov	dptr,#_hedges
      00235F E4               [12] 7187 	clr	a
      002360 93               [24] 7188 	movc	a,@a+dptr
      002361 FB               [12] 7189 	mov	r3,a
                           0022AB  7190 	C$controller_8051.c$96$1_0$115 ==.
                                   7191 ;	../../controller_8051.c:96: 20.0f,
      002362 C0 03            [24] 7192 	push	ar3
      002364 E4               [12] 7193 	clr	a
      002365 C0 E0            [24] 7194 	push	acc
      002367 C0 04            [24] 7195 	push	ar4
      002369 C0 05            [24] 7196 	push	ar5
      00236B C0 06            [24] 7197 	push	ar6
      00236D C0 07            [24] 7198 	push	ar7
      00236F C0 E0            [24] 7199 	push	acc
      002371 C0 E0            [24] 7200 	push	acc
      002373 74 48            [12] 7201 	mov	a,#0x48
      002375 C0 E0            [24] 7202 	push	acc
      002377 74 42            [12] 7203 	mov	a,#0x42
      002379 C0 E0            [24] 7204 	push	acc
      00237B 90 00 00         [24] 7205 	mov	dptr,#0x0000
      00237E 75 F0 A0         [24] 7206 	mov	b, #0xa0
      002381 14               [12] 7207 	dec	a
      002382 12 0A EC         [24] 7208 	lcall	_fuzzy_ramp
      002385 AC 82            [24] 7209 	mov	r4, dpl
      002387 AD 83            [24] 7210 	mov	r5, dph
      002389 AE F0            [24] 7211 	mov	r6, b
      00238B FF               [12] 7212 	mov	r7, a
      00238C E5 81            [12] 7213 	mov	a,sp
      00238E 24 F6            [12] 7214 	add	a,#0xf6
      002390 F5 81            [12] 7215 	mov	sp,a
      002392 8C 82            [24] 7216 	mov	dpl, r4
      002394 8D 83            [24] 7217 	mov	dph, r5
      002396 8E F0            [24] 7218 	mov	b, r6
      002398 EF               [12] 7219 	mov	a, r7
                           0022E2  7220 	C$controller_8051.c$102$1_0$115 ==.
                                   7221 ;	../../controller_8051.c:102: }
                           0022E2  7222 	C$controller_8051.c$102$1_0$115 ==.
                           0022E2  7223 	XFcontroller_8051$fan_slow$0$0 ==.
      002399 22               [24] 7224 	ret
                                   7225 ;------------------------------------------------------------
                                   7226 ;Allocation info for local variables in function 'fan_fast'
                                   7227 ;------------------------------------------------------------
                                   7228 ;value         Allocated to registers r4 r5 r6 r7 
                                   7229 ;------------------------------------------------------------
                           0022E3  7230 	Fcontroller_8051$fan_fast$0$0 ==.
                           0022E3  7231 	C$controller_8051.c$105$1_0$117 ==.
                                   7232 ;	../../controller_8051.c:105: static float fan_fast(
                                   7233 ;	-----------------------------------------
                                   7234 ;	 function fan_fast
                                   7235 ;	-----------------------------------------
      00239A                       7236 _fan_fast:
      00239A AC 82            [24] 7237 	mov	r4,dpl
      00239C AD 83            [24] 7238 	mov	r5,dph
      00239E AE F0            [24] 7239 	mov	r6,b
      0023A0 FF               [12] 7240 	mov	r7,a
                           0022EA  7241 	C$controller_8051.c$114$1_0$117 ==.
                                   7242 ;	../../controller_8051.c:114: hedges.none
      0023A1 90 2A 56         [24] 7243 	mov	dptr,#_hedges
      0023A4 E4               [12] 7244 	clr	a
      0023A5 93               [24] 7245 	movc	a,@a+dptr
      0023A6 FB               [12] 7246 	mov	r3,a
                           0022F0  7247 	C$controller_8051.c$110$1_0$117 ==.
                                   7248 ;	../../controller_8051.c:110: 40.0f,
      0023A7 C0 03            [24] 7249 	push	ar3
      0023A9 74 01            [12] 7250 	mov	a,#0x01
      0023AB C0 E0            [24] 7251 	push	acc
      0023AD C0 04            [24] 7252 	push	ar4
      0023AF C0 05            [24] 7253 	push	ar5
      0023B1 C0 06            [24] 7254 	push	ar6
      0023B3 C0 07            [24] 7255 	push	ar7
      0023B5 E4               [12] 7256 	clr	a
      0023B6 C0 E0            [24] 7257 	push	acc
      0023B8 C0 E0            [24] 7258 	push	acc
      0023BA 74 A0            [12] 7259 	mov	a,#0xa0
      0023BC C0 E0            [24] 7260 	push	acc
      0023BE 74 42            [12] 7261 	mov	a,#0x42
      0023C0 C0 E0            [24] 7262 	push	acc
      0023C2 90 00 00         [24] 7263 	mov	dptr,#0x0000
      0023C5 75 F0 20         [24] 7264 	mov	b, #0x20
      0023C8 12 0A EC         [24] 7265 	lcall	_fuzzy_ramp
      0023CB AC 82            [24] 7266 	mov	r4, dpl
      0023CD AD 83            [24] 7267 	mov	r5, dph
      0023CF AE F0            [24] 7268 	mov	r6, b
      0023D1 FF               [12] 7269 	mov	r7, a
      0023D2 E5 81            [12] 7270 	mov	a,sp
      0023D4 24 F6            [12] 7271 	add	a,#0xf6
      0023D6 F5 81            [12] 7272 	mov	sp,a
      0023D8 8C 82            [24] 7273 	mov	dpl, r4
      0023DA 8D 83            [24] 7274 	mov	dph, r5
      0023DC 8E F0            [24] 7275 	mov	b, r6
      0023DE EF               [12] 7276 	mov	a, r7
                           002328  7277 	C$controller_8051.c$116$1_0$117 ==.
                                   7278 ;	../../controller_8051.c:116: }
                           002328  7279 	C$controller_8051.c$116$1_0$117 ==.
                           002328  7280 	XFcontroller_8051$fan_fast$0$0 ==.
      0023DF 22               [24] 7281 	ret
                                   7282 ;------------------------------------------------------------
                                   7283 ;Allocation info for local variables in function 'calculate_fan_speed'
                                   7284 ;------------------------------------------------------------
                                   7285 ;temperature   Allocated to stack - _bp +1 +4 
                                   7286 ;rules         Allocated to stack - _bp +9 +146 
                                   7287 ;result        Allocated to registers r4 r5 r6 r7 
                                   7288 ;sloc0         Allocated to stack - _bp +5 +4 
                                   7289 ;------------------------------------------------------------
                           002329  7290 	Fcontroller_8051$calculate_fan_speed$0$0 ==.
                           002329  7291 	C$controller_8051.c$123$1_0$119 ==.
                                   7292 ;	../../controller_8051.c:123: static float calculate_fan_speed(float temperature)
                                   7293 ;	-----------------------------------------
                                   7294 ;	 function calculate_fan_speed
                                   7295 ;	-----------------------------------------
      0023E0                       7296 _calculate_fan_speed:
      0023E0 C0 08            [24] 7297 	push	_bp
      0023E2 85 81 08         [24] 7298 	mov	_bp,sp
      0023E5 C0 82            [24] 7299 	push	dpl
      0023E7 C0 83            [24] 7300 	push	dph
      0023E9 C0 F0            [24] 7301 	push	b
      0023EB C0 E0            [24] 7302 	push	acc
      0023ED E5 81            [12] 7303 	mov	a,sp
      0023EF 24 96            [12] 7304 	add	a,#0x96
      0023F1 F5 81            [12] 7305 	mov	sp,a
                           00233C  7306 	C$controller_8051.c$129$1_0$119 ==.
                                   7307 ;	../../controller_8051.c:129: rules.count = 0;
      0023F3 E5 08            [12] 7308 	mov	a,_bp
      0023F5 24 09            [12] 7309 	add	a,#0x09
      0023F7 FB               [12] 7310 	mov	r3,a
      0023F8 24 90            [12] 7311 	add	a,#0x90
      0023FA F9               [12] 7312 	mov	r1,a
      0023FB 77 00            [12] 7313 	mov	@r1,#0x00
      0023FD 09               [12] 7314 	inc	r1
      0023FE 77 00            [12] 7315 	mov	@r1,#0x00
      002400 19               [12] 7316 	dec	r1
                           00234A  7317 	C$controller_8051.c$132$1_0$119 ==.
                                   7318 ;	../../controller_8051.c:132: if (!FUZZY_RULE_ADD(&rules, temperature_low(temperature), fan_slow)) return 0.0f;
      002401 A8 08            [24] 7319 	mov	r0,_bp
      002403 08               [12] 7320 	inc	r0
      002404 86 82            [24] 7321 	mov	dpl, @r0
      002406 08               [12] 7322 	inc	r0
      002407 86 83            [24] 7323 	mov	dph, @r0
      002409 08               [12] 7324 	inc	r0
      00240A 86 F0            [24] 7325 	mov	b, @r0
      00240C 08               [12] 7326 	inc	r0
      00240D E6               [12] 7327 	mov	a, @r0
      00240E C0 03            [24] 7328 	push	ar3
      002410 C0 01            [24] 7329 	push	ar1
      002412 12 22 C9         [24] 7330 	lcall	_temperature_low
      002415 C8               [12] 7331 	xch	a,r0
      002416 E5 08            [12] 7332 	mov	a,_bp
      002418 24 05            [12] 7333 	add	a,#0x05
      00241A C8               [12] 7334 	xch	a,r0
      00241B A6 82            [24] 7335 	mov	@r0, dpl
      00241D 08               [12] 7336 	inc	r0
      00241E A6 83            [24] 7337 	mov	@r0, dph
      002420 08               [12] 7338 	inc	r0
      002421 A6 F0            [24] 7339 	mov	@r0, b
      002423 08               [12] 7340 	inc	r0
      002424 F6               [12] 7341 	mov	@r0,a
      002425 D0 01            [24] 7342 	pop	ar1
      002427 D0 03            [24] 7343 	pop	ar3
      002429 8B 04            [24] 7344 	mov	ar4,r3
      00242B 7E 00            [12] 7345 	mov	r6,#0x00
      00242D 7F 40            [12] 7346 	mov	r7,#0x40
      00242F C0 03            [24] 7347 	push	ar3
      002431 C0 01            [24] 7348 	push	ar1
      002433 74 55            [12] 7349 	mov	a,#_fan_slow
      002435 C0 E0            [24] 7350 	push	acc
      002437 74 23            [12] 7351 	mov	a,#(_fan_slow >> 8)
      002439 C0 E0            [24] 7352 	push	acc
      00243B E5 08            [12] 7353 	mov	a,_bp
      00243D 24 05            [12] 7354 	add	a,#0x05
      00243F F8               [12] 7355 	mov	r0,a
      002440 E6               [12] 7356 	mov	a,@r0
      002441 C0 E0            [24] 7357 	push	acc
      002443 08               [12] 7358 	inc	r0
      002444 E6               [12] 7359 	mov	a,@r0
      002445 C0 E0            [24] 7360 	push	acc
      002447 08               [12] 7361 	inc	r0
      002448 E6               [12] 7362 	mov	a,@r0
      002449 C0 E0            [24] 7363 	push	acc
      00244B 08               [12] 7364 	inc	r0
      00244C E6               [12] 7365 	mov	a,@r0
      00244D C0 E0            [24] 7366 	push	acc
      00244F 74 59            [12] 7367 	mov	a,#___str_0
      002451 C0 E0            [24] 7368 	push	acc
      002453 74 2A            [12] 7369 	mov	a,#(___str_0 >> 8)
      002455 C0 E0            [24] 7370 	push	acc
      002457 74 80            [12] 7371 	mov	a,#0x80
      002459 C0 E0            [24] 7372 	push	acc
      00245B 8C 82            [24] 7373 	mov	dpl, r4
      00245D 8E 83            [24] 7374 	mov	dph, r6
      00245F 8F F0            [24] 7375 	mov	b, r7
      002461 12 17 6D         [24] 7376 	lcall	_fuzzy_rules_add
      002464 AF 82            [24] 7377 	mov	r7, dpl
      002466 E5 81            [12] 7378 	mov	a,sp
      002468 24 F7            [12] 7379 	add	a,#0xf7
      00246A F5 81            [12] 7380 	mov	sp,a
      00246C D0 01            [24] 7381 	pop	ar1
      00246E D0 03            [24] 7382 	pop	ar3
      002470 EF               [12] 7383 	mov	a,r7
      002471 70 09            [24] 7384 	jnz	00102$
      002473 90 00 00         [24] 7385 	mov	dptr,#0x0000
      002476 E4               [12] 7386 	clr	a
      002477 F5 F0            [12] 7387 	mov	b,a
      002479 02 25 4B         [24] 7388 	ljmp	00105$
      00247C                       7389 00102$:
                           0023C5  7390 	C$controller_8051.c$134$1_0$119 ==.
                                   7391 ;	../../controller_8051.c:134: if (!FUZZY_RULE_ADD(&rules, temperature_high(temperature), fan_fast)) return 0.0f;
      00247C C0 01            [24] 7392 	push	ar1
      00247E A8 08            [24] 7393 	mov	r0,_bp
      002480 08               [12] 7394 	inc	r0
      002481 86 82            [24] 7395 	mov	dpl, @r0
      002483 08               [12] 7396 	inc	r0
      002484 86 83            [24] 7397 	mov	dph, @r0
      002486 08               [12] 7398 	inc	r0
      002487 86 F0            [24] 7399 	mov	b, @r0
      002489 08               [12] 7400 	inc	r0
      00248A E6               [12] 7401 	mov	a, @r0
      00248B C0 03            [24] 7402 	push	ar3
      00248D C0 01            [24] 7403 	push	ar1
      00248F 12 23 0E         [24] 7404 	lcall	_temperature_high
      002492 C8               [12] 7405 	xch	a,r0
      002493 E5 08            [12] 7406 	mov	a,_bp
      002495 24 05            [12] 7407 	add	a,#0x05
      002497 C8               [12] 7408 	xch	a,r0
      002498 A6 82            [24] 7409 	mov	@r0, dpl
      00249A 08               [12] 7410 	inc	r0
      00249B A6 83            [24] 7411 	mov	@r0, dph
      00249D 08               [12] 7412 	inc	r0
      00249E A6 F0            [24] 7413 	mov	@r0, b
      0024A0 08               [12] 7414 	inc	r0
      0024A1 F6               [12] 7415 	mov	@r0,a
      0024A2 D0 01            [24] 7416 	pop	ar1
      0024A4 D0 03            [24] 7417 	pop	ar3
      0024A6 8B 02            [24] 7418 	mov	ar2,r3
      0024A8 7E 00            [12] 7419 	mov	r6,#0x00
      0024AA 7F 40            [12] 7420 	mov	r7,#0x40
      0024AC C0 03            [24] 7421 	push	ar3
      0024AE C0 01            [24] 7422 	push	ar1
      0024B0 74 9A            [12] 7423 	mov	a,#_fan_fast
      0024B2 C0 E0            [24] 7424 	push	acc
      0024B4 74 23            [12] 7425 	mov	a,#(_fan_fast >> 8)
      0024B6 C0 E0            [24] 7426 	push	acc
      0024B8 E5 08            [12] 7427 	mov	a,_bp
      0024BA 24 05            [12] 7428 	add	a,#0x05
      0024BC F8               [12] 7429 	mov	r0,a
      0024BD E6               [12] 7430 	mov	a,@r0
      0024BE C0 E0            [24] 7431 	push	acc
      0024C0 08               [12] 7432 	inc	r0
      0024C1 E6               [12] 7433 	mov	a,@r0
      0024C2 C0 E0            [24] 7434 	push	acc
      0024C4 08               [12] 7435 	inc	r0
      0024C5 E6               [12] 7436 	mov	a,@r0
      0024C6 C0 E0            [24] 7437 	push	acc
      0024C8 08               [12] 7438 	inc	r0
      0024C9 E6               [12] 7439 	mov	a,@r0
      0024CA C0 E0            [24] 7440 	push	acc
      0024CC 74 62            [12] 7441 	mov	a,#___str_1
      0024CE C0 E0            [24] 7442 	push	acc
      0024D0 74 2A            [12] 7443 	mov	a,#(___str_1 >> 8)
      0024D2 C0 E0            [24] 7444 	push	acc
      0024D4 74 80            [12] 7445 	mov	a,#0x80
      0024D6 C0 E0            [24] 7446 	push	acc
      0024D8 8A 82            [24] 7447 	mov	dpl, r2
      0024DA 8E 83            [24] 7448 	mov	dph, r6
      0024DC 8F F0            [24] 7449 	mov	b, r7
      0024DE 12 17 6D         [24] 7450 	lcall	_fuzzy_rules_add
      0024E1 AF 82            [24] 7451 	mov	r7, dpl
      0024E3 E5 81            [12] 7452 	mov	a,sp
      0024E5 24 F7            [12] 7453 	add	a,#0xf7
      0024E7 F5 81            [12] 7454 	mov	sp,a
      0024E9 D0 01            [24] 7455 	pop	ar1
      0024EB D0 03            [24] 7456 	pop	ar3
      0024ED D0 01            [24] 7457 	pop	ar1
      0024EF EF               [12] 7458 	mov	a,r7
      0024F0 70 08            [24] 7459 	jnz	00104$
      0024F2 90 00 00         [24] 7460 	mov	dptr,#0x0000
      0024F5 E4               [12] 7461 	clr	a
      0024F6 F5 F0            [12] 7462 	mov	b,a
      0024F8 80 51            [24] 7463 	sjmp	00105$
      0024FA                       7464 00104$:
                           002443  7465 	C$controller_8051.c$138$1_0$119 ==.
                                   7466 ;	../../controller_8051.c:138: &rules,
      0024FA 7F 00            [12] 7467 	mov	r7,#0x00
      0024FC 7E 40            [12] 7468 	mov	r6,#0x40
      0024FE C0 01            [24] 7469 	push	ar1
      002500 74 01            [12] 7470 	mov	a,#0x01
      002502 C0 E0            [24] 7471 	push	acc
      002504 E4               [12] 7472 	clr	a
      002505 C0 E0            [24] 7473 	push	acc
      002507 C0 E0            [24] 7474 	push	acc
      002509 74 20            [12] 7475 	mov	a,#0x20
      00250B C0 E0            [24] 7476 	push	acc
      00250D 74 41            [12] 7477 	mov	a,#0x41
      00250F C0 E0            [24] 7478 	push	acc
      002511 E4               [12] 7479 	clr	a
      002512 C0 E0            [24] 7480 	push	acc
      002514 C0 E0            [24] 7481 	push	acc
      002516 74 C8            [12] 7482 	mov	a,#0xc8
      002518 C0 E0            [24] 7483 	push	acc
      00251A 74 42            [12] 7484 	mov	a,#0x42
      00251C C0 E0            [24] 7485 	push	acc
      00251E E4               [12] 7486 	clr	a
      00251F C0 E0            [24] 7487 	push	acc
      002521 C0 E0            [24] 7488 	push	acc
      002523 C0 E0            [24] 7489 	push	acc
      002525 C0 E0            [24] 7490 	push	acc
      002527 8B 82            [24] 7491 	mov	dpl, r3
      002529 8F 83            [24] 7492 	mov	dph, r7
      00252B 8E F0            [24] 7493 	mov	b, r6
      00252D 12 21 EB         [24] 7494 	lcall	_fuzzy_rules_defuzzify
      002530 AC 82            [24] 7495 	mov	r4, dpl
      002532 AD 83            [24] 7496 	mov	r5, dph
      002534 AE F0            [24] 7497 	mov	r6, b
      002536 FF               [12] 7498 	mov	r7, a
      002537 E5 81            [12] 7499 	mov	a,sp
      002539 24 F3            [12] 7500 	add	a,#0xf3
      00253B F5 81            [12] 7501 	mov	sp,a
      00253D D0 01            [24] 7502 	pop	ar1
                           002488  7503 	C$controller_8051.c$146$1_0$119 ==.
                                   7504 ;	../../controller_8051.c:146: rules.count = 0;
      00253F 77 00            [12] 7505 	mov	@r1,#0x00
      002541 09               [12] 7506 	inc	r1
      002542 77 00            [12] 7507 	mov	@r1,#0x00
                           00248D  7508 	C$controller_8051.c$148$1_0$119 ==.
                                   7509 ;	../../controller_8051.c:148: return result;
      002544 8C 82            [24] 7510 	mov	dpl, r4
      002546 8D 83            [24] 7511 	mov	dph, r5
      002548 8E F0            [24] 7512 	mov	b, r6
      00254A EF               [12] 7513 	mov	a, r7
      00254B                       7514 00105$:
                           002494  7515 	C$controller_8051.c$149$1_0$119 ==.
                                   7516 ;	../../controller_8051.c:149: }
      00254B 85 08 81         [24] 7517 	mov	sp,_bp
      00254E D0 08            [24] 7518 	pop	_bp
                           002499  7519 	C$controller_8051.c$149$1_0$119 ==.
                           002499  7520 	XFcontroller_8051$calculate_fan_speed$0$0 ==.
      002550 22               [24] 7521 	ret
                                   7522 ;------------------------------------------------------------
                                   7523 ;Allocation info for local variables in function 'fan_speed_to_pwm'
                                   7524 ;------------------------------------------------------------
                                   7525 ;fan_speed     Allocated to registers r4 r5 r6 r7 
                                   7526 ;------------------------------------------------------------
                           00249A  7527 	Fcontroller_8051$fan_speed_to_pwm$0$0 ==.
                           00249A  7528 	C$controller_8051.c$156$1_0$121 ==.
                                   7529 ;	../../controller_8051.c:156: static unsigned char fan_speed_to_pwm(
                                   7530 ;	-----------------------------------------
                                   7531 ;	 function fan_speed_to_pwm
                                   7532 ;	-----------------------------------------
      002551                       7533 _fan_speed_to_pwm:
      002551 AC 82            [24] 7534 	mov	r4,dpl
      002553 AD 83            [24] 7535 	mov	r5,dph
      002555 AE F0            [24] 7536 	mov	r6,b
      002557 FF               [12] 7537 	mov	r7,a
                           0024A1  7538 	C$controller_8051.c$160$1_0$121 ==.
                                   7539 ;	../../controller_8051.c:160: if (fan_speed <= 0.0f) {
      002558 C0 07            [24] 7540 	push	ar7
      00255A C0 06            [24] 7541 	push	ar6
      00255C C0 05            [24] 7542 	push	ar5
      00255E C0 04            [24] 7543 	push	ar4
      002560 C0 04            [24] 7544 	push	ar4
      002562 C0 05            [24] 7545 	push	ar5
      002564 C0 06            [24] 7546 	push	ar6
      002566 C0 07            [24] 7547 	push	ar7
      002568 90 00 00         [24] 7548 	mov	dptr,#0x0000
      00256B E4               [12] 7549 	clr	a
      00256C F5 F0            [12] 7550 	mov	b,a
      00256E 12 27 68         [24] 7551 	lcall	___fslt
      002571 E5 81            [12] 7552 	mov	a,sp
      002573 24 FC            [12] 7553 	add	a,#0xfc
      002575 F5 81            [12] 7554 	mov	sp,a
      002577 D0 04            [24] 7555 	pop	ar4
      002579 D0 05            [24] 7556 	pop	ar5
      00257B D0 06            [24] 7557 	pop	ar6
      00257D D0 07            [24] 7558 	pop	ar7
      00257F E5 82            [12] 7559 	mov	a, dpl
      002581 24 FF            [12] 7560 	add	a,#0xff
      002583 92 00            [24] 7561 	mov	b0,c
      002585 40 05            [24] 7562 	jc	00102$
                           0024D0  7563 	C$controller_8051.c$161$2_0$122 ==.
                                   7564 ;	../../controller_8051.c:161: return 0u;
      002587 75 82 00         [24] 7565 	mov	dpl, #0x00
      00258A 80 66            [24] 7566 	sjmp	00105$
      00258C                       7567 00102$:
                           0024D5  7568 	C$controller_8051.c$164$1_0$121 ==.
                                   7569 ;	../../controller_8051.c:164: if (fan_speed >= 100.0f) {
      00258C C0 07            [24] 7570 	push	ar7
      00258E C0 06            [24] 7571 	push	ar6
      002590 C0 05            [24] 7572 	push	ar5
      002592 C0 04            [24] 7573 	push	ar4
      002594 E4               [12] 7574 	clr	a
      002595 C0 E0            [24] 7575 	push	acc
      002597 C0 E0            [24] 7576 	push	acc
      002599 74 C8            [12] 7577 	mov	a,#0xc8
      00259B C0 E0            [24] 7578 	push	acc
      00259D 74 42            [12] 7579 	mov	a,#0x42
      00259F C0 E0            [24] 7580 	push	acc
      0025A1 8C 82            [24] 7581 	mov	dpl, r4
      0025A3 8D 83            [24] 7582 	mov	dph, r5
      0025A5 8E F0            [24] 7583 	mov	b, r6
      0025A7 EF               [12] 7584 	mov	a, r7
      0025A8 12 27 68         [24] 7585 	lcall	___fslt
      0025AB E5 81            [12] 7586 	mov	a,sp
      0025AD 24 FC            [12] 7587 	add	a,#0xfc
      0025AF F5 81            [12] 7588 	mov	sp,a
      0025B1 D0 04            [24] 7589 	pop	ar4
      0025B3 D0 05            [24] 7590 	pop	ar5
      0025B5 D0 06            [24] 7591 	pop	ar6
      0025B7 D0 07            [24] 7592 	pop	ar7
      0025B9 E5 82            [12] 7593 	mov	a, dpl
      0025BB 24 FF            [12] 7594 	add	a,#0xff
      0025BD 92 00            [24] 7595 	mov	b0,c
      0025BF 40 05            [24] 7596 	jc	00104$
                           00250A  7597 	C$controller_8051.c$165$2_0$123 ==.
                                   7598 ;	../../controller_8051.c:165: return 100u;
      0025C1 75 82 64         [24] 7599 	mov	dpl, #0x64
      0025C4 80 2C            [24] 7600 	sjmp	00105$
      0025C6                       7601 00104$:
                           00250F  7602 	C$controller_8051.c$170$1_0$121 ==.
                                   7603 ;	../../controller_8051.c:170: );
      0025C6 E4               [12] 7604 	clr	a
      0025C7 C0 E0            [24] 7605 	push	acc
      0025C9 C0 E0            [24] 7606 	push	acc
      0025CB C0 E0            [24] 7607 	push	acc
      0025CD 74 3F            [12] 7608 	mov	a,#0x3f
      0025CF C0 E0            [24] 7609 	push	acc
      0025D1 8C 82            [24] 7610 	mov	dpl, r4
      0025D3 8D 83            [24] 7611 	mov	dph, r5
      0025D5 8E F0            [24] 7612 	mov	b, r6
      0025D7 EF               [12] 7613 	mov	a, r7
      0025D8 12 27 BA         [24] 7614 	lcall	___fsadd
      0025DB AC 82            [24] 7615 	mov	r4, dpl
      0025DD AD 83            [24] 7616 	mov	r5, dph
      0025DF AE F0            [24] 7617 	mov	r6, b
      0025E1 FF               [12] 7618 	mov	r7, a
      0025E2 E5 81            [12] 7619 	mov	a,sp
      0025E4 24 FC            [12] 7620 	add	a,#0xfc
      0025E6 F5 81            [12] 7621 	mov	sp,a
      0025E8 8C 82            [24] 7622 	mov	dpl, r4
      0025EA 8D 83            [24] 7623 	mov	dph, r5
      0025EC 8E F0            [24] 7624 	mov	b, r6
      0025EE EF               [12] 7625 	mov	a, r7
      0025EF 12 29 B0         [24] 7626 	lcall	___fs2uchar
      0025F2                       7627 00105$:
                           00253B  7628 	C$controller_8051.c$171$1_0$121 ==.
                                   7629 ;	../../controller_8051.c:171: }
                           00253B  7630 	C$controller_8051.c$171$1_0$121 ==.
                           00253B  7631 	XFcontroller_8051$fan_speed_to_pwm$0$0 ==.
      0025F2 22               [24] 7632 	ret
                                   7633 ;------------------------------------------------------------
                                   7634 ;Allocation info for local variables in function 'main'
                                   7635 ;------------------------------------------------------------
                           00253C  7636 	G$main$0$0 ==.
                           00253C  7637 	C$controller_8051.c$188$1_0$125 ==.
                                   7638 ;	../../controller_8051.c:188: void main(void)
                                   7639 ;	-----------------------------------------
                                   7640 ;	 function main
                                   7641 ;	-----------------------------------------
      0025F3                       7642 _main:
                           00253C  7643 	C$controller_8051.c$196$1_0$125 ==.
                                   7644 ;	../../controller_8051.c:196: 42u;
      0025F3 75 61 2A         [24] 7645 	mov	_test_temperature,#0x2a
                           00253F  7646 	C$controller_8051.c$202$1_0$125 ==.
                                   7647 ;	../../controller_8051.c:202: 0x55u;
      0025F6 75 80 55         [24] 7648 	mov	_P0,#0x55
                           002542  7649 	C$controller_8051.c$205$1_0$125 ==.
                                   7650 ;	../../controller_8051.c:205: 0x00u;
      0025F9 75 90 00         [24] 7651 	mov	_P1,#0x00
                           002545  7652 	C$controller_8051.c$211$1_0$125 ==.
                                   7653 ;	../../controller_8051.c:211: test_temperature = P2;
      0025FC 85 A0 61         [24] 7654 	mov	_test_temperature,_P2
                           002548  7655 	C$controller_8051.c$216$2_0$125 ==.
                                   7656 ;	../../controller_8051.c:216: );
      0025FF 85 61 82         [24] 7657 	mov	dpl, _test_temperature
      002602 12 29 B8         [24] 7658 	lcall	___uchar2fs
      002605 12 23 E0         [24] 7659 	lcall	_calculate_fan_speed
      002608 85 82 63         [24] 7660 	mov	_test_fan_speed,dpl
      00260B 85 83 64         [24] 7661 	mov	(_test_fan_speed + 1),dph
      00260E 85 F0 65         [24] 7662 	mov	(_test_fan_speed + 2),b
      002611 F5 66            [12] 7663 	mov	(_test_fan_speed + 3),a
                           00255C  7664 	C$controller_8051.c$220$1_0$125 ==.
                                   7665 ;	../../controller_8051.c:220: test_fan_speed
      002613 85 63 82         [24] 7666 	mov	dpl, _test_fan_speed
      002616 85 64 83         [24] 7667 	mov	dph, (_test_fan_speed + 1)
      002619 85 65 F0         [24] 7668 	mov	b, (_test_fan_speed + 2)
      00261C E5 66            [12] 7669 	mov	a, (_test_fan_speed + 3)
      00261E 12 25 51         [24] 7670 	lcall	_fan_speed_to_pwm
      002621 85 82 62         [24] 7671 	mov	_test_pwm,dpl
                           00256D  7672 	C$controller_8051.c$227$1_0$125 ==.
                                   7673 ;	../../controller_8051.c:227: test_pwm;
      002624 85 62 90         [24] 7674 	mov	_P1,_test_pwm
                           002570  7675 	C$controller_8051.c$233$1_0$125 ==.
                                   7676 ;	../../controller_8051.c:233: 0xAAu;
      002627 75 80 AA         [24] 7677 	mov	_P0,#0xaa
      00262A                       7678 00103$:
      00262A 80 FE            [24] 7679 	sjmp	00103$
                           002575  7680 	C$controller_8051.c$238$2_0$125 ==.
                                   7681 ;	../../controller_8051.c:238: }
                           002575  7682 	C$controller_8051.c$238$2_0$125 ==.
                           002575  7683 	XG$main$0$0 ==.
      00262C 22               [24] 7684 	ret
                                   7685 	.area CSEG    (CODE)
                                   7686 	.area CONST   (CODE)
                                   7687 	.area CONST   (CODE)
                           000000  7688 Fcontroller_8051$hedges$0_0$0 == .
      002A56                       7689 _hedges:
      002A56 01                    7690 	.db #0x01	; 1
      002A57 02                    7691 	.db #0x02	; 2
      002A58 03                    7692 	.db #0x03	; 3
                                   7693 	.area CSEG    (CODE)
                           002576  7694 Fcontroller_8051$__str_0$0_0$0 == .
                                   7695 	.area CONST   (CODE)
      002A59                       7696 ___str_0:
      002A59 66 61 6E 5F 73 6C 6F  7697 	.ascii "fan_slow"
             77
      002A61 00                    7698 	.db 0x00
                                   7699 	.area CSEG    (CODE)
                           002576  7700 Fcontroller_8051$__str_1$0_0$0 == .
                                   7701 	.area CONST   (CODE)
      002A62                       7702 ___str_1:
      002A62 66 61 6E 5F 66 61 73  7703 	.ascii "fan_fast"
             74
      002A6A 00                    7704 	.db 0x00
                                   7705 	.area CSEG    (CODE)
                                   7706 	.area XINIT   (CODE)
                                   7707 	.area CABS    (ABS,CODE)
