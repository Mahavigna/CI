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
                                    134 	.globl _fuzzy_ramp
                                    135 	.globl _fuzzy_rules_create
                                    136 	.globl _fuzzy_rules_add
                                    137 	.globl _fuzzy_rules_cog
                                    138 	.globl _fuzzy_rules_free
                                    139 ;--------------------------------------------------------
                                    140 ; special function registers
                                    141 ;--------------------------------------------------------
                                    142 	.area RSEG    (ABS,DATA)
      000000                        143 	.org 0x0000
                           000080   144 G$P0$0_0$0 == 0x0080
                           000080   145 _P0	=	0x0080
                           000081   146 G$SP$0_0$0 == 0x0081
                           000081   147 _SP	=	0x0081
                           000082   148 G$DPL$0_0$0 == 0x0082
                           000082   149 _DPL	=	0x0082
                           000083   150 G$DPH$0_0$0 == 0x0083
                           000083   151 _DPH	=	0x0083
                           000087   152 G$PCON$0_0$0 == 0x0087
                           000087   153 _PCON	=	0x0087
                           000088   154 G$TCON$0_0$0 == 0x0088
                           000088   155 _TCON	=	0x0088
                           000089   156 G$TMOD$0_0$0 == 0x0089
                           000089   157 _TMOD	=	0x0089
                           00008A   158 G$TL0$0_0$0 == 0x008a
                           00008A   159 _TL0	=	0x008a
                           00008B   160 G$TL1$0_0$0 == 0x008b
                           00008B   161 _TL1	=	0x008b
                           00008C   162 G$TH0$0_0$0 == 0x008c
                           00008C   163 _TH0	=	0x008c
                           00008D   164 G$TH1$0_0$0 == 0x008d
                           00008D   165 _TH1	=	0x008d
                           000090   166 G$P1$0_0$0 == 0x0090
                           000090   167 _P1	=	0x0090
                           000098   168 G$SCON$0_0$0 == 0x0098
                           000098   169 _SCON	=	0x0098
                           000099   170 G$SBUF$0_0$0 == 0x0099
                           000099   171 _SBUF	=	0x0099
                           0000A0   172 G$P2$0_0$0 == 0x00a0
                           0000A0   173 _P2	=	0x00a0
                           0000A8   174 G$IE$0_0$0 == 0x00a8
                           0000A8   175 _IE	=	0x00a8
                           0000B0   176 G$P3$0_0$0 == 0x00b0
                           0000B0   177 _P3	=	0x00b0
                           0000B8   178 G$IP$0_0$0 == 0x00b8
                           0000B8   179 _IP	=	0x00b8
                           0000D0   180 G$PSW$0_0$0 == 0x00d0
                           0000D0   181 _PSW	=	0x00d0
                           0000E0   182 G$ACC$0_0$0 == 0x00e0
                           0000E0   183 _ACC	=	0x00e0
                           0000F0   184 G$B$0_0$0 == 0x00f0
                           0000F0   185 _B	=	0x00f0
                           0000C8   186 G$T2CON$0_0$0 == 0x00c8
                           0000C8   187 _T2CON	=	0x00c8
                           0000CA   188 G$RCAP2L$0_0$0 == 0x00ca
                           0000CA   189 _RCAP2L	=	0x00ca
                           0000CB   190 G$RCAP2H$0_0$0 == 0x00cb
                           0000CB   191 _RCAP2H	=	0x00cb
                           0000CC   192 G$TL2$0_0$0 == 0x00cc
                           0000CC   193 _TL2	=	0x00cc
                           0000CD   194 G$TH2$0_0$0 == 0x00cd
                           0000CD   195 _TH2	=	0x00cd
                                    196 ;--------------------------------------------------------
                                    197 ; special function bits
                                    198 ;--------------------------------------------------------
                                    199 	.area RSEG    (ABS,DATA)
      000000                        200 	.org 0x0000
                           000080   201 G$P0_0$0_0$0 == 0x0080
                           000080   202 _P0_0	=	0x0080
                           000081   203 G$P0_1$0_0$0 == 0x0081
                           000081   204 _P0_1	=	0x0081
                           000082   205 G$P0_2$0_0$0 == 0x0082
                           000082   206 _P0_2	=	0x0082
                           000083   207 G$P0_3$0_0$0 == 0x0083
                           000083   208 _P0_3	=	0x0083
                           000084   209 G$P0_4$0_0$0 == 0x0084
                           000084   210 _P0_4	=	0x0084
                           000085   211 G$P0_5$0_0$0 == 0x0085
                           000085   212 _P0_5	=	0x0085
                           000086   213 G$P0_6$0_0$0 == 0x0086
                           000086   214 _P0_6	=	0x0086
                           000087   215 G$P0_7$0_0$0 == 0x0087
                           000087   216 _P0_7	=	0x0087
                           000088   217 G$IT0$0_0$0 == 0x0088
                           000088   218 _IT0	=	0x0088
                           000089   219 G$IE0$0_0$0 == 0x0089
                           000089   220 _IE0	=	0x0089
                           00008A   221 G$IT1$0_0$0 == 0x008a
                           00008A   222 _IT1	=	0x008a
                           00008B   223 G$IE1$0_0$0 == 0x008b
                           00008B   224 _IE1	=	0x008b
                           00008C   225 G$TR0$0_0$0 == 0x008c
                           00008C   226 _TR0	=	0x008c
                           00008D   227 G$TF0$0_0$0 == 0x008d
                           00008D   228 _TF0	=	0x008d
                           00008E   229 G$TR1$0_0$0 == 0x008e
                           00008E   230 _TR1	=	0x008e
                           00008F   231 G$TF1$0_0$0 == 0x008f
                           00008F   232 _TF1	=	0x008f
                           000090   233 G$P1_0$0_0$0 == 0x0090
                           000090   234 _P1_0	=	0x0090
                           000091   235 G$P1_1$0_0$0 == 0x0091
                           000091   236 _P1_1	=	0x0091
                           000092   237 G$P1_2$0_0$0 == 0x0092
                           000092   238 _P1_2	=	0x0092
                           000093   239 G$P1_3$0_0$0 == 0x0093
                           000093   240 _P1_3	=	0x0093
                           000094   241 G$P1_4$0_0$0 == 0x0094
                           000094   242 _P1_4	=	0x0094
                           000095   243 G$P1_5$0_0$0 == 0x0095
                           000095   244 _P1_5	=	0x0095
                           000096   245 G$P1_6$0_0$0 == 0x0096
                           000096   246 _P1_6	=	0x0096
                           000097   247 G$P1_7$0_0$0 == 0x0097
                           000097   248 _P1_7	=	0x0097
                           000098   249 G$RI$0_0$0 == 0x0098
                           000098   250 _RI	=	0x0098
                           000099   251 G$TI$0_0$0 == 0x0099
                           000099   252 _TI	=	0x0099
                           00009A   253 G$RB8$0_0$0 == 0x009a
                           00009A   254 _RB8	=	0x009a
                           00009B   255 G$TB8$0_0$0 == 0x009b
                           00009B   256 _TB8	=	0x009b
                           00009C   257 G$REN$0_0$0 == 0x009c
                           00009C   258 _REN	=	0x009c
                           00009D   259 G$SM2$0_0$0 == 0x009d
                           00009D   260 _SM2	=	0x009d
                           00009E   261 G$SM1$0_0$0 == 0x009e
                           00009E   262 _SM1	=	0x009e
                           00009F   263 G$SM0$0_0$0 == 0x009f
                           00009F   264 _SM0	=	0x009f
                           0000A0   265 G$P2_0$0_0$0 == 0x00a0
                           0000A0   266 _P2_0	=	0x00a0
                           0000A1   267 G$P2_1$0_0$0 == 0x00a1
                           0000A1   268 _P2_1	=	0x00a1
                           0000A2   269 G$P2_2$0_0$0 == 0x00a2
                           0000A2   270 _P2_2	=	0x00a2
                           0000A3   271 G$P2_3$0_0$0 == 0x00a3
                           0000A3   272 _P2_3	=	0x00a3
                           0000A4   273 G$P2_4$0_0$0 == 0x00a4
                           0000A4   274 _P2_4	=	0x00a4
                           0000A5   275 G$P2_5$0_0$0 == 0x00a5
                           0000A5   276 _P2_5	=	0x00a5
                           0000A6   277 G$P2_6$0_0$0 == 0x00a6
                           0000A6   278 _P2_6	=	0x00a6
                           0000A7   279 G$P2_7$0_0$0 == 0x00a7
                           0000A7   280 _P2_7	=	0x00a7
                           0000A8   281 G$EX0$0_0$0 == 0x00a8
                           0000A8   282 _EX0	=	0x00a8
                           0000A9   283 G$ET0$0_0$0 == 0x00a9
                           0000A9   284 _ET0	=	0x00a9
                           0000AA   285 G$EX1$0_0$0 == 0x00aa
                           0000AA   286 _EX1	=	0x00aa
                           0000AB   287 G$ET1$0_0$0 == 0x00ab
                           0000AB   288 _ET1	=	0x00ab
                           0000AC   289 G$ES$0_0$0 == 0x00ac
                           0000AC   290 _ES	=	0x00ac
                           0000AF   291 G$EA$0_0$0 == 0x00af
                           0000AF   292 _EA	=	0x00af
                           0000B0   293 G$P3_0$0_0$0 == 0x00b0
                           0000B0   294 _P3_0	=	0x00b0
                           0000B1   295 G$P3_1$0_0$0 == 0x00b1
                           0000B1   296 _P3_1	=	0x00b1
                           0000B2   297 G$P3_2$0_0$0 == 0x00b2
                           0000B2   298 _P3_2	=	0x00b2
                           0000B3   299 G$P3_3$0_0$0 == 0x00b3
                           0000B3   300 _P3_3	=	0x00b3
                           0000B4   301 G$P3_4$0_0$0 == 0x00b4
                           0000B4   302 _P3_4	=	0x00b4
                           0000B5   303 G$P3_5$0_0$0 == 0x00b5
                           0000B5   304 _P3_5	=	0x00b5
                           0000B6   305 G$P3_6$0_0$0 == 0x00b6
                           0000B6   306 _P3_6	=	0x00b6
                           0000B7   307 G$P3_7$0_0$0 == 0x00b7
                           0000B7   308 _P3_7	=	0x00b7
                           0000B0   309 G$RXD$0_0$0 == 0x00b0
                           0000B0   310 _RXD	=	0x00b0
                           0000B1   311 G$TXD$0_0$0 == 0x00b1
                           0000B1   312 _TXD	=	0x00b1
                           0000B2   313 G$INT0$0_0$0 == 0x00b2
                           0000B2   314 _INT0	=	0x00b2
                           0000B3   315 G$INT1$0_0$0 == 0x00b3
                           0000B3   316 _INT1	=	0x00b3
                           0000B4   317 G$T0$0_0$0 == 0x00b4
                           0000B4   318 _T0	=	0x00b4
                           0000B5   319 G$T1$0_0$0 == 0x00b5
                           0000B5   320 _T1	=	0x00b5
                           0000B6   321 G$WR$0_0$0 == 0x00b6
                           0000B6   322 _WR	=	0x00b6
                           0000B7   323 G$RD$0_0$0 == 0x00b7
                           0000B7   324 _RD	=	0x00b7
                           0000B8   325 G$PX0$0_0$0 == 0x00b8
                           0000B8   326 _PX0	=	0x00b8
                           0000B9   327 G$PT0$0_0$0 == 0x00b9
                           0000B9   328 _PT0	=	0x00b9
                           0000BA   329 G$PX1$0_0$0 == 0x00ba
                           0000BA   330 _PX1	=	0x00ba
                           0000BB   331 G$PT1$0_0$0 == 0x00bb
                           0000BB   332 _PT1	=	0x00bb
                           0000BC   333 G$PS$0_0$0 == 0x00bc
                           0000BC   334 _PS	=	0x00bc
                           0000D0   335 G$P$0_0$0 == 0x00d0
                           0000D0   336 _P	=	0x00d0
                           0000D1   337 G$F1$0_0$0 == 0x00d1
                           0000D1   338 _F1	=	0x00d1
                           0000D2   339 G$OV$0_0$0 == 0x00d2
                           0000D2   340 _OV	=	0x00d2
                           0000D3   341 G$RS0$0_0$0 == 0x00d3
                           0000D3   342 _RS0	=	0x00d3
                           0000D4   343 G$RS1$0_0$0 == 0x00d4
                           0000D4   344 _RS1	=	0x00d4
                           0000D5   345 G$F0$0_0$0 == 0x00d5
                           0000D5   346 _F0	=	0x00d5
                           0000D6   347 G$AC$0_0$0 == 0x00d6
                           0000D6   348 _AC	=	0x00d6
                           0000D7   349 G$CY$0_0$0 == 0x00d7
                           0000D7   350 _CY	=	0x00d7
                           0000AD   351 G$ET2$0_0$0 == 0x00ad
                           0000AD   352 _ET2	=	0x00ad
                           0000BD   353 G$PT2$0_0$0 == 0x00bd
                           0000BD   354 _PT2	=	0x00bd
                           0000C8   355 G$T2CON_0$0_0$0 == 0x00c8
                           0000C8   356 _T2CON_0	=	0x00c8
                           0000C9   357 G$T2CON_1$0_0$0 == 0x00c9
                           0000C9   358 _T2CON_1	=	0x00c9
                           0000CA   359 G$T2CON_2$0_0$0 == 0x00ca
                           0000CA   360 _T2CON_2	=	0x00ca
                           0000CB   361 G$T2CON_3$0_0$0 == 0x00cb
                           0000CB   362 _T2CON_3	=	0x00cb
                           0000CC   363 G$T2CON_4$0_0$0 == 0x00cc
                           0000CC   364 _T2CON_4	=	0x00cc
                           0000CD   365 G$T2CON_5$0_0$0 == 0x00cd
                           0000CD   366 _T2CON_5	=	0x00cd
                           0000CE   367 G$T2CON_6$0_0$0 == 0x00ce
                           0000CE   368 _T2CON_6	=	0x00ce
                           0000CF   369 G$T2CON_7$0_0$0 == 0x00cf
                           0000CF   370 _T2CON_7	=	0x00cf
                           0000C8   371 G$CP_RL2$0_0$0 == 0x00c8
                           0000C8   372 _CP_RL2	=	0x00c8
                           0000C9   373 G$C_T2$0_0$0 == 0x00c9
                           0000C9   374 _C_T2	=	0x00c9
                           0000CA   375 G$TR2$0_0$0 == 0x00ca
                           0000CA   376 _TR2	=	0x00ca
                           0000CB   377 G$EXEN2$0_0$0 == 0x00cb
                           0000CB   378 _EXEN2	=	0x00cb
                           0000CC   379 G$TCLK$0_0$0 == 0x00cc
                           0000CC   380 _TCLK	=	0x00cc
                           0000CD   381 G$RCLK$0_0$0 == 0x00cd
                           0000CD   382 _RCLK	=	0x00cd
                           0000CE   383 G$EXF2$0_0$0 == 0x00ce
                           0000CE   384 _EXF2	=	0x00ce
                           0000CF   385 G$TF2$0_0$0 == 0x00cf
                           0000CF   386 _TF2	=	0x00cf
                                    387 ;--------------------------------------------------------
                                    388 ; overlayable register banks
                                    389 ;--------------------------------------------------------
                                    390 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        391 	.ds 8
                                    392 ;--------------------------------------------------------
                                    393 ; overlayable bit register bank
                                    394 ;--------------------------------------------------------
                                    395 	.area BIT_BANK	(REL,OVR,DATA)
      000020                        396 bits:
      000020                        397 	.ds 1
                           008000   398 	b0 = bits[0]
                           008100   399 	b1 = bits[1]
                           008200   400 	b2 = bits[2]
                           008300   401 	b3 = bits[3]
                           008400   402 	b4 = bits[4]
                           008500   403 	b5 = bits[5]
                           008600   404 	b6 = bits[6]
                           008700   405 	b7 = bits[7]
                                    406 ;--------------------------------------------------------
                                    407 ; internal ram data
                                    408 ;--------------------------------------------------------
                                    409 	.area DSEG    (DATA)
                           000000   410 G$test_temperature$0_0$0==.
      000008                        411 _test_temperature::
      000008                        412 	.ds 1
                           000001   413 G$test_pwm$0_0$0==.
      000009                        414 _test_pwm::
      000009                        415 	.ds 1
                           000002   416 G$test_fan_speed$0_0$0==.
      00000A                        417 _test_fan_speed::
      00000A                        418 	.ds 4
                                    419 ;--------------------------------------------------------
                                    420 ; overlayable items in internal ram
                                    421 ;--------------------------------------------------------
                                    422 ;--------------------------------------------------------
                                    423 ; Stack segment in internal ram
                                    424 ;--------------------------------------------------------
                                    425 	.area SSEG
      000021                        426 __start__stack:
      000021                        427 	.ds	1
                                    428 
                                    429 ;--------------------------------------------------------
                                    430 ; indirectly addressable internal ram data
                                    431 ;--------------------------------------------------------
                                    432 	.area ISEG    (DATA)
                                    433 ;--------------------------------------------------------
                                    434 ; absolute internal ram data
                                    435 ;--------------------------------------------------------
                                    436 	.area IABS    (ABS,DATA)
                                    437 	.area IABS    (ABS,DATA)
                                    438 ;--------------------------------------------------------
                                    439 ; bit data
                                    440 ;--------------------------------------------------------
                                    441 	.area BSEG    (BIT)
                                    442 ;--------------------------------------------------------
                                    443 ; paged external ram data
                                    444 ;--------------------------------------------------------
                                    445 	.area PSEG    (PAG,XDATA)
                                    446 ;--------------------------------------------------------
                                    447 ; uninitialized external ram data
                                    448 ;--------------------------------------------------------
                                    449 	.area XSEG    (XDATA)
                                    450 ;--------------------------------------------------------
                                    451 ; absolute external ram data
                                    452 ;--------------------------------------------------------
                                    453 	.area XABS    (ABS,XDATA)
                                    454 ;--------------------------------------------------------
                                    455 ; initialized external ram data
                                    456 ;--------------------------------------------------------
                                    457 	.area XISEG   (XDATA)
                                    458 	.area HOME    (CODE)
                                    459 	.area GSINIT0 (CODE)
                                    460 	.area GSINIT1 (CODE)
                                    461 	.area GSINIT2 (CODE)
                                    462 	.area GSINIT3 (CODE)
                                    463 	.area GSINIT4 (CODE)
                                    464 	.area GSINIT5 (CODE)
                                    465 	.area GSINIT  (CODE)
                                    466 	.area GSFINAL (CODE)
                                    467 	.area CSEG    (CODE)
                                    468 ;--------------------------------------------------------
                                    469 ; interrupt vector
                                    470 ;--------------------------------------------------------
                                    471 	.area HOME    (CODE)
      000000                        472 __interrupt_vect:
      000000 02 00 4C         [24]  473 	ljmp	__sdcc_gsinit_startup
                                    474 ; restartable atomic support routines
      000003                        475 	.ds	5
      000008                        476 sdcc_atomic_exchange_rollback_start::
      000008 00               [12]  477 	nop
      000009 00               [12]  478 	nop
      00000A                        479 sdcc_atomic_exchange_pdata_impl:
      00000A E2               [24]  480 	movx	a, @r0
      00000B FB               [12]  481 	mov	r3, a
      00000C EA               [12]  482 	mov	a, r2
      00000D F2               [24]  483 	movx	@r0, a
      00000E 80 2C            [24]  484 	sjmp	sdcc_atomic_exchange_exit
      000010 00               [12]  485 	nop
      000011 00               [12]  486 	nop
      000012                        487 sdcc_atomic_exchange_xdata_impl:
      000012 E0               [24]  488 	movx	a, @dptr
      000013 FB               [12]  489 	mov	r3, a
      000014 EA               [12]  490 	mov	a, r2
      000015 F0               [24]  491 	movx	@dptr, a
      000016 80 24            [24]  492 	sjmp	sdcc_atomic_exchange_exit
      000018                        493 sdcc_atomic_compare_exchange_idata_impl:
      000018 E6               [12]  494 	mov	a, @r0
      000019 B5 02 02         [24]  495 	cjne	a, ar2, .+#5
      00001C EB               [12]  496 	mov	a, r3
      00001D F6               [12]  497 	mov	@r0, a
      00001E 22               [24]  498 	ret
      00001F 00               [12]  499 	nop
      000020                        500 sdcc_atomic_compare_exchange_pdata_impl:
      000020 E2               [24]  501 	movx	a, @r0
      000021 B5 02 02         [24]  502 	cjne	a, ar2, .+#5
      000024 EB               [12]  503 	mov	a, r3
      000025 F2               [24]  504 	movx	@r0, a
      000026 22               [24]  505 	ret
      000027 00               [12]  506 	nop
      000028                        507 sdcc_atomic_compare_exchange_xdata_impl:
      000028 E0               [24]  508 	movx	a, @dptr
      000029 B5 02 02         [24]  509 	cjne	a, ar2, .+#5
      00002C EB               [12]  510 	mov	a, r3
      00002D F0               [24]  511 	movx	@dptr, a
      00002E 22               [24]  512 	ret
      00002F                        513 sdcc_atomic_exchange_rollback_end::
                                    514 
      00002F                        515 sdcc_atomic_exchange_gptr_impl::
      00002F 30 F6 E0         [24]  516 	jnb	b.6, sdcc_atomic_exchange_xdata_impl
      000032 A8 82            [24]  517 	mov	r0, dpl
      000034 20 F5 D3         [24]  518 	jb	b.5, sdcc_atomic_exchange_pdata_impl
      000037                        519 sdcc_atomic_exchange_idata_impl:
      000037 EA               [12]  520 	mov	a, r2
      000038 C6               [12]  521 	xch	a, @r0
      000039 F5 82            [12]  522 	mov	dpl, a
      00003B 22               [24]  523 	ret
      00003C                        524 sdcc_atomic_exchange_exit:
      00003C 8B 82            [24]  525 	mov	dpl, r3
      00003E 22               [24]  526 	ret
      00003F                        527 sdcc_atomic_compare_exchange_gptr_impl::
      00003F 30 F6 E6         [24]  528 	jnb	b.6, sdcc_atomic_compare_exchange_xdata_impl
      000042 A8 82            [24]  529 	mov	r0, dpl
      000044 20 F5 D9         [24]  530 	jb	b.5, sdcc_atomic_compare_exchange_pdata_impl
      000047 80 CF            [24]  531 	sjmp	sdcc_atomic_compare_exchange_idata_impl
                                    532 ;--------------------------------------------------------
                                    533 ; global & static initialisations
                                    534 ;--------------------------------------------------------
                                    535 	.area HOME    (CODE)
                                    536 	.area GSINIT  (CODE)
                                    537 	.area GSFINAL (CODE)
                                    538 	.area GSINIT  (CODE)
                                    539 	.globl __sdcc_gsinit_startup
                                    540 	.globl __sdcc_program_startup
                                    541 	.globl __start__stack
                                    542 	.globl __mcs51_genXINIT
                                    543 	.globl __mcs51_genXRAMCLEAR
                                    544 	.globl __mcs51_genRAMCLEAR
                           000000   545 	C$controller_8051.c$20$2_0$83 ==.
                                    546 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:20: volatile unsigned char test_temperature = 0u;
      0000A5 75 08 00         [24]  547 	mov	_test_temperature,#0x00
                           000003   548 	C$controller_8051.c$21$2_0$83 ==.
                                    549 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:21: volatile unsigned char test_pwm = 0u;
      0000A8 75 09 00         [24]  550 	mov	_test_pwm,#0x00
                           000006   551 	C$controller_8051.c$22$2_0$83 ==.
                                    552 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:22: volatile float test_fan_speed = 0.0f;
      0000AB E4               [12]  553 	clr	a
      0000AC F5 0A            [12]  554 	mov	_test_fan_speed,a
      0000AE F5 0B            [12]  555 	mov	(_test_fan_speed + 1),a
      0000B0 F5 0C            [12]  556 	mov	(_test_fan_speed + 2),a
      0000B2 F5 0D            [12]  557 	mov	(_test_fan_speed + 3),a
                                    558 	.area GSFINAL (CODE)
      0000B4 02 00 49         [24]  559 	ljmp	__sdcc_program_startup
                                    560 ;--------------------------------------------------------
                                    561 ; Home
                                    562 ;--------------------------------------------------------
                                    563 	.area HOME    (CODE)
                                    564 	.area HOME    (CODE)
      000049                        565 __sdcc_program_startup:
      000049 02 0C D0         [24]  566 	ljmp	_main
                                    567 ;	return from main will return to caller
                                    568 ;--------------------------------------------------------
                                    569 ; code
                                    570 ;--------------------------------------------------------
                                    571 	.area CSEG    (CODE)
                                    572 ;------------------------------------------------------------
                                    573 ;Allocation info for local variables in function 'fuzzy_clamp'
                                    574 ;------------------------------------------------------------
                                    575 ;value         Allocated to registers r4 r5 r6 r7 
                                    576 ;------------------------------------------------------------
                           000000   577 	Fcontroller_8051$fuzzy_clamp$0$0 ==.
                           000000   578 	C$fuzzy.h$465$0_0$35 ==.
                                    579 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:465: static float fuzzy_clamp(float value)
                                    580 ;	-----------------------------------------
                                    581 ;	 function fuzzy_clamp
                                    582 ;	-----------------------------------------
      0000B7                        583 _fuzzy_clamp:
                           000007   584 	ar7 = 0x07
                           000006   585 	ar6 = 0x06
                           000005   586 	ar5 = 0x05
                           000004   587 	ar4 = 0x04
                           000003   588 	ar3 = 0x03
                           000002   589 	ar2 = 0x02
                           000001   590 	ar1 = 0x01
                           000000   591 	ar0 = 0x00
      0000B7 AC 82            [24]  592 	mov	r4,dpl
      0000B9 AD 83            [24]  593 	mov	r5,dph
      0000BB AE F0            [24]  594 	mov	r6,b
      0000BD FF               [12]  595 	mov	r7,a
                           000007   596 	C$fuzzy.h$467$1_0$35 ==.
                                    597 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:467: if (value < LEVEL_LO) {
      0000BE C0 07            [24]  598 	push	ar7
      0000C0 C0 06            [24]  599 	push	ar6
      0000C2 C0 05            [24]  600 	push	ar5
      0000C4 C0 04            [24]  601 	push	ar4
      0000C6 E4               [12]  602 	clr	a
      0000C7 C0 E0            [24]  603 	push	acc
      0000C9 C0 E0            [24]  604 	push	acc
      0000CB C0 E0            [24]  605 	push	acc
      0000CD C0 E0            [24]  606 	push	acc
      0000CF 8C 82            [24]  607 	mov	dpl, r4
      0000D1 8D 83            [24]  608 	mov	dph, r5
      0000D3 8E F0            [24]  609 	mov	b, r6
      0000D5 EF               [12]  610 	mov	a, r7
      0000D6 12 0E 34         [24]  611 	lcall	___fslt
      0000D9 AB 82            [24]  612 	mov	r3, dpl
      0000DB E5 81            [12]  613 	mov	a,sp
      0000DD 24 FC            [12]  614 	add	a,#0xfc
      0000DF F5 81            [12]  615 	mov	sp,a
      0000E1 D0 04            [24]  616 	pop	ar4
      0000E3 D0 05            [24]  617 	pop	ar5
      0000E5 D0 06            [24]  618 	pop	ar6
      0000E7 D0 07            [24]  619 	pop	ar7
      0000E9 EB               [12]  620 	mov	a,r3
      0000EA 60 08            [24]  621 	jz	00102$
                           000035   622 	C$fuzzy.h$468$2_0$36 ==.
                                    623 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:468: return LEVEL_LO;
      0000EC 90 00 00         [24]  624 	mov	dptr,#0x0000
      0000EF E4               [12]  625 	clr	a
      0000F0 F5 F0            [12]  626 	mov	b,a
      0000F2 80 3F            [24]  627 	sjmp	00105$
      0000F4                        628 00102$:
                           00003D   629 	C$fuzzy.h$471$1_0$35 ==.
                                    630 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:471: if (value > LEVEL_HI) {
      0000F4 C0 07            [24]  631 	push	ar7
      0000F6 C0 06            [24]  632 	push	ar6
      0000F8 C0 05            [24]  633 	push	ar5
      0000FA C0 04            [24]  634 	push	ar4
      0000FC C0 04            [24]  635 	push	ar4
      0000FE C0 05            [24]  636 	push	ar5
      000100 C0 06            [24]  637 	push	ar6
      000102 C0 07            [24]  638 	push	ar7
      000104 90 00 00         [24]  639 	mov	dptr,#0x0000
      000107 75 F0 80         [24]  640 	mov	b, #0x80
      00010A 74 3F            [12]  641 	mov	a, #0x3f
      00010C 12 0E 34         [24]  642 	lcall	___fslt
      00010F AB 82            [24]  643 	mov	r3, dpl
      000111 E5 81            [12]  644 	mov	a,sp
      000113 24 FC            [12]  645 	add	a,#0xfc
      000115 F5 81            [12]  646 	mov	sp,a
      000117 D0 04            [24]  647 	pop	ar4
      000119 D0 05            [24]  648 	pop	ar5
      00011B D0 06            [24]  649 	pop	ar6
      00011D D0 07            [24]  650 	pop	ar7
      00011F EB               [12]  651 	mov	a,r3
      000120 60 0A            [24]  652 	jz	00104$
                           00006B   653 	C$fuzzy.h$472$2_0$37 ==.
                                    654 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:472: return LEVEL_HI;
      000122 90 00 00         [24]  655 	mov	dptr,#0x0000
      000125 75 F0 80         [24]  656 	mov	b, #0x80
      000128 74 3F            [12]  657 	mov	a, #0x3f
      00012A 80 07            [24]  658 	sjmp	00105$
      00012C                        659 00104$:
                           000075   660 	C$fuzzy.h$475$1_0$35 ==.
                                    661 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:475: return value;
      00012C 8C 82            [24]  662 	mov	dpl, r4
      00012E 8D 83            [24]  663 	mov	dph, r5
      000130 8E F0            [24]  664 	mov	b, r6
      000132 EF               [12]  665 	mov	a, r7
      000133                        666 00105$:
                           00007C   667 	C$fuzzy.h$476$1_0$35 ==.
                                    668 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:476: }
                           00007C   669 	C$fuzzy.h$476$1_0$35 ==.
                           00007C   670 	XFcontroller_8051$fuzzy_clamp$0$0 ==.
      000133 22               [24]  671 	ret
                                    672 ;------------------------------------------------------------
                                    673 ;Allocation info for local variables in function 'fuzzy_apply_hedge'
                                    674 ;------------------------------------------------------------
                                    675 ;hedge         Allocated to stack - _bp -3 +1 
                                    676 ;membership    Allocated to stack - _bp +1 +4 
                                    677 ;result        Allocated to registers r2 r3 r6 r7 
                                    678 ;------------------------------------------------------------
                           00007D   679 	Fcontroller_8051$fuzzy_apply_hedge$0$0 ==.
                           00007D   680 	C$fuzzy.h$486$1_0$39 ==.
                                    681 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:486: static float fuzzy_apply_hedge(
                                    682 ;	-----------------------------------------
                                    683 ;	 function fuzzy_apply_hedge
                                    684 ;	-----------------------------------------
      000134                        685 _fuzzy_apply_hedge:
      000134 C0 0E            [24]  686 	push	_bp
      000136 85 81 0E         [24]  687 	mov	_bp,sp
      000139 AC 82            [24]  688 	mov	r4,dpl
      00013B AD 83            [24]  689 	mov	r5,dph
      00013D AE F0            [24]  690 	mov	r6,b
      00013F FF               [12]  691 	mov	r7,a
      000140 E5 81            [12]  692 	mov	a,sp
      000142 24 04            [12]  693 	add	a,#0x04
      000144 F5 81            [12]  694 	mov	sp,a
                           00008F   695 	C$fuzzy.h$498$1_0$39 ==.
                                    696 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:498: fuzzy_clamp(membership);
      000146 8C 82            [24]  697 	mov	dpl, r4
      000148 8D 83            [24]  698 	mov	dph, r5
      00014A 8E F0            [24]  699 	mov	b, r6
      00014C EF               [12]  700 	mov	a, r7
      00014D 12 00 B7         [24]  701 	lcall	_fuzzy_clamp
      000150 A8 0E            [24]  702 	mov	r0,_bp
      000152 08               [12]  703 	inc	r0
      000153 A6 82            [24]  704 	mov	@r0, dpl
      000155 08               [12]  705 	inc	r0
      000156 A6 83            [24]  706 	mov	@r0, dph
      000158 08               [12]  707 	inc	r0
      000159 A6 F0            [24]  708 	mov	@r0, b
      00015B 08               [12]  709 	inc	r0
      00015C F6               [12]  710 	mov	@r0,a
                           0000A6   711 	C$fuzzy.h$513$1_0$39 ==.
                                    712 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:513: if (hedge == 0u) {
      00015D E5 0E            [12]  713 	mov	a,_bp
      00015F 24 FD            [12]  714 	add	a,#0xfd
      000161 F8               [12]  715 	mov	r0,a
      000162 E6               [12]  716 	mov	a,@r0
      000163 70 07            [24]  717 	jnz	00102$
                           0000AE   718 	C$fuzzy.h$514$2_0$40 ==.
                                    719 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:514: hedge = 1u;
      000165 E5 0E            [12]  720 	mov	a,_bp
      000167 24 FD            [12]  721 	add	a,#0xfd
      000169 F8               [12]  722 	mov	r0,a
      00016A 76 01            [12]  723 	mov	@r0,#0x01
      00016C                        724 00102$:
                           0000B5   725 	C$fuzzy.h$517$1_0$39 ==.
                                    726 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:517: result = LEVEL_HI;
      00016C 7A 00            [12]  727 	mov	r2,#0x00
      00016E 7B 00            [12]  728 	mov	r3,#0x00
      000170 7E 80            [12]  729 	mov	r6,#0x80
      000172 7F 3F            [12]  730 	mov	r7,#0x3f
                           0000BD   731 	C$fuzzy.h$519$1_0$39 ==.
                                    732 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:519: while (hedge > 0u) {
      000174 E5 0E            [12]  733 	mov	a,_bp
      000176 24 FD            [12]  734 	add	a,#0xfd
      000178 F8               [12]  735 	mov	r0,a
      000179 86 05            [24]  736 	mov	ar5,@r0
      00017B                        737 00103$:
      00017B ED               [12]  738 	mov	a,r5
      00017C 60 30            [24]  739 	jz	00105$
                           0000C7   740 	C$fuzzy.h$520$1_0$39 ==.
                                    741 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:520: result *= membership;
      00017E C0 05            [24]  742 	push	ar5
      000180 A8 0E            [24]  743 	mov	r0,_bp
      000182 08               [12]  744 	inc	r0
      000183 E6               [12]  745 	mov	a,@r0
      000184 C0 E0            [24]  746 	push	acc
      000186 08               [12]  747 	inc	r0
      000187 E6               [12]  748 	mov	a,@r0
      000188 C0 E0            [24]  749 	push	acc
      00018A 08               [12]  750 	inc	r0
      00018B E6               [12]  751 	mov	a,@r0
      00018C C0 E0            [24]  752 	push	acc
      00018E 08               [12]  753 	inc	r0
      00018F E6               [12]  754 	mov	a,@r0
      000190 C0 E0            [24]  755 	push	acc
                           0000DB   756 	C$fuzzy.h$521$1_0$39 ==.
                                    757 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:521: hedge--;
      000192 8A 82            [24]  758 	mov	dpl, r2
      000194 8B 83            [24]  759 	mov	dph, r3
      000196 8E F0            [24]  760 	mov	b, r6
      000198 EF               [12]  761 	mov	a, r7
      000199 12 0D 15         [24]  762 	lcall	___fsmul
      00019C AA 82            [24]  763 	mov	r2, dpl
      00019E AB 83            [24]  764 	mov	r3, dph
      0001A0 AE F0            [24]  765 	mov	r6, b
      0001A2 FF               [12]  766 	mov	r7, a
      0001A3 E5 81            [12]  767 	mov	a,sp
      0001A5 24 FC            [12]  768 	add	a,#0xfc
      0001A7 F5 81            [12]  769 	mov	sp,a
      0001A9 D0 05            [24]  770 	pop	ar5
      0001AB 1D               [12]  771 	dec	r5
      0001AC 80 CD            [24]  772 	sjmp	00103$
      0001AE                        773 00105$:
                           0000F7   774 	C$fuzzy.h$525$1_0$39 ==.
                                    775 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:525: result
      0001AE 8A 82            [24]  776 	mov	dpl, r2
      0001B0 8B 83            [24]  777 	mov	dph, r3
      0001B2 8E F0            [24]  778 	mov	b, r6
      0001B4 EF               [12]  779 	mov	a, r7
      0001B5 12 00 B7         [24]  780 	lcall	_fuzzy_clamp
                           000101   781 	C$fuzzy.h$529$1_0$39 ==.
                                    782 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:529: }
      0001B8 85 0E 81         [24]  783 	mov	sp,_bp
      0001BB D0 0E            [24]  784 	pop	_bp
                           000106   785 	C$fuzzy.h$529$1_0$39 ==.
                           000106   786 	XFcontroller_8051$fuzzy_apply_hedge$0$0 ==.
      0001BD 22               [24]  787 	ret
                                    788 ;------------------------------------------------------------
                                    789 ;Allocation info for local variables in function 'fuzzy_ramp'
                                    790 ;------------------------------------------------------------
                                    791 ;lower_boundary Allocated to stack - _bp -6 +4 
                                    792 ;upper_boundary Allocated to stack - _bp -10 +4 
                                    793 ;value         Allocated to stack - _bp -14 +4 
                                    794 ;ramp_up       Allocated to stack - _bp -15 +1 
                                    795 ;hedge         Allocated to stack - _bp -16 +1 
                                    796 ;name          Allocated to registers 
                                    797 ;result        Allocated to stack - _bp +5 +4 
                                    798 ;normalized    Allocated to registers r7 r6 r5 r4 
                                    799 ;sloc0         Allocated to stack - _bp +12 +4 
                                    800 ;sloc1         Allocated to stack - _bp +1 +4 
                                    801 ;------------------------------------------------------------
                           000107   802 	G$fuzzy_ramp$0$0 ==.
                           000107   803 	C$fuzzy.h$616$1_0$43 ==.
                                    804 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:616: float fuzzy_ramp(
                                    805 ;	-----------------------------------------
                                    806 ;	 function fuzzy_ramp
                                    807 ;	-----------------------------------------
      0001BE                        808 _fuzzy_ramp:
      0001BE C0 0E            [24]  809 	push	_bp
      0001C0 E5 81            [12]  810 	mov	a,sp
      0001C2 F5 0E            [12]  811 	mov	_bp,a
      0001C4 24 08            [12]  812 	add	a,#0x08
      0001C6 F5 81            [12]  813 	mov	sp,a
                           000111   814 	C$fuzzy.h$630$1_0$43 ==.
                                    815 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:630: if (lower_boundary >= upper_boundary) {
      0001C8 E5 0E            [12]  816 	mov	a,_bp
      0001CA 24 F6            [12]  817 	add	a,#0xf6
      0001CC F8               [12]  818 	mov	r0,a
      0001CD E6               [12]  819 	mov	a,@r0
      0001CE C0 E0            [24]  820 	push	acc
      0001D0 08               [12]  821 	inc	r0
      0001D1 E6               [12]  822 	mov	a,@r0
      0001D2 C0 E0            [24]  823 	push	acc
      0001D4 08               [12]  824 	inc	r0
      0001D5 E6               [12]  825 	mov	a,@r0
      0001D6 C0 E0            [24]  826 	push	acc
      0001D8 08               [12]  827 	inc	r0
      0001D9 E6               [12]  828 	mov	a,@r0
      0001DA C0 E0            [24]  829 	push	acc
      0001DC E5 0E            [12]  830 	mov	a,_bp
      0001DE 24 FA            [12]  831 	add	a,#0xfa
      0001E0 F8               [12]  832 	mov	r0,a
      0001E1 86 82            [24]  833 	mov	dpl, @r0
      0001E3 08               [12]  834 	inc	r0
      0001E4 86 83            [24]  835 	mov	dph, @r0
      0001E6 08               [12]  836 	inc	r0
      0001E7 86 F0            [24]  837 	mov	b, @r0
      0001E9 08               [12]  838 	inc	r0
      0001EA E6               [12]  839 	mov	a, @r0
      0001EB 12 0E 34         [24]  840 	lcall	___fslt
      0001EE E5 81            [12]  841 	mov	a,sp
      0001F0 24 FC            [12]  842 	add	a,#0xfc
      0001F2 F5 81            [12]  843 	mov	sp,a
      0001F4 E5 82            [12]  844 	mov	a, dpl
      0001F6 24 FF            [12]  845 	add	a,#0xff
      0001F8 92 00            [24]  846 	mov	b0,c
      0001FA 40 09            [24]  847 	jc	00102$
                           000145   848 	C$fuzzy.h$631$2_0$44 ==.
                                    849 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:631: return LEVEL_LO;
      0001FC 90 00 00         [24]  850 	mov	dptr,#0x0000
      0001FF E4               [12]  851 	clr	a
      000200 F5 F0            [12]  852 	mov	b,a
      000202 02 03 DD         [24]  853 	ljmp	00109$
      000205                        854 00102$:
                           00014E   855 	C$fuzzy.h$634$1_0$43 ==.
                                    856 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:634: if (value <= lower_boundary) {
      000205 E5 0E            [12]  857 	mov	a,_bp
      000207 24 F2            [12]  858 	add	a,#0xf2
      000209 F8               [12]  859 	mov	r0,a
      00020A E6               [12]  860 	mov	a,@r0
      00020B C0 E0            [24]  861 	push	acc
      00020D 08               [12]  862 	inc	r0
      00020E E6               [12]  863 	mov	a,@r0
      00020F C0 E0            [24]  864 	push	acc
      000211 08               [12]  865 	inc	r0
      000212 E6               [12]  866 	mov	a,@r0
      000213 C0 E0            [24]  867 	push	acc
      000215 08               [12]  868 	inc	r0
      000216 E6               [12]  869 	mov	a,@r0
      000217 C0 E0            [24]  870 	push	acc
      000219 E5 0E            [12]  871 	mov	a,_bp
      00021B 24 FA            [12]  872 	add	a,#0xfa
      00021D F8               [12]  873 	mov	r0,a
      00021E 86 82            [24]  874 	mov	dpl, @r0
      000220 08               [12]  875 	inc	r0
      000221 86 83            [24]  876 	mov	dph, @r0
      000223 08               [12]  877 	inc	r0
      000224 86 F0            [24]  878 	mov	b, @r0
      000226 08               [12]  879 	inc	r0
      000227 E6               [12]  880 	mov	a, @r0
      000228 12 0E 34         [24]  881 	lcall	___fslt
      00022B E5 81            [12]  882 	mov	a,sp
      00022D 24 FC            [12]  883 	add	a,#0xfc
      00022F F5 81            [12]  884 	mov	sp,a
      000231 E5 82            [12]  885 	mov	a, dpl
      000233 24 FF            [12]  886 	add	a,#0xff
      000235 92 00            [24]  887 	mov	b0,c
      000237 40 1D            [24]  888 	jc	00107$
                           000182   889 	C$fuzzy.h$636$2_0$45 ==.
                                    890 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:636: ramp_up
      000239 E5 0E            [12]  891 	mov	a,_bp
      00023B 24 F1            [12]  892 	add	a,#0xf1
      00023D F8               [12]  893 	mov	r0,a
      00023E E6               [12]  894 	mov	a,@r0
      00023F 60 0A            [24]  895 	jz	00111$
                           00018A   896 	C$fuzzy.h$637$2_0$45 ==.
                                    897 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:637: ? LEVEL_LO
      000241 7C 00            [12]  898 	mov	r4,#0x00
      000243 7D 00            [12]  899 	mov	r5,#0x00
      000245 7E 00            [12]  900 	mov	r6,#0x00
      000247 7F 00            [12]  901 	mov	r7,#0x00
      000249 80 08            [24]  902 	sjmp	00112$
      00024B                        903 00111$:
                           000194   904 	C$fuzzy.h$638$2_0$45 ==.
                                    905 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:638: : LEVEL_HI;
      00024B 7C 00            [12]  906 	mov	r4,#0x00
      00024D 7D 00            [12]  907 	mov	r5,#0x00
      00024F 7E 80            [12]  908 	mov	r6,#0x80
      000251 7F 3F            [12]  909 	mov	r7,#0x3f
      000253                        910 00112$:
      000253 02 03 BB         [24]  911 	ljmp	00108$
      000256                        912 00107$:
                           00019F   913 	C$fuzzy.h$640$1_0$43 ==.
                                    914 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:640: else if (value >= upper_boundary) {
      000256 E5 0E            [12]  915 	mov	a,_bp
      000258 24 F6            [12]  916 	add	a,#0xf6
      00025A F8               [12]  917 	mov	r0,a
      00025B E6               [12]  918 	mov	a,@r0
      00025C C0 E0            [24]  919 	push	acc
      00025E 08               [12]  920 	inc	r0
      00025F E6               [12]  921 	mov	a,@r0
      000260 C0 E0            [24]  922 	push	acc
      000262 08               [12]  923 	inc	r0
      000263 E6               [12]  924 	mov	a,@r0
      000264 C0 E0            [24]  925 	push	acc
      000266 08               [12]  926 	inc	r0
      000267 E6               [12]  927 	mov	a,@r0
      000268 C0 E0            [24]  928 	push	acc
      00026A E5 0E            [12]  929 	mov	a,_bp
      00026C 24 F2            [12]  930 	add	a,#0xf2
      00026E F8               [12]  931 	mov	r0,a
      00026F 86 82            [24]  932 	mov	dpl, @r0
      000271 08               [12]  933 	inc	r0
      000272 86 83            [24]  934 	mov	dph, @r0
      000274 08               [12]  935 	inc	r0
      000275 86 F0            [24]  936 	mov	b, @r0
      000277 08               [12]  937 	inc	r0
      000278 E6               [12]  938 	mov	a, @r0
      000279 12 0E 34         [24]  939 	lcall	___fslt
      00027C E5 81            [12]  940 	mov	a,sp
      00027E 24 FC            [12]  941 	add	a,#0xfc
      000280 F5 81            [12]  942 	mov	sp,a
      000282 E5 82            [12]  943 	mov	a, dpl
      000284 24 FF            [12]  944 	add	a,#0xff
      000286 92 00            [24]  945 	mov	b0,c
      000288 40 39            [24]  946 	jc	00104$
                           0001D3   947 	C$fuzzy.h$642$2_0$46 ==.
                                    948 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:642: ramp_up
      00028A E5 0E            [12]  949 	mov	a,_bp
      00028C 24 F1            [12]  950 	add	a,#0xf1
      00028E F8               [12]  951 	mov	r0,a
      00028F E6               [12]  952 	mov	a,@r0
      000290 60 11            [24]  953 	jz	00113$
                           0001DB   954 	C$fuzzy.h$643$2_0$46 ==.
                                    955 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:643: ? LEVEL_HI
      000292 E5 0E            [12]  956 	mov	a,_bp
      000294 24 05            [12]  957 	add	a,#0x05
      000296 F8               [12]  958 	mov	r0,a
      000297 E4               [12]  959 	clr	a
      000298 F6               [12]  960 	mov	@r0,a
      000299 08               [12]  961 	inc	r0
      00029A F6               [12]  962 	mov	@r0,a
      00029B 08               [12]  963 	inc	r0
      00029C 76 80            [12]  964 	mov	@r0,#0x80
      00029E 08               [12]  965 	inc	r0
      00029F 76 3F            [12]  966 	mov	@r0,#0x3f
      0002A1 80 0D            [24]  967 	sjmp	00114$
      0002A3                        968 00113$:
                           0001EC   969 	C$fuzzy.h$644$2_0$46 ==.
                                    970 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:644: : LEVEL_LO;
      0002A3 E5 0E            [12]  971 	mov	a,_bp
      0002A5 24 05            [12]  972 	add	a,#0x05
      0002A7 F8               [12]  973 	mov	r0,a
      0002A8 E4               [12]  974 	clr	a
      0002A9 F6               [12]  975 	mov	@r0,a
      0002AA 08               [12]  976 	inc	r0
      0002AB F6               [12]  977 	mov	@r0,a
      0002AC 08               [12]  978 	inc	r0
      0002AD F6               [12]  979 	mov	@r0,a
      0002AE 08               [12]  980 	inc	r0
      0002AF F6               [12]  981 	mov	@r0,a
      0002B0                        982 00114$:
      0002B0 E5 0E            [12]  983 	mov	a,_bp
      0002B2 24 05            [12]  984 	add	a,#0x05
      0002B4 F8               [12]  985 	mov	r0,a
      0002B5 86 04            [24]  986 	mov	ar4,@r0
      0002B7 08               [12]  987 	inc	r0
      0002B8 86 05            [24]  988 	mov	ar5,@r0
      0002BA 08               [12]  989 	inc	r0
      0002BB 86 06            [24]  990 	mov	ar6,@r0
      0002BD 08               [12]  991 	inc	r0
      0002BE 86 07            [24]  992 	mov	ar7,@r0
      0002C0 02 03 BB         [24]  993 	ljmp	00108$
      0002C3                        994 00104$:
                           00020C   995 	C$fuzzy.h$648$1_0$43 ==.
                                    996 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:648: (value - lower_boundary) /
      0002C3 E5 0E            [12]  997 	mov	a,_bp
      0002C5 24 FA            [12]  998 	add	a,#0xfa
      0002C7 F8               [12]  999 	mov	r0,a
      0002C8 E6               [12] 1000 	mov	a,@r0
      0002C9 C0 E0            [24] 1001 	push	acc
      0002CB 08               [12] 1002 	inc	r0
      0002CC E6               [12] 1003 	mov	a,@r0
      0002CD C0 E0            [24] 1004 	push	acc
      0002CF 08               [12] 1005 	inc	r0
      0002D0 E6               [12] 1006 	mov	a,@r0
      0002D1 C0 E0            [24] 1007 	push	acc
      0002D3 08               [12] 1008 	inc	r0
      0002D4 E6               [12] 1009 	mov	a,@r0
      0002D5 C0 E0            [24] 1010 	push	acc
                           000220  1011 	C$fuzzy.h$649$1_0$43 ==.
                                   1012 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:649: (upper_boundary - lower_boundary);
      0002D7 E5 0E            [12] 1013 	mov	a,_bp
      0002D9 24 F2            [12] 1014 	add	a,#0xf2
      0002DB F8               [12] 1015 	mov	r0,a
      0002DC 86 82            [24] 1016 	mov	dpl, @r0
      0002DE 08               [12] 1017 	inc	r0
      0002DF 86 83            [24] 1018 	mov	dph, @r0
      0002E1 08               [12] 1019 	inc	r0
      0002E2 86 F0            [24] 1020 	mov	b, @r0
      0002E4 08               [12] 1021 	inc	r0
      0002E5 E6               [12] 1022 	mov	a, @r0
      0002E6 12 0D 0A         [24] 1023 	lcall	___fssub
      0002E9 AF 82            [24] 1024 	mov	r7, dpl
      0002EB AE 83            [24] 1025 	mov	r6, dph
      0002ED AD F0            [24] 1026 	mov	r5, b
      0002EF FC               [12] 1027 	mov	r4, a
      0002F0 E5 81            [12] 1028 	mov	a,sp
      0002F2 24 FC            [12] 1029 	add	a,#0xfc
      0002F4 F5 81            [12] 1030 	mov	sp,a
      0002F6 C0 07            [24] 1031 	push	ar7
      0002F8 C0 06            [24] 1032 	push	ar6
      0002FA C0 05            [24] 1033 	push	ar5
      0002FC C0 04            [24] 1034 	push	ar4
      0002FE E5 0E            [12] 1035 	mov	a,_bp
      000300 24 FA            [12] 1036 	add	a,#0xfa
      000302 F8               [12] 1037 	mov	r0,a
      000303 E6               [12] 1038 	mov	a,@r0
      000304 C0 E0            [24] 1039 	push	acc
      000306 08               [12] 1040 	inc	r0
      000307 E6               [12] 1041 	mov	a,@r0
      000308 C0 E0            [24] 1042 	push	acc
      00030A 08               [12] 1043 	inc	r0
      00030B E6               [12] 1044 	mov	a,@r0
      00030C C0 E0            [24] 1045 	push	acc
      00030E 08               [12] 1046 	inc	r0
      00030F E6               [12] 1047 	mov	a,@r0
      000310 C0 E0            [24] 1048 	push	acc
      000312 E5 0E            [12] 1049 	mov	a,_bp
      000314 24 F6            [12] 1050 	add	a,#0xf6
      000316 F8               [12] 1051 	mov	r0,a
      000317 86 82            [24] 1052 	mov	dpl, @r0
      000319 08               [12] 1053 	inc	r0
      00031A 86 83            [24] 1054 	mov	dph, @r0
      00031C 08               [12] 1055 	inc	r0
      00031D 86 F0            [24] 1056 	mov	b, @r0
      00031F 08               [12] 1057 	inc	r0
      000320 E6               [12] 1058 	mov	a, @r0
      000321 12 0D 0A         [24] 1059 	lcall	___fssub
      000324 A8 0E            [24] 1060 	mov	r0,_bp
      000326 08               [12] 1061 	inc	r0
      000327 A6 82            [24] 1062 	mov	@r0, dpl
      000329 08               [12] 1063 	inc	r0
      00032A A6 83            [24] 1064 	mov	@r0, dph
      00032C 08               [12] 1065 	inc	r0
      00032D A6 F0            [24] 1066 	mov	@r0, b
      00032F 08               [12] 1067 	inc	r0
      000330 F6               [12] 1068 	mov	@r0,a
      000331 E5 81            [12] 1069 	mov	a,sp
      000333 24 FC            [12] 1070 	add	a,#0xfc
      000335 F5 81            [12] 1071 	mov	sp,a
      000337 D0 04            [24] 1072 	pop	ar4
      000339 D0 05            [24] 1073 	pop	ar5
      00033B D0 06            [24] 1074 	pop	ar6
      00033D D0 07            [24] 1075 	pop	ar7
      00033F A8 0E            [24] 1076 	mov	r0,_bp
      000341 08               [12] 1077 	inc	r0
      000342 E6               [12] 1078 	mov	a,@r0
      000343 C0 E0            [24] 1079 	push	acc
      000345 08               [12] 1080 	inc	r0
      000346 E6               [12] 1081 	mov	a,@r0
      000347 C0 E0            [24] 1082 	push	acc
      000349 08               [12] 1083 	inc	r0
      00034A E6               [12] 1084 	mov	a,@r0
      00034B C0 E0            [24] 1085 	push	acc
      00034D 08               [12] 1086 	inc	r0
      00034E E6               [12] 1087 	mov	a,@r0
      00034F C0 E0            [24] 1088 	push	acc
                           00029A  1089 	C$fuzzy.h$652$1_0$43 ==.
                                   1090 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:652: ramp_up
      000351 8F 82            [24] 1091 	mov	dpl, r7
      000353 8E 83            [24] 1092 	mov	dph, r6
      000355 8D F0            [24] 1093 	mov	b, r5
      000357 EC               [12] 1094 	mov	a, r4
      000358 12 0F 91         [24] 1095 	lcall	___fsdiv
      00035B AF 82            [24] 1096 	mov	r7, dpl
      00035D AE 83            [24] 1097 	mov	r6, dph
      00035F AD F0            [24] 1098 	mov	r5, b
      000361 FC               [12] 1099 	mov	r4, a
      000362 E5 81            [12] 1100 	mov	a,sp
      000364 24 FC            [12] 1101 	add	a,#0xfc
      000366 F5 81            [12] 1102 	mov	sp,a
      000368 E5 0E            [12] 1103 	mov	a,_bp
      00036A 24 F1            [12] 1104 	add	a,#0xf1
      00036C F8               [12] 1105 	mov	r0,a
      00036D E6               [12] 1106 	mov	a,@r0
      00036E 60 12            [24] 1107 	jz	00115$
                           0002B9  1108 	C$fuzzy.h$653$2_0$47 ==.
                                   1109 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:653: ? normalized
      000370 E5 0E            [12] 1110 	mov	a,_bp
      000372 24 05            [12] 1111 	add	a,#0x05
      000374 F8               [12] 1112 	mov	r0,a
      000375 A6 07            [24] 1113 	mov	@r0,ar7
      000377 08               [12] 1114 	inc	r0
      000378 A6 06            [24] 1115 	mov	@r0,ar6
      00037A 08               [12] 1116 	inc	r0
      00037B A6 05            [24] 1117 	mov	@r0,ar5
      00037D 08               [12] 1118 	inc	r0
      00037E A6 04            [24] 1119 	mov	@r0,ar4
      000380 80 29            [24] 1120 	sjmp	00116$
      000382                       1121 00115$:
                           0002CB  1122 	C$fuzzy.h$654$1_0$43 ==.
                                   1123 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:654: : LEVEL_HI - normalized;
      000382 C0 07            [24] 1124 	push	ar7
      000384 C0 06            [24] 1125 	push	ar6
      000386 C0 05            [24] 1126 	push	ar5
      000388 C0 04            [24] 1127 	push	ar4
      00038A 90 00 00         [24] 1128 	mov	dptr,#0x0000
      00038D 75 F0 80         [24] 1129 	mov	b, #0x80
      000390 74 3F            [12] 1130 	mov	a, #0x3f
      000392 12 0D 0A         [24] 1131 	lcall	___fssub
      000395 C8               [12] 1132 	xch	a,r0
      000396 E5 0E            [12] 1133 	mov	a,_bp
      000398 24 05            [12] 1134 	add	a,#0x05
      00039A C8               [12] 1135 	xch	a,r0
      00039B A6 82            [24] 1136 	mov	@r0, dpl
      00039D 08               [12] 1137 	inc	r0
      00039E A6 83            [24] 1138 	mov	@r0, dph
      0003A0 08               [12] 1139 	inc	r0
      0003A1 A6 F0            [24] 1140 	mov	@r0, b
      0003A3 08               [12] 1141 	inc	r0
      0003A4 F6               [12] 1142 	mov	@r0,a
      0003A5 E5 81            [12] 1143 	mov	a,sp
      0003A7 24 FC            [12] 1144 	add	a,#0xfc
      0003A9 F5 81            [12] 1145 	mov	sp,a
      0003AB                       1146 00116$:
      0003AB E5 0E            [12] 1147 	mov	a,_bp
      0003AD 24 05            [12] 1148 	add	a,#0x05
      0003AF F8               [12] 1149 	mov	r0,a
      0003B0 86 04            [24] 1150 	mov	ar4,@r0
      0003B2 08               [12] 1151 	inc	r0
      0003B3 86 05            [24] 1152 	mov	ar5,@r0
      0003B5 08               [12] 1153 	inc	r0
      0003B6 86 06            [24] 1154 	mov	ar6,@r0
      0003B8 08               [12] 1155 	inc	r0
      0003B9 86 07            [24] 1156 	mov	ar7,@r0
      0003BB                       1157 00108$:
                           000304  1158 	C$fuzzy.h$658$1_0$43 ==.
                                   1159 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:658: result,
      0003BB E5 0E            [12] 1160 	mov	a,_bp
      0003BD 24 F0            [12] 1161 	add	a,#0xf0
      0003BF F8               [12] 1162 	mov	r0,a
      0003C0 E6               [12] 1163 	mov	a,@r0
      0003C1 C0 E0            [24] 1164 	push	acc
      0003C3 8C 82            [24] 1165 	mov	dpl, r4
      0003C5 8D 83            [24] 1166 	mov	dph, r5
      0003C7 8E F0            [24] 1167 	mov	b, r6
      0003C9 EF               [12] 1168 	mov	a, r7
      0003CA 12 01 34         [24] 1169 	lcall	_fuzzy_apply_hedge
      0003CD AC 82            [24] 1170 	mov	r4, dpl
      0003CF AD 83            [24] 1171 	mov	r5, dph
      0003D1 AE F0            [24] 1172 	mov	r6, b
      0003D3 FF               [12] 1173 	mov	r7, a
      0003D4 15 81            [12] 1174 	dec	sp
      0003D6 8C 82            [24] 1175 	mov	dpl, r4
      0003D8 8D 83            [24] 1176 	mov	dph, r5
      0003DA 8E F0            [24] 1177 	mov	b, r6
      0003DC EF               [12] 1178 	mov	a, r7
      0003DD                       1179 00109$:
                           000326  1180 	C$fuzzy.h$661$1_0$43 ==.
                                   1181 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:661: }
      0003DD 85 0E 81         [24] 1182 	mov	sp,_bp
      0003E0 D0 0E            [24] 1183 	pop	_bp
                           00032B  1184 	C$fuzzy.h$661$1_0$43 ==.
                           00032B  1185 	XG$fuzzy_ramp$0$0 ==.
      0003E2 22               [24] 1186 	ret
                                   1187 ;------------------------------------------------------------
                                   1188 ;Allocation info for local variables in function 'fuzzy_rules_create'
                                   1189 ;------------------------------------------------------------
                                   1190 ;rules         Allocated to registers r5 r6 r7 
                                   1191 ;------------------------------------------------------------
                           00032C  1192 	G$fuzzy_rules_create$0$0 ==.
                           00032C  1193 	C$fuzzy.h$1079$1_0$49 ==.
                                   1194 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1079: void fuzzy_rules_create(
                                   1195 ;	-----------------------------------------
                                   1196 ;	 function fuzzy_rules_create
                                   1197 ;	-----------------------------------------
      0003E3                       1198 _fuzzy_rules_create:
      0003E3 AD 82            [24] 1199 	mov	r5, dpl
      0003E5 AE 83            [24] 1200 	mov	r6, dph
      0003E7 AF F0            [24] 1201 	mov	r7, b
                           000332  1202 	C$fuzzy.h$1083$1_0$49 ==.
                                   1203 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1083: if (rules == NULL) {
      0003E9 ED               [12] 1204 	mov	a,r5
      0003EA 4E               [12] 1205 	orl	a,r6
      0003EB 70 02            [24] 1206 	jnz	00102$
                           000336  1207 	C$fuzzy.h$1084$2_0$50 ==.
                                   1208 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1084: return;
      0003ED 80 15            [24] 1209 	sjmp	00103$
      0003EF                       1210 00102$:
                           000338  1211 	C$fuzzy.h$1087$1_0$49 ==.
                                   1212 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1087: rules->count = 0;
      0003EF 74 0C            [12] 1213 	mov	a,#0x0c
      0003F1 2D               [12] 1214 	add	a, r5
      0003F2 FD               [12] 1215 	mov	r5,a
      0003F3 E4               [12] 1216 	clr	a
      0003F4 3E               [12] 1217 	addc	a, r6
      0003F5 FE               [12] 1218 	mov	r6,a
      0003F6 8D 82            [24] 1219 	mov	dpl,r5
      0003F8 8E 83            [24] 1220 	mov	dph,r6
      0003FA 8F F0            [24] 1221 	mov	b,r7
      0003FC E4               [12] 1222 	clr	a
      0003FD 12 0E 19         [24] 1223 	lcall	__gptrput
      000400 A3               [24] 1224 	inc	dptr
      000401 12 0E 19         [24] 1225 	lcall	__gptrput
      000404                       1226 00103$:
                           00034D  1227 	C$fuzzy.h$1088$1_0$49 ==.
                                   1228 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1088: }
                           00034D  1229 	C$fuzzy.h$1088$1_0$49 ==.
                           00034D  1230 	XG$fuzzy_rules_create$0$0 ==.
      000404 22               [24] 1231 	ret
                                   1232 ;------------------------------------------------------------
                                   1233 ;Allocation info for local variables in function 'fuzzy_rules_add'
                                   1234 ;------------------------------------------------------------
                                   1235 ;name          Allocated to stack - _bp -5 +3 
                                   1236 ;value         Allocated to stack - _bp -9 +4 
                                   1237 ;output_function Allocated to stack - _bp -11 +2 
                                   1238 ;rules         Allocated to stack - _bp +1 +3 
                                   1239 ;index         Allocated to registers 
                                   1240 ;sloc0         Allocated to stack - _bp +6 +2 
                                   1241 ;sloc1         Allocated to stack - _bp +4 +3 
                                   1242 ;sloc2         Allocated to stack - _bp +7 +3 
                                   1243 ;------------------------------------------------------------
                           00034E  1244 	G$fuzzy_rules_add$0$0 ==.
                           00034E  1245 	C$fuzzy.h$1091$1_0$52 ==.
                                   1246 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1091: bool fuzzy_rules_add(
                                   1247 ;	-----------------------------------------
                                   1248 ;	 function fuzzy_rules_add
                                   1249 ;	-----------------------------------------
      000405                       1250 _fuzzy_rules_add:
      000405 C0 0E            [24] 1251 	push	_bp
      000407 85 81 0E         [24] 1252 	mov	_bp,sp
      00040A C0 82            [24] 1253 	push	dpl
      00040C C0 83            [24] 1254 	push	dph
      00040E C0 F0            [24] 1255 	push	b
      000410 E5 81            [12] 1256 	mov	a,sp
      000412 24 06            [12] 1257 	add	a,#0x06
      000414 F5 81            [12] 1258 	mov	sp,a
                           00035F  1259 	C$fuzzy.h$1101$1_0$52 ==.
                                   1260 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1101: rules == NULL ||
      000416 A8 0E            [24] 1261 	mov	r0,_bp
      000418 08               [12] 1262 	inc	r0
      000419 E6               [12] 1263 	mov	a,@r0
      00041A 08               [12] 1264 	inc	r0
      00041B 46               [12] 1265 	orl	a,@r0
      00041C 60 0A            [24] 1266 	jz	00101$
                           000367  1267 	C$fuzzy.h$1102$1_0$52 ==.
                                   1268 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1102: output_function == NULL
      00041E E5 0E            [12] 1269 	mov	a,_bp
      000420 24 F5            [12] 1270 	add	a,#0xf5
      000422 F8               [12] 1271 	mov	r0,a
      000423 E6               [12] 1272 	mov	a,@r0
      000424 08               [12] 1273 	inc	r0
      000425 46               [12] 1274 	orl	a,@r0
      000426 70 06            [24] 1275 	jnz	00102$
      000428                       1276 00101$:
                           000371  1277 	C$fuzzy.h$1104$2_0$53 ==.
                                   1278 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1104: return false;
      000428 75 82 00         [24] 1279 	mov	dpl, #0x00
      00042B 02 05 2C         [24] 1280 	ljmp	00106$
      00042E                       1281 00102$:
                           000377  1282 	C$fuzzy.h$1107$1_0$52 ==.
                                   1283 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1107: if (rules->count >= FUZZY_MAX_RULES) {
      00042E A8 0E            [24] 1284 	mov	r0,_bp
      000430 08               [12] 1285 	inc	r0
      000431 E5 0E            [12] 1286 	mov	a,_bp
      000433 24 07            [12] 1287 	add	a,#0x07
      000435 F9               [12] 1288 	mov	r1,a
      000436 74 0C            [12] 1289 	mov	a,#0x0c
      000438 26               [12] 1290 	add	a, @r0
      000439 F7               [12] 1291 	mov	@r1,a
      00043A E4               [12] 1292 	clr	a
      00043B 08               [12] 1293 	inc	r0
      00043C 36               [12] 1294 	addc	a, @r0
      00043D 09               [12] 1295 	inc	r1
      00043E F7               [12] 1296 	mov	@r1,a
      00043F 08               [12] 1297 	inc	r0
      000440 E6               [12] 1298 	mov	a,@r0
      000441 09               [12] 1299 	inc	r1
      000442 F7               [12] 1300 	mov	@r1,a
      000443 E5 0E            [12] 1301 	mov	a,_bp
      000445 24 07            [12] 1302 	add	a,#0x07
      000447 F8               [12] 1303 	mov	r0,a
      000448 86 82            [24] 1304 	mov	dpl,@r0
      00044A 08               [12] 1305 	inc	r0
      00044B 86 83            [24] 1306 	mov	dph,@r0
      00044D 08               [12] 1307 	inc	r0
      00044E 86 F0            [24] 1308 	mov	b,@r0
      000450 12 10 54         [24] 1309 	lcall	__gptrget
      000453 FF               [12] 1310 	mov	r7,a
      000454 A3               [24] 1311 	inc	dptr
      000455 12 10 54         [24] 1312 	lcall	__gptrget
      000458 FE               [12] 1313 	mov	r6,a
      000459 C3               [12] 1314 	clr	c
      00045A EF               [12] 1315 	mov	a,r7
      00045B 94 02            [12] 1316 	subb	a,#0x02
      00045D EE               [12] 1317 	mov	a,r6
      00045E 94 00            [12] 1318 	subb	a,#0x00
      000460 40 06            [24] 1319 	jc	00105$
                           0003AB  1320 	C$fuzzy.h$1116$2_0$54 ==.
                                   1321 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1116: return false;
      000462 75 82 00         [24] 1322 	mov	dpl, #0x00
      000465 02 05 2C         [24] 1323 	ljmp	00106$
      000468                       1324 00105$:
                           0003B1  1325 	C$fuzzy.h$1133$1_0$52 ==.
                                   1326 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1133: rules->rules[index].value =
      000468 C0 07            [24] 1327 	push	ar7
      00046A C0 06            [24] 1328 	push	ar6
      00046C 90 00 06         [24] 1329 	mov	dptr,#0x0006
      00046F 12 0E 64         [24] 1330 	lcall	__mulint
      000472 AB 82            [24] 1331 	mov	r3, dpl
      000474 AA 83            [24] 1332 	mov	r2, dph
      000476 15 81            [12] 1333 	dec	sp
      000478 15 81            [12] 1334 	dec	sp
      00047A A8 0E            [24] 1335 	mov	r0,_bp
      00047C 08               [12] 1336 	inc	r0
      00047D E5 0E            [12] 1337 	mov	a,_bp
      00047F 24 04            [12] 1338 	add	a,#0x04
      000481 F9               [12] 1339 	mov	r1,a
      000482 EB               [12] 1340 	mov	a,r3
      000483 26               [12] 1341 	add	a, @r0
      000484 F7               [12] 1342 	mov	@r1,a
      000485 EA               [12] 1343 	mov	a,r2
      000486 08               [12] 1344 	inc	r0
      000487 36               [12] 1345 	addc	a, @r0
      000488 09               [12] 1346 	inc	r1
      000489 F7               [12] 1347 	mov	@r1,a
      00048A 08               [12] 1348 	inc	r0
      00048B E6               [12] 1349 	mov	a,@r0
      00048C 09               [12] 1350 	inc	r1
      00048D F7               [12] 1351 	mov	@r1,a
                           0003D7  1352 	C$fuzzy.h$1134$1_0$52 ==.
                                   1353 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1134: fuzzy_clamp(value);
      00048E E5 0E            [12] 1354 	mov	a,_bp
      000490 24 F7            [12] 1355 	add	a,#0xf7
      000492 F8               [12] 1356 	mov	r0,a
      000493 86 82            [24] 1357 	mov	dpl, @r0
      000495 08               [12] 1358 	inc	r0
      000496 86 83            [24] 1359 	mov	dph, @r0
      000498 08               [12] 1360 	inc	r0
      000499 86 F0            [24] 1361 	mov	b, @r0
      00049B 08               [12] 1362 	inc	r0
      00049C E6               [12] 1363 	mov	a, @r0
      00049D C0 03            [24] 1364 	push	ar3
      00049F C0 02            [24] 1365 	push	ar2
      0004A1 12 00 B7         [24] 1366 	lcall	_fuzzy_clamp
      0004A4 AD 82            [24] 1367 	mov	r5, dpl
      0004A6 AE 83            [24] 1368 	mov	r6, dph
      0004A8 AC F0            [24] 1369 	mov	r4, b
      0004AA FF               [12] 1370 	mov	r7, a
      0004AB D0 02            [24] 1371 	pop	ar2
      0004AD D0 03            [24] 1372 	pop	ar3
      0004AF E5 0E            [12] 1373 	mov	a,_bp
      0004B1 24 04            [12] 1374 	add	a,#0x04
      0004B3 F8               [12] 1375 	mov	r0,a
      0004B4 86 82            [24] 1376 	mov	dpl,@r0
      0004B6 08               [12] 1377 	inc	r0
      0004B7 86 83            [24] 1378 	mov	dph,@r0
      0004B9 08               [12] 1379 	inc	r0
      0004BA 86 F0            [24] 1380 	mov	b,@r0
      0004BC ED               [12] 1381 	mov	a,r5
      0004BD 12 0E 19         [24] 1382 	lcall	__gptrput
      0004C0 A3               [24] 1383 	inc	dptr
      0004C1 EE               [12] 1384 	mov	a,r6
      0004C2 12 0E 19         [24] 1385 	lcall	__gptrput
      0004C5 A3               [24] 1386 	inc	dptr
      0004C6 EC               [12] 1387 	mov	a,r4
      0004C7 12 0E 19         [24] 1388 	lcall	__gptrput
      0004CA A3               [24] 1389 	inc	dptr
      0004CB EF               [12] 1390 	mov	a,r7
      0004CC 12 0E 19         [24] 1391 	lcall	__gptrput
                           000418  1392 	C$fuzzy.h$1136$1_0$52 ==.
                                   1393 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1136: rules->rules[index].output_function =
      0004CF A8 0E            [24] 1394 	mov	r0,_bp
      0004D1 08               [12] 1395 	inc	r0
      0004D2 EB               [12] 1396 	mov	a,r3
      0004D3 26               [12] 1397 	add	a, @r0
      0004D4 FD               [12] 1398 	mov	r5,a
      0004D5 EA               [12] 1399 	mov	a,r2
      0004D6 08               [12] 1400 	inc	r0
      0004D7 36               [12] 1401 	addc	a, @r0
      0004D8 FE               [12] 1402 	mov	r6,a
      0004D9 08               [12] 1403 	inc	r0
      0004DA 86 07            [24] 1404 	mov	ar7,@r0
      0004DC 74 04            [12] 1405 	mov	a,#0x04
      0004DE 2D               [12] 1406 	add	a, r5
      0004DF FD               [12] 1407 	mov	r5,a
      0004E0 E4               [12] 1408 	clr	a
      0004E1 3E               [12] 1409 	addc	a, r6
      0004E2 FE               [12] 1410 	mov	r6,a
      0004E3 8D 82            [24] 1411 	mov	dpl,r5
      0004E5 8E 83            [24] 1412 	mov	dph,r6
      0004E7 8F F0            [24] 1413 	mov	b,r7
      0004E9 E5 0E            [12] 1414 	mov	a,_bp
      0004EB 24 F5            [12] 1415 	add	a,#0xf5
      0004ED F8               [12] 1416 	mov	r0,a
      0004EE E6               [12] 1417 	mov	a,@r0
      0004EF 12 0E 19         [24] 1418 	lcall	__gptrput
      0004F2 A3               [24] 1419 	inc	dptr
      0004F3 08               [12] 1420 	inc	r0
      0004F4 E6               [12] 1421 	mov	a,@r0
      0004F5 12 0E 19         [24] 1422 	lcall	__gptrput
                           000441  1423 	C$fuzzy.h$1139$1_0$52 ==.
                                   1424 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1139: rules->count++;
      0004F8 E5 0E            [12] 1425 	mov	a,_bp
      0004FA 24 07            [12] 1426 	add	a,#0x07
      0004FC F8               [12] 1427 	mov	r0,a
      0004FD 86 82            [24] 1428 	mov	dpl,@r0
      0004FF 08               [12] 1429 	inc	r0
      000500 86 83            [24] 1430 	mov	dph,@r0
      000502 08               [12] 1431 	inc	r0
      000503 86 F0            [24] 1432 	mov	b,@r0
      000505 12 10 54         [24] 1433 	lcall	__gptrget
      000508 FE               [12] 1434 	mov	r6,a
      000509 A3               [24] 1435 	inc	dptr
      00050A 12 10 54         [24] 1436 	lcall	__gptrget
      00050D FF               [12] 1437 	mov	r7,a
      00050E 0E               [12] 1438 	inc	r6
      00050F BE 00 01         [24] 1439 	cjne	r6,#0x00,00123$
      000512 0F               [12] 1440 	inc	r7
      000513                       1441 00123$:
      000513 E5 0E            [12] 1442 	mov	a,_bp
      000515 24 07            [12] 1443 	add	a,#0x07
      000517 F8               [12] 1444 	mov	r0,a
      000518 86 82            [24] 1445 	mov	dpl,@r0
      00051A 08               [12] 1446 	inc	r0
      00051B 86 83            [24] 1447 	mov	dph,@r0
      00051D 08               [12] 1448 	inc	r0
      00051E 86 F0            [24] 1449 	mov	b,@r0
      000520 EE               [12] 1450 	mov	a,r6
      000521 12 0E 19         [24] 1451 	lcall	__gptrput
      000524 A3               [24] 1452 	inc	dptr
      000525 EF               [12] 1453 	mov	a,r7
      000526 12 0E 19         [24] 1454 	lcall	__gptrput
                           000472  1455 	C$fuzzy.h$1141$1_0$52 ==.
                                   1456 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1141: return true;
      000529 75 82 01         [24] 1457 	mov	dpl, #0x01
      00052C                       1458 00106$:
                           000475  1459 	C$fuzzy.h$1142$1_0$52 ==.
                                   1460 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1142: }
      00052C 85 0E 81         [24] 1461 	mov	sp,_bp
      00052F D0 0E            [24] 1462 	pop	_bp
                           00047A  1463 	C$fuzzy.h$1142$1_0$52 ==.
                           00047A  1464 	XG$fuzzy_rules_add$0$0 ==.
      000531 22               [24] 1465 	ret
                                   1466 ;------------------------------------------------------------
                                   1467 ;Allocation info for local variables in function 'fuzzy_rules_cog'
                                   1468 ;------------------------------------------------------------
                                   1469 ;lower         Allocated to stack - _bp -6 +4 
                                   1470 ;upper         Allocated to stack - _bp -10 +4 
                                   1471 ;step          Allocated to stack - _bp -14 +4 
                                   1472 ;rules         Allocated to stack - _bp +1 +3 
                                   1473 ;weighted_sum  Allocated to stack - _bp +14 +4 
                                   1474 ;height_sum    Allocated to stack - _bp +18 +4 
                                   1475 ;value         Allocated to stack - _bp +22 +4 
                                   1476 ;aggregated_height Allocated to stack - _bp +26 +4 
                                   1477 ;output_membership Allocated to stack - _bp +30 +4 
                                   1478 ;clipped_height Allocated to stack - _bp +34 +4 
                                   1479 ;i             Allocated to stack - _bp +38 +2 
                                   1480 ;sloc0         Allocated to stack - _bp +4 +3 
                                   1481 ;sloc1         Allocated to stack - _bp +7 +3 
                                   1482 ;sloc2         Allocated to stack - _bp +10 +4 
                                   1483 ;------------------------------------------------------------
                           00047B  1484 	G$fuzzy_rules_cog$0$0 ==.
                           00047B  1485 	C$fuzzy.h$1175$1_0$56 ==.
                                   1486 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1175: float fuzzy_rules_cog(
                                   1487 ;	-----------------------------------------
                                   1488 ;	 function fuzzy_rules_cog
                                   1489 ;	-----------------------------------------
      000532                       1490 _fuzzy_rules_cog:
      000532 C0 0E            [24] 1491 	push	_bp
      000534 85 81 0E         [24] 1492 	mov	_bp,sp
      000537 C0 82            [24] 1493 	push	dpl
      000539 C0 83            [24] 1494 	push	dph
      00053B C0 F0            [24] 1495 	push	b
      00053D E5 81            [12] 1496 	mov	a,sp
      00053F 24 24            [12] 1497 	add	a,#0x24
      000541 F5 81            [12] 1498 	mov	sp,a
                           00048C  1499 	C$fuzzy.h$1191$1_0$56 ==.
                                   1500 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1191: rules == NULL ||
      000543 A8 0E            [24] 1501 	mov	r0,_bp
      000545 08               [12] 1502 	inc	r0
      000546 E6               [12] 1503 	mov	a,@r0
      000547 08               [12] 1504 	inc	r0
      000548 46               [12] 1505 	orl	a,@r0
      000549 70 03            [24] 1506 	jnz	00183$
      00054B 02 05 D7         [24] 1507 	ljmp	00101$
      00054E                       1508 00183$:
                           000497  1509 	C$fuzzy.h$1192$1_0$56 ==.
                                   1510 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1192: rules->count == 0 ||
      00054E A8 0E            [24] 1511 	mov	r0,_bp
      000550 08               [12] 1512 	inc	r0
      000551 E5 0E            [12] 1513 	mov	a,_bp
      000553 24 04            [12] 1514 	add	a,#0x04
      000555 F9               [12] 1515 	mov	r1,a
      000556 74 0C            [12] 1516 	mov	a,#0x0c
      000558 26               [12] 1517 	add	a, @r0
      000559 F7               [12] 1518 	mov	@r1,a
      00055A E4               [12] 1519 	clr	a
      00055B 08               [12] 1520 	inc	r0
      00055C 36               [12] 1521 	addc	a, @r0
      00055D 09               [12] 1522 	inc	r1
      00055E F7               [12] 1523 	mov	@r1,a
      00055F 08               [12] 1524 	inc	r0
      000560 E6               [12] 1525 	mov	a,@r0
      000561 09               [12] 1526 	inc	r1
      000562 F7               [12] 1527 	mov	@r1,a
      000563 E5 0E            [12] 1528 	mov	a,_bp
      000565 24 04            [12] 1529 	add	a,#0x04
      000567 F8               [12] 1530 	mov	r0,a
      000568 86 82            [24] 1531 	mov	dpl,@r0
      00056A 08               [12] 1532 	inc	r0
      00056B 86 83            [24] 1533 	mov	dph,@r0
      00056D 08               [12] 1534 	inc	r0
      00056E 86 F0            [24] 1535 	mov	b,@r0
      000570 12 10 54         [24] 1536 	lcall	__gptrget
      000573 FE               [12] 1537 	mov	r6,a
      000574 A3               [24] 1538 	inc	dptr
      000575 12 10 54         [24] 1539 	lcall	__gptrget
      000578 4E               [12] 1540 	orl	a,r6
      000579 60 5C            [24] 1541 	jz	00101$
                           0004C4  1542 	C$fuzzy.h$1193$1_0$56 ==.
                                   1543 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1193: lower > upper ||
      00057B E5 0E            [12] 1544 	mov	a,_bp
      00057D 24 FA            [12] 1545 	add	a,#0xfa
      00057F F8               [12] 1546 	mov	r0,a
      000580 E6               [12] 1547 	mov	a,@r0
      000581 C0 E0            [24] 1548 	push	acc
      000583 08               [12] 1549 	inc	r0
      000584 E6               [12] 1550 	mov	a,@r0
      000585 C0 E0            [24] 1551 	push	acc
      000587 08               [12] 1552 	inc	r0
      000588 E6               [12] 1553 	mov	a,@r0
      000589 C0 E0            [24] 1554 	push	acc
      00058B 08               [12] 1555 	inc	r0
      00058C E6               [12] 1556 	mov	a,@r0
      00058D C0 E0            [24] 1557 	push	acc
      00058F E5 0E            [12] 1558 	mov	a,_bp
      000591 24 F6            [12] 1559 	add	a,#0xf6
      000593 F8               [12] 1560 	mov	r0,a
      000594 86 82            [24] 1561 	mov	dpl, @r0
      000596 08               [12] 1562 	inc	r0
      000597 86 83            [24] 1563 	mov	dph, @r0
      000599 08               [12] 1564 	inc	r0
      00059A 86 F0            [24] 1565 	mov	b, @r0
      00059C 08               [12] 1566 	inc	r0
      00059D E6               [12] 1567 	mov	a, @r0
      00059E 12 0E 34         [24] 1568 	lcall	___fslt
      0005A1 AF 82            [24] 1569 	mov	r7, dpl
      0005A3 E5 81            [12] 1570 	mov	a,sp
      0005A5 24 FC            [12] 1571 	add	a,#0xfc
      0005A7 F5 81            [12] 1572 	mov	sp,a
      0005A9 EF               [12] 1573 	mov	a,r7
      0005AA 70 2B            [24] 1574 	jnz	00101$
                           0004F5  1575 	C$fuzzy.h$1195$1_0$56 ==.
                                   1576 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1195: ) {
      0005AC E5 0E            [12] 1577 	mov	a,_bp
      0005AE 24 F2            [12] 1578 	add	a,#0xf2
      0005B0 F8               [12] 1579 	mov	r0,a
      0005B1 E6               [12] 1580 	mov	a,@r0
      0005B2 C0 E0            [24] 1581 	push	acc
      0005B4 08               [12] 1582 	inc	r0
      0005B5 E6               [12] 1583 	mov	a,@r0
      0005B6 C0 E0            [24] 1584 	push	acc
      0005B8 08               [12] 1585 	inc	r0
      0005B9 E6               [12] 1586 	mov	a,@r0
      0005BA C0 E0            [24] 1587 	push	acc
      0005BC 08               [12] 1588 	inc	r0
      0005BD E6               [12] 1589 	mov	a,@r0
      0005BE C0 E0            [24] 1590 	push	acc
      0005C0 90 00 00         [24] 1591 	mov	dptr,#0x0000
      0005C3 E4               [12] 1592 	clr	a
      0005C4 F5 F0            [12] 1593 	mov	b,a
      0005C6 12 0E 34         [24] 1594 	lcall	___fslt
      0005C9 E5 81            [12] 1595 	mov	a,sp
      0005CB 24 FC            [12] 1596 	add	a,#0xfc
      0005CD F5 81            [12] 1597 	mov	sp,a
      0005CF E5 82            [12] 1598 	mov	a, dpl
      0005D1 24 FF            [12] 1599 	add	a,#0xff
      0005D3 92 00            [24] 1600 	mov	b0,c
      0005D5 40 09            [24] 1601 	jc	00102$
      0005D7                       1602 00101$:
                           000520  1603 	C$fuzzy.h$1196$2_0$57 ==.
                                   1604 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1196: return 0.0f;
      0005D7 90 00 00         [24] 1605 	mov	dptr,#0x0000
      0005DA E4               [12] 1606 	clr	a
      0005DB F5 F0            [12] 1607 	mov	b,a
      0005DD 02 09 4F         [24] 1608 	ljmp	00116$
      0005E0                       1609 00102$:
                           000529  1610 	C$fuzzy.h$1199$1_0$56 ==.
                                   1611 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1199: weighted_sum = 0.0f;
      0005E0 E5 0E            [12] 1612 	mov	a,_bp
      0005E2 24 0E            [12] 1613 	add	a,#0x0e
      0005E4 F8               [12] 1614 	mov	r0,a
      0005E5 E4               [12] 1615 	clr	a
      0005E6 F6               [12] 1616 	mov	@r0,a
      0005E7 08               [12] 1617 	inc	r0
      0005E8 F6               [12] 1618 	mov	@r0,a
      0005E9 08               [12] 1619 	inc	r0
      0005EA F6               [12] 1620 	mov	@r0,a
      0005EB 08               [12] 1621 	inc	r0
      0005EC F6               [12] 1622 	mov	@r0,a
                           000536  1623 	C$fuzzy.h$1200$1_0$56 ==.
                                   1624 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1200: height_sum = 0.0f;
      0005ED E5 0E            [12] 1625 	mov	a,_bp
      0005EF 24 12            [12] 1626 	add	a,#0x12
      0005F1 F8               [12] 1627 	mov	r0,a
      0005F2 E4               [12] 1628 	clr	a
      0005F3 F6               [12] 1629 	mov	@r0,a
      0005F4 08               [12] 1630 	inc	r0
      0005F5 F6               [12] 1631 	mov	@r0,a
      0005F6 08               [12] 1632 	inc	r0
      0005F7 F6               [12] 1633 	mov	@r0,a
      0005F8 08               [12] 1634 	inc	r0
      0005F9 F6               [12] 1635 	mov	@r0,a
                           000543  1636 	C$fuzzy.h$1203$2_0$58 ==.
                                   1637 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1203: value = lower;
      0005FA E5 0E            [12] 1638 	mov	a,_bp
      0005FC 24 FA            [12] 1639 	add	a,#0xfa
      0005FE F8               [12] 1640 	mov	r0,a
      0005FF E5 0E            [12] 1641 	mov	a,_bp
      000601 24 16            [12] 1642 	add	a,#0x16
      000603 F9               [12] 1643 	mov	r1,a
      000604 E6               [12] 1644 	mov	a,@r0
      000605 F7               [12] 1645 	mov	@r1,a
      000606 08               [12] 1646 	inc	r0
      000607 E6               [12] 1647 	mov	a,@r0
      000608 09               [12] 1648 	inc	r1
      000609 F7               [12] 1649 	mov	@r1,a
      00060A 08               [12] 1650 	inc	r0
      00060B E6               [12] 1651 	mov	a,@r0
      00060C 09               [12] 1652 	inc	r1
      00060D F7               [12] 1653 	mov	@r1,a
      00060E 08               [12] 1654 	inc	r0
      00060F E6               [12] 1655 	mov	a,@r0
      000610 09               [12] 1656 	inc	r1
      000611 F7               [12] 1657 	mov	@r1,a
      000612 A8 0E            [24] 1658 	mov	r0,_bp
      000614 08               [12] 1659 	inc	r0
      000615 E5 0E            [12] 1660 	mov	a,_bp
      000617 24 07            [12] 1661 	add	a,#0x07
      000619 F9               [12] 1662 	mov	r1,a
      00061A E6               [12] 1663 	mov	a,@r0
      00061B F7               [12] 1664 	mov	@r1,a
      00061C 08               [12] 1665 	inc	r0
      00061D E6               [12] 1666 	mov	a,@r0
      00061E 09               [12] 1667 	inc	r1
      00061F F7               [12] 1668 	mov	@r1,a
      000620 08               [12] 1669 	inc	r0
      000621 E6               [12] 1670 	mov	a,@r0
      000622 09               [12] 1671 	inc	r1
      000623 F7               [12] 1672 	mov	@r1,a
      000624                       1673 00114$:
                           00056D  1674 	C$fuzzy.h$1204$1_0$56 ==.
                                   1675 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1204: value <= upper;
      000624 E5 0E            [12] 1676 	mov	a,_bp
      000626 24 16            [12] 1677 	add	a,#0x16
      000628 F8               [12] 1678 	mov	r0,a
      000629 E6               [12] 1679 	mov	a,@r0
      00062A C0 E0            [24] 1680 	push	acc
      00062C 08               [12] 1681 	inc	r0
      00062D E6               [12] 1682 	mov	a,@r0
      00062E C0 E0            [24] 1683 	push	acc
      000630 08               [12] 1684 	inc	r0
      000631 E6               [12] 1685 	mov	a,@r0
      000632 C0 E0            [24] 1686 	push	acc
      000634 08               [12] 1687 	inc	r0
      000635 E6               [12] 1688 	mov	a,@r0
      000636 C0 E0            [24] 1689 	push	acc
      000638 E5 0E            [12] 1690 	mov	a,_bp
      00063A 24 F6            [12] 1691 	add	a,#0xf6
      00063C F8               [12] 1692 	mov	r0,a
      00063D 86 82            [24] 1693 	mov	dpl, @r0
      00063F 08               [12] 1694 	inc	r0
      000640 86 83            [24] 1695 	mov	dph, @r0
      000642 08               [12] 1696 	inc	r0
      000643 86 F0            [24] 1697 	mov	b, @r0
      000645 08               [12] 1698 	inc	r0
      000646 E6               [12] 1699 	mov	a, @r0
      000647 12 0E 34         [24] 1700 	lcall	___fslt
      00064A E5 81            [12] 1701 	mov	a,sp
      00064C 24 FC            [12] 1702 	add	a,#0xfc
      00064E F5 81            [12] 1703 	mov	sp,a
      000650 E5 82            [12] 1704 	mov	a, dpl
      000652 24 FF            [12] 1705 	add	a,#0xff
      000654 92 00            [24] 1706 	mov	b0,c
      000656 50 03            [24] 1707 	jnc	00187$
      000658 02 08 F6         [24] 1708 	ljmp	00107$
      00065B                       1709 00187$:
                           0005A4  1710 	C$fuzzy.h$1208$3_0$59 ==.
                                   1711 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1208: LEVEL_LO;
      00065B E5 0E            [12] 1712 	mov	a,_bp
      00065D 24 1A            [12] 1713 	add	a,#0x1a
      00065F F8               [12] 1714 	mov	r0,a
      000660 E4               [12] 1715 	clr	a
      000661 F6               [12] 1716 	mov	@r0,a
      000662 08               [12] 1717 	inc	r0
      000663 F6               [12] 1718 	mov	@r0,a
      000664 08               [12] 1719 	inc	r0
      000665 F6               [12] 1720 	mov	@r0,a
      000666 08               [12] 1721 	inc	r0
      000667 F6               [12] 1722 	mov	@r0,a
                           0005B1  1723 	C$fuzzy.h$1211$1_0$56 ==.
                                   1724 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1211: i = 0;
      000668 E5 0E            [12] 1725 	mov	a,_bp
      00066A 24 26            [12] 1726 	add	a,#0x26
      00066C F8               [12] 1727 	mov	r0,a
      00066D E4               [12] 1728 	clr	a
      00066E F6               [12] 1729 	mov	@r0,a
      00066F 08               [12] 1730 	inc	r0
      000670 F6               [12] 1731 	mov	@r0,a
      000671 FA               [12] 1732 	mov	r2,a
      000672 FB               [12] 1733 	mov	r3,a
      000673                       1734 00111$:
                           0005BC  1735 	C$fuzzy.h$1212$1_0$56 ==.
                                   1736 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1212: i < rules->count;
      000673 C0 02            [24] 1737 	push	ar2
      000675 C0 03            [24] 1738 	push	ar3
      000677 E5 0E            [12] 1739 	mov	a,_bp
      000679 24 04            [12] 1740 	add	a,#0x04
      00067B F8               [12] 1741 	mov	r0,a
      00067C 86 82            [24] 1742 	mov	dpl,@r0
      00067E 08               [12] 1743 	inc	r0
      00067F 86 83            [24] 1744 	mov	dph,@r0
      000681 08               [12] 1745 	inc	r0
      000682 86 F0            [24] 1746 	mov	b,@r0
      000684 12 10 54         [24] 1747 	lcall	__gptrget
      000687 FA               [12] 1748 	mov	r2,a
      000688 A3               [24] 1749 	inc	dptr
      000689 12 10 54         [24] 1750 	lcall	__gptrget
      00068C FB               [12] 1751 	mov	r3,a
      00068D E5 0E            [12] 1752 	mov	a,_bp
      00068F 24 26            [12] 1753 	add	a,#0x26
      000691 F8               [12] 1754 	mov	r0,a
      000692 C3               [12] 1755 	clr	c
      000693 E6               [12] 1756 	mov	a,@r0
      000694 9A               [12] 1757 	subb	a,r2
      000695 08               [12] 1758 	inc	r0
      000696 E6               [12] 1759 	mov	a,@r0
      000697 9B               [12] 1760 	subb	a,r3
      000698 D0 03            [24] 1761 	pop	ar3
      00069A D0 02            [24] 1762 	pop	ar2
      00069C 40 03            [24] 1763 	jc	00188$
      00069E 02 08 18         [24] 1764 	ljmp	00106$
      0006A1                       1765 00188$:
                           0005EA  1766 	C$fuzzy.h$1216$1_0$56 ==.
                                   1767 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1216: rules->rules[i]
      0006A1 E5 0E            [12] 1768 	mov	a,_bp
      0006A3 24 07            [12] 1769 	add	a,#0x07
      0006A5 F8               [12] 1770 	mov	r0,a
      0006A6 EA               [12] 1771 	mov	a,r2
      0006A7 26               [12] 1772 	add	a, @r0
      0006A8 FD               [12] 1773 	mov	r5,a
      0006A9 EB               [12] 1774 	mov	a,r3
      0006AA 08               [12] 1775 	inc	r0
      0006AB 36               [12] 1776 	addc	a, @r0
      0006AC FE               [12] 1777 	mov	r6,a
      0006AD 08               [12] 1778 	inc	r0
      0006AE 86 07            [24] 1779 	mov	ar7,@r0
      0006B0 74 04            [12] 1780 	mov	a,#0x04
      0006B2 2D               [12] 1781 	add	a, r5
      0006B3 FD               [12] 1782 	mov	r5,a
      0006B4 E4               [12] 1783 	clr	a
      0006B5 3E               [12] 1784 	addc	a, r6
      0006B6 FE               [12] 1785 	mov	r6,a
      0006B7 8D 82            [24] 1786 	mov	dpl,r5
      0006B9 8E 83            [24] 1787 	mov	dph,r6
      0006BB 8F F0            [24] 1788 	mov	b,r7
      0006BD 12 10 54         [24] 1789 	lcall	__gptrget
      0006C0 FD               [12] 1790 	mov	r5,a
      0006C1 A3               [24] 1791 	inc	dptr
      0006C2 12 10 54         [24] 1792 	lcall	__gptrget
      0006C5 FE               [12] 1793 	mov	r6,a
                           00060F  1794 	C$fuzzy.h$1217$5_0$61 ==.
                                   1795 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1217: .output_function(value);
      0006C6 C0 06            [24] 1796 	push	ar6
      0006C8 C0 05            [24] 1797 	push	ar5
      0006CA C0 03            [24] 1798 	push	ar3
      0006CC C0 02            [24] 1799 	push	ar2
      0006CE 12 06 D3         [24] 1800 	lcall	00189$
      0006D1 80 14            [24] 1801 	sjmp	00190$
      0006D3                       1802 00189$:
      0006D3 C0 05            [24] 1803 	push	ar5
      0006D5 C0 06            [24] 1804 	push	ar6
      0006D7 E5 0E            [12] 1805 	mov	a,_bp
      0006D9 24 16            [12] 1806 	add	a,#0x16
      0006DB F8               [12] 1807 	mov	r0,a
      0006DC 86 82            [24] 1808 	mov	dpl, @r0
      0006DE 08               [12] 1809 	inc	r0
      0006DF 86 83            [24] 1810 	mov	dph, @r0
      0006E1 08               [12] 1811 	inc	r0
      0006E2 86 F0            [24] 1812 	mov	b, @r0
      0006E4 08               [12] 1813 	inc	r0
      0006E5 E6               [12] 1814 	mov	a, @r0
      0006E6 22               [24] 1815 	ret
      0006E7                       1816 00190$:
      0006E7 C8               [12] 1817 	xch	a,r0
      0006E8 E5 0E            [12] 1818 	mov	a,_bp
      0006EA 24 1E            [12] 1819 	add	a,#0x1e
      0006EC C8               [12] 1820 	xch	a,r0
      0006ED A6 82            [24] 1821 	mov	@r0, dpl
      0006EF 08               [12] 1822 	inc	r0
      0006F0 A6 83            [24] 1823 	mov	@r0, dph
      0006F2 08               [12] 1824 	inc	r0
      0006F3 A6 F0            [24] 1825 	mov	@r0, b
      0006F5 08               [12] 1826 	inc	r0
      0006F6 F6               [12] 1827 	mov	@r0,a
      0006F7 D0 02            [24] 1828 	pop	ar2
      0006F9 D0 03            [24] 1829 	pop	ar3
      0006FB D0 05            [24] 1830 	pop	ar5
      0006FD D0 06            [24] 1831 	pop	ar6
                           000648  1832 	C$fuzzy.h$1220$5_0$61 ==.
                                   1833 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1220: rules->rules[i].value <
      0006FF A8 0E            [24] 1834 	mov	r0,_bp
      000701 08               [12] 1835 	inc	r0
      000702 EA               [12] 1836 	mov	a,r2
      000703 26               [12] 1837 	add	a, @r0
      000704 FD               [12] 1838 	mov	r5,a
      000705 EB               [12] 1839 	mov	a,r3
      000706 08               [12] 1840 	inc	r0
      000707 36               [12] 1841 	addc	a, @r0
      000708 FE               [12] 1842 	mov	r6,a
      000709 08               [12] 1843 	inc	r0
      00070A 86 07            [24] 1844 	mov	ar7,@r0
      00070C 8D 82            [24] 1845 	mov	dpl,r5
      00070E 8E 83            [24] 1846 	mov	dph,r6
      000710 8F F0            [24] 1847 	mov	b,r7
      000712 E5 0E            [12] 1848 	mov	a,_bp
      000714 24 0A            [12] 1849 	add	a,#0x0a
      000716 F8               [12] 1850 	mov	r0,a
      000717 12 10 54         [24] 1851 	lcall	__gptrget
      00071A F6               [12] 1852 	mov	@r0,a
      00071B A3               [24] 1853 	inc	dptr
      00071C 12 10 54         [24] 1854 	lcall	__gptrget
      00071F 08               [12] 1855 	inc	r0
      000720 F6               [12] 1856 	mov	@r0,a
      000721 A3               [24] 1857 	inc	dptr
      000722 12 10 54         [24] 1858 	lcall	__gptrget
      000725 08               [12] 1859 	inc	r0
      000726 F6               [12] 1860 	mov	@r0,a
      000727 A3               [24] 1861 	inc	dptr
      000728 12 10 54         [24] 1862 	lcall	__gptrget
      00072B 08               [12] 1863 	inc	r0
      00072C F6               [12] 1864 	mov	@r0,a
      00072D C0 03            [24] 1865 	push	ar3
      00072F C0 02            [24] 1866 	push	ar2
      000731 E5 0E            [12] 1867 	mov	a,_bp
      000733 24 1E            [12] 1868 	add	a,#0x1e
      000735 F8               [12] 1869 	mov	r0,a
      000736 E6               [12] 1870 	mov	a,@r0
      000737 C0 E0            [24] 1871 	push	acc
      000739 08               [12] 1872 	inc	r0
      00073A E6               [12] 1873 	mov	a,@r0
      00073B C0 E0            [24] 1874 	push	acc
      00073D 08               [12] 1875 	inc	r0
      00073E E6               [12] 1876 	mov	a,@r0
      00073F C0 E0            [24] 1877 	push	acc
      000741 08               [12] 1878 	inc	r0
      000742 E6               [12] 1879 	mov	a,@r0
      000743 C0 E0            [24] 1880 	push	acc
      000745 E5 0E            [12] 1881 	mov	a,_bp
      000747 24 0A            [12] 1882 	add	a,#0x0a
      000749 F8               [12] 1883 	mov	r0,a
      00074A 86 82            [24] 1884 	mov	dpl, @r0
      00074C 08               [12] 1885 	inc	r0
      00074D 86 83            [24] 1886 	mov	dph, @r0
      00074F 08               [12] 1887 	inc	r0
      000750 86 F0            [24] 1888 	mov	b, @r0
      000752 08               [12] 1889 	inc	r0
      000753 E6               [12] 1890 	mov	a, @r0
      000754 12 0E 34         [24] 1891 	lcall	___fslt
      000757 AF 82            [24] 1892 	mov	r7, dpl
      000759 E5 81            [12] 1893 	mov	a,sp
      00075B 24 FC            [12] 1894 	add	a,#0xfc
      00075D F5 81            [12] 1895 	mov	sp,a
      00075F D0 02            [24] 1896 	pop	ar2
      000761 D0 03            [24] 1897 	pop	ar3
      000763 EF               [12] 1898 	mov	a,r7
      000764 60 12            [24] 1899 	jz	00118$
                           0006AF  1900 	C$fuzzy.h$1222$5_0$61 ==.
                                   1901 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1222: ? rules->rules[i].value
      000766 E5 0E            [12] 1902 	mov	a,_bp
      000768 24 0A            [12] 1903 	add	a,#0x0a
      00076A F8               [12] 1904 	mov	r0,a
      00076B 86 07            [24] 1905 	mov	ar7,@r0
      00076D 08               [12] 1906 	inc	r0
      00076E 86 06            [24] 1907 	mov	ar6,@r0
      000770 08               [12] 1908 	inc	r0
      000771 86 05            [24] 1909 	mov	ar5,@r0
      000773 08               [12] 1910 	inc	r0
      000774 86 04            [24] 1911 	mov	ar4,@r0
      000776 80 10            [24] 1912 	sjmp	00119$
      000778                       1913 00118$:
                           0006C1  1914 	C$fuzzy.h$1223$5_0$61 ==.
                                   1915 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1223: : output_membership;
      000778 E5 0E            [12] 1916 	mov	a,_bp
      00077A 24 1E            [12] 1917 	add	a,#0x1e
      00077C F8               [12] 1918 	mov	r0,a
      00077D 86 07            [24] 1919 	mov	ar7,@r0
      00077F 08               [12] 1920 	inc	r0
      000780 86 06            [24] 1921 	mov	ar6,@r0
      000782 08               [12] 1922 	inc	r0
      000783 86 05            [24] 1923 	mov	ar5,@r0
      000785 08               [12] 1924 	inc	r0
      000786 86 04            [24] 1925 	mov	ar4,@r0
      000788                       1926 00119$:
      000788 E5 0E            [12] 1927 	mov	a,_bp
      00078A 24 22            [12] 1928 	add	a,#0x22
      00078C F8               [12] 1929 	mov	r0,a
      00078D A6 07            [24] 1930 	mov	@r0,ar7
      00078F 08               [12] 1931 	inc	r0
      000790 A6 06            [24] 1932 	mov	@r0,ar6
      000792 08               [12] 1933 	inc	r0
      000793 A6 05            [24] 1934 	mov	@r0,ar5
      000795 08               [12] 1935 	inc	r0
      000796 A6 04            [24] 1936 	mov	@r0,ar4
                           0006E1  1937 	C$fuzzy.h$1228$1_0$56 ==.
                                   1938 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1228: ? aggregated_height
      000798 C0 03            [24] 1939 	push	ar3
      00079A C0 02            [24] 1940 	push	ar2
      00079C E5 0E            [12] 1941 	mov	a,_bp
      00079E 24 1A            [12] 1942 	add	a,#0x1a
      0007A0 F8               [12] 1943 	mov	r0,a
      0007A1 E6               [12] 1944 	mov	a,@r0
      0007A2 C0 E0            [24] 1945 	push	acc
      0007A4 08               [12] 1946 	inc	r0
      0007A5 E6               [12] 1947 	mov	a,@r0
      0007A6 C0 E0            [24] 1948 	push	acc
      0007A8 08               [12] 1949 	inc	r0
      0007A9 E6               [12] 1950 	mov	a,@r0
      0007AA C0 E0            [24] 1951 	push	acc
      0007AC 08               [12] 1952 	inc	r0
      0007AD E6               [12] 1953 	mov	a,@r0
      0007AE C0 E0            [24] 1954 	push	acc
      0007B0 E5 0E            [12] 1955 	mov	a,_bp
      0007B2 24 22            [12] 1956 	add	a,#0x22
      0007B4 F8               [12] 1957 	mov	r0,a
      0007B5 86 82            [24] 1958 	mov	dpl, @r0
      0007B7 08               [12] 1959 	inc	r0
      0007B8 86 83            [24] 1960 	mov	dph, @r0
      0007BA 08               [12] 1961 	inc	r0
      0007BB 86 F0            [24] 1962 	mov	b, @r0
      0007BD 08               [12] 1963 	inc	r0
      0007BE E6               [12] 1964 	mov	a, @r0
      0007BF 12 0E 34         [24] 1965 	lcall	___fslt
      0007C2 AF 82            [24] 1966 	mov	r7, dpl
      0007C4 E5 81            [12] 1967 	mov	a,sp
      0007C6 24 FC            [12] 1968 	add	a,#0xfc
      0007C8 F5 81            [12] 1969 	mov	sp,a
      0007CA D0 02            [24] 1970 	pop	ar2
      0007CC D0 03            [24] 1971 	pop	ar3
      0007CE EF               [12] 1972 	mov	a,r7
      0007CF 60 12            [24] 1973 	jz	00120$
      0007D1 E5 0E            [12] 1974 	mov	a,_bp
      0007D3 24 1A            [12] 1975 	add	a,#0x1a
      0007D5 F8               [12] 1976 	mov	r0,a
      0007D6 86 04            [24] 1977 	mov	ar4,@r0
      0007D8 08               [12] 1978 	inc	r0
      0007D9 86 05            [24] 1979 	mov	ar5,@r0
      0007DB 08               [12] 1980 	inc	r0
      0007DC 86 06            [24] 1981 	mov	ar6,@r0
      0007DE 08               [12] 1982 	inc	r0
      0007DF 86 07            [24] 1983 	mov	ar7,@r0
      0007E1 80 10            [24] 1984 	sjmp	00121$
      0007E3                       1985 00120$:
                           00072C  1986 	C$fuzzy.h$1229$5_0$61 ==.
                                   1987 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1229: : clipped_height;
      0007E3 E5 0E            [12] 1988 	mov	a,_bp
      0007E5 24 22            [12] 1989 	add	a,#0x22
      0007E7 F8               [12] 1990 	mov	r0,a
      0007E8 86 04            [24] 1991 	mov	ar4,@r0
      0007EA 08               [12] 1992 	inc	r0
      0007EB 86 05            [24] 1993 	mov	ar5,@r0
      0007ED 08               [12] 1994 	inc	r0
      0007EE 86 06            [24] 1995 	mov	ar6,@r0
      0007F0 08               [12] 1996 	inc	r0
      0007F1 86 07            [24] 1997 	mov	ar7,@r0
      0007F3                       1998 00121$:
      0007F3 E5 0E            [12] 1999 	mov	a,_bp
      0007F5 24 1A            [12] 2000 	add	a,#0x1a
      0007F7 F8               [12] 2001 	mov	r0,a
      0007F8 A6 04            [24] 2002 	mov	@r0,ar4
      0007FA 08               [12] 2003 	inc	r0
      0007FB A6 05            [24] 2004 	mov	@r0,ar5
      0007FD 08               [12] 2005 	inc	r0
      0007FE A6 06            [24] 2006 	mov	@r0,ar6
      000800 08               [12] 2007 	inc	r0
      000801 A6 07            [24] 2008 	mov	@r0,ar7
                           00074C  2009 	C$fuzzy.h$1213$1_0$56 ==.
                                   2010 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1213: i++
      000803 74 06            [12] 2011 	mov	a,#0x06
      000805 2A               [12] 2012 	add	a, r2
      000806 FA               [12] 2013 	mov	r2,a
      000807 E4               [12] 2014 	clr	a
      000808 3B               [12] 2015 	addc	a, r3
      000809 FB               [12] 2016 	mov	r3,a
      00080A E5 0E            [12] 2017 	mov	a,_bp
      00080C 24 26            [12] 2018 	add	a,#0x26
      00080E F8               [12] 2019 	mov	r0,a
      00080F 06               [12] 2020 	inc	@r0
      000810 B6 00 02         [24] 2021 	cjne	@r0,#0x00,00193$
      000813 08               [12] 2022 	inc	r0
      000814 06               [12] 2023 	inc	@r0
      000815                       2024 00193$:
      000815 02 06 73         [24] 2025 	ljmp	00111$
      000818                       2026 00106$:
                           000761  2027 	C$fuzzy.h$1234$1_0$56 ==.
                                   2028 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1234: aggregated_height;
      000818 E5 0E            [12] 2029 	mov	a,_bp
      00081A 24 1A            [12] 2030 	add	a,#0x1a
      00081C F8               [12] 2031 	mov	r0,a
      00081D E6               [12] 2032 	mov	a,@r0
      00081E C0 E0            [24] 2033 	push	acc
      000820 08               [12] 2034 	inc	r0
      000821 E6               [12] 2035 	mov	a,@r0
      000822 C0 E0            [24] 2036 	push	acc
      000824 08               [12] 2037 	inc	r0
      000825 E6               [12] 2038 	mov	a,@r0
      000826 C0 E0            [24] 2039 	push	acc
      000828 08               [12] 2040 	inc	r0
      000829 E6               [12] 2041 	mov	a,@r0
      00082A C0 E0            [24] 2042 	push	acc
      00082C E5 0E            [12] 2043 	mov	a,_bp
      00082E 24 16            [12] 2044 	add	a,#0x16
      000830 F8               [12] 2045 	mov	r0,a
      000831 86 82            [24] 2046 	mov	dpl, @r0
      000833 08               [12] 2047 	inc	r0
      000834 86 83            [24] 2048 	mov	dph, @r0
      000836 08               [12] 2049 	inc	r0
      000837 86 F0            [24] 2050 	mov	b, @r0
      000839 08               [12] 2051 	inc	r0
      00083A E6               [12] 2052 	mov	a, @r0
      00083B 12 0D 15         [24] 2053 	lcall	___fsmul
      00083E AC 82            [24] 2054 	mov	r4, dpl
      000840 AD 83            [24] 2055 	mov	r5, dph
      000842 AE F0            [24] 2056 	mov	r6, b
      000844 FF               [12] 2057 	mov	r7, a
      000845 E5 81            [12] 2058 	mov	a,sp
      000847 24 FC            [12] 2059 	add	a,#0xfc
      000849 F5 81            [12] 2060 	mov	sp,a
      00084B C0 04            [24] 2061 	push	ar4
      00084D C0 05            [24] 2062 	push	ar5
      00084F C0 06            [24] 2063 	push	ar6
      000851 C0 07            [24] 2064 	push	ar7
                           00079C  2065 	C$fuzzy.h$1237$1_0$56 ==.
                                   2066 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1237: aggregated_height;
      000853 E5 0E            [12] 2067 	mov	a,_bp
      000855 24 0E            [12] 2068 	add	a,#0x0e
      000857 F8               [12] 2069 	mov	r0,a
      000858 86 82            [24] 2070 	mov	dpl, @r0
      00085A 08               [12] 2071 	inc	r0
      00085B 86 83            [24] 2072 	mov	dph, @r0
      00085D 08               [12] 2073 	inc	r0
      00085E 86 F0            [24] 2074 	mov	b, @r0
      000860 08               [12] 2075 	inc	r0
      000861 E6               [12] 2076 	mov	a, @r0
      000862 12 0E 86         [24] 2077 	lcall	___fsadd
      000865 C8               [12] 2078 	xch	a,r0
      000866 E5 0E            [12] 2079 	mov	a,_bp
      000868 24 0E            [12] 2080 	add	a,#0x0e
      00086A C8               [12] 2081 	xch	a,r0
      00086B A6 82            [24] 2082 	mov	@r0, dpl
      00086D 08               [12] 2083 	inc	r0
      00086E A6 83            [24] 2084 	mov	@r0, dph
      000870 08               [12] 2085 	inc	r0
      000871 A6 F0            [24] 2086 	mov	@r0, b
      000873 08               [12] 2087 	inc	r0
      000874 F6               [12] 2088 	mov	@r0,a
      000875 E5 81            [12] 2089 	mov	a,sp
      000877 24 FC            [12] 2090 	add	a,#0xfc
      000879 F5 81            [12] 2091 	mov	sp,a
      00087B E5 0E            [12] 2092 	mov	a,_bp
      00087D 24 1A            [12] 2093 	add	a,#0x1a
      00087F F8               [12] 2094 	mov	r0,a
      000880 E6               [12] 2095 	mov	a,@r0
      000881 C0 E0            [24] 2096 	push	acc
      000883 08               [12] 2097 	inc	r0
      000884 E6               [12] 2098 	mov	a,@r0
      000885 C0 E0            [24] 2099 	push	acc
      000887 08               [12] 2100 	inc	r0
      000888 E6               [12] 2101 	mov	a,@r0
      000889 C0 E0            [24] 2102 	push	acc
      00088B 08               [12] 2103 	inc	r0
      00088C E6               [12] 2104 	mov	a,@r0
      00088D C0 E0            [24] 2105 	push	acc
                           0007D8  2106 	C$fuzzy.h$1206$1_0$56 ==.
                                   2107 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1206: ) {
      00088F E5 0E            [12] 2108 	mov	a,_bp
      000891 24 12            [12] 2109 	add	a,#0x12
      000893 F8               [12] 2110 	mov	r0,a
      000894 86 82            [24] 2111 	mov	dpl, @r0
      000896 08               [12] 2112 	inc	r0
      000897 86 83            [24] 2113 	mov	dph, @r0
      000899 08               [12] 2114 	inc	r0
      00089A 86 F0            [24] 2115 	mov	b, @r0
      00089C 08               [12] 2116 	inc	r0
      00089D E6               [12] 2117 	mov	a, @r0
      00089E 12 0E 86         [24] 2118 	lcall	___fsadd
      0008A1 C8               [12] 2119 	xch	a,r0
      0008A2 E5 0E            [12] 2120 	mov	a,_bp
      0008A4 24 12            [12] 2121 	add	a,#0x12
      0008A6 C8               [12] 2122 	xch	a,r0
      0008A7 A6 82            [24] 2123 	mov	@r0, dpl
      0008A9 08               [12] 2124 	inc	r0
      0008AA A6 83            [24] 2125 	mov	@r0, dph
      0008AC 08               [12] 2126 	inc	r0
      0008AD A6 F0            [24] 2127 	mov	@r0, b
      0008AF 08               [12] 2128 	inc	r0
      0008B0 F6               [12] 2129 	mov	@r0,a
      0008B1 E5 81            [12] 2130 	mov	a,sp
      0008B3 24 FC            [12] 2131 	add	a,#0xfc
      0008B5 F5 81            [12] 2132 	mov	sp,a
      0008B7 E5 0E            [12] 2133 	mov	a,_bp
      0008B9 24 F2            [12] 2134 	add	a,#0xf2
      0008BB F8               [12] 2135 	mov	r0,a
      0008BC E6               [12] 2136 	mov	a,@r0
      0008BD C0 E0            [24] 2137 	push	acc
      0008BF 08               [12] 2138 	inc	r0
      0008C0 E6               [12] 2139 	mov	a,@r0
      0008C1 C0 E0            [24] 2140 	push	acc
      0008C3 08               [12] 2141 	inc	r0
      0008C4 E6               [12] 2142 	mov	a,@r0
      0008C5 C0 E0            [24] 2143 	push	acc
      0008C7 08               [12] 2144 	inc	r0
      0008C8 E6               [12] 2145 	mov	a,@r0
      0008C9 C0 E0            [24] 2146 	push	acc
      0008CB E5 0E            [12] 2147 	mov	a,_bp
      0008CD 24 16            [12] 2148 	add	a,#0x16
      0008CF F8               [12] 2149 	mov	r0,a
      0008D0 86 82            [24] 2150 	mov	dpl, @r0
      0008D2 08               [12] 2151 	inc	r0
      0008D3 86 83            [24] 2152 	mov	dph, @r0
      0008D5 08               [12] 2153 	inc	r0
      0008D6 86 F0            [24] 2154 	mov	b, @r0
      0008D8 08               [12] 2155 	inc	r0
      0008D9 E6               [12] 2156 	mov	a, @r0
      0008DA 12 0E 86         [24] 2157 	lcall	___fsadd
      0008DD C8               [12] 2158 	xch	a,r0
      0008DE E5 0E            [12] 2159 	mov	a,_bp
      0008E0 24 16            [12] 2160 	add	a,#0x16
      0008E2 C8               [12] 2161 	xch	a,r0
      0008E3 A6 82            [24] 2162 	mov	@r0, dpl
      0008E5 08               [12] 2163 	inc	r0
      0008E6 A6 83            [24] 2164 	mov	@r0, dph
      0008E8 08               [12] 2165 	inc	r0
      0008E9 A6 F0            [24] 2166 	mov	@r0, b
      0008EB 08               [12] 2167 	inc	r0
      0008EC F6               [12] 2168 	mov	@r0,a
      0008ED E5 81            [12] 2169 	mov	a,sp
      0008EF 24 FC            [12] 2170 	add	a,#0xfc
      0008F1 F5 81            [12] 2171 	mov	sp,a
      0008F3 02 06 24         [24] 2172 	ljmp	00114$
      0008F6                       2173 00107$:
                           00083F  2174 	C$fuzzy.h$1240$1_0$56 ==.
                                   2175 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1240: if (height_sum == 0.0f) {
      0008F6 E5 0E            [12] 2176 	mov	a,_bp
      0008F8 24 12            [12] 2177 	add	a,#0x12
      0008FA F8               [12] 2178 	mov	r0,a
      0008FB 86 F0            [24] 2179 	mov	b,@r0
      0008FD 08               [12] 2180 	inc	r0
      0008FE E6               [12] 2181 	mov	a,@r0
      0008FF 42 F0            [12] 2182 	orl	b,a
      000901 08               [12] 2183 	inc	r0
      000902 E6               [12] 2184 	mov	a,@r0
      000903 42 F0            [12] 2185 	orl	b,a
      000905 08               [12] 2186 	inc	r0
      000906 E6               [12] 2187 	mov	a,@r0
      000907 54 7F            [12] 2188 	anl	a,#0x7F
      000909 45 F0            [12] 2189 	orl	a,b
      00090B 70 08            [24] 2190 	jnz	00109$
                           000856  2191 	C$fuzzy.h$1241$2_0$62 ==.
                                   2192 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1241: return 0.0f;
      00090D 90 00 00         [24] 2193 	mov	dptr,#0x0000
      000910 E4               [12] 2194 	clr	a
      000911 F5 F0            [12] 2195 	mov	b,a
      000913 80 3A            [24] 2196 	sjmp	00116$
      000915                       2197 00109$:
                           00085E  2198 	C$fuzzy.h$1245$1_0$56 ==.
                                   2199 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1245: height_sum;
      000915 E5 0E            [12] 2200 	mov	a,_bp
      000917 24 12            [12] 2201 	add	a,#0x12
      000919 F8               [12] 2202 	mov	r0,a
      00091A E6               [12] 2203 	mov	a,@r0
      00091B C0 E0            [24] 2204 	push	acc
      00091D 08               [12] 2205 	inc	r0
      00091E E6               [12] 2206 	mov	a,@r0
      00091F C0 E0            [24] 2207 	push	acc
      000921 08               [12] 2208 	inc	r0
      000922 E6               [12] 2209 	mov	a,@r0
      000923 C0 E0            [24] 2210 	push	acc
      000925 08               [12] 2211 	inc	r0
      000926 E6               [12] 2212 	mov	a,@r0
      000927 C0 E0            [24] 2213 	push	acc
      000929 E5 0E            [12] 2214 	mov	a,_bp
      00092B 24 0E            [12] 2215 	add	a,#0x0e
      00092D F8               [12] 2216 	mov	r0,a
      00092E 86 82            [24] 2217 	mov	dpl, @r0
      000930 08               [12] 2218 	inc	r0
      000931 86 83            [24] 2219 	mov	dph, @r0
      000933 08               [12] 2220 	inc	r0
      000934 86 F0            [24] 2221 	mov	b, @r0
      000936 08               [12] 2222 	inc	r0
      000937 E6               [12] 2223 	mov	a, @r0
      000938 12 0F 91         [24] 2224 	lcall	___fsdiv
      00093B AC 82            [24] 2225 	mov	r4, dpl
      00093D AD 83            [24] 2226 	mov	r5, dph
      00093F AE F0            [24] 2227 	mov	r6, b
      000941 FF               [12] 2228 	mov	r7, a
      000942 E5 81            [12] 2229 	mov	a,sp
      000944 24 FC            [12] 2230 	add	a,#0xfc
      000946 F5 81            [12] 2231 	mov	sp,a
      000948 8C 82            [24] 2232 	mov	dpl, r4
      00094A 8D 83            [24] 2233 	mov	dph, r5
      00094C 8E F0            [24] 2234 	mov	b, r6
      00094E EF               [12] 2235 	mov	a, r7
      00094F                       2236 00116$:
                           000898  2237 	C$fuzzy.h$1246$1_0$56 ==.
                                   2238 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1246: }
      00094F 85 0E 81         [24] 2239 	mov	sp,_bp
      000952 D0 0E            [24] 2240 	pop	_bp
                           00089D  2241 	C$fuzzy.h$1246$1_0$56 ==.
                           00089D  2242 	XG$fuzzy_rules_cog$0$0 ==.
      000954 22               [24] 2243 	ret
                                   2244 ;------------------------------------------------------------
                                   2245 ;Allocation info for local variables in function 'fuzzy_rules_free'
                                   2246 ;------------------------------------------------------------
                                   2247 ;rules         Allocated to registers r5 r6 r7 
                                   2248 ;------------------------------------------------------------
                           00089E  2249 	G$fuzzy_rules_free$0$0 ==.
                           00089E  2250 	C$fuzzy.h$1248$1_0$64 ==.
                                   2251 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1248: void fuzzy_rules_free(
                                   2252 ;	-----------------------------------------
                                   2253 ;	 function fuzzy_rules_free
                                   2254 ;	-----------------------------------------
      000955                       2255 _fuzzy_rules_free:
      000955 AD 82            [24] 2256 	mov	r5, dpl
      000957 AE 83            [24] 2257 	mov	r6, dph
      000959 AF F0            [24] 2258 	mov	r7, b
                           0008A4  2259 	C$fuzzy.h$1252$1_0$64 ==.
                                   2260 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1252: if (rules == NULL) {
      00095B ED               [12] 2261 	mov	a,r5
      00095C 4E               [12] 2262 	orl	a,r6
      00095D 70 02            [24] 2263 	jnz	00102$
                           0008A8  2264 	C$fuzzy.h$1253$2_0$65 ==.
                                   2265 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1253: return;
      00095F 80 15            [24] 2266 	sjmp	00103$
      000961                       2267 00102$:
                           0008AA  2268 	C$fuzzy.h$1261$1_0$64 ==.
                                   2269 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1261: rules->count = 0;
      000961 74 0C            [12] 2270 	mov	a,#0x0c
      000963 2D               [12] 2271 	add	a, r5
      000964 FD               [12] 2272 	mov	r5,a
      000965 E4               [12] 2273 	clr	a
      000966 3E               [12] 2274 	addc	a, r6
      000967 FE               [12] 2275 	mov	r6,a
      000968 8D 82            [24] 2276 	mov	dpl,r5
      00096A 8E 83            [24] 2277 	mov	dph,r6
      00096C 8F F0            [24] 2278 	mov	b,r7
      00096E E4               [12] 2279 	clr	a
      00096F 12 0E 19         [24] 2280 	lcall	__gptrput
      000972 A3               [24] 2281 	inc	dptr
      000973 12 0E 19         [24] 2282 	lcall	__gptrput
      000976                       2283 00103$:
                           0008BF  2284 	C$fuzzy.h$1262$1_0$64 ==.
                                   2285 ;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1262: }
                           0008BF  2286 	C$fuzzy.h$1262$1_0$64 ==.
                           0008BF  2287 	XG$fuzzy_rules_free$0$0 ==.
      000976 22               [24] 2288 	ret
                                   2289 ;------------------------------------------------------------
                                   2290 ;Allocation info for local variables in function 'temperature_low'
                                   2291 ;------------------------------------------------------------
                                   2292 ;value         Allocated to registers r4 r5 r6 r7 
                                   2293 ;------------------------------------------------------------
                           0008C0  2294 	Fcontroller_8051$temperature_low$0$0 ==.
                           0008C0  2295 	C$controller_8051.c$40$1_0$67 ==.
                                   2296 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:40: static float temperature_low(
                                   2297 ;	-----------------------------------------
                                   2298 ;	 function temperature_low
                                   2299 ;	-----------------------------------------
      000977                       2300 _temperature_low:
      000977 AC 82            [24] 2301 	mov	r4,dpl
      000979 AD 83            [24] 2302 	mov	r5,dph
      00097B AE F0            [24] 2303 	mov	r6,b
      00097D FF               [12] 2304 	mov	r7,a
                           0008C7  2305 	C$controller_8051.c$50$1_0$67 ==.
                                   2306 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:50: hedges.none
      00097E 90 11 16         [24] 2307 	mov	dptr,#_hedges
      000981 E4               [12] 2308 	clr	a
      000982 93               [24] 2309 	movc	a,@a+dptr
      000983 FB               [12] 2310 	mov	r3,a
                           0008CD  2311 	C$controller_8051.c$45$1_0$67 ==.
                                   2312 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:45: NULL,
      000984 C0 03            [24] 2313 	push	ar3
      000986 E4               [12] 2314 	clr	a
      000987 C0 E0            [24] 2315 	push	acc
      000989 C0 04            [24] 2316 	push	ar4
      00098B C0 05            [24] 2317 	push	ar5
      00098D C0 06            [24] 2318 	push	ar6
      00098F C0 07            [24] 2319 	push	ar7
      000991 C0 E0            [24] 2320 	push	acc
      000993 C0 E0            [24] 2321 	push	acc
      000995 74 20            [12] 2322 	mov	a,#0x20
      000997 C0 E0            [24] 2323 	push	acc
      000999 74 42            [12] 2324 	mov	a,#0x42
      00099B C0 E0            [24] 2325 	push	acc
      00099D E4               [12] 2326 	clr	a
      00099E C0 E0            [24] 2327 	push	acc
      0009A0 C0 E0            [24] 2328 	push	acc
      0009A2 74 A0            [12] 2329 	mov	a,#0xa0
      0009A4 C0 E0            [24] 2330 	push	acc
      0009A6 23               [12] 2331 	rl	a
      0009A7 C0 E0            [24] 2332 	push	acc
      0009A9 90 00 00         [24] 2333 	mov	dptr,#0x0000
      0009AC 75 F0 00         [24] 2334 	mov	b, #0x00
      0009AF 12 01 BE         [24] 2335 	lcall	_fuzzy_ramp
      0009B2 AC 82            [24] 2336 	mov	r4, dpl
      0009B4 AD 83            [24] 2337 	mov	r5, dph
      0009B6 AE F0            [24] 2338 	mov	r6, b
      0009B8 FF               [12] 2339 	mov	r7, a
      0009B9 E5 81            [12] 2340 	mov	a,sp
      0009BB 24 F2            [12] 2341 	add	a,#0xf2
      0009BD F5 81            [12] 2342 	mov	sp,a
      0009BF 8C 82            [24] 2343 	mov	dpl, r4
      0009C1 8D 83            [24] 2344 	mov	dph, r5
      0009C3 8E F0            [24] 2345 	mov	b, r6
      0009C5 EF               [12] 2346 	mov	a, r7
                           00090F  2347 	C$controller_8051.c$52$1_0$67 ==.
                                   2348 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:52: }
                           00090F  2349 	C$controller_8051.c$52$1_0$67 ==.
                           00090F  2350 	XFcontroller_8051$temperature_low$0$0 ==.
      0009C6 22               [24] 2351 	ret
                                   2352 ;------------------------------------------------------------
                                   2353 ;Allocation info for local variables in function 'temperature_high'
                                   2354 ;------------------------------------------------------------
                                   2355 ;value         Allocated to registers r4 r5 r6 r7 
                                   2356 ;------------------------------------------------------------
                           000910  2357 	Fcontroller_8051$temperature_high$0$0 ==.
                           000910  2358 	C$controller_8051.c$55$1_0$69 ==.
                                   2359 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:55: static float temperature_high(
                                   2360 ;	-----------------------------------------
                                   2361 ;	 function temperature_high
                                   2362 ;	-----------------------------------------
      0009C7                       2363 _temperature_high:
      0009C7 AC 82            [24] 2364 	mov	r4,dpl
      0009C9 AD 83            [24] 2365 	mov	r5,dph
      0009CB AE F0            [24] 2366 	mov	r6,b
      0009CD FF               [12] 2367 	mov	r7,a
                           000917  2368 	C$controller_8051.c$65$1_0$69 ==.
                                   2369 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:65: hedges.none
      0009CE 90 11 16         [24] 2370 	mov	dptr,#_hedges
      0009D1 E4               [12] 2371 	clr	a
      0009D2 93               [24] 2372 	movc	a,@a+dptr
      0009D3 FB               [12] 2373 	mov	r3,a
                           00091D  2374 	C$controller_8051.c$60$1_0$69 ==.
                                   2375 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:60: NULL,
      0009D4 C0 03            [24] 2376 	push	ar3
      0009D6 74 01            [12] 2377 	mov	a,#0x01
      0009D8 C0 E0            [24] 2378 	push	acc
      0009DA C0 04            [24] 2379 	push	ar4
      0009DC C0 05            [24] 2380 	push	ar5
      0009DE C0 06            [24] 2381 	push	ar6
      0009E0 C0 07            [24] 2382 	push	ar7
      0009E2 E4               [12] 2383 	clr	a
      0009E3 C0 E0            [24] 2384 	push	acc
      0009E5 C0 E0            [24] 2385 	push	acc
      0009E7 74 70            [12] 2386 	mov	a,#0x70
      0009E9 C0 E0            [24] 2387 	push	acc
      0009EB 74 42            [12] 2388 	mov	a,#0x42
      0009ED C0 E0            [24] 2389 	push	acc
      0009EF E4               [12] 2390 	clr	a
      0009F0 C0 E0            [24] 2391 	push	acc
      0009F2 C0 E0            [24] 2392 	push	acc
      0009F4 74 F0            [12] 2393 	mov	a,#0xf0
      0009F6 C0 E0            [24] 2394 	push	acc
      0009F8 74 41            [12] 2395 	mov	a,#0x41
      0009FA C0 E0            [24] 2396 	push	acc
      0009FC 90 00 00         [24] 2397 	mov	dptr,#0x0000
      0009FF 75 F0 00         [24] 2398 	mov	b, #0x00
      000A02 12 01 BE         [24] 2399 	lcall	_fuzzy_ramp
      000A05 AC 82            [24] 2400 	mov	r4, dpl
      000A07 AD 83            [24] 2401 	mov	r5, dph
      000A09 AE F0            [24] 2402 	mov	r6, b
      000A0B FF               [12] 2403 	mov	r7, a
      000A0C E5 81            [12] 2404 	mov	a,sp
      000A0E 24 F2            [12] 2405 	add	a,#0xf2
      000A10 F5 81            [12] 2406 	mov	sp,a
      000A12 8C 82            [24] 2407 	mov	dpl, r4
      000A14 8D 83            [24] 2408 	mov	dph, r5
      000A16 8E F0            [24] 2409 	mov	b, r6
      000A18 EF               [12] 2410 	mov	a, r7
                           000962  2411 	C$controller_8051.c$67$1_0$69 ==.
                                   2412 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:67: }
                           000962  2413 	C$controller_8051.c$67$1_0$69 ==.
                           000962  2414 	XFcontroller_8051$temperature_high$0$0 ==.
      000A19 22               [24] 2415 	ret
                                   2416 ;------------------------------------------------------------
                                   2417 ;Allocation info for local variables in function 'fan_slow'
                                   2418 ;------------------------------------------------------------
                                   2419 ;value         Allocated to registers r4 r5 r6 r7 
                                   2420 ;------------------------------------------------------------
                           000963  2421 	Fcontroller_8051$fan_slow$0$0 ==.
                           000963  2422 	C$controller_8051.c$74$1_0$71 ==.
                                   2423 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:74: static float fan_slow(
                                   2424 ;	-----------------------------------------
                                   2425 ;	 function fan_slow
                                   2426 ;	-----------------------------------------
      000A1A                       2427 _fan_slow:
      000A1A AC 82            [24] 2428 	mov	r4,dpl
      000A1C AD 83            [24] 2429 	mov	r5,dph
      000A1E AE F0            [24] 2430 	mov	r6,b
      000A20 FF               [12] 2431 	mov	r7,a
                           00096A  2432 	C$controller_8051.c$84$1_0$71 ==.
                                   2433 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:84: hedges.none
      000A21 90 11 16         [24] 2434 	mov	dptr,#_hedges
      000A24 E4               [12] 2435 	clr	a
      000A25 93               [24] 2436 	movc	a,@a+dptr
      000A26 FB               [12] 2437 	mov	r3,a
                           000970  2438 	C$controller_8051.c$79$1_0$71 ==.
                                   2439 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:79: NULL,
      000A27 C0 03            [24] 2440 	push	ar3
      000A29 E4               [12] 2441 	clr	a
      000A2A C0 E0            [24] 2442 	push	acc
      000A2C C0 04            [24] 2443 	push	ar4
      000A2E C0 05            [24] 2444 	push	ar5
      000A30 C0 06            [24] 2445 	push	ar6
      000A32 C0 07            [24] 2446 	push	ar7
      000A34 C0 E0            [24] 2447 	push	acc
      000A36 C0 E0            [24] 2448 	push	acc
      000A38 74 48            [12] 2449 	mov	a,#0x48
      000A3A C0 E0            [24] 2450 	push	acc
      000A3C 74 42            [12] 2451 	mov	a,#0x42
      000A3E C0 E0            [24] 2452 	push	acc
      000A40 E4               [12] 2453 	clr	a
      000A41 C0 E0            [24] 2454 	push	acc
      000A43 C0 E0            [24] 2455 	push	acc
      000A45 74 A0            [12] 2456 	mov	a,#0xa0
      000A47 C0 E0            [24] 2457 	push	acc
      000A49 23               [12] 2458 	rl	a
      000A4A C0 E0            [24] 2459 	push	acc
      000A4C 90 00 00         [24] 2460 	mov	dptr,#0x0000
      000A4F 75 F0 00         [24] 2461 	mov	b, #0x00
      000A52 12 01 BE         [24] 2462 	lcall	_fuzzy_ramp
      000A55 AC 82            [24] 2463 	mov	r4, dpl
      000A57 AD 83            [24] 2464 	mov	r5, dph
      000A59 AE F0            [24] 2465 	mov	r6, b
      000A5B FF               [12] 2466 	mov	r7, a
      000A5C E5 81            [12] 2467 	mov	a,sp
      000A5E 24 F2            [12] 2468 	add	a,#0xf2
      000A60 F5 81            [12] 2469 	mov	sp,a
      000A62 8C 82            [24] 2470 	mov	dpl, r4
      000A64 8D 83            [24] 2471 	mov	dph, r5
      000A66 8E F0            [24] 2472 	mov	b, r6
      000A68 EF               [12] 2473 	mov	a, r7
                           0009B2  2474 	C$controller_8051.c$86$1_0$71 ==.
                                   2475 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:86: }
                           0009B2  2476 	C$controller_8051.c$86$1_0$71 ==.
                           0009B2  2477 	XFcontroller_8051$fan_slow$0$0 ==.
      000A69 22               [24] 2478 	ret
                                   2479 ;------------------------------------------------------------
                                   2480 ;Allocation info for local variables in function 'fan_fast'
                                   2481 ;------------------------------------------------------------
                                   2482 ;value         Allocated to registers r4 r5 r6 r7 
                                   2483 ;------------------------------------------------------------
                           0009B3  2484 	Fcontroller_8051$fan_fast$0$0 ==.
                           0009B3  2485 	C$controller_8051.c$89$1_0$73 ==.
                                   2486 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:89: static float fan_fast(
                                   2487 ;	-----------------------------------------
                                   2488 ;	 function fan_fast
                                   2489 ;	-----------------------------------------
      000A6A                       2490 _fan_fast:
      000A6A AC 82            [24] 2491 	mov	r4,dpl
      000A6C AD 83            [24] 2492 	mov	r5,dph
      000A6E AE F0            [24] 2493 	mov	r6,b
      000A70 FF               [12] 2494 	mov	r7,a
                           0009BA  2495 	C$controller_8051.c$99$1_0$73 ==.
                                   2496 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:99: hedges.none
      000A71 90 11 16         [24] 2497 	mov	dptr,#_hedges
      000A74 E4               [12] 2498 	clr	a
      000A75 93               [24] 2499 	movc	a,@a+dptr
      000A76 FB               [12] 2500 	mov	r3,a
                           0009C0  2501 	C$controller_8051.c$94$1_0$73 ==.
                                   2502 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:94: NULL,
      000A77 C0 03            [24] 2503 	push	ar3
      000A79 74 01            [12] 2504 	mov	a,#0x01
      000A7B C0 E0            [24] 2505 	push	acc
      000A7D C0 04            [24] 2506 	push	ar4
      000A7F C0 05            [24] 2507 	push	ar5
      000A81 C0 06            [24] 2508 	push	ar6
      000A83 C0 07            [24] 2509 	push	ar7
      000A85 E4               [12] 2510 	clr	a
      000A86 C0 E0            [24] 2511 	push	acc
      000A88 C0 E0            [24] 2512 	push	acc
      000A8A 74 A0            [12] 2513 	mov	a,#0xa0
      000A8C C0 E0            [24] 2514 	push	acc
      000A8E 74 42            [12] 2515 	mov	a,#0x42
      000A90 C0 E0            [24] 2516 	push	acc
      000A92 E4               [12] 2517 	clr	a
      000A93 C0 E0            [24] 2518 	push	acc
      000A95 C0 E0            [24] 2519 	push	acc
      000A97 74 20            [12] 2520 	mov	a,#0x20
      000A99 C0 E0            [24] 2521 	push	acc
      000A9B 74 42            [12] 2522 	mov	a,#0x42
      000A9D C0 E0            [24] 2523 	push	acc
      000A9F 90 00 00         [24] 2524 	mov	dptr,#0x0000
      000AA2 75 F0 00         [24] 2525 	mov	b, #0x00
      000AA5 12 01 BE         [24] 2526 	lcall	_fuzzy_ramp
      000AA8 AC 82            [24] 2527 	mov	r4, dpl
      000AAA AD 83            [24] 2528 	mov	r5, dph
      000AAC AE F0            [24] 2529 	mov	r6, b
      000AAE FF               [12] 2530 	mov	r7, a
      000AAF E5 81            [12] 2531 	mov	a,sp
      000AB1 24 F2            [12] 2532 	add	a,#0xf2
      000AB3 F5 81            [12] 2533 	mov	sp,a
      000AB5 8C 82            [24] 2534 	mov	dpl, r4
      000AB7 8D 83            [24] 2535 	mov	dph, r5
      000AB9 8E F0            [24] 2536 	mov	b, r6
      000ABB EF               [12] 2537 	mov	a, r7
                           000A05  2538 	C$controller_8051.c$101$1_0$73 ==.
                                   2539 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:101: }
                           000A05  2540 	C$controller_8051.c$101$1_0$73 ==.
                           000A05  2541 	XFcontroller_8051$fan_fast$0$0 ==.
      000ABC 22               [24] 2542 	ret
                                   2543 ;------------------------------------------------------------
                                   2544 ;Allocation info for local variables in function 'calculate_fan_speed'
                                   2545 ;------------------------------------------------------------
                                   2546 ;temperature   Allocated to stack - _bp +1 +4 
                                   2547 ;rules         Allocated to stack - _bp +9 +14 
                                   2548 ;result        Allocated to stack - _bp +23 +4 
                                   2549 ;sloc0         Allocated to stack - _bp +5 +4 
                                   2550 ;------------------------------------------------------------
                           000A06  2551 	Fcontroller_8051$calculate_fan_speed$0$0 ==.
                           000A06  2552 	C$controller_8051.c$108$1_0$75 ==.
                                   2553 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:108: static float calculate_fan_speed(
                                   2554 ;	-----------------------------------------
                                   2555 ;	 function calculate_fan_speed
                                   2556 ;	-----------------------------------------
      000ABD                       2557 _calculate_fan_speed:
      000ABD C0 0E            [24] 2558 	push	_bp
      000ABF 85 81 0E         [24] 2559 	mov	_bp,sp
      000AC2 C0 82            [24] 2560 	push	dpl
      000AC4 C0 83            [24] 2561 	push	dph
      000AC6 C0 F0            [24] 2562 	push	b
      000AC8 C0 E0            [24] 2563 	push	acc
      000ACA E5 81            [12] 2564 	mov	a,sp
      000ACC 24 16            [12] 2565 	add	a,#0x16
      000ACE F5 81            [12] 2566 	mov	sp,a
                           000A19  2567 	C$controller_8051.c$117$1_0$75 ==.
                                   2568 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:117: );
      000AD0 E5 0E            [12] 2569 	mov	a,_bp
      000AD2 24 09            [12] 2570 	add	a,#0x09
      000AD4 FB               [12] 2571 	mov	r3,a
      000AD5 FA               [12] 2572 	mov	r2,a
      000AD6 7E 00            [12] 2573 	mov	r6,#0x00
      000AD8 7F 40            [12] 2574 	mov	r7,#0x40
      000ADA 8A 82            [24] 2575 	mov	dpl, r2
      000ADC 8E 83            [24] 2576 	mov	dph, r6
      000ADE 8F F0            [24] 2577 	mov	b, r7
      000AE0 C0 03            [24] 2578 	push	ar3
      000AE2 12 03 E3         [24] 2579 	lcall	_fuzzy_rules_create
                           000A2E  2580 	C$controller_8051.c$119$1_0$75 ==.
                                   2581 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:119: if (!FUZZY_RULE_ADD(
      000AE5 A8 0E            [24] 2582 	mov	r0,_bp
      000AE7 08               [12] 2583 	inc	r0
      000AE8 86 82            [24] 2584 	mov	dpl, @r0
      000AEA 08               [12] 2585 	inc	r0
      000AEB 86 83            [24] 2586 	mov	dph, @r0
      000AED 08               [12] 2587 	inc	r0
      000AEE 86 F0            [24] 2588 	mov	b, @r0
      000AF0 08               [12] 2589 	inc	r0
      000AF1 E6               [12] 2590 	mov	a, @r0
      000AF2 12 09 77         [24] 2591 	lcall	_temperature_low
      000AF5 C8               [12] 2592 	xch	a,r0
      000AF6 E5 0E            [12] 2593 	mov	a,_bp
      000AF8 24 05            [12] 2594 	add	a,#0x05
      000AFA C8               [12] 2595 	xch	a,r0
      000AFB A6 82            [24] 2596 	mov	@r0, dpl
      000AFD 08               [12] 2597 	inc	r0
      000AFE A6 83            [24] 2598 	mov	@r0, dph
      000B00 08               [12] 2599 	inc	r0
      000B01 A6 F0            [24] 2600 	mov	@r0, b
      000B03 08               [12] 2601 	inc	r0
      000B04 F6               [12] 2602 	mov	@r0,a
      000B05 D0 03            [24] 2603 	pop	ar3
      000B07 8B 02            [24] 2604 	mov	ar2,r3
      000B09 7E 00            [12] 2605 	mov	r6,#0x00
      000B0B 7F 40            [12] 2606 	mov	r7,#0x40
      000B0D C0 03            [24] 2607 	push	ar3
      000B0F 74 1A            [12] 2608 	mov	a,#_fan_slow
      000B11 C0 E0            [24] 2609 	push	acc
      000B13 74 0A            [12] 2610 	mov	a,#(_fan_slow >> 8)
      000B15 C0 E0            [24] 2611 	push	acc
      000B17 E5 0E            [12] 2612 	mov	a,_bp
      000B19 24 05            [12] 2613 	add	a,#0x05
      000B1B F8               [12] 2614 	mov	r0,a
      000B1C E6               [12] 2615 	mov	a,@r0
      000B1D C0 E0            [24] 2616 	push	acc
      000B1F 08               [12] 2617 	inc	r0
      000B20 E6               [12] 2618 	mov	a,@r0
      000B21 C0 E0            [24] 2619 	push	acc
      000B23 08               [12] 2620 	inc	r0
      000B24 E6               [12] 2621 	mov	a,@r0
      000B25 C0 E0            [24] 2622 	push	acc
      000B27 08               [12] 2623 	inc	r0
      000B28 E6               [12] 2624 	mov	a,@r0
      000B29 C0 E0            [24] 2625 	push	acc
      000B2B E4               [12] 2626 	clr	a
      000B2C C0 E0            [24] 2627 	push	acc
      000B2E C0 E0            [24] 2628 	push	acc
      000B30 C0 E0            [24] 2629 	push	acc
      000B32 8A 82            [24] 2630 	mov	dpl, r2
      000B34 8E 83            [24] 2631 	mov	dph, r6
      000B36 8F F0            [24] 2632 	mov	b, r7
      000B38 12 04 05         [24] 2633 	lcall	_fuzzy_rules_add
      000B3B AF 82            [24] 2634 	mov	r7, dpl
      000B3D E5 81            [12] 2635 	mov	a,sp
      000B3F 24 F7            [12] 2636 	add	a,#0xf7
      000B41 F5 81            [12] 2637 	mov	sp,a
      000B43 D0 03            [24] 2638 	pop	ar3
      000B45 EF               [12] 2639 	mov	a,r7
      000B46 70 09            [24] 2640 	jnz	00102$
                           000A91  2641 	C$controller_8051.c$124$2_0$76 ==.
                                   2642 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:124: return 0.0f;
      000B48 90 00 00         [24] 2643 	mov	dptr,#0x0000
      000B4B E4               [12] 2644 	clr	a
      000B4C F5 F0            [12] 2645 	mov	b,a
      000B4E 02 0C 28         [24] 2646 	ljmp	00105$
      000B51                       2647 00102$:
                           000A9A  2648 	C$controller_8051.c$127$1_0$75 ==.
                                   2649 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:127: if (!FUZZY_RULE_ADD(
      000B51 A8 0E            [24] 2650 	mov	r0,_bp
      000B53 08               [12] 2651 	inc	r0
      000B54 86 82            [24] 2652 	mov	dpl, @r0
      000B56 08               [12] 2653 	inc	r0
      000B57 86 83            [24] 2654 	mov	dph, @r0
      000B59 08               [12] 2655 	inc	r0
      000B5A 86 F0            [24] 2656 	mov	b, @r0
      000B5C 08               [12] 2657 	inc	r0
      000B5D E6               [12] 2658 	mov	a, @r0
      000B5E C0 03            [24] 2659 	push	ar3
      000B60 12 09 C7         [24] 2660 	lcall	_temperature_high
      000B63 C8               [12] 2661 	xch	a,r0
      000B64 E5 0E            [12] 2662 	mov	a,_bp
      000B66 24 05            [12] 2663 	add	a,#0x05
      000B68 C8               [12] 2664 	xch	a,r0
      000B69 A6 82            [24] 2665 	mov	@r0, dpl
      000B6B 08               [12] 2666 	inc	r0
      000B6C A6 83            [24] 2667 	mov	@r0, dph
      000B6E 08               [12] 2668 	inc	r0
      000B6F A6 F0            [24] 2669 	mov	@r0, b
      000B71 08               [12] 2670 	inc	r0
      000B72 F6               [12] 2671 	mov	@r0,a
      000B73 D0 03            [24] 2672 	pop	ar3
      000B75 8B 02            [24] 2673 	mov	ar2,r3
      000B77 7E 00            [12] 2674 	mov	r6,#0x00
      000B79 7F 40            [12] 2675 	mov	r7,#0x40
      000B7B C0 03            [24] 2676 	push	ar3
      000B7D 74 6A            [12] 2677 	mov	a,#_fan_fast
      000B7F C0 E0            [24] 2678 	push	acc
      000B81 74 0A            [12] 2679 	mov	a,#(_fan_fast >> 8)
      000B83 C0 E0            [24] 2680 	push	acc
      000B85 E5 0E            [12] 2681 	mov	a,_bp
      000B87 24 05            [12] 2682 	add	a,#0x05
      000B89 F8               [12] 2683 	mov	r0,a
      000B8A E6               [12] 2684 	mov	a,@r0
      000B8B C0 E0            [24] 2685 	push	acc
      000B8D 08               [12] 2686 	inc	r0
      000B8E E6               [12] 2687 	mov	a,@r0
      000B8F C0 E0            [24] 2688 	push	acc
      000B91 08               [12] 2689 	inc	r0
      000B92 E6               [12] 2690 	mov	a,@r0
      000B93 C0 E0            [24] 2691 	push	acc
      000B95 08               [12] 2692 	inc	r0
      000B96 E6               [12] 2693 	mov	a,@r0
      000B97 C0 E0            [24] 2694 	push	acc
      000B99 E4               [12] 2695 	clr	a
      000B9A C0 E0            [24] 2696 	push	acc
      000B9C C0 E0            [24] 2697 	push	acc
      000B9E C0 E0            [24] 2698 	push	acc
      000BA0 8A 82            [24] 2699 	mov	dpl, r2
      000BA2 8E 83            [24] 2700 	mov	dph, r6
      000BA4 8F F0            [24] 2701 	mov	b, r7
      000BA6 12 04 05         [24] 2702 	lcall	_fuzzy_rules_add
      000BA9 AF 82            [24] 2703 	mov	r7, dpl
      000BAB E5 81            [12] 2704 	mov	a,sp
      000BAD 24 F7            [12] 2705 	add	a,#0xf7
      000BAF F5 81            [12] 2706 	mov	sp,a
      000BB1 D0 03            [24] 2707 	pop	ar3
      000BB3 EF               [12] 2708 	mov	a,r7
      000BB4 70 08            [24] 2709 	jnz	00104$
                           000AFF  2710 	C$controller_8051.c$132$2_0$77 ==.
                                   2711 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:132: return 0.0f;
      000BB6 90 00 00         [24] 2712 	mov	dptr,#0x0000
      000BB9 E4               [12] 2713 	clr	a
      000BBA F5 F0            [12] 2714 	mov	b,a
      000BBC 80 6A            [24] 2715 	sjmp	00105$
      000BBE                       2716 00104$:
                           000B07  2717 	C$controller_8051.c$137$1_0$75 ==.
                                   2718 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:137: &rules,
      000BBE 8B 05            [24] 2719 	mov	ar5,r3
      000BC0 7E 00            [12] 2720 	mov	r6,#0x00
      000BC2 7F 40            [12] 2721 	mov	r7,#0x40
      000BC4 C0 03            [24] 2722 	push	ar3
      000BC6 E4               [12] 2723 	clr	a
      000BC7 C0 E0            [24] 2724 	push	acc
      000BC9 C0 E0            [24] 2725 	push	acc
      000BCB 74 20            [12] 2726 	mov	a,#0x20
      000BCD C0 E0            [24] 2727 	push	acc
      000BCF 74 41            [12] 2728 	mov	a,#0x41
      000BD1 C0 E0            [24] 2729 	push	acc
      000BD3 E4               [12] 2730 	clr	a
      000BD4 C0 E0            [24] 2731 	push	acc
      000BD6 C0 E0            [24] 2732 	push	acc
      000BD8 74 C8            [12] 2733 	mov	a,#0xc8
      000BDA C0 E0            [24] 2734 	push	acc
      000BDC 74 42            [12] 2735 	mov	a,#0x42
      000BDE C0 E0            [24] 2736 	push	acc
      000BE0 E4               [12] 2737 	clr	a
      000BE1 C0 E0            [24] 2738 	push	acc
      000BE3 C0 E0            [24] 2739 	push	acc
      000BE5 C0 E0            [24] 2740 	push	acc
      000BE7 C0 E0            [24] 2741 	push	acc
      000BE9 8D 82            [24] 2742 	mov	dpl, r5
      000BEB 8E 83            [24] 2743 	mov	dph, r6
      000BED 8F F0            [24] 2744 	mov	b, r7
      000BEF 12 05 32         [24] 2745 	lcall	_fuzzy_rules_cog
      000BF2 C8               [12] 2746 	xch	a,r0
      000BF3 E5 0E            [12] 2747 	mov	a,_bp
      000BF5 24 17            [12] 2748 	add	a,#0x17
      000BF7 C8               [12] 2749 	xch	a,r0
      000BF8 A6 82            [24] 2750 	mov	@r0, dpl
      000BFA 08               [12] 2751 	inc	r0
      000BFB A6 83            [24] 2752 	mov	@r0, dph
      000BFD 08               [12] 2753 	inc	r0
      000BFE A6 F0            [24] 2754 	mov	@r0, b
      000C00 08               [12] 2755 	inc	r0
      000C01 F6               [12] 2756 	mov	@r0,a
      000C02 E5 81            [12] 2757 	mov	a,sp
      000C04 24 F4            [12] 2758 	add	a,#0xf4
      000C06 F5 81            [12] 2759 	mov	sp,a
      000C08 D0 03            [24] 2760 	pop	ar3
                           000B53  2761 	C$controller_8051.c$145$1_0$75 ==.
                                   2762 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:145: );
      000C0A 8B 02            [24] 2763 	mov	ar2,r3
      000C0C 7B 00            [12] 2764 	mov	r3,#0x00
      000C0E 7F 40            [12] 2765 	mov	r7,#0x40
      000C10 8A 82            [24] 2766 	mov	dpl, r2
      000C12 8B 83            [24] 2767 	mov	dph, r3
      000C14 8F F0            [24] 2768 	mov	b, r7
      000C16 12 09 55         [24] 2769 	lcall	_fuzzy_rules_free
                           000B62  2770 	C$controller_8051.c$147$1_0$75 ==.
                                   2771 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:147: return result;
      000C19 E5 0E            [12] 2772 	mov	a,_bp
      000C1B 24 17            [12] 2773 	add	a,#0x17
      000C1D F8               [12] 2774 	mov	r0,a
      000C1E 86 82            [24] 2775 	mov	dpl, @r0
      000C20 08               [12] 2776 	inc	r0
      000C21 86 83            [24] 2777 	mov	dph, @r0
      000C23 08               [12] 2778 	inc	r0
      000C24 86 F0            [24] 2779 	mov	b, @r0
      000C26 08               [12] 2780 	inc	r0
      000C27 E6               [12] 2781 	mov	a, @r0
      000C28                       2782 00105$:
                           000B71  2783 	C$controller_8051.c$148$1_0$75 ==.
                                   2784 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:148: }
      000C28 85 0E 81         [24] 2785 	mov	sp,_bp
      000C2B D0 0E            [24] 2786 	pop	_bp
                           000B76  2787 	C$controller_8051.c$148$1_0$75 ==.
                           000B76  2788 	XFcontroller_8051$calculate_fan_speed$0$0 ==.
      000C2D 22               [24] 2789 	ret
                                   2790 ;------------------------------------------------------------
                                   2791 ;Allocation info for local variables in function 'fan_speed_to_pwm'
                                   2792 ;------------------------------------------------------------
                                   2793 ;fan_speed     Allocated to registers r4 r5 r6 r7 
                                   2794 ;------------------------------------------------------------
                           000B77  2795 	Fcontroller_8051$fan_speed_to_pwm$0$0 ==.
                           000B77  2796 	C$controller_8051.c$155$1_0$79 ==.
                                   2797 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:155: static unsigned char fan_speed_to_pwm(
                                   2798 ;	-----------------------------------------
                                   2799 ;	 function fan_speed_to_pwm
                                   2800 ;	-----------------------------------------
      000C2E                       2801 _fan_speed_to_pwm:
      000C2E AC 82            [24] 2802 	mov	r4,dpl
      000C30 AD 83            [24] 2803 	mov	r5,dph
      000C32 AE F0            [24] 2804 	mov	r6,b
      000C34 FF               [12] 2805 	mov	r7,a
                           000B7E  2806 	C$controller_8051.c$159$1_0$79 ==.
                                   2807 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:159: if (fan_speed <= 0.0f) {
      000C35 C0 07            [24] 2808 	push	ar7
      000C37 C0 06            [24] 2809 	push	ar6
      000C39 C0 05            [24] 2810 	push	ar5
      000C3B C0 04            [24] 2811 	push	ar4
      000C3D C0 04            [24] 2812 	push	ar4
      000C3F C0 05            [24] 2813 	push	ar5
      000C41 C0 06            [24] 2814 	push	ar6
      000C43 C0 07            [24] 2815 	push	ar7
      000C45 90 00 00         [24] 2816 	mov	dptr,#0x0000
      000C48 E4               [12] 2817 	clr	a
      000C49 F5 F0            [12] 2818 	mov	b,a
      000C4B 12 0E 34         [24] 2819 	lcall	___fslt
      000C4E E5 81            [12] 2820 	mov	a,sp
      000C50 24 FC            [12] 2821 	add	a,#0xfc
      000C52 F5 81            [12] 2822 	mov	sp,a
      000C54 D0 04            [24] 2823 	pop	ar4
      000C56 D0 05            [24] 2824 	pop	ar5
      000C58 D0 06            [24] 2825 	pop	ar6
      000C5A D0 07            [24] 2826 	pop	ar7
      000C5C E5 82            [12] 2827 	mov	a, dpl
      000C5E 24 FF            [12] 2828 	add	a,#0xff
      000C60 92 00            [24] 2829 	mov	b0,c
      000C62 40 05            [24] 2830 	jc	00102$
                           000BAD  2831 	C$controller_8051.c$160$2_0$80 ==.
                                   2832 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:160: return 0u;
      000C64 75 82 00         [24] 2833 	mov	dpl, #0x00
      000C67 80 66            [24] 2834 	sjmp	00105$
      000C69                       2835 00102$:
                           000BB2  2836 	C$controller_8051.c$163$1_0$79 ==.
                                   2837 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:163: if (fan_speed >= 100.0f) {
      000C69 C0 07            [24] 2838 	push	ar7
      000C6B C0 06            [24] 2839 	push	ar6
      000C6D C0 05            [24] 2840 	push	ar5
      000C6F C0 04            [24] 2841 	push	ar4
      000C71 E4               [12] 2842 	clr	a
      000C72 C0 E0            [24] 2843 	push	acc
      000C74 C0 E0            [24] 2844 	push	acc
      000C76 74 C8            [12] 2845 	mov	a,#0xc8
      000C78 C0 E0            [24] 2846 	push	acc
      000C7A 74 42            [12] 2847 	mov	a,#0x42
      000C7C C0 E0            [24] 2848 	push	acc
      000C7E 8C 82            [24] 2849 	mov	dpl, r4
      000C80 8D 83            [24] 2850 	mov	dph, r5
      000C82 8E F0            [24] 2851 	mov	b, r6
      000C84 EF               [12] 2852 	mov	a, r7
      000C85 12 0E 34         [24] 2853 	lcall	___fslt
      000C88 E5 81            [12] 2854 	mov	a,sp
      000C8A 24 FC            [12] 2855 	add	a,#0xfc
      000C8C F5 81            [12] 2856 	mov	sp,a
      000C8E D0 04            [24] 2857 	pop	ar4
      000C90 D0 05            [24] 2858 	pop	ar5
      000C92 D0 06            [24] 2859 	pop	ar6
      000C94 D0 07            [24] 2860 	pop	ar7
      000C96 E5 82            [12] 2861 	mov	a, dpl
      000C98 24 FF            [12] 2862 	add	a,#0xff
      000C9A 92 00            [24] 2863 	mov	b0,c
      000C9C 40 05            [24] 2864 	jc	00104$
                           000BE7  2865 	C$controller_8051.c$164$2_0$81 ==.
                                   2866 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:164: return 100u;
      000C9E 75 82 64         [24] 2867 	mov	dpl, #0x64
      000CA1 80 2C            [24] 2868 	sjmp	00105$
      000CA3                       2869 00104$:
                           000BEC  2870 	C$controller_8051.c$169$1_0$79 ==.
                                   2871 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:169: );
      000CA3 E4               [12] 2872 	clr	a
      000CA4 C0 E0            [24] 2873 	push	acc
      000CA6 C0 E0            [24] 2874 	push	acc
      000CA8 C0 E0            [24] 2875 	push	acc
      000CAA 74 3F            [12] 2876 	mov	a,#0x3f
      000CAC C0 E0            [24] 2877 	push	acc
      000CAE 8C 82            [24] 2878 	mov	dpl, r4
      000CB0 8D 83            [24] 2879 	mov	dph, r5
      000CB2 8E F0            [24] 2880 	mov	b, r6
      000CB4 EF               [12] 2881 	mov	a, r7
      000CB5 12 0E 86         [24] 2882 	lcall	___fsadd
      000CB8 AC 82            [24] 2883 	mov	r4, dpl
      000CBA AD 83            [24] 2884 	mov	r5, dph
      000CBC AE F0            [24] 2885 	mov	r6, b
      000CBE FF               [12] 2886 	mov	r7, a
      000CBF E5 81            [12] 2887 	mov	a,sp
      000CC1 24 FC            [12] 2888 	add	a,#0xfc
      000CC3 F5 81            [12] 2889 	mov	sp,a
      000CC5 8C 82            [24] 2890 	mov	dpl, r4
      000CC7 8D 83            [24] 2891 	mov	dph, r5
      000CC9 8E F0            [24] 2892 	mov	b, r6
      000CCB EF               [12] 2893 	mov	a, r7
      000CCC 12 10 70         [24] 2894 	lcall	___fs2uchar
      000CCF                       2895 00105$:
                           000C18  2896 	C$controller_8051.c$170$1_0$79 ==.
                                   2897 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:170: }
                           000C18  2898 	C$controller_8051.c$170$1_0$79 ==.
                           000C18  2899 	XFcontroller_8051$fan_speed_to_pwm$0$0 ==.
      000CCF 22               [24] 2900 	ret
                                   2901 ;------------------------------------------------------------
                                   2902 ;Allocation info for local variables in function 'main'
                                   2903 ;------------------------------------------------------------
                           000C19  2904 	G$main$0$0 ==.
                           000C19  2905 	C$controller_8051.c$185$1_0$83 ==.
                                   2906 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:185: void main(void)
                                   2907 ;	-----------------------------------------
                                   2908 ;	 function main
                                   2909 ;	-----------------------------------------
      000CD0                       2910 _main:
                           000C19  2911 	C$controller_8051.c$192$1_0$83 ==.
                                   2912 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:192: test_temperature = 42u;
      000CD0 75 08 2A         [24] 2913 	mov	_test_temperature,#0x2a
                           000C1C  2914 	C$controller_8051.c$197$1_0$83 ==.
                                   2915 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:197: P0 = 0x55u;
      000CD3 75 80 55         [24] 2916 	mov	_P0,#0x55
                           000C1F  2917 	C$controller_8051.c$198$1_0$83 ==.
                                   2918 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:198: P1 = 0x00u;
      000CD6 75 90 00         [24] 2919 	mov	_P1,#0x00
                           000C22  2920 	C$controller_8051.c$199$1_0$83 ==.
                                   2921 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:199: P2 = test_temperature;
      000CD9 85 08 A0         [24] 2922 	mov	_P2,_test_temperature
                           000C25  2923 	C$controller_8051.c$204$2_0$83 ==.
                                   2924 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:204: );
      000CDC 85 08 82         [24] 2925 	mov	dpl, _test_temperature
      000CDF 12 10 78         [24] 2926 	lcall	___uchar2fs
      000CE2 12 0A BD         [24] 2927 	lcall	_calculate_fan_speed
      000CE5 85 82 0A         [24] 2928 	mov	_test_fan_speed,dpl
      000CE8 85 83 0B         [24] 2929 	mov	(_test_fan_speed + 1),dph
      000CEB 85 F0 0C         [24] 2930 	mov	(_test_fan_speed + 2),b
      000CEE F5 0D            [12] 2931 	mov	(_test_fan_speed + 3),a
                           000C39  2932 	C$controller_8051.c$208$1_0$83 ==.
                                   2933 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:208: test_fan_speed
      000CF0 85 0A 82         [24] 2934 	mov	dpl, _test_fan_speed
      000CF3 85 0B 83         [24] 2935 	mov	dph, (_test_fan_speed + 1)
      000CF6 85 0C F0         [24] 2936 	mov	b, (_test_fan_speed + 2)
      000CF9 E5 0D            [12] 2937 	mov	a, (_test_fan_speed + 3)
      000CFB 12 0C 2E         [24] 2938 	lcall	_fan_speed_to_pwm
      000CFE 85 82 09         [24] 2939 	mov	_test_pwm,dpl
                           000C4A  2940 	C$controller_8051.c$214$1_0$83 ==.
                                   2941 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:214: P1 = test_pwm;
      000D01 85 09 90         [24] 2942 	mov	_P1,_test_pwm
                           000C4D  2943 	C$controller_8051.c$219$1_0$83 ==.
                                   2944 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:219: P0 = 0xAAu;
      000D04 75 80 AA         [24] 2945 	mov	_P0,#0xaa
      000D07                       2946 00103$:
      000D07 80 FE            [24] 2947 	sjmp	00103$
                           000C52  2948 	C$controller_8051.c$224$2_0$83 ==.
                                   2949 ;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:224: }
                           000C52  2950 	C$controller_8051.c$224$2_0$83 ==.
                           000C52  2951 	XG$main$0$0 ==.
      000D09 22               [24] 2952 	ret
                                   2953 	.area CSEG    (CODE)
                                   2954 	.area CONST   (CODE)
                                   2955 	.area CONST   (CODE)
                           000000  2956 Fcontroller_8051$hedges$0_0$0 == .
      001116                       2957 _hedges:
      001116 01                    2958 	.db #0x01	; 1
      001117 02                    2959 	.db #0x02	; 2
      001118 03                    2960 	.db #0x03	; 3
                                   2961 	.area CSEG    (CODE)
                                   2962 	.area XINIT   (CODE)
                                   2963 	.area CABS    (ABS,CODE)
