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
	.globl _fuzzy_triangle
	.globl _fuzzy_trapezoid
	.globl _fuzzy_function_array
	.globl _fuzzy_rules_add
	.globl _fuzzy_rules_defuzzify_cog
	.globl _fuzzy_rules_defuzzify_boa
	.globl _fuzzy_rules_defuzzify_cos
	.globl _fuzzy_rules_defuzzify_mom
	.globl _fuzzy_rules_defuzzify_som
	.globl _fuzzy_rules_defuzzify_lom
	.globl _fuzzy_rules_defuzzify_method
	.globl _fuzzy_rules_defuzzify
	.globl _fuzzy_rules_cog
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
Fcontroller_8051$fuzzy_values_buffer$0_0$0==.
_fuzzy_values_buffer:
	.ds 64
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
	C$controller_8051.c$25$2_0$161 ==.
;	../../controller_8051.c:25: volatile unsigned char test_temperature = 0u;
	mov	_test_temperature,#0x00
	C$controller_8051.c$26$2_0$161 ==.
;	../../controller_8051.c:26: volatile unsigned char test_pwm = 0u;
	mov	_test_pwm,#0x00
	C$controller_8051.c$27$2_0$161 ==.
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
;Allocation info for local variables in function 'fuzzy_values_initialize'
;------------------------------------------------------------
;index         Allocated to registers r6 r7 
;------------------------------------------------------------
	Fcontroller_8051$fuzzy_values_initialize$0$0 ==.
	C$fuzzy.h$277$0_0$3 ==.
;	../../fuzzy.h:277: static float *fuzzy_values_initialize(void)
;	-----------------------------------------
;	 function fuzzy_values_initialize
;	-----------------------------------------
_fuzzy_values_initialize:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	C$fuzzy.h$282$3_0$5 ==.
;	../../fuzzy.h:282: index = 0u;
	mov	r6,#0x00
	mov	r7,#0x00
00102$:
	C$fuzzy.h$286$3_0$5 ==.
;	../../fuzzy.h:286: fuzzy_values_buffer[index] = 0.0f;
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
	mov	a,r4
	add	a, #_fuzzy_values_buffer
	mov	r0,a
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
	C$fuzzy.h$284$2_0$4 ==.
;	../../fuzzy.h:284: index++
	inc	r6
	cjne	r6,#0x00,00119$
	inc	r7
00119$:
	C$fuzzy.h$283$2_0$4 ==.
;	../../fuzzy.h:283: index < FUZZY_MAX_VALUES;
	clr	c
	mov	a,r6
	subb	a,#0x10
	mov	a,r7
	subb	a,#0x00
	jc	00102$
	C$fuzzy.h$289$1_0$3 ==.
;	../../fuzzy.h:289: return fuzzy_values_buffer;
	mov	dptr,#_fuzzy_values_buffer
	mov	b, #0x40
	C$fuzzy.h$290$1_0$3 ==.
;	../../fuzzy.h:290: }
	C$fuzzy.h$290$1_0$3 ==.
	XFcontroller_8051$fuzzy_values_initialize$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_clamp'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fcontroller_8051$fuzzy_clamp$0$0 ==.
	C$fuzzy.h$1238$1_0$27 ==.
;	../../fuzzy.h:1238: static float fuzzy_clamp(float value)
;	-----------------------------------------
;	 function fuzzy_clamp
;	-----------------------------------------
_fuzzy_clamp:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$fuzzy.h$1240$1_0$27 ==.
;	../../fuzzy.h:1240: if (value < LEVEL_LO) return LEVEL_LO;
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
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00105$
00102$:
	C$fuzzy.h$1242$1_0$27 ==.
;	../../fuzzy.h:1242: if (value > LEVEL_HI) return LEVEL_HI;
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
	mov	dptr,#0x0000
	mov	b, #0x80
	mov	a, #0x3f
	sjmp	00105$
00104$:
	C$fuzzy.h$1244$1_0$27 ==.
;	../../fuzzy.h:1244: return value;
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
00105$:
	C$fuzzy.h$1245$1_0$27 ==.
;	../../fuzzy.h:1245: }
	C$fuzzy.h$1245$1_0$27 ==.
	XFcontroller_8051$fuzzy_clamp$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_not'
;------------------------------------------------------------
;membership    Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	G$fuzzy_not$0$0 ==.
	C$fuzzy.h$1250$1_0$29 ==.
;	../../fuzzy.h:1250: float fuzzy_not(float membership)
;	-----------------------------------------
;	 function fuzzy_not
;	-----------------------------------------
_fuzzy_not:
	C$fuzzy.h$1252$1_0$29 ==.
;	../../fuzzy.h:1252: return LEVEL_HI - fuzzy_clamp(membership);
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
	C$fuzzy.h$1253$1_0$29 ==.
;	../../fuzzy.h:1253: }
	C$fuzzy.h$1253$1_0$29 ==.
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
	C$fuzzy.h$1263$1_0$31 ==.
;	../../fuzzy.h:1263: static float fuzzy_apply_hedge(
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
	C$fuzzy.h$1269$1_0$31 ==.
;	../../fuzzy.h:1269: fuzzy_clamp( membership
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
	C$fuzzy.h$1274$2_0$32 ==.
;	../../fuzzy.h:1274: float result =
	mov	r2,#0x00
	mov	r3,#0x00
	mov	r6,#0x80
	mov	r7,#0x3f
	C$fuzzy.h$1277$1_1$32 ==.
;	../../fuzzy.h:1277: if (hedge == 0u) {
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	a,@r0
	jnz	00110$
	C$fuzzy.h$1278$2_1$33 ==.
;	../../fuzzy.h:1278: hedge = 1u;
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	@r0,#0x01
	C$fuzzy.h$1281$1_1$31 ==.
;	../../fuzzy.h:1281: while (hedge > 0u) {
00110$:
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	ar5,@r0
00103$:
	mov	a,r5
	jz	00105$
	C$fuzzy.h$1282$1_1$31 ==.
;	../../fuzzy.h:1282: result *= membership;
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
	C$fuzzy.h$1284$1_1$31 ==.
;	../../fuzzy.h:1284: hedge--;
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
	C$fuzzy.h$1288$1_1$32 ==.
;	../../fuzzy.h:1288: result
	mov	dpl, r2
	mov	dph, r3
	mov	b, r6
	mov	a, r7
	lcall	_fuzzy_clamp
	C$fuzzy.h$1304$1_1$31 ==.
;	../../fuzzy.h:1304: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1304$1_1$31 ==.
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
	C$fuzzy.h$1318$1_1$36 ==.
;	../../fuzzy.h:1318: float fuzzy_and_array(
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
	C$fuzzy.h$1329$1_0$36 ==.
;	../../fuzzy.h:1329: args == NULL ||
	mov	a,_bp
	add	a,#0xf9
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$1330$1_0$36 ==.
;	../../fuzzy.h:1330: count == 0u
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00102$
00101$:
	C$fuzzy.h$1332$2_0$37 ==.
;	../../fuzzy.h:1332: return LEVEL_HI;
	mov	dptr,#0x0000
	mov	b, #0x80
	mov	a, #0x3f
	ljmp	00121$
00102$:
	C$fuzzy.h$1336$1_0$36 ==.
;	../../fuzzy.h:1336: method != FUZZY_LOGIC_STANDARD &&
	mov	a,r5
	jz	00105$
	C$fuzzy.h$1337$1_0$36 ==.
;	../../fuzzy.h:1337: method != FUZZY_LOGIC_ALGEBRAIC &&
	cjne	r5,#0x01,00192$
	sjmp	00105$
00192$:
	C$fuzzy.h$1339$1_0$36 ==.
;	../../fuzzy.h:1339: ) {
	cjne	r5,#0x02,00193$
	sjmp	00105$
00193$:
	C$fuzzy.h$1340$2_0$38 ==.
;	../../fuzzy.h:1340: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00121$
00105$:
	C$fuzzy.h$1345$1_0$36 ==.
;	../../fuzzy.h:1345: args[0]
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
	C$fuzzy.h$1349$3_0$40 ==.
;	../../fuzzy.h:1349: index = 1u;
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
	C$fuzzy.h$1350$2_0$39 ==.
;	../../fuzzy.h:1350: index < count;
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
	C$fuzzy.h$1355$1_0$36 ==.
;	../../fuzzy.h:1355: args[index]
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
	C$fuzzy.h$1358$1_0$36 ==.
;	../../fuzzy.h:1358: switch (method) {
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
	C$fuzzy.h$1359$4_0$41 ==.
;	../../fuzzy.h:1359: case FUZZY_LOGIC_STANDARD:
00108$:
	C$fuzzy.h$1360$1_0$36 ==.
;	../../fuzzy.h:1360: if (next < result) {
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
	C$fuzzy.h$1361$5_0$42 ==.
;	../../fuzzy.h:1361: result = next;
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
	C$fuzzy.h$1363$4_0$41 ==.
;	../../fuzzy.h:1363: break;
	ljmp	00120$
	C$fuzzy.h$1365$4_0$41 ==.
;	../../fuzzy.h:1365: case FUZZY_LOGIC_ALGEBRAIC:
00111$:
	C$fuzzy.h$1367$1_0$36 ==.
;	../../fuzzy.h:1367: next;
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
	C$fuzzy.h$1368$1_0$36 ==.
;	../../fuzzy.h:1368: break;
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
	C$fuzzy.h$1370$4_0$41 ==.
;	../../fuzzy.h:1370: case FUZZY_LOGIC_BOUNDED:
00112$:
	C$fuzzy.h$1373$1_0$36 ==.
;	../../fuzzy.h:1373: next -
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
	C$fuzzy.h$1376$1_0$36 ==.
;	../../fuzzy.h:1376: if (result < LEVEL_LO) {
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
	C$fuzzy.h$1377$5_0$43 ==.
;	../../fuzzy.h:1377: result = LEVEL_LO;
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
	C$fuzzy.h$1379$4_0$41 ==.
;	../../fuzzy.h:1379: break;
	C$fuzzy.h$1381$4_0$41 ==.
;	../../fuzzy.h:1381: default:
	sjmp	00120$
00115$:
	C$fuzzy.h$1382$4_0$41 ==.
;	../../fuzzy.h:1382: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$1383$3_0$40 ==.
;	../../fuzzy.h:1383: }
	sjmp	00121$
00120$:
	C$fuzzy.h$1351$2_0$39 ==.
;	../../fuzzy.h:1351: index++
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
	C$fuzzy.h$1387$1_0$36 ==.
;	../../fuzzy.h:1387: result
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
	C$fuzzy.h$1389$1_0$36 ==.
;	../../fuzzy.h:1389: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1389$1_0$36 ==.
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
	C$fuzzy.h$1404$1_0$45 ==.
;	../../fuzzy.h:1404: float fuzzy_or_array(
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
	C$fuzzy.h$1415$1_0$45 ==.
;	../../fuzzy.h:1415: args == NULL ||
	mov	a,_bp
	add	a,#0xf9
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$1416$1_0$45 ==.
;	../../fuzzy.h:1416: count == 0u
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00102$
00101$:
	C$fuzzy.h$1418$2_0$46 ==.
;	../../fuzzy.h:1418: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00121$
00102$:
	C$fuzzy.h$1422$1_0$45 ==.
;	../../fuzzy.h:1422: method != FUZZY_LOGIC_STANDARD &&
	mov	a,r5
	jz	00105$
	C$fuzzy.h$1423$1_0$45 ==.
;	../../fuzzy.h:1423: method != FUZZY_LOGIC_ALGEBRAIC &&
	cjne	r5,#0x01,00192$
	sjmp	00105$
00192$:
	C$fuzzy.h$1425$1_0$45 ==.
;	../../fuzzy.h:1425: ) {
	cjne	r5,#0x02,00193$
	sjmp	00105$
00193$:
	C$fuzzy.h$1426$2_0$47 ==.
;	../../fuzzy.h:1426: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00121$
00105$:
	C$fuzzy.h$1431$1_0$45 ==.
;	../../fuzzy.h:1431: args[0]
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
	C$fuzzy.h$1435$3_0$49 ==.
;	../../fuzzy.h:1435: index = 1u;
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
	C$fuzzy.h$1436$2_0$48 ==.
;	../../fuzzy.h:1436: index < count;
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
	C$fuzzy.h$1441$1_0$45 ==.
;	../../fuzzy.h:1441: args[index]
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
	C$fuzzy.h$1444$1_0$45 ==.
;	../../fuzzy.h:1444: switch (method) {
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
	C$fuzzy.h$1445$4_0$50 ==.
;	../../fuzzy.h:1445: case FUZZY_LOGIC_STANDARD:
00108$:
	C$fuzzy.h$1446$1_0$45 ==.
;	../../fuzzy.h:1446: if (next > result) {
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
	C$fuzzy.h$1447$5_0$51 ==.
;	../../fuzzy.h:1447: result = next;
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
	C$fuzzy.h$1449$4_0$50 ==.
;	../../fuzzy.h:1449: break;
	ljmp	00120$
	C$fuzzy.h$1451$4_0$50 ==.
;	../../fuzzy.h:1451: case FUZZY_LOGIC_ALGEBRAIC:
00111$:
	C$fuzzy.h$1454$1_0$45 ==.
;	../../fuzzy.h:1454: next -
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
	C$fuzzy.h$1455$1_0$45 ==.
;	../../fuzzy.h:1455: result * next;
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
	C$fuzzy.h$1456$1_0$45 ==.
;	../../fuzzy.h:1456: break;
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
	C$fuzzy.h$1458$4_0$50 ==.
;	../../fuzzy.h:1458: case FUZZY_LOGIC_BOUNDED:
	sjmp	00120$
00112$:
	C$fuzzy.h$1460$1_0$45 ==.
;	../../fuzzy.h:1460: next;
	push	ar2
	push	ar4
	push	ar5
	push	ar6
	push	ar3
	C$fuzzy.h$1462$1_0$45 ==.
;	../../fuzzy.h:1462: if (result > LEVEL_HI) {
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
	C$fuzzy.h$1463$5_0$52 ==.
;	../../fuzzy.h:1463: result = LEVEL_HI;
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
	C$fuzzy.h$1465$4_0$50 ==.
;	../../fuzzy.h:1465: break;
	C$fuzzy.h$1467$4_0$50 ==.
;	../../fuzzy.h:1467: default:
	sjmp	00120$
00115$:
	C$fuzzy.h$1468$4_0$50 ==.
;	../../fuzzy.h:1468: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$1469$3_0$49 ==.
;	../../fuzzy.h:1469: }
	sjmp	00121$
00120$:
	C$fuzzy.h$1437$2_0$48 ==.
;	../../fuzzy.h:1437: index++
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
	C$fuzzy.h$1473$1_0$45 ==.
;	../../fuzzy.h:1473: result
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
	C$fuzzy.h$1475$1_0$45 ==.
;	../../fuzzy.h:1475: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1475$1_0$45 ==.
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
	C$fuzzy.h$1486$1_0$54 ==.
;	../../fuzzy.h:1486: float fuzzy_sugeno_weighted_average_array(
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
	C$fuzzy.h$1499$1_0$54 ==.
;	../../fuzzy.h:1499: values == NULL ||
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$1500$1_0$54 ==.
;	../../fuzzy.h:1500: value_count == 0u ||
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$1501$1_0$54 ==.
;	../../fuzzy.h:1501: value_count % 2u != 0u
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	jnb	acc.0,00102$
00101$:
	C$fuzzy.h$1503$2_0$55 ==.
;	../../fuzzy.h:1503: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00111$
00102$:
	C$fuzzy.h$1507$1_0$54 ==.
;	../../fuzzy.h:1507: 0.0f;
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
	C$fuzzy.h$1510$1_0$54 ==.
;	../../fuzzy.h:1510: 0.0f;
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
	C$fuzzy.h$1513$1_0$54 ==.
;	../../fuzzy.h:1513: index = 0u;
	mov	r6,a
	mov	r7,a
00109$:
	C$fuzzy.h$1514$2_0$56 ==.
;	../../fuzzy.h:1514: index < value_count;
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
	C$fuzzy.h$1519$3_0$57 ==.
;	../../fuzzy.h:1519: values[index]
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
	C$fuzzy.h$1523$3_0$57 ==.
;	../../fuzzy.h:1523: values[index + 1u];
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
	C$fuzzy.h$1528$1_0$54 ==.
;	../../fuzzy.h:1528: consequent;
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
	C$fuzzy.h$1531$1_0$54 ==.
;	../../fuzzy.h:1531: firing_strength;
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
	C$fuzzy.h$1516$1_0$54 ==.
;	../../fuzzy.h:1516: ) {
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
	C$fuzzy.h$1534$1_0$54 ==.
;	../../fuzzy.h:1534: if (firing_sum <= LEVEL_LO) {
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
	C$fuzzy.h$1535$2_0$58 ==.
;	../../fuzzy.h:1535: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00111$
00107$:
	C$fuzzy.h$1539$1_0$54 ==.
;	../../fuzzy.h:1539: firing_sum;
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
	C$fuzzy.h$1540$1_0$54 ==.
;	../../fuzzy.h:1540: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1540$1_0$54 ==.
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
	C$fuzzy.h$1550$1_0$60 ==.
;	../../fuzzy.h:1550: float fuzzy_sugeno_weighted_sum_array(
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
	C$fuzzy.h$1562$1_0$60 ==.
;	../../fuzzy.h:1562: values == NULL ||
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$1563$1_0$60 ==.
;	../../fuzzy.h:1563: value_count == 0u ||
	mov	a,r6
	orl	a,r7
	jz	00101$
	C$fuzzy.h$1564$1_0$60 ==.
;	../../fuzzy.h:1564: value_count % 2u != 0u
	mov	a,r6
	jnb	acc.0,00102$
00101$:
	C$fuzzy.h$1566$2_0$61 ==.
;	../../fuzzy.h:1566: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00109$
00102$:
	C$fuzzy.h$1570$1_0$60 ==.
;	../../fuzzy.h:1570: 0.0f;
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
	C$fuzzy.h$1573$1_0$60 ==.
;	../../fuzzy.h:1573: index = 0u;
	mov	r4,a
	mov	r5,a
00107$:
	C$fuzzy.h$1574$2_0$62 ==.
;	../../fuzzy.h:1574: index < value_count;
	clr	c
	mov	a,r4
	subb	a,r6
	mov	a,r5
	subb	a,r7
	jc	00139$
	ljmp	00105$
00139$:
	C$fuzzy.h$1579$1_0$60 ==.
;	../../fuzzy.h:1579: values[index]
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
	C$fuzzy.h$1583$3_0$63 ==.
;	../../fuzzy.h:1583: values[index + 1u];
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
	C$fuzzy.h$1588$1_0$60 ==.
;	../../fuzzy.h:1588: consequent;
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
	C$fuzzy.h$1576$1_0$60 ==.
;	../../fuzzy.h:1576: ) {
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
	C$fuzzy.h$1591$1_0$60 ==.
;	../../fuzzy.h:1591: return weighted_sum;
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
	C$fuzzy.h$1592$1_0$60 ==.
;	../../fuzzy.h:1592: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1592$1_0$60 ==.
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
	C$fuzzy.h$1598$1_0$65 ==.
;	../../fuzzy.h:1598: float fuzzy_ramp(
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
	C$fuzzy.h$1609$1_0$65 ==.
;	../../fuzzy.h:1609: if (lower_boundary >= upper_boundary) {
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
	C$fuzzy.h$1610$2_0$66 ==.
;	../../fuzzy.h:1610: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00109$
00102$:
	C$fuzzy.h$1613$1_0$65 ==.
;	../../fuzzy.h:1613: if (value <= lower_boundary) {
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
	C$fuzzy.h$1615$2_0$67 ==.
;	../../fuzzy.h:1615: ramp_up
	mov	a,_bp
	add	a,#0xf5
	mov	r0,a
	mov	a,@r0
	jz	00111$
	C$fuzzy.h$1616$2_0$67 ==.
;	../../fuzzy.h:1616: ? LEVEL_LO
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
	C$fuzzy.h$1617$2_0$67 ==.
;	../../fuzzy.h:1617: : LEVEL_HI;
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
	C$fuzzy.h$1619$1_0$65 ==.
;	../../fuzzy.h:1619: else if (value >= upper_boundary) {
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
	C$fuzzy.h$1621$2_0$68 ==.
;	../../fuzzy.h:1621: ramp_up
	mov	a,_bp
	add	a,#0xf5
	mov	r0,a
	mov	a,@r0
	jz	00113$
	C$fuzzy.h$1622$2_0$68 ==.
;	../../fuzzy.h:1622: ? LEVEL_HI
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
	C$fuzzy.h$1623$2_0$68 ==.
;	../../fuzzy.h:1623: : LEVEL_LO;
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
	C$fuzzy.h$1627$1_0$65 ==.
;	../../fuzzy.h:1627: (value - lower_boundary) /
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	C$fuzzy.h$1628$1_0$65 ==.
;	../../fuzzy.h:1628: (upper_boundary - lower_boundary);
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
	C$fuzzy.h$1631$1_0$65 ==.
;	../../fuzzy.h:1631: ramp_up
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
	C$fuzzy.h$1632$2_0$69 ==.
;	../../fuzzy.h:1632: ? normalized
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
	C$fuzzy.h$1633$1_0$65 ==.
;	../../fuzzy.h:1633: : LEVEL_HI - normalized;
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
	C$fuzzy.h$1637$1_0$65 ==.
;	../../fuzzy.h:1637: result,
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
	C$fuzzy.h$1640$1_0$65 ==.
;	../../fuzzy.h:1640: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1640$1_0$65 ==.
	XG$fuzzy_ramp$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_triangle'
;------------------------------------------------------------
;b             Allocated to stack - _bp -6 +4 
;c             Allocated to stack - _bp -10 +4 
;value         Allocated to stack - _bp -14 +4 
;hedge         Allocated to stack - _bp -15 +1 
;a             Allocated to registers r7 r6 r5 r4 
;result        Allocated to stack - _bp +1 +4 
;sloc0         Allocated to stack - _bp +1 +4 
;sloc1         Allocated to stack - _bp +5 +4 
;------------------------------------------------------------
	G$fuzzy_triangle$0$0 ==.
	C$fuzzy.h$1684$1_0$71 ==.
;	../../fuzzy.h:1684: float fuzzy_triangle(
;	-----------------------------------------
;	 function fuzzy_triangle
;	-----------------------------------------
_fuzzy_triangle:
	push	_bp
	mov	_bp,sp
	mov	r7,dpl
	mov	r6,dph
	mov	r5,b
	mov	r4,a
	mov	a,sp
	add	a,#0x08
	mov	sp,a
	C$fuzzy.h$1695$1_0$71 ==.
;	../../fuzzy.h:1695: a >= b ||
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
	jc	00145$
	ljmp	00107$
00145$:
	C$fuzzy.h$1696$1_0$71 ==.
;	../../fuzzy.h:1696: b >= c ||
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
	jc	00146$
	ljmp	00107$
00146$:
	C$fuzzy.h$1697$1_0$71 ==.
;	../../fuzzy.h:1697: value <= a ||
	push	ar7
	push	ar6
	push	ar5
	push	ar4
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
	jnc	00107$
	C$fuzzy.h$1699$1_0$71 ==.
;	../../fuzzy.h:1699: ) {
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
	mov	a,_bp
	add	a,#0xf2
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
	jc	00108$
00107$:
	C$fuzzy.h$1700$2_0$72 ==.
;	../../fuzzy.h:1700: result = LEVEL_LO;
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
	ljmp	00109$
00108$:
	C$fuzzy.h$1702$1_0$71 ==.
;	../../fuzzy.h:1702: else if (value == b) {
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
	add	a,#0xf2
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
	jz	00105$
	C$fuzzy.h$1703$2_0$73 ==.
;	../../fuzzy.h:1703: result = LEVEL_HI;
	mov	r0,_bp
	inc	r0
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,#0x80
	inc	r0
	mov	@r0,#0x3f
	ljmp	00109$
00105$:
	C$fuzzy.h$1705$1_0$71 ==.
;	../../fuzzy.h:1705: else if (value < b) {
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
	add	a,#0xf2
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
	jnz	00150$
	ljmp	00102$
00150$:
	C$fuzzy.h$1707$1_0$71 ==.
;	../../fuzzy.h:1707: (value - a) /
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	C$fuzzy.h$1708$1_0$71 ==.
;	../../fuzzy.h:1708: (b - a);
	mov	a,_bp
	add	a,#0xf2
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
	lcall	___fsdiv
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
	ljmp	00109$
00102$:
	C$fuzzy.h$1712$1_0$71 ==.
;	../../fuzzy.h:1712: (c - value) /
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
	C$fuzzy.h$1713$1_0$71 ==.
;	../../fuzzy.h:1713: (c - b);
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
	lcall	___fssub
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
	lcall	___fsdiv
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
00109$:
	C$fuzzy.h$1717$1_0$71 ==.
;	../../fuzzy.h:1717: result,
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
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
	C$fuzzy.h$1720$1_0$71 ==.
;	../../fuzzy.h:1720: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1720$1_0$71 ==.
	XG$fuzzy_triangle$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_trapezoid'
;------------------------------------------------------------
;b             Allocated to stack - _bp -6 +4 
;c             Allocated to stack - _bp -10 +4 
;d             Allocated to stack - _bp -14 +4 
;value         Allocated to stack - _bp -18 +4 
;hedge         Allocated to stack - _bp -19 +1 
;a             Allocated to registers r7 r6 r5 r4 
;result        Allocated to stack - _bp +1 +4 
;sloc0         Allocated to stack - _bp +1 +4 
;sloc1         Allocated to stack - _bp +5 +4 
;------------------------------------------------------------
	G$fuzzy_trapezoid$0$0 ==.
	C$fuzzy.h$1722$1_0$77 ==.
;	../../fuzzy.h:1722: float fuzzy_trapezoid(
;	-----------------------------------------
;	 function fuzzy_trapezoid
;	-----------------------------------------
_fuzzy_trapezoid:
	push	_bp
	mov	_bp,sp
	mov	r7,dpl
	mov	r6,dph
	mov	r5,b
	mov	r4,a
	mov	a,sp
	add	a,#0x08
	mov	sp,a
	C$fuzzy.h$1734$1_0$77 ==.
;	../../fuzzy.h:1734: a >= b ||
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
	jc	00159$
	ljmp	00108$
00159$:
	C$fuzzy.h$1735$1_0$77 ==.
;	../../fuzzy.h:1735: b > c ||
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
	mov	r3, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a,r3
	jz	00160$
	ljmp	00108$
00160$:
	C$fuzzy.h$1736$1_0$77 ==.
;	../../fuzzy.h:1736: c >= d ||
	push	ar7
	push	ar6
	push	ar5
	push	ar4
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
	jc	00161$
	ljmp	00108$
00161$:
	C$fuzzy.h$1737$1_0$77 ==.
;	../../fuzzy.h:1737: value <= a ||
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	a,_bp
	add	a,#0xee
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
	jnc	00108$
	C$fuzzy.h$1739$1_0$77 ==.
;	../../fuzzy.h:1739: ) {
	push	ar7
	push	ar6
	push	ar5
	push	ar4
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
	add	a,#0xee
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
	jc	00109$
00108$:
	C$fuzzy.h$1740$2_0$78 ==.
;	../../fuzzy.h:1740: result = LEVEL_LO;
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
	ljmp	00110$
00109$:
	C$fuzzy.h$1743$1_0$77 ==.
;	../../fuzzy.h:1743: value >= b &&
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
	add	a,#0xee
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
	jc	00105$
	C$fuzzy.h$1745$1_0$77 ==.
;	../../fuzzy.h:1745: ) {
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	a,_bp
	add	a,#0xee
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
	jc	00105$
	C$fuzzy.h$1746$2_0$79 ==.
;	../../fuzzy.h:1746: result = LEVEL_HI;
	mov	r0,_bp
	inc	r0
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,#0x80
	inc	r0
	mov	@r0,#0x3f
	ljmp	00110$
00105$:
	C$fuzzy.h$1748$1_0$77 ==.
;	../../fuzzy.h:1748: else if (value < b) {
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
	add	a,#0xee
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
	jnz	00166$
	ljmp	00102$
00166$:
	C$fuzzy.h$1750$1_0$77 ==.
;	../../fuzzy.h:1750: (value - a) /
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	C$fuzzy.h$1751$1_0$77 ==.
;	../../fuzzy.h:1751: (b - a);
	mov	a,_bp
	add	a,#0xee
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
	lcall	___fsdiv
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
	ljmp	00110$
00102$:
	C$fuzzy.h$1755$1_0$77 ==.
;	../../fuzzy.h:1755: (d - value) /
	mov	a,_bp
	add	a,#0xee
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
	C$fuzzy.h$1756$1_0$77 ==.
;	../../fuzzy.h:1756: (d - c);
	mov	a,_bp
	add	a,#0xf2
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
	add	a,#0xf2
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fssub
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
	lcall	___fsdiv
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
00110$:
	C$fuzzy.h$1760$1_0$77 ==.
;	../../fuzzy.h:1760: result,
	mov	a,_bp
	add	a,#0xed
	mov	r0,a
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
	C$fuzzy.h$1763$1_0$77 ==.
;	../../fuzzy.h:1763: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1763$1_0$77 ==.
	XG$fuzzy_trapezoid$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_function_array'
;------------------------------------------------------------
;value         Allocated to stack - _bp -6 +4 
;hedge         Allocated to stack - _bp -7 +1 
;parameter_count Allocated to stack - _bp -9 +2 
;parameters    Allocated to stack - _bp -12 +3 
;shape         Allocated to registers r7 
;sloc0         Allocated to stack - _bp +2 +1 
;sloc1         Allocated to stack - _bp +1 +4 
;sloc2         Allocated to stack - _bp +5 +4 
;sloc3         Allocated to stack - _bp +9 +4 
;------------------------------------------------------------
	G$fuzzy_function_array$0$0 ==.
	C$fuzzy.h$2220$1_0$83 ==.
;	../../fuzzy.h:2220: float fuzzy_function_array(
;	-----------------------------------------
;	 function fuzzy_function_array
;	-----------------------------------------
_fuzzy_function_array:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x0c
	mov	sp,a
	mov	r7, dpl
	C$fuzzy.h$2228$1_0$83 ==.
;	../../fuzzy.h:2228: if (parameters == NULL) {
	mov	a,_bp
	add	a,#0xf4
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00102$
	C$fuzzy.h$2229$2_0$84 ==.
;	../../fuzzy.h:2229: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00123$
00102$:
	C$fuzzy.h$2232$1_0$83 ==.
;	../../fuzzy.h:2232: switch (shape) {
	mov	a,r7
	add	a,#0xff - 0x0b
	jnc	00156$
	ljmp	00121$
00156$:
	mov	a,r7
	add	a,#(00157$-3-.)
	movc	a,@a+pc
	mov	dpl,a
	mov	a,r7
	add	a,#(00158$-3-.)
	movc	a,@a+pc
	mov	dph,a
	clr	a
	jmp	@a+dptr
00157$:
	.db	00103$
	.db	00106$
	.db	00109$
	.db	00120$
	.db	00120$
	.db	00120$
	.db	00120$
	.db	00120$
	.db	00120$
	.db	00120$
	.db	00120$
	.db	00120$
00158$:
	.db	00103$>>8
	.db	00106$>>8
	.db	00109$>>8
	.db	00120$>>8
	.db	00120$>>8
	.db	00120$>>8
	.db	00120$>>8
	.db	00120$>>8
	.db	00120$>>8
	.db	00120$>>8
	.db	00120$>>8
	.db	00120$>>8
	C$fuzzy.h$2233$2_0$85 ==.
;	../../fuzzy.h:2233: case FUZZY_SHAPE_RAMP:
00103$:
	C$fuzzy.h$2234$2_0$85 ==.
;	../../fuzzy.h:2234: if (parameter_count != 3u) {
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	cjne	@r0,#0x03,00159$
	inc	r0
	cjne	@r0,#0x00,00159$
	sjmp	00105$
00159$:
	C$fuzzy.h$2235$3_0$86 ==.
;	../../fuzzy.h:2235: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00123$
00105$:
	C$fuzzy.h$2242$2_0$85 ==.
;	../../fuzzy.h:2242: parameters[2] != 0.0f,
	mov	a,_bp
	add	a,#0xf4
	mov	r0,a
	mov	a,#0x08
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
	mov	b,r5
	mov	a,r6
	orl	b,a
	mov	a,r7
	orl	b,a
	mov	a,r4
	anl	a,#0x7F
	orl	a,b
	cjne	a,#0x01,00160$
00160$:
	cpl	c
	mov	b0,c
	clr	a
	rlc	a
	mov	r3,a
	C$fuzzy.h$2240$2_0$85 ==.
;	../../fuzzy.h:2240: parameters[1],
	mov	a,_bp
	add	a,#0xf4
	mov	r0,a
	mov	a,#0x04
	add	a, @r0
	mov	r4,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r5,a
	inc	r0
	mov	ar6,@r0
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
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
	C$fuzzy.h$2239$2_0$85 ==.
;	../../fuzzy.h:2239: parameters[0],
	mov	a,_bp
	add	a,#0xf4
	mov	r0,a
	mov	ar2,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar7,@r0
	mov	dpl,r2
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	mov	a,_bp
	add	a,#0xf9
	mov	r0,a
	mov	a,@r0
	push	acc
	push	ar3
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
	mov	dpl, r2
	mov	dph, r6
	mov	b, r7
	mov	a, r5
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
	ljmp	00123$
	C$fuzzy.h$2246$2_0$85 ==.
;	../../fuzzy.h:2246: case FUZZY_SHAPE_TRIANGLE:
00106$:
	C$fuzzy.h$2247$2_0$85 ==.
;	../../fuzzy.h:2247: if (parameter_count != 3u) {
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	cjne	@r0,#0x03,00161$
	inc	r0
	cjne	@r0,#0x00,00161$
	sjmp	00108$
00161$:
	C$fuzzy.h$2248$3_0$87 ==.
;	../../fuzzy.h:2248: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00123$
00108$:
	C$fuzzy.h$2254$2_0$85 ==.
;	../../fuzzy.h:2254: parameters[2],
	mov	a,_bp
	add	a,#0xf4
	mov	r0,a
	mov	a,#0x08
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
	C$fuzzy.h$2253$2_0$85 ==.
;	../../fuzzy.h:2253: parameters[1],
	mov	a,_bp
	add	a,#0xf4
	mov	r0,a
	mov	a,#0x04
	add	a, @r0
	mov	r2,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r3,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r2
	mov	dph,r3
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
	C$fuzzy.h$2252$2_0$85 ==.
;	../../fuzzy.h:2252: parameters[0],
	mov	a,_bp
	add	a,#0xf4
	mov	r0,a
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar7,@r0
	mov	dpl,r4
	mov	dph,r5
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	a,_bp
	add	a,#0xf9
	mov	r0,a
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
	mov	dpl, r4
	mov	dph, r5
	mov	b, r7
	mov	a, r6
	lcall	_fuzzy_triangle
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
	ljmp	00123$
	C$fuzzy.h$2259$2_0$85 ==.
;	../../fuzzy.h:2259: case FUZZY_SHAPE_TRAPEZOID:
00109$:
	C$fuzzy.h$2260$2_0$85 ==.
;	../../fuzzy.h:2260: if (parameter_count != 4u) {
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	cjne	@r0,#0x04,00162$
	inc	r0
	cjne	@r0,#0x00,00162$
	sjmp	00111$
00162$:
	C$fuzzy.h$2261$3_0$88 ==.
;	../../fuzzy.h:2261: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00123$
00111$:
	C$fuzzy.h$2268$2_0$85 ==.
;	../../fuzzy.h:2268: parameters[3],
	mov	a,_bp
	add	a,#0xf4
	mov	r0,a
	mov	a,#0x0c
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
	C$fuzzy.h$2267$2_0$85 ==.
;	../../fuzzy.h:2267: parameters[2],
	mov	a,_bp
	add	a,#0xf4
	mov	r0,a
	mov	a,#0x08
	add	a, @r0
	mov	r2,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r3,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
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
	C$fuzzy.h$2266$2_0$85 ==.
;	../../fuzzy.h:2266: parameters[1],
	mov	a,_bp
	add	a,#0xf4
	mov	r0,a
	mov	a,#0x04
	add	a, @r0
	mov	r4,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r5,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r4
	mov	dph,r5
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
	C$fuzzy.h$2265$2_0$85 ==.
;	../../fuzzy.h:2265: parameters[0],
	mov	a,_bp
	add	a,#0xf4
	mov	r0,a
	mov	ar2,@r0
	inc	r0
	mov	ar3,@r0
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
	mov	a,_bp
	add	a,#0xf9
	mov	r0,a
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
	mov	dph, r3
	mov	b, r7
	mov	a, r6
	lcall	_fuzzy_trapezoid
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xef
	mov	sp,a
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	C$fuzzy.h$2402$2_0$85 ==.
;	../../fuzzy.h:2402: case FUZZY_SHAPE_PSIGMOID:
	sjmp	00123$
00120$:
	C$fuzzy.h$2403$2_0$85 ==.
;	../../fuzzy.h:2403: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$2407$2_0$85 ==.
;	../../fuzzy.h:2407: default:
	sjmp	00123$
00121$:
	C$fuzzy.h$2408$2_0$85 ==.
;	../../fuzzy.h:2408: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$2409$1_0$83 ==.
;	../../fuzzy.h:2409: }
00123$:
	C$fuzzy.h$2410$1_0$83 ==.
;	../../fuzzy.h:2410: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$2410$1_0$83 ==.
	XG$fuzzy_function_array$0$0 ==.
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
	C$fuzzy.h$2412$1_0$90 ==.
;	../../fuzzy.h:2412: bool fuzzy_rules_add(
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
	C$fuzzy.h$2422$1_0$90 ==.
;	../../fuzzy.h:2422: rules == NULL ||
	mov	a,r2
	orl	a,r3
	jz	00101$
	C$fuzzy.h$2423$1_0$90 ==.
;	../../fuzzy.h:2423: output_function == NULL
	mov	a,_bp
	add	a,#0xf5
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00102$
00101$:
	C$fuzzy.h$2425$2_0$91 ==.
;	../../fuzzy.h:2425: return false;
	mov	dpl, #0x00
	ljmp	00106$
00102$:
	C$fuzzy.h$2428$1_0$90 ==.
;	../../fuzzy.h:2428: if (rules->count >= FUZZY_MAX_RULES) {
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	mov	a,#0x90
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
	subb	a,#0x10
	mov	a,r6
	subb	a,#0x00
	jc	00105$
	C$fuzzy.h$2429$2_0$92 ==.
;	../../fuzzy.h:2429: return false;
	mov	dpl, #0x00
	ljmp	00106$
00105$:
	C$fuzzy.h$2435$1_0$90 ==.
;	../../fuzzy.h:2435: rules->rules[index].name =
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
	C$fuzzy.h$2438$1_0$90 ==.
;	../../fuzzy.h:2438: rules->rules[index].value =
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
	C$fuzzy.h$2439$1_0$90 ==.
;	../../fuzzy.h:2439: fuzzy_clamp(value);
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
	C$fuzzy.h$2441$1_0$90 ==.
;	../../fuzzy.h:2441: rules->rules[index].output_function =
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
	C$fuzzy.h$2444$1_0$90 ==.
;	../../fuzzy.h:2444: rules->count++;
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
	C$fuzzy.h$2446$1_0$90 ==.
;	../../fuzzy.h:2446: return true;
	mov	dpl, #0x01
00106$:
	C$fuzzy.h$2447$1_0$90 ==.
;	../../fuzzy.h:2447: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$2447$1_0$90 ==.
	XG$fuzzy_rules_add$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_implication'
;------------------------------------------------------------
;activation    Allocated to stack - _bp -6 +4 
;membership    Allocated to stack - _bp -10 +4 
;method        Allocated to registers r7 
;sloc0         Allocated to stack - _bp +1 +4 
;sloc1         Allocated to stack - _bp +5 +4 
;------------------------------------------------------------
	Fcontroller_8051$fuzzy_implication$0$0 ==.
	C$fuzzy.h$2480$1_0$94 ==.
;	../../fuzzy.h:2480: static float fuzzy_implication(
;	-----------------------------------------
;	 function fuzzy_implication
;	-----------------------------------------
_fuzzy_implication:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x08
	mov	sp,a
	mov	r7, dpl
	C$fuzzy.h$2486$1_0$94 ==.
;	../../fuzzy.h:2486: activation = fuzzy_clamp(activation);
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
	push	ar7
	lcall	_fuzzy_clamp
	mov	r3, dpl
	mov	r4, dph
	mov	r5, b
	mov	r6, a
	C$fuzzy.h$2487$1_0$94 ==.
;	../../fuzzy.h:2487: membership = fuzzy_clamp(membership);
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
	push	ar6
	push	ar5
	push	ar4
	push	ar3
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
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	C$fuzzy.h$2489$1_0$94 ==.
;	../../fuzzy.h:2489: switch (method) {
	cjne	r7,#0x00,00127$
	sjmp	00101$
00127$:
	cjne	r7,#0x01,00128$
	sjmp	00102$
00128$:
	ljmp	00103$
	C$fuzzy.h$2490$2_0$95 ==.
;	../../fuzzy.h:2490: case FUZZY_IMPLICATION_MIN:
00101$:
	C$fuzzy.h$2492$1_0$94 ==.
;	../../fuzzy.h:2492: ? activation
	push	ar6
	push	ar5
	push	ar4
	push	ar3
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
	mov	dpl, r3
	mov	dph, r4
	mov	b, r5
	mov	a, r6
	lcall	___fslt
	mov	r7, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	mov	a,r7
	jz	00107$
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	@r0,ar3
	inc	r0
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar5
	inc	r0
	mov	@r0,ar6
	sjmp	00108$
00107$:
	C$fuzzy.h$2493$2_0$95 ==.
;	../../fuzzy.h:2493: : membership;
	mov	r0,_bp
	inc	r0
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
00108$:
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
	C$fuzzy.h$2495$2_0$95 ==.
;	../../fuzzy.h:2495: case FUZZY_IMPLICATION_PRODUCT:
	sjmp	00105$
00102$:
	C$fuzzy.h$2496$1_0$94 ==.
;	../../fuzzy.h:2496: return activation * membership;
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
	mov	dpl, r3
	mov	dph, r4
	mov	b, r5
	mov	a, r6
	lcall	___fsmul
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
	C$fuzzy.h$2498$2_0$95 ==.
;	../../fuzzy.h:2498: default:
	sjmp	00105$
00103$:
	C$fuzzy.h$2499$2_0$95 ==.
;	../../fuzzy.h:2499: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$2500$1_0$94 ==.
;	../../fuzzy.h:2500: }
00105$:
	C$fuzzy.h$2501$1_0$94 ==.
;	../../fuzzy.h:2501: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$2501$1_0$94 ==.
	XFcontroller_8051$fuzzy_implication$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_aggregation'
;------------------------------------------------------------
;aggregated    Allocated to stack - _bp -6 +4 
;implied       Allocated to stack - _bp -10 +4 
;method        Allocated to registers r7 
;sloc0         Allocated to stack - _bp +1 +4 
;sloc1         Allocated to stack - _bp +5 +4 
;sloc2         Allocated to stack - _bp +10 +4 
;------------------------------------------------------------
	Fcontroller_8051$fuzzy_aggregation$0$0 ==.
	C$fuzzy.h$2503$1_0$97 ==.
;	../../fuzzy.h:2503: static float fuzzy_aggregation(
;	-----------------------------------------
;	 function fuzzy_aggregation
;	-----------------------------------------
_fuzzy_aggregation:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x08
	mov	sp,a
	mov	r7, dpl
	C$fuzzy.h$2509$1_0$97 ==.
;	../../fuzzy.h:2509: aggregated = fuzzy_clamp(aggregated);
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
	push	ar7
	lcall	_fuzzy_clamp
	mov	r6, dpl
	mov	r5, dph
	mov	r4, b
	mov	r3, a
	C$fuzzy.h$2510$1_0$97 ==.
;	../../fuzzy.h:2510: implied = fuzzy_clamp(implied);
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
	push	ar6
	push	ar5
	push	ar4
	push	ar3
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
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	C$fuzzy.h$2512$1_0$97 ==.
;	../../fuzzy.h:2512: switch (method) {
	cjne	r7,#0x00,00134$
	sjmp	00101$
00134$:
	cjne	r7,#0x01,00135$
	sjmp	00102$
00135$:
	cjne	r7,#0x02,00136$
	ljmp	00103$
00136$:
	ljmp	00104$
	C$fuzzy.h$2513$2_0$98 ==.
;	../../fuzzy.h:2513: case FUZZY_AGGREGATION_MAX:
00101$:
	C$fuzzy.h$2515$1_0$97 ==.
;	../../fuzzy.h:2515: ? aggregated
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	mov	r0,_bp
	inc	r0
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
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	mov	a,r7
	jz	00108$
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	@r0,ar6
	inc	r0
	mov	@r0,ar5
	inc	r0
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar3
	sjmp	00109$
00108$:
	C$fuzzy.h$2516$2_0$98 ==.
;	../../fuzzy.h:2516: : implied;
	mov	r0,_bp
	inc	r0
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
00109$:
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
	ljmp	00106$
	C$fuzzy.h$2518$2_0$98 ==.
;	../../fuzzy.h:2518: case FUZZY_AGGREGATION_ALGEBRAIC:
00102$:
	C$fuzzy.h$2520$1_0$97 ==.
;	../../fuzzy.h:2520: implied -
	push	ar6
	push	ar5
	push	ar4
	push	ar3
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
	C$fuzzy.h$2521$1_0$97 ==.
;	../../fuzzy.h:2521: aggregated * implied;
	mov	dpl, r6
	mov	dph, r5
	mov	b, r4
	mov	a, r3
	lcall	___fsadd
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
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
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
	mov	dpl, r6
	mov	dph, r5
	mov	b, r4
	mov	a, r3
	lcall	___fsmul
	mov	r3, dpl
	mov	r4, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	push	ar3
	push	ar4
	push	ar6
	push	ar7
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
	C$fuzzy.h$2523$2_0$98 ==.
;	../../fuzzy.h:2523: case FUZZY_AGGREGATION_BOUNDED:
	sjmp	00106$
00103$:
	C$fuzzy.h$2527$1_0$97 ==.
;	../../fuzzy.h:2527: );
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
	mov	dpl, r6
	mov	dph, r5
	mov	b, r4
	mov	a, r3
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
	lcall	_fuzzy_clamp
	C$fuzzy.h$2529$2_0$98 ==.
;	../../fuzzy.h:2529: default:
	sjmp	00106$
00104$:
	C$fuzzy.h$2530$2_0$98 ==.
;	../../fuzzy.h:2530: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$2531$1_0$97 ==.
;	../../fuzzy.h:2531: }
00106$:
	C$fuzzy.h$2532$1_0$97 ==.
;	../../fuzzy.h:2532: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$2532$1_0$97 ==.
	XFcontroller_8051$fuzzy_aggregation$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_aggregated_height'
;------------------------------------------------------------
;value         Allocated to stack - _bp -6 +4 
;implication_method Allocated to stack - _bp -7 +1 
;aggregation_method Allocated to stack - _bp -8 +1 
;rules         Allocated to stack - _bp +1 +3 
;aggregated_height Allocated to stack - _bp +12 +4 
;output_membership Allocated to stack - _bp +16 +4 
;implied_height Allocated to registers r4 r5 r6 r7 
;index         Allocated to stack - _bp +20 +2 
;sloc0         Allocated to stack - _bp +4 +3 
;sloc1         Allocated to stack - _bp +7 +2 
;sloc2         Allocated to stack - _bp +9 +3 
;------------------------------------------------------------
	Fcontroller_8051$fuzzy_rules_aggregated_height$0$0 ==.
	C$fuzzy.h$2538$1_0$100 ==.
;	../../fuzzy.h:2538: static float fuzzy_rules_aggregated_height(
;	-----------------------------------------
;	 function fuzzy_rules_aggregated_height
;	-----------------------------------------
_fuzzy_rules_aggregated_height:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	mov	a,sp
	add	a,#0x12
	mov	sp,a
	C$fuzzy.h$2551$1_0$100 ==.
;	../../fuzzy.h:2551: LEVEL_LO;
	mov	a,_bp
	add	a,#0x0c
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$2554$3_0$102 ==.
;	../../fuzzy.h:2554: index = 0u;
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x09
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
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x04
	mov	r1,a
	mov	a,#0x90
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
	add	a,#0x14
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
00103$:
	C$fuzzy.h$2555$1_0$100 ==.
;	../../fuzzy.h:2555: index < rules->count;
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	mov	a,_bp
	add	a,#0x14
	mov	r0,a
	clr	c
	mov	a,@r0
	subb	a,r4
	inc	r0
	mov	a,@r0
	subb	a,r5
	jc	00120$
	ljmp	00101$
00120$:
	C$fuzzy.h$2560$3_0$102 ==.
;	../../fuzzy.h:2560: rules->rules[index]
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	mov	a,_bp
	add	a,#0x07
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
	mov	a,#0x07
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
	C$fuzzy.h$2561$3_0$102 ==.
;	../../fuzzy.h:2561: .output_function(value)
	lcall	00121$
	sjmp	00122$
00121$:
	push	ar5
	push	ar6
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
	ret
00122$:
	lcall	_fuzzy_clamp
	xch	a,r0
	mov	a,_bp
	add	a,#0x10
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	C$fuzzy.h$2567$3_0$102 ==.
;	../../fuzzy.h:2567: rules->rules[index].value,
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x07
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
	mov	ar7,@r0
	mov	a,#0x03
	add	a, r2
	mov	r2,a
	clr	a
	addc	a, r3
	mov	r3,a
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
	C$fuzzy.h$2566$3_0$102 ==.
;	../../fuzzy.h:2566: implication_method,
	mov	a,_bp
	add	a,#0x10
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
	push	ar2
	push	ar3
	push	ar7
	push	ar6
	mov	a,_bp
	add	a,#0xf9
	mov	r0,a
	mov	dpl, @r0
	lcall	_fuzzy_implication
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
	C$fuzzy.h$2573$3_0$102 ==.
;	../../fuzzy.h:2573: aggregation_method,
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	a,_bp
	add	a,#0x0c
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
	add	a,#0xf8
	mov	r0,a
	mov	dpl, @r0
	lcall	_fuzzy_aggregation
	xch	a,r0
	mov	a,_bp
	add	a,#0x0c
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
	C$fuzzy.h$2556$1_0$100 ==.
;	../../fuzzy.h:2556: index++
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	a,#0x09
	add	a, @r0
	mov	@r0,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x14
	mov	r0,a
	inc	@r0
	cjne	@r0,#0x00,00123$
	inc	r0
	inc	@r0
00123$:
	ljmp	00103$
00101$:
	C$fuzzy.h$2580$1_0$100 ==.
;	../../fuzzy.h:2580: aggregated_height
	mov	a,_bp
	add	a,#0x0c
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	_fuzzy_clamp
	C$fuzzy.h$2582$1_0$100 ==.
;	../../fuzzy.h:2582: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$2582$1_0$100 ==.
	XFcontroller_8051$fuzzy_rules_aggregated_height$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_maximum_result'
;------------------------------------------------------------
;rules         Allocated to stack - _bp -5 +3 
;lower         Allocated to stack - _bp -9 +4 
;upper         Allocated to stack - _bp -13 +4 
;step          Allocated to stack - _bp -17 +4 
;implication_method Allocated to stack - _bp -18 +1 
;aggregation_method Allocated to stack - _bp -19 +1 
;result        Allocated to registers r5 r6 r7 
;value         Allocated to stack - _bp +16 +4 
;height        Allocated to stack - _bp +20 +4 
;sloc0         Allocated to stack - _bp +1 +3 
;sloc1         Allocated to stack - _bp +4 +3 
;sloc2         Allocated to stack - _bp +7 +3 
;sloc3         Allocated to stack - _bp +10 +3 
;sloc4         Allocated to stack - _bp +13 +3 
;------------------------------------------------------------
	Fcontroller_8051$fuzzy_rules_maximum_result$0$0 ==.
	C$fuzzy.h$2602$1_0$104 ==.
;	../../fuzzy.h:2602: static void fuzzy_rules_maximum_result(
;	-----------------------------------------
;	 function fuzzy_rules_maximum_result
;	-----------------------------------------
_fuzzy_rules_maximum_result:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x17
	mov	sp,a
	mov	r5, dpl
	mov	r6, dph
	mov	r7, b
	C$fuzzy.h$2615$1_0$104 ==.
;	../../fuzzy.h:2615: result->height =
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	@r0,ar5
	inc	r0
	mov	@r0,ar6
	inc	r0
	mov	@r0,ar7
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	clr	a
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
	C$fuzzy.h$2618$1_0$104 ==.
;	../../fuzzy.h:2618: result->smallest_position =
	mov	r0,_bp
	inc	r0
	mov	a,#0x04
	add	a, r5
	mov	@r0,a
	clr	a
	addc	a, r6
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,ar7
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,_bp
	add	a,#0xf7
	mov	r1,a
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	C$fuzzy.h$2621$1_0$104 ==.
;	../../fuzzy.h:2621: result->largest_position =
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	a,#0x08
	add	a, r5
	mov	@r0,a
	clr	a
	addc	a, r6
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,ar7
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,_bp
	add	a,#0xf7
	mov	r1,a
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	C$fuzzy.h$2624$1_0$104 ==.
;	../../fuzzy.h:2624: result->position_sum =
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	a,#0x0c
	add	a, r5
	mov	@r0,a
	clr	a
	addc	a, r6
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,ar7
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	clr	a
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
	C$fuzzy.h$2627$1_0$104 ==.
;	../../fuzzy.h:2627: result->position_count =
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	a,#0x10
	add	a, r5
	mov	@r0,a
	clr	a
	addc	a, r6
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,ar7
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	clr	a
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
	C$fuzzy.h$2631$2_0$105 ==.
;	../../fuzzy.h:2631: value = lower;
	mov	a,_bp
	add	a,#0xf7
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
00109$:
	C$fuzzy.h$2632$2_0$104 ==.
;	../../fuzzy.h:2632: value <= upper;
	mov	a,_bp
	add	a,#0x10
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
	add	a,#0xf3
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
	jnc	00137$
	ljmp	00111$
00137$:
	C$fuzzy.h$2637$3_0$106 ==.
;	../../fuzzy.h:2637: rules,
	mov	a,_bp
	add	a,#0xed
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xee
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x10
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
	add	a,#0xfb
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	lcall	_fuzzy_rules_aggregated_height
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
	add	a,#0xfa
	mov	sp,a
	C$fuzzy.h$2644$3_0$106 ==.
;	../../fuzzy.h:2644: result->position_count == 0u ||
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	orl	a,r5
	jz	00103$
	C$fuzzy.h$2645$2_0$104 ==.
;	../../fuzzy.h:2645: height > result->height
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	mov	a,_bp
	add	a,#0x14
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
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	lcall	___fslt
	mov	r7, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,r7
	jnz	00139$
	ljmp	00104$
00139$:
00103$:
	C$fuzzy.h$2647$4_0$107 ==.
;	../../fuzzy.h:2647: result->height =
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,_bp
	add	a,#0x14
	mov	r1,a
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	C$fuzzy.h$2650$4_0$107 ==.
;	../../fuzzy.h:2650: result->smallest_position =
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,_bp
	add	a,#0x10
	mov	r1,a
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	C$fuzzy.h$2653$4_0$107 ==.
;	../../fuzzy.h:2653: result->largest_position =
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,_bp
	add	a,#0x10
	mov	r1,a
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	C$fuzzy.h$2656$4_0$107 ==.
;	../../fuzzy.h:2656: result->position_sum =
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,_bp
	add	a,#0x10
	mov	r1,a
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	C$fuzzy.h$2659$4_0$107 ==.
;	../../fuzzy.h:2659: result->position_count =
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,#0x01
	lcall	__gptrput
	inc	dptr
	clr	a
	lcall	__gptrput
	ljmp	00110$
00104$:
	C$fuzzy.h$2664$2_0$104 ==.
;	../../fuzzy.h:2664: result->height
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
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
	lcall	___fseq
	mov	r7, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,r7
	jnz	00140$
	ljmp	00110$
00140$:
	C$fuzzy.h$2666$4_0$108 ==.
;	../../fuzzy.h:2666: result->largest_position =
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,_bp
	add	a,#0x10
	mov	r1,a
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	inc	dptr
	inc	r1
	mov	a,@r1
	lcall	__gptrput
	C$fuzzy.h$2669$4_0$108 ==.
;	../../fuzzy.h:2669: result->position_sum +=
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	mov	a,_bp
	add	a,#0x10
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
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,r4
	lcall	__gptrput
	inc	dptr
	mov	a,r5
	lcall	__gptrput
	inc	dptr
	mov	a,r6
	lcall	__gptrput
	inc	dptr
	mov	a,r7
	lcall	__gptrput
	C$fuzzy.h$2672$4_0$108 ==.
;	../../fuzzy.h:2672: result->position_count++;
	mov	a,_bp
	add	a,#0x0d
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
	inc	r7
	cjne	r7,#0x00,00141$
	inc	r6
00141$:
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,r7
	lcall	__gptrput
	inc	dptr
	mov	a,r6
	lcall	__gptrput
00110$:
	C$fuzzy.h$2634$2_0$104 ==.
;	../../fuzzy.h:2634: ) {
	mov	a,_bp
	add	a,#0xef
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
	lcall	___fsadd
	xch	a,r0
	mov	a,_bp
	add	a,#0x10
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
	ljmp	00109$
00111$:
	C$fuzzy.h$2675$2_0$104 ==.
;	../../fuzzy.h:2675: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$2675$2_0$104 ==.
	XFcontroller_8051$fuzzy_rules_maximum_result$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_defuzzify_cog'
;------------------------------------------------------------
;lower         Allocated to stack - _bp -6 +4 
;upper         Allocated to stack - _bp -10 +4 
;step          Allocated to stack - _bp -14 +4 
;implication_method Allocated to stack - _bp -15 +1 
;aggregation_method Allocated to stack - _bp -16 +1 
;rules         Allocated to stack - _bp +1 +3 
;weighted_sum  Allocated to stack - _bp +4 +4 
;height_sum    Allocated to stack - _bp +8 +4 
;value         Allocated to stack - _bp +12 +4 
;height        Allocated to stack - _bp +16 +4 
;------------------------------------------------------------
	G$fuzzy_rules_defuzzify_cog$0$0 ==.
	C$fuzzy.h$2682$2_0$110 ==.
;	../../fuzzy.h:2682: float fuzzy_rules_defuzzify_cog(
;	-----------------------------------------
;	 function fuzzy_rules_defuzzify_cog
;	-----------------------------------------
_fuzzy_rules_defuzzify_cog:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	mov	a,sp
	add	a,#0x10
	mov	sp,a
	C$fuzzy.h$2697$1_0$110 ==.
;	../../fuzzy.h:2697: 0.0f;
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$2700$1_0$110 ==.
;	../../fuzzy.h:2700: 0.0f;
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$2703$2_0$111 ==.
;	../../fuzzy.h:2703: value = lower;
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	a,_bp
	add	a,#0x0c
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
00105$:
	C$fuzzy.h$2704$1_0$110 ==.
;	../../fuzzy.h:2704: value <= upper;
	mov	a,_bp
	add	a,#0x0c
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
	jnc	00127$
	ljmp	00101$
00127$:
	C$fuzzy.h$2709$3_0$112 ==.
;	../../fuzzy.h:2709: rules,
	mov	a,_bp
	add	a,#0xf0
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x0c
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
	lcall	_fuzzy_rules_aggregated_height
	xch	a,r0
	mov	a,_bp
	add	a,#0x10
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfa
	mov	sp,a
	C$fuzzy.h$2717$1_0$110 ==.
;	../../fuzzy.h:2717: height;
	mov	a,_bp
	add	a,#0x10
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
	add	a,#0x0c
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fsmul
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
	C$fuzzy.h$2720$1_0$110 ==.
;	../../fuzzy.h:2720: height;
	mov	a,_bp
	add	a,#0x04
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
	add	a,#0x04
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
	add	a,#0x10
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
	C$fuzzy.h$2706$1_0$110 ==.
;	../../fuzzy.h:2706: ) {
	mov	a,_bp
	add	a,#0x08
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
	add	a,#0x08
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
	add	a,#0x0c
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
	add	a,#0x0c
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
	ljmp	00105$
00101$:
	C$fuzzy.h$2723$1_0$110 ==.
;	../../fuzzy.h:2723: if (height_sum <= LEVEL_LO) {
	mov	a,_bp
	add	a,#0x08
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
	jc	00103$
	C$fuzzy.h$2724$2_0$113 ==.
;	../../fuzzy.h:2724: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00107$
00103$:
	C$fuzzy.h$2728$1_0$110 ==.
;	../../fuzzy.h:2728: height_sum;
	mov	a,_bp
	add	a,#0x08
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
	add	a,#0x04
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
00107$:
	C$fuzzy.h$2729$1_0$110 ==.
;	../../fuzzy.h:2729: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$2729$1_0$110 ==.
	XG$fuzzy_rules_defuzzify_cog$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_defuzzify_boa'
;------------------------------------------------------------
;lower         Allocated to stack - _bp -6 +4 
;upper         Allocated to stack - _bp -10 +4 
;step          Allocated to stack - _bp -14 +4 
;implication_method Allocated to stack - _bp -15 +1 
;aggregation_method Allocated to stack - _bp -16 +1 
;rules         Allocated to stack - _bp +1 +3 
;total_area    Allocated to stack - _bp +8 +4 
;half_area     Allocated to stack - _bp +12 +4 
;accumulated_area Allocated to stack - _bp +16 +4 
;value         Allocated to stack - _bp +20 +4 
;sloc0         Allocated to stack - _bp +4 +4 
;------------------------------------------------------------
	G$fuzzy_rules_defuzzify_boa$0$0 ==.
	C$fuzzy.h$2739$1_0$115 ==.
;	../../fuzzy.h:2739: float fuzzy_rules_defuzzify_boa(
;	-----------------------------------------
;	 function fuzzy_rules_defuzzify_boa
;	-----------------------------------------
_fuzzy_rules_defuzzify_boa:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	mov	a,sp
	add	a,#0x14
	mov	sp,a
	C$fuzzy.h$2754$1_0$115 ==.
;	../../fuzzy.h:2754: 0.0f;
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$2757$2_0$116 ==.
;	../../fuzzy.h:2757: value = lower;
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	a,_bp
	add	a,#0x04
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
00108$:
	C$fuzzy.h$2758$1_0$115 ==.
;	../../fuzzy.h:2758: value <= upper;
	mov	a,_bp
	add	a,#0x04
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
	jnc	00157$
	ljmp	00101$
00157$:
	C$fuzzy.h$2763$3_0$117 ==.
;	../../fuzzy.h:2763: rules,
	mov	a,_bp
	add	a,#0xf0
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x04
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
	lcall	_fuzzy_rules_aggregated_height
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfa
	mov	sp,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	C$fuzzy.h$2760$1_0$115 ==.
;	../../fuzzy.h:2760: ) {
	mov	a,_bp
	add	a,#0x08
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
	add	a,#0x08
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
	add	a,#0x04
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
	add	a,#0x04
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
	ljmp	00108$
00101$:
	C$fuzzy.h$2770$1_0$115 ==.
;	../../fuzzy.h:2770: if (total_area <= LEVEL_LO) {
	mov	a,_bp
	add	a,#0x08
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
	jc	00103$
	C$fuzzy.h$2771$2_0$118 ==.
;	../../fuzzy.h:2771: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00113$
00103$:
	C$fuzzy.h$2776$1_0$115 ==.
;	../../fuzzy.h:2776: 2.0f;
	clr	a
	push	acc
	push	acc
	push	acc
	mov	a,#0x40
	push	acc
	C$fuzzy.h$2779$1_0$115 ==.
;	../../fuzzy.h:2779: 0.0f;
	mov	a,_bp
	add	a,#0x08
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
	add	a,#0x0c
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
	add	a,#0x10
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$2782$2_0$119 ==.
;	../../fuzzy.h:2782: value = lower;
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	a,_bp
	add	a,#0x14
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
00111$:
	C$fuzzy.h$2783$1_0$115 ==.
;	../../fuzzy.h:2783: value <= upper;
	mov	a,_bp
	add	a,#0x14
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
	jnc	00159$
	ljmp	00106$
00159$:
	C$fuzzy.h$2788$3_0$120 ==.
;	../../fuzzy.h:2788: rules,
	mov	a,_bp
	add	a,#0xf0
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x14
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
	lcall	_fuzzy_rules_aggregated_height
	mov	r2, dpl
	mov	r3, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfa
	mov	sp,a
	push	ar2
	push	ar3
	push	ar6
	push	ar7
	C$fuzzy.h$2797$1_0$115 ==.
;	../../fuzzy.h:2797: ) {
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
	lcall	___fsadd
	xch	a,r0
	mov	a,_bp
	add	a,#0x10
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
	add	a,#0x0c
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
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00112$
	C$fuzzy.h$2798$4_0$121 ==.
;	../../fuzzy.h:2798: return value;
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
	sjmp	00113$
00112$:
	C$fuzzy.h$2785$1_0$115 ==.
;	../../fuzzy.h:2785: ) {
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
	ljmp	00111$
00106$:
	C$fuzzy.h$2802$1_0$115 ==.
;	../../fuzzy.h:2802: return upper;
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
00113$:
	C$fuzzy.h$2803$1_0$115 ==.
;	../../fuzzy.h:2803: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$2803$1_0$115 ==.
	XG$fuzzy_rules_defuzzify_boa$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_defuzzify_cos'
;------------------------------------------------------------
;lower         Allocated to stack - _bp -6 +4 
;upper         Allocated to stack - _bp -10 +4 
;step          Allocated to stack - _bp -14 +4 
;implication_method Allocated to stack - _bp -15 +1 
;rules         Allocated to stack - _bp +1 +3 
;weighted_sum  Allocated to stack - _bp +9 +4 
;height_sum    Allocated to stack - _bp +13 +4 
;value         Allocated to stack - _bp +17 +4 
;output_membership Allocated to stack - _bp +21 +4 
;implied_height Allocated to stack - _bp +25 +4 
;index         Allocated to stack - _bp +29 +2 
;sloc0         Allocated to stack - _bp +4 +3 
;sloc1         Allocated to stack - _bp +7 +2 
;------------------------------------------------------------
	G$fuzzy_rules_defuzzify_cos$0$0 ==.
	C$fuzzy.h$2815$1_0$123 ==.
;	../../fuzzy.h:2815: float fuzzy_rules_defuzzify_cos(
;	-----------------------------------------
;	 function fuzzy_rules_defuzzify_cos
;	-----------------------------------------
_fuzzy_rules_defuzzify_cos:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	mov	a,sp
	add	a,#0x1b
	mov	sp,a
	C$fuzzy.h$2831$1_0$123 ==.
;	../../fuzzy.h:2831: 0.0f;
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$2834$1_0$123 ==.
;	../../fuzzy.h:2834: 0.0f;
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$2837$2_0$124 ==.
;	../../fuzzy.h:2837: value = lower;
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	a,_bp
	add	a,#0x11
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
	add	a,#0x04
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
	mov	r0,_bp
	inc	r0
	mov	a,#0x90
	add	a, @r0
	mov	r4,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r5,a
	inc	r0
	mov	ar6,@r0
00109$:
	C$fuzzy.h$2838$1_0$123 ==.
;	../../fuzzy.h:2838: value <= upper;
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
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jnc	00144$
	ljmp	00102$
00144$:
	C$fuzzy.h$2842$1_0$123 ==.
;	../../fuzzy.h:2842: index = 0u;
	mov	a,_bp
	add	a,#0x1d
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
00106$:
	C$fuzzy.h$2843$4_0$126 ==.
;	../../fuzzy.h:2843: index < rules->count;
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	mov	a,_bp
	add	a,#0x1d
	mov	r0,a
	clr	c
	mov	a,@r0
	subb	a,r2
	inc	r0
	mov	a,@r0
	subb	a,r7
	jc	00145$
	ljmp	00110$
00145$:
	C$fuzzy.h$2848$1_0$123 ==.
;	../../fuzzy.h:2848: rules->rules[index]
	push	ar4
	push	ar5
	push	ar6
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	a,_bp
	add	a,#0x07
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
	mov	ar7,@r0
	mov	a,#0x07
	add	a, r2
	mov	r2,a
	clr	a
	addc	a, r3
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	C$fuzzy.h$2849$5_0$127 ==.
;	../../fuzzy.h:2849: .output_function(value)
	push	ar5
	push	ar4
	lcall	00146$
	sjmp	00147$
00146$:
	push	ar2
	push	ar3
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
	ret
00147$:
	mov	r2, dpl
	mov	r3, dph
	mov	r6, b
	mov	r7, a
	pop	ar4
	pop	ar5
	mov	dpl, r2
	mov	dph, r3
	mov	b, r6
	mov	a, r7
	push	ar6
	push	ar5
	push	ar4
	lcall	_fuzzy_clamp
	xch	a,r0
	mov	a,_bp
	add	a,#0x15
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
	C$fuzzy.h$2855$5_0$127 ==.
;	../../fuzzy.h:2855: rules->rules[index].value,
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x07
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
	mov	ar7,@r0
	mov	a,#0x03
	add	a, r2
	mov	r2,a
	clr	a
	addc	a, r3
	mov	r3,a
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
	C$fuzzy.h$2854$5_0$127 ==.
;	../../fuzzy.h:2854: implication_method,
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
	push	ar2
	push	ar3
	push	ar7
	push	ar6
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	mov	dpl, @r0
	lcall	_fuzzy_implication
	xch	a,r0
	mov	a,_bp
	add	a,#0x19
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	C$fuzzy.h$2861$1_0$123 ==.
;	../../fuzzy.h:2861: implied_height;
	push	ar5
	push	ar4
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
	push	ar6
	push	ar5
	push	ar4
	push	ar2
	push	ar3
	push	ar6
	push	ar7
	C$fuzzy.h$2864$1_0$123 ==.
;	../../fuzzy.h:2864: implied_height;
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
	lcall	___fsadd
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
	C$fuzzy.h$2844$1_0$123 ==.
;	../../fuzzy.h:2844: index++
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
	lcall	___fsadd
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
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	a,#0x09
	add	a, @r0
	mov	@r0,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	@r0,a
	mov	a,_bp
	add	a,#0x1d
	mov	r0,a
	inc	@r0
	cjne	@r0,#0x00,00148$
	inc	r0
	inc	@r0
00148$:
	pop	ar6
	pop	ar5
	pop	ar4
	ljmp	00106$
00110$:
	C$fuzzy.h$2840$1_0$123 ==.
;	../../fuzzy.h:2840: ) {
	push	ar6
	push	ar5
	push	ar4
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
	add	a,#0x11
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
	add	a,#0x11
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
	ljmp	00109$
00102$:
	C$fuzzy.h$2868$1_0$123 ==.
;	../../fuzzy.h:2868: if (height_sum <= LEVEL_LO) {
	mov	a,_bp
	add	a,#0x0d
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
	jc	00104$
	C$fuzzy.h$2869$2_0$128 ==.
;	../../fuzzy.h:2869: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00111$
00104$:
	C$fuzzy.h$2873$1_0$123 ==.
;	../../fuzzy.h:2873: height_sum;
	mov	a,_bp
	add	a,#0x0d
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
	C$fuzzy.h$2874$1_0$123 ==.
;	../../fuzzy.h:2874: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$2874$1_0$123 ==.
	XG$fuzzy_rules_defuzzify_cos$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_defuzzify_mom'
;------------------------------------------------------------
;lower         Allocated to stack - _bp -6 +4 
;upper         Allocated to stack - _bp -10 +4 
;step          Allocated to stack - _bp -14 +4 
;implication_method Allocated to stack - _bp -15 +1 
;aggregation_method Allocated to stack - _bp -16 +1 
;rules         Allocated to stack - _bp +1 +3 
;result        Allocated to stack - _bp +8 +18 
;sloc0         Allocated to stack - _bp +4 +4 
;------------------------------------------------------------
	G$fuzzy_rules_defuzzify_mom$0$0 ==.
	C$fuzzy.h$2880$1_0$130 ==.
;	../../fuzzy.h:2880: float fuzzy_rules_defuzzify_mom(
;	-----------------------------------------
;	 function fuzzy_rules_defuzzify_mom
;	-----------------------------------------
_fuzzy_rules_defuzzify_mom:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	mov	a,sp
	add	a,#0x16
	mov	sp,a
	C$fuzzy.h$2892$1_0$130 ==.
;	../../fuzzy.h:2892: &result,
	mov	a,_bp
	add	a,#0x08
	mov	r4,a
	mov	r2,a
	mov	r3,#0x00
	mov	r7,#0x40
	push	ar4
	mov	a,_bp
	add	a,#0xf0
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	mov	a,@r0
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
	mov	dpl, r2
	mov	dph, r3
	mov	b, r7
	lcall	_fuzzy_rules_maximum_result
	mov	a,sp
	add	a,#0xef
	mov	sp,a
	pop	ar4
	C$fuzzy.h$2902$1_0$130 ==.
;	../../fuzzy.h:2902: result.position_count == 0u ||
	mov	a,#0x10
	add	a, r4
	mov	r1,a
	mov	ar6,@r1
	inc	r1
	mov	ar7,@r1
	mov	a,r6
	orl	a,r7
	jz	00101$
	C$fuzzy.h$2903$1_0$130 ==.
;	../../fuzzy.h:2903: result.height <= LEVEL_LO
	push	ar6
	push	ar7
	mov	ar1,r4
	mov	ar2,@r1
	inc	r1
	mov	ar3,@r1
	inc	r1
	mov	ar5,@r1
	inc	r1
	mov	ar7,@r1
	push	ar7
	push	ar6
	push	ar4
	push	ar2
	push	ar3
	push	ar5
	push	ar7
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar6
	pop	ar7
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	pop	ar7
	pop	ar6
	jb	b0,00102$
00101$:
	C$fuzzy.h$2905$2_0$131 ==.
;	../../fuzzy.h:2905: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00104$
00102$:
	C$fuzzy.h$2908$1_0$130 ==.
;	../../fuzzy.h:2908: return result.position_sum /
	mov	a,#0x0c
	add	a, r4
	mov	r1,a
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	a,@r1
	mov	@r0,a
	inc	r1
	mov	a,@r1
	inc	r0
	mov	@r0,a
	inc	r1
	mov	a,@r1
	inc	r0
	mov	@r0,a
	inc	r1
	mov	a,@r1
	inc	r0
	mov	@r0,a
	C$fuzzy.h$2909$1_0$130 ==.
;	../../fuzzy.h:2909: (float)result.position_count;
	mov	dpl, r6
	mov	dph, r7
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
	add	a,#0x04
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
00104$:
	C$fuzzy.h$2910$1_0$130 ==.
;	../../fuzzy.h:2910: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$2910$1_0$130 ==.
	XG$fuzzy_rules_defuzzify_mom$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_defuzzify_som'
;------------------------------------------------------------
;lower         Allocated to stack - _bp -6 +4 
;upper         Allocated to stack - _bp -10 +4 
;step          Allocated to stack - _bp -14 +4 
;implication_method Allocated to stack - _bp -15 +1 
;aggregation_method Allocated to stack - _bp -16 +1 
;rules         Allocated to stack - _bp +1 +3 
;result        Allocated to stack - _bp +4 +18 
;------------------------------------------------------------
	G$fuzzy_rules_defuzzify_som$0$0 ==.
	C$fuzzy.h$2916$1_0$133 ==.
;	../../fuzzy.h:2916: float fuzzy_rules_defuzzify_som(
;	-----------------------------------------
;	 function fuzzy_rules_defuzzify_som
;	-----------------------------------------
_fuzzy_rules_defuzzify_som:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	mov	a,sp
	add	a,#0x12
	mov	sp,a
	C$fuzzy.h$2928$1_0$133 ==.
;	../../fuzzy.h:2928: &result,
	mov	a,_bp
	add	a,#0x04
	mov	r4,a
	mov	r2,a
	mov	r3,#0x00
	mov	r7,#0x40
	push	ar4
	mov	a,_bp
	add	a,#0xf0
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	mov	a,@r0
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
	mov	dpl, r2
	mov	dph, r3
	mov	b, r7
	lcall	_fuzzy_rules_maximum_result
	mov	a,sp
	add	a,#0xef
	mov	sp,a
	pop	ar4
	C$fuzzy.h$2938$1_0$133 ==.
;	../../fuzzy.h:2938: result.position_count == 0u ||
	mov	a,#0x10
	add	a, r4
	mov	r1,a
	mov	ar6,@r1
	inc	r1
	mov	ar7,@r1
	mov	a,r6
	orl	a,r7
	jz	00101$
	C$fuzzy.h$2939$1_0$133 ==.
;	../../fuzzy.h:2939: result.height <= LEVEL_LO
	mov	ar1,r4
	mov	ar3,@r1
	inc	r1
	mov	ar5,@r1
	inc	r1
	mov	ar6,@r1
	inc	r1
	mov	ar7,@r1
	push	ar4
	push	ar3
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
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00102$
00101$:
	C$fuzzy.h$2941$2_0$134 ==.
;	../../fuzzy.h:2941: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00104$
00102$:
	C$fuzzy.h$2944$1_0$133 ==.
;	../../fuzzy.h:2944: return result.smallest_position;
	mov	a,#0x04
	add	a, r4
	mov	r1,a
	mov	ar4,@r1
	inc	r1
	mov	ar5,@r1
	inc	r1
	mov	ar6,@r1
	inc	r1
	mov	ar7,@r1
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
00104$:
	C$fuzzy.h$2945$1_0$133 ==.
;	../../fuzzy.h:2945: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$2945$1_0$133 ==.
	XG$fuzzy_rules_defuzzify_som$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_defuzzify_lom'
;------------------------------------------------------------
;lower         Allocated to stack - _bp -6 +4 
;upper         Allocated to stack - _bp -10 +4 
;step          Allocated to stack - _bp -14 +4 
;implication_method Allocated to stack - _bp -15 +1 
;aggregation_method Allocated to stack - _bp -16 +1 
;rules         Allocated to stack - _bp +1 +3 
;result        Allocated to stack - _bp +4 +18 
;------------------------------------------------------------
	G$fuzzy_rules_defuzzify_lom$0$0 ==.
	C$fuzzy.h$2951$1_0$136 ==.
;	../../fuzzy.h:2951: float fuzzy_rules_defuzzify_lom(
;	-----------------------------------------
;	 function fuzzy_rules_defuzzify_lom
;	-----------------------------------------
_fuzzy_rules_defuzzify_lom:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	mov	a,sp
	add	a,#0x12
	mov	sp,a
	C$fuzzy.h$2963$1_0$136 ==.
;	../../fuzzy.h:2963: &result,
	mov	a,_bp
	add	a,#0x04
	mov	r4,a
	mov	r2,a
	mov	r3,#0x00
	mov	r7,#0x40
	push	ar4
	mov	a,_bp
	add	a,#0xf0
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	mov	a,@r0
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
	mov	dpl, r2
	mov	dph, r3
	mov	b, r7
	lcall	_fuzzy_rules_maximum_result
	mov	a,sp
	add	a,#0xef
	mov	sp,a
	pop	ar4
	C$fuzzy.h$2973$1_0$136 ==.
;	../../fuzzy.h:2973: result.position_count == 0u ||
	mov	a,#0x10
	add	a, r4
	mov	r1,a
	mov	ar6,@r1
	inc	r1
	mov	ar7,@r1
	mov	a,r6
	orl	a,r7
	jz	00101$
	C$fuzzy.h$2974$1_0$136 ==.
;	../../fuzzy.h:2974: result.height <= LEVEL_LO
	mov	ar1,r4
	mov	ar3,@r1
	inc	r1
	mov	ar5,@r1
	inc	r1
	mov	ar6,@r1
	inc	r1
	mov	ar7,@r1
	push	ar4
	push	ar3
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
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00102$
00101$:
	C$fuzzy.h$2976$2_0$137 ==.
;	../../fuzzy.h:2976: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00104$
00102$:
	C$fuzzy.h$2979$1_0$136 ==.
;	../../fuzzy.h:2979: return result.largest_position;
	mov	a,#0x08
	add	a, r4
	mov	r1,a
	mov	ar4,@r1
	inc	r1
	mov	ar5,@r1
	inc	r1
	mov	ar6,@r1
	inc	r1
	mov	ar7,@r1
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
00104$:
	C$fuzzy.h$2980$1_0$136 ==.
;	../../fuzzy.h:2980: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$2980$1_0$136 ==.
	XG$fuzzy_rules_defuzzify_lom$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_defuzzify_method'
;------------------------------------------------------------
;lower         Allocated to stack - _bp -6 +4 
;upper         Allocated to stack - _bp -10 +4 
;step          Allocated to stack - _bp -14 +4 
;defuzz_method Allocated to stack - _bp -15 +1 
;implication_method Allocated to stack - _bp -16 +1 
;aggregation_method Allocated to stack - _bp -17 +1 
;rules         Allocated to registers r5 r6 r7 
;sloc0         Allocated to stack - _bp +1 +4 
;------------------------------------------------------------
	G$fuzzy_rules_defuzzify_method$0$0 ==.
	C$fuzzy.h$2986$1_0$139 ==.
;	../../fuzzy.h:2986: float fuzzy_rules_defuzzify_method(
;	-----------------------------------------
;	 function fuzzy_rules_defuzzify_method
;	-----------------------------------------
_fuzzy_rules_defuzzify_method:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x04
	mov	sp,a
	mov	r5, dpl
	mov	r6, dph
	mov	r7, b
	C$fuzzy.h$2997$1_0$139 ==.
;	../../fuzzy.h:2997: rules == NULL ||
	mov	a,r5
	orl	a,r6
	jnz	00140$
	ljmp	00101$
00140$:
	C$fuzzy.h$2998$1_0$139 ==.
;	../../fuzzy.h:2998: rules->count == 0u ||
	mov	a,#0x90
	add	a, r5
	mov	r2,a
	clr	a
	addc	a, r6
	mov	r3,a
	mov	ar4,r7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	orl	a,r2
	jz	00101$
	C$fuzzy.h$2999$1_0$139 ==.
;	../../fuzzy.h:2999: lower > upper ||
	push	ar7
	push	ar6
	push	ar5
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
	mov	r4, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a,r4
	jnz	00101$
	C$fuzzy.h$3001$1_0$139 ==.
;	../../fuzzy.h:3001: ) {
	push	ar7
	push	ar6
	push	ar5
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
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00102$
00101$:
	C$fuzzy.h$3002$2_0$140 ==.
;	../../fuzzy.h:3002: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00114$
00102$:
	C$fuzzy.h$3005$1_0$139 ==.
;	../../fuzzy.h:3005: switch (defuzz_method) {
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	mov	a,@r0
	add	a,#0xff - 0x05
	jnc	00144$
	ljmp	00112$
00144$:
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	mov	a,@r0
	add	a,@r0
	add	a,@r0
	mov	dptr,#00145$
	jmp	@a+dptr
00145$:
	ljmp	00106$
	ljmp	00107$
	ljmp	00108$
	ljmp	00109$
	ljmp	00110$
	ljmp	00111$
	C$fuzzy.h$3006$2_0$141 ==.
;	../../fuzzy.h:3006: case FUZZY_DEFUZZ_COG:
00106$:
	C$fuzzy.h$3008$2_0$141 ==.
;	../../fuzzy.h:3008: rules,
	mov	a,_bp
	add	a,#0xef
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xf0
	mov	r0,a
	mov	a,@r0
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
	lcall	_fuzzy_rules_defuzzify_cog
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
	add	a,#0xf2
	mov	sp,a
	mov	r0,_bp
	inc	r0
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	ljmp	00114$
	C$fuzzy.h$3016$2_0$141 ==.
;	../../fuzzy.h:3016: case FUZZY_DEFUZZ_BOA:
00107$:
	C$fuzzy.h$3018$2_0$141 ==.
;	../../fuzzy.h:3018: rules,
	mov	a,_bp
	add	a,#0xef
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xf0
	mov	r0,a
	mov	a,@r0
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
	lcall	_fuzzy_rules_defuzzify_boa
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
	add	a,#0xf2
	mov	sp,a
	mov	r0,_bp
	inc	r0
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	ljmp	00114$
	C$fuzzy.h$3026$2_0$141 ==.
;	../../fuzzy.h:3026: case FUZZY_DEFUZZ_COS:
00108$:
	C$fuzzy.h$3028$2_0$141 ==.
;	../../fuzzy.h:3028: rules,
	mov	a,_bp
	add	a,#0xf0
	mov	r0,a
	mov	a,@r0
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
	lcall	_fuzzy_rules_defuzzify_cos
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
	add	a,#0xf3
	mov	sp,a
	mov	r0,_bp
	inc	r0
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	ljmp	00114$
	C$fuzzy.h$3035$2_0$141 ==.
;	../../fuzzy.h:3035: case FUZZY_DEFUZZ_MOM:
00109$:
	C$fuzzy.h$3037$2_0$141 ==.
;	../../fuzzy.h:3037: rules,
	mov	a,_bp
	add	a,#0xef
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xf0
	mov	r0,a
	mov	a,@r0
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
	lcall	_fuzzy_rules_defuzzify_mom
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
	add	a,#0xf2
	mov	sp,a
	mov	r0,_bp
	inc	r0
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	ljmp	00114$
	C$fuzzy.h$3045$2_0$141 ==.
;	../../fuzzy.h:3045: case FUZZY_DEFUZZ_SOM:
00110$:
	C$fuzzy.h$3047$2_0$141 ==.
;	../../fuzzy.h:3047: rules,
	mov	a,_bp
	add	a,#0xef
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xf0
	mov	r0,a
	mov	a,@r0
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
	lcall	_fuzzy_rules_defuzzify_som
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
	add	a,#0xf2
	mov	sp,a
	mov	r0,_bp
	inc	r0
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	C$fuzzy.h$3055$2_0$141 ==.
;	../../fuzzy.h:3055: case FUZZY_DEFUZZ_LOM:
	sjmp	00114$
00111$:
	C$fuzzy.h$3057$2_0$141 ==.
;	../../fuzzy.h:3057: rules,
	mov	a,_bp
	add	a,#0xef
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0xf0
	mov	r0,a
	mov	a,@r0
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
	lcall	_fuzzy_rules_defuzzify_lom
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf2
	mov	sp,a
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	C$fuzzy.h$3065$2_0$141 ==.
;	../../fuzzy.h:3065: default:
	sjmp	00114$
00112$:
	C$fuzzy.h$3066$2_0$141 ==.
;	../../fuzzy.h:3066: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$3067$1_0$139 ==.
;	../../fuzzy.h:3067: }
00114$:
	C$fuzzy.h$3068$1_0$139 ==.
;	../../fuzzy.h:3068: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$3068$1_0$139 ==.
	XG$fuzzy_rules_defuzzify_method$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_defuzzify'
;------------------------------------------------------------
;lower         Allocated to stack - _bp -6 +4 
;upper         Allocated to stack - _bp -10 +4 
;step          Allocated to stack - _bp -14 +4 
;method        Allocated to stack - _bp -15 +1 
;rules         Allocated to registers r5 r6 r7 
;------------------------------------------------------------
	G$fuzzy_rules_defuzzify$0$0 ==.
	C$fuzzy.h$3075$1_0$143 ==.
;	../../fuzzy.h:3075: float fuzzy_rules_defuzzify(
;	-----------------------------------------
;	 function fuzzy_rules_defuzzify
;	-----------------------------------------
_fuzzy_rules_defuzzify:
	push	_bp
	mov	_bp,sp
	mov	r5, dpl
	mov	r6, dph
	mov	r7, b
	C$fuzzy.h$3084$1_0$143 ==.
;	../../fuzzy.h:3084: rules,
	clr	a
	push	acc
	push	acc
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	mov	a,@r0
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
	lcall	_fuzzy_rules_defuzzify_method
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf1
	mov	sp,a
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	C$fuzzy.h$3092$1_0$143 ==.
;	../../fuzzy.h:3092: }
	pop	_bp
	C$fuzzy.h$3092$1_0$143 ==.
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
	C$fuzzy.h$3098$1_0$145 ==.
;	../../fuzzy.h:3098: float fuzzy_rules_cog(
;	-----------------------------------------
;	 function fuzzy_rules_cog
;	-----------------------------------------
_fuzzy_rules_cog:
	push	_bp
	mov	_bp,sp
	mov	r5, dpl
	mov	r6, dph
	mov	r7, b
	C$fuzzy.h$3106$1_0$145 ==.
;	../../fuzzy.h:3106: rules,
	clr	a
	push	acc
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
	lcall	_fuzzy_rules_defuzzify_cog
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf2
	mov	sp,a
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	C$fuzzy.h$3113$1_0$145 ==.
;	../../fuzzy.h:3113: }
	pop	_bp
	C$fuzzy.h$3113$1_0$145 ==.
	XG$fuzzy_rules_cog$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'temperature_low'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fcontroller_8051$temperature_low$0$0 ==.
	C$controller_8051.c$59$1_0$147 ==.
;	../../controller_8051.c:59: static float temperature_low(
;	-----------------------------------------
;	 function temperature_low
;	-----------------------------------------
_temperature_low:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$controller_8051.c$68$1_0$147 ==.
;	../../controller_8051.c:68: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$controller_8051.c$64$1_0$147 ==.
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
	C$controller_8051.c$70$1_0$147 ==.
;	../../controller_8051.c:70: }
	C$controller_8051.c$70$1_0$147 ==.
	XFcontroller_8051$temperature_low$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'temperature_high'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fcontroller_8051$temperature_high$0$0 ==.
	C$controller_8051.c$73$1_0$149 ==.
;	../../controller_8051.c:73: static float temperature_high(
;	-----------------------------------------
;	 function temperature_high
;	-----------------------------------------
_temperature_high:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$controller_8051.c$82$1_0$149 ==.
;	../../controller_8051.c:82: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$controller_8051.c$78$1_0$149 ==.
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
	C$controller_8051.c$84$1_0$149 ==.
;	../../controller_8051.c:84: }
	C$controller_8051.c$84$1_0$149 ==.
	XFcontroller_8051$temperature_high$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fan_slow'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fcontroller_8051$fan_slow$0$0 ==.
	C$controller_8051.c$91$1_0$151 ==.
;	../../controller_8051.c:91: static float fan_slow(
;	-----------------------------------------
;	 function fan_slow
;	-----------------------------------------
_fan_slow:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$controller_8051.c$100$1_0$151 ==.
;	../../controller_8051.c:100: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$controller_8051.c$96$1_0$151 ==.
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
	C$controller_8051.c$102$1_0$151 ==.
;	../../controller_8051.c:102: }
	C$controller_8051.c$102$1_0$151 ==.
	XFcontroller_8051$fan_slow$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fan_fast'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fcontroller_8051$fan_fast$0$0 ==.
	C$controller_8051.c$105$1_0$153 ==.
;	../../controller_8051.c:105: static float fan_fast(
;	-----------------------------------------
;	 function fan_fast
;	-----------------------------------------
_fan_fast:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$controller_8051.c$114$1_0$153 ==.
;	../../controller_8051.c:114: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$controller_8051.c$110$1_0$153 ==.
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
	C$controller_8051.c$116$1_0$153 ==.
;	../../controller_8051.c:116: }
	C$controller_8051.c$116$1_0$153 ==.
	XFcontroller_8051$fan_fast$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'calculate_fan_speed'
;------------------------------------------------------------
;temperature   Allocated to stack - _bp +1 +4 
;rules         Allocated to stack - _bp +9 +146 
;result        Allocated to registers r4 r5 r6 r7 
;sloc0         Allocated to stack - _bp +5 +4 
;------------------------------------------------------------
	Fcontroller_8051$calculate_fan_speed$0$0 ==.
	C$controller_8051.c$123$1_0$155 ==.
;	../../controller_8051.c:123: static float calculate_fan_speed(float temperature)
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
	add	a,#0x96
	mov	sp,a
	C$controller_8051.c$129$1_0$155 ==.
;	../../controller_8051.c:129: rules.count = 0;
	mov	a,_bp
	add	a,#0x09
	mov	r3,a
	add	a,#0x90
	mov	r1,a
	mov	@r1,#0x00
	inc	r1
	mov	@r1,#0x00
	dec	r1
	C$controller_8051.c$132$1_0$155 ==.
;	../../controller_8051.c:132: if (!FUZZY_RULE_ADD(&rules, temperature_low(temperature), fan_slow)) return 0.0f;
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
	push	ar1
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
	pop	ar1
	pop	ar3
	mov	ar4,r3
	mov	r6,#0x00
	mov	r7,#0x40
	push	ar3
	push	ar1
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
	mov	dpl, r4
	mov	dph, r6
	mov	b, r7
	lcall	_fuzzy_rules_add
	mov	r7, dpl
	mov	a,sp
	add	a,#0xf7
	mov	sp,a
	pop	ar1
	pop	ar3
	mov	a,r7
	jnz	00102$
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00105$
00102$:
	C$controller_8051.c$134$1_0$155 ==.
;	../../controller_8051.c:134: if (!FUZZY_RULE_ADD(&rules, temperature_high(temperature), fan_fast)) return 0.0f;
	push	ar1
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
	push	ar1
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
	pop	ar1
	pop	ar3
	mov	ar2,r3
	mov	r6,#0x00
	mov	r7,#0x40
	push	ar3
	push	ar1
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
	pop	ar1
	pop	ar3
	pop	ar1
	mov	a,r7
	jnz	00104$
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00105$
00104$:
	C$controller_8051.c$138$1_0$155 ==.
;	../../controller_8051.c:138: &rules,
	mov	r7,#0x00
	mov	r6,#0x40
	push	ar1
	mov	a,#0x03
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
	mov	dpl, r3
	mov	dph, r7
	mov	b, r6
	lcall	_fuzzy_rules_defuzzify
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf3
	mov	sp,a
	pop	ar1
	C$controller_8051.c$146$1_0$155 ==.
;	../../controller_8051.c:146: rules.count = 0;
	mov	@r1,#0x00
	inc	r1
	mov	@r1,#0x00
	C$controller_8051.c$148$1_0$155 ==.
;	../../controller_8051.c:148: return result;
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
00105$:
	C$controller_8051.c$149$1_0$155 ==.
;	../../controller_8051.c:149: }
	mov	sp,_bp
	pop	_bp
	C$controller_8051.c$149$1_0$155 ==.
	XFcontroller_8051$calculate_fan_speed$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fan_speed_to_pwm'
;------------------------------------------------------------
;fan_speed     Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fcontroller_8051$fan_speed_to_pwm$0$0 ==.
	C$controller_8051.c$156$1_0$157 ==.
;	../../controller_8051.c:156: static unsigned char fan_speed_to_pwm(
;	-----------------------------------------
;	 function fan_speed_to_pwm
;	-----------------------------------------
_fan_speed_to_pwm:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$controller_8051.c$160$1_0$157 ==.
;	../../controller_8051.c:160: if (fan_speed <= 0.0f) {
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
	C$controller_8051.c$161$2_0$158 ==.
;	../../controller_8051.c:161: return 0u;
	mov	dpl, #0x00
	sjmp	00105$
00102$:
	C$controller_8051.c$164$1_0$157 ==.
;	../../controller_8051.c:164: if (fan_speed >= 100.0f) {
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
	C$controller_8051.c$165$2_0$159 ==.
;	../../controller_8051.c:165: return 100u;
	mov	dpl, #0x64
	sjmp	00105$
00104$:
	C$controller_8051.c$170$1_0$157 ==.
;	../../controller_8051.c:170: );
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
	C$controller_8051.c$171$1_0$157 ==.
;	../../controller_8051.c:171: }
	C$controller_8051.c$171$1_0$157 ==.
	XFcontroller_8051$fan_speed_to_pwm$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
	G$main$0$0 ==.
	C$controller_8051.c$188$1_0$161 ==.
;	../../controller_8051.c:188: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	C$controller_8051.c$196$1_0$161 ==.
;	../../controller_8051.c:196: 42u;
	mov	_test_temperature,#0x2a
	C$controller_8051.c$202$1_0$161 ==.
;	../../controller_8051.c:202: 0x55u;
	mov	_P0,#0x55
	C$controller_8051.c$205$1_0$161 ==.
;	../../controller_8051.c:205: 0x00u;
	mov	_P1,#0x00
	C$controller_8051.c$211$1_0$161 ==.
;	../../controller_8051.c:211: test_temperature = P2;
	mov	_test_temperature,_P2
	C$controller_8051.c$216$2_0$161 ==.
;	../../controller_8051.c:216: );
	mov	dpl, _test_temperature
	lcall	___uchar2fs
	lcall	_calculate_fan_speed
	mov	_test_fan_speed,dpl
	mov	(_test_fan_speed + 1),dph
	mov	(_test_fan_speed + 2),b
	mov	(_test_fan_speed + 3),a
	C$controller_8051.c$220$1_0$161 ==.
;	../../controller_8051.c:220: test_fan_speed
	mov	dpl, _test_fan_speed
	mov	dph, (_test_fan_speed + 1)
	mov	b, (_test_fan_speed + 2)
	mov	a, (_test_fan_speed + 3)
	lcall	_fan_speed_to_pwm
	mov	_test_pwm,dpl
	C$controller_8051.c$227$1_0$161 ==.
;	../../controller_8051.c:227: test_pwm;
	mov	_P1,_test_pwm
	C$controller_8051.c$233$1_0$161 ==.
;	../../controller_8051.c:233: 0xAAu;
	mov	_P0,#0xaa
00103$:
	sjmp	00103$
	C$controller_8051.c$238$2_0$161 ==.
;	../../controller_8051.c:238: }
	C$controller_8051.c$238$2_0$161 ==.
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
