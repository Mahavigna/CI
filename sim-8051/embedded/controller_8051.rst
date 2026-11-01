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
                           000000   562 	C$controller_8051.c$25$2_0$163 ==.
                                    563 ;	../../controller_8051.c:25: volatile unsigned char test_temperature = 0u;
      0000A5 75 61 00         [24]  564 	mov	_test_temperature,#0x00
                           000003   565 	C$controller_8051.c$26$2_0$163 ==.
                                    566 ;	../../controller_8051.c:26: volatile unsigned char test_pwm = 0u;
      0000A8 75 62 00         [24]  567 	mov	_test_pwm,#0x00
                           000006   568 	C$controller_8051.c$27$2_0$163 ==.
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
                           000000   595 	C$fuzzy.h$148$0_0$3 ==.
                                    596 ;	../../fuzzy.h:148: static float *fuzzy_values_initialize(void)
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
                           000000   609 	C$fuzzy.h$153$3_0$5 ==.
                                    610 ;	../../fuzzy.h:153: index = 0u;
      0000B7 7E 00            [12]  611 	mov	r6,#0x00
      0000B9 7F 00            [12]  612 	mov	r7,#0x00
      0000BB                        613 00102$:
                           000004   614 	C$fuzzy.h$157$3_0$5 ==.
                                    615 ;	../../fuzzy.h:157: fuzzy_values_buffer[index] = 0.0f;
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
                           00001E   637 	C$fuzzy.h$155$2_0$4 ==.
                                    638 ;	../../fuzzy.h:155: index++
      0000D5 0E               [12]  639 	inc	r6
      0000D6 BE 00 01         [24]  640 	cjne	r6,#0x00,00119$
      0000D9 0F               [12]  641 	inc	r7
      0000DA                        642 00119$:
                           000023   643 	C$fuzzy.h$154$2_0$4 ==.
                                    644 ;	../../fuzzy.h:154: index < FUZZY_MAX_VALUES;
      0000DA C3               [12]  645 	clr	c
      0000DB EE               [12]  646 	mov	a,r6
      0000DC 94 10            [12]  647 	subb	a,#0x10
      0000DE EF               [12]  648 	mov	a,r7
      0000DF 94 00            [12]  649 	subb	a,#0x00
      0000E1 40 D8            [24]  650 	jc	00102$
                           00002C   651 	C$fuzzy.h$160$1_0$3 ==.
                                    652 ;	../../fuzzy.h:160: return fuzzy_values_buffer;
      0000E3 90 00 21         [24]  653 	mov	dptr,#_fuzzy_values_buffer
      0000E6 75 F0 40         [24]  654 	mov	b, #0x40
                           000032   655 	C$fuzzy.h$161$1_0$3 ==.
                                    656 ;	../../fuzzy.h:161: }
                           000032   657 	C$fuzzy.h$161$1_0$3 ==.
                           000032   658 	XFcontroller_8051$fuzzy_values_initialize$0$0 ==.
      0000E9 22               [24]  659 	ret
                                    660 ;------------------------------------------------------------
                                    661 ;Allocation info for local variables in function 'fuzzy_clamp'
                                    662 ;------------------------------------------------------------
                                    663 ;value         Allocated to registers r4 r5 r6 r7 
                                    664 ;------------------------------------------------------------
                           000033   665 	Fcontroller_8051$fuzzy_clamp$0$0 ==.
                           000033   666 	C$fuzzy.h$926$1_0$27 ==.
                                    667 ;	../../fuzzy.h:926: static float fuzzy_clamp(float value)
                                    668 ;	-----------------------------------------
                                    669 ;	 function fuzzy_clamp
                                    670 ;	-----------------------------------------
      0000EA                        671 _fuzzy_clamp:
      0000EA AC 82            [24]  672 	mov	r4,dpl
      0000EC AD 83            [24]  673 	mov	r5,dph
      0000EE AE F0            [24]  674 	mov	r6,b
      0000F0 FF               [12]  675 	mov	r7,a
                           00003A   676 	C$fuzzy.h$928$1_0$27 ==.
                                    677 ;	../../fuzzy.h:928: if (value < LEVEL_LO) {
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
                           000068   702 	C$fuzzy.h$929$2_0$28 ==.
                                    703 ;	../../fuzzy.h:929: return LEVEL_LO;
      00011F 90 00 00         [24]  704 	mov	dptr,#0x0000
      000122 E4               [12]  705 	clr	a
      000123 F5 F0            [12]  706 	mov	b,a
      000125 80 3F            [24]  707 	sjmp	00105$
      000127                        708 00102$:
                           000070   709 	C$fuzzy.h$932$1_0$27 ==.
                                    710 ;	../../fuzzy.h:932: if (value > LEVEL_HI) {
      000127 C0 07            [24]  711 	push	ar7
      000129 C0 06            [24]  712 	push	ar6
      00012B C0 05            [24]  713 	push	ar5
      00012D C0 04            [24]  714 	push	ar4
      00012F C0 04            [24]  715 	push	ar4
      000131 C0 05            [24]  716 	push	ar5
      000133 C0 06            [24]  717 	push	ar6
      000135 C0 07            [24]  718 	push	ar7
      000137 90 00 00         [24]  719 	mov	dptr,#0x0000
      00013A 75 F0 80         [24]  720 	mov	b, #0x80
      00013D 74 3F            [12]  721 	mov	a, #0x3f
      00013F 12 35 C2         [24]  722 	lcall	___fslt
      000142 AB 82            [24]  723 	mov	r3, dpl
      000144 E5 81            [12]  724 	mov	a,sp
      000146 24 FC            [12]  725 	add	a,#0xfc
      000148 F5 81            [12]  726 	mov	sp,a
      00014A D0 04            [24]  727 	pop	ar4
      00014C D0 05            [24]  728 	pop	ar5
      00014E D0 06            [24]  729 	pop	ar6
      000150 D0 07            [24]  730 	pop	ar7
      000152 EB               [12]  731 	mov	a,r3
      000153 60 0A            [24]  732 	jz	00104$
                           00009E   733 	C$fuzzy.h$933$2_0$29 ==.
                                    734 ;	../../fuzzy.h:933: return LEVEL_HI;
      000155 90 00 00         [24]  735 	mov	dptr,#0x0000
      000158 75 F0 80         [24]  736 	mov	b, #0x80
      00015B 74 3F            [12]  737 	mov	a, #0x3f
      00015D 80 07            [24]  738 	sjmp	00105$
      00015F                        739 00104$:
                           0000A8   740 	C$fuzzy.h$936$1_0$27 ==.
                                    741 ;	../../fuzzy.h:936: return value;
      00015F 8C 82            [24]  742 	mov	dpl, r4
      000161 8D 83            [24]  743 	mov	dph, r5
      000163 8E F0            [24]  744 	mov	b, r6
      000165 EF               [12]  745 	mov	a, r7
      000166                        746 00105$:
                           0000AF   747 	C$fuzzy.h$937$1_0$27 ==.
                                    748 ;	../../fuzzy.h:937: }
                           0000AF   749 	C$fuzzy.h$937$1_0$27 ==.
                           0000AF   750 	XFcontroller_8051$fuzzy_clamp$0$0 ==.
      000166 22               [24]  751 	ret
                                    752 ;------------------------------------------------------------
                                    753 ;Allocation info for local variables in function 'fuzzy_not'
                                    754 ;------------------------------------------------------------
                                    755 ;membership    Allocated to registers r4 r5 r6 r7 
                                    756 ;------------------------------------------------------------
                           0000B0   757 	G$fuzzy_not$0$0 ==.
                           0000B0   758 	C$fuzzy.h$942$1_0$31 ==.
                                    759 ;	../../fuzzy.h:942: float fuzzy_not(
                                    760 ;	-----------------------------------------
                                    761 ;	 function fuzzy_not
                                    762 ;	-----------------------------------------
      000167                        763 _fuzzy_not:
                           0000B0   764 	C$fuzzy.h$947$1_0$31 ==.
                                    765 ;	../../fuzzy.h:947: fuzzy_clamp( membership
      000167 12 00 EA         [24]  766 	lcall	_fuzzy_clamp
      00016A AC 82            [24]  767 	mov	r4, dpl
      00016C AD 83            [24]  768 	mov	r5, dph
      00016E AE F0            [24]  769 	mov	r6, b
      000170 FF               [12]  770 	mov	r7, a
      000171 C0 04            [24]  771 	push	ar4
      000173 C0 05            [24]  772 	push	ar5
      000175 C0 06            [24]  773 	push	ar6
      000177 C0 07            [24]  774 	push	ar7
      000179 90 00 00         [24]  775 	mov	dptr,#0x0000
      00017C 75 F0 80         [24]  776 	mov	b, #0x80
      00017F 74 3F            [12]  777 	mov	a, #0x3f
      000181 12 34 87         [24]  778 	lcall	___fssub
      000184 AC 82            [24]  779 	mov	r4, dpl
      000186 AD 83            [24]  780 	mov	r5, dph
      000188 AE F0            [24]  781 	mov	r6, b
      00018A FF               [12]  782 	mov	r7, a
      00018B E5 81            [12]  783 	mov	a,sp
      00018D 24 FC            [12]  784 	add	a,#0xfc
      00018F F5 81            [12]  785 	mov	sp,a
      000191 8C 82            [24]  786 	mov	dpl, r4
      000193 8D 83            [24]  787 	mov	dph, r5
      000195 8E F0            [24]  788 	mov	b, r6
      000197 EF               [12]  789 	mov	a, r7
                           0000E1   790 	C$fuzzy.h$949$1_0$31 ==.
                                    791 ;	../../fuzzy.h:949: }
                           0000E1   792 	C$fuzzy.h$949$1_0$31 ==.
                           0000E1   793 	XG$fuzzy_not$0$0 ==.
      000198 22               [24]  794 	ret
                                    795 ;------------------------------------------------------------
                                    796 ;Allocation info for local variables in function 'fuzzy_apply_hedge'
                                    797 ;------------------------------------------------------------
                                    798 ;hedge         Allocated to stack - _bp -3 +1 
                                    799 ;membership    Allocated to stack - _bp +1 +4 
                                    800 ;result        Allocated to registers r2 r3 r6 r7 
                                    801 ;------------------------------------------------------------
                           0000E2   802 	Fcontroller_8051$fuzzy_apply_hedge$0$0 ==.
                           0000E2   803 	C$fuzzy.h$959$1_0$33 ==.
                                    804 ;	../../fuzzy.h:959: static float fuzzy_apply_hedge(
                                    805 ;	-----------------------------------------
                                    806 ;	 function fuzzy_apply_hedge
                                    807 ;	-----------------------------------------
      000199                        808 _fuzzy_apply_hedge:
      000199 C0 08            [24]  809 	push	_bp
      00019B 85 81 08         [24]  810 	mov	_bp,sp
      00019E AC 82            [24]  811 	mov	r4,dpl
      0001A0 AD 83            [24]  812 	mov	r5,dph
      0001A2 AE F0            [24]  813 	mov	r6,b
      0001A4 FF               [12]  814 	mov	r7,a
      0001A5 E5 81            [12]  815 	mov	a,sp
      0001A7 24 04            [12]  816 	add	a,#0x04
      0001A9 F5 81            [12]  817 	mov	sp,a
                           0000F4   818 	C$fuzzy.h$965$1_0$33 ==.
                                    819 ;	../../fuzzy.h:965: fuzzy_clamp( membership
      0001AB 8C 82            [24]  820 	mov	dpl, r4
      0001AD 8D 83            [24]  821 	mov	dph, r5
      0001AF 8E F0            [24]  822 	mov	b, r6
      0001B1 EF               [12]  823 	mov	a, r7
      0001B2 12 00 EA         [24]  824 	lcall	_fuzzy_clamp
      0001B5 A8 08            [24]  825 	mov	r0,_bp
      0001B7 08               [12]  826 	inc	r0
      0001B8 A6 82            [24]  827 	mov	@r0, dpl
      0001BA 08               [12]  828 	inc	r0
      0001BB A6 83            [24]  829 	mov	@r0, dph
      0001BD 08               [12]  830 	inc	r0
      0001BE A6 F0            [24]  831 	mov	@r0, b
      0001C0 08               [12]  832 	inc	r0
      0001C1 F6               [12]  833 	mov	@r0,a
                           00010B   834 	C$fuzzy.h$970$2_0$34 ==.
                                    835 ;	../../fuzzy.h:970: float result =
      0001C2 7A 00            [12]  836 	mov	r2,#0x00
      0001C4 7B 00            [12]  837 	mov	r3,#0x00
      0001C6 7E 80            [12]  838 	mov	r6,#0x80
      0001C8 7F 3F            [12]  839 	mov	r7,#0x3f
                           000113   840 	C$fuzzy.h$973$1_1$34 ==.
                                    841 ;	../../fuzzy.h:973: if (hedge == 0u) {
      0001CA E5 08            [12]  842 	mov	a,_bp
      0001CC 24 FD            [12]  843 	add	a,#0xfd
      0001CE F8               [12]  844 	mov	r0,a
      0001CF E6               [12]  845 	mov	a,@r0
      0001D0 70 07            [24]  846 	jnz	00110$
                           00011B   847 	C$fuzzy.h$974$2_1$35 ==.
                                    848 ;	../../fuzzy.h:974: hedge = 1u;
      0001D2 E5 08            [12]  849 	mov	a,_bp
      0001D4 24 FD            [12]  850 	add	a,#0xfd
      0001D6 F8               [12]  851 	mov	r0,a
      0001D7 76 01            [12]  852 	mov	@r0,#0x01
                           000122   853 	C$fuzzy.h$977$1_1$33 ==.
                                    854 ;	../../fuzzy.h:977: while (hedge > 0u) {
      0001D9                        855 00110$:
      0001D9 E5 08            [12]  856 	mov	a,_bp
      0001DB 24 FD            [12]  857 	add	a,#0xfd
      0001DD F8               [12]  858 	mov	r0,a
      0001DE 86 05            [24]  859 	mov	ar5,@r0
      0001E0                        860 00103$:
      0001E0 ED               [12]  861 	mov	a,r5
      0001E1 60 30            [24]  862 	jz	00105$
                           00012C   863 	C$fuzzy.h$978$1_1$33 ==.
                                    864 ;	../../fuzzy.h:978: result *= membership;
      0001E3 C0 05            [24]  865 	push	ar5
      0001E5 A8 08            [24]  866 	mov	r0,_bp
      0001E7 08               [12]  867 	inc	r0
      0001E8 E6               [12]  868 	mov	a,@r0
      0001E9 C0 E0            [24]  869 	push	acc
      0001EB 08               [12]  870 	inc	r0
      0001EC E6               [12]  871 	mov	a,@r0
      0001ED C0 E0            [24]  872 	push	acc
      0001EF 08               [12]  873 	inc	r0
      0001F0 E6               [12]  874 	mov	a,@r0
      0001F1 C0 E0            [24]  875 	push	acc
      0001F3 08               [12]  876 	inc	r0
      0001F4 E6               [12]  877 	mov	a,@r0
      0001F5 C0 E0            [24]  878 	push	acc
                           000140   879 	C$fuzzy.h$980$1_1$33 ==.
                                    880 ;	../../fuzzy.h:980: hedge--;
      0001F7 8A 82            [24]  881 	mov	dpl, r2
      0001F9 8B 83            [24]  882 	mov	dph, r3
      0001FB 8E F0            [24]  883 	mov	b, r6
      0001FD EF               [12]  884 	mov	a, r7
      0001FE 12 34 92         [24]  885 	lcall	___fsmul
      000201 AA 82            [24]  886 	mov	r2, dpl
      000203 AB 83            [24]  887 	mov	r3, dph
      000205 AE F0            [24]  888 	mov	r6, b
      000207 FF               [12]  889 	mov	r7, a
      000208 E5 81            [12]  890 	mov	a,sp
      00020A 24 FC            [12]  891 	add	a,#0xfc
      00020C F5 81            [12]  892 	mov	sp,a
      00020E D0 05            [24]  893 	pop	ar5
      000210 1D               [12]  894 	dec	r5
      000211 80 CD            [24]  895 	sjmp	00103$
      000213                        896 00105$:
                           00015C   897 	C$fuzzy.h$984$1_1$34 ==.
                                    898 ;	../../fuzzy.h:984: result
      000213 8A 82            [24]  899 	mov	dpl, r2
      000215 8B 83            [24]  900 	mov	dph, r3
      000217 8E F0            [24]  901 	mov	b, r6
      000219 EF               [12]  902 	mov	a, r7
      00021A 12 00 EA         [24]  903 	lcall	_fuzzy_clamp
                           000166   904 	C$fuzzy.h$1000$1_1$33 ==.
                                    905 ;	../../fuzzy.h:1000: }
      00021D 85 08 81         [24]  906 	mov	sp,_bp
      000220 D0 08            [24]  907 	pop	_bp
                           00016B   908 	C$fuzzy.h$1000$1_1$33 ==.
                           00016B   909 	XFcontroller_8051$fuzzy_apply_hedge$0$0 ==.
      000222 22               [24]  910 	ret
                                    911 ;------------------------------------------------------------
                                    912 ;Allocation info for local variables in function 'fuzzy_and_array'
                                    913 ;------------------------------------------------------------
                                    914 ;count         Allocated to stack - _bp -4 +2 
                                    915 ;args          Allocated to stack - _bp -7 +3 
                                    916 ;method        Allocated to registers r5 
                                    917 ;result        Allocated to stack - _bp +5 +4 
                                    918 ;next          Allocated to stack - _bp +9 +4 
                                    919 ;index         Allocated to stack - _bp +13 +2 
                                    920 ;sloc0         Allocated to stack - _bp +1 +3 
                                    921 ;sloc1         Allocated to stack - _bp +4 +1 
                                    922 ;------------------------------------------------------------
                           00016C   923 	G$fuzzy_and_array$0$0 ==.
                           00016C   924 	C$fuzzy.h$1014$1_1$38 ==.
                                    925 ;	../../fuzzy.h:1014: float fuzzy_and_array(
                                    926 ;	-----------------------------------------
                                    927 ;	 function fuzzy_and_array
                                    928 ;	-----------------------------------------
      000223                        929 _fuzzy_and_array:
      000223 C0 08            [24]  930 	push	_bp
      000225 E5 81            [12]  931 	mov	a,sp
      000227 F5 08            [12]  932 	mov	_bp,a
      000229 24 0E            [12]  933 	add	a,#0x0e
      00022B F5 81            [12]  934 	mov	sp,a
      00022D AD 82            [24]  935 	mov	r5, dpl
                           000178   936 	C$fuzzy.h$1025$1_0$38 ==.
                                    937 ;	../../fuzzy.h:1025: args == NULL ||
      00022F E5 08            [12]  938 	mov	a,_bp
      000231 24 F9            [12]  939 	add	a,#0xf9
      000233 F8               [12]  940 	mov	r0,a
      000234 E6               [12]  941 	mov	a,@r0
      000235 08               [12]  942 	inc	r0
      000236 46               [12]  943 	orl	a,@r0
      000237 60 0A            [24]  944 	jz	00101$
                           000182   945 	C$fuzzy.h$1026$1_0$38 ==.
                                    946 ;	../../fuzzy.h:1026: count == 0u
      000239 E5 08            [12]  947 	mov	a,_bp
      00023B 24 FC            [12]  948 	add	a,#0xfc
      00023D F8               [12]  949 	mov	r0,a
      00023E E6               [12]  950 	mov	a,@r0
      00023F 08               [12]  951 	inc	r0
      000240 46               [12]  952 	orl	a,@r0
      000241 70 0B            [24]  953 	jnz	00102$
      000243                        954 00101$:
                           00018C   955 	C$fuzzy.h$1028$2_0$39 ==.
                                    956 ;	../../fuzzy.h:1028: return LEVEL_HI;
      000243 90 00 00         [24]  957 	mov	dptr,#0x0000
      000246 75 F0 80         [24]  958 	mov	b, #0x80
      000249 74 3F            [12]  959 	mov	a, #0x3f
      00024B 02 04 BC         [24]  960 	ljmp	00121$
      00024E                        961 00102$:
                           000197   962 	C$fuzzy.h$1032$1_0$38 ==.
                                    963 ;	../../fuzzy.h:1032: method != FUZZY_LOGIC_STANDARD &&
      00024E ED               [12]  964 	mov	a,r5
      00024F 60 13            [24]  965 	jz	00105$
                           00019A   966 	C$fuzzy.h$1033$1_0$38 ==.
                                    967 ;	../../fuzzy.h:1033: method != FUZZY_LOGIC_ALGEBRAIC &&
      000251 BD 01 02         [24]  968 	cjne	r5,#0x01,00192$
      000254 80 0E            [24]  969 	sjmp	00105$
      000256                        970 00192$:
                           00019F   971 	C$fuzzy.h$1035$1_0$38 ==.
                                    972 ;	../../fuzzy.h:1035: ) {
      000256 BD 02 02         [24]  973 	cjne	r5,#0x02,00193$
      000259 80 09            [24]  974 	sjmp	00105$
      00025B                        975 00193$:
                           0001A4   976 	C$fuzzy.h$1036$2_0$40 ==.
                                    977 ;	../../fuzzy.h:1036: return LEVEL_LO;
      00025B 90 00 00         [24]  978 	mov	dptr,#0x0000
      00025E E4               [12]  979 	clr	a
      00025F F5 F0            [12]  980 	mov	b,a
      000261 02 04 BC         [24]  981 	ljmp	00121$
      000264                        982 00105$:
                           0001AD   983 	C$fuzzy.h$1041$1_0$38 ==.
                                    984 ;	../../fuzzy.h:1041: args[0]
      000264 E5 08            [12]  985 	mov	a,_bp
      000266 24 F9            [12]  986 	add	a,#0xf9
      000268 F8               [12]  987 	mov	r0,a
      000269 A9 08            [24]  988 	mov	r1,_bp
      00026B 09               [12]  989 	inc	r1
      00026C E6               [12]  990 	mov	a,@r0
      00026D F7               [12]  991 	mov	@r1,a
      00026E 08               [12]  992 	inc	r0
      00026F E6               [12]  993 	mov	a,@r0
      000270 09               [12]  994 	inc	r1
      000271 F7               [12]  995 	mov	@r1,a
      000272 08               [12]  996 	inc	r0
      000273 E6               [12]  997 	mov	a,@r0
      000274 09               [12]  998 	inc	r1
      000275 F7               [12]  999 	mov	@r1,a
      000276 A8 08            [24] 1000 	mov	r0,_bp
      000278 08               [12] 1001 	inc	r0
      000279 86 82            [24] 1002 	mov	dpl,@r0
      00027B 08               [12] 1003 	inc	r0
      00027C 86 83            [24] 1004 	mov	dph,@r0
      00027E 08               [12] 1005 	inc	r0
      00027F 86 F0            [24] 1006 	mov	b,@r0
      000281 12 37 EE         [24] 1007 	lcall	__gptrget
      000284 FA               [12] 1008 	mov	r2,a
      000285 A3               [24] 1009 	inc	dptr
      000286 12 37 EE         [24] 1010 	lcall	__gptrget
      000289 FB               [12] 1011 	mov	r3,a
      00028A A3               [24] 1012 	inc	dptr
      00028B 12 37 EE         [24] 1013 	lcall	__gptrget
      00028E FE               [12] 1014 	mov	r6,a
      00028F A3               [24] 1015 	inc	dptr
      000290 12 37 EE         [24] 1016 	lcall	__gptrget
      000293 8A 82            [24] 1017 	mov	dpl,r2
      000295 8B 83            [24] 1018 	mov	dph,r3
      000297 8E F0            [24] 1019 	mov	b,r6
      000299 C0 05            [24] 1020 	push	ar5
      00029B 12 00 EA         [24] 1021 	lcall	_fuzzy_clamp
      00029E C8               [12] 1022 	xch	a,r0
      00029F E5 08            [12] 1023 	mov	a,_bp
      0002A1 24 05            [12] 1024 	add	a,#0x05
      0002A3 C8               [12] 1025 	xch	a,r0
      0002A4 A6 82            [24] 1026 	mov	@r0, dpl
      0002A6 08               [12] 1027 	inc	r0
      0002A7 A6 83            [24] 1028 	mov	@r0, dph
      0002A9 08               [12] 1029 	inc	r0
      0002AA A6 F0            [24] 1030 	mov	@r0, b
      0002AC 08               [12] 1031 	inc	r0
      0002AD F6               [12] 1032 	mov	@r0,a
      0002AE D0 05            [24] 1033 	pop	ar5
                           0001F9  1034 	C$fuzzy.h$1045$3_0$42 ==.
                                   1035 ;	../../fuzzy.h:1045: index = 1u;
      0002B0 E4               [12] 1036 	clr	a
      0002B1 BD 00 01         [24] 1037 	cjne	r5,#0x00,00194$
      0002B4 04               [12] 1038 	inc	a
      0002B5                       1039 00194$:
      0002B5 FB               [12] 1040 	mov	r3,a
      0002B6 BD 01 03         [24] 1041 	cjne	r5,#0x01,00196$
      0002B9 ED               [12] 1042 	mov	a,r5
      0002BA 80 01            [24] 1043 	sjmp	00197$
      0002BC                       1044 00196$:
      0002BC E4               [12] 1045 	clr	a
      0002BD                       1046 00197$:
      0002BD FA               [12] 1047 	mov	r2,a
      0002BE E5 08            [12] 1048 	mov	a,_bp
      0002C0 24 04            [12] 1049 	add	a,#0x04
      0002C2 F8               [12] 1050 	mov	r0,a
      0002C3 E4               [12] 1051 	clr	a
      0002C4 BD 02 01         [24] 1052 	cjne	r5,#0x02,00198$
      0002C7 04               [12] 1053 	inc	a
      0002C8                       1054 00198$:
      0002C8 F6               [12] 1055 	mov	@r0,a
      0002C9 E5 08            [12] 1056 	mov	a,_bp
      0002CB 24 0D            [12] 1057 	add	a,#0x0d
      0002CD F8               [12] 1058 	mov	r0,a
      0002CE 76 01            [12] 1059 	mov	@r0,#0x01
      0002D0 08               [12] 1060 	inc	r0
      0002D1 76 00            [12] 1061 	mov	@r0,#0x00
      0002D3                       1062 00119$:
                           00021C  1063 	C$fuzzy.h$1046$2_0$41 ==.
                                   1064 ;	../../fuzzy.h:1046: index < count;
      0002D3 E5 08            [12] 1065 	mov	a,_bp
      0002D5 24 0D            [12] 1066 	add	a,#0x0d
      0002D7 F8               [12] 1067 	mov	r0,a
      0002D8 E5 08            [12] 1068 	mov	a,_bp
      0002DA 24 FC            [12] 1069 	add	a,#0xfc
      0002DC F9               [12] 1070 	mov	r1,a
      0002DD C3               [12] 1071 	clr	c
      0002DE E6               [12] 1072 	mov	a,@r0
      0002DF 97               [12] 1073 	subb	a,@r1
      0002E0 08               [12] 1074 	inc	r0
      0002E1 E6               [12] 1075 	mov	a,@r0
      0002E2 09               [12] 1076 	inc	r1
      0002E3 97               [12] 1077 	subb	a,@r1
      0002E4 40 03            [24] 1078 	jc	00200$
      0002E6 02 04 AA         [24] 1079 	ljmp	00117$
      0002E9                       1080 00200$:
                           000232  1081 	C$fuzzy.h$1051$1_0$38 ==.
                                   1082 ;	../../fuzzy.h:1051: args[index]
      0002E9 C0 02            [24] 1083 	push	ar2
      0002EB E5 08            [12] 1084 	mov	a,_bp
      0002ED 24 0D            [12] 1085 	add	a,#0x0d
      0002EF F8               [12] 1086 	mov	r0,a
      0002F0 E6               [12] 1087 	mov	a,@r0
      0002F1 26               [12] 1088 	add	a,@r0
      0002F2 FD               [12] 1089 	mov	r5,a
      0002F3 08               [12] 1090 	inc	r0
      0002F4 E6               [12] 1091 	mov	a,@r0
      0002F5 33               [12] 1092 	rlc	a
      0002F6 FC               [12] 1093 	mov	r4,a
      0002F7 ED               [12] 1094 	mov	a,r5
      0002F8 2D               [12] 1095 	add	a,r5
      0002F9 FD               [12] 1096 	mov	r5,a
      0002FA EC               [12] 1097 	mov	a,r4
      0002FB 33               [12] 1098 	rlc	a
      0002FC FC               [12] 1099 	mov	r4,a
      0002FD A8 08            [24] 1100 	mov	r0,_bp
      0002FF 08               [12] 1101 	inc	r0
      000300 ED               [12] 1102 	mov	a,r5
      000301 26               [12] 1103 	add	a, @r0
      000302 FA               [12] 1104 	mov	r2,a
      000303 EC               [12] 1105 	mov	a,r4
      000304 08               [12] 1106 	inc	r0
      000305 36               [12] 1107 	addc	a, @r0
      000306 FC               [12] 1108 	mov	r4,a
      000307 08               [12] 1109 	inc	r0
      000308 86 05            [24] 1110 	mov	ar5,@r0
      00030A 8A 82            [24] 1111 	mov	dpl,r2
      00030C 8C 83            [24] 1112 	mov	dph,r4
      00030E 8D F0            [24] 1113 	mov	b,r5
      000310 12 37 EE         [24] 1114 	lcall	__gptrget
      000313 FA               [12] 1115 	mov	r2,a
      000314 A3               [24] 1116 	inc	dptr
      000315 12 37 EE         [24] 1117 	lcall	__gptrget
      000318 FC               [12] 1118 	mov	r4,a
      000319 A3               [24] 1119 	inc	dptr
      00031A 12 37 EE         [24] 1120 	lcall	__gptrget
      00031D FD               [12] 1121 	mov	r5,a
      00031E A3               [24] 1122 	inc	dptr
      00031F 12 37 EE         [24] 1123 	lcall	__gptrget
      000322 8A 82            [24] 1124 	mov	dpl,r2
      000324 8C 83            [24] 1125 	mov	dph,r4
      000326 8D F0            [24] 1126 	mov	b,r5
      000328 C0 03            [24] 1127 	push	ar3
      00032A C0 02            [24] 1128 	push	ar2
      00032C 12 00 EA         [24] 1129 	lcall	_fuzzy_clamp
      00032F C8               [12] 1130 	xch	a,r0
      000330 E5 08            [12] 1131 	mov	a,_bp
      000332 24 09            [12] 1132 	add	a,#0x09
      000334 C8               [12] 1133 	xch	a,r0
      000335 A6 82            [24] 1134 	mov	@r0, dpl
      000337 08               [12] 1135 	inc	r0
      000338 A6 83            [24] 1136 	mov	@r0, dph
      00033A 08               [12] 1137 	inc	r0
      00033B A6 F0            [24] 1138 	mov	@r0, b
      00033D 08               [12] 1139 	inc	r0
      00033E F6               [12] 1140 	mov	@r0,a
      00033F D0 02            [24] 1141 	pop	ar2
      000341 D0 03            [24] 1142 	pop	ar3
                           00028C  1143 	C$fuzzy.h$1054$1_0$38 ==.
                                   1144 ;	../../fuzzy.h:1054: switch (method) {
      000343 D0 02            [24] 1145 	pop	ar2
      000345 EB               [12] 1146 	mov	a,r3
      000346 70 11            [24] 1147 	jnz	00108$
      000348 EA               [12] 1148 	mov	a,r2
      000349 70 65            [24] 1149 	jnz	00111$
      00034B E5 08            [12] 1150 	mov	a,_bp
      00034D 24 04            [12] 1151 	add	a,#0x04
      00034F F8               [12] 1152 	mov	r0,a
      000350 E6               [12] 1153 	mov	a,@r0
      000351 60 03            [24] 1154 	jz	00203$
      000353 02 03 F7         [24] 1155 	ljmp	00112$
      000356                       1156 00203$:
      000356 02 04 94         [24] 1157 	ljmp	00115$
                           0002A2  1158 	C$fuzzy.h$1055$4_0$43 ==.
                                   1159 ;	../../fuzzy.h:1055: case FUZZY_LOGIC_STANDARD:
      000359                       1160 00108$:
                           0002A2  1161 	C$fuzzy.h$1056$1_0$38 ==.
                                   1162 ;	../../fuzzy.h:1056: if (next < result) {
      000359 C0 03            [24] 1163 	push	ar3
      00035B C0 02            [24] 1164 	push	ar2
      00035D E5 08            [12] 1165 	mov	a,_bp
      00035F 24 05            [12] 1166 	add	a,#0x05
      000361 F8               [12] 1167 	mov	r0,a
      000362 E6               [12] 1168 	mov	a,@r0
      000363 C0 E0            [24] 1169 	push	acc
      000365 08               [12] 1170 	inc	r0
      000366 E6               [12] 1171 	mov	a,@r0
      000367 C0 E0            [24] 1172 	push	acc
      000369 08               [12] 1173 	inc	r0
      00036A E6               [12] 1174 	mov	a,@r0
      00036B C0 E0            [24] 1175 	push	acc
      00036D 08               [12] 1176 	inc	r0
      00036E E6               [12] 1177 	mov	a,@r0
      00036F C0 E0            [24] 1178 	push	acc
      000371 E5 08            [12] 1179 	mov	a,_bp
      000373 24 09            [12] 1180 	add	a,#0x09
      000375 F8               [12] 1181 	mov	r0,a
      000376 86 82            [24] 1182 	mov	dpl, @r0
      000378 08               [12] 1183 	inc	r0
      000379 86 83            [24] 1184 	mov	dph, @r0
      00037B 08               [12] 1185 	inc	r0
      00037C 86 F0            [24] 1186 	mov	b, @r0
      00037E 08               [12] 1187 	inc	r0
      00037F E6               [12] 1188 	mov	a, @r0
      000380 12 35 C2         [24] 1189 	lcall	___fslt
      000383 AF 82            [24] 1190 	mov	r7, dpl
      000385 E5 81            [12] 1191 	mov	a,sp
      000387 24 FC            [12] 1192 	add	a,#0xfc
      000389 F5 81            [12] 1193 	mov	sp,a
      00038B D0 02            [24] 1194 	pop	ar2
      00038D D0 03            [24] 1195 	pop	ar3
      00038F EF               [12] 1196 	mov	a,r7
      000390 70 03            [24] 1197 	jnz	00204$
      000392 02 04 9C         [24] 1198 	ljmp	00120$
      000395                       1199 00204$:
                           0002DE  1200 	C$fuzzy.h$1057$5_0$44 ==.
                                   1201 ;	../../fuzzy.h:1057: result = next;
      000395 E5 08            [12] 1202 	mov	a,_bp
      000397 24 09            [12] 1203 	add	a,#0x09
      000399 F8               [12] 1204 	mov	r0,a
      00039A E5 08            [12] 1205 	mov	a,_bp
      00039C 24 05            [12] 1206 	add	a,#0x05
      00039E F9               [12] 1207 	mov	r1,a
      00039F E6               [12] 1208 	mov	a,@r0
      0003A0 F7               [12] 1209 	mov	@r1,a
      0003A1 08               [12] 1210 	inc	r0
      0003A2 E6               [12] 1211 	mov	a,@r0
      0003A3 09               [12] 1212 	inc	r1
      0003A4 F7               [12] 1213 	mov	@r1,a
      0003A5 08               [12] 1214 	inc	r0
      0003A6 E6               [12] 1215 	mov	a,@r0
      0003A7 09               [12] 1216 	inc	r1
      0003A8 F7               [12] 1217 	mov	@r1,a
      0003A9 08               [12] 1218 	inc	r0
      0003AA E6               [12] 1219 	mov	a,@r0
      0003AB 09               [12] 1220 	inc	r1
      0003AC F7               [12] 1221 	mov	@r1,a
                           0002F6  1222 	C$fuzzy.h$1059$4_0$43 ==.
                                   1223 ;	../../fuzzy.h:1059: break;
      0003AD 02 04 9C         [24] 1224 	ljmp	00120$
                           0002F9  1225 	C$fuzzy.h$1061$4_0$43 ==.
                                   1226 ;	../../fuzzy.h:1061: case FUZZY_LOGIC_ALGEBRAIC:
      0003B0                       1227 00111$:
                           0002F9  1228 	C$fuzzy.h$1063$1_0$38 ==.
                                   1229 ;	../../fuzzy.h:1063: next;
      0003B0 C0 03            [24] 1230 	push	ar3
      0003B2 C0 02            [24] 1231 	push	ar2
      0003B4 E5 08            [12] 1232 	mov	a,_bp
      0003B6 24 09            [12] 1233 	add	a,#0x09
      0003B8 F8               [12] 1234 	mov	r0,a
      0003B9 E6               [12] 1235 	mov	a,@r0
      0003BA C0 E0            [24] 1236 	push	acc
      0003BC 08               [12] 1237 	inc	r0
      0003BD E6               [12] 1238 	mov	a,@r0
      0003BE C0 E0            [24] 1239 	push	acc
      0003C0 08               [12] 1240 	inc	r0
      0003C1 E6               [12] 1241 	mov	a,@r0
      0003C2 C0 E0            [24] 1242 	push	acc
      0003C4 08               [12] 1243 	inc	r0
      0003C5 E6               [12] 1244 	mov	a,@r0
      0003C6 C0 E0            [24] 1245 	push	acc
                           000311  1246 	C$fuzzy.h$1064$1_0$38 ==.
                                   1247 ;	../../fuzzy.h:1064: break;
      0003C8 E5 08            [12] 1248 	mov	a,_bp
      0003CA 24 05            [12] 1249 	add	a,#0x05
      0003CC F8               [12] 1250 	mov	r0,a
      0003CD 86 82            [24] 1251 	mov	dpl, @r0
      0003CF 08               [12] 1252 	inc	r0
      0003D0 86 83            [24] 1253 	mov	dph, @r0
      0003D2 08               [12] 1254 	inc	r0
      0003D3 86 F0            [24] 1255 	mov	b, @r0
      0003D5 08               [12] 1256 	inc	r0
      0003D6 E6               [12] 1257 	mov	a, @r0
      0003D7 12 34 92         [24] 1258 	lcall	___fsmul
      0003DA C8               [12] 1259 	xch	a,r0
      0003DB E5 08            [12] 1260 	mov	a,_bp
      0003DD 24 05            [12] 1261 	add	a,#0x05
      0003DF C8               [12] 1262 	xch	a,r0
      0003E0 A6 82            [24] 1263 	mov	@r0, dpl
      0003E2 08               [12] 1264 	inc	r0
      0003E3 A6 83            [24] 1265 	mov	@r0, dph
      0003E5 08               [12] 1266 	inc	r0
      0003E6 A6 F0            [24] 1267 	mov	@r0, b
      0003E8 08               [12] 1268 	inc	r0
      0003E9 F6               [12] 1269 	mov	@r0,a
      0003EA E5 81            [12] 1270 	mov	a,sp
      0003EC 24 FC            [12] 1271 	add	a,#0xfc
      0003EE F5 81            [12] 1272 	mov	sp,a
      0003F0 D0 02            [24] 1273 	pop	ar2
      0003F2 D0 03            [24] 1274 	pop	ar3
      0003F4 02 04 9C         [24] 1275 	ljmp	00120$
                           000340  1276 	C$fuzzy.h$1066$4_0$43 ==.
                                   1277 ;	../../fuzzy.h:1066: case FUZZY_LOGIC_BOUNDED:
      0003F7                       1278 00112$:
                           000340  1279 	C$fuzzy.h$1069$1_0$38 ==.
                                   1280 ;	../../fuzzy.h:1069: next -
      0003F7 C0 03            [24] 1281 	push	ar3
      0003F9 C0 02            [24] 1282 	push	ar2
      0003FB E5 08            [12] 1283 	mov	a,_bp
      0003FD 24 09            [12] 1284 	add	a,#0x09
      0003FF F8               [12] 1285 	mov	r0,a
      000400 E6               [12] 1286 	mov	a,@r0
      000401 C0 E0            [24] 1287 	push	acc
      000403 08               [12] 1288 	inc	r0
      000404 E6               [12] 1289 	mov	a,@r0
      000405 C0 E0            [24] 1290 	push	acc
      000407 08               [12] 1291 	inc	r0
      000408 E6               [12] 1292 	mov	a,@r0
      000409 C0 E0            [24] 1293 	push	acc
      00040B 08               [12] 1294 	inc	r0
      00040C E6               [12] 1295 	mov	a,@r0
      00040D C0 E0            [24] 1296 	push	acc
      00040F E5 08            [12] 1297 	mov	a,_bp
      000411 24 05            [12] 1298 	add	a,#0x05
      000413 F8               [12] 1299 	mov	r0,a
      000414 86 82            [24] 1300 	mov	dpl, @r0
      000416 08               [12] 1301 	inc	r0
      000417 86 83            [24] 1302 	mov	dph, @r0
      000419 08               [12] 1303 	inc	r0
      00041A 86 F0            [24] 1304 	mov	b, @r0
      00041C 08               [12] 1305 	inc	r0
      00041D E6               [12] 1306 	mov	a, @r0
      00041E 12 36 14         [24] 1307 	lcall	___fsadd
      000421 AC 82            [24] 1308 	mov	r4, dpl
      000423 AD 83            [24] 1309 	mov	r5, dph
      000425 AE F0            [24] 1310 	mov	r6, b
      000427 FF               [12] 1311 	mov	r7, a
      000428 E5 81            [12] 1312 	mov	a,sp
      00042A 24 FC            [12] 1313 	add	a,#0xfc
      00042C F5 81            [12] 1314 	mov	sp,a
      00042E E4               [12] 1315 	clr	a
      00042F C0 E0            [24] 1316 	push	acc
      000431 C0 E0            [24] 1317 	push	acc
      000433 74 80            [12] 1318 	mov	a,#0x80
      000435 C0 E0            [24] 1319 	push	acc
      000437 74 3F            [12] 1320 	mov	a,#0x3f
      000439 C0 E0            [24] 1321 	push	acc
                           000384  1322 	C$fuzzy.h$1072$1_0$38 ==.
                                   1323 ;	../../fuzzy.h:1072: if (result < LEVEL_LO) {
      00043B 8C 82            [24] 1324 	mov	dpl, r4
      00043D 8D 83            [24] 1325 	mov	dph, r5
      00043F 8E F0            [24] 1326 	mov	b, r6
      000441 EF               [12] 1327 	mov	a, r7
      000442 12 34 87         [24] 1328 	lcall	___fssub
      000445 C8               [12] 1329 	xch	a,r0
      000446 E5 08            [12] 1330 	mov	a,_bp
      000448 24 05            [12] 1331 	add	a,#0x05
      00044A C8               [12] 1332 	xch	a,r0
      00044B A6 82            [24] 1333 	mov	@r0, dpl
      00044D 08               [12] 1334 	inc	r0
      00044E A6 83            [24] 1335 	mov	@r0, dph
      000450 08               [12] 1336 	inc	r0
      000451 A6 F0            [24] 1337 	mov	@r0, b
      000453 08               [12] 1338 	inc	r0
      000454 F6               [12] 1339 	mov	@r0,a
      000455 E5 81            [12] 1340 	mov	a,sp
      000457 24 FC            [12] 1341 	add	a,#0xfc
      000459 F5 81            [12] 1342 	mov	sp,a
      00045B E4               [12] 1343 	clr	a
      00045C C0 E0            [24] 1344 	push	acc
      00045E C0 E0            [24] 1345 	push	acc
      000460 C0 E0            [24] 1346 	push	acc
      000462 C0 E0            [24] 1347 	push	acc
      000464 E5 08            [12] 1348 	mov	a,_bp
      000466 24 05            [12] 1349 	add	a,#0x05
      000468 F8               [12] 1350 	mov	r0,a
      000469 86 82            [24] 1351 	mov	dpl, @r0
      00046B 08               [12] 1352 	inc	r0
      00046C 86 83            [24] 1353 	mov	dph, @r0
      00046E 08               [12] 1354 	inc	r0
      00046F 86 F0            [24] 1355 	mov	b, @r0
      000471 08               [12] 1356 	inc	r0
      000472 E6               [12] 1357 	mov	a, @r0
      000473 12 35 C2         [24] 1358 	lcall	___fslt
      000476 AF 82            [24] 1359 	mov	r7, dpl
      000478 E5 81            [12] 1360 	mov	a,sp
      00047A 24 FC            [12] 1361 	add	a,#0xfc
      00047C F5 81            [12] 1362 	mov	sp,a
      00047E D0 02            [24] 1363 	pop	ar2
      000480 D0 03            [24] 1364 	pop	ar3
      000482 EF               [12] 1365 	mov	a,r7
      000483 60 17            [24] 1366 	jz	00120$
                           0003CE  1367 	C$fuzzy.h$1073$5_0$45 ==.
                                   1368 ;	../../fuzzy.h:1073: result = LEVEL_LO;
      000485 E5 08            [12] 1369 	mov	a,_bp
      000487 24 05            [12] 1370 	add	a,#0x05
      000489 F8               [12] 1371 	mov	r0,a
      00048A E4               [12] 1372 	clr	a
      00048B F6               [12] 1373 	mov	@r0,a
      00048C 08               [12] 1374 	inc	r0
      00048D F6               [12] 1375 	mov	@r0,a
      00048E 08               [12] 1376 	inc	r0
      00048F F6               [12] 1377 	mov	@r0,a
      000490 08               [12] 1378 	inc	r0
      000491 F6               [12] 1379 	mov	@r0,a
                           0003DB  1380 	C$fuzzy.h$1075$4_0$43 ==.
                                   1381 ;	../../fuzzy.h:1075: break;
                           0003DB  1382 	C$fuzzy.h$1077$4_0$43 ==.
                                   1383 ;	../../fuzzy.h:1077: default:
      000492 80 08            [24] 1384 	sjmp	00120$
      000494                       1385 00115$:
                           0003DD  1386 	C$fuzzy.h$1078$4_0$43 ==.
                                   1387 ;	../../fuzzy.h:1078: return LEVEL_LO;
      000494 90 00 00         [24] 1388 	mov	dptr,#0x0000
      000497 E4               [12] 1389 	clr	a
      000498 F5 F0            [12] 1390 	mov	b,a
                           0003E3  1391 	C$fuzzy.h$1079$3_0$42 ==.
                                   1392 ;	../../fuzzy.h:1079: }
      00049A 80 20            [24] 1393 	sjmp	00121$
      00049C                       1394 00120$:
                           0003E5  1395 	C$fuzzy.h$1047$2_0$41 ==.
                                   1396 ;	../../fuzzy.h:1047: index++
      00049C E5 08            [12] 1397 	mov	a,_bp
      00049E 24 0D            [12] 1398 	add	a,#0x0d
      0004A0 F8               [12] 1399 	mov	r0,a
      0004A1 06               [12] 1400 	inc	@r0
      0004A2 B6 00 02         [24] 1401 	cjne	@r0,#0x00,00206$
      0004A5 08               [12] 1402 	inc	r0
      0004A6 06               [12] 1403 	inc	@r0
      0004A7                       1404 00206$:
      0004A7 02 02 D3         [24] 1405 	ljmp	00119$
      0004AA                       1406 00117$:
                           0003F3  1407 	C$fuzzy.h$1083$1_0$38 ==.
                                   1408 ;	../../fuzzy.h:1083: result
      0004AA E5 08            [12] 1409 	mov	a,_bp
      0004AC 24 05            [12] 1410 	add	a,#0x05
      0004AE F8               [12] 1411 	mov	r0,a
      0004AF 86 82            [24] 1412 	mov	dpl, @r0
      0004B1 08               [12] 1413 	inc	r0
      0004B2 86 83            [24] 1414 	mov	dph, @r0
      0004B4 08               [12] 1415 	inc	r0
      0004B5 86 F0            [24] 1416 	mov	b, @r0
      0004B7 08               [12] 1417 	inc	r0
      0004B8 E6               [12] 1418 	mov	a, @r0
      0004B9 12 00 EA         [24] 1419 	lcall	_fuzzy_clamp
      0004BC                       1420 00121$:
                           000405  1421 	C$fuzzy.h$1085$1_0$38 ==.
                                   1422 ;	../../fuzzy.h:1085: }
      0004BC 85 08 81         [24] 1423 	mov	sp,_bp
      0004BF D0 08            [24] 1424 	pop	_bp
                           00040A  1425 	C$fuzzy.h$1085$1_0$38 ==.
                           00040A  1426 	XG$fuzzy_and_array$0$0 ==.
      0004C1 22               [24] 1427 	ret
                                   1428 ;------------------------------------------------------------
                                   1429 ;Allocation info for local variables in function 'fuzzy_or_array'
                                   1430 ;------------------------------------------------------------
                                   1431 ;count         Allocated to stack - _bp -4 +2 
                                   1432 ;args          Allocated to stack - _bp -7 +3 
                                   1433 ;method        Allocated to registers r5 
                                   1434 ;result        Allocated to stack - _bp +10 +4 
                                   1435 ;next          Allocated to registers r4 r5 r6 r3 
                                   1436 ;index         Allocated to stack - _bp +14 +2 
                                   1437 ;sloc0         Allocated to stack - _bp +1 +3 
                                   1438 ;sloc1         Allocated to stack - _bp +4 +1 
                                   1439 ;sloc2         Allocated to stack - _bp +5 +1 
                                   1440 ;sloc3         Allocated to stack - _bp +6 +4 
                                   1441 ;------------------------------------------------------------
                           00040B  1442 	G$fuzzy_or_array$0$0 ==.
                           00040B  1443 	C$fuzzy.h$1100$1_0$47 ==.
                                   1444 ;	../../fuzzy.h:1100: float fuzzy_or_array(
                                   1445 ;	-----------------------------------------
                                   1446 ;	 function fuzzy_or_array
                                   1447 ;	-----------------------------------------
      0004C2                       1448 _fuzzy_or_array:
      0004C2 C0 08            [24] 1449 	push	_bp
      0004C4 E5 81            [12] 1450 	mov	a,sp
      0004C6 F5 08            [12] 1451 	mov	_bp,a
      0004C8 24 0F            [12] 1452 	add	a,#0x0f
      0004CA F5 81            [12] 1453 	mov	sp,a
      0004CC AD 82            [24] 1454 	mov	r5, dpl
                           000417  1455 	C$fuzzy.h$1111$1_0$47 ==.
                                   1456 ;	../../fuzzy.h:1111: args == NULL ||
      0004CE E5 08            [12] 1457 	mov	a,_bp
      0004D0 24 F9            [12] 1458 	add	a,#0xf9
      0004D2 F8               [12] 1459 	mov	r0,a
      0004D3 E6               [12] 1460 	mov	a,@r0
      0004D4 08               [12] 1461 	inc	r0
      0004D5 46               [12] 1462 	orl	a,@r0
      0004D6 60 0A            [24] 1463 	jz	00101$
                           000421  1464 	C$fuzzy.h$1112$1_0$47 ==.
                                   1465 ;	../../fuzzy.h:1112: count == 0u
      0004D8 E5 08            [12] 1466 	mov	a,_bp
      0004DA 24 FC            [12] 1467 	add	a,#0xfc
      0004DC F8               [12] 1468 	mov	r0,a
      0004DD E6               [12] 1469 	mov	a,@r0
      0004DE 08               [12] 1470 	inc	r0
      0004DF 46               [12] 1471 	orl	a,@r0
      0004E0 70 09            [24] 1472 	jnz	00102$
      0004E2                       1473 00101$:
                           00042B  1474 	C$fuzzy.h$1114$2_0$48 ==.
                                   1475 ;	../../fuzzy.h:1114: return LEVEL_LO;
      0004E2 90 00 00         [24] 1476 	mov	dptr,#0x0000
      0004E5 E4               [12] 1477 	clr	a
      0004E6 F5 F0            [12] 1478 	mov	b,a
      0004E8 02 07 7E         [24] 1479 	ljmp	00121$
      0004EB                       1480 00102$:
                           000434  1481 	C$fuzzy.h$1118$1_0$47 ==.
                                   1482 ;	../../fuzzy.h:1118: method != FUZZY_LOGIC_STANDARD &&
      0004EB ED               [12] 1483 	mov	a,r5
      0004EC 60 13            [24] 1484 	jz	00105$
                           000437  1485 	C$fuzzy.h$1119$1_0$47 ==.
                                   1486 ;	../../fuzzy.h:1119: method != FUZZY_LOGIC_ALGEBRAIC &&
      0004EE BD 01 02         [24] 1487 	cjne	r5,#0x01,00192$
      0004F1 80 0E            [24] 1488 	sjmp	00105$
      0004F3                       1489 00192$:
                           00043C  1490 	C$fuzzy.h$1121$1_0$47 ==.
                                   1491 ;	../../fuzzy.h:1121: ) {
      0004F3 BD 02 02         [24] 1492 	cjne	r5,#0x02,00193$
      0004F6 80 09            [24] 1493 	sjmp	00105$
      0004F8                       1494 00193$:
                           000441  1495 	C$fuzzy.h$1122$2_0$49 ==.
                                   1496 ;	../../fuzzy.h:1122: return LEVEL_LO;
      0004F8 90 00 00         [24] 1497 	mov	dptr,#0x0000
      0004FB E4               [12] 1498 	clr	a
      0004FC F5 F0            [12] 1499 	mov	b,a
      0004FE 02 07 7E         [24] 1500 	ljmp	00121$
      000501                       1501 00105$:
                           00044A  1502 	C$fuzzy.h$1127$1_0$47 ==.
                                   1503 ;	../../fuzzy.h:1127: args[0]
      000501 E5 08            [12] 1504 	mov	a,_bp
      000503 24 F9            [12] 1505 	add	a,#0xf9
      000505 F8               [12] 1506 	mov	r0,a
      000506 A9 08            [24] 1507 	mov	r1,_bp
      000508 09               [12] 1508 	inc	r1
      000509 E6               [12] 1509 	mov	a,@r0
      00050A F7               [12] 1510 	mov	@r1,a
      00050B 08               [12] 1511 	inc	r0
      00050C E6               [12] 1512 	mov	a,@r0
      00050D 09               [12] 1513 	inc	r1
      00050E F7               [12] 1514 	mov	@r1,a
      00050F 08               [12] 1515 	inc	r0
      000510 E6               [12] 1516 	mov	a,@r0
      000511 09               [12] 1517 	inc	r1
      000512 F7               [12] 1518 	mov	@r1,a
      000513 A8 08            [24] 1519 	mov	r0,_bp
      000515 08               [12] 1520 	inc	r0
      000516 86 82            [24] 1521 	mov	dpl,@r0
      000518 08               [12] 1522 	inc	r0
      000519 86 83            [24] 1523 	mov	dph,@r0
      00051B 08               [12] 1524 	inc	r0
      00051C 86 F0            [24] 1525 	mov	b,@r0
      00051E 12 37 EE         [24] 1526 	lcall	__gptrget
      000521 FA               [12] 1527 	mov	r2,a
      000522 A3               [24] 1528 	inc	dptr
      000523 12 37 EE         [24] 1529 	lcall	__gptrget
      000526 FB               [12] 1530 	mov	r3,a
      000527 A3               [24] 1531 	inc	dptr
      000528 12 37 EE         [24] 1532 	lcall	__gptrget
      00052B FE               [12] 1533 	mov	r6,a
      00052C A3               [24] 1534 	inc	dptr
      00052D 12 37 EE         [24] 1535 	lcall	__gptrget
      000530 8A 82            [24] 1536 	mov	dpl,r2
      000532 8B 83            [24] 1537 	mov	dph,r3
      000534 8E F0            [24] 1538 	mov	b,r6
      000536 C0 05            [24] 1539 	push	ar5
      000538 12 00 EA         [24] 1540 	lcall	_fuzzy_clamp
      00053B C8               [12] 1541 	xch	a,r0
      00053C E5 08            [12] 1542 	mov	a,_bp
      00053E 24 0A            [12] 1543 	add	a,#0x0a
      000540 C8               [12] 1544 	xch	a,r0
      000541 A6 82            [24] 1545 	mov	@r0, dpl
      000543 08               [12] 1546 	inc	r0
      000544 A6 83            [24] 1547 	mov	@r0, dph
      000546 08               [12] 1548 	inc	r0
      000547 A6 F0            [24] 1549 	mov	@r0, b
      000549 08               [12] 1550 	inc	r0
      00054A F6               [12] 1551 	mov	@r0,a
      00054B D0 05            [24] 1552 	pop	ar5
                           000496  1553 	C$fuzzy.h$1131$3_0$51 ==.
                                   1554 ;	../../fuzzy.h:1131: index = 1u;
      00054D E5 08            [12] 1555 	mov	a,_bp
      00054F 24 05            [12] 1556 	add	a,#0x05
      000551 F8               [12] 1557 	mov	r0,a
      000552 E4               [12] 1558 	clr	a
      000553 BD 00 01         [24] 1559 	cjne	r5,#0x00,00194$
      000556 04               [12] 1560 	inc	a
      000557                       1561 00194$:
      000557 F6               [12] 1562 	mov	@r0,a
      000558 BD 01 03         [24] 1563 	cjne	r5,#0x01,00196$
      00055B ED               [12] 1564 	mov	a,r5
      00055C 80 01            [24] 1565 	sjmp	00197$
      00055E                       1566 00196$:
      00055E E4               [12] 1567 	clr	a
      00055F                       1568 00197$:
      00055F FA               [12] 1569 	mov	r2,a
      000560 E5 08            [12] 1570 	mov	a,_bp
      000562 24 04            [12] 1571 	add	a,#0x04
      000564 F8               [12] 1572 	mov	r0,a
      000565 E4               [12] 1573 	clr	a
      000566 BD 02 01         [24] 1574 	cjne	r5,#0x02,00198$
      000569 04               [12] 1575 	inc	a
      00056A                       1576 00198$:
      00056A F6               [12] 1577 	mov	@r0,a
      00056B E5 08            [12] 1578 	mov	a,_bp
      00056D 24 0E            [12] 1579 	add	a,#0x0e
      00056F F8               [12] 1580 	mov	r0,a
      000570 76 01            [12] 1581 	mov	@r0,#0x01
      000572 08               [12] 1582 	inc	r0
      000573 76 00            [12] 1583 	mov	@r0,#0x00
      000575                       1584 00119$:
                           0004BE  1585 	C$fuzzy.h$1132$2_0$50 ==.
                                   1586 ;	../../fuzzy.h:1132: index < count;
      000575 E5 08            [12] 1587 	mov	a,_bp
      000577 24 0E            [12] 1588 	add	a,#0x0e
      000579 F8               [12] 1589 	mov	r0,a
      00057A E5 08            [12] 1590 	mov	a,_bp
      00057C 24 FC            [12] 1591 	add	a,#0xfc
      00057E F9               [12] 1592 	mov	r1,a
      00057F C3               [12] 1593 	clr	c
      000580 E6               [12] 1594 	mov	a,@r0
      000581 97               [12] 1595 	subb	a,@r1
      000582 08               [12] 1596 	inc	r0
      000583 E6               [12] 1597 	mov	a,@r0
      000584 09               [12] 1598 	inc	r1
      000585 97               [12] 1599 	subb	a,@r1
      000586 40 03            [24] 1600 	jc	00200$
      000588 02 07 6C         [24] 1601 	ljmp	00117$
      00058B                       1602 00200$:
                           0004D4  1603 	C$fuzzy.h$1137$1_0$47 ==.
                                   1604 ;	../../fuzzy.h:1137: args[index]
      00058B C0 02            [24] 1605 	push	ar2
      00058D E5 08            [12] 1606 	mov	a,_bp
      00058F 24 0E            [12] 1607 	add	a,#0x0e
      000591 F8               [12] 1608 	mov	r0,a
      000592 E6               [12] 1609 	mov	a,@r0
      000593 26               [12] 1610 	add	a,@r0
      000594 FD               [12] 1611 	mov	r5,a
      000595 08               [12] 1612 	inc	r0
      000596 E6               [12] 1613 	mov	a,@r0
      000597 33               [12] 1614 	rlc	a
      000598 FC               [12] 1615 	mov	r4,a
      000599 ED               [12] 1616 	mov	a,r5
      00059A 2D               [12] 1617 	add	a,r5
      00059B FD               [12] 1618 	mov	r5,a
      00059C EC               [12] 1619 	mov	a,r4
      00059D 33               [12] 1620 	rlc	a
      00059E FC               [12] 1621 	mov	r4,a
      00059F A8 08            [24] 1622 	mov	r0,_bp
      0005A1 08               [12] 1623 	inc	r0
      0005A2 ED               [12] 1624 	mov	a,r5
      0005A3 26               [12] 1625 	add	a, @r0
      0005A4 FA               [12] 1626 	mov	r2,a
      0005A5 EC               [12] 1627 	mov	a,r4
      0005A6 08               [12] 1628 	inc	r0
      0005A7 36               [12] 1629 	addc	a, @r0
      0005A8 FC               [12] 1630 	mov	r4,a
      0005A9 08               [12] 1631 	inc	r0
      0005AA 86 05            [24] 1632 	mov	ar5,@r0
      0005AC 8A 82            [24] 1633 	mov	dpl,r2
      0005AE 8C 83            [24] 1634 	mov	dph,r4
      0005B0 8D F0            [24] 1635 	mov	b,r5
      0005B2 12 37 EE         [24] 1636 	lcall	__gptrget
      0005B5 FA               [12] 1637 	mov	r2,a
      0005B6 A3               [24] 1638 	inc	dptr
      0005B7 12 37 EE         [24] 1639 	lcall	__gptrget
      0005BA FC               [12] 1640 	mov	r4,a
      0005BB A3               [24] 1641 	inc	dptr
      0005BC 12 37 EE         [24] 1642 	lcall	__gptrget
      0005BF FD               [12] 1643 	mov	r5,a
      0005C0 A3               [24] 1644 	inc	dptr
      0005C1 12 37 EE         [24] 1645 	lcall	__gptrget
      0005C4 8A 82            [24] 1646 	mov	dpl,r2
      0005C6 8C 83            [24] 1647 	mov	dph,r4
      0005C8 8D F0            [24] 1648 	mov	b,r5
      0005CA C0 02            [24] 1649 	push	ar2
      0005CC 12 00 EA         [24] 1650 	lcall	_fuzzy_clamp
      0005CF AC 82            [24] 1651 	mov	r4, dpl
      0005D1 AD 83            [24] 1652 	mov	r5, dph
      0005D3 AE F0            [24] 1653 	mov	r6, b
      0005D5 FB               [12] 1654 	mov	r3, a
      0005D6 D0 02            [24] 1655 	pop	ar2
                           000521  1656 	C$fuzzy.h$1140$1_0$47 ==.
                                   1657 ;	../../fuzzy.h:1140: switch (method) {
      0005D8 D0 02            [24] 1658 	pop	ar2
      0005DA E5 08            [12] 1659 	mov	a,_bp
      0005DC 24 05            [12] 1660 	add	a,#0x05
      0005DE F8               [12] 1661 	mov	r0,a
      0005DF E6               [12] 1662 	mov	a,@r0
      0005E0 70 11            [24] 1663 	jnz	00108$
      0005E2 EA               [12] 1664 	mov	a,r2
      0005E3 70 5D            [24] 1665 	jnz	00111$
      0005E5 E5 08            [12] 1666 	mov	a,_bp
      0005E7 24 04            [12] 1667 	add	a,#0x04
      0005E9 F8               [12] 1668 	mov	r0,a
      0005EA E6               [12] 1669 	mov	a,@r0
      0005EB 60 03            [24] 1670 	jz	00203$
      0005ED 02 06 E7         [24] 1671 	ljmp	00112$
      0005F0                       1672 00203$:
      0005F0 02 07 56         [24] 1673 	ljmp	00115$
                           00053C  1674 	C$fuzzy.h$1141$4_0$52 ==.
                                   1675 ;	../../fuzzy.h:1141: case FUZZY_LOGIC_STANDARD:
      0005F3                       1676 00108$:
                           00053C  1677 	C$fuzzy.h$1142$1_0$47 ==.
                                   1678 ;	../../fuzzy.h:1142: if (next > result) {
      0005F3 C0 06            [24] 1679 	push	ar6
      0005F5 C0 05            [24] 1680 	push	ar5
      0005F7 C0 04            [24] 1681 	push	ar4
      0005F9 C0 03            [24] 1682 	push	ar3
      0005FB C0 02            [24] 1683 	push	ar2
      0005FD C0 04            [24] 1684 	push	ar4
      0005FF C0 05            [24] 1685 	push	ar5
      000601 C0 06            [24] 1686 	push	ar6
      000603 C0 03            [24] 1687 	push	ar3
      000605 E5 08            [12] 1688 	mov	a,_bp
      000607 24 0A            [12] 1689 	add	a,#0x0a
      000609 F8               [12] 1690 	mov	r0,a
      00060A 86 82            [24] 1691 	mov	dpl, @r0
      00060C 08               [12] 1692 	inc	r0
      00060D 86 83            [24] 1693 	mov	dph, @r0
      00060F 08               [12] 1694 	inc	r0
      000610 86 F0            [24] 1695 	mov	b, @r0
      000612 08               [12] 1696 	inc	r0
      000613 E6               [12] 1697 	mov	a, @r0
      000614 12 35 C2         [24] 1698 	lcall	___fslt
      000617 AF 82            [24] 1699 	mov	r7, dpl
      000619 E5 81            [12] 1700 	mov	a,sp
      00061B 24 FC            [12] 1701 	add	a,#0xfc
      00061D F5 81            [12] 1702 	mov	sp,a
      00061F D0 02            [24] 1703 	pop	ar2
      000621 D0 03            [24] 1704 	pop	ar3
      000623 D0 04            [24] 1705 	pop	ar4
      000625 D0 05            [24] 1706 	pop	ar5
      000627 D0 06            [24] 1707 	pop	ar6
      000629 EF               [12] 1708 	mov	a,r7
      00062A 70 03            [24] 1709 	jnz	00204$
      00062C 02 07 5E         [24] 1710 	ljmp	00120$
      00062F                       1711 00204$:
                           000578  1712 	C$fuzzy.h$1143$5_0$53 ==.
                                   1713 ;	../../fuzzy.h:1143: result = next;
      00062F E5 08            [12] 1714 	mov	a,_bp
      000631 24 0A            [12] 1715 	add	a,#0x0a
      000633 F8               [12] 1716 	mov	r0,a
      000634 A6 04            [24] 1717 	mov	@r0,ar4
      000636 08               [12] 1718 	inc	r0
      000637 A6 05            [24] 1719 	mov	@r0,ar5
      000639 08               [12] 1720 	inc	r0
      00063A A6 06            [24] 1721 	mov	@r0,ar6
      00063C 08               [12] 1722 	inc	r0
      00063D A6 03            [24] 1723 	mov	@r0,ar3
                           000588  1724 	C$fuzzy.h$1145$4_0$52 ==.
                                   1725 ;	../../fuzzy.h:1145: break;
      00063F 02 07 5E         [24] 1726 	ljmp	00120$
                           00058B  1727 	C$fuzzy.h$1147$4_0$52 ==.
                                   1728 ;	../../fuzzy.h:1147: case FUZZY_LOGIC_ALGEBRAIC:
      000642                       1729 00111$:
                           00058B  1730 	C$fuzzy.h$1150$1_0$47 ==.
                                   1731 ;	../../fuzzy.h:1150: next -
      000642 C0 02            [24] 1732 	push	ar2
      000644 C0 06            [24] 1733 	push	ar6
      000646 C0 05            [24] 1734 	push	ar5
      000648 C0 04            [24] 1735 	push	ar4
      00064A C0 03            [24] 1736 	push	ar3
      00064C C0 02            [24] 1737 	push	ar2
      00064E C0 04            [24] 1738 	push	ar4
      000650 C0 05            [24] 1739 	push	ar5
      000652 C0 06            [24] 1740 	push	ar6
      000654 C0 03            [24] 1741 	push	ar3
                           00059F  1742 	C$fuzzy.h$1151$1_0$47 ==.
                                   1743 ;	../../fuzzy.h:1151: result * next;
      000656 E5 08            [12] 1744 	mov	a,_bp
      000658 24 0A            [12] 1745 	add	a,#0x0a
      00065A F8               [12] 1746 	mov	r0,a
      00065B 86 82            [24] 1747 	mov	dpl, @r0
      00065D 08               [12] 1748 	inc	r0
      00065E 86 83            [24] 1749 	mov	dph, @r0
      000660 08               [12] 1750 	inc	r0
      000661 86 F0            [24] 1751 	mov	b, @r0
      000663 08               [12] 1752 	inc	r0
      000664 E6               [12] 1753 	mov	a, @r0
      000665 12 36 14         [24] 1754 	lcall	___fsadd
      000668 C8               [12] 1755 	xch	a,r0
      000669 E5 08            [12] 1756 	mov	a,_bp
      00066B 24 06            [12] 1757 	add	a,#0x06
      00066D C8               [12] 1758 	xch	a,r0
      00066E A6 82            [24] 1759 	mov	@r0, dpl
      000670 08               [12] 1760 	inc	r0
      000671 A6 83            [24] 1761 	mov	@r0, dph
      000673 08               [12] 1762 	inc	r0
      000674 A6 F0            [24] 1763 	mov	@r0, b
      000676 08               [12] 1764 	inc	r0
      000677 F6               [12] 1765 	mov	@r0,a
      000678 E5 81            [12] 1766 	mov	a,sp
      00067A 24 FC            [12] 1767 	add	a,#0xfc
      00067C F5 81            [12] 1768 	mov	sp,a
      00067E D0 02            [24] 1769 	pop	ar2
      000680 D0 03            [24] 1770 	pop	ar3
      000682 D0 04            [24] 1771 	pop	ar4
      000684 D0 05            [24] 1772 	pop	ar5
      000686 D0 06            [24] 1773 	pop	ar6
      000688 C0 04            [24] 1774 	push	ar4
      00068A C0 05            [24] 1775 	push	ar5
      00068C C0 06            [24] 1776 	push	ar6
      00068E C0 03            [24] 1777 	push	ar3
      000690 E5 08            [12] 1778 	mov	a,_bp
      000692 24 0A            [12] 1779 	add	a,#0x0a
      000694 F8               [12] 1780 	mov	r0,a
      000695 86 82            [24] 1781 	mov	dpl, @r0
      000697 08               [12] 1782 	inc	r0
      000698 86 83            [24] 1783 	mov	dph, @r0
      00069A 08               [12] 1784 	inc	r0
      00069B 86 F0            [24] 1785 	mov	b, @r0
      00069D 08               [12] 1786 	inc	r0
      00069E E6               [12] 1787 	mov	a, @r0
      00069F 12 34 92         [24] 1788 	lcall	___fsmul
      0006A2 AA 82            [24] 1789 	mov	r2, dpl
      0006A4 AB 83            [24] 1790 	mov	r3, dph
      0006A6 AE F0            [24] 1791 	mov	r6, b
      0006A8 FF               [12] 1792 	mov	r7, a
      0006A9 E5 81            [12] 1793 	mov	a,sp
      0006AB 24 FC            [12] 1794 	add	a,#0xfc
      0006AD F5 81            [12] 1795 	mov	sp,a
      0006AF C0 02            [24] 1796 	push	ar2
      0006B1 C0 02            [24] 1797 	push	ar2
      0006B3 C0 03            [24] 1798 	push	ar3
      0006B5 C0 06            [24] 1799 	push	ar6
      0006B7 C0 07            [24] 1800 	push	ar7
                           000602  1801 	C$fuzzy.h$1152$1_0$47 ==.
                                   1802 ;	../../fuzzy.h:1152: break;
      0006B9 E5 08            [12] 1803 	mov	a,_bp
      0006BB 24 06            [12] 1804 	add	a,#0x06
      0006BD F8               [12] 1805 	mov	r0,a
      0006BE 86 82            [24] 1806 	mov	dpl, @r0
      0006C0 08               [12] 1807 	inc	r0
      0006C1 86 83            [24] 1808 	mov	dph, @r0
      0006C3 08               [12] 1809 	inc	r0
      0006C4 86 F0            [24] 1810 	mov	b, @r0
      0006C6 08               [12] 1811 	inc	r0
      0006C7 E6               [12] 1812 	mov	a, @r0
      0006C8 12 34 87         [24] 1813 	lcall	___fssub
      0006CB C8               [12] 1814 	xch	a,r0
      0006CC E5 08            [12] 1815 	mov	a,_bp
      0006CE 24 0A            [12] 1816 	add	a,#0x0a
      0006D0 C8               [12] 1817 	xch	a,r0
      0006D1 A6 82            [24] 1818 	mov	@r0, dpl
      0006D3 08               [12] 1819 	inc	r0
      0006D4 A6 83            [24] 1820 	mov	@r0, dph
      0006D6 08               [12] 1821 	inc	r0
      0006D7 A6 F0            [24] 1822 	mov	@r0, b
      0006D9 08               [12] 1823 	inc	r0
      0006DA F6               [12] 1824 	mov	@r0,a
      0006DB E5 81            [12] 1825 	mov	a,sp
      0006DD 24 FC            [12] 1826 	add	a,#0xfc
      0006DF F5 81            [12] 1827 	mov	sp,a
      0006E1 D0 02            [24] 1828 	pop	ar2
      0006E3 D0 02            [24] 1829 	pop	ar2
                           00062E  1830 	C$fuzzy.h$1154$4_0$52 ==.
                                   1831 ;	../../fuzzy.h:1154: case FUZZY_LOGIC_BOUNDED:
      0006E5 80 77            [24] 1832 	sjmp	00120$
      0006E7                       1833 00112$:
                           000630  1834 	C$fuzzy.h$1156$1_0$47 ==.
                                   1835 ;	../../fuzzy.h:1156: next;
      0006E7 C0 02            [24] 1836 	push	ar2
      0006E9 C0 04            [24] 1837 	push	ar4
      0006EB C0 05            [24] 1838 	push	ar5
      0006ED C0 06            [24] 1839 	push	ar6
      0006EF C0 03            [24] 1840 	push	ar3
                           00063A  1841 	C$fuzzy.h$1158$1_0$47 ==.
                                   1842 ;	../../fuzzy.h:1158: if (result > LEVEL_HI) {
      0006F1 E5 08            [12] 1843 	mov	a,_bp
      0006F3 24 0A            [12] 1844 	add	a,#0x0a
      0006F5 F8               [12] 1845 	mov	r0,a
      0006F6 86 82            [24] 1846 	mov	dpl, @r0
      0006F8 08               [12] 1847 	inc	r0
      0006F9 86 83            [24] 1848 	mov	dph, @r0
      0006FB 08               [12] 1849 	inc	r0
      0006FC 86 F0            [24] 1850 	mov	b, @r0
      0006FE 08               [12] 1851 	inc	r0
      0006FF E6               [12] 1852 	mov	a, @r0
      000700 12 36 14         [24] 1853 	lcall	___fsadd
      000703 C8               [12] 1854 	xch	a,r0
      000704 E5 08            [12] 1855 	mov	a,_bp
      000706 24 0A            [12] 1856 	add	a,#0x0a
      000708 C8               [12] 1857 	xch	a,r0
      000709 A6 82            [24] 1858 	mov	@r0, dpl
      00070B 08               [12] 1859 	inc	r0
      00070C A6 83            [24] 1860 	mov	@r0, dph
      00070E 08               [12] 1861 	inc	r0
      00070F A6 F0            [24] 1862 	mov	@r0, b
      000711 08               [12] 1863 	inc	r0
      000712 F6               [12] 1864 	mov	@r0,a
      000713 E5 81            [12] 1865 	mov	a,sp
      000715 24 FC            [12] 1866 	add	a,#0xfc
      000717 F5 81            [12] 1867 	mov	sp,a
      000719 E5 08            [12] 1868 	mov	a,_bp
      00071B 24 0A            [12] 1869 	add	a,#0x0a
      00071D F8               [12] 1870 	mov	r0,a
      00071E E6               [12] 1871 	mov	a,@r0
      00071F C0 E0            [24] 1872 	push	acc
      000721 08               [12] 1873 	inc	r0
      000722 E6               [12] 1874 	mov	a,@r0
      000723 C0 E0            [24] 1875 	push	acc
      000725 08               [12] 1876 	inc	r0
      000726 E6               [12] 1877 	mov	a,@r0
      000727 C0 E0            [24] 1878 	push	acc
      000729 08               [12] 1879 	inc	r0
      00072A E6               [12] 1880 	mov	a,@r0
      00072B C0 E0            [24] 1881 	push	acc
      00072D 90 00 00         [24] 1882 	mov	dptr,#0x0000
      000730 75 F0 80         [24] 1883 	mov	b, #0x80
      000733 74 3F            [12] 1884 	mov	a, #0x3f
      000735 12 35 C2         [24] 1885 	lcall	___fslt
      000738 AF 82            [24] 1886 	mov	r7, dpl
      00073A E5 81            [12] 1887 	mov	a,sp
      00073C 24 FC            [12] 1888 	add	a,#0xfc
      00073E F5 81            [12] 1889 	mov	sp,a
      000740 D0 02            [24] 1890 	pop	ar2
      000742 EF               [12] 1891 	mov	a,r7
      000743 60 19            [24] 1892 	jz	00120$
                           00068E  1893 	C$fuzzy.h$1159$5_0$54 ==.
                                   1894 ;	../../fuzzy.h:1159: result = LEVEL_HI;
      000745 E5 08            [12] 1895 	mov	a,_bp
      000747 24 0A            [12] 1896 	add	a,#0x0a
      000749 F8               [12] 1897 	mov	r0,a
      00074A E4               [12] 1898 	clr	a
      00074B F6               [12] 1899 	mov	@r0,a
      00074C 08               [12] 1900 	inc	r0
      00074D F6               [12] 1901 	mov	@r0,a
      00074E 08               [12] 1902 	inc	r0
      00074F 76 80            [12] 1903 	mov	@r0,#0x80
      000751 08               [12] 1904 	inc	r0
      000752 76 3F            [12] 1905 	mov	@r0,#0x3f
                           00069D  1906 	C$fuzzy.h$1161$4_0$52 ==.
                                   1907 ;	../../fuzzy.h:1161: break;
                           00069D  1908 	C$fuzzy.h$1163$4_0$52 ==.
                                   1909 ;	../../fuzzy.h:1163: default:
      000754 80 08            [24] 1910 	sjmp	00120$
      000756                       1911 00115$:
                           00069F  1912 	C$fuzzy.h$1164$4_0$52 ==.
                                   1913 ;	../../fuzzy.h:1164: return LEVEL_LO;
      000756 90 00 00         [24] 1914 	mov	dptr,#0x0000
      000759 E4               [12] 1915 	clr	a
      00075A F5 F0            [12] 1916 	mov	b,a
                           0006A5  1917 	C$fuzzy.h$1165$3_0$51 ==.
                                   1918 ;	../../fuzzy.h:1165: }
      00075C 80 20            [24] 1919 	sjmp	00121$
      00075E                       1920 00120$:
                           0006A7  1921 	C$fuzzy.h$1133$2_0$50 ==.
                                   1922 ;	../../fuzzy.h:1133: index++
      00075E E5 08            [12] 1923 	mov	a,_bp
      000760 24 0E            [12] 1924 	add	a,#0x0e
      000762 F8               [12] 1925 	mov	r0,a
      000763 06               [12] 1926 	inc	@r0
      000764 B6 00 02         [24] 1927 	cjne	@r0,#0x00,00206$
      000767 08               [12] 1928 	inc	r0
      000768 06               [12] 1929 	inc	@r0
      000769                       1930 00206$:
      000769 02 05 75         [24] 1931 	ljmp	00119$
      00076C                       1932 00117$:
                           0006B5  1933 	C$fuzzy.h$1169$1_0$47 ==.
                                   1934 ;	../../fuzzy.h:1169: result
      00076C E5 08            [12] 1935 	mov	a,_bp
      00076E 24 0A            [12] 1936 	add	a,#0x0a
      000770 F8               [12] 1937 	mov	r0,a
      000771 86 82            [24] 1938 	mov	dpl, @r0
      000773 08               [12] 1939 	inc	r0
      000774 86 83            [24] 1940 	mov	dph, @r0
      000776 08               [12] 1941 	inc	r0
      000777 86 F0            [24] 1942 	mov	b, @r0
      000779 08               [12] 1943 	inc	r0
      00077A E6               [12] 1944 	mov	a, @r0
      00077B 12 00 EA         [24] 1945 	lcall	_fuzzy_clamp
      00077E                       1946 00121$:
                           0006C7  1947 	C$fuzzy.h$1171$1_0$47 ==.
                                   1948 ;	../../fuzzy.h:1171: }
      00077E 85 08 81         [24] 1949 	mov	sp,_bp
      000781 D0 08            [24] 1950 	pop	_bp
                           0006CC  1951 	C$fuzzy.h$1171$1_0$47 ==.
                           0006CC  1952 	XG$fuzzy_or_array$0$0 ==.
      000783 22               [24] 1953 	ret
                                   1954 ;------------------------------------------------------------
                                   1955 ;Allocation info for local variables in function 'fuzzy_sugeno_weighted_average_array'
                                   1956 ;------------------------------------------------------------
                                   1957 ;values        Allocated to stack - _bp -5 +3 
                                   1958 ;value_count   Allocated to stack - _bp +1 +2 
                                   1959 ;weighted_sum  Allocated to stack - _bp +3 +4 
                                   1960 ;firing_sum    Allocated to stack - _bp +7 +4 
                                   1961 ;firing_strength Allocated to stack - _bp +11 +4 
                                   1962 ;consequent    Allocated to registers r4 r5 r3 r2 
                                   1963 ;index         Allocated to registers r6 r7 
                                   1964 ;------------------------------------------------------------
                           0006CD  1965 	G$fuzzy_sugeno_weighted_average_array$0$0 ==.
                           0006CD  1966 	C$fuzzy.h$1182$1_0$56 ==.
                                   1967 ;	../../fuzzy.h:1182: float fuzzy_sugeno_weighted_average_array(
                                   1968 ;	-----------------------------------------
                                   1969 ;	 function fuzzy_sugeno_weighted_average_array
                                   1970 ;	-----------------------------------------
      000784                       1971 _fuzzy_sugeno_weighted_average_array:
      000784 C0 08            [24] 1972 	push	_bp
      000786 85 81 08         [24] 1973 	mov	_bp,sp
      000789 C0 82            [24] 1974 	push	dpl
      00078B C0 83            [24] 1975 	push	dph
      00078D E5 81            [12] 1976 	mov	a,sp
      00078F 24 0C            [12] 1977 	add	a,#0x0c
      000791 F5 81            [12] 1978 	mov	sp,a
                           0006DC  1979 	C$fuzzy.h$1195$1_0$56 ==.
                                   1980 ;	../../fuzzy.h:1195: values == NULL ||
      000793 E5 08            [12] 1981 	mov	a,_bp
      000795 24 FB            [12] 1982 	add	a,#0xfb
      000797 F8               [12] 1983 	mov	r0,a
      000798 E6               [12] 1984 	mov	a,@r0
      000799 08               [12] 1985 	inc	r0
      00079A 46               [12] 1986 	orl	a,@r0
      00079B 60 0F            [24] 1987 	jz	00101$
                           0006E6  1988 	C$fuzzy.h$1196$1_0$56 ==.
                                   1989 ;	../../fuzzy.h:1196: value_count == 0u ||
      00079D A8 08            [24] 1990 	mov	r0,_bp
      00079F 08               [12] 1991 	inc	r0
      0007A0 E6               [12] 1992 	mov	a,@r0
      0007A1 08               [12] 1993 	inc	r0
      0007A2 46               [12] 1994 	orl	a,@r0
      0007A3 60 07            [24] 1995 	jz	00101$
                           0006EE  1996 	C$fuzzy.h$1197$1_0$56 ==.
                                   1997 ;	../../fuzzy.h:1197: value_count % 2u != 0u
      0007A5 A8 08            [24] 1998 	mov	r0,_bp
      0007A7 08               [12] 1999 	inc	r0
      0007A8 E6               [12] 2000 	mov	a,@r0
      0007A9 30 E0 09         [24] 2001 	jnb	acc.0,00102$
      0007AC                       2002 00101$:
                           0006F5  2003 	C$fuzzy.h$1199$2_0$57 ==.
                                   2004 ;	../../fuzzy.h:1199: return 0.0f;
      0007AC 90 00 00         [24] 2005 	mov	dptr,#0x0000
      0007AF E4               [12] 2006 	clr	a
      0007B0 F5 F0            [12] 2007 	mov	b,a
      0007B2 02 09 7F         [24] 2008 	ljmp	00111$
      0007B5                       2009 00102$:
                           0006FE  2010 	C$fuzzy.h$1203$1_0$56 ==.
                                   2011 ;	../../fuzzy.h:1203: 0.0f;
      0007B5 E5 08            [12] 2012 	mov	a,_bp
      0007B7 24 03            [12] 2013 	add	a,#0x03
      0007B9 F8               [12] 2014 	mov	r0,a
      0007BA E4               [12] 2015 	clr	a
      0007BB F6               [12] 2016 	mov	@r0,a
      0007BC 08               [12] 2017 	inc	r0
      0007BD F6               [12] 2018 	mov	@r0,a
      0007BE 08               [12] 2019 	inc	r0
      0007BF F6               [12] 2020 	mov	@r0,a
      0007C0 08               [12] 2021 	inc	r0
      0007C1 F6               [12] 2022 	mov	@r0,a
                           00070B  2023 	C$fuzzy.h$1206$1_0$56 ==.
                                   2024 ;	../../fuzzy.h:1206: 0.0f;
      0007C2 E5 08            [12] 2025 	mov	a,_bp
      0007C4 24 07            [12] 2026 	add	a,#0x07
      0007C6 F8               [12] 2027 	mov	r0,a
      0007C7 E4               [12] 2028 	clr	a
      0007C8 F6               [12] 2029 	mov	@r0,a
      0007C9 08               [12] 2030 	inc	r0
      0007CA F6               [12] 2031 	mov	@r0,a
      0007CB 08               [12] 2032 	inc	r0
      0007CC F6               [12] 2033 	mov	@r0,a
      0007CD 08               [12] 2034 	inc	r0
      0007CE F6               [12] 2035 	mov	@r0,a
                           000718  2036 	C$fuzzy.h$1209$1_0$56 ==.
                                   2037 ;	../../fuzzy.h:1209: index = 0u;
      0007CF FE               [12] 2038 	mov	r6,a
      0007D0 FF               [12] 2039 	mov	r7,a
      0007D1                       2040 00109$:
                           00071A  2041 	C$fuzzy.h$1210$2_0$58 ==.
                                   2042 ;	../../fuzzy.h:1210: index < value_count;
      0007D1 A8 08            [24] 2043 	mov	r0,_bp
      0007D3 08               [12] 2044 	inc	r0
      0007D4 C3               [12] 2045 	clr	c
      0007D5 EE               [12] 2046 	mov	a,r6
      0007D6 96               [12] 2047 	subb	a,@r0
      0007D7 EF               [12] 2048 	mov	a,r7
      0007D8 08               [12] 2049 	inc	r0
      0007D9 96               [12] 2050 	subb	a,@r0
      0007DA 40 03            [24] 2051 	jc	00147$
      0007DC 02 09 12         [24] 2052 	ljmp	00105$
      0007DF                       2053 00147$:
                           000728  2054 	C$fuzzy.h$1215$3_0$59 ==.
                                   2055 ;	../../fuzzy.h:1215: values[index]
      0007DF EE               [12] 2056 	mov	a,r6
      0007E0 2E               [12] 2057 	add	a,r6
      0007E1 FC               [12] 2058 	mov	r4,a
      0007E2 EF               [12] 2059 	mov	a,r7
      0007E3 33               [12] 2060 	rlc	a
      0007E4 FD               [12] 2061 	mov	r5,a
      0007E5 EC               [12] 2062 	mov	a,r4
      0007E6 2C               [12] 2063 	add	a,r4
      0007E7 FC               [12] 2064 	mov	r4,a
      0007E8 ED               [12] 2065 	mov	a,r5
      0007E9 33               [12] 2066 	rlc	a
      0007EA FD               [12] 2067 	mov	r5,a
      0007EB E5 08            [12] 2068 	mov	a,_bp
      0007ED 24 FB            [12] 2069 	add	a,#0xfb
      0007EF F8               [12] 2070 	mov	r0,a
      0007F0 EC               [12] 2071 	mov	a,r4
      0007F1 26               [12] 2072 	add	a, @r0
      0007F2 FC               [12] 2073 	mov	r4,a
      0007F3 ED               [12] 2074 	mov	a,r5
      0007F4 08               [12] 2075 	inc	r0
      0007F5 36               [12] 2076 	addc	a, @r0
      0007F6 FD               [12] 2077 	mov	r5,a
      0007F7 08               [12] 2078 	inc	r0
      0007F8 86 03            [24] 2079 	mov	ar3,@r0
      0007FA 8C 82            [24] 2080 	mov	dpl,r4
      0007FC 8D 83            [24] 2081 	mov	dph,r5
      0007FE 8B F0            [24] 2082 	mov	b,r3
      000800 12 37 EE         [24] 2083 	lcall	__gptrget
      000803 FC               [12] 2084 	mov	r4,a
      000804 A3               [24] 2085 	inc	dptr
      000805 12 37 EE         [24] 2086 	lcall	__gptrget
      000808 FD               [12] 2087 	mov	r5,a
      000809 A3               [24] 2088 	inc	dptr
      00080A 12 37 EE         [24] 2089 	lcall	__gptrget
      00080D FB               [12] 2090 	mov	r3,a
      00080E A3               [24] 2091 	inc	dptr
      00080F 12 37 EE         [24] 2092 	lcall	__gptrget
      000812 8C 82            [24] 2093 	mov	dpl,r4
      000814 8D 83            [24] 2094 	mov	dph,r5
      000816 8B F0            [24] 2095 	mov	b,r3
      000818 C0 07            [24] 2096 	push	ar7
      00081A C0 06            [24] 2097 	push	ar6
      00081C 12 00 EA         [24] 2098 	lcall	_fuzzy_clamp
      00081F C8               [12] 2099 	xch	a,r0
      000820 E5 08            [12] 2100 	mov	a,_bp
      000822 24 0B            [12] 2101 	add	a,#0x0b
      000824 C8               [12] 2102 	xch	a,r0
      000825 A6 82            [24] 2103 	mov	@r0, dpl
      000827 08               [12] 2104 	inc	r0
      000828 A6 83            [24] 2105 	mov	@r0, dph
      00082A 08               [12] 2106 	inc	r0
      00082B A6 F0            [24] 2107 	mov	@r0, b
      00082D 08               [12] 2108 	inc	r0
      00082E F6               [12] 2109 	mov	@r0,a
      00082F D0 06            [24] 2110 	pop	ar6
      000831 D0 07            [24] 2111 	pop	ar7
                           00077C  2112 	C$fuzzy.h$1219$3_0$59 ==.
                                   2113 ;	../../fuzzy.h:1219: values[index + 1u];
      000833 74 01            [12] 2114 	mov	a,#0x01
      000835 2E               [12] 2115 	add	a, r6
      000836 FC               [12] 2116 	mov	r4,a
      000837 E4               [12] 2117 	clr	a
      000838 3F               [12] 2118 	addc	a, r7
      000839 FD               [12] 2119 	mov	r5,a
      00083A EC               [12] 2120 	mov	a,r4
      00083B 2C               [12] 2121 	add	a,r4
      00083C FC               [12] 2122 	mov	r4,a
      00083D ED               [12] 2123 	mov	a,r5
      00083E 33               [12] 2124 	rlc	a
      00083F FD               [12] 2125 	mov	r5,a
      000840 EC               [12] 2126 	mov	a,r4
      000841 2C               [12] 2127 	add	a,r4
      000842 FC               [12] 2128 	mov	r4,a
      000843 ED               [12] 2129 	mov	a,r5
      000844 33               [12] 2130 	rlc	a
      000845 FD               [12] 2131 	mov	r5,a
      000846 E5 08            [12] 2132 	mov	a,_bp
      000848 24 FB            [12] 2133 	add	a,#0xfb
      00084A F8               [12] 2134 	mov	r0,a
      00084B EC               [12] 2135 	mov	a,r4
      00084C 26               [12] 2136 	add	a, @r0
      00084D FC               [12] 2137 	mov	r4,a
      00084E ED               [12] 2138 	mov	a,r5
      00084F 08               [12] 2139 	inc	r0
      000850 36               [12] 2140 	addc	a, @r0
      000851 FD               [12] 2141 	mov	r5,a
      000852 08               [12] 2142 	inc	r0
      000853 86 03            [24] 2143 	mov	ar3,@r0
      000855 8C 82            [24] 2144 	mov	dpl,r4
      000857 8D 83            [24] 2145 	mov	dph,r5
      000859 8B F0            [24] 2146 	mov	b,r3
      00085B 12 37 EE         [24] 2147 	lcall	__gptrget
      00085E FC               [12] 2148 	mov	r4,a
      00085F A3               [24] 2149 	inc	dptr
      000860 12 37 EE         [24] 2150 	lcall	__gptrget
      000863 FD               [12] 2151 	mov	r5,a
      000864 A3               [24] 2152 	inc	dptr
      000865 12 37 EE         [24] 2153 	lcall	__gptrget
      000868 FB               [12] 2154 	mov	r3,a
      000869 A3               [24] 2155 	inc	dptr
      00086A 12 37 EE         [24] 2156 	lcall	__gptrget
      00086D FA               [12] 2157 	mov	r2,a
                           0007B7  2158 	C$fuzzy.h$1224$1_0$56 ==.
                                   2159 ;	../../fuzzy.h:1224: consequent;
      00086E C0 07            [24] 2160 	push	ar7
      000870 C0 06            [24] 2161 	push	ar6
      000872 C0 04            [24] 2162 	push	ar4
      000874 C0 05            [24] 2163 	push	ar5
      000876 C0 03            [24] 2164 	push	ar3
      000878 C0 02            [24] 2165 	push	ar2
      00087A E5 08            [12] 2166 	mov	a,_bp
      00087C 24 0B            [12] 2167 	add	a,#0x0b
      00087E F8               [12] 2168 	mov	r0,a
      00087F 86 82            [24] 2169 	mov	dpl, @r0
      000881 08               [12] 2170 	inc	r0
      000882 86 83            [24] 2171 	mov	dph, @r0
      000884 08               [12] 2172 	inc	r0
      000885 86 F0            [24] 2173 	mov	b, @r0
      000887 08               [12] 2174 	inc	r0
      000888 E6               [12] 2175 	mov	a, @r0
      000889 12 34 92         [24] 2176 	lcall	___fsmul
      00088C AA 82            [24] 2177 	mov	r2, dpl
      00088E AB 83            [24] 2178 	mov	r3, dph
      000890 AC F0            [24] 2179 	mov	r4, b
      000892 FD               [12] 2180 	mov	r5, a
      000893 E5 81            [12] 2181 	mov	a,sp
      000895 24 FC            [12] 2182 	add	a,#0xfc
      000897 F5 81            [12] 2183 	mov	sp,a
      000899 C0 02            [24] 2184 	push	ar2
      00089B C0 03            [24] 2185 	push	ar3
      00089D C0 04            [24] 2186 	push	ar4
      00089F C0 05            [24] 2187 	push	ar5
                           0007EA  2188 	C$fuzzy.h$1227$1_0$56 ==.
                                   2189 ;	../../fuzzy.h:1227: firing_strength;
      0008A1 E5 08            [12] 2190 	mov	a,_bp
      0008A3 24 03            [12] 2191 	add	a,#0x03
      0008A5 F8               [12] 2192 	mov	r0,a
      0008A6 86 82            [24] 2193 	mov	dpl, @r0
      0008A8 08               [12] 2194 	inc	r0
      0008A9 86 83            [24] 2195 	mov	dph, @r0
      0008AB 08               [12] 2196 	inc	r0
      0008AC 86 F0            [24] 2197 	mov	b, @r0
      0008AE 08               [12] 2198 	inc	r0
      0008AF E6               [12] 2199 	mov	a, @r0
      0008B0 12 36 14         [24] 2200 	lcall	___fsadd
      0008B3 A8 08            [24] 2201 	mov	r0,_bp
      0008B5 08               [12] 2202 	inc	r0
      0008B6 08               [12] 2203 	inc	r0
      0008B7 08               [12] 2204 	inc	r0
      0008B8 A6 82            [24] 2205 	mov	@r0, dpl
      0008BA 08               [12] 2206 	inc	r0
      0008BB A6 83            [24] 2207 	mov	@r0, dph
      0008BD 08               [12] 2208 	inc	r0
      0008BE A6 F0            [24] 2209 	mov	@r0, b
      0008C0 08               [12] 2210 	inc	r0
      0008C1 F6               [12] 2211 	mov	@r0,a
      0008C2 E5 81            [12] 2212 	mov	a,sp
      0008C4 24 FC            [12] 2213 	add	a,#0xfc
      0008C6 F5 81            [12] 2214 	mov	sp,a
      0008C8 E5 08            [12] 2215 	mov	a,_bp
      0008CA 24 0B            [12] 2216 	add	a,#0x0b
      0008CC F8               [12] 2217 	mov	r0,a
      0008CD E6               [12] 2218 	mov	a,@r0
      0008CE C0 E0            [24] 2219 	push	acc
      0008D0 08               [12] 2220 	inc	r0
      0008D1 E6               [12] 2221 	mov	a,@r0
      0008D2 C0 E0            [24] 2222 	push	acc
      0008D4 08               [12] 2223 	inc	r0
      0008D5 E6               [12] 2224 	mov	a,@r0
      0008D6 C0 E0            [24] 2225 	push	acc
      0008D8 08               [12] 2226 	inc	r0
      0008D9 E6               [12] 2227 	mov	a,@r0
      0008DA C0 E0            [24] 2228 	push	acc
                           000825  2229 	C$fuzzy.h$1212$1_0$56 ==.
                                   2230 ;	../../fuzzy.h:1212: ) {
      0008DC E5 08            [12] 2231 	mov	a,_bp
      0008DE 24 07            [12] 2232 	add	a,#0x07
      0008E0 F8               [12] 2233 	mov	r0,a
      0008E1 86 82            [24] 2234 	mov	dpl, @r0
      0008E3 08               [12] 2235 	inc	r0
      0008E4 86 83            [24] 2236 	mov	dph, @r0
      0008E6 08               [12] 2237 	inc	r0
      0008E7 86 F0            [24] 2238 	mov	b, @r0
      0008E9 08               [12] 2239 	inc	r0
      0008EA E6               [12] 2240 	mov	a, @r0
      0008EB 12 36 14         [24] 2241 	lcall	___fsadd
      0008EE C8               [12] 2242 	xch	a,r0
      0008EF E5 08            [12] 2243 	mov	a,_bp
      0008F1 24 07            [12] 2244 	add	a,#0x07
      0008F3 C8               [12] 2245 	xch	a,r0
      0008F4 A6 82            [24] 2246 	mov	@r0, dpl
      0008F6 08               [12] 2247 	inc	r0
      0008F7 A6 83            [24] 2248 	mov	@r0, dph
      0008F9 08               [12] 2249 	inc	r0
      0008FA A6 F0            [24] 2250 	mov	@r0, b
      0008FC 08               [12] 2251 	inc	r0
      0008FD F6               [12] 2252 	mov	@r0,a
      0008FE E5 81            [12] 2253 	mov	a,sp
      000900 24 FC            [12] 2254 	add	a,#0xfc
      000902 F5 81            [12] 2255 	mov	sp,a
      000904 D0 06            [24] 2256 	pop	ar6
      000906 D0 07            [24] 2257 	pop	ar7
      000908 74 02            [12] 2258 	mov	a,#0x02
      00090A 2E               [12] 2259 	add	a, r6
      00090B FE               [12] 2260 	mov	r6,a
      00090C E4               [12] 2261 	clr	a
      00090D 3F               [12] 2262 	addc	a, r7
      00090E FF               [12] 2263 	mov	r7,a
      00090F 02 07 D1         [24] 2264 	ljmp	00109$
      000912                       2265 00105$:
                           00085B  2266 	C$fuzzy.h$1230$1_0$56 ==.
                                   2267 ;	../../fuzzy.h:1230: if (firing_sum <= LEVEL_LO) {
      000912 E5 08            [12] 2268 	mov	a,_bp
      000914 24 07            [12] 2269 	add	a,#0x07
      000916 F8               [12] 2270 	mov	r0,a
      000917 E6               [12] 2271 	mov	a,@r0
      000918 C0 E0            [24] 2272 	push	acc
      00091A 08               [12] 2273 	inc	r0
      00091B E6               [12] 2274 	mov	a,@r0
      00091C C0 E0            [24] 2275 	push	acc
      00091E 08               [12] 2276 	inc	r0
      00091F E6               [12] 2277 	mov	a,@r0
      000920 C0 E0            [24] 2278 	push	acc
      000922 08               [12] 2279 	inc	r0
      000923 E6               [12] 2280 	mov	a,@r0
      000924 C0 E0            [24] 2281 	push	acc
      000926 90 00 00         [24] 2282 	mov	dptr,#0x0000
      000929 E4               [12] 2283 	clr	a
      00092A F5 F0            [12] 2284 	mov	b,a
      00092C 12 35 C2         [24] 2285 	lcall	___fslt
      00092F E5 81            [12] 2286 	mov	a,sp
      000931 24 FC            [12] 2287 	add	a,#0xfc
      000933 F5 81            [12] 2288 	mov	sp,a
      000935 E5 82            [12] 2289 	mov	a, dpl
      000937 24 FF            [12] 2290 	add	a,#0xff
      000939 92 00            [24] 2291 	mov	b0,c
      00093B 40 08            [24] 2292 	jc	00107$
                           000886  2293 	C$fuzzy.h$1231$2_0$60 ==.
                                   2294 ;	../../fuzzy.h:1231: return 0.0f;
      00093D 90 00 00         [24] 2295 	mov	dptr,#0x0000
      000940 E4               [12] 2296 	clr	a
      000941 F5 F0            [12] 2297 	mov	b,a
      000943 80 3A            [24] 2298 	sjmp	00111$
      000945                       2299 00107$:
                           00088E  2300 	C$fuzzy.h$1235$1_0$56 ==.
                                   2301 ;	../../fuzzy.h:1235: firing_sum;
      000945 E5 08            [12] 2302 	mov	a,_bp
      000947 24 07            [12] 2303 	add	a,#0x07
      000949 F8               [12] 2304 	mov	r0,a
      00094A E6               [12] 2305 	mov	a,@r0
      00094B C0 E0            [24] 2306 	push	acc
      00094D 08               [12] 2307 	inc	r0
      00094E E6               [12] 2308 	mov	a,@r0
      00094F C0 E0            [24] 2309 	push	acc
      000951 08               [12] 2310 	inc	r0
      000952 E6               [12] 2311 	mov	a,@r0
      000953 C0 E0            [24] 2312 	push	acc
      000955 08               [12] 2313 	inc	r0
      000956 E6               [12] 2314 	mov	a,@r0
      000957 C0 E0            [24] 2315 	push	acc
      000959 E5 08            [12] 2316 	mov	a,_bp
      00095B 24 03            [12] 2317 	add	a,#0x03
      00095D F8               [12] 2318 	mov	r0,a
      00095E 86 82            [24] 2319 	mov	dpl, @r0
      000960 08               [12] 2320 	inc	r0
      000961 86 83            [24] 2321 	mov	dph, @r0
      000963 08               [12] 2322 	inc	r0
      000964 86 F0            [24] 2323 	mov	b, @r0
      000966 08               [12] 2324 	inc	r0
      000967 E6               [12] 2325 	mov	a, @r0
      000968 12 37 2B         [24] 2326 	lcall	___fsdiv
      00096B AC 82            [24] 2327 	mov	r4, dpl
      00096D AD 83            [24] 2328 	mov	r5, dph
      00096F AE F0            [24] 2329 	mov	r6, b
      000971 FF               [12] 2330 	mov	r7, a
      000972 E5 81            [12] 2331 	mov	a,sp
      000974 24 FC            [12] 2332 	add	a,#0xfc
      000976 F5 81            [12] 2333 	mov	sp,a
      000978 8C 82            [24] 2334 	mov	dpl, r4
      00097A 8D 83            [24] 2335 	mov	dph, r5
      00097C 8E F0            [24] 2336 	mov	b, r6
      00097E EF               [12] 2337 	mov	a, r7
      00097F                       2338 00111$:
                           0008C8  2339 	C$fuzzy.h$1236$1_0$56 ==.
                                   2340 ;	../../fuzzy.h:1236: }
      00097F 85 08 81         [24] 2341 	mov	sp,_bp
      000982 D0 08            [24] 2342 	pop	_bp
                           0008CD  2343 	C$fuzzy.h$1236$1_0$56 ==.
                           0008CD  2344 	XG$fuzzy_sugeno_weighted_average_array$0$0 ==.
      000984 22               [24] 2345 	ret
                                   2346 ;------------------------------------------------------------
                                   2347 ;Allocation info for local variables in function 'fuzzy_sugeno_weighted_sum_array'
                                   2348 ;------------------------------------------------------------
                                   2349 ;values        Allocated to stack - _bp -5 +3 
                                   2350 ;value_count   Allocated to registers r6 r7 
                                   2351 ;weighted_sum  Allocated to stack - _bp +1 +4 
                                   2352 ;firing_strength Allocated to stack - _bp +5 +4 
                                   2353 ;consequent    Allocated to registers r6 r7 r3 r2 
                                   2354 ;index         Allocated to registers r4 r5 
                                   2355 ;------------------------------------------------------------
                           0008CE  2356 	G$fuzzy_sugeno_weighted_sum_array$0$0 ==.
                           0008CE  2357 	C$fuzzy.h$1246$1_0$62 ==.
                                   2358 ;	../../fuzzy.h:1246: float fuzzy_sugeno_weighted_sum_array(
                                   2359 ;	-----------------------------------------
                                   2360 ;	 function fuzzy_sugeno_weighted_sum_array
                                   2361 ;	-----------------------------------------
      000985                       2362 _fuzzy_sugeno_weighted_sum_array:
      000985 C0 08            [24] 2363 	push	_bp
      000987 E5 81            [12] 2364 	mov	a,sp
      000989 F5 08            [12] 2365 	mov	_bp,a
      00098B 24 08            [12] 2366 	add	a,#0x08
      00098D F5 81            [12] 2367 	mov	sp,a
      00098F AE 82            [24] 2368 	mov	r6, dpl
      000991 AF 83            [24] 2369 	mov	r7, dph
                           0008DC  2370 	C$fuzzy.h$1258$1_0$62 ==.
                                   2371 ;	../../fuzzy.h:1258: values == NULL ||
      000993 E5 08            [12] 2372 	mov	a,_bp
      000995 24 FB            [12] 2373 	add	a,#0xfb
      000997 F8               [12] 2374 	mov	r0,a
      000998 E6               [12] 2375 	mov	a,@r0
      000999 08               [12] 2376 	inc	r0
      00099A 46               [12] 2377 	orl	a,@r0
      00099B 60 08            [24] 2378 	jz	00101$
                           0008E6  2379 	C$fuzzy.h$1259$1_0$62 ==.
                                   2380 ;	../../fuzzy.h:1259: value_count == 0u ||
      00099D EE               [12] 2381 	mov	a,r6
      00099E 4F               [12] 2382 	orl	a,r7
      00099F 60 04            [24] 2383 	jz	00101$
                           0008EA  2384 	C$fuzzy.h$1260$1_0$62 ==.
                                   2385 ;	../../fuzzy.h:1260: value_count % 2u != 0u
      0009A1 EE               [12] 2386 	mov	a,r6
      0009A2 30 E0 09         [24] 2387 	jnb	acc.0,00102$
      0009A5                       2388 00101$:
                           0008EE  2389 	C$fuzzy.h$1262$2_0$63 ==.
                                   2390 ;	../../fuzzy.h:1262: return 0.0f;
      0009A5 90 00 00         [24] 2391 	mov	dptr,#0x0000
      0009A8 E4               [12] 2392 	clr	a
      0009A9 F5 F0            [12] 2393 	mov	b,a
      0009AB 02 0A E6         [24] 2394 	ljmp	00109$
      0009AE                       2395 00102$:
                           0008F7  2396 	C$fuzzy.h$1266$1_0$62 ==.
                                   2397 ;	../../fuzzy.h:1266: 0.0f;
      0009AE A8 08            [24] 2398 	mov	r0,_bp
      0009B0 08               [12] 2399 	inc	r0
      0009B1 E4               [12] 2400 	clr	a
      0009B2 F6               [12] 2401 	mov	@r0,a
      0009B3 08               [12] 2402 	inc	r0
      0009B4 F6               [12] 2403 	mov	@r0,a
      0009B5 08               [12] 2404 	inc	r0
      0009B6 F6               [12] 2405 	mov	@r0,a
      0009B7 08               [12] 2406 	inc	r0
      0009B8 F6               [12] 2407 	mov	@r0,a
                           000902  2408 	C$fuzzy.h$1269$1_0$62 ==.
                                   2409 ;	../../fuzzy.h:1269: index = 0u;
      0009B9 FC               [12] 2410 	mov	r4,a
      0009BA FD               [12] 2411 	mov	r5,a
      0009BB                       2412 00107$:
                           000904  2413 	C$fuzzy.h$1270$2_0$64 ==.
                                   2414 ;	../../fuzzy.h:1270: index < value_count;
      0009BB C3               [12] 2415 	clr	c
      0009BC EC               [12] 2416 	mov	a,r4
      0009BD 9E               [12] 2417 	subb	a,r6
      0009BE ED               [12] 2418 	mov	a,r5
      0009BF 9F               [12] 2419 	subb	a,r7
      0009C0 40 03            [24] 2420 	jc	00139$
      0009C2 02 0A D9         [24] 2421 	ljmp	00105$
      0009C5                       2422 00139$:
                           00090E  2423 	C$fuzzy.h$1275$1_0$62 ==.
                                   2424 ;	../../fuzzy.h:1275: values[index]
      0009C5 C0 06            [24] 2425 	push	ar6
      0009C7 C0 07            [24] 2426 	push	ar7
      0009C9 EC               [12] 2427 	mov	a,r4
      0009CA 2C               [12] 2428 	add	a,r4
      0009CB FA               [12] 2429 	mov	r2,a
      0009CC ED               [12] 2430 	mov	a,r5
      0009CD 33               [12] 2431 	rlc	a
      0009CE FB               [12] 2432 	mov	r3,a
      0009CF EA               [12] 2433 	mov	a,r2
      0009D0 2A               [12] 2434 	add	a,r2
      0009D1 FA               [12] 2435 	mov	r2,a
      0009D2 EB               [12] 2436 	mov	a,r3
      0009D3 33               [12] 2437 	rlc	a
      0009D4 FB               [12] 2438 	mov	r3,a
      0009D5 E5 08            [12] 2439 	mov	a,_bp
      0009D7 24 FB            [12] 2440 	add	a,#0xfb
      0009D9 F8               [12] 2441 	mov	r0,a
      0009DA EA               [12] 2442 	mov	a,r2
      0009DB 26               [12] 2443 	add	a, @r0
      0009DC FA               [12] 2444 	mov	r2,a
      0009DD EB               [12] 2445 	mov	a,r3
      0009DE 08               [12] 2446 	inc	r0
      0009DF 36               [12] 2447 	addc	a, @r0
      0009E0 FB               [12] 2448 	mov	r3,a
      0009E1 08               [12] 2449 	inc	r0
      0009E2 86 07            [24] 2450 	mov	ar7,@r0
      0009E4 8A 82            [24] 2451 	mov	dpl,r2
      0009E6 8B 83            [24] 2452 	mov	dph,r3
      0009E8 8F F0            [24] 2453 	mov	b,r7
      0009EA 12 37 EE         [24] 2454 	lcall	__gptrget
      0009ED FA               [12] 2455 	mov	r2,a
      0009EE A3               [24] 2456 	inc	dptr
      0009EF 12 37 EE         [24] 2457 	lcall	__gptrget
      0009F2 FB               [12] 2458 	mov	r3,a
      0009F3 A3               [24] 2459 	inc	dptr
      0009F4 12 37 EE         [24] 2460 	lcall	__gptrget
      0009F7 FF               [12] 2461 	mov	r7,a
      0009F8 A3               [24] 2462 	inc	dptr
      0009F9 12 37 EE         [24] 2463 	lcall	__gptrget
      0009FC FE               [12] 2464 	mov	r6,a
      0009FD 8A 82            [24] 2465 	mov	dpl,r2
      0009FF 8B 83            [24] 2466 	mov	dph,r3
      000A01 8F F0            [24] 2467 	mov	b,r7
      000A03 C0 07            [24] 2468 	push	ar7
      000A05 C0 06            [24] 2469 	push	ar6
      000A07 C0 05            [24] 2470 	push	ar5
      000A09 C0 04            [24] 2471 	push	ar4
      000A0B 12 00 EA         [24] 2472 	lcall	_fuzzy_clamp
      000A0E C8               [12] 2473 	xch	a,r0
      000A0F E5 08            [12] 2474 	mov	a,_bp
      000A11 24 05            [12] 2475 	add	a,#0x05
      000A13 C8               [12] 2476 	xch	a,r0
      000A14 A6 82            [24] 2477 	mov	@r0, dpl
      000A16 08               [12] 2478 	inc	r0
      000A17 A6 83            [24] 2479 	mov	@r0, dph
      000A19 08               [12] 2480 	inc	r0
      000A1A A6 F0            [24] 2481 	mov	@r0, b
      000A1C 08               [12] 2482 	inc	r0
      000A1D F6               [12] 2483 	mov	@r0,a
      000A1E D0 04            [24] 2484 	pop	ar4
      000A20 D0 05            [24] 2485 	pop	ar5
      000A22 D0 06            [24] 2486 	pop	ar6
      000A24 D0 07            [24] 2487 	pop	ar7
                           00096F  2488 	C$fuzzy.h$1279$3_0$65 ==.
                                   2489 ;	../../fuzzy.h:1279: values[index + 1u];
      000A26 74 01            [12] 2490 	mov	a,#0x01
      000A28 2C               [12] 2491 	add	a, r4
      000A29 FE               [12] 2492 	mov	r6,a
      000A2A E4               [12] 2493 	clr	a
      000A2B 3D               [12] 2494 	addc	a, r5
      000A2C FF               [12] 2495 	mov	r7,a
      000A2D EE               [12] 2496 	mov	a,r6
      000A2E 2E               [12] 2497 	add	a,r6
      000A2F FE               [12] 2498 	mov	r6,a
      000A30 EF               [12] 2499 	mov	a,r7
      000A31 33               [12] 2500 	rlc	a
      000A32 FF               [12] 2501 	mov	r7,a
      000A33 EE               [12] 2502 	mov	a,r6
      000A34 2E               [12] 2503 	add	a,r6
      000A35 FE               [12] 2504 	mov	r6,a
      000A36 EF               [12] 2505 	mov	a,r7
      000A37 33               [12] 2506 	rlc	a
      000A38 FF               [12] 2507 	mov	r7,a
      000A39 E5 08            [12] 2508 	mov	a,_bp
      000A3B 24 FB            [12] 2509 	add	a,#0xfb
      000A3D F8               [12] 2510 	mov	r0,a
      000A3E EE               [12] 2511 	mov	a,r6
      000A3F 26               [12] 2512 	add	a, @r0
      000A40 FE               [12] 2513 	mov	r6,a
      000A41 EF               [12] 2514 	mov	a,r7
      000A42 08               [12] 2515 	inc	r0
      000A43 36               [12] 2516 	addc	a, @r0
      000A44 FF               [12] 2517 	mov	r7,a
      000A45 08               [12] 2518 	inc	r0
      000A46 86 03            [24] 2519 	mov	ar3,@r0
      000A48 8E 82            [24] 2520 	mov	dpl,r6
      000A4A 8F 83            [24] 2521 	mov	dph,r7
      000A4C 8B F0            [24] 2522 	mov	b,r3
      000A4E 12 37 EE         [24] 2523 	lcall	__gptrget
      000A51 FE               [12] 2524 	mov	r6,a
      000A52 A3               [24] 2525 	inc	dptr
      000A53 12 37 EE         [24] 2526 	lcall	__gptrget
      000A56 FF               [12] 2527 	mov	r7,a
      000A57 A3               [24] 2528 	inc	dptr
      000A58 12 37 EE         [24] 2529 	lcall	__gptrget
      000A5B FB               [12] 2530 	mov	r3,a
      000A5C A3               [24] 2531 	inc	dptr
      000A5D 12 37 EE         [24] 2532 	lcall	__gptrget
      000A60 FA               [12] 2533 	mov	r2,a
                           0009AA  2534 	C$fuzzy.h$1284$1_0$62 ==.
                                   2535 ;	../../fuzzy.h:1284: consequent;
      000A61 C0 05            [24] 2536 	push	ar5
      000A63 C0 04            [24] 2537 	push	ar4
      000A65 C0 06            [24] 2538 	push	ar6
      000A67 C0 07            [24] 2539 	push	ar7
      000A69 C0 03            [24] 2540 	push	ar3
      000A6B C0 02            [24] 2541 	push	ar2
      000A6D E5 08            [12] 2542 	mov	a,_bp
      000A6F 24 05            [12] 2543 	add	a,#0x05
      000A71 F8               [12] 2544 	mov	r0,a
      000A72 86 82            [24] 2545 	mov	dpl, @r0
      000A74 08               [12] 2546 	inc	r0
      000A75 86 83            [24] 2547 	mov	dph, @r0
      000A77 08               [12] 2548 	inc	r0
      000A78 86 F0            [24] 2549 	mov	b, @r0
      000A7A 08               [12] 2550 	inc	r0
      000A7B E6               [12] 2551 	mov	a, @r0
      000A7C 12 34 92         [24] 2552 	lcall	___fsmul
      000A7F AA 82            [24] 2553 	mov	r2, dpl
      000A81 AB 83            [24] 2554 	mov	r3, dph
      000A83 AE F0            [24] 2555 	mov	r6, b
      000A85 FF               [12] 2556 	mov	r7, a
      000A86 E5 81            [12] 2557 	mov	a,sp
      000A88 24 FC            [12] 2558 	add	a,#0xfc
      000A8A F5 81            [12] 2559 	mov	sp,a
      000A8C D0 04            [24] 2560 	pop	ar4
      000A8E D0 05            [24] 2561 	pop	ar5
      000A90 C0 07            [24] 2562 	push	ar7
      000A92 C0 06            [24] 2563 	push	ar6
      000A94 C0 05            [24] 2564 	push	ar5
      000A96 C0 04            [24] 2565 	push	ar4
      000A98 C0 02            [24] 2566 	push	ar2
      000A9A C0 03            [24] 2567 	push	ar3
      000A9C C0 06            [24] 2568 	push	ar6
      000A9E C0 07            [24] 2569 	push	ar7
                           0009E9  2570 	C$fuzzy.h$1272$1_0$62 ==.
                                   2571 ;	../../fuzzy.h:1272: ) {
      000AA0 A8 08            [24] 2572 	mov	r0,_bp
      000AA2 08               [12] 2573 	inc	r0
      000AA3 86 82            [24] 2574 	mov	dpl, @r0
      000AA5 08               [12] 2575 	inc	r0
      000AA6 86 83            [24] 2576 	mov	dph, @r0
      000AA8 08               [12] 2577 	inc	r0
      000AA9 86 F0            [24] 2578 	mov	b, @r0
      000AAB 08               [12] 2579 	inc	r0
      000AAC E6               [12] 2580 	mov	a, @r0
      000AAD 12 36 14         [24] 2581 	lcall	___fsadd
      000AB0 A8 08            [24] 2582 	mov	r0,_bp
      000AB2 08               [12] 2583 	inc	r0
      000AB3 A6 82            [24] 2584 	mov	@r0, dpl
      000AB5 08               [12] 2585 	inc	r0
      000AB6 A6 83            [24] 2586 	mov	@r0, dph
      000AB8 08               [12] 2587 	inc	r0
      000AB9 A6 F0            [24] 2588 	mov	@r0, b
      000ABB 08               [12] 2589 	inc	r0
      000ABC F6               [12] 2590 	mov	@r0,a
      000ABD E5 81            [12] 2591 	mov	a,sp
      000ABF 24 FC            [12] 2592 	add	a,#0xfc
      000AC1 F5 81            [12] 2593 	mov	sp,a
      000AC3 D0 04            [24] 2594 	pop	ar4
      000AC5 D0 05            [24] 2595 	pop	ar5
      000AC7 D0 06            [24] 2596 	pop	ar6
      000AC9 D0 07            [24] 2597 	pop	ar7
      000ACB 74 02            [12] 2598 	mov	a,#0x02
      000ACD 2C               [12] 2599 	add	a, r4
      000ACE FC               [12] 2600 	mov	r4,a
      000ACF E4               [12] 2601 	clr	a
      000AD0 3D               [12] 2602 	addc	a, r5
      000AD1 FD               [12] 2603 	mov	r5,a
      000AD2 D0 07            [24] 2604 	pop	ar7
      000AD4 D0 06            [24] 2605 	pop	ar6
      000AD6 02 09 BB         [24] 2606 	ljmp	00107$
      000AD9                       2607 00105$:
                           000A22  2608 	C$fuzzy.h$1287$1_0$62 ==.
                                   2609 ;	../../fuzzy.h:1287: return weighted_sum;
      000AD9 A8 08            [24] 2610 	mov	r0,_bp
      000ADB 08               [12] 2611 	inc	r0
      000ADC 86 82            [24] 2612 	mov	dpl, @r0
      000ADE 08               [12] 2613 	inc	r0
      000ADF 86 83            [24] 2614 	mov	dph, @r0
      000AE1 08               [12] 2615 	inc	r0
      000AE2 86 F0            [24] 2616 	mov	b, @r0
      000AE4 08               [12] 2617 	inc	r0
      000AE5 E6               [12] 2618 	mov	a, @r0
      000AE6                       2619 00109$:
                           000A2F  2620 	C$fuzzy.h$1288$1_0$62 ==.
                                   2621 ;	../../fuzzy.h:1288: }
      000AE6 85 08 81         [24] 2622 	mov	sp,_bp
      000AE9 D0 08            [24] 2623 	pop	_bp
                           000A34  2624 	C$fuzzy.h$1288$1_0$62 ==.
                           000A34  2625 	XG$fuzzy_sugeno_weighted_sum_array$0$0 ==.
      000AEB 22               [24] 2626 	ret
                                   2627 ;------------------------------------------------------------
                                   2628 ;Allocation info for local variables in function 'fuzzy_ramp'
                                   2629 ;------------------------------------------------------------
                                   2630 ;upper_boundary Allocated to stack - _bp -6 +4 
                                   2631 ;value         Allocated to stack - _bp -10 +4 
                                   2632 ;ramp_up       Allocated to stack - _bp -11 +1 
                                   2633 ;hedge         Allocated to stack - _bp -12 +1 
                                   2634 ;lower_boundary Allocated to registers r7 r6 r5 r4 
                                   2635 ;result        Allocated to stack - _bp +5 +4 
                                   2636 ;normalized    Allocated to registers r4 r5 r6 r7 
                                   2637 ;sloc0         Allocated to stack - _bp +13 +4 
                                   2638 ;sloc1         Allocated to stack - _bp +1 +4 
                                   2639 ;------------------------------------------------------------
                           000A35  2640 	G$fuzzy_ramp$0$0 ==.
                           000A35  2641 	C$fuzzy.h$1294$1_0$67 ==.
                                   2642 ;	../../fuzzy.h:1294: float fuzzy_ramp(
                                   2643 ;	-----------------------------------------
                                   2644 ;	 function fuzzy_ramp
                                   2645 ;	-----------------------------------------
      000AEC                       2646 _fuzzy_ramp:
      000AEC C0 08            [24] 2647 	push	_bp
      000AEE 85 81 08         [24] 2648 	mov	_bp,sp
      000AF1 AF 82            [24] 2649 	mov	r7,dpl
      000AF3 AE 83            [24] 2650 	mov	r6,dph
      000AF5 AD F0            [24] 2651 	mov	r5,b
      000AF7 FC               [12] 2652 	mov	r4,a
      000AF8 E5 81            [12] 2653 	mov	a,sp
      000AFA 24 08            [12] 2654 	add	a,#0x08
      000AFC F5 81            [12] 2655 	mov	sp,a
                           000A47  2656 	C$fuzzy.h$1305$1_0$67 ==.
                                   2657 ;	../../fuzzy.h:1305: if (lower_boundary >= upper_boundary) {
      000AFE C0 07            [24] 2658 	push	ar7
      000B00 C0 06            [24] 2659 	push	ar6
      000B02 C0 05            [24] 2660 	push	ar5
      000B04 C0 04            [24] 2661 	push	ar4
      000B06 E5 08            [12] 2662 	mov	a,_bp
      000B08 24 FA            [12] 2663 	add	a,#0xfa
      000B0A F8               [12] 2664 	mov	r0,a
      000B0B E6               [12] 2665 	mov	a,@r0
      000B0C C0 E0            [24] 2666 	push	acc
      000B0E 08               [12] 2667 	inc	r0
      000B0F E6               [12] 2668 	mov	a,@r0
      000B10 C0 E0            [24] 2669 	push	acc
      000B12 08               [12] 2670 	inc	r0
      000B13 E6               [12] 2671 	mov	a,@r0
      000B14 C0 E0            [24] 2672 	push	acc
      000B16 08               [12] 2673 	inc	r0
      000B17 E6               [12] 2674 	mov	a,@r0
      000B18 C0 E0            [24] 2675 	push	acc
      000B1A 8F 82            [24] 2676 	mov	dpl, r7
      000B1C 8E 83            [24] 2677 	mov	dph, r6
      000B1E 8D F0            [24] 2678 	mov	b, r5
      000B20 EC               [12] 2679 	mov	a, r4
      000B21 12 35 C2         [24] 2680 	lcall	___fslt
      000B24 E5 81            [12] 2681 	mov	a,sp
      000B26 24 FC            [12] 2682 	add	a,#0xfc
      000B28 F5 81            [12] 2683 	mov	sp,a
      000B2A D0 04            [24] 2684 	pop	ar4
      000B2C D0 05            [24] 2685 	pop	ar5
      000B2E D0 06            [24] 2686 	pop	ar6
      000B30 D0 07            [24] 2687 	pop	ar7
      000B32 E5 82            [12] 2688 	mov	a, dpl
      000B34 24 FF            [12] 2689 	add	a,#0xff
      000B36 92 00            [24] 2690 	mov	b0,c
      000B38 40 09            [24] 2691 	jc	00102$
                           000A83  2692 	C$fuzzy.h$1306$2_0$68 ==.
                                   2693 ;	../../fuzzy.h:1306: return LEVEL_LO;
      000B3A 90 00 00         [24] 2694 	mov	dptr,#0x0000
      000B3D E4               [12] 2695 	clr	a
      000B3E F5 F0            [12] 2696 	mov	b,a
      000B40 02 0D 23         [24] 2697 	ljmp	00109$
      000B43                       2698 00102$:
                           000A8C  2699 	C$fuzzy.h$1309$1_0$67 ==.
                                   2700 ;	../../fuzzy.h:1309: if (value <= lower_boundary) {
      000B43 C0 07            [24] 2701 	push	ar7
      000B45 C0 06            [24] 2702 	push	ar6
      000B47 C0 05            [24] 2703 	push	ar5
      000B49 C0 04            [24] 2704 	push	ar4
      000B4B E5 08            [12] 2705 	mov	a,_bp
      000B4D 24 F6            [12] 2706 	add	a,#0xf6
      000B4F F8               [12] 2707 	mov	r0,a
      000B50 E6               [12] 2708 	mov	a,@r0
      000B51 C0 E0            [24] 2709 	push	acc
      000B53 08               [12] 2710 	inc	r0
      000B54 E6               [12] 2711 	mov	a,@r0
      000B55 C0 E0            [24] 2712 	push	acc
      000B57 08               [12] 2713 	inc	r0
      000B58 E6               [12] 2714 	mov	a,@r0
      000B59 C0 E0            [24] 2715 	push	acc
      000B5B 08               [12] 2716 	inc	r0
      000B5C E6               [12] 2717 	mov	a,@r0
      000B5D C0 E0            [24] 2718 	push	acc
      000B5F 8F 82            [24] 2719 	mov	dpl, r7
      000B61 8E 83            [24] 2720 	mov	dph, r6
      000B63 8D F0            [24] 2721 	mov	b, r5
      000B65 EC               [12] 2722 	mov	a, r4
      000B66 12 35 C2         [24] 2723 	lcall	___fslt
      000B69 E5 81            [12] 2724 	mov	a,sp
      000B6B 24 FC            [12] 2725 	add	a,#0xfc
      000B6D F5 81            [12] 2726 	mov	sp,a
      000B6F D0 04            [24] 2727 	pop	ar4
      000B71 D0 05            [24] 2728 	pop	ar5
      000B73 D0 06            [24] 2729 	pop	ar6
      000B75 D0 07            [24] 2730 	pop	ar7
      000B77 E5 82            [12] 2731 	mov	a, dpl
      000B79 24 FF            [12] 2732 	add	a,#0xff
      000B7B 92 00            [24] 2733 	mov	b0,c
      000B7D 40 39            [24] 2734 	jc	00107$
                           000AC8  2735 	C$fuzzy.h$1311$2_0$69 ==.
                                   2736 ;	../../fuzzy.h:1311: ramp_up
      000B7F E5 08            [12] 2737 	mov	a,_bp
      000B81 24 F5            [12] 2738 	add	a,#0xf5
      000B83 F8               [12] 2739 	mov	r0,a
      000B84 E6               [12] 2740 	mov	a,@r0
      000B85 60 0F            [24] 2741 	jz	00111$
                           000AD0  2742 	C$fuzzy.h$1312$2_0$69 ==.
                                   2743 ;	../../fuzzy.h:1312: ? LEVEL_LO
      000B87 E5 08            [12] 2744 	mov	a,_bp
      000B89 24 05            [12] 2745 	add	a,#0x05
      000B8B F8               [12] 2746 	mov	r0,a
      000B8C E4               [12] 2747 	clr	a
      000B8D F6               [12] 2748 	mov	@r0,a
      000B8E 08               [12] 2749 	inc	r0
      000B8F F6               [12] 2750 	mov	@r0,a
      000B90 08               [12] 2751 	inc	r0
      000B91 F6               [12] 2752 	mov	@r0,a
      000B92 08               [12] 2753 	inc	r0
      000B93 F6               [12] 2754 	mov	@r0,a
      000B94 80 0F            [24] 2755 	sjmp	00112$
      000B96                       2756 00111$:
                           000ADF  2757 	C$fuzzy.h$1313$2_0$69 ==.
                                   2758 ;	../../fuzzy.h:1313: : LEVEL_HI;
      000B96 E5 08            [12] 2759 	mov	a,_bp
      000B98 24 05            [12] 2760 	add	a,#0x05
      000B9A F8               [12] 2761 	mov	r0,a
      000B9B E4               [12] 2762 	clr	a
      000B9C F6               [12] 2763 	mov	@r0,a
      000B9D 08               [12] 2764 	inc	r0
      000B9E F6               [12] 2765 	mov	@r0,a
      000B9F 08               [12] 2766 	inc	r0
      000BA0 76 80            [12] 2767 	mov	@r0,#0x80
      000BA2 08               [12] 2768 	inc	r0
      000BA3 76 3F            [12] 2769 	mov	@r0,#0x3f
      000BA5                       2770 00112$:
      000BA5 E5 08            [12] 2771 	mov	a,_bp
      000BA7 24 05            [12] 2772 	add	a,#0x05
      000BA9 F8               [12] 2773 	mov	r0,a
      000BAA 86 07            [24] 2774 	mov	ar7,@r0
      000BAC 08               [12] 2775 	inc	r0
      000BAD 86 06            [24] 2776 	mov	ar6,@r0
      000BAF 08               [12] 2777 	inc	r0
      000BB0 86 05            [24] 2778 	mov	ar5,@r0
      000BB2 08               [12] 2779 	inc	r0
      000BB3 86 04            [24] 2780 	mov	ar4,@r0
      000BB5 02 0D 01         [24] 2781 	ljmp	00108$
      000BB8                       2782 00107$:
                           000B01  2783 	C$fuzzy.h$1315$1_0$67 ==.
                                   2784 ;	../../fuzzy.h:1315: else if (value >= upper_boundary) {
      000BB8 C0 07            [24] 2785 	push	ar7
      000BBA C0 06            [24] 2786 	push	ar6
      000BBC C0 05            [24] 2787 	push	ar5
      000BBE C0 04            [24] 2788 	push	ar4
      000BC0 E5 08            [12] 2789 	mov	a,_bp
      000BC2 24 FA            [12] 2790 	add	a,#0xfa
      000BC4 F8               [12] 2791 	mov	r0,a
      000BC5 E6               [12] 2792 	mov	a,@r0
      000BC6 C0 E0            [24] 2793 	push	acc
      000BC8 08               [12] 2794 	inc	r0
      000BC9 E6               [12] 2795 	mov	a,@r0
      000BCA C0 E0            [24] 2796 	push	acc
      000BCC 08               [12] 2797 	inc	r0
      000BCD E6               [12] 2798 	mov	a,@r0
      000BCE C0 E0            [24] 2799 	push	acc
      000BD0 08               [12] 2800 	inc	r0
      000BD1 E6               [12] 2801 	mov	a,@r0
      000BD2 C0 E0            [24] 2802 	push	acc
      000BD4 E5 08            [12] 2803 	mov	a,_bp
      000BD6 24 F6            [12] 2804 	add	a,#0xf6
      000BD8 F8               [12] 2805 	mov	r0,a
      000BD9 86 82            [24] 2806 	mov	dpl, @r0
      000BDB 08               [12] 2807 	inc	r0
      000BDC 86 83            [24] 2808 	mov	dph, @r0
      000BDE 08               [12] 2809 	inc	r0
      000BDF 86 F0            [24] 2810 	mov	b, @r0
      000BE1 08               [12] 2811 	inc	r0
      000BE2 E6               [12] 2812 	mov	a, @r0
      000BE3 12 35 C2         [24] 2813 	lcall	___fslt
      000BE6 E5 81            [12] 2814 	mov	a,sp
      000BE8 24 FC            [12] 2815 	add	a,#0xfc
      000BEA F5 81            [12] 2816 	mov	sp,a
      000BEC D0 04            [24] 2817 	pop	ar4
      000BEE D0 05            [24] 2818 	pop	ar5
      000BF0 D0 06            [24] 2819 	pop	ar6
      000BF2 D0 07            [24] 2820 	pop	ar7
      000BF4 E5 82            [12] 2821 	mov	a, dpl
      000BF6 24 FF            [12] 2822 	add	a,#0xff
      000BF8 92 00            [24] 2823 	mov	b0,c
      000BFA 40 39            [24] 2824 	jc	00104$
                           000B45  2825 	C$fuzzy.h$1317$2_0$70 ==.
                                   2826 ;	../../fuzzy.h:1317: ramp_up
      000BFC E5 08            [12] 2827 	mov	a,_bp
      000BFE 24 F5            [12] 2828 	add	a,#0xf5
      000C00 F8               [12] 2829 	mov	r0,a
      000C01 E6               [12] 2830 	mov	a,@r0
      000C02 60 11            [24] 2831 	jz	00113$
                           000B4D  2832 	C$fuzzy.h$1318$2_0$70 ==.
                                   2833 ;	../../fuzzy.h:1318: ? LEVEL_HI
      000C04 E5 08            [12] 2834 	mov	a,_bp
      000C06 24 05            [12] 2835 	add	a,#0x05
      000C08 F8               [12] 2836 	mov	r0,a
      000C09 E4               [12] 2837 	clr	a
      000C0A F6               [12] 2838 	mov	@r0,a
      000C0B 08               [12] 2839 	inc	r0
      000C0C F6               [12] 2840 	mov	@r0,a
      000C0D 08               [12] 2841 	inc	r0
      000C0E 76 80            [12] 2842 	mov	@r0,#0x80
      000C10 08               [12] 2843 	inc	r0
      000C11 76 3F            [12] 2844 	mov	@r0,#0x3f
      000C13 80 0D            [24] 2845 	sjmp	00114$
      000C15                       2846 00113$:
                           000B5E  2847 	C$fuzzy.h$1319$2_0$70 ==.
                                   2848 ;	../../fuzzy.h:1319: : LEVEL_LO;
      000C15 E5 08            [12] 2849 	mov	a,_bp
      000C17 24 05            [12] 2850 	add	a,#0x05
      000C19 F8               [12] 2851 	mov	r0,a
      000C1A E4               [12] 2852 	clr	a
      000C1B F6               [12] 2853 	mov	@r0,a
      000C1C 08               [12] 2854 	inc	r0
      000C1D F6               [12] 2855 	mov	@r0,a
      000C1E 08               [12] 2856 	inc	r0
      000C1F F6               [12] 2857 	mov	@r0,a
      000C20 08               [12] 2858 	inc	r0
      000C21 F6               [12] 2859 	mov	@r0,a
      000C22                       2860 00114$:
      000C22 E5 08            [12] 2861 	mov	a,_bp
      000C24 24 05            [12] 2862 	add	a,#0x05
      000C26 F8               [12] 2863 	mov	r0,a
      000C27 86 07            [24] 2864 	mov	ar7,@r0
      000C29 08               [12] 2865 	inc	r0
      000C2A 86 06            [24] 2866 	mov	ar6,@r0
      000C2C 08               [12] 2867 	inc	r0
      000C2D 86 05            [24] 2868 	mov	ar5,@r0
      000C2F 08               [12] 2869 	inc	r0
      000C30 86 04            [24] 2870 	mov	ar4,@r0
      000C32 02 0D 01         [24] 2871 	ljmp	00108$
      000C35                       2872 00104$:
                           000B7E  2873 	C$fuzzy.h$1323$1_0$67 ==.
                                   2874 ;	../../fuzzy.h:1323: (value - lower_boundary) /
      000C35 C0 07            [24] 2875 	push	ar7
      000C37 C0 06            [24] 2876 	push	ar6
      000C39 C0 05            [24] 2877 	push	ar5
      000C3B C0 04            [24] 2878 	push	ar4
      000C3D C0 07            [24] 2879 	push	ar7
      000C3F C0 06            [24] 2880 	push	ar6
      000C41 C0 05            [24] 2881 	push	ar5
      000C43 C0 04            [24] 2882 	push	ar4
                           000B8E  2883 	C$fuzzy.h$1324$1_0$67 ==.
                                   2884 ;	../../fuzzy.h:1324: (upper_boundary - lower_boundary);
      000C45 E5 08            [12] 2885 	mov	a,_bp
      000C47 24 F6            [12] 2886 	add	a,#0xf6
      000C49 F8               [12] 2887 	mov	r0,a
      000C4A 86 82            [24] 2888 	mov	dpl, @r0
      000C4C 08               [12] 2889 	inc	r0
      000C4D 86 83            [24] 2890 	mov	dph, @r0
      000C4F 08               [12] 2891 	inc	r0
      000C50 86 F0            [24] 2892 	mov	b, @r0
      000C52 08               [12] 2893 	inc	r0
      000C53 E6               [12] 2894 	mov	a, @r0
      000C54 12 34 87         [24] 2895 	lcall	___fssub
      000C57 A8 08            [24] 2896 	mov	r0,_bp
      000C59 08               [12] 2897 	inc	r0
      000C5A A6 82            [24] 2898 	mov	@r0, dpl
      000C5C 08               [12] 2899 	inc	r0
      000C5D A6 83            [24] 2900 	mov	@r0, dph
      000C5F 08               [12] 2901 	inc	r0
      000C60 A6 F0            [24] 2902 	mov	@r0, b
      000C62 08               [12] 2903 	inc	r0
      000C63 F6               [12] 2904 	mov	@r0,a
      000C64 E5 81            [12] 2905 	mov	a,sp
      000C66 24 FC            [12] 2906 	add	a,#0xfc
      000C68 F5 81            [12] 2907 	mov	sp,a
      000C6A E5 08            [12] 2908 	mov	a,_bp
      000C6C 24 FA            [12] 2909 	add	a,#0xfa
      000C6E F8               [12] 2910 	mov	r0,a
      000C6F 86 82            [24] 2911 	mov	dpl, @r0
      000C71 08               [12] 2912 	inc	r0
      000C72 86 83            [24] 2913 	mov	dph, @r0
      000C74 08               [12] 2914 	inc	r0
      000C75 86 F0            [24] 2915 	mov	b, @r0
      000C77 08               [12] 2916 	inc	r0
      000C78 E6               [12] 2917 	mov	a, @r0
      000C79 12 34 87         [24] 2918 	lcall	___fssub
      000C7C AC 82            [24] 2919 	mov	r4, dpl
      000C7E AD 83            [24] 2920 	mov	r5, dph
      000C80 AE F0            [24] 2921 	mov	r6, b
      000C82 FF               [12] 2922 	mov	r7, a
      000C83 E5 81            [12] 2923 	mov	a,sp
      000C85 24 FC            [12] 2924 	add	a,#0xfc
      000C87 F5 81            [12] 2925 	mov	sp,a
      000C89 C0 04            [24] 2926 	push	ar4
      000C8B C0 05            [24] 2927 	push	ar5
      000C8D C0 06            [24] 2928 	push	ar6
      000C8F C0 07            [24] 2929 	push	ar7
                           000BDA  2930 	C$fuzzy.h$1327$1_0$67 ==.
                                   2931 ;	../../fuzzy.h:1327: ramp_up
      000C91 A8 08            [24] 2932 	mov	r0,_bp
      000C93 08               [12] 2933 	inc	r0
      000C94 86 82            [24] 2934 	mov	dpl, @r0
      000C96 08               [12] 2935 	inc	r0
      000C97 86 83            [24] 2936 	mov	dph, @r0
      000C99 08               [12] 2937 	inc	r0
      000C9A 86 F0            [24] 2938 	mov	b, @r0
      000C9C 08               [12] 2939 	inc	r0
      000C9D E6               [12] 2940 	mov	a, @r0
      000C9E 12 37 2B         [24] 2941 	lcall	___fsdiv
      000CA1 AC 82            [24] 2942 	mov	r4, dpl
      000CA3 AD 83            [24] 2943 	mov	r5, dph
      000CA5 AE F0            [24] 2944 	mov	r6, b
      000CA7 FF               [12] 2945 	mov	r7, a
      000CA8 E5 81            [12] 2946 	mov	a,sp
      000CAA 24 FC            [12] 2947 	add	a,#0xfc
      000CAC F5 81            [12] 2948 	mov	sp,a
      000CAE E5 08            [12] 2949 	mov	a,_bp
      000CB0 24 F5            [12] 2950 	add	a,#0xf5
      000CB2 F8               [12] 2951 	mov	r0,a
      000CB3 E6               [12] 2952 	mov	a,@r0
      000CB4 60 12            [24] 2953 	jz	00115$
                           000BFF  2954 	C$fuzzy.h$1328$2_0$71 ==.
                                   2955 ;	../../fuzzy.h:1328: ? normalized
      000CB6 E5 08            [12] 2956 	mov	a,_bp
      000CB8 24 05            [12] 2957 	add	a,#0x05
      000CBA F8               [12] 2958 	mov	r0,a
      000CBB A6 04            [24] 2959 	mov	@r0,ar4
      000CBD 08               [12] 2960 	inc	r0
      000CBE A6 05            [24] 2961 	mov	@r0,ar5
      000CC0 08               [12] 2962 	inc	r0
      000CC1 A6 06            [24] 2963 	mov	@r0,ar6
      000CC3 08               [12] 2964 	inc	r0
      000CC4 A6 07            [24] 2965 	mov	@r0,ar7
      000CC6 80 29            [24] 2966 	sjmp	00116$
      000CC8                       2967 00115$:
                           000C11  2968 	C$fuzzy.h$1329$1_0$67 ==.
                                   2969 ;	../../fuzzy.h:1329: : LEVEL_HI - normalized;
      000CC8 C0 04            [24] 2970 	push	ar4
      000CCA C0 05            [24] 2971 	push	ar5
      000CCC C0 06            [24] 2972 	push	ar6
      000CCE C0 07            [24] 2973 	push	ar7
      000CD0 90 00 00         [24] 2974 	mov	dptr,#0x0000
      000CD3 75 F0 80         [24] 2975 	mov	b, #0x80
      000CD6 74 3F            [12] 2976 	mov	a, #0x3f
      000CD8 12 34 87         [24] 2977 	lcall	___fssub
      000CDB C8               [12] 2978 	xch	a,r0
      000CDC E5 08            [12] 2979 	mov	a,_bp
      000CDE 24 05            [12] 2980 	add	a,#0x05
      000CE0 C8               [12] 2981 	xch	a,r0
      000CE1 A6 82            [24] 2982 	mov	@r0, dpl
      000CE3 08               [12] 2983 	inc	r0
      000CE4 A6 83            [24] 2984 	mov	@r0, dph
      000CE6 08               [12] 2985 	inc	r0
      000CE7 A6 F0            [24] 2986 	mov	@r0, b
      000CE9 08               [12] 2987 	inc	r0
      000CEA F6               [12] 2988 	mov	@r0,a
      000CEB E5 81            [12] 2989 	mov	a,sp
      000CED 24 FC            [12] 2990 	add	a,#0xfc
      000CEF F5 81            [12] 2991 	mov	sp,a
      000CF1                       2992 00116$:
      000CF1 E5 08            [12] 2993 	mov	a,_bp
      000CF3 24 05            [12] 2994 	add	a,#0x05
      000CF5 F8               [12] 2995 	mov	r0,a
      000CF6 86 07            [24] 2996 	mov	ar7,@r0
      000CF8 08               [12] 2997 	inc	r0
      000CF9 86 06            [24] 2998 	mov	ar6,@r0
      000CFB 08               [12] 2999 	inc	r0
      000CFC 86 05            [24] 3000 	mov	ar5,@r0
      000CFE 08               [12] 3001 	inc	r0
      000CFF 86 04            [24] 3002 	mov	ar4,@r0
      000D01                       3003 00108$:
                           000C4A  3004 	C$fuzzy.h$1333$1_0$67 ==.
                                   3005 ;	../../fuzzy.h:1333: result,
      000D01 E5 08            [12] 3006 	mov	a,_bp
      000D03 24 F4            [12] 3007 	add	a,#0xf4
      000D05 F8               [12] 3008 	mov	r0,a
      000D06 E6               [12] 3009 	mov	a,@r0
      000D07 C0 E0            [24] 3010 	push	acc
      000D09 8F 82            [24] 3011 	mov	dpl, r7
      000D0B 8E 83            [24] 3012 	mov	dph, r6
      000D0D 8D F0            [24] 3013 	mov	b, r5
      000D0F EC               [12] 3014 	mov	a, r4
      000D10 12 01 99         [24] 3015 	lcall	_fuzzy_apply_hedge
      000D13 AC 82            [24] 3016 	mov	r4, dpl
      000D15 AD 83            [24] 3017 	mov	r5, dph
      000D17 AE F0            [24] 3018 	mov	r6, b
      000D19 FF               [12] 3019 	mov	r7, a
      000D1A 15 81            [12] 3020 	dec	sp
      000D1C 8C 82            [24] 3021 	mov	dpl, r4
      000D1E 8D 83            [24] 3022 	mov	dph, r5
      000D20 8E F0            [24] 3023 	mov	b, r6
      000D22 EF               [12] 3024 	mov	a, r7
      000D23                       3025 00109$:
                           000C6C  3026 	C$fuzzy.h$1336$1_0$67 ==.
                                   3027 ;	../../fuzzy.h:1336: }
      000D23 85 08 81         [24] 3028 	mov	sp,_bp
      000D26 D0 08            [24] 3029 	pop	_bp
                           000C71  3030 	C$fuzzy.h$1336$1_0$67 ==.
                           000C71  3031 	XG$fuzzy_ramp$0$0 ==.
      000D28 22               [24] 3032 	ret
                                   3033 ;------------------------------------------------------------
                                   3034 ;Allocation info for local variables in function 'fuzzy_triangle'
                                   3035 ;------------------------------------------------------------
                                   3036 ;b             Allocated to stack - _bp -6 +4 
                                   3037 ;c             Allocated to stack - _bp -10 +4 
                                   3038 ;value         Allocated to stack - _bp -14 +4 
                                   3039 ;hedge         Allocated to stack - _bp -15 +1 
                                   3040 ;a             Allocated to registers r7 r6 r5 r4 
                                   3041 ;result        Allocated to stack - _bp +1 +4 
                                   3042 ;sloc0         Allocated to stack - _bp +1 +4 
                                   3043 ;sloc1         Allocated to stack - _bp +5 +4 
                                   3044 ;------------------------------------------------------------
                           000C72  3045 	G$fuzzy_triangle$0$0 ==.
                           000C72  3046 	C$fuzzy.h$1380$1_0$73 ==.
                                   3047 ;	../../fuzzy.h:1380: float fuzzy_triangle(
                                   3048 ;	-----------------------------------------
                                   3049 ;	 function fuzzy_triangle
                                   3050 ;	-----------------------------------------
      000D29                       3051 _fuzzy_triangle:
      000D29 C0 08            [24] 3052 	push	_bp
      000D2B 85 81 08         [24] 3053 	mov	_bp,sp
      000D2E AF 82            [24] 3054 	mov	r7,dpl
      000D30 AE 83            [24] 3055 	mov	r6,dph
      000D32 AD F0            [24] 3056 	mov	r5,b
      000D34 FC               [12] 3057 	mov	r4,a
      000D35 E5 81            [12] 3058 	mov	a,sp
      000D37 24 08            [12] 3059 	add	a,#0x08
      000D39 F5 81            [12] 3060 	mov	sp,a
                           000C84  3061 	C$fuzzy.h$1391$1_0$73 ==.
                                   3062 ;	../../fuzzy.h:1391: a >= b ||
      000D3B C0 07            [24] 3063 	push	ar7
      000D3D C0 06            [24] 3064 	push	ar6
      000D3F C0 05            [24] 3065 	push	ar5
      000D41 C0 04            [24] 3066 	push	ar4
      000D43 E5 08            [12] 3067 	mov	a,_bp
      000D45 24 FA            [12] 3068 	add	a,#0xfa
      000D47 F8               [12] 3069 	mov	r0,a
      000D48 E6               [12] 3070 	mov	a,@r0
      000D49 C0 E0            [24] 3071 	push	acc
      000D4B 08               [12] 3072 	inc	r0
      000D4C E6               [12] 3073 	mov	a,@r0
      000D4D C0 E0            [24] 3074 	push	acc
      000D4F 08               [12] 3075 	inc	r0
      000D50 E6               [12] 3076 	mov	a,@r0
      000D51 C0 E0            [24] 3077 	push	acc
      000D53 08               [12] 3078 	inc	r0
      000D54 E6               [12] 3079 	mov	a,@r0
      000D55 C0 E0            [24] 3080 	push	acc
      000D57 8F 82            [24] 3081 	mov	dpl, r7
      000D59 8E 83            [24] 3082 	mov	dph, r6
      000D5B 8D F0            [24] 3083 	mov	b, r5
      000D5D EC               [12] 3084 	mov	a, r4
      000D5E 12 35 C2         [24] 3085 	lcall	___fslt
      000D61 E5 81            [12] 3086 	mov	a,sp
      000D63 24 FC            [12] 3087 	add	a,#0xfc
      000D65 F5 81            [12] 3088 	mov	sp,a
      000D67 D0 04            [24] 3089 	pop	ar4
      000D69 D0 05            [24] 3090 	pop	ar5
      000D6B D0 06            [24] 3091 	pop	ar6
      000D6D D0 07            [24] 3092 	pop	ar7
      000D6F E5 82            [12] 3093 	mov	a, dpl
      000D71 24 FF            [12] 3094 	add	a,#0xff
      000D73 92 00            [24] 3095 	mov	b0,c
      000D75 40 03            [24] 3096 	jc	00145$
      000D77 02 0E 41         [24] 3097 	ljmp	00107$
      000D7A                       3098 00145$:
                           000CC3  3099 	C$fuzzy.h$1392$1_0$73 ==.
                                   3100 ;	../../fuzzy.h:1392: b >= c ||
      000D7A C0 07            [24] 3101 	push	ar7
      000D7C C0 06            [24] 3102 	push	ar6
      000D7E C0 05            [24] 3103 	push	ar5
      000D80 C0 04            [24] 3104 	push	ar4
      000D82 E5 08            [12] 3105 	mov	a,_bp
      000D84 24 F6            [12] 3106 	add	a,#0xf6
      000D86 F8               [12] 3107 	mov	r0,a
      000D87 E6               [12] 3108 	mov	a,@r0
      000D88 C0 E0            [24] 3109 	push	acc
      000D8A 08               [12] 3110 	inc	r0
      000D8B E6               [12] 3111 	mov	a,@r0
      000D8C C0 E0            [24] 3112 	push	acc
      000D8E 08               [12] 3113 	inc	r0
      000D8F E6               [12] 3114 	mov	a,@r0
      000D90 C0 E0            [24] 3115 	push	acc
      000D92 08               [12] 3116 	inc	r0
      000D93 E6               [12] 3117 	mov	a,@r0
      000D94 C0 E0            [24] 3118 	push	acc
      000D96 E5 08            [12] 3119 	mov	a,_bp
      000D98 24 FA            [12] 3120 	add	a,#0xfa
      000D9A F8               [12] 3121 	mov	r0,a
      000D9B 86 82            [24] 3122 	mov	dpl, @r0
      000D9D 08               [12] 3123 	inc	r0
      000D9E 86 83            [24] 3124 	mov	dph, @r0
      000DA0 08               [12] 3125 	inc	r0
      000DA1 86 F0            [24] 3126 	mov	b, @r0
      000DA3 08               [12] 3127 	inc	r0
      000DA4 E6               [12] 3128 	mov	a, @r0
      000DA5 12 35 C2         [24] 3129 	lcall	___fslt
      000DA8 E5 81            [12] 3130 	mov	a,sp
      000DAA 24 FC            [12] 3131 	add	a,#0xfc
      000DAC F5 81            [12] 3132 	mov	sp,a
      000DAE D0 04            [24] 3133 	pop	ar4
      000DB0 D0 05            [24] 3134 	pop	ar5
      000DB2 D0 06            [24] 3135 	pop	ar6
      000DB4 D0 07            [24] 3136 	pop	ar7
      000DB6 E5 82            [12] 3137 	mov	a, dpl
      000DB8 24 FF            [12] 3138 	add	a,#0xff
      000DBA 92 00            [24] 3139 	mov	b0,c
      000DBC 40 03            [24] 3140 	jc	00146$
      000DBE 02 0E 41         [24] 3141 	ljmp	00107$
      000DC1                       3142 00146$:
                           000D0A  3143 	C$fuzzy.h$1393$1_0$73 ==.
                                   3144 ;	../../fuzzy.h:1393: value <= a ||
      000DC1 C0 07            [24] 3145 	push	ar7
      000DC3 C0 06            [24] 3146 	push	ar6
      000DC5 C0 05            [24] 3147 	push	ar5
      000DC7 C0 04            [24] 3148 	push	ar4
      000DC9 E5 08            [12] 3149 	mov	a,_bp
      000DCB 24 F2            [12] 3150 	add	a,#0xf2
      000DCD F8               [12] 3151 	mov	r0,a
      000DCE E6               [12] 3152 	mov	a,@r0
      000DCF C0 E0            [24] 3153 	push	acc
      000DD1 08               [12] 3154 	inc	r0
      000DD2 E6               [12] 3155 	mov	a,@r0
      000DD3 C0 E0            [24] 3156 	push	acc
      000DD5 08               [12] 3157 	inc	r0
      000DD6 E6               [12] 3158 	mov	a,@r0
      000DD7 C0 E0            [24] 3159 	push	acc
      000DD9 08               [12] 3160 	inc	r0
      000DDA E6               [12] 3161 	mov	a,@r0
      000DDB C0 E0            [24] 3162 	push	acc
      000DDD 8F 82            [24] 3163 	mov	dpl, r7
      000DDF 8E 83            [24] 3164 	mov	dph, r6
      000DE1 8D F0            [24] 3165 	mov	b, r5
      000DE3 EC               [12] 3166 	mov	a, r4
      000DE4 12 35 C2         [24] 3167 	lcall	___fslt
      000DE7 E5 81            [12] 3168 	mov	a,sp
      000DE9 24 FC            [12] 3169 	add	a,#0xfc
      000DEB F5 81            [12] 3170 	mov	sp,a
      000DED D0 04            [24] 3171 	pop	ar4
      000DEF D0 05            [24] 3172 	pop	ar5
      000DF1 D0 06            [24] 3173 	pop	ar6
      000DF3 D0 07            [24] 3174 	pop	ar7
      000DF5 E5 82            [12] 3175 	mov	a, dpl
      000DF7 24 FF            [12] 3176 	add	a,#0xff
      000DF9 92 00            [24] 3177 	mov	b0,c
      000DFB 50 44            [24] 3178 	jnc	00107$
                           000D46  3179 	C$fuzzy.h$1395$1_0$73 ==.
                                   3180 ;	../../fuzzy.h:1395: ) {
      000DFD C0 07            [24] 3181 	push	ar7
      000DFF C0 06            [24] 3182 	push	ar6
      000E01 C0 05            [24] 3183 	push	ar5
      000E03 C0 04            [24] 3184 	push	ar4
      000E05 E5 08            [12] 3185 	mov	a,_bp
      000E07 24 F6            [12] 3186 	add	a,#0xf6
      000E09 F8               [12] 3187 	mov	r0,a
      000E0A E6               [12] 3188 	mov	a,@r0
      000E0B C0 E0            [24] 3189 	push	acc
      000E0D 08               [12] 3190 	inc	r0
      000E0E E6               [12] 3191 	mov	a,@r0
      000E0F C0 E0            [24] 3192 	push	acc
      000E11 08               [12] 3193 	inc	r0
      000E12 E6               [12] 3194 	mov	a,@r0
      000E13 C0 E0            [24] 3195 	push	acc
      000E15 08               [12] 3196 	inc	r0
      000E16 E6               [12] 3197 	mov	a,@r0
      000E17 C0 E0            [24] 3198 	push	acc
      000E19 E5 08            [12] 3199 	mov	a,_bp
      000E1B 24 F2            [12] 3200 	add	a,#0xf2
      000E1D F8               [12] 3201 	mov	r0,a
      000E1E 86 82            [24] 3202 	mov	dpl, @r0
      000E20 08               [12] 3203 	inc	r0
      000E21 86 83            [24] 3204 	mov	dph, @r0
      000E23 08               [12] 3205 	inc	r0
      000E24 86 F0            [24] 3206 	mov	b, @r0
      000E26 08               [12] 3207 	inc	r0
      000E27 E6               [12] 3208 	mov	a, @r0
      000E28 12 35 C2         [24] 3209 	lcall	___fslt
      000E2B E5 81            [12] 3210 	mov	a,sp
      000E2D 24 FC            [12] 3211 	add	a,#0xfc
      000E2F F5 81            [12] 3212 	mov	sp,a
      000E31 D0 04            [24] 3213 	pop	ar4
      000E33 D0 05            [24] 3214 	pop	ar5
      000E35 D0 06            [24] 3215 	pop	ar6
      000E37 D0 07            [24] 3216 	pop	ar7
      000E39 E5 82            [12] 3217 	mov	a, dpl
      000E3B 24 FF            [12] 3218 	add	a,#0xff
      000E3D 92 00            [24] 3219 	mov	b0,c
      000E3F 40 0E            [24] 3220 	jc	00108$
      000E41                       3221 00107$:
                           000D8A  3222 	C$fuzzy.h$1396$2_0$74 ==.
                                   3223 ;	../../fuzzy.h:1396: result = LEVEL_LO;
      000E41 A8 08            [24] 3224 	mov	r0,_bp
      000E43 08               [12] 3225 	inc	r0
      000E44 E4               [12] 3226 	clr	a
      000E45 F6               [12] 3227 	mov	@r0,a
      000E46 08               [12] 3228 	inc	r0
      000E47 F6               [12] 3229 	mov	@r0,a
      000E48 08               [12] 3230 	inc	r0
      000E49 F6               [12] 3231 	mov	@r0,a
      000E4A 08               [12] 3232 	inc	r0
      000E4B F6               [12] 3233 	mov	@r0,a
      000E4C 02 10 07         [24] 3234 	ljmp	00109$
      000E4F                       3235 00108$:
                           000D98  3236 	C$fuzzy.h$1398$1_0$73 ==.
                                   3237 ;	../../fuzzy.h:1398: else if (value == b) {
      000E4F C0 07            [24] 3238 	push	ar7
      000E51 C0 06            [24] 3239 	push	ar6
      000E53 C0 05            [24] 3240 	push	ar5
      000E55 C0 04            [24] 3241 	push	ar4
      000E57 E5 08            [12] 3242 	mov	a,_bp
      000E59 24 FA            [12] 3243 	add	a,#0xfa
      000E5B F8               [12] 3244 	mov	r0,a
      000E5C E6               [12] 3245 	mov	a,@r0
      000E5D C0 E0            [24] 3246 	push	acc
      000E5F 08               [12] 3247 	inc	r0
      000E60 E6               [12] 3248 	mov	a,@r0
      000E61 C0 E0            [24] 3249 	push	acc
      000E63 08               [12] 3250 	inc	r0
      000E64 E6               [12] 3251 	mov	a,@r0
      000E65 C0 E0            [24] 3252 	push	acc
      000E67 08               [12] 3253 	inc	r0
      000E68 E6               [12] 3254 	mov	a,@r0
      000E69 C0 E0            [24] 3255 	push	acc
      000E6B E5 08            [12] 3256 	mov	a,_bp
      000E6D 24 F2            [12] 3257 	add	a,#0xf2
      000E6F F8               [12] 3258 	mov	r0,a
      000E70 86 82            [24] 3259 	mov	dpl, @r0
      000E72 08               [12] 3260 	inc	r0
      000E73 86 83            [24] 3261 	mov	dph, @r0
      000E75 08               [12] 3262 	inc	r0
      000E76 86 F0            [24] 3263 	mov	b, @r0
      000E78 08               [12] 3264 	inc	r0
      000E79 E6               [12] 3265 	mov	a, @r0
      000E7A 12 35 96         [24] 3266 	lcall	___fseq
      000E7D AB 82            [24] 3267 	mov	r3, dpl
      000E7F E5 81            [12] 3268 	mov	a,sp
      000E81 24 FC            [12] 3269 	add	a,#0xfc
      000E83 F5 81            [12] 3270 	mov	sp,a
      000E85 D0 04            [24] 3271 	pop	ar4
      000E87 D0 05            [24] 3272 	pop	ar5
      000E89 D0 06            [24] 3273 	pop	ar6
      000E8B D0 07            [24] 3274 	pop	ar7
      000E8D EB               [12] 3275 	mov	a,r3
      000E8E 60 10            [24] 3276 	jz	00105$
                           000DD9  3277 	C$fuzzy.h$1399$2_0$75 ==.
                                   3278 ;	../../fuzzy.h:1399: result = LEVEL_HI;
      000E90 A8 08            [24] 3279 	mov	r0,_bp
      000E92 08               [12] 3280 	inc	r0
      000E93 E4               [12] 3281 	clr	a
      000E94 F6               [12] 3282 	mov	@r0,a
      000E95 08               [12] 3283 	inc	r0
      000E96 F6               [12] 3284 	mov	@r0,a
      000E97 08               [12] 3285 	inc	r0
      000E98 76 80            [12] 3286 	mov	@r0,#0x80
      000E9A 08               [12] 3287 	inc	r0
      000E9B 76 3F            [12] 3288 	mov	@r0,#0x3f
      000E9D 02 10 07         [24] 3289 	ljmp	00109$
      000EA0                       3290 00105$:
                           000DE9  3291 	C$fuzzy.h$1401$1_0$73 ==.
                                   3292 ;	../../fuzzy.h:1401: else if (value < b) {
      000EA0 C0 07            [24] 3293 	push	ar7
      000EA2 C0 06            [24] 3294 	push	ar6
      000EA4 C0 05            [24] 3295 	push	ar5
      000EA6 C0 04            [24] 3296 	push	ar4
      000EA8 E5 08            [12] 3297 	mov	a,_bp
      000EAA 24 FA            [12] 3298 	add	a,#0xfa
      000EAC F8               [12] 3299 	mov	r0,a
      000EAD E6               [12] 3300 	mov	a,@r0
      000EAE C0 E0            [24] 3301 	push	acc
      000EB0 08               [12] 3302 	inc	r0
      000EB1 E6               [12] 3303 	mov	a,@r0
      000EB2 C0 E0            [24] 3304 	push	acc
      000EB4 08               [12] 3305 	inc	r0
      000EB5 E6               [12] 3306 	mov	a,@r0
      000EB6 C0 E0            [24] 3307 	push	acc
      000EB8 08               [12] 3308 	inc	r0
      000EB9 E6               [12] 3309 	mov	a,@r0
      000EBA C0 E0            [24] 3310 	push	acc
      000EBC E5 08            [12] 3311 	mov	a,_bp
      000EBE 24 F2            [12] 3312 	add	a,#0xf2
      000EC0 F8               [12] 3313 	mov	r0,a
      000EC1 86 82            [24] 3314 	mov	dpl, @r0
      000EC3 08               [12] 3315 	inc	r0
      000EC4 86 83            [24] 3316 	mov	dph, @r0
      000EC6 08               [12] 3317 	inc	r0
      000EC7 86 F0            [24] 3318 	mov	b, @r0
      000EC9 08               [12] 3319 	inc	r0
      000ECA E6               [12] 3320 	mov	a, @r0
      000ECB 12 35 C2         [24] 3321 	lcall	___fslt
      000ECE AB 82            [24] 3322 	mov	r3, dpl
      000ED0 E5 81            [12] 3323 	mov	a,sp
      000ED2 24 FC            [12] 3324 	add	a,#0xfc
      000ED4 F5 81            [12] 3325 	mov	sp,a
      000ED6 D0 04            [24] 3326 	pop	ar4
      000ED8 D0 05            [24] 3327 	pop	ar5
      000EDA D0 06            [24] 3328 	pop	ar6
      000EDC D0 07            [24] 3329 	pop	ar7
      000EDE EB               [12] 3330 	mov	a,r3
      000EDF 70 03            [24] 3331 	jnz	00150$
      000EE1 02 0F 6B         [24] 3332 	ljmp	00102$
      000EE4                       3333 00150$:
                           000E2D  3334 	C$fuzzy.h$1403$1_0$73 ==.
                                   3335 ;	../../fuzzy.h:1403: (value - a) /
      000EE4 C0 07            [24] 3336 	push	ar7
      000EE6 C0 06            [24] 3337 	push	ar6
      000EE8 C0 05            [24] 3338 	push	ar5
      000EEA C0 04            [24] 3339 	push	ar4
      000EEC C0 07            [24] 3340 	push	ar7
      000EEE C0 06            [24] 3341 	push	ar6
      000EF0 C0 05            [24] 3342 	push	ar5
      000EF2 C0 04            [24] 3343 	push	ar4
                           000E3D  3344 	C$fuzzy.h$1404$1_0$73 ==.
                                   3345 ;	../../fuzzy.h:1404: (b - a);
      000EF4 E5 08            [12] 3346 	mov	a,_bp
      000EF6 24 F2            [12] 3347 	add	a,#0xf2
      000EF8 F8               [12] 3348 	mov	r0,a
      000EF9 86 82            [24] 3349 	mov	dpl, @r0
      000EFB 08               [12] 3350 	inc	r0
      000EFC 86 83            [24] 3351 	mov	dph, @r0
      000EFE 08               [12] 3352 	inc	r0
      000EFF 86 F0            [24] 3353 	mov	b, @r0
      000F01 08               [12] 3354 	inc	r0
      000F02 E6               [12] 3355 	mov	a, @r0
      000F03 12 34 87         [24] 3356 	lcall	___fssub
      000F06 C8               [12] 3357 	xch	a,r0
      000F07 E5 08            [12] 3358 	mov	a,_bp
      000F09 24 05            [12] 3359 	add	a,#0x05
      000F0B C8               [12] 3360 	xch	a,r0
      000F0C A6 82            [24] 3361 	mov	@r0, dpl
      000F0E 08               [12] 3362 	inc	r0
      000F0F A6 83            [24] 3363 	mov	@r0, dph
      000F11 08               [12] 3364 	inc	r0
      000F12 A6 F0            [24] 3365 	mov	@r0, b
      000F14 08               [12] 3366 	inc	r0
      000F15 F6               [12] 3367 	mov	@r0,a
      000F16 E5 81            [12] 3368 	mov	a,sp
      000F18 24 FC            [12] 3369 	add	a,#0xfc
      000F1A F5 81            [12] 3370 	mov	sp,a
      000F1C E5 08            [12] 3371 	mov	a,_bp
      000F1E 24 FA            [12] 3372 	add	a,#0xfa
      000F20 F8               [12] 3373 	mov	r0,a
      000F21 86 82            [24] 3374 	mov	dpl, @r0
      000F23 08               [12] 3375 	inc	r0
      000F24 86 83            [24] 3376 	mov	dph, @r0
      000F26 08               [12] 3377 	inc	r0
      000F27 86 F0            [24] 3378 	mov	b, @r0
      000F29 08               [12] 3379 	inc	r0
      000F2A E6               [12] 3380 	mov	a, @r0
      000F2B 12 34 87         [24] 3381 	lcall	___fssub
      000F2E AC 82            [24] 3382 	mov	r4, dpl
      000F30 AD 83            [24] 3383 	mov	r5, dph
      000F32 AE F0            [24] 3384 	mov	r6, b
      000F34 FF               [12] 3385 	mov	r7, a
      000F35 E5 81            [12] 3386 	mov	a,sp
      000F37 24 FC            [12] 3387 	add	a,#0xfc
      000F39 F5 81            [12] 3388 	mov	sp,a
      000F3B C0 04            [24] 3389 	push	ar4
      000F3D C0 05            [24] 3390 	push	ar5
      000F3F C0 06            [24] 3391 	push	ar6
      000F41 C0 07            [24] 3392 	push	ar7
      000F43 E5 08            [12] 3393 	mov	a,_bp
      000F45 24 05            [12] 3394 	add	a,#0x05
      000F47 F8               [12] 3395 	mov	r0,a
      000F48 86 82            [24] 3396 	mov	dpl, @r0
      000F4A 08               [12] 3397 	inc	r0
      000F4B 86 83            [24] 3398 	mov	dph, @r0
      000F4D 08               [12] 3399 	inc	r0
      000F4E 86 F0            [24] 3400 	mov	b, @r0
      000F50 08               [12] 3401 	inc	r0
      000F51 E6               [12] 3402 	mov	a, @r0
      000F52 12 37 2B         [24] 3403 	lcall	___fsdiv
      000F55 A8 08            [24] 3404 	mov	r0,_bp
      000F57 08               [12] 3405 	inc	r0
      000F58 A6 82            [24] 3406 	mov	@r0, dpl
      000F5A 08               [12] 3407 	inc	r0
      000F5B A6 83            [24] 3408 	mov	@r0, dph
      000F5D 08               [12] 3409 	inc	r0
      000F5E A6 F0            [24] 3410 	mov	@r0, b
      000F60 08               [12] 3411 	inc	r0
      000F61 F6               [12] 3412 	mov	@r0,a
      000F62 E5 81            [12] 3413 	mov	a,sp
      000F64 24 FC            [12] 3414 	add	a,#0xfc
      000F66 F5 81            [12] 3415 	mov	sp,a
      000F68 02 10 07         [24] 3416 	ljmp	00109$
      000F6B                       3417 00102$:
                           000EB4  3418 	C$fuzzy.h$1408$1_0$73 ==.
                                   3419 ;	../../fuzzy.h:1408: (c - value) /
      000F6B E5 08            [12] 3420 	mov	a,_bp
      000F6D 24 F2            [12] 3421 	add	a,#0xf2
      000F6F F8               [12] 3422 	mov	r0,a
      000F70 E6               [12] 3423 	mov	a,@r0
      000F71 C0 E0            [24] 3424 	push	acc
      000F73 08               [12] 3425 	inc	r0
      000F74 E6               [12] 3426 	mov	a,@r0
      000F75 C0 E0            [24] 3427 	push	acc
      000F77 08               [12] 3428 	inc	r0
      000F78 E6               [12] 3429 	mov	a,@r0
      000F79 C0 E0            [24] 3430 	push	acc
      000F7B 08               [12] 3431 	inc	r0
      000F7C E6               [12] 3432 	mov	a,@r0
      000F7D C0 E0            [24] 3433 	push	acc
                           000EC8  3434 	C$fuzzy.h$1409$1_0$73 ==.
                                   3435 ;	../../fuzzy.h:1409: (c - b);
      000F7F E5 08            [12] 3436 	mov	a,_bp
      000F81 24 F6            [12] 3437 	add	a,#0xf6
      000F83 F8               [12] 3438 	mov	r0,a
      000F84 86 82            [24] 3439 	mov	dpl, @r0
      000F86 08               [12] 3440 	inc	r0
      000F87 86 83            [24] 3441 	mov	dph, @r0
      000F89 08               [12] 3442 	inc	r0
      000F8A 86 F0            [24] 3443 	mov	b, @r0
      000F8C 08               [12] 3444 	inc	r0
      000F8D E6               [12] 3445 	mov	a, @r0
      000F8E 12 34 87         [24] 3446 	lcall	___fssub
      000F91 C8               [12] 3447 	xch	a,r0
      000F92 E5 08            [12] 3448 	mov	a,_bp
      000F94 24 05            [12] 3449 	add	a,#0x05
      000F96 C8               [12] 3450 	xch	a,r0
      000F97 A6 82            [24] 3451 	mov	@r0, dpl
      000F99 08               [12] 3452 	inc	r0
      000F9A A6 83            [24] 3453 	mov	@r0, dph
      000F9C 08               [12] 3454 	inc	r0
      000F9D A6 F0            [24] 3455 	mov	@r0, b
      000F9F 08               [12] 3456 	inc	r0
      000FA0 F6               [12] 3457 	mov	@r0,a
      000FA1 E5 81            [12] 3458 	mov	a,sp
      000FA3 24 FC            [12] 3459 	add	a,#0xfc
      000FA5 F5 81            [12] 3460 	mov	sp,a
      000FA7 E5 08            [12] 3461 	mov	a,_bp
      000FA9 24 FA            [12] 3462 	add	a,#0xfa
      000FAB F8               [12] 3463 	mov	r0,a
      000FAC E6               [12] 3464 	mov	a,@r0
      000FAD C0 E0            [24] 3465 	push	acc
      000FAF 08               [12] 3466 	inc	r0
      000FB0 E6               [12] 3467 	mov	a,@r0
      000FB1 C0 E0            [24] 3468 	push	acc
      000FB3 08               [12] 3469 	inc	r0
      000FB4 E6               [12] 3470 	mov	a,@r0
      000FB5 C0 E0            [24] 3471 	push	acc
      000FB7 08               [12] 3472 	inc	r0
      000FB8 E6               [12] 3473 	mov	a,@r0
      000FB9 C0 E0            [24] 3474 	push	acc
      000FBB E5 08            [12] 3475 	mov	a,_bp
      000FBD 24 F6            [12] 3476 	add	a,#0xf6
      000FBF F8               [12] 3477 	mov	r0,a
      000FC0 86 82            [24] 3478 	mov	dpl, @r0
      000FC2 08               [12] 3479 	inc	r0
      000FC3 86 83            [24] 3480 	mov	dph, @r0
      000FC5 08               [12] 3481 	inc	r0
      000FC6 86 F0            [24] 3482 	mov	b, @r0
      000FC8 08               [12] 3483 	inc	r0
      000FC9 E6               [12] 3484 	mov	a, @r0
      000FCA 12 34 87         [24] 3485 	lcall	___fssub
      000FCD AA 82            [24] 3486 	mov	r2, dpl
      000FCF AB 83            [24] 3487 	mov	r3, dph
      000FD1 AE F0            [24] 3488 	mov	r6, b
      000FD3 FF               [12] 3489 	mov	r7, a
      000FD4 E5 81            [12] 3490 	mov	a,sp
      000FD6 24 FC            [12] 3491 	add	a,#0xfc
      000FD8 F5 81            [12] 3492 	mov	sp,a
      000FDA C0 02            [24] 3493 	push	ar2
      000FDC C0 03            [24] 3494 	push	ar3
      000FDE C0 06            [24] 3495 	push	ar6
      000FE0 C0 07            [24] 3496 	push	ar7
      000FE2 E5 08            [12] 3497 	mov	a,_bp
      000FE4 24 05            [12] 3498 	add	a,#0x05
      000FE6 F8               [12] 3499 	mov	r0,a
      000FE7 86 82            [24] 3500 	mov	dpl, @r0
      000FE9 08               [12] 3501 	inc	r0
      000FEA 86 83            [24] 3502 	mov	dph, @r0
      000FEC 08               [12] 3503 	inc	r0
      000FED 86 F0            [24] 3504 	mov	b, @r0
      000FEF 08               [12] 3505 	inc	r0
      000FF0 E6               [12] 3506 	mov	a, @r0
      000FF1 12 37 2B         [24] 3507 	lcall	___fsdiv
      000FF4 A8 08            [24] 3508 	mov	r0,_bp
      000FF6 08               [12] 3509 	inc	r0
      000FF7 A6 82            [24] 3510 	mov	@r0, dpl
      000FF9 08               [12] 3511 	inc	r0
      000FFA A6 83            [24] 3512 	mov	@r0, dph
      000FFC 08               [12] 3513 	inc	r0
      000FFD A6 F0            [24] 3514 	mov	@r0, b
      000FFF 08               [12] 3515 	inc	r0
      001000 F6               [12] 3516 	mov	@r0,a
      001001 E5 81            [12] 3517 	mov	a,sp
      001003 24 FC            [12] 3518 	add	a,#0xfc
      001005 F5 81            [12] 3519 	mov	sp,a
      001007                       3520 00109$:
                           000F50  3521 	C$fuzzy.h$1413$1_0$73 ==.
                                   3522 ;	../../fuzzy.h:1413: result,
      001007 E5 08            [12] 3523 	mov	a,_bp
      001009 24 F1            [12] 3524 	add	a,#0xf1
      00100B F8               [12] 3525 	mov	r0,a
      00100C E6               [12] 3526 	mov	a,@r0
      00100D C0 E0            [24] 3527 	push	acc
      00100F A8 08            [24] 3528 	mov	r0,_bp
      001011 08               [12] 3529 	inc	r0
      001012 86 82            [24] 3530 	mov	dpl, @r0
      001014 08               [12] 3531 	inc	r0
      001015 86 83            [24] 3532 	mov	dph, @r0
      001017 08               [12] 3533 	inc	r0
      001018 86 F0            [24] 3534 	mov	b, @r0
      00101A 08               [12] 3535 	inc	r0
      00101B E6               [12] 3536 	mov	a, @r0
      00101C 12 01 99         [24] 3537 	lcall	_fuzzy_apply_hedge
      00101F AC 82            [24] 3538 	mov	r4, dpl
      001021 AD 83            [24] 3539 	mov	r5, dph
      001023 AE F0            [24] 3540 	mov	r6, b
      001025 FF               [12] 3541 	mov	r7, a
      001026 15 81            [12] 3542 	dec	sp
      001028 8C 82            [24] 3543 	mov	dpl, r4
      00102A 8D 83            [24] 3544 	mov	dph, r5
      00102C 8E F0            [24] 3545 	mov	b, r6
      00102E EF               [12] 3546 	mov	a, r7
                           000F78  3547 	C$fuzzy.h$1416$1_0$73 ==.
                                   3548 ;	../../fuzzy.h:1416: }
      00102F 85 08 81         [24] 3549 	mov	sp,_bp
      001032 D0 08            [24] 3550 	pop	_bp
                           000F7D  3551 	C$fuzzy.h$1416$1_0$73 ==.
                           000F7D  3552 	XG$fuzzy_triangle$0$0 ==.
      001034 22               [24] 3553 	ret
                                   3554 ;------------------------------------------------------------
                                   3555 ;Allocation info for local variables in function 'fuzzy_trapezoid'
                                   3556 ;------------------------------------------------------------
                                   3557 ;b             Allocated to stack - _bp -6 +4 
                                   3558 ;c             Allocated to stack - _bp -10 +4 
                                   3559 ;d             Allocated to stack - _bp -14 +4 
                                   3560 ;value         Allocated to stack - _bp -18 +4 
                                   3561 ;hedge         Allocated to stack - _bp -19 +1 
                                   3562 ;a             Allocated to registers r7 r6 r5 r4 
                                   3563 ;result        Allocated to stack - _bp +1 +4 
                                   3564 ;sloc0         Allocated to stack - _bp +1 +4 
                                   3565 ;sloc1         Allocated to stack - _bp +5 +4 
                                   3566 ;------------------------------------------------------------
                           000F7E  3567 	G$fuzzy_trapezoid$0$0 ==.
                           000F7E  3568 	C$fuzzy.h$1418$1_0$79 ==.
                                   3569 ;	../../fuzzy.h:1418: float fuzzy_trapezoid(
                                   3570 ;	-----------------------------------------
                                   3571 ;	 function fuzzy_trapezoid
                                   3572 ;	-----------------------------------------
      001035                       3573 _fuzzy_trapezoid:
      001035 C0 08            [24] 3574 	push	_bp
      001037 85 81 08         [24] 3575 	mov	_bp,sp
      00103A AF 82            [24] 3576 	mov	r7,dpl
      00103C AE 83            [24] 3577 	mov	r6,dph
      00103E AD F0            [24] 3578 	mov	r5,b
      001040 FC               [12] 3579 	mov	r4,a
      001041 E5 81            [12] 3580 	mov	a,sp
      001043 24 08            [12] 3581 	add	a,#0x08
      001045 F5 81            [12] 3582 	mov	sp,a
                           000F90  3583 	C$fuzzy.h$1430$1_0$79 ==.
                                   3584 ;	../../fuzzy.h:1430: a >= b ||
      001047 C0 07            [24] 3585 	push	ar7
      001049 C0 06            [24] 3586 	push	ar6
      00104B C0 05            [24] 3587 	push	ar5
      00104D C0 04            [24] 3588 	push	ar4
      00104F E5 08            [12] 3589 	mov	a,_bp
      001051 24 FA            [12] 3590 	add	a,#0xfa
      001053 F8               [12] 3591 	mov	r0,a
      001054 E6               [12] 3592 	mov	a,@r0
      001055 C0 E0            [24] 3593 	push	acc
      001057 08               [12] 3594 	inc	r0
      001058 E6               [12] 3595 	mov	a,@r0
      001059 C0 E0            [24] 3596 	push	acc
      00105B 08               [12] 3597 	inc	r0
      00105C E6               [12] 3598 	mov	a,@r0
      00105D C0 E0            [24] 3599 	push	acc
      00105F 08               [12] 3600 	inc	r0
      001060 E6               [12] 3601 	mov	a,@r0
      001061 C0 E0            [24] 3602 	push	acc
      001063 8F 82            [24] 3603 	mov	dpl, r7
      001065 8E 83            [24] 3604 	mov	dph, r6
      001067 8D F0            [24] 3605 	mov	b, r5
      001069 EC               [12] 3606 	mov	a, r4
      00106A 12 35 C2         [24] 3607 	lcall	___fslt
      00106D E5 81            [12] 3608 	mov	a,sp
      00106F 24 FC            [12] 3609 	add	a,#0xfc
      001071 F5 81            [12] 3610 	mov	sp,a
      001073 D0 04            [24] 3611 	pop	ar4
      001075 D0 05            [24] 3612 	pop	ar5
      001077 D0 06            [24] 3613 	pop	ar6
      001079 D0 07            [24] 3614 	pop	ar7
      00107B E5 82            [12] 3615 	mov	a, dpl
      00107D 24 FF            [12] 3616 	add	a,#0xff
      00107F 92 00            [24] 3617 	mov	b0,c
      001081 40 03            [24] 3618 	jc	00159$
      001083 02 11 91         [24] 3619 	ljmp	00108$
      001086                       3620 00159$:
                           000FCF  3621 	C$fuzzy.h$1431$1_0$79 ==.
                                   3622 ;	../../fuzzy.h:1431: b > c ||
      001086 C0 07            [24] 3623 	push	ar7
      001088 C0 06            [24] 3624 	push	ar6
      00108A C0 05            [24] 3625 	push	ar5
      00108C C0 04            [24] 3626 	push	ar4
      00108E E5 08            [12] 3627 	mov	a,_bp
      001090 24 FA            [12] 3628 	add	a,#0xfa
      001092 F8               [12] 3629 	mov	r0,a
      001093 E6               [12] 3630 	mov	a,@r0
      001094 C0 E0            [24] 3631 	push	acc
      001096 08               [12] 3632 	inc	r0
      001097 E6               [12] 3633 	mov	a,@r0
      001098 C0 E0            [24] 3634 	push	acc
      00109A 08               [12] 3635 	inc	r0
      00109B E6               [12] 3636 	mov	a,@r0
      00109C C0 E0            [24] 3637 	push	acc
      00109E 08               [12] 3638 	inc	r0
      00109F E6               [12] 3639 	mov	a,@r0
      0010A0 C0 E0            [24] 3640 	push	acc
      0010A2 E5 08            [12] 3641 	mov	a,_bp
      0010A4 24 F6            [12] 3642 	add	a,#0xf6
      0010A6 F8               [12] 3643 	mov	r0,a
      0010A7 86 82            [24] 3644 	mov	dpl, @r0
      0010A9 08               [12] 3645 	inc	r0
      0010AA 86 83            [24] 3646 	mov	dph, @r0
      0010AC 08               [12] 3647 	inc	r0
      0010AD 86 F0            [24] 3648 	mov	b, @r0
      0010AF 08               [12] 3649 	inc	r0
      0010B0 E6               [12] 3650 	mov	a, @r0
      0010B1 12 35 C2         [24] 3651 	lcall	___fslt
      0010B4 AB 82            [24] 3652 	mov	r3, dpl
      0010B6 E5 81            [12] 3653 	mov	a,sp
      0010B8 24 FC            [12] 3654 	add	a,#0xfc
      0010BA F5 81            [12] 3655 	mov	sp,a
      0010BC D0 04            [24] 3656 	pop	ar4
      0010BE D0 05            [24] 3657 	pop	ar5
      0010C0 D0 06            [24] 3658 	pop	ar6
      0010C2 D0 07            [24] 3659 	pop	ar7
      0010C4 EB               [12] 3660 	mov	a,r3
      0010C5 60 03            [24] 3661 	jz	00160$
      0010C7 02 11 91         [24] 3662 	ljmp	00108$
      0010CA                       3663 00160$:
                           001013  3664 	C$fuzzy.h$1432$1_0$79 ==.
                                   3665 ;	../../fuzzy.h:1432: c >= d ||
      0010CA C0 07            [24] 3666 	push	ar7
      0010CC C0 06            [24] 3667 	push	ar6
      0010CE C0 05            [24] 3668 	push	ar5
      0010D0 C0 04            [24] 3669 	push	ar4
      0010D2 E5 08            [12] 3670 	mov	a,_bp
      0010D4 24 F2            [12] 3671 	add	a,#0xf2
      0010D6 F8               [12] 3672 	mov	r0,a
      0010D7 E6               [12] 3673 	mov	a,@r0
      0010D8 C0 E0            [24] 3674 	push	acc
      0010DA 08               [12] 3675 	inc	r0
      0010DB E6               [12] 3676 	mov	a,@r0
      0010DC C0 E0            [24] 3677 	push	acc
      0010DE 08               [12] 3678 	inc	r0
      0010DF E6               [12] 3679 	mov	a,@r0
      0010E0 C0 E0            [24] 3680 	push	acc
      0010E2 08               [12] 3681 	inc	r0
      0010E3 E6               [12] 3682 	mov	a,@r0
      0010E4 C0 E0            [24] 3683 	push	acc
      0010E6 E5 08            [12] 3684 	mov	a,_bp
      0010E8 24 F6            [12] 3685 	add	a,#0xf6
      0010EA F8               [12] 3686 	mov	r0,a
      0010EB 86 82            [24] 3687 	mov	dpl, @r0
      0010ED 08               [12] 3688 	inc	r0
      0010EE 86 83            [24] 3689 	mov	dph, @r0
      0010F0 08               [12] 3690 	inc	r0
      0010F1 86 F0            [24] 3691 	mov	b, @r0
      0010F3 08               [12] 3692 	inc	r0
      0010F4 E6               [12] 3693 	mov	a, @r0
      0010F5 12 35 C2         [24] 3694 	lcall	___fslt
      0010F8 E5 81            [12] 3695 	mov	a,sp
      0010FA 24 FC            [12] 3696 	add	a,#0xfc
      0010FC F5 81            [12] 3697 	mov	sp,a
      0010FE D0 04            [24] 3698 	pop	ar4
      001100 D0 05            [24] 3699 	pop	ar5
      001102 D0 06            [24] 3700 	pop	ar6
      001104 D0 07            [24] 3701 	pop	ar7
      001106 E5 82            [12] 3702 	mov	a, dpl
      001108 24 FF            [12] 3703 	add	a,#0xff
      00110A 92 00            [24] 3704 	mov	b0,c
      00110C 40 03            [24] 3705 	jc	00161$
      00110E 02 11 91         [24] 3706 	ljmp	00108$
      001111                       3707 00161$:
                           00105A  3708 	C$fuzzy.h$1433$1_0$79 ==.
                                   3709 ;	../../fuzzy.h:1433: value <= a ||
      001111 C0 07            [24] 3710 	push	ar7
      001113 C0 06            [24] 3711 	push	ar6
      001115 C0 05            [24] 3712 	push	ar5
      001117 C0 04            [24] 3713 	push	ar4
      001119 E5 08            [12] 3714 	mov	a,_bp
      00111B 24 EE            [12] 3715 	add	a,#0xee
      00111D F8               [12] 3716 	mov	r0,a
      00111E E6               [12] 3717 	mov	a,@r0
      00111F C0 E0            [24] 3718 	push	acc
      001121 08               [12] 3719 	inc	r0
      001122 E6               [12] 3720 	mov	a,@r0
      001123 C0 E0            [24] 3721 	push	acc
      001125 08               [12] 3722 	inc	r0
      001126 E6               [12] 3723 	mov	a,@r0
      001127 C0 E0            [24] 3724 	push	acc
      001129 08               [12] 3725 	inc	r0
      00112A E6               [12] 3726 	mov	a,@r0
      00112B C0 E0            [24] 3727 	push	acc
      00112D 8F 82            [24] 3728 	mov	dpl, r7
      00112F 8E 83            [24] 3729 	mov	dph, r6
      001131 8D F0            [24] 3730 	mov	b, r5
      001133 EC               [12] 3731 	mov	a, r4
      001134 12 35 C2         [24] 3732 	lcall	___fslt
      001137 E5 81            [12] 3733 	mov	a,sp
      001139 24 FC            [12] 3734 	add	a,#0xfc
      00113B F5 81            [12] 3735 	mov	sp,a
      00113D D0 04            [24] 3736 	pop	ar4
      00113F D0 05            [24] 3737 	pop	ar5
      001141 D0 06            [24] 3738 	pop	ar6
      001143 D0 07            [24] 3739 	pop	ar7
      001145 E5 82            [12] 3740 	mov	a, dpl
      001147 24 FF            [12] 3741 	add	a,#0xff
      001149 92 00            [24] 3742 	mov	b0,c
      00114B 50 44            [24] 3743 	jnc	00108$
                           001096  3744 	C$fuzzy.h$1435$1_0$79 ==.
                                   3745 ;	../../fuzzy.h:1435: ) {
      00114D C0 07            [24] 3746 	push	ar7
      00114F C0 06            [24] 3747 	push	ar6
      001151 C0 05            [24] 3748 	push	ar5
      001153 C0 04            [24] 3749 	push	ar4
      001155 E5 08            [12] 3750 	mov	a,_bp
      001157 24 F2            [12] 3751 	add	a,#0xf2
      001159 F8               [12] 3752 	mov	r0,a
      00115A E6               [12] 3753 	mov	a,@r0
      00115B C0 E0            [24] 3754 	push	acc
      00115D 08               [12] 3755 	inc	r0
      00115E E6               [12] 3756 	mov	a,@r0
      00115F C0 E0            [24] 3757 	push	acc
      001161 08               [12] 3758 	inc	r0
      001162 E6               [12] 3759 	mov	a,@r0
      001163 C0 E0            [24] 3760 	push	acc
      001165 08               [12] 3761 	inc	r0
      001166 E6               [12] 3762 	mov	a,@r0
      001167 C0 E0            [24] 3763 	push	acc
      001169 E5 08            [12] 3764 	mov	a,_bp
      00116B 24 EE            [12] 3765 	add	a,#0xee
      00116D F8               [12] 3766 	mov	r0,a
      00116E 86 82            [24] 3767 	mov	dpl, @r0
      001170 08               [12] 3768 	inc	r0
      001171 86 83            [24] 3769 	mov	dph, @r0
      001173 08               [12] 3770 	inc	r0
      001174 86 F0            [24] 3771 	mov	b, @r0
      001176 08               [12] 3772 	inc	r0
      001177 E6               [12] 3773 	mov	a, @r0
      001178 12 35 C2         [24] 3774 	lcall	___fslt
      00117B E5 81            [12] 3775 	mov	a,sp
      00117D 24 FC            [12] 3776 	add	a,#0xfc
      00117F F5 81            [12] 3777 	mov	sp,a
      001181 D0 04            [24] 3778 	pop	ar4
      001183 D0 05            [24] 3779 	pop	ar5
      001185 D0 06            [24] 3780 	pop	ar6
      001187 D0 07            [24] 3781 	pop	ar7
      001189 E5 82            [12] 3782 	mov	a, dpl
      00118B 24 FF            [12] 3783 	add	a,#0xff
      00118D 92 00            [24] 3784 	mov	b0,c
      00118F 40 0E            [24] 3785 	jc	00109$
      001191                       3786 00108$:
                           0010DA  3787 	C$fuzzy.h$1436$2_0$80 ==.
                                   3788 ;	../../fuzzy.h:1436: result = LEVEL_LO;
      001191 A8 08            [24] 3789 	mov	r0,_bp
      001193 08               [12] 3790 	inc	r0
      001194 E4               [12] 3791 	clr	a
      001195 F6               [12] 3792 	mov	@r0,a
      001196 08               [12] 3793 	inc	r0
      001197 F6               [12] 3794 	mov	@r0,a
      001198 08               [12] 3795 	inc	r0
      001199 F6               [12] 3796 	mov	@r0,a
      00119A 08               [12] 3797 	inc	r0
      00119B F6               [12] 3798 	mov	@r0,a
      00119C 02 13 9E         [24] 3799 	ljmp	00110$
      00119F                       3800 00109$:
                           0010E8  3801 	C$fuzzy.h$1439$1_0$79 ==.
                                   3802 ;	../../fuzzy.h:1439: value >= b &&
      00119F C0 07            [24] 3803 	push	ar7
      0011A1 C0 06            [24] 3804 	push	ar6
      0011A3 C0 05            [24] 3805 	push	ar5
      0011A5 C0 04            [24] 3806 	push	ar4
      0011A7 E5 08            [12] 3807 	mov	a,_bp
      0011A9 24 FA            [12] 3808 	add	a,#0xfa
      0011AB F8               [12] 3809 	mov	r0,a
      0011AC E6               [12] 3810 	mov	a,@r0
      0011AD C0 E0            [24] 3811 	push	acc
      0011AF 08               [12] 3812 	inc	r0
      0011B0 E6               [12] 3813 	mov	a,@r0
      0011B1 C0 E0            [24] 3814 	push	acc
      0011B3 08               [12] 3815 	inc	r0
      0011B4 E6               [12] 3816 	mov	a,@r0
      0011B5 C0 E0            [24] 3817 	push	acc
      0011B7 08               [12] 3818 	inc	r0
      0011B8 E6               [12] 3819 	mov	a,@r0
      0011B9 C0 E0            [24] 3820 	push	acc
      0011BB E5 08            [12] 3821 	mov	a,_bp
      0011BD 24 EE            [12] 3822 	add	a,#0xee
      0011BF F8               [12] 3823 	mov	r0,a
      0011C0 86 82            [24] 3824 	mov	dpl, @r0
      0011C2 08               [12] 3825 	inc	r0
      0011C3 86 83            [24] 3826 	mov	dph, @r0
      0011C5 08               [12] 3827 	inc	r0
      0011C6 86 F0            [24] 3828 	mov	b, @r0
      0011C8 08               [12] 3829 	inc	r0
      0011C9 E6               [12] 3830 	mov	a, @r0
      0011CA 12 35 C2         [24] 3831 	lcall	___fslt
      0011CD E5 81            [12] 3832 	mov	a,sp
      0011CF 24 FC            [12] 3833 	add	a,#0xfc
      0011D1 F5 81            [12] 3834 	mov	sp,a
      0011D3 D0 04            [24] 3835 	pop	ar4
      0011D5 D0 05            [24] 3836 	pop	ar5
      0011D7 D0 06            [24] 3837 	pop	ar6
      0011D9 D0 07            [24] 3838 	pop	ar7
      0011DB E5 82            [12] 3839 	mov	a, dpl
      0011DD 24 FF            [12] 3840 	add	a,#0xff
      0011DF 92 00            [24] 3841 	mov	b0,c
      0011E1 40 54            [24] 3842 	jc	00105$
                           00112C  3843 	C$fuzzy.h$1441$1_0$79 ==.
                                   3844 ;	../../fuzzy.h:1441: ) {
      0011E3 C0 07            [24] 3845 	push	ar7
      0011E5 C0 06            [24] 3846 	push	ar6
      0011E7 C0 05            [24] 3847 	push	ar5
      0011E9 C0 04            [24] 3848 	push	ar4
      0011EB E5 08            [12] 3849 	mov	a,_bp
      0011ED 24 EE            [12] 3850 	add	a,#0xee
      0011EF F8               [12] 3851 	mov	r0,a
      0011F0 E6               [12] 3852 	mov	a,@r0
      0011F1 C0 E0            [24] 3853 	push	acc
      0011F3 08               [12] 3854 	inc	r0
      0011F4 E6               [12] 3855 	mov	a,@r0
      0011F5 C0 E0            [24] 3856 	push	acc
      0011F7 08               [12] 3857 	inc	r0
      0011F8 E6               [12] 3858 	mov	a,@r0
      0011F9 C0 E0            [24] 3859 	push	acc
      0011FB 08               [12] 3860 	inc	r0
      0011FC E6               [12] 3861 	mov	a,@r0
      0011FD C0 E0            [24] 3862 	push	acc
      0011FF E5 08            [12] 3863 	mov	a,_bp
      001201 24 F6            [12] 3864 	add	a,#0xf6
      001203 F8               [12] 3865 	mov	r0,a
      001204 86 82            [24] 3866 	mov	dpl, @r0
      001206 08               [12] 3867 	inc	r0
      001207 86 83            [24] 3868 	mov	dph, @r0
      001209 08               [12] 3869 	inc	r0
      00120A 86 F0            [24] 3870 	mov	b, @r0
      00120C 08               [12] 3871 	inc	r0
      00120D E6               [12] 3872 	mov	a, @r0
      00120E 12 35 C2         [24] 3873 	lcall	___fslt
      001211 E5 81            [12] 3874 	mov	a,sp
      001213 24 FC            [12] 3875 	add	a,#0xfc
      001215 F5 81            [12] 3876 	mov	sp,a
      001217 D0 04            [24] 3877 	pop	ar4
      001219 D0 05            [24] 3878 	pop	ar5
      00121B D0 06            [24] 3879 	pop	ar6
      00121D D0 07            [24] 3880 	pop	ar7
      00121F E5 82            [12] 3881 	mov	a, dpl
      001221 24 FF            [12] 3882 	add	a,#0xff
      001223 92 00            [24] 3883 	mov	b0,c
      001225 40 10            [24] 3884 	jc	00105$
                           001170  3885 	C$fuzzy.h$1442$2_0$81 ==.
                                   3886 ;	../../fuzzy.h:1442: result = LEVEL_HI;
      001227 A8 08            [24] 3887 	mov	r0,_bp
      001229 08               [12] 3888 	inc	r0
      00122A E4               [12] 3889 	clr	a
      00122B F6               [12] 3890 	mov	@r0,a
      00122C 08               [12] 3891 	inc	r0
      00122D F6               [12] 3892 	mov	@r0,a
      00122E 08               [12] 3893 	inc	r0
      00122F 76 80            [12] 3894 	mov	@r0,#0x80
      001231 08               [12] 3895 	inc	r0
      001232 76 3F            [12] 3896 	mov	@r0,#0x3f
      001234 02 13 9E         [24] 3897 	ljmp	00110$
      001237                       3898 00105$:
                           001180  3899 	C$fuzzy.h$1444$1_0$79 ==.
                                   3900 ;	../../fuzzy.h:1444: else if (value < b) {
      001237 C0 07            [24] 3901 	push	ar7
      001239 C0 06            [24] 3902 	push	ar6
      00123B C0 05            [24] 3903 	push	ar5
      00123D C0 04            [24] 3904 	push	ar4
      00123F E5 08            [12] 3905 	mov	a,_bp
      001241 24 FA            [12] 3906 	add	a,#0xfa
      001243 F8               [12] 3907 	mov	r0,a
      001244 E6               [12] 3908 	mov	a,@r0
      001245 C0 E0            [24] 3909 	push	acc
      001247 08               [12] 3910 	inc	r0
      001248 E6               [12] 3911 	mov	a,@r0
      001249 C0 E0            [24] 3912 	push	acc
      00124B 08               [12] 3913 	inc	r0
      00124C E6               [12] 3914 	mov	a,@r0
      00124D C0 E0            [24] 3915 	push	acc
      00124F 08               [12] 3916 	inc	r0
      001250 E6               [12] 3917 	mov	a,@r0
      001251 C0 E0            [24] 3918 	push	acc
      001253 E5 08            [12] 3919 	mov	a,_bp
      001255 24 EE            [12] 3920 	add	a,#0xee
      001257 F8               [12] 3921 	mov	r0,a
      001258 86 82            [24] 3922 	mov	dpl, @r0
      00125A 08               [12] 3923 	inc	r0
      00125B 86 83            [24] 3924 	mov	dph, @r0
      00125D 08               [12] 3925 	inc	r0
      00125E 86 F0            [24] 3926 	mov	b, @r0
      001260 08               [12] 3927 	inc	r0
      001261 E6               [12] 3928 	mov	a, @r0
      001262 12 35 C2         [24] 3929 	lcall	___fslt
      001265 AB 82            [24] 3930 	mov	r3, dpl
      001267 E5 81            [12] 3931 	mov	a,sp
      001269 24 FC            [12] 3932 	add	a,#0xfc
      00126B F5 81            [12] 3933 	mov	sp,a
      00126D D0 04            [24] 3934 	pop	ar4
      00126F D0 05            [24] 3935 	pop	ar5
      001271 D0 06            [24] 3936 	pop	ar6
      001273 D0 07            [24] 3937 	pop	ar7
      001275 EB               [12] 3938 	mov	a,r3
      001276 70 03            [24] 3939 	jnz	00166$
      001278 02 13 02         [24] 3940 	ljmp	00102$
      00127B                       3941 00166$:
                           0011C4  3942 	C$fuzzy.h$1446$1_0$79 ==.
                                   3943 ;	../../fuzzy.h:1446: (value - a) /
      00127B C0 07            [24] 3944 	push	ar7
      00127D C0 06            [24] 3945 	push	ar6
      00127F C0 05            [24] 3946 	push	ar5
      001281 C0 04            [24] 3947 	push	ar4
      001283 C0 07            [24] 3948 	push	ar7
      001285 C0 06            [24] 3949 	push	ar6
      001287 C0 05            [24] 3950 	push	ar5
      001289 C0 04            [24] 3951 	push	ar4
                           0011D4  3952 	C$fuzzy.h$1447$1_0$79 ==.
                                   3953 ;	../../fuzzy.h:1447: (b - a);
      00128B E5 08            [12] 3954 	mov	a,_bp
      00128D 24 EE            [12] 3955 	add	a,#0xee
      00128F F8               [12] 3956 	mov	r0,a
      001290 86 82            [24] 3957 	mov	dpl, @r0
      001292 08               [12] 3958 	inc	r0
      001293 86 83            [24] 3959 	mov	dph, @r0
      001295 08               [12] 3960 	inc	r0
      001296 86 F0            [24] 3961 	mov	b, @r0
      001298 08               [12] 3962 	inc	r0
      001299 E6               [12] 3963 	mov	a, @r0
      00129A 12 34 87         [24] 3964 	lcall	___fssub
      00129D C8               [12] 3965 	xch	a,r0
      00129E E5 08            [12] 3966 	mov	a,_bp
      0012A0 24 05            [12] 3967 	add	a,#0x05
      0012A2 C8               [12] 3968 	xch	a,r0
      0012A3 A6 82            [24] 3969 	mov	@r0, dpl
      0012A5 08               [12] 3970 	inc	r0
      0012A6 A6 83            [24] 3971 	mov	@r0, dph
      0012A8 08               [12] 3972 	inc	r0
      0012A9 A6 F0            [24] 3973 	mov	@r0, b
      0012AB 08               [12] 3974 	inc	r0
      0012AC F6               [12] 3975 	mov	@r0,a
      0012AD E5 81            [12] 3976 	mov	a,sp
      0012AF 24 FC            [12] 3977 	add	a,#0xfc
      0012B1 F5 81            [12] 3978 	mov	sp,a
      0012B3 E5 08            [12] 3979 	mov	a,_bp
      0012B5 24 FA            [12] 3980 	add	a,#0xfa
      0012B7 F8               [12] 3981 	mov	r0,a
      0012B8 86 82            [24] 3982 	mov	dpl, @r0
      0012BA 08               [12] 3983 	inc	r0
      0012BB 86 83            [24] 3984 	mov	dph, @r0
      0012BD 08               [12] 3985 	inc	r0
      0012BE 86 F0            [24] 3986 	mov	b, @r0
      0012C0 08               [12] 3987 	inc	r0
      0012C1 E6               [12] 3988 	mov	a, @r0
      0012C2 12 34 87         [24] 3989 	lcall	___fssub
      0012C5 AC 82            [24] 3990 	mov	r4, dpl
      0012C7 AD 83            [24] 3991 	mov	r5, dph
      0012C9 AE F0            [24] 3992 	mov	r6, b
      0012CB FF               [12] 3993 	mov	r7, a
      0012CC E5 81            [12] 3994 	mov	a,sp
      0012CE 24 FC            [12] 3995 	add	a,#0xfc
      0012D0 F5 81            [12] 3996 	mov	sp,a
      0012D2 C0 04            [24] 3997 	push	ar4
      0012D4 C0 05            [24] 3998 	push	ar5
      0012D6 C0 06            [24] 3999 	push	ar6
      0012D8 C0 07            [24] 4000 	push	ar7
      0012DA E5 08            [12] 4001 	mov	a,_bp
      0012DC 24 05            [12] 4002 	add	a,#0x05
      0012DE F8               [12] 4003 	mov	r0,a
      0012DF 86 82            [24] 4004 	mov	dpl, @r0
      0012E1 08               [12] 4005 	inc	r0
      0012E2 86 83            [24] 4006 	mov	dph, @r0
      0012E4 08               [12] 4007 	inc	r0
      0012E5 86 F0            [24] 4008 	mov	b, @r0
      0012E7 08               [12] 4009 	inc	r0
      0012E8 E6               [12] 4010 	mov	a, @r0
      0012E9 12 37 2B         [24] 4011 	lcall	___fsdiv
      0012EC A8 08            [24] 4012 	mov	r0,_bp
      0012EE 08               [12] 4013 	inc	r0
      0012EF A6 82            [24] 4014 	mov	@r0, dpl
      0012F1 08               [12] 4015 	inc	r0
      0012F2 A6 83            [24] 4016 	mov	@r0, dph
      0012F4 08               [12] 4017 	inc	r0
      0012F5 A6 F0            [24] 4018 	mov	@r0, b
      0012F7 08               [12] 4019 	inc	r0
      0012F8 F6               [12] 4020 	mov	@r0,a
      0012F9 E5 81            [12] 4021 	mov	a,sp
      0012FB 24 FC            [12] 4022 	add	a,#0xfc
      0012FD F5 81            [12] 4023 	mov	sp,a
      0012FF 02 13 9E         [24] 4024 	ljmp	00110$
      001302                       4025 00102$:
                           00124B  4026 	C$fuzzy.h$1451$1_0$79 ==.
                                   4027 ;	../../fuzzy.h:1451: (d - value) /
      001302 E5 08            [12] 4028 	mov	a,_bp
      001304 24 EE            [12] 4029 	add	a,#0xee
      001306 F8               [12] 4030 	mov	r0,a
      001307 E6               [12] 4031 	mov	a,@r0
      001308 C0 E0            [24] 4032 	push	acc
      00130A 08               [12] 4033 	inc	r0
      00130B E6               [12] 4034 	mov	a,@r0
      00130C C0 E0            [24] 4035 	push	acc
      00130E 08               [12] 4036 	inc	r0
      00130F E6               [12] 4037 	mov	a,@r0
      001310 C0 E0            [24] 4038 	push	acc
      001312 08               [12] 4039 	inc	r0
      001313 E6               [12] 4040 	mov	a,@r0
      001314 C0 E0            [24] 4041 	push	acc
                           00125F  4042 	C$fuzzy.h$1452$1_0$79 ==.
                                   4043 ;	../../fuzzy.h:1452: (d - c);
      001316 E5 08            [12] 4044 	mov	a,_bp
      001318 24 F2            [12] 4045 	add	a,#0xf2
      00131A F8               [12] 4046 	mov	r0,a
      00131B 86 82            [24] 4047 	mov	dpl, @r0
      00131D 08               [12] 4048 	inc	r0
      00131E 86 83            [24] 4049 	mov	dph, @r0
      001320 08               [12] 4050 	inc	r0
      001321 86 F0            [24] 4051 	mov	b, @r0
      001323 08               [12] 4052 	inc	r0
      001324 E6               [12] 4053 	mov	a, @r0
      001325 12 34 87         [24] 4054 	lcall	___fssub
      001328 C8               [12] 4055 	xch	a,r0
      001329 E5 08            [12] 4056 	mov	a,_bp
      00132B 24 05            [12] 4057 	add	a,#0x05
      00132D C8               [12] 4058 	xch	a,r0
      00132E A6 82            [24] 4059 	mov	@r0, dpl
      001330 08               [12] 4060 	inc	r0
      001331 A6 83            [24] 4061 	mov	@r0, dph
      001333 08               [12] 4062 	inc	r0
      001334 A6 F0            [24] 4063 	mov	@r0, b
      001336 08               [12] 4064 	inc	r0
      001337 F6               [12] 4065 	mov	@r0,a
      001338 E5 81            [12] 4066 	mov	a,sp
      00133A 24 FC            [12] 4067 	add	a,#0xfc
      00133C F5 81            [12] 4068 	mov	sp,a
      00133E E5 08            [12] 4069 	mov	a,_bp
      001340 24 F6            [12] 4070 	add	a,#0xf6
      001342 F8               [12] 4071 	mov	r0,a
      001343 E6               [12] 4072 	mov	a,@r0
      001344 C0 E0            [24] 4073 	push	acc
      001346 08               [12] 4074 	inc	r0
      001347 E6               [12] 4075 	mov	a,@r0
      001348 C0 E0            [24] 4076 	push	acc
      00134A 08               [12] 4077 	inc	r0
      00134B E6               [12] 4078 	mov	a,@r0
      00134C C0 E0            [24] 4079 	push	acc
      00134E 08               [12] 4080 	inc	r0
      00134F E6               [12] 4081 	mov	a,@r0
      001350 C0 E0            [24] 4082 	push	acc
      001352 E5 08            [12] 4083 	mov	a,_bp
      001354 24 F2            [12] 4084 	add	a,#0xf2
      001356 F8               [12] 4085 	mov	r0,a
      001357 86 82            [24] 4086 	mov	dpl, @r0
      001359 08               [12] 4087 	inc	r0
      00135A 86 83            [24] 4088 	mov	dph, @r0
      00135C 08               [12] 4089 	inc	r0
      00135D 86 F0            [24] 4090 	mov	b, @r0
      00135F 08               [12] 4091 	inc	r0
      001360 E6               [12] 4092 	mov	a, @r0
      001361 12 34 87         [24] 4093 	lcall	___fssub
      001364 AA 82            [24] 4094 	mov	r2, dpl
      001366 AB 83            [24] 4095 	mov	r3, dph
      001368 AE F0            [24] 4096 	mov	r6, b
      00136A FF               [12] 4097 	mov	r7, a
      00136B E5 81            [12] 4098 	mov	a,sp
      00136D 24 FC            [12] 4099 	add	a,#0xfc
      00136F F5 81            [12] 4100 	mov	sp,a
      001371 C0 02            [24] 4101 	push	ar2
      001373 C0 03            [24] 4102 	push	ar3
      001375 C0 06            [24] 4103 	push	ar6
      001377 C0 07            [24] 4104 	push	ar7
      001379 E5 08            [12] 4105 	mov	a,_bp
      00137B 24 05            [12] 4106 	add	a,#0x05
      00137D F8               [12] 4107 	mov	r0,a
      00137E 86 82            [24] 4108 	mov	dpl, @r0
      001380 08               [12] 4109 	inc	r0
      001381 86 83            [24] 4110 	mov	dph, @r0
      001383 08               [12] 4111 	inc	r0
      001384 86 F0            [24] 4112 	mov	b, @r0
      001386 08               [12] 4113 	inc	r0
      001387 E6               [12] 4114 	mov	a, @r0
      001388 12 37 2B         [24] 4115 	lcall	___fsdiv
      00138B A8 08            [24] 4116 	mov	r0,_bp
      00138D 08               [12] 4117 	inc	r0
      00138E A6 82            [24] 4118 	mov	@r0, dpl
      001390 08               [12] 4119 	inc	r0
      001391 A6 83            [24] 4120 	mov	@r0, dph
      001393 08               [12] 4121 	inc	r0
      001394 A6 F0            [24] 4122 	mov	@r0, b
      001396 08               [12] 4123 	inc	r0
      001397 F6               [12] 4124 	mov	@r0,a
      001398 E5 81            [12] 4125 	mov	a,sp
      00139A 24 FC            [12] 4126 	add	a,#0xfc
      00139C F5 81            [12] 4127 	mov	sp,a
      00139E                       4128 00110$:
                           0012E7  4129 	C$fuzzy.h$1456$1_0$79 ==.
                                   4130 ;	../../fuzzy.h:1456: result,
      00139E E5 08            [12] 4131 	mov	a,_bp
      0013A0 24 ED            [12] 4132 	add	a,#0xed
      0013A2 F8               [12] 4133 	mov	r0,a
      0013A3 E6               [12] 4134 	mov	a,@r0
      0013A4 C0 E0            [24] 4135 	push	acc
      0013A6 A8 08            [24] 4136 	mov	r0,_bp
      0013A8 08               [12] 4137 	inc	r0
      0013A9 86 82            [24] 4138 	mov	dpl, @r0
      0013AB 08               [12] 4139 	inc	r0
      0013AC 86 83            [24] 4140 	mov	dph, @r0
      0013AE 08               [12] 4141 	inc	r0
      0013AF 86 F0            [24] 4142 	mov	b, @r0
      0013B1 08               [12] 4143 	inc	r0
      0013B2 E6               [12] 4144 	mov	a, @r0
      0013B3 12 01 99         [24] 4145 	lcall	_fuzzy_apply_hedge
      0013B6 AC 82            [24] 4146 	mov	r4, dpl
      0013B8 AD 83            [24] 4147 	mov	r5, dph
      0013BA AE F0            [24] 4148 	mov	r6, b
      0013BC FF               [12] 4149 	mov	r7, a
      0013BD 15 81            [12] 4150 	dec	sp
      0013BF 8C 82            [24] 4151 	mov	dpl, r4
      0013C1 8D 83            [24] 4152 	mov	dph, r5
      0013C3 8E F0            [24] 4153 	mov	b, r6
      0013C5 EF               [12] 4154 	mov	a, r7
                           00130F  4155 	C$fuzzy.h$1459$1_0$79 ==.
                                   4156 ;	../../fuzzy.h:1459: }
      0013C6 85 08 81         [24] 4157 	mov	sp,_bp
      0013C9 D0 08            [24] 4158 	pop	_bp
                           001314  4159 	C$fuzzy.h$1459$1_0$79 ==.
                           001314  4160 	XG$fuzzy_trapezoid$0$0 ==.
      0013CB 22               [24] 4161 	ret
                                   4162 ;------------------------------------------------------------
                                   4163 ;Allocation info for local variables in function 'fuzzy_function_array'
                                   4164 ;------------------------------------------------------------
                                   4165 ;value         Allocated to stack - _bp -6 +4 
                                   4166 ;hedge         Allocated to stack - _bp -7 +1 
                                   4167 ;parameter_count Allocated to stack - _bp -9 +2 
                                   4168 ;parameters    Allocated to stack - _bp -12 +3 
                                   4169 ;shape         Allocated to registers r7 
                                   4170 ;sloc0         Allocated to stack - _bp +2 +1 
                                   4171 ;sloc1         Allocated to stack - _bp +1 +4 
                                   4172 ;sloc2         Allocated to stack - _bp +5 +4 
                                   4173 ;sloc3         Allocated to stack - _bp +9 +4 
                                   4174 ;------------------------------------------------------------
                           001315  4175 	G$fuzzy_function_array$0$0 ==.
                           001315  4176 	C$fuzzy.h$1916$1_0$85 ==.
                                   4177 ;	../../fuzzy.h:1916: float fuzzy_function_array(
                                   4178 ;	-----------------------------------------
                                   4179 ;	 function fuzzy_function_array
                                   4180 ;	-----------------------------------------
      0013CC                       4181 _fuzzy_function_array:
      0013CC C0 08            [24] 4182 	push	_bp
      0013CE E5 81            [12] 4183 	mov	a,sp
      0013D0 F5 08            [12] 4184 	mov	_bp,a
      0013D2 24 0C            [12] 4185 	add	a,#0x0c
      0013D4 F5 81            [12] 4186 	mov	sp,a
      0013D6 AF 82            [24] 4187 	mov	r7, dpl
                           001321  4188 	C$fuzzy.h$1924$1_0$85 ==.
                                   4189 ;	../../fuzzy.h:1924: if (parameters == NULL) {
      0013D8 E5 08            [12] 4190 	mov	a,_bp
      0013DA 24 F4            [12] 4191 	add	a,#0xf4
      0013DC F8               [12] 4192 	mov	r0,a
      0013DD E6               [12] 4193 	mov	a,@r0
      0013DE 08               [12] 4194 	inc	r0
      0013DF 46               [12] 4195 	orl	a,@r0
      0013E0 70 09            [24] 4196 	jnz	00102$
                           00132B  4197 	C$fuzzy.h$1925$2_0$86 ==.
                                   4198 ;	../../fuzzy.h:1925: return LEVEL_LO;
      0013E2 90 00 00         [24] 4199 	mov	dptr,#0x0000
      0013E5 E4               [12] 4200 	clr	a
      0013E6 F5 F0            [12] 4201 	mov	b,a
      0013E8 02 17 67         [24] 4202 	ljmp	00123$
      0013EB                       4203 00102$:
                           001334  4204 	C$fuzzy.h$1928$1_0$85 ==.
                                   4205 ;	../../fuzzy.h:1928: switch (shape) {
      0013EB EF               [12] 4206 	mov	a,r7
      0013EC 24 F4            [12] 4207 	add	a,#0xff - 0x0b
      0013EE 50 03            [24] 4208 	jnc	00156$
      0013F0 02 17 61         [24] 4209 	ljmp	00121$
      0013F3                       4210 00156$:
      0013F3 EF               [12] 4211 	mov	a,r7
      0013F4 24 0A            [12] 4212 	add	a,#(00157$-3-.)
      0013F6 83               [24] 4213 	movc	a,@a+pc
      0013F7 F5 82            [12] 4214 	mov	dpl,a
      0013F9 EF               [12] 4215 	mov	a,r7
      0013FA 24 10            [12] 4216 	add	a,#(00158$-3-.)
      0013FC 83               [24] 4217 	movc	a,@a+pc
      0013FD F5 83            [12] 4218 	mov	dph,a
      0013FF E4               [12] 4219 	clr	a
      001400 73               [24] 4220 	jmp	@a+dptr
      001401                       4221 00157$:
      001401 19                    4222 	.db	00103$
      001402 15                    4223 	.db	00106$
      001403 15                    4224 	.db	00109$
      001404 59                    4225 	.db	00120$
      001405 59                    4226 	.db	00120$
      001406 59                    4227 	.db	00120$
      001407 59                    4228 	.db	00120$
      001408 59                    4229 	.db	00120$
      001409 59                    4230 	.db	00120$
      00140A 59                    4231 	.db	00120$
      00140B 59                    4232 	.db	00120$
      00140C 59                    4233 	.db	00120$
      00140D                       4234 00158$:
      00140D 14                    4235 	.db	00103$>>8
      00140E 15                    4236 	.db	00106$>>8
      00140F 16                    4237 	.db	00109$>>8
      001410 17                    4238 	.db	00120$>>8
      001411 17                    4239 	.db	00120$>>8
      001412 17                    4240 	.db	00120$>>8
      001413 17                    4241 	.db	00120$>>8
      001414 17                    4242 	.db	00120$>>8
      001415 17                    4243 	.db	00120$>>8
      001416 17                    4244 	.db	00120$>>8
      001417 17                    4245 	.db	00120$>>8
      001418 17                    4246 	.db	00120$>>8
                           001362  4247 	C$fuzzy.h$1929$2_0$87 ==.
                                   4248 ;	../../fuzzy.h:1929: case FUZZY_SHAPE_RAMP:
      001419                       4249 00103$:
                           001362  4250 	C$fuzzy.h$1930$2_0$87 ==.
                                   4251 ;	../../fuzzy.h:1930: if (parameter_count != 3u) {
      001419 E5 08            [12] 4252 	mov	a,_bp
      00141B 24 F7            [12] 4253 	add	a,#0xf7
      00141D F8               [12] 4254 	mov	r0,a
      00141E B6 03 06         [24] 4255 	cjne	@r0,#0x03,00159$
      001421 08               [12] 4256 	inc	r0
      001422 B6 00 02         [24] 4257 	cjne	@r0,#0x00,00159$
      001425 80 09            [24] 4258 	sjmp	00105$
      001427                       4259 00159$:
                           001370  4260 	C$fuzzy.h$1931$3_0$88 ==.
                                   4261 ;	../../fuzzy.h:1931: return LEVEL_LO;
      001427 90 00 00         [24] 4262 	mov	dptr,#0x0000
      00142A E4               [12] 4263 	clr	a
      00142B F5 F0            [12] 4264 	mov	b,a
      00142D 02 17 67         [24] 4265 	ljmp	00123$
      001430                       4266 00105$:
                           001379  4267 	C$fuzzy.h$1938$2_0$87 ==.
                                   4268 ;	../../fuzzy.h:1938: parameters[2] != 0.0f,
      001430 E5 08            [12] 4269 	mov	a,_bp
      001432 24 F4            [12] 4270 	add	a,#0xf4
      001434 F8               [12] 4271 	mov	r0,a
      001435 74 08            [12] 4272 	mov	a,#0x08
      001437 26               [12] 4273 	add	a, @r0
      001438 FD               [12] 4274 	mov	r5,a
      001439 E4               [12] 4275 	clr	a
      00143A 08               [12] 4276 	inc	r0
      00143B 36               [12] 4277 	addc	a, @r0
      00143C FE               [12] 4278 	mov	r6,a
      00143D 08               [12] 4279 	inc	r0
      00143E 86 07            [24] 4280 	mov	ar7,@r0
      001440 8D 82            [24] 4281 	mov	dpl,r5
      001442 8E 83            [24] 4282 	mov	dph,r6
      001444 8F F0            [24] 4283 	mov	b,r7
      001446 12 37 EE         [24] 4284 	lcall	__gptrget
      001449 FD               [12] 4285 	mov	r5,a
      00144A A3               [24] 4286 	inc	dptr
      00144B 12 37 EE         [24] 4287 	lcall	__gptrget
      00144E FE               [12] 4288 	mov	r6,a
      00144F A3               [24] 4289 	inc	dptr
      001450 12 37 EE         [24] 4290 	lcall	__gptrget
      001453 FF               [12] 4291 	mov	r7,a
      001454 A3               [24] 4292 	inc	dptr
      001455 12 37 EE         [24] 4293 	lcall	__gptrget
      001458 FC               [12] 4294 	mov	r4,a
      001459 8D F0            [24] 4295 	mov	b,r5
      00145B EE               [12] 4296 	mov	a,r6
      00145C 42 F0            [12] 4297 	orl	b,a
      00145E EF               [12] 4298 	mov	a,r7
      00145F 42 F0            [12] 4299 	orl	b,a
      001461 EC               [12] 4300 	mov	a,r4
      001462 54 7F            [12] 4301 	anl	a,#0x7F
      001464 45 F0            [12] 4302 	orl	a,b
      001466 B4 01 00         [24] 4303 	cjne	a,#0x01,00160$
      001469                       4304 00160$:
      001469 B3               [12] 4305 	cpl	c
      00146A 92 00            [24] 4306 	mov	b0,c
      00146C E4               [12] 4307 	clr	a
      00146D 33               [12] 4308 	rlc	a
      00146E FB               [12] 4309 	mov	r3,a
                           0013B8  4310 	C$fuzzy.h$1936$2_0$87 ==.
                                   4311 ;	../../fuzzy.h:1936: parameters[1],
      00146F E5 08            [12] 4312 	mov	a,_bp
      001471 24 F4            [12] 4313 	add	a,#0xf4
      001473 F8               [12] 4314 	mov	r0,a
      001474 74 04            [12] 4315 	mov	a,#0x04
      001476 26               [12] 4316 	add	a, @r0
      001477 FC               [12] 4317 	mov	r4,a
      001478 E4               [12] 4318 	clr	a
      001479 08               [12] 4319 	inc	r0
      00147A 36               [12] 4320 	addc	a, @r0
      00147B FD               [12] 4321 	mov	r5,a
      00147C 08               [12] 4322 	inc	r0
      00147D 86 06            [24] 4323 	mov	ar6,@r0
      00147F 8C 82            [24] 4324 	mov	dpl,r4
      001481 8D 83            [24] 4325 	mov	dph,r5
      001483 8E F0            [24] 4326 	mov	b,r6
      001485 A8 08            [24] 4327 	mov	r0,_bp
      001487 08               [12] 4328 	inc	r0
      001488 12 37 EE         [24] 4329 	lcall	__gptrget
      00148B F6               [12] 4330 	mov	@r0,a
      00148C A3               [24] 4331 	inc	dptr
      00148D 12 37 EE         [24] 4332 	lcall	__gptrget
      001490 08               [12] 4333 	inc	r0
      001491 F6               [12] 4334 	mov	@r0,a
      001492 A3               [24] 4335 	inc	dptr
      001493 12 37 EE         [24] 4336 	lcall	__gptrget
      001496 08               [12] 4337 	inc	r0
      001497 F6               [12] 4338 	mov	@r0,a
      001498 A3               [24] 4339 	inc	dptr
      001499 12 37 EE         [24] 4340 	lcall	__gptrget
      00149C 08               [12] 4341 	inc	r0
      00149D F6               [12] 4342 	mov	@r0,a
                           0013E7  4343 	C$fuzzy.h$1935$2_0$87 ==.
                                   4344 ;	../../fuzzy.h:1935: parameters[0],
      00149E E5 08            [12] 4345 	mov	a,_bp
      0014A0 24 F4            [12] 4346 	add	a,#0xf4
      0014A2 F8               [12] 4347 	mov	r0,a
      0014A3 86 02            [24] 4348 	mov	ar2,@r0
      0014A5 08               [12] 4349 	inc	r0
      0014A6 86 06            [24] 4350 	mov	ar6,@r0
      0014A8 08               [12] 4351 	inc	r0
      0014A9 86 07            [24] 4352 	mov	ar7,@r0
      0014AB 8A 82            [24] 4353 	mov	dpl,r2
      0014AD 8E 83            [24] 4354 	mov	dph,r6
      0014AF 8F F0            [24] 4355 	mov	b,r7
      0014B1 12 37 EE         [24] 4356 	lcall	__gptrget
      0014B4 FA               [12] 4357 	mov	r2,a
      0014B5 A3               [24] 4358 	inc	dptr
      0014B6 12 37 EE         [24] 4359 	lcall	__gptrget
      0014B9 FE               [12] 4360 	mov	r6,a
      0014BA A3               [24] 4361 	inc	dptr
      0014BB 12 37 EE         [24] 4362 	lcall	__gptrget
      0014BE FF               [12] 4363 	mov	r7,a
      0014BF A3               [24] 4364 	inc	dptr
      0014C0 12 37 EE         [24] 4365 	lcall	__gptrget
      0014C3 FD               [12] 4366 	mov	r5,a
      0014C4 E5 08            [12] 4367 	mov	a,_bp
      0014C6 24 F9            [12] 4368 	add	a,#0xf9
      0014C8 F8               [12] 4369 	mov	r0,a
      0014C9 E6               [12] 4370 	mov	a,@r0
      0014CA C0 E0            [24] 4371 	push	acc
      0014CC C0 03            [24] 4372 	push	ar3
      0014CE E5 08            [12] 4373 	mov	a,_bp
      0014D0 24 FA            [12] 4374 	add	a,#0xfa
      0014D2 F8               [12] 4375 	mov	r0,a
      0014D3 E6               [12] 4376 	mov	a,@r0
      0014D4 C0 E0            [24] 4377 	push	acc
      0014D6 08               [12] 4378 	inc	r0
      0014D7 E6               [12] 4379 	mov	a,@r0
      0014D8 C0 E0            [24] 4380 	push	acc
      0014DA 08               [12] 4381 	inc	r0
      0014DB E6               [12] 4382 	mov	a,@r0
      0014DC C0 E0            [24] 4383 	push	acc
      0014DE 08               [12] 4384 	inc	r0
      0014DF E6               [12] 4385 	mov	a,@r0
      0014E0 C0 E0            [24] 4386 	push	acc
      0014E2 A8 08            [24] 4387 	mov	r0,_bp
      0014E4 08               [12] 4388 	inc	r0
      0014E5 E6               [12] 4389 	mov	a,@r0
      0014E6 C0 E0            [24] 4390 	push	acc
      0014E8 08               [12] 4391 	inc	r0
      0014E9 E6               [12] 4392 	mov	a,@r0
      0014EA C0 E0            [24] 4393 	push	acc
      0014EC 08               [12] 4394 	inc	r0
      0014ED E6               [12] 4395 	mov	a,@r0
      0014EE C0 E0            [24] 4396 	push	acc
      0014F0 08               [12] 4397 	inc	r0
      0014F1 E6               [12] 4398 	mov	a,@r0
      0014F2 C0 E0            [24] 4399 	push	acc
      0014F4 8A 82            [24] 4400 	mov	dpl, r2
      0014F6 8E 83            [24] 4401 	mov	dph, r6
      0014F8 8F F0            [24] 4402 	mov	b, r7
      0014FA ED               [12] 4403 	mov	a, r5
      0014FB 12 0A EC         [24] 4404 	lcall	_fuzzy_ramp
      0014FE AC 82            [24] 4405 	mov	r4, dpl
      001500 AD 83            [24] 4406 	mov	r5, dph
      001502 AE F0            [24] 4407 	mov	r6, b
      001504 FF               [12] 4408 	mov	r7, a
      001505 E5 81            [12] 4409 	mov	a,sp
      001507 24 F6            [12] 4410 	add	a,#0xf6
      001509 F5 81            [12] 4411 	mov	sp,a
      00150B 8C 82            [24] 4412 	mov	dpl, r4
      00150D 8D 83            [24] 4413 	mov	dph, r5
      00150F 8E F0            [24] 4414 	mov	b, r6
      001511 EF               [12] 4415 	mov	a, r7
      001512 02 17 67         [24] 4416 	ljmp	00123$
                           00145E  4417 	C$fuzzy.h$1942$2_0$87 ==.
                                   4418 ;	../../fuzzy.h:1942: case FUZZY_SHAPE_TRIANGLE:
      001515                       4419 00106$:
                           00145E  4420 	C$fuzzy.h$1943$2_0$87 ==.
                                   4421 ;	../../fuzzy.h:1943: if (parameter_count != 3u) {
      001515 E5 08            [12] 4422 	mov	a,_bp
      001517 24 F7            [12] 4423 	add	a,#0xf7
      001519 F8               [12] 4424 	mov	r0,a
      00151A B6 03 06         [24] 4425 	cjne	@r0,#0x03,00161$
      00151D 08               [12] 4426 	inc	r0
      00151E B6 00 02         [24] 4427 	cjne	@r0,#0x00,00161$
      001521 80 09            [24] 4428 	sjmp	00108$
      001523                       4429 00161$:
                           00146C  4430 	C$fuzzy.h$1944$3_0$89 ==.
                                   4431 ;	../../fuzzy.h:1944: return LEVEL_LO;
      001523 90 00 00         [24] 4432 	mov	dptr,#0x0000
      001526 E4               [12] 4433 	clr	a
      001527 F5 F0            [12] 4434 	mov	b,a
      001529 02 17 67         [24] 4435 	ljmp	00123$
      00152C                       4436 00108$:
                           001475  4437 	C$fuzzy.h$1950$2_0$87 ==.
                                   4438 ;	../../fuzzy.h:1950: parameters[2],
      00152C E5 08            [12] 4439 	mov	a,_bp
      00152E 24 F4            [12] 4440 	add	a,#0xf4
      001530 F8               [12] 4441 	mov	r0,a
      001531 74 08            [12] 4442 	mov	a,#0x08
      001533 26               [12] 4443 	add	a, @r0
      001534 FD               [12] 4444 	mov	r5,a
      001535 E4               [12] 4445 	clr	a
      001536 08               [12] 4446 	inc	r0
      001537 36               [12] 4447 	addc	a, @r0
      001538 FE               [12] 4448 	mov	r6,a
      001539 08               [12] 4449 	inc	r0
      00153A 86 07            [24] 4450 	mov	ar7,@r0
      00153C 8D 82            [24] 4451 	mov	dpl,r5
      00153E 8E 83            [24] 4452 	mov	dph,r6
      001540 8F F0            [24] 4453 	mov	b,r7
      001542 A8 08            [24] 4454 	mov	r0,_bp
      001544 08               [12] 4455 	inc	r0
      001545 12 37 EE         [24] 4456 	lcall	__gptrget
      001548 F6               [12] 4457 	mov	@r0,a
      001549 A3               [24] 4458 	inc	dptr
      00154A 12 37 EE         [24] 4459 	lcall	__gptrget
      00154D 08               [12] 4460 	inc	r0
      00154E F6               [12] 4461 	mov	@r0,a
      00154F A3               [24] 4462 	inc	dptr
      001550 12 37 EE         [24] 4463 	lcall	__gptrget
      001553 08               [12] 4464 	inc	r0
      001554 F6               [12] 4465 	mov	@r0,a
      001555 A3               [24] 4466 	inc	dptr
      001556 12 37 EE         [24] 4467 	lcall	__gptrget
      001559 08               [12] 4468 	inc	r0
      00155A F6               [12] 4469 	mov	@r0,a
                           0014A4  4470 	C$fuzzy.h$1949$2_0$87 ==.
                                   4471 ;	../../fuzzy.h:1949: parameters[1],
      00155B E5 08            [12] 4472 	mov	a,_bp
      00155D 24 F4            [12] 4473 	add	a,#0xf4
      00155F F8               [12] 4474 	mov	r0,a
      001560 74 04            [12] 4475 	mov	a,#0x04
      001562 26               [12] 4476 	add	a, @r0
      001563 FA               [12] 4477 	mov	r2,a
      001564 E4               [12] 4478 	clr	a
      001565 08               [12] 4479 	inc	r0
      001566 36               [12] 4480 	addc	a, @r0
      001567 FB               [12] 4481 	mov	r3,a
      001568 08               [12] 4482 	inc	r0
      001569 86 07            [24] 4483 	mov	ar7,@r0
      00156B 8A 82            [24] 4484 	mov	dpl,r2
      00156D 8B 83            [24] 4485 	mov	dph,r3
      00156F 8F F0            [24] 4486 	mov	b,r7
      001571 E5 08            [12] 4487 	mov	a,_bp
      001573 24 05            [12] 4488 	add	a,#0x05
      001575 F8               [12] 4489 	mov	r0,a
      001576 12 37 EE         [24] 4490 	lcall	__gptrget
      001579 F6               [12] 4491 	mov	@r0,a
      00157A A3               [24] 4492 	inc	dptr
      00157B 12 37 EE         [24] 4493 	lcall	__gptrget
      00157E 08               [12] 4494 	inc	r0
      00157F F6               [12] 4495 	mov	@r0,a
      001580 A3               [24] 4496 	inc	dptr
      001581 12 37 EE         [24] 4497 	lcall	__gptrget
      001584 08               [12] 4498 	inc	r0
      001585 F6               [12] 4499 	mov	@r0,a
      001586 A3               [24] 4500 	inc	dptr
      001587 12 37 EE         [24] 4501 	lcall	__gptrget
      00158A 08               [12] 4502 	inc	r0
      00158B F6               [12] 4503 	mov	@r0,a
                           0014D5  4504 	C$fuzzy.h$1948$2_0$87 ==.
                                   4505 ;	../../fuzzy.h:1948: parameters[0],
      00158C E5 08            [12] 4506 	mov	a,_bp
      00158E 24 F4            [12] 4507 	add	a,#0xf4
      001590 F8               [12] 4508 	mov	r0,a
      001591 86 04            [24] 4509 	mov	ar4,@r0
      001593 08               [12] 4510 	inc	r0
      001594 86 05            [24] 4511 	mov	ar5,@r0
      001596 08               [12] 4512 	inc	r0
      001597 86 07            [24] 4513 	mov	ar7,@r0
      001599 8C 82            [24] 4514 	mov	dpl,r4
      00159B 8D 83            [24] 4515 	mov	dph,r5
      00159D 8F F0            [24] 4516 	mov	b,r7
      00159F 12 37 EE         [24] 4517 	lcall	__gptrget
      0015A2 FC               [12] 4518 	mov	r4,a
      0015A3 A3               [24] 4519 	inc	dptr
      0015A4 12 37 EE         [24] 4520 	lcall	__gptrget
      0015A7 FD               [12] 4521 	mov	r5,a
      0015A8 A3               [24] 4522 	inc	dptr
      0015A9 12 37 EE         [24] 4523 	lcall	__gptrget
      0015AC FF               [12] 4524 	mov	r7,a
      0015AD A3               [24] 4525 	inc	dptr
      0015AE 12 37 EE         [24] 4526 	lcall	__gptrget
      0015B1 FE               [12] 4527 	mov	r6,a
      0015B2 E5 08            [12] 4528 	mov	a,_bp
      0015B4 24 F9            [12] 4529 	add	a,#0xf9
      0015B6 F8               [12] 4530 	mov	r0,a
      0015B7 E6               [12] 4531 	mov	a,@r0
      0015B8 C0 E0            [24] 4532 	push	acc
      0015BA E5 08            [12] 4533 	mov	a,_bp
      0015BC 24 FA            [12] 4534 	add	a,#0xfa
      0015BE F8               [12] 4535 	mov	r0,a
      0015BF E6               [12] 4536 	mov	a,@r0
      0015C0 C0 E0            [24] 4537 	push	acc
      0015C2 08               [12] 4538 	inc	r0
      0015C3 E6               [12] 4539 	mov	a,@r0
      0015C4 C0 E0            [24] 4540 	push	acc
      0015C6 08               [12] 4541 	inc	r0
      0015C7 E6               [12] 4542 	mov	a,@r0
      0015C8 C0 E0            [24] 4543 	push	acc
      0015CA 08               [12] 4544 	inc	r0
      0015CB E6               [12] 4545 	mov	a,@r0
      0015CC C0 E0            [24] 4546 	push	acc
      0015CE A8 08            [24] 4547 	mov	r0,_bp
      0015D0 08               [12] 4548 	inc	r0
      0015D1 E6               [12] 4549 	mov	a,@r0
      0015D2 C0 E0            [24] 4550 	push	acc
      0015D4 08               [12] 4551 	inc	r0
      0015D5 E6               [12] 4552 	mov	a,@r0
      0015D6 C0 E0            [24] 4553 	push	acc
      0015D8 08               [12] 4554 	inc	r0
      0015D9 E6               [12] 4555 	mov	a,@r0
      0015DA C0 E0            [24] 4556 	push	acc
      0015DC 08               [12] 4557 	inc	r0
      0015DD E6               [12] 4558 	mov	a,@r0
      0015DE C0 E0            [24] 4559 	push	acc
      0015E0 E5 08            [12] 4560 	mov	a,_bp
      0015E2 24 05            [12] 4561 	add	a,#0x05
      0015E4 F8               [12] 4562 	mov	r0,a
      0015E5 E6               [12] 4563 	mov	a,@r0
      0015E6 C0 E0            [24] 4564 	push	acc
      0015E8 08               [12] 4565 	inc	r0
      0015E9 E6               [12] 4566 	mov	a,@r0
      0015EA C0 E0            [24] 4567 	push	acc
      0015EC 08               [12] 4568 	inc	r0
      0015ED E6               [12] 4569 	mov	a,@r0
      0015EE C0 E0            [24] 4570 	push	acc
      0015F0 08               [12] 4571 	inc	r0
      0015F1 E6               [12] 4572 	mov	a,@r0
      0015F2 C0 E0            [24] 4573 	push	acc
      0015F4 8C 82            [24] 4574 	mov	dpl, r4
      0015F6 8D 83            [24] 4575 	mov	dph, r5
      0015F8 8F F0            [24] 4576 	mov	b, r7
      0015FA EE               [12] 4577 	mov	a, r6
      0015FB 12 0D 29         [24] 4578 	lcall	_fuzzy_triangle
      0015FE AC 82            [24] 4579 	mov	r4, dpl
      001600 AD 83            [24] 4580 	mov	r5, dph
      001602 AE F0            [24] 4581 	mov	r6, b
      001604 FF               [12] 4582 	mov	r7, a
      001605 E5 81            [12] 4583 	mov	a,sp
      001607 24 F3            [12] 4584 	add	a,#0xf3
      001609 F5 81            [12] 4585 	mov	sp,a
      00160B 8C 82            [24] 4586 	mov	dpl, r4
      00160D 8D 83            [24] 4587 	mov	dph, r5
      00160F 8E F0            [24] 4588 	mov	b, r6
      001611 EF               [12] 4589 	mov	a, r7
      001612 02 17 67         [24] 4590 	ljmp	00123$
                           00155E  4591 	C$fuzzy.h$1955$2_0$87 ==.
                                   4592 ;	../../fuzzy.h:1955: case FUZZY_SHAPE_TRAPEZOID:
      001615                       4593 00109$:
                           00155E  4594 	C$fuzzy.h$1956$2_0$87 ==.
                                   4595 ;	../../fuzzy.h:1956: if (parameter_count != 4u) {
      001615 E5 08            [12] 4596 	mov	a,_bp
      001617 24 F7            [12] 4597 	add	a,#0xf7
      001619 F8               [12] 4598 	mov	r0,a
      00161A B6 04 06         [24] 4599 	cjne	@r0,#0x04,00162$
      00161D 08               [12] 4600 	inc	r0
      00161E B6 00 02         [24] 4601 	cjne	@r0,#0x00,00162$
      001621 80 09            [24] 4602 	sjmp	00111$
      001623                       4603 00162$:
                           00156C  4604 	C$fuzzy.h$1957$3_0$90 ==.
                                   4605 ;	../../fuzzy.h:1957: return LEVEL_LO;
      001623 90 00 00         [24] 4606 	mov	dptr,#0x0000
      001626 E4               [12] 4607 	clr	a
      001627 F5 F0            [12] 4608 	mov	b,a
      001629 02 17 67         [24] 4609 	ljmp	00123$
      00162C                       4610 00111$:
                           001575  4611 	C$fuzzy.h$1964$2_0$87 ==.
                                   4612 ;	../../fuzzy.h:1964: parameters[3],
      00162C E5 08            [12] 4613 	mov	a,_bp
      00162E 24 F4            [12] 4614 	add	a,#0xf4
      001630 F8               [12] 4615 	mov	r0,a
      001631 74 0C            [12] 4616 	mov	a,#0x0c
      001633 26               [12] 4617 	add	a, @r0
      001634 FD               [12] 4618 	mov	r5,a
      001635 E4               [12] 4619 	clr	a
      001636 08               [12] 4620 	inc	r0
      001637 36               [12] 4621 	addc	a, @r0
      001638 FE               [12] 4622 	mov	r6,a
      001639 08               [12] 4623 	inc	r0
      00163A 86 07            [24] 4624 	mov	ar7,@r0
      00163C 8D 82            [24] 4625 	mov	dpl,r5
      00163E 8E 83            [24] 4626 	mov	dph,r6
      001640 8F F0            [24] 4627 	mov	b,r7
      001642 E5 08            [12] 4628 	mov	a,_bp
      001644 24 05            [12] 4629 	add	a,#0x05
      001646 F8               [12] 4630 	mov	r0,a
      001647 12 37 EE         [24] 4631 	lcall	__gptrget
      00164A F6               [12] 4632 	mov	@r0,a
      00164B A3               [24] 4633 	inc	dptr
      00164C 12 37 EE         [24] 4634 	lcall	__gptrget
      00164F 08               [12] 4635 	inc	r0
      001650 F6               [12] 4636 	mov	@r0,a
      001651 A3               [24] 4637 	inc	dptr
      001652 12 37 EE         [24] 4638 	lcall	__gptrget
      001655 08               [12] 4639 	inc	r0
      001656 F6               [12] 4640 	mov	@r0,a
      001657 A3               [24] 4641 	inc	dptr
      001658 12 37 EE         [24] 4642 	lcall	__gptrget
      00165B 08               [12] 4643 	inc	r0
      00165C F6               [12] 4644 	mov	@r0,a
                           0015A6  4645 	C$fuzzy.h$1963$2_0$87 ==.
                                   4646 ;	../../fuzzy.h:1963: parameters[2],
      00165D E5 08            [12] 4647 	mov	a,_bp
      00165F 24 F4            [12] 4648 	add	a,#0xf4
      001661 F8               [12] 4649 	mov	r0,a
      001662 74 08            [12] 4650 	mov	a,#0x08
      001664 26               [12] 4651 	add	a, @r0
      001665 FA               [12] 4652 	mov	r2,a
      001666 E4               [12] 4653 	clr	a
      001667 08               [12] 4654 	inc	r0
      001668 36               [12] 4655 	addc	a, @r0
      001669 FB               [12] 4656 	mov	r3,a
      00166A 08               [12] 4657 	inc	r0
      00166B 86 07            [24] 4658 	mov	ar7,@r0
      00166D 8A 82            [24] 4659 	mov	dpl,r2
      00166F 8B 83            [24] 4660 	mov	dph,r3
      001671 8F F0            [24] 4661 	mov	b,r7
      001673 A8 08            [24] 4662 	mov	r0,_bp
      001675 08               [12] 4663 	inc	r0
      001676 12 37 EE         [24] 4664 	lcall	__gptrget
      001679 F6               [12] 4665 	mov	@r0,a
      00167A A3               [24] 4666 	inc	dptr
      00167B 12 37 EE         [24] 4667 	lcall	__gptrget
      00167E 08               [12] 4668 	inc	r0
      00167F F6               [12] 4669 	mov	@r0,a
      001680 A3               [24] 4670 	inc	dptr
      001681 12 37 EE         [24] 4671 	lcall	__gptrget
      001684 08               [12] 4672 	inc	r0
      001685 F6               [12] 4673 	mov	@r0,a
      001686 A3               [24] 4674 	inc	dptr
      001687 12 37 EE         [24] 4675 	lcall	__gptrget
      00168A 08               [12] 4676 	inc	r0
      00168B F6               [12] 4677 	mov	@r0,a
                           0015D5  4678 	C$fuzzy.h$1962$2_0$87 ==.
                                   4679 ;	../../fuzzy.h:1962: parameters[1],
      00168C E5 08            [12] 4680 	mov	a,_bp
      00168E 24 F4            [12] 4681 	add	a,#0xf4
      001690 F8               [12] 4682 	mov	r0,a
      001691 74 04            [12] 4683 	mov	a,#0x04
      001693 26               [12] 4684 	add	a, @r0
      001694 FC               [12] 4685 	mov	r4,a
      001695 E4               [12] 4686 	clr	a
      001696 08               [12] 4687 	inc	r0
      001697 36               [12] 4688 	addc	a, @r0
      001698 FD               [12] 4689 	mov	r5,a
      001699 08               [12] 4690 	inc	r0
      00169A 86 07            [24] 4691 	mov	ar7,@r0
      00169C 8C 82            [24] 4692 	mov	dpl,r4
      00169E 8D 83            [24] 4693 	mov	dph,r5
      0016A0 8F F0            [24] 4694 	mov	b,r7
      0016A2 E5 08            [12] 4695 	mov	a,_bp
      0016A4 24 09            [12] 4696 	add	a,#0x09
      0016A6 F8               [12] 4697 	mov	r0,a
      0016A7 12 37 EE         [24] 4698 	lcall	__gptrget
      0016AA F6               [12] 4699 	mov	@r0,a
      0016AB A3               [24] 4700 	inc	dptr
      0016AC 12 37 EE         [24] 4701 	lcall	__gptrget
      0016AF 08               [12] 4702 	inc	r0
      0016B0 F6               [12] 4703 	mov	@r0,a
      0016B1 A3               [24] 4704 	inc	dptr
      0016B2 12 37 EE         [24] 4705 	lcall	__gptrget
      0016B5 08               [12] 4706 	inc	r0
      0016B6 F6               [12] 4707 	mov	@r0,a
      0016B7 A3               [24] 4708 	inc	dptr
      0016B8 12 37 EE         [24] 4709 	lcall	__gptrget
      0016BB 08               [12] 4710 	inc	r0
      0016BC F6               [12] 4711 	mov	@r0,a
                           001606  4712 	C$fuzzy.h$1961$2_0$87 ==.
                                   4713 ;	../../fuzzy.h:1961: parameters[0],
      0016BD E5 08            [12] 4714 	mov	a,_bp
      0016BF 24 F4            [12] 4715 	add	a,#0xf4
      0016C1 F8               [12] 4716 	mov	r0,a
      0016C2 86 02            [24] 4717 	mov	ar2,@r0
      0016C4 08               [12] 4718 	inc	r0
      0016C5 86 03            [24] 4719 	mov	ar3,@r0
      0016C7 08               [12] 4720 	inc	r0
      0016C8 86 07            [24] 4721 	mov	ar7,@r0
      0016CA 8A 82            [24] 4722 	mov	dpl,r2
      0016CC 8B 83            [24] 4723 	mov	dph,r3
      0016CE 8F F0            [24] 4724 	mov	b,r7
      0016D0 12 37 EE         [24] 4725 	lcall	__gptrget
      0016D3 FA               [12] 4726 	mov	r2,a
      0016D4 A3               [24] 4727 	inc	dptr
      0016D5 12 37 EE         [24] 4728 	lcall	__gptrget
      0016D8 FB               [12] 4729 	mov	r3,a
      0016D9 A3               [24] 4730 	inc	dptr
      0016DA 12 37 EE         [24] 4731 	lcall	__gptrget
      0016DD FF               [12] 4732 	mov	r7,a
      0016DE A3               [24] 4733 	inc	dptr
      0016DF 12 37 EE         [24] 4734 	lcall	__gptrget
      0016E2 FE               [12] 4735 	mov	r6,a
      0016E3 E5 08            [12] 4736 	mov	a,_bp
      0016E5 24 F9            [12] 4737 	add	a,#0xf9
      0016E7 F8               [12] 4738 	mov	r0,a
      0016E8 E6               [12] 4739 	mov	a,@r0
      0016E9 C0 E0            [24] 4740 	push	acc
      0016EB E5 08            [12] 4741 	mov	a,_bp
      0016ED 24 FA            [12] 4742 	add	a,#0xfa
      0016EF F8               [12] 4743 	mov	r0,a
      0016F0 E6               [12] 4744 	mov	a,@r0
      0016F1 C0 E0            [24] 4745 	push	acc
      0016F3 08               [12] 4746 	inc	r0
      0016F4 E6               [12] 4747 	mov	a,@r0
      0016F5 C0 E0            [24] 4748 	push	acc
      0016F7 08               [12] 4749 	inc	r0
      0016F8 E6               [12] 4750 	mov	a,@r0
      0016F9 C0 E0            [24] 4751 	push	acc
      0016FB 08               [12] 4752 	inc	r0
      0016FC E6               [12] 4753 	mov	a,@r0
      0016FD C0 E0            [24] 4754 	push	acc
      0016FF E5 08            [12] 4755 	mov	a,_bp
      001701 24 05            [12] 4756 	add	a,#0x05
      001703 F8               [12] 4757 	mov	r0,a
      001704 E6               [12] 4758 	mov	a,@r0
      001705 C0 E0            [24] 4759 	push	acc
      001707 08               [12] 4760 	inc	r0
      001708 E6               [12] 4761 	mov	a,@r0
      001709 C0 E0            [24] 4762 	push	acc
      00170B 08               [12] 4763 	inc	r0
      00170C E6               [12] 4764 	mov	a,@r0
      00170D C0 E0            [24] 4765 	push	acc
      00170F 08               [12] 4766 	inc	r0
      001710 E6               [12] 4767 	mov	a,@r0
      001711 C0 E0            [24] 4768 	push	acc
      001713 A8 08            [24] 4769 	mov	r0,_bp
      001715 08               [12] 4770 	inc	r0
      001716 E6               [12] 4771 	mov	a,@r0
      001717 C0 E0            [24] 4772 	push	acc
      001719 08               [12] 4773 	inc	r0
      00171A E6               [12] 4774 	mov	a,@r0
      00171B C0 E0            [24] 4775 	push	acc
      00171D 08               [12] 4776 	inc	r0
      00171E E6               [12] 4777 	mov	a,@r0
      00171F C0 E0            [24] 4778 	push	acc
      001721 08               [12] 4779 	inc	r0
      001722 E6               [12] 4780 	mov	a,@r0
      001723 C0 E0            [24] 4781 	push	acc
      001725 E5 08            [12] 4782 	mov	a,_bp
      001727 24 09            [12] 4783 	add	a,#0x09
      001729 F8               [12] 4784 	mov	r0,a
      00172A E6               [12] 4785 	mov	a,@r0
      00172B C0 E0            [24] 4786 	push	acc
      00172D 08               [12] 4787 	inc	r0
      00172E E6               [12] 4788 	mov	a,@r0
      00172F C0 E0            [24] 4789 	push	acc
      001731 08               [12] 4790 	inc	r0
      001732 E6               [12] 4791 	mov	a,@r0
      001733 C0 E0            [24] 4792 	push	acc
      001735 08               [12] 4793 	inc	r0
      001736 E6               [12] 4794 	mov	a,@r0
      001737 C0 E0            [24] 4795 	push	acc
      001739 8A 82            [24] 4796 	mov	dpl, r2
      00173B 8B 83            [24] 4797 	mov	dph, r3
      00173D 8F F0            [24] 4798 	mov	b, r7
      00173F EE               [12] 4799 	mov	a, r6
      001740 12 10 35         [24] 4800 	lcall	_fuzzy_trapezoid
      001743 AC 82            [24] 4801 	mov	r4, dpl
      001745 AD 83            [24] 4802 	mov	r5, dph
      001747 AE F0            [24] 4803 	mov	r6, b
      001749 FF               [12] 4804 	mov	r7, a
      00174A E5 81            [12] 4805 	mov	a,sp
      00174C 24 EF            [12] 4806 	add	a,#0xef
      00174E F5 81            [12] 4807 	mov	sp,a
      001750 8C 82            [24] 4808 	mov	dpl, r4
      001752 8D 83            [24] 4809 	mov	dph, r5
      001754 8E F0            [24] 4810 	mov	b, r6
      001756 EF               [12] 4811 	mov	a, r7
                           0016A0  4812 	C$fuzzy.h$2098$2_0$87 ==.
                                   4813 ;	../../fuzzy.h:2098: case FUZZY_SHAPE_PSIGMOID:
      001757 80 0E            [24] 4814 	sjmp	00123$
      001759                       4815 00120$:
                           0016A2  4816 	C$fuzzy.h$2099$2_0$87 ==.
                                   4817 ;	../../fuzzy.h:2099: return LEVEL_LO;
      001759 90 00 00         [24] 4818 	mov	dptr,#0x0000
      00175C E4               [12] 4819 	clr	a
      00175D F5 F0            [12] 4820 	mov	b,a
                           0016A8  4821 	C$fuzzy.h$2103$2_0$87 ==.
                                   4822 ;	../../fuzzy.h:2103: default:
      00175F 80 06            [24] 4823 	sjmp	00123$
      001761                       4824 00121$:
                           0016AA  4825 	C$fuzzy.h$2104$2_0$87 ==.
                                   4826 ;	../../fuzzy.h:2104: return LEVEL_LO;
      001761 90 00 00         [24] 4827 	mov	dptr,#0x0000
      001764 E4               [12] 4828 	clr	a
      001765 F5 F0            [12] 4829 	mov	b,a
                           0016B0  4830 	C$fuzzy.h$2105$1_0$85 ==.
                                   4831 ;	../../fuzzy.h:2105: }
      001767                       4832 00123$:
                           0016B0  4833 	C$fuzzy.h$2106$1_0$85 ==.
                                   4834 ;	../../fuzzy.h:2106: }
      001767 85 08 81         [24] 4835 	mov	sp,_bp
      00176A D0 08            [24] 4836 	pop	_bp
                           0016B5  4837 	C$fuzzy.h$2106$1_0$85 ==.
                           0016B5  4838 	XG$fuzzy_function_array$0$0 ==.
      00176C 22               [24] 4839 	ret
                                   4840 ;------------------------------------------------------------
                                   4841 ;Allocation info for local variables in function 'fuzzy_rules_add'
                                   4842 ;------------------------------------------------------------
                                   4843 ;name          Allocated to stack - _bp -5 +3 
                                   4844 ;value         Allocated to stack - _bp -9 +4 
                                   4845 ;output_function Allocated to stack - _bp -11 +2 
                                   4846 ;rules         Allocated to registers r2 r3 r4 
                                   4847 ;index         Allocated to registers 
                                   4848 ;sloc0         Allocated to stack - _bp +1 +2 
                                   4849 ;sloc1         Allocated to stack - _bp +3 +3 
                                   4850 ;sloc2         Allocated to stack - _bp +6 +3 
                                   4851 ;sloc3         Allocated to stack - _bp +9 +3 
                                   4852 ;------------------------------------------------------------
                           0016B6  4853 	G$fuzzy_rules_add$0$0 ==.
                           0016B6  4854 	C$fuzzy.h$2108$1_0$92 ==.
                                   4855 ;	../../fuzzy.h:2108: bool fuzzy_rules_add(
                                   4856 ;	-----------------------------------------
                                   4857 ;	 function fuzzy_rules_add
                                   4858 ;	-----------------------------------------
      00176D                       4859 _fuzzy_rules_add:
      00176D C0 08            [24] 4860 	push	_bp
      00176F E5 81            [12] 4861 	mov	a,sp
      001771 F5 08            [12] 4862 	mov	_bp,a
      001773 24 0B            [12] 4863 	add	a,#0x0b
      001775 F5 81            [12] 4864 	mov	sp,a
      001777 AA 82            [24] 4865 	mov	r2, dpl
      001779 AB 83            [24] 4866 	mov	r3, dph
      00177B AC F0            [24] 4867 	mov	r4, b
                           0016C6  4868 	C$fuzzy.h$2118$1_0$92 ==.
                                   4869 ;	../../fuzzy.h:2118: rules == NULL ||
      00177D EA               [12] 4870 	mov	a,r2
      00177E 4B               [12] 4871 	orl	a,r3
      00177F 60 0A            [24] 4872 	jz	00101$
                           0016CA  4873 	C$fuzzy.h$2119$1_0$92 ==.
                                   4874 ;	../../fuzzy.h:2119: output_function == NULL
      001781 E5 08            [12] 4875 	mov	a,_bp
      001783 24 F5            [12] 4876 	add	a,#0xf5
      001785 F8               [12] 4877 	mov	r0,a
      001786 E6               [12] 4878 	mov	a,@r0
      001787 08               [12] 4879 	inc	r0
      001788 46               [12] 4880 	orl	a,@r0
      001789 70 06            [24] 4881 	jnz	00102$
      00178B                       4882 00101$:
                           0016D4  4883 	C$fuzzy.h$2121$2_0$93 ==.
                                   4884 ;	../../fuzzy.h:2121: return false;
      00178B 75 82 00         [24] 4885 	mov	dpl, #0x00
      00178E 02 18 CB         [24] 4886 	ljmp	00106$
      001791                       4887 00102$:
                           0016DA  4888 	C$fuzzy.h$2124$1_0$92 ==.
                                   4889 ;	../../fuzzy.h:2124: if (rules->count >= FUZZY_MAX_RULES) {
      001791 E5 08            [12] 4890 	mov	a,_bp
      001793 24 09            [12] 4891 	add	a,#0x09
      001795 F8               [12] 4892 	mov	r0,a
      001796 74 90            [12] 4893 	mov	a,#0x90
      001798 2A               [12] 4894 	add	a, r2
      001799 F6               [12] 4895 	mov	@r0,a
      00179A E4               [12] 4896 	clr	a
      00179B 3B               [12] 4897 	addc	a, r3
      00179C 08               [12] 4898 	inc	r0
      00179D F6               [12] 4899 	mov	@r0,a
      00179E 08               [12] 4900 	inc	r0
      00179F A6 04            [24] 4901 	mov	@r0,ar4
      0017A1 E5 08            [12] 4902 	mov	a,_bp
      0017A3 24 09            [12] 4903 	add	a,#0x09
      0017A5 F8               [12] 4904 	mov	r0,a
      0017A6 86 82            [24] 4905 	mov	dpl,@r0
      0017A8 08               [12] 4906 	inc	r0
      0017A9 86 83            [24] 4907 	mov	dph,@r0
      0017AB 08               [12] 4908 	inc	r0
      0017AC 86 F0            [24] 4909 	mov	b,@r0
      0017AE 12 37 EE         [24] 4910 	lcall	__gptrget
      0017B1 FF               [12] 4911 	mov	r7,a
      0017B2 A3               [24] 4912 	inc	dptr
      0017B3 12 37 EE         [24] 4913 	lcall	__gptrget
      0017B6 FE               [12] 4914 	mov	r6,a
      0017B7 C3               [12] 4915 	clr	c
      0017B8 EF               [12] 4916 	mov	a,r7
      0017B9 94 10            [12] 4917 	subb	a,#0x10
      0017BB EE               [12] 4918 	mov	a,r6
      0017BC 94 00            [12] 4919 	subb	a,#0x00
      0017BE 40 06            [24] 4920 	jc	00105$
                           001709  4921 	C$fuzzy.h$2125$2_0$94 ==.
                                   4922 ;	../../fuzzy.h:2125: return false;
      0017C0 75 82 00         [24] 4923 	mov	dpl, #0x00
      0017C3 02 18 CB         [24] 4924 	ljmp	00106$
      0017C6                       4925 00105$:
                           00170F  4926 	C$fuzzy.h$2131$1_0$92 ==.
                                   4927 ;	../../fuzzy.h:2131: rules->rules[index].name =
      0017C6 C0 04            [24] 4928 	push	ar4
      0017C8 C0 03            [24] 4929 	push	ar3
      0017CA C0 02            [24] 4930 	push	ar2
      0017CC C0 07            [24] 4931 	push	ar7
      0017CE C0 06            [24] 4932 	push	ar6
      0017D0 90 00 09         [24] 4933 	mov	dptr,#0x0009
      0017D3 12 35 F2         [24] 4934 	lcall	__mulint
      0017D6 A8 08            [24] 4935 	mov	r0,_bp
      0017D8 08               [12] 4936 	inc	r0
      0017D9 A6 82            [24] 4937 	mov	@r0, dpl
      0017DB 08               [12] 4938 	inc	r0
      0017DC A6 83            [24] 4939 	mov	@r0, dph
      0017DE 15 81            [12] 4940 	dec	sp
      0017E0 15 81            [12] 4941 	dec	sp
      0017E2 D0 02            [24] 4942 	pop	ar2
      0017E4 D0 03            [24] 4943 	pop	ar3
      0017E6 D0 04            [24] 4944 	pop	ar4
      0017E8 A8 08            [24] 4945 	mov	r0,_bp
      0017EA 08               [12] 4946 	inc	r0
      0017EB E6               [12] 4947 	mov	a,@r0
      0017EC 2A               [12] 4948 	add	a, r2
      0017ED FD               [12] 4949 	mov	r5,a
      0017EE 08               [12] 4950 	inc	r0
      0017EF E6               [12] 4951 	mov	a,@r0
      0017F0 3B               [12] 4952 	addc	a, r3
      0017F1 FE               [12] 4953 	mov	r6,a
      0017F2 8C 07            [24] 4954 	mov	ar7,r4
      0017F4 8D 82            [24] 4955 	mov	dpl,r5
      0017F6 8E 83            [24] 4956 	mov	dph,r6
      0017F8 8F F0            [24] 4957 	mov	b,r7
      0017FA E5 08            [12] 4958 	mov	a,_bp
      0017FC 24 FB            [12] 4959 	add	a,#0xfb
      0017FE F8               [12] 4960 	mov	r0,a
      0017FF E6               [12] 4961 	mov	a,@r0
      001800 12 35 A7         [24] 4962 	lcall	__gptrput
      001803 A3               [24] 4963 	inc	dptr
      001804 08               [12] 4964 	inc	r0
      001805 E6               [12] 4965 	mov	a,@r0
      001806 12 35 A7         [24] 4966 	lcall	__gptrput
      001809 A3               [24] 4967 	inc	dptr
      00180A 08               [12] 4968 	inc	r0
      00180B E6               [12] 4969 	mov	a,@r0
      00180C 12 35 A7         [24] 4970 	lcall	__gptrput
                           001758  4971 	C$fuzzy.h$2134$1_0$92 ==.
                                   4972 ;	../../fuzzy.h:2134: rules->rules[index].value =
      00180F A8 08            [24] 4973 	mov	r0,_bp
      001811 08               [12] 4974 	inc	r0
      001812 E5 08            [12] 4975 	mov	a,_bp
      001814 24 03            [12] 4976 	add	a,#0x03
      001816 F9               [12] 4977 	mov	r1,a
      001817 E6               [12] 4978 	mov	a,@r0
      001818 2A               [12] 4979 	add	a, r2
      001819 F7               [12] 4980 	mov	@r1,a
      00181A 08               [12] 4981 	inc	r0
      00181B E6               [12] 4982 	mov	a,@r0
      00181C 3B               [12] 4983 	addc	a, r3
      00181D 09               [12] 4984 	inc	r1
      00181E F7               [12] 4985 	mov	@r1,a
      00181F 09               [12] 4986 	inc	r1
      001820 A7 04            [24] 4987 	mov	@r1,ar4
      001822 E5 08            [12] 4988 	mov	a,_bp
      001824 24 03            [12] 4989 	add	a,#0x03
      001826 F8               [12] 4990 	mov	r0,a
      001827 E5 08            [12] 4991 	mov	a,_bp
      001829 24 06            [12] 4992 	add	a,#0x06
      00182B F9               [12] 4993 	mov	r1,a
      00182C 74 03            [12] 4994 	mov	a,#0x03
      00182E 26               [12] 4995 	add	a, @r0
      00182F F7               [12] 4996 	mov	@r1,a
      001830 E4               [12] 4997 	clr	a
      001831 08               [12] 4998 	inc	r0
      001832 36               [12] 4999 	addc	a, @r0
      001833 09               [12] 5000 	inc	r1
      001834 F7               [12] 5001 	mov	@r1,a
      001835 08               [12] 5002 	inc	r0
      001836 E6               [12] 5003 	mov	a,@r0
      001837 09               [12] 5004 	inc	r1
      001838 F7               [12] 5005 	mov	@r1,a
                           001782  5006 	C$fuzzy.h$2135$1_0$92 ==.
                                   5007 ;	../../fuzzy.h:2135: fuzzy_clamp(value);
      001839 E5 08            [12] 5008 	mov	a,_bp
      00183B 24 F7            [12] 5009 	add	a,#0xf7
      00183D F8               [12] 5010 	mov	r0,a
      00183E 86 82            [24] 5011 	mov	dpl, @r0
      001840 08               [12] 5012 	inc	r0
      001841 86 83            [24] 5013 	mov	dph, @r0
      001843 08               [12] 5014 	inc	r0
      001844 86 F0            [24] 5015 	mov	b, @r0
      001846 08               [12] 5016 	inc	r0
      001847 E6               [12] 5017 	mov	a, @r0
      001848 12 00 EA         [24] 5018 	lcall	_fuzzy_clamp
      00184B AD 82            [24] 5019 	mov	r5, dpl
      00184D AE 83            [24] 5020 	mov	r6, dph
      00184F AC F0            [24] 5021 	mov	r4, b
      001851 FF               [12] 5022 	mov	r7, a
      001852 E5 08            [12] 5023 	mov	a,_bp
      001854 24 06            [12] 5024 	add	a,#0x06
      001856 F8               [12] 5025 	mov	r0,a
      001857 86 82            [24] 5026 	mov	dpl,@r0
      001859 08               [12] 5027 	inc	r0
      00185A 86 83            [24] 5028 	mov	dph,@r0
      00185C 08               [12] 5029 	inc	r0
      00185D 86 F0            [24] 5030 	mov	b,@r0
      00185F ED               [12] 5031 	mov	a,r5
      001860 12 35 A7         [24] 5032 	lcall	__gptrput
      001863 A3               [24] 5033 	inc	dptr
      001864 EE               [12] 5034 	mov	a,r6
      001865 12 35 A7         [24] 5035 	lcall	__gptrput
      001868 A3               [24] 5036 	inc	dptr
      001869 EC               [12] 5037 	mov	a,r4
      00186A 12 35 A7         [24] 5038 	lcall	__gptrput
      00186D A3               [24] 5039 	inc	dptr
      00186E EF               [12] 5040 	mov	a,r7
      00186F 12 35 A7         [24] 5041 	lcall	__gptrput
                           0017BB  5042 	C$fuzzy.h$2137$1_0$92 ==.
                                   5043 ;	../../fuzzy.h:2137: rules->rules[index].output_function =
      001872 E5 08            [12] 5044 	mov	a,_bp
      001874 24 03            [12] 5045 	add	a,#0x03
      001876 F8               [12] 5046 	mov	r0,a
      001877 74 07            [12] 5047 	mov	a,#0x07
      001879 26               [12] 5048 	add	a, @r0
      00187A FD               [12] 5049 	mov	r5,a
      00187B E4               [12] 5050 	clr	a
      00187C 08               [12] 5051 	inc	r0
      00187D 36               [12] 5052 	addc	a, @r0
      00187E FE               [12] 5053 	mov	r6,a
      00187F 08               [12] 5054 	inc	r0
      001880 86 07            [24] 5055 	mov	ar7,@r0
      001882 8D 82            [24] 5056 	mov	dpl,r5
      001884 8E 83            [24] 5057 	mov	dph,r6
      001886 8F F0            [24] 5058 	mov	b,r7
      001888 E5 08            [12] 5059 	mov	a,_bp
      00188A 24 F5            [12] 5060 	add	a,#0xf5
      00188C F8               [12] 5061 	mov	r0,a
      00188D E6               [12] 5062 	mov	a,@r0
      00188E 12 35 A7         [24] 5063 	lcall	__gptrput
      001891 A3               [24] 5064 	inc	dptr
      001892 08               [12] 5065 	inc	r0
      001893 E6               [12] 5066 	mov	a,@r0
      001894 12 35 A7         [24] 5067 	lcall	__gptrput
                           0017E0  5068 	C$fuzzy.h$2140$1_0$92 ==.
                                   5069 ;	../../fuzzy.h:2140: rules->count++;
      001897 E5 08            [12] 5070 	mov	a,_bp
      001899 24 09            [12] 5071 	add	a,#0x09
      00189B F8               [12] 5072 	mov	r0,a
      00189C 86 82            [24] 5073 	mov	dpl,@r0
      00189E 08               [12] 5074 	inc	r0
      00189F 86 83            [24] 5075 	mov	dph,@r0
      0018A1 08               [12] 5076 	inc	r0
      0018A2 86 F0            [24] 5077 	mov	b,@r0
      0018A4 12 37 EE         [24] 5078 	lcall	__gptrget
      0018A7 FE               [12] 5079 	mov	r6,a
      0018A8 A3               [24] 5080 	inc	dptr
      0018A9 12 37 EE         [24] 5081 	lcall	__gptrget
      0018AC FF               [12] 5082 	mov	r7,a
      0018AD 0E               [12] 5083 	inc	r6
      0018AE BE 00 01         [24] 5084 	cjne	r6,#0x00,00123$
      0018B1 0F               [12] 5085 	inc	r7
      0018B2                       5086 00123$:
      0018B2 E5 08            [12] 5087 	mov	a,_bp
      0018B4 24 09            [12] 5088 	add	a,#0x09
      0018B6 F8               [12] 5089 	mov	r0,a
      0018B7 86 82            [24] 5090 	mov	dpl,@r0
      0018B9 08               [12] 5091 	inc	r0
      0018BA 86 83            [24] 5092 	mov	dph,@r0
      0018BC 08               [12] 5093 	inc	r0
      0018BD 86 F0            [24] 5094 	mov	b,@r0
      0018BF EE               [12] 5095 	mov	a,r6
      0018C0 12 35 A7         [24] 5096 	lcall	__gptrput
      0018C3 A3               [24] 5097 	inc	dptr
      0018C4 EF               [12] 5098 	mov	a,r7
      0018C5 12 35 A7         [24] 5099 	lcall	__gptrput
                           001811  5100 	C$fuzzy.h$2142$1_0$92 ==.
                                   5101 ;	../../fuzzy.h:2142: return true;
      0018C8 75 82 01         [24] 5102 	mov	dpl, #0x01
      0018CB                       5103 00106$:
                           001814  5104 	C$fuzzy.h$2143$1_0$92 ==.
                                   5105 ;	../../fuzzy.h:2143: }
      0018CB 85 08 81         [24] 5106 	mov	sp,_bp
      0018CE D0 08            [24] 5107 	pop	_bp
                           001819  5108 	C$fuzzy.h$2143$1_0$92 ==.
                           001819  5109 	XG$fuzzy_rules_add$0$0 ==.
      0018D0 22               [24] 5110 	ret
                                   5111 ;------------------------------------------------------------
                                   5112 ;Allocation info for local variables in function 'fuzzy_implication'
                                   5113 ;------------------------------------------------------------
                                   5114 ;activation    Allocated to stack - _bp -6 +4 
                                   5115 ;membership    Allocated to stack - _bp -10 +4 
                                   5116 ;method        Allocated to registers r7 
                                   5117 ;sloc0         Allocated to stack - _bp +1 +4 
                                   5118 ;sloc1         Allocated to stack - _bp +5 +4 
                                   5119 ;------------------------------------------------------------
                           00181A  5120 	Fcontroller_8051$fuzzy_implication$0$0 ==.
                           00181A  5121 	C$fuzzy.h$2176$1_0$96 ==.
                                   5122 ;	../../fuzzy.h:2176: static float fuzzy_implication(
                                   5123 ;	-----------------------------------------
                                   5124 ;	 function fuzzy_implication
                                   5125 ;	-----------------------------------------
      0018D1                       5126 _fuzzy_implication:
      0018D1 C0 08            [24] 5127 	push	_bp
      0018D3 E5 81            [12] 5128 	mov	a,sp
      0018D5 F5 08            [12] 5129 	mov	_bp,a
      0018D7 24 08            [12] 5130 	add	a,#0x08
      0018D9 F5 81            [12] 5131 	mov	sp,a
      0018DB AF 82            [24] 5132 	mov	r7, dpl
                           001826  5133 	C$fuzzy.h$2182$1_0$96 ==.
                                   5134 ;	../../fuzzy.h:2182: activation = fuzzy_clamp(activation);
      0018DD E5 08            [12] 5135 	mov	a,_bp
      0018DF 24 FA            [12] 5136 	add	a,#0xfa
      0018E1 F8               [12] 5137 	mov	r0,a
      0018E2 86 82            [24] 5138 	mov	dpl, @r0
      0018E4 08               [12] 5139 	inc	r0
      0018E5 86 83            [24] 5140 	mov	dph, @r0
      0018E7 08               [12] 5141 	inc	r0
      0018E8 86 F0            [24] 5142 	mov	b, @r0
      0018EA 08               [12] 5143 	inc	r0
      0018EB E6               [12] 5144 	mov	a, @r0
      0018EC C0 07            [24] 5145 	push	ar7
      0018EE 12 00 EA         [24] 5146 	lcall	_fuzzy_clamp
      0018F1 AB 82            [24] 5147 	mov	r3, dpl
      0018F3 AC 83            [24] 5148 	mov	r4, dph
      0018F5 AD F0            [24] 5149 	mov	r5, b
      0018F7 FE               [12] 5150 	mov	r6, a
                           001841  5151 	C$fuzzy.h$2183$1_0$96 ==.
                                   5152 ;	../../fuzzy.h:2183: membership = fuzzy_clamp(membership);
      0018F8 E5 08            [12] 5153 	mov	a,_bp
      0018FA 24 F6            [12] 5154 	add	a,#0xf6
      0018FC F8               [12] 5155 	mov	r0,a
      0018FD 86 82            [24] 5156 	mov	dpl, @r0
      0018FF 08               [12] 5157 	inc	r0
      001900 86 83            [24] 5158 	mov	dph, @r0
      001902 08               [12] 5159 	inc	r0
      001903 86 F0            [24] 5160 	mov	b, @r0
      001905 08               [12] 5161 	inc	r0
      001906 E6               [12] 5162 	mov	a, @r0
      001907 C0 06            [24] 5163 	push	ar6
      001909 C0 05            [24] 5164 	push	ar5
      00190B C0 04            [24] 5165 	push	ar4
      00190D C0 03            [24] 5166 	push	ar3
      00190F 12 00 EA         [24] 5167 	lcall	_fuzzy_clamp
      001912 A8 08            [24] 5168 	mov	r0,_bp
      001914 08               [12] 5169 	inc	r0
      001915 A6 82            [24] 5170 	mov	@r0, dpl
      001917 08               [12] 5171 	inc	r0
      001918 A6 83            [24] 5172 	mov	@r0, dph
      00191A 08               [12] 5173 	inc	r0
      00191B A6 F0            [24] 5174 	mov	@r0, b
      00191D 08               [12] 5175 	inc	r0
      00191E F6               [12] 5176 	mov	@r0,a
      00191F D0 03            [24] 5177 	pop	ar3
      001921 D0 04            [24] 5178 	pop	ar4
      001923 D0 05            [24] 5179 	pop	ar5
      001925 D0 06            [24] 5180 	pop	ar6
      001927 D0 07            [24] 5181 	pop	ar7
                           001872  5182 	C$fuzzy.h$2185$1_0$96 ==.
                                   5183 ;	../../fuzzy.h:2185: switch (method) {
      001929 BF 00 02         [24] 5184 	cjne	r7,#0x00,00127$
      00192C 80 08            [24] 5185 	sjmp	00101$
      00192E                       5186 00127$:
      00192E BF 01 02         [24] 5187 	cjne	r7,#0x01,00128$
      001931 80 73            [24] 5188 	sjmp	00102$
      001933                       5189 00128$:
      001933 02 19 D8         [24] 5190 	ljmp	00103$
                           00187F  5191 	C$fuzzy.h$2186$2_0$97 ==.
                                   5192 ;	../../fuzzy.h:2186: case FUZZY_IMPLICATION_MIN:
      001936                       5193 00101$:
                           00187F  5194 	C$fuzzy.h$2188$1_0$96 ==.
                                   5195 ;	../../fuzzy.h:2188: ? activation
      001936 C0 06            [24] 5196 	push	ar6
      001938 C0 05            [24] 5197 	push	ar5
      00193A C0 04            [24] 5198 	push	ar4
      00193C C0 03            [24] 5199 	push	ar3
      00193E A8 08            [24] 5200 	mov	r0,_bp
      001940 08               [12] 5201 	inc	r0
      001941 E6               [12] 5202 	mov	a,@r0
      001942 C0 E0            [24] 5203 	push	acc
      001944 08               [12] 5204 	inc	r0
      001945 E6               [12] 5205 	mov	a,@r0
      001946 C0 E0            [24] 5206 	push	acc
      001948 08               [12] 5207 	inc	r0
      001949 E6               [12] 5208 	mov	a,@r0
      00194A C0 E0            [24] 5209 	push	acc
      00194C 08               [12] 5210 	inc	r0
      00194D E6               [12] 5211 	mov	a,@r0
      00194E C0 E0            [24] 5212 	push	acc
      001950 8B 82            [24] 5213 	mov	dpl, r3
      001952 8C 83            [24] 5214 	mov	dph, r4
      001954 8D F0            [24] 5215 	mov	b, r5
      001956 EE               [12] 5216 	mov	a, r6
      001957 12 35 C2         [24] 5217 	lcall	___fslt
      00195A AF 82            [24] 5218 	mov	r7, dpl
      00195C E5 81            [12] 5219 	mov	a,sp
      00195E 24 FC            [12] 5220 	add	a,#0xfc
      001960 F5 81            [12] 5221 	mov	sp,a
      001962 D0 03            [24] 5222 	pop	ar3
      001964 D0 04            [24] 5223 	pop	ar4
      001966 D0 05            [24] 5224 	pop	ar5
      001968 D0 06            [24] 5225 	pop	ar6
      00196A EF               [12] 5226 	mov	a,r7
      00196B 60 12            [24] 5227 	jz	00107$
      00196D E5 08            [12] 5228 	mov	a,_bp
      00196F 24 05            [12] 5229 	add	a,#0x05
      001971 F8               [12] 5230 	mov	r0,a
      001972 A6 03            [24] 5231 	mov	@r0,ar3
      001974 08               [12] 5232 	inc	r0
      001975 A6 04            [24] 5233 	mov	@r0,ar4
      001977 08               [12] 5234 	inc	r0
      001978 A6 05            [24] 5235 	mov	@r0,ar5
      00197A 08               [12] 5236 	inc	r0
      00197B A6 06            [24] 5237 	mov	@r0,ar6
      00197D 80 16            [24] 5238 	sjmp	00108$
      00197F                       5239 00107$:
                           0018C8  5240 	C$fuzzy.h$2189$2_0$97 ==.
                                   5241 ;	../../fuzzy.h:2189: : membership;
      00197F A8 08            [24] 5242 	mov	r0,_bp
      001981 08               [12] 5243 	inc	r0
      001982 E5 08            [12] 5244 	mov	a,_bp
      001984 24 05            [12] 5245 	add	a,#0x05
      001986 F9               [12] 5246 	mov	r1,a
      001987 E6               [12] 5247 	mov	a,@r0
      001988 F7               [12] 5248 	mov	@r1,a
      001989 08               [12] 5249 	inc	r0
      00198A E6               [12] 5250 	mov	a,@r0
      00198B 09               [12] 5251 	inc	r1
      00198C F7               [12] 5252 	mov	@r1,a
      00198D 08               [12] 5253 	inc	r0
      00198E E6               [12] 5254 	mov	a,@r0
      00198F 09               [12] 5255 	inc	r1
      001990 F7               [12] 5256 	mov	@r1,a
      001991 08               [12] 5257 	inc	r0
      001992 E6               [12] 5258 	mov	a,@r0
      001993 09               [12] 5259 	inc	r1
      001994 F7               [12] 5260 	mov	@r1,a
      001995                       5261 00108$:
      001995 E5 08            [12] 5262 	mov	a,_bp
      001997 24 05            [12] 5263 	add	a,#0x05
      001999 F8               [12] 5264 	mov	r0,a
      00199A 86 82            [24] 5265 	mov	dpl, @r0
      00199C 08               [12] 5266 	inc	r0
      00199D 86 83            [24] 5267 	mov	dph, @r0
      00199F 08               [12] 5268 	inc	r0
      0019A0 86 F0            [24] 5269 	mov	b, @r0
      0019A2 08               [12] 5270 	inc	r0
      0019A3 E6               [12] 5271 	mov	a, @r0
                           0018ED  5272 	C$fuzzy.h$2191$2_0$97 ==.
                                   5273 ;	../../fuzzy.h:2191: case FUZZY_IMPLICATION_PRODUCT:
      0019A4 80 38            [24] 5274 	sjmp	00105$
      0019A6                       5275 00102$:
                           0018EF  5276 	C$fuzzy.h$2192$1_0$96 ==.
                                   5277 ;	../../fuzzy.h:2192: return activation * membership;
      0019A6 A8 08            [24] 5278 	mov	r0,_bp
      0019A8 08               [12] 5279 	inc	r0
      0019A9 E6               [12] 5280 	mov	a,@r0
      0019AA C0 E0            [24] 5281 	push	acc
      0019AC 08               [12] 5282 	inc	r0
      0019AD E6               [12] 5283 	mov	a,@r0
      0019AE C0 E0            [24] 5284 	push	acc
      0019B0 08               [12] 5285 	inc	r0
      0019B1 E6               [12] 5286 	mov	a,@r0
      0019B2 C0 E0            [24] 5287 	push	acc
      0019B4 08               [12] 5288 	inc	r0
      0019B5 E6               [12] 5289 	mov	a,@r0
      0019B6 C0 E0            [24] 5290 	push	acc
      0019B8 8B 82            [24] 5291 	mov	dpl, r3
      0019BA 8C 83            [24] 5292 	mov	dph, r4
      0019BC 8D F0            [24] 5293 	mov	b, r5
      0019BE EE               [12] 5294 	mov	a, r6
      0019BF 12 34 92         [24] 5295 	lcall	___fsmul
      0019C2 AC 82            [24] 5296 	mov	r4, dpl
      0019C4 AD 83            [24] 5297 	mov	r5, dph
      0019C6 AE F0            [24] 5298 	mov	r6, b
      0019C8 FF               [12] 5299 	mov	r7, a
      0019C9 E5 81            [12] 5300 	mov	a,sp
      0019CB 24 FC            [12] 5301 	add	a,#0xfc
      0019CD F5 81            [12] 5302 	mov	sp,a
      0019CF 8C 82            [24] 5303 	mov	dpl, r4
      0019D1 8D 83            [24] 5304 	mov	dph, r5
      0019D3 8E F0            [24] 5305 	mov	b, r6
      0019D5 EF               [12] 5306 	mov	a, r7
                           00191F  5307 	C$fuzzy.h$2194$2_0$97 ==.
                                   5308 ;	../../fuzzy.h:2194: default:
      0019D6 80 06            [24] 5309 	sjmp	00105$
      0019D8                       5310 00103$:
                           001921  5311 	C$fuzzy.h$2195$2_0$97 ==.
                                   5312 ;	../../fuzzy.h:2195: return LEVEL_LO;
      0019D8 90 00 00         [24] 5313 	mov	dptr,#0x0000
      0019DB E4               [12] 5314 	clr	a
      0019DC F5 F0            [12] 5315 	mov	b,a
                           001927  5316 	C$fuzzy.h$2196$1_0$96 ==.
                                   5317 ;	../../fuzzy.h:2196: }
      0019DE                       5318 00105$:
                           001927  5319 	C$fuzzy.h$2197$1_0$96 ==.
                                   5320 ;	../../fuzzy.h:2197: }
      0019DE 85 08 81         [24] 5321 	mov	sp,_bp
      0019E1 D0 08            [24] 5322 	pop	_bp
                           00192C  5323 	C$fuzzy.h$2197$1_0$96 ==.
                           00192C  5324 	XFcontroller_8051$fuzzy_implication$0$0 ==.
      0019E3 22               [24] 5325 	ret
                                   5326 ;------------------------------------------------------------
                                   5327 ;Allocation info for local variables in function 'fuzzy_aggregation'
                                   5328 ;------------------------------------------------------------
                                   5329 ;aggregated    Allocated to stack - _bp -6 +4 
                                   5330 ;implied       Allocated to stack - _bp -10 +4 
                                   5331 ;method        Allocated to registers r7 
                                   5332 ;sloc0         Allocated to stack - _bp +1 +4 
                                   5333 ;sloc1         Allocated to stack - _bp +5 +4 
                                   5334 ;sloc2         Allocated to stack - _bp +10 +4 
                                   5335 ;------------------------------------------------------------
                           00192D  5336 	Fcontroller_8051$fuzzy_aggregation$0$0 ==.
                           00192D  5337 	C$fuzzy.h$2199$1_0$99 ==.
                                   5338 ;	../../fuzzy.h:2199: static float fuzzy_aggregation(
                                   5339 ;	-----------------------------------------
                                   5340 ;	 function fuzzy_aggregation
                                   5341 ;	-----------------------------------------
      0019E4                       5342 _fuzzy_aggregation:
      0019E4 C0 08            [24] 5343 	push	_bp
      0019E6 E5 81            [12] 5344 	mov	a,sp
      0019E8 F5 08            [12] 5345 	mov	_bp,a
      0019EA 24 08            [12] 5346 	add	a,#0x08
      0019EC F5 81            [12] 5347 	mov	sp,a
      0019EE AF 82            [24] 5348 	mov	r7, dpl
                           001939  5349 	C$fuzzy.h$2205$1_0$99 ==.
                                   5350 ;	../../fuzzy.h:2205: aggregated = fuzzy_clamp(aggregated);
      0019F0 E5 08            [12] 5351 	mov	a,_bp
      0019F2 24 FA            [12] 5352 	add	a,#0xfa
      0019F4 F8               [12] 5353 	mov	r0,a
      0019F5 86 82            [24] 5354 	mov	dpl, @r0
      0019F7 08               [12] 5355 	inc	r0
      0019F8 86 83            [24] 5356 	mov	dph, @r0
      0019FA 08               [12] 5357 	inc	r0
      0019FB 86 F0            [24] 5358 	mov	b, @r0
      0019FD 08               [12] 5359 	inc	r0
      0019FE E6               [12] 5360 	mov	a, @r0
      0019FF C0 07            [24] 5361 	push	ar7
      001A01 12 00 EA         [24] 5362 	lcall	_fuzzy_clamp
      001A04 AE 82            [24] 5363 	mov	r6, dpl
      001A06 AD 83            [24] 5364 	mov	r5, dph
      001A08 AC F0            [24] 5365 	mov	r4, b
      001A0A FB               [12] 5366 	mov	r3, a
                           001954  5367 	C$fuzzy.h$2206$1_0$99 ==.
                                   5368 ;	../../fuzzy.h:2206: implied = fuzzy_clamp(implied);
      001A0B E5 08            [12] 5369 	mov	a,_bp
      001A0D 24 F6            [12] 5370 	add	a,#0xf6
      001A0F F8               [12] 5371 	mov	r0,a
      001A10 86 82            [24] 5372 	mov	dpl, @r0
      001A12 08               [12] 5373 	inc	r0
      001A13 86 83            [24] 5374 	mov	dph, @r0
      001A15 08               [12] 5375 	inc	r0
      001A16 86 F0            [24] 5376 	mov	b, @r0
      001A18 08               [12] 5377 	inc	r0
      001A19 E6               [12] 5378 	mov	a, @r0
      001A1A C0 06            [24] 5379 	push	ar6
      001A1C C0 05            [24] 5380 	push	ar5
      001A1E C0 04            [24] 5381 	push	ar4
      001A20 C0 03            [24] 5382 	push	ar3
      001A22 12 00 EA         [24] 5383 	lcall	_fuzzy_clamp
      001A25 A8 08            [24] 5384 	mov	r0,_bp
      001A27 08               [12] 5385 	inc	r0
      001A28 A6 82            [24] 5386 	mov	@r0, dpl
      001A2A 08               [12] 5387 	inc	r0
      001A2B A6 83            [24] 5388 	mov	@r0, dph
      001A2D 08               [12] 5389 	inc	r0
      001A2E A6 F0            [24] 5390 	mov	@r0, b
      001A30 08               [12] 5391 	inc	r0
      001A31 F6               [12] 5392 	mov	@r0,a
      001A32 D0 03            [24] 5393 	pop	ar3
      001A34 D0 04            [24] 5394 	pop	ar4
      001A36 D0 05            [24] 5395 	pop	ar5
      001A38 D0 06            [24] 5396 	pop	ar6
      001A3A D0 07            [24] 5397 	pop	ar7
                           001985  5398 	C$fuzzy.h$2208$1_0$99 ==.
                                   5399 ;	../../fuzzy.h:2208: switch (method) {
      001A3C BF 00 02         [24] 5400 	cjne	r7,#0x00,00134$
      001A3F 80 0E            [24] 5401 	sjmp	00101$
      001A41                       5402 00134$:
      001A41 BF 01 02         [24] 5403 	cjne	r7,#0x01,00135$
      001A44 80 76            [24] 5404 	sjmp	00102$
      001A46                       5405 00135$:
      001A46 BF 02 03         [24] 5406 	cjne	r7,#0x02,00136$
      001A49 02 1B 57         [24] 5407 	ljmp	00103$
      001A4C                       5408 00136$:
      001A4C 02 1B 8C         [24] 5409 	ljmp	00104$
                           001998  5410 	C$fuzzy.h$2209$2_0$100 ==.
                                   5411 ;	../../fuzzy.h:2209: case FUZZY_AGGREGATION_MAX:
      001A4F                       5412 00101$:
                           001998  5413 	C$fuzzy.h$2211$1_0$99 ==.
                                   5414 ;	../../fuzzy.h:2211: ? aggregated
      001A4F C0 06            [24] 5415 	push	ar6
      001A51 C0 05            [24] 5416 	push	ar5
      001A53 C0 04            [24] 5417 	push	ar4
      001A55 C0 03            [24] 5418 	push	ar3
      001A57 C0 06            [24] 5419 	push	ar6
      001A59 C0 05            [24] 5420 	push	ar5
      001A5B C0 04            [24] 5421 	push	ar4
      001A5D C0 03            [24] 5422 	push	ar3
      001A5F A8 08            [24] 5423 	mov	r0,_bp
      001A61 08               [12] 5424 	inc	r0
      001A62 86 82            [24] 5425 	mov	dpl, @r0
      001A64 08               [12] 5426 	inc	r0
      001A65 86 83            [24] 5427 	mov	dph, @r0
      001A67 08               [12] 5428 	inc	r0
      001A68 86 F0            [24] 5429 	mov	b, @r0
      001A6A 08               [12] 5430 	inc	r0
      001A6B E6               [12] 5431 	mov	a, @r0
      001A6C 12 35 C2         [24] 5432 	lcall	___fslt
      001A6F AF 82            [24] 5433 	mov	r7, dpl
      001A71 E5 81            [12] 5434 	mov	a,sp
      001A73 24 FC            [12] 5435 	add	a,#0xfc
      001A75 F5 81            [12] 5436 	mov	sp,a
      001A77 D0 03            [24] 5437 	pop	ar3
      001A79 D0 04            [24] 5438 	pop	ar4
      001A7B D0 05            [24] 5439 	pop	ar5
      001A7D D0 06            [24] 5440 	pop	ar6
      001A7F EF               [12] 5441 	mov	a,r7
      001A80 60 12            [24] 5442 	jz	00108$
      001A82 E5 08            [12] 5443 	mov	a,_bp
      001A84 24 05            [12] 5444 	add	a,#0x05
      001A86 F8               [12] 5445 	mov	r0,a
      001A87 A6 06            [24] 5446 	mov	@r0,ar6
      001A89 08               [12] 5447 	inc	r0
      001A8A A6 05            [24] 5448 	mov	@r0,ar5
      001A8C 08               [12] 5449 	inc	r0
      001A8D A6 04            [24] 5450 	mov	@r0,ar4
      001A8F 08               [12] 5451 	inc	r0
      001A90 A6 03            [24] 5452 	mov	@r0,ar3
      001A92 80 16            [24] 5453 	sjmp	00109$
      001A94                       5454 00108$:
                           0019DD  5455 	C$fuzzy.h$2212$2_0$100 ==.
                                   5456 ;	../../fuzzy.h:2212: : implied;
      001A94 A8 08            [24] 5457 	mov	r0,_bp
      001A96 08               [12] 5458 	inc	r0
      001A97 E5 08            [12] 5459 	mov	a,_bp
      001A99 24 05            [12] 5460 	add	a,#0x05
      001A9B F9               [12] 5461 	mov	r1,a
      001A9C E6               [12] 5462 	mov	a,@r0
      001A9D F7               [12] 5463 	mov	@r1,a
      001A9E 08               [12] 5464 	inc	r0
      001A9F E6               [12] 5465 	mov	a,@r0
      001AA0 09               [12] 5466 	inc	r1
      001AA1 F7               [12] 5467 	mov	@r1,a
      001AA2 08               [12] 5468 	inc	r0
      001AA3 E6               [12] 5469 	mov	a,@r0
      001AA4 09               [12] 5470 	inc	r1
      001AA5 F7               [12] 5471 	mov	@r1,a
      001AA6 08               [12] 5472 	inc	r0
      001AA7 E6               [12] 5473 	mov	a,@r0
      001AA8 09               [12] 5474 	inc	r1
      001AA9 F7               [12] 5475 	mov	@r1,a
      001AAA                       5476 00109$:
      001AAA E5 08            [12] 5477 	mov	a,_bp
      001AAC 24 05            [12] 5478 	add	a,#0x05
      001AAE F8               [12] 5479 	mov	r0,a
      001AAF 86 82            [24] 5480 	mov	dpl, @r0
      001AB1 08               [12] 5481 	inc	r0
      001AB2 86 83            [24] 5482 	mov	dph, @r0
      001AB4 08               [12] 5483 	inc	r0
      001AB5 86 F0            [24] 5484 	mov	b, @r0
      001AB7 08               [12] 5485 	inc	r0
      001AB8 E6               [12] 5486 	mov	a, @r0
      001AB9 02 1B 92         [24] 5487 	ljmp	00106$
                           001A05  5488 	C$fuzzy.h$2214$2_0$100 ==.
                                   5489 ;	../../fuzzy.h:2214: case FUZZY_AGGREGATION_ALGEBRAIC:
      001ABC                       5490 00102$:
                           001A05  5491 	C$fuzzy.h$2216$1_0$99 ==.
                                   5492 ;	../../fuzzy.h:2216: implied -
      001ABC C0 06            [24] 5493 	push	ar6
      001ABE C0 05            [24] 5494 	push	ar5
      001AC0 C0 04            [24] 5495 	push	ar4
      001AC2 C0 03            [24] 5496 	push	ar3
      001AC4 A8 08            [24] 5497 	mov	r0,_bp
      001AC6 08               [12] 5498 	inc	r0
      001AC7 E6               [12] 5499 	mov	a,@r0
      001AC8 C0 E0            [24] 5500 	push	acc
      001ACA 08               [12] 5501 	inc	r0
      001ACB E6               [12] 5502 	mov	a,@r0
      001ACC C0 E0            [24] 5503 	push	acc
      001ACE 08               [12] 5504 	inc	r0
      001ACF E6               [12] 5505 	mov	a,@r0
      001AD0 C0 E0            [24] 5506 	push	acc
      001AD2 08               [12] 5507 	inc	r0
      001AD3 E6               [12] 5508 	mov	a,@r0
      001AD4 C0 E0            [24] 5509 	push	acc
                           001A1F  5510 	C$fuzzy.h$2217$1_0$99 ==.
                                   5511 ;	../../fuzzy.h:2217: aggregated * implied;
      001AD6 8E 82            [24] 5512 	mov	dpl, r6
      001AD8 8D 83            [24] 5513 	mov	dph, r5
      001ADA 8C F0            [24] 5514 	mov	b, r4
      001ADC EB               [12] 5515 	mov	a, r3
      001ADD 12 36 14         [24] 5516 	lcall	___fsadd
      001AE0 C8               [12] 5517 	xch	a,r0
      001AE1 E5 08            [12] 5518 	mov	a,_bp
      001AE3 24 05            [12] 5519 	add	a,#0x05
      001AE5 C8               [12] 5520 	xch	a,r0
      001AE6 A6 82            [24] 5521 	mov	@r0, dpl
      001AE8 08               [12] 5522 	inc	r0
      001AE9 A6 83            [24] 5523 	mov	@r0, dph
      001AEB 08               [12] 5524 	inc	r0
      001AEC A6 F0            [24] 5525 	mov	@r0, b
      001AEE 08               [12] 5526 	inc	r0
      001AEF F6               [12] 5527 	mov	@r0,a
      001AF0 E5 81            [12] 5528 	mov	a,sp
      001AF2 24 FC            [12] 5529 	add	a,#0xfc
      001AF4 F5 81            [12] 5530 	mov	sp,a
      001AF6 D0 03            [24] 5531 	pop	ar3
      001AF8 D0 04            [24] 5532 	pop	ar4
      001AFA D0 05            [24] 5533 	pop	ar5
      001AFC D0 06            [24] 5534 	pop	ar6
      001AFE A8 08            [24] 5535 	mov	r0,_bp
      001B00 08               [12] 5536 	inc	r0
      001B01 E6               [12] 5537 	mov	a,@r0
      001B02 C0 E0            [24] 5538 	push	acc
      001B04 08               [12] 5539 	inc	r0
      001B05 E6               [12] 5540 	mov	a,@r0
      001B06 C0 E0            [24] 5541 	push	acc
      001B08 08               [12] 5542 	inc	r0
      001B09 E6               [12] 5543 	mov	a,@r0
      001B0A C0 E0            [24] 5544 	push	acc
      001B0C 08               [12] 5545 	inc	r0
      001B0D E6               [12] 5546 	mov	a,@r0
      001B0E C0 E0            [24] 5547 	push	acc
      001B10 8E 82            [24] 5548 	mov	dpl, r6
      001B12 8D 83            [24] 5549 	mov	dph, r5
      001B14 8C F0            [24] 5550 	mov	b, r4
      001B16 EB               [12] 5551 	mov	a, r3
      001B17 12 34 92         [24] 5552 	lcall	___fsmul
      001B1A AB 82            [24] 5553 	mov	r3, dpl
      001B1C AC 83            [24] 5554 	mov	r4, dph
      001B1E AE F0            [24] 5555 	mov	r6, b
      001B20 FF               [12] 5556 	mov	r7, a
      001B21 E5 81            [12] 5557 	mov	a,sp
      001B23 24 FC            [12] 5558 	add	a,#0xfc
      001B25 F5 81            [12] 5559 	mov	sp,a
      001B27 C0 03            [24] 5560 	push	ar3
      001B29 C0 04            [24] 5561 	push	ar4
      001B2B C0 06            [24] 5562 	push	ar6
      001B2D C0 07            [24] 5563 	push	ar7
      001B2F E5 08            [12] 5564 	mov	a,_bp
      001B31 24 05            [12] 5565 	add	a,#0x05
      001B33 F8               [12] 5566 	mov	r0,a
      001B34 86 82            [24] 5567 	mov	dpl, @r0
      001B36 08               [12] 5568 	inc	r0
      001B37 86 83            [24] 5569 	mov	dph, @r0
      001B39 08               [12] 5570 	inc	r0
      001B3A 86 F0            [24] 5571 	mov	b, @r0
      001B3C 08               [12] 5572 	inc	r0
      001B3D E6               [12] 5573 	mov	a, @r0
      001B3E 12 34 87         [24] 5574 	lcall	___fssub
      001B41 AC 82            [24] 5575 	mov	r4, dpl
      001B43 AD 83            [24] 5576 	mov	r5, dph
      001B45 AE F0            [24] 5577 	mov	r6, b
      001B47 FF               [12] 5578 	mov	r7, a
      001B48 E5 81            [12] 5579 	mov	a,sp
      001B4A 24 FC            [12] 5580 	add	a,#0xfc
      001B4C F5 81            [12] 5581 	mov	sp,a
      001B4E 8C 82            [24] 5582 	mov	dpl, r4
      001B50 8D 83            [24] 5583 	mov	dph, r5
      001B52 8E F0            [24] 5584 	mov	b, r6
      001B54 EF               [12] 5585 	mov	a, r7
                           001A9E  5586 	C$fuzzy.h$2219$2_0$100 ==.
                                   5587 ;	../../fuzzy.h:2219: case FUZZY_AGGREGATION_BOUNDED:
      001B55 80 3B            [24] 5588 	sjmp	00106$
      001B57                       5589 00103$:
                           001AA0  5590 	C$fuzzy.h$2223$1_0$99 ==.
                                   5591 ;	../../fuzzy.h:2223: );
      001B57 A8 08            [24] 5592 	mov	r0,_bp
      001B59 08               [12] 5593 	inc	r0
      001B5A E6               [12] 5594 	mov	a,@r0
      001B5B C0 E0            [24] 5595 	push	acc
      001B5D 08               [12] 5596 	inc	r0
      001B5E E6               [12] 5597 	mov	a,@r0
      001B5F C0 E0            [24] 5598 	push	acc
      001B61 08               [12] 5599 	inc	r0
      001B62 E6               [12] 5600 	mov	a,@r0
      001B63 C0 E0            [24] 5601 	push	acc
      001B65 08               [12] 5602 	inc	r0
      001B66 E6               [12] 5603 	mov	a,@r0
      001B67 C0 E0            [24] 5604 	push	acc
      001B69 8E 82            [24] 5605 	mov	dpl, r6
      001B6B 8D 83            [24] 5606 	mov	dph, r5
      001B6D 8C F0            [24] 5607 	mov	b, r4
      001B6F EB               [12] 5608 	mov	a, r3
      001B70 12 36 14         [24] 5609 	lcall	___fsadd
      001B73 AC 82            [24] 5610 	mov	r4, dpl
      001B75 AD 83            [24] 5611 	mov	r5, dph
      001B77 AE F0            [24] 5612 	mov	r6, b
      001B79 FF               [12] 5613 	mov	r7, a
      001B7A E5 81            [12] 5614 	mov	a,sp
      001B7C 24 FC            [12] 5615 	add	a,#0xfc
      001B7E F5 81            [12] 5616 	mov	sp,a
      001B80 8C 82            [24] 5617 	mov	dpl, r4
      001B82 8D 83            [24] 5618 	mov	dph, r5
      001B84 8E F0            [24] 5619 	mov	b, r6
      001B86 EF               [12] 5620 	mov	a, r7
      001B87 12 00 EA         [24] 5621 	lcall	_fuzzy_clamp
                           001AD3  5622 	C$fuzzy.h$2225$2_0$100 ==.
                                   5623 ;	../../fuzzy.h:2225: default:
      001B8A 80 06            [24] 5624 	sjmp	00106$
      001B8C                       5625 00104$:
                           001AD5  5626 	C$fuzzy.h$2226$2_0$100 ==.
                                   5627 ;	../../fuzzy.h:2226: return LEVEL_LO;
      001B8C 90 00 00         [24] 5628 	mov	dptr,#0x0000
      001B8F E4               [12] 5629 	clr	a
      001B90 F5 F0            [12] 5630 	mov	b,a
                           001ADB  5631 	C$fuzzy.h$2227$1_0$99 ==.
                                   5632 ;	../../fuzzy.h:2227: }
      001B92                       5633 00106$:
                           001ADB  5634 	C$fuzzy.h$2228$1_0$99 ==.
                                   5635 ;	../../fuzzy.h:2228: }
      001B92 85 08 81         [24] 5636 	mov	sp,_bp
      001B95 D0 08            [24] 5637 	pop	_bp
                           001AE0  5638 	C$fuzzy.h$2228$1_0$99 ==.
                           001AE0  5639 	XFcontroller_8051$fuzzy_aggregation$0$0 ==.
      001B97 22               [24] 5640 	ret
                                   5641 ;------------------------------------------------------------
                                   5642 ;Allocation info for local variables in function 'fuzzy_rules_aggregated_height'
                                   5643 ;------------------------------------------------------------
                                   5644 ;value         Allocated to stack - _bp -6 +4 
                                   5645 ;implication_method Allocated to stack - _bp -7 +1 
                                   5646 ;aggregation_method Allocated to stack - _bp -8 +1 
                                   5647 ;rules         Allocated to stack - _bp +1 +3 
                                   5648 ;aggregated_height Allocated to stack - _bp +12 +4 
                                   5649 ;output_membership Allocated to stack - _bp +16 +4 
                                   5650 ;implied_height Allocated to registers r4 r5 r6 r7 
                                   5651 ;index         Allocated to stack - _bp +20 +2 
                                   5652 ;sloc0         Allocated to stack - _bp +4 +3 
                                   5653 ;sloc1         Allocated to stack - _bp +7 +2 
                                   5654 ;sloc2         Allocated to stack - _bp +9 +3 
                                   5655 ;------------------------------------------------------------
                           001AE1  5656 	Fcontroller_8051$fuzzy_rules_aggregated_height$0$0 ==.
                           001AE1  5657 	C$fuzzy.h$2234$1_0$102 ==.
                                   5658 ;	../../fuzzy.h:2234: static float fuzzy_rules_aggregated_height(
                                   5659 ;	-----------------------------------------
                                   5660 ;	 function fuzzy_rules_aggregated_height
                                   5661 ;	-----------------------------------------
      001B98                       5662 _fuzzy_rules_aggregated_height:
      001B98 C0 08            [24] 5663 	push	_bp
      001B9A 85 81 08         [24] 5664 	mov	_bp,sp
      001B9D C0 82            [24] 5665 	push	dpl
      001B9F C0 83            [24] 5666 	push	dph
      001BA1 C0 F0            [24] 5667 	push	b
      001BA3 E5 81            [12] 5668 	mov	a,sp
      001BA5 24 12            [12] 5669 	add	a,#0x12
      001BA7 F5 81            [12] 5670 	mov	sp,a
                           001AF2  5671 	C$fuzzy.h$2247$1_0$102 ==.
                                   5672 ;	../../fuzzy.h:2247: LEVEL_LO;
      001BA9 E5 08            [12] 5673 	mov	a,_bp
      001BAB 24 0C            [12] 5674 	add	a,#0x0c
      001BAD F8               [12] 5675 	mov	r0,a
      001BAE E4               [12] 5676 	clr	a
      001BAF F6               [12] 5677 	mov	@r0,a
      001BB0 08               [12] 5678 	inc	r0
      001BB1 F6               [12] 5679 	mov	@r0,a
      001BB2 08               [12] 5680 	inc	r0
      001BB3 F6               [12] 5681 	mov	@r0,a
      001BB4 08               [12] 5682 	inc	r0
      001BB5 F6               [12] 5683 	mov	@r0,a
                           001AFF  5684 	C$fuzzy.h$2250$3_0$104 ==.
                                   5685 ;	../../fuzzy.h:2250: index = 0u;
      001BB6 A8 08            [24] 5686 	mov	r0,_bp
      001BB8 08               [12] 5687 	inc	r0
      001BB9 E5 08            [12] 5688 	mov	a,_bp
      001BBB 24 09            [12] 5689 	add	a,#0x09
      001BBD F9               [12] 5690 	mov	r1,a
      001BBE E6               [12] 5691 	mov	a,@r0
      001BBF F7               [12] 5692 	mov	@r1,a
      001BC0 08               [12] 5693 	inc	r0
      001BC1 E6               [12] 5694 	mov	a,@r0
      001BC2 09               [12] 5695 	inc	r1
      001BC3 F7               [12] 5696 	mov	@r1,a
      001BC4 08               [12] 5697 	inc	r0
      001BC5 E6               [12] 5698 	mov	a,@r0
      001BC6 09               [12] 5699 	inc	r1
      001BC7 F7               [12] 5700 	mov	@r1,a
      001BC8 A8 08            [24] 5701 	mov	r0,_bp
      001BCA 08               [12] 5702 	inc	r0
      001BCB E5 08            [12] 5703 	mov	a,_bp
      001BCD 24 04            [12] 5704 	add	a,#0x04
      001BCF F9               [12] 5705 	mov	r1,a
      001BD0 74 90            [12] 5706 	mov	a,#0x90
      001BD2 26               [12] 5707 	add	a, @r0
      001BD3 F7               [12] 5708 	mov	@r1,a
      001BD4 E4               [12] 5709 	clr	a
      001BD5 08               [12] 5710 	inc	r0
      001BD6 36               [12] 5711 	addc	a, @r0
      001BD7 09               [12] 5712 	inc	r1
      001BD8 F7               [12] 5713 	mov	@r1,a
      001BD9 08               [12] 5714 	inc	r0
      001BDA E6               [12] 5715 	mov	a,@r0
      001BDB 09               [12] 5716 	inc	r1
      001BDC F7               [12] 5717 	mov	@r1,a
      001BDD E5 08            [12] 5718 	mov	a,_bp
      001BDF 24 14            [12] 5719 	add	a,#0x14
      001BE1 F8               [12] 5720 	mov	r0,a
      001BE2 E4               [12] 5721 	clr	a
      001BE3 F6               [12] 5722 	mov	@r0,a
      001BE4 08               [12] 5723 	inc	r0
      001BE5 F6               [12] 5724 	mov	@r0,a
      001BE6 E5 08            [12] 5725 	mov	a,_bp
      001BE8 24 07            [12] 5726 	add	a,#0x07
      001BEA F8               [12] 5727 	mov	r0,a
      001BEB E4               [12] 5728 	clr	a
      001BEC F6               [12] 5729 	mov	@r0,a
      001BED 08               [12] 5730 	inc	r0
      001BEE F6               [12] 5731 	mov	@r0,a
      001BEF                       5732 00103$:
                           001B38  5733 	C$fuzzy.h$2251$1_0$102 ==.
                                   5734 ;	../../fuzzy.h:2251: index < rules->count;
      001BEF E5 08            [12] 5735 	mov	a,_bp
      001BF1 24 04            [12] 5736 	add	a,#0x04
      001BF3 F8               [12] 5737 	mov	r0,a
      001BF4 86 82            [24] 5738 	mov	dpl,@r0
      001BF6 08               [12] 5739 	inc	r0
      001BF7 86 83            [24] 5740 	mov	dph,@r0
      001BF9 08               [12] 5741 	inc	r0
      001BFA 86 F0            [24] 5742 	mov	b,@r0
      001BFC 12 37 EE         [24] 5743 	lcall	__gptrget
      001BFF FC               [12] 5744 	mov	r4,a
      001C00 A3               [24] 5745 	inc	dptr
      001C01 12 37 EE         [24] 5746 	lcall	__gptrget
      001C04 FD               [12] 5747 	mov	r5,a
      001C05 E5 08            [12] 5748 	mov	a,_bp
      001C07 24 14            [12] 5749 	add	a,#0x14
      001C09 F8               [12] 5750 	mov	r0,a
      001C0A C3               [12] 5751 	clr	c
      001C0B E6               [12] 5752 	mov	a,@r0
      001C0C 9C               [12] 5753 	subb	a,r4
      001C0D 08               [12] 5754 	inc	r0
      001C0E E6               [12] 5755 	mov	a,@r0
      001C0F 9D               [12] 5756 	subb	a,r5
      001C10 40 03            [24] 5757 	jc	00120$
      001C12 02 1D 29         [24] 5758 	ljmp	00101$
      001C15                       5759 00120$:
                           001B5E  5760 	C$fuzzy.h$2256$3_0$104 ==.
                                   5761 ;	../../fuzzy.h:2256: rules->rules[index]
      001C15 E5 08            [12] 5762 	mov	a,_bp
      001C17 24 09            [12] 5763 	add	a,#0x09
      001C19 F8               [12] 5764 	mov	r0,a
      001C1A E5 08            [12] 5765 	mov	a,_bp
      001C1C 24 07            [12] 5766 	add	a,#0x07
      001C1E F9               [12] 5767 	mov	r1,a
      001C1F E7               [12] 5768 	mov	a,@r1
      001C20 26               [12] 5769 	add	a, @r0
      001C21 FD               [12] 5770 	mov	r5,a
      001C22 09               [12] 5771 	inc	r1
      001C23 E7               [12] 5772 	mov	a,@r1
      001C24 08               [12] 5773 	inc	r0
      001C25 36               [12] 5774 	addc	a, @r0
      001C26 FE               [12] 5775 	mov	r6,a
      001C27 08               [12] 5776 	inc	r0
      001C28 86 07            [24] 5777 	mov	ar7,@r0
      001C2A 74 07            [12] 5778 	mov	a,#0x07
      001C2C 2D               [12] 5779 	add	a, r5
      001C2D FD               [12] 5780 	mov	r5,a
      001C2E E4               [12] 5781 	clr	a
      001C2F 3E               [12] 5782 	addc	a, r6
      001C30 FE               [12] 5783 	mov	r6,a
      001C31 8D 82            [24] 5784 	mov	dpl,r5
      001C33 8E 83            [24] 5785 	mov	dph,r6
      001C35 8F F0            [24] 5786 	mov	b,r7
      001C37 12 37 EE         [24] 5787 	lcall	__gptrget
      001C3A FD               [12] 5788 	mov	r5,a
      001C3B A3               [24] 5789 	inc	dptr
      001C3C 12 37 EE         [24] 5790 	lcall	__gptrget
      001C3F FE               [12] 5791 	mov	r6,a
                           001B89  5792 	C$fuzzy.h$2257$3_0$104 ==.
                                   5793 ;	../../fuzzy.h:2257: .output_function(value)
      001C40 12 1C 45         [24] 5794 	lcall	00121$
      001C43 80 14            [24] 5795 	sjmp	00122$
      001C45                       5796 00121$:
      001C45 C0 05            [24] 5797 	push	ar5
      001C47 C0 06            [24] 5798 	push	ar6
      001C49 E5 08            [12] 5799 	mov	a,_bp
      001C4B 24 FA            [12] 5800 	add	a,#0xfa
      001C4D F8               [12] 5801 	mov	r0,a
      001C4E 86 82            [24] 5802 	mov	dpl, @r0
      001C50 08               [12] 5803 	inc	r0
      001C51 86 83            [24] 5804 	mov	dph, @r0
      001C53 08               [12] 5805 	inc	r0
      001C54 86 F0            [24] 5806 	mov	b, @r0
      001C56 08               [12] 5807 	inc	r0
      001C57 E6               [12] 5808 	mov	a, @r0
      001C58 22               [24] 5809 	ret
      001C59                       5810 00122$:
      001C59 12 00 EA         [24] 5811 	lcall	_fuzzy_clamp
      001C5C C8               [12] 5812 	xch	a,r0
      001C5D E5 08            [12] 5813 	mov	a,_bp
      001C5F 24 10            [12] 5814 	add	a,#0x10
      001C61 C8               [12] 5815 	xch	a,r0
      001C62 A6 82            [24] 5816 	mov	@r0, dpl
      001C64 08               [12] 5817 	inc	r0
      001C65 A6 83            [24] 5818 	mov	@r0, dph
      001C67 08               [12] 5819 	inc	r0
      001C68 A6 F0            [24] 5820 	mov	@r0, b
      001C6A 08               [12] 5821 	inc	r0
      001C6B F6               [12] 5822 	mov	@r0,a
                           001BB5  5823 	C$fuzzy.h$2263$3_0$104 ==.
                                   5824 ;	../../fuzzy.h:2263: rules->rules[index].value,
      001C6C A8 08            [24] 5825 	mov	r0,_bp
      001C6E 08               [12] 5826 	inc	r0
      001C6F E5 08            [12] 5827 	mov	a,_bp
      001C71 24 07            [12] 5828 	add	a,#0x07
      001C73 F9               [12] 5829 	mov	r1,a
      001C74 E7               [12] 5830 	mov	a,@r1
      001C75 26               [12] 5831 	add	a, @r0
      001C76 FA               [12] 5832 	mov	r2,a
      001C77 09               [12] 5833 	inc	r1
      001C78 E7               [12] 5834 	mov	a,@r1
      001C79 08               [12] 5835 	inc	r0
      001C7A 36               [12] 5836 	addc	a, @r0
      001C7B FB               [12] 5837 	mov	r3,a
      001C7C 08               [12] 5838 	inc	r0
      001C7D 86 07            [24] 5839 	mov	ar7,@r0
      001C7F 74 03            [12] 5840 	mov	a,#0x03
      001C81 2A               [12] 5841 	add	a, r2
      001C82 FA               [12] 5842 	mov	r2,a
      001C83 E4               [12] 5843 	clr	a
      001C84 3B               [12] 5844 	addc	a, r3
      001C85 FB               [12] 5845 	mov	r3,a
      001C86 8A 82            [24] 5846 	mov	dpl,r2
      001C88 8B 83            [24] 5847 	mov	dph,r3
      001C8A 8F F0            [24] 5848 	mov	b,r7
      001C8C 12 37 EE         [24] 5849 	lcall	__gptrget
      001C8F FA               [12] 5850 	mov	r2,a
      001C90 A3               [24] 5851 	inc	dptr
      001C91 12 37 EE         [24] 5852 	lcall	__gptrget
      001C94 FB               [12] 5853 	mov	r3,a
      001C95 A3               [24] 5854 	inc	dptr
      001C96 12 37 EE         [24] 5855 	lcall	__gptrget
      001C99 FF               [12] 5856 	mov	r7,a
      001C9A A3               [24] 5857 	inc	dptr
      001C9B 12 37 EE         [24] 5858 	lcall	__gptrget
      001C9E FE               [12] 5859 	mov	r6,a
                           001BE8  5860 	C$fuzzy.h$2262$3_0$104 ==.
                                   5861 ;	../../fuzzy.h:2262: implication_method,
      001C9F E5 08            [12] 5862 	mov	a,_bp
      001CA1 24 10            [12] 5863 	add	a,#0x10
      001CA3 F8               [12] 5864 	mov	r0,a
      001CA4 E6               [12] 5865 	mov	a,@r0
      001CA5 C0 E0            [24] 5866 	push	acc
      001CA7 08               [12] 5867 	inc	r0
      001CA8 E6               [12] 5868 	mov	a,@r0
      001CA9 C0 E0            [24] 5869 	push	acc
      001CAB 08               [12] 5870 	inc	r0
      001CAC E6               [12] 5871 	mov	a,@r0
      001CAD C0 E0            [24] 5872 	push	acc
      001CAF 08               [12] 5873 	inc	r0
      001CB0 E6               [12] 5874 	mov	a,@r0
      001CB1 C0 E0            [24] 5875 	push	acc
      001CB3 C0 02            [24] 5876 	push	ar2
      001CB5 C0 03            [24] 5877 	push	ar3
      001CB7 C0 07            [24] 5878 	push	ar7
      001CB9 C0 06            [24] 5879 	push	ar6
      001CBB E5 08            [12] 5880 	mov	a,_bp
      001CBD 24 F9            [12] 5881 	add	a,#0xf9
      001CBF F8               [12] 5882 	mov	r0,a
      001CC0 86 82            [24] 5883 	mov	dpl, @r0
      001CC2 12 18 D1         [24] 5884 	lcall	_fuzzy_implication
      001CC5 AC 82            [24] 5885 	mov	r4, dpl
      001CC7 AD 83            [24] 5886 	mov	r5, dph
      001CC9 AE F0            [24] 5887 	mov	r6, b
      001CCB FF               [12] 5888 	mov	r7, a
      001CCC E5 81            [12] 5889 	mov	a,sp
      001CCE 24 F8            [12] 5890 	add	a,#0xf8
      001CD0 F5 81            [12] 5891 	mov	sp,a
                           001C1B  5892 	C$fuzzy.h$2269$3_0$104 ==.
                                   5893 ;	../../fuzzy.h:2269: aggregation_method,
      001CD2 C0 04            [24] 5894 	push	ar4
      001CD4 C0 05            [24] 5895 	push	ar5
      001CD6 C0 06            [24] 5896 	push	ar6
      001CD8 C0 07            [24] 5897 	push	ar7
      001CDA E5 08            [12] 5898 	mov	a,_bp
      001CDC 24 0C            [12] 5899 	add	a,#0x0c
      001CDE F8               [12] 5900 	mov	r0,a
      001CDF E6               [12] 5901 	mov	a,@r0
      001CE0 C0 E0            [24] 5902 	push	acc
      001CE2 08               [12] 5903 	inc	r0
      001CE3 E6               [12] 5904 	mov	a,@r0
      001CE4 C0 E0            [24] 5905 	push	acc
      001CE6 08               [12] 5906 	inc	r0
      001CE7 E6               [12] 5907 	mov	a,@r0
      001CE8 C0 E0            [24] 5908 	push	acc
      001CEA 08               [12] 5909 	inc	r0
      001CEB E6               [12] 5910 	mov	a,@r0
      001CEC C0 E0            [24] 5911 	push	acc
      001CEE E5 08            [12] 5912 	mov	a,_bp
      001CF0 24 F8            [12] 5913 	add	a,#0xf8
      001CF2 F8               [12] 5914 	mov	r0,a
      001CF3 86 82            [24] 5915 	mov	dpl, @r0
      001CF5 12 19 E4         [24] 5916 	lcall	_fuzzy_aggregation
      001CF8 C8               [12] 5917 	xch	a,r0
      001CF9 E5 08            [12] 5918 	mov	a,_bp
      001CFB 24 0C            [12] 5919 	add	a,#0x0c
      001CFD C8               [12] 5920 	xch	a,r0
      001CFE A6 82            [24] 5921 	mov	@r0, dpl
      001D00 08               [12] 5922 	inc	r0
      001D01 A6 83            [24] 5923 	mov	@r0, dph
      001D03 08               [12] 5924 	inc	r0
      001D04 A6 F0            [24] 5925 	mov	@r0, b
      001D06 08               [12] 5926 	inc	r0
      001D07 F6               [12] 5927 	mov	@r0,a
      001D08 E5 81            [12] 5928 	mov	a,sp
      001D0A 24 F8            [12] 5929 	add	a,#0xf8
      001D0C F5 81            [12] 5930 	mov	sp,a
                           001C57  5931 	C$fuzzy.h$2252$1_0$102 ==.
                                   5932 ;	../../fuzzy.h:2252: index++
      001D0E E5 08            [12] 5933 	mov	a,_bp
      001D10 24 07            [12] 5934 	add	a,#0x07
      001D12 F8               [12] 5935 	mov	r0,a
      001D13 74 09            [12] 5936 	mov	a,#0x09
      001D15 26               [12] 5937 	add	a, @r0
      001D16 F6               [12] 5938 	mov	@r0,a
      001D17 E4               [12] 5939 	clr	a
      001D18 08               [12] 5940 	inc	r0
      001D19 36               [12] 5941 	addc	a, @r0
      001D1A F6               [12] 5942 	mov	@r0,a
      001D1B E5 08            [12] 5943 	mov	a,_bp
      001D1D 24 14            [12] 5944 	add	a,#0x14
      001D1F F8               [12] 5945 	mov	r0,a
      001D20 06               [12] 5946 	inc	@r0
      001D21 B6 00 02         [24] 5947 	cjne	@r0,#0x00,00123$
      001D24 08               [12] 5948 	inc	r0
      001D25 06               [12] 5949 	inc	@r0
      001D26                       5950 00123$:
      001D26 02 1B EF         [24] 5951 	ljmp	00103$
      001D29                       5952 00101$:
                           001C72  5953 	C$fuzzy.h$2276$1_0$102 ==.
                                   5954 ;	../../fuzzy.h:2276: aggregated_height
      001D29 E5 08            [12] 5955 	mov	a,_bp
      001D2B 24 0C            [12] 5956 	add	a,#0x0c
      001D2D F8               [12] 5957 	mov	r0,a
      001D2E 86 82            [24] 5958 	mov	dpl, @r0
      001D30 08               [12] 5959 	inc	r0
      001D31 86 83            [24] 5960 	mov	dph, @r0
      001D33 08               [12] 5961 	inc	r0
      001D34 86 F0            [24] 5962 	mov	b, @r0
      001D36 08               [12] 5963 	inc	r0
      001D37 E6               [12] 5964 	mov	a, @r0
      001D38 12 00 EA         [24] 5965 	lcall	_fuzzy_clamp
                           001C84  5966 	C$fuzzy.h$2278$1_0$102 ==.
                                   5967 ;	../../fuzzy.h:2278: }
      001D3B 85 08 81         [24] 5968 	mov	sp,_bp
      001D3E D0 08            [24] 5969 	pop	_bp
                           001C89  5970 	C$fuzzy.h$2278$1_0$102 ==.
                           001C89  5971 	XFcontroller_8051$fuzzy_rules_aggregated_height$0$0 ==.
      001D40 22               [24] 5972 	ret
                                   5973 ;------------------------------------------------------------
                                   5974 ;Allocation info for local variables in function 'fuzzy_rules_maximum_result'
                                   5975 ;------------------------------------------------------------
                                   5976 ;rules         Allocated to stack - _bp -5 +3 
                                   5977 ;lower         Allocated to stack - _bp -9 +4 
                                   5978 ;upper         Allocated to stack - _bp -13 +4 
                                   5979 ;step          Allocated to stack - _bp -17 +4 
                                   5980 ;implication_method Allocated to stack - _bp -18 +1 
                                   5981 ;aggregation_method Allocated to stack - _bp -19 +1 
                                   5982 ;result        Allocated to registers r5 r6 r7 
                                   5983 ;value         Allocated to stack - _bp +16 +4 
                                   5984 ;height        Allocated to stack - _bp +20 +4 
                                   5985 ;sloc0         Allocated to stack - _bp +1 +3 
                                   5986 ;sloc1         Allocated to stack - _bp +4 +3 
                                   5987 ;sloc2         Allocated to stack - _bp +7 +3 
                                   5988 ;sloc3         Allocated to stack - _bp +10 +3 
                                   5989 ;sloc4         Allocated to stack - _bp +13 +3 
                                   5990 ;------------------------------------------------------------
                           001C8A  5991 	Fcontroller_8051$fuzzy_rules_maximum_result$0$0 ==.
                           001C8A  5992 	C$fuzzy.h$2298$1_0$106 ==.
                                   5993 ;	../../fuzzy.h:2298: static void fuzzy_rules_maximum_result(
                                   5994 ;	-----------------------------------------
                                   5995 ;	 function fuzzy_rules_maximum_result
                                   5996 ;	-----------------------------------------
      001D41                       5997 _fuzzy_rules_maximum_result:
      001D41 C0 08            [24] 5998 	push	_bp
      001D43 E5 81            [12] 5999 	mov	a,sp
      001D45 F5 08            [12] 6000 	mov	_bp,a
      001D47 24 17            [12] 6001 	add	a,#0x17
      001D49 F5 81            [12] 6002 	mov	sp,a
      001D4B AD 82            [24] 6003 	mov	r5, dpl
      001D4D AE 83            [24] 6004 	mov	r6, dph
      001D4F AF F0            [24] 6005 	mov	r7, b
                           001C9A  6006 	C$fuzzy.h$2311$1_0$106 ==.
                                   6007 ;	../../fuzzy.h:2311: result->height =
      001D51 E5 08            [12] 6008 	mov	a,_bp
      001D53 24 0A            [12] 6009 	add	a,#0x0a
      001D55 F8               [12] 6010 	mov	r0,a
      001D56 A6 05            [24] 6011 	mov	@r0,ar5
      001D58 08               [12] 6012 	inc	r0
      001D59 A6 06            [24] 6013 	mov	@r0,ar6
      001D5B 08               [12] 6014 	inc	r0
      001D5C A6 07            [24] 6015 	mov	@r0,ar7
      001D5E E5 08            [12] 6016 	mov	a,_bp
      001D60 24 0A            [12] 6017 	add	a,#0x0a
      001D62 F8               [12] 6018 	mov	r0,a
      001D63 86 82            [24] 6019 	mov	dpl,@r0
      001D65 08               [12] 6020 	inc	r0
      001D66 86 83            [24] 6021 	mov	dph,@r0
      001D68 08               [12] 6022 	inc	r0
      001D69 86 F0            [24] 6023 	mov	b,@r0
      001D6B E4               [12] 6024 	clr	a
      001D6C 12 35 A7         [24] 6025 	lcall	__gptrput
      001D6F A3               [24] 6026 	inc	dptr
      001D70 12 35 A7         [24] 6027 	lcall	__gptrput
      001D73 A3               [24] 6028 	inc	dptr
      001D74 12 35 A7         [24] 6029 	lcall	__gptrput
      001D77 A3               [24] 6030 	inc	dptr
      001D78 12 35 A7         [24] 6031 	lcall	__gptrput
                           001CC4  6032 	C$fuzzy.h$2314$1_0$106 ==.
                                   6033 ;	../../fuzzy.h:2314: result->smallest_position =
      001D7B A8 08            [24] 6034 	mov	r0,_bp
      001D7D 08               [12] 6035 	inc	r0
      001D7E 74 04            [12] 6036 	mov	a,#0x04
      001D80 2D               [12] 6037 	add	a, r5
      001D81 F6               [12] 6038 	mov	@r0,a
      001D82 E4               [12] 6039 	clr	a
      001D83 3E               [12] 6040 	addc	a, r6
      001D84 08               [12] 6041 	inc	r0
      001D85 F6               [12] 6042 	mov	@r0,a
      001D86 08               [12] 6043 	inc	r0
      001D87 A6 07            [24] 6044 	mov	@r0,ar7
      001D89 A8 08            [24] 6045 	mov	r0,_bp
      001D8B 08               [12] 6046 	inc	r0
      001D8C 86 82            [24] 6047 	mov	dpl,@r0
      001D8E 08               [12] 6048 	inc	r0
      001D8F 86 83            [24] 6049 	mov	dph,@r0
      001D91 08               [12] 6050 	inc	r0
      001D92 86 F0            [24] 6051 	mov	b,@r0
      001D94 E5 08            [12] 6052 	mov	a,_bp
      001D96 24 F7            [12] 6053 	add	a,#0xf7
      001D98 F9               [12] 6054 	mov	r1,a
      001D99 E7               [12] 6055 	mov	a,@r1
      001D9A 12 35 A7         [24] 6056 	lcall	__gptrput
      001D9D A3               [24] 6057 	inc	dptr
      001D9E 09               [12] 6058 	inc	r1
      001D9F E7               [12] 6059 	mov	a,@r1
      001DA0 12 35 A7         [24] 6060 	lcall	__gptrput
      001DA3 A3               [24] 6061 	inc	dptr
      001DA4 09               [12] 6062 	inc	r1
      001DA5 E7               [12] 6063 	mov	a,@r1
      001DA6 12 35 A7         [24] 6064 	lcall	__gptrput
      001DA9 A3               [24] 6065 	inc	dptr
      001DAA 09               [12] 6066 	inc	r1
      001DAB E7               [12] 6067 	mov	a,@r1
      001DAC 12 35 A7         [24] 6068 	lcall	__gptrput
                           001CF8  6069 	C$fuzzy.h$2317$1_0$106 ==.
                                   6070 ;	../../fuzzy.h:2317: result->largest_position =
      001DAF E5 08            [12] 6071 	mov	a,_bp
      001DB1 24 04            [12] 6072 	add	a,#0x04
      001DB3 F8               [12] 6073 	mov	r0,a
      001DB4 74 08            [12] 6074 	mov	a,#0x08
      001DB6 2D               [12] 6075 	add	a, r5
      001DB7 F6               [12] 6076 	mov	@r0,a
      001DB8 E4               [12] 6077 	clr	a
      001DB9 3E               [12] 6078 	addc	a, r6
      001DBA 08               [12] 6079 	inc	r0
      001DBB F6               [12] 6080 	mov	@r0,a
      001DBC 08               [12] 6081 	inc	r0
      001DBD A6 07            [24] 6082 	mov	@r0,ar7
      001DBF E5 08            [12] 6083 	mov	a,_bp
      001DC1 24 04            [12] 6084 	add	a,#0x04
      001DC3 F8               [12] 6085 	mov	r0,a
      001DC4 86 82            [24] 6086 	mov	dpl,@r0
      001DC6 08               [12] 6087 	inc	r0
      001DC7 86 83            [24] 6088 	mov	dph,@r0
      001DC9 08               [12] 6089 	inc	r0
      001DCA 86 F0            [24] 6090 	mov	b,@r0
      001DCC E5 08            [12] 6091 	mov	a,_bp
      001DCE 24 F7            [12] 6092 	add	a,#0xf7
      001DD0 F9               [12] 6093 	mov	r1,a
      001DD1 E7               [12] 6094 	mov	a,@r1
      001DD2 12 35 A7         [24] 6095 	lcall	__gptrput
      001DD5 A3               [24] 6096 	inc	dptr
      001DD6 09               [12] 6097 	inc	r1
      001DD7 E7               [12] 6098 	mov	a,@r1
      001DD8 12 35 A7         [24] 6099 	lcall	__gptrput
      001DDB A3               [24] 6100 	inc	dptr
      001DDC 09               [12] 6101 	inc	r1
      001DDD E7               [12] 6102 	mov	a,@r1
      001DDE 12 35 A7         [24] 6103 	lcall	__gptrput
      001DE1 A3               [24] 6104 	inc	dptr
      001DE2 09               [12] 6105 	inc	r1
      001DE3 E7               [12] 6106 	mov	a,@r1
      001DE4 12 35 A7         [24] 6107 	lcall	__gptrput
                           001D30  6108 	C$fuzzy.h$2320$1_0$106 ==.
                                   6109 ;	../../fuzzy.h:2320: result->position_sum =
      001DE7 E5 08            [12] 6110 	mov	a,_bp
      001DE9 24 07            [12] 6111 	add	a,#0x07
      001DEB F8               [12] 6112 	mov	r0,a
      001DEC 74 0C            [12] 6113 	mov	a,#0x0c
      001DEE 2D               [12] 6114 	add	a, r5
      001DEF F6               [12] 6115 	mov	@r0,a
      001DF0 E4               [12] 6116 	clr	a
      001DF1 3E               [12] 6117 	addc	a, r6
      001DF2 08               [12] 6118 	inc	r0
      001DF3 F6               [12] 6119 	mov	@r0,a
      001DF4 08               [12] 6120 	inc	r0
      001DF5 A6 07            [24] 6121 	mov	@r0,ar7
      001DF7 E5 08            [12] 6122 	mov	a,_bp
      001DF9 24 07            [12] 6123 	add	a,#0x07
      001DFB F8               [12] 6124 	mov	r0,a
      001DFC 86 82            [24] 6125 	mov	dpl,@r0
      001DFE 08               [12] 6126 	inc	r0
      001DFF 86 83            [24] 6127 	mov	dph,@r0
      001E01 08               [12] 6128 	inc	r0
      001E02 86 F0            [24] 6129 	mov	b,@r0
      001E04 E4               [12] 6130 	clr	a
      001E05 12 35 A7         [24] 6131 	lcall	__gptrput
      001E08 A3               [24] 6132 	inc	dptr
      001E09 12 35 A7         [24] 6133 	lcall	__gptrput
      001E0C A3               [24] 6134 	inc	dptr
      001E0D 12 35 A7         [24] 6135 	lcall	__gptrput
      001E10 A3               [24] 6136 	inc	dptr
      001E11 12 35 A7         [24] 6137 	lcall	__gptrput
                           001D5D  6138 	C$fuzzy.h$2323$1_0$106 ==.
                                   6139 ;	../../fuzzy.h:2323: result->position_count =
      001E14 E5 08            [12] 6140 	mov	a,_bp
      001E16 24 0D            [12] 6141 	add	a,#0x0d
      001E18 F8               [12] 6142 	mov	r0,a
      001E19 74 10            [12] 6143 	mov	a,#0x10
      001E1B 2D               [12] 6144 	add	a, r5
      001E1C F6               [12] 6145 	mov	@r0,a
      001E1D E4               [12] 6146 	clr	a
      001E1E 3E               [12] 6147 	addc	a, r6
      001E1F 08               [12] 6148 	inc	r0
      001E20 F6               [12] 6149 	mov	@r0,a
      001E21 08               [12] 6150 	inc	r0
      001E22 A6 07            [24] 6151 	mov	@r0,ar7
      001E24 E5 08            [12] 6152 	mov	a,_bp
      001E26 24 0D            [12] 6153 	add	a,#0x0d
      001E28 F8               [12] 6154 	mov	r0,a
      001E29 86 82            [24] 6155 	mov	dpl,@r0
      001E2B 08               [12] 6156 	inc	r0
      001E2C 86 83            [24] 6157 	mov	dph,@r0
      001E2E 08               [12] 6158 	inc	r0
      001E2F 86 F0            [24] 6159 	mov	b,@r0
      001E31 E4               [12] 6160 	clr	a
      001E32 12 35 A7         [24] 6161 	lcall	__gptrput
      001E35 A3               [24] 6162 	inc	dptr
      001E36 12 35 A7         [24] 6163 	lcall	__gptrput
                           001D82  6164 	C$fuzzy.h$2327$2_0$107 ==.
                                   6165 ;	../../fuzzy.h:2327: value = lower;
      001E39 E5 08            [12] 6166 	mov	a,_bp
      001E3B 24 F7            [12] 6167 	add	a,#0xf7
      001E3D F8               [12] 6168 	mov	r0,a
      001E3E E5 08            [12] 6169 	mov	a,_bp
      001E40 24 10            [12] 6170 	add	a,#0x10
      001E42 F9               [12] 6171 	mov	r1,a
      001E43 E6               [12] 6172 	mov	a,@r0
      001E44 F7               [12] 6173 	mov	@r1,a
      001E45 08               [12] 6174 	inc	r0
      001E46 E6               [12] 6175 	mov	a,@r0
      001E47 09               [12] 6176 	inc	r1
      001E48 F7               [12] 6177 	mov	@r1,a
      001E49 08               [12] 6178 	inc	r0
      001E4A E6               [12] 6179 	mov	a,@r0
      001E4B 09               [12] 6180 	inc	r1
      001E4C F7               [12] 6181 	mov	@r1,a
      001E4D 08               [12] 6182 	inc	r0
      001E4E E6               [12] 6183 	mov	a,@r0
      001E4F 09               [12] 6184 	inc	r1
      001E50 F7               [12] 6185 	mov	@r1,a
      001E51                       6186 00109$:
                           001D9A  6187 	C$fuzzy.h$2328$2_0$106 ==.
                                   6188 ;	../../fuzzy.h:2328: value <= upper;
      001E51 E5 08            [12] 6189 	mov	a,_bp
      001E53 24 10            [12] 6190 	add	a,#0x10
      001E55 F8               [12] 6191 	mov	r0,a
      001E56 E6               [12] 6192 	mov	a,@r0
      001E57 C0 E0            [24] 6193 	push	acc
      001E59 08               [12] 6194 	inc	r0
      001E5A E6               [12] 6195 	mov	a,@r0
      001E5B C0 E0            [24] 6196 	push	acc
      001E5D 08               [12] 6197 	inc	r0
      001E5E E6               [12] 6198 	mov	a,@r0
      001E5F C0 E0            [24] 6199 	push	acc
      001E61 08               [12] 6200 	inc	r0
      001E62 E6               [12] 6201 	mov	a,@r0
      001E63 C0 E0            [24] 6202 	push	acc
      001E65 E5 08            [12] 6203 	mov	a,_bp
      001E67 24 F3            [12] 6204 	add	a,#0xf3
      001E69 F8               [12] 6205 	mov	r0,a
      001E6A 86 82            [24] 6206 	mov	dpl, @r0
      001E6C 08               [12] 6207 	inc	r0
      001E6D 86 83            [24] 6208 	mov	dph, @r0
      001E6F 08               [12] 6209 	inc	r0
      001E70 86 F0            [24] 6210 	mov	b, @r0
      001E72 08               [12] 6211 	inc	r0
      001E73 E6               [12] 6212 	mov	a, @r0
      001E74 12 35 C2         [24] 6213 	lcall	___fslt
      001E77 E5 81            [12] 6214 	mov	a,sp
      001E79 24 FC            [12] 6215 	add	a,#0xfc
      001E7B F5 81            [12] 6216 	mov	sp,a
      001E7D E5 82            [12] 6217 	mov	a, dpl
      001E7F 24 FF            [12] 6218 	add	a,#0xff
      001E81 92 00            [24] 6219 	mov	b0,c
      001E83 50 03            [24] 6220 	jnc	00137$
      001E85 02 21 39         [24] 6221 	ljmp	00111$
      001E88                       6222 00137$:
                           001DD1  6223 	C$fuzzy.h$2333$3_0$108 ==.
                                   6224 ;	../../fuzzy.h:2333: rules,
      001E88 E5 08            [12] 6225 	mov	a,_bp
      001E8A 24 ED            [12] 6226 	add	a,#0xed
      001E8C F8               [12] 6227 	mov	r0,a
      001E8D E6               [12] 6228 	mov	a,@r0
      001E8E C0 E0            [24] 6229 	push	acc
      001E90 E5 08            [12] 6230 	mov	a,_bp
      001E92 24 EE            [12] 6231 	add	a,#0xee
      001E94 F8               [12] 6232 	mov	r0,a
      001E95 E6               [12] 6233 	mov	a,@r0
      001E96 C0 E0            [24] 6234 	push	acc
      001E98 E5 08            [12] 6235 	mov	a,_bp
      001E9A 24 10            [12] 6236 	add	a,#0x10
      001E9C F8               [12] 6237 	mov	r0,a
      001E9D E6               [12] 6238 	mov	a,@r0
      001E9E C0 E0            [24] 6239 	push	acc
      001EA0 08               [12] 6240 	inc	r0
      001EA1 E6               [12] 6241 	mov	a,@r0
      001EA2 C0 E0            [24] 6242 	push	acc
      001EA4 08               [12] 6243 	inc	r0
      001EA5 E6               [12] 6244 	mov	a,@r0
      001EA6 C0 E0            [24] 6245 	push	acc
      001EA8 08               [12] 6246 	inc	r0
      001EA9 E6               [12] 6247 	mov	a,@r0
      001EAA C0 E0            [24] 6248 	push	acc
      001EAC E5 08            [12] 6249 	mov	a,_bp
      001EAE 24 FB            [12] 6250 	add	a,#0xfb
      001EB0 F8               [12] 6251 	mov	r0,a
      001EB1 86 82            [24] 6252 	mov	dpl, @r0
      001EB3 08               [12] 6253 	inc	r0
      001EB4 86 83            [24] 6254 	mov	dph, @r0
      001EB6 08               [12] 6255 	inc	r0
      001EB7 86 F0            [24] 6256 	mov	b, @r0
      001EB9 12 1B 98         [24] 6257 	lcall	_fuzzy_rules_aggregated_height
      001EBC C8               [12] 6258 	xch	a,r0
      001EBD E5 08            [12] 6259 	mov	a,_bp
      001EBF 24 14            [12] 6260 	add	a,#0x14
      001EC1 C8               [12] 6261 	xch	a,r0
      001EC2 A6 82            [24] 6262 	mov	@r0, dpl
      001EC4 08               [12] 6263 	inc	r0
      001EC5 A6 83            [24] 6264 	mov	@r0, dph
      001EC7 08               [12] 6265 	inc	r0
      001EC8 A6 F0            [24] 6266 	mov	@r0, b
      001ECA 08               [12] 6267 	inc	r0
      001ECB F6               [12] 6268 	mov	@r0,a
      001ECC E5 81            [12] 6269 	mov	a,sp
      001ECE 24 FA            [12] 6270 	add	a,#0xfa
      001ED0 F5 81            [12] 6271 	mov	sp,a
                           001E1B  6272 	C$fuzzy.h$2340$3_0$108 ==.
                                   6273 ;	../../fuzzy.h:2340: result->position_count == 0u ||
      001ED2 E5 08            [12] 6274 	mov	a,_bp
      001ED4 24 0D            [12] 6275 	add	a,#0x0d
      001ED6 F8               [12] 6276 	mov	r0,a
      001ED7 86 82            [24] 6277 	mov	dpl,@r0
      001ED9 08               [12] 6278 	inc	r0
      001EDA 86 83            [24] 6279 	mov	dph,@r0
      001EDC 08               [12] 6280 	inc	r0
      001EDD 86 F0            [24] 6281 	mov	b,@r0
      001EDF 12 37 EE         [24] 6282 	lcall	__gptrget
      001EE2 FD               [12] 6283 	mov	r5,a
      001EE3 A3               [24] 6284 	inc	dptr
      001EE4 12 37 EE         [24] 6285 	lcall	__gptrget
      001EE7 4D               [12] 6286 	orl	a,r5
      001EE8 60 4C            [24] 6287 	jz	00103$
                           001E33  6288 	C$fuzzy.h$2341$2_0$106 ==.
                                   6289 ;	../../fuzzy.h:2341: height > result->height
      001EEA E5 08            [12] 6290 	mov	a,_bp
      001EEC 24 0A            [12] 6291 	add	a,#0x0a
      001EEE F8               [12] 6292 	mov	r0,a
      001EEF 86 82            [24] 6293 	mov	dpl,@r0
      001EF1 08               [12] 6294 	inc	r0
      001EF2 86 83            [24] 6295 	mov	dph,@r0
      001EF4 08               [12] 6296 	inc	r0
      001EF5 86 F0            [24] 6297 	mov	b,@r0
      001EF7 12 37 EE         [24] 6298 	lcall	__gptrget
      001EFA FC               [12] 6299 	mov	r4,a
      001EFB A3               [24] 6300 	inc	dptr
      001EFC 12 37 EE         [24] 6301 	lcall	__gptrget
      001EFF FD               [12] 6302 	mov	r5,a
      001F00 A3               [24] 6303 	inc	dptr
      001F01 12 37 EE         [24] 6304 	lcall	__gptrget
      001F04 FE               [12] 6305 	mov	r6,a
      001F05 A3               [24] 6306 	inc	dptr
      001F06 12 37 EE         [24] 6307 	lcall	__gptrget
      001F09 FF               [12] 6308 	mov	r7,a
      001F0A E5 08            [12] 6309 	mov	a,_bp
      001F0C 24 14            [12] 6310 	add	a,#0x14
      001F0E F8               [12] 6311 	mov	r0,a
      001F0F E6               [12] 6312 	mov	a,@r0
      001F10 C0 E0            [24] 6313 	push	acc
      001F12 08               [12] 6314 	inc	r0
      001F13 E6               [12] 6315 	mov	a,@r0
      001F14 C0 E0            [24] 6316 	push	acc
      001F16 08               [12] 6317 	inc	r0
      001F17 E6               [12] 6318 	mov	a,@r0
      001F18 C0 E0            [24] 6319 	push	acc
      001F1A 08               [12] 6320 	inc	r0
      001F1B E6               [12] 6321 	mov	a,@r0
      001F1C C0 E0            [24] 6322 	push	acc
      001F1E 8C 82            [24] 6323 	mov	dpl, r4
      001F20 8D 83            [24] 6324 	mov	dph, r5
      001F22 8E F0            [24] 6325 	mov	b, r6
      001F24 EF               [12] 6326 	mov	a, r7
      001F25 12 35 C2         [24] 6327 	lcall	___fslt
      001F28 AF 82            [24] 6328 	mov	r7, dpl
      001F2A E5 81            [12] 6329 	mov	a,sp
      001F2C 24 FC            [12] 6330 	add	a,#0xfc
      001F2E F5 81            [12] 6331 	mov	sp,a
      001F30 EF               [12] 6332 	mov	a,r7
      001F31 70 03            [24] 6333 	jnz	00139$
      001F33 02 1F EE         [24] 6334 	ljmp	00104$
      001F36                       6335 00139$:
      001F36                       6336 00103$:
                           001E7F  6337 	C$fuzzy.h$2343$4_0$109 ==.
                                   6338 ;	../../fuzzy.h:2343: result->height =
      001F36 E5 08            [12] 6339 	mov	a,_bp
      001F38 24 0A            [12] 6340 	add	a,#0x0a
      001F3A F8               [12] 6341 	mov	r0,a
      001F3B 86 82            [24] 6342 	mov	dpl,@r0
      001F3D 08               [12] 6343 	inc	r0
      001F3E 86 83            [24] 6344 	mov	dph,@r0
      001F40 08               [12] 6345 	inc	r0
      001F41 86 F0            [24] 6346 	mov	b,@r0
      001F43 E5 08            [12] 6347 	mov	a,_bp
      001F45 24 14            [12] 6348 	add	a,#0x14
      001F47 F9               [12] 6349 	mov	r1,a
      001F48 E7               [12] 6350 	mov	a,@r1
      001F49 12 35 A7         [24] 6351 	lcall	__gptrput
      001F4C A3               [24] 6352 	inc	dptr
      001F4D 09               [12] 6353 	inc	r1
      001F4E E7               [12] 6354 	mov	a,@r1
      001F4F 12 35 A7         [24] 6355 	lcall	__gptrput
      001F52 A3               [24] 6356 	inc	dptr
      001F53 09               [12] 6357 	inc	r1
      001F54 E7               [12] 6358 	mov	a,@r1
      001F55 12 35 A7         [24] 6359 	lcall	__gptrput
      001F58 A3               [24] 6360 	inc	dptr
      001F59 09               [12] 6361 	inc	r1
      001F5A E7               [12] 6362 	mov	a,@r1
      001F5B 12 35 A7         [24] 6363 	lcall	__gptrput
                           001EA7  6364 	C$fuzzy.h$2346$4_0$109 ==.
                                   6365 ;	../../fuzzy.h:2346: result->smallest_position =
      001F5E A8 08            [24] 6366 	mov	r0,_bp
      001F60 08               [12] 6367 	inc	r0
      001F61 86 82            [24] 6368 	mov	dpl,@r0
      001F63 08               [12] 6369 	inc	r0
      001F64 86 83            [24] 6370 	mov	dph,@r0
      001F66 08               [12] 6371 	inc	r0
      001F67 86 F0            [24] 6372 	mov	b,@r0
      001F69 E5 08            [12] 6373 	mov	a,_bp
      001F6B 24 10            [12] 6374 	add	a,#0x10
      001F6D F9               [12] 6375 	mov	r1,a
      001F6E E7               [12] 6376 	mov	a,@r1
      001F6F 12 35 A7         [24] 6377 	lcall	__gptrput
      001F72 A3               [24] 6378 	inc	dptr
      001F73 09               [12] 6379 	inc	r1
      001F74 E7               [12] 6380 	mov	a,@r1
      001F75 12 35 A7         [24] 6381 	lcall	__gptrput
      001F78 A3               [24] 6382 	inc	dptr
      001F79 09               [12] 6383 	inc	r1
      001F7A E7               [12] 6384 	mov	a,@r1
      001F7B 12 35 A7         [24] 6385 	lcall	__gptrput
      001F7E A3               [24] 6386 	inc	dptr
      001F7F 09               [12] 6387 	inc	r1
      001F80 E7               [12] 6388 	mov	a,@r1
      001F81 12 35 A7         [24] 6389 	lcall	__gptrput
                           001ECD  6390 	C$fuzzy.h$2349$4_0$109 ==.
                                   6391 ;	../../fuzzy.h:2349: result->largest_position =
      001F84 E5 08            [12] 6392 	mov	a,_bp
      001F86 24 04            [12] 6393 	add	a,#0x04
      001F88 F8               [12] 6394 	mov	r0,a
      001F89 86 82            [24] 6395 	mov	dpl,@r0
      001F8B 08               [12] 6396 	inc	r0
      001F8C 86 83            [24] 6397 	mov	dph,@r0
      001F8E 08               [12] 6398 	inc	r0
      001F8F 86 F0            [24] 6399 	mov	b,@r0
      001F91 E5 08            [12] 6400 	mov	a,_bp
      001F93 24 10            [12] 6401 	add	a,#0x10
      001F95 F9               [12] 6402 	mov	r1,a
      001F96 E7               [12] 6403 	mov	a,@r1
      001F97 12 35 A7         [24] 6404 	lcall	__gptrput
      001F9A A3               [24] 6405 	inc	dptr
      001F9B 09               [12] 6406 	inc	r1
      001F9C E7               [12] 6407 	mov	a,@r1
      001F9D 12 35 A7         [24] 6408 	lcall	__gptrput
      001FA0 A3               [24] 6409 	inc	dptr
      001FA1 09               [12] 6410 	inc	r1
      001FA2 E7               [12] 6411 	mov	a,@r1
      001FA3 12 35 A7         [24] 6412 	lcall	__gptrput
      001FA6 A3               [24] 6413 	inc	dptr
      001FA7 09               [12] 6414 	inc	r1
      001FA8 E7               [12] 6415 	mov	a,@r1
      001FA9 12 35 A7         [24] 6416 	lcall	__gptrput
                           001EF5  6417 	C$fuzzy.h$2352$4_0$109 ==.
                                   6418 ;	../../fuzzy.h:2352: result->position_sum =
      001FAC E5 08            [12] 6419 	mov	a,_bp
      001FAE 24 07            [12] 6420 	add	a,#0x07
      001FB0 F8               [12] 6421 	mov	r0,a
      001FB1 86 82            [24] 6422 	mov	dpl,@r0
      001FB3 08               [12] 6423 	inc	r0
      001FB4 86 83            [24] 6424 	mov	dph,@r0
      001FB6 08               [12] 6425 	inc	r0
      001FB7 86 F0            [24] 6426 	mov	b,@r0
      001FB9 E5 08            [12] 6427 	mov	a,_bp
      001FBB 24 10            [12] 6428 	add	a,#0x10
      001FBD F9               [12] 6429 	mov	r1,a
      001FBE E7               [12] 6430 	mov	a,@r1
      001FBF 12 35 A7         [24] 6431 	lcall	__gptrput
      001FC2 A3               [24] 6432 	inc	dptr
      001FC3 09               [12] 6433 	inc	r1
      001FC4 E7               [12] 6434 	mov	a,@r1
      001FC5 12 35 A7         [24] 6435 	lcall	__gptrput
      001FC8 A3               [24] 6436 	inc	dptr
      001FC9 09               [12] 6437 	inc	r1
      001FCA E7               [12] 6438 	mov	a,@r1
      001FCB 12 35 A7         [24] 6439 	lcall	__gptrput
      001FCE A3               [24] 6440 	inc	dptr
      001FCF 09               [12] 6441 	inc	r1
      001FD0 E7               [12] 6442 	mov	a,@r1
      001FD1 12 35 A7         [24] 6443 	lcall	__gptrput
                           001F1D  6444 	C$fuzzy.h$2355$4_0$109 ==.
                                   6445 ;	../../fuzzy.h:2355: result->position_count =
      001FD4 E5 08            [12] 6446 	mov	a,_bp
      001FD6 24 0D            [12] 6447 	add	a,#0x0d
      001FD8 F8               [12] 6448 	mov	r0,a
      001FD9 86 82            [24] 6449 	mov	dpl,@r0
      001FDB 08               [12] 6450 	inc	r0
      001FDC 86 83            [24] 6451 	mov	dph,@r0
      001FDE 08               [12] 6452 	inc	r0
      001FDF 86 F0            [24] 6453 	mov	b,@r0
      001FE1 74 01            [12] 6454 	mov	a,#0x01
      001FE3 12 35 A7         [24] 6455 	lcall	__gptrput
      001FE6 A3               [24] 6456 	inc	dptr
      001FE7 E4               [12] 6457 	clr	a
      001FE8 12 35 A7         [24] 6458 	lcall	__gptrput
      001FEB 02 20 FA         [24] 6459 	ljmp	00110$
      001FEE                       6460 00104$:
                           001F37  6461 	C$fuzzy.h$2360$2_0$106 ==.
                                   6462 ;	../../fuzzy.h:2360: result->height
      001FEE E5 08            [12] 6463 	mov	a,_bp
      001FF0 24 0A            [12] 6464 	add	a,#0x0a
      001FF2 F8               [12] 6465 	mov	r0,a
      001FF3 86 82            [24] 6466 	mov	dpl,@r0
      001FF5 08               [12] 6467 	inc	r0
      001FF6 86 83            [24] 6468 	mov	dph,@r0
      001FF8 08               [12] 6469 	inc	r0
      001FF9 86 F0            [24] 6470 	mov	b,@r0
      001FFB 12 37 EE         [24] 6471 	lcall	__gptrget
      001FFE FC               [12] 6472 	mov	r4,a
      001FFF A3               [24] 6473 	inc	dptr
      002000 12 37 EE         [24] 6474 	lcall	__gptrget
      002003 FD               [12] 6475 	mov	r5,a
      002004 A3               [24] 6476 	inc	dptr
      002005 12 37 EE         [24] 6477 	lcall	__gptrget
      002008 FE               [12] 6478 	mov	r6,a
      002009 A3               [24] 6479 	inc	dptr
      00200A 12 37 EE         [24] 6480 	lcall	__gptrget
      00200D FF               [12] 6481 	mov	r7,a
      00200E C0 04            [24] 6482 	push	ar4
      002010 C0 05            [24] 6483 	push	ar5
      002012 C0 06            [24] 6484 	push	ar6
      002014 C0 07            [24] 6485 	push	ar7
      002016 E5 08            [12] 6486 	mov	a,_bp
      002018 24 14            [12] 6487 	add	a,#0x14
      00201A F8               [12] 6488 	mov	r0,a
      00201B 86 82            [24] 6489 	mov	dpl, @r0
      00201D 08               [12] 6490 	inc	r0
      00201E 86 83            [24] 6491 	mov	dph, @r0
      002020 08               [12] 6492 	inc	r0
      002021 86 F0            [24] 6493 	mov	b, @r0
      002023 08               [12] 6494 	inc	r0
      002024 E6               [12] 6495 	mov	a, @r0
      002025 12 35 96         [24] 6496 	lcall	___fseq
      002028 AF 82            [24] 6497 	mov	r7, dpl
      00202A E5 81            [12] 6498 	mov	a,sp
      00202C 24 FC            [12] 6499 	add	a,#0xfc
      00202E F5 81            [12] 6500 	mov	sp,a
      002030 EF               [12] 6501 	mov	a,r7
      002031 70 03            [24] 6502 	jnz	00140$
      002033 02 20 FA         [24] 6503 	ljmp	00110$
      002036                       6504 00140$:
                           001F7F  6505 	C$fuzzy.h$2362$4_0$110 ==.
                                   6506 ;	../../fuzzy.h:2362: result->largest_position =
      002036 E5 08            [12] 6507 	mov	a,_bp
      002038 24 04            [12] 6508 	add	a,#0x04
      00203A F8               [12] 6509 	mov	r0,a
      00203B 86 82            [24] 6510 	mov	dpl,@r0
      00203D 08               [12] 6511 	inc	r0
      00203E 86 83            [24] 6512 	mov	dph,@r0
      002040 08               [12] 6513 	inc	r0
      002041 86 F0            [24] 6514 	mov	b,@r0
      002043 E5 08            [12] 6515 	mov	a,_bp
      002045 24 10            [12] 6516 	add	a,#0x10
      002047 F9               [12] 6517 	mov	r1,a
      002048 E7               [12] 6518 	mov	a,@r1
      002049 12 35 A7         [24] 6519 	lcall	__gptrput
      00204C A3               [24] 6520 	inc	dptr
      00204D 09               [12] 6521 	inc	r1
      00204E E7               [12] 6522 	mov	a,@r1
      00204F 12 35 A7         [24] 6523 	lcall	__gptrput
      002052 A3               [24] 6524 	inc	dptr
      002053 09               [12] 6525 	inc	r1
      002054 E7               [12] 6526 	mov	a,@r1
      002055 12 35 A7         [24] 6527 	lcall	__gptrput
      002058 A3               [24] 6528 	inc	dptr
      002059 09               [12] 6529 	inc	r1
      00205A E7               [12] 6530 	mov	a,@r1
      00205B 12 35 A7         [24] 6531 	lcall	__gptrput
                           001FA7  6532 	C$fuzzy.h$2365$4_0$110 ==.
                                   6533 ;	../../fuzzy.h:2365: result->position_sum +=
      00205E E5 08            [12] 6534 	mov	a,_bp
      002060 24 07            [12] 6535 	add	a,#0x07
      002062 F8               [12] 6536 	mov	r0,a
      002063 86 82            [24] 6537 	mov	dpl,@r0
      002065 08               [12] 6538 	inc	r0
      002066 86 83            [24] 6539 	mov	dph,@r0
      002068 08               [12] 6540 	inc	r0
      002069 86 F0            [24] 6541 	mov	b,@r0
      00206B 12 37 EE         [24] 6542 	lcall	__gptrget
      00206E FC               [12] 6543 	mov	r4,a
      00206F A3               [24] 6544 	inc	dptr
      002070 12 37 EE         [24] 6545 	lcall	__gptrget
      002073 FD               [12] 6546 	mov	r5,a
      002074 A3               [24] 6547 	inc	dptr
      002075 12 37 EE         [24] 6548 	lcall	__gptrget
      002078 FE               [12] 6549 	mov	r6,a
      002079 A3               [24] 6550 	inc	dptr
      00207A 12 37 EE         [24] 6551 	lcall	__gptrget
      00207D FF               [12] 6552 	mov	r7,a
      00207E E5 08            [12] 6553 	mov	a,_bp
      002080 24 10            [12] 6554 	add	a,#0x10
      002082 F8               [12] 6555 	mov	r0,a
      002083 E6               [12] 6556 	mov	a,@r0
      002084 C0 E0            [24] 6557 	push	acc
      002086 08               [12] 6558 	inc	r0
      002087 E6               [12] 6559 	mov	a,@r0
      002088 C0 E0            [24] 6560 	push	acc
      00208A 08               [12] 6561 	inc	r0
      00208B E6               [12] 6562 	mov	a,@r0
      00208C C0 E0            [24] 6563 	push	acc
      00208E 08               [12] 6564 	inc	r0
      00208F E6               [12] 6565 	mov	a,@r0
      002090 C0 E0            [24] 6566 	push	acc
      002092 8C 82            [24] 6567 	mov	dpl, r4
      002094 8D 83            [24] 6568 	mov	dph, r5
      002096 8E F0            [24] 6569 	mov	b, r6
      002098 EF               [12] 6570 	mov	a, r7
      002099 12 36 14         [24] 6571 	lcall	___fsadd
      00209C AC 82            [24] 6572 	mov	r4, dpl
      00209E AD 83            [24] 6573 	mov	r5, dph
      0020A0 AE F0            [24] 6574 	mov	r6, b
      0020A2 FF               [12] 6575 	mov	r7, a
      0020A3 E5 81            [12] 6576 	mov	a,sp
      0020A5 24 FC            [12] 6577 	add	a,#0xfc
      0020A7 F5 81            [12] 6578 	mov	sp,a
      0020A9 E5 08            [12] 6579 	mov	a,_bp
      0020AB 24 07            [12] 6580 	add	a,#0x07
      0020AD F8               [12] 6581 	mov	r0,a
      0020AE 86 82            [24] 6582 	mov	dpl,@r0
      0020B0 08               [12] 6583 	inc	r0
      0020B1 86 83            [24] 6584 	mov	dph,@r0
      0020B3 08               [12] 6585 	inc	r0
      0020B4 86 F0            [24] 6586 	mov	b,@r0
      0020B6 EC               [12] 6587 	mov	a,r4
      0020B7 12 35 A7         [24] 6588 	lcall	__gptrput
      0020BA A3               [24] 6589 	inc	dptr
      0020BB ED               [12] 6590 	mov	a,r5
      0020BC 12 35 A7         [24] 6591 	lcall	__gptrput
      0020BF A3               [24] 6592 	inc	dptr
      0020C0 EE               [12] 6593 	mov	a,r6
      0020C1 12 35 A7         [24] 6594 	lcall	__gptrput
      0020C4 A3               [24] 6595 	inc	dptr
      0020C5 EF               [12] 6596 	mov	a,r7
      0020C6 12 35 A7         [24] 6597 	lcall	__gptrput
                           002012  6598 	C$fuzzy.h$2368$4_0$110 ==.
                                   6599 ;	../../fuzzy.h:2368: result->position_count++;
      0020C9 E5 08            [12] 6600 	mov	a,_bp
      0020CB 24 0D            [12] 6601 	add	a,#0x0d
      0020CD F8               [12] 6602 	mov	r0,a
      0020CE 86 82            [24] 6603 	mov	dpl,@r0
      0020D0 08               [12] 6604 	inc	r0
      0020D1 86 83            [24] 6605 	mov	dph,@r0
      0020D3 08               [12] 6606 	inc	r0
      0020D4 86 F0            [24] 6607 	mov	b,@r0
      0020D6 12 37 EE         [24] 6608 	lcall	__gptrget
      0020D9 FF               [12] 6609 	mov	r7,a
      0020DA A3               [24] 6610 	inc	dptr
      0020DB 12 37 EE         [24] 6611 	lcall	__gptrget
      0020DE FE               [12] 6612 	mov	r6,a
      0020DF 0F               [12] 6613 	inc	r7
      0020E0 BF 00 01         [24] 6614 	cjne	r7,#0x00,00141$
      0020E3 0E               [12] 6615 	inc	r6
      0020E4                       6616 00141$:
      0020E4 E5 08            [12] 6617 	mov	a,_bp
      0020E6 24 0D            [12] 6618 	add	a,#0x0d
      0020E8 F8               [12] 6619 	mov	r0,a
      0020E9 86 82            [24] 6620 	mov	dpl,@r0
      0020EB 08               [12] 6621 	inc	r0
      0020EC 86 83            [24] 6622 	mov	dph,@r0
      0020EE 08               [12] 6623 	inc	r0
      0020EF 86 F0            [24] 6624 	mov	b,@r0
      0020F1 EF               [12] 6625 	mov	a,r7
      0020F2 12 35 A7         [24] 6626 	lcall	__gptrput
      0020F5 A3               [24] 6627 	inc	dptr
      0020F6 EE               [12] 6628 	mov	a,r6
      0020F7 12 35 A7         [24] 6629 	lcall	__gptrput
      0020FA                       6630 00110$:
                           002043  6631 	C$fuzzy.h$2330$2_0$106 ==.
                                   6632 ;	../../fuzzy.h:2330: ) {
      0020FA E5 08            [12] 6633 	mov	a,_bp
      0020FC 24 EF            [12] 6634 	add	a,#0xef
      0020FE F8               [12] 6635 	mov	r0,a
      0020FF E6               [12] 6636 	mov	a,@r0
      002100 C0 E0            [24] 6637 	push	acc
      002102 08               [12] 6638 	inc	r0
      002103 E6               [12] 6639 	mov	a,@r0
      002104 C0 E0            [24] 6640 	push	acc
      002106 08               [12] 6641 	inc	r0
      002107 E6               [12] 6642 	mov	a,@r0
      002108 C0 E0            [24] 6643 	push	acc
      00210A 08               [12] 6644 	inc	r0
      00210B E6               [12] 6645 	mov	a,@r0
      00210C C0 E0            [24] 6646 	push	acc
      00210E E5 08            [12] 6647 	mov	a,_bp
      002110 24 10            [12] 6648 	add	a,#0x10
      002112 F8               [12] 6649 	mov	r0,a
      002113 86 82            [24] 6650 	mov	dpl, @r0
      002115 08               [12] 6651 	inc	r0
      002116 86 83            [24] 6652 	mov	dph, @r0
      002118 08               [12] 6653 	inc	r0
      002119 86 F0            [24] 6654 	mov	b, @r0
      00211B 08               [12] 6655 	inc	r0
      00211C E6               [12] 6656 	mov	a, @r0
      00211D 12 36 14         [24] 6657 	lcall	___fsadd
      002120 C8               [12] 6658 	xch	a,r0
      002121 E5 08            [12] 6659 	mov	a,_bp
      002123 24 10            [12] 6660 	add	a,#0x10
      002125 C8               [12] 6661 	xch	a,r0
      002126 A6 82            [24] 6662 	mov	@r0, dpl
      002128 08               [12] 6663 	inc	r0
      002129 A6 83            [24] 6664 	mov	@r0, dph
      00212B 08               [12] 6665 	inc	r0
      00212C A6 F0            [24] 6666 	mov	@r0, b
      00212E 08               [12] 6667 	inc	r0
      00212F F6               [12] 6668 	mov	@r0,a
      002130 E5 81            [12] 6669 	mov	a,sp
      002132 24 FC            [12] 6670 	add	a,#0xfc
      002134 F5 81            [12] 6671 	mov	sp,a
      002136 02 1E 51         [24] 6672 	ljmp	00109$
      002139                       6673 00111$:
                           002082  6674 	C$fuzzy.h$2371$2_0$106 ==.
                                   6675 ;	../../fuzzy.h:2371: }
      002139 85 08 81         [24] 6676 	mov	sp,_bp
      00213C D0 08            [24] 6677 	pop	_bp
                           002087  6678 	C$fuzzy.h$2371$2_0$106 ==.
                           002087  6679 	XFcontroller_8051$fuzzy_rules_maximum_result$0$0 ==.
      00213E 22               [24] 6680 	ret
                                   6681 ;------------------------------------------------------------
                                   6682 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_cog'
                                   6683 ;------------------------------------------------------------
                                   6684 ;lower         Allocated to stack - _bp -6 +4 
                                   6685 ;upper         Allocated to stack - _bp -10 +4 
                                   6686 ;step          Allocated to stack - _bp -14 +4 
                                   6687 ;implication_method Allocated to stack - _bp -15 +1 
                                   6688 ;aggregation_method Allocated to stack - _bp -16 +1 
                                   6689 ;rules         Allocated to stack - _bp +1 +3 
                                   6690 ;weighted_sum  Allocated to stack - _bp +4 +4 
                                   6691 ;height_sum    Allocated to stack - _bp +8 +4 
                                   6692 ;value         Allocated to stack - _bp +12 +4 
                                   6693 ;height        Allocated to stack - _bp +16 +4 
                                   6694 ;------------------------------------------------------------
                           002088  6695 	G$fuzzy_rules_defuzzify_cog$0$0 ==.
                           002088  6696 	C$fuzzy.h$2378$2_0$112 ==.
                                   6697 ;	../../fuzzy.h:2378: float fuzzy_rules_defuzzify_cog(
                                   6698 ;	-----------------------------------------
                                   6699 ;	 function fuzzy_rules_defuzzify_cog
                                   6700 ;	-----------------------------------------
      00213F                       6701 _fuzzy_rules_defuzzify_cog:
      00213F C0 08            [24] 6702 	push	_bp
      002141 85 81 08         [24] 6703 	mov	_bp,sp
      002144 C0 82            [24] 6704 	push	dpl
      002146 C0 83            [24] 6705 	push	dph
      002148 C0 F0            [24] 6706 	push	b
      00214A E5 81            [12] 6707 	mov	a,sp
      00214C 24 10            [12] 6708 	add	a,#0x10
      00214E F5 81            [12] 6709 	mov	sp,a
                           002099  6710 	C$fuzzy.h$2393$1_0$112 ==.
                                   6711 ;	../../fuzzy.h:2393: 0.0f;
      002150 E5 08            [12] 6712 	mov	a,_bp
      002152 24 04            [12] 6713 	add	a,#0x04
      002154 F8               [12] 6714 	mov	r0,a
      002155 E4               [12] 6715 	clr	a
      002156 F6               [12] 6716 	mov	@r0,a
      002157 08               [12] 6717 	inc	r0
      002158 F6               [12] 6718 	mov	@r0,a
      002159 08               [12] 6719 	inc	r0
      00215A F6               [12] 6720 	mov	@r0,a
      00215B 08               [12] 6721 	inc	r0
      00215C F6               [12] 6722 	mov	@r0,a
                           0020A6  6723 	C$fuzzy.h$2396$1_0$112 ==.
                                   6724 ;	../../fuzzy.h:2396: 0.0f;
      00215D E5 08            [12] 6725 	mov	a,_bp
      00215F 24 08            [12] 6726 	add	a,#0x08
      002161 F8               [12] 6727 	mov	r0,a
      002162 E4               [12] 6728 	clr	a
      002163 F6               [12] 6729 	mov	@r0,a
      002164 08               [12] 6730 	inc	r0
      002165 F6               [12] 6731 	mov	@r0,a
      002166 08               [12] 6732 	inc	r0
      002167 F6               [12] 6733 	mov	@r0,a
      002168 08               [12] 6734 	inc	r0
      002169 F6               [12] 6735 	mov	@r0,a
                           0020B3  6736 	C$fuzzy.h$2399$2_0$113 ==.
                                   6737 ;	../../fuzzy.h:2399: value = lower;
      00216A E5 08            [12] 6738 	mov	a,_bp
      00216C 24 FA            [12] 6739 	add	a,#0xfa
      00216E F8               [12] 6740 	mov	r0,a
      00216F E5 08            [12] 6741 	mov	a,_bp
      002171 24 0C            [12] 6742 	add	a,#0x0c
      002173 F9               [12] 6743 	mov	r1,a
      002174 E6               [12] 6744 	mov	a,@r0
      002175 F7               [12] 6745 	mov	@r1,a
      002176 08               [12] 6746 	inc	r0
      002177 E6               [12] 6747 	mov	a,@r0
      002178 09               [12] 6748 	inc	r1
      002179 F7               [12] 6749 	mov	@r1,a
      00217A 08               [12] 6750 	inc	r0
      00217B E6               [12] 6751 	mov	a,@r0
      00217C 09               [12] 6752 	inc	r1
      00217D F7               [12] 6753 	mov	@r1,a
      00217E 08               [12] 6754 	inc	r0
      00217F E6               [12] 6755 	mov	a,@r0
      002180 09               [12] 6756 	inc	r1
      002181 F7               [12] 6757 	mov	@r1,a
      002182                       6758 00105$:
                           0020CB  6759 	C$fuzzy.h$2400$1_0$112 ==.
                                   6760 ;	../../fuzzy.h:2400: value <= upper;
      002182 E5 08            [12] 6761 	mov	a,_bp
      002184 24 0C            [12] 6762 	add	a,#0x0c
      002186 F8               [12] 6763 	mov	r0,a
      002187 E6               [12] 6764 	mov	a,@r0
      002188 C0 E0            [24] 6765 	push	acc
      00218A 08               [12] 6766 	inc	r0
      00218B E6               [12] 6767 	mov	a,@r0
      00218C C0 E0            [24] 6768 	push	acc
      00218E 08               [12] 6769 	inc	r0
      00218F E6               [12] 6770 	mov	a,@r0
      002190 C0 E0            [24] 6771 	push	acc
      002192 08               [12] 6772 	inc	r0
      002193 E6               [12] 6773 	mov	a,@r0
      002194 C0 E0            [24] 6774 	push	acc
      002196 E5 08            [12] 6775 	mov	a,_bp
      002198 24 F6            [12] 6776 	add	a,#0xf6
      00219A F8               [12] 6777 	mov	r0,a
      00219B 86 82            [24] 6778 	mov	dpl, @r0
      00219D 08               [12] 6779 	inc	r0
      00219E 86 83            [24] 6780 	mov	dph, @r0
      0021A0 08               [12] 6781 	inc	r0
      0021A1 86 F0            [24] 6782 	mov	b, @r0
      0021A3 08               [12] 6783 	inc	r0
      0021A4 E6               [12] 6784 	mov	a, @r0
      0021A5 12 35 C2         [24] 6785 	lcall	___fslt
      0021A8 E5 81            [12] 6786 	mov	a,sp
      0021AA 24 FC            [12] 6787 	add	a,#0xfc
      0021AC F5 81            [12] 6788 	mov	sp,a
      0021AE E5 82            [12] 6789 	mov	a, dpl
      0021B0 24 FF            [12] 6790 	add	a,#0xff
      0021B2 92 00            [24] 6791 	mov	b0,c
      0021B4 50 03            [24] 6792 	jnc	00127$
      0021B6 02 22 DF         [24] 6793 	ljmp	00101$
      0021B9                       6794 00127$:
                           002102  6795 	C$fuzzy.h$2405$3_0$114 ==.
                                   6796 ;	../../fuzzy.h:2405: rules,
      0021B9 E5 08            [12] 6797 	mov	a,_bp
      0021BB 24 F0            [12] 6798 	add	a,#0xf0
      0021BD F8               [12] 6799 	mov	r0,a
      0021BE E6               [12] 6800 	mov	a,@r0
      0021BF C0 E0            [24] 6801 	push	acc
      0021C1 E5 08            [12] 6802 	mov	a,_bp
      0021C3 24 F1            [12] 6803 	add	a,#0xf1
      0021C5 F8               [12] 6804 	mov	r0,a
      0021C6 E6               [12] 6805 	mov	a,@r0
      0021C7 C0 E0            [24] 6806 	push	acc
      0021C9 E5 08            [12] 6807 	mov	a,_bp
      0021CB 24 0C            [12] 6808 	add	a,#0x0c
      0021CD F8               [12] 6809 	mov	r0,a
      0021CE E6               [12] 6810 	mov	a,@r0
      0021CF C0 E0            [24] 6811 	push	acc
      0021D1 08               [12] 6812 	inc	r0
      0021D2 E6               [12] 6813 	mov	a,@r0
      0021D3 C0 E0            [24] 6814 	push	acc
      0021D5 08               [12] 6815 	inc	r0
      0021D6 E6               [12] 6816 	mov	a,@r0
      0021D7 C0 E0            [24] 6817 	push	acc
      0021D9 08               [12] 6818 	inc	r0
      0021DA E6               [12] 6819 	mov	a,@r0
      0021DB C0 E0            [24] 6820 	push	acc
      0021DD A8 08            [24] 6821 	mov	r0,_bp
      0021DF 08               [12] 6822 	inc	r0
      0021E0 86 82            [24] 6823 	mov	dpl, @r0
      0021E2 08               [12] 6824 	inc	r0
      0021E3 86 83            [24] 6825 	mov	dph, @r0
      0021E5 08               [12] 6826 	inc	r0
      0021E6 86 F0            [24] 6827 	mov	b, @r0
      0021E8 12 1B 98         [24] 6828 	lcall	_fuzzy_rules_aggregated_height
      0021EB C8               [12] 6829 	xch	a,r0
      0021EC E5 08            [12] 6830 	mov	a,_bp
      0021EE 24 10            [12] 6831 	add	a,#0x10
      0021F0 C8               [12] 6832 	xch	a,r0
      0021F1 A6 82            [24] 6833 	mov	@r0, dpl
      0021F3 08               [12] 6834 	inc	r0
      0021F4 A6 83            [24] 6835 	mov	@r0, dph
      0021F6 08               [12] 6836 	inc	r0
      0021F7 A6 F0            [24] 6837 	mov	@r0, b
      0021F9 08               [12] 6838 	inc	r0
      0021FA F6               [12] 6839 	mov	@r0,a
      0021FB E5 81            [12] 6840 	mov	a,sp
      0021FD 24 FA            [12] 6841 	add	a,#0xfa
      0021FF F5 81            [12] 6842 	mov	sp,a
                           00214A  6843 	C$fuzzy.h$2413$1_0$112 ==.
                                   6844 ;	../../fuzzy.h:2413: height;
      002201 E5 08            [12] 6845 	mov	a,_bp
      002203 24 10            [12] 6846 	add	a,#0x10
      002205 F8               [12] 6847 	mov	r0,a
      002206 E6               [12] 6848 	mov	a,@r0
      002207 C0 E0            [24] 6849 	push	acc
      002209 08               [12] 6850 	inc	r0
      00220A E6               [12] 6851 	mov	a,@r0
      00220B C0 E0            [24] 6852 	push	acc
      00220D 08               [12] 6853 	inc	r0
      00220E E6               [12] 6854 	mov	a,@r0
      00220F C0 E0            [24] 6855 	push	acc
      002211 08               [12] 6856 	inc	r0
      002212 E6               [12] 6857 	mov	a,@r0
      002213 C0 E0            [24] 6858 	push	acc
      002215 E5 08            [12] 6859 	mov	a,_bp
      002217 24 0C            [12] 6860 	add	a,#0x0c
      002219 F8               [12] 6861 	mov	r0,a
      00221A 86 82            [24] 6862 	mov	dpl, @r0
      00221C 08               [12] 6863 	inc	r0
      00221D 86 83            [24] 6864 	mov	dph, @r0
      00221F 08               [12] 6865 	inc	r0
      002220 86 F0            [24] 6866 	mov	b, @r0
      002222 08               [12] 6867 	inc	r0
      002223 E6               [12] 6868 	mov	a, @r0
      002224 12 34 92         [24] 6869 	lcall	___fsmul
      002227 AC 82            [24] 6870 	mov	r4, dpl
      002229 AD 83            [24] 6871 	mov	r5, dph
      00222B AE F0            [24] 6872 	mov	r6, b
      00222D FF               [12] 6873 	mov	r7, a
      00222E E5 81            [12] 6874 	mov	a,sp
      002230 24 FC            [12] 6875 	add	a,#0xfc
      002232 F5 81            [12] 6876 	mov	sp,a
      002234 C0 04            [24] 6877 	push	ar4
      002236 C0 05            [24] 6878 	push	ar5
      002238 C0 06            [24] 6879 	push	ar6
      00223A C0 07            [24] 6880 	push	ar7
                           002185  6881 	C$fuzzy.h$2416$1_0$112 ==.
                                   6882 ;	../../fuzzy.h:2416: height;
      00223C E5 08            [12] 6883 	mov	a,_bp
      00223E 24 04            [12] 6884 	add	a,#0x04
      002240 F8               [12] 6885 	mov	r0,a
      002241 86 82            [24] 6886 	mov	dpl, @r0
      002243 08               [12] 6887 	inc	r0
      002244 86 83            [24] 6888 	mov	dph, @r0
      002246 08               [12] 6889 	inc	r0
      002247 86 F0            [24] 6890 	mov	b, @r0
      002249 08               [12] 6891 	inc	r0
      00224A E6               [12] 6892 	mov	a, @r0
      00224B 12 36 14         [24] 6893 	lcall	___fsadd
      00224E C8               [12] 6894 	xch	a,r0
      00224F E5 08            [12] 6895 	mov	a,_bp
      002251 24 04            [12] 6896 	add	a,#0x04
      002253 C8               [12] 6897 	xch	a,r0
      002254 A6 82            [24] 6898 	mov	@r0, dpl
      002256 08               [12] 6899 	inc	r0
      002257 A6 83            [24] 6900 	mov	@r0, dph
      002259 08               [12] 6901 	inc	r0
      00225A A6 F0            [24] 6902 	mov	@r0, b
      00225C 08               [12] 6903 	inc	r0
      00225D F6               [12] 6904 	mov	@r0,a
      00225E E5 81            [12] 6905 	mov	a,sp
      002260 24 FC            [12] 6906 	add	a,#0xfc
      002262 F5 81            [12] 6907 	mov	sp,a
      002264 E5 08            [12] 6908 	mov	a,_bp
      002266 24 10            [12] 6909 	add	a,#0x10
      002268 F8               [12] 6910 	mov	r0,a
      002269 E6               [12] 6911 	mov	a,@r0
      00226A C0 E0            [24] 6912 	push	acc
      00226C 08               [12] 6913 	inc	r0
      00226D E6               [12] 6914 	mov	a,@r0
      00226E C0 E0            [24] 6915 	push	acc
      002270 08               [12] 6916 	inc	r0
      002271 E6               [12] 6917 	mov	a,@r0
      002272 C0 E0            [24] 6918 	push	acc
      002274 08               [12] 6919 	inc	r0
      002275 E6               [12] 6920 	mov	a,@r0
      002276 C0 E0            [24] 6921 	push	acc
                           0021C1  6922 	C$fuzzy.h$2402$1_0$112 ==.
                                   6923 ;	../../fuzzy.h:2402: ) {
      002278 E5 08            [12] 6924 	mov	a,_bp
      00227A 24 08            [12] 6925 	add	a,#0x08
      00227C F8               [12] 6926 	mov	r0,a
      00227D 86 82            [24] 6927 	mov	dpl, @r0
      00227F 08               [12] 6928 	inc	r0
      002280 86 83            [24] 6929 	mov	dph, @r0
      002282 08               [12] 6930 	inc	r0
      002283 86 F0            [24] 6931 	mov	b, @r0
      002285 08               [12] 6932 	inc	r0
      002286 E6               [12] 6933 	mov	a, @r0
      002287 12 36 14         [24] 6934 	lcall	___fsadd
      00228A C8               [12] 6935 	xch	a,r0
      00228B E5 08            [12] 6936 	mov	a,_bp
      00228D 24 08            [12] 6937 	add	a,#0x08
      00228F C8               [12] 6938 	xch	a,r0
      002290 A6 82            [24] 6939 	mov	@r0, dpl
      002292 08               [12] 6940 	inc	r0
      002293 A6 83            [24] 6941 	mov	@r0, dph
      002295 08               [12] 6942 	inc	r0
      002296 A6 F0            [24] 6943 	mov	@r0, b
      002298 08               [12] 6944 	inc	r0
      002299 F6               [12] 6945 	mov	@r0,a
      00229A E5 81            [12] 6946 	mov	a,sp
      00229C 24 FC            [12] 6947 	add	a,#0xfc
      00229E F5 81            [12] 6948 	mov	sp,a
      0022A0 E5 08            [12] 6949 	mov	a,_bp
      0022A2 24 F2            [12] 6950 	add	a,#0xf2
      0022A4 F8               [12] 6951 	mov	r0,a
      0022A5 E6               [12] 6952 	mov	a,@r0
      0022A6 C0 E0            [24] 6953 	push	acc
      0022A8 08               [12] 6954 	inc	r0
      0022A9 E6               [12] 6955 	mov	a,@r0
      0022AA C0 E0            [24] 6956 	push	acc
      0022AC 08               [12] 6957 	inc	r0
      0022AD E6               [12] 6958 	mov	a,@r0
      0022AE C0 E0            [24] 6959 	push	acc
      0022B0 08               [12] 6960 	inc	r0
      0022B1 E6               [12] 6961 	mov	a,@r0
      0022B2 C0 E0            [24] 6962 	push	acc
      0022B4 E5 08            [12] 6963 	mov	a,_bp
      0022B6 24 0C            [12] 6964 	add	a,#0x0c
      0022B8 F8               [12] 6965 	mov	r0,a
      0022B9 86 82            [24] 6966 	mov	dpl, @r0
      0022BB 08               [12] 6967 	inc	r0
      0022BC 86 83            [24] 6968 	mov	dph, @r0
      0022BE 08               [12] 6969 	inc	r0
      0022BF 86 F0            [24] 6970 	mov	b, @r0
      0022C1 08               [12] 6971 	inc	r0
      0022C2 E6               [12] 6972 	mov	a, @r0
      0022C3 12 36 14         [24] 6973 	lcall	___fsadd
      0022C6 C8               [12] 6974 	xch	a,r0
      0022C7 E5 08            [12] 6975 	mov	a,_bp
      0022C9 24 0C            [12] 6976 	add	a,#0x0c
      0022CB C8               [12] 6977 	xch	a,r0
      0022CC A6 82            [24] 6978 	mov	@r0, dpl
      0022CE 08               [12] 6979 	inc	r0
      0022CF A6 83            [24] 6980 	mov	@r0, dph
      0022D1 08               [12] 6981 	inc	r0
      0022D2 A6 F0            [24] 6982 	mov	@r0, b
      0022D4 08               [12] 6983 	inc	r0
      0022D5 F6               [12] 6984 	mov	@r0,a
      0022D6 E5 81            [12] 6985 	mov	a,sp
      0022D8 24 FC            [12] 6986 	add	a,#0xfc
      0022DA F5 81            [12] 6987 	mov	sp,a
      0022DC 02 21 82         [24] 6988 	ljmp	00105$
      0022DF                       6989 00101$:
                           002228  6990 	C$fuzzy.h$2419$1_0$112 ==.
                                   6991 ;	../../fuzzy.h:2419: if (height_sum <= LEVEL_LO) {
      0022DF E5 08            [12] 6992 	mov	a,_bp
      0022E1 24 08            [12] 6993 	add	a,#0x08
      0022E3 F8               [12] 6994 	mov	r0,a
      0022E4 E6               [12] 6995 	mov	a,@r0
      0022E5 C0 E0            [24] 6996 	push	acc
      0022E7 08               [12] 6997 	inc	r0
      0022E8 E6               [12] 6998 	mov	a,@r0
      0022E9 C0 E0            [24] 6999 	push	acc
      0022EB 08               [12] 7000 	inc	r0
      0022EC E6               [12] 7001 	mov	a,@r0
      0022ED C0 E0            [24] 7002 	push	acc
      0022EF 08               [12] 7003 	inc	r0
      0022F0 E6               [12] 7004 	mov	a,@r0
      0022F1 C0 E0            [24] 7005 	push	acc
      0022F3 90 00 00         [24] 7006 	mov	dptr,#0x0000
      0022F6 E4               [12] 7007 	clr	a
      0022F7 F5 F0            [12] 7008 	mov	b,a
      0022F9 12 35 C2         [24] 7009 	lcall	___fslt
      0022FC E5 81            [12] 7010 	mov	a,sp
      0022FE 24 FC            [12] 7011 	add	a,#0xfc
      002300 F5 81            [12] 7012 	mov	sp,a
      002302 E5 82            [12] 7013 	mov	a, dpl
      002304 24 FF            [12] 7014 	add	a,#0xff
      002306 92 00            [24] 7015 	mov	b0,c
      002308 40 08            [24] 7016 	jc	00103$
                           002253  7017 	C$fuzzy.h$2420$2_0$115 ==.
                                   7018 ;	../../fuzzy.h:2420: return 0.0f;
      00230A 90 00 00         [24] 7019 	mov	dptr,#0x0000
      00230D E4               [12] 7020 	clr	a
      00230E F5 F0            [12] 7021 	mov	b,a
      002310 80 3A            [24] 7022 	sjmp	00107$
      002312                       7023 00103$:
                           00225B  7024 	C$fuzzy.h$2424$1_0$112 ==.
                                   7025 ;	../../fuzzy.h:2424: height_sum;
      002312 E5 08            [12] 7026 	mov	a,_bp
      002314 24 08            [12] 7027 	add	a,#0x08
      002316 F8               [12] 7028 	mov	r0,a
      002317 E6               [12] 7029 	mov	a,@r0
      002318 C0 E0            [24] 7030 	push	acc
      00231A 08               [12] 7031 	inc	r0
      00231B E6               [12] 7032 	mov	a,@r0
      00231C C0 E0            [24] 7033 	push	acc
      00231E 08               [12] 7034 	inc	r0
      00231F E6               [12] 7035 	mov	a,@r0
      002320 C0 E0            [24] 7036 	push	acc
      002322 08               [12] 7037 	inc	r0
      002323 E6               [12] 7038 	mov	a,@r0
      002324 C0 E0            [24] 7039 	push	acc
      002326 E5 08            [12] 7040 	mov	a,_bp
      002328 24 04            [12] 7041 	add	a,#0x04
      00232A F8               [12] 7042 	mov	r0,a
      00232B 86 82            [24] 7043 	mov	dpl, @r0
      00232D 08               [12] 7044 	inc	r0
      00232E 86 83            [24] 7045 	mov	dph, @r0
      002330 08               [12] 7046 	inc	r0
      002331 86 F0            [24] 7047 	mov	b, @r0
      002333 08               [12] 7048 	inc	r0
      002334 E6               [12] 7049 	mov	a, @r0
      002335 12 37 2B         [24] 7050 	lcall	___fsdiv
      002338 AC 82            [24] 7051 	mov	r4, dpl
      00233A AD 83            [24] 7052 	mov	r5, dph
      00233C AE F0            [24] 7053 	mov	r6, b
      00233E FF               [12] 7054 	mov	r7, a
      00233F E5 81            [12] 7055 	mov	a,sp
      002341 24 FC            [12] 7056 	add	a,#0xfc
      002343 F5 81            [12] 7057 	mov	sp,a
      002345 8C 82            [24] 7058 	mov	dpl, r4
      002347 8D 83            [24] 7059 	mov	dph, r5
      002349 8E F0            [24] 7060 	mov	b, r6
      00234B EF               [12] 7061 	mov	a, r7
      00234C                       7062 00107$:
                           002295  7063 	C$fuzzy.h$2425$1_0$112 ==.
                                   7064 ;	../../fuzzy.h:2425: }
      00234C 85 08 81         [24] 7065 	mov	sp,_bp
      00234F D0 08            [24] 7066 	pop	_bp
                           00229A  7067 	C$fuzzy.h$2425$1_0$112 ==.
                           00229A  7068 	XG$fuzzy_rules_defuzzify_cog$0$0 ==.
      002351 22               [24] 7069 	ret
                                   7070 ;------------------------------------------------------------
                                   7071 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_boa'
                                   7072 ;------------------------------------------------------------
                                   7073 ;lower         Allocated to stack - _bp -6 +4 
                                   7074 ;upper         Allocated to stack - _bp -10 +4 
                                   7075 ;step          Allocated to stack - _bp -14 +4 
                                   7076 ;implication_method Allocated to stack - _bp -15 +1 
                                   7077 ;aggregation_method Allocated to stack - _bp -16 +1 
                                   7078 ;rules         Allocated to stack - _bp +1 +3 
                                   7079 ;total_area    Allocated to stack - _bp +8 +4 
                                   7080 ;half_area     Allocated to stack - _bp +12 +4 
                                   7081 ;accumulated_area Allocated to stack - _bp +16 +4 
                                   7082 ;value         Allocated to stack - _bp +20 +4 
                                   7083 ;sloc0         Allocated to stack - _bp +4 +4 
                                   7084 ;------------------------------------------------------------
                           00229B  7085 	G$fuzzy_rules_defuzzify_boa$0$0 ==.
                           00229B  7086 	C$fuzzy.h$2435$1_0$117 ==.
                                   7087 ;	../../fuzzy.h:2435: float fuzzy_rules_defuzzify_boa(
                                   7088 ;	-----------------------------------------
                                   7089 ;	 function fuzzy_rules_defuzzify_boa
                                   7090 ;	-----------------------------------------
      002352                       7091 _fuzzy_rules_defuzzify_boa:
      002352 C0 08            [24] 7092 	push	_bp
      002354 85 81 08         [24] 7093 	mov	_bp,sp
      002357 C0 82            [24] 7094 	push	dpl
      002359 C0 83            [24] 7095 	push	dph
      00235B C0 F0            [24] 7096 	push	b
      00235D E5 81            [12] 7097 	mov	a,sp
      00235F 24 14            [12] 7098 	add	a,#0x14
      002361 F5 81            [12] 7099 	mov	sp,a
                           0022AC  7100 	C$fuzzy.h$2450$1_0$117 ==.
                                   7101 ;	../../fuzzy.h:2450: 0.0f;
      002363 E5 08            [12] 7102 	mov	a,_bp
      002365 24 08            [12] 7103 	add	a,#0x08
      002367 F8               [12] 7104 	mov	r0,a
      002368 E4               [12] 7105 	clr	a
      002369 F6               [12] 7106 	mov	@r0,a
      00236A 08               [12] 7107 	inc	r0
      00236B F6               [12] 7108 	mov	@r0,a
      00236C 08               [12] 7109 	inc	r0
      00236D F6               [12] 7110 	mov	@r0,a
      00236E 08               [12] 7111 	inc	r0
      00236F F6               [12] 7112 	mov	@r0,a
                           0022B9  7113 	C$fuzzy.h$2453$2_0$118 ==.
                                   7114 ;	../../fuzzy.h:2453: value = lower;
      002370 E5 08            [12] 7115 	mov	a,_bp
      002372 24 FA            [12] 7116 	add	a,#0xfa
      002374 F8               [12] 7117 	mov	r0,a
      002375 E5 08            [12] 7118 	mov	a,_bp
      002377 24 04            [12] 7119 	add	a,#0x04
      002379 F9               [12] 7120 	mov	r1,a
      00237A E6               [12] 7121 	mov	a,@r0
      00237B F7               [12] 7122 	mov	@r1,a
      00237C 08               [12] 7123 	inc	r0
      00237D E6               [12] 7124 	mov	a,@r0
      00237E 09               [12] 7125 	inc	r1
      00237F F7               [12] 7126 	mov	@r1,a
      002380 08               [12] 7127 	inc	r0
      002381 E6               [12] 7128 	mov	a,@r0
      002382 09               [12] 7129 	inc	r1
      002383 F7               [12] 7130 	mov	@r1,a
      002384 08               [12] 7131 	inc	r0
      002385 E6               [12] 7132 	mov	a,@r0
      002386 09               [12] 7133 	inc	r1
      002387 F7               [12] 7134 	mov	@r1,a
      002388                       7135 00108$:
                           0022D1  7136 	C$fuzzy.h$2454$1_0$117 ==.
                                   7137 ;	../../fuzzy.h:2454: value <= upper;
      002388 E5 08            [12] 7138 	mov	a,_bp
      00238A 24 04            [12] 7139 	add	a,#0x04
      00238C F8               [12] 7140 	mov	r0,a
      00238D E6               [12] 7141 	mov	a,@r0
      00238E C0 E0            [24] 7142 	push	acc
      002390 08               [12] 7143 	inc	r0
      002391 E6               [12] 7144 	mov	a,@r0
      002392 C0 E0            [24] 7145 	push	acc
      002394 08               [12] 7146 	inc	r0
      002395 E6               [12] 7147 	mov	a,@r0
      002396 C0 E0            [24] 7148 	push	acc
      002398 08               [12] 7149 	inc	r0
      002399 E6               [12] 7150 	mov	a,@r0
      00239A C0 E0            [24] 7151 	push	acc
      00239C E5 08            [12] 7152 	mov	a,_bp
      00239E 24 F6            [12] 7153 	add	a,#0xf6
      0023A0 F8               [12] 7154 	mov	r0,a
      0023A1 86 82            [24] 7155 	mov	dpl, @r0
      0023A3 08               [12] 7156 	inc	r0
      0023A4 86 83            [24] 7157 	mov	dph, @r0
      0023A6 08               [12] 7158 	inc	r0
      0023A7 86 F0            [24] 7159 	mov	b, @r0
      0023A9 08               [12] 7160 	inc	r0
      0023AA E6               [12] 7161 	mov	a, @r0
      0023AB 12 35 C2         [24] 7162 	lcall	___fslt
      0023AE E5 81            [12] 7163 	mov	a,sp
      0023B0 24 FC            [12] 7164 	add	a,#0xfc
      0023B2 F5 81            [12] 7165 	mov	sp,a
      0023B4 E5 82            [12] 7166 	mov	a, dpl
      0023B6 24 FF            [12] 7167 	add	a,#0xff
      0023B8 92 00            [24] 7168 	mov	b0,c
      0023BA 50 03            [24] 7169 	jnc	00157$
      0023BC 02 24 6D         [24] 7170 	ljmp	00101$
      0023BF                       7171 00157$:
                           002308  7172 	C$fuzzy.h$2459$3_0$119 ==.
                                   7173 ;	../../fuzzy.h:2459: rules,
      0023BF E5 08            [12] 7174 	mov	a,_bp
      0023C1 24 F0            [12] 7175 	add	a,#0xf0
      0023C3 F8               [12] 7176 	mov	r0,a
      0023C4 E6               [12] 7177 	mov	a,@r0
      0023C5 C0 E0            [24] 7178 	push	acc
      0023C7 E5 08            [12] 7179 	mov	a,_bp
      0023C9 24 F1            [12] 7180 	add	a,#0xf1
      0023CB F8               [12] 7181 	mov	r0,a
      0023CC E6               [12] 7182 	mov	a,@r0
      0023CD C0 E0            [24] 7183 	push	acc
      0023CF E5 08            [12] 7184 	mov	a,_bp
      0023D1 24 04            [12] 7185 	add	a,#0x04
      0023D3 F8               [12] 7186 	mov	r0,a
      0023D4 E6               [12] 7187 	mov	a,@r0
      0023D5 C0 E0            [24] 7188 	push	acc
      0023D7 08               [12] 7189 	inc	r0
      0023D8 E6               [12] 7190 	mov	a,@r0
      0023D9 C0 E0            [24] 7191 	push	acc
      0023DB 08               [12] 7192 	inc	r0
      0023DC E6               [12] 7193 	mov	a,@r0
      0023DD C0 E0            [24] 7194 	push	acc
      0023DF 08               [12] 7195 	inc	r0
      0023E0 E6               [12] 7196 	mov	a,@r0
      0023E1 C0 E0            [24] 7197 	push	acc
      0023E3 A8 08            [24] 7198 	mov	r0,_bp
      0023E5 08               [12] 7199 	inc	r0
      0023E6 86 82            [24] 7200 	mov	dpl, @r0
      0023E8 08               [12] 7201 	inc	r0
      0023E9 86 83            [24] 7202 	mov	dph, @r0
      0023EB 08               [12] 7203 	inc	r0
      0023EC 86 F0            [24] 7204 	mov	b, @r0
      0023EE 12 1B 98         [24] 7205 	lcall	_fuzzy_rules_aggregated_height
      0023F1 AC 82            [24] 7206 	mov	r4, dpl
      0023F3 AD 83            [24] 7207 	mov	r5, dph
      0023F5 AE F0            [24] 7208 	mov	r6, b
      0023F7 FF               [12] 7209 	mov	r7, a
      0023F8 E5 81            [12] 7210 	mov	a,sp
      0023FA 24 FA            [12] 7211 	add	a,#0xfa
      0023FC F5 81            [12] 7212 	mov	sp,a
      0023FE C0 04            [24] 7213 	push	ar4
      002400 C0 05            [24] 7214 	push	ar5
      002402 C0 06            [24] 7215 	push	ar6
      002404 C0 07            [24] 7216 	push	ar7
                           00234F  7217 	C$fuzzy.h$2456$1_0$117 ==.
                                   7218 ;	../../fuzzy.h:2456: ) {
      002406 E5 08            [12] 7219 	mov	a,_bp
      002408 24 08            [12] 7220 	add	a,#0x08
      00240A F8               [12] 7221 	mov	r0,a
      00240B 86 82            [24] 7222 	mov	dpl, @r0
      00240D 08               [12] 7223 	inc	r0
      00240E 86 83            [24] 7224 	mov	dph, @r0
      002410 08               [12] 7225 	inc	r0
      002411 86 F0            [24] 7226 	mov	b, @r0
      002413 08               [12] 7227 	inc	r0
      002414 E6               [12] 7228 	mov	a, @r0
      002415 12 36 14         [24] 7229 	lcall	___fsadd
      002418 C8               [12] 7230 	xch	a,r0
      002419 E5 08            [12] 7231 	mov	a,_bp
      00241B 24 08            [12] 7232 	add	a,#0x08
      00241D C8               [12] 7233 	xch	a,r0
      00241E A6 82            [24] 7234 	mov	@r0, dpl
      002420 08               [12] 7235 	inc	r0
      002421 A6 83            [24] 7236 	mov	@r0, dph
      002423 08               [12] 7237 	inc	r0
      002424 A6 F0            [24] 7238 	mov	@r0, b
      002426 08               [12] 7239 	inc	r0
      002427 F6               [12] 7240 	mov	@r0,a
      002428 E5 81            [12] 7241 	mov	a,sp
      00242A 24 FC            [12] 7242 	add	a,#0xfc
      00242C F5 81            [12] 7243 	mov	sp,a
      00242E E5 08            [12] 7244 	mov	a,_bp
      002430 24 F2            [12] 7245 	add	a,#0xf2
      002432 F8               [12] 7246 	mov	r0,a
      002433 E6               [12] 7247 	mov	a,@r0
      002434 C0 E0            [24] 7248 	push	acc
      002436 08               [12] 7249 	inc	r0
      002437 E6               [12] 7250 	mov	a,@r0
      002438 C0 E0            [24] 7251 	push	acc
      00243A 08               [12] 7252 	inc	r0
      00243B E6               [12] 7253 	mov	a,@r0
      00243C C0 E0            [24] 7254 	push	acc
      00243E 08               [12] 7255 	inc	r0
      00243F E6               [12] 7256 	mov	a,@r0
      002440 C0 E0            [24] 7257 	push	acc
      002442 E5 08            [12] 7258 	mov	a,_bp
      002444 24 04            [12] 7259 	add	a,#0x04
      002446 F8               [12] 7260 	mov	r0,a
      002447 86 82            [24] 7261 	mov	dpl, @r0
      002449 08               [12] 7262 	inc	r0
      00244A 86 83            [24] 7263 	mov	dph, @r0
      00244C 08               [12] 7264 	inc	r0
      00244D 86 F0            [24] 7265 	mov	b, @r0
      00244F 08               [12] 7266 	inc	r0
      002450 E6               [12] 7267 	mov	a, @r0
      002451 12 36 14         [24] 7268 	lcall	___fsadd
      002454 C8               [12] 7269 	xch	a,r0
      002455 E5 08            [12] 7270 	mov	a,_bp
      002457 24 04            [12] 7271 	add	a,#0x04
      002459 C8               [12] 7272 	xch	a,r0
      00245A A6 82            [24] 7273 	mov	@r0, dpl
      00245C 08               [12] 7274 	inc	r0
      00245D A6 83            [24] 7275 	mov	@r0, dph
      00245F 08               [12] 7276 	inc	r0
      002460 A6 F0            [24] 7277 	mov	@r0, b
      002462 08               [12] 7278 	inc	r0
      002463 F6               [12] 7279 	mov	@r0,a
      002464 E5 81            [12] 7280 	mov	a,sp
      002466 24 FC            [12] 7281 	add	a,#0xfc
      002468 F5 81            [12] 7282 	mov	sp,a
      00246A 02 23 88         [24] 7283 	ljmp	00108$
      00246D                       7284 00101$:
                           0023B6  7285 	C$fuzzy.h$2466$1_0$117 ==.
                                   7286 ;	../../fuzzy.h:2466: if (total_area <= LEVEL_LO) {
      00246D E5 08            [12] 7287 	mov	a,_bp
      00246F 24 08            [12] 7288 	add	a,#0x08
      002471 F8               [12] 7289 	mov	r0,a
      002472 E6               [12] 7290 	mov	a,@r0
      002473 C0 E0            [24] 7291 	push	acc
      002475 08               [12] 7292 	inc	r0
      002476 E6               [12] 7293 	mov	a,@r0
      002477 C0 E0            [24] 7294 	push	acc
      002479 08               [12] 7295 	inc	r0
      00247A E6               [12] 7296 	mov	a,@r0
      00247B C0 E0            [24] 7297 	push	acc
      00247D 08               [12] 7298 	inc	r0
      00247E E6               [12] 7299 	mov	a,@r0
      00247F C0 E0            [24] 7300 	push	acc
      002481 90 00 00         [24] 7301 	mov	dptr,#0x0000
      002484 E4               [12] 7302 	clr	a
      002485 F5 F0            [12] 7303 	mov	b,a
      002487 12 35 C2         [24] 7304 	lcall	___fslt
      00248A E5 81            [12] 7305 	mov	a,sp
      00248C 24 FC            [12] 7306 	add	a,#0xfc
      00248E F5 81            [12] 7307 	mov	sp,a
      002490 E5 82            [12] 7308 	mov	a, dpl
      002492 24 FF            [12] 7309 	add	a,#0xff
      002494 92 00            [24] 7310 	mov	b0,c
      002496 40 09            [24] 7311 	jc	00103$
                           0023E1  7312 	C$fuzzy.h$2467$2_0$120 ==.
                                   7313 ;	../../fuzzy.h:2467: return 0.0f;
      002498 90 00 00         [24] 7314 	mov	dptr,#0x0000
      00249B E4               [12] 7315 	clr	a
      00249C F5 F0            [12] 7316 	mov	b,a
      00249E 02 26 32         [24] 7317 	ljmp	00113$
      0024A1                       7318 00103$:
                           0023EA  7319 	C$fuzzy.h$2472$1_0$117 ==.
                                   7320 ;	../../fuzzy.h:2472: 2.0f;
      0024A1 E4               [12] 7321 	clr	a
      0024A2 C0 E0            [24] 7322 	push	acc
      0024A4 C0 E0            [24] 7323 	push	acc
      0024A6 C0 E0            [24] 7324 	push	acc
      0024A8 74 40            [12] 7325 	mov	a,#0x40
      0024AA C0 E0            [24] 7326 	push	acc
                           0023F5  7327 	C$fuzzy.h$2475$1_0$117 ==.
                                   7328 ;	../../fuzzy.h:2475: 0.0f;
      0024AC E5 08            [12] 7329 	mov	a,_bp
      0024AE 24 08            [12] 7330 	add	a,#0x08
      0024B0 F8               [12] 7331 	mov	r0,a
      0024B1 86 82            [24] 7332 	mov	dpl, @r0
      0024B3 08               [12] 7333 	inc	r0
      0024B4 86 83            [24] 7334 	mov	dph, @r0
      0024B6 08               [12] 7335 	inc	r0
      0024B7 86 F0            [24] 7336 	mov	b, @r0
      0024B9 08               [12] 7337 	inc	r0
      0024BA E6               [12] 7338 	mov	a, @r0
      0024BB 12 37 2B         [24] 7339 	lcall	___fsdiv
      0024BE C8               [12] 7340 	xch	a,r0
      0024BF E5 08            [12] 7341 	mov	a,_bp
      0024C1 24 0C            [12] 7342 	add	a,#0x0c
      0024C3 C8               [12] 7343 	xch	a,r0
      0024C4 A6 82            [24] 7344 	mov	@r0, dpl
      0024C6 08               [12] 7345 	inc	r0
      0024C7 A6 83            [24] 7346 	mov	@r0, dph
      0024C9 08               [12] 7347 	inc	r0
      0024CA A6 F0            [24] 7348 	mov	@r0, b
      0024CC 08               [12] 7349 	inc	r0
      0024CD F6               [12] 7350 	mov	@r0,a
      0024CE E5 81            [12] 7351 	mov	a,sp
      0024D0 24 FC            [12] 7352 	add	a,#0xfc
      0024D2 F5 81            [12] 7353 	mov	sp,a
      0024D4 E5 08            [12] 7354 	mov	a,_bp
      0024D6 24 10            [12] 7355 	add	a,#0x10
      0024D8 F8               [12] 7356 	mov	r0,a
      0024D9 E4               [12] 7357 	clr	a
      0024DA F6               [12] 7358 	mov	@r0,a
      0024DB 08               [12] 7359 	inc	r0
      0024DC F6               [12] 7360 	mov	@r0,a
      0024DD 08               [12] 7361 	inc	r0
      0024DE F6               [12] 7362 	mov	@r0,a
      0024DF 08               [12] 7363 	inc	r0
      0024E0 F6               [12] 7364 	mov	@r0,a
                           00242A  7365 	C$fuzzy.h$2478$2_0$121 ==.
                                   7366 ;	../../fuzzy.h:2478: value = lower;
      0024E1 E5 08            [12] 7367 	mov	a,_bp
      0024E3 24 FA            [12] 7368 	add	a,#0xfa
      0024E5 F8               [12] 7369 	mov	r0,a
      0024E6 E5 08            [12] 7370 	mov	a,_bp
      0024E8 24 14            [12] 7371 	add	a,#0x14
      0024EA F9               [12] 7372 	mov	r1,a
      0024EB E6               [12] 7373 	mov	a,@r0
      0024EC F7               [12] 7374 	mov	@r1,a
      0024ED 08               [12] 7375 	inc	r0
      0024EE E6               [12] 7376 	mov	a,@r0
      0024EF 09               [12] 7377 	inc	r1
      0024F0 F7               [12] 7378 	mov	@r1,a
      0024F1 08               [12] 7379 	inc	r0
      0024F2 E6               [12] 7380 	mov	a,@r0
      0024F3 09               [12] 7381 	inc	r1
      0024F4 F7               [12] 7382 	mov	@r1,a
      0024F5 08               [12] 7383 	inc	r0
      0024F6 E6               [12] 7384 	mov	a,@r0
      0024F7 09               [12] 7385 	inc	r1
      0024F8 F7               [12] 7386 	mov	@r1,a
      0024F9                       7387 00111$:
                           002442  7388 	C$fuzzy.h$2479$1_0$117 ==.
                                   7389 ;	../../fuzzy.h:2479: value <= upper;
      0024F9 E5 08            [12] 7390 	mov	a,_bp
      0024FB 24 14            [12] 7391 	add	a,#0x14
      0024FD F8               [12] 7392 	mov	r0,a
      0024FE E6               [12] 7393 	mov	a,@r0
      0024FF C0 E0            [24] 7394 	push	acc
      002501 08               [12] 7395 	inc	r0
      002502 E6               [12] 7396 	mov	a,@r0
      002503 C0 E0            [24] 7397 	push	acc
      002505 08               [12] 7398 	inc	r0
      002506 E6               [12] 7399 	mov	a,@r0
      002507 C0 E0            [24] 7400 	push	acc
      002509 08               [12] 7401 	inc	r0
      00250A E6               [12] 7402 	mov	a,@r0
      00250B C0 E0            [24] 7403 	push	acc
      00250D E5 08            [12] 7404 	mov	a,_bp
      00250F 24 F6            [12] 7405 	add	a,#0xf6
      002511 F8               [12] 7406 	mov	r0,a
      002512 86 82            [24] 7407 	mov	dpl, @r0
      002514 08               [12] 7408 	inc	r0
      002515 86 83            [24] 7409 	mov	dph, @r0
      002517 08               [12] 7410 	inc	r0
      002518 86 F0            [24] 7411 	mov	b, @r0
      00251A 08               [12] 7412 	inc	r0
      00251B E6               [12] 7413 	mov	a, @r0
      00251C 12 35 C2         [24] 7414 	lcall	___fslt
      00251F E5 81            [12] 7415 	mov	a,sp
      002521 24 FC            [12] 7416 	add	a,#0xfc
      002523 F5 81            [12] 7417 	mov	sp,a
      002525 E5 82            [12] 7418 	mov	a, dpl
      002527 24 FF            [12] 7419 	add	a,#0xff
      002529 92 00            [24] 7420 	mov	b0,c
      00252B 50 03            [24] 7421 	jnc	00159$
      00252D 02 26 23         [24] 7422 	ljmp	00106$
      002530                       7423 00159$:
                           002479  7424 	C$fuzzy.h$2484$3_0$122 ==.
                                   7425 ;	../../fuzzy.h:2484: rules,
      002530 E5 08            [12] 7426 	mov	a,_bp
      002532 24 F0            [12] 7427 	add	a,#0xf0
      002534 F8               [12] 7428 	mov	r0,a
      002535 E6               [12] 7429 	mov	a,@r0
      002536 C0 E0            [24] 7430 	push	acc
      002538 E5 08            [12] 7431 	mov	a,_bp
      00253A 24 F1            [12] 7432 	add	a,#0xf1
      00253C F8               [12] 7433 	mov	r0,a
      00253D E6               [12] 7434 	mov	a,@r0
      00253E C0 E0            [24] 7435 	push	acc
      002540 E5 08            [12] 7436 	mov	a,_bp
      002542 24 14            [12] 7437 	add	a,#0x14
      002544 F8               [12] 7438 	mov	r0,a
      002545 E6               [12] 7439 	mov	a,@r0
      002546 C0 E0            [24] 7440 	push	acc
      002548 08               [12] 7441 	inc	r0
      002549 E6               [12] 7442 	mov	a,@r0
      00254A C0 E0            [24] 7443 	push	acc
      00254C 08               [12] 7444 	inc	r0
      00254D E6               [12] 7445 	mov	a,@r0
      00254E C0 E0            [24] 7446 	push	acc
      002550 08               [12] 7447 	inc	r0
      002551 E6               [12] 7448 	mov	a,@r0
      002552 C0 E0            [24] 7449 	push	acc
      002554 A8 08            [24] 7450 	mov	r0,_bp
      002556 08               [12] 7451 	inc	r0
      002557 86 82            [24] 7452 	mov	dpl, @r0
      002559 08               [12] 7453 	inc	r0
      00255A 86 83            [24] 7454 	mov	dph, @r0
      00255C 08               [12] 7455 	inc	r0
      00255D 86 F0            [24] 7456 	mov	b, @r0
      00255F 12 1B 98         [24] 7457 	lcall	_fuzzy_rules_aggregated_height
      002562 AA 82            [24] 7458 	mov	r2, dpl
      002564 AB 83            [24] 7459 	mov	r3, dph
      002566 AE F0            [24] 7460 	mov	r6, b
      002568 FF               [12] 7461 	mov	r7, a
      002569 E5 81            [12] 7462 	mov	a,sp
      00256B 24 FA            [12] 7463 	add	a,#0xfa
      00256D F5 81            [12] 7464 	mov	sp,a
      00256F C0 02            [24] 7465 	push	ar2
      002571 C0 03            [24] 7466 	push	ar3
      002573 C0 06            [24] 7467 	push	ar6
      002575 C0 07            [24] 7468 	push	ar7
                           0024C0  7469 	C$fuzzy.h$2493$1_0$117 ==.
                                   7470 ;	../../fuzzy.h:2493: ) {
      002577 E5 08            [12] 7471 	mov	a,_bp
      002579 24 10            [12] 7472 	add	a,#0x10
      00257B F8               [12] 7473 	mov	r0,a
      00257C 86 82            [24] 7474 	mov	dpl, @r0
      00257E 08               [12] 7475 	inc	r0
      00257F 86 83            [24] 7476 	mov	dph, @r0
      002581 08               [12] 7477 	inc	r0
      002582 86 F0            [24] 7478 	mov	b, @r0
      002584 08               [12] 7479 	inc	r0
      002585 E6               [12] 7480 	mov	a, @r0
      002586 12 36 14         [24] 7481 	lcall	___fsadd
      002589 C8               [12] 7482 	xch	a,r0
      00258A E5 08            [12] 7483 	mov	a,_bp
      00258C 24 10            [12] 7484 	add	a,#0x10
      00258E C8               [12] 7485 	xch	a,r0
      00258F A6 82            [24] 7486 	mov	@r0, dpl
      002591 08               [12] 7487 	inc	r0
      002592 A6 83            [24] 7488 	mov	@r0, dph
      002594 08               [12] 7489 	inc	r0
      002595 A6 F0            [24] 7490 	mov	@r0, b
      002597 08               [12] 7491 	inc	r0
      002598 F6               [12] 7492 	mov	@r0,a
      002599 E5 81            [12] 7493 	mov	a,sp
      00259B 24 FC            [12] 7494 	add	a,#0xfc
      00259D F5 81            [12] 7495 	mov	sp,a
      00259F E5 08            [12] 7496 	mov	a,_bp
      0025A1 24 0C            [12] 7497 	add	a,#0x0c
      0025A3 F8               [12] 7498 	mov	r0,a
      0025A4 E6               [12] 7499 	mov	a,@r0
      0025A5 C0 E0            [24] 7500 	push	acc
      0025A7 08               [12] 7501 	inc	r0
      0025A8 E6               [12] 7502 	mov	a,@r0
      0025A9 C0 E0            [24] 7503 	push	acc
      0025AB 08               [12] 7504 	inc	r0
      0025AC E6               [12] 7505 	mov	a,@r0
      0025AD C0 E0            [24] 7506 	push	acc
      0025AF 08               [12] 7507 	inc	r0
      0025B0 E6               [12] 7508 	mov	a,@r0
      0025B1 C0 E0            [24] 7509 	push	acc
      0025B3 E5 08            [12] 7510 	mov	a,_bp
      0025B5 24 10            [12] 7511 	add	a,#0x10
      0025B7 F8               [12] 7512 	mov	r0,a
      0025B8 86 82            [24] 7513 	mov	dpl, @r0
      0025BA 08               [12] 7514 	inc	r0
      0025BB 86 83            [24] 7515 	mov	dph, @r0
      0025BD 08               [12] 7516 	inc	r0
      0025BE 86 F0            [24] 7517 	mov	b, @r0
      0025C0 08               [12] 7518 	inc	r0
      0025C1 E6               [12] 7519 	mov	a, @r0
      0025C2 12 35 C2         [24] 7520 	lcall	___fslt
      0025C5 E5 81            [12] 7521 	mov	a,sp
      0025C7 24 FC            [12] 7522 	add	a,#0xfc
      0025C9 F5 81            [12] 7523 	mov	sp,a
      0025CB E5 82            [12] 7524 	mov	a, dpl
      0025CD 24 FF            [12] 7525 	add	a,#0xff
      0025CF 92 00            [24] 7526 	mov	b0,c
      0025D1 40 11            [24] 7527 	jc	00112$
                           00251C  7528 	C$fuzzy.h$2494$4_0$123 ==.
                                   7529 ;	../../fuzzy.h:2494: return value;
      0025D3 E5 08            [12] 7530 	mov	a,_bp
      0025D5 24 14            [12] 7531 	add	a,#0x14
      0025D7 F8               [12] 7532 	mov	r0,a
      0025D8 86 82            [24] 7533 	mov	dpl, @r0
      0025DA 08               [12] 7534 	inc	r0
      0025DB 86 83            [24] 7535 	mov	dph, @r0
      0025DD 08               [12] 7536 	inc	r0
      0025DE 86 F0            [24] 7537 	mov	b, @r0
      0025E0 08               [12] 7538 	inc	r0
      0025E1 E6               [12] 7539 	mov	a, @r0
      0025E2 80 4E            [24] 7540 	sjmp	00113$
      0025E4                       7541 00112$:
                           00252D  7542 	C$fuzzy.h$2481$1_0$117 ==.
                                   7543 ;	../../fuzzy.h:2481: ) {
      0025E4 E5 08            [12] 7544 	mov	a,_bp
      0025E6 24 F2            [12] 7545 	add	a,#0xf2
      0025E8 F8               [12] 7546 	mov	r0,a
      0025E9 E6               [12] 7547 	mov	a,@r0
      0025EA C0 E0            [24] 7548 	push	acc
      0025EC 08               [12] 7549 	inc	r0
      0025ED E6               [12] 7550 	mov	a,@r0
      0025EE C0 E0            [24] 7551 	push	acc
      0025F0 08               [12] 7552 	inc	r0
      0025F1 E6               [12] 7553 	mov	a,@r0
      0025F2 C0 E0            [24] 7554 	push	acc
      0025F4 08               [12] 7555 	inc	r0
      0025F5 E6               [12] 7556 	mov	a,@r0
      0025F6 C0 E0            [24] 7557 	push	acc
      0025F8 E5 08            [12] 7558 	mov	a,_bp
      0025FA 24 14            [12] 7559 	add	a,#0x14
      0025FC F8               [12] 7560 	mov	r0,a
      0025FD 86 82            [24] 7561 	mov	dpl, @r0
      0025FF 08               [12] 7562 	inc	r0
      002600 86 83            [24] 7563 	mov	dph, @r0
      002602 08               [12] 7564 	inc	r0
      002603 86 F0            [24] 7565 	mov	b, @r0
      002605 08               [12] 7566 	inc	r0
      002606 E6               [12] 7567 	mov	a, @r0
      002607 12 36 14         [24] 7568 	lcall	___fsadd
      00260A C8               [12] 7569 	xch	a,r0
      00260B E5 08            [12] 7570 	mov	a,_bp
      00260D 24 14            [12] 7571 	add	a,#0x14
      00260F C8               [12] 7572 	xch	a,r0
      002610 A6 82            [24] 7573 	mov	@r0, dpl
      002612 08               [12] 7574 	inc	r0
      002613 A6 83            [24] 7575 	mov	@r0, dph
      002615 08               [12] 7576 	inc	r0
      002616 A6 F0            [24] 7577 	mov	@r0, b
      002618 08               [12] 7578 	inc	r0
      002619 F6               [12] 7579 	mov	@r0,a
      00261A E5 81            [12] 7580 	mov	a,sp
      00261C 24 FC            [12] 7581 	add	a,#0xfc
      00261E F5 81            [12] 7582 	mov	sp,a
      002620 02 24 F9         [24] 7583 	ljmp	00111$
      002623                       7584 00106$:
                           00256C  7585 	C$fuzzy.h$2498$1_0$117 ==.
                                   7586 ;	../../fuzzy.h:2498: return upper;
      002623 E5 08            [12] 7587 	mov	a,_bp
      002625 24 F6            [12] 7588 	add	a,#0xf6
      002627 F8               [12] 7589 	mov	r0,a
      002628 86 82            [24] 7590 	mov	dpl, @r0
      00262A 08               [12] 7591 	inc	r0
      00262B 86 83            [24] 7592 	mov	dph, @r0
      00262D 08               [12] 7593 	inc	r0
      00262E 86 F0            [24] 7594 	mov	b, @r0
      002630 08               [12] 7595 	inc	r0
      002631 E6               [12] 7596 	mov	a, @r0
      002632                       7597 00113$:
                           00257B  7598 	C$fuzzy.h$2499$1_0$117 ==.
                                   7599 ;	../../fuzzy.h:2499: }
      002632 85 08 81         [24] 7600 	mov	sp,_bp
      002635 D0 08            [24] 7601 	pop	_bp
                           002580  7602 	C$fuzzy.h$2499$1_0$117 ==.
                           002580  7603 	XG$fuzzy_rules_defuzzify_boa$0$0 ==.
      002637 22               [24] 7604 	ret
                                   7605 ;------------------------------------------------------------
                                   7606 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_cos'
                                   7607 ;------------------------------------------------------------
                                   7608 ;lower         Allocated to stack - _bp -6 +4 
                                   7609 ;upper         Allocated to stack - _bp -10 +4 
                                   7610 ;step          Allocated to stack - _bp -14 +4 
                                   7611 ;implication_method Allocated to stack - _bp -15 +1 
                                   7612 ;rules         Allocated to stack - _bp +1 +3 
                                   7613 ;weighted_sum  Allocated to stack - _bp +9 +4 
                                   7614 ;height_sum    Allocated to stack - _bp +13 +4 
                                   7615 ;value         Allocated to stack - _bp +17 +4 
                                   7616 ;output_membership Allocated to stack - _bp +21 +4 
                                   7617 ;implied_height Allocated to stack - _bp +25 +4 
                                   7618 ;index         Allocated to stack - _bp +29 +2 
                                   7619 ;sloc0         Allocated to stack - _bp +4 +3 
                                   7620 ;sloc1         Allocated to stack - _bp +7 +2 
                                   7621 ;------------------------------------------------------------
                           002581  7622 	G$fuzzy_rules_defuzzify_cos$0$0 ==.
                           002581  7623 	C$fuzzy.h$2511$1_0$125 ==.
                                   7624 ;	../../fuzzy.h:2511: float fuzzy_rules_defuzzify_cos(
                                   7625 ;	-----------------------------------------
                                   7626 ;	 function fuzzy_rules_defuzzify_cos
                                   7627 ;	-----------------------------------------
      002638                       7628 _fuzzy_rules_defuzzify_cos:
      002638 C0 08            [24] 7629 	push	_bp
      00263A 85 81 08         [24] 7630 	mov	_bp,sp
      00263D C0 82            [24] 7631 	push	dpl
      00263F C0 83            [24] 7632 	push	dph
      002641 C0 F0            [24] 7633 	push	b
      002643 E5 81            [12] 7634 	mov	a,sp
      002645 24 1B            [12] 7635 	add	a,#0x1b
      002647 F5 81            [12] 7636 	mov	sp,a
                           002592  7637 	C$fuzzy.h$2527$1_0$125 ==.
                                   7638 ;	../../fuzzy.h:2527: 0.0f;
      002649 E5 08            [12] 7639 	mov	a,_bp
      00264B 24 09            [12] 7640 	add	a,#0x09
      00264D F8               [12] 7641 	mov	r0,a
      00264E E4               [12] 7642 	clr	a
      00264F F6               [12] 7643 	mov	@r0,a
      002650 08               [12] 7644 	inc	r0
      002651 F6               [12] 7645 	mov	@r0,a
      002652 08               [12] 7646 	inc	r0
      002653 F6               [12] 7647 	mov	@r0,a
      002654 08               [12] 7648 	inc	r0
      002655 F6               [12] 7649 	mov	@r0,a
                           00259F  7650 	C$fuzzy.h$2530$1_0$125 ==.
                                   7651 ;	../../fuzzy.h:2530: 0.0f;
      002656 E5 08            [12] 7652 	mov	a,_bp
      002658 24 0D            [12] 7653 	add	a,#0x0d
      00265A F8               [12] 7654 	mov	r0,a
      00265B E4               [12] 7655 	clr	a
      00265C F6               [12] 7656 	mov	@r0,a
      00265D 08               [12] 7657 	inc	r0
      00265E F6               [12] 7658 	mov	@r0,a
      00265F 08               [12] 7659 	inc	r0
      002660 F6               [12] 7660 	mov	@r0,a
      002661 08               [12] 7661 	inc	r0
      002662 F6               [12] 7662 	mov	@r0,a
                           0025AC  7663 	C$fuzzy.h$2533$2_0$126 ==.
                                   7664 ;	../../fuzzy.h:2533: value = lower;
      002663 E5 08            [12] 7665 	mov	a,_bp
      002665 24 FA            [12] 7666 	add	a,#0xfa
      002667 F8               [12] 7667 	mov	r0,a
      002668 E5 08            [12] 7668 	mov	a,_bp
      00266A 24 11            [12] 7669 	add	a,#0x11
      00266C F9               [12] 7670 	mov	r1,a
      00266D E6               [12] 7671 	mov	a,@r0
      00266E F7               [12] 7672 	mov	@r1,a
      00266F 08               [12] 7673 	inc	r0
      002670 E6               [12] 7674 	mov	a,@r0
      002671 09               [12] 7675 	inc	r1
      002672 F7               [12] 7676 	mov	@r1,a
      002673 08               [12] 7677 	inc	r0
      002674 E6               [12] 7678 	mov	a,@r0
      002675 09               [12] 7679 	inc	r1
      002676 F7               [12] 7680 	mov	@r1,a
      002677 08               [12] 7681 	inc	r0
      002678 E6               [12] 7682 	mov	a,@r0
      002679 09               [12] 7683 	inc	r1
      00267A F7               [12] 7684 	mov	@r1,a
      00267B A8 08            [24] 7685 	mov	r0,_bp
      00267D 08               [12] 7686 	inc	r0
      00267E E5 08            [12] 7687 	mov	a,_bp
      002680 24 04            [12] 7688 	add	a,#0x04
      002682 F9               [12] 7689 	mov	r1,a
      002683 E6               [12] 7690 	mov	a,@r0
      002684 F7               [12] 7691 	mov	@r1,a
      002685 08               [12] 7692 	inc	r0
      002686 E6               [12] 7693 	mov	a,@r0
      002687 09               [12] 7694 	inc	r1
      002688 F7               [12] 7695 	mov	@r1,a
      002689 08               [12] 7696 	inc	r0
      00268A E6               [12] 7697 	mov	a,@r0
      00268B 09               [12] 7698 	inc	r1
      00268C F7               [12] 7699 	mov	@r1,a
      00268D A8 08            [24] 7700 	mov	r0,_bp
      00268F 08               [12] 7701 	inc	r0
      002690 74 90            [12] 7702 	mov	a,#0x90
      002692 26               [12] 7703 	add	a, @r0
      002693 FC               [12] 7704 	mov	r4,a
      002694 E4               [12] 7705 	clr	a
      002695 08               [12] 7706 	inc	r0
      002696 36               [12] 7707 	addc	a, @r0
      002697 FD               [12] 7708 	mov	r5,a
      002698 08               [12] 7709 	inc	r0
      002699 86 06            [24] 7710 	mov	ar6,@r0
      00269B                       7711 00109$:
                           0025E4  7712 	C$fuzzy.h$2534$1_0$125 ==.
                                   7713 ;	../../fuzzy.h:2534: value <= upper;
      00269B C0 06            [24] 7714 	push	ar6
      00269D C0 05            [24] 7715 	push	ar5
      00269F C0 04            [24] 7716 	push	ar4
      0026A1 E5 08            [12] 7717 	mov	a,_bp
      0026A3 24 11            [12] 7718 	add	a,#0x11
      0026A5 F8               [12] 7719 	mov	r0,a
      0026A6 E6               [12] 7720 	mov	a,@r0
      0026A7 C0 E0            [24] 7721 	push	acc
      0026A9 08               [12] 7722 	inc	r0
      0026AA E6               [12] 7723 	mov	a,@r0
      0026AB C0 E0            [24] 7724 	push	acc
      0026AD 08               [12] 7725 	inc	r0
      0026AE E6               [12] 7726 	mov	a,@r0
      0026AF C0 E0            [24] 7727 	push	acc
      0026B1 08               [12] 7728 	inc	r0
      0026B2 E6               [12] 7729 	mov	a,@r0
      0026B3 C0 E0            [24] 7730 	push	acc
      0026B5 E5 08            [12] 7731 	mov	a,_bp
      0026B7 24 F6            [12] 7732 	add	a,#0xf6
      0026B9 F8               [12] 7733 	mov	r0,a
      0026BA 86 82            [24] 7734 	mov	dpl, @r0
      0026BC 08               [12] 7735 	inc	r0
      0026BD 86 83            [24] 7736 	mov	dph, @r0
      0026BF 08               [12] 7737 	inc	r0
      0026C0 86 F0            [24] 7738 	mov	b, @r0
      0026C2 08               [12] 7739 	inc	r0
      0026C3 E6               [12] 7740 	mov	a, @r0
      0026C4 12 35 C2         [24] 7741 	lcall	___fslt
      0026C7 E5 81            [12] 7742 	mov	a,sp
      0026C9 24 FC            [12] 7743 	add	a,#0xfc
      0026CB F5 81            [12] 7744 	mov	sp,a
      0026CD D0 04            [24] 7745 	pop	ar4
      0026CF D0 05            [24] 7746 	pop	ar5
      0026D1 D0 06            [24] 7747 	pop	ar6
      0026D3 E5 82            [12] 7748 	mov	a, dpl
      0026D5 24 FF            [12] 7749 	add	a,#0xff
      0026D7 92 00            [24] 7750 	mov	b0,c
      0026D9 50 03            [24] 7751 	jnc	00144$
      0026DB 02 29 28         [24] 7752 	ljmp	00102$
      0026DE                       7753 00144$:
                           002627  7754 	C$fuzzy.h$2538$1_0$125 ==.
                                   7755 ;	../../fuzzy.h:2538: index = 0u;
      0026DE E5 08            [12] 7756 	mov	a,_bp
      0026E0 24 1D            [12] 7757 	add	a,#0x1d
      0026E2 F8               [12] 7758 	mov	r0,a
      0026E3 E4               [12] 7759 	clr	a
      0026E4 F6               [12] 7760 	mov	@r0,a
      0026E5 08               [12] 7761 	inc	r0
      0026E6 F6               [12] 7762 	mov	@r0,a
      0026E7 E5 08            [12] 7763 	mov	a,_bp
      0026E9 24 07            [12] 7764 	add	a,#0x07
      0026EB F8               [12] 7765 	mov	r0,a
      0026EC E4               [12] 7766 	clr	a
      0026ED F6               [12] 7767 	mov	@r0,a
      0026EE 08               [12] 7768 	inc	r0
      0026EF F6               [12] 7769 	mov	@r0,a
      0026F0                       7770 00106$:
                           002639  7771 	C$fuzzy.h$2539$4_0$128 ==.
                                   7772 ;	../../fuzzy.h:2539: index < rules->count;
      0026F0 8C 82            [24] 7773 	mov	dpl,r4
      0026F2 8D 83            [24] 7774 	mov	dph,r5
      0026F4 8E F0            [24] 7775 	mov	b,r6
      0026F6 12 37 EE         [24] 7776 	lcall	__gptrget
      0026F9 FA               [12] 7777 	mov	r2,a
      0026FA A3               [24] 7778 	inc	dptr
      0026FB 12 37 EE         [24] 7779 	lcall	__gptrget
      0026FE FF               [12] 7780 	mov	r7,a
      0026FF E5 08            [12] 7781 	mov	a,_bp
      002701 24 1D            [12] 7782 	add	a,#0x1d
      002703 F8               [12] 7783 	mov	r0,a
      002704 C3               [12] 7784 	clr	c
      002705 E6               [12] 7785 	mov	a,@r0
      002706 9A               [12] 7786 	subb	a,r2
      002707 08               [12] 7787 	inc	r0
      002708 E6               [12] 7788 	mov	a,@r0
      002709 9F               [12] 7789 	subb	a,r7
      00270A 40 03            [24] 7790 	jc	00145$
      00270C 02 28 DD         [24] 7791 	ljmp	00110$
      00270F                       7792 00145$:
                           002658  7793 	C$fuzzy.h$2544$1_0$125 ==.
                                   7794 ;	../../fuzzy.h:2544: rules->rules[index]
      00270F C0 04            [24] 7795 	push	ar4
      002711 C0 05            [24] 7796 	push	ar5
      002713 C0 06            [24] 7797 	push	ar6
      002715 E5 08            [12] 7798 	mov	a,_bp
      002717 24 04            [12] 7799 	add	a,#0x04
      002719 F8               [12] 7800 	mov	r0,a
      00271A E5 08            [12] 7801 	mov	a,_bp
      00271C 24 07            [12] 7802 	add	a,#0x07
      00271E F9               [12] 7803 	mov	r1,a
      00271F E7               [12] 7804 	mov	a,@r1
      002720 26               [12] 7805 	add	a, @r0
      002721 FA               [12] 7806 	mov	r2,a
      002722 09               [12] 7807 	inc	r1
      002723 E7               [12] 7808 	mov	a,@r1
      002724 08               [12] 7809 	inc	r0
      002725 36               [12] 7810 	addc	a, @r0
      002726 FB               [12] 7811 	mov	r3,a
      002727 08               [12] 7812 	inc	r0
      002728 86 07            [24] 7813 	mov	ar7,@r0
      00272A 74 07            [12] 7814 	mov	a,#0x07
      00272C 2A               [12] 7815 	add	a, r2
      00272D FA               [12] 7816 	mov	r2,a
      00272E E4               [12] 7817 	clr	a
      00272F 3B               [12] 7818 	addc	a, r3
      002730 FB               [12] 7819 	mov	r3,a
      002731 8A 82            [24] 7820 	mov	dpl,r2
      002733 8B 83            [24] 7821 	mov	dph,r3
      002735 8F F0            [24] 7822 	mov	b,r7
      002737 12 37 EE         [24] 7823 	lcall	__gptrget
      00273A FA               [12] 7824 	mov	r2,a
      00273B A3               [24] 7825 	inc	dptr
      00273C 12 37 EE         [24] 7826 	lcall	__gptrget
      00273F FB               [12] 7827 	mov	r3,a
                           002689  7828 	C$fuzzy.h$2545$5_0$129 ==.
                                   7829 ;	../../fuzzy.h:2545: .output_function(value)
      002740 C0 05            [24] 7830 	push	ar5
      002742 C0 04            [24] 7831 	push	ar4
      002744 12 27 49         [24] 7832 	lcall	00146$
      002747 80 14            [24] 7833 	sjmp	00147$
      002749                       7834 00146$:
      002749 C0 02            [24] 7835 	push	ar2
      00274B C0 03            [24] 7836 	push	ar3
      00274D E5 08            [12] 7837 	mov	a,_bp
      00274F 24 11            [12] 7838 	add	a,#0x11
      002751 F8               [12] 7839 	mov	r0,a
      002752 86 82            [24] 7840 	mov	dpl, @r0
      002754 08               [12] 7841 	inc	r0
      002755 86 83            [24] 7842 	mov	dph, @r0
      002757 08               [12] 7843 	inc	r0
      002758 86 F0            [24] 7844 	mov	b, @r0
      00275A 08               [12] 7845 	inc	r0
      00275B E6               [12] 7846 	mov	a, @r0
      00275C 22               [24] 7847 	ret
      00275D                       7848 00147$:
      00275D AA 82            [24] 7849 	mov	r2, dpl
      00275F AB 83            [24] 7850 	mov	r3, dph
      002761 AE F0            [24] 7851 	mov	r6, b
      002763 FF               [12] 7852 	mov	r7, a
      002764 D0 04            [24] 7853 	pop	ar4
      002766 D0 05            [24] 7854 	pop	ar5
      002768 8A 82            [24] 7855 	mov	dpl, r2
      00276A 8B 83            [24] 7856 	mov	dph, r3
      00276C 8E F0            [24] 7857 	mov	b, r6
      00276E EF               [12] 7858 	mov	a, r7
      00276F C0 06            [24] 7859 	push	ar6
      002771 C0 05            [24] 7860 	push	ar5
      002773 C0 04            [24] 7861 	push	ar4
      002775 12 00 EA         [24] 7862 	lcall	_fuzzy_clamp
      002778 C8               [12] 7863 	xch	a,r0
      002779 E5 08            [12] 7864 	mov	a,_bp
      00277B 24 15            [12] 7865 	add	a,#0x15
      00277D C8               [12] 7866 	xch	a,r0
      00277E A6 82            [24] 7867 	mov	@r0, dpl
      002780 08               [12] 7868 	inc	r0
      002781 A6 83            [24] 7869 	mov	@r0, dph
      002783 08               [12] 7870 	inc	r0
      002784 A6 F0            [24] 7871 	mov	@r0, b
      002786 08               [12] 7872 	inc	r0
      002787 F6               [12] 7873 	mov	@r0,a
      002788 D0 04            [24] 7874 	pop	ar4
      00278A D0 05            [24] 7875 	pop	ar5
      00278C D0 06            [24] 7876 	pop	ar6
                           0026D7  7877 	C$fuzzy.h$2551$5_0$129 ==.
                                   7878 ;	../../fuzzy.h:2551: rules->rules[index].value,
      00278E A8 08            [24] 7879 	mov	r0,_bp
      002790 08               [12] 7880 	inc	r0
      002791 E5 08            [12] 7881 	mov	a,_bp
      002793 24 07            [12] 7882 	add	a,#0x07
      002795 F9               [12] 7883 	mov	r1,a
      002796 E7               [12] 7884 	mov	a,@r1
      002797 26               [12] 7885 	add	a, @r0
      002798 FA               [12] 7886 	mov	r2,a
      002799 09               [12] 7887 	inc	r1
      00279A E7               [12] 7888 	mov	a,@r1
      00279B 08               [12] 7889 	inc	r0
      00279C 36               [12] 7890 	addc	a, @r0
      00279D FB               [12] 7891 	mov	r3,a
      00279E 08               [12] 7892 	inc	r0
      00279F 86 07            [24] 7893 	mov	ar7,@r0
      0027A1 74 03            [12] 7894 	mov	a,#0x03
      0027A3 2A               [12] 7895 	add	a, r2
      0027A4 FA               [12] 7896 	mov	r2,a
      0027A5 E4               [12] 7897 	clr	a
      0027A6 3B               [12] 7898 	addc	a, r3
      0027A7 FB               [12] 7899 	mov	r3,a
      0027A8 8A 82            [24] 7900 	mov	dpl,r2
      0027AA 8B 83            [24] 7901 	mov	dph,r3
      0027AC 8F F0            [24] 7902 	mov	b,r7
      0027AE 12 37 EE         [24] 7903 	lcall	__gptrget
      0027B1 FA               [12] 7904 	mov	r2,a
      0027B2 A3               [24] 7905 	inc	dptr
      0027B3 12 37 EE         [24] 7906 	lcall	__gptrget
      0027B6 FB               [12] 7907 	mov	r3,a
      0027B7 A3               [24] 7908 	inc	dptr
      0027B8 12 37 EE         [24] 7909 	lcall	__gptrget
      0027BB FF               [12] 7910 	mov	r7,a
      0027BC A3               [24] 7911 	inc	dptr
      0027BD 12 37 EE         [24] 7912 	lcall	__gptrget
      0027C0 FE               [12] 7913 	mov	r6,a
                           00270A  7914 	C$fuzzy.h$2550$5_0$129 ==.
                                   7915 ;	../../fuzzy.h:2550: implication_method,
      0027C1 C0 06            [24] 7916 	push	ar6
      0027C3 C0 05            [24] 7917 	push	ar5
      0027C5 C0 04            [24] 7918 	push	ar4
      0027C7 E5 08            [12] 7919 	mov	a,_bp
      0027C9 24 15            [12] 7920 	add	a,#0x15
      0027CB F8               [12] 7921 	mov	r0,a
      0027CC E6               [12] 7922 	mov	a,@r0
      0027CD C0 E0            [24] 7923 	push	acc
      0027CF 08               [12] 7924 	inc	r0
      0027D0 E6               [12] 7925 	mov	a,@r0
      0027D1 C0 E0            [24] 7926 	push	acc
      0027D3 08               [12] 7927 	inc	r0
      0027D4 E6               [12] 7928 	mov	a,@r0
      0027D5 C0 E0            [24] 7929 	push	acc
      0027D7 08               [12] 7930 	inc	r0
      0027D8 E6               [12] 7931 	mov	a,@r0
      0027D9 C0 E0            [24] 7932 	push	acc
      0027DB C0 02            [24] 7933 	push	ar2
      0027DD C0 03            [24] 7934 	push	ar3
      0027DF C0 07            [24] 7935 	push	ar7
      0027E1 C0 06            [24] 7936 	push	ar6
      0027E3 E5 08            [12] 7937 	mov	a,_bp
      0027E5 24 F1            [12] 7938 	add	a,#0xf1
      0027E7 F8               [12] 7939 	mov	r0,a
      0027E8 86 82            [24] 7940 	mov	dpl, @r0
      0027EA 12 18 D1         [24] 7941 	lcall	_fuzzy_implication
      0027ED C8               [12] 7942 	xch	a,r0
      0027EE E5 08            [12] 7943 	mov	a,_bp
      0027F0 24 19            [12] 7944 	add	a,#0x19
      0027F2 C8               [12] 7945 	xch	a,r0
      0027F3 A6 82            [24] 7946 	mov	@r0, dpl
      0027F5 08               [12] 7947 	inc	r0
      0027F6 A6 83            [24] 7948 	mov	@r0, dph
      0027F8 08               [12] 7949 	inc	r0
      0027F9 A6 F0            [24] 7950 	mov	@r0, b
      0027FB 08               [12] 7951 	inc	r0
      0027FC F6               [12] 7952 	mov	@r0,a
      0027FD E5 81            [12] 7953 	mov	a,sp
      0027FF 24 F8            [12] 7954 	add	a,#0xf8
      002801 F5 81            [12] 7955 	mov	sp,a
      002803 D0 04            [24] 7956 	pop	ar4
      002805 D0 05            [24] 7957 	pop	ar5
      002807 D0 06            [24] 7958 	pop	ar6
                           002752  7959 	C$fuzzy.h$2557$1_0$125 ==.
                                   7960 ;	../../fuzzy.h:2557: implied_height;
      002809 C0 05            [24] 7961 	push	ar5
      00280B C0 04            [24] 7962 	push	ar4
      00280D E5 08            [12] 7963 	mov	a,_bp
      00280F 24 19            [12] 7964 	add	a,#0x19
      002811 F8               [12] 7965 	mov	r0,a
      002812 E6               [12] 7966 	mov	a,@r0
      002813 C0 E0            [24] 7967 	push	acc
      002815 08               [12] 7968 	inc	r0
      002816 E6               [12] 7969 	mov	a,@r0
      002817 C0 E0            [24] 7970 	push	acc
      002819 08               [12] 7971 	inc	r0
      00281A E6               [12] 7972 	mov	a,@r0
      00281B C0 E0            [24] 7973 	push	acc
      00281D 08               [12] 7974 	inc	r0
      00281E E6               [12] 7975 	mov	a,@r0
      00281F C0 E0            [24] 7976 	push	acc
      002821 E5 08            [12] 7977 	mov	a,_bp
      002823 24 11            [12] 7978 	add	a,#0x11
      002825 F8               [12] 7979 	mov	r0,a
      002826 86 82            [24] 7980 	mov	dpl, @r0
      002828 08               [12] 7981 	inc	r0
      002829 86 83            [24] 7982 	mov	dph, @r0
      00282B 08               [12] 7983 	inc	r0
      00282C 86 F0            [24] 7984 	mov	b, @r0
      00282E 08               [12] 7985 	inc	r0
      00282F E6               [12] 7986 	mov	a, @r0
      002830 12 34 92         [24] 7987 	lcall	___fsmul
      002833 AA 82            [24] 7988 	mov	r2, dpl
      002835 AB 83            [24] 7989 	mov	r3, dph
      002837 AE F0            [24] 7990 	mov	r6, b
      002839 FF               [12] 7991 	mov	r7, a
      00283A E5 81            [12] 7992 	mov	a,sp
      00283C 24 FC            [12] 7993 	add	a,#0xfc
      00283E F5 81            [12] 7994 	mov	sp,a
      002840 D0 04            [24] 7995 	pop	ar4
      002842 D0 05            [24] 7996 	pop	ar5
      002844 C0 06            [24] 7997 	push	ar6
      002846 C0 05            [24] 7998 	push	ar5
      002848 C0 04            [24] 7999 	push	ar4
      00284A C0 02            [24] 8000 	push	ar2
      00284C C0 03            [24] 8001 	push	ar3
      00284E C0 06            [24] 8002 	push	ar6
      002850 C0 07            [24] 8003 	push	ar7
                           00279B  8004 	C$fuzzy.h$2560$1_0$125 ==.
                                   8005 ;	../../fuzzy.h:2560: implied_height;
      002852 E5 08            [12] 8006 	mov	a,_bp
      002854 24 09            [12] 8007 	add	a,#0x09
      002856 F8               [12] 8008 	mov	r0,a
      002857 86 82            [24] 8009 	mov	dpl, @r0
      002859 08               [12] 8010 	inc	r0
      00285A 86 83            [24] 8011 	mov	dph, @r0
      00285C 08               [12] 8012 	inc	r0
      00285D 86 F0            [24] 8013 	mov	b, @r0
      00285F 08               [12] 8014 	inc	r0
      002860 E6               [12] 8015 	mov	a, @r0
      002861 12 36 14         [24] 8016 	lcall	___fsadd
      002864 C8               [12] 8017 	xch	a,r0
      002865 E5 08            [12] 8018 	mov	a,_bp
      002867 24 09            [12] 8019 	add	a,#0x09
      002869 C8               [12] 8020 	xch	a,r0
      00286A A6 82            [24] 8021 	mov	@r0, dpl
      00286C 08               [12] 8022 	inc	r0
      00286D A6 83            [24] 8023 	mov	@r0, dph
      00286F 08               [12] 8024 	inc	r0
      002870 A6 F0            [24] 8025 	mov	@r0, b
      002872 08               [12] 8026 	inc	r0
      002873 F6               [12] 8027 	mov	@r0,a
      002874 E5 81            [12] 8028 	mov	a,sp
      002876 24 FC            [12] 8029 	add	a,#0xfc
      002878 F5 81            [12] 8030 	mov	sp,a
      00287A E5 08            [12] 8031 	mov	a,_bp
      00287C 24 19            [12] 8032 	add	a,#0x19
      00287E F8               [12] 8033 	mov	r0,a
      00287F E6               [12] 8034 	mov	a,@r0
      002880 C0 E0            [24] 8035 	push	acc
      002882 08               [12] 8036 	inc	r0
      002883 E6               [12] 8037 	mov	a,@r0
      002884 C0 E0            [24] 8038 	push	acc
      002886 08               [12] 8039 	inc	r0
      002887 E6               [12] 8040 	mov	a,@r0
      002888 C0 E0            [24] 8041 	push	acc
      00288A 08               [12] 8042 	inc	r0
      00288B E6               [12] 8043 	mov	a,@r0
      00288C C0 E0            [24] 8044 	push	acc
                           0027D7  8045 	C$fuzzy.h$2540$1_0$125 ==.
                                   8046 ;	../../fuzzy.h:2540: index++
      00288E E5 08            [12] 8047 	mov	a,_bp
      002890 24 0D            [12] 8048 	add	a,#0x0d
      002892 F8               [12] 8049 	mov	r0,a
      002893 86 82            [24] 8050 	mov	dpl, @r0
      002895 08               [12] 8051 	inc	r0
      002896 86 83            [24] 8052 	mov	dph, @r0
      002898 08               [12] 8053 	inc	r0
      002899 86 F0            [24] 8054 	mov	b, @r0
      00289B 08               [12] 8055 	inc	r0
      00289C E6               [12] 8056 	mov	a, @r0
      00289D 12 36 14         [24] 8057 	lcall	___fsadd
      0028A0 C8               [12] 8058 	xch	a,r0
      0028A1 E5 08            [12] 8059 	mov	a,_bp
      0028A3 24 0D            [12] 8060 	add	a,#0x0d
      0028A5 C8               [12] 8061 	xch	a,r0
      0028A6 A6 82            [24] 8062 	mov	@r0, dpl
      0028A8 08               [12] 8063 	inc	r0
      0028A9 A6 83            [24] 8064 	mov	@r0, dph
      0028AB 08               [12] 8065 	inc	r0
      0028AC A6 F0            [24] 8066 	mov	@r0, b
      0028AE 08               [12] 8067 	inc	r0
      0028AF F6               [12] 8068 	mov	@r0,a
      0028B0 E5 81            [12] 8069 	mov	a,sp
      0028B2 24 FC            [12] 8070 	add	a,#0xfc
      0028B4 F5 81            [12] 8071 	mov	sp,a
      0028B6 D0 04            [24] 8072 	pop	ar4
      0028B8 D0 05            [24] 8073 	pop	ar5
      0028BA D0 06            [24] 8074 	pop	ar6
      0028BC E5 08            [12] 8075 	mov	a,_bp
      0028BE 24 07            [12] 8076 	add	a,#0x07
      0028C0 F8               [12] 8077 	mov	r0,a
      0028C1 74 09            [12] 8078 	mov	a,#0x09
      0028C3 26               [12] 8079 	add	a, @r0
      0028C4 F6               [12] 8080 	mov	@r0,a
      0028C5 E4               [12] 8081 	clr	a
      0028C6 08               [12] 8082 	inc	r0
      0028C7 36               [12] 8083 	addc	a, @r0
      0028C8 F6               [12] 8084 	mov	@r0,a
      0028C9 E5 08            [12] 8085 	mov	a,_bp
      0028CB 24 1D            [12] 8086 	add	a,#0x1d
      0028CD F8               [12] 8087 	mov	r0,a
      0028CE 06               [12] 8088 	inc	@r0
      0028CF B6 00 02         [24] 8089 	cjne	@r0,#0x00,00148$
      0028D2 08               [12] 8090 	inc	r0
      0028D3 06               [12] 8091 	inc	@r0
      0028D4                       8092 00148$:
      0028D4 D0 06            [24] 8093 	pop	ar6
      0028D6 D0 05            [24] 8094 	pop	ar5
      0028D8 D0 04            [24] 8095 	pop	ar4
      0028DA 02 26 F0         [24] 8096 	ljmp	00106$
      0028DD                       8097 00110$:
                           002826  8098 	C$fuzzy.h$2536$1_0$125 ==.
                                   8099 ;	../../fuzzy.h:2536: ) {
      0028DD C0 06            [24] 8100 	push	ar6
      0028DF C0 05            [24] 8101 	push	ar5
      0028E1 C0 04            [24] 8102 	push	ar4
      0028E3 E5 08            [12] 8103 	mov	a,_bp
      0028E5 24 F2            [12] 8104 	add	a,#0xf2
      0028E7 F8               [12] 8105 	mov	r0,a
      0028E8 E6               [12] 8106 	mov	a,@r0
      0028E9 C0 E0            [24] 8107 	push	acc
      0028EB 08               [12] 8108 	inc	r0
      0028EC E6               [12] 8109 	mov	a,@r0
      0028ED C0 E0            [24] 8110 	push	acc
      0028EF 08               [12] 8111 	inc	r0
      0028F0 E6               [12] 8112 	mov	a,@r0
      0028F1 C0 E0            [24] 8113 	push	acc
      0028F3 08               [12] 8114 	inc	r0
      0028F4 E6               [12] 8115 	mov	a,@r0
      0028F5 C0 E0            [24] 8116 	push	acc
      0028F7 E5 08            [12] 8117 	mov	a,_bp
      0028F9 24 11            [12] 8118 	add	a,#0x11
      0028FB F8               [12] 8119 	mov	r0,a
      0028FC 86 82            [24] 8120 	mov	dpl, @r0
      0028FE 08               [12] 8121 	inc	r0
      0028FF 86 83            [24] 8122 	mov	dph, @r0
      002901 08               [12] 8123 	inc	r0
      002902 86 F0            [24] 8124 	mov	b, @r0
      002904 08               [12] 8125 	inc	r0
      002905 E6               [12] 8126 	mov	a, @r0
      002906 12 36 14         [24] 8127 	lcall	___fsadd
      002909 C8               [12] 8128 	xch	a,r0
      00290A E5 08            [12] 8129 	mov	a,_bp
      00290C 24 11            [12] 8130 	add	a,#0x11
      00290E C8               [12] 8131 	xch	a,r0
      00290F A6 82            [24] 8132 	mov	@r0, dpl
      002911 08               [12] 8133 	inc	r0
      002912 A6 83            [24] 8134 	mov	@r0, dph
      002914 08               [12] 8135 	inc	r0
      002915 A6 F0            [24] 8136 	mov	@r0, b
      002917 08               [12] 8137 	inc	r0
      002918 F6               [12] 8138 	mov	@r0,a
      002919 E5 81            [12] 8139 	mov	a,sp
      00291B 24 FC            [12] 8140 	add	a,#0xfc
      00291D F5 81            [12] 8141 	mov	sp,a
      00291F D0 04            [24] 8142 	pop	ar4
      002921 D0 05            [24] 8143 	pop	ar5
      002923 D0 06            [24] 8144 	pop	ar6
      002925 02 26 9B         [24] 8145 	ljmp	00109$
      002928                       8146 00102$:
                           002871  8147 	C$fuzzy.h$2564$1_0$125 ==.
                                   8148 ;	../../fuzzy.h:2564: if (height_sum <= LEVEL_LO) {
      002928 E5 08            [12] 8149 	mov	a,_bp
      00292A 24 0D            [12] 8150 	add	a,#0x0d
      00292C F8               [12] 8151 	mov	r0,a
      00292D E6               [12] 8152 	mov	a,@r0
      00292E C0 E0            [24] 8153 	push	acc
      002930 08               [12] 8154 	inc	r0
      002931 E6               [12] 8155 	mov	a,@r0
      002932 C0 E0            [24] 8156 	push	acc
      002934 08               [12] 8157 	inc	r0
      002935 E6               [12] 8158 	mov	a,@r0
      002936 C0 E0            [24] 8159 	push	acc
      002938 08               [12] 8160 	inc	r0
      002939 E6               [12] 8161 	mov	a,@r0
      00293A C0 E0            [24] 8162 	push	acc
      00293C 90 00 00         [24] 8163 	mov	dptr,#0x0000
      00293F E4               [12] 8164 	clr	a
      002940 F5 F0            [12] 8165 	mov	b,a
      002942 12 35 C2         [24] 8166 	lcall	___fslt
      002945 E5 81            [12] 8167 	mov	a,sp
      002947 24 FC            [12] 8168 	add	a,#0xfc
      002949 F5 81            [12] 8169 	mov	sp,a
      00294B E5 82            [12] 8170 	mov	a, dpl
      00294D 24 FF            [12] 8171 	add	a,#0xff
      00294F 92 00            [24] 8172 	mov	b0,c
      002951 40 08            [24] 8173 	jc	00104$
                           00289C  8174 	C$fuzzy.h$2565$2_0$130 ==.
                                   8175 ;	../../fuzzy.h:2565: return 0.0f;
      002953 90 00 00         [24] 8176 	mov	dptr,#0x0000
      002956 E4               [12] 8177 	clr	a
      002957 F5 F0            [12] 8178 	mov	b,a
      002959 80 3A            [24] 8179 	sjmp	00111$
      00295B                       8180 00104$:
                           0028A4  8181 	C$fuzzy.h$2569$1_0$125 ==.
                                   8182 ;	../../fuzzy.h:2569: height_sum;
      00295B E5 08            [12] 8183 	mov	a,_bp
      00295D 24 0D            [12] 8184 	add	a,#0x0d
      00295F F8               [12] 8185 	mov	r0,a
      002960 E6               [12] 8186 	mov	a,@r0
      002961 C0 E0            [24] 8187 	push	acc
      002963 08               [12] 8188 	inc	r0
      002964 E6               [12] 8189 	mov	a,@r0
      002965 C0 E0            [24] 8190 	push	acc
      002967 08               [12] 8191 	inc	r0
      002968 E6               [12] 8192 	mov	a,@r0
      002969 C0 E0            [24] 8193 	push	acc
      00296B 08               [12] 8194 	inc	r0
      00296C E6               [12] 8195 	mov	a,@r0
      00296D C0 E0            [24] 8196 	push	acc
      00296F E5 08            [12] 8197 	mov	a,_bp
      002971 24 09            [12] 8198 	add	a,#0x09
      002973 F8               [12] 8199 	mov	r0,a
      002974 86 82            [24] 8200 	mov	dpl, @r0
      002976 08               [12] 8201 	inc	r0
      002977 86 83            [24] 8202 	mov	dph, @r0
      002979 08               [12] 8203 	inc	r0
      00297A 86 F0            [24] 8204 	mov	b, @r0
      00297C 08               [12] 8205 	inc	r0
      00297D E6               [12] 8206 	mov	a, @r0
      00297E 12 37 2B         [24] 8207 	lcall	___fsdiv
      002981 AC 82            [24] 8208 	mov	r4, dpl
      002983 AD 83            [24] 8209 	mov	r5, dph
      002985 AE F0            [24] 8210 	mov	r6, b
      002987 FF               [12] 8211 	mov	r7, a
      002988 E5 81            [12] 8212 	mov	a,sp
      00298A 24 FC            [12] 8213 	add	a,#0xfc
      00298C F5 81            [12] 8214 	mov	sp,a
      00298E 8C 82            [24] 8215 	mov	dpl, r4
      002990 8D 83            [24] 8216 	mov	dph, r5
      002992 8E F0            [24] 8217 	mov	b, r6
      002994 EF               [12] 8218 	mov	a, r7
      002995                       8219 00111$:
                           0028DE  8220 	C$fuzzy.h$2570$1_0$125 ==.
                                   8221 ;	../../fuzzy.h:2570: }
      002995 85 08 81         [24] 8222 	mov	sp,_bp
      002998 D0 08            [24] 8223 	pop	_bp
                           0028E3  8224 	C$fuzzy.h$2570$1_0$125 ==.
                           0028E3  8225 	XG$fuzzy_rules_defuzzify_cos$0$0 ==.
      00299A 22               [24] 8226 	ret
                                   8227 ;------------------------------------------------------------
                                   8228 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_mom'
                                   8229 ;------------------------------------------------------------
                                   8230 ;lower         Allocated to stack - _bp -6 +4 
                                   8231 ;upper         Allocated to stack - _bp -10 +4 
                                   8232 ;step          Allocated to stack - _bp -14 +4 
                                   8233 ;implication_method Allocated to stack - _bp -15 +1 
                                   8234 ;aggregation_method Allocated to stack - _bp -16 +1 
                                   8235 ;rules         Allocated to stack - _bp +1 +3 
                                   8236 ;result        Allocated to stack - _bp +8 +18 
                                   8237 ;sloc0         Allocated to stack - _bp +4 +4 
                                   8238 ;------------------------------------------------------------
                           0028E4  8239 	G$fuzzy_rules_defuzzify_mom$0$0 ==.
                           0028E4  8240 	C$fuzzy.h$2576$1_0$132 ==.
                                   8241 ;	../../fuzzy.h:2576: float fuzzy_rules_defuzzify_mom(
                                   8242 ;	-----------------------------------------
                                   8243 ;	 function fuzzy_rules_defuzzify_mom
                                   8244 ;	-----------------------------------------
      00299B                       8245 _fuzzy_rules_defuzzify_mom:
      00299B C0 08            [24] 8246 	push	_bp
      00299D 85 81 08         [24] 8247 	mov	_bp,sp
      0029A0 C0 82            [24] 8248 	push	dpl
      0029A2 C0 83            [24] 8249 	push	dph
      0029A4 C0 F0            [24] 8250 	push	b
      0029A6 E5 81            [12] 8251 	mov	a,sp
      0029A8 24 16            [12] 8252 	add	a,#0x16
      0029AA F5 81            [12] 8253 	mov	sp,a
                           0028F5  8254 	C$fuzzy.h$2588$1_0$132 ==.
                                   8255 ;	../../fuzzy.h:2588: &result,
      0029AC E5 08            [12] 8256 	mov	a,_bp
      0029AE 24 08            [12] 8257 	add	a,#0x08
      0029B0 FC               [12] 8258 	mov	r4,a
      0029B1 FA               [12] 8259 	mov	r2,a
      0029B2 7B 00            [12] 8260 	mov	r3,#0x00
      0029B4 7F 40            [12] 8261 	mov	r7,#0x40
      0029B6 C0 04            [24] 8262 	push	ar4
      0029B8 E5 08            [12] 8263 	mov	a,_bp
      0029BA 24 F0            [12] 8264 	add	a,#0xf0
      0029BC F8               [12] 8265 	mov	r0,a
      0029BD E6               [12] 8266 	mov	a,@r0
      0029BE C0 E0            [24] 8267 	push	acc
      0029C0 E5 08            [12] 8268 	mov	a,_bp
      0029C2 24 F1            [12] 8269 	add	a,#0xf1
      0029C4 F8               [12] 8270 	mov	r0,a
      0029C5 E6               [12] 8271 	mov	a,@r0
      0029C6 C0 E0            [24] 8272 	push	acc
      0029C8 E5 08            [12] 8273 	mov	a,_bp
      0029CA 24 F2            [12] 8274 	add	a,#0xf2
      0029CC F8               [12] 8275 	mov	r0,a
      0029CD E6               [12] 8276 	mov	a,@r0
      0029CE C0 E0            [24] 8277 	push	acc
      0029D0 08               [12] 8278 	inc	r0
      0029D1 E6               [12] 8279 	mov	a,@r0
      0029D2 C0 E0            [24] 8280 	push	acc
      0029D4 08               [12] 8281 	inc	r0
      0029D5 E6               [12] 8282 	mov	a,@r0
      0029D6 C0 E0            [24] 8283 	push	acc
      0029D8 08               [12] 8284 	inc	r0
      0029D9 E6               [12] 8285 	mov	a,@r0
      0029DA C0 E0            [24] 8286 	push	acc
      0029DC E5 08            [12] 8287 	mov	a,_bp
      0029DE 24 F6            [12] 8288 	add	a,#0xf6
      0029E0 F8               [12] 8289 	mov	r0,a
      0029E1 E6               [12] 8290 	mov	a,@r0
      0029E2 C0 E0            [24] 8291 	push	acc
      0029E4 08               [12] 8292 	inc	r0
      0029E5 E6               [12] 8293 	mov	a,@r0
      0029E6 C0 E0            [24] 8294 	push	acc
      0029E8 08               [12] 8295 	inc	r0
      0029E9 E6               [12] 8296 	mov	a,@r0
      0029EA C0 E0            [24] 8297 	push	acc
      0029EC 08               [12] 8298 	inc	r0
      0029ED E6               [12] 8299 	mov	a,@r0
      0029EE C0 E0            [24] 8300 	push	acc
      0029F0 E5 08            [12] 8301 	mov	a,_bp
      0029F2 24 FA            [12] 8302 	add	a,#0xfa
      0029F4 F8               [12] 8303 	mov	r0,a
      0029F5 E6               [12] 8304 	mov	a,@r0
      0029F6 C0 E0            [24] 8305 	push	acc
      0029F8 08               [12] 8306 	inc	r0
      0029F9 E6               [12] 8307 	mov	a,@r0
      0029FA C0 E0            [24] 8308 	push	acc
      0029FC 08               [12] 8309 	inc	r0
      0029FD E6               [12] 8310 	mov	a,@r0
      0029FE C0 E0            [24] 8311 	push	acc
      002A00 08               [12] 8312 	inc	r0
      002A01 E6               [12] 8313 	mov	a,@r0
      002A02 C0 E0            [24] 8314 	push	acc
      002A04 A8 08            [24] 8315 	mov	r0,_bp
      002A06 08               [12] 8316 	inc	r0
      002A07 E6               [12] 8317 	mov	a,@r0
      002A08 C0 E0            [24] 8318 	push	acc
      002A0A 08               [12] 8319 	inc	r0
      002A0B E6               [12] 8320 	mov	a,@r0
      002A0C C0 E0            [24] 8321 	push	acc
      002A0E 08               [12] 8322 	inc	r0
      002A0F E6               [12] 8323 	mov	a,@r0
      002A10 C0 E0            [24] 8324 	push	acc
      002A12 8A 82            [24] 8325 	mov	dpl, r2
      002A14 8B 83            [24] 8326 	mov	dph, r3
      002A16 8F F0            [24] 8327 	mov	b, r7
      002A18 12 1D 41         [24] 8328 	lcall	_fuzzy_rules_maximum_result
      002A1B E5 81            [12] 8329 	mov	a,sp
      002A1D 24 EF            [12] 8330 	add	a,#0xef
      002A1F F5 81            [12] 8331 	mov	sp,a
      002A21 D0 04            [24] 8332 	pop	ar4
                           00296C  8333 	C$fuzzy.h$2598$1_0$132 ==.
                                   8334 ;	../../fuzzy.h:2598: result.position_count == 0u ||
      002A23 74 10            [12] 8335 	mov	a,#0x10
      002A25 2C               [12] 8336 	add	a, r4
      002A26 F9               [12] 8337 	mov	r1,a
      002A27 87 06            [24] 8338 	mov	ar6,@r1
      002A29 09               [12] 8339 	inc	r1
      002A2A 87 07            [24] 8340 	mov	ar7,@r1
      002A2C EE               [12] 8341 	mov	a,r6
      002A2D 4F               [12] 8342 	orl	a,r7
      002A2E 60 41            [24] 8343 	jz	00101$
                           002979  8344 	C$fuzzy.h$2599$1_0$132 ==.
                                   8345 ;	../../fuzzy.h:2599: result.height <= LEVEL_LO
      002A30 C0 06            [24] 8346 	push	ar6
      002A32 C0 07            [24] 8347 	push	ar7
      002A34 8C 01            [24] 8348 	mov	ar1,r4
      002A36 87 02            [24] 8349 	mov	ar2,@r1
      002A38 09               [12] 8350 	inc	r1
      002A39 87 03            [24] 8351 	mov	ar3,@r1
      002A3B 09               [12] 8352 	inc	r1
      002A3C 87 05            [24] 8353 	mov	ar5,@r1
      002A3E 09               [12] 8354 	inc	r1
      002A3F 87 07            [24] 8355 	mov	ar7,@r1
      002A41 C0 07            [24] 8356 	push	ar7
      002A43 C0 06            [24] 8357 	push	ar6
      002A45 C0 04            [24] 8358 	push	ar4
      002A47 C0 02            [24] 8359 	push	ar2
      002A49 C0 03            [24] 8360 	push	ar3
      002A4B C0 05            [24] 8361 	push	ar5
      002A4D C0 07            [24] 8362 	push	ar7
      002A4F 90 00 00         [24] 8363 	mov	dptr,#0x0000
      002A52 E4               [12] 8364 	clr	a
      002A53 F5 F0            [12] 8365 	mov	b,a
      002A55 12 35 C2         [24] 8366 	lcall	___fslt
      002A58 E5 81            [12] 8367 	mov	a,sp
      002A5A 24 FC            [12] 8368 	add	a,#0xfc
      002A5C F5 81            [12] 8369 	mov	sp,a
      002A5E D0 04            [24] 8370 	pop	ar4
      002A60 D0 06            [24] 8371 	pop	ar6
      002A62 D0 07            [24] 8372 	pop	ar7
      002A64 E5 82            [12] 8373 	mov	a, dpl
      002A66 24 FF            [12] 8374 	add	a,#0xff
      002A68 92 00            [24] 8375 	mov	b0,c
      002A6A D0 07            [24] 8376 	pop	ar7
      002A6C D0 06            [24] 8377 	pop	ar6
      002A6E 20 00 08         [24] 8378 	jb	b0,00102$
      002A71                       8379 00101$:
                           0029BA  8380 	C$fuzzy.h$2601$2_0$133 ==.
                                   8381 ;	../../fuzzy.h:2601: return 0.0f;
      002A71 90 00 00         [24] 8382 	mov	dptr,#0x0000
      002A74 E4               [12] 8383 	clr	a
      002A75 F5 F0            [12] 8384 	mov	b,a
      002A77 80 53            [24] 8385 	sjmp	00104$
      002A79                       8386 00102$:
                           0029C2  8387 	C$fuzzy.h$2604$1_0$132 ==.
                                   8388 ;	../../fuzzy.h:2604: return result.position_sum /
      002A79 74 0C            [12] 8389 	mov	a,#0x0c
      002A7B 2C               [12] 8390 	add	a, r4
      002A7C F9               [12] 8391 	mov	r1,a
      002A7D E5 08            [12] 8392 	mov	a,_bp
      002A7F 24 04            [12] 8393 	add	a,#0x04
      002A81 F8               [12] 8394 	mov	r0,a
      002A82 E7               [12] 8395 	mov	a,@r1
      002A83 F6               [12] 8396 	mov	@r0,a
      002A84 09               [12] 8397 	inc	r1
      002A85 E7               [12] 8398 	mov	a,@r1
      002A86 08               [12] 8399 	inc	r0
      002A87 F6               [12] 8400 	mov	@r0,a
      002A88 09               [12] 8401 	inc	r1
      002A89 E7               [12] 8402 	mov	a,@r1
      002A8A 08               [12] 8403 	inc	r0
      002A8B F6               [12] 8404 	mov	@r0,a
      002A8C 09               [12] 8405 	inc	r1
      002A8D E7               [12] 8406 	mov	a,@r1
      002A8E 08               [12] 8407 	inc	r0
      002A8F F6               [12] 8408 	mov	@r0,a
                           0029D9  8409 	C$fuzzy.h$2605$1_0$132 ==.
                                   8410 ;	../../fuzzy.h:2605: (float)result.position_count;
      002A90 8E 82            [24] 8411 	mov	dpl, r6
      002A92 8F 83            [24] 8412 	mov	dph, r7
      002A94 12 36 B6         [24] 8413 	lcall	___uint2fs
      002A97 AC 82            [24] 8414 	mov	r4, dpl
      002A99 AD 83            [24] 8415 	mov	r5, dph
      002A9B AE F0            [24] 8416 	mov	r6, b
      002A9D FF               [12] 8417 	mov	r7, a
      002A9E C0 04            [24] 8418 	push	ar4
      002AA0 C0 05            [24] 8419 	push	ar5
      002AA2 C0 06            [24] 8420 	push	ar6
      002AA4 C0 07            [24] 8421 	push	ar7
      002AA6 E5 08            [12] 8422 	mov	a,_bp
      002AA8 24 04            [12] 8423 	add	a,#0x04
      002AAA F8               [12] 8424 	mov	r0,a
      002AAB 86 82            [24] 8425 	mov	dpl, @r0
      002AAD 08               [12] 8426 	inc	r0
      002AAE 86 83            [24] 8427 	mov	dph, @r0
      002AB0 08               [12] 8428 	inc	r0
      002AB1 86 F0            [24] 8429 	mov	b, @r0
      002AB3 08               [12] 8430 	inc	r0
      002AB4 E6               [12] 8431 	mov	a, @r0
      002AB5 12 37 2B         [24] 8432 	lcall	___fsdiv
      002AB8 AC 82            [24] 8433 	mov	r4, dpl
      002ABA AD 83            [24] 8434 	mov	r5, dph
      002ABC AE F0            [24] 8435 	mov	r6, b
      002ABE FF               [12] 8436 	mov	r7, a
      002ABF E5 81            [12] 8437 	mov	a,sp
      002AC1 24 FC            [12] 8438 	add	a,#0xfc
      002AC3 F5 81            [12] 8439 	mov	sp,a
      002AC5 8C 82            [24] 8440 	mov	dpl, r4
      002AC7 8D 83            [24] 8441 	mov	dph, r5
      002AC9 8E F0            [24] 8442 	mov	b, r6
      002ACB EF               [12] 8443 	mov	a, r7
      002ACC                       8444 00104$:
                           002A15  8445 	C$fuzzy.h$2606$1_0$132 ==.
                                   8446 ;	../../fuzzy.h:2606: }
      002ACC 85 08 81         [24] 8447 	mov	sp,_bp
      002ACF D0 08            [24] 8448 	pop	_bp
                           002A1A  8449 	C$fuzzy.h$2606$1_0$132 ==.
                           002A1A  8450 	XG$fuzzy_rules_defuzzify_mom$0$0 ==.
      002AD1 22               [24] 8451 	ret
                                   8452 ;------------------------------------------------------------
                                   8453 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_som'
                                   8454 ;------------------------------------------------------------
                                   8455 ;lower         Allocated to stack - _bp -6 +4 
                                   8456 ;upper         Allocated to stack - _bp -10 +4 
                                   8457 ;step          Allocated to stack - _bp -14 +4 
                                   8458 ;implication_method Allocated to stack - _bp -15 +1 
                                   8459 ;aggregation_method Allocated to stack - _bp -16 +1 
                                   8460 ;rules         Allocated to stack - _bp +1 +3 
                                   8461 ;result        Allocated to stack - _bp +4 +18 
                                   8462 ;------------------------------------------------------------
                           002A1B  8463 	G$fuzzy_rules_defuzzify_som$0$0 ==.
                           002A1B  8464 	C$fuzzy.h$2612$1_0$135 ==.
                                   8465 ;	../../fuzzy.h:2612: float fuzzy_rules_defuzzify_som(
                                   8466 ;	-----------------------------------------
                                   8467 ;	 function fuzzy_rules_defuzzify_som
                                   8468 ;	-----------------------------------------
      002AD2                       8469 _fuzzy_rules_defuzzify_som:
      002AD2 C0 08            [24] 8470 	push	_bp
      002AD4 85 81 08         [24] 8471 	mov	_bp,sp
      002AD7 C0 82            [24] 8472 	push	dpl
      002AD9 C0 83            [24] 8473 	push	dph
      002ADB C0 F0            [24] 8474 	push	b
      002ADD E5 81            [12] 8475 	mov	a,sp
      002ADF 24 12            [12] 8476 	add	a,#0x12
      002AE1 F5 81            [12] 8477 	mov	sp,a
                           002A2C  8478 	C$fuzzy.h$2624$1_0$135 ==.
                                   8479 ;	../../fuzzy.h:2624: &result,
      002AE3 E5 08            [12] 8480 	mov	a,_bp
      002AE5 24 04            [12] 8481 	add	a,#0x04
      002AE7 FC               [12] 8482 	mov	r4,a
      002AE8 FA               [12] 8483 	mov	r2,a
      002AE9 7B 00            [12] 8484 	mov	r3,#0x00
      002AEB 7F 40            [12] 8485 	mov	r7,#0x40
      002AED C0 04            [24] 8486 	push	ar4
      002AEF E5 08            [12] 8487 	mov	a,_bp
      002AF1 24 F0            [12] 8488 	add	a,#0xf0
      002AF3 F8               [12] 8489 	mov	r0,a
      002AF4 E6               [12] 8490 	mov	a,@r0
      002AF5 C0 E0            [24] 8491 	push	acc
      002AF7 E5 08            [12] 8492 	mov	a,_bp
      002AF9 24 F1            [12] 8493 	add	a,#0xf1
      002AFB F8               [12] 8494 	mov	r0,a
      002AFC E6               [12] 8495 	mov	a,@r0
      002AFD C0 E0            [24] 8496 	push	acc
      002AFF E5 08            [12] 8497 	mov	a,_bp
      002B01 24 F2            [12] 8498 	add	a,#0xf2
      002B03 F8               [12] 8499 	mov	r0,a
      002B04 E6               [12] 8500 	mov	a,@r0
      002B05 C0 E0            [24] 8501 	push	acc
      002B07 08               [12] 8502 	inc	r0
      002B08 E6               [12] 8503 	mov	a,@r0
      002B09 C0 E0            [24] 8504 	push	acc
      002B0B 08               [12] 8505 	inc	r0
      002B0C E6               [12] 8506 	mov	a,@r0
      002B0D C0 E0            [24] 8507 	push	acc
      002B0F 08               [12] 8508 	inc	r0
      002B10 E6               [12] 8509 	mov	a,@r0
      002B11 C0 E0            [24] 8510 	push	acc
      002B13 E5 08            [12] 8511 	mov	a,_bp
      002B15 24 F6            [12] 8512 	add	a,#0xf6
      002B17 F8               [12] 8513 	mov	r0,a
      002B18 E6               [12] 8514 	mov	a,@r0
      002B19 C0 E0            [24] 8515 	push	acc
      002B1B 08               [12] 8516 	inc	r0
      002B1C E6               [12] 8517 	mov	a,@r0
      002B1D C0 E0            [24] 8518 	push	acc
      002B1F 08               [12] 8519 	inc	r0
      002B20 E6               [12] 8520 	mov	a,@r0
      002B21 C0 E0            [24] 8521 	push	acc
      002B23 08               [12] 8522 	inc	r0
      002B24 E6               [12] 8523 	mov	a,@r0
      002B25 C0 E0            [24] 8524 	push	acc
      002B27 E5 08            [12] 8525 	mov	a,_bp
      002B29 24 FA            [12] 8526 	add	a,#0xfa
      002B2B F8               [12] 8527 	mov	r0,a
      002B2C E6               [12] 8528 	mov	a,@r0
      002B2D C0 E0            [24] 8529 	push	acc
      002B2F 08               [12] 8530 	inc	r0
      002B30 E6               [12] 8531 	mov	a,@r0
      002B31 C0 E0            [24] 8532 	push	acc
      002B33 08               [12] 8533 	inc	r0
      002B34 E6               [12] 8534 	mov	a,@r0
      002B35 C0 E0            [24] 8535 	push	acc
      002B37 08               [12] 8536 	inc	r0
      002B38 E6               [12] 8537 	mov	a,@r0
      002B39 C0 E0            [24] 8538 	push	acc
      002B3B A8 08            [24] 8539 	mov	r0,_bp
      002B3D 08               [12] 8540 	inc	r0
      002B3E E6               [12] 8541 	mov	a,@r0
      002B3F C0 E0            [24] 8542 	push	acc
      002B41 08               [12] 8543 	inc	r0
      002B42 E6               [12] 8544 	mov	a,@r0
      002B43 C0 E0            [24] 8545 	push	acc
      002B45 08               [12] 8546 	inc	r0
      002B46 E6               [12] 8547 	mov	a,@r0
      002B47 C0 E0            [24] 8548 	push	acc
      002B49 8A 82            [24] 8549 	mov	dpl, r2
      002B4B 8B 83            [24] 8550 	mov	dph, r3
      002B4D 8F F0            [24] 8551 	mov	b, r7
      002B4F 12 1D 41         [24] 8552 	lcall	_fuzzy_rules_maximum_result
      002B52 E5 81            [12] 8553 	mov	a,sp
      002B54 24 EF            [12] 8554 	add	a,#0xef
      002B56 F5 81            [12] 8555 	mov	sp,a
      002B58 D0 04            [24] 8556 	pop	ar4
                           002AA3  8557 	C$fuzzy.h$2634$1_0$135 ==.
                                   8558 ;	../../fuzzy.h:2634: result.position_count == 0u ||
      002B5A 74 10            [12] 8559 	mov	a,#0x10
      002B5C 2C               [12] 8560 	add	a, r4
      002B5D F9               [12] 8561 	mov	r1,a
      002B5E 87 06            [24] 8562 	mov	ar6,@r1
      002B60 09               [12] 8563 	inc	r1
      002B61 87 07            [24] 8564 	mov	ar7,@r1
      002B63 EE               [12] 8565 	mov	a,r6
      002B64 4F               [12] 8566 	orl	a,r7
      002B65 60 30            [24] 8567 	jz	00101$
                           002AB0  8568 	C$fuzzy.h$2635$1_0$135 ==.
                                   8569 ;	../../fuzzy.h:2635: result.height <= LEVEL_LO
      002B67 8C 01            [24] 8570 	mov	ar1,r4
      002B69 87 03            [24] 8571 	mov	ar3,@r1
      002B6B 09               [12] 8572 	inc	r1
      002B6C 87 05            [24] 8573 	mov	ar5,@r1
      002B6E 09               [12] 8574 	inc	r1
      002B6F 87 06            [24] 8575 	mov	ar6,@r1
      002B71 09               [12] 8576 	inc	r1
      002B72 87 07            [24] 8577 	mov	ar7,@r1
      002B74 C0 04            [24] 8578 	push	ar4
      002B76 C0 03            [24] 8579 	push	ar3
      002B78 C0 05            [24] 8580 	push	ar5
      002B7A C0 06            [24] 8581 	push	ar6
      002B7C C0 07            [24] 8582 	push	ar7
      002B7E 90 00 00         [24] 8583 	mov	dptr,#0x0000
      002B81 E4               [12] 8584 	clr	a
      002B82 F5 F0            [12] 8585 	mov	b,a
      002B84 12 35 C2         [24] 8586 	lcall	___fslt
      002B87 E5 81            [12] 8587 	mov	a,sp
      002B89 24 FC            [12] 8588 	add	a,#0xfc
      002B8B F5 81            [12] 8589 	mov	sp,a
      002B8D D0 04            [24] 8590 	pop	ar4
      002B8F E5 82            [12] 8591 	mov	a, dpl
      002B91 24 FF            [12] 8592 	add	a,#0xff
      002B93 92 00            [24] 8593 	mov	b0,c
      002B95 40 08            [24] 8594 	jc	00102$
      002B97                       8595 00101$:
                           002AE0  8596 	C$fuzzy.h$2637$2_0$136 ==.
                                   8597 ;	../../fuzzy.h:2637: return 0.0f;
      002B97 90 00 00         [24] 8598 	mov	dptr,#0x0000
      002B9A E4               [12] 8599 	clr	a
      002B9B F5 F0            [12] 8600 	mov	b,a
      002B9D 80 16            [24] 8601 	sjmp	00104$
      002B9F                       8602 00102$:
                           002AE8  8603 	C$fuzzy.h$2640$1_0$135 ==.
                                   8604 ;	../../fuzzy.h:2640: return result.smallest_position;
      002B9F 74 04            [12] 8605 	mov	a,#0x04
      002BA1 2C               [12] 8606 	add	a, r4
      002BA2 F9               [12] 8607 	mov	r1,a
      002BA3 87 04            [24] 8608 	mov	ar4,@r1
      002BA5 09               [12] 8609 	inc	r1
      002BA6 87 05            [24] 8610 	mov	ar5,@r1
      002BA8 09               [12] 8611 	inc	r1
      002BA9 87 06            [24] 8612 	mov	ar6,@r1
      002BAB 09               [12] 8613 	inc	r1
      002BAC 87 07            [24] 8614 	mov	ar7,@r1
      002BAE 8C 82            [24] 8615 	mov	dpl, r4
      002BB0 8D 83            [24] 8616 	mov	dph, r5
      002BB2 8E F0            [24] 8617 	mov	b, r6
      002BB4 EF               [12] 8618 	mov	a, r7
      002BB5                       8619 00104$:
                           002AFE  8620 	C$fuzzy.h$2641$1_0$135 ==.
                                   8621 ;	../../fuzzy.h:2641: }
      002BB5 85 08 81         [24] 8622 	mov	sp,_bp
      002BB8 D0 08            [24] 8623 	pop	_bp
                           002B03  8624 	C$fuzzy.h$2641$1_0$135 ==.
                           002B03  8625 	XG$fuzzy_rules_defuzzify_som$0$0 ==.
      002BBA 22               [24] 8626 	ret
                                   8627 ;------------------------------------------------------------
                                   8628 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_lom'
                                   8629 ;------------------------------------------------------------
                                   8630 ;lower         Allocated to stack - _bp -6 +4 
                                   8631 ;upper         Allocated to stack - _bp -10 +4 
                                   8632 ;step          Allocated to stack - _bp -14 +4 
                                   8633 ;implication_method Allocated to stack - _bp -15 +1 
                                   8634 ;aggregation_method Allocated to stack - _bp -16 +1 
                                   8635 ;rules         Allocated to stack - _bp +1 +3 
                                   8636 ;result        Allocated to stack - _bp +4 +18 
                                   8637 ;------------------------------------------------------------
                           002B04  8638 	G$fuzzy_rules_defuzzify_lom$0$0 ==.
                           002B04  8639 	C$fuzzy.h$2647$1_0$138 ==.
                                   8640 ;	../../fuzzy.h:2647: float fuzzy_rules_defuzzify_lom(
                                   8641 ;	-----------------------------------------
                                   8642 ;	 function fuzzy_rules_defuzzify_lom
                                   8643 ;	-----------------------------------------
      002BBB                       8644 _fuzzy_rules_defuzzify_lom:
      002BBB C0 08            [24] 8645 	push	_bp
      002BBD 85 81 08         [24] 8646 	mov	_bp,sp
      002BC0 C0 82            [24] 8647 	push	dpl
      002BC2 C0 83            [24] 8648 	push	dph
      002BC4 C0 F0            [24] 8649 	push	b
      002BC6 E5 81            [12] 8650 	mov	a,sp
      002BC8 24 12            [12] 8651 	add	a,#0x12
      002BCA F5 81            [12] 8652 	mov	sp,a
                           002B15  8653 	C$fuzzy.h$2659$1_0$138 ==.
                                   8654 ;	../../fuzzy.h:2659: &result,
      002BCC E5 08            [12] 8655 	mov	a,_bp
      002BCE 24 04            [12] 8656 	add	a,#0x04
      002BD0 FC               [12] 8657 	mov	r4,a
      002BD1 FA               [12] 8658 	mov	r2,a
      002BD2 7B 00            [12] 8659 	mov	r3,#0x00
      002BD4 7F 40            [12] 8660 	mov	r7,#0x40
      002BD6 C0 04            [24] 8661 	push	ar4
      002BD8 E5 08            [12] 8662 	mov	a,_bp
      002BDA 24 F0            [12] 8663 	add	a,#0xf0
      002BDC F8               [12] 8664 	mov	r0,a
      002BDD E6               [12] 8665 	mov	a,@r0
      002BDE C0 E0            [24] 8666 	push	acc
      002BE0 E5 08            [12] 8667 	mov	a,_bp
      002BE2 24 F1            [12] 8668 	add	a,#0xf1
      002BE4 F8               [12] 8669 	mov	r0,a
      002BE5 E6               [12] 8670 	mov	a,@r0
      002BE6 C0 E0            [24] 8671 	push	acc
      002BE8 E5 08            [12] 8672 	mov	a,_bp
      002BEA 24 F2            [12] 8673 	add	a,#0xf2
      002BEC F8               [12] 8674 	mov	r0,a
      002BED E6               [12] 8675 	mov	a,@r0
      002BEE C0 E0            [24] 8676 	push	acc
      002BF0 08               [12] 8677 	inc	r0
      002BF1 E6               [12] 8678 	mov	a,@r0
      002BF2 C0 E0            [24] 8679 	push	acc
      002BF4 08               [12] 8680 	inc	r0
      002BF5 E6               [12] 8681 	mov	a,@r0
      002BF6 C0 E0            [24] 8682 	push	acc
      002BF8 08               [12] 8683 	inc	r0
      002BF9 E6               [12] 8684 	mov	a,@r0
      002BFA C0 E0            [24] 8685 	push	acc
      002BFC E5 08            [12] 8686 	mov	a,_bp
      002BFE 24 F6            [12] 8687 	add	a,#0xf6
      002C00 F8               [12] 8688 	mov	r0,a
      002C01 E6               [12] 8689 	mov	a,@r0
      002C02 C0 E0            [24] 8690 	push	acc
      002C04 08               [12] 8691 	inc	r0
      002C05 E6               [12] 8692 	mov	a,@r0
      002C06 C0 E0            [24] 8693 	push	acc
      002C08 08               [12] 8694 	inc	r0
      002C09 E6               [12] 8695 	mov	a,@r0
      002C0A C0 E0            [24] 8696 	push	acc
      002C0C 08               [12] 8697 	inc	r0
      002C0D E6               [12] 8698 	mov	a,@r0
      002C0E C0 E0            [24] 8699 	push	acc
      002C10 E5 08            [12] 8700 	mov	a,_bp
      002C12 24 FA            [12] 8701 	add	a,#0xfa
      002C14 F8               [12] 8702 	mov	r0,a
      002C15 E6               [12] 8703 	mov	a,@r0
      002C16 C0 E0            [24] 8704 	push	acc
      002C18 08               [12] 8705 	inc	r0
      002C19 E6               [12] 8706 	mov	a,@r0
      002C1A C0 E0            [24] 8707 	push	acc
      002C1C 08               [12] 8708 	inc	r0
      002C1D E6               [12] 8709 	mov	a,@r0
      002C1E C0 E0            [24] 8710 	push	acc
      002C20 08               [12] 8711 	inc	r0
      002C21 E6               [12] 8712 	mov	a,@r0
      002C22 C0 E0            [24] 8713 	push	acc
      002C24 A8 08            [24] 8714 	mov	r0,_bp
      002C26 08               [12] 8715 	inc	r0
      002C27 E6               [12] 8716 	mov	a,@r0
      002C28 C0 E0            [24] 8717 	push	acc
      002C2A 08               [12] 8718 	inc	r0
      002C2B E6               [12] 8719 	mov	a,@r0
      002C2C C0 E0            [24] 8720 	push	acc
      002C2E 08               [12] 8721 	inc	r0
      002C2F E6               [12] 8722 	mov	a,@r0
      002C30 C0 E0            [24] 8723 	push	acc
      002C32 8A 82            [24] 8724 	mov	dpl, r2
      002C34 8B 83            [24] 8725 	mov	dph, r3
      002C36 8F F0            [24] 8726 	mov	b, r7
      002C38 12 1D 41         [24] 8727 	lcall	_fuzzy_rules_maximum_result
      002C3B E5 81            [12] 8728 	mov	a,sp
      002C3D 24 EF            [12] 8729 	add	a,#0xef
      002C3F F5 81            [12] 8730 	mov	sp,a
      002C41 D0 04            [24] 8731 	pop	ar4
                           002B8C  8732 	C$fuzzy.h$2669$1_0$138 ==.
                                   8733 ;	../../fuzzy.h:2669: result.position_count == 0u ||
      002C43 74 10            [12] 8734 	mov	a,#0x10
      002C45 2C               [12] 8735 	add	a, r4
      002C46 F9               [12] 8736 	mov	r1,a
      002C47 87 06            [24] 8737 	mov	ar6,@r1
      002C49 09               [12] 8738 	inc	r1
      002C4A 87 07            [24] 8739 	mov	ar7,@r1
      002C4C EE               [12] 8740 	mov	a,r6
      002C4D 4F               [12] 8741 	orl	a,r7
      002C4E 60 30            [24] 8742 	jz	00101$
                           002B99  8743 	C$fuzzy.h$2670$1_0$138 ==.
                                   8744 ;	../../fuzzy.h:2670: result.height <= LEVEL_LO
      002C50 8C 01            [24] 8745 	mov	ar1,r4
      002C52 87 03            [24] 8746 	mov	ar3,@r1
      002C54 09               [12] 8747 	inc	r1
      002C55 87 05            [24] 8748 	mov	ar5,@r1
      002C57 09               [12] 8749 	inc	r1
      002C58 87 06            [24] 8750 	mov	ar6,@r1
      002C5A 09               [12] 8751 	inc	r1
      002C5B 87 07            [24] 8752 	mov	ar7,@r1
      002C5D C0 04            [24] 8753 	push	ar4
      002C5F C0 03            [24] 8754 	push	ar3
      002C61 C0 05            [24] 8755 	push	ar5
      002C63 C0 06            [24] 8756 	push	ar6
      002C65 C0 07            [24] 8757 	push	ar7
      002C67 90 00 00         [24] 8758 	mov	dptr,#0x0000
      002C6A E4               [12] 8759 	clr	a
      002C6B F5 F0            [12] 8760 	mov	b,a
      002C6D 12 35 C2         [24] 8761 	lcall	___fslt
      002C70 E5 81            [12] 8762 	mov	a,sp
      002C72 24 FC            [12] 8763 	add	a,#0xfc
      002C74 F5 81            [12] 8764 	mov	sp,a
      002C76 D0 04            [24] 8765 	pop	ar4
      002C78 E5 82            [12] 8766 	mov	a, dpl
      002C7A 24 FF            [12] 8767 	add	a,#0xff
      002C7C 92 00            [24] 8768 	mov	b0,c
      002C7E 40 08            [24] 8769 	jc	00102$
      002C80                       8770 00101$:
                           002BC9  8771 	C$fuzzy.h$2672$2_0$139 ==.
                                   8772 ;	../../fuzzy.h:2672: return 0.0f;
      002C80 90 00 00         [24] 8773 	mov	dptr,#0x0000
      002C83 E4               [12] 8774 	clr	a
      002C84 F5 F0            [12] 8775 	mov	b,a
      002C86 80 16            [24] 8776 	sjmp	00104$
      002C88                       8777 00102$:
                           002BD1  8778 	C$fuzzy.h$2675$1_0$138 ==.
                                   8779 ;	../../fuzzy.h:2675: return result.largest_position;
      002C88 74 08            [12] 8780 	mov	a,#0x08
      002C8A 2C               [12] 8781 	add	a, r4
      002C8B F9               [12] 8782 	mov	r1,a
      002C8C 87 04            [24] 8783 	mov	ar4,@r1
      002C8E 09               [12] 8784 	inc	r1
      002C8F 87 05            [24] 8785 	mov	ar5,@r1
      002C91 09               [12] 8786 	inc	r1
      002C92 87 06            [24] 8787 	mov	ar6,@r1
      002C94 09               [12] 8788 	inc	r1
      002C95 87 07            [24] 8789 	mov	ar7,@r1
      002C97 8C 82            [24] 8790 	mov	dpl, r4
      002C99 8D 83            [24] 8791 	mov	dph, r5
      002C9B 8E F0            [24] 8792 	mov	b, r6
      002C9D EF               [12] 8793 	mov	a, r7
      002C9E                       8794 00104$:
                           002BE7  8795 	C$fuzzy.h$2676$1_0$138 ==.
                                   8796 ;	../../fuzzy.h:2676: }
      002C9E 85 08 81         [24] 8797 	mov	sp,_bp
      002CA1 D0 08            [24] 8798 	pop	_bp
                           002BEC  8799 	C$fuzzy.h$2676$1_0$138 ==.
                           002BEC  8800 	XG$fuzzy_rules_defuzzify_lom$0$0 ==.
      002CA3 22               [24] 8801 	ret
                                   8802 ;------------------------------------------------------------
                                   8803 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify_method'
                                   8804 ;------------------------------------------------------------
                                   8805 ;lower         Allocated to stack - _bp -6 +4 
                                   8806 ;upper         Allocated to stack - _bp -10 +4 
                                   8807 ;step          Allocated to stack - _bp -14 +4 
                                   8808 ;defuzz_method Allocated to stack - _bp -15 +1 
                                   8809 ;implication_method Allocated to stack - _bp -16 +1 
                                   8810 ;aggregation_method Allocated to stack - _bp -17 +1 
                                   8811 ;rules         Allocated to registers r5 r6 r7 
                                   8812 ;sloc0         Allocated to stack - _bp +1 +4 
                                   8813 ;------------------------------------------------------------
                           002BED  8814 	G$fuzzy_rules_defuzzify_method$0$0 ==.
                           002BED  8815 	C$fuzzy.h$2682$1_0$141 ==.
                                   8816 ;	../../fuzzy.h:2682: float fuzzy_rules_defuzzify_method(
                                   8817 ;	-----------------------------------------
                                   8818 ;	 function fuzzy_rules_defuzzify_method
                                   8819 ;	-----------------------------------------
      002CA4                       8820 _fuzzy_rules_defuzzify_method:
      002CA4 C0 08            [24] 8821 	push	_bp
      002CA6 E5 81            [12] 8822 	mov	a,sp
      002CA8 F5 08            [12] 8823 	mov	_bp,a
      002CAA 24 04            [12] 8824 	add	a,#0x04
      002CAC F5 81            [12] 8825 	mov	sp,a
      002CAE AD 82            [24] 8826 	mov	r5, dpl
      002CB0 AE 83            [24] 8827 	mov	r6, dph
      002CB2 AF F0            [24] 8828 	mov	r7, b
                           002BFD  8829 	C$fuzzy.h$2693$1_0$141 ==.
                                   8830 ;	../../fuzzy.h:2693: rules == NULL ||
      002CB4 ED               [12] 8831 	mov	a,r5
      002CB5 4E               [12] 8832 	orl	a,r6
      002CB6 70 03            [24] 8833 	jnz	00140$
      002CB8 02 2D 49         [24] 8834 	ljmp	00101$
      002CBB                       8835 00140$:
                           002C04  8836 	C$fuzzy.h$2694$1_0$141 ==.
                                   8837 ;	../../fuzzy.h:2694: rules->count == 0u ||
      002CBB 74 90            [12] 8838 	mov	a,#0x90
      002CBD 2D               [12] 8839 	add	a, r5
      002CBE FA               [12] 8840 	mov	r2,a
      002CBF E4               [12] 8841 	clr	a
      002CC0 3E               [12] 8842 	addc	a, r6
      002CC1 FB               [12] 8843 	mov	r3,a
      002CC2 8F 04            [24] 8844 	mov	ar4,r7
      002CC4 8A 82            [24] 8845 	mov	dpl,r2
      002CC6 8B 83            [24] 8846 	mov	dph,r3
      002CC8 8C F0            [24] 8847 	mov	b,r4
      002CCA 12 37 EE         [24] 8848 	lcall	__gptrget
      002CCD FA               [12] 8849 	mov	r2,a
      002CCE A3               [24] 8850 	inc	dptr
      002CCF 12 37 EE         [24] 8851 	lcall	__gptrget
      002CD2 4A               [12] 8852 	orl	a,r2
      002CD3 60 74            [24] 8853 	jz	00101$
                           002C1E  8854 	C$fuzzy.h$2695$1_0$141 ==.
                                   8855 ;	../../fuzzy.h:2695: lower > upper ||
      002CD5 C0 07            [24] 8856 	push	ar7
      002CD7 C0 06            [24] 8857 	push	ar6
      002CD9 C0 05            [24] 8858 	push	ar5
      002CDB E5 08            [12] 8859 	mov	a,_bp
      002CDD 24 FA            [12] 8860 	add	a,#0xfa
      002CDF F8               [12] 8861 	mov	r0,a
      002CE0 E6               [12] 8862 	mov	a,@r0
      002CE1 C0 E0            [24] 8863 	push	acc
      002CE3 08               [12] 8864 	inc	r0
      002CE4 E6               [12] 8865 	mov	a,@r0
      002CE5 C0 E0            [24] 8866 	push	acc
      002CE7 08               [12] 8867 	inc	r0
      002CE8 E6               [12] 8868 	mov	a,@r0
      002CE9 C0 E0            [24] 8869 	push	acc
      002CEB 08               [12] 8870 	inc	r0
      002CEC E6               [12] 8871 	mov	a,@r0
      002CED C0 E0            [24] 8872 	push	acc
      002CEF E5 08            [12] 8873 	mov	a,_bp
      002CF1 24 F6            [12] 8874 	add	a,#0xf6
      002CF3 F8               [12] 8875 	mov	r0,a
      002CF4 86 82            [24] 8876 	mov	dpl, @r0
      002CF6 08               [12] 8877 	inc	r0
      002CF7 86 83            [24] 8878 	mov	dph, @r0
      002CF9 08               [12] 8879 	inc	r0
      002CFA 86 F0            [24] 8880 	mov	b, @r0
      002CFC 08               [12] 8881 	inc	r0
      002CFD E6               [12] 8882 	mov	a, @r0
      002CFE 12 35 C2         [24] 8883 	lcall	___fslt
      002D01 AC 82            [24] 8884 	mov	r4, dpl
      002D03 E5 81            [12] 8885 	mov	a,sp
      002D05 24 FC            [12] 8886 	add	a,#0xfc
      002D07 F5 81            [12] 8887 	mov	sp,a
      002D09 D0 05            [24] 8888 	pop	ar5
      002D0B D0 06            [24] 8889 	pop	ar6
      002D0D D0 07            [24] 8890 	pop	ar7
      002D0F EC               [12] 8891 	mov	a,r4
      002D10 70 37            [24] 8892 	jnz	00101$
                           002C5B  8893 	C$fuzzy.h$2697$1_0$141 ==.
                                   8894 ;	../../fuzzy.h:2697: ) {
      002D12 C0 07            [24] 8895 	push	ar7
      002D14 C0 06            [24] 8896 	push	ar6
      002D16 C0 05            [24] 8897 	push	ar5
      002D18 E5 08            [12] 8898 	mov	a,_bp
      002D1A 24 F2            [12] 8899 	add	a,#0xf2
      002D1C F8               [12] 8900 	mov	r0,a
      002D1D E6               [12] 8901 	mov	a,@r0
      002D1E C0 E0            [24] 8902 	push	acc
      002D20 08               [12] 8903 	inc	r0
      002D21 E6               [12] 8904 	mov	a,@r0
      002D22 C0 E0            [24] 8905 	push	acc
      002D24 08               [12] 8906 	inc	r0
      002D25 E6               [12] 8907 	mov	a,@r0
      002D26 C0 E0            [24] 8908 	push	acc
      002D28 08               [12] 8909 	inc	r0
      002D29 E6               [12] 8910 	mov	a,@r0
      002D2A C0 E0            [24] 8911 	push	acc
      002D2C 90 00 00         [24] 8912 	mov	dptr,#0x0000
      002D2F E4               [12] 8913 	clr	a
      002D30 F5 F0            [12] 8914 	mov	b,a
      002D32 12 35 C2         [24] 8915 	lcall	___fslt
      002D35 E5 81            [12] 8916 	mov	a,sp
      002D37 24 FC            [12] 8917 	add	a,#0xfc
      002D39 F5 81            [12] 8918 	mov	sp,a
      002D3B D0 05            [24] 8919 	pop	ar5
      002D3D D0 06            [24] 8920 	pop	ar6
      002D3F D0 07            [24] 8921 	pop	ar7
      002D41 E5 82            [12] 8922 	mov	a, dpl
      002D43 24 FF            [12] 8923 	add	a,#0xff
      002D45 92 00            [24] 8924 	mov	b0,c
      002D47 40 09            [24] 8925 	jc	00102$
      002D49                       8926 00101$:
                           002C92  8927 	C$fuzzy.h$2698$2_0$142 ==.
                                   8928 ;	../../fuzzy.h:2698: return 0.0f;
      002D49 90 00 00         [24] 8929 	mov	dptr,#0x0000
      002D4C E4               [12] 8930 	clr	a
      002D4D F5 F0            [12] 8931 	mov	b,a
      002D4F 02 30 3D         [24] 8932 	ljmp	00114$
      002D52                       8933 00102$:
                           002C9B  8934 	C$fuzzy.h$2701$1_0$141 ==.
                                   8935 ;	../../fuzzy.h:2701: switch (defuzz_method) {
      002D52 E5 08            [12] 8936 	mov	a,_bp
      002D54 24 F1            [12] 8937 	add	a,#0xf1
      002D56 F8               [12] 8938 	mov	r0,a
      002D57 E6               [12] 8939 	mov	a,@r0
      002D58 24 FA            [12] 8940 	add	a,#0xff - 0x05
      002D5A 50 03            [24] 8941 	jnc	00144$
      002D5C 02 30 37         [24] 8942 	ljmp	00112$
      002D5F                       8943 00144$:
      002D5F E5 08            [12] 8944 	mov	a,_bp
      002D61 24 F1            [12] 8945 	add	a,#0xf1
      002D63 F8               [12] 8946 	mov	r0,a
      002D64 E6               [12] 8947 	mov	a,@r0
      002D65 26               [12] 8948 	add	a,@r0
      002D66 26               [12] 8949 	add	a,@r0
      002D67 90 2D 6B         [24] 8950 	mov	dptr,#00145$
      002D6A 73               [24] 8951 	jmp	@a+dptr
      002D6B                       8952 00145$:
      002D6B 02 2D 7D         [24] 8953 	ljmp	00106$
      002D6E 02 2D F5         [24] 8954 	ljmp	00107$
      002D71 02 2E 6D         [24] 8955 	ljmp	00108$
      002D74 02 2E DD         [24] 8956 	ljmp	00109$
      002D77 02 2F 55         [24] 8957 	ljmp	00110$
      002D7A 02 2F CC         [24] 8958 	ljmp	00111$
                           002CC6  8959 	C$fuzzy.h$2702$2_0$143 ==.
                                   8960 ;	../../fuzzy.h:2702: case FUZZY_DEFUZZ_COG:
      002D7D                       8961 00106$:
                           002CC6  8962 	C$fuzzy.h$2704$2_0$143 ==.
                                   8963 ;	../../fuzzy.h:2704: rules,
      002D7D E5 08            [12] 8964 	mov	a,_bp
      002D7F 24 EF            [12] 8965 	add	a,#0xef
      002D81 F8               [12] 8966 	mov	r0,a
      002D82 E6               [12] 8967 	mov	a,@r0
      002D83 C0 E0            [24] 8968 	push	acc
      002D85 E5 08            [12] 8969 	mov	a,_bp
      002D87 24 F0            [12] 8970 	add	a,#0xf0
      002D89 F8               [12] 8971 	mov	r0,a
      002D8A E6               [12] 8972 	mov	a,@r0
      002D8B C0 E0            [24] 8973 	push	acc
      002D8D E5 08            [12] 8974 	mov	a,_bp
      002D8F 24 F2            [12] 8975 	add	a,#0xf2
      002D91 F8               [12] 8976 	mov	r0,a
      002D92 E6               [12] 8977 	mov	a,@r0
      002D93 C0 E0            [24] 8978 	push	acc
      002D95 08               [12] 8979 	inc	r0
      002D96 E6               [12] 8980 	mov	a,@r0
      002D97 C0 E0            [24] 8981 	push	acc
      002D99 08               [12] 8982 	inc	r0
      002D9A E6               [12] 8983 	mov	a,@r0
      002D9B C0 E0            [24] 8984 	push	acc
      002D9D 08               [12] 8985 	inc	r0
      002D9E E6               [12] 8986 	mov	a,@r0
      002D9F C0 E0            [24] 8987 	push	acc
      002DA1 E5 08            [12] 8988 	mov	a,_bp
      002DA3 24 F6            [12] 8989 	add	a,#0xf6
      002DA5 F8               [12] 8990 	mov	r0,a
      002DA6 E6               [12] 8991 	mov	a,@r0
      002DA7 C0 E0            [24] 8992 	push	acc
      002DA9 08               [12] 8993 	inc	r0
      002DAA E6               [12] 8994 	mov	a,@r0
      002DAB C0 E0            [24] 8995 	push	acc
      002DAD 08               [12] 8996 	inc	r0
      002DAE E6               [12] 8997 	mov	a,@r0
      002DAF C0 E0            [24] 8998 	push	acc
      002DB1 08               [12] 8999 	inc	r0
      002DB2 E6               [12] 9000 	mov	a,@r0
      002DB3 C0 E0            [24] 9001 	push	acc
      002DB5 E5 08            [12] 9002 	mov	a,_bp
      002DB7 24 FA            [12] 9003 	add	a,#0xfa
      002DB9 F8               [12] 9004 	mov	r0,a
      002DBA E6               [12] 9005 	mov	a,@r0
      002DBB C0 E0            [24] 9006 	push	acc
      002DBD 08               [12] 9007 	inc	r0
      002DBE E6               [12] 9008 	mov	a,@r0
      002DBF C0 E0            [24] 9009 	push	acc
      002DC1 08               [12] 9010 	inc	r0
      002DC2 E6               [12] 9011 	mov	a,@r0
      002DC3 C0 E0            [24] 9012 	push	acc
      002DC5 08               [12] 9013 	inc	r0
      002DC6 E6               [12] 9014 	mov	a,@r0
      002DC7 C0 E0            [24] 9015 	push	acc
      002DC9 8D 82            [24] 9016 	mov	dpl, r5
      002DCB 8E 83            [24] 9017 	mov	dph, r6
      002DCD 8F F0            [24] 9018 	mov	b, r7
      002DCF 12 21 3F         [24] 9019 	lcall	_fuzzy_rules_defuzzify_cog
      002DD2 A8 08            [24] 9020 	mov	r0,_bp
      002DD4 08               [12] 9021 	inc	r0
      002DD5 A6 82            [24] 9022 	mov	@r0, dpl
      002DD7 08               [12] 9023 	inc	r0
      002DD8 A6 83            [24] 9024 	mov	@r0, dph
      002DDA 08               [12] 9025 	inc	r0
      002DDB A6 F0            [24] 9026 	mov	@r0, b
      002DDD 08               [12] 9027 	inc	r0
      002DDE F6               [12] 9028 	mov	@r0,a
      002DDF E5 81            [12] 9029 	mov	a,sp
      002DE1 24 F2            [12] 9030 	add	a,#0xf2
      002DE3 F5 81            [12] 9031 	mov	sp,a
      002DE5 A8 08            [24] 9032 	mov	r0,_bp
      002DE7 08               [12] 9033 	inc	r0
      002DE8 86 82            [24] 9034 	mov	dpl, @r0
      002DEA 08               [12] 9035 	inc	r0
      002DEB 86 83            [24] 9036 	mov	dph, @r0
      002DED 08               [12] 9037 	inc	r0
      002DEE 86 F0            [24] 9038 	mov	b, @r0
      002DF0 08               [12] 9039 	inc	r0
      002DF1 E6               [12] 9040 	mov	a, @r0
      002DF2 02 30 3D         [24] 9041 	ljmp	00114$
                           002D3E  9042 	C$fuzzy.h$2712$2_0$143 ==.
                                   9043 ;	../../fuzzy.h:2712: case FUZZY_DEFUZZ_BOA:
      002DF5                       9044 00107$:
                           002D3E  9045 	C$fuzzy.h$2714$2_0$143 ==.
                                   9046 ;	../../fuzzy.h:2714: rules,
      002DF5 E5 08            [12] 9047 	mov	a,_bp
      002DF7 24 EF            [12] 9048 	add	a,#0xef
      002DF9 F8               [12] 9049 	mov	r0,a
      002DFA E6               [12] 9050 	mov	a,@r0
      002DFB C0 E0            [24] 9051 	push	acc
      002DFD E5 08            [12] 9052 	mov	a,_bp
      002DFF 24 F0            [12] 9053 	add	a,#0xf0
      002E01 F8               [12] 9054 	mov	r0,a
      002E02 E6               [12] 9055 	mov	a,@r0
      002E03 C0 E0            [24] 9056 	push	acc
      002E05 E5 08            [12] 9057 	mov	a,_bp
      002E07 24 F2            [12] 9058 	add	a,#0xf2
      002E09 F8               [12] 9059 	mov	r0,a
      002E0A E6               [12] 9060 	mov	a,@r0
      002E0B C0 E0            [24] 9061 	push	acc
      002E0D 08               [12] 9062 	inc	r0
      002E0E E6               [12] 9063 	mov	a,@r0
      002E0F C0 E0            [24] 9064 	push	acc
      002E11 08               [12] 9065 	inc	r0
      002E12 E6               [12] 9066 	mov	a,@r0
      002E13 C0 E0            [24] 9067 	push	acc
      002E15 08               [12] 9068 	inc	r0
      002E16 E6               [12] 9069 	mov	a,@r0
      002E17 C0 E0            [24] 9070 	push	acc
      002E19 E5 08            [12] 9071 	mov	a,_bp
      002E1B 24 F6            [12] 9072 	add	a,#0xf6
      002E1D F8               [12] 9073 	mov	r0,a
      002E1E E6               [12] 9074 	mov	a,@r0
      002E1F C0 E0            [24] 9075 	push	acc
      002E21 08               [12] 9076 	inc	r0
      002E22 E6               [12] 9077 	mov	a,@r0
      002E23 C0 E0            [24] 9078 	push	acc
      002E25 08               [12] 9079 	inc	r0
      002E26 E6               [12] 9080 	mov	a,@r0
      002E27 C0 E0            [24] 9081 	push	acc
      002E29 08               [12] 9082 	inc	r0
      002E2A E6               [12] 9083 	mov	a,@r0
      002E2B C0 E0            [24] 9084 	push	acc
      002E2D E5 08            [12] 9085 	mov	a,_bp
      002E2F 24 FA            [12] 9086 	add	a,#0xfa
      002E31 F8               [12] 9087 	mov	r0,a
      002E32 E6               [12] 9088 	mov	a,@r0
      002E33 C0 E0            [24] 9089 	push	acc
      002E35 08               [12] 9090 	inc	r0
      002E36 E6               [12] 9091 	mov	a,@r0
      002E37 C0 E0            [24] 9092 	push	acc
      002E39 08               [12] 9093 	inc	r0
      002E3A E6               [12] 9094 	mov	a,@r0
      002E3B C0 E0            [24] 9095 	push	acc
      002E3D 08               [12] 9096 	inc	r0
      002E3E E6               [12] 9097 	mov	a,@r0
      002E3F C0 E0            [24] 9098 	push	acc
      002E41 8D 82            [24] 9099 	mov	dpl, r5
      002E43 8E 83            [24] 9100 	mov	dph, r6
      002E45 8F F0            [24] 9101 	mov	b, r7
      002E47 12 23 52         [24] 9102 	lcall	_fuzzy_rules_defuzzify_boa
      002E4A A8 08            [24] 9103 	mov	r0,_bp
      002E4C 08               [12] 9104 	inc	r0
      002E4D A6 82            [24] 9105 	mov	@r0, dpl
      002E4F 08               [12] 9106 	inc	r0
      002E50 A6 83            [24] 9107 	mov	@r0, dph
      002E52 08               [12] 9108 	inc	r0
      002E53 A6 F0            [24] 9109 	mov	@r0, b
      002E55 08               [12] 9110 	inc	r0
      002E56 F6               [12] 9111 	mov	@r0,a
      002E57 E5 81            [12] 9112 	mov	a,sp
      002E59 24 F2            [12] 9113 	add	a,#0xf2
      002E5B F5 81            [12] 9114 	mov	sp,a
      002E5D A8 08            [24] 9115 	mov	r0,_bp
      002E5F 08               [12] 9116 	inc	r0
      002E60 86 82            [24] 9117 	mov	dpl, @r0
      002E62 08               [12] 9118 	inc	r0
      002E63 86 83            [24] 9119 	mov	dph, @r0
      002E65 08               [12] 9120 	inc	r0
      002E66 86 F0            [24] 9121 	mov	b, @r0
      002E68 08               [12] 9122 	inc	r0
      002E69 E6               [12] 9123 	mov	a, @r0
      002E6A 02 30 3D         [24] 9124 	ljmp	00114$
                           002DB6  9125 	C$fuzzy.h$2722$2_0$143 ==.
                                   9126 ;	../../fuzzy.h:2722: case FUZZY_DEFUZZ_COS:
      002E6D                       9127 00108$:
                           002DB6  9128 	C$fuzzy.h$2724$2_0$143 ==.
                                   9129 ;	../../fuzzy.h:2724: rules,
      002E6D E5 08            [12] 9130 	mov	a,_bp
      002E6F 24 F0            [12] 9131 	add	a,#0xf0
      002E71 F8               [12] 9132 	mov	r0,a
      002E72 E6               [12] 9133 	mov	a,@r0
      002E73 C0 E0            [24] 9134 	push	acc
      002E75 E5 08            [12] 9135 	mov	a,_bp
      002E77 24 F2            [12] 9136 	add	a,#0xf2
      002E79 F8               [12] 9137 	mov	r0,a
      002E7A E6               [12] 9138 	mov	a,@r0
      002E7B C0 E0            [24] 9139 	push	acc
      002E7D 08               [12] 9140 	inc	r0
      002E7E E6               [12] 9141 	mov	a,@r0
      002E7F C0 E0            [24] 9142 	push	acc
      002E81 08               [12] 9143 	inc	r0
      002E82 E6               [12] 9144 	mov	a,@r0
      002E83 C0 E0            [24] 9145 	push	acc
      002E85 08               [12] 9146 	inc	r0
      002E86 E6               [12] 9147 	mov	a,@r0
      002E87 C0 E0            [24] 9148 	push	acc
      002E89 E5 08            [12] 9149 	mov	a,_bp
      002E8B 24 F6            [12] 9150 	add	a,#0xf6
      002E8D F8               [12] 9151 	mov	r0,a
      002E8E E6               [12] 9152 	mov	a,@r0
      002E8F C0 E0            [24] 9153 	push	acc
      002E91 08               [12] 9154 	inc	r0
      002E92 E6               [12] 9155 	mov	a,@r0
      002E93 C0 E0            [24] 9156 	push	acc
      002E95 08               [12] 9157 	inc	r0
      002E96 E6               [12] 9158 	mov	a,@r0
      002E97 C0 E0            [24] 9159 	push	acc
      002E99 08               [12] 9160 	inc	r0
      002E9A E6               [12] 9161 	mov	a,@r0
      002E9B C0 E0            [24] 9162 	push	acc
      002E9D E5 08            [12] 9163 	mov	a,_bp
      002E9F 24 FA            [12] 9164 	add	a,#0xfa
      002EA1 F8               [12] 9165 	mov	r0,a
      002EA2 E6               [12] 9166 	mov	a,@r0
      002EA3 C0 E0            [24] 9167 	push	acc
      002EA5 08               [12] 9168 	inc	r0
      002EA6 E6               [12] 9169 	mov	a,@r0
      002EA7 C0 E0            [24] 9170 	push	acc
      002EA9 08               [12] 9171 	inc	r0
      002EAA E6               [12] 9172 	mov	a,@r0
      002EAB C0 E0            [24] 9173 	push	acc
      002EAD 08               [12] 9174 	inc	r0
      002EAE E6               [12] 9175 	mov	a,@r0
      002EAF C0 E0            [24] 9176 	push	acc
      002EB1 8D 82            [24] 9177 	mov	dpl, r5
      002EB3 8E 83            [24] 9178 	mov	dph, r6
      002EB5 8F F0            [24] 9179 	mov	b, r7
      002EB7 12 26 38         [24] 9180 	lcall	_fuzzy_rules_defuzzify_cos
      002EBA A8 08            [24] 9181 	mov	r0,_bp
      002EBC 08               [12] 9182 	inc	r0
      002EBD A6 82            [24] 9183 	mov	@r0, dpl
      002EBF 08               [12] 9184 	inc	r0
      002EC0 A6 83            [24] 9185 	mov	@r0, dph
      002EC2 08               [12] 9186 	inc	r0
      002EC3 A6 F0            [24] 9187 	mov	@r0, b
      002EC5 08               [12] 9188 	inc	r0
      002EC6 F6               [12] 9189 	mov	@r0,a
      002EC7 E5 81            [12] 9190 	mov	a,sp
      002EC9 24 F3            [12] 9191 	add	a,#0xf3
      002ECB F5 81            [12] 9192 	mov	sp,a
      002ECD A8 08            [24] 9193 	mov	r0,_bp
      002ECF 08               [12] 9194 	inc	r0
      002ED0 86 82            [24] 9195 	mov	dpl, @r0
      002ED2 08               [12] 9196 	inc	r0
      002ED3 86 83            [24] 9197 	mov	dph, @r0
      002ED5 08               [12] 9198 	inc	r0
      002ED6 86 F0            [24] 9199 	mov	b, @r0
      002ED8 08               [12] 9200 	inc	r0
      002ED9 E6               [12] 9201 	mov	a, @r0
      002EDA 02 30 3D         [24] 9202 	ljmp	00114$
                           002E26  9203 	C$fuzzy.h$2731$2_0$143 ==.
                                   9204 ;	../../fuzzy.h:2731: case FUZZY_DEFUZZ_MOM:
      002EDD                       9205 00109$:
                           002E26  9206 	C$fuzzy.h$2733$2_0$143 ==.
                                   9207 ;	../../fuzzy.h:2733: rules,
      002EDD E5 08            [12] 9208 	mov	a,_bp
      002EDF 24 EF            [12] 9209 	add	a,#0xef
      002EE1 F8               [12] 9210 	mov	r0,a
      002EE2 E6               [12] 9211 	mov	a,@r0
      002EE3 C0 E0            [24] 9212 	push	acc
      002EE5 E5 08            [12] 9213 	mov	a,_bp
      002EE7 24 F0            [12] 9214 	add	a,#0xf0
      002EE9 F8               [12] 9215 	mov	r0,a
      002EEA E6               [12] 9216 	mov	a,@r0
      002EEB C0 E0            [24] 9217 	push	acc
      002EED E5 08            [12] 9218 	mov	a,_bp
      002EEF 24 F2            [12] 9219 	add	a,#0xf2
      002EF1 F8               [12] 9220 	mov	r0,a
      002EF2 E6               [12] 9221 	mov	a,@r0
      002EF3 C0 E0            [24] 9222 	push	acc
      002EF5 08               [12] 9223 	inc	r0
      002EF6 E6               [12] 9224 	mov	a,@r0
      002EF7 C0 E0            [24] 9225 	push	acc
      002EF9 08               [12] 9226 	inc	r0
      002EFA E6               [12] 9227 	mov	a,@r0
      002EFB C0 E0            [24] 9228 	push	acc
      002EFD 08               [12] 9229 	inc	r0
      002EFE E6               [12] 9230 	mov	a,@r0
      002EFF C0 E0            [24] 9231 	push	acc
      002F01 E5 08            [12] 9232 	mov	a,_bp
      002F03 24 F6            [12] 9233 	add	a,#0xf6
      002F05 F8               [12] 9234 	mov	r0,a
      002F06 E6               [12] 9235 	mov	a,@r0
      002F07 C0 E0            [24] 9236 	push	acc
      002F09 08               [12] 9237 	inc	r0
      002F0A E6               [12] 9238 	mov	a,@r0
      002F0B C0 E0            [24] 9239 	push	acc
      002F0D 08               [12] 9240 	inc	r0
      002F0E E6               [12] 9241 	mov	a,@r0
      002F0F C0 E0            [24] 9242 	push	acc
      002F11 08               [12] 9243 	inc	r0
      002F12 E6               [12] 9244 	mov	a,@r0
      002F13 C0 E0            [24] 9245 	push	acc
      002F15 E5 08            [12] 9246 	mov	a,_bp
      002F17 24 FA            [12] 9247 	add	a,#0xfa
      002F19 F8               [12] 9248 	mov	r0,a
      002F1A E6               [12] 9249 	mov	a,@r0
      002F1B C0 E0            [24] 9250 	push	acc
      002F1D 08               [12] 9251 	inc	r0
      002F1E E6               [12] 9252 	mov	a,@r0
      002F1F C0 E0            [24] 9253 	push	acc
      002F21 08               [12] 9254 	inc	r0
      002F22 E6               [12] 9255 	mov	a,@r0
      002F23 C0 E0            [24] 9256 	push	acc
      002F25 08               [12] 9257 	inc	r0
      002F26 E6               [12] 9258 	mov	a,@r0
      002F27 C0 E0            [24] 9259 	push	acc
      002F29 8D 82            [24] 9260 	mov	dpl, r5
      002F2B 8E 83            [24] 9261 	mov	dph, r6
      002F2D 8F F0            [24] 9262 	mov	b, r7
      002F2F 12 29 9B         [24] 9263 	lcall	_fuzzy_rules_defuzzify_mom
      002F32 A8 08            [24] 9264 	mov	r0,_bp
      002F34 08               [12] 9265 	inc	r0
      002F35 A6 82            [24] 9266 	mov	@r0, dpl
      002F37 08               [12] 9267 	inc	r0
      002F38 A6 83            [24] 9268 	mov	@r0, dph
      002F3A 08               [12] 9269 	inc	r0
      002F3B A6 F0            [24] 9270 	mov	@r0, b
      002F3D 08               [12] 9271 	inc	r0
      002F3E F6               [12] 9272 	mov	@r0,a
      002F3F E5 81            [12] 9273 	mov	a,sp
      002F41 24 F2            [12] 9274 	add	a,#0xf2
      002F43 F5 81            [12] 9275 	mov	sp,a
      002F45 A8 08            [24] 9276 	mov	r0,_bp
      002F47 08               [12] 9277 	inc	r0
      002F48 86 82            [24] 9278 	mov	dpl, @r0
      002F4A 08               [12] 9279 	inc	r0
      002F4B 86 83            [24] 9280 	mov	dph, @r0
      002F4D 08               [12] 9281 	inc	r0
      002F4E 86 F0            [24] 9282 	mov	b, @r0
      002F50 08               [12] 9283 	inc	r0
      002F51 E6               [12] 9284 	mov	a, @r0
      002F52 02 30 3D         [24] 9285 	ljmp	00114$
                           002E9E  9286 	C$fuzzy.h$2741$2_0$143 ==.
                                   9287 ;	../../fuzzy.h:2741: case FUZZY_DEFUZZ_SOM:
      002F55                       9288 00110$:
                           002E9E  9289 	C$fuzzy.h$2743$2_0$143 ==.
                                   9290 ;	../../fuzzy.h:2743: rules,
      002F55 E5 08            [12] 9291 	mov	a,_bp
      002F57 24 EF            [12] 9292 	add	a,#0xef
      002F59 F8               [12] 9293 	mov	r0,a
      002F5A E6               [12] 9294 	mov	a,@r0
      002F5B C0 E0            [24] 9295 	push	acc
      002F5D E5 08            [12] 9296 	mov	a,_bp
      002F5F 24 F0            [12] 9297 	add	a,#0xf0
      002F61 F8               [12] 9298 	mov	r0,a
      002F62 E6               [12] 9299 	mov	a,@r0
      002F63 C0 E0            [24] 9300 	push	acc
      002F65 E5 08            [12] 9301 	mov	a,_bp
      002F67 24 F2            [12] 9302 	add	a,#0xf2
      002F69 F8               [12] 9303 	mov	r0,a
      002F6A E6               [12] 9304 	mov	a,@r0
      002F6B C0 E0            [24] 9305 	push	acc
      002F6D 08               [12] 9306 	inc	r0
      002F6E E6               [12] 9307 	mov	a,@r0
      002F6F C0 E0            [24] 9308 	push	acc
      002F71 08               [12] 9309 	inc	r0
      002F72 E6               [12] 9310 	mov	a,@r0
      002F73 C0 E0            [24] 9311 	push	acc
      002F75 08               [12] 9312 	inc	r0
      002F76 E6               [12] 9313 	mov	a,@r0
      002F77 C0 E0            [24] 9314 	push	acc
      002F79 E5 08            [12] 9315 	mov	a,_bp
      002F7B 24 F6            [12] 9316 	add	a,#0xf6
      002F7D F8               [12] 9317 	mov	r0,a
      002F7E E6               [12] 9318 	mov	a,@r0
      002F7F C0 E0            [24] 9319 	push	acc
      002F81 08               [12] 9320 	inc	r0
      002F82 E6               [12] 9321 	mov	a,@r0
      002F83 C0 E0            [24] 9322 	push	acc
      002F85 08               [12] 9323 	inc	r0
      002F86 E6               [12] 9324 	mov	a,@r0
      002F87 C0 E0            [24] 9325 	push	acc
      002F89 08               [12] 9326 	inc	r0
      002F8A E6               [12] 9327 	mov	a,@r0
      002F8B C0 E0            [24] 9328 	push	acc
      002F8D E5 08            [12] 9329 	mov	a,_bp
      002F8F 24 FA            [12] 9330 	add	a,#0xfa
      002F91 F8               [12] 9331 	mov	r0,a
      002F92 E6               [12] 9332 	mov	a,@r0
      002F93 C0 E0            [24] 9333 	push	acc
      002F95 08               [12] 9334 	inc	r0
      002F96 E6               [12] 9335 	mov	a,@r0
      002F97 C0 E0            [24] 9336 	push	acc
      002F99 08               [12] 9337 	inc	r0
      002F9A E6               [12] 9338 	mov	a,@r0
      002F9B C0 E0            [24] 9339 	push	acc
      002F9D 08               [12] 9340 	inc	r0
      002F9E E6               [12] 9341 	mov	a,@r0
      002F9F C0 E0            [24] 9342 	push	acc
      002FA1 8D 82            [24] 9343 	mov	dpl, r5
      002FA3 8E 83            [24] 9344 	mov	dph, r6
      002FA5 8F F0            [24] 9345 	mov	b, r7
      002FA7 12 2A D2         [24] 9346 	lcall	_fuzzy_rules_defuzzify_som
      002FAA A8 08            [24] 9347 	mov	r0,_bp
      002FAC 08               [12] 9348 	inc	r0
      002FAD A6 82            [24] 9349 	mov	@r0, dpl
      002FAF 08               [12] 9350 	inc	r0
      002FB0 A6 83            [24] 9351 	mov	@r0, dph
      002FB2 08               [12] 9352 	inc	r0
      002FB3 A6 F0            [24] 9353 	mov	@r0, b
      002FB5 08               [12] 9354 	inc	r0
      002FB6 F6               [12] 9355 	mov	@r0,a
      002FB7 E5 81            [12] 9356 	mov	a,sp
      002FB9 24 F2            [12] 9357 	add	a,#0xf2
      002FBB F5 81            [12] 9358 	mov	sp,a
      002FBD A8 08            [24] 9359 	mov	r0,_bp
      002FBF 08               [12] 9360 	inc	r0
      002FC0 86 82            [24] 9361 	mov	dpl, @r0
      002FC2 08               [12] 9362 	inc	r0
      002FC3 86 83            [24] 9363 	mov	dph, @r0
      002FC5 08               [12] 9364 	inc	r0
      002FC6 86 F0            [24] 9365 	mov	b, @r0
      002FC8 08               [12] 9366 	inc	r0
      002FC9 E6               [12] 9367 	mov	a, @r0
                           002F13  9368 	C$fuzzy.h$2751$2_0$143 ==.
                                   9369 ;	../../fuzzy.h:2751: case FUZZY_DEFUZZ_LOM:
      002FCA 80 71            [24] 9370 	sjmp	00114$
      002FCC                       9371 00111$:
                           002F15  9372 	C$fuzzy.h$2753$2_0$143 ==.
                                   9373 ;	../../fuzzy.h:2753: rules,
      002FCC E5 08            [12] 9374 	mov	a,_bp
      002FCE 24 EF            [12] 9375 	add	a,#0xef
      002FD0 F8               [12] 9376 	mov	r0,a
      002FD1 E6               [12] 9377 	mov	a,@r0
      002FD2 C0 E0            [24] 9378 	push	acc
      002FD4 E5 08            [12] 9379 	mov	a,_bp
      002FD6 24 F0            [12] 9380 	add	a,#0xf0
      002FD8 F8               [12] 9381 	mov	r0,a
      002FD9 E6               [12] 9382 	mov	a,@r0
      002FDA C0 E0            [24] 9383 	push	acc
      002FDC E5 08            [12] 9384 	mov	a,_bp
      002FDE 24 F2            [12] 9385 	add	a,#0xf2
      002FE0 F8               [12] 9386 	mov	r0,a
      002FE1 E6               [12] 9387 	mov	a,@r0
      002FE2 C0 E0            [24] 9388 	push	acc
      002FE4 08               [12] 9389 	inc	r0
      002FE5 E6               [12] 9390 	mov	a,@r0
      002FE6 C0 E0            [24] 9391 	push	acc
      002FE8 08               [12] 9392 	inc	r0
      002FE9 E6               [12] 9393 	mov	a,@r0
      002FEA C0 E0            [24] 9394 	push	acc
      002FEC 08               [12] 9395 	inc	r0
      002FED E6               [12] 9396 	mov	a,@r0
      002FEE C0 E0            [24] 9397 	push	acc
      002FF0 E5 08            [12] 9398 	mov	a,_bp
      002FF2 24 F6            [12] 9399 	add	a,#0xf6
      002FF4 F8               [12] 9400 	mov	r0,a
      002FF5 E6               [12] 9401 	mov	a,@r0
      002FF6 C0 E0            [24] 9402 	push	acc
      002FF8 08               [12] 9403 	inc	r0
      002FF9 E6               [12] 9404 	mov	a,@r0
      002FFA C0 E0            [24] 9405 	push	acc
      002FFC 08               [12] 9406 	inc	r0
      002FFD E6               [12] 9407 	mov	a,@r0
      002FFE C0 E0            [24] 9408 	push	acc
      003000 08               [12] 9409 	inc	r0
      003001 E6               [12] 9410 	mov	a,@r0
      003002 C0 E0            [24] 9411 	push	acc
      003004 E5 08            [12] 9412 	mov	a,_bp
      003006 24 FA            [12] 9413 	add	a,#0xfa
      003008 F8               [12] 9414 	mov	r0,a
      003009 E6               [12] 9415 	mov	a,@r0
      00300A C0 E0            [24] 9416 	push	acc
      00300C 08               [12] 9417 	inc	r0
      00300D E6               [12] 9418 	mov	a,@r0
      00300E C0 E0            [24] 9419 	push	acc
      003010 08               [12] 9420 	inc	r0
      003011 E6               [12] 9421 	mov	a,@r0
      003012 C0 E0            [24] 9422 	push	acc
      003014 08               [12] 9423 	inc	r0
      003015 E6               [12] 9424 	mov	a,@r0
      003016 C0 E0            [24] 9425 	push	acc
      003018 8D 82            [24] 9426 	mov	dpl, r5
      00301A 8E 83            [24] 9427 	mov	dph, r6
      00301C 8F F0            [24] 9428 	mov	b, r7
      00301E 12 2B BB         [24] 9429 	lcall	_fuzzy_rules_defuzzify_lom
      003021 AC 82            [24] 9430 	mov	r4, dpl
      003023 AD 83            [24] 9431 	mov	r5, dph
      003025 AE F0            [24] 9432 	mov	r6, b
      003027 FF               [12] 9433 	mov	r7, a
      003028 E5 81            [12] 9434 	mov	a,sp
      00302A 24 F2            [12] 9435 	add	a,#0xf2
      00302C F5 81            [12] 9436 	mov	sp,a
      00302E 8C 82            [24] 9437 	mov	dpl, r4
      003030 8D 83            [24] 9438 	mov	dph, r5
      003032 8E F0            [24] 9439 	mov	b, r6
      003034 EF               [12] 9440 	mov	a, r7
                           002F7E  9441 	C$fuzzy.h$2761$2_0$143 ==.
                                   9442 ;	../../fuzzy.h:2761: default:
      003035 80 06            [24] 9443 	sjmp	00114$
      003037                       9444 00112$:
                           002F80  9445 	C$fuzzy.h$2762$2_0$143 ==.
                                   9446 ;	../../fuzzy.h:2762: return 0.0f;
      003037 90 00 00         [24] 9447 	mov	dptr,#0x0000
      00303A E4               [12] 9448 	clr	a
      00303B F5 F0            [12] 9449 	mov	b,a
                           002F86  9450 	C$fuzzy.h$2763$1_0$141 ==.
                                   9451 ;	../../fuzzy.h:2763: }
      00303D                       9452 00114$:
                           002F86  9453 	C$fuzzy.h$2764$1_0$141 ==.
                                   9454 ;	../../fuzzy.h:2764: }
      00303D 85 08 81         [24] 9455 	mov	sp,_bp
      003040 D0 08            [24] 9456 	pop	_bp
                           002F8B  9457 	C$fuzzy.h$2764$1_0$141 ==.
                           002F8B  9458 	XG$fuzzy_rules_defuzzify_method$0$0 ==.
      003042 22               [24] 9459 	ret
                                   9460 ;------------------------------------------------------------
                                   9461 ;Allocation info for local variables in function 'fuzzy_rules_defuzzify'
                                   9462 ;------------------------------------------------------------
                                   9463 ;lower         Allocated to stack - _bp -6 +4 
                                   9464 ;upper         Allocated to stack - _bp -10 +4 
                                   9465 ;step          Allocated to stack - _bp -14 +4 
                                   9466 ;method        Allocated to stack - _bp -15 +1 
                                   9467 ;rules         Allocated to registers r5 r6 r7 
                                   9468 ;------------------------------------------------------------
                           002F8C  9469 	G$fuzzy_rules_defuzzify$0$0 ==.
                           002F8C  9470 	C$fuzzy.h$2771$1_0$145 ==.
                                   9471 ;	../../fuzzy.h:2771: float fuzzy_rules_defuzzify(
                                   9472 ;	-----------------------------------------
                                   9473 ;	 function fuzzy_rules_defuzzify
                                   9474 ;	-----------------------------------------
      003043                       9475 _fuzzy_rules_defuzzify:
      003043 C0 08            [24] 9476 	push	_bp
      003045 85 81 08         [24] 9477 	mov	_bp,sp
      003048 AD 82            [24] 9478 	mov	r5, dpl
      00304A AE 83            [24] 9479 	mov	r6, dph
      00304C AF F0            [24] 9480 	mov	r7, b
                           002F97  9481 	C$fuzzy.h$2780$1_0$145 ==.
                                   9482 ;	../../fuzzy.h:2780: rules,
      00304E E4               [12] 9483 	clr	a
      00304F C0 E0            [24] 9484 	push	acc
      003051 C0 E0            [24] 9485 	push	acc
      003053 E5 08            [12] 9486 	mov	a,_bp
      003055 24 F1            [12] 9487 	add	a,#0xf1
      003057 F8               [12] 9488 	mov	r0,a
      003058 E6               [12] 9489 	mov	a,@r0
      003059 C0 E0            [24] 9490 	push	acc
      00305B E5 08            [12] 9491 	mov	a,_bp
      00305D 24 F2            [12] 9492 	add	a,#0xf2
      00305F F8               [12] 9493 	mov	r0,a
      003060 E6               [12] 9494 	mov	a,@r0
      003061 C0 E0            [24] 9495 	push	acc
      003063 08               [12] 9496 	inc	r0
      003064 E6               [12] 9497 	mov	a,@r0
      003065 C0 E0            [24] 9498 	push	acc
      003067 08               [12] 9499 	inc	r0
      003068 E6               [12] 9500 	mov	a,@r0
      003069 C0 E0            [24] 9501 	push	acc
      00306B 08               [12] 9502 	inc	r0
      00306C E6               [12] 9503 	mov	a,@r0
      00306D C0 E0            [24] 9504 	push	acc
      00306F E5 08            [12] 9505 	mov	a,_bp
      003071 24 F6            [12] 9506 	add	a,#0xf6
      003073 F8               [12] 9507 	mov	r0,a
      003074 E6               [12] 9508 	mov	a,@r0
      003075 C0 E0            [24] 9509 	push	acc
      003077 08               [12] 9510 	inc	r0
      003078 E6               [12] 9511 	mov	a,@r0
      003079 C0 E0            [24] 9512 	push	acc
      00307B 08               [12] 9513 	inc	r0
      00307C E6               [12] 9514 	mov	a,@r0
      00307D C0 E0            [24] 9515 	push	acc
      00307F 08               [12] 9516 	inc	r0
      003080 E6               [12] 9517 	mov	a,@r0
      003081 C0 E0            [24] 9518 	push	acc
      003083 E5 08            [12] 9519 	mov	a,_bp
      003085 24 FA            [12] 9520 	add	a,#0xfa
      003087 F8               [12] 9521 	mov	r0,a
      003088 E6               [12] 9522 	mov	a,@r0
      003089 C0 E0            [24] 9523 	push	acc
      00308B 08               [12] 9524 	inc	r0
      00308C E6               [12] 9525 	mov	a,@r0
      00308D C0 E0            [24] 9526 	push	acc
      00308F 08               [12] 9527 	inc	r0
      003090 E6               [12] 9528 	mov	a,@r0
      003091 C0 E0            [24] 9529 	push	acc
      003093 08               [12] 9530 	inc	r0
      003094 E6               [12] 9531 	mov	a,@r0
      003095 C0 E0            [24] 9532 	push	acc
      003097 8D 82            [24] 9533 	mov	dpl, r5
      003099 8E 83            [24] 9534 	mov	dph, r6
      00309B 8F F0            [24] 9535 	mov	b, r7
      00309D 12 2C A4         [24] 9536 	lcall	_fuzzy_rules_defuzzify_method
      0030A0 AC 82            [24] 9537 	mov	r4, dpl
      0030A2 AD 83            [24] 9538 	mov	r5, dph
      0030A4 AE F0            [24] 9539 	mov	r6, b
      0030A6 FF               [12] 9540 	mov	r7, a
      0030A7 E5 81            [12] 9541 	mov	a,sp
      0030A9 24 F1            [12] 9542 	add	a,#0xf1
      0030AB F5 81            [12] 9543 	mov	sp,a
      0030AD 8C 82            [24] 9544 	mov	dpl, r4
      0030AF 8D 83            [24] 9545 	mov	dph, r5
      0030B1 8E F0            [24] 9546 	mov	b, r6
      0030B3 EF               [12] 9547 	mov	a, r7
                           002FFD  9548 	C$fuzzy.h$2788$1_0$145 ==.
                                   9549 ;	../../fuzzy.h:2788: }
      0030B4 D0 08            [24] 9550 	pop	_bp
                           002FFF  9551 	C$fuzzy.h$2788$1_0$145 ==.
                           002FFF  9552 	XG$fuzzy_rules_defuzzify$0$0 ==.
      0030B6 22               [24] 9553 	ret
                                   9554 ;------------------------------------------------------------
                                   9555 ;Allocation info for local variables in function 'fuzzy_rules_cog'
                                   9556 ;------------------------------------------------------------
                                   9557 ;lower         Allocated to stack - _bp -6 +4 
                                   9558 ;upper         Allocated to stack - _bp -10 +4 
                                   9559 ;step          Allocated to stack - _bp -14 +4 
                                   9560 ;rules         Allocated to registers r5 r6 r7 
                                   9561 ;------------------------------------------------------------
                           003000  9562 	G$fuzzy_rules_cog$0$0 ==.
                           003000  9563 	C$fuzzy.h$2794$1_0$147 ==.
                                   9564 ;	../../fuzzy.h:2794: float fuzzy_rules_cog(
                                   9565 ;	-----------------------------------------
                                   9566 ;	 function fuzzy_rules_cog
                                   9567 ;	-----------------------------------------
      0030B7                       9568 _fuzzy_rules_cog:
      0030B7 C0 08            [24] 9569 	push	_bp
      0030B9 85 81 08         [24] 9570 	mov	_bp,sp
      0030BC AD 82            [24] 9571 	mov	r5, dpl
      0030BE AE 83            [24] 9572 	mov	r6, dph
      0030C0 AF F0            [24] 9573 	mov	r7, b
                           00300B  9574 	C$fuzzy.h$2802$1_0$147 ==.
                                   9575 ;	../../fuzzy.h:2802: rules,
      0030C2 E4               [12] 9576 	clr	a
      0030C3 C0 E0            [24] 9577 	push	acc
      0030C5 C0 E0            [24] 9578 	push	acc
      0030C7 E5 08            [12] 9579 	mov	a,_bp
      0030C9 24 F2            [12] 9580 	add	a,#0xf2
      0030CB F8               [12] 9581 	mov	r0,a
      0030CC E6               [12] 9582 	mov	a,@r0
      0030CD C0 E0            [24] 9583 	push	acc
      0030CF 08               [12] 9584 	inc	r0
      0030D0 E6               [12] 9585 	mov	a,@r0
      0030D1 C0 E0            [24] 9586 	push	acc
      0030D3 08               [12] 9587 	inc	r0
      0030D4 E6               [12] 9588 	mov	a,@r0
      0030D5 C0 E0            [24] 9589 	push	acc
      0030D7 08               [12] 9590 	inc	r0
      0030D8 E6               [12] 9591 	mov	a,@r0
      0030D9 C0 E0            [24] 9592 	push	acc
      0030DB E5 08            [12] 9593 	mov	a,_bp
      0030DD 24 F6            [12] 9594 	add	a,#0xf6
      0030DF F8               [12] 9595 	mov	r0,a
      0030E0 E6               [12] 9596 	mov	a,@r0
      0030E1 C0 E0            [24] 9597 	push	acc
      0030E3 08               [12] 9598 	inc	r0
      0030E4 E6               [12] 9599 	mov	a,@r0
      0030E5 C0 E0            [24] 9600 	push	acc
      0030E7 08               [12] 9601 	inc	r0
      0030E8 E6               [12] 9602 	mov	a,@r0
      0030E9 C0 E0            [24] 9603 	push	acc
      0030EB 08               [12] 9604 	inc	r0
      0030EC E6               [12] 9605 	mov	a,@r0
      0030ED C0 E0            [24] 9606 	push	acc
      0030EF E5 08            [12] 9607 	mov	a,_bp
      0030F1 24 FA            [12] 9608 	add	a,#0xfa
      0030F3 F8               [12] 9609 	mov	r0,a
      0030F4 E6               [12] 9610 	mov	a,@r0
      0030F5 C0 E0            [24] 9611 	push	acc
      0030F7 08               [12] 9612 	inc	r0
      0030F8 E6               [12] 9613 	mov	a,@r0
      0030F9 C0 E0            [24] 9614 	push	acc
      0030FB 08               [12] 9615 	inc	r0
      0030FC E6               [12] 9616 	mov	a,@r0
      0030FD C0 E0            [24] 9617 	push	acc
      0030FF 08               [12] 9618 	inc	r0
      003100 E6               [12] 9619 	mov	a,@r0
      003101 C0 E0            [24] 9620 	push	acc
      003103 8D 82            [24] 9621 	mov	dpl, r5
      003105 8E 83            [24] 9622 	mov	dph, r6
      003107 8F F0            [24] 9623 	mov	b, r7
      003109 12 21 3F         [24] 9624 	lcall	_fuzzy_rules_defuzzify_cog
      00310C AC 82            [24] 9625 	mov	r4, dpl
      00310E AD 83            [24] 9626 	mov	r5, dph
      003110 AE F0            [24] 9627 	mov	r6, b
      003112 FF               [12] 9628 	mov	r7, a
      003113 E5 81            [12] 9629 	mov	a,sp
      003115 24 F2            [12] 9630 	add	a,#0xf2
      003117 F5 81            [12] 9631 	mov	sp,a
      003119 8C 82            [24] 9632 	mov	dpl, r4
      00311B 8D 83            [24] 9633 	mov	dph, r5
      00311D 8E F0            [24] 9634 	mov	b, r6
      00311F EF               [12] 9635 	mov	a, r7
                           003069  9636 	C$fuzzy.h$2809$1_0$147 ==.
                                   9637 ;	../../fuzzy.h:2809: }
      003120 D0 08            [24] 9638 	pop	_bp
                           00306B  9639 	C$fuzzy.h$2809$1_0$147 ==.
                           00306B  9640 	XG$fuzzy_rules_cog$0$0 ==.
      003122 22               [24] 9641 	ret
                                   9642 ;------------------------------------------------------------
                                   9643 ;Allocation info for local variables in function 'temperature_low'
                                   9644 ;------------------------------------------------------------
                                   9645 ;value         Allocated to registers r4 r5 r6 r7 
                                   9646 ;------------------------------------------------------------
                           00306C  9647 	Fcontroller_8051$temperature_low$0$0 ==.
                           00306C  9648 	C$controller_8051.c$59$1_0$149 ==.
                                   9649 ;	../../controller_8051.c:59: static float temperature_low(
                                   9650 ;	-----------------------------------------
                                   9651 ;	 function temperature_low
                                   9652 ;	-----------------------------------------
      003123                       9653 _temperature_low:
      003123 AC 82            [24] 9654 	mov	r4,dpl
      003125 AD 83            [24] 9655 	mov	r5,dph
      003127 AE F0            [24] 9656 	mov	r6,b
      003129 FF               [12] 9657 	mov	r7,a
                           003073  9658 	C$controller_8051.c$68$1_0$149 ==.
                                   9659 ;	../../controller_8051.c:68: hedges.none
      00312A 90 38 B0         [24] 9660 	mov	dptr,#_hedges
      00312D E4               [12] 9661 	clr	a
      00312E 93               [24] 9662 	movc	a,@a+dptr
      00312F FB               [12] 9663 	mov	r3,a
                           003079  9664 	C$controller_8051.c$64$1_0$149 ==.
                                   9665 ;	../../controller_8051.c:64: 20.0f,
      003130 C0 03            [24] 9666 	push	ar3
      003132 E4               [12] 9667 	clr	a
      003133 C0 E0            [24] 9668 	push	acc
      003135 C0 04            [24] 9669 	push	ar4
      003137 C0 05            [24] 9670 	push	ar5
      003139 C0 06            [24] 9671 	push	ar6
      00313B C0 07            [24] 9672 	push	ar7
      00313D C0 E0            [24] 9673 	push	acc
      00313F C0 E0            [24] 9674 	push	acc
      003141 74 20            [12] 9675 	mov	a,#0x20
      003143 C0 E0            [24] 9676 	push	acc
      003145 74 42            [12] 9677 	mov	a,#0x42
      003147 C0 E0            [24] 9678 	push	acc
      003149 90 00 00         [24] 9679 	mov	dptr,#0x0000
      00314C 75 F0 A0         [24] 9680 	mov	b, #0xa0
      00314F 14               [12] 9681 	dec	a
      003150 12 0A EC         [24] 9682 	lcall	_fuzzy_ramp
      003153 AC 82            [24] 9683 	mov	r4, dpl
      003155 AD 83            [24] 9684 	mov	r5, dph
      003157 AE F0            [24] 9685 	mov	r6, b
      003159 FF               [12] 9686 	mov	r7, a
      00315A E5 81            [12] 9687 	mov	a,sp
      00315C 24 F6            [12] 9688 	add	a,#0xf6
      00315E F5 81            [12] 9689 	mov	sp,a
      003160 8C 82            [24] 9690 	mov	dpl, r4
      003162 8D 83            [24] 9691 	mov	dph, r5
      003164 8E F0            [24] 9692 	mov	b, r6
      003166 EF               [12] 9693 	mov	a, r7
                           0030B0  9694 	C$controller_8051.c$70$1_0$149 ==.
                                   9695 ;	../../controller_8051.c:70: }
                           0030B0  9696 	C$controller_8051.c$70$1_0$149 ==.
                           0030B0  9697 	XFcontroller_8051$temperature_low$0$0 ==.
      003167 22               [24] 9698 	ret
                                   9699 ;------------------------------------------------------------
                                   9700 ;Allocation info for local variables in function 'temperature_high'
                                   9701 ;------------------------------------------------------------
                                   9702 ;value         Allocated to registers r4 r5 r6 r7 
                                   9703 ;------------------------------------------------------------
                           0030B1  9704 	Fcontroller_8051$temperature_high$0$0 ==.
                           0030B1  9705 	C$controller_8051.c$73$1_0$151 ==.
                                   9706 ;	../../controller_8051.c:73: static float temperature_high(
                                   9707 ;	-----------------------------------------
                                   9708 ;	 function temperature_high
                                   9709 ;	-----------------------------------------
      003168                       9710 _temperature_high:
      003168 AC 82            [24] 9711 	mov	r4,dpl
      00316A AD 83            [24] 9712 	mov	r5,dph
      00316C AE F0            [24] 9713 	mov	r6,b
      00316E FF               [12] 9714 	mov	r7,a
                           0030B8  9715 	C$controller_8051.c$82$1_0$151 ==.
                                   9716 ;	../../controller_8051.c:82: hedges.none
      00316F 90 38 B0         [24] 9717 	mov	dptr,#_hedges
      003172 E4               [12] 9718 	clr	a
      003173 93               [24] 9719 	movc	a,@a+dptr
      003174 FB               [12] 9720 	mov	r3,a
                           0030BE  9721 	C$controller_8051.c$78$1_0$151 ==.
                                   9722 ;	../../controller_8051.c:78: 30.0f,
      003175 C0 03            [24] 9723 	push	ar3
      003177 74 01            [12] 9724 	mov	a,#0x01
      003179 C0 E0            [24] 9725 	push	acc
      00317B C0 04            [24] 9726 	push	ar4
      00317D C0 05            [24] 9727 	push	ar5
      00317F C0 06            [24] 9728 	push	ar6
      003181 C0 07            [24] 9729 	push	ar7
      003183 E4               [12] 9730 	clr	a
      003184 C0 E0            [24] 9731 	push	acc
      003186 C0 E0            [24] 9732 	push	acc
      003188 74 70            [12] 9733 	mov	a,#0x70
      00318A C0 E0            [24] 9734 	push	acc
      00318C 74 42            [12] 9735 	mov	a,#0x42
      00318E C0 E0            [24] 9736 	push	acc
      003190 90 00 00         [24] 9737 	mov	dptr,#0x0000
      003193 75 F0 F0         [24] 9738 	mov	b, #0xf0
      003196 14               [12] 9739 	dec	a
      003197 12 0A EC         [24] 9740 	lcall	_fuzzy_ramp
      00319A AC 82            [24] 9741 	mov	r4, dpl
      00319C AD 83            [24] 9742 	mov	r5, dph
      00319E AE F0            [24] 9743 	mov	r6, b
      0031A0 FF               [12] 9744 	mov	r7, a
      0031A1 E5 81            [12] 9745 	mov	a,sp
      0031A3 24 F6            [12] 9746 	add	a,#0xf6
      0031A5 F5 81            [12] 9747 	mov	sp,a
      0031A7 8C 82            [24] 9748 	mov	dpl, r4
      0031A9 8D 83            [24] 9749 	mov	dph, r5
      0031AB 8E F0            [24] 9750 	mov	b, r6
      0031AD EF               [12] 9751 	mov	a, r7
                           0030F7  9752 	C$controller_8051.c$84$1_0$151 ==.
                                   9753 ;	../../controller_8051.c:84: }
                           0030F7  9754 	C$controller_8051.c$84$1_0$151 ==.
                           0030F7  9755 	XFcontroller_8051$temperature_high$0$0 ==.
      0031AE 22               [24] 9756 	ret
                                   9757 ;------------------------------------------------------------
                                   9758 ;Allocation info for local variables in function 'fan_slow'
                                   9759 ;------------------------------------------------------------
                                   9760 ;value         Allocated to registers r4 r5 r6 r7 
                                   9761 ;------------------------------------------------------------
                           0030F8  9762 	Fcontroller_8051$fan_slow$0$0 ==.
                           0030F8  9763 	C$controller_8051.c$91$1_0$153 ==.
                                   9764 ;	../../controller_8051.c:91: static float fan_slow(
                                   9765 ;	-----------------------------------------
                                   9766 ;	 function fan_slow
                                   9767 ;	-----------------------------------------
      0031AF                       9768 _fan_slow:
      0031AF AC 82            [24] 9769 	mov	r4,dpl
      0031B1 AD 83            [24] 9770 	mov	r5,dph
      0031B3 AE F0            [24] 9771 	mov	r6,b
      0031B5 FF               [12] 9772 	mov	r7,a
                           0030FF  9773 	C$controller_8051.c$100$1_0$153 ==.
                                   9774 ;	../../controller_8051.c:100: hedges.none
      0031B6 90 38 B0         [24] 9775 	mov	dptr,#_hedges
      0031B9 E4               [12] 9776 	clr	a
      0031BA 93               [24] 9777 	movc	a,@a+dptr
      0031BB FB               [12] 9778 	mov	r3,a
                           003105  9779 	C$controller_8051.c$96$1_0$153 ==.
                                   9780 ;	../../controller_8051.c:96: 20.0f,
      0031BC C0 03            [24] 9781 	push	ar3
      0031BE E4               [12] 9782 	clr	a
      0031BF C0 E0            [24] 9783 	push	acc
      0031C1 C0 04            [24] 9784 	push	ar4
      0031C3 C0 05            [24] 9785 	push	ar5
      0031C5 C0 06            [24] 9786 	push	ar6
      0031C7 C0 07            [24] 9787 	push	ar7
      0031C9 C0 E0            [24] 9788 	push	acc
      0031CB C0 E0            [24] 9789 	push	acc
      0031CD 74 48            [12] 9790 	mov	a,#0x48
      0031CF C0 E0            [24] 9791 	push	acc
      0031D1 74 42            [12] 9792 	mov	a,#0x42
      0031D3 C0 E0            [24] 9793 	push	acc
      0031D5 90 00 00         [24] 9794 	mov	dptr,#0x0000
      0031D8 75 F0 A0         [24] 9795 	mov	b, #0xa0
      0031DB 14               [12] 9796 	dec	a
      0031DC 12 0A EC         [24] 9797 	lcall	_fuzzy_ramp
      0031DF AC 82            [24] 9798 	mov	r4, dpl
      0031E1 AD 83            [24] 9799 	mov	r5, dph
      0031E3 AE F0            [24] 9800 	mov	r6, b
      0031E5 FF               [12] 9801 	mov	r7, a
      0031E6 E5 81            [12] 9802 	mov	a,sp
      0031E8 24 F6            [12] 9803 	add	a,#0xf6
      0031EA F5 81            [12] 9804 	mov	sp,a
      0031EC 8C 82            [24] 9805 	mov	dpl, r4
      0031EE 8D 83            [24] 9806 	mov	dph, r5
      0031F0 8E F0            [24] 9807 	mov	b, r6
      0031F2 EF               [12] 9808 	mov	a, r7
                           00313C  9809 	C$controller_8051.c$102$1_0$153 ==.
                                   9810 ;	../../controller_8051.c:102: }
                           00313C  9811 	C$controller_8051.c$102$1_0$153 ==.
                           00313C  9812 	XFcontroller_8051$fan_slow$0$0 ==.
      0031F3 22               [24] 9813 	ret
                                   9814 ;------------------------------------------------------------
                                   9815 ;Allocation info for local variables in function 'fan_fast'
                                   9816 ;------------------------------------------------------------
                                   9817 ;value         Allocated to registers r4 r5 r6 r7 
                                   9818 ;------------------------------------------------------------
                           00313D  9819 	Fcontroller_8051$fan_fast$0$0 ==.
                           00313D  9820 	C$controller_8051.c$105$1_0$155 ==.
                                   9821 ;	../../controller_8051.c:105: static float fan_fast(
                                   9822 ;	-----------------------------------------
                                   9823 ;	 function fan_fast
                                   9824 ;	-----------------------------------------
      0031F4                       9825 _fan_fast:
      0031F4 AC 82            [24] 9826 	mov	r4,dpl
      0031F6 AD 83            [24] 9827 	mov	r5,dph
      0031F8 AE F0            [24] 9828 	mov	r6,b
      0031FA FF               [12] 9829 	mov	r7,a
                           003144  9830 	C$controller_8051.c$114$1_0$155 ==.
                                   9831 ;	../../controller_8051.c:114: hedges.none
      0031FB 90 38 B0         [24] 9832 	mov	dptr,#_hedges
      0031FE E4               [12] 9833 	clr	a
      0031FF 93               [24] 9834 	movc	a,@a+dptr
      003200 FB               [12] 9835 	mov	r3,a
                           00314A  9836 	C$controller_8051.c$110$1_0$155 ==.
                                   9837 ;	../../controller_8051.c:110: 40.0f,
      003201 C0 03            [24] 9838 	push	ar3
      003203 74 01            [12] 9839 	mov	a,#0x01
      003205 C0 E0            [24] 9840 	push	acc
      003207 C0 04            [24] 9841 	push	ar4
      003209 C0 05            [24] 9842 	push	ar5
      00320B C0 06            [24] 9843 	push	ar6
      00320D C0 07            [24] 9844 	push	ar7
      00320F E4               [12] 9845 	clr	a
      003210 C0 E0            [24] 9846 	push	acc
      003212 C0 E0            [24] 9847 	push	acc
      003214 74 A0            [12] 9848 	mov	a,#0xa0
      003216 C0 E0            [24] 9849 	push	acc
      003218 74 42            [12] 9850 	mov	a,#0x42
      00321A C0 E0            [24] 9851 	push	acc
      00321C 90 00 00         [24] 9852 	mov	dptr,#0x0000
      00321F 75 F0 20         [24] 9853 	mov	b, #0x20
      003222 12 0A EC         [24] 9854 	lcall	_fuzzy_ramp
      003225 AC 82            [24] 9855 	mov	r4, dpl
      003227 AD 83            [24] 9856 	mov	r5, dph
      003229 AE F0            [24] 9857 	mov	r6, b
      00322B FF               [12] 9858 	mov	r7, a
      00322C E5 81            [12] 9859 	mov	a,sp
      00322E 24 F6            [12] 9860 	add	a,#0xf6
      003230 F5 81            [12] 9861 	mov	sp,a
      003232 8C 82            [24] 9862 	mov	dpl, r4
      003234 8D 83            [24] 9863 	mov	dph, r5
      003236 8E F0            [24] 9864 	mov	b, r6
      003238 EF               [12] 9865 	mov	a, r7
                           003182  9866 	C$controller_8051.c$116$1_0$155 ==.
                                   9867 ;	../../controller_8051.c:116: }
                           003182  9868 	C$controller_8051.c$116$1_0$155 ==.
                           003182  9869 	XFcontroller_8051$fan_fast$0$0 ==.
      003239 22               [24] 9870 	ret
                                   9871 ;------------------------------------------------------------
                                   9872 ;Allocation info for local variables in function 'calculate_fan_speed'
                                   9873 ;------------------------------------------------------------
                                   9874 ;temperature   Allocated to stack - _bp +1 +4 
                                   9875 ;rules         Allocated to stack - _bp +9 +146 
                                   9876 ;result        Allocated to registers r4 r5 r6 r7 
                                   9877 ;sloc0         Allocated to stack - _bp +5 +4 
                                   9878 ;------------------------------------------------------------
                           003183  9879 	Fcontroller_8051$calculate_fan_speed$0$0 ==.
                           003183  9880 	C$controller_8051.c$123$1_0$157 ==.
                                   9881 ;	../../controller_8051.c:123: static float calculate_fan_speed(float temperature)
                                   9882 ;	-----------------------------------------
                                   9883 ;	 function calculate_fan_speed
                                   9884 ;	-----------------------------------------
      00323A                       9885 _calculate_fan_speed:
      00323A C0 08            [24] 9886 	push	_bp
      00323C 85 81 08         [24] 9887 	mov	_bp,sp
      00323F C0 82            [24] 9888 	push	dpl
      003241 C0 83            [24] 9889 	push	dph
      003243 C0 F0            [24] 9890 	push	b
      003245 C0 E0            [24] 9891 	push	acc
      003247 E5 81            [12] 9892 	mov	a,sp
      003249 24 96            [12] 9893 	add	a,#0x96
      00324B F5 81            [12] 9894 	mov	sp,a
                           003196  9895 	C$controller_8051.c$129$1_0$157 ==.
                                   9896 ;	../../controller_8051.c:129: rules.count = 0;
      00324D E5 08            [12] 9897 	mov	a,_bp
      00324F 24 09            [12] 9898 	add	a,#0x09
      003251 FB               [12] 9899 	mov	r3,a
      003252 24 90            [12] 9900 	add	a,#0x90
      003254 F9               [12] 9901 	mov	r1,a
      003255 77 00            [12] 9902 	mov	@r1,#0x00
      003257 09               [12] 9903 	inc	r1
      003258 77 00            [12] 9904 	mov	@r1,#0x00
      00325A 19               [12] 9905 	dec	r1
                           0031A4  9906 	C$controller_8051.c$132$1_0$157 ==.
                                   9907 ;	../../controller_8051.c:132: if (!FUZZY_RULE_ADD(&rules, temperature_low(temperature), fan_slow)) return 0.0f;
      00325B A8 08            [24] 9908 	mov	r0,_bp
      00325D 08               [12] 9909 	inc	r0
      00325E 86 82            [24] 9910 	mov	dpl, @r0
      003260 08               [12] 9911 	inc	r0
      003261 86 83            [24] 9912 	mov	dph, @r0
      003263 08               [12] 9913 	inc	r0
      003264 86 F0            [24] 9914 	mov	b, @r0
      003266 08               [12] 9915 	inc	r0
      003267 E6               [12] 9916 	mov	a, @r0
      003268 C0 03            [24] 9917 	push	ar3
      00326A C0 01            [24] 9918 	push	ar1
      00326C 12 31 23         [24] 9919 	lcall	_temperature_low
      00326F C8               [12] 9920 	xch	a,r0
      003270 E5 08            [12] 9921 	mov	a,_bp
      003272 24 05            [12] 9922 	add	a,#0x05
      003274 C8               [12] 9923 	xch	a,r0
      003275 A6 82            [24] 9924 	mov	@r0, dpl
      003277 08               [12] 9925 	inc	r0
      003278 A6 83            [24] 9926 	mov	@r0, dph
      00327A 08               [12] 9927 	inc	r0
      00327B A6 F0            [24] 9928 	mov	@r0, b
      00327D 08               [12] 9929 	inc	r0
      00327E F6               [12] 9930 	mov	@r0,a
      00327F D0 01            [24] 9931 	pop	ar1
      003281 D0 03            [24] 9932 	pop	ar3
      003283 8B 04            [24] 9933 	mov	ar4,r3
      003285 7E 00            [12] 9934 	mov	r6,#0x00
      003287 7F 40            [12] 9935 	mov	r7,#0x40
      003289 C0 03            [24] 9936 	push	ar3
      00328B C0 01            [24] 9937 	push	ar1
      00328D 74 AF            [12] 9938 	mov	a,#_fan_slow
      00328F C0 E0            [24] 9939 	push	acc
      003291 74 31            [12] 9940 	mov	a,#(_fan_slow >> 8)
      003293 C0 E0            [24] 9941 	push	acc
      003295 E5 08            [12] 9942 	mov	a,_bp
      003297 24 05            [12] 9943 	add	a,#0x05
      003299 F8               [12] 9944 	mov	r0,a
      00329A E6               [12] 9945 	mov	a,@r0
      00329B C0 E0            [24] 9946 	push	acc
      00329D 08               [12] 9947 	inc	r0
      00329E E6               [12] 9948 	mov	a,@r0
      00329F C0 E0            [24] 9949 	push	acc
      0032A1 08               [12] 9950 	inc	r0
      0032A2 E6               [12] 9951 	mov	a,@r0
      0032A3 C0 E0            [24] 9952 	push	acc
      0032A5 08               [12] 9953 	inc	r0
      0032A6 E6               [12] 9954 	mov	a,@r0
      0032A7 C0 E0            [24] 9955 	push	acc
      0032A9 74 B3            [12] 9956 	mov	a,#___str_0
      0032AB C0 E0            [24] 9957 	push	acc
      0032AD 74 38            [12] 9958 	mov	a,#(___str_0 >> 8)
      0032AF C0 E0            [24] 9959 	push	acc
      0032B1 74 80            [12] 9960 	mov	a,#0x80
      0032B3 C0 E0            [24] 9961 	push	acc
      0032B5 8C 82            [24] 9962 	mov	dpl, r4
      0032B7 8E 83            [24] 9963 	mov	dph, r6
      0032B9 8F F0            [24] 9964 	mov	b, r7
      0032BB 12 17 6D         [24] 9965 	lcall	_fuzzy_rules_add
      0032BE AF 82            [24] 9966 	mov	r7, dpl
      0032C0 E5 81            [12] 9967 	mov	a,sp
      0032C2 24 F7            [12] 9968 	add	a,#0xf7
      0032C4 F5 81            [12] 9969 	mov	sp,a
      0032C6 D0 01            [24] 9970 	pop	ar1
      0032C8 D0 03            [24] 9971 	pop	ar3
      0032CA EF               [12] 9972 	mov	a,r7
      0032CB 70 09            [24] 9973 	jnz	00102$
      0032CD 90 00 00         [24] 9974 	mov	dptr,#0x0000
      0032D0 E4               [12] 9975 	clr	a
      0032D1 F5 F0            [12] 9976 	mov	b,a
      0032D3 02 33 A5         [24] 9977 	ljmp	00105$
      0032D6                       9978 00102$:
                           00321F  9979 	C$controller_8051.c$134$1_0$157 ==.
                                   9980 ;	../../controller_8051.c:134: if (!FUZZY_RULE_ADD(&rules, temperature_high(temperature), fan_fast)) return 0.0f;
      0032D6 C0 01            [24] 9981 	push	ar1
      0032D8 A8 08            [24] 9982 	mov	r0,_bp
      0032DA 08               [12] 9983 	inc	r0
      0032DB 86 82            [24] 9984 	mov	dpl, @r0
      0032DD 08               [12] 9985 	inc	r0
      0032DE 86 83            [24] 9986 	mov	dph, @r0
      0032E0 08               [12] 9987 	inc	r0
      0032E1 86 F0            [24] 9988 	mov	b, @r0
      0032E3 08               [12] 9989 	inc	r0
      0032E4 E6               [12] 9990 	mov	a, @r0
      0032E5 C0 03            [24] 9991 	push	ar3
      0032E7 C0 01            [24] 9992 	push	ar1
      0032E9 12 31 68         [24] 9993 	lcall	_temperature_high
      0032EC C8               [12] 9994 	xch	a,r0
      0032ED E5 08            [12] 9995 	mov	a,_bp
      0032EF 24 05            [12] 9996 	add	a,#0x05
      0032F1 C8               [12] 9997 	xch	a,r0
      0032F2 A6 82            [24] 9998 	mov	@r0, dpl
      0032F4 08               [12] 9999 	inc	r0
      0032F5 A6 83            [24]10000 	mov	@r0, dph
      0032F7 08               [12]10001 	inc	r0
      0032F8 A6 F0            [24]10002 	mov	@r0, b
      0032FA 08               [12]10003 	inc	r0
      0032FB F6               [12]10004 	mov	@r0,a
      0032FC D0 01            [24]10005 	pop	ar1
      0032FE D0 03            [24]10006 	pop	ar3
      003300 8B 02            [24]10007 	mov	ar2,r3
      003302 7E 00            [12]10008 	mov	r6,#0x00
      003304 7F 40            [12]10009 	mov	r7,#0x40
      003306 C0 03            [24]10010 	push	ar3
      003308 C0 01            [24]10011 	push	ar1
      00330A 74 F4            [12]10012 	mov	a,#_fan_fast
      00330C C0 E0            [24]10013 	push	acc
      00330E 74 31            [12]10014 	mov	a,#(_fan_fast >> 8)
      003310 C0 E0            [24]10015 	push	acc
      003312 E5 08            [12]10016 	mov	a,_bp
      003314 24 05            [12]10017 	add	a,#0x05
      003316 F8               [12]10018 	mov	r0,a
      003317 E6               [12]10019 	mov	a,@r0
      003318 C0 E0            [24]10020 	push	acc
      00331A 08               [12]10021 	inc	r0
      00331B E6               [12]10022 	mov	a,@r0
      00331C C0 E0            [24]10023 	push	acc
      00331E 08               [12]10024 	inc	r0
      00331F E6               [12]10025 	mov	a,@r0
      003320 C0 E0            [24]10026 	push	acc
      003322 08               [12]10027 	inc	r0
      003323 E6               [12]10028 	mov	a,@r0
      003324 C0 E0            [24]10029 	push	acc
      003326 74 BC            [12]10030 	mov	a,#___str_1
      003328 C0 E0            [24]10031 	push	acc
      00332A 74 38            [12]10032 	mov	a,#(___str_1 >> 8)
      00332C C0 E0            [24]10033 	push	acc
      00332E 74 80            [12]10034 	mov	a,#0x80
      003330 C0 E0            [24]10035 	push	acc
      003332 8A 82            [24]10036 	mov	dpl, r2
      003334 8E 83            [24]10037 	mov	dph, r6
      003336 8F F0            [24]10038 	mov	b, r7
      003338 12 17 6D         [24]10039 	lcall	_fuzzy_rules_add
      00333B AF 82            [24]10040 	mov	r7, dpl
      00333D E5 81            [12]10041 	mov	a,sp
      00333F 24 F7            [12]10042 	add	a,#0xf7
      003341 F5 81            [12]10043 	mov	sp,a
      003343 D0 01            [24]10044 	pop	ar1
      003345 D0 03            [24]10045 	pop	ar3
      003347 D0 01            [24]10046 	pop	ar1
      003349 EF               [12]10047 	mov	a,r7
      00334A 70 08            [24]10048 	jnz	00104$
      00334C 90 00 00         [24]10049 	mov	dptr,#0x0000
      00334F E4               [12]10050 	clr	a
      003350 F5 F0            [12]10051 	mov	b,a
      003352 80 51            [24]10052 	sjmp	00105$
      003354                      10053 00104$:
                           00329D 10054 	C$controller_8051.c$138$1_0$157 ==.
                                  10055 ;	../../controller_8051.c:138: &rules,
      003354 7F 00            [12]10056 	mov	r7,#0x00
      003356 7E 40            [12]10057 	mov	r6,#0x40
      003358 C0 01            [24]10058 	push	ar1
      00335A 74 03            [12]10059 	mov	a,#0x03
      00335C C0 E0            [24]10060 	push	acc
      00335E E4               [12]10061 	clr	a
      00335F C0 E0            [24]10062 	push	acc
      003361 C0 E0            [24]10063 	push	acc
      003363 74 20            [12]10064 	mov	a,#0x20
      003365 C0 E0            [24]10065 	push	acc
      003367 74 41            [12]10066 	mov	a,#0x41
      003369 C0 E0            [24]10067 	push	acc
      00336B E4               [12]10068 	clr	a
      00336C C0 E0            [24]10069 	push	acc
      00336E C0 E0            [24]10070 	push	acc
      003370 74 C8            [12]10071 	mov	a,#0xc8
      003372 C0 E0            [24]10072 	push	acc
      003374 74 42            [12]10073 	mov	a,#0x42
      003376 C0 E0            [24]10074 	push	acc
      003378 E4               [12]10075 	clr	a
      003379 C0 E0            [24]10076 	push	acc
      00337B C0 E0            [24]10077 	push	acc
      00337D C0 E0            [24]10078 	push	acc
      00337F C0 E0            [24]10079 	push	acc
      003381 8B 82            [24]10080 	mov	dpl, r3
      003383 8F 83            [24]10081 	mov	dph, r7
      003385 8E F0            [24]10082 	mov	b, r6
      003387 12 30 43         [24]10083 	lcall	_fuzzy_rules_defuzzify
      00338A AC 82            [24]10084 	mov	r4, dpl
      00338C AD 83            [24]10085 	mov	r5, dph
      00338E AE F0            [24]10086 	mov	r6, b
      003390 FF               [12]10087 	mov	r7, a
      003391 E5 81            [12]10088 	mov	a,sp
      003393 24 F3            [12]10089 	add	a,#0xf3
      003395 F5 81            [12]10090 	mov	sp,a
      003397 D0 01            [24]10091 	pop	ar1
                           0032E2 10092 	C$controller_8051.c$146$1_0$157 ==.
                                  10093 ;	../../controller_8051.c:146: rules.count = 0;
      003399 77 00            [12]10094 	mov	@r1,#0x00
      00339B 09               [12]10095 	inc	r1
      00339C 77 00            [12]10096 	mov	@r1,#0x00
                           0032E7 10097 	C$controller_8051.c$148$1_0$157 ==.
                                  10098 ;	../../controller_8051.c:148: return result;
      00339E 8C 82            [24]10099 	mov	dpl, r4
      0033A0 8D 83            [24]10100 	mov	dph, r5
      0033A2 8E F0            [24]10101 	mov	b, r6
      0033A4 EF               [12]10102 	mov	a, r7
      0033A5                      10103 00105$:
                           0032EE 10104 	C$controller_8051.c$149$1_0$157 ==.
                                  10105 ;	../../controller_8051.c:149: }
      0033A5 85 08 81         [24]10106 	mov	sp,_bp
      0033A8 D0 08            [24]10107 	pop	_bp
                           0032F3 10108 	C$controller_8051.c$149$1_0$157 ==.
                           0032F3 10109 	XFcontroller_8051$calculate_fan_speed$0$0 ==.
      0033AA 22               [24]10110 	ret
                                  10111 ;------------------------------------------------------------
                                  10112 ;Allocation info for local variables in function 'fan_speed_to_pwm'
                                  10113 ;------------------------------------------------------------
                                  10114 ;fan_speed     Allocated to registers r4 r5 r6 r7 
                                  10115 ;------------------------------------------------------------
                           0032F4 10116 	Fcontroller_8051$fan_speed_to_pwm$0$0 ==.
                           0032F4 10117 	C$controller_8051.c$156$1_0$159 ==.
                                  10118 ;	../../controller_8051.c:156: static unsigned char fan_speed_to_pwm(
                                  10119 ;	-----------------------------------------
                                  10120 ;	 function fan_speed_to_pwm
                                  10121 ;	-----------------------------------------
      0033AB                      10122 _fan_speed_to_pwm:
      0033AB AC 82            [24]10123 	mov	r4,dpl
      0033AD AD 83            [24]10124 	mov	r5,dph
      0033AF AE F0            [24]10125 	mov	r6,b
      0033B1 FF               [12]10126 	mov	r7,a
                           0032FB 10127 	C$controller_8051.c$160$1_0$159 ==.
                                  10128 ;	../../controller_8051.c:160: if (fan_speed <= 0.0f) {
      0033B2 C0 07            [24]10129 	push	ar7
      0033B4 C0 06            [24]10130 	push	ar6
      0033B6 C0 05            [24]10131 	push	ar5
      0033B8 C0 04            [24]10132 	push	ar4
      0033BA C0 04            [24]10133 	push	ar4
      0033BC C0 05            [24]10134 	push	ar5
      0033BE C0 06            [24]10135 	push	ar6
      0033C0 C0 07            [24]10136 	push	ar7
      0033C2 90 00 00         [24]10137 	mov	dptr,#0x0000
      0033C5 E4               [12]10138 	clr	a
      0033C6 F5 F0            [12]10139 	mov	b,a
      0033C8 12 35 C2         [24]10140 	lcall	___fslt
      0033CB E5 81            [12]10141 	mov	a,sp
      0033CD 24 FC            [12]10142 	add	a,#0xfc
      0033CF F5 81            [12]10143 	mov	sp,a
      0033D1 D0 04            [24]10144 	pop	ar4
      0033D3 D0 05            [24]10145 	pop	ar5
      0033D5 D0 06            [24]10146 	pop	ar6
      0033D7 D0 07            [24]10147 	pop	ar7
      0033D9 E5 82            [12]10148 	mov	a, dpl
      0033DB 24 FF            [12]10149 	add	a,#0xff
      0033DD 92 00            [24]10150 	mov	b0,c
      0033DF 40 05            [24]10151 	jc	00102$
                           00332A 10152 	C$controller_8051.c$161$2_0$160 ==.
                                  10153 ;	../../controller_8051.c:161: return 0u;
      0033E1 75 82 00         [24]10154 	mov	dpl, #0x00
      0033E4 80 66            [24]10155 	sjmp	00105$
      0033E6                      10156 00102$:
                           00332F 10157 	C$controller_8051.c$164$1_0$159 ==.
                                  10158 ;	../../controller_8051.c:164: if (fan_speed >= 100.0f) {
      0033E6 C0 07            [24]10159 	push	ar7
      0033E8 C0 06            [24]10160 	push	ar6
      0033EA C0 05            [24]10161 	push	ar5
      0033EC C0 04            [24]10162 	push	ar4
      0033EE E4               [12]10163 	clr	a
      0033EF C0 E0            [24]10164 	push	acc
      0033F1 C0 E0            [24]10165 	push	acc
      0033F3 74 C8            [12]10166 	mov	a,#0xc8
      0033F5 C0 E0            [24]10167 	push	acc
      0033F7 74 42            [12]10168 	mov	a,#0x42
      0033F9 C0 E0            [24]10169 	push	acc
      0033FB 8C 82            [24]10170 	mov	dpl, r4
      0033FD 8D 83            [24]10171 	mov	dph, r5
      0033FF 8E F0            [24]10172 	mov	b, r6
      003401 EF               [12]10173 	mov	a, r7
      003402 12 35 C2         [24]10174 	lcall	___fslt
      003405 E5 81            [12]10175 	mov	a,sp
      003407 24 FC            [12]10176 	add	a,#0xfc
      003409 F5 81            [12]10177 	mov	sp,a
      00340B D0 04            [24]10178 	pop	ar4
      00340D D0 05            [24]10179 	pop	ar5
      00340F D0 06            [24]10180 	pop	ar6
      003411 D0 07            [24]10181 	pop	ar7
      003413 E5 82            [12]10182 	mov	a, dpl
      003415 24 FF            [12]10183 	add	a,#0xff
      003417 92 00            [24]10184 	mov	b0,c
      003419 40 05            [24]10185 	jc	00104$
                           003364 10186 	C$controller_8051.c$165$2_0$161 ==.
                                  10187 ;	../../controller_8051.c:165: return 100u;
      00341B 75 82 64         [24]10188 	mov	dpl, #0x64
      00341E 80 2C            [24]10189 	sjmp	00105$
      003420                      10190 00104$:
                           003369 10191 	C$controller_8051.c$170$1_0$159 ==.
                                  10192 ;	../../controller_8051.c:170: );
      003420 E4               [12]10193 	clr	a
      003421 C0 E0            [24]10194 	push	acc
      003423 C0 E0            [24]10195 	push	acc
      003425 C0 E0            [24]10196 	push	acc
      003427 74 3F            [12]10197 	mov	a,#0x3f
      003429 C0 E0            [24]10198 	push	acc
      00342B 8C 82            [24]10199 	mov	dpl, r4
      00342D 8D 83            [24]10200 	mov	dph, r5
      00342F 8E F0            [24]10201 	mov	b, r6
      003431 EF               [12]10202 	mov	a, r7
      003432 12 36 14         [24]10203 	lcall	___fsadd
      003435 AC 82            [24]10204 	mov	r4, dpl
      003437 AD 83            [24]10205 	mov	r5, dph
      003439 AE F0            [24]10206 	mov	r6, b
      00343B FF               [12]10207 	mov	r7, a
      00343C E5 81            [12]10208 	mov	a,sp
      00343E 24 FC            [12]10209 	add	a,#0xfc
      003440 F5 81            [12]10210 	mov	sp,a
      003442 8C 82            [24]10211 	mov	dpl, r4
      003444 8D 83            [24]10212 	mov	dph, r5
      003446 8E F0            [24]10213 	mov	b, r6
      003448 EF               [12]10214 	mov	a, r7
      003449 12 38 0A         [24]10215 	lcall	___fs2uchar
      00344C                      10216 00105$:
                           003395 10217 	C$controller_8051.c$171$1_0$159 ==.
                                  10218 ;	../../controller_8051.c:171: }
                           003395 10219 	C$controller_8051.c$171$1_0$159 ==.
                           003395 10220 	XFcontroller_8051$fan_speed_to_pwm$0$0 ==.
      00344C 22               [24]10221 	ret
                                  10222 ;------------------------------------------------------------
                                  10223 ;Allocation info for local variables in function 'main'
                                  10224 ;------------------------------------------------------------
                           003396 10225 	G$main$0$0 ==.
                           003396 10226 	C$controller_8051.c$188$1_0$163 ==.
                                  10227 ;	../../controller_8051.c:188: void main(void)
                                  10228 ;	-----------------------------------------
                                  10229 ;	 function main
                                  10230 ;	-----------------------------------------
      00344D                      10231 _main:
                           003396 10232 	C$controller_8051.c$196$1_0$163 ==.
                                  10233 ;	../../controller_8051.c:196: 42u;
      00344D 75 61 2A         [24]10234 	mov	_test_temperature,#0x2a
                           003399 10235 	C$controller_8051.c$202$1_0$163 ==.
                                  10236 ;	../../controller_8051.c:202: 0x55u;
      003450 75 80 55         [24]10237 	mov	_P0,#0x55
                           00339C 10238 	C$controller_8051.c$205$1_0$163 ==.
                                  10239 ;	../../controller_8051.c:205: 0x00u;
      003453 75 90 00         [24]10240 	mov	_P1,#0x00
                           00339F 10241 	C$controller_8051.c$211$1_0$163 ==.
                                  10242 ;	../../controller_8051.c:211: test_temperature = P2;
      003456 85 A0 61         [24]10243 	mov	_test_temperature,_P2
                           0033A2 10244 	C$controller_8051.c$216$2_0$163 ==.
                                  10245 ;	../../controller_8051.c:216: );
      003459 85 61 82         [24]10246 	mov	dpl, _test_temperature
      00345C 12 38 12         [24]10247 	lcall	___uchar2fs
      00345F 12 32 3A         [24]10248 	lcall	_calculate_fan_speed
      003462 85 82 63         [24]10249 	mov	_test_fan_speed,dpl
      003465 85 83 64         [24]10250 	mov	(_test_fan_speed + 1),dph
      003468 85 F0 65         [24]10251 	mov	(_test_fan_speed + 2),b
      00346B F5 66            [12]10252 	mov	(_test_fan_speed + 3),a
                           0033B6 10253 	C$controller_8051.c$220$1_0$163 ==.
                                  10254 ;	../../controller_8051.c:220: test_fan_speed
      00346D 85 63 82         [24]10255 	mov	dpl, _test_fan_speed
      003470 85 64 83         [24]10256 	mov	dph, (_test_fan_speed + 1)
      003473 85 65 F0         [24]10257 	mov	b, (_test_fan_speed + 2)
      003476 E5 66            [12]10258 	mov	a, (_test_fan_speed + 3)
      003478 12 33 AB         [24]10259 	lcall	_fan_speed_to_pwm
      00347B 85 82 62         [24]10260 	mov	_test_pwm,dpl
                           0033C7 10261 	C$controller_8051.c$227$1_0$163 ==.
                                  10262 ;	../../controller_8051.c:227: test_pwm;
      00347E 85 62 90         [24]10263 	mov	_P1,_test_pwm
                           0033CA 10264 	C$controller_8051.c$233$1_0$163 ==.
                                  10265 ;	../../controller_8051.c:233: 0xAAu;
      003481 75 80 AA         [24]10266 	mov	_P0,#0xaa
      003484                      10267 00103$:
      003484 80 FE            [24]10268 	sjmp	00103$
                           0033CF 10269 	C$controller_8051.c$238$2_0$163 ==.
                                  10270 ;	../../controller_8051.c:238: }
                           0033CF 10271 	C$controller_8051.c$238$2_0$163 ==.
                           0033CF 10272 	XG$main$0$0 ==.
      003486 22               [24]10273 	ret
                                  10274 	.area CSEG    (CODE)
                                  10275 	.area CONST   (CODE)
                                  10276 	.area CONST   (CODE)
                           000000 10277 Fcontroller_8051$hedges$0_0$0 == .
      0038B0                      10278 _hedges:
      0038B0 01                   10279 	.db #0x01	; 1
      0038B1 02                   10280 	.db #0x02	; 2
      0038B2 03                   10281 	.db #0x03	; 3
                                  10282 	.area CSEG    (CODE)
                           0033D0 10283 Fcontroller_8051$__str_0$0_0$0 == .
                                  10284 	.area CONST   (CODE)
      0038B3                      10285 ___str_0:
      0038B3 66 61 6E 5F 73 6C 6F 10286 	.ascii "fan_slow"
             77
      0038BB 00                   10287 	.db 0x00
                                  10288 	.area CSEG    (CODE)
                           0033D0 10289 Fcontroller_8051$__str_1$0_0$0 == .
                                  10290 	.area CONST   (CODE)
      0038BC                      10291 ___str_1:
      0038BC 66 61 6E 5F 66 61 73 10292 	.ascii "fan_fast"
             74
      0038C4 00                   10293 	.db 0x00
                                  10294 	.area CSEG    (CODE)
                                  10295 	.area XINIT   (CODE)
                                  10296 	.area CABS    (ABS,CODE)
