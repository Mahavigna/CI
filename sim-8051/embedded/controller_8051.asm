;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.0 #15242 (Linux)
;--------------------------------------------------------
	.module controller_8051
	
	.optsdcc -mmcs51 --model-small
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _TF2
	.globl _EXF2
	.globl _RCLK
	.globl _TCLK
	.globl _EXEN2
	.globl _TR2
	.globl _C_T2
	.globl _CP_RL2
	.globl _T2CON_7
	.globl _T2CON_6
	.globl _T2CON_5
	.globl _T2CON_4
	.globl _T2CON_3
	.globl _T2CON_2
	.globl _T2CON_1
	.globl _T2CON_0
	.globl _PT2
	.globl _ET2
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _F1
	.globl _P
	.globl _PS
	.globl _PT1
	.globl _PX1
	.globl _PT0
	.globl _PX0
	.globl _RD
	.globl _WR
	.globl _T1
	.globl _T0
	.globl _INT1
	.globl _INT0
	.globl _TXD
	.globl _RXD
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _EA
	.globl _ES
	.globl _ET1
	.globl _EX1
	.globl _ET0
	.globl _EX0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _SM0
	.globl _SM1
	.globl _SM2
	.globl _REN
	.globl _TB8
	.globl _RB8
	.globl _TI
	.globl _RI
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _TF1
	.globl _TR1
	.globl _TF0
	.globl _TR0
	.globl _IE1
	.globl _IT1
	.globl _IE0
	.globl _IT0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _TH2
	.globl _TL2
	.globl _RCAP2H
	.globl _RCAP2L
	.globl _T2CON
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _IP
	.globl _P3
	.globl _IE
	.globl _P2
	.globl _SBUF
	.globl _SCON
	.globl _P1
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _test_fan_speed
	.globl _test_pwm
	.globl _test_temperature
	.globl _fuzzy_not
	.globl _fuzzy_and_array
	.globl _fuzzy_or_array
	.globl _fuzzy_sugeno_weighted_average_array
	.globl _fuzzy_sugeno_weighted_sum_array
	.globl _fuzzy_ramp
	.globl _fuzzy_function_array
	.globl _fuzzy_rules_create
	.globl _fuzzy_rules_add
	.globl _fuzzy_rules_defuzzify
	.globl _fuzzy_rules_cog
	.globl _fuzzy_rules_free
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
G$P0$0_0$0 == 0x0080
_P0	=	0x0080
G$SP$0_0$0 == 0x0081
_SP	=	0x0081
G$DPL$0_0$0 == 0x0082
_DPL	=	0x0082
G$DPH$0_0$0 == 0x0083
_DPH	=	0x0083
G$PCON$0_0$0 == 0x0087
_PCON	=	0x0087
G$TCON$0_0$0 == 0x0088
_TCON	=	0x0088
G$TMOD$0_0$0 == 0x0089
_TMOD	=	0x0089
G$TL0$0_0$0 == 0x008a
_TL0	=	0x008a
G$TL1$0_0$0 == 0x008b
_TL1	=	0x008b
G$TH0$0_0$0 == 0x008c
_TH0	=	0x008c
G$TH1$0_0$0 == 0x008d
_TH1	=	0x008d
G$P1$0_0$0 == 0x0090
_P1	=	0x0090
G$SCON$0_0$0 == 0x0098
_SCON	=	0x0098
G$SBUF$0_0$0 == 0x0099
_SBUF	=	0x0099
G$P2$0_0$0 == 0x00a0
_P2	=	0x00a0
G$IE$0_0$0 == 0x00a8
_IE	=	0x00a8
G$P3$0_0$0 == 0x00b0
_P3	=	0x00b0
G$IP$0_0$0 == 0x00b8
_IP	=	0x00b8
G$PSW$0_0$0 == 0x00d0
_PSW	=	0x00d0
G$ACC$0_0$0 == 0x00e0
_ACC	=	0x00e0
G$B$0_0$0 == 0x00f0
_B	=	0x00f0
G$T2CON$0_0$0 == 0x00c8
_T2CON	=	0x00c8
G$RCAP2L$0_0$0 == 0x00ca
_RCAP2L	=	0x00ca
G$RCAP2H$0_0$0 == 0x00cb
_RCAP2H	=	0x00cb
G$TL2$0_0$0 == 0x00cc
_TL2	=	0x00cc
G$TH2$0_0$0 == 0x00cd
_TH2	=	0x00cd
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
G$P0_0$0_0$0 == 0x0080
_P0_0	=	0x0080
G$P0_1$0_0$0 == 0x0081
_P0_1	=	0x0081
G$P0_2$0_0$0 == 0x0082
_P0_2	=	0x0082
G$P0_3$0_0$0 == 0x0083
_P0_3	=	0x0083
G$P0_4$0_0$0 == 0x0084
_P0_4	=	0x0084
G$P0_5$0_0$0 == 0x0085
_P0_5	=	0x0085
G$P0_6$0_0$0 == 0x0086
_P0_6	=	0x0086
G$P0_7$0_0$0 == 0x0087
_P0_7	=	0x0087
G$IT0$0_0$0 == 0x0088
_IT0	=	0x0088
G$IE0$0_0$0 == 0x0089
_IE0	=	0x0089
G$IT1$0_0$0 == 0x008a
_IT1	=	0x008a
G$IE1$0_0$0 == 0x008b
_IE1	=	0x008b
G$TR0$0_0$0 == 0x008c
_TR0	=	0x008c
G$TF0$0_0$0 == 0x008d
_TF0	=	0x008d
G$TR1$0_0$0 == 0x008e
_TR1	=	0x008e
G$TF1$0_0$0 == 0x008f
_TF1	=	0x008f
G$P1_0$0_0$0 == 0x0090
_P1_0	=	0x0090
G$P1_1$0_0$0 == 0x0091
_P1_1	=	0x0091
G$P1_2$0_0$0 == 0x0092
_P1_2	=	0x0092
G$P1_3$0_0$0 == 0x0093
_P1_3	=	0x0093
G$P1_4$0_0$0 == 0x0094
_P1_4	=	0x0094
G$P1_5$0_0$0 == 0x0095
_P1_5	=	0x0095
G$P1_6$0_0$0 == 0x0096
_P1_6	=	0x0096
G$P1_7$0_0$0 == 0x0097
_P1_7	=	0x0097
G$RI$0_0$0 == 0x0098
_RI	=	0x0098
G$TI$0_0$0 == 0x0099
_TI	=	0x0099
G$RB8$0_0$0 == 0x009a
_RB8	=	0x009a
G$TB8$0_0$0 == 0x009b
_TB8	=	0x009b
G$REN$0_0$0 == 0x009c
_REN	=	0x009c
G$SM2$0_0$0 == 0x009d
_SM2	=	0x009d
G$SM1$0_0$0 == 0x009e
_SM1	=	0x009e
G$SM0$0_0$0 == 0x009f
_SM0	=	0x009f
G$P2_0$0_0$0 == 0x00a0
_P2_0	=	0x00a0
G$P2_1$0_0$0 == 0x00a1
_P2_1	=	0x00a1
G$P2_2$0_0$0 == 0x00a2
_P2_2	=	0x00a2
G$P2_3$0_0$0 == 0x00a3
_P2_3	=	0x00a3
G$P2_4$0_0$0 == 0x00a4
_P2_4	=	0x00a4
G$P2_5$0_0$0 == 0x00a5
_P2_5	=	0x00a5
G$P2_6$0_0$0 == 0x00a6
_P2_6	=	0x00a6
G$P2_7$0_0$0 == 0x00a7
_P2_7	=	0x00a7
G$EX0$0_0$0 == 0x00a8
_EX0	=	0x00a8
G$ET0$0_0$0 == 0x00a9
_ET0	=	0x00a9
G$EX1$0_0$0 == 0x00aa
_EX1	=	0x00aa
G$ET1$0_0$0 == 0x00ab
_ET1	=	0x00ab
G$ES$0_0$0 == 0x00ac
_ES	=	0x00ac
G$EA$0_0$0 == 0x00af
_EA	=	0x00af
G$P3_0$0_0$0 == 0x00b0
_P3_0	=	0x00b0
G$P3_1$0_0$0 == 0x00b1
_P3_1	=	0x00b1
G$P3_2$0_0$0 == 0x00b2
_P3_2	=	0x00b2
G$P3_3$0_0$0 == 0x00b3
_P3_3	=	0x00b3
G$P3_4$0_0$0 == 0x00b4
_P3_4	=	0x00b4
G$P3_5$0_0$0 == 0x00b5
_P3_5	=	0x00b5
G$P3_6$0_0$0 == 0x00b6
_P3_6	=	0x00b6
G$P3_7$0_0$0 == 0x00b7
_P3_7	=	0x00b7
G$RXD$0_0$0 == 0x00b0
_RXD	=	0x00b0
G$TXD$0_0$0 == 0x00b1
_TXD	=	0x00b1
G$INT0$0_0$0 == 0x00b2
_INT0	=	0x00b2
G$INT1$0_0$0 == 0x00b3
_INT1	=	0x00b3
G$T0$0_0$0 == 0x00b4
_T0	=	0x00b4
G$T1$0_0$0 == 0x00b5
_T1	=	0x00b5
G$WR$0_0$0 == 0x00b6
_WR	=	0x00b6
G$RD$0_0$0 == 0x00b7
_RD	=	0x00b7
G$PX0$0_0$0 == 0x00b8
_PX0	=	0x00b8
G$PT0$0_0$0 == 0x00b9
_PT0	=	0x00b9
G$PX1$0_0$0 == 0x00ba
_PX1	=	0x00ba
G$PT1$0_0$0 == 0x00bb
_PT1	=	0x00bb
G$PS$0_0$0 == 0x00bc
_PS	=	0x00bc
G$P$0_0$0 == 0x00d0
_P	=	0x00d0
G$F1$0_0$0 == 0x00d1
_F1	=	0x00d1
G$OV$0_0$0 == 0x00d2
_OV	=	0x00d2
G$RS0$0_0$0 == 0x00d3
_RS0	=	0x00d3
G$RS1$0_0$0 == 0x00d4
_RS1	=	0x00d4
G$F0$0_0$0 == 0x00d5
_F0	=	0x00d5
G$AC$0_0$0 == 0x00d6
_AC	=	0x00d6
G$CY$0_0$0 == 0x00d7
_CY	=	0x00d7
G$ET2$0_0$0 == 0x00ad
_ET2	=	0x00ad
G$PT2$0_0$0 == 0x00bd
_PT2	=	0x00bd
G$T2CON_0$0_0$0 == 0x00c8
_T2CON_0	=	0x00c8
G$T2CON_1$0_0$0 == 0x00c9
_T2CON_1	=	0x00c9
G$T2CON_2$0_0$0 == 0x00ca
_T2CON_2	=	0x00ca
G$T2CON_3$0_0$0 == 0x00cb
_T2CON_3	=	0x00cb
G$T2CON_4$0_0$0 == 0x00cc
_T2CON_4	=	0x00cc
G$T2CON_5$0_0$0 == 0x00cd
_T2CON_5	=	0x00cd
G$T2CON_6$0_0$0 == 0x00ce
_T2CON_6	=	0x00ce
G$T2CON_7$0_0$0 == 0x00cf
_T2CON_7	=	0x00cf
G$CP_RL2$0_0$0 == 0x00c8
_CP_RL2	=	0x00c8
G$C_T2$0_0$0 == 0x00c9
_C_T2	=	0x00c9
G$TR2$0_0$0 == 0x00ca
_TR2	=	0x00ca
G$EXEN2$0_0$0 == 0x00cb
_EXEN2	=	0x00cb
G$TCLK$0_0$0 == 0x00cc
_TCLK	=	0x00cc
G$RCLK$0_0$0 == 0x00cd
_RCLK	=	0x00cd
G$EXF2$0_0$0 == 0x00ce
_EXF2	=	0x00ce
G$TF2$0_0$0 == 0x00cf
_TF2	=	0x00cf
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; overlayable bit register bank
;--------------------------------------------------------
	.area BIT_BANK	(REL,OVR,DATA)
bits:
	.ds 1
	b0 = bits[0]
	b1 = bits[1]
	b2 = bits[2]
	b3 = bits[3]
	b4 = bits[4]
	b5 = bits[5]
	b6 = bits[6]
	b7 = bits[7]
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
G$test_temperature$0_0$0==.
_test_temperature::
	.ds 1
G$test_pwm$0_0$0==.
_test_pwm::
	.ds 1
G$test_fan_speed$0_0$0==.
_test_fan_speed::
	.ds 4
;--------------------------------------------------------
; overlayable items in internal ram
;--------------------------------------------------------
;--------------------------------------------------------
; Stack segment in internal ram
;--------------------------------------------------------
	.area SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; uninitialized external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; initialized external ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
; restartable atomic support routines
	.ds	5
sdcc_atomic_exchange_rollback_start::
	nop
	nop
sdcc_atomic_exchange_pdata_impl:
	movx	a, @r0
	mov	r3, a
	mov	a, r2
	movx	@r0, a
	sjmp	sdcc_atomic_exchange_exit
	nop
	nop
sdcc_atomic_exchange_xdata_impl:
	movx	a, @dptr
	mov	r3, a
	mov	a, r2
	movx	@dptr, a
	sjmp	sdcc_atomic_exchange_exit
sdcc_atomic_compare_exchange_idata_impl:
	mov	a, @r0
	cjne	a, ar2, .+#5
	mov	a, r3
	mov	@r0, a
	ret
	nop
sdcc_atomic_compare_exchange_pdata_impl:
	movx	a, @r0
	cjne	a, ar2, .+#5
	mov	a, r3
	movx	@r0, a
	ret
	nop
sdcc_atomic_compare_exchange_xdata_impl:
	movx	a, @dptr
	cjne	a, ar2, .+#5
	mov	a, r3
	movx	@dptr, a
	ret
sdcc_atomic_exchange_rollback_end::

sdcc_atomic_exchange_gptr_impl::
	jnb	b.6, sdcc_atomic_exchange_xdata_impl
	mov	r0, dpl
	jb	b.5, sdcc_atomic_exchange_pdata_impl
sdcc_atomic_exchange_idata_impl:
	mov	a, r2
	xch	a, @r0
	mov	dpl, a
	ret
sdcc_atomic_exchange_exit:
	mov	dpl, r3
	ret
sdcc_atomic_compare_exchange_gptr_impl::
	jnb	b.6, sdcc_atomic_compare_exchange_xdata_impl
	mov	r0, dpl
	jb	b.5, sdcc_atomic_compare_exchange_pdata_impl
	sjmp	sdcc_atomic_compare_exchange_idata_impl
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
	C$controller_8051.c$25$2_0$118 ==.
;	../../controller_8051.c:25: volatile unsigned char test_temperature = 0u;
	mov	_test_temperature,#0x00
	C$controller_8051.c$26$2_0$118 ==.
;	../../controller_8051.c:26: volatile unsigned char test_pwm = 0u;
	mov	_test_pwm,#0x00
	C$controller_8051.c$27$2_0$118 ==.
;	../../controller_8051.c:27: volatile float test_fan_speed = 0.0f;
	clr	a
	mov	_test_fan_speed,a
	mov	(_test_fan_speed + 1),a
	mov	(_test_fan_speed + 2),a
	mov	(_test_fan_speed + 3),a
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	ljmp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_clamp'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fcontroller_8051$fuzzy_clamp$0$0 ==.
	C$fuzzy.h$521$0_0$16 ==.
;	../../fuzzy.h:521: static float fuzzy_clamp(float value)
;	-----------------------------------------
;	 function fuzzy_clamp
;	-----------------------------------------
_fuzzy_clamp:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$fuzzy.h$523$1_0$16 ==.
;	../../fuzzy.h:523: if (value < LEVEL_LO) {
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	clr	a
	push	acc
	push	acc
	push	acc
	push	acc
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	lcall	___fslt
	mov	r3, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a,r3
	jz	00102$
	C$fuzzy.h$524$2_0$17 ==.
;	../../fuzzy.h:524: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00105$
00102$:
	C$fuzzy.h$527$1_0$16 ==.
;	../../fuzzy.h:527: if (value > LEVEL_HI) {
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#0x0000
	mov	b, #0x80
	mov	a, #0x3f
	lcall	___fslt
	mov	r3, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a,r3
	jz	00104$
	C$fuzzy.h$528$2_0$18 ==.
;	../../fuzzy.h:528: return LEVEL_HI;
	mov	dptr,#0x0000
	mov	b, #0x80
	mov	a, #0x3f
	sjmp	00105$
00104$:
	C$fuzzy.h$531$1_0$16 ==.
;	../../fuzzy.h:531: return value;
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
00105$:
	C$fuzzy.h$532$1_0$16 ==.
;	../../fuzzy.h:532: }
	C$fuzzy.h$532$1_0$16 ==.
	XFcontroller_8051$fuzzy_clamp$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_not'
;------------------------------------------------------------
;membership    Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	G$fuzzy_not$0$0 ==.
	C$fuzzy.h$537$1_0$20 ==.
;	../../fuzzy.h:537: float fuzzy_not(
;	-----------------------------------------
;	 function fuzzy_not
;	-----------------------------------------
_fuzzy_not:
	C$fuzzy.h$543$1_0$20 ==.
;	../../fuzzy.h:543: membership
	lcall	_fuzzy_clamp
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#0x0000
	mov	b, #0x80
	mov	a, #0x3f
	lcall	___fssub
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	C$fuzzy.h$545$1_0$20 ==.
;	../../fuzzy.h:545: }
	C$fuzzy.h$545$1_0$20 ==.
	XG$fuzzy_not$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_apply_hedge'
;------------------------------------------------------------
;hedge         Allocated to stack - _bp -3 +1 
;membership    Allocated to stack - _bp +1 +4 
;result        Allocated to registers r2 r3 r6 r7 
;------------------------------------------------------------
	Fcontroller_8051$fuzzy_apply_hedge$0$0 ==.
	C$fuzzy.h$555$1_0$22 ==.
;	../../fuzzy.h:555: static float fuzzy_apply_hedge(
;	-----------------------------------------
;	 function fuzzy_apply_hedge
;	-----------------------------------------
_fuzzy_apply_hedge:
	push	_bp
	mov	_bp,sp
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	mov	a,sp
	add	a,#0x04
	mov	sp,a
	C$fuzzy.h$562$1_0$22 ==.
;	../../fuzzy.h:562: membership
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	lcall	_fuzzy_clamp
	mov	r0,_bp
	inc	r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	C$fuzzy.h$567$2_0$23 ==.
;	../../fuzzy.h:567: float result =
	mov	r2,#0x00
	mov	r3,#0x00
	mov	r6,#0x80
	mov	r7,#0x3f
	C$fuzzy.h$570$1_1$23 ==.
;	../../fuzzy.h:570: if (hedge == 0u) {
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	a,@r0
	jnz	00110$
	C$fuzzy.h$572$2_1$24 ==.
;	../../fuzzy.h:572: 1u;
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	@r0,#0x01
	C$fuzzy.h$575$1_1$22 ==.
;	../../fuzzy.h:575: while (hedge > 0u) {
00110$:
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	ar5,@r0
00103$:
	mov	a,r5
	jz	00105$
	C$fuzzy.h$577$1_1$22 ==.
;	../../fuzzy.h:577: membership;
	push	ar5
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	C$fuzzy.h$579$1_1$22 ==.
;	../../fuzzy.h:579: hedge--;
	mov	dpl, r2
	mov	dph, r3
	mov	b, r6
	mov	a, r7
	lcall	___fsmul
	mov	r2, dpl
	mov	r3, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar5
	dec	r5
	sjmp	00103$
00105$:
	C$fuzzy.h$583$1_1$23 ==.
;	../../fuzzy.h:583: result
	mov	dpl, r2
	mov	dph, r3
	mov	b, r6
	mov	a, r7
	lcall	_fuzzy_clamp
	C$fuzzy.h$599$1_1$22 ==.
;	../../fuzzy.h:599: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$599$1_1$22 ==.
	XFcontroller_8051$fuzzy_apply_hedge$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_and_array'
;------------------------------------------------------------
;count         Allocated to stack - _bp -4 +2 
;args          Allocated to stack - _bp -7 +3 
;method        Allocated to registers r5 
;result        Allocated to stack - _bp +5 +4 
;next          Allocated to stack - _bp +9 +4 
;index         Allocated to stack - _bp +13 +2 
;sloc0         Allocated to stack - _bp +1 +3 
;sloc1         Allocated to stack - _bp +4 +1 
;------------------------------------------------------------
	G$fuzzy_and_array$0$0 ==.
	C$fuzzy.h$613$1_1$27 ==.
;	../../fuzzy.h:613: float fuzzy_and_array(
;	-----------------------------------------
;	 function fuzzy_and_array
;	-----------------------------------------
_fuzzy_and_array:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x0e
	mov	sp,a
	mov	r5, dpl
	C$fuzzy.h$624$1_0$27 ==.
;	../../fuzzy.h:624: args == NULL ||
	mov	a,_bp
	add	a,#0xf9
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$625$1_0$27 ==.
;	../../fuzzy.h:625: count == 0u
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00102$
00101$:
	C$fuzzy.h$627$2_0$28 ==.
;	../../fuzzy.h:627: return LEVEL_HI;
	mov	dptr,#0x0000
	mov	b, #0x80
	mov	a, #0x3f
	ljmp	00121$
00102$:
	C$fuzzy.h$631$1_0$27 ==.
;	../../fuzzy.h:631: method != FUZZY_LOGIC_STANDARD &&
	mov	a,r5
	jz	00105$
	C$fuzzy.h$632$1_0$27 ==.
;	../../fuzzy.h:632: method != FUZZY_LOGIC_ALGEBRAIC &&
	cjne	r5,#0x01,00192$
	sjmp	00105$
00192$:
	C$fuzzy.h$634$1_0$27 ==.
;	../../fuzzy.h:634: ) {
	cjne	r5,#0x02,00193$
	sjmp	00105$
00193$:
	C$fuzzy.h$635$2_0$29 ==.
;	../../fuzzy.h:635: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00121$
00105$:
	C$fuzzy.h$640$1_0$27 ==.
;	../../fuzzy.h:640: args[0]
	mov	a,_bp
	add	a,#0xf9
	mov	r0,a
	mov	r1,_bp
	inc	r1
	mov	a,@r0
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	dpl,r2
	mov	dph,r3
	mov	b,r6
	push	ar5
	lcall	_fuzzy_clamp
	xch	a,r0
	mov	a,_bp
	add	a,#0x05
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	pop	ar5
	C$fuzzy.h$644$3_0$31 ==.
;	../../fuzzy.h:644: index = 1u;
	clr	a
	cjne	r5,#0x00,00194$
	inc	a
00194$:
	mov	r3,a
	cjne	r5,#0x01,00196$
	mov	a,r5
	sjmp	00197$
00196$:
	clr	a
00197$:
	mov	r2,a
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	clr	a
	cjne	r5,#0x02,00198$
	inc	a
00198$:
	mov	@r0,a
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	@r0,#0x01
	inc	r0
	mov	@r0,#0x00
00119$:
	C$fuzzy.h$645$2_0$30 ==.
;	../../fuzzy.h:645: index < count;
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	a,_bp
	add	a,#0xfc
	mov	r1,a
	clr	c
	mov	a,@r0
	subb	a,@r1
	inc	r0
	mov	a,@r0
	inc	r1
	subb	a,@r1
	jc	00200$
	ljmp	00117$
00200$:
	C$fuzzy.h$650$1_0$27 ==.
;	../../fuzzy.h:650: args[index]
	push	ar2
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	a,@r0
	add	a,@r0
	mov	r5,a
	inc	r0
	mov	a,@r0
	rlc	a
	mov	r4,a
	mov	a,r5
	add	a,r5
	mov	r5,a
	mov	a,r4
	rlc	a
	mov	r4,a
	mov	r0,_bp
	inc	r0
	mov	a,r5
	add	a, @r0
	mov	r2,a
	mov	a,r4
	inc	r0
	addc	a, @r0
	mov	r4,a
	inc	r0
	mov	ar5,@r0
	mov	dpl,r2
	mov	dph,r4
	mov	b,r5
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	dpl,r2
	mov	dph,r4
	mov	b,r5
	push	ar3
	push	ar2
	lcall	_fuzzy_clamp
	xch	a,r0
	mov	a,_bp
	add	a,#0x09
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	pop	ar2
	pop	ar3
	C$fuzzy.h$653$1_0$27 ==.
;	../../fuzzy.h:653: switch (method) {
	pop	ar2
	mov	a,r3
	jnz	00108$
	mov	a,r2
	jnz	00111$
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	a,@r0
	jz	00203$
	ljmp	00112$
00203$:
	ljmp	00115$
	C$fuzzy.h$654$4_0$32 ==.
;	../../fuzzy.h:654: case FUZZY_LOGIC_STANDARD:
00108$:
	C$fuzzy.h$655$1_0$27 ==.
;	../../fuzzy.h:655: if (next < result) {
	push	ar3
	push	ar2
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	r7, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar2
	pop	ar3
	mov	a,r7
	jnz	00204$
	ljmp	00120$
00204$:
	C$fuzzy.h$656$5_0$33 ==.
;	../../fuzzy.h:656: result = next;
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	mov	a,_bp
	add	a,#0x05
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	C$fuzzy.h$658$4_0$32 ==.
;	../../fuzzy.h:658: break;
	ljmp	00120$
	C$fuzzy.h$660$4_0$32 ==.
;	../../fuzzy.h:660: case FUZZY_LOGIC_ALGEBRAIC:
00111$:
	C$fuzzy.h$662$1_0$27 ==.
;	../../fuzzy.h:662: next;
	push	ar3
	push	ar2
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	C$fuzzy.h$663$1_0$27 ==.
;	../../fuzzy.h:663: break;
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsmul
	xch	a,r0
	mov	a,_bp
	add	a,#0x05
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar2
	pop	ar3
	ljmp	00120$
	C$fuzzy.h$665$4_0$32 ==.
;	../../fuzzy.h:665: case FUZZY_LOGIC_BOUNDED:
00112$:
	C$fuzzy.h$668$1_0$27 ==.
;	../../fuzzy.h:668: next -
	push	ar3
	push	ar2
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsadd
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	clr	a
	push	acc
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0x3f
	push	acc
	C$fuzzy.h$671$1_0$27 ==.
;	../../fuzzy.h:671: if (result < LEVEL_LO) {
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	lcall	___fssub
	xch	a,r0
	mov	a,_bp
	add	a,#0x05
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	clr	a
	push	acc
	push	acc
	push	acc
	push	acc
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	r7, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar2
	pop	ar3
	mov	a,r7
	jz	00120$
	C$fuzzy.h$672$5_0$34 ==.
;	../../fuzzy.h:672: result = LEVEL_LO;
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$674$4_0$32 ==.
;	../../fuzzy.h:674: break;
	C$fuzzy.h$676$4_0$32 ==.
;	../../fuzzy.h:676: default:
	sjmp	00120$
00115$:
	C$fuzzy.h$677$4_0$32 ==.
;	../../fuzzy.h:677: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$678$3_0$31 ==.
;	../../fuzzy.h:678: }
	sjmp	00121$
00120$:
	C$fuzzy.h$646$2_0$30 ==.
;	../../fuzzy.h:646: index++
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	inc	@r0
	cjne	@r0,#0x00,00206$
	inc	r0
	inc	@r0
00206$:
	ljmp	00119$
00117$:
	C$fuzzy.h$682$1_0$27 ==.
;	../../fuzzy.h:682: result
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	_fuzzy_clamp
00121$:
	C$fuzzy.h$684$1_0$27 ==.
;	../../fuzzy.h:684: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$684$1_0$27 ==.
	XG$fuzzy_and_array$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_or_array'
;------------------------------------------------------------
;count         Allocated to stack - _bp -4 +2 
;args          Allocated to stack - _bp -7 +3 
;method        Allocated to registers r5 
;result        Allocated to stack - _bp +10 +4 
;next          Allocated to registers r4 r5 r6 r3 
;index         Allocated to stack - _bp +14 +2 
;sloc0         Allocated to stack - _bp +1 +3 
;sloc1         Allocated to stack - _bp +4 +1 
;sloc2         Allocated to stack - _bp +5 +1 
;sloc3         Allocated to stack - _bp +6 +4 
;------------------------------------------------------------
	G$fuzzy_or_array$0$0 ==.
	C$fuzzy.h$699$1_0$36 ==.
;	../../fuzzy.h:699: float fuzzy_or_array(
;	-----------------------------------------
;	 function fuzzy_or_array
;	-----------------------------------------
_fuzzy_or_array:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x0f
	mov	sp,a
	mov	r5, dpl
	C$fuzzy.h$710$1_0$36 ==.
;	../../fuzzy.h:710: args == NULL ||
	mov	a,_bp
	add	a,#0xf9
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$711$1_0$36 ==.
;	../../fuzzy.h:711: count == 0u
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00102$
00101$:
	C$fuzzy.h$713$2_0$37 ==.
;	../../fuzzy.h:713: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00121$
00102$:
	C$fuzzy.h$717$1_0$36 ==.
;	../../fuzzy.h:717: method != FUZZY_LOGIC_STANDARD &&
	mov	a,r5
	jz	00105$
	C$fuzzy.h$718$1_0$36 ==.
;	../../fuzzy.h:718: method != FUZZY_LOGIC_ALGEBRAIC &&
	cjne	r5,#0x01,00192$
	sjmp	00105$
00192$:
	C$fuzzy.h$720$1_0$36 ==.
;	../../fuzzy.h:720: ) {
	cjne	r5,#0x02,00193$
	sjmp	00105$
00193$:
	C$fuzzy.h$721$2_0$38 ==.
;	../../fuzzy.h:721: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00121$
00105$:
	C$fuzzy.h$726$1_0$36 ==.
;	../../fuzzy.h:726: args[0]
	mov	a,_bp
	add	a,#0xf9
	mov	r0,a
	mov	r1,_bp
	inc	r1
	mov	a,@r0
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	dpl,r2
	mov	dph,r3
	mov	b,r6
	push	ar5
	lcall	_fuzzy_clamp
	xch	a,r0
	mov	a,_bp
	add	a,#0x0a
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	pop	ar5
	C$fuzzy.h$730$3_0$40 ==.
;	../../fuzzy.h:730: index = 1u;
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	clr	a
	cjne	r5,#0x00,00194$
	inc	a
00194$:
	mov	@r0,a
	cjne	r5,#0x01,00196$
	mov	a,r5
	sjmp	00197$
00196$:
	clr	a
00197$:
	mov	r2,a
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	clr	a
	cjne	r5,#0x02,00198$
	inc	a
00198$:
	mov	@r0,a
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	mov	@r0,#0x01
	inc	r0
	mov	@r0,#0x00
00119$:
	C$fuzzy.h$731$2_0$39 ==.
;	../../fuzzy.h:731: index < count;
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	mov	a,_bp
	add	a,#0xfc
	mov	r1,a
	clr	c
	mov	a,@r0
	subb	a,@r1
	inc	r0
	mov	a,@r0
	inc	r1
	subb	a,@r1
	jc	00200$
	ljmp	00117$
00200$:
	C$fuzzy.h$736$1_0$36 ==.
;	../../fuzzy.h:736: args[index]
	push	ar2
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	mov	a,@r0
	add	a,@r0
	mov	r5,a
	inc	r0
	mov	a,@r0
	rlc	a
	mov	r4,a
	mov	a,r5
	add	a,r5
	mov	r5,a
	mov	a,r4
	rlc	a
	mov	r4,a
	mov	r0,_bp
	inc	r0
	mov	a,r5
	add	a, @r0
	mov	r2,a
	mov	a,r4
	inc	r0
	addc	a, @r0
	mov	r4,a
	inc	r0
	mov	ar5,@r0
	mov	dpl,r2
	mov	dph,r4
	mov	b,r5
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	dpl,r2
	mov	dph,r4
	mov	b,r5
	push	ar2
	lcall	_fuzzy_clamp
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r3, a
	pop	ar2
	C$fuzzy.h$739$1_0$36 ==.
;	../../fuzzy.h:739: switch (method) {
	pop	ar2
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,@r0
	jnz	00108$
	mov	a,r2
	jnz	00111$
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	a,@r0
	jz	00203$
	ljmp	00112$
00203$:
	ljmp	00115$
	C$fuzzy.h$740$4_0$41 ==.
;	../../fuzzy.h:740: case FUZZY_LOGIC_STANDARD:
00108$:
	C$fuzzy.h$741$1_0$36 ==.
;	../../fuzzy.h:741: if (next > result) {
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	push	ar2
	push	ar4
	push	ar5
	push	ar6
	push	ar3
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	r7, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar2
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	mov	a,r7
	jnz	00204$
	ljmp	00120$
00204$:
	C$fuzzy.h$742$5_0$42 ==.
;	../../fuzzy.h:742: result = next;
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar5
	inc	r0
	mov	@r0,ar6
	inc	r0
	mov	@r0,ar3
	C$fuzzy.h$744$4_0$41 ==.
;	../../fuzzy.h:744: break;
	ljmp	00120$
	C$fuzzy.h$746$4_0$41 ==.
;	../../fuzzy.h:746: case FUZZY_LOGIC_ALGEBRAIC:
00111$:
	C$fuzzy.h$749$1_0$36 ==.
;	../../fuzzy.h:749: next -
	push	ar2
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	push	ar2
	push	ar4
	push	ar5
	push	ar6
	push	ar3
	C$fuzzy.h$750$1_0$36 ==.
;	../../fuzzy.h:750: result * next;
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsadd
	xch	a,r0
	mov	a,_bp
	add	a,#0x06
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar2
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	push	ar4
	push	ar5
	push	ar6
	push	ar3
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsmul
	mov	r2, dpl
	mov	r3, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	push	ar2
	push	ar2
	push	ar3
	push	ar6
	push	ar7
	C$fuzzy.h$751$1_0$36 ==.
;	../../fuzzy.h:751: break;
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fssub
	xch	a,r0
	mov	a,_bp
	add	a,#0x0a
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar2
	pop	ar2
	C$fuzzy.h$753$4_0$41 ==.
;	../../fuzzy.h:753: case FUZZY_LOGIC_BOUNDED:
	sjmp	00120$
00112$:
	C$fuzzy.h$755$1_0$36 ==.
;	../../fuzzy.h:755: next;
	push	ar2
	push	ar4
	push	ar5
	push	ar6
	push	ar3
	C$fuzzy.h$757$1_0$36 ==.
;	../../fuzzy.h:757: if (result > LEVEL_HI) {
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsadd
	xch	a,r0
	mov	a,_bp
	add	a,#0x0a
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	dptr,#0x0000
	mov	b, #0x80
	mov	a, #0x3f
	lcall	___fslt
	mov	r7, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar2
	mov	a,r7
	jz	00120$
	C$fuzzy.h$758$5_0$43 ==.
;	../../fuzzy.h:758: result = LEVEL_HI;
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,#0x80
	inc	r0
	mov	@r0,#0x3f
	C$fuzzy.h$760$4_0$41 ==.
;	../../fuzzy.h:760: break;
	C$fuzzy.h$762$4_0$41 ==.
;	../../fuzzy.h:762: default:
	sjmp	00120$
00115$:
	C$fuzzy.h$763$4_0$41 ==.
;	../../fuzzy.h:763: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$764$3_0$40 ==.
;	../../fuzzy.h:764: }
	sjmp	00121$
00120$:
	C$fuzzy.h$732$2_0$39 ==.
;	../../fuzzy.h:732: index++
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	inc	@r0
	cjne	@r0,#0x00,00206$
	inc	r0
	inc	@r0
00206$:
	ljmp	00119$
00117$:
	C$fuzzy.h$768$1_0$36 ==.
;	../../fuzzy.h:768: result
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	_fuzzy_clamp
00121$:
	C$fuzzy.h$770$1_0$36 ==.
;	../../fuzzy.h:770: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$770$1_0$36 ==.
	XG$fuzzy_or_array$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_sugeno_weighted_average_array'
;------------------------------------------------------------
;values        Allocated to stack - _bp -5 +3 
;value_count   Allocated to stack - _bp +1 +2 
;weighted_sum  Allocated to stack - _bp +3 +4 
;firing_sum    Allocated to stack - _bp +7 +4 
;firing_strength Allocated to stack - _bp +11 +4 
;consequent    Allocated to registers r4 r5 r3 r2 
;index         Allocated to registers r6 r7 
;------------------------------------------------------------
	G$fuzzy_sugeno_weighted_average_array$0$0 ==.
	C$fuzzy.h$781$1_0$45 ==.
;	../../fuzzy.h:781: float fuzzy_sugeno_weighted_average_array(
;	-----------------------------------------
;	 function fuzzy_sugeno_weighted_average_array
;	-----------------------------------------
_fuzzy_sugeno_weighted_average_array:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	mov	a,sp
	add	a,#0x0c
	mov	sp,a
	C$fuzzy.h$794$1_0$45 ==.
;	../../fuzzy.h:794: values == NULL ||
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$795$1_0$45 ==.
;	../../fuzzy.h:795: value_count == 0u ||
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$796$1_0$45 ==.
;	../../fuzzy.h:796: value_count % 2u != 0u
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	jnb	acc.0,00102$
00101$:
	C$fuzzy.h$798$2_0$46 ==.
;	../../fuzzy.h:798: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00111$
00102$:
	C$fuzzy.h$802$1_0$45 ==.
;	../../fuzzy.h:802: 0.0f;
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$805$1_0$45 ==.
;	../../fuzzy.h:805: 0.0f;
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$808$1_0$45 ==.
;	../../fuzzy.h:808: index = 0u;
	mov	r6,a
	mov	r7,a
00109$:
	C$fuzzy.h$809$2_0$47 ==.
;	../../fuzzy.h:809: index < value_count;
	mov	r0,_bp
	inc	r0
	clr	c
	mov	a,r6
	subb	a,@r0
	mov	a,r7
	inc	r0
	subb	a,@r0
	jc	00147$
	ljmp	00105$
00147$:
	C$fuzzy.h$814$3_0$48 ==.
;	../../fuzzy.h:814: values[index]
	mov	a,r6
	add	a,r6
	mov	r4,a
	mov	a,r7
	rlc	a
	mov	r5,a
	mov	a,r4
	add	a,r4
	mov	r4,a
	mov	a,r5
	rlc	a
	mov	r5,a
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,r4
	add	a, @r0
	mov	r4,a
	mov	a,r5
	inc	r0
	addc	a, @r0
	mov	r5,a
	inc	r0
	mov	ar3,@r0
	mov	dpl,r4
	mov	dph,r5
	mov	b,r3
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	dpl,r4
	mov	dph,r5
	mov	b,r3
	push	ar7
	push	ar6
	lcall	_fuzzy_clamp
	xch	a,r0
	mov	a,_bp
	add	a,#0x0b
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	pop	ar6
	pop	ar7
	C$fuzzy.h$818$3_0$48 ==.
;	../../fuzzy.h:818: values[index + 1u];
	mov	a,#0x01
	add	a, r6
	mov	r4,a
	clr	a
	addc	a, r7
	mov	r5,a
	mov	a,r4
	add	a,r4
	mov	r4,a
	mov	a,r5
	rlc	a
	mov	r5,a
	mov	a,r4
	add	a,r4
	mov	r4,a
	mov	a,r5
	rlc	a
	mov	r5,a
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,r4
	add	a, @r0
	mov	r4,a
	mov	a,r5
	inc	r0
	addc	a, @r0
	mov	r5,a
	inc	r0
	mov	ar3,@r0
	mov	dpl,r4
	mov	dph,r5
	mov	b,r3
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r2,a
	C$fuzzy.h$823$1_0$45 ==.
;	../../fuzzy.h:823: consequent;
	push	ar7
	push	ar6
	push	ar4
	push	ar5
	push	ar3
	push	ar2
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsmul
	mov	r2, dpl
	mov	r3, dph
	mov	r4, b
	mov	r5, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	C$fuzzy.h$826$1_0$45 ==.
;	../../fuzzy.h:826: firing_strength;
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsadd
	mov	r0,_bp
	inc	r0
	inc	r0
	inc	r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	C$fuzzy.h$811$1_0$45 ==.
;	../../fuzzy.h:811: ) {
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsadd
	xch	a,r0
	mov	a,_bp
	add	a,#0x07
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar6
	pop	ar7
	mov	a,#0x02
	add	a, r6
	mov	r6,a
	clr	a
	addc	a, r7
	mov	r7,a
	ljmp	00109$
00105$:
	C$fuzzy.h$829$1_0$45 ==.
;	../../fuzzy.h:829: if (firing_sum <= LEVEL_LO) {
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00107$
	C$fuzzy.h$830$2_0$49 ==.
;	../../fuzzy.h:830: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00111$
00107$:
	C$fuzzy.h$834$1_0$45 ==.
;	../../fuzzy.h:834: firing_sum;
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsdiv
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
00111$:
	C$fuzzy.h$835$1_0$45 ==.
;	../../fuzzy.h:835: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$835$1_0$45 ==.
	XG$fuzzy_sugeno_weighted_average_array$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_sugeno_weighted_sum_array'
;------------------------------------------------------------
;values        Allocated to stack - _bp -5 +3 
;value_count   Allocated to registers r6 r7 
;weighted_sum  Allocated to stack - _bp +1 +4 
;firing_strength Allocated to stack - _bp +5 +4 
;consequent    Allocated to registers r6 r7 r3 r2 
;index         Allocated to registers r4 r5 
;------------------------------------------------------------
	G$fuzzy_sugeno_weighted_sum_array$0$0 ==.
	C$fuzzy.h$845$1_0$51 ==.
;	../../fuzzy.h:845: float fuzzy_sugeno_weighted_sum_array(
;	-----------------------------------------
;	 function fuzzy_sugeno_weighted_sum_array
;	-----------------------------------------
_fuzzy_sugeno_weighted_sum_array:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x08
	mov	sp,a
	mov	r6, dpl
	mov	r7, dph
	C$fuzzy.h$857$1_0$51 ==.
;	../../fuzzy.h:857: values == NULL ||
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$858$1_0$51 ==.
;	../../fuzzy.h:858: value_count == 0u ||
	mov	a,r6
	orl	a,r7
	jz	00101$
	C$fuzzy.h$859$1_0$51 ==.
;	../../fuzzy.h:859: value_count % 2u != 0u
	mov	a,r6
	jnb	acc.0,00102$
00101$:
	C$fuzzy.h$861$2_0$52 ==.
;	../../fuzzy.h:861: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00109$
00102$:
	C$fuzzy.h$865$1_0$51 ==.
;	../../fuzzy.h:865: 0.0f;
	mov	r0,_bp
	inc	r0
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$868$1_0$51 ==.
;	../../fuzzy.h:868: index = 0u;
	mov	r4,a
	mov	r5,a
00107$:
	C$fuzzy.h$869$2_0$53 ==.
;	../../fuzzy.h:869: index < value_count;
	clr	c
	mov	a,r4
	subb	a,r6
	mov	a,r5
	subb	a,r7
	jc	00139$
	ljmp	00105$
00139$:
	C$fuzzy.h$874$1_0$51 ==.
;	../../fuzzy.h:874: values[index]
	push	ar6
	push	ar7
	mov	a,r4
	add	a,r4
	mov	r2,a
	mov	a,r5
	rlc	a
	mov	r3,a
	mov	a,r2
	add	a,r2
	mov	r2,a
	mov	a,r3
	rlc	a
	mov	r3,a
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,r2
	add	a, @r0
	mov	r2,a
	mov	a,r3
	inc	r0
	addc	a, @r0
	mov	r3,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	lcall	_fuzzy_clamp
	xch	a,r0
	mov	a,_bp
	add	a,#0x05
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	C$fuzzy.h$878$3_0$54 ==.
;	../../fuzzy.h:878: values[index + 1u];
	mov	a,#0x01
	add	a, r4
	mov	r6,a
	clr	a
	addc	a, r5
	mov	r7,a
	mov	a,r6
	add	a,r6
	mov	r6,a
	mov	a,r7
	rlc	a
	mov	r7,a
	mov	a,r6
	add	a,r6
	mov	r6,a
	mov	a,r7
	rlc	a
	mov	r7,a
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,r6
	add	a, @r0
	mov	r6,a
	mov	a,r7
	inc	r0
	addc	a, @r0
	mov	r7,a
	inc	r0
	mov	ar3,@r0
	mov	dpl,r6
	mov	dph,r7
	mov	b,r3
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r2,a
	C$fuzzy.h$883$1_0$51 ==.
;	../../fuzzy.h:883: consequent;
	push	ar5
	push	ar4
	push	ar6
	push	ar7
	push	ar3
	push	ar2
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsmul
	mov	r2, dpl
	mov	r3, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar2
	push	ar3
	push	ar6
	push	ar7
	C$fuzzy.h$871$1_0$51 ==.
;	../../fuzzy.h:871: ) {
	mov	r0,_bp
	inc	r0
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsadd
	mov	r0,_bp
	inc	r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a,#0x02
	add	a, r4
	mov	r4,a
	clr	a
	addc	a, r5
	mov	r5,a
	pop	ar7
	pop	ar6
	ljmp	00107$
00105$:
	C$fuzzy.h$886$1_0$51 ==.
;	../../fuzzy.h:886: return weighted_sum;
	mov	r0,_bp
	inc	r0
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
00109$:
	C$fuzzy.h$887$1_0$51 ==.
;	../../fuzzy.h:887: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$887$1_0$51 ==.
	XG$fuzzy_sugeno_weighted_sum_array$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_ramp'
;------------------------------------------------------------
;upper_boundary Allocated to stack - _bp -6 +4 
;value         Allocated to stack - _bp -10 +4 
;ramp_up       Allocated to stack - _bp -11 +1 
;hedge         Allocated to stack - _bp -12 +1 
;lower_boundary Allocated to registers r7 r6 r5 r4 
;result        Allocated to stack - _bp +5 +4 
;normalized    Allocated to registers r4 r5 r6 r7 
;sloc0         Allocated to stack - _bp +13 +4 
;sloc1         Allocated to stack - _bp +1 +4 
;------------------------------------------------------------
	G$fuzzy_ramp$0$0 ==.
	C$fuzzy.h$893$1_0$56 ==.
;	../../fuzzy.h:893: float fuzzy_ramp(
;	-----------------------------------------
;	 function fuzzy_ramp
;	-----------------------------------------
_fuzzy_ramp:
	push	_bp
	mov	_bp,sp
	mov	r7,dpl
	mov	r6,dph
	mov	r5,b
	mov	r4,a
	mov	a,sp
	add	a,#0x08
	mov	sp,a
	C$fuzzy.h$904$1_0$56 ==.
;	../../fuzzy.h:904: if (lower_boundary >= upper_boundary) {
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	dpl, r7
	mov	dph, r6
	mov	b, r5
	mov	a, r4
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00102$
	C$fuzzy.h$905$2_0$57 ==.
;	../../fuzzy.h:905: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00109$
00102$:
	C$fuzzy.h$908$1_0$56 ==.
;	../../fuzzy.h:908: if (value <= lower_boundary) {
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	a,_bp
	add	a,#0xf6
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	dpl, r7
	mov	dph, r6
	mov	b, r5
	mov	a, r4
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00107$
	C$fuzzy.h$910$2_0$58 ==.
;	../../fuzzy.h:910: ramp_up
	mov	a,_bp
	add	a,#0xf5
	mov	r0,a
	mov	a,@r0
	jz	00111$
	C$fuzzy.h$911$2_0$58 ==.
;	../../fuzzy.h:911: ? LEVEL_LO
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	sjmp	00112$
00111$:
	C$fuzzy.h$912$2_0$58 ==.
;	../../fuzzy.h:912: : LEVEL_HI;
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,#0x80
	inc	r0
	mov	@r0,#0x3f
00112$:
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	ar7,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar4,@r0
	ljmp	00108$
00107$:
	C$fuzzy.h$914$1_0$56 ==.
;	../../fuzzy.h:914: else if (value >= upper_boundary) {
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xf6
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00104$
	C$fuzzy.h$916$2_0$59 ==.
;	../../fuzzy.h:916: ramp_up
	mov	a,_bp
	add	a,#0xf5
	mov	r0,a
	mov	a,@r0
	jz	00113$
	C$fuzzy.h$917$2_0$59 ==.
;	../../fuzzy.h:917: ? LEVEL_HI
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,#0x80
	inc	r0
	mov	@r0,#0x3f
	sjmp	00114$
00113$:
	C$fuzzy.h$918$2_0$59 ==.
;	../../fuzzy.h:918: : LEVEL_LO;
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
00114$:
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	ar7,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar4,@r0
	ljmp	00108$
00104$:
	C$fuzzy.h$922$1_0$56 ==.
;	../../fuzzy.h:922: (value - lower_boundary) /
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	C$fuzzy.h$923$1_0$56 ==.
;	../../fuzzy.h:923: (upper_boundary - lower_boundary);
	mov	a,_bp
	add	a,#0xf6
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fssub
	mov	r0,_bp
	inc	r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fssub
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	C$fuzzy.h$926$1_0$56 ==.
;	../../fuzzy.h:926: ramp_up
	mov	r0,_bp
	inc	r0
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsdiv
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,_bp
	add	a,#0xf5
	mov	r0,a
	mov	a,@r0
	jz	00115$
	C$fuzzy.h$927$2_0$60 ==.
;	../../fuzzy.h:927: ? normalized
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar5
	inc	r0
	mov	@r0,ar6
	inc	r0
	mov	@r0,ar7
	sjmp	00116$
00115$:
	C$fuzzy.h$928$1_0$56 ==.
;	../../fuzzy.h:928: : LEVEL_HI - normalized;
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#0x0000
	mov	b, #0x80
	mov	a, #0x3f
	lcall	___fssub
	xch	a,r0
	mov	a,_bp
	add	a,#0x05
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
00116$:
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	ar7,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar4,@r0
00108$:
	C$fuzzy.h$932$1_0$56 ==.
;	../../fuzzy.h:932: result,
	mov	a,_bp
	add	a,#0xf4
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	dpl, r7
	mov	dph, r6
	mov	b, r5
	mov	a, r4
	lcall	_fuzzy_apply_hedge
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	dec	sp
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
00109$:
	C$fuzzy.h$935$1_0$56 ==.
;	../../fuzzy.h:935: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$935$1_0$56 ==.
	XG$fuzzy_ramp$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_function_array'
;------------------------------------------------------------
;value         Allocated to stack - _bp -6 +4 
;hedge         Allocated to stack - _bp -7 +1 
;parameter_count Allocated to stack - _bp -9 +2 
;parameters    Allocated to stack - _bp -12 +3 
;shape         Allocated to registers r7 
;result        Allocated to stack - _bp +5 +4 
;parameter_1   Allocated to stack - _bp +17 +4 
;parameter_2   Allocated to stack - _bp +21 +4 
;parameter_3   Allocated to stack - _bp +25 +4 
;parameter_4   Allocated to registers r5 r6 r7 r4 
;ramp_up       Allocated to registers r7 
;sloc0         Allocated to stack - _bp +23 +3 
;sloc1         Allocated to stack - _bp +1 +4 
;sloc2         Allocated to stack - _bp +5 +4 
;sloc3         Allocated to stack - _bp +9 +4 
;sloc4         Allocated to stack - _bp +13 +4 
;------------------------------------------------------------
	G$fuzzy_function_array$0$0 ==.
	C$fuzzy.h$972$1_0$62 ==.
;	../../fuzzy.h:972: float fuzzy_function_array(
;	-----------------------------------------
;	 function fuzzy_function_array
;	-----------------------------------------
_fuzzy_function_array:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x1c
	mov	sp,a
	mov	r7, dpl
	C$fuzzy.h$994$1_0$62 ==.
;	../../fuzzy.h:994: if (parameters == NULL) {
	mov	a,_bp
	add	a,#0xf4
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00102$
	C$fuzzy.h$995$2_0$63 ==.
;	../../fuzzy.h:995: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00145$
00102$:
	C$fuzzy.h$998$1_0$62 ==.
;	../../fuzzy.h:998: switch (shape) {
	mov	a,r7
	add	a,#0xff - 0x07
	jnc	00267$
	ljmp	00143$
00267$:
	mov	a,r7
	add	a,#(00268$-3-.)
	movc	a,@a+pc
	mov	dpl,a
	mov	a,r7
	add	a,#(00269$-3-.)
	movc	a,@a+pc
	mov	dph,a
	clr	a
	jmp	@a+dptr
00268$:
	.db	00103$
	.db	00106$
	.db	00121$
	.db	00142$
	.db	00142$
	.db	00142$
	.db	00142$
	.db	00142$
00269$:
	.db	00103$>>8
	.db	00106$>>8
	.db	00121$>>8
	.db	00142$>>8
	.db	00142$>>8
	.db	00142$>>8
	.db	00142$>>8
	.db	00142$>>8
	C$fuzzy.h$999$2_0$64 ==.
;	../../fuzzy.h:999: case FUZZY_SHAPE_RAMP:
00103$:
	C$fuzzy.h$1000$2_0$64 ==.
;	../../fuzzy.h:1000: if (parameter_count != 3u) {
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	cjne	@r0,#0x03,00270$
	inc	r0
	cjne	@r0,#0x00,00270$
	sjmp	00105$
00270$:
	C$fuzzy.h$1001$3_0$65 ==.
;	../../fuzzy.h:1001: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00145$
00105$:
	C$fuzzy.h$1004$2_0$64 ==.
;	../../fuzzy.h:1004: parameter_1 = parameters[0];
	mov	a,_bp
	add	a,#0xf4
	mov	r0,a
	mov	ar2,@r0
	inc	r0
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	r0,_bp
	inc	r0
	lcall	__gptrget
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	C$fuzzy.h$1005$2_0$64 ==.
;	../../fuzzy.h:1005: parameter_2 = parameters[1];
	mov	a,#0x04
	add	a, r2
	mov	r5,a
	clr	a
	addc	a, r3
	mov	r6,a
	mov	ar7,r4
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	lcall	__gptrget
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	C$fuzzy.h$1006$2_0$64 ==.
;	../../fuzzy.h:1006: ramp_up = parameters[2] != 0.0f;
	mov	a,#0x08
	add	a, r2
	mov	r2,a
	clr	a
	addc	a, r3
	mov	r3,a
	mov	ar7,r4
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	b,r2
	mov	a,r3
	orl	b,a
	mov	a,r7
	orl	b,a
	mov	a,r6
	anl	a,#0x7F
	orl	a,b
	cjne	a,#0x01,00271$
00271$:
	cpl	c
	mov	b0,c
	clr	a
	rlc	a
	mov	r7,a
	C$fuzzy.h$1009$2_0$64 ==.
;	../../fuzzy.h:1009: parameter_1,
	mov	a,_bp
	add	a,#0xf9
	mov	r0,a
	mov	a,@r0
	push	acc
	push	ar7
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	r0,_bp
	inc	r0
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	_fuzzy_ramp
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf6
	mov	sp,a
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	ljmp	00145$
	C$fuzzy.h$1016$2_0$64 ==.
;	../../fuzzy.h:1016: case FUZZY_SHAPE_TRIANGLE:
00106$:
	C$fuzzy.h$1017$2_0$64 ==.
;	../../fuzzy.h:1017: if (parameter_count != 3u) {
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	cjne	@r0,#0x03,00272$
	inc	r0
	cjne	@r0,#0x00,00272$
	sjmp	00108$
00272$:
	C$fuzzy.h$1018$3_0$66 ==.
;	../../fuzzy.h:1018: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00145$
00108$:
	C$fuzzy.h$1021$2_0$64 ==.
;	../../fuzzy.h:1021: parameter_1 = parameters[0];
	mov	a,_bp
	add	a,#0xf4
	mov	r0,a
	mov	ar2,@r0
	inc	r0
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,_bp
	add	a,#0x11
	mov	r0,a
	lcall	__gptrget
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	C$fuzzy.h$1022$2_0$64 ==.
;	../../fuzzy.h:1022: parameter_2 = parameters[1];
	mov	a,#0x04
	add	a, r2
	mov	r7,a
	clr	a
	addc	a, r3
	mov	r5,a
	mov	ar6,r4
	mov	dpl,r7
	mov	dph,r5
	mov	b,r6
	mov	a,_bp
	add	a,#0x15
	mov	r0,a
	lcall	__gptrget
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	C$fuzzy.h$1023$2_0$64 ==.
;	../../fuzzy.h:1023: parameter_3 = parameters[2];
	mov	a,#0x08
	add	a, r2
	mov	r2,a
	clr	a
	addc	a, r3
	mov	r3,a
	mov	ar7,r4
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	C$fuzzy.h$1026$1_0$62 ==.
;	../../fuzzy.h:1026: parameter_1 >= parameter_2 ||
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	a,_bp
	add	a,#0x15
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x11
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00273$
	ljmp	00115$
00273$:
	C$fuzzy.h$1027$1_0$62 ==.
;	../../fuzzy.h:1027: parameter_2 >= parameter_3 ||
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	push	ar4
	mov	a,_bp
	add	a,#0x15
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jnc	00115$
	C$fuzzy.h$1028$1_0$62 ==.
;	../../fuzzy.h:1028: value <= parameter_1 ||
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x11
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jnc	00115$
	C$fuzzy.h$1030$1_0$62 ==.
;	../../fuzzy.h:1030: ) {
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	push	ar4
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00116$
00115$:
	C$fuzzy.h$1031$3_0$67 ==.
;	../../fuzzy.h:1031: result = LEVEL_LO;
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	ljmp	00144$
00116$:
	C$fuzzy.h$1033$1_0$62 ==.
;	../../fuzzy.h:1033: else if (value == parameter_2) {
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	a,_bp
	add	a,#0x15
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fseq
	mov	r3, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a,r3
	jz	00113$
	C$fuzzy.h$1034$3_0$68 ==.
;	../../fuzzy.h:1034: result = LEVEL_HI;
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,#0x80
	inc	r0
	mov	@r0,#0x3f
	ljmp	00144$
00113$:
	C$fuzzy.h$1036$1_0$62 ==.
;	../../fuzzy.h:1036: else if (value < parameter_2) {
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	a,_bp
	add	a,#0x15
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	r3, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a,r3
	jnz	00278$
	ljmp	00110$
00278$:
	C$fuzzy.h$1038$1_0$62 ==.
;	../../fuzzy.h:1038: (value - parameter_1) /
	mov	a,_bp
	add	a,#0x11
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	C$fuzzy.h$1039$1_0$62 ==.
;	../../fuzzy.h:1039: (parameter_2 - parameter_1);
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fssub
	mov	r7, dpl
	mov	r6, dph
	mov	r5, b
	mov	r4, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	a,_bp
	add	a,#0x11
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x15
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fssub
	xch	a,r0
	mov	a,_bp
	add	a,#0x09
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	dpl, r7
	mov	dph, r6
	mov	b, r5
	mov	a, r4
	lcall	___fsdiv
	xch	a,r0
	mov	a,_bp
	add	a,#0x05
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	ljmp	00144$
00110$:
	C$fuzzy.h$1043$1_0$62 ==.
;	../../fuzzy.h:1043: (parameter_3 - value) /
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	C$fuzzy.h$1044$1_0$62 ==.
;	../../fuzzy.h:1044: (parameter_3 - parameter_2);
	mov	dpl, r5
	mov	dph, r6
	mov	b, r7
	mov	a, r4
	lcall	___fssub
	mov	r0,_bp
	inc	r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a,_bp
	add	a,#0x15
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	dpl, r5
	mov	dph, r6
	mov	b, r7
	mov	a, r4
	lcall	___fssub
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	C$fuzzy.h$1046$1_0$62 ==.
;	../../fuzzy.h:1046: break;
	mov	r0,_bp
	inc	r0
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsdiv
	xch	a,r0
	mov	a,_bp
	add	a,#0x05
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	ljmp	00144$
	C$fuzzy.h$1048$2_0$64 ==.
;	../../fuzzy.h:1048: case FUZZY_SHAPE_TRAPEZOID:
00121$:
	C$fuzzy.h$1049$2_0$64 ==.
;	../../fuzzy.h:1049: if (parameter_count != 4u) {
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	cjne	@r0,#0x04,00279$
	inc	r0
	cjne	@r0,#0x00,00279$
	sjmp	00123$
00279$:
	C$fuzzy.h$1050$3_0$71 ==.
;	../../fuzzy.h:1050: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00145$
00123$:
	C$fuzzy.h$1053$2_0$64 ==.
;	../../fuzzy.h:1053: parameter_1 = parameters[0];
	mov	a,_bp
	add	a,#0xf4
	mov	r0,a
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar7,@r0
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	lcall	__gptrget
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	C$fuzzy.h$1054$2_0$64 ==.
;	../../fuzzy.h:1054: parameter_2 = parameters[1];
	mov	a,#0x04
	add	a, r5
	mov	r2,a
	clr	a
	addc	a, r6
	mov	r3,a
	mov	ar4,r7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	r0,_bp
	inc	r0
	lcall	__gptrget
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	C$fuzzy.h$1055$2_0$64 ==.
;	../../fuzzy.h:1055: parameter_3 = parameters[2];
	mov	a,#0x08
	add	a, r5
	mov	r2,a
	clr	a
	addc	a, r6
	mov	r3,a
	mov	ar4,r7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,_bp
	add	a,#0x19
	mov	r0,a
	lcall	__gptrget
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	C$fuzzy.h$1056$2_0$64 ==.
;	../../fuzzy.h:1056: parameter_4 = parameters[3];
	mov	a,#0x0c
	add	a, r5
	mov	r5,a
	clr	a
	addc	a, r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	C$fuzzy.h$1059$1_0$62 ==.
;	../../fuzzy.h:1059: parameter_1 >= parameter_2 ||
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00280$
	ljmp	00131$
00280$:
	C$fuzzy.h$1060$1_0$62 ==.
;	../../fuzzy.h:1060: parameter_2 > parameter_3 ||
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x19
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	r3, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a,r3
	jz	00281$
	ljmp	00131$
00281$:
	C$fuzzy.h$1061$1_0$62 ==.
;	../../fuzzy.h:1061: parameter_3 >= parameter_4 ||
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	push	ar4
	mov	a,_bp
	add	a,#0x19
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jnc	00131$
	C$fuzzy.h$1062$1_0$62 ==.
;	../../fuzzy.h:1062: value <= parameter_1 ||
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jnc	00131$
	C$fuzzy.h$1064$1_0$62 ==.
;	../../fuzzy.h:1064: ) {
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	push	ar4
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00132$
00131$:
	C$fuzzy.h$1065$3_0$72 ==.
;	../../fuzzy.h:1065: result = LEVEL_LO;
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	ljmp	00144$
00132$:
	C$fuzzy.h$1068$1_0$62 ==.
;	../../fuzzy.h:1068: value >= parameter_2 &&
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00128$
	C$fuzzy.h$1070$1_0$62 ==.
;	../../fuzzy.h:1070: ) {
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x19
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00128$
	C$fuzzy.h$1071$3_0$73 ==.
;	../../fuzzy.h:1071: result = LEVEL_HI;
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,#0x80
	inc	r0
	mov	@r0,#0x3f
	ljmp	00144$
00128$:
	C$fuzzy.h$1073$1_0$62 ==.
;	../../fuzzy.h:1073: else if (value < parameter_2) {
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	r3, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a,r3
	jnz	00287$
	ljmp	00125$
00287$:
	C$fuzzy.h$1075$1_0$62 ==.
;	../../fuzzy.h:1075: (value - parameter_1) /
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	C$fuzzy.h$1076$1_0$62 ==.
;	../../fuzzy.h:1076: (parameter_2 - parameter_1);
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fssub
	mov	r7, dpl
	mov	r6, dph
	mov	r5, b
	mov	r4, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	r0,_bp
	inc	r0
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fssub
	xch	a,r0
	mov	a,_bp
	add	a,#0x09
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	dpl, r7
	mov	dph, r6
	mov	b, r5
	mov	a, r4
	lcall	___fsdiv
	xch	a,r0
	mov	a,_bp
	add	a,#0x05
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	ljmp	00144$
00125$:
	C$fuzzy.h$1080$1_0$62 ==.
;	../../fuzzy.h:1080: (parameter_4 - value) /
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	C$fuzzy.h$1081$1_0$62 ==.
;	../../fuzzy.h:1081: (parameter_4 - parameter_3);
	mov	dpl, r5
	mov	dph, r6
	mov	b, r7
	mov	a, r4
	lcall	___fssub
	xch	a,r0
	mov	a,_bp
	add	a,#0x0d
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a,_bp
	add	a,#0x19
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	dpl, r5
	mov	dph, r6
	mov	b, r7
	mov	a, r4
	lcall	___fssub
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	C$fuzzy.h$1083$1_0$62 ==.
;	../../fuzzy.h:1083: break;
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsdiv
	xch	a,r0
	mov	a,_bp
	add	a,#0x05
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	C$fuzzy.h$1229$2_0$64 ==.
;	../../fuzzy.h:1229: case FUZZY_SHAPE_SIGMOID:
	sjmp	00144$
00142$:
	C$fuzzy.h$1230$2_0$64 ==.
;	../../fuzzy.h:1230: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$1234$2_0$64 ==.
;	../../fuzzy.h:1234: default:
	sjmp	00145$
00143$:
	C$fuzzy.h$1235$2_0$64 ==.
;	../../fuzzy.h:1235: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$1236$1_0$62 ==.
;	../../fuzzy.h:1236: }
	sjmp	00145$
00144$:
	C$fuzzy.h$1239$1_0$62 ==.
;	../../fuzzy.h:1239: result,
	mov	a,_bp
	add	a,#0xf9
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	_fuzzy_apply_hedge
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	dec	sp
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
00145$:
	C$fuzzy.h$1242$1_0$62 ==.
;	../../fuzzy.h:1242: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1242$1_0$62 ==.
	XG$fuzzy_function_array$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_create'
;------------------------------------------------------------
;rules         Allocated to registers r5 r6 r7 
;------------------------------------------------------------
	G$fuzzy_rules_create$0$0 ==.
	C$fuzzy.h$1245$1_0$77 ==.
;	../../fuzzy.h:1245: void fuzzy_rules_create(
;	-----------------------------------------
;	 function fuzzy_rules_create
;	-----------------------------------------
_fuzzy_rules_create:
	mov	r5, dpl
	mov	r6, dph
	mov	r7, b
	C$fuzzy.h$1249$1_0$77 ==.
;	../../fuzzy.h:1249: if (rules == NULL) {
	mov	a,r5
	orl	a,r6
	jnz	00102$
	C$fuzzy.h$1250$2_0$78 ==.
;	../../fuzzy.h:1250: return;
	sjmp	00103$
00102$:
	C$fuzzy.h$1253$1_0$77 ==.
;	../../fuzzy.h:1253: rules->count = 0;
	mov	a,#0x48
	add	a, r5
	mov	r5,a
	clr	a
	addc	a, r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	clr	a
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
00103$:
	C$fuzzy.h$1254$1_0$77 ==.
;	../../fuzzy.h:1254: }
	C$fuzzy.h$1254$1_0$77 ==.
	XG$fuzzy_rules_create$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_add'
;------------------------------------------------------------
;name          Allocated to stack - _bp -5 +3 
;value         Allocated to stack - _bp -9 +4 
;output_function Allocated to stack - _bp -11 +2 
;rules         Allocated to registers r2 r3 r4 
;index         Allocated to registers 
;sloc0         Allocated to stack - _bp +1 +2 
;sloc1         Allocated to stack - _bp +3 +3 
;sloc2         Allocated to stack - _bp +6 +3 
;sloc3         Allocated to stack - _bp +9 +3 
;------------------------------------------------------------
	G$fuzzy_rules_add$0$0 ==.
	C$fuzzy.h$1257$1_0$80 ==.
;	../../fuzzy.h:1257: bool fuzzy_rules_add(
;	-----------------------------------------
;	 function fuzzy_rules_add
;	-----------------------------------------
_fuzzy_rules_add:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x0b
	mov	sp,a
	mov	r2, dpl
	mov	r3, dph
	mov	r4, b
	C$fuzzy.h$1267$1_0$80 ==.
;	../../fuzzy.h:1267: rules == NULL ||
	mov	a,r2
	orl	a,r3
	jz	00101$
	C$fuzzy.h$1268$1_0$80 ==.
;	../../fuzzy.h:1268: output_function == NULL
	mov	a,_bp
	add	a,#0xf5
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00102$
00101$:
	C$fuzzy.h$1270$2_0$81 ==.
;	../../fuzzy.h:1270: return false;
	mov	dpl, #0x00
	ljmp	00106$
00102$:
	C$fuzzy.h$1273$1_0$80 ==.
;	../../fuzzy.h:1273: if (rules->count >= FUZZY_MAX_RULES) {
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	mov	a,#0x48
	add	a, r2
	mov	@r0,a
	clr	a
	addc	a, r3
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,ar4
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r7,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	clr	c
	mov	a,r7
	subb	a,#0x08
	mov	a,r6
	subb	a,#0x00
	jc	00105$
	C$fuzzy.h$1274$2_0$82 ==.
;	../../fuzzy.h:1274: return false;
	mov	dpl, #0x00
	ljmp	00106$
00105$:
	C$fuzzy.h$1280$1_0$80 ==.
;	../../fuzzy.h:1280: rules->rules[index].name =
	push	ar4
	push	ar3
	push	ar2
	push	ar7
	push	ar6
	mov	dptr,#0x0009
	lcall	__mulint
	mov	r0,_bp
	inc	r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	dec	sp
	dec	sp
	pop	ar2
	pop	ar3
	pop	ar4
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	add	a, r2
	mov	r5,a
	inc	r0
	mov	a,@r0
	addc	a, r3
	mov	r6,a
	mov	ar7,r4
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
	C$fuzzy.h$1283$1_0$80 ==.
;	../../fuzzy.h:1283: rules->rules[index].value =
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x03
	mov	r1,a
	mov	a,@r0
	add	a, r2
	mov	@r1,a
	inc	r0
	mov	a,@r0
	addc	a, r3
	inc	r1
	mov	@r1,a
	inc	r1
	mov	@r1,ar4
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	mov	a,_bp
	add	a,#0x06
	mov	r1,a
	mov	a,#0x03
	add	a, @r0
	mov	@r1,a
	clr	a
	inc	r0
	addc	a, @r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	C$fuzzy.h$1284$1_0$80 ==.
;	../../fuzzy.h:1284: fuzzy_clamp(value);
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	_fuzzy_clamp
	mov	r5, dpl
	mov	r6, dph
	mov	r4, b
	mov	r7, a
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,r5
	lcall	__gptrput
	inc	dptr
	mov	a,r6
	lcall	__gptrput
	inc	dptr
	mov	a,r4
	lcall	__gptrput
	inc	dptr
	mov	a,r7
	lcall	__gptrput
	C$fuzzy.h$1286$1_0$80 ==.
;	../../fuzzy.h:1286: rules->rules[index].output_function =
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	mov	a,#0x07
	add	a, @r0
	mov	r5,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r6,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	mov	a,_bp
	add	a,#0xf5
	mov	r0,a
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
	C$fuzzy.h$1289$1_0$80 ==.
;	../../fuzzy.h:1289: rules->count++;
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	inc	r6
	cjne	r6,#0x00,00123$
	inc	r7
00123$:
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,r6
	lcall	__gptrput
	inc	dptr
	mov	a,r7
	lcall	__gptrput
	C$fuzzy.h$1291$1_0$80 ==.
;	../../fuzzy.h:1291: return true;
	mov	dpl, #0x01
00106$:
	C$fuzzy.h$1292$1_0$80 ==.
;	../../fuzzy.h:1292: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1292$1_0$80 ==.
	XG$fuzzy_rules_add$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_defuzzify'
;------------------------------------------------------------
;lower         Allocated to stack - _bp -6 +4 
;upper         Allocated to stack - _bp -10 +4 
;step          Allocated to stack - _bp -14 +4 
;method        Allocated to stack - _bp -15 +1 
;rules         Allocated to stack - _bp +1 +3 
;weighted_sum  Allocated to stack - _bp +20 +4 
;height_sum    Allocated to stack - _bp +24 +4 
;maximum_height Allocated to stack - _bp +28 +4 
;maximum_position_sum Allocated to stack - _bp +32 +4 
;smallest_maximum Allocated to stack - _bp +36 +4 
;largest_maximum Allocated to stack - _bp +40 +4 
;value         Allocated to stack - _bp +44 +4 
;aggregated_height Allocated to stack - _bp +48 +4 
;output_membership Allocated to stack - _bp +52 +4 
;clipped_height Allocated to registers r2 r4 r5 r7 
;maximum_count Allocated to stack - _bp +56 +2 
;i             Allocated to stack - _bp +58 +2 
;maximum_found Allocated to stack - _bp +60 +1 
;sloc0         Allocated to stack - _bp +4 +3 
;sloc1         Allocated to stack - _bp +7 +4 
;sloc2         Allocated to stack - _bp +11 +2 
;sloc3         Allocated to stack - _bp +13 +3 
;sloc4         Allocated to stack - _bp +16 +4 
;------------------------------------------------------------
	G$fuzzy_rules_defuzzify$0$0 ==.
	C$fuzzy.h$1340$1_0$84 ==.
;	../../fuzzy.h:1340: float fuzzy_rules_defuzzify(
;	-----------------------------------------
;	 function fuzzy_rules_defuzzify
;	-----------------------------------------
_fuzzy_rules_defuzzify:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	mov	a,sp
	add	a,#0x39
	mov	sp,a
	C$fuzzy.h$1368$1_0$84 ==.
;	../../fuzzy.h:1368: rules == NULL ||
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00277$
	ljmp	00101$
00277$:
	C$fuzzy.h$1369$1_0$84 ==.
;	../../fuzzy.h:1369: rules->count == 0 ||
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x04
	mov	r1,a
	mov	a,#0x48
	add	a, @r0
	mov	@r1,a
	clr	a
	inc	r0
	addc	a, @r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	orl	a,r6
	jz	00101$
	C$fuzzy.h$1370$1_0$84 ==.
;	../../fuzzy.h:1370: lower > upper ||
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xf6
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	r7, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,r7
	jnz	00101$
	C$fuzzy.h$1372$1_0$84 ==.
;	../../fuzzy.h:1372: ) {
	mov	a,_bp
	add	a,#0xf2
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00102$
00101$:
	C$fuzzy.h$1373$2_0$85 ==.
;	../../fuzzy.h:1373: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00137$
00102$:
	C$fuzzy.h$1377$1_0$84 ==.
;	../../fuzzy.h:1377: method != FUZZY_DEFUZZ_COG &&
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	mov	a,@r0
	jz	00107$
	C$fuzzy.h$1378$1_0$84 ==.
;	../../fuzzy.h:1378: method != FUZZY_DEFUZZ_MOM &&
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	cjne	@r0,#0x01,00282$
	sjmp	00107$
00282$:
	C$fuzzy.h$1379$1_0$84 ==.
;	../../fuzzy.h:1379: method != FUZZY_DEFUZZ_SOM &&
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	cjne	@r0,#0x02,00283$
	sjmp	00107$
00283$:
	C$fuzzy.h$1381$1_0$84 ==.
;	../../fuzzy.h:1381: ) {
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	cjne	@r0,#0x03,00284$
	sjmp	00107$
00284$:
	C$fuzzy.h$1382$2_0$86 ==.
;	../../fuzzy.h:1382: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00137$
00107$:
	C$fuzzy.h$1386$1_0$84 ==.
;	../../fuzzy.h:1386: 0.0f;
	mov	a,_bp
	add	a,#0x14
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$1389$1_0$84 ==.
;	../../fuzzy.h:1389: 0.0f;
	mov	a,_bp
	add	a,#0x18
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$1392$1_0$84 ==.
;	../../fuzzy.h:1392: LEVEL_LO;
	mov	a,_bp
	add	a,#0x1c
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$1395$1_0$84 ==.
;	../../fuzzy.h:1395: 0.0f;
	mov	a,_bp
	add	a,#0x20
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$1398$1_0$84 ==.
;	../../fuzzy.h:1398: lower;
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	a,_bp
	add	a,#0x24
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	C$fuzzy.h$1401$1_0$84 ==.
;	../../fuzzy.h:1401: lower;
	mov	a,_bp
	add	a,#0x24
	mov	r0,a
	mov	a,_bp
	add	a,#0x28
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	C$fuzzy.h$1404$1_0$84 ==.
;	../../fuzzy.h:1404: 0u;
	mov	a,_bp
	add	a,#0x38
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$1407$1_0$84 ==.
;	../../fuzzy.h:1407: false;
	mov	a,_bp
	add	a,#0x3c
	mov	r0,a
	mov	@r0,#0x00
	C$fuzzy.h$1410$2_0$87 ==.
;	../../fuzzy.h:1410: value = lower;
	mov	a,_bp
	add	a,#0x24
	mov	r0,a
	mov	a,_bp
	add	a,#0x2c
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x0d
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
00135$:
	C$fuzzy.h$1411$1_0$84 ==.
;	../../fuzzy.h:1411: value <= upper;
	mov	a,_bp
	add	a,#0x2c
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xf6
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jnc	00285$
	ljmp	00118$
00285$:
	C$fuzzy.h$1415$3_0$88 ==.
;	../../fuzzy.h:1415: LEVEL_LO;
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$1424$1_0$84 ==.
;	../../fuzzy.h:1424: i = 0;
	mov	a,_bp
	add	a,#0x3a
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
00132$:
	C$fuzzy.h$1425$1_0$84 ==.
;	../../fuzzy.h:1425: i < rules->count;
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	mov	a,_bp
	add	a,#0x3a
	mov	r0,a
	clr	c
	mov	a,@r0
	subb	a,r2
	inc	r0
	mov	a,@r0
	subb	a,r7
	jc	00286$
	ljmp	00111$
00286$:
	C$fuzzy.h$1429$1_0$84 ==.
;	../../fuzzy.h:1429: rules->rules[i]
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	a,_bp
	add	a,#0x0b
	mov	r1,a
	mov	a,@r1
	add	a, @r0
	mov	r2,a
	inc	r1
	mov	a,@r1
	inc	r0
	addc	a, @r0
	mov	r3,a
	inc	r0
	mov	ar6,@r0
	mov	a,#0x07
	add	a, r2
	mov	r2,a
	clr	a
	addc	a, r3
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r6
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	C$fuzzy.h$1431$5_0$90 ==.
;	../../fuzzy.h:1431: value
	lcall	00287$
	sjmp	00288$
00287$:
	push	ar2
	push	ar3
	mov	a,_bp
	add	a,#0x2c
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	ret
00288$:
	C$fuzzy.h$1436$5_0$90 ==.
;	../../fuzzy.h:1436: output_membership
	lcall	_fuzzy_clamp
	xch	a,r0
	mov	a,_bp
	add	a,#0x34
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	C$fuzzy.h$1440$5_0$90 ==.
;	../../fuzzy.h:1440: rules->rules[i].value <
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x0b
	mov	r1,a
	mov	a,@r1
	add	a, @r0
	mov	r5,a
	inc	r1
	mov	a,@r1
	inc	r0
	addc	a, @r0
	mov	r6,a
	inc	r0
	mov	ar7,@r0
	mov	a,#0x03
	add	a, r5
	mov	r5,a
	clr	a
	addc	a, r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	mov	a,_bp
	add	a,#0x10
	mov	r0,a
	lcall	__gptrget
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	inc	dptr
	lcall	__gptrget
	inc	r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x34
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x10
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	r7, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,r7
	jz	00139$
	C$fuzzy.h$1442$5_0$90 ==.
;	../../fuzzy.h:1442: ? rules->rules[i].value
	mov	a,_bp
	add	a,#0x10
	mov	r0,a
	mov	ar2,@r0
	inc	r0
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar7,@r0
	sjmp	00140$
00139$:
	C$fuzzy.h$1443$5_0$90 ==.
;	../../fuzzy.h:1443: : output_membership;
	mov	a,_bp
	add	a,#0x34
	mov	r0,a
	mov	ar2,@r0
	inc	r0
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar7,@r0
00140$:
	C$fuzzy.h$1448$1_0$84 ==.
;	../../fuzzy.h:1448: ? aggregated_height
	push	ar7
	push	ar5
	push	ar4
	push	ar2
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	dpl, r2
	mov	dph, r4
	mov	b, r5
	mov	a, r7
	lcall	___fslt
	mov	r6, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar2
	pop	ar4
	pop	ar5
	pop	ar7
	mov	a,r6
	jz	00141$
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	a,_bp
	add	a,#0x10
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	sjmp	00142$
00141$:
	C$fuzzy.h$1449$5_0$90 ==.
;	../../fuzzy.h:1449: : clipped_height;
	mov	a,_bp
	add	a,#0x10
	mov	r0,a
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar5
	inc	r0
	mov	@r0,ar7
00142$:
	mov	a,_bp
	add	a,#0x10
	mov	r0,a
	mov	a,_bp
	add	a,#0x07
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	C$fuzzy.h$1426$1_0$84 ==.
;	../../fuzzy.h:1426: i++
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
	mov	a,#0x09
	add	a, @r0
	mov	@r0,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x3a
	mov	r0,a
	inc	@r0
	cjne	@r0,#0x00,00291$
	inc	r0
	inc	@r0
00291$:
	ljmp	00132$
00111$:
	C$fuzzy.h$1454$3_0$88 ==.
;	../../fuzzy.h:1454: aggregated_height
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	_fuzzy_clamp
	xch	a,r0
	mov	a,_bp
	add	a,#0x30
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	C$fuzzy.h$1462$1_0$84 ==.
;	../../fuzzy.h:1462: aggregated_height;
	mov	a,_bp
	add	a,#0x30
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x2c
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsmul
	mov	r2, dpl
	mov	r3, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	push	ar2
	push	ar3
	push	ar6
	push	ar7
	C$fuzzy.h$1465$1_0$84 ==.
;	../../fuzzy.h:1465: aggregated_height;
	mov	a,_bp
	add	a,#0x14
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsadd
	xch	a,r0
	mov	a,_bp
	add	a,#0x14
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,_bp
	add	a,#0x30
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	C$fuzzy.h$1473$1_0$84 ==.
;	../../fuzzy.h:1473: !maximum_found ||
	mov	a,_bp
	add	a,#0x18
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsadd
	xch	a,r0
	mov	a,_bp
	add	a,#0x18
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,_bp
	add	a,#0x3c
	mov	r0,a
	mov	a,@r0
	jz	00114$
	C$fuzzy.h$1475$1_0$84 ==.
;	../../fuzzy.h:1475: ) {
	mov	a,_bp
	add	a,#0x30
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x1c
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	r7, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,r7
	jz	00115$
00114$:
	C$fuzzy.h$1477$4_0$91 ==.
;	../../fuzzy.h:1477: aggregated_height;
	mov	a,_bp
	add	a,#0x30
	mov	r0,a
	mov	a,_bp
	add	a,#0x1c
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	C$fuzzy.h$1480$4_0$91 ==.
;	../../fuzzy.h:1480: value;
	mov	a,_bp
	add	a,#0x2c
	mov	r0,a
	mov	a,_bp
	add	a,#0x24
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	C$fuzzy.h$1483$4_0$91 ==.
;	../../fuzzy.h:1483: value;
	mov	a,_bp
	add	a,#0x2c
	mov	r0,a
	mov	a,_bp
	add	a,#0x28
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	C$fuzzy.h$1486$4_0$91 ==.
;	../../fuzzy.h:1486: value;
	mov	a,_bp
	add	a,#0x2c
	mov	r0,a
	mov	a,_bp
	add	a,#0x20
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	C$fuzzy.h$1489$4_0$91 ==.
;	../../fuzzy.h:1489: 1u;
	mov	a,_bp
	add	a,#0x38
	mov	r0,a
	mov	@r0,#0x01
	inc	r0
	mov	@r0,#0x00
	C$fuzzy.h$1492$4_0$91 ==.
;	../../fuzzy.h:1492: true;
	mov	a,_bp
	add	a,#0x3c
	mov	r0,a
	mov	@r0,#0x01
	ljmp	00136$
00115$:
	C$fuzzy.h$1496$1_0$84 ==.
;	../../fuzzy.h:1496: ) {
	mov	a,_bp
	add	a,#0x1c
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x30
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fseq
	mov	r7, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,r7
	jz	00136$
	C$fuzzy.h$1498$4_0$92 ==.
;	../../fuzzy.h:1498: value;
	mov	a,_bp
	add	a,#0x2c
	mov	r0,a
	mov	a,_bp
	add	a,#0x28
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	C$fuzzy.h$1501$1_0$84 ==.
;	../../fuzzy.h:1501: value;
	mov	a,_bp
	add	a,#0x2c
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	C$fuzzy.h$1503$1_0$84 ==.
;	../../fuzzy.h:1503: maximum_count++;
	mov	a,_bp
	add	a,#0x20
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsadd
	xch	a,r0
	mov	a,_bp
	add	a,#0x20
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,_bp
	add	a,#0x38
	mov	r0,a
	inc	@r0
	cjne	@r0,#0x00,00295$
	inc	r0
	inc	@r0
00295$:
00136$:
	C$fuzzy.h$1413$1_0$84 ==.
;	../../fuzzy.h:1413: ) {
	mov	a,_bp
	add	a,#0xf2
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x2c
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsadd
	xch	a,r0
	mov	a,_bp
	add	a,#0x2c
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	ljmp	00135$
00118$:
	C$fuzzy.h$1511$1_0$84 ==.
;	../../fuzzy.h:1511: !maximum_found ||
	mov	a,_bp
	add	a,#0x3c
	mov	r0,a
	mov	a,@r0
	jz	00119$
	C$fuzzy.h$1512$1_0$84 ==.
;	../../fuzzy.h:1512: maximum_height <= LEVEL_LO ||
	mov	a,_bp
	add	a,#0x1c
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jnc	00119$
	C$fuzzy.h$1514$1_0$84 ==.
;	../../fuzzy.h:1514: ) {
	mov	a,_bp
	add	a,#0x18
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00120$
00119$:
	C$fuzzy.h$1515$2_0$93 ==.
;	../../fuzzy.h:1515: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00137$
00120$:
	C$fuzzy.h$1518$1_0$84 ==.
;	../../fuzzy.h:1518: switch (method) {
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	mov	a,@r0
	add	a,#0xff - 0x03
	jnc	00299$
	ljmp	00129$
00299$:
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	mov	a,@r0
	add	a,@r0
	add	a,@r0
	mov	dptr,#00300$
	jmp	@a+dptr
00300$:
	ljmp	00123$
	ljmp	00124$
	ljmp	00127$
	ljmp	00128$
	C$fuzzy.h$1519$2_0$94 ==.
;	../../fuzzy.h:1519: case FUZZY_DEFUZZ_COG:
00123$:
	C$fuzzy.h$1521$1_0$84 ==.
;	../../fuzzy.h:1521: height_sum;
	mov	a,_bp
	add	a,#0x18
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x14
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsdiv
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	ljmp	00137$
	C$fuzzy.h$1523$2_0$94 ==.
;	../../fuzzy.h:1523: case FUZZY_DEFUZZ_MOM:
00124$:
	C$fuzzy.h$1524$2_0$94 ==.
;	../../fuzzy.h:1524: if (maximum_count == 0u) {
	mov	a,_bp
	add	a,#0x38
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00126$
	C$fuzzy.h$1525$3_0$95 ==.
;	../../fuzzy.h:1525: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00137$
00126$:
	C$fuzzy.h$1529$1_0$84 ==.
;	../../fuzzy.h:1529: (float)maximum_count;
	mov	a,_bp
	add	a,#0x38
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	lcall	___uint2fs
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	a,_bp
	add	a,#0x20
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsdiv
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	C$fuzzy.h$1531$2_0$94 ==.
;	../../fuzzy.h:1531: case FUZZY_DEFUZZ_SOM:
	sjmp	00137$
00127$:
	C$fuzzy.h$1532$2_0$94 ==.
;	../../fuzzy.h:1532: return smallest_maximum;
	mov	a,_bp
	add	a,#0x24
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	C$fuzzy.h$1534$2_0$94 ==.
;	../../fuzzy.h:1534: case FUZZY_DEFUZZ_LOM:
	sjmp	00137$
00128$:
	C$fuzzy.h$1535$2_0$94 ==.
;	../../fuzzy.h:1535: return largest_maximum;
	mov	a,_bp
	add	a,#0x28
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	C$fuzzy.h$1537$2_0$94 ==.
;	../../fuzzy.h:1537: default:
	sjmp	00137$
00129$:
	C$fuzzy.h$1538$2_0$94 ==.
;	../../fuzzy.h:1538: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$1539$1_0$84 ==.
;	../../fuzzy.h:1539: }
00137$:
	C$fuzzy.h$1540$1_0$84 ==.
;	../../fuzzy.h:1540: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1540$1_0$84 ==.
	XG$fuzzy_rules_defuzzify$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_cog'
;------------------------------------------------------------
;lower         Allocated to stack - _bp -6 +4 
;upper         Allocated to stack - _bp -10 +4 
;step          Allocated to stack - _bp -14 +4 
;rules         Allocated to registers r5 r6 r7 
;------------------------------------------------------------
	G$fuzzy_rules_cog$0$0 ==.
	C$fuzzy.h$1546$1_0$97 ==.
;	../../fuzzy.h:1546: float fuzzy_rules_cog(
;	-----------------------------------------
;	 function fuzzy_rules_cog
;	-----------------------------------------
_fuzzy_rules_cog:
	push	_bp
	mov	_bp,sp
	mov	r5, dpl
	mov	r6, dph
	mov	r7, b
	C$fuzzy.h$1554$1_0$97 ==.
;	../../fuzzy.h:1554: rules,
	clr	a
	push	acc
	mov	a,_bp
	add	a,#0xf2
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xf6
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	dpl, r5
	mov	dph, r6
	mov	b, r7
	lcall	_fuzzy_rules_defuzzify
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf3
	mov	sp,a
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	C$fuzzy.h$1560$1_0$97 ==.
;	../../fuzzy.h:1560: }
	pop	_bp
	C$fuzzy.h$1560$1_0$97 ==.
	XG$fuzzy_rules_cog$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_free'
;------------------------------------------------------------
;rules         Allocated to registers r5 r6 r7 
;------------------------------------------------------------
	G$fuzzy_rules_free$0$0 ==.
	C$fuzzy.h$1562$1_0$99 ==.
;	../../fuzzy.h:1562: void fuzzy_rules_free(
;	-----------------------------------------
;	 function fuzzy_rules_free
;	-----------------------------------------
_fuzzy_rules_free:
	mov	r5, dpl
	mov	r6, dph
	mov	r7, b
	C$fuzzy.h$1566$1_0$99 ==.
;	../../fuzzy.h:1566: if (rules == NULL) {
	mov	a,r5
	orl	a,r6
	jnz	00102$
	C$fuzzy.h$1567$2_0$100 ==.
;	../../fuzzy.h:1567: return;
	sjmp	00103$
00102$:
	C$fuzzy.h$1575$1_0$99 ==.
;	../../fuzzy.h:1575: rules->count = 0;
	mov	a,#0x48
	add	a, r5
	mov	r5,a
	clr	a
	addc	a, r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	clr	a
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
00103$:
	C$fuzzy.h$1576$1_0$99 ==.
;	../../fuzzy.h:1576: }
	C$fuzzy.h$1576$1_0$99 ==.
	XG$fuzzy_rules_free$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'temperature_low'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fcontroller_8051$temperature_low$0$0 ==.
	C$controller_8051.c$59$1_0$102 ==.
;	../../controller_8051.c:59: static float temperature_low(
;	-----------------------------------------
;	 function temperature_low
;	-----------------------------------------
_temperature_low:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$controller_8051.c$68$1_0$102 ==.
;	../../controller_8051.c:68: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$controller_8051.c$64$1_0$102 ==.
;	../../controller_8051.c:64: 20.0f,
	push	ar3
	clr	a
	push	acc
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	push	acc
	push	acc
	mov	a,#0x20
	push	acc
	mov	a,#0x42
	push	acc
	mov	dptr,#0x0000
	mov	b, #0xa0
	dec	a
	lcall	_fuzzy_ramp
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf6
	mov	sp,a
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	C$controller_8051.c$70$1_0$102 ==.
;	../../controller_8051.c:70: }
	C$controller_8051.c$70$1_0$102 ==.
	XFcontroller_8051$temperature_low$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'temperature_high'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fcontroller_8051$temperature_high$0$0 ==.
	C$controller_8051.c$73$1_0$104 ==.
;	../../controller_8051.c:73: static float temperature_high(
;	-----------------------------------------
;	 function temperature_high
;	-----------------------------------------
_temperature_high:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$controller_8051.c$82$1_0$104 ==.
;	../../controller_8051.c:82: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$controller_8051.c$78$1_0$104 ==.
;	../../controller_8051.c:78: 30.0f,
	push	ar3
	mov	a,#0x01
	push	acc
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	clr	a
	push	acc
	push	acc
	mov	a,#0x70
	push	acc
	mov	a,#0x42
	push	acc
	mov	dptr,#0x0000
	mov	b, #0xf0
	dec	a
	lcall	_fuzzy_ramp
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf6
	mov	sp,a
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	C$controller_8051.c$84$1_0$104 ==.
;	../../controller_8051.c:84: }
	C$controller_8051.c$84$1_0$104 ==.
	XFcontroller_8051$temperature_high$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fan_slow'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fcontroller_8051$fan_slow$0$0 ==.
	C$controller_8051.c$91$1_0$106 ==.
;	../../controller_8051.c:91: static float fan_slow(
;	-----------------------------------------
;	 function fan_slow
;	-----------------------------------------
_fan_slow:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$controller_8051.c$100$1_0$106 ==.
;	../../controller_8051.c:100: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$controller_8051.c$96$1_0$106 ==.
;	../../controller_8051.c:96: 20.0f,
	push	ar3
	clr	a
	push	acc
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	push	acc
	push	acc
	mov	a,#0x48
	push	acc
	mov	a,#0x42
	push	acc
	mov	dptr,#0x0000
	mov	b, #0xa0
	dec	a
	lcall	_fuzzy_ramp
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf6
	mov	sp,a
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	C$controller_8051.c$102$1_0$106 ==.
;	../../controller_8051.c:102: }
	C$controller_8051.c$102$1_0$106 ==.
	XFcontroller_8051$fan_slow$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fan_fast'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fcontroller_8051$fan_fast$0$0 ==.
	C$controller_8051.c$105$1_0$108 ==.
;	../../controller_8051.c:105: static float fan_fast(
;	-----------------------------------------
;	 function fan_fast
;	-----------------------------------------
_fan_fast:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$controller_8051.c$114$1_0$108 ==.
;	../../controller_8051.c:114: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$controller_8051.c$110$1_0$108 ==.
;	../../controller_8051.c:110: 40.0f,
	push	ar3
	mov	a,#0x01
	push	acc
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	clr	a
	push	acc
	push	acc
	mov	a,#0xa0
	push	acc
	mov	a,#0x42
	push	acc
	mov	dptr,#0x0000
	mov	b, #0x20
	lcall	_fuzzy_ramp
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf6
	mov	sp,a
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	C$controller_8051.c$116$1_0$108 ==.
;	../../controller_8051.c:116: }
	C$controller_8051.c$116$1_0$108 ==.
	XFcontroller_8051$fan_fast$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'calculate_fan_speed'
;------------------------------------------------------------
;temperature   Allocated to stack - _bp +1 +4 
;rules         Allocated to stack - _bp +9 +74 
;result        Allocated to stack - _bp +83 +4 
;sloc0         Allocated to stack - _bp +5 +4 
;------------------------------------------------------------
	Fcontroller_8051$calculate_fan_speed$0$0 ==.
	C$controller_8051.c$123$1_0$110 ==.
;	../../controller_8051.c:123: static float calculate_fan_speed(
;	-----------------------------------------
;	 function calculate_fan_speed
;	-----------------------------------------
_calculate_fan_speed:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	push	acc
	mov	a,sp
	add	a,#0x52
	mov	sp,a
	C$controller_8051.c$132$1_0$110 ==.
;	../../controller_8051.c:132: );
	mov	a,_bp
	add	a,#0x09
	mov	r3,a
	mov	r2,a
	mov	r6,#0x00
	mov	r7,#0x40
	mov	dpl, r2
	mov	dph, r6
	mov	b, r7
	push	ar3
	lcall	_fuzzy_rules_create
	C$controller_8051.c$134$1_0$110 ==.
;	../../controller_8051.c:134: if (!FUZZY_RULE_ADD(
	mov	r0,_bp
	inc	r0
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	_temperature_low
	xch	a,r0
	mov	a,_bp
	add	a,#0x05
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	pop	ar3
	mov	ar2,r3
	mov	r6,#0x00
	mov	r7,#0x40
	push	ar3
	mov	a,#_fan_slow
	push	acc
	mov	a,#(_fan_slow >> 8)
	push	acc
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,#___str_0
	push	acc
	mov	a,#(___str_0 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	dpl, r2
	mov	dph, r6
	mov	b, r7
	lcall	_fuzzy_rules_add
	mov	r7, dpl
	mov	a,sp
	add	a,#0xf7
	mov	sp,a
	pop	ar3
	mov	a,r7
	C$controller_8051.c$141$2_0$111 ==.
;	../../controller_8051.c:141: );
	jnz	00102$
	mov	ar5,r3
	mov	r6,a
	mov	r7,#0x40
	mov	dpl, r5
	mov	dph, r6
	mov	b, r7
	lcall	_fuzzy_rules_free
	C$controller_8051.c$143$2_0$111 ==.
;	../../controller_8051.c:143: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00105$
00102$:
	C$controller_8051.c$146$1_0$110 ==.
;	../../controller_8051.c:146: if (!FUZZY_RULE_ADD(
	mov	r0,_bp
	inc	r0
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	push	ar3
	lcall	_temperature_high
	xch	a,r0
	mov	a,_bp
	add	a,#0x05
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	pop	ar3
	mov	ar2,r3
	mov	r6,#0x00
	mov	r7,#0x40
	push	ar3
	mov	a,#_fan_fast
	push	acc
	mov	a,#(_fan_fast >> 8)
	push	acc
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,#___str_1
	push	acc
	mov	a,#(___str_1 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	dpl, r2
	mov	dph, r6
	mov	b, r7
	lcall	_fuzzy_rules_add
	mov	r7, dpl
	mov	a,sp
	add	a,#0xf7
	mov	sp,a
	pop	ar3
	mov	a,r7
	C$controller_8051.c$153$2_0$112 ==.
;	../../controller_8051.c:153: );
	jnz	00104$
	mov	ar5,r3
	mov	r6,a
	mov	r7,#0x40
	mov	dpl, r5
	mov	dph, r6
	mov	b, r7
	lcall	_fuzzy_rules_free
	C$controller_8051.c$155$2_0$112 ==.
;	../../controller_8051.c:155: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00105$
00104$:
	C$controller_8051.c$160$1_0$110 ==.
;	../../controller_8051.c:160: &rules,
	mov	ar5,r3
	mov	r6,#0x00
	mov	r7,#0x40
	push	ar3
	mov	a,#0x01
	push	acc
	clr	a
	push	acc
	push	acc
	mov	a,#0x20
	push	acc
	mov	a,#0x41
	push	acc
	clr	a
	push	acc
	push	acc
	mov	a,#0xc8
	push	acc
	mov	a,#0x42
	push	acc
	clr	a
	push	acc
	push	acc
	push	acc
	push	acc
	mov	dpl, r5
	mov	dph, r6
	mov	b, r7
	lcall	_fuzzy_rules_defuzzify
	xch	a,r0
	mov	a,_bp
	add	a,#0x53
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xf3
	mov	sp,a
	pop	ar3
	C$controller_8051.c$169$1_0$110 ==.
;	../../controller_8051.c:169: );
	mov	ar2,r3
	mov	r3,#0x00
	mov	r7,#0x40
	mov	dpl, r2
	mov	dph, r3
	mov	b, r7
	lcall	_fuzzy_rules_free
	C$controller_8051.c$171$1_0$110 ==.
;	../../controller_8051.c:171: return result;
	mov	a,_bp
	add	a,#0x53
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
00105$:
	C$controller_8051.c$172$1_0$110 ==.
;	../../controller_8051.c:172: }
	mov	sp,_bp
	pop	_bp
	C$controller_8051.c$172$1_0$110 ==.
	XFcontroller_8051$calculate_fan_speed$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fan_speed_to_pwm'
;------------------------------------------------------------
;fan_speed     Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fcontroller_8051$fan_speed_to_pwm$0$0 ==.
	C$controller_8051.c$179$1_0$114 ==.
;	../../controller_8051.c:179: static unsigned char fan_speed_to_pwm(
;	-----------------------------------------
;	 function fan_speed_to_pwm
;	-----------------------------------------
_fan_speed_to_pwm:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$controller_8051.c$183$1_0$114 ==.
;	../../controller_8051.c:183: if (fan_speed <= 0.0f) {
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00102$
	C$controller_8051.c$184$2_0$115 ==.
;	../../controller_8051.c:184: return 0u;
	mov	dpl, #0x00
	sjmp	00105$
00102$:
	C$controller_8051.c$187$1_0$114 ==.
;	../../controller_8051.c:187: if (fan_speed >= 100.0f) {
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	clr	a
	push	acc
	push	acc
	mov	a,#0xc8
	push	acc
	mov	a,#0x42
	push	acc
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00104$
	C$controller_8051.c$188$2_0$116 ==.
;	../../controller_8051.c:188: return 100u;
	mov	dpl, #0x64
	sjmp	00105$
00104$:
	C$controller_8051.c$193$1_0$114 ==.
;	../../controller_8051.c:193: );
	clr	a
	push	acc
	push	acc
	push	acc
	mov	a,#0x3f
	push	acc
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	lcall	___fsadd
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	lcall	___fs2uchar
00105$:
	C$controller_8051.c$194$1_0$114 ==.
;	../../controller_8051.c:194: }
	C$controller_8051.c$194$1_0$114 ==.
	XFcontroller_8051$fan_speed_to_pwm$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
	G$main$0$0 ==.
	C$controller_8051.c$211$1_0$118 ==.
;	../../controller_8051.c:211: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	C$controller_8051.c$219$1_0$118 ==.
;	../../controller_8051.c:219: 42u;
	mov	_test_temperature,#0x2a
	C$controller_8051.c$225$1_0$118 ==.
;	../../controller_8051.c:225: 0x55u;
	mov	_P0,#0x55
	C$controller_8051.c$228$1_0$118 ==.
;	../../controller_8051.c:228: 0x00u;
	mov	_P1,#0x00
	C$controller_8051.c$234$1_0$118 ==.
;	../../controller_8051.c:234: test_temperature = P2;
	mov	_test_temperature,_P2
	C$controller_8051.c$239$2_0$118 ==.
;	../../controller_8051.c:239: );
	mov	dpl, _test_temperature
	lcall	___uchar2fs
	lcall	_calculate_fan_speed
	mov	_test_fan_speed,dpl
	mov	(_test_fan_speed + 1),dph
	mov	(_test_fan_speed + 2),b
	mov	(_test_fan_speed + 3),a
	C$controller_8051.c$243$1_0$118 ==.
;	../../controller_8051.c:243: test_fan_speed
	mov	dpl, _test_fan_speed
	mov	dph, (_test_fan_speed + 1)
	mov	b, (_test_fan_speed + 2)
	mov	a, (_test_fan_speed + 3)
	lcall	_fan_speed_to_pwm
	mov	_test_pwm,dpl
	C$controller_8051.c$250$1_0$118 ==.
;	../../controller_8051.c:250: test_pwm;
	mov	_P1,_test_pwm
	C$controller_8051.c$256$1_0$118 ==.
;	../../controller_8051.c:256: 0xAAu;
	mov	_P0,#0xaa
00103$:
	sjmp	00103$
	C$controller_8051.c$261$2_0$118 ==.
;	../../controller_8051.c:261: }
	C$controller_8051.c$261$2_0$118 ==.
	XG$main$0$0 ==.
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area CONST   (CODE)
Fcontroller_8051$hedges$0_0$0 == .
_hedges:
	.db #0x01	; 1
	.db #0x02	; 2
	.db #0x03	; 3
	.area CSEG    (CODE)
Fcontroller_8051$__str_0$0_0$0 == .
	.area CONST   (CODE)
___str_0:
	.ascii "fan_slow"
	.db 0x00
	.area CSEG    (CODE)
Fcontroller_8051$__str_1$0_0$0 == .
	.area CONST   (CODE)
___str_1:
	.ascii "fan_fast"
	.db 0x00
	.area CSEG    (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
