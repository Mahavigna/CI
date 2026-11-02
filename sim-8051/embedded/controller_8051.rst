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
                                    144 	.globl _fuzzy_rules_defuzzify_cog
                                    145 	.globl _fuzzy_rules_defuzzify_boa
                                    146 	.globl _fuzzy_rules_defuzzify_cos
                                    147 	.globl _fuzzy_rules_defuzzify_mom
                                    148 	.globl _fuzzy_rules_defuzzify_som
                                    149 	.globl _fuzzy_rules_defuzzify_lom
                                    150 	.globl _fuzzy_rules_defuzzify_method
                                    151 	.globl _fuzzy_rules_defuzzify
                                    152 	.globl _fuzzy_rules_cog
                                    153 ;--------------------------------------------------------
                                    154 ; special function registers
                                    155 ;--------------------------------------------------------
                                    156 	.area RSEG    (ABS,DATA)
      000000                        157 	.org 0x0000
                           000080   158 G$P0$0_0$0 == 0x0080
                           000080   159 _P0	=	0x0080
                           000081   160 G$SP$0_0$0 == 0x0081
                           000081   161 _SP	=	0x0081
                           000082   162 G$DPL$0_0$0 == 0x0082
                           000082   163 _DPL	=	0x0082
                           000083   164 G$DPH$0_0$0 == 0x0083
                           000083   165 _DPH	=	0x0083
                           000087   166 G$PCON$0_0$0 == 0x0087
                           000087   167 _PCON	=	0x0087
                           000088   168 G$TCON$0_0$0 == 0x0088
                           000088   169 _TCON	=	0x0088
                           000089   170 G$TMOD$0_0$0 == 0x0089
                           000089   171 _TMOD	=	0x0089
                           00008A   172 G$TL0$0_0$0 == 0x008a
                           00008A   173 _TL0	=	0x008a
                           00008B   174 G$TL1$0_0$0 == 0x008b
                           00008B   175 _TL1	=	0x008b
                           00008C   176 G$TH0$0_0$0 == 0x008c
                           00008C   177 _TH0	=	0x008c
                           00008D   178 G$TH1$0_0$0 == 0x008d
                           00008D   179 _TH1	=	0x008d
                           000090   180 G$P1$0_0$0 == 0x0090
                           000090   181 _P1	=	0x0090
                           000098   182 G$SCON$0_0$0 == 0x0098
                           000098   183 _SCON	=	0x0098
                           000099   184 G$SBUF$0_0$0 == 0x0099
                           000099   185 _SBUF	=	0x0099
                           0000A0   186 G$P2$0_0$0 == 0x00a0
                           0000A0   187 _P2	=	0x00a0
                           0000A8   188 G$IE$0_0$0 == 0x00a8
                           0000A8   189 _IE	=	0x00a8
                           0000B0   190 G$P3$0_0$0 == 0x00b0
                           0000B0   191 _P3	=	0x00b0
                           0000B8   192 G$IP$0_0$0 == 0x00b8
                           0000B8   193 _IP	=	0x00b8
                           0000D0   194 G$PSW$0_0$0 == 0x00d0
                           0000D0   195 _PSW	=	0x00d0
                           0000E0   196 G$ACC$0_0$0 == 0x00e0
                           0000E0   197 _ACC	=	0x00e0
                           0000F0   198 G$B$0_0$0 == 0x00f0
                           0000F0   199 _B	=	0x00f0
                           0000C8   200 G$T2CON$0_0$0 == 0x00c8
                           0000C8   201 _T2CON	=	0x00c8
                           0000CA   202 G$RCAP2L$0_0$0 == 0x00ca
                           0000CA   203 _RCAP2L	=	0x00ca
                           0000CB   204 G$RCAP2H$0_0$0 == 0x00cb
                           0000CB   205 _RCAP2H	=	0x00cb
                           0000CC   206 G$TL2$0_0$0 == 0x00cc
                           0000CC   207 _TL2	=	0x00cc
                           0000CD   208 G$TH2$0_0$0 == 0x00cd
                           0000CD   209 _TH2	=	0x00cd
                                    210 ;--------------------------------------------------------
                                    211 ; special function bits
                                    212 ;--------------------------------------------------------
                                    213 	.area RSEG    (ABS,DATA)
      000000                        214 	.org 0x0000
                           000080   215 G$P0_0$0_0$0 == 0x0080
                           000080   216 _P0_0	=	0x0080
                           000081   217 G$P0_1$0_0$0 == 0x0081
                           000081   218 _P0_1	=	0x0081
                           000082   219 G$P0_2$0_0$0 == 0x0082
                           000082   220 _P0_2	=	0x0082
                           000083   221 G$P0_3$0_0$0 == 0x0083
                           000083   222 _P0_3	=	0x0083
                           000084   223 G$P0_4$0_0$0 == 0x0084
                           000084   224 _P0_4	=	0x0084
                           000085   225 G$P0_5$0_0$0 == 0x0085
                           000085   226 _P0_5	=	0x0085
                           000086   227 G$P0_6$0_0$0 == 0x0086
                           000086   228 _P0_6	=	0x0086
                           000087   229 G$P0_7$0_0$0 == 0x0087
                           000087   230 _P0_7	=	0x0087
                           000088   231 G$IT0$0_0$0 == 0x0088
                           000088   232 _IT0	=	0x0088
                           000089   233 G$IE0$0_0$0 == 0x0089
                           000089   234 _IE0	=	0x0089
                           00008A   235 G$IT1$0_0$0 == 0x008a
                           00008A   236 _IT1	=	0x008a
                           00008B   237 G$IE1$0_0$0 == 0x008b
                           00008B   238 _IE1	=	0x008b
                           00008C   239 G$TR0$0_0$0 == 0x008c
                           00008C   240 _TR0	=	0x008c
                           00008D   241 G$TF0$0_0$0 == 0x008d
                           00008D   242 _TF0	=	0x008d
                           00008E   243 G$TR1$0_0$0 == 0x008e
                           00008E   244 _TR1	=	0x008e
                           00008F   245 G$TF1$0_0$0 == 0x008f
                           00008F   246 _TF1	=	0x008f
                           000090   247 G$P1_0$0_0$0 == 0x0090
                           000090   248 _P1_0	=	0x0090
                           000091   249 G$P1_1$0_0$0 == 0x0091
                           000091   250 _P1_1	=	0x0091
                           000092   251 G$P1_2$0_0$0 == 0x0092
                           000092   252 _P1_2	=	0x0092
                           000093   253 G$P1_3$0_0$0 == 0x0093
                           000093   254 _P1_3	=	0x0093
                           000094   255 G$P1_4$0_0$0 == 0x0094
                           000094   256 _P1_4	=	0x0094
                           000095   257 G$P1_5$0_0$0 == 0x0095
                           000095   258 _P1_5	=	0x0095
                           000096   259 G$P1_6$0_0$0 == 0x0096
                           000096   260 _P1_6	=	0x0096
                           000097   261 G$P1_7$0_0$0 == 0x0097
                           000097   262 _P1_7	=	0x0097
                           000098   263 G$RI$0_0$0 == 0x0098
                           000098   264 _RI	=	0x0098
                           000099   265 G$TI$0_0$0 == 0x0099
                           000099   266 _TI	=	0x0099
                           00009A   267 G$RB8$0_0$0 == 0x009a
                           00009A   268 _RB8	=	0x009a
                           00009B   269 G$TB8$0_0$0 == 0x009b
                           00009B   270 _TB8	=	0x009b
                           00009C   271 G$REN$0_0$0 == 0x009c
                           00009C   272 _REN	=	0x009c
                           00009D   273 G$SM2$0_0$0 == 0x009d
                           00009D   274 _SM2	=	0x009d
                           00009E   275 G$SM1$0_0$0 == 0x009e
                           00009E   276 _SM1	=	0x009e
                           00009F   277 G$SM0$0_0$0 == 0x009f
                           00009F   278 _SM0	=	0x009f
                           0000A0   279 G$P2_0$0_0$0 == 0x00a0
                           0000A0   280 _P2_0	=	0x00a0
                           0000A1   281 G$P2_1$0_0$0 == 0x00a1
                           0000A1   282 _P2_1	=	0x00a1
                           0000A2   283 G$P2_2$0_0$0 == 0x00a2
                           0000A2   284 _P2_2	=	0x00a2
                           0000A3   285 G$P2_3$0_0$0 == 0x00a3
                           0000A3   286 _P2_3	=	0x00a3
                           0000A4   287 G$P2_4$0_0$0 == 0x00a4
                           0000A4   288 _P2_4	=	0x00a4
                           0000A5   289 G$P2_5$0_0$0 == 0x00a5
                           0000A5   290 _P2_5	=	0x00a5
                           0000A6   291 G$P2_6$0_0$0 == 0x00a6
                           0000A6   292 _P2_6	=	0x00a6
                           0000A7   293 G$P2_7$0_0$0 == 0x00a7
                           0000A7   294 _P2_7	=	0x00a7
                           0000A8   295 G$EX0$0_0$0 == 0x00a8
                           0000A8   296 _EX0	=	0x00a8
                           0000A9   297 G$ET0$0_0$0 == 0x00a9
                           0000A9   298 _ET0	=	0x00a9
                           0000AA   299 G$EX1$0_0$0 == 0x00aa
                           0000AA   300 _EX1	=	0x00aa
                           0000AB   301 G$ET1$0_0$0 == 0x00ab
                           0000AB   302 _ET1	=	0x00ab
                           0000AC   303 G$ES$0_0$0 == 0x00ac
                           0000AC   304 _ES	=	0x00ac
                           0000AF   305 G$EA$0_0$0 == 0x00af
                           0000AF   306 _EA	=	0x00af
                           0000B0   307 G$P3_0$0_0$0 == 0x00b0
                           0000B0   308 _P3_0	=	0x00b0
                           0000B1   309 G$P3_1$0_0$0 == 0x00b1
                           0000B1   310 _P3_1	=	0x00b1
                           0000B2   311 G$P3_2$0_0$0 == 0x00b2
                           0000B2   312 _P3_2	=	0x00b2
                           0000B3   313 G$P3_3$0_0$0 == 0x00b3
                           0000B3   314 _P3_3	=	0x00b3
                           0000B4   315 G$P3_4$0_0$0 == 0x00b4
                           0000B4   316 _P3_4	=	0x00b4
                           0000B5   317 G$P3_5$0_0$0 == 0x00b5
                           0000B5   318 _P3_5	=	0x00b5
                           0000B6   319 G$P3_6$0_0$0 == 0x00b6
                           0000B6   320 _P3_6	=	0x00b6
                           0000B7   321 G$P3_7$0_0$0 == 0x00b7
                           0000B7   322 _P3_7	=	0x00b7
                           0000B0   323 G$RXD$0_0$0 == 0x00b0
                           0000B0   324 _RXD	=	0x00b0
                           0000B1   325 G$TXD$0_0$0 == 0x00b1
                           0000B1   326 _TXD	=	0x00b1
                           0000B2   327 G$INT0$0_0$0 == 0x00b2
                           0000B2   328 _INT0	=	0x00b2
                           0000B3   329 G$INT1$0_0$0 == 0x00b3
                           0000B3   330 _INT1	=	0x00b3
                           0000B4   331 G$T0$0_0$0 == 0x00b4
                           0000B4   332 _T0	=	0x00b4
                           0000B5   333 G$T1$0_0$0 == 0x00b5
                           0000B5   334 _T1	=	0x00b5
                           0000B6   335 G$WR$0_0$0 == 0x00b6
                           0000B6   336 _WR	=	0x00b6
                           0000B7   337 G$RD$0_0$0 == 0x00b7
                           0000B7   338 _RD	=	0x00b7
                           0000B8   339 G$PX0$0_0$0 == 0x00b8
                           0000B8   340 _PX0	=	0x00b8
                           0000B9   341 G$PT0$0_0$0 == 0x00b9
                           0000B9   342 _PT0	=	0x00b9
                           0000BA   343 G$PX1$0_0$0 == 0x00ba
                           0000BA   344 _PX1	=	0x00ba
                           0000BB   345 G$PT1$0_0$0 == 0x00bb
                           0000BB   346 _PT1	=	0x00bb
                           0000BC   347 G$PS$0_0$0 == 0x00bc
                           0000BC   348 _PS	=	0x00bc
                           0000D0   349 G$P$0_0$0 == 0x00d0
                           0000D0   350 _P	=	0x00d0
                           0000D1   351 G$F1$0_0$0 == 0x00d1
                           0000D1   352 _F1	=	0x00d1
                           0000D2   353 G$OV$0_0$0 == 0x00d2
                           0000D2   354 _OV	=	0x00d2
                           0000D3   355 G$RS0$0_0$0 == 0x00d3
                           0000D3   356 _RS0	=	0x00d3
                           0000D4   357 G$RS1$0_0$0 == 0x00d4
                           0000D4   358 _RS1	=	0x00d4
                           0000D5   359 G$F0$0_0$0 == 0x00d5
                           0000D5   360 _F0	=	0x00d5
                           0000D6   361 G$AC$0_0$0 == 0x00d6
                           0000D6   362 _AC	=	0x00d6
                           0000D7   363 G$CY$0_0$0 == 0x00d7
                           0000D7   364 _CY	=	0x00d7
                           0000AD   365 G$ET2$0_0$0 == 0x00ad
                           0000AD   366 _ET2	=	0x00ad
                           0000BD   367 G$PT2$0_0$0 == 0x00bd
                           0000BD   368 _PT2	=	0x00bd
                           0000C8   369 G$T2CON_0$0_0$0 == 0x00c8
                           0000C8   370 _T2CON_0	=	0x00c8
                           0000C9   371 G$T2CON_1$0_0$0 == 0x00c9
                           0000C9   372 _T2CON_1	=	0x00c9
                           0000CA   373 G$T2CON_2$0_0$0 == 0x00ca
                           0000CA   374 _T2CON_2	=	0x00ca
                           0000CB   375 G$T2CON_3$0_0$0 == 0x00cb
                           0000CB   376 _T2CON_3	=	0x00cb
                           0000CC   377 G$T2CON_4$0_0$0 == 0x00cc
                           0000CC   378 _T2CON_4	=	0x00cc
                           0000CD   379 G$T2CON_5$0_0$0 == 0x00cd
                           0000CD   380 _T2CON_5	=	0x00cd
                           0000CE   381 G$T2CON_6$0_0$0 == 0x00ce
                           0000CE   382 _T2CON_6	=	0x00ce
                           0000CF   383 G$T2CON_7$0_0$0 == 0x00cf
                           0000CF   384 _T2CON_7	=	0x00cf
                           0000C8   385 G$CP_RL2$0_0$0 == 0x00c8
                           0000C8   386 _CP_RL2	=	0x00c8
                           0000C9   387 G$C_T2$0_0$0 == 0x00c9
                           0000C9   388 _C_T2	=	0x00c9
                           0000CA   389 G$TR2$0_0$0 == 0x00ca
                           0000CA   390 _TR2	=	0x00ca
                           0000CB   391 G$EXEN2$0_0$0 == 0x00cb
                           0000CB   392 _EXEN2	=	0x00cb
                           0000CC   393 G$TCLK$0_0$0 == 0x00cc
                           0000CC   394 _TCLK	=	0x00cc
                           0000CD   395 G$RCLK$0_0$0 == 0x00cd
                           0000CD   396 _RCLK	=	0x00cd
                           0000CE   397 G$EXF2$0_0$0 == 0x00ce
                           0000CE   398 _EXF2	=	0x00ce
                           0000CF   399 G$TF2$0_0$0 == 0x00cf
                           0000CF   400 _TF2	=	0x00cf
                                    401 ;--------------------------------------------------------
                                    402 ; overlayable register banks
                                    403 ;--------------------------------------------------------
                                    404 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        405 	.ds 8
                                    406 ;--------------------------------------------------------
                                    407 ; overlayable bit register bank
                                    408 ;--------------------------------------------------------
                                    409 	.area BIT_BANK	(REL,OVR,DATA)
      000020                        410 bits:
      000020                        411 	.ds 1
                           008000   412 	b0 = bits[0]
                           008100   413 	b1 = bits[1]
                           008200   414 	b2 = bits[2]
                           008300   415 	b3 = bits[3]
                           008400   416 	b4 = bits[4]
                           008500   417 	b5 = bits[5]
                           008600   418 	b6 = bits[6]
                           008700   419 	b7 = bits[7]
                                    420 ;--------------------------------------------------------
                                    421 ; internal ram data
                                    422 ;--------------------------------------------------------
                                    423 	.area DSEG    (DATA)
                           000000   424 Fcontroller_8051$fuzzy_values_buffer$0_0$0==.
      000021                        425 _fuzzy_values_buffer:
      000021                        426 	.ds 64
                           000040   427 G$test_temperature$0_0$0==.
      000061                        428 _test_temperature::
      000061                        429 	.ds 1
                           000041   430 G$test_pwm$0_0$0==.
      000062                        431 _test_pwm::
      000062                        432 	.ds 1
                           000042   433 G$test_fan_speed$0_0$0==.
      000063                        434 _test_fan_speed::
      000063                        435 	.ds 4
                                    436 ;--------------------------------------------------------
                                    437 ; overlayable items in internal ram
                                    438 ;--------------------------------------------------------
                                    439 ;--------------------------------------------------------
                                    440 ; Stack segment in internal ram
                                    441 ;--------------------------------------------------------
                                    442 	.area SSEG
      000067                        443 __start__stack:
      000067                        444 	.ds	1
                                    445 
                                    446 ;--------------------------------------------------------
                                    447 ; indirectly addressable internal ram data
                                    448 ;--------------------------------------------------------
                                    449 	.area ISEG    (DATA)
                                    450 ;--------------------------------------------------------
                                    451 ; absolute internal ram data
                                    452 ;--------------------------------------------------------
                                    453 	.area IABS    (ABS,DATA)
                                    454 	.area IABS    (ABS,DATA)
                                    455 ;--------------------------------------------------------
                                    456 ; bit data
                                    457 ;--------------------------------------------------------
                                    458 	.area BSEG    (BIT)
                                    459 ;--------------------------------------------------------
                                    460 ; paged external ram data
                                    461 ;--------------------------------------------------------
                                    462 	.area PSEG    (PAG,XDATA)
                                    463 ;--------------------------------------------------------
                                    464 ; uninitialized external ram data
                                    465 ;--------------------------------------------------------
                                    466 	.area XSEG    (XDATA)
                                    467 ;--------------------------------------------------------
                                    468 ; absolute external ram data
                                    469 ;--------------------------------------------------------
                                    470 	.area XABS    (ABS,XDATA)
                                    471 ;--------------------------------------------------------
                                    472 ; initialized external ram data
                                    473 ;--------------------------------------------------------
                                    474 	.area XISEG   (XDATA)
                                    475 	.area HOME    (CODE)
                                    476 	.area GSINIT0 (CODE)
                                    477 	.area GSINIT1 (CODE)
                                    478 	.area GSINIT2 (CODE)
                                    479 	.area GSINIT3 (CODE)
                                    480 	.area GSINIT4 (CODE)
                                    481 	.area GSINIT5 (CODE)
                                    482 	.area GSINIT  (CODE)
                                    483 	.area GSFINAL (CODE)
                                    484 	.area CSEG    (CODE)
                                    485 ;--------------------------------------------------------
                                    486 ; interrupt vector
                                    487 ;--------------------------------------------------------
                                    488 	.area HOME    (CODE)
      000000                        489 __interrupt_vect:
      000000 02 00 4C         [24]  490 	ljmp	__sdcc_gsinit_startup
                                    491 ; restartable atomic support routines
      000003                        492 	.ds	5
      000008                        493 sdcc_atomic_exchange_rollback_start::
      000008 00               [12]  494 	nop
      000009 00               [12]  495 	nop
      00000A                        496 sdcc_atomic_exchange_pdata_impl:
      00000A E2               [24]  497 	movx	a, @r0
      00000B FB               [12]  498 	mov	r3, a
      00000C EA               [12]  499 	mov	a, r2
      00000D F2               [24]  500 	movx	@r0, a
      00000E 80 2C            [24]  501 	sjmp	sdcc_atomic_exchange_exit
      000010 00               [12]  502 	nop
      000011 00               [12]  503 	nop
      000012                        504 sdcc_atomic_exchange_xdata_impl:
      000012 E0               [24]  505 	movx	a, @dptr
      000013 FB               [12]  506 	mov	r3, a
      000014 EA               [12]  507 	mov	a, r2
      000015 F0               [24]  508 	movx	@dptr, a
      000016 80 24            [24]  509 	sjmp	sdcc_atomic_exchange_exit
      000018                        510 sdcc_atomic_compare_exchange_idata_impl:
      000018 E6               [12]  511 	mov	a, @r0
      000019 B5 02 02         [24]  512 	cjne	a, ar2, .+#5
      00001C EB               [12]  513 	mov	a, r3
      00001D F6               [12]  514 	mov	@r0, a
      00001E 22               [24]  515 	ret
      00001F 00               [12]  516 	nop
      000020                        517 sdcc_atomic_compare_exchange_pdata_impl:
      000020 E2               [24]  518 	movx	a, @r0
      000021 B5 02 02         [24]  519 	cjne	a, ar2, .+#5
      000024 EB               [12]  520 	mov	a, r3
      000025 F2               [24]  521 	movx	@r0, a
      000026 22               [24]  522 	ret
      000027 00               [12]  523 	nop
      000028                        524 sdcc_atomic_compare_exchange_xdata_impl:
      000028 E0               [24]  525 	movx	a, @dptr
      000029 B5 02 02         [24]  526 	cjne	a, ar2, .+#5
      00002C EB               [12]  527 	mov	a, r3
      00002D F0               [24]  528 	movx	@dptr, a
      00002E 22               [24]  529 	ret
      00002F                        530 sdcc_atomic_exchange_rollback_end::
                                    531 
      00002F                        532 sdcc_atomic_exchange_gptr_impl::
      00002F 30 F6 E0         [24]  533 	jnb	b.6, sdcc_atomic_exchange_xdata_impl
      000032 A8 82            [24]  534 	mov	r0, dpl
      000034 20 F5 D3         [24]  535 	jb	b.5, sdcc_atomic_exchange_pdata_impl
      000037                        536 sdcc_atomic_exchange_idata_impl:
      000037 EA               [12]  537 	mov	a, r2
      000038 C6               [12]  538 	xch	a, @r0
      000039 F5 82            [12]  539 	mov	dpl, a
      00003B 22               [24]  540 	ret
      00003C                        541 sdcc_atomic_exchange_exit:
      00003C 8B 82            [24]  542 	mov	dpl, r3
      00003E 22               [24]  543 	ret
      00003F                        544 sdcc_atomic_compare_exchange_gptr_impl::
      00003F 30 F6 E6         [24]  545 	jnb	b.6, sdcc_atomic_compare_exchange_xdata_impl
      000042 A8 82            [24]  546 	mov	r0, dpl
      000044 20 F5 D9         [24]  547 	jb	b.5, sdcc_atomic_compare_exchange_pdata_impl
      000047 80 CF            [24]  548 	sjmp	sdcc_atomic_compare_exchange_idata_impl
                                    549 ;--------------------------------------------------------
                                    550 ; global & static initialisations
                                    551 ;--------------------------------------------------------
                                    552 	.area HOME    (CODE)
                                    553 	.area GSINIT  (CODE)
                                    554 	.area GSFINAL (CODE)
                                    555 	.area GSINIT  (CODE)
                                    556 	.globl __sdcc_gsinit_startup
                                    557 	.globl __sdcc_program_startup
                                    558 	.globl __start__stack
                                    559 	.globl __mcs51_genXINIT
                                    560 	.globl __mcs51_genXRAMCLEAR
                                    561 	.globl __mcs51_genRAMCLEAR
                           000000   562 	C$controller_8051.c$25$2_0$161 ==.
                                    563 ;	../../controller_8051.c:25: volatile unsigned char test_temperature = 0u;
      0000A5 75 61 00         [24]  564 	mov	_test_temperature,#0x00
                           000003   565 	C$controller_8051.c$26$2_0$161 ==.
                                    566 ;	../../controller_8051.c:26: volatile unsigned char test_pwm = 0u;
      0000A8 75 62 00         [24]  567 	mov	_test_pwm,#0x00
                           000006   568 	C$controller_8051.c$27$2_0$161 ==.
                                    569 ;	../../controller_8051.c:27: volatile float test_fan_speed = 0.0f;
      0000AB E4               [12]  570 	clr	a
      0000AC F5 63            [12]  571 	mov	_test_fan_speed,a
      0000AE F5 64            [12]  572 	mov	(_test_fan_speed + 1),a
      0000B0 F5 65            [12]  573 	mov	(_test_fan_speed + 2),a
      0000B2 F5 66            [12]  574 	mov	(_test_fan_speed + 3),a
                                    575 	.area GSFINAL (CODE)
      0000B4 02 00 49         [24]  576 	ljmp	__sdcc_program_startup
                                    577 ;--------------------------------------------------------
                                    578 ; Home
                                    579 ;--------------------------------------------------------
                                    580 	.area HOME    (CODE)
                                    581 	.area HOME    (CODE)
      000049                        582 __sdcc_program_startup:
      000049 02 34 4D         [24]  583 	ljmp	_main
                                    584 ;	return from main will return to caller
                                    585 ;--------------------------------------------------------
                                    586 ; code
                                    587 ;--------------------------------------------------------
                                    588 	.area CSEG    (CODE)
                                    589 ;------------------------------------------------------------
                                    590 ;Allocation info for local variables in function 'fuzzy_values_initialize'
                                    591 ;------------------------------------------------------------
                                    592 ;index         Allocated to registers r6 r7 
                                    593 ;------------------------------------------------------------
                           000000   594 	Fcontroller_8051$fuzzy_values_initialize$0$0 ==.
                           000000   595 	C$fuzzy.h$277$0_0$3 ==.
                                    596 ;	../../fuzzy.h:277: static float *fuzzy_values_initialize(void)
                                    597 ;	-----------------------------------------
                                    598 ;	 function fuzzy_values_initialize
                                    599 ;	-----------------------------------------
      0000B7                        600 _fuzzy_values_initialize:
                           000007   601 	ar7 = 0x07
                           000006   602 	ar6 = 0x06
                           000005   603 	ar5 = 0x05
                           000004   604 	ar4 = 0x04
                           000003   605 	ar3 = 0x03
                           000002   606 	ar2 = 0x02
                           000001   607 	ar1 = 0x01
                           000000   608 	ar0 = 0x00
                           000000   609 	C$fuzzy.h$282$3_0$5 ==.
                                    610 ;	../../fuzzy.h:282: index = 0u;
      0000B7 7E 00            [12]  611 	mov	r6,#0x00
      0000B9 7F 00            [12]  612 	mov	r7,#0x00
      0000BB                        613 00102$:
                           000004   614 	C$fuzzy.h$286$3_0$5 ==.
                                    615 ;	../../fuzzy.h:286: fuzzy_values_buffer[index] = 0.0f;
      0000BB EE               [12]  616 	mov	a,r6
      0000BC 2E               [12]  617 	add	a,r6
      0000BD FC               [12]  618 	mov	r4,a
      0000BE EF               [12]  619 	mov	a,r7
      0000BF 33               [12]  620 	rlc	a
      0000C0 FD               [12]  621 	mov	r5,a
      0000C1 EC               [12]  622 	mov	a,r4
      0000C2 2C               [12]  623 	add	a,r4
      0000C3 FC               [12]  624 	mov	r4,a
      0000C4 ED               [12]  625 	mov	a,r5
      0000C5 33               [12]  626 	rlc	a
      0000C6 EC               [12]  627 	mov	a,r4
      0000C7 24 21            [12]  628 	add	a, #_fuzzy_values_buffer
      0000C9 F8               [12]  629 	mov	r0,a
      0000CA 76 00            [12]  630 	mov	@r0,#0x00
      0000CC 08               [12]  631 	inc	r0
      0000CD 76 00            [12]  632 	mov	@r0,#0x00
      0000CF 08               [12]  633 	inc	r0
      0000D0 76 00            [12]  634 	mov	@r0,#0x00
      0000D2 08               [12]  635 	inc	r0
      0000D3 76 00            [12]  636 	mov	@r0,#0x00
                           00001E   637 	C$fuzzy.h$284$2_0$4 ==.
                                    638 ;	../../fuzzy.h:284: index++
      0000D5 0E               [12]  639 	inc	r6
      0000D6 BE 00 01         [24]  640 	cjne	r6,#0x00,00119$
      0000D9 0F               [12]  641 	inc	r7
      0000DA                        642 00119$:
                           000023   643 	C$fuzzy.h$283$2_0$4 ==.
                                    644 ;	../../fuzzy.h:283: index < FUZZY_MAX_VALUES;
      0000DA C3               [12]  645 	clr	c
      0000DB EE               [12]  646 	mov	a,r6
      0000DC 94 10            [12]  647 	subb	a,#0x10
      0000DE EF               [12]  648 	mov	a,r7
      0000DF 94 00            [12]  649 	subb	a,#0x00
      0000E1 40 D8            [24]  650 	jc	00102$
                           00002C   651 	C$fuzzy.h$289$1_0$3 ==.
                                    652 ;	../../fuzzy.h:289: return fuzzy_values_buffer;
      0000E3 90 00 21         [24]  653 	mov	dptr,#_fuzzy_values_buffer
      0000E6 75 F0 40         [24]  654 	mov	b, #0x40
                           000032   655 	C$fuzzy.h$290$1_0$3 ==.
                                    656 ;	../../fuzzy.h:290: }
                           000032   657 	C$fuzzy.h$290$1_0$3 ==.
                           000032   658 	XFcontroller_8051$fuzzy_values_initialize$0$0 ==.
      0000E9 22               [24]  659 	ret
                                    660 ;------------------------------------------------------------
                                    661 ;Allocation info for local variables in function 'fuzzy_clamp'
                                    662 ;------------------------------------------------------------
                                    663 ;value         Allocated to registers r4 r5 r6 r7 
                                    664 ;------------------------------------------------------------
                           000033   665 	Fcontroller_8051$fuzzy_clamp$0$0 ==.
                           000033   666 	C$fuzzy.h$1238$1_0$27 ==.
                                    667 ;	../../fuzzy.h:1238: static float fuzzy_clamp(float value)
                                    668 ;	-----------------------------------------
                                    669 ;	 function fuzzy_clamp
                                    670 ;	-----------------------------------------
      0000EA                        671 _fuzzy_clamp:
      0000EA AC 82            [24]  672 	mov	r4,dpl
      0000EC AD 83            [24]  673 	mov	r5,dph
      0000EE AE F0            [24]  674 	mov	r6,b
      0000F0 FF               [12]  675 	mov	r7,a
                           00003A   676 	C$fuzzy.h$1240$1_0$27 ==.
                                    677 ;	../../fuzzy.h:1240: if (value < LEVEL_LO) return LEVEL_LO;
      0000F1 C0 07            [24]  678 	push	ar7
      0000F3 C0 06            [24]  679 	push	ar6
      0000F5 C0 05            [24]  680 	push	ar5
      0000F7 C0 04            [24]  681 	push	ar4
      0000F9 E4               [12]  682 	clr	a
      0000FA C0 E0            [24]  683 	push	acc
      0000FC C0 E0            [24]  684 	push	acc
      0000FE C0 E0            [24]  685 	push	acc
      000100 C0 E0            [24]  686 	push	acc
      000102 8C 82            [24]  687 	mov	dpl, r4
      000104 8D 83            [24]  688 	mov	dph, r5
      000106 8E F0            [24]  689 	mov	b, r6
      000108 EF               [12]  690 	mov	a, r7
      000109 12 35 C2         [24]  691 	lcall	___fslt
      00010C AB 82            [24]  692 	mov	r3, dpl
      00010E E5 81            [12]  693 	mov	a,sp
      000110 24 FC            [12]  694 	add	a,#0xfc
      000112 F5 81            [12]  695 	mov	sp,a
      000114 D0 04            [24]  696 	pop	ar4
      000116 D0 05            [24]  697 	pop	ar5
      000118 D0 06            [24]  698 	pop	ar6
      00011A D0 07            [24]  699 	pop	ar7
      00011C EB               [12]  700 	mov	a,r3
      00011D 60 08            [24]  701 	jz	00102$
      00011F 90 00 00         [24]  702 	mov	dptr,#0x0000
      000122 E4               [12]  703 	clr	a
      000123 F5 F0            [12]  704 	mov	b,a
      000125 80 3F            [24]  705 	sjmp	00105$
      000127                        706 00102$:
                           000070   707 	C$fuzzy.h$1242$1_0$27 ==.
                                    708 ;	../../fuzzy.h:1242: if (value > LEVEL_HI) return LEVEL_HI;
      000127 C0 07            [24]  709 	push	ar7
      000129 C0 06            [24]  710 	push	ar6
      00012B C0 05            [24]  711 	push	ar5
      00012D C0 04            [24]  712 	push	ar4
      00012F C0 04            [24]  713 	push	ar4
      000131 C0 05            [24]  714 	push	ar5
      000133 C0 06            [24]  715 	push	ar6
      000135 C0 07            [24]  716 	push	ar7
      000137 90 00 00         [24]  717 	mov	dptr,#0x0000
      00013A 75 F0 80         [24]  718 	mov	b, #0x80
      00013D 74 3F            [12]  719 	mov	a, #0x3f
      00013F 12 35 C2         [24]  720 	lcall	___fslt
      000142 AB 82            [24]  721 	mov	r3, dpl
      000144 E5 81            [12]  722 	mov	a,sp
      000146 24 FC            [12]  723 	add	a,#0xfc
      000148 F5 81            [12]  724 	mov	sp,a
      00014A D0 04            [24]  725 	pop	ar4
      00014C D0 05            [24]  726 	pop	ar5
      00014E D0 06            [24]  727 	pop	ar6
      000150 D0 07            [24]  728 	pop	ar7
      000152 EB               [12]  729 	mov	a,r3
      000153 60 0A            [24]  730 	jz	00104$
      000155 90 00 00         [24]  731 	mov	dptr,#0x0000
      000158 75 F0 80         [24]  732 	mov	b, #0x80
      00015B 74 3F            [12]  733 	mov	a, #0x3f
      00015D 80 07            [24]  734 	sjmp	00105$
      00015F                        735 00104$:
                           0000A8   736 	C$fuzzy.h$1244$1_0$27 ==.
                                    737 ;	../../fuzzy.h:1244: return value;
      00015F 8C 82            [24]  738 	mov	dpl, r4
      000161 8D 83            [24]  739 	mov	dph, r5
      000163 8E F0            [24]  740 	mov	b, r6
      000165 EF               [12]  741 	mov	a, r7
      000166                        742 00105$:
                           0000AF   743 	C$fuzzy.h$1245$1_0$27 ==.
                                    744 ;	../../fuzzy.h:1245: }
                           0000AF   745 	C$fuzzy.h$1245$1_0$27 ==.
                           0000AF   746 	XFcontroller_8051$fuzzy_clamp$0$0 ==.
      000166 22               [24]  747 	ret
                                    748 ;------------------------------------------------------------
                                    749 ;Allocation info for local variables in function 'fuzzy_not'
                                    750 ;------------------------------------------------------------
                                    751 ;membership    Allocated to registers r4 r5 r6 r7 
                                    752 ;------------------------------------------------------------
                           0000B0   753 	G$fuzzy_not$0$0 ==.
                           0000B0   754 	C$fuzzy.h$1250$1_0$29 ==.
                                    755 ;	../../fuzzy.h:1250: float fuzzy_not(float membership)
                                    756 ;	-----------------------------------------
                                    757 ;	 function fuzzy_not
                                    758 ;	-----------------------------------------
      000167                        759 _fuzzy_not:
                           0000B0   760 	C$fuzzy.h$1252$1_0$29 ==.
                                    761 ;	../../fuzzy.h:1252: return LEVEL_HI - fuzzy_clamp(membership);
      000167 12 00 EA         [24]  762 	lcall	_fuzzy_clamp
      00016A AC 82            [24]  763 	mov	r4, dpl
      00016C AD 83            [24]  764 	mov	r5, dph
      00016E AE F0            [24]  765 	mov	r6, b
      000170 FF               [12]  766 	mov	r7, a
      000171 C0 04            [24]  767 	push	ar4
      000173 C0 05            [24]  768 	push	ar5
      000175 C0 06            [24]  769 	push	ar6
      000177 C0 07            [24]  770 	push	ar7
      000179 90 00 00         [24]  771 	mov	dptr,#0x0000
      00017C 75 F0 80         [24]  772 	mov	b, #0x80
      00017F 74 3F            [12]  773 	mov	a, #0x3f
      000181 12 34 87         [24]  774 	lcall	___fssub
      000184 AC 82            [24]  775 	mov	r4, dpl
      000186 AD 83            [24]  776 	mov	r5, dph
      000188 AE F0            [24]  777 	mov	r6, b
      00018A FF               [12]  778 	mov	r7, a
      00018B E5 81            [12]  779 	mov	a,sp
      00018D 24 FC            [12]  780 	add	a,#0xfc
      00018F F5 81            [12]  781 	mov	sp,a
      000191 8C 82            [24]  782 	mov	dpl, r4
      000193 8D 83            [24]  783 	mov	dph, r5
      000195 8E F0            [24]  784 	mov	b, r6
      000197 EF               [12]  785 	mov	a, r7
                           0000E1   786 	C$fuzzy.h$1253$1_0$29 ==.
                                    787 ;	../../fuzzy.h:1253: }
                           0000E1   788 	C$fuzzy.h$1253$1_0$29 ==.
                           0000E1   789 	XG$fuzzy_not$0$0 ==.
      000198 22               [24]  790 	ret
                                    791 ;------------------------------------------------------------
                                    792 ;Allocation info for local variables in function 'fuzzy_apply_hedge'
                                    793 ;------------------------------------------------------------
                                    794 ;hedge         Allocated to stack - _bp -3 +1 
                                    795 ;membership    Allocated to stack - _bp +1 +4 
                                    796 ;result        Allocated to registers r2 r3 r6 r7 
                                    797 ;------------------------------------------------------------
                           0000E2   798 	Fcontroller_8051$fuzzy_apply_hedge$0$0 ==.
                           0000E2   799 	C$fuzzy.h$1263$1_0$31 ==.
                                    800 ;	../../fuzzy.h:1263: static float fuzzy_apply_hedge(
                                    801 ;	-----------------------------------------
                                    802 ;	 function fuzzy_apply_hedge
                                    803 ;	-----------------------------------------
      000199                        804 _fuzzy_apply_hedge:
      000199 C0 08            [24]  805 	push	_bp
      00019B 85 81 08         [24]  806 	mov	_bp,sp
      00019E AC 82            [24]  807 	mov	r4,dpl
      0001A0 AD 83            [24]  808 	mov	r5,dph
      0001A2 AE F0            [24]  809 	mov	r6,b
      0001A4 FF               [12]  810 	mov	r7,a
      0001A5 E5 81            [12]  811 	mov	a,sp
      0001A7 24 04            [12]  812 	add	a,#0x04
      0001A9 F5 81            [12]  813 	mov	sp,a
                           0000F4   814 	C$fuzzy.h$1269$1_0$31 ==.
                                    815 ;	../../fuzzy.h:1269: fuzzy_clamp( membership
      0001AB 8C 82            [24]  816 	mov	dpl, r4
      0001AD 8D 83            [24]  817 	mov	dph, r5
      0001AF 8E F0            [24]  818 	mov	b, r6
      0001B1 EF               [12]  819 	mov	a, r7
      0001B2 12 00 EA         [24]  820 	lcall	_fuzzy_clamp
      0001B5 A8 08            [24]  821 	mov	r0,_bp
      0001B7 08               [12]  822 	inc	r0
      0001B8 A6 82            [24]  823 	mov	@r0, dpl
      0001BA 08               [12]  824 	inc	r0
      0001BB A6 83            [24]  825 	mov	@r0, dph
      0001BD 08               [12]  826 	inc	r0
      0001BE A6 F0            [24]  827 	mov	@r0, b
      0001C0 08               [12]  828 	inc	r0
      0001C1 F6               [12]  829 	mov	@r0,a
                           00010B   830 	C$fuzzy.h$1274$2_0$32 ==.
                                    831 ;	../../fuzzy.h:1274: float result =
      0001C2 7A 00            [12]  832 	mov	r2,#0x00
      0001C4 7B 00            [12]  833 	mov	r3,#0x00
      0001C6 7E 80            [12]  834 	mov	r6,#0x80
      0001C8 7F 3F            [12]  835 	mov	r7,#0x3f
                           000113   836 	C$fuzzy.h$1277$1_1$32 ==.
                                    837 ;	../../fuzzy.h:1277: if (hedge == 0u) {
      0001CA E5 08            [12]  838 	mov	a,_bp
      0001CC 24 FD            [12]  839 	add	a,#0xfd
      0001CE F8               [12]  840 	mov	r0,a
      0001CF E6               [12]  841 	mov	a,@r0
      0001D0 70 07            [24]  842 	jnz	00110$
                           00011B   843 	C$fuzzy.h$1278$2_1$33 ==.
                                    844 ;	../../fuzzy.h:1278: hedge = 1u;
      0001D2 E5 08            [12]  845 	mov	a,_bp
      0001D4 24 FD            [12]  846 	add	a,#0xfd
      0001D6 F8               [12]  847 	mov	r0,a
      0001D7 76 01            [12]  848 	mov	@r0,#0x01
                           000122   849 	C$fuzzy.h$1281$1_1$31 ==.
                                    850 ;	../../fuzzy.h:1281: while (hedge > 0u) {
      0001D9                        851 00110$:
      0001D9 E5 08            [12]  852 	mov	a,_bp
      0001DB 24 FD            [12]  853 	add	a,#0xfd
      0001DD F8               [12]  854 	mov	r0,a
      0001DE 86 05            [24]  855 	mov	ar5,@r0
      0001E0                        856 00103$:
      0001E0 ED               [12]  857 	mov	a,r5
      0001E1 60 30            [24]  858 	jz	00105$
                           00012C   859 	C$fuzzy.h$1282$1_1$31 ==.
                                    860 ;	../../fuzzy.h:1282: result *= membership;
      0001E3 C0 05            [24]  861 	push	ar5
      0001E5 A8 08            [24]  862 	mov	r0,_bp
      0001E7 08               [12]  863 	inc	r0
      0001E8 E6               [12]  864 	mov	a,@r0
      0001E9 C0 E0            [24]  865 	push	acc
      0001EB 08               [12]  866 	inc	r0
      0001EC E6               [12]  867 	mov	a,@r0
      0001ED C0 E0            [24]  868 	push	acc
      0001EF 08               [12]  869 	inc	r0
      0001F0 E6               [12]  870 	mov	a,@r0
      0001F1 C0 E0            [24]  871 	push	acc
      0001F3 08               [12]  872 	inc	r0
      0001F4 E6               [12]  873 	mov	a,@r0
      0001F5 C0 E0            [24]  874 	push	acc
                           000140   875 	C$fuzzy.h$1284$1_1$31 ==.
                                    876 ;	../../fuzzy.h:1284: hedge--;
      0001F7 8A 82            [24]  877 	mov	dpl, r2
      0001F9 8B 83            [24]  878 	mov	dph, r3
      0001FB 8E F0            [24]  879 	mov	b, r6
      0001FD EF               [12]  880 	mov	a, r7
      0001FE 12 34 92         [24]  881 	lcall	___fsmul
      000201 AA 82            [24]  882 	mov	r2, dpl
      000203 AB 83            [24]  883 	mov	r3, dph
      000205 AE F0            [24]  884 	mov	r6, b
      000207 FF               [12]  885 	mov	r7, a
      000208 E5 81            [12]  886 	mov	a,sp
      00020A 24 FC            [12]  887 	add	a,#0xfc
      00020C F5 81            [12]  888 	mov	sp,a
      00020E D0 05            [24]  889 	pop	ar5
      000210 1D               [12]  890 	dec	r5
      000211 80 CD            [24]  891 	sjmp	00103$
      000213                        892 00105$:
                           00015C   893 	C$fuzzy.h$1288$1_1$32 ==.
                                    894 ;	../../fuzzy.h:1288: result
      000213 8A 82            [24]  895 	mov	dpl, r2
      000215 8B 83            [24]  896 	mov	dph, r3
      000217 8E F0            [24]  897 	mov	b, r6
      000219 EF               [12]  898 	mov	a, r7
      00021A 12 00 EA         [24]  899 	lcall	_fuzzy_clamp
                           000166   900 	C$fuzzy.h$1304$1_1$31 ==.
                                    901 ;	../../fuzzy.h:1304: }
      00021D 85 08 81         [24]  902 	mov	sp,_bp
      000220 D0 08            [24]  903 	pop	_bp
                           00016B   904 	C$fuzzy.h$1304$1_1$31 ==.
                           00016B   905 	XFcontroller_8051$fuzzy_apply_hedge$0$0 ==.
      000222 22               [24]  906 	ret
                                    907 ;------------------------------------------------------------
                                    908 ;Allocation info for local variables in function 'fuzzy_and_array'
                                    909 ;------------------------------------------------------------
                                    910 ;count         Allocated to stack - _bp -4 +2 
                                    911 ;args          Allocated to stack - _bp -7 +3 
                                    912 ;method        Allocated to registers r5 
                                    913 ;result        Allocated to stack - _bp +5 +4 
                                    914 ;next          Allocated to stack - _bp +9 +4 
                                    915 ;index         Allocated to stack - _bp +13 +2 
                                    916 ;sloc0         Allocated to stack - _bp +1 +3 
                                    917 ;sloc1         Allocated to stack - _bp +4 +1 
                                    918 ;------------------------------------------------------------
                           00016C   919 	G$fuzzy_and_array$0$0 ==.
                           00016C   920 	C$fuzzy.h$1318$1_1$36 ==.
                                    921 ;	../../fuzzy.h:1318: float fuzzy_and_array(
                                    922 ;	-----------------------------------------
                                    923 ;	 function fuzzy_and_array
                                    924 ;	-----------------------------------------
      000223                        925 _fuzzy_and_array:
      000223 C0 08            [24]  926 	push	_bp
      000225 E5 81            [12]  927 	mov	a,sp
      000227 F5 08            [12]  928 	mov	_bp,a
      000229 24 0E            [12]  929 	add	a,#0x0e
      00022B F5 81            [12]  930 	mov	sp,a
      00022D AD 82            [24]  931 	mov	r5, dpl
                           000178   932 	C$fuzzy.h$1329$1_0$36 ==.
                                    933 ;	../../fuzzy.h:1329: args == NULL ||
      00022F E5 08            [12]  934 	mov	a,_bp
      000231 24 F9            [12]  935 	add	a,#0xf9
      000233 F8               [12]  936 	mov	r0,a
      000234 E6               [12]  937 	mov	a,@r0
      000235 08               [12]  938 	inc	r0
      000236 46               [12]  939 	orl	a,@r0
      000237 60 0A            [24]  940 	jz	00101$
                           000182   941 	C$fuzzy.h$1330$1_0$36 ==.
                                    942 ;	../../fuzzy.h:1330: count == 0u
      000239 E5 08            [12]  943 	mov	a,_bp
      00023B 24 FC            [12]  944 	add	a,#0xfc
      00023D F8               [12]  945 	mov	r0,a
      00023E E6               [12]  946 	mov	a,@r0
      00023F 08               [12]  947 	inc	r0
      000240 46               [12]  948 	orl	a,@r0
      000241 70 0B            [24]  949 	jnz	00102$
      000243                        950 00101$:
                           00018C   951 	C$fuzzy.h$1332$2_0$37 ==.
                                    952 ;	../../fuzzy.h:1332: return LEVEL_HI;
      000243 90 00 00         [24]  953 	mov	dptr,#0x0000
      000246 75 F0 80         [24]  954 	mov	b, #0x80
      000249 74 3F            [12]  955 	mov	a, #0x3f
      00024B 02 04 BC         [24]  956 	ljmp	00121$
      00024E                        957 00102$:
                           000197   958 	C$fuzzy.h$1336$1_0$36 ==.
                                    959 ;	../../fuzzy.h:1336: method != FUZZY_LOGIC_STANDARD &&
      00024E ED               [12]  960 	mov	a,r5
      00024F 60 13            [24]  961 	jz	00105$
                           00019A   962 	C$fuzzy.h$1337$1_0$36 ==.
                                    963 ;	../../fuzzy.h:1337: method != FUZZY_LOGIC_ALGEBRAIC &&
      000251 BD 01 02         [24]  964 	cjne	r5,#0x01,00192$
      000254 80 0E            [24]  965 	sjmp	00105$
      000256                        966 00192$:
                           00019F   967 	C$fuzzy.h$1339$1_0$36 ==.
                                    968 ;	../../fuzzy.h:1339: ) {
      000256 BD 02 02         [24]  969 	cjne	r5,#0x02,00193$
      000259 80 09            [24]  970 	sjmp	00105$
      00025B                        971 00193$:
                           0001A4   972 	C$fuzzy.h$1340$2_0$38 ==.
                                    973 ;	../../fuzzy.h:1340: return LEVEL_LO;
      00025B 90 00 00         [24]  974 	mov	dptr,#0x0000
      00025E E4               [12]  975 	clr	a
      00025F F5 F0            [12]  976 	mov	b,a
      000261 02 04 BC         [24]  977 	ljmp	00121$
      000264                        978 00105$:
                           0001AD   979 	C$fuzzy.h$1345$1_0$36 ==.
                                    980 ;	../../fuzzy.h:1345: args[0]
      000264 E5 08            [12]  981 	mov	a,_bp
      000266 24 F9            [12]  982 	add	a,#0xf9
      000268 F8               [12]  983 	mov	r0,a
      000269 A9 08            [24]  984 	mov	r1,_bp
      00026B 09               [12]  985 	inc	r1
      00026C E6               [12]  986 	mov	a,@r0
      00026D F7               [12]  987 	mov	@r1,a
      00026E 08               [12]  988 	inc	r0
      00026F E6               [12]  989 	mov	a,@r0
      000270 09               [12]  990 	inc	r1
      000271 F7               [12]  991 	mov	@r1,a
      000272 08               [12]  992 	inc	r0
      000273 E6               [12]  993 	mov	a,@r0
      000274 09               [12]  994 	inc	r1
      000275 F7               [12]  995 	mov	@r1,a
      000276 A8 08            [24]  996 	mov	r0,_bp
      000278 08               [12]  997 	inc	r0
      000279 86 82            [24]  998 	mov	dpl,@r0
      00027B 08               [12]  999 	inc	r0
      00027C 86 83            [24] 1000 	mov	dph,@r0
      00027E 08               [12] 1001 	inc	r0
      00027F 86 F0            [24] 1002 	mov	b,@r0
      000281 12 37 EE         [24] 1003 	lcall	__gptrget
      000284 FA               [12] 1004 	mov	r2,a
      000285 A3               [24] 1005 	inc	dptr
      000286 12 37 EE         [24] 1006 	lcall	__gptrget
      000289 FB               [12] 1007 	mov	r3,a
      00028A A3               [24] 1008 	inc	dptr
      00028B 12 37 EE         [24] 1009 	lcall	__gptrget
      00028E FE               [12] 1010 	mov	r6,a
      00028F A3               [24] 1011 	inc	dptr
      000290 12 37 EE         [24] 1012 	lcall	__gptrget
      000293 8A 82            [24] 1013 	mov	dpl,r2
      000295 8B 83            [24] 1014 	mov	dph,r3
      000297 8E F0            [24] 1015 	mov	b,r6
      000299 C0 05            [24] 1016 	push	ar5
      00029B 12 00 EA         [24] 1017 	lcall	_fuzzy_clamp
      00029E C8               [12] 1018 	xch	a,r0
      00029F E5 08            [12] 1019 	mov	a,_bp
      0002A1 24 05            [12] 1020 	add	a,#0x05
      0002A3 C8               [12] 1021 	xch	a,r0
      0002A4 A6 82            [24] 1022 	mov	@r0, dpl
      0002A6 08               [12] 1023 	inc	r0
      0002A7 A6 83            [24] 1024 	mov	@r0, dph
      0002A9 08               [12] 1025 	inc	r0
      0002AA A6 F0            [24] 1026 	mov	@r0, b
      0002AC 08               [12] 1027 	inc	r0
      0002AD F6               [12] 1028 	mov	@r0,a
      0002AE D0 05            [24] 1029 	pop	ar5
                           0001F9  1030 	C$fuzzy.h$1349$3_0$40 ==.
                                   1031 ;	../../fuzzy.h:1349: index = 1u;
      0002B0 E4               [12] 1032 	clr	a
      0002B1 BD 00 01         [24] 1033 	cjne	r5,#0x00,00194$
      0002B4 04               [12] 1034 	inc	a
      0002B5                       1035 00194$:
      0002B5 FB               [12] 1036 	mov	r3,a
      0002B6 BD 01 03         [24] 1037 	cjne	r5,#0x01,00196$
      0002B9 ED               [12] 1038 	mov	a,r5
      0002BA 80 01            [24] 1039 	sjmp	00197$
      0002BC                       1040 00196$:
      0002BC E4               [12] 1041 	clr	a
      0002BD                       1042 00197$:
      0002BD FA               [12] 1043 	mov	r2,a
      0002BE E5 08            [12] 1044 	mov	a,_bp
      0002C0 24 04            [12] 1045 	add	a,#0x04
      0002C2 F8               [12] 1046 	mov	r0,a
      0002C3 E4               [12] 1047 	clr	a
      0002C4 BD 02 01         [24] 1048 	cjne	r5,#0x02,00198$
      0002C7 04               [12] 1049 	inc	a
      0002C8                       1050 00198$:
      0002C8 F6               [12] 1051 	mov	@r0,a
      0002C9 E5 08            [12] 1052 	mov	a,_bp
      0002CB 24 0D            [12] 1053 	add	a,#0x0d
      0002CD F8               [12] 1054 	mov	r0,a
      0002CE 76 01            [12] 1055 	mov	@r0,#0x01
      0002D0 08               [12] 1056 	inc	r0
      0002D1 76 00            [12] 1057 	mov	@r0,#0x00
      0002D3                       1058 00119$:
                           00021C  1059 	C$fuzzy.h$1350$2_0$39 ==.
                                   1060 ;	../../fuzzy.h:1350: index < count;
      0002D3 E5 08            [12] 1061 	mov	a,_bp
      0002D5 24 0D            [12] 1062 	add	a,#0x0d
      0002D7 F8               [12] 1063 	mov	r0,a
      0002D8 E5 08            [12] 1064 	mov	a,_bp
      0002DA 24 FC            [12] 1065 	add	a,#0xfc
      0002DC F9               [12] 1066 	mov	r1,a
      0002DD C3               [12] 1067 	clr	c
      0002DE E6               [12] 1068 	mov	a,@r0
      0002DF 97               [12] 1069 	subb	a,@r1
      0002E0 08               [12] 1070 	inc	r0
      0002E1 E6               [12] 1071 	mov	a,@r0
      0002E2 09               [12] 1072 	inc	r1
      0002E3 97               [12] 1073 	subb	a,@r1
      0002E4 40 03            [24] 1074 	jc	00200$
      0002E6 02 04 AA         [24] 1075 	ljmp	00117$
      0002E9                       1076 00200$:
                           000232  1077 	C$fuzzy.h$1355$1_0$36 ==.
                                   1078 ;	../../fuzzy.h:1355: args[index]
      0002E9 C0 02            [24] 1079 	push	ar2
      0002EB E5 08            [12] 1080 	mov	a,_bp
      0002ED 24 0D            [12] 1081 	add	a,#0x0d
      0002EF F8               [12] 1082 	mov	r0,a
      0002F0 E6               [12] 1083 	mov	a,@r0
      0002F1 26               [12] 1084 	add	a,@r0
      0002F2 FD               [12] 1085 	mov	r5,a
      0002F3 08               [12] 1086 	inc	r0
      0002F4 E6               [12] 1087 	mov	a,@r0
      0002F5 33               [12] 1088 	rlc	a
      0002F6 FC               [12] 1089 	mov	r4,a
      0002F7 ED               [12] 1090 	mov	a,r5
      0002F8 2D               [12] 1091 	add	a,r5
      0002F9 FD               [12] 1092 	mov	r5,a
      0002FA EC               [12] 1093 	mov	a,r4
      0002FB 33               [12] 1094 	rlc	a
      0002FC FC               [12] 1095 	mov	r4,a
      0002FD A8 08            [24] 1096 	mov	r0,_bp
      0002FF 08               [12] 1097 	inc	r0
      000300 ED               [12] 1098 	mov	a,r5
      000301 26               [12] 1099 	add	a, @r0
      000302 FA               [12] 1100 	mov	r2,a
      000303 EC               [12] 1101 	mov	a,r4
      000304 08               [12] 1102 	inc	r0
      000305 36               [12] 1103 	addc	a, @r0
      000306 FC               [12] 1104 	mov	r4,a
      000307 08               [12] 1105 	inc	r0
      000308 86 05            [24] 1106 	mov	ar5,@r0
      00030A 8A 82            [24] 1107 	mov	dpl,r2
      00030C 8C 83            [24] 1108 	mov	dph,r4
      00030E 8D F0            [24] 1109 	mov	b,r5
      000310 12 37 EE         [24] 1110 	lcall	__gptrget
      000313 FA               [12] 1111 	mov	r2,a
      000314 A3               [24] 1112 	inc	dptr
      000315 12 37 EE         [24] 1113 	lcall	__gptrget
      000318 FC               [12] 1114 	mov	r4,a
      000319 A3               [24] 1115 	inc	dptr
      00031A 12 37 EE         [24] 1116 	lcall	__gptrget
      00031D FD               [12] 1117 	mov	r5,a
      00031E A3               [24] 1118 	inc	dptr
      00031F 12 37 EE         [24] 1119 	lcall	__gptrget
      000322 8A 82            [24] 1120 	mov	dpl,r2
      000324 8C 83            [24] 1121 	mov	dph,r4
      000326 8D F0            [24] 1122 	mov	b,r5
      000328 C0 03            [24] 1123 	push	ar3
      00032A C0 02            [24] 1124 	push	ar2
      00032C 12 00 EA         [24] 1125 	lcall	_fuzzy_clamp
      00032F C8               [12] 1126 	xch	a,r0
      000330 E5 08            [12] 1127 	mov	a,_bp
      000332 24 09            [12] 1128 	add	a,#0x09
      000334 C8               [12] 1129 	xch	a,r0
      000335 A6 82            [24] 1130 	mov	@r0, dpl
      000337 08               [12] 1131 	inc	r0
      000338 A6 83            [24] 1132 	mov	@r0, dph
      00033A 08               [12] 1133 	inc	r0
      00033B A6 F0            [24] 1134 	mov	@r0, b
      00033D 08               [12] 1135 	inc	r0
      00033E F6               [12] 1136 	mov	@r0,a
      00033F D0 02            [24] 1137 	pop	ar2
      000341 D0 03            [24] 1138 	pop	ar3
                           00028C  1139 	C$fuzzy.h$1358$1_0$36 ==.
                                   1140 ;	../../fuzzy.h:1358: switch (method) {
      000343 D0 02            [24] 1141 	pop	ar2
      000345 EB               [12] 1142 	mov	a,r3
      000346 70 11            [24] 1143 	jnz	00108$
      000348 EA               [12] 1144 	mov	a,r2
      000349 70 65            [24] 1145 	jnz	00111$
      00034B E5 08            [12] 1146 	mov	a,_bp
      00034D 24 04            [12] 1147 	add	a,#0x04
      00034F F8               [12] 1148 	mov	r0,a
      000350 E6               [12] 1149 	mov	a,@r0
      000351 60 03            [24] 1150 	jz	00203$
      000353 02 03 F7         [24] 1151 	ljmp	00112$
      000356                       1152 00203$:
      000356 02 04 94         [24] 1153 	ljmp	00115$
                           0002A2  1154 	C$fuzzy.h$1359$4_0$41 ==.
                                   1155 ;	../../fuzzy.h:1359: case FUZZY_LOGIC_STANDARD:
      000359                       1156 00108$:
                           0002A2  1157 	C$fuzzy.h$1360$1_0$36 ==.
                                   1158 ;	../../fuzzy.h:1360: if (next < result) {
      000359 C0 03            [24] 1159 	push	ar3
      00035B C0 02            [24] 1160 	push	ar2
      00035D E5 08            [12] 1161 	mov	a,_bp
      00035F 24 05            [12] 1162 	add	a,#0x05
      000361 F8               [12] 1163 	mov	r0,a
      000362 E6               [12] 1164 	mov	a,@r0
      000363 C0 E0            [24] 1165 	push	acc
      000365 08               [12] 1166 	inc	r0
      000366 E6               [12] 1167 	mov	a,@r0
      000367 C0 E0            [24] 1168 	push	acc
      000369 08               [12] 1169 	inc	r0
      00036A E6               [12] 1170 	mov	a,@r0
      00036B C0 E0            [24] 1171 	push	acc
      00036D 08               [12] 1172 	inc	r0
      00036E E6               [12] 1173 	mov	a,@r0
      00036F C0 E0            [24] 1174 	push	acc
      000371 E5 08            [12] 1175 	mov	a,_bp
      000373 24 09            [12] 1176 	add	a,#0x09
      000375 F8               [12] 1177 	mov	r0,a
      000376 86 82            [24] 1178 	mov	dpl, @r0
      000378 08               [12] 1179 	inc	r0
      000379 86 83            [24] 1180 	mov	dph, @r0
      00037B 08               [12] 1181 	inc	r0
      00037C 86 F0            [24] 1182 	mov	b, @r0
      00037E 08               [12] 1183 	inc	r0
      00037F E6               [12] 1184 	mov	a, @r0
      000380 12 35 C2         [24] 1185 	lcall	___fslt
      000383 AF 82            [24] 1186 	mov	r7, dpl
      000385 E5 81            [12] 1187 	mov	a,sp
      000387 24 FC            [12] 1188 	add	a,#0xfc
      000389 F5 81            [12] 1189 	mov	sp,a
      00038B D0 02            [24] 1190 	pop	ar2
      00038D D0 03            [24] 1191 	pop	ar3
      00038F EF               [12] 1192 	mov	a,r7
      000390 70 03            [24] 1193 	jnz	00204$
      000392 02 04 9C         [24] 1194 	ljmp	00120$
      000395                       1195 00204$:
                           0002DE  1196 	C$fuzzy.h$1361$5_0$42 ==.
                                   1197 ;	../../fuzzy.h:1361: result = next;
      000395 E5 08            [12] 1198 	mov	a,_bp
      000397 24 09            [12] 1199 	add	a,#0x09
      000399 F8               [12] 1200 	mov	r0,a
      00039A E5 08            [12] 1201 	mov	a,_bp
      00039C 24 05            [12] 1202 	add	a,#0x05
      00039E F9               [12] 1203 	mov	r1,a
      00039F E6               [12] 1204 	mov	a,@r0
      0003A0 F7               [12] 1205 	mov	@r1,a
      0003A1 08               [12] 1206 	inc	r0
      0003A2 E6               [12] 1207 	mov	a,@r0
      0003A3 09               [12] 1208 	inc	r1
      0003A4 F7               [12] 1209 	mov	@r1,a
      0003A5 08               [12] 1210 	inc	r0
      0003A6 E6               [12] 1211 	mov	a,@r0
      0003A7 09               [12] 1212 	inc	r1
      0003A8 F7               [12] 1213 	mov	@r1,a
      0003A9 08               [12] 1214 	inc	r0
      0003AA E6               [12] 1215 	mov	a,@r0
      0003AB 09               [12] 1216 	inc	r1
      0003AC F7               [12] 1217 	mov	@r1,a
                           0002F6  1218 	C$fuzzy.h$1363$4_0$41 ==.
                                   1219 ;	../../fuzzy.h:1363: break;
      0003AD 02 04 9C         [24] 1220 	ljmp	00120$
                           0002F9  1221 	C$fuzzy.h$1365$4_0$41 ==.
                                   1222 ;	../../fuzzy.h:1365: case FUZZY_LOGIC_ALGEBRAIC:
      0003B0                       1223 00111$:
                           0002F9  1224 	C$fuzzy.h$1367$1_0$36 ==.
                                   1225 ;	../../fuzzy.h:1367: next;
      0003B0 C0 03            [24] 1226 	push	ar3
      0003B2 C0 02            [24] 1227 	push	ar2
      0003B4 E5 08            [12] 1228 	mov	a,_bp
      0003B6 24 09            [12] 1229 	add	a,#0x09
      0003B8 F8               [12] 1230 	mov	r0,a
      0003B9 E6               [12] 1231 	mov	a,@r0
      0003BA C0 E0            [24] 1232 	push	acc
      0003BC 08               [12] 1233 	inc	r0
      0003BD E6               [12] 1234 	mov	a,@r0
      0003BE C0 E0            [24] 1235 	push	acc
      0003C0 08               [12] 1236 	inc	r0
      0003C1 E6               [12] 1237 	mov	a,@r0
      0003C2 C0 E0            [24] 1238 	push	acc
      0003C4 08               [12] 1239 	inc	r0
      0003C5 E6               [12] 1240 	mov	a,@r0
      0003C6 C0 E0            [24] 1241 	push	acc
                           000311  1242 	C$fuzzy.h$1368$1_0$36 ==.
                                   1243 ;	../../fuzzy.h:1368: break;
      0003C8 E5 08            [12] 1244 	mov	a,_bp
      0003CA 24 05            [12] 1245 	add	a,#0x05
      0003CC F8               [12] 1246 	mov	r0,a
      0003CD 86 82            [24] 1247 	mov	dpl, @r0
      0003CF 08               [12] 1248 	inc	r0
      0003D0 86 83            [24] 1249 	mov	dph, @r0
      0003D2 08               [12] 1250 	inc	r0
      0003D3 86 F0            [24] 1251 	mov	b, @r0
      0003D5 08               [12] 1252 	inc	r0
      0003D6 E6               [12] 1253 	mov	a, @r0
      0003D7 12 34 92         [24] 1254 	lcall	___fsmul
      0003DA C8               [12] 1255 	xch	a,r0
      0003DB E5 08            [12] 1256 	mov	a,_bp
      0003DD 24 05            [12] 1257 	add	a,#0x05
      0003DF C8               [12] 1258 	xch	a,r0
      0003E0 A6 82            [24] 1259 	mov	@r0, dpl
      0003E2 08               [12] 1260 	inc	r0
      0003E3 A6 83            [24] 1261 	mov	@r0, dph
      0003E5 08               [12] 1262 	inc	r0
      0003E6 A6 F0            [24] 1263 	mov	@r0, b
      0003E8 08               [12] 1264 	inc	r0
      0003E9 F6               [12] 1265 	mov	@r0,a
      0003EA E5 81            [12] 1266 	mov	a,sp
      0003EC 24 FC            [12] 1267 	add	a,#0xfc
      0003EE F5 81            [12] 1268 	mov	sp,a
      0003F0 D0 02            [24] 1269 	pop	ar2
      0003F2 D0 03            [24] 1270 	pop	ar3
      0003F4 02 04 9C         [24] 1271 	ljmp	00120$
                           000340  1272 	C$fuzzy.h$1370$4_0$41 ==.
                                   1273 ;	../../fuzzy.h:1370: case FUZZY_LOGIC_BOUNDED:
      0003F7                       1274 00112$:
                           000340  1275 	C$fuzzy.h$1373$1_0$36 ==.
                                   1276 ;	../../fuzzy.h:1373: next -
      0003F7 C0 03            [24] 1277 	push	ar3
      0003F9 C0 02            [24] 1278 	push	ar2
      0003FB E5 08            [12] 1279 	mov	a,_bp
      0003FD 24 09            [12] 1280 	add	a,#0x09
      0003FF F8               [12] 1281 	mov	r0,a
      000400 E6               [12] 1282 	mov	a,@r0
      000401 C0 E0            [24] 1283 	push	acc
      000403 08               [12] 1284 	inc	r0
      000404 E6               [12] 1285 	mov	a,@r0
      000405 C0 E0            [24] 1286 	push	acc
      000407 08               [12] 1287 	inc	r0
      000408 E6               [12] 1288 	mov	a,@r0
      000409 C0 E0            [24] 1289 	push	acc
      00040B 08               [12] 1290 	inc	r0
      00040C E6               [12] 1291 	mov	a,@r0
      00040D C0 E0            [24] 1292 	push	acc
      00040F E5 08            [12] 1293 	mov	a,_bp
      000411 24 05            [12] 1294 	add	a,#0x05
      000413 F8               [12] 1295 	mov	r0,a
      000414 86 82            [24] 1296 	mov	dpl, @r0
      000416 08               [12] 1297 	inc	r0
      000417 86 83            [24] 1298 	mov	dph, @r0
      000419 08               [12] 1299 	inc	r0
      00041A 86 F0            [24] 1300 	mov	b, @r0
      00041C 08               [12] 1301 	inc	r0
      00041D E6               [12] 1302 	mov	a, @r0
      00041E 12 36 14         [24] 1303 	lcall	___fsadd
      000421 AC 82            [24] 1304 	mov	r4, dpl
      000423 AD 83            [24] 1305 	mov	r5, dph
      000425 AE F0            [24] 1306 	mov	r6, b
      000427 FF               [12] 1307 	mov	r7, a
      000428 E5 81            [12] 1308 	mov	a,sp
      00042A 24 FC            [12] 1309 	add	a,#0xfc
      00042C F5 81            [12] 1310 	mov	sp,a
      00042E E4               [12] 1311 	clr	a
      00042F C0 E0            [24] 1312 	push	acc
      000431 C0 E0            [24] 1313 	push	acc
      000433 74 80            [12] 1314 	mov	a,#0x80
      000435 C0 E0            [24] 1315 	push	acc
      000437 74 3F            [12] 1316 	mov	a,#0x3f
      000439 C0 E0            [24] 1317 	push	acc
                           000384  1318 	C$fuzzy.h$1376$1_0$36 ==.
                                   1319 ;	../../fuzzy.h:1376: if (result < LEVEL_LO) {
      00043B 8C 82            [24] 1320 	mov	dpl, r4
      00043D 8D 83            [24] 1321 	mov	dph, r5
      00043F 8E F0            [24] 1322 	mov	b, r6
      000441 EF               [12] 1323 	mov	a, r7
      000442 12 34 87         [24] 1324 	lcall	___fssub
      000445 C8               [12] 1325 	xch	a,r0
      000446 E5 08            [12] 1326 	mov	a,_bp
      000448 24 05            [12] 1327 	add	a,#0x05
      00044A C8               [12] 1328 	xch	a,r0
      00044B A6 82            [24] 1329 	mov	@r0, dpl
      00044D 08               [12] 1330 	inc	r0
      00044E A6 83            [24] 1331 	mov	@r0, dph
      000450 08               [12] 1332 	inc	r0
      000451 A6 F0            [24] 1333 	mov	@r0, b
      000453 08               [12] 1334 	inc	r0
      000454 F6               [12] 1335 	mov	@r0,a
      000455 E5 81            [12] 1336 	mov	a,sp
      000457 24 FC            [12] 1337 	add	a,#0xfc
      000459 F5 81            [12] 1338 	mov	sp,a
      00045B E4               [12] 1339 	clr	a
      00045C C0 E0            [24] 1340 	push	acc
      00045E C0 E0            [24] 1341 	push	acc
      000460 C0 E0            [24] 1342 	push	acc
      000462 C0 E0            [24] 1343 	push	acc
      000464 E5 08            [12] 1344 	mov	a,_bp
      000466 24 05            [12] 1345 	add	a,#0x05
      000468 F8               [12] 1346 	mov	r0,a
      000469 86 82            [24] 1347 	mov	dpl, @r0
      00046B 08               [12] 1348 	inc	r0
      00046C 86 83            [24] 1349 	mov	dph, @r0
      00046E 08               [12] 1350 	inc	r0
      00046F 86 F0            [24] 1351 	mov	b, @r0
      000471 08               [12] 1352 	inc	r0
      000472 E6               [12] 1353 	mov	a, @r0
      000473 12 35 C2         [24] 1354 	lcall	___fslt
      000476 AF 82            [24] 1355 	mov	r7, dpl
      000478 E5 81            [12] 1356 	mov	a,sp
      00047A 24 FC            [12] 1357 	add	a,#0xfc
      00047C F5 81            [12] 1358 	mov	sp,a
      00047E D0 02            [24] 1359 	pop	ar2
      000480 D0 03            [24] 1360 	pop	ar3
      000482 EF               [12] 1361 	mov	a,r7
      000483 60 17            [24] 1362 	jz	00120$
                           0003CE  1363 	C$fuzzy.h$1377$5_0$43 ==.
                                   1364 ;	../../fuzzy.h:1377: result = LEVEL_LO;
      000485 E5 08            [12] 1365 	mov	a,_bp
      000487 24 05            [12] 1366 	add	a,#0x05
      000489 F8               [12] 1367 	mov	r0,a
      00048A E4               [12] 1368 	clr	a
      00048B F6               [12] 1369 	mov	@r0,a
      00048C 08               [12] 1370 	inc	r0
      00048D F6               [12] 1371 	mov	@r0,a
      00048E 08               [12] 1372 	inc	r0
      00048F F6               [12] 1373 	mov	@r0,a
      000490 08               [12] 1374 	inc	r0
      000491 F6               [12] 1375 	mov	@r0,a
                           0003DB  1376 	C$fuzzy.h$1379$4_0$41 ==.
                                   1377 ;	../../fuzzy.h:1379: break;
                           0003DB  1378 	C$fuzzy.h$1381$4_0$41 ==.
                                   1379 ;	../../fuzzy.h:1381: default:
      000492 80 08            [24] 1380 	sjmp	00120$
      000494                       1381 00115$:
                           0003DD  1382 	C$fuzzy.h$1382$4_0$41 ==.
                                   1383 ;	../../fuzzy.h:1382: return LEVEL_LO;
      000494 90 00 00         [24] 1384 	mov	dptr,#0x0000
      000497 E4               [12] 1385 	clr	a
      000498 F5 F0            [12] 1386 	mov	b,a
                           0003E3  1387 	C$fuzzy.h$1383$3_0$40 ==.
                                   1388 ;	../../fuzzy.h:1383: }
      00049A 80 20            [24] 1389 	sjmp	00121$
      00049C                       1390 00120$:
                           0003E5  1391 	C$fuzzy.h$1351$2_0$39 ==.
                                   1392 ;	../../fuzzy.h:1351: index++
      00049C E5 08            [12] 1393 	mov	a,_bp
      00049E 24 0D            [12] 1394 	add	a,#0x0d
      0004A0 F8               [12] 1395 	mov	r0,a
      0004A1 06               [12] 1396 	inc	@r0
      0004A2 B6 00 02         [24] 1397 	cjne	@r0,#0x00,00206$
      0004A5 08               [12] 1398 	inc	r0
      0004A6 06               [12] 1399 	inc	@r0
      0004A7                       1400 00206$:
      0004A7 02 02 D3         [24] 1401 	ljmp	00119$
      0004AA                       1402 00117$:
                           0003F3  1403 	C$fuzzy.h$1387$1_0$36 ==.
                                   1404 ;	../../fuzzy.h:1387: result
      0004AA E5 08            [12] 1405 	mov	a,_bp
      0004AC 24 05            [12] 1406 	add	a,#0x05
      0004AE F8               [12] 1407 	mov	r0,a
      0004AF 86 82            [24] 1408 	mov	dpl, @r0
      0004B1 08               [12] 1409 	inc	r0
      0004B2 86 83            [24] 1410 	mov	dph, @r0
      0004B4 08               [12] 1411 	inc	r0
      0004B5 86 F0            [24] 1412 	mov	b, @r0
      0004B7 08               [12] 1413 	inc	r0
      0004B8 E6               [12] 1414 	mov	a, @r0
      0004B9 12 00 EA         [24] 1415 	lcall	_fuzzy_clamp
      0004BC                       1416 00121$:
                           000405  1417 	C$fuzzy.h$1389$1_0$36 ==.
                                   1418 ;	../../fuzzy.h:1389: }
      0004BC 85 08 81         [24] 1419 	mov	sp,_bp
      0004BF D0 08            [24] 1420 	pop	_bp
                           00040A  1421 	C$fuzzy.h$1389$1_0$36 ==.
                           00040A  1422 	XG$fuzzy_and_array$0$0 ==.
      0004C1 22               [24] 1423 	ret
                                   1424 ;------------------------------------------------------------
                                   1425 ;Allocation info for local variables in function 'fuzzy_or_array'
                                   1426 ;------------------------------------------------------------
                                   1427 ;count         Allocated to stack - _bp -4 +2 
                                   1428 ;args          Allocated to stack - _bp -7 +3 
                                   1429 ;method        Allocated to registers r5 
                                   1430 ;result        Allocated to stack - _bp +10 +4 
                                   1431 ;next          Allocated to registers r4 r5 r6 r3 
                                   1432 ;index         Allocated to stack - _bp +14 +2 
                                   1433 ;sloc0         Allocated to stack - _bp +1 +3 
                                   1434 ;sloc1         Allocated to stack - _bp +4 +1 
                                   1435 ;sloc2         Allocated to stack - _bp +5 +1 
                                   1436 ;sloc3         Allocated to stack - _bp +6 +4 
                                   1437 ;------------------------------------------------------------
                           00040B  1438 	G$fuzzy_or_array$0$0 ==.
                           00040B  1439 	C$fuzzy.h$1404$1_0$45 ==.
                                   1440 ;	../../fuzzy.h:1404: float fuzzy_or_array(
                                   1441 ;	-----------------------------------------
                                   1442 ;	 function fuzzy_or_array
                                   1443 ;	-----------------------------------------
      0004C2                       1444 _fuzzy_or_array:
      0004C2 C0 08            [24] 1445 	push	_bp
      0004C4 E5 81            [12] 1446 	mov	a,sp
      0004C6 F5 08            [12] 1447 	mov	_bp,a
      0004C8 24 0F            [12] 1448 	add	a,#0x0f
      0004CA F5 81            [12] 1449 	mov	sp,a
      0004CC AD 82            [24] 1450 	mov	r5, dpl
                           000417  1451 	C$fuzzy.h$1415$1_0$45 ==.
                                   1452 ;	../../fuzzy.h:1415: args == NULL ||
      0004CE E5 08            [12] 1453 	mov	a,_bp
      0004D0 24 F9            [12] 1454 	add	a,#0xf9
      0004D2 F8               [12] 1455 	mov	r0,a
      0004D3 E6               [12] 1456 	mov	a,@r0
      0004D4 08               [12] 1457 	inc	r0
      0004D5 46               [12] 1458 	orl	a,@r0
      0004D6 60 0A            [24] 1459 	jz	00101$
                           000421  1460 	C$fuzzy.h$1416$1_0$45 ==.
                                   1461 ;	../../fuzzy.h:1416: count == 0u
      0004D8 E5 08            [12] 1462 	mov	a,_bp
      0004DA 24 FC            [12] 1463 	add	a,#0xfc
      0004DC F8               [12] 1464 	mov	r0,a
      0004DD E6               [12] 1465 	mov	a,@r0
      0004DE 08               [12] 1466 	inc	r0
      0004DF 46               [12] 1467 	orl	a,@r0
      0004E0 70 09            [24] 1468 	jnz	00102$
      0004E2                       1469 00101$:
                           00042B  1470 	C$fuzzy.h$1418$2_0$46 ==.
                                   1471 ;	../../fuzzy.h:1418: return LEVEL_LO;
      0004E2 90 00 00         [24] 1472 	mov	dptr,#0x0000
      0004E5 E4               [12] 1473 	clr	a
      0004E6 F5 F0            [12] 1474 	mov	b,a
      0004E8 02 07 7E         [24] 1475 	ljmp	00121$
      0004EB                       1476 00102$:
                           000434  1477 	C$fuzzy.h$1422$1_0$45 ==.
                                   1478 ;	../../fuzzy.h:1422: method != FUZZY_LOGIC_STANDARD &&
      0004EB ED               [12] 1479 	mov	a,r5
      0004EC 60 13            [24] 1480 	jz	00105$
                           000437  1481 	C$fuzzy.h$1423$1_0$45 ==.
                                   1482 ;	../../fuzzy.h:1423: method != FUZZY_LOGIC_ALGEBRAIC &&
      0004EE BD 01 02         [24] 1483 	cjne	r5,#0x01,00192$
      0004F1 80 0E            [24] 1484 	sjmp	00105$
      0004F3                       1485 00192$:
                           00043C  1486 	C$fuzzy.h$1425$1_0$45 ==.
                                   1487 ;	../../fuzzy.h:1425: ) {
      0004F3 BD 02 02         [24] 1488 	cjne	r5,#0x02,00193$
      0004F6 80 09            [24] 1489 	sjmp	00105$
      0004F8                       1490 00193$:
                           000441  1491 	C$fuzzy.h$1426$2_0$47 ==.
                                   1492 ;	../../fuzzy.h:1426: return LEVEL_LO;
      0004F8 90 00 00         [24] 1493 	mov	dptr,#0x0000
      0004FB E4               [12] 1494 	clr	a
      0004FC F5 F0            [12] 1495 	mov	b,a
      0004FE 02 07 7E         [24] 1496 	ljmp	00121$
      000501                       1497 00105$:
                           00044A  1498 	C$fuzzy.h$1431$1_0$45 ==.
                                   1499 ;	../../fuzzy.h:1431: args[0]
      000501 E5 08            [12] 1500 	mov	a,_bp
      000503 24 F9            [12] 1501 	add	a,#0xf9
      000505 F8               [12] 1502 	mov	r0,a
      000506 A9 08            [24] 1503 	mov	r1,_bp
      000508 09               [12] 1504 	inc	r1
      000509 E6               [12] 1505 	mov	a,@r0
      00050A F7               [12] 1506 	mov	@r1,a
      00050B 08               [12] 1507 	inc	r0
      00050C E6               [12] 1508 	mov	a,@r0
      00050D 09               [12] 1509 	inc	r1
      00050E F7               [12] 1510 	mov	@r1,a
      00050F 08               [12] 1511 	inc	r0
      000510 E6               [12] 1512 	mov	a,@r0
      000511 09               [12] 1513 	inc	r1
      000512 F7               [12] 1514 	mov	@r1,a
      000513 A8 08            [24] 1515 	mov	r0,_bp
      000515 08               [12] 1516 	inc	r0
      000516 86 82            [24] 1517 	mov	dpl,@r0
      000518 08               [12] 1518 	inc	r0
      000519 86 83            [24] 1519 	mov	dph,@r0
      00051B 08               [12] 1520 	inc	r0
      00051C 86 F0            [24] 1521 	mov	b,@r0
      00051E 12 37 EE         [24] 1522 	lcall	__gptrget
      000521 FA               [12] 1523 	mov	r2,a
      000522 A3               [24] 1524 	inc	dptr
      000523 12 37 EE         [24] 1525 	lcall	__gptrget
      000526 FB               [12] 1526 	mov	r3,a
      000527 A3               [24] 1527 	inc	dptr
      000528 12 37 EE         [24] 1528 	lcall	__gptrget
      00052B FE               [12] 1529 	mov	r6,a
      00052C A3               [24] 1530 	inc	dptr
      00052D 12 37 EE         [24] 1531 	lcall	__gptrget
      000530 8A 82            [24] 1532 	mov	dpl,r2
      000532 8B 83            [24] 1533 	mov	dph,r3
      000534 8E F0            [24] 1534 	mov	b,r6
      000536 C0 05            [24] 1535 	push	ar5
      000538 12 00 EA         [24] 1536 	lcall	_fuzzy_clamp
      00053B C8               [12] 1537 	xch	a,r0
      00053C E5 08            [12] 1538 	mov	a,_bp
      00053E 24 0A            [12] 1539 	add	a,#0x0a
      000540 C8               [12] 1540 	xch	a,r0
      000541 A6 82            [24] 1541 	mov	@r0, dpl
      000543 08               [12] 1542 	inc	r0
      000544 A6 83            [24] 1543 	mov	@r0, dph
      000546 08               [12] 1544 	inc	r0
      000547 A6 F0            [24] 1545 	mov	@r0, b
      000549 08               [12] 1546 	inc	r0
      00054A F6               [12] 1547 	mov	@r0,a
      00054B D0 05            [24] 1548 	pop	ar5
                           000496  1549 	C$fuzzy.h$1435$3_0$49 ==.
                                   1550 ;	../../fuzzy.h:1435: index = 1u;
      00054D E5 08            [12] 1551 	mov	a,_bp
      00054F 24 05            [12] 1552 	add	a,#0x05
      000551 F8               [12] 1553 	mov	r0,a
      000552 E4               [12] 1554 	clr	a
      000553 BD 00 01         [24] 1555 	cjne	r5,#0x00,00194$
      000556 04               [12] 1556 	inc	a
      000557                       1557 00194$:
      000557 F6               [12] 1558 	mov	@r0,a
      000558 BD 01 03         [24] 1559 	cjne	r5,#0x01,00196$
      00055B ED               [12] 1560 	mov	a,r5
      00055C 80 01            [24] 1561 	sjmp	00197$
      00055E                       1562 00196$:
      00055E E4               [12] 1563 	clr	a
      00055F                       1564 00197$:
      00055F FA               [12] 1565 	mov	r2,a
      000560 E5 08            [12] 1566 	mov	a,_bp
      000562 24 04            [12] 1567 	add	a,#0x04
      000564 F8               [12] 1568 	mov	r0,a
      000565 E4               [12] 1569 	clr	a
      000566 BD 02 01         [24] 1570 	cjne	r5,#0x02,00198$
      000569 04               [12] 1571 	inc	a
      00056A                       1572 00198$:
      00056A F6               [12] 1573 	mov	@r0,a
      00056B E5 08            [12] 1574 	mov	a,_bp
      00056D 24 0E            [12] 1575 	add	a,#0x0e
      00056F F8               [12] 1576 	mov	r0,a
      000570 76 01            [12] 1577 	mov	@r0,#0x01
      000572 08               [12] 1578 	inc	r0
      000573 76 00            [12] 1579 	mov	@r0,#0x00
      000575                       1580 00119$:
                           0004BE  1581 	C$fuzzy.h$1436$2_0$48 ==.
                                   1582 ;	../../fuzzy.h:1436: index < count;
      000575 E5 08            [12] 1583 	mov	a,_bp
      000577 24 0E            [12] 1584 	add	a,#0x0e
      000579 F8               [12] 1585 	mov	r0,a
      00057A E5 08            [12] 1586 	mov	a,_bp
      00057C 24 FC            [12] 1587 	add	a,#0xfc
      00057E F9               [12] 1588 	mov	r1,a
      00057F C3               [12] 1589 	clr	c
      000580 E6               [12] 1590 	mov	a,@r0
      000581 97               [12] 1591 	subb	a,@r1
      000582 08               [12] 1592 	inc	r0
      000583 E6               [12] 1593 	mov	a,@r0
      000584 09               [12] 1594 	inc	r1
      000585 97               [12] 1595 	subb	a,@r1
      000586 40 03            [24] 1596 	jc	00200$
      000588 02 07 6C         [24] 1597 	ljmp	00117$
      00058B                       1598 00200$:
                           0004D4  1599 	C$fuzzy.h$1441$1_0$45 ==.
                                   1600 ;	../../fuzzy.h:1441: args[index]
      00058B C0 02            [24] 1601 	push	ar2
      00058D E5 08            [12] 1602 	mov	a,_bp
      00058F 24 0E            [12] 1603 	add	a,#0x0e
      000591 F8               [12] 1604 	mov	r0,a
      000592 E6               [12] 1605 	mov	a,@r0
      000593 26               [12] 1606 	add	a,@r0
      000594 FD               [12] 1607 	mov	r5,a
      000595 08               [12] 1608 	inc	r0
      000596 E6               [12] 1609 	mov	a,@r0
      000597 33               [12] 1610 	rlc	a
      000598 FC               [12] 1611 	mov	r4,a
      000599 ED               [12] 1612 	mov	a,r5
      00059A 2D               [12] 1613 	add	a,r5
      00059B FD               [12] 1614 	mov	r5,a
      00059C EC               [12] 1615 	mov	a,r4
      00059D 33               [12] 1616 	rlc	a
      00059E FC               [12] 1617 	mov	r4,a
      00059F A8 08            [24] 1618 	mov	r0,_bp
      0005A1 08               [12] 1619 	inc	r0
      0005A2 ED               [12] 1620 	mov	a,r5
      0005A3 26               [12] 1621 	add	a, @r0
      0005A4 FA               [12] 1622 	mov	r2,a
      0005A5 EC               [12] 1623 	mov	a,r4
      0005A6 08               [12] 1624 	inc	r0
      0005A7 36               [12] 1625 	addc	a, @r0
      0005A8 FC               [12] 1626 	mov	r4,a
      0005A9 08               [12] 1627 	inc	r0
      0005AA 86 05            [24] 1628 	mov	ar5,@r0
      0005AC 8A 82            [24] 1629 	mov	dpl,r2
      0005AE 8C 83            [24] 1630 	mov	dph,r4
      0005B0 8D F0            [24] 1631 	mov	b,r5
      0005B2 12 37 EE         [24] 1632 	lcall	__gptrget
      0005B5 FA               [12] 1633 	mov	r2,a
      0005B6 A3               [24] 1634 	inc	dptr
      0005B7 12 37 EE         [24] 1635 	lcall	__gptrget
      0005BA FC               [12] 1636 	mov	r4,a
      0005BB A3               [24] 1637 	inc	dptr
      0005BC 12 37 EE         [24] 1638 	lcall	__gptrget
      0005BF FD               [12] 1639 	mov	r5,a
      0005C0 A3               [24] 1640 	inc	dptr
      0005C1 12 37 EE         [24] 1641 	lcall	__gptrget
      0005C4 8A 82            [24] 1642 	mov	dpl,r2
      0005C6 8C 83            [24] 1643 	mov	dph,r4
      0005C8 8D F0            [24] 1644 	mov	b,r5
      0005CA C0 02            [24] 1645 	push	ar2
      0005CC 12 00 EA         [24] 1646 	lcall	_fuzzy_clamp
      0005CF AC 82            [24] 1647 	mov	r4, dpl
      0005D1 AD 83            [24] 1648 	mov	r5, dph
      0005D3 AE F0            [24] 1649 	mov	r6, b
      0005D5 FB               [12] 1650 	mov	r3, a
      0005D6 D0 02            [24] 1651 	pop	ar2
                           000521  1652 	C$fuzzy.h$1444$1_0$45 ==.
                                   1653 ;	../../fuzzy.h:1444: switch (method) {
      0005D8 D0 02            [24] 1654 	pop	ar2
      0005DA E5 08            [12] 1655 	mov	a,_bp
      0005DC 24 05            [12] 1656 	add	a,#0x05
      0005DE F8               [12] 1657 	mov	r0,a
      0005DF E6               [12] 1658 	mov	a,@r0
      0005E0 70 11            [24] 1659 	jnz	00108$
      0005E2 EA               [12] 1660 	mov	a,r2
      0005E3 70 5D            [24] 1661 	jnz	00111$
      0005E5 E5 08            [12] 1662 	mov	a,_bp
      0005E7 24 04            [12] 1663 	add	a,#0x04
      0005E9 F8               [12] 1664 	mov	r0,a
      0005EA E6               [12] 1665 	mov	a,@r0
      0005EB 60 03            [24] 1666 	jz	00203$
      0005ED 02 06 E7         [24] 1667 	ljmp	00112$
      0005F0                       1668 00203$:
      0005F0 02 07 56         [24] 1669 	ljmp	00115$
                           00053C  1670 	C$fuzzy.h$1445$4_0$50 ==.
                                   1671 ;	../../fuzzy.h:1445: case FUZZY_LOGIC_STANDARD:
      0005F3                       1672 00108$:
                           00053C  1673 	C$fuzzy.h$1446$1_0$45 ==.
                                   1674 ;	../../fuzzy.h:1446: if (next > result) {
      0005F3 C0 06            [24] 1675 	push	ar6
      0005F5 C0 05            [24] 1676 	push	ar5
      0005F7 C0 04            [24] 1677 	push	ar4
      0005F9 C0 03            [24] 1678 	push	ar3
      0005FB C0 02            [24] 1679 	push	ar2
      0005FD C0 04            [24] 1680 	push	ar4
      0005FF C0 05            [24] 1681 	push	ar5
      000601 C0 06            [24] 1682 	push	ar6
      000603 C0 03            [24] 1683 	push	ar3
      000605 E5 08            [12] 1684 	mov	a,_bp
      000607 24 0A            [12] 1685 	add	a,#0x0a
      000609 F8               [12] 1686 	mov	r0,a
      00060A 86 82            [24] 1687 	mov	dpl, @r0
      00060C 08               [12] 1688 	inc	r0
      00060D 86 83            [24] 1689 	mov	dph, @r0
      00060F 08               [12] 1690 	inc	r0
      000610 86 F0            [24] 1691 	mov	b, @r0
      000612 08               [12] 1692 	inc	r0
      000613 E6               [12] 1693 	mov	a, @r0
      000614 12 35 C2         [24] 1694 	lcall	___fslt
      000617 AF 82            [24] 1695 	mov	r7, dpl
      000619 E5 81            [12] 1696 	mov	a,sp
      00061B 24 FC            [12] 1697 	add	a,#0xfc
      00061D F5 81            [12] 1698 	mov	sp,a
      00061F D0 02            [24] 1699 	pop	ar2
      000621 D0 03            [24] 1700 	pop	ar3
      000623 D0 04            [24] 1701 	pop	ar4
      000625 D0 05            [24] 1702 	pop	ar5
      000627 D0 06            [24] 1703 	pop	ar6
      000629 EF               [12] 1704 	mov	a,r7
      00062A 70 03            [24] 1705 	jnz	00204$
      00062C 02 07 5E         [24] 1706 	ljmp	00120$
      00062F                       1707 00204$:
                           000578  1708 	C$fuzzy.h$1447$5_0$51 ==.
                                   1709 ;	../../fuzzy.h:1447: result = next;
      00062F E5 08            [12] 1710 	mov	a,_bp
      000631 24 0A            [12] 1711 	add	a,#0x0a
      000633 F8               [12] 1712 	mov	r0,a
      000634 A6 04            [24] 1713 	mov	@r0,ar4
      000636 08               [12] 1714 	inc	r0
      000637 A6 05            [24] 1715 	mov	@r0,ar5
      000639 08               [12] 1716 	inc	r0
      00063A A6 06            [24] 1717 	mov	@r0,ar6
      00063C 08               [12] 1718 	inc	r0
      00063D A6 03            [24] 1719 	mov	@r0,ar3
                           000588  1720 	C$fuzzy.h$1449$4_0$50 ==.
                                   1721 ;	../../fuzzy.h:1449: break;
      00063F 02 07 5E         [24] 1722 	ljmp	00120$
                           00058B  1723 	C$fuzzy.h$1451$4_0$50 ==.
                                   1724 ;	../../fuzzy.h:1451: case FUZZY_LOGIC_ALGEBRAIC:
      000642                       1725 00111$:
                           00058B  1726 	C$fuzzy.h$1454$1_0$45 ==.
                                   1727 ;	../../fuzzy.h:1454: next -
      000642 C0 02            [24] 1728 	push	ar2
      000644 C0 06            [24] 1729 	push	ar6
      000646 C0 05            [24] 1730 	push	ar5
      000648 C0 04            [24] 1731 	push	ar4
      00064A C0 03            [24] 1732 	push	ar3
      00064C C0 02            [24] 1733 	push	ar2
      00064E C0 04            [24] 1734 	push	ar4
      000650 C0 05            [24] 1735 	push	ar5
      000652 C0 06            [24] 1736 	push	ar6
      000654 C0 03            [24] 1737 	push	ar3
                           00059F  1738 	C$fuzzy.h$1455$1_0$45 ==.
                                   1739 ;	../../fuzzy.h:1455: result * next;
      000656 E5 08            [12] 1740 	mov	a,_bp
      000658 24 0A            [12] 1741 	add	a,#0x0a
      00065A F8               [12] 1742 	mov	r0,a
      00065B 86 82            [24] 1743 	mov	dpl, @r0
      00065D 08               [12] 1744 	inc	r0
      00065E 86 83            [24] 1745 	mov	dph, @r0
      000660 08               [12] 1746 	inc	r0
      000661 86 F0            [24] 1747 	mov	b, @r0
      000663 08               [12] 1748 	inc	r0
      000664 E6               [12] 1749 	mov	a, @r0
      000665 12 36 14         [24] 1750 	lcall	___fsadd
      000668 C8               [12] 1751 	xch	a,r0
      000669 E5 08            [12] 1752 	mov	a,_bp
      00066B 24 06            [12] 1753 	add	a,#0x06
      00066D C8               [12] 1754 	xch	a,r0
      00066E A6 82            [24] 1755 	mov	@r0, dpl
      000670 08               [12] 1756 	inc	r0
      000671 A6 83            [24] 1757 	mov	@r0, dph
      000673 08               [12] 1758 	inc	r0
      000674 A6 F0            [24] 1759 	mov	@r0, b
      000676 08               [12] 1760 	inc	r0
      000677 F6               [12] 1761 	mov	@r0,a
      000678 E5 81            [12] 1762 	mov	a,sp
      00067A 24 FC            [12] 1763 	add	a,#0xfc
      00067C F5 81            [12] 1764 	mov	sp,a
      00067E D0 02            [24] 1765 	pop	ar2
      000680 D0 03            [24] 1766 	pop	ar3
      000682 D0 04            [24] 1767 	pop	ar4
      000684 D0 05            [24] 1768 	pop	ar5
      000686 D0 06            [24] 1769 	pop	ar6
      000688 C0 04            [24] 1770 	push	ar4
      00068A C0 05            [24] 1771 	push	ar5
      00068C C0 06            [24] 1772 	push	ar6
      00068E C0 03            [24] 1773 	push	ar3
      000690 E5 08            [12] 1774 	mov	a,_bp
      000692 24 0A            [12] 1775 	add	a,#0x0a
      000694 F8               [12] 1776 	mov	r0,a
      000695 86 82            [24] 1777 	mov	dpl, @r0
      000697 08               [12] 1778 	inc	r0
      000698 86 83            [24] 1779 	mov	dph, @r0
      00069A 08               [12] 1780 	inc	r0
      00069B 86 F0            [24] 1781 	mov	b, @r0
      00069D 08               [12] 1782 	inc	r0
      00069E E6               [12] 1783 	mov	a, @r0
      00069F 12 34 92         [24] 1784 	lcall	___fsmul
      0006A2 AA 82            [24] 1785 	mov	r2, dpl
      0006A4 AB 83            [24] 1786 	mov	r3, dph
      0006A6 AE F0            [24] 1787 	mov	r6, b
      0006A8 FF               [12] 1788 	mov	r7, a
      0006A9 E5 81            [12] 1789 	mov	a,sp
      0006AB 24 FC            [12] 1790 	add	a,#0xfc
      0006AD F5 81            [12] 1791 	mov	sp,a
      0006AF C0 02            [24] 1792 	push	ar2
      0006B1 C0 02            [24] 1793 	push	ar2
      0006B3 C0 03            [24] 1794 	push	ar3
      0006B5 C0 06            [24] 1795 	push	ar6
      0006B7 C0 07            [24] 1796 	push	ar7
                           000602  1797 	C$fuzzy.h$1456$1_0$45 ==.
                                   1798 ;	../../fuzzy.h:1456: break;
      0006B9 E5 08            [12] 1799 	mov	a,_bp
      0006BB 24 06            [12] 1800 	add	a,#0x06
      0006BD F8               [12] 1801 	mov	r0,a
      0006BE 86 82            [24] 1802 	mov	dpl, @r0
      0006C0 08               [12] 1803 	inc	r0
      0006C1 86 83            [24] 1804 	mov	dph, @r0
      0006C3 08               [12] 1805 	inc	r0
      0006C4 86 F0            [24] 1806 	mov	b, @r0
      0006C6 08               [12] 1807 	inc	r0
      0006C7 E6               [12] 1808 	mov	a, @r0
      0006C8 12 34 87         [24] 1809 	lcall	___fssub
      0006CB C8               [12] 1810 	xch	a,r0
      0006CC E5 08            [12] 1811 	mov	a,_bp
      0006CE 24 0A            [12] 1812 	add	a,#0x0a
      0006D0 C8               [12] 1813 	xch	a,r0
      0006D1 A6 82            [24] 1814 	mov	@r0, dpl
      0006D3 08               [12] 1815 	inc	r0
      0006D4 A6 83            [24] 1816 	mov	@r0, dph
      0006D6 08               [12] 1817 	inc	r0
      0006D7 A6 F0            [24] 1818 	mov	@r0, b
      0006D9 08               [12] 1819 	inc	r0
      0006DA F6               [12] 1820 	mov	@r0,a
      0006DB E5 81            [12] 1821 	mov	a,sp
      0006DD 24 FC            [12] 1822 	add	a,#0xfc
      0006DF F5 81            [12] 1823 	mov	sp,a
      0006E1 D0 02            [24] 1824 	pop	ar2
      0006E3 D0 02            [24] 1825 	pop	ar2
                           00062E  1826 	C$fuzzy.h$1458$4_0$50 ==.
                                   1827 ;	../../fuzzy.h:1458: case FUZZY_LOGIC_BOUNDED:
      0006E5 80 77            [24] 1828 	sjmp	00120$
      0006E7                       1829 00112$:
                           000630  1830 	C$fuzzy.h$1460$1_0$45 ==.
                                   1831 ;	../../fuzzy.h:1460: next;
      0006E7 C0 02            [24] 1832 	push	ar2
      0006E9 C0 04            [24] 1833 	push	ar4
      0006EB C0 05            [24] 1834 	push	ar5
      0006ED C0 06            [24] 1835 	push	ar6
      0006EF C0 03            [24] 1836 	push	ar3
                           00063A  1837 	C$fuzzy.h$1462$1_0$45 ==.
                                   1838 ;	../../fuzzy.h:1462: if (result > LEVEL_HI) {
      0006F1 E5 08            [12] 1839 	mov	a,_bp
      0006F3 24 0A            [12] 1840 	add	a,#0x0a
      0006F5 F8               [12] 1841 	mov	r0,a
      0006F6 86 82            [24] 1842 	mov	dpl, @r0
      0006F8 08               [12] 1843 	inc	r0
      0006F9 86 83            [24] 1844 	mov	dph, @r0
      0006FB 08               [12] 1845 	inc	r0
      0006FC 86 F0            [24] 1846 	mov	b, @r0
      0006FE 08               [12] 1847 	inc	r0
      0006FF E6               [12] 1848 	mov	a, @r0
      000700 12 36 14         [24] 1849 	lcall	___fsadd
      000703 C8               [12] 1850 	xch	a,r0
      000704 E5 08            [12] 1851 	mov	a,_bp
      000706 24 0A            [12] 1852 	add	a,#0x0a
      000708 C8               [12] 1853 	xch	a,r0
      000709 A6 82            [24] 1854 	mov	@r0, dpl
      00070B 08               [12] 1855 	inc	r0
      00070C A6 83            [24] 1856 	mov	@r0, dph
      00070E 08               [12] 1857 	inc	r0
      00070F A6 F0            [24] 1858 	mov	@r0, b
      000711 08               [12] 1859 	inc	r0
      000712 F6               [12] 1860 	mov	@r0,a
      000713 E5 81            [12] 1861 	mov	a,sp
      000715 24 FC            [12] 1862 	add	a,#0xfc
      000717 F5 81            [12] 1863 	mov	sp,a
      000719 E5 08            [12] 1864 	mov	a,_bp
      00071B 24 0A            [12] 1865 	add	a,#0x0a
      00071D F8               [12] 1866 	mov	r0,a
      00071E E6               [12] 1867 	mov	a,@r0
      00071F C0 E0            [24] 1868 	push	acc
      000721 08               [12] 1869 	inc	r0
      000722 E6               [12] 1870 	mov	a,@r0
      000723 C0 E0            [24] 1871 	push	acc
      000725 08               [12] 1872 	inc	r0
      000726 E6               [12] 1873 	mov	a,@r0
      000727 C0 E0            [24] 1874 	push	acc
      000729 08               [12] 1875 	inc	r0
      00072A E6               [12] 1876 	mov	a,@r0
      00072B C0 E0            [24] 1877 	push	acc
      00072D 90 00 00         [24] 1878 	mov	dptr,#0x0000
      000730 75 F0 80         [24] 1879 	mov	b, #0x80
      000733 74 3F            [12] 1880 	mov	a, #0x3f
      000735 12 35 C2         [24] 1881 	lcall	___fslt
      000738 AF 82            [24] 1882 	mov	r7, dpl
      00073A E5 81            [12] 1883 	mov	a,sp
      00073C 24 FC            [12] 1884 	add	a,#0xfc
      00073E F5 81            [12] 1885 	mov	sp,a
      000740 D0 02            [24] 1886 	pop	ar2
      000742 EF               [12] 1887 	mov	a,r7
      000743 60 19            [24] 1888 	jz	00120$
                           00068E  1889 	C$fuzzy.h$1463$5_0$52 ==.
                                   1890 ;	../../fuzzy.h:1463: result = LEVEL_HI;
      000745 E5 08            [12] 1891 	mov	a,_bp
      000747 24 0A            [12] 1892 	add	a,#0x0a
      000749 F8               [12] 1893 	mov	r0,a
      00074A E4               [12] 1894 	clr	a
      00074B F6               [12] 1895 	mov	@r0,a
      00074C 08               [12] 1896 	inc	r0
      00074D F6               [12] 1897 	mov	@r0,a
      00074E 08               [12] 1898 	inc	r0
      00074F 76 80            [12] 1899 	mov	@r0,#0x80
      000751 08               [12] 1900 	inc	r0
      000752 76 3F            [12] 1901 	mov	@r0,#0x3f
                           00069D  1902 	C$fuzzy.h$1465$4_0$50 ==.
                                   1903 ;	../../fuzzy.h:1465: break;
                           00069D  1904 	C$fuzzy.h$1467$4_0$50 ==.
                                   1905 ;	../../fuzzy.h:1467: default:
      000754 80 08            [24] 1906 	sjmp	00120$
      000756                       1907 00115$:
                           00069F  1908 	C$fuzzy.h$1468$4_0$50 ==.
                                   1909 ;	../../fuzzy.h:1468: return LEVEL_LO;
      000756 90 00 00         [24] 1910 	mov	dptr,#0x0000
      000759 E4               [12] 1911 	clr	a
      00075A F5 F0            [12] 1912 	mov	b,a
                           0006A5  1913 	C$fuzzy.h$1469$3_0$49 ==.
                                   1914 ;	../../fuzzy.h:1469: }
      00075C 80 20            [24] 1915 	sjmp	00121$
      00075E                       1916 00120$:
                           0006A7  1917 	C$fuzzy.h$1437$2_0$48 ==.
                                   1918 ;	../../fuzzy.h:1437: index++
      00075E E5 08            [12] 1919 	mov	a,_bp
      000760 24 0E            [12] 1920 	add	a,#0x0e
      000762 F8               [12] 1921 	mov	r0,a
      000763 06               [12] 1922 	inc	@r0
      000764 B6 00 02         [24] 1923 	cjne	@r0,#0x00,00206$
      000767 08               [12] 1924 	inc	r0
      000768 06               [12] 1925 	inc	@r0
      000769                       1926 00206$:
      000769 02 05 75         [24] 1927 	ljmp	00119$
      00076C                       1928 00117$:
                           0006B5  1929 	C$fuzzy.h$1473$1_0$45 ==.
                                   1930 ;	../../fuzzy.h:1473: result
      00076C E5 08            [12] 1931 	mov	a,_bp
      00076E 24 0A            [12] 1932 	add	a,#0x0a
      000770 F8               [12] 1933 	mov	r0,a
      000771 86 82            [24] 1934 	mov	dpl, @r0
      000773 08               [12] 1935 	inc	r0
      000774 86 83            [24] 1936 	mov	dph, @r0
      000776 08               [12] 1937 	inc	r0
      000777 86 F0            [24] 1938 	mov	b, @r0
      000779 08               [12] 1939 	inc	r0
      00077A E6               [12] 1940 	mov	a, @r0
      00077B 12 00 EA         [24] 1941 	lcall	_fuzzy_clamp
      00077E                       1942 00121$:
                           0006C7  1943 	C$fuzzy.h$1475$1_0$45 ==.
                                   1944 ;	../../fuzzy.h:1475: }
      00077E 85 08 81         [24] 1945 	mov	sp,_bp
      000781 D0 08            [24] 1946 	pop	_bp
                           0006CC  1947 	C$fuzzy.h$1475$1_0$45 ==.
                           0006CC  1948 	XG$fuzzy_or_array$0$0 ==.
      000783 22               [24] 1949 	ret
                                   1950 ;------------------------------------------------------------
                                   1951 ;Allocation info for local variables in function 'fuzzy_sugeno_weighted_average_array'
                                   1952 ;------------------------------------------------------------
                                   1953 ;values        Allocated to stack - _bp -5 +3 
                                   1954 ;value_count   Allocated to stack - _bp +1 +2 
                                   1955 ;weighted_sum  Allocated to stack - _bp +3 +4 
                                   1956 ;firing_sum    Allocated to stack - _bp +7 +4 
                                   1957 ;firing_strength Allocated to stack - _bp +11 +4 
                                   1958 ;consequent    Allocated to registers r4 r5 r3 r2 
                                   1959 ;index         Allocated to registers r6 r7 
                                   1960 ;------------------------------------------------------------
                           0006CD  1961 	G$fuzzy_sugeno_weighted_average_array$0$0 ==.
                           0006CD  1962 	C$fuzzy.h$1486$1_0$54 ==.
                                   1963 ;	../../fuzzy.h:1486: float fuzzy_sugeno_weighted_average_array(
                                   1964 ;	-----------------------------------------
                                   1965 ;	 function fuzzy_sugeno_weighted_average_array
                                   1966 ;	-----------------------------------------
      000784                       1967 _fuzzy_sugeno_weighted_average_array:
      000784 C0 08            [24] 1968 	push	_bp
      000786 85 81 08         [24] 1969 	mov	_bp,sp
      000789 C0 82            [24] 1970 	push	dpl
      00078B C0 83            [24] 1971 	push	dph
      00078D E5 81            [12] 1972 	mov	a,sp
      00078F 24 0C            [12] 1973 	add	a,#0x0c
      000791 F5 81            [12] 1974 	mov	sp,a
                           0006DC  1975 	C$fuzzy.h$1499$1_0$54 ==.
                                   1976 ;	../../fuzzy.h:1499: values == NULL ||
      000793 E5 08            [12] 1977 	mov	a,_bp
      000795 24 FB            [12] 1978 	add	a,#0xfb
      000797 F8               [12] 1979 	mov	r0,a
      000798 E6               [12] 1980 	mov	a,@r0
      000799 08               [12] 1981 	inc	r0
      00079A 46               [12] 1982 	orl	a,@r0
      00079B 60 0F            [24] 1983 	jz	00101$
                           0006E6  1984 	C$fuzzy.h$1500$1_0$54 ==.
                                   1985 ;	../../fuzzy.h:1500: value_count == 0u ||
      00079D A8 08            [24] 1986 	mov	r0,_bp
      00079F 08               [12] 1987 	inc	r0
      0007A0 E6               [12] 1988 	mov	a,@r0
      0007A1 08               [12] 1989 	inc	r0
      0007A2 46               [12] 1990 	orl	a,@r0
      0007A3 60 07            [24] 1991 	jz	00101$
                           0006EE  1992 	C$fuzzy.h$1501$1_0$54 ==.
                                   1993 ;	../../fuzzy.h:1501: value_count % 2u != 0u
      0007A5 A8 08            [24] 1994 	mov	r0,_bp
      0007A7 08               [12] 1995 	inc	r0
      0007A8 E6               [12] 1996 	mov	a,@r0
      0007A9 30 E0 09         [24] 1997 	jnb	acc.0,00102$
      0007AC                       1998 00101$:
                           0006F5  1999 	C$fuzzy.h$1503$2_0$55 ==.
                                   2000 ;	../../fuzzy.h:1503: return 0.0f;
      0007AC 90 00 00         [24] 2001 	mov	dptr,#0x0000
      0007AF E4               [12] 2002 	clr	a
      0007B0 F5 F0            [12] 2003 	mov	b,a
      0007B2 02 09 7F         [24] 2004 	ljmp	00111$
      0007B5                       2005 00102$:
                           0006FE  2006 	C$fuzzy.h$1507$1_0$54 ==.
                                   2007 ;	../../fuzzy.h:1507: 0.0f;
      0007B5 E5 08            [12] 2008 	mov	a,_bp
      0007B7 24 03            [12] 2009 	add	a,#0x03
      0007B9 F8               [12] 2010 	mov	r0,a
      0007BA E4               [12] 2011 	clr	a
      0007BB F6               [12] 2012 	mov	@r0,a
      0007BC 08               [12] 2013 	inc	r0
      0007BD F6               [12] 2014 	mov	@r0,a
      0007BE 08               [12] 2015 	inc	r0
      0007BF F6               [12] 2016 	mov	@r0,a
      0007C0 08               [12] 2017 	inc	r0
      0007C1 F6               [12] 2018 	mov	@r0,a
                           00070B  2019 	C$fuzzy.h$1510$1_0$54 ==.
                                   2020 ;	../../fuzzy.h:1510: 0.0f;
      0007C2 E5 08            [12] 2021 	mov	a,_bp
      0007C4 24 07            [12] 2022 	add	a,#0x07
      0007C6 F8               [12] 2023 	mov	r0,a
      0007C7 E4               [12] 2024 	clr	a
      0007C8 F6               [12] 2025 	mov	@r0,a
      0007C9 08               [12] 2026 	inc	r0
      0007CA F6               [12] 2027 	mov	@r0,a
      0007CB 08               [12] 2028 	inc	r0
      0007CC F6               [12] 2029 	mov	@r0,a
      0007CD 08               [12] 2030 	inc	r0
      0007CE F6               [12] 2031 	mov	@r0,a
                           000718  2032 	C$fuzzy.h$1513$1_0$54 ==.
                                   2033 ;	../../fuzzy.h:1513: index = 0u;
      0007CF FE               [12] 2034 	mov	r6,a
      0007D0 FF               [12] 2035 	mov	r7,a
      0007D1                       2036 00109$:
                           00071A  2037 	C$fuzzy.h$1514$2_0$56 ==.
                                   2038 ;	../../fuzzy.h:1514: index < value_count;
      0007D1 A8 08            [24] 2039 	mov	r0,_bp
      0007D3 08               [12] 2040 	inc	r0
      0007D4 C3               [12] 2041 	clr	c
      0007D5 EE               [12] 2042 	mov	a,r6
      0007D6 96               [12] 2043 	subb	a,@r0
      0007D7 EF               [12] 2044 	mov	a,r7
      0007D8 08               [12] 2045 	inc	r0
      0007D9 96               [12] 2046 	subb	a,@r0
      0007DA 40 03            [24] 2047 	jc	00147$
      0007DC 02 09 12         [24] 2048 	ljmp	00105$
      0007DF                       2049 00147$:
                           000728  2050 	C$fuzzy.h$1519$3_0$57 ==.
                                   2051 ;	../../fuzzy.h:1519: values[index]
      0007DF EE               [12] 2052 	mov	a,r6
      0007E0 2E               [12] 2053 	add	a,r6
      0007E1 FC               [12] 2054 	mov	r4,a
      0007E2 EF               [12] 2055 	mov	a,r7
      0007E3 33               [12] 2056 	rlc	a
      0007E4 FD               [12] 2057 	mov	r5,a
      0007E5 EC               [12] 2058 	mov	a,r4
      0007E6 2C               [12] 2059 	add	a,r4
      0007E7 FC               [12] 2060 	mov	r4,a
      0007E8 ED               [12] 2061 	mov	a,r5
      0007E9 33               [12] 2062 	rlc	a
      0007EA FD               [12] 2063 	mov	r5,a
      0007EB E5 08            [12] 2064 	mov	a,_bp
      0007ED 24 FB            [12] 2065 	add	a,#0xfb
      0007EF F8               [12] 2066 	mov	r0,a
      0007F0 EC               [12] 2067 	mov	a,r4
      0007F1 26               [12] 2068 	add	a, @r0
      0007F2 FC               [12] 2069 	mov	r4,a
      0007F3 ED               [12] 2070 	mov	a,r5
      0007F4 08               [12] 2071 	inc	r0
      0007F5 36               [12] 2072 	addc	a, @r0
      0007F6 FD               [12] 2073 	mov	r5,a
      0007F7 08               [12] 2074 	inc	r0
      0007F8 86 03            [24] 2075 	mov	ar3,@r0
      0007FA 8C 82            [24] 2076 	mov	dpl,r4
      0007FC 8D 83            [24] 2077 	mov	dph,r5
      0007FE 8B F0            [24] 2078 	mov	b,r3
      000800 12 37 EE         [24] 2079 	lcall	__gptrget
      000803 FC               [12] 2080 	mov	r4,a
      000804 A3               [24] 2081 	inc	dptr
      000805 12 37 EE         [24] 2082 	lcall	__gptrget
      000808 FD               [12] 2083 	mov	r5,a
      000809 A3               [24] 2084 	inc	dptr
      00080A 12 37 EE         [24] 2085 	lcall	__gptrget
      00080D FB               [12] 2086 	mov	r3,a
      00080E A3               [24] 2087 	inc	dptr
      00080F 12 37 EE         [24] 2088 	lcall	__gptrget
      000812 8C 82            [24] 2089 	mov	dpl,r4
      000814 8D 83            [24] 2090 	mov	dph,r5
      000816 8B F0            [24] 2091 	mov	b,r3
      000818 C0 07            [24] 2092 	push	ar7
      00081A C0 06            [24] 2093 	push	ar6
      00081C 12 00 EA         [24] 2094 	lcall	_fuzzy_clamp
      00081F C8               [12] 2095 	xch	a,r0
      000820 E5 08            [12] 2096 	mov	a,_bp
      000822 24 0B            [12] 2097 	add	a,#0x0b
      000824 C8               [12] 2098 	xch	a,r0
      000825 A6 82            [24] 2099 	mov	@r0, dpl
      000827 08               [12] 2100 	inc	r0
      000828 A6 83            [24] 2101 	mov	@r0, dph
      00082A 08               [12] 2102 	inc	r0
      00082B A6 F0            [24] 2103 	mov	@r0, b
      00082D 08               [12] 2104 	inc	r0
      00082E F6               [12] 2105 	mov	@r0,a
      00082F D0 06            [24] 2106 	pop	ar6
      000831 D0 07            [24] 2107 	pop	ar7
                           00077C  2108 	C$fuzzy.h$1523$3_0$57 ==.
                                   2109 ;	../../fuzzy.h:1523: values[index + 1u];
      000833 74 01            [12] 2110 	mov	a,#0x01
      000835 2E               [12] 2111 	add	a, r6
      000836 FC               [12] 2112 	mov	r4,a
      000837 E4               [12] 2113 	clr	a
      000838 3F               [12] 2114 	addc	a, r7
      000839 FD               [12] 2115 	mov	r5,a
      00083A EC               [12] 2116 	mov	a,r4
      00083B 2C               [12] 2117 	add	a,r4
      00083C FC               [12] 2118 	mov	r4,a
      00083D ED               [12] 2119 	mov	a,r5
      00083E 33               [12] 2120 	rlc	a
      00083F FD               [12] 2121 	mov	r5,a
      000840 EC               [12] 2122 	mov	a,r4
      000841 2C               [12] 2123 	add	a,r4
      000842 FC               [12] 2124 	mov	r4,a
      000843 ED               [12] 2125 	mov	a,r5
      000844 33               [12] 2126 	rlc	a
      000845 FD               [12] 2127 	mov	r5,a
      000846 E5 08            [12] 2128 	mov	a,_bp
      000848 24 FB            [12] 2129 	add	a,#0xfb
      00084A F8               [12] 2130 	mov	r0,a
      00084B EC               [12] 2131 	mov	a,r4
      00084C 26               [12] 2132 	add	a, @r0
      00084D FC               [12] 2133 	mov	r4,a
      00084E ED               [12] 2134 	mov	a,r5
      00084F 08               [12] 2135 	inc	r0
      000850 36               [12] 2136 	addc	a, @r0
      000851 FD               [12] 2137 	mov	r5,a
      000852 08               [12] 2138 	inc	r0
      000853 86 03            [24] 2139 	mov	ar3,@r0
      000855 8C 82            [24] 2140 	mov	dpl,r4
      000857 8D 83            [24] 2141 	mov	dph,r5
      000859 8B F0            [24] 2142 	mov	b,r3
      00085B 12 37 EE         [24] 2143 	lcall	__gptrget
      00085E FC               [12] 2144 	mov	r4,a
      00085F A3               [24] 2145 	inc	dptr
      000860 12 37 EE         [24] 2146 	lcall	__gptrget
      000863 FD               [12] 2147 	mov	r5,a
      000864 A3               [24] 2148 	inc	dptr
      000865 12 37 EE         [24] 2149 	lcall	__gptrget
      000868 FB               [12] 2150 	mov	r3,a
      000869 A3               [24] 2151 	inc	dptr
      00086A 12 37 EE         [24] 2152 	lcall	__gptrget
      00086D FA               [12] 2153 	mov	r2,a
                           0007B7  2154 	C$fuzzy.h$1528$1_0$54 ==.
                                   2155 ;	../../fuzzy.h:1528: consequent;
      00086E C0 07            [24] 2156 	push	ar7
      000870 C0 06            [24] 2157 	push	ar6
      000872 C0 04            [24] 2158 	push	ar4
      000874 C0 05            [24] 2159 	push	ar5
      000876 C0 03            [24] 2160 	push	ar3
      000878 C0 02            [24] 2161 	push	ar2
      00087A E5 08            [12] 2162 	mov	a,_bp
      00087C 24 0B            [12] 2163 	add	a,#0x0b
      00087E F8               [12] 2164 	mov	r0,a
      00087F 86 82            [24] 2165 	mov	dpl, @r0
      000881 08               [12] 2166 	inc	r0
      000882 86 83            [24] 2167 	mov	dph, @r0
      000884 08               [12] 2168 	inc	r0
      000885 86 F0            [24] 2169 	mov	b, @r0
      000887 08               [12] 2170 	inc	r0
      000888 E6               [12] 2171 	mov	a, @r0
      000889 12 34 92         [24] 2172 	lcall	___fsmul
      00088C AA 82            [24] 2173 	mov	r2, dpl
      00088E AB 83            [24] 2174 	mov	r3, dph
      000890 AC F0            [24] 2175 	mov	r4, b
      000892 FD               [12] 2176 	mov	r5, a
      000893 E5 81            [12] 2177 	mov	a,sp
      000895 24 FC            [12] 2178 	add	a,#0xfc
      000897 F5 81            [12] 2179 	mov	sp,a
      000899 C0 02            [24] 2180 	push	ar2
      00089B C0 03            [24] 2181 	push	ar3
      00089D C0 04            [24] 2182 	push	ar4
      00089F C0 05            [24] 2183 	push	ar5
                           0007EA  2184 	C$fuzzy.h$1531$1_0$54 ==.
                                   2185 ;	../../fuzzy.h:1531: firing_strength;
      0008A1 E5 08            [12] 2186 	mov	a,_bp
      0008A3 24 03            [12] 2187 	add	a,#0x03
      0008A5 F8               [12] 2188 	mov	r0,a
      0008A6 86 82            [24] 2189 	mov	dpl, @r0
      0008A8 08               [12] 2190 	inc	r0
      0008A9 86 83            [24] 2191 	mov	dph, @r0
      0008AB 08               [12] 2192 	inc	r0
      0008AC 86 F0            [24] 2193 	mov	b, @r0
      0008AE 08               [12] 2194 	inc	r0
      0008AF E6               [12] 2195 	mov	a, @r0
      0008B0 12 36 14         [24] 2196 	lcall	___fsadd
      0008B3 A8 08            [24] 2197 	mov	r0,_bp
      0008B5 08               [12] 2198 	inc	r0
      0008B6 08               [12] 2199 	inc	r0
      0008B7 08               [12] 2200 	inc	r0
      0008B8 A6 82            [24] 2201 	mov	@r0, dpl
      0008BA 08               [12] 2202 	inc	r0
      0008BB A6 83            [24] 2203 	mov	@r0, dph
      0008BD 08               [12] 2204 	inc	r0
      0008BE A6 F0            [24] 2205 	mov	@r0, b
      0008C0 08               [12] 2206 	inc	r0
      0008C1 F6               [12] 2207 	mov	@r0,a
      0008C2 E5 81            [12] 2208 	mov	a,sp
      0008C4 24 FC            [12] 2209 	add	a,#0xfc
      0008C6 F5 81            [12] 2210 	mov	sp,a
      0008C8 E5 08            [12] 2211 	mov	a,_bp
      0008CA 24 0B            [12] 2212 	add	a,#0x0b
      0008CC F8               [12] 2213 	mov	r0,a
      0008CD E6               [12] 2214 	mov	a,@r0
      0008CE C0 E0            [24] 2215 	push	acc
      0008D0 08               [12] 2216 	inc	r0
      0008D1 E6               [12] 2217 	mov	a,@r0
      0008D2 C0 E0            [24] 2218 	push	acc
      0008D4 08               [12] 2219 	inc	r0
      0008D5 E6               [12] 2220 	mov	a,@r0
      0008D6 C0 E0            [24] 2221 	push	acc
      0008D8 08               [12] 2222 	inc	r0
      0008D9 E6               [12] 2223 	mov	a,@r0
      0008DA C0 E0            [24] 2224 	push	acc
                           000825  2225 	C$fuzzy.h$1516$1_0$54 ==.
                                   2226 ;	../../fuzzy.h:1516: ) {
      0008DC E5 08            [12] 2227 	mov	a,_bp
      0008DE 24 07            [12] 2228 	add	a,#0x07
      0008E0 F8               [12] 2229 	mov	r0,a
      0008E1 86 82            [24] 2230 	mov	dpl, @r0
      0008E3 08               [12] 2231 	inc	r0
      0008E4 86 83            [24] 2232 	mov	dph, @r0
      0008E6 08               [12] 2233 	inc	r0
      0008E7 86 F0            [24] 2234 	mov	b, @r0
      0008E9 08               [12] 2235 	inc	r0
      0008EA E6               [12] 2236 	mov	a, @r0
      0008EB 12 36 14         [24] 2237 	lcall	___fsadd
      0008EE C8               [12] 2238 	xch	a,r0
      0008EF E5 08            [12] 2239 	mov	a,_bp
      0008F1 24 07            [12] 2240 	add	a,#0x07
      0008F3 C8               [12] 2241 	xch	a,r0
      0008F4 A6 82            [24] 2242 	mov	@r0, dpl
      0008F6 08               [12] 2243 	inc	r0
      0008F7 A6 83            [24] 2244 	mov	@r0, dph
      0008F9 08               [12] 2245 	inc	r0
      0008FA A6 F0            [24] 2246 	mov	@r0, b
      0008FC 08               [12] 2247 	inc	r0
      0008FD F6               [12] 2248 	mov	@r0,a
      0008FE E5 81            [12] 2249 	mov	a,sp
      000900 24 FC            [12] 2250 	add	a,#0xfc
      000902 F5 81            [12] 2251 	mov	sp,a
      000904 D0 06            [24] 2252 	pop	ar6
      000906 D0 07            [24] 2253 	pop	ar7
      000908 74 02            [12] 2254 	mov	a,#0x02
      00090A 2E               [12] 2255 	add	a, r6
      00090B FE               [12] 2256 	mov	r6,a
      00090C E4               [12] 2257 	clr	a
      00090D 3F               [12] 2258 	addc	a, r7
      00090E FF               [12] 2259 	mov	r7,a
      00090F 02 07 D1         [24] 2260 	ljmp	00109$
      000912                       2261 00105$:
                           00085B  2262 	C$fuzzy.h$1534$1_0$54 ==.
                                   2263 ;	../../fuzzy.h:1534: if (firing_sum <= LEVEL_LO) {
      000912 E5 08            [12] 2264 	mov	a,_bp
      000914 24 07            [12] 2265 	add	a,#0x07
      000916 F8               [12] 2266 	mov	r0,a
      000917 E6               [12] 2267 	mov	a,@r0
      000918 C0 E0            [24] 2268 	push	acc
      00091A 08               [12] 2269 	inc	r0
      00091B E6               [12] 2270 	mov	a,@r0
      00091C C0 E0            [24] 2271 	push	acc
      00091E 08               [12] 2272 	inc	r0
      00091F E6               [12] 2273 	mov	a,@r0
      000920 C0 E0            [24] 2274 	push	acc
      000922 08               [12] 2275 	inc	r0
      000923 E6               [12] 2276 	mov	a,@r0
      000924 C0 E0            [24] 2277 	push	acc
      000926 90 00 00         [24] 2278 	mov	dptr,#0x0000
      000929 E4               [12] 2279 	clr	a
      00092A F5 F0            [12] 2280 	mov	b,a
      00092C 12 35 C2         [24] 2281 	lcall	___fslt
      00092F E5 81            [12] 2282 	mov	a,sp
      000931 24 FC            [12] 2283 	add	a,#0xfc
      000933 F5 81            [12] 2284 	mov	sp,a
      000935 E5 82            [12] 2285 	mov	a, dpl
      000937 24 FF            [12] 2286 	add	a,#0xff
      000939 92 00            [24] 2287 	mov	b0,c
      00093B 40 08            [24] 2288 	jc	00107$
                           000886  2289 	C$fuzzy.h$1535$2_0$58 ==.
                                   2290 ;	../../fuzzy.h:1535: return 0.0f;
      00093D 90 00 00         [24] 2291 	mov	dptr,#0x0000
      000940 E4               [12] 2292 	clr	a
      000941 F5 F0            [12] 2293 	mov	b,a
      000943 80 3A            [24] 2294 	sjmp	00111$
      000945                       2295 00107$:
                           00088E  2296 	C$fuzzy.h$1539$1_0$54 ==.
                                   2297 ;	../../fuzzy.h:1539: firing_sum;
      000945 E5 08            [12] 2298 	mov	a,_bp
      000947 24 07            [12] 2299 	add	a,#0x07
      000949 F8               [12] 2300 	mov	r0,a
      00094A E6               [12] 2301 	mov	a,@r0
      00094B C0 E0            [24] 2302 	push	acc
      00094D 08               [12] 2303 	inc	r0
      00094E E6               [12] 2304 	mov	a,@r0
      00094F C0 E0            [24] 2305 	push	acc
      000951 08               [12] 2306 	inc	r0
      000952 E6               [12] 2307 	mov	a,@r0
      000953 C0 E0            [24] 2308 	push	acc
      000955 08               [12] 2309 	inc	r0
      000956 E6               [12] 2310 	mov	a,@r0
      000957 C0 E0            [24] 2311 	push	acc
      000959 E5 08            [12] 2312 	mov	a,_bp
      00095B 24 03            [12] 2313 	add	a,#0x03
      00095D F8               [12] 2314 	mov	r0,a
      00095E 86 82            [24] 2315 	mov	dpl, @r0
      000960 08               [12] 2316 	inc	r0
      000961 86 83            [24] 2317 	mov	dph, @r0
      000963 08               [12] 2318 	inc	r0
      000964 86 F0            [24] 2319 	mov	b, @r0
      000966 08               [12] 2320 	inc	r0
      000967 E6               [12] 2321 	mov	a, @r0
      000968 12 37 2B         [24] 2322 	lcall	___fsdiv
      00096B AC 82            [24] 2323 	mov	r4, dpl
      00096D AD 83            [24] 2324 	mov	r5, dph
      00096F AE F0            [24] 2325 	mov	r6, b
      000971 FF               [12] 2326 	mov	r7, a
      000972 E5 81            [12] 2327 	mov	a,sp
      000974 24 FC            [12] 2328 	add	a,#0xfc
      000976 F5 81            [12] 2329 	mov	sp,a
      000978 8C 82            [24] 2330 	mov	dpl, r4
      00097A 8D 83            [24] 2331 	mov	dph, r5
      00097C 8E F0            [24] 2332 	mov	b, r6
      00097E EF               [12] 2333 	mov	a, r7
      00097F                       2334 00111$:
                           0008C8  2335 	C$fuzzy.h$1540$1_0$54 ==.
                                   2336 ;	../../fuzzy.h:1540: }
      00097F 85 08 81         [24] 2337 	mov	sp,_bp
      000982 D0 08            [24] 2338 	pop	_bp
                           0008CD  2339 	C$fuzzy.h$1540$1_0$54 ==.
                           0008CD  2340 	XG$fuzzy_sugeno_weighted_average_array$0$0 ==.
      000984 22               [24] 2341 	ret
                                   2342 ;------------------------------------------------------------
                                   2343 ;Allocation info for local variables in function 'fuzzy_sugeno_weighted_sum_array'
                                   2344 ;------------------------------------------------------------
                                   2345 ;values        Allocated to stack - _bp -5 +3 
                                   2346 ;value_count   Allocated to registers r6 r7 
                                   2347 ;weighted_sum  Allocated to stack - _bp +1 +4 
                                   2348 ;firing_strength Allocated to stack - _bp +5 +4 
                                   2349 ;consequent    Allocated to registers r6 r7 r3 r2 
                                   2350 ;index         Allocated to registers r4 r5 
                                   2351 ;------------------------------------------------------------
                           0008CE  2352 	G$fuzzy_sugeno_weighted_sum_array$0$0 ==.
                           0008CE  2353 	C$fuzzy.h$1550$1_0$60 ==.
                                   2354 ;	../../fuzzy.h:1550: float fuzzy_sugeno_weighted_sum_array(
                                   2355 ;	-----------------------------------------
                                   2356 ;	 function fuzzy_sugeno_weighted_sum_array
                                   2357 ;	-----------------------------------------
      000985                       2358 _fuzzy_sugeno_weighted_sum_array:
      000985 C0 08            [24] 2359 	push	_bp
      000987 E5 81            [12] 2360 	mov	a,sp
      000989 F5 08            [12] 2361 	mov	_bp,a
      00098B 24 08            [12] 2362 	add	a,#0x08
      00098D F5 81            [12] 2363 	mov	sp,a
      00098F AE 82            [24] 2364 	mov	r6, dpl
      000991 AF 83            [24] 2365 	mov	r7, dph
                           0008DC  2366 	C$fuzzy.h$1562$1_0$60 ==.
                                   2367 ;	../../fuzzy.h:1562: values == NULL ||
      000993 E5 08            [12] 2368 	mov	a,_bp
      000995 24 FB            [12] 2369 	add	a,#0xfb
      000997 F8               [12] 2370 	mov	r0,a
      000998 E6               [12] 2371 	mov	a,@r0
      000999 08               [12] 2372 	inc	r0
      00099A 46               [12] 2373 	orl	a,@r0
      00099B 60 08            [24] 2374 	jz	00101$
                           0008E6  2375 	C$fuzzy.h$1563$1_0$60 ==.
                                   2376 ;	../../fuzzy.h:1563: value_count == 0u ||
      00099D EE               [12] 2377 	mov	a,r6
      00099E 4F               [12] 2378 	orl	a,r7
      00099F 60 04            [24] 2379 	jz	00101$
                           0008EA  2380 	C$fuzzy.h$1564$1_0$60 ==.
                                   2381 ;	../../fuzzy.h:1564: value_count % 2u != 0u
      0009A1 EE               [12] 2382 	mov	a,r6
      0009A2 30 E0 09         [24] 2383 	jnb	acc.0,00102$
      0009A5                       2384 00101$:
                           0008EE  2385 	C$fuzzy.h$1566$2_0$61 ==.
                                   2386 ;	../../fuzzy.h:1566: return 0.0f;
      0009A5 90 00 00         [24] 2387 	mov	dptr,#0x0000
      0009A8 E4               [12] 2388 	clr	a
      0009A9 F5 F0            [12] 2389 	mov	b,a
      0009AB 02 0A E6         [24] 2390 	ljmp	00109$
      0009AE                       2391 00102$:
                           0008F7  2392 	C$fuzzy.h$1570$1_0$60 ==.
                                   2393 ;	../../fuzzy.h:1570: 0.0f;
      0009AE A8 08            [24] 2394 	mov	r0,_bp
      0009B0 08               [12] 2395 	inc	r0
      0009B1 E4               [12] 2396 	clr	a
      0009B2 F6               [12] 2397 	mov	@r0,a
      0009B3 08               [12] 2398 	inc	r0
      0009B4 F6               [12] 2399 	mov	@r0,a
      0009B5 08               [12] 2400 	inc	r0
      0009B6 F6               [12] 2401 	mov	@r0,a
      0009B7 08               [12] 2402 	inc	r0
      0009B8 F6               [12] 2403 	mov	@r0,a
                           000902  2404 	C$fuzzy.h$1573$1_0$60 ==.
                                   2405 ;	../../fuzzy.h:1573: index = 0u;
      0009B9 FC               [12] 2406 	mov	r4,a
      0009BA FD               [12] 2407 	mov	r5,a
      0009BB                       2408 00107$:
                           000904  2409 	C$fuzzy.h$1574$2_0$62 ==.
                                   2410 ;	../../fuzzy.h:1574: index < value_count;
      0009BB C3               [12] 2411 	clr	c
      0009BC EC               [12] 2412 	mov	a,r4
      0009BD 9E               [12] 2413 	subb	a,r6
      0009BE ED               [12] 2414 	mov	a,r5
      0009BF 9F               [12] 2415 	subb	a,r7
      0009C0 40 03            [24] 2416 	jc	00139$
      0009C2 02 0A D9         [24] 2417 	ljmp	00105$
      0009C5                       2418 00139$:
                           00090E  2419 	C$fuzzy.h$1579$1_0$60 ==.
                                   2420 ;	../../fuzzy.h:1579: values[index]
      0009C5 C0 06            [24] 2421 	push	ar6
      0009C7 C0 07            [24] 2422 	push	ar7
      0009C9 EC               [12] 2423 	mov	a,r4
      0009CA 2C               [12] 2424 	add	a,r4
      0009CB FA               [12] 2425 	mov	r2,a
      0009CC ED               [12] 2426 	mov	a,r5
      0009CD 33               [12] 2427 	rlc	a
      0009CE FB               [12] 2428 	mov	r3,a
      0009CF EA               [12] 2429 	mov	a,r2
      0009D0 2A               [12] 2430 	add	a,r2
      0009D1 FA               [12] 2431 	mov	r2,a
      0009D2 EB               [12] 2432 	mov	a,r3
      0009D3 33               [12] 2433 	rlc	a
      0009D4 FB               [12] 2434 	mov	r3,a
      0009D5 E5 08            [12] 2435 	mov	a,_bp
      0009D7 24 FB            [12] 2436 	add	a,#0xfb
      0009D9 F8               [12] 2437 	mov	r0,a
      0009DA EA               [12] 2438 	mov	a,r2
      0009DB 26               [12] 2439 	add	a, @r0
      0009DC FA               [12] 2440 	mov	r2,a
      0009DD EB               [12] 2441 	mov	a,r3
      0009DE 08               [12] 2442 	inc	r0
      0009DF 36               [12] 2443 	addc	a, @r0
      0009E0 FB               [12] 2444 	mov	r3,a
      0009E1 08               [12] 2445 	inc	r0
      0009E2 86 07            [24] 2446 	mov	ar7,@r0
      0009E4 8A 82            [24] 2447 	mov	dpl,r2
      0009E6 8B 83            [24] 2448 	mov	dph,r3
      0009E8 8F F0            [24] 2449 	mov	b,r7
      0009EA 12 37 EE         [24] 2450 	lcall	__gptrget
      0009ED FA               [12] 2451 	mov	r2,a
      0009EE A3               [24] 2452 	inc	dptr
      0009EF 12 37 EE         [24] 2453 	lcall	__gptrget
      0009F2 FB               [12] 2454 	mov	r3,a
      0009F3 A3               [24] 2455 	inc	dptr
      0009F4 12 37 EE         [24] 2456 	lcall	__gptrget
      0009F7 FF               [12] 2457 	mov	r7,a
      0009F8 A3               [24] 2458 	inc	dptr
      0009F9 12 37 EE         [24] 2459 	lcall	__gptrget
      0009FC FE               [12] 2460 	mov	r6,a
      0009FD 8A 82            [24] 2461 	mov	dpl,r2
      0009FF 8B 83            [24] 2462 	mov	dph,r3
      000A01 8F F0            [24] 2463 	mov	b,r7
      000A03 C0 07            [24] 2464 	push	ar7
      000A05 C0 06            [24] 2465 	push	ar6
      000A07 C0 05            [24] 2466 	push	ar5
      000A09 C0 04            [24] 2467 	push	ar4
      000A0B 12 00 EA         [24] 2468 	lcall	_fuzzy_clamp
      000A0E C8               [12] 2469 	xch	a,r0
      000A0F E5 08            [12] 2470 	mov	a,_bp
      000A11 24 05            [12] 2471 	add	a,#0x05
      000A13 C8               [12] 2472 	xch	a,r0
      000A14 A6 82            [24] 2473 	mov	@r0, dpl
      000A16 08               [12] 2474 	inc	r0
      000A17 A6 83            [24] 2475 	mov	@r0, dph
      000A19 08               [12] 2476 	inc	r0
      000A1A A6 F0            [24] 2477 	mov	@r0, b
      000A1C 08               [12] 2478 	inc	r0
      000A1D F6               [12] 2479 	mov	@r0,a
      000A1E D0 04            [24] 2480 	pop	ar4
      000A20 D0 05            [24] 2481 	pop	ar5
      000A22 D0 06            [24] 2482 	pop	ar6
      000A24 D0 07            [24] 2483 	pop	ar7
                           00096F  2484 	C$fuzzy.h$1583$3_0$63 ==.
                                   2485 ;	../../fuzzy.h:1583: values[index + 1u];
      000A26 74 01            [12] 2486 	mov	a,#0x01
      000A28 2C               [12] 2487 	add	a, r4
      000A29 FE               [12] 2488 	mov	r6,a
      000A2A E4               [12] 2489 	clr	a
      000A2B 3D               [12] 2490 	addc	a, r5
      000A2C FF               [12] 2491 	mov	r7,a
      000A2D EE               [12] 2492 	mov	a,r6
      000A2E 2E               [12] 2493 	add	a,r6
      000A2F FE               [12] 2494 	mov	r6,a
      000A30 EF               [12] 2495 	mov	a,r7
      000A31 33               [12] 2496 	rlc	a
      000A32 FF               [12] 2497 	mov	r7,a
      000A33 EE               [12] 2498 	mov	a,r6
      000A34 2E               [12] 2499 	add	a,r6
      000A35 FE               [12] 2500 	mov	r6,a
      000A36 EF               [12] 2501 	mov	a,r7
      000A37 33               [12] 2502 	rlc	a
      000A38 FF               [12] 2503 	mov	r7,a
      000A39 E5 08            [12] 2504 	mov	a,_bp
      000A3B 24 FB            [12] 2505 	add	a,#0xfb
      000A3D F8               [12] 2506 	mov	r0,a
      000A3E EE               [12] 2507 	mov	a,r6
      000A3F 26               [12] 2508 	add	a, @r0
      000A40 FE               [12] 2509 	mov	r6,a
      000A41 EF               [12] 2510 	mov	a,r7
      000A42 08               [12] 2511 	inc	r0
      000A43 36               [12] 2512 	addc	a, @r0
      000A44 FF               [12] 2513 	mov	r7,a
      000A45 08               [12] 2514 	inc	r0
      000A46 86 03            [24] 2515 	mov	ar3,@r0
      000A48 8E 82            [24] 2516 	mov	dpl,r6
      000A4A 8F 83            [24] 2517 	mov	dph,r7
      000A4C 8B F0            [24] 2518 	mov	b,r3
      000A4E 12 37 EE         [24] 2519 	lcall	__gptrget
      000A51 FE               [12] 2520 	mov	r6,a
      000A52 A3               [24] 2521 	inc	dptr
      000A53 12 37 EE         [24] 2522 	lcall	__gptrget
      000A56 FF               [12] 2523 	mov	r7,a
      000A57 A3               [24] 2524 	inc	dptr
      000A58 12 37 EE         [24] 2525 	lcall	__gptrget
      000A5B FB               [12] 2526 	mov	r3,a
      000A5C A3               [24] 2527 	inc	dptr
      000A5D 12 37 EE         [24] 2528 	lcall	__gptrget
      000A60 FA               [12] 2529 	mov	r2,a
                           0009AA  2530 	C$fuzzy.h$1588$1_0$60 ==.
                                   2531 ;	../../fuzzy.h:1588: consequent;
      000A61 C0 05            [24] 2532 	push	ar5
      000A63 C0 04            [24] 2533 	push	ar4
      000A65 C0 06            [24] 2534 	push	ar6
      000A67 C0 07            [24] 2535 	push	ar7
      000A69 C0 03            [24] 2536 	push	ar3
      000A6B C0 02            [24] 2537 	push	ar2
      000A6D E5 08            [12] 2538 	mov	a,_bp
      000A6F 24 05            [12] 2539 	add	a,#0x05
      000A71 F8               [12] 2540 	mov	r0,a
      000A72 86 82            [24] 2541 	mov	dpl, @r0
      000A74 08               [12] 2542 	inc	r0
      000A75 86 83            [24] 2543 	mov	dph, @r0
      000A77 08               [12] 2544 	inc	r0
      000A78 86 F0            [24] 2545 	mov	b, @r0
      000A7A 08               [12] 2546 	inc	r0
      000A7B E6               [12] 2547 	mov	a, @r0
      000A7C 12 34 92         [24] 2548 	lcall	___fsmul
      000A7F AA 82            [24] 2549 	mov	r2, dpl
      000A81 AB 83            [24] 2550 	mov	r3, dph
      000A83 AE F0            [24] 2551 	mov	r6, b
      000A85 FF               [12] 2552 	mov	r7, a
      000A86 E5 81            [12] 2553 	mov	a,sp
      000A88 24 FC            [12] 2554 	add	a,#0xfc
      000A8A F5 81            [12] 2555 	mov	sp,a
      000A8C D0 04            [24] 2556 	pop	ar4
      000A8E D0 05            [24] 2557 	pop	ar5
      000A90 C0 07            [24] 2558 	push	ar7
      000A92 C0 06            [24] 2559 	push	ar6
      000A94 C0 05            [24] 2560 	push	ar5
      000A96 C0 04            [24] 2561 	push	ar4
      000A98 C0 02            [24] 2562 	push	ar2
      000A9A C0 03            [24] 2563 	push	ar3
      000A9C C0 06            [24] 2564 	push	ar6
      000A9E C0 07            [24] 2565 	push	ar7
                           0009E9  2566 	C$fuzzy.h$1576$1_0$60 ==.
                                   2567 ;	../../fuzzy.h:1576: ) {
      000AA0 A8 08            [24] 2568 	mov	r0,_bp
      000AA2 08               [12] 2569 	inc	r0
      000AA3 86 82            [24] 2570 	mov	dpl, @r0
      000AA5 08               [12] 2571 	inc	r0
      000AA6 86 83            [24] 2572 	mov	dph, @r0
      000AA8 08               [12] 2573 	inc	r0
      000AA9 86 F0            [24] 2574 	mov	b, @r0
      000AAB 08               [12] 2575 	inc	r0
      000AAC E6               [12] 2576 	mov	a, @r0
      000AAD 12 36 14         [24] 2577 	lcall	___fsadd
      000AB0 A8 08            [24] 2578 	mov	r0,_bp
      000AB2 08               [12] 2579 	inc	r0
      000AB3 A6 82            [24] 2580 	mov	@r0, dpl
      000AB5 08               [12] 2581 	inc	r0
      000AB6 A6 83            [24] 2582 	mov	@r0, dph
      000AB8 08               [12] 2583 	inc	r0
      000AB9 A6 F0            [24] 2584 	mov	@r0, b
      000ABB 08               [12] 2585 	inc	r0
      000ABC F6               [12] 2586 	mov	@r0,a
      000ABD E5 81            [12] 2587 	mov	a,sp
      000ABF 24 FC            [12] 2588 	add	a,#0xfc
      000AC1 F5 81            [12] 2589 	mov	sp,a
      000AC3 D0 04            [24] 2590 	pop	ar4
      000AC5 D0 05            [24] 2591 	pop	ar5
      000AC7 D0 06            [24] 2592 	pop	ar6
      000AC9 D0 07            [24] 2593 	pop	ar7
      000ACB 74 02            [12] 2594 	mov	a,#0x02
      000ACD 2C               [12] 2595 	add	a, r4
      000ACE FC               [12] 2596 	mov	r4,a
      000ACF E4               [12] 2597 	clr	a
      000AD0 3D               [12] 2598 	addc	a, r5
      000AD1 FD               [12] 2599 	mov	r5,a
      000AD2 D0 07            [24] 2600 	pop	ar7
      000AD4 D0 06            [24] 2601 	pop	ar6
      000AD6 02 09 BB         [24] 2602 	ljmp	00107$
      000AD9                       2603 00105$:
                           000A22  2604 	C$fuzzy.h$1591$1_0$60 ==.
                                   2605 ;	../../fuzzy.h:1591: return weighted_sum;
      000AD9 A8 08            [24] 2606 	mov	r0,_bp
      000ADB 08               [12] 2607 	inc	r0
      000ADC 86 82            [24] 2608 	mov	dpl, @r0
      000ADE 08               [12] 2609 	inc	r0
      000ADF 86 83            [24] 2610 	mov	dph, @r0
      000AE1 08               [12] 2611 	inc	r0
      000AE2 86 F0            [24] 2612 	mov	b, @r0
      000AE4 08               [12] 2613 	inc	r0
      000AE5 E6               [12] 2614 	mov	a, @r0
      000AE6                       2615 00109$:
                           000A2F  2616 	C$fuzzy.h$1592$1_0$60 ==.
                                   2617 ;	../../fuzzy.h:1592: }
      000AE6 85 08 81         [24] 2618 	mov	sp,_bp
      000AE9 D0 08            [24] 2619 	pop	_bp
                           000A34  2620 	C$fuzzy.h$1592$1_0$60 ==.
                           000A34  2621 	XG$fuzzy_sugeno_weighted_sum_array$0$0 ==.
      000AEB 22               [24] 2622 	ret
                                   2623 ;------------------------------------------------------------
                                   2624 ;Allocation info for local variables in function 'fuzzy_ramp'
                                   2625 ;------------------------------------------------------------
                                   2626 ;upper_boundary Allocated to stack - _bp -6 +4 
                                   2627 ;value         Allocated to stack - _bp -10 +4 
                                   2628 ;ramp_up       Allocated to stack - _bp -11 +1 
                                   2629 ;hedge         Allocated to stack - _bp -12 +1 
                                   2630 ;lower_boundary Allocated to registers r7 r6 r5 r4 
                                   2631 ;result        Allocated to stack - _bp +5 +4 
                                   2632 ;normalized    Allocated to registers r4 r5 r6 r7 
                                   2633 ;sloc0         Allocated to stack - _bp +13 +4 
                                   2634 ;sloc1         Allocated to stack - _bp +1 +4 
                                   2635 ;------------------------------------------------------------
                           000A35  2636 	G$fuzzy_ramp$0$0 ==.
                           000A35  2637 	C$fuzzy.h$1598$1_0$65 ==.
                                   2638 ;	../../fuzzy.h:1598: float fuzzy_ramp(
                                   2639 ;	-----------------------------------------
                                   2640 ;	 function fuzzy_ramp
                                   2641 ;	-----------------------------------------
      000AEC                       2642 _fuzzy_ramp:
      000AEC C0 08            [24] 2643 	push	_bp
      000AEE 85 81 08         [24] 2644 	mov	_bp,sp
      000AF1 AF 82            [24] 2645 	mov	r7,dpl
      000AF3 AE 83            [24] 2646 	mov	r6,dph
      000AF5 AD F0            [24] 2647 	mov	r5,b
      000AF7 FC               [12] 2648 	mov	r4,a
      000AF8 E5 81            [12] 2649 	mov	a,sp
      000AFA 24 08            [12] 2650 	add	a,#0x08
      000AFC F5 81            [12] 2651 	mov	sp,a
                           000A47  2652 	C$fuzzy.h$1609$1_0$65 ==.
                                   2653 ;	../../fuzzy.h:1609: if (lower_boundary >= upper_boundary) {
      000AFE C0 07            [24] 2654 	push	ar7
      000B00 C0 06            [24] 2655 	push	ar6
      000B02 C0 05            [24] 2656 	push	ar5
      000B04 C0 04            [24] 2657 	push	ar4
      000B06 E5 08            [12] 2658 	mov	a,_bp
      000B08 24 FA            [12] 2659 	add	a,#0xfa
      000B0A F8               [12] 2660 	mov	r0,a
      000B0B E6               [12] 2661 	mov	a,@r0
      000B0C C0 E0            [24] 2662 	push	acc
      000B0E 08               [12] 2663 	inc	r0
      000B0F E6               [12] 2664 	mov	a,@r0
      000B10 C0 E0            [24] 2665 	push	acc
      000B12 08               [12] 2666 	inc	r0
      000B13 E6               [12] 2667 	mov	a,@r0
      000B14 C0 E0            [24] 2668 	push	acc
      000B16 08               [12] 2669 	inc	r0
      000B17 E6               [12] 2670 	mov	a,@r0
      000B18 C0 E0            [24] 2671 	push	acc
      000B1A 8F 82            [24] 2672 	mov	dpl, r7
      000B1C 8E 83            [24] 2673 	mov	dph, r6
      000B1E 8D F0            [24] 2674 	mov	b, r5
      000B20 EC               [12] 2675 	mov	a, r4
      000B21 12 35 C2         [24] 2676 	lcall	___fslt
      000B24 E5 81            [12] 2677 	mov	a,sp
      000B26 24 FC            [12] 2678 	add	a,#0xfc
      000B28 F5 81            [12] 2679 	mov	sp,a
      000B2A D0 04            [24] 2680 	pop	ar4
      000B2C D0 05            [24] 2681 	pop	ar5
      000B2E D0 06            [24] 2682 	pop	ar6
      000B30 D0 07            [24] 2683 	pop	ar7
      000B32 E5 82            [12] 2684 	mov	a, dpl
      000B34 24 FF            [12] 2685 	add	a,#0xff
      000B36 92 00            [24] 2686 	mov	b0,c
      000B38 40 09            [24] 2687 	jc	00102$
                           000A83  2688 	C$fuzzy.h$1610$2_0$66 ==.
                                   2689 ;	../../fuzzy.h:1610: return LEVEL_LO;
      000B3A 90 00 00         [24] 2690 	mov	dptr,#0x0000
      000B3D E4               [12] 2691 	clr	a
      000B3E F5 F0            [12] 2692 	mov	b,a
      000B40 02 0D 23         [24] 2693 	ljmp	00109$
      000B43                       2694 00102$:
                           000A8C  2695 	C$fuzzy.h$1613$1_0$65 ==.
                                   2696 ;	../../fuzzy.h:1613: if (value <= lower_boundary) {
      000B43 C0 07            [24] 2697 	push	ar7
      000B45 C0 06            [24] 2698 	push	ar6
      000B47 C0 05            [24] 2699 	push	ar5
      000B49 C0 04            [24] 2700 	push	ar4
      000B4B E5 08            [12] 2701 	mov	a,_bp
      000B4D 24 F6            [12] 2702 	add	a,#0xf6
      000B4F F8               [12] 2703 	mov	r0,a
      000B50 E6               [12] 2704 	mov	a,@r0
      000B51 C0 E0            [24] 2705 	push	acc
      000B53 08               [12] 2706 	inc	r0
      000B54 E6               [12] 2707 	mov	a,@r0
      000B55 C0 E0            [24] 2708 	push	acc
      000B57 08               [12] 2709 	inc	r0
      000B58 E6               [12] 2710 	mov	a,@r0
      000B59 C0 E0            [24] 2711 	push	acc
      000B5B 08               [12] 2712 	inc	r0
      000B5C E6               [12] 2713 	mov	a,@r0
      000B5D C0 E0            [24] 2714 	push	acc
      000B5F 8F 82            [24] 2715 	mov	dpl, r7
      000B61 8E 83            [24] 2716 	mov	dph, r6
      000B63 8D F0            [24] 2717 	mov	b, r5
      000B65 EC               [12] 2718 	mov	a, r4
      000B66 12 35 C2         [24] 2719 	lcall	___fslt
      000B69 E5 81            [12] 2720 	mov	a,sp
      000B6B 24 FC            [12] 2721 	add	a,#0xfc
      000B6D F5 81            [12] 2722 	mov	sp,a
      000B6F D0 04            [24] 2723 	pop	ar4
      000B71 D0 05            [24] 2724 	pop	ar5
      000B73 D0 06            [24] 2725 	pop	ar6
      000B75 D0 07            [24] 2726 	pop	ar7
      000B77 E5 82            [12] 2727 	mov	a, dpl
      000B79 24 FF            [12] 2728 	add	a,#0xff
      000B7B 92 00            [24] 2729 	mov	b0,c
      000B7D 40 39            [24] 2730 	jc	00107$
                           000AC8  2731 	C$fuzzy.h$1615$2_0$67 ==.
                                   2732 ;	../../fuzzy.h:1615: ramp_up
      000B7F E5 08            [12] 2733 	mov	a,_bp
      000B81 24 F5            [12] 2734 	add	a,#0xf5
      000B83 F8               [12] 2735 	mov	r0,a
      000B84 E6               [12] 2736 	mov	a,@r0
      000B85 60 0F            [24] 2737 	jz	00111$
                           000AD0  2738 	C$fuzzy.h$1616$2_0$67 ==.
                                   2739 ;	../../fuzzy.h:1616: ? LEVEL_LO
      000B87 E5 08            [12] 2740 	mov	a,_bp
      000B89 24 05            [12] 2741 	add	a,#0x05
      000B8B F8               [12] 2742 	mov	r0,a
      000B8C E4               [12] 2743 	clr	a
      000B8D F6               [12] 2744 	mov	@r0,a
      000B8E 08               [12] 2745 	inc	r0
      000B8F F6               [12] 2746 	mov	@r0,a
      000B90 08               [12] 2747 	inc	r0
      000B91 F6               [12] 2748 	mov	@r0,a
      000B92 08               [12] 2749 	inc	r0
      000B93 F6               [12] 2750 	mov	@r0,a
      000B94 80 0F            [24] 2751 	sjmp	00112$
      000B96                       2752 00111$:
                           000ADF  2753 	C$fuzzy.h$1617$2_0$67 ==.
                                   2754 ;	../../fuzzy.h:1617: : LEVEL_HI;
      000B96 E5 08            [12] 2755 	mov	a,_bp
      000B98 24 05            [12] 2756 	add	a,#0x05
      000B9A F8               [12] 2757 	mov	r0,a
      000B9B E4               [12] 2758 	clr	a
      000B9C F6               [12] 2759 	mov	@r0,a
      000B9D 08               [12] 2760 	inc	r0
      000B9E F6               [12] 2761 	mov	@r0,a
      000B9F 08               [12] 2762 	inc	r0
      000BA0 76 80            [12] 2763 	mov	@r0,#0x80
      000BA2 08               [12] 2764 	inc	r0
      000BA3 76 3F            [12] 2765 	mov	@r0,#0x3f
      000BA5                       2766 00112$:
      000BA5 E5 08            [12] 2767 	mov	a,_bp
      000BA7 24 05            [12] 2768 	add	a,#0x05
      000BA9 F8               [12] 2769 	mov	r0,a
      000BAA 86 07            [24] 2770 	mov	ar7,@r0
      000BAC 08               [12] 2771 	inc	r0
      000BAD 86 06            [24] 2772 	mov	ar6,@r0
      000BAF 08               [12] 2773 	inc	r0
      000BB0 86 05            [24] 2774 	mov	ar5,@r0
      000BB2 08               [12] 2775 	inc	r0
      000BB3 86 04            [24] 2776 	mov	ar4,@r0
      000BB5 02 0D 01         [24] 2777 	ljmp	00108$
      000BB8                       2778 00107$:
                           000B01  2779 	C$fuzzy.h$1619$1_0$65 ==.
                                   2780 ;	../../fuzzy.h:1619: else if (value >= upper_boundary) {
      000BB8 C0 07            [24] 2781 	push	ar7
      000BBA C0 06            [24] 2782 	push	ar6
      000BBC C0 05            [24] 2783 	push	ar5
      000BBE C0 04            [24] 2784 	push	ar4
      000BC0 E5 08            [12] 2785 	mov	a,_bp
      000BC2 24 FA            [12] 2786 	add	a,#0xfa
      000BC4 F8               [12] 2787 	mov	r0,a
      000BC5 E6               [12] 2788 	mov	a,@r0
      000BC6 C0 E0            [24] 2789 	push	acc
      000BC8 08               [12] 2790 	inc	r0
      000BC9 E6               [12] 2791 	mov	a,@r0
      000BCA C0 E0            [24] 2792 	push	acc
      000BCC 08               [12] 2793 	inc	r0
      000BCD E6               [12] 2794 	mov	a,@r0
      000BCE C0 E0            [24] 2795 	push	acc
      000BD0 08               [12] 2796 	inc	r0
      000BD1 E6               [12] 2797 	mov	a,@r0
      000BD2 C0 E0            [24] 2798 	push	acc
      000BD4 E5 08            [12] 2799 	mov	a,_bp
      000BD6 24 F6            [12] 2800 	add	a,#0xf6
      000BD8 F8               [12] 2801 	mov	r0,a
      000BD9 86 82            [24] 2802 	mov	dpl, @r0
      000BDB 08               [12] 2803 	inc	r0
      000BDC 86 83            [24] 2804 	mov	dph, @r0
      000BDE 08               [12] 2805 	inc	r0
      000BDF 86 F0            [24] 2806 	mov	b, @r0
      000BE1 08               [12] 2807 	inc	r0
      000BE2 E6               [12] 2808 	mov	a, @r0
      000BE3 12 35 C2         [24] 2809 	lcall	___fslt
      000BE6 E5 81            [12] 2810 	mov	a,sp
      000BE8 24 FC            [12] 2811 	add	a,#0xfc
      000BEA F5 81            [12] 2812 	mov	sp,a
      000BEC D0 04            [24] 2813 	pop	ar4
      000BEE D0 05            [24] 2814 	pop	ar5
      000BF0 D0 06            [24] 2815 	pop	ar6
      000BF2 D0 07            [24] 2816 	pop	ar7
      000BF4 E5 82            [12] 2817 	mov	a, dpl
      000BF6 24 FF            [12] 2818 	add	a,#0xff
      000BF8 92 00            [24] 2819 	mov	b0,c
      000BFA 40 39            [24] 2820 	jc	00104$
                           000B45  2821 	C$fuzzy.h$1621$2_0$68 ==.
                                   2822 ;	../../fuzzy.h:1621: ramp_up
      000BFC E5 08            [12] 2823 	mov	a,_bp
      000BFE 24 F5            [12] 2824 	add	a,#0xf5
      000C00 F8               [12] 2825 	mov	r0,a
      000C01 E6               [12] 2826 	mov	a,@r0
      000C02 60 11            [24] 2827 	jz	00113$
                           000B4D  2828 	C$fuzzy.h$1622$2_0$68 ==.
                                   2829 ;	../../fuzzy.h:1622: ? LEVEL_HI
      000C04 E5 08            [12] 2830 	mov	a,_bp
      000C06 24 05            [12] 2831 	add	a,#0x05
      000C08 F8               [12] 2832 	mov	r0,a
      000C09 E4               [12] 2833 	clr	a
      000C0A F6               [12] 2834 	mov	@r0,a
      000C0B 08               [12] 2835 	inc	r0
      000C0C F6               [12] 2836 	mov	@r0,a
      000C0D 08               [12] 2837 	inc	r0
      000C0E 76 80            [12] 2838 	mov	@r0,#0x80
      000C10 08               [12] 2839 	inc	r0
      000C11 76 3F            [12] 2840 	mov	@r0,#0x3f
      000C13 80 0D            [24] 2841 	sjmp	00114$
      000C15                       2842 00113$:
                           000B5E  2843 	C$fuzzy.h$1623$2_0$68 ==.
                                   2844 ;	../../fuzzy.h:1623: : LEVEL_LO;
      000C15 E5 08            [12] 2845 	mov	a,_bp
      000C17 24 05            [12] 2846 	add	a,#0x05
      000C19 F8               [12] 2847 	mov	r0,a
      000C1A E4               [12] 2848 	clr	a
      000C1B F6               [12] 2849 	mov	@r0,a
      000C1C 08               [12] 2850 	inc	r0
      000C1D F6               [12] 2851 	mov	@r0,a
      000C1E 08               [12] 2852 	inc	r0
      000C1F F6               [12] 2853 	mov	@r0,a
      000C20 08               [12] 2854 	inc	r0
      000C21 F6               [12] 2855 	mov	@r0,a
      000C22                       2856 00114$:
      000C22 E5 08            [12] 2857 	mov	a,_bp
      000C24 24 05            [12] 2858 	add	a,#0x05
      000C26 F8               [12] 2859 	mov	r0,a
      000C27 86 07            [24] 2860 	mov	ar7,@r0
      000C29 08               [12] 2861 	inc	r0
      000C2A 86 06            [24] 2862 	mov	ar6,@r0
      000C2C 08               [12] 2863 	inc	r0
      000C2D 86 05            [24] 2864 	mov	ar5,@r0
      000C2F 08               [12] 2865 	inc	r0
      000C30 86 04            [24] 2866 	mov	ar4,@r0
      000C32 02 0D 01         [24] 2867 	ljmp	00108$
      000C35                       2868 00104$:
                           000B7E  2869 	C$fuzzy.h$1627$1_0$65 ==.
                                   2870 ;	../../fuzzy.h:1627: (value - lower_boundary) /
      000C35 C0 07            [24] 2871 	push	ar7
      000C37 C0 06            [24] 2872 	push	ar6
      000C39 C0 05            [24] 2873 	push	ar5
      000C3B C0 04            [24] 2874 	push	ar4
      000C3D C0 07            [24] 2875 	push	ar7
      000C3F C0 06            [24] 2876 	push	ar6
      000C41 C0 05            [24] 2877 	push	ar5
      000C43 C0 04            [24] 2878 	push	ar4
                           000B8E  2879 	C$fuzzy.h$1628$1_0$65 ==.
                                   2880 ;	../../fuzzy.h:1628: (upper_boundary - lower_boundary);
      000C45 E5 08            [12] 2881 	mov	a,_bp
      000C47 24 F6            [12] 2882 	add	a,#0xf6
      000C49 F8               [12] 2883 	mov	r0,a
      000C4A 86 82            [24] 2884 	mov	dpl, @r0
      000C4C 08               [12] 2885 	inc	r0
      000C4D 86 83            [24] 2886 	mov	dph, @r0
      000C4F 08               [12] 2887 	inc	r0
      000C50 86 F0            [24] 2888 	mov	b, @r0
      000C52 08               [12] 2889 	inc	r0
      000C53 E6               [12] 2890 	mov	a, @r0
      000C54 12 34 87         [24] 2891 	lcall	___fssub
      000C57 A8 08            [24] 2892 	mov	r0,_bp
      000C59 08               [12] 2893 	inc	r0
      000C5A A6 82            [24] 2894 	mov	@r0, dpl
      000C5C 08               [12] 2895 	inc	r0
      000C5D A6 83            [24] 2896 	mov	@r0, dph
      000C5F 08               [12] 2897 	inc	r0
      000C60 A6 F0            [24] 2898 	mov	@r0, b
      000C62 08               [12] 2899 	inc	r0
      000C63 F6               [12] 2900 	mov	@r0,a
      000C64 E5 81            [12] 2901 	mov	a,sp
      000C66 24 FC            [12] 2902 	add	a,#0xfc
      000C68 F5 81            [12] 2903 	mov	sp,a
      000C6A E5 08            [12] 2904 	mov	a,_bp
      000C6C 24 FA            [12] 2905 	add	a,#0xfa
      000C6E F8               [12] 2906 	mov	r0,a
      000C6F 86 82            [24] 2907 	mov	dpl, @r0
      000C71 08               [12] 2908 	inc	r0
      000C72 86 83            [24] 2909 	mov	dph, @r0
      000C74 08               [12] 2910 	inc	r0
      000C75 86 F0            [24] 2911 	mov	b, @r0
      000C77 08               [12] 2912 	inc	r0
      000C78 E6               [12] 2913 	mov	a, @r0
      000C79 12 34 87         [24] 2914 	lcall	___fssub
      000C7C AC 82            [24] 2915 	mov	r4, dpl
      000C7E AD 83            [24] 2916 	mov	r5, dph
      000C80 AE F0            [24] 2917 	mov	r6, b
      000C82 FF               [12] 2918 	mov	r7, a
      000C83 E5 81            [12] 2919 	mov	a,sp
      000C85 24 FC            [12] 2920 	add	a,#0xfc
      000C87 F5 81            [12] 2921 	mov	sp,a
      000C89 C0 04            [24] 2922 	push	ar4
      000C8B C0 05            [24] 2923 	push	ar5
      000C8D C0 06            [24] 2924 	push	ar6
      000C8F C0 07            [24] 2925 	push	ar7
                           000BDA  2926 	C$fuzzy.h$1631$1_0$65 ==.
                                   2927 ;	../../fuzzy.h:1631: ramp_up
      000C91 A8 08            [24] 2928 	mov	r0,_bp
      000C93 08               [12] 2929 	inc	r0
      000C94 86 82            [24] 2930 	mov	dpl, @r0
      000C96 08               [12] 2931 	inc	r0
      000C97 86 83            [24] 2932 	mov	dph, @r0
      000C99 08               [12] 2933 	inc	r0
      000C9A 86 F0            [24] 2934 	mov	b, @r0
      000C9C 08               [12] 2935 	inc	r0
      000C9D E6               [12] 2936 	mov	a, @r0
      000C9E 12 37 2B         [24] 2937 	lcall	___fsdiv
      000CA1 AC 82            [24] 2938 	mov	r4, dpl
      000CA3 AD 83            [24] 2939 	mov	r5, dph
      000CA5 AE F0            [24] 2940 	mov	r6, b
      000CA7 FF               [12] 2941 	mov	r7, a
      000CA8 E5 81            [12] 2942 	mov	a,sp
      000CAA 24 FC            [12] 2943 	add	a,#0xfc
      000CAC F5 81            [12] 2944 	mov	sp,a
      000CAE E5 08            [12] 2945 	mov	a,_bp
      000CB0 24 F5            [12] 2946 	add	a,#0xf5
      000CB2 F8               [12] 2947 	mov	r0,a
      000CB3 E6               [12] 2948 	mov	a,@r0
      000CB4 60 12            [24] 2949 	jz	00115$
                           000BFF  2950 	C$fuzzy.h$1632$2_0$69 ==.
                                   2951 ;	../../fuzzy.h:1632: ? normalized
      000CB6 E5 08            [12] 2952 	mov	a,_bp
      000CB8 24 05            [12] 2953 	add	a,#0x05
      000CBA F8               [12] 2954 	mov	r0,a
      000CBB A6 04            [24] 2955 	mov	@r0,ar4
      000CBD 08               [12] 2956 	inc	r0
      000CBE A6 05            [24] 2957 	mov	@r0,ar5
      000CC0 08               [12] 2958 	inc	r0
      000CC1 A6 06            [24] 2959 	mov	@r0,ar6
      000CC3 08               [12] 2960 	inc	r0
      000CC4 A6 07            [24] 2961 	mov	@r0,ar7
      000CC6 80 29            [24] 2962 	sjmp	00116$
      000CC8                       2963 00115$:
                           000C11  2964 	C$fuzzy.h$1633$1_0$65 ==.
                                   2965 ;	../../fuzzy.h:1633: : LEVEL_HI - normalized;
      000CC8 C0 04            [24] 2966 	push	ar4
      000CCA C0 05            [24] 2967 	push	ar5
      000CCC C0 06            [24] 2968 	push	ar6
      000CCE C0 07            [24] 2969 	push	ar7
      000CD0 90 00 00         [24] 2970 	mov	dptr,#0x0000
      000CD3 75 F0 80         [24] 2971 	mov	b, #0x80
      000CD6 74 3F            [12] 2972 	mov	a, #0x3f
      000CD8 12 34 87         [24] 2973 	lcall	___fssub
      000CDB C8               [12] 2974 	xch	a,r0
      000CDC E5 08            [12] 2975 	mov	a,_bp
      000CDE 24 05            [12] 2976 	add	a,#0x05
      000CE0 C8               [12] 2977 	xch	a,r0
      000CE1 A6 82            [24] 2978 	mov	@r0, dpl
      000CE3 08               [12] 2979 	inc	r0
      000CE4 A6 83            [24] 2980 	mov	@r0, dph
      000CE6 08               [12] 2981 	inc	r0
      000CE7 A6 F0            [24] 2982 	mov	@r0, b
      000CE9 08               [12] 2983 	inc	r0
      000CEA F6               [12] 2984 	mov	@r0,a
      000CEB E5 81            [12] 2985 	mov	a,sp
      000CED 24 FC            [12] 2986 	add	a,#0xfc
      000CEF F5 81            [12] 2987 	mov	sp,a
      000CF1                       2988 00116$:
      000CF1 E5 08            [12] 2989 	mov	a,_bp
      000CF3 24 05            [12] 2990 	add	a,#0x05
      000CF5 F8               [12] 2991 	mov	r0,a
      000CF6 86 07            [24] 2992 	mov	ar7,@r0
      000CF8 08               [12] 2993 	inc	r0
      000CF9 86 06            [24] 2994 	mov	ar6,@r0
      000CFB 08               [12] 2995 	inc	r0
      000CFC 86 05            [24] 2996 	mov	ar5,@r0
      000CFE 08               [12] 2997 	inc	r0
      000CFF 86 04            [24] 2998 	mov	ar4,@r0
      000D01                       2999 00108$:
                           000C4A  3000 	C$fuzzy.h$1637$1_0$65 ==.
                                   3001 ;	../../fuzzy.h:1637: result,
      000D01 E5 08            [12] 3002 	mov	a,_bp
      000D03 24 F4            [12] 3003 	add	a,#0xf4
      000D05 F8               [12] 3004 	mov	r0,a
      000D06 E6               [12] 3005 	mov	a,@r0
      000D07 C0 E0            [24] 3006 	push	acc
      000D09 8F 82            [24] 3007 	mov	dpl, r7
      000D0B 8E 83            [24] 3008 	mov	dph, r6
      000D0D 8D F0            [24] 3009 	mov	b, r5
      000D0F EC               [12] 3010 	mov	a, r4
      000D10 12 01 99         [24] 3011 	lcall	_fuzzy_apply_hedge
      000D13 AC 82            [24] 3012 	mov	r4, dpl
      000D15 AD 83            [24] 3013 	mov	r5, dph
      000D17 AE F0            [24] 3014 	mov	r6, b
      000D19 FF               [12] 3015 	mov	r7, a
      000D1A 15 81            [12] 3016 	dec	sp
      000D1C 8C 82            [24] 3017 	mov	dpl, r4
      000D1E 8D 83            [24] 3018 	mov	dph, r5
      000D20 8E F0            [24] 3019 	mov	b, r6
      000D22 EF               [12] 3020 	mov	a, r7
      000D23                       3021 00109$:
                           000C6C  3022 	C$fuzzy.h$1640$1_0$65 ==.
                                   3023 ;	../../fuzzy.h:1640: }
      000D23 85 08 81         [24] 3024 	mov	sp,_bp
      000D26 D0 08            [24] 3025 	pop	_bp
                           000C71  3026 	C$fuzzy.h$1640$1_0$65 ==.
                           000C71  3027 	XG$fuzzy_ramp$0$0 ==.
      000D28 22               [24] 3028 	ret
                                   3029 ;------------------------------------------------------------
                                   3030 ;Allocation info for local variables in function 'fuzzy_triangle'
                                   3031 ;------------------------------------------------------------
                                   3032 ;b             Allocated to stack - _bp -6 +4 
                                   3033 ;c             Allocated to stack - _bp -10 +4 
                                   3034 ;value         Allocated to stack - _bp -14 +4 
                                   3035 ;hedge         Allocated to stack - _bp -15 +1 
                                   3036 ;a             Allocated to registers r7 r6 r5 r4 
                                   3037 ;result        Allocated to stack - _bp +1 +4 
                                   3038 ;sloc0         Allocated to stack - _bp +1 +4 
                                   3039 ;sloc1         Allocated to stack - _bp +5 +4 
                                   3040 ;------------------------------------------------------------
                           000C72  3041 	G$fuzzy_triangle$0$0 ==.
                           000C72  3042 	C$fuzzy.h$1684$1_0$71 ==.
                                   3043 ;	../../fuzzy.h:1684: float fuzzy_triangle(
                                   3044 ;	-----------------------------------------
                                   3045 ;	 function fuzzy_triangle
                                   3046 ;	-----------------------------------------
      000D29                       3047 _fuzzy_triangle:
      000D29 C0 08            [24] 3048 	push	_bp
      000D2B 85 81 08         [24] 3049 	mov	_bp,sp
      000D2E AF 82            [24] 3050 	mov	r7,dpl
      000D30 AE 83            [24] 3051 	mov	r6,dph
      000D32 AD F0            [24] 3052 	mov	r5,b
      000D34 FC               [12] 3053 	mov	r4,a
      000D35 E5 81            [12] 3054 	mov	a,sp
      000D37 24 08            [12] 3055 	add	a,#0x08
      000D39 F5 81            [12] 3056 	mov	sp,a
                           000C84  3057 	C$fuzzy.h$1695$1_0$71 ==.
                                   3058 ;	../../fuzzy.h:1695: a >= b ||
      000D3B C0 07            [24] 3059 	push	ar7
      000D3D C0 06            [24] 3060 	push	ar6
      000D3F C0 05            [24] 3061 	push	ar5
      000D41 C0 04            [24] 3062 	push	ar4
      000D43 E5 08            [12] 3063 	mov	a,_bp
      000D45 24 FA            [12] 3064 	add	a,#0xfa
      000D47 F8               [12] 3065 	mov	r0,a
      000D48 E6               [12] 3066 	mov	a,@r0
      000D49 C0 E0            [24] 3067 	push	acc
      000D4B 08               [12] 3068 	inc	r0
      000D4C E6               [12] 3069 	mov	a,@r0
      000D4D C0 E0            [24] 3070 	push	acc
      000D4F 08               [12] 3071 	inc	r0
      000D50 E6               [12] 3072 	mov	a,@r0
      000D51 C0 E0            [24] 3073 	push	acc
      000D53 08               [12] 3074 	inc	r0
      000D54 E6               [12] 3075 	mov	a,@r0
      000D55 C0 E0            [24] 3076 	push	acc
      000D57 8F 82            [24] 3077 	mov	dpl, r7
      000D59 8E 83            [24] 3078 	mov	dph, r6
      000D5B 8D F0            [24] 3079 	mov	b, r5
      000D5D EC               [12] 3080 	mov	a, r4
      000D5E 12 35 C2         [24] 3081 	lcall	___fslt
      000D61 E5 81            [12] 3082 	mov	a,sp
      000D63 24 FC            [12] 3083 	add	a,#0xfc
      000D65 F5 81            [12] 3084 	mov	sp,a
      000D67 D0 04            [24] 3085 	pop	ar4
      000D69 D0 05            [24] 3086 	pop	ar5
      000D6B D0 06            [24] 3087 	pop	ar6
      000D6D D0 07            [24] 3088 	pop	ar7
      000D6F E5 82            [12] 3089 	mov	a, dpl
      000D71 24 FF            [12] 3090 	add	a,#0xff
      000D73 92 00            [24] 3091 	mov	b0,c
      000D75 40 03            [24] 3092 	jc	00145$
      000D77 02 0E 41         [24] 3093 	ljmp	00107$
      000D7A                       3094 00145$:
                           000CC3  3095 	C$fuzzy.h$1696$1_0$71 ==.
                                   3096 ;	../../fuzzy.h:1696: b >= c ||
      000D7A C0 07            [24] 3097 	push	ar7
      000D7C C0 06            [24] 3098 	push	ar6
      000D7E C0 05            [24] 3099 	push	ar5
      000D80 C0 04            [24] 3100 	push	ar4
      000D82 E5 08            [12] 3101 	mov	a,_bp
      000D84 24 F6            [12] 3102 	add	a,#0xf6
      000D86 F8               [12] 3103 	mov	r0,a
      000D87 E6               [12] 3104 	mov	a,@r0
      000D88 C0 E0            [24] 3105 	push	acc
      000D8A 08               [12] 3106 	inc	r0
      000D8B E6               [12] 3107 	mov	a,@r0
      000D8C C0 E0            [24] 3108 	push	acc
      000D8E 08               [12] 3109 	inc	r0
      000D8F E6               [12] 3110 	mov	a,@r0
      000D90 C0 E0            [24] 3111 	push	acc
      000D92 08               [12] 3112 	inc	r0
      000D93 E6               [12] 3113 	mov	a,@r0
      000D94 C0 E0            [24] 3114 	push	acc
      000D96 E5 08            [12] 3115 	mov	a,_bp
      000D98 24 FA            [12] 3116 	add	a,#0xfa
      000D9A F8               [12] 3117 	mov	r0,a
      000D9B 86 82            [24] 3118 	mov	dpl, @r0
      000D9D 08               [12] 3119 	inc	r0
      000D9E 86 83            [24] 3120 	mov	dph, @r0
      000DA0 08               [12] 3121 	inc	r0
      000DA1 86 F0            [24] 3122 	mov	b, @r0
      000DA3 08               [12] 3123 	inc	r0
      000DA4 E6               [12] 3124 	mov	a, @r0
      000DA5 12 35 C2         [24] 3125 	lcall	___fslt
      000DA8 E5 81            [12] 3126 	mov	a,sp
      000DAA 24 FC            [12] 3127 	add	a,#0xfc
      000DAC F5 81            [12] 3128 	mov	sp,a
      000DAE D0 04            [24] 3129 	pop	ar4
      000DB0 D0 05            [24] 3130 	pop	ar5
      000DB2 D0 06            [24] 3131 	pop	ar6
      000DB4 D0 07            [24] 3132 	pop	ar7
      000DB6 E5 82            [12] 3133 	mov	a, dpl
      000DB8 24 FF            [12] 3134 	add	a,#0xff
      000DBA 92 00            [24] 3135 	mov	b0,c
      000DBC 40 03            [24] 3136 	jc	00146$
      000DBE 02 0E 41         [24] 3137 	ljmp	00107$
      000DC1                       3138 00146$:
                           000D0A  3139 	C$fuzzy.h$1697$1_0$71 ==.
                                   3140 ;	../../fuzzy.h:1697: value <= a ||
      000DC1 C0 07            [24] 3141 	push	ar7
      000DC3 C0 06            [24] 3142 	push	ar6
      000DC5 C0 05            [24] 3143 	push	ar5
      000DC7 C0 04            [24] 3144 	push	ar4
      000DC9 E5 08            [12] 3145 	mov	a,_bp
      000DCB 24 F2            [12] 3146 	add	a,#0xf2
      000DCD F8               [12] 3147 	mov	r0,a
      000DCE E6               [12] 3148 	mov	a,@r0
      000DCF C0 E0            [24] 3149 	push	acc
      000DD1 08               [12] 3150 	inc	r0
      000DD2 E6               [12] 3151 	mov	a,@r0
      000DD3 C0 E0            [24] 3152 	push	acc
      000DD5 08               [12] 3153 	inc	r0
      000DD6 E6               [12] 3154 	mov	a,@r0
      000DD7 C0 E0            [24] 3155 	push	acc
      000DD9 08               [12] 3156 	inc	r0
      000DDA E6               [12] 3157 	mov	a,@r0
      000DDB C0 E0            [24] 3158 	push	acc
      000DDD 8F 82            [24] 3159 	mov	dpl, r7
      000DDF 8E 83            [24] 3160 	mov	dph, r6
      000DE1 8D F0            [24] 3161 	mov	b, r5
      000DE3 EC               [12] 3162 	mov	a, r4
      000DE4 12 35 C2         [24] 3163 	lcall	___fslt
      000DE7 E5 81            [12] 3164 	mov	a,sp
      000DE9 24 FC            [12] 3165 	add	a,#0xfc
      000DEB F5 81            [12] 3166 	mov	sp,a
      000DED D0 04            [24] 3167 	pop	ar4
      000DEF D0 05            [24] 3168 	pop	ar5
      000DF1 D0 06            [24] 3169 	pop	ar6
      000DF3 D0 07            [24] 3170 	pop	ar7
      000DF5 E5 82            [12] 3171 	mov	a, dpl
      000DF7 24 FF            [12] 3172 	add	a,#0xff
      000DF9 92 00            [24] 3173 	mov	b0,c
      000DFB 50 44            [24] 3174 	jnc	00107$
                           000D46  3175 	C$fuzzy.h$1699$1_0$71 ==.
                                   3176 ;	../../fuzzy.h:1699: ) {
      000DFD C0 07            [24] 3177 	push	ar7
      000DFF C0 06            [24] 3178 	push	ar6
      000E01 C0 05            [24] 3179 	push	ar5
      000E03 C0 04            [24] 3180 	push	ar4
      000E05 E5 08            [12] 3181 	mov	a,_bp
      000E07 24 F6            [12] 3182 	add	a,#0xf6
      000E09 F8               [12] 3183 	mov	r0,a
      000E0A E6               [12] 3184 	mov	a,@r0
      000E0B C0 E0            [24] 3185 	push	acc
      000E0D 08               [12] 3186 	inc	r0
      000E0E E6               [12] 3187 	mov	a,@r0
      000E0F C0 E0            [24] 3188 	push	acc
      000E11 08               [12] 3189 	inc	r0
      000E12 E6               [12] 3190 	mov	a,@r0
      000E13 C0 E0            [24] 3191 	push	acc
      000E15 08               [12] 3192 	inc	r0
      000E16 E6               [12] 3193 	mov	a,@r0
      000E17 C0 E0            [24] 3194 	push	acc
      000E19 E5 08            [12] 3195 	mov	a,_bp
      000E1B 24 F2            [12] 3196 	add	a,#0xf2
      000E1D F8               [12] 3197 	mov	r0,a
      000E1E 86 82            [24] 3198 	mov	dpl, @r0
      000E20 08               [12] 3199 	inc	r0
      000E21 86 83            [24] 3200 	mov	dph, @r0
      000E23 08               [12] 3201 	inc	r0
      000E24 86 F0            [24] 3202 	mov	b, @r0
      000E26 08               [12] 3203 	inc	r0
      000E27 E6               [12] 3204 	mov	a, @r0
      000E28 12 35 C2         [24] 3205 	lcall	___fslt
      000E2B E5 81            [12] 3206 	mov	a,sp
      000E2D 24 FC            [12] 3207 	add	a,#0xfc
      000E2F F5 81            [12] 3208 	mov	sp,a
      000E31 D0 04            [24] 3209 	pop	ar4
      000E33 D0 05            [24] 3210 	pop	ar5
      000E35 D0 06            [24] 3211 	pop	ar6
      000E37 D0 07            [24] 3212 	pop	ar7
      000E39 E5 82            [12] 3213 	mov	a, dpl
      000E3B 24 FF            [12] 3214 	add	a,#0xff
      000E3D 92 00            [24] 3215 	mov	b0,c
      000E3F 40 0E            [24] 3216 	jc	00108$
      000E41                       3217 00107$:
                           000D8A  3218 	C$fuzzy.h$1700$2_0$72 ==.
                                   3219 ;	../../fuzzy.h:1700: result = LEVEL_LO;
      000E41 A8 08            [24] 3220 	mov	r0,_bp
      000E43 08               [12] 3221 	inc	r0
      000E44 E4               [12] 3222 	clr	a
      000E45 F6               [12] 3223 	mov	@r0,a
      000E46 08               [12] 3224 	inc	r0
      000E47 F6               [12] 3225 	mov	@r0,a
      000E48 08               [12] 3226 	inc	r0
      000E49 F6               [12] 3227 	mov	@r0,a
      000E4A 08               [12] 3228 	inc	r0
      000E4B F6               [12] 3229 	mov	@r0,a
      000E4C 02 10 07         [24] 3230 	ljmp	00109$
      000E4F                       3231 00108$:
                           000D98  3232 	C$fuzzy.h$1702$1_0$71 ==.
                                   3233 ;	../../fuzzy.h:1702: else if (value == b) {
      000E4F C0 07            [24] 3234 	push	ar7
      000E51 C0 06            [24] 3235 	push	ar6
      000E53 C0 05            [24] 3236 	push	ar5
      000E55 C0 04            [24] 3237 	push	ar4
      000E57 E5 08            [12] 3238 	mov	a,_bp
      000E59 24 FA            [12] 3239 	add	a,#0xfa
      000E5B F8               [12] 3240 	mov	r0,a
      000E5C E6               [12] 3241 	mov	a,@r0
      000E5D C0 E0            [24] 3242 	push	acc
      000E5F 08               [12] 3243 	inc	r0
      000E60 E6               [12] 3244 	mov	a,@r0
      000E61 C0 E0            [24] 3245 	push	acc
      000E63 08               [12] 3246 	inc	r0
      000E64 E6               [12] 3247 	mov	a,@r0
      000E65 C0 E0            [24] 3248 	push	acc
      000E67 08               [12] 3249 	inc	r0
      000E68 E6               [12] 3250 	mov	a,@r0
      000E69 C0 E0            [24] 3251 	push	acc
      000E6B E5 08            [12] 3252 	mov	a,_bp
      000E6D 24 F2            [12] 3253 	add	a,#0xf2
      000E6F F8               [12] 3254 	mov	r0,a
      000E70 86 82            [24] 3255 	mov	dpl, @r0
      000E72 08               [12] 3256 	inc	r0
      000E73 86 83            [24] 3257 	mov	dph, @r0
      000E75 08               [12] 3258 	inc	r0
      000E76 86 F0            [24] 3259 	mov	b, @r0
      000E78 08               [12] 3260 	inc	r0
      000E79 E6               [12] 3261 	mov	a, @r0
      000E7A 12 35 96         [24] 3262 	lcall	___fseq
      000E7D AB 82            [24] 3263 	mov	r3, dpl
      000E7F E5 81            [12] 3264 	mov	a,sp
      000E81 24 FC            [12] 3265 	add	a,#0xfc
      000E83 F5 81            [12] 3266 	mov	sp,a
      000E85 D0 04            [24] 3267 	pop	ar4
      000E87 D0 05            [24] 3268 	pop	ar5
      000E89 D0 06            [24] 3269 	pop	ar6
      000E8B D0 07            [24] 3270 	pop	ar7
      000E8D EB               [12] 3271 	mov	a,r3
      000E8E 60 10            [24] 3272 	jz	00105$
                           000DD9  3273 	C$fuzzy.h$1703$2_0$73 ==.
                                   3274 ;	../../fuzzy.h:1703: result = LEVEL_HI;
      000E90 A8 08            [24] 3275 	mov	r0,_bp
      000E92 08               [12] 3276 	inc	r0
      000E93 E4               [12] 3277 	clr	a
      000E94 F6               [12] 3278 	mov	@r0,a
      000E95 08               [12] 3279 	inc	r0
      000E96 F6               [12] 3280 	mov	@r0,a
      000E97 08               [12] 3281 	inc	r0
      000E98 76 80            [12] 3282 	mov	@r0,#0x80
      000E9A 08               [12] 3283 	inc	r0
      000E9B 76 3F            [12] 3284 	mov	@r0,#0x3f
      000E9D 02 10 07         [24] 3285 	ljmp	00109$
      000EA0                       3286 00105$:
                           000DE9  3287 	C$fuzzy.h$1705$1_0$71 ==.
                                   3288 ;	../../fuzzy.h:1705: else if (value < b) {
      000EA0 C0 07            [24] 3289 	push	ar7
      000EA2 C0 06            [24] 3290 	push	ar6
      000EA4 C0 05            [24] 3291 	push	ar5
      000EA6 C0 04            [24] 3292 	push	ar4
      000EA8 E5 08            [12] 3293 	mov	a,_bp
      000EAA 24 FA            [12] 3294 	add	a,#0xfa
      000EAC F8               [12] 3295 	mov	r0,a
      000EAD E6               [12] 3296 	mov	a,@r0
      000EAE C0 E0            [24] 3297 	push	acc
      000EB0 08               [12] 3298 	inc	r0
      000EB1 E6               [12] 3299 	mov	a,@r0
      000EB2 C0 E0            [24] 3300 	push	acc
      000EB4 08               [12] 3301 	inc	r0
      000EB5 E6               [12] 3302 	mov	a,@r0
      000EB6 C0 E0            [24] 3303 	push	acc
      000EB8 08               [12] 3304 	inc	r0
      000EB9 E6               [12] 3305 	mov	a,@r0
      000EBA C0 E0            [24] 3306 	push	acc
      000EBC E5 08            [12] 3307 	mov	a,_bp
      000EBE 24 F2            [12] 3308 	add	a,#0xf2
      000EC0 F8               [12] 3309 	mov	r0,a
      000EC1 86 82            [24] 3310 	mov	dpl, @r0
      000EC3 08               [12] 3311 	inc	r0
      000EC4 86 83            [24] 3312 	mov	dph, @r0
      000EC6 08               [12] 3313 	inc	r0
      000EC7 86 F0            [24] 3314 	mov	b, @r0
      000EC9 08               [12] 3315 	inc	r0
      000ECA E6               [12] 3316 	mov	a, @r0
      000ECB 12 35 C2         [24] 3317 	lcall	___fslt
      000ECE AB 82            [24] 3318 	mov	r3, dpl
      000ED0 E5 81            [12] 3319 	mov	a,sp
      000ED2 24 FC            [12] 3320 	add	a,#0xfc
      000ED4 F5 81            [12] 3321 	mov	sp,a
      000ED6 D0 04            [24] 3322 	pop	ar4
      000ED8 D0 05            [24] 3323 	pop	ar5
      000EDA D0 06            [24] 3324 	pop	ar6
      000EDC D0 07            [24] 3325 	pop	ar7
      000EDE EB               [12] 3326 	mov	a,r3
      000EDF 70 03            [24] 3327 	jnz	00150$
      000EE1 02 0F 6B         [24] 3328 	ljmp	00102$
      000EE4                       3329 00150$:
                           000E2D  3330 	C$fuzzy.h$1707$1_0$71 ==.
                                   3331 ;	../../fuzzy.h:1707: (value - a) /
      000EE4 C0 07            [24] 3332 	push	ar7
      000EE6 C0 06            [24] 3333 	push	ar6
      000EE8 C0 05            [24] 3334 	push	ar5
      000EEA C0 04            [24] 3335 	push	ar4
      000EEC C0 07            [24] 3336 	push	ar7
      000EEE C0 06            [24] 3337 	push	ar6
      000EF0 C0 05            [24] 3338 	push	ar5
      000EF2 C0 04            [24] 3339 	push	ar4
                           000E3D  3340 	C$fuzzy.h$1708$1_0$71 ==.
                                   3341 ;	../../fuzzy.h:1708: (b - a);
      000EF4 E5 08            [12] 3342 	mov	a,_bp
      000EF6 24 F2            [12] 3343 	add	a,#0xf2
      000EF8 F8               [12] 3344 	mov	r0,a
      000EF9 86 82            [24] 3345 	mov	dpl, @r0
      000EFB 08               [12] 3346 	inc	r0
      000EFC 86 83            [24] 3347 	mov	dph, @r0
      000EFE 08               [12] 3348 	inc	r0
      000EFF 86 F0            [24] 3349 	mov	b, @r0
      000F01 08               [12] 3350 	inc	r0
      000F02 E6               [12] 3351 	mov	a, @r0
      000F03 12 34 87         [24] 3352 	lcall	___fssub
      000F06 C8               [12] 3353 	xch	a,r0
      000F07 E5 08            [12] 3354 	mov	a,_bp
      000F09 24 05            [12] 3355 	add	a,#0x05
      000F0B C8               [12] 3356 	xch	a,r0
      000F0C A6 82            [24] 3357 	mov	@r0, dpl
      000F0E 08               [12] 3358 	inc	r0
      000F0F A6 83            [24] 3359 	mov	@r0, dph
      000F11 08               [12] 3360 	inc	r0
      000F12 A6 F0            [24] 3361 	mov	@r0, b
      000F14 08               [12] 3362 	inc	r0
      000F15 F6               [12] 3363 	mov	@r0,a
      000F16 E5 81            [12] 3364 	mov	a,sp
      000F18 24 FC            [12] 3365 	add	a,#0xfc
      000F1A F5 81            [12] 3366 	mov	sp,a
      000F1C E5 08            [12] 3367 	mov	a,_bp
      000F1E 24 FA            [12] 3368 	add	a,#0xfa
      000F20 F8               [12] 3369 	mov	r0,a
      000F21 86 82            [24] 3370 	mov	dpl, @r0
      000F23 08               [12] 3371 	inc	r0
      000F24 86 83            [24] 3372 	mov	dph, @r0
      000F26 08               [12] 3373 	inc	r0
      000F27 86 F0            [24] 3374 	mov	b, @r0
      000F29 08               [12] 3375 	inc	r0
      000F2A E6               [12] 3376 	mov	a, @r0
      000F2B 12 34 87         [24] 3377 	lcall	___fssub
      000F2E AC 82            [24] 3378 	mov	r4, dpl
      000F30 AD 83            [24] 3379 	mov	r5, dph
      000F32 AE F0            [24] 3380 	mov	r6, b
      000F34 FF               [12] 3381 	mov	r7, a
      000F35 E5 81            [12] 3382 	mov	a,sp
      000F37 24 FC            [12] 3383 	add	a,#0xfc
      000F39 F5 81            [12] 3384 	mov	sp,a
      000F3B C0 04            [24] 3385 	push	ar4
      000F3D C0 05            [24] 3386 	push	ar5
      000F3F C0 06            [24] 3387 	push	ar6
      000F41 C0 07            [24] 3388 	push	ar7
      000F43 E5 08            [12] 3389 	mov	a,_bp
      000F45 24 05            [12] 3390 	add	a,#0x05
      000F47 F8               [12] 3391 	mov	r0,a
      000F48 86 82            [24] 3392 	mov	dpl, @r0
      000F4A 08               [12] 3393 	inc	r0
      000F4B 86 83            [24] 3394 	mov	dph, @r0
      000F4D 08               [12] 3395 	inc	r0
      000F4E 86 F0            [24] 3396 	mov	b, @r0
      000F50 08               [12] 3397 	inc	r0
      000F51 E6               [12] 3398 	mov	a, @r0
      000F52 12 37 2B         [24] 3399 	lcall	___fsdiv
      000F55 A8 08            [24] 3400 	mov	r0,_bp
      000F57 08               [12] 3401 	inc	r0
      000F58 A6 82            [24] 3402 	mov	@r0, dpl
      000F5A 08               [12] 3403 	inc	r0
      000F5B A6 83            [24] 3404 	mov	@r0, dph
      000F5D 08               [12] 3405 	inc	r0
      000F5E A6 F0            [24] 3406 	mov	@r0, b
      000F60 08               [12] 3407 	inc	r0
      000F61 F6               [12] 3408 	mov	@r0,a
      000F62 E5 81            [12] 3409 	mov	a,sp
      000F64 24 FC            [12] 3410 	add	a,#0xfc
      000F66 F5 81            [12] 3411 	mov	sp,a
      000F68 02 10 07         [24] 3412 	ljmp	00109$
      000F6B                       3413 00102$:
                           000EB4  3414 	C$fuzzy.h$1712$1_0$71 ==.
                                   3415 ;	../../fuzzy.h:1712: (c - value) /
      000F6B E5 08            [12] 3416 	mov	a,_bp
      000F6D 24 F2            [12] 3417 	add	a,#0xf2
      000F6F F8               [12] 3418 	mov	r0,a
      000F70 E6               [12] 3419 	mov	a,@r0
      000F71 C0 E0            [24] 3420 	push	acc
      000F73 08               [12] 3421 	inc	r0
      000F74 E6               [12] 3422 	mov	a,@r0
      000F75 C0 E0            [24] 3423 	push	acc
      000F77 08               [12] 3424 	inc	r0
      000F78 E6               [12] 3425 	mov	a,@r0
      000F79 C0 E0            [24] 3426 	push	acc
      000F7B 08               [12] 3427 	inc	r0
      000F7C E6               [12] 3428 	mov	a,@r0
      000F7D C0 E0            [24] 3429 	push	acc
                           000EC8  3430 	C$fuzzy.h$1713$1_0$71 ==.
                                   3431 ;	../../fuzzy.h:1713: (c - b);
      000F7F E5 08            [12] 3432 	mov	a,_bp
      000F81 24 F6            [12] 3433 	add	a,#0xf6
      000F83 F8               [12] 3434 	mov	r0,a
      000F84 86 82            [24] 3435 	mov	dpl, @r0
      000F86 08               [12] 3436 	inc	r0
      000F87 86 83            [24] 3437 	mov	dph, @r0
      000F89 08               [12] 3438 	inc	r0
      000F8A 86 F0            [24] 3439 	mov	b, @r0
      000F8C 08               [12] 3440 	inc	r0
      000F8D E6               [12] 3441 	mov	a, @r0
      000F8E 12 34 87         [24] 3442 	lcall	___fssub
      000F91 C8               [12] 3443 	xch	a,r0
      000F92 E5 08            [12] 3444 	mov	a,_bp
      000F94 24 05            [12] 3445 	add	a,#0x05
      000F96 C8               [12] 3446 	xch	a,r0
      000F97 A6 82            [24] 3447 	mov	@r0, dpl
      000F99 08               [12] 3448 	inc	r0
      000F9A A6 83            [24] 3449 	mov	@r0, dph
      000F9C 08               [12] 3450 	inc	r0
      000F9D A6 F0            [24] 3451 	mov	@r0, b
      000F9F 08               [12] 3452 	inc	r0
      000FA0 F6               [12] 3453 	mov	@r0,a
      000FA1 E5 81            [12] 3454 	mov	a,sp
      000FA3 24 FC            [12] 3455 	add	a,#0xfc
      000FA5 F5 81            [12] 3456 	mov	sp,a
      000FA7 E5 08            [12] 3457 	mov	a,_bp
      000FA9 24 FA            [12] 3458 	add	a,#0xfa
      000FAB F8               [12] 3459 	mov	r0,a
      000FAC E6               [12] 3460 	mov	a,@r0
      000FAD C0 E0            [24] 3461 	push	acc
      000FAF 08               [12] 3462 	inc	r0
      000FB0 E6               [12] 3463 	mov	a,@r0
      000FB1 C0 E0            [24] 3464 	push	acc
      000FB3 08               [12] 3465 	inc	r0
      000FB4 E6               [12] 3466 	mov	a,@r0
      000FB5 C0 E0            [24] 3467 	push	acc
      000FB7 08               [12] 3468 	inc	r0
      000FB8 E6               [12] 3469 	mov	a,@r0
      000FB9 C0 E0            [24] 3470 	push	acc
      000FBB E5 08            [12] 3471 	mov	a,_bp
      000FBD 24 F6            [12] 3472 	add	a,#0xf6
      000FBF F8               [12] 3473 	mov	r0,a
      000FC0 86 82            [24] 3474 	mov	dpl, @r0
      000FC2 08               [12] 3475 	inc	r0
      000FC3 86 83            [24] 3476 	mov	dph, @r0
      000FC5 08               [12] 3477 	inc	r0
      000FC6 86 F0            [24] 3478 	mov	b, @r0
      000FC8 08               [12] 3479 	inc	r0
      000FC9 E6               [12] 3480 	mov	a, @r0
      000FCA 12 34 87         [24] 3481 	lcall	___fssub
      000FCD AA 82            [24] 3482 	mov	r2, dpl
      000FCF AB 83            [24] 3483 	mov	r3, dph
      000FD1 AE F0            [24] 3484 	mov	r6, b
      000FD3 FF               [12] 3485 	mov	r7, a
      000FD4 E5 81            [12] 3486 	mov	a,sp
      000FD6 24 FC            [12] 3487 	add	a,#0xfc
      000FD8 F5 81            [12] 3488 	mov	sp,a
      000FDA C0 02            [24] 3489 	push	ar2
      000FDC C0 03            [24] 3490 	push	ar3
      000FDE C0 06            [24] 3491 	push	ar6
      000FE0 C0 07            [24] 3492 	push	ar7
      000FE2 E5 08            [12] 3493 	mov	a,_bp
      000FE4 24 05            [12] 3494 	add	a,#0x05
      000FE6 F8               [12] 3495 	mov	r0,a
      000FE7 86 82            [24] 3496 	mov	dpl, @r0
      000FE9 08               [12] 3497 	inc	r0
      000FEA 86 83            [24] 3498 	mov	dph, @r0
      000FEC 08               [12] 3499 	inc	r0
      000FED 86 F0            [24] 3500 	mov	b, @r0
      000FEF 08               [12] 3501 	inc	r0
      000FF0 E6               [12] 3502 	mov	a, @r0
      000FF1 12 37 2B         [24] 3503 	lcall	___fsdiv
      000FF4 A8 08            [24] 3504 	mov	r0,_bp
      000FF6 08               [12] 3505 	inc	r0
      000FF7 A6 82            [24] 3506 	mov	@r0, dpl
      000FF9 08               [12] 3507 	inc	r0
      000FFA A6 83            [24] 3508 	mov	@r0, dph
      000FFC 08               [12] 3509 	inc	r0
      000FFD A6 F0            [24] 3510 	mov	@r0, b
      000FFF 08               [12] 3511 	inc	r0
      001000 F6               [12] 3512 	mov	@r0,a
      001001 E5 81            [12] 3513 	mov	a,sp
      001003 24 FC            [12] 3514 	add	a,#0xfc
      001005 F5 81            [12] 3515 	mov	sp,a
      001007                       3516 00109$:
                           000F50  3517 	C$fuzzy.h$1717$1_0$71 ==.
                                   3518 ;	../../fuzzy.h:1717: result,
      001007 E5 08            [12] 3519 	mov	a,_bp
      001009 24 F1            [12] 3520 	add	a,#0xf1
      00100B F8               [12] 3521 	mov	r0,a
      00100C E6               [12] 3522 	mov	a,@r0
      00100D C0 E0            [24] 3523 	push	acc
      00100F A8 08            [24] 3524 	mov	r0,_bp
      001011 08               [12] 3525 	inc	r0
      001012 86 82            [24] 3526 	mov	dpl, @r0
      001014 08               [12] 3527 	inc	r0
      001015 86 83            [24] 3528 	mov	dph, @r0
      001017 08               [12] 3529 	inc	r0
      001018 86 F0            [24] 3530 	mov	b, @r0
      00101A 08               [12] 3531 	inc	r0
      00101B E6               [12] 3532 	mov	a, @r0
      00101C 12 01 99         [24] 3533 	lcall	_fuzzy_apply_hedge
      00101F AC 82            [24] 3534 	mov	r4, dpl
      001021 AD 83            [24] 3535 	mov	r5, dph
      001023 AE F0            [24] 3536 	mov	r6, b
      001025 FF               [12] 3537 	mov	r7, a
      001026 15 81            [12] 3538 	dec	sp
      001028 8C 82            [24] 3539 	mov	dpl, r4
      00102A 8D 83            [24] 3540 	mov	dph, r5
      00102C 8E F0            [24] 3541 	mov	b, r6
      00102E EF               [12] 3542 	mov	a, r7
                           000F78  3543 	C$fuzzy.h$1720$1_0$71 ==.
                                   3544 ;	../../fuzzy.h:1720: }
      00102F 85 08 81         [24] 3545 	mov	sp,_bp
      001032 D0 08            [24] 3546 	pop	_bp
                           000F7D  3547 	C$fuzzy.h$1720$1_0$71 ==.
                           000F7D  3548 	XG$fuzzy_triangle$0$0 ==.
      001034 22               [24] 3549 	ret
                                   3550 ;------------------------------------------------------------
                                   3551 ;Allocation info for local variables in function 'fuzzy_trapezoid'
                                   3552 ;------------------------------------------------------------
                                   3553 ;b             Allocated to stack - _bp -6 +4 
                                   3554 ;c             Allocated to stack - _bp -10 +4 
                                   3555 ;d             Allocated to stack - _bp -14 +4 
                                   3556 ;value         Allocated to stack - _bp -18 +4 
                                   3557 ;hedge         Allocated to stack - _bp -19 +1 
                                   3558 ;a             Allocated to registers r7 r6 r5 r4 
                                   3559 ;result        Allocated to stack - _bp +1 +4 
                                   3560 ;sloc0         Allocated to stack - _bp +1 +4 
                                   3561 ;sloc1         Allocated to stack - _bp +5 +4 
                                   3562 ;------------------------------------------------------------
                           000F7E  3563 	G$fuzzy_trapezoid$0$0 ==.
                           000F7E  3564 	C$fuzzy.h$1722$1_0$77 ==.
                                   3565 ;	../../fuzzy.h:1722: float fuzzy_trapezoid(
                                   3566 ;	-----------------------------------------
                                   3567 ;	 function fuzzy_trapezoid
                                   3568 ;	-----------------------------------------
      001035                       3569 _fuzzy_trapezoid:
      001035 C0 08            [24] 3570 	push	_bp
      001037 85 81 08         [24] 3571 	mov	_bp,sp
      00103A AF 82            [24] 3572 	mov	r7,dpl
      00103C AE 83            [24] 3573 	mov	r6,dph
      00103E AD F0            [24] 3574 	mov	r5,b
      001040 FC               [12] 3575 	mov	r4,a
      001041 E5 81            [12] 3576 	mov	a,sp
      001043 24 08            [12] 3577 	add	a,#0x08
      001045 F5 81            [12] 3578 	mov	sp,a
                           000F90  3579 	C$fuzzy.h$1734$1_0$77 ==.
                                   3580 ;	../../fuzzy.h:1734: a >= b ||
      001047 C0 07            [24] 3581 	push	ar7
      001049 C0 06            [24] 3582 	push	ar6
      00104B C0 05            [24] 3583 	push	ar5
      00104D C0 04            [24] 3584 	push	ar4
      00104F E5 08            [12] 3585 	mov	a,_bp
      001051 24 FA            [12] 3586 	add	a,#0xfa
      001053 F8               [12] 3587 	mov	r0,a
      001054 E6               [12] 3588 	mov	a,@r0
      001055 C0 E0            [24] 3589 	push	acc
      001057 08               [12] 3590 	inc	r0
      001058 E6               [12] 3591 	mov	a,@r0
      001059 C0 E0            [24] 3592 	push	acc
      00105B 08               [12] 3593 	inc	r0
      00105C E6               [12] 3594 	mov	a,@r0
      00105D C0 E0            [24] 3595 	push	acc
      00105F 08               [12] 3596 	inc	r0
      001060 E6               [12] 3597 	mov	a,@r0
      001061 C0 E0            [24] 3598 	push	acc
      001063 8F 82            [24] 3599 	mov	dpl, r7
      001065 8E 83            [24] 3600 	mov	dph, r6
      001067 8D F0            [24] 3601 	mov	b, r5
      001069 EC               [12] 3602 	mov	a, r4
      00106A 12 35 C2         [24] 3603 	lcall	___fslt
      00106D E5 81            [12] 3604 	mov	a,sp
      00106F 24 FC            [12] 3605 	add	a,#0xfc
      001071 F5 81            [12] 3606 	mov	sp,a
      001073 D0 04            [24] 3607 	pop	ar4
      001075 D0 05            [24] 3608 	pop	ar5
      001077 D0 06            [24] 3609 	pop	ar6
      001079 D0 07            [24] 3610 	pop	ar7
      00107B E5 82            [12] 3611 	mov	a, dpl
      00107D 24 FF            [12] 3612 	add	a,#0xff
      00107F 92 00            [24] 3613 	mov	b0,c
      001081 40 03            [24] 3614 	jc	00159$
      001083 02 11 91         [24] 3615 	ljmp	00108$
      001086                       3616 00159$:
                           000FCF  3617 	C$fuzzy.h$1735$1_0$77 ==.
                                   3618 ;	../../fuzzy.h:1735: b > c ||
      001086 C0 07            [24] 3619 	push	ar7
      001088 C0 06            [24] 3620 	push	ar6
      00108A C0 05            [24] 3621 	push	ar5
      00108C C0 04            [24] 3622 	push	ar4
      00108E E5 08            [12] 3623 	mov	a,_bp
      001090 24 FA            [12] 3624 	add	a,#0xfa
      001092 F8               [12] 3625 	mov	r0,a
      001093 E6               [12] 3626 	mov	a,@r0
      001094 C0 E0            [24] 3627 	push	acc
      001096 08               [12] 3628 	inc	r0
      001097 E6               [12] 3629 	mov	a,@r0
      001098 C0 E0            [24] 3630 	push	acc
      00109A 08               [12] 3631 	inc	r0
      00109B E6               [12] 3632 	mov	a,@r0
      00109C C0 E0            [24] 3633 	push	acc
      00109E 08               [12] 3634 	inc	r0
      00109F E6               [12] 3635 	mov	a,@r0
      0010A0 C0 E0            [24] 3636 	push	acc
      0010A2 E5 08            [12] 3637 	mov	a,_bp
      0010A4 24 F6            [12] 3638 	add	a,#0xf6
      0010A6 F8               [12] 3639 	mov	r0,a
      0010A7 86 82            [24] 3640 	mov	dpl, @r0
      0010A9 08               [12] 3641 	inc	r0
      0010AA 86 83            [24] 3642 	mov	dph, @r0
      0010AC 08               [12] 3643 	inc	r0
      0010AD 86 F0            [24] 3644 	mov	b, @r0
      0010AF 08               [12] 3645 	inc	r0
      0010B0 E6               [12] 3646 	mov	a, @r0
      0010B1 12 35 C2         [24] 3647 	lcall	___fslt
      0010B4 AB 82            [24] 3648 	mov	r3, dpl
      0010B6 E5 81            [12] 3649 	mov	a,sp
      0010B8 24 FC            [12] 3650 	add	a,#0xfc
      0010BA F5 81            [12] 3651 	mov	sp,a
      0010BC D0 04            [24] 3652 	pop	ar4
      0010BE D0 05            [24] 3653 	pop	ar5
      0010C0 D0 06            [24] 3654 	pop	ar6
      0010C2 D0 07            [24] 3655 	pop	ar7
      0010C4 EB               [12] 3656 	mov	a,r3
      0010C5 60 03            [24] 3657 	jz	00160$
      0010C7 02 11 91         [24] 3658 	ljmp	00108$
      0010CA                       3659 00160$:
                           001013  3660 	C$fuzzy.h$1736$1_0$77 ==.
                                   3661 ;	../../fuzzy.h:1736: c >= d ||
      0010CA C0 07            [24] 3662 	push	ar7
      0010CC C0 06            [24] 3663 	push	ar6
      0010CE C0 05            [24] 3664 	push	ar5
      0010D0 C0 04            [24] 3665 	push	ar4
      0010D2 E5 08            [12] 3666 	mov	a,_bp
      0010D4 24 F2            [12] 3667 	add	a,#0xf2
      0010D6 F8               [12] 3668 	mov	r0,a
      0010D7 E6               [12] 3669 	mov	a,@r0
      0010D8 C0 E0            [24] 3670 	push	acc
      0010DA 08               [12] 3671 	inc	r0
      0010DB E6               [12] 3672 	mov	a,@r0
      0010DC C0 E0            [24] 3673 	push	acc
      0010DE 08               [12] 3674 	inc	r0
      0010DF E6               [12] 3675 	mov	a,@r0
      0010E0 C0 E0            [24] 3676 	push	acc
      0010E2 08               [12] 3677 	inc	r0
      0010E3 E6               [12] 3678 	mov	a,@r0
      0010E4 C0 E0            [24] 3679 	push	acc
      0010E6 E5 08            [12] 3680 	mov	a,_bp
      0010E8 24 F6            [12] 3681 	add	a,#0xf6
      0010EA F8               [12] 3682 	mov	r0,a
      0010EB 86 82            [24] 3683 	mov	dpl, @r0
      0010ED 08               [12] 3684 	inc	r0
      0010EE 86 83            [24] 3685 	mov	dph, @r0
      0010F0 08               [12] 3686 	inc	r0
      0010F1 86 F0            [24] 3687 	mov	b, @r0
      0010F3 08               [12] 3688 	inc	r0
      0010F4 E6               [12] 3689 	mov	a, @r0
      0010F5 12 35 C2         [24] 3690 	lcall	___fslt
      0010F8 E5 81            [12] 3691 	mov	a,sp
      0010FA 24 FC            [12] 3692 	add	a,#0xfc
      0010FC F5 81            [12] 3693 	mov	sp,a
      0010FE D0 04            [24] 3694 	pop	ar4
      001100 D0 05            [24] 3695 	pop	ar5
      001102 D0 06            [24] 3696 	pop	ar6
      001104 D0 07            [24] 3697 	pop	ar7
      001106 E5 82            [12] 3698 	mov	a, dpl
      001108 24 FF            [12] 3699 	add	a,#0xff
      00110A 92 00            [24] 3700 	mov	b0,c
      00110C 40 03            [24] 3701 	jc	00161$
      00110E 02 11 91         [24] 3702 	ljmp	00108$
      001111                       3703 00161$:
                           00105A  3704 	C$fuzzy.h$1737$1_0$77 ==.
                                   3705 ;	../../fuzzy.h:1737: value <= a ||
      001111 C0 07            [24] 3706 	push	ar7
      001113 C0 06            [24] 3707 	push	ar6
      001115 C0 05            [24] 3708 	push	ar5
      001117 C0 04            [24] 3709 	push	ar4
      001119 E5 08            [12] 3710 	mov	a,_bp
      00111B 24 EE            [12] 3711 	add	a,#0xee
      00111D F8               [12] 3712 	mov	r0,a
      00111E E6               [12] 3713 	mov	a,@r0
      00111F C0 E0            [24] 3714 	push	acc
      001121 08               [12] 3715 	inc	r0
      001122 E6               [12] 3716 	mov	a,@r0
      001123 C0 E0            [24] 3717 	push	acc
      001125 08               [12] 3718 	inc	r0
      001126 E6               [12] 3719 	mov	a,@r0
      001127 C0 E0            [24] 3720 	push	acc
      001129 08               [12] 3721 	inc	r0
      00112A E6               [12] 3722 	mov	a,@r0
      00112B C0 E0            [24] 3723 	push	acc
      00112D 8F 82            [24] 3724 	mov	dpl, r7
      00112F 8E 83            [24] 3725 	mov	dph, r6
      001131 8D F0            [24] 3726 	mov	b, r5
      001133 EC               [12] 3727 	mov	a, r4
      001134 12 35 C2         [24] 3728 	lcall	___fslt
      001137 E5 81            [12] 3729 	mov	a,sp
      001139 24 FC            [12] 3730 	add	a,#0xfc
      00113B F5 81            [12] 3731 	mov	sp,a
      00113D D0 04            [24] 3732 	pop	ar4
      00113F D0 05            [24] 3733 	pop	ar5
      001141 D0 06            [24] 3734 	pop	ar6
      001143 D0 07            [24] 3735 	pop	ar7
      001145 E5 82            [12] 3736 	mov	a, dpl
      001147 24 FF            [12] 3737 	add	a,#0xff
      001149 92 00            [24] 3738 	mov	b0,c
      00114B 50 44            [24] 3739 	jnc	00108$
                           001096  3740 	C$fuzzy.h$1739$1_0$77 ==.
                                   3741 ;	../../fuzzy.h:1739: ) {
      00114D C0 07            [24] 3742 	push	ar7
      00114F C0 06            [24] 3743 	push	ar6
      001151 C0 05            [24] 3744 	push	ar5
      001153 C0 04            [24] 3745 	push	ar4
      001155 E5 08            [12] 3746 	mov	a,_bp
      001157 24 F2            [12] 3747 	add	a,#0xf2
      001159 F8               [12] 3748 	mov	r0,a
      00115A E6               [12] 3749 	mov	a,@r0
      00115B C0 E0            [24] 3750 	push	acc
      00115D 08               [12] 3751 	inc	r0
      00115E E6               [12] 3752 	mov	a,@r0
      00115F C0 E0            [24] 3753 	push	acc
      001161 08               [12] 3754 	inc	r0
      001162 E6               [12] 3755 	mov	a,@r0
      001163 C0 E0            [24] 3756 	push	acc
      001165 08               [12] 3757 	inc	r0
      001166 E6               [12] 3758 	mov	a,@r0
      001167 C0 E0            [24] 3759 	push	acc
      001169 E5 08            [12] 3760 	mov	a,_bp
      00116B 24 EE            [12] 3761 	add	a,#0xee
      00116D F8               [12] 3762 	mov	r0,a
      00116E 86 82            [24] 3763 	mov	dpl, @r0
      001170 08               [12] 3764 	inc	r0
      001171 86 83            [24] 3765 	mov	dph, @r0
      001173 08               [12] 3766 	inc	r0
      001174 86 F0            [24] 3767 	mov	b, @r0
      001176 08               [12] 3768 	inc	r0
      001177 E6               [12] 3769 	mov	a, @r0
      001178 12 35 C2         [24] 3770 	lcall	___fslt
      00117B E5 81            [12] 3771 	mov	a,sp
      00117D 24 FC            [12] 3772 	add	a,#0xfc
      00117F F5 81            [12] 3773 	mov	sp,a
      001181 D0 04            [24] 3774 	pop	ar4
      001183 D0 05            [24] 3775 	pop	ar5
      001185 D0 06            [24] 3776 	pop	ar6
      001187 D0 07            [24] 3777 	pop	ar7
      001189 E5 82            [12] 3778 	mov	a, dpl
      00118B 24 FF            [12] 3779 	add	a,#0xff
      00118D 92 00            [24] 3780 	mov	b0,c
      00118F 40 0E            [24] 3781 	jc	00109$
      001191                       3782 00108$:
                           0010DA  3783 	C$fuzzy.h$1740$2_0$78 ==.
                                   3784 ;	../../fuzzy.h:1740: result = LEVEL_LO;
      001191 A8 08            [24] 3785 	mov	r0,_bp
      001193 08               [12] 3786 	inc	r0
      001194 E4               [12] 3787 	clr	a
      001195 F6               [12] 3788 	mov	@r0,a
      001196 08               [12] 3789 	inc	r0
      001197 F6               [12] 3790 	mov	@r0,a
      001198 08               [12] 3791 	inc	r0
      001199 F6               [12] 3792 	mov	@r0,a
      00119A 08               [12] 3793 	inc	r0
      00119B F6               [12] 3794 	mov	@r0,a
      00119C 02 13 9E         [24] 3795 	ljmp	00110$
      00119F                       3796 00109$:
                           0010E8  3797 	C$fuzzy.h$1743$1_0$77 ==.
                                   3798 ;	../../fuzzy.h:1743: value >= b &&
      00119F C0 07            [24] 3799 	push	ar7
      0011A1 C0 06            [24] 3800 	push	ar6
      0011A3 C0 05            [24] 3801 	push	ar5
      0011A5 C0 04            [24] 3802 	push	ar4
      0011A7 E5 08            [12] 3803 	mov	a,_bp
      0011A9 24 FA            [12] 3804 	add	a,#0xfa
      0011AB F8               [12] 3805 	mov	r0,a
      0011AC E6               [12] 3806 	mov	a,@r0
      0011AD C0 E0            [24] 3807 	push	acc
      0011AF 08               [12] 3808 	inc	r0
      0011B0 E6               [12] 3809 	mov	a,@r0
      0011B1 C0 E0            [24] 3810 	push	acc
      0011B3 08               [12] 3811 	inc	r0
      0011B4 E6               [12] 3812 	mov	a,@r0
      0011B5 C0 E0            [24] 3813 	push	acc
      0011B7 08               [12] 3814 	inc	r0
      0011B8 E6               [12] 3815 	mov	a,@r0
      0011B9 C0 E0            [24] 3816 	push	acc
      0011BB E5 08            [12] 3817 	mov	a,_bp
      0011BD 24 EE            [12] 3818 	add	a,#0xee
      0011BF F8               [12] 3819 	mov	r0,a
      0011C0 86 82            [24] 3820 	mov	dpl, @r0
      0011C2 08               [12] 3821 	inc	r0
      0011C3 86 83            [24] 3822 	mov	dph, @r0
      0011C5 08               [12] 3823 	inc	r0
      0011C6 86 F0            [24] 3824 	mov	b, @r0
      0011C8 08               [12] 3825 	inc	r0
      0011C9 E6               [12] 3826 	mov	a, @r0
      0011CA 12 35 C2         [24] 3827 	lcall	___fslt
      0011CD E5 81            [12] 3828 	mov	a,sp
      0011CF 24 FC            [12] 3829 	add	a,#0xfc
      0011D1 F5 81            [12] 3830 	mov	sp,a
      0011D3 D0 04            [24] 3831 	pop	ar4
      0011D5 D0 05            [24] 3832 	pop	ar5
      0011D7 D0 06            [24] 3833 	pop	ar6
      0011D9 D0 07            [24] 3834 	pop	ar7
      0011DB E5 82            [12] 3835 	mov	a, dpl
      0011DD 24 FF            [12] 3836 	add	a,#0xff
      0011DF 92 00            [24] 3837 	mov	b0,c
      0011E1 40 54            [24] 3838 	jc	00105$
                           00112C  3839 	C$fuzzy.h$1745$1_0$77 ==.
                                   3840 ;	../../fuzzy.h:1745: ) {
      0011E3 C0 07            [24] 3841 	push	ar7
      0011E5 C0 06            [24] 3842 	push	ar6
      0011E7 C0 05            [24] 3843 	push	ar5
      0011E9 C0 04            [24] 3844 	push	ar4
      0011EB E5 08            [12] 3845 	mov	a,_bp
      0011ED 24 EE            [12] 3846 	add	a,#0xee
      0011EF F8               [12] 3847 	mov	r0,a
      0011F0 E6               [12] 3848 	mov	a,@r0
      0011F1 C0 E0            [24] 3849 	push	acc
      0011F3 08               [12] 3850 	inc	r0
      0011F4 E6               [12] 3851 	mov	a,@r0
      0011F5 C0 E0            [24] 3852 	push	acc
      0011F7 08               [12] 3853 	inc	r0
      0011F8 E6               [12] 3854 	mov	a,@r0
      0011F9 C0 E0            [24] 3855 	push	acc
      0011FB 08               [12] 3856 	inc	r0
      0011FC E6               [12] 3857 	mov	a,@r0
      0011FD C0 E0            [24] 3858 	push	acc
      0011FF E5 08            [12] 3859 	mov	a,_bp
      001201 24 F6            [12] 3860 	add	a,#0xf6
      001203 F8               [12] 3861 	mov	r0,a
      001204 86 82            [24] 3862 	mov	dpl, @r0
      001206 08               [12] 3863 	inc	r0
      001207 86 83            [24] 3864 	mov	dph, @r0
      001209 08               [12] 3865 	inc	r0
      00120A 86 F0            [24] 3866 	mov	b, @r0
      00120C 08               [12] 3867 	inc	r0
      00120D E6               [12] 3868 	mov	a, @r0
      00120E 12 35 C2         [24] 3869 	lcall	___fslt
      001211 E5 81            [12] 3870 	mov	a,sp
      001213 24 FC            [12] 3871 	add	a,#0xfc
      001215 F5 81            [12] 3872 	mov	sp,a
      001217 D0 04            [24] 3873 	pop	ar4
      001219 D0 05            [24] 3874 	pop	ar5
      00121B D0 06            [24] 3875 	pop	ar6
      00121D D0 07            [24] 3876 	pop	ar7
      00121F E5 82            [12] 3877 	mov	a, dpl
      001221 24 FF            [12] 3878 	add	a,#0xff
      001223 92 00            [24] 3879 	mov	b0,c
      001225 40 10            [24] 3880 	jc	00105$
                           001170  3881 	C$fuzzy.h$1746$2_0$79 ==.
                                   3882 ;	../../fuzzy.h:1746: result = LEVEL_HI;
      001227 A8 08            [24] 3883 	mov	r0,_bp
      001229 08               [12] 3884 	inc	r0
      00122A E4               [12] 3885 	clr	a
      00122B F6               [12] 3886 	mov	@r0,a
      00122C 08               [12] 3887 	inc	r0
      00122D F6               [12] 3888 	mov	@r0,a
      00122E 08               [12] 3889 	inc	r0
      00122F 76 80            [12] 3890 	mov	@r0,#0x80
      001231 08               [12] 3891 	inc	r0
      001232 76 3F            [12] 3892 	mov	@r0,#0x3f
      001234 02 13 9E         [24] 3893 	ljmp	00110$
      001237                       3894 00105$:
                           001180  3895 	C$fuzzy.h$1748$1_0$77 ==.
                                   3896 ;	../../fuzzy.h:1748: else if (value < b) {
      001237 C0 07            [24] 3897 	push	ar7
      001239 C0 06            [24] 3898 	push	ar6
      00123B C0 05            [24] 3899 	push	ar5
      00123D C0 04            [24] 3900 	push	ar4
      00123F E5 08            [12] 3901 	mov	a,_bp
      001241 24 FA            [12] 3902 	add	a,#0xfa
      001243 F8               [12] 3903 	mov	r0,a
      001244 E6               [12] 3904 	mov	a,@r0
      001245 C0 E0            [24] 3905 	push	acc
      001247 08               [12] 3906 	inc	r0
      001248 E6               [12] 3907 	mov	a,@r0
      001249 C0 E0            [24] 3908 	push	acc
      00124B 08               [12] 3909 	inc	r0
      00124C E6               [12] 3910 	mov	a,@r0
      00124D C0 E0            [24] 3911 	push	acc
      00124F 08               [12] 3912 	inc	r0
      001250 E6               [12] 3913 	mov	a,@r0
      001251 C0 E0            [24] 3914 	push	acc
      001253 E5 08            [12] 3915 	mov	a,_bp
      001255 24 EE            [12] 3916 	add	a,#0xee
      001257 F8               [12] 3917 	mov	r0,a
      001258 86 82            [24] 3918 	mov	dpl, @r0
      00125A 08               [12] 3919 	inc	r0
      00125B 86 83            [24] 3920 	mov	dph, @r0
      00125D 08               [12] 3921 	inc	r0
      00125E 86 F0            [24] 3922 	mov	b, @r0
      001260 08               [12] 3923 	inc	r0
      001261 E6               [12] 3924 	mov	a, @r0
      001262 12 35 C2         [24] 3925 	lcall	___fslt
      001265 AB 82            [24] 3926 	mov	r3, dpl
      001267 E5 81            [12] 3927 	mov	a,sp
      001269 24 FC            [12] 3928 	add	a,#0xfc
      00126B F5 81            [12] 3929 	mov	sp,a
      00126D D0 04            [24] 3930 	pop	ar4
      00126F D0 05            [24] 3931 	pop	ar5
      001271 D0 06            [24] 3932 	pop	ar6
      001273 D0 07            [24] 3933 	pop	ar7
      001275 EB               [12] 3934 	mov	a,r3
      001276 70 03            [24] 3935 	jnz	00166$
      001278 02 13 02         [24] 3936 	ljmp	00102$
      00127B                       3937 00166$:
                           0011C4  3938 	C$fuzzy.h$1750$1_0$77 ==.
                                   3939 ;	../../fuzzy.h:1750: (value - a) /
      00127B C0 07            [24] 3940 	push	ar7
      00127D C0 06            [24] 3941 	push	ar6
      00127F C0 05            [24] 3942 	push	ar5
      001281 C0 04            [24] 3943 	push	ar4
      001283 C0 07            [24] 3944 	push	ar7
      001285 C0 06            [24] 3945 	push	ar6
      001287 C0 05            [24] 3946 	push	ar5
      001289 C0 04            [24] 3947 	push	ar4
                           0011D4  3948 	C$fuzzy.h$1751$1_0$77 ==.
                                   3949 ;	../../fuzzy.h:1751: (b - a);
      00128B E5 08            [12] 3950 	mov	a,_bp
      00128D 24 EE            [12] 3951 	add	a,#0xee
      00128F F8               [12] 3952 	mov	r0,a
      001290 86 82            [24] 3953 	mov	dpl, @r0
      001292 08               [12] 3954 	inc	r0
      001293 86 83            [24] 3955 	mov	dph, @r0
      001295 08               [12] 3956 	inc	r0
      001296 86 F0            [24] 3957 	mov	b, @r0
      001298 08               [12] 3958 	inc	r0
      001299 E6               [12] 3959 	mov	a, @r0
      00129A 12 34 87         [24] 3960 	lcall	___fssub
      00129D C8               [12] 3961 	xch	a,r0
      00129E E5 08            [12] 3962 	mov	a,_bp
      0012A0 24 05            [12] 3963 	add	a,#0x05
      0012A2 C8               [12] 3964 	xch	a,r0
      0012A3 A6 82            [24] 3965 	mov	@r0, dpl
      0012A5 08               [12] 3966 	inc	r0
      0012A6 A6 83            [24] 3967 	mov	@r0, dph
      0012A8 08               [12] 3968 	inc	r0
      0012A9 A6 F0            [24] 3969 	mov	@r0, b
      0012AB 08               [12] 3970 	inc	r0
      0012AC F6               [12] 3971 	mov	@r0,a
      0012AD E5 81            [12] 3972 	mov	a,sp
      0012AF 24 FC            [12] 3973 	add	a,#0xfc
      0012B1 F5 81            [12] 3974 	mov	sp,a
      0012B3 E5 08            [12] 3975 	mov	a,_bp
      0012B5 24 FA            [12] 3976 	add	a,#0xfa
      0012B7 F8               [12] 3977 	mov	r0,a
      0012B8 86 82            [24] 3978 	mov	dpl, @r0
      0012BA 08               [12] 3979 	inc	r0
      0012BB 86 83            [24] 3980 	mov	dph, @r0
      0012BD 08               [12] 3981 	inc	r0
      0012BE 86 F0            [24] 3982 	mov	b, @r0
      0012C0 08               [12] 3983 	inc	r0
      0012C1 E6               [12] 3984 	mov	a, @r0
      0012C2 12 34 87         [24] 3985 	lcall	___fssub
      0012C5 AC 82            [24] 3986 	mov	r4, dpl
      0012C7 AD 83            [24] 3987 	mov	r5, dph
      0012C9 AE F0            [24] 3988 	mov	r6, b
      0012CB FF               [12] 3989 	mov	r7, a
      0012CC E5 81            [12] 3990 	mov	a,sp
      0012CE 24 FC            [12] 3991 	add	a,#0xfc
      0012D0 F5 81            [12] 3992 	mov	sp,a
      0012D2 C0 04            [24] 3993 	push	ar4
      0012D4 C0 05            [24] 3994 	push	ar5
      0012D6 C0 06            [24] 3995 	push	ar6
      0012D8 C0 07            [24] 3996 	push	ar7
      0012DA E5 08            [12] 3997 	mov	a,_bp
      0012DC 24 05            [12] 3998 	add	a,#0x05
      0012DE F8               [12] 3999 	mov	r0,a
      0012DF 86 82            [24] 4000 	mov	dpl, @r0
      0012E1 08               [12] 4001 	inc	r0
      0012E2 86 83            [24] 4002 	mov	dph, @r0
      0012E4 08               [12] 4003 	inc	r0
      0012E5 86 F0            [24] 4004 	mov	b, @r0
      0012E7 08               [12] 4005 	inc	r0
      0012E8 E6               [12] 4006 	mov	a, @r0
      0012E9 12 37 2B         [24] 4007 	lcall	___fsdiv
      0012EC A8 08            [24] 4008 	mov	r0,_bp
      0012EE 08               [12] 4009 	inc	r0
      0012EF A6 82            [24] 4010 	mov	@r0, dpl
      0012F1 08               [12] 4011 	inc	r0
      0012F2 A6 83            [24] 4012 	mov	@r0, dph
      0012F4 08               [12] 4013 	inc	r0
      0012F5 A6 F0            [24] 4014 	mov	@r0, b
      0012F7 08               [12] 4015 	inc	r0
      0012F8 F6               [12] 4016 	mov	@r0,a
      0012F9 E5 81            [12] 4017 	mov	a,sp
      0012FB 24 FC            [12] 4018 	add	a,#0xfc
      0012FD F5 81            [12] 4019 	mov	sp,a
      0012FF 02 13 9E         [24] 4020 	ljmp	00110$
      001302                       4021 00102$:
                           00124B  4022 	C$fuzzy.h$1755$1_0$77 ==.
                                   4023 ;	../../fuzzy.h:1755: (d - value) /
      001302 E5 08            [12] 4024 	mov	a,_bp
      001304 24 EE            [12] 4025 	add	a,#0xee
      001306 F8               [12] 4026 	mov	r0,a
      001307 E6               [12] 4027 	mov	a,@r0
      001308 C0 E0            [24] 4028 	push	acc
      00130A 08               [12] 4029 	inc	r0
      00130B E6               [12] 4030 	mov	a,@r0
      00130C C0 E0            [24] 4031 	push	acc
      00130E 08               [12] 4032 	inc	r0
      00130F E6               [12] 4033 	mov	a,@r0
      001310 C0 E0            [24] 4034 	push	acc
      001312 08               [12] 4035 	inc	r0
      001313 E6               [12] 4036 	mov	a,@r0
      001314 C0 E0            [24] 4037 	push	acc
                           00125F  4038 	C$fuzzy.h$1756$1_0$77 ==.
                                   4039 ;	../../fuzzy.h:1756: (d - c);
      001316 E5 08            [12] 4040 	mov	a,_bp
      001318 24 F2            [12] 4041 	add	a,#0xf2
      00131A F8               [12] 4042 	mov	r0,a
      00131B 86 82            [24] 4043 	mov	dpl, @r0
      00131D 08               [12] 4044 	inc	r0
      00131E 86 83            [24] 4045 	mov	dph, @r0
      001320 08               [12] 4046 	inc	r0
      001321 86 F0            [24] 4047 	mov	b, @r0
      001323 08               [12] 4048 	inc	r0
      001324 E6               [12] 4049 	mov	a, @r0
      001325 12 34 87         [24] 4050 	lcall	___fssub
      001328 C8               [12] 4051 	xch	a,r0
      001329 E5 08            [12] 4052 	mov	a,_bp
      00132B 24 05            [12] 4053 	add	a,#0x05
      00132D C8               [12] 4054 	xch	a,r0
      00132E A6 82            [24] 4055 	mov	@r0, dpl
      001330 08               [12] 4056 	inc	r0
      001331 A6 83            [24] 4057 	mov	@r0, dph
      001333 08               [12] 4058 	inc	r0
      001334 A6 F0            [24] 4059 	mov	@r0, b
      001336 08               [12] 4060 	inc	r0
      001337 F6               [12] 4061 	mov	@r0,a
      001338 E5 81            [12] 4062 	mov	a,sp
      00133A 24 FC            [12] 4063 	add	a,#0xfc
      00133C F5 81            [12] 4064 	mov	sp,a
      00133E E5 08            [12] 4065 	mov	a,_bp
      001340 24 F6            [12] 4066 	add	a,#0xf6
      001342 F8               [12] 4067 	mov	r0,a
      001343 E6               [12] 4068 	mov	a,@r0
      001344 C0 E0            [24] 4069 	push	acc
      001346 08               [12] 4070 	inc	r0
      001347 E6               [12] 4071 	mov	a,@r0
      001348 C0 E0            [24] 4072 	push	acc
      00134A 08               [12] 4073 	inc	r0
      00134B E6               [12] 4074 	mov	a,@r0
      00134C C0 E0            [24] 4075 	push	acc
      00134E 08               [12] 4076 	inc	r0
      00134F E6               [12] 4077 	mov	a,@r0
      001350 C0 E0            [24] 4078 	push	acc
      001352 E5 08            [12] 4079 	mov	a,_bp
      001354 24 F2            [12] 4080 	add	a,#0xf2
      001356 F8               [12] 4081 	mov	r0,a
      001357 86 82            [24] 4082 	mov	dpl, @r0
      001359 08               [12] 4083 	inc	r0
      00135A 86 83            [24] 4084 	mov	dph, @r0
      00135C 08               [12] 4085 	inc	r0
      00135D 86 F0            [24] 4086 	mov	b, @r0
      00135F 08               [12] 4087 	inc	r0
      001360 E6               [12] 4088 	mov	a, @r0
      001361 12 34 87         [24] 4089 	lcall	___fssub
      001364 AA 82            [24] 4090 	mov	r2, dpl
      001366 AB 83            [24] 4091 	mov	r3, dph
      001368 AE F0            [24] 4092 	mov	r6, b
      00136A FF               [12] 4093 	mov	r7, a
      00136B E5 81            [12] 4094 	mov	a,sp
      00136D 24 FC            [12] 4095 	add	a,#0xfc
      00136F F5 81            [12] 4096 	mov	sp,a
      001371 C0 02            [24] 4097 	push	ar2
      001373 C0 03            [24] 4098 	push	ar3
      001375 C0 06            [24] 4099 	push	ar6
      001377 C0 07            [24] 4100 	push	ar7
      001379 E5 08            [12] 4101 	mov	a,_bp
      00137B 24 05            [12] 4102 	add	a,#0x05
      00137D F8               [12] 4103 	mov	r0,a
      00137E 86 82            [24] 4104 	mov	dpl, @r0
      001380 08               [12] 4105 	inc	r0
      001381 86 83            [24] 4106 	mov	dph, @r0
      001383 08               [12] 4107 	inc	r0
      001384 86 F0            [24] 4108 	mov	b, @r0
      001386 08               [12] 4109 	inc	r0
      001387 E6               [12] 4110 	mov	a, @r0
      001388 12 37 2B         [24] 4111 	lcall	___fsdiv
      00138B A8 08            [24] 4112 	mov	r0,_bp
      00138D 08               [12] 4113 	inc	r0
      00138E A6 82            [24] 4114 	mov	@r0, dpl
      001390 08               [12] 4115 	inc	r0
      001391 A6 83            [24] 4116 	mov	@r0, dph
      001393 08               [12] 4117 	inc	r0
      001394 A6 F0            [24] 4118 	mov	@r0, b
      001396 08               [12] 4119 	inc	r0
      001397 F6               [12] 4120 	mov	@r0,a
      001398 E5 81            [12] 4121 	mov	a,sp
      00139A 24 FC            [12] 4122 	add	a,#0xfc
      00139C F5 81            [12] 4123 	mov	sp,a
      00139E                       4124 00110$:
                           0012E7  4125 	C$fuzzy.h$1760$1_0$77 ==.
                                   4126 ;	../../fuzzy.h:1760: result,
      00139E E5 08            [12] 4127 	mov	a,_bp
      0013A0 24 ED            [12] 4128 	add	a,#0xed
      0013A2 F8               [12] 4129 	mov	r0,a
      0013A3 E6               [12] 4130 	mov	a,@r0
      0013A4 C0 E0            [24] 4131 	push	acc
      0013A6 A8 08            [24] 4132 	mov	r0,_bp
      0013A8 08               [12] 4133 	inc	r0
      0013A9 86 82            [24] 4134 	mov	dpl, @r0
      0013AB 08               [12] 4135 	inc	r0
      0013AC 86 83            [24] 4136 	mov	dph, @r0
      0013AE 08               [12] 4137 	inc	r0
      0013AF 86 F0            [24] 4138 	mov	b, @r0
      0013B1 08               [12] 4139 	inc	r0
      0013B2 E6               [12] 4140 	mov	a, @r0
      0013B3 12 01 99         [24] 4141 	lcall	_fuzzy_apply_hedge
      0013B6 AC 82            [24] 4142 	mov	r4, dpl
      0013B8 AD 83            [24] 4143 	mov	r5, dph
      0013BA AE F0            [24] 4144 	mov	r6, b
      0013BC FF               [12] 4145 	mov	r7, a
      0013BD 15 81            [12] 4146 	dec	sp
      0013BF 8C 82            [24] 4147 	mov	dpl, r4
      0013C1 8D 83            [24] 4148 	mov	dph, r5
      0013C3 8E F0            [24] 4149 	mov	b, r6
      0013C5 EF               [12] 4150 	mov	a, r7
                           00130F  4151 	C$fuzzy.h$1763$1_0$77 ==.
                                   4152 ;	../../fuzzy.h:1763: }
      0013C6 85 08 81         [24] 4153 	mov	sp,_bp
      0013C9 D0 08            [24] 4154 	pop	_bp
                           001314  4155 	C$fuzzy.h$1763$1_0$77 ==.
                           001314  4156 	XG$fuzzy_trapezoid$0$0 ==.
      0013CB 22               [24] 4157 	ret
                                   4158 ;------------------------------------------------------------
                                   4159 ;Allocation info for local variables in function 'fuzzy_function_array'
                                   4160 ;------------------------------------------------------------
                                   4161 ;value         Allocated to stack - _bp -6 +4 
                                   4162 ;hedge         Allocated to stack - _bp -7 +1 
                                   4163 ;parameter_count Allocated to stack - _bp -9 +2 
                                   4164 ;parameters    Allocated to stack - _bp -12 +3 
                                   4165 ;shape         Allocated to registers r7 
                                   4166 ;sloc0         Allocated to stack - _bp +2 +1 
                                   4167 ;sloc1         Allocated to stack - _bp +1 +4 
                                   4168 ;sloc2         Allocated to stack - _bp +5 +4 
                                   4169 ;sloc3         Allocated to stack - _bp +9 +4 
                                   4170 ;------------------------------------------------------------
                           001315  4171 	G$fuzzy_function_array$0$0 ==.
                           001315  4172 	C$fuzzy.h$2220$1_0$83 ==.
                                   4173 ;	../../fuzzy.h:2220: float fuzzy_function_array(
                                   4174 ;	-----------------------------------------
                                   4175 ;	 function fuzzy_function_array
                                   4176 ;	-----------------------------------------
      0013CC                       4177 _fuzzy_function_array:
      0013CC C0 08            [24] 4178 	push	_bp
      0013CE E5 81            [12] 4179 	mov	a,sp
      0013D0 F5 08            [12] 4180 	mov	_bp,a
      0013D2 24 0C            [12] 4181 	add	a,#0x0c
      0013D4 F5 81            [12] 4182 	mov	sp,a
      0013D6 AF 82            [24] 4183 	mov	r7, dpl
                           001321  4184 	C$fuzzy.h$2228$1_0$83 ==.
                                   4185 ;	../../fuzzy.h:2228: if (parameters == NULL) {
      0013D8 E5 08            [12] 4186 	mov	a,_bp
      0013DA 24 F4            [12] 4187 	add	a,#0xf4
      0013DC F8               [12] 4188 	mov	r0,a
      0013DD E6               [12] 4189 	mov	a,@r0
      0013DE 08               [12] 4190 	inc	r0
      0013DF 46               [12] 4191 	orl	a,@r0
      0013E0 70 09            [24] 4192 	jnz	00102$
                           00132B  4193 	C$fuzzy.h$2229$2_0$84 ==.
                                   4194 ;	../../fuzzy.h:2229: return LEVEL_LO;
      0013E2 90 00 00         [24] 4195 	mov	dptr,#0x0000
      0013E5 E4               [12] 4196 	clr	a
      0013E6 F5 F0            [12] 4197 	mov	b,a
      0013E8 02 17 67         [24] 4198 	ljmp	00123$
      0013EB                       4199 00102$:
                           001334  4200 	C$fuzzy.h$2232$1_0$83 ==.
                                   4201 ;	../../fuzzy.h:2232: switch (shape) {
      0013EB EF               [12] 4202 	mov	a,r7
      0013EC 24 F4            [12] 4203 	add	a,#0xff - 0x0b
      0013EE 50 03            [24] 4204 	jnc	00156$
      0013F0 02 17 61         [24] 4205 	ljmp	00121$
      0013F3                       4206 00156$:
      0013F3 EF               [12] 4207 	mov	a,r7
      0013F4 24 0A            [12] 4208 	add	a,#(00157$-3-.)
      0013F6 83               [24] 4209 	movc	a,@a+pc
      0013F7 F5 82            [12] 4210 	mov	dpl,a
      0013F9 EF               [12] 4211 	mov	a,r7
      0013FA 24 10            [12] 4212 	add	a,#(00158$-3-.)
      0013FC 83               [24] 4213 	movc	a,@a+pc
      0013FD F5 83            [12] 4214 	mov	dph,a
      0013FF E4               [12] 4215 	clr	a
      001400 73               [24] 4216 	jmp	@a+dptr
      001401                       4217 00157$:
      001401 19                    4218 	.db	00103$
      001402 15                    4219 	.db	00106$
      001403 15                    4220 	.db	00109$
      001404 59                    4221 	.db	00120$
      001405 59                    4222 	.db	00120$
      001406 59                    4223 	.db	00120$
      001407 59                    4224 	.db	00120$
      001408 59                    4225 	.db	00120$
      001409 59                    4226 	.db	00120$
      00140A 59                    4227 	.db	00120$
      00140B 59                    4228 	.db	00120$
      00140C 59                    4229 	.db	00120$
      00140D                       4230 00158$:
      00140D 14                    4231 	.db	00103$>>8
      00140E 15                    4232 	.db	00106$>>8
      00140F 16                    4233 	.db	00109$>>8
      001410 17                    4234 	.db	00120$>>8
      001411 17                    4235 	.db	00120$>>8
      001412 17                    4236 	.db	00120$>>8
      001413 17                    4237 	.db	00120$>>8
      001414 17                    4238 	.db	00120$>>8
      001415 17                    4239 	.db	00120$>>8
      001416 17                    4240 	.db	00120$>>8
      001417 17                    4241 	.db	00120$>>8
      001418 17                    4242 	.db	00120$>>8
                           001362  4243 	C$fuzzy.h$2233$2_0$85 ==.
                                   4244 ;	../../fuzzy.h:2233: case FUZZY_SHAPE_RAMP:
      001419                       4245 00103$:
                           001362  4246 	C$fuzzy.h$2234$2_0$85 ==.
                                   4247 ;	../../fuzzy.h:2234: if (parameter_count != 3u) {
      001419 E5 08            [12] 4248 	mov	a,_bp
      00141B 24 F7            [12] 4249 	add	a,#0xf7
      00141D F8               [12] 4250 	mov	r0,a
      00141E B6 03 06         [24] 4251 	cjne	@r0,#0x03,00159$
      001421 08               [12] 4252 	inc	r0
      001422 B6 00 02         [24] 4253 	cjne	@r0,#0x00,00159$
      001425 80 09            [24] 4254 	sjmp	00105$
      001427                       4255 00159$:
                           001370  4256 	C$fuzzy.h$2235$3_0$86 ==.
                                   4257 ;	../../fuzzy.h:2235: return LEVEL_LO;
      001427 90 00 00         [24] 4258 	mov	dptr,#0x0000
      00142A E4               [12] 4259 	clr	a
      00142B F5 F0            [12] 4260 	mov	b,a
      00142D 02 17 67         [24] 4261 	ljmp	00123$
      001430                       4262 00105$:
                           001379  4263 	C$fuzzy.h$2242$2_0$85 ==.
                                   4264 ;	../../fuzzy.h:2242: parameters[2] != 0.0f,
      001430 E5 08            [12] 4265 	mov	a,_bp
      001432 24 F4            [12] 4266 	add	a,#0xf4
      001434 F8               [12] 4267 	mov	r0,a
      001435 74 08            [12] 4268 	mov	a,#0x08
      001437 26               [12] 4269 	add	a, @r0
      001438 FD               [12] 4270 	mov	r5,a
      001439 E4               [12] 4271 	clr	a
      00143A 08               [12] 4272 	inc	r0
      00143B 36               [12] 4273 	addc	a, @r0
      00143C FE               [12] 4274 	mov	r6,a
      00143D 08               [12] 4275 	inc	r0
      00143E 86 07            [24] 4276 	mov	ar7,@r0
      001440 8D 82            [24] 4277 	mov	dpl,r5
      001442 8E 83            [24] 4278 	mov	dph,r6
      001444 8F F0            [24] 4279 	mov	b,r7
      001446 12 37 EE         [24] 4280 	lcall	__gptrget
      001449 FD               [12] 4281 	mov	r5,a
      00144A A3               [24] 4282 	inc	dptr
      00144B 12 37 EE         [24] 4283 	lcall	__gptrget
      00144E FE               [12] 4284 	mov	r6,a
      00144F A3               [24] 4285 	inc	dptr
      001450 12 37 EE         [24] 4286 	lcall	__gptrget
      001453 FF               [12] 4287 	mov	r7,a
      001454 A3               [24] 4288 	inc	dptr
      001455 12 37 EE         [24] 4289 	lcall	__gptrget
      001458 FC               [12] 4290 	mov	r4,a
      001459 8D F0            [24] 4291 	mov	b,r5
      00145B EE               [12] 4292 	mov	a,r6
      00145C 42 F0            [12] 4293 	orl	b,a
      00145E EF               [12] 4294 	mov	a,r7
      00145F 42 F0            [12] 4295 	orl	b,a
      001461 EC               [12] 4296 	mov	a,r4
      001462 54 7F            [12] 4297 	anl	a,#0x7F
      001464 45 F0            [12] 4298 	orl	a,b
      001466 B4 01 00         [24] 4299 	cjne	a,#0x01,00160$
      001469                       4300 00160$:
      001469 B3               [12] 4301 	cpl	c
      00146A 92 00            [24] 4302 	mov	b0,c
      00146C E4               [12] 4303 	clr	a
      00146D 33               [12] 4304 	rlc	a
      00146E FB               [12] 4305 	mov	r3,a
                           0013B8  4306 	C$fuzzy.h$2240$2_0$85 ==.
                                   4307 ;	../../fuzzy.h:2240: parameters[1],
      00146F E5 08            [12] 4308 	mov	a,_bp
      001471 24 F4            [12] 4309 	add	a,#0xf4
      001473 F8               [12] 4310 	mov	r0,a
      001474 74 04            [12] 4311 	mov	a,#0x04
      001476 26               [12] 4312 	add	a, @r0
      001477 FC               [12] 4313 	mov	r4,a
      001478 E4               [12] 4314 	clr	a
      001479 08               [12] 4315 	inc	r0
      00147A 36               [12] 4316 	addc	a, @r0
      00147B FD               [12] 4317 	mov	r5,a
      00147C 08               [12] 4318 	inc	r0
      00147D 86 06            [24] 4319 	mov	ar6,@r0
      00147F 8C 82            [24] 4320 	mov	dpl,r4
      001481 8D 83            [24] 4321 	mov	dph,r5
      001483 8E F0            [24] 4322 	mov	b,r6
      001485 A8 08            [24] 4323 	mov	r0,_bp
      001487 08               [12] 4324 	inc	r0
      001488 12 37 EE         [24] 4325 	lcall	__gptrget
      00148B F6               [12] 4326 	mov	@r0,a
      00148C A3               [24] 4327 	inc	dptr
      00148D 12 37 EE         [24] 4328 	lcall	__gptrget
      001490 08               [12] 4329 	inc	r0
      001491 F6               [12] 4330 	mov	@r0,a
      001492 A3               [24] 4331 	inc	dptr
      001493 12 37 EE         [24] 4332 	lcall	__gptrget
      001496 08               [12] 4333 	inc	r0
      001497 F6               [12] 4334 	mov	@r0,a
      001498 A3               [24] 4335 	inc	dptr
      001499 12 37 EE         [24] 4336 	lcall	__gptrget
      00149C 08               [12] 4337 	inc	r0
      00149D F6               [12] 4338 	mov	@r0,a
                           0013E7  4339 	C$fuzzy.h$2239$2_0$85 ==.
                                   4340 ;	../../fuzzy.h:2239: parameters[0],
      00149E E5 08            [12] 4341 	mov	a,_bp
      0014A0 24 F4            [12] 4342 	add	a,#0xf4
      0014A2 F8               [12] 4343 	mov	r0,a
      0014A3 86 02            [24] 4344 	mov	ar2,@r0
      0014A5 08               [12] 4345 	inc	r0
      0014A6 86 06            [24] 4346 	mov	ar6,@r0
      0014A8 08               [12] 4347 	inc	r0
      0014A9 86 07            [24] 4348 	mov	ar7,@r0
      0014AB 8A 82            [24] 4349 	mov	dpl,r2
      0014AD 8E 83            [24] 4350 	mov	dph,r6
      0014AF 8F F0            [24] 4351 	mov	b,r7
      0014B1 12 37 EE         [24] 4352 	lcall	__gptrget
      0014B4 FA               [12] 4353 	mov	r2,a
      0014B5 A3               [24] 4354 	inc	dptr
      0014B6 12 37 EE         [24] 4355 	lcall	__gptrget
      0014B9 FE               [12] 4356 	mov	r6,a
      0014BA A3               [24] 4357 	inc	dptr
      0014BB 12 37 EE         [24] 4358 	lcall	__gptrget
      0014BE FF               [12] 4359 	mov	r7,a
      0014BF A3               [24] 4360 	inc	dptr
      0014C0 12 37 EE         [24] 4361 	lcall	__gptrget
      0014C3 FD               [12] 4362 	mov	r5,a
      0014C4 E5 08            [12] 4363 	mov	a,_bp
      0014C6 24 F9            [12] 4364 	add	a,#0xf9
      0014C8 F8               [12] 4365 	mov	r0,a
      0014C9 E6               [12] 4366 	mov	a,@r0
      0014CA C0 E0            [24] 4367 	push	acc
      0014CC C0 03            [24] 4368 	push	ar3
      0014CE E5 08            [12] 4369 	mov	a,_bp
      0014D0 24 FA            [12] 4370 	add	a,#0xfa
      0014D2 F8               [12] 4371 	mov	r0,a
      0014D3 E6               [12] 4372 	mov	a,@r0
      0014D4 C0 E0            [24] 4373 	push	acc
      0014D6 08               [12] 4374 	inc	r0
      0014D7 E6               [12] 4375 	mov	a,@r0
      0014D8 C0 E0            [24] 4376 	push	acc
      0014DA 08               [12] 4377 	inc	r0
      0014DB E6               [12] 4378 	mov	a,@r0
      0014DC C0 E0            [24] 4379 	push	acc
      0014DE 08               [12] 4380 	inc	r0
      0014DF E6               [12] 4381 	mov	a,@r0
      0014E0 C0 E0            [24] 4382 	push	acc
      0014E2 A8 08            [24] 4383 	mov	r0,_bp
      0014E4 08               [12] 4384 	inc	r0
      0014E5 E6               [12] 4385 	mov	a,@r0
      0014E6 C0 E0            [24] 4386 	push	acc
      0014E8 08               [12] 4387 	inc	r0
      0014E9 E6               [12] 4388 	mov	a,@r0
      0014EA C0 E0            [24] 4389 	push	acc
      0014EC 08               [12] 4390 	inc	r0
      0014ED E6               [12] 4391 	mov	a,@r0
      0014EE C0 E0            [24] 4392 	push	acc
      0014F0 08               [12] 4393 	inc	r0
      0014F1 E6               [12] 4394 	mov	a,@r0
      0014F2 C0 E0            [24] 4395 	push	acc
      0014F4 8A 82            [24] 4396 	mov	dpl, r2
      0014F6 8E 83            [24] 4397 	mov	dph, r6
      0014F8 8F F0            [24] 4398 	mov	b, r7
      0014FA ED               [12] 4399 	mov	a, r5
      0014FB 12 0A EC         [24] 4400 	lcall	_fuzzy_ramp
      0014FE AC 82            [24] 4401 	mov	r4, dpl
      001500 AD 83            [24] 4402 	mov	r5, dph
      001502 AE F0            [24] 4403 	mov	r6, b
      001504 FF               [12] 4404 	mov	r7, a
      001505 E5 81            [12] 4405 	mov	a,sp
      001507 24 F6            [12] 4406 	add	a,#0xf6
      001509 F5 81            [12] 4407 	mov	sp,a
      00150B 8C 82            [24] 4408 	mov	dpl, r4
      00150D 8D 83            [24] 4409 	mov	dph, r5
      00150F 8E F0            [24] 4410 	mov	b, r6
      001511 EF               [12] 4411 	mov	a, r7
      001512 02 17 67         [24] 4412 	ljmp	00123$
                           00145E  4413 	C$fuzzy.h$2246$2_0$85 ==.
                                   4414 ;	../../fuzzy.h:2246: case FUZZY_SHAPE_TRIANGLE:
      001515                       4415 00106$:
                           00145E  4416 	C$fuzzy.h$2247$2_0$85 ==.
                                   4417 ;	../../fuzzy.h:2247: if (parameter_count != 3u) {
      001515 E5 08            [12] 4418 	mov	a,_bp
      001517 24 F7            [12] 4419 	add	a,#0xf7
      001519 F8               [12] 4420 	mov	r0,a
      00151A B6 03 06         [24] 4421 	cjne	@r0,#0x03,00161$
      00151D 08               [12] 4422 	inc	r0
      00151E B6 00 02         [24] 4423 	cjne	@r0,#0x00,00161$
      001521 80 09            [24] 4424 	sjmp	00108$
      001523                       4425 00161$:
                           00146C  4426 	C$fuzzy.h$2248$3_0$87 ==.
                                   4427 ;	../../fuzzy.h:2248: return LEVEL_LO;
      001523 90 00 00         [24] 4428 	mov	dptr,#0x0000
      001526 E4               [12] 4429 	clr	a
      001527 F5 F0            [12] 4430 	mov	b,a
      001529 02 17 67         [24] 4431 	ljmp	00123$
      00152C                       4432 00108$:
                           001475  4433 	C$fuzzy.h$2254$2_0$85 ==.
                                   4434 ;	../../fuzzy.h:2254: parameters[2],
      00152C E5 08            [12] 4435 	mov	a,_bp
      00152E 24 F4            [12] 4436 	add	a,#0xf4
      001530 F8               [12] 4437 	mov	r0,a
      001531 74 08            [12] 4438 	mov	a,#0x08
      001533 26               [12] 4439 	add	a, @r0
      001534 FD               [12] 4440 	mov	r5,a
      001535 E4               [12] 4441 	clr	a
      001536 08               [12] 4442 	inc	r0
      001537 36               [12] 4443 	addc	a, @r0
      001538 FE               [12] 4444 	mov	r6,a
      001539 08               [12] 4445 	inc	r0
      00153A 86 07            [24] 4446 	mov	ar7,@r0
      00153C 8D 82            [24] 4447 	mov	dpl,r5
      00153E 8E 83            [24] 4448 	mov	dph,r6
      001540 8F F0            [24] 4449 	mov	b,r7
      001542 A8 08            [24] 4450 	mov	r0,_bp
      001544 08               [12] 4451 	inc	r0
      001545 12 37 EE         [24] 4452 	lcall	__gptrget
      001548 F6               [12] 4453 	mov	@r0,a
      001549 A3               [24] 4454 	inc	dptr
      00154A 12 37 EE         [24] 4455 	lcall	__gptrget
      00154D 08               [12] 4456 	inc	r0
      00154E F6               [12] 4457 	mov	@r0,a
      00154F A3               [24] 4458 	inc	dptr
      001550 12 37 EE         [24] 4459 	lcall	__gptrget
      001553 08               [12] 4460 	inc	r0
      001554 F6               [12] 4461 	mov	@r0,a
      001555 A3               [24] 4462 	inc	dptr
      001556 12 37 EE         [24] 4463 	lcall	__gptrget
      001559 08               [12] 4464 	inc	r0
      00155A F6               [12] 4465 	mov	@r0,a
                           0014A4  4466 	C$fuzzy.h$2253$2_0$85 ==.
                                   4467 ;	../../fuzzy.h:2253: parameters[1],
      00155B E5 08            [12] 4468 	mov	a,_bp
      00155D 24 F4            [12] 4469 	add	a,#0xf4
      00155F F8               [12] 4470 	mov	r0,a
      001560 74 04            [12] 4471 	mov	a,#0x04
      001562 26               [12] 4472 	add	a, @r0
      001563 FA               [12] 4473 	mov	r2,a
      001564 E4               [12] 4474 	clr	a
      001565 08               [12] 4475 	inc	r0
      001566 36               [12] 4476 	addc	a, @r0
      001567 FB               [12] 4477 	mov	r3,a
      001568 08               [12] 4478 	inc	r0
      001569 86 07            [24] 4479 	mov	ar7,@r0
      00156B 8A 82            [24] 4480 	mov	dpl,r2
      00156D 8B 83            [24] 4481 	mov	dph,r3
      00156F 8F F0            [24] 4482 	mov	b,r7
      001571 E5 08            [12] 4483 	mov	a,_bp
      001573 24 05            [12] 4484 	add	a,#0x05
      001575 F8               [12] 4485 	mov	r0,a
      001576 12 37 EE         [24] 4486 	lcall	__gptrget
      001579 F6               [12] 4487 	mov	@r0,a
      00157A A3               [24] 4488 	inc	dptr
      00157B 12 37 EE         [24] 4489 	lcall	__gptrget
      00157E 08               [12] 4490 	inc	r0
      00157F F6               [12] 4491 	mov	@r0,a
      001580 A3               [24] 4492 	inc	dptr
      001581 12 37 EE         [24] 4493 	lcall	__gptrget
      001584 08               [12] 4494 	inc	r0
      001585 F6               [12] 4495 	mov	@r0,a
      001586 A3               [24] 4496 	inc	dptr
      001587 12 37 EE         [24] 4497 	lcall	__gptrget
      00158A 08               [12] 4498 	inc	r0
      00158B F6               [12] 4499 	mov	@r0,a
                           0014D5  4500 	C$fuzzy.h$2252$2_0$85 ==.
                                   4501 ;	../../fuzzy.h:2252: parameters[0],
      00158C E5 08            [12] 4502 	mov	a,_bp
      00158E 24 F4            [12] 4503 	add	a,#0xf4
      001590 F8               [12] 4504 	mov	r0,a
      001591 86 04            [24] 4505 	mov	ar4,@r0
      001593 08               [12] 4506 	inc	r0
      001594 86 05            [24] 4507 	mov	ar5,@r0
      001596 08               [12] 4508 	inc	r0
      001597 86 07            [24] 4509 	mov	ar7,@r0
      001599 8C 82            [24] 4510 	mov	dpl,r4
      00159B 8D 83            [24] 4511 	mov	dph,r5
      00159D 8F F0            [24] 4512 	mov	b,r7
      00159F 12 37 EE         [24] 4513 	lcall	__gptrget
      0015A2 FC               [12] 4514 	mov	r4,a
      0015A3 A3               [24] 4515 	inc	dptr
      0015A4 12 37 EE         [24] 4516 	lcall	__gptrget
      0015A7 FD               [12] 4517 	mov	r5,a
      0015A8 A3               [24] 4518 	inc	dptr
      0015A9 12 37 EE         [24] 4519 	lcall	__gptrget
      0015AC FF               [12] 4520 	mov	r7,a
      0015AD A3               [24] 4521 	inc	dptr
      0015AE 12 37 EE         [24] 4522 	lcall	__gptrget
      0015B1 FE               [12] 4523 	mov	r6,a
      0015B2 E5 08            [12] 4524 	mov	a,_bp
      0015B4 24 F9            [12] 4525 	add	a,#0xf9
      0015B6 F8               [12] 4526 	mov	r0,a
      0015B7 E6               [12] 4527 	mov	a,@r0
      0015B8 C0 E0            [24] 4528 	push	acc
      0015BA E5 08            [12] 4529 	mov	a,_bp
      0015BC 24 FA            [12] 4530 	add	a,#0xfa
      0015BE F8               [12] 4531 	mov	r0,a
      0015BF E6               [12] 4532 	mov	a,@r0
      0015C0 C0 E0            [24] 4533 	push	acc
      0015C2 08               [12] 4534 	inc	r0
      0015C3 E6               [12] 4535 	mov	a,@r0
      0015C4 C0 E0            [24] 4536 	push	acc
      0015C6 08               [12] 4537 	inc	r0
      0015C7 E6               [12] 4538 	mov	a,@r0
      0015C8 C0 E0            [24] 4539 	push	acc
      0015CA 08               [12] 4540 	inc	r0
      0015CB E6               [12] 4541 	mov	a,@r0
      0015CC C0 E0            [24] 4542 	push	acc
      0015CE A8 08            [24] 4543 	mov	r0,_bp
      0015D0 08               [12] 4544 	inc	r0
      0015D1 E6               [12] 4545 	mov	a,@r0
      0015D2 C0 E0            [24] 4546 	push	acc
      0015D4 08               [12] 4547 	inc	r0
      0015D5 E6               [12] 4548 	mov	a,@r0
      0015D6 C0 E0            [24] 4549 	push	acc
      0015D8 08               [12] 4550 	inc	r0
      0015D9 E6               [12] 4551 	mov	a,@r0
      0015DA C0 E0            [24] 4552 	push	acc
      0015DC 08               [12] 4553 	inc	r0
      0015DD E6               [12] 4554 	mov	a,@r0
      0015DE C0 E0            [24] 4555 	push	acc
      0015E0 E5 08            [12] 4556 	mov	a,_bp
      0015E2 24 05            [12] 4557 	add	a,#0x05
      0015E4 F8               [12] 4558 	mov	r0,a
      0015E5 E6               [12] 4559 	mov	a,@r0
      0015E6 C0 E0            [24] 4560 	push	acc
      0015E8 08               [12] 4561 	inc	r0
      0015E9 E6               [12] 4562 	mov	a,@r0
      0015EA C0 E0            [24] 4563 	push	acc
      0015EC 08               [12] 4564 	inc	r0
      0015ED E6               [12] 4565 	mov	a,@r0
      0015EE C0 E0            [24] 4566 	push	acc
      0015F0 08               [12] 4567 	inc	r0
      0015F1 E6               [12] 4568 	mov	a,@r0
      0015F2 C0 E0            [24] 4569 	push	acc
      0015F4 8C 82            [24] 4570 	mov	dpl, r4
      0015F6 8D 83            [24] 4571 	mov	dph, r5
      0015F8 8F F0            [24] 4572 	mov	b, r7
      0015FA EE               [12] 4573 	mov	a, r6
      0015FB 12 0D 29         [24] 4574 	lcall	_fuzzy_triangle
      0015FE AC 82            [24] 4575 	mov	r4, dpl
      001600 AD 83            [24] 4576 	mov	r5, dph
      001602 AE F0            [24] 4577 	mov	r6, b
      001604 FF               [12] 4578 	mov	r7, a
      001605 E5 81            [12] 4579 	mov	a,sp
      001607 24 F3            [12] 4580 	add	a,#0xf3
      001609 F5 81            [12] 4581 	mov	sp,a
      00160B 8C 82            [24] 4582 	mov	dpl, r4
      00160D 8D 83            [24] 4583 	mov	dph, r5
      00160F 8E F0            [24] 4584 	mov	b, r6
      001611 EF               [12] 4585 	mov	a, r7
      001612 02 17 67         [24] 4586 	ljmp	00123$
                           00155E  4587 	C$fuzzy.h$2259$2_0$85 ==.
                                   4588 ;	../../fuzzy.h:2259: case FUZZY_SHAPE_TRAPEZOID:
      001615                       4589 00109$:
                           00155E  4590 	C$fuzzy.h$2260$2_0$85 ==.
                                   4591 ;	../../fuzzy.h:2260: if (parameter_count != 4u) {
      001615 E5 08            [12] 4592 	mov	a,_bp
      001617 24 F7            [12] 4593 	add	a,#0xf7
      001619 F8               [12] 4594 	mov	r0,a
      00161A B6 04 06         [24] 4595 	cjne	@r0,#0x04,00162$
      00161D 08               [12] 4596 	inc	r0
      00161E B6 00 02         [24] 4597 	cjne	@r0,#0x00,00162$
      001621 80 09            [24] 4598 	sjmp	00111$
      001623                       4599 00162$:
                           00156C  4600 	C$fuzzy.h$2261$3_0$88 ==.
                                   4601 ;	../../fuzzy.h:2261: return LEVEL_LO;
      001623 90 00 00         [24] 4602 	mov	dptr,#0x0000
      001626 E4               [12] 4603 	clr	a
      001627 F5 F0            [12] 4604 	mov	b,a
      001629 02 17 67         [24] 4605 	ljmp	00123$
      00162C                       4606 00111$:
                           001575  4607 	C$fuzzy.h$2268$2_0$85 ==.
                                   4608 ;	../../fuzzy.h:2268: parameters[3],
      00162C E5 08            [12] 4609 	mov	a,_bp
      00162E 24 F4            [12] 4610 	add	a,#0xf4
      001630 F8               [12] 4611 	mov	r0,a
      001631 74 0C            [12] 4612 	mov	a,#0x0c
      001633 26               [12] 4613 	add	a, @r0
      001634 FD               [12] 4614 	mov	r5,a
      001635 E4               [12] 4615 	clr	a
      001636 08               [12] 4616 	inc	r0
      001637 36               [12] 4617 	addc	a, @r0
      001638 FE               [12] 4618 	mov	r6,a
      001639 08               [12] 4619 	inc	r0
      00163A 86 07            [24] 4620 	mov	ar7,@r0
      00163C 8D 82            [24] 4621 	mov	dpl,r5
      00163E 8E 83            [24] 4622 	mov	dph,r6
      001640 8F F0            [24] 4623 	mov	b,r7
      001642 E5 08            [12] 4624 	mov	a,_bp
      001644 24 05            [12] 4625 	add	a,#0x05
      001646 F8               [12] 4626 	mov	r0,a
      001647 12 37 EE         [24] 4627 	lcall	__gptrget
      00164A F6               [12] 4628 	mov	@r0,a
      00164B A3               [24] 4629 	inc	dptr
      00164C 12 37 EE         [24] 4630 	lcall	__gptrget
      00164F 08               [12] 4631 	inc	r0
      001650 F6               [12] 4632 	mov	@r0,a
      001651 A3               [24] 4633 	inc	dptr
      001652 12 37 EE         [24] 4634 	lcall	__gptrget
      001655 08               [12] 4635 	inc	r0
      001656 F6               [12] 4636 	mov	@r0,a
      001657 A3               [24] 4637 	inc	dptr
      001658 12 37 EE         [24] 4638 	lcall	__gptrget
      00165B 08               [12] 4639 	inc	r0
      00165C F6               [12] 4640 	mov	@r0,a
                           0015A6  4641 	C$fuzzy.h$2267$2_0$85 ==.
                                   4642 ;	../../fuzzy.h:2267: parameters[2],
      00165D E5 08            [12] 4643 	mov	a,_bp
      00165F 24 F4            [12] 4644 	add	a,#0xf4
      001661 F8               [12] 4645 	mov	r0,a
      001662 74 08            [12] 4646 	mov	a,#0x08
      001664 26               [12] 4647 	add	a, @r0
      001665 FA               [12] 4648 	mov	r2,a
      001666 E4               [12] 4649 	clr	a
      001667 08               [12] 4650 	inc	r0
      001668 36               [12] 4651 	addc	a, @r0
      001669 FB               [12] 4652 	mov	r3,a
      00166A 08               [12] 4653 	inc	r0
      00166B 86 07            [24] 4654 	mov	ar7,@r0
      00166D 8A 82            [24] 4655 	mov	dpl,r2
      00166F 8B 83            [24] 4656 	mov	dph,r3
      001671 8F F0            [24] 4657 	mov	b,r7
      001673 A8 08            [24] 4658 	mov	r0,_bp
      001675 08               [12] 4659 	inc	r0
      001676 12 37 EE         [24] 4660 	lcall	__gptrget
      001679 F6               [12] 4661 	mov	@r0,a
      00167A A3               [24] 4662 	inc	dptr
      00167B 12 37 EE         [24] 4663 	lcall	__gptrget
      00167E 08               [12] 4664 	inc	r0
      00167F F6               [12] 4665 	mov	@r0,a
      001680 A3               [24] 4666 	inc	dptr
      001681 12 37 EE         [24] 4667 	lcall	__gptrget
      001684 08               [12] 4668 	inc	r0
      001685 F6               [12] 4669 	mov	@r0,a
      001686 A3               [24] 4670 	inc	dptr
      001687 12 37 EE         [24] 4671 	lcall	__gptrget
      00168A 08               [12] 4672 	inc	r0
      00168B F6               [12] 4673 	mov	@r0,a
                           0015D5  4674 	C$fuzzy.h$2266$2_0$85 ==.
                                   4675 ;	../../fuzzy.h:2266: parameters[1],
      00168C E5 08            [12] 4676 	mov	a,_bp
      00168E 24 F4            [12] 4677 	add	a,#0xf4
      001690 F8               [12] 4678 	mov	r0,a
      001691 74 04            [12] 4679 	mov	a,#0x04
      001693 26               [12] 4680 	add	a, @r0
      001694 FC               [12] 4681 	mov	r4,a
      001695 E4               [12] 4682 	clr	a
      001696 08               [12] 4683 	inc	r0
      001697 36               [12] 4684 	addc	a, @r0
      001698 FD               [12] 4685 	mov	r5,a
      001699 08               [12] 4686 	inc	r0
      00169A 86 07            [24] 4687 	mov	ar7,@r0
      00169C 8C 82            [24] 4688 	mov	dpl,r4
      00169E 8D 83            [24] 4689 	mov	dph,r5
      0016A0 8F F0            [24] 4690 	mov	b,r7
      0016A2 E5 08            [12] 4691 	mov	a,_bp
      0016A4 24 09            [12] 4692 	add	a,#0x09
      0016A6 F8               [12] 4693 	mov	r0,a
      0016A7 12 37 EE         [24] 4694 	lcall	__gptrget
      0016AA F6               [12] 4695 	mov	@r0,a
      0016AB A3               [24] 4696 	inc	dptr
      0016AC 12 37 EE         [24] 4697 	lcall	__gptrget
      0016AF 08               [12] 4698 	inc	r0
      0016B0 F6               [12] 4699 	mov	@r0,a
      0016B1 A3               [24] 4700 	inc	dptr
      0016B2 12 37 EE         [24] 4701 	lcall	__gptrget
      0016B5 08               [12] 4702 	inc	r0
      0016B6 F6               [12] 4703 	mov	@r0,a
      0016B7 A3               [24] 4704 	inc	dptr
      0016B8 12 37 EE         [24] 4705 	lcall	__gptrget
      0016BB 08               [12] 4706 	inc	r0
      0016BC F6               [12] 4707 	mov	@r0,a
                           001606  4708 	C$fuzzy.h$2265$2_0$85 ==.
                                   4709 ;	../../fuzzy.h:2265: parameters[0],
      0016BD E5 08            [12] 4710 	mov	a,_bp
      0016BF 24 F4            [12] 4711 	add	a,#0xf4
      0016C1 F8               [12] 4712 	mov	r0,a
      0016C2 86 02            [24] 4713 	mov	ar2,@r0
      0016C4 08               [12] 4714 	inc	r0
      0016C5 86 03            [24] 4715 	mov	ar3,@r0
      0016C7 08               [12] 4716 	inc	r0
      0016C8 86 07            [24] 4717 	mov	ar7,@r0
      0016CA 8A 82            [24] 4718 	mov	dpl,r2
      0016CC 8B 83            [24] 4719 	mov	dph,r3
      0016CE 8F F0            [24] 4720 	mov	b,r7
      0016D0 12 37 EE         [24] 4721 	lcall	__gptrget
      0016D3 FA               [12] 4722 	mov	r2,a
      0016D4 A3               [24] 4723 	inc	dptr
      0016D5 12 37 EE         [24] 4724 	lcall	__gptrget
      0016D8 FB               [12] 4725 	mov	r3,a
      0016D9 A3               [24] 4726 	inc	dptr
      0016DA 12 37 EE         [24] 4727 	lcall	__gptrget
      0016DD FF               [12] 4728 	mov	r7,a
      0016DE A3               [24] 4729 	inc	dptr
      0016DF 12 37 EE         [24] 4730 	lcall	__gptrget
      0016E2 FE               [12] 4731 	mov	r6,a
      0016E3 E5 08            [12] 4732 	mov	a,_bp
      0016E5 24 F9            [12] 4733 	add	a,#0xf9
      0016E7 F8               [12] 4734 	mov	r0,a
      0016E8 E6               [12] 4735 	mov	a,@r0
      0016E9 C0 E0            [24] 4736 	push	acc
      0016EB E5 08            [12] 4737 	mov	a,_bp
      0016ED 24 FA            [12] 4738 	add	a,#0xfa
      0016EF F8               [12] 4739 	mov	r0,a
      0016F0 E6               [12] 4740 	mov	a,@r0
      0016F1 C0 E0            [24] 4741 	push	acc
      0016F3 08               [12] 4742 	inc	r0
      0016F4 E6               [12] 4743 	mov	a,@r0
      0016F5 C0 E0            [24] 4744 	push	acc
      0016F7 08               [12] 4745 	inc	r0
      0016F8 E6               [12] 4746 	mov	a,@r0
      0016F9 C0 E0            [24] 4747 	push	acc
      0016FB 08               [12] 4748 	inc	r0
      0016FC E6               [12] 4749 	mov	a,@r0
      0016FD C0 E0            [24] 4750 	push	acc
      0016FF E5 08            [12] 4751 	mov	a,_bp
      001701 24 05            [12] 4752 	add	a,#0x05
      001703 F8               [12] 4753 	mov	r0,a
      001704 E6               [12] 4754 	mov	a,@r0
      001705 C0 E0            [24] 4755 	push	acc
      001707 08               [12] 4756 	inc	r0
      001708 E6               [12] 4757 	mov	a,@r0
      001709 C0 E0            [24] 4758 	push	acc
      00170B 08               [12] 4759 	inc	r0
      00170C E6               [12] 4760 	mov	a,@r0
      00170D C0 E0            [24] 4761 	push	acc
      00170F 08               [12] 4762 	inc	r0
      001710 E6               [12] 4763 	mov	a,@r0
      001711 C0 E0            [24] 4764 	push	acc
      001713 A8 08            [24] 4765 	mov	r0,_bp
      001715 08               [12] 4766 	inc	r0
      001716 E6               [12] 4767 	mov	a,@r0
      001717 C0 E0            [24] 4768 	push	acc
      001719 08               [12] 4769 	inc	r0
      00171A E6               [12] 4770 	mov	a,@r0
      00171B C0 E0            [24] 4771 	push	acc
      00171D 08               [12] 4772 	inc	r0
      00171E E6               [12] 4773 	mov	a,@r0
      00171F C0 E0            [24] 4774 	push	acc
      001721 08               [12] 4775 	inc	r0
      001722 E6               [12] 4776 	mov	a,@r0
      001723 C0 E0            [24] 4777 	push	acc
      001725 E5 08            [12] 4778 	mov	a,_bp
      001727 24 09            [12] 4779 	add	a,#0x09
      001729 F8               [12] 4780 	mov	r0,a
      00172A E6               [12] 4781 	mov	a,@r0
      00172B C0 E0            [24] 4782 	push	acc
      00172D 08               [12] 4783 	inc	r0
      00172E E6               [12] 4784 	mov	a,@r0
      00172F C0 E0            [24] 4785 	push	acc
      001731 08               [12] 4786 	inc	r0
      001732 E6               [12] 4787 	mov	a,@r0
      001733 C0 E0            [24] 4788 	push	acc
      001735 08               [12] 4789 	inc	r0
      001736 E6               [12] 4790 	mov	a,@r0
      001737 C0 E0            [24] 4791 	push	acc
      001739 8A 82            [24] 4792 	mov	dpl, r2
      00173B 8B 83            [24] 4793 	mov	dph, r3
      00173D 8F F0            [24] 4794 	mov	b, r7
      00173F EE               [12] 4795 	mov	a, r6
      001740 12 10 35         [24] 4796 	lcall	_fuzzy_trapezoid
      001743 AC 82            [24] 4797 	mov	r4, dpl
      001745 AD 83            [24] 4798 	mov	r5, dph
      001747 AE F0            [24] 4799 	mov	r6, b
      001749 FF               [12] 4800 	mov	r7, a
      00174A E5 81            [12] 4801 	mov	a,sp
      00174C 24 EF            [12] 4802 	add	a,#0xef
      00174E F5 81            [12] 4803 	mov	sp,a
      001750 8C 82            [24] 4804 	mov	dpl, r4
      001752 8D 83            [24] 4805 	mov	dph, r5
      001754 8E F0            [24] 4806 	mov	b, r6
      001756 EF               [12] 4807 	mov	a, r7
                           0016A0  4808 	C$fuzzy.h$2402$2_0$85 ==.
                                   4809 ;	../../fuzzy.h:2402: case FUZZY_SHAPE_PSIGMOID:
      001757 80 0E            [24] 4810 	sjmp	00123$
      001759                       4811 00120$:
                           0016A2  4812 	C$fuzzy.h$2403$2_0$85 ==.
                                   4813 ;	../../fuzzy.h:2403: return LEVEL_LO;
      001759 90 00 00         [24] 4814 	mov	dptr,#0x0000
      00175C E4               [12] 4815 	clr	a
      00175D F5 F0            [12] 4816 	mov	b,a
                           0016A8  4817 	C$fuzzy.h$2407$2_0$85 ==.
                                   4818 ;	../../fuzzy.h:2407: default:
      00175F 80 06            [24] 4819 	sjmp	00123$
      001761                       4820 00121$:
                           0016AA  4821 	C$fuzzy.h$2408$2_0$85 ==.
                                   4822 ;	../../fuzzy.h:2408: return LEVEL_LO;
      001761 90 00 00         [24] 4823 	mov	dptr,#0x0000
      001764 E4               [12] 4824 	clr	a
      001765 F5 F0            [12] 4825 	mov	b,a
                           0016B0  4826 	C$fuzzy.h$2409$1_0$83 ==.
                                   4827 ;	../../fuzzy.h:2409: }
      001767                       4828 00123$:
                           0016B0  4829 	C$fuzzy.h$2410$1_0$83 ==.
                                   4830 ;	../../fuzzy.h:2410: }
      001767 85 08 81         [24] 4831 	mov	sp,_bp
      00176A D0 08            [24] 4832 	pop	_bp
                           0016B5  4833 	C$fuzzy.h$2410$1_0$83 ==.
                           0016B5  4834 	XG$fuzzy_function_array$0$0 ==.
      00176C 22               [24] 4835 	ret
                                   4836 ;------------------------------------------------------------
                                   4837 ;Allocation info for local variables in function 'fuzzy_rules_add'
                                   4838 ;------------------------------------------------------------
                                   4839 ;name          Allocated to stack - _bp -5 +3 
                                   4840 ;value         Allocated to stack - _bp -9 +4 
                                   4841 ;output_function Allocated to stack - _bp -11 +2 
                                   4842 ;rules         Allocated to registers r2 r3 r4 
                                   4843 ;index         Allocated to registers 
                                   4844 ;sloc0         Allocated to stack - _bp +1 +2 
                                   4845 ;sloc1         Allocated to stack - _bp +3 +3 
                                   4846 ;sloc2         Allocated to stack - _bp +6 +3 
                                   4847 ;sloc3         Allocated to stack - _bp +9 +3 
                                   4848 ;------------------------------------------------------------
                           0016B6  4849 	G$fuzzy_rules_add$0$0 ==.
                           0016B6  4850 	C$fuzzy.h$2412$1_0$90 ==.
                                   4851 ;	../../fuzzy.h:2412: bool fuzzy_rules_add(
                                   4852 ;	-----------------------------------------
                                   4853 ;	 function fuzzy_rules_add
                                   4854 ;	-----------------------------------------
      00176D                       4855 _fuzzy_rules_add:
      00176D C0 08            [24] 4856 	push	_bp
      00176F E5 81            [12] 4857 	mov	a,sp
      001771 F5 08            [12] 4858 	mov	_bp,a
      001773 24 0B            [12] 4859 	add	a,#0x0b
      001775 F5 81            [12] 4860 	mov	sp,a
      001777 AA 82            [24] 4861 	mov	r2, dpl
      001779 AB 83            [24] 4862 	mov	r3, dph
      00177B AC F0            [24] 4863 	mov	r4, b
                           0016C6  4864 	C$fuzzy.h$2422$1_0$90 ==.
                                   4865 ;	../../fuzzy.h:2422: rules == NULL ||
      00177D EA               [12] 4866 	mov	a,r2
      00177E 4B               [12] 4867 	orl	a,r3
      00177F 60 0A            [24] 4868 	jz	00101$
                           0016CA  4869 	C$fuzzy.h$2423$1_0$90 ==.
                                   4870 ;	../../fuzzy.h:2423: output_function == NULL
      001781 E5 08            [12] 4871 	mov	a,_bp
      001783 24 F5            [12] 4872 	add	a,#0xf5
      001785 F8               [12] 4873 	mov	r0,a
      001786 E6               [12] 4874 	mov	a,@r0
      001787 08               [12] 4875 	inc	r0
      001788 46               [12] 4876 	orl	a,@r0
      001789 70 06            [24] 4877 	jnz	00102$
      00178B                       4878 00101$:
                           0016D4  4879 	C$fuzzy.h$2425$2_0$91 ==.
                                   4880 ;	../../fuzzy.h:2425: return false;
      00178B 75 82 00         [24] 4881 	mov	dpl, #0x00
      00178E 02 18 CB         [24] 4882 	ljmp	00106$
      001791                       4883 00102$:
                           0016DA  4884 	C$fuzzy.h$2428$1_0$90 ==.
                                   4885 ;	../../fuzzy.h:2428: if (rules->count >= FUZZY_MAX_RULES) {
      001791 E5 08            [12] 4886 	mov	a,_bp
      001793 24 09            [12] 4887 	add	a,#0x09
      001795 F8               [12] 4888 	mov	r0,a
      001796 74 90            [12] 4889 	mov	a,#0x90
      001798 2A               [12] 4890 	add	a, r2
      001799 F6               [12] 4891 	mov	@r0,a
      00179A E4               [12] 4892 	clr	a
      00179B 3B               [12] 4893 	addc	a, r3
      00179C 08               [12] 4894 	inc	r0
      00179D F6               [12] 4895 	mov	@r0,a
      00179E 08               [12] 4896 	inc	r0
      00179F A6 04            [24] 4897 	mov	@r0,ar4
      0017A1 E5 08            [12] 4898 	mov	a,_bp
      0017A3 24 09            [12] 4899 	add	a,#0x09
      0017A5 F8               [12] 4900 	mov	r0,a
      0017A6 86 82            [24] 4901 	mov	dpl,@r0
      0017A8 08               [12] 4902 	inc	r0
      0017A9 86 83            [24] 4903 	mov	dph,@r0
      0017AB 08               [12] 4904 	inc	r0
      0017AC 86 F0            [24] 4905 	mov	b,@r0
      0017AE 12 37 EE         [24] 4906 	lcall	__gptrget
      0017B1 FF               [12] 4907 	mov	r7,a
      0017B2 A3               [24] 4908 	inc	dptr
      0017B3 12 37 EE         [24] 4909 	lcall	__gptrget
      0017B6 FE               [12] 4910 	mov	r6,a
      0017B7 C3               [12] 4911 	clr	c
      0017B8 EF               [12] 4912 	mov	a,r7
      0017B9 94 10            [12] 4913 	subb	a,#0x10
      0017BB EE               [12] 4914 	mov	a,r6
      0017BC 94 00            [12] 4915 	subb	a,#0x00
      0017BE 40 06            [24] 4916 	jc	00105$
                           001709  4917 	C$fuzzy.h$2429$2_0$92 ==.
                                   4918 ;	../../fuzzy.h:2429: return false;
      0017C0 75 82 00         [24] 4919 	mov	dpl, #0x00
      0017C3 02 18 CB         [24] 4920 	ljmp	00106$
      0017C6                       4921 00105$:
                           00170F  4922 	C$fuzzy.h$2435$1_0$90 ==.
                                   4923 ;	../../fuzzy.h:2435: rules->rules[index].name =
      0017C6 C0 04            [24] 4924 	push	ar4
      0017C8 C0 03            [24] 4925 	push	ar3
      0017CA C0 02            [24] 4926 	push	ar2
      0017CC C0 07            [24] 4927 	push	ar7
      0017CE C0 06            [24] 4928 	push	ar6
      0017D0 90 00 09         [24] 4929 	mov	dptr,#0x0009
      0017D3 12 35 F2         [24] 4930 	lcall	__mulint
      0017D6 A8 08            [24] 4931 	mov	r0,_bp
      0017D8 08               [12] 4932 	inc	r0
      0017D9 A6 82            [24] 4933 	mov	@r0, dpl
      0017DB 08               [12] 4934 	inc	r0
      0017DC A6 83            [24] 4935 	mov	@r0, dph
      0017DE 15 81            [12] 4936 	dec	sp
      0017E0 15 81            [12] 4937 	dec	sp
      0017E2 D0 02            [24] 4938 	pop	ar2
      0017E4 D0 03            [24] 4939 	pop	ar3
      0017E6 D0 04            [24] 4940 	pop	ar4
      0017E8 A8 08            [24] 4941 	mov	r0,_bp
      0017EA 08               [12] 4942 	inc	r0
      0017EB E6               [12] 4943 	mov	a,@r0
      0017EC 2A               [12] 4944 	add	a, r2
      0017ED FD               [12] 4945 	mov	r5,a
      0017EE 08               [12] 4946 	inc	r0
      0017EF E6               [12] 4947 	mov	a,@r0
      0017F0 3B               [12] 4948 	addc	a, r3
      0017F1 FE               [12] 4949 	mov	r6,a
      0017F2 8C 07            [24] 4950 	mov	ar7,r4
      0017F4 8D 82            [24] 4951 	mov	dpl,r5
      0017F6 8E 83            [24] 4952 	mov	dph,r6
      0017F8 8F F0            [24] 4953 	mov	b,r7
      0017FA E5 08            [12] 4954 	mov	a,_bp
      0017FC 24 FB            [12] 4955 	add	a,#0xfb
      0017FE F8               [12] 4956 	mov	r0,a
      0017FF E6               [12] 4957 	mov	a,@r0
      001800 12 35 A7         [24] 4958 	lcall	__gptrput
      001803 A3               [24] 4959 	inc	dptr
      001804 08               [12] 4960 	inc	r0
      001805 E6               [12] 4961 	mov	a,@r0
      001806 12 35 A7         [24] 4962 	lcall	__gptrput
      001809 A3               [24] 4963 	inc	dptr
      00180A 08               [12] 4964 	inc	r0
      00180B E6               [12] 4965 	mov	a,@r0
      00180C 12 35 A7         [24] 4966 	lcall	__gptrput
                           001758  4967 	C$fuzzy.h$2438$1_0$90 ==.
                                   4968 ;	../../fuzzy.h:2438: rules->rules[index].value =
      00180F A8 08            [24] 4969 	mov	r0,_bp
      001811 08               [12] 4970 	inc	r0
      001812 E5 08            [12] 4971 	mov	a,_bp
      001814 24 03            [12] 4972 	add	a,#0x03
      001816 F9               [12] 4973 	mov	r1,a
      001817 E6               [12] 4974 	mov	a,@r0
      001818 2A               [12] 4975 	add	a, r2
      001819 F7               [12] 4976 	mov	@r1,a
      00181A 08               [12] 4977 	inc	r0
      00181B E6               [12] 4978 	mov	a,@r0
      00181C 3B               [12] 4979 	addc	a, r3
      00181D 09               [12] 4980 	inc	r1
      00181E F7               [12] 4981 	mov	@r1,a
      00181F 09               [12] 4982 	inc	r1
      001820 A7 04            [24] 4983 	mov	@r1,ar4
      001822 E5 08            [12] 4984 	mov	a,_bp
      001824 24 03            [12] 4985 	add	a,#0x03
      001826 F8               [12] 4986 	mov	r0,a
      001827 E5 08            [12] 4987 	mov	a,_bp
      001829 24 06            [12] 4988 	add	a,#0x06
      00182B F9               [12] 4989 	mov	r1,a
      00182C 74 03            [12] 4990 	mov	a,#0x03
      00182E 26               [12] 4991 	add	a, @r0
      00182F F7               [12] 4992 	mov	@r1,a
      001830 E4               [12] 4993 	clr	a
      001831 08               [12] 4994 	inc	r0
      001832 36               [12] 4995 	addc	a, @r0
      001833 09               [12] 4996 	inc	r1
      001834 F7               [12] 4997 	mov	@r1,a
      001835 08               [12] 4998 	inc	r0
      001836 E6               [12] 4999 	mov	a,@r0
      001837 09               [12] 5000 	inc	r1
      001838 F7               [12] 5001 	mov	@r1,a
                           001782  5002 	C$fuzzy.h$2439$1_0$90 ==.
                                   5003 ;	../../fuzzy.h:2439: fuzzy_clamp(value);
      001839 E5 08            [12] 5004 	mov	a,_bp
      00183B 24 F7            [12] 5005 	add	a,#0xf7
      00183D F8               [12] 5006 	mov	r0,a
      00183E 86 82            [24] 5007 	mov	dpl, @r0
      001840 08               [12] 5008 	inc	r0
      001841 86 83            [24] 5009 	mov	dph, @r0
      001843 08               [12] 5010 	inc	r0
      001844 86 F0            [24] 5011 	mov	b, @r0
      001846 08               [12] 5012 	inc	r0
      001847 E6               [12] 5013 	mov	a, @r0
      001848 12 00 EA         [24] 5014 	lcall	_fuzzy_clamp
      00184B AD 82            [24] 5015 	mov	r5, dpl
      00184D AE 83            [24] 5016 	mov	r6, dph
      00184F AC F0            [24] 5017 	mov	r4, b
      001851 FF               [12] 5018 	mov	r7, a
      001852 E5 08            [12] 5019 	mov	a,_bp
      001854 24 06            [12] 5020 	add	a,#0x06
      001856 F8               [12] 5021 	mov	r0,a
      001857 86 82            [24] 5022 	mov	dpl,@r0
      001859 08               [12] 5023 	inc	r0
      00185A 86 83            [24] 5024 	mov	dph,@r0
      00185C 08               [12] 5025 	inc	r0
      00185D 86 F0            [24] 5026 	mov	b,@r0
      00185F ED               [12] 5027 	mov	a,r5
      001860 12 35 A7         [24] 5028 	lcall	__gptrput
      001863 A3               [24] 5029 	inc	dptr
      001864 EE               [12] 5030 	mov	a,r6
      001865 12 35 A7         [24] 5031 	lcall	__gptrput
      001868 A3               [24] 5032 	inc	dptr
      001869 EC               [12] 5033 	mov	a,r4
      00186A 12 35 A7         [24] 5034 	lcall	__gptrput
      00186D A3               [24] 5035 	inc	dptr
      00186E EF               [12] 5036 	mov	a,r7
      00186F 12 35 A7         [24] 5037 	lcall	__gptrput
                           0017BB  5038 	C$fuzzy.h$2441$1_0$90 ==.
                                   5039 ;	../../fuzzy.h:2441: rules->rules[index].output_function =
      001872 E5 08            [12] 5040 	mov	a,_bp
      001874 24 03            [12] 5041 	add	a,#0x03
      001876 F8               [12] 5042 	mov	r0,a
      001877 74 07            [12] 5043 	mov	a,#0x07
      001879 26               [12] 5044 	add	a, @r0
      00187A FD               [12] 5045 	mov	r5,a
      00187B E4               [12] 5046 	clr	a
      00187C 08               [12] 5047 	inc	r0
      00187D 36               [12] 5048 	addc	a, @r0
      00187E FE               [12] 5049 	mov	r6,a
      00187F 08               [12] 5050 	inc	r0
      001880 86 07            [24] 5051 	mov	ar7,@r0
      001882 8D 82            [24] 5052 	mov	dpl,r5
      001884 8E 83            [24] 5053 	mov	dph,r6
      001886 8F F0            [24] 5054 	mov	b,r7
      001888 E5 08            [12] 5055 	mov	a,_bp
      00188A 24 F5            [12] 5056 	add	a,#0xf5
      00188C F8               [12] 5057 	mov	r0,a
      00188D E6               [12] 5058 	mov	a,@r0
      00188E 12 35 A7         [24] 5059 	lcall	__gptrput
      001891 A3               [24] 5060 	inc	dptr
      001892 08               [12] 5061 	inc	r0
      001893 E6               [12] 5062 	mov	a,@r0
      001894 12 35 A7         [24] 5063 	lcall	__gptrput
                           0017E0  5064 	C$fuzzy.h$2444$1_0$90 ==.
                                   5065 ;	../../fuzzy.h:2444: rules->count++;
      001897 E5 08            [12] 5066 	mov	a,_bp
      001899 24 09            [12] 5067 	add	a,#0x09
      00189B F8               [12] 5068 	mov	r0,a
      00189C 86 82            [24] 5069 	mov	dpl,@r0
      00189E 08               [12] 5070 	inc	r0
      00189F 86 83            [24] 5071 	mov	dph,@r0
      0018A1 08               [12] 5072 	inc	r0
      0018A2 86 F0            [24] 5073 	mov	b,@r0
      0018A4 12 37 EE         [24] 5074 	lcall	__gptrget
      0018A7 FE               [12] 5075 	mov	r6,a
      0018A8 A3               [24] 5076 	inc	dptr
      0018A9 12 37 EE         [24] 5077 	lcall	__gptrget
      0018AC FF               [12] 5078 	mov	r7,a
      0018AD 0E               [12] 5079 	inc	r6
      0018AE BE 00 01         [24] 5080 	cjne	r6,#0x00,00123$
      0018B1 0F               [12] 5081 	inc	r7
      0018B2                       5082 00123$:
      0018B2 E5 08            [12] 5083 	mov	a,_bp
      0018B4 24 09            [12] 5084 	add	a,#0x09
      0018B6 F8               [12] 5085 	mov	r0,a
      0018B7 86 82            [24] 5086 	mov	dpl,@r0
      0018B9 08               [12] 5087 	inc	r0
      0018BA 86 83            [24] 5088 	mov	dph,@r0
      0018BC 08               [12] 5089 	inc	r0
      0018BD 86 F0            [24] 5090 	mov	b,@r0
      0018BF EE               [12] 5091 	mov	a,r6
      0018C0 12 35 A7         [24] 5092 	lcall	__gptrput
      0018C3 A3               [24] 5093 	inc	dptr
      0018C4 EF               [12] 5094 	mov	a,r7
      0018C5 12 35 A7         [24] 5095 	lcall	__gptrput
                           001811  5096 	C$fuzzy.h$2446$1_0$90 ==.
                                   5097 ;	../../fuzzy.h:2446: return true;
      0018C8 75 82 01         [24] 5098 	mov	dpl, #0x01
      0018CB                       5099 00106$:
                           001814  5100 	C$fuzzy.h$2447$1_0$90 ==.
                                   5101 ;	../../fuzzy.h:2447: }
      0018CB 85 08 81         [24] 5102 	mov	sp,_bp
      0018CE D0 08            [24] 5103 	pop	_bp
                           001819  5104 	C$fuzzy.h$2447$1_0$90 ==.
                           001819  5105 	XG$fuzzy_rules_add$0$0 ==.
      0018D0 22               [24] 5106 	ret
                                   5107 ;------------------------------------------------------------
                                   5108 ;Allocation info for local variables in function 'fuzzy_implication'
                                   5109 ;------------------------------------------------------------
                                   5110 ;activation    Allocated to stack - _bp -6 +4 
                                   5111 ;membership    Allocated to stack - _bp -10 +4 
                                   5112 ;method        Allocated to registers r7 
                                   5113 ;sloc0         Allocated to stack - _bp +1 +4 
                                   5114 ;sloc1         Allocated to stack - _bp +5 +4 
                                   5115 ;------------------------------------------------------------
                           00181A  5116 	Fcontroller_8051$fuzzy_implication$0$0 ==.
                           00181A  5117 	C$fuzzy.h$2480$1_0$94 ==.
                                   5118 ;	../../fuzzy.h:2480: static float fuzzy_implication(
                                   5119 ;	-----------------------------------------
                                   5120 ;	 function fuzzy_implication
                                   5121 ;	-----------------------------------------
      0018D1                       5122 _fuzzy_implication:
      0018D1 C0 08            [24] 5123 	push	_bp
      0018D3 E5 81            [12] 5124 	mov	a,sp
      0018D5 F5 08            [12] 5125 	mov	_bp,a
      0018D7 24 08            [12] 5126 	add	a,#0x08
      0018D9 F5 81            [12] 5127 	mov	sp,a
      0018DB AF 82            [24] 5128 	mov	r7, dpl
                           001826  5129 	C$fuzzy.h$2486$1_0$94 ==.
                                   5130 ;	../../fuzzy.h:2486: activation = fuzzy_clamp(activation);
      0018DD E5 08            [12] 5131 	mov	a,_bp
      0018DF 24 FA            [12] 5132 	add	a,#0xfa
      0018E1 F8               [12] 5133 	mov	r0,a
      0018E2 86 82            [24] 5134 	mov	dpl, @r0
      0018E4 08               [12] 5135 	inc	r0
      0018E5 86 83            [24] 5136 	mov	dph, @r0
      0018E7 08               [12] 5137 	inc	r0
      0018E8 86 F0            [24] 5138 	mov	b, @r0
      0018EA 08               [12] 5139 	inc	r0
      0018EB E6               [12] 5140 	mov	a, @r0
      0018EC C0 07            [24] 5141 	push	ar7
      0018EE 12 00 EA         [24] 5142 	lcall	_fuzzy_clamp
      0018F1 AB 82            [24] 5143 	mov	r3, dpl
      0018F3 AC 83            [24] 5144 	mov	r4, dph
      0018F5 AD F0            [24] 5145 	mov	r5, b
      0018F7 FE               [12] 5146 	mov	r6, a
                           001841  5147 	C$fuzzy.h$2487$1_0$94 ==.
                                   5148 ;	../../fuzzy.h:2487: membership = fuzzy_clamp(membership);
      0018F8 E5 08            [12] 5149 	mov	a,_bp
      0018FA 24 F6            [12] 5150 	add	a,#0xf6
      0018FC F8               [12] 5151 	mov	r0,a
      0018FD 86 82            [24] 5152 	mov	dpl, @r0
      0018FF 08               [12] 5153 	inc	r0
      001900 86 83            [24] 5154 	mov	dph, @r0
      001902 08               [12] 5155 	inc	r0
      001903 86 F0            [24] 5156 	mov	b, @r0
      001905 08               [12] 5157 	inc	r0
      001906 E6               [12] 5158 	mov	a, @r0
      001907 C0 06            [24] 5159 	push	ar6
      001909 C0 05            [24] 5160 	push	ar5
      00190B C0 04            [24] 5161 	push	ar4
      00190D C0 03            [24] 5162 	push	ar3
      00190F 12 00 EA         [24] 5163 	lcall	_fuzzy_clamp
      001912 A8 08            [24] 5164 	mov	r0,_bp
      001914 08               [12] 5165 	inc	r0
      001915 A6 82            [24] 5166 	mov	@r0, dpl
      001917 08               [12] 5167 	inc	r0
      001918 A6 83            [24] 5168 	mov	@r0, dph
      00191A 08               [12] 5169 	inc	r0
      00191B A6 F0            [24] 5170 	mov	@r0, b
      00191D 08               [12] 5171 	inc	r0
      00191E F6               [12] 5172 	mov	@r0,a
      00191F D0 03            [24] 5173 	pop	ar3
      001921 D0 04            [24] 5174 	pop	ar4
      001923 D0 05            [24] 5175 	pop	ar5
      001925 D0 06            [24] 5176 	pop	ar6
      001927 D0 07            [24] 5177 	pop	ar7
                           001872  5178 	C$fuzzy.h$2489$1_0$94 ==.
                                   5179 ;	../../fuzzy.h:2489: switch (method) {
      001929 BF 00 02         [24] 5180 	cjne	r7,#0x00,00127$
      00192C 80 08            [24] 5181 	sjmp	00101$
      00192E                       5182 00127$:
      00192E BF 01 02         [24] 5183 	cjne	r7,#0x01,00128$
      001931 80 73            [24] 5184 	sjmp	00102$
      001933                       5185 00128$:
      001933 02 19 D8         [24] 5186 	ljmp	00103$
                           00187F  5187 	C$fuzzy.h$2490$2_0$95 ==.
                                   5188 ;	../../fuzzy.h:2490: case FUZZY_IMPLICATION_MIN:
      001936                       5189 00101$:
                           00187F  5190 	C$fuzzy.h$2492$1_0$94 ==.
                                   5191 ;	../../fuzzy.h:2492: ? activation
      001936 C0 06            [24] 5192 	push	ar6
      001938 C0 05            [24] 5193 	push	ar5
      00193A C0 04            [24] 5194 	push	ar4
      00193C C0 03            [24] 5195 	push	ar3
      00193E A8 08            [24] 5196 	mov	r0,_bp
      001940 08               [12] 5197 	inc	r0
      001941 E6               [12] 5198 	mov	a,@r0
      001942 C0 E0            [24] 5199 	push	acc
      001944 08               [12] 5200 	inc	r0
      001945 E6               [12] 5201 	mov	a,@r0
      001946 C0 E0            [24] 5202 	push	acc
      001948 08               [12] 5203 	inc	r0
      001949 E6               [12] 5204 	mov	a,@r0
      00194A C0 E0            [24] 5205 	push	acc
      00194C 08               [12] 5206 	inc	r0
      00194D E6               [12] 5207 	mov	a,@r0
      00194E C0 E0            [24] 5208 	push	acc
      001950 8B 82            [24] 5209 	mov	dpl, r3
      001952 8C 83            [24] 5210 	mov	dph, r4
      001954 8D F0            [24] 5211 	mov	b, r5
      001956 EE               [12] 5212 	mov	a, r6
      001957 12 35 C2         [24] 5213 	lcall	___fslt
      00195A AF 82            [24] 5214 	mov	r7, dpl
      00195C E5 81            [12] 5215 	mov	a,sp
      00195E 24 FC            [12] 5216 	add	a,#0xfc
      001960 F5 81            [12] 5217 	mov	sp,a
      001962 D0 03            [24] 5218 	pop	ar3
      001964 D0 04            [24] 5219 	pop	ar4
      001966 D0 05            [24] 5220 	pop	ar5
      001968 D0 06            [24] 5221 	pop	ar6
      00196A EF               [12] 5222 	mov	a,r7
      00196B 60 12            [24] 5223 	jz	00107$
      00196D E5 08            [12] 5224 	mov	a,_bp
      00196F 24 05            [12] 5225 	add	a,#0x05
      001971 F8               [12] 5226 	mov	r0,a
      001972 A6 03            [24] 5227 	mov	@r0,ar3
      001974 08               [12] 5228 	inc	r0
      001975 A6 04            [24] 5229 	mov	@r0,ar4
      001977 08               [12] 5230 	inc	r0
      001978 A6 05            [24] 5231 	mov	@r0,ar5
      00197A 08               [12] 5232 	inc	r0
      00197B A6 06            [24] 5233 	mov	@r0,ar6
      00197D 80 16            [24] 5234 	sjmp	00108$
      00197F                       5235 00107$:
                           0018C8  5236 	C$fuzzy.h$2493$2_0$95 ==.
                                   5237 ;	../../fuzzy.h:2493: : membership;
      00197F A8 08            [24] 5238 	mov	r0,_bp
      001981 08               [12] 5239 	inc	r0
      001982 E5 08            [12] 5240 	mov	a,_bp
      001984 24 05            [12] 5241 	add	a,#0x05
      001986 F9               [12] 5242 	mov	r1,a
      001987 E6               [12] 5243 	mov	a,@r0
      001988 F7               [12] 5244 	mov	@r1,a
      001989 08               [12] 5245 	inc	r0
      00198A E6               [12] 5246 	mov	a,@r0
      00198B 09               [12] 5247 	inc	r1
      00198C F7               [12] 5248 	mov	@r1,a
      00198D 08               [12] 5249 	inc	r0
      00198E E6               [12] 5250 	mov	a,@r0
      00198F 09               [12] 5251 	inc	r1
      001990 F7               [12] 5252 	mov	@r1,a
      001991 08               [12] 5253 	inc	r0
      001992 E6               [12] 5254 	mov	a,@r0
      001993 09               [12] 5255 	inc	r1
      001994 F7               [12] 5256 	mov	@r1,a
      001995                       5257 00108$:
      001995 E5 08            [12] 5258 	mov	a,_bp
      001997 24 05            [12] 5259 	add	a,#0x05
      001999 F8               [12] 5260 	mov	r0,a
      00199A 86 82            [24] 5261 	mov	dpl, @r0
      00199C 08               [12] 5262 	inc	r0
      00199D 86 83            [24] 5263 	mov	dph, @r0
      00199F 08               [12] 5264 	inc	r0
      0019A0 86 F0            [24] 5265 	mov	b, @r0
      0019A2 08               [12] 5266 	inc	r0
      0019A3 E6               [12] 5267 	mov	a, @r0
                           0018ED  5268 	C$fuzzy.h$2495$2_0$95 ==.
                                   5269 ;	../../fuzzy.h:2495: case FUZZY_IMPLICATION_PRODUCT:
      0019A4 80 38            [24] 5270 	sjmp	00105$
      0019A6                       5271 00102$:
                           0018EF  5272 	C$fuzzy.h$2496$1_0$94 ==.
                                   5273 ;	../../fuzzy.h:2496: return activation * membership;
      0019A6 A8 08            [24] 5274 	mov	r0,_bp
      0019A8 08               [12] 5275 	inc	r0
      0019A9 E6               [12] 5276 	mov	a,@r0
      0019AA C0 E0            [24] 5277 	push	acc
      0019AC 08               [12] 5278 	inc	r0
      0019AD E6               [12] 5279 	mov	a,@r0
      0019AE C0 E0            [24] 5280 	push	acc
      0019B0 08               [12] 5281 	inc	r0
      0019B1 E6               [12] 5282 	mov	a,@r0
      0019B2 C0 E0            [24] 5283 	push	acc
      0019B4 08               [12] 5284 	inc	r0
      0019B5 E6               [12] 5285 	mov	a,@r0
      0019B6 C0 E0            [24] 5286 	push	acc
      0019B8 8B 82            [24] 5287 	mov	dpl, r3
      0019BA 8C 83            [24] 5288 	mov	dph, r4
      0019BC 8D F0            [24] 5289 	mov	b, r5
      0019BE EE               [12] 5290 	mov	a, r6
      0019BF 12 34 92         [24] 5291 	lcall	___fsmul
      0019C2 AC 82            [24] 5292 	mov	r4, dpl
      0019C4 AD 83            [24] 5293 	mov	r5, dph
      0019C6 AE F0            [24] 5294 	mov	r6, b
      0019C8 FF               [12] 5295 	mov	r7, a
      0019C9 E5 81            [12] 5296 	mov	a,sp
      0019CB 24 FC            [12] 5297 	add	a,#0xfc
      0019CD F5 81            [12] 5298 	mov	sp,a
      0019CF 8C 82            [24] 5299 	mov	dpl, r4
      0019D1 8D 83            [24] 5300 	mov	dph, r5
      0019D3 8E F0            [24] 5301 	mov	b, r6
      0019D5 EF               [12] 5302 	mov	a, r7
                           00191F  5303 	C$fuzzy.h$2498$2_0$95 ==.
                                   5304 ;	../../fuzzy.h:2498: default:
      0019D6 80 06            [24] 5305 	sjmp	00105$
      0019D8                       5306 00103$:
                           001921  5307 	C$fuzzy.h$2499$2_0$95 ==.
                                   5308 ;	../../fuzzy.h:2499: return LEVEL_LO;
      0019D8 90 00 00         [24] 5309 	mov	dptr,#0x0000
      0019DB E4               [12] 5310 	clr	a
      0019DC F5 F0            [12] 5311 	mov	b,a
                           001927  5312 	C$fuzzy.h$2500$1_0$94 ==.
                                   5313 ;	../../fuzzy.h:2500: }
      0019DE                       5314 00105$:
                           001927  5315 	C$fuzzy.h$2501$1_0$94 ==.
                                   5316 ;	../../fuzzy.h:2501: }
      0019DE 85 08 81         [24] 5317 	mov	sp,_bp
      0019E1 D0 08            [24] 5318 	pop	_bp
                           00192C  5319 	C$fuzzy.h$2501$1_0$94 ==.
                           00192C  5320 	XFcontroller_8051$fuzzy_implication$0$0 ==.
      0019E3 22               [24] 5321 	ret
                                   5322 ;------------------------------------------------------------
                                   5323 ;Allocation info for local variables in function 'fuzzy_aggregation'
                                   5324 ;------------------------------------------------------------
                                   5325 ;aggregated    Allocated to stack - _bp -6 +4 
                                   5326 ;implied       Allocated to stack - _bp -10 +4 
                                   5327 ;method        Allocated to registers r7 
                                   5328 ;sloc0         Allocated to stack - _bp +1 +4 
                                   5329 ;sloc1         Allocated to stack - _bp +5 +4 
                                   5330 ;sloc2         Allocated to stack - _bp +10 +4 
                                   5331 ;------------------------------------------------------------
                           00192D  5332 	Fcontroller_8051$fuzzy_aggregation$0$0 ==.
                           00192D  5333 	C$fuzzy.h$2503$1_0$97 ==.
                                   5334 ;	../../fuzzy.h:2503: static float fuzzy_aggregation(
                                   5335 ;	-----------------------------------------
                                   5336 ;	 function fuzzy_aggregation
                                   5337 ;	-----------------------------------------
      0019E4                       5338 _fuzzy_aggregation:
      0019E4 C0 08            [24] 5339 	push	_bp
      0019E6 E5 81            [12] 5340 	mov	a,sp
      0019E8 F5 08            [12] 5341 	mov	_bp,a
      0019EA 24 08            [12] 5342 	add	a,#0x08
      0019EC F5 81            [12] 5343 	mov	sp,a
      0019EE AF 82            [24] 5344 	mov	r7, dpl
                           001939  5345 	C$fuzzy.h$2509$1_0$97 ==.
                                   5346 ;	../../fuzzy.h:2509: aggregated = fuzzy_clamp(aggregated);
      0019F0 E5 08            [12] 5347 	mov	a,_bp
      0019F2 24 FA            [12] 5348 	add	a,#0xfa
      0019F4 F8               [12] 5349 	mov	r0,a
      0019F5 86 82            [24] 5350 	mov	dpl, @r0
      0019F7 08               [12] 5351 	inc	r0
      0019F8 86 83            [24] 5352 	mov	dph, @r0
      0019FA 08               [12] 5353 	inc	r0
      0019FB 86 F0            [24] 5354 	mov	b, @r0
      0019FD 08               [12] 5355 	inc	r0
      0019FE E6               [12] 5356 	mov	a, @r0
      0019FF C0 07            [24] 5357 	push	ar7
      001A01 12 00 EA         [24] 5358 	lcall	_fuzzy_clamp
      001A04 AE 82            [24] 5359 	mov	r6, dpl
      001A06 AD 83            [24] 5360 	mov	r5, dph
      001A08 AC F0            [24] 5361 	mov	r4, b
      001A0A FB               [12] 5362 	mov	r3, a
                           001954  5363 	C$fuzzy.h$2510$1_0$97 ==.
                                   5364 ;	../../fuzzy.h:2510: implied = fuzzy_clamp(implied);
      001A0B E5 08            [12] 5365 	mov	a,_bp
      001A0D 24 F6            [12] 5366 	add	a,#0xf6
      001A0F F8               [12] 5367 	mov	r0,a
      001A10 86 82            [24] 5368 	mov	dpl, @r0
      001A12 08               [12] 5369 	inc	r0
      001A13 86 83            [24] 5370 	mov	dph, @r0
      001A15 08               [12] 5371 	inc	r0
      001A16 86 F0            [24] 5372 	mov	b, @r0
      001A18 08               [12] 5373 	inc	r0
      001A19 E6               [12] 5374 	mov	a, @r0
      001A1A C0 06            [24] 5375 	push	ar6
      001A1C C0 05            [24] 5376 	push	ar5
      001A1E C0 04            [24] 5377 	push	ar4
      001A20 C0 03            [24] 5378 	push	ar3
      001A22 12 00 EA         [24] 5379 	lcall	_fuzzy_clamp
      001A25 A8 08            [24] 5380 	mov	r0,_bp
      001A27 08               [12] 5381 	inc	r0
      001A28 A6 82            [24] 5382 	mov	@r0, dpl
      001A2A 08               [12] 5383 	inc	r0
      001A2B A6 83            [24] 5384 	mov	@r0, dph
      001A2D 08               [12] 5385 	inc	r0
      001A2E A6 F0            [24] 5386 	mov	@r0, b
      001A30 08               [12] 5387 	inc	r0
      001A31 F6               [12] 5388 	mov	@r0,a
      001A32 D0 03            [24] 5389 	pop	ar3
      001A34 D0 04            [24] 5390 	pop	ar4
      001A36 D0 05            [24] 5391 	pop	ar5
      001A38 D0 06            [24] 5392 	pop	ar6
      001A3A D0 07            [24] 5393 	pop	ar7
                           001985  5394 	C$fuzzy.h$2512$1_0$97 ==.
                                   5395 ;	../../fuzzy.h:2512: switch (method) {
      001A3C BF 00 02         [24] 5396 	cjne	r7,#0x00,00134$
      001A3F 80 0E            [24] 5397 	sjmp	00101$
      001A41                       5398 00134$:
      001A41 BF 01 02         [24] 5399 	cjne	r7,#0x01,00135$
      001A44 80 76            [24] 5400 	sjmp	00102$
      001A46                       5401 00135$:
      001A46 BF 02 03         [24] 5402 	cjne	r7,#0x02,00136$
      001A49 02 1B 57         [24] 5403 	ljmp	00103$
      001A4C                       5404 00136$:
      001A4C 02 1B 8C         [24] 5405 	ljmp	00104$
                           001998  5406 	C$fuzzy.h$2513$2_0$98 ==.
                                   5407 ;	../../fuzzy.h:2513: case FUZZY_AGGREGATION_MAX:
      001A4F                       5408 00101$:
                           001998  5409 	C$fuzzy.h$2515$1_0$97 ==.
                                   5410 ;	../../fuzzy.h:2515: ? aggregated
      001A4F C0 06            [24] 5411 	push	ar6
      001A51 C0 05            [24] 5412 	push	ar5
      001A53 C0 04            [24] 5413 	push	ar4
      001A55 C0 03            [24] 5414 	push	ar3
      001A57 C0 06            [24] 5415 	push	ar6
      001A59 C0 05            [24] 5416 	push	ar5
      001A5B C0 04            [24] 5417 	push	ar4
      001A5D C0 03            [24] 5418 	push	ar3
      001A5F A8 08            [24] 5419 	mov	r0,_bp
      001A61 08               [12] 5420 	inc	r0
      001A62 86 82            [24] 5421 	mov	dpl, @r0
      001A64 08               [12] 5422 	inc	r0
      001A65 86 83            [24] 5423 	mov	dph, @r0
      001A67 08               [12] 5424 	inc	r0
      001A68 86 F0            [24] 5425 	mov	b, @r0
      001A6A 08               [12] 5426 	inc	r0
      001A6B E6               [12] 5427 	mov	a, @r0
      001A6C 12 35 C2         [24] 5428 	lcall	___fslt
      001A6F AF 82            [24] 5429 	mov	r7, dpl
      001A71 E5 81            [12] 5430 	mov	a,sp
      001A73 24 FC            [12] 5431 	add	a,#0xfc
      001A75 F5 81            [12] 5432 	mov	sp,a
      001A77 D0 03            [24] 5433 	pop	ar3
      001A79 D0 04            [24] 5434 	pop	ar4
      001A7B D0 05            [24] 5435 	pop	ar5
      001A7D D0 06            [24] 5436 	pop	ar6
      001A7F EF               [12] 5437 	mov	a,r7
      001A80 60 12            [24] 5438 	jz	00108$
      001A82 E5 08            [12] 5439 	mov	a,_bp
      001A84 24 05            [12] 5440 	add	a,#0x05
      001A86 F8               [12] 5441 	mov	r0,a
      001A87 A6 06            [24] 5442 	mov	@r0,ar6
      001A89 08               [12] 5443 	inc	r0
      001A8A A6 05            [24] 5444 	mov	@r0,ar5
      001A8C 08               [12] 5445 	inc	r0
      001A8D A6 04            [24] 5446 	mov	@r0,ar4
      001A8F 08               [12] 5447 	inc	r0
      001A90 A6 03            [24] 5448 	mov	@r0,ar3
      001A92 80 16            [24] 5449 	sjmp	00109$
      001A94                       5450 00108$:
                           0019DD  5451 	C$fuzzy.h$2516$2_0$98 ==.
                                   5452 ;	../../fuzzy.h:2516: : implied;
      001A94 A8 08            [24] 5453 	mov	r0,_bp
      001A96 08               [12] 5454 	inc	r0
      001A97 E5 08            [12] 5455 	mov	a,_bp
      001A99 24 05            [12] 5456 	add	a,#0x05
      001A9B F9               [12] 5457 	mov	r1,a
      001A9C E6               [12] 5458 	mov	a,@r0
      001A9D F7               [12] 5459 	mov	@r1,a
      001A9E 08               [12] 5460 	inc	r0
      001A9F E6               [12] 5461 	mov	a,@r0
      001AA0 09               [12] 5462 	inc	r1
      001AA1 F7               [12] 5463 	mov	@r1,a
      001AA2 08               [12] 5464 	inc	r0
      001AA3 E6               [12] 5465 	mov	a,@r0
      001AA4 09               [12] 5466 	inc	r1
      001AA5 F7               [12] 5467 	mov	@r1,a
      001AA6 08               [12] 5468 	inc	r0
      001AA7 E6               [12] 5469 	mov	a,@r0
      001AA8 09               [12] 5470 	inc	r1
      001AA9 F7               [12] 5471 	mov	@r1,a
      001AAA                       5472 00109$:
      001AAA E5 08            [12] 5473 	mov	a,_bp
      001AAC 24 05            [12] 5474 	add	a,#0x05
      001AAE F8               [12] 5475 	mov	r0,a
      001AAF 86 82            [24] 5476 	mov	dpl, @r0
      001AB1 08               [12] 5477 	inc	r0
      001AB2 86 83            [24] 5478 	mov	dph, @r0
      001AB4 08               [12] 5479 	inc	r0
      001AB5 86 F0            [24] 5480 	mov	b, @r0
      001AB7 08               [12] 5481 	inc	r0
      001AB8 E6               [12] 5482 	mov	a, @r0
      001AB9 02 1B 92         [24] 5483 	ljmp	00106$
                           001A05  5484 	C$fuzzy.h$2518$2_0$98 ==.
                                   5485 ;	../../fuzzy.h:2518: case FUZZY_AGGREGATION_ALGEBRAIC:
      001ABC                       5486 00102$:
                           001A05  5487 	C$fuzzy.h$2520$1_0$97 ==.
                                   5488 ;	../../fuzzy.h:2520: implied -
      001ABC C0 06            [24] 5489 	push	ar6
      001ABE C0 05            [24] 5490 	push	ar5
      001AC0 C0 04            [24] 5491 	push	ar4
      001AC2 C0 03            [24] 5492 	push	ar3
      001AC4 A8 08            [24] 5493 	mov	r0,_bp
      001AC6 08               [12] 5494 	inc	r0
      001AC7 E6               [12] 5495 	mov	a,@r0
      001AC8 C0 E0            [24] 5496 	push	acc
      001ACA 08               [12] 5497 	inc	r0
      001ACB E6               [12] 5498 	mov	a,@r0
      001ACC C0 E0            [24] 5499 	push	acc
      001ACE 08               [12] 5500 	inc	r0
      001ACF E6               [12] 5501 	mov	a,@r0
      001AD0 C0 E0            [24] 5502 	push	acc
      001AD2 08               [12] 5503 	inc	r0
      001AD3 E6               [12] 5504 	mov	a,@r0
      001AD4 C0 E0            [24] 5505 	push	acc
                           001A1F  5506 	C$fuzzy.h$2521$1_0$97 ==.
                                   5507 ;	../../fuzzy.h:2521: aggregated * implied;
      001AD6 8E 82            [24] 5508 	mov	dpl, r6
      001AD8 8D 83            [24] 5509 	mov	dph, r5
      001ADA 8C F0            [24] 5510 	mov	b, r4
      001ADC EB               [12] 5511 	mov	a, r3
      001ADD 12 36 14         [24] 5512 	lcall	___fsadd
      001AE0 C8               [12] 5513 	xch	a,r0
      001AE1 E5 08            [12] 5514 	mov	a,_bp
      001AE3 24 05            [12] 5515 	add	a,#0x05
      001AE5 C8               [12] 5516 	xch	a,r0
      001AE6 A6 82            [24] 5517 	mov	@r0, dpl
      001AE8 08               [12] 5518 	inc	r0
      001AE9 A6 83            [24] 5519 	mov	@r0, dph
      001AEB 08               [12] 5520 	inc	r0
      001AEC A6 F0            [24] 5521 	mov	@r0, b
      001AEE 08               [12] 5522 	inc	r0
      001AEF F6               [12] 5523 	mov	@r0,a
      001AF0 E5 81            [12] 5524 	mov	a,sp
      001AF2 24 FC            [12] 5525 	add	a,#0xfc
      001AF4 F5 81            [12] 5526 	mov	sp,a
      001AF6 D0 03            [24] 5527 	pop	ar3
      001AF8 D0 04            [24] 5528 	pop	ar4
      001AFA D0 05            [24] 5529 	pop	ar5
      001AFC D0 06            [24] 5530 	pop	ar6
      001AFE A8 08            [24] 5531 	mov	r0,_bp
      001B00 08               [12] 5532 	inc	r0
      001B01 E6               [12] 5533 	mov	a,@r0
      001B02 C0 E0            [24] 5534 	push	acc
      001B04 08               [12] 5535 	inc	r0
      001B05 E6               [12] 5536 	mov	a,@r0
      001B06 C0 E0            [24] 5537 	push	acc
      001B08 08               [12] 5538 	inc	r0
      001B09 E6               [12] 5539 	mov	a,@r0
      001B0A C0 E0            [24] 5540 	push	acc
      001B0C 08               [12] 5541 	inc	r0
      001B0D E6               [12] 5542 	mov	a,@r0
      001B0E C0 E0            [24] 5543 	push	acc
      001B10 8E 82            [24] 5544 	mov	dpl, r6
      001B12 8D 83            [24] 5545 	mov	dph, r5
      001B14 8C F0            [24] 5546 	mov	b, r4
      001B16 EB               [12] 5547 	mov	a, r3
      001B17 12 34 92         [24] 5548 	lcall	___fsmul
      001B1A AB 82            [24] 5549 	mov	r3, dpl
      001B1C AC 83            [24] 5550 	mov	r4, dph
      001B1E AE F0            [24] 5551 	mov	r6, b
      001B20 FF               [12] 5552 	mov	r7, a
      001B21 E5 81            [12] 5553 	mov	a,sp
      001B23 24 FC            [12] 5554 	add	a,#0xfc
      001B25 F5 81            [12] 5555 	mov	sp,a
      001B27 C0 03            [24] 5556 	push	ar3
      001B29 C0 04            [24] 5557 	push	ar4
      001B2B C0 06            [24] 5558 	push	ar6
      001B2D C0 07            [24] 5559 	push	ar7
      001B2F E5 08            [12] 5560 	mov	a,_bp
      001B31 24 05            [12] 5561 	add	a,#0x05
      001B33 F8               [12] 5562 	mov	r0,a
      001B34 86 82            [24] 5563 	mov	dpl, @r0
      001B36 08               [12] 5564 	inc	r0
      001B37 86 83            [24] 5565 	mov	dph, @r0
      001B39 08               [12] 5566 	inc	r0
      001B3A 86 F0            [24] 5567 	mov	b, @r0
      001B3C 08               [12] 5568 	inc	r0
      001B3D E6               [12] 5569 	mov	a, @r0
      001B3E 12 34 87         [24] 5570 	lcall	___fssub
      001B41 AC 82            [24] 5571 	mov	r4, dpl
      001B43 AD 83            [24] 5572 	mov	r5, dph
      001B45 AE F0            [24] 5573 	mov	r6, b
      001B47 FF               [12] 5574 	mov	r7, a
      001B48 E5 81            [12] 5575 	mov	a,sp
      001B4A 24 FC            [12] 5576 	add	a,#0xfc
      001B4C F5 81            [12] 5577 	mov	sp,a
      001B4E 8C 82            [24] 5578 	mov	dpl, r4
      001B50 8D 83            [24] 5579 	mov	dph, r5
      001B52 8E F0            [24] 5580 	mov	b, r6
      001B54 EF               [12] 5581 	mov	a, r7
                           001A9E  5582 	C$fuzzy.h$2523$2_0$98 ==.
                                   5583 ;	../../fuzzy.h:2523: case FUZZY_AGGREGATION_BOUNDED:
      001B55 80 3B            [24] 5584 	sjmp	00106$
      001B57                       5585 00103$:
                           001AA0  5586 	C$fuzzy.h$2527$1_0$97 ==.
                                   5587 ;	../../fuzzy.h:2527: );
      001B57 A8 08            [24] 5588 	mov	r0,_bp
      001B59 08               [12] 5589 	inc	r0
      001B5A E6               [12] 5590 	mov	a,@r0
      001B5B C0 E0            [24] 5591 	push	acc
      001B5D 08               [12] 5592 	inc	r0
      001B5E E6               [12] 5593 	mov	a,@r0
      001B5F C0 E0            [24] 5594 	push	acc
      001B61 08               [12] 5595 	inc	r0
      001B62 E6               [12] 5596 	mov	a,@r0
      001B63 C0 E0            [24] 5597 	push	acc
      001B65 08               [12] 5598 	inc	r0
      001B66 E6               [12] 5599 	mov	a,@r0
      001B67 C0 E0            [24] 5600 	push	acc
      001B69 8E 82            [24] 5601 	mov	dpl, r6
      001B6B 8D 83            [24] 5602 	mov	dph, r5
      001B6D 8C F0            [24] 5603 	mov	b, r4
      001B6F EB               [12] 5604 	mov	a, r3
      001B70 12 36 14         [24] 5605 	lcall	___fsadd
      001B73 AC 82            [24] 5606 	mov	r4, dpl
      001B75 AD 83            [24] 5607 	mov	r5, dph
      001B77 AE F0            [24] 5608 	mov	r6, b
      001B79 FF               [12] 5609 	mov	r7, a
      001B7A E5 81            [12] 5610 	mov	a,sp
      001B7C 24 FC            [12] 5611 	add	a,#0xfc
      001B7E F5 81            [12] 5612 	mov	sp,a
      001B80 8C 82            [24] 5613 	mov	dpl, r4
      001B82 8D 83            [24] 5614 	mov	dph, r5
      001B84 8E F0            [24] 5615 	mov	b, r6
      001B86 EF               [12] 5616 	mov	a, r7
      001B87 12 00 EA         [24] 5617 	lcall	_fuzzy_clamp
                           001AD3  5618 	C$fuzzy.h$2529$2_0$98 ==.
                                   5619 ;	../../fuzzy.h:2529: default:
      001B8A 80 06            [24] 5620 	sjmp	00106$
      001B8C                       5621 00104$:
                           001AD5  5622 	C$fuzzy.h$2530$2_0$98 ==.
                                   5623 ;	../../fuzzy.h:2530: return LEVEL_LO;
      001B8C 90 00 00         [24] 5624 	mov	dptr,#0x0000
      001B8F E4               [12] 5625 	clr	a
      001B90 F5 F0            [12] 5626 	mov	b,a
                           001ADB  5627 	C$fuzzy.h$2531$1_0$97 ==.
                                   5628 ;	../../fuzzy.h:2531: }
      001B92                       5629 00106$:
                           001ADB  5630 	C$fuzzy.h$2532$1_0$97 ==.
                                   5631 ;	../../fuzzy.h:2532: }
      001B92 85 08 81         [24] 5632 	mov	sp,_bp
      001B95 D0 08            [24] 5633 	pop	_bp
                           001AE0  5634 	C$fuzzy.h$2532$1_0$97 ==.
                           001AE0  5635 	XFcontroller_8051$fuzzy_aggregation$0$0 ==.
      001B97 22               [24] 5636 	ret
                                   5637 ;------------------------------------------------------------
                                   5638 ;Allocation info for local variables in function 'fuzzy_rules_aggregated_height'
                                   5639 ;------------------------------------------------------------
                                   5640 ;value         Allocated to stack - _bp -6 +4 
                                   5641 ;implication_method Allocated to stack - _bp -7 +1 
                                   5642 ;aggregation_method Allocated to stack - _bp -8 +1 
                                   5643 ;rules         Allocated to stack - _bp +1 +3 
                                   5644 ;aggregated_height Allocated to stack - _bp +12 +4 
                                   5645 ;output_membership Allocated to stack - _bp +16 +4 
                                   5646 ;implied_height Allocated to registers r4 r5 r6 r7 
                                   5647 ;index         Allocated to stack - _bp +20 +2 
                                   5648 ;sloc0         Allocated to stack - _bp +4 +3 
                                   5649 ;sloc1         Allocated to stack - _bp +7 +2 
                                   5650 ;sloc2         Allocated to stack - _bp +9 +3 
                                   5651 ;------------------------------------------------------------
                           001AE1  5652 	Fcontroller_8051$fuzzy_rules_aggregated_height$0$0 ==.
                           001AE1  5653 	C$fuzzy.h$2538$1_0$100 ==.
                                   5654 ;	../../fuzzy.h:2538: static float fuzzy_rules_aggregated_height(
                                   5655 ;	-----------------------------------------
                                   5656 ;	 function fuzzy_rules_aggregated_height
                                   5657 ;	-----------------------------------------
      001B98                       5658 _fuzzy_rules_aggregated_height:
      001B98 C0 08            [24] 5659 	push	_bp
      001B9A 85 81 08         [24] 5660 	mov	_bp,sp
      001B9D C0 82            [24] 5661 	push	dpl
      001B9F C0 83            [24] 5662 	push	dph
      001BA1 C0 F0            [24] 5663 	push	b
      001BA3 E5 81            [12] 5664 	mov	a,sp
      001BA5 24 12            [12] 5665 	add	a,#0x12
      001BA7 F5 81            [12] 5666 	mov	sp,a
                           001AF2  5667 	C$fuzzy.h$2551$1_0$100 ==.
                                   5668 ;	../../fuzzy.h:2551: LEVEL_LO;
      001BA9 E5 08            [12] 5669 	mov	a,_bp
      001BAB 24 0C            [12] 5670 	add	a,#0x0c
      001BAD F8               [12] 5671 	mov	r0,a
      001BAE E4               [12] 5672 	clr	a
      001BAF F6               [12] 5673 	mov	@r0,a
      001BB0 08               [12] 5674 	inc	r0
      001BB1 F6               [12] 5675 	mov	@r0,a
      001BB2 08               [12] 5676 	inc	r0
      001BB3 F6               [12] 5677 	mov	@r0,a
      001BB4 08               [12] 5678 	inc	r0
      001BB5 F6               [12] 5679 	mov	@r0,a
                           001AFF  5680 	C$fuzzy.h$2554$3_0$102 ==.
                                   5681 ;	../../fuzzy.h:2554: index = 0u;
      001BB6 A8 08            [24] 5682 	mov	r0,_bp
      001BB8 08               [12] 5683 	inc	r0
      001BB9 E5 08            [12] 5684 	mov	a,_bp
      001BBB 24 09            [12] 5685 	add	a,#0x09
      001BBD F9               [12] 5686 	mov	r1,a
      001BBE E6               [12] 5687 	mov	a,@r0
      001BBF F7               [12] 5688 	mov	@r1,a
      001BC0 08               [12] 5689 	inc	r0
      001BC1 E6               [12] 5690 	mov	a,@r0
      001BC2 09               [12] 5691 	inc	r1
      001BC3 F7               [12] 5692 	mov	@r1,a
      001BC4 08               [12] 5693 	inc	r0
      001BC5 E6               [12] 5694 	mov	a,@r0
      001BC6 09               [12] 5695 	inc	r1
      001BC7 F7               [12] 5696 	mov	@r1,a
      001BC8 A8 08            [24] 5697 	mov	r0,_bp
      001BCA 08               [12] 5698 	inc	r0
      001BCB E5 08            [12] 5699 	mov	a,_bp
      001BCD 24 04            [12] 5700 	add	a,#0x04
      001BCF F9               [12] 5701 	mov	r1,a
      001BD0 74 90            [12] 5702 	mov	a,#0x90
      001BD2 26               [12] 5703 	add	a, @r0
      001BD3 F7               [12] 5704 	mov	@r1,a
      001BD4 E4               [12] 5705 	clr	a
      001BD5 08               [12] 5706 	inc	r0
      001BD6 36               [12] 5707 	addc	a, @r0
      001BD7 09               [12] 5708 	inc	r1
      001BD8 F7               [12] 5709 	mov	@r1,a
      001BD9 08               [12] 5710 	inc	r0
      001BDA E6               [12] 5711 	mov	a,@r0
      001BDB 09               [12] 5712 	inc	r1
      001BDC F7               [12] 5713 	mov	@r1,a
      001BDD E5 08            [12] 5714 	mov	a,_bp
      001BDF 24 14            [12] 5715 	add	a,#0x14
      001BE1 F8               [12] 5716 	mov	r0,a
      001BE2 E4               [12] 5717 	clr	a
      001BE3 F6               [12] 5718 	mov	@r0,a
      001BE4 08               [12] 5719 	inc	r0
      001BE5 F6               [12] 5720 	mov	@r0,a
      001BE6 E5 08            [12] 5721 	mov	a,_bp
      001BE8 24 07            [12] 5722 	add	a,#0x07
      001BEA F8               [12] 5723 	mov	r0,a
      001BEB E4               [12] 5724 	clr	a
      001BEC F6               [12] 5725 	mov	@r0,a
      001BED 08               [12] 5726 	inc	r0
      001BEE F6               [12] 5727 	mov	@r0,a
      001BEF                       5728 00103$:
                           001B38  5729 	C$fuzzy.h$2555$1_0$100 ==.
                                   5730 ;	../../fuzzy.h:2555: index < rules->count;
      001BEF E5 08            [12] 5731 	mov	a,_bp
      001BF1 24 04            [12] 5732 	add	a,#0x04
      001BF3 F8               [12] 5733 	mov	r0,a
      001BF4 86 82            [24] 5734 	mov	dpl,@r0
      001BF6 08               [12] 5735 	inc	r0
      001BF7 86 83            [24] 5736 	mov	dph,@r0
      001BF9 08               [12] 5737 	inc	r0
      001BFA 86 F0            [24] 5738 	mov	b,@r0
      001BFC 12 37 EE         [24] 5739 	lcall	__gptrget
      001BFF FC               [12] 5740 	mov	r4,a
      001C00 A3               [24] 5741 	inc	dptr
      001C01 12 37 EE         [24] 5742 	lcall	__gptrget
      001C04 FD               [12] 5743 	mov	r5,a
      001C05 E5 08            [12] 5744 	mov	a,_bp
      001C07 24 14            [12] 5745 	add	a,#0x14
      001C09 F8               [12] 5746 	mov	r0,a
      001C0A C3               [12] 5747 	clr	c
      001C0B E6               [12] 5748 	mov	a,@r0
      001C0C 9C               [12] 5749 	subb	a,r4
      001C0D 08               [12] 5750 	inc	r0
      001C0E E6               [12] 5751 	mov	a,@r0
      001C0F 9D               [12] 5752 	subb	a,r5
      001C10 40 03            [24] 5753 	jc	00120$
      001C12 02 1D 29         [24] 5754 	ljmp	00101$
      001C15                       5755 00120$:
                           001B5E  5756 	C$fuzzy.h$2560$3_0$102 ==.
                                   5757 ;	../../fuzzy.h:2560: rules->rules[index]
      001C15 E5 08            [12] 5758 	mov	a,_bp
      001C17 24 09            [12] 5759 	add	a,#0x09
      001C19 F8               [12] 5760 	mov	r0,a
      001C1A E5 08            [12] 5761 	mov	a,_bp
      001C1C 24 07            [12] 5762 	add	a,#0x07
      001C1E F9               [12] 5763 	mov	r1,a
      001C1F E7               [12] 5764 	mov	a,@r1
      001C20 26               [12] 5765 	add	a, @r0
      001C21 FD               [12] 5766 	mov	r5,a
      001C22 09               [12] 5767 	inc	r1
      001C23 E7               [12] 5768 	mov	a,@r1
      001C24 08               [12] 5769 	inc	r0
      001C25 36               [12] 5770 	addc	a, @r0
      001C26 FE               [12] 5771 	mov	r6,a
      001C27 08               [12] 5772 	inc	r0
      001C28 86 07            [24] 5773 	mov	ar7,@r0
      001C2A 74 07            [12] 5774 	mov	a,#0x07
      001C2C 2D               [12] 5775 	add	a, r5
      001C2D FD               [12] 5776 	mov	r5,a
      001C2E E4               [12] 5777 	clr	a
      001C2F 3E               [12] 5778 	addc	a, r6
      001C30 FE               [12] 5779 	mov	r6,a
      001C31 8D 82            [24] 5780 	mov	dpl,r5
      001C33 8E 83            [24] 5781 	mov	dph,r6
      001C35 8F F0            [24] 5782 	mov	b,r7
      001C37 12 37 EE         [24] 5783 	lcall	__gptrget
      001C3A FD               [12] 5784 	mov	r5,a
      001C3B A3               [24] 5785 	inc	dptr
      001C3C 12 37 EE         [24] 5786 	lcall	__gptrget
      001C3F FE               [12] 5787 	mov	r6,a
                           001B89  5788 	C$fuzzy.h$2561$3_0$102 ==.
                                   5789 ;	../../fuzzy.h:2561: .output_function(value)
      001C40 12 1C 45         [24] 5790 	lcall	00121$
      001C43 80 14            [24] 5791 	sjmp	00122$
      001C45                       5792 00121$:
      001C45 C0 05            [24] 5793 	push	ar5
      001C47 C0 06            [24] 5794 	push	ar6
      001C49 E5 08            [12] 5795 	mov	a,_bp
      001C4B 24 FA            [12] 5796 	add	a,#0xfa
      001C4D F8               [12] 5797 	mov	r0,a
      001C4E 86 82            [24] 5798 	mov	dpl, @r0
      001C50 08               [12] 5799 	inc	r0
      001C51 86 83            [24] 5800 	mov	dph, @r0
      001C53 08               [12] 5801 	inc	r0
      001C54 86 F0            [24] 5802 	mov	b, @r0
      001C56 08               [12] 5803 	inc	r0
      001C57 E6               [12] 5804 	mov	a, @r0
      001C58 22               [24] 5805 	ret
      001C59                       5806 00122$:
      001C59 12 00 EA         [24] 5807 	lcall	_fuzzy_clamp
      001C5C C8               [12] 5808 	xch	a,r0
      001C5D E5 08            [12] 5809 	mov	a,_bp
      001C5F 24 10            [12] 5810 	add	a,#0x10
      001C61 C8               [12] 5811 	xch	a,r0
      001C62 A6 82            [24] 5812 	mov	@r0, dpl
      001C64 08               [12] 5813 	inc	r0
      001C65 A6 83            [24] 5814 	mov	@r0, dph
      001C67 08               [12] 5815 	inc	r0
      001C68 A6 F0            [24] 5816 	mov	@r0, b
      001C6A 08               [12] 5817 	inc	r0
      001C6B F6               [12] 5818 	mov	@r0,a
                           001BB5  5819 	C$fuzzy.h$2567$3_0$102 ==.
                                   5820 ;	../../fuzzy.h:2567: rules->rules[index].value,
      001C6C A8 08            [24] 5821 	mov	r0,_bp
      001C6E 08               [12] 5822 	inc	r0
      001C6F E5 08            [12] 5823 	mov	a,_bp
      001C71 24 07            [12] 5824 	add	a,#0x07
      001C73 F9               [12] 5825 	mov	r1,a
      001C74 E7               [12] 5826 	mov	a,@r1
      001C75 26               [12] 5827 	add	a, @r0
      001C76 FA               [12] 5828 	mov	r2,a
      001C77 09               [12] 5829 	inc	r1
      001C78 E7               [12] 5830 	mov	a,@r1
      001C79 08               [12] 5831 	inc	r0
      001C7A 36               [12] 5832 	addc	a, @r0
      001C7B FB               [12] 5833 	mov	r3,a
      001C7C 08               [12] 5834 	inc	r0
      001C7D 86 07            [24] 5835 	mov	ar7,@r0
      001C7F 74 03            [12] 5836 	mov	a,#0x03
      001C81 2A               [12] 5837 	add	a, r2
      001C82 FA               [12] 5838 	mov	r2,a
      001C83 E4               [12] 5839 	clr	a
      001C84 3B               [12] 5840 	addc	a, r3
      001C85 FB               [12] 5841 	mov	r3,a
      001C86 8A 82            [24] 5842 	mov	dpl,r2
      001C88 8B 83            [24] 5843 	mov	dph,r3
      001C8A 8F F0            [24] 5844 	mov	b,r7
      001C8C 12 37 EE         [24] 5845 	lcall	__gptrget
      001C8F FA               [12] 5846 	mov	r2,a
      001C90 A3               [24] 5847 	inc	dptr
      001C91 12 37 EE         [24] 5848 	lcall	__gptrget
      001C94 FB               [12] 5849 	mov	r3,a
      001C95 A3               [24] 5850 	inc	dptr
      001C96 12 37 EE         [24] 5851 	lcall	__gptrget
      001C99 FF               [12] 5852 	mov	r7,a
      001C9A A3               [24] 5853 	inc	dptr
      001C9B 12 37 EE         [24] 5854 	lcall	__gptrget
      001C9E FE               [12] 5855 	mov	r6,a
                           001BE8  5856 	C$fuzzy.h$2566$3_0$102 ==.
                                   5857 ;	../../fuzzy.h:2566: implication_method,
      001C9F E5 08            [12] 5858 	mov	a,_bp
      001CA1 24 10            [12] 5859 	add	a,#0x10
      001CA3 F8               [12] 5860 	mov	r0,a
      001CA4 E6               [12] 5861 	mov	a,@r0
      001CA5 C0 E0            [24] 5862 	push	acc
      001CA7 08               [12] 5863 	inc	r0
      001CA8 E6               [12] 5864 	mov	a,@r0
      001CA9 C0 E0            [24] 5865 	push	acc
      001CAB 08               [12] 5866 	inc	r0
      001CAC E6               [12] 5867 	mov	a,@r0
      001CAD C0 E0            [24] 5868 	push	acc
      001CAF 08               [12] 5869 	inc	r0
      001CB0 E6               [12] 5870 	mov	a,@r0
      001CB1 C0 E0            [24] 5871 	push	acc
      001CB3 C0 02            [24] 5872 	push	ar2
      001CB5 C0 03            [24] 5873 	push	ar3
      001CB7 C0 07            [24] 5874 	push	ar7
      001CB9 C0 06            [24] 5875 	push	ar6
      001CBB E5 08            [12] 5876 	mov	a,_bp
      001CBD 24 F9            [12] 5877 	add	a,#0xf9
      001CBF F8               [12] 5878 	mov	r0,a
      001CC0 86 82            [24] 5879 	mov	dpl, @r0
      001CC2 12 18 D1         [24] 5880 	lcall	_fuzzy_implication
      001CC5 AC 82            [24] 5881 	mov	r4, dpl
      001CC7 AD 83            [24] 5882 	mov	r5, dph
      001CC9 AE F0            [24] 5883 	mov	r6, b
      001CCB FF               [12] 5884 	mov	r7, a
      001CCC E5 81            [12] 5885 	mov	a,sp
      001CCE 24 F8            [12] 5886 	add	a,#0xf8
      001CD0 F5 81            [12] 5887 	mov	sp,a
                           001C1B  5888 	C$fuzzy.h$2573$3_0$102 ==.
                                   5889 ;	../../fuzzy.h:2573: aggregation_method,
      001CD2 C0 04            [24] 5890 	push	ar4
      001CD4 C0 05            [24] 5891 	push	ar5
      001CD6 C0 06            [24] 5892 	push	ar6
      001CD8 C0 07            [24] 5893 	push	ar7
      001CDA E5 08            [12] 5894 	mov	a,_bp
      001CDC 24 0C            [12] 5895 	add	a,#0x0c
      001CDE F8               [12] 5896 	mov	r0,a
      001CDF E6               [12] 5897 	mov	a,@r0
      001CE0 C0 E0            [24] 5898 	push	acc
      001CE2 08               [12] 5899 	inc	r0
      001CE3 E6               [12] 5900 	mov	a,@r0
      001CE4 C0 E0            [24] 5901 	push	acc
      001CE6 08               [12] 5902 	inc	r0
      001CE7 E6               [12] 5903 	mov	a,@r0
      001CE8 C0 E0            [24] 5904 	push	acc
      001CEA 08               [12] 5905 	inc	r0
      001CEB E6               [12] 5906 	mov	a,@r0
      001CEC C0 E0            [24] 5907 	push	acc
      001CEE E5 08            [12] 5908 	mov	a,_bp
      001CF0 24 F8            [12] 5909 	add	a,#0xf8
      001CF2 F8               [12] 5910 	mov	r0,a
      001CF3 86 82            [24] 5911 	mov	dpl, @r0
      001CF5 12 19 E4         [24] 5912 	lcall	_fuzzy_aggregation
      001CF8 C8               [12] 5913 	xch	a,r0
      001CF9 E5 08            [12] 5914 	mov	a,_bp
      001CFB 24 0C            [12] 5915 	add	a,#0x0c
      001CFD C8               [12] 5916 	xch	a,r0
      001CFE A6 82            [24] 5917 	mov	@r0, dpl
      001D00 08               [12] 5918 	inc	r0
      001D01 A6 83            [24] 5919 	mov	@r0, dph
      001D03 08               [12] 5920 	inc	r0
      001D04 A6 F0            [24] 5921 	mov	@r0, b
      001D06 08               [12] 5922 	inc	r0
      001D07 F6               [12] 5923 	mov	@r0,a
      001D08 E5 81            [12] 5924 	mov	a,sp
      001D0A 24 F8            [12] 5925 	add	a,#0xf8
      001D0C F5 81            [12] 5926 	mov	sp,a
                           001C57  5927 	C$fuzzy.h$2556$1_0$100 ==.
                                   5928 ;	../../fuzzy.h:2556: index++
      001D0E E5 08            [12] 5929 	mov	a,_bp
      001D10 24 07            [12] 5930 	add	a,#0x07
      001D12 F8               [12] 5931 	mov	r0,a
      001D13 74 09            [12] 5932 	mov	a,#0x09
      001D15 26               [12] 5933 	add	a, @r0
      001D16 F6               [12] 5934 	mov	@r0,a
      001D17 E4               [12] 5935 	clr	a
      001D18 08               [12] 5936 	inc	r0
      001D19 36               [12] 5937 	addc	a, @r0
      001D1A F6               [12] 5938 	mov	@r0,a
      001D1B E5 08            [12] 5939 	mov	a,_bp
      001D1D 24 14            [12] 5940 	add	a,#0x14
      001D1F F8               [12] 5941 	mov	r0,a
      001D20 06               [12] 5942 	inc	@r0
      001D21 B6 00 02         [24] 5943 	cjne	@r0,#0x00,00123$
      001D24 08               [12] 5944 	inc	r0
      001D25 06               [12] 5945 	inc	@r0
      001D26                       5946 00123$:
      001D26 02 1B EF         [24] 5947 	ljmp	00103$
      001D29                       5948 00101$:
                           001C72  5949 	C$fuzzy.h$2580$1_0$100 ==.
                                   5950 ;	../../fuzzy.h:2580: aggregated_height
      001D29 E5 08            [12] 5951 	mov	a,_bp
      001D2B 24 0C            [12] 5952 	add	a,#0x0c
      001D2D F8               [12] 5953 	mov	r0,a
      001D2E 86 82            [24] 5954 	mov	dpl, @r0
      001D30 08               [12] 5955 	inc	r0
      001D31 86 83            [24] 5956 	mov	dph, @r0
      001D33 08               [12] 5957 	inc	r0
      001D34 86 F0            [24] 5958 	mov	b, @r0
      001D36 08               [12] 5959 	inc	r0
      001D37 E6               [12] 5960 	mov	a, @r0
      001D38 12 00 EA         [24] 5961 	lcall	_fuzzy_clamp
                           001C84  5962 	C$fuzzy.h$2582$1_0$100 ==.
                                   5963 ;	../../fuzzy.h:2582: }
      001D3B 85 08 81         [24] 5964 	mov	sp,_bp
      001D3E D0 08            [24] 5965 	pop	_bp
                           001C89  5966 	C$fuzzy.h$2582$1_0$100 ==.
                           001C89  5967 	XFcontroller_8051$fuzzy_rules_aggregated_height$0$0 ==.
      001D40 22               [24] 5968 	ret
                                   5969 ;------------------------------------------------------------
                                   5970 ;Allocation info for local variables in function 'fuzzy_rules_maximum_result'
                                   5971 ;------------------------------------------------------------
                                   5972 ;rules         Allocated to stack - _bp -5 +3 
                                   5973 ;lower         Allocated to stack - _bp -9 +4 
                                   5974 ;upper         Allocated to stack - _bp -13 +4 
                                   5975 ;step          Allocated to stack - _bp -17 +4 
                                   5976 ;implication_method Allocated to stack - _bp -18 +1 
                                   5977 ;aggregation_method Allocated to stack - _bp -19 +1 
                                   5978 ;result        Allocated to registers r5 r6 r7 
                                   5979 ;value         Allocated to stack - _bp +16 +4 
                                   5980 ;height        Allocated to stack - _bp +20 +4 
                                   5981 ;sloc0         Allocated to stack - _bp +1 +3 
                                   5982 ;sloc1         Allocated to stack - _bp +4 +3 
                                   5983 ;sloc2         Allocated to stack - _bp +7 +3 
                                   5984 ;sloc3         Allocated to stack - _bp +10 +3 
                                   5985 ;sloc4         Allocated to stack - _bp +13 +3 
                                   5986 ;------------------------------------------------------------
                           001C8A  5987 	Fcontroller_8051$fuzzy_rules_maximum_result$0$0 ==.
                           001C8A  5988 	C$fuzzy.h$2602$1_0$104 ==.
                                   5989 ;	../../fuzzy.h:2602: static void fuzzy_rules_maximum_result(
                                   5990 ;	-----------------------------------------
                                   5991 ;	 function fuzzy_rules_maximum_result
                                   5992 ;	-----------------------------------------
      001D41                       5993 _fuzzy_rules_maximum_result:
      001D41 C0 08            [24] 5994 	push	_bp
      001D43 E5 81            [12] 5995 	mov	a,sp
      001D45 F5 08            [12] 5996 	mov	_bp,a
      001D47 24 17            [12] 5997 	add	a,#0x17
      001D49 F5 81            [12] 5998 	mov	sp,a
      001D4B AD 82            [24] 5999 	mov	r5, dpl
      001D4D AE 83            [24] 6000 	mov	r6, dph
      001D4F AF F0            [24] 6001 	mov	r7, b
                           001C9A  6002 	C$fuzzy.h$2615$1_0$104 ==.
                                   6003 ;	../../fuzzy.h:2615: result->height =
      001D51 E5 08            [12] 6004 	mov	a,_bp
      001D53 24 0A            [12] 6005 	add	a,#0x0a
      001D55 F8               [12] 6006 	mov	r0,a
      001D56 A6 05            [24] 6007 	mov	@r0,ar5
      001D58 08               [12] 6008 	inc	r0
      001D59 A6 06            [24] 6009 	mov	@r0,ar6
      001D5B 08               [12] 6010 	inc	r0
      001D5C A6 07            [24] 6011 	mov	@r0,ar7
      001D5E E5 08            [12] 6012 	mov	a,_bp
      001D60 24 0A            [12] 6013 	add	a,#0x0a
      001D62 F8               [12] 6014 	mov	r0,a
      001D63 86 82            [24] 6015 	mov	dpl,@r0
      001D65 08               [12] 6016 	inc	r0
      001D66 86 83            [24] 6017 	mov	dph,@r0
      001D68 08               [12] 6018 	inc	r0
      001D69 86 F0            [24] 6019 	mov	b,@r0
      001D6B E4               [12] 6020 	clr	a
      001D6C 12 35 A7         [24] 6021 	lcall	__gptrput
      001D6F A3               [24] 6022 	inc	dptr
      001D70 12 35 A7         [24] 6023 	lcall	__gptrput
      001D73 A3               [24] 6024 	inc	dptr
      001D74 12 35 A7         [24] 6025 	lcall	__gptrput
      001D77 A3               [24] 6026 	inc	dptr
      001D78 12 35 A7         [24] 6027 	lcall	__gptrput
                           001CC4  6028 	C$fuzzy.h$2618$1_0$104 ==.
                                   6029 ;	../../fuzzy.h:2618: result->smallest_position =
      001D7B A8 08            [24] 6030 	mov	r0,_bp
      001D7D 08               [12] 6031 	inc	r0
      001D7E 74 04            [12] 6032 	mov	a,#0x04
      001D80 2D               [12] 6033 	add	a, r5
      001D81 F6               [12] 6034 	mov	@r0,a
      001D82 E4               [12] 6035 	clr	a
      001D83 3E               [12] 6036 	addc	a, r6
      001D84 08               [12] 6037 	inc	r0
      001D85 F6               [12] 6038 	mov	@r0,a
      001D86 08               [12] 6039 	inc	r0
      001D87 A6 07            [24] 6040 	mov	@r0,ar7
      001D89 A8 08            [24] 6041 	mov	r0,_bp
      001D8B 08               [12] 6042 	inc	r0
      001D8C 86 82            [24] 6043 	mov	dpl,@r0
      001D8E 08               [12] 6044 	inc	r0
      001D8F 86 83            [24] 6045 	mov	dph,@r0
      001D91 08               [12] 6046 	inc	r0
      001D92 86 F0            [24] 6047 	mov	b,@r0
      001D94 E5 08            [12] 6048 	mov	a,_bp
      001D96 24 F7            [12] 6049 	add	a,#0xf7
      001D98 F9               [12] 6050 	mov	r1,a
      001D99 E7               [12] 6051 	mov	a,@r1
      001D9A 12 35 A7         [24] 6052 	lcall	__gptrput
      001D9D A3               [24] 6053 	inc	dptr
      001D9E 09               [12] 6054 	inc	r1
      001D9F E7               [12] 6055 	mov	a,@r1
      001DA0 12 35 A7         [24] 6056 	lcall	__gptrput
      001DA3 A3               [24] 6057 	inc	dptr
      001DA4 09               [12] 6058 	inc	r1
      001DA5 E7               [12] 6059 	mov	a,@r1
      001DA6 12 35 A7         [24] 6060 	lcall	__gptrput
      001DA9 A3               [24] 6061 	inc	dptr
      001DAA 09               [12] 6062 	inc	r1
      001DAB E7               [12] 6063 	mov	a,@r1
      001DAC 12 35 A7         [24] 6064 	lcall	__gptrput
                           001CF8  6065 	C$fuzzy.h$2621$1_0$104 ==.
                                   6066 ;	../../fuzzy.h:2621: result->largest_position =
      001DAF E5 08            [12] 6067 	mov	a,_bp
      001DB1 24 04            [12] 6068 	add	a,#0x04
      001DB3 F8               [12] 6069 	mov	r0,a
      001DB4 74 08            [12] 6070 	mov	a,#0x08
      001DB6 2D               [12] 6071 	add	a, r5
      001DB7 F6               [12] 6072 	mov	@r0,a
      001DB8 E4               [12] 6073 	clr	a
      001DB9 3E               [12] 6074 	addc	a, r6
      001DBA 08               [12] 6075 	inc	r0
      001DBB F6               [12] 6076 	mov	@r0,a
      001DBC 08               [12] 6077 	inc	r0
      001DBD A6 07            [24] 6078 	mov	@r0,ar7
      001DBF E5 08            [12] 6079 	mov	a,_bp
      001DC1 24 04            [12] 6080 	add	a,#0x04
      001DC3 F8               [12] 6081 	mov	r0,a
      001DC4 86 82            [24] 6082 	mov	dpl,@r0
      001DC6 08               [12] 6083 	inc	r0
      001DC7 86 83            [24] 6084 	mov	dph,@r0
      001DC9 08               [12] 6085 	inc	r0
      001DCA 86 F0            [24] 6086 	mov	b,@r0
      001DCC E5 08            [12] 6087 	mov	a,_bp
      001DCE 24 F7            [12] 6088 	add	a,#0xf7
      001DD0 F9               [12] 6089 	mov	r1,a
      001DD1 E7               [12] 6090 	mov	a,@r1
      001DD2 12 35 A7         [24] 6091 	lcall	__gptrput
      001DD5 A3               [24] 6092 	inc	dptr
      001DD6 09               [12] 6093 	inc	r1
      001DD7 E7               [12] 6094 	mov	a,@r1
      001DD8 12 35 A7         [24] 6095 	lcall	__gptrput
      001DDB A3               [24] 6096 	inc	dptr
      001DDC 09               [12] 6097 	inc	r1
      001DDD E7               [12] 6098 	mov	a,@r1
      001DDE 12 35 A7         [24] 6099 	lcall	__gptrput
      001DE1 A3               [24] 6100 	inc	dptr
      001DE2 09               [12] 6101 	inc	r1
      001DE3 E7               [12] 6102 	mov	a,@r1
      001DE4 12 35 A7         [24] 6103 	lcall	__gptrput
                           001D30  6104 	C$fuzzy.h$2624$1_0$104 ==.
                                   6105 ;	../../fuzzy.h:2624: result->position_sum =
      001DE7 E5 08            [12] 6106 	mov	a,_bp
      001DE9 24 07            [12] 6107 	add	a,#0x07
      001DEB F8               [12] 6108 	mov	r0,a
      001DEC 74 0C            [12] 6109 	mov	a,#0x0c
      001DEE 2D               [12] 6110 	add	a, r5
      001DEF F6               [12] 6111 	mov	@r0,a
      001DF0 E4               [12] 6112 	clr	a
      001DF1 3E               [12] 6113 	addc	a, r6
      001DF2 08               [12] 6114 	inc	r0
      001DF3 F6               [12] 6115 	mov	@r0,a
      001DF4 08               [12] 6116 	inc	r0
      001DF5 A6 07            [24] 6117 	mov	@r0,ar7
      001DF7 E5 08            [12] 6118 	mov	a,_bp
      001DF9 24 07            [12] 6119 	add	a,#0x07
      001DFB F8               [12] 6120 	mov	r0,a
      001DFC 86 82            [24] 6121 	mov	dpl,@r0
      001DFE 08               [12] 6122 	inc	r0
      001DFF 86 83            [24] 6123 	mov	dph,@r0
      001E01 08               [12] 6124 	inc	r0
      001E02 86 F0            [24] 6125 	mov	b,@r0
      001E04 E4               [12] 6126 	clr	a
      001E05 12 35 A7         [24] 6127 	lcall	__gptrput
      001E08 A3               [24] 6128 	inc	dptr
      001E09 12 35 A7         [24] 6129 	lcall	__gptrput
      001E0C A3               [24] 6130 	inc	dptr
      001E0D 12 35 A7         [24] 6131 	lcall	__gptrput
      001E10 A3               [24] 6132 	inc	dptr
      001E11 12 35 A7         [24] 6133 	lcall	__gptrput
                           001D5D  6134 	C$fuzzy.h$2627$1_0$104 ==.
                                   6135 ;	../../fuzzy.h:2627: result->position_count =
      001E14 E5 08            [12] 6136 	mov	a,_bp
      001E16 24 0D            [12] 6137 	add	a,#0x0d
      001E18 F8               [12] 6138 	mov	r0,a
      001E19 74 10            [12] 6139 	mov	a,#0x10
      001E1B 2D               [12] 6140 	add	a, r5
      001E1C F6               [12] 6141 	mov	@r0,a
      001E1D E4               [12] 6142 	clr	a
      001E1E 3E               [12] 6143 	addc	a, r6
      001E1F 08               [12] 6144 	inc	r0
      001E20 F6               [12] 6145 	mov	@r0,a
      001E21 08               [12] 6146 	inc	r0
      001E22 A6 07            [24] 6147 	mov	@r0,ar7
      001E24 E5 08            [12] 6148 	mov	a,_bp
      001E26 24 0D            [12] 6149 	add	a,#0x0d
      001E28 F8               [12] 6150 	mov	r0,a
      001E29 86 82            [24] 6151 	mov	dpl,@r0
      001E2B 08               [12] 6152 	inc	r0
      001E2C 86 83            [24] 6153 	mov	dph,@r0
      001E2E 08               [12] 6154 	inc	r0
      001E2F 86 F0            [24] 6155 	mov	b,@r0
      001E31 E4               [12] 6156 	clr	a
      001E32 12 35 A7         [24] 6157 	lcall	__gptrput
      001E35 A3               [24] 6158 	inc	dptr
      001E36 12 35 A7         [24] 6159 	lcall	__gptrput
                           001D82  6160 	C$fuzzy.h$2631$2_0$105 ==.
                                   6161 ;	../../fuzzy.h:2631: value = lower;
      001E39 E5 08            [12] 6162 	mov	a,_bp
      001E3B 24 F7            [12] 6163 	add	a,#0xf7
      001E3D F8               [12] 6164 	mov	r0,a
      001E3E E5 08            [12] 6165 	mov	a,_bp
      001E40 24 10            [12] 6166 	add	a,#0x10
      001E42 F9               [12] 6167 	mov	r1,a
      001E43 E6               [12] 6168 	mov	a,@r0
      001E44 F7               [12] 6169 	mov	@r1,a
      001E45 08               [12] 6170 	inc	r0
      001E46 E6               [12] 6171 	mov	a,@r0
      001E47 09               [12] 6172 	inc	r1
      001E48 F7               [12] 6173 	mov	@r1,a
      001E49 08               [12] 6174 	inc	r0
      001E4A E6               [12] 6175 	mov	a,@r0
      001E4B 09               [12] 6176 	inc	r1
      001E4C F7               [12] 6177 	mov	@r1,a
      001E4D 08               [12] 6178 	inc	r0
      001E4E E6               [12] 6179 	mov	a,@r0
      001E4F 09               [12] 6180 	inc	r1
      001E50 F7               [12] 6181 	mov	@r1,a
      001E51                       6182 00109$:
                           001D9A  6183 	C$fuzzy.h$2632$2_0$104 ==.
                                   6184 ;	../../fuzzy.h:2632: value <= upper;
      001E51 E5 08            [12] 6185 	mov	a,_bp
      001E53 24 10            [12] 6186 	add	a,#0x10
      001E55 F8               [12] 6187 	mov	r0,a
      001E56 E6               [12] 6188 	mov	a,@r0
      001E57 C0 E0            [24] 6189 	push	acc
      001E59 08               [12] 6190 	inc	r0
      001E5A E6               [12] 6191 	mov	a,@r0
      001E5B C0 E0            [24] 6192 	push	acc
      001E5D 08               [12] 6193 	inc	r0
      001E5E E6               [12] 6194 	mov	a,@r0
      001E5F C0 E0            [24] 6195 	push	acc
      001E61 08               [12] 6196 	inc	r0
      001E62 E6               [12] 6197 	mov	a,@r0
      001E63 C0 E0            [24] 6198 	push	acc
      001E65 E5 08            [12] 6199 	mov	a,_bp
      001E67 24 F3            [12] 6200 	add	a,#0xf3
      001E69 F8               [12] 6201 	mov	r0,a
      001E6A 86 82            [24] 6202 	mov	dpl, @r0
      001E6C 08               [12] 6203 	inc	r0
      001E6D 86 83            [24] 6204 	mov	dph, @r0
      001E6F 08               [12] 6205 	inc	r0
      001E70 86 F0            [24] 6206 	mov	b, @r0
      001E72 08               [12] 6207 	inc	r0
      001E73 E6               [12] 6208 	mov	a, @r0
      001E74 12 35 C2         [24] 6209 	lcall	___fslt
      001E77 E5 81            [12] 6210 	mov	a,sp
      001E79 24 FC            [12] 6211 	add	a,#0xfc
      001E7B F5 81            [12] 6212 	mov	sp,a
      001E7D E5 82            [12] 6213 	mov	a, dpl
      001E7F 24 FF            [12] 6214 	add	a,#0xff
      001E81 92 00            [24] 6215 	mov	b0,c
      001E83 50 03            [24] 6216 	jnc	00137$
      001E85 02 21 39         [24] 6217 	ljmp	00111$
      001E88                       6218 00137$:
                           001DD1  6219 	C$fuzzy.h$2637$3_0$106 ==.
                                   6220 ;	../../fuzzy.h:2637: rules,
      001E88 E5 08            [12] 6221 	mov	a,_bp
      001E8A 24 ED            [12] 6222 	add	a,#0xed
      001E8C F8               [12] 6223 	mov	r0,a
      001E8D E6               [12] 6224 	mov	a,@r0
      001E8E C0 E0            [24] 6225 	push	acc
      001E90 E5 08            [12] 6226 	mov	a,_bp
      001E92 24 EE            [12] 6227 	add	a,#0xee
      001E94 F8               [12] 6228 	mov	r0,a
      001E95 E6               [12] 6229 	mov	a,@r0
      001E96 C0 E0            [24] 6230 	push	acc
      001E98 E5 08            [12] 6231 	mov	a,_bp
      001E9A 24 10            [12] 6232 	add	a,#0x10
      001E9C F8               [12] 6233 	mov	r0,a
      001E9D E6               [12] 6234 	mov	a,@r0
      001E9E C0 E0            [24] 6235 	push	acc
      001EA0 08               [12] 6236 	inc	r0
      001EA1 E6               [12] 6237 	mov	a,@r0
      001EA2 C0 E0            [24] 6238 	push	acc
      001EA4 08               [12] 6239 	inc	r0
      001EA5 E6               [12] 6240 	mov	a,@r0
      001EA6 C0 E0            [24] 6241 	push	acc
      001EA8 08               [12] 6242 	inc	r0
      001EA9 E6               [12] 6243 	mov	a,@r0
      001EAA C0 E0            [24] 6244 	push	acc
      001EAC E5 08            [12] 6245 	mov	a,_bp
      001EAE 24 FB            [12] 6246 	add	a,#0xfb
      001EB0 F8               [12] 6247 	mov	r0,a
      001EB1 86 82            [24] 6248 	mov	dpl, @r0
      001EB3 08               [12] 6249 	inc	r0
      001EB4 86 83            [24] 6250 	mov	dph, @r0
      001EB6 08               [12] 6251 	inc	r0
      001EB7 86 F0            [24] 6252 	mov	b, @r0
      001EB9 12 1B 98         [24] 6253 	lcall	_fuzzy_rules_aggregated_height
      001EBC C8               [12] 6254 	xch	a,r0
      001EBD E5 08            [12] 6255 	mov	a,_bp
      001EBF 24 14            [12] 6256 	add	a,#0x14
      001EC1 C8               [12] 6257 	xch	a,r0
      001EC2 A6 82            [24] 6258 	mov	@r0, dpl
      001EC4 08               [12] 6259 	inc	r0
      001EC5 A6 83            [24] 6260 	mov	@r0, dph
      001EC7 08               [12] 6261 	inc	r0
      001EC8 A6 F0            [24] 6262 	mov	@r0, b
      001ECA 08               [12] 6263 	inc	r0
      001ECB F6               [12] 6264 	mov	@r0,a
      001ECC E5 81            [12] 6265 	mov	a,sp
      001ECE 24 FA            [12] 6266 	add	a,#0xfa
      001ED0 F5 81            [12] 6267 	mov	sp,a
                           001E1B  6268 	C$fuzzy.h$2644$3_0$106 ==.
                                   6269 ;	../../fuzzy.h:2644: result->position_count == 0u ||
      001ED2 E5 08            [12] 6270 	mov	a,_bp
      001ED4 24 0D            [12] 6271 	add	a,#0x0d
      001ED6 F8               [12] 6272 	mov	r0,a
      001ED7 86 82            [24] 6273 	mov	dpl,@r0
      001ED9 08               [12] 6274 	inc	r0
      001EDA 86 83            [24] 6275 	mov	dph,@r0
      001EDC 08               [12] 6276 	inc	r0
      001EDD 86 F0            [24] 6277 	mov	b,@r0
      001EDF 12 37 EE         [24] 6278 	lcall	__gptrget
      001EE2 FD               [12] 6279 	mov	r5,a
      001EE3 A3               [24] 6280 	inc	dptr
      001EE4 12 37 EE         [24] 6281 	lcall	__gptrget
      001EE7 4D               [12] 6282 	orl	a,r5
      001EE8 60 4C            [24] 6283 	jz	00103$
                           001E33  6284 	C$fuzzy.h$2645$2_0$104 ==.
                                   6285 ;	../../fuzzy.h:2645: height > result->height
      001EEA E5 08            [12] 6286 	mov	a,_bp
      001EEC 24 0A            [12] 6287 	add	a,#0x0a
      001EEE F8               [12] 6288 	mov	r0,a
      001EEF 86 82            [24] 6289 	mov	dpl,@r0
      001EF1 08               [12] 6290 	inc	r0
      001EF2 86 83            [24] 6291 	mov	dph,@r0
      001EF4 08               [12] 6292 	inc	r0
      001EF5 86 F0            [24] 6293 	mov	b,@r0
      001EF7 12 37 EE         [24] 6294 	lcall	__gptrget
      001EFA FC               [12] 6295 	mov	r4,a
      001EFB A3               [24] 6296 	inc	dptr
      001EFC 12 37 EE         [24] 6297 	lcall	__gptrget
      001EFF FD               [12] 6298 	mov	r5,a
      001F00 A3               [24] 6299 	inc	dptr
      001F01 12 37 EE         [24] 6300 	lcall	__gptrget
      001F04 FE               [12] 6301 	mov	r6,a
      001F05 A3               [24] 6302 	inc	dptr
      001F06 12 37 EE         [24] 6303 	lcall	__gptrget
      001F09 FF               [12] 6304 	mov	r7,a
      001F0A E5 08            [12] 6305 	mov	a,_bp
      001F0C 24 14            [12] 6306 	add	a,#0x14
      001F0E F8               [12] 6307 	mov	r0,a
      001F0F E6               [12] 6308 	mov	a,@r0
      001F10 C0 E0            [24] 6309 	push	acc
      001F12 08               [12] 6310 	inc	r0
      001F13 E6               [12] 6311 	mov	a,@r0
      001F14 C0 E0            [24] 6312 	push	acc
      001F16 08               [12] 6313 	inc	r0
      001F17 E6               [12] 6314 	mov	a,@r0
      001F18 C0 E0            [24] 6315 	push	acc
      001F1A 08               [12] 6316 	inc	r0
      001F1B E6               [12] 6317 	mov	a,@r0
      001F1C C0 E0            [24] 6318 	push	acc
      001F1E 8C 82            [24] 6319 	mov	dpl, r4
      001F20 8D 83            [24] 6320 	mov	dph, r5
      001F22 8E F0            [24] 6321 	mov	b, r6
      001F24 EF               [12] 6322 	mov	a, r7
      001F25 12 35 C2         [24] 6323 	lcall	___fslt
      001F28 AF 82            [24] 6324 	mov	r7, dpl
      001F2A E5 81            [12] 6325 	mov	a,sp
      001F2C 24 FC            [12] 6326 	add	a,#0xfc
      001F2E F5 81            [12] 6327 	mov	sp,a
      001F30 EF               [12] 6328 	mov	a,r7
      001F31 70 03            [24] 6329 	jnz	00139$
      001F33 02 1F EE         [24] 6330 	ljmp	00104$
      001F36                       6331 00139$:
      001F36                       6332 00103$:
                           001E7F  6333 	C$fuzzy.h$2647$4_0$107 ==.
                                   6334 ;	../../fuzzy.h:2647: result->height =
      001F36 E5 08            [12] 6335 	mov	a,_bp
      001F38 24 0A            [12] 6336 	add	a,#0x0a
      001F3A F8               [12] 6337 	mov	r0,a
      001F3B 86 82            [24] 6338 	mov	dpl,@r0
      001F3D 08               [12] 6339 	inc	r0
      001F3E 86 83            [24] 6340 	mov	dph,@r0
      001F40 08               [12] 6341 	inc	r0
      001F41 86 F0            [24] 6342 	mov	b,@r0
      001F43 E5 08            [12] 6343 	mov	a,_bp
      001F45 24 14            [12] 6344 	add	a,#0x14
      001F47 F9               [12] 6345 	mov	r1,a
      001F48 E7               [12] 6346 	mov	a,@r1
      001F49 12 35 A7         [24] 6347 	lcall	__gptrput
      001F4C A3               [24] 6348 	inc	dptr
      001F4D 09               [12] 6349 	inc	r1
      001F4E E7               [12] 6350 	mov	a,@r1
      001F4F 12 35 A7         [24] 6351 	lcall	__gptrput
      001F52 A3               [24] 6352 	inc	dptr
      001F53 09               [12] 6353 	inc	r1
      001F54 E7               [12] 6354 	mov	a,@r1
      001F55 12 35 A7         [24] 6355 	lcall	__gptrput
      001F58 A3               [24] 6356 	inc	dptr
      001F59 09               [12] 6357 	inc	r1
      001F5A E7               [12] 6358 	mov	a,@r1
      001F5B 12 35 A7         [24] 6359 	lcall	__gptrput
                           001EA7  6360 	C$fuzzy.h$2650$4_0$107 ==.
                                   6361 ;	../../fuzzy.h:2650: result->smallest_position =
      001F5E A8 08            [24] 6362 	mov	r0,_bp
      001F60 08               [12] 6363 	inc	r0
      001F61 86 82            [24] 6364 	mov	dpl,@r0
      001F63 08               [12] 6365 	inc	r0
      001F64 86 83            [24] 6366 	mov	dph,@r0
      001F66 08               [12] 6367 	inc	r0
      001F67 86 F0            [24] 6368 	mov	b,@r0
      001F69 E5 08            [12] 6369 	mov	a,_bp
      001F6B 24 10            [12] 6370 	add	a,#0x10
      001F6D F9               [12] 6371 	mov	r1,a
      001F6E E7               [12] 6372 	mov	a,@r1
      001F6F 12 35 A7         [24] 6373 	lcall	__gptrput
      001F72 A3               [24] 6374 	inc	dptr
      001F73 09               [12] 6375 	inc	r1
      001F74 E7               [12] 6376 	mov	a,@r1
      001F75 12 35 A7         [24] 6377 	lcall	__gptrput
      001F78 A3               [24] 6378 	inc	dptr
      001F79 09               [12] 6379 	inc	r1
      001F7A E7               [12] 6380 	mov	a,@r1
      001F7B 12 35 A7         [24] 6381 	lcall	__gptrput
      001F7E A3               [24] 6382 	inc	dptr
      001F7F 09               [12] 6383 	inc	r1
      001F80 E7               [12] 6384 	mov	a,@r1
      001F81 12 35 A7         [24] 6385 	lcall	__gptrput
                           001ECD  6386 	C$fuzzy.h$2653$4_0$107 ==.
                                   6387 ;	../../fuzzy.h:2653: result->largest_position =
      001F84 E5 08            [12] 6388 	mov	a,_bp
      001F86 24 04            [12] 6389 	add	a,#0x04
      001F88 F8               [12] 6390 	mov	r0,a
      001F89 86 82            [24] 6391 	mov	dpl,@r0
      001F8B 08               [12] 6392 	inc	r0
      001F8C 86 83            [24] 6393 	mov	dph,@r0
      001F8E 08               [12] 6394 	inc	r0
      001F8F 86 F0            [24] 6395 	mov	b,@r0
      001F91 E5 08            [12] 6396 	mov	a,_bp
      001F93 24 10            [12] 6397 	add	a,#0x10
      001F95 F9               [12] 6398 	mov	r1,a
      001F96 E7               [12] 6399 	mov	a,@r1
      001F97 12 35 A7         [24] 6400 	lcall	__gptrput
      001F9A A3               [24] 6401 	inc	dptr
      001F9B 09               [12] 6402 	inc	r1
      001F9C E7               [12] 6403 	mov	a,@r1
      001F9D 12 35 A7         [24] 6404 	lcall	__gptrput
      001FA0 A3               [24] 6405 	inc	dptr
      001FA1 09               [12] 6406 	inc	r1
      001FA2 E7               [12] 6407 	mov	a,@r1
      001FA3 12 35 A7         [24] 6408 	lcall	__gptrput
      001FA6 A3               [24] 6409 	inc	dptr
      001FA7 09               [12] 6410 	inc	r1
      001FA8 E7               [12] 6411 	mov	a,@r1
      001FA9 12 35 A7         [24] 6412 	lcall	__gptrput
                           001EF5  6413 	C$fuzzy.h$2656$4_0$107 ==.
                                   6414 ;	../../fuzzy.h:2656: result->position_sum =
      001FAC E5 08            [12] 6415 	mov	a,_bp
      001FAE 24 07            [12] 6416 	add	a,#0x07
      001FB0 F8               [12] 6417 	mov	r0,a
      001FB1 86 82            [24] 6418 	mov	dpl,@r0
      001FB3 08               [12] 6419 	inc	r0
      001FB4 86 83            [24] 6420 	mov	dph,@r0
      001FB6 08               [12] 6421 	inc	r0
      001FB7 86 F0            [24] 6422 	mov	b,@r0
      001FB9 E5 08            [12] 6423 	mov	a,_bp
      001FBB 24 10            [12] 6424 	add	a,#0x10
      001FBD F9               [12] 6425 	mov	r1,a
      001FBE E7               [12] 6426 	mov	a,@r1
      001FBF 12 35 A7         [24] 6427 	lcall	__gptrput
      001FC2 A3               [24] 6428 	inc	dptr
      001FC3 09               [12] 6429 	inc	r1
      001FC4 E7               [12] 6430 	mov	a,@r1
      001FC5 12 35 A7         [24] 6431 	lcall	__gptrput
      001FC8 A3               [24] 6432 	inc	dptr
      001FC9 09               [12] 6433 	inc	r1
      001FCA E7               [12] 6434 	mov	a,@r1
      001FCB 12 35 A7         [24] 6435 	lcall	__gptrput
      001FCE A3               [24] 6436 	inc	dptr
      001FCF 09               [12] 6437 	inc	r1
      001FD0 E7               [12] 6438 	mov	a,@r1
      001FD1 12 35 A7         [24] 6439 	lcall	__gptrput
                           001F1D  6440 	C$fuzzy.h$2659$4_0$107 ==.
                                   6441 ;	../../fuzzy.h:2659: result->position_count =
      001FD4 E5 08            [12] 6442 	mov	a,_bp
      001FD6 24 0D            [12] 6443 	add	a,#0x0d
      001FD8 F8               [12] 6444 	mov	r0,a
      001FD9 86 82            [24] 6445 	mov	dpl,@r0
      001FDB 08               [12] 6446 	inc	r0
      001FDC 86 83            [24] 6447 	mov	dph,@r0
      001FDE 08               [12] 6448 	inc	r0
      001FDF 86 F0            [24] 6449 	mov	b,@r0
      001FE1 74 01            [12] 6450 	mov	a,#0x01
      001FE3 12 35 A7         [24] 6451 	lcall	__gptrput
      001FE6 A3               [24] 6452 	inc	dptr
      001FE7 E4               [12] 6453 	clr	a
      001FE8 12 35 A7         [24] 6454 	lcall	__gptrput
      001FEB 02 20 FA         [24] 6455 	ljmp	00110$
      001FEE                       6456 00104$:
                           001F37  6457 	C$fuzzy.h$2664$2_0$104 ==.
                                   6458 ;	../../fuzzy.h:2664: result->height
      001FEE E5 08            [12] 6459 	mov	a,_bp
      001FF0 24 0A            [12] 6460 	add	a,#0x0a
      001FF2 F8               [12] 6461 	mov	r0,a
      001FF3 86 82            [24] 6462 	mov	dpl,@r0
      001FF5 08               [12] 6463 	inc	r0
      001FF6 86 83            [24] 6464 	mov	dph,@r0
      001FF8 08               [12] 6465 	inc	r0
      001FF9 86 F0            [24] 6466 	mov	b,@r0
      001FFB 12 37 EE         [24] 6467 	lcall	__gptrget
      001FFE FC               [12] 6468 	mov	r4,a
      001FFF A3               [24] 6469 	inc	dptr
      002000 12 37 EE         [24] 6470 	lcall	__gptrget
      002003 FD               [12] 6471 	mov	r5,a
      002004 A3               [24] 6472 	inc	dptr
      002005 12 37 EE         [24] 6473 	lcall	__gptrget
      002008 FE               [12] 6474 	mov	r6,a
      002009 A3               [24] 6475 	inc	dptr
      00200A 12 37 EE         [24] 6476 	lcall	__gptrget
      00200D FF               [12] 6477 	mov	r7,a
      00200E C0 04            [24] 6478 	push	ar4
      002010 C0 05            [24] 6479 	push	ar5
      002012 C0 06            [24] 6480 	push	ar6
      002014 C0 07            [24] 6481 	push	ar7
      002016 E5 08            [12] 6482 	mov	a,_bp
      002018 24 14            [12] 6483 	add	a,#0x14
      00201A F8               [12] 6484 	mov	r0,a
      00201B 86 82            [24] 6485 	mov	dpl, @r0
      00201D 08               [12] 6486 	inc	r0
      00201E 86 83            [24] 6487 	mov	dph, @r0
      002020 08               [12] 6488 	inc	r0
      002021 86 F0            [24] 6489 	mov	b, @r0
      002023 08               [12] 6490 	inc	r0
      002024 E6               [12] 6491 	mov	a, @r0
      002025 12 35 96         [24] 6492 	lcall	___fseq
      002028 AF 82            [24] 6493 	mov	r7, dpl
      00202A E5 81            [12] 6494 	mov	a,sp
      00202C 24 FC            [12] 6495 	add	a,#0xfc
      00202E F5 81            [12] 6496 	mov	sp,a
      002030 EF               [12] 6497 	mov	a,r7
      002031 70 03            [24] 6498 	jnz	00140$
      002033 02 20 FA         [24] 6499 	ljmp	00110$
      002036                       6500 00140$:
                           001F7F  6501 	C$fuzzy.h$2666$4_0$108 ==.
                                   6502 ;	../../fuzzy.h:2666: result->largest_position =
      002036 E5 08            [12] 6503 	mov	a,_bp
      002038 24 04            [12] 6504 	add	a,#0x04
      00203A F8               [12] 6505 	mov	r0,a
      00203B 86 82            [24] 6506 	mov	dpl,@r0
      00203D 08               [12] 6507 	inc	r0
      00203E 86 83            [24] 6508 	mov	dph,@r0
      002040 08               [12] 6509 	inc	r0
      002041 86 F0            [24] 6510 	mov	b,@r0
      002043 E5 08            [12] 6511 	mov	a,_bp
      002045 24 10            [12] 6512 	add	a,#0x10
      002047 F9               [12] 6513 	mov	r1,a
      002048 E7               [12] 6514 	mov	a,@r1
      002049 12 35 A7         [24] 6515 	lcall	__gptrput
      00204C A3               [24] 6516 	inc	dptr
      00204D 09               [12] 6517 	inc	r1
      00204E E7               [12] 6518 	mov	a,@r1
      00204F 12 35 A7         [24] 6519 	lcall	__gptrput
      002052 A3               [24] 6520 	inc	dptr
      002053 09               [12] 6521 	inc	r1
      002054 E7               [12] 6522 	mov	a,@r1
      002055 12 35 A7         [24] 6523 	lcall	__gptrput
      002058 A3               [24] 6524 	inc	dptr
      002059 09               [12] 6525 	inc	r1
      00205A E7               [12] 6526 	mov	a,@r1
      00205B 12 35 A7         [24] 6527 	lcall	__gptrput
                           001FA7  6528 	C$fuzzy.h$2669$4_0$108 ==.
                                   6529 ;	../../fuzzy.h:2669: result->position_sum +=
      00205E E5 08            [12] 6530 	mov	a,_bp
      002060 24 07            [12] 6531 	add	a,#0x07
      002062 F8               [12] 6532 	mov	r0,a
      002063 86 82            [24] 6533 	mov	dpl,@r0
      002065 08               [12] 6534 	inc	r0
      002066 86 83            [24] 6535 	mov	dph,@r0
      002068 08               [12] 6536 	inc	r0
      002069 86 F0            [24] 6537 	mov	b,@r0
      00206B 12 37 EE         [24] 6538 	lcall	__gptrget
      00206E FC               [12] 6539 	mov	r4,a
      00206F A3               [24] 6540 	inc	dptr
      002070 12 37 EE         [24] 6541 	lcall	__gptrget
      002073 FD               [12] 6542 	mov	r5,a
      002074 A3               [24] 6543 	inc	dptr
      002075 12 37 EE         [24] 6544 	lcall	__gptrget
      002078 FE               [12] 6545 	mov	r6,a
      002079 A3               [24] 6546 	inc	dptr
      00207A 12 37 EE         [24] 6547 	lcall	__gptrget
      00207D FF               [12] 6548 	mov	r7,a
      00207E E5 08            [12] 6549 	mov	a,_bp
      002080 24 10            [12] 6550 	add	a,#0x10
      002082 F8               [12] 6551 	mov	r0,a
      002083 E6               [12] 6552 	mov	a,@r0
      002084 C0 E0            [24] 6553 	push	acc
      002086 08               [12] 6554 	inc	r0
      002087 E6               [12] 6555 	mov	a,@r0
      002088 C0 E0            [24] 6556 	push	acc
      00208A 08               [12] 6557 	inc	r0
      00208B E6               [12] 6558 	mov	a,@r0
      00208C C0 E0            [24] 6559 	push	acc
      00208E 08               [12] 6560 	inc	r0
      00208F E6               [12] 6561 	mov	a,@r0
      002090 C0 E0            [24] 6562 	push	acc
      002092 8C 82            [24] 6563 	mov	dpl, r4
      002094 8D 83            [24] 6564 	mov	dph, r5
      002096 8E F0            [24] 6565 	mov	b, r6
      002098 EF               [12] 6566 	mov	a, r7
      002099 12 36 14         [24] 6567 	lcall	___fsadd
      00209C AC 82            [24] 6568 	mov	r4, dpl
      00209E AD 83            [24] 6569 	mov	r5, dph
      0020A0 AE F0            [24] 6570 	mov	r6, b
      0020A2 FF               [12] 6571 	mov	r7, a
      0020A3 E5 81            [12] 6572 	mov	a,sp
      0020A5 24 FC            [12] 6573 	add	a,#0xfc
      0020A7 F5 81            [12] 6574 	mov	sp,a
      0020A9 E5 08            [12] 6575 	mov	a,_bp
      0020AB 24 07            [12] 6576 	add	a,#0x07
      0020AD F8               [12] 6577 	mov	r0,a
      0020AE 86 82            [24] 6578 	mov	dpl,@r0
      0020B0 08               [12] 6579 	inc	r0
      0020B1 86 83            [24] 6580 	mov	dph,@r0
      0020B3 08               [12] 6581 	inc	r0
      0020B4 86 F0            [24] 6582 	mov	b,@r0
      0020B6 EC               [12] 6583 	mov	a,r4
      0020B7 12 35 A7         [24] 6584 	lcall	__gptrput
      0020BA A3               [24] 6585 	inc	dptr
      0020BB ED               [12] 6586 	mov	a,r5
      0020BC 12 35 A7         [24] 6587 	lcall	__gptrput
      0020BF A3               [24] 6588 	inc	dptr
      0020C0 EE               [12] 6589 	mov	a,r6
      0020C1 12 35 A7         [24] 6590 	lcall	__gptrput
      0020C4 A3               [24] 6591 	inc	dptr
      0020C5 EF               [12] 6592 	mov	a,r7
      0020C6 12 35 A7         [24] 6593 	lcall	__gptrput
                           002012  6594 	C$fuzzy.h$2672$4_0$108 ==.
                                   6595 ;	../../fuzzy.h:2672: result->position_count++;
      0020C9 E5 08            [12] 6596 	mov	a,_bp
      0020CB 24 0D            [12] 6597 	add	a,#0x0d
      0020CD F8               [12] 6598 	mov	r0,a
      0020CE 86 82            [24] 6599 	mov	dpl,@r0
      0020D0 08               [12] 6600 	inc	r0
      0020D1 86 83            [24] 6601 	mov	dph,@r0
      0020D3 08               [12] 6602 	inc	r0
      0020D4 86 F0            [24] 6603 	mov	b,@r0
      0020D6 12 37 EE         [24] 6604 	lcall	__gptrget
      0020D9 FF               [12] 6605 	mov	r7,a
      0020DA A3               [24] 6606 	inc	dptr
      0020DB 12 37 EE         [24] 6607 	lcall	__gptrget
      0020DE FE               [12] 6608 	mov	r6,a
      0020DF 0F               [12] 6609 	inc	r7
      0020E0 BF 00 01         [24] 6610 	cjne	r7,#0x00,00141$
      0020E3 0E               [12] 6611 	inc	r6
      0020E4                       6612 00141$:
      0020E4 E5 08            [12] 6613 	mov	a,_bp
      0020E6 24 0D            [12] 6614 	add	a,#0x0d
      0020E8 F8               [12] 6615 	mov	r0,a
      0020E9 86 82            [24] 6616 	mov	dpl,@r0
      0020EB 08               [12] 6617 	inc	r0
      0020EC 86 83            [24] 6618 	mov	dph,@r0
      0020EE 08               [12] 6619 	inc	r0
      0020EF 86 F0            [24] 6620 	mov	b,@r0
      0020F1 EF               [12] 6621 	mov	a,r7
      0020F2 12 35 A7         [24] 6622 	lcall	__gptrput
      0020F5 A3               [24] 6623 	inc	dptr
      0020F6 EE               [12] 6624 	mov	a,r6
      0020F7 12 35 A7         [24] 6625 	lcall	__gptrput
      0020FA                       6626 00110$:
                           002043  6627 	C$fuzzy.h$2634$2_0$104 ==.
                                   6628 ;	../../fuzzy.h:2634: ) {
      0020FA E5 08            [12] 6629 	mov	a,_bp
      0020FC 24 EF            [12] 6630 	add	a,#0xef
      0020FE F8               [12] 6631 	mov	r0,a
      0020FF E6               [12] 6632 	mov	a,@r0
      002100 C0 E0            [24] 6633 	push	acc
      002102 08               [12] 6634 	inc	r0
      002103 E6               [12] 6635 	mov	a,@r0
      002104 C0 E0            [24] 6636 	push	acc
      002106 08               [12] 6637 	inc	r0
      002107 E6               [12] 6638 	mov	a,@r0
      002108 C0 E0            [24] 6639 	push	acc
      00210A 08               [12] 6640 	inc	r0
      00210B E6               [12] 6641 	mov	a,@r0
      00210C C0 E0            [24] 6642 	push	acc
      00210E E5 08            [12] 6643 	mov	a,_bp
      002110 24 10            [12] 6644 	add	a,#0x10
      002112 F8               [12] 6645 	mov	r0,a
      002113 86 82            [24] 6646 	mov	dpl, @r0
      002115 08               [12] 6647 	inc	r0
      002116 86 83            [24] 6648 	mov	dph, @r0
      002118 08               [12] 6649 	inc	r0
      002119 86 F0            [24] 6650 	mov	b, @r0
      00211B 08               [12] 6651 	inc	r0
      00211C E6               [12] 6652 	mov	a, @r0
      00211D 12 36 14         [24] 6653 	lcall	___fsadd
      002120 C8               [12] 6654 	xch	a,r0
      002121 E5 08            [12] 6655 	mov	a,_bp
      002123 24 10            [12] 6656 	add	a,#0x10
      002125 C8               [12] 6657 	xch	a,r0
      002126 A6 82            [24] 6658 	mov	@r0, dpl
      002128 08               [12] 6659 	inc	r0
      002129 A6 83            [24] 6660 	mov	@r0, dph
      00212B 08               [12] 6661 	inc	r0
      00212C A6 F0            [24] 6662 	mov	@r0, b
      00212E 08               [12] 6663 	inc	r0
      00212F F6               [12] 6664 	mov	@r0,a
      002130 E5 81            [12] 6665 	mov	a,sp
      002132 24 FC            [12] 6666 	add	a,#0xfc
      002134 F5 81            [12] 6667 	mov	sp,a
      002136 02 1E 51         [24] 6668 	ljmp	00109$
      002139                       6669 00111$:
                           002082  6670 	C$fuzzy.h$2675$2_0$104 ==.
                                   6671 ;	../../fuzzy.h:2675: }
      002139 85 08 81         [24] 6672 	mov	sp,_bp
      00213C D0 08            [24] 6673 	pop	_bp
                           002087  6674 	C$fuzzy.h$2675$2_0$104 ==.
                           002087  6675 	XFcontroller_8051$fuzzy_rules_maximum_result$0$0 ==.
      00213E 22               [24] 6676 	ret
                                   6677 ;------------------------------------------------------------
                                   6678 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_cog'
                                   6679 ;------------------------------------------------------------
                                   6680 ;lower         Allocated to stack - _bp -6 +4 
                                   6681 ;upper         Allocated to stack - _bp -10 +4 
                                   6682 ;step          Allocated to stack - _bp -14 +4 
                                   6683 ;implication_method Allocated to stack - _bp -15 +1 
                                   6684 ;aggregation_method Allocated to stack - _bp -16 +1 
                                   6685 ;rules         Allocated to stack - _bp +1 +3 
                                   6686 ;weighted_sum  Allocated to stack - _bp +4 +4 
                                   6687 ;height_sum    Allocated to stack - _bp +8 +4 
                                   6688 ;value         Allocated to stack - _bp +12 +4 
                                   6689 ;height        Allocated to stack - _bp +16 +4 
                                   6690 ;------------------------------------------------------------
                           002088  6691 	G$fuzzy_rules_defuzzify_cog$0$0 ==.
                           002088  6692 	C$fuzzy.h$2682$2_0$110 ==.
                                   6693 ;	../../fuzzy.h:2682: float fuzzy_rules_defuzzify_cog(
                                   6694 ;	-----------------------------------------
                                   6695 ;	 function fuzzy_rules_defuzzify_cog
                                   6696 ;	-----------------------------------------
      00213F                       6697 _fuzzy_rules_defuzzify_cog:
      00213F C0 08            [24] 6698 	push	_bp
      002141 85 81 08         [24] 6699 	mov	_bp,sp
      002144 C0 82            [24] 6700 	push	dpl
      002146 C0 83            [24] 6701 	push	dph
      002148 C0 F0            [24] 6702 	push	b
      00214A E5 81            [12] 6703 	mov	a,sp
      00214C 24 10            [12] 6704 	add	a,#0x10
      00214E F5 81            [12] 6705 	mov	sp,a
                           002099  6706 	C$fuzzy.h$2697$1_0$110 ==.
                                   6707 ;	../../fuzzy.h:2697: 0.0f;
      002150 E5 08            [12] 6708 	mov	a,_bp
      002152 24 04            [12] 6709 	add	a,#0x04
      002154 F8               [12] 6710 	mov	r0,a
      002155 E4               [12] 6711 	clr	a
      002156 F6               [12] 6712 	mov	@r0,a
      002157 08               [12] 6713 	inc	r0
      002158 F6               [12] 6714 	mov	@r0,a
      002159 08               [12] 6715 	inc	r0
      00215A F6               [12] 6716 	mov	@r0,a
      00215B 08               [12] 6717 	inc	r0
      00215C F6               [12] 6718 	mov	@r0,a
                           0020A6  6719 	C$fuzzy.h$2700$1_0$110 ==.
                                   6720 ;	../../fuzzy.h:2700: 0.0f;
      00215D E5 08            [12] 6721 	mov	a,_bp
      00215F 24 08            [12] 6722 	add	a,#0x08
      002161 F8               [12] 6723 	mov	r0,a
      002162 E4               [12] 6724 	clr	a
      002163 F6               [12] 6725 	mov	@r0,a
      002164 08               [12] 6726 	inc	r0
      002165 F6               [12] 6727 	mov	@r0,a
      002166 08               [12] 6728 	inc	r0
      002167 F6               [12] 6729 	mov	@r0,a
      002168 08               [12] 6730 	inc	r0
      002169 F6               [12] 6731 	mov	@r0,a
                           0020B3  6732 	C$fuzzy.h$2703$2_0$111 ==.
                                   6733 ;	../../fuzzy.h:2703: value = lower;
      00216A E5 08            [12] 6734 	mov	a,_bp
      00216C 24 FA            [12] 6735 	add	a,#0xfa
      00216E F8               [12] 6736 	mov	r0,a
      00216F E5 08            [12] 6737 	mov	a,_bp
      002171 24 0C            [12] 6738 	add	a,#0x0c
      002173 F9               [12] 6739 	mov	r1,a
      002174 E6               [12] 6740 	mov	a,@r0
      002175 F7               [12] 6741 	mov	@r1,a
      002176 08               [12] 6742 	inc	r0
      002177 E6               [12] 6743 	mov	a,@r0
      002178 09               [12] 6744 	inc	r1
      002179 F7               [12] 6745 	mov	@r1,a
      00217A 08               [12] 6746 	inc	r0
      00217B E6               [12] 6747 	mov	a,@r0
      00217C 09               [12] 6748 	inc	r1
      00217D F7               [12] 6749 	mov	@r1,a
      00217E 08               [12] 6750 	inc	r0
      00217F E6               [12] 6751 	mov	a,@r0
      002180 09               [12] 6752 	inc	r1
      002181 F7               [12] 6753 	mov	@r1,a
      002182                       6754 00105$:
                           0020CB  6755 	C$fuzzy.h$2704$1_0$110 ==.
                                   6756 ;	../../fuzzy.h:2704: value <= upper;
      002182 E5 08            [12] 6757 	mov	a,_bp
      002184 24 0C            [12] 6758 	add	a,#0x0c
      002186 F8               [12] 6759 	mov	r0,a
      002187 E6               [12] 6760 	mov	a,@r0
      002188 C0 E0            [24] 6761 	push	acc
      00218A 08               [12] 6762 	inc	r0
      00218B E6               [12] 6763 	mov	a,@r0
      00218C C0 E0            [24] 6764 	push	acc
      00218E 08               [12] 6765 	inc	r0
      00218F E6               [12] 6766 	mov	a,@r0
      002190 C0 E0            [24] 6767 	push	acc
      002192 08               [12] 6768 	inc	r0
      002193 E6               [12] 6769 	mov	a,@r0
      002194 C0 E0            [24] 6770 	push	acc
      002196 E5 08            [12] 6771 	mov	a,_bp
      002198 24 F6            [12] 6772 	add	a,#0xf6
      00219A F8               [12] 6773 	mov	r0,a
      00219B 86 82            [24] 6774 	mov	dpl, @r0
      00219D 08               [12] 6775 	inc	r0
      00219E 86 83            [24] 6776 	mov	dph, @r0
      0021A0 08               [12] 6777 	inc	r0
      0021A1 86 F0            [24] 6778 	mov	b, @r0
      0021A3 08               [12] 6779 	inc	r0
      0021A4 E6               [12] 6780 	mov	a, @r0
      0021A5 12 35 C2         [24] 6781 	lcall	___fslt
      0021A8 E5 81            [12] 6782 	mov	a,sp
      0021AA 24 FC            [12] 6783 	add	a,#0xfc
      0021AC F5 81            [12] 6784 	mov	sp,a
      0021AE E5 82            [12] 6785 	mov	a, dpl
      0021B0 24 FF            [12] 6786 	add	a,#0xff
      0021B2 92 00            [24] 6787 	mov	b0,c
      0021B4 50 03            [24] 6788 	jnc	00127$
      0021B6 02 22 DF         [24] 6789 	ljmp	00101$
      0021B9                       6790 00127$:
                           002102  6791 	C$fuzzy.h$2709$3_0$112 ==.
                                   6792 ;	../../fuzzy.h:2709: rules,
      0021B9 E5 08            [12] 6793 	mov	a,_bp
      0021BB 24 F0            [12] 6794 	add	a,#0xf0
      0021BD F8               [12] 6795 	mov	r0,a
      0021BE E6               [12] 6796 	mov	a,@r0
      0021BF C0 E0            [24] 6797 	push	acc
      0021C1 E5 08            [12] 6798 	mov	a,_bp
      0021C3 24 F1            [12] 6799 	add	a,#0xf1
      0021C5 F8               [12] 6800 	mov	r0,a
      0021C6 E6               [12] 6801 	mov	a,@r0
      0021C7 C0 E0            [24] 6802 	push	acc
      0021C9 E5 08            [12] 6803 	mov	a,_bp
      0021CB 24 0C            [12] 6804 	add	a,#0x0c
      0021CD F8               [12] 6805 	mov	r0,a
      0021CE E6               [12] 6806 	mov	a,@r0
      0021CF C0 E0            [24] 6807 	push	acc
      0021D1 08               [12] 6808 	inc	r0
      0021D2 E6               [12] 6809 	mov	a,@r0
      0021D3 C0 E0            [24] 6810 	push	acc
      0021D5 08               [12] 6811 	inc	r0
      0021D6 E6               [12] 6812 	mov	a,@r0
      0021D7 C0 E0            [24] 6813 	push	acc
      0021D9 08               [12] 6814 	inc	r0
      0021DA E6               [12] 6815 	mov	a,@r0
      0021DB C0 E0            [24] 6816 	push	acc
      0021DD A8 08            [24] 6817 	mov	r0,_bp
      0021DF 08               [12] 6818 	inc	r0
      0021E0 86 82            [24] 6819 	mov	dpl, @r0
      0021E2 08               [12] 6820 	inc	r0
      0021E3 86 83            [24] 6821 	mov	dph, @r0
      0021E5 08               [12] 6822 	inc	r0
      0021E6 86 F0            [24] 6823 	mov	b, @r0
      0021E8 12 1B 98         [24] 6824 	lcall	_fuzzy_rules_aggregated_height
      0021EB C8               [12] 6825 	xch	a,r0
      0021EC E5 08            [12] 6826 	mov	a,_bp
      0021EE 24 10            [12] 6827 	add	a,#0x10
      0021F0 C8               [12] 6828 	xch	a,r0
      0021F1 A6 82            [24] 6829 	mov	@r0, dpl
      0021F3 08               [12] 6830 	inc	r0
      0021F4 A6 83            [24] 6831 	mov	@r0, dph
      0021F6 08               [12] 6832 	inc	r0
      0021F7 A6 F0            [24] 6833 	mov	@r0, b
      0021F9 08               [12] 6834 	inc	r0
      0021FA F6               [12] 6835 	mov	@r0,a
      0021FB E5 81            [12] 6836 	mov	a,sp
      0021FD 24 FA            [12] 6837 	add	a,#0xfa
      0021FF F5 81            [12] 6838 	mov	sp,a
                           00214A  6839 	C$fuzzy.h$2717$1_0$110 ==.
                                   6840 ;	../../fuzzy.h:2717: height;
      002201 E5 08            [12] 6841 	mov	a,_bp
      002203 24 10            [12] 6842 	add	a,#0x10
      002205 F8               [12] 6843 	mov	r0,a
      002206 E6               [12] 6844 	mov	a,@r0
      002207 C0 E0            [24] 6845 	push	acc
      002209 08               [12] 6846 	inc	r0
      00220A E6               [12] 6847 	mov	a,@r0
      00220B C0 E0            [24] 6848 	push	acc
      00220D 08               [12] 6849 	inc	r0
      00220E E6               [12] 6850 	mov	a,@r0
      00220F C0 E0            [24] 6851 	push	acc
      002211 08               [12] 6852 	inc	r0
      002212 E6               [12] 6853 	mov	a,@r0
      002213 C0 E0            [24] 6854 	push	acc
      002215 E5 08            [12] 6855 	mov	a,_bp
      002217 24 0C            [12] 6856 	add	a,#0x0c
      002219 F8               [12] 6857 	mov	r0,a
      00221A 86 82            [24] 6858 	mov	dpl, @r0
      00221C 08               [12] 6859 	inc	r0
      00221D 86 83            [24] 6860 	mov	dph, @r0
      00221F 08               [12] 6861 	inc	r0
      002220 86 F0            [24] 6862 	mov	b, @r0
      002222 08               [12] 6863 	inc	r0
      002223 E6               [12] 6864 	mov	a, @r0
      002224 12 34 92         [24] 6865 	lcall	___fsmul
      002227 AC 82            [24] 6866 	mov	r4, dpl
      002229 AD 83            [24] 6867 	mov	r5, dph
      00222B AE F0            [24] 6868 	mov	r6, b
      00222D FF               [12] 6869 	mov	r7, a
      00222E E5 81            [12] 6870 	mov	a,sp
      002230 24 FC            [12] 6871 	add	a,#0xfc
      002232 F5 81            [12] 6872 	mov	sp,a
      002234 C0 04            [24] 6873 	push	ar4
      002236 C0 05            [24] 6874 	push	ar5
      002238 C0 06            [24] 6875 	push	ar6
      00223A C0 07            [24] 6876 	push	ar7
                           002185  6877 	C$fuzzy.h$2720$1_0$110 ==.
                                   6878 ;	../../fuzzy.h:2720: height;
      00223C E5 08            [12] 6879 	mov	a,_bp
      00223E 24 04            [12] 6880 	add	a,#0x04
      002240 F8               [12] 6881 	mov	r0,a
      002241 86 82            [24] 6882 	mov	dpl, @r0
      002243 08               [12] 6883 	inc	r0
      002244 86 83            [24] 6884 	mov	dph, @r0
      002246 08               [12] 6885 	inc	r0
      002247 86 F0            [24] 6886 	mov	b, @r0
      002249 08               [12] 6887 	inc	r0
      00224A E6               [12] 6888 	mov	a, @r0
      00224B 12 36 14         [24] 6889 	lcall	___fsadd
      00224E C8               [12] 6890 	xch	a,r0
      00224F E5 08            [12] 6891 	mov	a,_bp
      002251 24 04            [12] 6892 	add	a,#0x04
      002253 C8               [12] 6893 	xch	a,r0
      002254 A6 82            [24] 6894 	mov	@r0, dpl
      002256 08               [12] 6895 	inc	r0
      002257 A6 83            [24] 6896 	mov	@r0, dph
      002259 08               [12] 6897 	inc	r0
      00225A A6 F0            [24] 6898 	mov	@r0, b
      00225C 08               [12] 6899 	inc	r0
      00225D F6               [12] 6900 	mov	@r0,a
      00225E E5 81            [12] 6901 	mov	a,sp
      002260 24 FC            [12] 6902 	add	a,#0xfc
      002262 F5 81            [12] 6903 	mov	sp,a
      002264 E5 08            [12] 6904 	mov	a,_bp
      002266 24 10            [12] 6905 	add	a,#0x10
      002268 F8               [12] 6906 	mov	r0,a
      002269 E6               [12] 6907 	mov	a,@r0
      00226A C0 E0            [24] 6908 	push	acc
      00226C 08               [12] 6909 	inc	r0
      00226D E6               [12] 6910 	mov	a,@r0
      00226E C0 E0            [24] 6911 	push	acc
      002270 08               [12] 6912 	inc	r0
      002271 E6               [12] 6913 	mov	a,@r0
      002272 C0 E0            [24] 6914 	push	acc
      002274 08               [12] 6915 	inc	r0
      002275 E6               [12] 6916 	mov	a,@r0
      002276 C0 E0            [24] 6917 	push	acc
                           0021C1  6918 	C$fuzzy.h$2706$1_0$110 ==.
                                   6919 ;	../../fuzzy.h:2706: ) {
      002278 E5 08            [12] 6920 	mov	a,_bp
      00227A 24 08            [12] 6921 	add	a,#0x08
      00227C F8               [12] 6922 	mov	r0,a
      00227D 86 82            [24] 6923 	mov	dpl, @r0
      00227F 08               [12] 6924 	inc	r0
      002280 86 83            [24] 6925 	mov	dph, @r0
      002282 08               [12] 6926 	inc	r0
      002283 86 F0            [24] 6927 	mov	b, @r0
      002285 08               [12] 6928 	inc	r0
      002286 E6               [12] 6929 	mov	a, @r0
      002287 12 36 14         [24] 6930 	lcall	___fsadd
      00228A C8               [12] 6931 	xch	a,r0
      00228B E5 08            [12] 6932 	mov	a,_bp
      00228D 24 08            [12] 6933 	add	a,#0x08
      00228F C8               [12] 6934 	xch	a,r0
      002290 A6 82            [24] 6935 	mov	@r0, dpl
      002292 08               [12] 6936 	inc	r0
      002293 A6 83            [24] 6937 	mov	@r0, dph
      002295 08               [12] 6938 	inc	r0
      002296 A6 F0            [24] 6939 	mov	@r0, b
      002298 08               [12] 6940 	inc	r0
      002299 F6               [12] 6941 	mov	@r0,a
      00229A E5 81            [12] 6942 	mov	a,sp
      00229C 24 FC            [12] 6943 	add	a,#0xfc
      00229E F5 81            [12] 6944 	mov	sp,a
      0022A0 E5 08            [12] 6945 	mov	a,_bp
      0022A2 24 F2            [12] 6946 	add	a,#0xf2
      0022A4 F8               [12] 6947 	mov	r0,a
      0022A5 E6               [12] 6948 	mov	a,@r0
      0022A6 C0 E0            [24] 6949 	push	acc
      0022A8 08               [12] 6950 	inc	r0
      0022A9 E6               [12] 6951 	mov	a,@r0
      0022AA C0 E0            [24] 6952 	push	acc
      0022AC 08               [12] 6953 	inc	r0
      0022AD E6               [12] 6954 	mov	a,@r0
      0022AE C0 E0            [24] 6955 	push	acc
      0022B0 08               [12] 6956 	inc	r0
      0022B1 E6               [12] 6957 	mov	a,@r0
      0022B2 C0 E0            [24] 6958 	push	acc
      0022B4 E5 08            [12] 6959 	mov	a,_bp
      0022B6 24 0C            [12] 6960 	add	a,#0x0c
      0022B8 F8               [12] 6961 	mov	r0,a
      0022B9 86 82            [24] 6962 	mov	dpl, @r0
      0022BB 08               [12] 6963 	inc	r0
      0022BC 86 83            [24] 6964 	mov	dph, @r0
      0022BE 08               [12] 6965 	inc	r0
      0022BF 86 F0            [24] 6966 	mov	b, @r0
      0022C1 08               [12] 6967 	inc	r0
      0022C2 E6               [12] 6968 	mov	a, @r0
      0022C3 12 36 14         [24] 6969 	lcall	___fsadd
      0022C6 C8               [12] 6970 	xch	a,r0
      0022C7 E5 08            [12] 6971 	mov	a,_bp
      0022C9 24 0C            [12] 6972 	add	a,#0x0c
      0022CB C8               [12] 6973 	xch	a,r0
      0022CC A6 82            [24] 6974 	mov	@r0, dpl
      0022CE 08               [12] 6975 	inc	r0
      0022CF A6 83            [24] 6976 	mov	@r0, dph
      0022D1 08               [12] 6977 	inc	r0
      0022D2 A6 F0            [24] 6978 	mov	@r0, b
      0022D4 08               [12] 6979 	inc	r0
      0022D5 F6               [12] 6980 	mov	@r0,a
      0022D6 E5 81            [12] 6981 	mov	a,sp
      0022D8 24 FC            [12] 6982 	add	a,#0xfc
      0022DA F5 81            [12] 6983 	mov	sp,a
      0022DC 02 21 82         [24] 6984 	ljmp	00105$
      0022DF                       6985 00101$:
                           002228  6986 	C$fuzzy.h$2723$1_0$110 ==.
                                   6987 ;	../../fuzzy.h:2723: if (height_sum <= LEVEL_LO) {
      0022DF E5 08            [12] 6988 	mov	a,_bp
      0022E1 24 08            [12] 6989 	add	a,#0x08
      0022E3 F8               [12] 6990 	mov	r0,a
      0022E4 E6               [12] 6991 	mov	a,@r0
      0022E5 C0 E0            [24] 6992 	push	acc
      0022E7 08               [12] 6993 	inc	r0
      0022E8 E6               [12] 6994 	mov	a,@r0
      0022E9 C0 E0            [24] 6995 	push	acc
      0022EB 08               [12] 6996 	inc	r0
      0022EC E6               [12] 6997 	mov	a,@r0
      0022ED C0 E0            [24] 6998 	push	acc
      0022EF 08               [12] 6999 	inc	r0
      0022F0 E6               [12] 7000 	mov	a,@r0
      0022F1 C0 E0            [24] 7001 	push	acc
      0022F3 90 00 00         [24] 7002 	mov	dptr,#0x0000
      0022F6 E4               [12] 7003 	clr	a
      0022F7 F5 F0            [12] 7004 	mov	b,a
      0022F9 12 35 C2         [24] 7005 	lcall	___fslt
      0022FC E5 81            [12] 7006 	mov	a,sp
      0022FE 24 FC            [12] 7007 	add	a,#0xfc
      002300 F5 81            [12] 7008 	mov	sp,a
      002302 E5 82            [12] 7009 	mov	a, dpl
      002304 24 FF            [12] 7010 	add	a,#0xff
      002306 92 00            [24] 7011 	mov	b0,c
      002308 40 08            [24] 7012 	jc	00103$
                           002253  7013 	C$fuzzy.h$2724$2_0$113 ==.
                                   7014 ;	../../fuzzy.h:2724: return 0.0f;
      00230A 90 00 00         [24] 7015 	mov	dptr,#0x0000
      00230D E4               [12] 7016 	clr	a
      00230E F5 F0            [12] 7017 	mov	b,a
      002310 80 3A            [24] 7018 	sjmp	00107$
      002312                       7019 00103$:
                           00225B  7020 	C$fuzzy.h$2728$1_0$110 ==.
                                   7021 ;	../../fuzzy.h:2728: height_sum;
      002312 E5 08            [12] 7022 	mov	a,_bp
      002314 24 08            [12] 7023 	add	a,#0x08
      002316 F8               [12] 7024 	mov	r0,a
      002317 E6               [12] 7025 	mov	a,@r0
      002318 C0 E0            [24] 7026 	push	acc
      00231A 08               [12] 7027 	inc	r0
      00231B E6               [12] 7028 	mov	a,@r0
      00231C C0 E0            [24] 7029 	push	acc
      00231E 08               [12] 7030 	inc	r0
      00231F E6               [12] 7031 	mov	a,@r0
      002320 C0 E0            [24] 7032 	push	acc
      002322 08               [12] 7033 	inc	r0
      002323 E6               [12] 7034 	mov	a,@r0
      002324 C0 E0            [24] 7035 	push	acc
      002326 E5 08            [12] 7036 	mov	a,_bp
      002328 24 04            [12] 7037 	add	a,#0x04
      00232A F8               [12] 7038 	mov	r0,a
      00232B 86 82            [24] 7039 	mov	dpl, @r0
      00232D 08               [12] 7040 	inc	r0
      00232E 86 83            [24] 7041 	mov	dph, @r0
      002330 08               [12] 7042 	inc	r0
      002331 86 F0            [24] 7043 	mov	b, @r0
      002333 08               [12] 7044 	inc	r0
      002334 E6               [12] 7045 	mov	a, @r0
      002335 12 37 2B         [24] 7046 	lcall	___fsdiv
      002338 AC 82            [24] 7047 	mov	r4, dpl
      00233A AD 83            [24] 7048 	mov	r5, dph
      00233C AE F0            [24] 7049 	mov	r6, b
      00233E FF               [12] 7050 	mov	r7, a
      00233F E5 81            [12] 7051 	mov	a,sp
      002341 24 FC            [12] 7052 	add	a,#0xfc
      002343 F5 81            [12] 7053 	mov	sp,a
      002345 8C 82            [24] 7054 	mov	dpl, r4
      002347 8D 83            [24] 7055 	mov	dph, r5
      002349 8E F0            [24] 7056 	mov	b, r6
      00234B EF               [12] 7057 	mov	a, r7
      00234C                       7058 00107$:
                           002295  7059 	C$fuzzy.h$2729$1_0$110 ==.
                                   7060 ;	../../fuzzy.h:2729: }
      00234C 85 08 81         [24] 7061 	mov	sp,_bp
      00234F D0 08            [24] 7062 	pop	_bp
                           00229A  7063 	C$fuzzy.h$2729$1_0$110 ==.
                           00229A  7064 	XG$fuzzy_rules_defuzzify_cog$0$0 ==.
      002351 22               [24] 7065 	ret
                                   7066 ;------------------------------------------------------------
                                   7067 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_boa'
                                   7068 ;------------------------------------------------------------
                                   7069 ;lower         Allocated to stack - _bp -6 +4 
                                   7070 ;upper         Allocated to stack - _bp -10 +4 
                                   7071 ;step          Allocated to stack - _bp -14 +4 
                                   7072 ;implication_method Allocated to stack - _bp -15 +1 
                                   7073 ;aggregation_method Allocated to stack - _bp -16 +1 
                                   7074 ;rules         Allocated to stack - _bp +1 +3 
                                   7075 ;total_area    Allocated to stack - _bp +8 +4 
                                   7076 ;half_area     Allocated to stack - _bp +12 +4 
                                   7077 ;accumulated_area Allocated to stack - _bp +16 +4 
                                   7078 ;value         Allocated to stack - _bp +20 +4 
                                   7079 ;sloc0         Allocated to stack - _bp +4 +4 
                                   7080 ;------------------------------------------------------------
                           00229B  7081 	G$fuzzy_rules_defuzzify_boa$0$0 ==.
                           00229B  7082 	C$fuzzy.h$2739$1_0$115 ==.
                                   7083 ;	../../fuzzy.h:2739: float fuzzy_rules_defuzzify_boa(
                                   7084 ;	-----------------------------------------
                                   7085 ;	 function fuzzy_rules_defuzzify_boa
                                   7086 ;	-----------------------------------------
      002352                       7087 _fuzzy_rules_defuzzify_boa:
      002352 C0 08            [24] 7088 	push	_bp
      002354 85 81 08         [24] 7089 	mov	_bp,sp
      002357 C0 82            [24] 7090 	push	dpl
      002359 C0 83            [24] 7091 	push	dph
      00235B C0 F0            [24] 7092 	push	b
      00235D E5 81            [12] 7093 	mov	a,sp
      00235F 24 14            [12] 7094 	add	a,#0x14
      002361 F5 81            [12] 7095 	mov	sp,a
                           0022AC  7096 	C$fuzzy.h$2754$1_0$115 ==.
                                   7097 ;	../../fuzzy.h:2754: 0.0f;
      002363 E5 08            [12] 7098 	mov	a,_bp
      002365 24 08            [12] 7099 	add	a,#0x08
      002367 F8               [12] 7100 	mov	r0,a
      002368 E4               [12] 7101 	clr	a
      002369 F6               [12] 7102 	mov	@r0,a
      00236A 08               [12] 7103 	inc	r0
      00236B F6               [12] 7104 	mov	@r0,a
      00236C 08               [12] 7105 	inc	r0
      00236D F6               [12] 7106 	mov	@r0,a
      00236E 08               [12] 7107 	inc	r0
      00236F F6               [12] 7108 	mov	@r0,a
                           0022B9  7109 	C$fuzzy.h$2757$2_0$116 ==.
                                   7110 ;	../../fuzzy.h:2757: value = lower;
      002370 E5 08            [12] 7111 	mov	a,_bp
      002372 24 FA            [12] 7112 	add	a,#0xfa
      002374 F8               [12] 7113 	mov	r0,a
      002375 E5 08            [12] 7114 	mov	a,_bp
      002377 24 04            [12] 7115 	add	a,#0x04
      002379 F9               [12] 7116 	mov	r1,a
      00237A E6               [12] 7117 	mov	a,@r0
      00237B F7               [12] 7118 	mov	@r1,a
      00237C 08               [12] 7119 	inc	r0
      00237D E6               [12] 7120 	mov	a,@r0
      00237E 09               [12] 7121 	inc	r1
      00237F F7               [12] 7122 	mov	@r1,a
      002380 08               [12] 7123 	inc	r0
      002381 E6               [12] 7124 	mov	a,@r0
      002382 09               [12] 7125 	inc	r1
      002383 F7               [12] 7126 	mov	@r1,a
      002384 08               [12] 7127 	inc	r0
      002385 E6               [12] 7128 	mov	a,@r0
      002386 09               [12] 7129 	inc	r1
      002387 F7               [12] 7130 	mov	@r1,a
      002388                       7131 00108$:
                           0022D1  7132 	C$fuzzy.h$2758$1_0$115 ==.
                                   7133 ;	../../fuzzy.h:2758: value <= upper;
      002388 E5 08            [12] 7134 	mov	a,_bp
      00238A 24 04            [12] 7135 	add	a,#0x04
      00238C F8               [12] 7136 	mov	r0,a
      00238D E6               [12] 7137 	mov	a,@r0
      00238E C0 E0            [24] 7138 	push	acc
      002390 08               [12] 7139 	inc	r0
      002391 E6               [12] 7140 	mov	a,@r0
      002392 C0 E0            [24] 7141 	push	acc
      002394 08               [12] 7142 	inc	r0
      002395 E6               [12] 7143 	mov	a,@r0
      002396 C0 E0            [24] 7144 	push	acc
      002398 08               [12] 7145 	inc	r0
      002399 E6               [12] 7146 	mov	a,@r0
      00239A C0 E0            [24] 7147 	push	acc
      00239C E5 08            [12] 7148 	mov	a,_bp
      00239E 24 F6            [12] 7149 	add	a,#0xf6
      0023A0 F8               [12] 7150 	mov	r0,a
      0023A1 86 82            [24] 7151 	mov	dpl, @r0
      0023A3 08               [12] 7152 	inc	r0
      0023A4 86 83            [24] 7153 	mov	dph, @r0
      0023A6 08               [12] 7154 	inc	r0
      0023A7 86 F0            [24] 7155 	mov	b, @r0
      0023A9 08               [12] 7156 	inc	r0
      0023AA E6               [12] 7157 	mov	a, @r0
      0023AB 12 35 C2         [24] 7158 	lcall	___fslt
      0023AE E5 81            [12] 7159 	mov	a,sp
      0023B0 24 FC            [12] 7160 	add	a,#0xfc
      0023B2 F5 81            [12] 7161 	mov	sp,a
      0023B4 E5 82            [12] 7162 	mov	a, dpl
      0023B6 24 FF            [12] 7163 	add	a,#0xff
      0023B8 92 00            [24] 7164 	mov	b0,c
      0023BA 50 03            [24] 7165 	jnc	00157$
      0023BC 02 24 6D         [24] 7166 	ljmp	00101$
      0023BF                       7167 00157$:
                           002308  7168 	C$fuzzy.h$2763$3_0$117 ==.
                                   7169 ;	../../fuzzy.h:2763: rules,
      0023BF E5 08            [12] 7170 	mov	a,_bp
      0023C1 24 F0            [12] 7171 	add	a,#0xf0
      0023C3 F8               [12] 7172 	mov	r0,a
      0023C4 E6               [12] 7173 	mov	a,@r0
      0023C5 C0 E0            [24] 7174 	push	acc
      0023C7 E5 08            [12] 7175 	mov	a,_bp
      0023C9 24 F1            [12] 7176 	add	a,#0xf1
      0023CB F8               [12] 7177 	mov	r0,a
      0023CC E6               [12] 7178 	mov	a,@r0
      0023CD C0 E0            [24] 7179 	push	acc
      0023CF E5 08            [12] 7180 	mov	a,_bp
      0023D1 24 04            [12] 7181 	add	a,#0x04
      0023D3 F8               [12] 7182 	mov	r0,a
      0023D4 E6               [12] 7183 	mov	a,@r0
      0023D5 C0 E0            [24] 7184 	push	acc
      0023D7 08               [12] 7185 	inc	r0
      0023D8 E6               [12] 7186 	mov	a,@r0
      0023D9 C0 E0            [24] 7187 	push	acc
      0023DB 08               [12] 7188 	inc	r0
      0023DC E6               [12] 7189 	mov	a,@r0
      0023DD C0 E0            [24] 7190 	push	acc
      0023DF 08               [12] 7191 	inc	r0
      0023E0 E6               [12] 7192 	mov	a,@r0
      0023E1 C0 E0            [24] 7193 	push	acc
      0023E3 A8 08            [24] 7194 	mov	r0,_bp
      0023E5 08               [12] 7195 	inc	r0
      0023E6 86 82            [24] 7196 	mov	dpl, @r0
      0023E8 08               [12] 7197 	inc	r0
      0023E9 86 83            [24] 7198 	mov	dph, @r0
      0023EB 08               [12] 7199 	inc	r0
      0023EC 86 F0            [24] 7200 	mov	b, @r0
      0023EE 12 1B 98         [24] 7201 	lcall	_fuzzy_rules_aggregated_height
      0023F1 AC 82            [24] 7202 	mov	r4, dpl
      0023F3 AD 83            [24] 7203 	mov	r5, dph
      0023F5 AE F0            [24] 7204 	mov	r6, b
      0023F7 FF               [12] 7205 	mov	r7, a
      0023F8 E5 81            [12] 7206 	mov	a,sp
      0023FA 24 FA            [12] 7207 	add	a,#0xfa
      0023FC F5 81            [12] 7208 	mov	sp,a
      0023FE C0 04            [24] 7209 	push	ar4
      002400 C0 05            [24] 7210 	push	ar5
      002402 C0 06            [24] 7211 	push	ar6
      002404 C0 07            [24] 7212 	push	ar7
                           00234F  7213 	C$fuzzy.h$2760$1_0$115 ==.
                                   7214 ;	../../fuzzy.h:2760: ) {
      002406 E5 08            [12] 7215 	mov	a,_bp
      002408 24 08            [12] 7216 	add	a,#0x08
      00240A F8               [12] 7217 	mov	r0,a
      00240B 86 82            [24] 7218 	mov	dpl, @r0
      00240D 08               [12] 7219 	inc	r0
      00240E 86 83            [24] 7220 	mov	dph, @r0
      002410 08               [12] 7221 	inc	r0
      002411 86 F0            [24] 7222 	mov	b, @r0
      002413 08               [12] 7223 	inc	r0
      002414 E6               [12] 7224 	mov	a, @r0
      002415 12 36 14         [24] 7225 	lcall	___fsadd
      002418 C8               [12] 7226 	xch	a,r0
      002419 E5 08            [12] 7227 	mov	a,_bp
      00241B 24 08            [12] 7228 	add	a,#0x08
      00241D C8               [12] 7229 	xch	a,r0
      00241E A6 82            [24] 7230 	mov	@r0, dpl
      002420 08               [12] 7231 	inc	r0
      002421 A6 83            [24] 7232 	mov	@r0, dph
      002423 08               [12] 7233 	inc	r0
      002424 A6 F0            [24] 7234 	mov	@r0, b
      002426 08               [12] 7235 	inc	r0
      002427 F6               [12] 7236 	mov	@r0,a
      002428 E5 81            [12] 7237 	mov	a,sp
      00242A 24 FC            [12] 7238 	add	a,#0xfc
      00242C F5 81            [12] 7239 	mov	sp,a
      00242E E5 08            [12] 7240 	mov	a,_bp
      002430 24 F2            [12] 7241 	add	a,#0xf2
      002432 F8               [12] 7242 	mov	r0,a
      002433 E6               [12] 7243 	mov	a,@r0
      002434 C0 E0            [24] 7244 	push	acc
      002436 08               [12] 7245 	inc	r0
      002437 E6               [12] 7246 	mov	a,@r0
      002438 C0 E0            [24] 7247 	push	acc
      00243A 08               [12] 7248 	inc	r0
      00243B E6               [12] 7249 	mov	a,@r0
      00243C C0 E0            [24] 7250 	push	acc
      00243E 08               [12] 7251 	inc	r0
      00243F E6               [12] 7252 	mov	a,@r0
      002440 C0 E0            [24] 7253 	push	acc
      002442 E5 08            [12] 7254 	mov	a,_bp
      002444 24 04            [12] 7255 	add	a,#0x04
      002446 F8               [12] 7256 	mov	r0,a
      002447 86 82            [24] 7257 	mov	dpl, @r0
      002449 08               [12] 7258 	inc	r0
      00244A 86 83            [24] 7259 	mov	dph, @r0
      00244C 08               [12] 7260 	inc	r0
      00244D 86 F0            [24] 7261 	mov	b, @r0
      00244F 08               [12] 7262 	inc	r0
      002450 E6               [12] 7263 	mov	a, @r0
      002451 12 36 14         [24] 7264 	lcall	___fsadd
      002454 C8               [12] 7265 	xch	a,r0
      002455 E5 08            [12] 7266 	mov	a,_bp
      002457 24 04            [12] 7267 	add	a,#0x04
      002459 C8               [12] 7268 	xch	a,r0
      00245A A6 82            [24] 7269 	mov	@r0, dpl
      00245C 08               [12] 7270 	inc	r0
      00245D A6 83            [24] 7271 	mov	@r0, dph
      00245F 08               [12] 7272 	inc	r0
      002460 A6 F0            [24] 7273 	mov	@r0, b
      002462 08               [12] 7274 	inc	r0
      002463 F6               [12] 7275 	mov	@r0,a
      002464 E5 81            [12] 7276 	mov	a,sp
      002466 24 FC            [12] 7277 	add	a,#0xfc
      002468 F5 81            [12] 7278 	mov	sp,a
      00246A 02 23 88         [24] 7279 	ljmp	00108$
      00246D                       7280 00101$:
                           0023B6  7281 	C$fuzzy.h$2770$1_0$115 ==.
                                   7282 ;	../../fuzzy.h:2770: if (total_area <= LEVEL_LO) {
      00246D E5 08            [12] 7283 	mov	a,_bp
      00246F 24 08            [12] 7284 	add	a,#0x08
      002471 F8               [12] 7285 	mov	r0,a
      002472 E6               [12] 7286 	mov	a,@r0
      002473 C0 E0            [24] 7287 	push	acc
      002475 08               [12] 7288 	inc	r0
      002476 E6               [12] 7289 	mov	a,@r0
      002477 C0 E0            [24] 7290 	push	acc
      002479 08               [12] 7291 	inc	r0
      00247A E6               [12] 7292 	mov	a,@r0
      00247B C0 E0            [24] 7293 	push	acc
      00247D 08               [12] 7294 	inc	r0
      00247E E6               [12] 7295 	mov	a,@r0
      00247F C0 E0            [24] 7296 	push	acc
      002481 90 00 00         [24] 7297 	mov	dptr,#0x0000
      002484 E4               [12] 7298 	clr	a
      002485 F5 F0            [12] 7299 	mov	b,a
      002487 12 35 C2         [24] 7300 	lcall	___fslt
      00248A E5 81            [12] 7301 	mov	a,sp
      00248C 24 FC            [12] 7302 	add	a,#0xfc
      00248E F5 81            [12] 7303 	mov	sp,a
      002490 E5 82            [12] 7304 	mov	a, dpl
      002492 24 FF            [12] 7305 	add	a,#0xff
      002494 92 00            [24] 7306 	mov	b0,c
      002496 40 09            [24] 7307 	jc	00103$
                           0023E1  7308 	C$fuzzy.h$2771$2_0$118 ==.
                                   7309 ;	../../fuzzy.h:2771: return 0.0f;
      002498 90 00 00         [24] 7310 	mov	dptr,#0x0000
      00249B E4               [12] 7311 	clr	a
      00249C F5 F0            [12] 7312 	mov	b,a
      00249E 02 26 32         [24] 7313 	ljmp	00113$
      0024A1                       7314 00103$:
                           0023EA  7315 	C$fuzzy.h$2776$1_0$115 ==.
                                   7316 ;	../../fuzzy.h:2776: 2.0f;
      0024A1 E4               [12] 7317 	clr	a
      0024A2 C0 E0            [24] 7318 	push	acc
      0024A4 C0 E0            [24] 7319 	push	acc
      0024A6 C0 E0            [24] 7320 	push	acc
      0024A8 74 40            [12] 7321 	mov	a,#0x40
      0024AA C0 E0            [24] 7322 	push	acc
                           0023F5  7323 	C$fuzzy.h$2779$1_0$115 ==.
                                   7324 ;	../../fuzzy.h:2779: 0.0f;
      0024AC E5 08            [12] 7325 	mov	a,_bp
      0024AE 24 08            [12] 7326 	add	a,#0x08
      0024B0 F8               [12] 7327 	mov	r0,a
      0024B1 86 82            [24] 7328 	mov	dpl, @r0
      0024B3 08               [12] 7329 	inc	r0
      0024B4 86 83            [24] 7330 	mov	dph, @r0
      0024B6 08               [12] 7331 	inc	r0
      0024B7 86 F0            [24] 7332 	mov	b, @r0
      0024B9 08               [12] 7333 	inc	r0
      0024BA E6               [12] 7334 	mov	a, @r0
      0024BB 12 37 2B         [24] 7335 	lcall	___fsdiv
      0024BE C8               [12] 7336 	xch	a,r0
      0024BF E5 08            [12] 7337 	mov	a,_bp
      0024C1 24 0C            [12] 7338 	add	a,#0x0c
      0024C3 C8               [12] 7339 	xch	a,r0
      0024C4 A6 82            [24] 7340 	mov	@r0, dpl
      0024C6 08               [12] 7341 	inc	r0
      0024C7 A6 83            [24] 7342 	mov	@r0, dph
      0024C9 08               [12] 7343 	inc	r0
      0024CA A6 F0            [24] 7344 	mov	@r0, b
      0024CC 08               [12] 7345 	inc	r0
      0024CD F6               [12] 7346 	mov	@r0,a
      0024CE E5 81            [12] 7347 	mov	a,sp
      0024D0 24 FC            [12] 7348 	add	a,#0xfc
      0024D2 F5 81            [12] 7349 	mov	sp,a
      0024D4 E5 08            [12] 7350 	mov	a,_bp
      0024D6 24 10            [12] 7351 	add	a,#0x10
      0024D8 F8               [12] 7352 	mov	r0,a
      0024D9 E4               [12] 7353 	clr	a
      0024DA F6               [12] 7354 	mov	@r0,a
      0024DB 08               [12] 7355 	inc	r0
      0024DC F6               [12] 7356 	mov	@r0,a
      0024DD 08               [12] 7357 	inc	r0
      0024DE F6               [12] 7358 	mov	@r0,a
      0024DF 08               [12] 7359 	inc	r0
      0024E0 F6               [12] 7360 	mov	@r0,a
                           00242A  7361 	C$fuzzy.h$2782$2_0$119 ==.
                                   7362 ;	../../fuzzy.h:2782: value = lower;
      0024E1 E5 08            [12] 7363 	mov	a,_bp
      0024E3 24 FA            [12] 7364 	add	a,#0xfa
      0024E5 F8               [12] 7365 	mov	r0,a
      0024E6 E5 08            [12] 7366 	mov	a,_bp
      0024E8 24 14            [12] 7367 	add	a,#0x14
      0024EA F9               [12] 7368 	mov	r1,a
      0024EB E6               [12] 7369 	mov	a,@r0
      0024EC F7               [12] 7370 	mov	@r1,a
      0024ED 08               [12] 7371 	inc	r0
      0024EE E6               [12] 7372 	mov	a,@r0
      0024EF 09               [12] 7373 	inc	r1
      0024F0 F7               [12] 7374 	mov	@r1,a
      0024F1 08               [12] 7375 	inc	r0
      0024F2 E6               [12] 7376 	mov	a,@r0
      0024F3 09               [12] 7377 	inc	r1
      0024F4 F7               [12] 7378 	mov	@r1,a
      0024F5 08               [12] 7379 	inc	r0
      0024F6 E6               [12] 7380 	mov	a,@r0
      0024F7 09               [12] 7381 	inc	r1
      0024F8 F7               [12] 7382 	mov	@r1,a
      0024F9                       7383 00111$:
                           002442  7384 	C$fuzzy.h$2783$1_0$115 ==.
                                   7385 ;	../../fuzzy.h:2783: value <= upper;
      0024F9 E5 08            [12] 7386 	mov	a,_bp
      0024FB 24 14            [12] 7387 	add	a,#0x14
      0024FD F8               [12] 7388 	mov	r0,a
      0024FE E6               [12] 7389 	mov	a,@r0
      0024FF C0 E0            [24] 7390 	push	acc
      002501 08               [12] 7391 	inc	r0
      002502 E6               [12] 7392 	mov	a,@r0
      002503 C0 E0            [24] 7393 	push	acc
      002505 08               [12] 7394 	inc	r0
      002506 E6               [12] 7395 	mov	a,@r0
      002507 C0 E0            [24] 7396 	push	acc
      002509 08               [12] 7397 	inc	r0
      00250A E6               [12] 7398 	mov	a,@r0
      00250B C0 E0            [24] 7399 	push	acc
      00250D E5 08            [12] 7400 	mov	a,_bp
      00250F 24 F6            [12] 7401 	add	a,#0xf6
      002511 F8               [12] 7402 	mov	r0,a
      002512 86 82            [24] 7403 	mov	dpl, @r0
      002514 08               [12] 7404 	inc	r0
      002515 86 83            [24] 7405 	mov	dph, @r0
      002517 08               [12] 7406 	inc	r0
      002518 86 F0            [24] 7407 	mov	b, @r0
      00251A 08               [12] 7408 	inc	r0
      00251B E6               [12] 7409 	mov	a, @r0
      00251C 12 35 C2         [24] 7410 	lcall	___fslt
      00251F E5 81            [12] 7411 	mov	a,sp
      002521 24 FC            [12] 7412 	add	a,#0xfc
      002523 F5 81            [12] 7413 	mov	sp,a
      002525 E5 82            [12] 7414 	mov	a, dpl
      002527 24 FF            [12] 7415 	add	a,#0xff
      002529 92 00            [24] 7416 	mov	b0,c
      00252B 50 03            [24] 7417 	jnc	00159$
      00252D 02 26 23         [24] 7418 	ljmp	00106$
      002530                       7419 00159$:
                           002479  7420 	C$fuzzy.h$2788$3_0$120 ==.
                                   7421 ;	../../fuzzy.h:2788: rules,
      002530 E5 08            [12] 7422 	mov	a,_bp
      002532 24 F0            [12] 7423 	add	a,#0xf0
      002534 F8               [12] 7424 	mov	r0,a
      002535 E6               [12] 7425 	mov	a,@r0
      002536 C0 E0            [24] 7426 	push	acc
      002538 E5 08            [12] 7427 	mov	a,_bp
      00253A 24 F1            [12] 7428 	add	a,#0xf1
      00253C F8               [12] 7429 	mov	r0,a
      00253D E6               [12] 7430 	mov	a,@r0
      00253E C0 E0            [24] 7431 	push	acc
      002540 E5 08            [12] 7432 	mov	a,_bp
      002542 24 14            [12] 7433 	add	a,#0x14
      002544 F8               [12] 7434 	mov	r0,a
      002545 E6               [12] 7435 	mov	a,@r0
      002546 C0 E0            [24] 7436 	push	acc
      002548 08               [12] 7437 	inc	r0
      002549 E6               [12] 7438 	mov	a,@r0
      00254A C0 E0            [24] 7439 	push	acc
      00254C 08               [12] 7440 	inc	r0
      00254D E6               [12] 7441 	mov	a,@r0
      00254E C0 E0            [24] 7442 	push	acc
      002550 08               [12] 7443 	inc	r0
      002551 E6               [12] 7444 	mov	a,@r0
      002552 C0 E0            [24] 7445 	push	acc
      002554 A8 08            [24] 7446 	mov	r0,_bp
      002556 08               [12] 7447 	inc	r0
      002557 86 82            [24] 7448 	mov	dpl, @r0
      002559 08               [12] 7449 	inc	r0
      00255A 86 83            [24] 7450 	mov	dph, @r0
      00255C 08               [12] 7451 	inc	r0
      00255D 86 F0            [24] 7452 	mov	b, @r0
      00255F 12 1B 98         [24] 7453 	lcall	_fuzzy_rules_aggregated_height
      002562 AA 82            [24] 7454 	mov	r2, dpl
      002564 AB 83            [24] 7455 	mov	r3, dph
      002566 AE F0            [24] 7456 	mov	r6, b
      002568 FF               [12] 7457 	mov	r7, a
      002569 E5 81            [12] 7458 	mov	a,sp
      00256B 24 FA            [12] 7459 	add	a,#0xfa
      00256D F5 81            [12] 7460 	mov	sp,a
      00256F C0 02            [24] 7461 	push	ar2
      002571 C0 03            [24] 7462 	push	ar3
      002573 C0 06            [24] 7463 	push	ar6
      002575 C0 07            [24] 7464 	push	ar7
                           0024C0  7465 	C$fuzzy.h$2797$1_0$115 ==.
                                   7466 ;	../../fuzzy.h:2797: ) {
      002577 E5 08            [12] 7467 	mov	a,_bp
      002579 24 10            [12] 7468 	add	a,#0x10
      00257B F8               [12] 7469 	mov	r0,a
      00257C 86 82            [24] 7470 	mov	dpl, @r0
      00257E 08               [12] 7471 	inc	r0
      00257F 86 83            [24] 7472 	mov	dph, @r0
      002581 08               [12] 7473 	inc	r0
      002582 86 F0            [24] 7474 	mov	b, @r0
      002584 08               [12] 7475 	inc	r0
      002585 E6               [12] 7476 	mov	a, @r0
      002586 12 36 14         [24] 7477 	lcall	___fsadd
      002589 C8               [12] 7478 	xch	a,r0
      00258A E5 08            [12] 7479 	mov	a,_bp
      00258C 24 10            [12] 7480 	add	a,#0x10
      00258E C8               [12] 7481 	xch	a,r0
      00258F A6 82            [24] 7482 	mov	@r0, dpl
      002591 08               [12] 7483 	inc	r0
      002592 A6 83            [24] 7484 	mov	@r0, dph
      002594 08               [12] 7485 	inc	r0
      002595 A6 F0            [24] 7486 	mov	@r0, b
      002597 08               [12] 7487 	inc	r0
      002598 F6               [12] 7488 	mov	@r0,a
      002599 E5 81            [12] 7489 	mov	a,sp
      00259B 24 FC            [12] 7490 	add	a,#0xfc
      00259D F5 81            [12] 7491 	mov	sp,a
      00259F E5 08            [12] 7492 	mov	a,_bp
      0025A1 24 0C            [12] 7493 	add	a,#0x0c
      0025A3 F8               [12] 7494 	mov	r0,a
      0025A4 E6               [12] 7495 	mov	a,@r0
      0025A5 C0 E0            [24] 7496 	push	acc
      0025A7 08               [12] 7497 	inc	r0
      0025A8 E6               [12] 7498 	mov	a,@r0
      0025A9 C0 E0            [24] 7499 	push	acc
      0025AB 08               [12] 7500 	inc	r0
      0025AC E6               [12] 7501 	mov	a,@r0
      0025AD C0 E0            [24] 7502 	push	acc
      0025AF 08               [12] 7503 	inc	r0
      0025B0 E6               [12] 7504 	mov	a,@r0
      0025B1 C0 E0            [24] 7505 	push	acc
      0025B3 E5 08            [12] 7506 	mov	a,_bp
      0025B5 24 10            [12] 7507 	add	a,#0x10
      0025B7 F8               [12] 7508 	mov	r0,a
      0025B8 86 82            [24] 7509 	mov	dpl, @r0
      0025BA 08               [12] 7510 	inc	r0
      0025BB 86 83            [24] 7511 	mov	dph, @r0
      0025BD 08               [12] 7512 	inc	r0
      0025BE 86 F0            [24] 7513 	mov	b, @r0
      0025C0 08               [12] 7514 	inc	r0
      0025C1 E6               [12] 7515 	mov	a, @r0
      0025C2 12 35 C2         [24] 7516 	lcall	___fslt
      0025C5 E5 81            [12] 7517 	mov	a,sp
      0025C7 24 FC            [12] 7518 	add	a,#0xfc
      0025C9 F5 81            [12] 7519 	mov	sp,a
      0025CB E5 82            [12] 7520 	mov	a, dpl
      0025CD 24 FF            [12] 7521 	add	a,#0xff
      0025CF 92 00            [24] 7522 	mov	b0,c
      0025D1 40 11            [24] 7523 	jc	00112$
                           00251C  7524 	C$fuzzy.h$2798$4_0$121 ==.
                                   7525 ;	../../fuzzy.h:2798: return value;
      0025D3 E5 08            [12] 7526 	mov	a,_bp
      0025D5 24 14            [12] 7527 	add	a,#0x14
      0025D7 F8               [12] 7528 	mov	r0,a
      0025D8 86 82            [24] 7529 	mov	dpl, @r0
      0025DA 08               [12] 7530 	inc	r0
      0025DB 86 83            [24] 7531 	mov	dph, @r0
      0025DD 08               [12] 7532 	inc	r0
      0025DE 86 F0            [24] 7533 	mov	b, @r0
      0025E0 08               [12] 7534 	inc	r0
      0025E1 E6               [12] 7535 	mov	a, @r0
      0025E2 80 4E            [24] 7536 	sjmp	00113$
      0025E4                       7537 00112$:
                           00252D  7538 	C$fuzzy.h$2785$1_0$115 ==.
                                   7539 ;	../../fuzzy.h:2785: ) {
      0025E4 E5 08            [12] 7540 	mov	a,_bp
      0025E6 24 F2            [12] 7541 	add	a,#0xf2
      0025E8 F8               [12] 7542 	mov	r0,a
      0025E9 E6               [12] 7543 	mov	a,@r0
      0025EA C0 E0            [24] 7544 	push	acc
      0025EC 08               [12] 7545 	inc	r0
      0025ED E6               [12] 7546 	mov	a,@r0
      0025EE C0 E0            [24] 7547 	push	acc
      0025F0 08               [12] 7548 	inc	r0
      0025F1 E6               [12] 7549 	mov	a,@r0
      0025F2 C0 E0            [24] 7550 	push	acc
      0025F4 08               [12] 7551 	inc	r0
      0025F5 E6               [12] 7552 	mov	a,@r0
      0025F6 C0 E0            [24] 7553 	push	acc
      0025F8 E5 08            [12] 7554 	mov	a,_bp
      0025FA 24 14            [12] 7555 	add	a,#0x14
      0025FC F8               [12] 7556 	mov	r0,a
      0025FD 86 82            [24] 7557 	mov	dpl, @r0
      0025FF 08               [12] 7558 	inc	r0
      002600 86 83            [24] 7559 	mov	dph, @r0
      002602 08               [12] 7560 	inc	r0
      002603 86 F0            [24] 7561 	mov	b, @r0
      002605 08               [12] 7562 	inc	r0
      002606 E6               [12] 7563 	mov	a, @r0
      002607 12 36 14         [24] 7564 	lcall	___fsadd
      00260A C8               [12] 7565 	xch	a,r0
      00260B E5 08            [12] 7566 	mov	a,_bp
      00260D 24 14            [12] 7567 	add	a,#0x14
      00260F C8               [12] 7568 	xch	a,r0
      002610 A6 82            [24] 7569 	mov	@r0, dpl
      002612 08               [12] 7570 	inc	r0
      002613 A6 83            [24] 7571 	mov	@r0, dph
      002615 08               [12] 7572 	inc	r0
      002616 A6 F0            [24] 7573 	mov	@r0, b
      002618 08               [12] 7574 	inc	r0
      002619 F6               [12] 7575 	mov	@r0,a
      00261A E5 81            [12] 7576 	mov	a,sp
      00261C 24 FC            [12] 7577 	add	a,#0xfc
      00261E F5 81            [12] 7578 	mov	sp,a
      002620 02 24 F9         [24] 7579 	ljmp	00111$
      002623                       7580 00106$:
                           00256C  7581 	C$fuzzy.h$2802$1_0$115 ==.
                                   7582 ;	../../fuzzy.h:2802: return upper;
      002623 E5 08            [12] 7583 	mov	a,_bp
      002625 24 F6            [12] 7584 	add	a,#0xf6
      002627 F8               [12] 7585 	mov	r0,a
      002628 86 82            [24] 7586 	mov	dpl, @r0
      00262A 08               [12] 7587 	inc	r0
      00262B 86 83            [24] 7588 	mov	dph, @r0
      00262D 08               [12] 7589 	inc	r0
      00262E 86 F0            [24] 7590 	mov	b, @r0
      002630 08               [12] 7591 	inc	r0
      002631 E6               [12] 7592 	mov	a, @r0
      002632                       7593 00113$:
                           00257B  7594 	C$fuzzy.h$2803$1_0$115 ==.
                                   7595 ;	../../fuzzy.h:2803: }
      002632 85 08 81         [24] 7596 	mov	sp,_bp
      002635 D0 08            [24] 7597 	pop	_bp
                           002580  7598 	C$fuzzy.h$2803$1_0$115 ==.
                           002580  7599 	XG$fuzzy_rules_defuzzify_boa$0$0 ==.
      002637 22               [24] 7600 	ret
                                   7601 ;------------------------------------------------------------
                                   7602 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_cos'
                                   7603 ;------------------------------------------------------------
                                   7604 ;lower         Allocated to stack - _bp -6 +4 
                                   7605 ;upper         Allocated to stack - _bp -10 +4 
                                   7606 ;step          Allocated to stack - _bp -14 +4 
                                   7607 ;implication_method Allocated to stack - _bp -15 +1 
                                   7608 ;rules         Allocated to stack - _bp +1 +3 
                                   7609 ;weighted_sum  Allocated to stack - _bp +9 +4 
                                   7610 ;height_sum    Allocated to stack - _bp +13 +4 
                                   7611 ;value         Allocated to stack - _bp +17 +4 
                                   7612 ;output_membership Allocated to stack - _bp +21 +4 
                                   7613 ;implied_height Allocated to stack - _bp +25 +4 
                                   7614 ;index         Allocated to stack - _bp +29 +2 
                                   7615 ;sloc0         Allocated to stack - _bp +4 +3 
                                   7616 ;sloc1         Allocated to stack - _bp +7 +2 
                                   7617 ;------------------------------------------------------------
                           002581  7618 	G$fuzzy_rules_defuzzify_cos$0$0 ==.
                           002581  7619 	C$fuzzy.h$2815$1_0$123 ==.
                                   7620 ;	../../fuzzy.h:2815: float fuzzy_rules_defuzzify_cos(
                                   7621 ;	-----------------------------------------
                                   7622 ;	 function fuzzy_rules_defuzzify_cos
                                   7623 ;	-----------------------------------------
      002638                       7624 _fuzzy_rules_defuzzify_cos:
      002638 C0 08            [24] 7625 	push	_bp
      00263A 85 81 08         [24] 7626 	mov	_bp,sp
      00263D C0 82            [24] 7627 	push	dpl
      00263F C0 83            [24] 7628 	push	dph
      002641 C0 F0            [24] 7629 	push	b
      002643 E5 81            [12] 7630 	mov	a,sp
      002645 24 1B            [12] 7631 	add	a,#0x1b
      002647 F5 81            [12] 7632 	mov	sp,a
                           002592  7633 	C$fuzzy.h$2831$1_0$123 ==.
                                   7634 ;	../../fuzzy.h:2831: 0.0f;
      002649 E5 08            [12] 7635 	mov	a,_bp
      00264B 24 09            [12] 7636 	add	a,#0x09
      00264D F8               [12] 7637 	mov	r0,a
      00264E E4               [12] 7638 	clr	a
      00264F F6               [12] 7639 	mov	@r0,a
      002650 08               [12] 7640 	inc	r0
      002651 F6               [12] 7641 	mov	@r0,a
      002652 08               [12] 7642 	inc	r0
      002653 F6               [12] 7643 	mov	@r0,a
      002654 08               [12] 7644 	inc	r0
      002655 F6               [12] 7645 	mov	@r0,a
                           00259F  7646 	C$fuzzy.h$2834$1_0$123 ==.
                                   7647 ;	../../fuzzy.h:2834: 0.0f;
      002656 E5 08            [12] 7648 	mov	a,_bp
      002658 24 0D            [12] 7649 	add	a,#0x0d
      00265A F8               [12] 7650 	mov	r0,a
      00265B E4               [12] 7651 	clr	a
      00265C F6               [12] 7652 	mov	@r0,a
      00265D 08               [12] 7653 	inc	r0
      00265E F6               [12] 7654 	mov	@r0,a
      00265F 08               [12] 7655 	inc	r0
      002660 F6               [12] 7656 	mov	@r0,a
      002661 08               [12] 7657 	inc	r0
      002662 F6               [12] 7658 	mov	@r0,a
                           0025AC  7659 	C$fuzzy.h$2837$2_0$124 ==.
                                   7660 ;	../../fuzzy.h:2837: value = lower;
      002663 E5 08            [12] 7661 	mov	a,_bp
      002665 24 FA            [12] 7662 	add	a,#0xfa
      002667 F8               [12] 7663 	mov	r0,a
      002668 E5 08            [12] 7664 	mov	a,_bp
      00266A 24 11            [12] 7665 	add	a,#0x11
      00266C F9               [12] 7666 	mov	r1,a
      00266D E6               [12] 7667 	mov	a,@r0
      00266E F7               [12] 7668 	mov	@r1,a
      00266F 08               [12] 7669 	inc	r0
      002670 E6               [12] 7670 	mov	a,@r0
      002671 09               [12] 7671 	inc	r1
      002672 F7               [12] 7672 	mov	@r1,a
      002673 08               [12] 7673 	inc	r0
      002674 E6               [12] 7674 	mov	a,@r0
      002675 09               [12] 7675 	inc	r1
      002676 F7               [12] 7676 	mov	@r1,a
      002677 08               [12] 7677 	inc	r0
      002678 E6               [12] 7678 	mov	a,@r0
      002679 09               [12] 7679 	inc	r1
      00267A F7               [12] 7680 	mov	@r1,a
      00267B A8 08            [24] 7681 	mov	r0,_bp
      00267D 08               [12] 7682 	inc	r0
      00267E E5 08            [12] 7683 	mov	a,_bp
      002680 24 04            [12] 7684 	add	a,#0x04
      002682 F9               [12] 7685 	mov	r1,a
      002683 E6               [12] 7686 	mov	a,@r0
      002684 F7               [12] 7687 	mov	@r1,a
      002685 08               [12] 7688 	inc	r0
      002686 E6               [12] 7689 	mov	a,@r0
      002687 09               [12] 7690 	inc	r1
      002688 F7               [12] 7691 	mov	@r1,a
      002689 08               [12] 7692 	inc	r0
      00268A E6               [12] 7693 	mov	a,@r0
      00268B 09               [12] 7694 	inc	r1
      00268C F7               [12] 7695 	mov	@r1,a
      00268D A8 08            [24] 7696 	mov	r0,_bp
      00268F 08               [12] 7697 	inc	r0
      002690 74 90            [12] 7698 	mov	a,#0x90
      002692 26               [12] 7699 	add	a, @r0
      002693 FC               [12] 7700 	mov	r4,a
      002694 E4               [12] 7701 	clr	a
      002695 08               [12] 7702 	inc	r0
      002696 36               [12] 7703 	addc	a, @r0
      002697 FD               [12] 7704 	mov	r5,a
      002698 08               [12] 7705 	inc	r0
      002699 86 06            [24] 7706 	mov	ar6,@r0
      00269B                       7707 00109$:
                           0025E4  7708 	C$fuzzy.h$2838$1_0$123 ==.
                                   7709 ;	../../fuzzy.h:2838: value <= upper;
      00269B C0 06            [24] 7710 	push	ar6
      00269D C0 05            [24] 7711 	push	ar5
      00269F C0 04            [24] 7712 	push	ar4
      0026A1 E5 08            [12] 7713 	mov	a,_bp
      0026A3 24 11            [12] 7714 	add	a,#0x11
      0026A5 F8               [12] 7715 	mov	r0,a
      0026A6 E6               [12] 7716 	mov	a,@r0
      0026A7 C0 E0            [24] 7717 	push	acc
      0026A9 08               [12] 7718 	inc	r0
      0026AA E6               [12] 7719 	mov	a,@r0
      0026AB C0 E0            [24] 7720 	push	acc
      0026AD 08               [12] 7721 	inc	r0
      0026AE E6               [12] 7722 	mov	a,@r0
      0026AF C0 E0            [24] 7723 	push	acc
      0026B1 08               [12] 7724 	inc	r0
      0026B2 E6               [12] 7725 	mov	a,@r0
      0026B3 C0 E0            [24] 7726 	push	acc
      0026B5 E5 08            [12] 7727 	mov	a,_bp
      0026B7 24 F6            [12] 7728 	add	a,#0xf6
      0026B9 F8               [12] 7729 	mov	r0,a
      0026BA 86 82            [24] 7730 	mov	dpl, @r0
      0026BC 08               [12] 7731 	inc	r0
      0026BD 86 83            [24] 7732 	mov	dph, @r0
      0026BF 08               [12] 7733 	inc	r0
      0026C0 86 F0            [24] 7734 	mov	b, @r0
      0026C2 08               [12] 7735 	inc	r0
      0026C3 E6               [12] 7736 	mov	a, @r0
      0026C4 12 35 C2         [24] 7737 	lcall	___fslt
      0026C7 E5 81            [12] 7738 	mov	a,sp
      0026C9 24 FC            [12] 7739 	add	a,#0xfc
      0026CB F5 81            [12] 7740 	mov	sp,a
      0026CD D0 04            [24] 7741 	pop	ar4
      0026CF D0 05            [24] 7742 	pop	ar5
      0026D1 D0 06            [24] 7743 	pop	ar6
      0026D3 E5 82            [12] 7744 	mov	a, dpl
      0026D5 24 FF            [12] 7745 	add	a,#0xff
      0026D7 92 00            [24] 7746 	mov	b0,c
      0026D9 50 03            [24] 7747 	jnc	00144$
      0026DB 02 29 28         [24] 7748 	ljmp	00102$
      0026DE                       7749 00144$:
                           002627  7750 	C$fuzzy.h$2842$1_0$123 ==.
                                   7751 ;	../../fuzzy.h:2842: index = 0u;
      0026DE E5 08            [12] 7752 	mov	a,_bp
      0026E0 24 1D            [12] 7753 	add	a,#0x1d
      0026E2 F8               [12] 7754 	mov	r0,a
      0026E3 E4               [12] 7755 	clr	a
      0026E4 F6               [12] 7756 	mov	@r0,a
      0026E5 08               [12] 7757 	inc	r0
      0026E6 F6               [12] 7758 	mov	@r0,a
      0026E7 E5 08            [12] 7759 	mov	a,_bp
      0026E9 24 07            [12] 7760 	add	a,#0x07
      0026EB F8               [12] 7761 	mov	r0,a
      0026EC E4               [12] 7762 	clr	a
      0026ED F6               [12] 7763 	mov	@r0,a
      0026EE 08               [12] 7764 	inc	r0
      0026EF F6               [12] 7765 	mov	@r0,a
      0026F0                       7766 00106$:
                           002639  7767 	C$fuzzy.h$2843$4_0$126 ==.
                                   7768 ;	../../fuzzy.h:2843: index < rules->count;
      0026F0 8C 82            [24] 7769 	mov	dpl,r4
      0026F2 8D 83            [24] 7770 	mov	dph,r5
      0026F4 8E F0            [24] 7771 	mov	b,r6
      0026F6 12 37 EE         [24] 7772 	lcall	__gptrget
      0026F9 FA               [12] 7773 	mov	r2,a
      0026FA A3               [24] 7774 	inc	dptr
      0026FB 12 37 EE         [24] 7775 	lcall	__gptrget
      0026FE FF               [12] 7776 	mov	r7,a
      0026FF E5 08            [12] 7777 	mov	a,_bp
      002701 24 1D            [12] 7778 	add	a,#0x1d
      002703 F8               [12] 7779 	mov	r0,a
      002704 C3               [12] 7780 	clr	c
      002705 E6               [12] 7781 	mov	a,@r0
      002706 9A               [12] 7782 	subb	a,r2
      002707 08               [12] 7783 	inc	r0
      002708 E6               [12] 7784 	mov	a,@r0
      002709 9F               [12] 7785 	subb	a,r7
      00270A 40 03            [24] 7786 	jc	00145$
      00270C 02 28 DD         [24] 7787 	ljmp	00110$
      00270F                       7788 00145$:
                           002658  7789 	C$fuzzy.h$2848$1_0$123 ==.
                                   7790 ;	../../fuzzy.h:2848: rules->rules[index]
      00270F C0 04            [24] 7791 	push	ar4
      002711 C0 05            [24] 7792 	push	ar5
      002713 C0 06            [24] 7793 	push	ar6
      002715 E5 08            [12] 7794 	mov	a,_bp
      002717 24 04            [12] 7795 	add	a,#0x04
      002719 F8               [12] 7796 	mov	r0,a
      00271A E5 08            [12] 7797 	mov	a,_bp
      00271C 24 07            [12] 7798 	add	a,#0x07
      00271E F9               [12] 7799 	mov	r1,a
      00271F E7               [12] 7800 	mov	a,@r1
      002720 26               [12] 7801 	add	a, @r0
      002721 FA               [12] 7802 	mov	r2,a
      002722 09               [12] 7803 	inc	r1
      002723 E7               [12] 7804 	mov	a,@r1
      002724 08               [12] 7805 	inc	r0
      002725 36               [12] 7806 	addc	a, @r0
      002726 FB               [12] 7807 	mov	r3,a
      002727 08               [12] 7808 	inc	r0
      002728 86 07            [24] 7809 	mov	ar7,@r0
      00272A 74 07            [12] 7810 	mov	a,#0x07
      00272C 2A               [12] 7811 	add	a, r2
      00272D FA               [12] 7812 	mov	r2,a
      00272E E4               [12] 7813 	clr	a
      00272F 3B               [12] 7814 	addc	a, r3
      002730 FB               [12] 7815 	mov	r3,a
      002731 8A 82            [24] 7816 	mov	dpl,r2
      002733 8B 83            [24] 7817 	mov	dph,r3
      002735 8F F0            [24] 7818 	mov	b,r7
      002737 12 37 EE         [24] 7819 	lcall	__gptrget
      00273A FA               [12] 7820 	mov	r2,a
      00273B A3               [24] 7821 	inc	dptr
      00273C 12 37 EE         [24] 7822 	lcall	__gptrget
      00273F FB               [12] 7823 	mov	r3,a
                           002689  7824 	C$fuzzy.h$2849$5_0$127 ==.
                                   7825 ;	../../fuzzy.h:2849: .output_function(value)
      002740 C0 05            [24] 7826 	push	ar5
      002742 C0 04            [24] 7827 	push	ar4
      002744 12 27 49         [24] 7828 	lcall	00146$
      002747 80 14            [24] 7829 	sjmp	00147$
      002749                       7830 00146$:
      002749 C0 02            [24] 7831 	push	ar2
      00274B C0 03            [24] 7832 	push	ar3
      00274D E5 08            [12] 7833 	mov	a,_bp
      00274F 24 11            [12] 7834 	add	a,#0x11
      002751 F8               [12] 7835 	mov	r0,a
      002752 86 82            [24] 7836 	mov	dpl, @r0
      002754 08               [12] 7837 	inc	r0
      002755 86 83            [24] 7838 	mov	dph, @r0
      002757 08               [12] 7839 	inc	r0
      002758 86 F0            [24] 7840 	mov	b, @r0
      00275A 08               [12] 7841 	inc	r0
      00275B E6               [12] 7842 	mov	a, @r0
      00275C 22               [24] 7843 	ret
      00275D                       7844 00147$:
      00275D AA 82            [24] 7845 	mov	r2, dpl
      00275F AB 83            [24] 7846 	mov	r3, dph
      002761 AE F0            [24] 7847 	mov	r6, b
      002763 FF               [12] 7848 	mov	r7, a
      002764 D0 04            [24] 7849 	pop	ar4
      002766 D0 05            [24] 7850 	pop	ar5
      002768 8A 82            [24] 7851 	mov	dpl, r2
      00276A 8B 83            [24] 7852 	mov	dph, r3
      00276C 8E F0            [24] 7853 	mov	b, r6
      00276E EF               [12] 7854 	mov	a, r7
      00276F C0 06            [24] 7855 	push	ar6
      002771 C0 05            [24] 7856 	push	ar5
      002773 C0 04            [24] 7857 	push	ar4
      002775 12 00 EA         [24] 7858 	lcall	_fuzzy_clamp
      002778 C8               [12] 7859 	xch	a,r0
      002779 E5 08            [12] 7860 	mov	a,_bp
      00277B 24 15            [12] 7861 	add	a,#0x15
      00277D C8               [12] 7862 	xch	a,r0
      00277E A6 82            [24] 7863 	mov	@r0, dpl
      002780 08               [12] 7864 	inc	r0
      002781 A6 83            [24] 7865 	mov	@r0, dph
      002783 08               [12] 7866 	inc	r0
      002784 A6 F0            [24] 7867 	mov	@r0, b
      002786 08               [12] 7868 	inc	r0
      002787 F6               [12] 7869 	mov	@r0,a
      002788 D0 04            [24] 7870 	pop	ar4
      00278A D0 05            [24] 7871 	pop	ar5
      00278C D0 06            [24] 7872 	pop	ar6
                           0026D7  7873 	C$fuzzy.h$2855$5_0$127 ==.
                                   7874 ;	../../fuzzy.h:2855: rules->rules[index].value,
      00278E A8 08            [24] 7875 	mov	r0,_bp
      002790 08               [12] 7876 	inc	r0
      002791 E5 08            [12] 7877 	mov	a,_bp
      002793 24 07            [12] 7878 	add	a,#0x07
      002795 F9               [12] 7879 	mov	r1,a
      002796 E7               [12] 7880 	mov	a,@r1
      002797 26               [12] 7881 	add	a, @r0
      002798 FA               [12] 7882 	mov	r2,a
      002799 09               [12] 7883 	inc	r1
      00279A E7               [12] 7884 	mov	a,@r1
      00279B 08               [12] 7885 	inc	r0
      00279C 36               [12] 7886 	addc	a, @r0
      00279D FB               [12] 7887 	mov	r3,a
      00279E 08               [12] 7888 	inc	r0
      00279F 86 07            [24] 7889 	mov	ar7,@r0
      0027A1 74 03            [12] 7890 	mov	a,#0x03
      0027A3 2A               [12] 7891 	add	a, r2
      0027A4 FA               [12] 7892 	mov	r2,a
      0027A5 E4               [12] 7893 	clr	a
      0027A6 3B               [12] 7894 	addc	a, r3
      0027A7 FB               [12] 7895 	mov	r3,a
      0027A8 8A 82            [24] 7896 	mov	dpl,r2
      0027AA 8B 83            [24] 7897 	mov	dph,r3
      0027AC 8F F0            [24] 7898 	mov	b,r7
      0027AE 12 37 EE         [24] 7899 	lcall	__gptrget
      0027B1 FA               [12] 7900 	mov	r2,a
      0027B2 A3               [24] 7901 	inc	dptr
      0027B3 12 37 EE         [24] 7902 	lcall	__gptrget
      0027B6 FB               [12] 7903 	mov	r3,a
      0027B7 A3               [24] 7904 	inc	dptr
      0027B8 12 37 EE         [24] 7905 	lcall	__gptrget
      0027BB FF               [12] 7906 	mov	r7,a
      0027BC A3               [24] 7907 	inc	dptr
      0027BD 12 37 EE         [24] 7908 	lcall	__gptrget
      0027C0 FE               [12] 7909 	mov	r6,a
                           00270A  7910 	C$fuzzy.h$2854$5_0$127 ==.
                                   7911 ;	../../fuzzy.h:2854: implication_method,
      0027C1 C0 06            [24] 7912 	push	ar6
      0027C3 C0 05            [24] 7913 	push	ar5
      0027C5 C0 04            [24] 7914 	push	ar4
      0027C7 E5 08            [12] 7915 	mov	a,_bp
      0027C9 24 15            [12] 7916 	add	a,#0x15
      0027CB F8               [12] 7917 	mov	r0,a
      0027CC E6               [12] 7918 	mov	a,@r0
      0027CD C0 E0            [24] 7919 	push	acc
      0027CF 08               [12] 7920 	inc	r0
      0027D0 E6               [12] 7921 	mov	a,@r0
      0027D1 C0 E0            [24] 7922 	push	acc
      0027D3 08               [12] 7923 	inc	r0
      0027D4 E6               [12] 7924 	mov	a,@r0
      0027D5 C0 E0            [24] 7925 	push	acc
      0027D7 08               [12] 7926 	inc	r0
      0027D8 E6               [12] 7927 	mov	a,@r0
      0027D9 C0 E0            [24] 7928 	push	acc
      0027DB C0 02            [24] 7929 	push	ar2
      0027DD C0 03            [24] 7930 	push	ar3
      0027DF C0 07            [24] 7931 	push	ar7
      0027E1 C0 06            [24] 7932 	push	ar6
      0027E3 E5 08            [12] 7933 	mov	a,_bp
      0027E5 24 F1            [12] 7934 	add	a,#0xf1
      0027E7 F8               [12] 7935 	mov	r0,a
      0027E8 86 82            [24] 7936 	mov	dpl, @r0
      0027EA 12 18 D1         [24] 7937 	lcall	_fuzzy_implication
      0027ED C8               [12] 7938 	xch	a,r0
      0027EE E5 08            [12] 7939 	mov	a,_bp
      0027F0 24 19            [12] 7940 	add	a,#0x19
      0027F2 C8               [12] 7941 	xch	a,r0
      0027F3 A6 82            [24] 7942 	mov	@r0, dpl
      0027F5 08               [12] 7943 	inc	r0
      0027F6 A6 83            [24] 7944 	mov	@r0, dph
      0027F8 08               [12] 7945 	inc	r0
      0027F9 A6 F0            [24] 7946 	mov	@r0, b
      0027FB 08               [12] 7947 	inc	r0
      0027FC F6               [12] 7948 	mov	@r0,a
      0027FD E5 81            [12] 7949 	mov	a,sp
      0027FF 24 F8            [12] 7950 	add	a,#0xf8
      002801 F5 81            [12] 7951 	mov	sp,a
      002803 D0 04            [24] 7952 	pop	ar4
      002805 D0 05            [24] 7953 	pop	ar5
      002807 D0 06            [24] 7954 	pop	ar6
                           002752  7955 	C$fuzzy.h$2861$1_0$123 ==.
                                   7956 ;	../../fuzzy.h:2861: implied_height;
      002809 C0 05            [24] 7957 	push	ar5
      00280B C0 04            [24] 7958 	push	ar4
      00280D E5 08            [12] 7959 	mov	a,_bp
      00280F 24 19            [12] 7960 	add	a,#0x19
      002811 F8               [12] 7961 	mov	r0,a
      002812 E6               [12] 7962 	mov	a,@r0
      002813 C0 E0            [24] 7963 	push	acc
      002815 08               [12] 7964 	inc	r0
      002816 E6               [12] 7965 	mov	a,@r0
      002817 C0 E0            [24] 7966 	push	acc
      002819 08               [12] 7967 	inc	r0
      00281A E6               [12] 7968 	mov	a,@r0
      00281B C0 E0            [24] 7969 	push	acc
      00281D 08               [12] 7970 	inc	r0
      00281E E6               [12] 7971 	mov	a,@r0
      00281F C0 E0            [24] 7972 	push	acc
      002821 E5 08            [12] 7973 	mov	a,_bp
      002823 24 11            [12] 7974 	add	a,#0x11
      002825 F8               [12] 7975 	mov	r0,a
      002826 86 82            [24] 7976 	mov	dpl, @r0
      002828 08               [12] 7977 	inc	r0
      002829 86 83            [24] 7978 	mov	dph, @r0
      00282B 08               [12] 7979 	inc	r0
      00282C 86 F0            [24] 7980 	mov	b, @r0
      00282E 08               [12] 7981 	inc	r0
      00282F E6               [12] 7982 	mov	a, @r0
      002830 12 34 92         [24] 7983 	lcall	___fsmul
      002833 AA 82            [24] 7984 	mov	r2, dpl
      002835 AB 83            [24] 7985 	mov	r3, dph
      002837 AE F0            [24] 7986 	mov	r6, b
      002839 FF               [12] 7987 	mov	r7, a
      00283A E5 81            [12] 7988 	mov	a,sp
      00283C 24 FC            [12] 7989 	add	a,#0xfc
      00283E F5 81            [12] 7990 	mov	sp,a
      002840 D0 04            [24] 7991 	pop	ar4
      002842 D0 05            [24] 7992 	pop	ar5
      002844 C0 06            [24] 7993 	push	ar6
      002846 C0 05            [24] 7994 	push	ar5
      002848 C0 04            [24] 7995 	push	ar4
      00284A C0 02            [24] 7996 	push	ar2
      00284C C0 03            [24] 7997 	push	ar3
      00284E C0 06            [24] 7998 	push	ar6
      002850 C0 07            [24] 7999 	push	ar7
                           00279B  8000 	C$fuzzy.h$2864$1_0$123 ==.
                                   8001 ;	../../fuzzy.h:2864: implied_height;
      002852 E5 08            [12] 8002 	mov	a,_bp
      002854 24 09            [12] 8003 	add	a,#0x09
      002856 F8               [12] 8004 	mov	r0,a
      002857 86 82            [24] 8005 	mov	dpl, @r0
      002859 08               [12] 8006 	inc	r0
      00285A 86 83            [24] 8007 	mov	dph, @r0
      00285C 08               [12] 8008 	inc	r0
      00285D 86 F0            [24] 8009 	mov	b, @r0
      00285F 08               [12] 8010 	inc	r0
      002860 E6               [12] 8011 	mov	a, @r0
      002861 12 36 14         [24] 8012 	lcall	___fsadd
      002864 C8               [12] 8013 	xch	a,r0
      002865 E5 08            [12] 8014 	mov	a,_bp
      002867 24 09            [12] 8015 	add	a,#0x09
      002869 C8               [12] 8016 	xch	a,r0
      00286A A6 82            [24] 8017 	mov	@r0, dpl
      00286C 08               [12] 8018 	inc	r0
      00286D A6 83            [24] 8019 	mov	@r0, dph
      00286F 08               [12] 8020 	inc	r0
      002870 A6 F0            [24] 8021 	mov	@r0, b
      002872 08               [12] 8022 	inc	r0
      002873 F6               [12] 8023 	mov	@r0,a
      002874 E5 81            [12] 8024 	mov	a,sp
      002876 24 FC            [12] 8025 	add	a,#0xfc
      002878 F5 81            [12] 8026 	mov	sp,a
      00287A E5 08            [12] 8027 	mov	a,_bp
      00287C 24 19            [12] 8028 	add	a,#0x19
      00287E F8               [12] 8029 	mov	r0,a
      00287F E6               [12] 8030 	mov	a,@r0
      002880 C0 E0            [24] 8031 	push	acc
      002882 08               [12] 8032 	inc	r0
      002883 E6               [12] 8033 	mov	a,@r0
      002884 C0 E0            [24] 8034 	push	acc
      002886 08               [12] 8035 	inc	r0
      002887 E6               [12] 8036 	mov	a,@r0
      002888 C0 E0            [24] 8037 	push	acc
      00288A 08               [12] 8038 	inc	r0
      00288B E6               [12] 8039 	mov	a,@r0
      00288C C0 E0            [24] 8040 	push	acc
                           0027D7  8041 	C$fuzzy.h$2844$1_0$123 ==.
                                   8042 ;	../../fuzzy.h:2844: index++
      00288E E5 08            [12] 8043 	mov	a,_bp
      002890 24 0D            [12] 8044 	add	a,#0x0d
      002892 F8               [12] 8045 	mov	r0,a
      002893 86 82            [24] 8046 	mov	dpl, @r0
      002895 08               [12] 8047 	inc	r0
      002896 86 83            [24] 8048 	mov	dph, @r0
      002898 08               [12] 8049 	inc	r0
      002899 86 F0            [24] 8050 	mov	b, @r0
      00289B 08               [12] 8051 	inc	r0
      00289C E6               [12] 8052 	mov	a, @r0
      00289D 12 36 14         [24] 8053 	lcall	___fsadd
      0028A0 C8               [12] 8054 	xch	a,r0
      0028A1 E5 08            [12] 8055 	mov	a,_bp
      0028A3 24 0D            [12] 8056 	add	a,#0x0d
      0028A5 C8               [12] 8057 	xch	a,r0
      0028A6 A6 82            [24] 8058 	mov	@r0, dpl
      0028A8 08               [12] 8059 	inc	r0
      0028A9 A6 83            [24] 8060 	mov	@r0, dph
      0028AB 08               [12] 8061 	inc	r0
      0028AC A6 F0            [24] 8062 	mov	@r0, b
      0028AE 08               [12] 8063 	inc	r0
      0028AF F6               [12] 8064 	mov	@r0,a
      0028B0 E5 81            [12] 8065 	mov	a,sp
      0028B2 24 FC            [12] 8066 	add	a,#0xfc
      0028B4 F5 81            [12] 8067 	mov	sp,a
      0028B6 D0 04            [24] 8068 	pop	ar4
      0028B8 D0 05            [24] 8069 	pop	ar5
      0028BA D0 06            [24] 8070 	pop	ar6
      0028BC E5 08            [12] 8071 	mov	a,_bp
      0028BE 24 07            [12] 8072 	add	a,#0x07
      0028C0 F8               [12] 8073 	mov	r0,a
      0028C1 74 09            [12] 8074 	mov	a,#0x09
      0028C3 26               [12] 8075 	add	a, @r0
      0028C4 F6               [12] 8076 	mov	@r0,a
      0028C5 E4               [12] 8077 	clr	a
      0028C6 08               [12] 8078 	inc	r0
      0028C7 36               [12] 8079 	addc	a, @r0
      0028C8 F6               [12] 8080 	mov	@r0,a
      0028C9 E5 08            [12] 8081 	mov	a,_bp
      0028CB 24 1D            [12] 8082 	add	a,#0x1d
      0028CD F8               [12] 8083 	mov	r0,a
      0028CE 06               [12] 8084 	inc	@r0
      0028CF B6 00 02         [24] 8085 	cjne	@r0,#0x00,00148$
      0028D2 08               [12] 8086 	inc	r0
      0028D3 06               [12] 8087 	inc	@r0
      0028D4                       8088 00148$:
      0028D4 D0 06            [24] 8089 	pop	ar6
      0028D6 D0 05            [24] 8090 	pop	ar5
      0028D8 D0 04            [24] 8091 	pop	ar4
      0028DA 02 26 F0         [24] 8092 	ljmp	00106$
      0028DD                       8093 00110$:
                           002826  8094 	C$fuzzy.h$2840$1_0$123 ==.
                                   8095 ;	../../fuzzy.h:2840: ) {
      0028DD C0 06            [24] 8096 	push	ar6
      0028DF C0 05            [24] 8097 	push	ar5
      0028E1 C0 04            [24] 8098 	push	ar4
      0028E3 E5 08            [12] 8099 	mov	a,_bp
      0028E5 24 F2            [12] 8100 	add	a,#0xf2
      0028E7 F8               [12] 8101 	mov	r0,a
      0028E8 E6               [12] 8102 	mov	a,@r0
      0028E9 C0 E0            [24] 8103 	push	acc
      0028EB 08               [12] 8104 	inc	r0
      0028EC E6               [12] 8105 	mov	a,@r0
      0028ED C0 E0            [24] 8106 	push	acc
      0028EF 08               [12] 8107 	inc	r0
      0028F0 E6               [12] 8108 	mov	a,@r0
      0028F1 C0 E0            [24] 8109 	push	acc
      0028F3 08               [12] 8110 	inc	r0
      0028F4 E6               [12] 8111 	mov	a,@r0
      0028F5 C0 E0            [24] 8112 	push	acc
      0028F7 E5 08            [12] 8113 	mov	a,_bp
      0028F9 24 11            [12] 8114 	add	a,#0x11
      0028FB F8               [12] 8115 	mov	r0,a
      0028FC 86 82            [24] 8116 	mov	dpl, @r0
      0028FE 08               [12] 8117 	inc	r0
      0028FF 86 83            [24] 8118 	mov	dph, @r0
      002901 08               [12] 8119 	inc	r0
      002902 86 F0            [24] 8120 	mov	b, @r0
      002904 08               [12] 8121 	inc	r0
      002905 E6               [12] 8122 	mov	a, @r0
      002906 12 36 14         [24] 8123 	lcall	___fsadd
      002909 C8               [12] 8124 	xch	a,r0
      00290A E5 08            [12] 8125 	mov	a,_bp
      00290C 24 11            [12] 8126 	add	a,#0x11
      00290E C8               [12] 8127 	xch	a,r0
      00290F A6 82            [24] 8128 	mov	@r0, dpl
      002911 08               [12] 8129 	inc	r0
      002912 A6 83            [24] 8130 	mov	@r0, dph
      002914 08               [12] 8131 	inc	r0
      002915 A6 F0            [24] 8132 	mov	@r0, b
      002917 08               [12] 8133 	inc	r0
      002918 F6               [12] 8134 	mov	@r0,a
      002919 E5 81            [12] 8135 	mov	a,sp
      00291B 24 FC            [12] 8136 	add	a,#0xfc
      00291D F5 81            [12] 8137 	mov	sp,a
      00291F D0 04            [24] 8138 	pop	ar4
      002921 D0 05            [24] 8139 	pop	ar5
      002923 D0 06            [24] 8140 	pop	ar6
      002925 02 26 9B         [24] 8141 	ljmp	00109$
      002928                       8142 00102$:
                           002871  8143 	C$fuzzy.h$2868$1_0$123 ==.
                                   8144 ;	../../fuzzy.h:2868: if (height_sum <= LEVEL_LO) {
      002928 E5 08            [12] 8145 	mov	a,_bp
      00292A 24 0D            [12] 8146 	add	a,#0x0d
      00292C F8               [12] 8147 	mov	r0,a
      00292D E6               [12] 8148 	mov	a,@r0
      00292E C0 E0            [24] 8149 	push	acc
      002930 08               [12] 8150 	inc	r0
      002931 E6               [12] 8151 	mov	a,@r0
      002932 C0 E0            [24] 8152 	push	acc
      002934 08               [12] 8153 	inc	r0
      002935 E6               [12] 8154 	mov	a,@r0
      002936 C0 E0            [24] 8155 	push	acc
      002938 08               [12] 8156 	inc	r0
      002939 E6               [12] 8157 	mov	a,@r0
      00293A C0 E0            [24] 8158 	push	acc
      00293C 90 00 00         [24] 8159 	mov	dptr,#0x0000
      00293F E4               [12] 8160 	clr	a
      002940 F5 F0            [12] 8161 	mov	b,a
      002942 12 35 C2         [24] 8162 	lcall	___fslt
      002945 E5 81            [12] 8163 	mov	a,sp
      002947 24 FC            [12] 8164 	add	a,#0xfc
      002949 F5 81            [12] 8165 	mov	sp,a
      00294B E5 82            [12] 8166 	mov	a, dpl
      00294D 24 FF            [12] 8167 	add	a,#0xff
      00294F 92 00            [24] 8168 	mov	b0,c
      002951 40 08            [24] 8169 	jc	00104$
                           00289C  8170 	C$fuzzy.h$2869$2_0$128 ==.
                                   8171 ;	../../fuzzy.h:2869: return 0.0f;
      002953 90 00 00         [24] 8172 	mov	dptr,#0x0000
      002956 E4               [12] 8173 	clr	a
      002957 F5 F0            [12] 8174 	mov	b,a
      002959 80 3A            [24] 8175 	sjmp	00111$
      00295B                       8176 00104$:
                           0028A4  8177 	C$fuzzy.h$2873$1_0$123 ==.
                                   8178 ;	../../fuzzy.h:2873: height_sum;
      00295B E5 08            [12] 8179 	mov	a,_bp
      00295D 24 0D            [12] 8180 	add	a,#0x0d
      00295F F8               [12] 8181 	mov	r0,a
      002960 E6               [12] 8182 	mov	a,@r0
      002961 C0 E0            [24] 8183 	push	acc
      002963 08               [12] 8184 	inc	r0
      002964 E6               [12] 8185 	mov	a,@r0
      002965 C0 E0            [24] 8186 	push	acc
      002967 08               [12] 8187 	inc	r0
      002968 E6               [12] 8188 	mov	a,@r0
      002969 C0 E0            [24] 8189 	push	acc
      00296B 08               [12] 8190 	inc	r0
      00296C E6               [12] 8191 	mov	a,@r0
      00296D C0 E0            [24] 8192 	push	acc
      00296F E5 08            [12] 8193 	mov	a,_bp
      002971 24 09            [12] 8194 	add	a,#0x09
      002973 F8               [12] 8195 	mov	r0,a
      002974 86 82            [24] 8196 	mov	dpl, @r0
      002976 08               [12] 8197 	inc	r0
      002977 86 83            [24] 8198 	mov	dph, @r0
      002979 08               [12] 8199 	inc	r0
      00297A 86 F0            [24] 8200 	mov	b, @r0
      00297C 08               [12] 8201 	inc	r0
      00297D E6               [12] 8202 	mov	a, @r0
      00297E 12 37 2B         [24] 8203 	lcall	___fsdiv
      002981 AC 82            [24] 8204 	mov	r4, dpl
      002983 AD 83            [24] 8205 	mov	r5, dph
      002985 AE F0            [24] 8206 	mov	r6, b
      002987 FF               [12] 8207 	mov	r7, a
      002988 E5 81            [12] 8208 	mov	a,sp
      00298A 24 FC            [12] 8209 	add	a,#0xfc
      00298C F5 81            [12] 8210 	mov	sp,a
      00298E 8C 82            [24] 8211 	mov	dpl, r4
      002990 8D 83            [24] 8212 	mov	dph, r5
      002992 8E F0            [24] 8213 	mov	b, r6
      002994 EF               [12] 8214 	mov	a, r7
      002995                       8215 00111$:
                           0028DE  8216 	C$fuzzy.h$2874$1_0$123 ==.
                                   8217 ;	../../fuzzy.h:2874: }
      002995 85 08 81         [24] 8218 	mov	sp,_bp
      002998 D0 08            [24] 8219 	pop	_bp
                           0028E3  8220 	C$fuzzy.h$2874$1_0$123 ==.
                           0028E3  8221 	XG$fuzzy_rules_defuzzify_cos$0$0 ==.
      00299A 22               [24] 8222 	ret
                                   8223 ;------------------------------------------------------------
                                   8224 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_mom'
                                   8225 ;------------------------------------------------------------
                                   8226 ;lower         Allocated to stack - _bp -6 +4 
                                   8227 ;upper         Allocated to stack - _bp -10 +4 
                                   8228 ;step          Allocated to stack - _bp -14 +4 
                                   8229 ;implication_method Allocated to stack - _bp -15 +1 
                                   8230 ;aggregation_method Allocated to stack - _bp -16 +1 
                                   8231 ;rules         Allocated to stack - _bp +1 +3 
                                   8232 ;result        Allocated to stack - _bp +8 +18 
                                   8233 ;sloc0         Allocated to stack - _bp +4 +4 
                                   8234 ;------------------------------------------------------------
                           0028E4  8235 	G$fuzzy_rules_defuzzify_mom$0$0 ==.
                           0028E4  8236 	C$fuzzy.h$2880$1_0$130 ==.
                                   8237 ;	../../fuzzy.h:2880: float fuzzy_rules_defuzzify_mom(
                                   8238 ;	-----------------------------------------
                                   8239 ;	 function fuzzy_rules_defuzzify_mom
                                   8240 ;	-----------------------------------------
      00299B                       8241 _fuzzy_rules_defuzzify_mom:
      00299B C0 08            [24] 8242 	push	_bp
      00299D 85 81 08         [24] 8243 	mov	_bp,sp
      0029A0 C0 82            [24] 8244 	push	dpl
      0029A2 C0 83            [24] 8245 	push	dph
      0029A4 C0 F0            [24] 8246 	push	b
      0029A6 E5 81            [12] 8247 	mov	a,sp
      0029A8 24 16            [12] 8248 	add	a,#0x16
      0029AA F5 81            [12] 8249 	mov	sp,a
                           0028F5  8250 	C$fuzzy.h$2892$1_0$130 ==.
                                   8251 ;	../../fuzzy.h:2892: &result,
      0029AC E5 08            [12] 8252 	mov	a,_bp
      0029AE 24 08            [12] 8253 	add	a,#0x08
      0029B0 FC               [12] 8254 	mov	r4,a
      0029B1 FA               [12] 8255 	mov	r2,a
      0029B2 7B 00            [12] 8256 	mov	r3,#0x00
      0029B4 7F 40            [12] 8257 	mov	r7,#0x40
      0029B6 C0 04            [24] 8258 	push	ar4
      0029B8 E5 08            [12] 8259 	mov	a,_bp
      0029BA 24 F0            [12] 8260 	add	a,#0xf0
      0029BC F8               [12] 8261 	mov	r0,a
      0029BD E6               [12] 8262 	mov	a,@r0
      0029BE C0 E0            [24] 8263 	push	acc
      0029C0 E5 08            [12] 8264 	mov	a,_bp
      0029C2 24 F1            [12] 8265 	add	a,#0xf1
      0029C4 F8               [12] 8266 	mov	r0,a
      0029C5 E6               [12] 8267 	mov	a,@r0
      0029C6 C0 E0            [24] 8268 	push	acc
      0029C8 E5 08            [12] 8269 	mov	a,_bp
      0029CA 24 F2            [12] 8270 	add	a,#0xf2
      0029CC F8               [12] 8271 	mov	r0,a
      0029CD E6               [12] 8272 	mov	a,@r0
      0029CE C0 E0            [24] 8273 	push	acc
      0029D0 08               [12] 8274 	inc	r0
      0029D1 E6               [12] 8275 	mov	a,@r0
      0029D2 C0 E0            [24] 8276 	push	acc
      0029D4 08               [12] 8277 	inc	r0
      0029D5 E6               [12] 8278 	mov	a,@r0
      0029D6 C0 E0            [24] 8279 	push	acc
      0029D8 08               [12] 8280 	inc	r0
      0029D9 E6               [12] 8281 	mov	a,@r0
      0029DA C0 E0            [24] 8282 	push	acc
      0029DC E5 08            [12] 8283 	mov	a,_bp
      0029DE 24 F6            [12] 8284 	add	a,#0xf6
      0029E0 F8               [12] 8285 	mov	r0,a
      0029E1 E6               [12] 8286 	mov	a,@r0
      0029E2 C0 E0            [24] 8287 	push	acc
      0029E4 08               [12] 8288 	inc	r0
      0029E5 E6               [12] 8289 	mov	a,@r0
      0029E6 C0 E0            [24] 8290 	push	acc
      0029E8 08               [12] 8291 	inc	r0
      0029E9 E6               [12] 8292 	mov	a,@r0
      0029EA C0 E0            [24] 8293 	push	acc
      0029EC 08               [12] 8294 	inc	r0
      0029ED E6               [12] 8295 	mov	a,@r0
      0029EE C0 E0            [24] 8296 	push	acc
      0029F0 E5 08            [12] 8297 	mov	a,_bp
      0029F2 24 FA            [12] 8298 	add	a,#0xfa
      0029F4 F8               [12] 8299 	mov	r0,a
      0029F5 E6               [12] 8300 	mov	a,@r0
      0029F6 C0 E0            [24] 8301 	push	acc
      0029F8 08               [12] 8302 	inc	r0
      0029F9 E6               [12] 8303 	mov	a,@r0
      0029FA C0 E0            [24] 8304 	push	acc
      0029FC 08               [12] 8305 	inc	r0
      0029FD E6               [12] 8306 	mov	a,@r0
      0029FE C0 E0            [24] 8307 	push	acc
      002A00 08               [12] 8308 	inc	r0
      002A01 E6               [12] 8309 	mov	a,@r0
      002A02 C0 E0            [24] 8310 	push	acc
      002A04 A8 08            [24] 8311 	mov	r0,_bp
      002A06 08               [12] 8312 	inc	r0
      002A07 E6               [12] 8313 	mov	a,@r0
      002A08 C0 E0            [24] 8314 	push	acc
      002A0A 08               [12] 8315 	inc	r0
      002A0B E6               [12] 8316 	mov	a,@r0
      002A0C C0 E0            [24] 8317 	push	acc
      002A0E 08               [12] 8318 	inc	r0
      002A0F E6               [12] 8319 	mov	a,@r0
      002A10 C0 E0            [24] 8320 	push	acc
      002A12 8A 82            [24] 8321 	mov	dpl, r2
      002A14 8B 83            [24] 8322 	mov	dph, r3
      002A16 8F F0            [24] 8323 	mov	b, r7
      002A18 12 1D 41         [24] 8324 	lcall	_fuzzy_rules_maximum_result
      002A1B E5 81            [12] 8325 	mov	a,sp
      002A1D 24 EF            [12] 8326 	add	a,#0xef
      002A1F F5 81            [12] 8327 	mov	sp,a
      002A21 D0 04            [24] 8328 	pop	ar4
                           00296C  8329 	C$fuzzy.h$2902$1_0$130 ==.
                                   8330 ;	../../fuzzy.h:2902: result.position_count == 0u ||
      002A23 74 10            [12] 8331 	mov	a,#0x10
      002A25 2C               [12] 8332 	add	a, r4
      002A26 F9               [12] 8333 	mov	r1,a
      002A27 87 06            [24] 8334 	mov	ar6,@r1
      002A29 09               [12] 8335 	inc	r1
      002A2A 87 07            [24] 8336 	mov	ar7,@r1
      002A2C EE               [12] 8337 	mov	a,r6
      002A2D 4F               [12] 8338 	orl	a,r7
      002A2E 60 41            [24] 8339 	jz	00101$
                           002979  8340 	C$fuzzy.h$2903$1_0$130 ==.
                                   8341 ;	../../fuzzy.h:2903: result.height <= LEVEL_LO
      002A30 C0 06            [24] 8342 	push	ar6
      002A32 C0 07            [24] 8343 	push	ar7
      002A34 8C 01            [24] 8344 	mov	ar1,r4
      002A36 87 02            [24] 8345 	mov	ar2,@r1
      002A38 09               [12] 8346 	inc	r1
      002A39 87 03            [24] 8347 	mov	ar3,@r1
      002A3B 09               [12] 8348 	inc	r1
      002A3C 87 05            [24] 8349 	mov	ar5,@r1
      002A3E 09               [12] 8350 	inc	r1
      002A3F 87 07            [24] 8351 	mov	ar7,@r1
      002A41 C0 07            [24] 8352 	push	ar7
      002A43 C0 06            [24] 8353 	push	ar6
      002A45 C0 04            [24] 8354 	push	ar4
      002A47 C0 02            [24] 8355 	push	ar2
      002A49 C0 03            [24] 8356 	push	ar3
      002A4B C0 05            [24] 8357 	push	ar5
      002A4D C0 07            [24] 8358 	push	ar7
      002A4F 90 00 00         [24] 8359 	mov	dptr,#0x0000
      002A52 E4               [12] 8360 	clr	a
      002A53 F5 F0            [12] 8361 	mov	b,a
      002A55 12 35 C2         [24] 8362 	lcall	___fslt
      002A58 E5 81            [12] 8363 	mov	a,sp
      002A5A 24 FC            [12] 8364 	add	a,#0xfc
      002A5C F5 81            [12] 8365 	mov	sp,a
      002A5E D0 04            [24] 8366 	pop	ar4
      002A60 D0 06            [24] 8367 	pop	ar6
      002A62 D0 07            [24] 8368 	pop	ar7
      002A64 E5 82            [12] 8369 	mov	a, dpl
      002A66 24 FF            [12] 8370 	add	a,#0xff
      002A68 92 00            [24] 8371 	mov	b0,c
      002A6A D0 07            [24] 8372 	pop	ar7
      002A6C D0 06            [24] 8373 	pop	ar6
      002A6E 20 00 08         [24] 8374 	jb	b0,00102$
      002A71                       8375 00101$:
                           0029BA  8376 	C$fuzzy.h$2905$2_0$131 ==.
                                   8377 ;	../../fuzzy.h:2905: return 0.0f;
      002A71 90 00 00         [24] 8378 	mov	dptr,#0x0000
      002A74 E4               [12] 8379 	clr	a
      002A75 F5 F0            [12] 8380 	mov	b,a
      002A77 80 53            [24] 8381 	sjmp	00104$
      002A79                       8382 00102$:
                           0029C2  8383 	C$fuzzy.h$2908$1_0$130 ==.
                                   8384 ;	../../fuzzy.h:2908: return result.position_sum /
      002A79 74 0C            [12] 8385 	mov	a,#0x0c
      002A7B 2C               [12] 8386 	add	a, r4
      002A7C F9               [12] 8387 	mov	r1,a
      002A7D E5 08            [12] 8388 	mov	a,_bp
      002A7F 24 04            [12] 8389 	add	a,#0x04
      002A81 F8               [12] 8390 	mov	r0,a
      002A82 E7               [12] 8391 	mov	a,@r1
      002A83 F6               [12] 8392 	mov	@r0,a
      002A84 09               [12] 8393 	inc	r1
      002A85 E7               [12] 8394 	mov	a,@r1
      002A86 08               [12] 8395 	inc	r0
      002A87 F6               [12] 8396 	mov	@r0,a
      002A88 09               [12] 8397 	inc	r1
      002A89 E7               [12] 8398 	mov	a,@r1
      002A8A 08               [12] 8399 	inc	r0
      002A8B F6               [12] 8400 	mov	@r0,a
      002A8C 09               [12] 8401 	inc	r1
      002A8D E7               [12] 8402 	mov	a,@r1
      002A8E 08               [12] 8403 	inc	r0
      002A8F F6               [12] 8404 	mov	@r0,a
                           0029D9  8405 	C$fuzzy.h$2909$1_0$130 ==.
                                   8406 ;	../../fuzzy.h:2909: (float)result.position_count;
      002A90 8E 82            [24] 8407 	mov	dpl, r6
      002A92 8F 83            [24] 8408 	mov	dph, r7
      002A94 12 36 B6         [24] 8409 	lcall	___uint2fs
      002A97 AC 82            [24] 8410 	mov	r4, dpl
      002A99 AD 83            [24] 8411 	mov	r5, dph
      002A9B AE F0            [24] 8412 	mov	r6, b
      002A9D FF               [12] 8413 	mov	r7, a
      002A9E C0 04            [24] 8414 	push	ar4
      002AA0 C0 05            [24] 8415 	push	ar5
      002AA2 C0 06            [24] 8416 	push	ar6
      002AA4 C0 07            [24] 8417 	push	ar7
      002AA6 E5 08            [12] 8418 	mov	a,_bp
      002AA8 24 04            [12] 8419 	add	a,#0x04
      002AAA F8               [12] 8420 	mov	r0,a
      002AAB 86 82            [24] 8421 	mov	dpl, @r0
      002AAD 08               [12] 8422 	inc	r0
      002AAE 86 83            [24] 8423 	mov	dph, @r0
      002AB0 08               [12] 8424 	inc	r0
      002AB1 86 F0            [24] 8425 	mov	b, @r0
      002AB3 08               [12] 8426 	inc	r0
      002AB4 E6               [12] 8427 	mov	a, @r0
      002AB5 12 37 2B         [24] 8428 	lcall	___fsdiv
      002AB8 AC 82            [24] 8429 	mov	r4, dpl
      002ABA AD 83            [24] 8430 	mov	r5, dph
      002ABC AE F0            [24] 8431 	mov	r6, b
      002ABE FF               [12] 8432 	mov	r7, a
      002ABF E5 81            [12] 8433 	mov	a,sp
      002AC1 24 FC            [12] 8434 	add	a,#0xfc
      002AC3 F5 81            [12] 8435 	mov	sp,a
      002AC5 8C 82            [24] 8436 	mov	dpl, r4
      002AC7 8D 83            [24] 8437 	mov	dph, r5
      002AC9 8E F0            [24] 8438 	mov	b, r6
      002ACB EF               [12] 8439 	mov	a, r7
      002ACC                       8440 00104$:
                           002A15  8441 	C$fuzzy.h$2910$1_0$130 ==.
                                   8442 ;	../../fuzzy.h:2910: }
      002ACC 85 08 81         [24] 8443 	mov	sp,_bp
      002ACF D0 08            [24] 8444 	pop	_bp
                           002A1A  8445 	C$fuzzy.h$2910$1_0$130 ==.
                           002A1A  8446 	XG$fuzzy_rules_defuzzify_mom$0$0 ==.
      002AD1 22               [24] 8447 	ret
                                   8448 ;------------------------------------------------------------
                                   8449 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_som'
                                   8450 ;------------------------------------------------------------
                                   8451 ;lower         Allocated to stack - _bp -6 +4 
                                   8452 ;upper         Allocated to stack - _bp -10 +4 
                                   8453 ;step          Allocated to stack - _bp -14 +4 
                                   8454 ;implication_method Allocated to stack - _bp -15 +1 
                                   8455 ;aggregation_method Allocated to stack - _bp -16 +1 
                                   8456 ;rules         Allocated to stack - _bp +1 +3 
                                   8457 ;result        Allocated to stack - _bp +4 +18 
                                   8458 ;------------------------------------------------------------
                           002A1B  8459 	G$fuzzy_rules_defuzzify_som$0$0 ==.
                           002A1B  8460 	C$fuzzy.h$2916$1_0$133 ==.
                                   8461 ;	../../fuzzy.h:2916: float fuzzy_rules_defuzzify_som(
                                   8462 ;	-----------------------------------------
                                   8463 ;	 function fuzzy_rules_defuzzify_som
                                   8464 ;	-----------------------------------------
      002AD2                       8465 _fuzzy_rules_defuzzify_som:
      002AD2 C0 08            [24] 8466 	push	_bp
      002AD4 85 81 08         [24] 8467 	mov	_bp,sp
      002AD7 C0 82            [24] 8468 	push	dpl
      002AD9 C0 83            [24] 8469 	push	dph
      002ADB C0 F0            [24] 8470 	push	b
      002ADD E5 81            [12] 8471 	mov	a,sp
      002ADF 24 12            [12] 8472 	add	a,#0x12
      002AE1 F5 81            [12] 8473 	mov	sp,a
                           002A2C  8474 	C$fuzzy.h$2928$1_0$133 ==.
                                   8475 ;	../../fuzzy.h:2928: &result,
      002AE3 E5 08            [12] 8476 	mov	a,_bp
      002AE5 24 04            [12] 8477 	add	a,#0x04
      002AE7 FC               [12] 8478 	mov	r4,a
      002AE8 FA               [12] 8479 	mov	r2,a
      002AE9 7B 00            [12] 8480 	mov	r3,#0x00
      002AEB 7F 40            [12] 8481 	mov	r7,#0x40
      002AED C0 04            [24] 8482 	push	ar4
      002AEF E5 08            [12] 8483 	mov	a,_bp
      002AF1 24 F0            [12] 8484 	add	a,#0xf0
      002AF3 F8               [12] 8485 	mov	r0,a
      002AF4 E6               [12] 8486 	mov	a,@r0
      002AF5 C0 E0            [24] 8487 	push	acc
      002AF7 E5 08            [12] 8488 	mov	a,_bp
      002AF9 24 F1            [12] 8489 	add	a,#0xf1
      002AFB F8               [12] 8490 	mov	r0,a
      002AFC E6               [12] 8491 	mov	a,@r0
      002AFD C0 E0            [24] 8492 	push	acc
      002AFF E5 08            [12] 8493 	mov	a,_bp
      002B01 24 F2            [12] 8494 	add	a,#0xf2
      002B03 F8               [12] 8495 	mov	r0,a
      002B04 E6               [12] 8496 	mov	a,@r0
      002B05 C0 E0            [24] 8497 	push	acc
      002B07 08               [12] 8498 	inc	r0
      002B08 E6               [12] 8499 	mov	a,@r0
      002B09 C0 E0            [24] 8500 	push	acc
      002B0B 08               [12] 8501 	inc	r0
      002B0C E6               [12] 8502 	mov	a,@r0
      002B0D C0 E0            [24] 8503 	push	acc
      002B0F 08               [12] 8504 	inc	r0
      002B10 E6               [12] 8505 	mov	a,@r0
      002B11 C0 E0            [24] 8506 	push	acc
      002B13 E5 08            [12] 8507 	mov	a,_bp
      002B15 24 F6            [12] 8508 	add	a,#0xf6
      002B17 F8               [12] 8509 	mov	r0,a
      002B18 E6               [12] 8510 	mov	a,@r0
      002B19 C0 E0            [24] 8511 	push	acc
      002B1B 08               [12] 8512 	inc	r0
      002B1C E6               [12] 8513 	mov	a,@r0
      002B1D C0 E0            [24] 8514 	push	acc
      002B1F 08               [12] 8515 	inc	r0
      002B20 E6               [12] 8516 	mov	a,@r0
      002B21 C0 E0            [24] 8517 	push	acc
      002B23 08               [12] 8518 	inc	r0
      002B24 E6               [12] 8519 	mov	a,@r0
      002B25 C0 E0            [24] 8520 	push	acc
      002B27 E5 08            [12] 8521 	mov	a,_bp
      002B29 24 FA            [12] 8522 	add	a,#0xfa
      002B2B F8               [12] 8523 	mov	r0,a
      002B2C E6               [12] 8524 	mov	a,@r0
      002B2D C0 E0            [24] 8525 	push	acc
      002B2F 08               [12] 8526 	inc	r0
      002B30 E6               [12] 8527 	mov	a,@r0
      002B31 C0 E0            [24] 8528 	push	acc
      002B33 08               [12] 8529 	inc	r0
      002B34 E6               [12] 8530 	mov	a,@r0
      002B35 C0 E0            [24] 8531 	push	acc
      002B37 08               [12] 8532 	inc	r0
      002B38 E6               [12] 8533 	mov	a,@r0
      002B39 C0 E0            [24] 8534 	push	acc
      002B3B A8 08            [24] 8535 	mov	r0,_bp
      002B3D 08               [12] 8536 	inc	r0
      002B3E E6               [12] 8537 	mov	a,@r0
      002B3F C0 E0            [24] 8538 	push	acc
      002B41 08               [12] 8539 	inc	r0
      002B42 E6               [12] 8540 	mov	a,@r0
      002B43 C0 E0            [24] 8541 	push	acc
      002B45 08               [12] 8542 	inc	r0
      002B46 E6               [12] 8543 	mov	a,@r0
      002B47 C0 E0            [24] 8544 	push	acc
      002B49 8A 82            [24] 8545 	mov	dpl, r2
      002B4B 8B 83            [24] 8546 	mov	dph, r3
      002B4D 8F F0            [24] 8547 	mov	b, r7
      002B4F 12 1D 41         [24] 8548 	lcall	_fuzzy_rules_maximum_result
      002B52 E5 81            [12] 8549 	mov	a,sp
      002B54 24 EF            [12] 8550 	add	a,#0xef
      002B56 F5 81            [12] 8551 	mov	sp,a
      002B58 D0 04            [24] 8552 	pop	ar4
                           002AA3  8553 	C$fuzzy.h$2938$1_0$133 ==.
                                   8554 ;	../../fuzzy.h:2938: result.position_count == 0u ||
      002B5A 74 10            [12] 8555 	mov	a,#0x10
      002B5C 2C               [12] 8556 	add	a, r4
      002B5D F9               [12] 8557 	mov	r1,a
      002B5E 87 06            [24] 8558 	mov	ar6,@r1
      002B60 09               [12] 8559 	inc	r1
      002B61 87 07            [24] 8560 	mov	ar7,@r1
      002B63 EE               [12] 8561 	mov	a,r6
      002B64 4F               [12] 8562 	orl	a,r7
      002B65 60 30            [24] 8563 	jz	00101$
                           002AB0  8564 	C$fuzzy.h$2939$1_0$133 ==.
                                   8565 ;	../../fuzzy.h:2939: result.height <= LEVEL_LO
      002B67 8C 01            [24] 8566 	mov	ar1,r4
      002B69 87 03            [24] 8567 	mov	ar3,@r1
      002B6B 09               [12] 8568 	inc	r1
      002B6C 87 05            [24] 8569 	mov	ar5,@r1
      002B6E 09               [12] 8570 	inc	r1
      002B6F 87 06            [24] 8571 	mov	ar6,@r1
      002B71 09               [12] 8572 	inc	r1
      002B72 87 07            [24] 8573 	mov	ar7,@r1
      002B74 C0 04            [24] 8574 	push	ar4
      002B76 C0 03            [24] 8575 	push	ar3
      002B78 C0 05            [24] 8576 	push	ar5
      002B7A C0 06            [24] 8577 	push	ar6
      002B7C C0 07            [24] 8578 	push	ar7
      002B7E 90 00 00         [24] 8579 	mov	dptr,#0x0000
      002B81 E4               [12] 8580 	clr	a
      002B82 F5 F0            [12] 8581 	mov	b,a
      002B84 12 35 C2         [24] 8582 	lcall	___fslt
      002B87 E5 81            [12] 8583 	mov	a,sp
      002B89 24 FC            [12] 8584 	add	a,#0xfc
      002B8B F5 81            [12] 8585 	mov	sp,a
      002B8D D0 04            [24] 8586 	pop	ar4
      002B8F E5 82            [12] 8587 	mov	a, dpl
      002B91 24 FF            [12] 8588 	add	a,#0xff
      002B93 92 00            [24] 8589 	mov	b0,c
      002B95 40 08            [24] 8590 	jc	00102$
      002B97                       8591 00101$:
                           002AE0  8592 	C$fuzzy.h$2941$2_0$134 ==.
                                   8593 ;	../../fuzzy.h:2941: return 0.0f;
      002B97 90 00 00         [24] 8594 	mov	dptr,#0x0000
      002B9A E4               [12] 8595 	clr	a
      002B9B F5 F0            [12] 8596 	mov	b,a
      002B9D 80 16            [24] 8597 	sjmp	00104$
      002B9F                       8598 00102$:
                           002AE8  8599 	C$fuzzy.h$2944$1_0$133 ==.
                                   8600 ;	../../fuzzy.h:2944: return result.smallest_position;
      002B9F 74 04            [12] 8601 	mov	a,#0x04
      002BA1 2C               [12] 8602 	add	a, r4
      002BA2 F9               [12] 8603 	mov	r1,a
      002BA3 87 04            [24] 8604 	mov	ar4,@r1
      002BA5 09               [12] 8605 	inc	r1
      002BA6 87 05            [24] 8606 	mov	ar5,@r1
      002BA8 09               [12] 8607 	inc	r1
      002BA9 87 06            [24] 8608 	mov	ar6,@r1
      002BAB 09               [12] 8609 	inc	r1
      002BAC 87 07            [24] 8610 	mov	ar7,@r1
      002BAE 8C 82            [24] 8611 	mov	dpl, r4
      002BB0 8D 83            [24] 8612 	mov	dph, r5
      002BB2 8E F0            [24] 8613 	mov	b, r6
      002BB4 EF               [12] 8614 	mov	a, r7
      002BB5                       8615 00104$:
                           002AFE  8616 	C$fuzzy.h$2945$1_0$133 ==.
                                   8617 ;	../../fuzzy.h:2945: }
      002BB5 85 08 81         [24] 8618 	mov	sp,_bp
      002BB8 D0 08            [24] 8619 	pop	_bp
                           002B03  8620 	C$fuzzy.h$2945$1_0$133 ==.
                           002B03  8621 	XG$fuzzy_rules_defuzzify_som$0$0 ==.
      002BBA 22               [24] 8622 	ret
                                   8623 ;------------------------------------------------------------
                                   8624 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_lom'
                                   8625 ;------------------------------------------------------------
                                   8626 ;lower         Allocated to stack - _bp -6 +4 
                                   8627 ;upper         Allocated to stack - _bp -10 +4 
                                   8628 ;step          Allocated to stack - _bp -14 +4 
                                   8629 ;implication_method Allocated to stack - _bp -15 +1 
                                   8630 ;aggregation_method Allocated to stack - _bp -16 +1 
                                   8631 ;rules         Allocated to stack - _bp +1 +3 
                                   8632 ;result        Allocated to stack - _bp +4 +18 
                                   8633 ;------------------------------------------------------------
                           002B04  8634 	G$fuzzy_rules_defuzzify_lom$0$0 ==.
                           002B04  8635 	C$fuzzy.h$2951$1_0$136 ==.
                                   8636 ;	../../fuzzy.h:2951: float fuzzy_rules_defuzzify_lom(
                                   8637 ;	-----------------------------------------
                                   8638 ;	 function fuzzy_rules_defuzzify_lom
                                   8639 ;	-----------------------------------------
      002BBB                       8640 _fuzzy_rules_defuzzify_lom:
      002BBB C0 08            [24] 8641 	push	_bp
      002BBD 85 81 08         [24] 8642 	mov	_bp,sp
      002BC0 C0 82            [24] 8643 	push	dpl
      002BC2 C0 83            [24] 8644 	push	dph
      002BC4 C0 F0            [24] 8645 	push	b
      002BC6 E5 81            [12] 8646 	mov	a,sp
      002BC8 24 12            [12] 8647 	add	a,#0x12
      002BCA F5 81            [12] 8648 	mov	sp,a
                           002B15  8649 	C$fuzzy.h$2963$1_0$136 ==.
                                   8650 ;	../../fuzzy.h:2963: &result,
      002BCC E5 08            [12] 8651 	mov	a,_bp
      002BCE 24 04            [12] 8652 	add	a,#0x04
      002BD0 FC               [12] 8653 	mov	r4,a
      002BD1 FA               [12] 8654 	mov	r2,a
      002BD2 7B 00            [12] 8655 	mov	r3,#0x00
      002BD4 7F 40            [12] 8656 	mov	r7,#0x40
      002BD6 C0 04            [24] 8657 	push	ar4
      002BD8 E5 08            [12] 8658 	mov	a,_bp
      002BDA 24 F0            [12] 8659 	add	a,#0xf0
      002BDC F8               [12] 8660 	mov	r0,a
      002BDD E6               [12] 8661 	mov	a,@r0
      002BDE C0 E0            [24] 8662 	push	acc
      002BE0 E5 08            [12] 8663 	mov	a,_bp
      002BE2 24 F1            [12] 8664 	add	a,#0xf1
      002BE4 F8               [12] 8665 	mov	r0,a
      002BE5 E6               [12] 8666 	mov	a,@r0
      002BE6 C0 E0            [24] 8667 	push	acc
      002BE8 E5 08            [12] 8668 	mov	a,_bp
      002BEA 24 F2            [12] 8669 	add	a,#0xf2
      002BEC F8               [12] 8670 	mov	r0,a
      002BED E6               [12] 8671 	mov	a,@r0
      002BEE C0 E0            [24] 8672 	push	acc
      002BF0 08               [12] 8673 	inc	r0
      002BF1 E6               [12] 8674 	mov	a,@r0
      002BF2 C0 E0            [24] 8675 	push	acc
      002BF4 08               [12] 8676 	inc	r0
      002BF5 E6               [12] 8677 	mov	a,@r0
      002BF6 C0 E0            [24] 8678 	push	acc
      002BF8 08               [12] 8679 	inc	r0
      002BF9 E6               [12] 8680 	mov	a,@r0
      002BFA C0 E0            [24] 8681 	push	acc
      002BFC E5 08            [12] 8682 	mov	a,_bp
      002BFE 24 F6            [12] 8683 	add	a,#0xf6
      002C00 F8               [12] 8684 	mov	r0,a
      002C01 E6               [12] 8685 	mov	a,@r0
      002C02 C0 E0            [24] 8686 	push	acc
      002C04 08               [12] 8687 	inc	r0
      002C05 E6               [12] 8688 	mov	a,@r0
      002C06 C0 E0            [24] 8689 	push	acc
      002C08 08               [12] 8690 	inc	r0
      002C09 E6               [12] 8691 	mov	a,@r0
      002C0A C0 E0            [24] 8692 	push	acc
      002C0C 08               [12] 8693 	inc	r0
      002C0D E6               [12] 8694 	mov	a,@r0
      002C0E C0 E0            [24] 8695 	push	acc
      002C10 E5 08            [12] 8696 	mov	a,_bp
      002C12 24 FA            [12] 8697 	add	a,#0xfa
      002C14 F8               [12] 8698 	mov	r0,a
      002C15 E6               [12] 8699 	mov	a,@r0
      002C16 C0 E0            [24] 8700 	push	acc
      002C18 08               [12] 8701 	inc	r0
      002C19 E6               [12] 8702 	mov	a,@r0
      002C1A C0 E0            [24] 8703 	push	acc
      002C1C 08               [12] 8704 	inc	r0
      002C1D E6               [12] 8705 	mov	a,@r0
      002C1E C0 E0            [24] 8706 	push	acc
      002C20 08               [12] 8707 	inc	r0
      002C21 E6               [12] 8708 	mov	a,@r0
      002C22 C0 E0            [24] 8709 	push	acc
      002C24 A8 08            [24] 8710 	mov	r0,_bp
      002C26 08               [12] 8711 	inc	r0
      002C27 E6               [12] 8712 	mov	a,@r0
      002C28 C0 E0            [24] 8713 	push	acc
      002C2A 08               [12] 8714 	inc	r0
      002C2B E6               [12] 8715 	mov	a,@r0
      002C2C C0 E0            [24] 8716 	push	acc
      002C2E 08               [12] 8717 	inc	r0
      002C2F E6               [12] 8718 	mov	a,@r0
      002C30 C0 E0            [24] 8719 	push	acc
      002C32 8A 82            [24] 8720 	mov	dpl, r2
      002C34 8B 83            [24] 8721 	mov	dph, r3
      002C36 8F F0            [24] 8722 	mov	b, r7
      002C38 12 1D 41         [24] 8723 	lcall	_fuzzy_rules_maximum_result
      002C3B E5 81            [12] 8724 	mov	a,sp
      002C3D 24 EF            [12] 8725 	add	a,#0xef
      002C3F F5 81            [12] 8726 	mov	sp,a
      002C41 D0 04            [24] 8727 	pop	ar4
                           002B8C  8728 	C$fuzzy.h$2973$1_0$136 ==.
                                   8729 ;	../../fuzzy.h:2973: result.position_count == 0u ||
      002C43 74 10            [12] 8730 	mov	a,#0x10
      002C45 2C               [12] 8731 	add	a, r4
      002C46 F9               [12] 8732 	mov	r1,a
      002C47 87 06            [24] 8733 	mov	ar6,@r1
      002C49 09               [12] 8734 	inc	r1
      002C4A 87 07            [24] 8735 	mov	ar7,@r1
      002C4C EE               [12] 8736 	mov	a,r6
      002C4D 4F               [12] 8737 	orl	a,r7
      002C4E 60 30            [24] 8738 	jz	00101$
                           002B99  8739 	C$fuzzy.h$2974$1_0$136 ==.
                                   8740 ;	../../fuzzy.h:2974: result.height <= LEVEL_LO
      002C50 8C 01            [24] 8741 	mov	ar1,r4
      002C52 87 03            [24] 8742 	mov	ar3,@r1
      002C54 09               [12] 8743 	inc	r1
      002C55 87 05            [24] 8744 	mov	ar5,@r1
      002C57 09               [12] 8745 	inc	r1
      002C58 87 06            [24] 8746 	mov	ar6,@r1
      002C5A 09               [12] 8747 	inc	r1
      002C5B 87 07            [24] 8748 	mov	ar7,@r1
      002C5D C0 04            [24] 8749 	push	ar4
      002C5F C0 03            [24] 8750 	push	ar3
      002C61 C0 05            [24] 8751 	push	ar5
      002C63 C0 06            [24] 8752 	push	ar6
      002C65 C0 07            [24] 8753 	push	ar7
      002C67 90 00 00         [24] 8754 	mov	dptr,#0x0000
      002C6A E4               [12] 8755 	clr	a
      002C6B F5 F0            [12] 8756 	mov	b,a
      002C6D 12 35 C2         [24] 8757 	lcall	___fslt
      002C70 E5 81            [12] 8758 	mov	a,sp
      002C72 24 FC            [12] 8759 	add	a,#0xfc
      002C74 F5 81            [12] 8760 	mov	sp,a
      002C76 D0 04            [24] 8761 	pop	ar4
      002C78 E5 82            [12] 8762 	mov	a, dpl
      002C7A 24 FF            [12] 8763 	add	a,#0xff
      002C7C 92 00            [24] 8764 	mov	b0,c
      002C7E 40 08            [24] 8765 	jc	00102$
      002C80                       8766 00101$:
                           002BC9  8767 	C$fuzzy.h$2976$2_0$137 ==.
                                   8768 ;	../../fuzzy.h:2976: return 0.0f;
      002C80 90 00 00         [24] 8769 	mov	dptr,#0x0000
      002C83 E4               [12] 8770 	clr	a
      002C84 F5 F0            [12] 8771 	mov	b,a
      002C86 80 16            [24] 8772 	sjmp	00104$
      002C88                       8773 00102$:
                           002BD1  8774 	C$fuzzy.h$2979$1_0$136 ==.
                                   8775 ;	../../fuzzy.h:2979: return result.largest_position;
      002C88 74 08            [12] 8776 	mov	a,#0x08
      002C8A 2C               [12] 8777 	add	a, r4
      002C8B F9               [12] 8778 	mov	r1,a
      002C8C 87 04            [24] 8779 	mov	ar4,@r1
      002C8E 09               [12] 8780 	inc	r1
      002C8F 87 05            [24] 8781 	mov	ar5,@r1
      002C91 09               [12] 8782 	inc	r1
      002C92 87 06            [24] 8783 	mov	ar6,@r1
      002C94 09               [12] 8784 	inc	r1
      002C95 87 07            [24] 8785 	mov	ar7,@r1
      002C97 8C 82            [24] 8786 	mov	dpl, r4
      002C99 8D 83            [24] 8787 	mov	dph, r5
      002C9B 8E F0            [24] 8788 	mov	b, r6
      002C9D EF               [12] 8789 	mov	a, r7
      002C9E                       8790 00104$:
                           002BE7  8791 	C$fuzzy.h$2980$1_0$136 ==.
                                   8792 ;	../../fuzzy.h:2980: }
      002C9E 85 08 81         [24] 8793 	mov	sp,_bp
      002CA1 D0 08            [24] 8794 	pop	_bp
                           002BEC  8795 	C$fuzzy.h$2980$1_0$136 ==.
                           002BEC  8796 	XG$fuzzy_rules_defuzzify_lom$0$0 ==.
      002CA3 22               [24] 8797 	ret
                                   8798 ;------------------------------------------------------------
                                   8799 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_method'
                                   8800 ;------------------------------------------------------------
                                   8801 ;lower         Allocated to stack - _bp -6 +4 
                                   8802 ;upper         Allocated to stack - _bp -10 +4 
                                   8803 ;step          Allocated to stack - _bp -14 +4 
                                   8804 ;defuzz_method Allocated to stack - _bp -15 +1 
                                   8805 ;implication_method Allocated to stack - _bp -16 +1 
                                   8806 ;aggregation_method Allocated to stack - _bp -17 +1 
                                   8807 ;rules         Allocated to registers r5 r6 r7 
                                   8808 ;sloc0         Allocated to stack - _bp +1 +4 
                                   8809 ;------------------------------------------------------------
                           002BED  8810 	G$fuzzy_rules_defuzzify_method$0$0 ==.
                           002BED  8811 	C$fuzzy.h$2986$1_0$139 ==.
                                   8812 ;	../../fuzzy.h:2986: float fuzzy_rules_defuzzify_method(
                                   8813 ;	-----------------------------------------
                                   8814 ;	 function fuzzy_rules_defuzzify_method
                                   8815 ;	-----------------------------------------
      002CA4                       8816 _fuzzy_rules_defuzzify_method:
      002CA4 C0 08            [24] 8817 	push	_bp
      002CA6 E5 81            [12] 8818 	mov	a,sp
      002CA8 F5 08            [12] 8819 	mov	_bp,a
      002CAA 24 04            [12] 8820 	add	a,#0x04
      002CAC F5 81            [12] 8821 	mov	sp,a
      002CAE AD 82            [24] 8822 	mov	r5, dpl
      002CB0 AE 83            [24] 8823 	mov	r6, dph
      002CB2 AF F0            [24] 8824 	mov	r7, b
                           002BFD  8825 	C$fuzzy.h$2997$1_0$139 ==.
                                   8826 ;	../../fuzzy.h:2997: rules == NULL ||
      002CB4 ED               [12] 8827 	mov	a,r5
      002CB5 4E               [12] 8828 	orl	a,r6
      002CB6 70 03            [24] 8829 	jnz	00140$
      002CB8 02 2D 49         [24] 8830 	ljmp	00101$
      002CBB                       8831 00140$:
                           002C04  8832 	C$fuzzy.h$2998$1_0$139 ==.
                                   8833 ;	../../fuzzy.h:2998: rules->count == 0u ||
      002CBB 74 90            [12] 8834 	mov	a,#0x90
      002CBD 2D               [12] 8835 	add	a, r5
      002CBE FA               [12] 8836 	mov	r2,a
      002CBF E4               [12] 8837 	clr	a
      002CC0 3E               [12] 8838 	addc	a, r6
      002CC1 FB               [12] 8839 	mov	r3,a
      002CC2 8F 04            [24] 8840 	mov	ar4,r7
      002CC4 8A 82            [24] 8841 	mov	dpl,r2
      002CC6 8B 83            [24] 8842 	mov	dph,r3
      002CC8 8C F0            [24] 8843 	mov	b,r4
      002CCA 12 37 EE         [24] 8844 	lcall	__gptrget
      002CCD FA               [12] 8845 	mov	r2,a
      002CCE A3               [24] 8846 	inc	dptr
      002CCF 12 37 EE         [24] 8847 	lcall	__gptrget
      002CD2 4A               [12] 8848 	orl	a,r2
      002CD3 60 74            [24] 8849 	jz	00101$
                           002C1E  8850 	C$fuzzy.h$2999$1_0$139 ==.
                                   8851 ;	../../fuzzy.h:2999: lower > upper ||
      002CD5 C0 07            [24] 8852 	push	ar7
      002CD7 C0 06            [24] 8853 	push	ar6
      002CD9 C0 05            [24] 8854 	push	ar5
      002CDB E5 08            [12] 8855 	mov	a,_bp
      002CDD 24 FA            [12] 8856 	add	a,#0xfa
      002CDF F8               [12] 8857 	mov	r0,a
      002CE0 E6               [12] 8858 	mov	a,@r0
      002CE1 C0 E0            [24] 8859 	push	acc
      002CE3 08               [12] 8860 	inc	r0
      002CE4 E6               [12] 8861 	mov	a,@r0
      002CE5 C0 E0            [24] 8862 	push	acc
      002CE7 08               [12] 8863 	inc	r0
      002CE8 E6               [12] 8864 	mov	a,@r0
      002CE9 C0 E0            [24] 8865 	push	acc
      002CEB 08               [12] 8866 	inc	r0
      002CEC E6               [12] 8867 	mov	a,@r0
      002CED C0 E0            [24] 8868 	push	acc
      002CEF E5 08            [12] 8869 	mov	a,_bp
      002CF1 24 F6            [12] 8870 	add	a,#0xf6
      002CF3 F8               [12] 8871 	mov	r0,a
      002CF4 86 82            [24] 8872 	mov	dpl, @r0
      002CF6 08               [12] 8873 	inc	r0
      002CF7 86 83            [24] 8874 	mov	dph, @r0
      002CF9 08               [12] 8875 	inc	r0
      002CFA 86 F0            [24] 8876 	mov	b, @r0
      002CFC 08               [12] 8877 	inc	r0
      002CFD E6               [12] 8878 	mov	a, @r0
      002CFE 12 35 C2         [24] 8879 	lcall	___fslt
      002D01 AC 82            [24] 8880 	mov	r4, dpl
      002D03 E5 81            [12] 8881 	mov	a,sp
      002D05 24 FC            [12] 8882 	add	a,#0xfc
      002D07 F5 81            [12] 8883 	mov	sp,a
      002D09 D0 05            [24] 8884 	pop	ar5
      002D0B D0 06            [24] 8885 	pop	ar6
      002D0D D0 07            [24] 8886 	pop	ar7
      002D0F EC               [12] 8887 	mov	a,r4
      002D10 70 37            [24] 8888 	jnz	00101$
                           002C5B  8889 	C$fuzzy.h$3001$1_0$139 ==.
                                   8890 ;	../../fuzzy.h:3001: ) {
      002D12 C0 07            [24] 8891 	push	ar7
      002D14 C0 06            [24] 8892 	push	ar6
      002D16 C0 05            [24] 8893 	push	ar5
      002D18 E5 08            [12] 8894 	mov	a,_bp
      002D1A 24 F2            [12] 8895 	add	a,#0xf2
      002D1C F8               [12] 8896 	mov	r0,a
      002D1D E6               [12] 8897 	mov	a,@r0
      002D1E C0 E0            [24] 8898 	push	acc
      002D20 08               [12] 8899 	inc	r0
      002D21 E6               [12] 8900 	mov	a,@r0
      002D22 C0 E0            [24] 8901 	push	acc
      002D24 08               [12] 8902 	inc	r0
      002D25 E6               [12] 8903 	mov	a,@r0
      002D26 C0 E0            [24] 8904 	push	acc
      002D28 08               [12] 8905 	inc	r0
      002D29 E6               [12] 8906 	mov	a,@r0
      002D2A C0 E0            [24] 8907 	push	acc
      002D2C 90 00 00         [24] 8908 	mov	dptr,#0x0000
      002D2F E4               [12] 8909 	clr	a
      002D30 F5 F0            [12] 8910 	mov	b,a
      002D32 12 35 C2         [24] 8911 	lcall	___fslt
      002D35 E5 81            [12] 8912 	mov	a,sp
      002D37 24 FC            [12] 8913 	add	a,#0xfc
      002D39 F5 81            [12] 8914 	mov	sp,a
      002D3B D0 05            [24] 8915 	pop	ar5
      002D3D D0 06            [24] 8916 	pop	ar6
      002D3F D0 07            [24] 8917 	pop	ar7
      002D41 E5 82            [12] 8918 	mov	a, dpl
      002D43 24 FF            [12] 8919 	add	a,#0xff
      002D45 92 00            [24] 8920 	mov	b0,c
      002D47 40 09            [24] 8921 	jc	00102$
      002D49                       8922 00101$:
                           002C92  8923 	C$fuzzy.h$3002$2_0$140 ==.
                                   8924 ;	../../fuzzy.h:3002: return 0.0f;
      002D49 90 00 00         [24] 8925 	mov	dptr,#0x0000
      002D4C E4               [12] 8926 	clr	a
      002D4D F5 F0            [12] 8927 	mov	b,a
      002D4F 02 30 3D         [24] 8928 	ljmp	00114$
      002D52                       8929 00102$:
                           002C9B  8930 	C$fuzzy.h$3005$1_0$139 ==.
                                   8931 ;	../../fuzzy.h:3005: switch (defuzz_method) {
      002D52 E5 08            [12] 8932 	mov	a,_bp
      002D54 24 F1            [12] 8933 	add	a,#0xf1
      002D56 F8               [12] 8934 	mov	r0,a
      002D57 E6               [12] 8935 	mov	a,@r0
      002D58 24 FA            [12] 8936 	add	a,#0xff - 0x05
      002D5A 50 03            [24] 8937 	jnc	00144$
      002D5C 02 30 37         [24] 8938 	ljmp	00112$
      002D5F                       8939 00144$:
      002D5F E5 08            [12] 8940 	mov	a,_bp
      002D61 24 F1            [12] 8941 	add	a,#0xf1
      002D63 F8               [12] 8942 	mov	r0,a
      002D64 E6               [12] 8943 	mov	a,@r0
      002D65 26               [12] 8944 	add	a,@r0
      002D66 26               [12] 8945 	add	a,@r0
      002D67 90 2D 6B         [24] 8946 	mov	dptr,#00145$
      002D6A 73               [24] 8947 	jmp	@a+dptr
      002D6B                       8948 00145$:
      002D6B 02 2D 7D         [24] 8949 	ljmp	00106$
      002D6E 02 2D F5         [24] 8950 	ljmp	00107$
      002D71 02 2E 6D         [24] 8951 	ljmp	00108$
      002D74 02 2E DD         [24] 8952 	ljmp	00109$
      002D77 02 2F 55         [24] 8953 	ljmp	00110$
      002D7A 02 2F CC         [24] 8954 	ljmp	00111$
                           002CC6  8955 	C$fuzzy.h$3006$2_0$141 ==.
                                   8956 ;	../../fuzzy.h:3006: case FUZZY_DEFUZZ_COG:
      002D7D                       8957 00106$:
                           002CC6  8958 	C$fuzzy.h$3008$2_0$141 ==.
                                   8959 ;	../../fuzzy.h:3008: rules,
      002D7D E5 08            [12] 8960 	mov	a,_bp
      002D7F 24 EF            [12] 8961 	add	a,#0xef
      002D81 F8               [12] 8962 	mov	r0,a
      002D82 E6               [12] 8963 	mov	a,@r0
      002D83 C0 E0            [24] 8964 	push	acc
      002D85 E5 08            [12] 8965 	mov	a,_bp
      002D87 24 F0            [12] 8966 	add	a,#0xf0
      002D89 F8               [12] 8967 	mov	r0,a
      002D8A E6               [12] 8968 	mov	a,@r0
      002D8B C0 E0            [24] 8969 	push	acc
      002D8D E5 08            [12] 8970 	mov	a,_bp
      002D8F 24 F2            [12] 8971 	add	a,#0xf2
      002D91 F8               [12] 8972 	mov	r0,a
      002D92 E6               [12] 8973 	mov	a,@r0
      002D93 C0 E0            [24] 8974 	push	acc
      002D95 08               [12] 8975 	inc	r0
      002D96 E6               [12] 8976 	mov	a,@r0
      002D97 C0 E0            [24] 8977 	push	acc
      002D99 08               [12] 8978 	inc	r0
      002D9A E6               [12] 8979 	mov	a,@r0
      002D9B C0 E0            [24] 8980 	push	acc
      002D9D 08               [12] 8981 	inc	r0
      002D9E E6               [12] 8982 	mov	a,@r0
      002D9F C0 E0            [24] 8983 	push	acc
      002DA1 E5 08            [12] 8984 	mov	a,_bp
      002DA3 24 F6            [12] 8985 	add	a,#0xf6
      002DA5 F8               [12] 8986 	mov	r0,a
      002DA6 E6               [12] 8987 	mov	a,@r0
      002DA7 C0 E0            [24] 8988 	push	acc
      002DA9 08               [12] 8989 	inc	r0
      002DAA E6               [12] 8990 	mov	a,@r0
      002DAB C0 E0            [24] 8991 	push	acc
      002DAD 08               [12] 8992 	inc	r0
      002DAE E6               [12] 8993 	mov	a,@r0
      002DAF C0 E0            [24] 8994 	push	acc
      002DB1 08               [12] 8995 	inc	r0
      002DB2 E6               [12] 8996 	mov	a,@r0
      002DB3 C0 E0            [24] 8997 	push	acc
      002DB5 E5 08            [12] 8998 	mov	a,_bp
      002DB7 24 FA            [12] 8999 	add	a,#0xfa
      002DB9 F8               [12] 9000 	mov	r0,a
      002DBA E6               [12] 9001 	mov	a,@r0
      002DBB C0 E0            [24] 9002 	push	acc
      002DBD 08               [12] 9003 	inc	r0
      002DBE E6               [12] 9004 	mov	a,@r0
      002DBF C0 E0            [24] 9005 	push	acc
      002DC1 08               [12] 9006 	inc	r0
      002DC2 E6               [12] 9007 	mov	a,@r0
      002DC3 C0 E0            [24] 9008 	push	acc
      002DC5 08               [12] 9009 	inc	r0
      002DC6 E6               [12] 9010 	mov	a,@r0
      002DC7 C0 E0            [24] 9011 	push	acc
      002DC9 8D 82            [24] 9012 	mov	dpl, r5
      002DCB 8E 83            [24] 9013 	mov	dph, r6
      002DCD 8F F0            [24] 9014 	mov	b, r7
      002DCF 12 21 3F         [24] 9015 	lcall	_fuzzy_rules_defuzzify_cog
      002DD2 A8 08            [24] 9016 	mov	r0,_bp
      002DD4 08               [12] 9017 	inc	r0
      002DD5 A6 82            [24] 9018 	mov	@r0, dpl
      002DD7 08               [12] 9019 	inc	r0
      002DD8 A6 83            [24] 9020 	mov	@r0, dph
      002DDA 08               [12] 9021 	inc	r0
      002DDB A6 F0            [24] 9022 	mov	@r0, b
      002DDD 08               [12] 9023 	inc	r0
      002DDE F6               [12] 9024 	mov	@r0,a
      002DDF E5 81            [12] 9025 	mov	a,sp
      002DE1 24 F2            [12] 9026 	add	a,#0xf2
      002DE3 F5 81            [12] 9027 	mov	sp,a
      002DE5 A8 08            [24] 9028 	mov	r0,_bp
      002DE7 08               [12] 9029 	inc	r0
      002DE8 86 82            [24] 9030 	mov	dpl, @r0
      002DEA 08               [12] 9031 	inc	r0
      002DEB 86 83            [24] 9032 	mov	dph, @r0
      002DED 08               [12] 9033 	inc	r0
      002DEE 86 F0            [24] 9034 	mov	b, @r0
      002DF0 08               [12] 9035 	inc	r0
      002DF1 E6               [12] 9036 	mov	a, @r0
      002DF2 02 30 3D         [24] 9037 	ljmp	00114$
                           002D3E  9038 	C$fuzzy.h$3016$2_0$141 ==.
                                   9039 ;	../../fuzzy.h:3016: case FUZZY_DEFUZZ_BOA:
      002DF5                       9040 00107$:
                           002D3E  9041 	C$fuzzy.h$3018$2_0$141 ==.
                                   9042 ;	../../fuzzy.h:3018: rules,
      002DF5 E5 08            [12] 9043 	mov	a,_bp
      002DF7 24 EF            [12] 9044 	add	a,#0xef
      002DF9 F8               [12] 9045 	mov	r0,a
      002DFA E6               [12] 9046 	mov	a,@r0
      002DFB C0 E0            [24] 9047 	push	acc
      002DFD E5 08            [12] 9048 	mov	a,_bp
      002DFF 24 F0            [12] 9049 	add	a,#0xf0
      002E01 F8               [12] 9050 	mov	r0,a
      002E02 E6               [12] 9051 	mov	a,@r0
      002E03 C0 E0            [24] 9052 	push	acc
      002E05 E5 08            [12] 9053 	mov	a,_bp
      002E07 24 F2            [12] 9054 	add	a,#0xf2
      002E09 F8               [12] 9055 	mov	r0,a
      002E0A E6               [12] 9056 	mov	a,@r0
      002E0B C0 E0            [24] 9057 	push	acc
      002E0D 08               [12] 9058 	inc	r0
      002E0E E6               [12] 9059 	mov	a,@r0
      002E0F C0 E0            [24] 9060 	push	acc
      002E11 08               [12] 9061 	inc	r0
      002E12 E6               [12] 9062 	mov	a,@r0
      002E13 C0 E0            [24] 9063 	push	acc
      002E15 08               [12] 9064 	inc	r0
      002E16 E6               [12] 9065 	mov	a,@r0
      002E17 C0 E0            [24] 9066 	push	acc
      002E19 E5 08            [12] 9067 	mov	a,_bp
      002E1B 24 F6            [12] 9068 	add	a,#0xf6
      002E1D F8               [12] 9069 	mov	r0,a
      002E1E E6               [12] 9070 	mov	a,@r0
      002E1F C0 E0            [24] 9071 	push	acc
      002E21 08               [12] 9072 	inc	r0
      002E22 E6               [12] 9073 	mov	a,@r0
      002E23 C0 E0            [24] 9074 	push	acc
      002E25 08               [12] 9075 	inc	r0
      002E26 E6               [12] 9076 	mov	a,@r0
      002E27 C0 E0            [24] 9077 	push	acc
      002E29 08               [12] 9078 	inc	r0
      002E2A E6               [12] 9079 	mov	a,@r0
      002E2B C0 E0            [24] 9080 	push	acc
      002E2D E5 08            [12] 9081 	mov	a,_bp
      002E2F 24 FA            [12] 9082 	add	a,#0xfa
      002E31 F8               [12] 9083 	mov	r0,a
      002E32 E6               [12] 9084 	mov	a,@r0
      002E33 C0 E0            [24] 9085 	push	acc
      002E35 08               [12] 9086 	inc	r0
      002E36 E6               [12] 9087 	mov	a,@r0
      002E37 C0 E0            [24] 9088 	push	acc
      002E39 08               [12] 9089 	inc	r0
      002E3A E6               [12] 9090 	mov	a,@r0
      002E3B C0 E0            [24] 9091 	push	acc
      002E3D 08               [12] 9092 	inc	r0
      002E3E E6               [12] 9093 	mov	a,@r0
      002E3F C0 E0            [24] 9094 	push	acc
      002E41 8D 82            [24] 9095 	mov	dpl, r5
      002E43 8E 83            [24] 9096 	mov	dph, r6
      002E45 8F F0            [24] 9097 	mov	b, r7
      002E47 12 23 52         [24] 9098 	lcall	_fuzzy_rules_defuzzify_boa
      002E4A A8 08            [24] 9099 	mov	r0,_bp
      002E4C 08               [12] 9100 	inc	r0
      002E4D A6 82            [24] 9101 	mov	@r0, dpl
      002E4F 08               [12] 9102 	inc	r0
      002E50 A6 83            [24] 9103 	mov	@r0, dph
      002E52 08               [12] 9104 	inc	r0
      002E53 A6 F0            [24] 9105 	mov	@r0, b
      002E55 08               [12] 9106 	inc	r0
      002E56 F6               [12] 9107 	mov	@r0,a
      002E57 E5 81            [12] 9108 	mov	a,sp
      002E59 24 F2            [12] 9109 	add	a,#0xf2
      002E5B F5 81            [12] 9110 	mov	sp,a
      002E5D A8 08            [24] 9111 	mov	r0,_bp
      002E5F 08               [12] 9112 	inc	r0
      002E60 86 82            [24] 9113 	mov	dpl, @r0
      002E62 08               [12] 9114 	inc	r0
      002E63 86 83            [24] 9115 	mov	dph, @r0
      002E65 08               [12] 9116 	inc	r0
      002E66 86 F0            [24] 9117 	mov	b, @r0
      002E68 08               [12] 9118 	inc	r0
      002E69 E6               [12] 9119 	mov	a, @r0
      002E6A 02 30 3D         [24] 9120 	ljmp	00114$
                           002DB6  9121 	C$fuzzy.h$3026$2_0$141 ==.
                                   9122 ;	../../fuzzy.h:3026: case FUZZY_DEFUZZ_COS:
      002E6D                       9123 00108$:
                           002DB6  9124 	C$fuzzy.h$3028$2_0$141 ==.
                                   9125 ;	../../fuzzy.h:3028: rules,
      002E6D E5 08            [12] 9126 	mov	a,_bp
      002E6F 24 F0            [12] 9127 	add	a,#0xf0
      002E71 F8               [12] 9128 	mov	r0,a
      002E72 E6               [12] 9129 	mov	a,@r0
      002E73 C0 E0            [24] 9130 	push	acc
      002E75 E5 08            [12] 9131 	mov	a,_bp
      002E77 24 F2            [12] 9132 	add	a,#0xf2
      002E79 F8               [12] 9133 	mov	r0,a
      002E7A E6               [12] 9134 	mov	a,@r0
      002E7B C0 E0            [24] 9135 	push	acc
      002E7D 08               [12] 9136 	inc	r0
      002E7E E6               [12] 9137 	mov	a,@r0
      002E7F C0 E0            [24] 9138 	push	acc
      002E81 08               [12] 9139 	inc	r0
      002E82 E6               [12] 9140 	mov	a,@r0
      002E83 C0 E0            [24] 9141 	push	acc
      002E85 08               [12] 9142 	inc	r0
      002E86 E6               [12] 9143 	mov	a,@r0
      002E87 C0 E0            [24] 9144 	push	acc
      002E89 E5 08            [12] 9145 	mov	a,_bp
      002E8B 24 F6            [12] 9146 	add	a,#0xf6
      002E8D F8               [12] 9147 	mov	r0,a
      002E8E E6               [12] 9148 	mov	a,@r0
      002E8F C0 E0            [24] 9149 	push	acc
      002E91 08               [12] 9150 	inc	r0
      002E92 E6               [12] 9151 	mov	a,@r0
      002E93 C0 E0            [24] 9152 	push	acc
      002E95 08               [12] 9153 	inc	r0
      002E96 E6               [12] 9154 	mov	a,@r0
      002E97 C0 E0            [24] 9155 	push	acc
      002E99 08               [12] 9156 	inc	r0
      002E9A E6               [12] 9157 	mov	a,@r0
      002E9B C0 E0            [24] 9158 	push	acc
      002E9D E5 08            [12] 9159 	mov	a,_bp
      002E9F 24 FA            [12] 9160 	add	a,#0xfa
      002EA1 F8               [12] 9161 	mov	r0,a
      002EA2 E6               [12] 9162 	mov	a,@r0
      002EA3 C0 E0            [24] 9163 	push	acc
      002EA5 08               [12] 9164 	inc	r0
      002EA6 E6               [12] 9165 	mov	a,@r0
      002EA7 C0 E0            [24] 9166 	push	acc
      002EA9 08               [12] 9167 	inc	r0
      002EAA E6               [12] 9168 	mov	a,@r0
      002EAB C0 E0            [24] 9169 	push	acc
      002EAD 08               [12] 9170 	inc	r0
      002EAE E6               [12] 9171 	mov	a,@r0
      002EAF C0 E0            [24] 9172 	push	acc
      002EB1 8D 82            [24] 9173 	mov	dpl, r5
      002EB3 8E 83            [24] 9174 	mov	dph, r6
      002EB5 8F F0            [24] 9175 	mov	b, r7
      002EB7 12 26 38         [24] 9176 	lcall	_fuzzy_rules_defuzzify_cos
      002EBA A8 08            [24] 9177 	mov	r0,_bp
      002EBC 08               [12] 9178 	inc	r0
      002EBD A6 82            [24] 9179 	mov	@r0, dpl
      002EBF 08               [12] 9180 	inc	r0
      002EC0 A6 83            [24] 9181 	mov	@r0, dph
      002EC2 08               [12] 9182 	inc	r0
      002EC3 A6 F0            [24] 9183 	mov	@r0, b
      002EC5 08               [12] 9184 	inc	r0
      002EC6 F6               [12] 9185 	mov	@r0,a
      002EC7 E5 81            [12] 9186 	mov	a,sp
      002EC9 24 F3            [12] 9187 	add	a,#0xf3
      002ECB F5 81            [12] 9188 	mov	sp,a
      002ECD A8 08            [24] 9189 	mov	r0,_bp
      002ECF 08               [12] 9190 	inc	r0
      002ED0 86 82            [24] 9191 	mov	dpl, @r0
      002ED2 08               [12] 9192 	inc	r0
      002ED3 86 83            [24] 9193 	mov	dph, @r0
      002ED5 08               [12] 9194 	inc	r0
      002ED6 86 F0            [24] 9195 	mov	b, @r0
      002ED8 08               [12] 9196 	inc	r0
      002ED9 E6               [12] 9197 	mov	a, @r0
      002EDA 02 30 3D         [24] 9198 	ljmp	00114$
                           002E26  9199 	C$fuzzy.h$3035$2_0$141 ==.
                                   9200 ;	../../fuzzy.h:3035: case FUZZY_DEFUZZ_MOM:
      002EDD                       9201 00109$:
                           002E26  9202 	C$fuzzy.h$3037$2_0$141 ==.
                                   9203 ;	../../fuzzy.h:3037: rules,
      002EDD E5 08            [12] 9204 	mov	a,_bp
      002EDF 24 EF            [12] 9205 	add	a,#0xef
      002EE1 F8               [12] 9206 	mov	r0,a
      002EE2 E6               [12] 9207 	mov	a,@r0
      002EE3 C0 E0            [24] 9208 	push	acc
      002EE5 E5 08            [12] 9209 	mov	a,_bp
      002EE7 24 F0            [12] 9210 	add	a,#0xf0
      002EE9 F8               [12] 9211 	mov	r0,a
      002EEA E6               [12] 9212 	mov	a,@r0
      002EEB C0 E0            [24] 9213 	push	acc
      002EED E5 08            [12] 9214 	mov	a,_bp
      002EEF 24 F2            [12] 9215 	add	a,#0xf2
      002EF1 F8               [12] 9216 	mov	r0,a
      002EF2 E6               [12] 9217 	mov	a,@r0
      002EF3 C0 E0            [24] 9218 	push	acc
      002EF5 08               [12] 9219 	inc	r0
      002EF6 E6               [12] 9220 	mov	a,@r0
      002EF7 C0 E0            [24] 9221 	push	acc
      002EF9 08               [12] 9222 	inc	r0
      002EFA E6               [12] 9223 	mov	a,@r0
      002EFB C0 E0            [24] 9224 	push	acc
      002EFD 08               [12] 9225 	inc	r0
      002EFE E6               [12] 9226 	mov	a,@r0
      002EFF C0 E0            [24] 9227 	push	acc
      002F01 E5 08            [12] 9228 	mov	a,_bp
      002F03 24 F6            [12] 9229 	add	a,#0xf6
      002F05 F8               [12] 9230 	mov	r0,a
      002F06 E6               [12] 9231 	mov	a,@r0
      002F07 C0 E0            [24] 9232 	push	acc
      002F09 08               [12] 9233 	inc	r0
      002F0A E6               [12] 9234 	mov	a,@r0
      002F0B C0 E0            [24] 9235 	push	acc
      002F0D 08               [12] 9236 	inc	r0
      002F0E E6               [12] 9237 	mov	a,@r0
      002F0F C0 E0            [24] 9238 	push	acc
      002F11 08               [12] 9239 	inc	r0
      002F12 E6               [12] 9240 	mov	a,@r0
      002F13 C0 E0            [24] 9241 	push	acc
      002F15 E5 08            [12] 9242 	mov	a,_bp
      002F17 24 FA            [12] 9243 	add	a,#0xfa
      002F19 F8               [12] 9244 	mov	r0,a
      002F1A E6               [12] 9245 	mov	a,@r0
      002F1B C0 E0            [24] 9246 	push	acc
      002F1D 08               [12] 9247 	inc	r0
      002F1E E6               [12] 9248 	mov	a,@r0
      002F1F C0 E0            [24] 9249 	push	acc
      002F21 08               [12] 9250 	inc	r0
      002F22 E6               [12] 9251 	mov	a,@r0
      002F23 C0 E0            [24] 9252 	push	acc
      002F25 08               [12] 9253 	inc	r0
      002F26 E6               [12] 9254 	mov	a,@r0
      002F27 C0 E0            [24] 9255 	push	acc
      002F29 8D 82            [24] 9256 	mov	dpl, r5
      002F2B 8E 83            [24] 9257 	mov	dph, r6
      002F2D 8F F0            [24] 9258 	mov	b, r7
      002F2F 12 29 9B         [24] 9259 	lcall	_fuzzy_rules_defuzzify_mom
      002F32 A8 08            [24] 9260 	mov	r0,_bp
      002F34 08               [12] 9261 	inc	r0
      002F35 A6 82            [24] 9262 	mov	@r0, dpl
      002F37 08               [12] 9263 	inc	r0
      002F38 A6 83            [24] 9264 	mov	@r0, dph
      002F3A 08               [12] 9265 	inc	r0
      002F3B A6 F0            [24] 9266 	mov	@r0, b
      002F3D 08               [12] 9267 	inc	r0
      002F3E F6               [12] 9268 	mov	@r0,a
      002F3F E5 81            [12] 9269 	mov	a,sp
      002F41 24 F2            [12] 9270 	add	a,#0xf2
      002F43 F5 81            [12] 9271 	mov	sp,a
      002F45 A8 08            [24] 9272 	mov	r0,_bp
      002F47 08               [12] 9273 	inc	r0
      002F48 86 82            [24] 9274 	mov	dpl, @r0
      002F4A 08               [12] 9275 	inc	r0
      002F4B 86 83            [24] 9276 	mov	dph, @r0
      002F4D 08               [12] 9277 	inc	r0
      002F4E 86 F0            [24] 9278 	mov	b, @r0
      002F50 08               [12] 9279 	inc	r0
      002F51 E6               [12] 9280 	mov	a, @r0
      002F52 02 30 3D         [24] 9281 	ljmp	00114$
                           002E9E  9282 	C$fuzzy.h$3045$2_0$141 ==.
                                   9283 ;	../../fuzzy.h:3045: case FUZZY_DEFUZZ_SOM:
      002F55                       9284 00110$:
                           002E9E  9285 	C$fuzzy.h$3047$2_0$141 ==.
                                   9286 ;	../../fuzzy.h:3047: rules,
      002F55 E5 08            [12] 9287 	mov	a,_bp
      002F57 24 EF            [12] 9288 	add	a,#0xef
      002F59 F8               [12] 9289 	mov	r0,a
      002F5A E6               [12] 9290 	mov	a,@r0
      002F5B C0 E0            [24] 9291 	push	acc
      002F5D E5 08            [12] 9292 	mov	a,_bp
      002F5F 24 F0            [12] 9293 	add	a,#0xf0
      002F61 F8               [12] 9294 	mov	r0,a
      002F62 E6               [12] 9295 	mov	a,@r0
      002F63 C0 E0            [24] 9296 	push	acc
      002F65 E5 08            [12] 9297 	mov	a,_bp
      002F67 24 F2            [12] 9298 	add	a,#0xf2
      002F69 F8               [12] 9299 	mov	r0,a
      002F6A E6               [12] 9300 	mov	a,@r0
      002F6B C0 E0            [24] 9301 	push	acc
      002F6D 08               [12] 9302 	inc	r0
      002F6E E6               [12] 9303 	mov	a,@r0
      002F6F C0 E0            [24] 9304 	push	acc
      002F71 08               [12] 9305 	inc	r0
      002F72 E6               [12] 9306 	mov	a,@r0
      002F73 C0 E0            [24] 9307 	push	acc
      002F75 08               [12] 9308 	inc	r0
      002F76 E6               [12] 9309 	mov	a,@r0
      002F77 C0 E0            [24] 9310 	push	acc
      002F79 E5 08            [12] 9311 	mov	a,_bp
      002F7B 24 F6            [12] 9312 	add	a,#0xf6
      002F7D F8               [12] 9313 	mov	r0,a
      002F7E E6               [12] 9314 	mov	a,@r0
      002F7F C0 E0            [24] 9315 	push	acc
      002F81 08               [12] 9316 	inc	r0
      002F82 E6               [12] 9317 	mov	a,@r0
      002F83 C0 E0            [24] 9318 	push	acc
      002F85 08               [12] 9319 	inc	r0
      002F86 E6               [12] 9320 	mov	a,@r0
      002F87 C0 E0            [24] 9321 	push	acc
      002F89 08               [12] 9322 	inc	r0
      002F8A E6               [12] 9323 	mov	a,@r0
      002F8B C0 E0            [24] 9324 	push	acc
      002F8D E5 08            [12] 9325 	mov	a,_bp
      002F8F 24 FA            [12] 9326 	add	a,#0xfa
      002F91 F8               [12] 9327 	mov	r0,a
      002F92 E6               [12] 9328 	mov	a,@r0
      002F93 C0 E0            [24] 9329 	push	acc
      002F95 08               [12] 9330 	inc	r0
      002F96 E6               [12] 9331 	mov	a,@r0
      002F97 C0 E0            [24] 9332 	push	acc
      002F99 08               [12] 9333 	inc	r0
      002F9A E6               [12] 9334 	mov	a,@r0
      002F9B C0 E0            [24] 9335 	push	acc
      002F9D 08               [12] 9336 	inc	r0
      002F9E E6               [12] 9337 	mov	a,@r0
      002F9F C0 E0            [24] 9338 	push	acc
      002FA1 8D 82            [24] 9339 	mov	dpl, r5
      002FA3 8E 83            [24] 9340 	mov	dph, r6
      002FA5 8F F0            [24] 9341 	mov	b, r7
      002FA7 12 2A D2         [24] 9342 	lcall	_fuzzy_rules_defuzzify_som
      002FAA A8 08            [24] 9343 	mov	r0,_bp
      002FAC 08               [12] 9344 	inc	r0
      002FAD A6 82            [24] 9345 	mov	@r0, dpl
      002FAF 08               [12] 9346 	inc	r0
      002FB0 A6 83            [24] 9347 	mov	@r0, dph
      002FB2 08               [12] 9348 	inc	r0
      002FB3 A6 F0            [24] 9349 	mov	@r0, b
      002FB5 08               [12] 9350 	inc	r0
      002FB6 F6               [12] 9351 	mov	@r0,a
      002FB7 E5 81            [12] 9352 	mov	a,sp
      002FB9 24 F2            [12] 9353 	add	a,#0xf2
      002FBB F5 81            [12] 9354 	mov	sp,a
      002FBD A8 08            [24] 9355 	mov	r0,_bp
      002FBF 08               [12] 9356 	inc	r0
      002FC0 86 82            [24] 9357 	mov	dpl, @r0
      002FC2 08               [12] 9358 	inc	r0
      002FC3 86 83            [24] 9359 	mov	dph, @r0
      002FC5 08               [12] 9360 	inc	r0
      002FC6 86 F0            [24] 9361 	mov	b, @r0
      002FC8 08               [12] 9362 	inc	r0
      002FC9 E6               [12] 9363 	mov	a, @r0
                           002F13  9364 	C$fuzzy.h$3055$2_0$141 ==.
                                   9365 ;	../../fuzzy.h:3055: case FUZZY_DEFUZZ_LOM:
      002FCA 80 71            [24] 9366 	sjmp	00114$
      002FCC                       9367 00111$:
                           002F15  9368 	C$fuzzy.h$3057$2_0$141 ==.
                                   9369 ;	../../fuzzy.h:3057: rules,
      002FCC E5 08            [12] 9370 	mov	a,_bp
      002FCE 24 EF            [12] 9371 	add	a,#0xef
      002FD0 F8               [12] 9372 	mov	r0,a
      002FD1 E6               [12] 9373 	mov	a,@r0
      002FD2 C0 E0            [24] 9374 	push	acc
      002FD4 E5 08            [12] 9375 	mov	a,_bp
      002FD6 24 F0            [12] 9376 	add	a,#0xf0
      002FD8 F8               [12] 9377 	mov	r0,a
      002FD9 E6               [12] 9378 	mov	a,@r0
      002FDA C0 E0            [24] 9379 	push	acc
      002FDC E5 08            [12] 9380 	mov	a,_bp
      002FDE 24 F2            [12] 9381 	add	a,#0xf2
      002FE0 F8               [12] 9382 	mov	r0,a
      002FE1 E6               [12] 9383 	mov	a,@r0
      002FE2 C0 E0            [24] 9384 	push	acc
      002FE4 08               [12] 9385 	inc	r0
      002FE5 E6               [12] 9386 	mov	a,@r0
      002FE6 C0 E0            [24] 9387 	push	acc
      002FE8 08               [12] 9388 	inc	r0
      002FE9 E6               [12] 9389 	mov	a,@r0
      002FEA C0 E0            [24] 9390 	push	acc
      002FEC 08               [12] 9391 	inc	r0
      002FED E6               [12] 9392 	mov	a,@r0
      002FEE C0 E0            [24] 9393 	push	acc
      002FF0 E5 08            [12] 9394 	mov	a,_bp
      002FF2 24 F6            [12] 9395 	add	a,#0xf6
      002FF4 F8               [12] 9396 	mov	r0,a
      002FF5 E6               [12] 9397 	mov	a,@r0
      002FF6 C0 E0            [24] 9398 	push	acc
      002FF8 08               [12] 9399 	inc	r0
      002FF9 E6               [12] 9400 	mov	a,@r0
      002FFA C0 E0            [24] 9401 	push	acc
      002FFC 08               [12] 9402 	inc	r0
      002FFD E6               [12] 9403 	mov	a,@r0
      002FFE C0 E0            [24] 9404 	push	acc
      003000 08               [12] 9405 	inc	r0
      003001 E6               [12] 9406 	mov	a,@r0
      003002 C0 E0            [24] 9407 	push	acc
      003004 E5 08            [12] 9408 	mov	a,_bp
      003006 24 FA            [12] 9409 	add	a,#0xfa
      003008 F8               [12] 9410 	mov	r0,a
      003009 E6               [12] 9411 	mov	a,@r0
      00300A C0 E0            [24] 9412 	push	acc
      00300C 08               [12] 9413 	inc	r0
      00300D E6               [12] 9414 	mov	a,@r0
      00300E C0 E0            [24] 9415 	push	acc
      003010 08               [12] 9416 	inc	r0
      003011 E6               [12] 9417 	mov	a,@r0
      003012 C0 E0            [24] 9418 	push	acc
      003014 08               [12] 9419 	inc	r0
      003015 E6               [12] 9420 	mov	a,@r0
      003016 C0 E0            [24] 9421 	push	acc
      003018 8D 82            [24] 9422 	mov	dpl, r5
      00301A 8E 83            [24] 9423 	mov	dph, r6
      00301C 8F F0            [24] 9424 	mov	b, r7
      00301E 12 2B BB         [24] 9425 	lcall	_fuzzy_rules_defuzzify_lom
      003021 AC 82            [24] 9426 	mov	r4, dpl
      003023 AD 83            [24] 9427 	mov	r5, dph
      003025 AE F0            [24] 9428 	mov	r6, b
      003027 FF               [12] 9429 	mov	r7, a
      003028 E5 81            [12] 9430 	mov	a,sp
      00302A 24 F2            [12] 9431 	add	a,#0xf2
      00302C F5 81            [12] 9432 	mov	sp,a
      00302E 8C 82            [24] 9433 	mov	dpl, r4
      003030 8D 83            [24] 9434 	mov	dph, r5
      003032 8E F0            [24] 9435 	mov	b, r6
      003034 EF               [12] 9436 	mov	a, r7
                           002F7E  9437 	C$fuzzy.h$3065$2_0$141 ==.
                                   9438 ;	../../fuzzy.h:3065: default:
      003035 80 06            [24] 9439 	sjmp	00114$
      003037                       9440 00112$:
                           002F80  9441 	C$fuzzy.h$3066$2_0$141 ==.
                                   9442 ;	../../fuzzy.h:3066: return 0.0f;
      003037 90 00 00         [24] 9443 	mov	dptr,#0x0000
      00303A E4               [12] 9444 	clr	a
      00303B F5 F0            [12] 9445 	mov	b,a
                           002F86  9446 	C$fuzzy.h$3067$1_0$139 ==.
                                   9447 ;	../../fuzzy.h:3067: }
      00303D                       9448 00114$:
                           002F86  9449 	C$fuzzy.h$3068$1_0$139 ==.
                                   9450 ;	../../fuzzy.h:3068: }
      00303D 85 08 81         [24] 9451 	mov	sp,_bp
      003040 D0 08            [24] 9452 	pop	_bp
                           002F8B  9453 	C$fuzzy.h$3068$1_0$139 ==.
                           002F8B  9454 	XG$fuzzy_rules_defuzzify_method$0$0 ==.
      003042 22               [24] 9455 	ret
                                   9456 ;------------------------------------------------------------
                                   9457 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify'
                                   9458 ;------------------------------------------------------------
                                   9459 ;lower         Allocated to stack - _bp -6 +4 
                                   9460 ;upper         Allocated to stack - _bp -10 +4 
                                   9461 ;step          Allocated to stack - _bp -14 +4 
                                   9462 ;method        Allocated to stack - _bp -15 +1 
                                   9463 ;rules         Allocated to registers r5 r6 r7 
                                   9464 ;------------------------------------------------------------
                           002F8C  9465 	G$fuzzy_rules_defuzzify$0$0 ==.
                           002F8C  9466 	C$fuzzy.h$3075$1_0$143 ==.
                                   9467 ;	../../fuzzy.h:3075: float fuzzy_rules_defuzzify(
                                   9468 ;	-----------------------------------------
                                   9469 ;	 function fuzzy_rules_defuzzify
                                   9470 ;	-----------------------------------------
      003043                       9471 _fuzzy_rules_defuzzify:
      003043 C0 08            [24] 9472 	push	_bp
      003045 85 81 08         [24] 9473 	mov	_bp,sp
      003048 AD 82            [24] 9474 	mov	r5, dpl
      00304A AE 83            [24] 9475 	mov	r6, dph
      00304C AF F0            [24] 9476 	mov	r7, b
                           002F97  9477 	C$fuzzy.h$3084$1_0$143 ==.
                                   9478 ;	../../fuzzy.h:3084: rules,
      00304E E4               [12] 9479 	clr	a
      00304F C0 E0            [24] 9480 	push	acc
      003051 C0 E0            [24] 9481 	push	acc
      003053 E5 08            [12] 9482 	mov	a,_bp
      003055 24 F1            [12] 9483 	add	a,#0xf1
      003057 F8               [12] 9484 	mov	r0,a
      003058 E6               [12] 9485 	mov	a,@r0
      003059 C0 E0            [24] 9486 	push	acc
      00305B E5 08            [12] 9487 	mov	a,_bp
      00305D 24 F2            [12] 9488 	add	a,#0xf2
      00305F F8               [12] 9489 	mov	r0,a
      003060 E6               [12] 9490 	mov	a,@r0
      003061 C0 E0            [24] 9491 	push	acc
      003063 08               [12] 9492 	inc	r0
      003064 E6               [12] 9493 	mov	a,@r0
      003065 C0 E0            [24] 9494 	push	acc
      003067 08               [12] 9495 	inc	r0
      003068 E6               [12] 9496 	mov	a,@r0
      003069 C0 E0            [24] 9497 	push	acc
      00306B 08               [12] 9498 	inc	r0
      00306C E6               [12] 9499 	mov	a,@r0
      00306D C0 E0            [24] 9500 	push	acc
      00306F E5 08            [12] 9501 	mov	a,_bp
      003071 24 F6            [12] 9502 	add	a,#0xf6
      003073 F8               [12] 9503 	mov	r0,a
      003074 E6               [12] 9504 	mov	a,@r0
      003075 C0 E0            [24] 9505 	push	acc
      003077 08               [12] 9506 	inc	r0
      003078 E6               [12] 9507 	mov	a,@r0
      003079 C0 E0            [24] 9508 	push	acc
      00307B 08               [12] 9509 	inc	r0
      00307C E6               [12] 9510 	mov	a,@r0
      00307D C0 E0            [24] 9511 	push	acc
      00307F 08               [12] 9512 	inc	r0
      003080 E6               [12] 9513 	mov	a,@r0
      003081 C0 E0            [24] 9514 	push	acc
      003083 E5 08            [12] 9515 	mov	a,_bp
      003085 24 FA            [12] 9516 	add	a,#0xfa
      003087 F8               [12] 9517 	mov	r0,a
      003088 E6               [12] 9518 	mov	a,@r0
      003089 C0 E0            [24] 9519 	push	acc
      00308B 08               [12] 9520 	inc	r0
      00308C E6               [12] 9521 	mov	a,@r0
      00308D C0 E0            [24] 9522 	push	acc
      00308F 08               [12] 9523 	inc	r0
      003090 E6               [12] 9524 	mov	a,@r0
      003091 C0 E0            [24] 9525 	push	acc
      003093 08               [12] 9526 	inc	r0
      003094 E6               [12] 9527 	mov	a,@r0
      003095 C0 E0            [24] 9528 	push	acc
      003097 8D 82            [24] 9529 	mov	dpl, r5
      003099 8E 83            [24] 9530 	mov	dph, r6
      00309B 8F F0            [24] 9531 	mov	b, r7
      00309D 12 2C A4         [24] 9532 	lcall	_fuzzy_rules_defuzzify_method
      0030A0 AC 82            [24] 9533 	mov	r4, dpl
      0030A2 AD 83            [24] 9534 	mov	r5, dph
      0030A4 AE F0            [24] 9535 	mov	r6, b
      0030A6 FF               [12] 9536 	mov	r7, a
      0030A7 E5 81            [12] 9537 	mov	a,sp
      0030A9 24 F1            [12] 9538 	add	a,#0xf1
      0030AB F5 81            [12] 9539 	mov	sp,a
      0030AD 8C 82            [24] 9540 	mov	dpl, r4
      0030AF 8D 83            [24] 9541 	mov	dph, r5
      0030B1 8E F0            [24] 9542 	mov	b, r6
      0030B3 EF               [12] 9543 	mov	a, r7
                           002FFD  9544 	C$fuzzy.h$3092$1_0$143 ==.
                                   9545 ;	../../fuzzy.h:3092: }
      0030B4 D0 08            [24] 9546 	pop	_bp
                           002FFF  9547 	C$fuzzy.h$3092$1_0$143 ==.
                           002FFF  9548 	XG$fuzzy_rules_defuzzify$0$0 ==.
      0030B6 22               [24] 9549 	ret
                                   9550 ;------------------------------------------------------------
                                   9551 ;Allocation info for local variables in function 'fuzzy_rules_cog'
                                   9552 ;------------------------------------------------------------
                                   9553 ;lower         Allocated to stack - _bp -6 +4 
                                   9554 ;upper         Allocated to stack - _bp -10 +4 
                                   9555 ;step          Allocated to stack - _bp -14 +4 
                                   9556 ;rules         Allocated to registers r5 r6 r7 
                                   9557 ;------------------------------------------------------------
                           003000  9558 	G$fuzzy_rules_cog$0$0 ==.
                           003000  9559 	C$fuzzy.h$3098$1_0$145 ==.
                                   9560 ;	../../fuzzy.h:3098: float fuzzy_rules_cog(
                                   9561 ;	-----------------------------------------
                                   9562 ;	 function fuzzy_rules_cog
                                   9563 ;	-----------------------------------------
      0030B7                       9564 _fuzzy_rules_cog:
      0030B7 C0 08            [24] 9565 	push	_bp
      0030B9 85 81 08         [24] 9566 	mov	_bp,sp
      0030BC AD 82            [24] 9567 	mov	r5, dpl
      0030BE AE 83            [24] 9568 	mov	r6, dph
      0030C0 AF F0            [24] 9569 	mov	r7, b
                           00300B  9570 	C$fuzzy.h$3106$1_0$145 ==.
                                   9571 ;	../../fuzzy.h:3106: rules,
      0030C2 E4               [12] 9572 	clr	a
      0030C3 C0 E0            [24] 9573 	push	acc
      0030C5 C0 E0            [24] 9574 	push	acc
      0030C7 E5 08            [12] 9575 	mov	a,_bp
      0030C9 24 F2            [12] 9576 	add	a,#0xf2
      0030CB F8               [12] 9577 	mov	r0,a
      0030CC E6               [12] 9578 	mov	a,@r0
      0030CD C0 E0            [24] 9579 	push	acc
      0030CF 08               [12] 9580 	inc	r0
      0030D0 E6               [12] 9581 	mov	a,@r0
      0030D1 C0 E0            [24] 9582 	push	acc
      0030D3 08               [12] 9583 	inc	r0
      0030D4 E6               [12] 9584 	mov	a,@r0
      0030D5 C0 E0            [24] 9585 	push	acc
      0030D7 08               [12] 9586 	inc	r0
      0030D8 E6               [12] 9587 	mov	a,@r0
      0030D9 C0 E0            [24] 9588 	push	acc
      0030DB E5 08            [12] 9589 	mov	a,_bp
      0030DD 24 F6            [12] 9590 	add	a,#0xf6
      0030DF F8               [12] 9591 	mov	r0,a
      0030E0 E6               [12] 9592 	mov	a,@r0
      0030E1 C0 E0            [24] 9593 	push	acc
      0030E3 08               [12] 9594 	inc	r0
      0030E4 E6               [12] 9595 	mov	a,@r0
      0030E5 C0 E0            [24] 9596 	push	acc
      0030E7 08               [12] 9597 	inc	r0
      0030E8 E6               [12] 9598 	mov	a,@r0
      0030E9 C0 E0            [24] 9599 	push	acc
      0030EB 08               [12] 9600 	inc	r0
      0030EC E6               [12] 9601 	mov	a,@r0
      0030ED C0 E0            [24] 9602 	push	acc
      0030EF E5 08            [12] 9603 	mov	a,_bp
      0030F1 24 FA            [12] 9604 	add	a,#0xfa
      0030F3 F8               [12] 9605 	mov	r0,a
      0030F4 E6               [12] 9606 	mov	a,@r0
      0030F5 C0 E0            [24] 9607 	push	acc
      0030F7 08               [12] 9608 	inc	r0
      0030F8 E6               [12] 9609 	mov	a,@r0
      0030F9 C0 E0            [24] 9610 	push	acc
      0030FB 08               [12] 9611 	inc	r0
      0030FC E6               [12] 9612 	mov	a,@r0
      0030FD C0 E0            [24] 9613 	push	acc
      0030FF 08               [12] 9614 	inc	r0
      003100 E6               [12] 9615 	mov	a,@r0
      003101 C0 E0            [24] 9616 	push	acc
      003103 8D 82            [24] 9617 	mov	dpl, r5
      003105 8E 83            [24] 9618 	mov	dph, r6
      003107 8F F0            [24] 9619 	mov	b, r7
      003109 12 21 3F         [24] 9620 	lcall	_fuzzy_rules_defuzzify_cog
      00310C AC 82            [24] 9621 	mov	r4, dpl
      00310E AD 83            [24] 9622 	mov	r5, dph
      003110 AE F0            [24] 9623 	mov	r6, b
      003112 FF               [12] 9624 	mov	r7, a
      003113 E5 81            [12] 9625 	mov	a,sp
      003115 24 F2            [12] 9626 	add	a,#0xf2
      003117 F5 81            [12] 9627 	mov	sp,a
      003119 8C 82            [24] 9628 	mov	dpl, r4
      00311B 8D 83            [24] 9629 	mov	dph, r5
      00311D 8E F0            [24] 9630 	mov	b, r6
      00311F EF               [12] 9631 	mov	a, r7
                           003069  9632 	C$fuzzy.h$3113$1_0$145 ==.
                                   9633 ;	../../fuzzy.h:3113: }
      003120 D0 08            [24] 9634 	pop	_bp
                           00306B  9635 	C$fuzzy.h$3113$1_0$145 ==.
                           00306B  9636 	XG$fuzzy_rules_cog$0$0 ==.
      003122 22               [24] 9637 	ret
                                   9638 ;------------------------------------------------------------
                                   9639 ;Allocation info for local variables in function 'temperature_low'
                                   9640 ;------------------------------------------------------------
                                   9641 ;value         Allocated to registers r4 r5 r6 r7 
                                   9642 ;------------------------------------------------------------
                           00306C  9643 	Fcontroller_8051$temperature_low$0$0 ==.
                           00306C  9644 	C$controller_8051.c$59$1_0$147 ==.
                                   9645 ;	../../controller_8051.c:59: static float temperature_low(
                                   9646 ;	-----------------------------------------
                                   9647 ;	 function temperature_low
                                   9648 ;	-----------------------------------------
      003123                       9649 _temperature_low:
      003123 AC 82            [24] 9650 	mov	r4,dpl
      003125 AD 83            [24] 9651 	mov	r5,dph
      003127 AE F0            [24] 9652 	mov	r6,b
      003129 FF               [12] 9653 	mov	r7,a
                           003073  9654 	C$controller_8051.c$68$1_0$147 ==.
                                   9655 ;	../../controller_8051.c:68: hedges.none
      00312A 90 38 B0         [24] 9656 	mov	dptr,#_hedges
      00312D E4               [12] 9657 	clr	a
      00312E 93               [24] 9658 	movc	a,@a+dptr
      00312F FB               [12] 9659 	mov	r3,a
                           003079  9660 	C$controller_8051.c$64$1_0$147 ==.
                                   9661 ;	../../controller_8051.c:64: 20.0f,
      003130 C0 03            [24] 9662 	push	ar3
      003132 E4               [12] 9663 	clr	a
      003133 C0 E0            [24] 9664 	push	acc
      003135 C0 04            [24] 9665 	push	ar4
      003137 C0 05            [24] 9666 	push	ar5
      003139 C0 06            [24] 9667 	push	ar6
      00313B C0 07            [24] 9668 	push	ar7
      00313D C0 E0            [24] 9669 	push	acc
      00313F C0 E0            [24] 9670 	push	acc
      003141 74 20            [12] 9671 	mov	a,#0x20
      003143 C0 E0            [24] 9672 	push	acc
      003145 74 42            [12] 9673 	mov	a,#0x42
      003147 C0 E0            [24] 9674 	push	acc
      003149 90 00 00         [24] 9675 	mov	dptr,#0x0000
      00314C 75 F0 A0         [24] 9676 	mov	b, #0xa0
      00314F 14               [12] 9677 	dec	a
      003150 12 0A EC         [24] 9678 	lcall	_fuzzy_ramp
      003153 AC 82            [24] 9679 	mov	r4, dpl
      003155 AD 83            [24] 9680 	mov	r5, dph
      003157 AE F0            [24] 9681 	mov	r6, b
      003159 FF               [12] 9682 	mov	r7, a
      00315A E5 81            [12] 9683 	mov	a,sp
      00315C 24 F6            [12] 9684 	add	a,#0xf6
      00315E F5 81            [12] 9685 	mov	sp,a
      003160 8C 82            [24] 9686 	mov	dpl, r4
      003162 8D 83            [24] 9687 	mov	dph, r5
      003164 8E F0            [24] 9688 	mov	b, r6
      003166 EF               [12] 9689 	mov	a, r7
                           0030B0  9690 	C$controller_8051.c$70$1_0$147 ==.
                                   9691 ;	../../controller_8051.c:70: }
                           0030B0  9692 	C$controller_8051.c$70$1_0$147 ==.
                           0030B0  9693 	XFcontroller_8051$temperature_low$0$0 ==.
      003167 22               [24] 9694 	ret
                                   9695 ;------------------------------------------------------------
                                   9696 ;Allocation info for local variables in function 'temperature_high'
                                   9697 ;------------------------------------------------------------
                                   9698 ;value         Allocated to registers r4 r5 r6 r7 
                                   9699 ;------------------------------------------------------------
                           0030B1  9700 	Fcontroller_8051$temperature_high$0$0 ==.
                           0030B1  9701 	C$controller_8051.c$73$1_0$149 ==.
                                   9702 ;	../../controller_8051.c:73: static float temperature_high(
                                   9703 ;	-----------------------------------------
                                   9704 ;	 function temperature_high
                                   9705 ;	-----------------------------------------
      003168                       9706 _temperature_high:
      003168 AC 82            [24] 9707 	mov	r4,dpl
      00316A AD 83            [24] 9708 	mov	r5,dph
      00316C AE F0            [24] 9709 	mov	r6,b
      00316E FF               [12] 9710 	mov	r7,a
                           0030B8  9711 	C$controller_8051.c$82$1_0$149 ==.
                                   9712 ;	../../controller_8051.c:82: hedges.none
      00316F 90 38 B0         [24] 9713 	mov	dptr,#_hedges
      003172 E4               [12] 9714 	clr	a
      003173 93               [24] 9715 	movc	a,@a+dptr
      003174 FB               [12] 9716 	mov	r3,a
                           0030BE  9717 	C$controller_8051.c$78$1_0$149 ==.
                                   9718 ;	../../controller_8051.c:78: 30.0f,
      003175 C0 03            [24] 9719 	push	ar3
      003177 74 01            [12] 9720 	mov	a,#0x01
      003179 C0 E0            [24] 9721 	push	acc
      00317B C0 04            [24] 9722 	push	ar4
      00317D C0 05            [24] 9723 	push	ar5
      00317F C0 06            [24] 9724 	push	ar6
      003181 C0 07            [24] 9725 	push	ar7
      003183 E4               [12] 9726 	clr	a
      003184 C0 E0            [24] 9727 	push	acc
      003186 C0 E0            [24] 9728 	push	acc
      003188 74 70            [12] 9729 	mov	a,#0x70
      00318A C0 E0            [24] 9730 	push	acc
      00318C 74 42            [12] 9731 	mov	a,#0x42
      00318E C0 E0            [24] 9732 	push	acc
      003190 90 00 00         [24] 9733 	mov	dptr,#0x0000
      003193 75 F0 F0         [24] 9734 	mov	b, #0xf0
      003196 14               [12] 9735 	dec	a
      003197 12 0A EC         [24] 9736 	lcall	_fuzzy_ramp
      00319A AC 82            [24] 9737 	mov	r4, dpl
      00319C AD 83            [24] 9738 	mov	r5, dph
      00319E AE F0            [24] 9739 	mov	r6, b
      0031A0 FF               [12] 9740 	mov	r7, a
      0031A1 E5 81            [12] 9741 	mov	a,sp
      0031A3 24 F6            [12] 9742 	add	a,#0xf6
      0031A5 F5 81            [12] 9743 	mov	sp,a
      0031A7 8C 82            [24] 9744 	mov	dpl, r4
      0031A9 8D 83            [24] 9745 	mov	dph, r5
      0031AB 8E F0            [24] 9746 	mov	b, r6
      0031AD EF               [12] 9747 	mov	a, r7
                           0030F7  9748 	C$controller_8051.c$84$1_0$149 ==.
                                   9749 ;	../../controller_8051.c:84: }
                           0030F7  9750 	C$controller_8051.c$84$1_0$149 ==.
                           0030F7  9751 	XFcontroller_8051$temperature_high$0$0 ==.
      0031AE 22               [24] 9752 	ret
                                   9753 ;------------------------------------------------------------
                                   9754 ;Allocation info for local variables in function 'fan_slow'
                                   9755 ;------------------------------------------------------------
                                   9756 ;value         Allocated to registers r4 r5 r6 r7 
                                   9757 ;------------------------------------------------------------
                           0030F8  9758 	Fcontroller_8051$fan_slow$0$0 ==.
                           0030F8  9759 	C$controller_8051.c$91$1_0$151 ==.
                                   9760 ;	../../controller_8051.c:91: static float fan_slow(
                                   9761 ;	-----------------------------------------
                                   9762 ;	 function fan_slow
                                   9763 ;	-----------------------------------------
      0031AF                       9764 _fan_slow:
      0031AF AC 82            [24] 9765 	mov	r4,dpl
      0031B1 AD 83            [24] 9766 	mov	r5,dph
      0031B3 AE F0            [24] 9767 	mov	r6,b
      0031B5 FF               [12] 9768 	mov	r7,a
                           0030FF  9769 	C$controller_8051.c$100$1_0$151 ==.
                                   9770 ;	../../controller_8051.c:100: hedges.none
      0031B6 90 38 B0         [24] 9771 	mov	dptr,#_hedges
      0031B9 E4               [12] 9772 	clr	a
      0031BA 93               [24] 9773 	movc	a,@a+dptr
      0031BB FB               [12] 9774 	mov	r3,a
                           003105  9775 	C$controller_8051.c$96$1_0$151 ==.
                                   9776 ;	../../controller_8051.c:96: 20.0f,
      0031BC C0 03            [24] 9777 	push	ar3
      0031BE E4               [12] 9778 	clr	a
      0031BF C0 E0            [24] 9779 	push	acc
      0031C1 C0 04            [24] 9780 	push	ar4
      0031C3 C0 05            [24] 9781 	push	ar5
      0031C5 C0 06            [24] 9782 	push	ar6
      0031C7 C0 07            [24] 9783 	push	ar7
      0031C9 C0 E0            [24] 9784 	push	acc
      0031CB C0 E0            [24] 9785 	push	acc
      0031CD 74 48            [12] 9786 	mov	a,#0x48
      0031CF C0 E0            [24] 9787 	push	acc
      0031D1 74 42            [12] 9788 	mov	a,#0x42
      0031D3 C0 E0            [24] 9789 	push	acc
      0031D5 90 00 00         [24] 9790 	mov	dptr,#0x0000
      0031D8 75 F0 A0         [24] 9791 	mov	b, #0xa0
      0031DB 14               [12] 9792 	dec	a
      0031DC 12 0A EC         [24] 9793 	lcall	_fuzzy_ramp
      0031DF AC 82            [24] 9794 	mov	r4, dpl
      0031E1 AD 83            [24] 9795 	mov	r5, dph
      0031E3 AE F0            [24] 9796 	mov	r6, b
      0031E5 FF               [12] 9797 	mov	r7, a
      0031E6 E5 81            [12] 9798 	mov	a,sp
      0031E8 24 F6            [12] 9799 	add	a,#0xf6
      0031EA F5 81            [12] 9800 	mov	sp,a
      0031EC 8C 82            [24] 9801 	mov	dpl, r4
      0031EE 8D 83            [24] 9802 	mov	dph, r5
      0031F0 8E F0            [24] 9803 	mov	b, r6
      0031F2 EF               [12] 9804 	mov	a, r7
                           00313C  9805 	C$controller_8051.c$102$1_0$151 ==.
                                   9806 ;	../../controller_8051.c:102: }
                           00313C  9807 	C$controller_8051.c$102$1_0$151 ==.
                           00313C  9808 	XFcontroller_8051$fan_slow$0$0 ==.
      0031F3 22               [24] 9809 	ret
                                   9810 ;------------------------------------------------------------
                                   9811 ;Allocation info for local variables in function 'fan_fast'
                                   9812 ;------------------------------------------------------------
                                   9813 ;value         Allocated to registers r4 r5 r6 r7 
                                   9814 ;------------------------------------------------------------
                           00313D  9815 	Fcontroller_8051$fan_fast$0$0 ==.
                           00313D  9816 	C$controller_8051.c$105$1_0$153 ==.
                                   9817 ;	../../controller_8051.c:105: static float fan_fast(
                                   9818 ;	-----------------------------------------
                                   9819 ;	 function fan_fast
                                   9820 ;	-----------------------------------------
      0031F4                       9821 _fan_fast:
      0031F4 AC 82            [24] 9822 	mov	r4,dpl
      0031F6 AD 83            [24] 9823 	mov	r5,dph
      0031F8 AE F0            [24] 9824 	mov	r6,b
      0031FA FF               [12] 9825 	mov	r7,a
                           003144  9826 	C$controller_8051.c$114$1_0$153 ==.
                                   9827 ;	../../controller_8051.c:114: hedges.none
      0031FB 90 38 B0         [24] 9828 	mov	dptr,#_hedges
      0031FE E4               [12] 9829 	clr	a
      0031FF 93               [24] 9830 	movc	a,@a+dptr
      003200 FB               [12] 9831 	mov	r3,a
                           00314A  9832 	C$controller_8051.c$110$1_0$153 ==.
                                   9833 ;	../../controller_8051.c:110: 40.0f,
      003201 C0 03            [24] 9834 	push	ar3
      003203 74 01            [12] 9835 	mov	a,#0x01
      003205 C0 E0            [24] 9836 	push	acc
      003207 C0 04            [24] 9837 	push	ar4
      003209 C0 05            [24] 9838 	push	ar5
      00320B C0 06            [24] 9839 	push	ar6
      00320D C0 07            [24] 9840 	push	ar7
      00320F E4               [12] 9841 	clr	a
      003210 C0 E0            [24] 9842 	push	acc
      003212 C0 E0            [24] 9843 	push	acc
      003214 74 A0            [12] 9844 	mov	a,#0xa0
      003216 C0 E0            [24] 9845 	push	acc
      003218 74 42            [12] 9846 	mov	a,#0x42
      00321A C0 E0            [24] 9847 	push	acc
      00321C 90 00 00         [24] 9848 	mov	dptr,#0x0000
      00321F 75 F0 20         [24] 9849 	mov	b, #0x20
      003222 12 0A EC         [24] 9850 	lcall	_fuzzy_ramp
      003225 AC 82            [24] 9851 	mov	r4, dpl
      003227 AD 83            [24] 9852 	mov	r5, dph
      003229 AE F0            [24] 9853 	mov	r6, b
      00322B FF               [12] 9854 	mov	r7, a
      00322C E5 81            [12] 9855 	mov	a,sp
      00322E 24 F6            [12] 9856 	add	a,#0xf6
      003230 F5 81            [12] 9857 	mov	sp,a
      003232 8C 82            [24] 9858 	mov	dpl, r4
      003234 8D 83            [24] 9859 	mov	dph, r5
      003236 8E F0            [24] 9860 	mov	b, r6
      003238 EF               [12] 9861 	mov	a, r7
                           003182  9862 	C$controller_8051.c$116$1_0$153 ==.
                                   9863 ;	../../controller_8051.c:116: }
                           003182  9864 	C$controller_8051.c$116$1_0$153 ==.
                           003182  9865 	XFcontroller_8051$fan_fast$0$0 ==.
      003239 22               [24] 9866 	ret
                                   9867 ;------------------------------------------------------------
                                   9868 ;Allocation info for local variables in function 'calculate_fan_speed'
                                   9869 ;------------------------------------------------------------
                                   9870 ;temperature   Allocated to stack - _bp +1 +4 
                                   9871 ;rules         Allocated to stack - _bp +9 +146 
                                   9872 ;result        Allocated to registers r4 r5 r6 r7 
                                   9873 ;sloc0         Allocated to stack - _bp +5 +4 
                                   9874 ;------------------------------------------------------------
                           003183  9875 	Fcontroller_8051$calculate_fan_speed$0$0 ==.
                           003183  9876 	C$controller_8051.c$123$1_0$155 ==.
                                   9877 ;	../../controller_8051.c:123: static float calculate_fan_speed(float temperature)
                                   9878 ;	-----------------------------------------
                                   9879 ;	 function calculate_fan_speed
                                   9880 ;	-----------------------------------------
      00323A                       9881 _calculate_fan_speed:
      00323A C0 08            [24] 9882 	push	_bp
      00323C 85 81 08         [24] 9883 	mov	_bp,sp
      00323F C0 82            [24] 9884 	push	dpl
      003241 C0 83            [24] 9885 	push	dph
      003243 C0 F0            [24] 9886 	push	b
      003245 C0 E0            [24] 9887 	push	acc
      003247 E5 81            [12] 9888 	mov	a,sp
      003249 24 96            [12] 9889 	add	a,#0x96
      00324B F5 81            [12] 9890 	mov	sp,a
                           003196  9891 	C$controller_8051.c$129$1_0$155 ==.
                                   9892 ;	../../controller_8051.c:129: rules.count = 0;
      00324D E5 08            [12] 9893 	mov	a,_bp
      00324F 24 09            [12] 9894 	add	a,#0x09
      003251 FB               [12] 9895 	mov	r3,a
      003252 24 90            [12] 9896 	add	a,#0x90
      003254 F9               [12] 9897 	mov	r1,a
      003255 77 00            [12] 9898 	mov	@r1,#0x00
      003257 09               [12] 9899 	inc	r1
      003258 77 00            [12] 9900 	mov	@r1,#0x00
      00325A 19               [12] 9901 	dec	r1
                           0031A4  9902 	C$controller_8051.c$132$1_0$155 ==.
                                   9903 ;	../../controller_8051.c:132: if (!FUZZY_RULE_ADD(&rules, temperature_low(temperature), fan_slow)) return 0.0f;
      00325B A8 08            [24] 9904 	mov	r0,_bp
      00325D 08               [12] 9905 	inc	r0
      00325E 86 82            [24] 9906 	mov	dpl, @r0
      003260 08               [12] 9907 	inc	r0
      003261 86 83            [24] 9908 	mov	dph, @r0
      003263 08               [12] 9909 	inc	r0
      003264 86 F0            [24] 9910 	mov	b, @r0
      003266 08               [12] 9911 	inc	r0
      003267 E6               [12] 9912 	mov	a, @r0
      003268 C0 03            [24] 9913 	push	ar3
      00326A C0 01            [24] 9914 	push	ar1
      00326C 12 31 23         [24] 9915 	lcall	_temperature_low
      00326F C8               [12] 9916 	xch	a,r0
      003270 E5 08            [12] 9917 	mov	a,_bp
      003272 24 05            [12] 9918 	add	a,#0x05
      003274 C8               [12] 9919 	xch	a,r0
      003275 A6 82            [24] 9920 	mov	@r0, dpl
      003277 08               [12] 9921 	inc	r0
      003278 A6 83            [24] 9922 	mov	@r0, dph
      00327A 08               [12] 9923 	inc	r0
      00327B A6 F0            [24] 9924 	mov	@r0, b
      00327D 08               [12] 9925 	inc	r0
      00327E F6               [12] 9926 	mov	@r0,a
      00327F D0 01            [24] 9927 	pop	ar1
      003281 D0 03            [24] 9928 	pop	ar3
      003283 8B 04            [24] 9929 	mov	ar4,r3
      003285 7E 00            [12] 9930 	mov	r6,#0x00
      003287 7F 40            [12] 9931 	mov	r7,#0x40
      003289 C0 03            [24] 9932 	push	ar3
      00328B C0 01            [24] 9933 	push	ar1
      00328D 74 AF            [12] 9934 	mov	a,#_fan_slow
      00328F C0 E0            [24] 9935 	push	acc
      003291 74 31            [12] 9936 	mov	a,#(_fan_slow >> 8)
      003293 C0 E0            [24] 9937 	push	acc
      003295 E5 08            [12] 9938 	mov	a,_bp
      003297 24 05            [12] 9939 	add	a,#0x05
      003299 F8               [12] 9940 	mov	r0,a
      00329A E6               [12] 9941 	mov	a,@r0
      00329B C0 E0            [24] 9942 	push	acc
      00329D 08               [12] 9943 	inc	r0
      00329E E6               [12] 9944 	mov	a,@r0
      00329F C0 E0            [24] 9945 	push	acc
      0032A1 08               [12] 9946 	inc	r0
      0032A2 E6               [12] 9947 	mov	a,@r0
      0032A3 C0 E0            [24] 9948 	push	acc
      0032A5 08               [12] 9949 	inc	r0
      0032A6 E6               [12] 9950 	mov	a,@r0
      0032A7 C0 E0            [24] 9951 	push	acc
      0032A9 74 B3            [12] 9952 	mov	a,#___str_0
      0032AB C0 E0            [24] 9953 	push	acc
      0032AD 74 38            [12] 9954 	mov	a,#(___str_0 >> 8)
      0032AF C0 E0            [24] 9955 	push	acc
      0032B1 74 80            [12] 9956 	mov	a,#0x80
      0032B3 C0 E0            [24] 9957 	push	acc
      0032B5 8C 82            [24] 9958 	mov	dpl, r4
      0032B7 8E 83            [24] 9959 	mov	dph, r6
      0032B9 8F F0            [24] 9960 	mov	b, r7
      0032BB 12 17 6D         [24] 9961 	lcall	_fuzzy_rules_add
      0032BE AF 82            [24] 9962 	mov	r7, dpl
      0032C0 E5 81            [12] 9963 	mov	a,sp
      0032C2 24 F7            [12] 9964 	add	a,#0xf7
      0032C4 F5 81            [12] 9965 	mov	sp,a
      0032C6 D0 01            [24] 9966 	pop	ar1
      0032C8 D0 03            [24] 9967 	pop	ar3
      0032CA EF               [12] 9968 	mov	a,r7
      0032CB 70 09            [24] 9969 	jnz	00102$
      0032CD 90 00 00         [24] 9970 	mov	dptr,#0x0000
      0032D0 E4               [12] 9971 	clr	a
      0032D1 F5 F0            [12] 9972 	mov	b,a
      0032D3 02 33 A5         [24] 9973 	ljmp	00105$
      0032D6                       9974 00102$:
                           00321F  9975 	C$controller_8051.c$134$1_0$155 ==.
                                   9976 ;	../../controller_8051.c:134: if (!FUZZY_RULE_ADD(&rules, temperature_high(temperature), fan_fast)) return 0.0f;
      0032D6 C0 01            [24] 9977 	push	ar1
      0032D8 A8 08            [24] 9978 	mov	r0,_bp
      0032DA 08               [12] 9979 	inc	r0
      0032DB 86 82            [24] 9980 	mov	dpl, @r0
      0032DD 08               [12] 9981 	inc	r0
      0032DE 86 83            [24] 9982 	mov	dph, @r0
      0032E0 08               [12] 9983 	inc	r0
      0032E1 86 F0            [24] 9984 	mov	b, @r0
      0032E3 08               [12] 9985 	inc	r0
      0032E4 E6               [12] 9986 	mov	a, @r0
      0032E5 C0 03            [24] 9987 	push	ar3
      0032E7 C0 01            [24] 9988 	push	ar1
      0032E9 12 31 68         [24] 9989 	lcall	_temperature_high
      0032EC C8               [12] 9990 	xch	a,r0
      0032ED E5 08            [12] 9991 	mov	a,_bp
      0032EF 24 05            [12] 9992 	add	a,#0x05
      0032F1 C8               [12] 9993 	xch	a,r0
      0032F2 A6 82            [24] 9994 	mov	@r0, dpl
      0032F4 08               [12] 9995 	inc	r0
      0032F5 A6 83            [24] 9996 	mov	@r0, dph
      0032F7 08               [12] 9997 	inc	r0
      0032F8 A6 F0            [24] 9998 	mov	@r0, b
      0032FA 08               [12] 9999 	inc	r0
      0032FB F6               [12]10000 	mov	@r0,a
      0032FC D0 01            [24]10001 	pop	ar1
      0032FE D0 03            [24]10002 	pop	ar3
      003300 8B 02            [24]10003 	mov	ar2,r3
      003302 7E 00            [12]10004 	mov	r6,#0x00
      003304 7F 40            [12]10005 	mov	r7,#0x40
      003306 C0 03            [24]10006 	push	ar3
      003308 C0 01            [24]10007 	push	ar1
      00330A 74 F4            [12]10008 	mov	a,#_fan_fast
      00330C C0 E0            [24]10009 	push	acc
      00330E 74 31            [12]10010 	mov	a,#(_fan_fast >> 8)
      003310 C0 E0            [24]10011 	push	acc
      003312 E5 08            [12]10012 	mov	a,_bp
      003314 24 05            [12]10013 	add	a,#0x05
      003316 F8               [12]10014 	mov	r0,a
      003317 E6               [12]10015 	mov	a,@r0
      003318 C0 E0            [24]10016 	push	acc
      00331A 08               [12]10017 	inc	r0
      00331B E6               [12]10018 	mov	a,@r0
      00331C C0 E0            [24]10019 	push	acc
      00331E 08               [12]10020 	inc	r0
      00331F E6               [12]10021 	mov	a,@r0
      003320 C0 E0            [24]10022 	push	acc
      003322 08               [12]10023 	inc	r0
      003323 E6               [12]10024 	mov	a,@r0
      003324 C0 E0            [24]10025 	push	acc
      003326 74 BC            [12]10026 	mov	a,#___str_1
      003328 C0 E0            [24]10027 	push	acc
      00332A 74 38            [12]10028 	mov	a,#(___str_1 >> 8)
      00332C C0 E0            [24]10029 	push	acc
      00332E 74 80            [12]10030 	mov	a,#0x80
      003330 C0 E0            [24]10031 	push	acc
      003332 8A 82            [24]10032 	mov	dpl, r2
      003334 8E 83            [24]10033 	mov	dph, r6
      003336 8F F0            [24]10034 	mov	b, r7
      003338 12 17 6D         [24]10035 	lcall	_fuzzy_rules_add
      00333B AF 82            [24]10036 	mov	r7, dpl
      00333D E5 81            [12]10037 	mov	a,sp
      00333F 24 F7            [12]10038 	add	a,#0xf7
      003341 F5 81            [12]10039 	mov	sp,a
      003343 D0 01            [24]10040 	pop	ar1
      003345 D0 03            [24]10041 	pop	ar3
      003347 D0 01            [24]10042 	pop	ar1
      003349 EF               [12]10043 	mov	a,r7
      00334A 70 08            [24]10044 	jnz	00104$
      00334C 90 00 00         [24]10045 	mov	dptr,#0x0000
      00334F E4               [12]10046 	clr	a
      003350 F5 F0            [12]10047 	mov	b,a
      003352 80 51            [24]10048 	sjmp	00105$
      003354                      10049 00104$:
                           00329D 10050 	C$controller_8051.c$138$1_0$155 ==.
                                  10051 ;	../../controller_8051.c:138: &rules,
      003354 7F 00            [12]10052 	mov	r7,#0x00
      003356 7E 40            [12]10053 	mov	r6,#0x40
      003358 C0 01            [24]10054 	push	ar1
      00335A 74 03            [12]10055 	mov	a,#0x03
      00335C C0 E0            [24]10056 	push	acc
      00335E E4               [12]10057 	clr	a
      00335F C0 E0            [24]10058 	push	acc
      003361 C0 E0            [24]10059 	push	acc
      003363 74 20            [12]10060 	mov	a,#0x20
      003365 C0 E0            [24]10061 	push	acc
      003367 74 41            [12]10062 	mov	a,#0x41
      003369 C0 E0            [24]10063 	push	acc
      00336B E4               [12]10064 	clr	a
      00336C C0 E0            [24]10065 	push	acc
      00336E C0 E0            [24]10066 	push	acc
      003370 74 C8            [12]10067 	mov	a,#0xc8
      003372 C0 E0            [24]10068 	push	acc
      003374 74 42            [12]10069 	mov	a,#0x42
      003376 C0 E0            [24]10070 	push	acc
      003378 E4               [12]10071 	clr	a
      003379 C0 E0            [24]10072 	push	acc
      00337B C0 E0            [24]10073 	push	acc
      00337D C0 E0            [24]10074 	push	acc
      00337F C0 E0            [24]10075 	push	acc
      003381 8B 82            [24]10076 	mov	dpl, r3
      003383 8F 83            [24]10077 	mov	dph, r7
      003385 8E F0            [24]10078 	mov	b, r6
      003387 12 30 43         [24]10079 	lcall	_fuzzy_rules_defuzzify
      00338A AC 82            [24]10080 	mov	r4, dpl
      00338C AD 83            [24]10081 	mov	r5, dph
      00338E AE F0            [24]10082 	mov	r6, b
      003390 FF               [12]10083 	mov	r7, a
      003391 E5 81            [12]10084 	mov	a,sp
      003393 24 F3            [12]10085 	add	a,#0xf3
      003395 F5 81            [12]10086 	mov	sp,a
      003397 D0 01            [24]10087 	pop	ar1
                           0032E2 10088 	C$controller_8051.c$146$1_0$155 ==.
                                  10089 ;	../../controller_8051.c:146: rules.count = 0;
      003399 77 00            [12]10090 	mov	@r1,#0x00
      00339B 09               [12]10091 	inc	r1
      00339C 77 00            [12]10092 	mov	@r1,#0x00
                           0032E7 10093 	C$controller_8051.c$148$1_0$155 ==.
                                  10094 ;	../../controller_8051.c:148: return result;
      00339E 8C 82            [24]10095 	mov	dpl, r4
      0033A0 8D 83            [24]10096 	mov	dph, r5
      0033A2 8E F0            [24]10097 	mov	b, r6
      0033A4 EF               [12]10098 	mov	a, r7
      0033A5                      10099 00105$:
                           0032EE 10100 	C$controller_8051.c$149$1_0$155 ==.
                                  10101 ;	../../controller_8051.c:149: }
      0033A5 85 08 81         [24]10102 	mov	sp,_bp
      0033A8 D0 08            [24]10103 	pop	_bp
                           0032F3 10104 	C$controller_8051.c$149$1_0$155 ==.
                           0032F3 10105 	XFcontroller_8051$calculate_fan_speed$0$0 ==.
      0033AA 22               [24]10106 	ret
                                  10107 ;------------------------------------------------------------
                                  10108 ;Allocation info for local variables in function 'fan_speed_to_pwm'
                                  10109 ;------------------------------------------------------------
                                  10110 ;fan_speed     Allocated to registers r4 r5 r6 r7 
                                  10111 ;------------------------------------------------------------
                           0032F4 10112 	Fcontroller_8051$fan_speed_to_pwm$0$0 ==.
                           0032F4 10113 	C$controller_8051.c$156$1_0$157 ==.
                                  10114 ;	../../controller_8051.c:156: static unsigned char fan_speed_to_pwm(
                                  10115 ;	-----------------------------------------
                                  10116 ;	 function fan_speed_to_pwm
                                  10117 ;	-----------------------------------------
      0033AB                      10118 _fan_speed_to_pwm:
      0033AB AC 82            [24]10119 	mov	r4,dpl
      0033AD AD 83            [24]10120 	mov	r5,dph
      0033AF AE F0            [24]10121 	mov	r6,b
      0033B1 FF               [12]10122 	mov	r7,a
                           0032FB 10123 	C$controller_8051.c$160$1_0$157 ==.
                                  10124 ;	../../controller_8051.c:160: if (fan_speed <= 0.0f) {
      0033B2 C0 07            [24]10125 	push	ar7
      0033B4 C0 06            [24]10126 	push	ar6
      0033B6 C0 05            [24]10127 	push	ar5
      0033B8 C0 04            [24]10128 	push	ar4
      0033BA C0 04            [24]10129 	push	ar4
      0033BC C0 05            [24]10130 	push	ar5
      0033BE C0 06            [24]10131 	push	ar6
      0033C0 C0 07            [24]10132 	push	ar7
      0033C2 90 00 00         [24]10133 	mov	dptr,#0x0000
      0033C5 E4               [12]10134 	clr	a
      0033C6 F5 F0            [12]10135 	mov	b,a
      0033C8 12 35 C2         [24]10136 	lcall	___fslt
      0033CB E5 81            [12]10137 	mov	a,sp
      0033CD 24 FC            [12]10138 	add	a,#0xfc
      0033CF F5 81            [12]10139 	mov	sp,a
      0033D1 D0 04            [24]10140 	pop	ar4
      0033D3 D0 05            [24]10141 	pop	ar5
      0033D5 D0 06            [24]10142 	pop	ar6
      0033D7 D0 07            [24]10143 	pop	ar7
      0033D9 E5 82            [12]10144 	mov	a, dpl
      0033DB 24 FF            [12]10145 	add	a,#0xff
      0033DD 92 00            [24]10146 	mov	b0,c
      0033DF 40 05            [24]10147 	jc	00102$
                           00332A 10148 	C$controller_8051.c$161$2_0$158 ==.
                                  10149 ;	../../controller_8051.c:161: return 0u;
      0033E1 75 82 00         [24]10150 	mov	dpl, #0x00
      0033E4 80 66            [24]10151 	sjmp	00105$
      0033E6                      10152 00102$:
                           00332F 10153 	C$controller_8051.c$164$1_0$157 ==.
                                  10154 ;	../../controller_8051.c:164: if (fan_speed >= 100.0f) {
      0033E6 C0 07            [24]10155 	push	ar7
      0033E8 C0 06            [24]10156 	push	ar6
      0033EA C0 05            [24]10157 	push	ar5
      0033EC C0 04            [24]10158 	push	ar4
      0033EE E4               [12]10159 	clr	a
      0033EF C0 E0            [24]10160 	push	acc
      0033F1 C0 E0            [24]10161 	push	acc
      0033F3 74 C8            [12]10162 	mov	a,#0xc8
      0033F5 C0 E0            [24]10163 	push	acc
      0033F7 74 42            [12]10164 	mov	a,#0x42
      0033F9 C0 E0            [24]10165 	push	acc
      0033FB 8C 82            [24]10166 	mov	dpl, r4
      0033FD 8D 83            [24]10167 	mov	dph, r5
      0033FF 8E F0            [24]10168 	mov	b, r6
      003401 EF               [12]10169 	mov	a, r7
      003402 12 35 C2         [24]10170 	lcall	___fslt
      003405 E5 81            [12]10171 	mov	a,sp
      003407 24 FC            [12]10172 	add	a,#0xfc
      003409 F5 81            [12]10173 	mov	sp,a
      00340B D0 04            [24]10174 	pop	ar4
      00340D D0 05            [24]10175 	pop	ar5
      00340F D0 06            [24]10176 	pop	ar6
      003411 D0 07            [24]10177 	pop	ar7
      003413 E5 82            [12]10178 	mov	a, dpl
      003415 24 FF            [12]10179 	add	a,#0xff
      003417 92 00            [24]10180 	mov	b0,c
      003419 40 05            [24]10181 	jc	00104$
                           003364 10182 	C$controller_8051.c$165$2_0$159 ==.
                                  10183 ;	../../controller_8051.c:165: return 100u;
      00341B 75 82 64         [24]10184 	mov	dpl, #0x64
      00341E 80 2C            [24]10185 	sjmp	00105$
      003420                      10186 00104$:
                           003369 10187 	C$controller_8051.c$170$1_0$157 ==.
                                  10188 ;	../../controller_8051.c:170: );
      003420 E4               [12]10189 	clr	a
      003421 C0 E0            [24]10190 	push	acc
      003423 C0 E0            [24]10191 	push	acc
      003425 C0 E0            [24]10192 	push	acc
      003427 74 3F            [12]10193 	mov	a,#0x3f
      003429 C0 E0            [24]10194 	push	acc
      00342B 8C 82            [24]10195 	mov	dpl, r4
      00342D 8D 83            [24]10196 	mov	dph, r5
      00342F 8E F0            [24]10197 	mov	b, r6
      003431 EF               [12]10198 	mov	a, r7
      003432 12 36 14         [24]10199 	lcall	___fsadd
      003435 AC 82            [24]10200 	mov	r4, dpl
      003437 AD 83            [24]10201 	mov	r5, dph
      003439 AE F0            [24]10202 	mov	r6, b
      00343B FF               [12]10203 	mov	r7, a
      00343C E5 81            [12]10204 	mov	a,sp
      00343E 24 FC            [12]10205 	add	a,#0xfc
      003440 F5 81            [12]10206 	mov	sp,a
      003442 8C 82            [24]10207 	mov	dpl, r4
      003444 8D 83            [24]10208 	mov	dph, r5
      003446 8E F0            [24]10209 	mov	b, r6
      003448 EF               [12]10210 	mov	a, r7
      003449 12 38 0A         [24]10211 	lcall	___fs2uchar
      00344C                      10212 00105$:
                           003395 10213 	C$controller_8051.c$171$1_0$157 ==.
                                  10214 ;	../../controller_8051.c:171: }
                           003395 10215 	C$controller_8051.c$171$1_0$157 ==.
                           003395 10216 	XFcontroller_8051$fan_speed_to_pwm$0$0 ==.
      00344C 22               [24]10217 	ret
                                  10218 ;------------------------------------------------------------
                                  10219 ;Allocation info for local variables in function 'main'
                                  10220 ;------------------------------------------------------------
                           003396 10221 	G$main$0$0 ==.
                           003396 10222 	C$controller_8051.c$188$1_0$161 ==.
                                  10223 ;	../../controller_8051.c:188: void main(void)
                                  10224 ;	-----------------------------------------
                                  10225 ;	 function main
                                  10226 ;	-----------------------------------------
      00344D                      10227 _main:
                           003396 10228 	C$controller_8051.c$196$1_0$161 ==.
                                  10229 ;	../../controller_8051.c:196: 42u;
      00344D 75 61 2A         [24]10230 	mov	_test_temperature,#0x2a
                           003399 10231 	C$controller_8051.c$202$1_0$161 ==.
                                  10232 ;	../../controller_8051.c:202: 0x55u;
      003450 75 80 55         [24]10233 	mov	_P0,#0x55
                           00339C 10234 	C$controller_8051.c$205$1_0$161 ==.
                                  10235 ;	../../controller_8051.c:205: 0x00u;
      003453 75 90 00         [24]10236 	mov	_P1,#0x00
                           00339F 10237 	C$controller_8051.c$211$1_0$161 ==.
                                  10238 ;	../../controller_8051.c:211: test_temperature = P2;
      003456 85 A0 61         [24]10239 	mov	_test_temperature,_P2
                           0033A2 10240 	C$controller_8051.c$216$2_0$161 ==.
                                  10241 ;	../../controller_8051.c:216: );
      003459 85 61 82         [24]10242 	mov	dpl, _test_temperature
      00345C 12 38 12         [24]10243 	lcall	___uchar2fs
      00345F 12 32 3A         [24]10244 	lcall	_calculate_fan_speed
      003462 85 82 63         [24]10245 	mov	_test_fan_speed,dpl
      003465 85 83 64         [24]10246 	mov	(_test_fan_speed + 1),dph
      003468 85 F0 65         [24]10247 	mov	(_test_fan_speed + 2),b
      00346B F5 66            [12]10248 	mov	(_test_fan_speed + 3),a
                           0033B6 10249 	C$controller_8051.c$220$1_0$161 ==.
                                  10250 ;	../../controller_8051.c:220: test_fan_speed
      00346D 85 63 82         [24]10251 	mov	dpl, _test_fan_speed
      003470 85 64 83         [24]10252 	mov	dph, (_test_fan_speed + 1)
      003473 85 65 F0         [24]10253 	mov	b, (_test_fan_speed + 2)
      003476 E5 66            [12]10254 	mov	a, (_test_fan_speed + 3)
      003478 12 33 AB         [24]10255 	lcall	_fan_speed_to_pwm
      00347B 85 82 62         [24]10256 	mov	_test_pwm,dpl
                           0033C7 10257 	C$controller_8051.c$227$1_0$161 ==.
                                  10258 ;	../../controller_8051.c:227: test_pwm;
      00347E 85 62 90         [24]10259 	mov	_P1,_test_pwm
                           0033CA 10260 	C$controller_8051.c$233$1_0$161 ==.
                                  10261 ;	../../controller_8051.c:233: 0xAAu;
      003481 75 80 AA         [24]10262 	mov	_P0,#0xaa
      003484                      10263 00103$:
      003484 80 FE            [24]10264 	sjmp	00103$
                           0033CF 10265 	C$controller_8051.c$238$2_0$161 ==.
                                  10266 ;	../../controller_8051.c:238: }
                           0033CF 10267 	C$controller_8051.c$238$2_0$161 ==.
                           0033CF 10268 	XG$main$0$0 ==.
      003486 22               [24]10269 	ret
                                  10270 	.area CSEG    (CODE)
                                  10271 	.area CONST   (CODE)
                                  10272 	.area CONST   (CODE)
                           000000 10273 Fcontroller_8051$hedges$0_0$0 == .
      0038B0                      10274 _hedges:
      0038B0 01                   10275 	.db #0x01	; 1
      0038B1 02                   10276 	.db #0x02	; 2
      0038B2 03                   10277 	.db #0x03	; 3
                                  10278 	.area CSEG    (CODE)
                           0033D0 10279 Fcontroller_8051$__str_0$0_0$0 == .
                                  10280 	.area CONST   (CODE)
      0038B3                      10281 ___str_0:
      0038B3 66 61 6E 5F 73 6C 6F 10282 	.ascii "fan_slow"
             77
      0038BB 00                   10283 	.db 0x00
                                  10284 	.area CSEG    (CODE)
                           0033D0 10285 Fcontroller_8051$__str_1$0_0$0 == .
                                  10286 	.area CONST   (CODE)
      0038BC                      10287 ___str_1:
      0038BC 66 61 6E 5F 66 61 73 10288 	.ascii "fan_fast"
             74
      0038C4 00                   10289 	.db 0x00
                                  10290 	.area CSEG    (CODE)
                                  10291 	.area XINIT   (CODE)
                                  10292 	.area CABS    (ABS,CODE)
