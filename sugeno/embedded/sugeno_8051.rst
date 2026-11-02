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
                                    137 	.globl _fuzzy_and_array
                                    138 	.globl _fuzzy_or_array
                                    139 	.globl _fuzzy_sugeno_weighted_average_array
                                    140 	.globl _fuzzy_sugeno_weighted_sum_array
                                    141 	.globl _fuzzy_ramp
                                    142 	.globl _fuzzy_triangle
                                    143 	.globl _fuzzy_trapezoid
                                    144 	.globl _fuzzy_function_array
                                    145 	.globl _fuzzy_rules_add
                                    146 	.globl _fuzzy_rules_defuzzify_cog
                                    147 	.globl _fuzzy_rules_defuzzify_boa
                                    148 	.globl _fuzzy_rules_defuzzify_cos
                                    149 	.globl _fuzzy_rules_defuzzify_mom
                                    150 	.globl _fuzzy_rules_defuzzify_som
                                    151 	.globl _fuzzy_rules_defuzzify_lom
                                    152 	.globl _fuzzy_rules_defuzzify_method
                                    153 	.globl _fuzzy_rules_defuzzify
                                    154 	.globl _fuzzy_rules_cog
                                    155 ;--------------------------------------------------------
                                    156 ; special function registers
                                    157 ;--------------------------------------------------------
                                    158 	.area RSEG    (ABS,DATA)
      000000                        159 	.org 0x0000
                           000080   160 G$P0$0_0$0 == 0x0080
                           000080   161 _P0	=	0x0080
                           000081   162 G$SP$0_0$0 == 0x0081
                           000081   163 _SP	=	0x0081
                           000082   164 G$DPL$0_0$0 == 0x0082
                           000082   165 _DPL	=	0x0082
                           000083   166 G$DPH$0_0$0 == 0x0083
                           000083   167 _DPH	=	0x0083
                           000087   168 G$PCON$0_0$0 == 0x0087
                           000087   169 _PCON	=	0x0087
                           000088   170 G$TCON$0_0$0 == 0x0088
                           000088   171 _TCON	=	0x0088
                           000089   172 G$TMOD$0_0$0 == 0x0089
                           000089   173 _TMOD	=	0x0089
                           00008A   174 G$TL0$0_0$0 == 0x008a
                           00008A   175 _TL0	=	0x008a
                           00008B   176 G$TL1$0_0$0 == 0x008b
                           00008B   177 _TL1	=	0x008b
                           00008C   178 G$TH0$0_0$0 == 0x008c
                           00008C   179 _TH0	=	0x008c
                           00008D   180 G$TH1$0_0$0 == 0x008d
                           00008D   181 _TH1	=	0x008d
                           000090   182 G$P1$0_0$0 == 0x0090
                           000090   183 _P1	=	0x0090
                           000098   184 G$SCON$0_0$0 == 0x0098
                           000098   185 _SCON	=	0x0098
                           000099   186 G$SBUF$0_0$0 == 0x0099
                           000099   187 _SBUF	=	0x0099
                           0000A0   188 G$P2$0_0$0 == 0x00a0
                           0000A0   189 _P2	=	0x00a0
                           0000A8   190 G$IE$0_0$0 == 0x00a8
                           0000A8   191 _IE	=	0x00a8
                           0000B0   192 G$P3$0_0$0 == 0x00b0
                           0000B0   193 _P3	=	0x00b0
                           0000B8   194 G$IP$0_0$0 == 0x00b8
                           0000B8   195 _IP	=	0x00b8
                           0000D0   196 G$PSW$0_0$0 == 0x00d0
                           0000D0   197 _PSW	=	0x00d0
                           0000E0   198 G$ACC$0_0$0 == 0x00e0
                           0000E0   199 _ACC	=	0x00e0
                           0000F0   200 G$B$0_0$0 == 0x00f0
                           0000F0   201 _B	=	0x00f0
                           0000C8   202 G$T2CON$0_0$0 == 0x00c8
                           0000C8   203 _T2CON	=	0x00c8
                           0000CA   204 G$RCAP2L$0_0$0 == 0x00ca
                           0000CA   205 _RCAP2L	=	0x00ca
                           0000CB   206 G$RCAP2H$0_0$0 == 0x00cb
                           0000CB   207 _RCAP2H	=	0x00cb
                           0000CC   208 G$TL2$0_0$0 == 0x00cc
                           0000CC   209 _TL2	=	0x00cc
                           0000CD   210 G$TH2$0_0$0 == 0x00cd
                           0000CD   211 _TH2	=	0x00cd
                                    212 ;--------------------------------------------------------
                                    213 ; special function bits
                                    214 ;--------------------------------------------------------
                                    215 	.area RSEG    (ABS,DATA)
      000000                        216 	.org 0x0000
                           000080   217 G$P0_0$0_0$0 == 0x0080
                           000080   218 _P0_0	=	0x0080
                           000081   219 G$P0_1$0_0$0 == 0x0081
                           000081   220 _P0_1	=	0x0081
                           000082   221 G$P0_2$0_0$0 == 0x0082
                           000082   222 _P0_2	=	0x0082
                           000083   223 G$P0_3$0_0$0 == 0x0083
                           000083   224 _P0_3	=	0x0083
                           000084   225 G$P0_4$0_0$0 == 0x0084
                           000084   226 _P0_4	=	0x0084
                           000085   227 G$P0_5$0_0$0 == 0x0085
                           000085   228 _P0_5	=	0x0085
                           000086   229 G$P0_6$0_0$0 == 0x0086
                           000086   230 _P0_6	=	0x0086
                           000087   231 G$P0_7$0_0$0 == 0x0087
                           000087   232 _P0_7	=	0x0087
                           000088   233 G$IT0$0_0$0 == 0x0088
                           000088   234 _IT0	=	0x0088
                           000089   235 G$IE0$0_0$0 == 0x0089
                           000089   236 _IE0	=	0x0089
                           00008A   237 G$IT1$0_0$0 == 0x008a
                           00008A   238 _IT1	=	0x008a
                           00008B   239 G$IE1$0_0$0 == 0x008b
                           00008B   240 _IE1	=	0x008b
                           00008C   241 G$TR0$0_0$0 == 0x008c
                           00008C   242 _TR0	=	0x008c
                           00008D   243 G$TF0$0_0$0 == 0x008d
                           00008D   244 _TF0	=	0x008d
                           00008E   245 G$TR1$0_0$0 == 0x008e
                           00008E   246 _TR1	=	0x008e
                           00008F   247 G$TF1$0_0$0 == 0x008f
                           00008F   248 _TF1	=	0x008f
                           000090   249 G$P1_0$0_0$0 == 0x0090
                           000090   250 _P1_0	=	0x0090
                           000091   251 G$P1_1$0_0$0 == 0x0091
                           000091   252 _P1_1	=	0x0091
                           000092   253 G$P1_2$0_0$0 == 0x0092
                           000092   254 _P1_2	=	0x0092
                           000093   255 G$P1_3$0_0$0 == 0x0093
                           000093   256 _P1_3	=	0x0093
                           000094   257 G$P1_4$0_0$0 == 0x0094
                           000094   258 _P1_4	=	0x0094
                           000095   259 G$P1_5$0_0$0 == 0x0095
                           000095   260 _P1_5	=	0x0095
                           000096   261 G$P1_6$0_0$0 == 0x0096
                           000096   262 _P1_6	=	0x0096
                           000097   263 G$P1_7$0_0$0 == 0x0097
                           000097   264 _P1_7	=	0x0097
                           000098   265 G$RI$0_0$0 == 0x0098
                           000098   266 _RI	=	0x0098
                           000099   267 G$TI$0_0$0 == 0x0099
                           000099   268 _TI	=	0x0099
                           00009A   269 G$RB8$0_0$0 == 0x009a
                           00009A   270 _RB8	=	0x009a
                           00009B   271 G$TB8$0_0$0 == 0x009b
                           00009B   272 _TB8	=	0x009b
                           00009C   273 G$REN$0_0$0 == 0x009c
                           00009C   274 _REN	=	0x009c
                           00009D   275 G$SM2$0_0$0 == 0x009d
                           00009D   276 _SM2	=	0x009d
                           00009E   277 G$SM1$0_0$0 == 0x009e
                           00009E   278 _SM1	=	0x009e
                           00009F   279 G$SM0$0_0$0 == 0x009f
                           00009F   280 _SM0	=	0x009f
                           0000A0   281 G$P2_0$0_0$0 == 0x00a0
                           0000A0   282 _P2_0	=	0x00a0
                           0000A1   283 G$P2_1$0_0$0 == 0x00a1
                           0000A1   284 _P2_1	=	0x00a1
                           0000A2   285 G$P2_2$0_0$0 == 0x00a2
                           0000A2   286 _P2_2	=	0x00a2
                           0000A3   287 G$P2_3$0_0$0 == 0x00a3
                           0000A3   288 _P2_3	=	0x00a3
                           0000A4   289 G$P2_4$0_0$0 == 0x00a4
                           0000A4   290 _P2_4	=	0x00a4
                           0000A5   291 G$P2_5$0_0$0 == 0x00a5
                           0000A5   292 _P2_5	=	0x00a5
                           0000A6   293 G$P2_6$0_0$0 == 0x00a6
                           0000A6   294 _P2_6	=	0x00a6
                           0000A7   295 G$P2_7$0_0$0 == 0x00a7
                           0000A7   296 _P2_7	=	0x00a7
                           0000A8   297 G$EX0$0_0$0 == 0x00a8
                           0000A8   298 _EX0	=	0x00a8
                           0000A9   299 G$ET0$0_0$0 == 0x00a9
                           0000A9   300 _ET0	=	0x00a9
                           0000AA   301 G$EX1$0_0$0 == 0x00aa
                           0000AA   302 _EX1	=	0x00aa
                           0000AB   303 G$ET1$0_0$0 == 0x00ab
                           0000AB   304 _ET1	=	0x00ab
                           0000AC   305 G$ES$0_0$0 == 0x00ac
                           0000AC   306 _ES	=	0x00ac
                           0000AF   307 G$EA$0_0$0 == 0x00af
                           0000AF   308 _EA	=	0x00af
                           0000B0   309 G$P3_0$0_0$0 == 0x00b0
                           0000B0   310 _P3_0	=	0x00b0
                           0000B1   311 G$P3_1$0_0$0 == 0x00b1
                           0000B1   312 _P3_1	=	0x00b1
                           0000B2   313 G$P3_2$0_0$0 == 0x00b2
                           0000B2   314 _P3_2	=	0x00b2
                           0000B3   315 G$P3_3$0_0$0 == 0x00b3
                           0000B3   316 _P3_3	=	0x00b3
                           0000B4   317 G$P3_4$0_0$0 == 0x00b4
                           0000B4   318 _P3_4	=	0x00b4
                           0000B5   319 G$P3_5$0_0$0 == 0x00b5
                           0000B5   320 _P3_5	=	0x00b5
                           0000B6   321 G$P3_6$0_0$0 == 0x00b6
                           0000B6   322 _P3_6	=	0x00b6
                           0000B7   323 G$P3_7$0_0$0 == 0x00b7
                           0000B7   324 _P3_7	=	0x00b7
                           0000B0   325 G$RXD$0_0$0 == 0x00b0
                           0000B0   326 _RXD	=	0x00b0
                           0000B1   327 G$TXD$0_0$0 == 0x00b1
                           0000B1   328 _TXD	=	0x00b1
                           0000B2   329 G$INT0$0_0$0 == 0x00b2
                           0000B2   330 _INT0	=	0x00b2
                           0000B3   331 G$INT1$0_0$0 == 0x00b3
                           0000B3   332 _INT1	=	0x00b3
                           0000B4   333 G$T0$0_0$0 == 0x00b4
                           0000B4   334 _T0	=	0x00b4
                           0000B5   335 G$T1$0_0$0 == 0x00b5
                           0000B5   336 _T1	=	0x00b5
                           0000B6   337 G$WR$0_0$0 == 0x00b6
                           0000B6   338 _WR	=	0x00b6
                           0000B7   339 G$RD$0_0$0 == 0x00b7
                           0000B7   340 _RD	=	0x00b7
                           0000B8   341 G$PX0$0_0$0 == 0x00b8
                           0000B8   342 _PX0	=	0x00b8
                           0000B9   343 G$PT0$0_0$0 == 0x00b9
                           0000B9   344 _PT0	=	0x00b9
                           0000BA   345 G$PX1$0_0$0 == 0x00ba
                           0000BA   346 _PX1	=	0x00ba
                           0000BB   347 G$PT1$0_0$0 == 0x00bb
                           0000BB   348 _PT1	=	0x00bb
                           0000BC   349 G$PS$0_0$0 == 0x00bc
                           0000BC   350 _PS	=	0x00bc
                           0000D0   351 G$P$0_0$0 == 0x00d0
                           0000D0   352 _P	=	0x00d0
                           0000D1   353 G$F1$0_0$0 == 0x00d1
                           0000D1   354 _F1	=	0x00d1
                           0000D2   355 G$OV$0_0$0 == 0x00d2
                           0000D2   356 _OV	=	0x00d2
                           0000D3   357 G$RS0$0_0$0 == 0x00d3
                           0000D3   358 _RS0	=	0x00d3
                           0000D4   359 G$RS1$0_0$0 == 0x00d4
                           0000D4   360 _RS1	=	0x00d4
                           0000D5   361 G$F0$0_0$0 == 0x00d5
                           0000D5   362 _F0	=	0x00d5
                           0000D6   363 G$AC$0_0$0 == 0x00d6
                           0000D6   364 _AC	=	0x00d6
                           0000D7   365 G$CY$0_0$0 == 0x00d7
                           0000D7   366 _CY	=	0x00d7
                           0000AD   367 G$ET2$0_0$0 == 0x00ad
                           0000AD   368 _ET2	=	0x00ad
                           0000BD   369 G$PT2$0_0$0 == 0x00bd
                           0000BD   370 _PT2	=	0x00bd
                           0000C8   371 G$T2CON_0$0_0$0 == 0x00c8
                           0000C8   372 _T2CON_0	=	0x00c8
                           0000C9   373 G$T2CON_1$0_0$0 == 0x00c9
                           0000C9   374 _T2CON_1	=	0x00c9
                           0000CA   375 G$T2CON_2$0_0$0 == 0x00ca
                           0000CA   376 _T2CON_2	=	0x00ca
                           0000CB   377 G$T2CON_3$0_0$0 == 0x00cb
                           0000CB   378 _T2CON_3	=	0x00cb
                           0000CC   379 G$T2CON_4$0_0$0 == 0x00cc
                           0000CC   380 _T2CON_4	=	0x00cc
                           0000CD   381 G$T2CON_5$0_0$0 == 0x00cd
                           0000CD   382 _T2CON_5	=	0x00cd
                           0000CE   383 G$T2CON_6$0_0$0 == 0x00ce
                           0000CE   384 _T2CON_6	=	0x00ce
                           0000CF   385 G$T2CON_7$0_0$0 == 0x00cf
                           0000CF   386 _T2CON_7	=	0x00cf
                           0000C8   387 G$CP_RL2$0_0$0 == 0x00c8
                           0000C8   388 _CP_RL2	=	0x00c8
                           0000C9   389 G$C_T2$0_0$0 == 0x00c9
                           0000C9   390 _C_T2	=	0x00c9
                           0000CA   391 G$TR2$0_0$0 == 0x00ca
                           0000CA   392 _TR2	=	0x00ca
                           0000CB   393 G$EXEN2$0_0$0 == 0x00cb
                           0000CB   394 _EXEN2	=	0x00cb
                           0000CC   395 G$TCLK$0_0$0 == 0x00cc
                           0000CC   396 _TCLK	=	0x00cc
                           0000CD   397 G$RCLK$0_0$0 == 0x00cd
                           0000CD   398 _RCLK	=	0x00cd
                           0000CE   399 G$EXF2$0_0$0 == 0x00ce
                           0000CE   400 _EXF2	=	0x00ce
                           0000CF   401 G$TF2$0_0$0 == 0x00cf
                           0000CF   402 _TF2	=	0x00cf
                                    403 ;--------------------------------------------------------
                                    404 ; overlayable register banks
                                    405 ;--------------------------------------------------------
                                    406 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        407 	.ds 8
                                    408 ;--------------------------------------------------------
                                    409 ; overlayable bit register bank
                                    410 ;--------------------------------------------------------
                                    411 	.area BIT_BANK	(REL,OVR,DATA)
      000020                        412 bits:
      000020                        413 	.ds 1
                           008000   414 	b0 = bits[0]
                           008100   415 	b1 = bits[1]
                           008200   416 	b2 = bits[2]
                           008300   417 	b3 = bits[3]
                           008400   418 	b4 = bits[4]
                           008500   419 	b5 = bits[5]
                           008600   420 	b6 = bits[6]
                           008700   421 	b7 = bits[7]
                                    422 ;--------------------------------------------------------
                                    423 ; internal ram data
                                    424 ;--------------------------------------------------------
                                    425 	.area DSEG    (DATA)
                           000000   426 Fsugeno_demo$fuzzy_values_buffer$0_0$0==.
      000021                        427 _fuzzy_values_buffer:
      000021                        428 	.ds 64
                           000040   429 G$test_temperature$0_0$0==.
      000061                        430 _test_temperature::
      000061                        431 	.ds 1
                           000041   432 G$test_load$0_0$0==.
      000062                        433 _test_load::
      000062                        434 	.ds 1
                           000042   435 G$test_vibration$0_0$0==.
      000063                        436 _test_vibration::
      000063                        437 	.ds 1
                           000043   438 G$test_pwm$0_0$0==.
      000064                        439 _test_pwm::
      000064                        440 	.ds 1
                           000044   441 G$test_fan_speed$0_0$0==.
      000065                        442 _test_fan_speed::
      000065                        443 	.ds 4
                                    444 ;--------------------------------------------------------
                                    445 ; overlayable items in internal ram
                                    446 ;--------------------------------------------------------
                                    447 ;--------------------------------------------------------
                                    448 ; Stack segment in internal ram
                                    449 ;--------------------------------------------------------
                                    450 	.area SSEG
      000069                        451 __start__stack:
      000069                        452 	.ds	1
                                    453 
                                    454 ;--------------------------------------------------------
                                    455 ; indirectly addressable internal ram data
                                    456 ;--------------------------------------------------------
                                    457 	.area ISEG    (DATA)
                                    458 ;--------------------------------------------------------
                                    459 ; absolute internal ram data
                                    460 ;--------------------------------------------------------
                                    461 	.area IABS    (ABS,DATA)
                                    462 	.area IABS    (ABS,DATA)
                                    463 ;--------------------------------------------------------
                                    464 ; bit data
                                    465 ;--------------------------------------------------------
                                    466 	.area BSEG    (BIT)
                                    467 ;--------------------------------------------------------
                                    468 ; paged external ram data
                                    469 ;--------------------------------------------------------
                                    470 	.area PSEG    (PAG,XDATA)
                                    471 ;--------------------------------------------------------
                                    472 ; uninitialized external ram data
                                    473 ;--------------------------------------------------------
                                    474 	.area XSEG    (XDATA)
                                    475 ;--------------------------------------------------------
                                    476 ; absolute external ram data
                                    477 ;--------------------------------------------------------
                                    478 	.area XABS    (ABS,XDATA)
                                    479 ;--------------------------------------------------------
                                    480 ; initialized external ram data
                                    481 ;--------------------------------------------------------
                                    482 	.area XISEG   (XDATA)
                                    483 	.area HOME    (CODE)
                                    484 	.area GSINIT0 (CODE)
                                    485 	.area GSINIT1 (CODE)
                                    486 	.area GSINIT2 (CODE)
                                    487 	.area GSINIT3 (CODE)
                                    488 	.area GSINIT4 (CODE)
                                    489 	.area GSINIT5 (CODE)
                                    490 	.area GSINIT  (CODE)
                                    491 	.area GSFINAL (CODE)
                                    492 	.area CSEG    (CODE)
                                    493 ;--------------------------------------------------------
                                    494 ; interrupt vector
                                    495 ;--------------------------------------------------------
                                    496 	.area HOME    (CODE)
      000000                        497 __interrupt_vect:
      000000 02 00 4C         [24]  498 	ljmp	__sdcc_gsinit_startup
                                    499 ; restartable atomic support routines
      000003                        500 	.ds	5
      000008                        501 sdcc_atomic_exchange_rollback_start::
      000008 00               [12]  502 	nop
      000009 00               [12]  503 	nop
      00000A                        504 sdcc_atomic_exchange_pdata_impl:
      00000A E2               [24]  505 	movx	a, @r0
      00000B FB               [12]  506 	mov	r3, a
      00000C EA               [12]  507 	mov	a, r2
      00000D F2               [24]  508 	movx	@r0, a
      00000E 80 2C            [24]  509 	sjmp	sdcc_atomic_exchange_exit
      000010 00               [12]  510 	nop
      000011 00               [12]  511 	nop
      000012                        512 sdcc_atomic_exchange_xdata_impl:
      000012 E0               [24]  513 	movx	a, @dptr
      000013 FB               [12]  514 	mov	r3, a
      000014 EA               [12]  515 	mov	a, r2
      000015 F0               [24]  516 	movx	@dptr, a
      000016 80 24            [24]  517 	sjmp	sdcc_atomic_exchange_exit
      000018                        518 sdcc_atomic_compare_exchange_idata_impl:
      000018 E6               [12]  519 	mov	a, @r0
      000019 B5 02 02         [24]  520 	cjne	a, ar2, .+#5
      00001C EB               [12]  521 	mov	a, r3
      00001D F6               [12]  522 	mov	@r0, a
      00001E 22               [24]  523 	ret
      00001F 00               [12]  524 	nop
      000020                        525 sdcc_atomic_compare_exchange_pdata_impl:
      000020 E2               [24]  526 	movx	a, @r0
      000021 B5 02 02         [24]  527 	cjne	a, ar2, .+#5
      000024 EB               [12]  528 	mov	a, r3
      000025 F2               [24]  529 	movx	@r0, a
      000026 22               [24]  530 	ret
      000027 00               [12]  531 	nop
      000028                        532 sdcc_atomic_compare_exchange_xdata_impl:
      000028 E0               [24]  533 	movx	a, @dptr
      000029 B5 02 02         [24]  534 	cjne	a, ar2, .+#5
      00002C EB               [12]  535 	mov	a, r3
      00002D F0               [24]  536 	movx	@dptr, a
      00002E 22               [24]  537 	ret
      00002F                        538 sdcc_atomic_exchange_rollback_end::
                                    539 
      00002F                        540 sdcc_atomic_exchange_gptr_impl::
      00002F 30 F6 E0         [24]  541 	jnb	b.6, sdcc_atomic_exchange_xdata_impl
      000032 A8 82            [24]  542 	mov	r0, dpl
      000034 20 F5 D3         [24]  543 	jb	b.5, sdcc_atomic_exchange_pdata_impl
      000037                        544 sdcc_atomic_exchange_idata_impl:
      000037 EA               [12]  545 	mov	a, r2
      000038 C6               [12]  546 	xch	a, @r0
      000039 F5 82            [12]  547 	mov	dpl, a
      00003B 22               [24]  548 	ret
      00003C                        549 sdcc_atomic_exchange_exit:
      00003C 8B 82            [24]  550 	mov	dpl, r3
      00003E 22               [24]  551 	ret
      00003F                        552 sdcc_atomic_compare_exchange_gptr_impl::
      00003F 30 F6 E6         [24]  553 	jnb	b.6, sdcc_atomic_compare_exchange_xdata_impl
      000042 A8 82            [24]  554 	mov	r0, dpl
      000044 20 F5 D9         [24]  555 	jb	b.5, sdcc_atomic_compare_exchange_pdata_impl
      000047 80 CF            [24]  556 	sjmp	sdcc_atomic_compare_exchange_idata_impl
                                    557 ;--------------------------------------------------------
                                    558 ; global & static initialisations
                                    559 ;--------------------------------------------------------
                                    560 	.area HOME    (CODE)
                                    561 	.area GSINIT  (CODE)
                                    562 	.area GSFINAL (CODE)
                                    563 	.area GSINIT  (CODE)
                                    564 	.globl __sdcc_gsinit_startup
                                    565 	.globl __sdcc_program_startup
                                    566 	.globl __start__stack
                                    567 	.globl __mcs51_genXINIT
                                    568 	.globl __mcs51_genXRAMCLEAR
                                    569 	.globl __mcs51_genRAMCLEAR
                           000000   570 	C$sugeno_demo.c$25$2_0$177 ==.
                                    571 ;	../../sugeno_demo.c:25: volatile unsigned char test_temperature = 42u;
      0000A5 75 61 2A         [24]  572 	mov	_test_temperature,#0x2a
                           000003   573 	C$sugeno_demo.c$26$2_0$177 ==.
                                    574 ;	../../sugeno_demo.c:26: volatile unsigned char test_load = 65u;
      0000A8 75 62 41         [24]  575 	mov	_test_load,#0x41
                           000006   576 	C$sugeno_demo.c$27$2_0$177 ==.
                                    577 ;	../../sugeno_demo.c:27: volatile unsigned char test_vibration = 4u;
      0000AB 75 63 04         [24]  578 	mov	_test_vibration,#0x04
                           000009   579 	C$sugeno_demo.c$29$2_0$177 ==.
                                    580 ;	../../sugeno_demo.c:29: volatile unsigned char test_pwm = 0u;
      0000AE 75 64 00         [24]  581 	mov	_test_pwm,#0x00
                           00000C   582 	C$sugeno_demo.c$30$2_0$177 ==.
                                    583 ;	../../sugeno_demo.c:30: volatile float test_fan_speed = 0.0f;
      0000B1 E4               [12]  584 	clr	a
      0000B2 F5 65            [12]  585 	mov	_test_fan_speed,a
      0000B4 F5 66            [12]  586 	mov	(_test_fan_speed + 1),a
      0000B6 F5 67            [12]  587 	mov	(_test_fan_speed + 2),a
      0000B8 F5 68            [12]  588 	mov	(_test_fan_speed + 3),a
                                    589 	.area GSFINAL (CODE)
      0000BA 02 00 49         [24]  590 	ljmp	__sdcc_program_startup
                                    591 ;--------------------------------------------------------
                                    592 ; Home
                                    593 ;--------------------------------------------------------
                                    594 	.area HOME    (CODE)
                                    595 	.area HOME    (CODE)
      000049                        596 __sdcc_program_startup:
      000049 02 3F 98         [24]  597 	ljmp	_main
                                    598 ;	return from main will return to caller
                                    599 ;--------------------------------------------------------
                                    600 ; code
                                    601 ;--------------------------------------------------------
                                    602 	.area CSEG    (CODE)
                                    603 ;------------------------------------------------------------
                                    604 ;Allocation info for local variables in function 'fuzzy_values_initialize'
                                    605 ;------------------------------------------------------------
                                    606 ;index         Allocated to registers r6 r7 
                                    607 ;------------------------------------------------------------
                           000000   608 	Fsugeno_demo$fuzzy_values_initialize$0$0 ==.
                           000000   609 	C$fuzzy.h$277$0_0$3 ==.
                                    610 ;	../../fuzzy.h:277: static float *fuzzy_values_initialize(void)
                                    611 ;	-----------------------------------------
                                    612 ;	 function fuzzy_values_initialize
                                    613 ;	-----------------------------------------
      0000BD                        614 _fuzzy_values_initialize:
                           000007   615 	ar7 = 0x07
                           000006   616 	ar6 = 0x06
                           000005   617 	ar5 = 0x05
                           000004   618 	ar4 = 0x04
                           000003   619 	ar3 = 0x03
                           000002   620 	ar2 = 0x02
                           000001   621 	ar1 = 0x01
                           000000   622 	ar0 = 0x00
                           000000   623 	C$fuzzy.h$282$3_0$5 ==.
                                    624 ;	../../fuzzy.h:282: index = 0u;
      0000BD 7E 00            [12]  625 	mov	r6,#0x00
      0000BF 7F 00            [12]  626 	mov	r7,#0x00
      0000C1                        627 00102$:
                           000004   628 	C$fuzzy.h$286$3_0$5 ==.
                                    629 ;	../../fuzzy.h:286: fuzzy_values_buffer[index] = 0.0f;
      0000C1 EE               [12]  630 	mov	a,r6
      0000C2 2E               [12]  631 	add	a,r6
      0000C3 FC               [12]  632 	mov	r4,a
      0000C4 EF               [12]  633 	mov	a,r7
      0000C5 33               [12]  634 	rlc	a
      0000C6 FD               [12]  635 	mov	r5,a
      0000C7 EC               [12]  636 	mov	a,r4
      0000C8 2C               [12]  637 	add	a,r4
      0000C9 FC               [12]  638 	mov	r4,a
      0000CA ED               [12]  639 	mov	a,r5
      0000CB 33               [12]  640 	rlc	a
      0000CC EC               [12]  641 	mov	a,r4
      0000CD 24 21            [12]  642 	add	a, #_fuzzy_values_buffer
      0000CF F8               [12]  643 	mov	r0,a
      0000D0 76 00            [12]  644 	mov	@r0,#0x00
      0000D2 08               [12]  645 	inc	r0
      0000D3 76 00            [12]  646 	mov	@r0,#0x00
      0000D5 08               [12]  647 	inc	r0
      0000D6 76 00            [12]  648 	mov	@r0,#0x00
      0000D8 08               [12]  649 	inc	r0
      0000D9 76 00            [12]  650 	mov	@r0,#0x00
                           00001E   651 	C$fuzzy.h$284$2_0$4 ==.
                                    652 ;	../../fuzzy.h:284: index++
      0000DB 0E               [12]  653 	inc	r6
      0000DC BE 00 01         [24]  654 	cjne	r6,#0x00,00119$
      0000DF 0F               [12]  655 	inc	r7
      0000E0                        656 00119$:
                           000023   657 	C$fuzzy.h$283$2_0$4 ==.
                                    658 ;	../../fuzzy.h:283: index < FUZZY_MAX_VALUES;
      0000E0 C3               [12]  659 	clr	c
      0000E1 EE               [12]  660 	mov	a,r6
      0000E2 94 10            [12]  661 	subb	a,#0x10
      0000E4 EF               [12]  662 	mov	a,r7
      0000E5 94 00            [12]  663 	subb	a,#0x00
      0000E7 40 D8            [24]  664 	jc	00102$
                           00002C   665 	C$fuzzy.h$289$1_0$3 ==.
                                    666 ;	../../fuzzy.h:289: return fuzzy_values_buffer;
      0000E9 90 00 21         [24]  667 	mov	dptr,#_fuzzy_values_buffer
      0000EC 75 F0 40         [24]  668 	mov	b, #0x40
                           000032   669 	C$fuzzy.h$290$1_0$3 ==.
                                    670 ;	../../fuzzy.h:290: }
                           000032   671 	C$fuzzy.h$290$1_0$3 ==.
                           000032   672 	XFsugeno_demo$fuzzy_values_initialize$0$0 ==.
      0000EF 22               [24]  673 	ret
                                    674 ;------------------------------------------------------------
                                    675 ;Allocation info for local variables in function 'fuzzy_clamp'
                                    676 ;------------------------------------------------------------
                                    677 ;value         Allocated to registers r4 r5 r6 r7 
                                    678 ;------------------------------------------------------------
                           000033   679 	Fsugeno_demo$fuzzy_clamp$0$0 ==.
                           000033   680 	C$fuzzy.h$1212$1_0$27 ==.
                                    681 ;	../../fuzzy.h:1212: static float fuzzy_clamp(float value)
                                    682 ;	-----------------------------------------
                                    683 ;	 function fuzzy_clamp
                                    684 ;	-----------------------------------------
      0000F0                        685 _fuzzy_clamp:
      0000F0 AC 82            [24]  686 	mov	r4,dpl
      0000F2 AD 83            [24]  687 	mov	r5,dph
      0000F4 AE F0            [24]  688 	mov	r6,b
      0000F6 FF               [12]  689 	mov	r7,a
                           00003A   690 	C$fuzzy.h$1214$1_0$27 ==.
                                    691 ;	../../fuzzy.h:1214: if (value < LEVEL_LO) return LEVEL_LO;
      0000F7 C0 07            [24]  692 	push	ar7
      0000F9 C0 06            [24]  693 	push	ar6
      0000FB C0 05            [24]  694 	push	ar5
      0000FD C0 04            [24]  695 	push	ar4
      0000FF E4               [12]  696 	clr	a
      000100 C0 E0            [24]  697 	push	acc
      000102 C0 E0            [24]  698 	push	acc
      000104 C0 E0            [24]  699 	push	acc
      000106 C0 E0            [24]  700 	push	acc
      000108 8C 82            [24]  701 	mov	dpl, r4
      00010A 8D 83            [24]  702 	mov	dph, r5
      00010C 8E F0            [24]  703 	mov	b, r6
      00010E EF               [12]  704 	mov	a, r7
      00010F 12 41 7C         [24]  705 	lcall	___fslt
      000112 AB 82            [24]  706 	mov	r3, dpl
      000114 E5 81            [12]  707 	mov	a,sp
      000116 24 FC            [12]  708 	add	a,#0xfc
      000118 F5 81            [12]  709 	mov	sp,a
      00011A D0 04            [24]  710 	pop	ar4
      00011C D0 05            [24]  711 	pop	ar5
      00011E D0 06            [24]  712 	pop	ar6
      000120 D0 07            [24]  713 	pop	ar7
      000122 EB               [12]  714 	mov	a,r3
      000123 60 08            [24]  715 	jz	00102$
      000125 90 00 00         [24]  716 	mov	dptr,#0x0000
      000128 E4               [12]  717 	clr	a
      000129 F5 F0            [12]  718 	mov	b,a
      00012B 80 3F            [24]  719 	sjmp	00105$
      00012D                        720 00102$:
                           000070   721 	C$fuzzy.h$1216$1_0$27 ==.
                                    722 ;	../../fuzzy.h:1216: if (value > LEVEL_HI) return LEVEL_HI;
      00012D C0 07            [24]  723 	push	ar7
      00012F C0 06            [24]  724 	push	ar6
      000131 C0 05            [24]  725 	push	ar5
      000133 C0 04            [24]  726 	push	ar4
      000135 C0 04            [24]  727 	push	ar4
      000137 C0 05            [24]  728 	push	ar5
      000139 C0 06            [24]  729 	push	ar6
      00013B C0 07            [24]  730 	push	ar7
      00013D 90 00 00         [24]  731 	mov	dptr,#0x0000
      000140 75 F0 80         [24]  732 	mov	b, #0x80
      000143 74 3F            [12]  733 	mov	a, #0x3f
      000145 12 41 7C         [24]  734 	lcall	___fslt
      000148 AB 82            [24]  735 	mov	r3, dpl
      00014A E5 81            [12]  736 	mov	a,sp
      00014C 24 FC            [12]  737 	add	a,#0xfc
      00014E F5 81            [12]  738 	mov	sp,a
      000150 D0 04            [24]  739 	pop	ar4
      000152 D0 05            [24]  740 	pop	ar5
      000154 D0 06            [24]  741 	pop	ar6
      000156 D0 07            [24]  742 	pop	ar7
      000158 EB               [12]  743 	mov	a,r3
      000159 60 0A            [24]  744 	jz	00104$
      00015B 90 00 00         [24]  745 	mov	dptr,#0x0000
      00015E 75 F0 80         [24]  746 	mov	b, #0x80
      000161 74 3F            [12]  747 	mov	a, #0x3f
      000163 80 07            [24]  748 	sjmp	00105$
      000165                        749 00104$:
                           0000A8   750 	C$fuzzy.h$1218$1_0$27 ==.
                                    751 ;	../../fuzzy.h:1218: return value;
      000165 8C 82            [24]  752 	mov	dpl, r4
      000167 8D 83            [24]  753 	mov	dph, r5
      000169 8E F0            [24]  754 	mov	b, r6
      00016B EF               [12]  755 	mov	a, r7
      00016C                        756 00105$:
                           0000AF   757 	C$fuzzy.h$1219$1_0$27 ==.
                                    758 ;	../../fuzzy.h:1219: }
                           0000AF   759 	C$fuzzy.h$1219$1_0$27 ==.
                           0000AF   760 	XFsugeno_demo$fuzzy_clamp$0$0 ==.
      00016C 22               [24]  761 	ret
                                    762 ;------------------------------------------------------------
                                    763 ;Allocation info for local variables in function 'fuzzy_not'
                                    764 ;------------------------------------------------------------
                                    765 ;membership    Allocated to registers r4 r5 r6 r7 
                                    766 ;------------------------------------------------------------
                           0000B0   767 	G$fuzzy_not$0$0 ==.
                           0000B0   768 	C$fuzzy.h$1224$1_0$29 ==.
                                    769 ;	../../fuzzy.h:1224: float fuzzy_not(float membership)
                                    770 ;	-----------------------------------------
                                    771 ;	 function fuzzy_not
                                    772 ;	-----------------------------------------
      00016D                        773 _fuzzy_not:
                           0000B0   774 	C$fuzzy.h$1226$1_0$29 ==.
                                    775 ;	../../fuzzy.h:1226: return LEVEL_HI - fuzzy_clamp(membership);
      00016D 12 00 F0         [24]  776 	lcall	_fuzzy_clamp
      000170 AC 82            [24]  777 	mov	r4, dpl
      000172 AD 83            [24]  778 	mov	r5, dph
      000174 AE F0            [24]  779 	mov	r6, b
      000176 FF               [12]  780 	mov	r7, a
      000177 C0 04            [24]  781 	push	ar4
      000179 C0 05            [24]  782 	push	ar5
      00017B C0 06            [24]  783 	push	ar6
      00017D C0 07            [24]  784 	push	ar7
      00017F 90 00 00         [24]  785 	mov	dptr,#0x0000
      000182 75 F0 80         [24]  786 	mov	b, #0x80
      000185 74 3F            [12]  787 	mov	a, #0x3f
      000187 12 40 41         [24]  788 	lcall	___fssub
      00018A AC 82            [24]  789 	mov	r4, dpl
      00018C AD 83            [24]  790 	mov	r5, dph
      00018E AE F0            [24]  791 	mov	r6, b
      000190 FF               [12]  792 	mov	r7, a
      000191 E5 81            [12]  793 	mov	a,sp
      000193 24 FC            [12]  794 	add	a,#0xfc
      000195 F5 81            [12]  795 	mov	sp,a
      000197 8C 82            [24]  796 	mov	dpl, r4
      000199 8D 83            [24]  797 	mov	dph, r5
      00019B 8E F0            [24]  798 	mov	b, r6
      00019D EF               [12]  799 	mov	a, r7
                           0000E1   800 	C$fuzzy.h$1227$1_0$29 ==.
                                    801 ;	../../fuzzy.h:1227: }
                           0000E1   802 	C$fuzzy.h$1227$1_0$29 ==.
                           0000E1   803 	XG$fuzzy_not$0$0 ==.
      00019E 22               [24]  804 	ret
                                    805 ;------------------------------------------------------------
                                    806 ;Allocation info for local variables in function 'fuzzy_apply_hedge'
                                    807 ;------------------------------------------------------------
                                    808 ;hedge         Allocated to stack - _bp -3 +1 
                                    809 ;membership    Allocated to stack - _bp +1 +4 
                                    810 ;result        Allocated to registers r2 r3 r6 r7 
                                    811 ;------------------------------------------------------------
                           0000E2   812 	Fsugeno_demo$fuzzy_apply_hedge$0$0 ==.
                           0000E2   813 	C$fuzzy.h$1237$1_0$31 ==.
                                    814 ;	../../fuzzy.h:1237: static float fuzzy_apply_hedge(
                                    815 ;	-----------------------------------------
                                    816 ;	 function fuzzy_apply_hedge
                                    817 ;	-----------------------------------------
      00019F                        818 _fuzzy_apply_hedge:
      00019F C0 08            [24]  819 	push	_bp
      0001A1 85 81 08         [24]  820 	mov	_bp,sp
      0001A4 AC 82            [24]  821 	mov	r4,dpl
      0001A6 AD 83            [24]  822 	mov	r5,dph
      0001A8 AE F0            [24]  823 	mov	r6,b
      0001AA FF               [12]  824 	mov	r7,a
      0001AB E5 81            [12]  825 	mov	a,sp
      0001AD 24 04            [12]  826 	add	a,#0x04
      0001AF F5 81            [12]  827 	mov	sp,a
                           0000F4   828 	C$fuzzy.h$1243$1_0$31 ==.
                                    829 ;	../../fuzzy.h:1243: fuzzy_clamp( membership
      0001B1 8C 82            [24]  830 	mov	dpl, r4
      0001B3 8D 83            [24]  831 	mov	dph, r5
      0001B5 8E F0            [24]  832 	mov	b, r6
      0001B7 EF               [12]  833 	mov	a, r7
      0001B8 12 00 F0         [24]  834 	lcall	_fuzzy_clamp
      0001BB A8 08            [24]  835 	mov	r0,_bp
      0001BD 08               [12]  836 	inc	r0
      0001BE A6 82            [24]  837 	mov	@r0, dpl
      0001C0 08               [12]  838 	inc	r0
      0001C1 A6 83            [24]  839 	mov	@r0, dph
      0001C3 08               [12]  840 	inc	r0
      0001C4 A6 F0            [24]  841 	mov	@r0, b
      0001C6 08               [12]  842 	inc	r0
      0001C7 F6               [12]  843 	mov	@r0,a
                           00010B   844 	C$fuzzy.h$1248$2_0$32 ==.
                                    845 ;	../../fuzzy.h:1248: float result =
      0001C8 7A 00            [12]  846 	mov	r2,#0x00
      0001CA 7B 00            [12]  847 	mov	r3,#0x00
      0001CC 7E 80            [12]  848 	mov	r6,#0x80
      0001CE 7F 3F            [12]  849 	mov	r7,#0x3f
                           000113   850 	C$fuzzy.h$1251$1_1$32 ==.
                                    851 ;	../../fuzzy.h:1251: if (hedge == 0u) {
      0001D0 E5 08            [12]  852 	mov	a,_bp
      0001D2 24 FD            [12]  853 	add	a,#0xfd
      0001D4 F8               [12]  854 	mov	r0,a
      0001D5 E6               [12]  855 	mov	a,@r0
      0001D6 70 07            [24]  856 	jnz	00110$
                           00011B   857 	C$fuzzy.h$1252$2_1$33 ==.
                                    858 ;	../../fuzzy.h:1252: hedge = 1u;
      0001D8 E5 08            [12]  859 	mov	a,_bp
      0001DA 24 FD            [12]  860 	add	a,#0xfd
      0001DC F8               [12]  861 	mov	r0,a
      0001DD 76 01            [12]  862 	mov	@r0,#0x01
                           000122   863 	C$fuzzy.h$1255$1_1$31 ==.
                                    864 ;	../../fuzzy.h:1255: while (hedge > 0u) {
      0001DF                        865 00110$:
      0001DF E5 08            [12]  866 	mov	a,_bp
      0001E1 24 FD            [12]  867 	add	a,#0xfd
      0001E3 F8               [12]  868 	mov	r0,a
      0001E4 86 05            [24]  869 	mov	ar5,@r0
      0001E6                        870 00103$:
      0001E6 ED               [12]  871 	mov	a,r5
      0001E7 60 30            [24]  872 	jz	00105$
                           00012C   873 	C$fuzzy.h$1256$1_1$31 ==.
                                    874 ;	../../fuzzy.h:1256: result *= membership;
      0001E9 C0 05            [24]  875 	push	ar5
      0001EB A8 08            [24]  876 	mov	r0,_bp
      0001ED 08               [12]  877 	inc	r0
      0001EE E6               [12]  878 	mov	a,@r0
      0001EF C0 E0            [24]  879 	push	acc
      0001F1 08               [12]  880 	inc	r0
      0001F2 E6               [12]  881 	mov	a,@r0
      0001F3 C0 E0            [24]  882 	push	acc
      0001F5 08               [12]  883 	inc	r0
      0001F6 E6               [12]  884 	mov	a,@r0
      0001F7 C0 E0            [24]  885 	push	acc
      0001F9 08               [12]  886 	inc	r0
      0001FA E6               [12]  887 	mov	a,@r0
      0001FB C0 E0            [24]  888 	push	acc
                           000140   889 	C$fuzzy.h$1258$1_1$31 ==.
                                    890 ;	../../fuzzy.h:1258: hedge--;
      0001FD 8A 82            [24]  891 	mov	dpl, r2
      0001FF 8B 83            [24]  892 	mov	dph, r3
      000201 8E F0            [24]  893 	mov	b, r6
      000203 EF               [12]  894 	mov	a, r7
      000204 12 40 4C         [24]  895 	lcall	___fsmul
      000207 AA 82            [24]  896 	mov	r2, dpl
      000209 AB 83            [24]  897 	mov	r3, dph
      00020B AE F0            [24]  898 	mov	r6, b
      00020D FF               [12]  899 	mov	r7, a
      00020E E5 81            [12]  900 	mov	a,sp
      000210 24 FC            [12]  901 	add	a,#0xfc
      000212 F5 81            [12]  902 	mov	sp,a
      000214 D0 05            [24]  903 	pop	ar5
      000216 1D               [12]  904 	dec	r5
      000217 80 CD            [24]  905 	sjmp	00103$
      000219                        906 00105$:
                           00015C   907 	C$fuzzy.h$1262$1_1$32 ==.
                                    908 ;	../../fuzzy.h:1262: result
      000219 8A 82            [24]  909 	mov	dpl, r2
      00021B 8B 83            [24]  910 	mov	dph, r3
      00021D 8E F0            [24]  911 	mov	b, r6
      00021F EF               [12]  912 	mov	a, r7
      000220 12 00 F0         [24]  913 	lcall	_fuzzy_clamp
                           000166   914 	C$fuzzy.h$1278$1_1$31 ==.
                                    915 ;	../../fuzzy.h:1278: }
      000223 85 08 81         [24]  916 	mov	sp,_bp
      000226 D0 08            [24]  917 	pop	_bp
                           00016B   918 	C$fuzzy.h$1278$1_1$31 ==.
                           00016B   919 	XFsugeno_demo$fuzzy_apply_hedge$0$0 ==.
      000228 22               [24]  920 	ret
                                    921 ;------------------------------------------------------------
                                    922 ;Allocation info for local variables in function 'fuzzy_and_array'
                                    923 ;------------------------------------------------------------
                                    924 ;count         Allocated to stack - _bp -4 +2 
                                    925 ;args          Allocated to stack - _bp -7 +3 
                                    926 ;method        Allocated to registers r5 
                                    927 ;result        Allocated to stack - _bp +5 +4 
                                    928 ;next          Allocated to stack - _bp +9 +4 
                                    929 ;index         Allocated to stack - _bp +13 +2 
                                    930 ;sloc0         Allocated to stack - _bp +1 +3 
                                    931 ;sloc1         Allocated to stack - _bp +4 +1 
                                    932 ;------------------------------------------------------------
                           00016C   933 	G$fuzzy_and_array$0$0 ==.
                           00016C   934 	C$fuzzy.h$1292$1_1$36 ==.
                                    935 ;	../../fuzzy.h:1292: float fuzzy_and_array(
                                    936 ;	-----------------------------------------
                                    937 ;	 function fuzzy_and_array
                                    938 ;	-----------------------------------------
      000229                        939 _fuzzy_and_array:
      000229 C0 08            [24]  940 	push	_bp
      00022B E5 81            [12]  941 	mov	a,sp
      00022D F5 08            [12]  942 	mov	_bp,a
      00022F 24 0E            [12]  943 	add	a,#0x0e
      000231 F5 81            [12]  944 	mov	sp,a
      000233 AD 82            [24]  945 	mov	r5, dpl
                           000178   946 	C$fuzzy.h$1303$1_0$36 ==.
                                    947 ;	../../fuzzy.h:1303: args == NULL ||
      000235 E5 08            [12]  948 	mov	a,_bp
      000237 24 F9            [12]  949 	add	a,#0xf9
      000239 F8               [12]  950 	mov	r0,a
      00023A E6               [12]  951 	mov	a,@r0
      00023B 08               [12]  952 	inc	r0
      00023C 46               [12]  953 	orl	a,@r0
      00023D 60 0A            [24]  954 	jz	00101$
                           000182   955 	C$fuzzy.h$1304$1_0$36 ==.
                                    956 ;	../../fuzzy.h:1304: count == 0u
      00023F E5 08            [12]  957 	mov	a,_bp
      000241 24 FC            [12]  958 	add	a,#0xfc
      000243 F8               [12]  959 	mov	r0,a
      000244 E6               [12]  960 	mov	a,@r0
      000245 08               [12]  961 	inc	r0
      000246 46               [12]  962 	orl	a,@r0
      000247 70 0B            [24]  963 	jnz	00102$
      000249                        964 00101$:
                           00018C   965 	C$fuzzy.h$1306$2_0$37 ==.
                                    966 ;	../../fuzzy.h:1306: return LEVEL_HI;
      000249 90 00 00         [24]  967 	mov	dptr,#0x0000
      00024C 75 F0 80         [24]  968 	mov	b, #0x80
      00024F 74 3F            [12]  969 	mov	a, #0x3f
      000251 02 04 C2         [24]  970 	ljmp	00121$
      000254                        971 00102$:
                           000197   972 	C$fuzzy.h$1310$1_0$36 ==.
                                    973 ;	../../fuzzy.h:1310: method != FUZZY_LOGIC_STANDARD &&
      000254 ED               [12]  974 	mov	a,r5
      000255 60 13            [24]  975 	jz	00105$
                           00019A   976 	C$fuzzy.h$1311$1_0$36 ==.
                                    977 ;	../../fuzzy.h:1311: method != FUZZY_LOGIC_ALGEBRAIC &&
      000257 BD 01 02         [24]  978 	cjne	r5,#0x01,00192$
      00025A 80 0E            [24]  979 	sjmp	00105$
      00025C                        980 00192$:
                           00019F   981 	C$fuzzy.h$1313$1_0$36 ==.
                                    982 ;	../../fuzzy.h:1313: ) {
      00025C BD 02 02         [24]  983 	cjne	r5,#0x02,00193$
      00025F 80 09            [24]  984 	sjmp	00105$
      000261                        985 00193$:
                           0001A4   986 	C$fuzzy.h$1314$2_0$38 ==.
                                    987 ;	../../fuzzy.h:1314: return LEVEL_LO;
      000261 90 00 00         [24]  988 	mov	dptr,#0x0000
      000264 E4               [12]  989 	clr	a
      000265 F5 F0            [12]  990 	mov	b,a
      000267 02 04 C2         [24]  991 	ljmp	00121$
      00026A                        992 00105$:
                           0001AD   993 	C$fuzzy.h$1319$1_0$36 ==.
                                    994 ;	../../fuzzy.h:1319: args[0]
      00026A E5 08            [12]  995 	mov	a,_bp
      00026C 24 F9            [12]  996 	add	a,#0xf9
      00026E F8               [12]  997 	mov	r0,a
      00026F A9 08            [24]  998 	mov	r1,_bp
      000271 09               [12]  999 	inc	r1
      000272 E6               [12] 1000 	mov	a,@r0
      000273 F7               [12] 1001 	mov	@r1,a
      000274 08               [12] 1002 	inc	r0
      000275 E6               [12] 1003 	mov	a,@r0
      000276 09               [12] 1004 	inc	r1
      000277 F7               [12] 1005 	mov	@r1,a
      000278 08               [12] 1006 	inc	r0
      000279 E6               [12] 1007 	mov	a,@r0
      00027A 09               [12] 1008 	inc	r1
      00027B F7               [12] 1009 	mov	@r1,a
      00027C A8 08            [24] 1010 	mov	r0,_bp
      00027E 08               [12] 1011 	inc	r0
      00027F 86 82            [24] 1012 	mov	dpl,@r0
      000281 08               [12] 1013 	inc	r0
      000282 86 83            [24] 1014 	mov	dph,@r0
      000284 08               [12] 1015 	inc	r0
      000285 86 F0            [24] 1016 	mov	b,@r0
      000287 12 43 A8         [24] 1017 	lcall	__gptrget
      00028A FA               [12] 1018 	mov	r2,a
      00028B A3               [24] 1019 	inc	dptr
      00028C 12 43 A8         [24] 1020 	lcall	__gptrget
      00028F FB               [12] 1021 	mov	r3,a
      000290 A3               [24] 1022 	inc	dptr
      000291 12 43 A8         [24] 1023 	lcall	__gptrget
      000294 FE               [12] 1024 	mov	r6,a
      000295 A3               [24] 1025 	inc	dptr
      000296 12 43 A8         [24] 1026 	lcall	__gptrget
      000299 8A 82            [24] 1027 	mov	dpl,r2
      00029B 8B 83            [24] 1028 	mov	dph,r3
      00029D 8E F0            [24] 1029 	mov	b,r6
      00029F C0 05            [24] 1030 	push	ar5
      0002A1 12 00 F0         [24] 1031 	lcall	_fuzzy_clamp
      0002A4 C8               [12] 1032 	xch	a,r0
      0002A5 E5 08            [12] 1033 	mov	a,_bp
      0002A7 24 05            [12] 1034 	add	a,#0x05
      0002A9 C8               [12] 1035 	xch	a,r0
      0002AA A6 82            [24] 1036 	mov	@r0, dpl
      0002AC 08               [12] 1037 	inc	r0
      0002AD A6 83            [24] 1038 	mov	@r0, dph
      0002AF 08               [12] 1039 	inc	r0
      0002B0 A6 F0            [24] 1040 	mov	@r0, b
      0002B2 08               [12] 1041 	inc	r0
      0002B3 F6               [12] 1042 	mov	@r0,a
      0002B4 D0 05            [24] 1043 	pop	ar5
                           0001F9  1044 	C$fuzzy.h$1323$3_0$40 ==.
                                   1045 ;	../../fuzzy.h:1323: index = 1u;
      0002B6 E4               [12] 1046 	clr	a
      0002B7 BD 00 01         [24] 1047 	cjne	r5,#0x00,00194$
      0002BA 04               [12] 1048 	inc	a
      0002BB                       1049 00194$:
      0002BB FB               [12] 1050 	mov	r3,a
      0002BC BD 01 03         [24] 1051 	cjne	r5,#0x01,00196$
      0002BF ED               [12] 1052 	mov	a,r5
      0002C0 80 01            [24] 1053 	sjmp	00197$
      0002C2                       1054 00196$:
      0002C2 E4               [12] 1055 	clr	a
      0002C3                       1056 00197$:
      0002C3 FA               [12] 1057 	mov	r2,a
      0002C4 E5 08            [12] 1058 	mov	a,_bp
      0002C6 24 04            [12] 1059 	add	a,#0x04
      0002C8 F8               [12] 1060 	mov	r0,a
      0002C9 E4               [12] 1061 	clr	a
      0002CA BD 02 01         [24] 1062 	cjne	r5,#0x02,00198$
      0002CD 04               [12] 1063 	inc	a
      0002CE                       1064 00198$:
      0002CE F6               [12] 1065 	mov	@r0,a
      0002CF E5 08            [12] 1066 	mov	a,_bp
      0002D1 24 0D            [12] 1067 	add	a,#0x0d
      0002D3 F8               [12] 1068 	mov	r0,a
      0002D4 76 01            [12] 1069 	mov	@r0,#0x01
      0002D6 08               [12] 1070 	inc	r0
      0002D7 76 00            [12] 1071 	mov	@r0,#0x00
      0002D9                       1072 00119$:
                           00021C  1073 	C$fuzzy.h$1324$2_0$39 ==.
                                   1074 ;	../../fuzzy.h:1324: index < count;
      0002D9 E5 08            [12] 1075 	mov	a,_bp
      0002DB 24 0D            [12] 1076 	add	a,#0x0d
      0002DD F8               [12] 1077 	mov	r0,a
      0002DE E5 08            [12] 1078 	mov	a,_bp
      0002E0 24 FC            [12] 1079 	add	a,#0xfc
      0002E2 F9               [12] 1080 	mov	r1,a
      0002E3 C3               [12] 1081 	clr	c
      0002E4 E6               [12] 1082 	mov	a,@r0
      0002E5 97               [12] 1083 	subb	a,@r1
      0002E6 08               [12] 1084 	inc	r0
      0002E7 E6               [12] 1085 	mov	a,@r0
      0002E8 09               [12] 1086 	inc	r1
      0002E9 97               [12] 1087 	subb	a,@r1
      0002EA 40 03            [24] 1088 	jc	00200$
      0002EC 02 04 B0         [24] 1089 	ljmp	00117$
      0002EF                       1090 00200$:
                           000232  1091 	C$fuzzy.h$1329$1_0$36 ==.
                                   1092 ;	../../fuzzy.h:1329: args[index]
      0002EF C0 02            [24] 1093 	push	ar2
      0002F1 E5 08            [12] 1094 	mov	a,_bp
      0002F3 24 0D            [12] 1095 	add	a,#0x0d
      0002F5 F8               [12] 1096 	mov	r0,a
      0002F6 E6               [12] 1097 	mov	a,@r0
      0002F7 26               [12] 1098 	add	a,@r0
      0002F8 FD               [12] 1099 	mov	r5,a
      0002F9 08               [12] 1100 	inc	r0
      0002FA E6               [12] 1101 	mov	a,@r0
      0002FB 33               [12] 1102 	rlc	a
      0002FC FC               [12] 1103 	mov	r4,a
      0002FD ED               [12] 1104 	mov	a,r5
      0002FE 2D               [12] 1105 	add	a,r5
      0002FF FD               [12] 1106 	mov	r5,a
      000300 EC               [12] 1107 	mov	a,r4
      000301 33               [12] 1108 	rlc	a
      000302 FC               [12] 1109 	mov	r4,a
      000303 A8 08            [24] 1110 	mov	r0,_bp
      000305 08               [12] 1111 	inc	r0
      000306 ED               [12] 1112 	mov	a,r5
      000307 26               [12] 1113 	add	a, @r0
      000308 FA               [12] 1114 	mov	r2,a
      000309 EC               [12] 1115 	mov	a,r4
      00030A 08               [12] 1116 	inc	r0
      00030B 36               [12] 1117 	addc	a, @r0
      00030C FC               [12] 1118 	mov	r4,a
      00030D 08               [12] 1119 	inc	r0
      00030E 86 05            [24] 1120 	mov	ar5,@r0
      000310 8A 82            [24] 1121 	mov	dpl,r2
      000312 8C 83            [24] 1122 	mov	dph,r4
      000314 8D F0            [24] 1123 	mov	b,r5
      000316 12 43 A8         [24] 1124 	lcall	__gptrget
      000319 FA               [12] 1125 	mov	r2,a
      00031A A3               [24] 1126 	inc	dptr
      00031B 12 43 A8         [24] 1127 	lcall	__gptrget
      00031E FC               [12] 1128 	mov	r4,a
      00031F A3               [24] 1129 	inc	dptr
      000320 12 43 A8         [24] 1130 	lcall	__gptrget
      000323 FD               [12] 1131 	mov	r5,a
      000324 A3               [24] 1132 	inc	dptr
      000325 12 43 A8         [24] 1133 	lcall	__gptrget
      000328 8A 82            [24] 1134 	mov	dpl,r2
      00032A 8C 83            [24] 1135 	mov	dph,r4
      00032C 8D F0            [24] 1136 	mov	b,r5
      00032E C0 03            [24] 1137 	push	ar3
      000330 C0 02            [24] 1138 	push	ar2
      000332 12 00 F0         [24] 1139 	lcall	_fuzzy_clamp
      000335 C8               [12] 1140 	xch	a,r0
      000336 E5 08            [12] 1141 	mov	a,_bp
      000338 24 09            [12] 1142 	add	a,#0x09
      00033A C8               [12] 1143 	xch	a,r0
      00033B A6 82            [24] 1144 	mov	@r0, dpl
      00033D 08               [12] 1145 	inc	r0
      00033E A6 83            [24] 1146 	mov	@r0, dph
      000340 08               [12] 1147 	inc	r0
      000341 A6 F0            [24] 1148 	mov	@r0, b
      000343 08               [12] 1149 	inc	r0
      000344 F6               [12] 1150 	mov	@r0,a
      000345 D0 02            [24] 1151 	pop	ar2
      000347 D0 03            [24] 1152 	pop	ar3
                           00028C  1153 	C$fuzzy.h$1332$1_0$36 ==.
                                   1154 ;	../../fuzzy.h:1332: switch (method) {
      000349 D0 02            [24] 1155 	pop	ar2
      00034B EB               [12] 1156 	mov	a,r3
      00034C 70 11            [24] 1157 	jnz	00108$
      00034E EA               [12] 1158 	mov	a,r2
      00034F 70 65            [24] 1159 	jnz	00111$
      000351 E5 08            [12] 1160 	mov	a,_bp
      000353 24 04            [12] 1161 	add	a,#0x04
      000355 F8               [12] 1162 	mov	r0,a
      000356 E6               [12] 1163 	mov	a,@r0
      000357 60 03            [24] 1164 	jz	00203$
      000359 02 03 FD         [24] 1165 	ljmp	00112$
      00035C                       1166 00203$:
      00035C 02 04 9A         [24] 1167 	ljmp	00115$
                           0002A2  1168 	C$fuzzy.h$1333$4_0$41 ==.
                                   1169 ;	../../fuzzy.h:1333: case FUZZY_LOGIC_STANDARD:
      00035F                       1170 00108$:
                           0002A2  1171 	C$fuzzy.h$1334$1_0$36 ==.
                                   1172 ;	../../fuzzy.h:1334: if (next < result) {
      00035F C0 03            [24] 1173 	push	ar3
      000361 C0 02            [24] 1174 	push	ar2
      000363 E5 08            [12] 1175 	mov	a,_bp
      000365 24 05            [12] 1176 	add	a,#0x05
      000367 F8               [12] 1177 	mov	r0,a
      000368 E6               [12] 1178 	mov	a,@r0
      000369 C0 E0            [24] 1179 	push	acc
      00036B 08               [12] 1180 	inc	r0
      00036C E6               [12] 1181 	mov	a,@r0
      00036D C0 E0            [24] 1182 	push	acc
      00036F 08               [12] 1183 	inc	r0
      000370 E6               [12] 1184 	mov	a,@r0
      000371 C0 E0            [24] 1185 	push	acc
      000373 08               [12] 1186 	inc	r0
      000374 E6               [12] 1187 	mov	a,@r0
      000375 C0 E0            [24] 1188 	push	acc
      000377 E5 08            [12] 1189 	mov	a,_bp
      000379 24 09            [12] 1190 	add	a,#0x09
      00037B F8               [12] 1191 	mov	r0,a
      00037C 86 82            [24] 1192 	mov	dpl, @r0
      00037E 08               [12] 1193 	inc	r0
      00037F 86 83            [24] 1194 	mov	dph, @r0
      000381 08               [12] 1195 	inc	r0
      000382 86 F0            [24] 1196 	mov	b, @r0
      000384 08               [12] 1197 	inc	r0
      000385 E6               [12] 1198 	mov	a, @r0
      000386 12 41 7C         [24] 1199 	lcall	___fslt
      000389 AF 82            [24] 1200 	mov	r7, dpl
      00038B E5 81            [12] 1201 	mov	a,sp
      00038D 24 FC            [12] 1202 	add	a,#0xfc
      00038F F5 81            [12] 1203 	mov	sp,a
      000391 D0 02            [24] 1204 	pop	ar2
      000393 D0 03            [24] 1205 	pop	ar3
      000395 EF               [12] 1206 	mov	a,r7
      000396 70 03            [24] 1207 	jnz	00204$
      000398 02 04 A2         [24] 1208 	ljmp	00120$
      00039B                       1209 00204$:
                           0002DE  1210 	C$fuzzy.h$1335$5_0$42 ==.
                                   1211 ;	../../fuzzy.h:1335: result = next;
      00039B E5 08            [12] 1212 	mov	a,_bp
      00039D 24 09            [12] 1213 	add	a,#0x09
      00039F F8               [12] 1214 	mov	r0,a
      0003A0 E5 08            [12] 1215 	mov	a,_bp
      0003A2 24 05            [12] 1216 	add	a,#0x05
      0003A4 F9               [12] 1217 	mov	r1,a
      0003A5 E6               [12] 1218 	mov	a,@r0
      0003A6 F7               [12] 1219 	mov	@r1,a
      0003A7 08               [12] 1220 	inc	r0
      0003A8 E6               [12] 1221 	mov	a,@r0
      0003A9 09               [12] 1222 	inc	r1
      0003AA F7               [12] 1223 	mov	@r1,a
      0003AB 08               [12] 1224 	inc	r0
      0003AC E6               [12] 1225 	mov	a,@r0
      0003AD 09               [12] 1226 	inc	r1
      0003AE F7               [12] 1227 	mov	@r1,a
      0003AF 08               [12] 1228 	inc	r0
      0003B0 E6               [12] 1229 	mov	a,@r0
      0003B1 09               [12] 1230 	inc	r1
      0003B2 F7               [12] 1231 	mov	@r1,a
                           0002F6  1232 	C$fuzzy.h$1337$4_0$41 ==.
                                   1233 ;	../../fuzzy.h:1337: break;
      0003B3 02 04 A2         [24] 1234 	ljmp	00120$
                           0002F9  1235 	C$fuzzy.h$1339$4_0$41 ==.
                                   1236 ;	../../fuzzy.h:1339: case FUZZY_LOGIC_ALGEBRAIC:
      0003B6                       1237 00111$:
                           0002F9  1238 	C$fuzzy.h$1341$1_0$36 ==.
                                   1239 ;	../../fuzzy.h:1341: next;
      0003B6 C0 03            [24] 1240 	push	ar3
      0003B8 C0 02            [24] 1241 	push	ar2
      0003BA E5 08            [12] 1242 	mov	a,_bp
      0003BC 24 09            [12] 1243 	add	a,#0x09
      0003BE F8               [12] 1244 	mov	r0,a
      0003BF E6               [12] 1245 	mov	a,@r0
      0003C0 C0 E0            [24] 1246 	push	acc
      0003C2 08               [12] 1247 	inc	r0
      0003C3 E6               [12] 1248 	mov	a,@r0
      0003C4 C0 E0            [24] 1249 	push	acc
      0003C6 08               [12] 1250 	inc	r0
      0003C7 E6               [12] 1251 	mov	a,@r0
      0003C8 C0 E0            [24] 1252 	push	acc
      0003CA 08               [12] 1253 	inc	r0
      0003CB E6               [12] 1254 	mov	a,@r0
      0003CC C0 E0            [24] 1255 	push	acc
                           000311  1256 	C$fuzzy.h$1342$1_0$36 ==.
                                   1257 ;	../../fuzzy.h:1342: break;
      0003CE E5 08            [12] 1258 	mov	a,_bp
      0003D0 24 05            [12] 1259 	add	a,#0x05
      0003D2 F8               [12] 1260 	mov	r0,a
      0003D3 86 82            [24] 1261 	mov	dpl, @r0
      0003D5 08               [12] 1262 	inc	r0
      0003D6 86 83            [24] 1263 	mov	dph, @r0
      0003D8 08               [12] 1264 	inc	r0
      0003D9 86 F0            [24] 1265 	mov	b, @r0
      0003DB 08               [12] 1266 	inc	r0
      0003DC E6               [12] 1267 	mov	a, @r0
      0003DD 12 40 4C         [24] 1268 	lcall	___fsmul
      0003E0 C8               [12] 1269 	xch	a,r0
      0003E1 E5 08            [12] 1270 	mov	a,_bp
      0003E3 24 05            [12] 1271 	add	a,#0x05
      0003E5 C8               [12] 1272 	xch	a,r0
      0003E6 A6 82            [24] 1273 	mov	@r0, dpl
      0003E8 08               [12] 1274 	inc	r0
      0003E9 A6 83            [24] 1275 	mov	@r0, dph
      0003EB 08               [12] 1276 	inc	r0
      0003EC A6 F0            [24] 1277 	mov	@r0, b
      0003EE 08               [12] 1278 	inc	r0
      0003EF F6               [12] 1279 	mov	@r0,a
      0003F0 E5 81            [12] 1280 	mov	a,sp
      0003F2 24 FC            [12] 1281 	add	a,#0xfc
      0003F4 F5 81            [12] 1282 	mov	sp,a
      0003F6 D0 02            [24] 1283 	pop	ar2
      0003F8 D0 03            [24] 1284 	pop	ar3
      0003FA 02 04 A2         [24] 1285 	ljmp	00120$
                           000340  1286 	C$fuzzy.h$1344$4_0$41 ==.
                                   1287 ;	../../fuzzy.h:1344: case FUZZY_LOGIC_BOUNDED:
      0003FD                       1288 00112$:
                           000340  1289 	C$fuzzy.h$1347$1_0$36 ==.
                                   1290 ;	../../fuzzy.h:1347: next -
      0003FD C0 03            [24] 1291 	push	ar3
      0003FF C0 02            [24] 1292 	push	ar2
      000401 E5 08            [12] 1293 	mov	a,_bp
      000403 24 09            [12] 1294 	add	a,#0x09
      000405 F8               [12] 1295 	mov	r0,a
      000406 E6               [12] 1296 	mov	a,@r0
      000407 C0 E0            [24] 1297 	push	acc
      000409 08               [12] 1298 	inc	r0
      00040A E6               [12] 1299 	mov	a,@r0
      00040B C0 E0            [24] 1300 	push	acc
      00040D 08               [12] 1301 	inc	r0
      00040E E6               [12] 1302 	mov	a,@r0
      00040F C0 E0            [24] 1303 	push	acc
      000411 08               [12] 1304 	inc	r0
      000412 E6               [12] 1305 	mov	a,@r0
      000413 C0 E0            [24] 1306 	push	acc
      000415 E5 08            [12] 1307 	mov	a,_bp
      000417 24 05            [12] 1308 	add	a,#0x05
      000419 F8               [12] 1309 	mov	r0,a
      00041A 86 82            [24] 1310 	mov	dpl, @r0
      00041C 08               [12] 1311 	inc	r0
      00041D 86 83            [24] 1312 	mov	dph, @r0
      00041F 08               [12] 1313 	inc	r0
      000420 86 F0            [24] 1314 	mov	b, @r0
      000422 08               [12] 1315 	inc	r0
      000423 E6               [12] 1316 	mov	a, @r0
      000424 12 41 CE         [24] 1317 	lcall	___fsadd
      000427 AC 82            [24] 1318 	mov	r4, dpl
      000429 AD 83            [24] 1319 	mov	r5, dph
      00042B AE F0            [24] 1320 	mov	r6, b
      00042D FF               [12] 1321 	mov	r7, a
      00042E E5 81            [12] 1322 	mov	a,sp
      000430 24 FC            [12] 1323 	add	a,#0xfc
      000432 F5 81            [12] 1324 	mov	sp,a
      000434 E4               [12] 1325 	clr	a
      000435 C0 E0            [24] 1326 	push	acc
      000437 C0 E0            [24] 1327 	push	acc
      000439 74 80            [12] 1328 	mov	a,#0x80
      00043B C0 E0            [24] 1329 	push	acc
      00043D 74 3F            [12] 1330 	mov	a,#0x3f
      00043F C0 E0            [24] 1331 	push	acc
                           000384  1332 	C$fuzzy.h$1350$1_0$36 ==.
                                   1333 ;	../../fuzzy.h:1350: if (result < LEVEL_LO) {
      000441 8C 82            [24] 1334 	mov	dpl, r4
      000443 8D 83            [24] 1335 	mov	dph, r5
      000445 8E F0            [24] 1336 	mov	b, r6
      000447 EF               [12] 1337 	mov	a, r7
      000448 12 40 41         [24] 1338 	lcall	___fssub
      00044B C8               [12] 1339 	xch	a,r0
      00044C E5 08            [12] 1340 	mov	a,_bp
      00044E 24 05            [12] 1341 	add	a,#0x05
      000450 C8               [12] 1342 	xch	a,r0
      000451 A6 82            [24] 1343 	mov	@r0, dpl
      000453 08               [12] 1344 	inc	r0
      000454 A6 83            [24] 1345 	mov	@r0, dph
      000456 08               [12] 1346 	inc	r0
      000457 A6 F0            [24] 1347 	mov	@r0, b
      000459 08               [12] 1348 	inc	r0
      00045A F6               [12] 1349 	mov	@r0,a
      00045B E5 81            [12] 1350 	mov	a,sp
      00045D 24 FC            [12] 1351 	add	a,#0xfc
      00045F F5 81            [12] 1352 	mov	sp,a
      000461 E4               [12] 1353 	clr	a
      000462 C0 E0            [24] 1354 	push	acc
      000464 C0 E0            [24] 1355 	push	acc
      000466 C0 E0            [24] 1356 	push	acc
      000468 C0 E0            [24] 1357 	push	acc
      00046A E5 08            [12] 1358 	mov	a,_bp
      00046C 24 05            [12] 1359 	add	a,#0x05
      00046E F8               [12] 1360 	mov	r0,a
      00046F 86 82            [24] 1361 	mov	dpl, @r0
      000471 08               [12] 1362 	inc	r0
      000472 86 83            [24] 1363 	mov	dph, @r0
      000474 08               [12] 1364 	inc	r0
      000475 86 F0            [24] 1365 	mov	b, @r0
      000477 08               [12] 1366 	inc	r0
      000478 E6               [12] 1367 	mov	a, @r0
      000479 12 41 7C         [24] 1368 	lcall	___fslt
      00047C AF 82            [24] 1369 	mov	r7, dpl
      00047E E5 81            [12] 1370 	mov	a,sp
      000480 24 FC            [12] 1371 	add	a,#0xfc
      000482 F5 81            [12] 1372 	mov	sp,a
      000484 D0 02            [24] 1373 	pop	ar2
      000486 D0 03            [24] 1374 	pop	ar3
      000488 EF               [12] 1375 	mov	a,r7
      000489 60 17            [24] 1376 	jz	00120$
                           0003CE  1377 	C$fuzzy.h$1351$5_0$43 ==.
                                   1378 ;	../../fuzzy.h:1351: result = LEVEL_LO;
      00048B E5 08            [12] 1379 	mov	a,_bp
      00048D 24 05            [12] 1380 	add	a,#0x05
      00048F F8               [12] 1381 	mov	r0,a
      000490 E4               [12] 1382 	clr	a
      000491 F6               [12] 1383 	mov	@r0,a
      000492 08               [12] 1384 	inc	r0
      000493 F6               [12] 1385 	mov	@r0,a
      000494 08               [12] 1386 	inc	r0
      000495 F6               [12] 1387 	mov	@r0,a
      000496 08               [12] 1388 	inc	r0
      000497 F6               [12] 1389 	mov	@r0,a
                           0003DB  1390 	C$fuzzy.h$1353$4_0$41 ==.
                                   1391 ;	../../fuzzy.h:1353: break;
                           0003DB  1392 	C$fuzzy.h$1355$4_0$41 ==.
                                   1393 ;	../../fuzzy.h:1355: default:
      000498 80 08            [24] 1394 	sjmp	00120$
      00049A                       1395 00115$:
                           0003DD  1396 	C$fuzzy.h$1356$4_0$41 ==.
                                   1397 ;	../../fuzzy.h:1356: return LEVEL_LO;
      00049A 90 00 00         [24] 1398 	mov	dptr,#0x0000
      00049D E4               [12] 1399 	clr	a
      00049E F5 F0            [12] 1400 	mov	b,a
                           0003E3  1401 	C$fuzzy.h$1357$3_0$40 ==.
                                   1402 ;	../../fuzzy.h:1357: }
      0004A0 80 20            [24] 1403 	sjmp	00121$
      0004A2                       1404 00120$:
                           0003E5  1405 	C$fuzzy.h$1325$2_0$39 ==.
                                   1406 ;	../../fuzzy.h:1325: index++
      0004A2 E5 08            [12] 1407 	mov	a,_bp
      0004A4 24 0D            [12] 1408 	add	a,#0x0d
      0004A6 F8               [12] 1409 	mov	r0,a
      0004A7 06               [12] 1410 	inc	@r0
      0004A8 B6 00 02         [24] 1411 	cjne	@r0,#0x00,00206$
      0004AB 08               [12] 1412 	inc	r0
      0004AC 06               [12] 1413 	inc	@r0
      0004AD                       1414 00206$:
      0004AD 02 02 D9         [24] 1415 	ljmp	00119$
      0004B0                       1416 00117$:
                           0003F3  1417 	C$fuzzy.h$1361$1_0$36 ==.
                                   1418 ;	../../fuzzy.h:1361: result
      0004B0 E5 08            [12] 1419 	mov	a,_bp
      0004B2 24 05            [12] 1420 	add	a,#0x05
      0004B4 F8               [12] 1421 	mov	r0,a
      0004B5 86 82            [24] 1422 	mov	dpl, @r0
      0004B7 08               [12] 1423 	inc	r0
      0004B8 86 83            [24] 1424 	mov	dph, @r0
      0004BA 08               [12] 1425 	inc	r0
      0004BB 86 F0            [24] 1426 	mov	b, @r0
      0004BD 08               [12] 1427 	inc	r0
      0004BE E6               [12] 1428 	mov	a, @r0
      0004BF 12 00 F0         [24] 1429 	lcall	_fuzzy_clamp
      0004C2                       1430 00121$:
                           000405  1431 	C$fuzzy.h$1363$1_0$36 ==.
                                   1432 ;	../../fuzzy.h:1363: }
      0004C2 85 08 81         [24] 1433 	mov	sp,_bp
      0004C5 D0 08            [24] 1434 	pop	_bp
                           00040A  1435 	C$fuzzy.h$1363$1_0$36 ==.
                           00040A  1436 	XG$fuzzy_and_array$0$0 ==.
      0004C7 22               [24] 1437 	ret
                                   1438 ;------------------------------------------------------------
                                   1439 ;Allocation info for local variables in function 'fuzzy_or_array'
                                   1440 ;------------------------------------------------------------
                                   1441 ;count         Allocated to stack - _bp -4 +2 
                                   1442 ;args          Allocated to stack - _bp -7 +3 
                                   1443 ;method        Allocated to registers r5 
                                   1444 ;result        Allocated to stack - _bp +10 +4 
                                   1445 ;next          Allocated to registers r4 r5 r6 r3 
                                   1446 ;index         Allocated to stack - _bp +14 +2 
                                   1447 ;sloc0         Allocated to stack - _bp +1 +3 
                                   1448 ;sloc1         Allocated to stack - _bp +4 +1 
                                   1449 ;sloc2         Allocated to stack - _bp +5 +1 
                                   1450 ;sloc3         Allocated to stack - _bp +6 +4 
                                   1451 ;------------------------------------------------------------
                           00040B  1452 	G$fuzzy_or_array$0$0 ==.
                           00040B  1453 	C$fuzzy.h$1378$1_0$45 ==.
                                   1454 ;	../../fuzzy.h:1378: float fuzzy_or_array(
                                   1455 ;	-----------------------------------------
                                   1456 ;	 function fuzzy_or_array
                                   1457 ;	-----------------------------------------
      0004C8                       1458 _fuzzy_or_array:
      0004C8 C0 08            [24] 1459 	push	_bp
      0004CA E5 81            [12] 1460 	mov	a,sp
      0004CC F5 08            [12] 1461 	mov	_bp,a
      0004CE 24 0F            [12] 1462 	add	a,#0x0f
      0004D0 F5 81            [12] 1463 	mov	sp,a
      0004D2 AD 82            [24] 1464 	mov	r5, dpl
                           000417  1465 	C$fuzzy.h$1389$1_0$45 ==.
                                   1466 ;	../../fuzzy.h:1389: args == NULL ||
      0004D4 E5 08            [12] 1467 	mov	a,_bp
      0004D6 24 F9            [12] 1468 	add	a,#0xf9
      0004D8 F8               [12] 1469 	mov	r0,a
      0004D9 E6               [12] 1470 	mov	a,@r0
      0004DA 08               [12] 1471 	inc	r0
      0004DB 46               [12] 1472 	orl	a,@r0
      0004DC 60 0A            [24] 1473 	jz	00101$
                           000421  1474 	C$fuzzy.h$1390$1_0$45 ==.
                                   1475 ;	../../fuzzy.h:1390: count == 0u
      0004DE E5 08            [12] 1476 	mov	a,_bp
      0004E0 24 FC            [12] 1477 	add	a,#0xfc
      0004E2 F8               [12] 1478 	mov	r0,a
      0004E3 E6               [12] 1479 	mov	a,@r0
      0004E4 08               [12] 1480 	inc	r0
      0004E5 46               [12] 1481 	orl	a,@r0
      0004E6 70 09            [24] 1482 	jnz	00102$
      0004E8                       1483 00101$:
                           00042B  1484 	C$fuzzy.h$1392$2_0$46 ==.
                                   1485 ;	../../fuzzy.h:1392: return LEVEL_LO;
      0004E8 90 00 00         [24] 1486 	mov	dptr,#0x0000
      0004EB E4               [12] 1487 	clr	a
      0004EC F5 F0            [12] 1488 	mov	b,a
      0004EE 02 07 84         [24] 1489 	ljmp	00121$
      0004F1                       1490 00102$:
                           000434  1491 	C$fuzzy.h$1396$1_0$45 ==.
                                   1492 ;	../../fuzzy.h:1396: method != FUZZY_LOGIC_STANDARD &&
      0004F1 ED               [12] 1493 	mov	a,r5
      0004F2 60 13            [24] 1494 	jz	00105$
                           000437  1495 	C$fuzzy.h$1397$1_0$45 ==.
                                   1496 ;	../../fuzzy.h:1397: method != FUZZY_LOGIC_ALGEBRAIC &&
      0004F4 BD 01 02         [24] 1497 	cjne	r5,#0x01,00192$
      0004F7 80 0E            [24] 1498 	sjmp	00105$
      0004F9                       1499 00192$:
                           00043C  1500 	C$fuzzy.h$1399$1_0$45 ==.
                                   1501 ;	../../fuzzy.h:1399: ) {
      0004F9 BD 02 02         [24] 1502 	cjne	r5,#0x02,00193$
      0004FC 80 09            [24] 1503 	sjmp	00105$
      0004FE                       1504 00193$:
                           000441  1505 	C$fuzzy.h$1400$2_0$47 ==.
                                   1506 ;	../../fuzzy.h:1400: return LEVEL_LO;
      0004FE 90 00 00         [24] 1507 	mov	dptr,#0x0000
      000501 E4               [12] 1508 	clr	a
      000502 F5 F0            [12] 1509 	mov	b,a
      000504 02 07 84         [24] 1510 	ljmp	00121$
      000507                       1511 00105$:
                           00044A  1512 	C$fuzzy.h$1405$1_0$45 ==.
                                   1513 ;	../../fuzzy.h:1405: args[0]
      000507 E5 08            [12] 1514 	mov	a,_bp
      000509 24 F9            [12] 1515 	add	a,#0xf9
      00050B F8               [12] 1516 	mov	r0,a
      00050C A9 08            [24] 1517 	mov	r1,_bp
      00050E 09               [12] 1518 	inc	r1
      00050F E6               [12] 1519 	mov	a,@r0
      000510 F7               [12] 1520 	mov	@r1,a
      000511 08               [12] 1521 	inc	r0
      000512 E6               [12] 1522 	mov	a,@r0
      000513 09               [12] 1523 	inc	r1
      000514 F7               [12] 1524 	mov	@r1,a
      000515 08               [12] 1525 	inc	r0
      000516 E6               [12] 1526 	mov	a,@r0
      000517 09               [12] 1527 	inc	r1
      000518 F7               [12] 1528 	mov	@r1,a
      000519 A8 08            [24] 1529 	mov	r0,_bp
      00051B 08               [12] 1530 	inc	r0
      00051C 86 82            [24] 1531 	mov	dpl,@r0
      00051E 08               [12] 1532 	inc	r0
      00051F 86 83            [24] 1533 	mov	dph,@r0
      000521 08               [12] 1534 	inc	r0
      000522 86 F0            [24] 1535 	mov	b,@r0
      000524 12 43 A8         [24] 1536 	lcall	__gptrget
      000527 FA               [12] 1537 	mov	r2,a
      000528 A3               [24] 1538 	inc	dptr
      000529 12 43 A8         [24] 1539 	lcall	__gptrget
      00052C FB               [12] 1540 	mov	r3,a
      00052D A3               [24] 1541 	inc	dptr
      00052E 12 43 A8         [24] 1542 	lcall	__gptrget
      000531 FE               [12] 1543 	mov	r6,a
      000532 A3               [24] 1544 	inc	dptr
      000533 12 43 A8         [24] 1545 	lcall	__gptrget
      000536 8A 82            [24] 1546 	mov	dpl,r2
      000538 8B 83            [24] 1547 	mov	dph,r3
      00053A 8E F0            [24] 1548 	mov	b,r6
      00053C C0 05            [24] 1549 	push	ar5
      00053E 12 00 F0         [24] 1550 	lcall	_fuzzy_clamp
      000541 C8               [12] 1551 	xch	a,r0
      000542 E5 08            [12] 1552 	mov	a,_bp
      000544 24 0A            [12] 1553 	add	a,#0x0a
      000546 C8               [12] 1554 	xch	a,r0
      000547 A6 82            [24] 1555 	mov	@r0, dpl
      000549 08               [12] 1556 	inc	r0
      00054A A6 83            [24] 1557 	mov	@r0, dph
      00054C 08               [12] 1558 	inc	r0
      00054D A6 F0            [24] 1559 	mov	@r0, b
      00054F 08               [12] 1560 	inc	r0
      000550 F6               [12] 1561 	mov	@r0,a
      000551 D0 05            [24] 1562 	pop	ar5
                           000496  1563 	C$fuzzy.h$1409$3_0$49 ==.
                                   1564 ;	../../fuzzy.h:1409: index = 1u;
      000553 E5 08            [12] 1565 	mov	a,_bp
      000555 24 05            [12] 1566 	add	a,#0x05
      000557 F8               [12] 1567 	mov	r0,a
      000558 E4               [12] 1568 	clr	a
      000559 BD 00 01         [24] 1569 	cjne	r5,#0x00,00194$
      00055C 04               [12] 1570 	inc	a
      00055D                       1571 00194$:
      00055D F6               [12] 1572 	mov	@r0,a
      00055E BD 01 03         [24] 1573 	cjne	r5,#0x01,00196$
      000561 ED               [12] 1574 	mov	a,r5
      000562 80 01            [24] 1575 	sjmp	00197$
      000564                       1576 00196$:
      000564 E4               [12] 1577 	clr	a
      000565                       1578 00197$:
      000565 FA               [12] 1579 	mov	r2,a
      000566 E5 08            [12] 1580 	mov	a,_bp
      000568 24 04            [12] 1581 	add	a,#0x04
      00056A F8               [12] 1582 	mov	r0,a
      00056B E4               [12] 1583 	clr	a
      00056C BD 02 01         [24] 1584 	cjne	r5,#0x02,00198$
      00056F 04               [12] 1585 	inc	a
      000570                       1586 00198$:
      000570 F6               [12] 1587 	mov	@r0,a
      000571 E5 08            [12] 1588 	mov	a,_bp
      000573 24 0E            [12] 1589 	add	a,#0x0e
      000575 F8               [12] 1590 	mov	r0,a
      000576 76 01            [12] 1591 	mov	@r0,#0x01
      000578 08               [12] 1592 	inc	r0
      000579 76 00            [12] 1593 	mov	@r0,#0x00
      00057B                       1594 00119$:
                           0004BE  1595 	C$fuzzy.h$1410$2_0$48 ==.
                                   1596 ;	../../fuzzy.h:1410: index < count;
      00057B E5 08            [12] 1597 	mov	a,_bp
      00057D 24 0E            [12] 1598 	add	a,#0x0e
      00057F F8               [12] 1599 	mov	r0,a
      000580 E5 08            [12] 1600 	mov	a,_bp
      000582 24 FC            [12] 1601 	add	a,#0xfc
      000584 F9               [12] 1602 	mov	r1,a
      000585 C3               [12] 1603 	clr	c
      000586 E6               [12] 1604 	mov	a,@r0
      000587 97               [12] 1605 	subb	a,@r1
      000588 08               [12] 1606 	inc	r0
      000589 E6               [12] 1607 	mov	a,@r0
      00058A 09               [12] 1608 	inc	r1
      00058B 97               [12] 1609 	subb	a,@r1
      00058C 40 03            [24] 1610 	jc	00200$
      00058E 02 07 72         [24] 1611 	ljmp	00117$
      000591                       1612 00200$:
                           0004D4  1613 	C$fuzzy.h$1415$1_0$45 ==.
                                   1614 ;	../../fuzzy.h:1415: args[index]
      000591 C0 02            [24] 1615 	push	ar2
      000593 E5 08            [12] 1616 	mov	a,_bp
      000595 24 0E            [12] 1617 	add	a,#0x0e
      000597 F8               [12] 1618 	mov	r0,a
      000598 E6               [12] 1619 	mov	a,@r0
      000599 26               [12] 1620 	add	a,@r0
      00059A FD               [12] 1621 	mov	r5,a
      00059B 08               [12] 1622 	inc	r0
      00059C E6               [12] 1623 	mov	a,@r0
      00059D 33               [12] 1624 	rlc	a
      00059E FC               [12] 1625 	mov	r4,a
      00059F ED               [12] 1626 	mov	a,r5
      0005A0 2D               [12] 1627 	add	a,r5
      0005A1 FD               [12] 1628 	mov	r5,a
      0005A2 EC               [12] 1629 	mov	a,r4
      0005A3 33               [12] 1630 	rlc	a
      0005A4 FC               [12] 1631 	mov	r4,a
      0005A5 A8 08            [24] 1632 	mov	r0,_bp
      0005A7 08               [12] 1633 	inc	r0
      0005A8 ED               [12] 1634 	mov	a,r5
      0005A9 26               [12] 1635 	add	a, @r0
      0005AA FA               [12] 1636 	mov	r2,a
      0005AB EC               [12] 1637 	mov	a,r4
      0005AC 08               [12] 1638 	inc	r0
      0005AD 36               [12] 1639 	addc	a, @r0
      0005AE FC               [12] 1640 	mov	r4,a
      0005AF 08               [12] 1641 	inc	r0
      0005B0 86 05            [24] 1642 	mov	ar5,@r0
      0005B2 8A 82            [24] 1643 	mov	dpl,r2
      0005B4 8C 83            [24] 1644 	mov	dph,r4
      0005B6 8D F0            [24] 1645 	mov	b,r5
      0005B8 12 43 A8         [24] 1646 	lcall	__gptrget
      0005BB FA               [12] 1647 	mov	r2,a
      0005BC A3               [24] 1648 	inc	dptr
      0005BD 12 43 A8         [24] 1649 	lcall	__gptrget
      0005C0 FC               [12] 1650 	mov	r4,a
      0005C1 A3               [24] 1651 	inc	dptr
      0005C2 12 43 A8         [24] 1652 	lcall	__gptrget
      0005C5 FD               [12] 1653 	mov	r5,a
      0005C6 A3               [24] 1654 	inc	dptr
      0005C7 12 43 A8         [24] 1655 	lcall	__gptrget
      0005CA 8A 82            [24] 1656 	mov	dpl,r2
      0005CC 8C 83            [24] 1657 	mov	dph,r4
      0005CE 8D F0            [24] 1658 	mov	b,r5
      0005D0 C0 02            [24] 1659 	push	ar2
      0005D2 12 00 F0         [24] 1660 	lcall	_fuzzy_clamp
      0005D5 AC 82            [24] 1661 	mov	r4, dpl
      0005D7 AD 83            [24] 1662 	mov	r5, dph
      0005D9 AE F0            [24] 1663 	mov	r6, b
      0005DB FB               [12] 1664 	mov	r3, a
      0005DC D0 02            [24] 1665 	pop	ar2
                           000521  1666 	C$fuzzy.h$1418$1_0$45 ==.
                                   1667 ;	../../fuzzy.h:1418: switch (method) {
      0005DE D0 02            [24] 1668 	pop	ar2
      0005E0 E5 08            [12] 1669 	mov	a,_bp
      0005E2 24 05            [12] 1670 	add	a,#0x05
      0005E4 F8               [12] 1671 	mov	r0,a
      0005E5 E6               [12] 1672 	mov	a,@r0
      0005E6 70 11            [24] 1673 	jnz	00108$
      0005E8 EA               [12] 1674 	mov	a,r2
      0005E9 70 5D            [24] 1675 	jnz	00111$
      0005EB E5 08            [12] 1676 	mov	a,_bp
      0005ED 24 04            [12] 1677 	add	a,#0x04
      0005EF F8               [12] 1678 	mov	r0,a
      0005F0 E6               [12] 1679 	mov	a,@r0
      0005F1 60 03            [24] 1680 	jz	00203$
      0005F3 02 06 ED         [24] 1681 	ljmp	00112$
      0005F6                       1682 00203$:
      0005F6 02 07 5C         [24] 1683 	ljmp	00115$
                           00053C  1684 	C$fuzzy.h$1419$4_0$50 ==.
                                   1685 ;	../../fuzzy.h:1419: case FUZZY_LOGIC_STANDARD:
      0005F9                       1686 00108$:
                           00053C  1687 	C$fuzzy.h$1420$1_0$45 ==.
                                   1688 ;	../../fuzzy.h:1420: if (next > result) {
      0005F9 C0 06            [24] 1689 	push	ar6
      0005FB C0 05            [24] 1690 	push	ar5
      0005FD C0 04            [24] 1691 	push	ar4
      0005FF C0 03            [24] 1692 	push	ar3
      000601 C0 02            [24] 1693 	push	ar2
      000603 C0 04            [24] 1694 	push	ar4
      000605 C0 05            [24] 1695 	push	ar5
      000607 C0 06            [24] 1696 	push	ar6
      000609 C0 03            [24] 1697 	push	ar3
      00060B E5 08            [12] 1698 	mov	a,_bp
      00060D 24 0A            [12] 1699 	add	a,#0x0a
      00060F F8               [12] 1700 	mov	r0,a
      000610 86 82            [24] 1701 	mov	dpl, @r0
      000612 08               [12] 1702 	inc	r0
      000613 86 83            [24] 1703 	mov	dph, @r0
      000615 08               [12] 1704 	inc	r0
      000616 86 F0            [24] 1705 	mov	b, @r0
      000618 08               [12] 1706 	inc	r0
      000619 E6               [12] 1707 	mov	a, @r0
      00061A 12 41 7C         [24] 1708 	lcall	___fslt
      00061D AF 82            [24] 1709 	mov	r7, dpl
      00061F E5 81            [12] 1710 	mov	a,sp
      000621 24 FC            [12] 1711 	add	a,#0xfc
      000623 F5 81            [12] 1712 	mov	sp,a
      000625 D0 02            [24] 1713 	pop	ar2
      000627 D0 03            [24] 1714 	pop	ar3
      000629 D0 04            [24] 1715 	pop	ar4
      00062B D0 05            [24] 1716 	pop	ar5
      00062D D0 06            [24] 1717 	pop	ar6
      00062F EF               [12] 1718 	mov	a,r7
      000630 70 03            [24] 1719 	jnz	00204$
      000632 02 07 64         [24] 1720 	ljmp	00120$
      000635                       1721 00204$:
                           000578  1722 	C$fuzzy.h$1421$5_0$51 ==.
                                   1723 ;	../../fuzzy.h:1421: result = next;
      000635 E5 08            [12] 1724 	mov	a,_bp
      000637 24 0A            [12] 1725 	add	a,#0x0a
      000639 F8               [12] 1726 	mov	r0,a
      00063A A6 04            [24] 1727 	mov	@r0,ar4
      00063C 08               [12] 1728 	inc	r0
      00063D A6 05            [24] 1729 	mov	@r0,ar5
      00063F 08               [12] 1730 	inc	r0
      000640 A6 06            [24] 1731 	mov	@r0,ar6
      000642 08               [12] 1732 	inc	r0
      000643 A6 03            [24] 1733 	mov	@r0,ar3
                           000588  1734 	C$fuzzy.h$1423$4_0$50 ==.
                                   1735 ;	../../fuzzy.h:1423: break;
      000645 02 07 64         [24] 1736 	ljmp	00120$
                           00058B  1737 	C$fuzzy.h$1425$4_0$50 ==.
                                   1738 ;	../../fuzzy.h:1425: case FUZZY_LOGIC_ALGEBRAIC:
      000648                       1739 00111$:
                           00058B  1740 	C$fuzzy.h$1428$1_0$45 ==.
                                   1741 ;	../../fuzzy.h:1428: next -
      000648 C0 02            [24] 1742 	push	ar2
      00064A C0 06            [24] 1743 	push	ar6
      00064C C0 05            [24] 1744 	push	ar5
      00064E C0 04            [24] 1745 	push	ar4
      000650 C0 03            [24] 1746 	push	ar3
      000652 C0 02            [24] 1747 	push	ar2
      000654 C0 04            [24] 1748 	push	ar4
      000656 C0 05            [24] 1749 	push	ar5
      000658 C0 06            [24] 1750 	push	ar6
      00065A C0 03            [24] 1751 	push	ar3
                           00059F  1752 	C$fuzzy.h$1429$1_0$45 ==.
                                   1753 ;	../../fuzzy.h:1429: result * next;
      00065C E5 08            [12] 1754 	mov	a,_bp
      00065E 24 0A            [12] 1755 	add	a,#0x0a
      000660 F8               [12] 1756 	mov	r0,a
      000661 86 82            [24] 1757 	mov	dpl, @r0
      000663 08               [12] 1758 	inc	r0
      000664 86 83            [24] 1759 	mov	dph, @r0
      000666 08               [12] 1760 	inc	r0
      000667 86 F0            [24] 1761 	mov	b, @r0
      000669 08               [12] 1762 	inc	r0
      00066A E6               [12] 1763 	mov	a, @r0
      00066B 12 41 CE         [24] 1764 	lcall	___fsadd
      00066E C8               [12] 1765 	xch	a,r0
      00066F E5 08            [12] 1766 	mov	a,_bp
      000671 24 06            [12] 1767 	add	a,#0x06
      000673 C8               [12] 1768 	xch	a,r0
      000674 A6 82            [24] 1769 	mov	@r0, dpl
      000676 08               [12] 1770 	inc	r0
      000677 A6 83            [24] 1771 	mov	@r0, dph
      000679 08               [12] 1772 	inc	r0
      00067A A6 F0            [24] 1773 	mov	@r0, b
      00067C 08               [12] 1774 	inc	r0
      00067D F6               [12] 1775 	mov	@r0,a
      00067E E5 81            [12] 1776 	mov	a,sp
      000680 24 FC            [12] 1777 	add	a,#0xfc
      000682 F5 81            [12] 1778 	mov	sp,a
      000684 D0 02            [24] 1779 	pop	ar2
      000686 D0 03            [24] 1780 	pop	ar3
      000688 D0 04            [24] 1781 	pop	ar4
      00068A D0 05            [24] 1782 	pop	ar5
      00068C D0 06            [24] 1783 	pop	ar6
      00068E C0 04            [24] 1784 	push	ar4
      000690 C0 05            [24] 1785 	push	ar5
      000692 C0 06            [24] 1786 	push	ar6
      000694 C0 03            [24] 1787 	push	ar3
      000696 E5 08            [12] 1788 	mov	a,_bp
      000698 24 0A            [12] 1789 	add	a,#0x0a
      00069A F8               [12] 1790 	mov	r0,a
      00069B 86 82            [24] 1791 	mov	dpl, @r0
      00069D 08               [12] 1792 	inc	r0
      00069E 86 83            [24] 1793 	mov	dph, @r0
      0006A0 08               [12] 1794 	inc	r0
      0006A1 86 F0            [24] 1795 	mov	b, @r0
      0006A3 08               [12] 1796 	inc	r0
      0006A4 E6               [12] 1797 	mov	a, @r0
      0006A5 12 40 4C         [24] 1798 	lcall	___fsmul
      0006A8 AA 82            [24] 1799 	mov	r2, dpl
      0006AA AB 83            [24] 1800 	mov	r3, dph
      0006AC AE F0            [24] 1801 	mov	r6, b
      0006AE FF               [12] 1802 	mov	r7, a
      0006AF E5 81            [12] 1803 	mov	a,sp
      0006B1 24 FC            [12] 1804 	add	a,#0xfc
      0006B3 F5 81            [12] 1805 	mov	sp,a
      0006B5 C0 02            [24] 1806 	push	ar2
      0006B7 C0 02            [24] 1807 	push	ar2
      0006B9 C0 03            [24] 1808 	push	ar3
      0006BB C0 06            [24] 1809 	push	ar6
      0006BD C0 07            [24] 1810 	push	ar7
                           000602  1811 	C$fuzzy.h$1430$1_0$45 ==.
                                   1812 ;	../../fuzzy.h:1430: break;
      0006BF E5 08            [12] 1813 	mov	a,_bp
      0006C1 24 06            [12] 1814 	add	a,#0x06
      0006C3 F8               [12] 1815 	mov	r0,a
      0006C4 86 82            [24] 1816 	mov	dpl, @r0
      0006C6 08               [12] 1817 	inc	r0
      0006C7 86 83            [24] 1818 	mov	dph, @r0
      0006C9 08               [12] 1819 	inc	r0
      0006CA 86 F0            [24] 1820 	mov	b, @r0
      0006CC 08               [12] 1821 	inc	r0
      0006CD E6               [12] 1822 	mov	a, @r0
      0006CE 12 40 41         [24] 1823 	lcall	___fssub
      0006D1 C8               [12] 1824 	xch	a,r0
      0006D2 E5 08            [12] 1825 	mov	a,_bp
      0006D4 24 0A            [12] 1826 	add	a,#0x0a
      0006D6 C8               [12] 1827 	xch	a,r0
      0006D7 A6 82            [24] 1828 	mov	@r0, dpl
      0006D9 08               [12] 1829 	inc	r0
      0006DA A6 83            [24] 1830 	mov	@r0, dph
      0006DC 08               [12] 1831 	inc	r0
      0006DD A6 F0            [24] 1832 	mov	@r0, b
      0006DF 08               [12] 1833 	inc	r0
      0006E0 F6               [12] 1834 	mov	@r0,a
      0006E1 E5 81            [12] 1835 	mov	a,sp
      0006E3 24 FC            [12] 1836 	add	a,#0xfc
      0006E5 F5 81            [12] 1837 	mov	sp,a
      0006E7 D0 02            [24] 1838 	pop	ar2
      0006E9 D0 02            [24] 1839 	pop	ar2
                           00062E  1840 	C$fuzzy.h$1432$4_0$50 ==.
                                   1841 ;	../../fuzzy.h:1432: case FUZZY_LOGIC_BOUNDED:
      0006EB 80 77            [24] 1842 	sjmp	00120$
      0006ED                       1843 00112$:
                           000630  1844 	C$fuzzy.h$1434$1_0$45 ==.
                                   1845 ;	../../fuzzy.h:1434: next;
      0006ED C0 02            [24] 1846 	push	ar2
      0006EF C0 04            [24] 1847 	push	ar4
      0006F1 C0 05            [24] 1848 	push	ar5
      0006F3 C0 06            [24] 1849 	push	ar6
      0006F5 C0 03            [24] 1850 	push	ar3
                           00063A  1851 	C$fuzzy.h$1436$1_0$45 ==.
                                   1852 ;	../../fuzzy.h:1436: if (result > LEVEL_HI) {
      0006F7 E5 08            [12] 1853 	mov	a,_bp
      0006F9 24 0A            [12] 1854 	add	a,#0x0a
      0006FB F8               [12] 1855 	mov	r0,a
      0006FC 86 82            [24] 1856 	mov	dpl, @r0
      0006FE 08               [12] 1857 	inc	r0
      0006FF 86 83            [24] 1858 	mov	dph, @r0
      000701 08               [12] 1859 	inc	r0
      000702 86 F0            [24] 1860 	mov	b, @r0
      000704 08               [12] 1861 	inc	r0
      000705 E6               [12] 1862 	mov	a, @r0
      000706 12 41 CE         [24] 1863 	lcall	___fsadd
      000709 C8               [12] 1864 	xch	a,r0
      00070A E5 08            [12] 1865 	mov	a,_bp
      00070C 24 0A            [12] 1866 	add	a,#0x0a
      00070E C8               [12] 1867 	xch	a,r0
      00070F A6 82            [24] 1868 	mov	@r0, dpl
      000711 08               [12] 1869 	inc	r0
      000712 A6 83            [24] 1870 	mov	@r0, dph
      000714 08               [12] 1871 	inc	r0
      000715 A6 F0            [24] 1872 	mov	@r0, b
      000717 08               [12] 1873 	inc	r0
      000718 F6               [12] 1874 	mov	@r0,a
      000719 E5 81            [12] 1875 	mov	a,sp
      00071B 24 FC            [12] 1876 	add	a,#0xfc
      00071D F5 81            [12] 1877 	mov	sp,a
      00071F E5 08            [12] 1878 	mov	a,_bp
      000721 24 0A            [12] 1879 	add	a,#0x0a
      000723 F8               [12] 1880 	mov	r0,a
      000724 E6               [12] 1881 	mov	a,@r0
      000725 C0 E0            [24] 1882 	push	acc
      000727 08               [12] 1883 	inc	r0
      000728 E6               [12] 1884 	mov	a,@r0
      000729 C0 E0            [24] 1885 	push	acc
      00072B 08               [12] 1886 	inc	r0
      00072C E6               [12] 1887 	mov	a,@r0
      00072D C0 E0            [24] 1888 	push	acc
      00072F 08               [12] 1889 	inc	r0
      000730 E6               [12] 1890 	mov	a,@r0
      000731 C0 E0            [24] 1891 	push	acc
      000733 90 00 00         [24] 1892 	mov	dptr,#0x0000
      000736 75 F0 80         [24] 1893 	mov	b, #0x80
      000739 74 3F            [12] 1894 	mov	a, #0x3f
      00073B 12 41 7C         [24] 1895 	lcall	___fslt
      00073E AF 82            [24] 1896 	mov	r7, dpl
      000740 E5 81            [12] 1897 	mov	a,sp
      000742 24 FC            [12] 1898 	add	a,#0xfc
      000744 F5 81            [12] 1899 	mov	sp,a
      000746 D0 02            [24] 1900 	pop	ar2
      000748 EF               [12] 1901 	mov	a,r7
      000749 60 19            [24] 1902 	jz	00120$
                           00068E  1903 	C$fuzzy.h$1437$5_0$52 ==.
                                   1904 ;	../../fuzzy.h:1437: result = LEVEL_HI;
      00074B E5 08            [12] 1905 	mov	a,_bp
      00074D 24 0A            [12] 1906 	add	a,#0x0a
      00074F F8               [12] 1907 	mov	r0,a
      000750 E4               [12] 1908 	clr	a
      000751 F6               [12] 1909 	mov	@r0,a
      000752 08               [12] 1910 	inc	r0
      000753 F6               [12] 1911 	mov	@r0,a
      000754 08               [12] 1912 	inc	r0
      000755 76 80            [12] 1913 	mov	@r0,#0x80
      000757 08               [12] 1914 	inc	r0
      000758 76 3F            [12] 1915 	mov	@r0,#0x3f
                           00069D  1916 	C$fuzzy.h$1439$4_0$50 ==.
                                   1917 ;	../../fuzzy.h:1439: break;
                           00069D  1918 	C$fuzzy.h$1441$4_0$50 ==.
                                   1919 ;	../../fuzzy.h:1441: default:
      00075A 80 08            [24] 1920 	sjmp	00120$
      00075C                       1921 00115$:
                           00069F  1922 	C$fuzzy.h$1442$4_0$50 ==.
                                   1923 ;	../../fuzzy.h:1442: return LEVEL_LO;
      00075C 90 00 00         [24] 1924 	mov	dptr,#0x0000
      00075F E4               [12] 1925 	clr	a
      000760 F5 F0            [12] 1926 	mov	b,a
                           0006A5  1927 	C$fuzzy.h$1443$3_0$49 ==.
                                   1928 ;	../../fuzzy.h:1443: }
      000762 80 20            [24] 1929 	sjmp	00121$
      000764                       1930 00120$:
                           0006A7  1931 	C$fuzzy.h$1411$2_0$48 ==.
                                   1932 ;	../../fuzzy.h:1411: index++
      000764 E5 08            [12] 1933 	mov	a,_bp
      000766 24 0E            [12] 1934 	add	a,#0x0e
      000768 F8               [12] 1935 	mov	r0,a
      000769 06               [12] 1936 	inc	@r0
      00076A B6 00 02         [24] 1937 	cjne	@r0,#0x00,00206$
      00076D 08               [12] 1938 	inc	r0
      00076E 06               [12] 1939 	inc	@r0
      00076F                       1940 00206$:
      00076F 02 05 7B         [24] 1941 	ljmp	00119$
      000772                       1942 00117$:
                           0006B5  1943 	C$fuzzy.h$1447$1_0$45 ==.
                                   1944 ;	../../fuzzy.h:1447: result
      000772 E5 08            [12] 1945 	mov	a,_bp
      000774 24 0A            [12] 1946 	add	a,#0x0a
      000776 F8               [12] 1947 	mov	r0,a
      000777 86 82            [24] 1948 	mov	dpl, @r0
      000779 08               [12] 1949 	inc	r0
      00077A 86 83            [24] 1950 	mov	dph, @r0
      00077C 08               [12] 1951 	inc	r0
      00077D 86 F0            [24] 1952 	mov	b, @r0
      00077F 08               [12] 1953 	inc	r0
      000780 E6               [12] 1954 	mov	a, @r0
      000781 12 00 F0         [24] 1955 	lcall	_fuzzy_clamp
      000784                       1956 00121$:
                           0006C7  1957 	C$fuzzy.h$1449$1_0$45 ==.
                                   1958 ;	../../fuzzy.h:1449: }
      000784 85 08 81         [24] 1959 	mov	sp,_bp
      000787 D0 08            [24] 1960 	pop	_bp
                           0006CC  1961 	C$fuzzy.h$1449$1_0$45 ==.
                           0006CC  1962 	XG$fuzzy_or_array$0$0 ==.
      000789 22               [24] 1963 	ret
                                   1964 ;------------------------------------------------------------
                                   1965 ;Allocation info for local variables in function 'fuzzy_sugeno_weighted_average_array'
                                   1966 ;------------------------------------------------------------
                                   1967 ;values        Allocated to stack - _bp -5 +3 
                                   1968 ;value_count   Allocated to stack - _bp +1 +2 
                                   1969 ;weighted_sum  Allocated to stack - _bp +3 +4 
                                   1970 ;firing_sum    Allocated to stack - _bp +7 +4 
                                   1971 ;firing_strength Allocated to stack - _bp +11 +4 
                                   1972 ;consequent    Allocated to registers r4 r5 r3 r2 
                                   1973 ;index         Allocated to registers r6 r7 
                                   1974 ;------------------------------------------------------------
                           0006CD  1975 	G$fuzzy_sugeno_weighted_average_array$0$0 ==.
                           0006CD  1976 	C$fuzzy.h$1460$1_0$54 ==.
                                   1977 ;	../../fuzzy.h:1460: float fuzzy_sugeno_weighted_average_array(
                                   1978 ;	-----------------------------------------
                                   1979 ;	 function fuzzy_sugeno_weighted_average_array
                                   1980 ;	-----------------------------------------
      00078A                       1981 _fuzzy_sugeno_weighted_average_array:
      00078A C0 08            [24] 1982 	push	_bp
      00078C 85 81 08         [24] 1983 	mov	_bp,sp
      00078F C0 82            [24] 1984 	push	dpl
      000791 C0 83            [24] 1985 	push	dph
      000793 E5 81            [12] 1986 	mov	a,sp
      000795 24 0C            [12] 1987 	add	a,#0x0c
      000797 F5 81            [12] 1988 	mov	sp,a
                           0006DC  1989 	C$fuzzy.h$1473$1_0$54 ==.
                                   1990 ;	../../fuzzy.h:1473: values == NULL ||
      000799 E5 08            [12] 1991 	mov	a,_bp
      00079B 24 FB            [12] 1992 	add	a,#0xfb
      00079D F8               [12] 1993 	mov	r0,a
      00079E E6               [12] 1994 	mov	a,@r0
      00079F 08               [12] 1995 	inc	r0
      0007A0 46               [12] 1996 	orl	a,@r0
      0007A1 60 0F            [24] 1997 	jz	00101$
                           0006E6  1998 	C$fuzzy.h$1474$1_0$54 ==.
                                   1999 ;	../../fuzzy.h:1474: value_count == 0u ||
      0007A3 A8 08            [24] 2000 	mov	r0,_bp
      0007A5 08               [12] 2001 	inc	r0
      0007A6 E6               [12] 2002 	mov	a,@r0
      0007A7 08               [12] 2003 	inc	r0
      0007A8 46               [12] 2004 	orl	a,@r0
      0007A9 60 07            [24] 2005 	jz	00101$
                           0006EE  2006 	C$fuzzy.h$1475$1_0$54 ==.
                                   2007 ;	../../fuzzy.h:1475: value_count % 2u != 0u
      0007AB A8 08            [24] 2008 	mov	r0,_bp
      0007AD 08               [12] 2009 	inc	r0
      0007AE E6               [12] 2010 	mov	a,@r0
      0007AF 30 E0 09         [24] 2011 	jnb	acc.0,00102$
      0007B2                       2012 00101$:
                           0006F5  2013 	C$fuzzy.h$1477$2_0$55 ==.
                                   2014 ;	../../fuzzy.h:1477: return 0.0f;
      0007B2 90 00 00         [24] 2015 	mov	dptr,#0x0000
      0007B5 E4               [12] 2016 	clr	a
      0007B6 F5 F0            [12] 2017 	mov	b,a
      0007B8 02 09 85         [24] 2018 	ljmp	00111$
      0007BB                       2019 00102$:
                           0006FE  2020 	C$fuzzy.h$1481$1_0$54 ==.
                                   2021 ;	../../fuzzy.h:1481: 0.0f;
      0007BB E5 08            [12] 2022 	mov	a,_bp
      0007BD 24 03            [12] 2023 	add	a,#0x03
      0007BF F8               [12] 2024 	mov	r0,a
      0007C0 E4               [12] 2025 	clr	a
      0007C1 F6               [12] 2026 	mov	@r0,a
      0007C2 08               [12] 2027 	inc	r0
      0007C3 F6               [12] 2028 	mov	@r0,a
      0007C4 08               [12] 2029 	inc	r0
      0007C5 F6               [12] 2030 	mov	@r0,a
      0007C6 08               [12] 2031 	inc	r0
      0007C7 F6               [12] 2032 	mov	@r0,a
                           00070B  2033 	C$fuzzy.h$1484$1_0$54 ==.
                                   2034 ;	../../fuzzy.h:1484: 0.0f;
      0007C8 E5 08            [12] 2035 	mov	a,_bp
      0007CA 24 07            [12] 2036 	add	a,#0x07
      0007CC F8               [12] 2037 	mov	r0,a
      0007CD E4               [12] 2038 	clr	a
      0007CE F6               [12] 2039 	mov	@r0,a
      0007CF 08               [12] 2040 	inc	r0
      0007D0 F6               [12] 2041 	mov	@r0,a
      0007D1 08               [12] 2042 	inc	r0
      0007D2 F6               [12] 2043 	mov	@r0,a
      0007D3 08               [12] 2044 	inc	r0
      0007D4 F6               [12] 2045 	mov	@r0,a
                           000718  2046 	C$fuzzy.h$1487$1_0$54 ==.
                                   2047 ;	../../fuzzy.h:1487: index = 0u;
      0007D5 FE               [12] 2048 	mov	r6,a
      0007D6 FF               [12] 2049 	mov	r7,a
      0007D7                       2050 00109$:
                           00071A  2051 	C$fuzzy.h$1488$2_0$56 ==.
                                   2052 ;	../../fuzzy.h:1488: index < value_count;
      0007D7 A8 08            [24] 2053 	mov	r0,_bp
      0007D9 08               [12] 2054 	inc	r0
      0007DA C3               [12] 2055 	clr	c
      0007DB EE               [12] 2056 	mov	a,r6
      0007DC 96               [12] 2057 	subb	a,@r0
      0007DD EF               [12] 2058 	mov	a,r7
      0007DE 08               [12] 2059 	inc	r0
      0007DF 96               [12] 2060 	subb	a,@r0
      0007E0 40 03            [24] 2061 	jc	00147$
      0007E2 02 09 18         [24] 2062 	ljmp	00105$
      0007E5                       2063 00147$:
                           000728  2064 	C$fuzzy.h$1493$3_0$57 ==.
                                   2065 ;	../../fuzzy.h:1493: values[index]
      0007E5 EE               [12] 2066 	mov	a,r6
      0007E6 2E               [12] 2067 	add	a,r6
      0007E7 FC               [12] 2068 	mov	r4,a
      0007E8 EF               [12] 2069 	mov	a,r7
      0007E9 33               [12] 2070 	rlc	a
      0007EA FD               [12] 2071 	mov	r5,a
      0007EB EC               [12] 2072 	mov	a,r4
      0007EC 2C               [12] 2073 	add	a,r4
      0007ED FC               [12] 2074 	mov	r4,a
      0007EE ED               [12] 2075 	mov	a,r5
      0007EF 33               [12] 2076 	rlc	a
      0007F0 FD               [12] 2077 	mov	r5,a
      0007F1 E5 08            [12] 2078 	mov	a,_bp
      0007F3 24 FB            [12] 2079 	add	a,#0xfb
      0007F5 F8               [12] 2080 	mov	r0,a
      0007F6 EC               [12] 2081 	mov	a,r4
      0007F7 26               [12] 2082 	add	a, @r0
      0007F8 FC               [12] 2083 	mov	r4,a
      0007F9 ED               [12] 2084 	mov	a,r5
      0007FA 08               [12] 2085 	inc	r0
      0007FB 36               [12] 2086 	addc	a, @r0
      0007FC FD               [12] 2087 	mov	r5,a
      0007FD 08               [12] 2088 	inc	r0
      0007FE 86 03            [24] 2089 	mov	ar3,@r0
      000800 8C 82            [24] 2090 	mov	dpl,r4
      000802 8D 83            [24] 2091 	mov	dph,r5
      000804 8B F0            [24] 2092 	mov	b,r3
      000806 12 43 A8         [24] 2093 	lcall	__gptrget
      000809 FC               [12] 2094 	mov	r4,a
      00080A A3               [24] 2095 	inc	dptr
      00080B 12 43 A8         [24] 2096 	lcall	__gptrget
      00080E FD               [12] 2097 	mov	r5,a
      00080F A3               [24] 2098 	inc	dptr
      000810 12 43 A8         [24] 2099 	lcall	__gptrget
      000813 FB               [12] 2100 	mov	r3,a
      000814 A3               [24] 2101 	inc	dptr
      000815 12 43 A8         [24] 2102 	lcall	__gptrget
      000818 8C 82            [24] 2103 	mov	dpl,r4
      00081A 8D 83            [24] 2104 	mov	dph,r5
      00081C 8B F0            [24] 2105 	mov	b,r3
      00081E C0 07            [24] 2106 	push	ar7
      000820 C0 06            [24] 2107 	push	ar6
      000822 12 00 F0         [24] 2108 	lcall	_fuzzy_clamp
      000825 C8               [12] 2109 	xch	a,r0
      000826 E5 08            [12] 2110 	mov	a,_bp
      000828 24 0B            [12] 2111 	add	a,#0x0b
      00082A C8               [12] 2112 	xch	a,r0
      00082B A6 82            [24] 2113 	mov	@r0, dpl
      00082D 08               [12] 2114 	inc	r0
      00082E A6 83            [24] 2115 	mov	@r0, dph
      000830 08               [12] 2116 	inc	r0
      000831 A6 F0            [24] 2117 	mov	@r0, b
      000833 08               [12] 2118 	inc	r0
      000834 F6               [12] 2119 	mov	@r0,a
      000835 D0 06            [24] 2120 	pop	ar6
      000837 D0 07            [24] 2121 	pop	ar7
                           00077C  2122 	C$fuzzy.h$1497$3_0$57 ==.
                                   2123 ;	../../fuzzy.h:1497: values[index + 1u];
      000839 74 01            [12] 2124 	mov	a,#0x01
      00083B 2E               [12] 2125 	add	a, r6
      00083C FC               [12] 2126 	mov	r4,a
      00083D E4               [12] 2127 	clr	a
      00083E 3F               [12] 2128 	addc	a, r7
      00083F FD               [12] 2129 	mov	r5,a
      000840 EC               [12] 2130 	mov	a,r4
      000841 2C               [12] 2131 	add	a,r4
      000842 FC               [12] 2132 	mov	r4,a
      000843 ED               [12] 2133 	mov	a,r5
      000844 33               [12] 2134 	rlc	a
      000845 FD               [12] 2135 	mov	r5,a
      000846 EC               [12] 2136 	mov	a,r4
      000847 2C               [12] 2137 	add	a,r4
      000848 FC               [12] 2138 	mov	r4,a
      000849 ED               [12] 2139 	mov	a,r5
      00084A 33               [12] 2140 	rlc	a
      00084B FD               [12] 2141 	mov	r5,a
      00084C E5 08            [12] 2142 	mov	a,_bp
      00084E 24 FB            [12] 2143 	add	a,#0xfb
      000850 F8               [12] 2144 	mov	r0,a
      000851 EC               [12] 2145 	mov	a,r4
      000852 26               [12] 2146 	add	a, @r0
      000853 FC               [12] 2147 	mov	r4,a
      000854 ED               [12] 2148 	mov	a,r5
      000855 08               [12] 2149 	inc	r0
      000856 36               [12] 2150 	addc	a, @r0
      000857 FD               [12] 2151 	mov	r5,a
      000858 08               [12] 2152 	inc	r0
      000859 86 03            [24] 2153 	mov	ar3,@r0
      00085B 8C 82            [24] 2154 	mov	dpl,r4
      00085D 8D 83            [24] 2155 	mov	dph,r5
      00085F 8B F0            [24] 2156 	mov	b,r3
      000861 12 43 A8         [24] 2157 	lcall	__gptrget
      000864 FC               [12] 2158 	mov	r4,a
      000865 A3               [24] 2159 	inc	dptr
      000866 12 43 A8         [24] 2160 	lcall	__gptrget
      000869 FD               [12] 2161 	mov	r5,a
      00086A A3               [24] 2162 	inc	dptr
      00086B 12 43 A8         [24] 2163 	lcall	__gptrget
      00086E FB               [12] 2164 	mov	r3,a
      00086F A3               [24] 2165 	inc	dptr
      000870 12 43 A8         [24] 2166 	lcall	__gptrget
      000873 FA               [12] 2167 	mov	r2,a
                           0007B7  2168 	C$fuzzy.h$1502$1_0$54 ==.
                                   2169 ;	../../fuzzy.h:1502: consequent;
      000874 C0 07            [24] 2170 	push	ar7
      000876 C0 06            [24] 2171 	push	ar6
      000878 C0 04            [24] 2172 	push	ar4
      00087A C0 05            [24] 2173 	push	ar5
      00087C C0 03            [24] 2174 	push	ar3
      00087E C0 02            [24] 2175 	push	ar2
      000880 E5 08            [12] 2176 	mov	a,_bp
      000882 24 0B            [12] 2177 	add	a,#0x0b
      000884 F8               [12] 2178 	mov	r0,a
      000885 86 82            [24] 2179 	mov	dpl, @r0
      000887 08               [12] 2180 	inc	r0
      000888 86 83            [24] 2181 	mov	dph, @r0
      00088A 08               [12] 2182 	inc	r0
      00088B 86 F0            [24] 2183 	mov	b, @r0
      00088D 08               [12] 2184 	inc	r0
      00088E E6               [12] 2185 	mov	a, @r0
      00088F 12 40 4C         [24] 2186 	lcall	___fsmul
      000892 AA 82            [24] 2187 	mov	r2, dpl
      000894 AB 83            [24] 2188 	mov	r3, dph
      000896 AC F0            [24] 2189 	mov	r4, b
      000898 FD               [12] 2190 	mov	r5, a
      000899 E5 81            [12] 2191 	mov	a,sp
      00089B 24 FC            [12] 2192 	add	a,#0xfc
      00089D F5 81            [12] 2193 	mov	sp,a
      00089F C0 02            [24] 2194 	push	ar2
      0008A1 C0 03            [24] 2195 	push	ar3
      0008A3 C0 04            [24] 2196 	push	ar4
      0008A5 C0 05            [24] 2197 	push	ar5
                           0007EA  2198 	C$fuzzy.h$1505$1_0$54 ==.
                                   2199 ;	../../fuzzy.h:1505: firing_strength;
      0008A7 E5 08            [12] 2200 	mov	a,_bp
      0008A9 24 03            [12] 2201 	add	a,#0x03
      0008AB F8               [12] 2202 	mov	r0,a
      0008AC 86 82            [24] 2203 	mov	dpl, @r0
      0008AE 08               [12] 2204 	inc	r0
      0008AF 86 83            [24] 2205 	mov	dph, @r0
      0008B1 08               [12] 2206 	inc	r0
      0008B2 86 F0            [24] 2207 	mov	b, @r0
      0008B4 08               [12] 2208 	inc	r0
      0008B5 E6               [12] 2209 	mov	a, @r0
      0008B6 12 41 CE         [24] 2210 	lcall	___fsadd
      0008B9 A8 08            [24] 2211 	mov	r0,_bp
      0008BB 08               [12] 2212 	inc	r0
      0008BC 08               [12] 2213 	inc	r0
      0008BD 08               [12] 2214 	inc	r0
      0008BE A6 82            [24] 2215 	mov	@r0, dpl
      0008C0 08               [12] 2216 	inc	r0
      0008C1 A6 83            [24] 2217 	mov	@r0, dph
      0008C3 08               [12] 2218 	inc	r0
      0008C4 A6 F0            [24] 2219 	mov	@r0, b
      0008C6 08               [12] 2220 	inc	r0
      0008C7 F6               [12] 2221 	mov	@r0,a
      0008C8 E5 81            [12] 2222 	mov	a,sp
      0008CA 24 FC            [12] 2223 	add	a,#0xfc
      0008CC F5 81            [12] 2224 	mov	sp,a
      0008CE E5 08            [12] 2225 	mov	a,_bp
      0008D0 24 0B            [12] 2226 	add	a,#0x0b
      0008D2 F8               [12] 2227 	mov	r0,a
      0008D3 E6               [12] 2228 	mov	a,@r0
      0008D4 C0 E0            [24] 2229 	push	acc
      0008D6 08               [12] 2230 	inc	r0
      0008D7 E6               [12] 2231 	mov	a,@r0
      0008D8 C0 E0            [24] 2232 	push	acc
      0008DA 08               [12] 2233 	inc	r0
      0008DB E6               [12] 2234 	mov	a,@r0
      0008DC C0 E0            [24] 2235 	push	acc
      0008DE 08               [12] 2236 	inc	r0
      0008DF E6               [12] 2237 	mov	a,@r0
      0008E0 C0 E0            [24] 2238 	push	acc
                           000825  2239 	C$fuzzy.h$1490$1_0$54 ==.
                                   2240 ;	../../fuzzy.h:1490: ) {
      0008E2 E5 08            [12] 2241 	mov	a,_bp
      0008E4 24 07            [12] 2242 	add	a,#0x07
      0008E6 F8               [12] 2243 	mov	r0,a
      0008E7 86 82            [24] 2244 	mov	dpl, @r0
      0008E9 08               [12] 2245 	inc	r0
      0008EA 86 83            [24] 2246 	mov	dph, @r0
      0008EC 08               [12] 2247 	inc	r0
      0008ED 86 F0            [24] 2248 	mov	b, @r0
      0008EF 08               [12] 2249 	inc	r0
      0008F0 E6               [12] 2250 	mov	a, @r0
      0008F1 12 41 CE         [24] 2251 	lcall	___fsadd
      0008F4 C8               [12] 2252 	xch	a,r0
      0008F5 E5 08            [12] 2253 	mov	a,_bp
      0008F7 24 07            [12] 2254 	add	a,#0x07
      0008F9 C8               [12] 2255 	xch	a,r0
      0008FA A6 82            [24] 2256 	mov	@r0, dpl
      0008FC 08               [12] 2257 	inc	r0
      0008FD A6 83            [24] 2258 	mov	@r0, dph
      0008FF 08               [12] 2259 	inc	r0
      000900 A6 F0            [24] 2260 	mov	@r0, b
      000902 08               [12] 2261 	inc	r0
      000903 F6               [12] 2262 	mov	@r0,a
      000904 E5 81            [12] 2263 	mov	a,sp
      000906 24 FC            [12] 2264 	add	a,#0xfc
      000908 F5 81            [12] 2265 	mov	sp,a
      00090A D0 06            [24] 2266 	pop	ar6
      00090C D0 07            [24] 2267 	pop	ar7
      00090E 74 02            [12] 2268 	mov	a,#0x02
      000910 2E               [12] 2269 	add	a, r6
      000911 FE               [12] 2270 	mov	r6,a
      000912 E4               [12] 2271 	clr	a
      000913 3F               [12] 2272 	addc	a, r7
      000914 FF               [12] 2273 	mov	r7,a
      000915 02 07 D7         [24] 2274 	ljmp	00109$
      000918                       2275 00105$:
                           00085B  2276 	C$fuzzy.h$1508$1_0$54 ==.
                                   2277 ;	../../fuzzy.h:1508: if (firing_sum <= LEVEL_LO) {
      000918 E5 08            [12] 2278 	mov	a,_bp
      00091A 24 07            [12] 2279 	add	a,#0x07
      00091C F8               [12] 2280 	mov	r0,a
      00091D E6               [12] 2281 	mov	a,@r0
      00091E C0 E0            [24] 2282 	push	acc
      000920 08               [12] 2283 	inc	r0
      000921 E6               [12] 2284 	mov	a,@r0
      000922 C0 E0            [24] 2285 	push	acc
      000924 08               [12] 2286 	inc	r0
      000925 E6               [12] 2287 	mov	a,@r0
      000926 C0 E0            [24] 2288 	push	acc
      000928 08               [12] 2289 	inc	r0
      000929 E6               [12] 2290 	mov	a,@r0
      00092A C0 E0            [24] 2291 	push	acc
      00092C 90 00 00         [24] 2292 	mov	dptr,#0x0000
      00092F E4               [12] 2293 	clr	a
      000930 F5 F0            [12] 2294 	mov	b,a
      000932 12 41 7C         [24] 2295 	lcall	___fslt
      000935 E5 81            [12] 2296 	mov	a,sp
      000937 24 FC            [12] 2297 	add	a,#0xfc
      000939 F5 81            [12] 2298 	mov	sp,a
      00093B E5 82            [12] 2299 	mov	a, dpl
      00093D 24 FF            [12] 2300 	add	a,#0xff
      00093F 92 00            [24] 2301 	mov	b0,c
      000941 40 08            [24] 2302 	jc	00107$
                           000886  2303 	C$fuzzy.h$1509$2_0$58 ==.
                                   2304 ;	../../fuzzy.h:1509: return 0.0f;
      000943 90 00 00         [24] 2305 	mov	dptr,#0x0000
      000946 E4               [12] 2306 	clr	a
      000947 F5 F0            [12] 2307 	mov	b,a
      000949 80 3A            [24] 2308 	sjmp	00111$
      00094B                       2309 00107$:
                           00088E  2310 	C$fuzzy.h$1513$1_0$54 ==.
                                   2311 ;	../../fuzzy.h:1513: firing_sum;
      00094B E5 08            [12] 2312 	mov	a,_bp
      00094D 24 07            [12] 2313 	add	a,#0x07
      00094F F8               [12] 2314 	mov	r0,a
      000950 E6               [12] 2315 	mov	a,@r0
      000951 C0 E0            [24] 2316 	push	acc
      000953 08               [12] 2317 	inc	r0
      000954 E6               [12] 2318 	mov	a,@r0
      000955 C0 E0            [24] 2319 	push	acc
      000957 08               [12] 2320 	inc	r0
      000958 E6               [12] 2321 	mov	a,@r0
      000959 C0 E0            [24] 2322 	push	acc
      00095B 08               [12] 2323 	inc	r0
      00095C E6               [12] 2324 	mov	a,@r0
      00095D C0 E0            [24] 2325 	push	acc
      00095F E5 08            [12] 2326 	mov	a,_bp
      000961 24 03            [12] 2327 	add	a,#0x03
      000963 F8               [12] 2328 	mov	r0,a
      000964 86 82            [24] 2329 	mov	dpl, @r0
      000966 08               [12] 2330 	inc	r0
      000967 86 83            [24] 2331 	mov	dph, @r0
      000969 08               [12] 2332 	inc	r0
      00096A 86 F0            [24] 2333 	mov	b, @r0
      00096C 08               [12] 2334 	inc	r0
      00096D E6               [12] 2335 	mov	a, @r0
      00096E 12 42 E5         [24] 2336 	lcall	___fsdiv
      000971 AC 82            [24] 2337 	mov	r4, dpl
      000973 AD 83            [24] 2338 	mov	r5, dph
      000975 AE F0            [24] 2339 	mov	r6, b
      000977 FF               [12] 2340 	mov	r7, a
      000978 E5 81            [12] 2341 	mov	a,sp
      00097A 24 FC            [12] 2342 	add	a,#0xfc
      00097C F5 81            [12] 2343 	mov	sp,a
      00097E 8C 82            [24] 2344 	mov	dpl, r4
      000980 8D 83            [24] 2345 	mov	dph, r5
      000982 8E F0            [24] 2346 	mov	b, r6
      000984 EF               [12] 2347 	mov	a, r7
      000985                       2348 00111$:
                           0008C8  2349 	C$fuzzy.h$1514$1_0$54 ==.
                                   2350 ;	../../fuzzy.h:1514: }
      000985 85 08 81         [24] 2351 	mov	sp,_bp
      000988 D0 08            [24] 2352 	pop	_bp
                           0008CD  2353 	C$fuzzy.h$1514$1_0$54 ==.
                           0008CD  2354 	XG$fuzzy_sugeno_weighted_average_array$0$0 ==.
      00098A 22               [24] 2355 	ret
                                   2356 ;------------------------------------------------------------
                                   2357 ;Allocation info for local variables in function 'fuzzy_sugeno_weighted_sum_array'
                                   2358 ;------------------------------------------------------------
                                   2359 ;values        Allocated to stack - _bp -5 +3 
                                   2360 ;value_count   Allocated to registers r6 r7 
                                   2361 ;weighted_sum  Allocated to stack - _bp +1 +4 
                                   2362 ;firing_strength Allocated to stack - _bp +5 +4 
                                   2363 ;consequent    Allocated to registers r6 r7 r3 r2 
                                   2364 ;index         Allocated to registers r4 r5 
                                   2365 ;------------------------------------------------------------
                           0008CE  2366 	G$fuzzy_sugeno_weighted_sum_array$0$0 ==.
                           0008CE  2367 	C$fuzzy.h$1524$1_0$60 ==.
                                   2368 ;	../../fuzzy.h:1524: float fuzzy_sugeno_weighted_sum_array(
                                   2369 ;	-----------------------------------------
                                   2370 ;	 function fuzzy_sugeno_weighted_sum_array
                                   2371 ;	-----------------------------------------
      00098B                       2372 _fuzzy_sugeno_weighted_sum_array:
      00098B C0 08            [24] 2373 	push	_bp
      00098D E5 81            [12] 2374 	mov	a,sp
      00098F F5 08            [12] 2375 	mov	_bp,a
      000991 24 08            [12] 2376 	add	a,#0x08
      000993 F5 81            [12] 2377 	mov	sp,a
      000995 AE 82            [24] 2378 	mov	r6, dpl
      000997 AF 83            [24] 2379 	mov	r7, dph
                           0008DC  2380 	C$fuzzy.h$1536$1_0$60 ==.
                                   2381 ;	../../fuzzy.h:1536: values == NULL ||
      000999 E5 08            [12] 2382 	mov	a,_bp
      00099B 24 FB            [12] 2383 	add	a,#0xfb
      00099D F8               [12] 2384 	mov	r0,a
      00099E E6               [12] 2385 	mov	a,@r0
      00099F 08               [12] 2386 	inc	r0
      0009A0 46               [12] 2387 	orl	a,@r0
      0009A1 60 08            [24] 2388 	jz	00101$
                           0008E6  2389 	C$fuzzy.h$1537$1_0$60 ==.
                                   2390 ;	../../fuzzy.h:1537: value_count == 0u ||
      0009A3 EE               [12] 2391 	mov	a,r6
      0009A4 4F               [12] 2392 	orl	a,r7
      0009A5 60 04            [24] 2393 	jz	00101$
                           0008EA  2394 	C$fuzzy.h$1538$1_0$60 ==.
                                   2395 ;	../../fuzzy.h:1538: value_count % 2u != 0u
      0009A7 EE               [12] 2396 	mov	a,r6
      0009A8 30 E0 09         [24] 2397 	jnb	acc.0,00102$
      0009AB                       2398 00101$:
                           0008EE  2399 	C$fuzzy.h$1540$2_0$61 ==.
                                   2400 ;	../../fuzzy.h:1540: return 0.0f;
      0009AB 90 00 00         [24] 2401 	mov	dptr,#0x0000
      0009AE E4               [12] 2402 	clr	a
      0009AF F5 F0            [12] 2403 	mov	b,a
      0009B1 02 0A EC         [24] 2404 	ljmp	00109$
      0009B4                       2405 00102$:
                           0008F7  2406 	C$fuzzy.h$1544$1_0$60 ==.
                                   2407 ;	../../fuzzy.h:1544: 0.0f;
      0009B4 A8 08            [24] 2408 	mov	r0,_bp
      0009B6 08               [12] 2409 	inc	r0
      0009B7 E4               [12] 2410 	clr	a
      0009B8 F6               [12] 2411 	mov	@r0,a
      0009B9 08               [12] 2412 	inc	r0
      0009BA F6               [12] 2413 	mov	@r0,a
      0009BB 08               [12] 2414 	inc	r0
      0009BC F6               [12] 2415 	mov	@r0,a
      0009BD 08               [12] 2416 	inc	r0
      0009BE F6               [12] 2417 	mov	@r0,a
                           000902  2418 	C$fuzzy.h$1547$1_0$60 ==.
                                   2419 ;	../../fuzzy.h:1547: index = 0u;
      0009BF FC               [12] 2420 	mov	r4,a
      0009C0 FD               [12] 2421 	mov	r5,a
      0009C1                       2422 00107$:
                           000904  2423 	C$fuzzy.h$1548$2_0$62 ==.
                                   2424 ;	../../fuzzy.h:1548: index < value_count;
      0009C1 C3               [12] 2425 	clr	c
      0009C2 EC               [12] 2426 	mov	a,r4
      0009C3 9E               [12] 2427 	subb	a,r6
      0009C4 ED               [12] 2428 	mov	a,r5
      0009C5 9F               [12] 2429 	subb	a,r7
      0009C6 40 03            [24] 2430 	jc	00139$
      0009C8 02 0A DF         [24] 2431 	ljmp	00105$
      0009CB                       2432 00139$:
                           00090E  2433 	C$fuzzy.h$1553$1_0$60 ==.
                                   2434 ;	../../fuzzy.h:1553: values[index]
      0009CB C0 06            [24] 2435 	push	ar6
      0009CD C0 07            [24] 2436 	push	ar7
      0009CF EC               [12] 2437 	mov	a,r4
      0009D0 2C               [12] 2438 	add	a,r4
      0009D1 FA               [12] 2439 	mov	r2,a
      0009D2 ED               [12] 2440 	mov	a,r5
      0009D3 33               [12] 2441 	rlc	a
      0009D4 FB               [12] 2442 	mov	r3,a
      0009D5 EA               [12] 2443 	mov	a,r2
      0009D6 2A               [12] 2444 	add	a,r2
      0009D7 FA               [12] 2445 	mov	r2,a
      0009D8 EB               [12] 2446 	mov	a,r3
      0009D9 33               [12] 2447 	rlc	a
      0009DA FB               [12] 2448 	mov	r3,a
      0009DB E5 08            [12] 2449 	mov	a,_bp
      0009DD 24 FB            [12] 2450 	add	a,#0xfb
      0009DF F8               [12] 2451 	mov	r0,a
      0009E0 EA               [12] 2452 	mov	a,r2
      0009E1 26               [12] 2453 	add	a, @r0
      0009E2 FA               [12] 2454 	mov	r2,a
      0009E3 EB               [12] 2455 	mov	a,r3
      0009E4 08               [12] 2456 	inc	r0
      0009E5 36               [12] 2457 	addc	a, @r0
      0009E6 FB               [12] 2458 	mov	r3,a
      0009E7 08               [12] 2459 	inc	r0
      0009E8 86 07            [24] 2460 	mov	ar7,@r0
      0009EA 8A 82            [24] 2461 	mov	dpl,r2
      0009EC 8B 83            [24] 2462 	mov	dph,r3
      0009EE 8F F0            [24] 2463 	mov	b,r7
      0009F0 12 43 A8         [24] 2464 	lcall	__gptrget
      0009F3 FA               [12] 2465 	mov	r2,a
      0009F4 A3               [24] 2466 	inc	dptr
      0009F5 12 43 A8         [24] 2467 	lcall	__gptrget
      0009F8 FB               [12] 2468 	mov	r3,a
      0009F9 A3               [24] 2469 	inc	dptr
      0009FA 12 43 A8         [24] 2470 	lcall	__gptrget
      0009FD FF               [12] 2471 	mov	r7,a
      0009FE A3               [24] 2472 	inc	dptr
      0009FF 12 43 A8         [24] 2473 	lcall	__gptrget
      000A02 FE               [12] 2474 	mov	r6,a
      000A03 8A 82            [24] 2475 	mov	dpl,r2
      000A05 8B 83            [24] 2476 	mov	dph,r3
      000A07 8F F0            [24] 2477 	mov	b,r7
      000A09 C0 07            [24] 2478 	push	ar7
      000A0B C0 06            [24] 2479 	push	ar6
      000A0D C0 05            [24] 2480 	push	ar5
      000A0F C0 04            [24] 2481 	push	ar4
      000A11 12 00 F0         [24] 2482 	lcall	_fuzzy_clamp
      000A14 C8               [12] 2483 	xch	a,r0
      000A15 E5 08            [12] 2484 	mov	a,_bp
      000A17 24 05            [12] 2485 	add	a,#0x05
      000A19 C8               [12] 2486 	xch	a,r0
      000A1A A6 82            [24] 2487 	mov	@r0, dpl
      000A1C 08               [12] 2488 	inc	r0
      000A1D A6 83            [24] 2489 	mov	@r0, dph
      000A1F 08               [12] 2490 	inc	r0
      000A20 A6 F0            [24] 2491 	mov	@r0, b
      000A22 08               [12] 2492 	inc	r0
      000A23 F6               [12] 2493 	mov	@r0,a
      000A24 D0 04            [24] 2494 	pop	ar4
      000A26 D0 05            [24] 2495 	pop	ar5
      000A28 D0 06            [24] 2496 	pop	ar6
      000A2A D0 07            [24] 2497 	pop	ar7
                           00096F  2498 	C$fuzzy.h$1557$3_0$63 ==.
                                   2499 ;	../../fuzzy.h:1557: values[index + 1u];
      000A2C 74 01            [12] 2500 	mov	a,#0x01
      000A2E 2C               [12] 2501 	add	a, r4
      000A2F FE               [12] 2502 	mov	r6,a
      000A30 E4               [12] 2503 	clr	a
      000A31 3D               [12] 2504 	addc	a, r5
      000A32 FF               [12] 2505 	mov	r7,a
      000A33 EE               [12] 2506 	mov	a,r6
      000A34 2E               [12] 2507 	add	a,r6
      000A35 FE               [12] 2508 	mov	r6,a
      000A36 EF               [12] 2509 	mov	a,r7
      000A37 33               [12] 2510 	rlc	a
      000A38 FF               [12] 2511 	mov	r7,a
      000A39 EE               [12] 2512 	mov	a,r6
      000A3A 2E               [12] 2513 	add	a,r6
      000A3B FE               [12] 2514 	mov	r6,a
      000A3C EF               [12] 2515 	mov	a,r7
      000A3D 33               [12] 2516 	rlc	a
      000A3E FF               [12] 2517 	mov	r7,a
      000A3F E5 08            [12] 2518 	mov	a,_bp
      000A41 24 FB            [12] 2519 	add	a,#0xfb
      000A43 F8               [12] 2520 	mov	r0,a
      000A44 EE               [12] 2521 	mov	a,r6
      000A45 26               [12] 2522 	add	a, @r0
      000A46 FE               [12] 2523 	mov	r6,a
      000A47 EF               [12] 2524 	mov	a,r7
      000A48 08               [12] 2525 	inc	r0
      000A49 36               [12] 2526 	addc	a, @r0
      000A4A FF               [12] 2527 	mov	r7,a
      000A4B 08               [12] 2528 	inc	r0
      000A4C 86 03            [24] 2529 	mov	ar3,@r0
      000A4E 8E 82            [24] 2530 	mov	dpl,r6
      000A50 8F 83            [24] 2531 	mov	dph,r7
      000A52 8B F0            [24] 2532 	mov	b,r3
      000A54 12 43 A8         [24] 2533 	lcall	__gptrget
      000A57 FE               [12] 2534 	mov	r6,a
      000A58 A3               [24] 2535 	inc	dptr
      000A59 12 43 A8         [24] 2536 	lcall	__gptrget
      000A5C FF               [12] 2537 	mov	r7,a
      000A5D A3               [24] 2538 	inc	dptr
      000A5E 12 43 A8         [24] 2539 	lcall	__gptrget
      000A61 FB               [12] 2540 	mov	r3,a
      000A62 A3               [24] 2541 	inc	dptr
      000A63 12 43 A8         [24] 2542 	lcall	__gptrget
      000A66 FA               [12] 2543 	mov	r2,a
                           0009AA  2544 	C$fuzzy.h$1562$1_0$60 ==.
                                   2545 ;	../../fuzzy.h:1562: consequent;
      000A67 C0 05            [24] 2546 	push	ar5
      000A69 C0 04            [24] 2547 	push	ar4
      000A6B C0 06            [24] 2548 	push	ar6
      000A6D C0 07            [24] 2549 	push	ar7
      000A6F C0 03            [24] 2550 	push	ar3
      000A71 C0 02            [24] 2551 	push	ar2
      000A73 E5 08            [12] 2552 	mov	a,_bp
      000A75 24 05            [12] 2553 	add	a,#0x05
      000A77 F8               [12] 2554 	mov	r0,a
      000A78 86 82            [24] 2555 	mov	dpl, @r0
      000A7A 08               [12] 2556 	inc	r0
      000A7B 86 83            [24] 2557 	mov	dph, @r0
      000A7D 08               [12] 2558 	inc	r0
      000A7E 86 F0            [24] 2559 	mov	b, @r0
      000A80 08               [12] 2560 	inc	r0
      000A81 E6               [12] 2561 	mov	a, @r0
      000A82 12 40 4C         [24] 2562 	lcall	___fsmul
      000A85 AA 82            [24] 2563 	mov	r2, dpl
      000A87 AB 83            [24] 2564 	mov	r3, dph
      000A89 AE F0            [24] 2565 	mov	r6, b
      000A8B FF               [12] 2566 	mov	r7, a
      000A8C E5 81            [12] 2567 	mov	a,sp
      000A8E 24 FC            [12] 2568 	add	a,#0xfc
      000A90 F5 81            [12] 2569 	mov	sp,a
      000A92 D0 04            [24] 2570 	pop	ar4
      000A94 D0 05            [24] 2571 	pop	ar5
      000A96 C0 07            [24] 2572 	push	ar7
      000A98 C0 06            [24] 2573 	push	ar6
      000A9A C0 05            [24] 2574 	push	ar5
      000A9C C0 04            [24] 2575 	push	ar4
      000A9E C0 02            [24] 2576 	push	ar2
      000AA0 C0 03            [24] 2577 	push	ar3
      000AA2 C0 06            [24] 2578 	push	ar6
      000AA4 C0 07            [24] 2579 	push	ar7
                           0009E9  2580 	C$fuzzy.h$1550$1_0$60 ==.
                                   2581 ;	../../fuzzy.h:1550: ) {
      000AA6 A8 08            [24] 2582 	mov	r0,_bp
      000AA8 08               [12] 2583 	inc	r0
      000AA9 86 82            [24] 2584 	mov	dpl, @r0
      000AAB 08               [12] 2585 	inc	r0
      000AAC 86 83            [24] 2586 	mov	dph, @r0
      000AAE 08               [12] 2587 	inc	r0
      000AAF 86 F0            [24] 2588 	mov	b, @r0
      000AB1 08               [12] 2589 	inc	r0
      000AB2 E6               [12] 2590 	mov	a, @r0
      000AB3 12 41 CE         [24] 2591 	lcall	___fsadd
      000AB6 A8 08            [24] 2592 	mov	r0,_bp
      000AB8 08               [12] 2593 	inc	r0
      000AB9 A6 82            [24] 2594 	mov	@r0, dpl
      000ABB 08               [12] 2595 	inc	r0
      000ABC A6 83            [24] 2596 	mov	@r0, dph
      000ABE 08               [12] 2597 	inc	r0
      000ABF A6 F0            [24] 2598 	mov	@r0, b
      000AC1 08               [12] 2599 	inc	r0
      000AC2 F6               [12] 2600 	mov	@r0,a
      000AC3 E5 81            [12] 2601 	mov	a,sp
      000AC5 24 FC            [12] 2602 	add	a,#0xfc
      000AC7 F5 81            [12] 2603 	mov	sp,a
      000AC9 D0 04            [24] 2604 	pop	ar4
      000ACB D0 05            [24] 2605 	pop	ar5
      000ACD D0 06            [24] 2606 	pop	ar6
      000ACF D0 07            [24] 2607 	pop	ar7
      000AD1 74 02            [12] 2608 	mov	a,#0x02
      000AD3 2C               [12] 2609 	add	a, r4
      000AD4 FC               [12] 2610 	mov	r4,a
      000AD5 E4               [12] 2611 	clr	a
      000AD6 3D               [12] 2612 	addc	a, r5
      000AD7 FD               [12] 2613 	mov	r5,a
      000AD8 D0 07            [24] 2614 	pop	ar7
      000ADA D0 06            [24] 2615 	pop	ar6
      000ADC 02 09 C1         [24] 2616 	ljmp	00107$
      000ADF                       2617 00105$:
                           000A22  2618 	C$fuzzy.h$1565$1_0$60 ==.
                                   2619 ;	../../fuzzy.h:1565: return weighted_sum;
      000ADF A8 08            [24] 2620 	mov	r0,_bp
      000AE1 08               [12] 2621 	inc	r0
      000AE2 86 82            [24] 2622 	mov	dpl, @r0
      000AE4 08               [12] 2623 	inc	r0
      000AE5 86 83            [24] 2624 	mov	dph, @r0
      000AE7 08               [12] 2625 	inc	r0
      000AE8 86 F0            [24] 2626 	mov	b, @r0
      000AEA 08               [12] 2627 	inc	r0
      000AEB E6               [12] 2628 	mov	a, @r0
      000AEC                       2629 00109$:
                           000A2F  2630 	C$fuzzy.h$1566$1_0$60 ==.
                                   2631 ;	../../fuzzy.h:1566: }
      000AEC 85 08 81         [24] 2632 	mov	sp,_bp
      000AEF D0 08            [24] 2633 	pop	_bp
                           000A34  2634 	C$fuzzy.h$1566$1_0$60 ==.
                           000A34  2635 	XG$fuzzy_sugeno_weighted_sum_array$0$0 ==.
      000AF1 22               [24] 2636 	ret
                                   2637 ;------------------------------------------------------------
                                   2638 ;Allocation info for local variables in function 'fuzzy_ramp'
                                   2639 ;------------------------------------------------------------
                                   2640 ;upper_boundary Allocated to stack - _bp -6 +4 
                                   2641 ;value         Allocated to stack - _bp -10 +4 
                                   2642 ;ramp_up       Allocated to stack - _bp -11 +1 
                                   2643 ;hedge         Allocated to stack - _bp -12 +1 
                                   2644 ;lower_boundary Allocated to registers r7 r6 r5 r4 
                                   2645 ;result        Allocated to stack - _bp +5 +4 
                                   2646 ;normalized    Allocated to registers r4 r5 r6 r7 
                                   2647 ;sloc0         Allocated to stack - _bp +13 +4 
                                   2648 ;sloc1         Allocated to stack - _bp +1 +4 
                                   2649 ;------------------------------------------------------------
                           000A35  2650 	G$fuzzy_ramp$0$0 ==.
                           000A35  2651 	C$fuzzy.h$1572$1_0$65 ==.
                                   2652 ;	../../fuzzy.h:1572: float fuzzy_ramp(
                                   2653 ;	-----------------------------------------
                                   2654 ;	 function fuzzy_ramp
                                   2655 ;	-----------------------------------------
      000AF2                       2656 _fuzzy_ramp:
      000AF2 C0 08            [24] 2657 	push	_bp
      000AF4 85 81 08         [24] 2658 	mov	_bp,sp
      000AF7 AF 82            [24] 2659 	mov	r7,dpl
      000AF9 AE 83            [24] 2660 	mov	r6,dph
      000AFB AD F0            [24] 2661 	mov	r5,b
      000AFD FC               [12] 2662 	mov	r4,a
      000AFE E5 81            [12] 2663 	mov	a,sp
      000B00 24 08            [12] 2664 	add	a,#0x08
      000B02 F5 81            [12] 2665 	mov	sp,a
                           000A47  2666 	C$fuzzy.h$1583$1_0$65 ==.
                                   2667 ;	../../fuzzy.h:1583: if (lower_boundary >= upper_boundary) {
      000B04 C0 07            [24] 2668 	push	ar7
      000B06 C0 06            [24] 2669 	push	ar6
      000B08 C0 05            [24] 2670 	push	ar5
      000B0A C0 04            [24] 2671 	push	ar4
      000B0C E5 08            [12] 2672 	mov	a,_bp
      000B0E 24 FA            [12] 2673 	add	a,#0xfa
      000B10 F8               [12] 2674 	mov	r0,a
      000B11 E6               [12] 2675 	mov	a,@r0
      000B12 C0 E0            [24] 2676 	push	acc
      000B14 08               [12] 2677 	inc	r0
      000B15 E6               [12] 2678 	mov	a,@r0
      000B16 C0 E0            [24] 2679 	push	acc
      000B18 08               [12] 2680 	inc	r0
      000B19 E6               [12] 2681 	mov	a,@r0
      000B1A C0 E0            [24] 2682 	push	acc
      000B1C 08               [12] 2683 	inc	r0
      000B1D E6               [12] 2684 	mov	a,@r0
      000B1E C0 E0            [24] 2685 	push	acc
      000B20 8F 82            [24] 2686 	mov	dpl, r7
      000B22 8E 83            [24] 2687 	mov	dph, r6
      000B24 8D F0            [24] 2688 	mov	b, r5
      000B26 EC               [12] 2689 	mov	a, r4
      000B27 12 41 7C         [24] 2690 	lcall	___fslt
      000B2A E5 81            [12] 2691 	mov	a,sp
      000B2C 24 FC            [12] 2692 	add	a,#0xfc
      000B2E F5 81            [12] 2693 	mov	sp,a
      000B30 D0 04            [24] 2694 	pop	ar4
      000B32 D0 05            [24] 2695 	pop	ar5
      000B34 D0 06            [24] 2696 	pop	ar6
      000B36 D0 07            [24] 2697 	pop	ar7
      000B38 E5 82            [12] 2698 	mov	a, dpl
      000B3A 24 FF            [12] 2699 	add	a,#0xff
      000B3C 92 00            [24] 2700 	mov	b0,c
      000B3E 40 09            [24] 2701 	jc	00102$
                           000A83  2702 	C$fuzzy.h$1584$2_0$66 ==.
                                   2703 ;	../../fuzzy.h:1584: return LEVEL_LO;
      000B40 90 00 00         [24] 2704 	mov	dptr,#0x0000
      000B43 E4               [12] 2705 	clr	a
      000B44 F5 F0            [12] 2706 	mov	b,a
      000B46 02 0D 29         [24] 2707 	ljmp	00109$
      000B49                       2708 00102$:
                           000A8C  2709 	C$fuzzy.h$1587$1_0$65 ==.
                                   2710 ;	../../fuzzy.h:1587: if (value <= lower_boundary) {
      000B49 C0 07            [24] 2711 	push	ar7
      000B4B C0 06            [24] 2712 	push	ar6
      000B4D C0 05            [24] 2713 	push	ar5
      000B4F C0 04            [24] 2714 	push	ar4
      000B51 E5 08            [12] 2715 	mov	a,_bp
      000B53 24 F6            [12] 2716 	add	a,#0xf6
      000B55 F8               [12] 2717 	mov	r0,a
      000B56 E6               [12] 2718 	mov	a,@r0
      000B57 C0 E0            [24] 2719 	push	acc
      000B59 08               [12] 2720 	inc	r0
      000B5A E6               [12] 2721 	mov	a,@r0
      000B5B C0 E0            [24] 2722 	push	acc
      000B5D 08               [12] 2723 	inc	r0
      000B5E E6               [12] 2724 	mov	a,@r0
      000B5F C0 E0            [24] 2725 	push	acc
      000B61 08               [12] 2726 	inc	r0
      000B62 E6               [12] 2727 	mov	a,@r0
      000B63 C0 E0            [24] 2728 	push	acc
      000B65 8F 82            [24] 2729 	mov	dpl, r7
      000B67 8E 83            [24] 2730 	mov	dph, r6
      000B69 8D F0            [24] 2731 	mov	b, r5
      000B6B EC               [12] 2732 	mov	a, r4
      000B6C 12 41 7C         [24] 2733 	lcall	___fslt
      000B6F E5 81            [12] 2734 	mov	a,sp
      000B71 24 FC            [12] 2735 	add	a,#0xfc
      000B73 F5 81            [12] 2736 	mov	sp,a
      000B75 D0 04            [24] 2737 	pop	ar4
      000B77 D0 05            [24] 2738 	pop	ar5
      000B79 D0 06            [24] 2739 	pop	ar6
      000B7B D0 07            [24] 2740 	pop	ar7
      000B7D E5 82            [12] 2741 	mov	a, dpl
      000B7F 24 FF            [12] 2742 	add	a,#0xff
      000B81 92 00            [24] 2743 	mov	b0,c
      000B83 40 39            [24] 2744 	jc	00107$
                           000AC8  2745 	C$fuzzy.h$1589$2_0$67 ==.
                                   2746 ;	../../fuzzy.h:1589: ramp_up
      000B85 E5 08            [12] 2747 	mov	a,_bp
      000B87 24 F5            [12] 2748 	add	a,#0xf5
      000B89 F8               [12] 2749 	mov	r0,a
      000B8A E6               [12] 2750 	mov	a,@r0
      000B8B 60 0F            [24] 2751 	jz	00111$
                           000AD0  2752 	C$fuzzy.h$1590$2_0$67 ==.
                                   2753 ;	../../fuzzy.h:1590: ? LEVEL_LO
      000B8D E5 08            [12] 2754 	mov	a,_bp
      000B8F 24 05            [12] 2755 	add	a,#0x05
      000B91 F8               [12] 2756 	mov	r0,a
      000B92 E4               [12] 2757 	clr	a
      000B93 F6               [12] 2758 	mov	@r0,a
      000B94 08               [12] 2759 	inc	r0
      000B95 F6               [12] 2760 	mov	@r0,a
      000B96 08               [12] 2761 	inc	r0
      000B97 F6               [12] 2762 	mov	@r0,a
      000B98 08               [12] 2763 	inc	r0
      000B99 F6               [12] 2764 	mov	@r0,a
      000B9A 80 0F            [24] 2765 	sjmp	00112$
      000B9C                       2766 00111$:
                           000ADF  2767 	C$fuzzy.h$1591$2_0$67 ==.
                                   2768 ;	../../fuzzy.h:1591: : LEVEL_HI;
      000B9C E5 08            [12] 2769 	mov	a,_bp
      000B9E 24 05            [12] 2770 	add	a,#0x05
      000BA0 F8               [12] 2771 	mov	r0,a
      000BA1 E4               [12] 2772 	clr	a
      000BA2 F6               [12] 2773 	mov	@r0,a
      000BA3 08               [12] 2774 	inc	r0
      000BA4 F6               [12] 2775 	mov	@r0,a
      000BA5 08               [12] 2776 	inc	r0
      000BA6 76 80            [12] 2777 	mov	@r0,#0x80
      000BA8 08               [12] 2778 	inc	r0
      000BA9 76 3F            [12] 2779 	mov	@r0,#0x3f
      000BAB                       2780 00112$:
      000BAB E5 08            [12] 2781 	mov	a,_bp
      000BAD 24 05            [12] 2782 	add	a,#0x05
      000BAF F8               [12] 2783 	mov	r0,a
      000BB0 86 07            [24] 2784 	mov	ar7,@r0
      000BB2 08               [12] 2785 	inc	r0
      000BB3 86 06            [24] 2786 	mov	ar6,@r0
      000BB5 08               [12] 2787 	inc	r0
      000BB6 86 05            [24] 2788 	mov	ar5,@r0
      000BB8 08               [12] 2789 	inc	r0
      000BB9 86 04            [24] 2790 	mov	ar4,@r0
      000BBB 02 0D 07         [24] 2791 	ljmp	00108$
      000BBE                       2792 00107$:
                           000B01  2793 	C$fuzzy.h$1593$1_0$65 ==.
                                   2794 ;	../../fuzzy.h:1593: else if (value >= upper_boundary) {
      000BBE C0 07            [24] 2795 	push	ar7
      000BC0 C0 06            [24] 2796 	push	ar6
      000BC2 C0 05            [24] 2797 	push	ar5
      000BC4 C0 04            [24] 2798 	push	ar4
      000BC6 E5 08            [12] 2799 	mov	a,_bp
      000BC8 24 FA            [12] 2800 	add	a,#0xfa
      000BCA F8               [12] 2801 	mov	r0,a
      000BCB E6               [12] 2802 	mov	a,@r0
      000BCC C0 E0            [24] 2803 	push	acc
      000BCE 08               [12] 2804 	inc	r0
      000BCF E6               [12] 2805 	mov	a,@r0
      000BD0 C0 E0            [24] 2806 	push	acc
      000BD2 08               [12] 2807 	inc	r0
      000BD3 E6               [12] 2808 	mov	a,@r0
      000BD4 C0 E0            [24] 2809 	push	acc
      000BD6 08               [12] 2810 	inc	r0
      000BD7 E6               [12] 2811 	mov	a,@r0
      000BD8 C0 E0            [24] 2812 	push	acc
      000BDA E5 08            [12] 2813 	mov	a,_bp
      000BDC 24 F6            [12] 2814 	add	a,#0xf6
      000BDE F8               [12] 2815 	mov	r0,a
      000BDF 86 82            [24] 2816 	mov	dpl, @r0
      000BE1 08               [12] 2817 	inc	r0
      000BE2 86 83            [24] 2818 	mov	dph, @r0
      000BE4 08               [12] 2819 	inc	r0
      000BE5 86 F0            [24] 2820 	mov	b, @r0
      000BE7 08               [12] 2821 	inc	r0
      000BE8 E6               [12] 2822 	mov	a, @r0
      000BE9 12 41 7C         [24] 2823 	lcall	___fslt
      000BEC E5 81            [12] 2824 	mov	a,sp
      000BEE 24 FC            [12] 2825 	add	a,#0xfc
      000BF0 F5 81            [12] 2826 	mov	sp,a
      000BF2 D0 04            [24] 2827 	pop	ar4
      000BF4 D0 05            [24] 2828 	pop	ar5
      000BF6 D0 06            [24] 2829 	pop	ar6
      000BF8 D0 07            [24] 2830 	pop	ar7
      000BFA E5 82            [12] 2831 	mov	a, dpl
      000BFC 24 FF            [12] 2832 	add	a,#0xff
      000BFE 92 00            [24] 2833 	mov	b0,c
      000C00 40 39            [24] 2834 	jc	00104$
                           000B45  2835 	C$fuzzy.h$1595$2_0$68 ==.
                                   2836 ;	../../fuzzy.h:1595: ramp_up
      000C02 E5 08            [12] 2837 	mov	a,_bp
      000C04 24 F5            [12] 2838 	add	a,#0xf5
      000C06 F8               [12] 2839 	mov	r0,a
      000C07 E6               [12] 2840 	mov	a,@r0
      000C08 60 11            [24] 2841 	jz	00113$
                           000B4D  2842 	C$fuzzy.h$1596$2_0$68 ==.
                                   2843 ;	../../fuzzy.h:1596: ? LEVEL_HI
      000C0A E5 08            [12] 2844 	mov	a,_bp
      000C0C 24 05            [12] 2845 	add	a,#0x05
      000C0E F8               [12] 2846 	mov	r0,a
      000C0F E4               [12] 2847 	clr	a
      000C10 F6               [12] 2848 	mov	@r0,a
      000C11 08               [12] 2849 	inc	r0
      000C12 F6               [12] 2850 	mov	@r0,a
      000C13 08               [12] 2851 	inc	r0
      000C14 76 80            [12] 2852 	mov	@r0,#0x80
      000C16 08               [12] 2853 	inc	r0
      000C17 76 3F            [12] 2854 	mov	@r0,#0x3f
      000C19 80 0D            [24] 2855 	sjmp	00114$
      000C1B                       2856 00113$:
                           000B5E  2857 	C$fuzzy.h$1597$2_0$68 ==.
                                   2858 ;	../../fuzzy.h:1597: : LEVEL_LO;
      000C1B E5 08            [12] 2859 	mov	a,_bp
      000C1D 24 05            [12] 2860 	add	a,#0x05
      000C1F F8               [12] 2861 	mov	r0,a
      000C20 E4               [12] 2862 	clr	a
      000C21 F6               [12] 2863 	mov	@r0,a
      000C22 08               [12] 2864 	inc	r0
      000C23 F6               [12] 2865 	mov	@r0,a
      000C24 08               [12] 2866 	inc	r0
      000C25 F6               [12] 2867 	mov	@r0,a
      000C26 08               [12] 2868 	inc	r0
      000C27 F6               [12] 2869 	mov	@r0,a
      000C28                       2870 00114$:
      000C28 E5 08            [12] 2871 	mov	a,_bp
      000C2A 24 05            [12] 2872 	add	a,#0x05
      000C2C F8               [12] 2873 	mov	r0,a
      000C2D 86 07            [24] 2874 	mov	ar7,@r0
      000C2F 08               [12] 2875 	inc	r0
      000C30 86 06            [24] 2876 	mov	ar6,@r0
      000C32 08               [12] 2877 	inc	r0
      000C33 86 05            [24] 2878 	mov	ar5,@r0
      000C35 08               [12] 2879 	inc	r0
      000C36 86 04            [24] 2880 	mov	ar4,@r0
      000C38 02 0D 07         [24] 2881 	ljmp	00108$
      000C3B                       2882 00104$:
                           000B7E  2883 	C$fuzzy.h$1601$1_0$65 ==.
                                   2884 ;	../../fuzzy.h:1601: (value - lower_boundary) /
      000C3B C0 07            [24] 2885 	push	ar7
      000C3D C0 06            [24] 2886 	push	ar6
      000C3F C0 05            [24] 2887 	push	ar5
      000C41 C0 04            [24] 2888 	push	ar4
      000C43 C0 07            [24] 2889 	push	ar7
      000C45 C0 06            [24] 2890 	push	ar6
      000C47 C0 05            [24] 2891 	push	ar5
      000C49 C0 04            [24] 2892 	push	ar4
                           000B8E  2893 	C$fuzzy.h$1602$1_0$65 ==.
                                   2894 ;	../../fuzzy.h:1602: (upper_boundary - lower_boundary);
      000C4B E5 08            [12] 2895 	mov	a,_bp
      000C4D 24 F6            [12] 2896 	add	a,#0xf6
      000C4F F8               [12] 2897 	mov	r0,a
      000C50 86 82            [24] 2898 	mov	dpl, @r0
      000C52 08               [12] 2899 	inc	r0
      000C53 86 83            [24] 2900 	mov	dph, @r0
      000C55 08               [12] 2901 	inc	r0
      000C56 86 F0            [24] 2902 	mov	b, @r0
      000C58 08               [12] 2903 	inc	r0
      000C59 E6               [12] 2904 	mov	a, @r0
      000C5A 12 40 41         [24] 2905 	lcall	___fssub
      000C5D A8 08            [24] 2906 	mov	r0,_bp
      000C5F 08               [12] 2907 	inc	r0
      000C60 A6 82            [24] 2908 	mov	@r0, dpl
      000C62 08               [12] 2909 	inc	r0
      000C63 A6 83            [24] 2910 	mov	@r0, dph
      000C65 08               [12] 2911 	inc	r0
      000C66 A6 F0            [24] 2912 	mov	@r0, b
      000C68 08               [12] 2913 	inc	r0
      000C69 F6               [12] 2914 	mov	@r0,a
      000C6A E5 81            [12] 2915 	mov	a,sp
      000C6C 24 FC            [12] 2916 	add	a,#0xfc
      000C6E F5 81            [12] 2917 	mov	sp,a
      000C70 E5 08            [12] 2918 	mov	a,_bp
      000C72 24 FA            [12] 2919 	add	a,#0xfa
      000C74 F8               [12] 2920 	mov	r0,a
      000C75 86 82            [24] 2921 	mov	dpl, @r0
      000C77 08               [12] 2922 	inc	r0
      000C78 86 83            [24] 2923 	mov	dph, @r0
      000C7A 08               [12] 2924 	inc	r0
      000C7B 86 F0            [24] 2925 	mov	b, @r0
      000C7D 08               [12] 2926 	inc	r0
      000C7E E6               [12] 2927 	mov	a, @r0
      000C7F 12 40 41         [24] 2928 	lcall	___fssub
      000C82 AC 82            [24] 2929 	mov	r4, dpl
      000C84 AD 83            [24] 2930 	mov	r5, dph
      000C86 AE F0            [24] 2931 	mov	r6, b
      000C88 FF               [12] 2932 	mov	r7, a
      000C89 E5 81            [12] 2933 	mov	a,sp
      000C8B 24 FC            [12] 2934 	add	a,#0xfc
      000C8D F5 81            [12] 2935 	mov	sp,a
      000C8F C0 04            [24] 2936 	push	ar4
      000C91 C0 05            [24] 2937 	push	ar5
      000C93 C0 06            [24] 2938 	push	ar6
      000C95 C0 07            [24] 2939 	push	ar7
                           000BDA  2940 	C$fuzzy.h$1605$1_0$65 ==.
                                   2941 ;	../../fuzzy.h:1605: ramp_up
      000C97 A8 08            [24] 2942 	mov	r0,_bp
      000C99 08               [12] 2943 	inc	r0
      000C9A 86 82            [24] 2944 	mov	dpl, @r0
      000C9C 08               [12] 2945 	inc	r0
      000C9D 86 83            [24] 2946 	mov	dph, @r0
      000C9F 08               [12] 2947 	inc	r0
      000CA0 86 F0            [24] 2948 	mov	b, @r0
      000CA2 08               [12] 2949 	inc	r0
      000CA3 E6               [12] 2950 	mov	a, @r0
      000CA4 12 42 E5         [24] 2951 	lcall	___fsdiv
      000CA7 AC 82            [24] 2952 	mov	r4, dpl
      000CA9 AD 83            [24] 2953 	mov	r5, dph
      000CAB AE F0            [24] 2954 	mov	r6, b
      000CAD FF               [12] 2955 	mov	r7, a
      000CAE E5 81            [12] 2956 	mov	a,sp
      000CB0 24 FC            [12] 2957 	add	a,#0xfc
      000CB2 F5 81            [12] 2958 	mov	sp,a
      000CB4 E5 08            [12] 2959 	mov	a,_bp
      000CB6 24 F5            [12] 2960 	add	a,#0xf5
      000CB8 F8               [12] 2961 	mov	r0,a
      000CB9 E6               [12] 2962 	mov	a,@r0
      000CBA 60 12            [24] 2963 	jz	00115$
                           000BFF  2964 	C$fuzzy.h$1606$2_0$69 ==.
                                   2965 ;	../../fuzzy.h:1606: ? normalized
      000CBC E5 08            [12] 2966 	mov	a,_bp
      000CBE 24 05            [12] 2967 	add	a,#0x05
      000CC0 F8               [12] 2968 	mov	r0,a
      000CC1 A6 04            [24] 2969 	mov	@r0,ar4
      000CC3 08               [12] 2970 	inc	r0
      000CC4 A6 05            [24] 2971 	mov	@r0,ar5
      000CC6 08               [12] 2972 	inc	r0
      000CC7 A6 06            [24] 2973 	mov	@r0,ar6
      000CC9 08               [12] 2974 	inc	r0
      000CCA A6 07            [24] 2975 	mov	@r0,ar7
      000CCC 80 29            [24] 2976 	sjmp	00116$
      000CCE                       2977 00115$:
                           000C11  2978 	C$fuzzy.h$1607$1_0$65 ==.
                                   2979 ;	../../fuzzy.h:1607: : LEVEL_HI - normalized;
      000CCE C0 04            [24] 2980 	push	ar4
      000CD0 C0 05            [24] 2981 	push	ar5
      000CD2 C0 06            [24] 2982 	push	ar6
      000CD4 C0 07            [24] 2983 	push	ar7
      000CD6 90 00 00         [24] 2984 	mov	dptr,#0x0000
      000CD9 75 F0 80         [24] 2985 	mov	b, #0x80
      000CDC 74 3F            [12] 2986 	mov	a, #0x3f
      000CDE 12 40 41         [24] 2987 	lcall	___fssub
      000CE1 C8               [12] 2988 	xch	a,r0
      000CE2 E5 08            [12] 2989 	mov	a,_bp
      000CE4 24 05            [12] 2990 	add	a,#0x05
      000CE6 C8               [12] 2991 	xch	a,r0
      000CE7 A6 82            [24] 2992 	mov	@r0, dpl
      000CE9 08               [12] 2993 	inc	r0
      000CEA A6 83            [24] 2994 	mov	@r0, dph
      000CEC 08               [12] 2995 	inc	r0
      000CED A6 F0            [24] 2996 	mov	@r0, b
      000CEF 08               [12] 2997 	inc	r0
      000CF0 F6               [12] 2998 	mov	@r0,a
      000CF1 E5 81            [12] 2999 	mov	a,sp
      000CF3 24 FC            [12] 3000 	add	a,#0xfc
      000CF5 F5 81            [12] 3001 	mov	sp,a
      000CF7                       3002 00116$:
      000CF7 E5 08            [12] 3003 	mov	a,_bp
      000CF9 24 05            [12] 3004 	add	a,#0x05
      000CFB F8               [12] 3005 	mov	r0,a
      000CFC 86 07            [24] 3006 	mov	ar7,@r0
      000CFE 08               [12] 3007 	inc	r0
      000CFF 86 06            [24] 3008 	mov	ar6,@r0
      000D01 08               [12] 3009 	inc	r0
      000D02 86 05            [24] 3010 	mov	ar5,@r0
      000D04 08               [12] 3011 	inc	r0
      000D05 86 04            [24] 3012 	mov	ar4,@r0
      000D07                       3013 00108$:
                           000C4A  3014 	C$fuzzy.h$1611$1_0$65 ==.
                                   3015 ;	../../fuzzy.h:1611: result,
      000D07 E5 08            [12] 3016 	mov	a,_bp
      000D09 24 F4            [12] 3017 	add	a,#0xf4
      000D0B F8               [12] 3018 	mov	r0,a
      000D0C E6               [12] 3019 	mov	a,@r0
      000D0D C0 E0            [24] 3020 	push	acc
      000D0F 8F 82            [24] 3021 	mov	dpl, r7
      000D11 8E 83            [24] 3022 	mov	dph, r6
      000D13 8D F0            [24] 3023 	mov	b, r5
      000D15 EC               [12] 3024 	mov	a, r4
      000D16 12 01 9F         [24] 3025 	lcall	_fuzzy_apply_hedge
      000D19 AC 82            [24] 3026 	mov	r4, dpl
      000D1B AD 83            [24] 3027 	mov	r5, dph
      000D1D AE F0            [24] 3028 	mov	r6, b
      000D1F FF               [12] 3029 	mov	r7, a
      000D20 15 81            [12] 3030 	dec	sp
      000D22 8C 82            [24] 3031 	mov	dpl, r4
      000D24 8D 83            [24] 3032 	mov	dph, r5
      000D26 8E F0            [24] 3033 	mov	b, r6
      000D28 EF               [12] 3034 	mov	a, r7
      000D29                       3035 00109$:
                           000C6C  3036 	C$fuzzy.h$1614$1_0$65 ==.
                                   3037 ;	../../fuzzy.h:1614: }
      000D29 85 08 81         [24] 3038 	mov	sp,_bp
      000D2C D0 08            [24] 3039 	pop	_bp
                           000C71  3040 	C$fuzzy.h$1614$1_0$65 ==.
                           000C71  3041 	XG$fuzzy_ramp$0$0 ==.
      000D2E 22               [24] 3042 	ret
                                   3043 ;------------------------------------------------------------
                                   3044 ;Allocation info for local variables in function 'fuzzy_triangle'
                                   3045 ;------------------------------------------------------------
                                   3046 ;b             Allocated to stack - _bp -6 +4 
                                   3047 ;c             Allocated to stack - _bp -10 +4 
                                   3048 ;value         Allocated to stack - _bp -14 +4 
                                   3049 ;hedge         Allocated to stack - _bp -15 +1 
                                   3050 ;a             Allocated to registers r7 r6 r5 r4 
                                   3051 ;result        Allocated to stack - _bp +1 +4 
                                   3052 ;sloc0         Allocated to stack - _bp +1 +4 
                                   3053 ;sloc1         Allocated to stack - _bp +5 +4 
                                   3054 ;------------------------------------------------------------
                           000C72  3055 	G$fuzzy_triangle$0$0 ==.
                           000C72  3056 	C$fuzzy.h$1658$1_0$71 ==.
                                   3057 ;	../../fuzzy.h:1658: float fuzzy_triangle(
                                   3058 ;	-----------------------------------------
                                   3059 ;	 function fuzzy_triangle
                                   3060 ;	-----------------------------------------
      000D2F                       3061 _fuzzy_triangle:
      000D2F C0 08            [24] 3062 	push	_bp
      000D31 85 81 08         [24] 3063 	mov	_bp,sp
      000D34 AF 82            [24] 3064 	mov	r7,dpl
      000D36 AE 83            [24] 3065 	mov	r6,dph
      000D38 AD F0            [24] 3066 	mov	r5,b
      000D3A FC               [12] 3067 	mov	r4,a
      000D3B E5 81            [12] 3068 	mov	a,sp
      000D3D 24 08            [12] 3069 	add	a,#0x08
      000D3F F5 81            [12] 3070 	mov	sp,a
                           000C84  3071 	C$fuzzy.h$1669$1_0$71 ==.
                                   3072 ;	../../fuzzy.h:1669: a >= b ||
      000D41 C0 07            [24] 3073 	push	ar7
      000D43 C0 06            [24] 3074 	push	ar6
      000D45 C0 05            [24] 3075 	push	ar5
      000D47 C0 04            [24] 3076 	push	ar4
      000D49 E5 08            [12] 3077 	mov	a,_bp
      000D4B 24 FA            [12] 3078 	add	a,#0xfa
      000D4D F8               [12] 3079 	mov	r0,a
      000D4E E6               [12] 3080 	mov	a,@r0
      000D4F C0 E0            [24] 3081 	push	acc
      000D51 08               [12] 3082 	inc	r0
      000D52 E6               [12] 3083 	mov	a,@r0
      000D53 C0 E0            [24] 3084 	push	acc
      000D55 08               [12] 3085 	inc	r0
      000D56 E6               [12] 3086 	mov	a,@r0
      000D57 C0 E0            [24] 3087 	push	acc
      000D59 08               [12] 3088 	inc	r0
      000D5A E6               [12] 3089 	mov	a,@r0
      000D5B C0 E0            [24] 3090 	push	acc
      000D5D 8F 82            [24] 3091 	mov	dpl, r7
      000D5F 8E 83            [24] 3092 	mov	dph, r6
      000D61 8D F0            [24] 3093 	mov	b, r5
      000D63 EC               [12] 3094 	mov	a, r4
      000D64 12 41 7C         [24] 3095 	lcall	___fslt
      000D67 E5 81            [12] 3096 	mov	a,sp
      000D69 24 FC            [12] 3097 	add	a,#0xfc
      000D6B F5 81            [12] 3098 	mov	sp,a
      000D6D D0 04            [24] 3099 	pop	ar4
      000D6F D0 05            [24] 3100 	pop	ar5
      000D71 D0 06            [24] 3101 	pop	ar6
      000D73 D0 07            [24] 3102 	pop	ar7
      000D75 E5 82            [12] 3103 	mov	a, dpl
      000D77 24 FF            [12] 3104 	add	a,#0xff
      000D79 92 00            [24] 3105 	mov	b0,c
      000D7B 40 03            [24] 3106 	jc	00145$
      000D7D 02 0E 47         [24] 3107 	ljmp	00107$
      000D80                       3108 00145$:
                           000CC3  3109 	C$fuzzy.h$1670$1_0$71 ==.
                                   3110 ;	../../fuzzy.h:1670: b >= c ||
      000D80 C0 07            [24] 3111 	push	ar7
      000D82 C0 06            [24] 3112 	push	ar6
      000D84 C0 05            [24] 3113 	push	ar5
      000D86 C0 04            [24] 3114 	push	ar4
      000D88 E5 08            [12] 3115 	mov	a,_bp
      000D8A 24 F6            [12] 3116 	add	a,#0xf6
      000D8C F8               [12] 3117 	mov	r0,a
      000D8D E6               [12] 3118 	mov	a,@r0
      000D8E C0 E0            [24] 3119 	push	acc
      000D90 08               [12] 3120 	inc	r0
      000D91 E6               [12] 3121 	mov	a,@r0
      000D92 C0 E0            [24] 3122 	push	acc
      000D94 08               [12] 3123 	inc	r0
      000D95 E6               [12] 3124 	mov	a,@r0
      000D96 C0 E0            [24] 3125 	push	acc
      000D98 08               [12] 3126 	inc	r0
      000D99 E6               [12] 3127 	mov	a,@r0
      000D9A C0 E0            [24] 3128 	push	acc
      000D9C E5 08            [12] 3129 	mov	a,_bp
      000D9E 24 FA            [12] 3130 	add	a,#0xfa
      000DA0 F8               [12] 3131 	mov	r0,a
      000DA1 86 82            [24] 3132 	mov	dpl, @r0
      000DA3 08               [12] 3133 	inc	r0
      000DA4 86 83            [24] 3134 	mov	dph, @r0
      000DA6 08               [12] 3135 	inc	r0
      000DA7 86 F0            [24] 3136 	mov	b, @r0
      000DA9 08               [12] 3137 	inc	r0
      000DAA E6               [12] 3138 	mov	a, @r0
      000DAB 12 41 7C         [24] 3139 	lcall	___fslt
      000DAE E5 81            [12] 3140 	mov	a,sp
      000DB0 24 FC            [12] 3141 	add	a,#0xfc
      000DB2 F5 81            [12] 3142 	mov	sp,a
      000DB4 D0 04            [24] 3143 	pop	ar4
      000DB6 D0 05            [24] 3144 	pop	ar5
      000DB8 D0 06            [24] 3145 	pop	ar6
      000DBA D0 07            [24] 3146 	pop	ar7
      000DBC E5 82            [12] 3147 	mov	a, dpl
      000DBE 24 FF            [12] 3148 	add	a,#0xff
      000DC0 92 00            [24] 3149 	mov	b0,c
      000DC2 40 03            [24] 3150 	jc	00146$
      000DC4 02 0E 47         [24] 3151 	ljmp	00107$
      000DC7                       3152 00146$:
                           000D0A  3153 	C$fuzzy.h$1671$1_0$71 ==.
                                   3154 ;	../../fuzzy.h:1671: value <= a ||
      000DC7 C0 07            [24] 3155 	push	ar7
      000DC9 C0 06            [24] 3156 	push	ar6
      000DCB C0 05            [24] 3157 	push	ar5
      000DCD C0 04            [24] 3158 	push	ar4
      000DCF E5 08            [12] 3159 	mov	a,_bp
      000DD1 24 F2            [12] 3160 	add	a,#0xf2
      000DD3 F8               [12] 3161 	mov	r0,a
      000DD4 E6               [12] 3162 	mov	a,@r0
      000DD5 C0 E0            [24] 3163 	push	acc
      000DD7 08               [12] 3164 	inc	r0
      000DD8 E6               [12] 3165 	mov	a,@r0
      000DD9 C0 E0            [24] 3166 	push	acc
      000DDB 08               [12] 3167 	inc	r0
      000DDC E6               [12] 3168 	mov	a,@r0
      000DDD C0 E0            [24] 3169 	push	acc
      000DDF 08               [12] 3170 	inc	r0
      000DE0 E6               [12] 3171 	mov	a,@r0
      000DE1 C0 E0            [24] 3172 	push	acc
      000DE3 8F 82            [24] 3173 	mov	dpl, r7
      000DE5 8E 83            [24] 3174 	mov	dph, r6
      000DE7 8D F0            [24] 3175 	mov	b, r5
      000DE9 EC               [12] 3176 	mov	a, r4
      000DEA 12 41 7C         [24] 3177 	lcall	___fslt
      000DED E5 81            [12] 3178 	mov	a,sp
      000DEF 24 FC            [12] 3179 	add	a,#0xfc
      000DF1 F5 81            [12] 3180 	mov	sp,a
      000DF3 D0 04            [24] 3181 	pop	ar4
      000DF5 D0 05            [24] 3182 	pop	ar5
      000DF7 D0 06            [24] 3183 	pop	ar6
      000DF9 D0 07            [24] 3184 	pop	ar7
      000DFB E5 82            [12] 3185 	mov	a, dpl
      000DFD 24 FF            [12] 3186 	add	a,#0xff
      000DFF 92 00            [24] 3187 	mov	b0,c
      000E01 50 44            [24] 3188 	jnc	00107$
                           000D46  3189 	C$fuzzy.h$1673$1_0$71 ==.
                                   3190 ;	../../fuzzy.h:1673: ) {
      000E03 C0 07            [24] 3191 	push	ar7
      000E05 C0 06            [24] 3192 	push	ar6
      000E07 C0 05            [24] 3193 	push	ar5
      000E09 C0 04            [24] 3194 	push	ar4
      000E0B E5 08            [12] 3195 	mov	a,_bp
      000E0D 24 F6            [12] 3196 	add	a,#0xf6
      000E0F F8               [12] 3197 	mov	r0,a
      000E10 E6               [12] 3198 	mov	a,@r0
      000E11 C0 E0            [24] 3199 	push	acc
      000E13 08               [12] 3200 	inc	r0
      000E14 E6               [12] 3201 	mov	a,@r0
      000E15 C0 E0            [24] 3202 	push	acc
      000E17 08               [12] 3203 	inc	r0
      000E18 E6               [12] 3204 	mov	a,@r0
      000E19 C0 E0            [24] 3205 	push	acc
      000E1B 08               [12] 3206 	inc	r0
      000E1C E6               [12] 3207 	mov	a,@r0
      000E1D C0 E0            [24] 3208 	push	acc
      000E1F E5 08            [12] 3209 	mov	a,_bp
      000E21 24 F2            [12] 3210 	add	a,#0xf2
      000E23 F8               [12] 3211 	mov	r0,a
      000E24 86 82            [24] 3212 	mov	dpl, @r0
      000E26 08               [12] 3213 	inc	r0
      000E27 86 83            [24] 3214 	mov	dph, @r0
      000E29 08               [12] 3215 	inc	r0
      000E2A 86 F0            [24] 3216 	mov	b, @r0
      000E2C 08               [12] 3217 	inc	r0
      000E2D E6               [12] 3218 	mov	a, @r0
      000E2E 12 41 7C         [24] 3219 	lcall	___fslt
      000E31 E5 81            [12] 3220 	mov	a,sp
      000E33 24 FC            [12] 3221 	add	a,#0xfc
      000E35 F5 81            [12] 3222 	mov	sp,a
      000E37 D0 04            [24] 3223 	pop	ar4
      000E39 D0 05            [24] 3224 	pop	ar5
      000E3B D0 06            [24] 3225 	pop	ar6
      000E3D D0 07            [24] 3226 	pop	ar7
      000E3F E5 82            [12] 3227 	mov	a, dpl
      000E41 24 FF            [12] 3228 	add	a,#0xff
      000E43 92 00            [24] 3229 	mov	b0,c
      000E45 40 0E            [24] 3230 	jc	00108$
      000E47                       3231 00107$:
                           000D8A  3232 	C$fuzzy.h$1674$2_0$72 ==.
                                   3233 ;	../../fuzzy.h:1674: result = LEVEL_LO;
      000E47 A8 08            [24] 3234 	mov	r0,_bp
      000E49 08               [12] 3235 	inc	r0
      000E4A E4               [12] 3236 	clr	a
      000E4B F6               [12] 3237 	mov	@r0,a
      000E4C 08               [12] 3238 	inc	r0
      000E4D F6               [12] 3239 	mov	@r0,a
      000E4E 08               [12] 3240 	inc	r0
      000E4F F6               [12] 3241 	mov	@r0,a
      000E50 08               [12] 3242 	inc	r0
      000E51 F6               [12] 3243 	mov	@r0,a
      000E52 02 10 0D         [24] 3244 	ljmp	00109$
      000E55                       3245 00108$:
                           000D98  3246 	C$fuzzy.h$1676$1_0$71 ==.
                                   3247 ;	../../fuzzy.h:1676: else if (value == b) {
      000E55 C0 07            [24] 3248 	push	ar7
      000E57 C0 06            [24] 3249 	push	ar6
      000E59 C0 05            [24] 3250 	push	ar5
      000E5B C0 04            [24] 3251 	push	ar4
      000E5D E5 08            [12] 3252 	mov	a,_bp
      000E5F 24 FA            [12] 3253 	add	a,#0xfa
      000E61 F8               [12] 3254 	mov	r0,a
      000E62 E6               [12] 3255 	mov	a,@r0
      000E63 C0 E0            [24] 3256 	push	acc
      000E65 08               [12] 3257 	inc	r0
      000E66 E6               [12] 3258 	mov	a,@r0
      000E67 C0 E0            [24] 3259 	push	acc
      000E69 08               [12] 3260 	inc	r0
      000E6A E6               [12] 3261 	mov	a,@r0
      000E6B C0 E0            [24] 3262 	push	acc
      000E6D 08               [12] 3263 	inc	r0
      000E6E E6               [12] 3264 	mov	a,@r0
      000E6F C0 E0            [24] 3265 	push	acc
      000E71 E5 08            [12] 3266 	mov	a,_bp
      000E73 24 F2            [12] 3267 	add	a,#0xf2
      000E75 F8               [12] 3268 	mov	r0,a
      000E76 86 82            [24] 3269 	mov	dpl, @r0
      000E78 08               [12] 3270 	inc	r0
      000E79 86 83            [24] 3271 	mov	dph, @r0
      000E7B 08               [12] 3272 	inc	r0
      000E7C 86 F0            [24] 3273 	mov	b, @r0
      000E7E 08               [12] 3274 	inc	r0
      000E7F E6               [12] 3275 	mov	a, @r0
      000E80 12 41 50         [24] 3276 	lcall	___fseq
      000E83 AB 82            [24] 3277 	mov	r3, dpl
      000E85 E5 81            [12] 3278 	mov	a,sp
      000E87 24 FC            [12] 3279 	add	a,#0xfc
      000E89 F5 81            [12] 3280 	mov	sp,a
      000E8B D0 04            [24] 3281 	pop	ar4
      000E8D D0 05            [24] 3282 	pop	ar5
      000E8F D0 06            [24] 3283 	pop	ar6
      000E91 D0 07            [24] 3284 	pop	ar7
      000E93 EB               [12] 3285 	mov	a,r3
      000E94 60 10            [24] 3286 	jz	00105$
                           000DD9  3287 	C$fuzzy.h$1677$2_0$73 ==.
                                   3288 ;	../../fuzzy.h:1677: result = LEVEL_HI;
      000E96 A8 08            [24] 3289 	mov	r0,_bp
      000E98 08               [12] 3290 	inc	r0
      000E99 E4               [12] 3291 	clr	a
      000E9A F6               [12] 3292 	mov	@r0,a
      000E9B 08               [12] 3293 	inc	r0
      000E9C F6               [12] 3294 	mov	@r0,a
      000E9D 08               [12] 3295 	inc	r0
      000E9E 76 80            [12] 3296 	mov	@r0,#0x80
      000EA0 08               [12] 3297 	inc	r0
      000EA1 76 3F            [12] 3298 	mov	@r0,#0x3f
      000EA3 02 10 0D         [24] 3299 	ljmp	00109$
      000EA6                       3300 00105$:
                           000DE9  3301 	C$fuzzy.h$1679$1_0$71 ==.
                                   3302 ;	../../fuzzy.h:1679: else if (value < b) {
      000EA6 C0 07            [24] 3303 	push	ar7
      000EA8 C0 06            [24] 3304 	push	ar6
      000EAA C0 05            [24] 3305 	push	ar5
      000EAC C0 04            [24] 3306 	push	ar4
      000EAE E5 08            [12] 3307 	mov	a,_bp
      000EB0 24 FA            [12] 3308 	add	a,#0xfa
      000EB2 F8               [12] 3309 	mov	r0,a
      000EB3 E6               [12] 3310 	mov	a,@r0
      000EB4 C0 E0            [24] 3311 	push	acc
      000EB6 08               [12] 3312 	inc	r0
      000EB7 E6               [12] 3313 	mov	a,@r0
      000EB8 C0 E0            [24] 3314 	push	acc
      000EBA 08               [12] 3315 	inc	r0
      000EBB E6               [12] 3316 	mov	a,@r0
      000EBC C0 E0            [24] 3317 	push	acc
      000EBE 08               [12] 3318 	inc	r0
      000EBF E6               [12] 3319 	mov	a,@r0
      000EC0 C0 E0            [24] 3320 	push	acc
      000EC2 E5 08            [12] 3321 	mov	a,_bp
      000EC4 24 F2            [12] 3322 	add	a,#0xf2
      000EC6 F8               [12] 3323 	mov	r0,a
      000EC7 86 82            [24] 3324 	mov	dpl, @r0
      000EC9 08               [12] 3325 	inc	r0
      000ECA 86 83            [24] 3326 	mov	dph, @r0
      000ECC 08               [12] 3327 	inc	r0
      000ECD 86 F0            [24] 3328 	mov	b, @r0
      000ECF 08               [12] 3329 	inc	r0
      000ED0 E6               [12] 3330 	mov	a, @r0
      000ED1 12 41 7C         [24] 3331 	lcall	___fslt
      000ED4 AB 82            [24] 3332 	mov	r3, dpl
      000ED6 E5 81            [12] 3333 	mov	a,sp
      000ED8 24 FC            [12] 3334 	add	a,#0xfc
      000EDA F5 81            [12] 3335 	mov	sp,a
      000EDC D0 04            [24] 3336 	pop	ar4
      000EDE D0 05            [24] 3337 	pop	ar5
      000EE0 D0 06            [24] 3338 	pop	ar6
      000EE2 D0 07            [24] 3339 	pop	ar7
      000EE4 EB               [12] 3340 	mov	a,r3
      000EE5 70 03            [24] 3341 	jnz	00150$
      000EE7 02 0F 71         [24] 3342 	ljmp	00102$
      000EEA                       3343 00150$:
                           000E2D  3344 	C$fuzzy.h$1681$1_0$71 ==.
                                   3345 ;	../../fuzzy.h:1681: (value - a) /
      000EEA C0 07            [24] 3346 	push	ar7
      000EEC C0 06            [24] 3347 	push	ar6
      000EEE C0 05            [24] 3348 	push	ar5
      000EF0 C0 04            [24] 3349 	push	ar4
      000EF2 C0 07            [24] 3350 	push	ar7
      000EF4 C0 06            [24] 3351 	push	ar6
      000EF6 C0 05            [24] 3352 	push	ar5
      000EF8 C0 04            [24] 3353 	push	ar4
                           000E3D  3354 	C$fuzzy.h$1682$1_0$71 ==.
                                   3355 ;	../../fuzzy.h:1682: (b - a);
      000EFA E5 08            [12] 3356 	mov	a,_bp
      000EFC 24 F2            [12] 3357 	add	a,#0xf2
      000EFE F8               [12] 3358 	mov	r0,a
      000EFF 86 82            [24] 3359 	mov	dpl, @r0
      000F01 08               [12] 3360 	inc	r0
      000F02 86 83            [24] 3361 	mov	dph, @r0
      000F04 08               [12] 3362 	inc	r0
      000F05 86 F0            [24] 3363 	mov	b, @r0
      000F07 08               [12] 3364 	inc	r0
      000F08 E6               [12] 3365 	mov	a, @r0
      000F09 12 40 41         [24] 3366 	lcall	___fssub
      000F0C C8               [12] 3367 	xch	a,r0
      000F0D E5 08            [12] 3368 	mov	a,_bp
      000F0F 24 05            [12] 3369 	add	a,#0x05
      000F11 C8               [12] 3370 	xch	a,r0
      000F12 A6 82            [24] 3371 	mov	@r0, dpl
      000F14 08               [12] 3372 	inc	r0
      000F15 A6 83            [24] 3373 	mov	@r0, dph
      000F17 08               [12] 3374 	inc	r0
      000F18 A6 F0            [24] 3375 	mov	@r0, b
      000F1A 08               [12] 3376 	inc	r0
      000F1B F6               [12] 3377 	mov	@r0,a
      000F1C E5 81            [12] 3378 	mov	a,sp
      000F1E 24 FC            [12] 3379 	add	a,#0xfc
      000F20 F5 81            [12] 3380 	mov	sp,a
      000F22 E5 08            [12] 3381 	mov	a,_bp
      000F24 24 FA            [12] 3382 	add	a,#0xfa
      000F26 F8               [12] 3383 	mov	r0,a
      000F27 86 82            [24] 3384 	mov	dpl, @r0
      000F29 08               [12] 3385 	inc	r0
      000F2A 86 83            [24] 3386 	mov	dph, @r0
      000F2C 08               [12] 3387 	inc	r0
      000F2D 86 F0            [24] 3388 	mov	b, @r0
      000F2F 08               [12] 3389 	inc	r0
      000F30 E6               [12] 3390 	mov	a, @r0
      000F31 12 40 41         [24] 3391 	lcall	___fssub
      000F34 AC 82            [24] 3392 	mov	r4, dpl
      000F36 AD 83            [24] 3393 	mov	r5, dph
      000F38 AE F0            [24] 3394 	mov	r6, b
      000F3A FF               [12] 3395 	mov	r7, a
      000F3B E5 81            [12] 3396 	mov	a,sp
      000F3D 24 FC            [12] 3397 	add	a,#0xfc
      000F3F F5 81            [12] 3398 	mov	sp,a
      000F41 C0 04            [24] 3399 	push	ar4
      000F43 C0 05            [24] 3400 	push	ar5
      000F45 C0 06            [24] 3401 	push	ar6
      000F47 C0 07            [24] 3402 	push	ar7
      000F49 E5 08            [12] 3403 	mov	a,_bp
      000F4B 24 05            [12] 3404 	add	a,#0x05
      000F4D F8               [12] 3405 	mov	r0,a
      000F4E 86 82            [24] 3406 	mov	dpl, @r0
      000F50 08               [12] 3407 	inc	r0
      000F51 86 83            [24] 3408 	mov	dph, @r0
      000F53 08               [12] 3409 	inc	r0
      000F54 86 F0            [24] 3410 	mov	b, @r0
      000F56 08               [12] 3411 	inc	r0
      000F57 E6               [12] 3412 	mov	a, @r0
      000F58 12 42 E5         [24] 3413 	lcall	___fsdiv
      000F5B A8 08            [24] 3414 	mov	r0,_bp
      000F5D 08               [12] 3415 	inc	r0
      000F5E A6 82            [24] 3416 	mov	@r0, dpl
      000F60 08               [12] 3417 	inc	r0
      000F61 A6 83            [24] 3418 	mov	@r0, dph
      000F63 08               [12] 3419 	inc	r0
      000F64 A6 F0            [24] 3420 	mov	@r0, b
      000F66 08               [12] 3421 	inc	r0
      000F67 F6               [12] 3422 	mov	@r0,a
      000F68 E5 81            [12] 3423 	mov	a,sp
      000F6A 24 FC            [12] 3424 	add	a,#0xfc
      000F6C F5 81            [12] 3425 	mov	sp,a
      000F6E 02 10 0D         [24] 3426 	ljmp	00109$
      000F71                       3427 00102$:
                           000EB4  3428 	C$fuzzy.h$1686$1_0$71 ==.
                                   3429 ;	../../fuzzy.h:1686: (c - value) /
      000F71 E5 08            [12] 3430 	mov	a,_bp
      000F73 24 F2            [12] 3431 	add	a,#0xf2
      000F75 F8               [12] 3432 	mov	r0,a
      000F76 E6               [12] 3433 	mov	a,@r0
      000F77 C0 E0            [24] 3434 	push	acc
      000F79 08               [12] 3435 	inc	r0
      000F7A E6               [12] 3436 	mov	a,@r0
      000F7B C0 E0            [24] 3437 	push	acc
      000F7D 08               [12] 3438 	inc	r0
      000F7E E6               [12] 3439 	mov	a,@r0
      000F7F C0 E0            [24] 3440 	push	acc
      000F81 08               [12] 3441 	inc	r0
      000F82 E6               [12] 3442 	mov	a,@r0
      000F83 C0 E0            [24] 3443 	push	acc
                           000EC8  3444 	C$fuzzy.h$1687$1_0$71 ==.
                                   3445 ;	../../fuzzy.h:1687: (c - b);
      000F85 E5 08            [12] 3446 	mov	a,_bp
      000F87 24 F6            [12] 3447 	add	a,#0xf6
      000F89 F8               [12] 3448 	mov	r0,a
      000F8A 86 82            [24] 3449 	mov	dpl, @r0
      000F8C 08               [12] 3450 	inc	r0
      000F8D 86 83            [24] 3451 	mov	dph, @r0
      000F8F 08               [12] 3452 	inc	r0
      000F90 86 F0            [24] 3453 	mov	b, @r0
      000F92 08               [12] 3454 	inc	r0
      000F93 E6               [12] 3455 	mov	a, @r0
      000F94 12 40 41         [24] 3456 	lcall	___fssub
      000F97 C8               [12] 3457 	xch	a,r0
      000F98 E5 08            [12] 3458 	mov	a,_bp
      000F9A 24 05            [12] 3459 	add	a,#0x05
      000F9C C8               [12] 3460 	xch	a,r0
      000F9D A6 82            [24] 3461 	mov	@r0, dpl
      000F9F 08               [12] 3462 	inc	r0
      000FA0 A6 83            [24] 3463 	mov	@r0, dph
      000FA2 08               [12] 3464 	inc	r0
      000FA3 A6 F0            [24] 3465 	mov	@r0, b
      000FA5 08               [12] 3466 	inc	r0
      000FA6 F6               [12] 3467 	mov	@r0,a
      000FA7 E5 81            [12] 3468 	mov	a,sp
      000FA9 24 FC            [12] 3469 	add	a,#0xfc
      000FAB F5 81            [12] 3470 	mov	sp,a
      000FAD E5 08            [12] 3471 	mov	a,_bp
      000FAF 24 FA            [12] 3472 	add	a,#0xfa
      000FB1 F8               [12] 3473 	mov	r0,a
      000FB2 E6               [12] 3474 	mov	a,@r0
      000FB3 C0 E0            [24] 3475 	push	acc
      000FB5 08               [12] 3476 	inc	r0
      000FB6 E6               [12] 3477 	mov	a,@r0
      000FB7 C0 E0            [24] 3478 	push	acc
      000FB9 08               [12] 3479 	inc	r0
      000FBA E6               [12] 3480 	mov	a,@r0
      000FBB C0 E0            [24] 3481 	push	acc
      000FBD 08               [12] 3482 	inc	r0
      000FBE E6               [12] 3483 	mov	a,@r0
      000FBF C0 E0            [24] 3484 	push	acc
      000FC1 E5 08            [12] 3485 	mov	a,_bp
      000FC3 24 F6            [12] 3486 	add	a,#0xf6
      000FC5 F8               [12] 3487 	mov	r0,a
      000FC6 86 82            [24] 3488 	mov	dpl, @r0
      000FC8 08               [12] 3489 	inc	r0
      000FC9 86 83            [24] 3490 	mov	dph, @r0
      000FCB 08               [12] 3491 	inc	r0
      000FCC 86 F0            [24] 3492 	mov	b, @r0
      000FCE 08               [12] 3493 	inc	r0
      000FCF E6               [12] 3494 	mov	a, @r0
      000FD0 12 40 41         [24] 3495 	lcall	___fssub
      000FD3 AA 82            [24] 3496 	mov	r2, dpl
      000FD5 AB 83            [24] 3497 	mov	r3, dph
      000FD7 AE F0            [24] 3498 	mov	r6, b
      000FD9 FF               [12] 3499 	mov	r7, a
      000FDA E5 81            [12] 3500 	mov	a,sp
      000FDC 24 FC            [12] 3501 	add	a,#0xfc
      000FDE F5 81            [12] 3502 	mov	sp,a
      000FE0 C0 02            [24] 3503 	push	ar2
      000FE2 C0 03            [24] 3504 	push	ar3
      000FE4 C0 06            [24] 3505 	push	ar6
      000FE6 C0 07            [24] 3506 	push	ar7
      000FE8 E5 08            [12] 3507 	mov	a,_bp
      000FEA 24 05            [12] 3508 	add	a,#0x05
      000FEC F8               [12] 3509 	mov	r0,a
      000FED 86 82            [24] 3510 	mov	dpl, @r0
      000FEF 08               [12] 3511 	inc	r0
      000FF0 86 83            [24] 3512 	mov	dph, @r0
      000FF2 08               [12] 3513 	inc	r0
      000FF3 86 F0            [24] 3514 	mov	b, @r0
      000FF5 08               [12] 3515 	inc	r0
      000FF6 E6               [12] 3516 	mov	a, @r0
      000FF7 12 42 E5         [24] 3517 	lcall	___fsdiv
      000FFA A8 08            [24] 3518 	mov	r0,_bp
      000FFC 08               [12] 3519 	inc	r0
      000FFD A6 82            [24] 3520 	mov	@r0, dpl
      000FFF 08               [12] 3521 	inc	r0
      001000 A6 83            [24] 3522 	mov	@r0, dph
      001002 08               [12] 3523 	inc	r0
      001003 A6 F0            [24] 3524 	mov	@r0, b
      001005 08               [12] 3525 	inc	r0
      001006 F6               [12] 3526 	mov	@r0,a
      001007 E5 81            [12] 3527 	mov	a,sp
      001009 24 FC            [12] 3528 	add	a,#0xfc
      00100B F5 81            [12] 3529 	mov	sp,a
      00100D                       3530 00109$:
                           000F50  3531 	C$fuzzy.h$1691$1_0$71 ==.
                                   3532 ;	../../fuzzy.h:1691: result,
      00100D E5 08            [12] 3533 	mov	a,_bp
      00100F 24 F1            [12] 3534 	add	a,#0xf1
      001011 F8               [12] 3535 	mov	r0,a
      001012 E6               [12] 3536 	mov	a,@r0
      001013 C0 E0            [24] 3537 	push	acc
      001015 A8 08            [24] 3538 	mov	r0,_bp
      001017 08               [12] 3539 	inc	r0
      001018 86 82            [24] 3540 	mov	dpl, @r0
      00101A 08               [12] 3541 	inc	r0
      00101B 86 83            [24] 3542 	mov	dph, @r0
      00101D 08               [12] 3543 	inc	r0
      00101E 86 F0            [24] 3544 	mov	b, @r0
      001020 08               [12] 3545 	inc	r0
      001021 E6               [12] 3546 	mov	a, @r0
      001022 12 01 9F         [24] 3547 	lcall	_fuzzy_apply_hedge
      001025 AC 82            [24] 3548 	mov	r4, dpl
      001027 AD 83            [24] 3549 	mov	r5, dph
      001029 AE F0            [24] 3550 	mov	r6, b
      00102B FF               [12] 3551 	mov	r7, a
      00102C 15 81            [12] 3552 	dec	sp
      00102E 8C 82            [24] 3553 	mov	dpl, r4
      001030 8D 83            [24] 3554 	mov	dph, r5
      001032 8E F0            [24] 3555 	mov	b, r6
      001034 EF               [12] 3556 	mov	a, r7
                           000F78  3557 	C$fuzzy.h$1694$1_0$71 ==.
                                   3558 ;	../../fuzzy.h:1694: }
      001035 85 08 81         [24] 3559 	mov	sp,_bp
      001038 D0 08            [24] 3560 	pop	_bp
                           000F7D  3561 	C$fuzzy.h$1694$1_0$71 ==.
                           000F7D  3562 	XG$fuzzy_triangle$0$0 ==.
      00103A 22               [24] 3563 	ret
                                   3564 ;------------------------------------------------------------
                                   3565 ;Allocation info for local variables in function 'fuzzy_trapezoid'
                                   3566 ;------------------------------------------------------------
                                   3567 ;b             Allocated to stack - _bp -6 +4 
                                   3568 ;c             Allocated to stack - _bp -10 +4 
                                   3569 ;d             Allocated to stack - _bp -14 +4 
                                   3570 ;value         Allocated to stack - _bp -18 +4 
                                   3571 ;hedge         Allocated to stack - _bp -19 +1 
                                   3572 ;a             Allocated to registers r7 r6 r5 r4 
                                   3573 ;result        Allocated to stack - _bp +1 +4 
                                   3574 ;sloc0         Allocated to stack - _bp +1 +4 
                                   3575 ;sloc1         Allocated to stack - _bp +5 +4 
                                   3576 ;------------------------------------------------------------
                           000F7E  3577 	G$fuzzy_trapezoid$0$0 ==.
                           000F7E  3578 	C$fuzzy.h$1696$1_0$77 ==.
                                   3579 ;	../../fuzzy.h:1696: float fuzzy_trapezoid(
                                   3580 ;	-----------------------------------------
                                   3581 ;	 function fuzzy_trapezoid
                                   3582 ;	-----------------------------------------
      00103B                       3583 _fuzzy_trapezoid:
      00103B C0 08            [24] 3584 	push	_bp
      00103D 85 81 08         [24] 3585 	mov	_bp,sp
      001040 AF 82            [24] 3586 	mov	r7,dpl
      001042 AE 83            [24] 3587 	mov	r6,dph
      001044 AD F0            [24] 3588 	mov	r5,b
      001046 FC               [12] 3589 	mov	r4,a
      001047 E5 81            [12] 3590 	mov	a,sp
      001049 24 08            [12] 3591 	add	a,#0x08
      00104B F5 81            [12] 3592 	mov	sp,a
                           000F90  3593 	C$fuzzy.h$1708$1_0$77 ==.
                                   3594 ;	../../fuzzy.h:1708: a >= b ||
      00104D C0 07            [24] 3595 	push	ar7
      00104F C0 06            [24] 3596 	push	ar6
      001051 C0 05            [24] 3597 	push	ar5
      001053 C0 04            [24] 3598 	push	ar4
      001055 E5 08            [12] 3599 	mov	a,_bp
      001057 24 FA            [12] 3600 	add	a,#0xfa
      001059 F8               [12] 3601 	mov	r0,a
      00105A E6               [12] 3602 	mov	a,@r0
      00105B C0 E0            [24] 3603 	push	acc
      00105D 08               [12] 3604 	inc	r0
      00105E E6               [12] 3605 	mov	a,@r0
      00105F C0 E0            [24] 3606 	push	acc
      001061 08               [12] 3607 	inc	r0
      001062 E6               [12] 3608 	mov	a,@r0
      001063 C0 E0            [24] 3609 	push	acc
      001065 08               [12] 3610 	inc	r0
      001066 E6               [12] 3611 	mov	a,@r0
      001067 C0 E0            [24] 3612 	push	acc
      001069 8F 82            [24] 3613 	mov	dpl, r7
      00106B 8E 83            [24] 3614 	mov	dph, r6
      00106D 8D F0            [24] 3615 	mov	b, r5
      00106F EC               [12] 3616 	mov	a, r4
      001070 12 41 7C         [24] 3617 	lcall	___fslt
      001073 E5 81            [12] 3618 	mov	a,sp
      001075 24 FC            [12] 3619 	add	a,#0xfc
      001077 F5 81            [12] 3620 	mov	sp,a
      001079 D0 04            [24] 3621 	pop	ar4
      00107B D0 05            [24] 3622 	pop	ar5
      00107D D0 06            [24] 3623 	pop	ar6
      00107F D0 07            [24] 3624 	pop	ar7
      001081 E5 82            [12] 3625 	mov	a, dpl
      001083 24 FF            [12] 3626 	add	a,#0xff
      001085 92 00            [24] 3627 	mov	b0,c
      001087 40 03            [24] 3628 	jc	00159$
      001089 02 11 97         [24] 3629 	ljmp	00108$
      00108C                       3630 00159$:
                           000FCF  3631 	C$fuzzy.h$1709$1_0$77 ==.
                                   3632 ;	../../fuzzy.h:1709: b > c ||
      00108C C0 07            [24] 3633 	push	ar7
      00108E C0 06            [24] 3634 	push	ar6
      001090 C0 05            [24] 3635 	push	ar5
      001092 C0 04            [24] 3636 	push	ar4
      001094 E5 08            [12] 3637 	mov	a,_bp
      001096 24 FA            [12] 3638 	add	a,#0xfa
      001098 F8               [12] 3639 	mov	r0,a
      001099 E6               [12] 3640 	mov	a,@r0
      00109A C0 E0            [24] 3641 	push	acc
      00109C 08               [12] 3642 	inc	r0
      00109D E6               [12] 3643 	mov	a,@r0
      00109E C0 E0            [24] 3644 	push	acc
      0010A0 08               [12] 3645 	inc	r0
      0010A1 E6               [12] 3646 	mov	a,@r0
      0010A2 C0 E0            [24] 3647 	push	acc
      0010A4 08               [12] 3648 	inc	r0
      0010A5 E6               [12] 3649 	mov	a,@r0
      0010A6 C0 E0            [24] 3650 	push	acc
      0010A8 E5 08            [12] 3651 	mov	a,_bp
      0010AA 24 F6            [12] 3652 	add	a,#0xf6
      0010AC F8               [12] 3653 	mov	r0,a
      0010AD 86 82            [24] 3654 	mov	dpl, @r0
      0010AF 08               [12] 3655 	inc	r0
      0010B0 86 83            [24] 3656 	mov	dph, @r0
      0010B2 08               [12] 3657 	inc	r0
      0010B3 86 F0            [24] 3658 	mov	b, @r0
      0010B5 08               [12] 3659 	inc	r0
      0010B6 E6               [12] 3660 	mov	a, @r0
      0010B7 12 41 7C         [24] 3661 	lcall	___fslt
      0010BA AB 82            [24] 3662 	mov	r3, dpl
      0010BC E5 81            [12] 3663 	mov	a,sp
      0010BE 24 FC            [12] 3664 	add	a,#0xfc
      0010C0 F5 81            [12] 3665 	mov	sp,a
      0010C2 D0 04            [24] 3666 	pop	ar4
      0010C4 D0 05            [24] 3667 	pop	ar5
      0010C6 D0 06            [24] 3668 	pop	ar6
      0010C8 D0 07            [24] 3669 	pop	ar7
      0010CA EB               [12] 3670 	mov	a,r3
      0010CB 60 03            [24] 3671 	jz	00160$
      0010CD 02 11 97         [24] 3672 	ljmp	00108$
      0010D0                       3673 00160$:
                           001013  3674 	C$fuzzy.h$1710$1_0$77 ==.
                                   3675 ;	../../fuzzy.h:1710: c >= d ||
      0010D0 C0 07            [24] 3676 	push	ar7
      0010D2 C0 06            [24] 3677 	push	ar6
      0010D4 C0 05            [24] 3678 	push	ar5
      0010D6 C0 04            [24] 3679 	push	ar4
      0010D8 E5 08            [12] 3680 	mov	a,_bp
      0010DA 24 F2            [12] 3681 	add	a,#0xf2
      0010DC F8               [12] 3682 	mov	r0,a
      0010DD E6               [12] 3683 	mov	a,@r0
      0010DE C0 E0            [24] 3684 	push	acc
      0010E0 08               [12] 3685 	inc	r0
      0010E1 E6               [12] 3686 	mov	a,@r0
      0010E2 C0 E0            [24] 3687 	push	acc
      0010E4 08               [12] 3688 	inc	r0
      0010E5 E6               [12] 3689 	mov	a,@r0
      0010E6 C0 E0            [24] 3690 	push	acc
      0010E8 08               [12] 3691 	inc	r0
      0010E9 E6               [12] 3692 	mov	a,@r0
      0010EA C0 E0            [24] 3693 	push	acc
      0010EC E5 08            [12] 3694 	mov	a,_bp
      0010EE 24 F6            [12] 3695 	add	a,#0xf6
      0010F0 F8               [12] 3696 	mov	r0,a
      0010F1 86 82            [24] 3697 	mov	dpl, @r0
      0010F3 08               [12] 3698 	inc	r0
      0010F4 86 83            [24] 3699 	mov	dph, @r0
      0010F6 08               [12] 3700 	inc	r0
      0010F7 86 F0            [24] 3701 	mov	b, @r0
      0010F9 08               [12] 3702 	inc	r0
      0010FA E6               [12] 3703 	mov	a, @r0
      0010FB 12 41 7C         [24] 3704 	lcall	___fslt
      0010FE E5 81            [12] 3705 	mov	a,sp
      001100 24 FC            [12] 3706 	add	a,#0xfc
      001102 F5 81            [12] 3707 	mov	sp,a
      001104 D0 04            [24] 3708 	pop	ar4
      001106 D0 05            [24] 3709 	pop	ar5
      001108 D0 06            [24] 3710 	pop	ar6
      00110A D0 07            [24] 3711 	pop	ar7
      00110C E5 82            [12] 3712 	mov	a, dpl
      00110E 24 FF            [12] 3713 	add	a,#0xff
      001110 92 00            [24] 3714 	mov	b0,c
      001112 40 03            [24] 3715 	jc	00161$
      001114 02 11 97         [24] 3716 	ljmp	00108$
      001117                       3717 00161$:
                           00105A  3718 	C$fuzzy.h$1711$1_0$77 ==.
                                   3719 ;	../../fuzzy.h:1711: value <= a ||
      001117 C0 07            [24] 3720 	push	ar7
      001119 C0 06            [24] 3721 	push	ar6
      00111B C0 05            [24] 3722 	push	ar5
      00111D C0 04            [24] 3723 	push	ar4
      00111F E5 08            [12] 3724 	mov	a,_bp
      001121 24 EE            [12] 3725 	add	a,#0xee
      001123 F8               [12] 3726 	mov	r0,a
      001124 E6               [12] 3727 	mov	a,@r0
      001125 C0 E0            [24] 3728 	push	acc
      001127 08               [12] 3729 	inc	r0
      001128 E6               [12] 3730 	mov	a,@r0
      001129 C0 E0            [24] 3731 	push	acc
      00112B 08               [12] 3732 	inc	r0
      00112C E6               [12] 3733 	mov	a,@r0
      00112D C0 E0            [24] 3734 	push	acc
      00112F 08               [12] 3735 	inc	r0
      001130 E6               [12] 3736 	mov	a,@r0
      001131 C0 E0            [24] 3737 	push	acc
      001133 8F 82            [24] 3738 	mov	dpl, r7
      001135 8E 83            [24] 3739 	mov	dph, r6
      001137 8D F0            [24] 3740 	mov	b, r5
      001139 EC               [12] 3741 	mov	a, r4
      00113A 12 41 7C         [24] 3742 	lcall	___fslt
      00113D E5 81            [12] 3743 	mov	a,sp
      00113F 24 FC            [12] 3744 	add	a,#0xfc
      001141 F5 81            [12] 3745 	mov	sp,a
      001143 D0 04            [24] 3746 	pop	ar4
      001145 D0 05            [24] 3747 	pop	ar5
      001147 D0 06            [24] 3748 	pop	ar6
      001149 D0 07            [24] 3749 	pop	ar7
      00114B E5 82            [12] 3750 	mov	a, dpl
      00114D 24 FF            [12] 3751 	add	a,#0xff
      00114F 92 00            [24] 3752 	mov	b0,c
      001151 50 44            [24] 3753 	jnc	00108$
                           001096  3754 	C$fuzzy.h$1713$1_0$77 ==.
                                   3755 ;	../../fuzzy.h:1713: ) {
      001153 C0 07            [24] 3756 	push	ar7
      001155 C0 06            [24] 3757 	push	ar6
      001157 C0 05            [24] 3758 	push	ar5
      001159 C0 04            [24] 3759 	push	ar4
      00115B E5 08            [12] 3760 	mov	a,_bp
      00115D 24 F2            [12] 3761 	add	a,#0xf2
      00115F F8               [12] 3762 	mov	r0,a
      001160 E6               [12] 3763 	mov	a,@r0
      001161 C0 E0            [24] 3764 	push	acc
      001163 08               [12] 3765 	inc	r0
      001164 E6               [12] 3766 	mov	a,@r0
      001165 C0 E0            [24] 3767 	push	acc
      001167 08               [12] 3768 	inc	r0
      001168 E6               [12] 3769 	mov	a,@r0
      001169 C0 E0            [24] 3770 	push	acc
      00116B 08               [12] 3771 	inc	r0
      00116C E6               [12] 3772 	mov	a,@r0
      00116D C0 E0            [24] 3773 	push	acc
      00116F E5 08            [12] 3774 	mov	a,_bp
      001171 24 EE            [12] 3775 	add	a,#0xee
      001173 F8               [12] 3776 	mov	r0,a
      001174 86 82            [24] 3777 	mov	dpl, @r0
      001176 08               [12] 3778 	inc	r0
      001177 86 83            [24] 3779 	mov	dph, @r0
      001179 08               [12] 3780 	inc	r0
      00117A 86 F0            [24] 3781 	mov	b, @r0
      00117C 08               [12] 3782 	inc	r0
      00117D E6               [12] 3783 	mov	a, @r0
      00117E 12 41 7C         [24] 3784 	lcall	___fslt
      001181 E5 81            [12] 3785 	mov	a,sp
      001183 24 FC            [12] 3786 	add	a,#0xfc
      001185 F5 81            [12] 3787 	mov	sp,a
      001187 D0 04            [24] 3788 	pop	ar4
      001189 D0 05            [24] 3789 	pop	ar5
      00118B D0 06            [24] 3790 	pop	ar6
      00118D D0 07            [24] 3791 	pop	ar7
      00118F E5 82            [12] 3792 	mov	a, dpl
      001191 24 FF            [12] 3793 	add	a,#0xff
      001193 92 00            [24] 3794 	mov	b0,c
      001195 40 0E            [24] 3795 	jc	00109$
      001197                       3796 00108$:
                           0010DA  3797 	C$fuzzy.h$1714$2_0$78 ==.
                                   3798 ;	../../fuzzy.h:1714: result = LEVEL_LO;
      001197 A8 08            [24] 3799 	mov	r0,_bp
      001199 08               [12] 3800 	inc	r0
      00119A E4               [12] 3801 	clr	a
      00119B F6               [12] 3802 	mov	@r0,a
      00119C 08               [12] 3803 	inc	r0
      00119D F6               [12] 3804 	mov	@r0,a
      00119E 08               [12] 3805 	inc	r0
      00119F F6               [12] 3806 	mov	@r0,a
      0011A0 08               [12] 3807 	inc	r0
      0011A1 F6               [12] 3808 	mov	@r0,a
      0011A2 02 13 A4         [24] 3809 	ljmp	00110$
      0011A5                       3810 00109$:
                           0010E8  3811 	C$fuzzy.h$1717$1_0$77 ==.
                                   3812 ;	../../fuzzy.h:1717: value >= b &&
      0011A5 C0 07            [24] 3813 	push	ar7
      0011A7 C0 06            [24] 3814 	push	ar6
      0011A9 C0 05            [24] 3815 	push	ar5
      0011AB C0 04            [24] 3816 	push	ar4
      0011AD E5 08            [12] 3817 	mov	a,_bp
      0011AF 24 FA            [12] 3818 	add	a,#0xfa
      0011B1 F8               [12] 3819 	mov	r0,a
      0011B2 E6               [12] 3820 	mov	a,@r0
      0011B3 C0 E0            [24] 3821 	push	acc
      0011B5 08               [12] 3822 	inc	r0
      0011B6 E6               [12] 3823 	mov	a,@r0
      0011B7 C0 E0            [24] 3824 	push	acc
      0011B9 08               [12] 3825 	inc	r0
      0011BA E6               [12] 3826 	mov	a,@r0
      0011BB C0 E0            [24] 3827 	push	acc
      0011BD 08               [12] 3828 	inc	r0
      0011BE E6               [12] 3829 	mov	a,@r0
      0011BF C0 E0            [24] 3830 	push	acc
      0011C1 E5 08            [12] 3831 	mov	a,_bp
      0011C3 24 EE            [12] 3832 	add	a,#0xee
      0011C5 F8               [12] 3833 	mov	r0,a
      0011C6 86 82            [24] 3834 	mov	dpl, @r0
      0011C8 08               [12] 3835 	inc	r0
      0011C9 86 83            [24] 3836 	mov	dph, @r0
      0011CB 08               [12] 3837 	inc	r0
      0011CC 86 F0            [24] 3838 	mov	b, @r0
      0011CE 08               [12] 3839 	inc	r0
      0011CF E6               [12] 3840 	mov	a, @r0
      0011D0 12 41 7C         [24] 3841 	lcall	___fslt
      0011D3 E5 81            [12] 3842 	mov	a,sp
      0011D5 24 FC            [12] 3843 	add	a,#0xfc
      0011D7 F5 81            [12] 3844 	mov	sp,a
      0011D9 D0 04            [24] 3845 	pop	ar4
      0011DB D0 05            [24] 3846 	pop	ar5
      0011DD D0 06            [24] 3847 	pop	ar6
      0011DF D0 07            [24] 3848 	pop	ar7
      0011E1 E5 82            [12] 3849 	mov	a, dpl
      0011E3 24 FF            [12] 3850 	add	a,#0xff
      0011E5 92 00            [24] 3851 	mov	b0,c
      0011E7 40 54            [24] 3852 	jc	00105$
                           00112C  3853 	C$fuzzy.h$1719$1_0$77 ==.
                                   3854 ;	../../fuzzy.h:1719: ) {
      0011E9 C0 07            [24] 3855 	push	ar7
      0011EB C0 06            [24] 3856 	push	ar6
      0011ED C0 05            [24] 3857 	push	ar5
      0011EF C0 04            [24] 3858 	push	ar4
      0011F1 E5 08            [12] 3859 	mov	a,_bp
      0011F3 24 EE            [12] 3860 	add	a,#0xee
      0011F5 F8               [12] 3861 	mov	r0,a
      0011F6 E6               [12] 3862 	mov	a,@r0
      0011F7 C0 E0            [24] 3863 	push	acc
      0011F9 08               [12] 3864 	inc	r0
      0011FA E6               [12] 3865 	mov	a,@r0
      0011FB C0 E0            [24] 3866 	push	acc
      0011FD 08               [12] 3867 	inc	r0
      0011FE E6               [12] 3868 	mov	a,@r0
      0011FF C0 E0            [24] 3869 	push	acc
      001201 08               [12] 3870 	inc	r0
      001202 E6               [12] 3871 	mov	a,@r0
      001203 C0 E0            [24] 3872 	push	acc
      001205 E5 08            [12] 3873 	mov	a,_bp
      001207 24 F6            [12] 3874 	add	a,#0xf6
      001209 F8               [12] 3875 	mov	r0,a
      00120A 86 82            [24] 3876 	mov	dpl, @r0
      00120C 08               [12] 3877 	inc	r0
      00120D 86 83            [24] 3878 	mov	dph, @r0
      00120F 08               [12] 3879 	inc	r0
      001210 86 F0            [24] 3880 	mov	b, @r0
      001212 08               [12] 3881 	inc	r0
      001213 E6               [12] 3882 	mov	a, @r0
      001214 12 41 7C         [24] 3883 	lcall	___fslt
      001217 E5 81            [12] 3884 	mov	a,sp
      001219 24 FC            [12] 3885 	add	a,#0xfc
      00121B F5 81            [12] 3886 	mov	sp,a
      00121D D0 04            [24] 3887 	pop	ar4
      00121F D0 05            [24] 3888 	pop	ar5
      001221 D0 06            [24] 3889 	pop	ar6
      001223 D0 07            [24] 3890 	pop	ar7
      001225 E5 82            [12] 3891 	mov	a, dpl
      001227 24 FF            [12] 3892 	add	a,#0xff
      001229 92 00            [24] 3893 	mov	b0,c
      00122B 40 10            [24] 3894 	jc	00105$
                           001170  3895 	C$fuzzy.h$1720$2_0$79 ==.
                                   3896 ;	../../fuzzy.h:1720: result = LEVEL_HI;
      00122D A8 08            [24] 3897 	mov	r0,_bp
      00122F 08               [12] 3898 	inc	r0
      001230 E4               [12] 3899 	clr	a
      001231 F6               [12] 3900 	mov	@r0,a
      001232 08               [12] 3901 	inc	r0
      001233 F6               [12] 3902 	mov	@r0,a
      001234 08               [12] 3903 	inc	r0
      001235 76 80            [12] 3904 	mov	@r0,#0x80
      001237 08               [12] 3905 	inc	r0
      001238 76 3F            [12] 3906 	mov	@r0,#0x3f
      00123A 02 13 A4         [24] 3907 	ljmp	00110$
      00123D                       3908 00105$:
                           001180  3909 	C$fuzzy.h$1722$1_0$77 ==.
                                   3910 ;	../../fuzzy.h:1722: else if (value < b) {
      00123D C0 07            [24] 3911 	push	ar7
      00123F C0 06            [24] 3912 	push	ar6
      001241 C0 05            [24] 3913 	push	ar5
      001243 C0 04            [24] 3914 	push	ar4
      001245 E5 08            [12] 3915 	mov	a,_bp
      001247 24 FA            [12] 3916 	add	a,#0xfa
      001249 F8               [12] 3917 	mov	r0,a
      00124A E6               [12] 3918 	mov	a,@r0
      00124B C0 E0            [24] 3919 	push	acc
      00124D 08               [12] 3920 	inc	r0
      00124E E6               [12] 3921 	mov	a,@r0
      00124F C0 E0            [24] 3922 	push	acc
      001251 08               [12] 3923 	inc	r0
      001252 E6               [12] 3924 	mov	a,@r0
      001253 C0 E0            [24] 3925 	push	acc
      001255 08               [12] 3926 	inc	r0
      001256 E6               [12] 3927 	mov	a,@r0
      001257 C0 E0            [24] 3928 	push	acc
      001259 E5 08            [12] 3929 	mov	a,_bp
      00125B 24 EE            [12] 3930 	add	a,#0xee
      00125D F8               [12] 3931 	mov	r0,a
      00125E 86 82            [24] 3932 	mov	dpl, @r0
      001260 08               [12] 3933 	inc	r0
      001261 86 83            [24] 3934 	mov	dph, @r0
      001263 08               [12] 3935 	inc	r0
      001264 86 F0            [24] 3936 	mov	b, @r0
      001266 08               [12] 3937 	inc	r0
      001267 E6               [12] 3938 	mov	a, @r0
      001268 12 41 7C         [24] 3939 	lcall	___fslt
      00126B AB 82            [24] 3940 	mov	r3, dpl
      00126D E5 81            [12] 3941 	mov	a,sp
      00126F 24 FC            [12] 3942 	add	a,#0xfc
      001271 F5 81            [12] 3943 	mov	sp,a
      001273 D0 04            [24] 3944 	pop	ar4
      001275 D0 05            [24] 3945 	pop	ar5
      001277 D0 06            [24] 3946 	pop	ar6
      001279 D0 07            [24] 3947 	pop	ar7
      00127B EB               [12] 3948 	mov	a,r3
      00127C 70 03            [24] 3949 	jnz	00166$
      00127E 02 13 08         [24] 3950 	ljmp	00102$
      001281                       3951 00166$:
                           0011C4  3952 	C$fuzzy.h$1724$1_0$77 ==.
                                   3953 ;	../../fuzzy.h:1724: (value - a) /
      001281 C0 07            [24] 3954 	push	ar7
      001283 C0 06            [24] 3955 	push	ar6
      001285 C0 05            [24] 3956 	push	ar5
      001287 C0 04            [24] 3957 	push	ar4
      001289 C0 07            [24] 3958 	push	ar7
      00128B C0 06            [24] 3959 	push	ar6
      00128D C0 05            [24] 3960 	push	ar5
      00128F C0 04            [24] 3961 	push	ar4
                           0011D4  3962 	C$fuzzy.h$1725$1_0$77 ==.
                                   3963 ;	../../fuzzy.h:1725: (b - a);
      001291 E5 08            [12] 3964 	mov	a,_bp
      001293 24 EE            [12] 3965 	add	a,#0xee
      001295 F8               [12] 3966 	mov	r0,a
      001296 86 82            [24] 3967 	mov	dpl, @r0
      001298 08               [12] 3968 	inc	r0
      001299 86 83            [24] 3969 	mov	dph, @r0
      00129B 08               [12] 3970 	inc	r0
      00129C 86 F0            [24] 3971 	mov	b, @r0
      00129E 08               [12] 3972 	inc	r0
      00129F E6               [12] 3973 	mov	a, @r0
      0012A0 12 40 41         [24] 3974 	lcall	___fssub
      0012A3 C8               [12] 3975 	xch	a,r0
      0012A4 E5 08            [12] 3976 	mov	a,_bp
      0012A6 24 05            [12] 3977 	add	a,#0x05
      0012A8 C8               [12] 3978 	xch	a,r0
      0012A9 A6 82            [24] 3979 	mov	@r0, dpl
      0012AB 08               [12] 3980 	inc	r0
      0012AC A6 83            [24] 3981 	mov	@r0, dph
      0012AE 08               [12] 3982 	inc	r0
      0012AF A6 F0            [24] 3983 	mov	@r0, b
      0012B1 08               [12] 3984 	inc	r0
      0012B2 F6               [12] 3985 	mov	@r0,a
      0012B3 E5 81            [12] 3986 	mov	a,sp
      0012B5 24 FC            [12] 3987 	add	a,#0xfc
      0012B7 F5 81            [12] 3988 	mov	sp,a
      0012B9 E5 08            [12] 3989 	mov	a,_bp
      0012BB 24 FA            [12] 3990 	add	a,#0xfa
      0012BD F8               [12] 3991 	mov	r0,a
      0012BE 86 82            [24] 3992 	mov	dpl, @r0
      0012C0 08               [12] 3993 	inc	r0
      0012C1 86 83            [24] 3994 	mov	dph, @r0
      0012C3 08               [12] 3995 	inc	r0
      0012C4 86 F0            [24] 3996 	mov	b, @r0
      0012C6 08               [12] 3997 	inc	r0
      0012C7 E6               [12] 3998 	mov	a, @r0
      0012C8 12 40 41         [24] 3999 	lcall	___fssub
      0012CB AC 82            [24] 4000 	mov	r4, dpl
      0012CD AD 83            [24] 4001 	mov	r5, dph
      0012CF AE F0            [24] 4002 	mov	r6, b
      0012D1 FF               [12] 4003 	mov	r7, a
      0012D2 E5 81            [12] 4004 	mov	a,sp
      0012D4 24 FC            [12] 4005 	add	a,#0xfc
      0012D6 F5 81            [12] 4006 	mov	sp,a
      0012D8 C0 04            [24] 4007 	push	ar4
      0012DA C0 05            [24] 4008 	push	ar5
      0012DC C0 06            [24] 4009 	push	ar6
      0012DE C0 07            [24] 4010 	push	ar7
      0012E0 E5 08            [12] 4011 	mov	a,_bp
      0012E2 24 05            [12] 4012 	add	a,#0x05
      0012E4 F8               [12] 4013 	mov	r0,a
      0012E5 86 82            [24] 4014 	mov	dpl, @r0
      0012E7 08               [12] 4015 	inc	r0
      0012E8 86 83            [24] 4016 	mov	dph, @r0
      0012EA 08               [12] 4017 	inc	r0
      0012EB 86 F0            [24] 4018 	mov	b, @r0
      0012ED 08               [12] 4019 	inc	r0
      0012EE E6               [12] 4020 	mov	a, @r0
      0012EF 12 42 E5         [24] 4021 	lcall	___fsdiv
      0012F2 A8 08            [24] 4022 	mov	r0,_bp
      0012F4 08               [12] 4023 	inc	r0
      0012F5 A6 82            [24] 4024 	mov	@r0, dpl
      0012F7 08               [12] 4025 	inc	r0
      0012F8 A6 83            [24] 4026 	mov	@r0, dph
      0012FA 08               [12] 4027 	inc	r0
      0012FB A6 F0            [24] 4028 	mov	@r0, b
      0012FD 08               [12] 4029 	inc	r0
      0012FE F6               [12] 4030 	mov	@r0,a
      0012FF E5 81            [12] 4031 	mov	a,sp
      001301 24 FC            [12] 4032 	add	a,#0xfc
      001303 F5 81            [12] 4033 	mov	sp,a
      001305 02 13 A4         [24] 4034 	ljmp	00110$
      001308                       4035 00102$:
                           00124B  4036 	C$fuzzy.h$1729$1_0$77 ==.
                                   4037 ;	../../fuzzy.h:1729: (d - value) /
      001308 E5 08            [12] 4038 	mov	a,_bp
      00130A 24 EE            [12] 4039 	add	a,#0xee
      00130C F8               [12] 4040 	mov	r0,a
      00130D E6               [12] 4041 	mov	a,@r0
      00130E C0 E0            [24] 4042 	push	acc
      001310 08               [12] 4043 	inc	r0
      001311 E6               [12] 4044 	mov	a,@r0
      001312 C0 E0            [24] 4045 	push	acc
      001314 08               [12] 4046 	inc	r0
      001315 E6               [12] 4047 	mov	a,@r0
      001316 C0 E0            [24] 4048 	push	acc
      001318 08               [12] 4049 	inc	r0
      001319 E6               [12] 4050 	mov	a,@r0
      00131A C0 E0            [24] 4051 	push	acc
                           00125F  4052 	C$fuzzy.h$1730$1_0$77 ==.
                                   4053 ;	../../fuzzy.h:1730: (d - c);
      00131C E5 08            [12] 4054 	mov	a,_bp
      00131E 24 F2            [12] 4055 	add	a,#0xf2
      001320 F8               [12] 4056 	mov	r0,a
      001321 86 82            [24] 4057 	mov	dpl, @r0
      001323 08               [12] 4058 	inc	r0
      001324 86 83            [24] 4059 	mov	dph, @r0
      001326 08               [12] 4060 	inc	r0
      001327 86 F0            [24] 4061 	mov	b, @r0
      001329 08               [12] 4062 	inc	r0
      00132A E6               [12] 4063 	mov	a, @r0
      00132B 12 40 41         [24] 4064 	lcall	___fssub
      00132E C8               [12] 4065 	xch	a,r0
      00132F E5 08            [12] 4066 	mov	a,_bp
      001331 24 05            [12] 4067 	add	a,#0x05
      001333 C8               [12] 4068 	xch	a,r0
      001334 A6 82            [24] 4069 	mov	@r0, dpl
      001336 08               [12] 4070 	inc	r0
      001337 A6 83            [24] 4071 	mov	@r0, dph
      001339 08               [12] 4072 	inc	r0
      00133A A6 F0            [24] 4073 	mov	@r0, b
      00133C 08               [12] 4074 	inc	r0
      00133D F6               [12] 4075 	mov	@r0,a
      00133E E5 81            [12] 4076 	mov	a,sp
      001340 24 FC            [12] 4077 	add	a,#0xfc
      001342 F5 81            [12] 4078 	mov	sp,a
      001344 E5 08            [12] 4079 	mov	a,_bp
      001346 24 F6            [12] 4080 	add	a,#0xf6
      001348 F8               [12] 4081 	mov	r0,a
      001349 E6               [12] 4082 	mov	a,@r0
      00134A C0 E0            [24] 4083 	push	acc
      00134C 08               [12] 4084 	inc	r0
      00134D E6               [12] 4085 	mov	a,@r0
      00134E C0 E0            [24] 4086 	push	acc
      001350 08               [12] 4087 	inc	r0
      001351 E6               [12] 4088 	mov	a,@r0
      001352 C0 E0            [24] 4089 	push	acc
      001354 08               [12] 4090 	inc	r0
      001355 E6               [12] 4091 	mov	a,@r0
      001356 C0 E0            [24] 4092 	push	acc
      001358 E5 08            [12] 4093 	mov	a,_bp
      00135A 24 F2            [12] 4094 	add	a,#0xf2
      00135C F8               [12] 4095 	mov	r0,a
      00135D 86 82            [24] 4096 	mov	dpl, @r0
      00135F 08               [12] 4097 	inc	r0
      001360 86 83            [24] 4098 	mov	dph, @r0
      001362 08               [12] 4099 	inc	r0
      001363 86 F0            [24] 4100 	mov	b, @r0
      001365 08               [12] 4101 	inc	r0
      001366 E6               [12] 4102 	mov	a, @r0
      001367 12 40 41         [24] 4103 	lcall	___fssub
      00136A AA 82            [24] 4104 	mov	r2, dpl
      00136C AB 83            [24] 4105 	mov	r3, dph
      00136E AE F0            [24] 4106 	mov	r6, b
      001370 FF               [12] 4107 	mov	r7, a
      001371 E5 81            [12] 4108 	mov	a,sp
      001373 24 FC            [12] 4109 	add	a,#0xfc
      001375 F5 81            [12] 4110 	mov	sp,a
      001377 C0 02            [24] 4111 	push	ar2
      001379 C0 03            [24] 4112 	push	ar3
      00137B C0 06            [24] 4113 	push	ar6
      00137D C0 07            [24] 4114 	push	ar7
      00137F E5 08            [12] 4115 	mov	a,_bp
      001381 24 05            [12] 4116 	add	a,#0x05
      001383 F8               [12] 4117 	mov	r0,a
      001384 86 82            [24] 4118 	mov	dpl, @r0
      001386 08               [12] 4119 	inc	r0
      001387 86 83            [24] 4120 	mov	dph, @r0
      001389 08               [12] 4121 	inc	r0
      00138A 86 F0            [24] 4122 	mov	b, @r0
      00138C 08               [12] 4123 	inc	r0
      00138D E6               [12] 4124 	mov	a, @r0
      00138E 12 42 E5         [24] 4125 	lcall	___fsdiv
      001391 A8 08            [24] 4126 	mov	r0,_bp
      001393 08               [12] 4127 	inc	r0
      001394 A6 82            [24] 4128 	mov	@r0, dpl
      001396 08               [12] 4129 	inc	r0
      001397 A6 83            [24] 4130 	mov	@r0, dph
      001399 08               [12] 4131 	inc	r0
      00139A A6 F0            [24] 4132 	mov	@r0, b
      00139C 08               [12] 4133 	inc	r0
      00139D F6               [12] 4134 	mov	@r0,a
      00139E E5 81            [12] 4135 	mov	a,sp
      0013A0 24 FC            [12] 4136 	add	a,#0xfc
      0013A2 F5 81            [12] 4137 	mov	sp,a
      0013A4                       4138 00110$:
                           0012E7  4139 	C$fuzzy.h$1734$1_0$77 ==.
                                   4140 ;	../../fuzzy.h:1734: result,
      0013A4 E5 08            [12] 4141 	mov	a,_bp
      0013A6 24 ED            [12] 4142 	add	a,#0xed
      0013A8 F8               [12] 4143 	mov	r0,a
      0013A9 E6               [12] 4144 	mov	a,@r0
      0013AA C0 E0            [24] 4145 	push	acc
      0013AC A8 08            [24] 4146 	mov	r0,_bp
      0013AE 08               [12] 4147 	inc	r0
      0013AF 86 82            [24] 4148 	mov	dpl, @r0
      0013B1 08               [12] 4149 	inc	r0
      0013B2 86 83            [24] 4150 	mov	dph, @r0
      0013B4 08               [12] 4151 	inc	r0
      0013B5 86 F0            [24] 4152 	mov	b, @r0
      0013B7 08               [12] 4153 	inc	r0
      0013B8 E6               [12] 4154 	mov	a, @r0
      0013B9 12 01 9F         [24] 4155 	lcall	_fuzzy_apply_hedge
      0013BC AC 82            [24] 4156 	mov	r4, dpl
      0013BE AD 83            [24] 4157 	mov	r5, dph
      0013C0 AE F0            [24] 4158 	mov	r6, b
      0013C2 FF               [12] 4159 	mov	r7, a
      0013C3 15 81            [12] 4160 	dec	sp
      0013C5 8C 82            [24] 4161 	mov	dpl, r4
      0013C7 8D 83            [24] 4162 	mov	dph, r5
      0013C9 8E F0            [24] 4163 	mov	b, r6
      0013CB EF               [12] 4164 	mov	a, r7
                           00130F  4165 	C$fuzzy.h$1737$1_0$77 ==.
                                   4166 ;	../../fuzzy.h:1737: }
      0013CC 85 08 81         [24] 4167 	mov	sp,_bp
      0013CF D0 08            [24] 4168 	pop	_bp
                           001314  4169 	C$fuzzy.h$1737$1_0$77 ==.
                           001314  4170 	XG$fuzzy_trapezoid$0$0 ==.
      0013D1 22               [24] 4171 	ret
                                   4172 ;------------------------------------------------------------
                                   4173 ;Allocation info for local variables in function 'fuzzy_function_array'
                                   4174 ;------------------------------------------------------------
                                   4175 ;value         Allocated to stack - _bp -6 +4 
                                   4176 ;hedge         Allocated to stack - _bp -7 +1 
                                   4177 ;parameter_count Allocated to stack - _bp -9 +2 
                                   4178 ;parameters    Allocated to stack - _bp -12 +3 
                                   4179 ;shape         Allocated to registers r7 
                                   4180 ;sloc0         Allocated to stack - _bp +2 +1 
                                   4181 ;sloc1         Allocated to stack - _bp +1 +4 
                                   4182 ;sloc2         Allocated to stack - _bp +5 +4 
                                   4183 ;sloc3         Allocated to stack - _bp +9 +4 
                                   4184 ;------------------------------------------------------------
                           001315  4185 	G$fuzzy_function_array$0$0 ==.
                           001315  4186 	C$fuzzy.h$2194$1_0$83 ==.
                                   4187 ;	../../fuzzy.h:2194: float fuzzy_function_array(
                                   4188 ;	-----------------------------------------
                                   4189 ;	 function fuzzy_function_array
                                   4190 ;	-----------------------------------------
      0013D2                       4191 _fuzzy_function_array:
      0013D2 C0 08            [24] 4192 	push	_bp
      0013D4 E5 81            [12] 4193 	mov	a,sp
      0013D6 F5 08            [12] 4194 	mov	_bp,a
      0013D8 24 0C            [12] 4195 	add	a,#0x0c
      0013DA F5 81            [12] 4196 	mov	sp,a
      0013DC AF 82            [24] 4197 	mov	r7, dpl
                           001321  4198 	C$fuzzy.h$2202$1_0$83 ==.
                                   4199 ;	../../fuzzy.h:2202: if (parameters == NULL) {
      0013DE E5 08            [12] 4200 	mov	a,_bp
      0013E0 24 F4            [12] 4201 	add	a,#0xf4
      0013E2 F8               [12] 4202 	mov	r0,a
      0013E3 E6               [12] 4203 	mov	a,@r0
      0013E4 08               [12] 4204 	inc	r0
      0013E5 46               [12] 4205 	orl	a,@r0
      0013E6 70 09            [24] 4206 	jnz	00102$
                           00132B  4207 	C$fuzzy.h$2203$2_0$84 ==.
                                   4208 ;	../../fuzzy.h:2203: return LEVEL_LO;
      0013E8 90 00 00         [24] 4209 	mov	dptr,#0x0000
      0013EB E4               [12] 4210 	clr	a
      0013EC F5 F0            [12] 4211 	mov	b,a
      0013EE 02 17 6D         [24] 4212 	ljmp	00123$
      0013F1                       4213 00102$:
                           001334  4214 	C$fuzzy.h$2206$1_0$83 ==.
                                   4215 ;	../../fuzzy.h:2206: switch (shape) {
      0013F1 EF               [12] 4216 	mov	a,r7
      0013F2 24 F4            [12] 4217 	add	a,#0xff - 0x0b
      0013F4 50 03            [24] 4218 	jnc	00156$
      0013F6 02 17 67         [24] 4219 	ljmp	00121$
      0013F9                       4220 00156$:
      0013F9 EF               [12] 4221 	mov	a,r7
      0013FA 24 0A            [12] 4222 	add	a,#(00157$-3-.)
      0013FC 83               [24] 4223 	movc	a,@a+pc
      0013FD F5 82            [12] 4224 	mov	dpl,a
      0013FF EF               [12] 4225 	mov	a,r7
      001400 24 10            [12] 4226 	add	a,#(00158$-3-.)
      001402 83               [24] 4227 	movc	a,@a+pc
      001403 F5 83            [12] 4228 	mov	dph,a
      001405 E4               [12] 4229 	clr	a
      001406 73               [24] 4230 	jmp	@a+dptr
      001407                       4231 00157$:
      001407 1F                    4232 	.db	00103$
      001408 1B                    4233 	.db	00106$
      001409 1B                    4234 	.db	00109$
      00140A 5F                    4235 	.db	00120$
      00140B 5F                    4236 	.db	00120$
      00140C 5F                    4237 	.db	00120$
      00140D 5F                    4238 	.db	00120$
      00140E 5F                    4239 	.db	00120$
      00140F 5F                    4240 	.db	00120$
      001410 5F                    4241 	.db	00120$
      001411 5F                    4242 	.db	00120$
      001412 5F                    4243 	.db	00120$
      001413                       4244 00158$:
      001413 14                    4245 	.db	00103$>>8
      001414 15                    4246 	.db	00106$>>8
      001415 16                    4247 	.db	00109$>>8
      001416 17                    4248 	.db	00120$>>8
      001417 17                    4249 	.db	00120$>>8
      001418 17                    4250 	.db	00120$>>8
      001419 17                    4251 	.db	00120$>>8
      00141A 17                    4252 	.db	00120$>>8
      00141B 17                    4253 	.db	00120$>>8
      00141C 17                    4254 	.db	00120$>>8
      00141D 17                    4255 	.db	00120$>>8
      00141E 17                    4256 	.db	00120$>>8
                           001362  4257 	C$fuzzy.h$2207$2_0$85 ==.
                                   4258 ;	../../fuzzy.h:2207: case FUZZY_SHAPE_RAMP:
      00141F                       4259 00103$:
                           001362  4260 	C$fuzzy.h$2208$2_0$85 ==.
                                   4261 ;	../../fuzzy.h:2208: if (parameter_count != 3u) {
      00141F E5 08            [12] 4262 	mov	a,_bp
      001421 24 F7            [12] 4263 	add	a,#0xf7
      001423 F8               [12] 4264 	mov	r0,a
      001424 B6 03 06         [24] 4265 	cjne	@r0,#0x03,00159$
      001427 08               [12] 4266 	inc	r0
      001428 B6 00 02         [24] 4267 	cjne	@r0,#0x00,00159$
      00142B 80 09            [24] 4268 	sjmp	00105$
      00142D                       4269 00159$:
                           001370  4270 	C$fuzzy.h$2209$3_0$86 ==.
                                   4271 ;	../../fuzzy.h:2209: return LEVEL_LO;
      00142D 90 00 00         [24] 4272 	mov	dptr,#0x0000
      001430 E4               [12] 4273 	clr	a
      001431 F5 F0            [12] 4274 	mov	b,a
      001433 02 17 6D         [24] 4275 	ljmp	00123$
      001436                       4276 00105$:
                           001379  4277 	C$fuzzy.h$2216$2_0$85 ==.
                                   4278 ;	../../fuzzy.h:2216: parameters[2] != 0.0f,
      001436 E5 08            [12] 4279 	mov	a,_bp
      001438 24 F4            [12] 4280 	add	a,#0xf4
      00143A F8               [12] 4281 	mov	r0,a
      00143B 74 08            [12] 4282 	mov	a,#0x08
      00143D 26               [12] 4283 	add	a, @r0
      00143E FD               [12] 4284 	mov	r5,a
      00143F E4               [12] 4285 	clr	a
      001440 08               [12] 4286 	inc	r0
      001441 36               [12] 4287 	addc	a, @r0
      001442 FE               [12] 4288 	mov	r6,a
      001443 08               [12] 4289 	inc	r0
      001444 86 07            [24] 4290 	mov	ar7,@r0
      001446 8D 82            [24] 4291 	mov	dpl,r5
      001448 8E 83            [24] 4292 	mov	dph,r6
      00144A 8F F0            [24] 4293 	mov	b,r7
      00144C 12 43 A8         [24] 4294 	lcall	__gptrget
      00144F FD               [12] 4295 	mov	r5,a
      001450 A3               [24] 4296 	inc	dptr
      001451 12 43 A8         [24] 4297 	lcall	__gptrget
      001454 FE               [12] 4298 	mov	r6,a
      001455 A3               [24] 4299 	inc	dptr
      001456 12 43 A8         [24] 4300 	lcall	__gptrget
      001459 FF               [12] 4301 	mov	r7,a
      00145A A3               [24] 4302 	inc	dptr
      00145B 12 43 A8         [24] 4303 	lcall	__gptrget
      00145E FC               [12] 4304 	mov	r4,a
      00145F 8D F0            [24] 4305 	mov	b,r5
      001461 EE               [12] 4306 	mov	a,r6
      001462 42 F0            [12] 4307 	orl	b,a
      001464 EF               [12] 4308 	mov	a,r7
      001465 42 F0            [12] 4309 	orl	b,a
      001467 EC               [12] 4310 	mov	a,r4
      001468 54 7F            [12] 4311 	anl	a,#0x7F
      00146A 45 F0            [12] 4312 	orl	a,b
      00146C B4 01 00         [24] 4313 	cjne	a,#0x01,00160$
      00146F                       4314 00160$:
      00146F B3               [12] 4315 	cpl	c
      001470 92 00            [24] 4316 	mov	b0,c
      001472 E4               [12] 4317 	clr	a
      001473 33               [12] 4318 	rlc	a
      001474 FB               [12] 4319 	mov	r3,a
                           0013B8  4320 	C$fuzzy.h$2214$2_0$85 ==.
                                   4321 ;	../../fuzzy.h:2214: parameters[1],
      001475 E5 08            [12] 4322 	mov	a,_bp
      001477 24 F4            [12] 4323 	add	a,#0xf4
      001479 F8               [12] 4324 	mov	r0,a
      00147A 74 04            [12] 4325 	mov	a,#0x04
      00147C 26               [12] 4326 	add	a, @r0
      00147D FC               [12] 4327 	mov	r4,a
      00147E E4               [12] 4328 	clr	a
      00147F 08               [12] 4329 	inc	r0
      001480 36               [12] 4330 	addc	a, @r0
      001481 FD               [12] 4331 	mov	r5,a
      001482 08               [12] 4332 	inc	r0
      001483 86 06            [24] 4333 	mov	ar6,@r0
      001485 8C 82            [24] 4334 	mov	dpl,r4
      001487 8D 83            [24] 4335 	mov	dph,r5
      001489 8E F0            [24] 4336 	mov	b,r6
      00148B A8 08            [24] 4337 	mov	r0,_bp
      00148D 08               [12] 4338 	inc	r0
      00148E 12 43 A8         [24] 4339 	lcall	__gptrget
      001491 F6               [12] 4340 	mov	@r0,a
      001492 A3               [24] 4341 	inc	dptr
      001493 12 43 A8         [24] 4342 	lcall	__gptrget
      001496 08               [12] 4343 	inc	r0
      001497 F6               [12] 4344 	mov	@r0,a
      001498 A3               [24] 4345 	inc	dptr
      001499 12 43 A8         [24] 4346 	lcall	__gptrget
      00149C 08               [12] 4347 	inc	r0
      00149D F6               [12] 4348 	mov	@r0,a
      00149E A3               [24] 4349 	inc	dptr
      00149F 12 43 A8         [24] 4350 	lcall	__gptrget
      0014A2 08               [12] 4351 	inc	r0
      0014A3 F6               [12] 4352 	mov	@r0,a
                           0013E7  4353 	C$fuzzy.h$2213$2_0$85 ==.
                                   4354 ;	../../fuzzy.h:2213: parameters[0],
      0014A4 E5 08            [12] 4355 	mov	a,_bp
      0014A6 24 F4            [12] 4356 	add	a,#0xf4
      0014A8 F8               [12] 4357 	mov	r0,a
      0014A9 86 02            [24] 4358 	mov	ar2,@r0
      0014AB 08               [12] 4359 	inc	r0
      0014AC 86 06            [24] 4360 	mov	ar6,@r0
      0014AE 08               [12] 4361 	inc	r0
      0014AF 86 07            [24] 4362 	mov	ar7,@r0
      0014B1 8A 82            [24] 4363 	mov	dpl,r2
      0014B3 8E 83            [24] 4364 	mov	dph,r6
      0014B5 8F F0            [24] 4365 	mov	b,r7
      0014B7 12 43 A8         [24] 4366 	lcall	__gptrget
      0014BA FA               [12] 4367 	mov	r2,a
      0014BB A3               [24] 4368 	inc	dptr
      0014BC 12 43 A8         [24] 4369 	lcall	__gptrget
      0014BF FE               [12] 4370 	mov	r6,a
      0014C0 A3               [24] 4371 	inc	dptr
      0014C1 12 43 A8         [24] 4372 	lcall	__gptrget
      0014C4 FF               [12] 4373 	mov	r7,a
      0014C5 A3               [24] 4374 	inc	dptr
      0014C6 12 43 A8         [24] 4375 	lcall	__gptrget
      0014C9 FD               [12] 4376 	mov	r5,a
      0014CA E5 08            [12] 4377 	mov	a,_bp
      0014CC 24 F9            [12] 4378 	add	a,#0xf9
      0014CE F8               [12] 4379 	mov	r0,a
      0014CF E6               [12] 4380 	mov	a,@r0
      0014D0 C0 E0            [24] 4381 	push	acc
      0014D2 C0 03            [24] 4382 	push	ar3
      0014D4 E5 08            [12] 4383 	mov	a,_bp
      0014D6 24 FA            [12] 4384 	add	a,#0xfa
      0014D8 F8               [12] 4385 	mov	r0,a
      0014D9 E6               [12] 4386 	mov	a,@r0
      0014DA C0 E0            [24] 4387 	push	acc
      0014DC 08               [12] 4388 	inc	r0
      0014DD E6               [12] 4389 	mov	a,@r0
      0014DE C0 E0            [24] 4390 	push	acc
      0014E0 08               [12] 4391 	inc	r0
      0014E1 E6               [12] 4392 	mov	a,@r0
      0014E2 C0 E0            [24] 4393 	push	acc
      0014E4 08               [12] 4394 	inc	r0
      0014E5 E6               [12] 4395 	mov	a,@r0
      0014E6 C0 E0            [24] 4396 	push	acc
      0014E8 A8 08            [24] 4397 	mov	r0,_bp
      0014EA 08               [12] 4398 	inc	r0
      0014EB E6               [12] 4399 	mov	a,@r0
      0014EC C0 E0            [24] 4400 	push	acc
      0014EE 08               [12] 4401 	inc	r0
      0014EF E6               [12] 4402 	mov	a,@r0
      0014F0 C0 E0            [24] 4403 	push	acc
      0014F2 08               [12] 4404 	inc	r0
      0014F3 E6               [12] 4405 	mov	a,@r0
      0014F4 C0 E0            [24] 4406 	push	acc
      0014F6 08               [12] 4407 	inc	r0
      0014F7 E6               [12] 4408 	mov	a,@r0
      0014F8 C0 E0            [24] 4409 	push	acc
      0014FA 8A 82            [24] 4410 	mov	dpl, r2
      0014FC 8E 83            [24] 4411 	mov	dph, r6
      0014FE 8F F0            [24] 4412 	mov	b, r7
      001500 ED               [12] 4413 	mov	a, r5
      001501 12 0A F2         [24] 4414 	lcall	_fuzzy_ramp
      001504 AC 82            [24] 4415 	mov	r4, dpl
      001506 AD 83            [24] 4416 	mov	r5, dph
      001508 AE F0            [24] 4417 	mov	r6, b
      00150A FF               [12] 4418 	mov	r7, a
      00150B E5 81            [12] 4419 	mov	a,sp
      00150D 24 F6            [12] 4420 	add	a,#0xf6
      00150F F5 81            [12] 4421 	mov	sp,a
      001511 8C 82            [24] 4422 	mov	dpl, r4
      001513 8D 83            [24] 4423 	mov	dph, r5
      001515 8E F0            [24] 4424 	mov	b, r6
      001517 EF               [12] 4425 	mov	a, r7
      001518 02 17 6D         [24] 4426 	ljmp	00123$
                           00145E  4427 	C$fuzzy.h$2220$2_0$85 ==.
                                   4428 ;	../../fuzzy.h:2220: case FUZZY_SHAPE_TRIANGLE:
      00151B                       4429 00106$:
                           00145E  4430 	C$fuzzy.h$2221$2_0$85 ==.
                                   4431 ;	../../fuzzy.h:2221: if (parameter_count != 3u) {
      00151B E5 08            [12] 4432 	mov	a,_bp
      00151D 24 F7            [12] 4433 	add	a,#0xf7
      00151F F8               [12] 4434 	mov	r0,a
      001520 B6 03 06         [24] 4435 	cjne	@r0,#0x03,00161$
      001523 08               [12] 4436 	inc	r0
      001524 B6 00 02         [24] 4437 	cjne	@r0,#0x00,00161$
      001527 80 09            [24] 4438 	sjmp	00108$
      001529                       4439 00161$:
                           00146C  4440 	C$fuzzy.h$2222$3_0$87 ==.
                                   4441 ;	../../fuzzy.h:2222: return LEVEL_LO;
      001529 90 00 00         [24] 4442 	mov	dptr,#0x0000
      00152C E4               [12] 4443 	clr	a
      00152D F5 F0            [12] 4444 	mov	b,a
      00152F 02 17 6D         [24] 4445 	ljmp	00123$
      001532                       4446 00108$:
                           001475  4447 	C$fuzzy.h$2228$2_0$85 ==.
                                   4448 ;	../../fuzzy.h:2228: parameters[2],
      001532 E5 08            [12] 4449 	mov	a,_bp
      001534 24 F4            [12] 4450 	add	a,#0xf4
      001536 F8               [12] 4451 	mov	r0,a
      001537 74 08            [12] 4452 	mov	a,#0x08
      001539 26               [12] 4453 	add	a, @r0
      00153A FD               [12] 4454 	mov	r5,a
      00153B E4               [12] 4455 	clr	a
      00153C 08               [12] 4456 	inc	r0
      00153D 36               [12] 4457 	addc	a, @r0
      00153E FE               [12] 4458 	mov	r6,a
      00153F 08               [12] 4459 	inc	r0
      001540 86 07            [24] 4460 	mov	ar7,@r0
      001542 8D 82            [24] 4461 	mov	dpl,r5
      001544 8E 83            [24] 4462 	mov	dph,r6
      001546 8F F0            [24] 4463 	mov	b,r7
      001548 A8 08            [24] 4464 	mov	r0,_bp
      00154A 08               [12] 4465 	inc	r0
      00154B 12 43 A8         [24] 4466 	lcall	__gptrget
      00154E F6               [12] 4467 	mov	@r0,a
      00154F A3               [24] 4468 	inc	dptr
      001550 12 43 A8         [24] 4469 	lcall	__gptrget
      001553 08               [12] 4470 	inc	r0
      001554 F6               [12] 4471 	mov	@r0,a
      001555 A3               [24] 4472 	inc	dptr
      001556 12 43 A8         [24] 4473 	lcall	__gptrget
      001559 08               [12] 4474 	inc	r0
      00155A F6               [12] 4475 	mov	@r0,a
      00155B A3               [24] 4476 	inc	dptr
      00155C 12 43 A8         [24] 4477 	lcall	__gptrget
      00155F 08               [12] 4478 	inc	r0
      001560 F6               [12] 4479 	mov	@r0,a
                           0014A4  4480 	C$fuzzy.h$2227$2_0$85 ==.
                                   4481 ;	../../fuzzy.h:2227: parameters[1],
      001561 E5 08            [12] 4482 	mov	a,_bp
      001563 24 F4            [12] 4483 	add	a,#0xf4
      001565 F8               [12] 4484 	mov	r0,a
      001566 74 04            [12] 4485 	mov	a,#0x04
      001568 26               [12] 4486 	add	a, @r0
      001569 FA               [12] 4487 	mov	r2,a
      00156A E4               [12] 4488 	clr	a
      00156B 08               [12] 4489 	inc	r0
      00156C 36               [12] 4490 	addc	a, @r0
      00156D FB               [12] 4491 	mov	r3,a
      00156E 08               [12] 4492 	inc	r0
      00156F 86 07            [24] 4493 	mov	ar7,@r0
      001571 8A 82            [24] 4494 	mov	dpl,r2
      001573 8B 83            [24] 4495 	mov	dph,r3
      001575 8F F0            [24] 4496 	mov	b,r7
      001577 E5 08            [12] 4497 	mov	a,_bp
      001579 24 05            [12] 4498 	add	a,#0x05
      00157B F8               [12] 4499 	mov	r0,a
      00157C 12 43 A8         [24] 4500 	lcall	__gptrget
      00157F F6               [12] 4501 	mov	@r0,a
      001580 A3               [24] 4502 	inc	dptr
      001581 12 43 A8         [24] 4503 	lcall	__gptrget
      001584 08               [12] 4504 	inc	r0
      001585 F6               [12] 4505 	mov	@r0,a
      001586 A3               [24] 4506 	inc	dptr
      001587 12 43 A8         [24] 4507 	lcall	__gptrget
      00158A 08               [12] 4508 	inc	r0
      00158B F6               [12] 4509 	mov	@r0,a
      00158C A3               [24] 4510 	inc	dptr
      00158D 12 43 A8         [24] 4511 	lcall	__gptrget
      001590 08               [12] 4512 	inc	r0
      001591 F6               [12] 4513 	mov	@r0,a
                           0014D5  4514 	C$fuzzy.h$2226$2_0$85 ==.
                                   4515 ;	../../fuzzy.h:2226: parameters[0],
      001592 E5 08            [12] 4516 	mov	a,_bp
      001594 24 F4            [12] 4517 	add	a,#0xf4
      001596 F8               [12] 4518 	mov	r0,a
      001597 86 04            [24] 4519 	mov	ar4,@r0
      001599 08               [12] 4520 	inc	r0
      00159A 86 05            [24] 4521 	mov	ar5,@r0
      00159C 08               [12] 4522 	inc	r0
      00159D 86 07            [24] 4523 	mov	ar7,@r0
      00159F 8C 82            [24] 4524 	mov	dpl,r4
      0015A1 8D 83            [24] 4525 	mov	dph,r5
      0015A3 8F F0            [24] 4526 	mov	b,r7
      0015A5 12 43 A8         [24] 4527 	lcall	__gptrget
      0015A8 FC               [12] 4528 	mov	r4,a
      0015A9 A3               [24] 4529 	inc	dptr
      0015AA 12 43 A8         [24] 4530 	lcall	__gptrget
      0015AD FD               [12] 4531 	mov	r5,a
      0015AE A3               [24] 4532 	inc	dptr
      0015AF 12 43 A8         [24] 4533 	lcall	__gptrget
      0015B2 FF               [12] 4534 	mov	r7,a
      0015B3 A3               [24] 4535 	inc	dptr
      0015B4 12 43 A8         [24] 4536 	lcall	__gptrget
      0015B7 FE               [12] 4537 	mov	r6,a
      0015B8 E5 08            [12] 4538 	mov	a,_bp
      0015BA 24 F9            [12] 4539 	add	a,#0xf9
      0015BC F8               [12] 4540 	mov	r0,a
      0015BD E6               [12] 4541 	mov	a,@r0
      0015BE C0 E0            [24] 4542 	push	acc
      0015C0 E5 08            [12] 4543 	mov	a,_bp
      0015C2 24 FA            [12] 4544 	add	a,#0xfa
      0015C4 F8               [12] 4545 	mov	r0,a
      0015C5 E6               [12] 4546 	mov	a,@r0
      0015C6 C0 E0            [24] 4547 	push	acc
      0015C8 08               [12] 4548 	inc	r0
      0015C9 E6               [12] 4549 	mov	a,@r0
      0015CA C0 E0            [24] 4550 	push	acc
      0015CC 08               [12] 4551 	inc	r0
      0015CD E6               [12] 4552 	mov	a,@r0
      0015CE C0 E0            [24] 4553 	push	acc
      0015D0 08               [12] 4554 	inc	r0
      0015D1 E6               [12] 4555 	mov	a,@r0
      0015D2 C0 E0            [24] 4556 	push	acc
      0015D4 A8 08            [24] 4557 	mov	r0,_bp
      0015D6 08               [12] 4558 	inc	r0
      0015D7 E6               [12] 4559 	mov	a,@r0
      0015D8 C0 E0            [24] 4560 	push	acc
      0015DA 08               [12] 4561 	inc	r0
      0015DB E6               [12] 4562 	mov	a,@r0
      0015DC C0 E0            [24] 4563 	push	acc
      0015DE 08               [12] 4564 	inc	r0
      0015DF E6               [12] 4565 	mov	a,@r0
      0015E0 C0 E0            [24] 4566 	push	acc
      0015E2 08               [12] 4567 	inc	r0
      0015E3 E6               [12] 4568 	mov	a,@r0
      0015E4 C0 E0            [24] 4569 	push	acc
      0015E6 E5 08            [12] 4570 	mov	a,_bp
      0015E8 24 05            [12] 4571 	add	a,#0x05
      0015EA F8               [12] 4572 	mov	r0,a
      0015EB E6               [12] 4573 	mov	a,@r0
      0015EC C0 E0            [24] 4574 	push	acc
      0015EE 08               [12] 4575 	inc	r0
      0015EF E6               [12] 4576 	mov	a,@r0
      0015F0 C0 E0            [24] 4577 	push	acc
      0015F2 08               [12] 4578 	inc	r0
      0015F3 E6               [12] 4579 	mov	a,@r0
      0015F4 C0 E0            [24] 4580 	push	acc
      0015F6 08               [12] 4581 	inc	r0
      0015F7 E6               [12] 4582 	mov	a,@r0
      0015F8 C0 E0            [24] 4583 	push	acc
      0015FA 8C 82            [24] 4584 	mov	dpl, r4
      0015FC 8D 83            [24] 4585 	mov	dph, r5
      0015FE 8F F0            [24] 4586 	mov	b, r7
      001600 EE               [12] 4587 	mov	a, r6
      001601 12 0D 2F         [24] 4588 	lcall	_fuzzy_triangle
      001604 AC 82            [24] 4589 	mov	r4, dpl
      001606 AD 83            [24] 4590 	mov	r5, dph
      001608 AE F0            [24] 4591 	mov	r6, b
      00160A FF               [12] 4592 	mov	r7, a
      00160B E5 81            [12] 4593 	mov	a,sp
      00160D 24 F3            [12] 4594 	add	a,#0xf3
      00160F F5 81            [12] 4595 	mov	sp,a
      001611 8C 82            [24] 4596 	mov	dpl, r4
      001613 8D 83            [24] 4597 	mov	dph, r5
      001615 8E F0            [24] 4598 	mov	b, r6
      001617 EF               [12] 4599 	mov	a, r7
      001618 02 17 6D         [24] 4600 	ljmp	00123$
                           00155E  4601 	C$fuzzy.h$2233$2_0$85 ==.
                                   4602 ;	../../fuzzy.h:2233: case FUZZY_SHAPE_TRAPEZOID:
      00161B                       4603 00109$:
                           00155E  4604 	C$fuzzy.h$2234$2_0$85 ==.
                                   4605 ;	../../fuzzy.h:2234: if (parameter_count != 4u) {
      00161B E5 08            [12] 4606 	mov	a,_bp
      00161D 24 F7            [12] 4607 	add	a,#0xf7
      00161F F8               [12] 4608 	mov	r0,a
      001620 B6 04 06         [24] 4609 	cjne	@r0,#0x04,00162$
      001623 08               [12] 4610 	inc	r0
      001624 B6 00 02         [24] 4611 	cjne	@r0,#0x00,00162$
      001627 80 09            [24] 4612 	sjmp	00111$
      001629                       4613 00162$:
                           00156C  4614 	C$fuzzy.h$2235$3_0$88 ==.
                                   4615 ;	../../fuzzy.h:2235: return LEVEL_LO;
      001629 90 00 00         [24] 4616 	mov	dptr,#0x0000
      00162C E4               [12] 4617 	clr	a
      00162D F5 F0            [12] 4618 	mov	b,a
      00162F 02 17 6D         [24] 4619 	ljmp	00123$
      001632                       4620 00111$:
                           001575  4621 	C$fuzzy.h$2242$2_0$85 ==.
                                   4622 ;	../../fuzzy.h:2242: parameters[3],
      001632 E5 08            [12] 4623 	mov	a,_bp
      001634 24 F4            [12] 4624 	add	a,#0xf4
      001636 F8               [12] 4625 	mov	r0,a
      001637 74 0C            [12] 4626 	mov	a,#0x0c
      001639 26               [12] 4627 	add	a, @r0
      00163A FD               [12] 4628 	mov	r5,a
      00163B E4               [12] 4629 	clr	a
      00163C 08               [12] 4630 	inc	r0
      00163D 36               [12] 4631 	addc	a, @r0
      00163E FE               [12] 4632 	mov	r6,a
      00163F 08               [12] 4633 	inc	r0
      001640 86 07            [24] 4634 	mov	ar7,@r0
      001642 8D 82            [24] 4635 	mov	dpl,r5
      001644 8E 83            [24] 4636 	mov	dph,r6
      001646 8F F0            [24] 4637 	mov	b,r7
      001648 E5 08            [12] 4638 	mov	a,_bp
      00164A 24 05            [12] 4639 	add	a,#0x05
      00164C F8               [12] 4640 	mov	r0,a
      00164D 12 43 A8         [24] 4641 	lcall	__gptrget
      001650 F6               [12] 4642 	mov	@r0,a
      001651 A3               [24] 4643 	inc	dptr
      001652 12 43 A8         [24] 4644 	lcall	__gptrget
      001655 08               [12] 4645 	inc	r0
      001656 F6               [12] 4646 	mov	@r0,a
      001657 A3               [24] 4647 	inc	dptr
      001658 12 43 A8         [24] 4648 	lcall	__gptrget
      00165B 08               [12] 4649 	inc	r0
      00165C F6               [12] 4650 	mov	@r0,a
      00165D A3               [24] 4651 	inc	dptr
      00165E 12 43 A8         [24] 4652 	lcall	__gptrget
      001661 08               [12] 4653 	inc	r0
      001662 F6               [12] 4654 	mov	@r0,a
                           0015A6  4655 	C$fuzzy.h$2241$2_0$85 ==.
                                   4656 ;	../../fuzzy.h:2241: parameters[2],
      001663 E5 08            [12] 4657 	mov	a,_bp
      001665 24 F4            [12] 4658 	add	a,#0xf4
      001667 F8               [12] 4659 	mov	r0,a
      001668 74 08            [12] 4660 	mov	a,#0x08
      00166A 26               [12] 4661 	add	a, @r0
      00166B FA               [12] 4662 	mov	r2,a
      00166C E4               [12] 4663 	clr	a
      00166D 08               [12] 4664 	inc	r0
      00166E 36               [12] 4665 	addc	a, @r0
      00166F FB               [12] 4666 	mov	r3,a
      001670 08               [12] 4667 	inc	r0
      001671 86 07            [24] 4668 	mov	ar7,@r0
      001673 8A 82            [24] 4669 	mov	dpl,r2
      001675 8B 83            [24] 4670 	mov	dph,r3
      001677 8F F0            [24] 4671 	mov	b,r7
      001679 A8 08            [24] 4672 	mov	r0,_bp
      00167B 08               [12] 4673 	inc	r0
      00167C 12 43 A8         [24] 4674 	lcall	__gptrget
      00167F F6               [12] 4675 	mov	@r0,a
      001680 A3               [24] 4676 	inc	dptr
      001681 12 43 A8         [24] 4677 	lcall	__gptrget
      001684 08               [12] 4678 	inc	r0
      001685 F6               [12] 4679 	mov	@r0,a
      001686 A3               [24] 4680 	inc	dptr
      001687 12 43 A8         [24] 4681 	lcall	__gptrget
      00168A 08               [12] 4682 	inc	r0
      00168B F6               [12] 4683 	mov	@r0,a
      00168C A3               [24] 4684 	inc	dptr
      00168D 12 43 A8         [24] 4685 	lcall	__gptrget
      001690 08               [12] 4686 	inc	r0
      001691 F6               [12] 4687 	mov	@r0,a
                           0015D5  4688 	C$fuzzy.h$2240$2_0$85 ==.
                                   4689 ;	../../fuzzy.h:2240: parameters[1],
      001692 E5 08            [12] 4690 	mov	a,_bp
      001694 24 F4            [12] 4691 	add	a,#0xf4
      001696 F8               [12] 4692 	mov	r0,a
      001697 74 04            [12] 4693 	mov	a,#0x04
      001699 26               [12] 4694 	add	a, @r0
      00169A FC               [12] 4695 	mov	r4,a
      00169B E4               [12] 4696 	clr	a
      00169C 08               [12] 4697 	inc	r0
      00169D 36               [12] 4698 	addc	a, @r0
      00169E FD               [12] 4699 	mov	r5,a
      00169F 08               [12] 4700 	inc	r0
      0016A0 86 07            [24] 4701 	mov	ar7,@r0
      0016A2 8C 82            [24] 4702 	mov	dpl,r4
      0016A4 8D 83            [24] 4703 	mov	dph,r5
      0016A6 8F F0            [24] 4704 	mov	b,r7
      0016A8 E5 08            [12] 4705 	mov	a,_bp
      0016AA 24 09            [12] 4706 	add	a,#0x09
      0016AC F8               [12] 4707 	mov	r0,a
      0016AD 12 43 A8         [24] 4708 	lcall	__gptrget
      0016B0 F6               [12] 4709 	mov	@r0,a
      0016B1 A3               [24] 4710 	inc	dptr
      0016B2 12 43 A8         [24] 4711 	lcall	__gptrget
      0016B5 08               [12] 4712 	inc	r0
      0016B6 F6               [12] 4713 	mov	@r0,a
      0016B7 A3               [24] 4714 	inc	dptr
      0016B8 12 43 A8         [24] 4715 	lcall	__gptrget
      0016BB 08               [12] 4716 	inc	r0
      0016BC F6               [12] 4717 	mov	@r0,a
      0016BD A3               [24] 4718 	inc	dptr
      0016BE 12 43 A8         [24] 4719 	lcall	__gptrget
      0016C1 08               [12] 4720 	inc	r0
      0016C2 F6               [12] 4721 	mov	@r0,a
                           001606  4722 	C$fuzzy.h$2239$2_0$85 ==.
                                   4723 ;	../../fuzzy.h:2239: parameters[0],
      0016C3 E5 08            [12] 4724 	mov	a,_bp
      0016C5 24 F4            [12] 4725 	add	a,#0xf4
      0016C7 F8               [12] 4726 	mov	r0,a
      0016C8 86 02            [24] 4727 	mov	ar2,@r0
      0016CA 08               [12] 4728 	inc	r0
      0016CB 86 03            [24] 4729 	mov	ar3,@r0
      0016CD 08               [12] 4730 	inc	r0
      0016CE 86 07            [24] 4731 	mov	ar7,@r0
      0016D0 8A 82            [24] 4732 	mov	dpl,r2
      0016D2 8B 83            [24] 4733 	mov	dph,r3
      0016D4 8F F0            [24] 4734 	mov	b,r7
      0016D6 12 43 A8         [24] 4735 	lcall	__gptrget
      0016D9 FA               [12] 4736 	mov	r2,a
      0016DA A3               [24] 4737 	inc	dptr
      0016DB 12 43 A8         [24] 4738 	lcall	__gptrget
      0016DE FB               [12] 4739 	mov	r3,a
      0016DF A3               [24] 4740 	inc	dptr
      0016E0 12 43 A8         [24] 4741 	lcall	__gptrget
      0016E3 FF               [12] 4742 	mov	r7,a
      0016E4 A3               [24] 4743 	inc	dptr
      0016E5 12 43 A8         [24] 4744 	lcall	__gptrget
      0016E8 FE               [12] 4745 	mov	r6,a
      0016E9 E5 08            [12] 4746 	mov	a,_bp
      0016EB 24 F9            [12] 4747 	add	a,#0xf9
      0016ED F8               [12] 4748 	mov	r0,a
      0016EE E6               [12] 4749 	mov	a,@r0
      0016EF C0 E0            [24] 4750 	push	acc
      0016F1 E5 08            [12] 4751 	mov	a,_bp
      0016F3 24 FA            [12] 4752 	add	a,#0xfa
      0016F5 F8               [12] 4753 	mov	r0,a
      0016F6 E6               [12] 4754 	mov	a,@r0
      0016F7 C0 E0            [24] 4755 	push	acc
      0016F9 08               [12] 4756 	inc	r0
      0016FA E6               [12] 4757 	mov	a,@r0
      0016FB C0 E0            [24] 4758 	push	acc
      0016FD 08               [12] 4759 	inc	r0
      0016FE E6               [12] 4760 	mov	a,@r0
      0016FF C0 E0            [24] 4761 	push	acc
      001701 08               [12] 4762 	inc	r0
      001702 E6               [12] 4763 	mov	a,@r0
      001703 C0 E0            [24] 4764 	push	acc
      001705 E5 08            [12] 4765 	mov	a,_bp
      001707 24 05            [12] 4766 	add	a,#0x05
      001709 F8               [12] 4767 	mov	r0,a
      00170A E6               [12] 4768 	mov	a,@r0
      00170B C0 E0            [24] 4769 	push	acc
      00170D 08               [12] 4770 	inc	r0
      00170E E6               [12] 4771 	mov	a,@r0
      00170F C0 E0            [24] 4772 	push	acc
      001711 08               [12] 4773 	inc	r0
      001712 E6               [12] 4774 	mov	a,@r0
      001713 C0 E0            [24] 4775 	push	acc
      001715 08               [12] 4776 	inc	r0
      001716 E6               [12] 4777 	mov	a,@r0
      001717 C0 E0            [24] 4778 	push	acc
      001719 A8 08            [24] 4779 	mov	r0,_bp
      00171B 08               [12] 4780 	inc	r0
      00171C E6               [12] 4781 	mov	a,@r0
      00171D C0 E0            [24] 4782 	push	acc
      00171F 08               [12] 4783 	inc	r0
      001720 E6               [12] 4784 	mov	a,@r0
      001721 C0 E0            [24] 4785 	push	acc
      001723 08               [12] 4786 	inc	r0
      001724 E6               [12] 4787 	mov	a,@r0
      001725 C0 E0            [24] 4788 	push	acc
      001727 08               [12] 4789 	inc	r0
      001728 E6               [12] 4790 	mov	a,@r0
      001729 C0 E0            [24] 4791 	push	acc
      00172B E5 08            [12] 4792 	mov	a,_bp
      00172D 24 09            [12] 4793 	add	a,#0x09
      00172F F8               [12] 4794 	mov	r0,a
      001730 E6               [12] 4795 	mov	a,@r0
      001731 C0 E0            [24] 4796 	push	acc
      001733 08               [12] 4797 	inc	r0
      001734 E6               [12] 4798 	mov	a,@r0
      001735 C0 E0            [24] 4799 	push	acc
      001737 08               [12] 4800 	inc	r0
      001738 E6               [12] 4801 	mov	a,@r0
      001739 C0 E0            [24] 4802 	push	acc
      00173B 08               [12] 4803 	inc	r0
      00173C E6               [12] 4804 	mov	a,@r0
      00173D C0 E0            [24] 4805 	push	acc
      00173F 8A 82            [24] 4806 	mov	dpl, r2
      001741 8B 83            [24] 4807 	mov	dph, r3
      001743 8F F0            [24] 4808 	mov	b, r7
      001745 EE               [12] 4809 	mov	a, r6
      001746 12 10 3B         [24] 4810 	lcall	_fuzzy_trapezoid
      001749 AC 82            [24] 4811 	mov	r4, dpl
      00174B AD 83            [24] 4812 	mov	r5, dph
      00174D AE F0            [24] 4813 	mov	r6, b
      00174F FF               [12] 4814 	mov	r7, a
      001750 E5 81            [12] 4815 	mov	a,sp
      001752 24 EF            [12] 4816 	add	a,#0xef
      001754 F5 81            [12] 4817 	mov	sp,a
      001756 8C 82            [24] 4818 	mov	dpl, r4
      001758 8D 83            [24] 4819 	mov	dph, r5
      00175A 8E F0            [24] 4820 	mov	b, r6
      00175C EF               [12] 4821 	mov	a, r7
                           0016A0  4822 	C$fuzzy.h$2376$2_0$85 ==.
                                   4823 ;	../../fuzzy.h:2376: case FUZZY_SHAPE_PSIGMOID:
      00175D 80 0E            [24] 4824 	sjmp	00123$
      00175F                       4825 00120$:
                           0016A2  4826 	C$fuzzy.h$2377$2_0$85 ==.
                                   4827 ;	../../fuzzy.h:2377: return LEVEL_LO;
      00175F 90 00 00         [24] 4828 	mov	dptr,#0x0000
      001762 E4               [12] 4829 	clr	a
      001763 F5 F0            [12] 4830 	mov	b,a
                           0016A8  4831 	C$fuzzy.h$2381$2_0$85 ==.
                                   4832 ;	../../fuzzy.h:2381: default:
      001765 80 06            [24] 4833 	sjmp	00123$
      001767                       4834 00121$:
                           0016AA  4835 	C$fuzzy.h$2382$2_0$85 ==.
                                   4836 ;	../../fuzzy.h:2382: return LEVEL_LO;
      001767 90 00 00         [24] 4837 	mov	dptr,#0x0000
      00176A E4               [12] 4838 	clr	a
      00176B F5 F0            [12] 4839 	mov	b,a
                           0016B0  4840 	C$fuzzy.h$2383$1_0$83 ==.
                                   4841 ;	../../fuzzy.h:2383: }
      00176D                       4842 00123$:
                           0016B0  4843 	C$fuzzy.h$2384$1_0$83 ==.
                                   4844 ;	../../fuzzy.h:2384: }
      00176D 85 08 81         [24] 4845 	mov	sp,_bp
      001770 D0 08            [24] 4846 	pop	_bp
                           0016B5  4847 	C$fuzzy.h$2384$1_0$83 ==.
                           0016B5  4848 	XG$fuzzy_function_array$0$0 ==.
      001772 22               [24] 4849 	ret
                                   4850 ;------------------------------------------------------------
                                   4851 ;Allocation info for local variables in function 'fuzzy_rules_add'
                                   4852 ;------------------------------------------------------------
                                   4853 ;name          Allocated to stack - _bp -5 +3 
                                   4854 ;value         Allocated to stack - _bp -9 +4 
                                   4855 ;output_function Allocated to stack - _bp -11 +2 
                                   4856 ;rules         Allocated to registers r2 r3 r4 
                                   4857 ;index         Allocated to registers 
                                   4858 ;sloc0         Allocated to stack - _bp +1 +2 
                                   4859 ;sloc1         Allocated to stack - _bp +3 +3 
                                   4860 ;sloc2         Allocated to stack - _bp +6 +3 
                                   4861 ;sloc3         Allocated to stack - _bp +9 +3 
                                   4862 ;------------------------------------------------------------
                           0016B6  4863 	G$fuzzy_rules_add$0$0 ==.
                           0016B6  4864 	C$fuzzy.h$2386$1_0$90 ==.
                                   4865 ;	../../fuzzy.h:2386: bool fuzzy_rules_add(
                                   4866 ;	-----------------------------------------
                                   4867 ;	 function fuzzy_rules_add
                                   4868 ;	-----------------------------------------
      001773                       4869 _fuzzy_rules_add:
      001773 C0 08            [24] 4870 	push	_bp
      001775 E5 81            [12] 4871 	mov	a,sp
      001777 F5 08            [12] 4872 	mov	_bp,a
      001779 24 0B            [12] 4873 	add	a,#0x0b
      00177B F5 81            [12] 4874 	mov	sp,a
      00177D AA 82            [24] 4875 	mov	r2, dpl
      00177F AB 83            [24] 4876 	mov	r3, dph
      001781 AC F0            [24] 4877 	mov	r4, b
                           0016C6  4878 	C$fuzzy.h$2396$1_0$90 ==.
                                   4879 ;	../../fuzzy.h:2396: rules == NULL ||
      001783 EA               [12] 4880 	mov	a,r2
      001784 4B               [12] 4881 	orl	a,r3
      001785 60 0A            [24] 4882 	jz	00101$
                           0016CA  4883 	C$fuzzy.h$2397$1_0$90 ==.
                                   4884 ;	../../fuzzy.h:2397: output_function == NULL
      001787 E5 08            [12] 4885 	mov	a,_bp
      001789 24 F5            [12] 4886 	add	a,#0xf5
      00178B F8               [12] 4887 	mov	r0,a
      00178C E6               [12] 4888 	mov	a,@r0
      00178D 08               [12] 4889 	inc	r0
      00178E 46               [12] 4890 	orl	a,@r0
      00178F 70 06            [24] 4891 	jnz	00102$
      001791                       4892 00101$:
                           0016D4  4893 	C$fuzzy.h$2399$2_0$91 ==.
                                   4894 ;	../../fuzzy.h:2399: return false;
      001791 75 82 00         [24] 4895 	mov	dpl, #0x00
      001794 02 18 D1         [24] 4896 	ljmp	00106$
      001797                       4897 00102$:
                           0016DA  4898 	C$fuzzy.h$2402$1_0$90 ==.
                                   4899 ;	../../fuzzy.h:2402: if (rules->count >= FUZZY_MAX_RULES) {
      001797 E5 08            [12] 4900 	mov	a,_bp
      001799 24 09            [12] 4901 	add	a,#0x09
      00179B F8               [12] 4902 	mov	r0,a
      00179C 74 90            [12] 4903 	mov	a,#0x90
      00179E 2A               [12] 4904 	add	a, r2
      00179F F6               [12] 4905 	mov	@r0,a
      0017A0 E4               [12] 4906 	clr	a
      0017A1 3B               [12] 4907 	addc	a, r3
      0017A2 08               [12] 4908 	inc	r0
      0017A3 F6               [12] 4909 	mov	@r0,a
      0017A4 08               [12] 4910 	inc	r0
      0017A5 A6 04            [24] 4911 	mov	@r0,ar4
      0017A7 E5 08            [12] 4912 	mov	a,_bp
      0017A9 24 09            [12] 4913 	add	a,#0x09
      0017AB F8               [12] 4914 	mov	r0,a
      0017AC 86 82            [24] 4915 	mov	dpl,@r0
      0017AE 08               [12] 4916 	inc	r0
      0017AF 86 83            [24] 4917 	mov	dph,@r0
      0017B1 08               [12] 4918 	inc	r0
      0017B2 86 F0            [24] 4919 	mov	b,@r0
      0017B4 12 43 A8         [24] 4920 	lcall	__gptrget
      0017B7 FF               [12] 4921 	mov	r7,a
      0017B8 A3               [24] 4922 	inc	dptr
      0017B9 12 43 A8         [24] 4923 	lcall	__gptrget
      0017BC FE               [12] 4924 	mov	r6,a
      0017BD C3               [12] 4925 	clr	c
      0017BE EF               [12] 4926 	mov	a,r7
      0017BF 94 10            [12] 4927 	subb	a,#0x10
      0017C1 EE               [12] 4928 	mov	a,r6
      0017C2 94 00            [12] 4929 	subb	a,#0x00
      0017C4 40 06            [24] 4930 	jc	00105$
                           001709  4931 	C$fuzzy.h$2403$2_0$92 ==.
                                   4932 ;	../../fuzzy.h:2403: return false;
      0017C6 75 82 00         [24] 4933 	mov	dpl, #0x00
      0017C9 02 18 D1         [24] 4934 	ljmp	00106$
      0017CC                       4935 00105$:
                           00170F  4936 	C$fuzzy.h$2409$1_0$90 ==.
                                   4937 ;	../../fuzzy.h:2409: rules->rules[index].name =
      0017CC C0 04            [24] 4938 	push	ar4
      0017CE C0 03            [24] 4939 	push	ar3
      0017D0 C0 02            [24] 4940 	push	ar2
      0017D2 C0 07            [24] 4941 	push	ar7
      0017D4 C0 06            [24] 4942 	push	ar6
      0017D6 90 00 09         [24] 4943 	mov	dptr,#0x0009
      0017D9 12 41 AC         [24] 4944 	lcall	__mulint
      0017DC A8 08            [24] 4945 	mov	r0,_bp
      0017DE 08               [12] 4946 	inc	r0
      0017DF A6 82            [24] 4947 	mov	@r0, dpl
      0017E1 08               [12] 4948 	inc	r0
      0017E2 A6 83            [24] 4949 	mov	@r0, dph
      0017E4 15 81            [12] 4950 	dec	sp
      0017E6 15 81            [12] 4951 	dec	sp
      0017E8 D0 02            [24] 4952 	pop	ar2
      0017EA D0 03            [24] 4953 	pop	ar3
      0017EC D0 04            [24] 4954 	pop	ar4
      0017EE A8 08            [24] 4955 	mov	r0,_bp
      0017F0 08               [12] 4956 	inc	r0
      0017F1 E6               [12] 4957 	mov	a,@r0
      0017F2 2A               [12] 4958 	add	a, r2
      0017F3 FD               [12] 4959 	mov	r5,a
      0017F4 08               [12] 4960 	inc	r0
      0017F5 E6               [12] 4961 	mov	a,@r0
      0017F6 3B               [12] 4962 	addc	a, r3
      0017F7 FE               [12] 4963 	mov	r6,a
      0017F8 8C 07            [24] 4964 	mov	ar7,r4
      0017FA 8D 82            [24] 4965 	mov	dpl,r5
      0017FC 8E 83            [24] 4966 	mov	dph,r6
      0017FE 8F F0            [24] 4967 	mov	b,r7
      001800 E5 08            [12] 4968 	mov	a,_bp
      001802 24 FB            [12] 4969 	add	a,#0xfb
      001804 F8               [12] 4970 	mov	r0,a
      001805 E6               [12] 4971 	mov	a,@r0
      001806 12 41 61         [24] 4972 	lcall	__gptrput
      001809 A3               [24] 4973 	inc	dptr
      00180A 08               [12] 4974 	inc	r0
      00180B E6               [12] 4975 	mov	a,@r0
      00180C 12 41 61         [24] 4976 	lcall	__gptrput
      00180F A3               [24] 4977 	inc	dptr
      001810 08               [12] 4978 	inc	r0
      001811 E6               [12] 4979 	mov	a,@r0
      001812 12 41 61         [24] 4980 	lcall	__gptrput
                           001758  4981 	C$fuzzy.h$2412$1_0$90 ==.
                                   4982 ;	../../fuzzy.h:2412: rules->rules[index].value =
      001815 A8 08            [24] 4983 	mov	r0,_bp
      001817 08               [12] 4984 	inc	r0
      001818 E5 08            [12] 4985 	mov	a,_bp
      00181A 24 03            [12] 4986 	add	a,#0x03
      00181C F9               [12] 4987 	mov	r1,a
      00181D E6               [12] 4988 	mov	a,@r0
      00181E 2A               [12] 4989 	add	a, r2
      00181F F7               [12] 4990 	mov	@r1,a
      001820 08               [12] 4991 	inc	r0
      001821 E6               [12] 4992 	mov	a,@r0
      001822 3B               [12] 4993 	addc	a, r3
      001823 09               [12] 4994 	inc	r1
      001824 F7               [12] 4995 	mov	@r1,a
      001825 09               [12] 4996 	inc	r1
      001826 A7 04            [24] 4997 	mov	@r1,ar4
      001828 E5 08            [12] 4998 	mov	a,_bp
      00182A 24 03            [12] 4999 	add	a,#0x03
      00182C F8               [12] 5000 	mov	r0,a
      00182D E5 08            [12] 5001 	mov	a,_bp
      00182F 24 06            [12] 5002 	add	a,#0x06
      001831 F9               [12] 5003 	mov	r1,a
      001832 74 03            [12] 5004 	mov	a,#0x03
      001834 26               [12] 5005 	add	a, @r0
      001835 F7               [12] 5006 	mov	@r1,a
      001836 E4               [12] 5007 	clr	a
      001837 08               [12] 5008 	inc	r0
      001838 36               [12] 5009 	addc	a, @r0
      001839 09               [12] 5010 	inc	r1
      00183A F7               [12] 5011 	mov	@r1,a
      00183B 08               [12] 5012 	inc	r0
      00183C E6               [12] 5013 	mov	a,@r0
      00183D 09               [12] 5014 	inc	r1
      00183E F7               [12] 5015 	mov	@r1,a
                           001782  5016 	C$fuzzy.h$2413$1_0$90 ==.
                                   5017 ;	../../fuzzy.h:2413: fuzzy_clamp(value);
      00183F E5 08            [12] 5018 	mov	a,_bp
      001841 24 F7            [12] 5019 	add	a,#0xf7
      001843 F8               [12] 5020 	mov	r0,a
      001844 86 82            [24] 5021 	mov	dpl, @r0
      001846 08               [12] 5022 	inc	r0
      001847 86 83            [24] 5023 	mov	dph, @r0
      001849 08               [12] 5024 	inc	r0
      00184A 86 F0            [24] 5025 	mov	b, @r0
      00184C 08               [12] 5026 	inc	r0
      00184D E6               [12] 5027 	mov	a, @r0
      00184E 12 00 F0         [24] 5028 	lcall	_fuzzy_clamp
      001851 AD 82            [24] 5029 	mov	r5, dpl
      001853 AE 83            [24] 5030 	mov	r6, dph
      001855 AC F0            [24] 5031 	mov	r4, b
      001857 FF               [12] 5032 	mov	r7, a
      001858 E5 08            [12] 5033 	mov	a,_bp
      00185A 24 06            [12] 5034 	add	a,#0x06
      00185C F8               [12] 5035 	mov	r0,a
      00185D 86 82            [24] 5036 	mov	dpl,@r0
      00185F 08               [12] 5037 	inc	r0
      001860 86 83            [24] 5038 	mov	dph,@r0
      001862 08               [12] 5039 	inc	r0
      001863 86 F0            [24] 5040 	mov	b,@r0
      001865 ED               [12] 5041 	mov	a,r5
      001866 12 41 61         [24] 5042 	lcall	__gptrput
      001869 A3               [24] 5043 	inc	dptr
      00186A EE               [12] 5044 	mov	a,r6
      00186B 12 41 61         [24] 5045 	lcall	__gptrput
      00186E A3               [24] 5046 	inc	dptr
      00186F EC               [12] 5047 	mov	a,r4
      001870 12 41 61         [24] 5048 	lcall	__gptrput
      001873 A3               [24] 5049 	inc	dptr
      001874 EF               [12] 5050 	mov	a,r7
      001875 12 41 61         [24] 5051 	lcall	__gptrput
                           0017BB  5052 	C$fuzzy.h$2415$1_0$90 ==.
                                   5053 ;	../../fuzzy.h:2415: rules->rules[index].output_function =
      001878 E5 08            [12] 5054 	mov	a,_bp
      00187A 24 03            [12] 5055 	add	a,#0x03
      00187C F8               [12] 5056 	mov	r0,a
      00187D 74 07            [12] 5057 	mov	a,#0x07
      00187F 26               [12] 5058 	add	a, @r0
      001880 FD               [12] 5059 	mov	r5,a
      001881 E4               [12] 5060 	clr	a
      001882 08               [12] 5061 	inc	r0
      001883 36               [12] 5062 	addc	a, @r0
      001884 FE               [12] 5063 	mov	r6,a
      001885 08               [12] 5064 	inc	r0
      001886 86 07            [24] 5065 	mov	ar7,@r0
      001888 8D 82            [24] 5066 	mov	dpl,r5
      00188A 8E 83            [24] 5067 	mov	dph,r6
      00188C 8F F0            [24] 5068 	mov	b,r7
      00188E E5 08            [12] 5069 	mov	a,_bp
      001890 24 F5            [12] 5070 	add	a,#0xf5
      001892 F8               [12] 5071 	mov	r0,a
      001893 E6               [12] 5072 	mov	a,@r0
      001894 12 41 61         [24] 5073 	lcall	__gptrput
      001897 A3               [24] 5074 	inc	dptr
      001898 08               [12] 5075 	inc	r0
      001899 E6               [12] 5076 	mov	a,@r0
      00189A 12 41 61         [24] 5077 	lcall	__gptrput
                           0017E0  5078 	C$fuzzy.h$2418$1_0$90 ==.
                                   5079 ;	../../fuzzy.h:2418: rules->count++;
      00189D E5 08            [12] 5080 	mov	a,_bp
      00189F 24 09            [12] 5081 	add	a,#0x09
      0018A1 F8               [12] 5082 	mov	r0,a
      0018A2 86 82            [24] 5083 	mov	dpl,@r0
      0018A4 08               [12] 5084 	inc	r0
      0018A5 86 83            [24] 5085 	mov	dph,@r0
      0018A7 08               [12] 5086 	inc	r0
      0018A8 86 F0            [24] 5087 	mov	b,@r0
      0018AA 12 43 A8         [24] 5088 	lcall	__gptrget
      0018AD FE               [12] 5089 	mov	r6,a
      0018AE A3               [24] 5090 	inc	dptr
      0018AF 12 43 A8         [24] 5091 	lcall	__gptrget
      0018B2 FF               [12] 5092 	mov	r7,a
      0018B3 0E               [12] 5093 	inc	r6
      0018B4 BE 00 01         [24] 5094 	cjne	r6,#0x00,00123$
      0018B7 0F               [12] 5095 	inc	r7
      0018B8                       5096 00123$:
      0018B8 E5 08            [12] 5097 	mov	a,_bp
      0018BA 24 09            [12] 5098 	add	a,#0x09
      0018BC F8               [12] 5099 	mov	r0,a
      0018BD 86 82            [24] 5100 	mov	dpl,@r0
      0018BF 08               [12] 5101 	inc	r0
      0018C0 86 83            [24] 5102 	mov	dph,@r0
      0018C2 08               [12] 5103 	inc	r0
      0018C3 86 F0            [24] 5104 	mov	b,@r0
      0018C5 EE               [12] 5105 	mov	a,r6
      0018C6 12 41 61         [24] 5106 	lcall	__gptrput
      0018C9 A3               [24] 5107 	inc	dptr
      0018CA EF               [12] 5108 	mov	a,r7
      0018CB 12 41 61         [24] 5109 	lcall	__gptrput
                           001811  5110 	C$fuzzy.h$2420$1_0$90 ==.
                                   5111 ;	../../fuzzy.h:2420: return true;
      0018CE 75 82 01         [24] 5112 	mov	dpl, #0x01
      0018D1                       5113 00106$:
                           001814  5114 	C$fuzzy.h$2421$1_0$90 ==.
                                   5115 ;	../../fuzzy.h:2421: }
      0018D1 85 08 81         [24] 5116 	mov	sp,_bp
      0018D4 D0 08            [24] 5117 	pop	_bp
                           001819  5118 	C$fuzzy.h$2421$1_0$90 ==.
                           001819  5119 	XG$fuzzy_rules_add$0$0 ==.
      0018D6 22               [24] 5120 	ret
                                   5121 ;------------------------------------------------------------
                                   5122 ;Allocation info for local variables in function 'fuzzy_implication'
                                   5123 ;------------------------------------------------------------
                                   5124 ;activation    Allocated to stack - _bp -6 +4 
                                   5125 ;membership    Allocated to stack - _bp -10 +4 
                                   5126 ;method        Allocated to registers r7 
                                   5127 ;sloc0         Allocated to stack - _bp +1 +4 
                                   5128 ;sloc1         Allocated to stack - _bp +5 +4 
                                   5129 ;------------------------------------------------------------
                           00181A  5130 	Fsugeno_demo$fuzzy_implication$0$0 ==.
                           00181A  5131 	C$fuzzy.h$2454$1_0$94 ==.
                                   5132 ;	../../fuzzy.h:2454: static float fuzzy_implication(
                                   5133 ;	-----------------------------------------
                                   5134 ;	 function fuzzy_implication
                                   5135 ;	-----------------------------------------
      0018D7                       5136 _fuzzy_implication:
      0018D7 C0 08            [24] 5137 	push	_bp
      0018D9 E5 81            [12] 5138 	mov	a,sp
      0018DB F5 08            [12] 5139 	mov	_bp,a
      0018DD 24 08            [12] 5140 	add	a,#0x08
      0018DF F5 81            [12] 5141 	mov	sp,a
      0018E1 AF 82            [24] 5142 	mov	r7, dpl
                           001826  5143 	C$fuzzy.h$2460$1_0$94 ==.
                                   5144 ;	../../fuzzy.h:2460: activation = fuzzy_clamp(activation);
      0018E3 E5 08            [12] 5145 	mov	a,_bp
      0018E5 24 FA            [12] 5146 	add	a,#0xfa
      0018E7 F8               [12] 5147 	mov	r0,a
      0018E8 86 82            [24] 5148 	mov	dpl, @r0
      0018EA 08               [12] 5149 	inc	r0
      0018EB 86 83            [24] 5150 	mov	dph, @r0
      0018ED 08               [12] 5151 	inc	r0
      0018EE 86 F0            [24] 5152 	mov	b, @r0
      0018F0 08               [12] 5153 	inc	r0
      0018F1 E6               [12] 5154 	mov	a, @r0
      0018F2 C0 07            [24] 5155 	push	ar7
      0018F4 12 00 F0         [24] 5156 	lcall	_fuzzy_clamp
      0018F7 AB 82            [24] 5157 	mov	r3, dpl
      0018F9 AC 83            [24] 5158 	mov	r4, dph
      0018FB AD F0            [24] 5159 	mov	r5, b
      0018FD FE               [12] 5160 	mov	r6, a
                           001841  5161 	C$fuzzy.h$2461$1_0$94 ==.
                                   5162 ;	../../fuzzy.h:2461: membership = fuzzy_clamp(membership);
      0018FE E5 08            [12] 5163 	mov	a,_bp
      001900 24 F6            [12] 5164 	add	a,#0xf6
      001902 F8               [12] 5165 	mov	r0,a
      001903 86 82            [24] 5166 	mov	dpl, @r0
      001905 08               [12] 5167 	inc	r0
      001906 86 83            [24] 5168 	mov	dph, @r0
      001908 08               [12] 5169 	inc	r0
      001909 86 F0            [24] 5170 	mov	b, @r0
      00190B 08               [12] 5171 	inc	r0
      00190C E6               [12] 5172 	mov	a, @r0
      00190D C0 06            [24] 5173 	push	ar6
      00190F C0 05            [24] 5174 	push	ar5
      001911 C0 04            [24] 5175 	push	ar4
      001913 C0 03            [24] 5176 	push	ar3
      001915 12 00 F0         [24] 5177 	lcall	_fuzzy_clamp
      001918 A8 08            [24] 5178 	mov	r0,_bp
      00191A 08               [12] 5179 	inc	r0
      00191B A6 82            [24] 5180 	mov	@r0, dpl
      00191D 08               [12] 5181 	inc	r0
      00191E A6 83            [24] 5182 	mov	@r0, dph
      001920 08               [12] 5183 	inc	r0
      001921 A6 F0            [24] 5184 	mov	@r0, b
      001923 08               [12] 5185 	inc	r0
      001924 F6               [12] 5186 	mov	@r0,a
      001925 D0 03            [24] 5187 	pop	ar3
      001927 D0 04            [24] 5188 	pop	ar4
      001929 D0 05            [24] 5189 	pop	ar5
      00192B D0 06            [24] 5190 	pop	ar6
      00192D D0 07            [24] 5191 	pop	ar7
                           001872  5192 	C$fuzzy.h$2463$1_0$94 ==.
                                   5193 ;	../../fuzzy.h:2463: switch (method) {
      00192F BF 00 02         [24] 5194 	cjne	r7,#0x00,00127$
      001932 80 08            [24] 5195 	sjmp	00101$
      001934                       5196 00127$:
      001934 BF 01 02         [24] 5197 	cjne	r7,#0x01,00128$
      001937 80 73            [24] 5198 	sjmp	00102$
      001939                       5199 00128$:
      001939 02 19 DE         [24] 5200 	ljmp	00103$
                           00187F  5201 	C$fuzzy.h$2464$2_0$95 ==.
                                   5202 ;	../../fuzzy.h:2464: case FUZZY_IMPLICATION_MIN:
      00193C                       5203 00101$:
                           00187F  5204 	C$fuzzy.h$2466$1_0$94 ==.
                                   5205 ;	../../fuzzy.h:2466: ? activation
      00193C C0 06            [24] 5206 	push	ar6
      00193E C0 05            [24] 5207 	push	ar5
      001940 C0 04            [24] 5208 	push	ar4
      001942 C0 03            [24] 5209 	push	ar3
      001944 A8 08            [24] 5210 	mov	r0,_bp
      001946 08               [12] 5211 	inc	r0
      001947 E6               [12] 5212 	mov	a,@r0
      001948 C0 E0            [24] 5213 	push	acc
      00194A 08               [12] 5214 	inc	r0
      00194B E6               [12] 5215 	mov	a,@r0
      00194C C0 E0            [24] 5216 	push	acc
      00194E 08               [12] 5217 	inc	r0
      00194F E6               [12] 5218 	mov	a,@r0
      001950 C0 E0            [24] 5219 	push	acc
      001952 08               [12] 5220 	inc	r0
      001953 E6               [12] 5221 	mov	a,@r0
      001954 C0 E0            [24] 5222 	push	acc
      001956 8B 82            [24] 5223 	mov	dpl, r3
      001958 8C 83            [24] 5224 	mov	dph, r4
      00195A 8D F0            [24] 5225 	mov	b, r5
      00195C EE               [12] 5226 	mov	a, r6
      00195D 12 41 7C         [24] 5227 	lcall	___fslt
      001960 AF 82            [24] 5228 	mov	r7, dpl
      001962 E5 81            [12] 5229 	mov	a,sp
      001964 24 FC            [12] 5230 	add	a,#0xfc
      001966 F5 81            [12] 5231 	mov	sp,a
      001968 D0 03            [24] 5232 	pop	ar3
      00196A D0 04            [24] 5233 	pop	ar4
      00196C D0 05            [24] 5234 	pop	ar5
      00196E D0 06            [24] 5235 	pop	ar6
      001970 EF               [12] 5236 	mov	a,r7
      001971 60 12            [24] 5237 	jz	00107$
      001973 E5 08            [12] 5238 	mov	a,_bp
      001975 24 05            [12] 5239 	add	a,#0x05
      001977 F8               [12] 5240 	mov	r0,a
      001978 A6 03            [24] 5241 	mov	@r0,ar3
      00197A 08               [12] 5242 	inc	r0
      00197B A6 04            [24] 5243 	mov	@r0,ar4
      00197D 08               [12] 5244 	inc	r0
      00197E A6 05            [24] 5245 	mov	@r0,ar5
      001980 08               [12] 5246 	inc	r0
      001981 A6 06            [24] 5247 	mov	@r0,ar6
      001983 80 16            [24] 5248 	sjmp	00108$
      001985                       5249 00107$:
                           0018C8  5250 	C$fuzzy.h$2467$2_0$95 ==.
                                   5251 ;	../../fuzzy.h:2467: : membership;
      001985 A8 08            [24] 5252 	mov	r0,_bp
      001987 08               [12] 5253 	inc	r0
      001988 E5 08            [12] 5254 	mov	a,_bp
      00198A 24 05            [12] 5255 	add	a,#0x05
      00198C F9               [12] 5256 	mov	r1,a
      00198D E6               [12] 5257 	mov	a,@r0
      00198E F7               [12] 5258 	mov	@r1,a
      00198F 08               [12] 5259 	inc	r0
      001990 E6               [12] 5260 	mov	a,@r0
      001991 09               [12] 5261 	inc	r1
      001992 F7               [12] 5262 	mov	@r1,a
      001993 08               [12] 5263 	inc	r0
      001994 E6               [12] 5264 	mov	a,@r0
      001995 09               [12] 5265 	inc	r1
      001996 F7               [12] 5266 	mov	@r1,a
      001997 08               [12] 5267 	inc	r0
      001998 E6               [12] 5268 	mov	a,@r0
      001999 09               [12] 5269 	inc	r1
      00199A F7               [12] 5270 	mov	@r1,a
      00199B                       5271 00108$:
      00199B E5 08            [12] 5272 	mov	a,_bp
      00199D 24 05            [12] 5273 	add	a,#0x05
      00199F F8               [12] 5274 	mov	r0,a
      0019A0 86 82            [24] 5275 	mov	dpl, @r0
      0019A2 08               [12] 5276 	inc	r0
      0019A3 86 83            [24] 5277 	mov	dph, @r0
      0019A5 08               [12] 5278 	inc	r0
      0019A6 86 F0            [24] 5279 	mov	b, @r0
      0019A8 08               [12] 5280 	inc	r0
      0019A9 E6               [12] 5281 	mov	a, @r0
                           0018ED  5282 	C$fuzzy.h$2469$2_0$95 ==.
                                   5283 ;	../../fuzzy.h:2469: case FUZZY_IMPLICATION_PRODUCT:
      0019AA 80 38            [24] 5284 	sjmp	00105$
      0019AC                       5285 00102$:
                           0018EF  5286 	C$fuzzy.h$2470$1_0$94 ==.
                                   5287 ;	../../fuzzy.h:2470: return activation * membership;
      0019AC A8 08            [24] 5288 	mov	r0,_bp
      0019AE 08               [12] 5289 	inc	r0
      0019AF E6               [12] 5290 	mov	a,@r0
      0019B0 C0 E0            [24] 5291 	push	acc
      0019B2 08               [12] 5292 	inc	r0
      0019B3 E6               [12] 5293 	mov	a,@r0
      0019B4 C0 E0            [24] 5294 	push	acc
      0019B6 08               [12] 5295 	inc	r0
      0019B7 E6               [12] 5296 	mov	a,@r0
      0019B8 C0 E0            [24] 5297 	push	acc
      0019BA 08               [12] 5298 	inc	r0
      0019BB E6               [12] 5299 	mov	a,@r0
      0019BC C0 E0            [24] 5300 	push	acc
      0019BE 8B 82            [24] 5301 	mov	dpl, r3
      0019C0 8C 83            [24] 5302 	mov	dph, r4
      0019C2 8D F0            [24] 5303 	mov	b, r5
      0019C4 EE               [12] 5304 	mov	a, r6
      0019C5 12 40 4C         [24] 5305 	lcall	___fsmul
      0019C8 AC 82            [24] 5306 	mov	r4, dpl
      0019CA AD 83            [24] 5307 	mov	r5, dph
      0019CC AE F0            [24] 5308 	mov	r6, b
      0019CE FF               [12] 5309 	mov	r7, a
      0019CF E5 81            [12] 5310 	mov	a,sp
      0019D1 24 FC            [12] 5311 	add	a,#0xfc
      0019D3 F5 81            [12] 5312 	mov	sp,a
      0019D5 8C 82            [24] 5313 	mov	dpl, r4
      0019D7 8D 83            [24] 5314 	mov	dph, r5
      0019D9 8E F0            [24] 5315 	mov	b, r6
      0019DB EF               [12] 5316 	mov	a, r7
                           00191F  5317 	C$fuzzy.h$2472$2_0$95 ==.
                                   5318 ;	../../fuzzy.h:2472: default:
      0019DC 80 06            [24] 5319 	sjmp	00105$
      0019DE                       5320 00103$:
                           001921  5321 	C$fuzzy.h$2473$2_0$95 ==.
                                   5322 ;	../../fuzzy.h:2473: return LEVEL_LO;
      0019DE 90 00 00         [24] 5323 	mov	dptr,#0x0000
      0019E1 E4               [12] 5324 	clr	a
      0019E2 F5 F0            [12] 5325 	mov	b,a
                           001927  5326 	C$fuzzy.h$2474$1_0$94 ==.
                                   5327 ;	../../fuzzy.h:2474: }
      0019E4                       5328 00105$:
                           001927  5329 	C$fuzzy.h$2475$1_0$94 ==.
                                   5330 ;	../../fuzzy.h:2475: }
      0019E4 85 08 81         [24] 5331 	mov	sp,_bp
      0019E7 D0 08            [24] 5332 	pop	_bp
                           00192C  5333 	C$fuzzy.h$2475$1_0$94 ==.
                           00192C  5334 	XFsugeno_demo$fuzzy_implication$0$0 ==.
      0019E9 22               [24] 5335 	ret
                                   5336 ;------------------------------------------------------------
                                   5337 ;Allocation info for local variables in function 'fuzzy_aggregation'
                                   5338 ;------------------------------------------------------------
                                   5339 ;aggregated    Allocated to stack - _bp -6 +4 
                                   5340 ;implied       Allocated to stack - _bp -10 +4 
                                   5341 ;method        Allocated to registers r7 
                                   5342 ;sloc0         Allocated to stack - _bp +1 +4 
                                   5343 ;sloc1         Allocated to stack - _bp +5 +4 
                                   5344 ;sloc2         Allocated to stack - _bp +10 +4 
                                   5345 ;------------------------------------------------------------
                           00192D  5346 	Fsugeno_demo$fuzzy_aggregation$0$0 ==.
                           00192D  5347 	C$fuzzy.h$2477$1_0$97 ==.
                                   5348 ;	../../fuzzy.h:2477: static float fuzzy_aggregation(
                                   5349 ;	-----------------------------------------
                                   5350 ;	 function fuzzy_aggregation
                                   5351 ;	-----------------------------------------
      0019EA                       5352 _fuzzy_aggregation:
      0019EA C0 08            [24] 5353 	push	_bp
      0019EC E5 81            [12] 5354 	mov	a,sp
      0019EE F5 08            [12] 5355 	mov	_bp,a
      0019F0 24 08            [12] 5356 	add	a,#0x08
      0019F2 F5 81            [12] 5357 	mov	sp,a
      0019F4 AF 82            [24] 5358 	mov	r7, dpl
                           001939  5359 	C$fuzzy.h$2483$1_0$97 ==.
                                   5360 ;	../../fuzzy.h:2483: aggregated = fuzzy_clamp(aggregated);
      0019F6 E5 08            [12] 5361 	mov	a,_bp
      0019F8 24 FA            [12] 5362 	add	a,#0xfa
      0019FA F8               [12] 5363 	mov	r0,a
      0019FB 86 82            [24] 5364 	mov	dpl, @r0
      0019FD 08               [12] 5365 	inc	r0
      0019FE 86 83            [24] 5366 	mov	dph, @r0
      001A00 08               [12] 5367 	inc	r0
      001A01 86 F0            [24] 5368 	mov	b, @r0
      001A03 08               [12] 5369 	inc	r0
      001A04 E6               [12] 5370 	mov	a, @r0
      001A05 C0 07            [24] 5371 	push	ar7
      001A07 12 00 F0         [24] 5372 	lcall	_fuzzy_clamp
      001A0A AE 82            [24] 5373 	mov	r6, dpl
      001A0C AD 83            [24] 5374 	mov	r5, dph
      001A0E AC F0            [24] 5375 	mov	r4, b
      001A10 FB               [12] 5376 	mov	r3, a
                           001954  5377 	C$fuzzy.h$2484$1_0$97 ==.
                                   5378 ;	../../fuzzy.h:2484: implied = fuzzy_clamp(implied);
      001A11 E5 08            [12] 5379 	mov	a,_bp
      001A13 24 F6            [12] 5380 	add	a,#0xf6
      001A15 F8               [12] 5381 	mov	r0,a
      001A16 86 82            [24] 5382 	mov	dpl, @r0
      001A18 08               [12] 5383 	inc	r0
      001A19 86 83            [24] 5384 	mov	dph, @r0
      001A1B 08               [12] 5385 	inc	r0
      001A1C 86 F0            [24] 5386 	mov	b, @r0
      001A1E 08               [12] 5387 	inc	r0
      001A1F E6               [12] 5388 	mov	a, @r0
      001A20 C0 06            [24] 5389 	push	ar6
      001A22 C0 05            [24] 5390 	push	ar5
      001A24 C0 04            [24] 5391 	push	ar4
      001A26 C0 03            [24] 5392 	push	ar3
      001A28 12 00 F0         [24] 5393 	lcall	_fuzzy_clamp
      001A2B A8 08            [24] 5394 	mov	r0,_bp
      001A2D 08               [12] 5395 	inc	r0
      001A2E A6 82            [24] 5396 	mov	@r0, dpl
      001A30 08               [12] 5397 	inc	r0
      001A31 A6 83            [24] 5398 	mov	@r0, dph
      001A33 08               [12] 5399 	inc	r0
      001A34 A6 F0            [24] 5400 	mov	@r0, b
      001A36 08               [12] 5401 	inc	r0
      001A37 F6               [12] 5402 	mov	@r0,a
      001A38 D0 03            [24] 5403 	pop	ar3
      001A3A D0 04            [24] 5404 	pop	ar4
      001A3C D0 05            [24] 5405 	pop	ar5
      001A3E D0 06            [24] 5406 	pop	ar6
      001A40 D0 07            [24] 5407 	pop	ar7
                           001985  5408 	C$fuzzy.h$2486$1_0$97 ==.
                                   5409 ;	../../fuzzy.h:2486: switch (method) {
      001A42 BF 00 02         [24] 5410 	cjne	r7,#0x00,00134$
      001A45 80 0E            [24] 5411 	sjmp	00101$
      001A47                       5412 00134$:
      001A47 BF 01 02         [24] 5413 	cjne	r7,#0x01,00135$
      001A4A 80 76            [24] 5414 	sjmp	00102$
      001A4C                       5415 00135$:
      001A4C BF 02 03         [24] 5416 	cjne	r7,#0x02,00136$
      001A4F 02 1B 5D         [24] 5417 	ljmp	00103$
      001A52                       5418 00136$:
      001A52 02 1B 92         [24] 5419 	ljmp	00104$
                           001998  5420 	C$fuzzy.h$2487$2_0$98 ==.
                                   5421 ;	../../fuzzy.h:2487: case FUZZY_AGGREGATION_MAX:
      001A55                       5422 00101$:
                           001998  5423 	C$fuzzy.h$2489$1_0$97 ==.
                                   5424 ;	../../fuzzy.h:2489: ? aggregated
      001A55 C0 06            [24] 5425 	push	ar6
      001A57 C0 05            [24] 5426 	push	ar5
      001A59 C0 04            [24] 5427 	push	ar4
      001A5B C0 03            [24] 5428 	push	ar3
      001A5D C0 06            [24] 5429 	push	ar6
      001A5F C0 05            [24] 5430 	push	ar5
      001A61 C0 04            [24] 5431 	push	ar4
      001A63 C0 03            [24] 5432 	push	ar3
      001A65 A8 08            [24] 5433 	mov	r0,_bp
      001A67 08               [12] 5434 	inc	r0
      001A68 86 82            [24] 5435 	mov	dpl, @r0
      001A6A 08               [12] 5436 	inc	r0
      001A6B 86 83            [24] 5437 	mov	dph, @r0
      001A6D 08               [12] 5438 	inc	r0
      001A6E 86 F0            [24] 5439 	mov	b, @r0
      001A70 08               [12] 5440 	inc	r0
      001A71 E6               [12] 5441 	mov	a, @r0
      001A72 12 41 7C         [24] 5442 	lcall	___fslt
      001A75 AF 82            [24] 5443 	mov	r7, dpl
      001A77 E5 81            [12] 5444 	mov	a,sp
      001A79 24 FC            [12] 5445 	add	a,#0xfc
      001A7B F5 81            [12] 5446 	mov	sp,a
      001A7D D0 03            [24] 5447 	pop	ar3
      001A7F D0 04            [24] 5448 	pop	ar4
      001A81 D0 05            [24] 5449 	pop	ar5
      001A83 D0 06            [24] 5450 	pop	ar6
      001A85 EF               [12] 5451 	mov	a,r7
      001A86 60 12            [24] 5452 	jz	00108$
      001A88 E5 08            [12] 5453 	mov	a,_bp
      001A8A 24 05            [12] 5454 	add	a,#0x05
      001A8C F8               [12] 5455 	mov	r0,a
      001A8D A6 06            [24] 5456 	mov	@r0,ar6
      001A8F 08               [12] 5457 	inc	r0
      001A90 A6 05            [24] 5458 	mov	@r0,ar5
      001A92 08               [12] 5459 	inc	r0
      001A93 A6 04            [24] 5460 	mov	@r0,ar4
      001A95 08               [12] 5461 	inc	r0
      001A96 A6 03            [24] 5462 	mov	@r0,ar3
      001A98 80 16            [24] 5463 	sjmp	00109$
      001A9A                       5464 00108$:
                           0019DD  5465 	C$fuzzy.h$2490$2_0$98 ==.
                                   5466 ;	../../fuzzy.h:2490: : implied;
      001A9A A8 08            [24] 5467 	mov	r0,_bp
      001A9C 08               [12] 5468 	inc	r0
      001A9D E5 08            [12] 5469 	mov	a,_bp
      001A9F 24 05            [12] 5470 	add	a,#0x05
      001AA1 F9               [12] 5471 	mov	r1,a
      001AA2 E6               [12] 5472 	mov	a,@r0
      001AA3 F7               [12] 5473 	mov	@r1,a
      001AA4 08               [12] 5474 	inc	r0
      001AA5 E6               [12] 5475 	mov	a,@r0
      001AA6 09               [12] 5476 	inc	r1
      001AA7 F7               [12] 5477 	mov	@r1,a
      001AA8 08               [12] 5478 	inc	r0
      001AA9 E6               [12] 5479 	mov	a,@r0
      001AAA 09               [12] 5480 	inc	r1
      001AAB F7               [12] 5481 	mov	@r1,a
      001AAC 08               [12] 5482 	inc	r0
      001AAD E6               [12] 5483 	mov	a,@r0
      001AAE 09               [12] 5484 	inc	r1
      001AAF F7               [12] 5485 	mov	@r1,a
      001AB0                       5486 00109$:
      001AB0 E5 08            [12] 5487 	mov	a,_bp
      001AB2 24 05            [12] 5488 	add	a,#0x05
      001AB4 F8               [12] 5489 	mov	r0,a
      001AB5 86 82            [24] 5490 	mov	dpl, @r0
      001AB7 08               [12] 5491 	inc	r0
      001AB8 86 83            [24] 5492 	mov	dph, @r0
      001ABA 08               [12] 5493 	inc	r0
      001ABB 86 F0            [24] 5494 	mov	b, @r0
      001ABD 08               [12] 5495 	inc	r0
      001ABE E6               [12] 5496 	mov	a, @r0
      001ABF 02 1B 98         [24] 5497 	ljmp	00106$
                           001A05  5498 	C$fuzzy.h$2492$2_0$98 ==.
                                   5499 ;	../../fuzzy.h:2492: case FUZZY_AGGREGATION_ALGEBRAIC:
      001AC2                       5500 00102$:
                           001A05  5501 	C$fuzzy.h$2494$1_0$97 ==.
                                   5502 ;	../../fuzzy.h:2494: implied -
      001AC2 C0 06            [24] 5503 	push	ar6
      001AC4 C0 05            [24] 5504 	push	ar5
      001AC6 C0 04            [24] 5505 	push	ar4
      001AC8 C0 03            [24] 5506 	push	ar3
      001ACA A8 08            [24] 5507 	mov	r0,_bp
      001ACC 08               [12] 5508 	inc	r0
      001ACD E6               [12] 5509 	mov	a,@r0
      001ACE C0 E0            [24] 5510 	push	acc
      001AD0 08               [12] 5511 	inc	r0
      001AD1 E6               [12] 5512 	mov	a,@r0
      001AD2 C0 E0            [24] 5513 	push	acc
      001AD4 08               [12] 5514 	inc	r0
      001AD5 E6               [12] 5515 	mov	a,@r0
      001AD6 C0 E0            [24] 5516 	push	acc
      001AD8 08               [12] 5517 	inc	r0
      001AD9 E6               [12] 5518 	mov	a,@r0
      001ADA C0 E0            [24] 5519 	push	acc
                           001A1F  5520 	C$fuzzy.h$2495$1_0$97 ==.
                                   5521 ;	../../fuzzy.h:2495: aggregated * implied;
      001ADC 8E 82            [24] 5522 	mov	dpl, r6
      001ADE 8D 83            [24] 5523 	mov	dph, r5
      001AE0 8C F0            [24] 5524 	mov	b, r4
      001AE2 EB               [12] 5525 	mov	a, r3
      001AE3 12 41 CE         [24] 5526 	lcall	___fsadd
      001AE6 C8               [12] 5527 	xch	a,r0
      001AE7 E5 08            [12] 5528 	mov	a,_bp
      001AE9 24 05            [12] 5529 	add	a,#0x05
      001AEB C8               [12] 5530 	xch	a,r0
      001AEC A6 82            [24] 5531 	mov	@r0, dpl
      001AEE 08               [12] 5532 	inc	r0
      001AEF A6 83            [24] 5533 	mov	@r0, dph
      001AF1 08               [12] 5534 	inc	r0
      001AF2 A6 F0            [24] 5535 	mov	@r0, b
      001AF4 08               [12] 5536 	inc	r0
      001AF5 F6               [12] 5537 	mov	@r0,a
      001AF6 E5 81            [12] 5538 	mov	a,sp
      001AF8 24 FC            [12] 5539 	add	a,#0xfc
      001AFA F5 81            [12] 5540 	mov	sp,a
      001AFC D0 03            [24] 5541 	pop	ar3
      001AFE D0 04            [24] 5542 	pop	ar4
      001B00 D0 05            [24] 5543 	pop	ar5
      001B02 D0 06            [24] 5544 	pop	ar6
      001B04 A8 08            [24] 5545 	mov	r0,_bp
      001B06 08               [12] 5546 	inc	r0
      001B07 E6               [12] 5547 	mov	a,@r0
      001B08 C0 E0            [24] 5548 	push	acc
      001B0A 08               [12] 5549 	inc	r0
      001B0B E6               [12] 5550 	mov	a,@r0
      001B0C C0 E0            [24] 5551 	push	acc
      001B0E 08               [12] 5552 	inc	r0
      001B0F E6               [12] 5553 	mov	a,@r0
      001B10 C0 E0            [24] 5554 	push	acc
      001B12 08               [12] 5555 	inc	r0
      001B13 E6               [12] 5556 	mov	a,@r0
      001B14 C0 E0            [24] 5557 	push	acc
      001B16 8E 82            [24] 5558 	mov	dpl, r6
      001B18 8D 83            [24] 5559 	mov	dph, r5
      001B1A 8C F0            [24] 5560 	mov	b, r4
      001B1C EB               [12] 5561 	mov	a, r3
      001B1D 12 40 4C         [24] 5562 	lcall	___fsmul
      001B20 AB 82            [24] 5563 	mov	r3, dpl
      001B22 AC 83            [24] 5564 	mov	r4, dph
      001B24 AE F0            [24] 5565 	mov	r6, b
      001B26 FF               [12] 5566 	mov	r7, a
      001B27 E5 81            [12] 5567 	mov	a,sp
      001B29 24 FC            [12] 5568 	add	a,#0xfc
      001B2B F5 81            [12] 5569 	mov	sp,a
      001B2D C0 03            [24] 5570 	push	ar3
      001B2F C0 04            [24] 5571 	push	ar4
      001B31 C0 06            [24] 5572 	push	ar6
      001B33 C0 07            [24] 5573 	push	ar7
      001B35 E5 08            [12] 5574 	mov	a,_bp
      001B37 24 05            [12] 5575 	add	a,#0x05
      001B39 F8               [12] 5576 	mov	r0,a
      001B3A 86 82            [24] 5577 	mov	dpl, @r0
      001B3C 08               [12] 5578 	inc	r0
      001B3D 86 83            [24] 5579 	mov	dph, @r0
      001B3F 08               [12] 5580 	inc	r0
      001B40 86 F0            [24] 5581 	mov	b, @r0
      001B42 08               [12] 5582 	inc	r0
      001B43 E6               [12] 5583 	mov	a, @r0
      001B44 12 40 41         [24] 5584 	lcall	___fssub
      001B47 AC 82            [24] 5585 	mov	r4, dpl
      001B49 AD 83            [24] 5586 	mov	r5, dph
      001B4B AE F0            [24] 5587 	mov	r6, b
      001B4D FF               [12] 5588 	mov	r7, a
      001B4E E5 81            [12] 5589 	mov	a,sp
      001B50 24 FC            [12] 5590 	add	a,#0xfc
      001B52 F5 81            [12] 5591 	mov	sp,a
      001B54 8C 82            [24] 5592 	mov	dpl, r4
      001B56 8D 83            [24] 5593 	mov	dph, r5
      001B58 8E F0            [24] 5594 	mov	b, r6
      001B5A EF               [12] 5595 	mov	a, r7
                           001A9E  5596 	C$fuzzy.h$2497$2_0$98 ==.
                                   5597 ;	../../fuzzy.h:2497: case FUZZY_AGGREGATION_BOUNDED:
      001B5B 80 3B            [24] 5598 	sjmp	00106$
      001B5D                       5599 00103$:
                           001AA0  5600 	C$fuzzy.h$2501$1_0$97 ==.
                                   5601 ;	../../fuzzy.h:2501: );
      001B5D A8 08            [24] 5602 	mov	r0,_bp
      001B5F 08               [12] 5603 	inc	r0
      001B60 E6               [12] 5604 	mov	a,@r0
      001B61 C0 E0            [24] 5605 	push	acc
      001B63 08               [12] 5606 	inc	r0
      001B64 E6               [12] 5607 	mov	a,@r0
      001B65 C0 E0            [24] 5608 	push	acc
      001B67 08               [12] 5609 	inc	r0
      001B68 E6               [12] 5610 	mov	a,@r0
      001B69 C0 E0            [24] 5611 	push	acc
      001B6B 08               [12] 5612 	inc	r0
      001B6C E6               [12] 5613 	mov	a,@r0
      001B6D C0 E0            [24] 5614 	push	acc
      001B6F 8E 82            [24] 5615 	mov	dpl, r6
      001B71 8D 83            [24] 5616 	mov	dph, r5
      001B73 8C F0            [24] 5617 	mov	b, r4
      001B75 EB               [12] 5618 	mov	a, r3
      001B76 12 41 CE         [24] 5619 	lcall	___fsadd
      001B79 AC 82            [24] 5620 	mov	r4, dpl
      001B7B AD 83            [24] 5621 	mov	r5, dph
      001B7D AE F0            [24] 5622 	mov	r6, b
      001B7F FF               [12] 5623 	mov	r7, a
      001B80 E5 81            [12] 5624 	mov	a,sp
      001B82 24 FC            [12] 5625 	add	a,#0xfc
      001B84 F5 81            [12] 5626 	mov	sp,a
      001B86 8C 82            [24] 5627 	mov	dpl, r4
      001B88 8D 83            [24] 5628 	mov	dph, r5
      001B8A 8E F0            [24] 5629 	mov	b, r6
      001B8C EF               [12] 5630 	mov	a, r7
      001B8D 12 00 F0         [24] 5631 	lcall	_fuzzy_clamp
                           001AD3  5632 	C$fuzzy.h$2503$2_0$98 ==.
                                   5633 ;	../../fuzzy.h:2503: default:
      001B90 80 06            [24] 5634 	sjmp	00106$
      001B92                       5635 00104$:
                           001AD5  5636 	C$fuzzy.h$2504$2_0$98 ==.
                                   5637 ;	../../fuzzy.h:2504: return LEVEL_LO;
      001B92 90 00 00         [24] 5638 	mov	dptr,#0x0000
      001B95 E4               [12] 5639 	clr	a
      001B96 F5 F0            [12] 5640 	mov	b,a
                           001ADB  5641 	C$fuzzy.h$2505$1_0$97 ==.
                                   5642 ;	../../fuzzy.h:2505: }
      001B98                       5643 00106$:
                           001ADB  5644 	C$fuzzy.h$2506$1_0$97 ==.
                                   5645 ;	../../fuzzy.h:2506: }
      001B98 85 08 81         [24] 5646 	mov	sp,_bp
      001B9B D0 08            [24] 5647 	pop	_bp
                           001AE0  5648 	C$fuzzy.h$2506$1_0$97 ==.
                           001AE0  5649 	XFsugeno_demo$fuzzy_aggregation$0$0 ==.
      001B9D 22               [24] 5650 	ret
                                   5651 ;------------------------------------------------------------
                                   5652 ;Allocation info for local variables in function 'fuzzy_rules_aggregated_height'
                                   5653 ;------------------------------------------------------------
                                   5654 ;value         Allocated to stack - _bp -6 +4 
                                   5655 ;implication_method Allocated to stack - _bp -7 +1 
                                   5656 ;aggregation_method Allocated to stack - _bp -8 +1 
                                   5657 ;rules         Allocated to stack - _bp +1 +3 
                                   5658 ;aggregated_height Allocated to stack - _bp +12 +4 
                                   5659 ;output_membership Allocated to stack - _bp +16 +4 
                                   5660 ;implied_height Allocated to registers r4 r5 r6 r7 
                                   5661 ;index         Allocated to stack - _bp +20 +2 
                                   5662 ;sloc0         Allocated to stack - _bp +4 +3 
                                   5663 ;sloc1         Allocated to stack - _bp +7 +2 
                                   5664 ;sloc2         Allocated to stack - _bp +9 +3 
                                   5665 ;------------------------------------------------------------
                           001AE1  5666 	Fsugeno_demo$fuzzy_rules_aggregated_height$0$0 ==.
                           001AE1  5667 	C$fuzzy.h$2512$1_0$100 ==.
                                   5668 ;	../../fuzzy.h:2512: static float fuzzy_rules_aggregated_height(
                                   5669 ;	-----------------------------------------
                                   5670 ;	 function fuzzy_rules_aggregated_height
                                   5671 ;	-----------------------------------------
      001B9E                       5672 _fuzzy_rules_aggregated_height:
      001B9E C0 08            [24] 5673 	push	_bp
      001BA0 85 81 08         [24] 5674 	mov	_bp,sp
      001BA3 C0 82            [24] 5675 	push	dpl
      001BA5 C0 83            [24] 5676 	push	dph
      001BA7 C0 F0            [24] 5677 	push	b
      001BA9 E5 81            [12] 5678 	mov	a,sp
      001BAB 24 12            [12] 5679 	add	a,#0x12
      001BAD F5 81            [12] 5680 	mov	sp,a
                           001AF2  5681 	C$fuzzy.h$2525$1_0$100 ==.
                                   5682 ;	../../fuzzy.h:2525: LEVEL_LO;
      001BAF E5 08            [12] 5683 	mov	a,_bp
      001BB1 24 0C            [12] 5684 	add	a,#0x0c
      001BB3 F8               [12] 5685 	mov	r0,a
      001BB4 E4               [12] 5686 	clr	a
      001BB5 F6               [12] 5687 	mov	@r0,a
      001BB6 08               [12] 5688 	inc	r0
      001BB7 F6               [12] 5689 	mov	@r0,a
      001BB8 08               [12] 5690 	inc	r0
      001BB9 F6               [12] 5691 	mov	@r0,a
      001BBA 08               [12] 5692 	inc	r0
      001BBB F6               [12] 5693 	mov	@r0,a
                           001AFF  5694 	C$fuzzy.h$2528$3_0$102 ==.
                                   5695 ;	../../fuzzy.h:2528: index = 0u;
      001BBC A8 08            [24] 5696 	mov	r0,_bp
      001BBE 08               [12] 5697 	inc	r0
      001BBF E5 08            [12] 5698 	mov	a,_bp
      001BC1 24 09            [12] 5699 	add	a,#0x09
      001BC3 F9               [12] 5700 	mov	r1,a
      001BC4 E6               [12] 5701 	mov	a,@r0
      001BC5 F7               [12] 5702 	mov	@r1,a
      001BC6 08               [12] 5703 	inc	r0
      001BC7 E6               [12] 5704 	mov	a,@r0
      001BC8 09               [12] 5705 	inc	r1
      001BC9 F7               [12] 5706 	mov	@r1,a
      001BCA 08               [12] 5707 	inc	r0
      001BCB E6               [12] 5708 	mov	a,@r0
      001BCC 09               [12] 5709 	inc	r1
      001BCD F7               [12] 5710 	mov	@r1,a
      001BCE A8 08            [24] 5711 	mov	r0,_bp
      001BD0 08               [12] 5712 	inc	r0
      001BD1 E5 08            [12] 5713 	mov	a,_bp
      001BD3 24 04            [12] 5714 	add	a,#0x04
      001BD5 F9               [12] 5715 	mov	r1,a
      001BD6 74 90            [12] 5716 	mov	a,#0x90
      001BD8 26               [12] 5717 	add	a, @r0
      001BD9 F7               [12] 5718 	mov	@r1,a
      001BDA E4               [12] 5719 	clr	a
      001BDB 08               [12] 5720 	inc	r0
      001BDC 36               [12] 5721 	addc	a, @r0
      001BDD 09               [12] 5722 	inc	r1
      001BDE F7               [12] 5723 	mov	@r1,a
      001BDF 08               [12] 5724 	inc	r0
      001BE0 E6               [12] 5725 	mov	a,@r0
      001BE1 09               [12] 5726 	inc	r1
      001BE2 F7               [12] 5727 	mov	@r1,a
      001BE3 E5 08            [12] 5728 	mov	a,_bp
      001BE5 24 14            [12] 5729 	add	a,#0x14
      001BE7 F8               [12] 5730 	mov	r0,a
      001BE8 E4               [12] 5731 	clr	a
      001BE9 F6               [12] 5732 	mov	@r0,a
      001BEA 08               [12] 5733 	inc	r0
      001BEB F6               [12] 5734 	mov	@r0,a
      001BEC E5 08            [12] 5735 	mov	a,_bp
      001BEE 24 07            [12] 5736 	add	a,#0x07
      001BF0 F8               [12] 5737 	mov	r0,a
      001BF1 E4               [12] 5738 	clr	a
      001BF2 F6               [12] 5739 	mov	@r0,a
      001BF3 08               [12] 5740 	inc	r0
      001BF4 F6               [12] 5741 	mov	@r0,a
      001BF5                       5742 00103$:
                           001B38  5743 	C$fuzzy.h$2529$1_0$100 ==.
                                   5744 ;	../../fuzzy.h:2529: index < rules->count;
      001BF5 E5 08            [12] 5745 	mov	a,_bp
      001BF7 24 04            [12] 5746 	add	a,#0x04
      001BF9 F8               [12] 5747 	mov	r0,a
      001BFA 86 82            [24] 5748 	mov	dpl,@r0
      001BFC 08               [12] 5749 	inc	r0
      001BFD 86 83            [24] 5750 	mov	dph,@r0
      001BFF 08               [12] 5751 	inc	r0
      001C00 86 F0            [24] 5752 	mov	b,@r0
      001C02 12 43 A8         [24] 5753 	lcall	__gptrget
      001C05 FC               [12] 5754 	mov	r4,a
      001C06 A3               [24] 5755 	inc	dptr
      001C07 12 43 A8         [24] 5756 	lcall	__gptrget
      001C0A FD               [12] 5757 	mov	r5,a
      001C0B E5 08            [12] 5758 	mov	a,_bp
      001C0D 24 14            [12] 5759 	add	a,#0x14
      001C0F F8               [12] 5760 	mov	r0,a
      001C10 C3               [12] 5761 	clr	c
      001C11 E6               [12] 5762 	mov	a,@r0
      001C12 9C               [12] 5763 	subb	a,r4
      001C13 08               [12] 5764 	inc	r0
      001C14 E6               [12] 5765 	mov	a,@r0
      001C15 9D               [12] 5766 	subb	a,r5
      001C16 40 03            [24] 5767 	jc	00120$
      001C18 02 1D 2F         [24] 5768 	ljmp	00101$
      001C1B                       5769 00120$:
                           001B5E  5770 	C$fuzzy.h$2534$3_0$102 ==.
                                   5771 ;	../../fuzzy.h:2534: rules->rules[index]
      001C1B E5 08            [12] 5772 	mov	a,_bp
      001C1D 24 09            [12] 5773 	add	a,#0x09
      001C1F F8               [12] 5774 	mov	r0,a
      001C20 E5 08            [12] 5775 	mov	a,_bp
      001C22 24 07            [12] 5776 	add	a,#0x07
      001C24 F9               [12] 5777 	mov	r1,a
      001C25 E7               [12] 5778 	mov	a,@r1
      001C26 26               [12] 5779 	add	a, @r0
      001C27 FD               [12] 5780 	mov	r5,a
      001C28 09               [12] 5781 	inc	r1
      001C29 E7               [12] 5782 	mov	a,@r1
      001C2A 08               [12] 5783 	inc	r0
      001C2B 36               [12] 5784 	addc	a, @r0
      001C2C FE               [12] 5785 	mov	r6,a
      001C2D 08               [12] 5786 	inc	r0
      001C2E 86 07            [24] 5787 	mov	ar7,@r0
      001C30 74 07            [12] 5788 	mov	a,#0x07
      001C32 2D               [12] 5789 	add	a, r5
      001C33 FD               [12] 5790 	mov	r5,a
      001C34 E4               [12] 5791 	clr	a
      001C35 3E               [12] 5792 	addc	a, r6
      001C36 FE               [12] 5793 	mov	r6,a
      001C37 8D 82            [24] 5794 	mov	dpl,r5
      001C39 8E 83            [24] 5795 	mov	dph,r6
      001C3B 8F F0            [24] 5796 	mov	b,r7
      001C3D 12 43 A8         [24] 5797 	lcall	__gptrget
      001C40 FD               [12] 5798 	mov	r5,a
      001C41 A3               [24] 5799 	inc	dptr
      001C42 12 43 A8         [24] 5800 	lcall	__gptrget
      001C45 FE               [12] 5801 	mov	r6,a
                           001B89  5802 	C$fuzzy.h$2535$3_0$102 ==.
                                   5803 ;	../../fuzzy.h:2535: .output_function(value)
      001C46 12 1C 4B         [24] 5804 	lcall	00121$
      001C49 80 14            [24] 5805 	sjmp	00122$
      001C4B                       5806 00121$:
      001C4B C0 05            [24] 5807 	push	ar5
      001C4D C0 06            [24] 5808 	push	ar6
      001C4F E5 08            [12] 5809 	mov	a,_bp
      001C51 24 FA            [12] 5810 	add	a,#0xfa
      001C53 F8               [12] 5811 	mov	r0,a
      001C54 86 82            [24] 5812 	mov	dpl, @r0
      001C56 08               [12] 5813 	inc	r0
      001C57 86 83            [24] 5814 	mov	dph, @r0
      001C59 08               [12] 5815 	inc	r0
      001C5A 86 F0            [24] 5816 	mov	b, @r0
      001C5C 08               [12] 5817 	inc	r0
      001C5D E6               [12] 5818 	mov	a, @r0
      001C5E 22               [24] 5819 	ret
      001C5F                       5820 00122$:
      001C5F 12 00 F0         [24] 5821 	lcall	_fuzzy_clamp
      001C62 C8               [12] 5822 	xch	a,r0
      001C63 E5 08            [12] 5823 	mov	a,_bp
      001C65 24 10            [12] 5824 	add	a,#0x10
      001C67 C8               [12] 5825 	xch	a,r0
      001C68 A6 82            [24] 5826 	mov	@r0, dpl
      001C6A 08               [12] 5827 	inc	r0
      001C6B A6 83            [24] 5828 	mov	@r0, dph
      001C6D 08               [12] 5829 	inc	r0
      001C6E A6 F0            [24] 5830 	mov	@r0, b
      001C70 08               [12] 5831 	inc	r0
      001C71 F6               [12] 5832 	mov	@r0,a
                           001BB5  5833 	C$fuzzy.h$2541$3_0$102 ==.
                                   5834 ;	../../fuzzy.h:2541: rules->rules[index].value,
      001C72 A8 08            [24] 5835 	mov	r0,_bp
      001C74 08               [12] 5836 	inc	r0
      001C75 E5 08            [12] 5837 	mov	a,_bp
      001C77 24 07            [12] 5838 	add	a,#0x07
      001C79 F9               [12] 5839 	mov	r1,a
      001C7A E7               [12] 5840 	mov	a,@r1
      001C7B 26               [12] 5841 	add	a, @r0
      001C7C FA               [12] 5842 	mov	r2,a
      001C7D 09               [12] 5843 	inc	r1
      001C7E E7               [12] 5844 	mov	a,@r1
      001C7F 08               [12] 5845 	inc	r0
      001C80 36               [12] 5846 	addc	a, @r0
      001C81 FB               [12] 5847 	mov	r3,a
      001C82 08               [12] 5848 	inc	r0
      001C83 86 07            [24] 5849 	mov	ar7,@r0
      001C85 74 03            [12] 5850 	mov	a,#0x03
      001C87 2A               [12] 5851 	add	a, r2
      001C88 FA               [12] 5852 	mov	r2,a
      001C89 E4               [12] 5853 	clr	a
      001C8A 3B               [12] 5854 	addc	a, r3
      001C8B FB               [12] 5855 	mov	r3,a
      001C8C 8A 82            [24] 5856 	mov	dpl,r2
      001C8E 8B 83            [24] 5857 	mov	dph,r3
      001C90 8F F0            [24] 5858 	mov	b,r7
      001C92 12 43 A8         [24] 5859 	lcall	__gptrget
      001C95 FA               [12] 5860 	mov	r2,a
      001C96 A3               [24] 5861 	inc	dptr
      001C97 12 43 A8         [24] 5862 	lcall	__gptrget
      001C9A FB               [12] 5863 	mov	r3,a
      001C9B A3               [24] 5864 	inc	dptr
      001C9C 12 43 A8         [24] 5865 	lcall	__gptrget
      001C9F FF               [12] 5866 	mov	r7,a
      001CA0 A3               [24] 5867 	inc	dptr
      001CA1 12 43 A8         [24] 5868 	lcall	__gptrget
      001CA4 FE               [12] 5869 	mov	r6,a
                           001BE8  5870 	C$fuzzy.h$2540$3_0$102 ==.
                                   5871 ;	../../fuzzy.h:2540: implication_method,
      001CA5 E5 08            [12] 5872 	mov	a,_bp
      001CA7 24 10            [12] 5873 	add	a,#0x10
      001CA9 F8               [12] 5874 	mov	r0,a
      001CAA E6               [12] 5875 	mov	a,@r0
      001CAB C0 E0            [24] 5876 	push	acc
      001CAD 08               [12] 5877 	inc	r0
      001CAE E6               [12] 5878 	mov	a,@r0
      001CAF C0 E0            [24] 5879 	push	acc
      001CB1 08               [12] 5880 	inc	r0
      001CB2 E6               [12] 5881 	mov	a,@r0
      001CB3 C0 E0            [24] 5882 	push	acc
      001CB5 08               [12] 5883 	inc	r0
      001CB6 E6               [12] 5884 	mov	a,@r0
      001CB7 C0 E0            [24] 5885 	push	acc
      001CB9 C0 02            [24] 5886 	push	ar2
      001CBB C0 03            [24] 5887 	push	ar3
      001CBD C0 07            [24] 5888 	push	ar7
      001CBF C0 06            [24] 5889 	push	ar6
      001CC1 E5 08            [12] 5890 	mov	a,_bp
      001CC3 24 F9            [12] 5891 	add	a,#0xf9
      001CC5 F8               [12] 5892 	mov	r0,a
      001CC6 86 82            [24] 5893 	mov	dpl, @r0
      001CC8 12 18 D7         [24] 5894 	lcall	_fuzzy_implication
      001CCB AC 82            [24] 5895 	mov	r4, dpl
      001CCD AD 83            [24] 5896 	mov	r5, dph
      001CCF AE F0            [24] 5897 	mov	r6, b
      001CD1 FF               [12] 5898 	mov	r7, a
      001CD2 E5 81            [12] 5899 	mov	a,sp
      001CD4 24 F8            [12] 5900 	add	a,#0xf8
      001CD6 F5 81            [12] 5901 	mov	sp,a
                           001C1B  5902 	C$fuzzy.h$2547$3_0$102 ==.
                                   5903 ;	../../fuzzy.h:2547: aggregation_method,
      001CD8 C0 04            [24] 5904 	push	ar4
      001CDA C0 05            [24] 5905 	push	ar5
      001CDC C0 06            [24] 5906 	push	ar6
      001CDE C0 07            [24] 5907 	push	ar7
      001CE0 E5 08            [12] 5908 	mov	a,_bp
      001CE2 24 0C            [12] 5909 	add	a,#0x0c
      001CE4 F8               [12] 5910 	mov	r0,a
      001CE5 E6               [12] 5911 	mov	a,@r0
      001CE6 C0 E0            [24] 5912 	push	acc
      001CE8 08               [12] 5913 	inc	r0
      001CE9 E6               [12] 5914 	mov	a,@r0
      001CEA C0 E0            [24] 5915 	push	acc
      001CEC 08               [12] 5916 	inc	r0
      001CED E6               [12] 5917 	mov	a,@r0
      001CEE C0 E0            [24] 5918 	push	acc
      001CF0 08               [12] 5919 	inc	r0
      001CF1 E6               [12] 5920 	mov	a,@r0
      001CF2 C0 E0            [24] 5921 	push	acc
      001CF4 E5 08            [12] 5922 	mov	a,_bp
      001CF6 24 F8            [12] 5923 	add	a,#0xf8
      001CF8 F8               [12] 5924 	mov	r0,a
      001CF9 86 82            [24] 5925 	mov	dpl, @r0
      001CFB 12 19 EA         [24] 5926 	lcall	_fuzzy_aggregation
      001CFE C8               [12] 5927 	xch	a,r0
      001CFF E5 08            [12] 5928 	mov	a,_bp
      001D01 24 0C            [12] 5929 	add	a,#0x0c
      001D03 C8               [12] 5930 	xch	a,r0
      001D04 A6 82            [24] 5931 	mov	@r0, dpl
      001D06 08               [12] 5932 	inc	r0
      001D07 A6 83            [24] 5933 	mov	@r0, dph
      001D09 08               [12] 5934 	inc	r0
      001D0A A6 F0            [24] 5935 	mov	@r0, b
      001D0C 08               [12] 5936 	inc	r0
      001D0D F6               [12] 5937 	mov	@r0,a
      001D0E E5 81            [12] 5938 	mov	a,sp
      001D10 24 F8            [12] 5939 	add	a,#0xf8
      001D12 F5 81            [12] 5940 	mov	sp,a
                           001C57  5941 	C$fuzzy.h$2530$1_0$100 ==.
                                   5942 ;	../../fuzzy.h:2530: index++
      001D14 E5 08            [12] 5943 	mov	a,_bp
      001D16 24 07            [12] 5944 	add	a,#0x07
      001D18 F8               [12] 5945 	mov	r0,a
      001D19 74 09            [12] 5946 	mov	a,#0x09
      001D1B 26               [12] 5947 	add	a, @r0
      001D1C F6               [12] 5948 	mov	@r0,a
      001D1D E4               [12] 5949 	clr	a
      001D1E 08               [12] 5950 	inc	r0
      001D1F 36               [12] 5951 	addc	a, @r0
      001D20 F6               [12] 5952 	mov	@r0,a
      001D21 E5 08            [12] 5953 	mov	a,_bp
      001D23 24 14            [12] 5954 	add	a,#0x14
      001D25 F8               [12] 5955 	mov	r0,a
      001D26 06               [12] 5956 	inc	@r0
      001D27 B6 00 02         [24] 5957 	cjne	@r0,#0x00,00123$
      001D2A 08               [12] 5958 	inc	r0
      001D2B 06               [12] 5959 	inc	@r0
      001D2C                       5960 00123$:
      001D2C 02 1B F5         [24] 5961 	ljmp	00103$
      001D2F                       5962 00101$:
                           001C72  5963 	C$fuzzy.h$2554$1_0$100 ==.
                                   5964 ;	../../fuzzy.h:2554: aggregated_height
      001D2F E5 08            [12] 5965 	mov	a,_bp
      001D31 24 0C            [12] 5966 	add	a,#0x0c
      001D33 F8               [12] 5967 	mov	r0,a
      001D34 86 82            [24] 5968 	mov	dpl, @r0
      001D36 08               [12] 5969 	inc	r0
      001D37 86 83            [24] 5970 	mov	dph, @r0
      001D39 08               [12] 5971 	inc	r0
      001D3A 86 F0            [24] 5972 	mov	b, @r0
      001D3C 08               [12] 5973 	inc	r0
      001D3D E6               [12] 5974 	mov	a, @r0
      001D3E 12 00 F0         [24] 5975 	lcall	_fuzzy_clamp
                           001C84  5976 	C$fuzzy.h$2556$1_0$100 ==.
                                   5977 ;	../../fuzzy.h:2556: }
      001D41 85 08 81         [24] 5978 	mov	sp,_bp
      001D44 D0 08            [24] 5979 	pop	_bp
                           001C89  5980 	C$fuzzy.h$2556$1_0$100 ==.
                           001C89  5981 	XFsugeno_demo$fuzzy_rules_aggregated_height$0$0 ==.
      001D46 22               [24] 5982 	ret
                                   5983 ;------------------------------------------------------------
                                   5984 ;Allocation info for local variables in function 'fuzzy_rules_maximum_result'
                                   5985 ;------------------------------------------------------------
                                   5986 ;rules         Allocated to stack - _bp -5 +3 
                                   5987 ;lower         Allocated to stack - _bp -9 +4 
                                   5988 ;upper         Allocated to stack - _bp -13 +4 
                                   5989 ;step          Allocated to stack - _bp -17 +4 
                                   5990 ;implication_method Allocated to stack - _bp -18 +1 
                                   5991 ;aggregation_method Allocated to stack - _bp -19 +1 
                                   5992 ;result        Allocated to registers r5 r6 r7 
                                   5993 ;value         Allocated to stack - _bp +16 +4 
                                   5994 ;height        Allocated to stack - _bp +20 +4 
                                   5995 ;sloc0         Allocated to stack - _bp +1 +3 
                                   5996 ;sloc1         Allocated to stack - _bp +4 +3 
                                   5997 ;sloc2         Allocated to stack - _bp +7 +3 
                                   5998 ;sloc3         Allocated to stack - _bp +10 +3 
                                   5999 ;sloc4         Allocated to stack - _bp +13 +3 
                                   6000 ;------------------------------------------------------------
                           001C8A  6001 	Fsugeno_demo$fuzzy_rules_maximum_result$0$0 ==.
                           001C8A  6002 	C$fuzzy.h$2576$1_0$104 ==.
                                   6003 ;	../../fuzzy.h:2576: static void fuzzy_rules_maximum_result(
                                   6004 ;	-----------------------------------------
                                   6005 ;	 function fuzzy_rules_maximum_result
                                   6006 ;	-----------------------------------------
      001D47                       6007 _fuzzy_rules_maximum_result:
      001D47 C0 08            [24] 6008 	push	_bp
      001D49 E5 81            [12] 6009 	mov	a,sp
      001D4B F5 08            [12] 6010 	mov	_bp,a
      001D4D 24 17            [12] 6011 	add	a,#0x17
      001D4F F5 81            [12] 6012 	mov	sp,a
      001D51 AD 82            [24] 6013 	mov	r5, dpl
      001D53 AE 83            [24] 6014 	mov	r6, dph
      001D55 AF F0            [24] 6015 	mov	r7, b
                           001C9A  6016 	C$fuzzy.h$2589$1_0$104 ==.
                                   6017 ;	../../fuzzy.h:2589: result->height =
      001D57 E5 08            [12] 6018 	mov	a,_bp
      001D59 24 0A            [12] 6019 	add	a,#0x0a
      001D5B F8               [12] 6020 	mov	r0,a
      001D5C A6 05            [24] 6021 	mov	@r0,ar5
      001D5E 08               [12] 6022 	inc	r0
      001D5F A6 06            [24] 6023 	mov	@r0,ar6
      001D61 08               [12] 6024 	inc	r0
      001D62 A6 07            [24] 6025 	mov	@r0,ar7
      001D64 E5 08            [12] 6026 	mov	a,_bp
      001D66 24 0A            [12] 6027 	add	a,#0x0a
      001D68 F8               [12] 6028 	mov	r0,a
      001D69 86 82            [24] 6029 	mov	dpl,@r0
      001D6B 08               [12] 6030 	inc	r0
      001D6C 86 83            [24] 6031 	mov	dph,@r0
      001D6E 08               [12] 6032 	inc	r0
      001D6F 86 F0            [24] 6033 	mov	b,@r0
      001D71 E4               [12] 6034 	clr	a
      001D72 12 41 61         [24] 6035 	lcall	__gptrput
      001D75 A3               [24] 6036 	inc	dptr
      001D76 12 41 61         [24] 6037 	lcall	__gptrput
      001D79 A3               [24] 6038 	inc	dptr
      001D7A 12 41 61         [24] 6039 	lcall	__gptrput
      001D7D A3               [24] 6040 	inc	dptr
      001D7E 12 41 61         [24] 6041 	lcall	__gptrput
                           001CC4  6042 	C$fuzzy.h$2592$1_0$104 ==.
                                   6043 ;	../../fuzzy.h:2592: result->smallest_position =
      001D81 A8 08            [24] 6044 	mov	r0,_bp
      001D83 08               [12] 6045 	inc	r0
      001D84 74 04            [12] 6046 	mov	a,#0x04
      001D86 2D               [12] 6047 	add	a, r5
      001D87 F6               [12] 6048 	mov	@r0,a
      001D88 E4               [12] 6049 	clr	a
      001D89 3E               [12] 6050 	addc	a, r6
      001D8A 08               [12] 6051 	inc	r0
      001D8B F6               [12] 6052 	mov	@r0,a
      001D8C 08               [12] 6053 	inc	r0
      001D8D A6 07            [24] 6054 	mov	@r0,ar7
      001D8F A8 08            [24] 6055 	mov	r0,_bp
      001D91 08               [12] 6056 	inc	r0
      001D92 86 82            [24] 6057 	mov	dpl,@r0
      001D94 08               [12] 6058 	inc	r0
      001D95 86 83            [24] 6059 	mov	dph,@r0
      001D97 08               [12] 6060 	inc	r0
      001D98 86 F0            [24] 6061 	mov	b,@r0
      001D9A E5 08            [12] 6062 	mov	a,_bp
      001D9C 24 F7            [12] 6063 	add	a,#0xf7
      001D9E F9               [12] 6064 	mov	r1,a
      001D9F E7               [12] 6065 	mov	a,@r1
      001DA0 12 41 61         [24] 6066 	lcall	__gptrput
      001DA3 A3               [24] 6067 	inc	dptr
      001DA4 09               [12] 6068 	inc	r1
      001DA5 E7               [12] 6069 	mov	a,@r1
      001DA6 12 41 61         [24] 6070 	lcall	__gptrput
      001DA9 A3               [24] 6071 	inc	dptr
      001DAA 09               [12] 6072 	inc	r1
      001DAB E7               [12] 6073 	mov	a,@r1
      001DAC 12 41 61         [24] 6074 	lcall	__gptrput
      001DAF A3               [24] 6075 	inc	dptr
      001DB0 09               [12] 6076 	inc	r1
      001DB1 E7               [12] 6077 	mov	a,@r1
      001DB2 12 41 61         [24] 6078 	lcall	__gptrput
                           001CF8  6079 	C$fuzzy.h$2595$1_0$104 ==.
                                   6080 ;	../../fuzzy.h:2595: result->largest_position =
      001DB5 E5 08            [12] 6081 	mov	a,_bp
      001DB7 24 04            [12] 6082 	add	a,#0x04
      001DB9 F8               [12] 6083 	mov	r0,a
      001DBA 74 08            [12] 6084 	mov	a,#0x08
      001DBC 2D               [12] 6085 	add	a, r5
      001DBD F6               [12] 6086 	mov	@r0,a
      001DBE E4               [12] 6087 	clr	a
      001DBF 3E               [12] 6088 	addc	a, r6
      001DC0 08               [12] 6089 	inc	r0
      001DC1 F6               [12] 6090 	mov	@r0,a
      001DC2 08               [12] 6091 	inc	r0
      001DC3 A6 07            [24] 6092 	mov	@r0,ar7
      001DC5 E5 08            [12] 6093 	mov	a,_bp
      001DC7 24 04            [12] 6094 	add	a,#0x04
      001DC9 F8               [12] 6095 	mov	r0,a
      001DCA 86 82            [24] 6096 	mov	dpl,@r0
      001DCC 08               [12] 6097 	inc	r0
      001DCD 86 83            [24] 6098 	mov	dph,@r0
      001DCF 08               [12] 6099 	inc	r0
      001DD0 86 F0            [24] 6100 	mov	b,@r0
      001DD2 E5 08            [12] 6101 	mov	a,_bp
      001DD4 24 F7            [12] 6102 	add	a,#0xf7
      001DD6 F9               [12] 6103 	mov	r1,a
      001DD7 E7               [12] 6104 	mov	a,@r1
      001DD8 12 41 61         [24] 6105 	lcall	__gptrput
      001DDB A3               [24] 6106 	inc	dptr
      001DDC 09               [12] 6107 	inc	r1
      001DDD E7               [12] 6108 	mov	a,@r1
      001DDE 12 41 61         [24] 6109 	lcall	__gptrput
      001DE1 A3               [24] 6110 	inc	dptr
      001DE2 09               [12] 6111 	inc	r1
      001DE3 E7               [12] 6112 	mov	a,@r1
      001DE4 12 41 61         [24] 6113 	lcall	__gptrput
      001DE7 A3               [24] 6114 	inc	dptr
      001DE8 09               [12] 6115 	inc	r1
      001DE9 E7               [12] 6116 	mov	a,@r1
      001DEA 12 41 61         [24] 6117 	lcall	__gptrput
                           001D30  6118 	C$fuzzy.h$2598$1_0$104 ==.
                                   6119 ;	../../fuzzy.h:2598: result->position_sum =
      001DED E5 08            [12] 6120 	mov	a,_bp
      001DEF 24 07            [12] 6121 	add	a,#0x07
      001DF1 F8               [12] 6122 	mov	r0,a
      001DF2 74 0C            [12] 6123 	mov	a,#0x0c
      001DF4 2D               [12] 6124 	add	a, r5
      001DF5 F6               [12] 6125 	mov	@r0,a
      001DF6 E4               [12] 6126 	clr	a
      001DF7 3E               [12] 6127 	addc	a, r6
      001DF8 08               [12] 6128 	inc	r0
      001DF9 F6               [12] 6129 	mov	@r0,a
      001DFA 08               [12] 6130 	inc	r0
      001DFB A6 07            [24] 6131 	mov	@r0,ar7
      001DFD E5 08            [12] 6132 	mov	a,_bp
      001DFF 24 07            [12] 6133 	add	a,#0x07
      001E01 F8               [12] 6134 	mov	r0,a
      001E02 86 82            [24] 6135 	mov	dpl,@r0
      001E04 08               [12] 6136 	inc	r0
      001E05 86 83            [24] 6137 	mov	dph,@r0
      001E07 08               [12] 6138 	inc	r0
      001E08 86 F0            [24] 6139 	mov	b,@r0
      001E0A E4               [12] 6140 	clr	a
      001E0B 12 41 61         [24] 6141 	lcall	__gptrput
      001E0E A3               [24] 6142 	inc	dptr
      001E0F 12 41 61         [24] 6143 	lcall	__gptrput
      001E12 A3               [24] 6144 	inc	dptr
      001E13 12 41 61         [24] 6145 	lcall	__gptrput
      001E16 A3               [24] 6146 	inc	dptr
      001E17 12 41 61         [24] 6147 	lcall	__gptrput
                           001D5D  6148 	C$fuzzy.h$2601$1_0$104 ==.
                                   6149 ;	../../fuzzy.h:2601: result->position_count =
      001E1A E5 08            [12] 6150 	mov	a,_bp
      001E1C 24 0D            [12] 6151 	add	a,#0x0d
      001E1E F8               [12] 6152 	mov	r0,a
      001E1F 74 10            [12] 6153 	mov	a,#0x10
      001E21 2D               [12] 6154 	add	a, r5
      001E22 F6               [12] 6155 	mov	@r0,a
      001E23 E4               [12] 6156 	clr	a
      001E24 3E               [12] 6157 	addc	a, r6
      001E25 08               [12] 6158 	inc	r0
      001E26 F6               [12] 6159 	mov	@r0,a
      001E27 08               [12] 6160 	inc	r0
      001E28 A6 07            [24] 6161 	mov	@r0,ar7
      001E2A E5 08            [12] 6162 	mov	a,_bp
      001E2C 24 0D            [12] 6163 	add	a,#0x0d
      001E2E F8               [12] 6164 	mov	r0,a
      001E2F 86 82            [24] 6165 	mov	dpl,@r0
      001E31 08               [12] 6166 	inc	r0
      001E32 86 83            [24] 6167 	mov	dph,@r0
      001E34 08               [12] 6168 	inc	r0
      001E35 86 F0            [24] 6169 	mov	b,@r0
      001E37 E4               [12] 6170 	clr	a
      001E38 12 41 61         [24] 6171 	lcall	__gptrput
      001E3B A3               [24] 6172 	inc	dptr
      001E3C 12 41 61         [24] 6173 	lcall	__gptrput
                           001D82  6174 	C$fuzzy.h$2605$2_0$105 ==.
                                   6175 ;	../../fuzzy.h:2605: value = lower;
      001E3F E5 08            [12] 6176 	mov	a,_bp
      001E41 24 F7            [12] 6177 	add	a,#0xf7
      001E43 F8               [12] 6178 	mov	r0,a
      001E44 E5 08            [12] 6179 	mov	a,_bp
      001E46 24 10            [12] 6180 	add	a,#0x10
      001E48 F9               [12] 6181 	mov	r1,a
      001E49 E6               [12] 6182 	mov	a,@r0
      001E4A F7               [12] 6183 	mov	@r1,a
      001E4B 08               [12] 6184 	inc	r0
      001E4C E6               [12] 6185 	mov	a,@r0
      001E4D 09               [12] 6186 	inc	r1
      001E4E F7               [12] 6187 	mov	@r1,a
      001E4F 08               [12] 6188 	inc	r0
      001E50 E6               [12] 6189 	mov	a,@r0
      001E51 09               [12] 6190 	inc	r1
      001E52 F7               [12] 6191 	mov	@r1,a
      001E53 08               [12] 6192 	inc	r0
      001E54 E6               [12] 6193 	mov	a,@r0
      001E55 09               [12] 6194 	inc	r1
      001E56 F7               [12] 6195 	mov	@r1,a
      001E57                       6196 00109$:
                           001D9A  6197 	C$fuzzy.h$2606$2_0$104 ==.
                                   6198 ;	../../fuzzy.h:2606: value <= upper;
      001E57 E5 08            [12] 6199 	mov	a,_bp
      001E59 24 10            [12] 6200 	add	a,#0x10
      001E5B F8               [12] 6201 	mov	r0,a
      001E5C E6               [12] 6202 	mov	a,@r0
      001E5D C0 E0            [24] 6203 	push	acc
      001E5F 08               [12] 6204 	inc	r0
      001E60 E6               [12] 6205 	mov	a,@r0
      001E61 C0 E0            [24] 6206 	push	acc
      001E63 08               [12] 6207 	inc	r0
      001E64 E6               [12] 6208 	mov	a,@r0
      001E65 C0 E0            [24] 6209 	push	acc
      001E67 08               [12] 6210 	inc	r0
      001E68 E6               [12] 6211 	mov	a,@r0
      001E69 C0 E0            [24] 6212 	push	acc
      001E6B E5 08            [12] 6213 	mov	a,_bp
      001E6D 24 F3            [12] 6214 	add	a,#0xf3
      001E6F F8               [12] 6215 	mov	r0,a
      001E70 86 82            [24] 6216 	mov	dpl, @r0
      001E72 08               [12] 6217 	inc	r0
      001E73 86 83            [24] 6218 	mov	dph, @r0
      001E75 08               [12] 6219 	inc	r0
      001E76 86 F0            [24] 6220 	mov	b, @r0
      001E78 08               [12] 6221 	inc	r0
      001E79 E6               [12] 6222 	mov	a, @r0
      001E7A 12 41 7C         [24] 6223 	lcall	___fslt
      001E7D E5 81            [12] 6224 	mov	a,sp
      001E7F 24 FC            [12] 6225 	add	a,#0xfc
      001E81 F5 81            [12] 6226 	mov	sp,a
      001E83 E5 82            [12] 6227 	mov	a, dpl
      001E85 24 FF            [12] 6228 	add	a,#0xff
      001E87 92 00            [24] 6229 	mov	b0,c
      001E89 50 03            [24] 6230 	jnc	00137$
      001E8B 02 21 3F         [24] 6231 	ljmp	00111$
      001E8E                       6232 00137$:
                           001DD1  6233 	C$fuzzy.h$2611$3_0$106 ==.
                                   6234 ;	../../fuzzy.h:2611: rules,
      001E8E E5 08            [12] 6235 	mov	a,_bp
      001E90 24 ED            [12] 6236 	add	a,#0xed
      001E92 F8               [12] 6237 	mov	r0,a
      001E93 E6               [12] 6238 	mov	a,@r0
      001E94 C0 E0            [24] 6239 	push	acc
      001E96 E5 08            [12] 6240 	mov	a,_bp
      001E98 24 EE            [12] 6241 	add	a,#0xee
      001E9A F8               [12] 6242 	mov	r0,a
      001E9B E6               [12] 6243 	mov	a,@r0
      001E9C C0 E0            [24] 6244 	push	acc
      001E9E E5 08            [12] 6245 	mov	a,_bp
      001EA0 24 10            [12] 6246 	add	a,#0x10
      001EA2 F8               [12] 6247 	mov	r0,a
      001EA3 E6               [12] 6248 	mov	a,@r0
      001EA4 C0 E0            [24] 6249 	push	acc
      001EA6 08               [12] 6250 	inc	r0
      001EA7 E6               [12] 6251 	mov	a,@r0
      001EA8 C0 E0            [24] 6252 	push	acc
      001EAA 08               [12] 6253 	inc	r0
      001EAB E6               [12] 6254 	mov	a,@r0
      001EAC C0 E0            [24] 6255 	push	acc
      001EAE 08               [12] 6256 	inc	r0
      001EAF E6               [12] 6257 	mov	a,@r0
      001EB0 C0 E0            [24] 6258 	push	acc
      001EB2 E5 08            [12] 6259 	mov	a,_bp
      001EB4 24 FB            [12] 6260 	add	a,#0xfb
      001EB6 F8               [12] 6261 	mov	r0,a
      001EB7 86 82            [24] 6262 	mov	dpl, @r0
      001EB9 08               [12] 6263 	inc	r0
      001EBA 86 83            [24] 6264 	mov	dph, @r0
      001EBC 08               [12] 6265 	inc	r0
      001EBD 86 F0            [24] 6266 	mov	b, @r0
      001EBF 12 1B 9E         [24] 6267 	lcall	_fuzzy_rules_aggregated_height
      001EC2 C8               [12] 6268 	xch	a,r0
      001EC3 E5 08            [12] 6269 	mov	a,_bp
      001EC5 24 14            [12] 6270 	add	a,#0x14
      001EC7 C8               [12] 6271 	xch	a,r0
      001EC8 A6 82            [24] 6272 	mov	@r0, dpl
      001ECA 08               [12] 6273 	inc	r0
      001ECB A6 83            [24] 6274 	mov	@r0, dph
      001ECD 08               [12] 6275 	inc	r0
      001ECE A6 F0            [24] 6276 	mov	@r0, b
      001ED0 08               [12] 6277 	inc	r0
      001ED1 F6               [12] 6278 	mov	@r0,a
      001ED2 E5 81            [12] 6279 	mov	a,sp
      001ED4 24 FA            [12] 6280 	add	a,#0xfa
      001ED6 F5 81            [12] 6281 	mov	sp,a
                           001E1B  6282 	C$fuzzy.h$2618$3_0$106 ==.
                                   6283 ;	../../fuzzy.h:2618: result->position_count == 0u ||
      001ED8 E5 08            [12] 6284 	mov	a,_bp
      001EDA 24 0D            [12] 6285 	add	a,#0x0d
      001EDC F8               [12] 6286 	mov	r0,a
      001EDD 86 82            [24] 6287 	mov	dpl,@r0
      001EDF 08               [12] 6288 	inc	r0
      001EE0 86 83            [24] 6289 	mov	dph,@r0
      001EE2 08               [12] 6290 	inc	r0
      001EE3 86 F0            [24] 6291 	mov	b,@r0
      001EE5 12 43 A8         [24] 6292 	lcall	__gptrget
      001EE8 FD               [12] 6293 	mov	r5,a
      001EE9 A3               [24] 6294 	inc	dptr
      001EEA 12 43 A8         [24] 6295 	lcall	__gptrget
      001EED 4D               [12] 6296 	orl	a,r5
      001EEE 60 4C            [24] 6297 	jz	00103$
                           001E33  6298 	C$fuzzy.h$2619$2_0$104 ==.
                                   6299 ;	../../fuzzy.h:2619: height > result->height
      001EF0 E5 08            [12] 6300 	mov	a,_bp
      001EF2 24 0A            [12] 6301 	add	a,#0x0a
      001EF4 F8               [12] 6302 	mov	r0,a
      001EF5 86 82            [24] 6303 	mov	dpl,@r0
      001EF7 08               [12] 6304 	inc	r0
      001EF8 86 83            [24] 6305 	mov	dph,@r0
      001EFA 08               [12] 6306 	inc	r0
      001EFB 86 F0            [24] 6307 	mov	b,@r0
      001EFD 12 43 A8         [24] 6308 	lcall	__gptrget
      001F00 FC               [12] 6309 	mov	r4,a
      001F01 A3               [24] 6310 	inc	dptr
      001F02 12 43 A8         [24] 6311 	lcall	__gptrget
      001F05 FD               [12] 6312 	mov	r5,a
      001F06 A3               [24] 6313 	inc	dptr
      001F07 12 43 A8         [24] 6314 	lcall	__gptrget
      001F0A FE               [12] 6315 	mov	r6,a
      001F0B A3               [24] 6316 	inc	dptr
      001F0C 12 43 A8         [24] 6317 	lcall	__gptrget
      001F0F FF               [12] 6318 	mov	r7,a
      001F10 E5 08            [12] 6319 	mov	a,_bp
      001F12 24 14            [12] 6320 	add	a,#0x14
      001F14 F8               [12] 6321 	mov	r0,a
      001F15 E6               [12] 6322 	mov	a,@r0
      001F16 C0 E0            [24] 6323 	push	acc
      001F18 08               [12] 6324 	inc	r0
      001F19 E6               [12] 6325 	mov	a,@r0
      001F1A C0 E0            [24] 6326 	push	acc
      001F1C 08               [12] 6327 	inc	r0
      001F1D E6               [12] 6328 	mov	a,@r0
      001F1E C0 E0            [24] 6329 	push	acc
      001F20 08               [12] 6330 	inc	r0
      001F21 E6               [12] 6331 	mov	a,@r0
      001F22 C0 E0            [24] 6332 	push	acc
      001F24 8C 82            [24] 6333 	mov	dpl, r4
      001F26 8D 83            [24] 6334 	mov	dph, r5
      001F28 8E F0            [24] 6335 	mov	b, r6
      001F2A EF               [12] 6336 	mov	a, r7
      001F2B 12 41 7C         [24] 6337 	lcall	___fslt
      001F2E AF 82            [24] 6338 	mov	r7, dpl
      001F30 E5 81            [12] 6339 	mov	a,sp
      001F32 24 FC            [12] 6340 	add	a,#0xfc
      001F34 F5 81            [12] 6341 	mov	sp,a
      001F36 EF               [12] 6342 	mov	a,r7
      001F37 70 03            [24] 6343 	jnz	00139$
      001F39 02 1F F4         [24] 6344 	ljmp	00104$
      001F3C                       6345 00139$:
      001F3C                       6346 00103$:
                           001E7F  6347 	C$fuzzy.h$2621$4_0$107 ==.
                                   6348 ;	../../fuzzy.h:2621: result->height =
      001F3C E5 08            [12] 6349 	mov	a,_bp
      001F3E 24 0A            [12] 6350 	add	a,#0x0a
      001F40 F8               [12] 6351 	mov	r0,a
      001F41 86 82            [24] 6352 	mov	dpl,@r0
      001F43 08               [12] 6353 	inc	r0
      001F44 86 83            [24] 6354 	mov	dph,@r0
      001F46 08               [12] 6355 	inc	r0
      001F47 86 F0            [24] 6356 	mov	b,@r0
      001F49 E5 08            [12] 6357 	mov	a,_bp
      001F4B 24 14            [12] 6358 	add	a,#0x14
      001F4D F9               [12] 6359 	mov	r1,a
      001F4E E7               [12] 6360 	mov	a,@r1
      001F4F 12 41 61         [24] 6361 	lcall	__gptrput
      001F52 A3               [24] 6362 	inc	dptr
      001F53 09               [12] 6363 	inc	r1
      001F54 E7               [12] 6364 	mov	a,@r1
      001F55 12 41 61         [24] 6365 	lcall	__gptrput
      001F58 A3               [24] 6366 	inc	dptr
      001F59 09               [12] 6367 	inc	r1
      001F5A E7               [12] 6368 	mov	a,@r1
      001F5B 12 41 61         [24] 6369 	lcall	__gptrput
      001F5E A3               [24] 6370 	inc	dptr
      001F5F 09               [12] 6371 	inc	r1
      001F60 E7               [12] 6372 	mov	a,@r1
      001F61 12 41 61         [24] 6373 	lcall	__gptrput
                           001EA7  6374 	C$fuzzy.h$2624$4_0$107 ==.
                                   6375 ;	../../fuzzy.h:2624: result->smallest_position =
      001F64 A8 08            [24] 6376 	mov	r0,_bp
      001F66 08               [12] 6377 	inc	r0
      001F67 86 82            [24] 6378 	mov	dpl,@r0
      001F69 08               [12] 6379 	inc	r0
      001F6A 86 83            [24] 6380 	mov	dph,@r0
      001F6C 08               [12] 6381 	inc	r0
      001F6D 86 F0            [24] 6382 	mov	b,@r0
      001F6F E5 08            [12] 6383 	mov	a,_bp
      001F71 24 10            [12] 6384 	add	a,#0x10
      001F73 F9               [12] 6385 	mov	r1,a
      001F74 E7               [12] 6386 	mov	a,@r1
      001F75 12 41 61         [24] 6387 	lcall	__gptrput
      001F78 A3               [24] 6388 	inc	dptr
      001F79 09               [12] 6389 	inc	r1
      001F7A E7               [12] 6390 	mov	a,@r1
      001F7B 12 41 61         [24] 6391 	lcall	__gptrput
      001F7E A3               [24] 6392 	inc	dptr
      001F7F 09               [12] 6393 	inc	r1
      001F80 E7               [12] 6394 	mov	a,@r1
      001F81 12 41 61         [24] 6395 	lcall	__gptrput
      001F84 A3               [24] 6396 	inc	dptr
      001F85 09               [12] 6397 	inc	r1
      001F86 E7               [12] 6398 	mov	a,@r1
      001F87 12 41 61         [24] 6399 	lcall	__gptrput
                           001ECD  6400 	C$fuzzy.h$2627$4_0$107 ==.
                                   6401 ;	../../fuzzy.h:2627: result->largest_position =
      001F8A E5 08            [12] 6402 	mov	a,_bp
      001F8C 24 04            [12] 6403 	add	a,#0x04
      001F8E F8               [12] 6404 	mov	r0,a
      001F8F 86 82            [24] 6405 	mov	dpl,@r0
      001F91 08               [12] 6406 	inc	r0
      001F92 86 83            [24] 6407 	mov	dph,@r0
      001F94 08               [12] 6408 	inc	r0
      001F95 86 F0            [24] 6409 	mov	b,@r0
      001F97 E5 08            [12] 6410 	mov	a,_bp
      001F99 24 10            [12] 6411 	add	a,#0x10
      001F9B F9               [12] 6412 	mov	r1,a
      001F9C E7               [12] 6413 	mov	a,@r1
      001F9D 12 41 61         [24] 6414 	lcall	__gptrput
      001FA0 A3               [24] 6415 	inc	dptr
      001FA1 09               [12] 6416 	inc	r1
      001FA2 E7               [12] 6417 	mov	a,@r1
      001FA3 12 41 61         [24] 6418 	lcall	__gptrput
      001FA6 A3               [24] 6419 	inc	dptr
      001FA7 09               [12] 6420 	inc	r1
      001FA8 E7               [12] 6421 	mov	a,@r1
      001FA9 12 41 61         [24] 6422 	lcall	__gptrput
      001FAC A3               [24] 6423 	inc	dptr
      001FAD 09               [12] 6424 	inc	r1
      001FAE E7               [12] 6425 	mov	a,@r1
      001FAF 12 41 61         [24] 6426 	lcall	__gptrput
                           001EF5  6427 	C$fuzzy.h$2630$4_0$107 ==.
                                   6428 ;	../../fuzzy.h:2630: result->position_sum =
      001FB2 E5 08            [12] 6429 	mov	a,_bp
      001FB4 24 07            [12] 6430 	add	a,#0x07
      001FB6 F8               [12] 6431 	mov	r0,a
      001FB7 86 82            [24] 6432 	mov	dpl,@r0
      001FB9 08               [12] 6433 	inc	r0
      001FBA 86 83            [24] 6434 	mov	dph,@r0
      001FBC 08               [12] 6435 	inc	r0
      001FBD 86 F0            [24] 6436 	mov	b,@r0
      001FBF E5 08            [12] 6437 	mov	a,_bp
      001FC1 24 10            [12] 6438 	add	a,#0x10
      001FC3 F9               [12] 6439 	mov	r1,a
      001FC4 E7               [12] 6440 	mov	a,@r1
      001FC5 12 41 61         [24] 6441 	lcall	__gptrput
      001FC8 A3               [24] 6442 	inc	dptr
      001FC9 09               [12] 6443 	inc	r1
      001FCA E7               [12] 6444 	mov	a,@r1
      001FCB 12 41 61         [24] 6445 	lcall	__gptrput
      001FCE A3               [24] 6446 	inc	dptr
      001FCF 09               [12] 6447 	inc	r1
      001FD0 E7               [12] 6448 	mov	a,@r1
      001FD1 12 41 61         [24] 6449 	lcall	__gptrput
      001FD4 A3               [24] 6450 	inc	dptr
      001FD5 09               [12] 6451 	inc	r1
      001FD6 E7               [12] 6452 	mov	a,@r1
      001FD7 12 41 61         [24] 6453 	lcall	__gptrput
                           001F1D  6454 	C$fuzzy.h$2633$4_0$107 ==.
                                   6455 ;	../../fuzzy.h:2633: result->position_count =
      001FDA E5 08            [12] 6456 	mov	a,_bp
      001FDC 24 0D            [12] 6457 	add	a,#0x0d
      001FDE F8               [12] 6458 	mov	r0,a
      001FDF 86 82            [24] 6459 	mov	dpl,@r0
      001FE1 08               [12] 6460 	inc	r0
      001FE2 86 83            [24] 6461 	mov	dph,@r0
      001FE4 08               [12] 6462 	inc	r0
      001FE5 86 F0            [24] 6463 	mov	b,@r0
      001FE7 74 01            [12] 6464 	mov	a,#0x01
      001FE9 12 41 61         [24] 6465 	lcall	__gptrput
      001FEC A3               [24] 6466 	inc	dptr
      001FED E4               [12] 6467 	clr	a
      001FEE 12 41 61         [24] 6468 	lcall	__gptrput
      001FF1 02 21 00         [24] 6469 	ljmp	00110$
      001FF4                       6470 00104$:
                           001F37  6471 	C$fuzzy.h$2638$2_0$104 ==.
                                   6472 ;	../../fuzzy.h:2638: result->height
      001FF4 E5 08            [12] 6473 	mov	a,_bp
      001FF6 24 0A            [12] 6474 	add	a,#0x0a
      001FF8 F8               [12] 6475 	mov	r0,a
      001FF9 86 82            [24] 6476 	mov	dpl,@r0
      001FFB 08               [12] 6477 	inc	r0
      001FFC 86 83            [24] 6478 	mov	dph,@r0
      001FFE 08               [12] 6479 	inc	r0
      001FFF 86 F0            [24] 6480 	mov	b,@r0
      002001 12 43 A8         [24] 6481 	lcall	__gptrget
      002004 FC               [12] 6482 	mov	r4,a
      002005 A3               [24] 6483 	inc	dptr
      002006 12 43 A8         [24] 6484 	lcall	__gptrget
      002009 FD               [12] 6485 	mov	r5,a
      00200A A3               [24] 6486 	inc	dptr
      00200B 12 43 A8         [24] 6487 	lcall	__gptrget
      00200E FE               [12] 6488 	mov	r6,a
      00200F A3               [24] 6489 	inc	dptr
      002010 12 43 A8         [24] 6490 	lcall	__gptrget
      002013 FF               [12] 6491 	mov	r7,a
      002014 C0 04            [24] 6492 	push	ar4
      002016 C0 05            [24] 6493 	push	ar5
      002018 C0 06            [24] 6494 	push	ar6
      00201A C0 07            [24] 6495 	push	ar7
      00201C E5 08            [12] 6496 	mov	a,_bp
      00201E 24 14            [12] 6497 	add	a,#0x14
      002020 F8               [12] 6498 	mov	r0,a
      002021 86 82            [24] 6499 	mov	dpl, @r0
      002023 08               [12] 6500 	inc	r0
      002024 86 83            [24] 6501 	mov	dph, @r0
      002026 08               [12] 6502 	inc	r0
      002027 86 F0            [24] 6503 	mov	b, @r0
      002029 08               [12] 6504 	inc	r0
      00202A E6               [12] 6505 	mov	a, @r0
      00202B 12 41 50         [24] 6506 	lcall	___fseq
      00202E AF 82            [24] 6507 	mov	r7, dpl
      002030 E5 81            [12] 6508 	mov	a,sp
      002032 24 FC            [12] 6509 	add	a,#0xfc
      002034 F5 81            [12] 6510 	mov	sp,a
      002036 EF               [12] 6511 	mov	a,r7
      002037 70 03            [24] 6512 	jnz	00140$
      002039 02 21 00         [24] 6513 	ljmp	00110$
      00203C                       6514 00140$:
                           001F7F  6515 	C$fuzzy.h$2640$4_0$108 ==.
                                   6516 ;	../../fuzzy.h:2640: result->largest_position =
      00203C E5 08            [12] 6517 	mov	a,_bp
      00203E 24 04            [12] 6518 	add	a,#0x04
      002040 F8               [12] 6519 	mov	r0,a
      002041 86 82            [24] 6520 	mov	dpl,@r0
      002043 08               [12] 6521 	inc	r0
      002044 86 83            [24] 6522 	mov	dph,@r0
      002046 08               [12] 6523 	inc	r0
      002047 86 F0            [24] 6524 	mov	b,@r0
      002049 E5 08            [12] 6525 	mov	a,_bp
      00204B 24 10            [12] 6526 	add	a,#0x10
      00204D F9               [12] 6527 	mov	r1,a
      00204E E7               [12] 6528 	mov	a,@r1
      00204F 12 41 61         [24] 6529 	lcall	__gptrput
      002052 A3               [24] 6530 	inc	dptr
      002053 09               [12] 6531 	inc	r1
      002054 E7               [12] 6532 	mov	a,@r1
      002055 12 41 61         [24] 6533 	lcall	__gptrput
      002058 A3               [24] 6534 	inc	dptr
      002059 09               [12] 6535 	inc	r1
      00205A E7               [12] 6536 	mov	a,@r1
      00205B 12 41 61         [24] 6537 	lcall	__gptrput
      00205E A3               [24] 6538 	inc	dptr
      00205F 09               [12] 6539 	inc	r1
      002060 E7               [12] 6540 	mov	a,@r1
      002061 12 41 61         [24] 6541 	lcall	__gptrput
                           001FA7  6542 	C$fuzzy.h$2643$4_0$108 ==.
                                   6543 ;	../../fuzzy.h:2643: result->position_sum +=
      002064 E5 08            [12] 6544 	mov	a,_bp
      002066 24 07            [12] 6545 	add	a,#0x07
      002068 F8               [12] 6546 	mov	r0,a
      002069 86 82            [24] 6547 	mov	dpl,@r0
      00206B 08               [12] 6548 	inc	r0
      00206C 86 83            [24] 6549 	mov	dph,@r0
      00206E 08               [12] 6550 	inc	r0
      00206F 86 F0            [24] 6551 	mov	b,@r0
      002071 12 43 A8         [24] 6552 	lcall	__gptrget
      002074 FC               [12] 6553 	mov	r4,a
      002075 A3               [24] 6554 	inc	dptr
      002076 12 43 A8         [24] 6555 	lcall	__gptrget
      002079 FD               [12] 6556 	mov	r5,a
      00207A A3               [24] 6557 	inc	dptr
      00207B 12 43 A8         [24] 6558 	lcall	__gptrget
      00207E FE               [12] 6559 	mov	r6,a
      00207F A3               [24] 6560 	inc	dptr
      002080 12 43 A8         [24] 6561 	lcall	__gptrget
      002083 FF               [12] 6562 	mov	r7,a
      002084 E5 08            [12] 6563 	mov	a,_bp
      002086 24 10            [12] 6564 	add	a,#0x10
      002088 F8               [12] 6565 	mov	r0,a
      002089 E6               [12] 6566 	mov	a,@r0
      00208A C0 E0            [24] 6567 	push	acc
      00208C 08               [12] 6568 	inc	r0
      00208D E6               [12] 6569 	mov	a,@r0
      00208E C0 E0            [24] 6570 	push	acc
      002090 08               [12] 6571 	inc	r0
      002091 E6               [12] 6572 	mov	a,@r0
      002092 C0 E0            [24] 6573 	push	acc
      002094 08               [12] 6574 	inc	r0
      002095 E6               [12] 6575 	mov	a,@r0
      002096 C0 E0            [24] 6576 	push	acc
      002098 8C 82            [24] 6577 	mov	dpl, r4
      00209A 8D 83            [24] 6578 	mov	dph, r5
      00209C 8E F0            [24] 6579 	mov	b, r6
      00209E EF               [12] 6580 	mov	a, r7
      00209F 12 41 CE         [24] 6581 	lcall	___fsadd
      0020A2 AC 82            [24] 6582 	mov	r4, dpl
      0020A4 AD 83            [24] 6583 	mov	r5, dph
      0020A6 AE F0            [24] 6584 	mov	r6, b
      0020A8 FF               [12] 6585 	mov	r7, a
      0020A9 E5 81            [12] 6586 	mov	a,sp
      0020AB 24 FC            [12] 6587 	add	a,#0xfc
      0020AD F5 81            [12] 6588 	mov	sp,a
      0020AF E5 08            [12] 6589 	mov	a,_bp
      0020B1 24 07            [12] 6590 	add	a,#0x07
      0020B3 F8               [12] 6591 	mov	r0,a
      0020B4 86 82            [24] 6592 	mov	dpl,@r0
      0020B6 08               [12] 6593 	inc	r0
      0020B7 86 83            [24] 6594 	mov	dph,@r0
      0020B9 08               [12] 6595 	inc	r0
      0020BA 86 F0            [24] 6596 	mov	b,@r0
      0020BC EC               [12] 6597 	mov	a,r4
      0020BD 12 41 61         [24] 6598 	lcall	__gptrput
      0020C0 A3               [24] 6599 	inc	dptr
      0020C1 ED               [12] 6600 	mov	a,r5
      0020C2 12 41 61         [24] 6601 	lcall	__gptrput
      0020C5 A3               [24] 6602 	inc	dptr
      0020C6 EE               [12] 6603 	mov	a,r6
      0020C7 12 41 61         [24] 6604 	lcall	__gptrput
      0020CA A3               [24] 6605 	inc	dptr
      0020CB EF               [12] 6606 	mov	a,r7
      0020CC 12 41 61         [24] 6607 	lcall	__gptrput
                           002012  6608 	C$fuzzy.h$2646$4_0$108 ==.
                                   6609 ;	../../fuzzy.h:2646: result->position_count++;
      0020CF E5 08            [12] 6610 	mov	a,_bp
      0020D1 24 0D            [12] 6611 	add	a,#0x0d
      0020D3 F8               [12] 6612 	mov	r0,a
      0020D4 86 82            [24] 6613 	mov	dpl,@r0
      0020D6 08               [12] 6614 	inc	r0
      0020D7 86 83            [24] 6615 	mov	dph,@r0
      0020D9 08               [12] 6616 	inc	r0
      0020DA 86 F0            [24] 6617 	mov	b,@r0
      0020DC 12 43 A8         [24] 6618 	lcall	__gptrget
      0020DF FF               [12] 6619 	mov	r7,a
      0020E0 A3               [24] 6620 	inc	dptr
      0020E1 12 43 A8         [24] 6621 	lcall	__gptrget
      0020E4 FE               [12] 6622 	mov	r6,a
      0020E5 0F               [12] 6623 	inc	r7
      0020E6 BF 00 01         [24] 6624 	cjne	r7,#0x00,00141$
      0020E9 0E               [12] 6625 	inc	r6
      0020EA                       6626 00141$:
      0020EA E5 08            [12] 6627 	mov	a,_bp
      0020EC 24 0D            [12] 6628 	add	a,#0x0d
      0020EE F8               [12] 6629 	mov	r0,a
      0020EF 86 82            [24] 6630 	mov	dpl,@r0
      0020F1 08               [12] 6631 	inc	r0
      0020F2 86 83            [24] 6632 	mov	dph,@r0
      0020F4 08               [12] 6633 	inc	r0
      0020F5 86 F0            [24] 6634 	mov	b,@r0
      0020F7 EF               [12] 6635 	mov	a,r7
      0020F8 12 41 61         [24] 6636 	lcall	__gptrput
      0020FB A3               [24] 6637 	inc	dptr
      0020FC EE               [12] 6638 	mov	a,r6
      0020FD 12 41 61         [24] 6639 	lcall	__gptrput
      002100                       6640 00110$:
                           002043  6641 	C$fuzzy.h$2608$2_0$104 ==.
                                   6642 ;	../../fuzzy.h:2608: ) {
      002100 E5 08            [12] 6643 	mov	a,_bp
      002102 24 EF            [12] 6644 	add	a,#0xef
      002104 F8               [12] 6645 	mov	r0,a
      002105 E6               [12] 6646 	mov	a,@r0
      002106 C0 E0            [24] 6647 	push	acc
      002108 08               [12] 6648 	inc	r0
      002109 E6               [12] 6649 	mov	a,@r0
      00210A C0 E0            [24] 6650 	push	acc
      00210C 08               [12] 6651 	inc	r0
      00210D E6               [12] 6652 	mov	a,@r0
      00210E C0 E0            [24] 6653 	push	acc
      002110 08               [12] 6654 	inc	r0
      002111 E6               [12] 6655 	mov	a,@r0
      002112 C0 E0            [24] 6656 	push	acc
      002114 E5 08            [12] 6657 	mov	a,_bp
      002116 24 10            [12] 6658 	add	a,#0x10
      002118 F8               [12] 6659 	mov	r0,a
      002119 86 82            [24] 6660 	mov	dpl, @r0
      00211B 08               [12] 6661 	inc	r0
      00211C 86 83            [24] 6662 	mov	dph, @r0
      00211E 08               [12] 6663 	inc	r0
      00211F 86 F0            [24] 6664 	mov	b, @r0
      002121 08               [12] 6665 	inc	r0
      002122 E6               [12] 6666 	mov	a, @r0
      002123 12 41 CE         [24] 6667 	lcall	___fsadd
      002126 C8               [12] 6668 	xch	a,r0
      002127 E5 08            [12] 6669 	mov	a,_bp
      002129 24 10            [12] 6670 	add	a,#0x10
      00212B C8               [12] 6671 	xch	a,r0
      00212C A6 82            [24] 6672 	mov	@r0, dpl
      00212E 08               [12] 6673 	inc	r0
      00212F A6 83            [24] 6674 	mov	@r0, dph
      002131 08               [12] 6675 	inc	r0
      002132 A6 F0            [24] 6676 	mov	@r0, b
      002134 08               [12] 6677 	inc	r0
      002135 F6               [12] 6678 	mov	@r0,a
      002136 E5 81            [12] 6679 	mov	a,sp
      002138 24 FC            [12] 6680 	add	a,#0xfc
      00213A F5 81            [12] 6681 	mov	sp,a
      00213C 02 1E 57         [24] 6682 	ljmp	00109$
      00213F                       6683 00111$:
                           002082  6684 	C$fuzzy.h$2649$2_0$104 ==.
                                   6685 ;	../../fuzzy.h:2649: }
      00213F 85 08 81         [24] 6686 	mov	sp,_bp
      002142 D0 08            [24] 6687 	pop	_bp
                           002087  6688 	C$fuzzy.h$2649$2_0$104 ==.
                           002087  6689 	XFsugeno_demo$fuzzy_rules_maximum_result$0$0 ==.
      002144 22               [24] 6690 	ret
                                   6691 ;------------------------------------------------------------
                                   6692 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_cog'
                                   6693 ;------------------------------------------------------------
                                   6694 ;lower         Allocated to stack - _bp -6 +4 
                                   6695 ;upper         Allocated to stack - _bp -10 +4 
                                   6696 ;step          Allocated to stack - _bp -14 +4 
                                   6697 ;implication_method Allocated to stack - _bp -15 +1 
                                   6698 ;aggregation_method Allocated to stack - _bp -16 +1 
                                   6699 ;rules         Allocated to stack - _bp +1 +3 
                                   6700 ;weighted_sum  Allocated to stack - _bp +4 +4 
                                   6701 ;height_sum    Allocated to stack - _bp +8 +4 
                                   6702 ;value         Allocated to stack - _bp +12 +4 
                                   6703 ;height        Allocated to stack - _bp +16 +4 
                                   6704 ;------------------------------------------------------------
                           002088  6705 	G$fuzzy_rules_defuzzify_cog$0$0 ==.
                           002088  6706 	C$fuzzy.h$2656$2_0$110 ==.
                                   6707 ;	../../fuzzy.h:2656: float fuzzy_rules_defuzzify_cog(
                                   6708 ;	-----------------------------------------
                                   6709 ;	 function fuzzy_rules_defuzzify_cog
                                   6710 ;	-----------------------------------------
      002145                       6711 _fuzzy_rules_defuzzify_cog:
      002145 C0 08            [24] 6712 	push	_bp
      002147 85 81 08         [24] 6713 	mov	_bp,sp
      00214A C0 82            [24] 6714 	push	dpl
      00214C C0 83            [24] 6715 	push	dph
      00214E C0 F0            [24] 6716 	push	b
      002150 E5 81            [12] 6717 	mov	a,sp
      002152 24 10            [12] 6718 	add	a,#0x10
      002154 F5 81            [12] 6719 	mov	sp,a
                           002099  6720 	C$fuzzy.h$2671$1_0$110 ==.
                                   6721 ;	../../fuzzy.h:2671: 0.0f;
      002156 E5 08            [12] 6722 	mov	a,_bp
      002158 24 04            [12] 6723 	add	a,#0x04
      00215A F8               [12] 6724 	mov	r0,a
      00215B E4               [12] 6725 	clr	a
      00215C F6               [12] 6726 	mov	@r0,a
      00215D 08               [12] 6727 	inc	r0
      00215E F6               [12] 6728 	mov	@r0,a
      00215F 08               [12] 6729 	inc	r0
      002160 F6               [12] 6730 	mov	@r0,a
      002161 08               [12] 6731 	inc	r0
      002162 F6               [12] 6732 	mov	@r0,a
                           0020A6  6733 	C$fuzzy.h$2674$1_0$110 ==.
                                   6734 ;	../../fuzzy.h:2674: 0.0f;
      002163 E5 08            [12] 6735 	mov	a,_bp
      002165 24 08            [12] 6736 	add	a,#0x08
      002167 F8               [12] 6737 	mov	r0,a
      002168 E4               [12] 6738 	clr	a
      002169 F6               [12] 6739 	mov	@r0,a
      00216A 08               [12] 6740 	inc	r0
      00216B F6               [12] 6741 	mov	@r0,a
      00216C 08               [12] 6742 	inc	r0
      00216D F6               [12] 6743 	mov	@r0,a
      00216E 08               [12] 6744 	inc	r0
      00216F F6               [12] 6745 	mov	@r0,a
                           0020B3  6746 	C$fuzzy.h$2677$2_0$111 ==.
                                   6747 ;	../../fuzzy.h:2677: value = lower;
      002170 E5 08            [12] 6748 	mov	a,_bp
      002172 24 FA            [12] 6749 	add	a,#0xfa
      002174 F8               [12] 6750 	mov	r0,a
      002175 E5 08            [12] 6751 	mov	a,_bp
      002177 24 0C            [12] 6752 	add	a,#0x0c
      002179 F9               [12] 6753 	mov	r1,a
      00217A E6               [12] 6754 	mov	a,@r0
      00217B F7               [12] 6755 	mov	@r1,a
      00217C 08               [12] 6756 	inc	r0
      00217D E6               [12] 6757 	mov	a,@r0
      00217E 09               [12] 6758 	inc	r1
      00217F F7               [12] 6759 	mov	@r1,a
      002180 08               [12] 6760 	inc	r0
      002181 E6               [12] 6761 	mov	a,@r0
      002182 09               [12] 6762 	inc	r1
      002183 F7               [12] 6763 	mov	@r1,a
      002184 08               [12] 6764 	inc	r0
      002185 E6               [12] 6765 	mov	a,@r0
      002186 09               [12] 6766 	inc	r1
      002187 F7               [12] 6767 	mov	@r1,a
      002188                       6768 00105$:
                           0020CB  6769 	C$fuzzy.h$2678$1_0$110 ==.
                                   6770 ;	../../fuzzy.h:2678: value <= upper;
      002188 E5 08            [12] 6771 	mov	a,_bp
      00218A 24 0C            [12] 6772 	add	a,#0x0c
      00218C F8               [12] 6773 	mov	r0,a
      00218D E6               [12] 6774 	mov	a,@r0
      00218E C0 E0            [24] 6775 	push	acc
      002190 08               [12] 6776 	inc	r0
      002191 E6               [12] 6777 	mov	a,@r0
      002192 C0 E0            [24] 6778 	push	acc
      002194 08               [12] 6779 	inc	r0
      002195 E6               [12] 6780 	mov	a,@r0
      002196 C0 E0            [24] 6781 	push	acc
      002198 08               [12] 6782 	inc	r0
      002199 E6               [12] 6783 	mov	a,@r0
      00219A C0 E0            [24] 6784 	push	acc
      00219C E5 08            [12] 6785 	mov	a,_bp
      00219E 24 F6            [12] 6786 	add	a,#0xf6
      0021A0 F8               [12] 6787 	mov	r0,a
      0021A1 86 82            [24] 6788 	mov	dpl, @r0
      0021A3 08               [12] 6789 	inc	r0
      0021A4 86 83            [24] 6790 	mov	dph, @r0
      0021A6 08               [12] 6791 	inc	r0
      0021A7 86 F0            [24] 6792 	mov	b, @r0
      0021A9 08               [12] 6793 	inc	r0
      0021AA E6               [12] 6794 	mov	a, @r0
      0021AB 12 41 7C         [24] 6795 	lcall	___fslt
      0021AE E5 81            [12] 6796 	mov	a,sp
      0021B0 24 FC            [12] 6797 	add	a,#0xfc
      0021B2 F5 81            [12] 6798 	mov	sp,a
      0021B4 E5 82            [12] 6799 	mov	a, dpl
      0021B6 24 FF            [12] 6800 	add	a,#0xff
      0021B8 92 00            [24] 6801 	mov	b0,c
      0021BA 50 03            [24] 6802 	jnc	00127$
      0021BC 02 22 E5         [24] 6803 	ljmp	00101$
      0021BF                       6804 00127$:
                           002102  6805 	C$fuzzy.h$2683$3_0$112 ==.
                                   6806 ;	../../fuzzy.h:2683: rules,
      0021BF E5 08            [12] 6807 	mov	a,_bp
      0021C1 24 F0            [12] 6808 	add	a,#0xf0
      0021C3 F8               [12] 6809 	mov	r0,a
      0021C4 E6               [12] 6810 	mov	a,@r0
      0021C5 C0 E0            [24] 6811 	push	acc
      0021C7 E5 08            [12] 6812 	mov	a,_bp
      0021C9 24 F1            [12] 6813 	add	a,#0xf1
      0021CB F8               [12] 6814 	mov	r0,a
      0021CC E6               [12] 6815 	mov	a,@r0
      0021CD C0 E0            [24] 6816 	push	acc
      0021CF E5 08            [12] 6817 	mov	a,_bp
      0021D1 24 0C            [12] 6818 	add	a,#0x0c
      0021D3 F8               [12] 6819 	mov	r0,a
      0021D4 E6               [12] 6820 	mov	a,@r0
      0021D5 C0 E0            [24] 6821 	push	acc
      0021D7 08               [12] 6822 	inc	r0
      0021D8 E6               [12] 6823 	mov	a,@r0
      0021D9 C0 E0            [24] 6824 	push	acc
      0021DB 08               [12] 6825 	inc	r0
      0021DC E6               [12] 6826 	mov	a,@r0
      0021DD C0 E0            [24] 6827 	push	acc
      0021DF 08               [12] 6828 	inc	r0
      0021E0 E6               [12] 6829 	mov	a,@r0
      0021E1 C0 E0            [24] 6830 	push	acc
      0021E3 A8 08            [24] 6831 	mov	r0,_bp
      0021E5 08               [12] 6832 	inc	r0
      0021E6 86 82            [24] 6833 	mov	dpl, @r0
      0021E8 08               [12] 6834 	inc	r0
      0021E9 86 83            [24] 6835 	mov	dph, @r0
      0021EB 08               [12] 6836 	inc	r0
      0021EC 86 F0            [24] 6837 	mov	b, @r0
      0021EE 12 1B 9E         [24] 6838 	lcall	_fuzzy_rules_aggregated_height
      0021F1 C8               [12] 6839 	xch	a,r0
      0021F2 E5 08            [12] 6840 	mov	a,_bp
      0021F4 24 10            [12] 6841 	add	a,#0x10
      0021F6 C8               [12] 6842 	xch	a,r0
      0021F7 A6 82            [24] 6843 	mov	@r0, dpl
      0021F9 08               [12] 6844 	inc	r0
      0021FA A6 83            [24] 6845 	mov	@r0, dph
      0021FC 08               [12] 6846 	inc	r0
      0021FD A6 F0            [24] 6847 	mov	@r0, b
      0021FF 08               [12] 6848 	inc	r0
      002200 F6               [12] 6849 	mov	@r0,a
      002201 E5 81            [12] 6850 	mov	a,sp
      002203 24 FA            [12] 6851 	add	a,#0xfa
      002205 F5 81            [12] 6852 	mov	sp,a
                           00214A  6853 	C$fuzzy.h$2691$1_0$110 ==.
                                   6854 ;	../../fuzzy.h:2691: height;
      002207 E5 08            [12] 6855 	mov	a,_bp
      002209 24 10            [12] 6856 	add	a,#0x10
      00220B F8               [12] 6857 	mov	r0,a
      00220C E6               [12] 6858 	mov	a,@r0
      00220D C0 E0            [24] 6859 	push	acc
      00220F 08               [12] 6860 	inc	r0
      002210 E6               [12] 6861 	mov	a,@r0
      002211 C0 E0            [24] 6862 	push	acc
      002213 08               [12] 6863 	inc	r0
      002214 E6               [12] 6864 	mov	a,@r0
      002215 C0 E0            [24] 6865 	push	acc
      002217 08               [12] 6866 	inc	r0
      002218 E6               [12] 6867 	mov	a,@r0
      002219 C0 E0            [24] 6868 	push	acc
      00221B E5 08            [12] 6869 	mov	a,_bp
      00221D 24 0C            [12] 6870 	add	a,#0x0c
      00221F F8               [12] 6871 	mov	r0,a
      002220 86 82            [24] 6872 	mov	dpl, @r0
      002222 08               [12] 6873 	inc	r0
      002223 86 83            [24] 6874 	mov	dph, @r0
      002225 08               [12] 6875 	inc	r0
      002226 86 F0            [24] 6876 	mov	b, @r0
      002228 08               [12] 6877 	inc	r0
      002229 E6               [12] 6878 	mov	a, @r0
      00222A 12 40 4C         [24] 6879 	lcall	___fsmul
      00222D AC 82            [24] 6880 	mov	r4, dpl
      00222F AD 83            [24] 6881 	mov	r5, dph
      002231 AE F0            [24] 6882 	mov	r6, b
      002233 FF               [12] 6883 	mov	r7, a
      002234 E5 81            [12] 6884 	mov	a,sp
      002236 24 FC            [12] 6885 	add	a,#0xfc
      002238 F5 81            [12] 6886 	mov	sp,a
      00223A C0 04            [24] 6887 	push	ar4
      00223C C0 05            [24] 6888 	push	ar5
      00223E C0 06            [24] 6889 	push	ar6
      002240 C0 07            [24] 6890 	push	ar7
                           002185  6891 	C$fuzzy.h$2694$1_0$110 ==.
                                   6892 ;	../../fuzzy.h:2694: height;
      002242 E5 08            [12] 6893 	mov	a,_bp
      002244 24 04            [12] 6894 	add	a,#0x04
      002246 F8               [12] 6895 	mov	r0,a
      002247 86 82            [24] 6896 	mov	dpl, @r0
      002249 08               [12] 6897 	inc	r0
      00224A 86 83            [24] 6898 	mov	dph, @r0
      00224C 08               [12] 6899 	inc	r0
      00224D 86 F0            [24] 6900 	mov	b, @r0
      00224F 08               [12] 6901 	inc	r0
      002250 E6               [12] 6902 	mov	a, @r0
      002251 12 41 CE         [24] 6903 	lcall	___fsadd
      002254 C8               [12] 6904 	xch	a,r0
      002255 E5 08            [12] 6905 	mov	a,_bp
      002257 24 04            [12] 6906 	add	a,#0x04
      002259 C8               [12] 6907 	xch	a,r0
      00225A A6 82            [24] 6908 	mov	@r0, dpl
      00225C 08               [12] 6909 	inc	r0
      00225D A6 83            [24] 6910 	mov	@r0, dph
      00225F 08               [12] 6911 	inc	r0
      002260 A6 F0            [24] 6912 	mov	@r0, b
      002262 08               [12] 6913 	inc	r0
      002263 F6               [12] 6914 	mov	@r0,a
      002264 E5 81            [12] 6915 	mov	a,sp
      002266 24 FC            [12] 6916 	add	a,#0xfc
      002268 F5 81            [12] 6917 	mov	sp,a
      00226A E5 08            [12] 6918 	mov	a,_bp
      00226C 24 10            [12] 6919 	add	a,#0x10
      00226E F8               [12] 6920 	mov	r0,a
      00226F E6               [12] 6921 	mov	a,@r0
      002270 C0 E0            [24] 6922 	push	acc
      002272 08               [12] 6923 	inc	r0
      002273 E6               [12] 6924 	mov	a,@r0
      002274 C0 E0            [24] 6925 	push	acc
      002276 08               [12] 6926 	inc	r0
      002277 E6               [12] 6927 	mov	a,@r0
      002278 C0 E0            [24] 6928 	push	acc
      00227A 08               [12] 6929 	inc	r0
      00227B E6               [12] 6930 	mov	a,@r0
      00227C C0 E0            [24] 6931 	push	acc
                           0021C1  6932 	C$fuzzy.h$2680$1_0$110 ==.
                                   6933 ;	../../fuzzy.h:2680: ) {
      00227E E5 08            [12] 6934 	mov	a,_bp
      002280 24 08            [12] 6935 	add	a,#0x08
      002282 F8               [12] 6936 	mov	r0,a
      002283 86 82            [24] 6937 	mov	dpl, @r0
      002285 08               [12] 6938 	inc	r0
      002286 86 83            [24] 6939 	mov	dph, @r0
      002288 08               [12] 6940 	inc	r0
      002289 86 F0            [24] 6941 	mov	b, @r0
      00228B 08               [12] 6942 	inc	r0
      00228C E6               [12] 6943 	mov	a, @r0
      00228D 12 41 CE         [24] 6944 	lcall	___fsadd
      002290 C8               [12] 6945 	xch	a,r0
      002291 E5 08            [12] 6946 	mov	a,_bp
      002293 24 08            [12] 6947 	add	a,#0x08
      002295 C8               [12] 6948 	xch	a,r0
      002296 A6 82            [24] 6949 	mov	@r0, dpl
      002298 08               [12] 6950 	inc	r0
      002299 A6 83            [24] 6951 	mov	@r0, dph
      00229B 08               [12] 6952 	inc	r0
      00229C A6 F0            [24] 6953 	mov	@r0, b
      00229E 08               [12] 6954 	inc	r0
      00229F F6               [12] 6955 	mov	@r0,a
      0022A0 E5 81            [12] 6956 	mov	a,sp
      0022A2 24 FC            [12] 6957 	add	a,#0xfc
      0022A4 F5 81            [12] 6958 	mov	sp,a
      0022A6 E5 08            [12] 6959 	mov	a,_bp
      0022A8 24 F2            [12] 6960 	add	a,#0xf2
      0022AA F8               [12] 6961 	mov	r0,a
      0022AB E6               [12] 6962 	mov	a,@r0
      0022AC C0 E0            [24] 6963 	push	acc
      0022AE 08               [12] 6964 	inc	r0
      0022AF E6               [12] 6965 	mov	a,@r0
      0022B0 C0 E0            [24] 6966 	push	acc
      0022B2 08               [12] 6967 	inc	r0
      0022B3 E6               [12] 6968 	mov	a,@r0
      0022B4 C0 E0            [24] 6969 	push	acc
      0022B6 08               [12] 6970 	inc	r0
      0022B7 E6               [12] 6971 	mov	a,@r0
      0022B8 C0 E0            [24] 6972 	push	acc
      0022BA E5 08            [12] 6973 	mov	a,_bp
      0022BC 24 0C            [12] 6974 	add	a,#0x0c
      0022BE F8               [12] 6975 	mov	r0,a
      0022BF 86 82            [24] 6976 	mov	dpl, @r0
      0022C1 08               [12] 6977 	inc	r0
      0022C2 86 83            [24] 6978 	mov	dph, @r0
      0022C4 08               [12] 6979 	inc	r0
      0022C5 86 F0            [24] 6980 	mov	b, @r0
      0022C7 08               [12] 6981 	inc	r0
      0022C8 E6               [12] 6982 	mov	a, @r0
      0022C9 12 41 CE         [24] 6983 	lcall	___fsadd
      0022CC C8               [12] 6984 	xch	a,r0
      0022CD E5 08            [12] 6985 	mov	a,_bp
      0022CF 24 0C            [12] 6986 	add	a,#0x0c
      0022D1 C8               [12] 6987 	xch	a,r0
      0022D2 A6 82            [24] 6988 	mov	@r0, dpl
      0022D4 08               [12] 6989 	inc	r0
      0022D5 A6 83            [24] 6990 	mov	@r0, dph
      0022D7 08               [12] 6991 	inc	r0
      0022D8 A6 F0            [24] 6992 	mov	@r0, b
      0022DA 08               [12] 6993 	inc	r0
      0022DB F6               [12] 6994 	mov	@r0,a
      0022DC E5 81            [12] 6995 	mov	a,sp
      0022DE 24 FC            [12] 6996 	add	a,#0xfc
      0022E0 F5 81            [12] 6997 	mov	sp,a
      0022E2 02 21 88         [24] 6998 	ljmp	00105$
      0022E5                       6999 00101$:
                           002228  7000 	C$fuzzy.h$2697$1_0$110 ==.
                                   7001 ;	../../fuzzy.h:2697: if (height_sum <= LEVEL_LO) {
      0022E5 E5 08            [12] 7002 	mov	a,_bp
      0022E7 24 08            [12] 7003 	add	a,#0x08
      0022E9 F8               [12] 7004 	mov	r0,a
      0022EA E6               [12] 7005 	mov	a,@r0
      0022EB C0 E0            [24] 7006 	push	acc
      0022ED 08               [12] 7007 	inc	r0
      0022EE E6               [12] 7008 	mov	a,@r0
      0022EF C0 E0            [24] 7009 	push	acc
      0022F1 08               [12] 7010 	inc	r0
      0022F2 E6               [12] 7011 	mov	a,@r0
      0022F3 C0 E0            [24] 7012 	push	acc
      0022F5 08               [12] 7013 	inc	r0
      0022F6 E6               [12] 7014 	mov	a,@r0
      0022F7 C0 E0            [24] 7015 	push	acc
      0022F9 90 00 00         [24] 7016 	mov	dptr,#0x0000
      0022FC E4               [12] 7017 	clr	a
      0022FD F5 F0            [12] 7018 	mov	b,a
      0022FF 12 41 7C         [24] 7019 	lcall	___fslt
      002302 E5 81            [12] 7020 	mov	a,sp
      002304 24 FC            [12] 7021 	add	a,#0xfc
      002306 F5 81            [12] 7022 	mov	sp,a
      002308 E5 82            [12] 7023 	mov	a, dpl
      00230A 24 FF            [12] 7024 	add	a,#0xff
      00230C 92 00            [24] 7025 	mov	b0,c
      00230E 40 08            [24] 7026 	jc	00103$
                           002253  7027 	C$fuzzy.h$2698$2_0$113 ==.
                                   7028 ;	../../fuzzy.h:2698: return 0.0f;
      002310 90 00 00         [24] 7029 	mov	dptr,#0x0000
      002313 E4               [12] 7030 	clr	a
      002314 F5 F0            [12] 7031 	mov	b,a
      002316 80 3A            [24] 7032 	sjmp	00107$
      002318                       7033 00103$:
                           00225B  7034 	C$fuzzy.h$2702$1_0$110 ==.
                                   7035 ;	../../fuzzy.h:2702: height_sum;
      002318 E5 08            [12] 7036 	mov	a,_bp
      00231A 24 08            [12] 7037 	add	a,#0x08
      00231C F8               [12] 7038 	mov	r0,a
      00231D E6               [12] 7039 	mov	a,@r0
      00231E C0 E0            [24] 7040 	push	acc
      002320 08               [12] 7041 	inc	r0
      002321 E6               [12] 7042 	mov	a,@r0
      002322 C0 E0            [24] 7043 	push	acc
      002324 08               [12] 7044 	inc	r0
      002325 E6               [12] 7045 	mov	a,@r0
      002326 C0 E0            [24] 7046 	push	acc
      002328 08               [12] 7047 	inc	r0
      002329 E6               [12] 7048 	mov	a,@r0
      00232A C0 E0            [24] 7049 	push	acc
      00232C E5 08            [12] 7050 	mov	a,_bp
      00232E 24 04            [12] 7051 	add	a,#0x04
      002330 F8               [12] 7052 	mov	r0,a
      002331 86 82            [24] 7053 	mov	dpl, @r0
      002333 08               [12] 7054 	inc	r0
      002334 86 83            [24] 7055 	mov	dph, @r0
      002336 08               [12] 7056 	inc	r0
      002337 86 F0            [24] 7057 	mov	b, @r0
      002339 08               [12] 7058 	inc	r0
      00233A E6               [12] 7059 	mov	a, @r0
      00233B 12 42 E5         [24] 7060 	lcall	___fsdiv
      00233E AC 82            [24] 7061 	mov	r4, dpl
      002340 AD 83            [24] 7062 	mov	r5, dph
      002342 AE F0            [24] 7063 	mov	r6, b
      002344 FF               [12] 7064 	mov	r7, a
      002345 E5 81            [12] 7065 	mov	a,sp
      002347 24 FC            [12] 7066 	add	a,#0xfc
      002349 F5 81            [12] 7067 	mov	sp,a
      00234B 8C 82            [24] 7068 	mov	dpl, r4
      00234D 8D 83            [24] 7069 	mov	dph, r5
      00234F 8E F0            [24] 7070 	mov	b, r6
      002351 EF               [12] 7071 	mov	a, r7
      002352                       7072 00107$:
                           002295  7073 	C$fuzzy.h$2703$1_0$110 ==.
                                   7074 ;	../../fuzzy.h:2703: }
      002352 85 08 81         [24] 7075 	mov	sp,_bp
      002355 D0 08            [24] 7076 	pop	_bp
                           00229A  7077 	C$fuzzy.h$2703$1_0$110 ==.
                           00229A  7078 	XG$fuzzy_rules_defuzzify_cog$0$0 ==.
      002357 22               [24] 7079 	ret
                                   7080 ;------------------------------------------------------------
                                   7081 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_boa'
                                   7082 ;------------------------------------------------------------
                                   7083 ;lower         Allocated to stack - _bp -6 +4 
                                   7084 ;upper         Allocated to stack - _bp -10 +4 
                                   7085 ;step          Allocated to stack - _bp -14 +4 
                                   7086 ;implication_method Allocated to stack - _bp -15 +1 
                                   7087 ;aggregation_method Allocated to stack - _bp -16 +1 
                                   7088 ;rules         Allocated to stack - _bp +1 +3 
                                   7089 ;total_area    Allocated to stack - _bp +8 +4 
                                   7090 ;half_area     Allocated to stack - _bp +12 +4 
                                   7091 ;accumulated_area Allocated to stack - _bp +16 +4 
                                   7092 ;value         Allocated to stack - _bp +20 +4 
                                   7093 ;sloc0         Allocated to stack - _bp +4 +4 
                                   7094 ;------------------------------------------------------------
                           00229B  7095 	G$fuzzy_rules_defuzzify_boa$0$0 ==.
                           00229B  7096 	C$fuzzy.h$2713$1_0$115 ==.
                                   7097 ;	../../fuzzy.h:2713: float fuzzy_rules_defuzzify_boa(
                                   7098 ;	-----------------------------------------
                                   7099 ;	 function fuzzy_rules_defuzzify_boa
                                   7100 ;	-----------------------------------------
      002358                       7101 _fuzzy_rules_defuzzify_boa:
      002358 C0 08            [24] 7102 	push	_bp
      00235A 85 81 08         [24] 7103 	mov	_bp,sp
      00235D C0 82            [24] 7104 	push	dpl
      00235F C0 83            [24] 7105 	push	dph
      002361 C0 F0            [24] 7106 	push	b
      002363 E5 81            [12] 7107 	mov	a,sp
      002365 24 14            [12] 7108 	add	a,#0x14
      002367 F5 81            [12] 7109 	mov	sp,a
                           0022AC  7110 	C$fuzzy.h$2728$1_0$115 ==.
                                   7111 ;	../../fuzzy.h:2728: 0.0f;
      002369 E5 08            [12] 7112 	mov	a,_bp
      00236B 24 08            [12] 7113 	add	a,#0x08
      00236D F8               [12] 7114 	mov	r0,a
      00236E E4               [12] 7115 	clr	a
      00236F F6               [12] 7116 	mov	@r0,a
      002370 08               [12] 7117 	inc	r0
      002371 F6               [12] 7118 	mov	@r0,a
      002372 08               [12] 7119 	inc	r0
      002373 F6               [12] 7120 	mov	@r0,a
      002374 08               [12] 7121 	inc	r0
      002375 F6               [12] 7122 	mov	@r0,a
                           0022B9  7123 	C$fuzzy.h$2731$2_0$116 ==.
                                   7124 ;	../../fuzzy.h:2731: value = lower;
      002376 E5 08            [12] 7125 	mov	a,_bp
      002378 24 FA            [12] 7126 	add	a,#0xfa
      00237A F8               [12] 7127 	mov	r0,a
      00237B E5 08            [12] 7128 	mov	a,_bp
      00237D 24 04            [12] 7129 	add	a,#0x04
      00237F F9               [12] 7130 	mov	r1,a
      002380 E6               [12] 7131 	mov	a,@r0
      002381 F7               [12] 7132 	mov	@r1,a
      002382 08               [12] 7133 	inc	r0
      002383 E6               [12] 7134 	mov	a,@r0
      002384 09               [12] 7135 	inc	r1
      002385 F7               [12] 7136 	mov	@r1,a
      002386 08               [12] 7137 	inc	r0
      002387 E6               [12] 7138 	mov	a,@r0
      002388 09               [12] 7139 	inc	r1
      002389 F7               [12] 7140 	mov	@r1,a
      00238A 08               [12] 7141 	inc	r0
      00238B E6               [12] 7142 	mov	a,@r0
      00238C 09               [12] 7143 	inc	r1
      00238D F7               [12] 7144 	mov	@r1,a
      00238E                       7145 00108$:
                           0022D1  7146 	C$fuzzy.h$2732$1_0$115 ==.
                                   7147 ;	../../fuzzy.h:2732: value <= upper;
      00238E E5 08            [12] 7148 	mov	a,_bp
      002390 24 04            [12] 7149 	add	a,#0x04
      002392 F8               [12] 7150 	mov	r0,a
      002393 E6               [12] 7151 	mov	a,@r0
      002394 C0 E0            [24] 7152 	push	acc
      002396 08               [12] 7153 	inc	r0
      002397 E6               [12] 7154 	mov	a,@r0
      002398 C0 E0            [24] 7155 	push	acc
      00239A 08               [12] 7156 	inc	r0
      00239B E6               [12] 7157 	mov	a,@r0
      00239C C0 E0            [24] 7158 	push	acc
      00239E 08               [12] 7159 	inc	r0
      00239F E6               [12] 7160 	mov	a,@r0
      0023A0 C0 E0            [24] 7161 	push	acc
      0023A2 E5 08            [12] 7162 	mov	a,_bp
      0023A4 24 F6            [12] 7163 	add	a,#0xf6
      0023A6 F8               [12] 7164 	mov	r0,a
      0023A7 86 82            [24] 7165 	mov	dpl, @r0
      0023A9 08               [12] 7166 	inc	r0
      0023AA 86 83            [24] 7167 	mov	dph, @r0
      0023AC 08               [12] 7168 	inc	r0
      0023AD 86 F0            [24] 7169 	mov	b, @r0
      0023AF 08               [12] 7170 	inc	r0
      0023B0 E6               [12] 7171 	mov	a, @r0
      0023B1 12 41 7C         [24] 7172 	lcall	___fslt
      0023B4 E5 81            [12] 7173 	mov	a,sp
      0023B6 24 FC            [12] 7174 	add	a,#0xfc
      0023B8 F5 81            [12] 7175 	mov	sp,a
      0023BA E5 82            [12] 7176 	mov	a, dpl
      0023BC 24 FF            [12] 7177 	add	a,#0xff
      0023BE 92 00            [24] 7178 	mov	b0,c
      0023C0 50 03            [24] 7179 	jnc	00157$
      0023C2 02 24 73         [24] 7180 	ljmp	00101$
      0023C5                       7181 00157$:
                           002308  7182 	C$fuzzy.h$2737$3_0$117 ==.
                                   7183 ;	../../fuzzy.h:2737: rules,
      0023C5 E5 08            [12] 7184 	mov	a,_bp
      0023C7 24 F0            [12] 7185 	add	a,#0xf0
      0023C9 F8               [12] 7186 	mov	r0,a
      0023CA E6               [12] 7187 	mov	a,@r0
      0023CB C0 E0            [24] 7188 	push	acc
      0023CD E5 08            [12] 7189 	mov	a,_bp
      0023CF 24 F1            [12] 7190 	add	a,#0xf1
      0023D1 F8               [12] 7191 	mov	r0,a
      0023D2 E6               [12] 7192 	mov	a,@r0
      0023D3 C0 E0            [24] 7193 	push	acc
      0023D5 E5 08            [12] 7194 	mov	a,_bp
      0023D7 24 04            [12] 7195 	add	a,#0x04
      0023D9 F8               [12] 7196 	mov	r0,a
      0023DA E6               [12] 7197 	mov	a,@r0
      0023DB C0 E0            [24] 7198 	push	acc
      0023DD 08               [12] 7199 	inc	r0
      0023DE E6               [12] 7200 	mov	a,@r0
      0023DF C0 E0            [24] 7201 	push	acc
      0023E1 08               [12] 7202 	inc	r0
      0023E2 E6               [12] 7203 	mov	a,@r0
      0023E3 C0 E0            [24] 7204 	push	acc
      0023E5 08               [12] 7205 	inc	r0
      0023E6 E6               [12] 7206 	mov	a,@r0
      0023E7 C0 E0            [24] 7207 	push	acc
      0023E9 A8 08            [24] 7208 	mov	r0,_bp
      0023EB 08               [12] 7209 	inc	r0
      0023EC 86 82            [24] 7210 	mov	dpl, @r0
      0023EE 08               [12] 7211 	inc	r0
      0023EF 86 83            [24] 7212 	mov	dph, @r0
      0023F1 08               [12] 7213 	inc	r0
      0023F2 86 F0            [24] 7214 	mov	b, @r0
      0023F4 12 1B 9E         [24] 7215 	lcall	_fuzzy_rules_aggregated_height
      0023F7 AC 82            [24] 7216 	mov	r4, dpl
      0023F9 AD 83            [24] 7217 	mov	r5, dph
      0023FB AE F0            [24] 7218 	mov	r6, b
      0023FD FF               [12] 7219 	mov	r7, a
      0023FE E5 81            [12] 7220 	mov	a,sp
      002400 24 FA            [12] 7221 	add	a,#0xfa
      002402 F5 81            [12] 7222 	mov	sp,a
      002404 C0 04            [24] 7223 	push	ar4
      002406 C0 05            [24] 7224 	push	ar5
      002408 C0 06            [24] 7225 	push	ar6
      00240A C0 07            [24] 7226 	push	ar7
                           00234F  7227 	C$fuzzy.h$2734$1_0$115 ==.
                                   7228 ;	../../fuzzy.h:2734: ) {
      00240C E5 08            [12] 7229 	mov	a,_bp
      00240E 24 08            [12] 7230 	add	a,#0x08
      002410 F8               [12] 7231 	mov	r0,a
      002411 86 82            [24] 7232 	mov	dpl, @r0
      002413 08               [12] 7233 	inc	r0
      002414 86 83            [24] 7234 	mov	dph, @r0
      002416 08               [12] 7235 	inc	r0
      002417 86 F0            [24] 7236 	mov	b, @r0
      002419 08               [12] 7237 	inc	r0
      00241A E6               [12] 7238 	mov	a, @r0
      00241B 12 41 CE         [24] 7239 	lcall	___fsadd
      00241E C8               [12] 7240 	xch	a,r0
      00241F E5 08            [12] 7241 	mov	a,_bp
      002421 24 08            [12] 7242 	add	a,#0x08
      002423 C8               [12] 7243 	xch	a,r0
      002424 A6 82            [24] 7244 	mov	@r0, dpl
      002426 08               [12] 7245 	inc	r0
      002427 A6 83            [24] 7246 	mov	@r0, dph
      002429 08               [12] 7247 	inc	r0
      00242A A6 F0            [24] 7248 	mov	@r0, b
      00242C 08               [12] 7249 	inc	r0
      00242D F6               [12] 7250 	mov	@r0,a
      00242E E5 81            [12] 7251 	mov	a,sp
      002430 24 FC            [12] 7252 	add	a,#0xfc
      002432 F5 81            [12] 7253 	mov	sp,a
      002434 E5 08            [12] 7254 	mov	a,_bp
      002436 24 F2            [12] 7255 	add	a,#0xf2
      002438 F8               [12] 7256 	mov	r0,a
      002439 E6               [12] 7257 	mov	a,@r0
      00243A C0 E0            [24] 7258 	push	acc
      00243C 08               [12] 7259 	inc	r0
      00243D E6               [12] 7260 	mov	a,@r0
      00243E C0 E0            [24] 7261 	push	acc
      002440 08               [12] 7262 	inc	r0
      002441 E6               [12] 7263 	mov	a,@r0
      002442 C0 E0            [24] 7264 	push	acc
      002444 08               [12] 7265 	inc	r0
      002445 E6               [12] 7266 	mov	a,@r0
      002446 C0 E0            [24] 7267 	push	acc
      002448 E5 08            [12] 7268 	mov	a,_bp
      00244A 24 04            [12] 7269 	add	a,#0x04
      00244C F8               [12] 7270 	mov	r0,a
      00244D 86 82            [24] 7271 	mov	dpl, @r0
      00244F 08               [12] 7272 	inc	r0
      002450 86 83            [24] 7273 	mov	dph, @r0
      002452 08               [12] 7274 	inc	r0
      002453 86 F0            [24] 7275 	mov	b, @r0
      002455 08               [12] 7276 	inc	r0
      002456 E6               [12] 7277 	mov	a, @r0
      002457 12 41 CE         [24] 7278 	lcall	___fsadd
      00245A C8               [12] 7279 	xch	a,r0
      00245B E5 08            [12] 7280 	mov	a,_bp
      00245D 24 04            [12] 7281 	add	a,#0x04
      00245F C8               [12] 7282 	xch	a,r0
      002460 A6 82            [24] 7283 	mov	@r0, dpl
      002462 08               [12] 7284 	inc	r0
      002463 A6 83            [24] 7285 	mov	@r0, dph
      002465 08               [12] 7286 	inc	r0
      002466 A6 F0            [24] 7287 	mov	@r0, b
      002468 08               [12] 7288 	inc	r0
      002469 F6               [12] 7289 	mov	@r0,a
      00246A E5 81            [12] 7290 	mov	a,sp
      00246C 24 FC            [12] 7291 	add	a,#0xfc
      00246E F5 81            [12] 7292 	mov	sp,a
      002470 02 23 8E         [24] 7293 	ljmp	00108$
      002473                       7294 00101$:
                           0023B6  7295 	C$fuzzy.h$2744$1_0$115 ==.
                                   7296 ;	../../fuzzy.h:2744: if (total_area <= LEVEL_LO) {
      002473 E5 08            [12] 7297 	mov	a,_bp
      002475 24 08            [12] 7298 	add	a,#0x08
      002477 F8               [12] 7299 	mov	r0,a
      002478 E6               [12] 7300 	mov	a,@r0
      002479 C0 E0            [24] 7301 	push	acc
      00247B 08               [12] 7302 	inc	r0
      00247C E6               [12] 7303 	mov	a,@r0
      00247D C0 E0            [24] 7304 	push	acc
      00247F 08               [12] 7305 	inc	r0
      002480 E6               [12] 7306 	mov	a,@r0
      002481 C0 E0            [24] 7307 	push	acc
      002483 08               [12] 7308 	inc	r0
      002484 E6               [12] 7309 	mov	a,@r0
      002485 C0 E0            [24] 7310 	push	acc
      002487 90 00 00         [24] 7311 	mov	dptr,#0x0000
      00248A E4               [12] 7312 	clr	a
      00248B F5 F0            [12] 7313 	mov	b,a
      00248D 12 41 7C         [24] 7314 	lcall	___fslt
      002490 E5 81            [12] 7315 	mov	a,sp
      002492 24 FC            [12] 7316 	add	a,#0xfc
      002494 F5 81            [12] 7317 	mov	sp,a
      002496 E5 82            [12] 7318 	mov	a, dpl
      002498 24 FF            [12] 7319 	add	a,#0xff
      00249A 92 00            [24] 7320 	mov	b0,c
      00249C 40 09            [24] 7321 	jc	00103$
                           0023E1  7322 	C$fuzzy.h$2745$2_0$118 ==.
                                   7323 ;	../../fuzzy.h:2745: return 0.0f;
      00249E 90 00 00         [24] 7324 	mov	dptr,#0x0000
      0024A1 E4               [12] 7325 	clr	a
      0024A2 F5 F0            [12] 7326 	mov	b,a
      0024A4 02 26 38         [24] 7327 	ljmp	00113$
      0024A7                       7328 00103$:
                           0023EA  7329 	C$fuzzy.h$2750$1_0$115 ==.
                                   7330 ;	../../fuzzy.h:2750: 2.0f;
      0024A7 E4               [12] 7331 	clr	a
      0024A8 C0 E0            [24] 7332 	push	acc
      0024AA C0 E0            [24] 7333 	push	acc
      0024AC C0 E0            [24] 7334 	push	acc
      0024AE 74 40            [12] 7335 	mov	a,#0x40
      0024B0 C0 E0            [24] 7336 	push	acc
                           0023F5  7337 	C$fuzzy.h$2753$1_0$115 ==.
                                   7338 ;	../../fuzzy.h:2753: 0.0f;
      0024B2 E5 08            [12] 7339 	mov	a,_bp
      0024B4 24 08            [12] 7340 	add	a,#0x08
      0024B6 F8               [12] 7341 	mov	r0,a
      0024B7 86 82            [24] 7342 	mov	dpl, @r0
      0024B9 08               [12] 7343 	inc	r0
      0024BA 86 83            [24] 7344 	mov	dph, @r0
      0024BC 08               [12] 7345 	inc	r0
      0024BD 86 F0            [24] 7346 	mov	b, @r0
      0024BF 08               [12] 7347 	inc	r0
      0024C0 E6               [12] 7348 	mov	a, @r0
      0024C1 12 42 E5         [24] 7349 	lcall	___fsdiv
      0024C4 C8               [12] 7350 	xch	a,r0
      0024C5 E5 08            [12] 7351 	mov	a,_bp
      0024C7 24 0C            [12] 7352 	add	a,#0x0c
      0024C9 C8               [12] 7353 	xch	a,r0
      0024CA A6 82            [24] 7354 	mov	@r0, dpl
      0024CC 08               [12] 7355 	inc	r0
      0024CD A6 83            [24] 7356 	mov	@r0, dph
      0024CF 08               [12] 7357 	inc	r0
      0024D0 A6 F0            [24] 7358 	mov	@r0, b
      0024D2 08               [12] 7359 	inc	r0
      0024D3 F6               [12] 7360 	mov	@r0,a
      0024D4 E5 81            [12] 7361 	mov	a,sp
      0024D6 24 FC            [12] 7362 	add	a,#0xfc
      0024D8 F5 81            [12] 7363 	mov	sp,a
      0024DA E5 08            [12] 7364 	mov	a,_bp
      0024DC 24 10            [12] 7365 	add	a,#0x10
      0024DE F8               [12] 7366 	mov	r0,a
      0024DF E4               [12] 7367 	clr	a
      0024E0 F6               [12] 7368 	mov	@r0,a
      0024E1 08               [12] 7369 	inc	r0
      0024E2 F6               [12] 7370 	mov	@r0,a
      0024E3 08               [12] 7371 	inc	r0
      0024E4 F6               [12] 7372 	mov	@r0,a
      0024E5 08               [12] 7373 	inc	r0
      0024E6 F6               [12] 7374 	mov	@r0,a
                           00242A  7375 	C$fuzzy.h$2756$2_0$119 ==.
                                   7376 ;	../../fuzzy.h:2756: value = lower;
      0024E7 E5 08            [12] 7377 	mov	a,_bp
      0024E9 24 FA            [12] 7378 	add	a,#0xfa
      0024EB F8               [12] 7379 	mov	r0,a
      0024EC E5 08            [12] 7380 	mov	a,_bp
      0024EE 24 14            [12] 7381 	add	a,#0x14
      0024F0 F9               [12] 7382 	mov	r1,a
      0024F1 E6               [12] 7383 	mov	a,@r0
      0024F2 F7               [12] 7384 	mov	@r1,a
      0024F3 08               [12] 7385 	inc	r0
      0024F4 E6               [12] 7386 	mov	a,@r0
      0024F5 09               [12] 7387 	inc	r1
      0024F6 F7               [12] 7388 	mov	@r1,a
      0024F7 08               [12] 7389 	inc	r0
      0024F8 E6               [12] 7390 	mov	a,@r0
      0024F9 09               [12] 7391 	inc	r1
      0024FA F7               [12] 7392 	mov	@r1,a
      0024FB 08               [12] 7393 	inc	r0
      0024FC E6               [12] 7394 	mov	a,@r0
      0024FD 09               [12] 7395 	inc	r1
      0024FE F7               [12] 7396 	mov	@r1,a
      0024FF                       7397 00111$:
                           002442  7398 	C$fuzzy.h$2757$1_0$115 ==.
                                   7399 ;	../../fuzzy.h:2757: value <= upper;
      0024FF E5 08            [12] 7400 	mov	a,_bp
      002501 24 14            [12] 7401 	add	a,#0x14
      002503 F8               [12] 7402 	mov	r0,a
      002504 E6               [12] 7403 	mov	a,@r0
      002505 C0 E0            [24] 7404 	push	acc
      002507 08               [12] 7405 	inc	r0
      002508 E6               [12] 7406 	mov	a,@r0
      002509 C0 E0            [24] 7407 	push	acc
      00250B 08               [12] 7408 	inc	r0
      00250C E6               [12] 7409 	mov	a,@r0
      00250D C0 E0            [24] 7410 	push	acc
      00250F 08               [12] 7411 	inc	r0
      002510 E6               [12] 7412 	mov	a,@r0
      002511 C0 E0            [24] 7413 	push	acc
      002513 E5 08            [12] 7414 	mov	a,_bp
      002515 24 F6            [12] 7415 	add	a,#0xf6
      002517 F8               [12] 7416 	mov	r0,a
      002518 86 82            [24] 7417 	mov	dpl, @r0
      00251A 08               [12] 7418 	inc	r0
      00251B 86 83            [24] 7419 	mov	dph, @r0
      00251D 08               [12] 7420 	inc	r0
      00251E 86 F0            [24] 7421 	mov	b, @r0
      002520 08               [12] 7422 	inc	r0
      002521 E6               [12] 7423 	mov	a, @r0
      002522 12 41 7C         [24] 7424 	lcall	___fslt
      002525 E5 81            [12] 7425 	mov	a,sp
      002527 24 FC            [12] 7426 	add	a,#0xfc
      002529 F5 81            [12] 7427 	mov	sp,a
      00252B E5 82            [12] 7428 	mov	a, dpl
      00252D 24 FF            [12] 7429 	add	a,#0xff
      00252F 92 00            [24] 7430 	mov	b0,c
      002531 50 03            [24] 7431 	jnc	00159$
      002533 02 26 29         [24] 7432 	ljmp	00106$
      002536                       7433 00159$:
                           002479  7434 	C$fuzzy.h$2762$3_0$120 ==.
                                   7435 ;	../../fuzzy.h:2762: rules,
      002536 E5 08            [12] 7436 	mov	a,_bp
      002538 24 F0            [12] 7437 	add	a,#0xf0
      00253A F8               [12] 7438 	mov	r0,a
      00253B E6               [12] 7439 	mov	a,@r0
      00253C C0 E0            [24] 7440 	push	acc
      00253E E5 08            [12] 7441 	mov	a,_bp
      002540 24 F1            [12] 7442 	add	a,#0xf1
      002542 F8               [12] 7443 	mov	r0,a
      002543 E6               [12] 7444 	mov	a,@r0
      002544 C0 E0            [24] 7445 	push	acc
      002546 E5 08            [12] 7446 	mov	a,_bp
      002548 24 14            [12] 7447 	add	a,#0x14
      00254A F8               [12] 7448 	mov	r0,a
      00254B E6               [12] 7449 	mov	a,@r0
      00254C C0 E0            [24] 7450 	push	acc
      00254E 08               [12] 7451 	inc	r0
      00254F E6               [12] 7452 	mov	a,@r0
      002550 C0 E0            [24] 7453 	push	acc
      002552 08               [12] 7454 	inc	r0
      002553 E6               [12] 7455 	mov	a,@r0
      002554 C0 E0            [24] 7456 	push	acc
      002556 08               [12] 7457 	inc	r0
      002557 E6               [12] 7458 	mov	a,@r0
      002558 C0 E0            [24] 7459 	push	acc
      00255A A8 08            [24] 7460 	mov	r0,_bp
      00255C 08               [12] 7461 	inc	r0
      00255D 86 82            [24] 7462 	mov	dpl, @r0
      00255F 08               [12] 7463 	inc	r0
      002560 86 83            [24] 7464 	mov	dph, @r0
      002562 08               [12] 7465 	inc	r0
      002563 86 F0            [24] 7466 	mov	b, @r0
      002565 12 1B 9E         [24] 7467 	lcall	_fuzzy_rules_aggregated_height
      002568 AA 82            [24] 7468 	mov	r2, dpl
      00256A AB 83            [24] 7469 	mov	r3, dph
      00256C AE F0            [24] 7470 	mov	r6, b
      00256E FF               [12] 7471 	mov	r7, a
      00256F E5 81            [12] 7472 	mov	a,sp
      002571 24 FA            [12] 7473 	add	a,#0xfa
      002573 F5 81            [12] 7474 	mov	sp,a
      002575 C0 02            [24] 7475 	push	ar2
      002577 C0 03            [24] 7476 	push	ar3
      002579 C0 06            [24] 7477 	push	ar6
      00257B C0 07            [24] 7478 	push	ar7
                           0024C0  7479 	C$fuzzy.h$2771$1_0$115 ==.
                                   7480 ;	../../fuzzy.h:2771: ) {
      00257D E5 08            [12] 7481 	mov	a,_bp
      00257F 24 10            [12] 7482 	add	a,#0x10
      002581 F8               [12] 7483 	mov	r0,a
      002582 86 82            [24] 7484 	mov	dpl, @r0
      002584 08               [12] 7485 	inc	r0
      002585 86 83            [24] 7486 	mov	dph, @r0
      002587 08               [12] 7487 	inc	r0
      002588 86 F0            [24] 7488 	mov	b, @r0
      00258A 08               [12] 7489 	inc	r0
      00258B E6               [12] 7490 	mov	a, @r0
      00258C 12 41 CE         [24] 7491 	lcall	___fsadd
      00258F C8               [12] 7492 	xch	a,r0
      002590 E5 08            [12] 7493 	mov	a,_bp
      002592 24 10            [12] 7494 	add	a,#0x10
      002594 C8               [12] 7495 	xch	a,r0
      002595 A6 82            [24] 7496 	mov	@r0, dpl
      002597 08               [12] 7497 	inc	r0
      002598 A6 83            [24] 7498 	mov	@r0, dph
      00259A 08               [12] 7499 	inc	r0
      00259B A6 F0            [24] 7500 	mov	@r0, b
      00259D 08               [12] 7501 	inc	r0
      00259E F6               [12] 7502 	mov	@r0,a
      00259F E5 81            [12] 7503 	mov	a,sp
      0025A1 24 FC            [12] 7504 	add	a,#0xfc
      0025A3 F5 81            [12] 7505 	mov	sp,a
      0025A5 E5 08            [12] 7506 	mov	a,_bp
      0025A7 24 0C            [12] 7507 	add	a,#0x0c
      0025A9 F8               [12] 7508 	mov	r0,a
      0025AA E6               [12] 7509 	mov	a,@r0
      0025AB C0 E0            [24] 7510 	push	acc
      0025AD 08               [12] 7511 	inc	r0
      0025AE E6               [12] 7512 	mov	a,@r0
      0025AF C0 E0            [24] 7513 	push	acc
      0025B1 08               [12] 7514 	inc	r0
      0025B2 E6               [12] 7515 	mov	a,@r0
      0025B3 C0 E0            [24] 7516 	push	acc
      0025B5 08               [12] 7517 	inc	r0
      0025B6 E6               [12] 7518 	mov	a,@r0
      0025B7 C0 E0            [24] 7519 	push	acc
      0025B9 E5 08            [12] 7520 	mov	a,_bp
      0025BB 24 10            [12] 7521 	add	a,#0x10
      0025BD F8               [12] 7522 	mov	r0,a
      0025BE 86 82            [24] 7523 	mov	dpl, @r0
      0025C0 08               [12] 7524 	inc	r0
      0025C1 86 83            [24] 7525 	mov	dph, @r0
      0025C3 08               [12] 7526 	inc	r0
      0025C4 86 F0            [24] 7527 	mov	b, @r0
      0025C6 08               [12] 7528 	inc	r0
      0025C7 E6               [12] 7529 	mov	a, @r0
      0025C8 12 41 7C         [24] 7530 	lcall	___fslt
      0025CB E5 81            [12] 7531 	mov	a,sp
      0025CD 24 FC            [12] 7532 	add	a,#0xfc
      0025CF F5 81            [12] 7533 	mov	sp,a
      0025D1 E5 82            [12] 7534 	mov	a, dpl
      0025D3 24 FF            [12] 7535 	add	a,#0xff
      0025D5 92 00            [24] 7536 	mov	b0,c
      0025D7 40 11            [24] 7537 	jc	00112$
                           00251C  7538 	C$fuzzy.h$2772$4_0$121 ==.
                                   7539 ;	../../fuzzy.h:2772: return value;
      0025D9 E5 08            [12] 7540 	mov	a,_bp
      0025DB 24 14            [12] 7541 	add	a,#0x14
      0025DD F8               [12] 7542 	mov	r0,a
      0025DE 86 82            [24] 7543 	mov	dpl, @r0
      0025E0 08               [12] 7544 	inc	r0
      0025E1 86 83            [24] 7545 	mov	dph, @r0
      0025E3 08               [12] 7546 	inc	r0
      0025E4 86 F0            [24] 7547 	mov	b, @r0
      0025E6 08               [12] 7548 	inc	r0
      0025E7 E6               [12] 7549 	mov	a, @r0
      0025E8 80 4E            [24] 7550 	sjmp	00113$
      0025EA                       7551 00112$:
                           00252D  7552 	C$fuzzy.h$2759$1_0$115 ==.
                                   7553 ;	../../fuzzy.h:2759: ) {
      0025EA E5 08            [12] 7554 	mov	a,_bp
      0025EC 24 F2            [12] 7555 	add	a,#0xf2
      0025EE F8               [12] 7556 	mov	r0,a
      0025EF E6               [12] 7557 	mov	a,@r0
      0025F0 C0 E0            [24] 7558 	push	acc
      0025F2 08               [12] 7559 	inc	r0
      0025F3 E6               [12] 7560 	mov	a,@r0
      0025F4 C0 E0            [24] 7561 	push	acc
      0025F6 08               [12] 7562 	inc	r0
      0025F7 E6               [12] 7563 	mov	a,@r0
      0025F8 C0 E0            [24] 7564 	push	acc
      0025FA 08               [12] 7565 	inc	r0
      0025FB E6               [12] 7566 	mov	a,@r0
      0025FC C0 E0            [24] 7567 	push	acc
      0025FE E5 08            [12] 7568 	mov	a,_bp
      002600 24 14            [12] 7569 	add	a,#0x14
      002602 F8               [12] 7570 	mov	r0,a
      002603 86 82            [24] 7571 	mov	dpl, @r0
      002605 08               [12] 7572 	inc	r0
      002606 86 83            [24] 7573 	mov	dph, @r0
      002608 08               [12] 7574 	inc	r0
      002609 86 F0            [24] 7575 	mov	b, @r0
      00260B 08               [12] 7576 	inc	r0
      00260C E6               [12] 7577 	mov	a, @r0
      00260D 12 41 CE         [24] 7578 	lcall	___fsadd
      002610 C8               [12] 7579 	xch	a,r0
      002611 E5 08            [12] 7580 	mov	a,_bp
      002613 24 14            [12] 7581 	add	a,#0x14
      002615 C8               [12] 7582 	xch	a,r0
      002616 A6 82            [24] 7583 	mov	@r0, dpl
      002618 08               [12] 7584 	inc	r0
      002619 A6 83            [24] 7585 	mov	@r0, dph
      00261B 08               [12] 7586 	inc	r0
      00261C A6 F0            [24] 7587 	mov	@r0, b
      00261E 08               [12] 7588 	inc	r0
      00261F F6               [12] 7589 	mov	@r0,a
      002620 E5 81            [12] 7590 	mov	a,sp
      002622 24 FC            [12] 7591 	add	a,#0xfc
      002624 F5 81            [12] 7592 	mov	sp,a
      002626 02 24 FF         [24] 7593 	ljmp	00111$
      002629                       7594 00106$:
                           00256C  7595 	C$fuzzy.h$2776$1_0$115 ==.
                                   7596 ;	../../fuzzy.h:2776: return upper;
      002629 E5 08            [12] 7597 	mov	a,_bp
      00262B 24 F6            [12] 7598 	add	a,#0xf6
      00262D F8               [12] 7599 	mov	r0,a
      00262E 86 82            [24] 7600 	mov	dpl, @r0
      002630 08               [12] 7601 	inc	r0
      002631 86 83            [24] 7602 	mov	dph, @r0
      002633 08               [12] 7603 	inc	r0
      002634 86 F0            [24] 7604 	mov	b, @r0
      002636 08               [12] 7605 	inc	r0
      002637 E6               [12] 7606 	mov	a, @r0
      002638                       7607 00113$:
                           00257B  7608 	C$fuzzy.h$2777$1_0$115 ==.
                                   7609 ;	../../fuzzy.h:2777: }
      002638 85 08 81         [24] 7610 	mov	sp,_bp
      00263B D0 08            [24] 7611 	pop	_bp
                           002580  7612 	C$fuzzy.h$2777$1_0$115 ==.
                           002580  7613 	XG$fuzzy_rules_defuzzify_boa$0$0 ==.
      00263D 22               [24] 7614 	ret
                                   7615 ;------------------------------------------------------------
                                   7616 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_cos'
                                   7617 ;------------------------------------------------------------
                                   7618 ;lower         Allocated to stack - _bp -6 +4 
                                   7619 ;upper         Allocated to stack - _bp -10 +4 
                                   7620 ;step          Allocated to stack - _bp -14 +4 
                                   7621 ;implication_method Allocated to stack - _bp -15 +1 
                                   7622 ;rules         Allocated to stack - _bp +1 +3 
                                   7623 ;weighted_sum  Allocated to stack - _bp +9 +4 
                                   7624 ;height_sum    Allocated to stack - _bp +13 +4 
                                   7625 ;value         Allocated to stack - _bp +17 +4 
                                   7626 ;output_membership Allocated to stack - _bp +21 +4 
                                   7627 ;implied_height Allocated to stack - _bp +25 +4 
                                   7628 ;index         Allocated to stack - _bp +29 +2 
                                   7629 ;sloc0         Allocated to stack - _bp +4 +3 
                                   7630 ;sloc1         Allocated to stack - _bp +7 +2 
                                   7631 ;------------------------------------------------------------
                           002581  7632 	G$fuzzy_rules_defuzzify_cos$0$0 ==.
                           002581  7633 	C$fuzzy.h$2789$1_0$123 ==.
                                   7634 ;	../../fuzzy.h:2789: float fuzzy_rules_defuzzify_cos(
                                   7635 ;	-----------------------------------------
                                   7636 ;	 function fuzzy_rules_defuzzify_cos
                                   7637 ;	-----------------------------------------
      00263E                       7638 _fuzzy_rules_defuzzify_cos:
      00263E C0 08            [24] 7639 	push	_bp
      002640 85 81 08         [24] 7640 	mov	_bp,sp
      002643 C0 82            [24] 7641 	push	dpl
      002645 C0 83            [24] 7642 	push	dph
      002647 C0 F0            [24] 7643 	push	b
      002649 E5 81            [12] 7644 	mov	a,sp
      00264B 24 1B            [12] 7645 	add	a,#0x1b
      00264D F5 81            [12] 7646 	mov	sp,a
                           002592  7647 	C$fuzzy.h$2805$1_0$123 ==.
                                   7648 ;	../../fuzzy.h:2805: 0.0f;
      00264F E5 08            [12] 7649 	mov	a,_bp
      002651 24 09            [12] 7650 	add	a,#0x09
      002653 F8               [12] 7651 	mov	r0,a
      002654 E4               [12] 7652 	clr	a
      002655 F6               [12] 7653 	mov	@r0,a
      002656 08               [12] 7654 	inc	r0
      002657 F6               [12] 7655 	mov	@r0,a
      002658 08               [12] 7656 	inc	r0
      002659 F6               [12] 7657 	mov	@r0,a
      00265A 08               [12] 7658 	inc	r0
      00265B F6               [12] 7659 	mov	@r0,a
                           00259F  7660 	C$fuzzy.h$2808$1_0$123 ==.
                                   7661 ;	../../fuzzy.h:2808: 0.0f;
      00265C E5 08            [12] 7662 	mov	a,_bp
      00265E 24 0D            [12] 7663 	add	a,#0x0d
      002660 F8               [12] 7664 	mov	r0,a
      002661 E4               [12] 7665 	clr	a
      002662 F6               [12] 7666 	mov	@r0,a
      002663 08               [12] 7667 	inc	r0
      002664 F6               [12] 7668 	mov	@r0,a
      002665 08               [12] 7669 	inc	r0
      002666 F6               [12] 7670 	mov	@r0,a
      002667 08               [12] 7671 	inc	r0
      002668 F6               [12] 7672 	mov	@r0,a
                           0025AC  7673 	C$fuzzy.h$2811$2_0$124 ==.
                                   7674 ;	../../fuzzy.h:2811: value = lower;
      002669 E5 08            [12] 7675 	mov	a,_bp
      00266B 24 FA            [12] 7676 	add	a,#0xfa
      00266D F8               [12] 7677 	mov	r0,a
      00266E E5 08            [12] 7678 	mov	a,_bp
      002670 24 11            [12] 7679 	add	a,#0x11
      002672 F9               [12] 7680 	mov	r1,a
      002673 E6               [12] 7681 	mov	a,@r0
      002674 F7               [12] 7682 	mov	@r1,a
      002675 08               [12] 7683 	inc	r0
      002676 E6               [12] 7684 	mov	a,@r0
      002677 09               [12] 7685 	inc	r1
      002678 F7               [12] 7686 	mov	@r1,a
      002679 08               [12] 7687 	inc	r0
      00267A E6               [12] 7688 	mov	a,@r0
      00267B 09               [12] 7689 	inc	r1
      00267C F7               [12] 7690 	mov	@r1,a
      00267D 08               [12] 7691 	inc	r0
      00267E E6               [12] 7692 	mov	a,@r0
      00267F 09               [12] 7693 	inc	r1
      002680 F7               [12] 7694 	mov	@r1,a
      002681 A8 08            [24] 7695 	mov	r0,_bp
      002683 08               [12] 7696 	inc	r0
      002684 E5 08            [12] 7697 	mov	a,_bp
      002686 24 04            [12] 7698 	add	a,#0x04
      002688 F9               [12] 7699 	mov	r1,a
      002689 E6               [12] 7700 	mov	a,@r0
      00268A F7               [12] 7701 	mov	@r1,a
      00268B 08               [12] 7702 	inc	r0
      00268C E6               [12] 7703 	mov	a,@r0
      00268D 09               [12] 7704 	inc	r1
      00268E F7               [12] 7705 	mov	@r1,a
      00268F 08               [12] 7706 	inc	r0
      002690 E6               [12] 7707 	mov	a,@r0
      002691 09               [12] 7708 	inc	r1
      002692 F7               [12] 7709 	mov	@r1,a
      002693 A8 08            [24] 7710 	mov	r0,_bp
      002695 08               [12] 7711 	inc	r0
      002696 74 90            [12] 7712 	mov	a,#0x90
      002698 26               [12] 7713 	add	a, @r0
      002699 FC               [12] 7714 	mov	r4,a
      00269A E4               [12] 7715 	clr	a
      00269B 08               [12] 7716 	inc	r0
      00269C 36               [12] 7717 	addc	a, @r0
      00269D FD               [12] 7718 	mov	r5,a
      00269E 08               [12] 7719 	inc	r0
      00269F 86 06            [24] 7720 	mov	ar6,@r0
      0026A1                       7721 00109$:
                           0025E4  7722 	C$fuzzy.h$2812$1_0$123 ==.
                                   7723 ;	../../fuzzy.h:2812: value <= upper;
      0026A1 C0 06            [24] 7724 	push	ar6
      0026A3 C0 05            [24] 7725 	push	ar5
      0026A5 C0 04            [24] 7726 	push	ar4
      0026A7 E5 08            [12] 7727 	mov	a,_bp
      0026A9 24 11            [12] 7728 	add	a,#0x11
      0026AB F8               [12] 7729 	mov	r0,a
      0026AC E6               [12] 7730 	mov	a,@r0
      0026AD C0 E0            [24] 7731 	push	acc
      0026AF 08               [12] 7732 	inc	r0
      0026B0 E6               [12] 7733 	mov	a,@r0
      0026B1 C0 E0            [24] 7734 	push	acc
      0026B3 08               [12] 7735 	inc	r0
      0026B4 E6               [12] 7736 	mov	a,@r0
      0026B5 C0 E0            [24] 7737 	push	acc
      0026B7 08               [12] 7738 	inc	r0
      0026B8 E6               [12] 7739 	mov	a,@r0
      0026B9 C0 E0            [24] 7740 	push	acc
      0026BB E5 08            [12] 7741 	mov	a,_bp
      0026BD 24 F6            [12] 7742 	add	a,#0xf6
      0026BF F8               [12] 7743 	mov	r0,a
      0026C0 86 82            [24] 7744 	mov	dpl, @r0
      0026C2 08               [12] 7745 	inc	r0
      0026C3 86 83            [24] 7746 	mov	dph, @r0
      0026C5 08               [12] 7747 	inc	r0
      0026C6 86 F0            [24] 7748 	mov	b, @r0
      0026C8 08               [12] 7749 	inc	r0
      0026C9 E6               [12] 7750 	mov	a, @r0
      0026CA 12 41 7C         [24] 7751 	lcall	___fslt
      0026CD E5 81            [12] 7752 	mov	a,sp
      0026CF 24 FC            [12] 7753 	add	a,#0xfc
      0026D1 F5 81            [12] 7754 	mov	sp,a
      0026D3 D0 04            [24] 7755 	pop	ar4
      0026D5 D0 05            [24] 7756 	pop	ar5
      0026D7 D0 06            [24] 7757 	pop	ar6
      0026D9 E5 82            [12] 7758 	mov	a, dpl
      0026DB 24 FF            [12] 7759 	add	a,#0xff
      0026DD 92 00            [24] 7760 	mov	b0,c
      0026DF 50 03            [24] 7761 	jnc	00144$
      0026E1 02 29 2E         [24] 7762 	ljmp	00102$
      0026E4                       7763 00144$:
                           002627  7764 	C$fuzzy.h$2816$1_0$123 ==.
                                   7765 ;	../../fuzzy.h:2816: index = 0u;
      0026E4 E5 08            [12] 7766 	mov	a,_bp
      0026E6 24 1D            [12] 7767 	add	a,#0x1d
      0026E8 F8               [12] 7768 	mov	r0,a
      0026E9 E4               [12] 7769 	clr	a
      0026EA F6               [12] 7770 	mov	@r0,a
      0026EB 08               [12] 7771 	inc	r0
      0026EC F6               [12] 7772 	mov	@r0,a
      0026ED E5 08            [12] 7773 	mov	a,_bp
      0026EF 24 07            [12] 7774 	add	a,#0x07
      0026F1 F8               [12] 7775 	mov	r0,a
      0026F2 E4               [12] 7776 	clr	a
      0026F3 F6               [12] 7777 	mov	@r0,a
      0026F4 08               [12] 7778 	inc	r0
      0026F5 F6               [12] 7779 	mov	@r0,a
      0026F6                       7780 00106$:
                           002639  7781 	C$fuzzy.h$2817$4_0$126 ==.
                                   7782 ;	../../fuzzy.h:2817: index < rules->count;
      0026F6 8C 82            [24] 7783 	mov	dpl,r4
      0026F8 8D 83            [24] 7784 	mov	dph,r5
      0026FA 8E F0            [24] 7785 	mov	b,r6
      0026FC 12 43 A8         [24] 7786 	lcall	__gptrget
      0026FF FA               [12] 7787 	mov	r2,a
      002700 A3               [24] 7788 	inc	dptr
      002701 12 43 A8         [24] 7789 	lcall	__gptrget
      002704 FF               [12] 7790 	mov	r7,a
      002705 E5 08            [12] 7791 	mov	a,_bp
      002707 24 1D            [12] 7792 	add	a,#0x1d
      002709 F8               [12] 7793 	mov	r0,a
      00270A C3               [12] 7794 	clr	c
      00270B E6               [12] 7795 	mov	a,@r0
      00270C 9A               [12] 7796 	subb	a,r2
      00270D 08               [12] 7797 	inc	r0
      00270E E6               [12] 7798 	mov	a,@r0
      00270F 9F               [12] 7799 	subb	a,r7
      002710 40 03            [24] 7800 	jc	00145$
      002712 02 28 E3         [24] 7801 	ljmp	00110$
      002715                       7802 00145$:
                           002658  7803 	C$fuzzy.h$2822$1_0$123 ==.
                                   7804 ;	../../fuzzy.h:2822: rules->rules[index]
      002715 C0 04            [24] 7805 	push	ar4
      002717 C0 05            [24] 7806 	push	ar5
      002719 C0 06            [24] 7807 	push	ar6
      00271B E5 08            [12] 7808 	mov	a,_bp
      00271D 24 04            [12] 7809 	add	a,#0x04
      00271F F8               [12] 7810 	mov	r0,a
      002720 E5 08            [12] 7811 	mov	a,_bp
      002722 24 07            [12] 7812 	add	a,#0x07
      002724 F9               [12] 7813 	mov	r1,a
      002725 E7               [12] 7814 	mov	a,@r1
      002726 26               [12] 7815 	add	a, @r0
      002727 FA               [12] 7816 	mov	r2,a
      002728 09               [12] 7817 	inc	r1
      002729 E7               [12] 7818 	mov	a,@r1
      00272A 08               [12] 7819 	inc	r0
      00272B 36               [12] 7820 	addc	a, @r0
      00272C FB               [12] 7821 	mov	r3,a
      00272D 08               [12] 7822 	inc	r0
      00272E 86 07            [24] 7823 	mov	ar7,@r0
      002730 74 07            [12] 7824 	mov	a,#0x07
      002732 2A               [12] 7825 	add	a, r2
      002733 FA               [12] 7826 	mov	r2,a
      002734 E4               [12] 7827 	clr	a
      002735 3B               [12] 7828 	addc	a, r3
      002736 FB               [12] 7829 	mov	r3,a
      002737 8A 82            [24] 7830 	mov	dpl,r2
      002739 8B 83            [24] 7831 	mov	dph,r3
      00273B 8F F0            [24] 7832 	mov	b,r7
      00273D 12 43 A8         [24] 7833 	lcall	__gptrget
      002740 FA               [12] 7834 	mov	r2,a
      002741 A3               [24] 7835 	inc	dptr
      002742 12 43 A8         [24] 7836 	lcall	__gptrget
      002745 FB               [12] 7837 	mov	r3,a
                           002689  7838 	C$fuzzy.h$2823$5_0$127 ==.
                                   7839 ;	../../fuzzy.h:2823: .output_function(value)
      002746 C0 05            [24] 7840 	push	ar5
      002748 C0 04            [24] 7841 	push	ar4
      00274A 12 27 4F         [24] 7842 	lcall	00146$
      00274D 80 14            [24] 7843 	sjmp	00147$
      00274F                       7844 00146$:
      00274F C0 02            [24] 7845 	push	ar2
      002751 C0 03            [24] 7846 	push	ar3
      002753 E5 08            [12] 7847 	mov	a,_bp
      002755 24 11            [12] 7848 	add	a,#0x11
      002757 F8               [12] 7849 	mov	r0,a
      002758 86 82            [24] 7850 	mov	dpl, @r0
      00275A 08               [12] 7851 	inc	r0
      00275B 86 83            [24] 7852 	mov	dph, @r0
      00275D 08               [12] 7853 	inc	r0
      00275E 86 F0            [24] 7854 	mov	b, @r0
      002760 08               [12] 7855 	inc	r0
      002761 E6               [12] 7856 	mov	a, @r0
      002762 22               [24] 7857 	ret
      002763                       7858 00147$:
      002763 AA 82            [24] 7859 	mov	r2, dpl
      002765 AB 83            [24] 7860 	mov	r3, dph
      002767 AE F0            [24] 7861 	mov	r6, b
      002769 FF               [12] 7862 	mov	r7, a
      00276A D0 04            [24] 7863 	pop	ar4
      00276C D0 05            [24] 7864 	pop	ar5
      00276E 8A 82            [24] 7865 	mov	dpl, r2
      002770 8B 83            [24] 7866 	mov	dph, r3
      002772 8E F0            [24] 7867 	mov	b, r6
      002774 EF               [12] 7868 	mov	a, r7
      002775 C0 06            [24] 7869 	push	ar6
      002777 C0 05            [24] 7870 	push	ar5
      002779 C0 04            [24] 7871 	push	ar4
      00277B 12 00 F0         [24] 7872 	lcall	_fuzzy_clamp
      00277E C8               [12] 7873 	xch	a,r0
      00277F E5 08            [12] 7874 	mov	a,_bp
      002781 24 15            [12] 7875 	add	a,#0x15
      002783 C8               [12] 7876 	xch	a,r0
      002784 A6 82            [24] 7877 	mov	@r0, dpl
      002786 08               [12] 7878 	inc	r0
      002787 A6 83            [24] 7879 	mov	@r0, dph
      002789 08               [12] 7880 	inc	r0
      00278A A6 F0            [24] 7881 	mov	@r0, b
      00278C 08               [12] 7882 	inc	r0
      00278D F6               [12] 7883 	mov	@r0,a
      00278E D0 04            [24] 7884 	pop	ar4
      002790 D0 05            [24] 7885 	pop	ar5
      002792 D0 06            [24] 7886 	pop	ar6
                           0026D7  7887 	C$fuzzy.h$2829$5_0$127 ==.
                                   7888 ;	../../fuzzy.h:2829: rules->rules[index].value,
      002794 A8 08            [24] 7889 	mov	r0,_bp
      002796 08               [12] 7890 	inc	r0
      002797 E5 08            [12] 7891 	mov	a,_bp
      002799 24 07            [12] 7892 	add	a,#0x07
      00279B F9               [12] 7893 	mov	r1,a
      00279C E7               [12] 7894 	mov	a,@r1
      00279D 26               [12] 7895 	add	a, @r0
      00279E FA               [12] 7896 	mov	r2,a
      00279F 09               [12] 7897 	inc	r1
      0027A0 E7               [12] 7898 	mov	a,@r1
      0027A1 08               [12] 7899 	inc	r0
      0027A2 36               [12] 7900 	addc	a, @r0
      0027A3 FB               [12] 7901 	mov	r3,a
      0027A4 08               [12] 7902 	inc	r0
      0027A5 86 07            [24] 7903 	mov	ar7,@r0
      0027A7 74 03            [12] 7904 	mov	a,#0x03
      0027A9 2A               [12] 7905 	add	a, r2
      0027AA FA               [12] 7906 	mov	r2,a
      0027AB E4               [12] 7907 	clr	a
      0027AC 3B               [12] 7908 	addc	a, r3
      0027AD FB               [12] 7909 	mov	r3,a
      0027AE 8A 82            [24] 7910 	mov	dpl,r2
      0027B0 8B 83            [24] 7911 	mov	dph,r3
      0027B2 8F F0            [24] 7912 	mov	b,r7
      0027B4 12 43 A8         [24] 7913 	lcall	__gptrget
      0027B7 FA               [12] 7914 	mov	r2,a
      0027B8 A3               [24] 7915 	inc	dptr
      0027B9 12 43 A8         [24] 7916 	lcall	__gptrget
      0027BC FB               [12] 7917 	mov	r3,a
      0027BD A3               [24] 7918 	inc	dptr
      0027BE 12 43 A8         [24] 7919 	lcall	__gptrget
      0027C1 FF               [12] 7920 	mov	r7,a
      0027C2 A3               [24] 7921 	inc	dptr
      0027C3 12 43 A8         [24] 7922 	lcall	__gptrget
      0027C6 FE               [12] 7923 	mov	r6,a
                           00270A  7924 	C$fuzzy.h$2828$5_0$127 ==.
                                   7925 ;	../../fuzzy.h:2828: implication_method,
      0027C7 C0 06            [24] 7926 	push	ar6
      0027C9 C0 05            [24] 7927 	push	ar5
      0027CB C0 04            [24] 7928 	push	ar4
      0027CD E5 08            [12] 7929 	mov	a,_bp
      0027CF 24 15            [12] 7930 	add	a,#0x15
      0027D1 F8               [12] 7931 	mov	r0,a
      0027D2 E6               [12] 7932 	mov	a,@r0
      0027D3 C0 E0            [24] 7933 	push	acc
      0027D5 08               [12] 7934 	inc	r0
      0027D6 E6               [12] 7935 	mov	a,@r0
      0027D7 C0 E0            [24] 7936 	push	acc
      0027D9 08               [12] 7937 	inc	r0
      0027DA E6               [12] 7938 	mov	a,@r0
      0027DB C0 E0            [24] 7939 	push	acc
      0027DD 08               [12] 7940 	inc	r0
      0027DE E6               [12] 7941 	mov	a,@r0
      0027DF C0 E0            [24] 7942 	push	acc
      0027E1 C0 02            [24] 7943 	push	ar2
      0027E3 C0 03            [24] 7944 	push	ar3
      0027E5 C0 07            [24] 7945 	push	ar7
      0027E7 C0 06            [24] 7946 	push	ar6
      0027E9 E5 08            [12] 7947 	mov	a,_bp
      0027EB 24 F1            [12] 7948 	add	a,#0xf1
      0027ED F8               [12] 7949 	mov	r0,a
      0027EE 86 82            [24] 7950 	mov	dpl, @r0
      0027F0 12 18 D7         [24] 7951 	lcall	_fuzzy_implication
      0027F3 C8               [12] 7952 	xch	a,r0
      0027F4 E5 08            [12] 7953 	mov	a,_bp
      0027F6 24 19            [12] 7954 	add	a,#0x19
      0027F8 C8               [12] 7955 	xch	a,r0
      0027F9 A6 82            [24] 7956 	mov	@r0, dpl
      0027FB 08               [12] 7957 	inc	r0
      0027FC A6 83            [24] 7958 	mov	@r0, dph
      0027FE 08               [12] 7959 	inc	r0
      0027FF A6 F0            [24] 7960 	mov	@r0, b
      002801 08               [12] 7961 	inc	r0
      002802 F6               [12] 7962 	mov	@r0,a
      002803 E5 81            [12] 7963 	mov	a,sp
      002805 24 F8            [12] 7964 	add	a,#0xf8
      002807 F5 81            [12] 7965 	mov	sp,a
      002809 D0 04            [24] 7966 	pop	ar4
      00280B D0 05            [24] 7967 	pop	ar5
      00280D D0 06            [24] 7968 	pop	ar6
                           002752  7969 	C$fuzzy.h$2835$1_0$123 ==.
                                   7970 ;	../../fuzzy.h:2835: implied_height;
      00280F C0 05            [24] 7971 	push	ar5
      002811 C0 04            [24] 7972 	push	ar4
      002813 E5 08            [12] 7973 	mov	a,_bp
      002815 24 19            [12] 7974 	add	a,#0x19
      002817 F8               [12] 7975 	mov	r0,a
      002818 E6               [12] 7976 	mov	a,@r0
      002819 C0 E0            [24] 7977 	push	acc
      00281B 08               [12] 7978 	inc	r0
      00281C E6               [12] 7979 	mov	a,@r0
      00281D C0 E0            [24] 7980 	push	acc
      00281F 08               [12] 7981 	inc	r0
      002820 E6               [12] 7982 	mov	a,@r0
      002821 C0 E0            [24] 7983 	push	acc
      002823 08               [12] 7984 	inc	r0
      002824 E6               [12] 7985 	mov	a,@r0
      002825 C0 E0            [24] 7986 	push	acc
      002827 E5 08            [12] 7987 	mov	a,_bp
      002829 24 11            [12] 7988 	add	a,#0x11
      00282B F8               [12] 7989 	mov	r0,a
      00282C 86 82            [24] 7990 	mov	dpl, @r0
      00282E 08               [12] 7991 	inc	r0
      00282F 86 83            [24] 7992 	mov	dph, @r0
      002831 08               [12] 7993 	inc	r0
      002832 86 F0            [24] 7994 	mov	b, @r0
      002834 08               [12] 7995 	inc	r0
      002835 E6               [12] 7996 	mov	a, @r0
      002836 12 40 4C         [24] 7997 	lcall	___fsmul
      002839 AA 82            [24] 7998 	mov	r2, dpl
      00283B AB 83            [24] 7999 	mov	r3, dph
      00283D AE F0            [24] 8000 	mov	r6, b
      00283F FF               [12] 8001 	mov	r7, a
      002840 E5 81            [12] 8002 	mov	a,sp
      002842 24 FC            [12] 8003 	add	a,#0xfc
      002844 F5 81            [12] 8004 	mov	sp,a
      002846 D0 04            [24] 8005 	pop	ar4
      002848 D0 05            [24] 8006 	pop	ar5
      00284A C0 06            [24] 8007 	push	ar6
      00284C C0 05            [24] 8008 	push	ar5
      00284E C0 04            [24] 8009 	push	ar4
      002850 C0 02            [24] 8010 	push	ar2
      002852 C0 03            [24] 8011 	push	ar3
      002854 C0 06            [24] 8012 	push	ar6
      002856 C0 07            [24] 8013 	push	ar7
                           00279B  8014 	C$fuzzy.h$2838$1_0$123 ==.
                                   8015 ;	../../fuzzy.h:2838: implied_height;
      002858 E5 08            [12] 8016 	mov	a,_bp
      00285A 24 09            [12] 8017 	add	a,#0x09
      00285C F8               [12] 8018 	mov	r0,a
      00285D 86 82            [24] 8019 	mov	dpl, @r0
      00285F 08               [12] 8020 	inc	r0
      002860 86 83            [24] 8021 	mov	dph, @r0
      002862 08               [12] 8022 	inc	r0
      002863 86 F0            [24] 8023 	mov	b, @r0
      002865 08               [12] 8024 	inc	r0
      002866 E6               [12] 8025 	mov	a, @r0
      002867 12 41 CE         [24] 8026 	lcall	___fsadd
      00286A C8               [12] 8027 	xch	a,r0
      00286B E5 08            [12] 8028 	mov	a,_bp
      00286D 24 09            [12] 8029 	add	a,#0x09
      00286F C8               [12] 8030 	xch	a,r0
      002870 A6 82            [24] 8031 	mov	@r0, dpl
      002872 08               [12] 8032 	inc	r0
      002873 A6 83            [24] 8033 	mov	@r0, dph
      002875 08               [12] 8034 	inc	r0
      002876 A6 F0            [24] 8035 	mov	@r0, b
      002878 08               [12] 8036 	inc	r0
      002879 F6               [12] 8037 	mov	@r0,a
      00287A E5 81            [12] 8038 	mov	a,sp
      00287C 24 FC            [12] 8039 	add	a,#0xfc
      00287E F5 81            [12] 8040 	mov	sp,a
      002880 E5 08            [12] 8041 	mov	a,_bp
      002882 24 19            [12] 8042 	add	a,#0x19
      002884 F8               [12] 8043 	mov	r0,a
      002885 E6               [12] 8044 	mov	a,@r0
      002886 C0 E0            [24] 8045 	push	acc
      002888 08               [12] 8046 	inc	r0
      002889 E6               [12] 8047 	mov	a,@r0
      00288A C0 E0            [24] 8048 	push	acc
      00288C 08               [12] 8049 	inc	r0
      00288D E6               [12] 8050 	mov	a,@r0
      00288E C0 E0            [24] 8051 	push	acc
      002890 08               [12] 8052 	inc	r0
      002891 E6               [12] 8053 	mov	a,@r0
      002892 C0 E0            [24] 8054 	push	acc
                           0027D7  8055 	C$fuzzy.h$2818$1_0$123 ==.
                                   8056 ;	../../fuzzy.h:2818: index++
      002894 E5 08            [12] 8057 	mov	a,_bp
      002896 24 0D            [12] 8058 	add	a,#0x0d
      002898 F8               [12] 8059 	mov	r0,a
      002899 86 82            [24] 8060 	mov	dpl, @r0
      00289B 08               [12] 8061 	inc	r0
      00289C 86 83            [24] 8062 	mov	dph, @r0
      00289E 08               [12] 8063 	inc	r0
      00289F 86 F0            [24] 8064 	mov	b, @r0
      0028A1 08               [12] 8065 	inc	r0
      0028A2 E6               [12] 8066 	mov	a, @r0
      0028A3 12 41 CE         [24] 8067 	lcall	___fsadd
      0028A6 C8               [12] 8068 	xch	a,r0
      0028A7 E5 08            [12] 8069 	mov	a,_bp
      0028A9 24 0D            [12] 8070 	add	a,#0x0d
      0028AB C8               [12] 8071 	xch	a,r0
      0028AC A6 82            [24] 8072 	mov	@r0, dpl
      0028AE 08               [12] 8073 	inc	r0
      0028AF A6 83            [24] 8074 	mov	@r0, dph
      0028B1 08               [12] 8075 	inc	r0
      0028B2 A6 F0            [24] 8076 	mov	@r0, b
      0028B4 08               [12] 8077 	inc	r0
      0028B5 F6               [12] 8078 	mov	@r0,a
      0028B6 E5 81            [12] 8079 	mov	a,sp
      0028B8 24 FC            [12] 8080 	add	a,#0xfc
      0028BA F5 81            [12] 8081 	mov	sp,a
      0028BC D0 04            [24] 8082 	pop	ar4
      0028BE D0 05            [24] 8083 	pop	ar5
      0028C0 D0 06            [24] 8084 	pop	ar6
      0028C2 E5 08            [12] 8085 	mov	a,_bp
      0028C4 24 07            [12] 8086 	add	a,#0x07
      0028C6 F8               [12] 8087 	mov	r0,a
      0028C7 74 09            [12] 8088 	mov	a,#0x09
      0028C9 26               [12] 8089 	add	a, @r0
      0028CA F6               [12] 8090 	mov	@r0,a
      0028CB E4               [12] 8091 	clr	a
      0028CC 08               [12] 8092 	inc	r0
      0028CD 36               [12] 8093 	addc	a, @r0
      0028CE F6               [12] 8094 	mov	@r0,a
      0028CF E5 08            [12] 8095 	mov	a,_bp
      0028D1 24 1D            [12] 8096 	add	a,#0x1d
      0028D3 F8               [12] 8097 	mov	r0,a
      0028D4 06               [12] 8098 	inc	@r0
      0028D5 B6 00 02         [24] 8099 	cjne	@r0,#0x00,00148$
      0028D8 08               [12] 8100 	inc	r0
      0028D9 06               [12] 8101 	inc	@r0
      0028DA                       8102 00148$:
      0028DA D0 06            [24] 8103 	pop	ar6
      0028DC D0 05            [24] 8104 	pop	ar5
      0028DE D0 04            [24] 8105 	pop	ar4
      0028E0 02 26 F6         [24] 8106 	ljmp	00106$
      0028E3                       8107 00110$:
                           002826  8108 	C$fuzzy.h$2814$1_0$123 ==.
                                   8109 ;	../../fuzzy.h:2814: ) {
      0028E3 C0 06            [24] 8110 	push	ar6
      0028E5 C0 05            [24] 8111 	push	ar5
      0028E7 C0 04            [24] 8112 	push	ar4
      0028E9 E5 08            [12] 8113 	mov	a,_bp
      0028EB 24 F2            [12] 8114 	add	a,#0xf2
      0028ED F8               [12] 8115 	mov	r0,a
      0028EE E6               [12] 8116 	mov	a,@r0
      0028EF C0 E0            [24] 8117 	push	acc
      0028F1 08               [12] 8118 	inc	r0
      0028F2 E6               [12] 8119 	mov	a,@r0
      0028F3 C0 E0            [24] 8120 	push	acc
      0028F5 08               [12] 8121 	inc	r0
      0028F6 E6               [12] 8122 	mov	a,@r0
      0028F7 C0 E0            [24] 8123 	push	acc
      0028F9 08               [12] 8124 	inc	r0
      0028FA E6               [12] 8125 	mov	a,@r0
      0028FB C0 E0            [24] 8126 	push	acc
      0028FD E5 08            [12] 8127 	mov	a,_bp
      0028FF 24 11            [12] 8128 	add	a,#0x11
      002901 F8               [12] 8129 	mov	r0,a
      002902 86 82            [24] 8130 	mov	dpl, @r0
      002904 08               [12] 8131 	inc	r0
      002905 86 83            [24] 8132 	mov	dph, @r0
      002907 08               [12] 8133 	inc	r0
      002908 86 F0            [24] 8134 	mov	b, @r0
      00290A 08               [12] 8135 	inc	r0
      00290B E6               [12] 8136 	mov	a, @r0
      00290C 12 41 CE         [24] 8137 	lcall	___fsadd
      00290F C8               [12] 8138 	xch	a,r0
      002910 E5 08            [12] 8139 	mov	a,_bp
      002912 24 11            [12] 8140 	add	a,#0x11
      002914 C8               [12] 8141 	xch	a,r0
      002915 A6 82            [24] 8142 	mov	@r0, dpl
      002917 08               [12] 8143 	inc	r0
      002918 A6 83            [24] 8144 	mov	@r0, dph
      00291A 08               [12] 8145 	inc	r0
      00291B A6 F0            [24] 8146 	mov	@r0, b
      00291D 08               [12] 8147 	inc	r0
      00291E F6               [12] 8148 	mov	@r0,a
      00291F E5 81            [12] 8149 	mov	a,sp
      002921 24 FC            [12] 8150 	add	a,#0xfc
      002923 F5 81            [12] 8151 	mov	sp,a
      002925 D0 04            [24] 8152 	pop	ar4
      002927 D0 05            [24] 8153 	pop	ar5
      002929 D0 06            [24] 8154 	pop	ar6
      00292B 02 26 A1         [24] 8155 	ljmp	00109$
      00292E                       8156 00102$:
                           002871  8157 	C$fuzzy.h$2842$1_0$123 ==.
                                   8158 ;	../../fuzzy.h:2842: if (height_sum <= LEVEL_LO) {
      00292E E5 08            [12] 8159 	mov	a,_bp
      002930 24 0D            [12] 8160 	add	a,#0x0d
      002932 F8               [12] 8161 	mov	r0,a
      002933 E6               [12] 8162 	mov	a,@r0
      002934 C0 E0            [24] 8163 	push	acc
      002936 08               [12] 8164 	inc	r0
      002937 E6               [12] 8165 	mov	a,@r0
      002938 C0 E0            [24] 8166 	push	acc
      00293A 08               [12] 8167 	inc	r0
      00293B E6               [12] 8168 	mov	a,@r0
      00293C C0 E0            [24] 8169 	push	acc
      00293E 08               [12] 8170 	inc	r0
      00293F E6               [12] 8171 	mov	a,@r0
      002940 C0 E0            [24] 8172 	push	acc
      002942 90 00 00         [24] 8173 	mov	dptr,#0x0000
      002945 E4               [12] 8174 	clr	a
      002946 F5 F0            [12] 8175 	mov	b,a
      002948 12 41 7C         [24] 8176 	lcall	___fslt
      00294B E5 81            [12] 8177 	mov	a,sp
      00294D 24 FC            [12] 8178 	add	a,#0xfc
      00294F F5 81            [12] 8179 	mov	sp,a
      002951 E5 82            [12] 8180 	mov	a, dpl
      002953 24 FF            [12] 8181 	add	a,#0xff
      002955 92 00            [24] 8182 	mov	b0,c
      002957 40 08            [24] 8183 	jc	00104$
                           00289C  8184 	C$fuzzy.h$2843$2_0$128 ==.
                                   8185 ;	../../fuzzy.h:2843: return 0.0f;
      002959 90 00 00         [24] 8186 	mov	dptr,#0x0000
      00295C E4               [12] 8187 	clr	a
      00295D F5 F0            [12] 8188 	mov	b,a
      00295F 80 3A            [24] 8189 	sjmp	00111$
      002961                       8190 00104$:
                           0028A4  8191 	C$fuzzy.h$2847$1_0$123 ==.
                                   8192 ;	../../fuzzy.h:2847: height_sum;
      002961 E5 08            [12] 8193 	mov	a,_bp
      002963 24 0D            [12] 8194 	add	a,#0x0d
      002965 F8               [12] 8195 	mov	r0,a
      002966 E6               [12] 8196 	mov	a,@r0
      002967 C0 E0            [24] 8197 	push	acc
      002969 08               [12] 8198 	inc	r0
      00296A E6               [12] 8199 	mov	a,@r0
      00296B C0 E0            [24] 8200 	push	acc
      00296D 08               [12] 8201 	inc	r0
      00296E E6               [12] 8202 	mov	a,@r0
      00296F C0 E0            [24] 8203 	push	acc
      002971 08               [12] 8204 	inc	r0
      002972 E6               [12] 8205 	mov	a,@r0
      002973 C0 E0            [24] 8206 	push	acc
      002975 E5 08            [12] 8207 	mov	a,_bp
      002977 24 09            [12] 8208 	add	a,#0x09
      002979 F8               [12] 8209 	mov	r0,a
      00297A 86 82            [24] 8210 	mov	dpl, @r0
      00297C 08               [12] 8211 	inc	r0
      00297D 86 83            [24] 8212 	mov	dph, @r0
      00297F 08               [12] 8213 	inc	r0
      002980 86 F0            [24] 8214 	mov	b, @r0
      002982 08               [12] 8215 	inc	r0
      002983 E6               [12] 8216 	mov	a, @r0
      002984 12 42 E5         [24] 8217 	lcall	___fsdiv
      002987 AC 82            [24] 8218 	mov	r4, dpl
      002989 AD 83            [24] 8219 	mov	r5, dph
      00298B AE F0            [24] 8220 	mov	r6, b
      00298D FF               [12] 8221 	mov	r7, a
      00298E E5 81            [12] 8222 	mov	a,sp
      002990 24 FC            [12] 8223 	add	a,#0xfc
      002992 F5 81            [12] 8224 	mov	sp,a
      002994 8C 82            [24] 8225 	mov	dpl, r4
      002996 8D 83            [24] 8226 	mov	dph, r5
      002998 8E F0            [24] 8227 	mov	b, r6
      00299A EF               [12] 8228 	mov	a, r7
      00299B                       8229 00111$:
                           0028DE  8230 	C$fuzzy.h$2848$1_0$123 ==.
                                   8231 ;	../../fuzzy.h:2848: }
      00299B 85 08 81         [24] 8232 	mov	sp,_bp
      00299E D0 08            [24] 8233 	pop	_bp
                           0028E3  8234 	C$fuzzy.h$2848$1_0$123 ==.
                           0028E3  8235 	XG$fuzzy_rules_defuzzify_cos$0$0 ==.
      0029A0 22               [24] 8236 	ret
                                   8237 ;------------------------------------------------------------
                                   8238 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_mom'
                                   8239 ;------------------------------------------------------------
                                   8240 ;lower         Allocated to stack - _bp -6 +4 
                                   8241 ;upper         Allocated to stack - _bp -10 +4 
                                   8242 ;step          Allocated to stack - _bp -14 +4 
                                   8243 ;implication_method Allocated to stack - _bp -15 +1 
                                   8244 ;aggregation_method Allocated to stack - _bp -16 +1 
                                   8245 ;rules         Allocated to stack - _bp +1 +3 
                                   8246 ;result        Allocated to stack - _bp +8 +18 
                                   8247 ;sloc0         Allocated to stack - _bp +4 +4 
                                   8248 ;------------------------------------------------------------
                           0028E4  8249 	G$fuzzy_rules_defuzzify_mom$0$0 ==.
                           0028E4  8250 	C$fuzzy.h$2854$1_0$130 ==.
                                   8251 ;	../../fuzzy.h:2854: float fuzzy_rules_defuzzify_mom(
                                   8252 ;	-----------------------------------------
                                   8253 ;	 function fuzzy_rules_defuzzify_mom
                                   8254 ;	-----------------------------------------
      0029A1                       8255 _fuzzy_rules_defuzzify_mom:
      0029A1 C0 08            [24] 8256 	push	_bp
      0029A3 85 81 08         [24] 8257 	mov	_bp,sp
      0029A6 C0 82            [24] 8258 	push	dpl
      0029A8 C0 83            [24] 8259 	push	dph
      0029AA C0 F0            [24] 8260 	push	b
      0029AC E5 81            [12] 8261 	mov	a,sp
      0029AE 24 16            [12] 8262 	add	a,#0x16
      0029B0 F5 81            [12] 8263 	mov	sp,a
                           0028F5  8264 	C$fuzzy.h$2866$1_0$130 ==.
                                   8265 ;	../../fuzzy.h:2866: &result,
      0029B2 E5 08            [12] 8266 	mov	a,_bp
      0029B4 24 08            [12] 8267 	add	a,#0x08
      0029B6 FC               [12] 8268 	mov	r4,a
      0029B7 FA               [12] 8269 	mov	r2,a
      0029B8 7B 00            [12] 8270 	mov	r3,#0x00
      0029BA 7F 40            [12] 8271 	mov	r7,#0x40
      0029BC C0 04            [24] 8272 	push	ar4
      0029BE E5 08            [12] 8273 	mov	a,_bp
      0029C0 24 F0            [12] 8274 	add	a,#0xf0
      0029C2 F8               [12] 8275 	mov	r0,a
      0029C3 E6               [12] 8276 	mov	a,@r0
      0029C4 C0 E0            [24] 8277 	push	acc
      0029C6 E5 08            [12] 8278 	mov	a,_bp
      0029C8 24 F1            [12] 8279 	add	a,#0xf1
      0029CA F8               [12] 8280 	mov	r0,a
      0029CB E6               [12] 8281 	mov	a,@r0
      0029CC C0 E0            [24] 8282 	push	acc
      0029CE E5 08            [12] 8283 	mov	a,_bp
      0029D0 24 F2            [12] 8284 	add	a,#0xf2
      0029D2 F8               [12] 8285 	mov	r0,a
      0029D3 E6               [12] 8286 	mov	a,@r0
      0029D4 C0 E0            [24] 8287 	push	acc
      0029D6 08               [12] 8288 	inc	r0
      0029D7 E6               [12] 8289 	mov	a,@r0
      0029D8 C0 E0            [24] 8290 	push	acc
      0029DA 08               [12] 8291 	inc	r0
      0029DB E6               [12] 8292 	mov	a,@r0
      0029DC C0 E0            [24] 8293 	push	acc
      0029DE 08               [12] 8294 	inc	r0
      0029DF E6               [12] 8295 	mov	a,@r0
      0029E0 C0 E0            [24] 8296 	push	acc
      0029E2 E5 08            [12] 8297 	mov	a,_bp
      0029E4 24 F6            [12] 8298 	add	a,#0xf6
      0029E6 F8               [12] 8299 	mov	r0,a
      0029E7 E6               [12] 8300 	mov	a,@r0
      0029E8 C0 E0            [24] 8301 	push	acc
      0029EA 08               [12] 8302 	inc	r0
      0029EB E6               [12] 8303 	mov	a,@r0
      0029EC C0 E0            [24] 8304 	push	acc
      0029EE 08               [12] 8305 	inc	r0
      0029EF E6               [12] 8306 	mov	a,@r0
      0029F0 C0 E0            [24] 8307 	push	acc
      0029F2 08               [12] 8308 	inc	r0
      0029F3 E6               [12] 8309 	mov	a,@r0
      0029F4 C0 E0            [24] 8310 	push	acc
      0029F6 E5 08            [12] 8311 	mov	a,_bp
      0029F8 24 FA            [12] 8312 	add	a,#0xfa
      0029FA F8               [12] 8313 	mov	r0,a
      0029FB E6               [12] 8314 	mov	a,@r0
      0029FC C0 E0            [24] 8315 	push	acc
      0029FE 08               [12] 8316 	inc	r0
      0029FF E6               [12] 8317 	mov	a,@r0
      002A00 C0 E0            [24] 8318 	push	acc
      002A02 08               [12] 8319 	inc	r0
      002A03 E6               [12] 8320 	mov	a,@r0
      002A04 C0 E0            [24] 8321 	push	acc
      002A06 08               [12] 8322 	inc	r0
      002A07 E6               [12] 8323 	mov	a,@r0
      002A08 C0 E0            [24] 8324 	push	acc
      002A0A A8 08            [24] 8325 	mov	r0,_bp
      002A0C 08               [12] 8326 	inc	r0
      002A0D E6               [12] 8327 	mov	a,@r0
      002A0E C0 E0            [24] 8328 	push	acc
      002A10 08               [12] 8329 	inc	r0
      002A11 E6               [12] 8330 	mov	a,@r0
      002A12 C0 E0            [24] 8331 	push	acc
      002A14 08               [12] 8332 	inc	r0
      002A15 E6               [12] 8333 	mov	a,@r0
      002A16 C0 E0            [24] 8334 	push	acc
      002A18 8A 82            [24] 8335 	mov	dpl, r2
      002A1A 8B 83            [24] 8336 	mov	dph, r3
      002A1C 8F F0            [24] 8337 	mov	b, r7
      002A1E 12 1D 47         [24] 8338 	lcall	_fuzzy_rules_maximum_result
      002A21 E5 81            [12] 8339 	mov	a,sp
      002A23 24 EF            [12] 8340 	add	a,#0xef
      002A25 F5 81            [12] 8341 	mov	sp,a
      002A27 D0 04            [24] 8342 	pop	ar4
                           00296C  8343 	C$fuzzy.h$2876$1_0$130 ==.
                                   8344 ;	../../fuzzy.h:2876: result.position_count == 0u ||
      002A29 74 10            [12] 8345 	mov	a,#0x10
      002A2B 2C               [12] 8346 	add	a, r4
      002A2C F9               [12] 8347 	mov	r1,a
      002A2D 87 06            [24] 8348 	mov	ar6,@r1
      002A2F 09               [12] 8349 	inc	r1
      002A30 87 07            [24] 8350 	mov	ar7,@r1
      002A32 EE               [12] 8351 	mov	a,r6
      002A33 4F               [12] 8352 	orl	a,r7
      002A34 60 41            [24] 8353 	jz	00101$
                           002979  8354 	C$fuzzy.h$2877$1_0$130 ==.
                                   8355 ;	../../fuzzy.h:2877: result.height <= LEVEL_LO
      002A36 C0 06            [24] 8356 	push	ar6
      002A38 C0 07            [24] 8357 	push	ar7
      002A3A 8C 01            [24] 8358 	mov	ar1,r4
      002A3C 87 02            [24] 8359 	mov	ar2,@r1
      002A3E 09               [12] 8360 	inc	r1
      002A3F 87 03            [24] 8361 	mov	ar3,@r1
      002A41 09               [12] 8362 	inc	r1
      002A42 87 05            [24] 8363 	mov	ar5,@r1
      002A44 09               [12] 8364 	inc	r1
      002A45 87 07            [24] 8365 	mov	ar7,@r1
      002A47 C0 07            [24] 8366 	push	ar7
      002A49 C0 06            [24] 8367 	push	ar6
      002A4B C0 04            [24] 8368 	push	ar4
      002A4D C0 02            [24] 8369 	push	ar2
      002A4F C0 03            [24] 8370 	push	ar3
      002A51 C0 05            [24] 8371 	push	ar5
      002A53 C0 07            [24] 8372 	push	ar7
      002A55 90 00 00         [24] 8373 	mov	dptr,#0x0000
      002A58 E4               [12] 8374 	clr	a
      002A59 F5 F0            [12] 8375 	mov	b,a
      002A5B 12 41 7C         [24] 8376 	lcall	___fslt
      002A5E E5 81            [12] 8377 	mov	a,sp
      002A60 24 FC            [12] 8378 	add	a,#0xfc
      002A62 F5 81            [12] 8379 	mov	sp,a
      002A64 D0 04            [24] 8380 	pop	ar4
      002A66 D0 06            [24] 8381 	pop	ar6
      002A68 D0 07            [24] 8382 	pop	ar7
      002A6A E5 82            [12] 8383 	mov	a, dpl
      002A6C 24 FF            [12] 8384 	add	a,#0xff
      002A6E 92 00            [24] 8385 	mov	b0,c
      002A70 D0 07            [24] 8386 	pop	ar7
      002A72 D0 06            [24] 8387 	pop	ar6
      002A74 20 00 08         [24] 8388 	jb	b0,00102$
      002A77                       8389 00101$:
                           0029BA  8390 	C$fuzzy.h$2879$2_0$131 ==.
                                   8391 ;	../../fuzzy.h:2879: return 0.0f;
      002A77 90 00 00         [24] 8392 	mov	dptr,#0x0000
      002A7A E4               [12] 8393 	clr	a
      002A7B F5 F0            [12] 8394 	mov	b,a
      002A7D 80 53            [24] 8395 	sjmp	00104$
      002A7F                       8396 00102$:
                           0029C2  8397 	C$fuzzy.h$2882$1_0$130 ==.
                                   8398 ;	../../fuzzy.h:2882: return result.position_sum /
      002A7F 74 0C            [12] 8399 	mov	a,#0x0c
      002A81 2C               [12] 8400 	add	a, r4
      002A82 F9               [12] 8401 	mov	r1,a
      002A83 E5 08            [12] 8402 	mov	a,_bp
      002A85 24 04            [12] 8403 	add	a,#0x04
      002A87 F8               [12] 8404 	mov	r0,a
      002A88 E7               [12] 8405 	mov	a,@r1
      002A89 F6               [12] 8406 	mov	@r0,a
      002A8A 09               [12] 8407 	inc	r1
      002A8B E7               [12] 8408 	mov	a,@r1
      002A8C 08               [12] 8409 	inc	r0
      002A8D F6               [12] 8410 	mov	@r0,a
      002A8E 09               [12] 8411 	inc	r1
      002A8F E7               [12] 8412 	mov	a,@r1
      002A90 08               [12] 8413 	inc	r0
      002A91 F6               [12] 8414 	mov	@r0,a
      002A92 09               [12] 8415 	inc	r1
      002A93 E7               [12] 8416 	mov	a,@r1
      002A94 08               [12] 8417 	inc	r0
      002A95 F6               [12] 8418 	mov	@r0,a
                           0029D9  8419 	C$fuzzy.h$2883$1_0$130 ==.
                                   8420 ;	../../fuzzy.h:2883: (float)result.position_count;
      002A96 8E 82            [24] 8421 	mov	dpl, r6
      002A98 8F 83            [24] 8422 	mov	dph, r7
      002A9A 12 42 70         [24] 8423 	lcall	___uint2fs
      002A9D AC 82            [24] 8424 	mov	r4, dpl
      002A9F AD 83            [24] 8425 	mov	r5, dph
      002AA1 AE F0            [24] 8426 	mov	r6, b
      002AA3 FF               [12] 8427 	mov	r7, a
      002AA4 C0 04            [24] 8428 	push	ar4
      002AA6 C0 05            [24] 8429 	push	ar5
      002AA8 C0 06            [24] 8430 	push	ar6
      002AAA C0 07            [24] 8431 	push	ar7
      002AAC E5 08            [12] 8432 	mov	a,_bp
      002AAE 24 04            [12] 8433 	add	a,#0x04
      002AB0 F8               [12] 8434 	mov	r0,a
      002AB1 86 82            [24] 8435 	mov	dpl, @r0
      002AB3 08               [12] 8436 	inc	r0
      002AB4 86 83            [24] 8437 	mov	dph, @r0
      002AB6 08               [12] 8438 	inc	r0
      002AB7 86 F0            [24] 8439 	mov	b, @r0
      002AB9 08               [12] 8440 	inc	r0
      002ABA E6               [12] 8441 	mov	a, @r0
      002ABB 12 42 E5         [24] 8442 	lcall	___fsdiv
      002ABE AC 82            [24] 8443 	mov	r4, dpl
      002AC0 AD 83            [24] 8444 	mov	r5, dph
      002AC2 AE F0            [24] 8445 	mov	r6, b
      002AC4 FF               [12] 8446 	mov	r7, a
      002AC5 E5 81            [12] 8447 	mov	a,sp
      002AC7 24 FC            [12] 8448 	add	a,#0xfc
      002AC9 F5 81            [12] 8449 	mov	sp,a
      002ACB 8C 82            [24] 8450 	mov	dpl, r4
      002ACD 8D 83            [24] 8451 	mov	dph, r5
      002ACF 8E F0            [24] 8452 	mov	b, r6
      002AD1 EF               [12] 8453 	mov	a, r7
      002AD2                       8454 00104$:
                           002A15  8455 	C$fuzzy.h$2884$1_0$130 ==.
                                   8456 ;	../../fuzzy.h:2884: }
      002AD2 85 08 81         [24] 8457 	mov	sp,_bp
      002AD5 D0 08            [24] 8458 	pop	_bp
                           002A1A  8459 	C$fuzzy.h$2884$1_0$130 ==.
                           002A1A  8460 	XG$fuzzy_rules_defuzzify_mom$0$0 ==.
      002AD7 22               [24] 8461 	ret
                                   8462 ;------------------------------------------------------------
                                   8463 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_som'
                                   8464 ;------------------------------------------------------------
                                   8465 ;lower         Allocated to stack - _bp -6 +4 
                                   8466 ;upper         Allocated to stack - _bp -10 +4 
                                   8467 ;step          Allocated to stack - _bp -14 +4 
                                   8468 ;implication_method Allocated to stack - _bp -15 +1 
                                   8469 ;aggregation_method Allocated to stack - _bp -16 +1 
                                   8470 ;rules         Allocated to stack - _bp +1 +3 
                                   8471 ;result        Allocated to stack - _bp +4 +18 
                                   8472 ;------------------------------------------------------------
                           002A1B  8473 	G$fuzzy_rules_defuzzify_som$0$0 ==.
                           002A1B  8474 	C$fuzzy.h$2890$1_0$133 ==.
                                   8475 ;	../../fuzzy.h:2890: float fuzzy_rules_defuzzify_som(
                                   8476 ;	-----------------------------------------
                                   8477 ;	 function fuzzy_rules_defuzzify_som
                                   8478 ;	-----------------------------------------
      002AD8                       8479 _fuzzy_rules_defuzzify_som:
      002AD8 C0 08            [24] 8480 	push	_bp
      002ADA 85 81 08         [24] 8481 	mov	_bp,sp
      002ADD C0 82            [24] 8482 	push	dpl
      002ADF C0 83            [24] 8483 	push	dph
      002AE1 C0 F0            [24] 8484 	push	b
      002AE3 E5 81            [12] 8485 	mov	a,sp
      002AE5 24 12            [12] 8486 	add	a,#0x12
      002AE7 F5 81            [12] 8487 	mov	sp,a
                           002A2C  8488 	C$fuzzy.h$2902$1_0$133 ==.
                                   8489 ;	../../fuzzy.h:2902: &result,
      002AE9 E5 08            [12] 8490 	mov	a,_bp
      002AEB 24 04            [12] 8491 	add	a,#0x04
      002AED FC               [12] 8492 	mov	r4,a
      002AEE FA               [12] 8493 	mov	r2,a
      002AEF 7B 00            [12] 8494 	mov	r3,#0x00
      002AF1 7F 40            [12] 8495 	mov	r7,#0x40
      002AF3 C0 04            [24] 8496 	push	ar4
      002AF5 E5 08            [12] 8497 	mov	a,_bp
      002AF7 24 F0            [12] 8498 	add	a,#0xf0
      002AF9 F8               [12] 8499 	mov	r0,a
      002AFA E6               [12] 8500 	mov	a,@r0
      002AFB C0 E0            [24] 8501 	push	acc
      002AFD E5 08            [12] 8502 	mov	a,_bp
      002AFF 24 F1            [12] 8503 	add	a,#0xf1
      002B01 F8               [12] 8504 	mov	r0,a
      002B02 E6               [12] 8505 	mov	a,@r0
      002B03 C0 E0            [24] 8506 	push	acc
      002B05 E5 08            [12] 8507 	mov	a,_bp
      002B07 24 F2            [12] 8508 	add	a,#0xf2
      002B09 F8               [12] 8509 	mov	r0,a
      002B0A E6               [12] 8510 	mov	a,@r0
      002B0B C0 E0            [24] 8511 	push	acc
      002B0D 08               [12] 8512 	inc	r0
      002B0E E6               [12] 8513 	mov	a,@r0
      002B0F C0 E0            [24] 8514 	push	acc
      002B11 08               [12] 8515 	inc	r0
      002B12 E6               [12] 8516 	mov	a,@r0
      002B13 C0 E0            [24] 8517 	push	acc
      002B15 08               [12] 8518 	inc	r0
      002B16 E6               [12] 8519 	mov	a,@r0
      002B17 C0 E0            [24] 8520 	push	acc
      002B19 E5 08            [12] 8521 	mov	a,_bp
      002B1B 24 F6            [12] 8522 	add	a,#0xf6
      002B1D F8               [12] 8523 	mov	r0,a
      002B1E E6               [12] 8524 	mov	a,@r0
      002B1F C0 E0            [24] 8525 	push	acc
      002B21 08               [12] 8526 	inc	r0
      002B22 E6               [12] 8527 	mov	a,@r0
      002B23 C0 E0            [24] 8528 	push	acc
      002B25 08               [12] 8529 	inc	r0
      002B26 E6               [12] 8530 	mov	a,@r0
      002B27 C0 E0            [24] 8531 	push	acc
      002B29 08               [12] 8532 	inc	r0
      002B2A E6               [12] 8533 	mov	a,@r0
      002B2B C0 E0            [24] 8534 	push	acc
      002B2D E5 08            [12] 8535 	mov	a,_bp
      002B2F 24 FA            [12] 8536 	add	a,#0xfa
      002B31 F8               [12] 8537 	mov	r0,a
      002B32 E6               [12] 8538 	mov	a,@r0
      002B33 C0 E0            [24] 8539 	push	acc
      002B35 08               [12] 8540 	inc	r0
      002B36 E6               [12] 8541 	mov	a,@r0
      002B37 C0 E0            [24] 8542 	push	acc
      002B39 08               [12] 8543 	inc	r0
      002B3A E6               [12] 8544 	mov	a,@r0
      002B3B C0 E0            [24] 8545 	push	acc
      002B3D 08               [12] 8546 	inc	r0
      002B3E E6               [12] 8547 	mov	a,@r0
      002B3F C0 E0            [24] 8548 	push	acc
      002B41 A8 08            [24] 8549 	mov	r0,_bp
      002B43 08               [12] 8550 	inc	r0
      002B44 E6               [12] 8551 	mov	a,@r0
      002B45 C0 E0            [24] 8552 	push	acc
      002B47 08               [12] 8553 	inc	r0
      002B48 E6               [12] 8554 	mov	a,@r0
      002B49 C0 E0            [24] 8555 	push	acc
      002B4B 08               [12] 8556 	inc	r0
      002B4C E6               [12] 8557 	mov	a,@r0
      002B4D C0 E0            [24] 8558 	push	acc
      002B4F 8A 82            [24] 8559 	mov	dpl, r2
      002B51 8B 83            [24] 8560 	mov	dph, r3
      002B53 8F F0            [24] 8561 	mov	b, r7
      002B55 12 1D 47         [24] 8562 	lcall	_fuzzy_rules_maximum_result
      002B58 E5 81            [12] 8563 	mov	a,sp
      002B5A 24 EF            [12] 8564 	add	a,#0xef
      002B5C F5 81            [12] 8565 	mov	sp,a
      002B5E D0 04            [24] 8566 	pop	ar4
                           002AA3  8567 	C$fuzzy.h$2912$1_0$133 ==.
                                   8568 ;	../../fuzzy.h:2912: result.position_count == 0u ||
      002B60 74 10            [12] 8569 	mov	a,#0x10
      002B62 2C               [12] 8570 	add	a, r4
      002B63 F9               [12] 8571 	mov	r1,a
      002B64 87 06            [24] 8572 	mov	ar6,@r1
      002B66 09               [12] 8573 	inc	r1
      002B67 87 07            [24] 8574 	mov	ar7,@r1
      002B69 EE               [12] 8575 	mov	a,r6
      002B6A 4F               [12] 8576 	orl	a,r7
      002B6B 60 30            [24] 8577 	jz	00101$
                           002AB0  8578 	C$fuzzy.h$2913$1_0$133 ==.
                                   8579 ;	../../fuzzy.h:2913: result.height <= LEVEL_LO
      002B6D 8C 01            [24] 8580 	mov	ar1,r4
      002B6F 87 03            [24] 8581 	mov	ar3,@r1
      002B71 09               [12] 8582 	inc	r1
      002B72 87 05            [24] 8583 	mov	ar5,@r1
      002B74 09               [12] 8584 	inc	r1
      002B75 87 06            [24] 8585 	mov	ar6,@r1
      002B77 09               [12] 8586 	inc	r1
      002B78 87 07            [24] 8587 	mov	ar7,@r1
      002B7A C0 04            [24] 8588 	push	ar4
      002B7C C0 03            [24] 8589 	push	ar3
      002B7E C0 05            [24] 8590 	push	ar5
      002B80 C0 06            [24] 8591 	push	ar6
      002B82 C0 07            [24] 8592 	push	ar7
      002B84 90 00 00         [24] 8593 	mov	dptr,#0x0000
      002B87 E4               [12] 8594 	clr	a
      002B88 F5 F0            [12] 8595 	mov	b,a
      002B8A 12 41 7C         [24] 8596 	lcall	___fslt
      002B8D E5 81            [12] 8597 	mov	a,sp
      002B8F 24 FC            [12] 8598 	add	a,#0xfc
      002B91 F5 81            [12] 8599 	mov	sp,a
      002B93 D0 04            [24] 8600 	pop	ar4
      002B95 E5 82            [12] 8601 	mov	a, dpl
      002B97 24 FF            [12] 8602 	add	a,#0xff
      002B99 92 00            [24] 8603 	mov	b0,c
      002B9B 40 08            [24] 8604 	jc	00102$
      002B9D                       8605 00101$:
                           002AE0  8606 	C$fuzzy.h$2915$2_0$134 ==.
                                   8607 ;	../../fuzzy.h:2915: return 0.0f;
      002B9D 90 00 00         [24] 8608 	mov	dptr,#0x0000
      002BA0 E4               [12] 8609 	clr	a
      002BA1 F5 F0            [12] 8610 	mov	b,a
      002BA3 80 16            [24] 8611 	sjmp	00104$
      002BA5                       8612 00102$:
                           002AE8  8613 	C$fuzzy.h$2918$1_0$133 ==.
                                   8614 ;	../../fuzzy.h:2918: return result.smallest_position;
      002BA5 74 04            [12] 8615 	mov	a,#0x04
      002BA7 2C               [12] 8616 	add	a, r4
      002BA8 F9               [12] 8617 	mov	r1,a
      002BA9 87 04            [24] 8618 	mov	ar4,@r1
      002BAB 09               [12] 8619 	inc	r1
      002BAC 87 05            [24] 8620 	mov	ar5,@r1
      002BAE 09               [12] 8621 	inc	r1
      002BAF 87 06            [24] 8622 	mov	ar6,@r1
      002BB1 09               [12] 8623 	inc	r1
      002BB2 87 07            [24] 8624 	mov	ar7,@r1
      002BB4 8C 82            [24] 8625 	mov	dpl, r4
      002BB6 8D 83            [24] 8626 	mov	dph, r5
      002BB8 8E F0            [24] 8627 	mov	b, r6
      002BBA EF               [12] 8628 	mov	a, r7
      002BBB                       8629 00104$:
                           002AFE  8630 	C$fuzzy.h$2919$1_0$133 ==.
                                   8631 ;	../../fuzzy.h:2919: }
      002BBB 85 08 81         [24] 8632 	mov	sp,_bp
      002BBE D0 08            [24] 8633 	pop	_bp
                           002B03  8634 	C$fuzzy.h$2919$1_0$133 ==.
                           002B03  8635 	XG$fuzzy_rules_defuzzify_som$0$0 ==.
      002BC0 22               [24] 8636 	ret
                                   8637 ;------------------------------------------------------------
                                   8638 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_lom'
                                   8639 ;------------------------------------------------------------
                                   8640 ;lower         Allocated to stack - _bp -6 +4 
                                   8641 ;upper         Allocated to stack - _bp -10 +4 
                                   8642 ;step          Allocated to stack - _bp -14 +4 
                                   8643 ;implication_method Allocated to stack - _bp -15 +1 
                                   8644 ;aggregation_method Allocated to stack - _bp -16 +1 
                                   8645 ;rules         Allocated to stack - _bp +1 +3 
                                   8646 ;result        Allocated to stack - _bp +4 +18 
                                   8647 ;------------------------------------------------------------
                           002B04  8648 	G$fuzzy_rules_defuzzify_lom$0$0 ==.
                           002B04  8649 	C$fuzzy.h$2925$1_0$136 ==.
                                   8650 ;	../../fuzzy.h:2925: float fuzzy_rules_defuzzify_lom(
                                   8651 ;	-----------------------------------------
                                   8652 ;	 function fuzzy_rules_defuzzify_lom
                                   8653 ;	-----------------------------------------
      002BC1                       8654 _fuzzy_rules_defuzzify_lom:
      002BC1 C0 08            [24] 8655 	push	_bp
      002BC3 85 81 08         [24] 8656 	mov	_bp,sp
      002BC6 C0 82            [24] 8657 	push	dpl
      002BC8 C0 83            [24] 8658 	push	dph
      002BCA C0 F0            [24] 8659 	push	b
      002BCC E5 81            [12] 8660 	mov	a,sp
      002BCE 24 12            [12] 8661 	add	a,#0x12
      002BD0 F5 81            [12] 8662 	mov	sp,a
                           002B15  8663 	C$fuzzy.h$2937$1_0$136 ==.
                                   8664 ;	../../fuzzy.h:2937: &result,
      002BD2 E5 08            [12] 8665 	mov	a,_bp
      002BD4 24 04            [12] 8666 	add	a,#0x04
      002BD6 FC               [12] 8667 	mov	r4,a
      002BD7 FA               [12] 8668 	mov	r2,a
      002BD8 7B 00            [12] 8669 	mov	r3,#0x00
      002BDA 7F 40            [12] 8670 	mov	r7,#0x40
      002BDC C0 04            [24] 8671 	push	ar4
      002BDE E5 08            [12] 8672 	mov	a,_bp
      002BE0 24 F0            [12] 8673 	add	a,#0xf0
      002BE2 F8               [12] 8674 	mov	r0,a
      002BE3 E6               [12] 8675 	mov	a,@r0
      002BE4 C0 E0            [24] 8676 	push	acc
      002BE6 E5 08            [12] 8677 	mov	a,_bp
      002BE8 24 F1            [12] 8678 	add	a,#0xf1
      002BEA F8               [12] 8679 	mov	r0,a
      002BEB E6               [12] 8680 	mov	a,@r0
      002BEC C0 E0            [24] 8681 	push	acc
      002BEE E5 08            [12] 8682 	mov	a,_bp
      002BF0 24 F2            [12] 8683 	add	a,#0xf2
      002BF2 F8               [12] 8684 	mov	r0,a
      002BF3 E6               [12] 8685 	mov	a,@r0
      002BF4 C0 E0            [24] 8686 	push	acc
      002BF6 08               [12] 8687 	inc	r0
      002BF7 E6               [12] 8688 	mov	a,@r0
      002BF8 C0 E0            [24] 8689 	push	acc
      002BFA 08               [12] 8690 	inc	r0
      002BFB E6               [12] 8691 	mov	a,@r0
      002BFC C0 E0            [24] 8692 	push	acc
      002BFE 08               [12] 8693 	inc	r0
      002BFF E6               [12] 8694 	mov	a,@r0
      002C00 C0 E0            [24] 8695 	push	acc
      002C02 E5 08            [12] 8696 	mov	a,_bp
      002C04 24 F6            [12] 8697 	add	a,#0xf6
      002C06 F8               [12] 8698 	mov	r0,a
      002C07 E6               [12] 8699 	mov	a,@r0
      002C08 C0 E0            [24] 8700 	push	acc
      002C0A 08               [12] 8701 	inc	r0
      002C0B E6               [12] 8702 	mov	a,@r0
      002C0C C0 E0            [24] 8703 	push	acc
      002C0E 08               [12] 8704 	inc	r0
      002C0F E6               [12] 8705 	mov	a,@r0
      002C10 C0 E0            [24] 8706 	push	acc
      002C12 08               [12] 8707 	inc	r0
      002C13 E6               [12] 8708 	mov	a,@r0
      002C14 C0 E0            [24] 8709 	push	acc
      002C16 E5 08            [12] 8710 	mov	a,_bp
      002C18 24 FA            [12] 8711 	add	a,#0xfa
      002C1A F8               [12] 8712 	mov	r0,a
      002C1B E6               [12] 8713 	mov	a,@r0
      002C1C C0 E0            [24] 8714 	push	acc
      002C1E 08               [12] 8715 	inc	r0
      002C1F E6               [12] 8716 	mov	a,@r0
      002C20 C0 E0            [24] 8717 	push	acc
      002C22 08               [12] 8718 	inc	r0
      002C23 E6               [12] 8719 	mov	a,@r0
      002C24 C0 E0            [24] 8720 	push	acc
      002C26 08               [12] 8721 	inc	r0
      002C27 E6               [12] 8722 	mov	a,@r0
      002C28 C0 E0            [24] 8723 	push	acc
      002C2A A8 08            [24] 8724 	mov	r0,_bp
      002C2C 08               [12] 8725 	inc	r0
      002C2D E6               [12] 8726 	mov	a,@r0
      002C2E C0 E0            [24] 8727 	push	acc
      002C30 08               [12] 8728 	inc	r0
      002C31 E6               [12] 8729 	mov	a,@r0
      002C32 C0 E0            [24] 8730 	push	acc
      002C34 08               [12] 8731 	inc	r0
      002C35 E6               [12] 8732 	mov	a,@r0
      002C36 C0 E0            [24] 8733 	push	acc
      002C38 8A 82            [24] 8734 	mov	dpl, r2
      002C3A 8B 83            [24] 8735 	mov	dph, r3
      002C3C 8F F0            [24] 8736 	mov	b, r7
      002C3E 12 1D 47         [24] 8737 	lcall	_fuzzy_rules_maximum_result
      002C41 E5 81            [12] 8738 	mov	a,sp
      002C43 24 EF            [12] 8739 	add	a,#0xef
      002C45 F5 81            [12] 8740 	mov	sp,a
      002C47 D0 04            [24] 8741 	pop	ar4
                           002B8C  8742 	C$fuzzy.h$2947$1_0$136 ==.
                                   8743 ;	../../fuzzy.h:2947: result.position_count == 0u ||
      002C49 74 10            [12] 8744 	mov	a,#0x10
      002C4B 2C               [12] 8745 	add	a, r4
      002C4C F9               [12] 8746 	mov	r1,a
      002C4D 87 06            [24] 8747 	mov	ar6,@r1
      002C4F 09               [12] 8748 	inc	r1
      002C50 87 07            [24] 8749 	mov	ar7,@r1
      002C52 EE               [12] 8750 	mov	a,r6
      002C53 4F               [12] 8751 	orl	a,r7
      002C54 60 30            [24] 8752 	jz	00101$
                           002B99  8753 	C$fuzzy.h$2948$1_0$136 ==.
                                   8754 ;	../../fuzzy.h:2948: result.height <= LEVEL_LO
      002C56 8C 01            [24] 8755 	mov	ar1,r4
      002C58 87 03            [24] 8756 	mov	ar3,@r1
      002C5A 09               [12] 8757 	inc	r1
      002C5B 87 05            [24] 8758 	mov	ar5,@r1
      002C5D 09               [12] 8759 	inc	r1
      002C5E 87 06            [24] 8760 	mov	ar6,@r1
      002C60 09               [12] 8761 	inc	r1
      002C61 87 07            [24] 8762 	mov	ar7,@r1
      002C63 C0 04            [24] 8763 	push	ar4
      002C65 C0 03            [24] 8764 	push	ar3
      002C67 C0 05            [24] 8765 	push	ar5
      002C69 C0 06            [24] 8766 	push	ar6
      002C6B C0 07            [24] 8767 	push	ar7
      002C6D 90 00 00         [24] 8768 	mov	dptr,#0x0000
      002C70 E4               [12] 8769 	clr	a
      002C71 F5 F0            [12] 8770 	mov	b,a
      002C73 12 41 7C         [24] 8771 	lcall	___fslt
      002C76 E5 81            [12] 8772 	mov	a,sp
      002C78 24 FC            [12] 8773 	add	a,#0xfc
      002C7A F5 81            [12] 8774 	mov	sp,a
      002C7C D0 04            [24] 8775 	pop	ar4
      002C7E E5 82            [12] 8776 	mov	a, dpl
      002C80 24 FF            [12] 8777 	add	a,#0xff
      002C82 92 00            [24] 8778 	mov	b0,c
      002C84 40 08            [24] 8779 	jc	00102$
      002C86                       8780 00101$:
                           002BC9  8781 	C$fuzzy.h$2950$2_0$137 ==.
                                   8782 ;	../../fuzzy.h:2950: return 0.0f;
      002C86 90 00 00         [24] 8783 	mov	dptr,#0x0000
      002C89 E4               [12] 8784 	clr	a
      002C8A F5 F0            [12] 8785 	mov	b,a
      002C8C 80 16            [24] 8786 	sjmp	00104$
      002C8E                       8787 00102$:
                           002BD1  8788 	C$fuzzy.h$2953$1_0$136 ==.
                                   8789 ;	../../fuzzy.h:2953: return result.largest_position;
      002C8E 74 08            [12] 8790 	mov	a,#0x08
      002C90 2C               [12] 8791 	add	a, r4
      002C91 F9               [12] 8792 	mov	r1,a
      002C92 87 04            [24] 8793 	mov	ar4,@r1
      002C94 09               [12] 8794 	inc	r1
      002C95 87 05            [24] 8795 	mov	ar5,@r1
      002C97 09               [12] 8796 	inc	r1
      002C98 87 06            [24] 8797 	mov	ar6,@r1
      002C9A 09               [12] 8798 	inc	r1
      002C9B 87 07            [24] 8799 	mov	ar7,@r1
      002C9D 8C 82            [24] 8800 	mov	dpl, r4
      002C9F 8D 83            [24] 8801 	mov	dph, r5
      002CA1 8E F0            [24] 8802 	mov	b, r6
      002CA3 EF               [12] 8803 	mov	a, r7
      002CA4                       8804 00104$:
                           002BE7  8805 	C$fuzzy.h$2954$1_0$136 ==.
                                   8806 ;	../../fuzzy.h:2954: }
      002CA4 85 08 81         [24] 8807 	mov	sp,_bp
      002CA7 D0 08            [24] 8808 	pop	_bp
                           002BEC  8809 	C$fuzzy.h$2954$1_0$136 ==.
                           002BEC  8810 	XG$fuzzy_rules_defuzzify_lom$0$0 ==.
      002CA9 22               [24] 8811 	ret
                                   8812 ;------------------------------------------------------------
                                   8813 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_method'
                                   8814 ;------------------------------------------------------------
                                   8815 ;lower         Allocated to stack - _bp -6 +4 
                                   8816 ;upper         Allocated to stack - _bp -10 +4 
                                   8817 ;step          Allocated to stack - _bp -14 +4 
                                   8818 ;defuzz_method Allocated to stack - _bp -15 +1 
                                   8819 ;implication_method Allocated to stack - _bp -16 +1 
                                   8820 ;aggregation_method Allocated to stack - _bp -17 +1 
                                   8821 ;rules         Allocated to registers r5 r6 r7 
                                   8822 ;sloc0         Allocated to stack - _bp +1 +4 
                                   8823 ;------------------------------------------------------------
                           002BED  8824 	G$fuzzy_rules_defuzzify_method$0$0 ==.
                           002BED  8825 	C$fuzzy.h$2960$1_0$139 ==.
                                   8826 ;	../../fuzzy.h:2960: float fuzzy_rules_defuzzify_method(
                                   8827 ;	-----------------------------------------
                                   8828 ;	 function fuzzy_rules_defuzzify_method
                                   8829 ;	-----------------------------------------
      002CAA                       8830 _fuzzy_rules_defuzzify_method:
      002CAA C0 08            [24] 8831 	push	_bp
      002CAC E5 81            [12] 8832 	mov	a,sp
      002CAE F5 08            [12] 8833 	mov	_bp,a
      002CB0 24 04            [12] 8834 	add	a,#0x04
      002CB2 F5 81            [12] 8835 	mov	sp,a
      002CB4 AD 82            [24] 8836 	mov	r5, dpl
      002CB6 AE 83            [24] 8837 	mov	r6, dph
      002CB8 AF F0            [24] 8838 	mov	r7, b
                           002BFD  8839 	C$fuzzy.h$2971$1_0$139 ==.
                                   8840 ;	../../fuzzy.h:2971: rules == NULL ||
      002CBA ED               [12] 8841 	mov	a,r5
      002CBB 4E               [12] 8842 	orl	a,r6
      002CBC 70 03            [24] 8843 	jnz	00140$
      002CBE 02 2D 4F         [24] 8844 	ljmp	00101$
      002CC1                       8845 00140$:
                           002C04  8846 	C$fuzzy.h$2972$1_0$139 ==.
                                   8847 ;	../../fuzzy.h:2972: rules->count == 0u ||
      002CC1 74 90            [12] 8848 	mov	a,#0x90
      002CC3 2D               [12] 8849 	add	a, r5
      002CC4 FA               [12] 8850 	mov	r2,a
      002CC5 E4               [12] 8851 	clr	a
      002CC6 3E               [12] 8852 	addc	a, r6
      002CC7 FB               [12] 8853 	mov	r3,a
      002CC8 8F 04            [24] 8854 	mov	ar4,r7
      002CCA 8A 82            [24] 8855 	mov	dpl,r2
      002CCC 8B 83            [24] 8856 	mov	dph,r3
      002CCE 8C F0            [24] 8857 	mov	b,r4
      002CD0 12 43 A8         [24] 8858 	lcall	__gptrget
      002CD3 FA               [12] 8859 	mov	r2,a
      002CD4 A3               [24] 8860 	inc	dptr
      002CD5 12 43 A8         [24] 8861 	lcall	__gptrget
      002CD8 4A               [12] 8862 	orl	a,r2
      002CD9 60 74            [24] 8863 	jz	00101$
                           002C1E  8864 	C$fuzzy.h$2973$1_0$139 ==.
                                   8865 ;	../../fuzzy.h:2973: lower > upper ||
      002CDB C0 07            [24] 8866 	push	ar7
      002CDD C0 06            [24] 8867 	push	ar6
      002CDF C0 05            [24] 8868 	push	ar5
      002CE1 E5 08            [12] 8869 	mov	a,_bp
      002CE3 24 FA            [12] 8870 	add	a,#0xfa
      002CE5 F8               [12] 8871 	mov	r0,a
      002CE6 E6               [12] 8872 	mov	a,@r0
      002CE7 C0 E0            [24] 8873 	push	acc
      002CE9 08               [12] 8874 	inc	r0
      002CEA E6               [12] 8875 	mov	a,@r0
      002CEB C0 E0            [24] 8876 	push	acc
      002CED 08               [12] 8877 	inc	r0
      002CEE E6               [12] 8878 	mov	a,@r0
      002CEF C0 E0            [24] 8879 	push	acc
      002CF1 08               [12] 8880 	inc	r0
      002CF2 E6               [12] 8881 	mov	a,@r0
      002CF3 C0 E0            [24] 8882 	push	acc
      002CF5 E5 08            [12] 8883 	mov	a,_bp
      002CF7 24 F6            [12] 8884 	add	a,#0xf6
      002CF9 F8               [12] 8885 	mov	r0,a
      002CFA 86 82            [24] 8886 	mov	dpl, @r0
      002CFC 08               [12] 8887 	inc	r0
      002CFD 86 83            [24] 8888 	mov	dph, @r0
      002CFF 08               [12] 8889 	inc	r0
      002D00 86 F0            [24] 8890 	mov	b, @r0
      002D02 08               [12] 8891 	inc	r0
      002D03 E6               [12] 8892 	mov	a, @r0
      002D04 12 41 7C         [24] 8893 	lcall	___fslt
      002D07 AC 82            [24] 8894 	mov	r4, dpl
      002D09 E5 81            [12] 8895 	mov	a,sp
      002D0B 24 FC            [12] 8896 	add	a,#0xfc
      002D0D F5 81            [12] 8897 	mov	sp,a
      002D0F D0 05            [24] 8898 	pop	ar5
      002D11 D0 06            [24] 8899 	pop	ar6
      002D13 D0 07            [24] 8900 	pop	ar7
      002D15 EC               [12] 8901 	mov	a,r4
      002D16 70 37            [24] 8902 	jnz	00101$
                           002C5B  8903 	C$fuzzy.h$2975$1_0$139 ==.
                                   8904 ;	../../fuzzy.h:2975: ) {
      002D18 C0 07            [24] 8905 	push	ar7
      002D1A C0 06            [24] 8906 	push	ar6
      002D1C C0 05            [24] 8907 	push	ar5
      002D1E E5 08            [12] 8908 	mov	a,_bp
      002D20 24 F2            [12] 8909 	add	a,#0xf2
      002D22 F8               [12] 8910 	mov	r0,a
      002D23 E6               [12] 8911 	mov	a,@r0
      002D24 C0 E0            [24] 8912 	push	acc
      002D26 08               [12] 8913 	inc	r0
      002D27 E6               [12] 8914 	mov	a,@r0
      002D28 C0 E0            [24] 8915 	push	acc
      002D2A 08               [12] 8916 	inc	r0
      002D2B E6               [12] 8917 	mov	a,@r0
      002D2C C0 E0            [24] 8918 	push	acc
      002D2E 08               [12] 8919 	inc	r0
      002D2F E6               [12] 8920 	mov	a,@r0
      002D30 C0 E0            [24] 8921 	push	acc
      002D32 90 00 00         [24] 8922 	mov	dptr,#0x0000
      002D35 E4               [12] 8923 	clr	a
      002D36 F5 F0            [12] 8924 	mov	b,a
      002D38 12 41 7C         [24] 8925 	lcall	___fslt
      002D3B E5 81            [12] 8926 	mov	a,sp
      002D3D 24 FC            [12] 8927 	add	a,#0xfc
      002D3F F5 81            [12] 8928 	mov	sp,a
      002D41 D0 05            [24] 8929 	pop	ar5
      002D43 D0 06            [24] 8930 	pop	ar6
      002D45 D0 07            [24] 8931 	pop	ar7
      002D47 E5 82            [12] 8932 	mov	a, dpl
      002D49 24 FF            [12] 8933 	add	a,#0xff
      002D4B 92 00            [24] 8934 	mov	b0,c
      002D4D 40 09            [24] 8935 	jc	00102$
      002D4F                       8936 00101$:
                           002C92  8937 	C$fuzzy.h$2976$2_0$140 ==.
                                   8938 ;	../../fuzzy.h:2976: return 0.0f;
      002D4F 90 00 00         [24] 8939 	mov	dptr,#0x0000
      002D52 E4               [12] 8940 	clr	a
      002D53 F5 F0            [12] 8941 	mov	b,a
      002D55 02 30 43         [24] 8942 	ljmp	00114$
      002D58                       8943 00102$:
                           002C9B  8944 	C$fuzzy.h$2979$1_0$139 ==.
                                   8945 ;	../../fuzzy.h:2979: switch (defuzz_method) {
      002D58 E5 08            [12] 8946 	mov	a,_bp
      002D5A 24 F1            [12] 8947 	add	a,#0xf1
      002D5C F8               [12] 8948 	mov	r0,a
      002D5D E6               [12] 8949 	mov	a,@r0
      002D5E 24 FA            [12] 8950 	add	a,#0xff - 0x05
      002D60 50 03            [24] 8951 	jnc	00144$
      002D62 02 30 3D         [24] 8952 	ljmp	00112$
      002D65                       8953 00144$:
      002D65 E5 08            [12] 8954 	mov	a,_bp
      002D67 24 F1            [12] 8955 	add	a,#0xf1
      002D69 F8               [12] 8956 	mov	r0,a
      002D6A E6               [12] 8957 	mov	a,@r0
      002D6B 26               [12] 8958 	add	a,@r0
      002D6C 26               [12] 8959 	add	a,@r0
      002D6D 90 2D 71         [24] 8960 	mov	dptr,#00145$
      002D70 73               [24] 8961 	jmp	@a+dptr
      002D71                       8962 00145$:
      002D71 02 2D 83         [24] 8963 	ljmp	00106$
      002D74 02 2D FB         [24] 8964 	ljmp	00107$
      002D77 02 2E 73         [24] 8965 	ljmp	00108$
      002D7A 02 2E E3         [24] 8966 	ljmp	00109$
      002D7D 02 2F 5B         [24] 8967 	ljmp	00110$
      002D80 02 2F D2         [24] 8968 	ljmp	00111$
                           002CC6  8969 	C$fuzzy.h$2980$2_0$141 ==.
                                   8970 ;	../../fuzzy.h:2980: case FUZZY_DEFUZZ_COG:
      002D83                       8971 00106$:
                           002CC6  8972 	C$fuzzy.h$2982$2_0$141 ==.
                                   8973 ;	../../fuzzy.h:2982: rules,
      002D83 E5 08            [12] 8974 	mov	a,_bp
      002D85 24 EF            [12] 8975 	add	a,#0xef
      002D87 F8               [12] 8976 	mov	r0,a
      002D88 E6               [12] 8977 	mov	a,@r0
      002D89 C0 E0            [24] 8978 	push	acc
      002D8B E5 08            [12] 8979 	mov	a,_bp
      002D8D 24 F0            [12] 8980 	add	a,#0xf0
      002D8F F8               [12] 8981 	mov	r0,a
      002D90 E6               [12] 8982 	mov	a,@r0
      002D91 C0 E0            [24] 8983 	push	acc
      002D93 E5 08            [12] 8984 	mov	a,_bp
      002D95 24 F2            [12] 8985 	add	a,#0xf2
      002D97 F8               [12] 8986 	mov	r0,a
      002D98 E6               [12] 8987 	mov	a,@r0
      002D99 C0 E0            [24] 8988 	push	acc
      002D9B 08               [12] 8989 	inc	r0
      002D9C E6               [12] 8990 	mov	a,@r0
      002D9D C0 E0            [24] 8991 	push	acc
      002D9F 08               [12] 8992 	inc	r0
      002DA0 E6               [12] 8993 	mov	a,@r0
      002DA1 C0 E0            [24] 8994 	push	acc
      002DA3 08               [12] 8995 	inc	r0
      002DA4 E6               [12] 8996 	mov	a,@r0
      002DA5 C0 E0            [24] 8997 	push	acc
      002DA7 E5 08            [12] 8998 	mov	a,_bp
      002DA9 24 F6            [12] 8999 	add	a,#0xf6
      002DAB F8               [12] 9000 	mov	r0,a
      002DAC E6               [12] 9001 	mov	a,@r0
      002DAD C0 E0            [24] 9002 	push	acc
      002DAF 08               [12] 9003 	inc	r0
      002DB0 E6               [12] 9004 	mov	a,@r0
      002DB1 C0 E0            [24] 9005 	push	acc
      002DB3 08               [12] 9006 	inc	r0
      002DB4 E6               [12] 9007 	mov	a,@r0
      002DB5 C0 E0            [24] 9008 	push	acc
      002DB7 08               [12] 9009 	inc	r0
      002DB8 E6               [12] 9010 	mov	a,@r0
      002DB9 C0 E0            [24] 9011 	push	acc
      002DBB E5 08            [12] 9012 	mov	a,_bp
      002DBD 24 FA            [12] 9013 	add	a,#0xfa
      002DBF F8               [12] 9014 	mov	r0,a
      002DC0 E6               [12] 9015 	mov	a,@r0
      002DC1 C0 E0            [24] 9016 	push	acc
      002DC3 08               [12] 9017 	inc	r0
      002DC4 E6               [12] 9018 	mov	a,@r0
      002DC5 C0 E0            [24] 9019 	push	acc
      002DC7 08               [12] 9020 	inc	r0
      002DC8 E6               [12] 9021 	mov	a,@r0
      002DC9 C0 E0            [24] 9022 	push	acc
      002DCB 08               [12] 9023 	inc	r0
      002DCC E6               [12] 9024 	mov	a,@r0
      002DCD C0 E0            [24] 9025 	push	acc
      002DCF 8D 82            [24] 9026 	mov	dpl, r5
      002DD1 8E 83            [24] 9027 	mov	dph, r6
      002DD3 8F F0            [24] 9028 	mov	b, r7
      002DD5 12 21 45         [24] 9029 	lcall	_fuzzy_rules_defuzzify_cog
      002DD8 A8 08            [24] 9030 	mov	r0,_bp
      002DDA 08               [12] 9031 	inc	r0
      002DDB A6 82            [24] 9032 	mov	@r0, dpl
      002DDD 08               [12] 9033 	inc	r0
      002DDE A6 83            [24] 9034 	mov	@r0, dph
      002DE0 08               [12] 9035 	inc	r0
      002DE1 A6 F0            [24] 9036 	mov	@r0, b
      002DE3 08               [12] 9037 	inc	r0
      002DE4 F6               [12] 9038 	mov	@r0,a
      002DE5 E5 81            [12] 9039 	mov	a,sp
      002DE7 24 F2            [12] 9040 	add	a,#0xf2
      002DE9 F5 81            [12] 9041 	mov	sp,a
      002DEB A8 08            [24] 9042 	mov	r0,_bp
      002DED 08               [12] 9043 	inc	r0
      002DEE 86 82            [24] 9044 	mov	dpl, @r0
      002DF0 08               [12] 9045 	inc	r0
      002DF1 86 83            [24] 9046 	mov	dph, @r0
      002DF3 08               [12] 9047 	inc	r0
      002DF4 86 F0            [24] 9048 	mov	b, @r0
      002DF6 08               [12] 9049 	inc	r0
      002DF7 E6               [12] 9050 	mov	a, @r0
      002DF8 02 30 43         [24] 9051 	ljmp	00114$
                           002D3E  9052 	C$fuzzy.h$2990$2_0$141 ==.
                                   9053 ;	../../fuzzy.h:2990: case FUZZY_DEFUZZ_BOA:
      002DFB                       9054 00107$:
                           002D3E  9055 	C$fuzzy.h$2992$2_0$141 ==.
                                   9056 ;	../../fuzzy.h:2992: rules,
      002DFB E5 08            [12] 9057 	mov	a,_bp
      002DFD 24 EF            [12] 9058 	add	a,#0xef
      002DFF F8               [12] 9059 	mov	r0,a
      002E00 E6               [12] 9060 	mov	a,@r0
      002E01 C0 E0            [24] 9061 	push	acc
      002E03 E5 08            [12] 9062 	mov	a,_bp
      002E05 24 F0            [12] 9063 	add	a,#0xf0
      002E07 F8               [12] 9064 	mov	r0,a
      002E08 E6               [12] 9065 	mov	a,@r0
      002E09 C0 E0            [24] 9066 	push	acc
      002E0B E5 08            [12] 9067 	mov	a,_bp
      002E0D 24 F2            [12] 9068 	add	a,#0xf2
      002E0F F8               [12] 9069 	mov	r0,a
      002E10 E6               [12] 9070 	mov	a,@r0
      002E11 C0 E0            [24] 9071 	push	acc
      002E13 08               [12] 9072 	inc	r0
      002E14 E6               [12] 9073 	mov	a,@r0
      002E15 C0 E0            [24] 9074 	push	acc
      002E17 08               [12] 9075 	inc	r0
      002E18 E6               [12] 9076 	mov	a,@r0
      002E19 C0 E0            [24] 9077 	push	acc
      002E1B 08               [12] 9078 	inc	r0
      002E1C E6               [12] 9079 	mov	a,@r0
      002E1D C0 E0            [24] 9080 	push	acc
      002E1F E5 08            [12] 9081 	mov	a,_bp
      002E21 24 F6            [12] 9082 	add	a,#0xf6
      002E23 F8               [12] 9083 	mov	r0,a
      002E24 E6               [12] 9084 	mov	a,@r0
      002E25 C0 E0            [24] 9085 	push	acc
      002E27 08               [12] 9086 	inc	r0
      002E28 E6               [12] 9087 	mov	a,@r0
      002E29 C0 E0            [24] 9088 	push	acc
      002E2B 08               [12] 9089 	inc	r0
      002E2C E6               [12] 9090 	mov	a,@r0
      002E2D C0 E0            [24] 9091 	push	acc
      002E2F 08               [12] 9092 	inc	r0
      002E30 E6               [12] 9093 	mov	a,@r0
      002E31 C0 E0            [24] 9094 	push	acc
      002E33 E5 08            [12] 9095 	mov	a,_bp
      002E35 24 FA            [12] 9096 	add	a,#0xfa
      002E37 F8               [12] 9097 	mov	r0,a
      002E38 E6               [12] 9098 	mov	a,@r0
      002E39 C0 E0            [24] 9099 	push	acc
      002E3B 08               [12] 9100 	inc	r0
      002E3C E6               [12] 9101 	mov	a,@r0
      002E3D C0 E0            [24] 9102 	push	acc
      002E3F 08               [12] 9103 	inc	r0
      002E40 E6               [12] 9104 	mov	a,@r0
      002E41 C0 E0            [24] 9105 	push	acc
      002E43 08               [12] 9106 	inc	r0
      002E44 E6               [12] 9107 	mov	a,@r0
      002E45 C0 E0            [24] 9108 	push	acc
      002E47 8D 82            [24] 9109 	mov	dpl, r5
      002E49 8E 83            [24] 9110 	mov	dph, r6
      002E4B 8F F0            [24] 9111 	mov	b, r7
      002E4D 12 23 58         [24] 9112 	lcall	_fuzzy_rules_defuzzify_boa
      002E50 A8 08            [24] 9113 	mov	r0,_bp
      002E52 08               [12] 9114 	inc	r0
      002E53 A6 82            [24] 9115 	mov	@r0, dpl
      002E55 08               [12] 9116 	inc	r0
      002E56 A6 83            [24] 9117 	mov	@r0, dph
      002E58 08               [12] 9118 	inc	r0
      002E59 A6 F0            [24] 9119 	mov	@r0, b
      002E5B 08               [12] 9120 	inc	r0
      002E5C F6               [12] 9121 	mov	@r0,a
      002E5D E5 81            [12] 9122 	mov	a,sp
      002E5F 24 F2            [12] 9123 	add	a,#0xf2
      002E61 F5 81            [12] 9124 	mov	sp,a
      002E63 A8 08            [24] 9125 	mov	r0,_bp
      002E65 08               [12] 9126 	inc	r0
      002E66 86 82            [24] 9127 	mov	dpl, @r0
      002E68 08               [12] 9128 	inc	r0
      002E69 86 83            [24] 9129 	mov	dph, @r0
      002E6B 08               [12] 9130 	inc	r0
      002E6C 86 F0            [24] 9131 	mov	b, @r0
      002E6E 08               [12] 9132 	inc	r0
      002E6F E6               [12] 9133 	mov	a, @r0
      002E70 02 30 43         [24] 9134 	ljmp	00114$
                           002DB6  9135 	C$fuzzy.h$3000$2_0$141 ==.
                                   9136 ;	../../fuzzy.h:3000: case FUZZY_DEFUZZ_COS:
      002E73                       9137 00108$:
                           002DB6  9138 	C$fuzzy.h$3002$2_0$141 ==.
                                   9139 ;	../../fuzzy.h:3002: rules,
      002E73 E5 08            [12] 9140 	mov	a,_bp
      002E75 24 F0            [12] 9141 	add	a,#0xf0
      002E77 F8               [12] 9142 	mov	r0,a
      002E78 E6               [12] 9143 	mov	a,@r0
      002E79 C0 E0            [24] 9144 	push	acc
      002E7B E5 08            [12] 9145 	mov	a,_bp
      002E7D 24 F2            [12] 9146 	add	a,#0xf2
      002E7F F8               [12] 9147 	mov	r0,a
      002E80 E6               [12] 9148 	mov	a,@r0
      002E81 C0 E0            [24] 9149 	push	acc
      002E83 08               [12] 9150 	inc	r0
      002E84 E6               [12] 9151 	mov	a,@r0
      002E85 C0 E0            [24] 9152 	push	acc
      002E87 08               [12] 9153 	inc	r0
      002E88 E6               [12] 9154 	mov	a,@r0
      002E89 C0 E0            [24] 9155 	push	acc
      002E8B 08               [12] 9156 	inc	r0
      002E8C E6               [12] 9157 	mov	a,@r0
      002E8D C0 E0            [24] 9158 	push	acc
      002E8F E5 08            [12] 9159 	mov	a,_bp
      002E91 24 F6            [12] 9160 	add	a,#0xf6
      002E93 F8               [12] 9161 	mov	r0,a
      002E94 E6               [12] 9162 	mov	a,@r0
      002E95 C0 E0            [24] 9163 	push	acc
      002E97 08               [12] 9164 	inc	r0
      002E98 E6               [12] 9165 	mov	a,@r0
      002E99 C0 E0            [24] 9166 	push	acc
      002E9B 08               [12] 9167 	inc	r0
      002E9C E6               [12] 9168 	mov	a,@r0
      002E9D C0 E0            [24] 9169 	push	acc
      002E9F 08               [12] 9170 	inc	r0
      002EA0 E6               [12] 9171 	mov	a,@r0
      002EA1 C0 E0            [24] 9172 	push	acc
      002EA3 E5 08            [12] 9173 	mov	a,_bp
      002EA5 24 FA            [12] 9174 	add	a,#0xfa
      002EA7 F8               [12] 9175 	mov	r0,a
      002EA8 E6               [12] 9176 	mov	a,@r0
      002EA9 C0 E0            [24] 9177 	push	acc
      002EAB 08               [12] 9178 	inc	r0
      002EAC E6               [12] 9179 	mov	a,@r0
      002EAD C0 E0            [24] 9180 	push	acc
      002EAF 08               [12] 9181 	inc	r0
      002EB0 E6               [12] 9182 	mov	a,@r0
      002EB1 C0 E0            [24] 9183 	push	acc
      002EB3 08               [12] 9184 	inc	r0
      002EB4 E6               [12] 9185 	mov	a,@r0
      002EB5 C0 E0            [24] 9186 	push	acc
      002EB7 8D 82            [24] 9187 	mov	dpl, r5
      002EB9 8E 83            [24] 9188 	mov	dph, r6
      002EBB 8F F0            [24] 9189 	mov	b, r7
      002EBD 12 26 3E         [24] 9190 	lcall	_fuzzy_rules_defuzzify_cos
      002EC0 A8 08            [24] 9191 	mov	r0,_bp
      002EC2 08               [12] 9192 	inc	r0
      002EC3 A6 82            [24] 9193 	mov	@r0, dpl
      002EC5 08               [12] 9194 	inc	r0
      002EC6 A6 83            [24] 9195 	mov	@r0, dph
      002EC8 08               [12] 9196 	inc	r0
      002EC9 A6 F0            [24] 9197 	mov	@r0, b
      002ECB 08               [12] 9198 	inc	r0
      002ECC F6               [12] 9199 	mov	@r0,a
      002ECD E5 81            [12] 9200 	mov	a,sp
      002ECF 24 F3            [12] 9201 	add	a,#0xf3
      002ED1 F5 81            [12] 9202 	mov	sp,a
      002ED3 A8 08            [24] 9203 	mov	r0,_bp
      002ED5 08               [12] 9204 	inc	r0
      002ED6 86 82            [24] 9205 	mov	dpl, @r0
      002ED8 08               [12] 9206 	inc	r0
      002ED9 86 83            [24] 9207 	mov	dph, @r0
      002EDB 08               [12] 9208 	inc	r0
      002EDC 86 F0            [24] 9209 	mov	b, @r0
      002EDE 08               [12] 9210 	inc	r0
      002EDF E6               [12] 9211 	mov	a, @r0
      002EE0 02 30 43         [24] 9212 	ljmp	00114$
                           002E26  9213 	C$fuzzy.h$3009$2_0$141 ==.
                                   9214 ;	../../fuzzy.h:3009: case FUZZY_DEFUZZ_MOM:
      002EE3                       9215 00109$:
                           002E26  9216 	C$fuzzy.h$3011$2_0$141 ==.
                                   9217 ;	../../fuzzy.h:3011: rules,
      002EE3 E5 08            [12] 9218 	mov	a,_bp
      002EE5 24 EF            [12] 9219 	add	a,#0xef
      002EE7 F8               [12] 9220 	mov	r0,a
      002EE8 E6               [12] 9221 	mov	a,@r0
      002EE9 C0 E0            [24] 9222 	push	acc
      002EEB E5 08            [12] 9223 	mov	a,_bp
      002EED 24 F0            [12] 9224 	add	a,#0xf0
      002EEF F8               [12] 9225 	mov	r0,a
      002EF0 E6               [12] 9226 	mov	a,@r0
      002EF1 C0 E0            [24] 9227 	push	acc
      002EF3 E5 08            [12] 9228 	mov	a,_bp
      002EF5 24 F2            [12] 9229 	add	a,#0xf2
      002EF7 F8               [12] 9230 	mov	r0,a
      002EF8 E6               [12] 9231 	mov	a,@r0
      002EF9 C0 E0            [24] 9232 	push	acc
      002EFB 08               [12] 9233 	inc	r0
      002EFC E6               [12] 9234 	mov	a,@r0
      002EFD C0 E0            [24] 9235 	push	acc
      002EFF 08               [12] 9236 	inc	r0
      002F00 E6               [12] 9237 	mov	a,@r0
      002F01 C0 E0            [24] 9238 	push	acc
      002F03 08               [12] 9239 	inc	r0
      002F04 E6               [12] 9240 	mov	a,@r0
      002F05 C0 E0            [24] 9241 	push	acc
      002F07 E5 08            [12] 9242 	mov	a,_bp
      002F09 24 F6            [12] 9243 	add	a,#0xf6
      002F0B F8               [12] 9244 	mov	r0,a
      002F0C E6               [12] 9245 	mov	a,@r0
      002F0D C0 E0            [24] 9246 	push	acc
      002F0F 08               [12] 9247 	inc	r0
      002F10 E6               [12] 9248 	mov	a,@r0
      002F11 C0 E0            [24] 9249 	push	acc
      002F13 08               [12] 9250 	inc	r0
      002F14 E6               [12] 9251 	mov	a,@r0
      002F15 C0 E0            [24] 9252 	push	acc
      002F17 08               [12] 9253 	inc	r0
      002F18 E6               [12] 9254 	mov	a,@r0
      002F19 C0 E0            [24] 9255 	push	acc
      002F1B E5 08            [12] 9256 	mov	a,_bp
      002F1D 24 FA            [12] 9257 	add	a,#0xfa
      002F1F F8               [12] 9258 	mov	r0,a
      002F20 E6               [12] 9259 	mov	a,@r0
      002F21 C0 E0            [24] 9260 	push	acc
      002F23 08               [12] 9261 	inc	r0
      002F24 E6               [12] 9262 	mov	a,@r0
      002F25 C0 E0            [24] 9263 	push	acc
      002F27 08               [12] 9264 	inc	r0
      002F28 E6               [12] 9265 	mov	a,@r0
      002F29 C0 E0            [24] 9266 	push	acc
      002F2B 08               [12] 9267 	inc	r0
      002F2C E6               [12] 9268 	mov	a,@r0
      002F2D C0 E0            [24] 9269 	push	acc
      002F2F 8D 82            [24] 9270 	mov	dpl, r5
      002F31 8E 83            [24] 9271 	mov	dph, r6
      002F33 8F F0            [24] 9272 	mov	b, r7
      002F35 12 29 A1         [24] 9273 	lcall	_fuzzy_rules_defuzzify_mom
      002F38 A8 08            [24] 9274 	mov	r0,_bp
      002F3A 08               [12] 9275 	inc	r0
      002F3B A6 82            [24] 9276 	mov	@r0, dpl
      002F3D 08               [12] 9277 	inc	r0
      002F3E A6 83            [24] 9278 	mov	@r0, dph
      002F40 08               [12] 9279 	inc	r0
      002F41 A6 F0            [24] 9280 	mov	@r0, b
      002F43 08               [12] 9281 	inc	r0
      002F44 F6               [12] 9282 	mov	@r0,a
      002F45 E5 81            [12] 9283 	mov	a,sp
      002F47 24 F2            [12] 9284 	add	a,#0xf2
      002F49 F5 81            [12] 9285 	mov	sp,a
      002F4B A8 08            [24] 9286 	mov	r0,_bp
      002F4D 08               [12] 9287 	inc	r0
      002F4E 86 82            [24] 9288 	mov	dpl, @r0
      002F50 08               [12] 9289 	inc	r0
      002F51 86 83            [24] 9290 	mov	dph, @r0
      002F53 08               [12] 9291 	inc	r0
      002F54 86 F0            [24] 9292 	mov	b, @r0
      002F56 08               [12] 9293 	inc	r0
      002F57 E6               [12] 9294 	mov	a, @r0
      002F58 02 30 43         [24] 9295 	ljmp	00114$
                           002E9E  9296 	C$fuzzy.h$3019$2_0$141 ==.
                                   9297 ;	../../fuzzy.h:3019: case FUZZY_DEFUZZ_SOM:
      002F5B                       9298 00110$:
                           002E9E  9299 	C$fuzzy.h$3021$2_0$141 ==.
                                   9300 ;	../../fuzzy.h:3021: rules,
      002F5B E5 08            [12] 9301 	mov	a,_bp
      002F5D 24 EF            [12] 9302 	add	a,#0xef
      002F5F F8               [12] 9303 	mov	r0,a
      002F60 E6               [12] 9304 	mov	a,@r0
      002F61 C0 E0            [24] 9305 	push	acc
      002F63 E5 08            [12] 9306 	mov	a,_bp
      002F65 24 F0            [12] 9307 	add	a,#0xf0
      002F67 F8               [12] 9308 	mov	r0,a
      002F68 E6               [12] 9309 	mov	a,@r0
      002F69 C0 E0            [24] 9310 	push	acc
      002F6B E5 08            [12] 9311 	mov	a,_bp
      002F6D 24 F2            [12] 9312 	add	a,#0xf2
      002F6F F8               [12] 9313 	mov	r0,a
      002F70 E6               [12] 9314 	mov	a,@r0
      002F71 C0 E0            [24] 9315 	push	acc
      002F73 08               [12] 9316 	inc	r0
      002F74 E6               [12] 9317 	mov	a,@r0
      002F75 C0 E0            [24] 9318 	push	acc
      002F77 08               [12] 9319 	inc	r0
      002F78 E6               [12] 9320 	mov	a,@r0
      002F79 C0 E0            [24] 9321 	push	acc
      002F7B 08               [12] 9322 	inc	r0
      002F7C E6               [12] 9323 	mov	a,@r0
      002F7D C0 E0            [24] 9324 	push	acc
      002F7F E5 08            [12] 9325 	mov	a,_bp
      002F81 24 F6            [12] 9326 	add	a,#0xf6
      002F83 F8               [12] 9327 	mov	r0,a
      002F84 E6               [12] 9328 	mov	a,@r0
      002F85 C0 E0            [24] 9329 	push	acc
      002F87 08               [12] 9330 	inc	r0
      002F88 E6               [12] 9331 	mov	a,@r0
      002F89 C0 E0            [24] 9332 	push	acc
      002F8B 08               [12] 9333 	inc	r0
      002F8C E6               [12] 9334 	mov	a,@r0
      002F8D C0 E0            [24] 9335 	push	acc
      002F8F 08               [12] 9336 	inc	r0
      002F90 E6               [12] 9337 	mov	a,@r0
      002F91 C0 E0            [24] 9338 	push	acc
      002F93 E5 08            [12] 9339 	mov	a,_bp
      002F95 24 FA            [12] 9340 	add	a,#0xfa
      002F97 F8               [12] 9341 	mov	r0,a
      002F98 E6               [12] 9342 	mov	a,@r0
      002F99 C0 E0            [24] 9343 	push	acc
      002F9B 08               [12] 9344 	inc	r0
      002F9C E6               [12] 9345 	mov	a,@r0
      002F9D C0 E0            [24] 9346 	push	acc
      002F9F 08               [12] 9347 	inc	r0
      002FA0 E6               [12] 9348 	mov	a,@r0
      002FA1 C0 E0            [24] 9349 	push	acc
      002FA3 08               [12] 9350 	inc	r0
      002FA4 E6               [12] 9351 	mov	a,@r0
      002FA5 C0 E0            [24] 9352 	push	acc
      002FA7 8D 82            [24] 9353 	mov	dpl, r5
      002FA9 8E 83            [24] 9354 	mov	dph, r6
      002FAB 8F F0            [24] 9355 	mov	b, r7
      002FAD 12 2A D8         [24] 9356 	lcall	_fuzzy_rules_defuzzify_som
      002FB0 A8 08            [24] 9357 	mov	r0,_bp
      002FB2 08               [12] 9358 	inc	r0
      002FB3 A6 82            [24] 9359 	mov	@r0, dpl
      002FB5 08               [12] 9360 	inc	r0
      002FB6 A6 83            [24] 9361 	mov	@r0, dph
      002FB8 08               [12] 9362 	inc	r0
      002FB9 A6 F0            [24] 9363 	mov	@r0, b
      002FBB 08               [12] 9364 	inc	r0
      002FBC F6               [12] 9365 	mov	@r0,a
      002FBD E5 81            [12] 9366 	mov	a,sp
      002FBF 24 F2            [12] 9367 	add	a,#0xf2
      002FC1 F5 81            [12] 9368 	mov	sp,a
      002FC3 A8 08            [24] 9369 	mov	r0,_bp
      002FC5 08               [12] 9370 	inc	r0
      002FC6 86 82            [24] 9371 	mov	dpl, @r0
      002FC8 08               [12] 9372 	inc	r0
      002FC9 86 83            [24] 9373 	mov	dph, @r0
      002FCB 08               [12] 9374 	inc	r0
      002FCC 86 F0            [24] 9375 	mov	b, @r0
      002FCE 08               [12] 9376 	inc	r0
      002FCF E6               [12] 9377 	mov	a, @r0
                           002F13  9378 	C$fuzzy.h$3029$2_0$141 ==.
                                   9379 ;	../../fuzzy.h:3029: case FUZZY_DEFUZZ_LOM:
      002FD0 80 71            [24] 9380 	sjmp	00114$
      002FD2                       9381 00111$:
                           002F15  9382 	C$fuzzy.h$3031$2_0$141 ==.
                                   9383 ;	../../fuzzy.h:3031: rules,
      002FD2 E5 08            [12] 9384 	mov	a,_bp
      002FD4 24 EF            [12] 9385 	add	a,#0xef
      002FD6 F8               [12] 9386 	mov	r0,a
      002FD7 E6               [12] 9387 	mov	a,@r0
      002FD8 C0 E0            [24] 9388 	push	acc
      002FDA E5 08            [12] 9389 	mov	a,_bp
      002FDC 24 F0            [12] 9390 	add	a,#0xf0
      002FDE F8               [12] 9391 	mov	r0,a
      002FDF E6               [12] 9392 	mov	a,@r0
      002FE0 C0 E0            [24] 9393 	push	acc
      002FE2 E5 08            [12] 9394 	mov	a,_bp
      002FE4 24 F2            [12] 9395 	add	a,#0xf2
      002FE6 F8               [12] 9396 	mov	r0,a
      002FE7 E6               [12] 9397 	mov	a,@r0
      002FE8 C0 E0            [24] 9398 	push	acc
      002FEA 08               [12] 9399 	inc	r0
      002FEB E6               [12] 9400 	mov	a,@r0
      002FEC C0 E0            [24] 9401 	push	acc
      002FEE 08               [12] 9402 	inc	r0
      002FEF E6               [12] 9403 	mov	a,@r0
      002FF0 C0 E0            [24] 9404 	push	acc
      002FF2 08               [12] 9405 	inc	r0
      002FF3 E6               [12] 9406 	mov	a,@r0
      002FF4 C0 E0            [24] 9407 	push	acc
      002FF6 E5 08            [12] 9408 	mov	a,_bp
      002FF8 24 F6            [12] 9409 	add	a,#0xf6
      002FFA F8               [12] 9410 	mov	r0,a
      002FFB E6               [12] 9411 	mov	a,@r0
      002FFC C0 E0            [24] 9412 	push	acc
      002FFE 08               [12] 9413 	inc	r0
      002FFF E6               [12] 9414 	mov	a,@r0
      003000 C0 E0            [24] 9415 	push	acc
      003002 08               [12] 9416 	inc	r0
      003003 E6               [12] 9417 	mov	a,@r0
      003004 C0 E0            [24] 9418 	push	acc
      003006 08               [12] 9419 	inc	r0
      003007 E6               [12] 9420 	mov	a,@r0
      003008 C0 E0            [24] 9421 	push	acc
      00300A E5 08            [12] 9422 	mov	a,_bp
      00300C 24 FA            [12] 9423 	add	a,#0xfa
      00300E F8               [12] 9424 	mov	r0,a
      00300F E6               [12] 9425 	mov	a,@r0
      003010 C0 E0            [24] 9426 	push	acc
      003012 08               [12] 9427 	inc	r0
      003013 E6               [12] 9428 	mov	a,@r0
      003014 C0 E0            [24] 9429 	push	acc
      003016 08               [12] 9430 	inc	r0
      003017 E6               [12] 9431 	mov	a,@r0
      003018 C0 E0            [24] 9432 	push	acc
      00301A 08               [12] 9433 	inc	r0
      00301B E6               [12] 9434 	mov	a,@r0
      00301C C0 E0            [24] 9435 	push	acc
      00301E 8D 82            [24] 9436 	mov	dpl, r5
      003020 8E 83            [24] 9437 	mov	dph, r6
      003022 8F F0            [24] 9438 	mov	b, r7
      003024 12 2B C1         [24] 9439 	lcall	_fuzzy_rules_defuzzify_lom
      003027 AC 82            [24] 9440 	mov	r4, dpl
      003029 AD 83            [24] 9441 	mov	r5, dph
      00302B AE F0            [24] 9442 	mov	r6, b
      00302D FF               [12] 9443 	mov	r7, a
      00302E E5 81            [12] 9444 	mov	a,sp
      003030 24 F2            [12] 9445 	add	a,#0xf2
      003032 F5 81            [12] 9446 	mov	sp,a
      003034 8C 82            [24] 9447 	mov	dpl, r4
      003036 8D 83            [24] 9448 	mov	dph, r5
      003038 8E F0            [24] 9449 	mov	b, r6
      00303A EF               [12] 9450 	mov	a, r7
                           002F7E  9451 	C$fuzzy.h$3039$2_0$141 ==.
                                   9452 ;	../../fuzzy.h:3039: default:
      00303B 80 06            [24] 9453 	sjmp	00114$
      00303D                       9454 00112$:
                           002F80  9455 	C$fuzzy.h$3040$2_0$141 ==.
                                   9456 ;	../../fuzzy.h:3040: return 0.0f;
      00303D 90 00 00         [24] 9457 	mov	dptr,#0x0000
      003040 E4               [12] 9458 	clr	a
      003041 F5 F0            [12] 9459 	mov	b,a
                           002F86  9460 	C$fuzzy.h$3041$1_0$139 ==.
                                   9461 ;	../../fuzzy.h:3041: }
      003043                       9462 00114$:
                           002F86  9463 	C$fuzzy.h$3042$1_0$139 ==.
                                   9464 ;	../../fuzzy.h:3042: }
      003043 85 08 81         [24] 9465 	mov	sp,_bp
      003046 D0 08            [24] 9466 	pop	_bp
                           002F8B  9467 	C$fuzzy.h$3042$1_0$139 ==.
                           002F8B  9468 	XG$fuzzy_rules_defuzzify_method$0$0 ==.
      003048 22               [24] 9469 	ret
                                   9470 ;------------------------------------------------------------
                                   9471 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify'
                                   9472 ;------------------------------------------------------------
                                   9473 ;lower         Allocated to stack - _bp -6 +4 
                                   9474 ;upper         Allocated to stack - _bp -10 +4 
                                   9475 ;step          Allocated to stack - _bp -14 +4 
                                   9476 ;method        Allocated to stack - _bp -15 +1 
                                   9477 ;rules         Allocated to registers r5 r6 r7 
                                   9478 ;------------------------------------------------------------
                           002F8C  9479 	G$fuzzy_rules_defuzzify$0$0 ==.
                           002F8C  9480 	C$fuzzy.h$3049$1_0$143 ==.
                                   9481 ;	../../fuzzy.h:3049: float fuzzy_rules_defuzzify(
                                   9482 ;	-----------------------------------------
                                   9483 ;	 function fuzzy_rules_defuzzify
                                   9484 ;	-----------------------------------------
      003049                       9485 _fuzzy_rules_defuzzify:
      003049 C0 08            [24] 9486 	push	_bp
      00304B 85 81 08         [24] 9487 	mov	_bp,sp
      00304E AD 82            [24] 9488 	mov	r5, dpl
      003050 AE 83            [24] 9489 	mov	r6, dph
      003052 AF F0            [24] 9490 	mov	r7, b
                           002F97  9491 	C$fuzzy.h$3058$1_0$143 ==.
                                   9492 ;	../../fuzzy.h:3058: rules,
      003054 E4               [12] 9493 	clr	a
      003055 C0 E0            [24] 9494 	push	acc
      003057 C0 E0            [24] 9495 	push	acc
      003059 E5 08            [12] 9496 	mov	a,_bp
      00305B 24 F1            [12] 9497 	add	a,#0xf1
      00305D F8               [12] 9498 	mov	r0,a
      00305E E6               [12] 9499 	mov	a,@r0
      00305F C0 E0            [24] 9500 	push	acc
      003061 E5 08            [12] 9501 	mov	a,_bp
      003063 24 F2            [12] 9502 	add	a,#0xf2
      003065 F8               [12] 9503 	mov	r0,a
      003066 E6               [12] 9504 	mov	a,@r0
      003067 C0 E0            [24] 9505 	push	acc
      003069 08               [12] 9506 	inc	r0
      00306A E6               [12] 9507 	mov	a,@r0
      00306B C0 E0            [24] 9508 	push	acc
      00306D 08               [12] 9509 	inc	r0
      00306E E6               [12] 9510 	mov	a,@r0
      00306F C0 E0            [24] 9511 	push	acc
      003071 08               [12] 9512 	inc	r0
      003072 E6               [12] 9513 	mov	a,@r0
      003073 C0 E0            [24] 9514 	push	acc
      003075 E5 08            [12] 9515 	mov	a,_bp
      003077 24 F6            [12] 9516 	add	a,#0xf6
      003079 F8               [12] 9517 	mov	r0,a
      00307A E6               [12] 9518 	mov	a,@r0
      00307B C0 E0            [24] 9519 	push	acc
      00307D 08               [12] 9520 	inc	r0
      00307E E6               [12] 9521 	mov	a,@r0
      00307F C0 E0            [24] 9522 	push	acc
      003081 08               [12] 9523 	inc	r0
      003082 E6               [12] 9524 	mov	a,@r0
      003083 C0 E0            [24] 9525 	push	acc
      003085 08               [12] 9526 	inc	r0
      003086 E6               [12] 9527 	mov	a,@r0
      003087 C0 E0            [24] 9528 	push	acc
      003089 E5 08            [12] 9529 	mov	a,_bp
      00308B 24 FA            [12] 9530 	add	a,#0xfa
      00308D F8               [12] 9531 	mov	r0,a
      00308E E6               [12] 9532 	mov	a,@r0
      00308F C0 E0            [24] 9533 	push	acc
      003091 08               [12] 9534 	inc	r0
      003092 E6               [12] 9535 	mov	a,@r0
      003093 C0 E0            [24] 9536 	push	acc
      003095 08               [12] 9537 	inc	r0
      003096 E6               [12] 9538 	mov	a,@r0
      003097 C0 E0            [24] 9539 	push	acc
      003099 08               [12] 9540 	inc	r0
      00309A E6               [12] 9541 	mov	a,@r0
      00309B C0 E0            [24] 9542 	push	acc
      00309D 8D 82            [24] 9543 	mov	dpl, r5
      00309F 8E 83            [24] 9544 	mov	dph, r6
      0030A1 8F F0            [24] 9545 	mov	b, r7
      0030A3 12 2C AA         [24] 9546 	lcall	_fuzzy_rules_defuzzify_method
      0030A6 AC 82            [24] 9547 	mov	r4, dpl
      0030A8 AD 83            [24] 9548 	mov	r5, dph
      0030AA AE F0            [24] 9549 	mov	r6, b
      0030AC FF               [12] 9550 	mov	r7, a
      0030AD E5 81            [12] 9551 	mov	a,sp
      0030AF 24 F1            [12] 9552 	add	a,#0xf1
      0030B1 F5 81            [12] 9553 	mov	sp,a
      0030B3 8C 82            [24] 9554 	mov	dpl, r4
      0030B5 8D 83            [24] 9555 	mov	dph, r5
      0030B7 8E F0            [24] 9556 	mov	b, r6
      0030B9 EF               [12] 9557 	mov	a, r7
                           002FFD  9558 	C$fuzzy.h$3066$1_0$143 ==.
                                   9559 ;	../../fuzzy.h:3066: }
      0030BA D0 08            [24] 9560 	pop	_bp
                           002FFF  9561 	C$fuzzy.h$3066$1_0$143 ==.
                           002FFF  9562 	XG$fuzzy_rules_defuzzify$0$0 ==.
      0030BC 22               [24] 9563 	ret
                                   9564 ;------------------------------------------------------------
                                   9565 ;Allocation info for local variables in function 'fuzzy_rules_cog'
                                   9566 ;------------------------------------------------------------
                                   9567 ;lower         Allocated to stack - _bp -6 +4 
                                   9568 ;upper         Allocated to stack - _bp -10 +4 
                                   9569 ;step          Allocated to stack - _bp -14 +4 
                                   9570 ;rules         Allocated to registers r5 r6 r7 
                                   9571 ;------------------------------------------------------------
                           003000  9572 	G$fuzzy_rules_cog$0$0 ==.
                           003000  9573 	C$fuzzy.h$3072$1_0$145 ==.
                                   9574 ;	../../fuzzy.h:3072: float fuzzy_rules_cog(
                                   9575 ;	-----------------------------------------
                                   9576 ;	 function fuzzy_rules_cog
                                   9577 ;	-----------------------------------------
      0030BD                       9578 _fuzzy_rules_cog:
      0030BD C0 08            [24] 9579 	push	_bp
      0030BF 85 81 08         [24] 9580 	mov	_bp,sp
      0030C2 AD 82            [24] 9581 	mov	r5, dpl
      0030C4 AE 83            [24] 9582 	mov	r6, dph
      0030C6 AF F0            [24] 9583 	mov	r7, b
                           00300B  9584 	C$fuzzy.h$3080$1_0$145 ==.
                                   9585 ;	../../fuzzy.h:3080: rules,
      0030C8 E4               [12] 9586 	clr	a
      0030C9 C0 E0            [24] 9587 	push	acc
      0030CB C0 E0            [24] 9588 	push	acc
      0030CD E5 08            [12] 9589 	mov	a,_bp
      0030CF 24 F2            [12] 9590 	add	a,#0xf2
      0030D1 F8               [12] 9591 	mov	r0,a
      0030D2 E6               [12] 9592 	mov	a,@r0
      0030D3 C0 E0            [24] 9593 	push	acc
      0030D5 08               [12] 9594 	inc	r0
      0030D6 E6               [12] 9595 	mov	a,@r0
      0030D7 C0 E0            [24] 9596 	push	acc
      0030D9 08               [12] 9597 	inc	r0
      0030DA E6               [12] 9598 	mov	a,@r0
      0030DB C0 E0            [24] 9599 	push	acc
      0030DD 08               [12] 9600 	inc	r0
      0030DE E6               [12] 9601 	mov	a,@r0
      0030DF C0 E0            [24] 9602 	push	acc
      0030E1 E5 08            [12] 9603 	mov	a,_bp
      0030E3 24 F6            [12] 9604 	add	a,#0xf6
      0030E5 F8               [12] 9605 	mov	r0,a
      0030E6 E6               [12] 9606 	mov	a,@r0
      0030E7 C0 E0            [24] 9607 	push	acc
      0030E9 08               [12] 9608 	inc	r0
      0030EA E6               [12] 9609 	mov	a,@r0
      0030EB C0 E0            [24] 9610 	push	acc
      0030ED 08               [12] 9611 	inc	r0
      0030EE E6               [12] 9612 	mov	a,@r0
      0030EF C0 E0            [24] 9613 	push	acc
      0030F1 08               [12] 9614 	inc	r0
      0030F2 E6               [12] 9615 	mov	a,@r0
      0030F3 C0 E0            [24] 9616 	push	acc
      0030F5 E5 08            [12] 9617 	mov	a,_bp
      0030F7 24 FA            [12] 9618 	add	a,#0xfa
      0030F9 F8               [12] 9619 	mov	r0,a
      0030FA E6               [12] 9620 	mov	a,@r0
      0030FB C0 E0            [24] 9621 	push	acc
      0030FD 08               [12] 9622 	inc	r0
      0030FE E6               [12] 9623 	mov	a,@r0
      0030FF C0 E0            [24] 9624 	push	acc
      003101 08               [12] 9625 	inc	r0
      003102 E6               [12] 9626 	mov	a,@r0
      003103 C0 E0            [24] 9627 	push	acc
      003105 08               [12] 9628 	inc	r0
      003106 E6               [12] 9629 	mov	a,@r0
      003107 C0 E0            [24] 9630 	push	acc
      003109 8D 82            [24] 9631 	mov	dpl, r5
      00310B 8E 83            [24] 9632 	mov	dph, r6
      00310D 8F F0            [24] 9633 	mov	b, r7
      00310F 12 21 45         [24] 9634 	lcall	_fuzzy_rules_defuzzify_cog
      003112 AC 82            [24] 9635 	mov	r4, dpl
      003114 AD 83            [24] 9636 	mov	r5, dph
      003116 AE F0            [24] 9637 	mov	r6, b
      003118 FF               [12] 9638 	mov	r7, a
      003119 E5 81            [12] 9639 	mov	a,sp
      00311B 24 F2            [12] 9640 	add	a,#0xf2
      00311D F5 81            [12] 9641 	mov	sp,a
      00311F 8C 82            [24] 9642 	mov	dpl, r4
      003121 8D 83            [24] 9643 	mov	dph, r5
      003123 8E F0            [24] 9644 	mov	b, r6
      003125 EF               [12] 9645 	mov	a, r7
                           003069  9646 	C$fuzzy.h$3087$1_0$145 ==.
                                   9647 ;	../../fuzzy.h:3087: }
      003126 D0 08            [24] 9648 	pop	_bp
                           00306B  9649 	C$fuzzy.h$3087$1_0$145 ==.
                           00306B  9650 	XG$fuzzy_rules_cog$0$0 ==.
      003128 22               [24] 9651 	ret
                                   9652 ;------------------------------------------------------------
                                   9653 ;Allocation info for local variables in function 'temperature_low'
                                   9654 ;------------------------------------------------------------
                                   9655 ;value         Allocated to registers r4 r5 r6 r7 
                                   9656 ;------------------------------------------------------------
                           00306C  9657 	Fsugeno_demo$temperature_low$0$0 ==.
                           00306C  9658 	C$sugeno_demo.c$62$1_0$147 ==.
                                   9659 ;	../../sugeno_demo.c:62: static float temperature_low(float value)
                                   9660 ;	-----------------------------------------
                                   9661 ;	 function temperature_low
                                   9662 ;	-----------------------------------------
      003129                       9663 _temperature_low:
      003129 AC 82            [24] 9664 	mov	r4,dpl
      00312B AD 83            [24] 9665 	mov	r5,dph
      00312D AE F0            [24] 9666 	mov	r6,b
      00312F FF               [12] 9667 	mov	r7,a
                           003073  9668 	C$sugeno_demo.c$69$1_0$147 ==.
                                   9669 ;	../../sugeno_demo.c:69: hedges.none
      003130 90 44 6A         [24] 9670 	mov	dptr,#_hedges
      003133 E4               [12] 9671 	clr	a
      003134 93               [24] 9672 	movc	a,@a+dptr
      003135 FB               [12] 9673 	mov	r3,a
                           003079  9674 	C$sugeno_demo.c$65$1_0$147 ==.
                                   9675 ;	../../sugeno_demo.c:65: 15.0f,
      003136 C0 03            [24] 9676 	push	ar3
      003138 E4               [12] 9677 	clr	a
      003139 C0 E0            [24] 9678 	push	acc
      00313B C0 04            [24] 9679 	push	ar4
      00313D C0 05            [24] 9680 	push	ar5
      00313F C0 06            [24] 9681 	push	ar6
      003141 C0 07            [24] 9682 	push	ar7
      003143 C0 E0            [24] 9683 	push	acc
      003145 C0 E0            [24] 9684 	push	acc
      003147 74 20            [12] 9685 	mov	a,#0x20
      003149 C0 E0            [24] 9686 	push	acc
      00314B 74 42            [12] 9687 	mov	a,#0x42
      00314D C0 E0            [24] 9688 	push	acc
      00314F 90 00 00         [24] 9689 	mov	dptr,#0x0000
      003152 75 F0 70         [24] 9690 	mov	b, #0x70
      003155 14               [12] 9691 	dec	a
      003156 12 0A F2         [24] 9692 	lcall	_fuzzy_ramp
      003159 AC 82            [24] 9693 	mov	r4, dpl
      00315B AD 83            [24] 9694 	mov	r5, dph
      00315D AE F0            [24] 9695 	mov	r6, b
      00315F FF               [12] 9696 	mov	r7, a
      003160 E5 81            [12] 9697 	mov	a,sp
      003162 24 F6            [12] 9698 	add	a,#0xf6
      003164 F5 81            [12] 9699 	mov	sp,a
      003166 8C 82            [24] 9700 	mov	dpl, r4
      003168 8D 83            [24] 9701 	mov	dph, r5
      00316A 8E F0            [24] 9702 	mov	b, r6
      00316C EF               [12] 9703 	mov	a, r7
                           0030B0  9704 	C$sugeno_demo.c$71$1_0$147 ==.
                                   9705 ;	../../sugeno_demo.c:71: }
                           0030B0  9706 	C$sugeno_demo.c$71$1_0$147 ==.
                           0030B0  9707 	XFsugeno_demo$temperature_low$0$0 ==.
      00316D 22               [24] 9708 	ret
                                   9709 ;------------------------------------------------------------
                                   9710 ;Allocation info for local variables in function 'temperature_high'
                                   9711 ;------------------------------------------------------------
                                   9712 ;value         Allocated to registers r4 r5 r6 r7 
                                   9713 ;------------------------------------------------------------
                           0030B1  9714 	Fsugeno_demo$temperature_high$0$0 ==.
                           0030B1  9715 	C$sugeno_demo.c$74$1_0$149 ==.
                                   9716 ;	../../sugeno_demo.c:74: static float temperature_high(float value)
                                   9717 ;	-----------------------------------------
                                   9718 ;	 function temperature_high
                                   9719 ;	-----------------------------------------
      00316E                       9720 _temperature_high:
      00316E AC 82            [24] 9721 	mov	r4,dpl
      003170 AD 83            [24] 9722 	mov	r5,dph
      003172 AE F0            [24] 9723 	mov	r6,b
      003174 FF               [12] 9724 	mov	r7,a
                           0030B8  9725 	C$sugeno_demo.c$81$1_0$149 ==.
                                   9726 ;	../../sugeno_demo.c:81: hedges.none
      003175 90 44 6A         [24] 9727 	mov	dptr,#_hedges
      003178 E4               [12] 9728 	clr	a
      003179 93               [24] 9729 	movc	a,@a+dptr
      00317A FB               [12] 9730 	mov	r3,a
                           0030BE  9731 	C$sugeno_demo.c$77$1_0$149 ==.
                                   9732 ;	../../sugeno_demo.c:77: 35.0f,
      00317B C0 03            [24] 9733 	push	ar3
      00317D 74 01            [12] 9734 	mov	a,#0x01
      00317F C0 E0            [24] 9735 	push	acc
      003181 C0 04            [24] 9736 	push	ar4
      003183 C0 05            [24] 9737 	push	ar5
      003185 C0 06            [24] 9738 	push	ar6
      003187 C0 07            [24] 9739 	push	ar7
      003189 E4               [12] 9740 	clr	a
      00318A C0 E0            [24] 9741 	push	acc
      00318C C0 E0            [24] 9742 	push	acc
      00318E 74 96            [12] 9743 	mov	a,#0x96
      003190 C0 E0            [24] 9744 	push	acc
      003192 74 42            [12] 9745 	mov	a,#0x42
      003194 C0 E0            [24] 9746 	push	acc
      003196 90 00 00         [24] 9747 	mov	dptr,#0x0000
      003199 75 F0 0C         [24] 9748 	mov	b, #0x0c
      00319C 12 0A F2         [24] 9749 	lcall	_fuzzy_ramp
      00319F AC 82            [24] 9750 	mov	r4, dpl
      0031A1 AD 83            [24] 9751 	mov	r5, dph
      0031A3 AE F0            [24] 9752 	mov	r6, b
      0031A5 FF               [12] 9753 	mov	r7, a
      0031A6 E5 81            [12] 9754 	mov	a,sp
      0031A8 24 F6            [12] 9755 	add	a,#0xf6
      0031AA F5 81            [12] 9756 	mov	sp,a
      0031AC 8C 82            [24] 9757 	mov	dpl, r4
      0031AE 8D 83            [24] 9758 	mov	dph, r5
      0031B0 8E F0            [24] 9759 	mov	b, r6
      0031B2 EF               [12] 9760 	mov	a, r7
                           0030F6  9761 	C$sugeno_demo.c$83$1_0$149 ==.
                                   9762 ;	../../sugeno_demo.c:83: }
                           0030F6  9763 	C$sugeno_demo.c$83$1_0$149 ==.
                           0030F6  9764 	XFsugeno_demo$temperature_high$0$0 ==.
      0031B3 22               [24] 9765 	ret
                                   9766 ;------------------------------------------------------------
                                   9767 ;Allocation info for local variables in function 'load_low'
                                   9768 ;------------------------------------------------------------
                                   9769 ;value         Allocated to registers r4 r5 r6 r7 
                                   9770 ;------------------------------------------------------------
                           0030F7  9771 	Fsugeno_demo$load_low$0$0 ==.
                           0030F7  9772 	C$sugeno_demo.c$90$1_0$151 ==.
                                   9773 ;	../../sugeno_demo.c:90: static float load_low(float value)
                                   9774 ;	-----------------------------------------
                                   9775 ;	 function load_low
                                   9776 ;	-----------------------------------------
      0031B4                       9777 _load_low:
      0031B4 AC 82            [24] 9778 	mov	r4,dpl
      0031B6 AD 83            [24] 9779 	mov	r5,dph
      0031B8 AE F0            [24] 9780 	mov	r6,b
      0031BA FF               [12] 9781 	mov	r7,a
                           0030FE  9782 	C$sugeno_demo.c$97$1_0$151 ==.
                                   9783 ;	../../sugeno_demo.c:97: hedges.none
      0031BB 90 44 6A         [24] 9784 	mov	dptr,#_hedges
      0031BE E4               [12] 9785 	clr	a
      0031BF 93               [24] 9786 	movc	a,@a+dptr
      0031C0 FB               [12] 9787 	mov	r3,a
                           003104  9788 	C$sugeno_demo.c$93$1_0$151 ==.
                                   9789 ;	../../sugeno_demo.c:93: 20.0f,
      0031C1 C0 03            [24] 9790 	push	ar3
      0031C3 E4               [12] 9791 	clr	a
      0031C4 C0 E0            [24] 9792 	push	acc
      0031C6 C0 04            [24] 9793 	push	ar4
      0031C8 C0 05            [24] 9794 	push	ar5
      0031CA C0 06            [24] 9795 	push	ar6
      0031CC C0 07            [24] 9796 	push	ar7
      0031CE C0 E0            [24] 9797 	push	acc
      0031D0 C0 E0            [24] 9798 	push	acc
      0031D2 74 48            [12] 9799 	mov	a,#0x48
      0031D4 C0 E0            [24] 9800 	push	acc
      0031D6 74 42            [12] 9801 	mov	a,#0x42
      0031D8 C0 E0            [24] 9802 	push	acc
      0031DA 90 00 00         [24] 9803 	mov	dptr,#0x0000
      0031DD 75 F0 A0         [24] 9804 	mov	b, #0xa0
      0031E0 14               [12] 9805 	dec	a
      0031E1 12 0A F2         [24] 9806 	lcall	_fuzzy_ramp
      0031E4 AC 82            [24] 9807 	mov	r4, dpl
      0031E6 AD 83            [24] 9808 	mov	r5, dph
      0031E8 AE F0            [24] 9809 	mov	r6, b
      0031EA FF               [12] 9810 	mov	r7, a
      0031EB E5 81            [12] 9811 	mov	a,sp
      0031ED 24 F6            [12] 9812 	add	a,#0xf6
      0031EF F5 81            [12] 9813 	mov	sp,a
      0031F1 8C 82            [24] 9814 	mov	dpl, r4
      0031F3 8D 83            [24] 9815 	mov	dph, r5
      0031F5 8E F0            [24] 9816 	mov	b, r6
      0031F7 EF               [12] 9817 	mov	a, r7
                           00313B  9818 	C$sugeno_demo.c$99$1_0$151 ==.
                                   9819 ;	../../sugeno_demo.c:99: }
                           00313B  9820 	C$sugeno_demo.c$99$1_0$151 ==.
                           00313B  9821 	XFsugeno_demo$load_low$0$0 ==.
      0031F8 22               [24] 9822 	ret
                                   9823 ;------------------------------------------------------------
                                   9824 ;Allocation info for local variables in function 'load_high'
                                   9825 ;------------------------------------------------------------
                                   9826 ;value         Allocated to registers r4 r5 r6 r7 
                                   9827 ;------------------------------------------------------------
                           00313C  9828 	Fsugeno_demo$load_high$0$0 ==.
                           00313C  9829 	C$sugeno_demo.c$102$1_0$153 ==.
                                   9830 ;	../../sugeno_demo.c:102: static float load_high(float value)
                                   9831 ;	-----------------------------------------
                                   9832 ;	 function load_high
                                   9833 ;	-----------------------------------------
      0031F9                       9834 _load_high:
      0031F9 AC 82            [24] 9835 	mov	r4,dpl
      0031FB AD 83            [24] 9836 	mov	r5,dph
      0031FD AE F0            [24] 9837 	mov	r6,b
      0031FF FF               [12] 9838 	mov	r7,a
                           003143  9839 	C$sugeno_demo.c$109$1_0$153 ==.
                                   9840 ;	../../sugeno_demo.c:109: hedges.none
      003200 90 44 6A         [24] 9841 	mov	dptr,#_hedges
      003203 E4               [12] 9842 	clr	a
      003204 93               [24] 9843 	movc	a,@a+dptr
      003205 FB               [12] 9844 	mov	r3,a
                           003149  9845 	C$sugeno_demo.c$105$1_0$153 ==.
                                   9846 ;	../../sugeno_demo.c:105: 45.0f,
      003206 C0 03            [24] 9847 	push	ar3
      003208 74 01            [12] 9848 	mov	a,#0x01
      00320A C0 E0            [24] 9849 	push	acc
      00320C C0 04            [24] 9850 	push	ar4
      00320E C0 05            [24] 9851 	push	ar5
      003210 C0 06            [24] 9852 	push	ar6
      003212 C0 07            [24] 9853 	push	ar7
      003214 E4               [12] 9854 	clr	a
      003215 C0 E0            [24] 9855 	push	acc
      003217 C0 E0            [24] 9856 	push	acc
      003219 74 AA            [12] 9857 	mov	a,#0xaa
      00321B C0 E0            [24] 9858 	push	acc
      00321D 74 42            [12] 9859 	mov	a,#0x42
      00321F C0 E0            [24] 9860 	push	acc
      003221 90 00 00         [24] 9861 	mov	dptr,#0x0000
      003224 75 F0 34         [24] 9862 	mov	b, #0x34
      003227 12 0A F2         [24] 9863 	lcall	_fuzzy_ramp
      00322A AC 82            [24] 9864 	mov	r4, dpl
      00322C AD 83            [24] 9865 	mov	r5, dph
      00322E AE F0            [24] 9866 	mov	r6, b
      003230 FF               [12] 9867 	mov	r7, a
      003231 E5 81            [12] 9868 	mov	a,sp
      003233 24 F6            [12] 9869 	add	a,#0xf6
      003235 F5 81            [12] 9870 	mov	sp,a
      003237 8C 82            [24] 9871 	mov	dpl, r4
      003239 8D 83            [24] 9872 	mov	dph, r5
      00323B 8E F0            [24] 9873 	mov	b, r6
      00323D EF               [12] 9874 	mov	a, r7
                           003181  9875 	C$sugeno_demo.c$111$1_0$153 ==.
                                   9876 ;	../../sugeno_demo.c:111: }
                           003181  9877 	C$sugeno_demo.c$111$1_0$153 ==.
                           003181  9878 	XFsugeno_demo$load_high$0$0 ==.
      00323E 22               [24] 9879 	ret
                                   9880 ;------------------------------------------------------------
                                   9881 ;Allocation info for local variables in function 'vibration_low'
                                   9882 ;------------------------------------------------------------
                                   9883 ;value         Allocated to registers r4 r5 r6 r7 
                                   9884 ;------------------------------------------------------------
                           003182  9885 	Fsugeno_demo$vibration_low$0$0 ==.
                           003182  9886 	C$sugeno_demo.c$118$1_0$155 ==.
                                   9887 ;	../../sugeno_demo.c:118: static float vibration_low(float value)
                                   9888 ;	-----------------------------------------
                                   9889 ;	 function vibration_low
                                   9890 ;	-----------------------------------------
      00323F                       9891 _vibration_low:
      00323F AC 82            [24] 9892 	mov	r4,dpl
      003241 AD 83            [24] 9893 	mov	r5,dph
      003243 AE F0            [24] 9894 	mov	r6,b
      003245 FF               [12] 9895 	mov	r7,a
                           003189  9896 	C$sugeno_demo.c$125$1_0$155 ==.
                                   9897 ;	../../sugeno_demo.c:125: hedges.none
      003246 90 44 6A         [24] 9898 	mov	dptr,#_hedges
      003249 E4               [12] 9899 	clr	a
      00324A 93               [24] 9900 	movc	a,@a+dptr
      00324B FB               [12] 9901 	mov	r3,a
                           00318F  9902 	C$sugeno_demo.c$121$1_0$155 ==.
                                   9903 ;	../../sugeno_demo.c:121: 1.0f,
      00324C C0 03            [24] 9904 	push	ar3
      00324E E4               [12] 9905 	clr	a
      00324F C0 E0            [24] 9906 	push	acc
      003251 C0 04            [24] 9907 	push	ar4
      003253 C0 05            [24] 9908 	push	ar5
      003255 C0 06            [24] 9909 	push	ar6
      003257 C0 07            [24] 9910 	push	ar7
      003259 C0 E0            [24] 9911 	push	acc
      00325B C0 E0            [24] 9912 	push	acc
      00325D 74 80            [12] 9913 	mov	a,#0x80
      00325F C0 E0            [24] 9914 	push	acc
      003261 03               [12] 9915 	rr	a
      003262 C0 E0            [24] 9916 	push	acc
      003264 90 00 00         [24] 9917 	mov	dptr,#0x0000
      003267 75 F0 80         [24] 9918 	mov	b, #0x80
      00326A 14               [12] 9919 	dec	a
      00326B 12 0A F2         [24] 9920 	lcall	_fuzzy_ramp
      00326E AC 82            [24] 9921 	mov	r4, dpl
      003270 AD 83            [24] 9922 	mov	r5, dph
      003272 AE F0            [24] 9923 	mov	r6, b
      003274 FF               [12] 9924 	mov	r7, a
      003275 E5 81            [12] 9925 	mov	a,sp
      003277 24 F6            [12] 9926 	add	a,#0xf6
      003279 F5 81            [12] 9927 	mov	sp,a
      00327B 8C 82            [24] 9928 	mov	dpl, r4
      00327D 8D 83            [24] 9929 	mov	dph, r5
      00327F 8E F0            [24] 9930 	mov	b, r6
      003281 EF               [12] 9931 	mov	a, r7
                           0031C5  9932 	C$sugeno_demo.c$127$1_0$155 ==.
                                   9933 ;	../../sugeno_demo.c:127: }
                           0031C5  9934 	C$sugeno_demo.c$127$1_0$155 ==.
                           0031C5  9935 	XFsugeno_demo$vibration_low$0$0 ==.
      003282 22               [24] 9936 	ret
                                   9937 ;------------------------------------------------------------
                                   9938 ;Allocation info for local variables in function 'vibration_high'
                                   9939 ;------------------------------------------------------------
                                   9940 ;value         Allocated to registers r4 r5 r6 r7 
                                   9941 ;------------------------------------------------------------
                           0031C6  9942 	Fsugeno_demo$vibration_high$0$0 ==.
                           0031C6  9943 	C$sugeno_demo.c$130$1_0$157 ==.
                                   9944 ;	../../sugeno_demo.c:130: static float vibration_high(float value)
                                   9945 ;	-----------------------------------------
                                   9946 ;	 function vibration_high
                                   9947 ;	-----------------------------------------
      003283                       9948 _vibration_high:
      003283 AC 82            [24] 9949 	mov	r4,dpl
      003285 AD 83            [24] 9950 	mov	r5,dph
      003287 AE F0            [24] 9951 	mov	r6,b
      003289 FF               [12] 9952 	mov	r7,a
                           0031CD  9953 	C$sugeno_demo.c$137$1_0$157 ==.
                                   9954 ;	../../sugeno_demo.c:137: hedges.none
      00328A 90 44 6A         [24] 9955 	mov	dptr,#_hedges
      00328D E4               [12] 9956 	clr	a
      00328E 93               [24] 9957 	movc	a,@a+dptr
      00328F FB               [12] 9958 	mov	r3,a
                           0031D3  9959 	C$sugeno_demo.c$133$1_0$157 ==.
                                   9960 ;	../../sugeno_demo.c:133: 3.0f,
      003290 C0 03            [24] 9961 	push	ar3
      003292 74 01            [12] 9962 	mov	a,#0x01
      003294 C0 E0            [24] 9963 	push	acc
      003296 C0 04            [24] 9964 	push	ar4
      003298 C0 05            [24] 9965 	push	ar5
      00329A C0 06            [24] 9966 	push	ar6
      00329C C0 07            [24] 9967 	push	ar7
      00329E E4               [12] 9968 	clr	a
      00329F C0 E0            [24] 9969 	push	acc
      0032A1 C0 E0            [24] 9970 	push	acc
      0032A3 C0 E0            [24] 9971 	push	acc
      0032A5 74 41            [12] 9972 	mov	a,#0x41
      0032A7 C0 E0            [24] 9973 	push	acc
      0032A9 90 00 00         [24] 9974 	mov	dptr,#0x0000
      0032AC 75 F0 40         [24] 9975 	mov	b, #0x40
      0032AF 14               [12] 9976 	dec	a
      0032B0 12 0A F2         [24] 9977 	lcall	_fuzzy_ramp
      0032B3 AC 82            [24] 9978 	mov	r4, dpl
      0032B5 AD 83            [24] 9979 	mov	r5, dph
      0032B7 AE F0            [24] 9980 	mov	r6, b
      0032B9 FF               [12] 9981 	mov	r7, a
      0032BA E5 81            [12] 9982 	mov	a,sp
      0032BC 24 F6            [12] 9983 	add	a,#0xf6
      0032BE F5 81            [12] 9984 	mov	sp,a
      0032C0 8C 82            [24] 9985 	mov	dpl, r4
      0032C2 8D 83            [24] 9986 	mov	dph, r5
      0032C4 8E F0            [24] 9987 	mov	b, r6
      0032C6 EF               [12] 9988 	mov	a, r7
                           00320A  9989 	C$sugeno_demo.c$139$1_0$157 ==.
                                   9990 ;	../../sugeno_demo.c:139: }
                           00320A  9991 	C$sugeno_demo.c$139$1_0$157 ==.
                           00320A  9992 	XFsugeno_demo$vibration_high$0$0 ==.
      0032C7 22               [24] 9993 	ret
                                   9994 ;------------------------------------------------------------
                                   9995 ;Allocation info for local variables in function 'response_idle'
                                   9996 ;------------------------------------------------------------
                                   9997 ;load          Allocated to stack - _bp -6 +4 
                                   9998 ;vibration     Allocated to stack - _bp -10 +4 
                                   9999 ;temperature   Allocated to registers r4 r5 r6 r7 
                                  10000 ;sloc0         Allocated to stack - _bp +1 +4 
                                  10001 ;------------------------------------------------------------
                           00320B 10002 	Fsugeno_demo$response_idle$0$0 ==.
                           00320B 10003 	C$sugeno_demo.c$146$1_0$159 ==.
                                  10004 ;	../../sugeno_demo.c:146: static float response_idle(
                                  10005 ;	-----------------------------------------
                                  10006 ;	 function response_idle
                                  10007 ;	-----------------------------------------
      0032C8                      10008 _response_idle:
      0032C8 C0 08            [24]10009 	push	_bp
      0032CA 85 81 08         [24]10010 	mov	_bp,sp
      0032CD AC 82            [24]10011 	mov	r4,dpl
      0032CF AD 83            [24]10012 	mov	r5,dph
      0032D1 AE F0            [24]10013 	mov	r6,b
      0032D3 FF               [12]10014 	mov	r7,a
      0032D4 E5 81            [12]10015 	mov	a,sp
      0032D6 24 04            [12]10016 	add	a,#0x04
      0032D8 F5 81            [12]10017 	mov	sp,a
                           00321D 10018 	C$sugeno_demo.c$154$1_0$159 ==.
                                  10019 ;	../../sugeno_demo.c:154: 0.20f * temperature +
      0032DA C0 04            [24]10020 	push	ar4
      0032DC C0 05            [24]10021 	push	ar5
      0032DE C0 06            [24]10022 	push	ar6
      0032E0 C0 07            [24]10023 	push	ar7
      0032E2 90 CC CD         [24]10024 	mov	dptr,#0xcccd
      0032E5 75 F0 4C         [24]10025 	mov	b, #0x4c
      0032E8 74 3E            [12]10026 	mov	a, #0x3e
      0032EA 12 40 4C         [24]10027 	lcall	___fsmul
      0032ED AC 82            [24]10028 	mov	r4, dpl
      0032EF AD 83            [24]10029 	mov	r5, dph
      0032F1 AE F0            [24]10030 	mov	r6, b
      0032F3 FF               [12]10031 	mov	r7, a
      0032F4 E5 81            [12]10032 	mov	a,sp
      0032F6 24 FC            [12]10033 	add	a,#0xfc
      0032F8 F5 81            [12]10034 	mov	sp,a
      0032FA E4               [12]10035 	clr	a
      0032FB C0 E0            [24]10036 	push	acc
      0032FD C0 E0            [24]10037 	push	acc
      0032FF C0 E0            [24]10038 	push	acc
      003301 74 41            [12]10039 	mov	a,#0x41
      003303 C0 E0            [24]10040 	push	acc
                           003248 10041 	C$sugeno_demo.c$155$1_0$159 ==.
                                  10042 ;	../../sugeno_demo.c:155: 0.08f * load +
      003305 8C 82            [24]10043 	mov	dpl, r4
      003307 8D 83            [24]10044 	mov	dph, r5
      003309 8E F0            [24]10045 	mov	b, r6
      00330B EF               [12]10046 	mov	a, r7
      00330C 12 41 CE         [24]10047 	lcall	___fsadd
      00330F A8 08            [24]10048 	mov	r0,_bp
      003311 08               [12]10049 	inc	r0
      003312 A6 82            [24]10050 	mov	@r0, dpl
      003314 08               [12]10051 	inc	r0
      003315 A6 83            [24]10052 	mov	@r0, dph
      003317 08               [12]10053 	inc	r0
      003318 A6 F0            [24]10054 	mov	@r0, b
      00331A 08               [12]10055 	inc	r0
      00331B F6               [12]10056 	mov	@r0,a
      00331C E5 81            [12]10057 	mov	a,sp
      00331E 24 FC            [12]10058 	add	a,#0xfc
      003320 F5 81            [12]10059 	mov	sp,a
      003322 E5 08            [12]10060 	mov	a,_bp
      003324 24 FA            [12]10061 	add	a,#0xfa
      003326 F8               [12]10062 	mov	r0,a
      003327 E6               [12]10063 	mov	a,@r0
      003328 C0 E0            [24]10064 	push	acc
      00332A 08               [12]10065 	inc	r0
      00332B E6               [12]10066 	mov	a,@r0
      00332C C0 E0            [24]10067 	push	acc
      00332E 08               [12]10068 	inc	r0
      00332F E6               [12]10069 	mov	a,@r0
      003330 C0 E0            [24]10070 	push	acc
      003332 08               [12]10071 	inc	r0
      003333 E6               [12]10072 	mov	a,@r0
      003334 C0 E0            [24]10073 	push	acc
      003336 90 D7 0A         [24]10074 	mov	dptr,#0xd70a
      003339 75 F0 A3         [24]10075 	mov	b, #0xa3
      00333C 74 3D            [12]10076 	mov	a, #0x3d
      00333E 12 40 4C         [24]10077 	lcall	___fsmul
      003341 AA 82            [24]10078 	mov	r2, dpl
      003343 AB 83            [24]10079 	mov	r3, dph
      003345 AE F0            [24]10080 	mov	r6, b
      003347 FF               [12]10081 	mov	r7, a
      003348 E5 81            [12]10082 	mov	a,sp
      00334A 24 FC            [12]10083 	add	a,#0xfc
      00334C F5 81            [12]10084 	mov	sp,a
      00334E C0 02            [24]10085 	push	ar2
      003350 C0 03            [24]10086 	push	ar3
      003352 C0 06            [24]10087 	push	ar6
      003354 C0 07            [24]10088 	push	ar7
                           003299 10089 	C$sugeno_demo.c$156$1_0$159 ==.
                                  10090 ;	../../sugeno_demo.c:156: 0.50f * vibration;
      003356 A8 08            [24]10091 	mov	r0,_bp
      003358 08               [12]10092 	inc	r0
      003359 86 82            [24]10093 	mov	dpl, @r0
      00335B 08               [12]10094 	inc	r0
      00335C 86 83            [24]10095 	mov	dph, @r0
      00335E 08               [12]10096 	inc	r0
      00335F 86 F0            [24]10097 	mov	b, @r0
      003361 08               [12]10098 	inc	r0
      003362 E6               [12]10099 	mov	a, @r0
      003363 12 41 CE         [24]10100 	lcall	___fsadd
      003366 A8 08            [24]10101 	mov	r0,_bp
      003368 08               [12]10102 	inc	r0
      003369 A6 82            [24]10103 	mov	@r0, dpl
      00336B 08               [12]10104 	inc	r0
      00336C A6 83            [24]10105 	mov	@r0, dph
      00336E 08               [12]10106 	inc	r0
      00336F A6 F0            [24]10107 	mov	@r0, b
      003371 08               [12]10108 	inc	r0
      003372 F6               [12]10109 	mov	@r0,a
      003373 E5 81            [12]10110 	mov	a,sp
      003375 24 FC            [12]10111 	add	a,#0xfc
      003377 F5 81            [12]10112 	mov	sp,a
      003379 E5 08            [12]10113 	mov	a,_bp
      00337B 24 F6            [12]10114 	add	a,#0xf6
      00337D F8               [12]10115 	mov	r0,a
      00337E E6               [12]10116 	mov	a,@r0
      00337F C0 E0            [24]10117 	push	acc
      003381 08               [12]10118 	inc	r0
      003382 E6               [12]10119 	mov	a,@r0
      003383 C0 E0            [24]10120 	push	acc
      003385 08               [12]10121 	inc	r0
      003386 E6               [12]10122 	mov	a,@r0
      003387 C0 E0            [24]10123 	push	acc
      003389 08               [12]10124 	inc	r0
      00338A E6               [12]10125 	mov	a,@r0
      00338B C0 E0            [24]10126 	push	acc
      00338D 90 00 00         [24]10127 	mov	dptr,#(0x00&0x00ff)
      003390 E4               [12]10128 	clr	a
      003391 F5 F0            [12]10129 	mov	b,a
      003393 74 3F            [12]10130 	mov	a,#0x3f
      003395 12 40 4C         [24]10131 	lcall	___fsmul
      003398 AA 82            [24]10132 	mov	r2, dpl
      00339A AB 83            [24]10133 	mov	r3, dph
      00339C AE F0            [24]10134 	mov	r6, b
      00339E FF               [12]10135 	mov	r7, a
      00339F E5 81            [12]10136 	mov	a,sp
      0033A1 24 FC            [12]10137 	add	a,#0xfc
      0033A3 F5 81            [12]10138 	mov	sp,a
      0033A5 C0 02            [24]10139 	push	ar2
      0033A7 C0 03            [24]10140 	push	ar3
      0033A9 C0 06            [24]10141 	push	ar6
      0033AB C0 07            [24]10142 	push	ar7
      0033AD A8 08            [24]10143 	mov	r0,_bp
      0033AF 08               [12]10144 	inc	r0
      0033B0 86 82            [24]10145 	mov	dpl, @r0
      0033B2 08               [12]10146 	inc	r0
      0033B3 86 83            [24]10147 	mov	dph, @r0
      0033B5 08               [12]10148 	inc	r0
      0033B6 86 F0            [24]10149 	mov	b, @r0
      0033B8 08               [12]10150 	inc	r0
      0033B9 E6               [12]10151 	mov	a, @r0
      0033BA 12 41 CE         [24]10152 	lcall	___fsadd
      0033BD AC 82            [24]10153 	mov	r4, dpl
      0033BF AD 83            [24]10154 	mov	r5, dph
      0033C1 AE F0            [24]10155 	mov	r6, b
      0033C3 FF               [12]10156 	mov	r7, a
      0033C4 E5 81            [12]10157 	mov	a,sp
      0033C6 24 FC            [12]10158 	add	a,#0xfc
      0033C8 F5 81            [12]10159 	mov	sp,a
      0033CA 8C 82            [24]10160 	mov	dpl, r4
      0033CC 8D 83            [24]10161 	mov	dph, r5
      0033CE 8E F0            [24]10162 	mov	b, r6
      0033D0 EF               [12]10163 	mov	a, r7
                           003314 10164 	C$sugeno_demo.c$157$1_0$159 ==.
                                  10165 ;	../../sugeno_demo.c:157: }
      0033D1 85 08 81         [24]10166 	mov	sp,_bp
      0033D4 D0 08            [24]10167 	pop	_bp
                           003319 10168 	C$sugeno_demo.c$157$1_0$159 ==.
                           003319 10169 	XFsugeno_demo$response_idle$0$0 ==.
      0033D6 22               [24]10170 	ret
                                  10171 ;------------------------------------------------------------
                                  10172 ;Allocation info for local variables in function 'response_economy'
                                  10173 ;------------------------------------------------------------
                                  10174 ;load          Allocated to stack - _bp -6 +4 
                                  10175 ;vibration     Allocated to stack - _bp -10 +4 
                                  10176 ;temperature   Allocated to registers r4 r5 r6 r7 
                                  10177 ;sloc0         Allocated to stack - _bp +1 +4 
                                  10178 ;------------------------------------------------------------
                           00331A 10179 	Fsugeno_demo$response_economy$0$0 ==.
                           00331A 10180 	C$sugeno_demo.c$160$1_0$161 ==.
                                  10181 ;	../../sugeno_demo.c:160: static float response_economy(
                                  10182 ;	-----------------------------------------
                                  10183 ;	 function response_economy
                                  10184 ;	-----------------------------------------
      0033D7                      10185 _response_economy:
      0033D7 C0 08            [24]10186 	push	_bp
      0033D9 85 81 08         [24]10187 	mov	_bp,sp
      0033DC AC 82            [24]10188 	mov	r4,dpl
      0033DE AD 83            [24]10189 	mov	r5,dph
      0033E0 AE F0            [24]10190 	mov	r6,b
      0033E2 FF               [12]10191 	mov	r7,a
      0033E3 E5 81            [12]10192 	mov	a,sp
      0033E5 24 04            [12]10193 	add	a,#0x04
      0033E7 F5 81            [12]10194 	mov	sp,a
                           00332C 10195 	C$sugeno_demo.c$168$1_0$161 ==.
                                  10196 ;	../../sugeno_demo.c:168: 0.30f * temperature +
      0033E9 C0 04            [24]10197 	push	ar4
      0033EB C0 05            [24]10198 	push	ar5
      0033ED C0 06            [24]10199 	push	ar6
      0033EF C0 07            [24]10200 	push	ar7
      0033F1 90 99 9A         [24]10201 	mov	dptr,#0x999a
      0033F4 75 F0 99         [24]10202 	mov	b, #0x99
      0033F7 74 3E            [12]10203 	mov	a, #0x3e
      0033F9 12 40 4C         [24]10204 	lcall	___fsmul
      0033FC AC 82            [24]10205 	mov	r4, dpl
      0033FE AD 83            [24]10206 	mov	r5, dph
      003400 AE F0            [24]10207 	mov	r6, b
      003402 FF               [12]10208 	mov	r7, a
      003403 E5 81            [12]10209 	mov	a,sp
      003405 24 FC            [12]10210 	add	a,#0xfc
      003407 F5 81            [12]10211 	mov	sp,a
      003409 E4               [12]10212 	clr	a
      00340A C0 E0            [24]10213 	push	acc
      00340C C0 E0            [24]10214 	push	acc
      00340E 74 40            [12]10215 	mov	a,#0x40
      003410 C0 E0            [24]10216 	push	acc
      003412 04               [12]10217 	inc	a
      003413 C0 E0            [24]10218 	push	acc
                           003358 10219 	C$sugeno_demo.c$169$1_0$161 ==.
                                  10220 ;	../../sugeno_demo.c:169: 0.18f * load +
      003415 8C 82            [24]10221 	mov	dpl, r4
      003417 8D 83            [24]10222 	mov	dph, r5
      003419 8E F0            [24]10223 	mov	b, r6
      00341B EF               [12]10224 	mov	a, r7
      00341C 12 41 CE         [24]10225 	lcall	___fsadd
      00341F A8 08            [24]10226 	mov	r0,_bp
      003421 08               [12]10227 	inc	r0
      003422 A6 82            [24]10228 	mov	@r0, dpl
      003424 08               [12]10229 	inc	r0
      003425 A6 83            [24]10230 	mov	@r0, dph
      003427 08               [12]10231 	inc	r0
      003428 A6 F0            [24]10232 	mov	@r0, b
      00342A 08               [12]10233 	inc	r0
      00342B F6               [12]10234 	mov	@r0,a
      00342C E5 81            [12]10235 	mov	a,sp
      00342E 24 FC            [12]10236 	add	a,#0xfc
      003430 F5 81            [12]10237 	mov	sp,a
      003432 E5 08            [12]10238 	mov	a,_bp
      003434 24 FA            [12]10239 	add	a,#0xfa
      003436 F8               [12]10240 	mov	r0,a
      003437 E6               [12]10241 	mov	a,@r0
      003438 C0 E0            [24]10242 	push	acc
      00343A 08               [12]10243 	inc	r0
      00343B E6               [12]10244 	mov	a,@r0
      00343C C0 E0            [24]10245 	push	acc
      00343E 08               [12]10246 	inc	r0
      00343F E6               [12]10247 	mov	a,@r0
      003440 C0 E0            [24]10248 	push	acc
      003442 08               [12]10249 	inc	r0
      003443 E6               [12]10250 	mov	a,@r0
      003444 C0 E0            [24]10251 	push	acc
      003446 90 51 EC         [24]10252 	mov	dptr,#0x51ec
      003449 75 F0 38         [24]10253 	mov	b, #0x38
      00344C 74 3E            [12]10254 	mov	a, #0x3e
      00344E 12 40 4C         [24]10255 	lcall	___fsmul
      003451 AA 82            [24]10256 	mov	r2, dpl
      003453 AB 83            [24]10257 	mov	r3, dph
      003455 AE F0            [24]10258 	mov	r6, b
      003457 FF               [12]10259 	mov	r7, a
      003458 E5 81            [12]10260 	mov	a,sp
      00345A 24 FC            [12]10261 	add	a,#0xfc
      00345C F5 81            [12]10262 	mov	sp,a
      00345E C0 02            [24]10263 	push	ar2
      003460 C0 03            [24]10264 	push	ar3
      003462 C0 06            [24]10265 	push	ar6
      003464 C0 07            [24]10266 	push	ar7
                           0033A9 10267 	C$sugeno_demo.c$170$1_0$161 ==.
                                  10268 ;	../../sugeno_demo.c:170: 0.80f * vibration;
      003466 A8 08            [24]10269 	mov	r0,_bp
      003468 08               [12]10270 	inc	r0
      003469 86 82            [24]10271 	mov	dpl, @r0
      00346B 08               [12]10272 	inc	r0
      00346C 86 83            [24]10273 	mov	dph, @r0
      00346E 08               [12]10274 	inc	r0
      00346F 86 F0            [24]10275 	mov	b, @r0
      003471 08               [12]10276 	inc	r0
      003472 E6               [12]10277 	mov	a, @r0
      003473 12 41 CE         [24]10278 	lcall	___fsadd
      003476 A8 08            [24]10279 	mov	r0,_bp
      003478 08               [12]10280 	inc	r0
      003479 A6 82            [24]10281 	mov	@r0, dpl
      00347B 08               [12]10282 	inc	r0
      00347C A6 83            [24]10283 	mov	@r0, dph
      00347E 08               [12]10284 	inc	r0
      00347F A6 F0            [24]10285 	mov	@r0, b
      003481 08               [12]10286 	inc	r0
      003482 F6               [12]10287 	mov	@r0,a
      003483 E5 81            [12]10288 	mov	a,sp
      003485 24 FC            [12]10289 	add	a,#0xfc
      003487 F5 81            [12]10290 	mov	sp,a
      003489 E5 08            [12]10291 	mov	a,_bp
      00348B 24 F6            [12]10292 	add	a,#0xf6
      00348D F8               [12]10293 	mov	r0,a
      00348E E6               [12]10294 	mov	a,@r0
      00348F C0 E0            [24]10295 	push	acc
      003491 08               [12]10296 	inc	r0
      003492 E6               [12]10297 	mov	a,@r0
      003493 C0 E0            [24]10298 	push	acc
      003495 08               [12]10299 	inc	r0
      003496 E6               [12]10300 	mov	a,@r0
      003497 C0 E0            [24]10301 	push	acc
      003499 08               [12]10302 	inc	r0
      00349A E6               [12]10303 	mov	a,@r0
      00349B C0 E0            [24]10304 	push	acc
      00349D 90 CC CD         [24]10305 	mov	dptr,#0xcccd
      0034A0 75 F0 4C         [24]10306 	mov	b, #0x4c
      0034A3 74 3F            [12]10307 	mov	a, #0x3f
      0034A5 12 40 4C         [24]10308 	lcall	___fsmul
      0034A8 AA 82            [24]10309 	mov	r2, dpl
      0034AA AB 83            [24]10310 	mov	r3, dph
      0034AC AE F0            [24]10311 	mov	r6, b
      0034AE FF               [12]10312 	mov	r7, a
      0034AF E5 81            [12]10313 	mov	a,sp
      0034B1 24 FC            [12]10314 	add	a,#0xfc
      0034B3 F5 81            [12]10315 	mov	sp,a
      0034B5 C0 02            [24]10316 	push	ar2
      0034B7 C0 03            [24]10317 	push	ar3
      0034B9 C0 06            [24]10318 	push	ar6
      0034BB C0 07            [24]10319 	push	ar7
      0034BD A8 08            [24]10320 	mov	r0,_bp
      0034BF 08               [12]10321 	inc	r0
      0034C0 86 82            [24]10322 	mov	dpl, @r0
      0034C2 08               [12]10323 	inc	r0
      0034C3 86 83            [24]10324 	mov	dph, @r0
      0034C5 08               [12]10325 	inc	r0
      0034C6 86 F0            [24]10326 	mov	b, @r0
      0034C8 08               [12]10327 	inc	r0
      0034C9 E6               [12]10328 	mov	a, @r0
      0034CA 12 41 CE         [24]10329 	lcall	___fsadd
      0034CD AC 82            [24]10330 	mov	r4, dpl
      0034CF AD 83            [24]10331 	mov	r5, dph
      0034D1 AE F0            [24]10332 	mov	r6, b
      0034D3 FF               [12]10333 	mov	r7, a
      0034D4 E5 81            [12]10334 	mov	a,sp
      0034D6 24 FC            [12]10335 	add	a,#0xfc
      0034D8 F5 81            [12]10336 	mov	sp,a
      0034DA 8C 82            [24]10337 	mov	dpl, r4
      0034DC 8D 83            [24]10338 	mov	dph, r5
      0034DE 8E F0            [24]10339 	mov	b, r6
      0034E0 EF               [12]10340 	mov	a, r7
                           003424 10341 	C$sugeno_demo.c$171$1_0$161 ==.
                                  10342 ;	../../sugeno_demo.c:171: }
      0034E1 85 08 81         [24]10343 	mov	sp,_bp
      0034E4 D0 08            [24]10344 	pop	_bp
                           003429 10345 	C$sugeno_demo.c$171$1_0$161 ==.
                           003429 10346 	XFsugeno_demo$response_economy$0$0 ==.
      0034E6 22               [24]10347 	ret
                                  10348 ;------------------------------------------------------------
                                  10349 ;Allocation info for local variables in function 'response_balanced'
                                  10350 ;------------------------------------------------------------
                                  10351 ;load          Allocated to stack - _bp -6 +4 
                                  10352 ;vibration     Allocated to stack - _bp -10 +4 
                                  10353 ;temperature   Allocated to registers r4 r5 r6 r7 
                                  10354 ;sloc0         Allocated to stack - _bp +1 +4 
                                  10355 ;------------------------------------------------------------
                           00342A 10356 	Fsugeno_demo$response_balanced$0$0 ==.
                           00342A 10357 	C$sugeno_demo.c$174$1_0$163 ==.
                                  10358 ;	../../sugeno_demo.c:174: static float response_balanced(
                                  10359 ;	-----------------------------------------
                                  10360 ;	 function response_balanced
                                  10361 ;	-----------------------------------------
      0034E7                      10362 _response_balanced:
      0034E7 C0 08            [24]10363 	push	_bp
      0034E9 85 81 08         [24]10364 	mov	_bp,sp
      0034EC AC 82            [24]10365 	mov	r4,dpl
      0034EE AD 83            [24]10366 	mov	r5,dph
      0034F0 AE F0            [24]10367 	mov	r6,b
      0034F2 FF               [12]10368 	mov	r7,a
      0034F3 E5 81            [12]10369 	mov	a,sp
      0034F5 24 04            [12]10370 	add	a,#0x04
      0034F7 F5 81            [12]10371 	mov	sp,a
                           00343C 10372 	C$sugeno_demo.c$182$1_0$163 ==.
                                  10373 ;	../../sugeno_demo.c:182: 0.42f * temperature +
      0034F9 C0 04            [24]10374 	push	ar4
      0034FB C0 05            [24]10375 	push	ar5
      0034FD C0 06            [24]10376 	push	ar6
      0034FF C0 07            [24]10377 	push	ar7
      003501 90 0A 3D         [24]10378 	mov	dptr,#0x0a3d
      003504 75 F0 D7         [24]10379 	mov	b, #0xd7
      003507 74 3E            [12]10380 	mov	a, #0x3e
      003509 12 40 4C         [24]10381 	lcall	___fsmul
      00350C AC 82            [24]10382 	mov	r4, dpl
      00350E AD 83            [24]10383 	mov	r5, dph
      003510 AE F0            [24]10384 	mov	r6, b
      003512 FF               [12]10385 	mov	r7, a
      003513 E5 81            [12]10386 	mov	a,sp
      003515 24 FC            [12]10387 	add	a,#0xfc
      003517 F5 81            [12]10388 	mov	sp,a
      003519 E4               [12]10389 	clr	a
      00351A C0 E0            [24]10390 	push	acc
      00351C C0 E0            [24]10391 	push	acc
      00351E 74 70            [12]10392 	mov	a,#0x70
      003520 C0 E0            [24]10393 	push	acc
      003522 74 41            [12]10394 	mov	a,#0x41
      003524 C0 E0            [24]10395 	push	acc
                           003469 10396 	C$sugeno_demo.c$183$1_0$163 ==.
                                  10397 ;	../../sugeno_demo.c:183: 0.25f * load +
      003526 8C 82            [24]10398 	mov	dpl, r4
      003528 8D 83            [24]10399 	mov	dph, r5
      00352A 8E F0            [24]10400 	mov	b, r6
      00352C EF               [12]10401 	mov	a, r7
      00352D 12 41 CE         [24]10402 	lcall	___fsadd
      003530 A8 08            [24]10403 	mov	r0,_bp
      003532 08               [12]10404 	inc	r0
      003533 A6 82            [24]10405 	mov	@r0, dpl
      003535 08               [12]10406 	inc	r0
      003536 A6 83            [24]10407 	mov	@r0, dph
      003538 08               [12]10408 	inc	r0
      003539 A6 F0            [24]10409 	mov	@r0, b
      00353B 08               [12]10410 	inc	r0
      00353C F6               [12]10411 	mov	@r0,a
      00353D E5 81            [12]10412 	mov	a,sp
      00353F 24 FC            [12]10413 	add	a,#0xfc
      003541 F5 81            [12]10414 	mov	sp,a
      003543 E5 08            [12]10415 	mov	a,_bp
      003545 24 FA            [12]10416 	add	a,#0xfa
      003547 F8               [12]10417 	mov	r0,a
      003548 E6               [12]10418 	mov	a,@r0
      003549 C0 E0            [24]10419 	push	acc
      00354B 08               [12]10420 	inc	r0
      00354C E6               [12]10421 	mov	a,@r0
      00354D C0 E0            [24]10422 	push	acc
      00354F 08               [12]10423 	inc	r0
      003550 E6               [12]10424 	mov	a,@r0
      003551 C0 E0            [24]10425 	push	acc
      003553 08               [12]10426 	inc	r0
      003554 E6               [12]10427 	mov	a,@r0
      003555 C0 E0            [24]10428 	push	acc
      003557 90 00 00         [24]10429 	mov	dptr,#0x0000
      00355A 75 F0 80         [24]10430 	mov	b, #0x80
      00355D 74 3E            [12]10431 	mov	a, #0x3e
      00355F 12 40 4C         [24]10432 	lcall	___fsmul
      003562 AA 82            [24]10433 	mov	r2, dpl
      003564 AB 83            [24]10434 	mov	r3, dph
      003566 AE F0            [24]10435 	mov	r6, b
      003568 FF               [12]10436 	mov	r7, a
      003569 E5 81            [12]10437 	mov	a,sp
      00356B 24 FC            [12]10438 	add	a,#0xfc
      00356D F5 81            [12]10439 	mov	sp,a
      00356F C0 02            [24]10440 	push	ar2
      003571 C0 03            [24]10441 	push	ar3
      003573 C0 06            [24]10442 	push	ar6
      003575 C0 07            [24]10443 	push	ar7
                           0034BA 10444 	C$sugeno_demo.c$184$1_0$163 ==.
                                  10445 ;	../../sugeno_demo.c:184: 1.20f * vibration;
      003577 A8 08            [24]10446 	mov	r0,_bp
      003579 08               [12]10447 	inc	r0
      00357A 86 82            [24]10448 	mov	dpl, @r0
      00357C 08               [12]10449 	inc	r0
      00357D 86 83            [24]10450 	mov	dph, @r0
      00357F 08               [12]10451 	inc	r0
      003580 86 F0            [24]10452 	mov	b, @r0
      003582 08               [12]10453 	inc	r0
      003583 E6               [12]10454 	mov	a, @r0
      003584 12 41 CE         [24]10455 	lcall	___fsadd
      003587 A8 08            [24]10456 	mov	r0,_bp
      003589 08               [12]10457 	inc	r0
      00358A A6 82            [24]10458 	mov	@r0, dpl
      00358C 08               [12]10459 	inc	r0
      00358D A6 83            [24]10460 	mov	@r0, dph
      00358F 08               [12]10461 	inc	r0
      003590 A6 F0            [24]10462 	mov	@r0, b
      003592 08               [12]10463 	inc	r0
      003593 F6               [12]10464 	mov	@r0,a
      003594 E5 81            [12]10465 	mov	a,sp
      003596 24 FC            [12]10466 	add	a,#0xfc
      003598 F5 81            [12]10467 	mov	sp,a
      00359A E5 08            [12]10468 	mov	a,_bp
      00359C 24 F6            [12]10469 	add	a,#0xf6
      00359E F8               [12]10470 	mov	r0,a
      00359F E6               [12]10471 	mov	a,@r0
      0035A0 C0 E0            [24]10472 	push	acc
      0035A2 08               [12]10473 	inc	r0
      0035A3 E6               [12]10474 	mov	a,@r0
      0035A4 C0 E0            [24]10475 	push	acc
      0035A6 08               [12]10476 	inc	r0
      0035A7 E6               [12]10477 	mov	a,@r0
      0035A8 C0 E0            [24]10478 	push	acc
      0035AA 08               [12]10479 	inc	r0
      0035AB E6               [12]10480 	mov	a,@r0
      0035AC C0 E0            [24]10481 	push	acc
      0035AE 90 99 9A         [24]10482 	mov	dptr,#0x999a
      0035B1 75 F0 99         [24]10483 	mov	b, #0x99
      0035B4 74 3F            [12]10484 	mov	a, #0x3f
      0035B6 12 40 4C         [24]10485 	lcall	___fsmul
      0035B9 AA 82            [24]10486 	mov	r2, dpl
      0035BB AB 83            [24]10487 	mov	r3, dph
      0035BD AE F0            [24]10488 	mov	r6, b
      0035BF FF               [12]10489 	mov	r7, a
      0035C0 E5 81            [12]10490 	mov	a,sp
      0035C2 24 FC            [12]10491 	add	a,#0xfc
      0035C4 F5 81            [12]10492 	mov	sp,a
      0035C6 C0 02            [24]10493 	push	ar2
      0035C8 C0 03            [24]10494 	push	ar3
      0035CA C0 06            [24]10495 	push	ar6
      0035CC C0 07            [24]10496 	push	ar7
      0035CE A8 08            [24]10497 	mov	r0,_bp
      0035D0 08               [12]10498 	inc	r0
      0035D1 86 82            [24]10499 	mov	dpl, @r0
      0035D3 08               [12]10500 	inc	r0
      0035D4 86 83            [24]10501 	mov	dph, @r0
      0035D6 08               [12]10502 	inc	r0
      0035D7 86 F0            [24]10503 	mov	b, @r0
      0035D9 08               [12]10504 	inc	r0
      0035DA E6               [12]10505 	mov	a, @r0
      0035DB 12 41 CE         [24]10506 	lcall	___fsadd
      0035DE AC 82            [24]10507 	mov	r4, dpl
      0035E0 AD 83            [24]10508 	mov	r5, dph
      0035E2 AE F0            [24]10509 	mov	r6, b
      0035E4 FF               [12]10510 	mov	r7, a
      0035E5 E5 81            [12]10511 	mov	a,sp
      0035E7 24 FC            [12]10512 	add	a,#0xfc
      0035E9 F5 81            [12]10513 	mov	sp,a
      0035EB 8C 82            [24]10514 	mov	dpl, r4
      0035ED 8D 83            [24]10515 	mov	dph, r5
      0035EF 8E F0            [24]10516 	mov	b, r6
      0035F1 EF               [12]10517 	mov	a, r7
                           003535 10518 	C$sugeno_demo.c$185$1_0$163 ==.
                                  10519 ;	../../sugeno_demo.c:185: }
      0035F2 85 08 81         [24]10520 	mov	sp,_bp
      0035F5 D0 08            [24]10521 	pop	_bp
                           00353A 10522 	C$sugeno_demo.c$185$1_0$163 ==.
                           00353A 10523 	XFsugeno_demo$response_balanced$0$0 ==.
      0035F7 22               [24]10524 	ret
                                  10525 ;------------------------------------------------------------
                                  10526 ;Allocation info for local variables in function 'response_cooling'
                                  10527 ;------------------------------------------------------------
                                  10528 ;load          Allocated to stack - _bp -6 +4 
                                  10529 ;vibration     Allocated to stack - _bp -10 +4 
                                  10530 ;temperature   Allocated to registers r4 r5 r6 r7 
                                  10531 ;sloc0         Allocated to stack - _bp +1 +4 
                                  10532 ;------------------------------------------------------------
                           00353B 10533 	Fsugeno_demo$response_cooling$0$0 ==.
                           00353B 10534 	C$sugeno_demo.c$188$1_0$165 ==.
                                  10535 ;	../../sugeno_demo.c:188: static float response_cooling(
                                  10536 ;	-----------------------------------------
                                  10537 ;	 function response_cooling
                                  10538 ;	-----------------------------------------
      0035F8                      10539 _response_cooling:
      0035F8 C0 08            [24]10540 	push	_bp
      0035FA 85 81 08         [24]10541 	mov	_bp,sp
      0035FD AC 82            [24]10542 	mov	r4,dpl
      0035FF AD 83            [24]10543 	mov	r5,dph
      003601 AE F0            [24]10544 	mov	r6,b
      003603 FF               [12]10545 	mov	r7,a
      003604 E5 81            [12]10546 	mov	a,sp
      003606 24 04            [12]10547 	add	a,#0x04
      003608 F5 81            [12]10548 	mov	sp,a
                           00354D 10549 	C$sugeno_demo.c$196$1_0$165 ==.
                                  10550 ;	../../sugeno_demo.c:196: 0.65f * temperature +
      00360A C0 04            [24]10551 	push	ar4
      00360C C0 05            [24]10552 	push	ar5
      00360E C0 06            [24]10553 	push	ar6
      003610 C0 07            [24]10554 	push	ar7
      003612 90 66 66         [24]10555 	mov	dptr,#0x6666
      003615 75 F0 26         [24]10556 	mov	b, #0x26
      003618 74 3F            [12]10557 	mov	a, #0x3f
      00361A 12 40 4C         [24]10558 	lcall	___fsmul
      00361D AC 82            [24]10559 	mov	r4, dpl
      00361F AD 83            [24]10560 	mov	r5, dph
      003621 AE F0            [24]10561 	mov	r6, b
      003623 FF               [12]10562 	mov	r7, a
      003624 E5 81            [12]10563 	mov	a,sp
      003626 24 FC            [12]10564 	add	a,#0xfc
      003628 F5 81            [12]10565 	mov	sp,a
      00362A E4               [12]10566 	clr	a
      00362B C0 E0            [24]10567 	push	acc
      00362D C0 E0            [24]10568 	push	acc
      00362F 74 A0            [12]10569 	mov	a,#0xa0
      003631 C0 E0            [24]10570 	push	acc
      003633 23               [12]10571 	rl	a
      003634 C0 E0            [24]10572 	push	acc
                           003579 10573 	C$sugeno_demo.c$197$1_0$165 ==.
                                  10574 ;	../../sugeno_demo.c:197: 0.12f * load +
      003636 8C 82            [24]10575 	mov	dpl, r4
      003638 8D 83            [24]10576 	mov	dph, r5
      00363A 8E F0            [24]10577 	mov	b, r6
      00363C EF               [12]10578 	mov	a, r7
      00363D 12 41 CE         [24]10579 	lcall	___fsadd
      003640 A8 08            [24]10580 	mov	r0,_bp
      003642 08               [12]10581 	inc	r0
      003643 A6 82            [24]10582 	mov	@r0, dpl
      003645 08               [12]10583 	inc	r0
      003646 A6 83            [24]10584 	mov	@r0, dph
      003648 08               [12]10585 	inc	r0
      003649 A6 F0            [24]10586 	mov	@r0, b
      00364B 08               [12]10587 	inc	r0
      00364C F6               [12]10588 	mov	@r0,a
      00364D E5 81            [12]10589 	mov	a,sp
      00364F 24 FC            [12]10590 	add	a,#0xfc
      003651 F5 81            [12]10591 	mov	sp,a
      003653 E5 08            [12]10592 	mov	a,_bp
      003655 24 FA            [12]10593 	add	a,#0xfa
      003657 F8               [12]10594 	mov	r0,a
      003658 E6               [12]10595 	mov	a,@r0
      003659 C0 E0            [24]10596 	push	acc
      00365B 08               [12]10597 	inc	r0
      00365C E6               [12]10598 	mov	a,@r0
      00365D C0 E0            [24]10599 	push	acc
      00365F 08               [12]10600 	inc	r0
      003660 E6               [12]10601 	mov	a,@r0
      003661 C0 E0            [24]10602 	push	acc
      003663 08               [12]10603 	inc	r0
      003664 E6               [12]10604 	mov	a,@r0
      003665 C0 E0            [24]10605 	push	acc
      003667 90 C2 8F         [24]10606 	mov	dptr,#0xc28f
      00366A 75 F0 F5         [24]10607 	mov	b, #0xf5
      00366D 74 3D            [12]10608 	mov	a, #0x3d
      00366F 12 40 4C         [24]10609 	lcall	___fsmul
      003672 AA 82            [24]10610 	mov	r2, dpl
      003674 AB 83            [24]10611 	mov	r3, dph
      003676 AE F0            [24]10612 	mov	r6, b
      003678 FF               [12]10613 	mov	r7, a
      003679 E5 81            [12]10614 	mov	a,sp
      00367B 24 FC            [12]10615 	add	a,#0xfc
      00367D F5 81            [12]10616 	mov	sp,a
      00367F C0 02            [24]10617 	push	ar2
      003681 C0 03            [24]10618 	push	ar3
      003683 C0 06            [24]10619 	push	ar6
      003685 C0 07            [24]10620 	push	ar7
                           0035CA 10621 	C$sugeno_demo.c$198$1_0$165 ==.
                                  10622 ;	../../sugeno_demo.c:198: 1.50f * vibration;
      003687 A8 08            [24]10623 	mov	r0,_bp
      003689 08               [12]10624 	inc	r0
      00368A 86 82            [24]10625 	mov	dpl, @r0
      00368C 08               [12]10626 	inc	r0
      00368D 86 83            [24]10627 	mov	dph, @r0
      00368F 08               [12]10628 	inc	r0
      003690 86 F0            [24]10629 	mov	b, @r0
      003692 08               [12]10630 	inc	r0
      003693 E6               [12]10631 	mov	a, @r0
      003694 12 41 CE         [24]10632 	lcall	___fsadd
      003697 A8 08            [24]10633 	mov	r0,_bp
      003699 08               [12]10634 	inc	r0
      00369A A6 82            [24]10635 	mov	@r0, dpl
      00369C 08               [12]10636 	inc	r0
      00369D A6 83            [24]10637 	mov	@r0, dph
      00369F 08               [12]10638 	inc	r0
      0036A0 A6 F0            [24]10639 	mov	@r0, b
      0036A2 08               [12]10640 	inc	r0
      0036A3 F6               [12]10641 	mov	@r0,a
      0036A4 E5 81            [12]10642 	mov	a,sp
      0036A6 24 FC            [12]10643 	add	a,#0xfc
      0036A8 F5 81            [12]10644 	mov	sp,a
      0036AA E5 08            [12]10645 	mov	a,_bp
      0036AC 24 F6            [12]10646 	add	a,#0xf6
      0036AE F8               [12]10647 	mov	r0,a
      0036AF E6               [12]10648 	mov	a,@r0
      0036B0 C0 E0            [24]10649 	push	acc
      0036B2 08               [12]10650 	inc	r0
      0036B3 E6               [12]10651 	mov	a,@r0
      0036B4 C0 E0            [24]10652 	push	acc
      0036B6 08               [12]10653 	inc	r0
      0036B7 E6               [12]10654 	mov	a,@r0
      0036B8 C0 E0            [24]10655 	push	acc
      0036BA 08               [12]10656 	inc	r0
      0036BB E6               [12]10657 	mov	a,@r0
      0036BC C0 E0            [24]10658 	push	acc
      0036BE 90 00 00         [24]10659 	mov	dptr,#0x0000
      0036C1 75 F0 C0         [24]10660 	mov	b, #0xc0
      0036C4 74 3F            [12]10661 	mov	a, #0x3f
      0036C6 12 40 4C         [24]10662 	lcall	___fsmul
      0036C9 AA 82            [24]10663 	mov	r2, dpl
      0036CB AB 83            [24]10664 	mov	r3, dph
      0036CD AE F0            [24]10665 	mov	r6, b
      0036CF FF               [12]10666 	mov	r7, a
      0036D0 E5 81            [12]10667 	mov	a,sp
      0036D2 24 FC            [12]10668 	add	a,#0xfc
      0036D4 F5 81            [12]10669 	mov	sp,a
      0036D6 C0 02            [24]10670 	push	ar2
      0036D8 C0 03            [24]10671 	push	ar3
      0036DA C0 06            [24]10672 	push	ar6
      0036DC C0 07            [24]10673 	push	ar7
      0036DE A8 08            [24]10674 	mov	r0,_bp
      0036E0 08               [12]10675 	inc	r0
      0036E1 86 82            [24]10676 	mov	dpl, @r0
      0036E3 08               [12]10677 	inc	r0
      0036E4 86 83            [24]10678 	mov	dph, @r0
      0036E6 08               [12]10679 	inc	r0
      0036E7 86 F0            [24]10680 	mov	b, @r0
      0036E9 08               [12]10681 	inc	r0
      0036EA E6               [12]10682 	mov	a, @r0
      0036EB 12 41 CE         [24]10683 	lcall	___fsadd
      0036EE AC 82            [24]10684 	mov	r4, dpl
      0036F0 AD 83            [24]10685 	mov	r5, dph
      0036F2 AE F0            [24]10686 	mov	r6, b
      0036F4 FF               [12]10687 	mov	r7, a
      0036F5 E5 81            [12]10688 	mov	a,sp
      0036F7 24 FC            [12]10689 	add	a,#0xfc
      0036F9 F5 81            [12]10690 	mov	sp,a
      0036FB 8C 82            [24]10691 	mov	dpl, r4
      0036FD 8D 83            [24]10692 	mov	dph, r5
      0036FF 8E F0            [24]10693 	mov	b, r6
      003701 EF               [12]10694 	mov	a, r7
                           003645 10695 	C$sugeno_demo.c$199$1_0$165 ==.
                                  10696 ;	../../sugeno_demo.c:199: }
      003702 85 08 81         [24]10697 	mov	sp,_bp
      003705 D0 08            [24]10698 	pop	_bp
                           00364A 10699 	C$sugeno_demo.c$199$1_0$165 ==.
                           00364A 10700 	XFsugeno_demo$response_cooling$0$0 ==.
      003707 22               [24]10701 	ret
                                  10702 ;------------------------------------------------------------
                                  10703 ;Allocation info for local variables in function 'response_heavy_load'
                                  10704 ;------------------------------------------------------------
                                  10705 ;load          Allocated to stack - _bp -6 +4 
                                  10706 ;vibration     Allocated to stack - _bp -10 +4 
                                  10707 ;temperature   Allocated to registers r4 r5 r6 r7 
                                  10708 ;sloc0         Allocated to stack - _bp +1 +4 
                                  10709 ;------------------------------------------------------------
                           00364B 10710 	Fsugeno_demo$response_heavy_load$0$0 ==.
                           00364B 10711 	C$sugeno_demo.c$202$1_0$167 ==.
                                  10712 ;	../../sugeno_demo.c:202: static float response_heavy_load(
                                  10713 ;	-----------------------------------------
                                  10714 ;	 function response_heavy_load
                                  10715 ;	-----------------------------------------
      003708                      10716 _response_heavy_load:
      003708 C0 08            [24]10717 	push	_bp
      00370A 85 81 08         [24]10718 	mov	_bp,sp
      00370D AC 82            [24]10719 	mov	r4,dpl
      00370F AD 83            [24]10720 	mov	r5,dph
      003711 AE F0            [24]10721 	mov	r6,b
      003713 FF               [12]10722 	mov	r7,a
      003714 E5 81            [12]10723 	mov	a,sp
      003716 24 04            [12]10724 	add	a,#0x04
      003718 F5 81            [12]10725 	mov	sp,a
                           00365D 10726 	C$sugeno_demo.c$210$1_0$167 ==.
                                  10727 ;	../../sugeno_demo.c:210: 0.30f * temperature +
      00371A C0 04            [24]10728 	push	ar4
      00371C C0 05            [24]10729 	push	ar5
      00371E C0 06            [24]10730 	push	ar6
      003720 C0 07            [24]10731 	push	ar7
      003722 90 99 9A         [24]10732 	mov	dptr,#0x999a
      003725 75 F0 99         [24]10733 	mov	b, #0x99
      003728 74 3E            [12]10734 	mov	a, #0x3e
      00372A 12 40 4C         [24]10735 	lcall	___fsmul
      00372D AC 82            [24]10736 	mov	r4, dpl
      00372F AD 83            [24]10737 	mov	r5, dph
      003731 AE F0            [24]10738 	mov	r6, b
      003733 FF               [12]10739 	mov	r7, a
      003734 E5 81            [12]10740 	mov	a,sp
      003736 24 FC            [12]10741 	add	a,#0xfc
      003738 F5 81            [12]10742 	mov	sp,a
      00373A E4               [12]10743 	clr	a
      00373B C0 E0            [24]10744 	push	acc
      00373D C0 E0            [24]10745 	push	acc
      00373F 74 90            [12]10746 	mov	a,#0x90
      003741 C0 E0            [24]10747 	push	acc
      003743 74 41            [12]10748 	mov	a,#0x41
      003745 C0 E0            [24]10749 	push	acc
                           00368A 10750 	C$sugeno_demo.c$211$1_0$167 ==.
                                  10751 ;	../../sugeno_demo.c:211: 0.55f * load +
      003747 8C 82            [24]10752 	mov	dpl, r4
      003749 8D 83            [24]10753 	mov	dph, r5
      00374B 8E F0            [24]10754 	mov	b, r6
      00374D EF               [12]10755 	mov	a, r7
      00374E 12 41 CE         [24]10756 	lcall	___fsadd
      003751 A8 08            [24]10757 	mov	r0,_bp
      003753 08               [12]10758 	inc	r0
      003754 A6 82            [24]10759 	mov	@r0, dpl
      003756 08               [12]10760 	inc	r0
      003757 A6 83            [24]10761 	mov	@r0, dph
      003759 08               [12]10762 	inc	r0
      00375A A6 F0            [24]10763 	mov	@r0, b
      00375C 08               [12]10764 	inc	r0
      00375D F6               [12]10765 	mov	@r0,a
      00375E E5 81            [12]10766 	mov	a,sp
      003760 24 FC            [12]10767 	add	a,#0xfc
      003762 F5 81            [12]10768 	mov	sp,a
      003764 E5 08            [12]10769 	mov	a,_bp
      003766 24 FA            [12]10770 	add	a,#0xfa
      003768 F8               [12]10771 	mov	r0,a
      003769 E6               [12]10772 	mov	a,@r0
      00376A C0 E0            [24]10773 	push	acc
      00376C 08               [12]10774 	inc	r0
      00376D E6               [12]10775 	mov	a,@r0
      00376E C0 E0            [24]10776 	push	acc
      003770 08               [12]10777 	inc	r0
      003771 E6               [12]10778 	mov	a,@r0
      003772 C0 E0            [24]10779 	push	acc
      003774 08               [12]10780 	inc	r0
      003775 E6               [12]10781 	mov	a,@r0
      003776 C0 E0            [24]10782 	push	acc
      003778 90 CC CD         [24]10783 	mov	dptr,#0xcccd
      00377B 75 F0 0C         [24]10784 	mov	b, #0x0c
      00377E 74 3F            [12]10785 	mov	a, #0x3f
      003780 12 40 4C         [24]10786 	lcall	___fsmul
      003783 AA 82            [24]10787 	mov	r2, dpl
      003785 AB 83            [24]10788 	mov	r3, dph
      003787 AE F0            [24]10789 	mov	r6, b
      003789 FF               [12]10790 	mov	r7, a
      00378A E5 81            [12]10791 	mov	a,sp
      00378C 24 FC            [12]10792 	add	a,#0xfc
      00378E F5 81            [12]10793 	mov	sp,a
      003790 C0 02            [24]10794 	push	ar2
      003792 C0 03            [24]10795 	push	ar3
      003794 C0 06            [24]10796 	push	ar6
      003796 C0 07            [24]10797 	push	ar7
                           0036DB 10798 	C$sugeno_demo.c$212$1_0$167 ==.
                                  10799 ;	../../sugeno_demo.c:212: 1.00f * vibration;
      003798 A8 08            [24]10800 	mov	r0,_bp
      00379A 08               [12]10801 	inc	r0
      00379B 86 82            [24]10802 	mov	dpl, @r0
      00379D 08               [12]10803 	inc	r0
      00379E 86 83            [24]10804 	mov	dph, @r0
      0037A0 08               [12]10805 	inc	r0
      0037A1 86 F0            [24]10806 	mov	b, @r0
      0037A3 08               [12]10807 	inc	r0
      0037A4 E6               [12]10808 	mov	a, @r0
      0037A5 12 41 CE         [24]10809 	lcall	___fsadd
      0037A8 AC 82            [24]10810 	mov	r4, dpl
      0037AA AD 83            [24]10811 	mov	r5, dph
      0037AC AE F0            [24]10812 	mov	r6, b
      0037AE FF               [12]10813 	mov	r7, a
      0037AF E5 81            [12]10814 	mov	a,sp
      0037B1 24 FC            [12]10815 	add	a,#0xfc
      0037B3 F5 81            [12]10816 	mov	sp,a
      0037B5 E5 08            [12]10817 	mov	a,_bp
      0037B7 24 F6            [12]10818 	add	a,#0xf6
      0037B9 F8               [12]10819 	mov	r0,a
      0037BA E6               [12]10820 	mov	a,@r0
      0037BB C0 E0            [24]10821 	push	acc
      0037BD 08               [12]10822 	inc	r0
      0037BE E6               [12]10823 	mov	a,@r0
      0037BF C0 E0            [24]10824 	push	acc
      0037C1 08               [12]10825 	inc	r0
      0037C2 E6               [12]10826 	mov	a,@r0
      0037C3 C0 E0            [24]10827 	push	acc
      0037C5 08               [12]10828 	inc	r0
      0037C6 E6               [12]10829 	mov	a,@r0
      0037C7 C0 E0            [24]10830 	push	acc
      0037C9 8C 82            [24]10831 	mov	dpl, r4
      0037CB 8D 83            [24]10832 	mov	dph, r5
      0037CD 8E F0            [24]10833 	mov	b, r6
      0037CF EF               [12]10834 	mov	a, r7
      0037D0 12 41 CE         [24]10835 	lcall	___fsadd
      0037D3 AC 82            [24]10836 	mov	r4, dpl
      0037D5 AD 83            [24]10837 	mov	r5, dph
      0037D7 AE F0            [24]10838 	mov	r6, b
      0037D9 FF               [12]10839 	mov	r7, a
      0037DA E5 81            [12]10840 	mov	a,sp
      0037DC 24 FC            [12]10841 	add	a,#0xfc
      0037DE F5 81            [12]10842 	mov	sp,a
      0037E0 8C 82            [24]10843 	mov	dpl, r4
      0037E2 8D 83            [24]10844 	mov	dph, r5
      0037E4 8E F0            [24]10845 	mov	b, r6
      0037E6 EF               [12]10846 	mov	a, r7
                           00372A 10847 	C$sugeno_demo.c$213$1_0$167 ==.
                                  10848 ;	../../sugeno_demo.c:213: }
      0037E7 85 08 81         [24]10849 	mov	sp,_bp
      0037EA D0 08            [24]10850 	pop	_bp
                           00372F 10851 	C$sugeno_demo.c$213$1_0$167 ==.
                           00372F 10852 	XFsugeno_demo$response_heavy_load$0$0 ==.
      0037EC 22               [24]10853 	ret
                                  10854 ;------------------------------------------------------------
                                  10855 ;Allocation info for local variables in function 'response_protection'
                                  10856 ;------------------------------------------------------------
                                  10857 ;load          Allocated to stack - _bp -6 +4 
                                  10858 ;vibration     Allocated to stack - _bp -10 +4 
                                  10859 ;temperature   Allocated to registers r4 r5 r6 r7 
                                  10860 ;sloc0         Allocated to stack - _bp +1 +4 
                                  10861 ;------------------------------------------------------------
                           003730 10862 	Fsugeno_demo$response_protection$0$0 ==.
                           003730 10863 	C$sugeno_demo.c$216$1_0$169 ==.
                                  10864 ;	../../sugeno_demo.c:216: static float response_protection(
                                  10865 ;	-----------------------------------------
                                  10866 ;	 function response_protection
                                  10867 ;	-----------------------------------------
      0037ED                      10868 _response_protection:
      0037ED C0 08            [24]10869 	push	_bp
      0037EF 85 81 08         [24]10870 	mov	_bp,sp
      0037F2 AC 82            [24]10871 	mov	r4,dpl
      0037F4 AD 83            [24]10872 	mov	r5,dph
      0037F6 AE F0            [24]10873 	mov	r6,b
      0037F8 FF               [12]10874 	mov	r7,a
      0037F9 E5 81            [12]10875 	mov	a,sp
      0037FB 24 04            [12]10876 	add	a,#0x04
      0037FD F5 81            [12]10877 	mov	sp,a
                           003742 10878 	C$sugeno_demo.c$224$1_0$169 ==.
                                  10879 ;	../../sugeno_demo.c:224: 0.45f * temperature +
      0037FF C0 04            [24]10880 	push	ar4
      003801 C0 05            [24]10881 	push	ar5
      003803 C0 06            [24]10882 	push	ar6
      003805 C0 07            [24]10883 	push	ar7
      003807 90 66 66         [24]10884 	mov	dptr,#0x6666
      00380A 75 F0 E6         [24]10885 	mov	b, #0xe6
      00380D 74 3E            [12]10886 	mov	a, #0x3e
      00380F 12 40 4C         [24]10887 	lcall	___fsmul
      003812 AC 82            [24]10888 	mov	r4, dpl
      003814 AD 83            [24]10889 	mov	r5, dph
      003816 AE F0            [24]10890 	mov	r6, b
      003818 FF               [12]10891 	mov	r7, a
      003819 E5 81            [12]10892 	mov	a,sp
      00381B 24 FC            [12]10893 	add	a,#0xfc
      00381D F5 81            [12]10894 	mov	sp,a
      00381F E4               [12]10895 	clr	a
      003820 C0 E0            [24]10896 	push	acc
      003822 C0 E0            [24]10897 	push	acc
      003824 74 0C            [12]10898 	mov	a,#0x0c
      003826 C0 E0            [24]10899 	push	acc
      003828 74 42            [12]10900 	mov	a,#0x42
      00382A C0 E0            [24]10901 	push	acc
                           00376F 10902 	C$sugeno_demo.c$225$1_0$169 ==.
                                  10903 ;	../../sugeno_demo.c:225: 0.30f * load +
      00382C 8C 82            [24]10904 	mov	dpl, r4
      00382E 8D 83            [24]10905 	mov	dph, r5
      003830 8E F0            [24]10906 	mov	b, r6
      003832 EF               [12]10907 	mov	a, r7
      003833 12 41 CE         [24]10908 	lcall	___fsadd
      003836 A8 08            [24]10909 	mov	r0,_bp
      003838 08               [12]10910 	inc	r0
      003839 A6 82            [24]10911 	mov	@r0, dpl
      00383B 08               [12]10912 	inc	r0
      00383C A6 83            [24]10913 	mov	@r0, dph
      00383E 08               [12]10914 	inc	r0
      00383F A6 F0            [24]10915 	mov	@r0, b
      003841 08               [12]10916 	inc	r0
      003842 F6               [12]10917 	mov	@r0,a
      003843 E5 81            [12]10918 	mov	a,sp
      003845 24 FC            [12]10919 	add	a,#0xfc
      003847 F5 81            [12]10920 	mov	sp,a
      003849 E5 08            [12]10921 	mov	a,_bp
      00384B 24 FA            [12]10922 	add	a,#0xfa
      00384D F8               [12]10923 	mov	r0,a
      00384E E6               [12]10924 	mov	a,@r0
      00384F C0 E0            [24]10925 	push	acc
      003851 08               [12]10926 	inc	r0
      003852 E6               [12]10927 	mov	a,@r0
      003853 C0 E0            [24]10928 	push	acc
      003855 08               [12]10929 	inc	r0
      003856 E6               [12]10930 	mov	a,@r0
      003857 C0 E0            [24]10931 	push	acc
      003859 08               [12]10932 	inc	r0
      00385A E6               [12]10933 	mov	a,@r0
      00385B C0 E0            [24]10934 	push	acc
      00385D 90 99 9A         [24]10935 	mov	dptr,#0x999a
      003860 75 F0 99         [24]10936 	mov	b, #0x99
      003863 74 3E            [12]10937 	mov	a, #0x3e
      003865 12 40 4C         [24]10938 	lcall	___fsmul
      003868 AA 82            [24]10939 	mov	r2, dpl
      00386A AB 83            [24]10940 	mov	r3, dph
      00386C AE F0            [24]10941 	mov	r6, b
      00386E FF               [12]10942 	mov	r7, a
      00386F E5 81            [12]10943 	mov	a,sp
      003871 24 FC            [12]10944 	add	a,#0xfc
      003873 F5 81            [12]10945 	mov	sp,a
      003875 C0 02            [24]10946 	push	ar2
      003877 C0 03            [24]10947 	push	ar3
      003879 C0 06            [24]10948 	push	ar6
      00387B C0 07            [24]10949 	push	ar7
                           0037C0 10950 	C$sugeno_demo.c$226$1_0$169 ==.
                                  10951 ;	../../sugeno_demo.c:226: 2.50f * vibration;
      00387D A8 08            [24]10952 	mov	r0,_bp
      00387F 08               [12]10953 	inc	r0
      003880 86 82            [24]10954 	mov	dpl, @r0
      003882 08               [12]10955 	inc	r0
      003883 86 83            [24]10956 	mov	dph, @r0
      003885 08               [12]10957 	inc	r0
      003886 86 F0            [24]10958 	mov	b, @r0
      003888 08               [12]10959 	inc	r0
      003889 E6               [12]10960 	mov	a, @r0
      00388A 12 41 CE         [24]10961 	lcall	___fsadd
      00388D A8 08            [24]10962 	mov	r0,_bp
      00388F 08               [12]10963 	inc	r0
      003890 A6 82            [24]10964 	mov	@r0, dpl
      003892 08               [12]10965 	inc	r0
      003893 A6 83            [24]10966 	mov	@r0, dph
      003895 08               [12]10967 	inc	r0
      003896 A6 F0            [24]10968 	mov	@r0, b
      003898 08               [12]10969 	inc	r0
      003899 F6               [12]10970 	mov	@r0,a
      00389A E5 81            [12]10971 	mov	a,sp
      00389C 24 FC            [12]10972 	add	a,#0xfc
      00389E F5 81            [12]10973 	mov	sp,a
      0038A0 E5 08            [12]10974 	mov	a,_bp
      0038A2 24 F6            [12]10975 	add	a,#0xf6
      0038A4 F8               [12]10976 	mov	r0,a
      0038A5 E6               [12]10977 	mov	a,@r0
      0038A6 C0 E0            [24]10978 	push	acc
      0038A8 08               [12]10979 	inc	r0
      0038A9 E6               [12]10980 	mov	a,@r0
      0038AA C0 E0            [24]10981 	push	acc
      0038AC 08               [12]10982 	inc	r0
      0038AD E6               [12]10983 	mov	a,@r0
      0038AE C0 E0            [24]10984 	push	acc
      0038B0 08               [12]10985 	inc	r0
      0038B1 E6               [12]10986 	mov	a,@r0
      0038B2 C0 E0            [24]10987 	push	acc
      0038B4 90 00 00         [24]10988 	mov	dptr,#0x0000
      0038B7 75 F0 20         [24]10989 	mov	b, #0x20
      0038BA 74 40            [12]10990 	mov	a, #0x40
      0038BC 12 40 4C         [24]10991 	lcall	___fsmul
      0038BF AA 82            [24]10992 	mov	r2, dpl
      0038C1 AB 83            [24]10993 	mov	r3, dph
      0038C3 AE F0            [24]10994 	mov	r6, b
      0038C5 FF               [12]10995 	mov	r7, a
      0038C6 E5 81            [12]10996 	mov	a,sp
      0038C8 24 FC            [12]10997 	add	a,#0xfc
      0038CA F5 81            [12]10998 	mov	sp,a
      0038CC C0 02            [24]10999 	push	ar2
      0038CE C0 03            [24]11000 	push	ar3
      0038D0 C0 06            [24]11001 	push	ar6
      0038D2 C0 07            [24]11002 	push	ar7
      0038D4 A8 08            [24]11003 	mov	r0,_bp
      0038D6 08               [12]11004 	inc	r0
      0038D7 86 82            [24]11005 	mov	dpl, @r0
      0038D9 08               [12]11006 	inc	r0
      0038DA 86 83            [24]11007 	mov	dph, @r0
      0038DC 08               [12]11008 	inc	r0
      0038DD 86 F0            [24]11009 	mov	b, @r0
      0038DF 08               [12]11010 	inc	r0
      0038E0 E6               [12]11011 	mov	a, @r0
      0038E1 12 41 CE         [24]11012 	lcall	___fsadd
      0038E4 AC 82            [24]11013 	mov	r4, dpl
      0038E6 AD 83            [24]11014 	mov	r5, dph
      0038E8 AE F0            [24]11015 	mov	r6, b
      0038EA FF               [12]11016 	mov	r7, a
      0038EB E5 81            [12]11017 	mov	a,sp
      0038ED 24 FC            [12]11018 	add	a,#0xfc
      0038EF F5 81            [12]11019 	mov	sp,a
      0038F1 8C 82            [24]11020 	mov	dpl, r4
      0038F3 8D 83            [24]11021 	mov	dph, r5
      0038F5 8E F0            [24]11022 	mov	b, r6
      0038F7 EF               [12]11023 	mov	a, r7
                           00383B 11024 	C$sugeno_demo.c$227$1_0$169 ==.
                                  11025 ;	../../sugeno_demo.c:227: }
      0038F8 85 08 81         [24]11026 	mov	sp,_bp
      0038FB D0 08            [24]11027 	pop	_bp
                           003840 11028 	C$sugeno_demo.c$227$1_0$169 ==.
                           003840 11029 	XFsugeno_demo$response_protection$0$0 ==.
      0038FD 22               [24]11030 	ret
                                  11031 ;------------------------------------------------------------
                                  11032 ;Allocation info for local variables in function 'calculate_fan_speed'
                                  11033 ;------------------------------------------------------------
                                  11034 ;load          Allocated to stack - _bp -6 +4 
                                  11035 ;vibration     Allocated to stack - _bp -10 +4 
                                  11036 ;temperature   Allocated to stack - _bp +1 +4 
                                  11037 ;temperature_low_value Allocated to registers r7 r6 r5 r4 
                                  11038 ;temperature_high_value Allocated to stack - _bp +5 +4 
                                  11039 ;load_low_value Allocated to stack - _bp +9 +4 
                                  11040 ;load_high_value Allocated to stack - _bp +13 +4 
                                  11041 ;vibration_low_value Allocated to stack - _bp +17 +4 
                                  11042 ;vibration_high_value Allocated to stack - _bp +21 +4 
                                  11043 ;rule1         Allocated to stack - _bp +25 +4 
                                  11044 ;rule2         Allocated to stack - _bp +29 +4 
                                  11045 ;rule3         Allocated to stack - _bp +33 +4 
                                  11046 ;rule4         Allocated to stack - _bp +37 +4 
                                  11047 ;rule5         Allocated to stack - _bp +41 +4 
                                  11048 ;rule6         Allocated to stack - _bp +45 +4 
                                  11049 ;rule6_thermal Allocated to stack - _bp +49 +4 
                                  11050 ;rule6_mechanical Allocated to registers r4 r5 r6 r7 
                                  11051 ;------------------------------------------------------------
                           003841 11052 	Fsugeno_demo$calculate_fan_speed$0$0 ==.
                           003841 11053 	C$sugeno_demo.c$254$1_0$171 ==.
                                  11054 ;	../../sugeno_demo.c:254: static float calculate_fan_speed(
                                  11055 ;	-----------------------------------------
                                  11056 ;	 function calculate_fan_speed
                                  11057 ;	-----------------------------------------
      0038FE                      11058 _calculate_fan_speed:
      0038FE C0 08            [24]11059 	push	_bp
      003900 85 81 08         [24]11060 	mov	_bp,sp
      003903 C0 82            [24]11061 	push	dpl
      003905 C0 83            [24]11062 	push	dph
      003907 C0 F0            [24]11063 	push	b
      003909 C0 E0            [24]11064 	push	acc
      00390B E5 81            [12]11065 	mov	a,sp
      00390D 24 30            [12]11066 	add	a,#0x30
      00390F F5 81            [12]11067 	mov	sp,a
                           003854 11068 	C$sugeno_demo.c$281$1_0$171 ==.
                                  11069 ;	../../sugeno_demo.c:281: temperature
      003911 A8 08            [24]11070 	mov	r0,_bp
      003913 08               [12]11071 	inc	r0
      003914 86 82            [24]11072 	mov	dpl, @r0
      003916 08               [12]11073 	inc	r0
      003917 86 83            [24]11074 	mov	dph, @r0
      003919 08               [12]11075 	inc	r0
      00391A 86 F0            [24]11076 	mov	b, @r0
      00391C 08               [12]11077 	inc	r0
      00391D E6               [12]11078 	mov	a, @r0
      00391E 12 31 29         [24]11079 	lcall	_temperature_low
      003921 AF 82            [24]11080 	mov	r7, dpl
      003923 AE 83            [24]11081 	mov	r6, dph
      003925 AD F0            [24]11082 	mov	r5, b
      003927 FC               [12]11083 	mov	r4, a
                           00386B 11084 	C$sugeno_demo.c$286$1_0$171 ==.
                                  11085 ;	../../sugeno_demo.c:286: temperature
      003928 A8 08            [24]11086 	mov	r0,_bp
      00392A 08               [12]11087 	inc	r0
      00392B 86 82            [24]11088 	mov	dpl, @r0
      00392D 08               [12]11089 	inc	r0
      00392E 86 83            [24]11090 	mov	dph, @r0
      003930 08               [12]11091 	inc	r0
      003931 86 F0            [24]11092 	mov	b, @r0
      003933 08               [12]11093 	inc	r0
      003934 E6               [12]11094 	mov	a, @r0
      003935 C0 07            [24]11095 	push	ar7
      003937 C0 06            [24]11096 	push	ar6
      003939 C0 05            [24]11097 	push	ar5
      00393B C0 04            [24]11098 	push	ar4
      00393D 12 31 6E         [24]11099 	lcall	_temperature_high
      003940 C8               [12]11100 	xch	a,r0
      003941 E5 08            [12]11101 	mov	a,_bp
      003943 24 05            [12]11102 	add	a,#0x05
      003945 C8               [12]11103 	xch	a,r0
      003946 A6 82            [24]11104 	mov	@r0, dpl
      003948 08               [12]11105 	inc	r0
      003949 A6 83            [24]11106 	mov	@r0, dph
      00394B 08               [12]11107 	inc	r0
      00394C A6 F0            [24]11108 	mov	@r0, b
      00394E 08               [12]11109 	inc	r0
      00394F F6               [12]11110 	mov	@r0,a
                           003893 11111 	C$sugeno_demo.c$291$1_0$171 ==.
                                  11112 ;	../../sugeno_demo.c:291: load
      003950 E5 08            [12]11113 	mov	a,_bp
      003952 24 FA            [12]11114 	add	a,#0xfa
      003954 F8               [12]11115 	mov	r0,a
      003955 86 82            [24]11116 	mov	dpl, @r0
      003957 08               [12]11117 	inc	r0
      003958 86 83            [24]11118 	mov	dph, @r0
      00395A 08               [12]11119 	inc	r0
      00395B 86 F0            [24]11120 	mov	b, @r0
      00395D 08               [12]11121 	inc	r0
      00395E E6               [12]11122 	mov	a, @r0
      00395F 12 31 B4         [24]11123 	lcall	_load_low
      003962 C8               [12]11124 	xch	a,r0
      003963 E5 08            [12]11125 	mov	a,_bp
      003965 24 09            [12]11126 	add	a,#0x09
      003967 C8               [12]11127 	xch	a,r0
      003968 A6 82            [24]11128 	mov	@r0, dpl
      00396A 08               [12]11129 	inc	r0
      00396B A6 83            [24]11130 	mov	@r0, dph
      00396D 08               [12]11131 	inc	r0
      00396E A6 F0            [24]11132 	mov	@r0, b
      003970 08               [12]11133 	inc	r0
      003971 F6               [12]11134 	mov	@r0,a
                           0038B5 11135 	C$sugeno_demo.c$296$1_0$171 ==.
                                  11136 ;	../../sugeno_demo.c:296: load
      003972 E5 08            [12]11137 	mov	a,_bp
      003974 24 FA            [12]11138 	add	a,#0xfa
      003976 F8               [12]11139 	mov	r0,a
      003977 86 82            [24]11140 	mov	dpl, @r0
      003979 08               [12]11141 	inc	r0
      00397A 86 83            [24]11142 	mov	dph, @r0
      00397C 08               [12]11143 	inc	r0
      00397D 86 F0            [24]11144 	mov	b, @r0
      00397F 08               [12]11145 	inc	r0
      003980 E6               [12]11146 	mov	a, @r0
      003981 12 31 F9         [24]11147 	lcall	_load_high
      003984 C8               [12]11148 	xch	a,r0
      003985 E5 08            [12]11149 	mov	a,_bp
      003987 24 0D            [12]11150 	add	a,#0x0d
      003989 C8               [12]11151 	xch	a,r0
      00398A A6 82            [24]11152 	mov	@r0, dpl
      00398C 08               [12]11153 	inc	r0
      00398D A6 83            [24]11154 	mov	@r0, dph
      00398F 08               [12]11155 	inc	r0
      003990 A6 F0            [24]11156 	mov	@r0, b
      003992 08               [12]11157 	inc	r0
      003993 F6               [12]11158 	mov	@r0,a
                           0038D7 11159 	C$sugeno_demo.c$301$1_0$171 ==.
                                  11160 ;	../../sugeno_demo.c:301: vibration
      003994 E5 08            [12]11161 	mov	a,_bp
      003996 24 F6            [12]11162 	add	a,#0xf6
      003998 F8               [12]11163 	mov	r0,a
      003999 86 82            [24]11164 	mov	dpl, @r0
      00399B 08               [12]11165 	inc	r0
      00399C 86 83            [24]11166 	mov	dph, @r0
      00399E 08               [12]11167 	inc	r0
      00399F 86 F0            [24]11168 	mov	b, @r0
      0039A1 08               [12]11169 	inc	r0
      0039A2 E6               [12]11170 	mov	a, @r0
      0039A3 12 32 3F         [24]11171 	lcall	_vibration_low
      0039A6 C8               [12]11172 	xch	a,r0
      0039A7 E5 08            [12]11173 	mov	a,_bp
      0039A9 24 11            [12]11174 	add	a,#0x11
      0039AB C8               [12]11175 	xch	a,r0
      0039AC A6 82            [24]11176 	mov	@r0, dpl
      0039AE 08               [12]11177 	inc	r0
      0039AF A6 83            [24]11178 	mov	@r0, dph
      0039B1 08               [12]11179 	inc	r0
      0039B2 A6 F0            [24]11180 	mov	@r0, b
      0039B4 08               [12]11181 	inc	r0
      0039B5 F6               [12]11182 	mov	@r0,a
                           0038F9 11183 	C$sugeno_demo.c$306$1_0$171 ==.
                                  11184 ;	../../sugeno_demo.c:306: vibration
      0039B6 E5 08            [12]11185 	mov	a,_bp
      0039B8 24 F6            [12]11186 	add	a,#0xf6
      0039BA F8               [12]11187 	mov	r0,a
      0039BB 86 82            [24]11188 	mov	dpl, @r0
      0039BD 08               [12]11189 	inc	r0
      0039BE 86 83            [24]11190 	mov	dph, @r0
      0039C0 08               [12]11191 	inc	r0
      0039C1 86 F0            [24]11192 	mov	b, @r0
      0039C3 08               [12]11193 	inc	r0
      0039C4 E6               [12]11194 	mov	a, @r0
      0039C5 12 32 83         [24]11195 	lcall	_vibration_high
      0039C8 C8               [12]11196 	xch	a,r0
      0039C9 E5 08            [12]11197 	mov	a,_bp
      0039CB 24 15            [12]11198 	add	a,#0x15
      0039CD C8               [12]11199 	xch	a,r0
      0039CE A6 82            [24]11200 	mov	@r0, dpl
      0039D0 08               [12]11201 	inc	r0
      0039D1 A6 83            [24]11202 	mov	@r0, dph
      0039D3 08               [12]11203 	inc	r0
      0039D4 A6 F0            [24]11204 	mov	@r0, b
      0039D6 08               [12]11205 	inc	r0
      0039D7 F6               [12]11206 	mov	@r0,a
                           00391B 11207 	C$sugeno_demo.c$310$1_0$171 ==.
                                  11208 ;	../../sugeno_demo.c:310: fuzzy_and_method(
      0039D8 12 00 BD         [24]11209 	lcall	_fuzzy_values_initialize
      0039DB D0 04            [24]11210 	pop	ar4
      0039DD D0 05            [24]11211 	pop	ar5
      0039DF D0 06            [24]11212 	pop	ar6
      0039E1 D0 07            [24]11213 	pop	ar7
      0039E3 8F 21            [24]11214 	mov	(_fuzzy_values_buffer + 0),r7
      0039E5 8E 22            [24]11215 	mov	(_fuzzy_values_buffer + 1),r6
      0039E7 8D 23            [24]11216 	mov	(_fuzzy_values_buffer + 2),r5
      0039E9 8C 24            [24]11217 	mov	(_fuzzy_values_buffer + 3),r4
      0039EB E5 08            [12]11218 	mov	a,_bp
      0039ED 24 09            [12]11219 	add	a,#0x09
      0039EF F8               [12]11220 	mov	r0,a
      0039F0 86 25            [24]11221 	mov	((_fuzzy_values_buffer + 0x0004) + 0),@r0
      0039F2 08               [12]11222 	inc	r0
      0039F3 86 26            [24]11223 	mov	((_fuzzy_values_buffer + 0x0004) + 1),@r0
      0039F5 08               [12]11224 	inc	r0
      0039F6 86 27            [24]11225 	mov	((_fuzzy_values_buffer + 0x0004) + 2),@r0
      0039F8 08               [12]11226 	inc	r0
      0039F9 86 28            [24]11227 	mov	((_fuzzy_values_buffer + 0x0004) + 3),@r0
      0039FB E5 08            [12]11228 	mov	a,_bp
      0039FD 24 11            [12]11229 	add	a,#0x11
      0039FF F8               [12]11230 	mov	r0,a
      003A00 86 29            [24]11231 	mov	((_fuzzy_values_buffer + 0x0008) + 0),@r0
      003A02 08               [12]11232 	inc	r0
      003A03 86 2A            [24]11233 	mov	((_fuzzy_values_buffer + 0x0008) + 1),@r0
      003A05 08               [12]11234 	inc	r0
      003A06 86 2B            [24]11235 	mov	((_fuzzy_values_buffer + 0x0008) + 2),@r0
      003A08 08               [12]11236 	inc	r0
      003A09 86 2C            [24]11237 	mov	((_fuzzy_values_buffer + 0x0008) + 3),@r0
      003A0B 74 21            [12]11238 	mov	a,#_fuzzy_values_buffer
      003A0D C0 E0            [24]11239 	push	acc
      003A0F 74 00            [12]11240 	mov	a,#(_fuzzy_values_buffer >> 8)
      003A11 C0 E0            [24]11241 	push	acc
      003A13 74 40            [12]11242 	mov	a,#0x40
      003A15 C0 E0            [24]11243 	push	acc
      003A17 74 03            [12]11244 	mov	a,#0x03
      003A19 C0 E0            [24]11245 	push	acc
      003A1B E4               [12]11246 	clr	a
      003A1C C0 E0            [24]11247 	push	acc
      003A1E 75 82 00         [24]11248 	mov	dpl, #0x00
      003A21 12 02 29         [24]11249 	lcall	_fuzzy_and_array
      003A24 C8               [12]11250 	xch	a,r0
      003A25 E5 08            [12]11251 	mov	a,_bp
      003A27 24 19            [12]11252 	add	a,#0x19
      003A29 C8               [12]11253 	xch	a,r0
      003A2A A6 82            [24]11254 	mov	@r0, dpl
      003A2C 08               [12]11255 	inc	r0
      003A2D A6 83            [24]11256 	mov	@r0, dph
      003A2F 08               [12]11257 	inc	r0
      003A30 A6 F0            [24]11258 	mov	@r0, b
      003A32 08               [12]11259 	inc	r0
      003A33 F6               [12]11260 	mov	@r0,a
      003A34 E5 81            [12]11261 	mov	a,sp
      003A36 24 FB            [12]11262 	add	a,#0xfb
      003A38 F5 81            [12]11263 	mov	sp,a
                           00397D 11264 	C$sugeno_demo.c$318$1_0$171 ==.
                                  11265 ;	../../sugeno_demo.c:318: fuzzy_and_method(
      003A3A 12 00 BD         [24]11266 	lcall	_fuzzy_values_initialize
      003A3D E5 08            [12]11267 	mov	a,_bp
      003A3F 24 05            [12]11268 	add	a,#0x05
      003A41 F8               [12]11269 	mov	r0,a
      003A42 86 82            [24]11270 	mov	dpl, @r0
      003A44 08               [12]11271 	inc	r0
      003A45 86 83            [24]11272 	mov	dph, @r0
      003A47 08               [12]11273 	inc	r0
      003A48 86 F0            [24]11274 	mov	b, @r0
      003A4A 08               [12]11275 	inc	r0
      003A4B E6               [12]11276 	mov	a, @r0
      003A4C 12 01 6D         [24]11277 	lcall	_fuzzy_not
      003A4F AA 82            [24]11278 	mov	r2, dpl
      003A51 AB 83            [24]11279 	mov	r3, dph
      003A53 AE F0            [24]11280 	mov	r6, b
      003A55 FF               [12]11281 	mov	r7, a
      003A56 8A 21            [24]11282 	mov	(_fuzzy_values_buffer + 0),r2
      003A58 8B 22            [24]11283 	mov	(_fuzzy_values_buffer + 1),r3
      003A5A 8E 23            [24]11284 	mov	(_fuzzy_values_buffer + 2),r6
      003A5C 8F 24            [24]11285 	mov	(_fuzzy_values_buffer + 3),r7
      003A5E E5 08            [12]11286 	mov	a,_bp
      003A60 24 0D            [12]11287 	add	a,#0x0d
      003A62 F8               [12]11288 	mov	r0,a
      003A63 86 25            [24]11289 	mov	((_fuzzy_values_buffer + 0x0004) + 0),@r0
      003A65 08               [12]11290 	inc	r0
      003A66 86 26            [24]11291 	mov	((_fuzzy_values_buffer + 0x0004) + 1),@r0
      003A68 08               [12]11292 	inc	r0
      003A69 86 27            [24]11293 	mov	((_fuzzy_values_buffer + 0x0004) + 2),@r0
      003A6B 08               [12]11294 	inc	r0
      003A6C 86 28            [24]11295 	mov	((_fuzzy_values_buffer + 0x0004) + 3),@r0
      003A6E 74 21            [12]11296 	mov	a,#_fuzzy_values_buffer
      003A70 C0 E0            [24]11297 	push	acc
      003A72 74 00            [12]11298 	mov	a,#(_fuzzy_values_buffer >> 8)
      003A74 C0 E0            [24]11299 	push	acc
      003A76 74 40            [12]11300 	mov	a,#0x40
      003A78 C0 E0            [24]11301 	push	acc
      003A7A 74 02            [12]11302 	mov	a,#0x02
      003A7C C0 E0            [24]11303 	push	acc
      003A7E E4               [12]11304 	clr	a
      003A7F C0 E0            [24]11305 	push	acc
      003A81 75 82 00         [24]11306 	mov	dpl, #0x00
      003A84 12 02 29         [24]11307 	lcall	_fuzzy_and_array
      003A87 C8               [12]11308 	xch	a,r0
      003A88 E5 08            [12]11309 	mov	a,_bp
      003A8A 24 1D            [12]11310 	add	a,#0x1d
      003A8C C8               [12]11311 	xch	a,r0
      003A8D A6 82            [24]11312 	mov	@r0, dpl
      003A8F 08               [12]11313 	inc	r0
      003A90 A6 83            [24]11314 	mov	@r0, dph
      003A92 08               [12]11315 	inc	r0
      003A93 A6 F0            [24]11316 	mov	@r0, b
      003A95 08               [12]11317 	inc	r0
      003A96 F6               [12]11318 	mov	@r0,a
      003A97 E5 81            [12]11319 	mov	a,sp
      003A99 24 FB            [12]11320 	add	a,#0xfb
      003A9B F5 81            [12]11321 	mov	sp,a
                           0039E0 11322 	C$sugeno_demo.c$327$1_0$171 ==.
                                  11323 ;	../../sugeno_demo.c:327: fuzzy_or_method(
      003A9D 12 00 BD         [24]11324 	lcall	_fuzzy_values_initialize
      003AA0 E5 08            [12]11325 	mov	a,_bp
      003AA2 24 05            [12]11326 	add	a,#0x05
      003AA4 F8               [12]11327 	mov	r0,a
      003AA5 86 21            [24]11328 	mov	(_fuzzy_values_buffer + 0),@r0
      003AA7 08               [12]11329 	inc	r0
      003AA8 86 22            [24]11330 	mov	(_fuzzy_values_buffer + 1),@r0
      003AAA 08               [12]11331 	inc	r0
      003AAB 86 23            [24]11332 	mov	(_fuzzy_values_buffer + 2),@r0
      003AAD 08               [12]11333 	inc	r0
      003AAE 86 24            [24]11334 	mov	(_fuzzy_values_buffer + 3),@r0
      003AB0 E5 08            [12]11335 	mov	a,_bp
      003AB2 24 15            [12]11336 	add	a,#0x15
      003AB4 F8               [12]11337 	mov	r0,a
      003AB5 86 25            [24]11338 	mov	((_fuzzy_values_buffer + 0x0004) + 0),@r0
      003AB7 08               [12]11339 	inc	r0
      003AB8 86 26            [24]11340 	mov	((_fuzzy_values_buffer + 0x0004) + 1),@r0
      003ABA 08               [12]11341 	inc	r0
      003ABB 86 27            [24]11342 	mov	((_fuzzy_values_buffer + 0x0004) + 2),@r0
      003ABD 08               [12]11343 	inc	r0
      003ABE 86 28            [24]11344 	mov	((_fuzzy_values_buffer + 0x0004) + 3),@r0
      003AC0 74 21            [12]11345 	mov	a,#_fuzzy_values_buffer
      003AC2 C0 E0            [24]11346 	push	acc
      003AC4 74 00            [12]11347 	mov	a,#(_fuzzy_values_buffer >> 8)
      003AC6 C0 E0            [24]11348 	push	acc
      003AC8 74 40            [12]11349 	mov	a,#0x40
      003ACA C0 E0            [24]11350 	push	acc
      003ACC 74 02            [12]11351 	mov	a,#0x02
      003ACE C0 E0            [24]11352 	push	acc
      003AD0 E4               [12]11353 	clr	a
      003AD1 C0 E0            [24]11354 	push	acc
      003AD3 75 82 00         [24]11355 	mov	dpl, #0x00
      003AD6 12 04 C8         [24]11356 	lcall	_fuzzy_or_array
      003AD9 C8               [12]11357 	xch	a,r0
      003ADA E5 08            [12]11358 	mov	a,_bp
      003ADC 24 21            [12]11359 	add	a,#0x21
      003ADE C8               [12]11360 	xch	a,r0
      003ADF A6 82            [24]11361 	mov	@r0, dpl
      003AE1 08               [12]11362 	inc	r0
      003AE2 A6 83            [24]11363 	mov	@r0, dph
      003AE4 08               [12]11364 	inc	r0
      003AE5 A6 F0            [24]11365 	mov	@r0, b
      003AE7 08               [12]11366 	inc	r0
      003AE8 F6               [12]11367 	mov	@r0,a
      003AE9 E5 81            [12]11368 	mov	a,sp
      003AEB 24 FB            [12]11369 	add	a,#0xfb
      003AED F5 81            [12]11370 	mov	sp,a
                           003A32 11371 	C$sugeno_demo.c$334$1_0$171 ==.
                                  11372 ;	../../sugeno_demo.c:334: fuzzy_and_method(
      003AEF 12 00 BD         [24]11373 	lcall	_fuzzy_values_initialize
      003AF2 E5 08            [12]11374 	mov	a,_bp
      003AF4 24 05            [12]11375 	add	a,#0x05
      003AF6 F8               [12]11376 	mov	r0,a
      003AF7 86 21            [24]11377 	mov	(_fuzzy_values_buffer + 0),@r0
      003AF9 08               [12]11378 	inc	r0
      003AFA 86 22            [24]11379 	mov	(_fuzzy_values_buffer + 1),@r0
      003AFC 08               [12]11380 	inc	r0
      003AFD 86 23            [24]11381 	mov	(_fuzzy_values_buffer + 2),@r0
      003AFF 08               [12]11382 	inc	r0
      003B00 86 24            [24]11383 	mov	(_fuzzy_values_buffer + 3),@r0
      003B02 E5 08            [12]11384 	mov	a,_bp
      003B04 24 0D            [12]11385 	add	a,#0x0d
      003B06 F8               [12]11386 	mov	r0,a
      003B07 86 25            [24]11387 	mov	((_fuzzy_values_buffer + 0x0004) + 0),@r0
      003B09 08               [12]11388 	inc	r0
      003B0A 86 26            [24]11389 	mov	((_fuzzy_values_buffer + 0x0004) + 1),@r0
      003B0C 08               [12]11390 	inc	r0
      003B0D 86 27            [24]11391 	mov	((_fuzzy_values_buffer + 0x0004) + 2),@r0
      003B0F 08               [12]11392 	inc	r0
      003B10 86 28            [24]11393 	mov	((_fuzzy_values_buffer + 0x0004) + 3),@r0
      003B12 74 21            [12]11394 	mov	a,#_fuzzy_values_buffer
      003B14 C0 E0            [24]11395 	push	acc
      003B16 74 00            [12]11396 	mov	a,#(_fuzzy_values_buffer >> 8)
      003B18 C0 E0            [24]11397 	push	acc
      003B1A 74 40            [12]11398 	mov	a,#0x40
      003B1C C0 E0            [24]11399 	push	acc
      003B1E 74 02            [12]11400 	mov	a,#0x02
      003B20 C0 E0            [24]11401 	push	acc
      003B22 E4               [12]11402 	clr	a
      003B23 C0 E0            [24]11403 	push	acc
      003B25 75 82 00         [24]11404 	mov	dpl, #0x00
      003B28 12 02 29         [24]11405 	lcall	_fuzzy_and_array
      003B2B C8               [12]11406 	xch	a,r0
      003B2C E5 08            [12]11407 	mov	a,_bp
      003B2E 24 25            [12]11408 	add	a,#0x25
      003B30 C8               [12]11409 	xch	a,r0
      003B31 A6 82            [24]11410 	mov	@r0, dpl
      003B33 08               [12]11411 	inc	r0
      003B34 A6 83            [24]11412 	mov	@r0, dph
      003B36 08               [12]11413 	inc	r0
      003B37 A6 F0            [24]11414 	mov	@r0, b
      003B39 08               [12]11415 	inc	r0
      003B3A F6               [12]11416 	mov	@r0,a
      003B3B E5 81            [12]11417 	mov	a,sp
      003B3D 24 FB            [12]11418 	add	a,#0xfb
      003B3F F5 81            [12]11419 	mov	sp,a
                           003A84 11420 	C$sugeno_demo.c$341$1_0$171 ==.
                                  11421 ;	../../sugeno_demo.c:341: fuzzy_and_method(
      003B41 12 00 BD         [24]11422 	lcall	_fuzzy_values_initialize
      003B44 E5 08            [12]11423 	mov	a,_bp
      003B46 24 0D            [12]11424 	add	a,#0x0d
      003B48 F8               [12]11425 	mov	r0,a
      003B49 86 21            [24]11426 	mov	(_fuzzy_values_buffer + 0),@r0
      003B4B 08               [12]11427 	inc	r0
      003B4C 86 22            [24]11428 	mov	(_fuzzy_values_buffer + 1),@r0
      003B4E 08               [12]11429 	inc	r0
      003B4F 86 23            [24]11430 	mov	(_fuzzy_values_buffer + 2),@r0
      003B51 08               [12]11431 	inc	r0
      003B52 86 24            [24]11432 	mov	(_fuzzy_values_buffer + 3),@r0
      003B54 E5 08            [12]11433 	mov	a,_bp
      003B56 24 15            [12]11434 	add	a,#0x15
      003B58 F8               [12]11435 	mov	r0,a
      003B59 86 82            [24]11436 	mov	dpl, @r0
      003B5B 08               [12]11437 	inc	r0
      003B5C 86 83            [24]11438 	mov	dph, @r0
      003B5E 08               [12]11439 	inc	r0
      003B5F 86 F0            [24]11440 	mov	b, @r0
      003B61 08               [12]11441 	inc	r0
      003B62 E6               [12]11442 	mov	a, @r0
      003B63 12 01 6D         [24]11443 	lcall	_fuzzy_not
      003B66 AA 82            [24]11444 	mov	r2, dpl
      003B68 AB 83            [24]11445 	mov	r3, dph
      003B6A AE F0            [24]11446 	mov	r6, b
      003B6C FF               [12]11447 	mov	r7, a
      003B6D 8A 25            [24]11448 	mov	((_fuzzy_values_buffer + 0x0004) + 0),r2
      003B6F 8B 26            [24]11449 	mov	((_fuzzy_values_buffer + 0x0004) + 1),r3
      003B71 8E 27            [24]11450 	mov	((_fuzzy_values_buffer + 0x0004) + 2),r6
      003B73 8F 28            [24]11451 	mov	((_fuzzy_values_buffer + 0x0004) + 3),r7
      003B75 74 21            [12]11452 	mov	a,#_fuzzy_values_buffer
      003B77 C0 E0            [24]11453 	push	acc
      003B79 74 00            [12]11454 	mov	a,#(_fuzzy_values_buffer >> 8)
      003B7B C0 E0            [24]11455 	push	acc
      003B7D 74 40            [12]11456 	mov	a,#0x40
      003B7F C0 E0            [24]11457 	push	acc
      003B81 74 02            [12]11458 	mov	a,#0x02
      003B83 C0 E0            [24]11459 	push	acc
      003B85 E4               [12]11460 	clr	a
      003B86 C0 E0            [24]11461 	push	acc
      003B88 75 82 00         [24]11462 	mov	dpl, #0x00
      003B8B 12 02 29         [24]11463 	lcall	_fuzzy_and_array
      003B8E C8               [12]11464 	xch	a,r0
      003B8F E5 08            [12]11465 	mov	a,_bp
      003B91 24 29            [12]11466 	add	a,#0x29
      003B93 C8               [12]11467 	xch	a,r0
      003B94 A6 82            [24]11468 	mov	@r0, dpl
      003B96 08               [12]11469 	inc	r0
      003B97 A6 83            [24]11470 	mov	@r0, dph
      003B99 08               [12]11471 	inc	r0
      003B9A A6 F0            [24]11472 	mov	@r0, b
      003B9C 08               [12]11473 	inc	r0
      003B9D F6               [12]11474 	mov	@r0,a
      003B9E E5 81            [12]11475 	mov	a,sp
      003BA0 24 FB            [12]11476 	add	a,#0xfb
      003BA2 F5 81            [12]11477 	mov	sp,a
                           003AE7 11478 	C$sugeno_demo.c$350$1_0$171 ==.
                                  11479 ;	../../sugeno_demo.c:350: fuzzy_and_method(
      003BA4 12 00 BD         [24]11480 	lcall	_fuzzy_values_initialize
      003BA7 E5 08            [12]11481 	mov	a,_bp
      003BA9 24 05            [12]11482 	add	a,#0x05
      003BAB F8               [12]11483 	mov	r0,a
      003BAC 86 21            [24]11484 	mov	(_fuzzy_values_buffer + 0),@r0
      003BAE 08               [12]11485 	inc	r0
      003BAF 86 22            [24]11486 	mov	(_fuzzy_values_buffer + 1),@r0
      003BB1 08               [12]11487 	inc	r0
      003BB2 86 23            [24]11488 	mov	(_fuzzy_values_buffer + 2),@r0
      003BB4 08               [12]11489 	inc	r0
      003BB5 86 24            [24]11490 	mov	(_fuzzy_values_buffer + 3),@r0
      003BB7 E5 08            [12]11491 	mov	a,_bp
      003BB9 24 15            [12]11492 	add	a,#0x15
      003BBB F8               [12]11493 	mov	r0,a
      003BBC 86 25            [24]11494 	mov	((_fuzzy_values_buffer + 0x0004) + 0),@r0
      003BBE 08               [12]11495 	inc	r0
      003BBF 86 26            [24]11496 	mov	((_fuzzy_values_buffer + 0x0004) + 1),@r0
      003BC1 08               [12]11497 	inc	r0
      003BC2 86 27            [24]11498 	mov	((_fuzzy_values_buffer + 0x0004) + 2),@r0
      003BC4 08               [12]11499 	inc	r0
      003BC5 86 28            [24]11500 	mov	((_fuzzy_values_buffer + 0x0004) + 3),@r0
      003BC7 74 21            [12]11501 	mov	a,#_fuzzy_values_buffer
      003BC9 C0 E0            [24]11502 	push	acc
      003BCB 74 00            [12]11503 	mov	a,#(_fuzzy_values_buffer >> 8)
      003BCD C0 E0            [24]11504 	push	acc
      003BCF 74 40            [12]11505 	mov	a,#0x40
      003BD1 C0 E0            [24]11506 	push	acc
      003BD3 74 02            [12]11507 	mov	a,#0x02
      003BD5 C0 E0            [24]11508 	push	acc
      003BD7 E4               [12]11509 	clr	a
      003BD8 C0 E0            [24]11510 	push	acc
      003BDA 75 82 00         [24]11511 	mov	dpl, #0x00
      003BDD 12 02 29         [24]11512 	lcall	_fuzzy_and_array
      003BE0 C8               [12]11513 	xch	a,r0
      003BE1 E5 08            [12]11514 	mov	a,_bp
      003BE3 24 31            [12]11515 	add	a,#0x31
      003BE5 C8               [12]11516 	xch	a,r0
      003BE6 A6 82            [24]11517 	mov	@r0, dpl
      003BE8 08               [12]11518 	inc	r0
      003BE9 A6 83            [24]11519 	mov	@r0, dph
      003BEB 08               [12]11520 	inc	r0
      003BEC A6 F0            [24]11521 	mov	@r0, b
      003BEE 08               [12]11522 	inc	r0
      003BEF F6               [12]11523 	mov	@r0,a
      003BF0 E5 81            [12]11524 	mov	a,sp
      003BF2 24 FB            [12]11525 	add	a,#0xfb
      003BF4 F5 81            [12]11526 	mov	sp,a
                           003B39 11527 	C$sugeno_demo.c$357$1_0$171 ==.
                                  11528 ;	../../sugeno_demo.c:357: fuzzy_and_method(
      003BF6 12 00 BD         [24]11529 	lcall	_fuzzy_values_initialize
      003BF9 E5 08            [12]11530 	mov	a,_bp
      003BFB 24 0D            [12]11531 	add	a,#0x0d
      003BFD F8               [12]11532 	mov	r0,a
      003BFE 86 21            [24]11533 	mov	(_fuzzy_values_buffer + 0),@r0
      003C00 08               [12]11534 	inc	r0
      003C01 86 22            [24]11535 	mov	(_fuzzy_values_buffer + 1),@r0
      003C03 08               [12]11536 	inc	r0
      003C04 86 23            [24]11537 	mov	(_fuzzy_values_buffer + 2),@r0
      003C06 08               [12]11538 	inc	r0
      003C07 86 24            [24]11539 	mov	(_fuzzy_values_buffer + 3),@r0
      003C09 E5 08            [12]11540 	mov	a,_bp
      003C0B 24 15            [12]11541 	add	a,#0x15
      003C0D F8               [12]11542 	mov	r0,a
      003C0E 86 25            [24]11543 	mov	((_fuzzy_values_buffer + 0x0004) + 0),@r0
      003C10 08               [12]11544 	inc	r0
      003C11 86 26            [24]11545 	mov	((_fuzzy_values_buffer + 0x0004) + 1),@r0
      003C13 08               [12]11546 	inc	r0
      003C14 86 27            [24]11547 	mov	((_fuzzy_values_buffer + 0x0004) + 2),@r0
      003C16 08               [12]11548 	inc	r0
      003C17 86 28            [24]11549 	mov	((_fuzzy_values_buffer + 0x0004) + 3),@r0
      003C19 74 21            [12]11550 	mov	a,#_fuzzy_values_buffer
      003C1B C0 E0            [24]11551 	push	acc
      003C1D 74 00            [12]11552 	mov	a,#(_fuzzy_values_buffer >> 8)
      003C1F C0 E0            [24]11553 	push	acc
      003C21 74 40            [12]11554 	mov	a,#0x40
      003C23 C0 E0            [24]11555 	push	acc
      003C25 74 02            [12]11556 	mov	a,#0x02
      003C27 C0 E0            [24]11557 	push	acc
      003C29 E4               [12]11558 	clr	a
      003C2A C0 E0            [24]11559 	push	acc
      003C2C 75 82 00         [24]11560 	mov	dpl, #0x00
      003C2F 12 02 29         [24]11561 	lcall	_fuzzy_and_array
      003C32 AC 82            [24]11562 	mov	r4, dpl
      003C34 AD 83            [24]11563 	mov	r5, dph
      003C36 AE F0            [24]11564 	mov	r6, b
      003C38 FF               [12]11565 	mov	r7, a
      003C39 E5 81            [12]11566 	mov	a,sp
      003C3B 24 FB            [12]11567 	add	a,#0xfb
      003C3D F5 81            [12]11568 	mov	sp,a
                           003B82 11569 	C$sugeno_demo.c$364$1_0$171 ==.
                                  11570 ;	../../sugeno_demo.c:364: fuzzy_or_method(
      003C3F C0 07            [24]11571 	push	ar7
      003C41 C0 06            [24]11572 	push	ar6
      003C43 C0 05            [24]11573 	push	ar5
      003C45 C0 04            [24]11574 	push	ar4
      003C47 12 00 BD         [24]11575 	lcall	_fuzzy_values_initialize
      003C4A D0 04            [24]11576 	pop	ar4
      003C4C D0 05            [24]11577 	pop	ar5
      003C4E D0 06            [24]11578 	pop	ar6
      003C50 D0 07            [24]11579 	pop	ar7
      003C52 E5 08            [12]11580 	mov	a,_bp
      003C54 24 31            [12]11581 	add	a,#0x31
      003C56 F8               [12]11582 	mov	r0,a
      003C57 86 21            [24]11583 	mov	(_fuzzy_values_buffer + 0),@r0
      003C59 08               [12]11584 	inc	r0
      003C5A 86 22            [24]11585 	mov	(_fuzzy_values_buffer + 1),@r0
      003C5C 08               [12]11586 	inc	r0
      003C5D 86 23            [24]11587 	mov	(_fuzzy_values_buffer + 2),@r0
      003C5F 08               [12]11588 	inc	r0
      003C60 86 24            [24]11589 	mov	(_fuzzy_values_buffer + 3),@r0
      003C62 8C 25            [24]11590 	mov	((_fuzzy_values_buffer + 0x0004) + 0),r4
      003C64 8D 26            [24]11591 	mov	((_fuzzy_values_buffer + 0x0004) + 1),r5
      003C66 8E 27            [24]11592 	mov	((_fuzzy_values_buffer + 0x0004) + 2),r6
      003C68 8F 28            [24]11593 	mov	((_fuzzy_values_buffer + 0x0004) + 3),r7
      003C6A 74 21            [12]11594 	mov	a,#_fuzzy_values_buffer
      003C6C C0 E0            [24]11595 	push	acc
      003C6E 74 00            [12]11596 	mov	a,#(_fuzzy_values_buffer >> 8)
      003C70 C0 E0            [24]11597 	push	acc
      003C72 74 40            [12]11598 	mov	a,#0x40
      003C74 C0 E0            [24]11599 	push	acc
      003C76 74 02            [12]11600 	mov	a,#0x02
      003C78 C0 E0            [24]11601 	push	acc
      003C7A E4               [12]11602 	clr	a
      003C7B C0 E0            [24]11603 	push	acc
      003C7D 75 82 00         [24]11604 	mov	dpl, #0x00
      003C80 12 04 C8         [24]11605 	lcall	_fuzzy_or_array
      003C83 C8               [12]11606 	xch	a,r0
      003C84 E5 08            [12]11607 	mov	a,_bp
      003C86 24 2D            [12]11608 	add	a,#0x2d
      003C88 C8               [12]11609 	xch	a,r0
      003C89 A6 82            [24]11610 	mov	@r0, dpl
      003C8B 08               [12]11611 	inc	r0
      003C8C A6 83            [24]11612 	mov	@r0, dph
      003C8E 08               [12]11613 	inc	r0
      003C8F A6 F0            [24]11614 	mov	@r0, b
      003C91 08               [12]11615 	inc	r0
      003C92 F6               [12]11616 	mov	@r0,a
      003C93 E5 81            [12]11617 	mov	a,sp
      003C95 24 FB            [12]11618 	add	a,#0xfb
      003C97 F5 81            [12]11619 	mov	sp,a
                           003BDC 11620 	C$sugeno_demo.c$370$1_0$171 ==.
                                  11621 ;	../../sugeno_demo.c:370: return fuzzy_sugeno_weighted_average(
      003C99 12 00 BD         [24]11622 	lcall	_fuzzy_values_initialize
      003C9C E5 08            [12]11623 	mov	a,_bp
      003C9E 24 19            [12]11624 	add	a,#0x19
      003CA0 F8               [12]11625 	mov	r0,a
      003CA1 86 21            [24]11626 	mov	(_fuzzy_values_buffer + 0),@r0
      003CA3 08               [12]11627 	inc	r0
      003CA4 86 22            [24]11628 	mov	(_fuzzy_values_buffer + 1),@r0
      003CA6 08               [12]11629 	inc	r0
      003CA7 86 23            [24]11630 	mov	(_fuzzy_values_buffer + 2),@r0
      003CA9 08               [12]11631 	inc	r0
      003CAA 86 24            [24]11632 	mov	(_fuzzy_values_buffer + 3),@r0
      003CAC E5 08            [12]11633 	mov	a,_bp
      003CAE 24 F6            [12]11634 	add	a,#0xf6
      003CB0 F8               [12]11635 	mov	r0,a
      003CB1 E6               [12]11636 	mov	a,@r0
      003CB2 C0 E0            [24]11637 	push	acc
      003CB4 08               [12]11638 	inc	r0
      003CB5 E6               [12]11639 	mov	a,@r0
      003CB6 C0 E0            [24]11640 	push	acc
      003CB8 08               [12]11641 	inc	r0
      003CB9 E6               [12]11642 	mov	a,@r0
      003CBA C0 E0            [24]11643 	push	acc
      003CBC 08               [12]11644 	inc	r0
      003CBD E6               [12]11645 	mov	a,@r0
      003CBE C0 E0            [24]11646 	push	acc
      003CC0 E5 08            [12]11647 	mov	a,_bp
      003CC2 24 FA            [12]11648 	add	a,#0xfa
      003CC4 F8               [12]11649 	mov	r0,a
      003CC5 E6               [12]11650 	mov	a,@r0
      003CC6 C0 E0            [24]11651 	push	acc
      003CC8 08               [12]11652 	inc	r0
      003CC9 E6               [12]11653 	mov	a,@r0
      003CCA C0 E0            [24]11654 	push	acc
      003CCC 08               [12]11655 	inc	r0
      003CCD E6               [12]11656 	mov	a,@r0
      003CCE C0 E0            [24]11657 	push	acc
      003CD0 08               [12]11658 	inc	r0
      003CD1 E6               [12]11659 	mov	a,@r0
      003CD2 C0 E0            [24]11660 	push	acc
      003CD4 A8 08            [24]11661 	mov	r0,_bp
      003CD6 08               [12]11662 	inc	r0
      003CD7 86 82            [24]11663 	mov	dpl, @r0
      003CD9 08               [12]11664 	inc	r0
      003CDA 86 83            [24]11665 	mov	dph, @r0
      003CDC 08               [12]11666 	inc	r0
      003CDD 86 F0            [24]11667 	mov	b, @r0
      003CDF 08               [12]11668 	inc	r0
      003CE0 E6               [12]11669 	mov	a, @r0
      003CE1 12 32 C8         [24]11670 	lcall	_response_idle
      003CE4 AA 82            [24]11671 	mov	r2, dpl
      003CE6 AB 83            [24]11672 	mov	r3, dph
      003CE8 AE F0            [24]11673 	mov	r6, b
      003CEA FF               [12]11674 	mov	r7, a
      003CEB E5 81            [12]11675 	mov	a,sp
      003CED 24 F8            [12]11676 	add	a,#0xf8
      003CEF F5 81            [12]11677 	mov	sp,a
      003CF1 8A 25            [24]11678 	mov	((_fuzzy_values_buffer + 0x0004) + 0),r2
      003CF3 8B 26            [24]11679 	mov	((_fuzzy_values_buffer + 0x0004) + 1),r3
      003CF5 8E 27            [24]11680 	mov	((_fuzzy_values_buffer + 0x0004) + 2),r6
      003CF7 8F 28            [24]11681 	mov	((_fuzzy_values_buffer + 0x0004) + 3),r7
      003CF9 E5 08            [12]11682 	mov	a,_bp
      003CFB 24 1D            [12]11683 	add	a,#0x1d
      003CFD F8               [12]11684 	mov	r0,a
      003CFE 86 29            [24]11685 	mov	((_fuzzy_values_buffer + 0x0008) + 0),@r0
      003D00 08               [12]11686 	inc	r0
      003D01 86 2A            [24]11687 	mov	((_fuzzy_values_buffer + 0x0008) + 1),@r0
      003D03 08               [12]11688 	inc	r0
      003D04 86 2B            [24]11689 	mov	((_fuzzy_values_buffer + 0x0008) + 2),@r0
      003D06 08               [12]11690 	inc	r0
      003D07 86 2C            [24]11691 	mov	((_fuzzy_values_buffer + 0x0008) + 3),@r0
      003D09 E5 08            [12]11692 	mov	a,_bp
      003D0B 24 F6            [12]11693 	add	a,#0xf6
      003D0D F8               [12]11694 	mov	r0,a
      003D0E E6               [12]11695 	mov	a,@r0
      003D0F C0 E0            [24]11696 	push	acc
      003D11 08               [12]11697 	inc	r0
      003D12 E6               [12]11698 	mov	a,@r0
      003D13 C0 E0            [24]11699 	push	acc
      003D15 08               [12]11700 	inc	r0
      003D16 E6               [12]11701 	mov	a,@r0
      003D17 C0 E0            [24]11702 	push	acc
      003D19 08               [12]11703 	inc	r0
      003D1A E6               [12]11704 	mov	a,@r0
      003D1B C0 E0            [24]11705 	push	acc
      003D1D E5 08            [12]11706 	mov	a,_bp
      003D1F 24 FA            [12]11707 	add	a,#0xfa
      003D21 F8               [12]11708 	mov	r0,a
      003D22 E6               [12]11709 	mov	a,@r0
      003D23 C0 E0            [24]11710 	push	acc
      003D25 08               [12]11711 	inc	r0
      003D26 E6               [12]11712 	mov	a,@r0
      003D27 C0 E0            [24]11713 	push	acc
      003D29 08               [12]11714 	inc	r0
      003D2A E6               [12]11715 	mov	a,@r0
      003D2B C0 E0            [24]11716 	push	acc
      003D2D 08               [12]11717 	inc	r0
      003D2E E6               [12]11718 	mov	a,@r0
      003D2F C0 E0            [24]11719 	push	acc
      003D31 A8 08            [24]11720 	mov	r0,_bp
      003D33 08               [12]11721 	inc	r0
      003D34 86 82            [24]11722 	mov	dpl, @r0
      003D36 08               [12]11723 	inc	r0
      003D37 86 83            [24]11724 	mov	dph, @r0
      003D39 08               [12]11725 	inc	r0
      003D3A 86 F0            [24]11726 	mov	b, @r0
      003D3C 08               [12]11727 	inc	r0
      003D3D E6               [12]11728 	mov	a, @r0
      003D3E 12 33 D7         [24]11729 	lcall	_response_economy
      003D41 AC 82            [24]11730 	mov	r4, dpl
      003D43 AD 83            [24]11731 	mov	r5, dph
      003D45 AE F0            [24]11732 	mov	r6, b
      003D47 FF               [12]11733 	mov	r7, a
      003D48 E5 81            [12]11734 	mov	a,sp
      003D4A 24 F8            [12]11735 	add	a,#0xf8
      003D4C F5 81            [12]11736 	mov	sp,a
      003D4E 8C 2D            [24]11737 	mov	((_fuzzy_values_buffer + 0x000c) + 0),r4
      003D50 8D 2E            [24]11738 	mov	((_fuzzy_values_buffer + 0x000c) + 1),r5
      003D52 8E 2F            [24]11739 	mov	((_fuzzy_values_buffer + 0x000c) + 2),r6
      003D54 8F 30            [24]11740 	mov	((_fuzzy_values_buffer + 0x000c) + 3),r7
      003D56 E5 08            [12]11741 	mov	a,_bp
      003D58 24 21            [12]11742 	add	a,#0x21
      003D5A F8               [12]11743 	mov	r0,a
      003D5B 86 31            [24]11744 	mov	((_fuzzy_values_buffer + 0x0010) + 0),@r0
      003D5D 08               [12]11745 	inc	r0
      003D5E 86 32            [24]11746 	mov	((_fuzzy_values_buffer + 0x0010) + 1),@r0
      003D60 08               [12]11747 	inc	r0
      003D61 86 33            [24]11748 	mov	((_fuzzy_values_buffer + 0x0010) + 2),@r0
      003D63 08               [12]11749 	inc	r0
      003D64 86 34            [24]11750 	mov	((_fuzzy_values_buffer + 0x0010) + 3),@r0
      003D66 E5 08            [12]11751 	mov	a,_bp
      003D68 24 F6            [12]11752 	add	a,#0xf6
      003D6A F8               [12]11753 	mov	r0,a
      003D6B E6               [12]11754 	mov	a,@r0
      003D6C C0 E0            [24]11755 	push	acc
      003D6E 08               [12]11756 	inc	r0
      003D6F E6               [12]11757 	mov	a,@r0
      003D70 C0 E0            [24]11758 	push	acc
      003D72 08               [12]11759 	inc	r0
      003D73 E6               [12]11760 	mov	a,@r0
      003D74 C0 E0            [24]11761 	push	acc
      003D76 08               [12]11762 	inc	r0
      003D77 E6               [12]11763 	mov	a,@r0
      003D78 C0 E0            [24]11764 	push	acc
      003D7A E5 08            [12]11765 	mov	a,_bp
      003D7C 24 FA            [12]11766 	add	a,#0xfa
      003D7E F8               [12]11767 	mov	r0,a
      003D7F E6               [12]11768 	mov	a,@r0
      003D80 C0 E0            [24]11769 	push	acc
      003D82 08               [12]11770 	inc	r0
      003D83 E6               [12]11771 	mov	a,@r0
      003D84 C0 E0            [24]11772 	push	acc
      003D86 08               [12]11773 	inc	r0
      003D87 E6               [12]11774 	mov	a,@r0
      003D88 C0 E0            [24]11775 	push	acc
      003D8A 08               [12]11776 	inc	r0
      003D8B E6               [12]11777 	mov	a,@r0
      003D8C C0 E0            [24]11778 	push	acc
      003D8E A8 08            [24]11779 	mov	r0,_bp
      003D90 08               [12]11780 	inc	r0
      003D91 86 82            [24]11781 	mov	dpl, @r0
      003D93 08               [12]11782 	inc	r0
      003D94 86 83            [24]11783 	mov	dph, @r0
      003D96 08               [12]11784 	inc	r0
      003D97 86 F0            [24]11785 	mov	b, @r0
      003D99 08               [12]11786 	inc	r0
      003D9A E6               [12]11787 	mov	a, @r0
      003D9B 12 34 E7         [24]11788 	lcall	_response_balanced
      003D9E AC 82            [24]11789 	mov	r4, dpl
      003DA0 AD 83            [24]11790 	mov	r5, dph
      003DA2 AE F0            [24]11791 	mov	r6, b
      003DA4 FF               [12]11792 	mov	r7, a
      003DA5 E5 81            [12]11793 	mov	a,sp
      003DA7 24 F8            [12]11794 	add	a,#0xf8
      003DA9 F5 81            [12]11795 	mov	sp,a
      003DAB 8C 35            [24]11796 	mov	((_fuzzy_values_buffer + 0x0014) + 0),r4
      003DAD 8D 36            [24]11797 	mov	((_fuzzy_values_buffer + 0x0014) + 1),r5
      003DAF 8E 37            [24]11798 	mov	((_fuzzy_values_buffer + 0x0014) + 2),r6
      003DB1 8F 38            [24]11799 	mov	((_fuzzy_values_buffer + 0x0014) + 3),r7
      003DB3 E5 08            [12]11800 	mov	a,_bp
      003DB5 24 25            [12]11801 	add	a,#0x25
      003DB7 F8               [12]11802 	mov	r0,a
      003DB8 86 39            [24]11803 	mov	((_fuzzy_values_buffer + 0x0018) + 0),@r0
      003DBA 08               [12]11804 	inc	r0
      003DBB 86 3A            [24]11805 	mov	((_fuzzy_values_buffer + 0x0018) + 1),@r0
      003DBD 08               [12]11806 	inc	r0
      003DBE 86 3B            [24]11807 	mov	((_fuzzy_values_buffer + 0x0018) + 2),@r0
      003DC0 08               [12]11808 	inc	r0
      003DC1 86 3C            [24]11809 	mov	((_fuzzy_values_buffer + 0x0018) + 3),@r0
      003DC3 E5 08            [12]11810 	mov	a,_bp
      003DC5 24 F6            [12]11811 	add	a,#0xf6
      003DC7 F8               [12]11812 	mov	r0,a
      003DC8 E6               [12]11813 	mov	a,@r0
      003DC9 C0 E0            [24]11814 	push	acc
      003DCB 08               [12]11815 	inc	r0
      003DCC E6               [12]11816 	mov	a,@r0
      003DCD C0 E0            [24]11817 	push	acc
      003DCF 08               [12]11818 	inc	r0
      003DD0 E6               [12]11819 	mov	a,@r0
      003DD1 C0 E0            [24]11820 	push	acc
      003DD3 08               [12]11821 	inc	r0
      003DD4 E6               [12]11822 	mov	a,@r0
      003DD5 C0 E0            [24]11823 	push	acc
      003DD7 E5 08            [12]11824 	mov	a,_bp
      003DD9 24 FA            [12]11825 	add	a,#0xfa
      003DDB F8               [12]11826 	mov	r0,a
      003DDC E6               [12]11827 	mov	a,@r0
      003DDD C0 E0            [24]11828 	push	acc
      003DDF 08               [12]11829 	inc	r0
      003DE0 E6               [12]11830 	mov	a,@r0
      003DE1 C0 E0            [24]11831 	push	acc
      003DE3 08               [12]11832 	inc	r0
      003DE4 E6               [12]11833 	mov	a,@r0
      003DE5 C0 E0            [24]11834 	push	acc
      003DE7 08               [12]11835 	inc	r0
      003DE8 E6               [12]11836 	mov	a,@r0
      003DE9 C0 E0            [24]11837 	push	acc
      003DEB A8 08            [24]11838 	mov	r0,_bp
      003DED 08               [12]11839 	inc	r0
      003DEE 86 82            [24]11840 	mov	dpl, @r0
      003DF0 08               [12]11841 	inc	r0
      003DF1 86 83            [24]11842 	mov	dph, @r0
      003DF3 08               [12]11843 	inc	r0
      003DF4 86 F0            [24]11844 	mov	b, @r0
      003DF6 08               [12]11845 	inc	r0
      003DF7 E6               [12]11846 	mov	a, @r0
      003DF8 12 35 F8         [24]11847 	lcall	_response_cooling
      003DFB AC 82            [24]11848 	mov	r4, dpl
      003DFD AD 83            [24]11849 	mov	r5, dph
      003DFF AE F0            [24]11850 	mov	r6, b
      003E01 FF               [12]11851 	mov	r7, a
      003E02 E5 81            [12]11852 	mov	a,sp
      003E04 24 F8            [12]11853 	add	a,#0xf8
      003E06 F5 81            [12]11854 	mov	sp,a
      003E08 8C 3D            [24]11855 	mov	((_fuzzy_values_buffer + 0x001c) + 0),r4
      003E0A 8D 3E            [24]11856 	mov	((_fuzzy_values_buffer + 0x001c) + 1),r5
      003E0C 8E 3F            [24]11857 	mov	((_fuzzy_values_buffer + 0x001c) + 2),r6
      003E0E 8F 40            [24]11858 	mov	((_fuzzy_values_buffer + 0x001c) + 3),r7
      003E10 E5 08            [12]11859 	mov	a,_bp
      003E12 24 29            [12]11860 	add	a,#0x29
      003E14 F8               [12]11861 	mov	r0,a
      003E15 86 41            [24]11862 	mov	((_fuzzy_values_buffer + 0x0020) + 0),@r0
      003E17 08               [12]11863 	inc	r0
      003E18 86 42            [24]11864 	mov	((_fuzzy_values_buffer + 0x0020) + 1),@r0
      003E1A 08               [12]11865 	inc	r0
      003E1B 86 43            [24]11866 	mov	((_fuzzy_values_buffer + 0x0020) + 2),@r0
      003E1D 08               [12]11867 	inc	r0
      003E1E 86 44            [24]11868 	mov	((_fuzzy_values_buffer + 0x0020) + 3),@r0
      003E20 E5 08            [12]11869 	mov	a,_bp
      003E22 24 F6            [12]11870 	add	a,#0xf6
      003E24 F8               [12]11871 	mov	r0,a
      003E25 E6               [12]11872 	mov	a,@r0
      003E26 C0 E0            [24]11873 	push	acc
      003E28 08               [12]11874 	inc	r0
      003E29 E6               [12]11875 	mov	a,@r0
      003E2A C0 E0            [24]11876 	push	acc
      003E2C 08               [12]11877 	inc	r0
      003E2D E6               [12]11878 	mov	a,@r0
      003E2E C0 E0            [24]11879 	push	acc
      003E30 08               [12]11880 	inc	r0
      003E31 E6               [12]11881 	mov	a,@r0
      003E32 C0 E0            [24]11882 	push	acc
      003E34 E5 08            [12]11883 	mov	a,_bp
      003E36 24 FA            [12]11884 	add	a,#0xfa
      003E38 F8               [12]11885 	mov	r0,a
      003E39 E6               [12]11886 	mov	a,@r0
      003E3A C0 E0            [24]11887 	push	acc
      003E3C 08               [12]11888 	inc	r0
      003E3D E6               [12]11889 	mov	a,@r0
      003E3E C0 E0            [24]11890 	push	acc
      003E40 08               [12]11891 	inc	r0
      003E41 E6               [12]11892 	mov	a,@r0
      003E42 C0 E0            [24]11893 	push	acc
      003E44 08               [12]11894 	inc	r0
      003E45 E6               [12]11895 	mov	a,@r0
      003E46 C0 E0            [24]11896 	push	acc
      003E48 A8 08            [24]11897 	mov	r0,_bp
      003E4A 08               [12]11898 	inc	r0
      003E4B 86 82            [24]11899 	mov	dpl, @r0
      003E4D 08               [12]11900 	inc	r0
      003E4E 86 83            [24]11901 	mov	dph, @r0
      003E50 08               [12]11902 	inc	r0
      003E51 86 F0            [24]11903 	mov	b, @r0
      003E53 08               [12]11904 	inc	r0
      003E54 E6               [12]11905 	mov	a, @r0
      003E55 12 37 08         [24]11906 	lcall	_response_heavy_load
      003E58 AC 82            [24]11907 	mov	r4, dpl
      003E5A AD 83            [24]11908 	mov	r5, dph
      003E5C AE F0            [24]11909 	mov	r6, b
      003E5E FF               [12]11910 	mov	r7, a
      003E5F E5 81            [12]11911 	mov	a,sp
      003E61 24 F8            [12]11912 	add	a,#0xf8
      003E63 F5 81            [12]11913 	mov	sp,a
      003E65 8C 45            [24]11914 	mov	((_fuzzy_values_buffer + 0x0024) + 0),r4
      003E67 8D 46            [24]11915 	mov	((_fuzzy_values_buffer + 0x0024) + 1),r5
      003E69 8E 47            [24]11916 	mov	((_fuzzy_values_buffer + 0x0024) + 2),r6
      003E6B 8F 48            [24]11917 	mov	((_fuzzy_values_buffer + 0x0024) + 3),r7
      003E6D E5 08            [12]11918 	mov	a,_bp
      003E6F 24 2D            [12]11919 	add	a,#0x2d
      003E71 F8               [12]11920 	mov	r0,a
      003E72 86 49            [24]11921 	mov	((_fuzzy_values_buffer + 0x0028) + 0),@r0
      003E74 08               [12]11922 	inc	r0
      003E75 86 4A            [24]11923 	mov	((_fuzzy_values_buffer + 0x0028) + 1),@r0
      003E77 08               [12]11924 	inc	r0
      003E78 86 4B            [24]11925 	mov	((_fuzzy_values_buffer + 0x0028) + 2),@r0
      003E7A 08               [12]11926 	inc	r0
      003E7B 86 4C            [24]11927 	mov	((_fuzzy_values_buffer + 0x0028) + 3),@r0
      003E7D E5 08            [12]11928 	mov	a,_bp
      003E7F 24 F6            [12]11929 	add	a,#0xf6
      003E81 F8               [12]11930 	mov	r0,a
      003E82 E6               [12]11931 	mov	a,@r0
      003E83 C0 E0            [24]11932 	push	acc
      003E85 08               [12]11933 	inc	r0
      003E86 E6               [12]11934 	mov	a,@r0
      003E87 C0 E0            [24]11935 	push	acc
      003E89 08               [12]11936 	inc	r0
      003E8A E6               [12]11937 	mov	a,@r0
      003E8B C0 E0            [24]11938 	push	acc
      003E8D 08               [12]11939 	inc	r0
      003E8E E6               [12]11940 	mov	a,@r0
      003E8F C0 E0            [24]11941 	push	acc
      003E91 E5 08            [12]11942 	mov	a,_bp
      003E93 24 FA            [12]11943 	add	a,#0xfa
      003E95 F8               [12]11944 	mov	r0,a
      003E96 E6               [12]11945 	mov	a,@r0
      003E97 C0 E0            [24]11946 	push	acc
      003E99 08               [12]11947 	inc	r0
      003E9A E6               [12]11948 	mov	a,@r0
      003E9B C0 E0            [24]11949 	push	acc
      003E9D 08               [12]11950 	inc	r0
      003E9E E6               [12]11951 	mov	a,@r0
      003E9F C0 E0            [24]11952 	push	acc
      003EA1 08               [12]11953 	inc	r0
      003EA2 E6               [12]11954 	mov	a,@r0
      003EA3 C0 E0            [24]11955 	push	acc
      003EA5 A8 08            [24]11956 	mov	r0,_bp
      003EA7 08               [12]11957 	inc	r0
      003EA8 86 82            [24]11958 	mov	dpl, @r0
      003EAA 08               [12]11959 	inc	r0
      003EAB 86 83            [24]11960 	mov	dph, @r0
      003EAD 08               [12]11961 	inc	r0
      003EAE 86 F0            [24]11962 	mov	b, @r0
      003EB0 08               [12]11963 	inc	r0
      003EB1 E6               [12]11964 	mov	a, @r0
      003EB2 12 37 ED         [24]11965 	lcall	_response_protection
      003EB5 AC 82            [24]11966 	mov	r4, dpl
      003EB7 AD 83            [24]11967 	mov	r5, dph
      003EB9 AE F0            [24]11968 	mov	r6, b
      003EBB FF               [12]11969 	mov	r7, a
      003EBC E5 81            [12]11970 	mov	a,sp
      003EBE 24 F8            [12]11971 	add	a,#0xf8
      003EC0 F5 81            [12]11972 	mov	sp,a
      003EC2 8C 4D            [24]11973 	mov	((_fuzzy_values_buffer + 0x002c) + 0),r4
      003EC4 8D 4E            [24]11974 	mov	((_fuzzy_values_buffer + 0x002c) + 1),r5
      003EC6 8E 4F            [24]11975 	mov	((_fuzzy_values_buffer + 0x002c) + 2),r6
      003EC8 8F 50            [24]11976 	mov	((_fuzzy_values_buffer + 0x002c) + 3),r7
      003ECA 74 21            [12]11977 	mov	a,#_fuzzy_values_buffer
      003ECC C0 E0            [24]11978 	push	acc
      003ECE 74 00            [12]11979 	mov	a,#(_fuzzy_values_buffer >> 8)
      003ED0 C0 E0            [24]11980 	push	acc
      003ED2 74 40            [12]11981 	mov	a,#0x40
      003ED4 C0 E0            [24]11982 	push	acc
      003ED6 90 00 0C         [24]11983 	mov	dptr,#0x000c
      003ED9 12 07 8A         [24]11984 	lcall	_fuzzy_sugeno_weighted_average_array
      003EDC AC 82            [24]11985 	mov	r4, dpl
      003EDE AD 83            [24]11986 	mov	r5, dph
      003EE0 AE F0            [24]11987 	mov	r6, b
      003EE2 FF               [12]11988 	mov	r7, a
      003EE3 15 81            [12]11989 	dec	sp
      003EE5 15 81            [12]11990 	dec	sp
      003EE7 15 81            [12]11991 	dec	sp
      003EE9 8C 82            [24]11992 	mov	dpl, r4
      003EEB 8D 83            [24]11993 	mov	dph, r5
      003EED 8E F0            [24]11994 	mov	b, r6
      003EEF EF               [12]11995 	mov	a, r7
                           003E33 11996 	C$sugeno_demo.c$413$1_0$171 ==.
                                  11997 ;	../../sugeno_demo.c:413: }
      003EF0 85 08 81         [24]11998 	mov	sp,_bp
      003EF3 D0 08            [24]11999 	pop	_bp
                           003E38 12000 	C$sugeno_demo.c$413$1_0$171 ==.
                           003E38 12001 	XFsugeno_demo$calculate_fan_speed$0$0 ==.
      003EF5 22               [24]12002 	ret
                                  12003 ;------------------------------------------------------------
                                  12004 ;Allocation info for local variables in function 'fan_speed_to_pwm'
                                  12005 ;------------------------------------------------------------
                                  12006 ;fan_speed     Allocated to registers r4 r5 r6 r7 
                                  12007 ;------------------------------------------------------------
                           003E39 12008 	Fsugeno_demo$fan_speed_to_pwm$0$0 ==.
                           003E39 12009 	C$sugeno_demo.c$420$1_0$173 ==.
                                  12010 ;	../../sugeno_demo.c:420: static unsigned char fan_speed_to_pwm(float fan_speed)
                                  12011 ;	-----------------------------------------
                                  12012 ;	 function fan_speed_to_pwm
                                  12013 ;	-----------------------------------------
      003EF6                      12014 _fan_speed_to_pwm:
      003EF6 AC 82            [24]12015 	mov	r4,dpl
      003EF8 AD 83            [24]12016 	mov	r5,dph
      003EFA AE F0            [24]12017 	mov	r6,b
      003EFC FF               [12]12018 	mov	r7,a
                           003E40 12019 	C$sugeno_demo.c$422$1_0$173 ==.
                                  12020 ;	../../sugeno_demo.c:422: if (fan_speed <= 0.0f) {
      003EFD C0 07            [24]12021 	push	ar7
      003EFF C0 06            [24]12022 	push	ar6
      003F01 C0 05            [24]12023 	push	ar5
      003F03 C0 04            [24]12024 	push	ar4
      003F05 C0 04            [24]12025 	push	ar4
      003F07 C0 05            [24]12026 	push	ar5
      003F09 C0 06            [24]12027 	push	ar6
      003F0B C0 07            [24]12028 	push	ar7
      003F0D 90 00 00         [24]12029 	mov	dptr,#0x0000
      003F10 E4               [12]12030 	clr	a
      003F11 F5 F0            [12]12031 	mov	b,a
      003F13 12 41 7C         [24]12032 	lcall	___fslt
      003F16 E5 81            [12]12033 	mov	a,sp
      003F18 24 FC            [12]12034 	add	a,#0xfc
      003F1A F5 81            [12]12035 	mov	sp,a
      003F1C D0 04            [24]12036 	pop	ar4
      003F1E D0 05            [24]12037 	pop	ar5
      003F20 D0 06            [24]12038 	pop	ar6
      003F22 D0 07            [24]12039 	pop	ar7
      003F24 E5 82            [12]12040 	mov	a, dpl
      003F26 24 FF            [12]12041 	add	a,#0xff
      003F28 92 00            [24]12042 	mov	b0,c
      003F2A 40 05            [24]12043 	jc	00102$
                           003E6F 12044 	C$sugeno_demo.c$423$2_0$174 ==.
                                  12045 ;	../../sugeno_demo.c:423: return 0u;
      003F2C 75 82 00         [24]12046 	mov	dpl, #0x00
      003F2F 80 66            [24]12047 	sjmp	00105$
      003F31                      12048 00102$:
                           003E74 12049 	C$sugeno_demo.c$426$1_0$173 ==.
                                  12050 ;	../../sugeno_demo.c:426: if (fan_speed >= 100.0f) {
      003F31 C0 07            [24]12051 	push	ar7
      003F33 C0 06            [24]12052 	push	ar6
      003F35 C0 05            [24]12053 	push	ar5
      003F37 C0 04            [24]12054 	push	ar4
      003F39 E4               [12]12055 	clr	a
      003F3A C0 E0            [24]12056 	push	acc
      003F3C C0 E0            [24]12057 	push	acc
      003F3E 74 C8            [12]12058 	mov	a,#0xc8
      003F40 C0 E0            [24]12059 	push	acc
      003F42 74 42            [12]12060 	mov	a,#0x42
      003F44 C0 E0            [24]12061 	push	acc
      003F46 8C 82            [24]12062 	mov	dpl, r4
      003F48 8D 83            [24]12063 	mov	dph, r5
      003F4A 8E F0            [24]12064 	mov	b, r6
      003F4C EF               [12]12065 	mov	a, r7
      003F4D 12 41 7C         [24]12066 	lcall	___fslt
      003F50 E5 81            [12]12067 	mov	a,sp
      003F52 24 FC            [12]12068 	add	a,#0xfc
      003F54 F5 81            [12]12069 	mov	sp,a
      003F56 D0 04            [24]12070 	pop	ar4
      003F58 D0 05            [24]12071 	pop	ar5
      003F5A D0 06            [24]12072 	pop	ar6
      003F5C D0 07            [24]12073 	pop	ar7
      003F5E E5 82            [12]12074 	mov	a, dpl
      003F60 24 FF            [12]12075 	add	a,#0xff
      003F62 92 00            [24]12076 	mov	b0,c
      003F64 40 05            [24]12077 	jc	00104$
                           003EA9 12078 	C$sugeno_demo.c$427$2_0$175 ==.
                                  12079 ;	../../sugeno_demo.c:427: return 100u;
      003F66 75 82 64         [24]12080 	mov	dpl, #0x64
      003F69 80 2C            [24]12081 	sjmp	00105$
      003F6B                      12082 00104$:
                           003EAE 12083 	C$sugeno_demo.c$432$1_0$173 ==.
                                  12084 ;	../../sugeno_demo.c:432: );
      003F6B E4               [12]12085 	clr	a
      003F6C C0 E0            [24]12086 	push	acc
      003F6E C0 E0            [24]12087 	push	acc
      003F70 C0 E0            [24]12088 	push	acc
      003F72 74 3F            [12]12089 	mov	a,#0x3f
      003F74 C0 E0            [24]12090 	push	acc
      003F76 8C 82            [24]12091 	mov	dpl, r4
      003F78 8D 83            [24]12092 	mov	dph, r5
      003F7A 8E F0            [24]12093 	mov	b, r6
      003F7C EF               [12]12094 	mov	a, r7
      003F7D 12 41 CE         [24]12095 	lcall	___fsadd
      003F80 AC 82            [24]12096 	mov	r4, dpl
      003F82 AD 83            [24]12097 	mov	r5, dph
      003F84 AE F0            [24]12098 	mov	r6, b
      003F86 FF               [12]12099 	mov	r7, a
      003F87 E5 81            [12]12100 	mov	a,sp
      003F89 24 FC            [12]12101 	add	a,#0xfc
      003F8B F5 81            [12]12102 	mov	sp,a
      003F8D 8C 82            [24]12103 	mov	dpl, r4
      003F8F 8D 83            [24]12104 	mov	dph, r5
      003F91 8E F0            [24]12105 	mov	b, r6
      003F93 EF               [12]12106 	mov	a, r7
      003F94 12 43 C4         [24]12107 	lcall	___fs2uchar
      003F97                      12108 00105$:
                           003EDA 12109 	C$sugeno_demo.c$433$1_0$173 ==.
                                  12110 ;	../../sugeno_demo.c:433: }
                           003EDA 12111 	C$sugeno_demo.c$433$1_0$173 ==.
                           003EDA 12112 	XFsugeno_demo$fan_speed_to_pwm$0$0 ==.
      003F97 22               [24]12113 	ret
                                  12114 ;------------------------------------------------------------
                                  12115 ;Allocation info for local variables in function 'main'
                                  12116 ;------------------------------------------------------------
                                  12117 ;sloc0         Allocated to stack - _bp +1 +4 
                                  12118 ;sloc1         Allocated to stack - _bp +5 +4 
                                  12119 ;------------------------------------------------------------
                           003EDB 12120 	G$main$0$0 ==.
                           003EDB 12121 	C$sugeno_demo.c$456$1_0$177 ==.
                                  12122 ;	../../sugeno_demo.c:456: void main(void)
                                  12123 ;	-----------------------------------------
                                  12124 ;	 function main
                                  12125 ;	-----------------------------------------
      003F98                      12126 _main:
      003F98 C0 08            [24]12127 	push	_bp
      003F9A E5 81            [12]12128 	mov	a,sp
      003F9C F5 08            [12]12129 	mov	_bp,a
      003F9E 24 08            [12]12130 	add	a,#0x08
      003FA0 F5 81            [12]12131 	mov	sp,a
                           003EE5 12132 	C$sugeno_demo.c$459$1_0$177 ==.
                                  12133 ;	../../sugeno_demo.c:459: 0x55u;
      003FA2 75 80 55         [24]12134 	mov	_P0,#0x55
                           003EE8 12135 	C$sugeno_demo.c$462$1_0$177 ==.
                                  12136 ;	../../sugeno_demo.c:462: 0x00u;
      003FA5 75 90 00         [24]12137 	mov	_P1,#0x00
                           003EEB 12138 	C$sugeno_demo.c$465$1_0$177 ==.
                                  12139 ;	../../sugeno_demo.c:465: test_temperature;
      003FA8 85 61 A0         [24]12140 	mov	_P2,_test_temperature
                           003EEE 12141 	C$sugeno_demo.c$472$2_0$177 ==.
                                  12142 ;	../../sugeno_demo.c:472: );
      003FAB 85 63 82         [24]12143 	mov	dpl, _test_vibration
      003FAE 12 43 CC         [24]12144 	lcall	___uchar2fs
      003FB1 C8               [12]12145 	xch	a,r0
      003FB2 E5 08            [12]12146 	mov	a,_bp
      003FB4 24 05            [12]12147 	add	a,#0x05
      003FB6 C8               [12]12148 	xch	a,r0
      003FB7 A6 82            [24]12149 	mov	@r0, dpl
      003FB9 08               [12]12150 	inc	r0
      003FBA A6 83            [24]12151 	mov	@r0, dph
      003FBC 08               [12]12152 	inc	r0
      003FBD A6 F0            [24]12153 	mov	@r0, b
      003FBF 08               [12]12154 	inc	r0
      003FC0 F6               [12]12155 	mov	@r0,a
                           003F04 12156 	C$sugeno_demo.c$470$2_0$177 ==.
                                  12157 ;	../../sugeno_demo.c:470: (float)test_load,
      003FC1 85 62 82         [24]12158 	mov	dpl, _test_load
      003FC4 12 43 CC         [24]12159 	lcall	___uchar2fs
      003FC7 A8 08            [24]12160 	mov	r0,_bp
      003FC9 08               [12]12161 	inc	r0
      003FCA A6 82            [24]12162 	mov	@r0, dpl
      003FCC 08               [12]12163 	inc	r0
      003FCD A6 83            [24]12164 	mov	@r0, dph
      003FCF 08               [12]12165 	inc	r0
      003FD0 A6 F0            [24]12166 	mov	@r0, b
      003FD2 08               [12]12167 	inc	r0
      003FD3 F6               [12]12168 	mov	@r0,a
                           003F17 12169 	C$sugeno_demo.c$469$2_0$177 ==.
                                  12170 ;	../../sugeno_demo.c:469: (float)test_temperature,
      003FD4 85 61 82         [24]12171 	mov	dpl, _test_temperature
      003FD7 12 43 CC         [24]12172 	lcall	___uchar2fs
      003FDA AA 82            [24]12173 	mov	r2, dpl
      003FDC AB 83            [24]12174 	mov	r3, dph
      003FDE AE F0            [24]12175 	mov	r6, b
      003FE0 FF               [12]12176 	mov	r7, a
      003FE1 E5 08            [12]12177 	mov	a,_bp
      003FE3 24 05            [12]12178 	add	a,#0x05
      003FE5 F8               [12]12179 	mov	r0,a
      003FE6 E6               [12]12180 	mov	a,@r0
      003FE7 C0 E0            [24]12181 	push	acc
      003FE9 08               [12]12182 	inc	r0
      003FEA E6               [12]12183 	mov	a,@r0
      003FEB C0 E0            [24]12184 	push	acc
      003FED 08               [12]12185 	inc	r0
      003FEE E6               [12]12186 	mov	a,@r0
      003FEF C0 E0            [24]12187 	push	acc
      003FF1 08               [12]12188 	inc	r0
      003FF2 E6               [12]12189 	mov	a,@r0
      003FF3 C0 E0            [24]12190 	push	acc
      003FF5 A8 08            [24]12191 	mov	r0,_bp
      003FF7 08               [12]12192 	inc	r0
      003FF8 E6               [12]12193 	mov	a,@r0
      003FF9 C0 E0            [24]12194 	push	acc
      003FFB 08               [12]12195 	inc	r0
      003FFC E6               [12]12196 	mov	a,@r0
      003FFD C0 E0            [24]12197 	push	acc
      003FFF 08               [12]12198 	inc	r0
      004000 E6               [12]12199 	mov	a,@r0
      004001 C0 E0            [24]12200 	push	acc
      004003 08               [12]12201 	inc	r0
      004004 E6               [12]12202 	mov	a,@r0
      004005 C0 E0            [24]12203 	push	acc
      004007 8A 82            [24]12204 	mov	dpl, r2
      004009 8B 83            [24]12205 	mov	dph, r3
      00400B 8E F0            [24]12206 	mov	b, r6
      00400D EF               [12]12207 	mov	a, r7
      00400E 12 38 FE         [24]12208 	lcall	_calculate_fan_speed
      004011 85 82 65         [24]12209 	mov	_test_fan_speed,dpl
      004014 85 83 66         [24]12210 	mov	(_test_fan_speed + 1),dph
      004017 85 F0 67         [24]12211 	mov	(_test_fan_speed + 2),b
      00401A F5 68            [12]12212 	mov	(_test_fan_speed + 3),a
      00401C E5 81            [12]12213 	mov	a,sp
      00401E 24 F8            [12]12214 	add	a,#0xf8
      004020 F5 81            [12]12215 	mov	sp,a
                           003F65 12216 	C$sugeno_demo.c$476$1_0$177 ==.
                                  12217 ;	../../sugeno_demo.c:476: test_fan_speed
      004022 85 65 82         [24]12218 	mov	dpl, _test_fan_speed
      004025 85 66 83         [24]12219 	mov	dph, (_test_fan_speed + 1)
      004028 85 67 F0         [24]12220 	mov	b, (_test_fan_speed + 2)
      00402B E5 68            [12]12221 	mov	a, (_test_fan_speed + 3)
      00402D 12 3E F6         [24]12222 	lcall	_fan_speed_to_pwm
      004030 85 82 64         [24]12223 	mov	_test_pwm,dpl
                           003F76 12224 	C$sugeno_demo.c$480$1_0$177 ==.
                                  12225 ;	../../sugeno_demo.c:480: test_pwm;
      004033 85 64 90         [24]12226 	mov	_P1,_test_pwm
                           003F79 12227 	C$sugeno_demo.c$483$1_0$177 ==.
                                  12228 ;	../../sugeno_demo.c:483: 0xAAu;
      004036 75 80 AA         [24]12229 	mov	_P0,#0xaa
      004039                      12230 00103$:
      004039 80 FE            [24]12231 	sjmp	00103$
                           003F7E 12232 	C$sugeno_demo.c$488$2_0$177 ==.
                                  12233 ;	../../sugeno_demo.c:488: }
      00403B 85 08 81         [24]12234 	mov	sp,_bp
      00403E D0 08            [24]12235 	pop	_bp
                           003F83 12236 	C$sugeno_demo.c$488$2_0$177 ==.
                           003F83 12237 	XG$main$0$0 ==.
      004040 22               [24]12238 	ret
                                  12239 	.area CSEG    (CODE)
                                  12240 	.area CONST   (CODE)
                                  12241 	.area CONST   (CODE)
                           000000 12242 Fsugeno_demo$hedges$0_0$0 == .
      00446A                      12243 _hedges:
      00446A 01                   12244 	.db #0x01	; 1
      00446B 02                   12245 	.db #0x02	; 2
      00446C 03                   12246 	.db #0x03	; 3
                                  12247 	.area CSEG    (CODE)
                                  12248 	.area XINIT   (CODE)
                                  12249 	.area CABS    (ABS,CODE)
