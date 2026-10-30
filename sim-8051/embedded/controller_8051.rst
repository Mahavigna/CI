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
                                    140 	.globl _fuzzy_interpolate_membership
                                    141 	.globl _fuzzy_function_array
                                    142 	.globl _fuzzy_rules_create
                                    143 	.globl _fuzzy_rules_add
                                    144 	.globl _fuzzy_rules_defuzzify_method
                                    145 	.globl _fuzzy_rules_defuzzify
                                    146 	.globl _fuzzy_rules_cog
                                    147 	.globl _fuzzy_rules_free
                                    148 ;--------------------------------------------------------
                                    149 ; special function registers
                                    150 ;--------------------------------------------------------
                                    151 	.area RSEG    (ABS,DATA)
      000000                        152 	.org 0x0000
                           000080   153 G$P0$0_0$0 == 0x0080
                           000080   154 _P0	=	0x0080
                           000081   155 G$SP$0_0$0 == 0x0081
                           000081   156 _SP	=	0x0081
                           000082   157 G$DPL$0_0$0 == 0x0082
                           000082   158 _DPL	=	0x0082
                           000083   159 G$DPH$0_0$0 == 0x0083
                           000083   160 _DPH	=	0x0083
                           000087   161 G$PCON$0_0$0 == 0x0087
                           000087   162 _PCON	=	0x0087
                           000088   163 G$TCON$0_0$0 == 0x0088
                           000088   164 _TCON	=	0x0088
                           000089   165 G$TMOD$0_0$0 == 0x0089
                           000089   166 _TMOD	=	0x0089
                           00008A   167 G$TL0$0_0$0 == 0x008a
                           00008A   168 _TL0	=	0x008a
                           00008B   169 G$TL1$0_0$0 == 0x008b
                           00008B   170 _TL1	=	0x008b
                           00008C   171 G$TH0$0_0$0 == 0x008c
                           00008C   172 _TH0	=	0x008c
                           00008D   173 G$TH1$0_0$0 == 0x008d
                           00008D   174 _TH1	=	0x008d
                           000090   175 G$P1$0_0$0 == 0x0090
                           000090   176 _P1	=	0x0090
                           000098   177 G$SCON$0_0$0 == 0x0098
                           000098   178 _SCON	=	0x0098
                           000099   179 G$SBUF$0_0$0 == 0x0099
                           000099   180 _SBUF	=	0x0099
                           0000A0   181 G$P2$0_0$0 == 0x00a0
                           0000A0   182 _P2	=	0x00a0
                           0000A8   183 G$IE$0_0$0 == 0x00a8
                           0000A8   184 _IE	=	0x00a8
                           0000B0   185 G$P3$0_0$0 == 0x00b0
                           0000B0   186 _P3	=	0x00b0
                           0000B8   187 G$IP$0_0$0 == 0x00b8
                           0000B8   188 _IP	=	0x00b8
                           0000D0   189 G$PSW$0_0$0 == 0x00d0
                           0000D0   190 _PSW	=	0x00d0
                           0000E0   191 G$ACC$0_0$0 == 0x00e0
                           0000E0   192 _ACC	=	0x00e0
                           0000F0   193 G$B$0_0$0 == 0x00f0
                           0000F0   194 _B	=	0x00f0
                           0000C8   195 G$T2CON$0_0$0 == 0x00c8
                           0000C8   196 _T2CON	=	0x00c8
                           0000CA   197 G$RCAP2L$0_0$0 == 0x00ca
                           0000CA   198 _RCAP2L	=	0x00ca
                           0000CB   199 G$RCAP2H$0_0$0 == 0x00cb
                           0000CB   200 _RCAP2H	=	0x00cb
                           0000CC   201 G$TL2$0_0$0 == 0x00cc
                           0000CC   202 _TL2	=	0x00cc
                           0000CD   203 G$TH2$0_0$0 == 0x00cd
                           0000CD   204 _TH2	=	0x00cd
                                    205 ;--------------------------------------------------------
                                    206 ; special function bits
                                    207 ;--------------------------------------------------------
                                    208 	.area RSEG    (ABS,DATA)
      000000                        209 	.org 0x0000
                           000080   210 G$P0_0$0_0$0 == 0x0080
                           000080   211 _P0_0	=	0x0080
                           000081   212 G$P0_1$0_0$0 == 0x0081
                           000081   213 _P0_1	=	0x0081
                           000082   214 G$P0_2$0_0$0 == 0x0082
                           000082   215 _P0_2	=	0x0082
                           000083   216 G$P0_3$0_0$0 == 0x0083
                           000083   217 _P0_3	=	0x0083
                           000084   218 G$P0_4$0_0$0 == 0x0084
                           000084   219 _P0_4	=	0x0084
                           000085   220 G$P0_5$0_0$0 == 0x0085
                           000085   221 _P0_5	=	0x0085
                           000086   222 G$P0_6$0_0$0 == 0x0086
                           000086   223 _P0_6	=	0x0086
                           000087   224 G$P0_7$0_0$0 == 0x0087
                           000087   225 _P0_7	=	0x0087
                           000088   226 G$IT0$0_0$0 == 0x0088
                           000088   227 _IT0	=	0x0088
                           000089   228 G$IE0$0_0$0 == 0x0089
                           000089   229 _IE0	=	0x0089
                           00008A   230 G$IT1$0_0$0 == 0x008a
                           00008A   231 _IT1	=	0x008a
                           00008B   232 G$IE1$0_0$0 == 0x008b
                           00008B   233 _IE1	=	0x008b
                           00008C   234 G$TR0$0_0$0 == 0x008c
                           00008C   235 _TR0	=	0x008c
                           00008D   236 G$TF0$0_0$0 == 0x008d
                           00008D   237 _TF0	=	0x008d
                           00008E   238 G$TR1$0_0$0 == 0x008e
                           00008E   239 _TR1	=	0x008e
                           00008F   240 G$TF1$0_0$0 == 0x008f
                           00008F   241 _TF1	=	0x008f
                           000090   242 G$P1_0$0_0$0 == 0x0090
                           000090   243 _P1_0	=	0x0090
                           000091   244 G$P1_1$0_0$0 == 0x0091
                           000091   245 _P1_1	=	0x0091
                           000092   246 G$P1_2$0_0$0 == 0x0092
                           000092   247 _P1_2	=	0x0092
                           000093   248 G$P1_3$0_0$0 == 0x0093
                           000093   249 _P1_3	=	0x0093
                           000094   250 G$P1_4$0_0$0 == 0x0094
                           000094   251 _P1_4	=	0x0094
                           000095   252 G$P1_5$0_0$0 == 0x0095
                           000095   253 _P1_5	=	0x0095
                           000096   254 G$P1_6$0_0$0 == 0x0096
                           000096   255 _P1_6	=	0x0096
                           000097   256 G$P1_7$0_0$0 == 0x0097
                           000097   257 _P1_7	=	0x0097
                           000098   258 G$RI$0_0$0 == 0x0098
                           000098   259 _RI	=	0x0098
                           000099   260 G$TI$0_0$0 == 0x0099
                           000099   261 _TI	=	0x0099
                           00009A   262 G$RB8$0_0$0 == 0x009a
                           00009A   263 _RB8	=	0x009a
                           00009B   264 G$TB8$0_0$0 == 0x009b
                           00009B   265 _TB8	=	0x009b
                           00009C   266 G$REN$0_0$0 == 0x009c
                           00009C   267 _REN	=	0x009c
                           00009D   268 G$SM2$0_0$0 == 0x009d
                           00009D   269 _SM2	=	0x009d
                           00009E   270 G$SM1$0_0$0 == 0x009e
                           00009E   271 _SM1	=	0x009e
                           00009F   272 G$SM0$0_0$0 == 0x009f
                           00009F   273 _SM0	=	0x009f
                           0000A0   274 G$P2_0$0_0$0 == 0x00a0
                           0000A0   275 _P2_0	=	0x00a0
                           0000A1   276 G$P2_1$0_0$0 == 0x00a1
                           0000A1   277 _P2_1	=	0x00a1
                           0000A2   278 G$P2_2$0_0$0 == 0x00a2
                           0000A2   279 _P2_2	=	0x00a2
                           0000A3   280 G$P2_3$0_0$0 == 0x00a3
                           0000A3   281 _P2_3	=	0x00a3
                           0000A4   282 G$P2_4$0_0$0 == 0x00a4
                           0000A4   283 _P2_4	=	0x00a4
                           0000A5   284 G$P2_5$0_0$0 == 0x00a5
                           0000A5   285 _P2_5	=	0x00a5
                           0000A6   286 G$P2_6$0_0$0 == 0x00a6
                           0000A6   287 _P2_6	=	0x00a6
                           0000A7   288 G$P2_7$0_0$0 == 0x00a7
                           0000A7   289 _P2_7	=	0x00a7
                           0000A8   290 G$EX0$0_0$0 == 0x00a8
                           0000A8   291 _EX0	=	0x00a8
                           0000A9   292 G$ET0$0_0$0 == 0x00a9
                           0000A9   293 _ET0	=	0x00a9
                           0000AA   294 G$EX1$0_0$0 == 0x00aa
                           0000AA   295 _EX1	=	0x00aa
                           0000AB   296 G$ET1$0_0$0 == 0x00ab
                           0000AB   297 _ET1	=	0x00ab
                           0000AC   298 G$ES$0_0$0 == 0x00ac
                           0000AC   299 _ES	=	0x00ac
                           0000AF   300 G$EA$0_0$0 == 0x00af
                           0000AF   301 _EA	=	0x00af
                           0000B0   302 G$P3_0$0_0$0 == 0x00b0
                           0000B0   303 _P3_0	=	0x00b0
                           0000B1   304 G$P3_1$0_0$0 == 0x00b1
                           0000B1   305 _P3_1	=	0x00b1
                           0000B2   306 G$P3_2$0_0$0 == 0x00b2
                           0000B2   307 _P3_2	=	0x00b2
                           0000B3   308 G$P3_3$0_0$0 == 0x00b3
                           0000B3   309 _P3_3	=	0x00b3
                           0000B4   310 G$P3_4$0_0$0 == 0x00b4
                           0000B4   311 _P3_4	=	0x00b4
                           0000B5   312 G$P3_5$0_0$0 == 0x00b5
                           0000B5   313 _P3_5	=	0x00b5
                           0000B6   314 G$P3_6$0_0$0 == 0x00b6
                           0000B6   315 _P3_6	=	0x00b6
                           0000B7   316 G$P3_7$0_0$0 == 0x00b7
                           0000B7   317 _P3_7	=	0x00b7
                           0000B0   318 G$RXD$0_0$0 == 0x00b0
                           0000B0   319 _RXD	=	0x00b0
                           0000B1   320 G$TXD$0_0$0 == 0x00b1
                           0000B1   321 _TXD	=	0x00b1
                           0000B2   322 G$INT0$0_0$0 == 0x00b2
                           0000B2   323 _INT0	=	0x00b2
                           0000B3   324 G$INT1$0_0$0 == 0x00b3
                           0000B3   325 _INT1	=	0x00b3
                           0000B4   326 G$T0$0_0$0 == 0x00b4
                           0000B4   327 _T0	=	0x00b4
                           0000B5   328 G$T1$0_0$0 == 0x00b5
                           0000B5   329 _T1	=	0x00b5
                           0000B6   330 G$WR$0_0$0 == 0x00b6
                           0000B6   331 _WR	=	0x00b6
                           0000B7   332 G$RD$0_0$0 == 0x00b7
                           0000B7   333 _RD	=	0x00b7
                           0000B8   334 G$PX0$0_0$0 == 0x00b8
                           0000B8   335 _PX0	=	0x00b8
                           0000B9   336 G$PT0$0_0$0 == 0x00b9
                           0000B9   337 _PT0	=	0x00b9
                           0000BA   338 G$PX1$0_0$0 == 0x00ba
                           0000BA   339 _PX1	=	0x00ba
                           0000BB   340 G$PT1$0_0$0 == 0x00bb
                           0000BB   341 _PT1	=	0x00bb
                           0000BC   342 G$PS$0_0$0 == 0x00bc
                           0000BC   343 _PS	=	0x00bc
                           0000D0   344 G$P$0_0$0 == 0x00d0
                           0000D0   345 _P	=	0x00d0
                           0000D1   346 G$F1$0_0$0 == 0x00d1
                           0000D1   347 _F1	=	0x00d1
                           0000D2   348 G$OV$0_0$0 == 0x00d2
                           0000D2   349 _OV	=	0x00d2
                           0000D3   350 G$RS0$0_0$0 == 0x00d3
                           0000D3   351 _RS0	=	0x00d3
                           0000D4   352 G$RS1$0_0$0 == 0x00d4
                           0000D4   353 _RS1	=	0x00d4
                           0000D5   354 G$F0$0_0$0 == 0x00d5
                           0000D5   355 _F0	=	0x00d5
                           0000D6   356 G$AC$0_0$0 == 0x00d6
                           0000D6   357 _AC	=	0x00d6
                           0000D7   358 G$CY$0_0$0 == 0x00d7
                           0000D7   359 _CY	=	0x00d7
                           0000AD   360 G$ET2$0_0$0 == 0x00ad
                           0000AD   361 _ET2	=	0x00ad
                           0000BD   362 G$PT2$0_0$0 == 0x00bd
                           0000BD   363 _PT2	=	0x00bd
                           0000C8   364 G$T2CON_0$0_0$0 == 0x00c8
                           0000C8   365 _T2CON_0	=	0x00c8
                           0000C9   366 G$T2CON_1$0_0$0 == 0x00c9
                           0000C9   367 _T2CON_1	=	0x00c9
                           0000CA   368 G$T2CON_2$0_0$0 == 0x00ca
                           0000CA   369 _T2CON_2	=	0x00ca
                           0000CB   370 G$T2CON_3$0_0$0 == 0x00cb
                           0000CB   371 _T2CON_3	=	0x00cb
                           0000CC   372 G$T2CON_4$0_0$0 == 0x00cc
                           0000CC   373 _T2CON_4	=	0x00cc
                           0000CD   374 G$T2CON_5$0_0$0 == 0x00cd
                           0000CD   375 _T2CON_5	=	0x00cd
                           0000CE   376 G$T2CON_6$0_0$0 == 0x00ce
                           0000CE   377 _T2CON_6	=	0x00ce
                           0000CF   378 G$T2CON_7$0_0$0 == 0x00cf
                           0000CF   379 _T2CON_7	=	0x00cf
                           0000C8   380 G$CP_RL2$0_0$0 == 0x00c8
                           0000C8   381 _CP_RL2	=	0x00c8
                           0000C9   382 G$C_T2$0_0$0 == 0x00c9
                           0000C9   383 _C_T2	=	0x00c9
                           0000CA   384 G$TR2$0_0$0 == 0x00ca
                           0000CA   385 _TR2	=	0x00ca
                           0000CB   386 G$EXEN2$0_0$0 == 0x00cb
                           0000CB   387 _EXEN2	=	0x00cb
                           0000CC   388 G$TCLK$0_0$0 == 0x00cc
                           0000CC   389 _TCLK	=	0x00cc
                           0000CD   390 G$RCLK$0_0$0 == 0x00cd
                           0000CD   391 _RCLK	=	0x00cd
                           0000CE   392 G$EXF2$0_0$0 == 0x00ce
                           0000CE   393 _EXF2	=	0x00ce
                           0000CF   394 G$TF2$0_0$0 == 0x00cf
                           0000CF   395 _TF2	=	0x00cf
                                    396 ;--------------------------------------------------------
                                    397 ; overlayable register banks
                                    398 ;--------------------------------------------------------
                                    399 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        400 	.ds 8
                                    401 ;--------------------------------------------------------
                                    402 ; overlayable bit register bank
                                    403 ;--------------------------------------------------------
                                    404 	.area BIT_BANK	(REL,OVR,DATA)
      000020                        405 bits:
      000020                        406 	.ds 1
                           008000   407 	b0 = bits[0]
                           008100   408 	b1 = bits[1]
                           008200   409 	b2 = bits[2]
                           008300   410 	b3 = bits[3]
                           008400   411 	b4 = bits[4]
                           008500   412 	b5 = bits[5]
                           008600   413 	b6 = bits[6]
                           008700   414 	b7 = bits[7]
                                    415 ;--------------------------------------------------------
                                    416 ; internal ram data
                                    417 ;--------------------------------------------------------
                                    418 	.area DSEG    (DATA)
                           000000   419 Fcontroller_8051$fuzzy_values_buffer$0_0$0==.
      000021                        420 _fuzzy_values_buffer:
      000021                        421 	.ds 64
                           000040   422 G$test_temperature$0_0$0==.
      000061                        423 _test_temperature::
      000061                        424 	.ds 1
                           000041   425 G$test_pwm$0_0$0==.
      000062                        426 _test_pwm::
      000062                        427 	.ds 1
                           000042   428 G$test_fan_speed$0_0$0==.
      000063                        429 _test_fan_speed::
      000063                        430 	.ds 4
                                    431 ;--------------------------------------------------------
                                    432 ; overlayable items in internal ram
                                    433 ;--------------------------------------------------------
                                    434 ;--------------------------------------------------------
                                    435 ; Stack segment in internal ram
                                    436 ;--------------------------------------------------------
                                    437 	.area SSEG
      000067                        438 __start__stack:
      000067                        439 	.ds	1
                                    440 
                                    441 ;--------------------------------------------------------
                                    442 ; indirectly addressable internal ram data
                                    443 ;--------------------------------------------------------
                                    444 	.area ISEG    (DATA)
                                    445 ;--------------------------------------------------------
                                    446 ; absolute internal ram data
                                    447 ;--------------------------------------------------------
                                    448 	.area IABS    (ABS,DATA)
                                    449 	.area IABS    (ABS,DATA)
                                    450 ;--------------------------------------------------------
                                    451 ; bit data
                                    452 ;--------------------------------------------------------
                                    453 	.area BSEG    (BIT)
                                    454 ;--------------------------------------------------------
                                    455 ; paged external ram data
                                    456 ;--------------------------------------------------------
                                    457 	.area PSEG    (PAG,XDATA)
                                    458 ;--------------------------------------------------------
                                    459 ; uninitialized external ram data
                                    460 ;--------------------------------------------------------
                                    461 	.area XSEG    (XDATA)
                                    462 ;--------------------------------------------------------
                                    463 ; absolute external ram data
                                    464 ;--------------------------------------------------------
                                    465 	.area XABS    (ABS,XDATA)
                                    466 ;--------------------------------------------------------
                                    467 ; initialized external ram data
                                    468 ;--------------------------------------------------------
                                    469 	.area XISEG   (XDATA)
                                    470 	.area HOME    (CODE)
                                    471 	.area GSINIT0 (CODE)
                                    472 	.area GSINIT1 (CODE)
                                    473 	.area GSINIT2 (CODE)
                                    474 	.area GSINIT3 (CODE)
                                    475 	.area GSINIT4 (CODE)
                                    476 	.area GSINIT5 (CODE)
                                    477 	.area GSINIT  (CODE)
                                    478 	.area GSFINAL (CODE)
                                    479 	.area CSEG    (CODE)
                                    480 ;--------------------------------------------------------
                                    481 ; interrupt vector
                                    482 ;--------------------------------------------------------
                                    483 	.area HOME    (CODE)
      000000                        484 __interrupt_vect:
      000000 02 00 4C         [24]  485 	ljmp	__sdcc_gsinit_startup
                                    486 ; restartable atomic support routines
      000003                        487 	.ds	5
      000008                        488 sdcc_atomic_exchange_rollback_start::
      000008 00               [12]  489 	nop
      000009 00               [12]  490 	nop
      00000A                        491 sdcc_atomic_exchange_pdata_impl:
      00000A E2               [24]  492 	movx	a, @r0
      00000B FB               [12]  493 	mov	r3, a
      00000C EA               [12]  494 	mov	a, r2
      00000D F2               [24]  495 	movx	@r0, a
      00000E 80 2C            [24]  496 	sjmp	sdcc_atomic_exchange_exit
      000010 00               [12]  497 	nop
      000011 00               [12]  498 	nop
      000012                        499 sdcc_atomic_exchange_xdata_impl:
      000012 E0               [24]  500 	movx	a, @dptr
      000013 FB               [12]  501 	mov	r3, a
      000014 EA               [12]  502 	mov	a, r2
      000015 F0               [24]  503 	movx	@dptr, a
      000016 80 24            [24]  504 	sjmp	sdcc_atomic_exchange_exit
      000018                        505 sdcc_atomic_compare_exchange_idata_impl:
      000018 E6               [12]  506 	mov	a, @r0
      000019 B5 02 02         [24]  507 	cjne	a, ar2, .+#5
      00001C EB               [12]  508 	mov	a, r3
      00001D F6               [12]  509 	mov	@r0, a
      00001E 22               [24]  510 	ret
      00001F 00               [12]  511 	nop
      000020                        512 sdcc_atomic_compare_exchange_pdata_impl:
      000020 E2               [24]  513 	movx	a, @r0
      000021 B5 02 02         [24]  514 	cjne	a, ar2, .+#5
      000024 EB               [12]  515 	mov	a, r3
      000025 F2               [24]  516 	movx	@r0, a
      000026 22               [24]  517 	ret
      000027 00               [12]  518 	nop
      000028                        519 sdcc_atomic_compare_exchange_xdata_impl:
      000028 E0               [24]  520 	movx	a, @dptr
      000029 B5 02 02         [24]  521 	cjne	a, ar2, .+#5
      00002C EB               [12]  522 	mov	a, r3
      00002D F0               [24]  523 	movx	@dptr, a
      00002E 22               [24]  524 	ret
      00002F                        525 sdcc_atomic_exchange_rollback_end::
                                    526 
      00002F                        527 sdcc_atomic_exchange_gptr_impl::
      00002F 30 F6 E0         [24]  528 	jnb	b.6, sdcc_atomic_exchange_xdata_impl
      000032 A8 82            [24]  529 	mov	r0, dpl
      000034 20 F5 D3         [24]  530 	jb	b.5, sdcc_atomic_exchange_pdata_impl
      000037                        531 sdcc_atomic_exchange_idata_impl:
      000037 EA               [12]  532 	mov	a, r2
      000038 C6               [12]  533 	xch	a, @r0
      000039 F5 82            [12]  534 	mov	dpl, a
      00003B 22               [24]  535 	ret
      00003C                        536 sdcc_atomic_exchange_exit:
      00003C 8B 82            [24]  537 	mov	dpl, r3
      00003E 22               [24]  538 	ret
      00003F                        539 sdcc_atomic_compare_exchange_gptr_impl::
      00003F 30 F6 E6         [24]  540 	jnb	b.6, sdcc_atomic_compare_exchange_xdata_impl
      000042 A8 82            [24]  541 	mov	r0, dpl
      000044 20 F5 D9         [24]  542 	jb	b.5, sdcc_atomic_compare_exchange_pdata_impl
      000047 80 CF            [24]  543 	sjmp	sdcc_atomic_compare_exchange_idata_impl
                                    544 ;--------------------------------------------------------
                                    545 ; global & static initialisations
                                    546 ;--------------------------------------------------------
                                    547 	.area HOME    (CODE)
                                    548 	.area GSINIT  (CODE)
                                    549 	.area GSFINAL (CODE)
                                    550 	.area GSINIT  (CODE)
                                    551 	.globl __sdcc_gsinit_startup
                                    552 	.globl __sdcc_program_startup
                                    553 	.globl __start__stack
                                    554 	.globl __mcs51_genXINIT
                                    555 	.globl __mcs51_genXRAMCLEAR
                                    556 	.globl __mcs51_genRAMCLEAR
                           000000   557 	C$controller_8051.c$25$2_0$138 ==.
                                    558 ;	../../controller_8051.c:25: volatile unsigned char test_temperature = 0u;
      0000A5 75 61 00         [24]  559 	mov	_test_temperature,#0x00
                           000003   560 	C$controller_8051.c$26$2_0$138 ==.
                                    561 ;	../../controller_8051.c:26: volatile unsigned char test_pwm = 0u;
      0000A8 75 62 00         [24]  562 	mov	_test_pwm,#0x00
                           000006   563 	C$controller_8051.c$27$2_0$138 ==.
                                    564 ;	../../controller_8051.c:27: volatile float test_fan_speed = 0.0f;
      0000AB E4               [12]  565 	clr	a
      0000AC F5 63            [12]  566 	mov	_test_fan_speed,a
      0000AE F5 64            [12]  567 	mov	(_test_fan_speed + 1),a
      0000B0 F5 65            [12]  568 	mov	(_test_fan_speed + 2),a
      0000B2 F5 66            [12]  569 	mov	(_test_fan_speed + 3),a
                                    570 	.area GSFINAL (CODE)
      0000B4 02 00 49         [24]  571 	ljmp	__sdcc_program_startup
                                    572 ;--------------------------------------------------------
                                    573 ; Home
                                    574 ;--------------------------------------------------------
                                    575 	.area HOME    (CODE)
                                    576 	.area HOME    (CODE)
      000049                        577 __sdcc_program_startup:
      000049 02 2A 89         [24]  578 	ljmp	_main
                                    579 ;	return from main will return to caller
                                    580 ;--------------------------------------------------------
                                    581 ; code
                                    582 ;--------------------------------------------------------
                                    583 	.area CSEG    (CODE)
                                    584 ;------------------------------------------------------------
                                    585 ;Allocation info for local variables in function 'fuzzy_values_initialize'
                                    586 ;------------------------------------------------------------
                                    587 ;index         Allocated to registers r6 r7 
                                    588 ;------------------------------------------------------------
                           000000   589 	Fcontroller_8051$fuzzy_values_initialize$0$0 ==.
                           000000   590 	C$fuzzy.h$102$0_0$3 ==.
                                    591 ;	../../fuzzy.h:102: static float *fuzzy_values_initialize(void)
                                    592 ;	-----------------------------------------
                                    593 ;	 function fuzzy_values_initialize
                                    594 ;	-----------------------------------------
      0000B7                        595 _fuzzy_values_initialize:
                           000007   596 	ar7 = 0x07
                           000006   597 	ar6 = 0x06
                           000005   598 	ar5 = 0x05
                           000004   599 	ar4 = 0x04
                           000003   600 	ar3 = 0x03
                           000002   601 	ar2 = 0x02
                           000001   602 	ar1 = 0x01
                           000000   603 	ar0 = 0x00
                           000000   604 	C$fuzzy.h$107$3_0$5 ==.
                                    605 ;	../../fuzzy.h:107: index = 0u;
      0000B7 7E 00            [12]  606 	mov	r6,#0x00
      0000B9 7F 00            [12]  607 	mov	r7,#0x00
      0000BB                        608 00102$:
                           000004   609 	C$fuzzy.h$111$3_0$5 ==.
                                    610 ;	../../fuzzy.h:111: fuzzy_values_buffer[index] = 0.0f;
      0000BB EE               [12]  611 	mov	a,r6
      0000BC 2E               [12]  612 	add	a,r6
      0000BD FC               [12]  613 	mov	r4,a
      0000BE EF               [12]  614 	mov	a,r7
      0000BF 33               [12]  615 	rlc	a
      0000C0 FD               [12]  616 	mov	r5,a
      0000C1 EC               [12]  617 	mov	a,r4
      0000C2 2C               [12]  618 	add	a,r4
      0000C3 FC               [12]  619 	mov	r4,a
      0000C4 ED               [12]  620 	mov	a,r5
      0000C5 33               [12]  621 	rlc	a
      0000C6 EC               [12]  622 	mov	a,r4
      0000C7 24 21            [12]  623 	add	a, #_fuzzy_values_buffer
      0000C9 F8               [12]  624 	mov	r0,a
      0000CA 76 00            [12]  625 	mov	@r0,#0x00
      0000CC 08               [12]  626 	inc	r0
      0000CD 76 00            [12]  627 	mov	@r0,#0x00
      0000CF 08               [12]  628 	inc	r0
      0000D0 76 00            [12]  629 	mov	@r0,#0x00
      0000D2 08               [12]  630 	inc	r0
      0000D3 76 00            [12]  631 	mov	@r0,#0x00
                           00001E   632 	C$fuzzy.h$109$2_0$4 ==.
                                    633 ;	../../fuzzy.h:109: index++
      0000D5 0E               [12]  634 	inc	r6
      0000D6 BE 00 01         [24]  635 	cjne	r6,#0x00,00119$
      0000D9 0F               [12]  636 	inc	r7
      0000DA                        637 00119$:
                           000023   638 	C$fuzzy.h$108$2_0$4 ==.
                                    639 ;	../../fuzzy.h:108: index < FUZZY_MAX_VALUES;
      0000DA C3               [12]  640 	clr	c
      0000DB EE               [12]  641 	mov	a,r6
      0000DC 94 10            [12]  642 	subb	a,#0x10
      0000DE EF               [12]  643 	mov	a,r7
      0000DF 94 00            [12]  644 	subb	a,#0x00
      0000E1 40 D8            [24]  645 	jc	00102$
                           00002C   646 	C$fuzzy.h$114$1_0$3 ==.
                                    647 ;	../../fuzzy.h:114: return fuzzy_values_buffer;
      0000E3 90 00 21         [24]  648 	mov	dptr,#_fuzzy_values_buffer
      0000E6 75 F0 40         [24]  649 	mov	b, #0x40
                           000032   650 	C$fuzzy.h$115$1_0$3 ==.
                                    651 ;	../../fuzzy.h:115: }
                           000032   652 	C$fuzzy.h$115$1_0$3 ==.
                           000032   653 	XFcontroller_8051$fuzzy_values_initialize$0$0 ==.
      0000E9 22               [24]  654 	ret
                                    655 ;------------------------------------------------------------
                                    656 ;Allocation info for local variables in function 'fuzzy_clamp'
                                    657 ;------------------------------------------------------------
                                    658 ;value         Allocated to registers r4 r5 r6 r7 
                                    659 ;------------------------------------------------------------
                           000033   660 	Fcontroller_8051$fuzzy_clamp$0$0 ==.
                           000033   661 	C$fuzzy.h$727$1_0$22 ==.
                                    662 ;	../../fuzzy.h:727: static float fuzzy_clamp(float value)
                                    663 ;	-----------------------------------------
                                    664 ;	 function fuzzy_clamp
                                    665 ;	-----------------------------------------
      0000EA                        666 _fuzzy_clamp:
      0000EA AC 82            [24]  667 	mov	r4,dpl
      0000EC AD 83            [24]  668 	mov	r5,dph
      0000EE AE F0            [24]  669 	mov	r6,b
      0000F0 FF               [12]  670 	mov	r7,a
                           00003A   671 	C$fuzzy.h$729$1_0$22 ==.
                                    672 ;	../../fuzzy.h:729: if (value < LEVEL_LO) {
      0000F1 C0 07            [24]  673 	push	ar7
      0000F3 C0 06            [24]  674 	push	ar6
      0000F5 C0 05            [24]  675 	push	ar5
      0000F7 C0 04            [24]  676 	push	ar4
      0000F9 E4               [12]  677 	clr	a
      0000FA C0 E0            [24]  678 	push	acc
      0000FC C0 E0            [24]  679 	push	acc
      0000FE C0 E0            [24]  680 	push	acc
      000100 C0 E0            [24]  681 	push	acc
      000102 8C 82            [24]  682 	mov	dpl, r4
      000104 8D 83            [24]  683 	mov	dph, r5
      000106 8E F0            [24]  684 	mov	b, r6
      000108 EF               [12]  685 	mov	a, r7
      000109 12 2B FE         [24]  686 	lcall	___fslt
      00010C AB 82            [24]  687 	mov	r3, dpl
      00010E E5 81            [12]  688 	mov	a,sp
      000110 24 FC            [12]  689 	add	a,#0xfc
      000112 F5 81            [12]  690 	mov	sp,a
      000114 D0 04            [24]  691 	pop	ar4
      000116 D0 05            [24]  692 	pop	ar5
      000118 D0 06            [24]  693 	pop	ar6
      00011A D0 07            [24]  694 	pop	ar7
      00011C EB               [12]  695 	mov	a,r3
      00011D 60 08            [24]  696 	jz	00102$
                           000068   697 	C$fuzzy.h$730$2_0$23 ==.
                                    698 ;	../../fuzzy.h:730: return LEVEL_LO;
      00011F 90 00 00         [24]  699 	mov	dptr,#0x0000
      000122 E4               [12]  700 	clr	a
      000123 F5 F0            [12]  701 	mov	b,a
      000125 80 3F            [24]  702 	sjmp	00105$
      000127                        703 00102$:
                           000070   704 	C$fuzzy.h$733$1_0$22 ==.
                                    705 ;	../../fuzzy.h:733: if (value > LEVEL_HI) {
      000127 C0 07            [24]  706 	push	ar7
      000129 C0 06            [24]  707 	push	ar6
      00012B C0 05            [24]  708 	push	ar5
      00012D C0 04            [24]  709 	push	ar4
      00012F C0 04            [24]  710 	push	ar4
      000131 C0 05            [24]  711 	push	ar5
      000133 C0 06            [24]  712 	push	ar6
      000135 C0 07            [24]  713 	push	ar7
      000137 90 00 00         [24]  714 	mov	dptr,#0x0000
      00013A 75 F0 80         [24]  715 	mov	b, #0x80
      00013D 74 3F            [12]  716 	mov	a, #0x3f
      00013F 12 2B FE         [24]  717 	lcall	___fslt
      000142 AB 82            [24]  718 	mov	r3, dpl
      000144 E5 81            [12]  719 	mov	a,sp
      000146 24 FC            [12]  720 	add	a,#0xfc
      000148 F5 81            [12]  721 	mov	sp,a
      00014A D0 04            [24]  722 	pop	ar4
      00014C D0 05            [24]  723 	pop	ar5
      00014E D0 06            [24]  724 	pop	ar6
      000150 D0 07            [24]  725 	pop	ar7
      000152 EB               [12]  726 	mov	a,r3
      000153 60 0A            [24]  727 	jz	00104$
                           00009E   728 	C$fuzzy.h$734$2_0$24 ==.
                                    729 ;	../../fuzzy.h:734: return LEVEL_HI;
      000155 90 00 00         [24]  730 	mov	dptr,#0x0000
      000158 75 F0 80         [24]  731 	mov	b, #0x80
      00015B 74 3F            [12]  732 	mov	a, #0x3f
      00015D 80 07            [24]  733 	sjmp	00105$
      00015F                        734 00104$:
                           0000A8   735 	C$fuzzy.h$737$1_0$22 ==.
                                    736 ;	../../fuzzy.h:737: return value;
      00015F 8C 82            [24]  737 	mov	dpl, r4
      000161 8D 83            [24]  738 	mov	dph, r5
      000163 8E F0            [24]  739 	mov	b, r6
      000165 EF               [12]  740 	mov	a, r7
      000166                        741 00105$:
                           0000AF   742 	C$fuzzy.h$738$1_0$22 ==.
                                    743 ;	../../fuzzy.h:738: }
                           0000AF   744 	C$fuzzy.h$738$1_0$22 ==.
                           0000AF   745 	XFcontroller_8051$fuzzy_clamp$0$0 ==.
      000166 22               [24]  746 	ret
                                    747 ;------------------------------------------------------------
                                    748 ;Allocation info for local variables in function 'fuzzy_not'
                                    749 ;------------------------------------------------------------
                                    750 ;membership    Allocated to registers r4 r5 r6 r7 
                                    751 ;------------------------------------------------------------
                           0000B0   752 	G$fuzzy_not$0$0 ==.
                           0000B0   753 	C$fuzzy.h$743$1_0$26 ==.
                                    754 ;	../../fuzzy.h:743: float fuzzy_not(
                                    755 ;	-----------------------------------------
                                    756 ;	 function fuzzy_not
                                    757 ;	-----------------------------------------
      000167                        758 _fuzzy_not:
                           0000B0   759 	C$fuzzy.h$748$1_0$26 ==.
                                    760 ;	../../fuzzy.h:748: fuzzy_clamp( membership
      000167 12 00 EA         [24]  761 	lcall	_fuzzy_clamp
      00016A AC 82            [24]  762 	mov	r4, dpl
      00016C AD 83            [24]  763 	mov	r5, dph
      00016E AE F0            [24]  764 	mov	r6, b
      000170 FF               [12]  765 	mov	r7, a
      000171 C0 04            [24]  766 	push	ar4
      000173 C0 05            [24]  767 	push	ar5
      000175 C0 06            [24]  768 	push	ar6
      000177 C0 07            [24]  769 	push	ar7
      000179 90 00 00         [24]  770 	mov	dptr,#0x0000
      00017C 75 F0 80         [24]  771 	mov	b, #0x80
      00017F 74 3F            [12]  772 	mov	a, #0x3f
      000181 12 2A C3         [24]  773 	lcall	___fssub
      000184 AC 82            [24]  774 	mov	r4, dpl
      000186 AD 83            [24]  775 	mov	r5, dph
      000188 AE F0            [24]  776 	mov	r6, b
      00018A FF               [12]  777 	mov	r7, a
      00018B E5 81            [12]  778 	mov	a,sp
      00018D 24 FC            [12]  779 	add	a,#0xfc
      00018F F5 81            [12]  780 	mov	sp,a
      000191 8C 82            [24]  781 	mov	dpl, r4
      000193 8D 83            [24]  782 	mov	dph, r5
      000195 8E F0            [24]  783 	mov	b, r6
      000197 EF               [12]  784 	mov	a, r7
                           0000E1   785 	C$fuzzy.h$750$1_0$26 ==.
                                    786 ;	../../fuzzy.h:750: }
                           0000E1   787 	C$fuzzy.h$750$1_0$26 ==.
                           0000E1   788 	XG$fuzzy_not$0$0 ==.
      000198 22               [24]  789 	ret
                                    790 ;------------------------------------------------------------
                                    791 ;Allocation info for local variables in function 'fuzzy_apply_hedge'
                                    792 ;------------------------------------------------------------
                                    793 ;hedge         Allocated to stack - _bp -3 +1 
                                    794 ;membership    Allocated to stack - _bp +1 +4 
                                    795 ;result        Allocated to registers r2 r3 r6 r7 
                                    796 ;------------------------------------------------------------
                           0000E2   797 	Fcontroller_8051$fuzzy_apply_hedge$0$0 ==.
                           0000E2   798 	C$fuzzy.h$760$1_0$28 ==.
                                    799 ;	../../fuzzy.h:760: static float fuzzy_apply_hedge(
                                    800 ;	-----------------------------------------
                                    801 ;	 function fuzzy_apply_hedge
                                    802 ;	-----------------------------------------
      000199                        803 _fuzzy_apply_hedge:
      000199 C0 08            [24]  804 	push	_bp
      00019B 85 81 08         [24]  805 	mov	_bp,sp
      00019E AC 82            [24]  806 	mov	r4,dpl
      0001A0 AD 83            [24]  807 	mov	r5,dph
      0001A2 AE F0            [24]  808 	mov	r6,b
      0001A4 FF               [12]  809 	mov	r7,a
      0001A5 E5 81            [12]  810 	mov	a,sp
      0001A7 24 04            [12]  811 	add	a,#0x04
      0001A9 F5 81            [12]  812 	mov	sp,a
                           0000F4   813 	C$fuzzy.h$766$1_0$28 ==.
                                    814 ;	../../fuzzy.h:766: fuzzy_clamp( membership
      0001AB 8C 82            [24]  815 	mov	dpl, r4
      0001AD 8D 83            [24]  816 	mov	dph, r5
      0001AF 8E F0            [24]  817 	mov	b, r6
      0001B1 EF               [12]  818 	mov	a, r7
      0001B2 12 00 EA         [24]  819 	lcall	_fuzzy_clamp
      0001B5 A8 08            [24]  820 	mov	r0,_bp
      0001B7 08               [12]  821 	inc	r0
      0001B8 A6 82            [24]  822 	mov	@r0, dpl
      0001BA 08               [12]  823 	inc	r0
      0001BB A6 83            [24]  824 	mov	@r0, dph
      0001BD 08               [12]  825 	inc	r0
      0001BE A6 F0            [24]  826 	mov	@r0, b
      0001C0 08               [12]  827 	inc	r0
      0001C1 F6               [12]  828 	mov	@r0,a
                           00010B   829 	C$fuzzy.h$771$2_0$29 ==.
                                    830 ;	../../fuzzy.h:771: float result =
      0001C2 7A 00            [12]  831 	mov	r2,#0x00
      0001C4 7B 00            [12]  832 	mov	r3,#0x00
      0001C6 7E 80            [12]  833 	mov	r6,#0x80
      0001C8 7F 3F            [12]  834 	mov	r7,#0x3f
                           000113   835 	C$fuzzy.h$774$1_1$29 ==.
                                    836 ;	../../fuzzy.h:774: if (hedge == 0u) {
      0001CA E5 08            [12]  837 	mov	a,_bp
      0001CC 24 FD            [12]  838 	add	a,#0xfd
      0001CE F8               [12]  839 	mov	r0,a
      0001CF E6               [12]  840 	mov	a,@r0
      0001D0 70 07            [24]  841 	jnz	00110$
                           00011B   842 	C$fuzzy.h$775$2_1$30 ==.
                                    843 ;	../../fuzzy.h:775: hedge = 1u;
      0001D2 E5 08            [12]  844 	mov	a,_bp
      0001D4 24 FD            [12]  845 	add	a,#0xfd
      0001D6 F8               [12]  846 	mov	r0,a
      0001D7 76 01            [12]  847 	mov	@r0,#0x01
                           000122   848 	C$fuzzy.h$778$1_1$28 ==.
                                    849 ;	../../fuzzy.h:778: while (hedge > 0u) {
      0001D9                        850 00110$:
      0001D9 E5 08            [12]  851 	mov	a,_bp
      0001DB 24 FD            [12]  852 	add	a,#0xfd
      0001DD F8               [12]  853 	mov	r0,a
      0001DE 86 05            [24]  854 	mov	ar5,@r0
      0001E0                        855 00103$:
      0001E0 ED               [12]  856 	mov	a,r5
      0001E1 60 30            [24]  857 	jz	00105$
                           00012C   858 	C$fuzzy.h$779$1_1$28 ==.
                                    859 ;	../../fuzzy.h:779: result *= membership;
      0001E3 C0 05            [24]  860 	push	ar5
      0001E5 A8 08            [24]  861 	mov	r0,_bp
      0001E7 08               [12]  862 	inc	r0
      0001E8 E6               [12]  863 	mov	a,@r0
      0001E9 C0 E0            [24]  864 	push	acc
      0001EB 08               [12]  865 	inc	r0
      0001EC E6               [12]  866 	mov	a,@r0
      0001ED C0 E0            [24]  867 	push	acc
      0001EF 08               [12]  868 	inc	r0
      0001F0 E6               [12]  869 	mov	a,@r0
      0001F1 C0 E0            [24]  870 	push	acc
      0001F3 08               [12]  871 	inc	r0
      0001F4 E6               [12]  872 	mov	a,@r0
      0001F5 C0 E0            [24]  873 	push	acc
                           000140   874 	C$fuzzy.h$781$1_1$28 ==.
                                    875 ;	../../fuzzy.h:781: hedge--;
      0001F7 8A 82            [24]  876 	mov	dpl, r2
      0001F9 8B 83            [24]  877 	mov	dph, r3
      0001FB 8E F0            [24]  878 	mov	b, r6
      0001FD EF               [12]  879 	mov	a, r7
      0001FE 12 2A CE         [24]  880 	lcall	___fsmul
      000201 AA 82            [24]  881 	mov	r2, dpl
      000203 AB 83            [24]  882 	mov	r3, dph
      000205 AE F0            [24]  883 	mov	r6, b
      000207 FF               [12]  884 	mov	r7, a
      000208 E5 81            [12]  885 	mov	a,sp
      00020A 24 FC            [12]  886 	add	a,#0xfc
      00020C F5 81            [12]  887 	mov	sp,a
      00020E D0 05            [24]  888 	pop	ar5
      000210 1D               [12]  889 	dec	r5
      000211 80 CD            [24]  890 	sjmp	00103$
      000213                        891 00105$:
                           00015C   892 	C$fuzzy.h$785$1_1$29 ==.
                                    893 ;	../../fuzzy.h:785: result
      000213 8A 82            [24]  894 	mov	dpl, r2
      000215 8B 83            [24]  895 	mov	dph, r3
      000217 8E F0            [24]  896 	mov	b, r6
      000219 EF               [12]  897 	mov	a, r7
      00021A 12 00 EA         [24]  898 	lcall	_fuzzy_clamp
                           000166   899 	C$fuzzy.h$801$1_1$28 ==.
                                    900 ;	../../fuzzy.h:801: }
      00021D 85 08 81         [24]  901 	mov	sp,_bp
      000220 D0 08            [24]  902 	pop	_bp
                           00016B   903 	C$fuzzy.h$801$1_1$28 ==.
                           00016B   904 	XFcontroller_8051$fuzzy_apply_hedge$0$0 ==.
      000222 22               [24]  905 	ret
                                    906 ;------------------------------------------------------------
                                    907 ;Allocation info for local variables in function 'fuzzy_and_array'
                                    908 ;------------------------------------------------------------
                                    909 ;count         Allocated to stack - _bp -4 +2 
                                    910 ;args          Allocated to stack - _bp -7 +3 
                                    911 ;method        Allocated to registers r5 
                                    912 ;result        Allocated to stack - _bp +5 +4 
                                    913 ;next          Allocated to stack - _bp +9 +4 
                                    914 ;index         Allocated to stack - _bp +13 +2 
                                    915 ;sloc0         Allocated to stack - _bp +1 +3 
                                    916 ;sloc1         Allocated to stack - _bp +4 +1 
                                    917 ;------------------------------------------------------------
                           00016C   918 	G$fuzzy_and_array$0$0 ==.
                           00016C   919 	C$fuzzy.h$815$1_1$33 ==.
                                    920 ;	../../fuzzy.h:815: float fuzzy_and_array(
                                    921 ;	-----------------------------------------
                                    922 ;	 function fuzzy_and_array
                                    923 ;	-----------------------------------------
      000223                        924 _fuzzy_and_array:
      000223 C0 08            [24]  925 	push	_bp
      000225 E5 81            [12]  926 	mov	a,sp
      000227 F5 08            [12]  927 	mov	_bp,a
      000229 24 0E            [12]  928 	add	a,#0x0e
      00022B F5 81            [12]  929 	mov	sp,a
      00022D AD 82            [24]  930 	mov	r5, dpl
                           000178   931 	C$fuzzy.h$826$1_0$33 ==.
                                    932 ;	../../fuzzy.h:826: args == NULL ||
      00022F E5 08            [12]  933 	mov	a,_bp
      000231 24 F9            [12]  934 	add	a,#0xf9
      000233 F8               [12]  935 	mov	r0,a
      000234 E6               [12]  936 	mov	a,@r0
      000235 08               [12]  937 	inc	r0
      000236 46               [12]  938 	orl	a,@r0
      000237 60 0A            [24]  939 	jz	00101$
                           000182   940 	C$fuzzy.h$827$1_0$33 ==.
                                    941 ;	../../fuzzy.h:827: count == 0u
      000239 E5 08            [12]  942 	mov	a,_bp
      00023B 24 FC            [12]  943 	add	a,#0xfc
      00023D F8               [12]  944 	mov	r0,a
      00023E E6               [12]  945 	mov	a,@r0
      00023F 08               [12]  946 	inc	r0
      000240 46               [12]  947 	orl	a,@r0
      000241 70 0B            [24]  948 	jnz	00102$
      000243                        949 00101$:
                           00018C   950 	C$fuzzy.h$829$2_0$34 ==.
                                    951 ;	../../fuzzy.h:829: return LEVEL_HI;
      000243 90 00 00         [24]  952 	mov	dptr,#0x0000
      000246 75 F0 80         [24]  953 	mov	b, #0x80
      000249 74 3F            [12]  954 	mov	a, #0x3f
      00024B 02 04 BC         [24]  955 	ljmp	00121$
      00024E                        956 00102$:
                           000197   957 	C$fuzzy.h$833$1_0$33 ==.
                                    958 ;	../../fuzzy.h:833: method != FUZZY_LOGIC_STANDARD &&
      00024E ED               [12]  959 	mov	a,r5
      00024F 60 13            [24]  960 	jz	00105$
                           00019A   961 	C$fuzzy.h$834$1_0$33 ==.
                                    962 ;	../../fuzzy.h:834: method != FUZZY_LOGIC_ALGEBRAIC &&
      000251 BD 01 02         [24]  963 	cjne	r5,#0x01,00192$
      000254 80 0E            [24]  964 	sjmp	00105$
      000256                        965 00192$:
                           00019F   966 	C$fuzzy.h$836$1_0$33 ==.
                                    967 ;	../../fuzzy.h:836: ) {
      000256 BD 02 02         [24]  968 	cjne	r5,#0x02,00193$
      000259 80 09            [24]  969 	sjmp	00105$
      00025B                        970 00193$:
                           0001A4   971 	C$fuzzy.h$837$2_0$35 ==.
                                    972 ;	../../fuzzy.h:837: return LEVEL_LO;
      00025B 90 00 00         [24]  973 	mov	dptr,#0x0000
      00025E E4               [12]  974 	clr	a
      00025F F5 F0            [12]  975 	mov	b,a
      000261 02 04 BC         [24]  976 	ljmp	00121$
      000264                        977 00105$:
                           0001AD   978 	C$fuzzy.h$842$1_0$33 ==.
                                    979 ;	../../fuzzy.h:842: args[0]
      000264 E5 08            [12]  980 	mov	a,_bp
      000266 24 F9            [12]  981 	add	a,#0xf9
      000268 F8               [12]  982 	mov	r0,a
      000269 A9 08            [24]  983 	mov	r1,_bp
      00026B 09               [12]  984 	inc	r1
      00026C E6               [12]  985 	mov	a,@r0
      00026D F7               [12]  986 	mov	@r1,a
      00026E 08               [12]  987 	inc	r0
      00026F E6               [12]  988 	mov	a,@r0
      000270 09               [12]  989 	inc	r1
      000271 F7               [12]  990 	mov	@r1,a
      000272 08               [12]  991 	inc	r0
      000273 E6               [12]  992 	mov	a,@r0
      000274 09               [12]  993 	inc	r1
      000275 F7               [12]  994 	mov	@r1,a
      000276 A8 08            [24]  995 	mov	r0,_bp
      000278 08               [12]  996 	inc	r0
      000279 86 82            [24]  997 	mov	dpl,@r0
      00027B 08               [12]  998 	inc	r0
      00027C 86 83            [24]  999 	mov	dph,@r0
      00027E 08               [12] 1000 	inc	r0
      00027F 86 F0            [24] 1001 	mov	b,@r0
      000281 12 2E 2A         [24] 1002 	lcall	__gptrget
      000284 FA               [12] 1003 	mov	r2,a
      000285 A3               [24] 1004 	inc	dptr
      000286 12 2E 2A         [24] 1005 	lcall	__gptrget
      000289 FB               [12] 1006 	mov	r3,a
      00028A A3               [24] 1007 	inc	dptr
      00028B 12 2E 2A         [24] 1008 	lcall	__gptrget
      00028E FE               [12] 1009 	mov	r6,a
      00028F A3               [24] 1010 	inc	dptr
      000290 12 2E 2A         [24] 1011 	lcall	__gptrget
      000293 8A 82            [24] 1012 	mov	dpl,r2
      000295 8B 83            [24] 1013 	mov	dph,r3
      000297 8E F0            [24] 1014 	mov	b,r6
      000299 C0 05            [24] 1015 	push	ar5
      00029B 12 00 EA         [24] 1016 	lcall	_fuzzy_clamp
      00029E C8               [12] 1017 	xch	a,r0
      00029F E5 08            [12] 1018 	mov	a,_bp
      0002A1 24 05            [12] 1019 	add	a,#0x05
      0002A3 C8               [12] 1020 	xch	a,r0
      0002A4 A6 82            [24] 1021 	mov	@r0, dpl
      0002A6 08               [12] 1022 	inc	r0
      0002A7 A6 83            [24] 1023 	mov	@r0, dph
      0002A9 08               [12] 1024 	inc	r0
      0002AA A6 F0            [24] 1025 	mov	@r0, b
      0002AC 08               [12] 1026 	inc	r0
      0002AD F6               [12] 1027 	mov	@r0,a
      0002AE D0 05            [24] 1028 	pop	ar5
                           0001F9  1029 	C$fuzzy.h$846$3_0$37 ==.
                                   1030 ;	../../fuzzy.h:846: index = 1u;
      0002B0 E4               [12] 1031 	clr	a
      0002B1 BD 00 01         [24] 1032 	cjne	r5,#0x00,00194$
      0002B4 04               [12] 1033 	inc	a
      0002B5                       1034 00194$:
      0002B5 FB               [12] 1035 	mov	r3,a
      0002B6 BD 01 03         [24] 1036 	cjne	r5,#0x01,00196$
      0002B9 ED               [12] 1037 	mov	a,r5
      0002BA 80 01            [24] 1038 	sjmp	00197$
      0002BC                       1039 00196$:
      0002BC E4               [12] 1040 	clr	a
      0002BD                       1041 00197$:
      0002BD FA               [12] 1042 	mov	r2,a
      0002BE E5 08            [12] 1043 	mov	a,_bp
      0002C0 24 04            [12] 1044 	add	a,#0x04
      0002C2 F8               [12] 1045 	mov	r0,a
      0002C3 E4               [12] 1046 	clr	a
      0002C4 BD 02 01         [24] 1047 	cjne	r5,#0x02,00198$
      0002C7 04               [12] 1048 	inc	a
      0002C8                       1049 00198$:
      0002C8 F6               [12] 1050 	mov	@r0,a
      0002C9 E5 08            [12] 1051 	mov	a,_bp
      0002CB 24 0D            [12] 1052 	add	a,#0x0d
      0002CD F8               [12] 1053 	mov	r0,a
      0002CE 76 01            [12] 1054 	mov	@r0,#0x01
      0002D0 08               [12] 1055 	inc	r0
      0002D1 76 00            [12] 1056 	mov	@r0,#0x00
      0002D3                       1057 00119$:
                           00021C  1058 	C$fuzzy.h$847$2_0$36 ==.
                                   1059 ;	../../fuzzy.h:847: index < count;
      0002D3 E5 08            [12] 1060 	mov	a,_bp
      0002D5 24 0D            [12] 1061 	add	a,#0x0d
      0002D7 F8               [12] 1062 	mov	r0,a
      0002D8 E5 08            [12] 1063 	mov	a,_bp
      0002DA 24 FC            [12] 1064 	add	a,#0xfc
      0002DC F9               [12] 1065 	mov	r1,a
      0002DD C3               [12] 1066 	clr	c
      0002DE E6               [12] 1067 	mov	a,@r0
      0002DF 97               [12] 1068 	subb	a,@r1
      0002E0 08               [12] 1069 	inc	r0
      0002E1 E6               [12] 1070 	mov	a,@r0
      0002E2 09               [12] 1071 	inc	r1
      0002E3 97               [12] 1072 	subb	a,@r1
      0002E4 40 03            [24] 1073 	jc	00200$
      0002E6 02 04 AA         [24] 1074 	ljmp	00117$
      0002E9                       1075 00200$:
                           000232  1076 	C$fuzzy.h$852$1_0$33 ==.
                                   1077 ;	../../fuzzy.h:852: args[index]
      0002E9 C0 02            [24] 1078 	push	ar2
      0002EB E5 08            [12] 1079 	mov	a,_bp
      0002ED 24 0D            [12] 1080 	add	a,#0x0d
      0002EF F8               [12] 1081 	mov	r0,a
      0002F0 E6               [12] 1082 	mov	a,@r0
      0002F1 26               [12] 1083 	add	a,@r0
      0002F2 FD               [12] 1084 	mov	r5,a
      0002F3 08               [12] 1085 	inc	r0
      0002F4 E6               [12] 1086 	mov	a,@r0
      0002F5 33               [12] 1087 	rlc	a
      0002F6 FC               [12] 1088 	mov	r4,a
      0002F7 ED               [12] 1089 	mov	a,r5
      0002F8 2D               [12] 1090 	add	a,r5
      0002F9 FD               [12] 1091 	mov	r5,a
      0002FA EC               [12] 1092 	mov	a,r4
      0002FB 33               [12] 1093 	rlc	a
      0002FC FC               [12] 1094 	mov	r4,a
      0002FD A8 08            [24] 1095 	mov	r0,_bp
      0002FF 08               [12] 1096 	inc	r0
      000300 ED               [12] 1097 	mov	a,r5
      000301 26               [12] 1098 	add	a, @r0
      000302 FA               [12] 1099 	mov	r2,a
      000303 EC               [12] 1100 	mov	a,r4
      000304 08               [12] 1101 	inc	r0
      000305 36               [12] 1102 	addc	a, @r0
      000306 FC               [12] 1103 	mov	r4,a
      000307 08               [12] 1104 	inc	r0
      000308 86 05            [24] 1105 	mov	ar5,@r0
      00030A 8A 82            [24] 1106 	mov	dpl,r2
      00030C 8C 83            [24] 1107 	mov	dph,r4
      00030E 8D F0            [24] 1108 	mov	b,r5
      000310 12 2E 2A         [24] 1109 	lcall	__gptrget
      000313 FA               [12] 1110 	mov	r2,a
      000314 A3               [24] 1111 	inc	dptr
      000315 12 2E 2A         [24] 1112 	lcall	__gptrget
      000318 FC               [12] 1113 	mov	r4,a
      000319 A3               [24] 1114 	inc	dptr
      00031A 12 2E 2A         [24] 1115 	lcall	__gptrget
      00031D FD               [12] 1116 	mov	r5,a
      00031E A3               [24] 1117 	inc	dptr
      00031F 12 2E 2A         [24] 1118 	lcall	__gptrget
      000322 8A 82            [24] 1119 	mov	dpl,r2
      000324 8C 83            [24] 1120 	mov	dph,r4
      000326 8D F0            [24] 1121 	mov	b,r5
      000328 C0 03            [24] 1122 	push	ar3
      00032A C0 02            [24] 1123 	push	ar2
      00032C 12 00 EA         [24] 1124 	lcall	_fuzzy_clamp
      00032F C8               [12] 1125 	xch	a,r0
      000330 E5 08            [12] 1126 	mov	a,_bp
      000332 24 09            [12] 1127 	add	a,#0x09
      000334 C8               [12] 1128 	xch	a,r0
      000335 A6 82            [24] 1129 	mov	@r0, dpl
      000337 08               [12] 1130 	inc	r0
      000338 A6 83            [24] 1131 	mov	@r0, dph
      00033A 08               [12] 1132 	inc	r0
      00033B A6 F0            [24] 1133 	mov	@r0, b
      00033D 08               [12] 1134 	inc	r0
      00033E F6               [12] 1135 	mov	@r0,a
      00033F D0 02            [24] 1136 	pop	ar2
      000341 D0 03            [24] 1137 	pop	ar3
                           00028C  1138 	C$fuzzy.h$855$1_0$33 ==.
                                   1139 ;	../../fuzzy.h:855: switch (method) {
      000343 D0 02            [24] 1140 	pop	ar2
      000345 EB               [12] 1141 	mov	a,r3
      000346 70 11            [24] 1142 	jnz	00108$
      000348 EA               [12] 1143 	mov	a,r2
      000349 70 65            [24] 1144 	jnz	00111$
      00034B E5 08            [12] 1145 	mov	a,_bp
      00034D 24 04            [12] 1146 	add	a,#0x04
      00034F F8               [12] 1147 	mov	r0,a
      000350 E6               [12] 1148 	mov	a,@r0
      000351 60 03            [24] 1149 	jz	00203$
      000353 02 03 F7         [24] 1150 	ljmp	00112$
      000356                       1151 00203$:
      000356 02 04 94         [24] 1152 	ljmp	00115$
                           0002A2  1153 	C$fuzzy.h$856$4_0$38 ==.
                                   1154 ;	../../fuzzy.h:856: case FUZZY_LOGIC_STANDARD:
      000359                       1155 00108$:
                           0002A2  1156 	C$fuzzy.h$857$1_0$33 ==.
                                   1157 ;	../../fuzzy.h:857: if (next < result) {
      000359 C0 03            [24] 1158 	push	ar3
      00035B C0 02            [24] 1159 	push	ar2
      00035D E5 08            [12] 1160 	mov	a,_bp
      00035F 24 05            [12] 1161 	add	a,#0x05
      000361 F8               [12] 1162 	mov	r0,a
      000362 E6               [12] 1163 	mov	a,@r0
      000363 C0 E0            [24] 1164 	push	acc
      000365 08               [12] 1165 	inc	r0
      000366 E6               [12] 1166 	mov	a,@r0
      000367 C0 E0            [24] 1167 	push	acc
      000369 08               [12] 1168 	inc	r0
      00036A E6               [12] 1169 	mov	a,@r0
      00036B C0 E0            [24] 1170 	push	acc
      00036D 08               [12] 1171 	inc	r0
      00036E E6               [12] 1172 	mov	a,@r0
      00036F C0 E0            [24] 1173 	push	acc
      000371 E5 08            [12] 1174 	mov	a,_bp
      000373 24 09            [12] 1175 	add	a,#0x09
      000375 F8               [12] 1176 	mov	r0,a
      000376 86 82            [24] 1177 	mov	dpl, @r0
      000378 08               [12] 1178 	inc	r0
      000379 86 83            [24] 1179 	mov	dph, @r0
      00037B 08               [12] 1180 	inc	r0
      00037C 86 F0            [24] 1181 	mov	b, @r0
      00037E 08               [12] 1182 	inc	r0
      00037F E6               [12] 1183 	mov	a, @r0
      000380 12 2B FE         [24] 1184 	lcall	___fslt
      000383 AF 82            [24] 1185 	mov	r7, dpl
      000385 E5 81            [12] 1186 	mov	a,sp
      000387 24 FC            [12] 1187 	add	a,#0xfc
      000389 F5 81            [12] 1188 	mov	sp,a
      00038B D0 02            [24] 1189 	pop	ar2
      00038D D0 03            [24] 1190 	pop	ar3
      00038F EF               [12] 1191 	mov	a,r7
      000390 70 03            [24] 1192 	jnz	00204$
      000392 02 04 9C         [24] 1193 	ljmp	00120$
      000395                       1194 00204$:
                           0002DE  1195 	C$fuzzy.h$858$5_0$39 ==.
                                   1196 ;	../../fuzzy.h:858: result = next;
      000395 E5 08            [12] 1197 	mov	a,_bp
      000397 24 09            [12] 1198 	add	a,#0x09
      000399 F8               [12] 1199 	mov	r0,a
      00039A E5 08            [12] 1200 	mov	a,_bp
      00039C 24 05            [12] 1201 	add	a,#0x05
      00039E F9               [12] 1202 	mov	r1,a
      00039F E6               [12] 1203 	mov	a,@r0
      0003A0 F7               [12] 1204 	mov	@r1,a
      0003A1 08               [12] 1205 	inc	r0
      0003A2 E6               [12] 1206 	mov	a,@r0
      0003A3 09               [12] 1207 	inc	r1
      0003A4 F7               [12] 1208 	mov	@r1,a
      0003A5 08               [12] 1209 	inc	r0
      0003A6 E6               [12] 1210 	mov	a,@r0
      0003A7 09               [12] 1211 	inc	r1
      0003A8 F7               [12] 1212 	mov	@r1,a
      0003A9 08               [12] 1213 	inc	r0
      0003AA E6               [12] 1214 	mov	a,@r0
      0003AB 09               [12] 1215 	inc	r1
      0003AC F7               [12] 1216 	mov	@r1,a
                           0002F6  1217 	C$fuzzy.h$860$4_0$38 ==.
                                   1218 ;	../../fuzzy.h:860: break;
      0003AD 02 04 9C         [24] 1219 	ljmp	00120$
                           0002F9  1220 	C$fuzzy.h$862$4_0$38 ==.
                                   1221 ;	../../fuzzy.h:862: case FUZZY_LOGIC_ALGEBRAIC:
      0003B0                       1222 00111$:
                           0002F9  1223 	C$fuzzy.h$864$1_0$33 ==.
                                   1224 ;	../../fuzzy.h:864: next;
      0003B0 C0 03            [24] 1225 	push	ar3
      0003B2 C0 02            [24] 1226 	push	ar2
      0003B4 E5 08            [12] 1227 	mov	a,_bp
      0003B6 24 09            [12] 1228 	add	a,#0x09
      0003B8 F8               [12] 1229 	mov	r0,a
      0003B9 E6               [12] 1230 	mov	a,@r0
      0003BA C0 E0            [24] 1231 	push	acc
      0003BC 08               [12] 1232 	inc	r0
      0003BD E6               [12] 1233 	mov	a,@r0
      0003BE C0 E0            [24] 1234 	push	acc
      0003C0 08               [12] 1235 	inc	r0
      0003C1 E6               [12] 1236 	mov	a,@r0
      0003C2 C0 E0            [24] 1237 	push	acc
      0003C4 08               [12] 1238 	inc	r0
      0003C5 E6               [12] 1239 	mov	a,@r0
      0003C6 C0 E0            [24] 1240 	push	acc
                           000311  1241 	C$fuzzy.h$865$1_0$33 ==.
                                   1242 ;	../../fuzzy.h:865: break;
      0003C8 E5 08            [12] 1243 	mov	a,_bp
      0003CA 24 05            [12] 1244 	add	a,#0x05
      0003CC F8               [12] 1245 	mov	r0,a
      0003CD 86 82            [24] 1246 	mov	dpl, @r0
      0003CF 08               [12] 1247 	inc	r0
      0003D0 86 83            [24] 1248 	mov	dph, @r0
      0003D2 08               [12] 1249 	inc	r0
      0003D3 86 F0            [24] 1250 	mov	b, @r0
      0003D5 08               [12] 1251 	inc	r0
      0003D6 E6               [12] 1252 	mov	a, @r0
      0003D7 12 2A CE         [24] 1253 	lcall	___fsmul
      0003DA C8               [12] 1254 	xch	a,r0
      0003DB E5 08            [12] 1255 	mov	a,_bp
      0003DD 24 05            [12] 1256 	add	a,#0x05
      0003DF C8               [12] 1257 	xch	a,r0
      0003E0 A6 82            [24] 1258 	mov	@r0, dpl
      0003E2 08               [12] 1259 	inc	r0
      0003E3 A6 83            [24] 1260 	mov	@r0, dph
      0003E5 08               [12] 1261 	inc	r0
      0003E6 A6 F0            [24] 1262 	mov	@r0, b
      0003E8 08               [12] 1263 	inc	r0
      0003E9 F6               [12] 1264 	mov	@r0,a
      0003EA E5 81            [12] 1265 	mov	a,sp
      0003EC 24 FC            [12] 1266 	add	a,#0xfc
      0003EE F5 81            [12] 1267 	mov	sp,a
      0003F0 D0 02            [24] 1268 	pop	ar2
      0003F2 D0 03            [24] 1269 	pop	ar3
      0003F4 02 04 9C         [24] 1270 	ljmp	00120$
                           000340  1271 	C$fuzzy.h$867$4_0$38 ==.
                                   1272 ;	../../fuzzy.h:867: case FUZZY_LOGIC_BOUNDED:
      0003F7                       1273 00112$:
                           000340  1274 	C$fuzzy.h$870$1_0$33 ==.
                                   1275 ;	../../fuzzy.h:870: next -
      0003F7 C0 03            [24] 1276 	push	ar3
      0003F9 C0 02            [24] 1277 	push	ar2
      0003FB E5 08            [12] 1278 	mov	a,_bp
      0003FD 24 09            [12] 1279 	add	a,#0x09
      0003FF F8               [12] 1280 	mov	r0,a
      000400 E6               [12] 1281 	mov	a,@r0
      000401 C0 E0            [24] 1282 	push	acc
      000403 08               [12] 1283 	inc	r0
      000404 E6               [12] 1284 	mov	a,@r0
      000405 C0 E0            [24] 1285 	push	acc
      000407 08               [12] 1286 	inc	r0
      000408 E6               [12] 1287 	mov	a,@r0
      000409 C0 E0            [24] 1288 	push	acc
      00040B 08               [12] 1289 	inc	r0
      00040C E6               [12] 1290 	mov	a,@r0
      00040D C0 E0            [24] 1291 	push	acc
      00040F E5 08            [12] 1292 	mov	a,_bp
      000411 24 05            [12] 1293 	add	a,#0x05
      000413 F8               [12] 1294 	mov	r0,a
      000414 86 82            [24] 1295 	mov	dpl, @r0
      000416 08               [12] 1296 	inc	r0
      000417 86 83            [24] 1297 	mov	dph, @r0
      000419 08               [12] 1298 	inc	r0
      00041A 86 F0            [24] 1299 	mov	b, @r0
      00041C 08               [12] 1300 	inc	r0
      00041D E6               [12] 1301 	mov	a, @r0
      00041E 12 2C 50         [24] 1302 	lcall	___fsadd
      000421 AC 82            [24] 1303 	mov	r4, dpl
      000423 AD 83            [24] 1304 	mov	r5, dph
      000425 AE F0            [24] 1305 	mov	r6, b
      000427 FF               [12] 1306 	mov	r7, a
      000428 E5 81            [12] 1307 	mov	a,sp
      00042A 24 FC            [12] 1308 	add	a,#0xfc
      00042C F5 81            [12] 1309 	mov	sp,a
      00042E E4               [12] 1310 	clr	a
      00042F C0 E0            [24] 1311 	push	acc
      000431 C0 E0            [24] 1312 	push	acc
      000433 74 80            [12] 1313 	mov	a,#0x80
      000435 C0 E0            [24] 1314 	push	acc
      000437 74 3F            [12] 1315 	mov	a,#0x3f
      000439 C0 E0            [24] 1316 	push	acc
                           000384  1317 	C$fuzzy.h$873$1_0$33 ==.
                                   1318 ;	../../fuzzy.h:873: if (result < LEVEL_LO) {
      00043B 8C 82            [24] 1319 	mov	dpl, r4
      00043D 8D 83            [24] 1320 	mov	dph, r5
      00043F 8E F0            [24] 1321 	mov	b, r6
      000441 EF               [12] 1322 	mov	a, r7
      000442 12 2A C3         [24] 1323 	lcall	___fssub
      000445 C8               [12] 1324 	xch	a,r0
      000446 E5 08            [12] 1325 	mov	a,_bp
      000448 24 05            [12] 1326 	add	a,#0x05
      00044A C8               [12] 1327 	xch	a,r0
      00044B A6 82            [24] 1328 	mov	@r0, dpl
      00044D 08               [12] 1329 	inc	r0
      00044E A6 83            [24] 1330 	mov	@r0, dph
      000450 08               [12] 1331 	inc	r0
      000451 A6 F0            [24] 1332 	mov	@r0, b
      000453 08               [12] 1333 	inc	r0
      000454 F6               [12] 1334 	mov	@r0,a
      000455 E5 81            [12] 1335 	mov	a,sp
      000457 24 FC            [12] 1336 	add	a,#0xfc
      000459 F5 81            [12] 1337 	mov	sp,a
      00045B E4               [12] 1338 	clr	a
      00045C C0 E0            [24] 1339 	push	acc
      00045E C0 E0            [24] 1340 	push	acc
      000460 C0 E0            [24] 1341 	push	acc
      000462 C0 E0            [24] 1342 	push	acc
      000464 E5 08            [12] 1343 	mov	a,_bp
      000466 24 05            [12] 1344 	add	a,#0x05
      000468 F8               [12] 1345 	mov	r0,a
      000469 86 82            [24] 1346 	mov	dpl, @r0
      00046B 08               [12] 1347 	inc	r0
      00046C 86 83            [24] 1348 	mov	dph, @r0
      00046E 08               [12] 1349 	inc	r0
      00046F 86 F0            [24] 1350 	mov	b, @r0
      000471 08               [12] 1351 	inc	r0
      000472 E6               [12] 1352 	mov	a, @r0
      000473 12 2B FE         [24] 1353 	lcall	___fslt
      000476 AF 82            [24] 1354 	mov	r7, dpl
      000478 E5 81            [12] 1355 	mov	a,sp
      00047A 24 FC            [12] 1356 	add	a,#0xfc
      00047C F5 81            [12] 1357 	mov	sp,a
      00047E D0 02            [24] 1358 	pop	ar2
      000480 D0 03            [24] 1359 	pop	ar3
      000482 EF               [12] 1360 	mov	a,r7
      000483 60 17            [24] 1361 	jz	00120$
                           0003CE  1362 	C$fuzzy.h$874$5_0$40 ==.
                                   1363 ;	../../fuzzy.h:874: result = LEVEL_LO;
      000485 E5 08            [12] 1364 	mov	a,_bp
      000487 24 05            [12] 1365 	add	a,#0x05
      000489 F8               [12] 1366 	mov	r0,a
      00048A E4               [12] 1367 	clr	a
      00048B F6               [12] 1368 	mov	@r0,a
      00048C 08               [12] 1369 	inc	r0
      00048D F6               [12] 1370 	mov	@r0,a
      00048E 08               [12] 1371 	inc	r0
      00048F F6               [12] 1372 	mov	@r0,a
      000490 08               [12] 1373 	inc	r0
      000491 F6               [12] 1374 	mov	@r0,a
                           0003DB  1375 	C$fuzzy.h$876$4_0$38 ==.
                                   1376 ;	../../fuzzy.h:876: break;
                           0003DB  1377 	C$fuzzy.h$878$4_0$38 ==.
                                   1378 ;	../../fuzzy.h:878: default:
      000492 80 08            [24] 1379 	sjmp	00120$
      000494                       1380 00115$:
                           0003DD  1381 	C$fuzzy.h$879$4_0$38 ==.
                                   1382 ;	../../fuzzy.h:879: return LEVEL_LO;
      000494 90 00 00         [24] 1383 	mov	dptr,#0x0000
      000497 E4               [12] 1384 	clr	a
      000498 F5 F0            [12] 1385 	mov	b,a
                           0003E3  1386 	C$fuzzy.h$880$3_0$37 ==.
                                   1387 ;	../../fuzzy.h:880: }
      00049A 80 20            [24] 1388 	sjmp	00121$
      00049C                       1389 00120$:
                           0003E5  1390 	C$fuzzy.h$848$2_0$36 ==.
                                   1391 ;	../../fuzzy.h:848: index++
      00049C E5 08            [12] 1392 	mov	a,_bp
      00049E 24 0D            [12] 1393 	add	a,#0x0d
      0004A0 F8               [12] 1394 	mov	r0,a
      0004A1 06               [12] 1395 	inc	@r0
      0004A2 B6 00 02         [24] 1396 	cjne	@r0,#0x00,00206$
      0004A5 08               [12] 1397 	inc	r0
      0004A6 06               [12] 1398 	inc	@r0
      0004A7                       1399 00206$:
      0004A7 02 02 D3         [24] 1400 	ljmp	00119$
      0004AA                       1401 00117$:
                           0003F3  1402 	C$fuzzy.h$884$1_0$33 ==.
                                   1403 ;	../../fuzzy.h:884: result
      0004AA E5 08            [12] 1404 	mov	a,_bp
      0004AC 24 05            [12] 1405 	add	a,#0x05
      0004AE F8               [12] 1406 	mov	r0,a
      0004AF 86 82            [24] 1407 	mov	dpl, @r0
      0004B1 08               [12] 1408 	inc	r0
      0004B2 86 83            [24] 1409 	mov	dph, @r0
      0004B4 08               [12] 1410 	inc	r0
      0004B5 86 F0            [24] 1411 	mov	b, @r0
      0004B7 08               [12] 1412 	inc	r0
      0004B8 E6               [12] 1413 	mov	a, @r0
      0004B9 12 00 EA         [24] 1414 	lcall	_fuzzy_clamp
      0004BC                       1415 00121$:
                           000405  1416 	C$fuzzy.h$886$1_0$33 ==.
                                   1417 ;	../../fuzzy.h:886: }
      0004BC 85 08 81         [24] 1418 	mov	sp,_bp
      0004BF D0 08            [24] 1419 	pop	_bp
                           00040A  1420 	C$fuzzy.h$886$1_0$33 ==.
                           00040A  1421 	XG$fuzzy_and_array$0$0 ==.
      0004C1 22               [24] 1422 	ret
                                   1423 ;------------------------------------------------------------
                                   1424 ;Allocation info for local variables in function 'fuzzy_or_array'
                                   1425 ;------------------------------------------------------------
                                   1426 ;count         Allocated to stack - _bp -4 +2 
                                   1427 ;args          Allocated to stack - _bp -7 +3 
                                   1428 ;method        Allocated to registers r5 
                                   1429 ;result        Allocated to stack - _bp +10 +4 
                                   1430 ;next          Allocated to registers r4 r5 r6 r3 
                                   1431 ;index         Allocated to stack - _bp +14 +2 
                                   1432 ;sloc0         Allocated to stack - _bp +1 +3 
                                   1433 ;sloc1         Allocated to stack - _bp +4 +1 
                                   1434 ;sloc2         Allocated to stack - _bp +5 +1 
                                   1435 ;sloc3         Allocated to stack - _bp +6 +4 
                                   1436 ;------------------------------------------------------------
                           00040B  1437 	G$fuzzy_or_array$0$0 ==.
                           00040B  1438 	C$fuzzy.h$901$1_0$42 ==.
                                   1439 ;	../../fuzzy.h:901: float fuzzy_or_array(
                                   1440 ;	-----------------------------------------
                                   1441 ;	 function fuzzy_or_array
                                   1442 ;	-----------------------------------------
      0004C2                       1443 _fuzzy_or_array:
      0004C2 C0 08            [24] 1444 	push	_bp
      0004C4 E5 81            [12] 1445 	mov	a,sp
      0004C6 F5 08            [12] 1446 	mov	_bp,a
      0004C8 24 0F            [12] 1447 	add	a,#0x0f
      0004CA F5 81            [12] 1448 	mov	sp,a
      0004CC AD 82            [24] 1449 	mov	r5, dpl
                           000417  1450 	C$fuzzy.h$912$1_0$42 ==.
                                   1451 ;	../../fuzzy.h:912: args == NULL ||
      0004CE E5 08            [12] 1452 	mov	a,_bp
      0004D0 24 F9            [12] 1453 	add	a,#0xf9
      0004D2 F8               [12] 1454 	mov	r0,a
      0004D3 E6               [12] 1455 	mov	a,@r0
      0004D4 08               [12] 1456 	inc	r0
      0004D5 46               [12] 1457 	orl	a,@r0
      0004D6 60 0A            [24] 1458 	jz	00101$
                           000421  1459 	C$fuzzy.h$913$1_0$42 ==.
                                   1460 ;	../../fuzzy.h:913: count == 0u
      0004D8 E5 08            [12] 1461 	mov	a,_bp
      0004DA 24 FC            [12] 1462 	add	a,#0xfc
      0004DC F8               [12] 1463 	mov	r0,a
      0004DD E6               [12] 1464 	mov	a,@r0
      0004DE 08               [12] 1465 	inc	r0
      0004DF 46               [12] 1466 	orl	a,@r0
      0004E0 70 09            [24] 1467 	jnz	00102$
      0004E2                       1468 00101$:
                           00042B  1469 	C$fuzzy.h$915$2_0$43 ==.
                                   1470 ;	../../fuzzy.h:915: return LEVEL_LO;
      0004E2 90 00 00         [24] 1471 	mov	dptr,#0x0000
      0004E5 E4               [12] 1472 	clr	a
      0004E6 F5 F0            [12] 1473 	mov	b,a
      0004E8 02 07 7E         [24] 1474 	ljmp	00121$
      0004EB                       1475 00102$:
                           000434  1476 	C$fuzzy.h$919$1_0$42 ==.
                                   1477 ;	../../fuzzy.h:919: method != FUZZY_LOGIC_STANDARD &&
      0004EB ED               [12] 1478 	mov	a,r5
      0004EC 60 13            [24] 1479 	jz	00105$
                           000437  1480 	C$fuzzy.h$920$1_0$42 ==.
                                   1481 ;	../../fuzzy.h:920: method != FUZZY_LOGIC_ALGEBRAIC &&
      0004EE BD 01 02         [24] 1482 	cjne	r5,#0x01,00192$
      0004F1 80 0E            [24] 1483 	sjmp	00105$
      0004F3                       1484 00192$:
                           00043C  1485 	C$fuzzy.h$922$1_0$42 ==.
                                   1486 ;	../../fuzzy.h:922: ) {
      0004F3 BD 02 02         [24] 1487 	cjne	r5,#0x02,00193$
      0004F6 80 09            [24] 1488 	sjmp	00105$
      0004F8                       1489 00193$:
                           000441  1490 	C$fuzzy.h$923$2_0$44 ==.
                                   1491 ;	../../fuzzy.h:923: return LEVEL_LO;
      0004F8 90 00 00         [24] 1492 	mov	dptr,#0x0000
      0004FB E4               [12] 1493 	clr	a
      0004FC F5 F0            [12] 1494 	mov	b,a
      0004FE 02 07 7E         [24] 1495 	ljmp	00121$
      000501                       1496 00105$:
                           00044A  1497 	C$fuzzy.h$928$1_0$42 ==.
                                   1498 ;	../../fuzzy.h:928: args[0]
      000501 E5 08            [12] 1499 	mov	a,_bp
      000503 24 F9            [12] 1500 	add	a,#0xf9
      000505 F8               [12] 1501 	mov	r0,a
      000506 A9 08            [24] 1502 	mov	r1,_bp
      000508 09               [12] 1503 	inc	r1
      000509 E6               [12] 1504 	mov	a,@r0
      00050A F7               [12] 1505 	mov	@r1,a
      00050B 08               [12] 1506 	inc	r0
      00050C E6               [12] 1507 	mov	a,@r0
      00050D 09               [12] 1508 	inc	r1
      00050E F7               [12] 1509 	mov	@r1,a
      00050F 08               [12] 1510 	inc	r0
      000510 E6               [12] 1511 	mov	a,@r0
      000511 09               [12] 1512 	inc	r1
      000512 F7               [12] 1513 	mov	@r1,a
      000513 A8 08            [24] 1514 	mov	r0,_bp
      000515 08               [12] 1515 	inc	r0
      000516 86 82            [24] 1516 	mov	dpl,@r0
      000518 08               [12] 1517 	inc	r0
      000519 86 83            [24] 1518 	mov	dph,@r0
      00051B 08               [12] 1519 	inc	r0
      00051C 86 F0            [24] 1520 	mov	b,@r0
      00051E 12 2E 2A         [24] 1521 	lcall	__gptrget
      000521 FA               [12] 1522 	mov	r2,a
      000522 A3               [24] 1523 	inc	dptr
      000523 12 2E 2A         [24] 1524 	lcall	__gptrget
      000526 FB               [12] 1525 	mov	r3,a
      000527 A3               [24] 1526 	inc	dptr
      000528 12 2E 2A         [24] 1527 	lcall	__gptrget
      00052B FE               [12] 1528 	mov	r6,a
      00052C A3               [24] 1529 	inc	dptr
      00052D 12 2E 2A         [24] 1530 	lcall	__gptrget
      000530 8A 82            [24] 1531 	mov	dpl,r2
      000532 8B 83            [24] 1532 	mov	dph,r3
      000534 8E F0            [24] 1533 	mov	b,r6
      000536 C0 05            [24] 1534 	push	ar5
      000538 12 00 EA         [24] 1535 	lcall	_fuzzy_clamp
      00053B C8               [12] 1536 	xch	a,r0
      00053C E5 08            [12] 1537 	mov	a,_bp
      00053E 24 0A            [12] 1538 	add	a,#0x0a
      000540 C8               [12] 1539 	xch	a,r0
      000541 A6 82            [24] 1540 	mov	@r0, dpl
      000543 08               [12] 1541 	inc	r0
      000544 A6 83            [24] 1542 	mov	@r0, dph
      000546 08               [12] 1543 	inc	r0
      000547 A6 F0            [24] 1544 	mov	@r0, b
      000549 08               [12] 1545 	inc	r0
      00054A F6               [12] 1546 	mov	@r0,a
      00054B D0 05            [24] 1547 	pop	ar5
                           000496  1548 	C$fuzzy.h$932$3_0$46 ==.
                                   1549 ;	../../fuzzy.h:932: index = 1u;
      00054D E5 08            [12] 1550 	mov	a,_bp
      00054F 24 05            [12] 1551 	add	a,#0x05
      000551 F8               [12] 1552 	mov	r0,a
      000552 E4               [12] 1553 	clr	a
      000553 BD 00 01         [24] 1554 	cjne	r5,#0x00,00194$
      000556 04               [12] 1555 	inc	a
      000557                       1556 00194$:
      000557 F6               [12] 1557 	mov	@r0,a
      000558 BD 01 03         [24] 1558 	cjne	r5,#0x01,00196$
      00055B ED               [12] 1559 	mov	a,r5
      00055C 80 01            [24] 1560 	sjmp	00197$
      00055E                       1561 00196$:
      00055E E4               [12] 1562 	clr	a
      00055F                       1563 00197$:
      00055F FA               [12] 1564 	mov	r2,a
      000560 E5 08            [12] 1565 	mov	a,_bp
      000562 24 04            [12] 1566 	add	a,#0x04
      000564 F8               [12] 1567 	mov	r0,a
      000565 E4               [12] 1568 	clr	a
      000566 BD 02 01         [24] 1569 	cjne	r5,#0x02,00198$
      000569 04               [12] 1570 	inc	a
      00056A                       1571 00198$:
      00056A F6               [12] 1572 	mov	@r0,a
      00056B E5 08            [12] 1573 	mov	a,_bp
      00056D 24 0E            [12] 1574 	add	a,#0x0e
      00056F F8               [12] 1575 	mov	r0,a
      000570 76 01            [12] 1576 	mov	@r0,#0x01
      000572 08               [12] 1577 	inc	r0
      000573 76 00            [12] 1578 	mov	@r0,#0x00
      000575                       1579 00119$:
                           0004BE  1580 	C$fuzzy.h$933$2_0$45 ==.
                                   1581 ;	../../fuzzy.h:933: index < count;
      000575 E5 08            [12] 1582 	mov	a,_bp
      000577 24 0E            [12] 1583 	add	a,#0x0e
      000579 F8               [12] 1584 	mov	r0,a
      00057A E5 08            [12] 1585 	mov	a,_bp
      00057C 24 FC            [12] 1586 	add	a,#0xfc
      00057E F9               [12] 1587 	mov	r1,a
      00057F C3               [12] 1588 	clr	c
      000580 E6               [12] 1589 	mov	a,@r0
      000581 97               [12] 1590 	subb	a,@r1
      000582 08               [12] 1591 	inc	r0
      000583 E6               [12] 1592 	mov	a,@r0
      000584 09               [12] 1593 	inc	r1
      000585 97               [12] 1594 	subb	a,@r1
      000586 40 03            [24] 1595 	jc	00200$
      000588 02 07 6C         [24] 1596 	ljmp	00117$
      00058B                       1597 00200$:
                           0004D4  1598 	C$fuzzy.h$938$1_0$42 ==.
                                   1599 ;	../../fuzzy.h:938: args[index]
      00058B C0 02            [24] 1600 	push	ar2
      00058D E5 08            [12] 1601 	mov	a,_bp
      00058F 24 0E            [12] 1602 	add	a,#0x0e
      000591 F8               [12] 1603 	mov	r0,a
      000592 E6               [12] 1604 	mov	a,@r0
      000593 26               [12] 1605 	add	a,@r0
      000594 FD               [12] 1606 	mov	r5,a
      000595 08               [12] 1607 	inc	r0
      000596 E6               [12] 1608 	mov	a,@r0
      000597 33               [12] 1609 	rlc	a
      000598 FC               [12] 1610 	mov	r4,a
      000599 ED               [12] 1611 	mov	a,r5
      00059A 2D               [12] 1612 	add	a,r5
      00059B FD               [12] 1613 	mov	r5,a
      00059C EC               [12] 1614 	mov	a,r4
      00059D 33               [12] 1615 	rlc	a
      00059E FC               [12] 1616 	mov	r4,a
      00059F A8 08            [24] 1617 	mov	r0,_bp
      0005A1 08               [12] 1618 	inc	r0
      0005A2 ED               [12] 1619 	mov	a,r5
      0005A3 26               [12] 1620 	add	a, @r0
      0005A4 FA               [12] 1621 	mov	r2,a
      0005A5 EC               [12] 1622 	mov	a,r4
      0005A6 08               [12] 1623 	inc	r0
      0005A7 36               [12] 1624 	addc	a, @r0
      0005A8 FC               [12] 1625 	mov	r4,a
      0005A9 08               [12] 1626 	inc	r0
      0005AA 86 05            [24] 1627 	mov	ar5,@r0
      0005AC 8A 82            [24] 1628 	mov	dpl,r2
      0005AE 8C 83            [24] 1629 	mov	dph,r4
      0005B0 8D F0            [24] 1630 	mov	b,r5
      0005B2 12 2E 2A         [24] 1631 	lcall	__gptrget
      0005B5 FA               [12] 1632 	mov	r2,a
      0005B6 A3               [24] 1633 	inc	dptr
      0005B7 12 2E 2A         [24] 1634 	lcall	__gptrget
      0005BA FC               [12] 1635 	mov	r4,a
      0005BB A3               [24] 1636 	inc	dptr
      0005BC 12 2E 2A         [24] 1637 	lcall	__gptrget
      0005BF FD               [12] 1638 	mov	r5,a
      0005C0 A3               [24] 1639 	inc	dptr
      0005C1 12 2E 2A         [24] 1640 	lcall	__gptrget
      0005C4 8A 82            [24] 1641 	mov	dpl,r2
      0005C6 8C 83            [24] 1642 	mov	dph,r4
      0005C8 8D F0            [24] 1643 	mov	b,r5
      0005CA C0 02            [24] 1644 	push	ar2
      0005CC 12 00 EA         [24] 1645 	lcall	_fuzzy_clamp
      0005CF AC 82            [24] 1646 	mov	r4, dpl
      0005D1 AD 83            [24] 1647 	mov	r5, dph
      0005D3 AE F0            [24] 1648 	mov	r6, b
      0005D5 FB               [12] 1649 	mov	r3, a
      0005D6 D0 02            [24] 1650 	pop	ar2
                           000521  1651 	C$fuzzy.h$941$1_0$42 ==.
                                   1652 ;	../../fuzzy.h:941: switch (method) {
      0005D8 D0 02            [24] 1653 	pop	ar2
      0005DA E5 08            [12] 1654 	mov	a,_bp
      0005DC 24 05            [12] 1655 	add	a,#0x05
      0005DE F8               [12] 1656 	mov	r0,a
      0005DF E6               [12] 1657 	mov	a,@r0
      0005E0 70 11            [24] 1658 	jnz	00108$
      0005E2 EA               [12] 1659 	mov	a,r2
      0005E3 70 5D            [24] 1660 	jnz	00111$
      0005E5 E5 08            [12] 1661 	mov	a,_bp
      0005E7 24 04            [12] 1662 	add	a,#0x04
      0005E9 F8               [12] 1663 	mov	r0,a
      0005EA E6               [12] 1664 	mov	a,@r0
      0005EB 60 03            [24] 1665 	jz	00203$
      0005ED 02 06 E7         [24] 1666 	ljmp	00112$
      0005F0                       1667 00203$:
      0005F0 02 07 56         [24] 1668 	ljmp	00115$
                           00053C  1669 	C$fuzzy.h$942$4_0$47 ==.
                                   1670 ;	../../fuzzy.h:942: case FUZZY_LOGIC_STANDARD:
      0005F3                       1671 00108$:
                           00053C  1672 	C$fuzzy.h$943$1_0$42 ==.
                                   1673 ;	../../fuzzy.h:943: if (next > result) {
      0005F3 C0 06            [24] 1674 	push	ar6
      0005F5 C0 05            [24] 1675 	push	ar5
      0005F7 C0 04            [24] 1676 	push	ar4
      0005F9 C0 03            [24] 1677 	push	ar3
      0005FB C0 02            [24] 1678 	push	ar2
      0005FD C0 04            [24] 1679 	push	ar4
      0005FF C0 05            [24] 1680 	push	ar5
      000601 C0 06            [24] 1681 	push	ar6
      000603 C0 03            [24] 1682 	push	ar3
      000605 E5 08            [12] 1683 	mov	a,_bp
      000607 24 0A            [12] 1684 	add	a,#0x0a
      000609 F8               [12] 1685 	mov	r0,a
      00060A 86 82            [24] 1686 	mov	dpl, @r0
      00060C 08               [12] 1687 	inc	r0
      00060D 86 83            [24] 1688 	mov	dph, @r0
      00060F 08               [12] 1689 	inc	r0
      000610 86 F0            [24] 1690 	mov	b, @r0
      000612 08               [12] 1691 	inc	r0
      000613 E6               [12] 1692 	mov	a, @r0
      000614 12 2B FE         [24] 1693 	lcall	___fslt
      000617 AF 82            [24] 1694 	mov	r7, dpl
      000619 E5 81            [12] 1695 	mov	a,sp
      00061B 24 FC            [12] 1696 	add	a,#0xfc
      00061D F5 81            [12] 1697 	mov	sp,a
      00061F D0 02            [24] 1698 	pop	ar2
      000621 D0 03            [24] 1699 	pop	ar3
      000623 D0 04            [24] 1700 	pop	ar4
      000625 D0 05            [24] 1701 	pop	ar5
      000627 D0 06            [24] 1702 	pop	ar6
      000629 EF               [12] 1703 	mov	a,r7
      00062A 70 03            [24] 1704 	jnz	00204$
      00062C 02 07 5E         [24] 1705 	ljmp	00120$
      00062F                       1706 00204$:
                           000578  1707 	C$fuzzy.h$944$5_0$48 ==.
                                   1708 ;	../../fuzzy.h:944: result = next;
      00062F E5 08            [12] 1709 	mov	a,_bp
      000631 24 0A            [12] 1710 	add	a,#0x0a
      000633 F8               [12] 1711 	mov	r0,a
      000634 A6 04            [24] 1712 	mov	@r0,ar4
      000636 08               [12] 1713 	inc	r0
      000637 A6 05            [24] 1714 	mov	@r0,ar5
      000639 08               [12] 1715 	inc	r0
      00063A A6 06            [24] 1716 	mov	@r0,ar6
      00063C 08               [12] 1717 	inc	r0
      00063D A6 03            [24] 1718 	mov	@r0,ar3
                           000588  1719 	C$fuzzy.h$946$4_0$47 ==.
                                   1720 ;	../../fuzzy.h:946: break;
      00063F 02 07 5E         [24] 1721 	ljmp	00120$
                           00058B  1722 	C$fuzzy.h$948$4_0$47 ==.
                                   1723 ;	../../fuzzy.h:948: case FUZZY_LOGIC_ALGEBRAIC:
      000642                       1724 00111$:
                           00058B  1725 	C$fuzzy.h$951$1_0$42 ==.
                                   1726 ;	../../fuzzy.h:951: next -
      000642 C0 02            [24] 1727 	push	ar2
      000644 C0 06            [24] 1728 	push	ar6
      000646 C0 05            [24] 1729 	push	ar5
      000648 C0 04            [24] 1730 	push	ar4
      00064A C0 03            [24] 1731 	push	ar3
      00064C C0 02            [24] 1732 	push	ar2
      00064E C0 04            [24] 1733 	push	ar4
      000650 C0 05            [24] 1734 	push	ar5
      000652 C0 06            [24] 1735 	push	ar6
      000654 C0 03            [24] 1736 	push	ar3
                           00059F  1737 	C$fuzzy.h$952$1_0$42 ==.
                                   1738 ;	../../fuzzy.h:952: result * next;
      000656 E5 08            [12] 1739 	mov	a,_bp
      000658 24 0A            [12] 1740 	add	a,#0x0a
      00065A F8               [12] 1741 	mov	r0,a
      00065B 86 82            [24] 1742 	mov	dpl, @r0
      00065D 08               [12] 1743 	inc	r0
      00065E 86 83            [24] 1744 	mov	dph, @r0
      000660 08               [12] 1745 	inc	r0
      000661 86 F0            [24] 1746 	mov	b, @r0
      000663 08               [12] 1747 	inc	r0
      000664 E6               [12] 1748 	mov	a, @r0
      000665 12 2C 50         [24] 1749 	lcall	___fsadd
      000668 C8               [12] 1750 	xch	a,r0
      000669 E5 08            [12] 1751 	mov	a,_bp
      00066B 24 06            [12] 1752 	add	a,#0x06
      00066D C8               [12] 1753 	xch	a,r0
      00066E A6 82            [24] 1754 	mov	@r0, dpl
      000670 08               [12] 1755 	inc	r0
      000671 A6 83            [24] 1756 	mov	@r0, dph
      000673 08               [12] 1757 	inc	r0
      000674 A6 F0            [24] 1758 	mov	@r0, b
      000676 08               [12] 1759 	inc	r0
      000677 F6               [12] 1760 	mov	@r0,a
      000678 E5 81            [12] 1761 	mov	a,sp
      00067A 24 FC            [12] 1762 	add	a,#0xfc
      00067C F5 81            [12] 1763 	mov	sp,a
      00067E D0 02            [24] 1764 	pop	ar2
      000680 D0 03            [24] 1765 	pop	ar3
      000682 D0 04            [24] 1766 	pop	ar4
      000684 D0 05            [24] 1767 	pop	ar5
      000686 D0 06            [24] 1768 	pop	ar6
      000688 C0 04            [24] 1769 	push	ar4
      00068A C0 05            [24] 1770 	push	ar5
      00068C C0 06            [24] 1771 	push	ar6
      00068E C0 03            [24] 1772 	push	ar3
      000690 E5 08            [12] 1773 	mov	a,_bp
      000692 24 0A            [12] 1774 	add	a,#0x0a
      000694 F8               [12] 1775 	mov	r0,a
      000695 86 82            [24] 1776 	mov	dpl, @r0
      000697 08               [12] 1777 	inc	r0
      000698 86 83            [24] 1778 	mov	dph, @r0
      00069A 08               [12] 1779 	inc	r0
      00069B 86 F0            [24] 1780 	mov	b, @r0
      00069D 08               [12] 1781 	inc	r0
      00069E E6               [12] 1782 	mov	a, @r0
      00069F 12 2A CE         [24] 1783 	lcall	___fsmul
      0006A2 AA 82            [24] 1784 	mov	r2, dpl
      0006A4 AB 83            [24] 1785 	mov	r3, dph
      0006A6 AE F0            [24] 1786 	mov	r6, b
      0006A8 FF               [12] 1787 	mov	r7, a
      0006A9 E5 81            [12] 1788 	mov	a,sp
      0006AB 24 FC            [12] 1789 	add	a,#0xfc
      0006AD F5 81            [12] 1790 	mov	sp,a
      0006AF C0 02            [24] 1791 	push	ar2
      0006B1 C0 02            [24] 1792 	push	ar2
      0006B3 C0 03            [24] 1793 	push	ar3
      0006B5 C0 06            [24] 1794 	push	ar6
      0006B7 C0 07            [24] 1795 	push	ar7
                           000602  1796 	C$fuzzy.h$953$1_0$42 ==.
                                   1797 ;	../../fuzzy.h:953: break;
      0006B9 E5 08            [12] 1798 	mov	a,_bp
      0006BB 24 06            [12] 1799 	add	a,#0x06
      0006BD F8               [12] 1800 	mov	r0,a
      0006BE 86 82            [24] 1801 	mov	dpl, @r0
      0006C0 08               [12] 1802 	inc	r0
      0006C1 86 83            [24] 1803 	mov	dph, @r0
      0006C3 08               [12] 1804 	inc	r0
      0006C4 86 F0            [24] 1805 	mov	b, @r0
      0006C6 08               [12] 1806 	inc	r0
      0006C7 E6               [12] 1807 	mov	a, @r0
      0006C8 12 2A C3         [24] 1808 	lcall	___fssub
      0006CB C8               [12] 1809 	xch	a,r0
      0006CC E5 08            [12] 1810 	mov	a,_bp
      0006CE 24 0A            [12] 1811 	add	a,#0x0a
      0006D0 C8               [12] 1812 	xch	a,r0
      0006D1 A6 82            [24] 1813 	mov	@r0, dpl
      0006D3 08               [12] 1814 	inc	r0
      0006D4 A6 83            [24] 1815 	mov	@r0, dph
      0006D6 08               [12] 1816 	inc	r0
      0006D7 A6 F0            [24] 1817 	mov	@r0, b
      0006D9 08               [12] 1818 	inc	r0
      0006DA F6               [12] 1819 	mov	@r0,a
      0006DB E5 81            [12] 1820 	mov	a,sp
      0006DD 24 FC            [12] 1821 	add	a,#0xfc
      0006DF F5 81            [12] 1822 	mov	sp,a
      0006E1 D0 02            [24] 1823 	pop	ar2
      0006E3 D0 02            [24] 1824 	pop	ar2
                           00062E  1825 	C$fuzzy.h$955$4_0$47 ==.
                                   1826 ;	../../fuzzy.h:955: case FUZZY_LOGIC_BOUNDED:
      0006E5 80 77            [24] 1827 	sjmp	00120$
      0006E7                       1828 00112$:
                           000630  1829 	C$fuzzy.h$957$1_0$42 ==.
                                   1830 ;	../../fuzzy.h:957: next;
      0006E7 C0 02            [24] 1831 	push	ar2
      0006E9 C0 04            [24] 1832 	push	ar4
      0006EB C0 05            [24] 1833 	push	ar5
      0006ED C0 06            [24] 1834 	push	ar6
      0006EF C0 03            [24] 1835 	push	ar3
                           00063A  1836 	C$fuzzy.h$959$1_0$42 ==.
                                   1837 ;	../../fuzzy.h:959: if (result > LEVEL_HI) {
      0006F1 E5 08            [12] 1838 	mov	a,_bp
      0006F3 24 0A            [12] 1839 	add	a,#0x0a
      0006F5 F8               [12] 1840 	mov	r0,a
      0006F6 86 82            [24] 1841 	mov	dpl, @r0
      0006F8 08               [12] 1842 	inc	r0
      0006F9 86 83            [24] 1843 	mov	dph, @r0
      0006FB 08               [12] 1844 	inc	r0
      0006FC 86 F0            [24] 1845 	mov	b, @r0
      0006FE 08               [12] 1846 	inc	r0
      0006FF E6               [12] 1847 	mov	a, @r0
      000700 12 2C 50         [24] 1848 	lcall	___fsadd
      000703 C8               [12] 1849 	xch	a,r0
      000704 E5 08            [12] 1850 	mov	a,_bp
      000706 24 0A            [12] 1851 	add	a,#0x0a
      000708 C8               [12] 1852 	xch	a,r0
      000709 A6 82            [24] 1853 	mov	@r0, dpl
      00070B 08               [12] 1854 	inc	r0
      00070C A6 83            [24] 1855 	mov	@r0, dph
      00070E 08               [12] 1856 	inc	r0
      00070F A6 F0            [24] 1857 	mov	@r0, b
      000711 08               [12] 1858 	inc	r0
      000712 F6               [12] 1859 	mov	@r0,a
      000713 E5 81            [12] 1860 	mov	a,sp
      000715 24 FC            [12] 1861 	add	a,#0xfc
      000717 F5 81            [12] 1862 	mov	sp,a
      000719 E5 08            [12] 1863 	mov	a,_bp
      00071B 24 0A            [12] 1864 	add	a,#0x0a
      00071D F8               [12] 1865 	mov	r0,a
      00071E E6               [12] 1866 	mov	a,@r0
      00071F C0 E0            [24] 1867 	push	acc
      000721 08               [12] 1868 	inc	r0
      000722 E6               [12] 1869 	mov	a,@r0
      000723 C0 E0            [24] 1870 	push	acc
      000725 08               [12] 1871 	inc	r0
      000726 E6               [12] 1872 	mov	a,@r0
      000727 C0 E0            [24] 1873 	push	acc
      000729 08               [12] 1874 	inc	r0
      00072A E6               [12] 1875 	mov	a,@r0
      00072B C0 E0            [24] 1876 	push	acc
      00072D 90 00 00         [24] 1877 	mov	dptr,#0x0000
      000730 75 F0 80         [24] 1878 	mov	b, #0x80
      000733 74 3F            [12] 1879 	mov	a, #0x3f
      000735 12 2B FE         [24] 1880 	lcall	___fslt
      000738 AF 82            [24] 1881 	mov	r7, dpl
      00073A E5 81            [12] 1882 	mov	a,sp
      00073C 24 FC            [12] 1883 	add	a,#0xfc
      00073E F5 81            [12] 1884 	mov	sp,a
      000740 D0 02            [24] 1885 	pop	ar2
      000742 EF               [12] 1886 	mov	a,r7
      000743 60 19            [24] 1887 	jz	00120$
                           00068E  1888 	C$fuzzy.h$960$5_0$49 ==.
                                   1889 ;	../../fuzzy.h:960: result = LEVEL_HI;
      000745 E5 08            [12] 1890 	mov	a,_bp
      000747 24 0A            [12] 1891 	add	a,#0x0a
      000749 F8               [12] 1892 	mov	r0,a
      00074A E4               [12] 1893 	clr	a
      00074B F6               [12] 1894 	mov	@r0,a
      00074C 08               [12] 1895 	inc	r0
      00074D F6               [12] 1896 	mov	@r0,a
      00074E 08               [12] 1897 	inc	r0
      00074F 76 80            [12] 1898 	mov	@r0,#0x80
      000751 08               [12] 1899 	inc	r0
      000752 76 3F            [12] 1900 	mov	@r0,#0x3f
                           00069D  1901 	C$fuzzy.h$962$4_0$47 ==.
                                   1902 ;	../../fuzzy.h:962: break;
                           00069D  1903 	C$fuzzy.h$964$4_0$47 ==.
                                   1904 ;	../../fuzzy.h:964: default:
      000754 80 08            [24] 1905 	sjmp	00120$
      000756                       1906 00115$:
                           00069F  1907 	C$fuzzy.h$965$4_0$47 ==.
                                   1908 ;	../../fuzzy.h:965: return LEVEL_LO;
      000756 90 00 00         [24] 1909 	mov	dptr,#0x0000
      000759 E4               [12] 1910 	clr	a
      00075A F5 F0            [12] 1911 	mov	b,a
                           0006A5  1912 	C$fuzzy.h$966$3_0$46 ==.
                                   1913 ;	../../fuzzy.h:966: }
      00075C 80 20            [24] 1914 	sjmp	00121$
      00075E                       1915 00120$:
                           0006A7  1916 	C$fuzzy.h$934$2_0$45 ==.
                                   1917 ;	../../fuzzy.h:934: index++
      00075E E5 08            [12] 1918 	mov	a,_bp
      000760 24 0E            [12] 1919 	add	a,#0x0e
      000762 F8               [12] 1920 	mov	r0,a
      000763 06               [12] 1921 	inc	@r0
      000764 B6 00 02         [24] 1922 	cjne	@r0,#0x00,00206$
      000767 08               [12] 1923 	inc	r0
      000768 06               [12] 1924 	inc	@r0
      000769                       1925 00206$:
      000769 02 05 75         [24] 1926 	ljmp	00119$
      00076C                       1927 00117$:
                           0006B5  1928 	C$fuzzy.h$970$1_0$42 ==.
                                   1929 ;	../../fuzzy.h:970: result
      00076C E5 08            [12] 1930 	mov	a,_bp
      00076E 24 0A            [12] 1931 	add	a,#0x0a
      000770 F8               [12] 1932 	mov	r0,a
      000771 86 82            [24] 1933 	mov	dpl, @r0
      000773 08               [12] 1934 	inc	r0
      000774 86 83            [24] 1935 	mov	dph, @r0
      000776 08               [12] 1936 	inc	r0
      000777 86 F0            [24] 1937 	mov	b, @r0
      000779 08               [12] 1938 	inc	r0
      00077A E6               [12] 1939 	mov	a, @r0
      00077B 12 00 EA         [24] 1940 	lcall	_fuzzy_clamp
      00077E                       1941 00121$:
                           0006C7  1942 	C$fuzzy.h$972$1_0$42 ==.
                                   1943 ;	../../fuzzy.h:972: }
      00077E 85 08 81         [24] 1944 	mov	sp,_bp
      000781 D0 08            [24] 1945 	pop	_bp
                           0006CC  1946 	C$fuzzy.h$972$1_0$42 ==.
                           0006CC  1947 	XG$fuzzy_or_array$0$0 ==.
      000783 22               [24] 1948 	ret
                                   1949 ;------------------------------------------------------------
                                   1950 ;Allocation info for local variables in function 'fuzzy_sugeno_weighted_average_array'
                                   1951 ;------------------------------------------------------------
                                   1952 ;values        Allocated to stack - _bp -5 +3 
                                   1953 ;value_count   Allocated to stack - _bp +1 +2 
                                   1954 ;weighted_sum  Allocated to stack - _bp +3 +4 
                                   1955 ;firing_sum    Allocated to stack - _bp +7 +4 
                                   1956 ;firing_strength Allocated to stack - _bp +11 +4 
                                   1957 ;consequent    Allocated to registers r4 r5 r3 r2 
                                   1958 ;index         Allocated to registers r6 r7 
                                   1959 ;------------------------------------------------------------
                           0006CD  1960 	G$fuzzy_sugeno_weighted_average_array$0$0 ==.
                           0006CD  1961 	C$fuzzy.h$983$1_0$51 ==.
                                   1962 ;	../../fuzzy.h:983: float fuzzy_sugeno_weighted_average_array(
                                   1963 ;	-----------------------------------------
                                   1964 ;	 function fuzzy_sugeno_weighted_average_array
                                   1965 ;	-----------------------------------------
      000784                       1966 _fuzzy_sugeno_weighted_average_array:
      000784 C0 08            [24] 1967 	push	_bp
      000786 85 81 08         [24] 1968 	mov	_bp,sp
      000789 C0 82            [24] 1969 	push	dpl
      00078B C0 83            [24] 1970 	push	dph
      00078D E5 81            [12] 1971 	mov	a,sp
      00078F 24 0C            [12] 1972 	add	a,#0x0c
      000791 F5 81            [12] 1973 	mov	sp,a
                           0006DC  1974 	C$fuzzy.h$996$1_0$51 ==.
                                   1975 ;	../../fuzzy.h:996: values == NULL ||
      000793 E5 08            [12] 1976 	mov	a,_bp
      000795 24 FB            [12] 1977 	add	a,#0xfb
      000797 F8               [12] 1978 	mov	r0,a
      000798 E6               [12] 1979 	mov	a,@r0
      000799 08               [12] 1980 	inc	r0
      00079A 46               [12] 1981 	orl	a,@r0
      00079B 60 0F            [24] 1982 	jz	00101$
                           0006E6  1983 	C$fuzzy.h$997$1_0$51 ==.
                                   1984 ;	../../fuzzy.h:997: value_count == 0u ||
      00079D A8 08            [24] 1985 	mov	r0,_bp
      00079F 08               [12] 1986 	inc	r0
      0007A0 E6               [12] 1987 	mov	a,@r0
      0007A1 08               [12] 1988 	inc	r0
      0007A2 46               [12] 1989 	orl	a,@r0
      0007A3 60 07            [24] 1990 	jz	00101$
                           0006EE  1991 	C$fuzzy.h$998$1_0$51 ==.
                                   1992 ;	../../fuzzy.h:998: value_count % 2u != 0u
      0007A5 A8 08            [24] 1993 	mov	r0,_bp
      0007A7 08               [12] 1994 	inc	r0
      0007A8 E6               [12] 1995 	mov	a,@r0
      0007A9 30 E0 09         [24] 1996 	jnb	acc.0,00102$
      0007AC                       1997 00101$:
                           0006F5  1998 	C$fuzzy.h$1000$2_0$52 ==.
                                   1999 ;	../../fuzzy.h:1000: return 0.0f;
      0007AC 90 00 00         [24] 2000 	mov	dptr,#0x0000
      0007AF E4               [12] 2001 	clr	a
      0007B0 F5 F0            [12] 2002 	mov	b,a
      0007B2 02 09 7F         [24] 2003 	ljmp	00111$
      0007B5                       2004 00102$:
                           0006FE  2005 	C$fuzzy.h$1004$1_0$51 ==.
                                   2006 ;	../../fuzzy.h:1004: 0.0f;
      0007B5 E5 08            [12] 2007 	mov	a,_bp
      0007B7 24 03            [12] 2008 	add	a,#0x03
      0007B9 F8               [12] 2009 	mov	r0,a
      0007BA E4               [12] 2010 	clr	a
      0007BB F6               [12] 2011 	mov	@r0,a
      0007BC 08               [12] 2012 	inc	r0
      0007BD F6               [12] 2013 	mov	@r0,a
      0007BE 08               [12] 2014 	inc	r0
      0007BF F6               [12] 2015 	mov	@r0,a
      0007C0 08               [12] 2016 	inc	r0
      0007C1 F6               [12] 2017 	mov	@r0,a
                           00070B  2018 	C$fuzzy.h$1007$1_0$51 ==.
                                   2019 ;	../../fuzzy.h:1007: 0.0f;
      0007C2 E5 08            [12] 2020 	mov	a,_bp
      0007C4 24 07            [12] 2021 	add	a,#0x07
      0007C6 F8               [12] 2022 	mov	r0,a
      0007C7 E4               [12] 2023 	clr	a
      0007C8 F6               [12] 2024 	mov	@r0,a
      0007C9 08               [12] 2025 	inc	r0
      0007CA F6               [12] 2026 	mov	@r0,a
      0007CB 08               [12] 2027 	inc	r0
      0007CC F6               [12] 2028 	mov	@r0,a
      0007CD 08               [12] 2029 	inc	r0
      0007CE F6               [12] 2030 	mov	@r0,a
                           000718  2031 	C$fuzzy.h$1010$1_0$51 ==.
                                   2032 ;	../../fuzzy.h:1010: index = 0u;
      0007CF FE               [12] 2033 	mov	r6,a
      0007D0 FF               [12] 2034 	mov	r7,a
      0007D1                       2035 00109$:
                           00071A  2036 	C$fuzzy.h$1011$2_0$53 ==.
                                   2037 ;	../../fuzzy.h:1011: index < value_count;
      0007D1 A8 08            [24] 2038 	mov	r0,_bp
      0007D3 08               [12] 2039 	inc	r0
      0007D4 C3               [12] 2040 	clr	c
      0007D5 EE               [12] 2041 	mov	a,r6
      0007D6 96               [12] 2042 	subb	a,@r0
      0007D7 EF               [12] 2043 	mov	a,r7
      0007D8 08               [12] 2044 	inc	r0
      0007D9 96               [12] 2045 	subb	a,@r0
      0007DA 40 03            [24] 2046 	jc	00147$
      0007DC 02 09 12         [24] 2047 	ljmp	00105$
      0007DF                       2048 00147$:
                           000728  2049 	C$fuzzy.h$1016$3_0$54 ==.
                                   2050 ;	../../fuzzy.h:1016: values[index]
      0007DF EE               [12] 2051 	mov	a,r6
      0007E0 2E               [12] 2052 	add	a,r6
      0007E1 FC               [12] 2053 	mov	r4,a
      0007E2 EF               [12] 2054 	mov	a,r7
      0007E3 33               [12] 2055 	rlc	a
      0007E4 FD               [12] 2056 	mov	r5,a
      0007E5 EC               [12] 2057 	mov	a,r4
      0007E6 2C               [12] 2058 	add	a,r4
      0007E7 FC               [12] 2059 	mov	r4,a
      0007E8 ED               [12] 2060 	mov	a,r5
      0007E9 33               [12] 2061 	rlc	a
      0007EA FD               [12] 2062 	mov	r5,a
      0007EB E5 08            [12] 2063 	mov	a,_bp
      0007ED 24 FB            [12] 2064 	add	a,#0xfb
      0007EF F8               [12] 2065 	mov	r0,a
      0007F0 EC               [12] 2066 	mov	a,r4
      0007F1 26               [12] 2067 	add	a, @r0
      0007F2 FC               [12] 2068 	mov	r4,a
      0007F3 ED               [12] 2069 	mov	a,r5
      0007F4 08               [12] 2070 	inc	r0
      0007F5 36               [12] 2071 	addc	a, @r0
      0007F6 FD               [12] 2072 	mov	r5,a
      0007F7 08               [12] 2073 	inc	r0
      0007F8 86 03            [24] 2074 	mov	ar3,@r0
      0007FA 8C 82            [24] 2075 	mov	dpl,r4
      0007FC 8D 83            [24] 2076 	mov	dph,r5
      0007FE 8B F0            [24] 2077 	mov	b,r3
      000800 12 2E 2A         [24] 2078 	lcall	__gptrget
      000803 FC               [12] 2079 	mov	r4,a
      000804 A3               [24] 2080 	inc	dptr
      000805 12 2E 2A         [24] 2081 	lcall	__gptrget
      000808 FD               [12] 2082 	mov	r5,a
      000809 A3               [24] 2083 	inc	dptr
      00080A 12 2E 2A         [24] 2084 	lcall	__gptrget
      00080D FB               [12] 2085 	mov	r3,a
      00080E A3               [24] 2086 	inc	dptr
      00080F 12 2E 2A         [24] 2087 	lcall	__gptrget
      000812 8C 82            [24] 2088 	mov	dpl,r4
      000814 8D 83            [24] 2089 	mov	dph,r5
      000816 8B F0            [24] 2090 	mov	b,r3
      000818 C0 07            [24] 2091 	push	ar7
      00081A C0 06            [24] 2092 	push	ar6
      00081C 12 00 EA         [24] 2093 	lcall	_fuzzy_clamp
      00081F C8               [12] 2094 	xch	a,r0
      000820 E5 08            [12] 2095 	mov	a,_bp
      000822 24 0B            [12] 2096 	add	a,#0x0b
      000824 C8               [12] 2097 	xch	a,r0
      000825 A6 82            [24] 2098 	mov	@r0, dpl
      000827 08               [12] 2099 	inc	r0
      000828 A6 83            [24] 2100 	mov	@r0, dph
      00082A 08               [12] 2101 	inc	r0
      00082B A6 F0            [24] 2102 	mov	@r0, b
      00082D 08               [12] 2103 	inc	r0
      00082E F6               [12] 2104 	mov	@r0,a
      00082F D0 06            [24] 2105 	pop	ar6
      000831 D0 07            [24] 2106 	pop	ar7
                           00077C  2107 	C$fuzzy.h$1020$3_0$54 ==.
                                   2108 ;	../../fuzzy.h:1020: values[index + 1u];
      000833 74 01            [12] 2109 	mov	a,#0x01
      000835 2E               [12] 2110 	add	a, r6
      000836 FC               [12] 2111 	mov	r4,a
      000837 E4               [12] 2112 	clr	a
      000838 3F               [12] 2113 	addc	a, r7
      000839 FD               [12] 2114 	mov	r5,a
      00083A EC               [12] 2115 	mov	a,r4
      00083B 2C               [12] 2116 	add	a,r4
      00083C FC               [12] 2117 	mov	r4,a
      00083D ED               [12] 2118 	mov	a,r5
      00083E 33               [12] 2119 	rlc	a
      00083F FD               [12] 2120 	mov	r5,a
      000840 EC               [12] 2121 	mov	a,r4
      000841 2C               [12] 2122 	add	a,r4
      000842 FC               [12] 2123 	mov	r4,a
      000843 ED               [12] 2124 	mov	a,r5
      000844 33               [12] 2125 	rlc	a
      000845 FD               [12] 2126 	mov	r5,a
      000846 E5 08            [12] 2127 	mov	a,_bp
      000848 24 FB            [12] 2128 	add	a,#0xfb
      00084A F8               [12] 2129 	mov	r0,a
      00084B EC               [12] 2130 	mov	a,r4
      00084C 26               [12] 2131 	add	a, @r0
      00084D FC               [12] 2132 	mov	r4,a
      00084E ED               [12] 2133 	mov	a,r5
      00084F 08               [12] 2134 	inc	r0
      000850 36               [12] 2135 	addc	a, @r0
      000851 FD               [12] 2136 	mov	r5,a
      000852 08               [12] 2137 	inc	r0
      000853 86 03            [24] 2138 	mov	ar3,@r0
      000855 8C 82            [24] 2139 	mov	dpl,r4
      000857 8D 83            [24] 2140 	mov	dph,r5
      000859 8B F0            [24] 2141 	mov	b,r3
      00085B 12 2E 2A         [24] 2142 	lcall	__gptrget
      00085E FC               [12] 2143 	mov	r4,a
      00085F A3               [24] 2144 	inc	dptr
      000860 12 2E 2A         [24] 2145 	lcall	__gptrget
      000863 FD               [12] 2146 	mov	r5,a
      000864 A3               [24] 2147 	inc	dptr
      000865 12 2E 2A         [24] 2148 	lcall	__gptrget
      000868 FB               [12] 2149 	mov	r3,a
      000869 A3               [24] 2150 	inc	dptr
      00086A 12 2E 2A         [24] 2151 	lcall	__gptrget
      00086D FA               [12] 2152 	mov	r2,a
                           0007B7  2153 	C$fuzzy.h$1025$1_0$51 ==.
                                   2154 ;	../../fuzzy.h:1025: consequent;
      00086E C0 07            [24] 2155 	push	ar7
      000870 C0 06            [24] 2156 	push	ar6
      000872 C0 04            [24] 2157 	push	ar4
      000874 C0 05            [24] 2158 	push	ar5
      000876 C0 03            [24] 2159 	push	ar3
      000878 C0 02            [24] 2160 	push	ar2
      00087A E5 08            [12] 2161 	mov	a,_bp
      00087C 24 0B            [12] 2162 	add	a,#0x0b
      00087E F8               [12] 2163 	mov	r0,a
      00087F 86 82            [24] 2164 	mov	dpl, @r0
      000881 08               [12] 2165 	inc	r0
      000882 86 83            [24] 2166 	mov	dph, @r0
      000884 08               [12] 2167 	inc	r0
      000885 86 F0            [24] 2168 	mov	b, @r0
      000887 08               [12] 2169 	inc	r0
      000888 E6               [12] 2170 	mov	a, @r0
      000889 12 2A CE         [24] 2171 	lcall	___fsmul
      00088C AA 82            [24] 2172 	mov	r2, dpl
      00088E AB 83            [24] 2173 	mov	r3, dph
      000890 AC F0            [24] 2174 	mov	r4, b
      000892 FD               [12] 2175 	mov	r5, a
      000893 E5 81            [12] 2176 	mov	a,sp
      000895 24 FC            [12] 2177 	add	a,#0xfc
      000897 F5 81            [12] 2178 	mov	sp,a
      000899 C0 02            [24] 2179 	push	ar2
      00089B C0 03            [24] 2180 	push	ar3
      00089D C0 04            [24] 2181 	push	ar4
      00089F C0 05            [24] 2182 	push	ar5
                           0007EA  2183 	C$fuzzy.h$1028$1_0$51 ==.
                                   2184 ;	../../fuzzy.h:1028: firing_strength;
      0008A1 E5 08            [12] 2185 	mov	a,_bp
      0008A3 24 03            [12] 2186 	add	a,#0x03
      0008A5 F8               [12] 2187 	mov	r0,a
      0008A6 86 82            [24] 2188 	mov	dpl, @r0
      0008A8 08               [12] 2189 	inc	r0
      0008A9 86 83            [24] 2190 	mov	dph, @r0
      0008AB 08               [12] 2191 	inc	r0
      0008AC 86 F0            [24] 2192 	mov	b, @r0
      0008AE 08               [12] 2193 	inc	r0
      0008AF E6               [12] 2194 	mov	a, @r0
      0008B0 12 2C 50         [24] 2195 	lcall	___fsadd
      0008B3 A8 08            [24] 2196 	mov	r0,_bp
      0008B5 08               [12] 2197 	inc	r0
      0008B6 08               [12] 2198 	inc	r0
      0008B7 08               [12] 2199 	inc	r0
      0008B8 A6 82            [24] 2200 	mov	@r0, dpl
      0008BA 08               [12] 2201 	inc	r0
      0008BB A6 83            [24] 2202 	mov	@r0, dph
      0008BD 08               [12] 2203 	inc	r0
      0008BE A6 F0            [24] 2204 	mov	@r0, b
      0008C0 08               [12] 2205 	inc	r0
      0008C1 F6               [12] 2206 	mov	@r0,a
      0008C2 E5 81            [12] 2207 	mov	a,sp
      0008C4 24 FC            [12] 2208 	add	a,#0xfc
      0008C6 F5 81            [12] 2209 	mov	sp,a
      0008C8 E5 08            [12] 2210 	mov	a,_bp
      0008CA 24 0B            [12] 2211 	add	a,#0x0b
      0008CC F8               [12] 2212 	mov	r0,a
      0008CD E6               [12] 2213 	mov	a,@r0
      0008CE C0 E0            [24] 2214 	push	acc
      0008D0 08               [12] 2215 	inc	r0
      0008D1 E6               [12] 2216 	mov	a,@r0
      0008D2 C0 E0            [24] 2217 	push	acc
      0008D4 08               [12] 2218 	inc	r0
      0008D5 E6               [12] 2219 	mov	a,@r0
      0008D6 C0 E0            [24] 2220 	push	acc
      0008D8 08               [12] 2221 	inc	r0
      0008D9 E6               [12] 2222 	mov	a,@r0
      0008DA C0 E0            [24] 2223 	push	acc
                           000825  2224 	C$fuzzy.h$1013$1_0$51 ==.
                                   2225 ;	../../fuzzy.h:1013: ) {
      0008DC E5 08            [12] 2226 	mov	a,_bp
      0008DE 24 07            [12] 2227 	add	a,#0x07
      0008E0 F8               [12] 2228 	mov	r0,a
      0008E1 86 82            [24] 2229 	mov	dpl, @r0
      0008E3 08               [12] 2230 	inc	r0
      0008E4 86 83            [24] 2231 	mov	dph, @r0
      0008E6 08               [12] 2232 	inc	r0
      0008E7 86 F0            [24] 2233 	mov	b, @r0
      0008E9 08               [12] 2234 	inc	r0
      0008EA E6               [12] 2235 	mov	a, @r0
      0008EB 12 2C 50         [24] 2236 	lcall	___fsadd
      0008EE C8               [12] 2237 	xch	a,r0
      0008EF E5 08            [12] 2238 	mov	a,_bp
      0008F1 24 07            [12] 2239 	add	a,#0x07
      0008F3 C8               [12] 2240 	xch	a,r0
      0008F4 A6 82            [24] 2241 	mov	@r0, dpl
      0008F6 08               [12] 2242 	inc	r0
      0008F7 A6 83            [24] 2243 	mov	@r0, dph
      0008F9 08               [12] 2244 	inc	r0
      0008FA A6 F0            [24] 2245 	mov	@r0, b
      0008FC 08               [12] 2246 	inc	r0
      0008FD F6               [12] 2247 	mov	@r0,a
      0008FE E5 81            [12] 2248 	mov	a,sp
      000900 24 FC            [12] 2249 	add	a,#0xfc
      000902 F5 81            [12] 2250 	mov	sp,a
      000904 D0 06            [24] 2251 	pop	ar6
      000906 D0 07            [24] 2252 	pop	ar7
      000908 74 02            [12] 2253 	mov	a,#0x02
      00090A 2E               [12] 2254 	add	a, r6
      00090B FE               [12] 2255 	mov	r6,a
      00090C E4               [12] 2256 	clr	a
      00090D 3F               [12] 2257 	addc	a, r7
      00090E FF               [12] 2258 	mov	r7,a
      00090F 02 07 D1         [24] 2259 	ljmp	00109$
      000912                       2260 00105$:
                           00085B  2261 	C$fuzzy.h$1031$1_0$51 ==.
                                   2262 ;	../../fuzzy.h:1031: if (firing_sum <= LEVEL_LO) {
      000912 E5 08            [12] 2263 	mov	a,_bp
      000914 24 07            [12] 2264 	add	a,#0x07
      000916 F8               [12] 2265 	mov	r0,a
      000917 E6               [12] 2266 	mov	a,@r0
      000918 C0 E0            [24] 2267 	push	acc
      00091A 08               [12] 2268 	inc	r0
      00091B E6               [12] 2269 	mov	a,@r0
      00091C C0 E0            [24] 2270 	push	acc
      00091E 08               [12] 2271 	inc	r0
      00091F E6               [12] 2272 	mov	a,@r0
      000920 C0 E0            [24] 2273 	push	acc
      000922 08               [12] 2274 	inc	r0
      000923 E6               [12] 2275 	mov	a,@r0
      000924 C0 E0            [24] 2276 	push	acc
      000926 90 00 00         [24] 2277 	mov	dptr,#0x0000
      000929 E4               [12] 2278 	clr	a
      00092A F5 F0            [12] 2279 	mov	b,a
      00092C 12 2B FE         [24] 2280 	lcall	___fslt
      00092F E5 81            [12] 2281 	mov	a,sp
      000931 24 FC            [12] 2282 	add	a,#0xfc
      000933 F5 81            [12] 2283 	mov	sp,a
      000935 E5 82            [12] 2284 	mov	a, dpl
      000937 24 FF            [12] 2285 	add	a,#0xff
      000939 92 00            [24] 2286 	mov	b0,c
      00093B 40 08            [24] 2287 	jc	00107$
                           000886  2288 	C$fuzzy.h$1032$2_0$55 ==.
                                   2289 ;	../../fuzzy.h:1032: return 0.0f;
      00093D 90 00 00         [24] 2290 	mov	dptr,#0x0000
      000940 E4               [12] 2291 	clr	a
      000941 F5 F0            [12] 2292 	mov	b,a
      000943 80 3A            [24] 2293 	sjmp	00111$
      000945                       2294 00107$:
                           00088E  2295 	C$fuzzy.h$1036$1_0$51 ==.
                                   2296 ;	../../fuzzy.h:1036: firing_sum;
      000945 E5 08            [12] 2297 	mov	a,_bp
      000947 24 07            [12] 2298 	add	a,#0x07
      000949 F8               [12] 2299 	mov	r0,a
      00094A E6               [12] 2300 	mov	a,@r0
      00094B C0 E0            [24] 2301 	push	acc
      00094D 08               [12] 2302 	inc	r0
      00094E E6               [12] 2303 	mov	a,@r0
      00094F C0 E0            [24] 2304 	push	acc
      000951 08               [12] 2305 	inc	r0
      000952 E6               [12] 2306 	mov	a,@r0
      000953 C0 E0            [24] 2307 	push	acc
      000955 08               [12] 2308 	inc	r0
      000956 E6               [12] 2309 	mov	a,@r0
      000957 C0 E0            [24] 2310 	push	acc
      000959 E5 08            [12] 2311 	mov	a,_bp
      00095B 24 03            [12] 2312 	add	a,#0x03
      00095D F8               [12] 2313 	mov	r0,a
      00095E 86 82            [24] 2314 	mov	dpl, @r0
      000960 08               [12] 2315 	inc	r0
      000961 86 83            [24] 2316 	mov	dph, @r0
      000963 08               [12] 2317 	inc	r0
      000964 86 F0            [24] 2318 	mov	b, @r0
      000966 08               [12] 2319 	inc	r0
      000967 E6               [12] 2320 	mov	a, @r0
      000968 12 2D 67         [24] 2321 	lcall	___fsdiv
      00096B AC 82            [24] 2322 	mov	r4, dpl
      00096D AD 83            [24] 2323 	mov	r5, dph
      00096F AE F0            [24] 2324 	mov	r6, b
      000971 FF               [12] 2325 	mov	r7, a
      000972 E5 81            [12] 2326 	mov	a,sp
      000974 24 FC            [12] 2327 	add	a,#0xfc
      000976 F5 81            [12] 2328 	mov	sp,a
      000978 8C 82            [24] 2329 	mov	dpl, r4
      00097A 8D 83            [24] 2330 	mov	dph, r5
      00097C 8E F0            [24] 2331 	mov	b, r6
      00097E EF               [12] 2332 	mov	a, r7
      00097F                       2333 00111$:
                           0008C8  2334 	C$fuzzy.h$1037$1_0$51 ==.
                                   2335 ;	../../fuzzy.h:1037: }
      00097F 85 08 81         [24] 2336 	mov	sp,_bp
      000982 D0 08            [24] 2337 	pop	_bp
                           0008CD  2338 	C$fuzzy.h$1037$1_0$51 ==.
                           0008CD  2339 	XG$fuzzy_sugeno_weighted_average_array$0$0 ==.
      000984 22               [24] 2340 	ret
                                   2341 ;------------------------------------------------------------
                                   2342 ;Allocation info for local variables in function 'fuzzy_sugeno_weighted_sum_array'
                                   2343 ;------------------------------------------------------------
                                   2344 ;values        Allocated to stack - _bp -5 +3 
                                   2345 ;value_count   Allocated to registers r6 r7 
                                   2346 ;weighted_sum  Allocated to stack - _bp +1 +4 
                                   2347 ;firing_strength Allocated to stack - _bp +5 +4 
                                   2348 ;consequent    Allocated to registers r6 r7 r3 r2 
                                   2349 ;index         Allocated to registers r4 r5 
                                   2350 ;------------------------------------------------------------
                           0008CE  2351 	G$fuzzy_sugeno_weighted_sum_array$0$0 ==.
                           0008CE  2352 	C$fuzzy.h$1047$1_0$57 ==.
                                   2353 ;	../../fuzzy.h:1047: float fuzzy_sugeno_weighted_sum_array(
                                   2354 ;	-----------------------------------------
                                   2355 ;	 function fuzzy_sugeno_weighted_sum_array
                                   2356 ;	-----------------------------------------
      000985                       2357 _fuzzy_sugeno_weighted_sum_array:
      000985 C0 08            [24] 2358 	push	_bp
      000987 E5 81            [12] 2359 	mov	a,sp
      000989 F5 08            [12] 2360 	mov	_bp,a
      00098B 24 08            [12] 2361 	add	a,#0x08
      00098D F5 81            [12] 2362 	mov	sp,a
      00098F AE 82            [24] 2363 	mov	r6, dpl
      000991 AF 83            [24] 2364 	mov	r7, dph
                           0008DC  2365 	C$fuzzy.h$1059$1_0$57 ==.
                                   2366 ;	../../fuzzy.h:1059: values == NULL ||
      000993 E5 08            [12] 2367 	mov	a,_bp
      000995 24 FB            [12] 2368 	add	a,#0xfb
      000997 F8               [12] 2369 	mov	r0,a
      000998 E6               [12] 2370 	mov	a,@r0
      000999 08               [12] 2371 	inc	r0
      00099A 46               [12] 2372 	orl	a,@r0
      00099B 60 08            [24] 2373 	jz	00101$
                           0008E6  2374 	C$fuzzy.h$1060$1_0$57 ==.
                                   2375 ;	../../fuzzy.h:1060: value_count == 0u ||
      00099D EE               [12] 2376 	mov	a,r6
      00099E 4F               [12] 2377 	orl	a,r7
      00099F 60 04            [24] 2378 	jz	00101$
                           0008EA  2379 	C$fuzzy.h$1061$1_0$57 ==.
                                   2380 ;	../../fuzzy.h:1061: value_count % 2u != 0u
      0009A1 EE               [12] 2381 	mov	a,r6
      0009A2 30 E0 09         [24] 2382 	jnb	acc.0,00102$
      0009A5                       2383 00101$:
                           0008EE  2384 	C$fuzzy.h$1063$2_0$58 ==.
                                   2385 ;	../../fuzzy.h:1063: return 0.0f;
      0009A5 90 00 00         [24] 2386 	mov	dptr,#0x0000
      0009A8 E4               [12] 2387 	clr	a
      0009A9 F5 F0            [12] 2388 	mov	b,a
      0009AB 02 0A E6         [24] 2389 	ljmp	00109$
      0009AE                       2390 00102$:
                           0008F7  2391 	C$fuzzy.h$1067$1_0$57 ==.
                                   2392 ;	../../fuzzy.h:1067: 0.0f;
      0009AE A8 08            [24] 2393 	mov	r0,_bp
      0009B0 08               [12] 2394 	inc	r0
      0009B1 E4               [12] 2395 	clr	a
      0009B2 F6               [12] 2396 	mov	@r0,a
      0009B3 08               [12] 2397 	inc	r0
      0009B4 F6               [12] 2398 	mov	@r0,a
      0009B5 08               [12] 2399 	inc	r0
      0009B6 F6               [12] 2400 	mov	@r0,a
      0009B7 08               [12] 2401 	inc	r0
      0009B8 F6               [12] 2402 	mov	@r0,a
                           000902  2403 	C$fuzzy.h$1070$1_0$57 ==.
                                   2404 ;	../../fuzzy.h:1070: index = 0u;
      0009B9 FC               [12] 2405 	mov	r4,a
      0009BA FD               [12] 2406 	mov	r5,a
      0009BB                       2407 00107$:
                           000904  2408 	C$fuzzy.h$1071$2_0$59 ==.
                                   2409 ;	../../fuzzy.h:1071: index < value_count;
      0009BB C3               [12] 2410 	clr	c
      0009BC EC               [12] 2411 	mov	a,r4
      0009BD 9E               [12] 2412 	subb	a,r6
      0009BE ED               [12] 2413 	mov	a,r5
      0009BF 9F               [12] 2414 	subb	a,r7
      0009C0 40 03            [24] 2415 	jc	00139$
      0009C2 02 0A D9         [24] 2416 	ljmp	00105$
      0009C5                       2417 00139$:
                           00090E  2418 	C$fuzzy.h$1076$1_0$57 ==.
                                   2419 ;	../../fuzzy.h:1076: values[index]
      0009C5 C0 06            [24] 2420 	push	ar6
      0009C7 C0 07            [24] 2421 	push	ar7
      0009C9 EC               [12] 2422 	mov	a,r4
      0009CA 2C               [12] 2423 	add	a,r4
      0009CB FA               [12] 2424 	mov	r2,a
      0009CC ED               [12] 2425 	mov	a,r5
      0009CD 33               [12] 2426 	rlc	a
      0009CE FB               [12] 2427 	mov	r3,a
      0009CF EA               [12] 2428 	mov	a,r2
      0009D0 2A               [12] 2429 	add	a,r2
      0009D1 FA               [12] 2430 	mov	r2,a
      0009D2 EB               [12] 2431 	mov	a,r3
      0009D3 33               [12] 2432 	rlc	a
      0009D4 FB               [12] 2433 	mov	r3,a
      0009D5 E5 08            [12] 2434 	mov	a,_bp
      0009D7 24 FB            [12] 2435 	add	a,#0xfb
      0009D9 F8               [12] 2436 	mov	r0,a
      0009DA EA               [12] 2437 	mov	a,r2
      0009DB 26               [12] 2438 	add	a, @r0
      0009DC FA               [12] 2439 	mov	r2,a
      0009DD EB               [12] 2440 	mov	a,r3
      0009DE 08               [12] 2441 	inc	r0
      0009DF 36               [12] 2442 	addc	a, @r0
      0009E0 FB               [12] 2443 	mov	r3,a
      0009E1 08               [12] 2444 	inc	r0
      0009E2 86 07            [24] 2445 	mov	ar7,@r0
      0009E4 8A 82            [24] 2446 	mov	dpl,r2
      0009E6 8B 83            [24] 2447 	mov	dph,r3
      0009E8 8F F0            [24] 2448 	mov	b,r7
      0009EA 12 2E 2A         [24] 2449 	lcall	__gptrget
      0009ED FA               [12] 2450 	mov	r2,a
      0009EE A3               [24] 2451 	inc	dptr
      0009EF 12 2E 2A         [24] 2452 	lcall	__gptrget
      0009F2 FB               [12] 2453 	mov	r3,a
      0009F3 A3               [24] 2454 	inc	dptr
      0009F4 12 2E 2A         [24] 2455 	lcall	__gptrget
      0009F7 FF               [12] 2456 	mov	r7,a
      0009F8 A3               [24] 2457 	inc	dptr
      0009F9 12 2E 2A         [24] 2458 	lcall	__gptrget
      0009FC FE               [12] 2459 	mov	r6,a
      0009FD 8A 82            [24] 2460 	mov	dpl,r2
      0009FF 8B 83            [24] 2461 	mov	dph,r3
      000A01 8F F0            [24] 2462 	mov	b,r7
      000A03 C0 07            [24] 2463 	push	ar7
      000A05 C0 06            [24] 2464 	push	ar6
      000A07 C0 05            [24] 2465 	push	ar5
      000A09 C0 04            [24] 2466 	push	ar4
      000A0B 12 00 EA         [24] 2467 	lcall	_fuzzy_clamp
      000A0E C8               [12] 2468 	xch	a,r0
      000A0F E5 08            [12] 2469 	mov	a,_bp
      000A11 24 05            [12] 2470 	add	a,#0x05
      000A13 C8               [12] 2471 	xch	a,r0
      000A14 A6 82            [24] 2472 	mov	@r0, dpl
      000A16 08               [12] 2473 	inc	r0
      000A17 A6 83            [24] 2474 	mov	@r0, dph
      000A19 08               [12] 2475 	inc	r0
      000A1A A6 F0            [24] 2476 	mov	@r0, b
      000A1C 08               [12] 2477 	inc	r0
      000A1D F6               [12] 2478 	mov	@r0,a
      000A1E D0 04            [24] 2479 	pop	ar4
      000A20 D0 05            [24] 2480 	pop	ar5
      000A22 D0 06            [24] 2481 	pop	ar6
      000A24 D0 07            [24] 2482 	pop	ar7
                           00096F  2483 	C$fuzzy.h$1080$3_0$60 ==.
                                   2484 ;	../../fuzzy.h:1080: values[index + 1u];
      000A26 74 01            [12] 2485 	mov	a,#0x01
      000A28 2C               [12] 2486 	add	a, r4
      000A29 FE               [12] 2487 	mov	r6,a
      000A2A E4               [12] 2488 	clr	a
      000A2B 3D               [12] 2489 	addc	a, r5
      000A2C FF               [12] 2490 	mov	r7,a
      000A2D EE               [12] 2491 	mov	a,r6
      000A2E 2E               [12] 2492 	add	a,r6
      000A2F FE               [12] 2493 	mov	r6,a
      000A30 EF               [12] 2494 	mov	a,r7
      000A31 33               [12] 2495 	rlc	a
      000A32 FF               [12] 2496 	mov	r7,a
      000A33 EE               [12] 2497 	mov	a,r6
      000A34 2E               [12] 2498 	add	a,r6
      000A35 FE               [12] 2499 	mov	r6,a
      000A36 EF               [12] 2500 	mov	a,r7
      000A37 33               [12] 2501 	rlc	a
      000A38 FF               [12] 2502 	mov	r7,a
      000A39 E5 08            [12] 2503 	mov	a,_bp
      000A3B 24 FB            [12] 2504 	add	a,#0xfb
      000A3D F8               [12] 2505 	mov	r0,a
      000A3E EE               [12] 2506 	mov	a,r6
      000A3F 26               [12] 2507 	add	a, @r0
      000A40 FE               [12] 2508 	mov	r6,a
      000A41 EF               [12] 2509 	mov	a,r7
      000A42 08               [12] 2510 	inc	r0
      000A43 36               [12] 2511 	addc	a, @r0
      000A44 FF               [12] 2512 	mov	r7,a
      000A45 08               [12] 2513 	inc	r0
      000A46 86 03            [24] 2514 	mov	ar3,@r0
      000A48 8E 82            [24] 2515 	mov	dpl,r6
      000A4A 8F 83            [24] 2516 	mov	dph,r7
      000A4C 8B F0            [24] 2517 	mov	b,r3
      000A4E 12 2E 2A         [24] 2518 	lcall	__gptrget
      000A51 FE               [12] 2519 	mov	r6,a
      000A52 A3               [24] 2520 	inc	dptr
      000A53 12 2E 2A         [24] 2521 	lcall	__gptrget
      000A56 FF               [12] 2522 	mov	r7,a
      000A57 A3               [24] 2523 	inc	dptr
      000A58 12 2E 2A         [24] 2524 	lcall	__gptrget
      000A5B FB               [12] 2525 	mov	r3,a
      000A5C A3               [24] 2526 	inc	dptr
      000A5D 12 2E 2A         [24] 2527 	lcall	__gptrget
      000A60 FA               [12] 2528 	mov	r2,a
                           0009AA  2529 	C$fuzzy.h$1085$1_0$57 ==.
                                   2530 ;	../../fuzzy.h:1085: consequent;
      000A61 C0 05            [24] 2531 	push	ar5
      000A63 C0 04            [24] 2532 	push	ar4
      000A65 C0 06            [24] 2533 	push	ar6
      000A67 C0 07            [24] 2534 	push	ar7
      000A69 C0 03            [24] 2535 	push	ar3
      000A6B C0 02            [24] 2536 	push	ar2
      000A6D E5 08            [12] 2537 	mov	a,_bp
      000A6F 24 05            [12] 2538 	add	a,#0x05
      000A71 F8               [12] 2539 	mov	r0,a
      000A72 86 82            [24] 2540 	mov	dpl, @r0
      000A74 08               [12] 2541 	inc	r0
      000A75 86 83            [24] 2542 	mov	dph, @r0
      000A77 08               [12] 2543 	inc	r0
      000A78 86 F0            [24] 2544 	mov	b, @r0
      000A7A 08               [12] 2545 	inc	r0
      000A7B E6               [12] 2546 	mov	a, @r0
      000A7C 12 2A CE         [24] 2547 	lcall	___fsmul
      000A7F AA 82            [24] 2548 	mov	r2, dpl
      000A81 AB 83            [24] 2549 	mov	r3, dph
      000A83 AE F0            [24] 2550 	mov	r6, b
      000A85 FF               [12] 2551 	mov	r7, a
      000A86 E5 81            [12] 2552 	mov	a,sp
      000A88 24 FC            [12] 2553 	add	a,#0xfc
      000A8A F5 81            [12] 2554 	mov	sp,a
      000A8C D0 04            [24] 2555 	pop	ar4
      000A8E D0 05            [24] 2556 	pop	ar5
      000A90 C0 07            [24] 2557 	push	ar7
      000A92 C0 06            [24] 2558 	push	ar6
      000A94 C0 05            [24] 2559 	push	ar5
      000A96 C0 04            [24] 2560 	push	ar4
      000A98 C0 02            [24] 2561 	push	ar2
      000A9A C0 03            [24] 2562 	push	ar3
      000A9C C0 06            [24] 2563 	push	ar6
      000A9E C0 07            [24] 2564 	push	ar7
                           0009E9  2565 	C$fuzzy.h$1073$1_0$57 ==.
                                   2566 ;	../../fuzzy.h:1073: ) {
      000AA0 A8 08            [24] 2567 	mov	r0,_bp
      000AA2 08               [12] 2568 	inc	r0
      000AA3 86 82            [24] 2569 	mov	dpl, @r0
      000AA5 08               [12] 2570 	inc	r0
      000AA6 86 83            [24] 2571 	mov	dph, @r0
      000AA8 08               [12] 2572 	inc	r0
      000AA9 86 F0            [24] 2573 	mov	b, @r0
      000AAB 08               [12] 2574 	inc	r0
      000AAC E6               [12] 2575 	mov	a, @r0
      000AAD 12 2C 50         [24] 2576 	lcall	___fsadd
      000AB0 A8 08            [24] 2577 	mov	r0,_bp
      000AB2 08               [12] 2578 	inc	r0
      000AB3 A6 82            [24] 2579 	mov	@r0, dpl
      000AB5 08               [12] 2580 	inc	r0
      000AB6 A6 83            [24] 2581 	mov	@r0, dph
      000AB8 08               [12] 2582 	inc	r0
      000AB9 A6 F0            [24] 2583 	mov	@r0, b
      000ABB 08               [12] 2584 	inc	r0
      000ABC F6               [12] 2585 	mov	@r0,a
      000ABD E5 81            [12] 2586 	mov	a,sp
      000ABF 24 FC            [12] 2587 	add	a,#0xfc
      000AC1 F5 81            [12] 2588 	mov	sp,a
      000AC3 D0 04            [24] 2589 	pop	ar4
      000AC5 D0 05            [24] 2590 	pop	ar5
      000AC7 D0 06            [24] 2591 	pop	ar6
      000AC9 D0 07            [24] 2592 	pop	ar7
      000ACB 74 02            [12] 2593 	mov	a,#0x02
      000ACD 2C               [12] 2594 	add	a, r4
      000ACE FC               [12] 2595 	mov	r4,a
      000ACF E4               [12] 2596 	clr	a
      000AD0 3D               [12] 2597 	addc	a, r5
      000AD1 FD               [12] 2598 	mov	r5,a
      000AD2 D0 07            [24] 2599 	pop	ar7
      000AD4 D0 06            [24] 2600 	pop	ar6
      000AD6 02 09 BB         [24] 2601 	ljmp	00107$
      000AD9                       2602 00105$:
                           000A22  2603 	C$fuzzy.h$1088$1_0$57 ==.
                                   2604 ;	../../fuzzy.h:1088: return weighted_sum;
      000AD9 A8 08            [24] 2605 	mov	r0,_bp
      000ADB 08               [12] 2606 	inc	r0
      000ADC 86 82            [24] 2607 	mov	dpl, @r0
      000ADE 08               [12] 2608 	inc	r0
      000ADF 86 83            [24] 2609 	mov	dph, @r0
      000AE1 08               [12] 2610 	inc	r0
      000AE2 86 F0            [24] 2611 	mov	b, @r0
      000AE4 08               [12] 2612 	inc	r0
      000AE5 E6               [12] 2613 	mov	a, @r0
      000AE6                       2614 00109$:
                           000A2F  2615 	C$fuzzy.h$1089$1_0$57 ==.
                                   2616 ;	../../fuzzy.h:1089: }
      000AE6 85 08 81         [24] 2617 	mov	sp,_bp
      000AE9 D0 08            [24] 2618 	pop	_bp
                           000A34  2619 	C$fuzzy.h$1089$1_0$57 ==.
                           000A34  2620 	XG$fuzzy_sugeno_weighted_sum_array$0$0 ==.
      000AEB 22               [24] 2621 	ret
                                   2622 ;------------------------------------------------------------
                                   2623 ;Allocation info for local variables in function 'fuzzy_ramp'
                                   2624 ;------------------------------------------------------------
                                   2625 ;upper_boundary Allocated to stack - _bp -6 +4 
                                   2626 ;value         Allocated to stack - _bp -10 +4 
                                   2627 ;ramp_up       Allocated to stack - _bp -11 +1 
                                   2628 ;hedge         Allocated to stack - _bp -12 +1 
                                   2629 ;lower_boundary Allocated to registers r7 r6 r5 r4 
                                   2630 ;result        Allocated to stack - _bp +5 +4 
                                   2631 ;normalized    Allocated to registers r4 r5 r6 r7 
                                   2632 ;sloc0         Allocated to stack - _bp +13 +4 
                                   2633 ;sloc1         Allocated to stack - _bp +1 +4 
                                   2634 ;------------------------------------------------------------
                           000A35  2635 	G$fuzzy_ramp$0$0 ==.
                           000A35  2636 	C$fuzzy.h$1095$1_0$62 ==.
                                   2637 ;	../../fuzzy.h:1095: float fuzzy_ramp(
                                   2638 ;	-----------------------------------------
                                   2639 ;	 function fuzzy_ramp
                                   2640 ;	-----------------------------------------
      000AEC                       2641 _fuzzy_ramp:
      000AEC C0 08            [24] 2642 	push	_bp
      000AEE 85 81 08         [24] 2643 	mov	_bp,sp
      000AF1 AF 82            [24] 2644 	mov	r7,dpl
      000AF3 AE 83            [24] 2645 	mov	r6,dph
      000AF5 AD F0            [24] 2646 	mov	r5,b
      000AF7 FC               [12] 2647 	mov	r4,a
      000AF8 E5 81            [12] 2648 	mov	a,sp
      000AFA 24 08            [12] 2649 	add	a,#0x08
      000AFC F5 81            [12] 2650 	mov	sp,a
                           000A47  2651 	C$fuzzy.h$1106$1_0$62 ==.
                                   2652 ;	../../fuzzy.h:1106: if (lower_boundary >= upper_boundary) {
      000AFE C0 07            [24] 2653 	push	ar7
      000B00 C0 06            [24] 2654 	push	ar6
      000B02 C0 05            [24] 2655 	push	ar5
      000B04 C0 04            [24] 2656 	push	ar4
      000B06 E5 08            [12] 2657 	mov	a,_bp
      000B08 24 FA            [12] 2658 	add	a,#0xfa
      000B0A F8               [12] 2659 	mov	r0,a
      000B0B E6               [12] 2660 	mov	a,@r0
      000B0C C0 E0            [24] 2661 	push	acc
      000B0E 08               [12] 2662 	inc	r0
      000B0F E6               [12] 2663 	mov	a,@r0
      000B10 C0 E0            [24] 2664 	push	acc
      000B12 08               [12] 2665 	inc	r0
      000B13 E6               [12] 2666 	mov	a,@r0
      000B14 C0 E0            [24] 2667 	push	acc
      000B16 08               [12] 2668 	inc	r0
      000B17 E6               [12] 2669 	mov	a,@r0
      000B18 C0 E0            [24] 2670 	push	acc
      000B1A 8F 82            [24] 2671 	mov	dpl, r7
      000B1C 8E 83            [24] 2672 	mov	dph, r6
      000B1E 8D F0            [24] 2673 	mov	b, r5
      000B20 EC               [12] 2674 	mov	a, r4
      000B21 12 2B FE         [24] 2675 	lcall	___fslt
      000B24 E5 81            [12] 2676 	mov	a,sp
      000B26 24 FC            [12] 2677 	add	a,#0xfc
      000B28 F5 81            [12] 2678 	mov	sp,a
      000B2A D0 04            [24] 2679 	pop	ar4
      000B2C D0 05            [24] 2680 	pop	ar5
      000B2E D0 06            [24] 2681 	pop	ar6
      000B30 D0 07            [24] 2682 	pop	ar7
      000B32 E5 82            [12] 2683 	mov	a, dpl
      000B34 24 FF            [12] 2684 	add	a,#0xff
      000B36 92 00            [24] 2685 	mov	b0,c
      000B38 40 09            [24] 2686 	jc	00102$
                           000A83  2687 	C$fuzzy.h$1107$2_0$63 ==.
                                   2688 ;	../../fuzzy.h:1107: return LEVEL_LO;
      000B3A 90 00 00         [24] 2689 	mov	dptr,#0x0000
      000B3D E4               [12] 2690 	clr	a
      000B3E F5 F0            [12] 2691 	mov	b,a
      000B40 02 0D 23         [24] 2692 	ljmp	00109$
      000B43                       2693 00102$:
                           000A8C  2694 	C$fuzzy.h$1110$1_0$62 ==.
                                   2695 ;	../../fuzzy.h:1110: if (value <= lower_boundary) {
      000B43 C0 07            [24] 2696 	push	ar7
      000B45 C0 06            [24] 2697 	push	ar6
      000B47 C0 05            [24] 2698 	push	ar5
      000B49 C0 04            [24] 2699 	push	ar4
      000B4B E5 08            [12] 2700 	mov	a,_bp
      000B4D 24 F6            [12] 2701 	add	a,#0xf6
      000B4F F8               [12] 2702 	mov	r0,a
      000B50 E6               [12] 2703 	mov	a,@r0
      000B51 C0 E0            [24] 2704 	push	acc
      000B53 08               [12] 2705 	inc	r0
      000B54 E6               [12] 2706 	mov	a,@r0
      000B55 C0 E0            [24] 2707 	push	acc
      000B57 08               [12] 2708 	inc	r0
      000B58 E6               [12] 2709 	mov	a,@r0
      000B59 C0 E0            [24] 2710 	push	acc
      000B5B 08               [12] 2711 	inc	r0
      000B5C E6               [12] 2712 	mov	a,@r0
      000B5D C0 E0            [24] 2713 	push	acc
      000B5F 8F 82            [24] 2714 	mov	dpl, r7
      000B61 8E 83            [24] 2715 	mov	dph, r6
      000B63 8D F0            [24] 2716 	mov	b, r5
      000B65 EC               [12] 2717 	mov	a, r4
      000B66 12 2B FE         [24] 2718 	lcall	___fslt
      000B69 E5 81            [12] 2719 	mov	a,sp
      000B6B 24 FC            [12] 2720 	add	a,#0xfc
      000B6D F5 81            [12] 2721 	mov	sp,a
      000B6F D0 04            [24] 2722 	pop	ar4
      000B71 D0 05            [24] 2723 	pop	ar5
      000B73 D0 06            [24] 2724 	pop	ar6
      000B75 D0 07            [24] 2725 	pop	ar7
      000B77 E5 82            [12] 2726 	mov	a, dpl
      000B79 24 FF            [12] 2727 	add	a,#0xff
      000B7B 92 00            [24] 2728 	mov	b0,c
      000B7D 40 39            [24] 2729 	jc	00107$
                           000AC8  2730 	C$fuzzy.h$1112$2_0$64 ==.
                                   2731 ;	../../fuzzy.h:1112: ramp_up
      000B7F E5 08            [12] 2732 	mov	a,_bp
      000B81 24 F5            [12] 2733 	add	a,#0xf5
      000B83 F8               [12] 2734 	mov	r0,a
      000B84 E6               [12] 2735 	mov	a,@r0
      000B85 60 0F            [24] 2736 	jz	00111$
                           000AD0  2737 	C$fuzzy.h$1113$2_0$64 ==.
                                   2738 ;	../../fuzzy.h:1113: ? LEVEL_LO
      000B87 E5 08            [12] 2739 	mov	a,_bp
      000B89 24 05            [12] 2740 	add	a,#0x05
      000B8B F8               [12] 2741 	mov	r0,a
      000B8C E4               [12] 2742 	clr	a
      000B8D F6               [12] 2743 	mov	@r0,a
      000B8E 08               [12] 2744 	inc	r0
      000B8F F6               [12] 2745 	mov	@r0,a
      000B90 08               [12] 2746 	inc	r0
      000B91 F6               [12] 2747 	mov	@r0,a
      000B92 08               [12] 2748 	inc	r0
      000B93 F6               [12] 2749 	mov	@r0,a
      000B94 80 0F            [24] 2750 	sjmp	00112$
      000B96                       2751 00111$:
                           000ADF  2752 	C$fuzzy.h$1114$2_0$64 ==.
                                   2753 ;	../../fuzzy.h:1114: : LEVEL_HI;
      000B96 E5 08            [12] 2754 	mov	a,_bp
      000B98 24 05            [12] 2755 	add	a,#0x05
      000B9A F8               [12] 2756 	mov	r0,a
      000B9B E4               [12] 2757 	clr	a
      000B9C F6               [12] 2758 	mov	@r0,a
      000B9D 08               [12] 2759 	inc	r0
      000B9E F6               [12] 2760 	mov	@r0,a
      000B9F 08               [12] 2761 	inc	r0
      000BA0 76 80            [12] 2762 	mov	@r0,#0x80
      000BA2 08               [12] 2763 	inc	r0
      000BA3 76 3F            [12] 2764 	mov	@r0,#0x3f
      000BA5                       2765 00112$:
      000BA5 E5 08            [12] 2766 	mov	a,_bp
      000BA7 24 05            [12] 2767 	add	a,#0x05
      000BA9 F8               [12] 2768 	mov	r0,a
      000BAA 86 07            [24] 2769 	mov	ar7,@r0
      000BAC 08               [12] 2770 	inc	r0
      000BAD 86 06            [24] 2771 	mov	ar6,@r0
      000BAF 08               [12] 2772 	inc	r0
      000BB0 86 05            [24] 2773 	mov	ar5,@r0
      000BB2 08               [12] 2774 	inc	r0
      000BB3 86 04            [24] 2775 	mov	ar4,@r0
      000BB5 02 0D 01         [24] 2776 	ljmp	00108$
      000BB8                       2777 00107$:
                           000B01  2778 	C$fuzzy.h$1116$1_0$62 ==.
                                   2779 ;	../../fuzzy.h:1116: else if (value >= upper_boundary) {
      000BB8 C0 07            [24] 2780 	push	ar7
      000BBA C0 06            [24] 2781 	push	ar6
      000BBC C0 05            [24] 2782 	push	ar5
      000BBE C0 04            [24] 2783 	push	ar4
      000BC0 E5 08            [12] 2784 	mov	a,_bp
      000BC2 24 FA            [12] 2785 	add	a,#0xfa
      000BC4 F8               [12] 2786 	mov	r0,a
      000BC5 E6               [12] 2787 	mov	a,@r0
      000BC6 C0 E0            [24] 2788 	push	acc
      000BC8 08               [12] 2789 	inc	r0
      000BC9 E6               [12] 2790 	mov	a,@r0
      000BCA C0 E0            [24] 2791 	push	acc
      000BCC 08               [12] 2792 	inc	r0
      000BCD E6               [12] 2793 	mov	a,@r0
      000BCE C0 E0            [24] 2794 	push	acc
      000BD0 08               [12] 2795 	inc	r0
      000BD1 E6               [12] 2796 	mov	a,@r0
      000BD2 C0 E0            [24] 2797 	push	acc
      000BD4 E5 08            [12] 2798 	mov	a,_bp
      000BD6 24 F6            [12] 2799 	add	a,#0xf6
      000BD8 F8               [12] 2800 	mov	r0,a
      000BD9 86 82            [24] 2801 	mov	dpl, @r0
      000BDB 08               [12] 2802 	inc	r0
      000BDC 86 83            [24] 2803 	mov	dph, @r0
      000BDE 08               [12] 2804 	inc	r0
      000BDF 86 F0            [24] 2805 	mov	b, @r0
      000BE1 08               [12] 2806 	inc	r0
      000BE2 E6               [12] 2807 	mov	a, @r0
      000BE3 12 2B FE         [24] 2808 	lcall	___fslt
      000BE6 E5 81            [12] 2809 	mov	a,sp
      000BE8 24 FC            [12] 2810 	add	a,#0xfc
      000BEA F5 81            [12] 2811 	mov	sp,a
      000BEC D0 04            [24] 2812 	pop	ar4
      000BEE D0 05            [24] 2813 	pop	ar5
      000BF0 D0 06            [24] 2814 	pop	ar6
      000BF2 D0 07            [24] 2815 	pop	ar7
      000BF4 E5 82            [12] 2816 	mov	a, dpl
      000BF6 24 FF            [12] 2817 	add	a,#0xff
      000BF8 92 00            [24] 2818 	mov	b0,c
      000BFA 40 39            [24] 2819 	jc	00104$
                           000B45  2820 	C$fuzzy.h$1118$2_0$65 ==.
                                   2821 ;	../../fuzzy.h:1118: ramp_up
      000BFC E5 08            [12] 2822 	mov	a,_bp
      000BFE 24 F5            [12] 2823 	add	a,#0xf5
      000C00 F8               [12] 2824 	mov	r0,a
      000C01 E6               [12] 2825 	mov	a,@r0
      000C02 60 11            [24] 2826 	jz	00113$
                           000B4D  2827 	C$fuzzy.h$1119$2_0$65 ==.
                                   2828 ;	../../fuzzy.h:1119: ? LEVEL_HI
      000C04 E5 08            [12] 2829 	mov	a,_bp
      000C06 24 05            [12] 2830 	add	a,#0x05
      000C08 F8               [12] 2831 	mov	r0,a
      000C09 E4               [12] 2832 	clr	a
      000C0A F6               [12] 2833 	mov	@r0,a
      000C0B 08               [12] 2834 	inc	r0
      000C0C F6               [12] 2835 	mov	@r0,a
      000C0D 08               [12] 2836 	inc	r0
      000C0E 76 80            [12] 2837 	mov	@r0,#0x80
      000C10 08               [12] 2838 	inc	r0
      000C11 76 3F            [12] 2839 	mov	@r0,#0x3f
      000C13 80 0D            [24] 2840 	sjmp	00114$
      000C15                       2841 00113$:
                           000B5E  2842 	C$fuzzy.h$1120$2_0$65 ==.
                                   2843 ;	../../fuzzy.h:1120: : LEVEL_LO;
      000C15 E5 08            [12] 2844 	mov	a,_bp
      000C17 24 05            [12] 2845 	add	a,#0x05
      000C19 F8               [12] 2846 	mov	r0,a
      000C1A E4               [12] 2847 	clr	a
      000C1B F6               [12] 2848 	mov	@r0,a
      000C1C 08               [12] 2849 	inc	r0
      000C1D F6               [12] 2850 	mov	@r0,a
      000C1E 08               [12] 2851 	inc	r0
      000C1F F6               [12] 2852 	mov	@r0,a
      000C20 08               [12] 2853 	inc	r0
      000C21 F6               [12] 2854 	mov	@r0,a
      000C22                       2855 00114$:
      000C22 E5 08            [12] 2856 	mov	a,_bp
      000C24 24 05            [12] 2857 	add	a,#0x05
      000C26 F8               [12] 2858 	mov	r0,a
      000C27 86 07            [24] 2859 	mov	ar7,@r0
      000C29 08               [12] 2860 	inc	r0
      000C2A 86 06            [24] 2861 	mov	ar6,@r0
      000C2C 08               [12] 2862 	inc	r0
      000C2D 86 05            [24] 2863 	mov	ar5,@r0
      000C2F 08               [12] 2864 	inc	r0
      000C30 86 04            [24] 2865 	mov	ar4,@r0
      000C32 02 0D 01         [24] 2866 	ljmp	00108$
      000C35                       2867 00104$:
                           000B7E  2868 	C$fuzzy.h$1124$1_0$62 ==.
                                   2869 ;	../../fuzzy.h:1124: (value - lower_boundary) /
      000C35 C0 07            [24] 2870 	push	ar7
      000C37 C0 06            [24] 2871 	push	ar6
      000C39 C0 05            [24] 2872 	push	ar5
      000C3B C0 04            [24] 2873 	push	ar4
      000C3D C0 07            [24] 2874 	push	ar7
      000C3F C0 06            [24] 2875 	push	ar6
      000C41 C0 05            [24] 2876 	push	ar5
      000C43 C0 04            [24] 2877 	push	ar4
                           000B8E  2878 	C$fuzzy.h$1125$1_0$62 ==.
                                   2879 ;	../../fuzzy.h:1125: (upper_boundary - lower_boundary);
      000C45 E5 08            [12] 2880 	mov	a,_bp
      000C47 24 F6            [12] 2881 	add	a,#0xf6
      000C49 F8               [12] 2882 	mov	r0,a
      000C4A 86 82            [24] 2883 	mov	dpl, @r0
      000C4C 08               [12] 2884 	inc	r0
      000C4D 86 83            [24] 2885 	mov	dph, @r0
      000C4F 08               [12] 2886 	inc	r0
      000C50 86 F0            [24] 2887 	mov	b, @r0
      000C52 08               [12] 2888 	inc	r0
      000C53 E6               [12] 2889 	mov	a, @r0
      000C54 12 2A C3         [24] 2890 	lcall	___fssub
      000C57 A8 08            [24] 2891 	mov	r0,_bp
      000C59 08               [12] 2892 	inc	r0
      000C5A A6 82            [24] 2893 	mov	@r0, dpl
      000C5C 08               [12] 2894 	inc	r0
      000C5D A6 83            [24] 2895 	mov	@r0, dph
      000C5F 08               [12] 2896 	inc	r0
      000C60 A6 F0            [24] 2897 	mov	@r0, b
      000C62 08               [12] 2898 	inc	r0
      000C63 F6               [12] 2899 	mov	@r0,a
      000C64 E5 81            [12] 2900 	mov	a,sp
      000C66 24 FC            [12] 2901 	add	a,#0xfc
      000C68 F5 81            [12] 2902 	mov	sp,a
      000C6A E5 08            [12] 2903 	mov	a,_bp
      000C6C 24 FA            [12] 2904 	add	a,#0xfa
      000C6E F8               [12] 2905 	mov	r0,a
      000C6F 86 82            [24] 2906 	mov	dpl, @r0
      000C71 08               [12] 2907 	inc	r0
      000C72 86 83            [24] 2908 	mov	dph, @r0
      000C74 08               [12] 2909 	inc	r0
      000C75 86 F0            [24] 2910 	mov	b, @r0
      000C77 08               [12] 2911 	inc	r0
      000C78 E6               [12] 2912 	mov	a, @r0
      000C79 12 2A C3         [24] 2913 	lcall	___fssub
      000C7C AC 82            [24] 2914 	mov	r4, dpl
      000C7E AD 83            [24] 2915 	mov	r5, dph
      000C80 AE F0            [24] 2916 	mov	r6, b
      000C82 FF               [12] 2917 	mov	r7, a
      000C83 E5 81            [12] 2918 	mov	a,sp
      000C85 24 FC            [12] 2919 	add	a,#0xfc
      000C87 F5 81            [12] 2920 	mov	sp,a
      000C89 C0 04            [24] 2921 	push	ar4
      000C8B C0 05            [24] 2922 	push	ar5
      000C8D C0 06            [24] 2923 	push	ar6
      000C8F C0 07            [24] 2924 	push	ar7
                           000BDA  2925 	C$fuzzy.h$1128$1_0$62 ==.
                                   2926 ;	../../fuzzy.h:1128: ramp_up
      000C91 A8 08            [24] 2927 	mov	r0,_bp
      000C93 08               [12] 2928 	inc	r0
      000C94 86 82            [24] 2929 	mov	dpl, @r0
      000C96 08               [12] 2930 	inc	r0
      000C97 86 83            [24] 2931 	mov	dph, @r0
      000C99 08               [12] 2932 	inc	r0
      000C9A 86 F0            [24] 2933 	mov	b, @r0
      000C9C 08               [12] 2934 	inc	r0
      000C9D E6               [12] 2935 	mov	a, @r0
      000C9E 12 2D 67         [24] 2936 	lcall	___fsdiv
      000CA1 AC 82            [24] 2937 	mov	r4, dpl
      000CA3 AD 83            [24] 2938 	mov	r5, dph
      000CA5 AE F0            [24] 2939 	mov	r6, b
      000CA7 FF               [12] 2940 	mov	r7, a
      000CA8 E5 81            [12] 2941 	mov	a,sp
      000CAA 24 FC            [12] 2942 	add	a,#0xfc
      000CAC F5 81            [12] 2943 	mov	sp,a
      000CAE E5 08            [12] 2944 	mov	a,_bp
      000CB0 24 F5            [12] 2945 	add	a,#0xf5
      000CB2 F8               [12] 2946 	mov	r0,a
      000CB3 E6               [12] 2947 	mov	a,@r0
      000CB4 60 12            [24] 2948 	jz	00115$
                           000BFF  2949 	C$fuzzy.h$1129$2_0$66 ==.
                                   2950 ;	../../fuzzy.h:1129: ? normalized
      000CB6 E5 08            [12] 2951 	mov	a,_bp
      000CB8 24 05            [12] 2952 	add	a,#0x05
      000CBA F8               [12] 2953 	mov	r0,a
      000CBB A6 04            [24] 2954 	mov	@r0,ar4
      000CBD 08               [12] 2955 	inc	r0
      000CBE A6 05            [24] 2956 	mov	@r0,ar5
      000CC0 08               [12] 2957 	inc	r0
      000CC1 A6 06            [24] 2958 	mov	@r0,ar6
      000CC3 08               [12] 2959 	inc	r0
      000CC4 A6 07            [24] 2960 	mov	@r0,ar7
      000CC6 80 29            [24] 2961 	sjmp	00116$
      000CC8                       2962 00115$:
                           000C11  2963 	C$fuzzy.h$1130$1_0$62 ==.
                                   2964 ;	../../fuzzy.h:1130: : LEVEL_HI - normalized;
      000CC8 C0 04            [24] 2965 	push	ar4
      000CCA C0 05            [24] 2966 	push	ar5
      000CCC C0 06            [24] 2967 	push	ar6
      000CCE C0 07            [24] 2968 	push	ar7
      000CD0 90 00 00         [24] 2969 	mov	dptr,#0x0000
      000CD3 75 F0 80         [24] 2970 	mov	b, #0x80
      000CD6 74 3F            [12] 2971 	mov	a, #0x3f
      000CD8 12 2A C3         [24] 2972 	lcall	___fssub
      000CDB C8               [12] 2973 	xch	a,r0
      000CDC E5 08            [12] 2974 	mov	a,_bp
      000CDE 24 05            [12] 2975 	add	a,#0x05
      000CE0 C8               [12] 2976 	xch	a,r0
      000CE1 A6 82            [24] 2977 	mov	@r0, dpl
      000CE3 08               [12] 2978 	inc	r0
      000CE4 A6 83            [24] 2979 	mov	@r0, dph
      000CE6 08               [12] 2980 	inc	r0
      000CE7 A6 F0            [24] 2981 	mov	@r0, b
      000CE9 08               [12] 2982 	inc	r0
      000CEA F6               [12] 2983 	mov	@r0,a
      000CEB E5 81            [12] 2984 	mov	a,sp
      000CED 24 FC            [12] 2985 	add	a,#0xfc
      000CEF F5 81            [12] 2986 	mov	sp,a
      000CF1                       2987 00116$:
      000CF1 E5 08            [12] 2988 	mov	a,_bp
      000CF3 24 05            [12] 2989 	add	a,#0x05
      000CF5 F8               [12] 2990 	mov	r0,a
      000CF6 86 07            [24] 2991 	mov	ar7,@r0
      000CF8 08               [12] 2992 	inc	r0
      000CF9 86 06            [24] 2993 	mov	ar6,@r0
      000CFB 08               [12] 2994 	inc	r0
      000CFC 86 05            [24] 2995 	mov	ar5,@r0
      000CFE 08               [12] 2996 	inc	r0
      000CFF 86 04            [24] 2997 	mov	ar4,@r0
      000D01                       2998 00108$:
                           000C4A  2999 	C$fuzzy.h$1134$1_0$62 ==.
                                   3000 ;	../../fuzzy.h:1134: result,
      000D01 E5 08            [12] 3001 	mov	a,_bp
      000D03 24 F4            [12] 3002 	add	a,#0xf4
      000D05 F8               [12] 3003 	mov	r0,a
      000D06 E6               [12] 3004 	mov	a,@r0
      000D07 C0 E0            [24] 3005 	push	acc
      000D09 8F 82            [24] 3006 	mov	dpl, r7
      000D0B 8E 83            [24] 3007 	mov	dph, r6
      000D0D 8D F0            [24] 3008 	mov	b, r5
      000D0F EC               [12] 3009 	mov	a, r4
      000D10 12 01 99         [24] 3010 	lcall	_fuzzy_apply_hedge
      000D13 AC 82            [24] 3011 	mov	r4, dpl
      000D15 AD 83            [24] 3012 	mov	r5, dph
      000D17 AE F0            [24] 3013 	mov	r6, b
      000D19 FF               [12] 3014 	mov	r7, a
      000D1A 15 81            [12] 3015 	dec	sp
      000D1C 8C 82            [24] 3016 	mov	dpl, r4
      000D1E 8D 83            [24] 3017 	mov	dph, r5
      000D20 8E F0            [24] 3018 	mov	b, r6
      000D22 EF               [12] 3019 	mov	a, r7
      000D23                       3020 00109$:
                           000C6C  3021 	C$fuzzy.h$1137$1_0$62 ==.
                                   3022 ;	../../fuzzy.h:1137: }
      000D23 85 08 81         [24] 3023 	mov	sp,_bp
      000D26 D0 08            [24] 3024 	pop	_bp
                           000C71  3025 	C$fuzzy.h$1137$1_0$62 ==.
                           000C71  3026 	XG$fuzzy_ramp$0$0 ==.
      000D28 22               [24] 3027 	ret
                                   3028 ;------------------------------------------------------------
                                   3029 ;Allocation info for local variables in function 'fuzzy_interpolate_membership'
                                   3030 ;------------------------------------------------------------
                                   3031 ;memberships   Allocated to stack - _bp -5 +3 
                                   3032 ;count         Allocated to stack - _bp -7 +2 
                                   3033 ;value         Allocated to stack - _bp -11 +4 
                                   3034 ;universe      Allocated to stack - _bp +1 +3 
                                   3035 ;index         Allocated to stack - _bp +14 +2 
                                   3036 ;ratio         Allocated to stack - _bp +16 +4 
                                   3037 ;sloc0         Allocated to stack - _bp +4 +4 
                                   3038 ;sloc1         Allocated to stack - _bp +8 +2 
                                   3039 ;sloc2         Allocated to stack - _bp +10 +4 
                                   3040 ;sloc3         Allocated to stack - _bp +20 +2 
                                   3041 ;------------------------------------------------------------
                           000C72  3042 	G$fuzzy_interpolate_membership$0$0 ==.
                           000C72  3043 	C$fuzzy.h$1139$1_0$68 ==.
                                   3044 ;	../../fuzzy.h:1139: float fuzzy_interpolate_membership(
                                   3045 ;	-----------------------------------------
                                   3046 ;	 function fuzzy_interpolate_membership
                                   3047 ;	-----------------------------------------
      000D29                       3048 _fuzzy_interpolate_membership:
      000D29 C0 08            [24] 3049 	push	_bp
      000D2B 85 81 08         [24] 3050 	mov	_bp,sp
      000D2E C0 82            [24] 3051 	push	dpl
      000D30 C0 83            [24] 3052 	push	dph
      000D32 C0 F0            [24] 3053 	push	b
      000D34 E5 81            [12] 3054 	mov	a,sp
      000D36 24 10            [12] 3055 	add	a,#0x10
      000D38 F5 81            [12] 3056 	mov	sp,a
                           000C83  3057 	C$fuzzy.h$1150$1_0$68 ==.
                                   3058 ;	../../fuzzy.h:1150: universe == NULL ||
      000D3A A8 08            [24] 3059 	mov	r0,_bp
      000D3C 08               [12] 3060 	inc	r0
      000D3D E6               [12] 3061 	mov	a,@r0
      000D3E 08               [12] 3062 	inc	r0
      000D3F 46               [12] 3063 	orl	a,@r0
      000D40 60 14            [24] 3064 	jz	00101$
                           000C8B  3065 	C$fuzzy.h$1151$1_0$68 ==.
                                   3066 ;	../../fuzzy.h:1151: memberships == NULL ||
      000D42 E5 08            [12] 3067 	mov	a,_bp
      000D44 24 FB            [12] 3068 	add	a,#0xfb
      000D46 F8               [12] 3069 	mov	r0,a
      000D47 E6               [12] 3070 	mov	a,@r0
      000D48 08               [12] 3071 	inc	r0
      000D49 46               [12] 3072 	orl	a,@r0
      000D4A 60 0A            [24] 3073 	jz	00101$
                           000C95  3074 	C$fuzzy.h$1152$1_0$68 ==.
                                   3075 ;	../../fuzzy.h:1152: count == 0u
      000D4C E5 08            [12] 3076 	mov	a,_bp
      000D4E 24 F9            [12] 3077 	add	a,#0xf9
      000D50 F8               [12] 3078 	mov	r0,a
      000D51 E6               [12] 3079 	mov	a,@r0
      000D52 08               [12] 3080 	inc	r0
      000D53 46               [12] 3081 	orl	a,@r0
      000D54 70 09            [24] 3082 	jnz	00102$
      000D56                       3083 00101$:
                           000C9F  3084 	C$fuzzy.h$1154$2_0$69 ==.
                                   3085 ;	../../fuzzy.h:1154: return LEVEL_LO;
      000D56 90 00 00         [24] 3086 	mov	dptr,#0x0000
      000D59 E4               [12] 3087 	clr	a
      000D5A F5 F0            [12] 3088 	mov	b,a
      000D5C 02 12 4D         [24] 3089 	ljmp	00118$
      000D5F                       3090 00102$:
                           000CA8  3091 	C$fuzzy.h$1157$1_0$68 ==.
                                   3092 ;	../../fuzzy.h:1157: if (value <= universe[0]) {
      000D5F A8 08            [24] 3093 	mov	r0,_bp
      000D61 08               [12] 3094 	inc	r0
      000D62 86 82            [24] 3095 	mov	dpl,@r0
      000D64 08               [12] 3096 	inc	r0
      000D65 86 83            [24] 3097 	mov	dph,@r0
      000D67 08               [12] 3098 	inc	r0
      000D68 86 F0            [24] 3099 	mov	b,@r0
      000D6A 12 2E 2A         [24] 3100 	lcall	__gptrget
      000D6D FA               [12] 3101 	mov	r2,a
      000D6E A3               [24] 3102 	inc	dptr
      000D6F 12 2E 2A         [24] 3103 	lcall	__gptrget
      000D72 FB               [12] 3104 	mov	r3,a
      000D73 A3               [24] 3105 	inc	dptr
      000D74 12 2E 2A         [24] 3106 	lcall	__gptrget
      000D77 FC               [12] 3107 	mov	r4,a
      000D78 A3               [24] 3108 	inc	dptr
      000D79 12 2E 2A         [24] 3109 	lcall	__gptrget
      000D7C FF               [12] 3110 	mov	r7,a
      000D7D E5 08            [12] 3111 	mov	a,_bp
      000D7F 24 F5            [12] 3112 	add	a,#0xf5
      000D81 F8               [12] 3113 	mov	r0,a
      000D82 E6               [12] 3114 	mov	a,@r0
      000D83 C0 E0            [24] 3115 	push	acc
      000D85 08               [12] 3116 	inc	r0
      000D86 E6               [12] 3117 	mov	a,@r0
      000D87 C0 E0            [24] 3118 	push	acc
      000D89 08               [12] 3119 	inc	r0
      000D8A E6               [12] 3120 	mov	a,@r0
      000D8B C0 E0            [24] 3121 	push	acc
      000D8D 08               [12] 3122 	inc	r0
      000D8E E6               [12] 3123 	mov	a,@r0
      000D8F C0 E0            [24] 3124 	push	acc
      000D91 8A 82            [24] 3125 	mov	dpl, r2
      000D93 8B 83            [24] 3126 	mov	dph, r3
      000D95 8C F0            [24] 3127 	mov	b, r4
      000D97 EF               [12] 3128 	mov	a, r7
      000D98 12 2B FE         [24] 3129 	lcall	___fslt
      000D9B E5 81            [12] 3130 	mov	a,sp
      000D9D 24 FC            [12] 3131 	add	a,#0xfc
      000D9F F5 81            [12] 3132 	mov	sp,a
      000DA1 E5 82            [12] 3133 	mov	a, dpl
      000DA3 24 FF            [12] 3134 	add	a,#0xff
      000DA5 92 00            [24] 3135 	mov	b0,c
      000DA7 40 31            [24] 3136 	jc	00106$
                           000CF2  3137 	C$fuzzy.h$1158$2_0$70 ==.
                                   3138 ;	../../fuzzy.h:1158: return fuzzy_clamp(memberships[0]);
      000DA9 E5 08            [12] 3139 	mov	a,_bp
      000DAB 24 FB            [12] 3140 	add	a,#0xfb
      000DAD F8               [12] 3141 	mov	r0,a
      000DAE 86 05            [24] 3142 	mov	ar5,@r0
      000DB0 08               [12] 3143 	inc	r0
      000DB1 86 06            [24] 3144 	mov	ar6,@r0
      000DB3 08               [12] 3145 	inc	r0
      000DB4 86 07            [24] 3146 	mov	ar7,@r0
      000DB6 8D 82            [24] 3147 	mov	dpl,r5
      000DB8 8E 83            [24] 3148 	mov	dph,r6
      000DBA 8F F0            [24] 3149 	mov	b,r7
      000DBC 12 2E 2A         [24] 3150 	lcall	__gptrget
      000DBF FD               [12] 3151 	mov	r5,a
      000DC0 A3               [24] 3152 	inc	dptr
      000DC1 12 2E 2A         [24] 3153 	lcall	__gptrget
      000DC4 FE               [12] 3154 	mov	r6,a
      000DC5 A3               [24] 3155 	inc	dptr
      000DC6 12 2E 2A         [24] 3156 	lcall	__gptrget
      000DC9 FF               [12] 3157 	mov	r7,a
      000DCA A3               [24] 3158 	inc	dptr
      000DCB 12 2E 2A         [24] 3159 	lcall	__gptrget
      000DCE 8D 82            [24] 3160 	mov	dpl,r5
      000DD0 8E 83            [24] 3161 	mov	dph,r6
      000DD2 8F F0            [24] 3162 	mov	b,r7
      000DD4 12 00 EA         [24] 3163 	lcall	_fuzzy_clamp
      000DD7 02 12 4D         [24] 3164 	ljmp	00118$
      000DDA                       3165 00106$:
                           000D23  3166 	C$fuzzy.h$1161$1_0$68 ==.
                                   3167 ;	../../fuzzy.h:1161: if (value >= universe[count - 1u]) {
      000DDA E5 08            [12] 3168 	mov	a,_bp
      000DDC 24 F9            [12] 3169 	add	a,#0xf9
      000DDE F8               [12] 3170 	mov	r0,a
      000DDF E6               [12] 3171 	mov	a,@r0
      000DE0 24 FF            [12] 3172 	add	a,#0xff
      000DE2 FE               [12] 3173 	mov	r6,a
      000DE3 08               [12] 3174 	inc	r0
      000DE4 E6               [12] 3175 	mov	a,@r0
      000DE5 34 FF            [12] 3176 	addc	a,#0xff
      000DE7 FF               [12] 3177 	mov	r7,a
      000DE8 EE               [12] 3178 	mov	a,r6
      000DE9 2E               [12] 3179 	add	a,r6
      000DEA FE               [12] 3180 	mov	r6,a
      000DEB EF               [12] 3181 	mov	a,r7
      000DEC 33               [12] 3182 	rlc	a
      000DED FF               [12] 3183 	mov	r7,a
      000DEE EE               [12] 3184 	mov	a,r6
      000DEF 2E               [12] 3185 	add	a,r6
      000DF0 FE               [12] 3186 	mov	r6,a
      000DF1 EF               [12] 3187 	mov	a,r7
      000DF2 33               [12] 3188 	rlc	a
      000DF3 FF               [12] 3189 	mov	r7,a
      000DF4 A8 08            [24] 3190 	mov	r0,_bp
      000DF6 08               [12] 3191 	inc	r0
      000DF7 EE               [12] 3192 	mov	a,r6
      000DF8 26               [12] 3193 	add	a, @r0
      000DF9 FE               [12] 3194 	mov	r6,a
      000DFA EF               [12] 3195 	mov	a,r7
      000DFB 08               [12] 3196 	inc	r0
      000DFC 36               [12] 3197 	addc	a, @r0
      000DFD FF               [12] 3198 	mov	r7,a
      000DFE 08               [12] 3199 	inc	r0
      000DFF 86 05            [24] 3200 	mov	ar5,@r0
      000E01 8E 82            [24] 3201 	mov	dpl,r6
      000E03 8F 83            [24] 3202 	mov	dph,r7
      000E05 8D F0            [24] 3203 	mov	b,r5
      000E07 12 2E 2A         [24] 3204 	lcall	__gptrget
      000E0A FE               [12] 3205 	mov	r6,a
      000E0B A3               [24] 3206 	inc	dptr
      000E0C 12 2E 2A         [24] 3207 	lcall	__gptrget
      000E0F FF               [12] 3208 	mov	r7,a
      000E10 A3               [24] 3209 	inc	dptr
      000E11 12 2E 2A         [24] 3210 	lcall	__gptrget
      000E14 FD               [12] 3211 	mov	r5,a
      000E15 A3               [24] 3212 	inc	dptr
      000E16 12 2E 2A         [24] 3213 	lcall	__gptrget
      000E19 FC               [12] 3214 	mov	r4,a
      000E1A C0 06            [24] 3215 	push	ar6
      000E1C C0 07            [24] 3216 	push	ar7
      000E1E C0 05            [24] 3217 	push	ar5
      000E20 C0 04            [24] 3218 	push	ar4
      000E22 E5 08            [12] 3219 	mov	a,_bp
      000E24 24 F5            [12] 3220 	add	a,#0xf5
      000E26 F8               [12] 3221 	mov	r0,a
      000E27 86 82            [24] 3222 	mov	dpl, @r0
      000E29 08               [12] 3223 	inc	r0
      000E2A 86 83            [24] 3224 	mov	dph, @r0
      000E2C 08               [12] 3225 	inc	r0
      000E2D 86 F0            [24] 3226 	mov	b, @r0
      000E2F 08               [12] 3227 	inc	r0
      000E30 E6               [12] 3228 	mov	a, @r0
      000E31 12 2B FE         [24] 3229 	lcall	___fslt
      000E34 E5 81            [12] 3230 	mov	a,sp
      000E36 24 FC            [12] 3231 	add	a,#0xfc
      000E38 F5 81            [12] 3232 	mov	sp,a
      000E3A E5 82            [12] 3233 	mov	a, dpl
      000E3C 24 FF            [12] 3234 	add	a,#0xff
      000E3E 92 00            [24] 3235 	mov	b0,c
      000E40 40 4D            [24] 3236 	jc	00108$
                           000D8B  3237 	C$fuzzy.h$1162$2_0$71 ==.
                                   3238 ;	../../fuzzy.h:1162: return fuzzy_clamp(memberships[count - 1u]);
      000E42 E5 08            [12] 3239 	mov	a,_bp
      000E44 24 F9            [12] 3240 	add	a,#0xf9
      000E46 F8               [12] 3241 	mov	r0,a
      000E47 E6               [12] 3242 	mov	a,@r0
      000E48 24 FF            [12] 3243 	add	a,#0xff
      000E4A FE               [12] 3244 	mov	r6,a
      000E4B 08               [12] 3245 	inc	r0
      000E4C E6               [12] 3246 	mov	a,@r0
      000E4D 34 FF            [12] 3247 	addc	a,#0xff
      000E4F FF               [12] 3248 	mov	r7,a
      000E50 EE               [12] 3249 	mov	a,r6
      000E51 2E               [12] 3250 	add	a,r6
      000E52 FE               [12] 3251 	mov	r6,a
      000E53 EF               [12] 3252 	mov	a,r7
      000E54 33               [12] 3253 	rlc	a
      000E55 FF               [12] 3254 	mov	r7,a
      000E56 EE               [12] 3255 	mov	a,r6
      000E57 2E               [12] 3256 	add	a,r6
      000E58 FE               [12] 3257 	mov	r6,a
      000E59 EF               [12] 3258 	mov	a,r7
      000E5A 33               [12] 3259 	rlc	a
      000E5B FF               [12] 3260 	mov	r7,a
      000E5C E5 08            [12] 3261 	mov	a,_bp
      000E5E 24 FB            [12] 3262 	add	a,#0xfb
      000E60 F8               [12] 3263 	mov	r0,a
      000E61 EE               [12] 3264 	mov	a,r6
      000E62 26               [12] 3265 	add	a, @r0
      000E63 FE               [12] 3266 	mov	r6,a
      000E64 EF               [12] 3267 	mov	a,r7
      000E65 08               [12] 3268 	inc	r0
      000E66 36               [12] 3269 	addc	a, @r0
      000E67 FF               [12] 3270 	mov	r7,a
      000E68 08               [12] 3271 	inc	r0
      000E69 86 05            [24] 3272 	mov	ar5,@r0
      000E6B 8E 82            [24] 3273 	mov	dpl,r6
      000E6D 8F 83            [24] 3274 	mov	dph,r7
      000E6F 8D F0            [24] 3275 	mov	b,r5
      000E71 12 2E 2A         [24] 3276 	lcall	__gptrget
      000E74 FE               [12] 3277 	mov	r6,a
      000E75 A3               [24] 3278 	inc	dptr
      000E76 12 2E 2A         [24] 3279 	lcall	__gptrget
      000E79 FF               [12] 3280 	mov	r7,a
      000E7A A3               [24] 3281 	inc	dptr
      000E7B 12 2E 2A         [24] 3282 	lcall	__gptrget
      000E7E FD               [12] 3283 	mov	r5,a
      000E7F A3               [24] 3284 	inc	dptr
      000E80 12 2E 2A         [24] 3285 	lcall	__gptrget
      000E83 8E 82            [24] 3286 	mov	dpl,r6
      000E85 8F 83            [24] 3287 	mov	dph,r7
      000E87 8D F0            [24] 3288 	mov	b,r5
      000E89 12 00 EA         [24] 3289 	lcall	_fuzzy_clamp
      000E8C 02 12 4D         [24] 3290 	ljmp	00118$
      000E8F                       3291 00108$:
                           000DD8  3292 	C$fuzzy.h$1165$2_0$72 ==.
                                   3293 ;	../../fuzzy.h:1165: for (index = 0u; index + 1u < count; index++) {
      000E8F E4               [12] 3294 	clr	a
      000E90 FE               [12] 3295 	mov	r6,a
      000E91 FF               [12] 3296 	mov	r7,a
      000E92 E5 08            [12] 3297 	mov	a,_bp
      000E94 24 0E            [12] 3298 	add	a,#0x0e
      000E96 F8               [12] 3299 	mov	r0,a
      000E97 E4               [12] 3300 	clr	a
      000E98 F6               [12] 3301 	mov	@r0,a
      000E99 08               [12] 3302 	inc	r0
      000E9A F6               [12] 3303 	mov	@r0,a
      000E9B                       3304 00116$:
      000E9B E5 08            [12] 3305 	mov	a,_bp
      000E9D 24 0E            [12] 3306 	add	a,#0x0e
      000E9F F8               [12] 3307 	mov	r0,a
      000EA0 74 01            [12] 3308 	mov	a,#0x01
      000EA2 26               [12] 3309 	add	a, @r0
      000EA3 FA               [12] 3310 	mov	r2,a
      000EA4 E4               [12] 3311 	clr	a
      000EA5 08               [12] 3312 	inc	r0
      000EA6 36               [12] 3313 	addc	a, @r0
      000EA7 FB               [12] 3314 	mov	r3,a
      000EA8 E5 08            [12] 3315 	mov	a,_bp
      000EAA 24 F9            [12] 3316 	add	a,#0xf9
      000EAC F8               [12] 3317 	mov	r0,a
      000EAD C3               [12] 3318 	clr	c
      000EAE EA               [12] 3319 	mov	a,r2
      000EAF 96               [12] 3320 	subb	a,@r0
      000EB0 EB               [12] 3321 	mov	a,r3
      000EB1 08               [12] 3322 	inc	r0
      000EB2 96               [12] 3323 	subb	a,@r0
      000EB3 40 03            [24] 3324 	jc	00179$
      000EB5 02 12 47         [24] 3325 	ljmp	00114$
      000EB8                       3326 00179$:
                           000E01  3327 	C$fuzzy.h$1167$1_0$68 ==.
                                   3328 ;	../../fuzzy.h:1167: value >= universe[index] &&
      000EB8 C0 06            [24] 3329 	push	ar6
      000EBA C0 07            [24] 3330 	push	ar7
      000EBC E5 08            [12] 3331 	mov	a,_bp
      000EBE 24 0E            [12] 3332 	add	a,#0x0e
      000EC0 F8               [12] 3333 	mov	r0,a
      000EC1 E5 08            [12] 3334 	mov	a,_bp
      000EC3 24 08            [12] 3335 	add	a,#0x08
      000EC5 F9               [12] 3336 	mov	r1,a
      000EC6 E6               [12] 3337 	mov	a,@r0
      000EC7 26               [12] 3338 	add	a,@r0
      000EC8 F7               [12] 3339 	mov	@r1,a
      000EC9 08               [12] 3340 	inc	r0
      000ECA E6               [12] 3341 	mov	a,@r0
      000ECB 33               [12] 3342 	rlc	a
      000ECC 09               [12] 3343 	inc	r1
      000ECD F7               [12] 3344 	mov	@r1,a
      000ECE 19               [12] 3345 	dec	r1
      000ECF E7               [12] 3346 	mov	a,@r1
      000ED0 27               [12] 3347 	add	a,@r1
      000ED1 F7               [12] 3348 	mov	@r1,a
      000ED2 09               [12] 3349 	inc	r1
      000ED3 E7               [12] 3350 	mov	a,@r1
      000ED4 33               [12] 3351 	rlc	a
      000ED5 F7               [12] 3352 	mov	@r1,a
      000ED6 A8 08            [24] 3353 	mov	r0,_bp
      000ED8 08               [12] 3354 	inc	r0
      000ED9 E5 08            [12] 3355 	mov	a,_bp
      000EDB 24 08            [12] 3356 	add	a,#0x08
      000EDD F9               [12] 3357 	mov	r1,a
      000EDE E7               [12] 3358 	mov	a,@r1
      000EDF 26               [12] 3359 	add	a, @r0
      000EE0 FD               [12] 3360 	mov	r5,a
      000EE1 09               [12] 3361 	inc	r1
      000EE2 E7               [12] 3362 	mov	a,@r1
      000EE3 08               [12] 3363 	inc	r0
      000EE4 36               [12] 3364 	addc	a, @r0
      000EE5 FE               [12] 3365 	mov	r6,a
      000EE6 08               [12] 3366 	inc	r0
      000EE7 86 07            [24] 3367 	mov	ar7,@r0
      000EE9 8D 82            [24] 3368 	mov	dpl,r5
      000EEB 8E 83            [24] 3369 	mov	dph,r6
      000EED 8F F0            [24] 3370 	mov	b,r7
      000EEF E5 08            [12] 3371 	mov	a,_bp
      000EF1 24 04            [12] 3372 	add	a,#0x04
      000EF3 F8               [12] 3373 	mov	r0,a
      000EF4 12 2E 2A         [24] 3374 	lcall	__gptrget
      000EF7 F6               [12] 3375 	mov	@r0,a
      000EF8 A3               [24] 3376 	inc	dptr
      000EF9 12 2E 2A         [24] 3377 	lcall	__gptrget
      000EFC 08               [12] 3378 	inc	r0
      000EFD F6               [12] 3379 	mov	@r0,a
      000EFE A3               [24] 3380 	inc	dptr
      000EFF 12 2E 2A         [24] 3381 	lcall	__gptrget
      000F02 08               [12] 3382 	inc	r0
      000F03 F6               [12] 3383 	mov	@r0,a
      000F04 A3               [24] 3384 	inc	dptr
      000F05 12 2E 2A         [24] 3385 	lcall	__gptrget
      000F08 08               [12] 3386 	inc	r0
      000F09 F6               [12] 3387 	mov	@r0,a
      000F0A C0 07            [24] 3388 	push	ar7
      000F0C C0 06            [24] 3389 	push	ar6
      000F0E E5 08            [12] 3390 	mov	a,_bp
      000F10 24 04            [12] 3391 	add	a,#0x04
      000F12 F8               [12] 3392 	mov	r0,a
      000F13 E6               [12] 3393 	mov	a,@r0
      000F14 C0 E0            [24] 3394 	push	acc
      000F16 08               [12] 3395 	inc	r0
      000F17 E6               [12] 3396 	mov	a,@r0
      000F18 C0 E0            [24] 3397 	push	acc
      000F1A 08               [12] 3398 	inc	r0
      000F1B E6               [12] 3399 	mov	a,@r0
      000F1C C0 E0            [24] 3400 	push	acc
      000F1E 08               [12] 3401 	inc	r0
      000F1F E6               [12] 3402 	mov	a,@r0
      000F20 C0 E0            [24] 3403 	push	acc
      000F22 E5 08            [12] 3404 	mov	a,_bp
      000F24 24 F5            [12] 3405 	add	a,#0xf5
      000F26 F8               [12] 3406 	mov	r0,a
      000F27 86 82            [24] 3407 	mov	dpl, @r0
      000F29 08               [12] 3408 	inc	r0
      000F2A 86 83            [24] 3409 	mov	dph, @r0
      000F2C 08               [12] 3410 	inc	r0
      000F2D 86 F0            [24] 3411 	mov	b, @r0
      000F2F 08               [12] 3412 	inc	r0
      000F30 E6               [12] 3413 	mov	a, @r0
      000F31 12 2B FE         [24] 3414 	lcall	___fslt
      000F34 E5 81            [12] 3415 	mov	a,sp
      000F36 24 FC            [12] 3416 	add	a,#0xfc
      000F38 F5 81            [12] 3417 	mov	sp,a
      000F3A D0 06            [24] 3418 	pop	ar6
      000F3C D0 07            [24] 3419 	pop	ar7
      000F3E E5 82            [12] 3420 	mov	a, dpl
      000F40 24 FF            [12] 3421 	add	a,#0xff
      000F42 92 00            [24] 3422 	mov	b0,c
      000F44 D0 07            [24] 3423 	pop	ar7
      000F46 D0 06            [24] 3424 	pop	ar6
      000F48 30 00 03         [24] 3425 	jnb	b0,00180$
      000F4B 02 12 2F         [24] 3426 	ljmp	00117$
      000F4E                       3427 00180$:
                           000E97  3428 	C$fuzzy.h$1168$1_0$68 ==.
                                   3429 ;	../../fuzzy.h:1168: value <= universe[index + 1u]
      000F4E C0 06            [24] 3430 	push	ar6
      000F50 C0 07            [24] 3431 	push	ar7
      000F52 E5 08            [12] 3432 	mov	a,_bp
      000F54 24 0E            [12] 3433 	add	a,#0x0e
      000F56 F8               [12] 3434 	mov	r0,a
      000F57 74 01            [12] 3435 	mov	a,#0x01
      000F59 26               [12] 3436 	add	a, @r0
      000F5A FC               [12] 3437 	mov	r4,a
      000F5B E4               [12] 3438 	clr	a
      000F5C 08               [12] 3439 	inc	r0
      000F5D 36               [12] 3440 	addc	a, @r0
      000F5E FD               [12] 3441 	mov	r5,a
      000F5F EC               [12] 3442 	mov	a,r4
      000F60 2C               [12] 3443 	add	a,r4
      000F61 FC               [12] 3444 	mov	r4,a
      000F62 ED               [12] 3445 	mov	a,r5
      000F63 33               [12] 3446 	rlc	a
      000F64 FD               [12] 3447 	mov	r5,a
      000F65 EC               [12] 3448 	mov	a,r4
      000F66 2C               [12] 3449 	add	a,r4
      000F67 FC               [12] 3450 	mov	r4,a
      000F68 ED               [12] 3451 	mov	a,r5
      000F69 33               [12] 3452 	rlc	a
      000F6A FD               [12] 3453 	mov	r5,a
      000F6B A8 08            [24] 3454 	mov	r0,_bp
      000F6D 08               [12] 3455 	inc	r0
      000F6E EC               [12] 3456 	mov	a,r4
      000F6F 26               [12] 3457 	add	a, @r0
      000F70 FC               [12] 3458 	mov	r4,a
      000F71 ED               [12] 3459 	mov	a,r5
      000F72 08               [12] 3460 	inc	r0
      000F73 36               [12] 3461 	addc	a, @r0
      000F74 FD               [12] 3462 	mov	r5,a
      000F75 08               [12] 3463 	inc	r0
      000F76 86 07            [24] 3464 	mov	ar7,@r0
      000F78 8C 82            [24] 3465 	mov	dpl,r4
      000F7A 8D 83            [24] 3466 	mov	dph,r5
      000F7C 8F F0            [24] 3467 	mov	b,r7
      000F7E 12 2E 2A         [24] 3468 	lcall	__gptrget
      000F81 FC               [12] 3469 	mov	r4,a
      000F82 A3               [24] 3470 	inc	dptr
      000F83 12 2E 2A         [24] 3471 	lcall	__gptrget
      000F86 FD               [12] 3472 	mov	r5,a
      000F87 A3               [24] 3473 	inc	dptr
      000F88 12 2E 2A         [24] 3474 	lcall	__gptrget
      000F8B FF               [12] 3475 	mov	r7,a
      000F8C A3               [24] 3476 	inc	dptr
      000F8D 12 2E 2A         [24] 3477 	lcall	__gptrget
      000F90 FE               [12] 3478 	mov	r6,a
      000F91 C0 07            [24] 3479 	push	ar7
      000F93 C0 06            [24] 3480 	push	ar6
      000F95 E5 08            [12] 3481 	mov	a,_bp
      000F97 24 F5            [12] 3482 	add	a,#0xf5
      000F99 F8               [12] 3483 	mov	r0,a
      000F9A E6               [12] 3484 	mov	a,@r0
      000F9B C0 E0            [24] 3485 	push	acc
      000F9D 08               [12] 3486 	inc	r0
      000F9E E6               [12] 3487 	mov	a,@r0
      000F9F C0 E0            [24] 3488 	push	acc
      000FA1 08               [12] 3489 	inc	r0
      000FA2 E6               [12] 3490 	mov	a,@r0
      000FA3 C0 E0            [24] 3491 	push	acc
      000FA5 08               [12] 3492 	inc	r0
      000FA6 E6               [12] 3493 	mov	a,@r0
      000FA7 C0 E0            [24] 3494 	push	acc
      000FA9 8C 82            [24] 3495 	mov	dpl, r4
      000FAB 8D 83            [24] 3496 	mov	dph, r5
      000FAD 8F F0            [24] 3497 	mov	b, r7
      000FAF EE               [12] 3498 	mov	a, r6
      000FB0 12 2B FE         [24] 3499 	lcall	___fslt
      000FB3 E5 81            [12] 3500 	mov	a,sp
      000FB5 24 FC            [12] 3501 	add	a,#0xfc
      000FB7 F5 81            [12] 3502 	mov	sp,a
      000FB9 D0 06            [24] 3503 	pop	ar6
      000FBB D0 07            [24] 3504 	pop	ar7
      000FBD E5 82            [12] 3505 	mov	a, dpl
      000FBF 24 FF            [12] 3506 	add	a,#0xff
      000FC1 92 00            [24] 3507 	mov	b0,c
      000FC3 D0 07            [24] 3508 	pop	ar7
      000FC5 D0 06            [24] 3509 	pop	ar6
      000FC7 30 00 03         [24] 3510 	jnb	b0,00181$
      000FCA 02 12 2F         [24] 3511 	ljmp	00117$
      000FCD                       3512 00181$:
                           000F16  3513 	C$fuzzy.h$1170$1_0$68 ==.
                                   3514 ;	../../fuzzy.h:1170: if (universe[index] == universe[index + 1u]) {
      000FCD 74 01            [12] 3515 	mov	a,#0x01
      000FCF 2E               [12] 3516 	add	a, r6
      000FD0 FC               [12] 3517 	mov	r4,a
      000FD1 E4               [12] 3518 	clr	a
      000FD2 3F               [12] 3519 	addc	a, r7
      000FD3 FD               [12] 3520 	mov	r5,a
      000FD4 EC               [12] 3521 	mov	a,r4
      000FD5 2C               [12] 3522 	add	a,r4
      000FD6 FC               [12] 3523 	mov	r4,a
      000FD7 ED               [12] 3524 	mov	a,r5
      000FD8 33               [12] 3525 	rlc	a
      000FD9 FD               [12] 3526 	mov	r5,a
      000FDA EC               [12] 3527 	mov	a,r4
      000FDB 2C               [12] 3528 	add	a,r4
      000FDC FC               [12] 3529 	mov	r4,a
      000FDD ED               [12] 3530 	mov	a,r5
      000FDE 33               [12] 3531 	rlc	a
      000FDF FD               [12] 3532 	mov	r5,a
      000FE0 A8 08            [24] 3533 	mov	r0,_bp
      000FE2 08               [12] 3534 	inc	r0
      000FE3 EC               [12] 3535 	mov	a,r4
      000FE4 26               [12] 3536 	add	a, @r0
      000FE5 FC               [12] 3537 	mov	r4,a
      000FE6 ED               [12] 3538 	mov	a,r5
      000FE7 08               [12] 3539 	inc	r0
      000FE8 36               [12] 3540 	addc	a, @r0
      000FE9 FB               [12] 3541 	mov	r3,a
      000FEA 08               [12] 3542 	inc	r0
      000FEB 86 05            [24] 3543 	mov	ar5,@r0
      000FED 8C 82            [24] 3544 	mov	dpl,r4
      000FEF 8B 83            [24] 3545 	mov	dph,r3
      000FF1 8D F0            [24] 3546 	mov	b,r5
      000FF3 12 2E 2A         [24] 3547 	lcall	__gptrget
      000FF6 FC               [12] 3548 	mov	r4,a
      000FF7 A3               [24] 3549 	inc	dptr
      000FF8 12 2E 2A         [24] 3550 	lcall	__gptrget
      000FFB FB               [12] 3551 	mov	r3,a
      000FFC A3               [24] 3552 	inc	dptr
      000FFD 12 2E 2A         [24] 3553 	lcall	__gptrget
      001000 FD               [12] 3554 	mov	r5,a
      001001 A3               [24] 3555 	inc	dptr
      001002 12 2E 2A         [24] 3556 	lcall	__gptrget
      001005 FA               [12] 3557 	mov	r2,a
      001006 C0 07            [24] 3558 	push	ar7
      001008 C0 06            [24] 3559 	push	ar6
      00100A C0 04            [24] 3560 	push	ar4
      00100C C0 03            [24] 3561 	push	ar3
      00100E C0 05            [24] 3562 	push	ar5
      001010 C0 02            [24] 3563 	push	ar2
      001012 E5 08            [12] 3564 	mov	a,_bp
      001014 24 04            [12] 3565 	add	a,#0x04
      001016 F8               [12] 3566 	mov	r0,a
      001017 86 82            [24] 3567 	mov	dpl, @r0
      001019 08               [12] 3568 	inc	r0
      00101A 86 83            [24] 3569 	mov	dph, @r0
      00101C 08               [12] 3570 	inc	r0
      00101D 86 F0            [24] 3571 	mov	b, @r0
      00101F 08               [12] 3572 	inc	r0
      001020 E6               [12] 3573 	mov	a, @r0
      001021 12 2B D2         [24] 3574 	lcall	___fseq
      001024 AD 82            [24] 3575 	mov	r5, dpl
      001026 E5 81            [12] 3576 	mov	a,sp
      001028 24 FC            [12] 3577 	add	a,#0xfc
      00102A F5 81            [12] 3578 	mov	sp,a
      00102C D0 06            [24] 3579 	pop	ar6
      00102E D0 07            [24] 3580 	pop	ar7
      001030 ED               [12] 3581 	mov	a,r5
      001031 60 39            [24] 3582 	jz	00110$
                           000F7C  3583 	C$fuzzy.h$1171$5_0$75 ==.
                                   3584 ;	../../fuzzy.h:1171: return fuzzy_clamp(memberships[index]);
      001033 E5 08            [12] 3585 	mov	a,_bp
      001035 24 FB            [12] 3586 	add	a,#0xfb
      001037 F8               [12] 3587 	mov	r0,a
      001038 E5 08            [12] 3588 	mov	a,_bp
      00103A 24 08            [12] 3589 	add	a,#0x08
      00103C F9               [12] 3590 	mov	r1,a
      00103D E7               [12] 3591 	mov	a,@r1
      00103E 26               [12] 3592 	add	a, @r0
      00103F FB               [12] 3593 	mov	r3,a
      001040 09               [12] 3594 	inc	r1
      001041 E7               [12] 3595 	mov	a,@r1
      001042 08               [12] 3596 	inc	r0
      001043 36               [12] 3597 	addc	a, @r0
      001044 FC               [12] 3598 	mov	r4,a
      001045 08               [12] 3599 	inc	r0
      001046 86 05            [24] 3600 	mov	ar5,@r0
      001048 8B 82            [24] 3601 	mov	dpl,r3
      00104A 8C 83            [24] 3602 	mov	dph,r4
      00104C 8D F0            [24] 3603 	mov	b,r5
      00104E 12 2E 2A         [24] 3604 	lcall	__gptrget
      001051 FB               [12] 3605 	mov	r3,a
      001052 A3               [24] 3606 	inc	dptr
      001053 12 2E 2A         [24] 3607 	lcall	__gptrget
      001056 FC               [12] 3608 	mov	r4,a
      001057 A3               [24] 3609 	inc	dptr
      001058 12 2E 2A         [24] 3610 	lcall	__gptrget
      00105B FD               [12] 3611 	mov	r5,a
      00105C A3               [24] 3612 	inc	dptr
      00105D 12 2E 2A         [24] 3613 	lcall	__gptrget
      001060 8B 82            [24] 3614 	mov	dpl,r3
      001062 8C 83            [24] 3615 	mov	dph,r4
      001064 8D F0            [24] 3616 	mov	b,r5
      001066 12 00 EA         [24] 3617 	lcall	_fuzzy_clamp
      001069 02 12 4D         [24] 3618 	ljmp	00118$
      00106C                       3619 00110$:
                           000FB5  3620 	C$fuzzy.h$1175$1_0$68 ==.
                                   3621 ;	../../fuzzy.h:1175: (value - universe[index]) /
      00106C C0 07            [24] 3622 	push	ar7
      00106E C0 06            [24] 3623 	push	ar6
      001070 E5 08            [12] 3624 	mov	a,_bp
      001072 24 04            [12] 3625 	add	a,#0x04
      001074 F8               [12] 3626 	mov	r0,a
      001075 E6               [12] 3627 	mov	a,@r0
      001076 C0 E0            [24] 3628 	push	acc
      001078 08               [12] 3629 	inc	r0
      001079 E6               [12] 3630 	mov	a,@r0
      00107A C0 E0            [24] 3631 	push	acc
      00107C 08               [12] 3632 	inc	r0
      00107D E6               [12] 3633 	mov	a,@r0
      00107E C0 E0            [24] 3634 	push	acc
      001080 08               [12] 3635 	inc	r0
      001081 E6               [12] 3636 	mov	a,@r0
      001082 C0 E0            [24] 3637 	push	acc
                           000FCD  3638 	C$fuzzy.h$1176$1_0$68 ==.
                                   3639 ;	../../fuzzy.h:1176: (universe[index + 1u] - universe[index]);
      001084 E5 08            [12] 3640 	mov	a,_bp
      001086 24 F5            [12] 3641 	add	a,#0xf5
      001088 F8               [12] 3642 	mov	r0,a
      001089 86 82            [24] 3643 	mov	dpl, @r0
      00108B 08               [12] 3644 	inc	r0
      00108C 86 83            [24] 3645 	mov	dph, @r0
      00108E 08               [12] 3646 	inc	r0
      00108F 86 F0            [24] 3647 	mov	b, @r0
      001091 08               [12] 3648 	inc	r0
      001092 E6               [12] 3649 	mov	a, @r0
      001093 12 2A C3         [24] 3650 	lcall	___fssub
      001096 C8               [12] 3651 	xch	a,r0
      001097 E5 08            [12] 3652 	mov	a,_bp
      001099 24 0A            [12] 3653 	add	a,#0x0a
      00109B C8               [12] 3654 	xch	a,r0
      00109C A6 82            [24] 3655 	mov	@r0, dpl
      00109E 08               [12] 3656 	inc	r0
      00109F A6 83            [24] 3657 	mov	@r0, dph
      0010A1 08               [12] 3658 	inc	r0
      0010A2 A6 F0            [24] 3659 	mov	@r0, b
      0010A4 08               [12] 3660 	inc	r0
      0010A5 F6               [12] 3661 	mov	@r0,a
      0010A6 E5 81            [12] 3662 	mov	a,sp
      0010A8 24 FC            [12] 3663 	add	a,#0xfc
      0010AA F5 81            [12] 3664 	mov	sp,a
      0010AC D0 06            [24] 3665 	pop	ar6
      0010AE D0 07            [24] 3666 	pop	ar7
      0010B0 74 01            [12] 3667 	mov	a,#0x01
      0010B2 2E               [12] 3668 	add	a, r6
      0010B3 FC               [12] 3669 	mov	r4,a
      0010B4 E4               [12] 3670 	clr	a
      0010B5 3F               [12] 3671 	addc	a, r7
      0010B6 FD               [12] 3672 	mov	r5,a
      0010B7 EC               [12] 3673 	mov	a,r4
      0010B8 2C               [12] 3674 	add	a,r4
      0010B9 FF               [12] 3675 	mov	r7,a
      0010BA ED               [12] 3676 	mov	a,r5
      0010BB 33               [12] 3677 	rlc	a
      0010BC FE               [12] 3678 	mov	r6,a
      0010BD EF               [12] 3679 	mov	a,r7
      0010BE 2F               [12] 3680 	add	a,r7
      0010BF FF               [12] 3681 	mov	r7,a
      0010C0 EE               [12] 3682 	mov	a,r6
      0010C1 33               [12] 3683 	rlc	a
      0010C2 FE               [12] 3684 	mov	r6,a
      0010C3 A8 08            [24] 3685 	mov	r0,_bp
      0010C5 08               [12] 3686 	inc	r0
      0010C6 EF               [12] 3687 	mov	a,r7
      0010C7 26               [12] 3688 	add	a, @r0
      0010C8 FA               [12] 3689 	mov	r2,a
      0010C9 EE               [12] 3690 	mov	a,r6
      0010CA 08               [12] 3691 	inc	r0
      0010CB 36               [12] 3692 	addc	a, @r0
      0010CC FB               [12] 3693 	mov	r3,a
      0010CD 08               [12] 3694 	inc	r0
      0010CE 86 05            [24] 3695 	mov	ar5,@r0
      0010D0 8A 82            [24] 3696 	mov	dpl,r2
      0010D2 8B 83            [24] 3697 	mov	dph,r3
      0010D4 8D F0            [24] 3698 	mov	b,r5
      0010D6 12 2E 2A         [24] 3699 	lcall	__gptrget
      0010D9 FA               [12] 3700 	mov	r2,a
      0010DA A3               [24] 3701 	inc	dptr
      0010DB 12 2E 2A         [24] 3702 	lcall	__gptrget
      0010DE FB               [12] 3703 	mov	r3,a
      0010DF A3               [24] 3704 	inc	dptr
      0010E0 12 2E 2A         [24] 3705 	lcall	__gptrget
      0010E3 FD               [12] 3706 	mov	r5,a
      0010E4 A3               [24] 3707 	inc	dptr
      0010E5 12 2E 2A         [24] 3708 	lcall	__gptrget
      0010E8 FC               [12] 3709 	mov	r4,a
      0010E9 C0 07            [24] 3710 	push	ar7
      0010EB C0 06            [24] 3711 	push	ar6
      0010ED E5 08            [12] 3712 	mov	a,_bp
      0010EF 24 04            [12] 3713 	add	a,#0x04
      0010F1 F8               [12] 3714 	mov	r0,a
      0010F2 E6               [12] 3715 	mov	a,@r0
      0010F3 C0 E0            [24] 3716 	push	acc
      0010F5 08               [12] 3717 	inc	r0
      0010F6 E6               [12] 3718 	mov	a,@r0
      0010F7 C0 E0            [24] 3719 	push	acc
      0010F9 08               [12] 3720 	inc	r0
      0010FA E6               [12] 3721 	mov	a,@r0
      0010FB C0 E0            [24] 3722 	push	acc
      0010FD 08               [12] 3723 	inc	r0
      0010FE E6               [12] 3724 	mov	a,@r0
      0010FF C0 E0            [24] 3725 	push	acc
      001101 8A 82            [24] 3726 	mov	dpl, r2
      001103 8B 83            [24] 3727 	mov	dph, r3
      001105 8D F0            [24] 3728 	mov	b, r5
      001107 EC               [12] 3729 	mov	a, r4
      001108 12 2A C3         [24] 3730 	lcall	___fssub
      00110B AA 82            [24] 3731 	mov	r2, dpl
      00110D AB 83            [24] 3732 	mov	r3, dph
      00110F AC F0            [24] 3733 	mov	r4, b
      001111 FD               [12] 3734 	mov	r5, a
      001112 E5 81            [12] 3735 	mov	a,sp
      001114 24 FC            [12] 3736 	add	a,#0xfc
      001116 F5 81            [12] 3737 	mov	sp,a
      001118 C0 02            [24] 3738 	push	ar2
      00111A C0 03            [24] 3739 	push	ar3
      00111C C0 04            [24] 3740 	push	ar4
      00111E C0 05            [24] 3741 	push	ar5
                           001069  3742 	C$fuzzy.h$1179$1_0$68 ==.
                                   3743 ;	../../fuzzy.h:1179: memberships[index] +
      001120 E5 08            [12] 3744 	mov	a,_bp
      001122 24 0A            [12] 3745 	add	a,#0x0a
      001124 F8               [12] 3746 	mov	r0,a
      001125 86 82            [24] 3747 	mov	dpl, @r0
      001127 08               [12] 3748 	inc	r0
      001128 86 83            [24] 3749 	mov	dph, @r0
      00112A 08               [12] 3750 	inc	r0
      00112B 86 F0            [24] 3751 	mov	b, @r0
      00112D 08               [12] 3752 	inc	r0
      00112E E6               [12] 3753 	mov	a, @r0
      00112F 12 2D 67         [24] 3754 	lcall	___fsdiv
      001132 C8               [12] 3755 	xch	a,r0
      001133 E5 08            [12] 3756 	mov	a,_bp
      001135 24 10            [12] 3757 	add	a,#0x10
      001137 C8               [12] 3758 	xch	a,r0
      001138 A6 82            [24] 3759 	mov	@r0, dpl
      00113A 08               [12] 3760 	inc	r0
      00113B A6 83            [24] 3761 	mov	@r0, dph
      00113D 08               [12] 3762 	inc	r0
      00113E A6 F0            [24] 3763 	mov	@r0, b
      001140 08               [12] 3764 	inc	r0
      001141 F6               [12] 3765 	mov	@r0,a
      001142 E5 81            [12] 3766 	mov	a,sp
      001144 24 FC            [12] 3767 	add	a,#0xfc
      001146 F5 81            [12] 3768 	mov	sp,a
      001148 D0 06            [24] 3769 	pop	ar6
      00114A D0 07            [24] 3770 	pop	ar7
      00114C E5 08            [12] 3771 	mov	a,_bp
      00114E 24 FB            [12] 3772 	add	a,#0xfb
      001150 F8               [12] 3773 	mov	r0,a
      001151 E5 08            [12] 3774 	mov	a,_bp
      001153 24 08            [12] 3775 	add	a,#0x08
      001155 F9               [12] 3776 	mov	r1,a
      001156 E7               [12] 3777 	mov	a,@r1
      001157 26               [12] 3778 	add	a, @r0
      001158 FB               [12] 3779 	mov	r3,a
      001159 09               [12] 3780 	inc	r1
      00115A E7               [12] 3781 	mov	a,@r1
      00115B 08               [12] 3782 	inc	r0
      00115C 36               [12] 3783 	addc	a, @r0
      00115D FC               [12] 3784 	mov	r4,a
      00115E 08               [12] 3785 	inc	r0
      00115F 86 05            [24] 3786 	mov	ar5,@r0
      001161 8B 82            [24] 3787 	mov	dpl,r3
      001163 8C 83            [24] 3788 	mov	dph,r4
      001165 8D F0            [24] 3789 	mov	b,r5
      001167 E5 08            [12] 3790 	mov	a,_bp
      001169 24 0A            [12] 3791 	add	a,#0x0a
      00116B F8               [12] 3792 	mov	r0,a
      00116C 12 2E 2A         [24] 3793 	lcall	__gptrget
      00116F F6               [12] 3794 	mov	@r0,a
      001170 A3               [24] 3795 	inc	dptr
      001171 12 2E 2A         [24] 3796 	lcall	__gptrget
      001174 08               [12] 3797 	inc	r0
      001175 F6               [12] 3798 	mov	@r0,a
      001176 A3               [24] 3799 	inc	dptr
      001177 12 2E 2A         [24] 3800 	lcall	__gptrget
      00117A 08               [12] 3801 	inc	r0
      00117B F6               [12] 3802 	mov	@r0,a
      00117C A3               [24] 3803 	inc	dptr
      00117D 12 2E 2A         [24] 3804 	lcall	__gptrget
      001180 08               [12] 3805 	inc	r0
      001181 F6               [12] 3806 	mov	@r0,a
                           0010CB  3807 	C$fuzzy.h$1182$4_0$74 ==.
                                   3808 ;	../../fuzzy.h:1182: memberships[index + 1u] -
      001182 E5 08            [12] 3809 	mov	a,_bp
      001184 24 FB            [12] 3810 	add	a,#0xfb
      001186 F8               [12] 3811 	mov	r0,a
      001187 EF               [12] 3812 	mov	a,r7
      001188 26               [12] 3813 	add	a, @r0
      001189 FB               [12] 3814 	mov	r3,a
      00118A EE               [12] 3815 	mov	a,r6
      00118B 08               [12] 3816 	inc	r0
      00118C 36               [12] 3817 	addc	a, @r0
      00118D FC               [12] 3818 	mov	r4,a
      00118E 08               [12] 3819 	inc	r0
      00118F 86 05            [24] 3820 	mov	ar5,@r0
      001191 8B 82            [24] 3821 	mov	dpl,r3
      001193 8C 83            [24] 3822 	mov	dph,r4
      001195 8D F0            [24] 3823 	mov	b,r5
      001197 12 2E 2A         [24] 3824 	lcall	__gptrget
      00119A FB               [12] 3825 	mov	r3,a
      00119B A3               [24] 3826 	inc	dptr
      00119C 12 2E 2A         [24] 3827 	lcall	__gptrget
      00119F FC               [12] 3828 	mov	r4,a
      0011A0 A3               [24] 3829 	inc	dptr
      0011A1 12 2E 2A         [24] 3830 	lcall	__gptrget
      0011A4 FD               [12] 3831 	mov	r5,a
      0011A5 A3               [24] 3832 	inc	dptr
      0011A6 12 2E 2A         [24] 3833 	lcall	__gptrget
      0011A9 FA               [12] 3834 	mov	r2,a
                           0010F3  3835 	C$fuzzy.h$1183$1_0$68 ==.
                                   3836 ;	../../fuzzy.h:1183: memberships[index]
      0011AA E5 08            [12] 3837 	mov	a,_bp
      0011AC 24 0A            [12] 3838 	add	a,#0x0a
      0011AE F8               [12] 3839 	mov	r0,a
      0011AF E6               [12] 3840 	mov	a,@r0
      0011B0 C0 E0            [24] 3841 	push	acc
      0011B2 08               [12] 3842 	inc	r0
      0011B3 E6               [12] 3843 	mov	a,@r0
      0011B4 C0 E0            [24] 3844 	push	acc
      0011B6 08               [12] 3845 	inc	r0
      0011B7 E6               [12] 3846 	mov	a,@r0
      0011B8 C0 E0            [24] 3847 	push	acc
      0011BA 08               [12] 3848 	inc	r0
      0011BB E6               [12] 3849 	mov	a,@r0
      0011BC C0 E0            [24] 3850 	push	acc
      0011BE 8B 82            [24] 3851 	mov	dpl, r3
      0011C0 8C 83            [24] 3852 	mov	dph, r4
      0011C2 8D F0            [24] 3853 	mov	b, r5
      0011C4 EA               [12] 3854 	mov	a, r2
      0011C5 12 2A C3         [24] 3855 	lcall	___fssub
      0011C8 AA 82            [24] 3856 	mov	r2, dpl
      0011CA AB 83            [24] 3857 	mov	r3, dph
      0011CC AC F0            [24] 3858 	mov	r4, b
      0011CE FD               [12] 3859 	mov	r5, a
      0011CF E5 81            [12] 3860 	mov	a,sp
      0011D1 24 FC            [12] 3861 	add	a,#0xfc
      0011D3 F5 81            [12] 3862 	mov	sp,a
      0011D5 C0 02            [24] 3863 	push	ar2
      0011D7 C0 03            [24] 3864 	push	ar3
      0011D9 C0 04            [24] 3865 	push	ar4
      0011DB C0 05            [24] 3866 	push	ar5
      0011DD E5 08            [12] 3867 	mov	a,_bp
      0011DF 24 10            [12] 3868 	add	a,#0x10
      0011E1 F8               [12] 3869 	mov	r0,a
      0011E2 86 82            [24] 3870 	mov	dpl, @r0
      0011E4 08               [12] 3871 	inc	r0
      0011E5 86 83            [24] 3872 	mov	dph, @r0
      0011E7 08               [12] 3873 	inc	r0
      0011E8 86 F0            [24] 3874 	mov	b, @r0
      0011EA 08               [12] 3875 	inc	r0
      0011EB E6               [12] 3876 	mov	a, @r0
      0011EC 12 2A CE         [24] 3877 	lcall	___fsmul
      0011EF AA 82            [24] 3878 	mov	r2, dpl
      0011F1 AB 83            [24] 3879 	mov	r3, dph
      0011F3 AC F0            [24] 3880 	mov	r4, b
      0011F5 FD               [12] 3881 	mov	r5, a
      0011F6 E5 81            [12] 3882 	mov	a,sp
      0011F8 24 FC            [12] 3883 	add	a,#0xfc
      0011FA F5 81            [12] 3884 	mov	sp,a
      0011FC C0 02            [24] 3885 	push	ar2
      0011FE C0 03            [24] 3886 	push	ar3
      001200 C0 04            [24] 3887 	push	ar4
      001202 C0 05            [24] 3888 	push	ar5
      001204 E5 08            [12] 3889 	mov	a,_bp
      001206 24 0A            [12] 3890 	add	a,#0x0a
      001208 F8               [12] 3891 	mov	r0,a
      001209 86 82            [24] 3892 	mov	dpl, @r0
      00120B 08               [12] 3893 	inc	r0
      00120C 86 83            [24] 3894 	mov	dph, @r0
      00120E 08               [12] 3895 	inc	r0
      00120F 86 F0            [24] 3896 	mov	b, @r0
      001211 08               [12] 3897 	inc	r0
      001212 E6               [12] 3898 	mov	a, @r0
      001213 12 2C 50         [24] 3899 	lcall	___fsadd
      001216 AA 82            [24] 3900 	mov	r2, dpl
      001218 AB 83            [24] 3901 	mov	r3, dph
      00121A AC F0            [24] 3902 	mov	r4, b
      00121C FD               [12] 3903 	mov	r5, a
      00121D E5 81            [12] 3904 	mov	a,sp
      00121F 24 FC            [12] 3905 	add	a,#0xfc
      001221 F5 81            [12] 3906 	mov	sp,a
      001223 8A 82            [24] 3907 	mov	dpl, r2
      001225 8B 83            [24] 3908 	mov	dph, r3
      001227 8C F0            [24] 3909 	mov	b, r4
      001229 ED               [12] 3910 	mov	a, r5
      00122A 12 00 EA         [24] 3911 	lcall	_fuzzy_clamp
      00122D 80 1E            [24] 3912 	sjmp	00118$
      00122F                       3913 00117$:
                           001178  3914 	C$fuzzy.h$1165$2_0$72 ==.
                                   3915 ;	../../fuzzy.h:1165: for (index = 0u; index + 1u < count; index++) {
      00122F E5 08            [12] 3916 	mov	a,_bp
      001231 24 0E            [12] 3917 	add	a,#0x0e
      001233 F8               [12] 3918 	mov	r0,a
      001234 06               [12] 3919 	inc	@r0
      001235 B6 00 02         [24] 3920 	cjne	@r0,#0x00,00183$
      001238 08               [12] 3921 	inc	r0
      001239 06               [12] 3922 	inc	@r0
      00123A                       3923 00183$:
      00123A E5 08            [12] 3924 	mov	a,_bp
      00123C 24 0E            [12] 3925 	add	a,#0x0e
      00123E F8               [12] 3926 	mov	r0,a
      00123F 86 06            [24] 3927 	mov	ar6,@r0
      001241 08               [12] 3928 	inc	r0
      001242 86 07            [24] 3929 	mov	ar7,@r0
      001244 02 0E 9B         [24] 3930 	ljmp	00116$
      001247                       3931 00114$:
                           001190  3932 	C$fuzzy.h$1189$1_0$68 ==.
                                   3933 ;	../../fuzzy.h:1189: return LEVEL_LO;
      001247 90 00 00         [24] 3934 	mov	dptr,#0x0000
      00124A E4               [12] 3935 	clr	a
      00124B F5 F0            [12] 3936 	mov	b,a
      00124D                       3937 00118$:
                           001196  3938 	C$fuzzy.h$1190$1_0$68 ==.
                                   3939 ;	../../fuzzy.h:1190: }
      00124D 85 08 81         [24] 3940 	mov	sp,_bp
      001250 D0 08            [24] 3941 	pop	_bp
                           00119B  3942 	C$fuzzy.h$1190$1_0$68 ==.
                           00119B  3943 	XG$fuzzy_interpolate_membership$0$0 ==.
      001252 22               [24] 3944 	ret
                                   3945 ;------------------------------------------------------------
                                   3946 ;Allocation info for local variables in function 'fuzzy_function_array'
                                   3947 ;------------------------------------------------------------
                                   3948 ;value         Allocated to stack - _bp -6 +4 
                                   3949 ;hedge         Allocated to stack - _bp -7 +1 
                                   3950 ;parameter_count Allocated to stack - _bp -9 +2 
                                   3951 ;parameters    Allocated to stack - _bp -12 +3 
                                   3952 ;shape         Allocated to registers r7 
                                   3953 ;result        Allocated to stack - _bp +5 +4 
                                   3954 ;parameter_1   Allocated to stack - _bp +17 +4 
                                   3955 ;parameter_2   Allocated to stack - _bp +21 +4 
                                   3956 ;parameter_3   Allocated to stack - _bp +25 +4 
                                   3957 ;parameter_4   Allocated to registers r5 r6 r7 r4 
                                   3958 ;ramp_up       Allocated to registers r7 
                                   3959 ;sloc0         Allocated to stack - _bp +23 +3 
                                   3960 ;sloc1         Allocated to stack - _bp +1 +4 
                                   3961 ;sloc2         Allocated to stack - _bp +5 +4 
                                   3962 ;sloc3         Allocated to stack - _bp +9 +4 
                                   3963 ;sloc4         Allocated to stack - _bp +13 +4 
                                   3964 ;------------------------------------------------------------
                           00119C  3965 	G$fuzzy_function_array$0$0 ==.
                           00119C  3966 	C$fuzzy.h$1234$1_0$77 ==.
                                   3967 ;	../../fuzzy.h:1234: float fuzzy_function_array(
                                   3968 ;	-----------------------------------------
                                   3969 ;	 function fuzzy_function_array
                                   3970 ;	-----------------------------------------
      001253                       3971 _fuzzy_function_array:
      001253 C0 08            [24] 3972 	push	_bp
      001255 E5 81            [12] 3973 	mov	a,sp
      001257 F5 08            [12] 3974 	mov	_bp,a
      001259 24 1C            [12] 3975 	add	a,#0x1c
      00125B F5 81            [12] 3976 	mov	sp,a
      00125D AF 82            [24] 3977 	mov	r7, dpl
                           0011A8  3978 	C$fuzzy.h$1258$1_0$77 ==.
                                   3979 ;	../../fuzzy.h:1258: if (parameters == NULL) {
      00125F E5 08            [12] 3980 	mov	a,_bp
      001261 24 F4            [12] 3981 	add	a,#0xf4
      001263 F8               [12] 3982 	mov	r0,a
      001264 E6               [12] 3983 	mov	a,@r0
      001265 08               [12] 3984 	inc	r0
      001266 46               [12] 3985 	orl	a,@r0
      001267 70 09            [24] 3986 	jnz	00102$
                           0011B2  3987 	C$fuzzy.h$1259$2_0$78 ==.
                                   3988 ;	../../fuzzy.h:1259: return LEVEL_LO;
      001269 90 00 00         [24] 3989 	mov	dptr,#0x0000
      00126C E4               [12] 3990 	clr	a
      00126D F5 F0            [12] 3991 	mov	b,a
      00126F 02 1B 8F         [24] 3992 	ljmp	00149$
      001272                       3993 00102$:
                           0011BB  3994 	C$fuzzy.h$1262$1_0$77 ==.
                                   3995 ;	../../fuzzy.h:1262: switch (shape) {
      001272 EF               [12] 3996 	mov	a,r7
      001273 24 F4            [12] 3997 	add	a,#0xff - 0x0b
      001275 50 03            [24] 3998 	jnc	00271$
      001277 02 1B 5D         [24] 3999 	ljmp	00147$
      00127A                       4000 00271$:
      00127A EF               [12] 4001 	mov	a,r7
      00127B 24 0A            [12] 4002 	add	a,#(00272$-3-.)
      00127D 83               [24] 4003 	movc	a,@a+pc
      00127E F5 82            [12] 4004 	mov	dpl,a
      001280 EF               [12] 4005 	mov	a,r7
      001281 24 10            [12] 4006 	add	a,#(00273$-3-.)
      001283 83               [24] 4007 	movc	a,@a+pc
      001284 F5 83            [12] 4008 	mov	dph,a
      001286 E4               [12] 4009 	clr	a
      001287 73               [24] 4010 	jmp	@a+dptr
      001288                       4011 00272$:
      001288 A0                    4012 	.db	00103$
      001289 9E                    4013 	.db	00106$
      00128A 24                    4014 	.db	00121$
      00128B 55                    4015 	.db	00146$
      00128C 55                    4016 	.db	00146$
      00128D 55                    4017 	.db	00146$
      00128E 55                    4018 	.db	00146$
      00128F 55                    4019 	.db	00146$
      001290 55                    4020 	.db	00146$
      001291 55                    4021 	.db	00146$
      001292 55                    4022 	.db	00146$
      001293 55                    4023 	.db	00146$
      001294                       4024 00273$:
      001294 12                    4025 	.db	00103$>>8
      001295 13                    4026 	.db	00106$>>8
      001296 17                    4027 	.db	00121$>>8
      001297 1B                    4028 	.db	00146$>>8
      001298 1B                    4029 	.db	00146$>>8
      001299 1B                    4030 	.db	00146$>>8
      00129A 1B                    4031 	.db	00146$>>8
      00129B 1B                    4032 	.db	00146$>>8
      00129C 1B                    4033 	.db	00146$>>8
      00129D 1B                    4034 	.db	00146$>>8
      00129E 1B                    4035 	.db	00146$>>8
      00129F 1B                    4036 	.db	00146$>>8
                           0011E9  4037 	C$fuzzy.h$1263$2_0$79 ==.
                                   4038 ;	../../fuzzy.h:1263: case FUZZY_SHAPE_RAMP:
      0012A0                       4039 00103$:
                           0011E9  4040 	C$fuzzy.h$1264$2_0$79 ==.
                                   4041 ;	../../fuzzy.h:1264: if (parameter_count != 3u) {
      0012A0 E5 08            [12] 4042 	mov	a,_bp
      0012A2 24 F7            [12] 4043 	add	a,#0xf7
      0012A4 F8               [12] 4044 	mov	r0,a
      0012A5 B6 03 06         [24] 4045 	cjne	@r0,#0x03,00274$
      0012A8 08               [12] 4046 	inc	r0
      0012A9 B6 00 02         [24] 4047 	cjne	@r0,#0x00,00274$
      0012AC 80 09            [24] 4048 	sjmp	00105$
      0012AE                       4049 00274$:
                           0011F7  4050 	C$fuzzy.h$1265$3_0$80 ==.
                                   4051 ;	../../fuzzy.h:1265: return LEVEL_LO;
      0012AE 90 00 00         [24] 4052 	mov	dptr,#0x0000
      0012B1 E4               [12] 4053 	clr	a
      0012B2 F5 F0            [12] 4054 	mov	b,a
      0012B4 02 1B 8F         [24] 4055 	ljmp	00149$
      0012B7                       4056 00105$:
                           001200  4057 	C$fuzzy.h$1268$2_0$79 ==.
                                   4058 ;	../../fuzzy.h:1268: parameter_1 = parameters[0];
      0012B7 E5 08            [12] 4059 	mov	a,_bp
      0012B9 24 F4            [12] 4060 	add	a,#0xf4
      0012BB F8               [12] 4061 	mov	r0,a
      0012BC 86 02            [24] 4062 	mov	ar2,@r0
      0012BE 08               [12] 4063 	inc	r0
      0012BF 86 03            [24] 4064 	mov	ar3,@r0
      0012C1 08               [12] 4065 	inc	r0
      0012C2 86 04            [24] 4066 	mov	ar4,@r0
      0012C4 8A 82            [24] 4067 	mov	dpl,r2
      0012C6 8B 83            [24] 4068 	mov	dph,r3
      0012C8 8C F0            [24] 4069 	mov	b,r4
      0012CA A8 08            [24] 4070 	mov	r0,_bp
      0012CC 08               [12] 4071 	inc	r0
      0012CD 12 2E 2A         [24] 4072 	lcall	__gptrget
      0012D0 F6               [12] 4073 	mov	@r0,a
      0012D1 A3               [24] 4074 	inc	dptr
      0012D2 12 2E 2A         [24] 4075 	lcall	__gptrget
      0012D5 08               [12] 4076 	inc	r0
      0012D6 F6               [12] 4077 	mov	@r0,a
      0012D7 A3               [24] 4078 	inc	dptr
      0012D8 12 2E 2A         [24] 4079 	lcall	__gptrget
      0012DB 08               [12] 4080 	inc	r0
      0012DC F6               [12] 4081 	mov	@r0,a
      0012DD A3               [24] 4082 	inc	dptr
      0012DE 12 2E 2A         [24] 4083 	lcall	__gptrget
      0012E1 08               [12] 4084 	inc	r0
      0012E2 F6               [12] 4085 	mov	@r0,a
                           00122C  4086 	C$fuzzy.h$1269$2_0$79 ==.
                                   4087 ;	../../fuzzy.h:1269: parameter_2 = parameters[1];
      0012E3 74 04            [12] 4088 	mov	a,#0x04
      0012E5 2A               [12] 4089 	add	a, r2
      0012E6 FD               [12] 4090 	mov	r5,a
      0012E7 E4               [12] 4091 	clr	a
      0012E8 3B               [12] 4092 	addc	a, r3
      0012E9 FE               [12] 4093 	mov	r6,a
      0012EA 8C 07            [24] 4094 	mov	ar7,r4
      0012EC 8D 82            [24] 4095 	mov	dpl,r5
      0012EE 8E 83            [24] 4096 	mov	dph,r6
      0012F0 8F F0            [24] 4097 	mov	b,r7
      0012F2 E5 08            [12] 4098 	mov	a,_bp
      0012F4 24 05            [12] 4099 	add	a,#0x05
      0012F6 F8               [12] 4100 	mov	r0,a
      0012F7 12 2E 2A         [24] 4101 	lcall	__gptrget
      0012FA F6               [12] 4102 	mov	@r0,a
      0012FB A3               [24] 4103 	inc	dptr
      0012FC 12 2E 2A         [24] 4104 	lcall	__gptrget
      0012FF 08               [12] 4105 	inc	r0
      001300 F6               [12] 4106 	mov	@r0,a
      001301 A3               [24] 4107 	inc	dptr
      001302 12 2E 2A         [24] 4108 	lcall	__gptrget
      001305 08               [12] 4109 	inc	r0
      001306 F6               [12] 4110 	mov	@r0,a
      001307 A3               [24] 4111 	inc	dptr
      001308 12 2E 2A         [24] 4112 	lcall	__gptrget
      00130B 08               [12] 4113 	inc	r0
      00130C F6               [12] 4114 	mov	@r0,a
                           001256  4115 	C$fuzzy.h$1270$2_0$79 ==.
                                   4116 ;	../../fuzzy.h:1270: ramp_up = parameters[2] != 0.0f;
      00130D 74 08            [12] 4117 	mov	a,#0x08
      00130F 2A               [12] 4118 	add	a, r2
      001310 FA               [12] 4119 	mov	r2,a
      001311 E4               [12] 4120 	clr	a
      001312 3B               [12] 4121 	addc	a, r3
      001313 FB               [12] 4122 	mov	r3,a
      001314 8C 07            [24] 4123 	mov	ar7,r4
      001316 8A 82            [24] 4124 	mov	dpl,r2
      001318 8B 83            [24] 4125 	mov	dph,r3
      00131A 8F F0            [24] 4126 	mov	b,r7
      00131C 12 2E 2A         [24] 4127 	lcall	__gptrget
      00131F FA               [12] 4128 	mov	r2,a
      001320 A3               [24] 4129 	inc	dptr
      001321 12 2E 2A         [24] 4130 	lcall	__gptrget
      001324 FB               [12] 4131 	mov	r3,a
      001325 A3               [24] 4132 	inc	dptr
      001326 12 2E 2A         [24] 4133 	lcall	__gptrget
      001329 FF               [12] 4134 	mov	r7,a
      00132A A3               [24] 4135 	inc	dptr
      00132B 12 2E 2A         [24] 4136 	lcall	__gptrget
      00132E FE               [12] 4137 	mov	r6,a
      00132F 8A F0            [24] 4138 	mov	b,r2
      001331 EB               [12] 4139 	mov	a,r3
      001332 42 F0            [12] 4140 	orl	b,a
      001334 EF               [12] 4141 	mov	a,r7
      001335 42 F0            [12] 4142 	orl	b,a
      001337 EE               [12] 4143 	mov	a,r6
      001338 54 7F            [12] 4144 	anl	a,#0x7F
      00133A 45 F0            [12] 4145 	orl	a,b
      00133C B4 01 00         [24] 4146 	cjne	a,#0x01,00275$
      00133F                       4147 00275$:
      00133F B3               [12] 4148 	cpl	c
      001340 92 00            [24] 4149 	mov	b0,c
      001342 E4               [12] 4150 	clr	a
      001343 33               [12] 4151 	rlc	a
      001344 FF               [12] 4152 	mov	r7,a
                           00128E  4153 	C$fuzzy.h$1273$2_0$79 ==.
                                   4154 ;	../../fuzzy.h:1273: parameter_1,
      001345 E5 08            [12] 4155 	mov	a,_bp
      001347 24 F9            [12] 4156 	add	a,#0xf9
      001349 F8               [12] 4157 	mov	r0,a
      00134A E6               [12] 4158 	mov	a,@r0
      00134B C0 E0            [24] 4159 	push	acc
      00134D C0 07            [24] 4160 	push	ar7
      00134F E5 08            [12] 4161 	mov	a,_bp
      001351 24 FA            [12] 4162 	add	a,#0xfa
      001353 F8               [12] 4163 	mov	r0,a
      001354 E6               [12] 4164 	mov	a,@r0
      001355 C0 E0            [24] 4165 	push	acc
      001357 08               [12] 4166 	inc	r0
      001358 E6               [12] 4167 	mov	a,@r0
      001359 C0 E0            [24] 4168 	push	acc
      00135B 08               [12] 4169 	inc	r0
      00135C E6               [12] 4170 	mov	a,@r0
      00135D C0 E0            [24] 4171 	push	acc
      00135F 08               [12] 4172 	inc	r0
      001360 E6               [12] 4173 	mov	a,@r0
      001361 C0 E0            [24] 4174 	push	acc
      001363 E5 08            [12] 4175 	mov	a,_bp
      001365 24 05            [12] 4176 	add	a,#0x05
      001367 F8               [12] 4177 	mov	r0,a
      001368 E6               [12] 4178 	mov	a,@r0
      001369 C0 E0            [24] 4179 	push	acc
      00136B 08               [12] 4180 	inc	r0
      00136C E6               [12] 4181 	mov	a,@r0
      00136D C0 E0            [24] 4182 	push	acc
      00136F 08               [12] 4183 	inc	r0
      001370 E6               [12] 4184 	mov	a,@r0
      001371 C0 E0            [24] 4185 	push	acc
      001373 08               [12] 4186 	inc	r0
      001374 E6               [12] 4187 	mov	a,@r0
      001375 C0 E0            [24] 4188 	push	acc
      001377 A8 08            [24] 4189 	mov	r0,_bp
      001379 08               [12] 4190 	inc	r0
      00137A 86 82            [24] 4191 	mov	dpl, @r0
      00137C 08               [12] 4192 	inc	r0
      00137D 86 83            [24] 4193 	mov	dph, @r0
      00137F 08               [12] 4194 	inc	r0
      001380 86 F0            [24] 4195 	mov	b, @r0
      001382 08               [12] 4196 	inc	r0
      001383 E6               [12] 4197 	mov	a, @r0
      001384 12 0A EC         [24] 4198 	lcall	_fuzzy_ramp
      001387 AC 82            [24] 4199 	mov	r4, dpl
      001389 AD 83            [24] 4200 	mov	r5, dph
      00138B AE F0            [24] 4201 	mov	r6, b
      00138D FF               [12] 4202 	mov	r7, a
      00138E E5 81            [12] 4203 	mov	a,sp
      001390 24 F6            [12] 4204 	add	a,#0xf6
      001392 F5 81            [12] 4205 	mov	sp,a
      001394 8C 82            [24] 4206 	mov	dpl, r4
      001396 8D 83            [24] 4207 	mov	dph, r5
      001398 8E F0            [24] 4208 	mov	b, r6
      00139A EF               [12] 4209 	mov	a, r7
      00139B 02 1B 8F         [24] 4210 	ljmp	00149$
                           0012E7  4211 	C$fuzzy.h$1280$2_0$79 ==.
                                   4212 ;	../../fuzzy.h:1280: case FUZZY_SHAPE_TRIANGLE:
      00139E                       4213 00106$:
                           0012E7  4214 	C$fuzzy.h$1281$2_0$79 ==.
                                   4215 ;	../../fuzzy.h:1281: if (parameter_count != 3u) {
      00139E E5 08            [12] 4216 	mov	a,_bp
      0013A0 24 F7            [12] 4217 	add	a,#0xf7
      0013A2 F8               [12] 4218 	mov	r0,a
      0013A3 B6 03 06         [24] 4219 	cjne	@r0,#0x03,00276$
      0013A6 08               [12] 4220 	inc	r0
      0013A7 B6 00 02         [24] 4221 	cjne	@r0,#0x00,00276$
      0013AA 80 09            [24] 4222 	sjmp	00108$
      0013AC                       4223 00276$:
                           0012F5  4224 	C$fuzzy.h$1282$3_0$81 ==.
                                   4225 ;	../../fuzzy.h:1282: return LEVEL_LO;
      0013AC 90 00 00         [24] 4226 	mov	dptr,#0x0000
      0013AF E4               [12] 4227 	clr	a
      0013B0 F5 F0            [12] 4228 	mov	b,a
      0013B2 02 1B 8F         [24] 4229 	ljmp	00149$
      0013B5                       4230 00108$:
                           0012FE  4231 	C$fuzzy.h$1285$2_0$79 ==.
                                   4232 ;	../../fuzzy.h:1285: parameter_1 = parameters[0];
      0013B5 E5 08            [12] 4233 	mov	a,_bp
      0013B7 24 F4            [12] 4234 	add	a,#0xf4
      0013B9 F8               [12] 4235 	mov	r0,a
      0013BA 86 02            [24] 4236 	mov	ar2,@r0
      0013BC 08               [12] 4237 	inc	r0
      0013BD 86 03            [24] 4238 	mov	ar3,@r0
      0013BF 08               [12] 4239 	inc	r0
      0013C0 86 04            [24] 4240 	mov	ar4,@r0
      0013C2 8A 82            [24] 4241 	mov	dpl,r2
      0013C4 8B 83            [24] 4242 	mov	dph,r3
      0013C6 8C F0            [24] 4243 	mov	b,r4
      0013C8 E5 08            [12] 4244 	mov	a,_bp
      0013CA 24 11            [12] 4245 	add	a,#0x11
      0013CC F8               [12] 4246 	mov	r0,a
      0013CD 12 2E 2A         [24] 4247 	lcall	__gptrget
      0013D0 F6               [12] 4248 	mov	@r0,a
      0013D1 A3               [24] 4249 	inc	dptr
      0013D2 12 2E 2A         [24] 4250 	lcall	__gptrget
      0013D5 08               [12] 4251 	inc	r0
      0013D6 F6               [12] 4252 	mov	@r0,a
      0013D7 A3               [24] 4253 	inc	dptr
      0013D8 12 2E 2A         [24] 4254 	lcall	__gptrget
      0013DB 08               [12] 4255 	inc	r0
      0013DC F6               [12] 4256 	mov	@r0,a
      0013DD A3               [24] 4257 	inc	dptr
      0013DE 12 2E 2A         [24] 4258 	lcall	__gptrget
      0013E1 08               [12] 4259 	inc	r0
      0013E2 F6               [12] 4260 	mov	@r0,a
                           00132C  4261 	C$fuzzy.h$1286$2_0$79 ==.
                                   4262 ;	../../fuzzy.h:1286: parameter_2 = parameters[1];
      0013E3 74 04            [12] 4263 	mov	a,#0x04
      0013E5 2A               [12] 4264 	add	a, r2
      0013E6 FF               [12] 4265 	mov	r7,a
      0013E7 E4               [12] 4266 	clr	a
      0013E8 3B               [12] 4267 	addc	a, r3
      0013E9 FD               [12] 4268 	mov	r5,a
      0013EA 8C 06            [24] 4269 	mov	ar6,r4
      0013EC 8F 82            [24] 4270 	mov	dpl,r7
      0013EE 8D 83            [24] 4271 	mov	dph,r5
      0013F0 8E F0            [24] 4272 	mov	b,r6
      0013F2 E5 08            [12] 4273 	mov	a,_bp
      0013F4 24 15            [12] 4274 	add	a,#0x15
      0013F6 F8               [12] 4275 	mov	r0,a
      0013F7 12 2E 2A         [24] 4276 	lcall	__gptrget
      0013FA F6               [12] 4277 	mov	@r0,a
      0013FB A3               [24] 4278 	inc	dptr
      0013FC 12 2E 2A         [24] 4279 	lcall	__gptrget
      0013FF 08               [12] 4280 	inc	r0
      001400 F6               [12] 4281 	mov	@r0,a
      001401 A3               [24] 4282 	inc	dptr
      001402 12 2E 2A         [24] 4283 	lcall	__gptrget
      001405 08               [12] 4284 	inc	r0
      001406 F6               [12] 4285 	mov	@r0,a
      001407 A3               [24] 4286 	inc	dptr
      001408 12 2E 2A         [24] 4287 	lcall	__gptrget
      00140B 08               [12] 4288 	inc	r0
      00140C F6               [12] 4289 	mov	@r0,a
                           001356  4290 	C$fuzzy.h$1287$2_0$79 ==.
                                   4291 ;	../../fuzzy.h:1287: parameter_3 = parameters[2];
      00140D 74 08            [12] 4292 	mov	a,#0x08
      00140F 2A               [12] 4293 	add	a, r2
      001410 FA               [12] 4294 	mov	r2,a
      001411 E4               [12] 4295 	clr	a
      001412 3B               [12] 4296 	addc	a, r3
      001413 FB               [12] 4297 	mov	r3,a
      001414 8C 07            [24] 4298 	mov	ar7,r4
      001416 8A 82            [24] 4299 	mov	dpl,r2
      001418 8B 83            [24] 4300 	mov	dph,r3
      00141A 8F F0            [24] 4301 	mov	b,r7
      00141C 12 2E 2A         [24] 4302 	lcall	__gptrget
      00141F FD               [12] 4303 	mov	r5,a
      001420 A3               [24] 4304 	inc	dptr
      001421 12 2E 2A         [24] 4305 	lcall	__gptrget
      001424 FE               [12] 4306 	mov	r6,a
      001425 A3               [24] 4307 	inc	dptr
      001426 12 2E 2A         [24] 4308 	lcall	__gptrget
      001429 FF               [12] 4309 	mov	r7,a
      00142A A3               [24] 4310 	inc	dptr
      00142B 12 2E 2A         [24] 4311 	lcall	__gptrget
      00142E FC               [12] 4312 	mov	r4,a
                           001378  4313 	C$fuzzy.h$1290$1_0$77 ==.
                                   4314 ;	../../fuzzy.h:1290: parameter_1 >= parameter_2 ||
      00142F C0 07            [24] 4315 	push	ar7
      001431 C0 06            [24] 4316 	push	ar6
      001433 C0 05            [24] 4317 	push	ar5
      001435 C0 04            [24] 4318 	push	ar4
      001437 E5 08            [12] 4319 	mov	a,_bp
      001439 24 15            [12] 4320 	add	a,#0x15
      00143B F8               [12] 4321 	mov	r0,a
      00143C E6               [12] 4322 	mov	a,@r0
      00143D C0 E0            [24] 4323 	push	acc
      00143F 08               [12] 4324 	inc	r0
      001440 E6               [12] 4325 	mov	a,@r0
      001441 C0 E0            [24] 4326 	push	acc
      001443 08               [12] 4327 	inc	r0
      001444 E6               [12] 4328 	mov	a,@r0
      001445 C0 E0            [24] 4329 	push	acc
      001447 08               [12] 4330 	inc	r0
      001448 E6               [12] 4331 	mov	a,@r0
      001449 C0 E0            [24] 4332 	push	acc
      00144B E5 08            [12] 4333 	mov	a,_bp
      00144D 24 11            [12] 4334 	add	a,#0x11
      00144F F8               [12] 4335 	mov	r0,a
      001450 86 82            [24] 4336 	mov	dpl, @r0
      001452 08               [12] 4337 	inc	r0
      001453 86 83            [24] 4338 	mov	dph, @r0
      001455 08               [12] 4339 	inc	r0
      001456 86 F0            [24] 4340 	mov	b, @r0
      001458 08               [12] 4341 	inc	r0
      001459 E6               [12] 4342 	mov	a, @r0
      00145A 12 2B FE         [24] 4343 	lcall	___fslt
      00145D E5 81            [12] 4344 	mov	a,sp
      00145F 24 FC            [12] 4345 	add	a,#0xfc
      001461 F5 81            [12] 4346 	mov	sp,a
      001463 D0 04            [24] 4347 	pop	ar4
      001465 D0 05            [24] 4348 	pop	ar5
      001467 D0 06            [24] 4349 	pop	ar6
      001469 D0 07            [24] 4350 	pop	ar7
      00146B E5 82            [12] 4351 	mov	a, dpl
      00146D 24 FF            [12] 4352 	add	a,#0xff
      00146F 92 00            [24] 4353 	mov	b0,c
      001471 40 03            [24] 4354 	jc	00277$
      001473 02 15 2A         [24] 4355 	ljmp	00115$
      001476                       4356 00277$:
                           0013BF  4357 	C$fuzzy.h$1291$1_0$77 ==.
                                   4358 ;	../../fuzzy.h:1291: parameter_2 >= parameter_3 ||
      001476 C0 07            [24] 4359 	push	ar7
      001478 C0 06            [24] 4360 	push	ar6
      00147A C0 05            [24] 4361 	push	ar5
      00147C C0 04            [24] 4362 	push	ar4
      00147E C0 05            [24] 4363 	push	ar5
      001480 C0 06            [24] 4364 	push	ar6
      001482 C0 07            [24] 4365 	push	ar7
      001484 C0 04            [24] 4366 	push	ar4
      001486 E5 08            [12] 4367 	mov	a,_bp
      001488 24 15            [12] 4368 	add	a,#0x15
      00148A F8               [12] 4369 	mov	r0,a
      00148B 86 82            [24] 4370 	mov	dpl, @r0
      00148D 08               [12] 4371 	inc	r0
      00148E 86 83            [24] 4372 	mov	dph, @r0
      001490 08               [12] 4373 	inc	r0
      001491 86 F0            [24] 4374 	mov	b, @r0
      001493 08               [12] 4375 	inc	r0
      001494 E6               [12] 4376 	mov	a, @r0
      001495 12 2B FE         [24] 4377 	lcall	___fslt
      001498 E5 81            [12] 4378 	mov	a,sp
      00149A 24 FC            [12] 4379 	add	a,#0xfc
      00149C F5 81            [12] 4380 	mov	sp,a
      00149E D0 04            [24] 4381 	pop	ar4
      0014A0 D0 05            [24] 4382 	pop	ar5
      0014A2 D0 06            [24] 4383 	pop	ar6
      0014A4 D0 07            [24] 4384 	pop	ar7
      0014A6 E5 82            [12] 4385 	mov	a, dpl
      0014A8 24 FF            [12] 4386 	add	a,#0xff
      0014AA 92 00            [24] 4387 	mov	b0,c
      0014AC 50 7C            [24] 4388 	jnc	00115$
                           0013F7  4389 	C$fuzzy.h$1292$1_0$77 ==.
                                   4390 ;	../../fuzzy.h:1292: value <= parameter_1 ||
      0014AE C0 07            [24] 4391 	push	ar7
      0014B0 C0 06            [24] 4392 	push	ar6
      0014B2 C0 05            [24] 4393 	push	ar5
      0014B4 C0 04            [24] 4394 	push	ar4
      0014B6 E5 08            [12] 4395 	mov	a,_bp
      0014B8 24 FA            [12] 4396 	add	a,#0xfa
      0014BA F8               [12] 4397 	mov	r0,a
      0014BB E6               [12] 4398 	mov	a,@r0
      0014BC C0 E0            [24] 4399 	push	acc
      0014BE 08               [12] 4400 	inc	r0
      0014BF E6               [12] 4401 	mov	a,@r0
      0014C0 C0 E0            [24] 4402 	push	acc
      0014C2 08               [12] 4403 	inc	r0
      0014C3 E6               [12] 4404 	mov	a,@r0
      0014C4 C0 E0            [24] 4405 	push	acc
      0014C6 08               [12] 4406 	inc	r0
      0014C7 E6               [12] 4407 	mov	a,@r0
      0014C8 C0 E0            [24] 4408 	push	acc
      0014CA E5 08            [12] 4409 	mov	a,_bp
      0014CC 24 11            [12] 4410 	add	a,#0x11
      0014CE F8               [12] 4411 	mov	r0,a
      0014CF 86 82            [24] 4412 	mov	dpl, @r0
      0014D1 08               [12] 4413 	inc	r0
      0014D2 86 83            [24] 4414 	mov	dph, @r0
      0014D4 08               [12] 4415 	inc	r0
      0014D5 86 F0            [24] 4416 	mov	b, @r0
      0014D7 08               [12] 4417 	inc	r0
      0014D8 E6               [12] 4418 	mov	a, @r0
      0014D9 12 2B FE         [24] 4419 	lcall	___fslt
      0014DC E5 81            [12] 4420 	mov	a,sp
      0014DE 24 FC            [12] 4421 	add	a,#0xfc
      0014E0 F5 81            [12] 4422 	mov	sp,a
      0014E2 D0 04            [24] 4423 	pop	ar4
      0014E4 D0 05            [24] 4424 	pop	ar5
      0014E6 D0 06            [24] 4425 	pop	ar6
      0014E8 D0 07            [24] 4426 	pop	ar7
      0014EA E5 82            [12] 4427 	mov	a, dpl
      0014EC 24 FF            [12] 4428 	add	a,#0xff
      0014EE 92 00            [24] 4429 	mov	b0,c
      0014F0 50 38            [24] 4430 	jnc	00115$
                           00143B  4431 	C$fuzzy.h$1294$1_0$77 ==.
                                   4432 ;	../../fuzzy.h:1294: ) {
      0014F2 C0 07            [24] 4433 	push	ar7
      0014F4 C0 06            [24] 4434 	push	ar6
      0014F6 C0 05            [24] 4435 	push	ar5
      0014F8 C0 04            [24] 4436 	push	ar4
      0014FA C0 05            [24] 4437 	push	ar5
      0014FC C0 06            [24] 4438 	push	ar6
      0014FE C0 07            [24] 4439 	push	ar7
      001500 C0 04            [24] 4440 	push	ar4
      001502 E5 08            [12] 4441 	mov	a,_bp
      001504 24 FA            [12] 4442 	add	a,#0xfa
      001506 F8               [12] 4443 	mov	r0,a
      001507 86 82            [24] 4444 	mov	dpl, @r0
      001509 08               [12] 4445 	inc	r0
      00150A 86 83            [24] 4446 	mov	dph, @r0
      00150C 08               [12] 4447 	inc	r0
      00150D 86 F0            [24] 4448 	mov	b, @r0
      00150F 08               [12] 4449 	inc	r0
      001510 E6               [12] 4450 	mov	a, @r0
      001511 12 2B FE         [24] 4451 	lcall	___fslt
      001514 E5 81            [12] 4452 	mov	a,sp
      001516 24 FC            [12] 4453 	add	a,#0xfc
      001518 F5 81            [12] 4454 	mov	sp,a
      00151A D0 04            [24] 4455 	pop	ar4
      00151C D0 05            [24] 4456 	pop	ar5
      00151E D0 06            [24] 4457 	pop	ar6
      001520 D0 07            [24] 4458 	pop	ar7
      001522 E5 82            [12] 4459 	mov	a, dpl
      001524 24 FF            [12] 4460 	add	a,#0xff
      001526 92 00            [24] 4461 	mov	b0,c
      001528 40 10            [24] 4462 	jc	00116$
      00152A                       4463 00115$:
                           001473  4464 	C$fuzzy.h$1295$3_0$82 ==.
                                   4465 ;	../../fuzzy.h:1295: result = LEVEL_LO;
      00152A E5 08            [12] 4466 	mov	a,_bp
      00152C 24 05            [12] 4467 	add	a,#0x05
      00152E F8               [12] 4468 	mov	r0,a
      00152F E4               [12] 4469 	clr	a
      001530 F6               [12] 4470 	mov	@r0,a
      001531 08               [12] 4471 	inc	r0
      001532 F6               [12] 4472 	mov	@r0,a
      001533 08               [12] 4473 	inc	r0
      001534 F6               [12] 4474 	mov	@r0,a
      001535 08               [12] 4475 	inc	r0
      001536 F6               [12] 4476 	mov	@r0,a
      001537 02 1B 65         [24] 4477 	ljmp	00148$
      00153A                       4478 00116$:
                           001483  4479 	C$fuzzy.h$1297$1_0$77 ==.
                                   4480 ;	../../fuzzy.h:1297: else if (value == parameter_2) {
      00153A C0 07            [24] 4481 	push	ar7
      00153C C0 06            [24] 4482 	push	ar6
      00153E C0 05            [24] 4483 	push	ar5
      001540 C0 04            [24] 4484 	push	ar4
      001542 E5 08            [12] 4485 	mov	a,_bp
      001544 24 15            [12] 4486 	add	a,#0x15
      001546 F8               [12] 4487 	mov	r0,a
      001547 E6               [12] 4488 	mov	a,@r0
      001548 C0 E0            [24] 4489 	push	acc
      00154A 08               [12] 4490 	inc	r0
      00154B E6               [12] 4491 	mov	a,@r0
      00154C C0 E0            [24] 4492 	push	acc
      00154E 08               [12] 4493 	inc	r0
      00154F E6               [12] 4494 	mov	a,@r0
      001550 C0 E0            [24] 4495 	push	acc
      001552 08               [12] 4496 	inc	r0
      001553 E6               [12] 4497 	mov	a,@r0
      001554 C0 E0            [24] 4498 	push	acc
      001556 E5 08            [12] 4499 	mov	a,_bp
      001558 24 FA            [12] 4500 	add	a,#0xfa
      00155A F8               [12] 4501 	mov	r0,a
      00155B 86 82            [24] 4502 	mov	dpl, @r0
      00155D 08               [12] 4503 	inc	r0
      00155E 86 83            [24] 4504 	mov	dph, @r0
      001560 08               [12] 4505 	inc	r0
      001561 86 F0            [24] 4506 	mov	b, @r0
      001563 08               [12] 4507 	inc	r0
      001564 E6               [12] 4508 	mov	a, @r0
      001565 12 2B D2         [24] 4509 	lcall	___fseq
      001568 AB 82            [24] 4510 	mov	r3, dpl
      00156A E5 81            [12] 4511 	mov	a,sp
      00156C 24 FC            [12] 4512 	add	a,#0xfc
      00156E F5 81            [12] 4513 	mov	sp,a
      001570 D0 04            [24] 4514 	pop	ar4
      001572 D0 05            [24] 4515 	pop	ar5
      001574 D0 06            [24] 4516 	pop	ar6
      001576 D0 07            [24] 4517 	pop	ar7
      001578 EB               [12] 4518 	mov	a,r3
      001579 60 12            [24] 4519 	jz	00113$
                           0014C4  4520 	C$fuzzy.h$1298$3_0$83 ==.
                                   4521 ;	../../fuzzy.h:1298: result = LEVEL_HI;
      00157B E5 08            [12] 4522 	mov	a,_bp
      00157D 24 05            [12] 4523 	add	a,#0x05
      00157F F8               [12] 4524 	mov	r0,a
      001580 E4               [12] 4525 	clr	a
      001581 F6               [12] 4526 	mov	@r0,a
      001582 08               [12] 4527 	inc	r0
      001583 F6               [12] 4528 	mov	@r0,a
      001584 08               [12] 4529 	inc	r0
      001585 76 80            [12] 4530 	mov	@r0,#0x80
      001587 08               [12] 4531 	inc	r0
      001588 76 3F            [12] 4532 	mov	@r0,#0x3f
      00158A 02 1B 65         [24] 4533 	ljmp	00148$
      00158D                       4534 00113$:
                           0014D6  4535 	C$fuzzy.h$1300$1_0$77 ==.
                                   4536 ;	../../fuzzy.h:1300: else if (value < parameter_2) {
      00158D C0 07            [24] 4537 	push	ar7
      00158F C0 06            [24] 4538 	push	ar6
      001591 C0 05            [24] 4539 	push	ar5
      001593 C0 04            [24] 4540 	push	ar4
      001595 E5 08            [12] 4541 	mov	a,_bp
      001597 24 15            [12] 4542 	add	a,#0x15
      001599 F8               [12] 4543 	mov	r0,a
      00159A E6               [12] 4544 	mov	a,@r0
      00159B C0 E0            [24] 4545 	push	acc
      00159D 08               [12] 4546 	inc	r0
      00159E E6               [12] 4547 	mov	a,@r0
      00159F C0 E0            [24] 4548 	push	acc
      0015A1 08               [12] 4549 	inc	r0
      0015A2 E6               [12] 4550 	mov	a,@r0
      0015A3 C0 E0            [24] 4551 	push	acc
      0015A5 08               [12] 4552 	inc	r0
      0015A6 E6               [12] 4553 	mov	a,@r0
      0015A7 C0 E0            [24] 4554 	push	acc
      0015A9 E5 08            [12] 4555 	mov	a,_bp
      0015AB 24 FA            [12] 4556 	add	a,#0xfa
      0015AD F8               [12] 4557 	mov	r0,a
      0015AE 86 82            [24] 4558 	mov	dpl, @r0
      0015B0 08               [12] 4559 	inc	r0
      0015B1 86 83            [24] 4560 	mov	dph, @r0
      0015B3 08               [12] 4561 	inc	r0
      0015B4 86 F0            [24] 4562 	mov	b, @r0
      0015B6 08               [12] 4563 	inc	r0
      0015B7 E6               [12] 4564 	mov	a, @r0
      0015B8 12 2B FE         [24] 4565 	lcall	___fslt
      0015BB AB 82            [24] 4566 	mov	r3, dpl
      0015BD E5 81            [12] 4567 	mov	a,sp
      0015BF 24 FC            [12] 4568 	add	a,#0xfc
      0015C1 F5 81            [12] 4569 	mov	sp,a
      0015C3 D0 04            [24] 4570 	pop	ar4
      0015C5 D0 05            [24] 4571 	pop	ar5
      0015C7 D0 06            [24] 4572 	pop	ar6
      0015C9 D0 07            [24] 4573 	pop	ar7
      0015CB EB               [12] 4574 	mov	a,r3
      0015CC 70 03            [24] 4575 	jnz	00282$
      0015CE 02 16 87         [24] 4576 	ljmp	00110$
      0015D1                       4577 00282$:
                           00151A  4578 	C$fuzzy.h$1301$1_0$77 ==.
                                   4579 ;	../../fuzzy.h:1301: result = (value - parameter_1) /
      0015D1 E5 08            [12] 4580 	mov	a,_bp
      0015D3 24 11            [12] 4581 	add	a,#0x11
      0015D5 F8               [12] 4582 	mov	r0,a
      0015D6 E6               [12] 4583 	mov	a,@r0
      0015D7 C0 E0            [24] 4584 	push	acc
      0015D9 08               [12] 4585 	inc	r0
      0015DA E6               [12] 4586 	mov	a,@r0
      0015DB C0 E0            [24] 4587 	push	acc
      0015DD 08               [12] 4588 	inc	r0
      0015DE E6               [12] 4589 	mov	a,@r0
      0015DF C0 E0            [24] 4590 	push	acc
      0015E1 08               [12] 4591 	inc	r0
      0015E2 E6               [12] 4592 	mov	a,@r0
      0015E3 C0 E0            [24] 4593 	push	acc
                           00152E  4594 	C$fuzzy.h$1302$1_0$77 ==.
                                   4595 ;	../../fuzzy.h:1302: (parameter_2 - parameter_1);
      0015E5 E5 08            [12] 4596 	mov	a,_bp
      0015E7 24 FA            [12] 4597 	add	a,#0xfa
      0015E9 F8               [12] 4598 	mov	r0,a
      0015EA 86 82            [24] 4599 	mov	dpl, @r0
      0015EC 08               [12] 4600 	inc	r0
      0015ED 86 83            [24] 4601 	mov	dph, @r0
      0015EF 08               [12] 4602 	inc	r0
      0015F0 86 F0            [24] 4603 	mov	b, @r0
      0015F2 08               [12] 4604 	inc	r0
      0015F3 E6               [12] 4605 	mov	a, @r0
      0015F4 12 2A C3         [24] 4606 	lcall	___fssub
      0015F7 AF 82            [24] 4607 	mov	r7, dpl
      0015F9 AE 83            [24] 4608 	mov	r6, dph
      0015FB AD F0            [24] 4609 	mov	r5, b
      0015FD FC               [12] 4610 	mov	r4, a
      0015FE E5 81            [12] 4611 	mov	a,sp
      001600 24 FC            [12] 4612 	add	a,#0xfc
      001602 F5 81            [12] 4613 	mov	sp,a
      001604 C0 07            [24] 4614 	push	ar7
      001606 C0 06            [24] 4615 	push	ar6
      001608 C0 05            [24] 4616 	push	ar5
      00160A C0 04            [24] 4617 	push	ar4
      00160C E5 08            [12] 4618 	mov	a,_bp
      00160E 24 11            [12] 4619 	add	a,#0x11
      001610 F8               [12] 4620 	mov	r0,a
      001611 E6               [12] 4621 	mov	a,@r0
      001612 C0 E0            [24] 4622 	push	acc
      001614 08               [12] 4623 	inc	r0
      001615 E6               [12] 4624 	mov	a,@r0
      001616 C0 E0            [24] 4625 	push	acc
      001618 08               [12] 4626 	inc	r0
      001619 E6               [12] 4627 	mov	a,@r0
      00161A C0 E0            [24] 4628 	push	acc
      00161C 08               [12] 4629 	inc	r0
      00161D E6               [12] 4630 	mov	a,@r0
      00161E C0 E0            [24] 4631 	push	acc
      001620 E5 08            [12] 4632 	mov	a,_bp
      001622 24 15            [12] 4633 	add	a,#0x15
      001624 F8               [12] 4634 	mov	r0,a
      001625 86 82            [24] 4635 	mov	dpl, @r0
      001627 08               [12] 4636 	inc	r0
      001628 86 83            [24] 4637 	mov	dph, @r0
      00162A 08               [12] 4638 	inc	r0
      00162B 86 F0            [24] 4639 	mov	b, @r0
      00162D 08               [12] 4640 	inc	r0
      00162E E6               [12] 4641 	mov	a, @r0
      00162F 12 2A C3         [24] 4642 	lcall	___fssub
      001632 C8               [12] 4643 	xch	a,r0
      001633 E5 08            [12] 4644 	mov	a,_bp
      001635 24 09            [12] 4645 	add	a,#0x09
      001637 C8               [12] 4646 	xch	a,r0
      001638 A6 82            [24] 4647 	mov	@r0, dpl
      00163A 08               [12] 4648 	inc	r0
      00163B A6 83            [24] 4649 	mov	@r0, dph
      00163D 08               [12] 4650 	inc	r0
      00163E A6 F0            [24] 4651 	mov	@r0, b
      001640 08               [12] 4652 	inc	r0
      001641 F6               [12] 4653 	mov	@r0,a
      001642 E5 81            [12] 4654 	mov	a,sp
      001644 24 FC            [12] 4655 	add	a,#0xfc
      001646 F5 81            [12] 4656 	mov	sp,a
      001648 D0 04            [24] 4657 	pop	ar4
      00164A D0 05            [24] 4658 	pop	ar5
      00164C D0 06            [24] 4659 	pop	ar6
      00164E D0 07            [24] 4660 	pop	ar7
      001650 E5 08            [12] 4661 	mov	a,_bp
      001652 24 09            [12] 4662 	add	a,#0x09
      001654 F8               [12] 4663 	mov	r0,a
      001655 E6               [12] 4664 	mov	a,@r0
      001656 C0 E0            [24] 4665 	push	acc
      001658 08               [12] 4666 	inc	r0
      001659 E6               [12] 4667 	mov	a,@r0
      00165A C0 E0            [24] 4668 	push	acc
      00165C 08               [12] 4669 	inc	r0
      00165D E6               [12] 4670 	mov	a,@r0
      00165E C0 E0            [24] 4671 	push	acc
      001660 08               [12] 4672 	inc	r0
      001661 E6               [12] 4673 	mov	a,@r0
      001662 C0 E0            [24] 4674 	push	acc
      001664 8F 82            [24] 4675 	mov	dpl, r7
      001666 8E 83            [24] 4676 	mov	dph, r6
      001668 8D F0            [24] 4677 	mov	b, r5
      00166A EC               [12] 4678 	mov	a, r4
      00166B 12 2D 67         [24] 4679 	lcall	___fsdiv
      00166E C8               [12] 4680 	xch	a,r0
      00166F E5 08            [12] 4681 	mov	a,_bp
      001671 24 05            [12] 4682 	add	a,#0x05
      001673 C8               [12] 4683 	xch	a,r0
      001674 A6 82            [24] 4684 	mov	@r0, dpl
      001676 08               [12] 4685 	inc	r0
      001677 A6 83            [24] 4686 	mov	@r0, dph
      001679 08               [12] 4687 	inc	r0
      00167A A6 F0            [24] 4688 	mov	@r0, b
      00167C 08               [12] 4689 	inc	r0
      00167D F6               [12] 4690 	mov	@r0,a
      00167E E5 81            [12] 4691 	mov	a,sp
      001680 24 FC            [12] 4692 	add	a,#0xfc
      001682 F5 81            [12] 4693 	mov	sp,a
      001684 02 1B 65         [24] 4694 	ljmp	00148$
      001687                       4695 00110$:
                           0015D0  4696 	C$fuzzy.h$1305$1_0$77 ==.
                                   4697 ;	../../fuzzy.h:1305: result = (parameter_3 - value) /
      001687 C0 07            [24] 4698 	push	ar7
      001689 C0 06            [24] 4699 	push	ar6
      00168B C0 05            [24] 4700 	push	ar5
      00168D C0 04            [24] 4701 	push	ar4
      00168F E5 08            [12] 4702 	mov	a,_bp
      001691 24 FA            [12] 4703 	add	a,#0xfa
      001693 F8               [12] 4704 	mov	r0,a
      001694 E6               [12] 4705 	mov	a,@r0
      001695 C0 E0            [24] 4706 	push	acc
      001697 08               [12] 4707 	inc	r0
      001698 E6               [12] 4708 	mov	a,@r0
      001699 C0 E0            [24] 4709 	push	acc
      00169B 08               [12] 4710 	inc	r0
      00169C E6               [12] 4711 	mov	a,@r0
      00169D C0 E0            [24] 4712 	push	acc
      00169F 08               [12] 4713 	inc	r0
      0016A0 E6               [12] 4714 	mov	a,@r0
      0016A1 C0 E0            [24] 4715 	push	acc
                           0015EC  4716 	C$fuzzy.h$1306$1_0$77 ==.
                                   4717 ;	../../fuzzy.h:1306: (parameter_3 - parameter_2);
      0016A3 8D 82            [24] 4718 	mov	dpl, r5
      0016A5 8E 83            [24] 4719 	mov	dph, r6
      0016A7 8F F0            [24] 4720 	mov	b, r7
      0016A9 EC               [12] 4721 	mov	a, r4
      0016AA 12 2A C3         [24] 4722 	lcall	___fssub
      0016AD A8 08            [24] 4723 	mov	r0,_bp
      0016AF 08               [12] 4724 	inc	r0
      0016B0 A6 82            [24] 4725 	mov	@r0, dpl
      0016B2 08               [12] 4726 	inc	r0
      0016B3 A6 83            [24] 4727 	mov	@r0, dph
      0016B5 08               [12] 4728 	inc	r0
      0016B6 A6 F0            [24] 4729 	mov	@r0, b
      0016B8 08               [12] 4730 	inc	r0
      0016B9 F6               [12] 4731 	mov	@r0,a
      0016BA E5 81            [12] 4732 	mov	a,sp
      0016BC 24 FC            [12] 4733 	add	a,#0xfc
      0016BE F5 81            [12] 4734 	mov	sp,a
      0016C0 D0 04            [24] 4735 	pop	ar4
      0016C2 D0 05            [24] 4736 	pop	ar5
      0016C4 D0 06            [24] 4737 	pop	ar6
      0016C6 D0 07            [24] 4738 	pop	ar7
      0016C8 E5 08            [12] 4739 	mov	a,_bp
      0016CA 24 15            [12] 4740 	add	a,#0x15
      0016CC F8               [12] 4741 	mov	r0,a
      0016CD E6               [12] 4742 	mov	a,@r0
      0016CE C0 E0            [24] 4743 	push	acc
      0016D0 08               [12] 4744 	inc	r0
      0016D1 E6               [12] 4745 	mov	a,@r0
      0016D2 C0 E0            [24] 4746 	push	acc
      0016D4 08               [12] 4747 	inc	r0
      0016D5 E6               [12] 4748 	mov	a,@r0
      0016D6 C0 E0            [24] 4749 	push	acc
      0016D8 08               [12] 4750 	inc	r0
      0016D9 E6               [12] 4751 	mov	a,@r0
      0016DA C0 E0            [24] 4752 	push	acc
      0016DC 8D 82            [24] 4753 	mov	dpl, r5
      0016DE 8E 83            [24] 4754 	mov	dph, r6
      0016E0 8F F0            [24] 4755 	mov	b, r7
      0016E2 EC               [12] 4756 	mov	a, r4
      0016E3 12 2A C3         [24] 4757 	lcall	___fssub
      0016E6 AC 82            [24] 4758 	mov	r4, dpl
      0016E8 AD 83            [24] 4759 	mov	r5, dph
      0016EA AE F0            [24] 4760 	mov	r6, b
      0016EC FF               [12] 4761 	mov	r7, a
      0016ED E5 81            [12] 4762 	mov	a,sp
      0016EF 24 FC            [12] 4763 	add	a,#0xfc
      0016F1 F5 81            [12] 4764 	mov	sp,a
      0016F3 C0 04            [24] 4765 	push	ar4
      0016F5 C0 05            [24] 4766 	push	ar5
      0016F7 C0 06            [24] 4767 	push	ar6
      0016F9 C0 07            [24] 4768 	push	ar7
                           001644  4769 	C$fuzzy.h$1308$1_0$77 ==.
                                   4770 ;	../../fuzzy.h:1308: break;
      0016FB A8 08            [24] 4771 	mov	r0,_bp
      0016FD 08               [12] 4772 	inc	r0
      0016FE 86 82            [24] 4773 	mov	dpl, @r0
      001700 08               [12] 4774 	inc	r0
      001701 86 83            [24] 4775 	mov	dph, @r0
      001703 08               [12] 4776 	inc	r0
      001704 86 F0            [24] 4777 	mov	b, @r0
      001706 08               [12] 4778 	inc	r0
      001707 E6               [12] 4779 	mov	a, @r0
      001708 12 2D 67         [24] 4780 	lcall	___fsdiv
      00170B C8               [12] 4781 	xch	a,r0
      00170C E5 08            [12] 4782 	mov	a,_bp
      00170E 24 05            [12] 4783 	add	a,#0x05
      001710 C8               [12] 4784 	xch	a,r0
      001711 A6 82            [24] 4785 	mov	@r0, dpl
      001713 08               [12] 4786 	inc	r0
      001714 A6 83            [24] 4787 	mov	@r0, dph
      001716 08               [12] 4788 	inc	r0
      001717 A6 F0            [24] 4789 	mov	@r0, b
      001719 08               [12] 4790 	inc	r0
      00171A F6               [12] 4791 	mov	@r0,a
      00171B E5 81            [12] 4792 	mov	a,sp
      00171D 24 FC            [12] 4793 	add	a,#0xfc
      00171F F5 81            [12] 4794 	mov	sp,a
      001721 02 1B 65         [24] 4795 	ljmp	00148$
                           00166D  4796 	C$fuzzy.h$1310$2_0$79 ==.
                                   4797 ;	../../fuzzy.h:1310: case FUZZY_SHAPE_TRAPEZOID:
      001724                       4798 00121$:
                           00166D  4799 	C$fuzzy.h$1311$2_0$79 ==.
                                   4800 ;	../../fuzzy.h:1311: if (parameter_count != 4u) {
      001724 E5 08            [12] 4801 	mov	a,_bp
      001726 24 F7            [12] 4802 	add	a,#0xf7
      001728 F8               [12] 4803 	mov	r0,a
      001729 B6 04 06         [24] 4804 	cjne	@r0,#0x04,00283$
      00172C 08               [12] 4805 	inc	r0
      00172D B6 00 02         [24] 4806 	cjne	@r0,#0x00,00283$
      001730 80 09            [24] 4807 	sjmp	00123$
      001732                       4808 00283$:
                           00167B  4809 	C$fuzzy.h$1312$3_0$86 ==.
                                   4810 ;	../../fuzzy.h:1312: return LEVEL_LO;
      001732 90 00 00         [24] 4811 	mov	dptr,#0x0000
      001735 E4               [12] 4812 	clr	a
      001736 F5 F0            [12] 4813 	mov	b,a
      001738 02 1B 8F         [24] 4814 	ljmp	00149$
      00173B                       4815 00123$:
                           001684  4816 	C$fuzzy.h$1315$2_0$79 ==.
                                   4817 ;	../../fuzzy.h:1315: parameter_1 = parameters[0];
      00173B E5 08            [12] 4818 	mov	a,_bp
      00173D 24 F4            [12] 4819 	add	a,#0xf4
      00173F F8               [12] 4820 	mov	r0,a
      001740 86 05            [24] 4821 	mov	ar5,@r0
      001742 08               [12] 4822 	inc	r0
      001743 86 06            [24] 4823 	mov	ar6,@r0
      001745 08               [12] 4824 	inc	r0
      001746 86 07            [24] 4825 	mov	ar7,@r0
      001748 8D 82            [24] 4826 	mov	dpl,r5
      00174A 8E 83            [24] 4827 	mov	dph,r6
      00174C 8F F0            [24] 4828 	mov	b,r7
      00174E E5 08            [12] 4829 	mov	a,_bp
      001750 24 09            [12] 4830 	add	a,#0x09
      001752 F8               [12] 4831 	mov	r0,a
      001753 12 2E 2A         [24] 4832 	lcall	__gptrget
      001756 F6               [12] 4833 	mov	@r0,a
      001757 A3               [24] 4834 	inc	dptr
      001758 12 2E 2A         [24] 4835 	lcall	__gptrget
      00175B 08               [12] 4836 	inc	r0
      00175C F6               [12] 4837 	mov	@r0,a
      00175D A3               [24] 4838 	inc	dptr
      00175E 12 2E 2A         [24] 4839 	lcall	__gptrget
      001761 08               [12] 4840 	inc	r0
      001762 F6               [12] 4841 	mov	@r0,a
      001763 A3               [24] 4842 	inc	dptr
      001764 12 2E 2A         [24] 4843 	lcall	__gptrget
      001767 08               [12] 4844 	inc	r0
      001768 F6               [12] 4845 	mov	@r0,a
                           0016B2  4846 	C$fuzzy.h$1316$2_0$79 ==.
                                   4847 ;	../../fuzzy.h:1316: parameter_2 = parameters[1];
      001769 74 04            [12] 4848 	mov	a,#0x04
      00176B 2D               [12] 4849 	add	a, r5
      00176C FA               [12] 4850 	mov	r2,a
      00176D E4               [12] 4851 	clr	a
      00176E 3E               [12] 4852 	addc	a, r6
      00176F FB               [12] 4853 	mov	r3,a
      001770 8F 04            [24] 4854 	mov	ar4,r7
      001772 8A 82            [24] 4855 	mov	dpl,r2
      001774 8B 83            [24] 4856 	mov	dph,r3
      001776 8C F0            [24] 4857 	mov	b,r4
      001778 A8 08            [24] 4858 	mov	r0,_bp
      00177A 08               [12] 4859 	inc	r0
      00177B 12 2E 2A         [24] 4860 	lcall	__gptrget
      00177E F6               [12] 4861 	mov	@r0,a
      00177F A3               [24] 4862 	inc	dptr
      001780 12 2E 2A         [24] 4863 	lcall	__gptrget
      001783 08               [12] 4864 	inc	r0
      001784 F6               [12] 4865 	mov	@r0,a
      001785 A3               [24] 4866 	inc	dptr
      001786 12 2E 2A         [24] 4867 	lcall	__gptrget
      001789 08               [12] 4868 	inc	r0
      00178A F6               [12] 4869 	mov	@r0,a
      00178B A3               [24] 4870 	inc	dptr
      00178C 12 2E 2A         [24] 4871 	lcall	__gptrget
      00178F 08               [12] 4872 	inc	r0
      001790 F6               [12] 4873 	mov	@r0,a
                           0016DA  4874 	C$fuzzy.h$1317$2_0$79 ==.
                                   4875 ;	../../fuzzy.h:1317: parameter_3 = parameters[2];
      001791 74 08            [12] 4876 	mov	a,#0x08
      001793 2D               [12] 4877 	add	a, r5
      001794 FA               [12] 4878 	mov	r2,a
      001795 E4               [12] 4879 	clr	a
      001796 3E               [12] 4880 	addc	a, r6
      001797 FB               [12] 4881 	mov	r3,a
      001798 8F 04            [24] 4882 	mov	ar4,r7
      00179A 8A 82            [24] 4883 	mov	dpl,r2
      00179C 8B 83            [24] 4884 	mov	dph,r3
      00179E 8C F0            [24] 4885 	mov	b,r4
      0017A0 E5 08            [12] 4886 	mov	a,_bp
      0017A2 24 19            [12] 4887 	add	a,#0x19
      0017A4 F8               [12] 4888 	mov	r0,a
      0017A5 12 2E 2A         [24] 4889 	lcall	__gptrget
      0017A8 F6               [12] 4890 	mov	@r0,a
      0017A9 A3               [24] 4891 	inc	dptr
      0017AA 12 2E 2A         [24] 4892 	lcall	__gptrget
      0017AD 08               [12] 4893 	inc	r0
      0017AE F6               [12] 4894 	mov	@r0,a
      0017AF A3               [24] 4895 	inc	dptr
      0017B0 12 2E 2A         [24] 4896 	lcall	__gptrget
      0017B3 08               [12] 4897 	inc	r0
      0017B4 F6               [12] 4898 	mov	@r0,a
      0017B5 A3               [24] 4899 	inc	dptr
      0017B6 12 2E 2A         [24] 4900 	lcall	__gptrget
      0017B9 08               [12] 4901 	inc	r0
      0017BA F6               [12] 4902 	mov	@r0,a
                           001704  4903 	C$fuzzy.h$1318$2_0$79 ==.
                                   4904 ;	../../fuzzy.h:1318: parameter_4 = parameters[3];
      0017BB 74 0C            [12] 4905 	mov	a,#0x0c
      0017BD 2D               [12] 4906 	add	a, r5
      0017BE FD               [12] 4907 	mov	r5,a
      0017BF E4               [12] 4908 	clr	a
      0017C0 3E               [12] 4909 	addc	a, r6
      0017C1 FE               [12] 4910 	mov	r6,a
      0017C2 8D 82            [24] 4911 	mov	dpl,r5
      0017C4 8E 83            [24] 4912 	mov	dph,r6
      0017C6 8F F0            [24] 4913 	mov	b,r7
      0017C8 12 2E 2A         [24] 4914 	lcall	__gptrget
      0017CB FD               [12] 4915 	mov	r5,a
      0017CC A3               [24] 4916 	inc	dptr
      0017CD 12 2E 2A         [24] 4917 	lcall	__gptrget
      0017D0 FE               [12] 4918 	mov	r6,a
      0017D1 A3               [24] 4919 	inc	dptr
      0017D2 12 2E 2A         [24] 4920 	lcall	__gptrget
      0017D5 FF               [12] 4921 	mov	r7,a
      0017D6 A3               [24] 4922 	inc	dptr
      0017D7 12 2E 2A         [24] 4923 	lcall	__gptrget
      0017DA FC               [12] 4924 	mov	r4,a
                           001724  4925 	C$fuzzy.h$1321$1_0$77 ==.
                                   4926 ;	../../fuzzy.h:1321: parameter_1 >= parameter_2 ||
      0017DB C0 07            [24] 4927 	push	ar7
      0017DD C0 06            [24] 4928 	push	ar6
      0017DF C0 05            [24] 4929 	push	ar5
      0017E1 C0 04            [24] 4930 	push	ar4
      0017E3 A8 08            [24] 4931 	mov	r0,_bp
      0017E5 08               [12] 4932 	inc	r0
      0017E6 E6               [12] 4933 	mov	a,@r0
      0017E7 C0 E0            [24] 4934 	push	acc
      0017E9 08               [12] 4935 	inc	r0
      0017EA E6               [12] 4936 	mov	a,@r0
      0017EB C0 E0            [24] 4937 	push	acc
      0017ED 08               [12] 4938 	inc	r0
      0017EE E6               [12] 4939 	mov	a,@r0
      0017EF C0 E0            [24] 4940 	push	acc
      0017F1 08               [12] 4941 	inc	r0
      0017F2 E6               [12] 4942 	mov	a,@r0
      0017F3 C0 E0            [24] 4943 	push	acc
      0017F5 E5 08            [12] 4944 	mov	a,_bp
      0017F7 24 09            [12] 4945 	add	a,#0x09
      0017F9 F8               [12] 4946 	mov	r0,a
      0017FA 86 82            [24] 4947 	mov	dpl, @r0
      0017FC 08               [12] 4948 	inc	r0
      0017FD 86 83            [24] 4949 	mov	dph, @r0
      0017FF 08               [12] 4950 	inc	r0
      001800 86 F0            [24] 4951 	mov	b, @r0
      001802 08               [12] 4952 	inc	r0
      001803 E6               [12] 4953 	mov	a, @r0
      001804 12 2B FE         [24] 4954 	lcall	___fslt
      001807 E5 81            [12] 4955 	mov	a,sp
      001809 24 FC            [12] 4956 	add	a,#0xfc
      00180B F5 81            [12] 4957 	mov	sp,a
      00180D D0 04            [24] 4958 	pop	ar4
      00180F D0 05            [24] 4959 	pop	ar5
      001811 D0 06            [24] 4960 	pop	ar6
      001813 D0 07            [24] 4961 	pop	ar7
      001815 E5 82            [12] 4962 	mov	a, dpl
      001817 24 FF            [12] 4963 	add	a,#0xff
      001819 92 00            [24] 4964 	mov	b0,c
      00181B 40 03            [24] 4965 	jc	00284$
      00181D 02 19 16         [24] 4966 	ljmp	00131$
      001820                       4967 00284$:
                           001769  4968 	C$fuzzy.h$1322$1_0$77 ==.
                                   4969 ;	../../fuzzy.h:1322: parameter_2 > parameter_3 ||
      001820 C0 07            [24] 4970 	push	ar7
      001822 C0 06            [24] 4971 	push	ar6
      001824 C0 05            [24] 4972 	push	ar5
      001826 C0 04            [24] 4973 	push	ar4
      001828 A8 08            [24] 4974 	mov	r0,_bp
      00182A 08               [12] 4975 	inc	r0
      00182B E6               [12] 4976 	mov	a,@r0
      00182C C0 E0            [24] 4977 	push	acc
      00182E 08               [12] 4978 	inc	r0
      00182F E6               [12] 4979 	mov	a,@r0
      001830 C0 E0            [24] 4980 	push	acc
      001832 08               [12] 4981 	inc	r0
      001833 E6               [12] 4982 	mov	a,@r0
      001834 C0 E0            [24] 4983 	push	acc
      001836 08               [12] 4984 	inc	r0
      001837 E6               [12] 4985 	mov	a,@r0
      001838 C0 E0            [24] 4986 	push	acc
      00183A E5 08            [12] 4987 	mov	a,_bp
      00183C 24 19            [12] 4988 	add	a,#0x19
      00183E F8               [12] 4989 	mov	r0,a
      00183F 86 82            [24] 4990 	mov	dpl, @r0
      001841 08               [12] 4991 	inc	r0
      001842 86 83            [24] 4992 	mov	dph, @r0
      001844 08               [12] 4993 	inc	r0
      001845 86 F0            [24] 4994 	mov	b, @r0
      001847 08               [12] 4995 	inc	r0
      001848 E6               [12] 4996 	mov	a, @r0
      001849 12 2B FE         [24] 4997 	lcall	___fslt
      00184C AB 82            [24] 4998 	mov	r3, dpl
      00184E E5 81            [12] 4999 	mov	a,sp
      001850 24 FC            [12] 5000 	add	a,#0xfc
      001852 F5 81            [12] 5001 	mov	sp,a
      001854 D0 04            [24] 5002 	pop	ar4
      001856 D0 05            [24] 5003 	pop	ar5
      001858 D0 06            [24] 5004 	pop	ar6
      00185A D0 07            [24] 5005 	pop	ar7
      00185C EB               [12] 5006 	mov	a,r3
      00185D 60 03            [24] 5007 	jz	00285$
      00185F 02 19 16         [24] 5008 	ljmp	00131$
      001862                       5009 00285$:
                           0017AB  5010 	C$fuzzy.h$1323$1_0$77 ==.
                                   5011 ;	../../fuzzy.h:1323: parameter_3 >= parameter_4 ||
      001862 C0 07            [24] 5012 	push	ar7
      001864 C0 06            [24] 5013 	push	ar6
      001866 C0 05            [24] 5014 	push	ar5
      001868 C0 04            [24] 5015 	push	ar4
      00186A C0 05            [24] 5016 	push	ar5
      00186C C0 06            [24] 5017 	push	ar6
      00186E C0 07            [24] 5018 	push	ar7
      001870 C0 04            [24] 5019 	push	ar4
      001872 E5 08            [12] 5020 	mov	a,_bp
      001874 24 19            [12] 5021 	add	a,#0x19
      001876 F8               [12] 5022 	mov	r0,a
      001877 86 82            [24] 5023 	mov	dpl, @r0
      001879 08               [12] 5024 	inc	r0
      00187A 86 83            [24] 5025 	mov	dph, @r0
      00187C 08               [12] 5026 	inc	r0
      00187D 86 F0            [24] 5027 	mov	b, @r0
      00187F 08               [12] 5028 	inc	r0
      001880 E6               [12] 5029 	mov	a, @r0
      001881 12 2B FE         [24] 5030 	lcall	___fslt
      001884 E5 81            [12] 5031 	mov	a,sp
      001886 24 FC            [12] 5032 	add	a,#0xfc
      001888 F5 81            [12] 5033 	mov	sp,a
      00188A D0 04            [24] 5034 	pop	ar4
      00188C D0 05            [24] 5035 	pop	ar5
      00188E D0 06            [24] 5036 	pop	ar6
      001890 D0 07            [24] 5037 	pop	ar7
      001892 E5 82            [12] 5038 	mov	a, dpl
      001894 24 FF            [12] 5039 	add	a,#0xff
      001896 92 00            [24] 5040 	mov	b0,c
      001898 50 7C            [24] 5041 	jnc	00131$
                           0017E3  5042 	C$fuzzy.h$1324$1_0$77 ==.
                                   5043 ;	../../fuzzy.h:1324: value <= parameter_1 ||
      00189A C0 07            [24] 5044 	push	ar7
      00189C C0 06            [24] 5045 	push	ar6
      00189E C0 05            [24] 5046 	push	ar5
      0018A0 C0 04            [24] 5047 	push	ar4
      0018A2 E5 08            [12] 5048 	mov	a,_bp
      0018A4 24 FA            [12] 5049 	add	a,#0xfa
      0018A6 F8               [12] 5050 	mov	r0,a
      0018A7 E6               [12] 5051 	mov	a,@r0
      0018A8 C0 E0            [24] 5052 	push	acc
      0018AA 08               [12] 5053 	inc	r0
      0018AB E6               [12] 5054 	mov	a,@r0
      0018AC C0 E0            [24] 5055 	push	acc
      0018AE 08               [12] 5056 	inc	r0
      0018AF E6               [12] 5057 	mov	a,@r0
      0018B0 C0 E0            [24] 5058 	push	acc
      0018B2 08               [12] 5059 	inc	r0
      0018B3 E6               [12] 5060 	mov	a,@r0
      0018B4 C0 E0            [24] 5061 	push	acc
      0018B6 E5 08            [12] 5062 	mov	a,_bp
      0018B8 24 09            [12] 5063 	add	a,#0x09
      0018BA F8               [12] 5064 	mov	r0,a
      0018BB 86 82            [24] 5065 	mov	dpl, @r0
      0018BD 08               [12] 5066 	inc	r0
      0018BE 86 83            [24] 5067 	mov	dph, @r0
      0018C0 08               [12] 5068 	inc	r0
      0018C1 86 F0            [24] 5069 	mov	b, @r0
      0018C3 08               [12] 5070 	inc	r0
      0018C4 E6               [12] 5071 	mov	a, @r0
      0018C5 12 2B FE         [24] 5072 	lcall	___fslt
      0018C8 E5 81            [12] 5073 	mov	a,sp
      0018CA 24 FC            [12] 5074 	add	a,#0xfc
      0018CC F5 81            [12] 5075 	mov	sp,a
      0018CE D0 04            [24] 5076 	pop	ar4
      0018D0 D0 05            [24] 5077 	pop	ar5
      0018D2 D0 06            [24] 5078 	pop	ar6
      0018D4 D0 07            [24] 5079 	pop	ar7
      0018D6 E5 82            [12] 5080 	mov	a, dpl
      0018D8 24 FF            [12] 5081 	add	a,#0xff
      0018DA 92 00            [24] 5082 	mov	b0,c
      0018DC 50 38            [24] 5083 	jnc	00131$
                           001827  5084 	C$fuzzy.h$1326$1_0$77 ==.
                                   5085 ;	../../fuzzy.h:1326: ) {
      0018DE C0 07            [24] 5086 	push	ar7
      0018E0 C0 06            [24] 5087 	push	ar6
      0018E2 C0 05            [24] 5088 	push	ar5
      0018E4 C0 04            [24] 5089 	push	ar4
      0018E6 C0 05            [24] 5090 	push	ar5
      0018E8 C0 06            [24] 5091 	push	ar6
      0018EA C0 07            [24] 5092 	push	ar7
      0018EC C0 04            [24] 5093 	push	ar4
      0018EE E5 08            [12] 5094 	mov	a,_bp
      0018F0 24 FA            [12] 5095 	add	a,#0xfa
      0018F2 F8               [12] 5096 	mov	r0,a
      0018F3 86 82            [24] 5097 	mov	dpl, @r0
      0018F5 08               [12] 5098 	inc	r0
      0018F6 86 83            [24] 5099 	mov	dph, @r0
      0018F8 08               [12] 5100 	inc	r0
      0018F9 86 F0            [24] 5101 	mov	b, @r0
      0018FB 08               [12] 5102 	inc	r0
      0018FC E6               [12] 5103 	mov	a, @r0
      0018FD 12 2B FE         [24] 5104 	lcall	___fslt
      001900 E5 81            [12] 5105 	mov	a,sp
      001902 24 FC            [12] 5106 	add	a,#0xfc
      001904 F5 81            [12] 5107 	mov	sp,a
      001906 D0 04            [24] 5108 	pop	ar4
      001908 D0 05            [24] 5109 	pop	ar5
      00190A D0 06            [24] 5110 	pop	ar6
      00190C D0 07            [24] 5111 	pop	ar7
      00190E E5 82            [12] 5112 	mov	a, dpl
      001910 24 FF            [12] 5113 	add	a,#0xff
      001912 92 00            [24] 5114 	mov	b0,c
      001914 40 10            [24] 5115 	jc	00132$
      001916                       5116 00131$:
                           00185F  5117 	C$fuzzy.h$1327$3_0$87 ==.
                                   5118 ;	../../fuzzy.h:1327: result = LEVEL_LO;
      001916 E5 08            [12] 5119 	mov	a,_bp
      001918 24 05            [12] 5120 	add	a,#0x05
      00191A F8               [12] 5121 	mov	r0,a
      00191B E4               [12] 5122 	clr	a
      00191C F6               [12] 5123 	mov	@r0,a
      00191D 08               [12] 5124 	inc	r0
      00191E F6               [12] 5125 	mov	@r0,a
      00191F 08               [12] 5126 	inc	r0
      001920 F6               [12] 5127 	mov	@r0,a
      001921 08               [12] 5128 	inc	r0
      001922 F6               [12] 5129 	mov	@r0,a
      001923 02 1B 65         [24] 5130 	ljmp	00148$
      001926                       5131 00132$:
                           00186F  5132 	C$fuzzy.h$1330$1_0$77 ==.
                                   5133 ;	../../fuzzy.h:1330: value >= parameter_2 &&
      001926 C0 07            [24] 5134 	push	ar7
      001928 C0 06            [24] 5135 	push	ar6
      00192A C0 05            [24] 5136 	push	ar5
      00192C C0 04            [24] 5137 	push	ar4
      00192E A8 08            [24] 5138 	mov	r0,_bp
      001930 08               [12] 5139 	inc	r0
      001931 E6               [12] 5140 	mov	a,@r0
      001932 C0 E0            [24] 5141 	push	acc
      001934 08               [12] 5142 	inc	r0
      001935 E6               [12] 5143 	mov	a,@r0
      001936 C0 E0            [24] 5144 	push	acc
      001938 08               [12] 5145 	inc	r0
      001939 E6               [12] 5146 	mov	a,@r0
      00193A C0 E0            [24] 5147 	push	acc
      00193C 08               [12] 5148 	inc	r0
      00193D E6               [12] 5149 	mov	a,@r0
      00193E C0 E0            [24] 5150 	push	acc
      001940 E5 08            [12] 5151 	mov	a,_bp
      001942 24 FA            [12] 5152 	add	a,#0xfa
      001944 F8               [12] 5153 	mov	r0,a
      001945 86 82            [24] 5154 	mov	dpl, @r0
      001947 08               [12] 5155 	inc	r0
      001948 86 83            [24] 5156 	mov	dph, @r0
      00194A 08               [12] 5157 	inc	r0
      00194B 86 F0            [24] 5158 	mov	b, @r0
      00194D 08               [12] 5159 	inc	r0
      00194E E6               [12] 5160 	mov	a, @r0
      00194F 12 2B FE         [24] 5161 	lcall	___fslt
      001952 E5 81            [12] 5162 	mov	a,sp
      001954 24 FC            [12] 5163 	add	a,#0xfc
      001956 F5 81            [12] 5164 	mov	sp,a
      001958 D0 04            [24] 5165 	pop	ar4
      00195A D0 05            [24] 5166 	pop	ar5
      00195C D0 06            [24] 5167 	pop	ar6
      00195E D0 07            [24] 5168 	pop	ar7
      001960 E5 82            [12] 5169 	mov	a, dpl
      001962 24 FF            [12] 5170 	add	a,#0xff
      001964 92 00            [24] 5171 	mov	b0,c
      001966 40 56            [24] 5172 	jc	00128$
                           0018B1  5173 	C$fuzzy.h$1332$1_0$77 ==.
                                   5174 ;	../../fuzzy.h:1332: ) {
      001968 C0 07            [24] 5175 	push	ar7
      00196A C0 06            [24] 5176 	push	ar6
      00196C C0 05            [24] 5177 	push	ar5
      00196E C0 04            [24] 5178 	push	ar4
      001970 E5 08            [12] 5179 	mov	a,_bp
      001972 24 FA            [12] 5180 	add	a,#0xfa
      001974 F8               [12] 5181 	mov	r0,a
      001975 E6               [12] 5182 	mov	a,@r0
      001976 C0 E0            [24] 5183 	push	acc
      001978 08               [12] 5184 	inc	r0
      001979 E6               [12] 5185 	mov	a,@r0
      00197A C0 E0            [24] 5186 	push	acc
      00197C 08               [12] 5187 	inc	r0
      00197D E6               [12] 5188 	mov	a,@r0
      00197E C0 E0            [24] 5189 	push	acc
      001980 08               [12] 5190 	inc	r0
      001981 E6               [12] 5191 	mov	a,@r0
      001982 C0 E0            [24] 5192 	push	acc
      001984 E5 08            [12] 5193 	mov	a,_bp
      001986 24 19            [12] 5194 	add	a,#0x19
      001988 F8               [12] 5195 	mov	r0,a
      001989 86 82            [24] 5196 	mov	dpl, @r0
      00198B 08               [12] 5197 	inc	r0
      00198C 86 83            [24] 5198 	mov	dph, @r0
      00198E 08               [12] 5199 	inc	r0
      00198F 86 F0            [24] 5200 	mov	b, @r0
      001991 08               [12] 5201 	inc	r0
      001992 E6               [12] 5202 	mov	a, @r0
      001993 12 2B FE         [24] 5203 	lcall	___fslt
      001996 E5 81            [12] 5204 	mov	a,sp
      001998 24 FC            [12] 5205 	add	a,#0xfc
      00199A F5 81            [12] 5206 	mov	sp,a
      00199C D0 04            [24] 5207 	pop	ar4
      00199E D0 05            [24] 5208 	pop	ar5
      0019A0 D0 06            [24] 5209 	pop	ar6
      0019A2 D0 07            [24] 5210 	pop	ar7
      0019A4 E5 82            [12] 5211 	mov	a, dpl
      0019A6 24 FF            [12] 5212 	add	a,#0xff
      0019A8 92 00            [24] 5213 	mov	b0,c
      0019AA 40 12            [24] 5214 	jc	00128$
                           0018F5  5215 	C$fuzzy.h$1333$3_0$88 ==.
                                   5216 ;	../../fuzzy.h:1333: result = LEVEL_HI;
      0019AC E5 08            [12] 5217 	mov	a,_bp
      0019AE 24 05            [12] 5218 	add	a,#0x05
      0019B0 F8               [12] 5219 	mov	r0,a
      0019B1 E4               [12] 5220 	clr	a
      0019B2 F6               [12] 5221 	mov	@r0,a
      0019B3 08               [12] 5222 	inc	r0
      0019B4 F6               [12] 5223 	mov	@r0,a
      0019B5 08               [12] 5224 	inc	r0
      0019B6 76 80            [12] 5225 	mov	@r0,#0x80
      0019B8 08               [12] 5226 	inc	r0
      0019B9 76 3F            [12] 5227 	mov	@r0,#0x3f
      0019BB 02 1B 65         [24] 5228 	ljmp	00148$
      0019BE                       5229 00128$:
                           001907  5230 	C$fuzzy.h$1335$1_0$77 ==.
                                   5231 ;	../../fuzzy.h:1335: else if (value < parameter_2) {
      0019BE C0 07            [24] 5232 	push	ar7
      0019C0 C0 06            [24] 5233 	push	ar6
      0019C2 C0 05            [24] 5234 	push	ar5
      0019C4 C0 04            [24] 5235 	push	ar4
      0019C6 A8 08            [24] 5236 	mov	r0,_bp
      0019C8 08               [12] 5237 	inc	r0
      0019C9 E6               [12] 5238 	mov	a,@r0
      0019CA C0 E0            [24] 5239 	push	acc
      0019CC 08               [12] 5240 	inc	r0
      0019CD E6               [12] 5241 	mov	a,@r0
      0019CE C0 E0            [24] 5242 	push	acc
      0019D0 08               [12] 5243 	inc	r0
      0019D1 E6               [12] 5244 	mov	a,@r0
      0019D2 C0 E0            [24] 5245 	push	acc
      0019D4 08               [12] 5246 	inc	r0
      0019D5 E6               [12] 5247 	mov	a,@r0
      0019D6 C0 E0            [24] 5248 	push	acc
      0019D8 E5 08            [12] 5249 	mov	a,_bp
      0019DA 24 FA            [12] 5250 	add	a,#0xfa
      0019DC F8               [12] 5251 	mov	r0,a
      0019DD 86 82            [24] 5252 	mov	dpl, @r0
      0019DF 08               [12] 5253 	inc	r0
      0019E0 86 83            [24] 5254 	mov	dph, @r0
      0019E2 08               [12] 5255 	inc	r0
      0019E3 86 F0            [24] 5256 	mov	b, @r0
      0019E5 08               [12] 5257 	inc	r0
      0019E6 E6               [12] 5258 	mov	a, @r0
      0019E7 12 2B FE         [24] 5259 	lcall	___fslt
      0019EA AB 82            [24] 5260 	mov	r3, dpl
      0019EC E5 81            [12] 5261 	mov	a,sp
      0019EE 24 FC            [12] 5262 	add	a,#0xfc
      0019F0 F5 81            [12] 5263 	mov	sp,a
      0019F2 D0 04            [24] 5264 	pop	ar4
      0019F4 D0 05            [24] 5265 	pop	ar5
      0019F6 D0 06            [24] 5266 	pop	ar6
      0019F8 D0 07            [24] 5267 	pop	ar7
      0019FA EB               [12] 5268 	mov	a,r3
      0019FB 70 03            [24] 5269 	jnz	00291$
      0019FD 02 1A B4         [24] 5270 	ljmp	00125$
      001A00                       5271 00291$:
                           001949  5272 	C$fuzzy.h$1336$1_0$77 ==.
                                   5273 ;	../../fuzzy.h:1336: result = (value - parameter_1) /
      001A00 E5 08            [12] 5274 	mov	a,_bp
      001A02 24 09            [12] 5275 	add	a,#0x09
      001A04 F8               [12] 5276 	mov	r0,a
      001A05 E6               [12] 5277 	mov	a,@r0
      001A06 C0 E0            [24] 5278 	push	acc
      001A08 08               [12] 5279 	inc	r0
      001A09 E6               [12] 5280 	mov	a,@r0
      001A0A C0 E0            [24] 5281 	push	acc
      001A0C 08               [12] 5282 	inc	r0
      001A0D E6               [12] 5283 	mov	a,@r0
      001A0E C0 E0            [24] 5284 	push	acc
      001A10 08               [12] 5285 	inc	r0
      001A11 E6               [12] 5286 	mov	a,@r0
      001A12 C0 E0            [24] 5287 	push	acc
                           00195D  5288 	C$fuzzy.h$1337$1_0$77 ==.
                                   5289 ;	../../fuzzy.h:1337: (parameter_2 - parameter_1);
      001A14 E5 08            [12] 5290 	mov	a,_bp
      001A16 24 FA            [12] 5291 	add	a,#0xfa
      001A18 F8               [12] 5292 	mov	r0,a
      001A19 86 82            [24] 5293 	mov	dpl, @r0
      001A1B 08               [12] 5294 	inc	r0
      001A1C 86 83            [24] 5295 	mov	dph, @r0
      001A1E 08               [12] 5296 	inc	r0
      001A1F 86 F0            [24] 5297 	mov	b, @r0
      001A21 08               [12] 5298 	inc	r0
      001A22 E6               [12] 5299 	mov	a, @r0
      001A23 12 2A C3         [24] 5300 	lcall	___fssub
      001A26 AF 82            [24] 5301 	mov	r7, dpl
      001A28 AE 83            [24] 5302 	mov	r6, dph
      001A2A AD F0            [24] 5303 	mov	r5, b
      001A2C FC               [12] 5304 	mov	r4, a
      001A2D E5 81            [12] 5305 	mov	a,sp
      001A2F 24 FC            [12] 5306 	add	a,#0xfc
      001A31 F5 81            [12] 5307 	mov	sp,a
      001A33 C0 07            [24] 5308 	push	ar7
      001A35 C0 06            [24] 5309 	push	ar6
      001A37 C0 05            [24] 5310 	push	ar5
      001A39 C0 04            [24] 5311 	push	ar4
      001A3B E5 08            [12] 5312 	mov	a,_bp
      001A3D 24 09            [12] 5313 	add	a,#0x09
      001A3F F8               [12] 5314 	mov	r0,a
      001A40 E6               [12] 5315 	mov	a,@r0
      001A41 C0 E0            [24] 5316 	push	acc
      001A43 08               [12] 5317 	inc	r0
      001A44 E6               [12] 5318 	mov	a,@r0
      001A45 C0 E0            [24] 5319 	push	acc
      001A47 08               [12] 5320 	inc	r0
      001A48 E6               [12] 5321 	mov	a,@r0
      001A49 C0 E0            [24] 5322 	push	acc
      001A4B 08               [12] 5323 	inc	r0
      001A4C E6               [12] 5324 	mov	a,@r0
      001A4D C0 E0            [24] 5325 	push	acc
      001A4F A8 08            [24] 5326 	mov	r0,_bp
      001A51 08               [12] 5327 	inc	r0
      001A52 86 82            [24] 5328 	mov	dpl, @r0
      001A54 08               [12] 5329 	inc	r0
      001A55 86 83            [24] 5330 	mov	dph, @r0
      001A57 08               [12] 5331 	inc	r0
      001A58 86 F0            [24] 5332 	mov	b, @r0
      001A5A 08               [12] 5333 	inc	r0
      001A5B E6               [12] 5334 	mov	a, @r0
      001A5C 12 2A C3         [24] 5335 	lcall	___fssub
      001A5F C8               [12] 5336 	xch	a,r0
      001A60 E5 08            [12] 5337 	mov	a,_bp
      001A62 24 09            [12] 5338 	add	a,#0x09
      001A64 C8               [12] 5339 	xch	a,r0
      001A65 A6 82            [24] 5340 	mov	@r0, dpl
      001A67 08               [12] 5341 	inc	r0
      001A68 A6 83            [24] 5342 	mov	@r0, dph
      001A6A 08               [12] 5343 	inc	r0
      001A6B A6 F0            [24] 5344 	mov	@r0, b
      001A6D 08               [12] 5345 	inc	r0
      001A6E F6               [12] 5346 	mov	@r0,a
      001A6F E5 81            [12] 5347 	mov	a,sp
      001A71 24 FC            [12] 5348 	add	a,#0xfc
      001A73 F5 81            [12] 5349 	mov	sp,a
      001A75 D0 04            [24] 5350 	pop	ar4
      001A77 D0 05            [24] 5351 	pop	ar5
      001A79 D0 06            [24] 5352 	pop	ar6
      001A7B D0 07            [24] 5353 	pop	ar7
      001A7D E5 08            [12] 5354 	mov	a,_bp
      001A7F 24 09            [12] 5355 	add	a,#0x09
      001A81 F8               [12] 5356 	mov	r0,a
      001A82 E6               [12] 5357 	mov	a,@r0
      001A83 C0 E0            [24] 5358 	push	acc
      001A85 08               [12] 5359 	inc	r0
      001A86 E6               [12] 5360 	mov	a,@r0
      001A87 C0 E0            [24] 5361 	push	acc
      001A89 08               [12] 5362 	inc	r0
      001A8A E6               [12] 5363 	mov	a,@r0
      001A8B C0 E0            [24] 5364 	push	acc
      001A8D 08               [12] 5365 	inc	r0
      001A8E E6               [12] 5366 	mov	a,@r0
      001A8F C0 E0            [24] 5367 	push	acc
      001A91 8F 82            [24] 5368 	mov	dpl, r7
      001A93 8E 83            [24] 5369 	mov	dph, r6
      001A95 8D F0            [24] 5370 	mov	b, r5
      001A97 EC               [12] 5371 	mov	a, r4
      001A98 12 2D 67         [24] 5372 	lcall	___fsdiv
      001A9B C8               [12] 5373 	xch	a,r0
      001A9C E5 08            [12] 5374 	mov	a,_bp
      001A9E 24 05            [12] 5375 	add	a,#0x05
      001AA0 C8               [12] 5376 	xch	a,r0
      001AA1 A6 82            [24] 5377 	mov	@r0, dpl
      001AA3 08               [12] 5378 	inc	r0
      001AA4 A6 83            [24] 5379 	mov	@r0, dph
      001AA6 08               [12] 5380 	inc	r0
      001AA7 A6 F0            [24] 5381 	mov	@r0, b
      001AA9 08               [12] 5382 	inc	r0
      001AAA F6               [12] 5383 	mov	@r0,a
      001AAB E5 81            [12] 5384 	mov	a,sp
      001AAD 24 FC            [12] 5385 	add	a,#0xfc
      001AAF F5 81            [12] 5386 	mov	sp,a
      001AB1 02 1B 65         [24] 5387 	ljmp	00148$
      001AB4                       5388 00125$:
                           0019FD  5389 	C$fuzzy.h$1340$1_0$77 ==.
                                   5390 ;	../../fuzzy.h:1340: result = (parameter_4 - value) /
      001AB4 C0 07            [24] 5391 	push	ar7
      001AB6 C0 06            [24] 5392 	push	ar6
      001AB8 C0 05            [24] 5393 	push	ar5
      001ABA C0 04            [24] 5394 	push	ar4
      001ABC E5 08            [12] 5395 	mov	a,_bp
      001ABE 24 FA            [12] 5396 	add	a,#0xfa
      001AC0 F8               [12] 5397 	mov	r0,a
      001AC1 E6               [12] 5398 	mov	a,@r0
      001AC2 C0 E0            [24] 5399 	push	acc
      001AC4 08               [12] 5400 	inc	r0
      001AC5 E6               [12] 5401 	mov	a,@r0
      001AC6 C0 E0            [24] 5402 	push	acc
      001AC8 08               [12] 5403 	inc	r0
      001AC9 E6               [12] 5404 	mov	a,@r0
      001ACA C0 E0            [24] 5405 	push	acc
      001ACC 08               [12] 5406 	inc	r0
      001ACD E6               [12] 5407 	mov	a,@r0
      001ACE C0 E0            [24] 5408 	push	acc
                           001A19  5409 	C$fuzzy.h$1341$1_0$77 ==.
                                   5410 ;	../../fuzzy.h:1341: (parameter_4 - parameter_3);
      001AD0 8D 82            [24] 5411 	mov	dpl, r5
      001AD2 8E 83            [24] 5412 	mov	dph, r6
      001AD4 8F F0            [24] 5413 	mov	b, r7
      001AD6 EC               [12] 5414 	mov	a, r4
      001AD7 12 2A C3         [24] 5415 	lcall	___fssub
      001ADA C8               [12] 5416 	xch	a,r0
      001ADB E5 08            [12] 5417 	mov	a,_bp
      001ADD 24 0D            [12] 5418 	add	a,#0x0d
      001ADF C8               [12] 5419 	xch	a,r0
      001AE0 A6 82            [24] 5420 	mov	@r0, dpl
      001AE2 08               [12] 5421 	inc	r0
      001AE3 A6 83            [24] 5422 	mov	@r0, dph
      001AE5 08               [12] 5423 	inc	r0
      001AE6 A6 F0            [24] 5424 	mov	@r0, b
      001AE8 08               [12] 5425 	inc	r0
      001AE9 F6               [12] 5426 	mov	@r0,a
      001AEA E5 81            [12] 5427 	mov	a,sp
      001AEC 24 FC            [12] 5428 	add	a,#0xfc
      001AEE F5 81            [12] 5429 	mov	sp,a
      001AF0 D0 04            [24] 5430 	pop	ar4
      001AF2 D0 05            [24] 5431 	pop	ar5
      001AF4 D0 06            [24] 5432 	pop	ar6
      001AF6 D0 07            [24] 5433 	pop	ar7
      001AF8 E5 08            [12] 5434 	mov	a,_bp
      001AFA 24 19            [12] 5435 	add	a,#0x19
      001AFC F8               [12] 5436 	mov	r0,a
      001AFD E6               [12] 5437 	mov	a,@r0
      001AFE C0 E0            [24] 5438 	push	acc
      001B00 08               [12] 5439 	inc	r0
      001B01 E6               [12] 5440 	mov	a,@r0
      001B02 C0 E0            [24] 5441 	push	acc
      001B04 08               [12] 5442 	inc	r0
      001B05 E6               [12] 5443 	mov	a,@r0
      001B06 C0 E0            [24] 5444 	push	acc
      001B08 08               [12] 5445 	inc	r0
      001B09 E6               [12] 5446 	mov	a,@r0
      001B0A C0 E0            [24] 5447 	push	acc
      001B0C 8D 82            [24] 5448 	mov	dpl, r5
      001B0E 8E 83            [24] 5449 	mov	dph, r6
      001B10 8F F0            [24] 5450 	mov	b, r7
      001B12 EC               [12] 5451 	mov	a, r4
      001B13 12 2A C3         [24] 5452 	lcall	___fssub
      001B16 AC 82            [24] 5453 	mov	r4, dpl
      001B18 AD 83            [24] 5454 	mov	r5, dph
      001B1A AE F0            [24] 5455 	mov	r6, b
      001B1C FF               [12] 5456 	mov	r7, a
      001B1D E5 81            [12] 5457 	mov	a,sp
      001B1F 24 FC            [12] 5458 	add	a,#0xfc
      001B21 F5 81            [12] 5459 	mov	sp,a
      001B23 C0 04            [24] 5460 	push	ar4
      001B25 C0 05            [24] 5461 	push	ar5
      001B27 C0 06            [24] 5462 	push	ar6
      001B29 C0 07            [24] 5463 	push	ar7
                           001A74  5464 	C$fuzzy.h$1343$1_0$77 ==.
                                   5465 ;	../../fuzzy.h:1343: break;
      001B2B E5 08            [12] 5466 	mov	a,_bp
      001B2D 24 0D            [12] 5467 	add	a,#0x0d
      001B2F F8               [12] 5468 	mov	r0,a
      001B30 86 82            [24] 5469 	mov	dpl, @r0
      001B32 08               [12] 5470 	inc	r0
      001B33 86 83            [24] 5471 	mov	dph, @r0
      001B35 08               [12] 5472 	inc	r0
      001B36 86 F0            [24] 5473 	mov	b, @r0
      001B38 08               [12] 5474 	inc	r0
      001B39 E6               [12] 5475 	mov	a, @r0
      001B3A 12 2D 67         [24] 5476 	lcall	___fsdiv
      001B3D C8               [12] 5477 	xch	a,r0
      001B3E E5 08            [12] 5478 	mov	a,_bp
      001B40 24 05            [12] 5479 	add	a,#0x05
      001B42 C8               [12] 5480 	xch	a,r0
      001B43 A6 82            [24] 5481 	mov	@r0, dpl
      001B45 08               [12] 5482 	inc	r0
      001B46 A6 83            [24] 5483 	mov	@r0, dph
      001B48 08               [12] 5484 	inc	r0
      001B49 A6 F0            [24] 5485 	mov	@r0, b
      001B4B 08               [12] 5486 	inc	r0
      001B4C F6               [12] 5487 	mov	@r0,a
      001B4D E5 81            [12] 5488 	mov	a,sp
      001B4F 24 FC            [12] 5489 	add	a,#0xfc
      001B51 F5 81            [12] 5490 	mov	sp,a
                           001A9C  5491 	C$fuzzy.h$1643$2_0$79 ==.
                                   5492 ;	../../fuzzy.h:1643: case FUZZY_SHAPE_PSIGMOID:
      001B53 80 10            [24] 5493 	sjmp	00148$
      001B55                       5494 00146$:
                           001A9E  5495 	C$fuzzy.h$1644$2_0$79 ==.
                                   5496 ;	../../fuzzy.h:1644: return LEVEL_LO;
      001B55 90 00 00         [24] 5497 	mov	dptr,#0x0000
      001B58 E4               [12] 5498 	clr	a
      001B59 F5 F0            [12] 5499 	mov	b,a
                           001AA4  5500 	C$fuzzy.h$1648$2_0$79 ==.
                                   5501 ;	../../fuzzy.h:1648: default:
      001B5B 80 32            [24] 5502 	sjmp	00149$
      001B5D                       5503 00147$:
                           001AA6  5504 	C$fuzzy.h$1649$2_0$79 ==.
                                   5505 ;	../../fuzzy.h:1649: return LEVEL_LO;
      001B5D 90 00 00         [24] 5506 	mov	dptr,#0x0000
      001B60 E4               [12] 5507 	clr	a
      001B61 F5 F0            [12] 5508 	mov	b,a
                           001AAC  5509 	C$fuzzy.h$1650$1_0$77 ==.
                                   5510 ;	../../fuzzy.h:1650: }
      001B63 80 2A            [24] 5511 	sjmp	00149$
      001B65                       5512 00148$:
                           001AAE  5513 	C$fuzzy.h$1652$1_0$77 ==.
                                   5514 ;	../../fuzzy.h:1652: return fuzzy_apply_hedge(result, hedge);
      001B65 E5 08            [12] 5515 	mov	a,_bp
      001B67 24 F9            [12] 5516 	add	a,#0xf9
      001B69 F8               [12] 5517 	mov	r0,a
      001B6A E6               [12] 5518 	mov	a,@r0
      001B6B C0 E0            [24] 5519 	push	acc
      001B6D E5 08            [12] 5520 	mov	a,_bp
      001B6F 24 05            [12] 5521 	add	a,#0x05
      001B71 F8               [12] 5522 	mov	r0,a
      001B72 86 82            [24] 5523 	mov	dpl, @r0
      001B74 08               [12] 5524 	inc	r0
      001B75 86 83            [24] 5525 	mov	dph, @r0
      001B77 08               [12] 5526 	inc	r0
      001B78 86 F0            [24] 5527 	mov	b, @r0
      001B7A 08               [12] 5528 	inc	r0
      001B7B E6               [12] 5529 	mov	a, @r0
      001B7C 12 01 99         [24] 5530 	lcall	_fuzzy_apply_hedge
      001B7F AC 82            [24] 5531 	mov	r4, dpl
      001B81 AD 83            [24] 5532 	mov	r5, dph
      001B83 AE F0            [24] 5533 	mov	r6, b
      001B85 FF               [12] 5534 	mov	r7, a
      001B86 15 81            [12] 5535 	dec	sp
      001B88 8C 82            [24] 5536 	mov	dpl, r4
      001B8A 8D 83            [24] 5537 	mov	dph, r5
      001B8C 8E F0            [24] 5538 	mov	b, r6
      001B8E EF               [12] 5539 	mov	a, r7
      001B8F                       5540 00149$:
                           001AD8  5541 	C$fuzzy.h$1653$1_0$77 ==.
                                   5542 ;	../../fuzzy.h:1653: }
      001B8F 85 08 81         [24] 5543 	mov	sp,_bp
      001B92 D0 08            [24] 5544 	pop	_bp
                           001ADD  5545 	C$fuzzy.h$1653$1_0$77 ==.
                           001ADD  5546 	XG$fuzzy_function_array$0$0 ==.
      001B94 22               [24] 5547 	ret
                                   5548 ;------------------------------------------------------------
                                   5549 ;Allocation info for local variables in function 'fuzzy_rules_create'
                                   5550 ;------------------------------------------------------------
                                   5551 ;rules         Allocated to registers r5 r6 r7 
                                   5552 ;------------------------------------------------------------
                           001ADE  5553 	G$fuzzy_rules_create$0$0 ==.
                           001ADE  5554 	C$fuzzy.h$1655$1_0$92 ==.
                                   5555 ;	../../fuzzy.h:1655: void fuzzy_rules_create(
                                   5556 ;	-----------------------------------------
                                   5557 ;	 function fuzzy_rules_create
                                   5558 ;	-----------------------------------------
      001B95                       5559 _fuzzy_rules_create:
      001B95 AD 82            [24] 5560 	mov	r5, dpl
      001B97 AE 83            [24] 5561 	mov	r6, dph
      001B99 AF F0            [24] 5562 	mov	r7, b
                           001AE4  5563 	C$fuzzy.h$1659$1_0$92 ==.
                                   5564 ;	../../fuzzy.h:1659: if (rules == NULL) {
      001B9B ED               [12] 5565 	mov	a,r5
      001B9C 4E               [12] 5566 	orl	a,r6
      001B9D 70 02            [24] 5567 	jnz	00102$
                           001AE8  5568 	C$fuzzy.h$1660$2_0$93 ==.
                                   5569 ;	../../fuzzy.h:1660: return;
      001B9F 80 15            [24] 5570 	sjmp	00103$
      001BA1                       5571 00102$:
                           001AEA  5572 	C$fuzzy.h$1663$1_0$92 ==.
                                   5573 ;	../../fuzzy.h:1663: rules->count = 0;
      001BA1 74 90            [12] 5574 	mov	a,#0x90
      001BA3 2D               [12] 5575 	add	a, r5
      001BA4 FD               [12] 5576 	mov	r5,a
      001BA5 E4               [12] 5577 	clr	a
      001BA6 3E               [12] 5578 	addc	a, r6
      001BA7 FE               [12] 5579 	mov	r6,a
      001BA8 8D 82            [24] 5580 	mov	dpl,r5
      001BAA 8E 83            [24] 5581 	mov	dph,r6
      001BAC 8F F0            [24] 5582 	mov	b,r7
      001BAE E4               [12] 5583 	clr	a
      001BAF 12 2B E3         [24] 5584 	lcall	__gptrput
      001BB2 A3               [24] 5585 	inc	dptr
      001BB3 12 2B E3         [24] 5586 	lcall	__gptrput
      001BB6                       5587 00103$:
                           001AFF  5588 	C$fuzzy.h$1664$1_0$92 ==.
                                   5589 ;	../../fuzzy.h:1664: }
                           001AFF  5590 	C$fuzzy.h$1664$1_0$92 ==.
                           001AFF  5591 	XG$fuzzy_rules_create$0$0 ==.
      001BB6 22               [24] 5592 	ret
                                   5593 ;------------------------------------------------------------
                                   5594 ;Allocation info for local variables in function 'fuzzy_rules_add'
                                   5595 ;------------------------------------------------------------
                                   5596 ;name          Allocated to stack - _bp -5 +3 
                                   5597 ;value         Allocated to stack - _bp -9 +4 
                                   5598 ;output_function Allocated to stack - _bp -11 +2 
                                   5599 ;rules         Allocated to registers r2 r3 r4 
                                   5600 ;index         Allocated to registers 
                                   5601 ;sloc0         Allocated to stack - _bp +1 +2 
                                   5602 ;sloc1         Allocated to stack - _bp +3 +3 
                                   5603 ;sloc2         Allocated to stack - _bp +6 +3 
                                   5604 ;sloc3         Allocated to stack - _bp +9 +3 
                                   5605 ;------------------------------------------------------------
                           001B00  5606 	G$fuzzy_rules_add$0$0 ==.
                           001B00  5607 	C$fuzzy.h$1667$1_0$95 ==.
                                   5608 ;	../../fuzzy.h:1667: bool fuzzy_rules_add(
                                   5609 ;	-----------------------------------------
                                   5610 ;	 function fuzzy_rules_add
                                   5611 ;	-----------------------------------------
      001BB7                       5612 _fuzzy_rules_add:
      001BB7 C0 08            [24] 5613 	push	_bp
      001BB9 E5 81            [12] 5614 	mov	a,sp
      001BBB F5 08            [12] 5615 	mov	_bp,a
      001BBD 24 0B            [12] 5616 	add	a,#0x0b
      001BBF F5 81            [12] 5617 	mov	sp,a
      001BC1 AA 82            [24] 5618 	mov	r2, dpl
      001BC3 AB 83            [24] 5619 	mov	r3, dph
      001BC5 AC F0            [24] 5620 	mov	r4, b
                           001B10  5621 	C$fuzzy.h$1677$1_0$95 ==.
                                   5622 ;	../../fuzzy.h:1677: rules == NULL ||
      001BC7 EA               [12] 5623 	mov	a,r2
      001BC8 4B               [12] 5624 	orl	a,r3
      001BC9 60 0A            [24] 5625 	jz	00101$
                           001B14  5626 	C$fuzzy.h$1678$1_0$95 ==.
                                   5627 ;	../../fuzzy.h:1678: output_function == NULL
      001BCB E5 08            [12] 5628 	mov	a,_bp
      001BCD 24 F5            [12] 5629 	add	a,#0xf5
      001BCF F8               [12] 5630 	mov	r0,a
      001BD0 E6               [12] 5631 	mov	a,@r0
      001BD1 08               [12] 5632 	inc	r0
      001BD2 46               [12] 5633 	orl	a,@r0
      001BD3 70 06            [24] 5634 	jnz	00102$
      001BD5                       5635 00101$:
                           001B1E  5636 	C$fuzzy.h$1680$2_0$96 ==.
                                   5637 ;	../../fuzzy.h:1680: return false;
      001BD5 75 82 00         [24] 5638 	mov	dpl, #0x00
      001BD8 02 1D 15         [24] 5639 	ljmp	00106$
      001BDB                       5640 00102$:
                           001B24  5641 	C$fuzzy.h$1683$1_0$95 ==.
                                   5642 ;	../../fuzzy.h:1683: if (rules->count >= FUZZY_MAX_RULES) {
      001BDB E5 08            [12] 5643 	mov	a,_bp
      001BDD 24 09            [12] 5644 	add	a,#0x09
      001BDF F8               [12] 5645 	mov	r0,a
      001BE0 74 90            [12] 5646 	mov	a,#0x90
      001BE2 2A               [12] 5647 	add	a, r2
      001BE3 F6               [12] 5648 	mov	@r0,a
      001BE4 E4               [12] 5649 	clr	a
      001BE5 3B               [12] 5650 	addc	a, r3
      001BE6 08               [12] 5651 	inc	r0
      001BE7 F6               [12] 5652 	mov	@r0,a
      001BE8 08               [12] 5653 	inc	r0
      001BE9 A6 04            [24] 5654 	mov	@r0,ar4
      001BEB E5 08            [12] 5655 	mov	a,_bp
      001BED 24 09            [12] 5656 	add	a,#0x09
      001BEF F8               [12] 5657 	mov	r0,a
      001BF0 86 82            [24] 5658 	mov	dpl,@r0
      001BF2 08               [12] 5659 	inc	r0
      001BF3 86 83            [24] 5660 	mov	dph,@r0
      001BF5 08               [12] 5661 	inc	r0
      001BF6 86 F0            [24] 5662 	mov	b,@r0
      001BF8 12 2E 2A         [24] 5663 	lcall	__gptrget
      001BFB FF               [12] 5664 	mov	r7,a
      001BFC A3               [24] 5665 	inc	dptr
      001BFD 12 2E 2A         [24] 5666 	lcall	__gptrget
      001C00 FE               [12] 5667 	mov	r6,a
      001C01 C3               [12] 5668 	clr	c
      001C02 EF               [12] 5669 	mov	a,r7
      001C03 94 10            [12] 5670 	subb	a,#0x10
      001C05 EE               [12] 5671 	mov	a,r6
      001C06 94 00            [12] 5672 	subb	a,#0x00
      001C08 40 06            [24] 5673 	jc	00105$
                           001B53  5674 	C$fuzzy.h$1684$2_0$97 ==.
                                   5675 ;	../../fuzzy.h:1684: return false;
      001C0A 75 82 00         [24] 5676 	mov	dpl, #0x00
      001C0D 02 1D 15         [24] 5677 	ljmp	00106$
      001C10                       5678 00105$:
                           001B59  5679 	C$fuzzy.h$1690$1_0$95 ==.
                                   5680 ;	../../fuzzy.h:1690: rules->rules[index].name =
      001C10 C0 04            [24] 5681 	push	ar4
      001C12 C0 03            [24] 5682 	push	ar3
      001C14 C0 02            [24] 5683 	push	ar2
      001C16 C0 07            [24] 5684 	push	ar7
      001C18 C0 06            [24] 5685 	push	ar6
      001C1A 90 00 09         [24] 5686 	mov	dptr,#0x0009
      001C1D 12 2C 2E         [24] 5687 	lcall	__mulint
      001C20 A8 08            [24] 5688 	mov	r0,_bp
      001C22 08               [12] 5689 	inc	r0
      001C23 A6 82            [24] 5690 	mov	@r0, dpl
      001C25 08               [12] 5691 	inc	r0
      001C26 A6 83            [24] 5692 	mov	@r0, dph
      001C28 15 81            [12] 5693 	dec	sp
      001C2A 15 81            [12] 5694 	dec	sp
      001C2C D0 02            [24] 5695 	pop	ar2
      001C2E D0 03            [24] 5696 	pop	ar3
      001C30 D0 04            [24] 5697 	pop	ar4
      001C32 A8 08            [24] 5698 	mov	r0,_bp
      001C34 08               [12] 5699 	inc	r0
      001C35 E6               [12] 5700 	mov	a,@r0
      001C36 2A               [12] 5701 	add	a, r2
      001C37 FD               [12] 5702 	mov	r5,a
      001C38 08               [12] 5703 	inc	r0
      001C39 E6               [12] 5704 	mov	a,@r0
      001C3A 3B               [12] 5705 	addc	a, r3
      001C3B FE               [12] 5706 	mov	r6,a
      001C3C 8C 07            [24] 5707 	mov	ar7,r4
      001C3E 8D 82            [24] 5708 	mov	dpl,r5
      001C40 8E 83            [24] 5709 	mov	dph,r6
      001C42 8F F0            [24] 5710 	mov	b,r7
      001C44 E5 08            [12] 5711 	mov	a,_bp
      001C46 24 FB            [12] 5712 	add	a,#0xfb
      001C48 F8               [12] 5713 	mov	r0,a
      001C49 E6               [12] 5714 	mov	a,@r0
      001C4A 12 2B E3         [24] 5715 	lcall	__gptrput
      001C4D A3               [24] 5716 	inc	dptr
      001C4E 08               [12] 5717 	inc	r0
      001C4F E6               [12] 5718 	mov	a,@r0
      001C50 12 2B E3         [24] 5719 	lcall	__gptrput
      001C53 A3               [24] 5720 	inc	dptr
      001C54 08               [12] 5721 	inc	r0
      001C55 E6               [12] 5722 	mov	a,@r0
      001C56 12 2B E3         [24] 5723 	lcall	__gptrput
                           001BA2  5724 	C$fuzzy.h$1693$1_0$95 ==.
                                   5725 ;	../../fuzzy.h:1693: rules->rules[index].value =
      001C59 A8 08            [24] 5726 	mov	r0,_bp
      001C5B 08               [12] 5727 	inc	r0
      001C5C E5 08            [12] 5728 	mov	a,_bp
      001C5E 24 03            [12] 5729 	add	a,#0x03
      001C60 F9               [12] 5730 	mov	r1,a
      001C61 E6               [12] 5731 	mov	a,@r0
      001C62 2A               [12] 5732 	add	a, r2
      001C63 F7               [12] 5733 	mov	@r1,a
      001C64 08               [12] 5734 	inc	r0
      001C65 E6               [12] 5735 	mov	a,@r0
      001C66 3B               [12] 5736 	addc	a, r3
      001C67 09               [12] 5737 	inc	r1
      001C68 F7               [12] 5738 	mov	@r1,a
      001C69 09               [12] 5739 	inc	r1
      001C6A A7 04            [24] 5740 	mov	@r1,ar4
      001C6C E5 08            [12] 5741 	mov	a,_bp
      001C6E 24 03            [12] 5742 	add	a,#0x03
      001C70 F8               [12] 5743 	mov	r0,a
      001C71 E5 08            [12] 5744 	mov	a,_bp
      001C73 24 06            [12] 5745 	add	a,#0x06
      001C75 F9               [12] 5746 	mov	r1,a
      001C76 74 03            [12] 5747 	mov	a,#0x03
      001C78 26               [12] 5748 	add	a, @r0
      001C79 F7               [12] 5749 	mov	@r1,a
      001C7A E4               [12] 5750 	clr	a
      001C7B 08               [12] 5751 	inc	r0
      001C7C 36               [12] 5752 	addc	a, @r0
      001C7D 09               [12] 5753 	inc	r1
      001C7E F7               [12] 5754 	mov	@r1,a
      001C7F 08               [12] 5755 	inc	r0
      001C80 E6               [12] 5756 	mov	a,@r0
      001C81 09               [12] 5757 	inc	r1
      001C82 F7               [12] 5758 	mov	@r1,a
                           001BCC  5759 	C$fuzzy.h$1694$1_0$95 ==.
                                   5760 ;	../../fuzzy.h:1694: fuzzy_clamp(value);
      001C83 E5 08            [12] 5761 	mov	a,_bp
      001C85 24 F7            [12] 5762 	add	a,#0xf7
      001C87 F8               [12] 5763 	mov	r0,a
      001C88 86 82            [24] 5764 	mov	dpl, @r0
      001C8A 08               [12] 5765 	inc	r0
      001C8B 86 83            [24] 5766 	mov	dph, @r0
      001C8D 08               [12] 5767 	inc	r0
      001C8E 86 F0            [24] 5768 	mov	b, @r0
      001C90 08               [12] 5769 	inc	r0
      001C91 E6               [12] 5770 	mov	a, @r0
      001C92 12 00 EA         [24] 5771 	lcall	_fuzzy_clamp
      001C95 AD 82            [24] 5772 	mov	r5, dpl
      001C97 AE 83            [24] 5773 	mov	r6, dph
      001C99 AC F0            [24] 5774 	mov	r4, b
      001C9B FF               [12] 5775 	mov	r7, a
      001C9C E5 08            [12] 5776 	mov	a,_bp
      001C9E 24 06            [12] 5777 	add	a,#0x06
      001CA0 F8               [12] 5778 	mov	r0,a
      001CA1 86 82            [24] 5779 	mov	dpl,@r0
      001CA3 08               [12] 5780 	inc	r0
      001CA4 86 83            [24] 5781 	mov	dph,@r0
      001CA6 08               [12] 5782 	inc	r0
      001CA7 86 F0            [24] 5783 	mov	b,@r0
      001CA9 ED               [12] 5784 	mov	a,r5
      001CAA 12 2B E3         [24] 5785 	lcall	__gptrput
      001CAD A3               [24] 5786 	inc	dptr
      001CAE EE               [12] 5787 	mov	a,r6
      001CAF 12 2B E3         [24] 5788 	lcall	__gptrput
      001CB2 A3               [24] 5789 	inc	dptr
      001CB3 EC               [12] 5790 	mov	a,r4
      001CB4 12 2B E3         [24] 5791 	lcall	__gptrput
      001CB7 A3               [24] 5792 	inc	dptr
      001CB8 EF               [12] 5793 	mov	a,r7
      001CB9 12 2B E3         [24] 5794 	lcall	__gptrput
                           001C05  5795 	C$fuzzy.h$1696$1_0$95 ==.
                                   5796 ;	../../fuzzy.h:1696: rules->rules[index].output_function =
      001CBC E5 08            [12] 5797 	mov	a,_bp
      001CBE 24 03            [12] 5798 	add	a,#0x03
      001CC0 F8               [12] 5799 	mov	r0,a
      001CC1 74 07            [12] 5800 	mov	a,#0x07
      001CC3 26               [12] 5801 	add	a, @r0
      001CC4 FD               [12] 5802 	mov	r5,a
      001CC5 E4               [12] 5803 	clr	a
      001CC6 08               [12] 5804 	inc	r0
      001CC7 36               [12] 5805 	addc	a, @r0
      001CC8 FE               [12] 5806 	mov	r6,a
      001CC9 08               [12] 5807 	inc	r0
      001CCA 86 07            [24] 5808 	mov	ar7,@r0
      001CCC 8D 82            [24] 5809 	mov	dpl,r5
      001CCE 8E 83            [24] 5810 	mov	dph,r6
      001CD0 8F F0            [24] 5811 	mov	b,r7
      001CD2 E5 08            [12] 5812 	mov	a,_bp
      001CD4 24 F5            [12] 5813 	add	a,#0xf5
      001CD6 F8               [12] 5814 	mov	r0,a
      001CD7 E6               [12] 5815 	mov	a,@r0
      001CD8 12 2B E3         [24] 5816 	lcall	__gptrput
      001CDB A3               [24] 5817 	inc	dptr
      001CDC 08               [12] 5818 	inc	r0
      001CDD E6               [12] 5819 	mov	a,@r0
      001CDE 12 2B E3         [24] 5820 	lcall	__gptrput
                           001C2A  5821 	C$fuzzy.h$1699$1_0$95 ==.
                                   5822 ;	../../fuzzy.h:1699: rules->count++;
      001CE1 E5 08            [12] 5823 	mov	a,_bp
      001CE3 24 09            [12] 5824 	add	a,#0x09
      001CE5 F8               [12] 5825 	mov	r0,a
      001CE6 86 82            [24] 5826 	mov	dpl,@r0
      001CE8 08               [12] 5827 	inc	r0
      001CE9 86 83            [24] 5828 	mov	dph,@r0
      001CEB 08               [12] 5829 	inc	r0
      001CEC 86 F0            [24] 5830 	mov	b,@r0
      001CEE 12 2E 2A         [24] 5831 	lcall	__gptrget
      001CF1 FE               [12] 5832 	mov	r6,a
      001CF2 A3               [24] 5833 	inc	dptr
      001CF3 12 2E 2A         [24] 5834 	lcall	__gptrget
      001CF6 FF               [12] 5835 	mov	r7,a
      001CF7 0E               [12] 5836 	inc	r6
      001CF8 BE 00 01         [24] 5837 	cjne	r6,#0x00,00123$
      001CFB 0F               [12] 5838 	inc	r7
      001CFC                       5839 00123$:
      001CFC E5 08            [12] 5840 	mov	a,_bp
      001CFE 24 09            [12] 5841 	add	a,#0x09
      001D00 F8               [12] 5842 	mov	r0,a
      001D01 86 82            [24] 5843 	mov	dpl,@r0
      001D03 08               [12] 5844 	inc	r0
      001D04 86 83            [24] 5845 	mov	dph,@r0
      001D06 08               [12] 5846 	inc	r0
      001D07 86 F0            [24] 5847 	mov	b,@r0
      001D09 EE               [12] 5848 	mov	a,r6
      001D0A 12 2B E3         [24] 5849 	lcall	__gptrput
      001D0D A3               [24] 5850 	inc	dptr
      001D0E EF               [12] 5851 	mov	a,r7
      001D0F 12 2B E3         [24] 5852 	lcall	__gptrput
                           001C5B  5853 	C$fuzzy.h$1701$1_0$95 ==.
                                   5854 ;	../../fuzzy.h:1701: return true;
      001D12 75 82 01         [24] 5855 	mov	dpl, #0x01
      001D15                       5856 00106$:
                           001C5E  5857 	C$fuzzy.h$1702$1_0$95 ==.
                                   5858 ;	../../fuzzy.h:1702: }
      001D15 85 08 81         [24] 5859 	mov	sp,_bp
      001D18 D0 08            [24] 5860 	pop	_bp
                           001C63  5861 	C$fuzzy.h$1702$1_0$95 ==.
                           001C63  5862 	XG$fuzzy_rules_add$0$0 ==.
      001D1A 22               [24] 5863 	ret
                                   5864 ;------------------------------------------------------------
                                   5865 ;Allocation info for local variables in function 'fuzzy_implication'
                                   5866 ;------------------------------------------------------------
                                   5867 ;activation    Allocated to stack - _bp -6 +4 
                                   5868 ;membership    Allocated to stack - _bp -10 +4 
                                   5869 ;method        Allocated to registers r7 
                                   5870 ;sloc0         Allocated to stack - _bp +1 +4 
                                   5871 ;sloc1         Allocated to stack - _bp +5 +4 
                                   5872 ;------------------------------------------------------------
                           001C64  5873 	Fcontroller_8051$fuzzy_implication$0$0 ==.
                           001C64  5874 	C$fuzzy.h$1735$1_0$99 ==.
                                   5875 ;	../../fuzzy.h:1735: static float fuzzy_implication(
                                   5876 ;	-----------------------------------------
                                   5877 ;	 function fuzzy_implication
                                   5878 ;	-----------------------------------------
      001D1B                       5879 _fuzzy_implication:
      001D1B C0 08            [24] 5880 	push	_bp
      001D1D E5 81            [12] 5881 	mov	a,sp
      001D1F F5 08            [12] 5882 	mov	_bp,a
      001D21 24 08            [12] 5883 	add	a,#0x08
      001D23 F5 81            [12] 5884 	mov	sp,a
      001D25 AF 82            [24] 5885 	mov	r7, dpl
                           001C70  5886 	C$fuzzy.h$1741$1_0$99 ==.
                                   5887 ;	../../fuzzy.h:1741: activation = fuzzy_clamp(activation);
      001D27 E5 08            [12] 5888 	mov	a,_bp
      001D29 24 FA            [12] 5889 	add	a,#0xfa
      001D2B F8               [12] 5890 	mov	r0,a
      001D2C 86 82            [24] 5891 	mov	dpl, @r0
      001D2E 08               [12] 5892 	inc	r0
      001D2F 86 83            [24] 5893 	mov	dph, @r0
      001D31 08               [12] 5894 	inc	r0
      001D32 86 F0            [24] 5895 	mov	b, @r0
      001D34 08               [12] 5896 	inc	r0
      001D35 E6               [12] 5897 	mov	a, @r0
      001D36 C0 07            [24] 5898 	push	ar7
      001D38 12 00 EA         [24] 5899 	lcall	_fuzzy_clamp
      001D3B AB 82            [24] 5900 	mov	r3, dpl
      001D3D AC 83            [24] 5901 	mov	r4, dph
      001D3F AD F0            [24] 5902 	mov	r5, b
      001D41 FE               [12] 5903 	mov	r6, a
                           001C8B  5904 	C$fuzzy.h$1742$1_0$99 ==.
                                   5905 ;	../../fuzzy.h:1742: membership = fuzzy_clamp(membership);
      001D42 E5 08            [12] 5906 	mov	a,_bp
      001D44 24 F6            [12] 5907 	add	a,#0xf6
      001D46 F8               [12] 5908 	mov	r0,a
      001D47 86 82            [24] 5909 	mov	dpl, @r0
      001D49 08               [12] 5910 	inc	r0
      001D4A 86 83            [24] 5911 	mov	dph, @r0
      001D4C 08               [12] 5912 	inc	r0
      001D4D 86 F0            [24] 5913 	mov	b, @r0
      001D4F 08               [12] 5914 	inc	r0
      001D50 E6               [12] 5915 	mov	a, @r0
      001D51 C0 06            [24] 5916 	push	ar6
      001D53 C0 05            [24] 5917 	push	ar5
      001D55 C0 04            [24] 5918 	push	ar4
      001D57 C0 03            [24] 5919 	push	ar3
      001D59 12 00 EA         [24] 5920 	lcall	_fuzzy_clamp
      001D5C A8 08            [24] 5921 	mov	r0,_bp
      001D5E 08               [12] 5922 	inc	r0
      001D5F A6 82            [24] 5923 	mov	@r0, dpl
      001D61 08               [12] 5924 	inc	r0
      001D62 A6 83            [24] 5925 	mov	@r0, dph
      001D64 08               [12] 5926 	inc	r0
      001D65 A6 F0            [24] 5927 	mov	@r0, b
      001D67 08               [12] 5928 	inc	r0
      001D68 F6               [12] 5929 	mov	@r0,a
      001D69 D0 03            [24] 5930 	pop	ar3
      001D6B D0 04            [24] 5931 	pop	ar4
      001D6D D0 05            [24] 5932 	pop	ar5
      001D6F D0 06            [24] 5933 	pop	ar6
      001D71 D0 07            [24] 5934 	pop	ar7
                           001CBC  5935 	C$fuzzy.h$1744$1_0$99 ==.
                                   5936 ;	../../fuzzy.h:1744: switch (method) {
      001D73 BF 00 02         [24] 5937 	cjne	r7,#0x00,00127$
      001D76 80 08            [24] 5938 	sjmp	00101$
      001D78                       5939 00127$:
      001D78 BF 01 02         [24] 5940 	cjne	r7,#0x01,00128$
      001D7B 80 73            [24] 5941 	sjmp	00102$
      001D7D                       5942 00128$:
      001D7D 02 1E 22         [24] 5943 	ljmp	00103$
                           001CC9  5944 	C$fuzzy.h$1745$2_0$100 ==.
                                   5945 ;	../../fuzzy.h:1745: case FUZZY_IMPLICATION_MIN:
      001D80                       5946 00101$:
                           001CC9  5947 	C$fuzzy.h$1747$1_0$99 ==.
                                   5948 ;	../../fuzzy.h:1747: ? activation
      001D80 C0 06            [24] 5949 	push	ar6
      001D82 C0 05            [24] 5950 	push	ar5
      001D84 C0 04            [24] 5951 	push	ar4
      001D86 C0 03            [24] 5952 	push	ar3
      001D88 A8 08            [24] 5953 	mov	r0,_bp
      001D8A 08               [12] 5954 	inc	r0
      001D8B E6               [12] 5955 	mov	a,@r0
      001D8C C0 E0            [24] 5956 	push	acc
      001D8E 08               [12] 5957 	inc	r0
      001D8F E6               [12] 5958 	mov	a,@r0
      001D90 C0 E0            [24] 5959 	push	acc
      001D92 08               [12] 5960 	inc	r0
      001D93 E6               [12] 5961 	mov	a,@r0
      001D94 C0 E0            [24] 5962 	push	acc
      001D96 08               [12] 5963 	inc	r0
      001D97 E6               [12] 5964 	mov	a,@r0
      001D98 C0 E0            [24] 5965 	push	acc
      001D9A 8B 82            [24] 5966 	mov	dpl, r3
      001D9C 8C 83            [24] 5967 	mov	dph, r4
      001D9E 8D F0            [24] 5968 	mov	b, r5
      001DA0 EE               [12] 5969 	mov	a, r6
      001DA1 12 2B FE         [24] 5970 	lcall	___fslt
      001DA4 AF 82            [24] 5971 	mov	r7, dpl
      001DA6 E5 81            [12] 5972 	mov	a,sp
      001DA8 24 FC            [12] 5973 	add	a,#0xfc
      001DAA F5 81            [12] 5974 	mov	sp,a
      001DAC D0 03            [24] 5975 	pop	ar3
      001DAE D0 04            [24] 5976 	pop	ar4
      001DB0 D0 05            [24] 5977 	pop	ar5
      001DB2 D0 06            [24] 5978 	pop	ar6
      001DB4 EF               [12] 5979 	mov	a,r7
      001DB5 60 12            [24] 5980 	jz	00107$
      001DB7 E5 08            [12] 5981 	mov	a,_bp
      001DB9 24 05            [12] 5982 	add	a,#0x05
      001DBB F8               [12] 5983 	mov	r0,a
      001DBC A6 03            [24] 5984 	mov	@r0,ar3
      001DBE 08               [12] 5985 	inc	r0
      001DBF A6 04            [24] 5986 	mov	@r0,ar4
      001DC1 08               [12] 5987 	inc	r0
      001DC2 A6 05            [24] 5988 	mov	@r0,ar5
      001DC4 08               [12] 5989 	inc	r0
      001DC5 A6 06            [24] 5990 	mov	@r0,ar6
      001DC7 80 16            [24] 5991 	sjmp	00108$
      001DC9                       5992 00107$:
                           001D12  5993 	C$fuzzy.h$1748$2_0$100 ==.
                                   5994 ;	../../fuzzy.h:1748: : membership;
      001DC9 A8 08            [24] 5995 	mov	r0,_bp
      001DCB 08               [12] 5996 	inc	r0
      001DCC E5 08            [12] 5997 	mov	a,_bp
      001DCE 24 05            [12] 5998 	add	a,#0x05
      001DD0 F9               [12] 5999 	mov	r1,a
      001DD1 E6               [12] 6000 	mov	a,@r0
      001DD2 F7               [12] 6001 	mov	@r1,a
      001DD3 08               [12] 6002 	inc	r0
      001DD4 E6               [12] 6003 	mov	a,@r0
      001DD5 09               [12] 6004 	inc	r1
      001DD6 F7               [12] 6005 	mov	@r1,a
      001DD7 08               [12] 6006 	inc	r0
      001DD8 E6               [12] 6007 	mov	a,@r0
      001DD9 09               [12] 6008 	inc	r1
      001DDA F7               [12] 6009 	mov	@r1,a
      001DDB 08               [12] 6010 	inc	r0
      001DDC E6               [12] 6011 	mov	a,@r0
      001DDD 09               [12] 6012 	inc	r1
      001DDE F7               [12] 6013 	mov	@r1,a
      001DDF                       6014 00108$:
      001DDF E5 08            [12] 6015 	mov	a,_bp
      001DE1 24 05            [12] 6016 	add	a,#0x05
      001DE3 F8               [12] 6017 	mov	r0,a
      001DE4 86 82            [24] 6018 	mov	dpl, @r0
      001DE6 08               [12] 6019 	inc	r0
      001DE7 86 83            [24] 6020 	mov	dph, @r0
      001DE9 08               [12] 6021 	inc	r0
      001DEA 86 F0            [24] 6022 	mov	b, @r0
      001DEC 08               [12] 6023 	inc	r0
      001DED E6               [12] 6024 	mov	a, @r0
                           001D37  6025 	C$fuzzy.h$1750$2_0$100 ==.
                                   6026 ;	../../fuzzy.h:1750: case FUZZY_IMPLICATION_PRODUCT:
      001DEE 80 38            [24] 6027 	sjmp	00105$
      001DF0                       6028 00102$:
                           001D39  6029 	C$fuzzy.h$1751$1_0$99 ==.
                                   6030 ;	../../fuzzy.h:1751: return activation * membership;
      001DF0 A8 08            [24] 6031 	mov	r0,_bp
      001DF2 08               [12] 6032 	inc	r0
      001DF3 E6               [12] 6033 	mov	a,@r0
      001DF4 C0 E0            [24] 6034 	push	acc
      001DF6 08               [12] 6035 	inc	r0
      001DF7 E6               [12] 6036 	mov	a,@r0
      001DF8 C0 E0            [24] 6037 	push	acc
      001DFA 08               [12] 6038 	inc	r0
      001DFB E6               [12] 6039 	mov	a,@r0
      001DFC C0 E0            [24] 6040 	push	acc
      001DFE 08               [12] 6041 	inc	r0
      001DFF E6               [12] 6042 	mov	a,@r0
      001E00 C0 E0            [24] 6043 	push	acc
      001E02 8B 82            [24] 6044 	mov	dpl, r3
      001E04 8C 83            [24] 6045 	mov	dph, r4
      001E06 8D F0            [24] 6046 	mov	b, r5
      001E08 EE               [12] 6047 	mov	a, r6
      001E09 12 2A CE         [24] 6048 	lcall	___fsmul
      001E0C AC 82            [24] 6049 	mov	r4, dpl
      001E0E AD 83            [24] 6050 	mov	r5, dph
      001E10 AE F0            [24] 6051 	mov	r6, b
      001E12 FF               [12] 6052 	mov	r7, a
      001E13 E5 81            [12] 6053 	mov	a,sp
      001E15 24 FC            [12] 6054 	add	a,#0xfc
      001E17 F5 81            [12] 6055 	mov	sp,a
      001E19 8C 82            [24] 6056 	mov	dpl, r4
      001E1B 8D 83            [24] 6057 	mov	dph, r5
      001E1D 8E F0            [24] 6058 	mov	b, r6
      001E1F EF               [12] 6059 	mov	a, r7
                           001D69  6060 	C$fuzzy.h$1753$2_0$100 ==.
                                   6061 ;	../../fuzzy.h:1753: default:
      001E20 80 06            [24] 6062 	sjmp	00105$
      001E22                       6063 00103$:
                           001D6B  6064 	C$fuzzy.h$1754$2_0$100 ==.
                                   6065 ;	../../fuzzy.h:1754: return LEVEL_LO;
      001E22 90 00 00         [24] 6066 	mov	dptr,#0x0000
      001E25 E4               [12] 6067 	clr	a
      001E26 F5 F0            [12] 6068 	mov	b,a
                           001D71  6069 	C$fuzzy.h$1755$1_0$99 ==.
                                   6070 ;	../../fuzzy.h:1755: }
      001E28                       6071 00105$:
                           001D71  6072 	C$fuzzy.h$1756$1_0$99 ==.
                                   6073 ;	../../fuzzy.h:1756: }
      001E28 85 08 81         [24] 6074 	mov	sp,_bp
      001E2B D0 08            [24] 6075 	pop	_bp
                           001D76  6076 	C$fuzzy.h$1756$1_0$99 ==.
                           001D76  6077 	XFcontroller_8051$fuzzy_implication$0$0 ==.
      001E2D 22               [24] 6078 	ret
                                   6079 ;------------------------------------------------------------
                                   6080 ;Allocation info for local variables in function 'fuzzy_aggregation'
                                   6081 ;------------------------------------------------------------
                                   6082 ;aggregated    Allocated to stack - _bp -6 +4 
                                   6083 ;implied       Allocated to stack - _bp -10 +4 
                                   6084 ;method        Allocated to registers r7 
                                   6085 ;sloc0         Allocated to stack - _bp +1 +4 
                                   6086 ;sloc1         Allocated to stack - _bp +5 +4 
                                   6087 ;sloc2         Allocated to stack - _bp +10 +4 
                                   6088 ;------------------------------------------------------------
                           001D77  6089 	Fcontroller_8051$fuzzy_aggregation$0$0 ==.
                           001D77  6090 	C$fuzzy.h$1758$1_0$102 ==.
                                   6091 ;	../../fuzzy.h:1758: static float fuzzy_aggregation(
                                   6092 ;	-----------------------------------------
                                   6093 ;	 function fuzzy_aggregation
                                   6094 ;	-----------------------------------------
      001E2E                       6095 _fuzzy_aggregation:
      001E2E C0 08            [24] 6096 	push	_bp
      001E30 E5 81            [12] 6097 	mov	a,sp
      001E32 F5 08            [12] 6098 	mov	_bp,a
      001E34 24 08            [12] 6099 	add	a,#0x08
      001E36 F5 81            [12] 6100 	mov	sp,a
      001E38 AF 82            [24] 6101 	mov	r7, dpl
                           001D83  6102 	C$fuzzy.h$1764$1_0$102 ==.
                                   6103 ;	../../fuzzy.h:1764: aggregated = fuzzy_clamp(aggregated);
      001E3A E5 08            [12] 6104 	mov	a,_bp
      001E3C 24 FA            [12] 6105 	add	a,#0xfa
      001E3E F8               [12] 6106 	mov	r0,a
      001E3F 86 82            [24] 6107 	mov	dpl, @r0
      001E41 08               [12] 6108 	inc	r0
      001E42 86 83            [24] 6109 	mov	dph, @r0
      001E44 08               [12] 6110 	inc	r0
      001E45 86 F0            [24] 6111 	mov	b, @r0
      001E47 08               [12] 6112 	inc	r0
      001E48 E6               [12] 6113 	mov	a, @r0
      001E49 C0 07            [24] 6114 	push	ar7
      001E4B 12 00 EA         [24] 6115 	lcall	_fuzzy_clamp
      001E4E AE 82            [24] 6116 	mov	r6, dpl
      001E50 AD 83            [24] 6117 	mov	r5, dph
      001E52 AC F0            [24] 6118 	mov	r4, b
      001E54 FB               [12] 6119 	mov	r3, a
                           001D9E  6120 	C$fuzzy.h$1765$1_0$102 ==.
                                   6121 ;	../../fuzzy.h:1765: implied = fuzzy_clamp(implied);
      001E55 E5 08            [12] 6122 	mov	a,_bp
      001E57 24 F6            [12] 6123 	add	a,#0xf6
      001E59 F8               [12] 6124 	mov	r0,a
      001E5A 86 82            [24] 6125 	mov	dpl, @r0
      001E5C 08               [12] 6126 	inc	r0
      001E5D 86 83            [24] 6127 	mov	dph, @r0
      001E5F 08               [12] 6128 	inc	r0
      001E60 86 F0            [24] 6129 	mov	b, @r0
      001E62 08               [12] 6130 	inc	r0
      001E63 E6               [12] 6131 	mov	a, @r0
      001E64 C0 06            [24] 6132 	push	ar6
      001E66 C0 05            [24] 6133 	push	ar5
      001E68 C0 04            [24] 6134 	push	ar4
      001E6A C0 03            [24] 6135 	push	ar3
      001E6C 12 00 EA         [24] 6136 	lcall	_fuzzy_clamp
      001E6F A8 08            [24] 6137 	mov	r0,_bp
      001E71 08               [12] 6138 	inc	r0
      001E72 A6 82            [24] 6139 	mov	@r0, dpl
      001E74 08               [12] 6140 	inc	r0
      001E75 A6 83            [24] 6141 	mov	@r0, dph
      001E77 08               [12] 6142 	inc	r0
      001E78 A6 F0            [24] 6143 	mov	@r0, b
      001E7A 08               [12] 6144 	inc	r0
      001E7B F6               [12] 6145 	mov	@r0,a
      001E7C D0 03            [24] 6146 	pop	ar3
      001E7E D0 04            [24] 6147 	pop	ar4
      001E80 D0 05            [24] 6148 	pop	ar5
      001E82 D0 06            [24] 6149 	pop	ar6
      001E84 D0 07            [24] 6150 	pop	ar7
                           001DCF  6151 	C$fuzzy.h$1767$1_0$102 ==.
                                   6152 ;	../../fuzzy.h:1767: switch (method) {
      001E86 BF 00 02         [24] 6153 	cjne	r7,#0x00,00134$
      001E89 80 0E            [24] 6154 	sjmp	00101$
      001E8B                       6155 00134$:
      001E8B BF 01 02         [24] 6156 	cjne	r7,#0x01,00135$
      001E8E 80 76            [24] 6157 	sjmp	00102$
      001E90                       6158 00135$:
      001E90 BF 02 03         [24] 6159 	cjne	r7,#0x02,00136$
      001E93 02 1F A1         [24] 6160 	ljmp	00103$
      001E96                       6161 00136$:
      001E96 02 1F D6         [24] 6162 	ljmp	00104$
                           001DE2  6163 	C$fuzzy.h$1768$2_0$103 ==.
                                   6164 ;	../../fuzzy.h:1768: case FUZZY_AGGREGATION_MAX:
      001E99                       6165 00101$:
                           001DE2  6166 	C$fuzzy.h$1770$1_0$102 ==.
                                   6167 ;	../../fuzzy.h:1770: ? aggregated
      001E99 C0 06            [24] 6168 	push	ar6
      001E9B C0 05            [24] 6169 	push	ar5
      001E9D C0 04            [24] 6170 	push	ar4
      001E9F C0 03            [24] 6171 	push	ar3
      001EA1 C0 06            [24] 6172 	push	ar6
      001EA3 C0 05            [24] 6173 	push	ar5
      001EA5 C0 04            [24] 6174 	push	ar4
      001EA7 C0 03            [24] 6175 	push	ar3
      001EA9 A8 08            [24] 6176 	mov	r0,_bp
      001EAB 08               [12] 6177 	inc	r0
      001EAC 86 82            [24] 6178 	mov	dpl, @r0
      001EAE 08               [12] 6179 	inc	r0
      001EAF 86 83            [24] 6180 	mov	dph, @r0
      001EB1 08               [12] 6181 	inc	r0
      001EB2 86 F0            [24] 6182 	mov	b, @r0
      001EB4 08               [12] 6183 	inc	r0
      001EB5 E6               [12] 6184 	mov	a, @r0
      001EB6 12 2B FE         [24] 6185 	lcall	___fslt
      001EB9 AF 82            [24] 6186 	mov	r7, dpl
      001EBB E5 81            [12] 6187 	mov	a,sp
      001EBD 24 FC            [12] 6188 	add	a,#0xfc
      001EBF F5 81            [12] 6189 	mov	sp,a
      001EC1 D0 03            [24] 6190 	pop	ar3
      001EC3 D0 04            [24] 6191 	pop	ar4
      001EC5 D0 05            [24] 6192 	pop	ar5
      001EC7 D0 06            [24] 6193 	pop	ar6
      001EC9 EF               [12] 6194 	mov	a,r7
      001ECA 60 12            [24] 6195 	jz	00108$
      001ECC E5 08            [12] 6196 	mov	a,_bp
      001ECE 24 05            [12] 6197 	add	a,#0x05
      001ED0 F8               [12] 6198 	mov	r0,a
      001ED1 A6 06            [24] 6199 	mov	@r0,ar6
      001ED3 08               [12] 6200 	inc	r0
      001ED4 A6 05            [24] 6201 	mov	@r0,ar5
      001ED6 08               [12] 6202 	inc	r0
      001ED7 A6 04            [24] 6203 	mov	@r0,ar4
      001ED9 08               [12] 6204 	inc	r0
      001EDA A6 03            [24] 6205 	mov	@r0,ar3
      001EDC 80 16            [24] 6206 	sjmp	00109$
      001EDE                       6207 00108$:
                           001E27  6208 	C$fuzzy.h$1771$2_0$103 ==.
                                   6209 ;	../../fuzzy.h:1771: : implied;
      001EDE A8 08            [24] 6210 	mov	r0,_bp
      001EE0 08               [12] 6211 	inc	r0
      001EE1 E5 08            [12] 6212 	mov	a,_bp
      001EE3 24 05            [12] 6213 	add	a,#0x05
      001EE5 F9               [12] 6214 	mov	r1,a
      001EE6 E6               [12] 6215 	mov	a,@r0
      001EE7 F7               [12] 6216 	mov	@r1,a
      001EE8 08               [12] 6217 	inc	r0
      001EE9 E6               [12] 6218 	mov	a,@r0
      001EEA 09               [12] 6219 	inc	r1
      001EEB F7               [12] 6220 	mov	@r1,a
      001EEC 08               [12] 6221 	inc	r0
      001EED E6               [12] 6222 	mov	a,@r0
      001EEE 09               [12] 6223 	inc	r1
      001EEF F7               [12] 6224 	mov	@r1,a
      001EF0 08               [12] 6225 	inc	r0
      001EF1 E6               [12] 6226 	mov	a,@r0
      001EF2 09               [12] 6227 	inc	r1
      001EF3 F7               [12] 6228 	mov	@r1,a
      001EF4                       6229 00109$:
      001EF4 E5 08            [12] 6230 	mov	a,_bp
      001EF6 24 05            [12] 6231 	add	a,#0x05
      001EF8 F8               [12] 6232 	mov	r0,a
      001EF9 86 82            [24] 6233 	mov	dpl, @r0
      001EFB 08               [12] 6234 	inc	r0
      001EFC 86 83            [24] 6235 	mov	dph, @r0
      001EFE 08               [12] 6236 	inc	r0
      001EFF 86 F0            [24] 6237 	mov	b, @r0
      001F01 08               [12] 6238 	inc	r0
      001F02 E6               [12] 6239 	mov	a, @r0
      001F03 02 1F DC         [24] 6240 	ljmp	00106$
                           001E4F  6241 	C$fuzzy.h$1773$2_0$103 ==.
                                   6242 ;	../../fuzzy.h:1773: case FUZZY_AGGREGATION_ALGEBRAIC:
      001F06                       6243 00102$:
                           001E4F  6244 	C$fuzzy.h$1775$1_0$102 ==.
                                   6245 ;	../../fuzzy.h:1775: implied -
      001F06 C0 06            [24] 6246 	push	ar6
      001F08 C0 05            [24] 6247 	push	ar5
      001F0A C0 04            [24] 6248 	push	ar4
      001F0C C0 03            [24] 6249 	push	ar3
      001F0E A8 08            [24] 6250 	mov	r0,_bp
      001F10 08               [12] 6251 	inc	r0
      001F11 E6               [12] 6252 	mov	a,@r0
      001F12 C0 E0            [24] 6253 	push	acc
      001F14 08               [12] 6254 	inc	r0
      001F15 E6               [12] 6255 	mov	a,@r0
      001F16 C0 E0            [24] 6256 	push	acc
      001F18 08               [12] 6257 	inc	r0
      001F19 E6               [12] 6258 	mov	a,@r0
      001F1A C0 E0            [24] 6259 	push	acc
      001F1C 08               [12] 6260 	inc	r0
      001F1D E6               [12] 6261 	mov	a,@r0
      001F1E C0 E0            [24] 6262 	push	acc
                           001E69  6263 	C$fuzzy.h$1776$1_0$102 ==.
                                   6264 ;	../../fuzzy.h:1776: aggregated * implied;
      001F20 8E 82            [24] 6265 	mov	dpl, r6
      001F22 8D 83            [24] 6266 	mov	dph, r5
      001F24 8C F0            [24] 6267 	mov	b, r4
      001F26 EB               [12] 6268 	mov	a, r3
      001F27 12 2C 50         [24] 6269 	lcall	___fsadd
      001F2A C8               [12] 6270 	xch	a,r0
      001F2B E5 08            [12] 6271 	mov	a,_bp
      001F2D 24 05            [12] 6272 	add	a,#0x05
      001F2F C8               [12] 6273 	xch	a,r0
      001F30 A6 82            [24] 6274 	mov	@r0, dpl
      001F32 08               [12] 6275 	inc	r0
      001F33 A6 83            [24] 6276 	mov	@r0, dph
      001F35 08               [12] 6277 	inc	r0
      001F36 A6 F0            [24] 6278 	mov	@r0, b
      001F38 08               [12] 6279 	inc	r0
      001F39 F6               [12] 6280 	mov	@r0,a
      001F3A E5 81            [12] 6281 	mov	a,sp
      001F3C 24 FC            [12] 6282 	add	a,#0xfc
      001F3E F5 81            [12] 6283 	mov	sp,a
      001F40 D0 03            [24] 6284 	pop	ar3
      001F42 D0 04            [24] 6285 	pop	ar4
      001F44 D0 05            [24] 6286 	pop	ar5
      001F46 D0 06            [24] 6287 	pop	ar6
      001F48 A8 08            [24] 6288 	mov	r0,_bp
      001F4A 08               [12] 6289 	inc	r0
      001F4B E6               [12] 6290 	mov	a,@r0
      001F4C C0 E0            [24] 6291 	push	acc
      001F4E 08               [12] 6292 	inc	r0
      001F4F E6               [12] 6293 	mov	a,@r0
      001F50 C0 E0            [24] 6294 	push	acc
      001F52 08               [12] 6295 	inc	r0
      001F53 E6               [12] 6296 	mov	a,@r0
      001F54 C0 E0            [24] 6297 	push	acc
      001F56 08               [12] 6298 	inc	r0
      001F57 E6               [12] 6299 	mov	a,@r0
      001F58 C0 E0            [24] 6300 	push	acc
      001F5A 8E 82            [24] 6301 	mov	dpl, r6
      001F5C 8D 83            [24] 6302 	mov	dph, r5
      001F5E 8C F0            [24] 6303 	mov	b, r4
      001F60 EB               [12] 6304 	mov	a, r3
      001F61 12 2A CE         [24] 6305 	lcall	___fsmul
      001F64 AB 82            [24] 6306 	mov	r3, dpl
      001F66 AC 83            [24] 6307 	mov	r4, dph
      001F68 AE F0            [24] 6308 	mov	r6, b
      001F6A FF               [12] 6309 	mov	r7, a
      001F6B E5 81            [12] 6310 	mov	a,sp
      001F6D 24 FC            [12] 6311 	add	a,#0xfc
      001F6F F5 81            [12] 6312 	mov	sp,a
      001F71 C0 03            [24] 6313 	push	ar3
      001F73 C0 04            [24] 6314 	push	ar4
      001F75 C0 06            [24] 6315 	push	ar6
      001F77 C0 07            [24] 6316 	push	ar7
      001F79 E5 08            [12] 6317 	mov	a,_bp
      001F7B 24 05            [12] 6318 	add	a,#0x05
      001F7D F8               [12] 6319 	mov	r0,a
      001F7E 86 82            [24] 6320 	mov	dpl, @r0
      001F80 08               [12] 6321 	inc	r0
      001F81 86 83            [24] 6322 	mov	dph, @r0
      001F83 08               [12] 6323 	inc	r0
      001F84 86 F0            [24] 6324 	mov	b, @r0
      001F86 08               [12] 6325 	inc	r0
      001F87 E6               [12] 6326 	mov	a, @r0
      001F88 12 2A C3         [24] 6327 	lcall	___fssub
      001F8B AC 82            [24] 6328 	mov	r4, dpl
      001F8D AD 83            [24] 6329 	mov	r5, dph
      001F8F AE F0            [24] 6330 	mov	r6, b
      001F91 FF               [12] 6331 	mov	r7, a
      001F92 E5 81            [12] 6332 	mov	a,sp
      001F94 24 FC            [12] 6333 	add	a,#0xfc
      001F96 F5 81            [12] 6334 	mov	sp,a
      001F98 8C 82            [24] 6335 	mov	dpl, r4
      001F9A 8D 83            [24] 6336 	mov	dph, r5
      001F9C 8E F0            [24] 6337 	mov	b, r6
      001F9E EF               [12] 6338 	mov	a, r7
                           001EE8  6339 	C$fuzzy.h$1778$2_0$103 ==.
                                   6340 ;	../../fuzzy.h:1778: case FUZZY_AGGREGATION_BOUNDED:
      001F9F 80 3B            [24] 6341 	sjmp	00106$
      001FA1                       6342 00103$:
                           001EEA  6343 	C$fuzzy.h$1782$1_0$102 ==.
                                   6344 ;	../../fuzzy.h:1782: );
      001FA1 A8 08            [24] 6345 	mov	r0,_bp
      001FA3 08               [12] 6346 	inc	r0
      001FA4 E6               [12] 6347 	mov	a,@r0
      001FA5 C0 E0            [24] 6348 	push	acc
      001FA7 08               [12] 6349 	inc	r0
      001FA8 E6               [12] 6350 	mov	a,@r0
      001FA9 C0 E0            [24] 6351 	push	acc
      001FAB 08               [12] 6352 	inc	r0
      001FAC E6               [12] 6353 	mov	a,@r0
      001FAD C0 E0            [24] 6354 	push	acc
      001FAF 08               [12] 6355 	inc	r0
      001FB0 E6               [12] 6356 	mov	a,@r0
      001FB1 C0 E0            [24] 6357 	push	acc
      001FB3 8E 82            [24] 6358 	mov	dpl, r6
      001FB5 8D 83            [24] 6359 	mov	dph, r5
      001FB7 8C F0            [24] 6360 	mov	b, r4
      001FB9 EB               [12] 6361 	mov	a, r3
      001FBA 12 2C 50         [24] 6362 	lcall	___fsadd
      001FBD AC 82            [24] 6363 	mov	r4, dpl
      001FBF AD 83            [24] 6364 	mov	r5, dph
      001FC1 AE F0            [24] 6365 	mov	r6, b
      001FC3 FF               [12] 6366 	mov	r7, a
      001FC4 E5 81            [12] 6367 	mov	a,sp
      001FC6 24 FC            [12] 6368 	add	a,#0xfc
      001FC8 F5 81            [12] 6369 	mov	sp,a
      001FCA 8C 82            [24] 6370 	mov	dpl, r4
      001FCC 8D 83            [24] 6371 	mov	dph, r5
      001FCE 8E F0            [24] 6372 	mov	b, r6
      001FD0 EF               [12] 6373 	mov	a, r7
      001FD1 12 00 EA         [24] 6374 	lcall	_fuzzy_clamp
                           001F1D  6375 	C$fuzzy.h$1784$2_0$103 ==.
                                   6376 ;	../../fuzzy.h:1784: default:
      001FD4 80 06            [24] 6377 	sjmp	00106$
      001FD6                       6378 00104$:
                           001F1F  6379 	C$fuzzy.h$1785$2_0$103 ==.
                                   6380 ;	../../fuzzy.h:1785: return LEVEL_LO;
      001FD6 90 00 00         [24] 6381 	mov	dptr,#0x0000
      001FD9 E4               [12] 6382 	clr	a
      001FDA F5 F0            [12] 6383 	mov	b,a
                           001F25  6384 	C$fuzzy.h$1786$1_0$102 ==.
                                   6385 ;	../../fuzzy.h:1786: }
      001FDC                       6386 00106$:
                           001F25  6387 	C$fuzzy.h$1787$1_0$102 ==.
                                   6388 ;	../../fuzzy.h:1787: }
      001FDC 85 08 81         [24] 6389 	mov	sp,_bp
      001FDF D0 08            [24] 6390 	pop	_bp
                           001F2A  6391 	C$fuzzy.h$1787$1_0$102 ==.
                           001F2A  6392 	XFcontroller_8051$fuzzy_aggregation$0$0 ==.
      001FE1 22               [24] 6393 	ret
                                   6394 ;------------------------------------------------------------
                                   6395 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_method'
                                   6396 ;------------------------------------------------------------
                                   6397 ;lower         Allocated to stack - _bp -6 +4 
                                   6398 ;upper         Allocated to stack - _bp -10 +4 
                                   6399 ;step          Allocated to stack - _bp -14 +4 
                                   6400 ;defuzz_method Allocated to stack - _bp -15 +1 
                                   6401 ;implication_method Allocated to stack - _bp -16 +1 
                                   6402 ;aggregation_method Allocated to stack - _bp -17 +1 
                                   6403 ;rules         Allocated to stack - _bp +1 +3 
                                   6404 ;weighted_sum  Allocated to stack - _bp +16 +4 
                                   6405 ;height_sum    Allocated to stack - _bp +20 +4 
                                   6406 ;maximum_height Allocated to stack - _bp +24 +4 
                                   6407 ;maximum_position_sum Allocated to stack - _bp +28 +4 
                                   6408 ;smallest_maximum Allocated to stack - _bp +32 +4 
                                   6409 ;largest_maximum Allocated to stack - _bp +36 +4 
                                   6410 ;value         Allocated to stack - _bp +40 +4 
                                   6411 ;aggregated_height Allocated to stack - _bp +44 +4 
                                   6412 ;output_membership Allocated to stack - _bp +48 +4 
                                   6413 ;implied_height Allocated to registers r4 r5 r6 r7 
                                   6414 ;maximum_count Allocated to stack - _bp +52 +2 
                                   6415 ;index         Allocated to stack - _bp +54 +2 
                                   6416 ;maximum_found Allocated to stack - _bp +56 +1 
                                   6417 ;sloc0         Allocated to stack - _bp +4 +3 
                                   6418 ;sloc1         Allocated to stack - _bp +7 +4 
                                   6419 ;sloc2         Allocated to stack - _bp +11 +2 
                                   6420 ;sloc3         Allocated to stack - _bp +13 +3 
                                   6421 ;------------------------------------------------------------
                           001F2B  6422 	G$fuzzy_rules_defuzzify_method$0$0 ==.
                           001F2B  6423 	C$fuzzy.h$1804$1_0$105 ==.
                                   6424 ;	../../fuzzy.h:1804: float fuzzy_rules_defuzzify_method(
                                   6425 ;	-----------------------------------------
                                   6426 ;	 function fuzzy_rules_defuzzify_method
                                   6427 ;	-----------------------------------------
      001FE2                       6428 _fuzzy_rules_defuzzify_method:
      001FE2 C0 08            [24] 6429 	push	_bp
      001FE4 85 81 08         [24] 6430 	mov	_bp,sp
      001FE7 C0 82            [24] 6431 	push	dpl
      001FE9 C0 83            [24] 6432 	push	dph
      001FEB C0 F0            [24] 6433 	push	b
      001FED E5 81            [12] 6434 	mov	a,sp
      001FEF 24 35            [12] 6435 	add	a,#0x35
      001FF1 F5 81            [12] 6436 	mov	sp,a
                           001F3C  6437 	C$fuzzy.h$1814$2_0$105 ==.
                                   6438 ;	../../fuzzy.h:1814: float weighted_sum = 0.0f;
      001FF3 E5 08            [12] 6439 	mov	a,_bp
      001FF5 24 10            [12] 6440 	add	a,#0x10
      001FF7 F8               [12] 6441 	mov	r0,a
      001FF8 E4               [12] 6442 	clr	a
      001FF9 F6               [12] 6443 	mov	@r0,a
      001FFA 08               [12] 6444 	inc	r0
      001FFB F6               [12] 6445 	mov	@r0,a
      001FFC 08               [12] 6446 	inc	r0
      001FFD F6               [12] 6447 	mov	@r0,a
      001FFE 08               [12] 6448 	inc	r0
      001FFF F6               [12] 6449 	mov	@r0,a
                           001F49  6450 	C$fuzzy.h$1815$2_0$105 ==.
                                   6451 ;	../../fuzzy.h:1815: float height_sum = 0.0f;
      002000 E5 08            [12] 6452 	mov	a,_bp
      002002 24 14            [12] 6453 	add	a,#0x14
      002004 F8               [12] 6454 	mov	r0,a
      002005 E4               [12] 6455 	clr	a
      002006 F6               [12] 6456 	mov	@r0,a
      002007 08               [12] 6457 	inc	r0
      002008 F6               [12] 6458 	mov	@r0,a
      002009 08               [12] 6459 	inc	r0
      00200A F6               [12] 6460 	mov	@r0,a
      00200B 08               [12] 6461 	inc	r0
      00200C F6               [12] 6462 	mov	@r0,a
                           001F56  6463 	C$fuzzy.h$1816$2_0$105 ==.
                                   6464 ;	../../fuzzy.h:1816: float maximum_height = LEVEL_LO;
      00200D E5 08            [12] 6465 	mov	a,_bp
      00200F 24 18            [12] 6466 	add	a,#0x18
      002011 F8               [12] 6467 	mov	r0,a
      002012 E4               [12] 6468 	clr	a
      002013 F6               [12] 6469 	mov	@r0,a
      002014 08               [12] 6470 	inc	r0
      002015 F6               [12] 6471 	mov	@r0,a
      002016 08               [12] 6472 	inc	r0
      002017 F6               [12] 6473 	mov	@r0,a
      002018 08               [12] 6474 	inc	r0
      002019 F6               [12] 6475 	mov	@r0,a
                           001F63  6476 	C$fuzzy.h$1817$2_0$105 ==.
                                   6477 ;	../../fuzzy.h:1817: float maximum_position_sum = 0.0f;
      00201A E5 08            [12] 6478 	mov	a,_bp
      00201C 24 1C            [12] 6479 	add	a,#0x1c
      00201E F8               [12] 6480 	mov	r0,a
      00201F E4               [12] 6481 	clr	a
      002020 F6               [12] 6482 	mov	@r0,a
      002021 08               [12] 6483 	inc	r0
      002022 F6               [12] 6484 	mov	@r0,a
      002023 08               [12] 6485 	inc	r0
      002024 F6               [12] 6486 	mov	@r0,a
      002025 08               [12] 6487 	inc	r0
      002026 F6               [12] 6488 	mov	@r0,a
                           001F70  6489 	C$fuzzy.h$1818$2_0$105 ==.
                                   6490 ;	../../fuzzy.h:1818: float smallest_maximum = lower;
      002027 E5 08            [12] 6491 	mov	a,_bp
      002029 24 FA            [12] 6492 	add	a,#0xfa
      00202B F8               [12] 6493 	mov	r0,a
      00202C E5 08            [12] 6494 	mov	a,_bp
      00202E 24 20            [12] 6495 	add	a,#0x20
      002030 F9               [12] 6496 	mov	r1,a
      002031 E6               [12] 6497 	mov	a,@r0
      002032 F7               [12] 6498 	mov	@r1,a
      002033 08               [12] 6499 	inc	r0
      002034 E6               [12] 6500 	mov	a,@r0
      002035 09               [12] 6501 	inc	r1
      002036 F7               [12] 6502 	mov	@r1,a
      002037 08               [12] 6503 	inc	r0
      002038 E6               [12] 6504 	mov	a,@r0
      002039 09               [12] 6505 	inc	r1
      00203A F7               [12] 6506 	mov	@r1,a
      00203B 08               [12] 6507 	inc	r0
      00203C E6               [12] 6508 	mov	a,@r0
      00203D 09               [12] 6509 	inc	r1
      00203E F7               [12] 6510 	mov	@r1,a
                           001F88  6511 	C$fuzzy.h$1819$2_0$105 ==.
                                   6512 ;	../../fuzzy.h:1819: float largest_maximum = lower;
      00203F E5 08            [12] 6513 	mov	a,_bp
      002041 24 20            [12] 6514 	add	a,#0x20
      002043 F8               [12] 6515 	mov	r0,a
      002044 E5 08            [12] 6516 	mov	a,_bp
      002046 24 24            [12] 6517 	add	a,#0x24
      002048 F9               [12] 6518 	mov	r1,a
      002049 E6               [12] 6519 	mov	a,@r0
      00204A F7               [12] 6520 	mov	@r1,a
      00204B 08               [12] 6521 	inc	r0
      00204C E6               [12] 6522 	mov	a,@r0
      00204D 09               [12] 6523 	inc	r1
      00204E F7               [12] 6524 	mov	@r1,a
      00204F 08               [12] 6525 	inc	r0
      002050 E6               [12] 6526 	mov	a,@r0
      002051 09               [12] 6527 	inc	r1
      002052 F7               [12] 6528 	mov	@r1,a
      002053 08               [12] 6529 	inc	r0
      002054 E6               [12] 6530 	mov	a,@r0
      002055 09               [12] 6531 	inc	r1
      002056 F7               [12] 6532 	mov	@r1,a
                           001FA0  6533 	C$fuzzy.h$1824$2_0$105 ==.
                                   6534 ;	../../fuzzy.h:1824: size_t maximum_count = 0u;
      002057 E5 08            [12] 6535 	mov	a,_bp
      002059 24 34            [12] 6536 	add	a,#0x34
      00205B F8               [12] 6537 	mov	r0,a
      00205C E4               [12] 6538 	clr	a
      00205D F6               [12] 6539 	mov	@r0,a
      00205E 08               [12] 6540 	inc	r0
      00205F F6               [12] 6541 	mov	@r0,a
                           001FA9  6542 	C$fuzzy.h$1826$2_0$105 ==.
                                   6543 ;	../../fuzzy.h:1826: bool maximum_found = false;
      002060 E5 08            [12] 6544 	mov	a,_bp
      002062 24 38            [12] 6545 	add	a,#0x38
      002064 F8               [12] 6546 	mov	r0,a
      002065 76 00            [12] 6547 	mov	@r0,#0x00
                           001FB0  6548 	C$fuzzy.h$1829$1_0$105 ==.
                                   6549 ;	../../fuzzy.h:1829: rules == NULL ||
      002067 A8 08            [24] 6550 	mov	r0,_bp
      002069 08               [12] 6551 	inc	r0
      00206A E6               [12] 6552 	mov	a,@r0
      00206B 08               [12] 6553 	inc	r0
      00206C 46               [12] 6554 	orl	a,@r0
      00206D 70 03            [24] 6555 	jnz	00217$
      00206F 02 20 FB         [24] 6556 	ljmp	00101$
      002072                       6557 00217$:
                           001FBB  6558 	C$fuzzy.h$1830$1_0$105 ==.
                                   6559 ;	../../fuzzy.h:1830: rules->count == 0u ||
      002072 A8 08            [24] 6560 	mov	r0,_bp
      002074 08               [12] 6561 	inc	r0
      002075 E5 08            [12] 6562 	mov	a,_bp
      002077 24 04            [12] 6563 	add	a,#0x04
      002079 F9               [12] 6564 	mov	r1,a
      00207A 74 90            [12] 6565 	mov	a,#0x90
      00207C 26               [12] 6566 	add	a, @r0
      00207D F7               [12] 6567 	mov	@r1,a
      00207E E4               [12] 6568 	clr	a
      00207F 08               [12] 6569 	inc	r0
      002080 36               [12] 6570 	addc	a, @r0
      002081 09               [12] 6571 	inc	r1
      002082 F7               [12] 6572 	mov	@r1,a
      002083 08               [12] 6573 	inc	r0
      002084 E6               [12] 6574 	mov	a,@r0
      002085 09               [12] 6575 	inc	r1
      002086 F7               [12] 6576 	mov	@r1,a
      002087 E5 08            [12] 6577 	mov	a,_bp
      002089 24 04            [12] 6578 	add	a,#0x04
      00208B F8               [12] 6579 	mov	r0,a
      00208C 86 82            [24] 6580 	mov	dpl,@r0
      00208E 08               [12] 6581 	inc	r0
      00208F 86 83            [24] 6582 	mov	dph,@r0
      002091 08               [12] 6583 	inc	r0
      002092 86 F0            [24] 6584 	mov	b,@r0
      002094 12 2E 2A         [24] 6585 	lcall	__gptrget
      002097 FE               [12] 6586 	mov	r6,a
      002098 A3               [24] 6587 	inc	dptr
      002099 12 2E 2A         [24] 6588 	lcall	__gptrget
      00209C 4E               [12] 6589 	orl	a,r6
      00209D 60 5C            [24] 6590 	jz	00101$
                           001FE8  6591 	C$fuzzy.h$1831$1_0$105 ==.
                                   6592 ;	../../fuzzy.h:1831: lower > upper ||
      00209F E5 08            [12] 6593 	mov	a,_bp
      0020A1 24 20            [12] 6594 	add	a,#0x20
      0020A3 F8               [12] 6595 	mov	r0,a
      0020A4 E6               [12] 6596 	mov	a,@r0
      0020A5 C0 E0            [24] 6597 	push	acc
      0020A7 08               [12] 6598 	inc	r0
      0020A8 E6               [12] 6599 	mov	a,@r0
      0020A9 C0 E0            [24] 6600 	push	acc
      0020AB 08               [12] 6601 	inc	r0
      0020AC E6               [12] 6602 	mov	a,@r0
      0020AD C0 E0            [24] 6603 	push	acc
      0020AF 08               [12] 6604 	inc	r0
      0020B0 E6               [12] 6605 	mov	a,@r0
      0020B1 C0 E0            [24] 6606 	push	acc
      0020B3 E5 08            [12] 6607 	mov	a,_bp
      0020B5 24 F6            [12] 6608 	add	a,#0xf6
      0020B7 F8               [12] 6609 	mov	r0,a
      0020B8 86 82            [24] 6610 	mov	dpl, @r0
      0020BA 08               [12] 6611 	inc	r0
      0020BB 86 83            [24] 6612 	mov	dph, @r0
      0020BD 08               [12] 6613 	inc	r0
      0020BE 86 F0            [24] 6614 	mov	b, @r0
      0020C0 08               [12] 6615 	inc	r0
      0020C1 E6               [12] 6616 	mov	a, @r0
      0020C2 12 2B FE         [24] 6617 	lcall	___fslt
      0020C5 AF 82            [24] 6618 	mov	r7, dpl
      0020C7 E5 81            [12] 6619 	mov	a,sp
      0020C9 24 FC            [12] 6620 	add	a,#0xfc
      0020CB F5 81            [12] 6621 	mov	sp,a
      0020CD EF               [12] 6622 	mov	a,r7
      0020CE 70 2B            [24] 6623 	jnz	00101$
                           002019  6624 	C$fuzzy.h$1833$1_0$105 ==.
                                   6625 ;	../../fuzzy.h:1833: ) {
      0020D0 E5 08            [12] 6626 	mov	a,_bp
      0020D2 24 F2            [12] 6627 	add	a,#0xf2
      0020D4 F8               [12] 6628 	mov	r0,a
      0020D5 E6               [12] 6629 	mov	a,@r0
      0020D6 C0 E0            [24] 6630 	push	acc
      0020D8 08               [12] 6631 	inc	r0
      0020D9 E6               [12] 6632 	mov	a,@r0
      0020DA C0 E0            [24] 6633 	push	acc
      0020DC 08               [12] 6634 	inc	r0
      0020DD E6               [12] 6635 	mov	a,@r0
      0020DE C0 E0            [24] 6636 	push	acc
      0020E0 08               [12] 6637 	inc	r0
      0020E1 E6               [12] 6638 	mov	a,@r0
      0020E2 C0 E0            [24] 6639 	push	acc
      0020E4 90 00 00         [24] 6640 	mov	dptr,#0x0000
      0020E7 E4               [12] 6641 	clr	a
      0020E8 F5 F0            [12] 6642 	mov	b,a
      0020EA 12 2B FE         [24] 6643 	lcall	___fslt
      0020ED E5 81            [12] 6644 	mov	a,sp
      0020EF 24 FC            [12] 6645 	add	a,#0xfc
      0020F1 F5 81            [12] 6646 	mov	sp,a
      0020F3 E5 82            [12] 6647 	mov	a, dpl
      0020F5 24 FF            [12] 6648 	add	a,#0xff
      0020F7 92 00            [24] 6649 	mov	b0,c
      0020F9 40 09            [24] 6650 	jc	00102$
      0020FB                       6651 00101$:
                           002044  6652 	C$fuzzy.h$1834$2_0$106 ==.
                                   6653 ;	../../fuzzy.h:1834: return 0.0f;
      0020FB 90 00 00         [24] 6654 	mov	dptr,#0x0000
      0020FE E4               [12] 6655 	clr	a
      0020FF F5 F0            [12] 6656 	mov	b,a
      002101 02 26 2F         [24] 6657 	ljmp	00130$
      002104                       6658 00102$:
                           00204D  6659 	C$fuzzy.h$1838$2_0$107 ==.
                                   6660 ;	../../fuzzy.h:1838: value = lower;
      002104 E5 08            [12] 6661 	mov	a,_bp
      002106 24 20            [12] 6662 	add	a,#0x20
      002108 F8               [12] 6663 	mov	r0,a
      002109 E5 08            [12] 6664 	mov	a,_bp
      00210B 24 28            [12] 6665 	add	a,#0x28
      00210D F9               [12] 6666 	mov	r1,a
      00210E E6               [12] 6667 	mov	a,@r0
      00210F F7               [12] 6668 	mov	@r1,a
      002110 08               [12] 6669 	inc	r0
      002111 E6               [12] 6670 	mov	a,@r0
      002112 09               [12] 6671 	inc	r1
      002113 F7               [12] 6672 	mov	@r1,a
      002114 08               [12] 6673 	inc	r0
      002115 E6               [12] 6674 	mov	a,@r0
      002116 09               [12] 6675 	inc	r1
      002117 F7               [12] 6676 	mov	@r1,a
      002118 08               [12] 6677 	inc	r0
      002119 E6               [12] 6678 	mov	a,@r0
      00211A 09               [12] 6679 	inc	r1
      00211B F7               [12] 6680 	mov	@r1,a
      00211C A8 08            [24] 6681 	mov	r0,_bp
      00211E 08               [12] 6682 	inc	r0
      00211F E5 08            [12] 6683 	mov	a,_bp
      002121 24 0D            [12] 6684 	add	a,#0x0d
      002123 F9               [12] 6685 	mov	r1,a
      002124 E6               [12] 6686 	mov	a,@r0
      002125 F7               [12] 6687 	mov	@r1,a
      002126 08               [12] 6688 	inc	r0
      002127 E6               [12] 6689 	mov	a,@r0
      002128 09               [12] 6690 	inc	r1
      002129 F7               [12] 6691 	mov	@r1,a
      00212A 08               [12] 6692 	inc	r0
      00212B E6               [12] 6693 	mov	a,@r0
      00212C 09               [12] 6694 	inc	r1
      00212D F7               [12] 6695 	mov	@r1,a
      00212E                       6696 00128$:
                           002077  6697 	C$fuzzy.h$1839$1_0$105 ==.
                                   6698 ;	../../fuzzy.h:1839: value <= upper;
      00212E E5 08            [12] 6699 	mov	a,_bp
      002130 24 28            [12] 6700 	add	a,#0x28
      002132 F8               [12] 6701 	mov	r0,a
      002133 E6               [12] 6702 	mov	a,@r0
      002134 C0 E0            [24] 6703 	push	acc
      002136 08               [12] 6704 	inc	r0
      002137 E6               [12] 6705 	mov	a,@r0
      002138 C0 E0            [24] 6706 	push	acc
      00213A 08               [12] 6707 	inc	r0
      00213B E6               [12] 6708 	mov	a,@r0
      00213C C0 E0            [24] 6709 	push	acc
      00213E 08               [12] 6710 	inc	r0
      00213F E6               [12] 6711 	mov	a,@r0
      002140 C0 E0            [24] 6712 	push	acc
      002142 E5 08            [12] 6713 	mov	a,_bp
      002144 24 F6            [12] 6714 	add	a,#0xf6
      002146 F8               [12] 6715 	mov	r0,a
      002147 86 82            [24] 6716 	mov	dpl, @r0
      002149 08               [12] 6717 	inc	r0
      00214A 86 83            [24] 6718 	mov	dph, @r0
      00214C 08               [12] 6719 	inc	r0
      00214D 86 F0            [24] 6720 	mov	b, @r0
      00214F 08               [12] 6721 	inc	r0
      002150 E6               [12] 6722 	mov	a, @r0
      002151 12 2B FE         [24] 6723 	lcall	___fslt
      002154 E5 81            [12] 6724 	mov	a,sp
      002156 24 FC            [12] 6725 	add	a,#0xfc
      002158 F5 81            [12] 6726 	mov	sp,a
      00215A E5 82            [12] 6727 	mov	a, dpl
      00215C 24 FF            [12] 6728 	add	a,#0xff
      00215E 92 00            [24] 6729 	mov	b0,c
      002160 50 03            [24] 6730 	jnc	00221$
      002162 02 24 FB         [24] 6731 	ljmp	00113$
      002165                       6732 00221$:
                           0020AE  6733 	C$fuzzy.h$1842$3_0$108 ==.
                                   6734 ;	../../fuzzy.h:1842: aggregated_height = LEVEL_LO;
      002165 E5 08            [12] 6735 	mov	a,_bp
      002167 24 07            [12] 6736 	add	a,#0x07
      002169 F8               [12] 6737 	mov	r0,a
      00216A E4               [12] 6738 	clr	a
      00216B F6               [12] 6739 	mov	@r0,a
      00216C 08               [12] 6740 	inc	r0
      00216D F6               [12] 6741 	mov	@r0,a
      00216E 08               [12] 6742 	inc	r0
      00216F F6               [12] 6743 	mov	@r0,a
      002170 08               [12] 6744 	inc	r0
      002171 F6               [12] 6745 	mov	@r0,a
                           0020BB  6746 	C$fuzzy.h$1845$1_0$105 ==.
                                   6747 ;	../../fuzzy.h:1845: index = 0u;
      002172 E5 08            [12] 6748 	mov	a,_bp
      002174 24 36            [12] 6749 	add	a,#0x36
      002176 F8               [12] 6750 	mov	r0,a
      002177 E4               [12] 6751 	clr	a
      002178 F6               [12] 6752 	mov	@r0,a
      002179 08               [12] 6753 	inc	r0
      00217A F6               [12] 6754 	mov	@r0,a
      00217B E5 08            [12] 6755 	mov	a,_bp
      00217D 24 0B            [12] 6756 	add	a,#0x0b
      00217F F8               [12] 6757 	mov	r0,a
      002180 E4               [12] 6758 	clr	a
      002181 F6               [12] 6759 	mov	@r0,a
      002182 08               [12] 6760 	inc	r0
      002183 F6               [12] 6761 	mov	@r0,a
      002184                       6762 00125$:
                           0020CD  6763 	C$fuzzy.h$1846$1_0$105 ==.
                                   6764 ;	../../fuzzy.h:1846: index < rules->count;
      002184 E5 08            [12] 6765 	mov	a,_bp
      002186 24 04            [12] 6766 	add	a,#0x04
      002188 F8               [12] 6767 	mov	r0,a
      002189 86 82            [24] 6768 	mov	dpl,@r0
      00218B 08               [12] 6769 	inc	r0
      00218C 86 83            [24] 6770 	mov	dph,@r0
      00218E 08               [12] 6771 	inc	r0
      00218F 86 F0            [24] 6772 	mov	b,@r0
      002191 12 2E 2A         [24] 6773 	lcall	__gptrget
      002194 FC               [12] 6774 	mov	r4,a
      002195 A3               [24] 6775 	inc	dptr
      002196 12 2E 2A         [24] 6776 	lcall	__gptrget
      002199 FF               [12] 6777 	mov	r7,a
      00219A E5 08            [12] 6778 	mov	a,_bp
      00219C 24 36            [12] 6779 	add	a,#0x36
      00219E F8               [12] 6780 	mov	r0,a
      00219F C3               [12] 6781 	clr	c
      0021A0 E6               [12] 6782 	mov	a,@r0
      0021A1 9C               [12] 6783 	subb	a,r4
      0021A2 08               [12] 6784 	inc	r0
      0021A3 E6               [12] 6785 	mov	a,@r0
      0021A4 9F               [12] 6786 	subb	a,r7
      0021A5 40 03            [24] 6787 	jc	00222$
      0021A7 02 22 BE         [24] 6788 	ljmp	00106$
      0021AA                       6789 00222$:
                           0020F3  6790 	C$fuzzy.h$1850$5_0$110 ==.
                                   6791 ;	../../fuzzy.h:1850: rules->rules[index].output_function(value)
      0021AA E5 08            [12] 6792 	mov	a,_bp
      0021AC 24 0D            [12] 6793 	add	a,#0x0d
      0021AE F8               [12] 6794 	mov	r0,a
      0021AF E5 08            [12] 6795 	mov	a,_bp
      0021B1 24 0B            [12] 6796 	add	a,#0x0b
      0021B3 F9               [12] 6797 	mov	r1,a
      0021B4 E7               [12] 6798 	mov	a,@r1
      0021B5 26               [12] 6799 	add	a, @r0
      0021B6 FC               [12] 6800 	mov	r4,a
      0021B7 09               [12] 6801 	inc	r1
      0021B8 E7               [12] 6802 	mov	a,@r1
      0021B9 08               [12] 6803 	inc	r0
      0021BA 36               [12] 6804 	addc	a, @r0
      0021BB FD               [12] 6805 	mov	r5,a
      0021BC 08               [12] 6806 	inc	r0
      0021BD 86 06            [24] 6807 	mov	ar6,@r0
      0021BF 74 07            [12] 6808 	mov	a,#0x07
      0021C1 2C               [12] 6809 	add	a, r4
      0021C2 FC               [12] 6810 	mov	r4,a
      0021C3 E4               [12] 6811 	clr	a
      0021C4 3D               [12] 6812 	addc	a, r5
      0021C5 FD               [12] 6813 	mov	r5,a
      0021C6 8C 82            [24] 6814 	mov	dpl,r4
      0021C8 8D 83            [24] 6815 	mov	dph,r5
      0021CA 8E F0            [24] 6816 	mov	b,r6
      0021CC 12 2E 2A         [24] 6817 	lcall	__gptrget
      0021CF FC               [12] 6818 	mov	r4,a
      0021D0 A3               [24] 6819 	inc	dptr
      0021D1 12 2E 2A         [24] 6820 	lcall	__gptrget
      0021D4 FD               [12] 6821 	mov	r5,a
      0021D5 12 21 DA         [24] 6822 	lcall	00223$
      0021D8 80 14            [24] 6823 	sjmp	00224$
      0021DA                       6824 00223$:
      0021DA C0 04            [24] 6825 	push	ar4
      0021DC C0 05            [24] 6826 	push	ar5
      0021DE E5 08            [12] 6827 	mov	a,_bp
      0021E0 24 28            [12] 6828 	add	a,#0x28
      0021E2 F8               [12] 6829 	mov	r0,a
      0021E3 86 82            [24] 6830 	mov	dpl, @r0
      0021E5 08               [12] 6831 	inc	r0
      0021E6 86 83            [24] 6832 	mov	dph, @r0
      0021E8 08               [12] 6833 	inc	r0
      0021E9 86 F0            [24] 6834 	mov	b, @r0
      0021EB 08               [12] 6835 	inc	r0
      0021EC E6               [12] 6836 	mov	a, @r0
      0021ED 22               [24] 6837 	ret
      0021EE                       6838 00224$:
      0021EE 12 00 EA         [24] 6839 	lcall	_fuzzy_clamp
      0021F1 C8               [12] 6840 	xch	a,r0
      0021F2 E5 08            [12] 6841 	mov	a,_bp
      0021F4 24 30            [12] 6842 	add	a,#0x30
      0021F6 C8               [12] 6843 	xch	a,r0
      0021F7 A6 82            [24] 6844 	mov	@r0, dpl
      0021F9 08               [12] 6845 	inc	r0
      0021FA A6 83            [24] 6846 	mov	@r0, dph
      0021FC 08               [12] 6847 	inc	r0
      0021FD A6 F0            [24] 6848 	mov	@r0, b
      0021FF 08               [12] 6849 	inc	r0
      002200 F6               [12] 6850 	mov	@r0,a
                           00214A  6851 	C$fuzzy.h$1855$5_0$110 ==.
                                   6852 ;	../../fuzzy.h:1855: rules->rules[index].value,
      002201 A8 08            [24] 6853 	mov	r0,_bp
      002203 08               [12] 6854 	inc	r0
      002204 E5 08            [12] 6855 	mov	a,_bp
      002206 24 0B            [12] 6856 	add	a,#0x0b
      002208 F9               [12] 6857 	mov	r1,a
      002209 E7               [12] 6858 	mov	a,@r1
      00220A 26               [12] 6859 	add	a, @r0
      00220B FA               [12] 6860 	mov	r2,a
      00220C 09               [12] 6861 	inc	r1
      00220D E7               [12] 6862 	mov	a,@r1
      00220E 08               [12] 6863 	inc	r0
      00220F 36               [12] 6864 	addc	a, @r0
      002210 FB               [12] 6865 	mov	r3,a
      002211 08               [12] 6866 	inc	r0
      002212 86 07            [24] 6867 	mov	ar7,@r0
      002214 74 03            [12] 6868 	mov	a,#0x03
      002216 2A               [12] 6869 	add	a, r2
      002217 FA               [12] 6870 	mov	r2,a
      002218 E4               [12] 6871 	clr	a
      002219 3B               [12] 6872 	addc	a, r3
      00221A FB               [12] 6873 	mov	r3,a
      00221B 8A 82            [24] 6874 	mov	dpl,r2
      00221D 8B 83            [24] 6875 	mov	dph,r3
      00221F 8F F0            [24] 6876 	mov	b,r7
      002221 12 2E 2A         [24] 6877 	lcall	__gptrget
      002224 FA               [12] 6878 	mov	r2,a
      002225 A3               [24] 6879 	inc	dptr
      002226 12 2E 2A         [24] 6880 	lcall	__gptrget
      002229 FB               [12] 6881 	mov	r3,a
      00222A A3               [24] 6882 	inc	dptr
      00222B 12 2E 2A         [24] 6883 	lcall	__gptrget
      00222E FF               [12] 6884 	mov	r7,a
      00222F A3               [24] 6885 	inc	dptr
      002230 12 2E 2A         [24] 6886 	lcall	__gptrget
      002233 FE               [12] 6887 	mov	r6,a
                           00217D  6888 	C$fuzzy.h$1854$5_0$110 ==.
                                   6889 ;	../../fuzzy.h:1854: implication_method,
      002234 E5 08            [12] 6890 	mov	a,_bp
      002236 24 30            [12] 6891 	add	a,#0x30
      002238 F8               [12] 6892 	mov	r0,a
      002239 E6               [12] 6893 	mov	a,@r0
      00223A C0 E0            [24] 6894 	push	acc
      00223C 08               [12] 6895 	inc	r0
      00223D E6               [12] 6896 	mov	a,@r0
      00223E C0 E0            [24] 6897 	push	acc
      002240 08               [12] 6898 	inc	r0
      002241 E6               [12] 6899 	mov	a,@r0
      002242 C0 E0            [24] 6900 	push	acc
      002244 08               [12] 6901 	inc	r0
      002245 E6               [12] 6902 	mov	a,@r0
      002246 C0 E0            [24] 6903 	push	acc
      002248 C0 02            [24] 6904 	push	ar2
      00224A C0 03            [24] 6905 	push	ar3
      00224C C0 07            [24] 6906 	push	ar7
      00224E C0 06            [24] 6907 	push	ar6
      002250 E5 08            [12] 6908 	mov	a,_bp
      002252 24 F0            [12] 6909 	add	a,#0xf0
      002254 F8               [12] 6910 	mov	r0,a
      002255 86 82            [24] 6911 	mov	dpl, @r0
      002257 12 1D 1B         [24] 6912 	lcall	_fuzzy_implication
      00225A AC 82            [24] 6913 	mov	r4, dpl
      00225C AD 83            [24] 6914 	mov	r5, dph
      00225E AE F0            [24] 6915 	mov	r6, b
      002260 FF               [12] 6916 	mov	r7, a
      002261 E5 81            [12] 6917 	mov	a,sp
      002263 24 F8            [12] 6918 	add	a,#0xf8
      002265 F5 81            [12] 6919 	mov	sp,a
                           0021B0  6920 	C$fuzzy.h$1860$5_0$110 ==.
                                   6921 ;	../../fuzzy.h:1860: aggregation_method,
      002267 C0 04            [24] 6922 	push	ar4
      002269 C0 05            [24] 6923 	push	ar5
      00226B C0 06            [24] 6924 	push	ar6
      00226D C0 07            [24] 6925 	push	ar7
      00226F E5 08            [12] 6926 	mov	a,_bp
      002271 24 07            [12] 6927 	add	a,#0x07
      002273 F8               [12] 6928 	mov	r0,a
      002274 E6               [12] 6929 	mov	a,@r0
      002275 C0 E0            [24] 6930 	push	acc
      002277 08               [12] 6931 	inc	r0
      002278 E6               [12] 6932 	mov	a,@r0
      002279 C0 E0            [24] 6933 	push	acc
      00227B 08               [12] 6934 	inc	r0
      00227C E6               [12] 6935 	mov	a,@r0
      00227D C0 E0            [24] 6936 	push	acc
      00227F 08               [12] 6937 	inc	r0
      002280 E6               [12] 6938 	mov	a,@r0
      002281 C0 E0            [24] 6939 	push	acc
      002283 E5 08            [12] 6940 	mov	a,_bp
      002285 24 EF            [12] 6941 	add	a,#0xef
      002287 F8               [12] 6942 	mov	r0,a
      002288 86 82            [24] 6943 	mov	dpl, @r0
      00228A 12 1E 2E         [24] 6944 	lcall	_fuzzy_aggregation
      00228D C8               [12] 6945 	xch	a,r0
      00228E E5 08            [12] 6946 	mov	a,_bp
      002290 24 07            [12] 6947 	add	a,#0x07
      002292 C8               [12] 6948 	xch	a,r0
      002293 A6 82            [24] 6949 	mov	@r0, dpl
      002295 08               [12] 6950 	inc	r0
      002296 A6 83            [24] 6951 	mov	@r0, dph
      002298 08               [12] 6952 	inc	r0
      002299 A6 F0            [24] 6953 	mov	@r0, b
      00229B 08               [12] 6954 	inc	r0
      00229C F6               [12] 6955 	mov	@r0,a
      00229D E5 81            [12] 6956 	mov	a,sp
      00229F 24 F8            [12] 6957 	add	a,#0xf8
      0022A1 F5 81            [12] 6958 	mov	sp,a
                           0021EC  6959 	C$fuzzy.h$1847$1_0$105 ==.
                                   6960 ;	../../fuzzy.h:1847: index++
      0022A3 E5 08            [12] 6961 	mov	a,_bp
      0022A5 24 0B            [12] 6962 	add	a,#0x0b
      0022A7 F8               [12] 6963 	mov	r0,a
      0022A8 74 09            [12] 6964 	mov	a,#0x09
      0022AA 26               [12] 6965 	add	a, @r0
      0022AB F6               [12] 6966 	mov	@r0,a
      0022AC E4               [12] 6967 	clr	a
      0022AD 08               [12] 6968 	inc	r0
      0022AE 36               [12] 6969 	addc	a, @r0
      0022AF F6               [12] 6970 	mov	@r0,a
      0022B0 E5 08            [12] 6971 	mov	a,_bp
      0022B2 24 36            [12] 6972 	add	a,#0x36
      0022B4 F8               [12] 6973 	mov	r0,a
      0022B5 06               [12] 6974 	inc	@r0
      0022B6 B6 00 02         [24] 6975 	cjne	@r0,#0x00,00225$
      0022B9 08               [12] 6976 	inc	r0
      0022BA 06               [12] 6977 	inc	@r0
      0022BB                       6978 00225$:
      0022BB 02 21 84         [24] 6979 	ljmp	00125$
      0022BE                       6980 00106$:
                           002207  6981 	C$fuzzy.h$1867$3_0$108 ==.
                                   6982 ;	../../fuzzy.h:1867: aggregated_height
      0022BE E5 08            [12] 6983 	mov	a,_bp
      0022C0 24 07            [12] 6984 	add	a,#0x07
      0022C2 F8               [12] 6985 	mov	r0,a
      0022C3 86 82            [24] 6986 	mov	dpl, @r0
      0022C5 08               [12] 6987 	inc	r0
      0022C6 86 83            [24] 6988 	mov	dph, @r0
      0022C8 08               [12] 6989 	inc	r0
      0022C9 86 F0            [24] 6990 	mov	b, @r0
      0022CB 08               [12] 6991 	inc	r0
      0022CC E6               [12] 6992 	mov	a, @r0
      0022CD 12 00 EA         [24] 6993 	lcall	_fuzzy_clamp
      0022D0 C8               [12] 6994 	xch	a,r0
      0022D1 E5 08            [12] 6995 	mov	a,_bp
      0022D3 24 2C            [12] 6996 	add	a,#0x2c
      0022D5 C8               [12] 6997 	xch	a,r0
      0022D6 A6 82            [24] 6998 	mov	@r0, dpl
      0022D8 08               [12] 6999 	inc	r0
      0022D9 A6 83            [24] 7000 	mov	@r0, dph
      0022DB 08               [12] 7001 	inc	r0
      0022DC A6 F0            [24] 7002 	mov	@r0, b
      0022DE 08               [12] 7003 	inc	r0
      0022DF F6               [12] 7004 	mov	@r0,a
                           002229  7005 	C$fuzzy.h$1872$1_0$105 ==.
                                   7006 ;	../../fuzzy.h:1872: aggregated_height;
      0022E0 E5 08            [12] 7007 	mov	a,_bp
      0022E2 24 2C            [12] 7008 	add	a,#0x2c
      0022E4 F8               [12] 7009 	mov	r0,a
      0022E5 E6               [12] 7010 	mov	a,@r0
      0022E6 C0 E0            [24] 7011 	push	acc
      0022E8 08               [12] 7012 	inc	r0
      0022E9 E6               [12] 7013 	mov	a,@r0
      0022EA C0 E0            [24] 7014 	push	acc
      0022EC 08               [12] 7015 	inc	r0
      0022ED E6               [12] 7016 	mov	a,@r0
      0022EE C0 E0            [24] 7017 	push	acc
      0022F0 08               [12] 7018 	inc	r0
      0022F1 E6               [12] 7019 	mov	a,@r0
      0022F2 C0 E0            [24] 7020 	push	acc
      0022F4 E5 08            [12] 7021 	mov	a,_bp
      0022F6 24 28            [12] 7022 	add	a,#0x28
      0022F8 F8               [12] 7023 	mov	r0,a
      0022F9 86 82            [24] 7024 	mov	dpl, @r0
      0022FB 08               [12] 7025 	inc	r0
      0022FC 86 83            [24] 7026 	mov	dph, @r0
      0022FE 08               [12] 7027 	inc	r0
      0022FF 86 F0            [24] 7028 	mov	b, @r0
      002301 08               [12] 7029 	inc	r0
      002302 E6               [12] 7030 	mov	a, @r0
      002303 12 2A CE         [24] 7031 	lcall	___fsmul
      002306 AA 82            [24] 7032 	mov	r2, dpl
      002308 AB 83            [24] 7033 	mov	r3, dph
      00230A AE F0            [24] 7034 	mov	r6, b
      00230C FF               [12] 7035 	mov	r7, a
      00230D E5 81            [12] 7036 	mov	a,sp
      00230F 24 FC            [12] 7037 	add	a,#0xfc
      002311 F5 81            [12] 7038 	mov	sp,a
      002313 C0 02            [24] 7039 	push	ar2
      002315 C0 03            [24] 7040 	push	ar3
      002317 C0 06            [24] 7041 	push	ar6
      002319 C0 07            [24] 7042 	push	ar7
                           002264  7043 	C$fuzzy.h$1875$1_0$105 ==.
                                   7044 ;	../../fuzzy.h:1875: aggregated_height;
      00231B E5 08            [12] 7045 	mov	a,_bp
      00231D 24 10            [12] 7046 	add	a,#0x10
      00231F F8               [12] 7047 	mov	r0,a
      002320 86 82            [24] 7048 	mov	dpl, @r0
      002322 08               [12] 7049 	inc	r0
      002323 86 83            [24] 7050 	mov	dph, @r0
      002325 08               [12] 7051 	inc	r0
      002326 86 F0            [24] 7052 	mov	b, @r0
      002328 08               [12] 7053 	inc	r0
      002329 E6               [12] 7054 	mov	a, @r0
      00232A 12 2C 50         [24] 7055 	lcall	___fsadd
      00232D C8               [12] 7056 	xch	a,r0
      00232E E5 08            [12] 7057 	mov	a,_bp
      002330 24 10            [12] 7058 	add	a,#0x10
      002332 C8               [12] 7059 	xch	a,r0
      002333 A6 82            [24] 7060 	mov	@r0, dpl
      002335 08               [12] 7061 	inc	r0
      002336 A6 83            [24] 7062 	mov	@r0, dph
      002338 08               [12] 7063 	inc	r0
      002339 A6 F0            [24] 7064 	mov	@r0, b
      00233B 08               [12] 7065 	inc	r0
      00233C F6               [12] 7066 	mov	@r0,a
      00233D E5 81            [12] 7067 	mov	a,sp
      00233F 24 FC            [12] 7068 	add	a,#0xfc
      002341 F5 81            [12] 7069 	mov	sp,a
      002343 E5 08            [12] 7070 	mov	a,_bp
      002345 24 2C            [12] 7071 	add	a,#0x2c
      002347 F8               [12] 7072 	mov	r0,a
      002348 E6               [12] 7073 	mov	a,@r0
      002349 C0 E0            [24] 7074 	push	acc
      00234B 08               [12] 7075 	inc	r0
      00234C E6               [12] 7076 	mov	a,@r0
      00234D C0 E0            [24] 7077 	push	acc
      00234F 08               [12] 7078 	inc	r0
      002350 E6               [12] 7079 	mov	a,@r0
      002351 C0 E0            [24] 7080 	push	acc
      002353 08               [12] 7081 	inc	r0
      002354 E6               [12] 7082 	mov	a,@r0
      002355 C0 E0            [24] 7083 	push	acc
                           0022A0  7084 	C$fuzzy.h$1878$1_0$105 ==.
                                   7085 ;	../../fuzzy.h:1878: !maximum_found ||
      002357 E5 08            [12] 7086 	mov	a,_bp
      002359 24 14            [12] 7087 	add	a,#0x14
      00235B F8               [12] 7088 	mov	r0,a
      00235C 86 82            [24] 7089 	mov	dpl, @r0
      00235E 08               [12] 7090 	inc	r0
      00235F 86 83            [24] 7091 	mov	dph, @r0
      002361 08               [12] 7092 	inc	r0
      002362 86 F0            [24] 7093 	mov	b, @r0
      002364 08               [12] 7094 	inc	r0
      002365 E6               [12] 7095 	mov	a, @r0
      002366 12 2C 50         [24] 7096 	lcall	___fsadd
      002369 C8               [12] 7097 	xch	a,r0
      00236A E5 08            [12] 7098 	mov	a,_bp
      00236C 24 14            [12] 7099 	add	a,#0x14
      00236E C8               [12] 7100 	xch	a,r0
      00236F A6 82            [24] 7101 	mov	@r0, dpl
      002371 08               [12] 7102 	inc	r0
      002372 A6 83            [24] 7103 	mov	@r0, dph
      002374 08               [12] 7104 	inc	r0
      002375 A6 F0            [24] 7105 	mov	@r0, b
      002377 08               [12] 7106 	inc	r0
      002378 F6               [12] 7107 	mov	@r0,a
      002379 E5 81            [12] 7108 	mov	a,sp
      00237B 24 FC            [12] 7109 	add	a,#0xfc
      00237D F5 81            [12] 7110 	mov	sp,a
      00237F E5 08            [12] 7111 	mov	a,_bp
      002381 24 38            [12] 7112 	add	a,#0x38
      002383 F8               [12] 7113 	mov	r0,a
      002384 E6               [12] 7114 	mov	a,@r0
      002385 60 31            [24] 7115 	jz	00109$
                           0022D0  7116 	C$fuzzy.h$1880$1_0$105 ==.
                                   7117 ;	../../fuzzy.h:1880: ) {
      002387 E5 08            [12] 7118 	mov	a,_bp
      002389 24 2C            [12] 7119 	add	a,#0x2c
      00238B F8               [12] 7120 	mov	r0,a
      00238C E6               [12] 7121 	mov	a,@r0
      00238D C0 E0            [24] 7122 	push	acc
      00238F 08               [12] 7123 	inc	r0
      002390 E6               [12] 7124 	mov	a,@r0
      002391 C0 E0            [24] 7125 	push	acc
      002393 08               [12] 7126 	inc	r0
      002394 E6               [12] 7127 	mov	a,@r0
      002395 C0 E0            [24] 7128 	push	acc
      002397 08               [12] 7129 	inc	r0
      002398 E6               [12] 7130 	mov	a,@r0
      002399 C0 E0            [24] 7131 	push	acc
      00239B E5 08            [12] 7132 	mov	a,_bp
      00239D 24 18            [12] 7133 	add	a,#0x18
      00239F F8               [12] 7134 	mov	r0,a
      0023A0 86 82            [24] 7135 	mov	dpl, @r0
      0023A2 08               [12] 7136 	inc	r0
      0023A3 86 83            [24] 7137 	mov	dph, @r0
      0023A5 08               [12] 7138 	inc	r0
      0023A6 86 F0            [24] 7139 	mov	b, @r0
      0023A8 08               [12] 7140 	inc	r0
      0023A9 E6               [12] 7141 	mov	a, @r0
      0023AA 12 2B FE         [24] 7142 	lcall	___fslt
      0023AD AF 82            [24] 7143 	mov	r7, dpl
      0023AF E5 81            [12] 7144 	mov	a,sp
      0023B1 24 FC            [12] 7145 	add	a,#0xfc
      0023B3 F5 81            [12] 7146 	mov	sp,a
      0023B5 EF               [12] 7147 	mov	a,r7
      0023B6 60 74            [24] 7148 	jz	00110$
      0023B8                       7149 00109$:
                           002301  7150 	C$fuzzy.h$1881$4_0$111 ==.
                                   7151 ;	../../fuzzy.h:1881: maximum_height = aggregated_height;
      0023B8 E5 08            [12] 7152 	mov	a,_bp
      0023BA 24 2C            [12] 7153 	add	a,#0x2c
      0023BC F8               [12] 7154 	mov	r0,a
      0023BD E5 08            [12] 7155 	mov	a,_bp
      0023BF 24 18            [12] 7156 	add	a,#0x18
      0023C1 F9               [12] 7157 	mov	r1,a
      0023C2 E6               [12] 7158 	mov	a,@r0
      0023C3 F7               [12] 7159 	mov	@r1,a
      0023C4 08               [12] 7160 	inc	r0
      0023C5 E6               [12] 7161 	mov	a,@r0
      0023C6 09               [12] 7162 	inc	r1
      0023C7 F7               [12] 7163 	mov	@r1,a
      0023C8 08               [12] 7164 	inc	r0
      0023C9 E6               [12] 7165 	mov	a,@r0
      0023CA 09               [12] 7166 	inc	r1
      0023CB F7               [12] 7167 	mov	@r1,a
      0023CC 08               [12] 7168 	inc	r0
      0023CD E6               [12] 7169 	mov	a,@r0
      0023CE 09               [12] 7170 	inc	r1
      0023CF F7               [12] 7171 	mov	@r1,a
                           002319  7172 	C$fuzzy.h$1882$4_0$111 ==.
                                   7173 ;	../../fuzzy.h:1882: smallest_maximum = value;
      0023D0 E5 08            [12] 7174 	mov	a,_bp
      0023D2 24 28            [12] 7175 	add	a,#0x28
      0023D4 F8               [12] 7176 	mov	r0,a
      0023D5 E5 08            [12] 7177 	mov	a,_bp
      0023D7 24 20            [12] 7178 	add	a,#0x20
      0023D9 F9               [12] 7179 	mov	r1,a
      0023DA E6               [12] 7180 	mov	a,@r0
      0023DB F7               [12] 7181 	mov	@r1,a
      0023DC 08               [12] 7182 	inc	r0
      0023DD E6               [12] 7183 	mov	a,@r0
      0023DE 09               [12] 7184 	inc	r1
      0023DF F7               [12] 7185 	mov	@r1,a
      0023E0 08               [12] 7186 	inc	r0
      0023E1 E6               [12] 7187 	mov	a,@r0
      0023E2 09               [12] 7188 	inc	r1
      0023E3 F7               [12] 7189 	mov	@r1,a
      0023E4 08               [12] 7190 	inc	r0
      0023E5 E6               [12] 7191 	mov	a,@r0
      0023E6 09               [12] 7192 	inc	r1
      0023E7 F7               [12] 7193 	mov	@r1,a
                           002331  7194 	C$fuzzy.h$1883$4_0$111 ==.
                                   7195 ;	../../fuzzy.h:1883: largest_maximum = value;
      0023E8 E5 08            [12] 7196 	mov	a,_bp
      0023EA 24 28            [12] 7197 	add	a,#0x28
      0023EC F8               [12] 7198 	mov	r0,a
      0023ED E5 08            [12] 7199 	mov	a,_bp
      0023EF 24 24            [12] 7200 	add	a,#0x24
      0023F1 F9               [12] 7201 	mov	r1,a
      0023F2 E6               [12] 7202 	mov	a,@r0
      0023F3 F7               [12] 7203 	mov	@r1,a
      0023F4 08               [12] 7204 	inc	r0
      0023F5 E6               [12] 7205 	mov	a,@r0
      0023F6 09               [12] 7206 	inc	r1
      0023F7 F7               [12] 7207 	mov	@r1,a
      0023F8 08               [12] 7208 	inc	r0
      0023F9 E6               [12] 7209 	mov	a,@r0
      0023FA 09               [12] 7210 	inc	r1
      0023FB F7               [12] 7211 	mov	@r1,a
      0023FC 08               [12] 7212 	inc	r0
      0023FD E6               [12] 7213 	mov	a,@r0
      0023FE 09               [12] 7214 	inc	r1
      0023FF F7               [12] 7215 	mov	@r1,a
                           002349  7216 	C$fuzzy.h$1884$4_0$111 ==.
                                   7217 ;	../../fuzzy.h:1884: maximum_position_sum = value;
      002400 E5 08            [12] 7218 	mov	a,_bp
      002402 24 28            [12] 7219 	add	a,#0x28
      002404 F8               [12] 7220 	mov	r0,a
      002405 E5 08            [12] 7221 	mov	a,_bp
      002407 24 1C            [12] 7222 	add	a,#0x1c
      002409 F9               [12] 7223 	mov	r1,a
      00240A E6               [12] 7224 	mov	a,@r0
      00240B F7               [12] 7225 	mov	@r1,a
      00240C 08               [12] 7226 	inc	r0
      00240D E6               [12] 7227 	mov	a,@r0
      00240E 09               [12] 7228 	inc	r1
      00240F F7               [12] 7229 	mov	@r1,a
      002410 08               [12] 7230 	inc	r0
      002411 E6               [12] 7231 	mov	a,@r0
      002412 09               [12] 7232 	inc	r1
      002413 F7               [12] 7233 	mov	@r1,a
      002414 08               [12] 7234 	inc	r0
      002415 E6               [12] 7235 	mov	a,@r0
      002416 09               [12] 7236 	inc	r1
      002417 F7               [12] 7237 	mov	@r1,a
                           002361  7238 	C$fuzzy.h$1885$4_0$111 ==.
                                   7239 ;	../../fuzzy.h:1885: maximum_count = 1u;
      002418 E5 08            [12] 7240 	mov	a,_bp
      00241A 24 34            [12] 7241 	add	a,#0x34
      00241C F8               [12] 7242 	mov	r0,a
      00241D 76 01            [12] 7243 	mov	@r0,#0x01
      00241F 08               [12] 7244 	inc	r0
      002420 76 00            [12] 7245 	mov	@r0,#0x00
                           00236B  7246 	C$fuzzy.h$1886$4_0$111 ==.
                                   7247 ;	../../fuzzy.h:1886: maximum_found = true;
      002422 E5 08            [12] 7248 	mov	a,_bp
      002424 24 38            [12] 7249 	add	a,#0x38
      002426 F8               [12] 7250 	mov	r0,a
      002427 76 01            [12] 7251 	mov	@r0,#0x01
      002429 02 24 BC         [24] 7252 	ljmp	00129$
      00242C                       7253 00110$:
                           002375  7254 	C$fuzzy.h$1888$1_0$105 ==.
                                   7255 ;	../../fuzzy.h:1888: else if (aggregated_height == maximum_height) {
      00242C E5 08            [12] 7256 	mov	a,_bp
      00242E 24 18            [12] 7257 	add	a,#0x18
      002430 F8               [12] 7258 	mov	r0,a
      002431 E6               [12] 7259 	mov	a,@r0
      002432 C0 E0            [24] 7260 	push	acc
      002434 08               [12] 7261 	inc	r0
      002435 E6               [12] 7262 	mov	a,@r0
      002436 C0 E0            [24] 7263 	push	acc
      002438 08               [12] 7264 	inc	r0
      002439 E6               [12] 7265 	mov	a,@r0
      00243A C0 E0            [24] 7266 	push	acc
      00243C 08               [12] 7267 	inc	r0
      00243D E6               [12] 7268 	mov	a,@r0
      00243E C0 E0            [24] 7269 	push	acc
      002440 E5 08            [12] 7270 	mov	a,_bp
      002442 24 2C            [12] 7271 	add	a,#0x2c
      002444 F8               [12] 7272 	mov	r0,a
      002445 86 82            [24] 7273 	mov	dpl, @r0
      002447 08               [12] 7274 	inc	r0
      002448 86 83            [24] 7275 	mov	dph, @r0
      00244A 08               [12] 7276 	inc	r0
      00244B 86 F0            [24] 7277 	mov	b, @r0
      00244D 08               [12] 7278 	inc	r0
      00244E E6               [12] 7279 	mov	a, @r0
      00244F 12 2B D2         [24] 7280 	lcall	___fseq
      002452 AF 82            [24] 7281 	mov	r7, dpl
      002454 E5 81            [12] 7282 	mov	a,sp
      002456 24 FC            [12] 7283 	add	a,#0xfc
      002458 F5 81            [12] 7284 	mov	sp,a
      00245A EF               [12] 7285 	mov	a,r7
      00245B 60 5F            [24] 7286 	jz	00129$
                           0023A6  7287 	C$fuzzy.h$1889$4_0$112 ==.
                                   7288 ;	../../fuzzy.h:1889: largest_maximum = value;
      00245D E5 08            [12] 7289 	mov	a,_bp
      00245F 24 28            [12] 7290 	add	a,#0x28
      002461 F8               [12] 7291 	mov	r0,a
      002462 E5 08            [12] 7292 	mov	a,_bp
      002464 24 24            [12] 7293 	add	a,#0x24
      002466 F9               [12] 7294 	mov	r1,a
      002467 E6               [12] 7295 	mov	a,@r0
      002468 F7               [12] 7296 	mov	@r1,a
      002469 08               [12] 7297 	inc	r0
      00246A E6               [12] 7298 	mov	a,@r0
      00246B 09               [12] 7299 	inc	r1
      00246C F7               [12] 7300 	mov	@r1,a
      00246D 08               [12] 7301 	inc	r0
      00246E E6               [12] 7302 	mov	a,@r0
      00246F 09               [12] 7303 	inc	r1
      002470 F7               [12] 7304 	mov	@r1,a
      002471 08               [12] 7305 	inc	r0
      002472 E6               [12] 7306 	mov	a,@r0
      002473 09               [12] 7307 	inc	r1
      002474 F7               [12] 7308 	mov	@r1,a
                           0023BE  7309 	C$fuzzy.h$1890$1_0$105 ==.
                                   7310 ;	../../fuzzy.h:1890: maximum_position_sum += value;
      002475 E5 08            [12] 7311 	mov	a,_bp
      002477 24 28            [12] 7312 	add	a,#0x28
      002479 F8               [12] 7313 	mov	r0,a
      00247A E6               [12] 7314 	mov	a,@r0
      00247B C0 E0            [24] 7315 	push	acc
      00247D 08               [12] 7316 	inc	r0
      00247E E6               [12] 7317 	mov	a,@r0
      00247F C0 E0            [24] 7318 	push	acc
      002481 08               [12] 7319 	inc	r0
      002482 E6               [12] 7320 	mov	a,@r0
      002483 C0 E0            [24] 7321 	push	acc
      002485 08               [12] 7322 	inc	r0
      002486 E6               [12] 7323 	mov	a,@r0
      002487 C0 E0            [24] 7324 	push	acc
                           0023D2  7325 	C$fuzzy.h$1891$1_0$105 ==.
                                   7326 ;	../../fuzzy.h:1891: maximum_count++;
      002489 E5 08            [12] 7327 	mov	a,_bp
      00248B 24 1C            [12] 7328 	add	a,#0x1c
      00248D F8               [12] 7329 	mov	r0,a
      00248E 86 82            [24] 7330 	mov	dpl, @r0
      002490 08               [12] 7331 	inc	r0
      002491 86 83            [24] 7332 	mov	dph, @r0
      002493 08               [12] 7333 	inc	r0
      002494 86 F0            [24] 7334 	mov	b, @r0
      002496 08               [12] 7335 	inc	r0
      002497 E6               [12] 7336 	mov	a, @r0
      002498 12 2C 50         [24] 7337 	lcall	___fsadd
      00249B C8               [12] 7338 	xch	a,r0
      00249C E5 08            [12] 7339 	mov	a,_bp
      00249E 24 1C            [12] 7340 	add	a,#0x1c
      0024A0 C8               [12] 7341 	xch	a,r0
      0024A1 A6 82            [24] 7342 	mov	@r0, dpl
      0024A3 08               [12] 7343 	inc	r0
      0024A4 A6 83            [24] 7344 	mov	@r0, dph
      0024A6 08               [12] 7345 	inc	r0
      0024A7 A6 F0            [24] 7346 	mov	@r0, b
      0024A9 08               [12] 7347 	inc	r0
      0024AA F6               [12] 7348 	mov	@r0,a
      0024AB E5 81            [12] 7349 	mov	a,sp
      0024AD 24 FC            [12] 7350 	add	a,#0xfc
      0024AF F5 81            [12] 7351 	mov	sp,a
      0024B1 E5 08            [12] 7352 	mov	a,_bp
      0024B3 24 34            [12] 7353 	add	a,#0x34
      0024B5 F8               [12] 7354 	mov	r0,a
      0024B6 06               [12] 7355 	inc	@r0
      0024B7 B6 00 02         [24] 7356 	cjne	@r0,#0x00,00229$
      0024BA 08               [12] 7357 	inc	r0
      0024BB 06               [12] 7358 	inc	@r0
      0024BC                       7359 00229$:
      0024BC                       7360 00129$:
                           002405  7361 	C$fuzzy.h$1841$1_0$105 ==.
                                   7362 ;	../../fuzzy.h:1841: ) {
      0024BC E5 08            [12] 7363 	mov	a,_bp
      0024BE 24 F2            [12] 7364 	add	a,#0xf2
      0024C0 F8               [12] 7365 	mov	r0,a
      0024C1 E6               [12] 7366 	mov	a,@r0
      0024C2 C0 E0            [24] 7367 	push	acc
      0024C4 08               [12] 7368 	inc	r0
      0024C5 E6               [12] 7369 	mov	a,@r0
      0024C6 C0 E0            [24] 7370 	push	acc
      0024C8 08               [12] 7371 	inc	r0
      0024C9 E6               [12] 7372 	mov	a,@r0
      0024CA C0 E0            [24] 7373 	push	acc
      0024CC 08               [12] 7374 	inc	r0
      0024CD E6               [12] 7375 	mov	a,@r0
      0024CE C0 E0            [24] 7376 	push	acc
      0024D0 E5 08            [12] 7377 	mov	a,_bp
      0024D2 24 28            [12] 7378 	add	a,#0x28
      0024D4 F8               [12] 7379 	mov	r0,a
      0024D5 86 82            [24] 7380 	mov	dpl, @r0
      0024D7 08               [12] 7381 	inc	r0
      0024D8 86 83            [24] 7382 	mov	dph, @r0
      0024DA 08               [12] 7383 	inc	r0
      0024DB 86 F0            [24] 7384 	mov	b, @r0
      0024DD 08               [12] 7385 	inc	r0
      0024DE E6               [12] 7386 	mov	a, @r0
      0024DF 12 2C 50         [24] 7387 	lcall	___fsadd
      0024E2 C8               [12] 7388 	xch	a,r0
      0024E3 E5 08            [12] 7389 	mov	a,_bp
      0024E5 24 28            [12] 7390 	add	a,#0x28
      0024E7 C8               [12] 7391 	xch	a,r0
      0024E8 A6 82            [24] 7392 	mov	@r0, dpl
      0024EA 08               [12] 7393 	inc	r0
      0024EB A6 83            [24] 7394 	mov	@r0, dph
      0024ED 08               [12] 7395 	inc	r0
      0024EE A6 F0            [24] 7396 	mov	@r0, b
      0024F0 08               [12] 7397 	inc	r0
      0024F1 F6               [12] 7398 	mov	@r0,a
      0024F2 E5 81            [12] 7399 	mov	a,sp
      0024F4 24 FC            [12] 7400 	add	a,#0xfc
      0024F6 F5 81            [12] 7401 	mov	sp,a
      0024F8 02 21 2E         [24] 7402 	ljmp	00128$
      0024FB                       7403 00113$:
                           002444  7404 	C$fuzzy.h$1896$1_0$105 ==.
                                   7405 ;	../../fuzzy.h:1896: !maximum_found ||
      0024FB E5 08            [12] 7406 	mov	a,_bp
      0024FD 24 38            [12] 7407 	add	a,#0x38
      0024FF F8               [12] 7408 	mov	r0,a
      002500 E6               [12] 7409 	mov	a,@r0
      002501 60 56            [24] 7410 	jz	00114$
                           00244C  7411 	C$fuzzy.h$1897$1_0$105 ==.
                                   7412 ;	../../fuzzy.h:1897: maximum_height <= LEVEL_LO ||
      002503 E5 08            [12] 7413 	mov	a,_bp
      002505 24 18            [12] 7414 	add	a,#0x18
      002507 F8               [12] 7415 	mov	r0,a
      002508 E6               [12] 7416 	mov	a,@r0
      002509 C0 E0            [24] 7417 	push	acc
      00250B 08               [12] 7418 	inc	r0
      00250C E6               [12] 7419 	mov	a,@r0
      00250D C0 E0            [24] 7420 	push	acc
      00250F 08               [12] 7421 	inc	r0
      002510 E6               [12] 7422 	mov	a,@r0
      002511 C0 E0            [24] 7423 	push	acc
      002513 08               [12] 7424 	inc	r0
      002514 E6               [12] 7425 	mov	a,@r0
      002515 C0 E0            [24] 7426 	push	acc
      002517 90 00 00         [24] 7427 	mov	dptr,#0x0000
      00251A E4               [12] 7428 	clr	a
      00251B F5 F0            [12] 7429 	mov	b,a
      00251D 12 2B FE         [24] 7430 	lcall	___fslt
      002520 E5 81            [12] 7431 	mov	a,sp
      002522 24 FC            [12] 7432 	add	a,#0xfc
      002524 F5 81            [12] 7433 	mov	sp,a
      002526 E5 82            [12] 7434 	mov	a, dpl
      002528 24 FF            [12] 7435 	add	a,#0xff
      00252A 92 00            [24] 7436 	mov	b0,c
      00252C 50 2B            [24] 7437 	jnc	00114$
                           002477  7438 	C$fuzzy.h$1899$1_0$105 ==.
                                   7439 ;	../../fuzzy.h:1899: ) {
      00252E E5 08            [12] 7440 	mov	a,_bp
      002530 24 14            [12] 7441 	add	a,#0x14
      002532 F8               [12] 7442 	mov	r0,a
      002533 E6               [12] 7443 	mov	a,@r0
      002534 C0 E0            [24] 7444 	push	acc
      002536 08               [12] 7445 	inc	r0
      002537 E6               [12] 7446 	mov	a,@r0
      002538 C0 E0            [24] 7447 	push	acc
      00253A 08               [12] 7448 	inc	r0
      00253B E6               [12] 7449 	mov	a,@r0
      00253C C0 E0            [24] 7450 	push	acc
      00253E 08               [12] 7451 	inc	r0
      00253F E6               [12] 7452 	mov	a,@r0
      002540 C0 E0            [24] 7453 	push	acc
      002542 90 00 00         [24] 7454 	mov	dptr,#0x0000
      002545 E4               [12] 7455 	clr	a
      002546 F5 F0            [12] 7456 	mov	b,a
      002548 12 2B FE         [24] 7457 	lcall	___fslt
      00254B E5 81            [12] 7458 	mov	a,sp
      00254D 24 FC            [12] 7459 	add	a,#0xfc
      00254F F5 81            [12] 7460 	mov	sp,a
      002551 E5 82            [12] 7461 	mov	a, dpl
      002553 24 FF            [12] 7462 	add	a,#0xff
      002555 92 00            [24] 7463 	mov	b0,c
      002557 40 09            [24] 7464 	jc	00115$
      002559                       7465 00114$:
                           0024A2  7466 	C$fuzzy.h$1900$2_0$113 ==.
                                   7467 ;	../../fuzzy.h:1900: return 0.0f;
      002559 90 00 00         [24] 7468 	mov	dptr,#0x0000
      00255C E4               [12] 7469 	clr	a
      00255D F5 F0            [12] 7470 	mov	b,a
      00255F 02 26 2F         [24] 7471 	ljmp	00130$
      002562                       7472 00115$:
                           0024AB  7473 	C$fuzzy.h$1903$1_0$105 ==.
                                   7474 ;	../../fuzzy.h:1903: switch (defuzz_method) {
      002562 E5 08            [12] 7475 	mov	a,_bp
      002564 24 F1            [12] 7476 	add	a,#0xf1
      002566 F8               [12] 7477 	mov	r0,a
      002567 E6               [12] 7478 	mov	a,@r0
      002568 24 FC            [12] 7479 	add	a,#0xff - 0x03
      00256A 50 03            [24] 7480 	jnc	00233$
      00256C 02 26 29         [24] 7481 	ljmp	00122$
      00256F                       7482 00233$:
      00256F E5 08            [12] 7483 	mov	a,_bp
      002571 24 F1            [12] 7484 	add	a,#0xf1
      002573 F8               [12] 7485 	mov	r0,a
      002574 E6               [12] 7486 	mov	a,@r0
      002575 26               [12] 7487 	add	a,@r0
      002576 26               [12] 7488 	add	a,@r0
      002577 90 25 7B         [24] 7489 	mov	dptr,#00234$
      00257A 73               [24] 7490 	jmp	@a+dptr
      00257B                       7491 00234$:
      00257B 02 25 87         [24] 7492 	ljmp	00118$
      00257E 02 25 C3         [24] 7493 	ljmp	00119$
      002581 02 26 07         [24] 7494 	ljmp	00120$
      002584 02 26 18         [24] 7495 	ljmp	00121$
                           0024D0  7496 	C$fuzzy.h$1904$2_0$114 ==.
                                   7497 ;	../../fuzzy.h:1904: case FUZZY_DEFUZZ_COG:
      002587                       7498 00118$:
                           0024D0  7499 	C$fuzzy.h$1906$1_0$105 ==.
                                   7500 ;	../../fuzzy.h:1906: height_sum;
      002587 E5 08            [12] 7501 	mov	a,_bp
      002589 24 14            [12] 7502 	add	a,#0x14
      00258B F8               [12] 7503 	mov	r0,a
      00258C E6               [12] 7504 	mov	a,@r0
      00258D C0 E0            [24] 7505 	push	acc
      00258F 08               [12] 7506 	inc	r0
      002590 E6               [12] 7507 	mov	a,@r0
      002591 C0 E0            [24] 7508 	push	acc
      002593 08               [12] 7509 	inc	r0
      002594 E6               [12] 7510 	mov	a,@r0
      002595 C0 E0            [24] 7511 	push	acc
      002597 08               [12] 7512 	inc	r0
      002598 E6               [12] 7513 	mov	a,@r0
      002599 C0 E0            [24] 7514 	push	acc
      00259B E5 08            [12] 7515 	mov	a,_bp
      00259D 24 10            [12] 7516 	add	a,#0x10
      00259F F8               [12] 7517 	mov	r0,a
      0025A0 86 82            [24] 7518 	mov	dpl, @r0
      0025A2 08               [12] 7519 	inc	r0
      0025A3 86 83            [24] 7520 	mov	dph, @r0
      0025A5 08               [12] 7521 	inc	r0
      0025A6 86 F0            [24] 7522 	mov	b, @r0
      0025A8 08               [12] 7523 	inc	r0
      0025A9 E6               [12] 7524 	mov	a, @r0
      0025AA 12 2D 67         [24] 7525 	lcall	___fsdiv
      0025AD AC 82            [24] 7526 	mov	r4, dpl
      0025AF AD 83            [24] 7527 	mov	r5, dph
      0025B1 AE F0            [24] 7528 	mov	r6, b
      0025B3 FF               [12] 7529 	mov	r7, a
      0025B4 E5 81            [12] 7530 	mov	a,sp
      0025B6 24 FC            [12] 7531 	add	a,#0xfc
      0025B8 F5 81            [12] 7532 	mov	sp,a
      0025BA 8C 82            [24] 7533 	mov	dpl, r4
      0025BC 8D 83            [24] 7534 	mov	dph, r5
      0025BE 8E F0            [24] 7535 	mov	b, r6
      0025C0 EF               [12] 7536 	mov	a, r7
                           00250A  7537 	C$fuzzy.h$1908$2_0$114 ==.
                                   7538 ;	../../fuzzy.h:1908: case FUZZY_DEFUZZ_MOM:
      0025C1 80 6C            [24] 7539 	sjmp	00130$
      0025C3                       7540 00119$:
                           00250C  7541 	C$fuzzy.h$1910$1_0$105 ==.
                                   7542 ;	../../fuzzy.h:1910: (float)maximum_count;
      0025C3 E5 08            [12] 7543 	mov	a,_bp
      0025C5 24 34            [12] 7544 	add	a,#0x34
      0025C7 F8               [12] 7545 	mov	r0,a
      0025C8 86 82            [24] 7546 	mov	dpl, @r0
      0025CA 08               [12] 7547 	inc	r0
      0025CB 86 83            [24] 7548 	mov	dph, @r0
      0025CD 12 2C F2         [24] 7549 	lcall	___uint2fs
      0025D0 AC 82            [24] 7550 	mov	r4, dpl
      0025D2 AD 83            [24] 7551 	mov	r5, dph
      0025D4 AE F0            [24] 7552 	mov	r6, b
      0025D6 FF               [12] 7553 	mov	r7, a
      0025D7 C0 04            [24] 7554 	push	ar4
      0025D9 C0 05            [24] 7555 	push	ar5
      0025DB C0 06            [24] 7556 	push	ar6
      0025DD C0 07            [24] 7557 	push	ar7
      0025DF E5 08            [12] 7558 	mov	a,_bp
      0025E1 24 1C            [12] 7559 	add	a,#0x1c
      0025E3 F8               [12] 7560 	mov	r0,a
      0025E4 86 82            [24] 7561 	mov	dpl, @r0
      0025E6 08               [12] 7562 	inc	r0
      0025E7 86 83            [24] 7563 	mov	dph, @r0
      0025E9 08               [12] 7564 	inc	r0
      0025EA 86 F0            [24] 7565 	mov	b, @r0
      0025EC 08               [12] 7566 	inc	r0
      0025ED E6               [12] 7567 	mov	a, @r0
      0025EE 12 2D 67         [24] 7568 	lcall	___fsdiv
      0025F1 AC 82            [24] 7569 	mov	r4, dpl
      0025F3 AD 83            [24] 7570 	mov	r5, dph
      0025F5 AE F0            [24] 7571 	mov	r6, b
      0025F7 FF               [12] 7572 	mov	r7, a
      0025F8 E5 81            [12] 7573 	mov	a,sp
      0025FA 24 FC            [12] 7574 	add	a,#0xfc
      0025FC F5 81            [12] 7575 	mov	sp,a
      0025FE 8C 82            [24] 7576 	mov	dpl, r4
      002600 8D 83            [24] 7577 	mov	dph, r5
      002602 8E F0            [24] 7578 	mov	b, r6
      002604 EF               [12] 7579 	mov	a, r7
                           00254E  7580 	C$fuzzy.h$1912$2_0$114 ==.
                                   7581 ;	../../fuzzy.h:1912: case FUZZY_DEFUZZ_SOM:
      002605 80 28            [24] 7582 	sjmp	00130$
      002607                       7583 00120$:
                           002550  7584 	C$fuzzy.h$1913$2_0$114 ==.
                                   7585 ;	../../fuzzy.h:1913: return smallest_maximum;
      002607 E5 08            [12] 7586 	mov	a,_bp
      002609 24 20            [12] 7587 	add	a,#0x20
      00260B F8               [12] 7588 	mov	r0,a
      00260C 86 82            [24] 7589 	mov	dpl, @r0
      00260E 08               [12] 7590 	inc	r0
      00260F 86 83            [24] 7591 	mov	dph, @r0
      002611 08               [12] 7592 	inc	r0
      002612 86 F0            [24] 7593 	mov	b, @r0
      002614 08               [12] 7594 	inc	r0
      002615 E6               [12] 7595 	mov	a, @r0
                           00255F  7596 	C$fuzzy.h$1915$2_0$114 ==.
                                   7597 ;	../../fuzzy.h:1915: case FUZZY_DEFUZZ_LOM:
      002616 80 17            [24] 7598 	sjmp	00130$
      002618                       7599 00121$:
                           002561  7600 	C$fuzzy.h$1916$2_0$114 ==.
                                   7601 ;	../../fuzzy.h:1916: return largest_maximum;
      002618 E5 08            [12] 7602 	mov	a,_bp
      00261A 24 24            [12] 7603 	add	a,#0x24
      00261C F8               [12] 7604 	mov	r0,a
      00261D 86 82            [24] 7605 	mov	dpl, @r0
      00261F 08               [12] 7606 	inc	r0
      002620 86 83            [24] 7607 	mov	dph, @r0
      002622 08               [12] 7608 	inc	r0
      002623 86 F0            [24] 7609 	mov	b, @r0
      002625 08               [12] 7610 	inc	r0
      002626 E6               [12] 7611 	mov	a, @r0
                           002570  7612 	C$fuzzy.h$1918$2_0$114 ==.
                                   7613 ;	../../fuzzy.h:1918: default:
      002627 80 06            [24] 7614 	sjmp	00130$
      002629                       7615 00122$:
                           002572  7616 	C$fuzzy.h$1919$2_0$114 ==.
                                   7617 ;	../../fuzzy.h:1919: return 0.0f;
      002629 90 00 00         [24] 7618 	mov	dptr,#0x0000
      00262C E4               [12] 7619 	clr	a
      00262D F5 F0            [12] 7620 	mov	b,a
                           002578  7621 	C$fuzzy.h$1920$1_0$105 ==.
                                   7622 ;	../../fuzzy.h:1920: }
      00262F                       7623 00130$:
                           002578  7624 	C$fuzzy.h$1921$1_0$105 ==.
                                   7625 ;	../../fuzzy.h:1921: }
      00262F 85 08 81         [24] 7626 	mov	sp,_bp
      002632 D0 08            [24] 7627 	pop	_bp
                           00257D  7628 	C$fuzzy.h$1921$1_0$105 ==.
                           00257D  7629 	XG$fuzzy_rules_defuzzify_method$0$0 ==.
      002634 22               [24] 7630 	ret
                                   7631 ;------------------------------------------------------------
                                   7632 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify'
                                   7633 ;------------------------------------------------------------
                                   7634 ;lower         Allocated to stack - _bp -6 +4 
                                   7635 ;upper         Allocated to stack - _bp -10 +4 
                                   7636 ;step          Allocated to stack - _bp -14 +4 
                                   7637 ;method        Allocated to stack - _bp -15 +1 
                                   7638 ;rules         Allocated to registers r5 r6 r7 
                                   7639 ;------------------------------------------------------------
                           00257E  7640 	G$fuzzy_rules_defuzzify$0$0 ==.
                           00257E  7641 	C$fuzzy.h$1923$1_0$116 ==.
                                   7642 ;	../../fuzzy.h:1923: float fuzzy_rules_defuzzify(
                                   7643 ;	-----------------------------------------
                                   7644 ;	 function fuzzy_rules_defuzzify
                                   7645 ;	-----------------------------------------
      002635                       7646 _fuzzy_rules_defuzzify:
      002635 C0 08            [24] 7647 	push	_bp
      002637 85 81 08         [24] 7648 	mov	_bp,sp
      00263A AD 82            [24] 7649 	mov	r5, dpl
      00263C AE 83            [24] 7650 	mov	r6, dph
      00263E AF F0            [24] 7651 	mov	r7, b
                           002589  7652 	C$fuzzy.h$1932$1_0$116 ==.
                                   7653 ;	../../fuzzy.h:1932: rules,
      002640 E4               [12] 7654 	clr	a
      002641 C0 E0            [24] 7655 	push	acc
      002643 C0 E0            [24] 7656 	push	acc
      002645 E5 08            [12] 7657 	mov	a,_bp
      002647 24 F1            [12] 7658 	add	a,#0xf1
      002649 F8               [12] 7659 	mov	r0,a
      00264A E6               [12] 7660 	mov	a,@r0
      00264B C0 E0            [24] 7661 	push	acc
      00264D E5 08            [12] 7662 	mov	a,_bp
      00264F 24 F2            [12] 7663 	add	a,#0xf2
      002651 F8               [12] 7664 	mov	r0,a
      002652 E6               [12] 7665 	mov	a,@r0
      002653 C0 E0            [24] 7666 	push	acc
      002655 08               [12] 7667 	inc	r0
      002656 E6               [12] 7668 	mov	a,@r0
      002657 C0 E0            [24] 7669 	push	acc
      002659 08               [12] 7670 	inc	r0
      00265A E6               [12] 7671 	mov	a,@r0
      00265B C0 E0            [24] 7672 	push	acc
      00265D 08               [12] 7673 	inc	r0
      00265E E6               [12] 7674 	mov	a,@r0
      00265F C0 E0            [24] 7675 	push	acc
      002661 E5 08            [12] 7676 	mov	a,_bp
      002663 24 F6            [12] 7677 	add	a,#0xf6
      002665 F8               [12] 7678 	mov	r0,a
      002666 E6               [12] 7679 	mov	a,@r0
      002667 C0 E0            [24] 7680 	push	acc
      002669 08               [12] 7681 	inc	r0
      00266A E6               [12] 7682 	mov	a,@r0
      00266B C0 E0            [24] 7683 	push	acc
      00266D 08               [12] 7684 	inc	r0
      00266E E6               [12] 7685 	mov	a,@r0
      00266F C0 E0            [24] 7686 	push	acc
      002671 08               [12] 7687 	inc	r0
      002672 E6               [12] 7688 	mov	a,@r0
      002673 C0 E0            [24] 7689 	push	acc
      002675 E5 08            [12] 7690 	mov	a,_bp
      002677 24 FA            [12] 7691 	add	a,#0xfa
      002679 F8               [12] 7692 	mov	r0,a
      00267A E6               [12] 7693 	mov	a,@r0
      00267B C0 E0            [24] 7694 	push	acc
      00267D 08               [12] 7695 	inc	r0
      00267E E6               [12] 7696 	mov	a,@r0
      00267F C0 E0            [24] 7697 	push	acc
      002681 08               [12] 7698 	inc	r0
      002682 E6               [12] 7699 	mov	a,@r0
      002683 C0 E0            [24] 7700 	push	acc
      002685 08               [12] 7701 	inc	r0
      002686 E6               [12] 7702 	mov	a,@r0
      002687 C0 E0            [24] 7703 	push	acc
      002689 8D 82            [24] 7704 	mov	dpl, r5
      00268B 8E 83            [24] 7705 	mov	dph, r6
      00268D 8F F0            [24] 7706 	mov	b, r7
      00268F 12 1F E2         [24] 7707 	lcall	_fuzzy_rules_defuzzify_method
      002692 AC 82            [24] 7708 	mov	r4, dpl
      002694 AD 83            [24] 7709 	mov	r5, dph
      002696 AE F0            [24] 7710 	mov	r6, b
      002698 FF               [12] 7711 	mov	r7, a
      002699 E5 81            [12] 7712 	mov	a,sp
      00269B 24 F1            [12] 7713 	add	a,#0xf1
      00269D F5 81            [12] 7714 	mov	sp,a
      00269F 8C 82            [24] 7715 	mov	dpl, r4
      0026A1 8D 83            [24] 7716 	mov	dph, r5
      0026A3 8E F0            [24] 7717 	mov	b, r6
      0026A5 EF               [12] 7718 	mov	a, r7
                           0025EF  7719 	C$fuzzy.h$1940$1_0$116 ==.
                                   7720 ;	../../fuzzy.h:1940: }
      0026A6 D0 08            [24] 7721 	pop	_bp
                           0025F1  7722 	C$fuzzy.h$1940$1_0$116 ==.
                           0025F1  7723 	XG$fuzzy_rules_defuzzify$0$0 ==.
      0026A8 22               [24] 7724 	ret
                                   7725 ;------------------------------------------------------------
                                   7726 ;Allocation info for local variables in function 'fuzzy_rules_cog'
                                   7727 ;------------------------------------------------------------
                                   7728 ;lower         Allocated to stack - _bp -6 +4 
                                   7729 ;upper         Allocated to stack - _bp -10 +4 
                                   7730 ;step          Allocated to stack - _bp -14 +4 
                                   7731 ;rules         Allocated to registers r5 r6 r7 
                                   7732 ;------------------------------------------------------------
                           0025F2  7733 	G$fuzzy_rules_cog$0$0 ==.
                           0025F2  7734 	C$fuzzy.h$1945$1_0$118 ==.
                                   7735 ;	../../fuzzy.h:1945: float fuzzy_rules_cog(
                                   7736 ;	-----------------------------------------
                                   7737 ;	 function fuzzy_rules_cog
                                   7738 ;	-----------------------------------------
      0026A9                       7739 _fuzzy_rules_cog:
      0026A9 C0 08            [24] 7740 	push	_bp
      0026AB 85 81 08         [24] 7741 	mov	_bp,sp
      0026AE AD 82            [24] 7742 	mov	r5, dpl
      0026B0 AE 83            [24] 7743 	mov	r6, dph
      0026B2 AF F0            [24] 7744 	mov	r7, b
                           0025FD  7745 	C$fuzzy.h$1953$1_0$118 ==.
                                   7746 ;	../../fuzzy.h:1953: rules,
      0026B4 E4               [12] 7747 	clr	a
      0026B5 C0 E0            [24] 7748 	push	acc
      0026B7 E5 08            [12] 7749 	mov	a,_bp
      0026B9 24 F2            [12] 7750 	add	a,#0xf2
      0026BB F8               [12] 7751 	mov	r0,a
      0026BC E6               [12] 7752 	mov	a,@r0
      0026BD C0 E0            [24] 7753 	push	acc
      0026BF 08               [12] 7754 	inc	r0
      0026C0 E6               [12] 7755 	mov	a,@r0
      0026C1 C0 E0            [24] 7756 	push	acc
      0026C3 08               [12] 7757 	inc	r0
      0026C4 E6               [12] 7758 	mov	a,@r0
      0026C5 C0 E0            [24] 7759 	push	acc
      0026C7 08               [12] 7760 	inc	r0
      0026C8 E6               [12] 7761 	mov	a,@r0
      0026C9 C0 E0            [24] 7762 	push	acc
      0026CB E5 08            [12] 7763 	mov	a,_bp
      0026CD 24 F6            [12] 7764 	add	a,#0xf6
      0026CF F8               [12] 7765 	mov	r0,a
      0026D0 E6               [12] 7766 	mov	a,@r0
      0026D1 C0 E0            [24] 7767 	push	acc
      0026D3 08               [12] 7768 	inc	r0
      0026D4 E6               [12] 7769 	mov	a,@r0
      0026D5 C0 E0            [24] 7770 	push	acc
      0026D7 08               [12] 7771 	inc	r0
      0026D8 E6               [12] 7772 	mov	a,@r0
      0026D9 C0 E0            [24] 7773 	push	acc
      0026DB 08               [12] 7774 	inc	r0
      0026DC E6               [12] 7775 	mov	a,@r0
      0026DD C0 E0            [24] 7776 	push	acc
      0026DF E5 08            [12] 7777 	mov	a,_bp
      0026E1 24 FA            [12] 7778 	add	a,#0xfa
      0026E3 F8               [12] 7779 	mov	r0,a
      0026E4 E6               [12] 7780 	mov	a,@r0
      0026E5 C0 E0            [24] 7781 	push	acc
      0026E7 08               [12] 7782 	inc	r0
      0026E8 E6               [12] 7783 	mov	a,@r0
      0026E9 C0 E0            [24] 7784 	push	acc
      0026EB 08               [12] 7785 	inc	r0
      0026EC E6               [12] 7786 	mov	a,@r0
      0026ED C0 E0            [24] 7787 	push	acc
      0026EF 08               [12] 7788 	inc	r0
      0026F0 E6               [12] 7789 	mov	a,@r0
      0026F1 C0 E0            [24] 7790 	push	acc
      0026F3 8D 82            [24] 7791 	mov	dpl, r5
      0026F5 8E 83            [24] 7792 	mov	dph, r6
      0026F7 8F F0            [24] 7793 	mov	b, r7
      0026F9 12 26 35         [24] 7794 	lcall	_fuzzy_rules_defuzzify
      0026FC AC 82            [24] 7795 	mov	r4, dpl
      0026FE AD 83            [24] 7796 	mov	r5, dph
      002700 AE F0            [24] 7797 	mov	r6, b
      002702 FF               [12] 7798 	mov	r7, a
      002703 E5 81            [12] 7799 	mov	a,sp
      002705 24 F3            [12] 7800 	add	a,#0xf3
      002707 F5 81            [12] 7801 	mov	sp,a
      002709 8C 82            [24] 7802 	mov	dpl, r4
      00270B 8D 83            [24] 7803 	mov	dph, r5
      00270D 8E F0            [24] 7804 	mov	b, r6
      00270F EF               [12] 7805 	mov	a, r7
                           002659  7806 	C$fuzzy.h$1959$1_0$118 ==.
                                   7807 ;	../../fuzzy.h:1959: }
      002710 D0 08            [24] 7808 	pop	_bp
                           00265B  7809 	C$fuzzy.h$1959$1_0$118 ==.
                           00265B  7810 	XG$fuzzy_rules_cog$0$0 ==.
      002712 22               [24] 7811 	ret
                                   7812 ;------------------------------------------------------------
                                   7813 ;Allocation info for local variables in function 'fuzzy_rules_free'
                                   7814 ;------------------------------------------------------------
                                   7815 ;rules         Allocated to registers r5 r6 r7 
                                   7816 ;------------------------------------------------------------
                           00265C  7817 	G$fuzzy_rules_free$0$0 ==.
                           00265C  7818 	C$fuzzy.h$1961$1_0$120 ==.
                                   7819 ;	../../fuzzy.h:1961: void fuzzy_rules_free(fuzzy_rules_t *rules)
                                   7820 ;	-----------------------------------------
                                   7821 ;	 function fuzzy_rules_free
                                   7822 ;	-----------------------------------------
      002713                       7823 _fuzzy_rules_free:
      002713 AD 82            [24] 7824 	mov	r5, dpl
      002715 AE 83            [24] 7825 	mov	r6, dph
      002717 AF F0            [24] 7826 	mov	r7, b
                           002662  7827 	C$fuzzy.h$1963$1_0$120 ==.
                                   7828 ;	../../fuzzy.h:1963: if (rules == NULL) return;
      002719 ED               [12] 7829 	mov	a,r5
      00271A 4E               [12] 7830 	orl	a,r6
      00271B 70 02            [24] 7831 	jnz	00102$
      00271D 80 15            [24] 7832 	sjmp	00103$
      00271F                       7833 00102$:
                           002668  7834 	C$fuzzy.h$1970$1_0$120 ==.
                                   7835 ;	../../fuzzy.h:1970: rules->count = 0;
      00271F 74 90            [12] 7836 	mov	a,#0x90
      002721 2D               [12] 7837 	add	a, r5
      002722 FD               [12] 7838 	mov	r5,a
      002723 E4               [12] 7839 	clr	a
      002724 3E               [12] 7840 	addc	a, r6
      002725 FE               [12] 7841 	mov	r6,a
      002726 8D 82            [24] 7842 	mov	dpl,r5
      002728 8E 83            [24] 7843 	mov	dph,r6
      00272A 8F F0            [24] 7844 	mov	b,r7
      00272C E4               [12] 7845 	clr	a
      00272D 12 2B E3         [24] 7846 	lcall	__gptrput
      002730 A3               [24] 7847 	inc	dptr
      002731 12 2B E3         [24] 7848 	lcall	__gptrput
      002734                       7849 00103$:
                           00267D  7850 	C$fuzzy.h$1971$1_0$120 ==.
                                   7851 ;	../../fuzzy.h:1971: }
                           00267D  7852 	C$fuzzy.h$1971$1_0$120 ==.
                           00267D  7853 	XG$fuzzy_rules_free$0$0 ==.
      002734 22               [24] 7854 	ret
                                   7855 ;------------------------------------------------------------
                                   7856 ;Allocation info for local variables in function 'temperature_low'
                                   7857 ;------------------------------------------------------------
                                   7858 ;value         Allocated to registers r4 r5 r6 r7 
                                   7859 ;------------------------------------------------------------
                           00267E  7860 	Fcontroller_8051$temperature_low$0$0 ==.
                           00267E  7861 	C$controller_8051.c$59$1_0$122 ==.
                                   7862 ;	../../controller_8051.c:59: static float temperature_low(
                                   7863 ;	-----------------------------------------
                                   7864 ;	 function temperature_low
                                   7865 ;	-----------------------------------------
      002735                       7866 _temperature_low:
      002735 AC 82            [24] 7867 	mov	r4,dpl
      002737 AD 83            [24] 7868 	mov	r5,dph
      002739 AE F0            [24] 7869 	mov	r6,b
      00273B FF               [12] 7870 	mov	r7,a
                           002685  7871 	C$controller_8051.c$68$1_0$122 ==.
                                   7872 ;	../../controller_8051.c:68: hedges.none
      00273C 90 2E EC         [24] 7873 	mov	dptr,#_hedges
      00273F E4               [12] 7874 	clr	a
      002740 93               [24] 7875 	movc	a,@a+dptr
      002741 FB               [12] 7876 	mov	r3,a
                           00268B  7877 	C$controller_8051.c$64$1_0$122 ==.
                                   7878 ;	../../controller_8051.c:64: 20.0f,
      002742 C0 03            [24] 7879 	push	ar3
      002744 E4               [12] 7880 	clr	a
      002745 C0 E0            [24] 7881 	push	acc
      002747 C0 04            [24] 7882 	push	ar4
      002749 C0 05            [24] 7883 	push	ar5
      00274B C0 06            [24] 7884 	push	ar6
      00274D C0 07            [24] 7885 	push	ar7
      00274F C0 E0            [24] 7886 	push	acc
      002751 C0 E0            [24] 7887 	push	acc
      002753 74 20            [12] 7888 	mov	a,#0x20
      002755 C0 E0            [24] 7889 	push	acc
      002757 74 42            [12] 7890 	mov	a,#0x42
      002759 C0 E0            [24] 7891 	push	acc
      00275B 90 00 00         [24] 7892 	mov	dptr,#0x0000
      00275E 75 F0 A0         [24] 7893 	mov	b, #0xa0
      002761 14               [12] 7894 	dec	a
      002762 12 0A EC         [24] 7895 	lcall	_fuzzy_ramp
      002765 AC 82            [24] 7896 	mov	r4, dpl
      002767 AD 83            [24] 7897 	mov	r5, dph
      002769 AE F0            [24] 7898 	mov	r6, b
      00276B FF               [12] 7899 	mov	r7, a
      00276C E5 81            [12] 7900 	mov	a,sp
      00276E 24 F6            [12] 7901 	add	a,#0xf6
      002770 F5 81            [12] 7902 	mov	sp,a
      002772 8C 82            [24] 7903 	mov	dpl, r4
      002774 8D 83            [24] 7904 	mov	dph, r5
      002776 8E F0            [24] 7905 	mov	b, r6
      002778 EF               [12] 7906 	mov	a, r7
                           0026C2  7907 	C$controller_8051.c$70$1_0$122 ==.
                                   7908 ;	../../controller_8051.c:70: }
                           0026C2  7909 	C$controller_8051.c$70$1_0$122 ==.
                           0026C2  7910 	XFcontroller_8051$temperature_low$0$0 ==.
      002779 22               [24] 7911 	ret
                                   7912 ;------------------------------------------------------------
                                   7913 ;Allocation info for local variables in function 'temperature_high'
                                   7914 ;------------------------------------------------------------
                                   7915 ;value         Allocated to registers r4 r5 r6 r7 
                                   7916 ;------------------------------------------------------------
                           0026C3  7917 	Fcontroller_8051$temperature_high$0$0 ==.
                           0026C3  7918 	C$controller_8051.c$73$1_0$124 ==.
                                   7919 ;	../../controller_8051.c:73: static float temperature_high(
                                   7920 ;	-----------------------------------------
                                   7921 ;	 function temperature_high
                                   7922 ;	-----------------------------------------
      00277A                       7923 _temperature_high:
      00277A AC 82            [24] 7924 	mov	r4,dpl
      00277C AD 83            [24] 7925 	mov	r5,dph
      00277E AE F0            [24] 7926 	mov	r6,b
      002780 FF               [12] 7927 	mov	r7,a
                           0026CA  7928 	C$controller_8051.c$82$1_0$124 ==.
                                   7929 ;	../../controller_8051.c:82: hedges.none
      002781 90 2E EC         [24] 7930 	mov	dptr,#_hedges
      002784 E4               [12] 7931 	clr	a
      002785 93               [24] 7932 	movc	a,@a+dptr
      002786 FB               [12] 7933 	mov	r3,a
                           0026D0  7934 	C$controller_8051.c$78$1_0$124 ==.
                                   7935 ;	../../controller_8051.c:78: 30.0f,
      002787 C0 03            [24] 7936 	push	ar3
      002789 74 01            [12] 7937 	mov	a,#0x01
      00278B C0 E0            [24] 7938 	push	acc
      00278D C0 04            [24] 7939 	push	ar4
      00278F C0 05            [24] 7940 	push	ar5
      002791 C0 06            [24] 7941 	push	ar6
      002793 C0 07            [24] 7942 	push	ar7
      002795 E4               [12] 7943 	clr	a
      002796 C0 E0            [24] 7944 	push	acc
      002798 C0 E0            [24] 7945 	push	acc
      00279A 74 70            [12] 7946 	mov	a,#0x70
      00279C C0 E0            [24] 7947 	push	acc
      00279E 74 42            [12] 7948 	mov	a,#0x42
      0027A0 C0 E0            [24] 7949 	push	acc
      0027A2 90 00 00         [24] 7950 	mov	dptr,#0x0000
      0027A5 75 F0 F0         [24] 7951 	mov	b, #0xf0
      0027A8 14               [12] 7952 	dec	a
      0027A9 12 0A EC         [24] 7953 	lcall	_fuzzy_ramp
      0027AC AC 82            [24] 7954 	mov	r4, dpl
      0027AE AD 83            [24] 7955 	mov	r5, dph
      0027B0 AE F0            [24] 7956 	mov	r6, b
      0027B2 FF               [12] 7957 	mov	r7, a
      0027B3 E5 81            [12] 7958 	mov	a,sp
      0027B5 24 F6            [12] 7959 	add	a,#0xf6
      0027B7 F5 81            [12] 7960 	mov	sp,a
      0027B9 8C 82            [24] 7961 	mov	dpl, r4
      0027BB 8D 83            [24] 7962 	mov	dph, r5
      0027BD 8E F0            [24] 7963 	mov	b, r6
      0027BF EF               [12] 7964 	mov	a, r7
                           002709  7965 	C$controller_8051.c$84$1_0$124 ==.
                                   7966 ;	../../controller_8051.c:84: }
                           002709  7967 	C$controller_8051.c$84$1_0$124 ==.
                           002709  7968 	XFcontroller_8051$temperature_high$0$0 ==.
      0027C0 22               [24] 7969 	ret
                                   7970 ;------------------------------------------------------------
                                   7971 ;Allocation info for local variables in function 'fan_slow'
                                   7972 ;------------------------------------------------------------
                                   7973 ;value         Allocated to registers r4 r5 r6 r7 
                                   7974 ;------------------------------------------------------------
                           00270A  7975 	Fcontroller_8051$fan_slow$0$0 ==.
                           00270A  7976 	C$controller_8051.c$91$1_0$126 ==.
                                   7977 ;	../../controller_8051.c:91: static float fan_slow(
                                   7978 ;	-----------------------------------------
                                   7979 ;	 function fan_slow
                                   7980 ;	-----------------------------------------
      0027C1                       7981 _fan_slow:
      0027C1 AC 82            [24] 7982 	mov	r4,dpl
      0027C3 AD 83            [24] 7983 	mov	r5,dph
      0027C5 AE F0            [24] 7984 	mov	r6,b
      0027C7 FF               [12] 7985 	mov	r7,a
                           002711  7986 	C$controller_8051.c$100$1_0$126 ==.
                                   7987 ;	../../controller_8051.c:100: hedges.none
      0027C8 90 2E EC         [24] 7988 	mov	dptr,#_hedges
      0027CB E4               [12] 7989 	clr	a
      0027CC 93               [24] 7990 	movc	a,@a+dptr
      0027CD FB               [12] 7991 	mov	r3,a
                           002717  7992 	C$controller_8051.c$96$1_0$126 ==.
                                   7993 ;	../../controller_8051.c:96: 20.0f,
      0027CE C0 03            [24] 7994 	push	ar3
      0027D0 E4               [12] 7995 	clr	a
      0027D1 C0 E0            [24] 7996 	push	acc
      0027D3 C0 04            [24] 7997 	push	ar4
      0027D5 C0 05            [24] 7998 	push	ar5
      0027D7 C0 06            [24] 7999 	push	ar6
      0027D9 C0 07            [24] 8000 	push	ar7
      0027DB C0 E0            [24] 8001 	push	acc
      0027DD C0 E0            [24] 8002 	push	acc
      0027DF 74 48            [12] 8003 	mov	a,#0x48
      0027E1 C0 E0            [24] 8004 	push	acc
      0027E3 74 42            [12] 8005 	mov	a,#0x42
      0027E5 C0 E0            [24] 8006 	push	acc
      0027E7 90 00 00         [24] 8007 	mov	dptr,#0x0000
      0027EA 75 F0 A0         [24] 8008 	mov	b, #0xa0
      0027ED 14               [12] 8009 	dec	a
      0027EE 12 0A EC         [24] 8010 	lcall	_fuzzy_ramp
      0027F1 AC 82            [24] 8011 	mov	r4, dpl
      0027F3 AD 83            [24] 8012 	mov	r5, dph
      0027F5 AE F0            [24] 8013 	mov	r6, b
      0027F7 FF               [12] 8014 	mov	r7, a
      0027F8 E5 81            [12] 8015 	mov	a,sp
      0027FA 24 F6            [12] 8016 	add	a,#0xf6
      0027FC F5 81            [12] 8017 	mov	sp,a
      0027FE 8C 82            [24] 8018 	mov	dpl, r4
      002800 8D 83            [24] 8019 	mov	dph, r5
      002802 8E F0            [24] 8020 	mov	b, r6
      002804 EF               [12] 8021 	mov	a, r7
                           00274E  8022 	C$controller_8051.c$102$1_0$126 ==.
                                   8023 ;	../../controller_8051.c:102: }
                           00274E  8024 	C$controller_8051.c$102$1_0$126 ==.
                           00274E  8025 	XFcontroller_8051$fan_slow$0$0 ==.
      002805 22               [24] 8026 	ret
                                   8027 ;------------------------------------------------------------
                                   8028 ;Allocation info for local variables in function 'fan_fast'
                                   8029 ;------------------------------------------------------------
                                   8030 ;value         Allocated to registers r4 r5 r6 r7 
                                   8031 ;------------------------------------------------------------
                           00274F  8032 	Fcontroller_8051$fan_fast$0$0 ==.
                           00274F  8033 	C$controller_8051.c$105$1_0$128 ==.
                                   8034 ;	../../controller_8051.c:105: static float fan_fast(
                                   8035 ;	-----------------------------------------
                                   8036 ;	 function fan_fast
                                   8037 ;	-----------------------------------------
      002806                       8038 _fan_fast:
      002806 AC 82            [24] 8039 	mov	r4,dpl
      002808 AD 83            [24] 8040 	mov	r5,dph
      00280A AE F0            [24] 8041 	mov	r6,b
      00280C FF               [12] 8042 	mov	r7,a
                           002756  8043 	C$controller_8051.c$114$1_0$128 ==.
                                   8044 ;	../../controller_8051.c:114: hedges.none
      00280D 90 2E EC         [24] 8045 	mov	dptr,#_hedges
      002810 E4               [12] 8046 	clr	a
      002811 93               [24] 8047 	movc	a,@a+dptr
      002812 FB               [12] 8048 	mov	r3,a
                           00275C  8049 	C$controller_8051.c$110$1_0$128 ==.
                                   8050 ;	../../controller_8051.c:110: 40.0f,
      002813 C0 03            [24] 8051 	push	ar3
      002815 74 01            [12] 8052 	mov	a,#0x01
      002817 C0 E0            [24] 8053 	push	acc
      002819 C0 04            [24] 8054 	push	ar4
      00281B C0 05            [24] 8055 	push	ar5
      00281D C0 06            [24] 8056 	push	ar6
      00281F C0 07            [24] 8057 	push	ar7
      002821 E4               [12] 8058 	clr	a
      002822 C0 E0            [24] 8059 	push	acc
      002824 C0 E0            [24] 8060 	push	acc
      002826 74 A0            [12] 8061 	mov	a,#0xa0
      002828 C0 E0            [24] 8062 	push	acc
      00282A 74 42            [12] 8063 	mov	a,#0x42
      00282C C0 E0            [24] 8064 	push	acc
      00282E 90 00 00         [24] 8065 	mov	dptr,#0x0000
      002831 75 F0 20         [24] 8066 	mov	b, #0x20
      002834 12 0A EC         [24] 8067 	lcall	_fuzzy_ramp
      002837 AC 82            [24] 8068 	mov	r4, dpl
      002839 AD 83            [24] 8069 	mov	r5, dph
      00283B AE F0            [24] 8070 	mov	r6, b
      00283D FF               [12] 8071 	mov	r7, a
      00283E E5 81            [12] 8072 	mov	a,sp
      002840 24 F6            [12] 8073 	add	a,#0xf6
      002842 F5 81            [12] 8074 	mov	sp,a
      002844 8C 82            [24] 8075 	mov	dpl, r4
      002846 8D 83            [24] 8076 	mov	dph, r5
      002848 8E F0            [24] 8077 	mov	b, r6
      00284A EF               [12] 8078 	mov	a, r7
                           002794  8079 	C$controller_8051.c$116$1_0$128 ==.
                                   8080 ;	../../controller_8051.c:116: }
                           002794  8081 	C$controller_8051.c$116$1_0$128 ==.
                           002794  8082 	XFcontroller_8051$fan_fast$0$0 ==.
      00284B 22               [24] 8083 	ret
                                   8084 ;------------------------------------------------------------
                                   8085 ;Allocation info for local variables in function 'calculate_fan_speed'
                                   8086 ;------------------------------------------------------------
                                   8087 ;temperature   Allocated to stack - _bp +1 +4 
                                   8088 ;rules         Allocated to stack - _bp +9 +146 
                                   8089 ;result        Allocated to stack - _bp +155 +4 
                                   8090 ;sloc0         Allocated to stack - _bp +5 +4 
                                   8091 ;------------------------------------------------------------
                           002795  8092 	Fcontroller_8051$calculate_fan_speed$0$0 ==.
                           002795  8093 	C$controller_8051.c$123$1_0$130 ==.
                                   8094 ;	../../controller_8051.c:123: static float calculate_fan_speed(
                                   8095 ;	-----------------------------------------
                                   8096 ;	 function calculate_fan_speed
                                   8097 ;	-----------------------------------------
      00284C                       8098 _calculate_fan_speed:
      00284C C0 08            [24] 8099 	push	_bp
      00284E 85 81 08         [24] 8100 	mov	_bp,sp
      002851 C0 82            [24] 8101 	push	dpl
      002853 C0 83            [24] 8102 	push	dph
      002855 C0 F0            [24] 8103 	push	b
      002857 C0 E0            [24] 8104 	push	acc
      002859 E5 81            [12] 8105 	mov	a,sp
      00285B 24 9A            [12] 8106 	add	a,#0x9a
      00285D F5 81            [12] 8107 	mov	sp,a
                           0027A8  8108 	C$controller_8051.c$132$1_0$130 ==.
                                   8109 ;	../../controller_8051.c:132: );
      00285F E5 08            [12] 8110 	mov	a,_bp
      002861 24 09            [12] 8111 	add	a,#0x09
      002863 FB               [12] 8112 	mov	r3,a
      002864 FA               [12] 8113 	mov	r2,a
      002865 7E 00            [12] 8114 	mov	r6,#0x00
      002867 7F 40            [12] 8115 	mov	r7,#0x40
      002869 8A 82            [24] 8116 	mov	dpl, r2
      00286B 8E 83            [24] 8117 	mov	dph, r6
      00286D 8F F0            [24] 8118 	mov	b, r7
      00286F C0 03            [24] 8119 	push	ar3
      002871 12 1B 95         [24] 8120 	lcall	_fuzzy_rules_create
                           0027BD  8121 	C$controller_8051.c$134$1_0$130 ==.
                                   8122 ;	../../controller_8051.c:134: if (!FUZZY_RULE_ADD(
      002874 A8 08            [24] 8123 	mov	r0,_bp
      002876 08               [12] 8124 	inc	r0
      002877 86 82            [24] 8125 	mov	dpl, @r0
      002879 08               [12] 8126 	inc	r0
      00287A 86 83            [24] 8127 	mov	dph, @r0
      00287C 08               [12] 8128 	inc	r0
      00287D 86 F0            [24] 8129 	mov	b, @r0
      00287F 08               [12] 8130 	inc	r0
      002880 E6               [12] 8131 	mov	a, @r0
      002881 12 27 35         [24] 8132 	lcall	_temperature_low
      002884 C8               [12] 8133 	xch	a,r0
      002885 E5 08            [12] 8134 	mov	a,_bp
      002887 24 05            [12] 8135 	add	a,#0x05
      002889 C8               [12] 8136 	xch	a,r0
      00288A A6 82            [24] 8137 	mov	@r0, dpl
      00288C 08               [12] 8138 	inc	r0
      00288D A6 83            [24] 8139 	mov	@r0, dph
      00288F 08               [12] 8140 	inc	r0
      002890 A6 F0            [24] 8141 	mov	@r0, b
      002892 08               [12] 8142 	inc	r0
      002893 F6               [12] 8143 	mov	@r0,a
      002894 D0 03            [24] 8144 	pop	ar3
      002896 8B 02            [24] 8145 	mov	ar2,r3
      002898 7E 00            [12] 8146 	mov	r6,#0x00
      00289A 7F 40            [12] 8147 	mov	r7,#0x40
      00289C C0 03            [24] 8148 	push	ar3
      00289E 74 C1            [12] 8149 	mov	a,#_fan_slow
      0028A0 C0 E0            [24] 8150 	push	acc
      0028A2 74 27            [12] 8151 	mov	a,#(_fan_slow >> 8)
      0028A4 C0 E0            [24] 8152 	push	acc
      0028A6 E5 08            [12] 8153 	mov	a,_bp
      0028A8 24 05            [12] 8154 	add	a,#0x05
      0028AA F8               [12] 8155 	mov	r0,a
      0028AB E6               [12] 8156 	mov	a,@r0
      0028AC C0 E0            [24] 8157 	push	acc
      0028AE 08               [12] 8158 	inc	r0
      0028AF E6               [12] 8159 	mov	a,@r0
      0028B0 C0 E0            [24] 8160 	push	acc
      0028B2 08               [12] 8161 	inc	r0
      0028B3 E6               [12] 8162 	mov	a,@r0
      0028B4 C0 E0            [24] 8163 	push	acc
      0028B6 08               [12] 8164 	inc	r0
      0028B7 E6               [12] 8165 	mov	a,@r0
      0028B8 C0 E0            [24] 8166 	push	acc
      0028BA 74 EF            [12] 8167 	mov	a,#___str_0
      0028BC C0 E0            [24] 8168 	push	acc
      0028BE 74 2E            [12] 8169 	mov	a,#(___str_0 >> 8)
      0028C0 C0 E0            [24] 8170 	push	acc
      0028C2 74 80            [12] 8171 	mov	a,#0x80
      0028C4 C0 E0            [24] 8172 	push	acc
      0028C6 8A 82            [24] 8173 	mov	dpl, r2
      0028C8 8E 83            [24] 8174 	mov	dph, r6
      0028CA 8F F0            [24] 8175 	mov	b, r7
      0028CC 12 1B B7         [24] 8176 	lcall	_fuzzy_rules_add
      0028CF AF 82            [24] 8177 	mov	r7, dpl
      0028D1 E5 81            [12] 8178 	mov	a,sp
      0028D3 24 F7            [12] 8179 	add	a,#0xf7
      0028D5 F5 81            [12] 8180 	mov	sp,a
      0028D7 D0 03            [24] 8181 	pop	ar3
      0028D9 EF               [12] 8182 	mov	a,r7
                           002823  8183 	C$controller_8051.c$141$2_0$131 ==.
                                   8184 ;	../../controller_8051.c:141: );
      0028DA 70 17            [24] 8185 	jnz	00102$
      0028DC 8B 05            [24] 8186 	mov	ar5,r3
      0028DE FE               [12] 8187 	mov	r6,a
      0028DF 7F 40            [12] 8188 	mov	r7,#0x40
      0028E1 8D 82            [24] 8189 	mov	dpl, r5
      0028E3 8E 83            [24] 8190 	mov	dph, r6
      0028E5 8F F0            [24] 8191 	mov	b, r7
      0028E7 12 27 13         [24] 8192 	lcall	_fuzzy_rules_free
                           002833  8193 	C$controller_8051.c$143$2_0$131 ==.
                                   8194 ;	../../controller_8051.c:143: return 0.0f;
      0028EA 90 00 00         [24] 8195 	mov	dptr,#0x0000
      0028ED E4               [12] 8196 	clr	a
      0028EE F5 F0            [12] 8197 	mov	b,a
      0028F0 02 29 E1         [24] 8198 	ljmp	00105$
      0028F3                       8199 00102$:
                           00283C  8200 	C$controller_8051.c$146$1_0$130 ==.
                                   8201 ;	../../controller_8051.c:146: if (!FUZZY_RULE_ADD(
      0028F3 A8 08            [24] 8202 	mov	r0,_bp
      0028F5 08               [12] 8203 	inc	r0
      0028F6 86 82            [24] 8204 	mov	dpl, @r0
      0028F8 08               [12] 8205 	inc	r0
      0028F9 86 83            [24] 8206 	mov	dph, @r0
      0028FB 08               [12] 8207 	inc	r0
      0028FC 86 F0            [24] 8208 	mov	b, @r0
      0028FE 08               [12] 8209 	inc	r0
      0028FF E6               [12] 8210 	mov	a, @r0
      002900 C0 03            [24] 8211 	push	ar3
      002902 12 27 7A         [24] 8212 	lcall	_temperature_high
      002905 C8               [12] 8213 	xch	a,r0
      002906 E5 08            [12] 8214 	mov	a,_bp
      002908 24 05            [12] 8215 	add	a,#0x05
      00290A C8               [12] 8216 	xch	a,r0
      00290B A6 82            [24] 8217 	mov	@r0, dpl
      00290D 08               [12] 8218 	inc	r0
      00290E A6 83            [24] 8219 	mov	@r0, dph
      002910 08               [12] 8220 	inc	r0
      002911 A6 F0            [24] 8221 	mov	@r0, b
      002913 08               [12] 8222 	inc	r0
      002914 F6               [12] 8223 	mov	@r0,a
      002915 D0 03            [24] 8224 	pop	ar3
      002917 8B 02            [24] 8225 	mov	ar2,r3
      002919 7E 00            [12] 8226 	mov	r6,#0x00
      00291B 7F 40            [12] 8227 	mov	r7,#0x40
      00291D C0 03            [24] 8228 	push	ar3
      00291F 74 06            [12] 8229 	mov	a,#_fan_fast
      002921 C0 E0            [24] 8230 	push	acc
      002923 74 28            [12] 8231 	mov	a,#(_fan_fast >> 8)
      002925 C0 E0            [24] 8232 	push	acc
      002927 E5 08            [12] 8233 	mov	a,_bp
      002929 24 05            [12] 8234 	add	a,#0x05
      00292B F8               [12] 8235 	mov	r0,a
      00292C E6               [12] 8236 	mov	a,@r0
      00292D C0 E0            [24] 8237 	push	acc
      00292F 08               [12] 8238 	inc	r0
      002930 E6               [12] 8239 	mov	a,@r0
      002931 C0 E0            [24] 8240 	push	acc
      002933 08               [12] 8241 	inc	r0
      002934 E6               [12] 8242 	mov	a,@r0
      002935 C0 E0            [24] 8243 	push	acc
      002937 08               [12] 8244 	inc	r0
      002938 E6               [12] 8245 	mov	a,@r0
      002939 C0 E0            [24] 8246 	push	acc
      00293B 74 F8            [12] 8247 	mov	a,#___str_1
      00293D C0 E0            [24] 8248 	push	acc
      00293F 74 2E            [12] 8249 	mov	a,#(___str_1 >> 8)
      002941 C0 E0            [24] 8250 	push	acc
      002943 74 80            [12] 8251 	mov	a,#0x80
      002945 C0 E0            [24] 8252 	push	acc
      002947 8A 82            [24] 8253 	mov	dpl, r2
      002949 8E 83            [24] 8254 	mov	dph, r6
      00294B 8F F0            [24] 8255 	mov	b, r7
      00294D 12 1B B7         [24] 8256 	lcall	_fuzzy_rules_add
      002950 AF 82            [24] 8257 	mov	r7, dpl
      002952 E5 81            [12] 8258 	mov	a,sp
      002954 24 F7            [12] 8259 	add	a,#0xf7
      002956 F5 81            [12] 8260 	mov	sp,a
      002958 D0 03            [24] 8261 	pop	ar3
      00295A EF               [12] 8262 	mov	a,r7
                           0028A4  8263 	C$controller_8051.c$153$2_0$132 ==.
                                   8264 ;	../../controller_8051.c:153: );
      00295B 70 16            [24] 8265 	jnz	00104$
      00295D 8B 05            [24] 8266 	mov	ar5,r3
      00295F FE               [12] 8267 	mov	r6,a
      002960 7F 40            [12] 8268 	mov	r7,#0x40
      002962 8D 82            [24] 8269 	mov	dpl, r5
      002964 8E 83            [24] 8270 	mov	dph, r6
      002966 8F F0            [24] 8271 	mov	b, r7
      002968 12 27 13         [24] 8272 	lcall	_fuzzy_rules_free
                           0028B4  8273 	C$controller_8051.c$155$2_0$132 ==.
                                   8274 ;	../../controller_8051.c:155: return 0.0f;
      00296B 90 00 00         [24] 8275 	mov	dptr,#0x0000
      00296E E4               [12] 8276 	clr	a
      00296F F5 F0            [12] 8277 	mov	b,a
      002971 80 6E            [24] 8278 	sjmp	00105$
      002973                       8279 00104$:
                           0028BC  8280 	C$controller_8051.c$160$1_0$130 ==.
                                   8281 ;	../../controller_8051.c:160: &rules,
      002973 8B 05            [24] 8282 	mov	ar5,r3
      002975 7E 00            [12] 8283 	mov	r6,#0x00
      002977 7F 40            [12] 8284 	mov	r7,#0x40
      002979 C0 03            [24] 8285 	push	ar3
      00297B 74 01            [12] 8286 	mov	a,#0x01
      00297D C0 E0            [24] 8287 	push	acc
      00297F E4               [12] 8288 	clr	a
      002980 C0 E0            [24] 8289 	push	acc
      002982 C0 E0            [24] 8290 	push	acc
      002984 74 20            [12] 8291 	mov	a,#0x20
      002986 C0 E0            [24] 8292 	push	acc
      002988 74 41            [12] 8293 	mov	a,#0x41
      00298A C0 E0            [24] 8294 	push	acc
      00298C E4               [12] 8295 	clr	a
      00298D C0 E0            [24] 8296 	push	acc
      00298F C0 E0            [24] 8297 	push	acc
      002991 74 C8            [12] 8298 	mov	a,#0xc8
      002993 C0 E0            [24] 8299 	push	acc
      002995 74 42            [12] 8300 	mov	a,#0x42
      002997 C0 E0            [24] 8301 	push	acc
      002999 E4               [12] 8302 	clr	a
      00299A C0 E0            [24] 8303 	push	acc
      00299C C0 E0            [24] 8304 	push	acc
      00299E C0 E0            [24] 8305 	push	acc
      0029A0 C0 E0            [24] 8306 	push	acc
      0029A2 8D 82            [24] 8307 	mov	dpl, r5
      0029A4 8E 83            [24] 8308 	mov	dph, r6
      0029A6 8F F0            [24] 8309 	mov	b, r7
      0029A8 12 26 35         [24] 8310 	lcall	_fuzzy_rules_defuzzify
      0029AB C8               [12] 8311 	xch	a,r0
      0029AC E5 08            [12] 8312 	mov	a,_bp
      0029AE 24 9B            [12] 8313 	add	a,#0x9b
      0029B0 C8               [12] 8314 	xch	a,r0
      0029B1 A6 82            [24] 8315 	mov	@r0, dpl
      0029B3 08               [12] 8316 	inc	r0
      0029B4 A6 83            [24] 8317 	mov	@r0, dph
      0029B6 08               [12] 8318 	inc	r0
      0029B7 A6 F0            [24] 8319 	mov	@r0, b
      0029B9 08               [12] 8320 	inc	r0
      0029BA F6               [12] 8321 	mov	@r0,a
      0029BB E5 81            [12] 8322 	mov	a,sp
      0029BD 24 F3            [12] 8323 	add	a,#0xf3
      0029BF F5 81            [12] 8324 	mov	sp,a
      0029C1 D0 03            [24] 8325 	pop	ar3
                           00290C  8326 	C$controller_8051.c$169$1_0$130 ==.
                                   8327 ;	../../controller_8051.c:169: );
      0029C3 8B 02            [24] 8328 	mov	ar2,r3
      0029C5 7B 00            [12] 8329 	mov	r3,#0x00
      0029C7 7F 40            [12] 8330 	mov	r7,#0x40
      0029C9 8A 82            [24] 8331 	mov	dpl, r2
      0029CB 8B 83            [24] 8332 	mov	dph, r3
      0029CD 8F F0            [24] 8333 	mov	b, r7
      0029CF 12 27 13         [24] 8334 	lcall	_fuzzy_rules_free
                           00291B  8335 	C$controller_8051.c$171$1_0$130 ==.
                                   8336 ;	../../controller_8051.c:171: return result;
      0029D2 E5 08            [12] 8337 	mov	a,_bp
      0029D4 24 9B            [12] 8338 	add	a,#0x9b
      0029D6 F8               [12] 8339 	mov	r0,a
      0029D7 86 82            [24] 8340 	mov	dpl, @r0
      0029D9 08               [12] 8341 	inc	r0
      0029DA 86 83            [24] 8342 	mov	dph, @r0
      0029DC 08               [12] 8343 	inc	r0
      0029DD 86 F0            [24] 8344 	mov	b, @r0
      0029DF 08               [12] 8345 	inc	r0
      0029E0 E6               [12] 8346 	mov	a, @r0
      0029E1                       8347 00105$:
                           00292A  8348 	C$controller_8051.c$172$1_0$130 ==.
                                   8349 ;	../../controller_8051.c:172: }
      0029E1 85 08 81         [24] 8350 	mov	sp,_bp
      0029E4 D0 08            [24] 8351 	pop	_bp
                           00292F  8352 	C$controller_8051.c$172$1_0$130 ==.
                           00292F  8353 	XFcontroller_8051$calculate_fan_speed$0$0 ==.
      0029E6 22               [24] 8354 	ret
                                   8355 ;------------------------------------------------------------
                                   8356 ;Allocation info for local variables in function 'fan_speed_to_pwm'
                                   8357 ;------------------------------------------------------------
                                   8358 ;fan_speed     Allocated to registers r4 r5 r6 r7 
                                   8359 ;------------------------------------------------------------
                           002930  8360 	Fcontroller_8051$fan_speed_to_pwm$0$0 ==.
                           002930  8361 	C$controller_8051.c$179$1_0$134 ==.
                                   8362 ;	../../controller_8051.c:179: static unsigned char fan_speed_to_pwm(
                                   8363 ;	-----------------------------------------
                                   8364 ;	 function fan_speed_to_pwm
                                   8365 ;	-----------------------------------------
      0029E7                       8366 _fan_speed_to_pwm:
      0029E7 AC 82            [24] 8367 	mov	r4,dpl
      0029E9 AD 83            [24] 8368 	mov	r5,dph
      0029EB AE F0            [24] 8369 	mov	r6,b
      0029ED FF               [12] 8370 	mov	r7,a
                           002937  8371 	C$controller_8051.c$183$1_0$134 ==.
                                   8372 ;	../../controller_8051.c:183: if (fan_speed <= 0.0f) {
      0029EE C0 07            [24] 8373 	push	ar7
      0029F0 C0 06            [24] 8374 	push	ar6
      0029F2 C0 05            [24] 8375 	push	ar5
      0029F4 C0 04            [24] 8376 	push	ar4
      0029F6 C0 04            [24] 8377 	push	ar4
      0029F8 C0 05            [24] 8378 	push	ar5
      0029FA C0 06            [24] 8379 	push	ar6
      0029FC C0 07            [24] 8380 	push	ar7
      0029FE 90 00 00         [24] 8381 	mov	dptr,#0x0000
      002A01 E4               [12] 8382 	clr	a
      002A02 F5 F0            [12] 8383 	mov	b,a
      002A04 12 2B FE         [24] 8384 	lcall	___fslt
      002A07 E5 81            [12] 8385 	mov	a,sp
      002A09 24 FC            [12] 8386 	add	a,#0xfc
      002A0B F5 81            [12] 8387 	mov	sp,a
      002A0D D0 04            [24] 8388 	pop	ar4
      002A0F D0 05            [24] 8389 	pop	ar5
      002A11 D0 06            [24] 8390 	pop	ar6
      002A13 D0 07            [24] 8391 	pop	ar7
      002A15 E5 82            [12] 8392 	mov	a, dpl
      002A17 24 FF            [12] 8393 	add	a,#0xff
      002A19 92 00            [24] 8394 	mov	b0,c
      002A1B 40 05            [24] 8395 	jc	00102$
                           002966  8396 	C$controller_8051.c$184$2_0$135 ==.
                                   8397 ;	../../controller_8051.c:184: return 0u;
      002A1D 75 82 00         [24] 8398 	mov	dpl, #0x00
      002A20 80 66            [24] 8399 	sjmp	00105$
      002A22                       8400 00102$:
                           00296B  8401 	C$controller_8051.c$187$1_0$134 ==.
                                   8402 ;	../../controller_8051.c:187: if (fan_speed >= 100.0f) {
      002A22 C0 07            [24] 8403 	push	ar7
      002A24 C0 06            [24] 8404 	push	ar6
      002A26 C0 05            [24] 8405 	push	ar5
      002A28 C0 04            [24] 8406 	push	ar4
      002A2A E4               [12] 8407 	clr	a
      002A2B C0 E0            [24] 8408 	push	acc
      002A2D C0 E0            [24] 8409 	push	acc
      002A2F 74 C8            [12] 8410 	mov	a,#0xc8
      002A31 C0 E0            [24] 8411 	push	acc
      002A33 74 42            [12] 8412 	mov	a,#0x42
      002A35 C0 E0            [24] 8413 	push	acc
      002A37 8C 82            [24] 8414 	mov	dpl, r4
      002A39 8D 83            [24] 8415 	mov	dph, r5
      002A3B 8E F0            [24] 8416 	mov	b, r6
      002A3D EF               [12] 8417 	mov	a, r7
      002A3E 12 2B FE         [24] 8418 	lcall	___fslt
      002A41 E5 81            [12] 8419 	mov	a,sp
      002A43 24 FC            [12] 8420 	add	a,#0xfc
      002A45 F5 81            [12] 8421 	mov	sp,a
      002A47 D0 04            [24] 8422 	pop	ar4
      002A49 D0 05            [24] 8423 	pop	ar5
      002A4B D0 06            [24] 8424 	pop	ar6
      002A4D D0 07            [24] 8425 	pop	ar7
      002A4F E5 82            [12] 8426 	mov	a, dpl
      002A51 24 FF            [12] 8427 	add	a,#0xff
      002A53 92 00            [24] 8428 	mov	b0,c
      002A55 40 05            [24] 8429 	jc	00104$
                           0029A0  8430 	C$controller_8051.c$188$2_0$136 ==.
                                   8431 ;	../../controller_8051.c:188: return 100u;
      002A57 75 82 64         [24] 8432 	mov	dpl, #0x64
      002A5A 80 2C            [24] 8433 	sjmp	00105$
      002A5C                       8434 00104$:
                           0029A5  8435 	C$controller_8051.c$193$1_0$134 ==.
                                   8436 ;	../../controller_8051.c:193: );
      002A5C E4               [12] 8437 	clr	a
      002A5D C0 E0            [24] 8438 	push	acc
      002A5F C0 E0            [24] 8439 	push	acc
      002A61 C0 E0            [24] 8440 	push	acc
      002A63 74 3F            [12] 8441 	mov	a,#0x3f
      002A65 C0 E0            [24] 8442 	push	acc
      002A67 8C 82            [24] 8443 	mov	dpl, r4
      002A69 8D 83            [24] 8444 	mov	dph, r5
      002A6B 8E F0            [24] 8445 	mov	b, r6
      002A6D EF               [12] 8446 	mov	a, r7
      002A6E 12 2C 50         [24] 8447 	lcall	___fsadd
      002A71 AC 82            [24] 8448 	mov	r4, dpl
      002A73 AD 83            [24] 8449 	mov	r5, dph
      002A75 AE F0            [24] 8450 	mov	r6, b
      002A77 FF               [12] 8451 	mov	r7, a
      002A78 E5 81            [12] 8452 	mov	a,sp
      002A7A 24 FC            [12] 8453 	add	a,#0xfc
      002A7C F5 81            [12] 8454 	mov	sp,a
      002A7E 8C 82            [24] 8455 	mov	dpl, r4
      002A80 8D 83            [24] 8456 	mov	dph, r5
      002A82 8E F0            [24] 8457 	mov	b, r6
      002A84 EF               [12] 8458 	mov	a, r7
      002A85 12 2E 46         [24] 8459 	lcall	___fs2uchar
      002A88                       8460 00105$:
                           0029D1  8461 	C$controller_8051.c$194$1_0$134 ==.
                                   8462 ;	../../controller_8051.c:194: }
                           0029D1  8463 	C$controller_8051.c$194$1_0$134 ==.
                           0029D1  8464 	XFcontroller_8051$fan_speed_to_pwm$0$0 ==.
      002A88 22               [24] 8465 	ret
                                   8466 ;------------------------------------------------------------
                                   8467 ;Allocation info for local variables in function 'main'
                                   8468 ;------------------------------------------------------------
                           0029D2  8469 	G$main$0$0 ==.
                           0029D2  8470 	C$controller_8051.c$211$1_0$138 ==.
                                   8471 ;	../../controller_8051.c:211: void main(void)
                                   8472 ;	-----------------------------------------
                                   8473 ;	 function main
                                   8474 ;	-----------------------------------------
      002A89                       8475 _main:
                           0029D2  8476 	C$controller_8051.c$219$1_0$138 ==.
                                   8477 ;	../../controller_8051.c:219: 42u;
      002A89 75 61 2A         [24] 8478 	mov	_test_temperature,#0x2a
                           0029D5  8479 	C$controller_8051.c$225$1_0$138 ==.
                                   8480 ;	../../controller_8051.c:225: 0x55u;
      002A8C 75 80 55         [24] 8481 	mov	_P0,#0x55
                           0029D8  8482 	C$controller_8051.c$228$1_0$138 ==.
                                   8483 ;	../../controller_8051.c:228: 0x00u;
      002A8F 75 90 00         [24] 8484 	mov	_P1,#0x00
                           0029DB  8485 	C$controller_8051.c$234$1_0$138 ==.
                                   8486 ;	../../controller_8051.c:234: test_temperature = P2;
      002A92 85 A0 61         [24] 8487 	mov	_test_temperature,_P2
                           0029DE  8488 	C$controller_8051.c$239$2_0$138 ==.
                                   8489 ;	../../controller_8051.c:239: );
      002A95 85 61 82         [24] 8490 	mov	dpl, _test_temperature
      002A98 12 2E 4E         [24] 8491 	lcall	___uchar2fs
      002A9B 12 28 4C         [24] 8492 	lcall	_calculate_fan_speed
      002A9E 85 82 63         [24] 8493 	mov	_test_fan_speed,dpl
      002AA1 85 83 64         [24] 8494 	mov	(_test_fan_speed + 1),dph
      002AA4 85 F0 65         [24] 8495 	mov	(_test_fan_speed + 2),b
      002AA7 F5 66            [12] 8496 	mov	(_test_fan_speed + 3),a
                           0029F2  8497 	C$controller_8051.c$243$1_0$138 ==.
                                   8498 ;	../../controller_8051.c:243: test_fan_speed
      002AA9 85 63 82         [24] 8499 	mov	dpl, _test_fan_speed
      002AAC 85 64 83         [24] 8500 	mov	dph, (_test_fan_speed + 1)
      002AAF 85 65 F0         [24] 8501 	mov	b, (_test_fan_speed + 2)
      002AB2 E5 66            [12] 8502 	mov	a, (_test_fan_speed + 3)
      002AB4 12 29 E7         [24] 8503 	lcall	_fan_speed_to_pwm
      002AB7 85 82 62         [24] 8504 	mov	_test_pwm,dpl
                           002A03  8505 	C$controller_8051.c$250$1_0$138 ==.
                                   8506 ;	../../controller_8051.c:250: test_pwm;
      002ABA 85 62 90         [24] 8507 	mov	_P1,_test_pwm
                           002A06  8508 	C$controller_8051.c$256$1_0$138 ==.
                                   8509 ;	../../controller_8051.c:256: 0xAAu;
      002ABD 75 80 AA         [24] 8510 	mov	_P0,#0xaa
      002AC0                       8511 00103$:
      002AC0 80 FE            [24] 8512 	sjmp	00103$
                           002A0B  8513 	C$controller_8051.c$261$2_0$138 ==.
                                   8514 ;	../../controller_8051.c:261: }
                           002A0B  8515 	C$controller_8051.c$261$2_0$138 ==.
                           002A0B  8516 	XG$main$0$0 ==.
      002AC2 22               [24] 8517 	ret
                                   8518 	.area CSEG    (CODE)
                                   8519 	.area CONST   (CODE)
                                   8520 	.area CONST   (CODE)
                           000000  8521 Fcontroller_8051$hedges$0_0$0 == .
      002EEC                       8522 _hedges:
      002EEC 01                    8523 	.db #0x01	; 1
      002EED 02                    8524 	.db #0x02	; 2
      002EEE 03                    8525 	.db #0x03	; 3
                                   8526 	.area CSEG    (CODE)
                           002A0C  8527 Fcontroller_8051$__str_0$0_0$0 == .
                                   8528 	.area CONST   (CODE)
      002EEF                       8529 ___str_0:
      002EEF 66 61 6E 5F 73 6C 6F  8530 	.ascii "fan_slow"
             77
      002EF7 00                    8531 	.db 0x00
                                   8532 	.area CSEG    (CODE)
                           002A0C  8533 Fcontroller_8051$__str_1$0_0$0 == .
                                   8534 	.area CONST   (CODE)
      002EF8                       8535 ___str_1:
      002EF8 66 61 6E 5F 66 61 73  8536 	.ascii "fan_fast"
             74
      002F00 00                    8537 	.db 0x00
                                   8538 	.area CSEG    (CODE)
                                   8539 	.area XINIT   (CODE)
                                   8540 	.area CABS    (ABS,CODE)
