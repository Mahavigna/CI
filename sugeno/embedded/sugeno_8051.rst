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
                           000000   570 	C$sugeno_demo.c$25$2_0$179 ==.
                                    571 ;	../../sugeno_demo.c:25: volatile unsigned char test_temperature = 42u;
      0000A5 75 61 2A         [24]  572 	mov	_test_temperature,#0x2a
                           000003   573 	C$sugeno_demo.c$26$2_0$179 ==.
                                    574 ;	../../sugeno_demo.c:26: volatile unsigned char test_load = 65u;
      0000A8 75 62 41         [24]  575 	mov	_test_load,#0x41
                           000006   576 	C$sugeno_demo.c$27$2_0$179 ==.
                                    577 ;	../../sugeno_demo.c:27: volatile unsigned char test_vibration = 4u;
      0000AB 75 63 04         [24]  578 	mov	_test_vibration,#0x04
                           000009   579 	C$sugeno_demo.c$29$2_0$179 ==.
                                    580 ;	../../sugeno_demo.c:29: volatile unsigned char test_pwm = 0u;
      0000AE 75 64 00         [24]  581 	mov	_test_pwm,#0x00
                           00000C   582 	C$sugeno_demo.c$30$2_0$179 ==.
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
                           000000   609 	C$fuzzy.h$148$0_0$3 ==.
                                    610 ;	../../fuzzy.h:148: static float *fuzzy_values_initialize(void)
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
                           000000   623 	C$fuzzy.h$153$3_0$5 ==.
                                    624 ;	../../fuzzy.h:153: index = 0u;
      0000BD 7E 00            [12]  625 	mov	r6,#0x00
      0000BF 7F 00            [12]  626 	mov	r7,#0x00
      0000C1                        627 00102$:
                           000004   628 	C$fuzzy.h$157$3_0$5 ==.
                                    629 ;	../../fuzzy.h:157: fuzzy_values_buffer[index] = 0.0f;
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
                           00001E   651 	C$fuzzy.h$155$2_0$4 ==.
                                    652 ;	../../fuzzy.h:155: index++
      0000DB 0E               [12]  653 	inc	r6
      0000DC BE 00 01         [24]  654 	cjne	r6,#0x00,00119$
      0000DF 0F               [12]  655 	inc	r7
      0000E0                        656 00119$:
                           000023   657 	C$fuzzy.h$154$2_0$4 ==.
                                    658 ;	../../fuzzy.h:154: index < FUZZY_MAX_VALUES;
      0000E0 C3               [12]  659 	clr	c
      0000E1 EE               [12]  660 	mov	a,r6
      0000E2 94 10            [12]  661 	subb	a,#0x10
      0000E4 EF               [12]  662 	mov	a,r7
      0000E5 94 00            [12]  663 	subb	a,#0x00
      0000E7 40 D8            [24]  664 	jc	00102$
                           00002C   665 	C$fuzzy.h$160$1_0$3 ==.
                                    666 ;	../../fuzzy.h:160: return fuzzy_values_buffer;
      0000E9 90 00 21         [24]  667 	mov	dptr,#_fuzzy_values_buffer
      0000EC 75 F0 40         [24]  668 	mov	b, #0x40
                           000032   669 	C$fuzzy.h$161$1_0$3 ==.
                                    670 ;	../../fuzzy.h:161: }
                           000032   671 	C$fuzzy.h$161$1_0$3 ==.
                           000032   672 	XFsugeno_demo$fuzzy_values_initialize$0$0 ==.
      0000EF 22               [24]  673 	ret
                                    674 ;------------------------------------------------------------
                                    675 ;Allocation info for local variables in function 'fuzzy_clamp'
                                    676 ;------------------------------------------------------------
                                    677 ;value         Allocated to registers r4 r5 r6 r7 
                                    678 ;------------------------------------------------------------
                           000033   679 	Fsugeno_demo$fuzzy_clamp$0$0 ==.
                           000033   680 	C$fuzzy.h$926$1_0$27 ==.
                                    681 ;	../../fuzzy.h:926: static float fuzzy_clamp(float value)
                                    682 ;	-----------------------------------------
                                    683 ;	 function fuzzy_clamp
                                    684 ;	-----------------------------------------
      0000F0                        685 _fuzzy_clamp:
      0000F0 AC 82            [24]  686 	mov	r4,dpl
      0000F2 AD 83            [24]  687 	mov	r5,dph
      0000F4 AE F0            [24]  688 	mov	r6,b
      0000F6 FF               [12]  689 	mov	r7,a
                           00003A   690 	C$fuzzy.h$928$1_0$27 ==.
                                    691 ;	../../fuzzy.h:928: if (value < LEVEL_LO) {
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
                           000068   716 	C$fuzzy.h$929$2_0$28 ==.
                                    717 ;	../../fuzzy.h:929: return LEVEL_LO;
      000125 90 00 00         [24]  718 	mov	dptr,#0x0000
      000128 E4               [12]  719 	clr	a
      000129 F5 F0            [12]  720 	mov	b,a
      00012B 80 3F            [24]  721 	sjmp	00105$
      00012D                        722 00102$:
                           000070   723 	C$fuzzy.h$932$1_0$27 ==.
                                    724 ;	../../fuzzy.h:932: if (value > LEVEL_HI) {
      00012D C0 07            [24]  725 	push	ar7
      00012F C0 06            [24]  726 	push	ar6
      000131 C0 05            [24]  727 	push	ar5
      000133 C0 04            [24]  728 	push	ar4
      000135 C0 04            [24]  729 	push	ar4
      000137 C0 05            [24]  730 	push	ar5
      000139 C0 06            [24]  731 	push	ar6
      00013B C0 07            [24]  732 	push	ar7
      00013D 90 00 00         [24]  733 	mov	dptr,#0x0000
      000140 75 F0 80         [24]  734 	mov	b, #0x80
      000143 74 3F            [12]  735 	mov	a, #0x3f
      000145 12 41 7C         [24]  736 	lcall	___fslt
      000148 AB 82            [24]  737 	mov	r3, dpl
      00014A E5 81            [12]  738 	mov	a,sp
      00014C 24 FC            [12]  739 	add	a,#0xfc
      00014E F5 81            [12]  740 	mov	sp,a
      000150 D0 04            [24]  741 	pop	ar4
      000152 D0 05            [24]  742 	pop	ar5
      000154 D0 06            [24]  743 	pop	ar6
      000156 D0 07            [24]  744 	pop	ar7
      000158 EB               [12]  745 	mov	a,r3
      000159 60 0A            [24]  746 	jz	00104$
                           00009E   747 	C$fuzzy.h$933$2_0$29 ==.
                                    748 ;	../../fuzzy.h:933: return LEVEL_HI;
      00015B 90 00 00         [24]  749 	mov	dptr,#0x0000
      00015E 75 F0 80         [24]  750 	mov	b, #0x80
      000161 74 3F            [12]  751 	mov	a, #0x3f
      000163 80 07            [24]  752 	sjmp	00105$
      000165                        753 00104$:
                           0000A8   754 	C$fuzzy.h$936$1_0$27 ==.
                                    755 ;	../../fuzzy.h:936: return value;
      000165 8C 82            [24]  756 	mov	dpl, r4
      000167 8D 83            [24]  757 	mov	dph, r5
      000169 8E F0            [24]  758 	mov	b, r6
      00016B EF               [12]  759 	mov	a, r7
      00016C                        760 00105$:
                           0000AF   761 	C$fuzzy.h$937$1_0$27 ==.
                                    762 ;	../../fuzzy.h:937: }
                           0000AF   763 	C$fuzzy.h$937$1_0$27 ==.
                           0000AF   764 	XFsugeno_demo$fuzzy_clamp$0$0 ==.
      00016C 22               [24]  765 	ret
                                    766 ;------------------------------------------------------------
                                    767 ;Allocation info for local variables in function 'fuzzy_not'
                                    768 ;------------------------------------------------------------
                                    769 ;membership    Allocated to registers r4 r5 r6 r7 
                                    770 ;------------------------------------------------------------
                           0000B0   771 	G$fuzzy_not$0$0 ==.
                           0000B0   772 	C$fuzzy.h$942$1_0$31 ==.
                                    773 ;	../../fuzzy.h:942: float fuzzy_not(
                                    774 ;	-----------------------------------------
                                    775 ;	 function fuzzy_not
                                    776 ;	-----------------------------------------
      00016D                        777 _fuzzy_not:
                           0000B0   778 	C$fuzzy.h$947$1_0$31 ==.
                                    779 ;	../../fuzzy.h:947: fuzzy_clamp( membership
      00016D 12 00 F0         [24]  780 	lcall	_fuzzy_clamp
      000170 AC 82            [24]  781 	mov	r4, dpl
      000172 AD 83            [24]  782 	mov	r5, dph
      000174 AE F0            [24]  783 	mov	r6, b
      000176 FF               [12]  784 	mov	r7, a
      000177 C0 04            [24]  785 	push	ar4
      000179 C0 05            [24]  786 	push	ar5
      00017B C0 06            [24]  787 	push	ar6
      00017D C0 07            [24]  788 	push	ar7
      00017F 90 00 00         [24]  789 	mov	dptr,#0x0000
      000182 75 F0 80         [24]  790 	mov	b, #0x80
      000185 74 3F            [12]  791 	mov	a, #0x3f
      000187 12 40 41         [24]  792 	lcall	___fssub
      00018A AC 82            [24]  793 	mov	r4, dpl
      00018C AD 83            [24]  794 	mov	r5, dph
      00018E AE F0            [24]  795 	mov	r6, b
      000190 FF               [12]  796 	mov	r7, a
      000191 E5 81            [12]  797 	mov	a,sp
      000193 24 FC            [12]  798 	add	a,#0xfc
      000195 F5 81            [12]  799 	mov	sp,a
      000197 8C 82            [24]  800 	mov	dpl, r4
      000199 8D 83            [24]  801 	mov	dph, r5
      00019B 8E F0            [24]  802 	mov	b, r6
      00019D EF               [12]  803 	mov	a, r7
                           0000E1   804 	C$fuzzy.h$949$1_0$31 ==.
                                    805 ;	../../fuzzy.h:949: }
                           0000E1   806 	C$fuzzy.h$949$1_0$31 ==.
                           0000E1   807 	XG$fuzzy_not$0$0 ==.
      00019E 22               [24]  808 	ret
                                    809 ;------------------------------------------------------------
                                    810 ;Allocation info for local variables in function 'fuzzy_apply_hedge'
                                    811 ;------------------------------------------------------------
                                    812 ;hedge         Allocated to stack - _bp -3 +1 
                                    813 ;membership    Allocated to stack - _bp +1 +4 
                                    814 ;result        Allocated to registers r2 r3 r6 r7 
                                    815 ;------------------------------------------------------------
                           0000E2   816 	Fsugeno_demo$fuzzy_apply_hedge$0$0 ==.
                           0000E2   817 	C$fuzzy.h$959$1_0$33 ==.
                                    818 ;	../../fuzzy.h:959: static float fuzzy_apply_hedge(
                                    819 ;	-----------------------------------------
                                    820 ;	 function fuzzy_apply_hedge
                                    821 ;	-----------------------------------------
      00019F                        822 _fuzzy_apply_hedge:
      00019F C0 08            [24]  823 	push	_bp
      0001A1 85 81 08         [24]  824 	mov	_bp,sp
      0001A4 AC 82            [24]  825 	mov	r4,dpl
      0001A6 AD 83            [24]  826 	mov	r5,dph
      0001A8 AE F0            [24]  827 	mov	r6,b
      0001AA FF               [12]  828 	mov	r7,a
      0001AB E5 81            [12]  829 	mov	a,sp
      0001AD 24 04            [12]  830 	add	a,#0x04
      0001AF F5 81            [12]  831 	mov	sp,a
                           0000F4   832 	C$fuzzy.h$965$1_0$33 ==.
                                    833 ;	../../fuzzy.h:965: fuzzy_clamp( membership
      0001B1 8C 82            [24]  834 	mov	dpl, r4
      0001B3 8D 83            [24]  835 	mov	dph, r5
      0001B5 8E F0            [24]  836 	mov	b, r6
      0001B7 EF               [12]  837 	mov	a, r7
      0001B8 12 00 F0         [24]  838 	lcall	_fuzzy_clamp
      0001BB A8 08            [24]  839 	mov	r0,_bp
      0001BD 08               [12]  840 	inc	r0
      0001BE A6 82            [24]  841 	mov	@r0, dpl
      0001C0 08               [12]  842 	inc	r0
      0001C1 A6 83            [24]  843 	mov	@r0, dph
      0001C3 08               [12]  844 	inc	r0
      0001C4 A6 F0            [24]  845 	mov	@r0, b
      0001C6 08               [12]  846 	inc	r0
      0001C7 F6               [12]  847 	mov	@r0,a
                           00010B   848 	C$fuzzy.h$970$2_0$34 ==.
                                    849 ;	../../fuzzy.h:970: float result =
      0001C8 7A 00            [12]  850 	mov	r2,#0x00
      0001CA 7B 00            [12]  851 	mov	r3,#0x00
      0001CC 7E 80            [12]  852 	mov	r6,#0x80
      0001CE 7F 3F            [12]  853 	mov	r7,#0x3f
                           000113   854 	C$fuzzy.h$973$1_1$34 ==.
                                    855 ;	../../fuzzy.h:973: if (hedge == 0u) {
      0001D0 E5 08            [12]  856 	mov	a,_bp
      0001D2 24 FD            [12]  857 	add	a,#0xfd
      0001D4 F8               [12]  858 	mov	r0,a
      0001D5 E6               [12]  859 	mov	a,@r0
      0001D6 70 07            [24]  860 	jnz	00110$
                           00011B   861 	C$fuzzy.h$974$2_1$35 ==.
                                    862 ;	../../fuzzy.h:974: hedge = 1u;
      0001D8 E5 08            [12]  863 	mov	a,_bp
      0001DA 24 FD            [12]  864 	add	a,#0xfd
      0001DC F8               [12]  865 	mov	r0,a
      0001DD 76 01            [12]  866 	mov	@r0,#0x01
                           000122   867 	C$fuzzy.h$977$1_1$33 ==.
                                    868 ;	../../fuzzy.h:977: while (hedge > 0u) {
      0001DF                        869 00110$:
      0001DF E5 08            [12]  870 	mov	a,_bp
      0001E1 24 FD            [12]  871 	add	a,#0xfd
      0001E3 F8               [12]  872 	mov	r0,a
      0001E4 86 05            [24]  873 	mov	ar5,@r0
      0001E6                        874 00103$:
      0001E6 ED               [12]  875 	mov	a,r5
      0001E7 60 30            [24]  876 	jz	00105$
                           00012C   877 	C$fuzzy.h$978$1_1$33 ==.
                                    878 ;	../../fuzzy.h:978: result *= membership;
      0001E9 C0 05            [24]  879 	push	ar5
      0001EB A8 08            [24]  880 	mov	r0,_bp
      0001ED 08               [12]  881 	inc	r0
      0001EE E6               [12]  882 	mov	a,@r0
      0001EF C0 E0            [24]  883 	push	acc
      0001F1 08               [12]  884 	inc	r0
      0001F2 E6               [12]  885 	mov	a,@r0
      0001F3 C0 E0            [24]  886 	push	acc
      0001F5 08               [12]  887 	inc	r0
      0001F6 E6               [12]  888 	mov	a,@r0
      0001F7 C0 E0            [24]  889 	push	acc
      0001F9 08               [12]  890 	inc	r0
      0001FA E6               [12]  891 	mov	a,@r0
      0001FB C0 E0            [24]  892 	push	acc
                           000140   893 	C$fuzzy.h$980$1_1$33 ==.
                                    894 ;	../../fuzzy.h:980: hedge--;
      0001FD 8A 82            [24]  895 	mov	dpl, r2
      0001FF 8B 83            [24]  896 	mov	dph, r3
      000201 8E F0            [24]  897 	mov	b, r6
      000203 EF               [12]  898 	mov	a, r7
      000204 12 40 4C         [24]  899 	lcall	___fsmul
      000207 AA 82            [24]  900 	mov	r2, dpl
      000209 AB 83            [24]  901 	mov	r3, dph
      00020B AE F0            [24]  902 	mov	r6, b
      00020D FF               [12]  903 	mov	r7, a
      00020E E5 81            [12]  904 	mov	a,sp
      000210 24 FC            [12]  905 	add	a,#0xfc
      000212 F5 81            [12]  906 	mov	sp,a
      000214 D0 05            [24]  907 	pop	ar5
      000216 1D               [12]  908 	dec	r5
      000217 80 CD            [24]  909 	sjmp	00103$
      000219                        910 00105$:
                           00015C   911 	C$fuzzy.h$984$1_1$34 ==.
                                    912 ;	../../fuzzy.h:984: result
      000219 8A 82            [24]  913 	mov	dpl, r2
      00021B 8B 83            [24]  914 	mov	dph, r3
      00021D 8E F0            [24]  915 	mov	b, r6
      00021F EF               [12]  916 	mov	a, r7
      000220 12 00 F0         [24]  917 	lcall	_fuzzy_clamp
                           000166   918 	C$fuzzy.h$1000$1_1$33 ==.
                                    919 ;	../../fuzzy.h:1000: }
      000223 85 08 81         [24]  920 	mov	sp,_bp
      000226 D0 08            [24]  921 	pop	_bp
                           00016B   922 	C$fuzzy.h$1000$1_1$33 ==.
                           00016B   923 	XFsugeno_demo$fuzzy_apply_hedge$0$0 ==.
      000228 22               [24]  924 	ret
                                    925 ;------------------------------------------------------------
                                    926 ;Allocation info for local variables in function 'fuzzy_and_array'
                                    927 ;------------------------------------------------------------
                                    928 ;count         Allocated to stack - _bp -4 +2 
                                    929 ;args          Allocated to stack - _bp -7 +3 
                                    930 ;method        Allocated to registers r5 
                                    931 ;result        Allocated to stack - _bp +5 +4 
                                    932 ;next          Allocated to stack - _bp +9 +4 
                                    933 ;index         Allocated to stack - _bp +13 +2 
                                    934 ;sloc0         Allocated to stack - _bp +1 +3 
                                    935 ;sloc1         Allocated to stack - _bp +4 +1 
                                    936 ;------------------------------------------------------------
                           00016C   937 	G$fuzzy_and_array$0$0 ==.
                           00016C   938 	C$fuzzy.h$1014$1_1$38 ==.
                                    939 ;	../../fuzzy.h:1014: float fuzzy_and_array(
                                    940 ;	-----------------------------------------
                                    941 ;	 function fuzzy_and_array
                                    942 ;	-----------------------------------------
      000229                        943 _fuzzy_and_array:
      000229 C0 08            [24]  944 	push	_bp
      00022B E5 81            [12]  945 	mov	a,sp
      00022D F5 08            [12]  946 	mov	_bp,a
      00022F 24 0E            [12]  947 	add	a,#0x0e
      000231 F5 81            [12]  948 	mov	sp,a
      000233 AD 82            [24]  949 	mov	r5, dpl
                           000178   950 	C$fuzzy.h$1025$1_0$38 ==.
                                    951 ;	../../fuzzy.h:1025: args == NULL ||
      000235 E5 08            [12]  952 	mov	a,_bp
      000237 24 F9            [12]  953 	add	a,#0xf9
      000239 F8               [12]  954 	mov	r0,a
      00023A E6               [12]  955 	mov	a,@r0
      00023B 08               [12]  956 	inc	r0
      00023C 46               [12]  957 	orl	a,@r0
      00023D 60 0A            [24]  958 	jz	00101$
                           000182   959 	C$fuzzy.h$1026$1_0$38 ==.
                                    960 ;	../../fuzzy.h:1026: count == 0u
      00023F E5 08            [12]  961 	mov	a,_bp
      000241 24 FC            [12]  962 	add	a,#0xfc
      000243 F8               [12]  963 	mov	r0,a
      000244 E6               [12]  964 	mov	a,@r0
      000245 08               [12]  965 	inc	r0
      000246 46               [12]  966 	orl	a,@r0
      000247 70 0B            [24]  967 	jnz	00102$
      000249                        968 00101$:
                           00018C   969 	C$fuzzy.h$1028$2_0$39 ==.
                                    970 ;	../../fuzzy.h:1028: return LEVEL_HI;
      000249 90 00 00         [24]  971 	mov	dptr,#0x0000
      00024C 75 F0 80         [24]  972 	mov	b, #0x80
      00024F 74 3F            [12]  973 	mov	a, #0x3f
      000251 02 04 C2         [24]  974 	ljmp	00121$
      000254                        975 00102$:
                           000197   976 	C$fuzzy.h$1032$1_0$38 ==.
                                    977 ;	../../fuzzy.h:1032: method != FUZZY_LOGIC_STANDARD &&
      000254 ED               [12]  978 	mov	a,r5
      000255 60 13            [24]  979 	jz	00105$
                           00019A   980 	C$fuzzy.h$1033$1_0$38 ==.
                                    981 ;	../../fuzzy.h:1033: method != FUZZY_LOGIC_ALGEBRAIC &&
      000257 BD 01 02         [24]  982 	cjne	r5,#0x01,00192$
      00025A 80 0E            [24]  983 	sjmp	00105$
      00025C                        984 00192$:
                           00019F   985 	C$fuzzy.h$1035$1_0$38 ==.
                                    986 ;	../../fuzzy.h:1035: ) {
      00025C BD 02 02         [24]  987 	cjne	r5,#0x02,00193$
      00025F 80 09            [24]  988 	sjmp	00105$
      000261                        989 00193$:
                           0001A4   990 	C$fuzzy.h$1036$2_0$40 ==.
                                    991 ;	../../fuzzy.h:1036: return LEVEL_LO;
      000261 90 00 00         [24]  992 	mov	dptr,#0x0000
      000264 E4               [12]  993 	clr	a
      000265 F5 F0            [12]  994 	mov	b,a
      000267 02 04 C2         [24]  995 	ljmp	00121$
      00026A                        996 00105$:
                           0001AD   997 	C$fuzzy.h$1041$1_0$38 ==.
                                    998 ;	../../fuzzy.h:1041: args[0]
      00026A E5 08            [12]  999 	mov	a,_bp
      00026C 24 F9            [12] 1000 	add	a,#0xf9
      00026E F8               [12] 1001 	mov	r0,a
      00026F A9 08            [24] 1002 	mov	r1,_bp
      000271 09               [12] 1003 	inc	r1
      000272 E6               [12] 1004 	mov	a,@r0
      000273 F7               [12] 1005 	mov	@r1,a
      000274 08               [12] 1006 	inc	r0
      000275 E6               [12] 1007 	mov	a,@r0
      000276 09               [12] 1008 	inc	r1
      000277 F7               [12] 1009 	mov	@r1,a
      000278 08               [12] 1010 	inc	r0
      000279 E6               [12] 1011 	mov	a,@r0
      00027A 09               [12] 1012 	inc	r1
      00027B F7               [12] 1013 	mov	@r1,a
      00027C A8 08            [24] 1014 	mov	r0,_bp
      00027E 08               [12] 1015 	inc	r0
      00027F 86 82            [24] 1016 	mov	dpl,@r0
      000281 08               [12] 1017 	inc	r0
      000282 86 83            [24] 1018 	mov	dph,@r0
      000284 08               [12] 1019 	inc	r0
      000285 86 F0            [24] 1020 	mov	b,@r0
      000287 12 43 A8         [24] 1021 	lcall	__gptrget
      00028A FA               [12] 1022 	mov	r2,a
      00028B A3               [24] 1023 	inc	dptr
      00028C 12 43 A8         [24] 1024 	lcall	__gptrget
      00028F FB               [12] 1025 	mov	r3,a
      000290 A3               [24] 1026 	inc	dptr
      000291 12 43 A8         [24] 1027 	lcall	__gptrget
      000294 FE               [12] 1028 	mov	r6,a
      000295 A3               [24] 1029 	inc	dptr
      000296 12 43 A8         [24] 1030 	lcall	__gptrget
      000299 8A 82            [24] 1031 	mov	dpl,r2
      00029B 8B 83            [24] 1032 	mov	dph,r3
      00029D 8E F0            [24] 1033 	mov	b,r6
      00029F C0 05            [24] 1034 	push	ar5
      0002A1 12 00 F0         [24] 1035 	lcall	_fuzzy_clamp
      0002A4 C8               [12] 1036 	xch	a,r0
      0002A5 E5 08            [12] 1037 	mov	a,_bp
      0002A7 24 05            [12] 1038 	add	a,#0x05
      0002A9 C8               [12] 1039 	xch	a,r0
      0002AA A6 82            [24] 1040 	mov	@r0, dpl
      0002AC 08               [12] 1041 	inc	r0
      0002AD A6 83            [24] 1042 	mov	@r0, dph
      0002AF 08               [12] 1043 	inc	r0
      0002B0 A6 F0            [24] 1044 	mov	@r0, b
      0002B2 08               [12] 1045 	inc	r0
      0002B3 F6               [12] 1046 	mov	@r0,a
      0002B4 D0 05            [24] 1047 	pop	ar5
                           0001F9  1048 	C$fuzzy.h$1045$3_0$42 ==.
                                   1049 ;	../../fuzzy.h:1045: index = 1u;
      0002B6 E4               [12] 1050 	clr	a
      0002B7 BD 00 01         [24] 1051 	cjne	r5,#0x00,00194$
      0002BA 04               [12] 1052 	inc	a
      0002BB                       1053 00194$:
      0002BB FB               [12] 1054 	mov	r3,a
      0002BC BD 01 03         [24] 1055 	cjne	r5,#0x01,00196$
      0002BF ED               [12] 1056 	mov	a,r5
      0002C0 80 01            [24] 1057 	sjmp	00197$
      0002C2                       1058 00196$:
      0002C2 E4               [12] 1059 	clr	a
      0002C3                       1060 00197$:
      0002C3 FA               [12] 1061 	mov	r2,a
      0002C4 E5 08            [12] 1062 	mov	a,_bp
      0002C6 24 04            [12] 1063 	add	a,#0x04
      0002C8 F8               [12] 1064 	mov	r0,a
      0002C9 E4               [12] 1065 	clr	a
      0002CA BD 02 01         [24] 1066 	cjne	r5,#0x02,00198$
      0002CD 04               [12] 1067 	inc	a
      0002CE                       1068 00198$:
      0002CE F6               [12] 1069 	mov	@r0,a
      0002CF E5 08            [12] 1070 	mov	a,_bp
      0002D1 24 0D            [12] 1071 	add	a,#0x0d
      0002D3 F8               [12] 1072 	mov	r0,a
      0002D4 76 01            [12] 1073 	mov	@r0,#0x01
      0002D6 08               [12] 1074 	inc	r0
      0002D7 76 00            [12] 1075 	mov	@r0,#0x00
      0002D9                       1076 00119$:
                           00021C  1077 	C$fuzzy.h$1046$2_0$41 ==.
                                   1078 ;	../../fuzzy.h:1046: index < count;
      0002D9 E5 08            [12] 1079 	mov	a,_bp
      0002DB 24 0D            [12] 1080 	add	a,#0x0d
      0002DD F8               [12] 1081 	mov	r0,a
      0002DE E5 08            [12] 1082 	mov	a,_bp
      0002E0 24 FC            [12] 1083 	add	a,#0xfc
      0002E2 F9               [12] 1084 	mov	r1,a
      0002E3 C3               [12] 1085 	clr	c
      0002E4 E6               [12] 1086 	mov	a,@r0
      0002E5 97               [12] 1087 	subb	a,@r1
      0002E6 08               [12] 1088 	inc	r0
      0002E7 E6               [12] 1089 	mov	a,@r0
      0002E8 09               [12] 1090 	inc	r1
      0002E9 97               [12] 1091 	subb	a,@r1
      0002EA 40 03            [24] 1092 	jc	00200$
      0002EC 02 04 B0         [24] 1093 	ljmp	00117$
      0002EF                       1094 00200$:
                           000232  1095 	C$fuzzy.h$1051$1_0$38 ==.
                                   1096 ;	../../fuzzy.h:1051: args[index]
      0002EF C0 02            [24] 1097 	push	ar2
      0002F1 E5 08            [12] 1098 	mov	a,_bp
      0002F3 24 0D            [12] 1099 	add	a,#0x0d
      0002F5 F8               [12] 1100 	mov	r0,a
      0002F6 E6               [12] 1101 	mov	a,@r0
      0002F7 26               [12] 1102 	add	a,@r0
      0002F8 FD               [12] 1103 	mov	r5,a
      0002F9 08               [12] 1104 	inc	r0
      0002FA E6               [12] 1105 	mov	a,@r0
      0002FB 33               [12] 1106 	rlc	a
      0002FC FC               [12] 1107 	mov	r4,a
      0002FD ED               [12] 1108 	mov	a,r5
      0002FE 2D               [12] 1109 	add	a,r5
      0002FF FD               [12] 1110 	mov	r5,a
      000300 EC               [12] 1111 	mov	a,r4
      000301 33               [12] 1112 	rlc	a
      000302 FC               [12] 1113 	mov	r4,a
      000303 A8 08            [24] 1114 	mov	r0,_bp
      000305 08               [12] 1115 	inc	r0
      000306 ED               [12] 1116 	mov	a,r5
      000307 26               [12] 1117 	add	a, @r0
      000308 FA               [12] 1118 	mov	r2,a
      000309 EC               [12] 1119 	mov	a,r4
      00030A 08               [12] 1120 	inc	r0
      00030B 36               [12] 1121 	addc	a, @r0
      00030C FC               [12] 1122 	mov	r4,a
      00030D 08               [12] 1123 	inc	r0
      00030E 86 05            [24] 1124 	mov	ar5,@r0
      000310 8A 82            [24] 1125 	mov	dpl,r2
      000312 8C 83            [24] 1126 	mov	dph,r4
      000314 8D F0            [24] 1127 	mov	b,r5
      000316 12 43 A8         [24] 1128 	lcall	__gptrget
      000319 FA               [12] 1129 	mov	r2,a
      00031A A3               [24] 1130 	inc	dptr
      00031B 12 43 A8         [24] 1131 	lcall	__gptrget
      00031E FC               [12] 1132 	mov	r4,a
      00031F A3               [24] 1133 	inc	dptr
      000320 12 43 A8         [24] 1134 	lcall	__gptrget
      000323 FD               [12] 1135 	mov	r5,a
      000324 A3               [24] 1136 	inc	dptr
      000325 12 43 A8         [24] 1137 	lcall	__gptrget
      000328 8A 82            [24] 1138 	mov	dpl,r2
      00032A 8C 83            [24] 1139 	mov	dph,r4
      00032C 8D F0            [24] 1140 	mov	b,r5
      00032E C0 03            [24] 1141 	push	ar3
      000330 C0 02            [24] 1142 	push	ar2
      000332 12 00 F0         [24] 1143 	lcall	_fuzzy_clamp
      000335 C8               [12] 1144 	xch	a,r0
      000336 E5 08            [12] 1145 	mov	a,_bp
      000338 24 09            [12] 1146 	add	a,#0x09
      00033A C8               [12] 1147 	xch	a,r0
      00033B A6 82            [24] 1148 	mov	@r0, dpl
      00033D 08               [12] 1149 	inc	r0
      00033E A6 83            [24] 1150 	mov	@r0, dph
      000340 08               [12] 1151 	inc	r0
      000341 A6 F0            [24] 1152 	mov	@r0, b
      000343 08               [12] 1153 	inc	r0
      000344 F6               [12] 1154 	mov	@r0,a
      000345 D0 02            [24] 1155 	pop	ar2
      000347 D0 03            [24] 1156 	pop	ar3
                           00028C  1157 	C$fuzzy.h$1054$1_0$38 ==.
                                   1158 ;	../../fuzzy.h:1054: switch (method) {
      000349 D0 02            [24] 1159 	pop	ar2
      00034B EB               [12] 1160 	mov	a,r3
      00034C 70 11            [24] 1161 	jnz	00108$
      00034E EA               [12] 1162 	mov	a,r2
      00034F 70 65            [24] 1163 	jnz	00111$
      000351 E5 08            [12] 1164 	mov	a,_bp
      000353 24 04            [12] 1165 	add	a,#0x04
      000355 F8               [12] 1166 	mov	r0,a
      000356 E6               [12] 1167 	mov	a,@r0
      000357 60 03            [24] 1168 	jz	00203$
      000359 02 03 FD         [24] 1169 	ljmp	00112$
      00035C                       1170 00203$:
      00035C 02 04 9A         [24] 1171 	ljmp	00115$
                           0002A2  1172 	C$fuzzy.h$1055$4_0$43 ==.
                                   1173 ;	../../fuzzy.h:1055: case FUZZY_LOGIC_STANDARD:
      00035F                       1174 00108$:
                           0002A2  1175 	C$fuzzy.h$1056$1_0$38 ==.
                                   1176 ;	../../fuzzy.h:1056: if (next < result) {
      00035F C0 03            [24] 1177 	push	ar3
      000361 C0 02            [24] 1178 	push	ar2
      000363 E5 08            [12] 1179 	mov	a,_bp
      000365 24 05            [12] 1180 	add	a,#0x05
      000367 F8               [12] 1181 	mov	r0,a
      000368 E6               [12] 1182 	mov	a,@r0
      000369 C0 E0            [24] 1183 	push	acc
      00036B 08               [12] 1184 	inc	r0
      00036C E6               [12] 1185 	mov	a,@r0
      00036D C0 E0            [24] 1186 	push	acc
      00036F 08               [12] 1187 	inc	r0
      000370 E6               [12] 1188 	mov	a,@r0
      000371 C0 E0            [24] 1189 	push	acc
      000373 08               [12] 1190 	inc	r0
      000374 E6               [12] 1191 	mov	a,@r0
      000375 C0 E0            [24] 1192 	push	acc
      000377 E5 08            [12] 1193 	mov	a,_bp
      000379 24 09            [12] 1194 	add	a,#0x09
      00037B F8               [12] 1195 	mov	r0,a
      00037C 86 82            [24] 1196 	mov	dpl, @r0
      00037E 08               [12] 1197 	inc	r0
      00037F 86 83            [24] 1198 	mov	dph, @r0
      000381 08               [12] 1199 	inc	r0
      000382 86 F0            [24] 1200 	mov	b, @r0
      000384 08               [12] 1201 	inc	r0
      000385 E6               [12] 1202 	mov	a, @r0
      000386 12 41 7C         [24] 1203 	lcall	___fslt
      000389 AF 82            [24] 1204 	mov	r7, dpl
      00038B E5 81            [12] 1205 	mov	a,sp
      00038D 24 FC            [12] 1206 	add	a,#0xfc
      00038F F5 81            [12] 1207 	mov	sp,a
      000391 D0 02            [24] 1208 	pop	ar2
      000393 D0 03            [24] 1209 	pop	ar3
      000395 EF               [12] 1210 	mov	a,r7
      000396 70 03            [24] 1211 	jnz	00204$
      000398 02 04 A2         [24] 1212 	ljmp	00120$
      00039B                       1213 00204$:
                           0002DE  1214 	C$fuzzy.h$1057$5_0$44 ==.
                                   1215 ;	../../fuzzy.h:1057: result = next;
      00039B E5 08            [12] 1216 	mov	a,_bp
      00039D 24 09            [12] 1217 	add	a,#0x09
      00039F F8               [12] 1218 	mov	r0,a
      0003A0 E5 08            [12] 1219 	mov	a,_bp
      0003A2 24 05            [12] 1220 	add	a,#0x05
      0003A4 F9               [12] 1221 	mov	r1,a
      0003A5 E6               [12] 1222 	mov	a,@r0
      0003A6 F7               [12] 1223 	mov	@r1,a
      0003A7 08               [12] 1224 	inc	r0
      0003A8 E6               [12] 1225 	mov	a,@r0
      0003A9 09               [12] 1226 	inc	r1
      0003AA F7               [12] 1227 	mov	@r1,a
      0003AB 08               [12] 1228 	inc	r0
      0003AC E6               [12] 1229 	mov	a,@r0
      0003AD 09               [12] 1230 	inc	r1
      0003AE F7               [12] 1231 	mov	@r1,a
      0003AF 08               [12] 1232 	inc	r0
      0003B0 E6               [12] 1233 	mov	a,@r0
      0003B1 09               [12] 1234 	inc	r1
      0003B2 F7               [12] 1235 	mov	@r1,a
                           0002F6  1236 	C$fuzzy.h$1059$4_0$43 ==.
                                   1237 ;	../../fuzzy.h:1059: break;
      0003B3 02 04 A2         [24] 1238 	ljmp	00120$
                           0002F9  1239 	C$fuzzy.h$1061$4_0$43 ==.
                                   1240 ;	../../fuzzy.h:1061: case FUZZY_LOGIC_ALGEBRAIC:
      0003B6                       1241 00111$:
                           0002F9  1242 	C$fuzzy.h$1063$1_0$38 ==.
                                   1243 ;	../../fuzzy.h:1063: next;
      0003B6 C0 03            [24] 1244 	push	ar3
      0003B8 C0 02            [24] 1245 	push	ar2
      0003BA E5 08            [12] 1246 	mov	a,_bp
      0003BC 24 09            [12] 1247 	add	a,#0x09
      0003BE F8               [12] 1248 	mov	r0,a
      0003BF E6               [12] 1249 	mov	a,@r0
      0003C0 C0 E0            [24] 1250 	push	acc
      0003C2 08               [12] 1251 	inc	r0
      0003C3 E6               [12] 1252 	mov	a,@r0
      0003C4 C0 E0            [24] 1253 	push	acc
      0003C6 08               [12] 1254 	inc	r0
      0003C7 E6               [12] 1255 	mov	a,@r0
      0003C8 C0 E0            [24] 1256 	push	acc
      0003CA 08               [12] 1257 	inc	r0
      0003CB E6               [12] 1258 	mov	a,@r0
      0003CC C0 E0            [24] 1259 	push	acc
                           000311  1260 	C$fuzzy.h$1064$1_0$38 ==.
                                   1261 ;	../../fuzzy.h:1064: break;
      0003CE E5 08            [12] 1262 	mov	a,_bp
      0003D0 24 05            [12] 1263 	add	a,#0x05
      0003D2 F8               [12] 1264 	mov	r0,a
      0003D3 86 82            [24] 1265 	mov	dpl, @r0
      0003D5 08               [12] 1266 	inc	r0
      0003D6 86 83            [24] 1267 	mov	dph, @r0
      0003D8 08               [12] 1268 	inc	r0
      0003D9 86 F0            [24] 1269 	mov	b, @r0
      0003DB 08               [12] 1270 	inc	r0
      0003DC E6               [12] 1271 	mov	a, @r0
      0003DD 12 40 4C         [24] 1272 	lcall	___fsmul
      0003E0 C8               [12] 1273 	xch	a,r0
      0003E1 E5 08            [12] 1274 	mov	a,_bp
      0003E3 24 05            [12] 1275 	add	a,#0x05
      0003E5 C8               [12] 1276 	xch	a,r0
      0003E6 A6 82            [24] 1277 	mov	@r0, dpl
      0003E8 08               [12] 1278 	inc	r0
      0003E9 A6 83            [24] 1279 	mov	@r0, dph
      0003EB 08               [12] 1280 	inc	r0
      0003EC A6 F0            [24] 1281 	mov	@r0, b
      0003EE 08               [12] 1282 	inc	r0
      0003EF F6               [12] 1283 	mov	@r0,a
      0003F0 E5 81            [12] 1284 	mov	a,sp
      0003F2 24 FC            [12] 1285 	add	a,#0xfc
      0003F4 F5 81            [12] 1286 	mov	sp,a
      0003F6 D0 02            [24] 1287 	pop	ar2
      0003F8 D0 03            [24] 1288 	pop	ar3
      0003FA 02 04 A2         [24] 1289 	ljmp	00120$
                           000340  1290 	C$fuzzy.h$1066$4_0$43 ==.
                                   1291 ;	../../fuzzy.h:1066: case FUZZY_LOGIC_BOUNDED:
      0003FD                       1292 00112$:
                           000340  1293 	C$fuzzy.h$1069$1_0$38 ==.
                                   1294 ;	../../fuzzy.h:1069: next -
      0003FD C0 03            [24] 1295 	push	ar3
      0003FF C0 02            [24] 1296 	push	ar2
      000401 E5 08            [12] 1297 	mov	a,_bp
      000403 24 09            [12] 1298 	add	a,#0x09
      000405 F8               [12] 1299 	mov	r0,a
      000406 E6               [12] 1300 	mov	a,@r0
      000407 C0 E0            [24] 1301 	push	acc
      000409 08               [12] 1302 	inc	r0
      00040A E6               [12] 1303 	mov	a,@r0
      00040B C0 E0            [24] 1304 	push	acc
      00040D 08               [12] 1305 	inc	r0
      00040E E6               [12] 1306 	mov	a,@r0
      00040F C0 E0            [24] 1307 	push	acc
      000411 08               [12] 1308 	inc	r0
      000412 E6               [12] 1309 	mov	a,@r0
      000413 C0 E0            [24] 1310 	push	acc
      000415 E5 08            [12] 1311 	mov	a,_bp
      000417 24 05            [12] 1312 	add	a,#0x05
      000419 F8               [12] 1313 	mov	r0,a
      00041A 86 82            [24] 1314 	mov	dpl, @r0
      00041C 08               [12] 1315 	inc	r0
      00041D 86 83            [24] 1316 	mov	dph, @r0
      00041F 08               [12] 1317 	inc	r0
      000420 86 F0            [24] 1318 	mov	b, @r0
      000422 08               [12] 1319 	inc	r0
      000423 E6               [12] 1320 	mov	a, @r0
      000424 12 41 CE         [24] 1321 	lcall	___fsadd
      000427 AC 82            [24] 1322 	mov	r4, dpl
      000429 AD 83            [24] 1323 	mov	r5, dph
      00042B AE F0            [24] 1324 	mov	r6, b
      00042D FF               [12] 1325 	mov	r7, a
      00042E E5 81            [12] 1326 	mov	a,sp
      000430 24 FC            [12] 1327 	add	a,#0xfc
      000432 F5 81            [12] 1328 	mov	sp,a
      000434 E4               [12] 1329 	clr	a
      000435 C0 E0            [24] 1330 	push	acc
      000437 C0 E0            [24] 1331 	push	acc
      000439 74 80            [12] 1332 	mov	a,#0x80
      00043B C0 E0            [24] 1333 	push	acc
      00043D 74 3F            [12] 1334 	mov	a,#0x3f
      00043F C0 E0            [24] 1335 	push	acc
                           000384  1336 	C$fuzzy.h$1072$1_0$38 ==.
                                   1337 ;	../../fuzzy.h:1072: if (result < LEVEL_LO) {
      000441 8C 82            [24] 1338 	mov	dpl, r4
      000443 8D 83            [24] 1339 	mov	dph, r5
      000445 8E F0            [24] 1340 	mov	b, r6
      000447 EF               [12] 1341 	mov	a, r7
      000448 12 40 41         [24] 1342 	lcall	___fssub
      00044B C8               [12] 1343 	xch	a,r0
      00044C E5 08            [12] 1344 	mov	a,_bp
      00044E 24 05            [12] 1345 	add	a,#0x05
      000450 C8               [12] 1346 	xch	a,r0
      000451 A6 82            [24] 1347 	mov	@r0, dpl
      000453 08               [12] 1348 	inc	r0
      000454 A6 83            [24] 1349 	mov	@r0, dph
      000456 08               [12] 1350 	inc	r0
      000457 A6 F0            [24] 1351 	mov	@r0, b
      000459 08               [12] 1352 	inc	r0
      00045A F6               [12] 1353 	mov	@r0,a
      00045B E5 81            [12] 1354 	mov	a,sp
      00045D 24 FC            [12] 1355 	add	a,#0xfc
      00045F F5 81            [12] 1356 	mov	sp,a
      000461 E4               [12] 1357 	clr	a
      000462 C0 E0            [24] 1358 	push	acc
      000464 C0 E0            [24] 1359 	push	acc
      000466 C0 E0            [24] 1360 	push	acc
      000468 C0 E0            [24] 1361 	push	acc
      00046A E5 08            [12] 1362 	mov	a,_bp
      00046C 24 05            [12] 1363 	add	a,#0x05
      00046E F8               [12] 1364 	mov	r0,a
      00046F 86 82            [24] 1365 	mov	dpl, @r0
      000471 08               [12] 1366 	inc	r0
      000472 86 83            [24] 1367 	mov	dph, @r0
      000474 08               [12] 1368 	inc	r0
      000475 86 F0            [24] 1369 	mov	b, @r0
      000477 08               [12] 1370 	inc	r0
      000478 E6               [12] 1371 	mov	a, @r0
      000479 12 41 7C         [24] 1372 	lcall	___fslt
      00047C AF 82            [24] 1373 	mov	r7, dpl
      00047E E5 81            [12] 1374 	mov	a,sp
      000480 24 FC            [12] 1375 	add	a,#0xfc
      000482 F5 81            [12] 1376 	mov	sp,a
      000484 D0 02            [24] 1377 	pop	ar2
      000486 D0 03            [24] 1378 	pop	ar3
      000488 EF               [12] 1379 	mov	a,r7
      000489 60 17            [24] 1380 	jz	00120$
                           0003CE  1381 	C$fuzzy.h$1073$5_0$45 ==.
                                   1382 ;	../../fuzzy.h:1073: result = LEVEL_LO;
      00048B E5 08            [12] 1383 	mov	a,_bp
      00048D 24 05            [12] 1384 	add	a,#0x05
      00048F F8               [12] 1385 	mov	r0,a
      000490 E4               [12] 1386 	clr	a
      000491 F6               [12] 1387 	mov	@r0,a
      000492 08               [12] 1388 	inc	r0
      000493 F6               [12] 1389 	mov	@r0,a
      000494 08               [12] 1390 	inc	r0
      000495 F6               [12] 1391 	mov	@r0,a
      000496 08               [12] 1392 	inc	r0
      000497 F6               [12] 1393 	mov	@r0,a
                           0003DB  1394 	C$fuzzy.h$1075$4_0$43 ==.
                                   1395 ;	../../fuzzy.h:1075: break;
                           0003DB  1396 	C$fuzzy.h$1077$4_0$43 ==.
                                   1397 ;	../../fuzzy.h:1077: default:
      000498 80 08            [24] 1398 	sjmp	00120$
      00049A                       1399 00115$:
                           0003DD  1400 	C$fuzzy.h$1078$4_0$43 ==.
                                   1401 ;	../../fuzzy.h:1078: return LEVEL_LO;
      00049A 90 00 00         [24] 1402 	mov	dptr,#0x0000
      00049D E4               [12] 1403 	clr	a
      00049E F5 F0            [12] 1404 	mov	b,a
                           0003E3  1405 	C$fuzzy.h$1079$3_0$42 ==.
                                   1406 ;	../../fuzzy.h:1079: }
      0004A0 80 20            [24] 1407 	sjmp	00121$
      0004A2                       1408 00120$:
                           0003E5  1409 	C$fuzzy.h$1047$2_0$41 ==.
                                   1410 ;	../../fuzzy.h:1047: index++
      0004A2 E5 08            [12] 1411 	mov	a,_bp
      0004A4 24 0D            [12] 1412 	add	a,#0x0d
      0004A6 F8               [12] 1413 	mov	r0,a
      0004A7 06               [12] 1414 	inc	@r0
      0004A8 B6 00 02         [24] 1415 	cjne	@r0,#0x00,00206$
      0004AB 08               [12] 1416 	inc	r0
      0004AC 06               [12] 1417 	inc	@r0
      0004AD                       1418 00206$:
      0004AD 02 02 D9         [24] 1419 	ljmp	00119$
      0004B0                       1420 00117$:
                           0003F3  1421 	C$fuzzy.h$1083$1_0$38 ==.
                                   1422 ;	../../fuzzy.h:1083: result
      0004B0 E5 08            [12] 1423 	mov	a,_bp
      0004B2 24 05            [12] 1424 	add	a,#0x05
      0004B4 F8               [12] 1425 	mov	r0,a
      0004B5 86 82            [24] 1426 	mov	dpl, @r0
      0004B7 08               [12] 1427 	inc	r0
      0004B8 86 83            [24] 1428 	mov	dph, @r0
      0004BA 08               [12] 1429 	inc	r0
      0004BB 86 F0            [24] 1430 	mov	b, @r0
      0004BD 08               [12] 1431 	inc	r0
      0004BE E6               [12] 1432 	mov	a, @r0
      0004BF 12 00 F0         [24] 1433 	lcall	_fuzzy_clamp
      0004C2                       1434 00121$:
                           000405  1435 	C$fuzzy.h$1085$1_0$38 ==.
                                   1436 ;	../../fuzzy.h:1085: }
      0004C2 85 08 81         [24] 1437 	mov	sp,_bp
      0004C5 D0 08            [24] 1438 	pop	_bp
                           00040A  1439 	C$fuzzy.h$1085$1_0$38 ==.
                           00040A  1440 	XG$fuzzy_and_array$0$0 ==.
      0004C7 22               [24] 1441 	ret
                                   1442 ;------------------------------------------------------------
                                   1443 ;Allocation info for local variables in function 'fuzzy_or_array'
                                   1444 ;------------------------------------------------------------
                                   1445 ;count         Allocated to stack - _bp -4 +2 
                                   1446 ;args          Allocated to stack - _bp -7 +3 
                                   1447 ;method        Allocated to registers r5 
                                   1448 ;result        Allocated to stack - _bp +10 +4 
                                   1449 ;next          Allocated to registers r4 r5 r6 r3 
                                   1450 ;index         Allocated to stack - _bp +14 +2 
                                   1451 ;sloc0         Allocated to stack - _bp +1 +3 
                                   1452 ;sloc1         Allocated to stack - _bp +4 +1 
                                   1453 ;sloc2         Allocated to stack - _bp +5 +1 
                                   1454 ;sloc3         Allocated to stack - _bp +6 +4 
                                   1455 ;------------------------------------------------------------
                           00040B  1456 	G$fuzzy_or_array$0$0 ==.
                           00040B  1457 	C$fuzzy.h$1100$1_0$47 ==.
                                   1458 ;	../../fuzzy.h:1100: float fuzzy_or_array(
                                   1459 ;	-----------------------------------------
                                   1460 ;	 function fuzzy_or_array
                                   1461 ;	-----------------------------------------
      0004C8                       1462 _fuzzy_or_array:
      0004C8 C0 08            [24] 1463 	push	_bp
      0004CA E5 81            [12] 1464 	mov	a,sp
      0004CC F5 08            [12] 1465 	mov	_bp,a
      0004CE 24 0F            [12] 1466 	add	a,#0x0f
      0004D0 F5 81            [12] 1467 	mov	sp,a
      0004D2 AD 82            [24] 1468 	mov	r5, dpl
                           000417  1469 	C$fuzzy.h$1111$1_0$47 ==.
                                   1470 ;	../../fuzzy.h:1111: args == NULL ||
      0004D4 E5 08            [12] 1471 	mov	a,_bp
      0004D6 24 F9            [12] 1472 	add	a,#0xf9
      0004D8 F8               [12] 1473 	mov	r0,a
      0004D9 E6               [12] 1474 	mov	a,@r0
      0004DA 08               [12] 1475 	inc	r0
      0004DB 46               [12] 1476 	orl	a,@r0
      0004DC 60 0A            [24] 1477 	jz	00101$
                           000421  1478 	C$fuzzy.h$1112$1_0$47 ==.
                                   1479 ;	../../fuzzy.h:1112: count == 0u
      0004DE E5 08            [12] 1480 	mov	a,_bp
      0004E0 24 FC            [12] 1481 	add	a,#0xfc
      0004E2 F8               [12] 1482 	mov	r0,a
      0004E3 E6               [12] 1483 	mov	a,@r0
      0004E4 08               [12] 1484 	inc	r0
      0004E5 46               [12] 1485 	orl	a,@r0
      0004E6 70 09            [24] 1486 	jnz	00102$
      0004E8                       1487 00101$:
                           00042B  1488 	C$fuzzy.h$1114$2_0$48 ==.
                                   1489 ;	../../fuzzy.h:1114: return LEVEL_LO;
      0004E8 90 00 00         [24] 1490 	mov	dptr,#0x0000
      0004EB E4               [12] 1491 	clr	a
      0004EC F5 F0            [12] 1492 	mov	b,a
      0004EE 02 07 84         [24] 1493 	ljmp	00121$
      0004F1                       1494 00102$:
                           000434  1495 	C$fuzzy.h$1118$1_0$47 ==.
                                   1496 ;	../../fuzzy.h:1118: method != FUZZY_LOGIC_STANDARD &&
      0004F1 ED               [12] 1497 	mov	a,r5
      0004F2 60 13            [24] 1498 	jz	00105$
                           000437  1499 	C$fuzzy.h$1119$1_0$47 ==.
                                   1500 ;	../../fuzzy.h:1119: method != FUZZY_LOGIC_ALGEBRAIC &&
      0004F4 BD 01 02         [24] 1501 	cjne	r5,#0x01,00192$
      0004F7 80 0E            [24] 1502 	sjmp	00105$
      0004F9                       1503 00192$:
                           00043C  1504 	C$fuzzy.h$1121$1_0$47 ==.
                                   1505 ;	../../fuzzy.h:1121: ) {
      0004F9 BD 02 02         [24] 1506 	cjne	r5,#0x02,00193$
      0004FC 80 09            [24] 1507 	sjmp	00105$
      0004FE                       1508 00193$:
                           000441  1509 	C$fuzzy.h$1122$2_0$49 ==.
                                   1510 ;	../../fuzzy.h:1122: return LEVEL_LO;
      0004FE 90 00 00         [24] 1511 	mov	dptr,#0x0000
      000501 E4               [12] 1512 	clr	a
      000502 F5 F0            [12] 1513 	mov	b,a
      000504 02 07 84         [24] 1514 	ljmp	00121$
      000507                       1515 00105$:
                           00044A  1516 	C$fuzzy.h$1127$1_0$47 ==.
                                   1517 ;	../../fuzzy.h:1127: args[0]
      000507 E5 08            [12] 1518 	mov	a,_bp
      000509 24 F9            [12] 1519 	add	a,#0xf9
      00050B F8               [12] 1520 	mov	r0,a
      00050C A9 08            [24] 1521 	mov	r1,_bp
      00050E 09               [12] 1522 	inc	r1
      00050F E6               [12] 1523 	mov	a,@r0
      000510 F7               [12] 1524 	mov	@r1,a
      000511 08               [12] 1525 	inc	r0
      000512 E6               [12] 1526 	mov	a,@r0
      000513 09               [12] 1527 	inc	r1
      000514 F7               [12] 1528 	mov	@r1,a
      000515 08               [12] 1529 	inc	r0
      000516 E6               [12] 1530 	mov	a,@r0
      000517 09               [12] 1531 	inc	r1
      000518 F7               [12] 1532 	mov	@r1,a
      000519 A8 08            [24] 1533 	mov	r0,_bp
      00051B 08               [12] 1534 	inc	r0
      00051C 86 82            [24] 1535 	mov	dpl,@r0
      00051E 08               [12] 1536 	inc	r0
      00051F 86 83            [24] 1537 	mov	dph,@r0
      000521 08               [12] 1538 	inc	r0
      000522 86 F0            [24] 1539 	mov	b,@r0
      000524 12 43 A8         [24] 1540 	lcall	__gptrget
      000527 FA               [12] 1541 	mov	r2,a
      000528 A3               [24] 1542 	inc	dptr
      000529 12 43 A8         [24] 1543 	lcall	__gptrget
      00052C FB               [12] 1544 	mov	r3,a
      00052D A3               [24] 1545 	inc	dptr
      00052E 12 43 A8         [24] 1546 	lcall	__gptrget
      000531 FE               [12] 1547 	mov	r6,a
      000532 A3               [24] 1548 	inc	dptr
      000533 12 43 A8         [24] 1549 	lcall	__gptrget
      000536 8A 82            [24] 1550 	mov	dpl,r2
      000538 8B 83            [24] 1551 	mov	dph,r3
      00053A 8E F0            [24] 1552 	mov	b,r6
      00053C C0 05            [24] 1553 	push	ar5
      00053E 12 00 F0         [24] 1554 	lcall	_fuzzy_clamp
      000541 C8               [12] 1555 	xch	a,r0
      000542 E5 08            [12] 1556 	mov	a,_bp
      000544 24 0A            [12] 1557 	add	a,#0x0a
      000546 C8               [12] 1558 	xch	a,r0
      000547 A6 82            [24] 1559 	mov	@r0, dpl
      000549 08               [12] 1560 	inc	r0
      00054A A6 83            [24] 1561 	mov	@r0, dph
      00054C 08               [12] 1562 	inc	r0
      00054D A6 F0            [24] 1563 	mov	@r0, b
      00054F 08               [12] 1564 	inc	r0
      000550 F6               [12] 1565 	mov	@r0,a
      000551 D0 05            [24] 1566 	pop	ar5
                           000496  1567 	C$fuzzy.h$1131$3_0$51 ==.
                                   1568 ;	../../fuzzy.h:1131: index = 1u;
      000553 E5 08            [12] 1569 	mov	a,_bp
      000555 24 05            [12] 1570 	add	a,#0x05
      000557 F8               [12] 1571 	mov	r0,a
      000558 E4               [12] 1572 	clr	a
      000559 BD 00 01         [24] 1573 	cjne	r5,#0x00,00194$
      00055C 04               [12] 1574 	inc	a
      00055D                       1575 00194$:
      00055D F6               [12] 1576 	mov	@r0,a
      00055E BD 01 03         [24] 1577 	cjne	r5,#0x01,00196$
      000561 ED               [12] 1578 	mov	a,r5
      000562 80 01            [24] 1579 	sjmp	00197$
      000564                       1580 00196$:
      000564 E4               [12] 1581 	clr	a
      000565                       1582 00197$:
      000565 FA               [12] 1583 	mov	r2,a
      000566 E5 08            [12] 1584 	mov	a,_bp
      000568 24 04            [12] 1585 	add	a,#0x04
      00056A F8               [12] 1586 	mov	r0,a
      00056B E4               [12] 1587 	clr	a
      00056C BD 02 01         [24] 1588 	cjne	r5,#0x02,00198$
      00056F 04               [12] 1589 	inc	a
      000570                       1590 00198$:
      000570 F6               [12] 1591 	mov	@r0,a
      000571 E5 08            [12] 1592 	mov	a,_bp
      000573 24 0E            [12] 1593 	add	a,#0x0e
      000575 F8               [12] 1594 	mov	r0,a
      000576 76 01            [12] 1595 	mov	@r0,#0x01
      000578 08               [12] 1596 	inc	r0
      000579 76 00            [12] 1597 	mov	@r0,#0x00
      00057B                       1598 00119$:
                           0004BE  1599 	C$fuzzy.h$1132$2_0$50 ==.
                                   1600 ;	../../fuzzy.h:1132: index < count;
      00057B E5 08            [12] 1601 	mov	a,_bp
      00057D 24 0E            [12] 1602 	add	a,#0x0e
      00057F F8               [12] 1603 	mov	r0,a
      000580 E5 08            [12] 1604 	mov	a,_bp
      000582 24 FC            [12] 1605 	add	a,#0xfc
      000584 F9               [12] 1606 	mov	r1,a
      000585 C3               [12] 1607 	clr	c
      000586 E6               [12] 1608 	mov	a,@r0
      000587 97               [12] 1609 	subb	a,@r1
      000588 08               [12] 1610 	inc	r0
      000589 E6               [12] 1611 	mov	a,@r0
      00058A 09               [12] 1612 	inc	r1
      00058B 97               [12] 1613 	subb	a,@r1
      00058C 40 03            [24] 1614 	jc	00200$
      00058E 02 07 72         [24] 1615 	ljmp	00117$
      000591                       1616 00200$:
                           0004D4  1617 	C$fuzzy.h$1137$1_0$47 ==.
                                   1618 ;	../../fuzzy.h:1137: args[index]
      000591 C0 02            [24] 1619 	push	ar2
      000593 E5 08            [12] 1620 	mov	a,_bp
      000595 24 0E            [12] 1621 	add	a,#0x0e
      000597 F8               [12] 1622 	mov	r0,a
      000598 E6               [12] 1623 	mov	a,@r0
      000599 26               [12] 1624 	add	a,@r0
      00059A FD               [12] 1625 	mov	r5,a
      00059B 08               [12] 1626 	inc	r0
      00059C E6               [12] 1627 	mov	a,@r0
      00059D 33               [12] 1628 	rlc	a
      00059E FC               [12] 1629 	mov	r4,a
      00059F ED               [12] 1630 	mov	a,r5
      0005A0 2D               [12] 1631 	add	a,r5
      0005A1 FD               [12] 1632 	mov	r5,a
      0005A2 EC               [12] 1633 	mov	a,r4
      0005A3 33               [12] 1634 	rlc	a
      0005A4 FC               [12] 1635 	mov	r4,a
      0005A5 A8 08            [24] 1636 	mov	r0,_bp
      0005A7 08               [12] 1637 	inc	r0
      0005A8 ED               [12] 1638 	mov	a,r5
      0005A9 26               [12] 1639 	add	a, @r0
      0005AA FA               [12] 1640 	mov	r2,a
      0005AB EC               [12] 1641 	mov	a,r4
      0005AC 08               [12] 1642 	inc	r0
      0005AD 36               [12] 1643 	addc	a, @r0
      0005AE FC               [12] 1644 	mov	r4,a
      0005AF 08               [12] 1645 	inc	r0
      0005B0 86 05            [24] 1646 	mov	ar5,@r0
      0005B2 8A 82            [24] 1647 	mov	dpl,r2
      0005B4 8C 83            [24] 1648 	mov	dph,r4
      0005B6 8D F0            [24] 1649 	mov	b,r5
      0005B8 12 43 A8         [24] 1650 	lcall	__gptrget
      0005BB FA               [12] 1651 	mov	r2,a
      0005BC A3               [24] 1652 	inc	dptr
      0005BD 12 43 A8         [24] 1653 	lcall	__gptrget
      0005C0 FC               [12] 1654 	mov	r4,a
      0005C1 A3               [24] 1655 	inc	dptr
      0005C2 12 43 A8         [24] 1656 	lcall	__gptrget
      0005C5 FD               [12] 1657 	mov	r5,a
      0005C6 A3               [24] 1658 	inc	dptr
      0005C7 12 43 A8         [24] 1659 	lcall	__gptrget
      0005CA 8A 82            [24] 1660 	mov	dpl,r2
      0005CC 8C 83            [24] 1661 	mov	dph,r4
      0005CE 8D F0            [24] 1662 	mov	b,r5
      0005D0 C0 02            [24] 1663 	push	ar2
      0005D2 12 00 F0         [24] 1664 	lcall	_fuzzy_clamp
      0005D5 AC 82            [24] 1665 	mov	r4, dpl
      0005D7 AD 83            [24] 1666 	mov	r5, dph
      0005D9 AE F0            [24] 1667 	mov	r6, b
      0005DB FB               [12] 1668 	mov	r3, a
      0005DC D0 02            [24] 1669 	pop	ar2
                           000521  1670 	C$fuzzy.h$1140$1_0$47 ==.
                                   1671 ;	../../fuzzy.h:1140: switch (method) {
      0005DE D0 02            [24] 1672 	pop	ar2
      0005E0 E5 08            [12] 1673 	mov	a,_bp
      0005E2 24 05            [12] 1674 	add	a,#0x05
      0005E4 F8               [12] 1675 	mov	r0,a
      0005E5 E6               [12] 1676 	mov	a,@r0
      0005E6 70 11            [24] 1677 	jnz	00108$
      0005E8 EA               [12] 1678 	mov	a,r2
      0005E9 70 5D            [24] 1679 	jnz	00111$
      0005EB E5 08            [12] 1680 	mov	a,_bp
      0005ED 24 04            [12] 1681 	add	a,#0x04
      0005EF F8               [12] 1682 	mov	r0,a
      0005F0 E6               [12] 1683 	mov	a,@r0
      0005F1 60 03            [24] 1684 	jz	00203$
      0005F3 02 06 ED         [24] 1685 	ljmp	00112$
      0005F6                       1686 00203$:
      0005F6 02 07 5C         [24] 1687 	ljmp	00115$
                           00053C  1688 	C$fuzzy.h$1141$4_0$52 ==.
                                   1689 ;	../../fuzzy.h:1141: case FUZZY_LOGIC_STANDARD:
      0005F9                       1690 00108$:
                           00053C  1691 	C$fuzzy.h$1142$1_0$47 ==.
                                   1692 ;	../../fuzzy.h:1142: if (next > result) {
      0005F9 C0 06            [24] 1693 	push	ar6
      0005FB C0 05            [24] 1694 	push	ar5
      0005FD C0 04            [24] 1695 	push	ar4
      0005FF C0 03            [24] 1696 	push	ar3
      000601 C0 02            [24] 1697 	push	ar2
      000603 C0 04            [24] 1698 	push	ar4
      000605 C0 05            [24] 1699 	push	ar5
      000607 C0 06            [24] 1700 	push	ar6
      000609 C0 03            [24] 1701 	push	ar3
      00060B E5 08            [12] 1702 	mov	a,_bp
      00060D 24 0A            [12] 1703 	add	a,#0x0a
      00060F F8               [12] 1704 	mov	r0,a
      000610 86 82            [24] 1705 	mov	dpl, @r0
      000612 08               [12] 1706 	inc	r0
      000613 86 83            [24] 1707 	mov	dph, @r0
      000615 08               [12] 1708 	inc	r0
      000616 86 F0            [24] 1709 	mov	b, @r0
      000618 08               [12] 1710 	inc	r0
      000619 E6               [12] 1711 	mov	a, @r0
      00061A 12 41 7C         [24] 1712 	lcall	___fslt
      00061D AF 82            [24] 1713 	mov	r7, dpl
      00061F E5 81            [12] 1714 	mov	a,sp
      000621 24 FC            [12] 1715 	add	a,#0xfc
      000623 F5 81            [12] 1716 	mov	sp,a
      000625 D0 02            [24] 1717 	pop	ar2
      000627 D0 03            [24] 1718 	pop	ar3
      000629 D0 04            [24] 1719 	pop	ar4
      00062B D0 05            [24] 1720 	pop	ar5
      00062D D0 06            [24] 1721 	pop	ar6
      00062F EF               [12] 1722 	mov	a,r7
      000630 70 03            [24] 1723 	jnz	00204$
      000632 02 07 64         [24] 1724 	ljmp	00120$
      000635                       1725 00204$:
                           000578  1726 	C$fuzzy.h$1143$5_0$53 ==.
                                   1727 ;	../../fuzzy.h:1143: result = next;
      000635 E5 08            [12] 1728 	mov	a,_bp
      000637 24 0A            [12] 1729 	add	a,#0x0a
      000639 F8               [12] 1730 	mov	r0,a
      00063A A6 04            [24] 1731 	mov	@r0,ar4
      00063C 08               [12] 1732 	inc	r0
      00063D A6 05            [24] 1733 	mov	@r0,ar5
      00063F 08               [12] 1734 	inc	r0
      000640 A6 06            [24] 1735 	mov	@r0,ar6
      000642 08               [12] 1736 	inc	r0
      000643 A6 03            [24] 1737 	mov	@r0,ar3
                           000588  1738 	C$fuzzy.h$1145$4_0$52 ==.
                                   1739 ;	../../fuzzy.h:1145: break;
      000645 02 07 64         [24] 1740 	ljmp	00120$
                           00058B  1741 	C$fuzzy.h$1147$4_0$52 ==.
                                   1742 ;	../../fuzzy.h:1147: case FUZZY_LOGIC_ALGEBRAIC:
      000648                       1743 00111$:
                           00058B  1744 	C$fuzzy.h$1150$1_0$47 ==.
                                   1745 ;	../../fuzzy.h:1150: next -
      000648 C0 02            [24] 1746 	push	ar2
      00064A C0 06            [24] 1747 	push	ar6
      00064C C0 05            [24] 1748 	push	ar5
      00064E C0 04            [24] 1749 	push	ar4
      000650 C0 03            [24] 1750 	push	ar3
      000652 C0 02            [24] 1751 	push	ar2
      000654 C0 04            [24] 1752 	push	ar4
      000656 C0 05            [24] 1753 	push	ar5
      000658 C0 06            [24] 1754 	push	ar6
      00065A C0 03            [24] 1755 	push	ar3
                           00059F  1756 	C$fuzzy.h$1151$1_0$47 ==.
                                   1757 ;	../../fuzzy.h:1151: result * next;
      00065C E5 08            [12] 1758 	mov	a,_bp
      00065E 24 0A            [12] 1759 	add	a,#0x0a
      000660 F8               [12] 1760 	mov	r0,a
      000661 86 82            [24] 1761 	mov	dpl, @r0
      000663 08               [12] 1762 	inc	r0
      000664 86 83            [24] 1763 	mov	dph, @r0
      000666 08               [12] 1764 	inc	r0
      000667 86 F0            [24] 1765 	mov	b, @r0
      000669 08               [12] 1766 	inc	r0
      00066A E6               [12] 1767 	mov	a, @r0
      00066B 12 41 CE         [24] 1768 	lcall	___fsadd
      00066E C8               [12] 1769 	xch	a,r0
      00066F E5 08            [12] 1770 	mov	a,_bp
      000671 24 06            [12] 1771 	add	a,#0x06
      000673 C8               [12] 1772 	xch	a,r0
      000674 A6 82            [24] 1773 	mov	@r0, dpl
      000676 08               [12] 1774 	inc	r0
      000677 A6 83            [24] 1775 	mov	@r0, dph
      000679 08               [12] 1776 	inc	r0
      00067A A6 F0            [24] 1777 	mov	@r0, b
      00067C 08               [12] 1778 	inc	r0
      00067D F6               [12] 1779 	mov	@r0,a
      00067E E5 81            [12] 1780 	mov	a,sp
      000680 24 FC            [12] 1781 	add	a,#0xfc
      000682 F5 81            [12] 1782 	mov	sp,a
      000684 D0 02            [24] 1783 	pop	ar2
      000686 D0 03            [24] 1784 	pop	ar3
      000688 D0 04            [24] 1785 	pop	ar4
      00068A D0 05            [24] 1786 	pop	ar5
      00068C D0 06            [24] 1787 	pop	ar6
      00068E C0 04            [24] 1788 	push	ar4
      000690 C0 05            [24] 1789 	push	ar5
      000692 C0 06            [24] 1790 	push	ar6
      000694 C0 03            [24] 1791 	push	ar3
      000696 E5 08            [12] 1792 	mov	a,_bp
      000698 24 0A            [12] 1793 	add	a,#0x0a
      00069A F8               [12] 1794 	mov	r0,a
      00069B 86 82            [24] 1795 	mov	dpl, @r0
      00069D 08               [12] 1796 	inc	r0
      00069E 86 83            [24] 1797 	mov	dph, @r0
      0006A0 08               [12] 1798 	inc	r0
      0006A1 86 F0            [24] 1799 	mov	b, @r0
      0006A3 08               [12] 1800 	inc	r0
      0006A4 E6               [12] 1801 	mov	a, @r0
      0006A5 12 40 4C         [24] 1802 	lcall	___fsmul
      0006A8 AA 82            [24] 1803 	mov	r2, dpl
      0006AA AB 83            [24] 1804 	mov	r3, dph
      0006AC AE F0            [24] 1805 	mov	r6, b
      0006AE FF               [12] 1806 	mov	r7, a
      0006AF E5 81            [12] 1807 	mov	a,sp
      0006B1 24 FC            [12] 1808 	add	a,#0xfc
      0006B3 F5 81            [12] 1809 	mov	sp,a
      0006B5 C0 02            [24] 1810 	push	ar2
      0006B7 C0 02            [24] 1811 	push	ar2
      0006B9 C0 03            [24] 1812 	push	ar3
      0006BB C0 06            [24] 1813 	push	ar6
      0006BD C0 07            [24] 1814 	push	ar7
                           000602  1815 	C$fuzzy.h$1152$1_0$47 ==.
                                   1816 ;	../../fuzzy.h:1152: break;
      0006BF E5 08            [12] 1817 	mov	a,_bp
      0006C1 24 06            [12] 1818 	add	a,#0x06
      0006C3 F8               [12] 1819 	mov	r0,a
      0006C4 86 82            [24] 1820 	mov	dpl, @r0
      0006C6 08               [12] 1821 	inc	r0
      0006C7 86 83            [24] 1822 	mov	dph, @r0
      0006C9 08               [12] 1823 	inc	r0
      0006CA 86 F0            [24] 1824 	mov	b, @r0
      0006CC 08               [12] 1825 	inc	r0
      0006CD E6               [12] 1826 	mov	a, @r0
      0006CE 12 40 41         [24] 1827 	lcall	___fssub
      0006D1 C8               [12] 1828 	xch	a,r0
      0006D2 E5 08            [12] 1829 	mov	a,_bp
      0006D4 24 0A            [12] 1830 	add	a,#0x0a
      0006D6 C8               [12] 1831 	xch	a,r0
      0006D7 A6 82            [24] 1832 	mov	@r0, dpl
      0006D9 08               [12] 1833 	inc	r0
      0006DA A6 83            [24] 1834 	mov	@r0, dph
      0006DC 08               [12] 1835 	inc	r0
      0006DD A6 F0            [24] 1836 	mov	@r0, b
      0006DF 08               [12] 1837 	inc	r0
      0006E0 F6               [12] 1838 	mov	@r0,a
      0006E1 E5 81            [12] 1839 	mov	a,sp
      0006E3 24 FC            [12] 1840 	add	a,#0xfc
      0006E5 F5 81            [12] 1841 	mov	sp,a
      0006E7 D0 02            [24] 1842 	pop	ar2
      0006E9 D0 02            [24] 1843 	pop	ar2
                           00062E  1844 	C$fuzzy.h$1154$4_0$52 ==.
                                   1845 ;	../../fuzzy.h:1154: case FUZZY_LOGIC_BOUNDED:
      0006EB 80 77            [24] 1846 	sjmp	00120$
      0006ED                       1847 00112$:
                           000630  1848 	C$fuzzy.h$1156$1_0$47 ==.
                                   1849 ;	../../fuzzy.h:1156: next;
      0006ED C0 02            [24] 1850 	push	ar2
      0006EF C0 04            [24] 1851 	push	ar4
      0006F1 C0 05            [24] 1852 	push	ar5
      0006F3 C0 06            [24] 1853 	push	ar6
      0006F5 C0 03            [24] 1854 	push	ar3
                           00063A  1855 	C$fuzzy.h$1158$1_0$47 ==.
                                   1856 ;	../../fuzzy.h:1158: if (result > LEVEL_HI) {
      0006F7 E5 08            [12] 1857 	mov	a,_bp
      0006F9 24 0A            [12] 1858 	add	a,#0x0a
      0006FB F8               [12] 1859 	mov	r0,a
      0006FC 86 82            [24] 1860 	mov	dpl, @r0
      0006FE 08               [12] 1861 	inc	r0
      0006FF 86 83            [24] 1862 	mov	dph, @r0
      000701 08               [12] 1863 	inc	r0
      000702 86 F0            [24] 1864 	mov	b, @r0
      000704 08               [12] 1865 	inc	r0
      000705 E6               [12] 1866 	mov	a, @r0
      000706 12 41 CE         [24] 1867 	lcall	___fsadd
      000709 C8               [12] 1868 	xch	a,r0
      00070A E5 08            [12] 1869 	mov	a,_bp
      00070C 24 0A            [12] 1870 	add	a,#0x0a
      00070E C8               [12] 1871 	xch	a,r0
      00070F A6 82            [24] 1872 	mov	@r0, dpl
      000711 08               [12] 1873 	inc	r0
      000712 A6 83            [24] 1874 	mov	@r0, dph
      000714 08               [12] 1875 	inc	r0
      000715 A6 F0            [24] 1876 	mov	@r0, b
      000717 08               [12] 1877 	inc	r0
      000718 F6               [12] 1878 	mov	@r0,a
      000719 E5 81            [12] 1879 	mov	a,sp
      00071B 24 FC            [12] 1880 	add	a,#0xfc
      00071D F5 81            [12] 1881 	mov	sp,a
      00071F E5 08            [12] 1882 	mov	a,_bp
      000721 24 0A            [12] 1883 	add	a,#0x0a
      000723 F8               [12] 1884 	mov	r0,a
      000724 E6               [12] 1885 	mov	a,@r0
      000725 C0 E0            [24] 1886 	push	acc
      000727 08               [12] 1887 	inc	r0
      000728 E6               [12] 1888 	mov	a,@r0
      000729 C0 E0            [24] 1889 	push	acc
      00072B 08               [12] 1890 	inc	r0
      00072C E6               [12] 1891 	mov	a,@r0
      00072D C0 E0            [24] 1892 	push	acc
      00072F 08               [12] 1893 	inc	r0
      000730 E6               [12] 1894 	mov	a,@r0
      000731 C0 E0            [24] 1895 	push	acc
      000733 90 00 00         [24] 1896 	mov	dptr,#0x0000
      000736 75 F0 80         [24] 1897 	mov	b, #0x80
      000739 74 3F            [12] 1898 	mov	a, #0x3f
      00073B 12 41 7C         [24] 1899 	lcall	___fslt
      00073E AF 82            [24] 1900 	mov	r7, dpl
      000740 E5 81            [12] 1901 	mov	a,sp
      000742 24 FC            [12] 1902 	add	a,#0xfc
      000744 F5 81            [12] 1903 	mov	sp,a
      000746 D0 02            [24] 1904 	pop	ar2
      000748 EF               [12] 1905 	mov	a,r7
      000749 60 19            [24] 1906 	jz	00120$
                           00068E  1907 	C$fuzzy.h$1159$5_0$54 ==.
                                   1908 ;	../../fuzzy.h:1159: result = LEVEL_HI;
      00074B E5 08            [12] 1909 	mov	a,_bp
      00074D 24 0A            [12] 1910 	add	a,#0x0a
      00074F F8               [12] 1911 	mov	r0,a
      000750 E4               [12] 1912 	clr	a
      000751 F6               [12] 1913 	mov	@r0,a
      000752 08               [12] 1914 	inc	r0
      000753 F6               [12] 1915 	mov	@r0,a
      000754 08               [12] 1916 	inc	r0
      000755 76 80            [12] 1917 	mov	@r0,#0x80
      000757 08               [12] 1918 	inc	r0
      000758 76 3F            [12] 1919 	mov	@r0,#0x3f
                           00069D  1920 	C$fuzzy.h$1161$4_0$52 ==.
                                   1921 ;	../../fuzzy.h:1161: break;
                           00069D  1922 	C$fuzzy.h$1163$4_0$52 ==.
                                   1923 ;	../../fuzzy.h:1163: default:
      00075A 80 08            [24] 1924 	sjmp	00120$
      00075C                       1925 00115$:
                           00069F  1926 	C$fuzzy.h$1164$4_0$52 ==.
                                   1927 ;	../../fuzzy.h:1164: return LEVEL_LO;
      00075C 90 00 00         [24] 1928 	mov	dptr,#0x0000
      00075F E4               [12] 1929 	clr	a
      000760 F5 F0            [12] 1930 	mov	b,a
                           0006A5  1931 	C$fuzzy.h$1165$3_0$51 ==.
                                   1932 ;	../../fuzzy.h:1165: }
      000762 80 20            [24] 1933 	sjmp	00121$
      000764                       1934 00120$:
                           0006A7  1935 	C$fuzzy.h$1133$2_0$50 ==.
                                   1936 ;	../../fuzzy.h:1133: index++
      000764 E5 08            [12] 1937 	mov	a,_bp
      000766 24 0E            [12] 1938 	add	a,#0x0e
      000768 F8               [12] 1939 	mov	r0,a
      000769 06               [12] 1940 	inc	@r0
      00076A B6 00 02         [24] 1941 	cjne	@r0,#0x00,00206$
      00076D 08               [12] 1942 	inc	r0
      00076E 06               [12] 1943 	inc	@r0
      00076F                       1944 00206$:
      00076F 02 05 7B         [24] 1945 	ljmp	00119$
      000772                       1946 00117$:
                           0006B5  1947 	C$fuzzy.h$1169$1_0$47 ==.
                                   1948 ;	../../fuzzy.h:1169: result
      000772 E5 08            [12] 1949 	mov	a,_bp
      000774 24 0A            [12] 1950 	add	a,#0x0a
      000776 F8               [12] 1951 	mov	r0,a
      000777 86 82            [24] 1952 	mov	dpl, @r0
      000779 08               [12] 1953 	inc	r0
      00077A 86 83            [24] 1954 	mov	dph, @r0
      00077C 08               [12] 1955 	inc	r0
      00077D 86 F0            [24] 1956 	mov	b, @r0
      00077F 08               [12] 1957 	inc	r0
      000780 E6               [12] 1958 	mov	a, @r0
      000781 12 00 F0         [24] 1959 	lcall	_fuzzy_clamp
      000784                       1960 00121$:
                           0006C7  1961 	C$fuzzy.h$1171$1_0$47 ==.
                                   1962 ;	../../fuzzy.h:1171: }
      000784 85 08 81         [24] 1963 	mov	sp,_bp
      000787 D0 08            [24] 1964 	pop	_bp
                           0006CC  1965 	C$fuzzy.h$1171$1_0$47 ==.
                           0006CC  1966 	XG$fuzzy_or_array$0$0 ==.
      000789 22               [24] 1967 	ret
                                   1968 ;------------------------------------------------------------
                                   1969 ;Allocation info for local variables in function 'fuzzy_sugeno_weighted_average_array'
                                   1970 ;------------------------------------------------------------
                                   1971 ;values        Allocated to stack - _bp -5 +3 
                                   1972 ;value_count   Allocated to stack - _bp +1 +2 
                                   1973 ;weighted_sum  Allocated to stack - _bp +3 +4 
                                   1974 ;firing_sum    Allocated to stack - _bp +7 +4 
                                   1975 ;firing_strength Allocated to stack - _bp +11 +4 
                                   1976 ;consequent    Allocated to registers r4 r5 r3 r2 
                                   1977 ;index         Allocated to registers r6 r7 
                                   1978 ;------------------------------------------------------------
                           0006CD  1979 	G$fuzzy_sugeno_weighted_average_array$0$0 ==.
                           0006CD  1980 	C$fuzzy.h$1182$1_0$56 ==.
                                   1981 ;	../../fuzzy.h:1182: float fuzzy_sugeno_weighted_average_array(
                                   1982 ;	-----------------------------------------
                                   1983 ;	 function fuzzy_sugeno_weighted_average_array
                                   1984 ;	-----------------------------------------
      00078A                       1985 _fuzzy_sugeno_weighted_average_array:
      00078A C0 08            [24] 1986 	push	_bp
      00078C 85 81 08         [24] 1987 	mov	_bp,sp
      00078F C0 82            [24] 1988 	push	dpl
      000791 C0 83            [24] 1989 	push	dph
      000793 E5 81            [12] 1990 	mov	a,sp
      000795 24 0C            [12] 1991 	add	a,#0x0c
      000797 F5 81            [12] 1992 	mov	sp,a
                           0006DC  1993 	C$fuzzy.h$1195$1_0$56 ==.
                                   1994 ;	../../fuzzy.h:1195: values == NULL ||
      000799 E5 08            [12] 1995 	mov	a,_bp
      00079B 24 FB            [12] 1996 	add	a,#0xfb
      00079D F8               [12] 1997 	mov	r0,a
      00079E E6               [12] 1998 	mov	a,@r0
      00079F 08               [12] 1999 	inc	r0
      0007A0 46               [12] 2000 	orl	a,@r0
      0007A1 60 0F            [24] 2001 	jz	00101$
                           0006E6  2002 	C$fuzzy.h$1196$1_0$56 ==.
                                   2003 ;	../../fuzzy.h:1196: value_count == 0u ||
      0007A3 A8 08            [24] 2004 	mov	r0,_bp
      0007A5 08               [12] 2005 	inc	r0
      0007A6 E6               [12] 2006 	mov	a,@r0
      0007A7 08               [12] 2007 	inc	r0
      0007A8 46               [12] 2008 	orl	a,@r0
      0007A9 60 07            [24] 2009 	jz	00101$
                           0006EE  2010 	C$fuzzy.h$1197$1_0$56 ==.
                                   2011 ;	../../fuzzy.h:1197: value_count % 2u != 0u
      0007AB A8 08            [24] 2012 	mov	r0,_bp
      0007AD 08               [12] 2013 	inc	r0
      0007AE E6               [12] 2014 	mov	a,@r0
      0007AF 30 E0 09         [24] 2015 	jnb	acc.0,00102$
      0007B2                       2016 00101$:
                           0006F5  2017 	C$fuzzy.h$1199$2_0$57 ==.
                                   2018 ;	../../fuzzy.h:1199: return 0.0f;
      0007B2 90 00 00         [24] 2019 	mov	dptr,#0x0000
      0007B5 E4               [12] 2020 	clr	a
      0007B6 F5 F0            [12] 2021 	mov	b,a
      0007B8 02 09 85         [24] 2022 	ljmp	00111$
      0007BB                       2023 00102$:
                           0006FE  2024 	C$fuzzy.h$1203$1_0$56 ==.
                                   2025 ;	../../fuzzy.h:1203: 0.0f;
      0007BB E5 08            [12] 2026 	mov	a,_bp
      0007BD 24 03            [12] 2027 	add	a,#0x03
      0007BF F8               [12] 2028 	mov	r0,a
      0007C0 E4               [12] 2029 	clr	a
      0007C1 F6               [12] 2030 	mov	@r0,a
      0007C2 08               [12] 2031 	inc	r0
      0007C3 F6               [12] 2032 	mov	@r0,a
      0007C4 08               [12] 2033 	inc	r0
      0007C5 F6               [12] 2034 	mov	@r0,a
      0007C6 08               [12] 2035 	inc	r0
      0007C7 F6               [12] 2036 	mov	@r0,a
                           00070B  2037 	C$fuzzy.h$1206$1_0$56 ==.
                                   2038 ;	../../fuzzy.h:1206: 0.0f;
      0007C8 E5 08            [12] 2039 	mov	a,_bp
      0007CA 24 07            [12] 2040 	add	a,#0x07
      0007CC F8               [12] 2041 	mov	r0,a
      0007CD E4               [12] 2042 	clr	a
      0007CE F6               [12] 2043 	mov	@r0,a
      0007CF 08               [12] 2044 	inc	r0
      0007D0 F6               [12] 2045 	mov	@r0,a
      0007D1 08               [12] 2046 	inc	r0
      0007D2 F6               [12] 2047 	mov	@r0,a
      0007D3 08               [12] 2048 	inc	r0
      0007D4 F6               [12] 2049 	mov	@r0,a
                           000718  2050 	C$fuzzy.h$1209$1_0$56 ==.
                                   2051 ;	../../fuzzy.h:1209: index = 0u;
      0007D5 FE               [12] 2052 	mov	r6,a
      0007D6 FF               [12] 2053 	mov	r7,a
      0007D7                       2054 00109$:
                           00071A  2055 	C$fuzzy.h$1210$2_0$58 ==.
                                   2056 ;	../../fuzzy.h:1210: index < value_count;
      0007D7 A8 08            [24] 2057 	mov	r0,_bp
      0007D9 08               [12] 2058 	inc	r0
      0007DA C3               [12] 2059 	clr	c
      0007DB EE               [12] 2060 	mov	a,r6
      0007DC 96               [12] 2061 	subb	a,@r0
      0007DD EF               [12] 2062 	mov	a,r7
      0007DE 08               [12] 2063 	inc	r0
      0007DF 96               [12] 2064 	subb	a,@r0
      0007E0 40 03            [24] 2065 	jc	00147$
      0007E2 02 09 18         [24] 2066 	ljmp	00105$
      0007E5                       2067 00147$:
                           000728  2068 	C$fuzzy.h$1215$3_0$59 ==.
                                   2069 ;	../../fuzzy.h:1215: values[index]
      0007E5 EE               [12] 2070 	mov	a,r6
      0007E6 2E               [12] 2071 	add	a,r6
      0007E7 FC               [12] 2072 	mov	r4,a
      0007E8 EF               [12] 2073 	mov	a,r7
      0007E9 33               [12] 2074 	rlc	a
      0007EA FD               [12] 2075 	mov	r5,a
      0007EB EC               [12] 2076 	mov	a,r4
      0007EC 2C               [12] 2077 	add	a,r4
      0007ED FC               [12] 2078 	mov	r4,a
      0007EE ED               [12] 2079 	mov	a,r5
      0007EF 33               [12] 2080 	rlc	a
      0007F0 FD               [12] 2081 	mov	r5,a
      0007F1 E5 08            [12] 2082 	mov	a,_bp
      0007F3 24 FB            [12] 2083 	add	a,#0xfb
      0007F5 F8               [12] 2084 	mov	r0,a
      0007F6 EC               [12] 2085 	mov	a,r4
      0007F7 26               [12] 2086 	add	a, @r0
      0007F8 FC               [12] 2087 	mov	r4,a
      0007F9 ED               [12] 2088 	mov	a,r5
      0007FA 08               [12] 2089 	inc	r0
      0007FB 36               [12] 2090 	addc	a, @r0
      0007FC FD               [12] 2091 	mov	r5,a
      0007FD 08               [12] 2092 	inc	r0
      0007FE 86 03            [24] 2093 	mov	ar3,@r0
      000800 8C 82            [24] 2094 	mov	dpl,r4
      000802 8D 83            [24] 2095 	mov	dph,r5
      000804 8B F0            [24] 2096 	mov	b,r3
      000806 12 43 A8         [24] 2097 	lcall	__gptrget
      000809 FC               [12] 2098 	mov	r4,a
      00080A A3               [24] 2099 	inc	dptr
      00080B 12 43 A8         [24] 2100 	lcall	__gptrget
      00080E FD               [12] 2101 	mov	r5,a
      00080F A3               [24] 2102 	inc	dptr
      000810 12 43 A8         [24] 2103 	lcall	__gptrget
      000813 FB               [12] 2104 	mov	r3,a
      000814 A3               [24] 2105 	inc	dptr
      000815 12 43 A8         [24] 2106 	lcall	__gptrget
      000818 8C 82            [24] 2107 	mov	dpl,r4
      00081A 8D 83            [24] 2108 	mov	dph,r5
      00081C 8B F0            [24] 2109 	mov	b,r3
      00081E C0 07            [24] 2110 	push	ar7
      000820 C0 06            [24] 2111 	push	ar6
      000822 12 00 F0         [24] 2112 	lcall	_fuzzy_clamp
      000825 C8               [12] 2113 	xch	a,r0
      000826 E5 08            [12] 2114 	mov	a,_bp
      000828 24 0B            [12] 2115 	add	a,#0x0b
      00082A C8               [12] 2116 	xch	a,r0
      00082B A6 82            [24] 2117 	mov	@r0, dpl
      00082D 08               [12] 2118 	inc	r0
      00082E A6 83            [24] 2119 	mov	@r0, dph
      000830 08               [12] 2120 	inc	r0
      000831 A6 F0            [24] 2121 	mov	@r0, b
      000833 08               [12] 2122 	inc	r0
      000834 F6               [12] 2123 	mov	@r0,a
      000835 D0 06            [24] 2124 	pop	ar6
      000837 D0 07            [24] 2125 	pop	ar7
                           00077C  2126 	C$fuzzy.h$1219$3_0$59 ==.
                                   2127 ;	../../fuzzy.h:1219: values[index + 1u];
      000839 74 01            [12] 2128 	mov	a,#0x01
      00083B 2E               [12] 2129 	add	a, r6
      00083C FC               [12] 2130 	mov	r4,a
      00083D E4               [12] 2131 	clr	a
      00083E 3F               [12] 2132 	addc	a, r7
      00083F FD               [12] 2133 	mov	r5,a
      000840 EC               [12] 2134 	mov	a,r4
      000841 2C               [12] 2135 	add	a,r4
      000842 FC               [12] 2136 	mov	r4,a
      000843 ED               [12] 2137 	mov	a,r5
      000844 33               [12] 2138 	rlc	a
      000845 FD               [12] 2139 	mov	r5,a
      000846 EC               [12] 2140 	mov	a,r4
      000847 2C               [12] 2141 	add	a,r4
      000848 FC               [12] 2142 	mov	r4,a
      000849 ED               [12] 2143 	mov	a,r5
      00084A 33               [12] 2144 	rlc	a
      00084B FD               [12] 2145 	mov	r5,a
      00084C E5 08            [12] 2146 	mov	a,_bp
      00084E 24 FB            [12] 2147 	add	a,#0xfb
      000850 F8               [12] 2148 	mov	r0,a
      000851 EC               [12] 2149 	mov	a,r4
      000852 26               [12] 2150 	add	a, @r0
      000853 FC               [12] 2151 	mov	r4,a
      000854 ED               [12] 2152 	mov	a,r5
      000855 08               [12] 2153 	inc	r0
      000856 36               [12] 2154 	addc	a, @r0
      000857 FD               [12] 2155 	mov	r5,a
      000858 08               [12] 2156 	inc	r0
      000859 86 03            [24] 2157 	mov	ar3,@r0
      00085B 8C 82            [24] 2158 	mov	dpl,r4
      00085D 8D 83            [24] 2159 	mov	dph,r5
      00085F 8B F0            [24] 2160 	mov	b,r3
      000861 12 43 A8         [24] 2161 	lcall	__gptrget
      000864 FC               [12] 2162 	mov	r4,a
      000865 A3               [24] 2163 	inc	dptr
      000866 12 43 A8         [24] 2164 	lcall	__gptrget
      000869 FD               [12] 2165 	mov	r5,a
      00086A A3               [24] 2166 	inc	dptr
      00086B 12 43 A8         [24] 2167 	lcall	__gptrget
      00086E FB               [12] 2168 	mov	r3,a
      00086F A3               [24] 2169 	inc	dptr
      000870 12 43 A8         [24] 2170 	lcall	__gptrget
      000873 FA               [12] 2171 	mov	r2,a
                           0007B7  2172 	C$fuzzy.h$1224$1_0$56 ==.
                                   2173 ;	../../fuzzy.h:1224: consequent;
      000874 C0 07            [24] 2174 	push	ar7
      000876 C0 06            [24] 2175 	push	ar6
      000878 C0 04            [24] 2176 	push	ar4
      00087A C0 05            [24] 2177 	push	ar5
      00087C C0 03            [24] 2178 	push	ar3
      00087E C0 02            [24] 2179 	push	ar2
      000880 E5 08            [12] 2180 	mov	a,_bp
      000882 24 0B            [12] 2181 	add	a,#0x0b
      000884 F8               [12] 2182 	mov	r0,a
      000885 86 82            [24] 2183 	mov	dpl, @r0
      000887 08               [12] 2184 	inc	r0
      000888 86 83            [24] 2185 	mov	dph, @r0
      00088A 08               [12] 2186 	inc	r0
      00088B 86 F0            [24] 2187 	mov	b, @r0
      00088D 08               [12] 2188 	inc	r0
      00088E E6               [12] 2189 	mov	a, @r0
      00088F 12 40 4C         [24] 2190 	lcall	___fsmul
      000892 AA 82            [24] 2191 	mov	r2, dpl
      000894 AB 83            [24] 2192 	mov	r3, dph
      000896 AC F0            [24] 2193 	mov	r4, b
      000898 FD               [12] 2194 	mov	r5, a
      000899 E5 81            [12] 2195 	mov	a,sp
      00089B 24 FC            [12] 2196 	add	a,#0xfc
      00089D F5 81            [12] 2197 	mov	sp,a
      00089F C0 02            [24] 2198 	push	ar2
      0008A1 C0 03            [24] 2199 	push	ar3
      0008A3 C0 04            [24] 2200 	push	ar4
      0008A5 C0 05            [24] 2201 	push	ar5
                           0007EA  2202 	C$fuzzy.h$1227$1_0$56 ==.
                                   2203 ;	../../fuzzy.h:1227: firing_strength;
      0008A7 E5 08            [12] 2204 	mov	a,_bp
      0008A9 24 03            [12] 2205 	add	a,#0x03
      0008AB F8               [12] 2206 	mov	r0,a
      0008AC 86 82            [24] 2207 	mov	dpl, @r0
      0008AE 08               [12] 2208 	inc	r0
      0008AF 86 83            [24] 2209 	mov	dph, @r0
      0008B1 08               [12] 2210 	inc	r0
      0008B2 86 F0            [24] 2211 	mov	b, @r0
      0008B4 08               [12] 2212 	inc	r0
      0008B5 E6               [12] 2213 	mov	a, @r0
      0008B6 12 41 CE         [24] 2214 	lcall	___fsadd
      0008B9 A8 08            [24] 2215 	mov	r0,_bp
      0008BB 08               [12] 2216 	inc	r0
      0008BC 08               [12] 2217 	inc	r0
      0008BD 08               [12] 2218 	inc	r0
      0008BE A6 82            [24] 2219 	mov	@r0, dpl
      0008C0 08               [12] 2220 	inc	r0
      0008C1 A6 83            [24] 2221 	mov	@r0, dph
      0008C3 08               [12] 2222 	inc	r0
      0008C4 A6 F0            [24] 2223 	mov	@r0, b
      0008C6 08               [12] 2224 	inc	r0
      0008C7 F6               [12] 2225 	mov	@r0,a
      0008C8 E5 81            [12] 2226 	mov	a,sp
      0008CA 24 FC            [12] 2227 	add	a,#0xfc
      0008CC F5 81            [12] 2228 	mov	sp,a
      0008CE E5 08            [12] 2229 	mov	a,_bp
      0008D0 24 0B            [12] 2230 	add	a,#0x0b
      0008D2 F8               [12] 2231 	mov	r0,a
      0008D3 E6               [12] 2232 	mov	a,@r0
      0008D4 C0 E0            [24] 2233 	push	acc
      0008D6 08               [12] 2234 	inc	r0
      0008D7 E6               [12] 2235 	mov	a,@r0
      0008D8 C0 E0            [24] 2236 	push	acc
      0008DA 08               [12] 2237 	inc	r0
      0008DB E6               [12] 2238 	mov	a,@r0
      0008DC C0 E0            [24] 2239 	push	acc
      0008DE 08               [12] 2240 	inc	r0
      0008DF E6               [12] 2241 	mov	a,@r0
      0008E0 C0 E0            [24] 2242 	push	acc
                           000825  2243 	C$fuzzy.h$1212$1_0$56 ==.
                                   2244 ;	../../fuzzy.h:1212: ) {
      0008E2 E5 08            [12] 2245 	mov	a,_bp
      0008E4 24 07            [12] 2246 	add	a,#0x07
      0008E6 F8               [12] 2247 	mov	r0,a
      0008E7 86 82            [24] 2248 	mov	dpl, @r0
      0008E9 08               [12] 2249 	inc	r0
      0008EA 86 83            [24] 2250 	mov	dph, @r0
      0008EC 08               [12] 2251 	inc	r0
      0008ED 86 F0            [24] 2252 	mov	b, @r0
      0008EF 08               [12] 2253 	inc	r0
      0008F0 E6               [12] 2254 	mov	a, @r0
      0008F1 12 41 CE         [24] 2255 	lcall	___fsadd
      0008F4 C8               [12] 2256 	xch	a,r0
      0008F5 E5 08            [12] 2257 	mov	a,_bp
      0008F7 24 07            [12] 2258 	add	a,#0x07
      0008F9 C8               [12] 2259 	xch	a,r0
      0008FA A6 82            [24] 2260 	mov	@r0, dpl
      0008FC 08               [12] 2261 	inc	r0
      0008FD A6 83            [24] 2262 	mov	@r0, dph
      0008FF 08               [12] 2263 	inc	r0
      000900 A6 F0            [24] 2264 	mov	@r0, b
      000902 08               [12] 2265 	inc	r0
      000903 F6               [12] 2266 	mov	@r0,a
      000904 E5 81            [12] 2267 	mov	a,sp
      000906 24 FC            [12] 2268 	add	a,#0xfc
      000908 F5 81            [12] 2269 	mov	sp,a
      00090A D0 06            [24] 2270 	pop	ar6
      00090C D0 07            [24] 2271 	pop	ar7
      00090E 74 02            [12] 2272 	mov	a,#0x02
      000910 2E               [12] 2273 	add	a, r6
      000911 FE               [12] 2274 	mov	r6,a
      000912 E4               [12] 2275 	clr	a
      000913 3F               [12] 2276 	addc	a, r7
      000914 FF               [12] 2277 	mov	r7,a
      000915 02 07 D7         [24] 2278 	ljmp	00109$
      000918                       2279 00105$:
                           00085B  2280 	C$fuzzy.h$1230$1_0$56 ==.
                                   2281 ;	../../fuzzy.h:1230: if (firing_sum <= LEVEL_LO) {
      000918 E5 08            [12] 2282 	mov	a,_bp
      00091A 24 07            [12] 2283 	add	a,#0x07
      00091C F8               [12] 2284 	mov	r0,a
      00091D E6               [12] 2285 	mov	a,@r0
      00091E C0 E0            [24] 2286 	push	acc
      000920 08               [12] 2287 	inc	r0
      000921 E6               [12] 2288 	mov	a,@r0
      000922 C0 E0            [24] 2289 	push	acc
      000924 08               [12] 2290 	inc	r0
      000925 E6               [12] 2291 	mov	a,@r0
      000926 C0 E0            [24] 2292 	push	acc
      000928 08               [12] 2293 	inc	r0
      000929 E6               [12] 2294 	mov	a,@r0
      00092A C0 E0            [24] 2295 	push	acc
      00092C 90 00 00         [24] 2296 	mov	dptr,#0x0000
      00092F E4               [12] 2297 	clr	a
      000930 F5 F0            [12] 2298 	mov	b,a
      000932 12 41 7C         [24] 2299 	lcall	___fslt
      000935 E5 81            [12] 2300 	mov	a,sp
      000937 24 FC            [12] 2301 	add	a,#0xfc
      000939 F5 81            [12] 2302 	mov	sp,a
      00093B E5 82            [12] 2303 	mov	a, dpl
      00093D 24 FF            [12] 2304 	add	a,#0xff
      00093F 92 00            [24] 2305 	mov	b0,c
      000941 40 08            [24] 2306 	jc	00107$
                           000886  2307 	C$fuzzy.h$1231$2_0$60 ==.
                                   2308 ;	../../fuzzy.h:1231: return 0.0f;
      000943 90 00 00         [24] 2309 	mov	dptr,#0x0000
      000946 E4               [12] 2310 	clr	a
      000947 F5 F0            [12] 2311 	mov	b,a
      000949 80 3A            [24] 2312 	sjmp	00111$
      00094B                       2313 00107$:
                           00088E  2314 	C$fuzzy.h$1235$1_0$56 ==.
                                   2315 ;	../../fuzzy.h:1235: firing_sum;
      00094B E5 08            [12] 2316 	mov	a,_bp
      00094D 24 07            [12] 2317 	add	a,#0x07
      00094F F8               [12] 2318 	mov	r0,a
      000950 E6               [12] 2319 	mov	a,@r0
      000951 C0 E0            [24] 2320 	push	acc
      000953 08               [12] 2321 	inc	r0
      000954 E6               [12] 2322 	mov	a,@r0
      000955 C0 E0            [24] 2323 	push	acc
      000957 08               [12] 2324 	inc	r0
      000958 E6               [12] 2325 	mov	a,@r0
      000959 C0 E0            [24] 2326 	push	acc
      00095B 08               [12] 2327 	inc	r0
      00095C E6               [12] 2328 	mov	a,@r0
      00095D C0 E0            [24] 2329 	push	acc
      00095F E5 08            [12] 2330 	mov	a,_bp
      000961 24 03            [12] 2331 	add	a,#0x03
      000963 F8               [12] 2332 	mov	r0,a
      000964 86 82            [24] 2333 	mov	dpl, @r0
      000966 08               [12] 2334 	inc	r0
      000967 86 83            [24] 2335 	mov	dph, @r0
      000969 08               [12] 2336 	inc	r0
      00096A 86 F0            [24] 2337 	mov	b, @r0
      00096C 08               [12] 2338 	inc	r0
      00096D E6               [12] 2339 	mov	a, @r0
      00096E 12 42 E5         [24] 2340 	lcall	___fsdiv
      000971 AC 82            [24] 2341 	mov	r4, dpl
      000973 AD 83            [24] 2342 	mov	r5, dph
      000975 AE F0            [24] 2343 	mov	r6, b
      000977 FF               [12] 2344 	mov	r7, a
      000978 E5 81            [12] 2345 	mov	a,sp
      00097A 24 FC            [12] 2346 	add	a,#0xfc
      00097C F5 81            [12] 2347 	mov	sp,a
      00097E 8C 82            [24] 2348 	mov	dpl, r4
      000980 8D 83            [24] 2349 	mov	dph, r5
      000982 8E F0            [24] 2350 	mov	b, r6
      000984 EF               [12] 2351 	mov	a, r7
      000985                       2352 00111$:
                           0008C8  2353 	C$fuzzy.h$1236$1_0$56 ==.
                                   2354 ;	../../fuzzy.h:1236: }
      000985 85 08 81         [24] 2355 	mov	sp,_bp
      000988 D0 08            [24] 2356 	pop	_bp
                           0008CD  2357 	C$fuzzy.h$1236$1_0$56 ==.
                           0008CD  2358 	XG$fuzzy_sugeno_weighted_average_array$0$0 ==.
      00098A 22               [24] 2359 	ret
                                   2360 ;------------------------------------------------------------
                                   2361 ;Allocation info for local variables in function 'fuzzy_sugeno_weighted_sum_array'
                                   2362 ;------------------------------------------------------------
                                   2363 ;values        Allocated to stack - _bp -5 +3 
                                   2364 ;value_count   Allocated to registers r6 r7 
                                   2365 ;weighted_sum  Allocated to stack - _bp +1 +4 
                                   2366 ;firing_strength Allocated to stack - _bp +5 +4 
                                   2367 ;consequent    Allocated to registers r6 r7 r3 r2 
                                   2368 ;index         Allocated to registers r4 r5 
                                   2369 ;------------------------------------------------------------
                           0008CE  2370 	G$fuzzy_sugeno_weighted_sum_array$0$0 ==.
                           0008CE  2371 	C$fuzzy.h$1246$1_0$62 ==.
                                   2372 ;	../../fuzzy.h:1246: float fuzzy_sugeno_weighted_sum_array(
                                   2373 ;	-----------------------------------------
                                   2374 ;	 function fuzzy_sugeno_weighted_sum_array
                                   2375 ;	-----------------------------------------
      00098B                       2376 _fuzzy_sugeno_weighted_sum_array:
      00098B C0 08            [24] 2377 	push	_bp
      00098D E5 81            [12] 2378 	mov	a,sp
      00098F F5 08            [12] 2379 	mov	_bp,a
      000991 24 08            [12] 2380 	add	a,#0x08
      000993 F5 81            [12] 2381 	mov	sp,a
      000995 AE 82            [24] 2382 	mov	r6, dpl
      000997 AF 83            [24] 2383 	mov	r7, dph
                           0008DC  2384 	C$fuzzy.h$1258$1_0$62 ==.
                                   2385 ;	../../fuzzy.h:1258: values == NULL ||
      000999 E5 08            [12] 2386 	mov	a,_bp
      00099B 24 FB            [12] 2387 	add	a,#0xfb
      00099D F8               [12] 2388 	mov	r0,a
      00099E E6               [12] 2389 	mov	a,@r0
      00099F 08               [12] 2390 	inc	r0
      0009A0 46               [12] 2391 	orl	a,@r0
      0009A1 60 08            [24] 2392 	jz	00101$
                           0008E6  2393 	C$fuzzy.h$1259$1_0$62 ==.
                                   2394 ;	../../fuzzy.h:1259: value_count == 0u ||
      0009A3 EE               [12] 2395 	mov	a,r6
      0009A4 4F               [12] 2396 	orl	a,r7
      0009A5 60 04            [24] 2397 	jz	00101$
                           0008EA  2398 	C$fuzzy.h$1260$1_0$62 ==.
                                   2399 ;	../../fuzzy.h:1260: value_count % 2u != 0u
      0009A7 EE               [12] 2400 	mov	a,r6
      0009A8 30 E0 09         [24] 2401 	jnb	acc.0,00102$
      0009AB                       2402 00101$:
                           0008EE  2403 	C$fuzzy.h$1262$2_0$63 ==.
                                   2404 ;	../../fuzzy.h:1262: return 0.0f;
      0009AB 90 00 00         [24] 2405 	mov	dptr,#0x0000
      0009AE E4               [12] 2406 	clr	a
      0009AF F5 F0            [12] 2407 	mov	b,a
      0009B1 02 0A EC         [24] 2408 	ljmp	00109$
      0009B4                       2409 00102$:
                           0008F7  2410 	C$fuzzy.h$1266$1_0$62 ==.
                                   2411 ;	../../fuzzy.h:1266: 0.0f;
      0009B4 A8 08            [24] 2412 	mov	r0,_bp
      0009B6 08               [12] 2413 	inc	r0
      0009B7 E4               [12] 2414 	clr	a
      0009B8 F6               [12] 2415 	mov	@r0,a
      0009B9 08               [12] 2416 	inc	r0
      0009BA F6               [12] 2417 	mov	@r0,a
      0009BB 08               [12] 2418 	inc	r0
      0009BC F6               [12] 2419 	mov	@r0,a
      0009BD 08               [12] 2420 	inc	r0
      0009BE F6               [12] 2421 	mov	@r0,a
                           000902  2422 	C$fuzzy.h$1269$1_0$62 ==.
                                   2423 ;	../../fuzzy.h:1269: index = 0u;
      0009BF FC               [12] 2424 	mov	r4,a
      0009C0 FD               [12] 2425 	mov	r5,a
      0009C1                       2426 00107$:
                           000904  2427 	C$fuzzy.h$1270$2_0$64 ==.
                                   2428 ;	../../fuzzy.h:1270: index < value_count;
      0009C1 C3               [12] 2429 	clr	c
      0009C2 EC               [12] 2430 	mov	a,r4
      0009C3 9E               [12] 2431 	subb	a,r6
      0009C4 ED               [12] 2432 	mov	a,r5
      0009C5 9F               [12] 2433 	subb	a,r7
      0009C6 40 03            [24] 2434 	jc	00139$
      0009C8 02 0A DF         [24] 2435 	ljmp	00105$
      0009CB                       2436 00139$:
                           00090E  2437 	C$fuzzy.h$1275$1_0$62 ==.
                                   2438 ;	../../fuzzy.h:1275: values[index]
      0009CB C0 06            [24] 2439 	push	ar6
      0009CD C0 07            [24] 2440 	push	ar7
      0009CF EC               [12] 2441 	mov	a,r4
      0009D0 2C               [12] 2442 	add	a,r4
      0009D1 FA               [12] 2443 	mov	r2,a
      0009D2 ED               [12] 2444 	mov	a,r5
      0009D3 33               [12] 2445 	rlc	a
      0009D4 FB               [12] 2446 	mov	r3,a
      0009D5 EA               [12] 2447 	mov	a,r2
      0009D6 2A               [12] 2448 	add	a,r2
      0009D7 FA               [12] 2449 	mov	r2,a
      0009D8 EB               [12] 2450 	mov	a,r3
      0009D9 33               [12] 2451 	rlc	a
      0009DA FB               [12] 2452 	mov	r3,a
      0009DB E5 08            [12] 2453 	mov	a,_bp
      0009DD 24 FB            [12] 2454 	add	a,#0xfb
      0009DF F8               [12] 2455 	mov	r0,a
      0009E0 EA               [12] 2456 	mov	a,r2
      0009E1 26               [12] 2457 	add	a, @r0
      0009E2 FA               [12] 2458 	mov	r2,a
      0009E3 EB               [12] 2459 	mov	a,r3
      0009E4 08               [12] 2460 	inc	r0
      0009E5 36               [12] 2461 	addc	a, @r0
      0009E6 FB               [12] 2462 	mov	r3,a
      0009E7 08               [12] 2463 	inc	r0
      0009E8 86 07            [24] 2464 	mov	ar7,@r0
      0009EA 8A 82            [24] 2465 	mov	dpl,r2
      0009EC 8B 83            [24] 2466 	mov	dph,r3
      0009EE 8F F0            [24] 2467 	mov	b,r7
      0009F0 12 43 A8         [24] 2468 	lcall	__gptrget
      0009F3 FA               [12] 2469 	mov	r2,a
      0009F4 A3               [24] 2470 	inc	dptr
      0009F5 12 43 A8         [24] 2471 	lcall	__gptrget
      0009F8 FB               [12] 2472 	mov	r3,a
      0009F9 A3               [24] 2473 	inc	dptr
      0009FA 12 43 A8         [24] 2474 	lcall	__gptrget
      0009FD FF               [12] 2475 	mov	r7,a
      0009FE A3               [24] 2476 	inc	dptr
      0009FF 12 43 A8         [24] 2477 	lcall	__gptrget
      000A02 FE               [12] 2478 	mov	r6,a
      000A03 8A 82            [24] 2479 	mov	dpl,r2
      000A05 8B 83            [24] 2480 	mov	dph,r3
      000A07 8F F0            [24] 2481 	mov	b,r7
      000A09 C0 07            [24] 2482 	push	ar7
      000A0B C0 06            [24] 2483 	push	ar6
      000A0D C0 05            [24] 2484 	push	ar5
      000A0F C0 04            [24] 2485 	push	ar4
      000A11 12 00 F0         [24] 2486 	lcall	_fuzzy_clamp
      000A14 C8               [12] 2487 	xch	a,r0
      000A15 E5 08            [12] 2488 	mov	a,_bp
      000A17 24 05            [12] 2489 	add	a,#0x05
      000A19 C8               [12] 2490 	xch	a,r0
      000A1A A6 82            [24] 2491 	mov	@r0, dpl
      000A1C 08               [12] 2492 	inc	r0
      000A1D A6 83            [24] 2493 	mov	@r0, dph
      000A1F 08               [12] 2494 	inc	r0
      000A20 A6 F0            [24] 2495 	mov	@r0, b
      000A22 08               [12] 2496 	inc	r0
      000A23 F6               [12] 2497 	mov	@r0,a
      000A24 D0 04            [24] 2498 	pop	ar4
      000A26 D0 05            [24] 2499 	pop	ar5
      000A28 D0 06            [24] 2500 	pop	ar6
      000A2A D0 07            [24] 2501 	pop	ar7
                           00096F  2502 	C$fuzzy.h$1279$3_0$65 ==.
                                   2503 ;	../../fuzzy.h:1279: values[index + 1u];
      000A2C 74 01            [12] 2504 	mov	a,#0x01
      000A2E 2C               [12] 2505 	add	a, r4
      000A2F FE               [12] 2506 	mov	r6,a
      000A30 E4               [12] 2507 	clr	a
      000A31 3D               [12] 2508 	addc	a, r5
      000A32 FF               [12] 2509 	mov	r7,a
      000A33 EE               [12] 2510 	mov	a,r6
      000A34 2E               [12] 2511 	add	a,r6
      000A35 FE               [12] 2512 	mov	r6,a
      000A36 EF               [12] 2513 	mov	a,r7
      000A37 33               [12] 2514 	rlc	a
      000A38 FF               [12] 2515 	mov	r7,a
      000A39 EE               [12] 2516 	mov	a,r6
      000A3A 2E               [12] 2517 	add	a,r6
      000A3B FE               [12] 2518 	mov	r6,a
      000A3C EF               [12] 2519 	mov	a,r7
      000A3D 33               [12] 2520 	rlc	a
      000A3E FF               [12] 2521 	mov	r7,a
      000A3F E5 08            [12] 2522 	mov	a,_bp
      000A41 24 FB            [12] 2523 	add	a,#0xfb
      000A43 F8               [12] 2524 	mov	r0,a
      000A44 EE               [12] 2525 	mov	a,r6
      000A45 26               [12] 2526 	add	a, @r0
      000A46 FE               [12] 2527 	mov	r6,a
      000A47 EF               [12] 2528 	mov	a,r7
      000A48 08               [12] 2529 	inc	r0
      000A49 36               [12] 2530 	addc	a, @r0
      000A4A FF               [12] 2531 	mov	r7,a
      000A4B 08               [12] 2532 	inc	r0
      000A4C 86 03            [24] 2533 	mov	ar3,@r0
      000A4E 8E 82            [24] 2534 	mov	dpl,r6
      000A50 8F 83            [24] 2535 	mov	dph,r7
      000A52 8B F0            [24] 2536 	mov	b,r3
      000A54 12 43 A8         [24] 2537 	lcall	__gptrget
      000A57 FE               [12] 2538 	mov	r6,a
      000A58 A3               [24] 2539 	inc	dptr
      000A59 12 43 A8         [24] 2540 	lcall	__gptrget
      000A5C FF               [12] 2541 	mov	r7,a
      000A5D A3               [24] 2542 	inc	dptr
      000A5E 12 43 A8         [24] 2543 	lcall	__gptrget
      000A61 FB               [12] 2544 	mov	r3,a
      000A62 A3               [24] 2545 	inc	dptr
      000A63 12 43 A8         [24] 2546 	lcall	__gptrget
      000A66 FA               [12] 2547 	mov	r2,a
                           0009AA  2548 	C$fuzzy.h$1284$1_0$62 ==.
                                   2549 ;	../../fuzzy.h:1284: consequent;
      000A67 C0 05            [24] 2550 	push	ar5
      000A69 C0 04            [24] 2551 	push	ar4
      000A6B C0 06            [24] 2552 	push	ar6
      000A6D C0 07            [24] 2553 	push	ar7
      000A6F C0 03            [24] 2554 	push	ar3
      000A71 C0 02            [24] 2555 	push	ar2
      000A73 E5 08            [12] 2556 	mov	a,_bp
      000A75 24 05            [12] 2557 	add	a,#0x05
      000A77 F8               [12] 2558 	mov	r0,a
      000A78 86 82            [24] 2559 	mov	dpl, @r0
      000A7A 08               [12] 2560 	inc	r0
      000A7B 86 83            [24] 2561 	mov	dph, @r0
      000A7D 08               [12] 2562 	inc	r0
      000A7E 86 F0            [24] 2563 	mov	b, @r0
      000A80 08               [12] 2564 	inc	r0
      000A81 E6               [12] 2565 	mov	a, @r0
      000A82 12 40 4C         [24] 2566 	lcall	___fsmul
      000A85 AA 82            [24] 2567 	mov	r2, dpl
      000A87 AB 83            [24] 2568 	mov	r3, dph
      000A89 AE F0            [24] 2569 	mov	r6, b
      000A8B FF               [12] 2570 	mov	r7, a
      000A8C E5 81            [12] 2571 	mov	a,sp
      000A8E 24 FC            [12] 2572 	add	a,#0xfc
      000A90 F5 81            [12] 2573 	mov	sp,a
      000A92 D0 04            [24] 2574 	pop	ar4
      000A94 D0 05            [24] 2575 	pop	ar5
      000A96 C0 07            [24] 2576 	push	ar7
      000A98 C0 06            [24] 2577 	push	ar6
      000A9A C0 05            [24] 2578 	push	ar5
      000A9C C0 04            [24] 2579 	push	ar4
      000A9E C0 02            [24] 2580 	push	ar2
      000AA0 C0 03            [24] 2581 	push	ar3
      000AA2 C0 06            [24] 2582 	push	ar6
      000AA4 C0 07            [24] 2583 	push	ar7
                           0009E9  2584 	C$fuzzy.h$1272$1_0$62 ==.
                                   2585 ;	../../fuzzy.h:1272: ) {
      000AA6 A8 08            [24] 2586 	mov	r0,_bp
      000AA8 08               [12] 2587 	inc	r0
      000AA9 86 82            [24] 2588 	mov	dpl, @r0
      000AAB 08               [12] 2589 	inc	r0
      000AAC 86 83            [24] 2590 	mov	dph, @r0
      000AAE 08               [12] 2591 	inc	r0
      000AAF 86 F0            [24] 2592 	mov	b, @r0
      000AB1 08               [12] 2593 	inc	r0
      000AB2 E6               [12] 2594 	mov	a, @r0
      000AB3 12 41 CE         [24] 2595 	lcall	___fsadd
      000AB6 A8 08            [24] 2596 	mov	r0,_bp
      000AB8 08               [12] 2597 	inc	r0
      000AB9 A6 82            [24] 2598 	mov	@r0, dpl
      000ABB 08               [12] 2599 	inc	r0
      000ABC A6 83            [24] 2600 	mov	@r0, dph
      000ABE 08               [12] 2601 	inc	r0
      000ABF A6 F0            [24] 2602 	mov	@r0, b
      000AC1 08               [12] 2603 	inc	r0
      000AC2 F6               [12] 2604 	mov	@r0,a
      000AC3 E5 81            [12] 2605 	mov	a,sp
      000AC5 24 FC            [12] 2606 	add	a,#0xfc
      000AC7 F5 81            [12] 2607 	mov	sp,a
      000AC9 D0 04            [24] 2608 	pop	ar4
      000ACB D0 05            [24] 2609 	pop	ar5
      000ACD D0 06            [24] 2610 	pop	ar6
      000ACF D0 07            [24] 2611 	pop	ar7
      000AD1 74 02            [12] 2612 	mov	a,#0x02
      000AD3 2C               [12] 2613 	add	a, r4
      000AD4 FC               [12] 2614 	mov	r4,a
      000AD5 E4               [12] 2615 	clr	a
      000AD6 3D               [12] 2616 	addc	a, r5
      000AD7 FD               [12] 2617 	mov	r5,a
      000AD8 D0 07            [24] 2618 	pop	ar7
      000ADA D0 06            [24] 2619 	pop	ar6
      000ADC 02 09 C1         [24] 2620 	ljmp	00107$
      000ADF                       2621 00105$:
                           000A22  2622 	C$fuzzy.h$1287$1_0$62 ==.
                                   2623 ;	../../fuzzy.h:1287: return weighted_sum;
      000ADF A8 08            [24] 2624 	mov	r0,_bp
      000AE1 08               [12] 2625 	inc	r0
      000AE2 86 82            [24] 2626 	mov	dpl, @r0
      000AE4 08               [12] 2627 	inc	r0
      000AE5 86 83            [24] 2628 	mov	dph, @r0
      000AE7 08               [12] 2629 	inc	r0
      000AE8 86 F0            [24] 2630 	mov	b, @r0
      000AEA 08               [12] 2631 	inc	r0
      000AEB E6               [12] 2632 	mov	a, @r0
      000AEC                       2633 00109$:
                           000A2F  2634 	C$fuzzy.h$1288$1_0$62 ==.
                                   2635 ;	../../fuzzy.h:1288: }
      000AEC 85 08 81         [24] 2636 	mov	sp,_bp
      000AEF D0 08            [24] 2637 	pop	_bp
                           000A34  2638 	C$fuzzy.h$1288$1_0$62 ==.
                           000A34  2639 	XG$fuzzy_sugeno_weighted_sum_array$0$0 ==.
      000AF1 22               [24] 2640 	ret
                                   2641 ;------------------------------------------------------------
                                   2642 ;Allocation info for local variables in function 'fuzzy_ramp'
                                   2643 ;------------------------------------------------------------
                                   2644 ;upper_boundary Allocated to stack - _bp -6 +4 
                                   2645 ;value         Allocated to stack - _bp -10 +4 
                                   2646 ;ramp_up       Allocated to stack - _bp -11 +1 
                                   2647 ;hedge         Allocated to stack - _bp -12 +1 
                                   2648 ;lower_boundary Allocated to registers r7 r6 r5 r4 
                                   2649 ;result        Allocated to stack - _bp +5 +4 
                                   2650 ;normalized    Allocated to registers r4 r5 r6 r7 
                                   2651 ;sloc0         Allocated to stack - _bp +13 +4 
                                   2652 ;sloc1         Allocated to stack - _bp +1 +4 
                                   2653 ;------------------------------------------------------------
                           000A35  2654 	G$fuzzy_ramp$0$0 ==.
                           000A35  2655 	C$fuzzy.h$1294$1_0$67 ==.
                                   2656 ;	../../fuzzy.h:1294: float fuzzy_ramp(
                                   2657 ;	-----------------------------------------
                                   2658 ;	 function fuzzy_ramp
                                   2659 ;	-----------------------------------------
      000AF2                       2660 _fuzzy_ramp:
      000AF2 C0 08            [24] 2661 	push	_bp
      000AF4 85 81 08         [24] 2662 	mov	_bp,sp
      000AF7 AF 82            [24] 2663 	mov	r7,dpl
      000AF9 AE 83            [24] 2664 	mov	r6,dph
      000AFB AD F0            [24] 2665 	mov	r5,b
      000AFD FC               [12] 2666 	mov	r4,a
      000AFE E5 81            [12] 2667 	mov	a,sp
      000B00 24 08            [12] 2668 	add	a,#0x08
      000B02 F5 81            [12] 2669 	mov	sp,a
                           000A47  2670 	C$fuzzy.h$1305$1_0$67 ==.
                                   2671 ;	../../fuzzy.h:1305: if (lower_boundary >= upper_boundary) {
      000B04 C0 07            [24] 2672 	push	ar7
      000B06 C0 06            [24] 2673 	push	ar6
      000B08 C0 05            [24] 2674 	push	ar5
      000B0A C0 04            [24] 2675 	push	ar4
      000B0C E5 08            [12] 2676 	mov	a,_bp
      000B0E 24 FA            [12] 2677 	add	a,#0xfa
      000B10 F8               [12] 2678 	mov	r0,a
      000B11 E6               [12] 2679 	mov	a,@r0
      000B12 C0 E0            [24] 2680 	push	acc
      000B14 08               [12] 2681 	inc	r0
      000B15 E6               [12] 2682 	mov	a,@r0
      000B16 C0 E0            [24] 2683 	push	acc
      000B18 08               [12] 2684 	inc	r0
      000B19 E6               [12] 2685 	mov	a,@r0
      000B1A C0 E0            [24] 2686 	push	acc
      000B1C 08               [12] 2687 	inc	r0
      000B1D E6               [12] 2688 	mov	a,@r0
      000B1E C0 E0            [24] 2689 	push	acc
      000B20 8F 82            [24] 2690 	mov	dpl, r7
      000B22 8E 83            [24] 2691 	mov	dph, r6
      000B24 8D F0            [24] 2692 	mov	b, r5
      000B26 EC               [12] 2693 	mov	a, r4
      000B27 12 41 7C         [24] 2694 	lcall	___fslt
      000B2A E5 81            [12] 2695 	mov	a,sp
      000B2C 24 FC            [12] 2696 	add	a,#0xfc
      000B2E F5 81            [12] 2697 	mov	sp,a
      000B30 D0 04            [24] 2698 	pop	ar4
      000B32 D0 05            [24] 2699 	pop	ar5
      000B34 D0 06            [24] 2700 	pop	ar6
      000B36 D0 07            [24] 2701 	pop	ar7
      000B38 E5 82            [12] 2702 	mov	a, dpl
      000B3A 24 FF            [12] 2703 	add	a,#0xff
      000B3C 92 00            [24] 2704 	mov	b0,c
      000B3E 40 09            [24] 2705 	jc	00102$
                           000A83  2706 	C$fuzzy.h$1306$2_0$68 ==.
                                   2707 ;	../../fuzzy.h:1306: return LEVEL_LO;
      000B40 90 00 00         [24] 2708 	mov	dptr,#0x0000
      000B43 E4               [12] 2709 	clr	a
      000B44 F5 F0            [12] 2710 	mov	b,a
      000B46 02 0D 29         [24] 2711 	ljmp	00109$
      000B49                       2712 00102$:
                           000A8C  2713 	C$fuzzy.h$1309$1_0$67 ==.
                                   2714 ;	../../fuzzy.h:1309: if (value <= lower_boundary) {
      000B49 C0 07            [24] 2715 	push	ar7
      000B4B C0 06            [24] 2716 	push	ar6
      000B4D C0 05            [24] 2717 	push	ar5
      000B4F C0 04            [24] 2718 	push	ar4
      000B51 E5 08            [12] 2719 	mov	a,_bp
      000B53 24 F6            [12] 2720 	add	a,#0xf6
      000B55 F8               [12] 2721 	mov	r0,a
      000B56 E6               [12] 2722 	mov	a,@r0
      000B57 C0 E0            [24] 2723 	push	acc
      000B59 08               [12] 2724 	inc	r0
      000B5A E6               [12] 2725 	mov	a,@r0
      000B5B C0 E0            [24] 2726 	push	acc
      000B5D 08               [12] 2727 	inc	r0
      000B5E E6               [12] 2728 	mov	a,@r0
      000B5F C0 E0            [24] 2729 	push	acc
      000B61 08               [12] 2730 	inc	r0
      000B62 E6               [12] 2731 	mov	a,@r0
      000B63 C0 E0            [24] 2732 	push	acc
      000B65 8F 82            [24] 2733 	mov	dpl, r7
      000B67 8E 83            [24] 2734 	mov	dph, r6
      000B69 8D F0            [24] 2735 	mov	b, r5
      000B6B EC               [12] 2736 	mov	a, r4
      000B6C 12 41 7C         [24] 2737 	lcall	___fslt
      000B6F E5 81            [12] 2738 	mov	a,sp
      000B71 24 FC            [12] 2739 	add	a,#0xfc
      000B73 F5 81            [12] 2740 	mov	sp,a
      000B75 D0 04            [24] 2741 	pop	ar4
      000B77 D0 05            [24] 2742 	pop	ar5
      000B79 D0 06            [24] 2743 	pop	ar6
      000B7B D0 07            [24] 2744 	pop	ar7
      000B7D E5 82            [12] 2745 	mov	a, dpl
      000B7F 24 FF            [12] 2746 	add	a,#0xff
      000B81 92 00            [24] 2747 	mov	b0,c
      000B83 40 39            [24] 2748 	jc	00107$
                           000AC8  2749 	C$fuzzy.h$1311$2_0$69 ==.
                                   2750 ;	../../fuzzy.h:1311: ramp_up
      000B85 E5 08            [12] 2751 	mov	a,_bp
      000B87 24 F5            [12] 2752 	add	a,#0xf5
      000B89 F8               [12] 2753 	mov	r0,a
      000B8A E6               [12] 2754 	mov	a,@r0
      000B8B 60 0F            [24] 2755 	jz	00111$
                           000AD0  2756 	C$fuzzy.h$1312$2_0$69 ==.
                                   2757 ;	../../fuzzy.h:1312: ? LEVEL_LO
      000B8D E5 08            [12] 2758 	mov	a,_bp
      000B8F 24 05            [12] 2759 	add	a,#0x05
      000B91 F8               [12] 2760 	mov	r0,a
      000B92 E4               [12] 2761 	clr	a
      000B93 F6               [12] 2762 	mov	@r0,a
      000B94 08               [12] 2763 	inc	r0
      000B95 F6               [12] 2764 	mov	@r0,a
      000B96 08               [12] 2765 	inc	r0
      000B97 F6               [12] 2766 	mov	@r0,a
      000B98 08               [12] 2767 	inc	r0
      000B99 F6               [12] 2768 	mov	@r0,a
      000B9A 80 0F            [24] 2769 	sjmp	00112$
      000B9C                       2770 00111$:
                           000ADF  2771 	C$fuzzy.h$1313$2_0$69 ==.
                                   2772 ;	../../fuzzy.h:1313: : LEVEL_HI;
      000B9C E5 08            [12] 2773 	mov	a,_bp
      000B9E 24 05            [12] 2774 	add	a,#0x05
      000BA0 F8               [12] 2775 	mov	r0,a
      000BA1 E4               [12] 2776 	clr	a
      000BA2 F6               [12] 2777 	mov	@r0,a
      000BA3 08               [12] 2778 	inc	r0
      000BA4 F6               [12] 2779 	mov	@r0,a
      000BA5 08               [12] 2780 	inc	r0
      000BA6 76 80            [12] 2781 	mov	@r0,#0x80
      000BA8 08               [12] 2782 	inc	r0
      000BA9 76 3F            [12] 2783 	mov	@r0,#0x3f
      000BAB                       2784 00112$:
      000BAB E5 08            [12] 2785 	mov	a,_bp
      000BAD 24 05            [12] 2786 	add	a,#0x05
      000BAF F8               [12] 2787 	mov	r0,a
      000BB0 86 07            [24] 2788 	mov	ar7,@r0
      000BB2 08               [12] 2789 	inc	r0
      000BB3 86 06            [24] 2790 	mov	ar6,@r0
      000BB5 08               [12] 2791 	inc	r0
      000BB6 86 05            [24] 2792 	mov	ar5,@r0
      000BB8 08               [12] 2793 	inc	r0
      000BB9 86 04            [24] 2794 	mov	ar4,@r0
      000BBB 02 0D 07         [24] 2795 	ljmp	00108$
      000BBE                       2796 00107$:
                           000B01  2797 	C$fuzzy.h$1315$1_0$67 ==.
                                   2798 ;	../../fuzzy.h:1315: else if (value >= upper_boundary) {
      000BBE C0 07            [24] 2799 	push	ar7
      000BC0 C0 06            [24] 2800 	push	ar6
      000BC2 C0 05            [24] 2801 	push	ar5
      000BC4 C0 04            [24] 2802 	push	ar4
      000BC6 E5 08            [12] 2803 	mov	a,_bp
      000BC8 24 FA            [12] 2804 	add	a,#0xfa
      000BCA F8               [12] 2805 	mov	r0,a
      000BCB E6               [12] 2806 	mov	a,@r0
      000BCC C0 E0            [24] 2807 	push	acc
      000BCE 08               [12] 2808 	inc	r0
      000BCF E6               [12] 2809 	mov	a,@r0
      000BD0 C0 E0            [24] 2810 	push	acc
      000BD2 08               [12] 2811 	inc	r0
      000BD3 E6               [12] 2812 	mov	a,@r0
      000BD4 C0 E0            [24] 2813 	push	acc
      000BD6 08               [12] 2814 	inc	r0
      000BD7 E6               [12] 2815 	mov	a,@r0
      000BD8 C0 E0            [24] 2816 	push	acc
      000BDA E5 08            [12] 2817 	mov	a,_bp
      000BDC 24 F6            [12] 2818 	add	a,#0xf6
      000BDE F8               [12] 2819 	mov	r0,a
      000BDF 86 82            [24] 2820 	mov	dpl, @r0
      000BE1 08               [12] 2821 	inc	r0
      000BE2 86 83            [24] 2822 	mov	dph, @r0
      000BE4 08               [12] 2823 	inc	r0
      000BE5 86 F0            [24] 2824 	mov	b, @r0
      000BE7 08               [12] 2825 	inc	r0
      000BE8 E6               [12] 2826 	mov	a, @r0
      000BE9 12 41 7C         [24] 2827 	lcall	___fslt
      000BEC E5 81            [12] 2828 	mov	a,sp
      000BEE 24 FC            [12] 2829 	add	a,#0xfc
      000BF0 F5 81            [12] 2830 	mov	sp,a
      000BF2 D0 04            [24] 2831 	pop	ar4
      000BF4 D0 05            [24] 2832 	pop	ar5
      000BF6 D0 06            [24] 2833 	pop	ar6
      000BF8 D0 07            [24] 2834 	pop	ar7
      000BFA E5 82            [12] 2835 	mov	a, dpl
      000BFC 24 FF            [12] 2836 	add	a,#0xff
      000BFE 92 00            [24] 2837 	mov	b0,c
      000C00 40 39            [24] 2838 	jc	00104$
                           000B45  2839 	C$fuzzy.h$1317$2_0$70 ==.
                                   2840 ;	../../fuzzy.h:1317: ramp_up
      000C02 E5 08            [12] 2841 	mov	a,_bp
      000C04 24 F5            [12] 2842 	add	a,#0xf5
      000C06 F8               [12] 2843 	mov	r0,a
      000C07 E6               [12] 2844 	mov	a,@r0
      000C08 60 11            [24] 2845 	jz	00113$
                           000B4D  2846 	C$fuzzy.h$1318$2_0$70 ==.
                                   2847 ;	../../fuzzy.h:1318: ? LEVEL_HI
      000C0A E5 08            [12] 2848 	mov	a,_bp
      000C0C 24 05            [12] 2849 	add	a,#0x05
      000C0E F8               [12] 2850 	mov	r0,a
      000C0F E4               [12] 2851 	clr	a
      000C10 F6               [12] 2852 	mov	@r0,a
      000C11 08               [12] 2853 	inc	r0
      000C12 F6               [12] 2854 	mov	@r0,a
      000C13 08               [12] 2855 	inc	r0
      000C14 76 80            [12] 2856 	mov	@r0,#0x80
      000C16 08               [12] 2857 	inc	r0
      000C17 76 3F            [12] 2858 	mov	@r0,#0x3f
      000C19 80 0D            [24] 2859 	sjmp	00114$
      000C1B                       2860 00113$:
                           000B5E  2861 	C$fuzzy.h$1319$2_0$70 ==.
                                   2862 ;	../../fuzzy.h:1319: : LEVEL_LO;
      000C1B E5 08            [12] 2863 	mov	a,_bp
      000C1D 24 05            [12] 2864 	add	a,#0x05
      000C1F F8               [12] 2865 	mov	r0,a
      000C20 E4               [12] 2866 	clr	a
      000C21 F6               [12] 2867 	mov	@r0,a
      000C22 08               [12] 2868 	inc	r0
      000C23 F6               [12] 2869 	mov	@r0,a
      000C24 08               [12] 2870 	inc	r0
      000C25 F6               [12] 2871 	mov	@r0,a
      000C26 08               [12] 2872 	inc	r0
      000C27 F6               [12] 2873 	mov	@r0,a
      000C28                       2874 00114$:
      000C28 E5 08            [12] 2875 	mov	a,_bp
      000C2A 24 05            [12] 2876 	add	a,#0x05
      000C2C F8               [12] 2877 	mov	r0,a
      000C2D 86 07            [24] 2878 	mov	ar7,@r0
      000C2F 08               [12] 2879 	inc	r0
      000C30 86 06            [24] 2880 	mov	ar6,@r0
      000C32 08               [12] 2881 	inc	r0
      000C33 86 05            [24] 2882 	mov	ar5,@r0
      000C35 08               [12] 2883 	inc	r0
      000C36 86 04            [24] 2884 	mov	ar4,@r0
      000C38 02 0D 07         [24] 2885 	ljmp	00108$
      000C3B                       2886 00104$:
                           000B7E  2887 	C$fuzzy.h$1323$1_0$67 ==.
                                   2888 ;	../../fuzzy.h:1323: (value - lower_boundary) /
      000C3B C0 07            [24] 2889 	push	ar7
      000C3D C0 06            [24] 2890 	push	ar6
      000C3F C0 05            [24] 2891 	push	ar5
      000C41 C0 04            [24] 2892 	push	ar4
      000C43 C0 07            [24] 2893 	push	ar7
      000C45 C0 06            [24] 2894 	push	ar6
      000C47 C0 05            [24] 2895 	push	ar5
      000C49 C0 04            [24] 2896 	push	ar4
                           000B8E  2897 	C$fuzzy.h$1324$1_0$67 ==.
                                   2898 ;	../../fuzzy.h:1324: (upper_boundary - lower_boundary);
      000C4B E5 08            [12] 2899 	mov	a,_bp
      000C4D 24 F6            [12] 2900 	add	a,#0xf6
      000C4F F8               [12] 2901 	mov	r0,a
      000C50 86 82            [24] 2902 	mov	dpl, @r0
      000C52 08               [12] 2903 	inc	r0
      000C53 86 83            [24] 2904 	mov	dph, @r0
      000C55 08               [12] 2905 	inc	r0
      000C56 86 F0            [24] 2906 	mov	b, @r0
      000C58 08               [12] 2907 	inc	r0
      000C59 E6               [12] 2908 	mov	a, @r0
      000C5A 12 40 41         [24] 2909 	lcall	___fssub
      000C5D A8 08            [24] 2910 	mov	r0,_bp
      000C5F 08               [12] 2911 	inc	r0
      000C60 A6 82            [24] 2912 	mov	@r0, dpl
      000C62 08               [12] 2913 	inc	r0
      000C63 A6 83            [24] 2914 	mov	@r0, dph
      000C65 08               [12] 2915 	inc	r0
      000C66 A6 F0            [24] 2916 	mov	@r0, b
      000C68 08               [12] 2917 	inc	r0
      000C69 F6               [12] 2918 	mov	@r0,a
      000C6A E5 81            [12] 2919 	mov	a,sp
      000C6C 24 FC            [12] 2920 	add	a,#0xfc
      000C6E F5 81            [12] 2921 	mov	sp,a
      000C70 E5 08            [12] 2922 	mov	a,_bp
      000C72 24 FA            [12] 2923 	add	a,#0xfa
      000C74 F8               [12] 2924 	mov	r0,a
      000C75 86 82            [24] 2925 	mov	dpl, @r0
      000C77 08               [12] 2926 	inc	r0
      000C78 86 83            [24] 2927 	mov	dph, @r0
      000C7A 08               [12] 2928 	inc	r0
      000C7B 86 F0            [24] 2929 	mov	b, @r0
      000C7D 08               [12] 2930 	inc	r0
      000C7E E6               [12] 2931 	mov	a, @r0
      000C7F 12 40 41         [24] 2932 	lcall	___fssub
      000C82 AC 82            [24] 2933 	mov	r4, dpl
      000C84 AD 83            [24] 2934 	mov	r5, dph
      000C86 AE F0            [24] 2935 	mov	r6, b
      000C88 FF               [12] 2936 	mov	r7, a
      000C89 E5 81            [12] 2937 	mov	a,sp
      000C8B 24 FC            [12] 2938 	add	a,#0xfc
      000C8D F5 81            [12] 2939 	mov	sp,a
      000C8F C0 04            [24] 2940 	push	ar4
      000C91 C0 05            [24] 2941 	push	ar5
      000C93 C0 06            [24] 2942 	push	ar6
      000C95 C0 07            [24] 2943 	push	ar7
                           000BDA  2944 	C$fuzzy.h$1327$1_0$67 ==.
                                   2945 ;	../../fuzzy.h:1327: ramp_up
      000C97 A8 08            [24] 2946 	mov	r0,_bp
      000C99 08               [12] 2947 	inc	r0
      000C9A 86 82            [24] 2948 	mov	dpl, @r0
      000C9C 08               [12] 2949 	inc	r0
      000C9D 86 83            [24] 2950 	mov	dph, @r0
      000C9F 08               [12] 2951 	inc	r0
      000CA0 86 F0            [24] 2952 	mov	b, @r0
      000CA2 08               [12] 2953 	inc	r0
      000CA3 E6               [12] 2954 	mov	a, @r0
      000CA4 12 42 E5         [24] 2955 	lcall	___fsdiv
      000CA7 AC 82            [24] 2956 	mov	r4, dpl
      000CA9 AD 83            [24] 2957 	mov	r5, dph
      000CAB AE F0            [24] 2958 	mov	r6, b
      000CAD FF               [12] 2959 	mov	r7, a
      000CAE E5 81            [12] 2960 	mov	a,sp
      000CB0 24 FC            [12] 2961 	add	a,#0xfc
      000CB2 F5 81            [12] 2962 	mov	sp,a
      000CB4 E5 08            [12] 2963 	mov	a,_bp
      000CB6 24 F5            [12] 2964 	add	a,#0xf5
      000CB8 F8               [12] 2965 	mov	r0,a
      000CB9 E6               [12] 2966 	mov	a,@r0
      000CBA 60 12            [24] 2967 	jz	00115$
                           000BFF  2968 	C$fuzzy.h$1328$2_0$71 ==.
                                   2969 ;	../../fuzzy.h:1328: ? normalized
      000CBC E5 08            [12] 2970 	mov	a,_bp
      000CBE 24 05            [12] 2971 	add	a,#0x05
      000CC0 F8               [12] 2972 	mov	r0,a
      000CC1 A6 04            [24] 2973 	mov	@r0,ar4
      000CC3 08               [12] 2974 	inc	r0
      000CC4 A6 05            [24] 2975 	mov	@r0,ar5
      000CC6 08               [12] 2976 	inc	r0
      000CC7 A6 06            [24] 2977 	mov	@r0,ar6
      000CC9 08               [12] 2978 	inc	r0
      000CCA A6 07            [24] 2979 	mov	@r0,ar7
      000CCC 80 29            [24] 2980 	sjmp	00116$
      000CCE                       2981 00115$:
                           000C11  2982 	C$fuzzy.h$1329$1_0$67 ==.
                                   2983 ;	../../fuzzy.h:1329: : LEVEL_HI - normalized;
      000CCE C0 04            [24] 2984 	push	ar4
      000CD0 C0 05            [24] 2985 	push	ar5
      000CD2 C0 06            [24] 2986 	push	ar6
      000CD4 C0 07            [24] 2987 	push	ar7
      000CD6 90 00 00         [24] 2988 	mov	dptr,#0x0000
      000CD9 75 F0 80         [24] 2989 	mov	b, #0x80
      000CDC 74 3F            [12] 2990 	mov	a, #0x3f
      000CDE 12 40 41         [24] 2991 	lcall	___fssub
      000CE1 C8               [12] 2992 	xch	a,r0
      000CE2 E5 08            [12] 2993 	mov	a,_bp
      000CE4 24 05            [12] 2994 	add	a,#0x05
      000CE6 C8               [12] 2995 	xch	a,r0
      000CE7 A6 82            [24] 2996 	mov	@r0, dpl
      000CE9 08               [12] 2997 	inc	r0
      000CEA A6 83            [24] 2998 	mov	@r0, dph
      000CEC 08               [12] 2999 	inc	r0
      000CED A6 F0            [24] 3000 	mov	@r0, b
      000CEF 08               [12] 3001 	inc	r0
      000CF0 F6               [12] 3002 	mov	@r0,a
      000CF1 E5 81            [12] 3003 	mov	a,sp
      000CF3 24 FC            [12] 3004 	add	a,#0xfc
      000CF5 F5 81            [12] 3005 	mov	sp,a
      000CF7                       3006 00116$:
      000CF7 E5 08            [12] 3007 	mov	a,_bp
      000CF9 24 05            [12] 3008 	add	a,#0x05
      000CFB F8               [12] 3009 	mov	r0,a
      000CFC 86 07            [24] 3010 	mov	ar7,@r0
      000CFE 08               [12] 3011 	inc	r0
      000CFF 86 06            [24] 3012 	mov	ar6,@r0
      000D01 08               [12] 3013 	inc	r0
      000D02 86 05            [24] 3014 	mov	ar5,@r0
      000D04 08               [12] 3015 	inc	r0
      000D05 86 04            [24] 3016 	mov	ar4,@r0
      000D07                       3017 00108$:
                           000C4A  3018 	C$fuzzy.h$1333$1_0$67 ==.
                                   3019 ;	../../fuzzy.h:1333: result,
      000D07 E5 08            [12] 3020 	mov	a,_bp
      000D09 24 F4            [12] 3021 	add	a,#0xf4
      000D0B F8               [12] 3022 	mov	r0,a
      000D0C E6               [12] 3023 	mov	a,@r0
      000D0D C0 E0            [24] 3024 	push	acc
      000D0F 8F 82            [24] 3025 	mov	dpl, r7
      000D11 8E 83            [24] 3026 	mov	dph, r6
      000D13 8D F0            [24] 3027 	mov	b, r5
      000D15 EC               [12] 3028 	mov	a, r4
      000D16 12 01 9F         [24] 3029 	lcall	_fuzzy_apply_hedge
      000D19 AC 82            [24] 3030 	mov	r4, dpl
      000D1B AD 83            [24] 3031 	mov	r5, dph
      000D1D AE F0            [24] 3032 	mov	r6, b
      000D1F FF               [12] 3033 	mov	r7, a
      000D20 15 81            [12] 3034 	dec	sp
      000D22 8C 82            [24] 3035 	mov	dpl, r4
      000D24 8D 83            [24] 3036 	mov	dph, r5
      000D26 8E F0            [24] 3037 	mov	b, r6
      000D28 EF               [12] 3038 	mov	a, r7
      000D29                       3039 00109$:
                           000C6C  3040 	C$fuzzy.h$1336$1_0$67 ==.
                                   3041 ;	../../fuzzy.h:1336: }
      000D29 85 08 81         [24] 3042 	mov	sp,_bp
      000D2C D0 08            [24] 3043 	pop	_bp
                           000C71  3044 	C$fuzzy.h$1336$1_0$67 ==.
                           000C71  3045 	XG$fuzzy_ramp$0$0 ==.
      000D2E 22               [24] 3046 	ret
                                   3047 ;------------------------------------------------------------
                                   3048 ;Allocation info for local variables in function 'fuzzy_triangle'
                                   3049 ;------------------------------------------------------------
                                   3050 ;b             Allocated to stack - _bp -6 +4 
                                   3051 ;c             Allocated to stack - _bp -10 +4 
                                   3052 ;value         Allocated to stack - _bp -14 +4 
                                   3053 ;hedge         Allocated to stack - _bp -15 +1 
                                   3054 ;a             Allocated to registers r7 r6 r5 r4 
                                   3055 ;result        Allocated to stack - _bp +1 +4 
                                   3056 ;sloc0         Allocated to stack - _bp +1 +4 
                                   3057 ;sloc1         Allocated to stack - _bp +5 +4 
                                   3058 ;------------------------------------------------------------
                           000C72  3059 	G$fuzzy_triangle$0$0 ==.
                           000C72  3060 	C$fuzzy.h$1380$1_0$73 ==.
                                   3061 ;	../../fuzzy.h:1380: float fuzzy_triangle(
                                   3062 ;	-----------------------------------------
                                   3063 ;	 function fuzzy_triangle
                                   3064 ;	-----------------------------------------
      000D2F                       3065 _fuzzy_triangle:
      000D2F C0 08            [24] 3066 	push	_bp
      000D31 85 81 08         [24] 3067 	mov	_bp,sp
      000D34 AF 82            [24] 3068 	mov	r7,dpl
      000D36 AE 83            [24] 3069 	mov	r6,dph
      000D38 AD F0            [24] 3070 	mov	r5,b
      000D3A FC               [12] 3071 	mov	r4,a
      000D3B E5 81            [12] 3072 	mov	a,sp
      000D3D 24 08            [12] 3073 	add	a,#0x08
      000D3F F5 81            [12] 3074 	mov	sp,a
                           000C84  3075 	C$fuzzy.h$1391$1_0$73 ==.
                                   3076 ;	../../fuzzy.h:1391: a >= b ||
      000D41 C0 07            [24] 3077 	push	ar7
      000D43 C0 06            [24] 3078 	push	ar6
      000D45 C0 05            [24] 3079 	push	ar5
      000D47 C0 04            [24] 3080 	push	ar4
      000D49 E5 08            [12] 3081 	mov	a,_bp
      000D4B 24 FA            [12] 3082 	add	a,#0xfa
      000D4D F8               [12] 3083 	mov	r0,a
      000D4E E6               [12] 3084 	mov	a,@r0
      000D4F C0 E0            [24] 3085 	push	acc
      000D51 08               [12] 3086 	inc	r0
      000D52 E6               [12] 3087 	mov	a,@r0
      000D53 C0 E0            [24] 3088 	push	acc
      000D55 08               [12] 3089 	inc	r0
      000D56 E6               [12] 3090 	mov	a,@r0
      000D57 C0 E0            [24] 3091 	push	acc
      000D59 08               [12] 3092 	inc	r0
      000D5A E6               [12] 3093 	mov	a,@r0
      000D5B C0 E0            [24] 3094 	push	acc
      000D5D 8F 82            [24] 3095 	mov	dpl, r7
      000D5F 8E 83            [24] 3096 	mov	dph, r6
      000D61 8D F0            [24] 3097 	mov	b, r5
      000D63 EC               [12] 3098 	mov	a, r4
      000D64 12 41 7C         [24] 3099 	lcall	___fslt
      000D67 E5 81            [12] 3100 	mov	a,sp
      000D69 24 FC            [12] 3101 	add	a,#0xfc
      000D6B F5 81            [12] 3102 	mov	sp,a
      000D6D D0 04            [24] 3103 	pop	ar4
      000D6F D0 05            [24] 3104 	pop	ar5
      000D71 D0 06            [24] 3105 	pop	ar6
      000D73 D0 07            [24] 3106 	pop	ar7
      000D75 E5 82            [12] 3107 	mov	a, dpl
      000D77 24 FF            [12] 3108 	add	a,#0xff
      000D79 92 00            [24] 3109 	mov	b0,c
      000D7B 40 03            [24] 3110 	jc	00145$
      000D7D 02 0E 47         [24] 3111 	ljmp	00107$
      000D80                       3112 00145$:
                           000CC3  3113 	C$fuzzy.h$1392$1_0$73 ==.
                                   3114 ;	../../fuzzy.h:1392: b >= c ||
      000D80 C0 07            [24] 3115 	push	ar7
      000D82 C0 06            [24] 3116 	push	ar6
      000D84 C0 05            [24] 3117 	push	ar5
      000D86 C0 04            [24] 3118 	push	ar4
      000D88 E5 08            [12] 3119 	mov	a,_bp
      000D8A 24 F6            [12] 3120 	add	a,#0xf6
      000D8C F8               [12] 3121 	mov	r0,a
      000D8D E6               [12] 3122 	mov	a,@r0
      000D8E C0 E0            [24] 3123 	push	acc
      000D90 08               [12] 3124 	inc	r0
      000D91 E6               [12] 3125 	mov	a,@r0
      000D92 C0 E0            [24] 3126 	push	acc
      000D94 08               [12] 3127 	inc	r0
      000D95 E6               [12] 3128 	mov	a,@r0
      000D96 C0 E0            [24] 3129 	push	acc
      000D98 08               [12] 3130 	inc	r0
      000D99 E6               [12] 3131 	mov	a,@r0
      000D9A C0 E0            [24] 3132 	push	acc
      000D9C E5 08            [12] 3133 	mov	a,_bp
      000D9E 24 FA            [12] 3134 	add	a,#0xfa
      000DA0 F8               [12] 3135 	mov	r0,a
      000DA1 86 82            [24] 3136 	mov	dpl, @r0
      000DA3 08               [12] 3137 	inc	r0
      000DA4 86 83            [24] 3138 	mov	dph, @r0
      000DA6 08               [12] 3139 	inc	r0
      000DA7 86 F0            [24] 3140 	mov	b, @r0
      000DA9 08               [12] 3141 	inc	r0
      000DAA E6               [12] 3142 	mov	a, @r0
      000DAB 12 41 7C         [24] 3143 	lcall	___fslt
      000DAE E5 81            [12] 3144 	mov	a,sp
      000DB0 24 FC            [12] 3145 	add	a,#0xfc
      000DB2 F5 81            [12] 3146 	mov	sp,a
      000DB4 D0 04            [24] 3147 	pop	ar4
      000DB6 D0 05            [24] 3148 	pop	ar5
      000DB8 D0 06            [24] 3149 	pop	ar6
      000DBA D0 07            [24] 3150 	pop	ar7
      000DBC E5 82            [12] 3151 	mov	a, dpl
      000DBE 24 FF            [12] 3152 	add	a,#0xff
      000DC0 92 00            [24] 3153 	mov	b0,c
      000DC2 40 03            [24] 3154 	jc	00146$
      000DC4 02 0E 47         [24] 3155 	ljmp	00107$
      000DC7                       3156 00146$:
                           000D0A  3157 	C$fuzzy.h$1393$1_0$73 ==.
                                   3158 ;	../../fuzzy.h:1393: value <= a ||
      000DC7 C0 07            [24] 3159 	push	ar7
      000DC9 C0 06            [24] 3160 	push	ar6
      000DCB C0 05            [24] 3161 	push	ar5
      000DCD C0 04            [24] 3162 	push	ar4
      000DCF E5 08            [12] 3163 	mov	a,_bp
      000DD1 24 F2            [12] 3164 	add	a,#0xf2
      000DD3 F8               [12] 3165 	mov	r0,a
      000DD4 E6               [12] 3166 	mov	a,@r0
      000DD5 C0 E0            [24] 3167 	push	acc
      000DD7 08               [12] 3168 	inc	r0
      000DD8 E6               [12] 3169 	mov	a,@r0
      000DD9 C0 E0            [24] 3170 	push	acc
      000DDB 08               [12] 3171 	inc	r0
      000DDC E6               [12] 3172 	mov	a,@r0
      000DDD C0 E0            [24] 3173 	push	acc
      000DDF 08               [12] 3174 	inc	r0
      000DE0 E6               [12] 3175 	mov	a,@r0
      000DE1 C0 E0            [24] 3176 	push	acc
      000DE3 8F 82            [24] 3177 	mov	dpl, r7
      000DE5 8E 83            [24] 3178 	mov	dph, r6
      000DE7 8D F0            [24] 3179 	mov	b, r5
      000DE9 EC               [12] 3180 	mov	a, r4
      000DEA 12 41 7C         [24] 3181 	lcall	___fslt
      000DED E5 81            [12] 3182 	mov	a,sp
      000DEF 24 FC            [12] 3183 	add	a,#0xfc
      000DF1 F5 81            [12] 3184 	mov	sp,a
      000DF3 D0 04            [24] 3185 	pop	ar4
      000DF5 D0 05            [24] 3186 	pop	ar5
      000DF7 D0 06            [24] 3187 	pop	ar6
      000DF9 D0 07            [24] 3188 	pop	ar7
      000DFB E5 82            [12] 3189 	mov	a, dpl
      000DFD 24 FF            [12] 3190 	add	a,#0xff
      000DFF 92 00            [24] 3191 	mov	b0,c
      000E01 50 44            [24] 3192 	jnc	00107$
                           000D46  3193 	C$fuzzy.h$1395$1_0$73 ==.
                                   3194 ;	../../fuzzy.h:1395: ) {
      000E03 C0 07            [24] 3195 	push	ar7
      000E05 C0 06            [24] 3196 	push	ar6
      000E07 C0 05            [24] 3197 	push	ar5
      000E09 C0 04            [24] 3198 	push	ar4
      000E0B E5 08            [12] 3199 	mov	a,_bp
      000E0D 24 F6            [12] 3200 	add	a,#0xf6
      000E0F F8               [12] 3201 	mov	r0,a
      000E10 E6               [12] 3202 	mov	a,@r0
      000E11 C0 E0            [24] 3203 	push	acc
      000E13 08               [12] 3204 	inc	r0
      000E14 E6               [12] 3205 	mov	a,@r0
      000E15 C0 E0            [24] 3206 	push	acc
      000E17 08               [12] 3207 	inc	r0
      000E18 E6               [12] 3208 	mov	a,@r0
      000E19 C0 E0            [24] 3209 	push	acc
      000E1B 08               [12] 3210 	inc	r0
      000E1C E6               [12] 3211 	mov	a,@r0
      000E1D C0 E0            [24] 3212 	push	acc
      000E1F E5 08            [12] 3213 	mov	a,_bp
      000E21 24 F2            [12] 3214 	add	a,#0xf2
      000E23 F8               [12] 3215 	mov	r0,a
      000E24 86 82            [24] 3216 	mov	dpl, @r0
      000E26 08               [12] 3217 	inc	r0
      000E27 86 83            [24] 3218 	mov	dph, @r0
      000E29 08               [12] 3219 	inc	r0
      000E2A 86 F0            [24] 3220 	mov	b, @r0
      000E2C 08               [12] 3221 	inc	r0
      000E2D E6               [12] 3222 	mov	a, @r0
      000E2E 12 41 7C         [24] 3223 	lcall	___fslt
      000E31 E5 81            [12] 3224 	mov	a,sp
      000E33 24 FC            [12] 3225 	add	a,#0xfc
      000E35 F5 81            [12] 3226 	mov	sp,a
      000E37 D0 04            [24] 3227 	pop	ar4
      000E39 D0 05            [24] 3228 	pop	ar5
      000E3B D0 06            [24] 3229 	pop	ar6
      000E3D D0 07            [24] 3230 	pop	ar7
      000E3F E5 82            [12] 3231 	mov	a, dpl
      000E41 24 FF            [12] 3232 	add	a,#0xff
      000E43 92 00            [24] 3233 	mov	b0,c
      000E45 40 0E            [24] 3234 	jc	00108$
      000E47                       3235 00107$:
                           000D8A  3236 	C$fuzzy.h$1396$2_0$74 ==.
                                   3237 ;	../../fuzzy.h:1396: result = LEVEL_LO;
      000E47 A8 08            [24] 3238 	mov	r0,_bp
      000E49 08               [12] 3239 	inc	r0
      000E4A E4               [12] 3240 	clr	a
      000E4B F6               [12] 3241 	mov	@r0,a
      000E4C 08               [12] 3242 	inc	r0
      000E4D F6               [12] 3243 	mov	@r0,a
      000E4E 08               [12] 3244 	inc	r0
      000E4F F6               [12] 3245 	mov	@r0,a
      000E50 08               [12] 3246 	inc	r0
      000E51 F6               [12] 3247 	mov	@r0,a
      000E52 02 10 0D         [24] 3248 	ljmp	00109$
      000E55                       3249 00108$:
                           000D98  3250 	C$fuzzy.h$1398$1_0$73 ==.
                                   3251 ;	../../fuzzy.h:1398: else if (value == b) {
      000E55 C0 07            [24] 3252 	push	ar7
      000E57 C0 06            [24] 3253 	push	ar6
      000E59 C0 05            [24] 3254 	push	ar5
      000E5B C0 04            [24] 3255 	push	ar4
      000E5D E5 08            [12] 3256 	mov	a,_bp
      000E5F 24 FA            [12] 3257 	add	a,#0xfa
      000E61 F8               [12] 3258 	mov	r0,a
      000E62 E6               [12] 3259 	mov	a,@r0
      000E63 C0 E0            [24] 3260 	push	acc
      000E65 08               [12] 3261 	inc	r0
      000E66 E6               [12] 3262 	mov	a,@r0
      000E67 C0 E0            [24] 3263 	push	acc
      000E69 08               [12] 3264 	inc	r0
      000E6A E6               [12] 3265 	mov	a,@r0
      000E6B C0 E0            [24] 3266 	push	acc
      000E6D 08               [12] 3267 	inc	r0
      000E6E E6               [12] 3268 	mov	a,@r0
      000E6F C0 E0            [24] 3269 	push	acc
      000E71 E5 08            [12] 3270 	mov	a,_bp
      000E73 24 F2            [12] 3271 	add	a,#0xf2
      000E75 F8               [12] 3272 	mov	r0,a
      000E76 86 82            [24] 3273 	mov	dpl, @r0
      000E78 08               [12] 3274 	inc	r0
      000E79 86 83            [24] 3275 	mov	dph, @r0
      000E7B 08               [12] 3276 	inc	r0
      000E7C 86 F0            [24] 3277 	mov	b, @r0
      000E7E 08               [12] 3278 	inc	r0
      000E7F E6               [12] 3279 	mov	a, @r0
      000E80 12 41 50         [24] 3280 	lcall	___fseq
      000E83 AB 82            [24] 3281 	mov	r3, dpl
      000E85 E5 81            [12] 3282 	mov	a,sp
      000E87 24 FC            [12] 3283 	add	a,#0xfc
      000E89 F5 81            [12] 3284 	mov	sp,a
      000E8B D0 04            [24] 3285 	pop	ar4
      000E8D D0 05            [24] 3286 	pop	ar5
      000E8F D0 06            [24] 3287 	pop	ar6
      000E91 D0 07            [24] 3288 	pop	ar7
      000E93 EB               [12] 3289 	mov	a,r3
      000E94 60 10            [24] 3290 	jz	00105$
                           000DD9  3291 	C$fuzzy.h$1399$2_0$75 ==.
                                   3292 ;	../../fuzzy.h:1399: result = LEVEL_HI;
      000E96 A8 08            [24] 3293 	mov	r0,_bp
      000E98 08               [12] 3294 	inc	r0
      000E99 E4               [12] 3295 	clr	a
      000E9A F6               [12] 3296 	mov	@r0,a
      000E9B 08               [12] 3297 	inc	r0
      000E9C F6               [12] 3298 	mov	@r0,a
      000E9D 08               [12] 3299 	inc	r0
      000E9E 76 80            [12] 3300 	mov	@r0,#0x80
      000EA0 08               [12] 3301 	inc	r0
      000EA1 76 3F            [12] 3302 	mov	@r0,#0x3f
      000EA3 02 10 0D         [24] 3303 	ljmp	00109$
      000EA6                       3304 00105$:
                           000DE9  3305 	C$fuzzy.h$1401$1_0$73 ==.
                                   3306 ;	../../fuzzy.h:1401: else if (value < b) {
      000EA6 C0 07            [24] 3307 	push	ar7
      000EA8 C0 06            [24] 3308 	push	ar6
      000EAA C0 05            [24] 3309 	push	ar5
      000EAC C0 04            [24] 3310 	push	ar4
      000EAE E5 08            [12] 3311 	mov	a,_bp
      000EB0 24 FA            [12] 3312 	add	a,#0xfa
      000EB2 F8               [12] 3313 	mov	r0,a
      000EB3 E6               [12] 3314 	mov	a,@r0
      000EB4 C0 E0            [24] 3315 	push	acc
      000EB6 08               [12] 3316 	inc	r0
      000EB7 E6               [12] 3317 	mov	a,@r0
      000EB8 C0 E0            [24] 3318 	push	acc
      000EBA 08               [12] 3319 	inc	r0
      000EBB E6               [12] 3320 	mov	a,@r0
      000EBC C0 E0            [24] 3321 	push	acc
      000EBE 08               [12] 3322 	inc	r0
      000EBF E6               [12] 3323 	mov	a,@r0
      000EC0 C0 E0            [24] 3324 	push	acc
      000EC2 E5 08            [12] 3325 	mov	a,_bp
      000EC4 24 F2            [12] 3326 	add	a,#0xf2
      000EC6 F8               [12] 3327 	mov	r0,a
      000EC7 86 82            [24] 3328 	mov	dpl, @r0
      000EC9 08               [12] 3329 	inc	r0
      000ECA 86 83            [24] 3330 	mov	dph, @r0
      000ECC 08               [12] 3331 	inc	r0
      000ECD 86 F0            [24] 3332 	mov	b, @r0
      000ECF 08               [12] 3333 	inc	r0
      000ED0 E6               [12] 3334 	mov	a, @r0
      000ED1 12 41 7C         [24] 3335 	lcall	___fslt
      000ED4 AB 82            [24] 3336 	mov	r3, dpl
      000ED6 E5 81            [12] 3337 	mov	a,sp
      000ED8 24 FC            [12] 3338 	add	a,#0xfc
      000EDA F5 81            [12] 3339 	mov	sp,a
      000EDC D0 04            [24] 3340 	pop	ar4
      000EDE D0 05            [24] 3341 	pop	ar5
      000EE0 D0 06            [24] 3342 	pop	ar6
      000EE2 D0 07            [24] 3343 	pop	ar7
      000EE4 EB               [12] 3344 	mov	a,r3
      000EE5 70 03            [24] 3345 	jnz	00150$
      000EE7 02 0F 71         [24] 3346 	ljmp	00102$
      000EEA                       3347 00150$:
                           000E2D  3348 	C$fuzzy.h$1403$1_0$73 ==.
                                   3349 ;	../../fuzzy.h:1403: (value - a) /
      000EEA C0 07            [24] 3350 	push	ar7
      000EEC C0 06            [24] 3351 	push	ar6
      000EEE C0 05            [24] 3352 	push	ar5
      000EF0 C0 04            [24] 3353 	push	ar4
      000EF2 C0 07            [24] 3354 	push	ar7
      000EF4 C0 06            [24] 3355 	push	ar6
      000EF6 C0 05            [24] 3356 	push	ar5
      000EF8 C0 04            [24] 3357 	push	ar4
                           000E3D  3358 	C$fuzzy.h$1404$1_0$73 ==.
                                   3359 ;	../../fuzzy.h:1404: (b - a);
      000EFA E5 08            [12] 3360 	mov	a,_bp
      000EFC 24 F2            [12] 3361 	add	a,#0xf2
      000EFE F8               [12] 3362 	mov	r0,a
      000EFF 86 82            [24] 3363 	mov	dpl, @r0
      000F01 08               [12] 3364 	inc	r0
      000F02 86 83            [24] 3365 	mov	dph, @r0
      000F04 08               [12] 3366 	inc	r0
      000F05 86 F0            [24] 3367 	mov	b, @r0
      000F07 08               [12] 3368 	inc	r0
      000F08 E6               [12] 3369 	mov	a, @r0
      000F09 12 40 41         [24] 3370 	lcall	___fssub
      000F0C C8               [12] 3371 	xch	a,r0
      000F0D E5 08            [12] 3372 	mov	a,_bp
      000F0F 24 05            [12] 3373 	add	a,#0x05
      000F11 C8               [12] 3374 	xch	a,r0
      000F12 A6 82            [24] 3375 	mov	@r0, dpl
      000F14 08               [12] 3376 	inc	r0
      000F15 A6 83            [24] 3377 	mov	@r0, dph
      000F17 08               [12] 3378 	inc	r0
      000F18 A6 F0            [24] 3379 	mov	@r0, b
      000F1A 08               [12] 3380 	inc	r0
      000F1B F6               [12] 3381 	mov	@r0,a
      000F1C E5 81            [12] 3382 	mov	a,sp
      000F1E 24 FC            [12] 3383 	add	a,#0xfc
      000F20 F5 81            [12] 3384 	mov	sp,a
      000F22 E5 08            [12] 3385 	mov	a,_bp
      000F24 24 FA            [12] 3386 	add	a,#0xfa
      000F26 F8               [12] 3387 	mov	r0,a
      000F27 86 82            [24] 3388 	mov	dpl, @r0
      000F29 08               [12] 3389 	inc	r0
      000F2A 86 83            [24] 3390 	mov	dph, @r0
      000F2C 08               [12] 3391 	inc	r0
      000F2D 86 F0            [24] 3392 	mov	b, @r0
      000F2F 08               [12] 3393 	inc	r0
      000F30 E6               [12] 3394 	mov	a, @r0
      000F31 12 40 41         [24] 3395 	lcall	___fssub
      000F34 AC 82            [24] 3396 	mov	r4, dpl
      000F36 AD 83            [24] 3397 	mov	r5, dph
      000F38 AE F0            [24] 3398 	mov	r6, b
      000F3A FF               [12] 3399 	mov	r7, a
      000F3B E5 81            [12] 3400 	mov	a,sp
      000F3D 24 FC            [12] 3401 	add	a,#0xfc
      000F3F F5 81            [12] 3402 	mov	sp,a
      000F41 C0 04            [24] 3403 	push	ar4
      000F43 C0 05            [24] 3404 	push	ar5
      000F45 C0 06            [24] 3405 	push	ar6
      000F47 C0 07            [24] 3406 	push	ar7
      000F49 E5 08            [12] 3407 	mov	a,_bp
      000F4B 24 05            [12] 3408 	add	a,#0x05
      000F4D F8               [12] 3409 	mov	r0,a
      000F4E 86 82            [24] 3410 	mov	dpl, @r0
      000F50 08               [12] 3411 	inc	r0
      000F51 86 83            [24] 3412 	mov	dph, @r0
      000F53 08               [12] 3413 	inc	r0
      000F54 86 F0            [24] 3414 	mov	b, @r0
      000F56 08               [12] 3415 	inc	r0
      000F57 E6               [12] 3416 	mov	a, @r0
      000F58 12 42 E5         [24] 3417 	lcall	___fsdiv
      000F5B A8 08            [24] 3418 	mov	r0,_bp
      000F5D 08               [12] 3419 	inc	r0
      000F5E A6 82            [24] 3420 	mov	@r0, dpl
      000F60 08               [12] 3421 	inc	r0
      000F61 A6 83            [24] 3422 	mov	@r0, dph
      000F63 08               [12] 3423 	inc	r0
      000F64 A6 F0            [24] 3424 	mov	@r0, b
      000F66 08               [12] 3425 	inc	r0
      000F67 F6               [12] 3426 	mov	@r0,a
      000F68 E5 81            [12] 3427 	mov	a,sp
      000F6A 24 FC            [12] 3428 	add	a,#0xfc
      000F6C F5 81            [12] 3429 	mov	sp,a
      000F6E 02 10 0D         [24] 3430 	ljmp	00109$
      000F71                       3431 00102$:
                           000EB4  3432 	C$fuzzy.h$1408$1_0$73 ==.
                                   3433 ;	../../fuzzy.h:1408: (c - value) /
      000F71 E5 08            [12] 3434 	mov	a,_bp
      000F73 24 F2            [12] 3435 	add	a,#0xf2
      000F75 F8               [12] 3436 	mov	r0,a
      000F76 E6               [12] 3437 	mov	a,@r0
      000F77 C0 E0            [24] 3438 	push	acc
      000F79 08               [12] 3439 	inc	r0
      000F7A E6               [12] 3440 	mov	a,@r0
      000F7B C0 E0            [24] 3441 	push	acc
      000F7D 08               [12] 3442 	inc	r0
      000F7E E6               [12] 3443 	mov	a,@r0
      000F7F C0 E0            [24] 3444 	push	acc
      000F81 08               [12] 3445 	inc	r0
      000F82 E6               [12] 3446 	mov	a,@r0
      000F83 C0 E0            [24] 3447 	push	acc
                           000EC8  3448 	C$fuzzy.h$1409$1_0$73 ==.
                                   3449 ;	../../fuzzy.h:1409: (c - b);
      000F85 E5 08            [12] 3450 	mov	a,_bp
      000F87 24 F6            [12] 3451 	add	a,#0xf6
      000F89 F8               [12] 3452 	mov	r0,a
      000F8A 86 82            [24] 3453 	mov	dpl, @r0
      000F8C 08               [12] 3454 	inc	r0
      000F8D 86 83            [24] 3455 	mov	dph, @r0
      000F8F 08               [12] 3456 	inc	r0
      000F90 86 F0            [24] 3457 	mov	b, @r0
      000F92 08               [12] 3458 	inc	r0
      000F93 E6               [12] 3459 	mov	a, @r0
      000F94 12 40 41         [24] 3460 	lcall	___fssub
      000F97 C8               [12] 3461 	xch	a,r0
      000F98 E5 08            [12] 3462 	mov	a,_bp
      000F9A 24 05            [12] 3463 	add	a,#0x05
      000F9C C8               [12] 3464 	xch	a,r0
      000F9D A6 82            [24] 3465 	mov	@r0, dpl
      000F9F 08               [12] 3466 	inc	r0
      000FA0 A6 83            [24] 3467 	mov	@r0, dph
      000FA2 08               [12] 3468 	inc	r0
      000FA3 A6 F0            [24] 3469 	mov	@r0, b
      000FA5 08               [12] 3470 	inc	r0
      000FA6 F6               [12] 3471 	mov	@r0,a
      000FA7 E5 81            [12] 3472 	mov	a,sp
      000FA9 24 FC            [12] 3473 	add	a,#0xfc
      000FAB F5 81            [12] 3474 	mov	sp,a
      000FAD E5 08            [12] 3475 	mov	a,_bp
      000FAF 24 FA            [12] 3476 	add	a,#0xfa
      000FB1 F8               [12] 3477 	mov	r0,a
      000FB2 E6               [12] 3478 	mov	a,@r0
      000FB3 C0 E0            [24] 3479 	push	acc
      000FB5 08               [12] 3480 	inc	r0
      000FB6 E6               [12] 3481 	mov	a,@r0
      000FB7 C0 E0            [24] 3482 	push	acc
      000FB9 08               [12] 3483 	inc	r0
      000FBA E6               [12] 3484 	mov	a,@r0
      000FBB C0 E0            [24] 3485 	push	acc
      000FBD 08               [12] 3486 	inc	r0
      000FBE E6               [12] 3487 	mov	a,@r0
      000FBF C0 E0            [24] 3488 	push	acc
      000FC1 E5 08            [12] 3489 	mov	a,_bp
      000FC3 24 F6            [12] 3490 	add	a,#0xf6
      000FC5 F8               [12] 3491 	mov	r0,a
      000FC6 86 82            [24] 3492 	mov	dpl, @r0
      000FC8 08               [12] 3493 	inc	r0
      000FC9 86 83            [24] 3494 	mov	dph, @r0
      000FCB 08               [12] 3495 	inc	r0
      000FCC 86 F0            [24] 3496 	mov	b, @r0
      000FCE 08               [12] 3497 	inc	r0
      000FCF E6               [12] 3498 	mov	a, @r0
      000FD0 12 40 41         [24] 3499 	lcall	___fssub
      000FD3 AA 82            [24] 3500 	mov	r2, dpl
      000FD5 AB 83            [24] 3501 	mov	r3, dph
      000FD7 AE F0            [24] 3502 	mov	r6, b
      000FD9 FF               [12] 3503 	mov	r7, a
      000FDA E5 81            [12] 3504 	mov	a,sp
      000FDC 24 FC            [12] 3505 	add	a,#0xfc
      000FDE F5 81            [12] 3506 	mov	sp,a
      000FE0 C0 02            [24] 3507 	push	ar2
      000FE2 C0 03            [24] 3508 	push	ar3
      000FE4 C0 06            [24] 3509 	push	ar6
      000FE6 C0 07            [24] 3510 	push	ar7
      000FE8 E5 08            [12] 3511 	mov	a,_bp
      000FEA 24 05            [12] 3512 	add	a,#0x05
      000FEC F8               [12] 3513 	mov	r0,a
      000FED 86 82            [24] 3514 	mov	dpl, @r0
      000FEF 08               [12] 3515 	inc	r0
      000FF0 86 83            [24] 3516 	mov	dph, @r0
      000FF2 08               [12] 3517 	inc	r0
      000FF3 86 F0            [24] 3518 	mov	b, @r0
      000FF5 08               [12] 3519 	inc	r0
      000FF6 E6               [12] 3520 	mov	a, @r0
      000FF7 12 42 E5         [24] 3521 	lcall	___fsdiv
      000FFA A8 08            [24] 3522 	mov	r0,_bp
      000FFC 08               [12] 3523 	inc	r0
      000FFD A6 82            [24] 3524 	mov	@r0, dpl
      000FFF 08               [12] 3525 	inc	r0
      001000 A6 83            [24] 3526 	mov	@r0, dph
      001002 08               [12] 3527 	inc	r0
      001003 A6 F0            [24] 3528 	mov	@r0, b
      001005 08               [12] 3529 	inc	r0
      001006 F6               [12] 3530 	mov	@r0,a
      001007 E5 81            [12] 3531 	mov	a,sp
      001009 24 FC            [12] 3532 	add	a,#0xfc
      00100B F5 81            [12] 3533 	mov	sp,a
      00100D                       3534 00109$:
                           000F50  3535 	C$fuzzy.h$1413$1_0$73 ==.
                                   3536 ;	../../fuzzy.h:1413: result,
      00100D E5 08            [12] 3537 	mov	a,_bp
      00100F 24 F1            [12] 3538 	add	a,#0xf1
      001011 F8               [12] 3539 	mov	r0,a
      001012 E6               [12] 3540 	mov	a,@r0
      001013 C0 E0            [24] 3541 	push	acc
      001015 A8 08            [24] 3542 	mov	r0,_bp
      001017 08               [12] 3543 	inc	r0
      001018 86 82            [24] 3544 	mov	dpl, @r0
      00101A 08               [12] 3545 	inc	r0
      00101B 86 83            [24] 3546 	mov	dph, @r0
      00101D 08               [12] 3547 	inc	r0
      00101E 86 F0            [24] 3548 	mov	b, @r0
      001020 08               [12] 3549 	inc	r0
      001021 E6               [12] 3550 	mov	a, @r0
      001022 12 01 9F         [24] 3551 	lcall	_fuzzy_apply_hedge
      001025 AC 82            [24] 3552 	mov	r4, dpl
      001027 AD 83            [24] 3553 	mov	r5, dph
      001029 AE F0            [24] 3554 	mov	r6, b
      00102B FF               [12] 3555 	mov	r7, a
      00102C 15 81            [12] 3556 	dec	sp
      00102E 8C 82            [24] 3557 	mov	dpl, r4
      001030 8D 83            [24] 3558 	mov	dph, r5
      001032 8E F0            [24] 3559 	mov	b, r6
      001034 EF               [12] 3560 	mov	a, r7
                           000F78  3561 	C$fuzzy.h$1416$1_0$73 ==.
                                   3562 ;	../../fuzzy.h:1416: }
      001035 85 08 81         [24] 3563 	mov	sp,_bp
      001038 D0 08            [24] 3564 	pop	_bp
                           000F7D  3565 	C$fuzzy.h$1416$1_0$73 ==.
                           000F7D  3566 	XG$fuzzy_triangle$0$0 ==.
      00103A 22               [24] 3567 	ret
                                   3568 ;------------------------------------------------------------
                                   3569 ;Allocation info for local variables in function 'fuzzy_trapezoid'
                                   3570 ;------------------------------------------------------------
                                   3571 ;b             Allocated to stack - _bp -6 +4 
                                   3572 ;c             Allocated to stack - _bp -10 +4 
                                   3573 ;d             Allocated to stack - _bp -14 +4 
                                   3574 ;value         Allocated to stack - _bp -18 +4 
                                   3575 ;hedge         Allocated to stack - _bp -19 +1 
                                   3576 ;a             Allocated to registers r7 r6 r5 r4 
                                   3577 ;result        Allocated to stack - _bp +1 +4 
                                   3578 ;sloc0         Allocated to stack - _bp +1 +4 
                                   3579 ;sloc1         Allocated to stack - _bp +5 +4 
                                   3580 ;------------------------------------------------------------
                           000F7E  3581 	G$fuzzy_trapezoid$0$0 ==.
                           000F7E  3582 	C$fuzzy.h$1418$1_0$79 ==.
                                   3583 ;	../../fuzzy.h:1418: float fuzzy_trapezoid(
                                   3584 ;	-----------------------------------------
                                   3585 ;	 function fuzzy_trapezoid
                                   3586 ;	-----------------------------------------
      00103B                       3587 _fuzzy_trapezoid:
      00103B C0 08            [24] 3588 	push	_bp
      00103D 85 81 08         [24] 3589 	mov	_bp,sp
      001040 AF 82            [24] 3590 	mov	r7,dpl
      001042 AE 83            [24] 3591 	mov	r6,dph
      001044 AD F0            [24] 3592 	mov	r5,b
      001046 FC               [12] 3593 	mov	r4,a
      001047 E5 81            [12] 3594 	mov	a,sp
      001049 24 08            [12] 3595 	add	a,#0x08
      00104B F5 81            [12] 3596 	mov	sp,a
                           000F90  3597 	C$fuzzy.h$1430$1_0$79 ==.
                                   3598 ;	../../fuzzy.h:1430: a >= b ||
      00104D C0 07            [24] 3599 	push	ar7
      00104F C0 06            [24] 3600 	push	ar6
      001051 C0 05            [24] 3601 	push	ar5
      001053 C0 04            [24] 3602 	push	ar4
      001055 E5 08            [12] 3603 	mov	a,_bp
      001057 24 FA            [12] 3604 	add	a,#0xfa
      001059 F8               [12] 3605 	mov	r0,a
      00105A E6               [12] 3606 	mov	a,@r0
      00105B C0 E0            [24] 3607 	push	acc
      00105D 08               [12] 3608 	inc	r0
      00105E E6               [12] 3609 	mov	a,@r0
      00105F C0 E0            [24] 3610 	push	acc
      001061 08               [12] 3611 	inc	r0
      001062 E6               [12] 3612 	mov	a,@r0
      001063 C0 E0            [24] 3613 	push	acc
      001065 08               [12] 3614 	inc	r0
      001066 E6               [12] 3615 	mov	a,@r0
      001067 C0 E0            [24] 3616 	push	acc
      001069 8F 82            [24] 3617 	mov	dpl, r7
      00106B 8E 83            [24] 3618 	mov	dph, r6
      00106D 8D F0            [24] 3619 	mov	b, r5
      00106F EC               [12] 3620 	mov	a, r4
      001070 12 41 7C         [24] 3621 	lcall	___fslt
      001073 E5 81            [12] 3622 	mov	a,sp
      001075 24 FC            [12] 3623 	add	a,#0xfc
      001077 F5 81            [12] 3624 	mov	sp,a
      001079 D0 04            [24] 3625 	pop	ar4
      00107B D0 05            [24] 3626 	pop	ar5
      00107D D0 06            [24] 3627 	pop	ar6
      00107F D0 07            [24] 3628 	pop	ar7
      001081 E5 82            [12] 3629 	mov	a, dpl
      001083 24 FF            [12] 3630 	add	a,#0xff
      001085 92 00            [24] 3631 	mov	b0,c
      001087 40 03            [24] 3632 	jc	00159$
      001089 02 11 97         [24] 3633 	ljmp	00108$
      00108C                       3634 00159$:
                           000FCF  3635 	C$fuzzy.h$1431$1_0$79 ==.
                                   3636 ;	../../fuzzy.h:1431: b > c ||
      00108C C0 07            [24] 3637 	push	ar7
      00108E C0 06            [24] 3638 	push	ar6
      001090 C0 05            [24] 3639 	push	ar5
      001092 C0 04            [24] 3640 	push	ar4
      001094 E5 08            [12] 3641 	mov	a,_bp
      001096 24 FA            [12] 3642 	add	a,#0xfa
      001098 F8               [12] 3643 	mov	r0,a
      001099 E6               [12] 3644 	mov	a,@r0
      00109A C0 E0            [24] 3645 	push	acc
      00109C 08               [12] 3646 	inc	r0
      00109D E6               [12] 3647 	mov	a,@r0
      00109E C0 E0            [24] 3648 	push	acc
      0010A0 08               [12] 3649 	inc	r0
      0010A1 E6               [12] 3650 	mov	a,@r0
      0010A2 C0 E0            [24] 3651 	push	acc
      0010A4 08               [12] 3652 	inc	r0
      0010A5 E6               [12] 3653 	mov	a,@r0
      0010A6 C0 E0            [24] 3654 	push	acc
      0010A8 E5 08            [12] 3655 	mov	a,_bp
      0010AA 24 F6            [12] 3656 	add	a,#0xf6
      0010AC F8               [12] 3657 	mov	r0,a
      0010AD 86 82            [24] 3658 	mov	dpl, @r0
      0010AF 08               [12] 3659 	inc	r0
      0010B0 86 83            [24] 3660 	mov	dph, @r0
      0010B2 08               [12] 3661 	inc	r0
      0010B3 86 F0            [24] 3662 	mov	b, @r0
      0010B5 08               [12] 3663 	inc	r0
      0010B6 E6               [12] 3664 	mov	a, @r0
      0010B7 12 41 7C         [24] 3665 	lcall	___fslt
      0010BA AB 82            [24] 3666 	mov	r3, dpl
      0010BC E5 81            [12] 3667 	mov	a,sp
      0010BE 24 FC            [12] 3668 	add	a,#0xfc
      0010C0 F5 81            [12] 3669 	mov	sp,a
      0010C2 D0 04            [24] 3670 	pop	ar4
      0010C4 D0 05            [24] 3671 	pop	ar5
      0010C6 D0 06            [24] 3672 	pop	ar6
      0010C8 D0 07            [24] 3673 	pop	ar7
      0010CA EB               [12] 3674 	mov	a,r3
      0010CB 60 03            [24] 3675 	jz	00160$
      0010CD 02 11 97         [24] 3676 	ljmp	00108$
      0010D0                       3677 00160$:
                           001013  3678 	C$fuzzy.h$1432$1_0$79 ==.
                                   3679 ;	../../fuzzy.h:1432: c >= d ||
      0010D0 C0 07            [24] 3680 	push	ar7
      0010D2 C0 06            [24] 3681 	push	ar6
      0010D4 C0 05            [24] 3682 	push	ar5
      0010D6 C0 04            [24] 3683 	push	ar4
      0010D8 E5 08            [12] 3684 	mov	a,_bp
      0010DA 24 F2            [12] 3685 	add	a,#0xf2
      0010DC F8               [12] 3686 	mov	r0,a
      0010DD E6               [12] 3687 	mov	a,@r0
      0010DE C0 E0            [24] 3688 	push	acc
      0010E0 08               [12] 3689 	inc	r0
      0010E1 E6               [12] 3690 	mov	a,@r0
      0010E2 C0 E0            [24] 3691 	push	acc
      0010E4 08               [12] 3692 	inc	r0
      0010E5 E6               [12] 3693 	mov	a,@r0
      0010E6 C0 E0            [24] 3694 	push	acc
      0010E8 08               [12] 3695 	inc	r0
      0010E9 E6               [12] 3696 	mov	a,@r0
      0010EA C0 E0            [24] 3697 	push	acc
      0010EC E5 08            [12] 3698 	mov	a,_bp
      0010EE 24 F6            [12] 3699 	add	a,#0xf6
      0010F0 F8               [12] 3700 	mov	r0,a
      0010F1 86 82            [24] 3701 	mov	dpl, @r0
      0010F3 08               [12] 3702 	inc	r0
      0010F4 86 83            [24] 3703 	mov	dph, @r0
      0010F6 08               [12] 3704 	inc	r0
      0010F7 86 F0            [24] 3705 	mov	b, @r0
      0010F9 08               [12] 3706 	inc	r0
      0010FA E6               [12] 3707 	mov	a, @r0
      0010FB 12 41 7C         [24] 3708 	lcall	___fslt
      0010FE E5 81            [12] 3709 	mov	a,sp
      001100 24 FC            [12] 3710 	add	a,#0xfc
      001102 F5 81            [12] 3711 	mov	sp,a
      001104 D0 04            [24] 3712 	pop	ar4
      001106 D0 05            [24] 3713 	pop	ar5
      001108 D0 06            [24] 3714 	pop	ar6
      00110A D0 07            [24] 3715 	pop	ar7
      00110C E5 82            [12] 3716 	mov	a, dpl
      00110E 24 FF            [12] 3717 	add	a,#0xff
      001110 92 00            [24] 3718 	mov	b0,c
      001112 40 03            [24] 3719 	jc	00161$
      001114 02 11 97         [24] 3720 	ljmp	00108$
      001117                       3721 00161$:
                           00105A  3722 	C$fuzzy.h$1433$1_0$79 ==.
                                   3723 ;	../../fuzzy.h:1433: value <= a ||
      001117 C0 07            [24] 3724 	push	ar7
      001119 C0 06            [24] 3725 	push	ar6
      00111B C0 05            [24] 3726 	push	ar5
      00111D C0 04            [24] 3727 	push	ar4
      00111F E5 08            [12] 3728 	mov	a,_bp
      001121 24 EE            [12] 3729 	add	a,#0xee
      001123 F8               [12] 3730 	mov	r0,a
      001124 E6               [12] 3731 	mov	a,@r0
      001125 C0 E0            [24] 3732 	push	acc
      001127 08               [12] 3733 	inc	r0
      001128 E6               [12] 3734 	mov	a,@r0
      001129 C0 E0            [24] 3735 	push	acc
      00112B 08               [12] 3736 	inc	r0
      00112C E6               [12] 3737 	mov	a,@r0
      00112D C0 E0            [24] 3738 	push	acc
      00112F 08               [12] 3739 	inc	r0
      001130 E6               [12] 3740 	mov	a,@r0
      001131 C0 E0            [24] 3741 	push	acc
      001133 8F 82            [24] 3742 	mov	dpl, r7
      001135 8E 83            [24] 3743 	mov	dph, r6
      001137 8D F0            [24] 3744 	mov	b, r5
      001139 EC               [12] 3745 	mov	a, r4
      00113A 12 41 7C         [24] 3746 	lcall	___fslt
      00113D E5 81            [12] 3747 	mov	a,sp
      00113F 24 FC            [12] 3748 	add	a,#0xfc
      001141 F5 81            [12] 3749 	mov	sp,a
      001143 D0 04            [24] 3750 	pop	ar4
      001145 D0 05            [24] 3751 	pop	ar5
      001147 D0 06            [24] 3752 	pop	ar6
      001149 D0 07            [24] 3753 	pop	ar7
      00114B E5 82            [12] 3754 	mov	a, dpl
      00114D 24 FF            [12] 3755 	add	a,#0xff
      00114F 92 00            [24] 3756 	mov	b0,c
      001151 50 44            [24] 3757 	jnc	00108$
                           001096  3758 	C$fuzzy.h$1435$1_0$79 ==.
                                   3759 ;	../../fuzzy.h:1435: ) {
      001153 C0 07            [24] 3760 	push	ar7
      001155 C0 06            [24] 3761 	push	ar6
      001157 C0 05            [24] 3762 	push	ar5
      001159 C0 04            [24] 3763 	push	ar4
      00115B E5 08            [12] 3764 	mov	a,_bp
      00115D 24 F2            [12] 3765 	add	a,#0xf2
      00115F F8               [12] 3766 	mov	r0,a
      001160 E6               [12] 3767 	mov	a,@r0
      001161 C0 E0            [24] 3768 	push	acc
      001163 08               [12] 3769 	inc	r0
      001164 E6               [12] 3770 	mov	a,@r0
      001165 C0 E0            [24] 3771 	push	acc
      001167 08               [12] 3772 	inc	r0
      001168 E6               [12] 3773 	mov	a,@r0
      001169 C0 E0            [24] 3774 	push	acc
      00116B 08               [12] 3775 	inc	r0
      00116C E6               [12] 3776 	mov	a,@r0
      00116D C0 E0            [24] 3777 	push	acc
      00116F E5 08            [12] 3778 	mov	a,_bp
      001171 24 EE            [12] 3779 	add	a,#0xee
      001173 F8               [12] 3780 	mov	r0,a
      001174 86 82            [24] 3781 	mov	dpl, @r0
      001176 08               [12] 3782 	inc	r0
      001177 86 83            [24] 3783 	mov	dph, @r0
      001179 08               [12] 3784 	inc	r0
      00117A 86 F0            [24] 3785 	mov	b, @r0
      00117C 08               [12] 3786 	inc	r0
      00117D E6               [12] 3787 	mov	a, @r0
      00117E 12 41 7C         [24] 3788 	lcall	___fslt
      001181 E5 81            [12] 3789 	mov	a,sp
      001183 24 FC            [12] 3790 	add	a,#0xfc
      001185 F5 81            [12] 3791 	mov	sp,a
      001187 D0 04            [24] 3792 	pop	ar4
      001189 D0 05            [24] 3793 	pop	ar5
      00118B D0 06            [24] 3794 	pop	ar6
      00118D D0 07            [24] 3795 	pop	ar7
      00118F E5 82            [12] 3796 	mov	a, dpl
      001191 24 FF            [12] 3797 	add	a,#0xff
      001193 92 00            [24] 3798 	mov	b0,c
      001195 40 0E            [24] 3799 	jc	00109$
      001197                       3800 00108$:
                           0010DA  3801 	C$fuzzy.h$1436$2_0$80 ==.
                                   3802 ;	../../fuzzy.h:1436: result = LEVEL_LO;
      001197 A8 08            [24] 3803 	mov	r0,_bp
      001199 08               [12] 3804 	inc	r0
      00119A E4               [12] 3805 	clr	a
      00119B F6               [12] 3806 	mov	@r0,a
      00119C 08               [12] 3807 	inc	r0
      00119D F6               [12] 3808 	mov	@r0,a
      00119E 08               [12] 3809 	inc	r0
      00119F F6               [12] 3810 	mov	@r0,a
      0011A0 08               [12] 3811 	inc	r0
      0011A1 F6               [12] 3812 	mov	@r0,a
      0011A2 02 13 A4         [24] 3813 	ljmp	00110$
      0011A5                       3814 00109$:
                           0010E8  3815 	C$fuzzy.h$1439$1_0$79 ==.
                                   3816 ;	../../fuzzy.h:1439: value >= b &&
      0011A5 C0 07            [24] 3817 	push	ar7
      0011A7 C0 06            [24] 3818 	push	ar6
      0011A9 C0 05            [24] 3819 	push	ar5
      0011AB C0 04            [24] 3820 	push	ar4
      0011AD E5 08            [12] 3821 	mov	a,_bp
      0011AF 24 FA            [12] 3822 	add	a,#0xfa
      0011B1 F8               [12] 3823 	mov	r0,a
      0011B2 E6               [12] 3824 	mov	a,@r0
      0011B3 C0 E0            [24] 3825 	push	acc
      0011B5 08               [12] 3826 	inc	r0
      0011B6 E6               [12] 3827 	mov	a,@r0
      0011B7 C0 E0            [24] 3828 	push	acc
      0011B9 08               [12] 3829 	inc	r0
      0011BA E6               [12] 3830 	mov	a,@r0
      0011BB C0 E0            [24] 3831 	push	acc
      0011BD 08               [12] 3832 	inc	r0
      0011BE E6               [12] 3833 	mov	a,@r0
      0011BF C0 E0            [24] 3834 	push	acc
      0011C1 E5 08            [12] 3835 	mov	a,_bp
      0011C3 24 EE            [12] 3836 	add	a,#0xee
      0011C5 F8               [12] 3837 	mov	r0,a
      0011C6 86 82            [24] 3838 	mov	dpl, @r0
      0011C8 08               [12] 3839 	inc	r0
      0011C9 86 83            [24] 3840 	mov	dph, @r0
      0011CB 08               [12] 3841 	inc	r0
      0011CC 86 F0            [24] 3842 	mov	b, @r0
      0011CE 08               [12] 3843 	inc	r0
      0011CF E6               [12] 3844 	mov	a, @r0
      0011D0 12 41 7C         [24] 3845 	lcall	___fslt
      0011D3 E5 81            [12] 3846 	mov	a,sp
      0011D5 24 FC            [12] 3847 	add	a,#0xfc
      0011D7 F5 81            [12] 3848 	mov	sp,a
      0011D9 D0 04            [24] 3849 	pop	ar4
      0011DB D0 05            [24] 3850 	pop	ar5
      0011DD D0 06            [24] 3851 	pop	ar6
      0011DF D0 07            [24] 3852 	pop	ar7
      0011E1 E5 82            [12] 3853 	mov	a, dpl
      0011E3 24 FF            [12] 3854 	add	a,#0xff
      0011E5 92 00            [24] 3855 	mov	b0,c
      0011E7 40 54            [24] 3856 	jc	00105$
                           00112C  3857 	C$fuzzy.h$1441$1_0$79 ==.
                                   3858 ;	../../fuzzy.h:1441: ) {
      0011E9 C0 07            [24] 3859 	push	ar7
      0011EB C0 06            [24] 3860 	push	ar6
      0011ED C0 05            [24] 3861 	push	ar5
      0011EF C0 04            [24] 3862 	push	ar4
      0011F1 E5 08            [12] 3863 	mov	a,_bp
      0011F3 24 EE            [12] 3864 	add	a,#0xee
      0011F5 F8               [12] 3865 	mov	r0,a
      0011F6 E6               [12] 3866 	mov	a,@r0
      0011F7 C0 E0            [24] 3867 	push	acc
      0011F9 08               [12] 3868 	inc	r0
      0011FA E6               [12] 3869 	mov	a,@r0
      0011FB C0 E0            [24] 3870 	push	acc
      0011FD 08               [12] 3871 	inc	r0
      0011FE E6               [12] 3872 	mov	a,@r0
      0011FF C0 E0            [24] 3873 	push	acc
      001201 08               [12] 3874 	inc	r0
      001202 E6               [12] 3875 	mov	a,@r0
      001203 C0 E0            [24] 3876 	push	acc
      001205 E5 08            [12] 3877 	mov	a,_bp
      001207 24 F6            [12] 3878 	add	a,#0xf6
      001209 F8               [12] 3879 	mov	r0,a
      00120A 86 82            [24] 3880 	mov	dpl, @r0
      00120C 08               [12] 3881 	inc	r0
      00120D 86 83            [24] 3882 	mov	dph, @r0
      00120F 08               [12] 3883 	inc	r0
      001210 86 F0            [24] 3884 	mov	b, @r0
      001212 08               [12] 3885 	inc	r0
      001213 E6               [12] 3886 	mov	a, @r0
      001214 12 41 7C         [24] 3887 	lcall	___fslt
      001217 E5 81            [12] 3888 	mov	a,sp
      001219 24 FC            [12] 3889 	add	a,#0xfc
      00121B F5 81            [12] 3890 	mov	sp,a
      00121D D0 04            [24] 3891 	pop	ar4
      00121F D0 05            [24] 3892 	pop	ar5
      001221 D0 06            [24] 3893 	pop	ar6
      001223 D0 07            [24] 3894 	pop	ar7
      001225 E5 82            [12] 3895 	mov	a, dpl
      001227 24 FF            [12] 3896 	add	a,#0xff
      001229 92 00            [24] 3897 	mov	b0,c
      00122B 40 10            [24] 3898 	jc	00105$
                           001170  3899 	C$fuzzy.h$1442$2_0$81 ==.
                                   3900 ;	../../fuzzy.h:1442: result = LEVEL_HI;
      00122D A8 08            [24] 3901 	mov	r0,_bp
      00122F 08               [12] 3902 	inc	r0
      001230 E4               [12] 3903 	clr	a
      001231 F6               [12] 3904 	mov	@r0,a
      001232 08               [12] 3905 	inc	r0
      001233 F6               [12] 3906 	mov	@r0,a
      001234 08               [12] 3907 	inc	r0
      001235 76 80            [12] 3908 	mov	@r0,#0x80
      001237 08               [12] 3909 	inc	r0
      001238 76 3F            [12] 3910 	mov	@r0,#0x3f
      00123A 02 13 A4         [24] 3911 	ljmp	00110$
      00123D                       3912 00105$:
                           001180  3913 	C$fuzzy.h$1444$1_0$79 ==.
                                   3914 ;	../../fuzzy.h:1444: else if (value < b) {
      00123D C0 07            [24] 3915 	push	ar7
      00123F C0 06            [24] 3916 	push	ar6
      001241 C0 05            [24] 3917 	push	ar5
      001243 C0 04            [24] 3918 	push	ar4
      001245 E5 08            [12] 3919 	mov	a,_bp
      001247 24 FA            [12] 3920 	add	a,#0xfa
      001249 F8               [12] 3921 	mov	r0,a
      00124A E6               [12] 3922 	mov	a,@r0
      00124B C0 E0            [24] 3923 	push	acc
      00124D 08               [12] 3924 	inc	r0
      00124E E6               [12] 3925 	mov	a,@r0
      00124F C0 E0            [24] 3926 	push	acc
      001251 08               [12] 3927 	inc	r0
      001252 E6               [12] 3928 	mov	a,@r0
      001253 C0 E0            [24] 3929 	push	acc
      001255 08               [12] 3930 	inc	r0
      001256 E6               [12] 3931 	mov	a,@r0
      001257 C0 E0            [24] 3932 	push	acc
      001259 E5 08            [12] 3933 	mov	a,_bp
      00125B 24 EE            [12] 3934 	add	a,#0xee
      00125D F8               [12] 3935 	mov	r0,a
      00125E 86 82            [24] 3936 	mov	dpl, @r0
      001260 08               [12] 3937 	inc	r0
      001261 86 83            [24] 3938 	mov	dph, @r0
      001263 08               [12] 3939 	inc	r0
      001264 86 F0            [24] 3940 	mov	b, @r0
      001266 08               [12] 3941 	inc	r0
      001267 E6               [12] 3942 	mov	a, @r0
      001268 12 41 7C         [24] 3943 	lcall	___fslt
      00126B AB 82            [24] 3944 	mov	r3, dpl
      00126D E5 81            [12] 3945 	mov	a,sp
      00126F 24 FC            [12] 3946 	add	a,#0xfc
      001271 F5 81            [12] 3947 	mov	sp,a
      001273 D0 04            [24] 3948 	pop	ar4
      001275 D0 05            [24] 3949 	pop	ar5
      001277 D0 06            [24] 3950 	pop	ar6
      001279 D0 07            [24] 3951 	pop	ar7
      00127B EB               [12] 3952 	mov	a,r3
      00127C 70 03            [24] 3953 	jnz	00166$
      00127E 02 13 08         [24] 3954 	ljmp	00102$
      001281                       3955 00166$:
                           0011C4  3956 	C$fuzzy.h$1446$1_0$79 ==.
                                   3957 ;	../../fuzzy.h:1446: (value - a) /
      001281 C0 07            [24] 3958 	push	ar7
      001283 C0 06            [24] 3959 	push	ar6
      001285 C0 05            [24] 3960 	push	ar5
      001287 C0 04            [24] 3961 	push	ar4
      001289 C0 07            [24] 3962 	push	ar7
      00128B C0 06            [24] 3963 	push	ar6
      00128D C0 05            [24] 3964 	push	ar5
      00128F C0 04            [24] 3965 	push	ar4
                           0011D4  3966 	C$fuzzy.h$1447$1_0$79 ==.
                                   3967 ;	../../fuzzy.h:1447: (b - a);
      001291 E5 08            [12] 3968 	mov	a,_bp
      001293 24 EE            [12] 3969 	add	a,#0xee
      001295 F8               [12] 3970 	mov	r0,a
      001296 86 82            [24] 3971 	mov	dpl, @r0
      001298 08               [12] 3972 	inc	r0
      001299 86 83            [24] 3973 	mov	dph, @r0
      00129B 08               [12] 3974 	inc	r0
      00129C 86 F0            [24] 3975 	mov	b, @r0
      00129E 08               [12] 3976 	inc	r0
      00129F E6               [12] 3977 	mov	a, @r0
      0012A0 12 40 41         [24] 3978 	lcall	___fssub
      0012A3 C8               [12] 3979 	xch	a,r0
      0012A4 E5 08            [12] 3980 	mov	a,_bp
      0012A6 24 05            [12] 3981 	add	a,#0x05
      0012A8 C8               [12] 3982 	xch	a,r0
      0012A9 A6 82            [24] 3983 	mov	@r0, dpl
      0012AB 08               [12] 3984 	inc	r0
      0012AC A6 83            [24] 3985 	mov	@r0, dph
      0012AE 08               [12] 3986 	inc	r0
      0012AF A6 F0            [24] 3987 	mov	@r0, b
      0012B1 08               [12] 3988 	inc	r0
      0012B2 F6               [12] 3989 	mov	@r0,a
      0012B3 E5 81            [12] 3990 	mov	a,sp
      0012B5 24 FC            [12] 3991 	add	a,#0xfc
      0012B7 F5 81            [12] 3992 	mov	sp,a
      0012B9 E5 08            [12] 3993 	mov	a,_bp
      0012BB 24 FA            [12] 3994 	add	a,#0xfa
      0012BD F8               [12] 3995 	mov	r0,a
      0012BE 86 82            [24] 3996 	mov	dpl, @r0
      0012C0 08               [12] 3997 	inc	r0
      0012C1 86 83            [24] 3998 	mov	dph, @r0
      0012C3 08               [12] 3999 	inc	r0
      0012C4 86 F0            [24] 4000 	mov	b, @r0
      0012C6 08               [12] 4001 	inc	r0
      0012C7 E6               [12] 4002 	mov	a, @r0
      0012C8 12 40 41         [24] 4003 	lcall	___fssub
      0012CB AC 82            [24] 4004 	mov	r4, dpl
      0012CD AD 83            [24] 4005 	mov	r5, dph
      0012CF AE F0            [24] 4006 	mov	r6, b
      0012D1 FF               [12] 4007 	mov	r7, a
      0012D2 E5 81            [12] 4008 	mov	a,sp
      0012D4 24 FC            [12] 4009 	add	a,#0xfc
      0012D6 F5 81            [12] 4010 	mov	sp,a
      0012D8 C0 04            [24] 4011 	push	ar4
      0012DA C0 05            [24] 4012 	push	ar5
      0012DC C0 06            [24] 4013 	push	ar6
      0012DE C0 07            [24] 4014 	push	ar7
      0012E0 E5 08            [12] 4015 	mov	a,_bp
      0012E2 24 05            [12] 4016 	add	a,#0x05
      0012E4 F8               [12] 4017 	mov	r0,a
      0012E5 86 82            [24] 4018 	mov	dpl, @r0
      0012E7 08               [12] 4019 	inc	r0
      0012E8 86 83            [24] 4020 	mov	dph, @r0
      0012EA 08               [12] 4021 	inc	r0
      0012EB 86 F0            [24] 4022 	mov	b, @r0
      0012ED 08               [12] 4023 	inc	r0
      0012EE E6               [12] 4024 	mov	a, @r0
      0012EF 12 42 E5         [24] 4025 	lcall	___fsdiv
      0012F2 A8 08            [24] 4026 	mov	r0,_bp
      0012F4 08               [12] 4027 	inc	r0
      0012F5 A6 82            [24] 4028 	mov	@r0, dpl
      0012F7 08               [12] 4029 	inc	r0
      0012F8 A6 83            [24] 4030 	mov	@r0, dph
      0012FA 08               [12] 4031 	inc	r0
      0012FB A6 F0            [24] 4032 	mov	@r0, b
      0012FD 08               [12] 4033 	inc	r0
      0012FE F6               [12] 4034 	mov	@r0,a
      0012FF E5 81            [12] 4035 	mov	a,sp
      001301 24 FC            [12] 4036 	add	a,#0xfc
      001303 F5 81            [12] 4037 	mov	sp,a
      001305 02 13 A4         [24] 4038 	ljmp	00110$
      001308                       4039 00102$:
                           00124B  4040 	C$fuzzy.h$1451$1_0$79 ==.
                                   4041 ;	../../fuzzy.h:1451: (d - value) /
      001308 E5 08            [12] 4042 	mov	a,_bp
      00130A 24 EE            [12] 4043 	add	a,#0xee
      00130C F8               [12] 4044 	mov	r0,a
      00130D E6               [12] 4045 	mov	a,@r0
      00130E C0 E0            [24] 4046 	push	acc
      001310 08               [12] 4047 	inc	r0
      001311 E6               [12] 4048 	mov	a,@r0
      001312 C0 E0            [24] 4049 	push	acc
      001314 08               [12] 4050 	inc	r0
      001315 E6               [12] 4051 	mov	a,@r0
      001316 C0 E0            [24] 4052 	push	acc
      001318 08               [12] 4053 	inc	r0
      001319 E6               [12] 4054 	mov	a,@r0
      00131A C0 E0            [24] 4055 	push	acc
                           00125F  4056 	C$fuzzy.h$1452$1_0$79 ==.
                                   4057 ;	../../fuzzy.h:1452: (d - c);
      00131C E5 08            [12] 4058 	mov	a,_bp
      00131E 24 F2            [12] 4059 	add	a,#0xf2
      001320 F8               [12] 4060 	mov	r0,a
      001321 86 82            [24] 4061 	mov	dpl, @r0
      001323 08               [12] 4062 	inc	r0
      001324 86 83            [24] 4063 	mov	dph, @r0
      001326 08               [12] 4064 	inc	r0
      001327 86 F0            [24] 4065 	mov	b, @r0
      001329 08               [12] 4066 	inc	r0
      00132A E6               [12] 4067 	mov	a, @r0
      00132B 12 40 41         [24] 4068 	lcall	___fssub
      00132E C8               [12] 4069 	xch	a,r0
      00132F E5 08            [12] 4070 	mov	a,_bp
      001331 24 05            [12] 4071 	add	a,#0x05
      001333 C8               [12] 4072 	xch	a,r0
      001334 A6 82            [24] 4073 	mov	@r0, dpl
      001336 08               [12] 4074 	inc	r0
      001337 A6 83            [24] 4075 	mov	@r0, dph
      001339 08               [12] 4076 	inc	r0
      00133A A6 F0            [24] 4077 	mov	@r0, b
      00133C 08               [12] 4078 	inc	r0
      00133D F6               [12] 4079 	mov	@r0,a
      00133E E5 81            [12] 4080 	mov	a,sp
      001340 24 FC            [12] 4081 	add	a,#0xfc
      001342 F5 81            [12] 4082 	mov	sp,a
      001344 E5 08            [12] 4083 	mov	a,_bp
      001346 24 F6            [12] 4084 	add	a,#0xf6
      001348 F8               [12] 4085 	mov	r0,a
      001349 E6               [12] 4086 	mov	a,@r0
      00134A C0 E0            [24] 4087 	push	acc
      00134C 08               [12] 4088 	inc	r0
      00134D E6               [12] 4089 	mov	a,@r0
      00134E C0 E0            [24] 4090 	push	acc
      001350 08               [12] 4091 	inc	r0
      001351 E6               [12] 4092 	mov	a,@r0
      001352 C0 E0            [24] 4093 	push	acc
      001354 08               [12] 4094 	inc	r0
      001355 E6               [12] 4095 	mov	a,@r0
      001356 C0 E0            [24] 4096 	push	acc
      001358 E5 08            [12] 4097 	mov	a,_bp
      00135A 24 F2            [12] 4098 	add	a,#0xf2
      00135C F8               [12] 4099 	mov	r0,a
      00135D 86 82            [24] 4100 	mov	dpl, @r0
      00135F 08               [12] 4101 	inc	r0
      001360 86 83            [24] 4102 	mov	dph, @r0
      001362 08               [12] 4103 	inc	r0
      001363 86 F0            [24] 4104 	mov	b, @r0
      001365 08               [12] 4105 	inc	r0
      001366 E6               [12] 4106 	mov	a, @r0
      001367 12 40 41         [24] 4107 	lcall	___fssub
      00136A AA 82            [24] 4108 	mov	r2, dpl
      00136C AB 83            [24] 4109 	mov	r3, dph
      00136E AE F0            [24] 4110 	mov	r6, b
      001370 FF               [12] 4111 	mov	r7, a
      001371 E5 81            [12] 4112 	mov	a,sp
      001373 24 FC            [12] 4113 	add	a,#0xfc
      001375 F5 81            [12] 4114 	mov	sp,a
      001377 C0 02            [24] 4115 	push	ar2
      001379 C0 03            [24] 4116 	push	ar3
      00137B C0 06            [24] 4117 	push	ar6
      00137D C0 07            [24] 4118 	push	ar7
      00137F E5 08            [12] 4119 	mov	a,_bp
      001381 24 05            [12] 4120 	add	a,#0x05
      001383 F8               [12] 4121 	mov	r0,a
      001384 86 82            [24] 4122 	mov	dpl, @r0
      001386 08               [12] 4123 	inc	r0
      001387 86 83            [24] 4124 	mov	dph, @r0
      001389 08               [12] 4125 	inc	r0
      00138A 86 F0            [24] 4126 	mov	b, @r0
      00138C 08               [12] 4127 	inc	r0
      00138D E6               [12] 4128 	mov	a, @r0
      00138E 12 42 E5         [24] 4129 	lcall	___fsdiv
      001391 A8 08            [24] 4130 	mov	r0,_bp
      001393 08               [12] 4131 	inc	r0
      001394 A6 82            [24] 4132 	mov	@r0, dpl
      001396 08               [12] 4133 	inc	r0
      001397 A6 83            [24] 4134 	mov	@r0, dph
      001399 08               [12] 4135 	inc	r0
      00139A A6 F0            [24] 4136 	mov	@r0, b
      00139C 08               [12] 4137 	inc	r0
      00139D F6               [12] 4138 	mov	@r0,a
      00139E E5 81            [12] 4139 	mov	a,sp
      0013A0 24 FC            [12] 4140 	add	a,#0xfc
      0013A2 F5 81            [12] 4141 	mov	sp,a
      0013A4                       4142 00110$:
                           0012E7  4143 	C$fuzzy.h$1456$1_0$79 ==.
                                   4144 ;	../../fuzzy.h:1456: result,
      0013A4 E5 08            [12] 4145 	mov	a,_bp
      0013A6 24 ED            [12] 4146 	add	a,#0xed
      0013A8 F8               [12] 4147 	mov	r0,a
      0013A9 E6               [12] 4148 	mov	a,@r0
      0013AA C0 E0            [24] 4149 	push	acc
      0013AC A8 08            [24] 4150 	mov	r0,_bp
      0013AE 08               [12] 4151 	inc	r0
      0013AF 86 82            [24] 4152 	mov	dpl, @r0
      0013B1 08               [12] 4153 	inc	r0
      0013B2 86 83            [24] 4154 	mov	dph, @r0
      0013B4 08               [12] 4155 	inc	r0
      0013B5 86 F0            [24] 4156 	mov	b, @r0
      0013B7 08               [12] 4157 	inc	r0
      0013B8 E6               [12] 4158 	mov	a, @r0
      0013B9 12 01 9F         [24] 4159 	lcall	_fuzzy_apply_hedge
      0013BC AC 82            [24] 4160 	mov	r4, dpl
      0013BE AD 83            [24] 4161 	mov	r5, dph
      0013C0 AE F0            [24] 4162 	mov	r6, b
      0013C2 FF               [12] 4163 	mov	r7, a
      0013C3 15 81            [12] 4164 	dec	sp
      0013C5 8C 82            [24] 4165 	mov	dpl, r4
      0013C7 8D 83            [24] 4166 	mov	dph, r5
      0013C9 8E F0            [24] 4167 	mov	b, r6
      0013CB EF               [12] 4168 	mov	a, r7
                           00130F  4169 	C$fuzzy.h$1459$1_0$79 ==.
                                   4170 ;	../../fuzzy.h:1459: }
      0013CC 85 08 81         [24] 4171 	mov	sp,_bp
      0013CF D0 08            [24] 4172 	pop	_bp
                           001314  4173 	C$fuzzy.h$1459$1_0$79 ==.
                           001314  4174 	XG$fuzzy_trapezoid$0$0 ==.
      0013D1 22               [24] 4175 	ret
                                   4176 ;------------------------------------------------------------
                                   4177 ;Allocation info for local variables in function 'fuzzy_function_array'
                                   4178 ;------------------------------------------------------------
                                   4179 ;value         Allocated to stack - _bp -6 +4 
                                   4180 ;hedge         Allocated to stack - _bp -7 +1 
                                   4181 ;parameter_count Allocated to stack - _bp -9 +2 
                                   4182 ;parameters    Allocated to stack - _bp -12 +3 
                                   4183 ;shape         Allocated to registers r7 
                                   4184 ;sloc0         Allocated to stack - _bp +2 +1 
                                   4185 ;sloc1         Allocated to stack - _bp +1 +4 
                                   4186 ;sloc2         Allocated to stack - _bp +5 +4 
                                   4187 ;sloc3         Allocated to stack - _bp +9 +4 
                                   4188 ;------------------------------------------------------------
                           001315  4189 	G$fuzzy_function_array$0$0 ==.
                           001315  4190 	C$fuzzy.h$1916$1_0$85 ==.
                                   4191 ;	../../fuzzy.h:1916: float fuzzy_function_array(
                                   4192 ;	-----------------------------------------
                                   4193 ;	 function fuzzy_function_array
                                   4194 ;	-----------------------------------------
      0013D2                       4195 _fuzzy_function_array:
      0013D2 C0 08            [24] 4196 	push	_bp
      0013D4 E5 81            [12] 4197 	mov	a,sp
      0013D6 F5 08            [12] 4198 	mov	_bp,a
      0013D8 24 0C            [12] 4199 	add	a,#0x0c
      0013DA F5 81            [12] 4200 	mov	sp,a
      0013DC AF 82            [24] 4201 	mov	r7, dpl
                           001321  4202 	C$fuzzy.h$1924$1_0$85 ==.
                                   4203 ;	../../fuzzy.h:1924: if (parameters == NULL) {
      0013DE E5 08            [12] 4204 	mov	a,_bp
      0013E0 24 F4            [12] 4205 	add	a,#0xf4
      0013E2 F8               [12] 4206 	mov	r0,a
      0013E3 E6               [12] 4207 	mov	a,@r0
      0013E4 08               [12] 4208 	inc	r0
      0013E5 46               [12] 4209 	orl	a,@r0
      0013E6 70 09            [24] 4210 	jnz	00102$
                           00132B  4211 	C$fuzzy.h$1925$2_0$86 ==.
                                   4212 ;	../../fuzzy.h:1925: return LEVEL_LO;
      0013E8 90 00 00         [24] 4213 	mov	dptr,#0x0000
      0013EB E4               [12] 4214 	clr	a
      0013EC F5 F0            [12] 4215 	mov	b,a
      0013EE 02 17 6D         [24] 4216 	ljmp	00123$
      0013F1                       4217 00102$:
                           001334  4218 	C$fuzzy.h$1928$1_0$85 ==.
                                   4219 ;	../../fuzzy.h:1928: switch (shape) {
      0013F1 EF               [12] 4220 	mov	a,r7
      0013F2 24 F4            [12] 4221 	add	a,#0xff - 0x0b
      0013F4 50 03            [24] 4222 	jnc	00156$
      0013F6 02 17 67         [24] 4223 	ljmp	00121$
      0013F9                       4224 00156$:
      0013F9 EF               [12] 4225 	mov	a,r7
      0013FA 24 0A            [12] 4226 	add	a,#(00157$-3-.)
      0013FC 83               [24] 4227 	movc	a,@a+pc
      0013FD F5 82            [12] 4228 	mov	dpl,a
      0013FF EF               [12] 4229 	mov	a,r7
      001400 24 10            [12] 4230 	add	a,#(00158$-3-.)
      001402 83               [24] 4231 	movc	a,@a+pc
      001403 F5 83            [12] 4232 	mov	dph,a
      001405 E4               [12] 4233 	clr	a
      001406 73               [24] 4234 	jmp	@a+dptr
      001407                       4235 00157$:
      001407 1F                    4236 	.db	00103$
      001408 1B                    4237 	.db	00106$
      001409 1B                    4238 	.db	00109$
      00140A 5F                    4239 	.db	00120$
      00140B 5F                    4240 	.db	00120$
      00140C 5F                    4241 	.db	00120$
      00140D 5F                    4242 	.db	00120$
      00140E 5F                    4243 	.db	00120$
      00140F 5F                    4244 	.db	00120$
      001410 5F                    4245 	.db	00120$
      001411 5F                    4246 	.db	00120$
      001412 5F                    4247 	.db	00120$
      001413                       4248 00158$:
      001413 14                    4249 	.db	00103$>>8
      001414 15                    4250 	.db	00106$>>8
      001415 16                    4251 	.db	00109$>>8
      001416 17                    4252 	.db	00120$>>8
      001417 17                    4253 	.db	00120$>>8
      001418 17                    4254 	.db	00120$>>8
      001419 17                    4255 	.db	00120$>>8
      00141A 17                    4256 	.db	00120$>>8
      00141B 17                    4257 	.db	00120$>>8
      00141C 17                    4258 	.db	00120$>>8
      00141D 17                    4259 	.db	00120$>>8
      00141E 17                    4260 	.db	00120$>>8
                           001362  4261 	C$fuzzy.h$1929$2_0$87 ==.
                                   4262 ;	../../fuzzy.h:1929: case FUZZY_SHAPE_RAMP:
      00141F                       4263 00103$:
                           001362  4264 	C$fuzzy.h$1930$2_0$87 ==.
                                   4265 ;	../../fuzzy.h:1930: if (parameter_count != 3u) {
      00141F E5 08            [12] 4266 	mov	a,_bp
      001421 24 F7            [12] 4267 	add	a,#0xf7
      001423 F8               [12] 4268 	mov	r0,a
      001424 B6 03 06         [24] 4269 	cjne	@r0,#0x03,00159$
      001427 08               [12] 4270 	inc	r0
      001428 B6 00 02         [24] 4271 	cjne	@r0,#0x00,00159$
      00142B 80 09            [24] 4272 	sjmp	00105$
      00142D                       4273 00159$:
                           001370  4274 	C$fuzzy.h$1931$3_0$88 ==.
                                   4275 ;	../../fuzzy.h:1931: return LEVEL_LO;
      00142D 90 00 00         [24] 4276 	mov	dptr,#0x0000
      001430 E4               [12] 4277 	clr	a
      001431 F5 F0            [12] 4278 	mov	b,a
      001433 02 17 6D         [24] 4279 	ljmp	00123$
      001436                       4280 00105$:
                           001379  4281 	C$fuzzy.h$1938$2_0$87 ==.
                                   4282 ;	../../fuzzy.h:1938: parameters[2] != 0.0f,
      001436 E5 08            [12] 4283 	mov	a,_bp
      001438 24 F4            [12] 4284 	add	a,#0xf4
      00143A F8               [12] 4285 	mov	r0,a
      00143B 74 08            [12] 4286 	mov	a,#0x08
      00143D 26               [12] 4287 	add	a, @r0
      00143E FD               [12] 4288 	mov	r5,a
      00143F E4               [12] 4289 	clr	a
      001440 08               [12] 4290 	inc	r0
      001441 36               [12] 4291 	addc	a, @r0
      001442 FE               [12] 4292 	mov	r6,a
      001443 08               [12] 4293 	inc	r0
      001444 86 07            [24] 4294 	mov	ar7,@r0
      001446 8D 82            [24] 4295 	mov	dpl,r5
      001448 8E 83            [24] 4296 	mov	dph,r6
      00144A 8F F0            [24] 4297 	mov	b,r7
      00144C 12 43 A8         [24] 4298 	lcall	__gptrget
      00144F FD               [12] 4299 	mov	r5,a
      001450 A3               [24] 4300 	inc	dptr
      001451 12 43 A8         [24] 4301 	lcall	__gptrget
      001454 FE               [12] 4302 	mov	r6,a
      001455 A3               [24] 4303 	inc	dptr
      001456 12 43 A8         [24] 4304 	lcall	__gptrget
      001459 FF               [12] 4305 	mov	r7,a
      00145A A3               [24] 4306 	inc	dptr
      00145B 12 43 A8         [24] 4307 	lcall	__gptrget
      00145E FC               [12] 4308 	mov	r4,a
      00145F 8D F0            [24] 4309 	mov	b,r5
      001461 EE               [12] 4310 	mov	a,r6
      001462 42 F0            [12] 4311 	orl	b,a
      001464 EF               [12] 4312 	mov	a,r7
      001465 42 F0            [12] 4313 	orl	b,a
      001467 EC               [12] 4314 	mov	a,r4
      001468 54 7F            [12] 4315 	anl	a,#0x7F
      00146A 45 F0            [12] 4316 	orl	a,b
      00146C B4 01 00         [24] 4317 	cjne	a,#0x01,00160$
      00146F                       4318 00160$:
      00146F B3               [12] 4319 	cpl	c
      001470 92 00            [24] 4320 	mov	b0,c
      001472 E4               [12] 4321 	clr	a
      001473 33               [12] 4322 	rlc	a
      001474 FB               [12] 4323 	mov	r3,a
                           0013B8  4324 	C$fuzzy.h$1936$2_0$87 ==.
                                   4325 ;	../../fuzzy.h:1936: parameters[1],
      001475 E5 08            [12] 4326 	mov	a,_bp
      001477 24 F4            [12] 4327 	add	a,#0xf4
      001479 F8               [12] 4328 	mov	r0,a
      00147A 74 04            [12] 4329 	mov	a,#0x04
      00147C 26               [12] 4330 	add	a, @r0
      00147D FC               [12] 4331 	mov	r4,a
      00147E E4               [12] 4332 	clr	a
      00147F 08               [12] 4333 	inc	r0
      001480 36               [12] 4334 	addc	a, @r0
      001481 FD               [12] 4335 	mov	r5,a
      001482 08               [12] 4336 	inc	r0
      001483 86 06            [24] 4337 	mov	ar6,@r0
      001485 8C 82            [24] 4338 	mov	dpl,r4
      001487 8D 83            [24] 4339 	mov	dph,r5
      001489 8E F0            [24] 4340 	mov	b,r6
      00148B A8 08            [24] 4341 	mov	r0,_bp
      00148D 08               [12] 4342 	inc	r0
      00148E 12 43 A8         [24] 4343 	lcall	__gptrget
      001491 F6               [12] 4344 	mov	@r0,a
      001492 A3               [24] 4345 	inc	dptr
      001493 12 43 A8         [24] 4346 	lcall	__gptrget
      001496 08               [12] 4347 	inc	r0
      001497 F6               [12] 4348 	mov	@r0,a
      001498 A3               [24] 4349 	inc	dptr
      001499 12 43 A8         [24] 4350 	lcall	__gptrget
      00149C 08               [12] 4351 	inc	r0
      00149D F6               [12] 4352 	mov	@r0,a
      00149E A3               [24] 4353 	inc	dptr
      00149F 12 43 A8         [24] 4354 	lcall	__gptrget
      0014A2 08               [12] 4355 	inc	r0
      0014A3 F6               [12] 4356 	mov	@r0,a
                           0013E7  4357 	C$fuzzy.h$1935$2_0$87 ==.
                                   4358 ;	../../fuzzy.h:1935: parameters[0],
      0014A4 E5 08            [12] 4359 	mov	a,_bp
      0014A6 24 F4            [12] 4360 	add	a,#0xf4
      0014A8 F8               [12] 4361 	mov	r0,a
      0014A9 86 02            [24] 4362 	mov	ar2,@r0
      0014AB 08               [12] 4363 	inc	r0
      0014AC 86 06            [24] 4364 	mov	ar6,@r0
      0014AE 08               [12] 4365 	inc	r0
      0014AF 86 07            [24] 4366 	mov	ar7,@r0
      0014B1 8A 82            [24] 4367 	mov	dpl,r2
      0014B3 8E 83            [24] 4368 	mov	dph,r6
      0014B5 8F F0            [24] 4369 	mov	b,r7
      0014B7 12 43 A8         [24] 4370 	lcall	__gptrget
      0014BA FA               [12] 4371 	mov	r2,a
      0014BB A3               [24] 4372 	inc	dptr
      0014BC 12 43 A8         [24] 4373 	lcall	__gptrget
      0014BF FE               [12] 4374 	mov	r6,a
      0014C0 A3               [24] 4375 	inc	dptr
      0014C1 12 43 A8         [24] 4376 	lcall	__gptrget
      0014C4 FF               [12] 4377 	mov	r7,a
      0014C5 A3               [24] 4378 	inc	dptr
      0014C6 12 43 A8         [24] 4379 	lcall	__gptrget
      0014C9 FD               [12] 4380 	mov	r5,a
      0014CA E5 08            [12] 4381 	mov	a,_bp
      0014CC 24 F9            [12] 4382 	add	a,#0xf9
      0014CE F8               [12] 4383 	mov	r0,a
      0014CF E6               [12] 4384 	mov	a,@r0
      0014D0 C0 E0            [24] 4385 	push	acc
      0014D2 C0 03            [24] 4386 	push	ar3
      0014D4 E5 08            [12] 4387 	mov	a,_bp
      0014D6 24 FA            [12] 4388 	add	a,#0xfa
      0014D8 F8               [12] 4389 	mov	r0,a
      0014D9 E6               [12] 4390 	mov	a,@r0
      0014DA C0 E0            [24] 4391 	push	acc
      0014DC 08               [12] 4392 	inc	r0
      0014DD E6               [12] 4393 	mov	a,@r0
      0014DE C0 E0            [24] 4394 	push	acc
      0014E0 08               [12] 4395 	inc	r0
      0014E1 E6               [12] 4396 	mov	a,@r0
      0014E2 C0 E0            [24] 4397 	push	acc
      0014E4 08               [12] 4398 	inc	r0
      0014E5 E6               [12] 4399 	mov	a,@r0
      0014E6 C0 E0            [24] 4400 	push	acc
      0014E8 A8 08            [24] 4401 	mov	r0,_bp
      0014EA 08               [12] 4402 	inc	r0
      0014EB E6               [12] 4403 	mov	a,@r0
      0014EC C0 E0            [24] 4404 	push	acc
      0014EE 08               [12] 4405 	inc	r0
      0014EF E6               [12] 4406 	mov	a,@r0
      0014F0 C0 E0            [24] 4407 	push	acc
      0014F2 08               [12] 4408 	inc	r0
      0014F3 E6               [12] 4409 	mov	a,@r0
      0014F4 C0 E0            [24] 4410 	push	acc
      0014F6 08               [12] 4411 	inc	r0
      0014F7 E6               [12] 4412 	mov	a,@r0
      0014F8 C0 E0            [24] 4413 	push	acc
      0014FA 8A 82            [24] 4414 	mov	dpl, r2
      0014FC 8E 83            [24] 4415 	mov	dph, r6
      0014FE 8F F0            [24] 4416 	mov	b, r7
      001500 ED               [12] 4417 	mov	a, r5
      001501 12 0A F2         [24] 4418 	lcall	_fuzzy_ramp
      001504 AC 82            [24] 4419 	mov	r4, dpl
      001506 AD 83            [24] 4420 	mov	r5, dph
      001508 AE F0            [24] 4421 	mov	r6, b
      00150A FF               [12] 4422 	mov	r7, a
      00150B E5 81            [12] 4423 	mov	a,sp
      00150D 24 F6            [12] 4424 	add	a,#0xf6
      00150F F5 81            [12] 4425 	mov	sp,a
      001511 8C 82            [24] 4426 	mov	dpl, r4
      001513 8D 83            [24] 4427 	mov	dph, r5
      001515 8E F0            [24] 4428 	mov	b, r6
      001517 EF               [12] 4429 	mov	a, r7
      001518 02 17 6D         [24] 4430 	ljmp	00123$
                           00145E  4431 	C$fuzzy.h$1942$2_0$87 ==.
                                   4432 ;	../../fuzzy.h:1942: case FUZZY_SHAPE_TRIANGLE:
      00151B                       4433 00106$:
                           00145E  4434 	C$fuzzy.h$1943$2_0$87 ==.
                                   4435 ;	../../fuzzy.h:1943: if (parameter_count != 3u) {
      00151B E5 08            [12] 4436 	mov	a,_bp
      00151D 24 F7            [12] 4437 	add	a,#0xf7
      00151F F8               [12] 4438 	mov	r0,a
      001520 B6 03 06         [24] 4439 	cjne	@r0,#0x03,00161$
      001523 08               [12] 4440 	inc	r0
      001524 B6 00 02         [24] 4441 	cjne	@r0,#0x00,00161$
      001527 80 09            [24] 4442 	sjmp	00108$
      001529                       4443 00161$:
                           00146C  4444 	C$fuzzy.h$1944$3_0$89 ==.
                                   4445 ;	../../fuzzy.h:1944: return LEVEL_LO;
      001529 90 00 00         [24] 4446 	mov	dptr,#0x0000
      00152C E4               [12] 4447 	clr	a
      00152D F5 F0            [12] 4448 	mov	b,a
      00152F 02 17 6D         [24] 4449 	ljmp	00123$
      001532                       4450 00108$:
                           001475  4451 	C$fuzzy.h$1950$2_0$87 ==.
                                   4452 ;	../../fuzzy.h:1950: parameters[2],
      001532 E5 08            [12] 4453 	mov	a,_bp
      001534 24 F4            [12] 4454 	add	a,#0xf4
      001536 F8               [12] 4455 	mov	r0,a
      001537 74 08            [12] 4456 	mov	a,#0x08
      001539 26               [12] 4457 	add	a, @r0
      00153A FD               [12] 4458 	mov	r5,a
      00153B E4               [12] 4459 	clr	a
      00153C 08               [12] 4460 	inc	r0
      00153D 36               [12] 4461 	addc	a, @r0
      00153E FE               [12] 4462 	mov	r6,a
      00153F 08               [12] 4463 	inc	r0
      001540 86 07            [24] 4464 	mov	ar7,@r0
      001542 8D 82            [24] 4465 	mov	dpl,r5
      001544 8E 83            [24] 4466 	mov	dph,r6
      001546 8F F0            [24] 4467 	mov	b,r7
      001548 A8 08            [24] 4468 	mov	r0,_bp
      00154A 08               [12] 4469 	inc	r0
      00154B 12 43 A8         [24] 4470 	lcall	__gptrget
      00154E F6               [12] 4471 	mov	@r0,a
      00154F A3               [24] 4472 	inc	dptr
      001550 12 43 A8         [24] 4473 	lcall	__gptrget
      001553 08               [12] 4474 	inc	r0
      001554 F6               [12] 4475 	mov	@r0,a
      001555 A3               [24] 4476 	inc	dptr
      001556 12 43 A8         [24] 4477 	lcall	__gptrget
      001559 08               [12] 4478 	inc	r0
      00155A F6               [12] 4479 	mov	@r0,a
      00155B A3               [24] 4480 	inc	dptr
      00155C 12 43 A8         [24] 4481 	lcall	__gptrget
      00155F 08               [12] 4482 	inc	r0
      001560 F6               [12] 4483 	mov	@r0,a
                           0014A4  4484 	C$fuzzy.h$1949$2_0$87 ==.
                                   4485 ;	../../fuzzy.h:1949: parameters[1],
      001561 E5 08            [12] 4486 	mov	a,_bp
      001563 24 F4            [12] 4487 	add	a,#0xf4
      001565 F8               [12] 4488 	mov	r0,a
      001566 74 04            [12] 4489 	mov	a,#0x04
      001568 26               [12] 4490 	add	a, @r0
      001569 FA               [12] 4491 	mov	r2,a
      00156A E4               [12] 4492 	clr	a
      00156B 08               [12] 4493 	inc	r0
      00156C 36               [12] 4494 	addc	a, @r0
      00156D FB               [12] 4495 	mov	r3,a
      00156E 08               [12] 4496 	inc	r0
      00156F 86 07            [24] 4497 	mov	ar7,@r0
      001571 8A 82            [24] 4498 	mov	dpl,r2
      001573 8B 83            [24] 4499 	mov	dph,r3
      001575 8F F0            [24] 4500 	mov	b,r7
      001577 E5 08            [12] 4501 	mov	a,_bp
      001579 24 05            [12] 4502 	add	a,#0x05
      00157B F8               [12] 4503 	mov	r0,a
      00157C 12 43 A8         [24] 4504 	lcall	__gptrget
      00157F F6               [12] 4505 	mov	@r0,a
      001580 A3               [24] 4506 	inc	dptr
      001581 12 43 A8         [24] 4507 	lcall	__gptrget
      001584 08               [12] 4508 	inc	r0
      001585 F6               [12] 4509 	mov	@r0,a
      001586 A3               [24] 4510 	inc	dptr
      001587 12 43 A8         [24] 4511 	lcall	__gptrget
      00158A 08               [12] 4512 	inc	r0
      00158B F6               [12] 4513 	mov	@r0,a
      00158C A3               [24] 4514 	inc	dptr
      00158D 12 43 A8         [24] 4515 	lcall	__gptrget
      001590 08               [12] 4516 	inc	r0
      001591 F6               [12] 4517 	mov	@r0,a
                           0014D5  4518 	C$fuzzy.h$1948$2_0$87 ==.
                                   4519 ;	../../fuzzy.h:1948: parameters[0],
      001592 E5 08            [12] 4520 	mov	a,_bp
      001594 24 F4            [12] 4521 	add	a,#0xf4
      001596 F8               [12] 4522 	mov	r0,a
      001597 86 04            [24] 4523 	mov	ar4,@r0
      001599 08               [12] 4524 	inc	r0
      00159A 86 05            [24] 4525 	mov	ar5,@r0
      00159C 08               [12] 4526 	inc	r0
      00159D 86 07            [24] 4527 	mov	ar7,@r0
      00159F 8C 82            [24] 4528 	mov	dpl,r4
      0015A1 8D 83            [24] 4529 	mov	dph,r5
      0015A3 8F F0            [24] 4530 	mov	b,r7
      0015A5 12 43 A8         [24] 4531 	lcall	__gptrget
      0015A8 FC               [12] 4532 	mov	r4,a
      0015A9 A3               [24] 4533 	inc	dptr
      0015AA 12 43 A8         [24] 4534 	lcall	__gptrget
      0015AD FD               [12] 4535 	mov	r5,a
      0015AE A3               [24] 4536 	inc	dptr
      0015AF 12 43 A8         [24] 4537 	lcall	__gptrget
      0015B2 FF               [12] 4538 	mov	r7,a
      0015B3 A3               [24] 4539 	inc	dptr
      0015B4 12 43 A8         [24] 4540 	lcall	__gptrget
      0015B7 FE               [12] 4541 	mov	r6,a
      0015B8 E5 08            [12] 4542 	mov	a,_bp
      0015BA 24 F9            [12] 4543 	add	a,#0xf9
      0015BC F8               [12] 4544 	mov	r0,a
      0015BD E6               [12] 4545 	mov	a,@r0
      0015BE C0 E0            [24] 4546 	push	acc
      0015C0 E5 08            [12] 4547 	mov	a,_bp
      0015C2 24 FA            [12] 4548 	add	a,#0xfa
      0015C4 F8               [12] 4549 	mov	r0,a
      0015C5 E6               [12] 4550 	mov	a,@r0
      0015C6 C0 E0            [24] 4551 	push	acc
      0015C8 08               [12] 4552 	inc	r0
      0015C9 E6               [12] 4553 	mov	a,@r0
      0015CA C0 E0            [24] 4554 	push	acc
      0015CC 08               [12] 4555 	inc	r0
      0015CD E6               [12] 4556 	mov	a,@r0
      0015CE C0 E0            [24] 4557 	push	acc
      0015D0 08               [12] 4558 	inc	r0
      0015D1 E6               [12] 4559 	mov	a,@r0
      0015D2 C0 E0            [24] 4560 	push	acc
      0015D4 A8 08            [24] 4561 	mov	r0,_bp
      0015D6 08               [12] 4562 	inc	r0
      0015D7 E6               [12] 4563 	mov	a,@r0
      0015D8 C0 E0            [24] 4564 	push	acc
      0015DA 08               [12] 4565 	inc	r0
      0015DB E6               [12] 4566 	mov	a,@r0
      0015DC C0 E0            [24] 4567 	push	acc
      0015DE 08               [12] 4568 	inc	r0
      0015DF E6               [12] 4569 	mov	a,@r0
      0015E0 C0 E0            [24] 4570 	push	acc
      0015E2 08               [12] 4571 	inc	r0
      0015E3 E6               [12] 4572 	mov	a,@r0
      0015E4 C0 E0            [24] 4573 	push	acc
      0015E6 E5 08            [12] 4574 	mov	a,_bp
      0015E8 24 05            [12] 4575 	add	a,#0x05
      0015EA F8               [12] 4576 	mov	r0,a
      0015EB E6               [12] 4577 	mov	a,@r0
      0015EC C0 E0            [24] 4578 	push	acc
      0015EE 08               [12] 4579 	inc	r0
      0015EF E6               [12] 4580 	mov	a,@r0
      0015F0 C0 E0            [24] 4581 	push	acc
      0015F2 08               [12] 4582 	inc	r0
      0015F3 E6               [12] 4583 	mov	a,@r0
      0015F4 C0 E0            [24] 4584 	push	acc
      0015F6 08               [12] 4585 	inc	r0
      0015F7 E6               [12] 4586 	mov	a,@r0
      0015F8 C0 E0            [24] 4587 	push	acc
      0015FA 8C 82            [24] 4588 	mov	dpl, r4
      0015FC 8D 83            [24] 4589 	mov	dph, r5
      0015FE 8F F0            [24] 4590 	mov	b, r7
      001600 EE               [12] 4591 	mov	a, r6
      001601 12 0D 2F         [24] 4592 	lcall	_fuzzy_triangle
      001604 AC 82            [24] 4593 	mov	r4, dpl
      001606 AD 83            [24] 4594 	mov	r5, dph
      001608 AE F0            [24] 4595 	mov	r6, b
      00160A FF               [12] 4596 	mov	r7, a
      00160B E5 81            [12] 4597 	mov	a,sp
      00160D 24 F3            [12] 4598 	add	a,#0xf3
      00160F F5 81            [12] 4599 	mov	sp,a
      001611 8C 82            [24] 4600 	mov	dpl, r4
      001613 8D 83            [24] 4601 	mov	dph, r5
      001615 8E F0            [24] 4602 	mov	b, r6
      001617 EF               [12] 4603 	mov	a, r7
      001618 02 17 6D         [24] 4604 	ljmp	00123$
                           00155E  4605 	C$fuzzy.h$1955$2_0$87 ==.
                                   4606 ;	../../fuzzy.h:1955: case FUZZY_SHAPE_TRAPEZOID:
      00161B                       4607 00109$:
                           00155E  4608 	C$fuzzy.h$1956$2_0$87 ==.
                                   4609 ;	../../fuzzy.h:1956: if (parameter_count != 4u) {
      00161B E5 08            [12] 4610 	mov	a,_bp
      00161D 24 F7            [12] 4611 	add	a,#0xf7
      00161F F8               [12] 4612 	mov	r0,a
      001620 B6 04 06         [24] 4613 	cjne	@r0,#0x04,00162$
      001623 08               [12] 4614 	inc	r0
      001624 B6 00 02         [24] 4615 	cjne	@r0,#0x00,00162$
      001627 80 09            [24] 4616 	sjmp	00111$
      001629                       4617 00162$:
                           00156C  4618 	C$fuzzy.h$1957$3_0$90 ==.
                                   4619 ;	../../fuzzy.h:1957: return LEVEL_LO;
      001629 90 00 00         [24] 4620 	mov	dptr,#0x0000
      00162C E4               [12] 4621 	clr	a
      00162D F5 F0            [12] 4622 	mov	b,a
      00162F 02 17 6D         [24] 4623 	ljmp	00123$
      001632                       4624 00111$:
                           001575  4625 	C$fuzzy.h$1964$2_0$87 ==.
                                   4626 ;	../../fuzzy.h:1964: parameters[3],
      001632 E5 08            [12] 4627 	mov	a,_bp
      001634 24 F4            [12] 4628 	add	a,#0xf4
      001636 F8               [12] 4629 	mov	r0,a
      001637 74 0C            [12] 4630 	mov	a,#0x0c
      001639 26               [12] 4631 	add	a, @r0
      00163A FD               [12] 4632 	mov	r5,a
      00163B E4               [12] 4633 	clr	a
      00163C 08               [12] 4634 	inc	r0
      00163D 36               [12] 4635 	addc	a, @r0
      00163E FE               [12] 4636 	mov	r6,a
      00163F 08               [12] 4637 	inc	r0
      001640 86 07            [24] 4638 	mov	ar7,@r0
      001642 8D 82            [24] 4639 	mov	dpl,r5
      001644 8E 83            [24] 4640 	mov	dph,r6
      001646 8F F0            [24] 4641 	mov	b,r7
      001648 E5 08            [12] 4642 	mov	a,_bp
      00164A 24 05            [12] 4643 	add	a,#0x05
      00164C F8               [12] 4644 	mov	r0,a
      00164D 12 43 A8         [24] 4645 	lcall	__gptrget
      001650 F6               [12] 4646 	mov	@r0,a
      001651 A3               [24] 4647 	inc	dptr
      001652 12 43 A8         [24] 4648 	lcall	__gptrget
      001655 08               [12] 4649 	inc	r0
      001656 F6               [12] 4650 	mov	@r0,a
      001657 A3               [24] 4651 	inc	dptr
      001658 12 43 A8         [24] 4652 	lcall	__gptrget
      00165B 08               [12] 4653 	inc	r0
      00165C F6               [12] 4654 	mov	@r0,a
      00165D A3               [24] 4655 	inc	dptr
      00165E 12 43 A8         [24] 4656 	lcall	__gptrget
      001661 08               [12] 4657 	inc	r0
      001662 F6               [12] 4658 	mov	@r0,a
                           0015A6  4659 	C$fuzzy.h$1963$2_0$87 ==.
                                   4660 ;	../../fuzzy.h:1963: parameters[2],
      001663 E5 08            [12] 4661 	mov	a,_bp
      001665 24 F4            [12] 4662 	add	a,#0xf4
      001667 F8               [12] 4663 	mov	r0,a
      001668 74 08            [12] 4664 	mov	a,#0x08
      00166A 26               [12] 4665 	add	a, @r0
      00166B FA               [12] 4666 	mov	r2,a
      00166C E4               [12] 4667 	clr	a
      00166D 08               [12] 4668 	inc	r0
      00166E 36               [12] 4669 	addc	a, @r0
      00166F FB               [12] 4670 	mov	r3,a
      001670 08               [12] 4671 	inc	r0
      001671 86 07            [24] 4672 	mov	ar7,@r0
      001673 8A 82            [24] 4673 	mov	dpl,r2
      001675 8B 83            [24] 4674 	mov	dph,r3
      001677 8F F0            [24] 4675 	mov	b,r7
      001679 A8 08            [24] 4676 	mov	r0,_bp
      00167B 08               [12] 4677 	inc	r0
      00167C 12 43 A8         [24] 4678 	lcall	__gptrget
      00167F F6               [12] 4679 	mov	@r0,a
      001680 A3               [24] 4680 	inc	dptr
      001681 12 43 A8         [24] 4681 	lcall	__gptrget
      001684 08               [12] 4682 	inc	r0
      001685 F6               [12] 4683 	mov	@r0,a
      001686 A3               [24] 4684 	inc	dptr
      001687 12 43 A8         [24] 4685 	lcall	__gptrget
      00168A 08               [12] 4686 	inc	r0
      00168B F6               [12] 4687 	mov	@r0,a
      00168C A3               [24] 4688 	inc	dptr
      00168D 12 43 A8         [24] 4689 	lcall	__gptrget
      001690 08               [12] 4690 	inc	r0
      001691 F6               [12] 4691 	mov	@r0,a
                           0015D5  4692 	C$fuzzy.h$1962$2_0$87 ==.
                                   4693 ;	../../fuzzy.h:1962: parameters[1],
      001692 E5 08            [12] 4694 	mov	a,_bp
      001694 24 F4            [12] 4695 	add	a,#0xf4
      001696 F8               [12] 4696 	mov	r0,a
      001697 74 04            [12] 4697 	mov	a,#0x04
      001699 26               [12] 4698 	add	a, @r0
      00169A FC               [12] 4699 	mov	r4,a
      00169B E4               [12] 4700 	clr	a
      00169C 08               [12] 4701 	inc	r0
      00169D 36               [12] 4702 	addc	a, @r0
      00169E FD               [12] 4703 	mov	r5,a
      00169F 08               [12] 4704 	inc	r0
      0016A0 86 07            [24] 4705 	mov	ar7,@r0
      0016A2 8C 82            [24] 4706 	mov	dpl,r4
      0016A4 8D 83            [24] 4707 	mov	dph,r5
      0016A6 8F F0            [24] 4708 	mov	b,r7
      0016A8 E5 08            [12] 4709 	mov	a,_bp
      0016AA 24 09            [12] 4710 	add	a,#0x09
      0016AC F8               [12] 4711 	mov	r0,a
      0016AD 12 43 A8         [24] 4712 	lcall	__gptrget
      0016B0 F6               [12] 4713 	mov	@r0,a
      0016B1 A3               [24] 4714 	inc	dptr
      0016B2 12 43 A8         [24] 4715 	lcall	__gptrget
      0016B5 08               [12] 4716 	inc	r0
      0016B6 F6               [12] 4717 	mov	@r0,a
      0016B7 A3               [24] 4718 	inc	dptr
      0016B8 12 43 A8         [24] 4719 	lcall	__gptrget
      0016BB 08               [12] 4720 	inc	r0
      0016BC F6               [12] 4721 	mov	@r0,a
      0016BD A3               [24] 4722 	inc	dptr
      0016BE 12 43 A8         [24] 4723 	lcall	__gptrget
      0016C1 08               [12] 4724 	inc	r0
      0016C2 F6               [12] 4725 	mov	@r0,a
                           001606  4726 	C$fuzzy.h$1961$2_0$87 ==.
                                   4727 ;	../../fuzzy.h:1961: parameters[0],
      0016C3 E5 08            [12] 4728 	mov	a,_bp
      0016C5 24 F4            [12] 4729 	add	a,#0xf4
      0016C7 F8               [12] 4730 	mov	r0,a
      0016C8 86 02            [24] 4731 	mov	ar2,@r0
      0016CA 08               [12] 4732 	inc	r0
      0016CB 86 03            [24] 4733 	mov	ar3,@r0
      0016CD 08               [12] 4734 	inc	r0
      0016CE 86 07            [24] 4735 	mov	ar7,@r0
      0016D0 8A 82            [24] 4736 	mov	dpl,r2
      0016D2 8B 83            [24] 4737 	mov	dph,r3
      0016D4 8F F0            [24] 4738 	mov	b,r7
      0016D6 12 43 A8         [24] 4739 	lcall	__gptrget
      0016D9 FA               [12] 4740 	mov	r2,a
      0016DA A3               [24] 4741 	inc	dptr
      0016DB 12 43 A8         [24] 4742 	lcall	__gptrget
      0016DE FB               [12] 4743 	mov	r3,a
      0016DF A3               [24] 4744 	inc	dptr
      0016E0 12 43 A8         [24] 4745 	lcall	__gptrget
      0016E3 FF               [12] 4746 	mov	r7,a
      0016E4 A3               [24] 4747 	inc	dptr
      0016E5 12 43 A8         [24] 4748 	lcall	__gptrget
      0016E8 FE               [12] 4749 	mov	r6,a
      0016E9 E5 08            [12] 4750 	mov	a,_bp
      0016EB 24 F9            [12] 4751 	add	a,#0xf9
      0016ED F8               [12] 4752 	mov	r0,a
      0016EE E6               [12] 4753 	mov	a,@r0
      0016EF C0 E0            [24] 4754 	push	acc
      0016F1 E5 08            [12] 4755 	mov	a,_bp
      0016F3 24 FA            [12] 4756 	add	a,#0xfa
      0016F5 F8               [12] 4757 	mov	r0,a
      0016F6 E6               [12] 4758 	mov	a,@r0
      0016F7 C0 E0            [24] 4759 	push	acc
      0016F9 08               [12] 4760 	inc	r0
      0016FA E6               [12] 4761 	mov	a,@r0
      0016FB C0 E0            [24] 4762 	push	acc
      0016FD 08               [12] 4763 	inc	r0
      0016FE E6               [12] 4764 	mov	a,@r0
      0016FF C0 E0            [24] 4765 	push	acc
      001701 08               [12] 4766 	inc	r0
      001702 E6               [12] 4767 	mov	a,@r0
      001703 C0 E0            [24] 4768 	push	acc
      001705 E5 08            [12] 4769 	mov	a,_bp
      001707 24 05            [12] 4770 	add	a,#0x05
      001709 F8               [12] 4771 	mov	r0,a
      00170A E6               [12] 4772 	mov	a,@r0
      00170B C0 E0            [24] 4773 	push	acc
      00170D 08               [12] 4774 	inc	r0
      00170E E6               [12] 4775 	mov	a,@r0
      00170F C0 E0            [24] 4776 	push	acc
      001711 08               [12] 4777 	inc	r0
      001712 E6               [12] 4778 	mov	a,@r0
      001713 C0 E0            [24] 4779 	push	acc
      001715 08               [12] 4780 	inc	r0
      001716 E6               [12] 4781 	mov	a,@r0
      001717 C0 E0            [24] 4782 	push	acc
      001719 A8 08            [24] 4783 	mov	r0,_bp
      00171B 08               [12] 4784 	inc	r0
      00171C E6               [12] 4785 	mov	a,@r0
      00171D C0 E0            [24] 4786 	push	acc
      00171F 08               [12] 4787 	inc	r0
      001720 E6               [12] 4788 	mov	a,@r0
      001721 C0 E0            [24] 4789 	push	acc
      001723 08               [12] 4790 	inc	r0
      001724 E6               [12] 4791 	mov	a,@r0
      001725 C0 E0            [24] 4792 	push	acc
      001727 08               [12] 4793 	inc	r0
      001728 E6               [12] 4794 	mov	a,@r0
      001729 C0 E0            [24] 4795 	push	acc
      00172B E5 08            [12] 4796 	mov	a,_bp
      00172D 24 09            [12] 4797 	add	a,#0x09
      00172F F8               [12] 4798 	mov	r0,a
      001730 E6               [12] 4799 	mov	a,@r0
      001731 C0 E0            [24] 4800 	push	acc
      001733 08               [12] 4801 	inc	r0
      001734 E6               [12] 4802 	mov	a,@r0
      001735 C0 E0            [24] 4803 	push	acc
      001737 08               [12] 4804 	inc	r0
      001738 E6               [12] 4805 	mov	a,@r0
      001739 C0 E0            [24] 4806 	push	acc
      00173B 08               [12] 4807 	inc	r0
      00173C E6               [12] 4808 	mov	a,@r0
      00173D C0 E0            [24] 4809 	push	acc
      00173F 8A 82            [24] 4810 	mov	dpl, r2
      001741 8B 83            [24] 4811 	mov	dph, r3
      001743 8F F0            [24] 4812 	mov	b, r7
      001745 EE               [12] 4813 	mov	a, r6
      001746 12 10 3B         [24] 4814 	lcall	_fuzzy_trapezoid
      001749 AC 82            [24] 4815 	mov	r4, dpl
      00174B AD 83            [24] 4816 	mov	r5, dph
      00174D AE F0            [24] 4817 	mov	r6, b
      00174F FF               [12] 4818 	mov	r7, a
      001750 E5 81            [12] 4819 	mov	a,sp
      001752 24 EF            [12] 4820 	add	a,#0xef
      001754 F5 81            [12] 4821 	mov	sp,a
      001756 8C 82            [24] 4822 	mov	dpl, r4
      001758 8D 83            [24] 4823 	mov	dph, r5
      00175A 8E F0            [24] 4824 	mov	b, r6
      00175C EF               [12] 4825 	mov	a, r7
                           0016A0  4826 	C$fuzzy.h$2098$2_0$87 ==.
                                   4827 ;	../../fuzzy.h:2098: case FUZZY_SHAPE_PSIGMOID:
      00175D 80 0E            [24] 4828 	sjmp	00123$
      00175F                       4829 00120$:
                           0016A2  4830 	C$fuzzy.h$2099$2_0$87 ==.
                                   4831 ;	../../fuzzy.h:2099: return LEVEL_LO;
      00175F 90 00 00         [24] 4832 	mov	dptr,#0x0000
      001762 E4               [12] 4833 	clr	a
      001763 F5 F0            [12] 4834 	mov	b,a
                           0016A8  4835 	C$fuzzy.h$2103$2_0$87 ==.
                                   4836 ;	../../fuzzy.h:2103: default:
      001765 80 06            [24] 4837 	sjmp	00123$
      001767                       4838 00121$:
                           0016AA  4839 	C$fuzzy.h$2104$2_0$87 ==.
                                   4840 ;	../../fuzzy.h:2104: return LEVEL_LO;
      001767 90 00 00         [24] 4841 	mov	dptr,#0x0000
      00176A E4               [12] 4842 	clr	a
      00176B F5 F0            [12] 4843 	mov	b,a
                           0016B0  4844 	C$fuzzy.h$2105$1_0$85 ==.
                                   4845 ;	../../fuzzy.h:2105: }
      00176D                       4846 00123$:
                           0016B0  4847 	C$fuzzy.h$2106$1_0$85 ==.
                                   4848 ;	../../fuzzy.h:2106: }
      00176D 85 08 81         [24] 4849 	mov	sp,_bp
      001770 D0 08            [24] 4850 	pop	_bp
                           0016B5  4851 	C$fuzzy.h$2106$1_0$85 ==.
                           0016B5  4852 	XG$fuzzy_function_array$0$0 ==.
      001772 22               [24] 4853 	ret
                                   4854 ;------------------------------------------------------------
                                   4855 ;Allocation info for local variables in function 'fuzzy_rules_add'
                                   4856 ;------------------------------------------------------------
                                   4857 ;name          Allocated to stack - _bp -5 +3 
                                   4858 ;value         Allocated to stack - _bp -9 +4 
                                   4859 ;output_function Allocated to stack - _bp -11 +2 
                                   4860 ;rules         Allocated to registers r2 r3 r4 
                                   4861 ;index         Allocated to registers 
                                   4862 ;sloc0         Allocated to stack - _bp +1 +2 
                                   4863 ;sloc1         Allocated to stack - _bp +3 +3 
                                   4864 ;sloc2         Allocated to stack - _bp +6 +3 
                                   4865 ;sloc3         Allocated to stack - _bp +9 +3 
                                   4866 ;------------------------------------------------------------
                           0016B6  4867 	G$fuzzy_rules_add$0$0 ==.
                           0016B6  4868 	C$fuzzy.h$2108$1_0$92 ==.
                                   4869 ;	../../fuzzy.h:2108: bool fuzzy_rules_add(
                                   4870 ;	-----------------------------------------
                                   4871 ;	 function fuzzy_rules_add
                                   4872 ;	-----------------------------------------
      001773                       4873 _fuzzy_rules_add:
      001773 C0 08            [24] 4874 	push	_bp
      001775 E5 81            [12] 4875 	mov	a,sp
      001777 F5 08            [12] 4876 	mov	_bp,a
      001779 24 0B            [12] 4877 	add	a,#0x0b
      00177B F5 81            [12] 4878 	mov	sp,a
      00177D AA 82            [24] 4879 	mov	r2, dpl
      00177F AB 83            [24] 4880 	mov	r3, dph
      001781 AC F0            [24] 4881 	mov	r4, b
                           0016C6  4882 	C$fuzzy.h$2118$1_0$92 ==.
                                   4883 ;	../../fuzzy.h:2118: rules == NULL ||
      001783 EA               [12] 4884 	mov	a,r2
      001784 4B               [12] 4885 	orl	a,r3
      001785 60 0A            [24] 4886 	jz	00101$
                           0016CA  4887 	C$fuzzy.h$2119$1_0$92 ==.
                                   4888 ;	../../fuzzy.h:2119: output_function == NULL
      001787 E5 08            [12] 4889 	mov	a,_bp
      001789 24 F5            [12] 4890 	add	a,#0xf5
      00178B F8               [12] 4891 	mov	r0,a
      00178C E6               [12] 4892 	mov	a,@r0
      00178D 08               [12] 4893 	inc	r0
      00178E 46               [12] 4894 	orl	a,@r0
      00178F 70 06            [24] 4895 	jnz	00102$
      001791                       4896 00101$:
                           0016D4  4897 	C$fuzzy.h$2121$2_0$93 ==.
                                   4898 ;	../../fuzzy.h:2121: return false;
      001791 75 82 00         [24] 4899 	mov	dpl, #0x00
      001794 02 18 D1         [24] 4900 	ljmp	00106$
      001797                       4901 00102$:
                           0016DA  4902 	C$fuzzy.h$2124$1_0$92 ==.
                                   4903 ;	../../fuzzy.h:2124: if (rules->count >= FUZZY_MAX_RULES) {
      001797 E5 08            [12] 4904 	mov	a,_bp
      001799 24 09            [12] 4905 	add	a,#0x09
      00179B F8               [12] 4906 	mov	r0,a
      00179C 74 90            [12] 4907 	mov	a,#0x90
      00179E 2A               [12] 4908 	add	a, r2
      00179F F6               [12] 4909 	mov	@r0,a
      0017A0 E4               [12] 4910 	clr	a
      0017A1 3B               [12] 4911 	addc	a, r3
      0017A2 08               [12] 4912 	inc	r0
      0017A3 F6               [12] 4913 	mov	@r0,a
      0017A4 08               [12] 4914 	inc	r0
      0017A5 A6 04            [24] 4915 	mov	@r0,ar4
      0017A7 E5 08            [12] 4916 	mov	a,_bp
      0017A9 24 09            [12] 4917 	add	a,#0x09
      0017AB F8               [12] 4918 	mov	r0,a
      0017AC 86 82            [24] 4919 	mov	dpl,@r0
      0017AE 08               [12] 4920 	inc	r0
      0017AF 86 83            [24] 4921 	mov	dph,@r0
      0017B1 08               [12] 4922 	inc	r0
      0017B2 86 F0            [24] 4923 	mov	b,@r0
      0017B4 12 43 A8         [24] 4924 	lcall	__gptrget
      0017B7 FF               [12] 4925 	mov	r7,a
      0017B8 A3               [24] 4926 	inc	dptr
      0017B9 12 43 A8         [24] 4927 	lcall	__gptrget
      0017BC FE               [12] 4928 	mov	r6,a
      0017BD C3               [12] 4929 	clr	c
      0017BE EF               [12] 4930 	mov	a,r7
      0017BF 94 10            [12] 4931 	subb	a,#0x10
      0017C1 EE               [12] 4932 	mov	a,r6
      0017C2 94 00            [12] 4933 	subb	a,#0x00
      0017C4 40 06            [24] 4934 	jc	00105$
                           001709  4935 	C$fuzzy.h$2125$2_0$94 ==.
                                   4936 ;	../../fuzzy.h:2125: return false;
      0017C6 75 82 00         [24] 4937 	mov	dpl, #0x00
      0017C9 02 18 D1         [24] 4938 	ljmp	00106$
      0017CC                       4939 00105$:
                           00170F  4940 	C$fuzzy.h$2131$1_0$92 ==.
                                   4941 ;	../../fuzzy.h:2131: rules->rules[index].name =
      0017CC C0 04            [24] 4942 	push	ar4
      0017CE C0 03            [24] 4943 	push	ar3
      0017D0 C0 02            [24] 4944 	push	ar2
      0017D2 C0 07            [24] 4945 	push	ar7
      0017D4 C0 06            [24] 4946 	push	ar6
      0017D6 90 00 09         [24] 4947 	mov	dptr,#0x0009
      0017D9 12 41 AC         [24] 4948 	lcall	__mulint
      0017DC A8 08            [24] 4949 	mov	r0,_bp
      0017DE 08               [12] 4950 	inc	r0
      0017DF A6 82            [24] 4951 	mov	@r0, dpl
      0017E1 08               [12] 4952 	inc	r0
      0017E2 A6 83            [24] 4953 	mov	@r0, dph
      0017E4 15 81            [12] 4954 	dec	sp
      0017E6 15 81            [12] 4955 	dec	sp
      0017E8 D0 02            [24] 4956 	pop	ar2
      0017EA D0 03            [24] 4957 	pop	ar3
      0017EC D0 04            [24] 4958 	pop	ar4
      0017EE A8 08            [24] 4959 	mov	r0,_bp
      0017F0 08               [12] 4960 	inc	r0
      0017F1 E6               [12] 4961 	mov	a,@r0
      0017F2 2A               [12] 4962 	add	a, r2
      0017F3 FD               [12] 4963 	mov	r5,a
      0017F4 08               [12] 4964 	inc	r0
      0017F5 E6               [12] 4965 	mov	a,@r0
      0017F6 3B               [12] 4966 	addc	a, r3
      0017F7 FE               [12] 4967 	mov	r6,a
      0017F8 8C 07            [24] 4968 	mov	ar7,r4
      0017FA 8D 82            [24] 4969 	mov	dpl,r5
      0017FC 8E 83            [24] 4970 	mov	dph,r6
      0017FE 8F F0            [24] 4971 	mov	b,r7
      001800 E5 08            [12] 4972 	mov	a,_bp
      001802 24 FB            [12] 4973 	add	a,#0xfb
      001804 F8               [12] 4974 	mov	r0,a
      001805 E6               [12] 4975 	mov	a,@r0
      001806 12 41 61         [24] 4976 	lcall	__gptrput
      001809 A3               [24] 4977 	inc	dptr
      00180A 08               [12] 4978 	inc	r0
      00180B E6               [12] 4979 	mov	a,@r0
      00180C 12 41 61         [24] 4980 	lcall	__gptrput
      00180F A3               [24] 4981 	inc	dptr
      001810 08               [12] 4982 	inc	r0
      001811 E6               [12] 4983 	mov	a,@r0
      001812 12 41 61         [24] 4984 	lcall	__gptrput
                           001758  4985 	C$fuzzy.h$2134$1_0$92 ==.
                                   4986 ;	../../fuzzy.h:2134: rules->rules[index].value =
      001815 A8 08            [24] 4987 	mov	r0,_bp
      001817 08               [12] 4988 	inc	r0
      001818 E5 08            [12] 4989 	mov	a,_bp
      00181A 24 03            [12] 4990 	add	a,#0x03
      00181C F9               [12] 4991 	mov	r1,a
      00181D E6               [12] 4992 	mov	a,@r0
      00181E 2A               [12] 4993 	add	a, r2
      00181F F7               [12] 4994 	mov	@r1,a
      001820 08               [12] 4995 	inc	r0
      001821 E6               [12] 4996 	mov	a,@r0
      001822 3B               [12] 4997 	addc	a, r3
      001823 09               [12] 4998 	inc	r1
      001824 F7               [12] 4999 	mov	@r1,a
      001825 09               [12] 5000 	inc	r1
      001826 A7 04            [24] 5001 	mov	@r1,ar4
      001828 E5 08            [12] 5002 	mov	a,_bp
      00182A 24 03            [12] 5003 	add	a,#0x03
      00182C F8               [12] 5004 	mov	r0,a
      00182D E5 08            [12] 5005 	mov	a,_bp
      00182F 24 06            [12] 5006 	add	a,#0x06
      001831 F9               [12] 5007 	mov	r1,a
      001832 74 03            [12] 5008 	mov	a,#0x03
      001834 26               [12] 5009 	add	a, @r0
      001835 F7               [12] 5010 	mov	@r1,a
      001836 E4               [12] 5011 	clr	a
      001837 08               [12] 5012 	inc	r0
      001838 36               [12] 5013 	addc	a, @r0
      001839 09               [12] 5014 	inc	r1
      00183A F7               [12] 5015 	mov	@r1,a
      00183B 08               [12] 5016 	inc	r0
      00183C E6               [12] 5017 	mov	a,@r0
      00183D 09               [12] 5018 	inc	r1
      00183E F7               [12] 5019 	mov	@r1,a
                           001782  5020 	C$fuzzy.h$2135$1_0$92 ==.
                                   5021 ;	../../fuzzy.h:2135: fuzzy_clamp(value);
      00183F E5 08            [12] 5022 	mov	a,_bp
      001841 24 F7            [12] 5023 	add	a,#0xf7
      001843 F8               [12] 5024 	mov	r0,a
      001844 86 82            [24] 5025 	mov	dpl, @r0
      001846 08               [12] 5026 	inc	r0
      001847 86 83            [24] 5027 	mov	dph, @r0
      001849 08               [12] 5028 	inc	r0
      00184A 86 F0            [24] 5029 	mov	b, @r0
      00184C 08               [12] 5030 	inc	r0
      00184D E6               [12] 5031 	mov	a, @r0
      00184E 12 00 F0         [24] 5032 	lcall	_fuzzy_clamp
      001851 AD 82            [24] 5033 	mov	r5, dpl
      001853 AE 83            [24] 5034 	mov	r6, dph
      001855 AC F0            [24] 5035 	mov	r4, b
      001857 FF               [12] 5036 	mov	r7, a
      001858 E5 08            [12] 5037 	mov	a,_bp
      00185A 24 06            [12] 5038 	add	a,#0x06
      00185C F8               [12] 5039 	mov	r0,a
      00185D 86 82            [24] 5040 	mov	dpl,@r0
      00185F 08               [12] 5041 	inc	r0
      001860 86 83            [24] 5042 	mov	dph,@r0
      001862 08               [12] 5043 	inc	r0
      001863 86 F0            [24] 5044 	mov	b,@r0
      001865 ED               [12] 5045 	mov	a,r5
      001866 12 41 61         [24] 5046 	lcall	__gptrput
      001869 A3               [24] 5047 	inc	dptr
      00186A EE               [12] 5048 	mov	a,r6
      00186B 12 41 61         [24] 5049 	lcall	__gptrput
      00186E A3               [24] 5050 	inc	dptr
      00186F EC               [12] 5051 	mov	a,r4
      001870 12 41 61         [24] 5052 	lcall	__gptrput
      001873 A3               [24] 5053 	inc	dptr
      001874 EF               [12] 5054 	mov	a,r7
      001875 12 41 61         [24] 5055 	lcall	__gptrput
                           0017BB  5056 	C$fuzzy.h$2137$1_0$92 ==.
                                   5057 ;	../../fuzzy.h:2137: rules->rules[index].output_function =
      001878 E5 08            [12] 5058 	mov	a,_bp
      00187A 24 03            [12] 5059 	add	a,#0x03
      00187C F8               [12] 5060 	mov	r0,a
      00187D 74 07            [12] 5061 	mov	a,#0x07
      00187F 26               [12] 5062 	add	a, @r0
      001880 FD               [12] 5063 	mov	r5,a
      001881 E4               [12] 5064 	clr	a
      001882 08               [12] 5065 	inc	r0
      001883 36               [12] 5066 	addc	a, @r0
      001884 FE               [12] 5067 	mov	r6,a
      001885 08               [12] 5068 	inc	r0
      001886 86 07            [24] 5069 	mov	ar7,@r0
      001888 8D 82            [24] 5070 	mov	dpl,r5
      00188A 8E 83            [24] 5071 	mov	dph,r6
      00188C 8F F0            [24] 5072 	mov	b,r7
      00188E E5 08            [12] 5073 	mov	a,_bp
      001890 24 F5            [12] 5074 	add	a,#0xf5
      001892 F8               [12] 5075 	mov	r0,a
      001893 E6               [12] 5076 	mov	a,@r0
      001894 12 41 61         [24] 5077 	lcall	__gptrput
      001897 A3               [24] 5078 	inc	dptr
      001898 08               [12] 5079 	inc	r0
      001899 E6               [12] 5080 	mov	a,@r0
      00189A 12 41 61         [24] 5081 	lcall	__gptrput
                           0017E0  5082 	C$fuzzy.h$2140$1_0$92 ==.
                                   5083 ;	../../fuzzy.h:2140: rules->count++;
      00189D E5 08            [12] 5084 	mov	a,_bp
      00189F 24 09            [12] 5085 	add	a,#0x09
      0018A1 F8               [12] 5086 	mov	r0,a
      0018A2 86 82            [24] 5087 	mov	dpl,@r0
      0018A4 08               [12] 5088 	inc	r0
      0018A5 86 83            [24] 5089 	mov	dph,@r0
      0018A7 08               [12] 5090 	inc	r0
      0018A8 86 F0            [24] 5091 	mov	b,@r0
      0018AA 12 43 A8         [24] 5092 	lcall	__gptrget
      0018AD FE               [12] 5093 	mov	r6,a
      0018AE A3               [24] 5094 	inc	dptr
      0018AF 12 43 A8         [24] 5095 	lcall	__gptrget
      0018B2 FF               [12] 5096 	mov	r7,a
      0018B3 0E               [12] 5097 	inc	r6
      0018B4 BE 00 01         [24] 5098 	cjne	r6,#0x00,00123$
      0018B7 0F               [12] 5099 	inc	r7
      0018B8                       5100 00123$:
      0018B8 E5 08            [12] 5101 	mov	a,_bp
      0018BA 24 09            [12] 5102 	add	a,#0x09
      0018BC F8               [12] 5103 	mov	r0,a
      0018BD 86 82            [24] 5104 	mov	dpl,@r0
      0018BF 08               [12] 5105 	inc	r0
      0018C0 86 83            [24] 5106 	mov	dph,@r0
      0018C2 08               [12] 5107 	inc	r0
      0018C3 86 F0            [24] 5108 	mov	b,@r0
      0018C5 EE               [12] 5109 	mov	a,r6
      0018C6 12 41 61         [24] 5110 	lcall	__gptrput
      0018C9 A3               [24] 5111 	inc	dptr
      0018CA EF               [12] 5112 	mov	a,r7
      0018CB 12 41 61         [24] 5113 	lcall	__gptrput
                           001811  5114 	C$fuzzy.h$2142$1_0$92 ==.
                                   5115 ;	../../fuzzy.h:2142: return true;
      0018CE 75 82 01         [24] 5116 	mov	dpl, #0x01
      0018D1                       5117 00106$:
                           001814  5118 	C$fuzzy.h$2143$1_0$92 ==.
                                   5119 ;	../../fuzzy.h:2143: }
      0018D1 85 08 81         [24] 5120 	mov	sp,_bp
      0018D4 D0 08            [24] 5121 	pop	_bp
                           001819  5122 	C$fuzzy.h$2143$1_0$92 ==.
                           001819  5123 	XG$fuzzy_rules_add$0$0 ==.
      0018D6 22               [24] 5124 	ret
                                   5125 ;------------------------------------------------------------
                                   5126 ;Allocation info for local variables in function 'fuzzy_implication'
                                   5127 ;------------------------------------------------------------
                                   5128 ;activation    Allocated to stack - _bp -6 +4 
                                   5129 ;membership    Allocated to stack - _bp -10 +4 
                                   5130 ;method        Allocated to registers r7 
                                   5131 ;sloc0         Allocated to stack - _bp +1 +4 
                                   5132 ;sloc1         Allocated to stack - _bp +5 +4 
                                   5133 ;------------------------------------------------------------
                           00181A  5134 	Fsugeno_demo$fuzzy_implication$0$0 ==.
                           00181A  5135 	C$fuzzy.h$2176$1_0$96 ==.
                                   5136 ;	../../fuzzy.h:2176: static float fuzzy_implication(
                                   5137 ;	-----------------------------------------
                                   5138 ;	 function fuzzy_implication
                                   5139 ;	-----------------------------------------
      0018D7                       5140 _fuzzy_implication:
      0018D7 C0 08            [24] 5141 	push	_bp
      0018D9 E5 81            [12] 5142 	mov	a,sp
      0018DB F5 08            [12] 5143 	mov	_bp,a
      0018DD 24 08            [12] 5144 	add	a,#0x08
      0018DF F5 81            [12] 5145 	mov	sp,a
      0018E1 AF 82            [24] 5146 	mov	r7, dpl
                           001826  5147 	C$fuzzy.h$2182$1_0$96 ==.
                                   5148 ;	../../fuzzy.h:2182: activation = fuzzy_clamp(activation);
      0018E3 E5 08            [12] 5149 	mov	a,_bp
      0018E5 24 FA            [12] 5150 	add	a,#0xfa
      0018E7 F8               [12] 5151 	mov	r0,a
      0018E8 86 82            [24] 5152 	mov	dpl, @r0
      0018EA 08               [12] 5153 	inc	r0
      0018EB 86 83            [24] 5154 	mov	dph, @r0
      0018ED 08               [12] 5155 	inc	r0
      0018EE 86 F0            [24] 5156 	mov	b, @r0
      0018F0 08               [12] 5157 	inc	r0
      0018F1 E6               [12] 5158 	mov	a, @r0
      0018F2 C0 07            [24] 5159 	push	ar7
      0018F4 12 00 F0         [24] 5160 	lcall	_fuzzy_clamp
      0018F7 AB 82            [24] 5161 	mov	r3, dpl
      0018F9 AC 83            [24] 5162 	mov	r4, dph
      0018FB AD F0            [24] 5163 	mov	r5, b
      0018FD FE               [12] 5164 	mov	r6, a
                           001841  5165 	C$fuzzy.h$2183$1_0$96 ==.
                                   5166 ;	../../fuzzy.h:2183: membership = fuzzy_clamp(membership);
      0018FE E5 08            [12] 5167 	mov	a,_bp
      001900 24 F6            [12] 5168 	add	a,#0xf6
      001902 F8               [12] 5169 	mov	r0,a
      001903 86 82            [24] 5170 	mov	dpl, @r0
      001905 08               [12] 5171 	inc	r0
      001906 86 83            [24] 5172 	mov	dph, @r0
      001908 08               [12] 5173 	inc	r0
      001909 86 F0            [24] 5174 	mov	b, @r0
      00190B 08               [12] 5175 	inc	r0
      00190C E6               [12] 5176 	mov	a, @r0
      00190D C0 06            [24] 5177 	push	ar6
      00190F C0 05            [24] 5178 	push	ar5
      001911 C0 04            [24] 5179 	push	ar4
      001913 C0 03            [24] 5180 	push	ar3
      001915 12 00 F0         [24] 5181 	lcall	_fuzzy_clamp
      001918 A8 08            [24] 5182 	mov	r0,_bp
      00191A 08               [12] 5183 	inc	r0
      00191B A6 82            [24] 5184 	mov	@r0, dpl
      00191D 08               [12] 5185 	inc	r0
      00191E A6 83            [24] 5186 	mov	@r0, dph
      001920 08               [12] 5187 	inc	r0
      001921 A6 F0            [24] 5188 	mov	@r0, b
      001923 08               [12] 5189 	inc	r0
      001924 F6               [12] 5190 	mov	@r0,a
      001925 D0 03            [24] 5191 	pop	ar3
      001927 D0 04            [24] 5192 	pop	ar4
      001929 D0 05            [24] 5193 	pop	ar5
      00192B D0 06            [24] 5194 	pop	ar6
      00192D D0 07            [24] 5195 	pop	ar7
                           001872  5196 	C$fuzzy.h$2185$1_0$96 ==.
                                   5197 ;	../../fuzzy.h:2185: switch (method) {
      00192F BF 00 02         [24] 5198 	cjne	r7,#0x00,00127$
      001932 80 08            [24] 5199 	sjmp	00101$
      001934                       5200 00127$:
      001934 BF 01 02         [24] 5201 	cjne	r7,#0x01,00128$
      001937 80 73            [24] 5202 	sjmp	00102$
      001939                       5203 00128$:
      001939 02 19 DE         [24] 5204 	ljmp	00103$
                           00187F  5205 	C$fuzzy.h$2186$2_0$97 ==.
                                   5206 ;	../../fuzzy.h:2186: case FUZZY_IMPLICATION_MIN:
      00193C                       5207 00101$:
                           00187F  5208 	C$fuzzy.h$2188$1_0$96 ==.
                                   5209 ;	../../fuzzy.h:2188: ? activation
      00193C C0 06            [24] 5210 	push	ar6
      00193E C0 05            [24] 5211 	push	ar5
      001940 C0 04            [24] 5212 	push	ar4
      001942 C0 03            [24] 5213 	push	ar3
      001944 A8 08            [24] 5214 	mov	r0,_bp
      001946 08               [12] 5215 	inc	r0
      001947 E6               [12] 5216 	mov	a,@r0
      001948 C0 E0            [24] 5217 	push	acc
      00194A 08               [12] 5218 	inc	r0
      00194B E6               [12] 5219 	mov	a,@r0
      00194C C0 E0            [24] 5220 	push	acc
      00194E 08               [12] 5221 	inc	r0
      00194F E6               [12] 5222 	mov	a,@r0
      001950 C0 E0            [24] 5223 	push	acc
      001952 08               [12] 5224 	inc	r0
      001953 E6               [12] 5225 	mov	a,@r0
      001954 C0 E0            [24] 5226 	push	acc
      001956 8B 82            [24] 5227 	mov	dpl, r3
      001958 8C 83            [24] 5228 	mov	dph, r4
      00195A 8D F0            [24] 5229 	mov	b, r5
      00195C EE               [12] 5230 	mov	a, r6
      00195D 12 41 7C         [24] 5231 	lcall	___fslt
      001960 AF 82            [24] 5232 	mov	r7, dpl
      001962 E5 81            [12] 5233 	mov	a,sp
      001964 24 FC            [12] 5234 	add	a,#0xfc
      001966 F5 81            [12] 5235 	mov	sp,a
      001968 D0 03            [24] 5236 	pop	ar3
      00196A D0 04            [24] 5237 	pop	ar4
      00196C D0 05            [24] 5238 	pop	ar5
      00196E D0 06            [24] 5239 	pop	ar6
      001970 EF               [12] 5240 	mov	a,r7
      001971 60 12            [24] 5241 	jz	00107$
      001973 E5 08            [12] 5242 	mov	a,_bp
      001975 24 05            [12] 5243 	add	a,#0x05
      001977 F8               [12] 5244 	mov	r0,a
      001978 A6 03            [24] 5245 	mov	@r0,ar3
      00197A 08               [12] 5246 	inc	r0
      00197B A6 04            [24] 5247 	mov	@r0,ar4
      00197D 08               [12] 5248 	inc	r0
      00197E A6 05            [24] 5249 	mov	@r0,ar5
      001980 08               [12] 5250 	inc	r0
      001981 A6 06            [24] 5251 	mov	@r0,ar6
      001983 80 16            [24] 5252 	sjmp	00108$
      001985                       5253 00107$:
                           0018C8  5254 	C$fuzzy.h$2189$2_0$97 ==.
                                   5255 ;	../../fuzzy.h:2189: : membership;
      001985 A8 08            [24] 5256 	mov	r0,_bp
      001987 08               [12] 5257 	inc	r0
      001988 E5 08            [12] 5258 	mov	a,_bp
      00198A 24 05            [12] 5259 	add	a,#0x05
      00198C F9               [12] 5260 	mov	r1,a
      00198D E6               [12] 5261 	mov	a,@r0
      00198E F7               [12] 5262 	mov	@r1,a
      00198F 08               [12] 5263 	inc	r0
      001990 E6               [12] 5264 	mov	a,@r0
      001991 09               [12] 5265 	inc	r1
      001992 F7               [12] 5266 	mov	@r1,a
      001993 08               [12] 5267 	inc	r0
      001994 E6               [12] 5268 	mov	a,@r0
      001995 09               [12] 5269 	inc	r1
      001996 F7               [12] 5270 	mov	@r1,a
      001997 08               [12] 5271 	inc	r0
      001998 E6               [12] 5272 	mov	a,@r0
      001999 09               [12] 5273 	inc	r1
      00199A F7               [12] 5274 	mov	@r1,a
      00199B                       5275 00108$:
      00199B E5 08            [12] 5276 	mov	a,_bp
      00199D 24 05            [12] 5277 	add	a,#0x05
      00199F F8               [12] 5278 	mov	r0,a
      0019A0 86 82            [24] 5279 	mov	dpl, @r0
      0019A2 08               [12] 5280 	inc	r0
      0019A3 86 83            [24] 5281 	mov	dph, @r0
      0019A5 08               [12] 5282 	inc	r0
      0019A6 86 F0            [24] 5283 	mov	b, @r0
      0019A8 08               [12] 5284 	inc	r0
      0019A9 E6               [12] 5285 	mov	a, @r0
                           0018ED  5286 	C$fuzzy.h$2191$2_0$97 ==.
                                   5287 ;	../../fuzzy.h:2191: case FUZZY_IMPLICATION_PRODUCT:
      0019AA 80 38            [24] 5288 	sjmp	00105$
      0019AC                       5289 00102$:
                           0018EF  5290 	C$fuzzy.h$2192$1_0$96 ==.
                                   5291 ;	../../fuzzy.h:2192: return activation * membership;
      0019AC A8 08            [24] 5292 	mov	r0,_bp
      0019AE 08               [12] 5293 	inc	r0
      0019AF E6               [12] 5294 	mov	a,@r0
      0019B0 C0 E0            [24] 5295 	push	acc
      0019B2 08               [12] 5296 	inc	r0
      0019B3 E6               [12] 5297 	mov	a,@r0
      0019B4 C0 E0            [24] 5298 	push	acc
      0019B6 08               [12] 5299 	inc	r0
      0019B7 E6               [12] 5300 	mov	a,@r0
      0019B8 C0 E0            [24] 5301 	push	acc
      0019BA 08               [12] 5302 	inc	r0
      0019BB E6               [12] 5303 	mov	a,@r0
      0019BC C0 E0            [24] 5304 	push	acc
      0019BE 8B 82            [24] 5305 	mov	dpl, r3
      0019C0 8C 83            [24] 5306 	mov	dph, r4
      0019C2 8D F0            [24] 5307 	mov	b, r5
      0019C4 EE               [12] 5308 	mov	a, r6
      0019C5 12 40 4C         [24] 5309 	lcall	___fsmul
      0019C8 AC 82            [24] 5310 	mov	r4, dpl
      0019CA AD 83            [24] 5311 	mov	r5, dph
      0019CC AE F0            [24] 5312 	mov	r6, b
      0019CE FF               [12] 5313 	mov	r7, a
      0019CF E5 81            [12] 5314 	mov	a,sp
      0019D1 24 FC            [12] 5315 	add	a,#0xfc
      0019D3 F5 81            [12] 5316 	mov	sp,a
      0019D5 8C 82            [24] 5317 	mov	dpl, r4
      0019D7 8D 83            [24] 5318 	mov	dph, r5
      0019D9 8E F0            [24] 5319 	mov	b, r6
      0019DB EF               [12] 5320 	mov	a, r7
                           00191F  5321 	C$fuzzy.h$2194$2_0$97 ==.
                                   5322 ;	../../fuzzy.h:2194: default:
      0019DC 80 06            [24] 5323 	sjmp	00105$
      0019DE                       5324 00103$:
                           001921  5325 	C$fuzzy.h$2195$2_0$97 ==.
                                   5326 ;	../../fuzzy.h:2195: return LEVEL_LO;
      0019DE 90 00 00         [24] 5327 	mov	dptr,#0x0000
      0019E1 E4               [12] 5328 	clr	a
      0019E2 F5 F0            [12] 5329 	mov	b,a
                           001927  5330 	C$fuzzy.h$2196$1_0$96 ==.
                                   5331 ;	../../fuzzy.h:2196: }
      0019E4                       5332 00105$:
                           001927  5333 	C$fuzzy.h$2197$1_0$96 ==.
                                   5334 ;	../../fuzzy.h:2197: }
      0019E4 85 08 81         [24] 5335 	mov	sp,_bp
      0019E7 D0 08            [24] 5336 	pop	_bp
                           00192C  5337 	C$fuzzy.h$2197$1_0$96 ==.
                           00192C  5338 	XFsugeno_demo$fuzzy_implication$0$0 ==.
      0019E9 22               [24] 5339 	ret
                                   5340 ;------------------------------------------------------------
                                   5341 ;Allocation info for local variables in function 'fuzzy_aggregation'
                                   5342 ;------------------------------------------------------------
                                   5343 ;aggregated    Allocated to stack - _bp -6 +4 
                                   5344 ;implied       Allocated to stack - _bp -10 +4 
                                   5345 ;method        Allocated to registers r7 
                                   5346 ;sloc0         Allocated to stack - _bp +1 +4 
                                   5347 ;sloc1         Allocated to stack - _bp +5 +4 
                                   5348 ;sloc2         Allocated to stack - _bp +10 +4 
                                   5349 ;------------------------------------------------------------
                           00192D  5350 	Fsugeno_demo$fuzzy_aggregation$0$0 ==.
                           00192D  5351 	C$fuzzy.h$2199$1_0$99 ==.
                                   5352 ;	../../fuzzy.h:2199: static float fuzzy_aggregation(
                                   5353 ;	-----------------------------------------
                                   5354 ;	 function fuzzy_aggregation
                                   5355 ;	-----------------------------------------
      0019EA                       5356 _fuzzy_aggregation:
      0019EA C0 08            [24] 5357 	push	_bp
      0019EC E5 81            [12] 5358 	mov	a,sp
      0019EE F5 08            [12] 5359 	mov	_bp,a
      0019F0 24 08            [12] 5360 	add	a,#0x08
      0019F2 F5 81            [12] 5361 	mov	sp,a
      0019F4 AF 82            [24] 5362 	mov	r7, dpl
                           001939  5363 	C$fuzzy.h$2205$1_0$99 ==.
                                   5364 ;	../../fuzzy.h:2205: aggregated = fuzzy_clamp(aggregated);
      0019F6 E5 08            [12] 5365 	mov	a,_bp
      0019F8 24 FA            [12] 5366 	add	a,#0xfa
      0019FA F8               [12] 5367 	mov	r0,a
      0019FB 86 82            [24] 5368 	mov	dpl, @r0
      0019FD 08               [12] 5369 	inc	r0
      0019FE 86 83            [24] 5370 	mov	dph, @r0
      001A00 08               [12] 5371 	inc	r0
      001A01 86 F0            [24] 5372 	mov	b, @r0
      001A03 08               [12] 5373 	inc	r0
      001A04 E6               [12] 5374 	mov	a, @r0
      001A05 C0 07            [24] 5375 	push	ar7
      001A07 12 00 F0         [24] 5376 	lcall	_fuzzy_clamp
      001A0A AE 82            [24] 5377 	mov	r6, dpl
      001A0C AD 83            [24] 5378 	mov	r5, dph
      001A0E AC F0            [24] 5379 	mov	r4, b
      001A10 FB               [12] 5380 	mov	r3, a
                           001954  5381 	C$fuzzy.h$2206$1_0$99 ==.
                                   5382 ;	../../fuzzy.h:2206: implied = fuzzy_clamp(implied);
      001A11 E5 08            [12] 5383 	mov	a,_bp
      001A13 24 F6            [12] 5384 	add	a,#0xf6
      001A15 F8               [12] 5385 	mov	r0,a
      001A16 86 82            [24] 5386 	mov	dpl, @r0
      001A18 08               [12] 5387 	inc	r0
      001A19 86 83            [24] 5388 	mov	dph, @r0
      001A1B 08               [12] 5389 	inc	r0
      001A1C 86 F0            [24] 5390 	mov	b, @r0
      001A1E 08               [12] 5391 	inc	r0
      001A1F E6               [12] 5392 	mov	a, @r0
      001A20 C0 06            [24] 5393 	push	ar6
      001A22 C0 05            [24] 5394 	push	ar5
      001A24 C0 04            [24] 5395 	push	ar4
      001A26 C0 03            [24] 5396 	push	ar3
      001A28 12 00 F0         [24] 5397 	lcall	_fuzzy_clamp
      001A2B A8 08            [24] 5398 	mov	r0,_bp
      001A2D 08               [12] 5399 	inc	r0
      001A2E A6 82            [24] 5400 	mov	@r0, dpl
      001A30 08               [12] 5401 	inc	r0
      001A31 A6 83            [24] 5402 	mov	@r0, dph
      001A33 08               [12] 5403 	inc	r0
      001A34 A6 F0            [24] 5404 	mov	@r0, b
      001A36 08               [12] 5405 	inc	r0
      001A37 F6               [12] 5406 	mov	@r0,a
      001A38 D0 03            [24] 5407 	pop	ar3
      001A3A D0 04            [24] 5408 	pop	ar4
      001A3C D0 05            [24] 5409 	pop	ar5
      001A3E D0 06            [24] 5410 	pop	ar6
      001A40 D0 07            [24] 5411 	pop	ar7
                           001985  5412 	C$fuzzy.h$2208$1_0$99 ==.
                                   5413 ;	../../fuzzy.h:2208: switch (method) {
      001A42 BF 00 02         [24] 5414 	cjne	r7,#0x00,00134$
      001A45 80 0E            [24] 5415 	sjmp	00101$
      001A47                       5416 00134$:
      001A47 BF 01 02         [24] 5417 	cjne	r7,#0x01,00135$
      001A4A 80 76            [24] 5418 	sjmp	00102$
      001A4C                       5419 00135$:
      001A4C BF 02 03         [24] 5420 	cjne	r7,#0x02,00136$
      001A4F 02 1B 5D         [24] 5421 	ljmp	00103$
      001A52                       5422 00136$:
      001A52 02 1B 92         [24] 5423 	ljmp	00104$
                           001998  5424 	C$fuzzy.h$2209$2_0$100 ==.
                                   5425 ;	../../fuzzy.h:2209: case FUZZY_AGGREGATION_MAX:
      001A55                       5426 00101$:
                           001998  5427 	C$fuzzy.h$2211$1_0$99 ==.
                                   5428 ;	../../fuzzy.h:2211: ? aggregated
      001A55 C0 06            [24] 5429 	push	ar6
      001A57 C0 05            [24] 5430 	push	ar5
      001A59 C0 04            [24] 5431 	push	ar4
      001A5B C0 03            [24] 5432 	push	ar3
      001A5D C0 06            [24] 5433 	push	ar6
      001A5F C0 05            [24] 5434 	push	ar5
      001A61 C0 04            [24] 5435 	push	ar4
      001A63 C0 03            [24] 5436 	push	ar3
      001A65 A8 08            [24] 5437 	mov	r0,_bp
      001A67 08               [12] 5438 	inc	r0
      001A68 86 82            [24] 5439 	mov	dpl, @r0
      001A6A 08               [12] 5440 	inc	r0
      001A6B 86 83            [24] 5441 	mov	dph, @r0
      001A6D 08               [12] 5442 	inc	r0
      001A6E 86 F0            [24] 5443 	mov	b, @r0
      001A70 08               [12] 5444 	inc	r0
      001A71 E6               [12] 5445 	mov	a, @r0
      001A72 12 41 7C         [24] 5446 	lcall	___fslt
      001A75 AF 82            [24] 5447 	mov	r7, dpl
      001A77 E5 81            [12] 5448 	mov	a,sp
      001A79 24 FC            [12] 5449 	add	a,#0xfc
      001A7B F5 81            [12] 5450 	mov	sp,a
      001A7D D0 03            [24] 5451 	pop	ar3
      001A7F D0 04            [24] 5452 	pop	ar4
      001A81 D0 05            [24] 5453 	pop	ar5
      001A83 D0 06            [24] 5454 	pop	ar6
      001A85 EF               [12] 5455 	mov	a,r7
      001A86 60 12            [24] 5456 	jz	00108$
      001A88 E5 08            [12] 5457 	mov	a,_bp
      001A8A 24 05            [12] 5458 	add	a,#0x05
      001A8C F8               [12] 5459 	mov	r0,a
      001A8D A6 06            [24] 5460 	mov	@r0,ar6
      001A8F 08               [12] 5461 	inc	r0
      001A90 A6 05            [24] 5462 	mov	@r0,ar5
      001A92 08               [12] 5463 	inc	r0
      001A93 A6 04            [24] 5464 	mov	@r0,ar4
      001A95 08               [12] 5465 	inc	r0
      001A96 A6 03            [24] 5466 	mov	@r0,ar3
      001A98 80 16            [24] 5467 	sjmp	00109$
      001A9A                       5468 00108$:
                           0019DD  5469 	C$fuzzy.h$2212$2_0$100 ==.
                                   5470 ;	../../fuzzy.h:2212: : implied;
      001A9A A8 08            [24] 5471 	mov	r0,_bp
      001A9C 08               [12] 5472 	inc	r0
      001A9D E5 08            [12] 5473 	mov	a,_bp
      001A9F 24 05            [12] 5474 	add	a,#0x05
      001AA1 F9               [12] 5475 	mov	r1,a
      001AA2 E6               [12] 5476 	mov	a,@r0
      001AA3 F7               [12] 5477 	mov	@r1,a
      001AA4 08               [12] 5478 	inc	r0
      001AA5 E6               [12] 5479 	mov	a,@r0
      001AA6 09               [12] 5480 	inc	r1
      001AA7 F7               [12] 5481 	mov	@r1,a
      001AA8 08               [12] 5482 	inc	r0
      001AA9 E6               [12] 5483 	mov	a,@r0
      001AAA 09               [12] 5484 	inc	r1
      001AAB F7               [12] 5485 	mov	@r1,a
      001AAC 08               [12] 5486 	inc	r0
      001AAD E6               [12] 5487 	mov	a,@r0
      001AAE 09               [12] 5488 	inc	r1
      001AAF F7               [12] 5489 	mov	@r1,a
      001AB0                       5490 00109$:
      001AB0 E5 08            [12] 5491 	mov	a,_bp
      001AB2 24 05            [12] 5492 	add	a,#0x05
      001AB4 F8               [12] 5493 	mov	r0,a
      001AB5 86 82            [24] 5494 	mov	dpl, @r0
      001AB7 08               [12] 5495 	inc	r0
      001AB8 86 83            [24] 5496 	mov	dph, @r0
      001ABA 08               [12] 5497 	inc	r0
      001ABB 86 F0            [24] 5498 	mov	b, @r0
      001ABD 08               [12] 5499 	inc	r0
      001ABE E6               [12] 5500 	mov	a, @r0
      001ABF 02 1B 98         [24] 5501 	ljmp	00106$
                           001A05  5502 	C$fuzzy.h$2214$2_0$100 ==.
                                   5503 ;	../../fuzzy.h:2214: case FUZZY_AGGREGATION_ALGEBRAIC:
      001AC2                       5504 00102$:
                           001A05  5505 	C$fuzzy.h$2216$1_0$99 ==.
                                   5506 ;	../../fuzzy.h:2216: implied -
      001AC2 C0 06            [24] 5507 	push	ar6
      001AC4 C0 05            [24] 5508 	push	ar5
      001AC6 C0 04            [24] 5509 	push	ar4
      001AC8 C0 03            [24] 5510 	push	ar3
      001ACA A8 08            [24] 5511 	mov	r0,_bp
      001ACC 08               [12] 5512 	inc	r0
      001ACD E6               [12] 5513 	mov	a,@r0
      001ACE C0 E0            [24] 5514 	push	acc
      001AD0 08               [12] 5515 	inc	r0
      001AD1 E6               [12] 5516 	mov	a,@r0
      001AD2 C0 E0            [24] 5517 	push	acc
      001AD4 08               [12] 5518 	inc	r0
      001AD5 E6               [12] 5519 	mov	a,@r0
      001AD6 C0 E0            [24] 5520 	push	acc
      001AD8 08               [12] 5521 	inc	r0
      001AD9 E6               [12] 5522 	mov	a,@r0
      001ADA C0 E0            [24] 5523 	push	acc
                           001A1F  5524 	C$fuzzy.h$2217$1_0$99 ==.
                                   5525 ;	../../fuzzy.h:2217: aggregated * implied;
      001ADC 8E 82            [24] 5526 	mov	dpl, r6
      001ADE 8D 83            [24] 5527 	mov	dph, r5
      001AE0 8C F0            [24] 5528 	mov	b, r4
      001AE2 EB               [12] 5529 	mov	a, r3
      001AE3 12 41 CE         [24] 5530 	lcall	___fsadd
      001AE6 C8               [12] 5531 	xch	a,r0
      001AE7 E5 08            [12] 5532 	mov	a,_bp
      001AE9 24 05            [12] 5533 	add	a,#0x05
      001AEB C8               [12] 5534 	xch	a,r0
      001AEC A6 82            [24] 5535 	mov	@r0, dpl
      001AEE 08               [12] 5536 	inc	r0
      001AEF A6 83            [24] 5537 	mov	@r0, dph
      001AF1 08               [12] 5538 	inc	r0
      001AF2 A6 F0            [24] 5539 	mov	@r0, b
      001AF4 08               [12] 5540 	inc	r0
      001AF5 F6               [12] 5541 	mov	@r0,a
      001AF6 E5 81            [12] 5542 	mov	a,sp
      001AF8 24 FC            [12] 5543 	add	a,#0xfc
      001AFA F5 81            [12] 5544 	mov	sp,a
      001AFC D0 03            [24] 5545 	pop	ar3
      001AFE D0 04            [24] 5546 	pop	ar4
      001B00 D0 05            [24] 5547 	pop	ar5
      001B02 D0 06            [24] 5548 	pop	ar6
      001B04 A8 08            [24] 5549 	mov	r0,_bp
      001B06 08               [12] 5550 	inc	r0
      001B07 E6               [12] 5551 	mov	a,@r0
      001B08 C0 E0            [24] 5552 	push	acc
      001B0A 08               [12] 5553 	inc	r0
      001B0B E6               [12] 5554 	mov	a,@r0
      001B0C C0 E0            [24] 5555 	push	acc
      001B0E 08               [12] 5556 	inc	r0
      001B0F E6               [12] 5557 	mov	a,@r0
      001B10 C0 E0            [24] 5558 	push	acc
      001B12 08               [12] 5559 	inc	r0
      001B13 E6               [12] 5560 	mov	a,@r0
      001B14 C0 E0            [24] 5561 	push	acc
      001B16 8E 82            [24] 5562 	mov	dpl, r6
      001B18 8D 83            [24] 5563 	mov	dph, r5
      001B1A 8C F0            [24] 5564 	mov	b, r4
      001B1C EB               [12] 5565 	mov	a, r3
      001B1D 12 40 4C         [24] 5566 	lcall	___fsmul
      001B20 AB 82            [24] 5567 	mov	r3, dpl
      001B22 AC 83            [24] 5568 	mov	r4, dph
      001B24 AE F0            [24] 5569 	mov	r6, b
      001B26 FF               [12] 5570 	mov	r7, a
      001B27 E5 81            [12] 5571 	mov	a,sp
      001B29 24 FC            [12] 5572 	add	a,#0xfc
      001B2B F5 81            [12] 5573 	mov	sp,a
      001B2D C0 03            [24] 5574 	push	ar3
      001B2F C0 04            [24] 5575 	push	ar4
      001B31 C0 06            [24] 5576 	push	ar6
      001B33 C0 07            [24] 5577 	push	ar7
      001B35 E5 08            [12] 5578 	mov	a,_bp
      001B37 24 05            [12] 5579 	add	a,#0x05
      001B39 F8               [12] 5580 	mov	r0,a
      001B3A 86 82            [24] 5581 	mov	dpl, @r0
      001B3C 08               [12] 5582 	inc	r0
      001B3D 86 83            [24] 5583 	mov	dph, @r0
      001B3F 08               [12] 5584 	inc	r0
      001B40 86 F0            [24] 5585 	mov	b, @r0
      001B42 08               [12] 5586 	inc	r0
      001B43 E6               [12] 5587 	mov	a, @r0
      001B44 12 40 41         [24] 5588 	lcall	___fssub
      001B47 AC 82            [24] 5589 	mov	r4, dpl
      001B49 AD 83            [24] 5590 	mov	r5, dph
      001B4B AE F0            [24] 5591 	mov	r6, b
      001B4D FF               [12] 5592 	mov	r7, a
      001B4E E5 81            [12] 5593 	mov	a,sp
      001B50 24 FC            [12] 5594 	add	a,#0xfc
      001B52 F5 81            [12] 5595 	mov	sp,a
      001B54 8C 82            [24] 5596 	mov	dpl, r4
      001B56 8D 83            [24] 5597 	mov	dph, r5
      001B58 8E F0            [24] 5598 	mov	b, r6
      001B5A EF               [12] 5599 	mov	a, r7
                           001A9E  5600 	C$fuzzy.h$2219$2_0$100 ==.
                                   5601 ;	../../fuzzy.h:2219: case FUZZY_AGGREGATION_BOUNDED:
      001B5B 80 3B            [24] 5602 	sjmp	00106$
      001B5D                       5603 00103$:
                           001AA0  5604 	C$fuzzy.h$2223$1_0$99 ==.
                                   5605 ;	../../fuzzy.h:2223: );
      001B5D A8 08            [24] 5606 	mov	r0,_bp
      001B5F 08               [12] 5607 	inc	r0
      001B60 E6               [12] 5608 	mov	a,@r0
      001B61 C0 E0            [24] 5609 	push	acc
      001B63 08               [12] 5610 	inc	r0
      001B64 E6               [12] 5611 	mov	a,@r0
      001B65 C0 E0            [24] 5612 	push	acc
      001B67 08               [12] 5613 	inc	r0
      001B68 E6               [12] 5614 	mov	a,@r0
      001B69 C0 E0            [24] 5615 	push	acc
      001B6B 08               [12] 5616 	inc	r0
      001B6C E6               [12] 5617 	mov	a,@r0
      001B6D C0 E0            [24] 5618 	push	acc
      001B6F 8E 82            [24] 5619 	mov	dpl, r6
      001B71 8D 83            [24] 5620 	mov	dph, r5
      001B73 8C F0            [24] 5621 	mov	b, r4
      001B75 EB               [12] 5622 	mov	a, r3
      001B76 12 41 CE         [24] 5623 	lcall	___fsadd
      001B79 AC 82            [24] 5624 	mov	r4, dpl
      001B7B AD 83            [24] 5625 	mov	r5, dph
      001B7D AE F0            [24] 5626 	mov	r6, b
      001B7F FF               [12] 5627 	mov	r7, a
      001B80 E5 81            [12] 5628 	mov	a,sp
      001B82 24 FC            [12] 5629 	add	a,#0xfc
      001B84 F5 81            [12] 5630 	mov	sp,a
      001B86 8C 82            [24] 5631 	mov	dpl, r4
      001B88 8D 83            [24] 5632 	mov	dph, r5
      001B8A 8E F0            [24] 5633 	mov	b, r6
      001B8C EF               [12] 5634 	mov	a, r7
      001B8D 12 00 F0         [24] 5635 	lcall	_fuzzy_clamp
                           001AD3  5636 	C$fuzzy.h$2225$2_0$100 ==.
                                   5637 ;	../../fuzzy.h:2225: default:
      001B90 80 06            [24] 5638 	sjmp	00106$
      001B92                       5639 00104$:
                           001AD5  5640 	C$fuzzy.h$2226$2_0$100 ==.
                                   5641 ;	../../fuzzy.h:2226: return LEVEL_LO;
      001B92 90 00 00         [24] 5642 	mov	dptr,#0x0000
      001B95 E4               [12] 5643 	clr	a
      001B96 F5 F0            [12] 5644 	mov	b,a
                           001ADB  5645 	C$fuzzy.h$2227$1_0$99 ==.
                                   5646 ;	../../fuzzy.h:2227: }
      001B98                       5647 00106$:
                           001ADB  5648 	C$fuzzy.h$2228$1_0$99 ==.
                                   5649 ;	../../fuzzy.h:2228: }
      001B98 85 08 81         [24] 5650 	mov	sp,_bp
      001B9B D0 08            [24] 5651 	pop	_bp
                           001AE0  5652 	C$fuzzy.h$2228$1_0$99 ==.
                           001AE0  5653 	XFsugeno_demo$fuzzy_aggregation$0$0 ==.
      001B9D 22               [24] 5654 	ret
                                   5655 ;------------------------------------------------------------
                                   5656 ;Allocation info for local variables in function 'fuzzy_rules_aggregated_height'
                                   5657 ;------------------------------------------------------------
                                   5658 ;value         Allocated to stack - _bp -6 +4 
                                   5659 ;implication_method Allocated to stack - _bp -7 +1 
                                   5660 ;aggregation_method Allocated to stack - _bp -8 +1 
                                   5661 ;rules         Allocated to stack - _bp +1 +3 
                                   5662 ;aggregated_height Allocated to stack - _bp +12 +4 
                                   5663 ;output_membership Allocated to stack - _bp +16 +4 
                                   5664 ;implied_height Allocated to registers r4 r5 r6 r7 
                                   5665 ;index         Allocated to stack - _bp +20 +2 
                                   5666 ;sloc0         Allocated to stack - _bp +4 +3 
                                   5667 ;sloc1         Allocated to stack - _bp +7 +2 
                                   5668 ;sloc2         Allocated to stack - _bp +9 +3 
                                   5669 ;------------------------------------------------------------
                           001AE1  5670 	Fsugeno_demo$fuzzy_rules_aggregated_height$0$0 ==.
                           001AE1  5671 	C$fuzzy.h$2234$1_0$102 ==.
                                   5672 ;	../../fuzzy.h:2234: static float fuzzy_rules_aggregated_height(
                                   5673 ;	-----------------------------------------
                                   5674 ;	 function fuzzy_rules_aggregated_height
                                   5675 ;	-----------------------------------------
      001B9E                       5676 _fuzzy_rules_aggregated_height:
      001B9E C0 08            [24] 5677 	push	_bp
      001BA0 85 81 08         [24] 5678 	mov	_bp,sp
      001BA3 C0 82            [24] 5679 	push	dpl
      001BA5 C0 83            [24] 5680 	push	dph
      001BA7 C0 F0            [24] 5681 	push	b
      001BA9 E5 81            [12] 5682 	mov	a,sp
      001BAB 24 12            [12] 5683 	add	a,#0x12
      001BAD F5 81            [12] 5684 	mov	sp,a
                           001AF2  5685 	C$fuzzy.h$2247$1_0$102 ==.
                                   5686 ;	../../fuzzy.h:2247: LEVEL_LO;
      001BAF E5 08            [12] 5687 	mov	a,_bp
      001BB1 24 0C            [12] 5688 	add	a,#0x0c
      001BB3 F8               [12] 5689 	mov	r0,a
      001BB4 E4               [12] 5690 	clr	a
      001BB5 F6               [12] 5691 	mov	@r0,a
      001BB6 08               [12] 5692 	inc	r0
      001BB7 F6               [12] 5693 	mov	@r0,a
      001BB8 08               [12] 5694 	inc	r0
      001BB9 F6               [12] 5695 	mov	@r0,a
      001BBA 08               [12] 5696 	inc	r0
      001BBB F6               [12] 5697 	mov	@r0,a
                           001AFF  5698 	C$fuzzy.h$2250$3_0$104 ==.
                                   5699 ;	../../fuzzy.h:2250: index = 0u;
      001BBC A8 08            [24] 5700 	mov	r0,_bp
      001BBE 08               [12] 5701 	inc	r0
      001BBF E5 08            [12] 5702 	mov	a,_bp
      001BC1 24 09            [12] 5703 	add	a,#0x09
      001BC3 F9               [12] 5704 	mov	r1,a
      001BC4 E6               [12] 5705 	mov	a,@r0
      001BC5 F7               [12] 5706 	mov	@r1,a
      001BC6 08               [12] 5707 	inc	r0
      001BC7 E6               [12] 5708 	mov	a,@r0
      001BC8 09               [12] 5709 	inc	r1
      001BC9 F7               [12] 5710 	mov	@r1,a
      001BCA 08               [12] 5711 	inc	r0
      001BCB E6               [12] 5712 	mov	a,@r0
      001BCC 09               [12] 5713 	inc	r1
      001BCD F7               [12] 5714 	mov	@r1,a
      001BCE A8 08            [24] 5715 	mov	r0,_bp
      001BD0 08               [12] 5716 	inc	r0
      001BD1 E5 08            [12] 5717 	mov	a,_bp
      001BD3 24 04            [12] 5718 	add	a,#0x04
      001BD5 F9               [12] 5719 	mov	r1,a
      001BD6 74 90            [12] 5720 	mov	a,#0x90
      001BD8 26               [12] 5721 	add	a, @r0
      001BD9 F7               [12] 5722 	mov	@r1,a
      001BDA E4               [12] 5723 	clr	a
      001BDB 08               [12] 5724 	inc	r0
      001BDC 36               [12] 5725 	addc	a, @r0
      001BDD 09               [12] 5726 	inc	r1
      001BDE F7               [12] 5727 	mov	@r1,a
      001BDF 08               [12] 5728 	inc	r0
      001BE0 E6               [12] 5729 	mov	a,@r0
      001BE1 09               [12] 5730 	inc	r1
      001BE2 F7               [12] 5731 	mov	@r1,a
      001BE3 E5 08            [12] 5732 	mov	a,_bp
      001BE5 24 14            [12] 5733 	add	a,#0x14
      001BE7 F8               [12] 5734 	mov	r0,a
      001BE8 E4               [12] 5735 	clr	a
      001BE9 F6               [12] 5736 	mov	@r0,a
      001BEA 08               [12] 5737 	inc	r0
      001BEB F6               [12] 5738 	mov	@r0,a
      001BEC E5 08            [12] 5739 	mov	a,_bp
      001BEE 24 07            [12] 5740 	add	a,#0x07
      001BF0 F8               [12] 5741 	mov	r0,a
      001BF1 E4               [12] 5742 	clr	a
      001BF2 F6               [12] 5743 	mov	@r0,a
      001BF3 08               [12] 5744 	inc	r0
      001BF4 F6               [12] 5745 	mov	@r0,a
      001BF5                       5746 00103$:
                           001B38  5747 	C$fuzzy.h$2251$1_0$102 ==.
                                   5748 ;	../../fuzzy.h:2251: index < rules->count;
      001BF5 E5 08            [12] 5749 	mov	a,_bp
      001BF7 24 04            [12] 5750 	add	a,#0x04
      001BF9 F8               [12] 5751 	mov	r0,a
      001BFA 86 82            [24] 5752 	mov	dpl,@r0
      001BFC 08               [12] 5753 	inc	r0
      001BFD 86 83            [24] 5754 	mov	dph,@r0
      001BFF 08               [12] 5755 	inc	r0
      001C00 86 F0            [24] 5756 	mov	b,@r0
      001C02 12 43 A8         [24] 5757 	lcall	__gptrget
      001C05 FC               [12] 5758 	mov	r4,a
      001C06 A3               [24] 5759 	inc	dptr
      001C07 12 43 A8         [24] 5760 	lcall	__gptrget
      001C0A FD               [12] 5761 	mov	r5,a
      001C0B E5 08            [12] 5762 	mov	a,_bp
      001C0D 24 14            [12] 5763 	add	a,#0x14
      001C0F F8               [12] 5764 	mov	r0,a
      001C10 C3               [12] 5765 	clr	c
      001C11 E6               [12] 5766 	mov	a,@r0
      001C12 9C               [12] 5767 	subb	a,r4
      001C13 08               [12] 5768 	inc	r0
      001C14 E6               [12] 5769 	mov	a,@r0
      001C15 9D               [12] 5770 	subb	a,r5
      001C16 40 03            [24] 5771 	jc	00120$
      001C18 02 1D 2F         [24] 5772 	ljmp	00101$
      001C1B                       5773 00120$:
                           001B5E  5774 	C$fuzzy.h$2256$3_0$104 ==.
                                   5775 ;	../../fuzzy.h:2256: rules->rules[index]
      001C1B E5 08            [12] 5776 	mov	a,_bp
      001C1D 24 09            [12] 5777 	add	a,#0x09
      001C1F F8               [12] 5778 	mov	r0,a
      001C20 E5 08            [12] 5779 	mov	a,_bp
      001C22 24 07            [12] 5780 	add	a,#0x07
      001C24 F9               [12] 5781 	mov	r1,a
      001C25 E7               [12] 5782 	mov	a,@r1
      001C26 26               [12] 5783 	add	a, @r0
      001C27 FD               [12] 5784 	mov	r5,a
      001C28 09               [12] 5785 	inc	r1
      001C29 E7               [12] 5786 	mov	a,@r1
      001C2A 08               [12] 5787 	inc	r0
      001C2B 36               [12] 5788 	addc	a, @r0
      001C2C FE               [12] 5789 	mov	r6,a
      001C2D 08               [12] 5790 	inc	r0
      001C2E 86 07            [24] 5791 	mov	ar7,@r0
      001C30 74 07            [12] 5792 	mov	a,#0x07
      001C32 2D               [12] 5793 	add	a, r5
      001C33 FD               [12] 5794 	mov	r5,a
      001C34 E4               [12] 5795 	clr	a
      001C35 3E               [12] 5796 	addc	a, r6
      001C36 FE               [12] 5797 	mov	r6,a
      001C37 8D 82            [24] 5798 	mov	dpl,r5
      001C39 8E 83            [24] 5799 	mov	dph,r6
      001C3B 8F F0            [24] 5800 	mov	b,r7
      001C3D 12 43 A8         [24] 5801 	lcall	__gptrget
      001C40 FD               [12] 5802 	mov	r5,a
      001C41 A3               [24] 5803 	inc	dptr
      001C42 12 43 A8         [24] 5804 	lcall	__gptrget
      001C45 FE               [12] 5805 	mov	r6,a
                           001B89  5806 	C$fuzzy.h$2257$3_0$104 ==.
                                   5807 ;	../../fuzzy.h:2257: .output_function(value)
      001C46 12 1C 4B         [24] 5808 	lcall	00121$
      001C49 80 14            [24] 5809 	sjmp	00122$
      001C4B                       5810 00121$:
      001C4B C0 05            [24] 5811 	push	ar5
      001C4D C0 06            [24] 5812 	push	ar6
      001C4F E5 08            [12] 5813 	mov	a,_bp
      001C51 24 FA            [12] 5814 	add	a,#0xfa
      001C53 F8               [12] 5815 	mov	r0,a
      001C54 86 82            [24] 5816 	mov	dpl, @r0
      001C56 08               [12] 5817 	inc	r0
      001C57 86 83            [24] 5818 	mov	dph, @r0
      001C59 08               [12] 5819 	inc	r0
      001C5A 86 F0            [24] 5820 	mov	b, @r0
      001C5C 08               [12] 5821 	inc	r0
      001C5D E6               [12] 5822 	mov	a, @r0
      001C5E 22               [24] 5823 	ret
      001C5F                       5824 00122$:
      001C5F 12 00 F0         [24] 5825 	lcall	_fuzzy_clamp
      001C62 C8               [12] 5826 	xch	a,r0
      001C63 E5 08            [12] 5827 	mov	a,_bp
      001C65 24 10            [12] 5828 	add	a,#0x10
      001C67 C8               [12] 5829 	xch	a,r0
      001C68 A6 82            [24] 5830 	mov	@r0, dpl
      001C6A 08               [12] 5831 	inc	r0
      001C6B A6 83            [24] 5832 	mov	@r0, dph
      001C6D 08               [12] 5833 	inc	r0
      001C6E A6 F0            [24] 5834 	mov	@r0, b
      001C70 08               [12] 5835 	inc	r0
      001C71 F6               [12] 5836 	mov	@r0,a
                           001BB5  5837 	C$fuzzy.h$2263$3_0$104 ==.
                                   5838 ;	../../fuzzy.h:2263: rules->rules[index].value,
      001C72 A8 08            [24] 5839 	mov	r0,_bp
      001C74 08               [12] 5840 	inc	r0
      001C75 E5 08            [12] 5841 	mov	a,_bp
      001C77 24 07            [12] 5842 	add	a,#0x07
      001C79 F9               [12] 5843 	mov	r1,a
      001C7A E7               [12] 5844 	mov	a,@r1
      001C7B 26               [12] 5845 	add	a, @r0
      001C7C FA               [12] 5846 	mov	r2,a
      001C7D 09               [12] 5847 	inc	r1
      001C7E E7               [12] 5848 	mov	a,@r1
      001C7F 08               [12] 5849 	inc	r0
      001C80 36               [12] 5850 	addc	a, @r0
      001C81 FB               [12] 5851 	mov	r3,a
      001C82 08               [12] 5852 	inc	r0
      001C83 86 07            [24] 5853 	mov	ar7,@r0
      001C85 74 03            [12] 5854 	mov	a,#0x03
      001C87 2A               [12] 5855 	add	a, r2
      001C88 FA               [12] 5856 	mov	r2,a
      001C89 E4               [12] 5857 	clr	a
      001C8A 3B               [12] 5858 	addc	a, r3
      001C8B FB               [12] 5859 	mov	r3,a
      001C8C 8A 82            [24] 5860 	mov	dpl,r2
      001C8E 8B 83            [24] 5861 	mov	dph,r3
      001C90 8F F0            [24] 5862 	mov	b,r7
      001C92 12 43 A8         [24] 5863 	lcall	__gptrget
      001C95 FA               [12] 5864 	mov	r2,a
      001C96 A3               [24] 5865 	inc	dptr
      001C97 12 43 A8         [24] 5866 	lcall	__gptrget
      001C9A FB               [12] 5867 	mov	r3,a
      001C9B A3               [24] 5868 	inc	dptr
      001C9C 12 43 A8         [24] 5869 	lcall	__gptrget
      001C9F FF               [12] 5870 	mov	r7,a
      001CA0 A3               [24] 5871 	inc	dptr
      001CA1 12 43 A8         [24] 5872 	lcall	__gptrget
      001CA4 FE               [12] 5873 	mov	r6,a
                           001BE8  5874 	C$fuzzy.h$2262$3_0$104 ==.
                                   5875 ;	../../fuzzy.h:2262: implication_method,
      001CA5 E5 08            [12] 5876 	mov	a,_bp
      001CA7 24 10            [12] 5877 	add	a,#0x10
      001CA9 F8               [12] 5878 	mov	r0,a
      001CAA E6               [12] 5879 	mov	a,@r0
      001CAB C0 E0            [24] 5880 	push	acc
      001CAD 08               [12] 5881 	inc	r0
      001CAE E6               [12] 5882 	mov	a,@r0
      001CAF C0 E0            [24] 5883 	push	acc
      001CB1 08               [12] 5884 	inc	r0
      001CB2 E6               [12] 5885 	mov	a,@r0
      001CB3 C0 E0            [24] 5886 	push	acc
      001CB5 08               [12] 5887 	inc	r0
      001CB6 E6               [12] 5888 	mov	a,@r0
      001CB7 C0 E0            [24] 5889 	push	acc
      001CB9 C0 02            [24] 5890 	push	ar2
      001CBB C0 03            [24] 5891 	push	ar3
      001CBD C0 07            [24] 5892 	push	ar7
      001CBF C0 06            [24] 5893 	push	ar6
      001CC1 E5 08            [12] 5894 	mov	a,_bp
      001CC3 24 F9            [12] 5895 	add	a,#0xf9
      001CC5 F8               [12] 5896 	mov	r0,a
      001CC6 86 82            [24] 5897 	mov	dpl, @r0
      001CC8 12 18 D7         [24] 5898 	lcall	_fuzzy_implication
      001CCB AC 82            [24] 5899 	mov	r4, dpl
      001CCD AD 83            [24] 5900 	mov	r5, dph
      001CCF AE F0            [24] 5901 	mov	r6, b
      001CD1 FF               [12] 5902 	mov	r7, a
      001CD2 E5 81            [12] 5903 	mov	a,sp
      001CD4 24 F8            [12] 5904 	add	a,#0xf8
      001CD6 F5 81            [12] 5905 	mov	sp,a
                           001C1B  5906 	C$fuzzy.h$2269$3_0$104 ==.
                                   5907 ;	../../fuzzy.h:2269: aggregation_method,
      001CD8 C0 04            [24] 5908 	push	ar4
      001CDA C0 05            [24] 5909 	push	ar5
      001CDC C0 06            [24] 5910 	push	ar6
      001CDE C0 07            [24] 5911 	push	ar7
      001CE0 E5 08            [12] 5912 	mov	a,_bp
      001CE2 24 0C            [12] 5913 	add	a,#0x0c
      001CE4 F8               [12] 5914 	mov	r0,a
      001CE5 E6               [12] 5915 	mov	a,@r0
      001CE6 C0 E0            [24] 5916 	push	acc
      001CE8 08               [12] 5917 	inc	r0
      001CE9 E6               [12] 5918 	mov	a,@r0
      001CEA C0 E0            [24] 5919 	push	acc
      001CEC 08               [12] 5920 	inc	r0
      001CED E6               [12] 5921 	mov	a,@r0
      001CEE C0 E0            [24] 5922 	push	acc
      001CF0 08               [12] 5923 	inc	r0
      001CF1 E6               [12] 5924 	mov	a,@r0
      001CF2 C0 E0            [24] 5925 	push	acc
      001CF4 E5 08            [12] 5926 	mov	a,_bp
      001CF6 24 F8            [12] 5927 	add	a,#0xf8
      001CF8 F8               [12] 5928 	mov	r0,a
      001CF9 86 82            [24] 5929 	mov	dpl, @r0
      001CFB 12 19 EA         [24] 5930 	lcall	_fuzzy_aggregation
      001CFE C8               [12] 5931 	xch	a,r0
      001CFF E5 08            [12] 5932 	mov	a,_bp
      001D01 24 0C            [12] 5933 	add	a,#0x0c
      001D03 C8               [12] 5934 	xch	a,r0
      001D04 A6 82            [24] 5935 	mov	@r0, dpl
      001D06 08               [12] 5936 	inc	r0
      001D07 A6 83            [24] 5937 	mov	@r0, dph
      001D09 08               [12] 5938 	inc	r0
      001D0A A6 F0            [24] 5939 	mov	@r0, b
      001D0C 08               [12] 5940 	inc	r0
      001D0D F6               [12] 5941 	mov	@r0,a
      001D0E E5 81            [12] 5942 	mov	a,sp
      001D10 24 F8            [12] 5943 	add	a,#0xf8
      001D12 F5 81            [12] 5944 	mov	sp,a
                           001C57  5945 	C$fuzzy.h$2252$1_0$102 ==.
                                   5946 ;	../../fuzzy.h:2252: index++
      001D14 E5 08            [12] 5947 	mov	a,_bp
      001D16 24 07            [12] 5948 	add	a,#0x07
      001D18 F8               [12] 5949 	mov	r0,a
      001D19 74 09            [12] 5950 	mov	a,#0x09
      001D1B 26               [12] 5951 	add	a, @r0
      001D1C F6               [12] 5952 	mov	@r0,a
      001D1D E4               [12] 5953 	clr	a
      001D1E 08               [12] 5954 	inc	r0
      001D1F 36               [12] 5955 	addc	a, @r0
      001D20 F6               [12] 5956 	mov	@r0,a
      001D21 E5 08            [12] 5957 	mov	a,_bp
      001D23 24 14            [12] 5958 	add	a,#0x14
      001D25 F8               [12] 5959 	mov	r0,a
      001D26 06               [12] 5960 	inc	@r0
      001D27 B6 00 02         [24] 5961 	cjne	@r0,#0x00,00123$
      001D2A 08               [12] 5962 	inc	r0
      001D2B 06               [12] 5963 	inc	@r0
      001D2C                       5964 00123$:
      001D2C 02 1B F5         [24] 5965 	ljmp	00103$
      001D2F                       5966 00101$:
                           001C72  5967 	C$fuzzy.h$2276$1_0$102 ==.
                                   5968 ;	../../fuzzy.h:2276: aggregated_height
      001D2F E5 08            [12] 5969 	mov	a,_bp
      001D31 24 0C            [12] 5970 	add	a,#0x0c
      001D33 F8               [12] 5971 	mov	r0,a
      001D34 86 82            [24] 5972 	mov	dpl, @r0
      001D36 08               [12] 5973 	inc	r0
      001D37 86 83            [24] 5974 	mov	dph, @r0
      001D39 08               [12] 5975 	inc	r0
      001D3A 86 F0            [24] 5976 	mov	b, @r0
      001D3C 08               [12] 5977 	inc	r0
      001D3D E6               [12] 5978 	mov	a, @r0
      001D3E 12 00 F0         [24] 5979 	lcall	_fuzzy_clamp
                           001C84  5980 	C$fuzzy.h$2278$1_0$102 ==.
                                   5981 ;	../../fuzzy.h:2278: }
      001D41 85 08 81         [24] 5982 	mov	sp,_bp
      001D44 D0 08            [24] 5983 	pop	_bp
                           001C89  5984 	C$fuzzy.h$2278$1_0$102 ==.
                           001C89  5985 	XFsugeno_demo$fuzzy_rules_aggregated_height$0$0 ==.
      001D46 22               [24] 5986 	ret
                                   5987 ;------------------------------------------------------------
                                   5988 ;Allocation info for local variables in function 'fuzzy_rules_maximum_result'
                                   5989 ;------------------------------------------------------------
                                   5990 ;rules         Allocated to stack - _bp -5 +3 
                                   5991 ;lower         Allocated to stack - _bp -9 +4 
                                   5992 ;upper         Allocated to stack - _bp -13 +4 
                                   5993 ;step          Allocated to stack - _bp -17 +4 
                                   5994 ;implication_method Allocated to stack - _bp -18 +1 
                                   5995 ;aggregation_method Allocated to stack - _bp -19 +1 
                                   5996 ;result        Allocated to registers r5 r6 r7 
                                   5997 ;value         Allocated to stack - _bp +16 +4 
                                   5998 ;height        Allocated to stack - _bp +20 +4 
                                   5999 ;sloc0         Allocated to stack - _bp +1 +3 
                                   6000 ;sloc1         Allocated to stack - _bp +4 +3 
                                   6001 ;sloc2         Allocated to stack - _bp +7 +3 
                                   6002 ;sloc3         Allocated to stack - _bp +10 +3 
                                   6003 ;sloc4         Allocated to stack - _bp +13 +3 
                                   6004 ;------------------------------------------------------------
                           001C8A  6005 	Fsugeno_demo$fuzzy_rules_maximum_result$0$0 ==.
                           001C8A  6006 	C$fuzzy.h$2298$1_0$106 ==.
                                   6007 ;	../../fuzzy.h:2298: static void fuzzy_rules_maximum_result(
                                   6008 ;	-----------------------------------------
                                   6009 ;	 function fuzzy_rules_maximum_result
                                   6010 ;	-----------------------------------------
      001D47                       6011 _fuzzy_rules_maximum_result:
      001D47 C0 08            [24] 6012 	push	_bp
      001D49 E5 81            [12] 6013 	mov	a,sp
      001D4B F5 08            [12] 6014 	mov	_bp,a
      001D4D 24 17            [12] 6015 	add	a,#0x17
      001D4F F5 81            [12] 6016 	mov	sp,a
      001D51 AD 82            [24] 6017 	mov	r5, dpl
      001D53 AE 83            [24] 6018 	mov	r6, dph
      001D55 AF F0            [24] 6019 	mov	r7, b
                           001C9A  6020 	C$fuzzy.h$2311$1_0$106 ==.
                                   6021 ;	../../fuzzy.h:2311: result->height =
      001D57 E5 08            [12] 6022 	mov	a,_bp
      001D59 24 0A            [12] 6023 	add	a,#0x0a
      001D5B F8               [12] 6024 	mov	r0,a
      001D5C A6 05            [24] 6025 	mov	@r0,ar5
      001D5E 08               [12] 6026 	inc	r0
      001D5F A6 06            [24] 6027 	mov	@r0,ar6
      001D61 08               [12] 6028 	inc	r0
      001D62 A6 07            [24] 6029 	mov	@r0,ar7
      001D64 E5 08            [12] 6030 	mov	a,_bp
      001D66 24 0A            [12] 6031 	add	a,#0x0a
      001D68 F8               [12] 6032 	mov	r0,a
      001D69 86 82            [24] 6033 	mov	dpl,@r0
      001D6B 08               [12] 6034 	inc	r0
      001D6C 86 83            [24] 6035 	mov	dph,@r0
      001D6E 08               [12] 6036 	inc	r0
      001D6F 86 F0            [24] 6037 	mov	b,@r0
      001D71 E4               [12] 6038 	clr	a
      001D72 12 41 61         [24] 6039 	lcall	__gptrput
      001D75 A3               [24] 6040 	inc	dptr
      001D76 12 41 61         [24] 6041 	lcall	__gptrput
      001D79 A3               [24] 6042 	inc	dptr
      001D7A 12 41 61         [24] 6043 	lcall	__gptrput
      001D7D A3               [24] 6044 	inc	dptr
      001D7E 12 41 61         [24] 6045 	lcall	__gptrput
                           001CC4  6046 	C$fuzzy.h$2314$1_0$106 ==.
                                   6047 ;	../../fuzzy.h:2314: result->smallest_position =
      001D81 A8 08            [24] 6048 	mov	r0,_bp
      001D83 08               [12] 6049 	inc	r0
      001D84 74 04            [12] 6050 	mov	a,#0x04
      001D86 2D               [12] 6051 	add	a, r5
      001D87 F6               [12] 6052 	mov	@r0,a
      001D88 E4               [12] 6053 	clr	a
      001D89 3E               [12] 6054 	addc	a, r6
      001D8A 08               [12] 6055 	inc	r0
      001D8B F6               [12] 6056 	mov	@r0,a
      001D8C 08               [12] 6057 	inc	r0
      001D8D A6 07            [24] 6058 	mov	@r0,ar7
      001D8F A8 08            [24] 6059 	mov	r0,_bp
      001D91 08               [12] 6060 	inc	r0
      001D92 86 82            [24] 6061 	mov	dpl,@r0
      001D94 08               [12] 6062 	inc	r0
      001D95 86 83            [24] 6063 	mov	dph,@r0
      001D97 08               [12] 6064 	inc	r0
      001D98 86 F0            [24] 6065 	mov	b,@r0
      001D9A E5 08            [12] 6066 	mov	a,_bp
      001D9C 24 F7            [12] 6067 	add	a,#0xf7
      001D9E F9               [12] 6068 	mov	r1,a
      001D9F E7               [12] 6069 	mov	a,@r1
      001DA0 12 41 61         [24] 6070 	lcall	__gptrput
      001DA3 A3               [24] 6071 	inc	dptr
      001DA4 09               [12] 6072 	inc	r1
      001DA5 E7               [12] 6073 	mov	a,@r1
      001DA6 12 41 61         [24] 6074 	lcall	__gptrput
      001DA9 A3               [24] 6075 	inc	dptr
      001DAA 09               [12] 6076 	inc	r1
      001DAB E7               [12] 6077 	mov	a,@r1
      001DAC 12 41 61         [24] 6078 	lcall	__gptrput
      001DAF A3               [24] 6079 	inc	dptr
      001DB0 09               [12] 6080 	inc	r1
      001DB1 E7               [12] 6081 	mov	a,@r1
      001DB2 12 41 61         [24] 6082 	lcall	__gptrput
                           001CF8  6083 	C$fuzzy.h$2317$1_0$106 ==.
                                   6084 ;	../../fuzzy.h:2317: result->largest_position =
      001DB5 E5 08            [12] 6085 	mov	a,_bp
      001DB7 24 04            [12] 6086 	add	a,#0x04
      001DB9 F8               [12] 6087 	mov	r0,a
      001DBA 74 08            [12] 6088 	mov	a,#0x08
      001DBC 2D               [12] 6089 	add	a, r5
      001DBD F6               [12] 6090 	mov	@r0,a
      001DBE E4               [12] 6091 	clr	a
      001DBF 3E               [12] 6092 	addc	a, r6
      001DC0 08               [12] 6093 	inc	r0
      001DC1 F6               [12] 6094 	mov	@r0,a
      001DC2 08               [12] 6095 	inc	r0
      001DC3 A6 07            [24] 6096 	mov	@r0,ar7
      001DC5 E5 08            [12] 6097 	mov	a,_bp
      001DC7 24 04            [12] 6098 	add	a,#0x04
      001DC9 F8               [12] 6099 	mov	r0,a
      001DCA 86 82            [24] 6100 	mov	dpl,@r0
      001DCC 08               [12] 6101 	inc	r0
      001DCD 86 83            [24] 6102 	mov	dph,@r0
      001DCF 08               [12] 6103 	inc	r0
      001DD0 86 F0            [24] 6104 	mov	b,@r0
      001DD2 E5 08            [12] 6105 	mov	a,_bp
      001DD4 24 F7            [12] 6106 	add	a,#0xf7
      001DD6 F9               [12] 6107 	mov	r1,a
      001DD7 E7               [12] 6108 	mov	a,@r1
      001DD8 12 41 61         [24] 6109 	lcall	__gptrput
      001DDB A3               [24] 6110 	inc	dptr
      001DDC 09               [12] 6111 	inc	r1
      001DDD E7               [12] 6112 	mov	a,@r1
      001DDE 12 41 61         [24] 6113 	lcall	__gptrput
      001DE1 A3               [24] 6114 	inc	dptr
      001DE2 09               [12] 6115 	inc	r1
      001DE3 E7               [12] 6116 	mov	a,@r1
      001DE4 12 41 61         [24] 6117 	lcall	__gptrput
      001DE7 A3               [24] 6118 	inc	dptr
      001DE8 09               [12] 6119 	inc	r1
      001DE9 E7               [12] 6120 	mov	a,@r1
      001DEA 12 41 61         [24] 6121 	lcall	__gptrput
                           001D30  6122 	C$fuzzy.h$2320$1_0$106 ==.
                                   6123 ;	../../fuzzy.h:2320: result->position_sum =
      001DED E5 08            [12] 6124 	mov	a,_bp
      001DEF 24 07            [12] 6125 	add	a,#0x07
      001DF1 F8               [12] 6126 	mov	r0,a
      001DF2 74 0C            [12] 6127 	mov	a,#0x0c
      001DF4 2D               [12] 6128 	add	a, r5
      001DF5 F6               [12] 6129 	mov	@r0,a
      001DF6 E4               [12] 6130 	clr	a
      001DF7 3E               [12] 6131 	addc	a, r6
      001DF8 08               [12] 6132 	inc	r0
      001DF9 F6               [12] 6133 	mov	@r0,a
      001DFA 08               [12] 6134 	inc	r0
      001DFB A6 07            [24] 6135 	mov	@r0,ar7
      001DFD E5 08            [12] 6136 	mov	a,_bp
      001DFF 24 07            [12] 6137 	add	a,#0x07
      001E01 F8               [12] 6138 	mov	r0,a
      001E02 86 82            [24] 6139 	mov	dpl,@r0
      001E04 08               [12] 6140 	inc	r0
      001E05 86 83            [24] 6141 	mov	dph,@r0
      001E07 08               [12] 6142 	inc	r0
      001E08 86 F0            [24] 6143 	mov	b,@r0
      001E0A E4               [12] 6144 	clr	a
      001E0B 12 41 61         [24] 6145 	lcall	__gptrput
      001E0E A3               [24] 6146 	inc	dptr
      001E0F 12 41 61         [24] 6147 	lcall	__gptrput
      001E12 A3               [24] 6148 	inc	dptr
      001E13 12 41 61         [24] 6149 	lcall	__gptrput
      001E16 A3               [24] 6150 	inc	dptr
      001E17 12 41 61         [24] 6151 	lcall	__gptrput
                           001D5D  6152 	C$fuzzy.h$2323$1_0$106 ==.
                                   6153 ;	../../fuzzy.h:2323: result->position_count =
      001E1A E5 08            [12] 6154 	mov	a,_bp
      001E1C 24 0D            [12] 6155 	add	a,#0x0d
      001E1E F8               [12] 6156 	mov	r0,a
      001E1F 74 10            [12] 6157 	mov	a,#0x10
      001E21 2D               [12] 6158 	add	a, r5
      001E22 F6               [12] 6159 	mov	@r0,a
      001E23 E4               [12] 6160 	clr	a
      001E24 3E               [12] 6161 	addc	a, r6
      001E25 08               [12] 6162 	inc	r0
      001E26 F6               [12] 6163 	mov	@r0,a
      001E27 08               [12] 6164 	inc	r0
      001E28 A6 07            [24] 6165 	mov	@r0,ar7
      001E2A E5 08            [12] 6166 	mov	a,_bp
      001E2C 24 0D            [12] 6167 	add	a,#0x0d
      001E2E F8               [12] 6168 	mov	r0,a
      001E2F 86 82            [24] 6169 	mov	dpl,@r0
      001E31 08               [12] 6170 	inc	r0
      001E32 86 83            [24] 6171 	mov	dph,@r0
      001E34 08               [12] 6172 	inc	r0
      001E35 86 F0            [24] 6173 	mov	b,@r0
      001E37 E4               [12] 6174 	clr	a
      001E38 12 41 61         [24] 6175 	lcall	__gptrput
      001E3B A3               [24] 6176 	inc	dptr
      001E3C 12 41 61         [24] 6177 	lcall	__gptrput
                           001D82  6178 	C$fuzzy.h$2327$2_0$107 ==.
                                   6179 ;	../../fuzzy.h:2327: value = lower;
      001E3F E5 08            [12] 6180 	mov	a,_bp
      001E41 24 F7            [12] 6181 	add	a,#0xf7
      001E43 F8               [12] 6182 	mov	r0,a
      001E44 E5 08            [12] 6183 	mov	a,_bp
      001E46 24 10            [12] 6184 	add	a,#0x10
      001E48 F9               [12] 6185 	mov	r1,a
      001E49 E6               [12] 6186 	mov	a,@r0
      001E4A F7               [12] 6187 	mov	@r1,a
      001E4B 08               [12] 6188 	inc	r0
      001E4C E6               [12] 6189 	mov	a,@r0
      001E4D 09               [12] 6190 	inc	r1
      001E4E F7               [12] 6191 	mov	@r1,a
      001E4F 08               [12] 6192 	inc	r0
      001E50 E6               [12] 6193 	mov	a,@r0
      001E51 09               [12] 6194 	inc	r1
      001E52 F7               [12] 6195 	mov	@r1,a
      001E53 08               [12] 6196 	inc	r0
      001E54 E6               [12] 6197 	mov	a,@r0
      001E55 09               [12] 6198 	inc	r1
      001E56 F7               [12] 6199 	mov	@r1,a
      001E57                       6200 00109$:
                           001D9A  6201 	C$fuzzy.h$2328$2_0$106 ==.
                                   6202 ;	../../fuzzy.h:2328: value <= upper;
      001E57 E5 08            [12] 6203 	mov	a,_bp
      001E59 24 10            [12] 6204 	add	a,#0x10
      001E5B F8               [12] 6205 	mov	r0,a
      001E5C E6               [12] 6206 	mov	a,@r0
      001E5D C0 E0            [24] 6207 	push	acc
      001E5F 08               [12] 6208 	inc	r0
      001E60 E6               [12] 6209 	mov	a,@r0
      001E61 C0 E0            [24] 6210 	push	acc
      001E63 08               [12] 6211 	inc	r0
      001E64 E6               [12] 6212 	mov	a,@r0
      001E65 C0 E0            [24] 6213 	push	acc
      001E67 08               [12] 6214 	inc	r0
      001E68 E6               [12] 6215 	mov	a,@r0
      001E69 C0 E0            [24] 6216 	push	acc
      001E6B E5 08            [12] 6217 	mov	a,_bp
      001E6D 24 F3            [12] 6218 	add	a,#0xf3
      001E6F F8               [12] 6219 	mov	r0,a
      001E70 86 82            [24] 6220 	mov	dpl, @r0
      001E72 08               [12] 6221 	inc	r0
      001E73 86 83            [24] 6222 	mov	dph, @r0
      001E75 08               [12] 6223 	inc	r0
      001E76 86 F0            [24] 6224 	mov	b, @r0
      001E78 08               [12] 6225 	inc	r0
      001E79 E6               [12] 6226 	mov	a, @r0
      001E7A 12 41 7C         [24] 6227 	lcall	___fslt
      001E7D E5 81            [12] 6228 	mov	a,sp
      001E7F 24 FC            [12] 6229 	add	a,#0xfc
      001E81 F5 81            [12] 6230 	mov	sp,a
      001E83 E5 82            [12] 6231 	mov	a, dpl
      001E85 24 FF            [12] 6232 	add	a,#0xff
      001E87 92 00            [24] 6233 	mov	b0,c
      001E89 50 03            [24] 6234 	jnc	00137$
      001E8B 02 21 3F         [24] 6235 	ljmp	00111$
      001E8E                       6236 00137$:
                           001DD1  6237 	C$fuzzy.h$2333$3_0$108 ==.
                                   6238 ;	../../fuzzy.h:2333: rules,
      001E8E E5 08            [12] 6239 	mov	a,_bp
      001E90 24 ED            [12] 6240 	add	a,#0xed
      001E92 F8               [12] 6241 	mov	r0,a
      001E93 E6               [12] 6242 	mov	a,@r0
      001E94 C0 E0            [24] 6243 	push	acc
      001E96 E5 08            [12] 6244 	mov	a,_bp
      001E98 24 EE            [12] 6245 	add	a,#0xee
      001E9A F8               [12] 6246 	mov	r0,a
      001E9B E6               [12] 6247 	mov	a,@r0
      001E9C C0 E0            [24] 6248 	push	acc
      001E9E E5 08            [12] 6249 	mov	a,_bp
      001EA0 24 10            [12] 6250 	add	a,#0x10
      001EA2 F8               [12] 6251 	mov	r0,a
      001EA3 E6               [12] 6252 	mov	a,@r0
      001EA4 C0 E0            [24] 6253 	push	acc
      001EA6 08               [12] 6254 	inc	r0
      001EA7 E6               [12] 6255 	mov	a,@r0
      001EA8 C0 E0            [24] 6256 	push	acc
      001EAA 08               [12] 6257 	inc	r0
      001EAB E6               [12] 6258 	mov	a,@r0
      001EAC C0 E0            [24] 6259 	push	acc
      001EAE 08               [12] 6260 	inc	r0
      001EAF E6               [12] 6261 	mov	a,@r0
      001EB0 C0 E0            [24] 6262 	push	acc
      001EB2 E5 08            [12] 6263 	mov	a,_bp
      001EB4 24 FB            [12] 6264 	add	a,#0xfb
      001EB6 F8               [12] 6265 	mov	r0,a
      001EB7 86 82            [24] 6266 	mov	dpl, @r0
      001EB9 08               [12] 6267 	inc	r0
      001EBA 86 83            [24] 6268 	mov	dph, @r0
      001EBC 08               [12] 6269 	inc	r0
      001EBD 86 F0            [24] 6270 	mov	b, @r0
      001EBF 12 1B 9E         [24] 6271 	lcall	_fuzzy_rules_aggregated_height
      001EC2 C8               [12] 6272 	xch	a,r0
      001EC3 E5 08            [12] 6273 	mov	a,_bp
      001EC5 24 14            [12] 6274 	add	a,#0x14
      001EC7 C8               [12] 6275 	xch	a,r0
      001EC8 A6 82            [24] 6276 	mov	@r0, dpl
      001ECA 08               [12] 6277 	inc	r0
      001ECB A6 83            [24] 6278 	mov	@r0, dph
      001ECD 08               [12] 6279 	inc	r0
      001ECE A6 F0            [24] 6280 	mov	@r0, b
      001ED0 08               [12] 6281 	inc	r0
      001ED1 F6               [12] 6282 	mov	@r0,a
      001ED2 E5 81            [12] 6283 	mov	a,sp
      001ED4 24 FA            [12] 6284 	add	a,#0xfa
      001ED6 F5 81            [12] 6285 	mov	sp,a
                           001E1B  6286 	C$fuzzy.h$2340$3_0$108 ==.
                                   6287 ;	../../fuzzy.h:2340: result->position_count == 0u ||
      001ED8 E5 08            [12] 6288 	mov	a,_bp
      001EDA 24 0D            [12] 6289 	add	a,#0x0d
      001EDC F8               [12] 6290 	mov	r0,a
      001EDD 86 82            [24] 6291 	mov	dpl,@r0
      001EDF 08               [12] 6292 	inc	r0
      001EE0 86 83            [24] 6293 	mov	dph,@r0
      001EE2 08               [12] 6294 	inc	r0
      001EE3 86 F0            [24] 6295 	mov	b,@r0
      001EE5 12 43 A8         [24] 6296 	lcall	__gptrget
      001EE8 FD               [12] 6297 	mov	r5,a
      001EE9 A3               [24] 6298 	inc	dptr
      001EEA 12 43 A8         [24] 6299 	lcall	__gptrget
      001EED 4D               [12] 6300 	orl	a,r5
      001EEE 60 4C            [24] 6301 	jz	00103$
                           001E33  6302 	C$fuzzy.h$2341$2_0$106 ==.
                                   6303 ;	../../fuzzy.h:2341: height > result->height
      001EF0 E5 08            [12] 6304 	mov	a,_bp
      001EF2 24 0A            [12] 6305 	add	a,#0x0a
      001EF4 F8               [12] 6306 	mov	r0,a
      001EF5 86 82            [24] 6307 	mov	dpl,@r0
      001EF7 08               [12] 6308 	inc	r0
      001EF8 86 83            [24] 6309 	mov	dph,@r0
      001EFA 08               [12] 6310 	inc	r0
      001EFB 86 F0            [24] 6311 	mov	b,@r0
      001EFD 12 43 A8         [24] 6312 	lcall	__gptrget
      001F00 FC               [12] 6313 	mov	r4,a
      001F01 A3               [24] 6314 	inc	dptr
      001F02 12 43 A8         [24] 6315 	lcall	__gptrget
      001F05 FD               [12] 6316 	mov	r5,a
      001F06 A3               [24] 6317 	inc	dptr
      001F07 12 43 A8         [24] 6318 	lcall	__gptrget
      001F0A FE               [12] 6319 	mov	r6,a
      001F0B A3               [24] 6320 	inc	dptr
      001F0C 12 43 A8         [24] 6321 	lcall	__gptrget
      001F0F FF               [12] 6322 	mov	r7,a
      001F10 E5 08            [12] 6323 	mov	a,_bp
      001F12 24 14            [12] 6324 	add	a,#0x14
      001F14 F8               [12] 6325 	mov	r0,a
      001F15 E6               [12] 6326 	mov	a,@r0
      001F16 C0 E0            [24] 6327 	push	acc
      001F18 08               [12] 6328 	inc	r0
      001F19 E6               [12] 6329 	mov	a,@r0
      001F1A C0 E0            [24] 6330 	push	acc
      001F1C 08               [12] 6331 	inc	r0
      001F1D E6               [12] 6332 	mov	a,@r0
      001F1E C0 E0            [24] 6333 	push	acc
      001F20 08               [12] 6334 	inc	r0
      001F21 E6               [12] 6335 	mov	a,@r0
      001F22 C0 E0            [24] 6336 	push	acc
      001F24 8C 82            [24] 6337 	mov	dpl, r4
      001F26 8D 83            [24] 6338 	mov	dph, r5
      001F28 8E F0            [24] 6339 	mov	b, r6
      001F2A EF               [12] 6340 	mov	a, r7
      001F2B 12 41 7C         [24] 6341 	lcall	___fslt
      001F2E AF 82            [24] 6342 	mov	r7, dpl
      001F30 E5 81            [12] 6343 	mov	a,sp
      001F32 24 FC            [12] 6344 	add	a,#0xfc
      001F34 F5 81            [12] 6345 	mov	sp,a
      001F36 EF               [12] 6346 	mov	a,r7
      001F37 70 03            [24] 6347 	jnz	00139$
      001F39 02 1F F4         [24] 6348 	ljmp	00104$
      001F3C                       6349 00139$:
      001F3C                       6350 00103$:
                           001E7F  6351 	C$fuzzy.h$2343$4_0$109 ==.
                                   6352 ;	../../fuzzy.h:2343: result->height =
      001F3C E5 08            [12] 6353 	mov	a,_bp
      001F3E 24 0A            [12] 6354 	add	a,#0x0a
      001F40 F8               [12] 6355 	mov	r0,a
      001F41 86 82            [24] 6356 	mov	dpl,@r0
      001F43 08               [12] 6357 	inc	r0
      001F44 86 83            [24] 6358 	mov	dph,@r0
      001F46 08               [12] 6359 	inc	r0
      001F47 86 F0            [24] 6360 	mov	b,@r0
      001F49 E5 08            [12] 6361 	mov	a,_bp
      001F4B 24 14            [12] 6362 	add	a,#0x14
      001F4D F9               [12] 6363 	mov	r1,a
      001F4E E7               [12] 6364 	mov	a,@r1
      001F4F 12 41 61         [24] 6365 	lcall	__gptrput
      001F52 A3               [24] 6366 	inc	dptr
      001F53 09               [12] 6367 	inc	r1
      001F54 E7               [12] 6368 	mov	a,@r1
      001F55 12 41 61         [24] 6369 	lcall	__gptrput
      001F58 A3               [24] 6370 	inc	dptr
      001F59 09               [12] 6371 	inc	r1
      001F5A E7               [12] 6372 	mov	a,@r1
      001F5B 12 41 61         [24] 6373 	lcall	__gptrput
      001F5E A3               [24] 6374 	inc	dptr
      001F5F 09               [12] 6375 	inc	r1
      001F60 E7               [12] 6376 	mov	a,@r1
      001F61 12 41 61         [24] 6377 	lcall	__gptrput
                           001EA7  6378 	C$fuzzy.h$2346$4_0$109 ==.
                                   6379 ;	../../fuzzy.h:2346: result->smallest_position =
      001F64 A8 08            [24] 6380 	mov	r0,_bp
      001F66 08               [12] 6381 	inc	r0
      001F67 86 82            [24] 6382 	mov	dpl,@r0
      001F69 08               [12] 6383 	inc	r0
      001F6A 86 83            [24] 6384 	mov	dph,@r0
      001F6C 08               [12] 6385 	inc	r0
      001F6D 86 F0            [24] 6386 	mov	b,@r0
      001F6F E5 08            [12] 6387 	mov	a,_bp
      001F71 24 10            [12] 6388 	add	a,#0x10
      001F73 F9               [12] 6389 	mov	r1,a
      001F74 E7               [12] 6390 	mov	a,@r1
      001F75 12 41 61         [24] 6391 	lcall	__gptrput
      001F78 A3               [24] 6392 	inc	dptr
      001F79 09               [12] 6393 	inc	r1
      001F7A E7               [12] 6394 	mov	a,@r1
      001F7B 12 41 61         [24] 6395 	lcall	__gptrput
      001F7E A3               [24] 6396 	inc	dptr
      001F7F 09               [12] 6397 	inc	r1
      001F80 E7               [12] 6398 	mov	a,@r1
      001F81 12 41 61         [24] 6399 	lcall	__gptrput
      001F84 A3               [24] 6400 	inc	dptr
      001F85 09               [12] 6401 	inc	r1
      001F86 E7               [12] 6402 	mov	a,@r1
      001F87 12 41 61         [24] 6403 	lcall	__gptrput
                           001ECD  6404 	C$fuzzy.h$2349$4_0$109 ==.
                                   6405 ;	../../fuzzy.h:2349: result->largest_position =
      001F8A E5 08            [12] 6406 	mov	a,_bp
      001F8C 24 04            [12] 6407 	add	a,#0x04
      001F8E F8               [12] 6408 	mov	r0,a
      001F8F 86 82            [24] 6409 	mov	dpl,@r0
      001F91 08               [12] 6410 	inc	r0
      001F92 86 83            [24] 6411 	mov	dph,@r0
      001F94 08               [12] 6412 	inc	r0
      001F95 86 F0            [24] 6413 	mov	b,@r0
      001F97 E5 08            [12] 6414 	mov	a,_bp
      001F99 24 10            [12] 6415 	add	a,#0x10
      001F9B F9               [12] 6416 	mov	r1,a
      001F9C E7               [12] 6417 	mov	a,@r1
      001F9D 12 41 61         [24] 6418 	lcall	__gptrput
      001FA0 A3               [24] 6419 	inc	dptr
      001FA1 09               [12] 6420 	inc	r1
      001FA2 E7               [12] 6421 	mov	a,@r1
      001FA3 12 41 61         [24] 6422 	lcall	__gptrput
      001FA6 A3               [24] 6423 	inc	dptr
      001FA7 09               [12] 6424 	inc	r1
      001FA8 E7               [12] 6425 	mov	a,@r1
      001FA9 12 41 61         [24] 6426 	lcall	__gptrput
      001FAC A3               [24] 6427 	inc	dptr
      001FAD 09               [12] 6428 	inc	r1
      001FAE E7               [12] 6429 	mov	a,@r1
      001FAF 12 41 61         [24] 6430 	lcall	__gptrput
                           001EF5  6431 	C$fuzzy.h$2352$4_0$109 ==.
                                   6432 ;	../../fuzzy.h:2352: result->position_sum =
      001FB2 E5 08            [12] 6433 	mov	a,_bp
      001FB4 24 07            [12] 6434 	add	a,#0x07
      001FB6 F8               [12] 6435 	mov	r0,a
      001FB7 86 82            [24] 6436 	mov	dpl,@r0
      001FB9 08               [12] 6437 	inc	r0
      001FBA 86 83            [24] 6438 	mov	dph,@r0
      001FBC 08               [12] 6439 	inc	r0
      001FBD 86 F0            [24] 6440 	mov	b,@r0
      001FBF E5 08            [12] 6441 	mov	a,_bp
      001FC1 24 10            [12] 6442 	add	a,#0x10
      001FC3 F9               [12] 6443 	mov	r1,a
      001FC4 E7               [12] 6444 	mov	a,@r1
      001FC5 12 41 61         [24] 6445 	lcall	__gptrput
      001FC8 A3               [24] 6446 	inc	dptr
      001FC9 09               [12] 6447 	inc	r1
      001FCA E7               [12] 6448 	mov	a,@r1
      001FCB 12 41 61         [24] 6449 	lcall	__gptrput
      001FCE A3               [24] 6450 	inc	dptr
      001FCF 09               [12] 6451 	inc	r1
      001FD0 E7               [12] 6452 	mov	a,@r1
      001FD1 12 41 61         [24] 6453 	lcall	__gptrput
      001FD4 A3               [24] 6454 	inc	dptr
      001FD5 09               [12] 6455 	inc	r1
      001FD6 E7               [12] 6456 	mov	a,@r1
      001FD7 12 41 61         [24] 6457 	lcall	__gptrput
                           001F1D  6458 	C$fuzzy.h$2355$4_0$109 ==.
                                   6459 ;	../../fuzzy.h:2355: result->position_count =
      001FDA E5 08            [12] 6460 	mov	a,_bp
      001FDC 24 0D            [12] 6461 	add	a,#0x0d
      001FDE F8               [12] 6462 	mov	r0,a
      001FDF 86 82            [24] 6463 	mov	dpl,@r0
      001FE1 08               [12] 6464 	inc	r0
      001FE2 86 83            [24] 6465 	mov	dph,@r0
      001FE4 08               [12] 6466 	inc	r0
      001FE5 86 F0            [24] 6467 	mov	b,@r0
      001FE7 74 01            [12] 6468 	mov	a,#0x01
      001FE9 12 41 61         [24] 6469 	lcall	__gptrput
      001FEC A3               [24] 6470 	inc	dptr
      001FED E4               [12] 6471 	clr	a
      001FEE 12 41 61         [24] 6472 	lcall	__gptrput
      001FF1 02 21 00         [24] 6473 	ljmp	00110$
      001FF4                       6474 00104$:
                           001F37  6475 	C$fuzzy.h$2360$2_0$106 ==.
                                   6476 ;	../../fuzzy.h:2360: result->height
      001FF4 E5 08            [12] 6477 	mov	a,_bp
      001FF6 24 0A            [12] 6478 	add	a,#0x0a
      001FF8 F8               [12] 6479 	mov	r0,a
      001FF9 86 82            [24] 6480 	mov	dpl,@r0
      001FFB 08               [12] 6481 	inc	r0
      001FFC 86 83            [24] 6482 	mov	dph,@r0
      001FFE 08               [12] 6483 	inc	r0
      001FFF 86 F0            [24] 6484 	mov	b,@r0
      002001 12 43 A8         [24] 6485 	lcall	__gptrget
      002004 FC               [12] 6486 	mov	r4,a
      002005 A3               [24] 6487 	inc	dptr
      002006 12 43 A8         [24] 6488 	lcall	__gptrget
      002009 FD               [12] 6489 	mov	r5,a
      00200A A3               [24] 6490 	inc	dptr
      00200B 12 43 A8         [24] 6491 	lcall	__gptrget
      00200E FE               [12] 6492 	mov	r6,a
      00200F A3               [24] 6493 	inc	dptr
      002010 12 43 A8         [24] 6494 	lcall	__gptrget
      002013 FF               [12] 6495 	mov	r7,a
      002014 C0 04            [24] 6496 	push	ar4
      002016 C0 05            [24] 6497 	push	ar5
      002018 C0 06            [24] 6498 	push	ar6
      00201A C0 07            [24] 6499 	push	ar7
      00201C E5 08            [12] 6500 	mov	a,_bp
      00201E 24 14            [12] 6501 	add	a,#0x14
      002020 F8               [12] 6502 	mov	r0,a
      002021 86 82            [24] 6503 	mov	dpl, @r0
      002023 08               [12] 6504 	inc	r0
      002024 86 83            [24] 6505 	mov	dph, @r0
      002026 08               [12] 6506 	inc	r0
      002027 86 F0            [24] 6507 	mov	b, @r0
      002029 08               [12] 6508 	inc	r0
      00202A E6               [12] 6509 	mov	a, @r0
      00202B 12 41 50         [24] 6510 	lcall	___fseq
      00202E AF 82            [24] 6511 	mov	r7, dpl
      002030 E5 81            [12] 6512 	mov	a,sp
      002032 24 FC            [12] 6513 	add	a,#0xfc
      002034 F5 81            [12] 6514 	mov	sp,a
      002036 EF               [12] 6515 	mov	a,r7
      002037 70 03            [24] 6516 	jnz	00140$
      002039 02 21 00         [24] 6517 	ljmp	00110$
      00203C                       6518 00140$:
                           001F7F  6519 	C$fuzzy.h$2362$4_0$110 ==.
                                   6520 ;	../../fuzzy.h:2362: result->largest_position =
      00203C E5 08            [12] 6521 	mov	a,_bp
      00203E 24 04            [12] 6522 	add	a,#0x04
      002040 F8               [12] 6523 	mov	r0,a
      002041 86 82            [24] 6524 	mov	dpl,@r0
      002043 08               [12] 6525 	inc	r0
      002044 86 83            [24] 6526 	mov	dph,@r0
      002046 08               [12] 6527 	inc	r0
      002047 86 F0            [24] 6528 	mov	b,@r0
      002049 E5 08            [12] 6529 	mov	a,_bp
      00204B 24 10            [12] 6530 	add	a,#0x10
      00204D F9               [12] 6531 	mov	r1,a
      00204E E7               [12] 6532 	mov	a,@r1
      00204F 12 41 61         [24] 6533 	lcall	__gptrput
      002052 A3               [24] 6534 	inc	dptr
      002053 09               [12] 6535 	inc	r1
      002054 E7               [12] 6536 	mov	a,@r1
      002055 12 41 61         [24] 6537 	lcall	__gptrput
      002058 A3               [24] 6538 	inc	dptr
      002059 09               [12] 6539 	inc	r1
      00205A E7               [12] 6540 	mov	a,@r1
      00205B 12 41 61         [24] 6541 	lcall	__gptrput
      00205E A3               [24] 6542 	inc	dptr
      00205F 09               [12] 6543 	inc	r1
      002060 E7               [12] 6544 	mov	a,@r1
      002061 12 41 61         [24] 6545 	lcall	__gptrput
                           001FA7  6546 	C$fuzzy.h$2365$4_0$110 ==.
                                   6547 ;	../../fuzzy.h:2365: result->position_sum +=
      002064 E5 08            [12] 6548 	mov	a,_bp
      002066 24 07            [12] 6549 	add	a,#0x07
      002068 F8               [12] 6550 	mov	r0,a
      002069 86 82            [24] 6551 	mov	dpl,@r0
      00206B 08               [12] 6552 	inc	r0
      00206C 86 83            [24] 6553 	mov	dph,@r0
      00206E 08               [12] 6554 	inc	r0
      00206F 86 F0            [24] 6555 	mov	b,@r0
      002071 12 43 A8         [24] 6556 	lcall	__gptrget
      002074 FC               [12] 6557 	mov	r4,a
      002075 A3               [24] 6558 	inc	dptr
      002076 12 43 A8         [24] 6559 	lcall	__gptrget
      002079 FD               [12] 6560 	mov	r5,a
      00207A A3               [24] 6561 	inc	dptr
      00207B 12 43 A8         [24] 6562 	lcall	__gptrget
      00207E FE               [12] 6563 	mov	r6,a
      00207F A3               [24] 6564 	inc	dptr
      002080 12 43 A8         [24] 6565 	lcall	__gptrget
      002083 FF               [12] 6566 	mov	r7,a
      002084 E5 08            [12] 6567 	mov	a,_bp
      002086 24 10            [12] 6568 	add	a,#0x10
      002088 F8               [12] 6569 	mov	r0,a
      002089 E6               [12] 6570 	mov	a,@r0
      00208A C0 E0            [24] 6571 	push	acc
      00208C 08               [12] 6572 	inc	r0
      00208D E6               [12] 6573 	mov	a,@r0
      00208E C0 E0            [24] 6574 	push	acc
      002090 08               [12] 6575 	inc	r0
      002091 E6               [12] 6576 	mov	a,@r0
      002092 C0 E0            [24] 6577 	push	acc
      002094 08               [12] 6578 	inc	r0
      002095 E6               [12] 6579 	mov	a,@r0
      002096 C0 E0            [24] 6580 	push	acc
      002098 8C 82            [24] 6581 	mov	dpl, r4
      00209A 8D 83            [24] 6582 	mov	dph, r5
      00209C 8E F0            [24] 6583 	mov	b, r6
      00209E EF               [12] 6584 	mov	a, r7
      00209F 12 41 CE         [24] 6585 	lcall	___fsadd
      0020A2 AC 82            [24] 6586 	mov	r4, dpl
      0020A4 AD 83            [24] 6587 	mov	r5, dph
      0020A6 AE F0            [24] 6588 	mov	r6, b
      0020A8 FF               [12] 6589 	mov	r7, a
      0020A9 E5 81            [12] 6590 	mov	a,sp
      0020AB 24 FC            [12] 6591 	add	a,#0xfc
      0020AD F5 81            [12] 6592 	mov	sp,a
      0020AF E5 08            [12] 6593 	mov	a,_bp
      0020B1 24 07            [12] 6594 	add	a,#0x07
      0020B3 F8               [12] 6595 	mov	r0,a
      0020B4 86 82            [24] 6596 	mov	dpl,@r0
      0020B6 08               [12] 6597 	inc	r0
      0020B7 86 83            [24] 6598 	mov	dph,@r0
      0020B9 08               [12] 6599 	inc	r0
      0020BA 86 F0            [24] 6600 	mov	b,@r0
      0020BC EC               [12] 6601 	mov	a,r4
      0020BD 12 41 61         [24] 6602 	lcall	__gptrput
      0020C0 A3               [24] 6603 	inc	dptr
      0020C1 ED               [12] 6604 	mov	a,r5
      0020C2 12 41 61         [24] 6605 	lcall	__gptrput
      0020C5 A3               [24] 6606 	inc	dptr
      0020C6 EE               [12] 6607 	mov	a,r6
      0020C7 12 41 61         [24] 6608 	lcall	__gptrput
      0020CA A3               [24] 6609 	inc	dptr
      0020CB EF               [12] 6610 	mov	a,r7
      0020CC 12 41 61         [24] 6611 	lcall	__gptrput
                           002012  6612 	C$fuzzy.h$2368$4_0$110 ==.
                                   6613 ;	../../fuzzy.h:2368: result->position_count++;
      0020CF E5 08            [12] 6614 	mov	a,_bp
      0020D1 24 0D            [12] 6615 	add	a,#0x0d
      0020D3 F8               [12] 6616 	mov	r0,a
      0020D4 86 82            [24] 6617 	mov	dpl,@r0
      0020D6 08               [12] 6618 	inc	r0
      0020D7 86 83            [24] 6619 	mov	dph,@r0
      0020D9 08               [12] 6620 	inc	r0
      0020DA 86 F0            [24] 6621 	mov	b,@r0
      0020DC 12 43 A8         [24] 6622 	lcall	__gptrget
      0020DF FF               [12] 6623 	mov	r7,a
      0020E0 A3               [24] 6624 	inc	dptr
      0020E1 12 43 A8         [24] 6625 	lcall	__gptrget
      0020E4 FE               [12] 6626 	mov	r6,a
      0020E5 0F               [12] 6627 	inc	r7
      0020E6 BF 00 01         [24] 6628 	cjne	r7,#0x00,00141$
      0020E9 0E               [12] 6629 	inc	r6
      0020EA                       6630 00141$:
      0020EA E5 08            [12] 6631 	mov	a,_bp
      0020EC 24 0D            [12] 6632 	add	a,#0x0d
      0020EE F8               [12] 6633 	mov	r0,a
      0020EF 86 82            [24] 6634 	mov	dpl,@r0
      0020F1 08               [12] 6635 	inc	r0
      0020F2 86 83            [24] 6636 	mov	dph,@r0
      0020F4 08               [12] 6637 	inc	r0
      0020F5 86 F0            [24] 6638 	mov	b,@r0
      0020F7 EF               [12] 6639 	mov	a,r7
      0020F8 12 41 61         [24] 6640 	lcall	__gptrput
      0020FB A3               [24] 6641 	inc	dptr
      0020FC EE               [12] 6642 	mov	a,r6
      0020FD 12 41 61         [24] 6643 	lcall	__gptrput
      002100                       6644 00110$:
                           002043  6645 	C$fuzzy.h$2330$2_0$106 ==.
                                   6646 ;	../../fuzzy.h:2330: ) {
      002100 E5 08            [12] 6647 	mov	a,_bp
      002102 24 EF            [12] 6648 	add	a,#0xef
      002104 F8               [12] 6649 	mov	r0,a
      002105 E6               [12] 6650 	mov	a,@r0
      002106 C0 E0            [24] 6651 	push	acc
      002108 08               [12] 6652 	inc	r0
      002109 E6               [12] 6653 	mov	a,@r0
      00210A C0 E0            [24] 6654 	push	acc
      00210C 08               [12] 6655 	inc	r0
      00210D E6               [12] 6656 	mov	a,@r0
      00210E C0 E0            [24] 6657 	push	acc
      002110 08               [12] 6658 	inc	r0
      002111 E6               [12] 6659 	mov	a,@r0
      002112 C0 E0            [24] 6660 	push	acc
      002114 E5 08            [12] 6661 	mov	a,_bp
      002116 24 10            [12] 6662 	add	a,#0x10
      002118 F8               [12] 6663 	mov	r0,a
      002119 86 82            [24] 6664 	mov	dpl, @r0
      00211B 08               [12] 6665 	inc	r0
      00211C 86 83            [24] 6666 	mov	dph, @r0
      00211E 08               [12] 6667 	inc	r0
      00211F 86 F0            [24] 6668 	mov	b, @r0
      002121 08               [12] 6669 	inc	r0
      002122 E6               [12] 6670 	mov	a, @r0
      002123 12 41 CE         [24] 6671 	lcall	___fsadd
      002126 C8               [12] 6672 	xch	a,r0
      002127 E5 08            [12] 6673 	mov	a,_bp
      002129 24 10            [12] 6674 	add	a,#0x10
      00212B C8               [12] 6675 	xch	a,r0
      00212C A6 82            [24] 6676 	mov	@r0, dpl
      00212E 08               [12] 6677 	inc	r0
      00212F A6 83            [24] 6678 	mov	@r0, dph
      002131 08               [12] 6679 	inc	r0
      002132 A6 F0            [24] 6680 	mov	@r0, b
      002134 08               [12] 6681 	inc	r0
      002135 F6               [12] 6682 	mov	@r0,a
      002136 E5 81            [12] 6683 	mov	a,sp
      002138 24 FC            [12] 6684 	add	a,#0xfc
      00213A F5 81            [12] 6685 	mov	sp,a
      00213C 02 1E 57         [24] 6686 	ljmp	00109$
      00213F                       6687 00111$:
                           002082  6688 	C$fuzzy.h$2371$2_0$106 ==.
                                   6689 ;	../../fuzzy.h:2371: }
      00213F 85 08 81         [24] 6690 	mov	sp,_bp
      002142 D0 08            [24] 6691 	pop	_bp
                           002087  6692 	C$fuzzy.h$2371$2_0$106 ==.
                           002087  6693 	XFsugeno_demo$fuzzy_rules_maximum_result$0$0 ==.
      002144 22               [24] 6694 	ret
                                   6695 ;------------------------------------------------------------
                                   6696 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_cog'
                                   6697 ;------------------------------------------------------------
                                   6698 ;lower         Allocated to stack - _bp -6 +4 
                                   6699 ;upper         Allocated to stack - _bp -10 +4 
                                   6700 ;step          Allocated to stack - _bp -14 +4 
                                   6701 ;implication_method Allocated to stack - _bp -15 +1 
                                   6702 ;aggregation_method Allocated to stack - _bp -16 +1 
                                   6703 ;rules         Allocated to stack - _bp +1 +3 
                                   6704 ;weighted_sum  Allocated to stack - _bp +4 +4 
                                   6705 ;height_sum    Allocated to stack - _bp +8 +4 
                                   6706 ;value         Allocated to stack - _bp +12 +4 
                                   6707 ;height        Allocated to stack - _bp +16 +4 
                                   6708 ;------------------------------------------------------------
                           002088  6709 	G$fuzzy_rules_defuzzify_cog$0$0 ==.
                           002088  6710 	C$fuzzy.h$2378$2_0$112 ==.
                                   6711 ;	../../fuzzy.h:2378: float fuzzy_rules_defuzzify_cog(
                                   6712 ;	-----------------------------------------
                                   6713 ;	 function fuzzy_rules_defuzzify_cog
                                   6714 ;	-----------------------------------------
      002145                       6715 _fuzzy_rules_defuzzify_cog:
      002145 C0 08            [24] 6716 	push	_bp
      002147 85 81 08         [24] 6717 	mov	_bp,sp
      00214A C0 82            [24] 6718 	push	dpl
      00214C C0 83            [24] 6719 	push	dph
      00214E C0 F0            [24] 6720 	push	b
      002150 E5 81            [12] 6721 	mov	a,sp
      002152 24 10            [12] 6722 	add	a,#0x10
      002154 F5 81            [12] 6723 	mov	sp,a
                           002099  6724 	C$fuzzy.h$2393$1_0$112 ==.
                                   6725 ;	../../fuzzy.h:2393: 0.0f;
      002156 E5 08            [12] 6726 	mov	a,_bp
      002158 24 04            [12] 6727 	add	a,#0x04
      00215A F8               [12] 6728 	mov	r0,a
      00215B E4               [12] 6729 	clr	a
      00215C F6               [12] 6730 	mov	@r0,a
      00215D 08               [12] 6731 	inc	r0
      00215E F6               [12] 6732 	mov	@r0,a
      00215F 08               [12] 6733 	inc	r0
      002160 F6               [12] 6734 	mov	@r0,a
      002161 08               [12] 6735 	inc	r0
      002162 F6               [12] 6736 	mov	@r0,a
                           0020A6  6737 	C$fuzzy.h$2396$1_0$112 ==.
                                   6738 ;	../../fuzzy.h:2396: 0.0f;
      002163 E5 08            [12] 6739 	mov	a,_bp
      002165 24 08            [12] 6740 	add	a,#0x08
      002167 F8               [12] 6741 	mov	r0,a
      002168 E4               [12] 6742 	clr	a
      002169 F6               [12] 6743 	mov	@r0,a
      00216A 08               [12] 6744 	inc	r0
      00216B F6               [12] 6745 	mov	@r0,a
      00216C 08               [12] 6746 	inc	r0
      00216D F6               [12] 6747 	mov	@r0,a
      00216E 08               [12] 6748 	inc	r0
      00216F F6               [12] 6749 	mov	@r0,a
                           0020B3  6750 	C$fuzzy.h$2399$2_0$113 ==.
                                   6751 ;	../../fuzzy.h:2399: value = lower;
      002170 E5 08            [12] 6752 	mov	a,_bp
      002172 24 FA            [12] 6753 	add	a,#0xfa
      002174 F8               [12] 6754 	mov	r0,a
      002175 E5 08            [12] 6755 	mov	a,_bp
      002177 24 0C            [12] 6756 	add	a,#0x0c
      002179 F9               [12] 6757 	mov	r1,a
      00217A E6               [12] 6758 	mov	a,@r0
      00217B F7               [12] 6759 	mov	@r1,a
      00217C 08               [12] 6760 	inc	r0
      00217D E6               [12] 6761 	mov	a,@r0
      00217E 09               [12] 6762 	inc	r1
      00217F F7               [12] 6763 	mov	@r1,a
      002180 08               [12] 6764 	inc	r0
      002181 E6               [12] 6765 	mov	a,@r0
      002182 09               [12] 6766 	inc	r1
      002183 F7               [12] 6767 	mov	@r1,a
      002184 08               [12] 6768 	inc	r0
      002185 E6               [12] 6769 	mov	a,@r0
      002186 09               [12] 6770 	inc	r1
      002187 F7               [12] 6771 	mov	@r1,a
      002188                       6772 00105$:
                           0020CB  6773 	C$fuzzy.h$2400$1_0$112 ==.
                                   6774 ;	../../fuzzy.h:2400: value <= upper;
      002188 E5 08            [12] 6775 	mov	a,_bp
      00218A 24 0C            [12] 6776 	add	a,#0x0c
      00218C F8               [12] 6777 	mov	r0,a
      00218D E6               [12] 6778 	mov	a,@r0
      00218E C0 E0            [24] 6779 	push	acc
      002190 08               [12] 6780 	inc	r0
      002191 E6               [12] 6781 	mov	a,@r0
      002192 C0 E0            [24] 6782 	push	acc
      002194 08               [12] 6783 	inc	r0
      002195 E6               [12] 6784 	mov	a,@r0
      002196 C0 E0            [24] 6785 	push	acc
      002198 08               [12] 6786 	inc	r0
      002199 E6               [12] 6787 	mov	a,@r0
      00219A C0 E0            [24] 6788 	push	acc
      00219C E5 08            [12] 6789 	mov	a,_bp
      00219E 24 F6            [12] 6790 	add	a,#0xf6
      0021A0 F8               [12] 6791 	mov	r0,a
      0021A1 86 82            [24] 6792 	mov	dpl, @r0
      0021A3 08               [12] 6793 	inc	r0
      0021A4 86 83            [24] 6794 	mov	dph, @r0
      0021A6 08               [12] 6795 	inc	r0
      0021A7 86 F0            [24] 6796 	mov	b, @r0
      0021A9 08               [12] 6797 	inc	r0
      0021AA E6               [12] 6798 	mov	a, @r0
      0021AB 12 41 7C         [24] 6799 	lcall	___fslt
      0021AE E5 81            [12] 6800 	mov	a,sp
      0021B0 24 FC            [12] 6801 	add	a,#0xfc
      0021B2 F5 81            [12] 6802 	mov	sp,a
      0021B4 E5 82            [12] 6803 	mov	a, dpl
      0021B6 24 FF            [12] 6804 	add	a,#0xff
      0021B8 92 00            [24] 6805 	mov	b0,c
      0021BA 50 03            [24] 6806 	jnc	00127$
      0021BC 02 22 E5         [24] 6807 	ljmp	00101$
      0021BF                       6808 00127$:
                           002102  6809 	C$fuzzy.h$2405$3_0$114 ==.
                                   6810 ;	../../fuzzy.h:2405: rules,
      0021BF E5 08            [12] 6811 	mov	a,_bp
      0021C1 24 F0            [12] 6812 	add	a,#0xf0
      0021C3 F8               [12] 6813 	mov	r0,a
      0021C4 E6               [12] 6814 	mov	a,@r0
      0021C5 C0 E0            [24] 6815 	push	acc
      0021C7 E5 08            [12] 6816 	mov	a,_bp
      0021C9 24 F1            [12] 6817 	add	a,#0xf1
      0021CB F8               [12] 6818 	mov	r0,a
      0021CC E6               [12] 6819 	mov	a,@r0
      0021CD C0 E0            [24] 6820 	push	acc
      0021CF E5 08            [12] 6821 	mov	a,_bp
      0021D1 24 0C            [12] 6822 	add	a,#0x0c
      0021D3 F8               [12] 6823 	mov	r0,a
      0021D4 E6               [12] 6824 	mov	a,@r0
      0021D5 C0 E0            [24] 6825 	push	acc
      0021D7 08               [12] 6826 	inc	r0
      0021D8 E6               [12] 6827 	mov	a,@r0
      0021D9 C0 E0            [24] 6828 	push	acc
      0021DB 08               [12] 6829 	inc	r0
      0021DC E6               [12] 6830 	mov	a,@r0
      0021DD C0 E0            [24] 6831 	push	acc
      0021DF 08               [12] 6832 	inc	r0
      0021E0 E6               [12] 6833 	mov	a,@r0
      0021E1 C0 E0            [24] 6834 	push	acc
      0021E3 A8 08            [24] 6835 	mov	r0,_bp
      0021E5 08               [12] 6836 	inc	r0
      0021E6 86 82            [24] 6837 	mov	dpl, @r0
      0021E8 08               [12] 6838 	inc	r0
      0021E9 86 83            [24] 6839 	mov	dph, @r0
      0021EB 08               [12] 6840 	inc	r0
      0021EC 86 F0            [24] 6841 	mov	b, @r0
      0021EE 12 1B 9E         [24] 6842 	lcall	_fuzzy_rules_aggregated_height
      0021F1 C8               [12] 6843 	xch	a,r0
      0021F2 E5 08            [12] 6844 	mov	a,_bp
      0021F4 24 10            [12] 6845 	add	a,#0x10
      0021F6 C8               [12] 6846 	xch	a,r0
      0021F7 A6 82            [24] 6847 	mov	@r0, dpl
      0021F9 08               [12] 6848 	inc	r0
      0021FA A6 83            [24] 6849 	mov	@r0, dph
      0021FC 08               [12] 6850 	inc	r0
      0021FD A6 F0            [24] 6851 	mov	@r0, b
      0021FF 08               [12] 6852 	inc	r0
      002200 F6               [12] 6853 	mov	@r0,a
      002201 E5 81            [12] 6854 	mov	a,sp
      002203 24 FA            [12] 6855 	add	a,#0xfa
      002205 F5 81            [12] 6856 	mov	sp,a
                           00214A  6857 	C$fuzzy.h$2413$1_0$112 ==.
                                   6858 ;	../../fuzzy.h:2413: height;
      002207 E5 08            [12] 6859 	mov	a,_bp
      002209 24 10            [12] 6860 	add	a,#0x10
      00220B F8               [12] 6861 	mov	r0,a
      00220C E6               [12] 6862 	mov	a,@r0
      00220D C0 E0            [24] 6863 	push	acc
      00220F 08               [12] 6864 	inc	r0
      002210 E6               [12] 6865 	mov	a,@r0
      002211 C0 E0            [24] 6866 	push	acc
      002213 08               [12] 6867 	inc	r0
      002214 E6               [12] 6868 	mov	a,@r0
      002215 C0 E0            [24] 6869 	push	acc
      002217 08               [12] 6870 	inc	r0
      002218 E6               [12] 6871 	mov	a,@r0
      002219 C0 E0            [24] 6872 	push	acc
      00221B E5 08            [12] 6873 	mov	a,_bp
      00221D 24 0C            [12] 6874 	add	a,#0x0c
      00221F F8               [12] 6875 	mov	r0,a
      002220 86 82            [24] 6876 	mov	dpl, @r0
      002222 08               [12] 6877 	inc	r0
      002223 86 83            [24] 6878 	mov	dph, @r0
      002225 08               [12] 6879 	inc	r0
      002226 86 F0            [24] 6880 	mov	b, @r0
      002228 08               [12] 6881 	inc	r0
      002229 E6               [12] 6882 	mov	a, @r0
      00222A 12 40 4C         [24] 6883 	lcall	___fsmul
      00222D AC 82            [24] 6884 	mov	r4, dpl
      00222F AD 83            [24] 6885 	mov	r5, dph
      002231 AE F0            [24] 6886 	mov	r6, b
      002233 FF               [12] 6887 	mov	r7, a
      002234 E5 81            [12] 6888 	mov	a,sp
      002236 24 FC            [12] 6889 	add	a,#0xfc
      002238 F5 81            [12] 6890 	mov	sp,a
      00223A C0 04            [24] 6891 	push	ar4
      00223C C0 05            [24] 6892 	push	ar5
      00223E C0 06            [24] 6893 	push	ar6
      002240 C0 07            [24] 6894 	push	ar7
                           002185  6895 	C$fuzzy.h$2416$1_0$112 ==.
                                   6896 ;	../../fuzzy.h:2416: height;
      002242 E5 08            [12] 6897 	mov	a,_bp
      002244 24 04            [12] 6898 	add	a,#0x04
      002246 F8               [12] 6899 	mov	r0,a
      002247 86 82            [24] 6900 	mov	dpl, @r0
      002249 08               [12] 6901 	inc	r0
      00224A 86 83            [24] 6902 	mov	dph, @r0
      00224C 08               [12] 6903 	inc	r0
      00224D 86 F0            [24] 6904 	mov	b, @r0
      00224F 08               [12] 6905 	inc	r0
      002250 E6               [12] 6906 	mov	a, @r0
      002251 12 41 CE         [24] 6907 	lcall	___fsadd
      002254 C8               [12] 6908 	xch	a,r0
      002255 E5 08            [12] 6909 	mov	a,_bp
      002257 24 04            [12] 6910 	add	a,#0x04
      002259 C8               [12] 6911 	xch	a,r0
      00225A A6 82            [24] 6912 	mov	@r0, dpl
      00225C 08               [12] 6913 	inc	r0
      00225D A6 83            [24] 6914 	mov	@r0, dph
      00225F 08               [12] 6915 	inc	r0
      002260 A6 F0            [24] 6916 	mov	@r0, b
      002262 08               [12] 6917 	inc	r0
      002263 F6               [12] 6918 	mov	@r0,a
      002264 E5 81            [12] 6919 	mov	a,sp
      002266 24 FC            [12] 6920 	add	a,#0xfc
      002268 F5 81            [12] 6921 	mov	sp,a
      00226A E5 08            [12] 6922 	mov	a,_bp
      00226C 24 10            [12] 6923 	add	a,#0x10
      00226E F8               [12] 6924 	mov	r0,a
      00226F E6               [12] 6925 	mov	a,@r0
      002270 C0 E0            [24] 6926 	push	acc
      002272 08               [12] 6927 	inc	r0
      002273 E6               [12] 6928 	mov	a,@r0
      002274 C0 E0            [24] 6929 	push	acc
      002276 08               [12] 6930 	inc	r0
      002277 E6               [12] 6931 	mov	a,@r0
      002278 C0 E0            [24] 6932 	push	acc
      00227A 08               [12] 6933 	inc	r0
      00227B E6               [12] 6934 	mov	a,@r0
      00227C C0 E0            [24] 6935 	push	acc
                           0021C1  6936 	C$fuzzy.h$2402$1_0$112 ==.
                                   6937 ;	../../fuzzy.h:2402: ) {
      00227E E5 08            [12] 6938 	mov	a,_bp
      002280 24 08            [12] 6939 	add	a,#0x08
      002282 F8               [12] 6940 	mov	r0,a
      002283 86 82            [24] 6941 	mov	dpl, @r0
      002285 08               [12] 6942 	inc	r0
      002286 86 83            [24] 6943 	mov	dph, @r0
      002288 08               [12] 6944 	inc	r0
      002289 86 F0            [24] 6945 	mov	b, @r0
      00228B 08               [12] 6946 	inc	r0
      00228C E6               [12] 6947 	mov	a, @r0
      00228D 12 41 CE         [24] 6948 	lcall	___fsadd
      002290 C8               [12] 6949 	xch	a,r0
      002291 E5 08            [12] 6950 	mov	a,_bp
      002293 24 08            [12] 6951 	add	a,#0x08
      002295 C8               [12] 6952 	xch	a,r0
      002296 A6 82            [24] 6953 	mov	@r0, dpl
      002298 08               [12] 6954 	inc	r0
      002299 A6 83            [24] 6955 	mov	@r0, dph
      00229B 08               [12] 6956 	inc	r0
      00229C A6 F0            [24] 6957 	mov	@r0, b
      00229E 08               [12] 6958 	inc	r0
      00229F F6               [12] 6959 	mov	@r0,a
      0022A0 E5 81            [12] 6960 	mov	a,sp
      0022A2 24 FC            [12] 6961 	add	a,#0xfc
      0022A4 F5 81            [12] 6962 	mov	sp,a
      0022A6 E5 08            [12] 6963 	mov	a,_bp
      0022A8 24 F2            [12] 6964 	add	a,#0xf2
      0022AA F8               [12] 6965 	mov	r0,a
      0022AB E6               [12] 6966 	mov	a,@r0
      0022AC C0 E0            [24] 6967 	push	acc
      0022AE 08               [12] 6968 	inc	r0
      0022AF E6               [12] 6969 	mov	a,@r0
      0022B0 C0 E0            [24] 6970 	push	acc
      0022B2 08               [12] 6971 	inc	r0
      0022B3 E6               [12] 6972 	mov	a,@r0
      0022B4 C0 E0            [24] 6973 	push	acc
      0022B6 08               [12] 6974 	inc	r0
      0022B7 E6               [12] 6975 	mov	a,@r0
      0022B8 C0 E0            [24] 6976 	push	acc
      0022BA E5 08            [12] 6977 	mov	a,_bp
      0022BC 24 0C            [12] 6978 	add	a,#0x0c
      0022BE F8               [12] 6979 	mov	r0,a
      0022BF 86 82            [24] 6980 	mov	dpl, @r0
      0022C1 08               [12] 6981 	inc	r0
      0022C2 86 83            [24] 6982 	mov	dph, @r0
      0022C4 08               [12] 6983 	inc	r0
      0022C5 86 F0            [24] 6984 	mov	b, @r0
      0022C7 08               [12] 6985 	inc	r0
      0022C8 E6               [12] 6986 	mov	a, @r0
      0022C9 12 41 CE         [24] 6987 	lcall	___fsadd
      0022CC C8               [12] 6988 	xch	a,r0
      0022CD E5 08            [12] 6989 	mov	a,_bp
      0022CF 24 0C            [12] 6990 	add	a,#0x0c
      0022D1 C8               [12] 6991 	xch	a,r0
      0022D2 A6 82            [24] 6992 	mov	@r0, dpl
      0022D4 08               [12] 6993 	inc	r0
      0022D5 A6 83            [24] 6994 	mov	@r0, dph
      0022D7 08               [12] 6995 	inc	r0
      0022D8 A6 F0            [24] 6996 	mov	@r0, b
      0022DA 08               [12] 6997 	inc	r0
      0022DB F6               [12] 6998 	mov	@r0,a
      0022DC E5 81            [12] 6999 	mov	a,sp
      0022DE 24 FC            [12] 7000 	add	a,#0xfc
      0022E0 F5 81            [12] 7001 	mov	sp,a
      0022E2 02 21 88         [24] 7002 	ljmp	00105$
      0022E5                       7003 00101$:
                           002228  7004 	C$fuzzy.h$2419$1_0$112 ==.
                                   7005 ;	../../fuzzy.h:2419: if (height_sum <= LEVEL_LO) {
      0022E5 E5 08            [12] 7006 	mov	a,_bp
      0022E7 24 08            [12] 7007 	add	a,#0x08
      0022E9 F8               [12] 7008 	mov	r0,a
      0022EA E6               [12] 7009 	mov	a,@r0
      0022EB C0 E0            [24] 7010 	push	acc
      0022ED 08               [12] 7011 	inc	r0
      0022EE E6               [12] 7012 	mov	a,@r0
      0022EF C0 E0            [24] 7013 	push	acc
      0022F1 08               [12] 7014 	inc	r0
      0022F2 E6               [12] 7015 	mov	a,@r0
      0022F3 C0 E0            [24] 7016 	push	acc
      0022F5 08               [12] 7017 	inc	r0
      0022F6 E6               [12] 7018 	mov	a,@r0
      0022F7 C0 E0            [24] 7019 	push	acc
      0022F9 90 00 00         [24] 7020 	mov	dptr,#0x0000
      0022FC E4               [12] 7021 	clr	a
      0022FD F5 F0            [12] 7022 	mov	b,a
      0022FF 12 41 7C         [24] 7023 	lcall	___fslt
      002302 E5 81            [12] 7024 	mov	a,sp
      002304 24 FC            [12] 7025 	add	a,#0xfc
      002306 F5 81            [12] 7026 	mov	sp,a
      002308 E5 82            [12] 7027 	mov	a, dpl
      00230A 24 FF            [12] 7028 	add	a,#0xff
      00230C 92 00            [24] 7029 	mov	b0,c
      00230E 40 08            [24] 7030 	jc	00103$
                           002253  7031 	C$fuzzy.h$2420$2_0$115 ==.
                                   7032 ;	../../fuzzy.h:2420: return 0.0f;
      002310 90 00 00         [24] 7033 	mov	dptr,#0x0000
      002313 E4               [12] 7034 	clr	a
      002314 F5 F0            [12] 7035 	mov	b,a
      002316 80 3A            [24] 7036 	sjmp	00107$
      002318                       7037 00103$:
                           00225B  7038 	C$fuzzy.h$2424$1_0$112 ==.
                                   7039 ;	../../fuzzy.h:2424: height_sum;
      002318 E5 08            [12] 7040 	mov	a,_bp
      00231A 24 08            [12] 7041 	add	a,#0x08
      00231C F8               [12] 7042 	mov	r0,a
      00231D E6               [12] 7043 	mov	a,@r0
      00231E C0 E0            [24] 7044 	push	acc
      002320 08               [12] 7045 	inc	r0
      002321 E6               [12] 7046 	mov	a,@r0
      002322 C0 E0            [24] 7047 	push	acc
      002324 08               [12] 7048 	inc	r0
      002325 E6               [12] 7049 	mov	a,@r0
      002326 C0 E0            [24] 7050 	push	acc
      002328 08               [12] 7051 	inc	r0
      002329 E6               [12] 7052 	mov	a,@r0
      00232A C0 E0            [24] 7053 	push	acc
      00232C E5 08            [12] 7054 	mov	a,_bp
      00232E 24 04            [12] 7055 	add	a,#0x04
      002330 F8               [12] 7056 	mov	r0,a
      002331 86 82            [24] 7057 	mov	dpl, @r0
      002333 08               [12] 7058 	inc	r0
      002334 86 83            [24] 7059 	mov	dph, @r0
      002336 08               [12] 7060 	inc	r0
      002337 86 F0            [24] 7061 	mov	b, @r0
      002339 08               [12] 7062 	inc	r0
      00233A E6               [12] 7063 	mov	a, @r0
      00233B 12 42 E5         [24] 7064 	lcall	___fsdiv
      00233E AC 82            [24] 7065 	mov	r4, dpl
      002340 AD 83            [24] 7066 	mov	r5, dph
      002342 AE F0            [24] 7067 	mov	r6, b
      002344 FF               [12] 7068 	mov	r7, a
      002345 E5 81            [12] 7069 	mov	a,sp
      002347 24 FC            [12] 7070 	add	a,#0xfc
      002349 F5 81            [12] 7071 	mov	sp,a
      00234B 8C 82            [24] 7072 	mov	dpl, r4
      00234D 8D 83            [24] 7073 	mov	dph, r5
      00234F 8E F0            [24] 7074 	mov	b, r6
      002351 EF               [12] 7075 	mov	a, r7
      002352                       7076 00107$:
                           002295  7077 	C$fuzzy.h$2425$1_0$112 ==.
                                   7078 ;	../../fuzzy.h:2425: }
      002352 85 08 81         [24] 7079 	mov	sp,_bp
      002355 D0 08            [24] 7080 	pop	_bp
                           00229A  7081 	C$fuzzy.h$2425$1_0$112 ==.
                           00229A  7082 	XG$fuzzy_rules_defuzzify_cog$0$0 ==.
      002357 22               [24] 7083 	ret
                                   7084 ;------------------------------------------------------------
                                   7085 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_boa'
                                   7086 ;------------------------------------------------------------
                                   7087 ;lower         Allocated to stack - _bp -6 +4 
                                   7088 ;upper         Allocated to stack - _bp -10 +4 
                                   7089 ;step          Allocated to stack - _bp -14 +4 
                                   7090 ;implication_method Allocated to stack - _bp -15 +1 
                                   7091 ;aggregation_method Allocated to stack - _bp -16 +1 
                                   7092 ;rules         Allocated to stack - _bp +1 +3 
                                   7093 ;total_area    Allocated to stack - _bp +8 +4 
                                   7094 ;half_area     Allocated to stack - _bp +12 +4 
                                   7095 ;accumulated_area Allocated to stack - _bp +16 +4 
                                   7096 ;value         Allocated to stack - _bp +20 +4 
                                   7097 ;sloc0         Allocated to stack - _bp +4 +4 
                                   7098 ;------------------------------------------------------------
                           00229B  7099 	G$fuzzy_rules_defuzzify_boa$0$0 ==.
                           00229B  7100 	C$fuzzy.h$2435$1_0$117 ==.
                                   7101 ;	../../fuzzy.h:2435: float fuzzy_rules_defuzzify_boa(
                                   7102 ;	-----------------------------------------
                                   7103 ;	 function fuzzy_rules_defuzzify_boa
                                   7104 ;	-----------------------------------------
      002358                       7105 _fuzzy_rules_defuzzify_boa:
      002358 C0 08            [24] 7106 	push	_bp
      00235A 85 81 08         [24] 7107 	mov	_bp,sp
      00235D C0 82            [24] 7108 	push	dpl
      00235F C0 83            [24] 7109 	push	dph
      002361 C0 F0            [24] 7110 	push	b
      002363 E5 81            [12] 7111 	mov	a,sp
      002365 24 14            [12] 7112 	add	a,#0x14
      002367 F5 81            [12] 7113 	mov	sp,a
                           0022AC  7114 	C$fuzzy.h$2450$1_0$117 ==.
                                   7115 ;	../../fuzzy.h:2450: 0.0f;
      002369 E5 08            [12] 7116 	mov	a,_bp
      00236B 24 08            [12] 7117 	add	a,#0x08
      00236D F8               [12] 7118 	mov	r0,a
      00236E E4               [12] 7119 	clr	a
      00236F F6               [12] 7120 	mov	@r0,a
      002370 08               [12] 7121 	inc	r0
      002371 F6               [12] 7122 	mov	@r0,a
      002372 08               [12] 7123 	inc	r0
      002373 F6               [12] 7124 	mov	@r0,a
      002374 08               [12] 7125 	inc	r0
      002375 F6               [12] 7126 	mov	@r0,a
                           0022B9  7127 	C$fuzzy.h$2453$2_0$118 ==.
                                   7128 ;	../../fuzzy.h:2453: value = lower;
      002376 E5 08            [12] 7129 	mov	a,_bp
      002378 24 FA            [12] 7130 	add	a,#0xfa
      00237A F8               [12] 7131 	mov	r0,a
      00237B E5 08            [12] 7132 	mov	a,_bp
      00237D 24 04            [12] 7133 	add	a,#0x04
      00237F F9               [12] 7134 	mov	r1,a
      002380 E6               [12] 7135 	mov	a,@r0
      002381 F7               [12] 7136 	mov	@r1,a
      002382 08               [12] 7137 	inc	r0
      002383 E6               [12] 7138 	mov	a,@r0
      002384 09               [12] 7139 	inc	r1
      002385 F7               [12] 7140 	mov	@r1,a
      002386 08               [12] 7141 	inc	r0
      002387 E6               [12] 7142 	mov	a,@r0
      002388 09               [12] 7143 	inc	r1
      002389 F7               [12] 7144 	mov	@r1,a
      00238A 08               [12] 7145 	inc	r0
      00238B E6               [12] 7146 	mov	a,@r0
      00238C 09               [12] 7147 	inc	r1
      00238D F7               [12] 7148 	mov	@r1,a
      00238E                       7149 00108$:
                           0022D1  7150 	C$fuzzy.h$2454$1_0$117 ==.
                                   7151 ;	../../fuzzy.h:2454: value <= upper;
      00238E E5 08            [12] 7152 	mov	a,_bp
      002390 24 04            [12] 7153 	add	a,#0x04
      002392 F8               [12] 7154 	mov	r0,a
      002393 E6               [12] 7155 	mov	a,@r0
      002394 C0 E0            [24] 7156 	push	acc
      002396 08               [12] 7157 	inc	r0
      002397 E6               [12] 7158 	mov	a,@r0
      002398 C0 E0            [24] 7159 	push	acc
      00239A 08               [12] 7160 	inc	r0
      00239B E6               [12] 7161 	mov	a,@r0
      00239C C0 E0            [24] 7162 	push	acc
      00239E 08               [12] 7163 	inc	r0
      00239F E6               [12] 7164 	mov	a,@r0
      0023A0 C0 E0            [24] 7165 	push	acc
      0023A2 E5 08            [12] 7166 	mov	a,_bp
      0023A4 24 F6            [12] 7167 	add	a,#0xf6
      0023A6 F8               [12] 7168 	mov	r0,a
      0023A7 86 82            [24] 7169 	mov	dpl, @r0
      0023A9 08               [12] 7170 	inc	r0
      0023AA 86 83            [24] 7171 	mov	dph, @r0
      0023AC 08               [12] 7172 	inc	r0
      0023AD 86 F0            [24] 7173 	mov	b, @r0
      0023AF 08               [12] 7174 	inc	r0
      0023B0 E6               [12] 7175 	mov	a, @r0
      0023B1 12 41 7C         [24] 7176 	lcall	___fslt
      0023B4 E5 81            [12] 7177 	mov	a,sp
      0023B6 24 FC            [12] 7178 	add	a,#0xfc
      0023B8 F5 81            [12] 7179 	mov	sp,a
      0023BA E5 82            [12] 7180 	mov	a, dpl
      0023BC 24 FF            [12] 7181 	add	a,#0xff
      0023BE 92 00            [24] 7182 	mov	b0,c
      0023C0 50 03            [24] 7183 	jnc	00157$
      0023C2 02 24 73         [24] 7184 	ljmp	00101$
      0023C5                       7185 00157$:
                           002308  7186 	C$fuzzy.h$2459$3_0$119 ==.
                                   7187 ;	../../fuzzy.h:2459: rules,
      0023C5 E5 08            [12] 7188 	mov	a,_bp
      0023C7 24 F0            [12] 7189 	add	a,#0xf0
      0023C9 F8               [12] 7190 	mov	r0,a
      0023CA E6               [12] 7191 	mov	a,@r0
      0023CB C0 E0            [24] 7192 	push	acc
      0023CD E5 08            [12] 7193 	mov	a,_bp
      0023CF 24 F1            [12] 7194 	add	a,#0xf1
      0023D1 F8               [12] 7195 	mov	r0,a
      0023D2 E6               [12] 7196 	mov	a,@r0
      0023D3 C0 E0            [24] 7197 	push	acc
      0023D5 E5 08            [12] 7198 	mov	a,_bp
      0023D7 24 04            [12] 7199 	add	a,#0x04
      0023D9 F8               [12] 7200 	mov	r0,a
      0023DA E6               [12] 7201 	mov	a,@r0
      0023DB C0 E0            [24] 7202 	push	acc
      0023DD 08               [12] 7203 	inc	r0
      0023DE E6               [12] 7204 	mov	a,@r0
      0023DF C0 E0            [24] 7205 	push	acc
      0023E1 08               [12] 7206 	inc	r0
      0023E2 E6               [12] 7207 	mov	a,@r0
      0023E3 C0 E0            [24] 7208 	push	acc
      0023E5 08               [12] 7209 	inc	r0
      0023E6 E6               [12] 7210 	mov	a,@r0
      0023E7 C0 E0            [24] 7211 	push	acc
      0023E9 A8 08            [24] 7212 	mov	r0,_bp
      0023EB 08               [12] 7213 	inc	r0
      0023EC 86 82            [24] 7214 	mov	dpl, @r0
      0023EE 08               [12] 7215 	inc	r0
      0023EF 86 83            [24] 7216 	mov	dph, @r0
      0023F1 08               [12] 7217 	inc	r0
      0023F2 86 F0            [24] 7218 	mov	b, @r0
      0023F4 12 1B 9E         [24] 7219 	lcall	_fuzzy_rules_aggregated_height
      0023F7 AC 82            [24] 7220 	mov	r4, dpl
      0023F9 AD 83            [24] 7221 	mov	r5, dph
      0023FB AE F0            [24] 7222 	mov	r6, b
      0023FD FF               [12] 7223 	mov	r7, a
      0023FE E5 81            [12] 7224 	mov	a,sp
      002400 24 FA            [12] 7225 	add	a,#0xfa
      002402 F5 81            [12] 7226 	mov	sp,a
      002404 C0 04            [24] 7227 	push	ar4
      002406 C0 05            [24] 7228 	push	ar5
      002408 C0 06            [24] 7229 	push	ar6
      00240A C0 07            [24] 7230 	push	ar7
                           00234F  7231 	C$fuzzy.h$2456$1_0$117 ==.
                                   7232 ;	../../fuzzy.h:2456: ) {
      00240C E5 08            [12] 7233 	mov	a,_bp
      00240E 24 08            [12] 7234 	add	a,#0x08
      002410 F8               [12] 7235 	mov	r0,a
      002411 86 82            [24] 7236 	mov	dpl, @r0
      002413 08               [12] 7237 	inc	r0
      002414 86 83            [24] 7238 	mov	dph, @r0
      002416 08               [12] 7239 	inc	r0
      002417 86 F0            [24] 7240 	mov	b, @r0
      002419 08               [12] 7241 	inc	r0
      00241A E6               [12] 7242 	mov	a, @r0
      00241B 12 41 CE         [24] 7243 	lcall	___fsadd
      00241E C8               [12] 7244 	xch	a,r0
      00241F E5 08            [12] 7245 	mov	a,_bp
      002421 24 08            [12] 7246 	add	a,#0x08
      002423 C8               [12] 7247 	xch	a,r0
      002424 A6 82            [24] 7248 	mov	@r0, dpl
      002426 08               [12] 7249 	inc	r0
      002427 A6 83            [24] 7250 	mov	@r0, dph
      002429 08               [12] 7251 	inc	r0
      00242A A6 F0            [24] 7252 	mov	@r0, b
      00242C 08               [12] 7253 	inc	r0
      00242D F6               [12] 7254 	mov	@r0,a
      00242E E5 81            [12] 7255 	mov	a,sp
      002430 24 FC            [12] 7256 	add	a,#0xfc
      002432 F5 81            [12] 7257 	mov	sp,a
      002434 E5 08            [12] 7258 	mov	a,_bp
      002436 24 F2            [12] 7259 	add	a,#0xf2
      002438 F8               [12] 7260 	mov	r0,a
      002439 E6               [12] 7261 	mov	a,@r0
      00243A C0 E0            [24] 7262 	push	acc
      00243C 08               [12] 7263 	inc	r0
      00243D E6               [12] 7264 	mov	a,@r0
      00243E C0 E0            [24] 7265 	push	acc
      002440 08               [12] 7266 	inc	r0
      002441 E6               [12] 7267 	mov	a,@r0
      002442 C0 E0            [24] 7268 	push	acc
      002444 08               [12] 7269 	inc	r0
      002445 E6               [12] 7270 	mov	a,@r0
      002446 C0 E0            [24] 7271 	push	acc
      002448 E5 08            [12] 7272 	mov	a,_bp
      00244A 24 04            [12] 7273 	add	a,#0x04
      00244C F8               [12] 7274 	mov	r0,a
      00244D 86 82            [24] 7275 	mov	dpl, @r0
      00244F 08               [12] 7276 	inc	r0
      002450 86 83            [24] 7277 	mov	dph, @r0
      002452 08               [12] 7278 	inc	r0
      002453 86 F0            [24] 7279 	mov	b, @r0
      002455 08               [12] 7280 	inc	r0
      002456 E6               [12] 7281 	mov	a, @r0
      002457 12 41 CE         [24] 7282 	lcall	___fsadd
      00245A C8               [12] 7283 	xch	a,r0
      00245B E5 08            [12] 7284 	mov	a,_bp
      00245D 24 04            [12] 7285 	add	a,#0x04
      00245F C8               [12] 7286 	xch	a,r0
      002460 A6 82            [24] 7287 	mov	@r0, dpl
      002462 08               [12] 7288 	inc	r0
      002463 A6 83            [24] 7289 	mov	@r0, dph
      002465 08               [12] 7290 	inc	r0
      002466 A6 F0            [24] 7291 	mov	@r0, b
      002468 08               [12] 7292 	inc	r0
      002469 F6               [12] 7293 	mov	@r0,a
      00246A E5 81            [12] 7294 	mov	a,sp
      00246C 24 FC            [12] 7295 	add	a,#0xfc
      00246E F5 81            [12] 7296 	mov	sp,a
      002470 02 23 8E         [24] 7297 	ljmp	00108$
      002473                       7298 00101$:
                           0023B6  7299 	C$fuzzy.h$2466$1_0$117 ==.
                                   7300 ;	../../fuzzy.h:2466: if (total_area <= LEVEL_LO) {
      002473 E5 08            [12] 7301 	mov	a,_bp
      002475 24 08            [12] 7302 	add	a,#0x08
      002477 F8               [12] 7303 	mov	r0,a
      002478 E6               [12] 7304 	mov	a,@r0
      002479 C0 E0            [24] 7305 	push	acc
      00247B 08               [12] 7306 	inc	r0
      00247C E6               [12] 7307 	mov	a,@r0
      00247D C0 E0            [24] 7308 	push	acc
      00247F 08               [12] 7309 	inc	r0
      002480 E6               [12] 7310 	mov	a,@r0
      002481 C0 E0            [24] 7311 	push	acc
      002483 08               [12] 7312 	inc	r0
      002484 E6               [12] 7313 	mov	a,@r0
      002485 C0 E0            [24] 7314 	push	acc
      002487 90 00 00         [24] 7315 	mov	dptr,#0x0000
      00248A E4               [12] 7316 	clr	a
      00248B F5 F0            [12] 7317 	mov	b,a
      00248D 12 41 7C         [24] 7318 	lcall	___fslt
      002490 E5 81            [12] 7319 	mov	a,sp
      002492 24 FC            [12] 7320 	add	a,#0xfc
      002494 F5 81            [12] 7321 	mov	sp,a
      002496 E5 82            [12] 7322 	mov	a, dpl
      002498 24 FF            [12] 7323 	add	a,#0xff
      00249A 92 00            [24] 7324 	mov	b0,c
      00249C 40 09            [24] 7325 	jc	00103$
                           0023E1  7326 	C$fuzzy.h$2467$2_0$120 ==.
                                   7327 ;	../../fuzzy.h:2467: return 0.0f;
      00249E 90 00 00         [24] 7328 	mov	dptr,#0x0000
      0024A1 E4               [12] 7329 	clr	a
      0024A2 F5 F0            [12] 7330 	mov	b,a
      0024A4 02 26 38         [24] 7331 	ljmp	00113$
      0024A7                       7332 00103$:
                           0023EA  7333 	C$fuzzy.h$2472$1_0$117 ==.
                                   7334 ;	../../fuzzy.h:2472: 2.0f;
      0024A7 E4               [12] 7335 	clr	a
      0024A8 C0 E0            [24] 7336 	push	acc
      0024AA C0 E0            [24] 7337 	push	acc
      0024AC C0 E0            [24] 7338 	push	acc
      0024AE 74 40            [12] 7339 	mov	a,#0x40
      0024B0 C0 E0            [24] 7340 	push	acc
                           0023F5  7341 	C$fuzzy.h$2475$1_0$117 ==.
                                   7342 ;	../../fuzzy.h:2475: 0.0f;
      0024B2 E5 08            [12] 7343 	mov	a,_bp
      0024B4 24 08            [12] 7344 	add	a,#0x08
      0024B6 F8               [12] 7345 	mov	r0,a
      0024B7 86 82            [24] 7346 	mov	dpl, @r0
      0024B9 08               [12] 7347 	inc	r0
      0024BA 86 83            [24] 7348 	mov	dph, @r0
      0024BC 08               [12] 7349 	inc	r0
      0024BD 86 F0            [24] 7350 	mov	b, @r0
      0024BF 08               [12] 7351 	inc	r0
      0024C0 E6               [12] 7352 	mov	a, @r0
      0024C1 12 42 E5         [24] 7353 	lcall	___fsdiv
      0024C4 C8               [12] 7354 	xch	a,r0
      0024C5 E5 08            [12] 7355 	mov	a,_bp
      0024C7 24 0C            [12] 7356 	add	a,#0x0c
      0024C9 C8               [12] 7357 	xch	a,r0
      0024CA A6 82            [24] 7358 	mov	@r0, dpl
      0024CC 08               [12] 7359 	inc	r0
      0024CD A6 83            [24] 7360 	mov	@r0, dph
      0024CF 08               [12] 7361 	inc	r0
      0024D0 A6 F0            [24] 7362 	mov	@r0, b
      0024D2 08               [12] 7363 	inc	r0
      0024D3 F6               [12] 7364 	mov	@r0,a
      0024D4 E5 81            [12] 7365 	mov	a,sp
      0024D6 24 FC            [12] 7366 	add	a,#0xfc
      0024D8 F5 81            [12] 7367 	mov	sp,a
      0024DA E5 08            [12] 7368 	mov	a,_bp
      0024DC 24 10            [12] 7369 	add	a,#0x10
      0024DE F8               [12] 7370 	mov	r0,a
      0024DF E4               [12] 7371 	clr	a
      0024E0 F6               [12] 7372 	mov	@r0,a
      0024E1 08               [12] 7373 	inc	r0
      0024E2 F6               [12] 7374 	mov	@r0,a
      0024E3 08               [12] 7375 	inc	r0
      0024E4 F6               [12] 7376 	mov	@r0,a
      0024E5 08               [12] 7377 	inc	r0
      0024E6 F6               [12] 7378 	mov	@r0,a
                           00242A  7379 	C$fuzzy.h$2478$2_0$121 ==.
                                   7380 ;	../../fuzzy.h:2478: value = lower;
      0024E7 E5 08            [12] 7381 	mov	a,_bp
      0024E9 24 FA            [12] 7382 	add	a,#0xfa
      0024EB F8               [12] 7383 	mov	r0,a
      0024EC E5 08            [12] 7384 	mov	a,_bp
      0024EE 24 14            [12] 7385 	add	a,#0x14
      0024F0 F9               [12] 7386 	mov	r1,a
      0024F1 E6               [12] 7387 	mov	a,@r0
      0024F2 F7               [12] 7388 	mov	@r1,a
      0024F3 08               [12] 7389 	inc	r0
      0024F4 E6               [12] 7390 	mov	a,@r0
      0024F5 09               [12] 7391 	inc	r1
      0024F6 F7               [12] 7392 	mov	@r1,a
      0024F7 08               [12] 7393 	inc	r0
      0024F8 E6               [12] 7394 	mov	a,@r0
      0024F9 09               [12] 7395 	inc	r1
      0024FA F7               [12] 7396 	mov	@r1,a
      0024FB 08               [12] 7397 	inc	r0
      0024FC E6               [12] 7398 	mov	a,@r0
      0024FD 09               [12] 7399 	inc	r1
      0024FE F7               [12] 7400 	mov	@r1,a
      0024FF                       7401 00111$:
                           002442  7402 	C$fuzzy.h$2479$1_0$117 ==.
                                   7403 ;	../../fuzzy.h:2479: value <= upper;
      0024FF E5 08            [12] 7404 	mov	a,_bp
      002501 24 14            [12] 7405 	add	a,#0x14
      002503 F8               [12] 7406 	mov	r0,a
      002504 E6               [12] 7407 	mov	a,@r0
      002505 C0 E0            [24] 7408 	push	acc
      002507 08               [12] 7409 	inc	r0
      002508 E6               [12] 7410 	mov	a,@r0
      002509 C0 E0            [24] 7411 	push	acc
      00250B 08               [12] 7412 	inc	r0
      00250C E6               [12] 7413 	mov	a,@r0
      00250D C0 E0            [24] 7414 	push	acc
      00250F 08               [12] 7415 	inc	r0
      002510 E6               [12] 7416 	mov	a,@r0
      002511 C0 E0            [24] 7417 	push	acc
      002513 E5 08            [12] 7418 	mov	a,_bp
      002515 24 F6            [12] 7419 	add	a,#0xf6
      002517 F8               [12] 7420 	mov	r0,a
      002518 86 82            [24] 7421 	mov	dpl, @r0
      00251A 08               [12] 7422 	inc	r0
      00251B 86 83            [24] 7423 	mov	dph, @r0
      00251D 08               [12] 7424 	inc	r0
      00251E 86 F0            [24] 7425 	mov	b, @r0
      002520 08               [12] 7426 	inc	r0
      002521 E6               [12] 7427 	mov	a, @r0
      002522 12 41 7C         [24] 7428 	lcall	___fslt
      002525 E5 81            [12] 7429 	mov	a,sp
      002527 24 FC            [12] 7430 	add	a,#0xfc
      002529 F5 81            [12] 7431 	mov	sp,a
      00252B E5 82            [12] 7432 	mov	a, dpl
      00252D 24 FF            [12] 7433 	add	a,#0xff
      00252F 92 00            [24] 7434 	mov	b0,c
      002531 50 03            [24] 7435 	jnc	00159$
      002533 02 26 29         [24] 7436 	ljmp	00106$
      002536                       7437 00159$:
                           002479  7438 	C$fuzzy.h$2484$3_0$122 ==.
                                   7439 ;	../../fuzzy.h:2484: rules,
      002536 E5 08            [12] 7440 	mov	a,_bp
      002538 24 F0            [12] 7441 	add	a,#0xf0
      00253A F8               [12] 7442 	mov	r0,a
      00253B E6               [12] 7443 	mov	a,@r0
      00253C C0 E0            [24] 7444 	push	acc
      00253E E5 08            [12] 7445 	mov	a,_bp
      002540 24 F1            [12] 7446 	add	a,#0xf1
      002542 F8               [12] 7447 	mov	r0,a
      002543 E6               [12] 7448 	mov	a,@r0
      002544 C0 E0            [24] 7449 	push	acc
      002546 E5 08            [12] 7450 	mov	a,_bp
      002548 24 14            [12] 7451 	add	a,#0x14
      00254A F8               [12] 7452 	mov	r0,a
      00254B E6               [12] 7453 	mov	a,@r0
      00254C C0 E0            [24] 7454 	push	acc
      00254E 08               [12] 7455 	inc	r0
      00254F E6               [12] 7456 	mov	a,@r0
      002550 C0 E0            [24] 7457 	push	acc
      002552 08               [12] 7458 	inc	r0
      002553 E6               [12] 7459 	mov	a,@r0
      002554 C0 E0            [24] 7460 	push	acc
      002556 08               [12] 7461 	inc	r0
      002557 E6               [12] 7462 	mov	a,@r0
      002558 C0 E0            [24] 7463 	push	acc
      00255A A8 08            [24] 7464 	mov	r0,_bp
      00255C 08               [12] 7465 	inc	r0
      00255D 86 82            [24] 7466 	mov	dpl, @r0
      00255F 08               [12] 7467 	inc	r0
      002560 86 83            [24] 7468 	mov	dph, @r0
      002562 08               [12] 7469 	inc	r0
      002563 86 F0            [24] 7470 	mov	b, @r0
      002565 12 1B 9E         [24] 7471 	lcall	_fuzzy_rules_aggregated_height
      002568 AA 82            [24] 7472 	mov	r2, dpl
      00256A AB 83            [24] 7473 	mov	r3, dph
      00256C AE F0            [24] 7474 	mov	r6, b
      00256E FF               [12] 7475 	mov	r7, a
      00256F E5 81            [12] 7476 	mov	a,sp
      002571 24 FA            [12] 7477 	add	a,#0xfa
      002573 F5 81            [12] 7478 	mov	sp,a
      002575 C0 02            [24] 7479 	push	ar2
      002577 C0 03            [24] 7480 	push	ar3
      002579 C0 06            [24] 7481 	push	ar6
      00257B C0 07            [24] 7482 	push	ar7
                           0024C0  7483 	C$fuzzy.h$2493$1_0$117 ==.
                                   7484 ;	../../fuzzy.h:2493: ) {
      00257D E5 08            [12] 7485 	mov	a,_bp
      00257F 24 10            [12] 7486 	add	a,#0x10
      002581 F8               [12] 7487 	mov	r0,a
      002582 86 82            [24] 7488 	mov	dpl, @r0
      002584 08               [12] 7489 	inc	r0
      002585 86 83            [24] 7490 	mov	dph, @r0
      002587 08               [12] 7491 	inc	r0
      002588 86 F0            [24] 7492 	mov	b, @r0
      00258A 08               [12] 7493 	inc	r0
      00258B E6               [12] 7494 	mov	a, @r0
      00258C 12 41 CE         [24] 7495 	lcall	___fsadd
      00258F C8               [12] 7496 	xch	a,r0
      002590 E5 08            [12] 7497 	mov	a,_bp
      002592 24 10            [12] 7498 	add	a,#0x10
      002594 C8               [12] 7499 	xch	a,r0
      002595 A6 82            [24] 7500 	mov	@r0, dpl
      002597 08               [12] 7501 	inc	r0
      002598 A6 83            [24] 7502 	mov	@r0, dph
      00259A 08               [12] 7503 	inc	r0
      00259B A6 F0            [24] 7504 	mov	@r0, b
      00259D 08               [12] 7505 	inc	r0
      00259E F6               [12] 7506 	mov	@r0,a
      00259F E5 81            [12] 7507 	mov	a,sp
      0025A1 24 FC            [12] 7508 	add	a,#0xfc
      0025A3 F5 81            [12] 7509 	mov	sp,a
      0025A5 E5 08            [12] 7510 	mov	a,_bp
      0025A7 24 0C            [12] 7511 	add	a,#0x0c
      0025A9 F8               [12] 7512 	mov	r0,a
      0025AA E6               [12] 7513 	mov	a,@r0
      0025AB C0 E0            [24] 7514 	push	acc
      0025AD 08               [12] 7515 	inc	r0
      0025AE E6               [12] 7516 	mov	a,@r0
      0025AF C0 E0            [24] 7517 	push	acc
      0025B1 08               [12] 7518 	inc	r0
      0025B2 E6               [12] 7519 	mov	a,@r0
      0025B3 C0 E0            [24] 7520 	push	acc
      0025B5 08               [12] 7521 	inc	r0
      0025B6 E6               [12] 7522 	mov	a,@r0
      0025B7 C0 E0            [24] 7523 	push	acc
      0025B9 E5 08            [12] 7524 	mov	a,_bp
      0025BB 24 10            [12] 7525 	add	a,#0x10
      0025BD F8               [12] 7526 	mov	r0,a
      0025BE 86 82            [24] 7527 	mov	dpl, @r0
      0025C0 08               [12] 7528 	inc	r0
      0025C1 86 83            [24] 7529 	mov	dph, @r0
      0025C3 08               [12] 7530 	inc	r0
      0025C4 86 F0            [24] 7531 	mov	b, @r0
      0025C6 08               [12] 7532 	inc	r0
      0025C7 E6               [12] 7533 	mov	a, @r0
      0025C8 12 41 7C         [24] 7534 	lcall	___fslt
      0025CB E5 81            [12] 7535 	mov	a,sp
      0025CD 24 FC            [12] 7536 	add	a,#0xfc
      0025CF F5 81            [12] 7537 	mov	sp,a
      0025D1 E5 82            [12] 7538 	mov	a, dpl
      0025D3 24 FF            [12] 7539 	add	a,#0xff
      0025D5 92 00            [24] 7540 	mov	b0,c
      0025D7 40 11            [24] 7541 	jc	00112$
                           00251C  7542 	C$fuzzy.h$2494$4_0$123 ==.
                                   7543 ;	../../fuzzy.h:2494: return value;
      0025D9 E5 08            [12] 7544 	mov	a,_bp
      0025DB 24 14            [12] 7545 	add	a,#0x14
      0025DD F8               [12] 7546 	mov	r0,a
      0025DE 86 82            [24] 7547 	mov	dpl, @r0
      0025E0 08               [12] 7548 	inc	r0
      0025E1 86 83            [24] 7549 	mov	dph, @r0
      0025E3 08               [12] 7550 	inc	r0
      0025E4 86 F0            [24] 7551 	mov	b, @r0
      0025E6 08               [12] 7552 	inc	r0
      0025E7 E6               [12] 7553 	mov	a, @r0
      0025E8 80 4E            [24] 7554 	sjmp	00113$
      0025EA                       7555 00112$:
                           00252D  7556 	C$fuzzy.h$2481$1_0$117 ==.
                                   7557 ;	../../fuzzy.h:2481: ) {
      0025EA E5 08            [12] 7558 	mov	a,_bp
      0025EC 24 F2            [12] 7559 	add	a,#0xf2
      0025EE F8               [12] 7560 	mov	r0,a
      0025EF E6               [12] 7561 	mov	a,@r0
      0025F0 C0 E0            [24] 7562 	push	acc
      0025F2 08               [12] 7563 	inc	r0
      0025F3 E6               [12] 7564 	mov	a,@r0
      0025F4 C0 E0            [24] 7565 	push	acc
      0025F6 08               [12] 7566 	inc	r0
      0025F7 E6               [12] 7567 	mov	a,@r0
      0025F8 C0 E0            [24] 7568 	push	acc
      0025FA 08               [12] 7569 	inc	r0
      0025FB E6               [12] 7570 	mov	a,@r0
      0025FC C0 E0            [24] 7571 	push	acc
      0025FE E5 08            [12] 7572 	mov	a,_bp
      002600 24 14            [12] 7573 	add	a,#0x14
      002602 F8               [12] 7574 	mov	r0,a
      002603 86 82            [24] 7575 	mov	dpl, @r0
      002605 08               [12] 7576 	inc	r0
      002606 86 83            [24] 7577 	mov	dph, @r0
      002608 08               [12] 7578 	inc	r0
      002609 86 F0            [24] 7579 	mov	b, @r0
      00260B 08               [12] 7580 	inc	r0
      00260C E6               [12] 7581 	mov	a, @r0
      00260D 12 41 CE         [24] 7582 	lcall	___fsadd
      002610 C8               [12] 7583 	xch	a,r0
      002611 E5 08            [12] 7584 	mov	a,_bp
      002613 24 14            [12] 7585 	add	a,#0x14
      002615 C8               [12] 7586 	xch	a,r0
      002616 A6 82            [24] 7587 	mov	@r0, dpl
      002618 08               [12] 7588 	inc	r0
      002619 A6 83            [24] 7589 	mov	@r0, dph
      00261B 08               [12] 7590 	inc	r0
      00261C A6 F0            [24] 7591 	mov	@r0, b
      00261E 08               [12] 7592 	inc	r0
      00261F F6               [12] 7593 	mov	@r0,a
      002620 E5 81            [12] 7594 	mov	a,sp
      002622 24 FC            [12] 7595 	add	a,#0xfc
      002624 F5 81            [12] 7596 	mov	sp,a
      002626 02 24 FF         [24] 7597 	ljmp	00111$
      002629                       7598 00106$:
                           00256C  7599 	C$fuzzy.h$2498$1_0$117 ==.
                                   7600 ;	../../fuzzy.h:2498: return upper;
      002629 E5 08            [12] 7601 	mov	a,_bp
      00262B 24 F6            [12] 7602 	add	a,#0xf6
      00262D F8               [12] 7603 	mov	r0,a
      00262E 86 82            [24] 7604 	mov	dpl, @r0
      002630 08               [12] 7605 	inc	r0
      002631 86 83            [24] 7606 	mov	dph, @r0
      002633 08               [12] 7607 	inc	r0
      002634 86 F0            [24] 7608 	mov	b, @r0
      002636 08               [12] 7609 	inc	r0
      002637 E6               [12] 7610 	mov	a, @r0
      002638                       7611 00113$:
                           00257B  7612 	C$fuzzy.h$2499$1_0$117 ==.
                                   7613 ;	../../fuzzy.h:2499: }
      002638 85 08 81         [24] 7614 	mov	sp,_bp
      00263B D0 08            [24] 7615 	pop	_bp
                           002580  7616 	C$fuzzy.h$2499$1_0$117 ==.
                           002580  7617 	XG$fuzzy_rules_defuzzify_boa$0$0 ==.
      00263D 22               [24] 7618 	ret
                                   7619 ;------------------------------------------------------------
                                   7620 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_cos'
                                   7621 ;------------------------------------------------------------
                                   7622 ;lower         Allocated to stack - _bp -6 +4 
                                   7623 ;upper         Allocated to stack - _bp -10 +4 
                                   7624 ;step          Allocated to stack - _bp -14 +4 
                                   7625 ;implication_method Allocated to stack - _bp -15 +1 
                                   7626 ;rules         Allocated to stack - _bp +1 +3 
                                   7627 ;weighted_sum  Allocated to stack - _bp +9 +4 
                                   7628 ;height_sum    Allocated to stack - _bp +13 +4 
                                   7629 ;value         Allocated to stack - _bp +17 +4 
                                   7630 ;output_membership Allocated to stack - _bp +21 +4 
                                   7631 ;implied_height Allocated to stack - _bp +25 +4 
                                   7632 ;index         Allocated to stack - _bp +29 +2 
                                   7633 ;sloc0         Allocated to stack - _bp +4 +3 
                                   7634 ;sloc1         Allocated to stack - _bp +7 +2 
                                   7635 ;------------------------------------------------------------
                           002581  7636 	G$fuzzy_rules_defuzzify_cos$0$0 ==.
                           002581  7637 	C$fuzzy.h$2511$1_0$125 ==.
                                   7638 ;	../../fuzzy.h:2511: float fuzzy_rules_defuzzify_cos(
                                   7639 ;	-----------------------------------------
                                   7640 ;	 function fuzzy_rules_defuzzify_cos
                                   7641 ;	-----------------------------------------
      00263E                       7642 _fuzzy_rules_defuzzify_cos:
      00263E C0 08            [24] 7643 	push	_bp
      002640 85 81 08         [24] 7644 	mov	_bp,sp
      002643 C0 82            [24] 7645 	push	dpl
      002645 C0 83            [24] 7646 	push	dph
      002647 C0 F0            [24] 7647 	push	b
      002649 E5 81            [12] 7648 	mov	a,sp
      00264B 24 1B            [12] 7649 	add	a,#0x1b
      00264D F5 81            [12] 7650 	mov	sp,a
                           002592  7651 	C$fuzzy.h$2527$1_0$125 ==.
                                   7652 ;	../../fuzzy.h:2527: 0.0f;
      00264F E5 08            [12] 7653 	mov	a,_bp
      002651 24 09            [12] 7654 	add	a,#0x09
      002653 F8               [12] 7655 	mov	r0,a
      002654 E4               [12] 7656 	clr	a
      002655 F6               [12] 7657 	mov	@r0,a
      002656 08               [12] 7658 	inc	r0
      002657 F6               [12] 7659 	mov	@r0,a
      002658 08               [12] 7660 	inc	r0
      002659 F6               [12] 7661 	mov	@r0,a
      00265A 08               [12] 7662 	inc	r0
      00265B F6               [12] 7663 	mov	@r0,a
                           00259F  7664 	C$fuzzy.h$2530$1_0$125 ==.
                                   7665 ;	../../fuzzy.h:2530: 0.0f;
      00265C E5 08            [12] 7666 	mov	a,_bp
      00265E 24 0D            [12] 7667 	add	a,#0x0d
      002660 F8               [12] 7668 	mov	r0,a
      002661 E4               [12] 7669 	clr	a
      002662 F6               [12] 7670 	mov	@r0,a
      002663 08               [12] 7671 	inc	r0
      002664 F6               [12] 7672 	mov	@r0,a
      002665 08               [12] 7673 	inc	r0
      002666 F6               [12] 7674 	mov	@r0,a
      002667 08               [12] 7675 	inc	r0
      002668 F6               [12] 7676 	mov	@r0,a
                           0025AC  7677 	C$fuzzy.h$2533$2_0$126 ==.
                                   7678 ;	../../fuzzy.h:2533: value = lower;
      002669 E5 08            [12] 7679 	mov	a,_bp
      00266B 24 FA            [12] 7680 	add	a,#0xfa
      00266D F8               [12] 7681 	mov	r0,a
      00266E E5 08            [12] 7682 	mov	a,_bp
      002670 24 11            [12] 7683 	add	a,#0x11
      002672 F9               [12] 7684 	mov	r1,a
      002673 E6               [12] 7685 	mov	a,@r0
      002674 F7               [12] 7686 	mov	@r1,a
      002675 08               [12] 7687 	inc	r0
      002676 E6               [12] 7688 	mov	a,@r0
      002677 09               [12] 7689 	inc	r1
      002678 F7               [12] 7690 	mov	@r1,a
      002679 08               [12] 7691 	inc	r0
      00267A E6               [12] 7692 	mov	a,@r0
      00267B 09               [12] 7693 	inc	r1
      00267C F7               [12] 7694 	mov	@r1,a
      00267D 08               [12] 7695 	inc	r0
      00267E E6               [12] 7696 	mov	a,@r0
      00267F 09               [12] 7697 	inc	r1
      002680 F7               [12] 7698 	mov	@r1,a
      002681 A8 08            [24] 7699 	mov	r0,_bp
      002683 08               [12] 7700 	inc	r0
      002684 E5 08            [12] 7701 	mov	a,_bp
      002686 24 04            [12] 7702 	add	a,#0x04
      002688 F9               [12] 7703 	mov	r1,a
      002689 E6               [12] 7704 	mov	a,@r0
      00268A F7               [12] 7705 	mov	@r1,a
      00268B 08               [12] 7706 	inc	r0
      00268C E6               [12] 7707 	mov	a,@r0
      00268D 09               [12] 7708 	inc	r1
      00268E F7               [12] 7709 	mov	@r1,a
      00268F 08               [12] 7710 	inc	r0
      002690 E6               [12] 7711 	mov	a,@r0
      002691 09               [12] 7712 	inc	r1
      002692 F7               [12] 7713 	mov	@r1,a
      002693 A8 08            [24] 7714 	mov	r0,_bp
      002695 08               [12] 7715 	inc	r0
      002696 74 90            [12] 7716 	mov	a,#0x90
      002698 26               [12] 7717 	add	a, @r0
      002699 FC               [12] 7718 	mov	r4,a
      00269A E4               [12] 7719 	clr	a
      00269B 08               [12] 7720 	inc	r0
      00269C 36               [12] 7721 	addc	a, @r0
      00269D FD               [12] 7722 	mov	r5,a
      00269E 08               [12] 7723 	inc	r0
      00269F 86 06            [24] 7724 	mov	ar6,@r0
      0026A1                       7725 00109$:
                           0025E4  7726 	C$fuzzy.h$2534$1_0$125 ==.
                                   7727 ;	../../fuzzy.h:2534: value <= upper;
      0026A1 C0 06            [24] 7728 	push	ar6
      0026A3 C0 05            [24] 7729 	push	ar5
      0026A5 C0 04            [24] 7730 	push	ar4
      0026A7 E5 08            [12] 7731 	mov	a,_bp
      0026A9 24 11            [12] 7732 	add	a,#0x11
      0026AB F8               [12] 7733 	mov	r0,a
      0026AC E6               [12] 7734 	mov	a,@r0
      0026AD C0 E0            [24] 7735 	push	acc
      0026AF 08               [12] 7736 	inc	r0
      0026B0 E6               [12] 7737 	mov	a,@r0
      0026B1 C0 E0            [24] 7738 	push	acc
      0026B3 08               [12] 7739 	inc	r0
      0026B4 E6               [12] 7740 	mov	a,@r0
      0026B5 C0 E0            [24] 7741 	push	acc
      0026B7 08               [12] 7742 	inc	r0
      0026B8 E6               [12] 7743 	mov	a,@r0
      0026B9 C0 E0            [24] 7744 	push	acc
      0026BB E5 08            [12] 7745 	mov	a,_bp
      0026BD 24 F6            [12] 7746 	add	a,#0xf6
      0026BF F8               [12] 7747 	mov	r0,a
      0026C0 86 82            [24] 7748 	mov	dpl, @r0
      0026C2 08               [12] 7749 	inc	r0
      0026C3 86 83            [24] 7750 	mov	dph, @r0
      0026C5 08               [12] 7751 	inc	r0
      0026C6 86 F0            [24] 7752 	mov	b, @r0
      0026C8 08               [12] 7753 	inc	r0
      0026C9 E6               [12] 7754 	mov	a, @r0
      0026CA 12 41 7C         [24] 7755 	lcall	___fslt
      0026CD E5 81            [12] 7756 	mov	a,sp
      0026CF 24 FC            [12] 7757 	add	a,#0xfc
      0026D1 F5 81            [12] 7758 	mov	sp,a
      0026D3 D0 04            [24] 7759 	pop	ar4
      0026D5 D0 05            [24] 7760 	pop	ar5
      0026D7 D0 06            [24] 7761 	pop	ar6
      0026D9 E5 82            [12] 7762 	mov	a, dpl
      0026DB 24 FF            [12] 7763 	add	a,#0xff
      0026DD 92 00            [24] 7764 	mov	b0,c
      0026DF 50 03            [24] 7765 	jnc	00144$
      0026E1 02 29 2E         [24] 7766 	ljmp	00102$
      0026E4                       7767 00144$:
                           002627  7768 	C$fuzzy.h$2538$1_0$125 ==.
                                   7769 ;	../../fuzzy.h:2538: index = 0u;
      0026E4 E5 08            [12] 7770 	mov	a,_bp
      0026E6 24 1D            [12] 7771 	add	a,#0x1d
      0026E8 F8               [12] 7772 	mov	r0,a
      0026E9 E4               [12] 7773 	clr	a
      0026EA F6               [12] 7774 	mov	@r0,a
      0026EB 08               [12] 7775 	inc	r0
      0026EC F6               [12] 7776 	mov	@r0,a
      0026ED E5 08            [12] 7777 	mov	a,_bp
      0026EF 24 07            [12] 7778 	add	a,#0x07
      0026F1 F8               [12] 7779 	mov	r0,a
      0026F2 E4               [12] 7780 	clr	a
      0026F3 F6               [12] 7781 	mov	@r0,a
      0026F4 08               [12] 7782 	inc	r0
      0026F5 F6               [12] 7783 	mov	@r0,a
      0026F6                       7784 00106$:
                           002639  7785 	C$fuzzy.h$2539$4_0$128 ==.
                                   7786 ;	../../fuzzy.h:2539: index < rules->count;
      0026F6 8C 82            [24] 7787 	mov	dpl,r4
      0026F8 8D 83            [24] 7788 	mov	dph,r5
      0026FA 8E F0            [24] 7789 	mov	b,r6
      0026FC 12 43 A8         [24] 7790 	lcall	__gptrget
      0026FF FA               [12] 7791 	mov	r2,a
      002700 A3               [24] 7792 	inc	dptr
      002701 12 43 A8         [24] 7793 	lcall	__gptrget
      002704 FF               [12] 7794 	mov	r7,a
      002705 E5 08            [12] 7795 	mov	a,_bp
      002707 24 1D            [12] 7796 	add	a,#0x1d
      002709 F8               [12] 7797 	mov	r0,a
      00270A C3               [12] 7798 	clr	c
      00270B E6               [12] 7799 	mov	a,@r0
      00270C 9A               [12] 7800 	subb	a,r2
      00270D 08               [12] 7801 	inc	r0
      00270E E6               [12] 7802 	mov	a,@r0
      00270F 9F               [12] 7803 	subb	a,r7
      002710 40 03            [24] 7804 	jc	00145$
      002712 02 28 E3         [24] 7805 	ljmp	00110$
      002715                       7806 00145$:
                           002658  7807 	C$fuzzy.h$2544$1_0$125 ==.
                                   7808 ;	../../fuzzy.h:2544: rules->rules[index]
      002715 C0 04            [24] 7809 	push	ar4
      002717 C0 05            [24] 7810 	push	ar5
      002719 C0 06            [24] 7811 	push	ar6
      00271B E5 08            [12] 7812 	mov	a,_bp
      00271D 24 04            [12] 7813 	add	a,#0x04
      00271F F8               [12] 7814 	mov	r0,a
      002720 E5 08            [12] 7815 	mov	a,_bp
      002722 24 07            [12] 7816 	add	a,#0x07
      002724 F9               [12] 7817 	mov	r1,a
      002725 E7               [12] 7818 	mov	a,@r1
      002726 26               [12] 7819 	add	a, @r0
      002727 FA               [12] 7820 	mov	r2,a
      002728 09               [12] 7821 	inc	r1
      002729 E7               [12] 7822 	mov	a,@r1
      00272A 08               [12] 7823 	inc	r0
      00272B 36               [12] 7824 	addc	a, @r0
      00272C FB               [12] 7825 	mov	r3,a
      00272D 08               [12] 7826 	inc	r0
      00272E 86 07            [24] 7827 	mov	ar7,@r0
      002730 74 07            [12] 7828 	mov	a,#0x07
      002732 2A               [12] 7829 	add	a, r2
      002733 FA               [12] 7830 	mov	r2,a
      002734 E4               [12] 7831 	clr	a
      002735 3B               [12] 7832 	addc	a, r3
      002736 FB               [12] 7833 	mov	r3,a
      002737 8A 82            [24] 7834 	mov	dpl,r2
      002739 8B 83            [24] 7835 	mov	dph,r3
      00273B 8F F0            [24] 7836 	mov	b,r7
      00273D 12 43 A8         [24] 7837 	lcall	__gptrget
      002740 FA               [12] 7838 	mov	r2,a
      002741 A3               [24] 7839 	inc	dptr
      002742 12 43 A8         [24] 7840 	lcall	__gptrget
      002745 FB               [12] 7841 	mov	r3,a
                           002689  7842 	C$fuzzy.h$2545$5_0$129 ==.
                                   7843 ;	../../fuzzy.h:2545: .output_function(value)
      002746 C0 05            [24] 7844 	push	ar5
      002748 C0 04            [24] 7845 	push	ar4
      00274A 12 27 4F         [24] 7846 	lcall	00146$
      00274D 80 14            [24] 7847 	sjmp	00147$
      00274F                       7848 00146$:
      00274F C0 02            [24] 7849 	push	ar2
      002751 C0 03            [24] 7850 	push	ar3
      002753 E5 08            [12] 7851 	mov	a,_bp
      002755 24 11            [12] 7852 	add	a,#0x11
      002757 F8               [12] 7853 	mov	r0,a
      002758 86 82            [24] 7854 	mov	dpl, @r0
      00275A 08               [12] 7855 	inc	r0
      00275B 86 83            [24] 7856 	mov	dph, @r0
      00275D 08               [12] 7857 	inc	r0
      00275E 86 F0            [24] 7858 	mov	b, @r0
      002760 08               [12] 7859 	inc	r0
      002761 E6               [12] 7860 	mov	a, @r0
      002762 22               [24] 7861 	ret
      002763                       7862 00147$:
      002763 AA 82            [24] 7863 	mov	r2, dpl
      002765 AB 83            [24] 7864 	mov	r3, dph
      002767 AE F0            [24] 7865 	mov	r6, b
      002769 FF               [12] 7866 	mov	r7, a
      00276A D0 04            [24] 7867 	pop	ar4
      00276C D0 05            [24] 7868 	pop	ar5
      00276E 8A 82            [24] 7869 	mov	dpl, r2
      002770 8B 83            [24] 7870 	mov	dph, r3
      002772 8E F0            [24] 7871 	mov	b, r6
      002774 EF               [12] 7872 	mov	a, r7
      002775 C0 06            [24] 7873 	push	ar6
      002777 C0 05            [24] 7874 	push	ar5
      002779 C0 04            [24] 7875 	push	ar4
      00277B 12 00 F0         [24] 7876 	lcall	_fuzzy_clamp
      00277E C8               [12] 7877 	xch	a,r0
      00277F E5 08            [12] 7878 	mov	a,_bp
      002781 24 15            [12] 7879 	add	a,#0x15
      002783 C8               [12] 7880 	xch	a,r0
      002784 A6 82            [24] 7881 	mov	@r0, dpl
      002786 08               [12] 7882 	inc	r0
      002787 A6 83            [24] 7883 	mov	@r0, dph
      002789 08               [12] 7884 	inc	r0
      00278A A6 F0            [24] 7885 	mov	@r0, b
      00278C 08               [12] 7886 	inc	r0
      00278D F6               [12] 7887 	mov	@r0,a
      00278E D0 04            [24] 7888 	pop	ar4
      002790 D0 05            [24] 7889 	pop	ar5
      002792 D0 06            [24] 7890 	pop	ar6
                           0026D7  7891 	C$fuzzy.h$2551$5_0$129 ==.
                                   7892 ;	../../fuzzy.h:2551: rules->rules[index].value,
      002794 A8 08            [24] 7893 	mov	r0,_bp
      002796 08               [12] 7894 	inc	r0
      002797 E5 08            [12] 7895 	mov	a,_bp
      002799 24 07            [12] 7896 	add	a,#0x07
      00279B F9               [12] 7897 	mov	r1,a
      00279C E7               [12] 7898 	mov	a,@r1
      00279D 26               [12] 7899 	add	a, @r0
      00279E FA               [12] 7900 	mov	r2,a
      00279F 09               [12] 7901 	inc	r1
      0027A0 E7               [12] 7902 	mov	a,@r1
      0027A1 08               [12] 7903 	inc	r0
      0027A2 36               [12] 7904 	addc	a, @r0
      0027A3 FB               [12] 7905 	mov	r3,a
      0027A4 08               [12] 7906 	inc	r0
      0027A5 86 07            [24] 7907 	mov	ar7,@r0
      0027A7 74 03            [12] 7908 	mov	a,#0x03
      0027A9 2A               [12] 7909 	add	a, r2
      0027AA FA               [12] 7910 	mov	r2,a
      0027AB E4               [12] 7911 	clr	a
      0027AC 3B               [12] 7912 	addc	a, r3
      0027AD FB               [12] 7913 	mov	r3,a
      0027AE 8A 82            [24] 7914 	mov	dpl,r2
      0027B0 8B 83            [24] 7915 	mov	dph,r3
      0027B2 8F F0            [24] 7916 	mov	b,r7
      0027B4 12 43 A8         [24] 7917 	lcall	__gptrget
      0027B7 FA               [12] 7918 	mov	r2,a
      0027B8 A3               [24] 7919 	inc	dptr
      0027B9 12 43 A8         [24] 7920 	lcall	__gptrget
      0027BC FB               [12] 7921 	mov	r3,a
      0027BD A3               [24] 7922 	inc	dptr
      0027BE 12 43 A8         [24] 7923 	lcall	__gptrget
      0027C1 FF               [12] 7924 	mov	r7,a
      0027C2 A3               [24] 7925 	inc	dptr
      0027C3 12 43 A8         [24] 7926 	lcall	__gptrget
      0027C6 FE               [12] 7927 	mov	r6,a
                           00270A  7928 	C$fuzzy.h$2550$5_0$129 ==.
                                   7929 ;	../../fuzzy.h:2550: implication_method,
      0027C7 C0 06            [24] 7930 	push	ar6
      0027C9 C0 05            [24] 7931 	push	ar5
      0027CB C0 04            [24] 7932 	push	ar4
      0027CD E5 08            [12] 7933 	mov	a,_bp
      0027CF 24 15            [12] 7934 	add	a,#0x15
      0027D1 F8               [12] 7935 	mov	r0,a
      0027D2 E6               [12] 7936 	mov	a,@r0
      0027D3 C0 E0            [24] 7937 	push	acc
      0027D5 08               [12] 7938 	inc	r0
      0027D6 E6               [12] 7939 	mov	a,@r0
      0027D7 C0 E0            [24] 7940 	push	acc
      0027D9 08               [12] 7941 	inc	r0
      0027DA E6               [12] 7942 	mov	a,@r0
      0027DB C0 E0            [24] 7943 	push	acc
      0027DD 08               [12] 7944 	inc	r0
      0027DE E6               [12] 7945 	mov	a,@r0
      0027DF C0 E0            [24] 7946 	push	acc
      0027E1 C0 02            [24] 7947 	push	ar2
      0027E3 C0 03            [24] 7948 	push	ar3
      0027E5 C0 07            [24] 7949 	push	ar7
      0027E7 C0 06            [24] 7950 	push	ar6
      0027E9 E5 08            [12] 7951 	mov	a,_bp
      0027EB 24 F1            [12] 7952 	add	a,#0xf1
      0027ED F8               [12] 7953 	mov	r0,a
      0027EE 86 82            [24] 7954 	mov	dpl, @r0
      0027F0 12 18 D7         [24] 7955 	lcall	_fuzzy_implication
      0027F3 C8               [12] 7956 	xch	a,r0
      0027F4 E5 08            [12] 7957 	mov	a,_bp
      0027F6 24 19            [12] 7958 	add	a,#0x19
      0027F8 C8               [12] 7959 	xch	a,r0
      0027F9 A6 82            [24] 7960 	mov	@r0, dpl
      0027FB 08               [12] 7961 	inc	r0
      0027FC A6 83            [24] 7962 	mov	@r0, dph
      0027FE 08               [12] 7963 	inc	r0
      0027FF A6 F0            [24] 7964 	mov	@r0, b
      002801 08               [12] 7965 	inc	r0
      002802 F6               [12] 7966 	mov	@r0,a
      002803 E5 81            [12] 7967 	mov	a,sp
      002805 24 F8            [12] 7968 	add	a,#0xf8
      002807 F5 81            [12] 7969 	mov	sp,a
      002809 D0 04            [24] 7970 	pop	ar4
      00280B D0 05            [24] 7971 	pop	ar5
      00280D D0 06            [24] 7972 	pop	ar6
                           002752  7973 	C$fuzzy.h$2557$1_0$125 ==.
                                   7974 ;	../../fuzzy.h:2557: implied_height;
      00280F C0 05            [24] 7975 	push	ar5
      002811 C0 04            [24] 7976 	push	ar4
      002813 E5 08            [12] 7977 	mov	a,_bp
      002815 24 19            [12] 7978 	add	a,#0x19
      002817 F8               [12] 7979 	mov	r0,a
      002818 E6               [12] 7980 	mov	a,@r0
      002819 C0 E0            [24] 7981 	push	acc
      00281B 08               [12] 7982 	inc	r0
      00281C E6               [12] 7983 	mov	a,@r0
      00281D C0 E0            [24] 7984 	push	acc
      00281F 08               [12] 7985 	inc	r0
      002820 E6               [12] 7986 	mov	a,@r0
      002821 C0 E0            [24] 7987 	push	acc
      002823 08               [12] 7988 	inc	r0
      002824 E6               [12] 7989 	mov	a,@r0
      002825 C0 E0            [24] 7990 	push	acc
      002827 E5 08            [12] 7991 	mov	a,_bp
      002829 24 11            [12] 7992 	add	a,#0x11
      00282B F8               [12] 7993 	mov	r0,a
      00282C 86 82            [24] 7994 	mov	dpl, @r0
      00282E 08               [12] 7995 	inc	r0
      00282F 86 83            [24] 7996 	mov	dph, @r0
      002831 08               [12] 7997 	inc	r0
      002832 86 F0            [24] 7998 	mov	b, @r0
      002834 08               [12] 7999 	inc	r0
      002835 E6               [12] 8000 	mov	a, @r0
      002836 12 40 4C         [24] 8001 	lcall	___fsmul
      002839 AA 82            [24] 8002 	mov	r2, dpl
      00283B AB 83            [24] 8003 	mov	r3, dph
      00283D AE F0            [24] 8004 	mov	r6, b
      00283F FF               [12] 8005 	mov	r7, a
      002840 E5 81            [12] 8006 	mov	a,sp
      002842 24 FC            [12] 8007 	add	a,#0xfc
      002844 F5 81            [12] 8008 	mov	sp,a
      002846 D0 04            [24] 8009 	pop	ar4
      002848 D0 05            [24] 8010 	pop	ar5
      00284A C0 06            [24] 8011 	push	ar6
      00284C C0 05            [24] 8012 	push	ar5
      00284E C0 04            [24] 8013 	push	ar4
      002850 C0 02            [24] 8014 	push	ar2
      002852 C0 03            [24] 8015 	push	ar3
      002854 C0 06            [24] 8016 	push	ar6
      002856 C0 07            [24] 8017 	push	ar7
                           00279B  8018 	C$fuzzy.h$2560$1_0$125 ==.
                                   8019 ;	../../fuzzy.h:2560: implied_height;
      002858 E5 08            [12] 8020 	mov	a,_bp
      00285A 24 09            [12] 8021 	add	a,#0x09
      00285C F8               [12] 8022 	mov	r0,a
      00285D 86 82            [24] 8023 	mov	dpl, @r0
      00285F 08               [12] 8024 	inc	r0
      002860 86 83            [24] 8025 	mov	dph, @r0
      002862 08               [12] 8026 	inc	r0
      002863 86 F0            [24] 8027 	mov	b, @r0
      002865 08               [12] 8028 	inc	r0
      002866 E6               [12] 8029 	mov	a, @r0
      002867 12 41 CE         [24] 8030 	lcall	___fsadd
      00286A C8               [12] 8031 	xch	a,r0
      00286B E5 08            [12] 8032 	mov	a,_bp
      00286D 24 09            [12] 8033 	add	a,#0x09
      00286F C8               [12] 8034 	xch	a,r0
      002870 A6 82            [24] 8035 	mov	@r0, dpl
      002872 08               [12] 8036 	inc	r0
      002873 A6 83            [24] 8037 	mov	@r0, dph
      002875 08               [12] 8038 	inc	r0
      002876 A6 F0            [24] 8039 	mov	@r0, b
      002878 08               [12] 8040 	inc	r0
      002879 F6               [12] 8041 	mov	@r0,a
      00287A E5 81            [12] 8042 	mov	a,sp
      00287C 24 FC            [12] 8043 	add	a,#0xfc
      00287E F5 81            [12] 8044 	mov	sp,a
      002880 E5 08            [12] 8045 	mov	a,_bp
      002882 24 19            [12] 8046 	add	a,#0x19
      002884 F8               [12] 8047 	mov	r0,a
      002885 E6               [12] 8048 	mov	a,@r0
      002886 C0 E0            [24] 8049 	push	acc
      002888 08               [12] 8050 	inc	r0
      002889 E6               [12] 8051 	mov	a,@r0
      00288A C0 E0            [24] 8052 	push	acc
      00288C 08               [12] 8053 	inc	r0
      00288D E6               [12] 8054 	mov	a,@r0
      00288E C0 E0            [24] 8055 	push	acc
      002890 08               [12] 8056 	inc	r0
      002891 E6               [12] 8057 	mov	a,@r0
      002892 C0 E0            [24] 8058 	push	acc
                           0027D7  8059 	C$fuzzy.h$2540$1_0$125 ==.
                                   8060 ;	../../fuzzy.h:2540: index++
      002894 E5 08            [12] 8061 	mov	a,_bp
      002896 24 0D            [12] 8062 	add	a,#0x0d
      002898 F8               [12] 8063 	mov	r0,a
      002899 86 82            [24] 8064 	mov	dpl, @r0
      00289B 08               [12] 8065 	inc	r0
      00289C 86 83            [24] 8066 	mov	dph, @r0
      00289E 08               [12] 8067 	inc	r0
      00289F 86 F0            [24] 8068 	mov	b, @r0
      0028A1 08               [12] 8069 	inc	r0
      0028A2 E6               [12] 8070 	mov	a, @r0
      0028A3 12 41 CE         [24] 8071 	lcall	___fsadd
      0028A6 C8               [12] 8072 	xch	a,r0
      0028A7 E5 08            [12] 8073 	mov	a,_bp
      0028A9 24 0D            [12] 8074 	add	a,#0x0d
      0028AB C8               [12] 8075 	xch	a,r0
      0028AC A6 82            [24] 8076 	mov	@r0, dpl
      0028AE 08               [12] 8077 	inc	r0
      0028AF A6 83            [24] 8078 	mov	@r0, dph
      0028B1 08               [12] 8079 	inc	r0
      0028B2 A6 F0            [24] 8080 	mov	@r0, b
      0028B4 08               [12] 8081 	inc	r0
      0028B5 F6               [12] 8082 	mov	@r0,a
      0028B6 E5 81            [12] 8083 	mov	a,sp
      0028B8 24 FC            [12] 8084 	add	a,#0xfc
      0028BA F5 81            [12] 8085 	mov	sp,a
      0028BC D0 04            [24] 8086 	pop	ar4
      0028BE D0 05            [24] 8087 	pop	ar5
      0028C0 D0 06            [24] 8088 	pop	ar6
      0028C2 E5 08            [12] 8089 	mov	a,_bp
      0028C4 24 07            [12] 8090 	add	a,#0x07
      0028C6 F8               [12] 8091 	mov	r0,a
      0028C7 74 09            [12] 8092 	mov	a,#0x09
      0028C9 26               [12] 8093 	add	a, @r0
      0028CA F6               [12] 8094 	mov	@r0,a
      0028CB E4               [12] 8095 	clr	a
      0028CC 08               [12] 8096 	inc	r0
      0028CD 36               [12] 8097 	addc	a, @r0
      0028CE F6               [12] 8098 	mov	@r0,a
      0028CF E5 08            [12] 8099 	mov	a,_bp
      0028D1 24 1D            [12] 8100 	add	a,#0x1d
      0028D3 F8               [12] 8101 	mov	r0,a
      0028D4 06               [12] 8102 	inc	@r0
      0028D5 B6 00 02         [24] 8103 	cjne	@r0,#0x00,00148$
      0028D8 08               [12] 8104 	inc	r0
      0028D9 06               [12] 8105 	inc	@r0
      0028DA                       8106 00148$:
      0028DA D0 06            [24] 8107 	pop	ar6
      0028DC D0 05            [24] 8108 	pop	ar5
      0028DE D0 04            [24] 8109 	pop	ar4
      0028E0 02 26 F6         [24] 8110 	ljmp	00106$
      0028E3                       8111 00110$:
                           002826  8112 	C$fuzzy.h$2536$1_0$125 ==.
                                   8113 ;	../../fuzzy.h:2536: ) {
      0028E3 C0 06            [24] 8114 	push	ar6
      0028E5 C0 05            [24] 8115 	push	ar5
      0028E7 C0 04            [24] 8116 	push	ar4
      0028E9 E5 08            [12] 8117 	mov	a,_bp
      0028EB 24 F2            [12] 8118 	add	a,#0xf2
      0028ED F8               [12] 8119 	mov	r0,a
      0028EE E6               [12] 8120 	mov	a,@r0
      0028EF C0 E0            [24] 8121 	push	acc
      0028F1 08               [12] 8122 	inc	r0
      0028F2 E6               [12] 8123 	mov	a,@r0
      0028F3 C0 E0            [24] 8124 	push	acc
      0028F5 08               [12] 8125 	inc	r0
      0028F6 E6               [12] 8126 	mov	a,@r0
      0028F7 C0 E0            [24] 8127 	push	acc
      0028F9 08               [12] 8128 	inc	r0
      0028FA E6               [12] 8129 	mov	a,@r0
      0028FB C0 E0            [24] 8130 	push	acc
      0028FD E5 08            [12] 8131 	mov	a,_bp
      0028FF 24 11            [12] 8132 	add	a,#0x11
      002901 F8               [12] 8133 	mov	r0,a
      002902 86 82            [24] 8134 	mov	dpl, @r0
      002904 08               [12] 8135 	inc	r0
      002905 86 83            [24] 8136 	mov	dph, @r0
      002907 08               [12] 8137 	inc	r0
      002908 86 F0            [24] 8138 	mov	b, @r0
      00290A 08               [12] 8139 	inc	r0
      00290B E6               [12] 8140 	mov	a, @r0
      00290C 12 41 CE         [24] 8141 	lcall	___fsadd
      00290F C8               [12] 8142 	xch	a,r0
      002910 E5 08            [12] 8143 	mov	a,_bp
      002912 24 11            [12] 8144 	add	a,#0x11
      002914 C8               [12] 8145 	xch	a,r0
      002915 A6 82            [24] 8146 	mov	@r0, dpl
      002917 08               [12] 8147 	inc	r0
      002918 A6 83            [24] 8148 	mov	@r0, dph
      00291A 08               [12] 8149 	inc	r0
      00291B A6 F0            [24] 8150 	mov	@r0, b
      00291D 08               [12] 8151 	inc	r0
      00291E F6               [12] 8152 	mov	@r0,a
      00291F E5 81            [12] 8153 	mov	a,sp
      002921 24 FC            [12] 8154 	add	a,#0xfc
      002923 F5 81            [12] 8155 	mov	sp,a
      002925 D0 04            [24] 8156 	pop	ar4
      002927 D0 05            [24] 8157 	pop	ar5
      002929 D0 06            [24] 8158 	pop	ar6
      00292B 02 26 A1         [24] 8159 	ljmp	00109$
      00292E                       8160 00102$:
                           002871  8161 	C$fuzzy.h$2564$1_0$125 ==.
                                   8162 ;	../../fuzzy.h:2564: if (height_sum <= LEVEL_LO) {
      00292E E5 08            [12] 8163 	mov	a,_bp
      002930 24 0D            [12] 8164 	add	a,#0x0d
      002932 F8               [12] 8165 	mov	r0,a
      002933 E6               [12] 8166 	mov	a,@r0
      002934 C0 E0            [24] 8167 	push	acc
      002936 08               [12] 8168 	inc	r0
      002937 E6               [12] 8169 	mov	a,@r0
      002938 C0 E0            [24] 8170 	push	acc
      00293A 08               [12] 8171 	inc	r0
      00293B E6               [12] 8172 	mov	a,@r0
      00293C C0 E0            [24] 8173 	push	acc
      00293E 08               [12] 8174 	inc	r0
      00293F E6               [12] 8175 	mov	a,@r0
      002940 C0 E0            [24] 8176 	push	acc
      002942 90 00 00         [24] 8177 	mov	dptr,#0x0000
      002945 E4               [12] 8178 	clr	a
      002946 F5 F0            [12] 8179 	mov	b,a
      002948 12 41 7C         [24] 8180 	lcall	___fslt
      00294B E5 81            [12] 8181 	mov	a,sp
      00294D 24 FC            [12] 8182 	add	a,#0xfc
      00294F F5 81            [12] 8183 	mov	sp,a
      002951 E5 82            [12] 8184 	mov	a, dpl
      002953 24 FF            [12] 8185 	add	a,#0xff
      002955 92 00            [24] 8186 	mov	b0,c
      002957 40 08            [24] 8187 	jc	00104$
                           00289C  8188 	C$fuzzy.h$2565$2_0$130 ==.
                                   8189 ;	../../fuzzy.h:2565: return 0.0f;
      002959 90 00 00         [24] 8190 	mov	dptr,#0x0000
      00295C E4               [12] 8191 	clr	a
      00295D F5 F0            [12] 8192 	mov	b,a
      00295F 80 3A            [24] 8193 	sjmp	00111$
      002961                       8194 00104$:
                           0028A4  8195 	C$fuzzy.h$2569$1_0$125 ==.
                                   8196 ;	../../fuzzy.h:2569: height_sum;
      002961 E5 08            [12] 8197 	mov	a,_bp
      002963 24 0D            [12] 8198 	add	a,#0x0d
      002965 F8               [12] 8199 	mov	r0,a
      002966 E6               [12] 8200 	mov	a,@r0
      002967 C0 E0            [24] 8201 	push	acc
      002969 08               [12] 8202 	inc	r0
      00296A E6               [12] 8203 	mov	a,@r0
      00296B C0 E0            [24] 8204 	push	acc
      00296D 08               [12] 8205 	inc	r0
      00296E E6               [12] 8206 	mov	a,@r0
      00296F C0 E0            [24] 8207 	push	acc
      002971 08               [12] 8208 	inc	r0
      002972 E6               [12] 8209 	mov	a,@r0
      002973 C0 E0            [24] 8210 	push	acc
      002975 E5 08            [12] 8211 	mov	a,_bp
      002977 24 09            [12] 8212 	add	a,#0x09
      002979 F8               [12] 8213 	mov	r0,a
      00297A 86 82            [24] 8214 	mov	dpl, @r0
      00297C 08               [12] 8215 	inc	r0
      00297D 86 83            [24] 8216 	mov	dph, @r0
      00297F 08               [12] 8217 	inc	r0
      002980 86 F0            [24] 8218 	mov	b, @r0
      002982 08               [12] 8219 	inc	r0
      002983 E6               [12] 8220 	mov	a, @r0
      002984 12 42 E5         [24] 8221 	lcall	___fsdiv
      002987 AC 82            [24] 8222 	mov	r4, dpl
      002989 AD 83            [24] 8223 	mov	r5, dph
      00298B AE F0            [24] 8224 	mov	r6, b
      00298D FF               [12] 8225 	mov	r7, a
      00298E E5 81            [12] 8226 	mov	a,sp
      002990 24 FC            [12] 8227 	add	a,#0xfc
      002992 F5 81            [12] 8228 	mov	sp,a
      002994 8C 82            [24] 8229 	mov	dpl, r4
      002996 8D 83            [24] 8230 	mov	dph, r5
      002998 8E F0            [24] 8231 	mov	b, r6
      00299A EF               [12] 8232 	mov	a, r7
      00299B                       8233 00111$:
                           0028DE  8234 	C$fuzzy.h$2570$1_0$125 ==.
                                   8235 ;	../../fuzzy.h:2570: }
      00299B 85 08 81         [24] 8236 	mov	sp,_bp
      00299E D0 08            [24] 8237 	pop	_bp
                           0028E3  8238 	C$fuzzy.h$2570$1_0$125 ==.
                           0028E3  8239 	XG$fuzzy_rules_defuzzify_cos$0$0 ==.
      0029A0 22               [24] 8240 	ret
                                   8241 ;------------------------------------------------------------
                                   8242 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_mom'
                                   8243 ;------------------------------------------------------------
                                   8244 ;lower         Allocated to stack - _bp -6 +4 
                                   8245 ;upper         Allocated to stack - _bp -10 +4 
                                   8246 ;step          Allocated to stack - _bp -14 +4 
                                   8247 ;implication_method Allocated to stack - _bp -15 +1 
                                   8248 ;aggregation_method Allocated to stack - _bp -16 +1 
                                   8249 ;rules         Allocated to stack - _bp +1 +3 
                                   8250 ;result        Allocated to stack - _bp +8 +18 
                                   8251 ;sloc0         Allocated to stack - _bp +4 +4 
                                   8252 ;------------------------------------------------------------
                           0028E4  8253 	G$fuzzy_rules_defuzzify_mom$0$0 ==.
                           0028E4  8254 	C$fuzzy.h$2576$1_0$132 ==.
                                   8255 ;	../../fuzzy.h:2576: float fuzzy_rules_defuzzify_mom(
                                   8256 ;	-----------------------------------------
                                   8257 ;	 function fuzzy_rules_defuzzify_mom
                                   8258 ;	-----------------------------------------
      0029A1                       8259 _fuzzy_rules_defuzzify_mom:
      0029A1 C0 08            [24] 8260 	push	_bp
      0029A3 85 81 08         [24] 8261 	mov	_bp,sp
      0029A6 C0 82            [24] 8262 	push	dpl
      0029A8 C0 83            [24] 8263 	push	dph
      0029AA C0 F0            [24] 8264 	push	b
      0029AC E5 81            [12] 8265 	mov	a,sp
      0029AE 24 16            [12] 8266 	add	a,#0x16
      0029B0 F5 81            [12] 8267 	mov	sp,a
                           0028F5  8268 	C$fuzzy.h$2588$1_0$132 ==.
                                   8269 ;	../../fuzzy.h:2588: &result,
      0029B2 E5 08            [12] 8270 	mov	a,_bp
      0029B4 24 08            [12] 8271 	add	a,#0x08
      0029B6 FC               [12] 8272 	mov	r4,a
      0029B7 FA               [12] 8273 	mov	r2,a
      0029B8 7B 00            [12] 8274 	mov	r3,#0x00
      0029BA 7F 40            [12] 8275 	mov	r7,#0x40
      0029BC C0 04            [24] 8276 	push	ar4
      0029BE E5 08            [12] 8277 	mov	a,_bp
      0029C0 24 F0            [12] 8278 	add	a,#0xf0
      0029C2 F8               [12] 8279 	mov	r0,a
      0029C3 E6               [12] 8280 	mov	a,@r0
      0029C4 C0 E0            [24] 8281 	push	acc
      0029C6 E5 08            [12] 8282 	mov	a,_bp
      0029C8 24 F1            [12] 8283 	add	a,#0xf1
      0029CA F8               [12] 8284 	mov	r0,a
      0029CB E6               [12] 8285 	mov	a,@r0
      0029CC C0 E0            [24] 8286 	push	acc
      0029CE E5 08            [12] 8287 	mov	a,_bp
      0029D0 24 F2            [12] 8288 	add	a,#0xf2
      0029D2 F8               [12] 8289 	mov	r0,a
      0029D3 E6               [12] 8290 	mov	a,@r0
      0029D4 C0 E0            [24] 8291 	push	acc
      0029D6 08               [12] 8292 	inc	r0
      0029D7 E6               [12] 8293 	mov	a,@r0
      0029D8 C0 E0            [24] 8294 	push	acc
      0029DA 08               [12] 8295 	inc	r0
      0029DB E6               [12] 8296 	mov	a,@r0
      0029DC C0 E0            [24] 8297 	push	acc
      0029DE 08               [12] 8298 	inc	r0
      0029DF E6               [12] 8299 	mov	a,@r0
      0029E0 C0 E0            [24] 8300 	push	acc
      0029E2 E5 08            [12] 8301 	mov	a,_bp
      0029E4 24 F6            [12] 8302 	add	a,#0xf6
      0029E6 F8               [12] 8303 	mov	r0,a
      0029E7 E6               [12] 8304 	mov	a,@r0
      0029E8 C0 E0            [24] 8305 	push	acc
      0029EA 08               [12] 8306 	inc	r0
      0029EB E6               [12] 8307 	mov	a,@r0
      0029EC C0 E0            [24] 8308 	push	acc
      0029EE 08               [12] 8309 	inc	r0
      0029EF E6               [12] 8310 	mov	a,@r0
      0029F0 C0 E0            [24] 8311 	push	acc
      0029F2 08               [12] 8312 	inc	r0
      0029F3 E6               [12] 8313 	mov	a,@r0
      0029F4 C0 E0            [24] 8314 	push	acc
      0029F6 E5 08            [12] 8315 	mov	a,_bp
      0029F8 24 FA            [12] 8316 	add	a,#0xfa
      0029FA F8               [12] 8317 	mov	r0,a
      0029FB E6               [12] 8318 	mov	a,@r0
      0029FC C0 E0            [24] 8319 	push	acc
      0029FE 08               [12] 8320 	inc	r0
      0029FF E6               [12] 8321 	mov	a,@r0
      002A00 C0 E0            [24] 8322 	push	acc
      002A02 08               [12] 8323 	inc	r0
      002A03 E6               [12] 8324 	mov	a,@r0
      002A04 C0 E0            [24] 8325 	push	acc
      002A06 08               [12] 8326 	inc	r0
      002A07 E6               [12] 8327 	mov	a,@r0
      002A08 C0 E0            [24] 8328 	push	acc
      002A0A A8 08            [24] 8329 	mov	r0,_bp
      002A0C 08               [12] 8330 	inc	r0
      002A0D E6               [12] 8331 	mov	a,@r0
      002A0E C0 E0            [24] 8332 	push	acc
      002A10 08               [12] 8333 	inc	r0
      002A11 E6               [12] 8334 	mov	a,@r0
      002A12 C0 E0            [24] 8335 	push	acc
      002A14 08               [12] 8336 	inc	r0
      002A15 E6               [12] 8337 	mov	a,@r0
      002A16 C0 E0            [24] 8338 	push	acc
      002A18 8A 82            [24] 8339 	mov	dpl, r2
      002A1A 8B 83            [24] 8340 	mov	dph, r3
      002A1C 8F F0            [24] 8341 	mov	b, r7
      002A1E 12 1D 47         [24] 8342 	lcall	_fuzzy_rules_maximum_result
      002A21 E5 81            [12] 8343 	mov	a,sp
      002A23 24 EF            [12] 8344 	add	a,#0xef
      002A25 F5 81            [12] 8345 	mov	sp,a
      002A27 D0 04            [24] 8346 	pop	ar4
                           00296C  8347 	C$fuzzy.h$2598$1_0$132 ==.
                                   8348 ;	../../fuzzy.h:2598: result.position_count == 0u ||
      002A29 74 10            [12] 8349 	mov	a,#0x10
      002A2B 2C               [12] 8350 	add	a, r4
      002A2C F9               [12] 8351 	mov	r1,a
      002A2D 87 06            [24] 8352 	mov	ar6,@r1
      002A2F 09               [12] 8353 	inc	r1
      002A30 87 07            [24] 8354 	mov	ar7,@r1
      002A32 EE               [12] 8355 	mov	a,r6
      002A33 4F               [12] 8356 	orl	a,r7
      002A34 60 41            [24] 8357 	jz	00101$
                           002979  8358 	C$fuzzy.h$2599$1_0$132 ==.
                                   8359 ;	../../fuzzy.h:2599: result.height <= LEVEL_LO
      002A36 C0 06            [24] 8360 	push	ar6
      002A38 C0 07            [24] 8361 	push	ar7
      002A3A 8C 01            [24] 8362 	mov	ar1,r4
      002A3C 87 02            [24] 8363 	mov	ar2,@r1
      002A3E 09               [12] 8364 	inc	r1
      002A3F 87 03            [24] 8365 	mov	ar3,@r1
      002A41 09               [12] 8366 	inc	r1
      002A42 87 05            [24] 8367 	mov	ar5,@r1
      002A44 09               [12] 8368 	inc	r1
      002A45 87 07            [24] 8369 	mov	ar7,@r1
      002A47 C0 07            [24] 8370 	push	ar7
      002A49 C0 06            [24] 8371 	push	ar6
      002A4B C0 04            [24] 8372 	push	ar4
      002A4D C0 02            [24] 8373 	push	ar2
      002A4F C0 03            [24] 8374 	push	ar3
      002A51 C0 05            [24] 8375 	push	ar5
      002A53 C0 07            [24] 8376 	push	ar7
      002A55 90 00 00         [24] 8377 	mov	dptr,#0x0000
      002A58 E4               [12] 8378 	clr	a
      002A59 F5 F0            [12] 8379 	mov	b,a
      002A5B 12 41 7C         [24] 8380 	lcall	___fslt
      002A5E E5 81            [12] 8381 	mov	a,sp
      002A60 24 FC            [12] 8382 	add	a,#0xfc
      002A62 F5 81            [12] 8383 	mov	sp,a
      002A64 D0 04            [24] 8384 	pop	ar4
      002A66 D0 06            [24] 8385 	pop	ar6
      002A68 D0 07            [24] 8386 	pop	ar7
      002A6A E5 82            [12] 8387 	mov	a, dpl
      002A6C 24 FF            [12] 8388 	add	a,#0xff
      002A6E 92 00            [24] 8389 	mov	b0,c
      002A70 D0 07            [24] 8390 	pop	ar7
      002A72 D0 06            [24] 8391 	pop	ar6
      002A74 20 00 08         [24] 8392 	jb	b0,00102$
      002A77                       8393 00101$:
                           0029BA  8394 	C$fuzzy.h$2601$2_0$133 ==.
                                   8395 ;	../../fuzzy.h:2601: return 0.0f;
      002A77 90 00 00         [24] 8396 	mov	dptr,#0x0000
      002A7A E4               [12] 8397 	clr	a
      002A7B F5 F0            [12] 8398 	mov	b,a
      002A7D 80 53            [24] 8399 	sjmp	00104$
      002A7F                       8400 00102$:
                           0029C2  8401 	C$fuzzy.h$2604$1_0$132 ==.
                                   8402 ;	../../fuzzy.h:2604: return result.position_sum /
      002A7F 74 0C            [12] 8403 	mov	a,#0x0c
      002A81 2C               [12] 8404 	add	a, r4
      002A82 F9               [12] 8405 	mov	r1,a
      002A83 E5 08            [12] 8406 	mov	a,_bp
      002A85 24 04            [12] 8407 	add	a,#0x04
      002A87 F8               [12] 8408 	mov	r0,a
      002A88 E7               [12] 8409 	mov	a,@r1
      002A89 F6               [12] 8410 	mov	@r0,a
      002A8A 09               [12] 8411 	inc	r1
      002A8B E7               [12] 8412 	mov	a,@r1
      002A8C 08               [12] 8413 	inc	r0
      002A8D F6               [12] 8414 	mov	@r0,a
      002A8E 09               [12] 8415 	inc	r1
      002A8F E7               [12] 8416 	mov	a,@r1
      002A90 08               [12] 8417 	inc	r0
      002A91 F6               [12] 8418 	mov	@r0,a
      002A92 09               [12] 8419 	inc	r1
      002A93 E7               [12] 8420 	mov	a,@r1
      002A94 08               [12] 8421 	inc	r0
      002A95 F6               [12] 8422 	mov	@r0,a
                           0029D9  8423 	C$fuzzy.h$2605$1_0$132 ==.
                                   8424 ;	../../fuzzy.h:2605: (float)result.position_count;
      002A96 8E 82            [24] 8425 	mov	dpl, r6
      002A98 8F 83            [24] 8426 	mov	dph, r7
      002A9A 12 42 70         [24] 8427 	lcall	___uint2fs
      002A9D AC 82            [24] 8428 	mov	r4, dpl
      002A9F AD 83            [24] 8429 	mov	r5, dph
      002AA1 AE F0            [24] 8430 	mov	r6, b
      002AA3 FF               [12] 8431 	mov	r7, a
      002AA4 C0 04            [24] 8432 	push	ar4
      002AA6 C0 05            [24] 8433 	push	ar5
      002AA8 C0 06            [24] 8434 	push	ar6
      002AAA C0 07            [24] 8435 	push	ar7
      002AAC E5 08            [12] 8436 	mov	a,_bp
      002AAE 24 04            [12] 8437 	add	a,#0x04
      002AB0 F8               [12] 8438 	mov	r0,a
      002AB1 86 82            [24] 8439 	mov	dpl, @r0
      002AB3 08               [12] 8440 	inc	r0
      002AB4 86 83            [24] 8441 	mov	dph, @r0
      002AB6 08               [12] 8442 	inc	r0
      002AB7 86 F0            [24] 8443 	mov	b, @r0
      002AB9 08               [12] 8444 	inc	r0
      002ABA E6               [12] 8445 	mov	a, @r0
      002ABB 12 42 E5         [24] 8446 	lcall	___fsdiv
      002ABE AC 82            [24] 8447 	mov	r4, dpl
      002AC0 AD 83            [24] 8448 	mov	r5, dph
      002AC2 AE F0            [24] 8449 	mov	r6, b
      002AC4 FF               [12] 8450 	mov	r7, a
      002AC5 E5 81            [12] 8451 	mov	a,sp
      002AC7 24 FC            [12] 8452 	add	a,#0xfc
      002AC9 F5 81            [12] 8453 	mov	sp,a
      002ACB 8C 82            [24] 8454 	mov	dpl, r4
      002ACD 8D 83            [24] 8455 	mov	dph, r5
      002ACF 8E F0            [24] 8456 	mov	b, r6
      002AD1 EF               [12] 8457 	mov	a, r7
      002AD2                       8458 00104$:
                           002A15  8459 	C$fuzzy.h$2606$1_0$132 ==.
                                   8460 ;	../../fuzzy.h:2606: }
      002AD2 85 08 81         [24] 8461 	mov	sp,_bp
      002AD5 D0 08            [24] 8462 	pop	_bp
                           002A1A  8463 	C$fuzzy.h$2606$1_0$132 ==.
                           002A1A  8464 	XG$fuzzy_rules_defuzzify_mom$0$0 ==.
      002AD7 22               [24] 8465 	ret
                                   8466 ;------------------------------------------------------------
                                   8467 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_som'
                                   8468 ;------------------------------------------------------------
                                   8469 ;lower         Allocated to stack - _bp -6 +4 
                                   8470 ;upper         Allocated to stack - _bp -10 +4 
                                   8471 ;step          Allocated to stack - _bp -14 +4 
                                   8472 ;implication_method Allocated to stack - _bp -15 +1 
                                   8473 ;aggregation_method Allocated to stack - _bp -16 +1 
                                   8474 ;rules         Allocated to stack - _bp +1 +3 
                                   8475 ;result        Allocated to stack - _bp +4 +18 
                                   8476 ;------------------------------------------------------------
                           002A1B  8477 	G$fuzzy_rules_defuzzify_som$0$0 ==.
                           002A1B  8478 	C$fuzzy.h$2612$1_0$135 ==.
                                   8479 ;	../../fuzzy.h:2612: float fuzzy_rules_defuzzify_som(
                                   8480 ;	-----------------------------------------
                                   8481 ;	 function fuzzy_rules_defuzzify_som
                                   8482 ;	-----------------------------------------
      002AD8                       8483 _fuzzy_rules_defuzzify_som:
      002AD8 C0 08            [24] 8484 	push	_bp
      002ADA 85 81 08         [24] 8485 	mov	_bp,sp
      002ADD C0 82            [24] 8486 	push	dpl
      002ADF C0 83            [24] 8487 	push	dph
      002AE1 C0 F0            [24] 8488 	push	b
      002AE3 E5 81            [12] 8489 	mov	a,sp
      002AE5 24 12            [12] 8490 	add	a,#0x12
      002AE7 F5 81            [12] 8491 	mov	sp,a
                           002A2C  8492 	C$fuzzy.h$2624$1_0$135 ==.
                                   8493 ;	../../fuzzy.h:2624: &result,
      002AE9 E5 08            [12] 8494 	mov	a,_bp
      002AEB 24 04            [12] 8495 	add	a,#0x04
      002AED FC               [12] 8496 	mov	r4,a
      002AEE FA               [12] 8497 	mov	r2,a
      002AEF 7B 00            [12] 8498 	mov	r3,#0x00
      002AF1 7F 40            [12] 8499 	mov	r7,#0x40
      002AF3 C0 04            [24] 8500 	push	ar4
      002AF5 E5 08            [12] 8501 	mov	a,_bp
      002AF7 24 F0            [12] 8502 	add	a,#0xf0
      002AF9 F8               [12] 8503 	mov	r0,a
      002AFA E6               [12] 8504 	mov	a,@r0
      002AFB C0 E0            [24] 8505 	push	acc
      002AFD E5 08            [12] 8506 	mov	a,_bp
      002AFF 24 F1            [12] 8507 	add	a,#0xf1
      002B01 F8               [12] 8508 	mov	r0,a
      002B02 E6               [12] 8509 	mov	a,@r0
      002B03 C0 E0            [24] 8510 	push	acc
      002B05 E5 08            [12] 8511 	mov	a,_bp
      002B07 24 F2            [12] 8512 	add	a,#0xf2
      002B09 F8               [12] 8513 	mov	r0,a
      002B0A E6               [12] 8514 	mov	a,@r0
      002B0B C0 E0            [24] 8515 	push	acc
      002B0D 08               [12] 8516 	inc	r0
      002B0E E6               [12] 8517 	mov	a,@r0
      002B0F C0 E0            [24] 8518 	push	acc
      002B11 08               [12] 8519 	inc	r0
      002B12 E6               [12] 8520 	mov	a,@r0
      002B13 C0 E0            [24] 8521 	push	acc
      002B15 08               [12] 8522 	inc	r0
      002B16 E6               [12] 8523 	mov	a,@r0
      002B17 C0 E0            [24] 8524 	push	acc
      002B19 E5 08            [12] 8525 	mov	a,_bp
      002B1B 24 F6            [12] 8526 	add	a,#0xf6
      002B1D F8               [12] 8527 	mov	r0,a
      002B1E E6               [12] 8528 	mov	a,@r0
      002B1F C0 E0            [24] 8529 	push	acc
      002B21 08               [12] 8530 	inc	r0
      002B22 E6               [12] 8531 	mov	a,@r0
      002B23 C0 E0            [24] 8532 	push	acc
      002B25 08               [12] 8533 	inc	r0
      002B26 E6               [12] 8534 	mov	a,@r0
      002B27 C0 E0            [24] 8535 	push	acc
      002B29 08               [12] 8536 	inc	r0
      002B2A E6               [12] 8537 	mov	a,@r0
      002B2B C0 E0            [24] 8538 	push	acc
      002B2D E5 08            [12] 8539 	mov	a,_bp
      002B2F 24 FA            [12] 8540 	add	a,#0xfa
      002B31 F8               [12] 8541 	mov	r0,a
      002B32 E6               [12] 8542 	mov	a,@r0
      002B33 C0 E0            [24] 8543 	push	acc
      002B35 08               [12] 8544 	inc	r0
      002B36 E6               [12] 8545 	mov	a,@r0
      002B37 C0 E0            [24] 8546 	push	acc
      002B39 08               [12] 8547 	inc	r0
      002B3A E6               [12] 8548 	mov	a,@r0
      002B3B C0 E0            [24] 8549 	push	acc
      002B3D 08               [12] 8550 	inc	r0
      002B3E E6               [12] 8551 	mov	a,@r0
      002B3F C0 E0            [24] 8552 	push	acc
      002B41 A8 08            [24] 8553 	mov	r0,_bp
      002B43 08               [12] 8554 	inc	r0
      002B44 E6               [12] 8555 	mov	a,@r0
      002B45 C0 E0            [24] 8556 	push	acc
      002B47 08               [12] 8557 	inc	r0
      002B48 E6               [12] 8558 	mov	a,@r0
      002B49 C0 E0            [24] 8559 	push	acc
      002B4B 08               [12] 8560 	inc	r0
      002B4C E6               [12] 8561 	mov	a,@r0
      002B4D C0 E0            [24] 8562 	push	acc
      002B4F 8A 82            [24] 8563 	mov	dpl, r2
      002B51 8B 83            [24] 8564 	mov	dph, r3
      002B53 8F F0            [24] 8565 	mov	b, r7
      002B55 12 1D 47         [24] 8566 	lcall	_fuzzy_rules_maximum_result
      002B58 E5 81            [12] 8567 	mov	a,sp
      002B5A 24 EF            [12] 8568 	add	a,#0xef
      002B5C F5 81            [12] 8569 	mov	sp,a
      002B5E D0 04            [24] 8570 	pop	ar4
                           002AA3  8571 	C$fuzzy.h$2634$1_0$135 ==.
                                   8572 ;	../../fuzzy.h:2634: result.position_count == 0u ||
      002B60 74 10            [12] 8573 	mov	a,#0x10
      002B62 2C               [12] 8574 	add	a, r4
      002B63 F9               [12] 8575 	mov	r1,a
      002B64 87 06            [24] 8576 	mov	ar6,@r1
      002B66 09               [12] 8577 	inc	r1
      002B67 87 07            [24] 8578 	mov	ar7,@r1
      002B69 EE               [12] 8579 	mov	a,r6
      002B6A 4F               [12] 8580 	orl	a,r7
      002B6B 60 30            [24] 8581 	jz	00101$
                           002AB0  8582 	C$fuzzy.h$2635$1_0$135 ==.
                                   8583 ;	../../fuzzy.h:2635: result.height <= LEVEL_LO
      002B6D 8C 01            [24] 8584 	mov	ar1,r4
      002B6F 87 03            [24] 8585 	mov	ar3,@r1
      002B71 09               [12] 8586 	inc	r1
      002B72 87 05            [24] 8587 	mov	ar5,@r1
      002B74 09               [12] 8588 	inc	r1
      002B75 87 06            [24] 8589 	mov	ar6,@r1
      002B77 09               [12] 8590 	inc	r1
      002B78 87 07            [24] 8591 	mov	ar7,@r1
      002B7A C0 04            [24] 8592 	push	ar4
      002B7C C0 03            [24] 8593 	push	ar3
      002B7E C0 05            [24] 8594 	push	ar5
      002B80 C0 06            [24] 8595 	push	ar6
      002B82 C0 07            [24] 8596 	push	ar7
      002B84 90 00 00         [24] 8597 	mov	dptr,#0x0000
      002B87 E4               [12] 8598 	clr	a
      002B88 F5 F0            [12] 8599 	mov	b,a
      002B8A 12 41 7C         [24] 8600 	lcall	___fslt
      002B8D E5 81            [12] 8601 	mov	a,sp
      002B8F 24 FC            [12] 8602 	add	a,#0xfc
      002B91 F5 81            [12] 8603 	mov	sp,a
      002B93 D0 04            [24] 8604 	pop	ar4
      002B95 E5 82            [12] 8605 	mov	a, dpl
      002B97 24 FF            [12] 8606 	add	a,#0xff
      002B99 92 00            [24] 8607 	mov	b0,c
      002B9B 40 08            [24] 8608 	jc	00102$
      002B9D                       8609 00101$:
                           002AE0  8610 	C$fuzzy.h$2637$2_0$136 ==.
                                   8611 ;	../../fuzzy.h:2637: return 0.0f;
      002B9D 90 00 00         [24] 8612 	mov	dptr,#0x0000
      002BA0 E4               [12] 8613 	clr	a
      002BA1 F5 F0            [12] 8614 	mov	b,a
      002BA3 80 16            [24] 8615 	sjmp	00104$
      002BA5                       8616 00102$:
                           002AE8  8617 	C$fuzzy.h$2640$1_0$135 ==.
                                   8618 ;	../../fuzzy.h:2640: return result.smallest_position;
      002BA5 74 04            [12] 8619 	mov	a,#0x04
      002BA7 2C               [12] 8620 	add	a, r4
      002BA8 F9               [12] 8621 	mov	r1,a
      002BA9 87 04            [24] 8622 	mov	ar4,@r1
      002BAB 09               [12] 8623 	inc	r1
      002BAC 87 05            [24] 8624 	mov	ar5,@r1
      002BAE 09               [12] 8625 	inc	r1
      002BAF 87 06            [24] 8626 	mov	ar6,@r1
      002BB1 09               [12] 8627 	inc	r1
      002BB2 87 07            [24] 8628 	mov	ar7,@r1
      002BB4 8C 82            [24] 8629 	mov	dpl, r4
      002BB6 8D 83            [24] 8630 	mov	dph, r5
      002BB8 8E F0            [24] 8631 	mov	b, r6
      002BBA EF               [12] 8632 	mov	a, r7
      002BBB                       8633 00104$:
                           002AFE  8634 	C$fuzzy.h$2641$1_0$135 ==.
                                   8635 ;	../../fuzzy.h:2641: }
      002BBB 85 08 81         [24] 8636 	mov	sp,_bp
      002BBE D0 08            [24] 8637 	pop	_bp
                           002B03  8638 	C$fuzzy.h$2641$1_0$135 ==.
                           002B03  8639 	XG$fuzzy_rules_defuzzify_som$0$0 ==.
      002BC0 22               [24] 8640 	ret
                                   8641 ;------------------------------------------------------------
                                   8642 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_lom'
                                   8643 ;------------------------------------------------------------
                                   8644 ;lower         Allocated to stack - _bp -6 +4 
                                   8645 ;upper         Allocated to stack - _bp -10 +4 
                                   8646 ;step          Allocated to stack - _bp -14 +4 
                                   8647 ;implication_method Allocated to stack - _bp -15 +1 
                                   8648 ;aggregation_method Allocated to stack - _bp -16 +1 
                                   8649 ;rules         Allocated to stack - _bp +1 +3 
                                   8650 ;result        Allocated to stack - _bp +4 +18 
                                   8651 ;------------------------------------------------------------
                           002B04  8652 	G$fuzzy_rules_defuzzify_lom$0$0 ==.
                           002B04  8653 	C$fuzzy.h$2647$1_0$138 ==.
                                   8654 ;	../../fuzzy.h:2647: float fuzzy_rules_defuzzify_lom(
                                   8655 ;	-----------------------------------------
                                   8656 ;	 function fuzzy_rules_defuzzify_lom
                                   8657 ;	-----------------------------------------
      002BC1                       8658 _fuzzy_rules_defuzzify_lom:
      002BC1 C0 08            [24] 8659 	push	_bp
      002BC3 85 81 08         [24] 8660 	mov	_bp,sp
      002BC6 C0 82            [24] 8661 	push	dpl
      002BC8 C0 83            [24] 8662 	push	dph
      002BCA C0 F0            [24] 8663 	push	b
      002BCC E5 81            [12] 8664 	mov	a,sp
      002BCE 24 12            [12] 8665 	add	a,#0x12
      002BD0 F5 81            [12] 8666 	mov	sp,a
                           002B15  8667 	C$fuzzy.h$2659$1_0$138 ==.
                                   8668 ;	../../fuzzy.h:2659: &result,
      002BD2 E5 08            [12] 8669 	mov	a,_bp
      002BD4 24 04            [12] 8670 	add	a,#0x04
      002BD6 FC               [12] 8671 	mov	r4,a
      002BD7 FA               [12] 8672 	mov	r2,a
      002BD8 7B 00            [12] 8673 	mov	r3,#0x00
      002BDA 7F 40            [12] 8674 	mov	r7,#0x40
      002BDC C0 04            [24] 8675 	push	ar4
      002BDE E5 08            [12] 8676 	mov	a,_bp
      002BE0 24 F0            [12] 8677 	add	a,#0xf0
      002BE2 F8               [12] 8678 	mov	r0,a
      002BE3 E6               [12] 8679 	mov	a,@r0
      002BE4 C0 E0            [24] 8680 	push	acc
      002BE6 E5 08            [12] 8681 	mov	a,_bp
      002BE8 24 F1            [12] 8682 	add	a,#0xf1
      002BEA F8               [12] 8683 	mov	r0,a
      002BEB E6               [12] 8684 	mov	a,@r0
      002BEC C0 E0            [24] 8685 	push	acc
      002BEE E5 08            [12] 8686 	mov	a,_bp
      002BF0 24 F2            [12] 8687 	add	a,#0xf2
      002BF2 F8               [12] 8688 	mov	r0,a
      002BF3 E6               [12] 8689 	mov	a,@r0
      002BF4 C0 E0            [24] 8690 	push	acc
      002BF6 08               [12] 8691 	inc	r0
      002BF7 E6               [12] 8692 	mov	a,@r0
      002BF8 C0 E0            [24] 8693 	push	acc
      002BFA 08               [12] 8694 	inc	r0
      002BFB E6               [12] 8695 	mov	a,@r0
      002BFC C0 E0            [24] 8696 	push	acc
      002BFE 08               [12] 8697 	inc	r0
      002BFF E6               [12] 8698 	mov	a,@r0
      002C00 C0 E0            [24] 8699 	push	acc
      002C02 E5 08            [12] 8700 	mov	a,_bp
      002C04 24 F6            [12] 8701 	add	a,#0xf6
      002C06 F8               [12] 8702 	mov	r0,a
      002C07 E6               [12] 8703 	mov	a,@r0
      002C08 C0 E0            [24] 8704 	push	acc
      002C0A 08               [12] 8705 	inc	r0
      002C0B E6               [12] 8706 	mov	a,@r0
      002C0C C0 E0            [24] 8707 	push	acc
      002C0E 08               [12] 8708 	inc	r0
      002C0F E6               [12] 8709 	mov	a,@r0
      002C10 C0 E0            [24] 8710 	push	acc
      002C12 08               [12] 8711 	inc	r0
      002C13 E6               [12] 8712 	mov	a,@r0
      002C14 C0 E0            [24] 8713 	push	acc
      002C16 E5 08            [12] 8714 	mov	a,_bp
      002C18 24 FA            [12] 8715 	add	a,#0xfa
      002C1A F8               [12] 8716 	mov	r0,a
      002C1B E6               [12] 8717 	mov	a,@r0
      002C1C C0 E0            [24] 8718 	push	acc
      002C1E 08               [12] 8719 	inc	r0
      002C1F E6               [12] 8720 	mov	a,@r0
      002C20 C0 E0            [24] 8721 	push	acc
      002C22 08               [12] 8722 	inc	r0
      002C23 E6               [12] 8723 	mov	a,@r0
      002C24 C0 E0            [24] 8724 	push	acc
      002C26 08               [12] 8725 	inc	r0
      002C27 E6               [12] 8726 	mov	a,@r0
      002C28 C0 E0            [24] 8727 	push	acc
      002C2A A8 08            [24] 8728 	mov	r0,_bp
      002C2C 08               [12] 8729 	inc	r0
      002C2D E6               [12] 8730 	mov	a,@r0
      002C2E C0 E0            [24] 8731 	push	acc
      002C30 08               [12] 8732 	inc	r0
      002C31 E6               [12] 8733 	mov	a,@r0
      002C32 C0 E0            [24] 8734 	push	acc
      002C34 08               [12] 8735 	inc	r0
      002C35 E6               [12] 8736 	mov	a,@r0
      002C36 C0 E0            [24] 8737 	push	acc
      002C38 8A 82            [24] 8738 	mov	dpl, r2
      002C3A 8B 83            [24] 8739 	mov	dph, r3
      002C3C 8F F0            [24] 8740 	mov	b, r7
      002C3E 12 1D 47         [24] 8741 	lcall	_fuzzy_rules_maximum_result
      002C41 E5 81            [12] 8742 	mov	a,sp
      002C43 24 EF            [12] 8743 	add	a,#0xef
      002C45 F5 81            [12] 8744 	mov	sp,a
      002C47 D0 04            [24] 8745 	pop	ar4
                           002B8C  8746 	C$fuzzy.h$2669$1_0$138 ==.
                                   8747 ;	../../fuzzy.h:2669: result.position_count == 0u ||
      002C49 74 10            [12] 8748 	mov	a,#0x10
      002C4B 2C               [12] 8749 	add	a, r4
      002C4C F9               [12] 8750 	mov	r1,a
      002C4D 87 06            [24] 8751 	mov	ar6,@r1
      002C4F 09               [12] 8752 	inc	r1
      002C50 87 07            [24] 8753 	mov	ar7,@r1
      002C52 EE               [12] 8754 	mov	a,r6
      002C53 4F               [12] 8755 	orl	a,r7
      002C54 60 30            [24] 8756 	jz	00101$
                           002B99  8757 	C$fuzzy.h$2670$1_0$138 ==.
                                   8758 ;	../../fuzzy.h:2670: result.height <= LEVEL_LO
      002C56 8C 01            [24] 8759 	mov	ar1,r4
      002C58 87 03            [24] 8760 	mov	ar3,@r1
      002C5A 09               [12] 8761 	inc	r1
      002C5B 87 05            [24] 8762 	mov	ar5,@r1
      002C5D 09               [12] 8763 	inc	r1
      002C5E 87 06            [24] 8764 	mov	ar6,@r1
      002C60 09               [12] 8765 	inc	r1
      002C61 87 07            [24] 8766 	mov	ar7,@r1
      002C63 C0 04            [24] 8767 	push	ar4
      002C65 C0 03            [24] 8768 	push	ar3
      002C67 C0 05            [24] 8769 	push	ar5
      002C69 C0 06            [24] 8770 	push	ar6
      002C6B C0 07            [24] 8771 	push	ar7
      002C6D 90 00 00         [24] 8772 	mov	dptr,#0x0000
      002C70 E4               [12] 8773 	clr	a
      002C71 F5 F0            [12] 8774 	mov	b,a
      002C73 12 41 7C         [24] 8775 	lcall	___fslt
      002C76 E5 81            [12] 8776 	mov	a,sp
      002C78 24 FC            [12] 8777 	add	a,#0xfc
      002C7A F5 81            [12] 8778 	mov	sp,a
      002C7C D0 04            [24] 8779 	pop	ar4
      002C7E E5 82            [12] 8780 	mov	a, dpl
      002C80 24 FF            [12] 8781 	add	a,#0xff
      002C82 92 00            [24] 8782 	mov	b0,c
      002C84 40 08            [24] 8783 	jc	00102$
      002C86                       8784 00101$:
                           002BC9  8785 	C$fuzzy.h$2672$2_0$139 ==.
                                   8786 ;	../../fuzzy.h:2672: return 0.0f;
      002C86 90 00 00         [24] 8787 	mov	dptr,#0x0000
      002C89 E4               [12] 8788 	clr	a
      002C8A F5 F0            [12] 8789 	mov	b,a
      002C8C 80 16            [24] 8790 	sjmp	00104$
      002C8E                       8791 00102$:
                           002BD1  8792 	C$fuzzy.h$2675$1_0$138 ==.
                                   8793 ;	../../fuzzy.h:2675: return result.largest_position;
      002C8E 74 08            [12] 8794 	mov	a,#0x08
      002C90 2C               [12] 8795 	add	a, r4
      002C91 F9               [12] 8796 	mov	r1,a
      002C92 87 04            [24] 8797 	mov	ar4,@r1
      002C94 09               [12] 8798 	inc	r1
      002C95 87 05            [24] 8799 	mov	ar5,@r1
      002C97 09               [12] 8800 	inc	r1
      002C98 87 06            [24] 8801 	mov	ar6,@r1
      002C9A 09               [12] 8802 	inc	r1
      002C9B 87 07            [24] 8803 	mov	ar7,@r1
      002C9D 8C 82            [24] 8804 	mov	dpl, r4
      002C9F 8D 83            [24] 8805 	mov	dph, r5
      002CA1 8E F0            [24] 8806 	mov	b, r6
      002CA3 EF               [12] 8807 	mov	a, r7
      002CA4                       8808 00104$:
                           002BE7  8809 	C$fuzzy.h$2676$1_0$138 ==.
                                   8810 ;	../../fuzzy.h:2676: }
      002CA4 85 08 81         [24] 8811 	mov	sp,_bp
      002CA7 D0 08            [24] 8812 	pop	_bp
                           002BEC  8813 	C$fuzzy.h$2676$1_0$138 ==.
                           002BEC  8814 	XG$fuzzy_rules_defuzzify_lom$0$0 ==.
      002CA9 22               [24] 8815 	ret
                                   8816 ;------------------------------------------------------------
                                   8817 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_method'
                                   8818 ;------------------------------------------------------------
                                   8819 ;lower         Allocated to stack - _bp -6 +4 
                                   8820 ;upper         Allocated to stack - _bp -10 +4 
                                   8821 ;step          Allocated to stack - _bp -14 +4 
                                   8822 ;defuzz_method Allocated to stack - _bp -15 +1 
                                   8823 ;implication_method Allocated to stack - _bp -16 +1 
                                   8824 ;aggregation_method Allocated to stack - _bp -17 +1 
                                   8825 ;rules         Allocated to registers r5 r6 r7 
                                   8826 ;sloc0         Allocated to stack - _bp +1 +4 
                                   8827 ;------------------------------------------------------------
                           002BED  8828 	G$fuzzy_rules_defuzzify_method$0$0 ==.
                           002BED  8829 	C$fuzzy.h$2682$1_0$141 ==.
                                   8830 ;	../../fuzzy.h:2682: float fuzzy_rules_defuzzify_method(
                                   8831 ;	-----------------------------------------
                                   8832 ;	 function fuzzy_rules_defuzzify_method
                                   8833 ;	-----------------------------------------
      002CAA                       8834 _fuzzy_rules_defuzzify_method:
      002CAA C0 08            [24] 8835 	push	_bp
      002CAC E5 81            [12] 8836 	mov	a,sp
      002CAE F5 08            [12] 8837 	mov	_bp,a
      002CB0 24 04            [12] 8838 	add	a,#0x04
      002CB2 F5 81            [12] 8839 	mov	sp,a
      002CB4 AD 82            [24] 8840 	mov	r5, dpl
      002CB6 AE 83            [24] 8841 	mov	r6, dph
      002CB8 AF F0            [24] 8842 	mov	r7, b
                           002BFD  8843 	C$fuzzy.h$2693$1_0$141 ==.
                                   8844 ;	../../fuzzy.h:2693: rules == NULL ||
      002CBA ED               [12] 8845 	mov	a,r5
      002CBB 4E               [12] 8846 	orl	a,r6
      002CBC 70 03            [24] 8847 	jnz	00140$
      002CBE 02 2D 4F         [24] 8848 	ljmp	00101$
      002CC1                       8849 00140$:
                           002C04  8850 	C$fuzzy.h$2694$1_0$141 ==.
                                   8851 ;	../../fuzzy.h:2694: rules->count == 0u ||
      002CC1 74 90            [12] 8852 	mov	a,#0x90
      002CC3 2D               [12] 8853 	add	a, r5
      002CC4 FA               [12] 8854 	mov	r2,a
      002CC5 E4               [12] 8855 	clr	a
      002CC6 3E               [12] 8856 	addc	a, r6
      002CC7 FB               [12] 8857 	mov	r3,a
      002CC8 8F 04            [24] 8858 	mov	ar4,r7
      002CCA 8A 82            [24] 8859 	mov	dpl,r2
      002CCC 8B 83            [24] 8860 	mov	dph,r3
      002CCE 8C F0            [24] 8861 	mov	b,r4
      002CD0 12 43 A8         [24] 8862 	lcall	__gptrget
      002CD3 FA               [12] 8863 	mov	r2,a
      002CD4 A3               [24] 8864 	inc	dptr
      002CD5 12 43 A8         [24] 8865 	lcall	__gptrget
      002CD8 4A               [12] 8866 	orl	a,r2
      002CD9 60 74            [24] 8867 	jz	00101$
                           002C1E  8868 	C$fuzzy.h$2695$1_0$141 ==.
                                   8869 ;	../../fuzzy.h:2695: lower > upper ||
      002CDB C0 07            [24] 8870 	push	ar7
      002CDD C0 06            [24] 8871 	push	ar6
      002CDF C0 05            [24] 8872 	push	ar5
      002CE1 E5 08            [12] 8873 	mov	a,_bp
      002CE3 24 FA            [12] 8874 	add	a,#0xfa
      002CE5 F8               [12] 8875 	mov	r0,a
      002CE6 E6               [12] 8876 	mov	a,@r0
      002CE7 C0 E0            [24] 8877 	push	acc
      002CE9 08               [12] 8878 	inc	r0
      002CEA E6               [12] 8879 	mov	a,@r0
      002CEB C0 E0            [24] 8880 	push	acc
      002CED 08               [12] 8881 	inc	r0
      002CEE E6               [12] 8882 	mov	a,@r0
      002CEF C0 E0            [24] 8883 	push	acc
      002CF1 08               [12] 8884 	inc	r0
      002CF2 E6               [12] 8885 	mov	a,@r0
      002CF3 C0 E0            [24] 8886 	push	acc
      002CF5 E5 08            [12] 8887 	mov	a,_bp
      002CF7 24 F6            [12] 8888 	add	a,#0xf6
      002CF9 F8               [12] 8889 	mov	r0,a
      002CFA 86 82            [24] 8890 	mov	dpl, @r0
      002CFC 08               [12] 8891 	inc	r0
      002CFD 86 83            [24] 8892 	mov	dph, @r0
      002CFF 08               [12] 8893 	inc	r0
      002D00 86 F0            [24] 8894 	mov	b, @r0
      002D02 08               [12] 8895 	inc	r0
      002D03 E6               [12] 8896 	mov	a, @r0
      002D04 12 41 7C         [24] 8897 	lcall	___fslt
      002D07 AC 82            [24] 8898 	mov	r4, dpl
      002D09 E5 81            [12] 8899 	mov	a,sp
      002D0B 24 FC            [12] 8900 	add	a,#0xfc
      002D0D F5 81            [12] 8901 	mov	sp,a
      002D0F D0 05            [24] 8902 	pop	ar5
      002D11 D0 06            [24] 8903 	pop	ar6
      002D13 D0 07            [24] 8904 	pop	ar7
      002D15 EC               [12] 8905 	mov	a,r4
      002D16 70 37            [24] 8906 	jnz	00101$
                           002C5B  8907 	C$fuzzy.h$2697$1_0$141 ==.
                                   8908 ;	../../fuzzy.h:2697: ) {
      002D18 C0 07            [24] 8909 	push	ar7
      002D1A C0 06            [24] 8910 	push	ar6
      002D1C C0 05            [24] 8911 	push	ar5
      002D1E E5 08            [12] 8912 	mov	a,_bp
      002D20 24 F2            [12] 8913 	add	a,#0xf2
      002D22 F8               [12] 8914 	mov	r0,a
      002D23 E6               [12] 8915 	mov	a,@r0
      002D24 C0 E0            [24] 8916 	push	acc
      002D26 08               [12] 8917 	inc	r0
      002D27 E6               [12] 8918 	mov	a,@r0
      002D28 C0 E0            [24] 8919 	push	acc
      002D2A 08               [12] 8920 	inc	r0
      002D2B E6               [12] 8921 	mov	a,@r0
      002D2C C0 E0            [24] 8922 	push	acc
      002D2E 08               [12] 8923 	inc	r0
      002D2F E6               [12] 8924 	mov	a,@r0
      002D30 C0 E0            [24] 8925 	push	acc
      002D32 90 00 00         [24] 8926 	mov	dptr,#0x0000
      002D35 E4               [12] 8927 	clr	a
      002D36 F5 F0            [12] 8928 	mov	b,a
      002D38 12 41 7C         [24] 8929 	lcall	___fslt
      002D3B E5 81            [12] 8930 	mov	a,sp
      002D3D 24 FC            [12] 8931 	add	a,#0xfc
      002D3F F5 81            [12] 8932 	mov	sp,a
      002D41 D0 05            [24] 8933 	pop	ar5
      002D43 D0 06            [24] 8934 	pop	ar6
      002D45 D0 07            [24] 8935 	pop	ar7
      002D47 E5 82            [12] 8936 	mov	a, dpl
      002D49 24 FF            [12] 8937 	add	a,#0xff
      002D4B 92 00            [24] 8938 	mov	b0,c
      002D4D 40 09            [24] 8939 	jc	00102$
      002D4F                       8940 00101$:
                           002C92  8941 	C$fuzzy.h$2698$2_0$142 ==.
                                   8942 ;	../../fuzzy.h:2698: return 0.0f;
      002D4F 90 00 00         [24] 8943 	mov	dptr,#0x0000
      002D52 E4               [12] 8944 	clr	a
      002D53 F5 F0            [12] 8945 	mov	b,a
      002D55 02 30 43         [24] 8946 	ljmp	00114$
      002D58                       8947 00102$:
                           002C9B  8948 	C$fuzzy.h$2701$1_0$141 ==.
                                   8949 ;	../../fuzzy.h:2701: switch (defuzz_method) {
      002D58 E5 08            [12] 8950 	mov	a,_bp
      002D5A 24 F1            [12] 8951 	add	a,#0xf1
      002D5C F8               [12] 8952 	mov	r0,a
      002D5D E6               [12] 8953 	mov	a,@r0
      002D5E 24 FA            [12] 8954 	add	a,#0xff - 0x05
      002D60 50 03            [24] 8955 	jnc	00144$
      002D62 02 30 3D         [24] 8956 	ljmp	00112$
      002D65                       8957 00144$:
      002D65 E5 08            [12] 8958 	mov	a,_bp
      002D67 24 F1            [12] 8959 	add	a,#0xf1
      002D69 F8               [12] 8960 	mov	r0,a
      002D6A E6               [12] 8961 	mov	a,@r0
      002D6B 26               [12] 8962 	add	a,@r0
      002D6C 26               [12] 8963 	add	a,@r0
      002D6D 90 2D 71         [24] 8964 	mov	dptr,#00145$
      002D70 73               [24] 8965 	jmp	@a+dptr
      002D71                       8966 00145$:
      002D71 02 2D 83         [24] 8967 	ljmp	00106$
      002D74 02 2D FB         [24] 8968 	ljmp	00107$
      002D77 02 2E 73         [24] 8969 	ljmp	00108$
      002D7A 02 2E E3         [24] 8970 	ljmp	00109$
      002D7D 02 2F 5B         [24] 8971 	ljmp	00110$
      002D80 02 2F D2         [24] 8972 	ljmp	00111$
                           002CC6  8973 	C$fuzzy.h$2702$2_0$143 ==.
                                   8974 ;	../../fuzzy.h:2702: case FUZZY_DEFUZZ_COG:
      002D83                       8975 00106$:
                           002CC6  8976 	C$fuzzy.h$2704$2_0$143 ==.
                                   8977 ;	../../fuzzy.h:2704: rules,
      002D83 E5 08            [12] 8978 	mov	a,_bp
      002D85 24 EF            [12] 8979 	add	a,#0xef
      002D87 F8               [12] 8980 	mov	r0,a
      002D88 E6               [12] 8981 	mov	a,@r0
      002D89 C0 E0            [24] 8982 	push	acc
      002D8B E5 08            [12] 8983 	mov	a,_bp
      002D8D 24 F0            [12] 8984 	add	a,#0xf0
      002D8F F8               [12] 8985 	mov	r0,a
      002D90 E6               [12] 8986 	mov	a,@r0
      002D91 C0 E0            [24] 8987 	push	acc
      002D93 E5 08            [12] 8988 	mov	a,_bp
      002D95 24 F2            [12] 8989 	add	a,#0xf2
      002D97 F8               [12] 8990 	mov	r0,a
      002D98 E6               [12] 8991 	mov	a,@r0
      002D99 C0 E0            [24] 8992 	push	acc
      002D9B 08               [12] 8993 	inc	r0
      002D9C E6               [12] 8994 	mov	a,@r0
      002D9D C0 E0            [24] 8995 	push	acc
      002D9F 08               [12] 8996 	inc	r0
      002DA0 E6               [12] 8997 	mov	a,@r0
      002DA1 C0 E0            [24] 8998 	push	acc
      002DA3 08               [12] 8999 	inc	r0
      002DA4 E6               [12] 9000 	mov	a,@r0
      002DA5 C0 E0            [24] 9001 	push	acc
      002DA7 E5 08            [12] 9002 	mov	a,_bp
      002DA9 24 F6            [12] 9003 	add	a,#0xf6
      002DAB F8               [12] 9004 	mov	r0,a
      002DAC E6               [12] 9005 	mov	a,@r0
      002DAD C0 E0            [24] 9006 	push	acc
      002DAF 08               [12] 9007 	inc	r0
      002DB0 E6               [12] 9008 	mov	a,@r0
      002DB1 C0 E0            [24] 9009 	push	acc
      002DB3 08               [12] 9010 	inc	r0
      002DB4 E6               [12] 9011 	mov	a,@r0
      002DB5 C0 E0            [24] 9012 	push	acc
      002DB7 08               [12] 9013 	inc	r0
      002DB8 E6               [12] 9014 	mov	a,@r0
      002DB9 C0 E0            [24] 9015 	push	acc
      002DBB E5 08            [12] 9016 	mov	a,_bp
      002DBD 24 FA            [12] 9017 	add	a,#0xfa
      002DBF F8               [12] 9018 	mov	r0,a
      002DC0 E6               [12] 9019 	mov	a,@r0
      002DC1 C0 E0            [24] 9020 	push	acc
      002DC3 08               [12] 9021 	inc	r0
      002DC4 E6               [12] 9022 	mov	a,@r0
      002DC5 C0 E0            [24] 9023 	push	acc
      002DC7 08               [12] 9024 	inc	r0
      002DC8 E6               [12] 9025 	mov	a,@r0
      002DC9 C0 E0            [24] 9026 	push	acc
      002DCB 08               [12] 9027 	inc	r0
      002DCC E6               [12] 9028 	mov	a,@r0
      002DCD C0 E0            [24] 9029 	push	acc
      002DCF 8D 82            [24] 9030 	mov	dpl, r5
      002DD1 8E 83            [24] 9031 	mov	dph, r6
      002DD3 8F F0            [24] 9032 	mov	b, r7
      002DD5 12 21 45         [24] 9033 	lcall	_fuzzy_rules_defuzzify_cog
      002DD8 A8 08            [24] 9034 	mov	r0,_bp
      002DDA 08               [12] 9035 	inc	r0
      002DDB A6 82            [24] 9036 	mov	@r0, dpl
      002DDD 08               [12] 9037 	inc	r0
      002DDE A6 83            [24] 9038 	mov	@r0, dph
      002DE0 08               [12] 9039 	inc	r0
      002DE1 A6 F0            [24] 9040 	mov	@r0, b
      002DE3 08               [12] 9041 	inc	r0
      002DE4 F6               [12] 9042 	mov	@r0,a
      002DE5 E5 81            [12] 9043 	mov	a,sp
      002DE7 24 F2            [12] 9044 	add	a,#0xf2
      002DE9 F5 81            [12] 9045 	mov	sp,a
      002DEB A8 08            [24] 9046 	mov	r0,_bp
      002DED 08               [12] 9047 	inc	r0
      002DEE 86 82            [24] 9048 	mov	dpl, @r0
      002DF0 08               [12] 9049 	inc	r0
      002DF1 86 83            [24] 9050 	mov	dph, @r0
      002DF3 08               [12] 9051 	inc	r0
      002DF4 86 F0            [24] 9052 	mov	b, @r0
      002DF6 08               [12] 9053 	inc	r0
      002DF7 E6               [12] 9054 	mov	a, @r0
      002DF8 02 30 43         [24] 9055 	ljmp	00114$
                           002D3E  9056 	C$fuzzy.h$2712$2_0$143 ==.
                                   9057 ;	../../fuzzy.h:2712: case FUZZY_DEFUZZ_BOA:
      002DFB                       9058 00107$:
                           002D3E  9059 	C$fuzzy.h$2714$2_0$143 ==.
                                   9060 ;	../../fuzzy.h:2714: rules,
      002DFB E5 08            [12] 9061 	mov	a,_bp
      002DFD 24 EF            [12] 9062 	add	a,#0xef
      002DFF F8               [12] 9063 	mov	r0,a
      002E00 E6               [12] 9064 	mov	a,@r0
      002E01 C0 E0            [24] 9065 	push	acc
      002E03 E5 08            [12] 9066 	mov	a,_bp
      002E05 24 F0            [12] 9067 	add	a,#0xf0
      002E07 F8               [12] 9068 	mov	r0,a
      002E08 E6               [12] 9069 	mov	a,@r0
      002E09 C0 E0            [24] 9070 	push	acc
      002E0B E5 08            [12] 9071 	mov	a,_bp
      002E0D 24 F2            [12] 9072 	add	a,#0xf2
      002E0F F8               [12] 9073 	mov	r0,a
      002E10 E6               [12] 9074 	mov	a,@r0
      002E11 C0 E0            [24] 9075 	push	acc
      002E13 08               [12] 9076 	inc	r0
      002E14 E6               [12] 9077 	mov	a,@r0
      002E15 C0 E0            [24] 9078 	push	acc
      002E17 08               [12] 9079 	inc	r0
      002E18 E6               [12] 9080 	mov	a,@r0
      002E19 C0 E0            [24] 9081 	push	acc
      002E1B 08               [12] 9082 	inc	r0
      002E1C E6               [12] 9083 	mov	a,@r0
      002E1D C0 E0            [24] 9084 	push	acc
      002E1F E5 08            [12] 9085 	mov	a,_bp
      002E21 24 F6            [12] 9086 	add	a,#0xf6
      002E23 F8               [12] 9087 	mov	r0,a
      002E24 E6               [12] 9088 	mov	a,@r0
      002E25 C0 E0            [24] 9089 	push	acc
      002E27 08               [12] 9090 	inc	r0
      002E28 E6               [12] 9091 	mov	a,@r0
      002E29 C0 E0            [24] 9092 	push	acc
      002E2B 08               [12] 9093 	inc	r0
      002E2C E6               [12] 9094 	mov	a,@r0
      002E2D C0 E0            [24] 9095 	push	acc
      002E2F 08               [12] 9096 	inc	r0
      002E30 E6               [12] 9097 	mov	a,@r0
      002E31 C0 E0            [24] 9098 	push	acc
      002E33 E5 08            [12] 9099 	mov	a,_bp
      002E35 24 FA            [12] 9100 	add	a,#0xfa
      002E37 F8               [12] 9101 	mov	r0,a
      002E38 E6               [12] 9102 	mov	a,@r0
      002E39 C0 E0            [24] 9103 	push	acc
      002E3B 08               [12] 9104 	inc	r0
      002E3C E6               [12] 9105 	mov	a,@r0
      002E3D C0 E0            [24] 9106 	push	acc
      002E3F 08               [12] 9107 	inc	r0
      002E40 E6               [12] 9108 	mov	a,@r0
      002E41 C0 E0            [24] 9109 	push	acc
      002E43 08               [12] 9110 	inc	r0
      002E44 E6               [12] 9111 	mov	a,@r0
      002E45 C0 E0            [24] 9112 	push	acc
      002E47 8D 82            [24] 9113 	mov	dpl, r5
      002E49 8E 83            [24] 9114 	mov	dph, r6
      002E4B 8F F0            [24] 9115 	mov	b, r7
      002E4D 12 23 58         [24] 9116 	lcall	_fuzzy_rules_defuzzify_boa
      002E50 A8 08            [24] 9117 	mov	r0,_bp
      002E52 08               [12] 9118 	inc	r0
      002E53 A6 82            [24] 9119 	mov	@r0, dpl
      002E55 08               [12] 9120 	inc	r0
      002E56 A6 83            [24] 9121 	mov	@r0, dph
      002E58 08               [12] 9122 	inc	r0
      002E59 A6 F0            [24] 9123 	mov	@r0, b
      002E5B 08               [12] 9124 	inc	r0
      002E5C F6               [12] 9125 	mov	@r0,a
      002E5D E5 81            [12] 9126 	mov	a,sp
      002E5F 24 F2            [12] 9127 	add	a,#0xf2
      002E61 F5 81            [12] 9128 	mov	sp,a
      002E63 A8 08            [24] 9129 	mov	r0,_bp
      002E65 08               [12] 9130 	inc	r0
      002E66 86 82            [24] 9131 	mov	dpl, @r0
      002E68 08               [12] 9132 	inc	r0
      002E69 86 83            [24] 9133 	mov	dph, @r0
      002E6B 08               [12] 9134 	inc	r0
      002E6C 86 F0            [24] 9135 	mov	b, @r0
      002E6E 08               [12] 9136 	inc	r0
      002E6F E6               [12] 9137 	mov	a, @r0
      002E70 02 30 43         [24] 9138 	ljmp	00114$
                           002DB6  9139 	C$fuzzy.h$2722$2_0$143 ==.
                                   9140 ;	../../fuzzy.h:2722: case FUZZY_DEFUZZ_COS:
      002E73                       9141 00108$:
                           002DB6  9142 	C$fuzzy.h$2724$2_0$143 ==.
                                   9143 ;	../../fuzzy.h:2724: rules,
      002E73 E5 08            [12] 9144 	mov	a,_bp
      002E75 24 F0            [12] 9145 	add	a,#0xf0
      002E77 F8               [12] 9146 	mov	r0,a
      002E78 E6               [12] 9147 	mov	a,@r0
      002E79 C0 E0            [24] 9148 	push	acc
      002E7B E5 08            [12] 9149 	mov	a,_bp
      002E7D 24 F2            [12] 9150 	add	a,#0xf2
      002E7F F8               [12] 9151 	mov	r0,a
      002E80 E6               [12] 9152 	mov	a,@r0
      002E81 C0 E0            [24] 9153 	push	acc
      002E83 08               [12] 9154 	inc	r0
      002E84 E6               [12] 9155 	mov	a,@r0
      002E85 C0 E0            [24] 9156 	push	acc
      002E87 08               [12] 9157 	inc	r0
      002E88 E6               [12] 9158 	mov	a,@r0
      002E89 C0 E0            [24] 9159 	push	acc
      002E8B 08               [12] 9160 	inc	r0
      002E8C E6               [12] 9161 	mov	a,@r0
      002E8D C0 E0            [24] 9162 	push	acc
      002E8F E5 08            [12] 9163 	mov	a,_bp
      002E91 24 F6            [12] 9164 	add	a,#0xf6
      002E93 F8               [12] 9165 	mov	r0,a
      002E94 E6               [12] 9166 	mov	a,@r0
      002E95 C0 E0            [24] 9167 	push	acc
      002E97 08               [12] 9168 	inc	r0
      002E98 E6               [12] 9169 	mov	a,@r0
      002E99 C0 E0            [24] 9170 	push	acc
      002E9B 08               [12] 9171 	inc	r0
      002E9C E6               [12] 9172 	mov	a,@r0
      002E9D C0 E0            [24] 9173 	push	acc
      002E9F 08               [12] 9174 	inc	r0
      002EA0 E6               [12] 9175 	mov	a,@r0
      002EA1 C0 E0            [24] 9176 	push	acc
      002EA3 E5 08            [12] 9177 	mov	a,_bp
      002EA5 24 FA            [12] 9178 	add	a,#0xfa
      002EA7 F8               [12] 9179 	mov	r0,a
      002EA8 E6               [12] 9180 	mov	a,@r0
      002EA9 C0 E0            [24] 9181 	push	acc
      002EAB 08               [12] 9182 	inc	r0
      002EAC E6               [12] 9183 	mov	a,@r0
      002EAD C0 E0            [24] 9184 	push	acc
      002EAF 08               [12] 9185 	inc	r0
      002EB0 E6               [12] 9186 	mov	a,@r0
      002EB1 C0 E0            [24] 9187 	push	acc
      002EB3 08               [12] 9188 	inc	r0
      002EB4 E6               [12] 9189 	mov	a,@r0
      002EB5 C0 E0            [24] 9190 	push	acc
      002EB7 8D 82            [24] 9191 	mov	dpl, r5
      002EB9 8E 83            [24] 9192 	mov	dph, r6
      002EBB 8F F0            [24] 9193 	mov	b, r7
      002EBD 12 26 3E         [24] 9194 	lcall	_fuzzy_rules_defuzzify_cos
      002EC0 A8 08            [24] 9195 	mov	r0,_bp
      002EC2 08               [12] 9196 	inc	r0
      002EC3 A6 82            [24] 9197 	mov	@r0, dpl
      002EC5 08               [12] 9198 	inc	r0
      002EC6 A6 83            [24] 9199 	mov	@r0, dph
      002EC8 08               [12] 9200 	inc	r0
      002EC9 A6 F0            [24] 9201 	mov	@r0, b
      002ECB 08               [12] 9202 	inc	r0
      002ECC F6               [12] 9203 	mov	@r0,a
      002ECD E5 81            [12] 9204 	mov	a,sp
      002ECF 24 F3            [12] 9205 	add	a,#0xf3
      002ED1 F5 81            [12] 9206 	mov	sp,a
      002ED3 A8 08            [24] 9207 	mov	r0,_bp
      002ED5 08               [12] 9208 	inc	r0
      002ED6 86 82            [24] 9209 	mov	dpl, @r0
      002ED8 08               [12] 9210 	inc	r0
      002ED9 86 83            [24] 9211 	mov	dph, @r0
      002EDB 08               [12] 9212 	inc	r0
      002EDC 86 F0            [24] 9213 	mov	b, @r0
      002EDE 08               [12] 9214 	inc	r0
      002EDF E6               [12] 9215 	mov	a, @r0
      002EE0 02 30 43         [24] 9216 	ljmp	00114$
                           002E26  9217 	C$fuzzy.h$2731$2_0$143 ==.
                                   9218 ;	../../fuzzy.h:2731: case FUZZY_DEFUZZ_MOM:
      002EE3                       9219 00109$:
                           002E26  9220 	C$fuzzy.h$2733$2_0$143 ==.
                                   9221 ;	../../fuzzy.h:2733: rules,
      002EE3 E5 08            [12] 9222 	mov	a,_bp
      002EE5 24 EF            [12] 9223 	add	a,#0xef
      002EE7 F8               [12] 9224 	mov	r0,a
      002EE8 E6               [12] 9225 	mov	a,@r0
      002EE9 C0 E0            [24] 9226 	push	acc
      002EEB E5 08            [12] 9227 	mov	a,_bp
      002EED 24 F0            [12] 9228 	add	a,#0xf0
      002EEF F8               [12] 9229 	mov	r0,a
      002EF0 E6               [12] 9230 	mov	a,@r0
      002EF1 C0 E0            [24] 9231 	push	acc
      002EF3 E5 08            [12] 9232 	mov	a,_bp
      002EF5 24 F2            [12] 9233 	add	a,#0xf2
      002EF7 F8               [12] 9234 	mov	r0,a
      002EF8 E6               [12] 9235 	mov	a,@r0
      002EF9 C0 E0            [24] 9236 	push	acc
      002EFB 08               [12] 9237 	inc	r0
      002EFC E6               [12] 9238 	mov	a,@r0
      002EFD C0 E0            [24] 9239 	push	acc
      002EFF 08               [12] 9240 	inc	r0
      002F00 E6               [12] 9241 	mov	a,@r0
      002F01 C0 E0            [24] 9242 	push	acc
      002F03 08               [12] 9243 	inc	r0
      002F04 E6               [12] 9244 	mov	a,@r0
      002F05 C0 E0            [24] 9245 	push	acc
      002F07 E5 08            [12] 9246 	mov	a,_bp
      002F09 24 F6            [12] 9247 	add	a,#0xf6
      002F0B F8               [12] 9248 	mov	r0,a
      002F0C E6               [12] 9249 	mov	a,@r0
      002F0D C0 E0            [24] 9250 	push	acc
      002F0F 08               [12] 9251 	inc	r0
      002F10 E6               [12] 9252 	mov	a,@r0
      002F11 C0 E0            [24] 9253 	push	acc
      002F13 08               [12] 9254 	inc	r0
      002F14 E6               [12] 9255 	mov	a,@r0
      002F15 C0 E0            [24] 9256 	push	acc
      002F17 08               [12] 9257 	inc	r0
      002F18 E6               [12] 9258 	mov	a,@r0
      002F19 C0 E0            [24] 9259 	push	acc
      002F1B E5 08            [12] 9260 	mov	a,_bp
      002F1D 24 FA            [12] 9261 	add	a,#0xfa
      002F1F F8               [12] 9262 	mov	r0,a
      002F20 E6               [12] 9263 	mov	a,@r0
      002F21 C0 E0            [24] 9264 	push	acc
      002F23 08               [12] 9265 	inc	r0
      002F24 E6               [12] 9266 	mov	a,@r0
      002F25 C0 E0            [24] 9267 	push	acc
      002F27 08               [12] 9268 	inc	r0
      002F28 E6               [12] 9269 	mov	a,@r0
      002F29 C0 E0            [24] 9270 	push	acc
      002F2B 08               [12] 9271 	inc	r0
      002F2C E6               [12] 9272 	mov	a,@r0
      002F2D C0 E0            [24] 9273 	push	acc
      002F2F 8D 82            [24] 9274 	mov	dpl, r5
      002F31 8E 83            [24] 9275 	mov	dph, r6
      002F33 8F F0            [24] 9276 	mov	b, r7
      002F35 12 29 A1         [24] 9277 	lcall	_fuzzy_rules_defuzzify_mom
      002F38 A8 08            [24] 9278 	mov	r0,_bp
      002F3A 08               [12] 9279 	inc	r0
      002F3B A6 82            [24] 9280 	mov	@r0, dpl
      002F3D 08               [12] 9281 	inc	r0
      002F3E A6 83            [24] 9282 	mov	@r0, dph
      002F40 08               [12] 9283 	inc	r0
      002F41 A6 F0            [24] 9284 	mov	@r0, b
      002F43 08               [12] 9285 	inc	r0
      002F44 F6               [12] 9286 	mov	@r0,a
      002F45 E5 81            [12] 9287 	mov	a,sp
      002F47 24 F2            [12] 9288 	add	a,#0xf2
      002F49 F5 81            [12] 9289 	mov	sp,a
      002F4B A8 08            [24] 9290 	mov	r0,_bp
      002F4D 08               [12] 9291 	inc	r0
      002F4E 86 82            [24] 9292 	mov	dpl, @r0
      002F50 08               [12] 9293 	inc	r0
      002F51 86 83            [24] 9294 	mov	dph, @r0
      002F53 08               [12] 9295 	inc	r0
      002F54 86 F0            [24] 9296 	mov	b, @r0
      002F56 08               [12] 9297 	inc	r0
      002F57 E6               [12] 9298 	mov	a, @r0
      002F58 02 30 43         [24] 9299 	ljmp	00114$
                           002E9E  9300 	C$fuzzy.h$2741$2_0$143 ==.
                                   9301 ;	../../fuzzy.h:2741: case FUZZY_DEFUZZ_SOM:
      002F5B                       9302 00110$:
                           002E9E  9303 	C$fuzzy.h$2743$2_0$143 ==.
                                   9304 ;	../../fuzzy.h:2743: rules,
      002F5B E5 08            [12] 9305 	mov	a,_bp
      002F5D 24 EF            [12] 9306 	add	a,#0xef
      002F5F F8               [12] 9307 	mov	r0,a
      002F60 E6               [12] 9308 	mov	a,@r0
      002F61 C0 E0            [24] 9309 	push	acc
      002F63 E5 08            [12] 9310 	mov	a,_bp
      002F65 24 F0            [12] 9311 	add	a,#0xf0
      002F67 F8               [12] 9312 	mov	r0,a
      002F68 E6               [12] 9313 	mov	a,@r0
      002F69 C0 E0            [24] 9314 	push	acc
      002F6B E5 08            [12] 9315 	mov	a,_bp
      002F6D 24 F2            [12] 9316 	add	a,#0xf2
      002F6F F8               [12] 9317 	mov	r0,a
      002F70 E6               [12] 9318 	mov	a,@r0
      002F71 C0 E0            [24] 9319 	push	acc
      002F73 08               [12] 9320 	inc	r0
      002F74 E6               [12] 9321 	mov	a,@r0
      002F75 C0 E0            [24] 9322 	push	acc
      002F77 08               [12] 9323 	inc	r0
      002F78 E6               [12] 9324 	mov	a,@r0
      002F79 C0 E0            [24] 9325 	push	acc
      002F7B 08               [12] 9326 	inc	r0
      002F7C E6               [12] 9327 	mov	a,@r0
      002F7D C0 E0            [24] 9328 	push	acc
      002F7F E5 08            [12] 9329 	mov	a,_bp
      002F81 24 F6            [12] 9330 	add	a,#0xf6
      002F83 F8               [12] 9331 	mov	r0,a
      002F84 E6               [12] 9332 	mov	a,@r0
      002F85 C0 E0            [24] 9333 	push	acc
      002F87 08               [12] 9334 	inc	r0
      002F88 E6               [12] 9335 	mov	a,@r0
      002F89 C0 E0            [24] 9336 	push	acc
      002F8B 08               [12] 9337 	inc	r0
      002F8C E6               [12] 9338 	mov	a,@r0
      002F8D C0 E0            [24] 9339 	push	acc
      002F8F 08               [12] 9340 	inc	r0
      002F90 E6               [12] 9341 	mov	a,@r0
      002F91 C0 E0            [24] 9342 	push	acc
      002F93 E5 08            [12] 9343 	mov	a,_bp
      002F95 24 FA            [12] 9344 	add	a,#0xfa
      002F97 F8               [12] 9345 	mov	r0,a
      002F98 E6               [12] 9346 	mov	a,@r0
      002F99 C0 E0            [24] 9347 	push	acc
      002F9B 08               [12] 9348 	inc	r0
      002F9C E6               [12] 9349 	mov	a,@r0
      002F9D C0 E0            [24] 9350 	push	acc
      002F9F 08               [12] 9351 	inc	r0
      002FA0 E6               [12] 9352 	mov	a,@r0
      002FA1 C0 E0            [24] 9353 	push	acc
      002FA3 08               [12] 9354 	inc	r0
      002FA4 E6               [12] 9355 	mov	a,@r0
      002FA5 C0 E0            [24] 9356 	push	acc
      002FA7 8D 82            [24] 9357 	mov	dpl, r5
      002FA9 8E 83            [24] 9358 	mov	dph, r6
      002FAB 8F F0            [24] 9359 	mov	b, r7
      002FAD 12 2A D8         [24] 9360 	lcall	_fuzzy_rules_defuzzify_som
      002FB0 A8 08            [24] 9361 	mov	r0,_bp
      002FB2 08               [12] 9362 	inc	r0
      002FB3 A6 82            [24] 9363 	mov	@r0, dpl
      002FB5 08               [12] 9364 	inc	r0
      002FB6 A6 83            [24] 9365 	mov	@r0, dph
      002FB8 08               [12] 9366 	inc	r0
      002FB9 A6 F0            [24] 9367 	mov	@r0, b
      002FBB 08               [12] 9368 	inc	r0
      002FBC F6               [12] 9369 	mov	@r0,a
      002FBD E5 81            [12] 9370 	mov	a,sp
      002FBF 24 F2            [12] 9371 	add	a,#0xf2
      002FC1 F5 81            [12] 9372 	mov	sp,a
      002FC3 A8 08            [24] 9373 	mov	r0,_bp
      002FC5 08               [12] 9374 	inc	r0
      002FC6 86 82            [24] 9375 	mov	dpl, @r0
      002FC8 08               [12] 9376 	inc	r0
      002FC9 86 83            [24] 9377 	mov	dph, @r0
      002FCB 08               [12] 9378 	inc	r0
      002FCC 86 F0            [24] 9379 	mov	b, @r0
      002FCE 08               [12] 9380 	inc	r0
      002FCF E6               [12] 9381 	mov	a, @r0
                           002F13  9382 	C$fuzzy.h$2751$2_0$143 ==.
                                   9383 ;	../../fuzzy.h:2751: case FUZZY_DEFUZZ_LOM:
      002FD0 80 71            [24] 9384 	sjmp	00114$
      002FD2                       9385 00111$:
                           002F15  9386 	C$fuzzy.h$2753$2_0$143 ==.
                                   9387 ;	../../fuzzy.h:2753: rules,
      002FD2 E5 08            [12] 9388 	mov	a,_bp
      002FD4 24 EF            [12] 9389 	add	a,#0xef
      002FD6 F8               [12] 9390 	mov	r0,a
      002FD7 E6               [12] 9391 	mov	a,@r0
      002FD8 C0 E0            [24] 9392 	push	acc
      002FDA E5 08            [12] 9393 	mov	a,_bp
      002FDC 24 F0            [12] 9394 	add	a,#0xf0
      002FDE F8               [12] 9395 	mov	r0,a
      002FDF E6               [12] 9396 	mov	a,@r0
      002FE0 C0 E0            [24] 9397 	push	acc
      002FE2 E5 08            [12] 9398 	mov	a,_bp
      002FE4 24 F2            [12] 9399 	add	a,#0xf2
      002FE6 F8               [12] 9400 	mov	r0,a
      002FE7 E6               [12] 9401 	mov	a,@r0
      002FE8 C0 E0            [24] 9402 	push	acc
      002FEA 08               [12] 9403 	inc	r0
      002FEB E6               [12] 9404 	mov	a,@r0
      002FEC C0 E0            [24] 9405 	push	acc
      002FEE 08               [12] 9406 	inc	r0
      002FEF E6               [12] 9407 	mov	a,@r0
      002FF0 C0 E0            [24] 9408 	push	acc
      002FF2 08               [12] 9409 	inc	r0
      002FF3 E6               [12] 9410 	mov	a,@r0
      002FF4 C0 E0            [24] 9411 	push	acc
      002FF6 E5 08            [12] 9412 	mov	a,_bp
      002FF8 24 F6            [12] 9413 	add	a,#0xf6
      002FFA F8               [12] 9414 	mov	r0,a
      002FFB E6               [12] 9415 	mov	a,@r0
      002FFC C0 E0            [24] 9416 	push	acc
      002FFE 08               [12] 9417 	inc	r0
      002FFF E6               [12] 9418 	mov	a,@r0
      003000 C0 E0            [24] 9419 	push	acc
      003002 08               [12] 9420 	inc	r0
      003003 E6               [12] 9421 	mov	a,@r0
      003004 C0 E0            [24] 9422 	push	acc
      003006 08               [12] 9423 	inc	r0
      003007 E6               [12] 9424 	mov	a,@r0
      003008 C0 E0            [24] 9425 	push	acc
      00300A E5 08            [12] 9426 	mov	a,_bp
      00300C 24 FA            [12] 9427 	add	a,#0xfa
      00300E F8               [12] 9428 	mov	r0,a
      00300F E6               [12] 9429 	mov	a,@r0
      003010 C0 E0            [24] 9430 	push	acc
      003012 08               [12] 9431 	inc	r0
      003013 E6               [12] 9432 	mov	a,@r0
      003014 C0 E0            [24] 9433 	push	acc
      003016 08               [12] 9434 	inc	r0
      003017 E6               [12] 9435 	mov	a,@r0
      003018 C0 E0            [24] 9436 	push	acc
      00301A 08               [12] 9437 	inc	r0
      00301B E6               [12] 9438 	mov	a,@r0
      00301C C0 E0            [24] 9439 	push	acc
      00301E 8D 82            [24] 9440 	mov	dpl, r5
      003020 8E 83            [24] 9441 	mov	dph, r6
      003022 8F F0            [24] 9442 	mov	b, r7
      003024 12 2B C1         [24] 9443 	lcall	_fuzzy_rules_defuzzify_lom
      003027 AC 82            [24] 9444 	mov	r4, dpl
      003029 AD 83            [24] 9445 	mov	r5, dph
      00302B AE F0            [24] 9446 	mov	r6, b
      00302D FF               [12] 9447 	mov	r7, a
      00302E E5 81            [12] 9448 	mov	a,sp
      003030 24 F2            [12] 9449 	add	a,#0xf2
      003032 F5 81            [12] 9450 	mov	sp,a
      003034 8C 82            [24] 9451 	mov	dpl, r4
      003036 8D 83            [24] 9452 	mov	dph, r5
      003038 8E F0            [24] 9453 	mov	b, r6
      00303A EF               [12] 9454 	mov	a, r7
                           002F7E  9455 	C$fuzzy.h$2761$2_0$143 ==.
                                   9456 ;	../../fuzzy.h:2761: default:
      00303B 80 06            [24] 9457 	sjmp	00114$
      00303D                       9458 00112$:
                           002F80  9459 	C$fuzzy.h$2762$2_0$143 ==.
                                   9460 ;	../../fuzzy.h:2762: return 0.0f;
      00303D 90 00 00         [24] 9461 	mov	dptr,#0x0000
      003040 E4               [12] 9462 	clr	a
      003041 F5 F0            [12] 9463 	mov	b,a
                           002F86  9464 	C$fuzzy.h$2763$1_0$141 ==.
                                   9465 ;	../../fuzzy.h:2763: }
      003043                       9466 00114$:
                           002F86  9467 	C$fuzzy.h$2764$1_0$141 ==.
                                   9468 ;	../../fuzzy.h:2764: }
      003043 85 08 81         [24] 9469 	mov	sp,_bp
      003046 D0 08            [24] 9470 	pop	_bp
                           002F8B  9471 	C$fuzzy.h$2764$1_0$141 ==.
                           002F8B  9472 	XG$fuzzy_rules_defuzzify_method$0$0 ==.
      003048 22               [24] 9473 	ret
                                   9474 ;------------------------------------------------------------
                                   9475 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify'
                                   9476 ;------------------------------------------------------------
                                   9477 ;lower         Allocated to stack - _bp -6 +4 
                                   9478 ;upper         Allocated to stack - _bp -10 +4 
                                   9479 ;step          Allocated to stack - _bp -14 +4 
                                   9480 ;method        Allocated to stack - _bp -15 +1 
                                   9481 ;rules         Allocated to registers r5 r6 r7 
                                   9482 ;------------------------------------------------------------
                           002F8C  9483 	G$fuzzy_rules_defuzzify$0$0 ==.
                           002F8C  9484 	C$fuzzy.h$2771$1_0$145 ==.
                                   9485 ;	../../fuzzy.h:2771: float fuzzy_rules_defuzzify(
                                   9486 ;	-----------------------------------------
                                   9487 ;	 function fuzzy_rules_defuzzify
                                   9488 ;	-----------------------------------------
      003049                       9489 _fuzzy_rules_defuzzify:
      003049 C0 08            [24] 9490 	push	_bp
      00304B 85 81 08         [24] 9491 	mov	_bp,sp
      00304E AD 82            [24] 9492 	mov	r5, dpl
      003050 AE 83            [24] 9493 	mov	r6, dph
      003052 AF F0            [24] 9494 	mov	r7, b
                           002F97  9495 	C$fuzzy.h$2780$1_0$145 ==.
                                   9496 ;	../../fuzzy.h:2780: rules,
      003054 E4               [12] 9497 	clr	a
      003055 C0 E0            [24] 9498 	push	acc
      003057 C0 E0            [24] 9499 	push	acc
      003059 E5 08            [12] 9500 	mov	a,_bp
      00305B 24 F1            [12] 9501 	add	a,#0xf1
      00305D F8               [12] 9502 	mov	r0,a
      00305E E6               [12] 9503 	mov	a,@r0
      00305F C0 E0            [24] 9504 	push	acc
      003061 E5 08            [12] 9505 	mov	a,_bp
      003063 24 F2            [12] 9506 	add	a,#0xf2
      003065 F8               [12] 9507 	mov	r0,a
      003066 E6               [12] 9508 	mov	a,@r0
      003067 C0 E0            [24] 9509 	push	acc
      003069 08               [12] 9510 	inc	r0
      00306A E6               [12] 9511 	mov	a,@r0
      00306B C0 E0            [24] 9512 	push	acc
      00306D 08               [12] 9513 	inc	r0
      00306E E6               [12] 9514 	mov	a,@r0
      00306F C0 E0            [24] 9515 	push	acc
      003071 08               [12] 9516 	inc	r0
      003072 E6               [12] 9517 	mov	a,@r0
      003073 C0 E0            [24] 9518 	push	acc
      003075 E5 08            [12] 9519 	mov	a,_bp
      003077 24 F6            [12] 9520 	add	a,#0xf6
      003079 F8               [12] 9521 	mov	r0,a
      00307A E6               [12] 9522 	mov	a,@r0
      00307B C0 E0            [24] 9523 	push	acc
      00307D 08               [12] 9524 	inc	r0
      00307E E6               [12] 9525 	mov	a,@r0
      00307F C0 E0            [24] 9526 	push	acc
      003081 08               [12] 9527 	inc	r0
      003082 E6               [12] 9528 	mov	a,@r0
      003083 C0 E0            [24] 9529 	push	acc
      003085 08               [12] 9530 	inc	r0
      003086 E6               [12] 9531 	mov	a,@r0
      003087 C0 E0            [24] 9532 	push	acc
      003089 E5 08            [12] 9533 	mov	a,_bp
      00308B 24 FA            [12] 9534 	add	a,#0xfa
      00308D F8               [12] 9535 	mov	r0,a
      00308E E6               [12] 9536 	mov	a,@r0
      00308F C0 E0            [24] 9537 	push	acc
      003091 08               [12] 9538 	inc	r0
      003092 E6               [12] 9539 	mov	a,@r0
      003093 C0 E0            [24] 9540 	push	acc
      003095 08               [12] 9541 	inc	r0
      003096 E6               [12] 9542 	mov	a,@r0
      003097 C0 E0            [24] 9543 	push	acc
      003099 08               [12] 9544 	inc	r0
      00309A E6               [12] 9545 	mov	a,@r0
      00309B C0 E0            [24] 9546 	push	acc
      00309D 8D 82            [24] 9547 	mov	dpl, r5
      00309F 8E 83            [24] 9548 	mov	dph, r6
      0030A1 8F F0            [24] 9549 	mov	b, r7
      0030A3 12 2C AA         [24] 9550 	lcall	_fuzzy_rules_defuzzify_method
      0030A6 AC 82            [24] 9551 	mov	r4, dpl
      0030A8 AD 83            [24] 9552 	mov	r5, dph
      0030AA AE F0            [24] 9553 	mov	r6, b
      0030AC FF               [12] 9554 	mov	r7, a
      0030AD E5 81            [12] 9555 	mov	a,sp
      0030AF 24 F1            [12] 9556 	add	a,#0xf1
      0030B1 F5 81            [12] 9557 	mov	sp,a
      0030B3 8C 82            [24] 9558 	mov	dpl, r4
      0030B5 8D 83            [24] 9559 	mov	dph, r5
      0030B7 8E F0            [24] 9560 	mov	b, r6
      0030B9 EF               [12] 9561 	mov	a, r7
                           002FFD  9562 	C$fuzzy.h$2788$1_0$145 ==.
                                   9563 ;	../../fuzzy.h:2788: }
      0030BA D0 08            [24] 9564 	pop	_bp
                           002FFF  9565 	C$fuzzy.h$2788$1_0$145 ==.
                           002FFF  9566 	XG$fuzzy_rules_defuzzify$0$0 ==.
      0030BC 22               [24] 9567 	ret
                                   9568 ;------------------------------------------------------------
                                   9569 ;Allocation info for local variables in function 'fuzzy_rules_cog'
                                   9570 ;------------------------------------------------------------
                                   9571 ;lower         Allocated to stack - _bp -6 +4 
                                   9572 ;upper         Allocated to stack - _bp -10 +4 
                                   9573 ;step          Allocated to stack - _bp -14 +4 
                                   9574 ;rules         Allocated to registers r5 r6 r7 
                                   9575 ;------------------------------------------------------------
                           003000  9576 	G$fuzzy_rules_cog$0$0 ==.
                           003000  9577 	C$fuzzy.h$2794$1_0$147 ==.
                                   9578 ;	../../fuzzy.h:2794: float fuzzy_rules_cog(
                                   9579 ;	-----------------------------------------
                                   9580 ;	 function fuzzy_rules_cog
                                   9581 ;	-----------------------------------------
      0030BD                       9582 _fuzzy_rules_cog:
      0030BD C0 08            [24] 9583 	push	_bp
      0030BF 85 81 08         [24] 9584 	mov	_bp,sp
      0030C2 AD 82            [24] 9585 	mov	r5, dpl
      0030C4 AE 83            [24] 9586 	mov	r6, dph
      0030C6 AF F0            [24] 9587 	mov	r7, b
                           00300B  9588 	C$fuzzy.h$2802$1_0$147 ==.
                                   9589 ;	../../fuzzy.h:2802: rules,
      0030C8 E4               [12] 9590 	clr	a
      0030C9 C0 E0            [24] 9591 	push	acc
      0030CB C0 E0            [24] 9592 	push	acc
      0030CD E5 08            [12] 9593 	mov	a,_bp
      0030CF 24 F2            [12] 9594 	add	a,#0xf2
      0030D1 F8               [12] 9595 	mov	r0,a
      0030D2 E6               [12] 9596 	mov	a,@r0
      0030D3 C0 E0            [24] 9597 	push	acc
      0030D5 08               [12] 9598 	inc	r0
      0030D6 E6               [12] 9599 	mov	a,@r0
      0030D7 C0 E0            [24] 9600 	push	acc
      0030D9 08               [12] 9601 	inc	r0
      0030DA E6               [12] 9602 	mov	a,@r0
      0030DB C0 E0            [24] 9603 	push	acc
      0030DD 08               [12] 9604 	inc	r0
      0030DE E6               [12] 9605 	mov	a,@r0
      0030DF C0 E0            [24] 9606 	push	acc
      0030E1 E5 08            [12] 9607 	mov	a,_bp
      0030E3 24 F6            [12] 9608 	add	a,#0xf6
      0030E5 F8               [12] 9609 	mov	r0,a
      0030E6 E6               [12] 9610 	mov	a,@r0
      0030E7 C0 E0            [24] 9611 	push	acc
      0030E9 08               [12] 9612 	inc	r0
      0030EA E6               [12] 9613 	mov	a,@r0
      0030EB C0 E0            [24] 9614 	push	acc
      0030ED 08               [12] 9615 	inc	r0
      0030EE E6               [12] 9616 	mov	a,@r0
      0030EF C0 E0            [24] 9617 	push	acc
      0030F1 08               [12] 9618 	inc	r0
      0030F2 E6               [12] 9619 	mov	a,@r0
      0030F3 C0 E0            [24] 9620 	push	acc
      0030F5 E5 08            [12] 9621 	mov	a,_bp
      0030F7 24 FA            [12] 9622 	add	a,#0xfa
      0030F9 F8               [12] 9623 	mov	r0,a
      0030FA E6               [12] 9624 	mov	a,@r0
      0030FB C0 E0            [24] 9625 	push	acc
      0030FD 08               [12] 9626 	inc	r0
      0030FE E6               [12] 9627 	mov	a,@r0
      0030FF C0 E0            [24] 9628 	push	acc
      003101 08               [12] 9629 	inc	r0
      003102 E6               [12] 9630 	mov	a,@r0
      003103 C0 E0            [24] 9631 	push	acc
      003105 08               [12] 9632 	inc	r0
      003106 E6               [12] 9633 	mov	a,@r0
      003107 C0 E0            [24] 9634 	push	acc
      003109 8D 82            [24] 9635 	mov	dpl, r5
      00310B 8E 83            [24] 9636 	mov	dph, r6
      00310D 8F F0            [24] 9637 	mov	b, r7
      00310F 12 21 45         [24] 9638 	lcall	_fuzzy_rules_defuzzify_cog
      003112 AC 82            [24] 9639 	mov	r4, dpl
      003114 AD 83            [24] 9640 	mov	r5, dph
      003116 AE F0            [24] 9641 	mov	r6, b
      003118 FF               [12] 9642 	mov	r7, a
      003119 E5 81            [12] 9643 	mov	a,sp
      00311B 24 F2            [12] 9644 	add	a,#0xf2
      00311D F5 81            [12] 9645 	mov	sp,a
      00311F 8C 82            [24] 9646 	mov	dpl, r4
      003121 8D 83            [24] 9647 	mov	dph, r5
      003123 8E F0            [24] 9648 	mov	b, r6
      003125 EF               [12] 9649 	mov	a, r7
                           003069  9650 	C$fuzzy.h$2809$1_0$147 ==.
                                   9651 ;	../../fuzzy.h:2809: }
      003126 D0 08            [24] 9652 	pop	_bp
                           00306B  9653 	C$fuzzy.h$2809$1_0$147 ==.
                           00306B  9654 	XG$fuzzy_rules_cog$0$0 ==.
      003128 22               [24] 9655 	ret
                                   9656 ;------------------------------------------------------------
                                   9657 ;Allocation info for local variables in function 'temperature_low'
                                   9658 ;------------------------------------------------------------
                                   9659 ;value         Allocated to registers r4 r5 r6 r7 
                                   9660 ;------------------------------------------------------------
                           00306C  9661 	Fsugeno_demo$temperature_low$0$0 ==.
                           00306C  9662 	C$sugeno_demo.c$62$1_0$149 ==.
                                   9663 ;	../../sugeno_demo.c:62: static float temperature_low(float value)
                                   9664 ;	-----------------------------------------
                                   9665 ;	 function temperature_low
                                   9666 ;	-----------------------------------------
      003129                       9667 _temperature_low:
      003129 AC 82            [24] 9668 	mov	r4,dpl
      00312B AD 83            [24] 9669 	mov	r5,dph
      00312D AE F0            [24] 9670 	mov	r6,b
      00312F FF               [12] 9671 	mov	r7,a
                           003073  9672 	C$sugeno_demo.c$69$1_0$149 ==.
                                   9673 ;	../../sugeno_demo.c:69: hedges.none
      003130 90 44 6A         [24] 9674 	mov	dptr,#_hedges
      003133 E4               [12] 9675 	clr	a
      003134 93               [24] 9676 	movc	a,@a+dptr
      003135 FB               [12] 9677 	mov	r3,a
                           003079  9678 	C$sugeno_demo.c$65$1_0$149 ==.
                                   9679 ;	../../sugeno_demo.c:65: 15.0f,
      003136 C0 03            [24] 9680 	push	ar3
      003138 E4               [12] 9681 	clr	a
      003139 C0 E0            [24] 9682 	push	acc
      00313B C0 04            [24] 9683 	push	ar4
      00313D C0 05            [24] 9684 	push	ar5
      00313F C0 06            [24] 9685 	push	ar6
      003141 C0 07            [24] 9686 	push	ar7
      003143 C0 E0            [24] 9687 	push	acc
      003145 C0 E0            [24] 9688 	push	acc
      003147 74 20            [12] 9689 	mov	a,#0x20
      003149 C0 E0            [24] 9690 	push	acc
      00314B 74 42            [12] 9691 	mov	a,#0x42
      00314D C0 E0            [24] 9692 	push	acc
      00314F 90 00 00         [24] 9693 	mov	dptr,#0x0000
      003152 75 F0 70         [24] 9694 	mov	b, #0x70
      003155 14               [12] 9695 	dec	a
      003156 12 0A F2         [24] 9696 	lcall	_fuzzy_ramp
      003159 AC 82            [24] 9697 	mov	r4, dpl
      00315B AD 83            [24] 9698 	mov	r5, dph
      00315D AE F0            [24] 9699 	mov	r6, b
      00315F FF               [12] 9700 	mov	r7, a
      003160 E5 81            [12] 9701 	mov	a,sp
      003162 24 F6            [12] 9702 	add	a,#0xf6
      003164 F5 81            [12] 9703 	mov	sp,a
      003166 8C 82            [24] 9704 	mov	dpl, r4
      003168 8D 83            [24] 9705 	mov	dph, r5
      00316A 8E F0            [24] 9706 	mov	b, r6
      00316C EF               [12] 9707 	mov	a, r7
                           0030B0  9708 	C$sugeno_demo.c$71$1_0$149 ==.
                                   9709 ;	../../sugeno_demo.c:71: }
                           0030B0  9710 	C$sugeno_demo.c$71$1_0$149 ==.
                           0030B0  9711 	XFsugeno_demo$temperature_low$0$0 ==.
      00316D 22               [24] 9712 	ret
                                   9713 ;------------------------------------------------------------
                                   9714 ;Allocation info for local variables in function 'temperature_high'
                                   9715 ;------------------------------------------------------------
                                   9716 ;value         Allocated to registers r4 r5 r6 r7 
                                   9717 ;------------------------------------------------------------
                           0030B1  9718 	Fsugeno_demo$temperature_high$0$0 ==.
                           0030B1  9719 	C$sugeno_demo.c$74$1_0$151 ==.
                                   9720 ;	../../sugeno_demo.c:74: static float temperature_high(float value)
                                   9721 ;	-----------------------------------------
                                   9722 ;	 function temperature_high
                                   9723 ;	-----------------------------------------
      00316E                       9724 _temperature_high:
      00316E AC 82            [24] 9725 	mov	r4,dpl
      003170 AD 83            [24] 9726 	mov	r5,dph
      003172 AE F0            [24] 9727 	mov	r6,b
      003174 FF               [12] 9728 	mov	r7,a
                           0030B8  9729 	C$sugeno_demo.c$81$1_0$151 ==.
                                   9730 ;	../../sugeno_demo.c:81: hedges.none
      003175 90 44 6A         [24] 9731 	mov	dptr,#_hedges
      003178 E4               [12] 9732 	clr	a
      003179 93               [24] 9733 	movc	a,@a+dptr
      00317A FB               [12] 9734 	mov	r3,a
                           0030BE  9735 	C$sugeno_demo.c$77$1_0$151 ==.
                                   9736 ;	../../sugeno_demo.c:77: 35.0f,
      00317B C0 03            [24] 9737 	push	ar3
      00317D 74 01            [12] 9738 	mov	a,#0x01
      00317F C0 E0            [24] 9739 	push	acc
      003181 C0 04            [24] 9740 	push	ar4
      003183 C0 05            [24] 9741 	push	ar5
      003185 C0 06            [24] 9742 	push	ar6
      003187 C0 07            [24] 9743 	push	ar7
      003189 E4               [12] 9744 	clr	a
      00318A C0 E0            [24] 9745 	push	acc
      00318C C0 E0            [24] 9746 	push	acc
      00318E 74 96            [12] 9747 	mov	a,#0x96
      003190 C0 E0            [24] 9748 	push	acc
      003192 74 42            [12] 9749 	mov	a,#0x42
      003194 C0 E0            [24] 9750 	push	acc
      003196 90 00 00         [24] 9751 	mov	dptr,#0x0000
      003199 75 F0 0C         [24] 9752 	mov	b, #0x0c
      00319C 12 0A F2         [24] 9753 	lcall	_fuzzy_ramp
      00319F AC 82            [24] 9754 	mov	r4, dpl
      0031A1 AD 83            [24] 9755 	mov	r5, dph
      0031A3 AE F0            [24] 9756 	mov	r6, b
      0031A5 FF               [12] 9757 	mov	r7, a
      0031A6 E5 81            [12] 9758 	mov	a,sp
      0031A8 24 F6            [12] 9759 	add	a,#0xf6
      0031AA F5 81            [12] 9760 	mov	sp,a
      0031AC 8C 82            [24] 9761 	mov	dpl, r4
      0031AE 8D 83            [24] 9762 	mov	dph, r5
      0031B0 8E F0            [24] 9763 	mov	b, r6
      0031B2 EF               [12] 9764 	mov	a, r7
                           0030F6  9765 	C$sugeno_demo.c$83$1_0$151 ==.
                                   9766 ;	../../sugeno_demo.c:83: }
                           0030F6  9767 	C$sugeno_demo.c$83$1_0$151 ==.
                           0030F6  9768 	XFsugeno_demo$temperature_high$0$0 ==.
      0031B3 22               [24] 9769 	ret
                                   9770 ;------------------------------------------------------------
                                   9771 ;Allocation info for local variables in function 'load_low'
                                   9772 ;------------------------------------------------------------
                                   9773 ;value         Allocated to registers r4 r5 r6 r7 
                                   9774 ;------------------------------------------------------------
                           0030F7  9775 	Fsugeno_demo$load_low$0$0 ==.
                           0030F7  9776 	C$sugeno_demo.c$90$1_0$153 ==.
                                   9777 ;	../../sugeno_demo.c:90: static float load_low(float value)
                                   9778 ;	-----------------------------------------
                                   9779 ;	 function load_low
                                   9780 ;	-----------------------------------------
      0031B4                       9781 _load_low:
      0031B4 AC 82            [24] 9782 	mov	r4,dpl
      0031B6 AD 83            [24] 9783 	mov	r5,dph
      0031B8 AE F0            [24] 9784 	mov	r6,b
      0031BA FF               [12] 9785 	mov	r7,a
                           0030FE  9786 	C$sugeno_demo.c$97$1_0$153 ==.
                                   9787 ;	../../sugeno_demo.c:97: hedges.none
      0031BB 90 44 6A         [24] 9788 	mov	dptr,#_hedges
      0031BE E4               [12] 9789 	clr	a
      0031BF 93               [24] 9790 	movc	a,@a+dptr
      0031C0 FB               [12] 9791 	mov	r3,a
                           003104  9792 	C$sugeno_demo.c$93$1_0$153 ==.
                                   9793 ;	../../sugeno_demo.c:93: 20.0f,
      0031C1 C0 03            [24] 9794 	push	ar3
      0031C3 E4               [12] 9795 	clr	a
      0031C4 C0 E0            [24] 9796 	push	acc
      0031C6 C0 04            [24] 9797 	push	ar4
      0031C8 C0 05            [24] 9798 	push	ar5
      0031CA C0 06            [24] 9799 	push	ar6
      0031CC C0 07            [24] 9800 	push	ar7
      0031CE C0 E0            [24] 9801 	push	acc
      0031D0 C0 E0            [24] 9802 	push	acc
      0031D2 74 48            [12] 9803 	mov	a,#0x48
      0031D4 C0 E0            [24] 9804 	push	acc
      0031D6 74 42            [12] 9805 	mov	a,#0x42
      0031D8 C0 E0            [24] 9806 	push	acc
      0031DA 90 00 00         [24] 9807 	mov	dptr,#0x0000
      0031DD 75 F0 A0         [24] 9808 	mov	b, #0xa0
      0031E0 14               [12] 9809 	dec	a
      0031E1 12 0A F2         [24] 9810 	lcall	_fuzzy_ramp
      0031E4 AC 82            [24] 9811 	mov	r4, dpl
      0031E6 AD 83            [24] 9812 	mov	r5, dph
      0031E8 AE F0            [24] 9813 	mov	r6, b
      0031EA FF               [12] 9814 	mov	r7, a
      0031EB E5 81            [12] 9815 	mov	a,sp
      0031ED 24 F6            [12] 9816 	add	a,#0xf6
      0031EF F5 81            [12] 9817 	mov	sp,a
      0031F1 8C 82            [24] 9818 	mov	dpl, r4
      0031F3 8D 83            [24] 9819 	mov	dph, r5
      0031F5 8E F0            [24] 9820 	mov	b, r6
      0031F7 EF               [12] 9821 	mov	a, r7
                           00313B  9822 	C$sugeno_demo.c$99$1_0$153 ==.
                                   9823 ;	../../sugeno_demo.c:99: }
                           00313B  9824 	C$sugeno_demo.c$99$1_0$153 ==.
                           00313B  9825 	XFsugeno_demo$load_low$0$0 ==.
      0031F8 22               [24] 9826 	ret
                                   9827 ;------------------------------------------------------------
                                   9828 ;Allocation info for local variables in function 'load_high'
                                   9829 ;------------------------------------------------------------
                                   9830 ;value         Allocated to registers r4 r5 r6 r7 
                                   9831 ;------------------------------------------------------------
                           00313C  9832 	Fsugeno_demo$load_high$0$0 ==.
                           00313C  9833 	C$sugeno_demo.c$102$1_0$155 ==.
                                   9834 ;	../../sugeno_demo.c:102: static float load_high(float value)
                                   9835 ;	-----------------------------------------
                                   9836 ;	 function load_high
                                   9837 ;	-----------------------------------------
      0031F9                       9838 _load_high:
      0031F9 AC 82            [24] 9839 	mov	r4,dpl
      0031FB AD 83            [24] 9840 	mov	r5,dph
      0031FD AE F0            [24] 9841 	mov	r6,b
      0031FF FF               [12] 9842 	mov	r7,a
                           003143  9843 	C$sugeno_demo.c$109$1_0$155 ==.
                                   9844 ;	../../sugeno_demo.c:109: hedges.none
      003200 90 44 6A         [24] 9845 	mov	dptr,#_hedges
      003203 E4               [12] 9846 	clr	a
      003204 93               [24] 9847 	movc	a,@a+dptr
      003205 FB               [12] 9848 	mov	r3,a
                           003149  9849 	C$sugeno_demo.c$105$1_0$155 ==.
                                   9850 ;	../../sugeno_demo.c:105: 45.0f,
      003206 C0 03            [24] 9851 	push	ar3
      003208 74 01            [12] 9852 	mov	a,#0x01
      00320A C0 E0            [24] 9853 	push	acc
      00320C C0 04            [24] 9854 	push	ar4
      00320E C0 05            [24] 9855 	push	ar5
      003210 C0 06            [24] 9856 	push	ar6
      003212 C0 07            [24] 9857 	push	ar7
      003214 E4               [12] 9858 	clr	a
      003215 C0 E0            [24] 9859 	push	acc
      003217 C0 E0            [24] 9860 	push	acc
      003219 74 AA            [12] 9861 	mov	a,#0xaa
      00321B C0 E0            [24] 9862 	push	acc
      00321D 74 42            [12] 9863 	mov	a,#0x42
      00321F C0 E0            [24] 9864 	push	acc
      003221 90 00 00         [24] 9865 	mov	dptr,#0x0000
      003224 75 F0 34         [24] 9866 	mov	b, #0x34
      003227 12 0A F2         [24] 9867 	lcall	_fuzzy_ramp
      00322A AC 82            [24] 9868 	mov	r4, dpl
      00322C AD 83            [24] 9869 	mov	r5, dph
      00322E AE F0            [24] 9870 	mov	r6, b
      003230 FF               [12] 9871 	mov	r7, a
      003231 E5 81            [12] 9872 	mov	a,sp
      003233 24 F6            [12] 9873 	add	a,#0xf6
      003235 F5 81            [12] 9874 	mov	sp,a
      003237 8C 82            [24] 9875 	mov	dpl, r4
      003239 8D 83            [24] 9876 	mov	dph, r5
      00323B 8E F0            [24] 9877 	mov	b, r6
      00323D EF               [12] 9878 	mov	a, r7
                           003181  9879 	C$sugeno_demo.c$111$1_0$155 ==.
                                   9880 ;	../../sugeno_demo.c:111: }
                           003181  9881 	C$sugeno_demo.c$111$1_0$155 ==.
                           003181  9882 	XFsugeno_demo$load_high$0$0 ==.
      00323E 22               [24] 9883 	ret
                                   9884 ;------------------------------------------------------------
                                   9885 ;Allocation info for local variables in function 'vibration_low'
                                   9886 ;------------------------------------------------------------
                                   9887 ;value         Allocated to registers r4 r5 r6 r7 
                                   9888 ;------------------------------------------------------------
                           003182  9889 	Fsugeno_demo$vibration_low$0$0 ==.
                           003182  9890 	C$sugeno_demo.c$118$1_0$157 ==.
                                   9891 ;	../../sugeno_demo.c:118: static float vibration_low(float value)
                                   9892 ;	-----------------------------------------
                                   9893 ;	 function vibration_low
                                   9894 ;	-----------------------------------------
      00323F                       9895 _vibration_low:
      00323F AC 82            [24] 9896 	mov	r4,dpl
      003241 AD 83            [24] 9897 	mov	r5,dph
      003243 AE F0            [24] 9898 	mov	r6,b
      003245 FF               [12] 9899 	mov	r7,a
                           003189  9900 	C$sugeno_demo.c$125$1_0$157 ==.
                                   9901 ;	../../sugeno_demo.c:125: hedges.none
      003246 90 44 6A         [24] 9902 	mov	dptr,#_hedges
      003249 E4               [12] 9903 	clr	a
      00324A 93               [24] 9904 	movc	a,@a+dptr
      00324B FB               [12] 9905 	mov	r3,a
                           00318F  9906 	C$sugeno_demo.c$121$1_0$157 ==.
                                   9907 ;	../../sugeno_demo.c:121: 1.0f,
      00324C C0 03            [24] 9908 	push	ar3
      00324E E4               [12] 9909 	clr	a
      00324F C0 E0            [24] 9910 	push	acc
      003251 C0 04            [24] 9911 	push	ar4
      003253 C0 05            [24] 9912 	push	ar5
      003255 C0 06            [24] 9913 	push	ar6
      003257 C0 07            [24] 9914 	push	ar7
      003259 C0 E0            [24] 9915 	push	acc
      00325B C0 E0            [24] 9916 	push	acc
      00325D 74 80            [12] 9917 	mov	a,#0x80
      00325F C0 E0            [24] 9918 	push	acc
      003261 03               [12] 9919 	rr	a
      003262 C0 E0            [24] 9920 	push	acc
      003264 90 00 00         [24] 9921 	mov	dptr,#0x0000
      003267 75 F0 80         [24] 9922 	mov	b, #0x80
      00326A 14               [12] 9923 	dec	a
      00326B 12 0A F2         [24] 9924 	lcall	_fuzzy_ramp
      00326E AC 82            [24] 9925 	mov	r4, dpl
      003270 AD 83            [24] 9926 	mov	r5, dph
      003272 AE F0            [24] 9927 	mov	r6, b
      003274 FF               [12] 9928 	mov	r7, a
      003275 E5 81            [12] 9929 	mov	a,sp
      003277 24 F6            [12] 9930 	add	a,#0xf6
      003279 F5 81            [12] 9931 	mov	sp,a
      00327B 8C 82            [24] 9932 	mov	dpl, r4
      00327D 8D 83            [24] 9933 	mov	dph, r5
      00327F 8E F0            [24] 9934 	mov	b, r6
      003281 EF               [12] 9935 	mov	a, r7
                           0031C5  9936 	C$sugeno_demo.c$127$1_0$157 ==.
                                   9937 ;	../../sugeno_demo.c:127: }
                           0031C5  9938 	C$sugeno_demo.c$127$1_0$157 ==.
                           0031C5  9939 	XFsugeno_demo$vibration_low$0$0 ==.
      003282 22               [24] 9940 	ret
                                   9941 ;------------------------------------------------------------
                                   9942 ;Allocation info for local variables in function 'vibration_high'
                                   9943 ;------------------------------------------------------------
                                   9944 ;value         Allocated to registers r4 r5 r6 r7 
                                   9945 ;------------------------------------------------------------
                           0031C6  9946 	Fsugeno_demo$vibration_high$0$0 ==.
                           0031C6  9947 	C$sugeno_demo.c$130$1_0$159 ==.
                                   9948 ;	../../sugeno_demo.c:130: static float vibration_high(float value)
                                   9949 ;	-----------------------------------------
                                   9950 ;	 function vibration_high
                                   9951 ;	-----------------------------------------
      003283                       9952 _vibration_high:
      003283 AC 82            [24] 9953 	mov	r4,dpl
      003285 AD 83            [24] 9954 	mov	r5,dph
      003287 AE F0            [24] 9955 	mov	r6,b
      003289 FF               [12] 9956 	mov	r7,a
                           0031CD  9957 	C$sugeno_demo.c$137$1_0$159 ==.
                                   9958 ;	../../sugeno_demo.c:137: hedges.none
      00328A 90 44 6A         [24] 9959 	mov	dptr,#_hedges
      00328D E4               [12] 9960 	clr	a
      00328E 93               [24] 9961 	movc	a,@a+dptr
      00328F FB               [12] 9962 	mov	r3,a
                           0031D3  9963 	C$sugeno_demo.c$133$1_0$159 ==.
                                   9964 ;	../../sugeno_demo.c:133: 3.0f,
      003290 C0 03            [24] 9965 	push	ar3
      003292 74 01            [12] 9966 	mov	a,#0x01
      003294 C0 E0            [24] 9967 	push	acc
      003296 C0 04            [24] 9968 	push	ar4
      003298 C0 05            [24] 9969 	push	ar5
      00329A C0 06            [24] 9970 	push	ar6
      00329C C0 07            [24] 9971 	push	ar7
      00329E E4               [12] 9972 	clr	a
      00329F C0 E0            [24] 9973 	push	acc
      0032A1 C0 E0            [24] 9974 	push	acc
      0032A3 C0 E0            [24] 9975 	push	acc
      0032A5 74 41            [12] 9976 	mov	a,#0x41
      0032A7 C0 E0            [24] 9977 	push	acc
      0032A9 90 00 00         [24] 9978 	mov	dptr,#0x0000
      0032AC 75 F0 40         [24] 9979 	mov	b, #0x40
      0032AF 14               [12] 9980 	dec	a
      0032B0 12 0A F2         [24] 9981 	lcall	_fuzzy_ramp
      0032B3 AC 82            [24] 9982 	mov	r4, dpl
      0032B5 AD 83            [24] 9983 	mov	r5, dph
      0032B7 AE F0            [24] 9984 	mov	r6, b
      0032B9 FF               [12] 9985 	mov	r7, a
      0032BA E5 81            [12] 9986 	mov	a,sp
      0032BC 24 F6            [12] 9987 	add	a,#0xf6
      0032BE F5 81            [12] 9988 	mov	sp,a
      0032C0 8C 82            [24] 9989 	mov	dpl, r4
      0032C2 8D 83            [24] 9990 	mov	dph, r5
      0032C4 8E F0            [24] 9991 	mov	b, r6
      0032C6 EF               [12] 9992 	mov	a, r7
                           00320A  9993 	C$sugeno_demo.c$139$1_0$159 ==.
                                   9994 ;	../../sugeno_demo.c:139: }
                           00320A  9995 	C$sugeno_demo.c$139$1_0$159 ==.
                           00320A  9996 	XFsugeno_demo$vibration_high$0$0 ==.
      0032C7 22               [24] 9997 	ret
                                   9998 ;------------------------------------------------------------
                                   9999 ;Allocation info for local variables in function 'response_idle'
                                  10000 ;------------------------------------------------------------
                                  10001 ;load          Allocated to stack - _bp -6 +4 
                                  10002 ;vibration     Allocated to stack - _bp -10 +4 
                                  10003 ;temperature   Allocated to registers r4 r5 r6 r7 
                                  10004 ;sloc0         Allocated to stack - _bp +1 +4 
                                  10005 ;------------------------------------------------------------
                           00320B 10006 	Fsugeno_demo$response_idle$0$0 ==.
                           00320B 10007 	C$sugeno_demo.c$146$1_0$161 ==.
                                  10008 ;	../../sugeno_demo.c:146: static float response_idle(
                                  10009 ;	-----------------------------------------
                                  10010 ;	 function response_idle
                                  10011 ;	-----------------------------------------
      0032C8                      10012 _response_idle:
      0032C8 C0 08            [24]10013 	push	_bp
      0032CA 85 81 08         [24]10014 	mov	_bp,sp
      0032CD AC 82            [24]10015 	mov	r4,dpl
      0032CF AD 83            [24]10016 	mov	r5,dph
      0032D1 AE F0            [24]10017 	mov	r6,b
      0032D3 FF               [12]10018 	mov	r7,a
      0032D4 E5 81            [12]10019 	mov	a,sp
      0032D6 24 04            [12]10020 	add	a,#0x04
      0032D8 F5 81            [12]10021 	mov	sp,a
                           00321D 10022 	C$sugeno_demo.c$154$1_0$161 ==.
                                  10023 ;	../../sugeno_demo.c:154: 0.20f * temperature +
      0032DA C0 04            [24]10024 	push	ar4
      0032DC C0 05            [24]10025 	push	ar5
      0032DE C0 06            [24]10026 	push	ar6
      0032E0 C0 07            [24]10027 	push	ar7
      0032E2 90 CC CD         [24]10028 	mov	dptr,#0xcccd
      0032E5 75 F0 4C         [24]10029 	mov	b, #0x4c
      0032E8 74 3E            [12]10030 	mov	a, #0x3e
      0032EA 12 40 4C         [24]10031 	lcall	___fsmul
      0032ED AC 82            [24]10032 	mov	r4, dpl
      0032EF AD 83            [24]10033 	mov	r5, dph
      0032F1 AE F0            [24]10034 	mov	r6, b
      0032F3 FF               [12]10035 	mov	r7, a
      0032F4 E5 81            [12]10036 	mov	a,sp
      0032F6 24 FC            [12]10037 	add	a,#0xfc
      0032F8 F5 81            [12]10038 	mov	sp,a
      0032FA E4               [12]10039 	clr	a
      0032FB C0 E0            [24]10040 	push	acc
      0032FD C0 E0            [24]10041 	push	acc
      0032FF C0 E0            [24]10042 	push	acc
      003301 74 41            [12]10043 	mov	a,#0x41
      003303 C0 E0            [24]10044 	push	acc
                           003248 10045 	C$sugeno_demo.c$155$1_0$161 ==.
                                  10046 ;	../../sugeno_demo.c:155: 0.08f * load +
      003305 8C 82            [24]10047 	mov	dpl, r4
      003307 8D 83            [24]10048 	mov	dph, r5
      003309 8E F0            [24]10049 	mov	b, r6
      00330B EF               [12]10050 	mov	a, r7
      00330C 12 41 CE         [24]10051 	lcall	___fsadd
      00330F A8 08            [24]10052 	mov	r0,_bp
      003311 08               [12]10053 	inc	r0
      003312 A6 82            [24]10054 	mov	@r0, dpl
      003314 08               [12]10055 	inc	r0
      003315 A6 83            [24]10056 	mov	@r0, dph
      003317 08               [12]10057 	inc	r0
      003318 A6 F0            [24]10058 	mov	@r0, b
      00331A 08               [12]10059 	inc	r0
      00331B F6               [12]10060 	mov	@r0,a
      00331C E5 81            [12]10061 	mov	a,sp
      00331E 24 FC            [12]10062 	add	a,#0xfc
      003320 F5 81            [12]10063 	mov	sp,a
      003322 E5 08            [12]10064 	mov	a,_bp
      003324 24 FA            [12]10065 	add	a,#0xfa
      003326 F8               [12]10066 	mov	r0,a
      003327 E6               [12]10067 	mov	a,@r0
      003328 C0 E0            [24]10068 	push	acc
      00332A 08               [12]10069 	inc	r0
      00332B E6               [12]10070 	mov	a,@r0
      00332C C0 E0            [24]10071 	push	acc
      00332E 08               [12]10072 	inc	r0
      00332F E6               [12]10073 	mov	a,@r0
      003330 C0 E0            [24]10074 	push	acc
      003332 08               [12]10075 	inc	r0
      003333 E6               [12]10076 	mov	a,@r0
      003334 C0 E0            [24]10077 	push	acc
      003336 90 D7 0A         [24]10078 	mov	dptr,#0xd70a
      003339 75 F0 A3         [24]10079 	mov	b, #0xa3
      00333C 74 3D            [12]10080 	mov	a, #0x3d
      00333E 12 40 4C         [24]10081 	lcall	___fsmul
      003341 AA 82            [24]10082 	mov	r2, dpl
      003343 AB 83            [24]10083 	mov	r3, dph
      003345 AE F0            [24]10084 	mov	r6, b
      003347 FF               [12]10085 	mov	r7, a
      003348 E5 81            [12]10086 	mov	a,sp
      00334A 24 FC            [12]10087 	add	a,#0xfc
      00334C F5 81            [12]10088 	mov	sp,a
      00334E C0 02            [24]10089 	push	ar2
      003350 C0 03            [24]10090 	push	ar3
      003352 C0 06            [24]10091 	push	ar6
      003354 C0 07            [24]10092 	push	ar7
                           003299 10093 	C$sugeno_demo.c$156$1_0$161 ==.
                                  10094 ;	../../sugeno_demo.c:156: 0.50f * vibration;
      003356 A8 08            [24]10095 	mov	r0,_bp
      003358 08               [12]10096 	inc	r0
      003359 86 82            [24]10097 	mov	dpl, @r0
      00335B 08               [12]10098 	inc	r0
      00335C 86 83            [24]10099 	mov	dph, @r0
      00335E 08               [12]10100 	inc	r0
      00335F 86 F0            [24]10101 	mov	b, @r0
      003361 08               [12]10102 	inc	r0
      003362 E6               [12]10103 	mov	a, @r0
      003363 12 41 CE         [24]10104 	lcall	___fsadd
      003366 A8 08            [24]10105 	mov	r0,_bp
      003368 08               [12]10106 	inc	r0
      003369 A6 82            [24]10107 	mov	@r0, dpl
      00336B 08               [12]10108 	inc	r0
      00336C A6 83            [24]10109 	mov	@r0, dph
      00336E 08               [12]10110 	inc	r0
      00336F A6 F0            [24]10111 	mov	@r0, b
      003371 08               [12]10112 	inc	r0
      003372 F6               [12]10113 	mov	@r0,a
      003373 E5 81            [12]10114 	mov	a,sp
      003375 24 FC            [12]10115 	add	a,#0xfc
      003377 F5 81            [12]10116 	mov	sp,a
      003379 E5 08            [12]10117 	mov	a,_bp
      00337B 24 F6            [12]10118 	add	a,#0xf6
      00337D F8               [12]10119 	mov	r0,a
      00337E E6               [12]10120 	mov	a,@r0
      00337F C0 E0            [24]10121 	push	acc
      003381 08               [12]10122 	inc	r0
      003382 E6               [12]10123 	mov	a,@r0
      003383 C0 E0            [24]10124 	push	acc
      003385 08               [12]10125 	inc	r0
      003386 E6               [12]10126 	mov	a,@r0
      003387 C0 E0            [24]10127 	push	acc
      003389 08               [12]10128 	inc	r0
      00338A E6               [12]10129 	mov	a,@r0
      00338B C0 E0            [24]10130 	push	acc
      00338D 90 00 00         [24]10131 	mov	dptr,#(0x00&0x00ff)
      003390 E4               [12]10132 	clr	a
      003391 F5 F0            [12]10133 	mov	b,a
      003393 74 3F            [12]10134 	mov	a,#0x3f
      003395 12 40 4C         [24]10135 	lcall	___fsmul
      003398 AA 82            [24]10136 	mov	r2, dpl
      00339A AB 83            [24]10137 	mov	r3, dph
      00339C AE F0            [24]10138 	mov	r6, b
      00339E FF               [12]10139 	mov	r7, a
      00339F E5 81            [12]10140 	mov	a,sp
      0033A1 24 FC            [12]10141 	add	a,#0xfc
      0033A3 F5 81            [12]10142 	mov	sp,a
      0033A5 C0 02            [24]10143 	push	ar2
      0033A7 C0 03            [24]10144 	push	ar3
      0033A9 C0 06            [24]10145 	push	ar6
      0033AB C0 07            [24]10146 	push	ar7
      0033AD A8 08            [24]10147 	mov	r0,_bp
      0033AF 08               [12]10148 	inc	r0
      0033B0 86 82            [24]10149 	mov	dpl, @r0
      0033B2 08               [12]10150 	inc	r0
      0033B3 86 83            [24]10151 	mov	dph, @r0
      0033B5 08               [12]10152 	inc	r0
      0033B6 86 F0            [24]10153 	mov	b, @r0
      0033B8 08               [12]10154 	inc	r0
      0033B9 E6               [12]10155 	mov	a, @r0
      0033BA 12 41 CE         [24]10156 	lcall	___fsadd
      0033BD AC 82            [24]10157 	mov	r4, dpl
      0033BF AD 83            [24]10158 	mov	r5, dph
      0033C1 AE F0            [24]10159 	mov	r6, b
      0033C3 FF               [12]10160 	mov	r7, a
      0033C4 E5 81            [12]10161 	mov	a,sp
      0033C6 24 FC            [12]10162 	add	a,#0xfc
      0033C8 F5 81            [12]10163 	mov	sp,a
      0033CA 8C 82            [24]10164 	mov	dpl, r4
      0033CC 8D 83            [24]10165 	mov	dph, r5
      0033CE 8E F0            [24]10166 	mov	b, r6
      0033D0 EF               [12]10167 	mov	a, r7
                           003314 10168 	C$sugeno_demo.c$157$1_0$161 ==.
                                  10169 ;	../../sugeno_demo.c:157: }
      0033D1 85 08 81         [24]10170 	mov	sp,_bp
      0033D4 D0 08            [24]10171 	pop	_bp
                           003319 10172 	C$sugeno_demo.c$157$1_0$161 ==.
                           003319 10173 	XFsugeno_demo$response_idle$0$0 ==.
      0033D6 22               [24]10174 	ret
                                  10175 ;------------------------------------------------------------
                                  10176 ;Allocation info for local variables in function 'response_economy'
                                  10177 ;------------------------------------------------------------
                                  10178 ;load          Allocated to stack - _bp -6 +4 
                                  10179 ;vibration     Allocated to stack - _bp -10 +4 
                                  10180 ;temperature   Allocated to registers r4 r5 r6 r7 
                                  10181 ;sloc0         Allocated to stack - _bp +1 +4 
                                  10182 ;------------------------------------------------------------
                           00331A 10183 	Fsugeno_demo$response_economy$0$0 ==.
                           00331A 10184 	C$sugeno_demo.c$160$1_0$163 ==.
                                  10185 ;	../../sugeno_demo.c:160: static float response_economy(
                                  10186 ;	-----------------------------------------
                                  10187 ;	 function response_economy
                                  10188 ;	-----------------------------------------
      0033D7                      10189 _response_economy:
      0033D7 C0 08            [24]10190 	push	_bp
      0033D9 85 81 08         [24]10191 	mov	_bp,sp
      0033DC AC 82            [24]10192 	mov	r4,dpl
      0033DE AD 83            [24]10193 	mov	r5,dph
      0033E0 AE F0            [24]10194 	mov	r6,b
      0033E2 FF               [12]10195 	mov	r7,a
      0033E3 E5 81            [12]10196 	mov	a,sp
      0033E5 24 04            [12]10197 	add	a,#0x04
      0033E7 F5 81            [12]10198 	mov	sp,a
                           00332C 10199 	C$sugeno_demo.c$168$1_0$163 ==.
                                  10200 ;	../../sugeno_demo.c:168: 0.30f * temperature +
      0033E9 C0 04            [24]10201 	push	ar4
      0033EB C0 05            [24]10202 	push	ar5
      0033ED C0 06            [24]10203 	push	ar6
      0033EF C0 07            [24]10204 	push	ar7
      0033F1 90 99 9A         [24]10205 	mov	dptr,#0x999a
      0033F4 75 F0 99         [24]10206 	mov	b, #0x99
      0033F7 74 3E            [12]10207 	mov	a, #0x3e
      0033F9 12 40 4C         [24]10208 	lcall	___fsmul
      0033FC AC 82            [24]10209 	mov	r4, dpl
      0033FE AD 83            [24]10210 	mov	r5, dph
      003400 AE F0            [24]10211 	mov	r6, b
      003402 FF               [12]10212 	mov	r7, a
      003403 E5 81            [12]10213 	mov	a,sp
      003405 24 FC            [12]10214 	add	a,#0xfc
      003407 F5 81            [12]10215 	mov	sp,a
      003409 E4               [12]10216 	clr	a
      00340A C0 E0            [24]10217 	push	acc
      00340C C0 E0            [24]10218 	push	acc
      00340E 74 40            [12]10219 	mov	a,#0x40
      003410 C0 E0            [24]10220 	push	acc
      003412 04               [12]10221 	inc	a
      003413 C0 E0            [24]10222 	push	acc
                           003358 10223 	C$sugeno_demo.c$169$1_0$163 ==.
                                  10224 ;	../../sugeno_demo.c:169: 0.18f * load +
      003415 8C 82            [24]10225 	mov	dpl, r4
      003417 8D 83            [24]10226 	mov	dph, r5
      003419 8E F0            [24]10227 	mov	b, r6
      00341B EF               [12]10228 	mov	a, r7
      00341C 12 41 CE         [24]10229 	lcall	___fsadd
      00341F A8 08            [24]10230 	mov	r0,_bp
      003421 08               [12]10231 	inc	r0
      003422 A6 82            [24]10232 	mov	@r0, dpl
      003424 08               [12]10233 	inc	r0
      003425 A6 83            [24]10234 	mov	@r0, dph
      003427 08               [12]10235 	inc	r0
      003428 A6 F0            [24]10236 	mov	@r0, b
      00342A 08               [12]10237 	inc	r0
      00342B F6               [12]10238 	mov	@r0,a
      00342C E5 81            [12]10239 	mov	a,sp
      00342E 24 FC            [12]10240 	add	a,#0xfc
      003430 F5 81            [12]10241 	mov	sp,a
      003432 E5 08            [12]10242 	mov	a,_bp
      003434 24 FA            [12]10243 	add	a,#0xfa
      003436 F8               [12]10244 	mov	r0,a
      003437 E6               [12]10245 	mov	a,@r0
      003438 C0 E0            [24]10246 	push	acc
      00343A 08               [12]10247 	inc	r0
      00343B E6               [12]10248 	mov	a,@r0
      00343C C0 E0            [24]10249 	push	acc
      00343E 08               [12]10250 	inc	r0
      00343F E6               [12]10251 	mov	a,@r0
      003440 C0 E0            [24]10252 	push	acc
      003442 08               [12]10253 	inc	r0
      003443 E6               [12]10254 	mov	a,@r0
      003444 C0 E0            [24]10255 	push	acc
      003446 90 51 EC         [24]10256 	mov	dptr,#0x51ec
      003449 75 F0 38         [24]10257 	mov	b, #0x38
      00344C 74 3E            [12]10258 	mov	a, #0x3e
      00344E 12 40 4C         [24]10259 	lcall	___fsmul
      003451 AA 82            [24]10260 	mov	r2, dpl
      003453 AB 83            [24]10261 	mov	r3, dph
      003455 AE F0            [24]10262 	mov	r6, b
      003457 FF               [12]10263 	mov	r7, a
      003458 E5 81            [12]10264 	mov	a,sp
      00345A 24 FC            [12]10265 	add	a,#0xfc
      00345C F5 81            [12]10266 	mov	sp,a
      00345E C0 02            [24]10267 	push	ar2
      003460 C0 03            [24]10268 	push	ar3
      003462 C0 06            [24]10269 	push	ar6
      003464 C0 07            [24]10270 	push	ar7
                           0033A9 10271 	C$sugeno_demo.c$170$1_0$163 ==.
                                  10272 ;	../../sugeno_demo.c:170: 0.80f * vibration;
      003466 A8 08            [24]10273 	mov	r0,_bp
      003468 08               [12]10274 	inc	r0
      003469 86 82            [24]10275 	mov	dpl, @r0
      00346B 08               [12]10276 	inc	r0
      00346C 86 83            [24]10277 	mov	dph, @r0
      00346E 08               [12]10278 	inc	r0
      00346F 86 F0            [24]10279 	mov	b, @r0
      003471 08               [12]10280 	inc	r0
      003472 E6               [12]10281 	mov	a, @r0
      003473 12 41 CE         [24]10282 	lcall	___fsadd
      003476 A8 08            [24]10283 	mov	r0,_bp
      003478 08               [12]10284 	inc	r0
      003479 A6 82            [24]10285 	mov	@r0, dpl
      00347B 08               [12]10286 	inc	r0
      00347C A6 83            [24]10287 	mov	@r0, dph
      00347E 08               [12]10288 	inc	r0
      00347F A6 F0            [24]10289 	mov	@r0, b
      003481 08               [12]10290 	inc	r0
      003482 F6               [12]10291 	mov	@r0,a
      003483 E5 81            [12]10292 	mov	a,sp
      003485 24 FC            [12]10293 	add	a,#0xfc
      003487 F5 81            [12]10294 	mov	sp,a
      003489 E5 08            [12]10295 	mov	a,_bp
      00348B 24 F6            [12]10296 	add	a,#0xf6
      00348D F8               [12]10297 	mov	r0,a
      00348E E6               [12]10298 	mov	a,@r0
      00348F C0 E0            [24]10299 	push	acc
      003491 08               [12]10300 	inc	r0
      003492 E6               [12]10301 	mov	a,@r0
      003493 C0 E0            [24]10302 	push	acc
      003495 08               [12]10303 	inc	r0
      003496 E6               [12]10304 	mov	a,@r0
      003497 C0 E0            [24]10305 	push	acc
      003499 08               [12]10306 	inc	r0
      00349A E6               [12]10307 	mov	a,@r0
      00349B C0 E0            [24]10308 	push	acc
      00349D 90 CC CD         [24]10309 	mov	dptr,#0xcccd
      0034A0 75 F0 4C         [24]10310 	mov	b, #0x4c
      0034A3 74 3F            [12]10311 	mov	a, #0x3f
      0034A5 12 40 4C         [24]10312 	lcall	___fsmul
      0034A8 AA 82            [24]10313 	mov	r2, dpl
      0034AA AB 83            [24]10314 	mov	r3, dph
      0034AC AE F0            [24]10315 	mov	r6, b
      0034AE FF               [12]10316 	mov	r7, a
      0034AF E5 81            [12]10317 	mov	a,sp
      0034B1 24 FC            [12]10318 	add	a,#0xfc
      0034B3 F5 81            [12]10319 	mov	sp,a
      0034B5 C0 02            [24]10320 	push	ar2
      0034B7 C0 03            [24]10321 	push	ar3
      0034B9 C0 06            [24]10322 	push	ar6
      0034BB C0 07            [24]10323 	push	ar7
      0034BD A8 08            [24]10324 	mov	r0,_bp
      0034BF 08               [12]10325 	inc	r0
      0034C0 86 82            [24]10326 	mov	dpl, @r0
      0034C2 08               [12]10327 	inc	r0
      0034C3 86 83            [24]10328 	mov	dph, @r0
      0034C5 08               [12]10329 	inc	r0
      0034C6 86 F0            [24]10330 	mov	b, @r0
      0034C8 08               [12]10331 	inc	r0
      0034C9 E6               [12]10332 	mov	a, @r0
      0034CA 12 41 CE         [24]10333 	lcall	___fsadd
      0034CD AC 82            [24]10334 	mov	r4, dpl
      0034CF AD 83            [24]10335 	mov	r5, dph
      0034D1 AE F0            [24]10336 	mov	r6, b
      0034D3 FF               [12]10337 	mov	r7, a
      0034D4 E5 81            [12]10338 	mov	a,sp
      0034D6 24 FC            [12]10339 	add	a,#0xfc
      0034D8 F5 81            [12]10340 	mov	sp,a
      0034DA 8C 82            [24]10341 	mov	dpl, r4
      0034DC 8D 83            [24]10342 	mov	dph, r5
      0034DE 8E F0            [24]10343 	mov	b, r6
      0034E0 EF               [12]10344 	mov	a, r7
                           003424 10345 	C$sugeno_demo.c$171$1_0$163 ==.
                                  10346 ;	../../sugeno_demo.c:171: }
      0034E1 85 08 81         [24]10347 	mov	sp,_bp
      0034E4 D0 08            [24]10348 	pop	_bp
                           003429 10349 	C$sugeno_demo.c$171$1_0$163 ==.
                           003429 10350 	XFsugeno_demo$response_economy$0$0 ==.
      0034E6 22               [24]10351 	ret
                                  10352 ;------------------------------------------------------------
                                  10353 ;Allocation info for local variables in function 'response_balanced'
                                  10354 ;------------------------------------------------------------
                                  10355 ;load          Allocated to stack - _bp -6 +4 
                                  10356 ;vibration     Allocated to stack - _bp -10 +4 
                                  10357 ;temperature   Allocated to registers r4 r5 r6 r7 
                                  10358 ;sloc0         Allocated to stack - _bp +1 +4 
                                  10359 ;------------------------------------------------------------
                           00342A 10360 	Fsugeno_demo$response_balanced$0$0 ==.
                           00342A 10361 	C$sugeno_demo.c$174$1_0$165 ==.
                                  10362 ;	../../sugeno_demo.c:174: static float response_balanced(
                                  10363 ;	-----------------------------------------
                                  10364 ;	 function response_balanced
                                  10365 ;	-----------------------------------------
      0034E7                      10366 _response_balanced:
      0034E7 C0 08            [24]10367 	push	_bp
      0034E9 85 81 08         [24]10368 	mov	_bp,sp
      0034EC AC 82            [24]10369 	mov	r4,dpl
      0034EE AD 83            [24]10370 	mov	r5,dph
      0034F0 AE F0            [24]10371 	mov	r6,b
      0034F2 FF               [12]10372 	mov	r7,a
      0034F3 E5 81            [12]10373 	mov	a,sp
      0034F5 24 04            [12]10374 	add	a,#0x04
      0034F7 F5 81            [12]10375 	mov	sp,a
                           00343C 10376 	C$sugeno_demo.c$182$1_0$165 ==.
                                  10377 ;	../../sugeno_demo.c:182: 0.42f * temperature +
      0034F9 C0 04            [24]10378 	push	ar4
      0034FB C0 05            [24]10379 	push	ar5
      0034FD C0 06            [24]10380 	push	ar6
      0034FF C0 07            [24]10381 	push	ar7
      003501 90 0A 3D         [24]10382 	mov	dptr,#0x0a3d
      003504 75 F0 D7         [24]10383 	mov	b, #0xd7
      003507 74 3E            [12]10384 	mov	a, #0x3e
      003509 12 40 4C         [24]10385 	lcall	___fsmul
      00350C AC 82            [24]10386 	mov	r4, dpl
      00350E AD 83            [24]10387 	mov	r5, dph
      003510 AE F0            [24]10388 	mov	r6, b
      003512 FF               [12]10389 	mov	r7, a
      003513 E5 81            [12]10390 	mov	a,sp
      003515 24 FC            [12]10391 	add	a,#0xfc
      003517 F5 81            [12]10392 	mov	sp,a
      003519 E4               [12]10393 	clr	a
      00351A C0 E0            [24]10394 	push	acc
      00351C C0 E0            [24]10395 	push	acc
      00351E 74 70            [12]10396 	mov	a,#0x70
      003520 C0 E0            [24]10397 	push	acc
      003522 74 41            [12]10398 	mov	a,#0x41
      003524 C0 E0            [24]10399 	push	acc
                           003469 10400 	C$sugeno_demo.c$183$1_0$165 ==.
                                  10401 ;	../../sugeno_demo.c:183: 0.25f * load +
      003526 8C 82            [24]10402 	mov	dpl, r4
      003528 8D 83            [24]10403 	mov	dph, r5
      00352A 8E F0            [24]10404 	mov	b, r6
      00352C EF               [12]10405 	mov	a, r7
      00352D 12 41 CE         [24]10406 	lcall	___fsadd
      003530 A8 08            [24]10407 	mov	r0,_bp
      003532 08               [12]10408 	inc	r0
      003533 A6 82            [24]10409 	mov	@r0, dpl
      003535 08               [12]10410 	inc	r0
      003536 A6 83            [24]10411 	mov	@r0, dph
      003538 08               [12]10412 	inc	r0
      003539 A6 F0            [24]10413 	mov	@r0, b
      00353B 08               [12]10414 	inc	r0
      00353C F6               [12]10415 	mov	@r0,a
      00353D E5 81            [12]10416 	mov	a,sp
      00353F 24 FC            [12]10417 	add	a,#0xfc
      003541 F5 81            [12]10418 	mov	sp,a
      003543 E5 08            [12]10419 	mov	a,_bp
      003545 24 FA            [12]10420 	add	a,#0xfa
      003547 F8               [12]10421 	mov	r0,a
      003548 E6               [12]10422 	mov	a,@r0
      003549 C0 E0            [24]10423 	push	acc
      00354B 08               [12]10424 	inc	r0
      00354C E6               [12]10425 	mov	a,@r0
      00354D C0 E0            [24]10426 	push	acc
      00354F 08               [12]10427 	inc	r0
      003550 E6               [12]10428 	mov	a,@r0
      003551 C0 E0            [24]10429 	push	acc
      003553 08               [12]10430 	inc	r0
      003554 E6               [12]10431 	mov	a,@r0
      003555 C0 E0            [24]10432 	push	acc
      003557 90 00 00         [24]10433 	mov	dptr,#0x0000
      00355A 75 F0 80         [24]10434 	mov	b, #0x80
      00355D 74 3E            [12]10435 	mov	a, #0x3e
      00355F 12 40 4C         [24]10436 	lcall	___fsmul
      003562 AA 82            [24]10437 	mov	r2, dpl
      003564 AB 83            [24]10438 	mov	r3, dph
      003566 AE F0            [24]10439 	mov	r6, b
      003568 FF               [12]10440 	mov	r7, a
      003569 E5 81            [12]10441 	mov	a,sp
      00356B 24 FC            [12]10442 	add	a,#0xfc
      00356D F5 81            [12]10443 	mov	sp,a
      00356F C0 02            [24]10444 	push	ar2
      003571 C0 03            [24]10445 	push	ar3
      003573 C0 06            [24]10446 	push	ar6
      003575 C0 07            [24]10447 	push	ar7
                           0034BA 10448 	C$sugeno_demo.c$184$1_0$165 ==.
                                  10449 ;	../../sugeno_demo.c:184: 1.20f * vibration;
      003577 A8 08            [24]10450 	mov	r0,_bp
      003579 08               [12]10451 	inc	r0
      00357A 86 82            [24]10452 	mov	dpl, @r0
      00357C 08               [12]10453 	inc	r0
      00357D 86 83            [24]10454 	mov	dph, @r0
      00357F 08               [12]10455 	inc	r0
      003580 86 F0            [24]10456 	mov	b, @r0
      003582 08               [12]10457 	inc	r0
      003583 E6               [12]10458 	mov	a, @r0
      003584 12 41 CE         [24]10459 	lcall	___fsadd
      003587 A8 08            [24]10460 	mov	r0,_bp
      003589 08               [12]10461 	inc	r0
      00358A A6 82            [24]10462 	mov	@r0, dpl
      00358C 08               [12]10463 	inc	r0
      00358D A6 83            [24]10464 	mov	@r0, dph
      00358F 08               [12]10465 	inc	r0
      003590 A6 F0            [24]10466 	mov	@r0, b
      003592 08               [12]10467 	inc	r0
      003593 F6               [12]10468 	mov	@r0,a
      003594 E5 81            [12]10469 	mov	a,sp
      003596 24 FC            [12]10470 	add	a,#0xfc
      003598 F5 81            [12]10471 	mov	sp,a
      00359A E5 08            [12]10472 	mov	a,_bp
      00359C 24 F6            [12]10473 	add	a,#0xf6
      00359E F8               [12]10474 	mov	r0,a
      00359F E6               [12]10475 	mov	a,@r0
      0035A0 C0 E0            [24]10476 	push	acc
      0035A2 08               [12]10477 	inc	r0
      0035A3 E6               [12]10478 	mov	a,@r0
      0035A4 C0 E0            [24]10479 	push	acc
      0035A6 08               [12]10480 	inc	r0
      0035A7 E6               [12]10481 	mov	a,@r0
      0035A8 C0 E0            [24]10482 	push	acc
      0035AA 08               [12]10483 	inc	r0
      0035AB E6               [12]10484 	mov	a,@r0
      0035AC C0 E0            [24]10485 	push	acc
      0035AE 90 99 9A         [24]10486 	mov	dptr,#0x999a
      0035B1 75 F0 99         [24]10487 	mov	b, #0x99
      0035B4 74 3F            [12]10488 	mov	a, #0x3f
      0035B6 12 40 4C         [24]10489 	lcall	___fsmul
      0035B9 AA 82            [24]10490 	mov	r2, dpl
      0035BB AB 83            [24]10491 	mov	r3, dph
      0035BD AE F0            [24]10492 	mov	r6, b
      0035BF FF               [12]10493 	mov	r7, a
      0035C0 E5 81            [12]10494 	mov	a,sp
      0035C2 24 FC            [12]10495 	add	a,#0xfc
      0035C4 F5 81            [12]10496 	mov	sp,a
      0035C6 C0 02            [24]10497 	push	ar2
      0035C8 C0 03            [24]10498 	push	ar3
      0035CA C0 06            [24]10499 	push	ar6
      0035CC C0 07            [24]10500 	push	ar7
      0035CE A8 08            [24]10501 	mov	r0,_bp
      0035D0 08               [12]10502 	inc	r0
      0035D1 86 82            [24]10503 	mov	dpl, @r0
      0035D3 08               [12]10504 	inc	r0
      0035D4 86 83            [24]10505 	mov	dph, @r0
      0035D6 08               [12]10506 	inc	r0
      0035D7 86 F0            [24]10507 	mov	b, @r0
      0035D9 08               [12]10508 	inc	r0
      0035DA E6               [12]10509 	mov	a, @r0
      0035DB 12 41 CE         [24]10510 	lcall	___fsadd
      0035DE AC 82            [24]10511 	mov	r4, dpl
      0035E0 AD 83            [24]10512 	mov	r5, dph
      0035E2 AE F0            [24]10513 	mov	r6, b
      0035E4 FF               [12]10514 	mov	r7, a
      0035E5 E5 81            [12]10515 	mov	a,sp
      0035E7 24 FC            [12]10516 	add	a,#0xfc
      0035E9 F5 81            [12]10517 	mov	sp,a
      0035EB 8C 82            [24]10518 	mov	dpl, r4
      0035ED 8D 83            [24]10519 	mov	dph, r5
      0035EF 8E F0            [24]10520 	mov	b, r6
      0035F1 EF               [12]10521 	mov	a, r7
                           003535 10522 	C$sugeno_demo.c$185$1_0$165 ==.
                                  10523 ;	../../sugeno_demo.c:185: }
      0035F2 85 08 81         [24]10524 	mov	sp,_bp
      0035F5 D0 08            [24]10525 	pop	_bp
                           00353A 10526 	C$sugeno_demo.c$185$1_0$165 ==.
                           00353A 10527 	XFsugeno_demo$response_balanced$0$0 ==.
      0035F7 22               [24]10528 	ret
                                  10529 ;------------------------------------------------------------
                                  10530 ;Allocation info for local variables in function 'response_cooling'
                                  10531 ;------------------------------------------------------------
                                  10532 ;load          Allocated to stack - _bp -6 +4 
                                  10533 ;vibration     Allocated to stack - _bp -10 +4 
                                  10534 ;temperature   Allocated to registers r4 r5 r6 r7 
                                  10535 ;sloc0         Allocated to stack - _bp +1 +4 
                                  10536 ;------------------------------------------------------------
                           00353B 10537 	Fsugeno_demo$response_cooling$0$0 ==.
                           00353B 10538 	C$sugeno_demo.c$188$1_0$167 ==.
                                  10539 ;	../../sugeno_demo.c:188: static float response_cooling(
                                  10540 ;	-----------------------------------------
                                  10541 ;	 function response_cooling
                                  10542 ;	-----------------------------------------
      0035F8                      10543 _response_cooling:
      0035F8 C0 08            [24]10544 	push	_bp
      0035FA 85 81 08         [24]10545 	mov	_bp,sp
      0035FD AC 82            [24]10546 	mov	r4,dpl
      0035FF AD 83            [24]10547 	mov	r5,dph
      003601 AE F0            [24]10548 	mov	r6,b
      003603 FF               [12]10549 	mov	r7,a
      003604 E5 81            [12]10550 	mov	a,sp
      003606 24 04            [12]10551 	add	a,#0x04
      003608 F5 81            [12]10552 	mov	sp,a
                           00354D 10553 	C$sugeno_demo.c$196$1_0$167 ==.
                                  10554 ;	../../sugeno_demo.c:196: 0.65f * temperature +
      00360A C0 04            [24]10555 	push	ar4
      00360C C0 05            [24]10556 	push	ar5
      00360E C0 06            [24]10557 	push	ar6
      003610 C0 07            [24]10558 	push	ar7
      003612 90 66 66         [24]10559 	mov	dptr,#0x6666
      003615 75 F0 26         [24]10560 	mov	b, #0x26
      003618 74 3F            [12]10561 	mov	a, #0x3f
      00361A 12 40 4C         [24]10562 	lcall	___fsmul
      00361D AC 82            [24]10563 	mov	r4, dpl
      00361F AD 83            [24]10564 	mov	r5, dph
      003621 AE F0            [24]10565 	mov	r6, b
      003623 FF               [12]10566 	mov	r7, a
      003624 E5 81            [12]10567 	mov	a,sp
      003626 24 FC            [12]10568 	add	a,#0xfc
      003628 F5 81            [12]10569 	mov	sp,a
      00362A E4               [12]10570 	clr	a
      00362B C0 E0            [24]10571 	push	acc
      00362D C0 E0            [24]10572 	push	acc
      00362F 74 A0            [12]10573 	mov	a,#0xa0
      003631 C0 E0            [24]10574 	push	acc
      003633 23               [12]10575 	rl	a
      003634 C0 E0            [24]10576 	push	acc
                           003579 10577 	C$sugeno_demo.c$197$1_0$167 ==.
                                  10578 ;	../../sugeno_demo.c:197: 0.12f * load +
      003636 8C 82            [24]10579 	mov	dpl, r4
      003638 8D 83            [24]10580 	mov	dph, r5
      00363A 8E F0            [24]10581 	mov	b, r6
      00363C EF               [12]10582 	mov	a, r7
      00363D 12 41 CE         [24]10583 	lcall	___fsadd
      003640 A8 08            [24]10584 	mov	r0,_bp
      003642 08               [12]10585 	inc	r0
      003643 A6 82            [24]10586 	mov	@r0, dpl
      003645 08               [12]10587 	inc	r0
      003646 A6 83            [24]10588 	mov	@r0, dph
      003648 08               [12]10589 	inc	r0
      003649 A6 F0            [24]10590 	mov	@r0, b
      00364B 08               [12]10591 	inc	r0
      00364C F6               [12]10592 	mov	@r0,a
      00364D E5 81            [12]10593 	mov	a,sp
      00364F 24 FC            [12]10594 	add	a,#0xfc
      003651 F5 81            [12]10595 	mov	sp,a
      003653 E5 08            [12]10596 	mov	a,_bp
      003655 24 FA            [12]10597 	add	a,#0xfa
      003657 F8               [12]10598 	mov	r0,a
      003658 E6               [12]10599 	mov	a,@r0
      003659 C0 E0            [24]10600 	push	acc
      00365B 08               [12]10601 	inc	r0
      00365C E6               [12]10602 	mov	a,@r0
      00365D C0 E0            [24]10603 	push	acc
      00365F 08               [12]10604 	inc	r0
      003660 E6               [12]10605 	mov	a,@r0
      003661 C0 E0            [24]10606 	push	acc
      003663 08               [12]10607 	inc	r0
      003664 E6               [12]10608 	mov	a,@r0
      003665 C0 E0            [24]10609 	push	acc
      003667 90 C2 8F         [24]10610 	mov	dptr,#0xc28f
      00366A 75 F0 F5         [24]10611 	mov	b, #0xf5
      00366D 74 3D            [12]10612 	mov	a, #0x3d
      00366F 12 40 4C         [24]10613 	lcall	___fsmul
      003672 AA 82            [24]10614 	mov	r2, dpl
      003674 AB 83            [24]10615 	mov	r3, dph
      003676 AE F0            [24]10616 	mov	r6, b
      003678 FF               [12]10617 	mov	r7, a
      003679 E5 81            [12]10618 	mov	a,sp
      00367B 24 FC            [12]10619 	add	a,#0xfc
      00367D F5 81            [12]10620 	mov	sp,a
      00367F C0 02            [24]10621 	push	ar2
      003681 C0 03            [24]10622 	push	ar3
      003683 C0 06            [24]10623 	push	ar6
      003685 C0 07            [24]10624 	push	ar7
                           0035CA 10625 	C$sugeno_demo.c$198$1_0$167 ==.
                                  10626 ;	../../sugeno_demo.c:198: 1.50f * vibration;
      003687 A8 08            [24]10627 	mov	r0,_bp
      003689 08               [12]10628 	inc	r0
      00368A 86 82            [24]10629 	mov	dpl, @r0
      00368C 08               [12]10630 	inc	r0
      00368D 86 83            [24]10631 	mov	dph, @r0
      00368F 08               [12]10632 	inc	r0
      003690 86 F0            [24]10633 	mov	b, @r0
      003692 08               [12]10634 	inc	r0
      003693 E6               [12]10635 	mov	a, @r0
      003694 12 41 CE         [24]10636 	lcall	___fsadd
      003697 A8 08            [24]10637 	mov	r0,_bp
      003699 08               [12]10638 	inc	r0
      00369A A6 82            [24]10639 	mov	@r0, dpl
      00369C 08               [12]10640 	inc	r0
      00369D A6 83            [24]10641 	mov	@r0, dph
      00369F 08               [12]10642 	inc	r0
      0036A0 A6 F0            [24]10643 	mov	@r0, b
      0036A2 08               [12]10644 	inc	r0
      0036A3 F6               [12]10645 	mov	@r0,a
      0036A4 E5 81            [12]10646 	mov	a,sp
      0036A6 24 FC            [12]10647 	add	a,#0xfc
      0036A8 F5 81            [12]10648 	mov	sp,a
      0036AA E5 08            [12]10649 	mov	a,_bp
      0036AC 24 F6            [12]10650 	add	a,#0xf6
      0036AE F8               [12]10651 	mov	r0,a
      0036AF E6               [12]10652 	mov	a,@r0
      0036B0 C0 E0            [24]10653 	push	acc
      0036B2 08               [12]10654 	inc	r0
      0036B3 E6               [12]10655 	mov	a,@r0
      0036B4 C0 E0            [24]10656 	push	acc
      0036B6 08               [12]10657 	inc	r0
      0036B7 E6               [12]10658 	mov	a,@r0
      0036B8 C0 E0            [24]10659 	push	acc
      0036BA 08               [12]10660 	inc	r0
      0036BB E6               [12]10661 	mov	a,@r0
      0036BC C0 E0            [24]10662 	push	acc
      0036BE 90 00 00         [24]10663 	mov	dptr,#0x0000
      0036C1 75 F0 C0         [24]10664 	mov	b, #0xc0
      0036C4 74 3F            [12]10665 	mov	a, #0x3f
      0036C6 12 40 4C         [24]10666 	lcall	___fsmul
      0036C9 AA 82            [24]10667 	mov	r2, dpl
      0036CB AB 83            [24]10668 	mov	r3, dph
      0036CD AE F0            [24]10669 	mov	r6, b
      0036CF FF               [12]10670 	mov	r7, a
      0036D0 E5 81            [12]10671 	mov	a,sp
      0036D2 24 FC            [12]10672 	add	a,#0xfc
      0036D4 F5 81            [12]10673 	mov	sp,a
      0036D6 C0 02            [24]10674 	push	ar2
      0036D8 C0 03            [24]10675 	push	ar3
      0036DA C0 06            [24]10676 	push	ar6
      0036DC C0 07            [24]10677 	push	ar7
      0036DE A8 08            [24]10678 	mov	r0,_bp
      0036E0 08               [12]10679 	inc	r0
      0036E1 86 82            [24]10680 	mov	dpl, @r0
      0036E3 08               [12]10681 	inc	r0
      0036E4 86 83            [24]10682 	mov	dph, @r0
      0036E6 08               [12]10683 	inc	r0
      0036E7 86 F0            [24]10684 	mov	b, @r0
      0036E9 08               [12]10685 	inc	r0
      0036EA E6               [12]10686 	mov	a, @r0
      0036EB 12 41 CE         [24]10687 	lcall	___fsadd
      0036EE AC 82            [24]10688 	mov	r4, dpl
      0036F0 AD 83            [24]10689 	mov	r5, dph
      0036F2 AE F0            [24]10690 	mov	r6, b
      0036F4 FF               [12]10691 	mov	r7, a
      0036F5 E5 81            [12]10692 	mov	a,sp
      0036F7 24 FC            [12]10693 	add	a,#0xfc
      0036F9 F5 81            [12]10694 	mov	sp,a
      0036FB 8C 82            [24]10695 	mov	dpl, r4
      0036FD 8D 83            [24]10696 	mov	dph, r5
      0036FF 8E F0            [24]10697 	mov	b, r6
      003701 EF               [12]10698 	mov	a, r7
                           003645 10699 	C$sugeno_demo.c$199$1_0$167 ==.
                                  10700 ;	../../sugeno_demo.c:199: }
      003702 85 08 81         [24]10701 	mov	sp,_bp
      003705 D0 08            [24]10702 	pop	_bp
                           00364A 10703 	C$sugeno_demo.c$199$1_0$167 ==.
                           00364A 10704 	XFsugeno_demo$response_cooling$0$0 ==.
      003707 22               [24]10705 	ret
                                  10706 ;------------------------------------------------------------
                                  10707 ;Allocation info for local variables in function 'response_heavy_load'
                                  10708 ;------------------------------------------------------------
                                  10709 ;load          Allocated to stack - _bp -6 +4 
                                  10710 ;vibration     Allocated to stack - _bp -10 +4 
                                  10711 ;temperature   Allocated to registers r4 r5 r6 r7 
                                  10712 ;sloc0         Allocated to stack - _bp +1 +4 
                                  10713 ;------------------------------------------------------------
                           00364B 10714 	Fsugeno_demo$response_heavy_load$0$0 ==.
                           00364B 10715 	C$sugeno_demo.c$202$1_0$169 ==.
                                  10716 ;	../../sugeno_demo.c:202: static float response_heavy_load(
                                  10717 ;	-----------------------------------------
                                  10718 ;	 function response_heavy_load
                                  10719 ;	-----------------------------------------
      003708                      10720 _response_heavy_load:
      003708 C0 08            [24]10721 	push	_bp
      00370A 85 81 08         [24]10722 	mov	_bp,sp
      00370D AC 82            [24]10723 	mov	r4,dpl
      00370F AD 83            [24]10724 	mov	r5,dph
      003711 AE F0            [24]10725 	mov	r6,b
      003713 FF               [12]10726 	mov	r7,a
      003714 E5 81            [12]10727 	mov	a,sp
      003716 24 04            [12]10728 	add	a,#0x04
      003718 F5 81            [12]10729 	mov	sp,a
                           00365D 10730 	C$sugeno_demo.c$210$1_0$169 ==.
                                  10731 ;	../../sugeno_demo.c:210: 0.30f * temperature +
      00371A C0 04            [24]10732 	push	ar4
      00371C C0 05            [24]10733 	push	ar5
      00371E C0 06            [24]10734 	push	ar6
      003720 C0 07            [24]10735 	push	ar7
      003722 90 99 9A         [24]10736 	mov	dptr,#0x999a
      003725 75 F0 99         [24]10737 	mov	b, #0x99
      003728 74 3E            [12]10738 	mov	a, #0x3e
      00372A 12 40 4C         [24]10739 	lcall	___fsmul
      00372D AC 82            [24]10740 	mov	r4, dpl
      00372F AD 83            [24]10741 	mov	r5, dph
      003731 AE F0            [24]10742 	mov	r6, b
      003733 FF               [12]10743 	mov	r7, a
      003734 E5 81            [12]10744 	mov	a,sp
      003736 24 FC            [12]10745 	add	a,#0xfc
      003738 F5 81            [12]10746 	mov	sp,a
      00373A E4               [12]10747 	clr	a
      00373B C0 E0            [24]10748 	push	acc
      00373D C0 E0            [24]10749 	push	acc
      00373F 74 90            [12]10750 	mov	a,#0x90
      003741 C0 E0            [24]10751 	push	acc
      003743 74 41            [12]10752 	mov	a,#0x41
      003745 C0 E0            [24]10753 	push	acc
                           00368A 10754 	C$sugeno_demo.c$211$1_0$169 ==.
                                  10755 ;	../../sugeno_demo.c:211: 0.55f * load +
      003747 8C 82            [24]10756 	mov	dpl, r4
      003749 8D 83            [24]10757 	mov	dph, r5
      00374B 8E F0            [24]10758 	mov	b, r6
      00374D EF               [12]10759 	mov	a, r7
      00374E 12 41 CE         [24]10760 	lcall	___fsadd
      003751 A8 08            [24]10761 	mov	r0,_bp
      003753 08               [12]10762 	inc	r0
      003754 A6 82            [24]10763 	mov	@r0, dpl
      003756 08               [12]10764 	inc	r0
      003757 A6 83            [24]10765 	mov	@r0, dph
      003759 08               [12]10766 	inc	r0
      00375A A6 F0            [24]10767 	mov	@r0, b
      00375C 08               [12]10768 	inc	r0
      00375D F6               [12]10769 	mov	@r0,a
      00375E E5 81            [12]10770 	mov	a,sp
      003760 24 FC            [12]10771 	add	a,#0xfc
      003762 F5 81            [12]10772 	mov	sp,a
      003764 E5 08            [12]10773 	mov	a,_bp
      003766 24 FA            [12]10774 	add	a,#0xfa
      003768 F8               [12]10775 	mov	r0,a
      003769 E6               [12]10776 	mov	a,@r0
      00376A C0 E0            [24]10777 	push	acc
      00376C 08               [12]10778 	inc	r0
      00376D E6               [12]10779 	mov	a,@r0
      00376E C0 E0            [24]10780 	push	acc
      003770 08               [12]10781 	inc	r0
      003771 E6               [12]10782 	mov	a,@r0
      003772 C0 E0            [24]10783 	push	acc
      003774 08               [12]10784 	inc	r0
      003775 E6               [12]10785 	mov	a,@r0
      003776 C0 E0            [24]10786 	push	acc
      003778 90 CC CD         [24]10787 	mov	dptr,#0xcccd
      00377B 75 F0 0C         [24]10788 	mov	b, #0x0c
      00377E 74 3F            [12]10789 	mov	a, #0x3f
      003780 12 40 4C         [24]10790 	lcall	___fsmul
      003783 AA 82            [24]10791 	mov	r2, dpl
      003785 AB 83            [24]10792 	mov	r3, dph
      003787 AE F0            [24]10793 	mov	r6, b
      003789 FF               [12]10794 	mov	r7, a
      00378A E5 81            [12]10795 	mov	a,sp
      00378C 24 FC            [12]10796 	add	a,#0xfc
      00378E F5 81            [12]10797 	mov	sp,a
      003790 C0 02            [24]10798 	push	ar2
      003792 C0 03            [24]10799 	push	ar3
      003794 C0 06            [24]10800 	push	ar6
      003796 C0 07            [24]10801 	push	ar7
                           0036DB 10802 	C$sugeno_demo.c$212$1_0$169 ==.
                                  10803 ;	../../sugeno_demo.c:212: 1.00f * vibration;
      003798 A8 08            [24]10804 	mov	r0,_bp
      00379A 08               [12]10805 	inc	r0
      00379B 86 82            [24]10806 	mov	dpl, @r0
      00379D 08               [12]10807 	inc	r0
      00379E 86 83            [24]10808 	mov	dph, @r0
      0037A0 08               [12]10809 	inc	r0
      0037A1 86 F0            [24]10810 	mov	b, @r0
      0037A3 08               [12]10811 	inc	r0
      0037A4 E6               [12]10812 	mov	a, @r0
      0037A5 12 41 CE         [24]10813 	lcall	___fsadd
      0037A8 AC 82            [24]10814 	mov	r4, dpl
      0037AA AD 83            [24]10815 	mov	r5, dph
      0037AC AE F0            [24]10816 	mov	r6, b
      0037AE FF               [12]10817 	mov	r7, a
      0037AF E5 81            [12]10818 	mov	a,sp
      0037B1 24 FC            [12]10819 	add	a,#0xfc
      0037B3 F5 81            [12]10820 	mov	sp,a
      0037B5 E5 08            [12]10821 	mov	a,_bp
      0037B7 24 F6            [12]10822 	add	a,#0xf6
      0037B9 F8               [12]10823 	mov	r0,a
      0037BA E6               [12]10824 	mov	a,@r0
      0037BB C0 E0            [24]10825 	push	acc
      0037BD 08               [12]10826 	inc	r0
      0037BE E6               [12]10827 	mov	a,@r0
      0037BF C0 E0            [24]10828 	push	acc
      0037C1 08               [12]10829 	inc	r0
      0037C2 E6               [12]10830 	mov	a,@r0
      0037C3 C0 E0            [24]10831 	push	acc
      0037C5 08               [12]10832 	inc	r0
      0037C6 E6               [12]10833 	mov	a,@r0
      0037C7 C0 E0            [24]10834 	push	acc
      0037C9 8C 82            [24]10835 	mov	dpl, r4
      0037CB 8D 83            [24]10836 	mov	dph, r5
      0037CD 8E F0            [24]10837 	mov	b, r6
      0037CF EF               [12]10838 	mov	a, r7
      0037D0 12 41 CE         [24]10839 	lcall	___fsadd
      0037D3 AC 82            [24]10840 	mov	r4, dpl
      0037D5 AD 83            [24]10841 	mov	r5, dph
      0037D7 AE F0            [24]10842 	mov	r6, b
      0037D9 FF               [12]10843 	mov	r7, a
      0037DA E5 81            [12]10844 	mov	a,sp
      0037DC 24 FC            [12]10845 	add	a,#0xfc
      0037DE F5 81            [12]10846 	mov	sp,a
      0037E0 8C 82            [24]10847 	mov	dpl, r4
      0037E2 8D 83            [24]10848 	mov	dph, r5
      0037E4 8E F0            [24]10849 	mov	b, r6
      0037E6 EF               [12]10850 	mov	a, r7
                           00372A 10851 	C$sugeno_demo.c$213$1_0$169 ==.
                                  10852 ;	../../sugeno_demo.c:213: }
      0037E7 85 08 81         [24]10853 	mov	sp,_bp
      0037EA D0 08            [24]10854 	pop	_bp
                           00372F 10855 	C$sugeno_demo.c$213$1_0$169 ==.
                           00372F 10856 	XFsugeno_demo$response_heavy_load$0$0 ==.
      0037EC 22               [24]10857 	ret
                                  10858 ;------------------------------------------------------------
                                  10859 ;Allocation info for local variables in function 'response_protection'
                                  10860 ;------------------------------------------------------------
                                  10861 ;load          Allocated to stack - _bp -6 +4 
                                  10862 ;vibration     Allocated to stack - _bp -10 +4 
                                  10863 ;temperature   Allocated to registers r4 r5 r6 r7 
                                  10864 ;sloc0         Allocated to stack - _bp +1 +4 
                                  10865 ;------------------------------------------------------------
                           003730 10866 	Fsugeno_demo$response_protection$0$0 ==.
                           003730 10867 	C$sugeno_demo.c$216$1_0$171 ==.
                                  10868 ;	../../sugeno_demo.c:216: static float response_protection(
                                  10869 ;	-----------------------------------------
                                  10870 ;	 function response_protection
                                  10871 ;	-----------------------------------------
      0037ED                      10872 _response_protection:
      0037ED C0 08            [24]10873 	push	_bp
      0037EF 85 81 08         [24]10874 	mov	_bp,sp
      0037F2 AC 82            [24]10875 	mov	r4,dpl
      0037F4 AD 83            [24]10876 	mov	r5,dph
      0037F6 AE F0            [24]10877 	mov	r6,b
      0037F8 FF               [12]10878 	mov	r7,a
      0037F9 E5 81            [12]10879 	mov	a,sp
      0037FB 24 04            [12]10880 	add	a,#0x04
      0037FD F5 81            [12]10881 	mov	sp,a
                           003742 10882 	C$sugeno_demo.c$224$1_0$171 ==.
                                  10883 ;	../../sugeno_demo.c:224: 0.45f * temperature +
      0037FF C0 04            [24]10884 	push	ar4
      003801 C0 05            [24]10885 	push	ar5
      003803 C0 06            [24]10886 	push	ar6
      003805 C0 07            [24]10887 	push	ar7
      003807 90 66 66         [24]10888 	mov	dptr,#0x6666
      00380A 75 F0 E6         [24]10889 	mov	b, #0xe6
      00380D 74 3E            [12]10890 	mov	a, #0x3e
      00380F 12 40 4C         [24]10891 	lcall	___fsmul
      003812 AC 82            [24]10892 	mov	r4, dpl
      003814 AD 83            [24]10893 	mov	r5, dph
      003816 AE F0            [24]10894 	mov	r6, b
      003818 FF               [12]10895 	mov	r7, a
      003819 E5 81            [12]10896 	mov	a,sp
      00381B 24 FC            [12]10897 	add	a,#0xfc
      00381D F5 81            [12]10898 	mov	sp,a
      00381F E4               [12]10899 	clr	a
      003820 C0 E0            [24]10900 	push	acc
      003822 C0 E0            [24]10901 	push	acc
      003824 74 0C            [12]10902 	mov	a,#0x0c
      003826 C0 E0            [24]10903 	push	acc
      003828 74 42            [12]10904 	mov	a,#0x42
      00382A C0 E0            [24]10905 	push	acc
                           00376F 10906 	C$sugeno_demo.c$225$1_0$171 ==.
                                  10907 ;	../../sugeno_demo.c:225: 0.30f * load +
      00382C 8C 82            [24]10908 	mov	dpl, r4
      00382E 8D 83            [24]10909 	mov	dph, r5
      003830 8E F0            [24]10910 	mov	b, r6
      003832 EF               [12]10911 	mov	a, r7
      003833 12 41 CE         [24]10912 	lcall	___fsadd
      003836 A8 08            [24]10913 	mov	r0,_bp
      003838 08               [12]10914 	inc	r0
      003839 A6 82            [24]10915 	mov	@r0, dpl
      00383B 08               [12]10916 	inc	r0
      00383C A6 83            [24]10917 	mov	@r0, dph
      00383E 08               [12]10918 	inc	r0
      00383F A6 F0            [24]10919 	mov	@r0, b
      003841 08               [12]10920 	inc	r0
      003842 F6               [12]10921 	mov	@r0,a
      003843 E5 81            [12]10922 	mov	a,sp
      003845 24 FC            [12]10923 	add	a,#0xfc
      003847 F5 81            [12]10924 	mov	sp,a
      003849 E5 08            [12]10925 	mov	a,_bp
      00384B 24 FA            [12]10926 	add	a,#0xfa
      00384D F8               [12]10927 	mov	r0,a
      00384E E6               [12]10928 	mov	a,@r0
      00384F C0 E0            [24]10929 	push	acc
      003851 08               [12]10930 	inc	r0
      003852 E6               [12]10931 	mov	a,@r0
      003853 C0 E0            [24]10932 	push	acc
      003855 08               [12]10933 	inc	r0
      003856 E6               [12]10934 	mov	a,@r0
      003857 C0 E0            [24]10935 	push	acc
      003859 08               [12]10936 	inc	r0
      00385A E6               [12]10937 	mov	a,@r0
      00385B C0 E0            [24]10938 	push	acc
      00385D 90 99 9A         [24]10939 	mov	dptr,#0x999a
      003860 75 F0 99         [24]10940 	mov	b, #0x99
      003863 74 3E            [12]10941 	mov	a, #0x3e
      003865 12 40 4C         [24]10942 	lcall	___fsmul
      003868 AA 82            [24]10943 	mov	r2, dpl
      00386A AB 83            [24]10944 	mov	r3, dph
      00386C AE F0            [24]10945 	mov	r6, b
      00386E FF               [12]10946 	mov	r7, a
      00386F E5 81            [12]10947 	mov	a,sp
      003871 24 FC            [12]10948 	add	a,#0xfc
      003873 F5 81            [12]10949 	mov	sp,a
      003875 C0 02            [24]10950 	push	ar2
      003877 C0 03            [24]10951 	push	ar3
      003879 C0 06            [24]10952 	push	ar6
      00387B C0 07            [24]10953 	push	ar7
                           0037C0 10954 	C$sugeno_demo.c$226$1_0$171 ==.
                                  10955 ;	../../sugeno_demo.c:226: 2.50f * vibration;
      00387D A8 08            [24]10956 	mov	r0,_bp
      00387F 08               [12]10957 	inc	r0
      003880 86 82            [24]10958 	mov	dpl, @r0
      003882 08               [12]10959 	inc	r0
      003883 86 83            [24]10960 	mov	dph, @r0
      003885 08               [12]10961 	inc	r0
      003886 86 F0            [24]10962 	mov	b, @r0
      003888 08               [12]10963 	inc	r0
      003889 E6               [12]10964 	mov	a, @r0
      00388A 12 41 CE         [24]10965 	lcall	___fsadd
      00388D A8 08            [24]10966 	mov	r0,_bp
      00388F 08               [12]10967 	inc	r0
      003890 A6 82            [24]10968 	mov	@r0, dpl
      003892 08               [12]10969 	inc	r0
      003893 A6 83            [24]10970 	mov	@r0, dph
      003895 08               [12]10971 	inc	r0
      003896 A6 F0            [24]10972 	mov	@r0, b
      003898 08               [12]10973 	inc	r0
      003899 F6               [12]10974 	mov	@r0,a
      00389A E5 81            [12]10975 	mov	a,sp
      00389C 24 FC            [12]10976 	add	a,#0xfc
      00389E F5 81            [12]10977 	mov	sp,a
      0038A0 E5 08            [12]10978 	mov	a,_bp
      0038A2 24 F6            [12]10979 	add	a,#0xf6
      0038A4 F8               [12]10980 	mov	r0,a
      0038A5 E6               [12]10981 	mov	a,@r0
      0038A6 C0 E0            [24]10982 	push	acc
      0038A8 08               [12]10983 	inc	r0
      0038A9 E6               [12]10984 	mov	a,@r0
      0038AA C0 E0            [24]10985 	push	acc
      0038AC 08               [12]10986 	inc	r0
      0038AD E6               [12]10987 	mov	a,@r0
      0038AE C0 E0            [24]10988 	push	acc
      0038B0 08               [12]10989 	inc	r0
      0038B1 E6               [12]10990 	mov	a,@r0
      0038B2 C0 E0            [24]10991 	push	acc
      0038B4 90 00 00         [24]10992 	mov	dptr,#0x0000
      0038B7 75 F0 20         [24]10993 	mov	b, #0x20
      0038BA 74 40            [12]10994 	mov	a, #0x40
      0038BC 12 40 4C         [24]10995 	lcall	___fsmul
      0038BF AA 82            [24]10996 	mov	r2, dpl
      0038C1 AB 83            [24]10997 	mov	r3, dph
      0038C3 AE F0            [24]10998 	mov	r6, b
      0038C5 FF               [12]10999 	mov	r7, a
      0038C6 E5 81            [12]11000 	mov	a,sp
      0038C8 24 FC            [12]11001 	add	a,#0xfc
      0038CA F5 81            [12]11002 	mov	sp,a
      0038CC C0 02            [24]11003 	push	ar2
      0038CE C0 03            [24]11004 	push	ar3
      0038D0 C0 06            [24]11005 	push	ar6
      0038D2 C0 07            [24]11006 	push	ar7
      0038D4 A8 08            [24]11007 	mov	r0,_bp
      0038D6 08               [12]11008 	inc	r0
      0038D7 86 82            [24]11009 	mov	dpl, @r0
      0038D9 08               [12]11010 	inc	r0
      0038DA 86 83            [24]11011 	mov	dph, @r0
      0038DC 08               [12]11012 	inc	r0
      0038DD 86 F0            [24]11013 	mov	b, @r0
      0038DF 08               [12]11014 	inc	r0
      0038E0 E6               [12]11015 	mov	a, @r0
      0038E1 12 41 CE         [24]11016 	lcall	___fsadd
      0038E4 AC 82            [24]11017 	mov	r4, dpl
      0038E6 AD 83            [24]11018 	mov	r5, dph
      0038E8 AE F0            [24]11019 	mov	r6, b
      0038EA FF               [12]11020 	mov	r7, a
      0038EB E5 81            [12]11021 	mov	a,sp
      0038ED 24 FC            [12]11022 	add	a,#0xfc
      0038EF F5 81            [12]11023 	mov	sp,a
      0038F1 8C 82            [24]11024 	mov	dpl, r4
      0038F3 8D 83            [24]11025 	mov	dph, r5
      0038F5 8E F0            [24]11026 	mov	b, r6
      0038F7 EF               [12]11027 	mov	a, r7
                           00383B 11028 	C$sugeno_demo.c$227$1_0$171 ==.
                                  11029 ;	../../sugeno_demo.c:227: }
      0038F8 85 08 81         [24]11030 	mov	sp,_bp
      0038FB D0 08            [24]11031 	pop	_bp
                           003840 11032 	C$sugeno_demo.c$227$1_0$171 ==.
                           003840 11033 	XFsugeno_demo$response_protection$0$0 ==.
      0038FD 22               [24]11034 	ret
                                  11035 ;------------------------------------------------------------
                                  11036 ;Allocation info for local variables in function 'calculate_fan_speed'
                                  11037 ;------------------------------------------------------------
                                  11038 ;load          Allocated to stack - _bp -6 +4 
                                  11039 ;vibration     Allocated to stack - _bp -10 +4 
                                  11040 ;temperature   Allocated to stack - _bp +1 +4 
                                  11041 ;temperature_low_value Allocated to registers r7 r6 r5 r4 
                                  11042 ;temperature_high_value Allocated to stack - _bp +5 +4 
                                  11043 ;load_low_value Allocated to stack - _bp +9 +4 
                                  11044 ;load_high_value Allocated to stack - _bp +13 +4 
                                  11045 ;vibration_low_value Allocated to stack - _bp +17 +4 
                                  11046 ;vibration_high_value Allocated to stack - _bp +21 +4 
                                  11047 ;rule1         Allocated to stack - _bp +25 +4 
                                  11048 ;rule2         Allocated to stack - _bp +29 +4 
                                  11049 ;rule3         Allocated to stack - _bp +33 +4 
                                  11050 ;rule4         Allocated to stack - _bp +37 +4 
                                  11051 ;rule5         Allocated to stack - _bp +41 +4 
                                  11052 ;rule6         Allocated to stack - _bp +45 +4 
                                  11053 ;rule6_thermal Allocated to stack - _bp +49 +4 
                                  11054 ;rule6_mechanical Allocated to registers r4 r5 r6 r7 
                                  11055 ;------------------------------------------------------------
                           003841 11056 	Fsugeno_demo$calculate_fan_speed$0$0 ==.
                           003841 11057 	C$sugeno_demo.c$254$1_0$173 ==.
                                  11058 ;	../../sugeno_demo.c:254: static float calculate_fan_speed(
                                  11059 ;	-----------------------------------------
                                  11060 ;	 function calculate_fan_speed
                                  11061 ;	-----------------------------------------
      0038FE                      11062 _calculate_fan_speed:
      0038FE C0 08            [24]11063 	push	_bp
      003900 85 81 08         [24]11064 	mov	_bp,sp
      003903 C0 82            [24]11065 	push	dpl
      003905 C0 83            [24]11066 	push	dph
      003907 C0 F0            [24]11067 	push	b
      003909 C0 E0            [24]11068 	push	acc
      00390B E5 81            [12]11069 	mov	a,sp
      00390D 24 30            [12]11070 	add	a,#0x30
      00390F F5 81            [12]11071 	mov	sp,a
                           003854 11072 	C$sugeno_demo.c$281$1_0$173 ==.
                                  11073 ;	../../sugeno_demo.c:281: temperature
      003911 A8 08            [24]11074 	mov	r0,_bp
      003913 08               [12]11075 	inc	r0
      003914 86 82            [24]11076 	mov	dpl, @r0
      003916 08               [12]11077 	inc	r0
      003917 86 83            [24]11078 	mov	dph, @r0
      003919 08               [12]11079 	inc	r0
      00391A 86 F0            [24]11080 	mov	b, @r0
      00391C 08               [12]11081 	inc	r0
      00391D E6               [12]11082 	mov	a, @r0
      00391E 12 31 29         [24]11083 	lcall	_temperature_low
      003921 AF 82            [24]11084 	mov	r7, dpl
      003923 AE 83            [24]11085 	mov	r6, dph
      003925 AD F0            [24]11086 	mov	r5, b
      003927 FC               [12]11087 	mov	r4, a
                           00386B 11088 	C$sugeno_demo.c$286$1_0$173 ==.
                                  11089 ;	../../sugeno_demo.c:286: temperature
      003928 A8 08            [24]11090 	mov	r0,_bp
      00392A 08               [12]11091 	inc	r0
      00392B 86 82            [24]11092 	mov	dpl, @r0
      00392D 08               [12]11093 	inc	r0
      00392E 86 83            [24]11094 	mov	dph, @r0
      003930 08               [12]11095 	inc	r0
      003931 86 F0            [24]11096 	mov	b, @r0
      003933 08               [12]11097 	inc	r0
      003934 E6               [12]11098 	mov	a, @r0
      003935 C0 07            [24]11099 	push	ar7
      003937 C0 06            [24]11100 	push	ar6
      003939 C0 05            [24]11101 	push	ar5
      00393B C0 04            [24]11102 	push	ar4
      00393D 12 31 6E         [24]11103 	lcall	_temperature_high
      003940 C8               [12]11104 	xch	a,r0
      003941 E5 08            [12]11105 	mov	a,_bp
      003943 24 05            [12]11106 	add	a,#0x05
      003945 C8               [12]11107 	xch	a,r0
      003946 A6 82            [24]11108 	mov	@r0, dpl
      003948 08               [12]11109 	inc	r0
      003949 A6 83            [24]11110 	mov	@r0, dph
      00394B 08               [12]11111 	inc	r0
      00394C A6 F0            [24]11112 	mov	@r0, b
      00394E 08               [12]11113 	inc	r0
      00394F F6               [12]11114 	mov	@r0,a
                           003893 11115 	C$sugeno_demo.c$291$1_0$173 ==.
                                  11116 ;	../../sugeno_demo.c:291: load
      003950 E5 08            [12]11117 	mov	a,_bp
      003952 24 FA            [12]11118 	add	a,#0xfa
      003954 F8               [12]11119 	mov	r0,a
      003955 86 82            [24]11120 	mov	dpl, @r0
      003957 08               [12]11121 	inc	r0
      003958 86 83            [24]11122 	mov	dph, @r0
      00395A 08               [12]11123 	inc	r0
      00395B 86 F0            [24]11124 	mov	b, @r0
      00395D 08               [12]11125 	inc	r0
      00395E E6               [12]11126 	mov	a, @r0
      00395F 12 31 B4         [24]11127 	lcall	_load_low
      003962 C8               [12]11128 	xch	a,r0
      003963 E5 08            [12]11129 	mov	a,_bp
      003965 24 09            [12]11130 	add	a,#0x09
      003967 C8               [12]11131 	xch	a,r0
      003968 A6 82            [24]11132 	mov	@r0, dpl
      00396A 08               [12]11133 	inc	r0
      00396B A6 83            [24]11134 	mov	@r0, dph
      00396D 08               [12]11135 	inc	r0
      00396E A6 F0            [24]11136 	mov	@r0, b
      003970 08               [12]11137 	inc	r0
      003971 F6               [12]11138 	mov	@r0,a
                           0038B5 11139 	C$sugeno_demo.c$296$1_0$173 ==.
                                  11140 ;	../../sugeno_demo.c:296: load
      003972 E5 08            [12]11141 	mov	a,_bp
      003974 24 FA            [12]11142 	add	a,#0xfa
      003976 F8               [12]11143 	mov	r0,a
      003977 86 82            [24]11144 	mov	dpl, @r0
      003979 08               [12]11145 	inc	r0
      00397A 86 83            [24]11146 	mov	dph, @r0
      00397C 08               [12]11147 	inc	r0
      00397D 86 F0            [24]11148 	mov	b, @r0
      00397F 08               [12]11149 	inc	r0
      003980 E6               [12]11150 	mov	a, @r0
      003981 12 31 F9         [24]11151 	lcall	_load_high
      003984 C8               [12]11152 	xch	a,r0
      003985 E5 08            [12]11153 	mov	a,_bp
      003987 24 0D            [12]11154 	add	a,#0x0d
      003989 C8               [12]11155 	xch	a,r0
      00398A A6 82            [24]11156 	mov	@r0, dpl
      00398C 08               [12]11157 	inc	r0
      00398D A6 83            [24]11158 	mov	@r0, dph
      00398F 08               [12]11159 	inc	r0
      003990 A6 F0            [24]11160 	mov	@r0, b
      003992 08               [12]11161 	inc	r0
      003993 F6               [12]11162 	mov	@r0,a
                           0038D7 11163 	C$sugeno_demo.c$301$1_0$173 ==.
                                  11164 ;	../../sugeno_demo.c:301: vibration
      003994 E5 08            [12]11165 	mov	a,_bp
      003996 24 F6            [12]11166 	add	a,#0xf6
      003998 F8               [12]11167 	mov	r0,a
      003999 86 82            [24]11168 	mov	dpl, @r0
      00399B 08               [12]11169 	inc	r0
      00399C 86 83            [24]11170 	mov	dph, @r0
      00399E 08               [12]11171 	inc	r0
      00399F 86 F0            [24]11172 	mov	b, @r0
      0039A1 08               [12]11173 	inc	r0
      0039A2 E6               [12]11174 	mov	a, @r0
      0039A3 12 32 3F         [24]11175 	lcall	_vibration_low
      0039A6 C8               [12]11176 	xch	a,r0
      0039A7 E5 08            [12]11177 	mov	a,_bp
      0039A9 24 11            [12]11178 	add	a,#0x11
      0039AB C8               [12]11179 	xch	a,r0
      0039AC A6 82            [24]11180 	mov	@r0, dpl
      0039AE 08               [12]11181 	inc	r0
      0039AF A6 83            [24]11182 	mov	@r0, dph
      0039B1 08               [12]11183 	inc	r0
      0039B2 A6 F0            [24]11184 	mov	@r0, b
      0039B4 08               [12]11185 	inc	r0
      0039B5 F6               [12]11186 	mov	@r0,a
                           0038F9 11187 	C$sugeno_demo.c$306$1_0$173 ==.
                                  11188 ;	../../sugeno_demo.c:306: vibration
      0039B6 E5 08            [12]11189 	mov	a,_bp
      0039B8 24 F6            [12]11190 	add	a,#0xf6
      0039BA F8               [12]11191 	mov	r0,a
      0039BB 86 82            [24]11192 	mov	dpl, @r0
      0039BD 08               [12]11193 	inc	r0
      0039BE 86 83            [24]11194 	mov	dph, @r0
      0039C0 08               [12]11195 	inc	r0
      0039C1 86 F0            [24]11196 	mov	b, @r0
      0039C3 08               [12]11197 	inc	r0
      0039C4 E6               [12]11198 	mov	a, @r0
      0039C5 12 32 83         [24]11199 	lcall	_vibration_high
      0039C8 C8               [12]11200 	xch	a,r0
      0039C9 E5 08            [12]11201 	mov	a,_bp
      0039CB 24 15            [12]11202 	add	a,#0x15
      0039CD C8               [12]11203 	xch	a,r0
      0039CE A6 82            [24]11204 	mov	@r0, dpl
      0039D0 08               [12]11205 	inc	r0
      0039D1 A6 83            [24]11206 	mov	@r0, dph
      0039D3 08               [12]11207 	inc	r0
      0039D4 A6 F0            [24]11208 	mov	@r0, b
      0039D6 08               [12]11209 	inc	r0
      0039D7 F6               [12]11210 	mov	@r0,a
                           00391B 11211 	C$sugeno_demo.c$310$1_0$173 ==.
                                  11212 ;	../../sugeno_demo.c:310: fuzzy_and_method(
      0039D8 12 00 BD         [24]11213 	lcall	_fuzzy_values_initialize
      0039DB D0 04            [24]11214 	pop	ar4
      0039DD D0 05            [24]11215 	pop	ar5
      0039DF D0 06            [24]11216 	pop	ar6
      0039E1 D0 07            [24]11217 	pop	ar7
      0039E3 8F 21            [24]11218 	mov	(_fuzzy_values_buffer + 0),r7
      0039E5 8E 22            [24]11219 	mov	(_fuzzy_values_buffer + 1),r6
      0039E7 8D 23            [24]11220 	mov	(_fuzzy_values_buffer + 2),r5
      0039E9 8C 24            [24]11221 	mov	(_fuzzy_values_buffer + 3),r4
      0039EB E5 08            [12]11222 	mov	a,_bp
      0039ED 24 09            [12]11223 	add	a,#0x09
      0039EF F8               [12]11224 	mov	r0,a
      0039F0 86 25            [24]11225 	mov	((_fuzzy_values_buffer + 0x0004) + 0),@r0
      0039F2 08               [12]11226 	inc	r0
      0039F3 86 26            [24]11227 	mov	((_fuzzy_values_buffer + 0x0004) + 1),@r0
      0039F5 08               [12]11228 	inc	r0
      0039F6 86 27            [24]11229 	mov	((_fuzzy_values_buffer + 0x0004) + 2),@r0
      0039F8 08               [12]11230 	inc	r0
      0039F9 86 28            [24]11231 	mov	((_fuzzy_values_buffer + 0x0004) + 3),@r0
      0039FB E5 08            [12]11232 	mov	a,_bp
      0039FD 24 11            [12]11233 	add	a,#0x11
      0039FF F8               [12]11234 	mov	r0,a
      003A00 86 29            [24]11235 	mov	((_fuzzy_values_buffer + 0x0008) + 0),@r0
      003A02 08               [12]11236 	inc	r0
      003A03 86 2A            [24]11237 	mov	((_fuzzy_values_buffer + 0x0008) + 1),@r0
      003A05 08               [12]11238 	inc	r0
      003A06 86 2B            [24]11239 	mov	((_fuzzy_values_buffer + 0x0008) + 2),@r0
      003A08 08               [12]11240 	inc	r0
      003A09 86 2C            [24]11241 	mov	((_fuzzy_values_buffer + 0x0008) + 3),@r0
      003A0B 74 21            [12]11242 	mov	a,#_fuzzy_values_buffer
      003A0D C0 E0            [24]11243 	push	acc
      003A0F 74 00            [12]11244 	mov	a,#(_fuzzy_values_buffer >> 8)
      003A11 C0 E0            [24]11245 	push	acc
      003A13 74 40            [12]11246 	mov	a,#0x40
      003A15 C0 E0            [24]11247 	push	acc
      003A17 74 03            [12]11248 	mov	a,#0x03
      003A19 C0 E0            [24]11249 	push	acc
      003A1B E4               [12]11250 	clr	a
      003A1C C0 E0            [24]11251 	push	acc
      003A1E 75 82 00         [24]11252 	mov	dpl, #0x00
      003A21 12 02 29         [24]11253 	lcall	_fuzzy_and_array
      003A24 C8               [12]11254 	xch	a,r0
      003A25 E5 08            [12]11255 	mov	a,_bp
      003A27 24 19            [12]11256 	add	a,#0x19
      003A29 C8               [12]11257 	xch	a,r0
      003A2A A6 82            [24]11258 	mov	@r0, dpl
      003A2C 08               [12]11259 	inc	r0
      003A2D A6 83            [24]11260 	mov	@r0, dph
      003A2F 08               [12]11261 	inc	r0
      003A30 A6 F0            [24]11262 	mov	@r0, b
      003A32 08               [12]11263 	inc	r0
      003A33 F6               [12]11264 	mov	@r0,a
      003A34 E5 81            [12]11265 	mov	a,sp
      003A36 24 FB            [12]11266 	add	a,#0xfb
      003A38 F5 81            [12]11267 	mov	sp,a
                           00397D 11268 	C$sugeno_demo.c$318$1_0$173 ==.
                                  11269 ;	../../sugeno_demo.c:318: fuzzy_and_method(
      003A3A 12 00 BD         [24]11270 	lcall	_fuzzy_values_initialize
      003A3D E5 08            [12]11271 	mov	a,_bp
      003A3F 24 05            [12]11272 	add	a,#0x05
      003A41 F8               [12]11273 	mov	r0,a
      003A42 86 82            [24]11274 	mov	dpl, @r0
      003A44 08               [12]11275 	inc	r0
      003A45 86 83            [24]11276 	mov	dph, @r0
      003A47 08               [12]11277 	inc	r0
      003A48 86 F0            [24]11278 	mov	b, @r0
      003A4A 08               [12]11279 	inc	r0
      003A4B E6               [12]11280 	mov	a, @r0
      003A4C 12 01 6D         [24]11281 	lcall	_fuzzy_not
      003A4F AA 82            [24]11282 	mov	r2, dpl
      003A51 AB 83            [24]11283 	mov	r3, dph
      003A53 AE F0            [24]11284 	mov	r6, b
      003A55 FF               [12]11285 	mov	r7, a
      003A56 8A 21            [24]11286 	mov	(_fuzzy_values_buffer + 0),r2
      003A58 8B 22            [24]11287 	mov	(_fuzzy_values_buffer + 1),r3
      003A5A 8E 23            [24]11288 	mov	(_fuzzy_values_buffer + 2),r6
      003A5C 8F 24            [24]11289 	mov	(_fuzzy_values_buffer + 3),r7
      003A5E E5 08            [12]11290 	mov	a,_bp
      003A60 24 0D            [12]11291 	add	a,#0x0d
      003A62 F8               [12]11292 	mov	r0,a
      003A63 86 25            [24]11293 	mov	((_fuzzy_values_buffer + 0x0004) + 0),@r0
      003A65 08               [12]11294 	inc	r0
      003A66 86 26            [24]11295 	mov	((_fuzzy_values_buffer + 0x0004) + 1),@r0
      003A68 08               [12]11296 	inc	r0
      003A69 86 27            [24]11297 	mov	((_fuzzy_values_buffer + 0x0004) + 2),@r0
      003A6B 08               [12]11298 	inc	r0
      003A6C 86 28            [24]11299 	mov	((_fuzzy_values_buffer + 0x0004) + 3),@r0
      003A6E 74 21            [12]11300 	mov	a,#_fuzzy_values_buffer
      003A70 C0 E0            [24]11301 	push	acc
      003A72 74 00            [12]11302 	mov	a,#(_fuzzy_values_buffer >> 8)
      003A74 C0 E0            [24]11303 	push	acc
      003A76 74 40            [12]11304 	mov	a,#0x40
      003A78 C0 E0            [24]11305 	push	acc
      003A7A 74 02            [12]11306 	mov	a,#0x02
      003A7C C0 E0            [24]11307 	push	acc
      003A7E E4               [12]11308 	clr	a
      003A7F C0 E0            [24]11309 	push	acc
      003A81 75 82 00         [24]11310 	mov	dpl, #0x00
      003A84 12 02 29         [24]11311 	lcall	_fuzzy_and_array
      003A87 C8               [12]11312 	xch	a,r0
      003A88 E5 08            [12]11313 	mov	a,_bp
      003A8A 24 1D            [12]11314 	add	a,#0x1d
      003A8C C8               [12]11315 	xch	a,r0
      003A8D A6 82            [24]11316 	mov	@r0, dpl
      003A8F 08               [12]11317 	inc	r0
      003A90 A6 83            [24]11318 	mov	@r0, dph
      003A92 08               [12]11319 	inc	r0
      003A93 A6 F0            [24]11320 	mov	@r0, b
      003A95 08               [12]11321 	inc	r0
      003A96 F6               [12]11322 	mov	@r0,a
      003A97 E5 81            [12]11323 	mov	a,sp
      003A99 24 FB            [12]11324 	add	a,#0xfb
      003A9B F5 81            [12]11325 	mov	sp,a
                           0039E0 11326 	C$sugeno_demo.c$327$1_0$173 ==.
                                  11327 ;	../../sugeno_demo.c:327: fuzzy_or_method(
      003A9D 12 00 BD         [24]11328 	lcall	_fuzzy_values_initialize
      003AA0 E5 08            [12]11329 	mov	a,_bp
      003AA2 24 05            [12]11330 	add	a,#0x05
      003AA4 F8               [12]11331 	mov	r0,a
      003AA5 86 21            [24]11332 	mov	(_fuzzy_values_buffer + 0),@r0
      003AA7 08               [12]11333 	inc	r0
      003AA8 86 22            [24]11334 	mov	(_fuzzy_values_buffer + 1),@r0
      003AAA 08               [12]11335 	inc	r0
      003AAB 86 23            [24]11336 	mov	(_fuzzy_values_buffer + 2),@r0
      003AAD 08               [12]11337 	inc	r0
      003AAE 86 24            [24]11338 	mov	(_fuzzy_values_buffer + 3),@r0
      003AB0 E5 08            [12]11339 	mov	a,_bp
      003AB2 24 15            [12]11340 	add	a,#0x15
      003AB4 F8               [12]11341 	mov	r0,a
      003AB5 86 25            [24]11342 	mov	((_fuzzy_values_buffer + 0x0004) + 0),@r0
      003AB7 08               [12]11343 	inc	r0
      003AB8 86 26            [24]11344 	mov	((_fuzzy_values_buffer + 0x0004) + 1),@r0
      003ABA 08               [12]11345 	inc	r0
      003ABB 86 27            [24]11346 	mov	((_fuzzy_values_buffer + 0x0004) + 2),@r0
      003ABD 08               [12]11347 	inc	r0
      003ABE 86 28            [24]11348 	mov	((_fuzzy_values_buffer + 0x0004) + 3),@r0
      003AC0 74 21            [12]11349 	mov	a,#_fuzzy_values_buffer
      003AC2 C0 E0            [24]11350 	push	acc
      003AC4 74 00            [12]11351 	mov	a,#(_fuzzy_values_buffer >> 8)
      003AC6 C0 E0            [24]11352 	push	acc
      003AC8 74 40            [12]11353 	mov	a,#0x40
      003ACA C0 E0            [24]11354 	push	acc
      003ACC 74 02            [12]11355 	mov	a,#0x02
      003ACE C0 E0            [24]11356 	push	acc
      003AD0 E4               [12]11357 	clr	a
      003AD1 C0 E0            [24]11358 	push	acc
      003AD3 75 82 00         [24]11359 	mov	dpl, #0x00
      003AD6 12 04 C8         [24]11360 	lcall	_fuzzy_or_array
      003AD9 C8               [12]11361 	xch	a,r0
      003ADA E5 08            [12]11362 	mov	a,_bp
      003ADC 24 21            [12]11363 	add	a,#0x21
      003ADE C8               [12]11364 	xch	a,r0
      003ADF A6 82            [24]11365 	mov	@r0, dpl
      003AE1 08               [12]11366 	inc	r0
      003AE2 A6 83            [24]11367 	mov	@r0, dph
      003AE4 08               [12]11368 	inc	r0
      003AE5 A6 F0            [24]11369 	mov	@r0, b
      003AE7 08               [12]11370 	inc	r0
      003AE8 F6               [12]11371 	mov	@r0,a
      003AE9 E5 81            [12]11372 	mov	a,sp
      003AEB 24 FB            [12]11373 	add	a,#0xfb
      003AED F5 81            [12]11374 	mov	sp,a
                           003A32 11375 	C$sugeno_demo.c$334$1_0$173 ==.
                                  11376 ;	../../sugeno_demo.c:334: fuzzy_and_method(
      003AEF 12 00 BD         [24]11377 	lcall	_fuzzy_values_initialize
      003AF2 E5 08            [12]11378 	mov	a,_bp
      003AF4 24 05            [12]11379 	add	a,#0x05
      003AF6 F8               [12]11380 	mov	r0,a
      003AF7 86 21            [24]11381 	mov	(_fuzzy_values_buffer + 0),@r0
      003AF9 08               [12]11382 	inc	r0
      003AFA 86 22            [24]11383 	mov	(_fuzzy_values_buffer + 1),@r0
      003AFC 08               [12]11384 	inc	r0
      003AFD 86 23            [24]11385 	mov	(_fuzzy_values_buffer + 2),@r0
      003AFF 08               [12]11386 	inc	r0
      003B00 86 24            [24]11387 	mov	(_fuzzy_values_buffer + 3),@r0
      003B02 E5 08            [12]11388 	mov	a,_bp
      003B04 24 0D            [12]11389 	add	a,#0x0d
      003B06 F8               [12]11390 	mov	r0,a
      003B07 86 25            [24]11391 	mov	((_fuzzy_values_buffer + 0x0004) + 0),@r0
      003B09 08               [12]11392 	inc	r0
      003B0A 86 26            [24]11393 	mov	((_fuzzy_values_buffer + 0x0004) + 1),@r0
      003B0C 08               [12]11394 	inc	r0
      003B0D 86 27            [24]11395 	mov	((_fuzzy_values_buffer + 0x0004) + 2),@r0
      003B0F 08               [12]11396 	inc	r0
      003B10 86 28            [24]11397 	mov	((_fuzzy_values_buffer + 0x0004) + 3),@r0
      003B12 74 21            [12]11398 	mov	a,#_fuzzy_values_buffer
      003B14 C0 E0            [24]11399 	push	acc
      003B16 74 00            [12]11400 	mov	a,#(_fuzzy_values_buffer >> 8)
      003B18 C0 E0            [24]11401 	push	acc
      003B1A 74 40            [12]11402 	mov	a,#0x40
      003B1C C0 E0            [24]11403 	push	acc
      003B1E 74 02            [12]11404 	mov	a,#0x02
      003B20 C0 E0            [24]11405 	push	acc
      003B22 E4               [12]11406 	clr	a
      003B23 C0 E0            [24]11407 	push	acc
      003B25 75 82 00         [24]11408 	mov	dpl, #0x00
      003B28 12 02 29         [24]11409 	lcall	_fuzzy_and_array
      003B2B C8               [12]11410 	xch	a,r0
      003B2C E5 08            [12]11411 	mov	a,_bp
      003B2E 24 25            [12]11412 	add	a,#0x25
      003B30 C8               [12]11413 	xch	a,r0
      003B31 A6 82            [24]11414 	mov	@r0, dpl
      003B33 08               [12]11415 	inc	r0
      003B34 A6 83            [24]11416 	mov	@r0, dph
      003B36 08               [12]11417 	inc	r0
      003B37 A6 F0            [24]11418 	mov	@r0, b
      003B39 08               [12]11419 	inc	r0
      003B3A F6               [12]11420 	mov	@r0,a
      003B3B E5 81            [12]11421 	mov	a,sp
      003B3D 24 FB            [12]11422 	add	a,#0xfb
      003B3F F5 81            [12]11423 	mov	sp,a
                           003A84 11424 	C$sugeno_demo.c$341$1_0$173 ==.
                                  11425 ;	../../sugeno_demo.c:341: fuzzy_and_method(
      003B41 12 00 BD         [24]11426 	lcall	_fuzzy_values_initialize
      003B44 E5 08            [12]11427 	mov	a,_bp
      003B46 24 0D            [12]11428 	add	a,#0x0d
      003B48 F8               [12]11429 	mov	r0,a
      003B49 86 21            [24]11430 	mov	(_fuzzy_values_buffer + 0),@r0
      003B4B 08               [12]11431 	inc	r0
      003B4C 86 22            [24]11432 	mov	(_fuzzy_values_buffer + 1),@r0
      003B4E 08               [12]11433 	inc	r0
      003B4F 86 23            [24]11434 	mov	(_fuzzy_values_buffer + 2),@r0
      003B51 08               [12]11435 	inc	r0
      003B52 86 24            [24]11436 	mov	(_fuzzy_values_buffer + 3),@r0
      003B54 E5 08            [12]11437 	mov	a,_bp
      003B56 24 15            [12]11438 	add	a,#0x15
      003B58 F8               [12]11439 	mov	r0,a
      003B59 86 82            [24]11440 	mov	dpl, @r0
      003B5B 08               [12]11441 	inc	r0
      003B5C 86 83            [24]11442 	mov	dph, @r0
      003B5E 08               [12]11443 	inc	r0
      003B5F 86 F0            [24]11444 	mov	b, @r0
      003B61 08               [12]11445 	inc	r0
      003B62 E6               [12]11446 	mov	a, @r0
      003B63 12 01 6D         [24]11447 	lcall	_fuzzy_not
      003B66 AA 82            [24]11448 	mov	r2, dpl
      003B68 AB 83            [24]11449 	mov	r3, dph
      003B6A AE F0            [24]11450 	mov	r6, b
      003B6C FF               [12]11451 	mov	r7, a
      003B6D 8A 25            [24]11452 	mov	((_fuzzy_values_buffer + 0x0004) + 0),r2
      003B6F 8B 26            [24]11453 	mov	((_fuzzy_values_buffer + 0x0004) + 1),r3
      003B71 8E 27            [24]11454 	mov	((_fuzzy_values_buffer + 0x0004) + 2),r6
      003B73 8F 28            [24]11455 	mov	((_fuzzy_values_buffer + 0x0004) + 3),r7
      003B75 74 21            [12]11456 	mov	a,#_fuzzy_values_buffer
      003B77 C0 E0            [24]11457 	push	acc
      003B79 74 00            [12]11458 	mov	a,#(_fuzzy_values_buffer >> 8)
      003B7B C0 E0            [24]11459 	push	acc
      003B7D 74 40            [12]11460 	mov	a,#0x40
      003B7F C0 E0            [24]11461 	push	acc
      003B81 74 02            [12]11462 	mov	a,#0x02
      003B83 C0 E0            [24]11463 	push	acc
      003B85 E4               [12]11464 	clr	a
      003B86 C0 E0            [24]11465 	push	acc
      003B88 75 82 00         [24]11466 	mov	dpl, #0x00
      003B8B 12 02 29         [24]11467 	lcall	_fuzzy_and_array
      003B8E C8               [12]11468 	xch	a,r0
      003B8F E5 08            [12]11469 	mov	a,_bp
      003B91 24 29            [12]11470 	add	a,#0x29
      003B93 C8               [12]11471 	xch	a,r0
      003B94 A6 82            [24]11472 	mov	@r0, dpl
      003B96 08               [12]11473 	inc	r0
      003B97 A6 83            [24]11474 	mov	@r0, dph
      003B99 08               [12]11475 	inc	r0
      003B9A A6 F0            [24]11476 	mov	@r0, b
      003B9C 08               [12]11477 	inc	r0
      003B9D F6               [12]11478 	mov	@r0,a
      003B9E E5 81            [12]11479 	mov	a,sp
      003BA0 24 FB            [12]11480 	add	a,#0xfb
      003BA2 F5 81            [12]11481 	mov	sp,a
                           003AE7 11482 	C$sugeno_demo.c$350$1_0$173 ==.
                                  11483 ;	../../sugeno_demo.c:350: fuzzy_and_method(
      003BA4 12 00 BD         [24]11484 	lcall	_fuzzy_values_initialize
      003BA7 E5 08            [12]11485 	mov	a,_bp
      003BA9 24 05            [12]11486 	add	a,#0x05
      003BAB F8               [12]11487 	mov	r0,a
      003BAC 86 21            [24]11488 	mov	(_fuzzy_values_buffer + 0),@r0
      003BAE 08               [12]11489 	inc	r0
      003BAF 86 22            [24]11490 	mov	(_fuzzy_values_buffer + 1),@r0
      003BB1 08               [12]11491 	inc	r0
      003BB2 86 23            [24]11492 	mov	(_fuzzy_values_buffer + 2),@r0
      003BB4 08               [12]11493 	inc	r0
      003BB5 86 24            [24]11494 	mov	(_fuzzy_values_buffer + 3),@r0
      003BB7 E5 08            [12]11495 	mov	a,_bp
      003BB9 24 15            [12]11496 	add	a,#0x15
      003BBB F8               [12]11497 	mov	r0,a
      003BBC 86 25            [24]11498 	mov	((_fuzzy_values_buffer + 0x0004) + 0),@r0
      003BBE 08               [12]11499 	inc	r0
      003BBF 86 26            [24]11500 	mov	((_fuzzy_values_buffer + 0x0004) + 1),@r0
      003BC1 08               [12]11501 	inc	r0
      003BC2 86 27            [24]11502 	mov	((_fuzzy_values_buffer + 0x0004) + 2),@r0
      003BC4 08               [12]11503 	inc	r0
      003BC5 86 28            [24]11504 	mov	((_fuzzy_values_buffer + 0x0004) + 3),@r0
      003BC7 74 21            [12]11505 	mov	a,#_fuzzy_values_buffer
      003BC9 C0 E0            [24]11506 	push	acc
      003BCB 74 00            [12]11507 	mov	a,#(_fuzzy_values_buffer >> 8)
      003BCD C0 E0            [24]11508 	push	acc
      003BCF 74 40            [12]11509 	mov	a,#0x40
      003BD1 C0 E0            [24]11510 	push	acc
      003BD3 74 02            [12]11511 	mov	a,#0x02
      003BD5 C0 E0            [24]11512 	push	acc
      003BD7 E4               [12]11513 	clr	a
      003BD8 C0 E0            [24]11514 	push	acc
      003BDA 75 82 00         [24]11515 	mov	dpl, #0x00
      003BDD 12 02 29         [24]11516 	lcall	_fuzzy_and_array
      003BE0 C8               [12]11517 	xch	a,r0
      003BE1 E5 08            [12]11518 	mov	a,_bp
      003BE3 24 31            [12]11519 	add	a,#0x31
      003BE5 C8               [12]11520 	xch	a,r0
      003BE6 A6 82            [24]11521 	mov	@r0, dpl
      003BE8 08               [12]11522 	inc	r0
      003BE9 A6 83            [24]11523 	mov	@r0, dph
      003BEB 08               [12]11524 	inc	r0
      003BEC A6 F0            [24]11525 	mov	@r0, b
      003BEE 08               [12]11526 	inc	r0
      003BEF F6               [12]11527 	mov	@r0,a
      003BF0 E5 81            [12]11528 	mov	a,sp
      003BF2 24 FB            [12]11529 	add	a,#0xfb
      003BF4 F5 81            [12]11530 	mov	sp,a
                           003B39 11531 	C$sugeno_demo.c$357$1_0$173 ==.
                                  11532 ;	../../sugeno_demo.c:357: fuzzy_and_method(
      003BF6 12 00 BD         [24]11533 	lcall	_fuzzy_values_initialize
      003BF9 E5 08            [12]11534 	mov	a,_bp
      003BFB 24 0D            [12]11535 	add	a,#0x0d
      003BFD F8               [12]11536 	mov	r0,a
      003BFE 86 21            [24]11537 	mov	(_fuzzy_values_buffer + 0),@r0
      003C00 08               [12]11538 	inc	r0
      003C01 86 22            [24]11539 	mov	(_fuzzy_values_buffer + 1),@r0
      003C03 08               [12]11540 	inc	r0
      003C04 86 23            [24]11541 	mov	(_fuzzy_values_buffer + 2),@r0
      003C06 08               [12]11542 	inc	r0
      003C07 86 24            [24]11543 	mov	(_fuzzy_values_buffer + 3),@r0
      003C09 E5 08            [12]11544 	mov	a,_bp
      003C0B 24 15            [12]11545 	add	a,#0x15
      003C0D F8               [12]11546 	mov	r0,a
      003C0E 86 25            [24]11547 	mov	((_fuzzy_values_buffer + 0x0004) + 0),@r0
      003C10 08               [12]11548 	inc	r0
      003C11 86 26            [24]11549 	mov	((_fuzzy_values_buffer + 0x0004) + 1),@r0
      003C13 08               [12]11550 	inc	r0
      003C14 86 27            [24]11551 	mov	((_fuzzy_values_buffer + 0x0004) + 2),@r0
      003C16 08               [12]11552 	inc	r0
      003C17 86 28            [24]11553 	mov	((_fuzzy_values_buffer + 0x0004) + 3),@r0
      003C19 74 21            [12]11554 	mov	a,#_fuzzy_values_buffer
      003C1B C0 E0            [24]11555 	push	acc
      003C1D 74 00            [12]11556 	mov	a,#(_fuzzy_values_buffer >> 8)
      003C1F C0 E0            [24]11557 	push	acc
      003C21 74 40            [12]11558 	mov	a,#0x40
      003C23 C0 E0            [24]11559 	push	acc
      003C25 74 02            [12]11560 	mov	a,#0x02
      003C27 C0 E0            [24]11561 	push	acc
      003C29 E4               [12]11562 	clr	a
      003C2A C0 E0            [24]11563 	push	acc
      003C2C 75 82 00         [24]11564 	mov	dpl, #0x00
      003C2F 12 02 29         [24]11565 	lcall	_fuzzy_and_array
      003C32 AC 82            [24]11566 	mov	r4, dpl
      003C34 AD 83            [24]11567 	mov	r5, dph
      003C36 AE F0            [24]11568 	mov	r6, b
      003C38 FF               [12]11569 	mov	r7, a
      003C39 E5 81            [12]11570 	mov	a,sp
      003C3B 24 FB            [12]11571 	add	a,#0xfb
      003C3D F5 81            [12]11572 	mov	sp,a
                           003B82 11573 	C$sugeno_demo.c$364$1_0$173 ==.
                                  11574 ;	../../sugeno_demo.c:364: fuzzy_or_method(
      003C3F C0 07            [24]11575 	push	ar7
      003C41 C0 06            [24]11576 	push	ar6
      003C43 C0 05            [24]11577 	push	ar5
      003C45 C0 04            [24]11578 	push	ar4
      003C47 12 00 BD         [24]11579 	lcall	_fuzzy_values_initialize
      003C4A D0 04            [24]11580 	pop	ar4
      003C4C D0 05            [24]11581 	pop	ar5
      003C4E D0 06            [24]11582 	pop	ar6
      003C50 D0 07            [24]11583 	pop	ar7
      003C52 E5 08            [12]11584 	mov	a,_bp
      003C54 24 31            [12]11585 	add	a,#0x31
      003C56 F8               [12]11586 	mov	r0,a
      003C57 86 21            [24]11587 	mov	(_fuzzy_values_buffer + 0),@r0
      003C59 08               [12]11588 	inc	r0
      003C5A 86 22            [24]11589 	mov	(_fuzzy_values_buffer + 1),@r0
      003C5C 08               [12]11590 	inc	r0
      003C5D 86 23            [24]11591 	mov	(_fuzzy_values_buffer + 2),@r0
      003C5F 08               [12]11592 	inc	r0
      003C60 86 24            [24]11593 	mov	(_fuzzy_values_buffer + 3),@r0
      003C62 8C 25            [24]11594 	mov	((_fuzzy_values_buffer + 0x0004) + 0),r4
      003C64 8D 26            [24]11595 	mov	((_fuzzy_values_buffer + 0x0004) + 1),r5
      003C66 8E 27            [24]11596 	mov	((_fuzzy_values_buffer + 0x0004) + 2),r6
      003C68 8F 28            [24]11597 	mov	((_fuzzy_values_buffer + 0x0004) + 3),r7
      003C6A 74 21            [12]11598 	mov	a,#_fuzzy_values_buffer
      003C6C C0 E0            [24]11599 	push	acc
      003C6E 74 00            [12]11600 	mov	a,#(_fuzzy_values_buffer >> 8)
      003C70 C0 E0            [24]11601 	push	acc
      003C72 74 40            [12]11602 	mov	a,#0x40
      003C74 C0 E0            [24]11603 	push	acc
      003C76 74 02            [12]11604 	mov	a,#0x02
      003C78 C0 E0            [24]11605 	push	acc
      003C7A E4               [12]11606 	clr	a
      003C7B C0 E0            [24]11607 	push	acc
      003C7D 75 82 00         [24]11608 	mov	dpl, #0x00
      003C80 12 04 C8         [24]11609 	lcall	_fuzzy_or_array
      003C83 C8               [12]11610 	xch	a,r0
      003C84 E5 08            [12]11611 	mov	a,_bp
      003C86 24 2D            [12]11612 	add	a,#0x2d
      003C88 C8               [12]11613 	xch	a,r0
      003C89 A6 82            [24]11614 	mov	@r0, dpl
      003C8B 08               [12]11615 	inc	r0
      003C8C A6 83            [24]11616 	mov	@r0, dph
      003C8E 08               [12]11617 	inc	r0
      003C8F A6 F0            [24]11618 	mov	@r0, b
      003C91 08               [12]11619 	inc	r0
      003C92 F6               [12]11620 	mov	@r0,a
      003C93 E5 81            [12]11621 	mov	a,sp
      003C95 24 FB            [12]11622 	add	a,#0xfb
      003C97 F5 81            [12]11623 	mov	sp,a
                           003BDC 11624 	C$sugeno_demo.c$370$1_0$173 ==.
                                  11625 ;	../../sugeno_demo.c:370: return fuzzy_sugeno_weighted_average(
      003C99 12 00 BD         [24]11626 	lcall	_fuzzy_values_initialize
      003C9C E5 08            [12]11627 	mov	a,_bp
      003C9E 24 19            [12]11628 	add	a,#0x19
      003CA0 F8               [12]11629 	mov	r0,a
      003CA1 86 21            [24]11630 	mov	(_fuzzy_values_buffer + 0),@r0
      003CA3 08               [12]11631 	inc	r0
      003CA4 86 22            [24]11632 	mov	(_fuzzy_values_buffer + 1),@r0
      003CA6 08               [12]11633 	inc	r0
      003CA7 86 23            [24]11634 	mov	(_fuzzy_values_buffer + 2),@r0
      003CA9 08               [12]11635 	inc	r0
      003CAA 86 24            [24]11636 	mov	(_fuzzy_values_buffer + 3),@r0
      003CAC E5 08            [12]11637 	mov	a,_bp
      003CAE 24 F6            [12]11638 	add	a,#0xf6
      003CB0 F8               [12]11639 	mov	r0,a
      003CB1 E6               [12]11640 	mov	a,@r0
      003CB2 C0 E0            [24]11641 	push	acc
      003CB4 08               [12]11642 	inc	r0
      003CB5 E6               [12]11643 	mov	a,@r0
      003CB6 C0 E0            [24]11644 	push	acc
      003CB8 08               [12]11645 	inc	r0
      003CB9 E6               [12]11646 	mov	a,@r0
      003CBA C0 E0            [24]11647 	push	acc
      003CBC 08               [12]11648 	inc	r0
      003CBD E6               [12]11649 	mov	a,@r0
      003CBE C0 E0            [24]11650 	push	acc
      003CC0 E5 08            [12]11651 	mov	a,_bp
      003CC2 24 FA            [12]11652 	add	a,#0xfa
      003CC4 F8               [12]11653 	mov	r0,a
      003CC5 E6               [12]11654 	mov	a,@r0
      003CC6 C0 E0            [24]11655 	push	acc
      003CC8 08               [12]11656 	inc	r0
      003CC9 E6               [12]11657 	mov	a,@r0
      003CCA C0 E0            [24]11658 	push	acc
      003CCC 08               [12]11659 	inc	r0
      003CCD E6               [12]11660 	mov	a,@r0
      003CCE C0 E0            [24]11661 	push	acc
      003CD0 08               [12]11662 	inc	r0
      003CD1 E6               [12]11663 	mov	a,@r0
      003CD2 C0 E0            [24]11664 	push	acc
      003CD4 A8 08            [24]11665 	mov	r0,_bp
      003CD6 08               [12]11666 	inc	r0
      003CD7 86 82            [24]11667 	mov	dpl, @r0
      003CD9 08               [12]11668 	inc	r0
      003CDA 86 83            [24]11669 	mov	dph, @r0
      003CDC 08               [12]11670 	inc	r0
      003CDD 86 F0            [24]11671 	mov	b, @r0
      003CDF 08               [12]11672 	inc	r0
      003CE0 E6               [12]11673 	mov	a, @r0
      003CE1 12 32 C8         [24]11674 	lcall	_response_idle
      003CE4 AA 82            [24]11675 	mov	r2, dpl
      003CE6 AB 83            [24]11676 	mov	r3, dph
      003CE8 AE F0            [24]11677 	mov	r6, b
      003CEA FF               [12]11678 	mov	r7, a
      003CEB E5 81            [12]11679 	mov	a,sp
      003CED 24 F8            [12]11680 	add	a,#0xf8
      003CEF F5 81            [12]11681 	mov	sp,a
      003CF1 8A 25            [24]11682 	mov	((_fuzzy_values_buffer + 0x0004) + 0),r2
      003CF3 8B 26            [24]11683 	mov	((_fuzzy_values_buffer + 0x0004) + 1),r3
      003CF5 8E 27            [24]11684 	mov	((_fuzzy_values_buffer + 0x0004) + 2),r6
      003CF7 8F 28            [24]11685 	mov	((_fuzzy_values_buffer + 0x0004) + 3),r7
      003CF9 E5 08            [12]11686 	mov	a,_bp
      003CFB 24 1D            [12]11687 	add	a,#0x1d
      003CFD F8               [12]11688 	mov	r0,a
      003CFE 86 29            [24]11689 	mov	((_fuzzy_values_buffer + 0x0008) + 0),@r0
      003D00 08               [12]11690 	inc	r0
      003D01 86 2A            [24]11691 	mov	((_fuzzy_values_buffer + 0x0008) + 1),@r0
      003D03 08               [12]11692 	inc	r0
      003D04 86 2B            [24]11693 	mov	((_fuzzy_values_buffer + 0x0008) + 2),@r0
      003D06 08               [12]11694 	inc	r0
      003D07 86 2C            [24]11695 	mov	((_fuzzy_values_buffer + 0x0008) + 3),@r0
      003D09 E5 08            [12]11696 	mov	a,_bp
      003D0B 24 F6            [12]11697 	add	a,#0xf6
      003D0D F8               [12]11698 	mov	r0,a
      003D0E E6               [12]11699 	mov	a,@r0
      003D0F C0 E0            [24]11700 	push	acc
      003D11 08               [12]11701 	inc	r0
      003D12 E6               [12]11702 	mov	a,@r0
      003D13 C0 E0            [24]11703 	push	acc
      003D15 08               [12]11704 	inc	r0
      003D16 E6               [12]11705 	mov	a,@r0
      003D17 C0 E0            [24]11706 	push	acc
      003D19 08               [12]11707 	inc	r0
      003D1A E6               [12]11708 	mov	a,@r0
      003D1B C0 E0            [24]11709 	push	acc
      003D1D E5 08            [12]11710 	mov	a,_bp
      003D1F 24 FA            [12]11711 	add	a,#0xfa
      003D21 F8               [12]11712 	mov	r0,a
      003D22 E6               [12]11713 	mov	a,@r0
      003D23 C0 E0            [24]11714 	push	acc
      003D25 08               [12]11715 	inc	r0
      003D26 E6               [12]11716 	mov	a,@r0
      003D27 C0 E0            [24]11717 	push	acc
      003D29 08               [12]11718 	inc	r0
      003D2A E6               [12]11719 	mov	a,@r0
      003D2B C0 E0            [24]11720 	push	acc
      003D2D 08               [12]11721 	inc	r0
      003D2E E6               [12]11722 	mov	a,@r0
      003D2F C0 E0            [24]11723 	push	acc
      003D31 A8 08            [24]11724 	mov	r0,_bp
      003D33 08               [12]11725 	inc	r0
      003D34 86 82            [24]11726 	mov	dpl, @r0
      003D36 08               [12]11727 	inc	r0
      003D37 86 83            [24]11728 	mov	dph, @r0
      003D39 08               [12]11729 	inc	r0
      003D3A 86 F0            [24]11730 	mov	b, @r0
      003D3C 08               [12]11731 	inc	r0
      003D3D E6               [12]11732 	mov	a, @r0
      003D3E 12 33 D7         [24]11733 	lcall	_response_economy
      003D41 AC 82            [24]11734 	mov	r4, dpl
      003D43 AD 83            [24]11735 	mov	r5, dph
      003D45 AE F0            [24]11736 	mov	r6, b
      003D47 FF               [12]11737 	mov	r7, a
      003D48 E5 81            [12]11738 	mov	a,sp
      003D4A 24 F8            [12]11739 	add	a,#0xf8
      003D4C F5 81            [12]11740 	mov	sp,a
      003D4E 8C 2D            [24]11741 	mov	((_fuzzy_values_buffer + 0x000c) + 0),r4
      003D50 8D 2E            [24]11742 	mov	((_fuzzy_values_buffer + 0x000c) + 1),r5
      003D52 8E 2F            [24]11743 	mov	((_fuzzy_values_buffer + 0x000c) + 2),r6
      003D54 8F 30            [24]11744 	mov	((_fuzzy_values_buffer + 0x000c) + 3),r7
      003D56 E5 08            [12]11745 	mov	a,_bp
      003D58 24 21            [12]11746 	add	a,#0x21
      003D5A F8               [12]11747 	mov	r0,a
      003D5B 86 31            [24]11748 	mov	((_fuzzy_values_buffer + 0x0010) + 0),@r0
      003D5D 08               [12]11749 	inc	r0
      003D5E 86 32            [24]11750 	mov	((_fuzzy_values_buffer + 0x0010) + 1),@r0
      003D60 08               [12]11751 	inc	r0
      003D61 86 33            [24]11752 	mov	((_fuzzy_values_buffer + 0x0010) + 2),@r0
      003D63 08               [12]11753 	inc	r0
      003D64 86 34            [24]11754 	mov	((_fuzzy_values_buffer + 0x0010) + 3),@r0
      003D66 E5 08            [12]11755 	mov	a,_bp
      003D68 24 F6            [12]11756 	add	a,#0xf6
      003D6A F8               [12]11757 	mov	r0,a
      003D6B E6               [12]11758 	mov	a,@r0
      003D6C C0 E0            [24]11759 	push	acc
      003D6E 08               [12]11760 	inc	r0
      003D6F E6               [12]11761 	mov	a,@r0
      003D70 C0 E0            [24]11762 	push	acc
      003D72 08               [12]11763 	inc	r0
      003D73 E6               [12]11764 	mov	a,@r0
      003D74 C0 E0            [24]11765 	push	acc
      003D76 08               [12]11766 	inc	r0
      003D77 E6               [12]11767 	mov	a,@r0
      003D78 C0 E0            [24]11768 	push	acc
      003D7A E5 08            [12]11769 	mov	a,_bp
      003D7C 24 FA            [12]11770 	add	a,#0xfa
      003D7E F8               [12]11771 	mov	r0,a
      003D7F E6               [12]11772 	mov	a,@r0
      003D80 C0 E0            [24]11773 	push	acc
      003D82 08               [12]11774 	inc	r0
      003D83 E6               [12]11775 	mov	a,@r0
      003D84 C0 E0            [24]11776 	push	acc
      003D86 08               [12]11777 	inc	r0
      003D87 E6               [12]11778 	mov	a,@r0
      003D88 C0 E0            [24]11779 	push	acc
      003D8A 08               [12]11780 	inc	r0
      003D8B E6               [12]11781 	mov	a,@r0
      003D8C C0 E0            [24]11782 	push	acc
      003D8E A8 08            [24]11783 	mov	r0,_bp
      003D90 08               [12]11784 	inc	r0
      003D91 86 82            [24]11785 	mov	dpl, @r0
      003D93 08               [12]11786 	inc	r0
      003D94 86 83            [24]11787 	mov	dph, @r0
      003D96 08               [12]11788 	inc	r0
      003D97 86 F0            [24]11789 	mov	b, @r0
      003D99 08               [12]11790 	inc	r0
      003D9A E6               [12]11791 	mov	a, @r0
      003D9B 12 34 E7         [24]11792 	lcall	_response_balanced
      003D9E AC 82            [24]11793 	mov	r4, dpl
      003DA0 AD 83            [24]11794 	mov	r5, dph
      003DA2 AE F0            [24]11795 	mov	r6, b
      003DA4 FF               [12]11796 	mov	r7, a
      003DA5 E5 81            [12]11797 	mov	a,sp
      003DA7 24 F8            [12]11798 	add	a,#0xf8
      003DA9 F5 81            [12]11799 	mov	sp,a
      003DAB 8C 35            [24]11800 	mov	((_fuzzy_values_buffer + 0x0014) + 0),r4
      003DAD 8D 36            [24]11801 	mov	((_fuzzy_values_buffer + 0x0014) + 1),r5
      003DAF 8E 37            [24]11802 	mov	((_fuzzy_values_buffer + 0x0014) + 2),r6
      003DB1 8F 38            [24]11803 	mov	((_fuzzy_values_buffer + 0x0014) + 3),r7
      003DB3 E5 08            [12]11804 	mov	a,_bp
      003DB5 24 25            [12]11805 	add	a,#0x25
      003DB7 F8               [12]11806 	mov	r0,a
      003DB8 86 39            [24]11807 	mov	((_fuzzy_values_buffer + 0x0018) + 0),@r0
      003DBA 08               [12]11808 	inc	r0
      003DBB 86 3A            [24]11809 	mov	((_fuzzy_values_buffer + 0x0018) + 1),@r0
      003DBD 08               [12]11810 	inc	r0
      003DBE 86 3B            [24]11811 	mov	((_fuzzy_values_buffer + 0x0018) + 2),@r0
      003DC0 08               [12]11812 	inc	r0
      003DC1 86 3C            [24]11813 	mov	((_fuzzy_values_buffer + 0x0018) + 3),@r0
      003DC3 E5 08            [12]11814 	mov	a,_bp
      003DC5 24 F6            [12]11815 	add	a,#0xf6
      003DC7 F8               [12]11816 	mov	r0,a
      003DC8 E6               [12]11817 	mov	a,@r0
      003DC9 C0 E0            [24]11818 	push	acc
      003DCB 08               [12]11819 	inc	r0
      003DCC E6               [12]11820 	mov	a,@r0
      003DCD C0 E0            [24]11821 	push	acc
      003DCF 08               [12]11822 	inc	r0
      003DD0 E6               [12]11823 	mov	a,@r0
      003DD1 C0 E0            [24]11824 	push	acc
      003DD3 08               [12]11825 	inc	r0
      003DD4 E6               [12]11826 	mov	a,@r0
      003DD5 C0 E0            [24]11827 	push	acc
      003DD7 E5 08            [12]11828 	mov	a,_bp
      003DD9 24 FA            [12]11829 	add	a,#0xfa
      003DDB F8               [12]11830 	mov	r0,a
      003DDC E6               [12]11831 	mov	a,@r0
      003DDD C0 E0            [24]11832 	push	acc
      003DDF 08               [12]11833 	inc	r0
      003DE0 E6               [12]11834 	mov	a,@r0
      003DE1 C0 E0            [24]11835 	push	acc
      003DE3 08               [12]11836 	inc	r0
      003DE4 E6               [12]11837 	mov	a,@r0
      003DE5 C0 E0            [24]11838 	push	acc
      003DE7 08               [12]11839 	inc	r0
      003DE8 E6               [12]11840 	mov	a,@r0
      003DE9 C0 E0            [24]11841 	push	acc
      003DEB A8 08            [24]11842 	mov	r0,_bp
      003DED 08               [12]11843 	inc	r0
      003DEE 86 82            [24]11844 	mov	dpl, @r0
      003DF0 08               [12]11845 	inc	r0
      003DF1 86 83            [24]11846 	mov	dph, @r0
      003DF3 08               [12]11847 	inc	r0
      003DF4 86 F0            [24]11848 	mov	b, @r0
      003DF6 08               [12]11849 	inc	r0
      003DF7 E6               [12]11850 	mov	a, @r0
      003DF8 12 35 F8         [24]11851 	lcall	_response_cooling
      003DFB AC 82            [24]11852 	mov	r4, dpl
      003DFD AD 83            [24]11853 	mov	r5, dph
      003DFF AE F0            [24]11854 	mov	r6, b
      003E01 FF               [12]11855 	mov	r7, a
      003E02 E5 81            [12]11856 	mov	a,sp
      003E04 24 F8            [12]11857 	add	a,#0xf8
      003E06 F5 81            [12]11858 	mov	sp,a
      003E08 8C 3D            [24]11859 	mov	((_fuzzy_values_buffer + 0x001c) + 0),r4
      003E0A 8D 3E            [24]11860 	mov	((_fuzzy_values_buffer + 0x001c) + 1),r5
      003E0C 8E 3F            [24]11861 	mov	((_fuzzy_values_buffer + 0x001c) + 2),r6
      003E0E 8F 40            [24]11862 	mov	((_fuzzy_values_buffer + 0x001c) + 3),r7
      003E10 E5 08            [12]11863 	mov	a,_bp
      003E12 24 29            [12]11864 	add	a,#0x29
      003E14 F8               [12]11865 	mov	r0,a
      003E15 86 41            [24]11866 	mov	((_fuzzy_values_buffer + 0x0020) + 0),@r0
      003E17 08               [12]11867 	inc	r0
      003E18 86 42            [24]11868 	mov	((_fuzzy_values_buffer + 0x0020) + 1),@r0
      003E1A 08               [12]11869 	inc	r0
      003E1B 86 43            [24]11870 	mov	((_fuzzy_values_buffer + 0x0020) + 2),@r0
      003E1D 08               [12]11871 	inc	r0
      003E1E 86 44            [24]11872 	mov	((_fuzzy_values_buffer + 0x0020) + 3),@r0
      003E20 E5 08            [12]11873 	mov	a,_bp
      003E22 24 F6            [12]11874 	add	a,#0xf6
      003E24 F8               [12]11875 	mov	r0,a
      003E25 E6               [12]11876 	mov	a,@r0
      003E26 C0 E0            [24]11877 	push	acc
      003E28 08               [12]11878 	inc	r0
      003E29 E6               [12]11879 	mov	a,@r0
      003E2A C0 E0            [24]11880 	push	acc
      003E2C 08               [12]11881 	inc	r0
      003E2D E6               [12]11882 	mov	a,@r0
      003E2E C0 E0            [24]11883 	push	acc
      003E30 08               [12]11884 	inc	r0
      003E31 E6               [12]11885 	mov	a,@r0
      003E32 C0 E0            [24]11886 	push	acc
      003E34 E5 08            [12]11887 	mov	a,_bp
      003E36 24 FA            [12]11888 	add	a,#0xfa
      003E38 F8               [12]11889 	mov	r0,a
      003E39 E6               [12]11890 	mov	a,@r0
      003E3A C0 E0            [24]11891 	push	acc
      003E3C 08               [12]11892 	inc	r0
      003E3D E6               [12]11893 	mov	a,@r0
      003E3E C0 E0            [24]11894 	push	acc
      003E40 08               [12]11895 	inc	r0
      003E41 E6               [12]11896 	mov	a,@r0
      003E42 C0 E0            [24]11897 	push	acc
      003E44 08               [12]11898 	inc	r0
      003E45 E6               [12]11899 	mov	a,@r0
      003E46 C0 E0            [24]11900 	push	acc
      003E48 A8 08            [24]11901 	mov	r0,_bp
      003E4A 08               [12]11902 	inc	r0
      003E4B 86 82            [24]11903 	mov	dpl, @r0
      003E4D 08               [12]11904 	inc	r0
      003E4E 86 83            [24]11905 	mov	dph, @r0
      003E50 08               [12]11906 	inc	r0
      003E51 86 F0            [24]11907 	mov	b, @r0
      003E53 08               [12]11908 	inc	r0
      003E54 E6               [12]11909 	mov	a, @r0
      003E55 12 37 08         [24]11910 	lcall	_response_heavy_load
      003E58 AC 82            [24]11911 	mov	r4, dpl
      003E5A AD 83            [24]11912 	mov	r5, dph
      003E5C AE F0            [24]11913 	mov	r6, b
      003E5E FF               [12]11914 	mov	r7, a
      003E5F E5 81            [12]11915 	mov	a,sp
      003E61 24 F8            [12]11916 	add	a,#0xf8
      003E63 F5 81            [12]11917 	mov	sp,a
      003E65 8C 45            [24]11918 	mov	((_fuzzy_values_buffer + 0x0024) + 0),r4
      003E67 8D 46            [24]11919 	mov	((_fuzzy_values_buffer + 0x0024) + 1),r5
      003E69 8E 47            [24]11920 	mov	((_fuzzy_values_buffer + 0x0024) + 2),r6
      003E6B 8F 48            [24]11921 	mov	((_fuzzy_values_buffer + 0x0024) + 3),r7
      003E6D E5 08            [12]11922 	mov	a,_bp
      003E6F 24 2D            [12]11923 	add	a,#0x2d
      003E71 F8               [12]11924 	mov	r0,a
      003E72 86 49            [24]11925 	mov	((_fuzzy_values_buffer + 0x0028) + 0),@r0
      003E74 08               [12]11926 	inc	r0
      003E75 86 4A            [24]11927 	mov	((_fuzzy_values_buffer + 0x0028) + 1),@r0
      003E77 08               [12]11928 	inc	r0
      003E78 86 4B            [24]11929 	mov	((_fuzzy_values_buffer + 0x0028) + 2),@r0
      003E7A 08               [12]11930 	inc	r0
      003E7B 86 4C            [24]11931 	mov	((_fuzzy_values_buffer + 0x0028) + 3),@r0
      003E7D E5 08            [12]11932 	mov	a,_bp
      003E7F 24 F6            [12]11933 	add	a,#0xf6
      003E81 F8               [12]11934 	mov	r0,a
      003E82 E6               [12]11935 	mov	a,@r0
      003E83 C0 E0            [24]11936 	push	acc
      003E85 08               [12]11937 	inc	r0
      003E86 E6               [12]11938 	mov	a,@r0
      003E87 C0 E0            [24]11939 	push	acc
      003E89 08               [12]11940 	inc	r0
      003E8A E6               [12]11941 	mov	a,@r0
      003E8B C0 E0            [24]11942 	push	acc
      003E8D 08               [12]11943 	inc	r0
      003E8E E6               [12]11944 	mov	a,@r0
      003E8F C0 E0            [24]11945 	push	acc
      003E91 E5 08            [12]11946 	mov	a,_bp
      003E93 24 FA            [12]11947 	add	a,#0xfa
      003E95 F8               [12]11948 	mov	r0,a
      003E96 E6               [12]11949 	mov	a,@r0
      003E97 C0 E0            [24]11950 	push	acc
      003E99 08               [12]11951 	inc	r0
      003E9A E6               [12]11952 	mov	a,@r0
      003E9B C0 E0            [24]11953 	push	acc
      003E9D 08               [12]11954 	inc	r0
      003E9E E6               [12]11955 	mov	a,@r0
      003E9F C0 E0            [24]11956 	push	acc
      003EA1 08               [12]11957 	inc	r0
      003EA2 E6               [12]11958 	mov	a,@r0
      003EA3 C0 E0            [24]11959 	push	acc
      003EA5 A8 08            [24]11960 	mov	r0,_bp
      003EA7 08               [12]11961 	inc	r0
      003EA8 86 82            [24]11962 	mov	dpl, @r0
      003EAA 08               [12]11963 	inc	r0
      003EAB 86 83            [24]11964 	mov	dph, @r0
      003EAD 08               [12]11965 	inc	r0
      003EAE 86 F0            [24]11966 	mov	b, @r0
      003EB0 08               [12]11967 	inc	r0
      003EB1 E6               [12]11968 	mov	a, @r0
      003EB2 12 37 ED         [24]11969 	lcall	_response_protection
      003EB5 AC 82            [24]11970 	mov	r4, dpl
      003EB7 AD 83            [24]11971 	mov	r5, dph
      003EB9 AE F0            [24]11972 	mov	r6, b
      003EBB FF               [12]11973 	mov	r7, a
      003EBC E5 81            [12]11974 	mov	a,sp
      003EBE 24 F8            [12]11975 	add	a,#0xf8
      003EC0 F5 81            [12]11976 	mov	sp,a
      003EC2 8C 4D            [24]11977 	mov	((_fuzzy_values_buffer + 0x002c) + 0),r4
      003EC4 8D 4E            [24]11978 	mov	((_fuzzy_values_buffer + 0x002c) + 1),r5
      003EC6 8E 4F            [24]11979 	mov	((_fuzzy_values_buffer + 0x002c) + 2),r6
      003EC8 8F 50            [24]11980 	mov	((_fuzzy_values_buffer + 0x002c) + 3),r7
      003ECA 74 21            [12]11981 	mov	a,#_fuzzy_values_buffer
      003ECC C0 E0            [24]11982 	push	acc
      003ECE 74 00            [12]11983 	mov	a,#(_fuzzy_values_buffer >> 8)
      003ED0 C0 E0            [24]11984 	push	acc
      003ED2 74 40            [12]11985 	mov	a,#0x40
      003ED4 C0 E0            [24]11986 	push	acc
      003ED6 90 00 0C         [24]11987 	mov	dptr,#0x000c
      003ED9 12 07 8A         [24]11988 	lcall	_fuzzy_sugeno_weighted_average_array
      003EDC AC 82            [24]11989 	mov	r4, dpl
      003EDE AD 83            [24]11990 	mov	r5, dph
      003EE0 AE F0            [24]11991 	mov	r6, b
      003EE2 FF               [12]11992 	mov	r7, a
      003EE3 15 81            [12]11993 	dec	sp
      003EE5 15 81            [12]11994 	dec	sp
      003EE7 15 81            [12]11995 	dec	sp
      003EE9 8C 82            [24]11996 	mov	dpl, r4
      003EEB 8D 83            [24]11997 	mov	dph, r5
      003EED 8E F0            [24]11998 	mov	b, r6
      003EEF EF               [12]11999 	mov	a, r7
                           003E33 12000 	C$sugeno_demo.c$413$1_0$173 ==.
                                  12001 ;	../../sugeno_demo.c:413: }
      003EF0 85 08 81         [24]12002 	mov	sp,_bp
      003EF3 D0 08            [24]12003 	pop	_bp
                           003E38 12004 	C$sugeno_demo.c$413$1_0$173 ==.
                           003E38 12005 	XFsugeno_demo$calculate_fan_speed$0$0 ==.
      003EF5 22               [24]12006 	ret
                                  12007 ;------------------------------------------------------------
                                  12008 ;Allocation info for local variables in function 'fan_speed_to_pwm'
                                  12009 ;------------------------------------------------------------
                                  12010 ;fan_speed     Allocated to registers r4 r5 r6 r7 
                                  12011 ;------------------------------------------------------------
                           003E39 12012 	Fsugeno_demo$fan_speed_to_pwm$0$0 ==.
                           003E39 12013 	C$sugeno_demo.c$420$1_0$175 ==.
                                  12014 ;	../../sugeno_demo.c:420: static unsigned char fan_speed_to_pwm(float fan_speed)
                                  12015 ;	-----------------------------------------
                                  12016 ;	 function fan_speed_to_pwm
                                  12017 ;	-----------------------------------------
      003EF6                      12018 _fan_speed_to_pwm:
      003EF6 AC 82            [24]12019 	mov	r4,dpl
      003EF8 AD 83            [24]12020 	mov	r5,dph
      003EFA AE F0            [24]12021 	mov	r6,b
      003EFC FF               [12]12022 	mov	r7,a
                           003E40 12023 	C$sugeno_demo.c$422$1_0$175 ==.
                                  12024 ;	../../sugeno_demo.c:422: if (fan_speed <= 0.0f) {
      003EFD C0 07            [24]12025 	push	ar7
      003EFF C0 06            [24]12026 	push	ar6
      003F01 C0 05            [24]12027 	push	ar5
      003F03 C0 04            [24]12028 	push	ar4
      003F05 C0 04            [24]12029 	push	ar4
      003F07 C0 05            [24]12030 	push	ar5
      003F09 C0 06            [24]12031 	push	ar6
      003F0B C0 07            [24]12032 	push	ar7
      003F0D 90 00 00         [24]12033 	mov	dptr,#0x0000
      003F10 E4               [12]12034 	clr	a
      003F11 F5 F0            [12]12035 	mov	b,a
      003F13 12 41 7C         [24]12036 	lcall	___fslt
      003F16 E5 81            [12]12037 	mov	a,sp
      003F18 24 FC            [12]12038 	add	a,#0xfc
      003F1A F5 81            [12]12039 	mov	sp,a
      003F1C D0 04            [24]12040 	pop	ar4
      003F1E D0 05            [24]12041 	pop	ar5
      003F20 D0 06            [24]12042 	pop	ar6
      003F22 D0 07            [24]12043 	pop	ar7
      003F24 E5 82            [12]12044 	mov	a, dpl
      003F26 24 FF            [12]12045 	add	a,#0xff
      003F28 92 00            [24]12046 	mov	b0,c
      003F2A 40 05            [24]12047 	jc	00102$
                           003E6F 12048 	C$sugeno_demo.c$423$2_0$176 ==.
                                  12049 ;	../../sugeno_demo.c:423: return 0u;
      003F2C 75 82 00         [24]12050 	mov	dpl, #0x00
      003F2F 80 66            [24]12051 	sjmp	00105$
      003F31                      12052 00102$:
                           003E74 12053 	C$sugeno_demo.c$426$1_0$175 ==.
                                  12054 ;	../../sugeno_demo.c:426: if (fan_speed >= 100.0f) {
      003F31 C0 07            [24]12055 	push	ar7
      003F33 C0 06            [24]12056 	push	ar6
      003F35 C0 05            [24]12057 	push	ar5
      003F37 C0 04            [24]12058 	push	ar4
      003F39 E4               [12]12059 	clr	a
      003F3A C0 E0            [24]12060 	push	acc
      003F3C C0 E0            [24]12061 	push	acc
      003F3E 74 C8            [12]12062 	mov	a,#0xc8
      003F40 C0 E0            [24]12063 	push	acc
      003F42 74 42            [12]12064 	mov	a,#0x42
      003F44 C0 E0            [24]12065 	push	acc
      003F46 8C 82            [24]12066 	mov	dpl, r4
      003F48 8D 83            [24]12067 	mov	dph, r5
      003F4A 8E F0            [24]12068 	mov	b, r6
      003F4C EF               [12]12069 	mov	a, r7
      003F4D 12 41 7C         [24]12070 	lcall	___fslt
      003F50 E5 81            [12]12071 	mov	a,sp
      003F52 24 FC            [12]12072 	add	a,#0xfc
      003F54 F5 81            [12]12073 	mov	sp,a
      003F56 D0 04            [24]12074 	pop	ar4
      003F58 D0 05            [24]12075 	pop	ar5
      003F5A D0 06            [24]12076 	pop	ar6
      003F5C D0 07            [24]12077 	pop	ar7
      003F5E E5 82            [12]12078 	mov	a, dpl
      003F60 24 FF            [12]12079 	add	a,#0xff
      003F62 92 00            [24]12080 	mov	b0,c
      003F64 40 05            [24]12081 	jc	00104$
                           003EA9 12082 	C$sugeno_demo.c$427$2_0$177 ==.
                                  12083 ;	../../sugeno_demo.c:427: return 100u;
      003F66 75 82 64         [24]12084 	mov	dpl, #0x64
      003F69 80 2C            [24]12085 	sjmp	00105$
      003F6B                      12086 00104$:
                           003EAE 12087 	C$sugeno_demo.c$432$1_0$175 ==.
                                  12088 ;	../../sugeno_demo.c:432: );
      003F6B E4               [12]12089 	clr	a
      003F6C C0 E0            [24]12090 	push	acc
      003F6E C0 E0            [24]12091 	push	acc
      003F70 C0 E0            [24]12092 	push	acc
      003F72 74 3F            [12]12093 	mov	a,#0x3f
      003F74 C0 E0            [24]12094 	push	acc
      003F76 8C 82            [24]12095 	mov	dpl, r4
      003F78 8D 83            [24]12096 	mov	dph, r5
      003F7A 8E F0            [24]12097 	mov	b, r6
      003F7C EF               [12]12098 	mov	a, r7
      003F7D 12 41 CE         [24]12099 	lcall	___fsadd
      003F80 AC 82            [24]12100 	mov	r4, dpl
      003F82 AD 83            [24]12101 	mov	r5, dph
      003F84 AE F0            [24]12102 	mov	r6, b
      003F86 FF               [12]12103 	mov	r7, a
      003F87 E5 81            [12]12104 	mov	a,sp
      003F89 24 FC            [12]12105 	add	a,#0xfc
      003F8B F5 81            [12]12106 	mov	sp,a
      003F8D 8C 82            [24]12107 	mov	dpl, r4
      003F8F 8D 83            [24]12108 	mov	dph, r5
      003F91 8E F0            [24]12109 	mov	b, r6
      003F93 EF               [12]12110 	mov	a, r7
      003F94 12 43 C4         [24]12111 	lcall	___fs2uchar
      003F97                      12112 00105$:
                           003EDA 12113 	C$sugeno_demo.c$433$1_0$175 ==.
                                  12114 ;	../../sugeno_demo.c:433: }
                           003EDA 12115 	C$sugeno_demo.c$433$1_0$175 ==.
                           003EDA 12116 	XFsugeno_demo$fan_speed_to_pwm$0$0 ==.
      003F97 22               [24]12117 	ret
                                  12118 ;------------------------------------------------------------
                                  12119 ;Allocation info for local variables in function 'main'
                                  12120 ;------------------------------------------------------------
                                  12121 ;sloc0         Allocated to stack - _bp +1 +4 
                                  12122 ;sloc1         Allocated to stack - _bp +5 +4 
                                  12123 ;------------------------------------------------------------
                           003EDB 12124 	G$main$0$0 ==.
                           003EDB 12125 	C$sugeno_demo.c$456$1_0$179 ==.
                                  12126 ;	../../sugeno_demo.c:456: void main(void)
                                  12127 ;	-----------------------------------------
                                  12128 ;	 function main
                                  12129 ;	-----------------------------------------
      003F98                      12130 _main:
      003F98 C0 08            [24]12131 	push	_bp
      003F9A E5 81            [12]12132 	mov	a,sp
      003F9C F5 08            [12]12133 	mov	_bp,a
      003F9E 24 08            [12]12134 	add	a,#0x08
      003FA0 F5 81            [12]12135 	mov	sp,a
                           003EE5 12136 	C$sugeno_demo.c$459$1_0$179 ==.
                                  12137 ;	../../sugeno_demo.c:459: 0x55u;
      003FA2 75 80 55         [24]12138 	mov	_P0,#0x55
                           003EE8 12139 	C$sugeno_demo.c$462$1_0$179 ==.
                                  12140 ;	../../sugeno_demo.c:462: 0x00u;
      003FA5 75 90 00         [24]12141 	mov	_P1,#0x00
                           003EEB 12142 	C$sugeno_demo.c$465$1_0$179 ==.
                                  12143 ;	../../sugeno_demo.c:465: test_temperature;
      003FA8 85 61 A0         [24]12144 	mov	_P2,_test_temperature
                           003EEE 12145 	C$sugeno_demo.c$472$2_0$179 ==.
                                  12146 ;	../../sugeno_demo.c:472: );
      003FAB 85 63 82         [24]12147 	mov	dpl, _test_vibration
      003FAE 12 43 CC         [24]12148 	lcall	___uchar2fs
      003FB1 C8               [12]12149 	xch	a,r0
      003FB2 E5 08            [12]12150 	mov	a,_bp
      003FB4 24 05            [12]12151 	add	a,#0x05
      003FB6 C8               [12]12152 	xch	a,r0
      003FB7 A6 82            [24]12153 	mov	@r0, dpl
      003FB9 08               [12]12154 	inc	r0
      003FBA A6 83            [24]12155 	mov	@r0, dph
      003FBC 08               [12]12156 	inc	r0
      003FBD A6 F0            [24]12157 	mov	@r0, b
      003FBF 08               [12]12158 	inc	r0
      003FC0 F6               [12]12159 	mov	@r0,a
                           003F04 12160 	C$sugeno_demo.c$470$2_0$179 ==.
                                  12161 ;	../../sugeno_demo.c:470: (float)test_load,
      003FC1 85 62 82         [24]12162 	mov	dpl, _test_load
      003FC4 12 43 CC         [24]12163 	lcall	___uchar2fs
      003FC7 A8 08            [24]12164 	mov	r0,_bp
      003FC9 08               [12]12165 	inc	r0
      003FCA A6 82            [24]12166 	mov	@r0, dpl
      003FCC 08               [12]12167 	inc	r0
      003FCD A6 83            [24]12168 	mov	@r0, dph
      003FCF 08               [12]12169 	inc	r0
      003FD0 A6 F0            [24]12170 	mov	@r0, b
      003FD2 08               [12]12171 	inc	r0
      003FD3 F6               [12]12172 	mov	@r0,a
                           003F17 12173 	C$sugeno_demo.c$469$2_0$179 ==.
                                  12174 ;	../../sugeno_demo.c:469: (float)test_temperature,
      003FD4 85 61 82         [24]12175 	mov	dpl, _test_temperature
      003FD7 12 43 CC         [24]12176 	lcall	___uchar2fs
      003FDA AA 82            [24]12177 	mov	r2, dpl
      003FDC AB 83            [24]12178 	mov	r3, dph
      003FDE AE F0            [24]12179 	mov	r6, b
      003FE0 FF               [12]12180 	mov	r7, a
      003FE1 E5 08            [12]12181 	mov	a,_bp
      003FE3 24 05            [12]12182 	add	a,#0x05
      003FE5 F8               [12]12183 	mov	r0,a
      003FE6 E6               [12]12184 	mov	a,@r0
      003FE7 C0 E0            [24]12185 	push	acc
      003FE9 08               [12]12186 	inc	r0
      003FEA E6               [12]12187 	mov	a,@r0
      003FEB C0 E0            [24]12188 	push	acc
      003FED 08               [12]12189 	inc	r0
      003FEE E6               [12]12190 	mov	a,@r0
      003FEF C0 E0            [24]12191 	push	acc
      003FF1 08               [12]12192 	inc	r0
      003FF2 E6               [12]12193 	mov	a,@r0
      003FF3 C0 E0            [24]12194 	push	acc
      003FF5 A8 08            [24]12195 	mov	r0,_bp
      003FF7 08               [12]12196 	inc	r0
      003FF8 E6               [12]12197 	mov	a,@r0
      003FF9 C0 E0            [24]12198 	push	acc
      003FFB 08               [12]12199 	inc	r0
      003FFC E6               [12]12200 	mov	a,@r0
      003FFD C0 E0            [24]12201 	push	acc
      003FFF 08               [12]12202 	inc	r0
      004000 E6               [12]12203 	mov	a,@r0
      004001 C0 E0            [24]12204 	push	acc
      004003 08               [12]12205 	inc	r0
      004004 E6               [12]12206 	mov	a,@r0
      004005 C0 E0            [24]12207 	push	acc
      004007 8A 82            [24]12208 	mov	dpl, r2
      004009 8B 83            [24]12209 	mov	dph, r3
      00400B 8E F0            [24]12210 	mov	b, r6
      00400D EF               [12]12211 	mov	a, r7
      00400E 12 38 FE         [24]12212 	lcall	_calculate_fan_speed
      004011 85 82 65         [24]12213 	mov	_test_fan_speed,dpl
      004014 85 83 66         [24]12214 	mov	(_test_fan_speed + 1),dph
      004017 85 F0 67         [24]12215 	mov	(_test_fan_speed + 2),b
      00401A F5 68            [12]12216 	mov	(_test_fan_speed + 3),a
      00401C E5 81            [12]12217 	mov	a,sp
      00401E 24 F8            [12]12218 	add	a,#0xf8
      004020 F5 81            [12]12219 	mov	sp,a
                           003F65 12220 	C$sugeno_demo.c$476$1_0$179 ==.
                                  12221 ;	../../sugeno_demo.c:476: test_fan_speed
      004022 85 65 82         [24]12222 	mov	dpl, _test_fan_speed
      004025 85 66 83         [24]12223 	mov	dph, (_test_fan_speed + 1)
      004028 85 67 F0         [24]12224 	mov	b, (_test_fan_speed + 2)
      00402B E5 68            [12]12225 	mov	a, (_test_fan_speed + 3)
      00402D 12 3E F6         [24]12226 	lcall	_fan_speed_to_pwm
      004030 85 82 64         [24]12227 	mov	_test_pwm,dpl
                           003F76 12228 	C$sugeno_demo.c$480$1_0$179 ==.
                                  12229 ;	../../sugeno_demo.c:480: test_pwm;
      004033 85 64 90         [24]12230 	mov	_P1,_test_pwm
                           003F79 12231 	C$sugeno_demo.c$483$1_0$179 ==.
                                  12232 ;	../../sugeno_demo.c:483: 0xAAu;
      004036 75 80 AA         [24]12233 	mov	_P0,#0xaa
      004039                      12234 00103$:
      004039 80 FE            [24]12235 	sjmp	00103$
                           003F7E 12236 	C$sugeno_demo.c$488$2_0$179 ==.
                                  12237 ;	../../sugeno_demo.c:488: }
      00403B 85 08 81         [24]12238 	mov	sp,_bp
      00403E D0 08            [24]12239 	pop	_bp
                           003F83 12240 	C$sugeno_demo.c$488$2_0$179 ==.
                           003F83 12241 	XG$main$0$0 ==.
      004040 22               [24]12242 	ret
                                  12243 	.area CSEG    (CODE)
                                  12244 	.area CONST   (CODE)
                                  12245 	.area CONST   (CODE)
                           000000 12246 Fsugeno_demo$hedges$0_0$0 == .
      00446A                      12247 _hedges:
      00446A 01                   12248 	.db #0x01	; 1
      00446B 02                   12249 	.db #0x02	; 2
      00446C 03                   12250 	.db #0x03	; 3
                                  12251 	.area CSEG    (CODE)
                                  12252 	.area XINIT   (CODE)
                                  12253 	.area CABS    (ABS,CODE)
