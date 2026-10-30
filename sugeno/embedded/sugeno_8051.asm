;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.0 #15242 (Linux)
;--------------------------------------------------------
	.module sugeno_demo
	
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
	.globl _test_vibration
	.globl _test_load
	.globl _test_temperature
	.globl _fuzzy_not
	.globl _fuzzy_and_array
	.globl _fuzzy_or_array
	.globl _fuzzy_sugeno_weighted_average_array
	.globl _fuzzy_sugeno_weighted_sum_array
	.globl _fuzzy_ramp
	.globl _fuzzy_interpolate_membership
	.globl _fuzzy_function_array
	.globl _fuzzy_rules_create
	.globl _fuzzy_rules_add
	.globl _fuzzy_rules_defuzzify_method
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
Fsugeno_demo$fuzzy_values_buffer$0_0$0==.
_fuzzy_values_buffer:
	.ds 64
G$test_temperature$0_0$0==.
_test_temperature::
	.ds 1
G$test_load$0_0$0==.
_test_load::
	.ds 1
G$test_vibration$0_0$0==.
_test_vibration::
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
	C$sugeno_demo.c$25$2_0$152 ==.
;	../../sugeno_demo.c:25: volatile unsigned char test_temperature = 42u;
	mov	_test_temperature,#0x2a
	C$sugeno_demo.c$26$2_0$152 ==.
;	../../sugeno_demo.c:26: volatile unsigned char test_load = 65u;
	mov	_test_load,#0x41
	C$sugeno_demo.c$27$2_0$152 ==.
;	../../sugeno_demo.c:27: volatile unsigned char test_vibration = 4u;
	mov	_test_vibration,#0x04
	C$sugeno_demo.c$29$2_0$152 ==.
;	../../sugeno_demo.c:29: volatile unsigned char test_pwm = 0u;
	mov	_test_pwm,#0x00
	C$sugeno_demo.c$30$2_0$152 ==.
;	../../sugeno_demo.c:30: volatile float test_fan_speed = 0.0f;
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
	Fsugeno_demo$fuzzy_values_initialize$0$0 ==.
	C$fuzzy.h$102$0_0$3 ==.
;	../../fuzzy.h:102: static float *fuzzy_values_initialize(void)
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
	C$fuzzy.h$107$3_0$5 ==.
;	../../fuzzy.h:107: index = 0u;
	mov	r6,#0x00
	mov	r7,#0x00
00102$:
	C$fuzzy.h$111$3_0$5 ==.
;	../../fuzzy.h:111: fuzzy_values_buffer[index] = 0.0f;
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
	C$fuzzy.h$109$2_0$4 ==.
;	../../fuzzy.h:109: index++
	inc	r6
	cjne	r6,#0x00,00119$
	inc	r7
00119$:
	C$fuzzy.h$108$2_0$4 ==.
;	../../fuzzy.h:108: index < FUZZY_MAX_VALUES;
	clr	c
	mov	a,r6
	subb	a,#0x10
	mov	a,r7
	subb	a,#0x00
	jc	00102$
	C$fuzzy.h$114$1_0$3 ==.
;	../../fuzzy.h:114: return fuzzy_values_buffer;
	mov	dptr,#_fuzzy_values_buffer
	mov	b, #0x40
	C$fuzzy.h$115$1_0$3 ==.
;	../../fuzzy.h:115: }
	C$fuzzy.h$115$1_0$3 ==.
	XFsugeno_demo$fuzzy_values_initialize$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_clamp'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$fuzzy_clamp$0$0 ==.
	C$fuzzy.h$727$1_0$22 ==.
;	../../fuzzy.h:727: static float fuzzy_clamp(float value)
;	-----------------------------------------
;	 function fuzzy_clamp
;	-----------------------------------------
_fuzzy_clamp:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$fuzzy.h$729$1_0$22 ==.
;	../../fuzzy.h:729: if (value < LEVEL_LO) {
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
	C$fuzzy.h$730$2_0$23 ==.
;	../../fuzzy.h:730: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00105$
00102$:
	C$fuzzy.h$733$1_0$22 ==.
;	../../fuzzy.h:733: if (value > LEVEL_HI) {
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
	C$fuzzy.h$734$2_0$24 ==.
;	../../fuzzy.h:734: return LEVEL_HI;
	mov	dptr,#0x0000
	mov	b, #0x80
	mov	a, #0x3f
	sjmp	00105$
00104$:
	C$fuzzy.h$737$1_0$22 ==.
;	../../fuzzy.h:737: return value;
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
00105$:
	C$fuzzy.h$738$1_0$22 ==.
;	../../fuzzy.h:738: }
	C$fuzzy.h$738$1_0$22 ==.
	XFsugeno_demo$fuzzy_clamp$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_not'
;------------------------------------------------------------
;membership    Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	G$fuzzy_not$0$0 ==.
	C$fuzzy.h$743$1_0$26 ==.
;	../../fuzzy.h:743: float fuzzy_not(
;	-----------------------------------------
;	 function fuzzy_not
;	-----------------------------------------
_fuzzy_not:
	C$fuzzy.h$748$1_0$26 ==.
;	../../fuzzy.h:748: fuzzy_clamp( membership
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
	C$fuzzy.h$750$1_0$26 ==.
;	../../fuzzy.h:750: }
	C$fuzzy.h$750$1_0$26 ==.
	XG$fuzzy_not$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_apply_hedge'
;------------------------------------------------------------
;hedge         Allocated to stack - _bp -3 +1 
;membership    Allocated to stack - _bp +1 +4 
;result        Allocated to registers r2 r3 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$fuzzy_apply_hedge$0$0 ==.
	C$fuzzy.h$760$1_0$28 ==.
;	../../fuzzy.h:760: static float fuzzy_apply_hedge(
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
	C$fuzzy.h$766$1_0$28 ==.
;	../../fuzzy.h:766: fuzzy_clamp( membership
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
	C$fuzzy.h$771$2_0$29 ==.
;	../../fuzzy.h:771: float result =
	mov	r2,#0x00
	mov	r3,#0x00
	mov	r6,#0x80
	mov	r7,#0x3f
	C$fuzzy.h$774$1_1$29 ==.
;	../../fuzzy.h:774: if (hedge == 0u) {
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	a,@r0
	jnz	00110$
	C$fuzzy.h$775$2_1$30 ==.
;	../../fuzzy.h:775: hedge = 1u;
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	@r0,#0x01
	C$fuzzy.h$778$1_1$28 ==.
;	../../fuzzy.h:778: while (hedge > 0u) {
00110$:
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	ar5,@r0
00103$:
	mov	a,r5
	jz	00105$
	C$fuzzy.h$779$1_1$28 ==.
;	../../fuzzy.h:779: result *= membership;
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
	C$fuzzy.h$781$1_1$28 ==.
;	../../fuzzy.h:781: hedge--;
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
	C$fuzzy.h$785$1_1$29 ==.
;	../../fuzzy.h:785: result
	mov	dpl, r2
	mov	dph, r3
	mov	b, r6
	mov	a, r7
	lcall	_fuzzy_clamp
	C$fuzzy.h$801$1_1$28 ==.
;	../../fuzzy.h:801: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$801$1_1$28 ==.
	XFsugeno_demo$fuzzy_apply_hedge$0$0 ==.
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
	C$fuzzy.h$815$1_1$33 ==.
;	../../fuzzy.h:815: float fuzzy_and_array(
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
	C$fuzzy.h$826$1_0$33 ==.
;	../../fuzzy.h:826: args == NULL ||
	mov	a,_bp
	add	a,#0xf9
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$827$1_0$33 ==.
;	../../fuzzy.h:827: count == 0u
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00102$
00101$:
	C$fuzzy.h$829$2_0$34 ==.
;	../../fuzzy.h:829: return LEVEL_HI;
	mov	dptr,#0x0000
	mov	b, #0x80
	mov	a, #0x3f
	ljmp	00121$
00102$:
	C$fuzzy.h$833$1_0$33 ==.
;	../../fuzzy.h:833: method != FUZZY_LOGIC_STANDARD &&
	mov	a,r5
	jz	00105$
	C$fuzzy.h$834$1_0$33 ==.
;	../../fuzzy.h:834: method != FUZZY_LOGIC_ALGEBRAIC &&
	cjne	r5,#0x01,00192$
	sjmp	00105$
00192$:
	C$fuzzy.h$836$1_0$33 ==.
;	../../fuzzy.h:836: ) {
	cjne	r5,#0x02,00193$
	sjmp	00105$
00193$:
	C$fuzzy.h$837$2_0$35 ==.
;	../../fuzzy.h:837: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00121$
00105$:
	C$fuzzy.h$842$1_0$33 ==.
;	../../fuzzy.h:842: args[0]
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
	C$fuzzy.h$846$3_0$37 ==.
;	../../fuzzy.h:846: index = 1u;
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
	C$fuzzy.h$847$2_0$36 ==.
;	../../fuzzy.h:847: index < count;
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
	C$fuzzy.h$852$1_0$33 ==.
;	../../fuzzy.h:852: args[index]
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
	C$fuzzy.h$855$1_0$33 ==.
;	../../fuzzy.h:855: switch (method) {
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
	C$fuzzy.h$856$4_0$38 ==.
;	../../fuzzy.h:856: case FUZZY_LOGIC_STANDARD:
00108$:
	C$fuzzy.h$857$1_0$33 ==.
;	../../fuzzy.h:857: if (next < result) {
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
	C$fuzzy.h$858$5_0$39 ==.
;	../../fuzzy.h:858: result = next;
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
	C$fuzzy.h$860$4_0$38 ==.
;	../../fuzzy.h:860: break;
	ljmp	00120$
	C$fuzzy.h$862$4_0$38 ==.
;	../../fuzzy.h:862: case FUZZY_LOGIC_ALGEBRAIC:
00111$:
	C$fuzzy.h$864$1_0$33 ==.
;	../../fuzzy.h:864: next;
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
	C$fuzzy.h$865$1_0$33 ==.
;	../../fuzzy.h:865: break;
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
	C$fuzzy.h$867$4_0$38 ==.
;	../../fuzzy.h:867: case FUZZY_LOGIC_BOUNDED:
00112$:
	C$fuzzy.h$870$1_0$33 ==.
;	../../fuzzy.h:870: next -
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
	C$fuzzy.h$873$1_0$33 ==.
;	../../fuzzy.h:873: if (result < LEVEL_LO) {
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
	C$fuzzy.h$874$5_0$40 ==.
;	../../fuzzy.h:874: result = LEVEL_LO;
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
	C$fuzzy.h$876$4_0$38 ==.
;	../../fuzzy.h:876: break;
	C$fuzzy.h$878$4_0$38 ==.
;	../../fuzzy.h:878: default:
	sjmp	00120$
00115$:
	C$fuzzy.h$879$4_0$38 ==.
;	../../fuzzy.h:879: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$880$3_0$37 ==.
;	../../fuzzy.h:880: }
	sjmp	00121$
00120$:
	C$fuzzy.h$848$2_0$36 ==.
;	../../fuzzy.h:848: index++
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
	C$fuzzy.h$884$1_0$33 ==.
;	../../fuzzy.h:884: result
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
	C$fuzzy.h$886$1_0$33 ==.
;	../../fuzzy.h:886: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$886$1_0$33 ==.
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
	C$fuzzy.h$901$1_0$42 ==.
;	../../fuzzy.h:901: float fuzzy_or_array(
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
	C$fuzzy.h$912$1_0$42 ==.
;	../../fuzzy.h:912: args == NULL ||
	mov	a,_bp
	add	a,#0xf9
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$913$1_0$42 ==.
;	../../fuzzy.h:913: count == 0u
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00102$
00101$:
	C$fuzzy.h$915$2_0$43 ==.
;	../../fuzzy.h:915: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00121$
00102$:
	C$fuzzy.h$919$1_0$42 ==.
;	../../fuzzy.h:919: method != FUZZY_LOGIC_STANDARD &&
	mov	a,r5
	jz	00105$
	C$fuzzy.h$920$1_0$42 ==.
;	../../fuzzy.h:920: method != FUZZY_LOGIC_ALGEBRAIC &&
	cjne	r5,#0x01,00192$
	sjmp	00105$
00192$:
	C$fuzzy.h$922$1_0$42 ==.
;	../../fuzzy.h:922: ) {
	cjne	r5,#0x02,00193$
	sjmp	00105$
00193$:
	C$fuzzy.h$923$2_0$44 ==.
;	../../fuzzy.h:923: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00121$
00105$:
	C$fuzzy.h$928$1_0$42 ==.
;	../../fuzzy.h:928: args[0]
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
	C$fuzzy.h$932$3_0$46 ==.
;	../../fuzzy.h:932: index = 1u;
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
	C$fuzzy.h$933$2_0$45 ==.
;	../../fuzzy.h:933: index < count;
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
	C$fuzzy.h$938$1_0$42 ==.
;	../../fuzzy.h:938: args[index]
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
	C$fuzzy.h$941$1_0$42 ==.
;	../../fuzzy.h:941: switch (method) {
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
	C$fuzzy.h$942$4_0$47 ==.
;	../../fuzzy.h:942: case FUZZY_LOGIC_STANDARD:
00108$:
	C$fuzzy.h$943$1_0$42 ==.
;	../../fuzzy.h:943: if (next > result) {
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
	C$fuzzy.h$944$5_0$48 ==.
;	../../fuzzy.h:944: result = next;
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
	C$fuzzy.h$946$4_0$47 ==.
;	../../fuzzy.h:946: break;
	ljmp	00120$
	C$fuzzy.h$948$4_0$47 ==.
;	../../fuzzy.h:948: case FUZZY_LOGIC_ALGEBRAIC:
00111$:
	C$fuzzy.h$951$1_0$42 ==.
;	../../fuzzy.h:951: next -
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
	C$fuzzy.h$952$1_0$42 ==.
;	../../fuzzy.h:952: result * next;
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
	C$fuzzy.h$953$1_0$42 ==.
;	../../fuzzy.h:953: break;
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
	C$fuzzy.h$955$4_0$47 ==.
;	../../fuzzy.h:955: case FUZZY_LOGIC_BOUNDED:
	sjmp	00120$
00112$:
	C$fuzzy.h$957$1_0$42 ==.
;	../../fuzzy.h:957: next;
	push	ar2
	push	ar4
	push	ar5
	push	ar6
	push	ar3
	C$fuzzy.h$959$1_0$42 ==.
;	../../fuzzy.h:959: if (result > LEVEL_HI) {
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
	C$fuzzy.h$960$5_0$49 ==.
;	../../fuzzy.h:960: result = LEVEL_HI;
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
	C$fuzzy.h$962$4_0$47 ==.
;	../../fuzzy.h:962: break;
	C$fuzzy.h$964$4_0$47 ==.
;	../../fuzzy.h:964: default:
	sjmp	00120$
00115$:
	C$fuzzy.h$965$4_0$47 ==.
;	../../fuzzy.h:965: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$966$3_0$46 ==.
;	../../fuzzy.h:966: }
	sjmp	00121$
00120$:
	C$fuzzy.h$934$2_0$45 ==.
;	../../fuzzy.h:934: index++
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
	C$fuzzy.h$970$1_0$42 ==.
;	../../fuzzy.h:970: result
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
	C$fuzzy.h$972$1_0$42 ==.
;	../../fuzzy.h:972: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$972$1_0$42 ==.
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
	C$fuzzy.h$983$1_0$51 ==.
;	../../fuzzy.h:983: float fuzzy_sugeno_weighted_average_array(
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
	C$fuzzy.h$996$1_0$51 ==.
;	../../fuzzy.h:996: values == NULL ||
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$997$1_0$51 ==.
;	../../fuzzy.h:997: value_count == 0u ||
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$998$1_0$51 ==.
;	../../fuzzy.h:998: value_count % 2u != 0u
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	jnb	acc.0,00102$
00101$:
	C$fuzzy.h$1000$2_0$52 ==.
;	../../fuzzy.h:1000: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00111$
00102$:
	C$fuzzy.h$1004$1_0$51 ==.
;	../../fuzzy.h:1004: 0.0f;
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
	C$fuzzy.h$1007$1_0$51 ==.
;	../../fuzzy.h:1007: 0.0f;
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
	C$fuzzy.h$1010$1_0$51 ==.
;	../../fuzzy.h:1010: index = 0u;
	mov	r6,a
	mov	r7,a
00109$:
	C$fuzzy.h$1011$2_0$53 ==.
;	../../fuzzy.h:1011: index < value_count;
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
	C$fuzzy.h$1016$3_0$54 ==.
;	../../fuzzy.h:1016: values[index]
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
	C$fuzzy.h$1020$3_0$54 ==.
;	../../fuzzy.h:1020: values[index + 1u];
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
	C$fuzzy.h$1025$1_0$51 ==.
;	../../fuzzy.h:1025: consequent;
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
	C$fuzzy.h$1028$1_0$51 ==.
;	../../fuzzy.h:1028: firing_strength;
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
	C$fuzzy.h$1013$1_0$51 ==.
;	../../fuzzy.h:1013: ) {
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
	C$fuzzy.h$1031$1_0$51 ==.
;	../../fuzzy.h:1031: if (firing_sum <= LEVEL_LO) {
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
	C$fuzzy.h$1032$2_0$55 ==.
;	../../fuzzy.h:1032: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00111$
00107$:
	C$fuzzy.h$1036$1_0$51 ==.
;	../../fuzzy.h:1036: firing_sum;
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
	C$fuzzy.h$1037$1_0$51 ==.
;	../../fuzzy.h:1037: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1037$1_0$51 ==.
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
	C$fuzzy.h$1047$1_0$57 ==.
;	../../fuzzy.h:1047: float fuzzy_sugeno_weighted_sum_array(
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
	C$fuzzy.h$1059$1_0$57 ==.
;	../../fuzzy.h:1059: values == NULL ||
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$1060$1_0$57 ==.
;	../../fuzzy.h:1060: value_count == 0u ||
	mov	a,r6
	orl	a,r7
	jz	00101$
	C$fuzzy.h$1061$1_0$57 ==.
;	../../fuzzy.h:1061: value_count % 2u != 0u
	mov	a,r6
	jnb	acc.0,00102$
00101$:
	C$fuzzy.h$1063$2_0$58 ==.
;	../../fuzzy.h:1063: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00109$
00102$:
	C$fuzzy.h$1067$1_0$57 ==.
;	../../fuzzy.h:1067: 0.0f;
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
	C$fuzzy.h$1070$1_0$57 ==.
;	../../fuzzy.h:1070: index = 0u;
	mov	r4,a
	mov	r5,a
00107$:
	C$fuzzy.h$1071$2_0$59 ==.
;	../../fuzzy.h:1071: index < value_count;
	clr	c
	mov	a,r4
	subb	a,r6
	mov	a,r5
	subb	a,r7
	jc	00139$
	ljmp	00105$
00139$:
	C$fuzzy.h$1076$1_0$57 ==.
;	../../fuzzy.h:1076: values[index]
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
	C$fuzzy.h$1080$3_0$60 ==.
;	../../fuzzy.h:1080: values[index + 1u];
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
	C$fuzzy.h$1085$1_0$57 ==.
;	../../fuzzy.h:1085: consequent;
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
	C$fuzzy.h$1073$1_0$57 ==.
;	../../fuzzy.h:1073: ) {
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
	C$fuzzy.h$1088$1_0$57 ==.
;	../../fuzzy.h:1088: return weighted_sum;
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
	C$fuzzy.h$1089$1_0$57 ==.
;	../../fuzzy.h:1089: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1089$1_0$57 ==.
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
	C$fuzzy.h$1095$1_0$62 ==.
;	../../fuzzy.h:1095: float fuzzy_ramp(
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
	C$fuzzy.h$1106$1_0$62 ==.
;	../../fuzzy.h:1106: if (lower_boundary >= upper_boundary) {
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
	C$fuzzy.h$1107$2_0$63 ==.
;	../../fuzzy.h:1107: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00109$
00102$:
	C$fuzzy.h$1110$1_0$62 ==.
;	../../fuzzy.h:1110: if (value <= lower_boundary) {
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
	C$fuzzy.h$1112$2_0$64 ==.
;	../../fuzzy.h:1112: ramp_up
	mov	a,_bp
	add	a,#0xf5
	mov	r0,a
	mov	a,@r0
	jz	00111$
	C$fuzzy.h$1113$2_0$64 ==.
;	../../fuzzy.h:1113: ? LEVEL_LO
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
	C$fuzzy.h$1114$2_0$64 ==.
;	../../fuzzy.h:1114: : LEVEL_HI;
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
	C$fuzzy.h$1116$1_0$62 ==.
;	../../fuzzy.h:1116: else if (value >= upper_boundary) {
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
	C$fuzzy.h$1118$2_0$65 ==.
;	../../fuzzy.h:1118: ramp_up
	mov	a,_bp
	add	a,#0xf5
	mov	r0,a
	mov	a,@r0
	jz	00113$
	C$fuzzy.h$1119$2_0$65 ==.
;	../../fuzzy.h:1119: ? LEVEL_HI
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
	C$fuzzy.h$1120$2_0$65 ==.
;	../../fuzzy.h:1120: : LEVEL_LO;
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
	C$fuzzy.h$1124$1_0$62 ==.
;	../../fuzzy.h:1124: (value - lower_boundary) /
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	C$fuzzy.h$1125$1_0$62 ==.
;	../../fuzzy.h:1125: (upper_boundary - lower_boundary);
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
	C$fuzzy.h$1128$1_0$62 ==.
;	../../fuzzy.h:1128: ramp_up
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
	C$fuzzy.h$1129$2_0$66 ==.
;	../../fuzzy.h:1129: ? normalized
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
	C$fuzzy.h$1130$1_0$62 ==.
;	../../fuzzy.h:1130: : LEVEL_HI - normalized;
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
	C$fuzzy.h$1134$1_0$62 ==.
;	../../fuzzy.h:1134: result,
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
	C$fuzzy.h$1137$1_0$62 ==.
;	../../fuzzy.h:1137: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1137$1_0$62 ==.
	XG$fuzzy_ramp$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_interpolate_membership'
;------------------------------------------------------------
;memberships   Allocated to stack - _bp -5 +3 
;count         Allocated to stack - _bp -7 +2 
;value         Allocated to stack - _bp -11 +4 
;universe      Allocated to stack - _bp +1 +3 
;index         Allocated to stack - _bp +14 +2 
;ratio         Allocated to stack - _bp +16 +4 
;sloc0         Allocated to stack - _bp +4 +4 
;sloc1         Allocated to stack - _bp +8 +2 
;sloc2         Allocated to stack - _bp +10 +4 
;sloc3         Allocated to stack - _bp +20 +2 
;------------------------------------------------------------
	G$fuzzy_interpolate_membership$0$0 ==.
	C$fuzzy.h$1139$1_0$68 ==.
;	../../fuzzy.h:1139: float fuzzy_interpolate_membership(
;	-----------------------------------------
;	 function fuzzy_interpolate_membership
;	-----------------------------------------
_fuzzy_interpolate_membership:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	mov	a,sp
	add	a,#0x10
	mov	sp,a
	C$fuzzy.h$1150$1_0$68 ==.
;	../../fuzzy.h:1150: universe == NULL ||
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$1151$1_0$68 ==.
;	../../fuzzy.h:1151: memberships == NULL ||
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$1152$1_0$68 ==.
;	../../fuzzy.h:1152: count == 0u
	mov	a,_bp
	add	a,#0xf9
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00102$
00101$:
	C$fuzzy.h$1154$2_0$69 ==.
;	../../fuzzy.h:1154: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00118$
00102$:
	C$fuzzy.h$1157$1_0$68 ==.
;	../../fuzzy.h:1157: if (value <= universe[0]) {
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
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	mov	a,_bp
	add	a,#0xf5
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
	mov	b, r4
	mov	a, r7
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00106$
	C$fuzzy.h$1158$2_0$70 ==.
;	../../fuzzy.h:1158: return fuzzy_clamp(memberships[0]);
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
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
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	_fuzzy_clamp
	ljmp	00118$
00106$:
	C$fuzzy.h$1161$1_0$68 ==.
;	../../fuzzy.h:1161: if (value >= universe[count - 1u]) {
	mov	a,_bp
	add	a,#0xf9
	mov	r0,a
	mov	a,@r0
	add	a,#0xff
	mov	r6,a
	inc	r0
	mov	a,@r0
	addc	a,#0xff
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
	mov	r0,_bp
	inc	r0
	mov	a,r6
	add	a, @r0
	mov	r6,a
	mov	a,r7
	inc	r0
	addc	a, @r0
	mov	r7,a
	inc	r0
	mov	ar5,@r0
	mov	dpl,r6
	mov	dph,r7
	mov	b,r5
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	push	ar6
	push	ar7
	push	ar5
	push	ar4
	mov	a,_bp
	add	a,#0xf5
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
	jc	00108$
	C$fuzzy.h$1162$2_0$71 ==.
;	../../fuzzy.h:1162: return fuzzy_clamp(memberships[count - 1u]);
	mov	a,_bp
	add	a,#0xf9
	mov	r0,a
	mov	a,@r0
	add	a,#0xff
	mov	r6,a
	inc	r0
	mov	a,@r0
	addc	a,#0xff
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
	mov	ar5,@r0
	mov	dpl,r6
	mov	dph,r7
	mov	b,r5
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	dpl,r6
	mov	dph,r7
	mov	b,r5
	lcall	_fuzzy_clamp
	ljmp	00118$
00108$:
	C$fuzzy.h$1165$2_0$72 ==.
;	../../fuzzy.h:1165: for (index = 0u; index + 1u < count; index++) {
	clr	a
	mov	r6,a
	mov	r7,a
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
00116$:
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	mov	a,#0x01
	add	a, @r0
	mov	r2,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r3,a
	mov	a,_bp
	add	a,#0xf9
	mov	r0,a
	clr	c
	mov	a,r2
	subb	a,@r0
	mov	a,r3
	inc	r0
	subb	a,@r0
	jc	00179$
	ljmp	00114$
00179$:
	C$fuzzy.h$1167$1_0$68 ==.
;	../../fuzzy.h:1167: value >= universe[index] &&
	push	ar6
	push	ar7
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	mov	a,_bp
	add	a,#0x08
	mov	r1,a
	mov	a,@r0
	add	a,@r0
	mov	@r1,a
	inc	r0
	mov	a,@r0
	rlc	a
	inc	r1
	mov	@r1,a
	dec	r1
	mov	a,@r1
	add	a,@r1
	mov	@r1,a
	inc	r1
	mov	a,@r1
	rlc	a
	mov	@r1,a
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x08
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
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	mov	a,_bp
	add	a,#0x04
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
	push	ar7
	push	ar6
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
	add	a,#0xf5
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
	pop	ar6
	pop	ar7
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	pop	ar7
	pop	ar6
	jnb	b0,00180$
	ljmp	00117$
00180$:
	C$fuzzy.h$1168$1_0$68 ==.
;	../../fuzzy.h:1168: value <= universe[index + 1u]
	push	ar6
	push	ar7
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	mov	a,#0x01
	add	a, @r0
	mov	r4,a
	clr	a
	inc	r0
	addc	a, @r0
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
	mov	r0,_bp
	inc	r0
	mov	a,r4
	add	a, @r0
	mov	r4,a
	mov	a,r5
	inc	r0
	addc	a, @r0
	mov	r5,a
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
	push	ar7
	push	ar6
	mov	a,_bp
	add	a,#0xf5
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
	lcall	___fslt
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar6
	pop	ar7
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	pop	ar7
	pop	ar6
	jnb	b0,00181$
	ljmp	00117$
00181$:
	C$fuzzy.h$1170$1_0$68 ==.
;	../../fuzzy.h:1170: if (universe[index] == universe[index + 1u]) {
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
	mov	r0,_bp
	inc	r0
	mov	a,r4
	add	a, @r0
	mov	r4,a
	mov	a,r5
	inc	r0
	addc	a, @r0
	mov	r3,a
	inc	r0
	mov	ar5,@r0
	mov	dpl,r4
	mov	dph,r3
	mov	b,r5
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r2,a
	push	ar7
	push	ar6
	push	ar4
	push	ar3
	push	ar5
	push	ar2
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
	lcall	___fseq
	mov	r5, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar6
	pop	ar7
	mov	a,r5
	jz	00110$
	C$fuzzy.h$1171$5_0$75 ==.
;	../../fuzzy.h:1171: return fuzzy_clamp(memberships[index]);
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,_bp
	add	a,#0x08
	mov	r1,a
	mov	a,@r1
	add	a, @r0
	mov	r3,a
	inc	r1
	mov	a,@r1
	inc	r0
	addc	a, @r0
	mov	r4,a
	inc	r0
	mov	ar5,@r0
	mov	dpl,r3
	mov	dph,r4
	mov	b,r5
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	dpl,r3
	mov	dph,r4
	mov	b,r5
	lcall	_fuzzy_clamp
	ljmp	00118$
00110$:
	C$fuzzy.h$1175$1_0$68 ==.
;	../../fuzzy.h:1175: (value - universe[index]) /
	push	ar7
	push	ar6
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
	C$fuzzy.h$1176$1_0$68 ==.
;	../../fuzzy.h:1176: (universe[index + 1u] - universe[index]);
	mov	a,_bp
	add	a,#0xf5
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
	pop	ar6
	pop	ar7
	mov	a,#0x01
	add	a, r6
	mov	r4,a
	clr	a
	addc	a, r7
	mov	r5,a
	mov	a,r4
	add	a,r4
	mov	r7,a
	mov	a,r5
	rlc	a
	mov	r6,a
	mov	a,r7
	add	a,r7
	mov	r7,a
	mov	a,r6
	rlc	a
	mov	r6,a
	mov	r0,_bp
	inc	r0
	mov	a,r7
	add	a, @r0
	mov	r2,a
	mov	a,r6
	inc	r0
	addc	a, @r0
	mov	r3,a
	inc	r0
	mov	ar5,@r0
	mov	dpl,r2
	mov	dph,r3
	mov	b,r5
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	push	ar7
	push	ar6
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
	mov	dpl, r2
	mov	dph, r3
	mov	b, r5
	mov	a, r4
	lcall	___fssub
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
	C$fuzzy.h$1179$1_0$68 ==.
;	../../fuzzy.h:1179: memberships[index] +
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
	lcall	___fsdiv
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
	pop	ar6
	pop	ar7
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,_bp
	add	a,#0x08
	mov	r1,a
	mov	a,@r1
	add	a, @r0
	mov	r3,a
	inc	r1
	mov	a,@r1
	inc	r0
	addc	a, @r0
	mov	r4,a
	inc	r0
	mov	ar5,@r0
	mov	dpl,r3
	mov	dph,r4
	mov	b,r5
	mov	a,_bp
	add	a,#0x0a
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
	C$fuzzy.h$1182$4_0$74 ==.
;	../../fuzzy.h:1182: memberships[index + 1u] -
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,r7
	add	a, @r0
	mov	r3,a
	mov	a,r6
	inc	r0
	addc	a, @r0
	mov	r4,a
	inc	r0
	mov	ar5,@r0
	mov	dpl,r3
	mov	dph,r4
	mov	b,r5
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r2,a
	C$fuzzy.h$1183$1_0$68 ==.
;	../../fuzzy.h:1183: memberships[index]
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
	mov	dpl, r3
	mov	dph, r4
	mov	b, r5
	mov	a, r2
	lcall	___fssub
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
	mov	r2, dpl
	mov	r3, dph
	mov	r4, b
	mov	r5, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	dpl, r2
	mov	dph, r3
	mov	b, r4
	mov	a, r5
	lcall	_fuzzy_clamp
	sjmp	00118$
00117$:
	C$fuzzy.h$1165$2_0$72 ==.
;	../../fuzzy.h:1165: for (index = 0u; index + 1u < count; index++) {
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	inc	@r0
	cjne	@r0,#0x00,00183$
	inc	r0
	inc	@r0
00183$:
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	mov	ar6,@r0
	inc	r0
	mov	ar7,@r0
	ljmp	00116$
00114$:
	C$fuzzy.h$1189$1_0$68 ==.
;	../../fuzzy.h:1189: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
00118$:
	C$fuzzy.h$1190$1_0$68 ==.
;	../../fuzzy.h:1190: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1190$1_0$68 ==.
	XG$fuzzy_interpolate_membership$0$0 ==.
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
	C$fuzzy.h$1234$1_0$77 ==.
;	../../fuzzy.h:1234: float fuzzy_function_array(
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
	C$fuzzy.h$1258$1_0$77 ==.
;	../../fuzzy.h:1258: if (parameters == NULL) {
	mov	a,_bp
	add	a,#0xf4
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00102$
	C$fuzzy.h$1259$2_0$78 ==.
;	../../fuzzy.h:1259: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00149$
00102$:
	C$fuzzy.h$1262$1_0$77 ==.
;	../../fuzzy.h:1262: switch (shape) {
	mov	a,r7
	add	a,#0xff - 0x0b
	jnc	00271$
	ljmp	00147$
00271$:
	mov	a,r7
	add	a,#(00272$-3-.)
	movc	a,@a+pc
	mov	dpl,a
	mov	a,r7
	add	a,#(00273$-3-.)
	movc	a,@a+pc
	mov	dph,a
	clr	a
	jmp	@a+dptr
00272$:
	.db	00103$
	.db	00106$
	.db	00121$
	.db	00146$
	.db	00146$
	.db	00146$
	.db	00146$
	.db	00146$
	.db	00146$
	.db	00146$
	.db	00146$
	.db	00146$
00273$:
	.db	00103$>>8
	.db	00106$>>8
	.db	00121$>>8
	.db	00146$>>8
	.db	00146$>>8
	.db	00146$>>8
	.db	00146$>>8
	.db	00146$>>8
	.db	00146$>>8
	.db	00146$>>8
	.db	00146$>>8
	.db	00146$>>8
	C$fuzzy.h$1263$2_0$79 ==.
;	../../fuzzy.h:1263: case FUZZY_SHAPE_RAMP:
00103$:
	C$fuzzy.h$1264$2_0$79 ==.
;	../../fuzzy.h:1264: if (parameter_count != 3u) {
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	cjne	@r0,#0x03,00274$
	inc	r0
	cjne	@r0,#0x00,00274$
	sjmp	00105$
00274$:
	C$fuzzy.h$1265$3_0$80 ==.
;	../../fuzzy.h:1265: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00149$
00105$:
	C$fuzzy.h$1268$2_0$79 ==.
;	../../fuzzy.h:1268: parameter_1 = parameters[0];
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
	C$fuzzy.h$1269$2_0$79 ==.
;	../../fuzzy.h:1269: parameter_2 = parameters[1];
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
	C$fuzzy.h$1270$2_0$79 ==.
;	../../fuzzy.h:1270: ramp_up = parameters[2] != 0.0f;
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
	cjne	a,#0x01,00275$
00275$:
	cpl	c
	mov	b0,c
	clr	a
	rlc	a
	mov	r7,a
	C$fuzzy.h$1273$2_0$79 ==.
;	../../fuzzy.h:1273: parameter_1,
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
	ljmp	00149$
	C$fuzzy.h$1280$2_0$79 ==.
;	../../fuzzy.h:1280: case FUZZY_SHAPE_TRIANGLE:
00106$:
	C$fuzzy.h$1281$2_0$79 ==.
;	../../fuzzy.h:1281: if (parameter_count != 3u) {
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	cjne	@r0,#0x03,00276$
	inc	r0
	cjne	@r0,#0x00,00276$
	sjmp	00108$
00276$:
	C$fuzzy.h$1282$3_0$81 ==.
;	../../fuzzy.h:1282: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00149$
00108$:
	C$fuzzy.h$1285$2_0$79 ==.
;	../../fuzzy.h:1285: parameter_1 = parameters[0];
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
	C$fuzzy.h$1286$2_0$79 ==.
;	../../fuzzy.h:1286: parameter_2 = parameters[1];
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
	C$fuzzy.h$1287$2_0$79 ==.
;	../../fuzzy.h:1287: parameter_3 = parameters[2];
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
	C$fuzzy.h$1290$1_0$77 ==.
;	../../fuzzy.h:1290: parameter_1 >= parameter_2 ||
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
	jc	00277$
	ljmp	00115$
00277$:
	C$fuzzy.h$1291$1_0$77 ==.
;	../../fuzzy.h:1291: parameter_2 >= parameter_3 ||
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
	C$fuzzy.h$1292$1_0$77 ==.
;	../../fuzzy.h:1292: value <= parameter_1 ||
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
	C$fuzzy.h$1294$1_0$77 ==.
;	../../fuzzy.h:1294: ) {
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
	C$fuzzy.h$1295$3_0$82 ==.
;	../../fuzzy.h:1295: result = LEVEL_LO;
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
	ljmp	00148$
00116$:
	C$fuzzy.h$1297$1_0$77 ==.
;	../../fuzzy.h:1297: else if (value == parameter_2) {
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
	C$fuzzy.h$1298$3_0$83 ==.
;	../../fuzzy.h:1298: result = LEVEL_HI;
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
	ljmp	00148$
00113$:
	C$fuzzy.h$1300$1_0$77 ==.
;	../../fuzzy.h:1300: else if (value < parameter_2) {
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
	jnz	00282$
	ljmp	00110$
00282$:
	C$fuzzy.h$1301$1_0$77 ==.
;	../../fuzzy.h:1301: result = (value - parameter_1) /
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
	C$fuzzy.h$1302$1_0$77 ==.
;	../../fuzzy.h:1302: (parameter_2 - parameter_1);
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
	ljmp	00148$
00110$:
	C$fuzzy.h$1305$1_0$77 ==.
;	../../fuzzy.h:1305: result = (parameter_3 - value) /
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
	C$fuzzy.h$1306$1_0$77 ==.
;	../../fuzzy.h:1306: (parameter_3 - parameter_2);
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
	C$fuzzy.h$1308$1_0$77 ==.
;	../../fuzzy.h:1308: break;
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
	ljmp	00148$
	C$fuzzy.h$1310$2_0$79 ==.
;	../../fuzzy.h:1310: case FUZZY_SHAPE_TRAPEZOID:
00121$:
	C$fuzzy.h$1311$2_0$79 ==.
;	../../fuzzy.h:1311: if (parameter_count != 4u) {
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	cjne	@r0,#0x04,00283$
	inc	r0
	cjne	@r0,#0x00,00283$
	sjmp	00123$
00283$:
	C$fuzzy.h$1312$3_0$86 ==.
;	../../fuzzy.h:1312: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00149$
00123$:
	C$fuzzy.h$1315$2_0$79 ==.
;	../../fuzzy.h:1315: parameter_1 = parameters[0];
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
	C$fuzzy.h$1316$2_0$79 ==.
;	../../fuzzy.h:1316: parameter_2 = parameters[1];
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
	C$fuzzy.h$1317$2_0$79 ==.
;	../../fuzzy.h:1317: parameter_3 = parameters[2];
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
	C$fuzzy.h$1318$2_0$79 ==.
;	../../fuzzy.h:1318: parameter_4 = parameters[3];
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
	C$fuzzy.h$1321$1_0$77 ==.
;	../../fuzzy.h:1321: parameter_1 >= parameter_2 ||
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
	jc	00284$
	ljmp	00131$
00284$:
	C$fuzzy.h$1322$1_0$77 ==.
;	../../fuzzy.h:1322: parameter_2 > parameter_3 ||
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
	jz	00285$
	ljmp	00131$
00285$:
	C$fuzzy.h$1323$1_0$77 ==.
;	../../fuzzy.h:1323: parameter_3 >= parameter_4 ||
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
	C$fuzzy.h$1324$1_0$77 ==.
;	../../fuzzy.h:1324: value <= parameter_1 ||
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
	C$fuzzy.h$1326$1_0$77 ==.
;	../../fuzzy.h:1326: ) {
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
	C$fuzzy.h$1327$3_0$87 ==.
;	../../fuzzy.h:1327: result = LEVEL_LO;
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
	ljmp	00148$
00132$:
	C$fuzzy.h$1330$1_0$77 ==.
;	../../fuzzy.h:1330: value >= parameter_2 &&
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
	C$fuzzy.h$1332$1_0$77 ==.
;	../../fuzzy.h:1332: ) {
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
	C$fuzzy.h$1333$3_0$88 ==.
;	../../fuzzy.h:1333: result = LEVEL_HI;
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
	ljmp	00148$
00128$:
	C$fuzzy.h$1335$1_0$77 ==.
;	../../fuzzy.h:1335: else if (value < parameter_2) {
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
	jnz	00291$
	ljmp	00125$
00291$:
	C$fuzzy.h$1336$1_0$77 ==.
;	../../fuzzy.h:1336: result = (value - parameter_1) /
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
	C$fuzzy.h$1337$1_0$77 ==.
;	../../fuzzy.h:1337: (parameter_2 - parameter_1);
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
	ljmp	00148$
00125$:
	C$fuzzy.h$1340$1_0$77 ==.
;	../../fuzzy.h:1340: result = (parameter_4 - value) /
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
	C$fuzzy.h$1341$1_0$77 ==.
;	../../fuzzy.h:1341: (parameter_4 - parameter_3);
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
	C$fuzzy.h$1343$1_0$77 ==.
;	../../fuzzy.h:1343: break;
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
	C$fuzzy.h$1643$2_0$79 ==.
;	../../fuzzy.h:1643: case FUZZY_SHAPE_PSIGMOID:
	sjmp	00148$
00146$:
	C$fuzzy.h$1644$2_0$79 ==.
;	../../fuzzy.h:1644: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$1648$2_0$79 ==.
;	../../fuzzy.h:1648: default:
	sjmp	00149$
00147$:
	C$fuzzy.h$1649$2_0$79 ==.
;	../../fuzzy.h:1649: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$1650$1_0$77 ==.
;	../../fuzzy.h:1650: }
	sjmp	00149$
00148$:
	C$fuzzy.h$1652$1_0$77 ==.
;	../../fuzzy.h:1652: return fuzzy_apply_hedge(result, hedge);
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
00149$:
	C$fuzzy.h$1653$1_0$77 ==.
;	../../fuzzy.h:1653: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1653$1_0$77 ==.
	XG$fuzzy_function_array$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_create'
;------------------------------------------------------------
;rules         Allocated to registers r5 r6 r7 
;------------------------------------------------------------
	G$fuzzy_rules_create$0$0 ==.
	C$fuzzy.h$1655$1_0$92 ==.
;	../../fuzzy.h:1655: void fuzzy_rules_create(
;	-----------------------------------------
;	 function fuzzy_rules_create
;	-----------------------------------------
_fuzzy_rules_create:
	mov	r5, dpl
	mov	r6, dph
	mov	r7, b
	C$fuzzy.h$1659$1_0$92 ==.
;	../../fuzzy.h:1659: if (rules == NULL) {
	mov	a,r5
	orl	a,r6
	jnz	00102$
	C$fuzzy.h$1660$2_0$93 ==.
;	../../fuzzy.h:1660: return;
	sjmp	00103$
00102$:
	C$fuzzy.h$1663$1_0$92 ==.
;	../../fuzzy.h:1663: rules->count = 0;
	mov	a,#0x90
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
	C$fuzzy.h$1664$1_0$92 ==.
;	../../fuzzy.h:1664: }
	C$fuzzy.h$1664$1_0$92 ==.
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
	C$fuzzy.h$1667$1_0$95 ==.
;	../../fuzzy.h:1667: bool fuzzy_rules_add(
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
	C$fuzzy.h$1677$1_0$95 ==.
;	../../fuzzy.h:1677: rules == NULL ||
	mov	a,r2
	orl	a,r3
	jz	00101$
	C$fuzzy.h$1678$1_0$95 ==.
;	../../fuzzy.h:1678: output_function == NULL
	mov	a,_bp
	add	a,#0xf5
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00102$
00101$:
	C$fuzzy.h$1680$2_0$96 ==.
;	../../fuzzy.h:1680: return false;
	mov	dpl, #0x00
	ljmp	00106$
00102$:
	C$fuzzy.h$1683$1_0$95 ==.
;	../../fuzzy.h:1683: if (rules->count >= FUZZY_MAX_RULES) {
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
	C$fuzzy.h$1684$2_0$97 ==.
;	../../fuzzy.h:1684: return false;
	mov	dpl, #0x00
	ljmp	00106$
00105$:
	C$fuzzy.h$1690$1_0$95 ==.
;	../../fuzzy.h:1690: rules->rules[index].name =
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
	C$fuzzy.h$1693$1_0$95 ==.
;	../../fuzzy.h:1693: rules->rules[index].value =
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
	C$fuzzy.h$1694$1_0$95 ==.
;	../../fuzzy.h:1694: fuzzy_clamp(value);
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
	C$fuzzy.h$1696$1_0$95 ==.
;	../../fuzzy.h:1696: rules->rules[index].output_function =
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
	C$fuzzy.h$1699$1_0$95 ==.
;	../../fuzzy.h:1699: rules->count++;
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
	C$fuzzy.h$1701$1_0$95 ==.
;	../../fuzzy.h:1701: return true;
	mov	dpl, #0x01
00106$:
	C$fuzzy.h$1702$1_0$95 ==.
;	../../fuzzy.h:1702: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1702$1_0$95 ==.
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
	Fsugeno_demo$fuzzy_implication$0$0 ==.
	C$fuzzy.h$1735$1_0$99 ==.
;	../../fuzzy.h:1735: static float fuzzy_implication(
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
	C$fuzzy.h$1741$1_0$99 ==.
;	../../fuzzy.h:1741: activation = fuzzy_clamp(activation);
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
	C$fuzzy.h$1742$1_0$99 ==.
;	../../fuzzy.h:1742: membership = fuzzy_clamp(membership);
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
	C$fuzzy.h$1744$1_0$99 ==.
;	../../fuzzy.h:1744: switch (method) {
	cjne	r7,#0x00,00127$
	sjmp	00101$
00127$:
	cjne	r7,#0x01,00128$
	sjmp	00102$
00128$:
	ljmp	00103$
	C$fuzzy.h$1745$2_0$100 ==.
;	../../fuzzy.h:1745: case FUZZY_IMPLICATION_MIN:
00101$:
	C$fuzzy.h$1747$1_0$99 ==.
;	../../fuzzy.h:1747: ? activation
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
	C$fuzzy.h$1748$2_0$100 ==.
;	../../fuzzy.h:1748: : membership;
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
	C$fuzzy.h$1750$2_0$100 ==.
;	../../fuzzy.h:1750: case FUZZY_IMPLICATION_PRODUCT:
	sjmp	00105$
00102$:
	C$fuzzy.h$1751$1_0$99 ==.
;	../../fuzzy.h:1751: return activation * membership;
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
	C$fuzzy.h$1753$2_0$100 ==.
;	../../fuzzy.h:1753: default:
	sjmp	00105$
00103$:
	C$fuzzy.h$1754$2_0$100 ==.
;	../../fuzzy.h:1754: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$1755$1_0$99 ==.
;	../../fuzzy.h:1755: }
00105$:
	C$fuzzy.h$1756$1_0$99 ==.
;	../../fuzzy.h:1756: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1756$1_0$99 ==.
	XFsugeno_demo$fuzzy_implication$0$0 ==.
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
	Fsugeno_demo$fuzzy_aggregation$0$0 ==.
	C$fuzzy.h$1758$1_0$102 ==.
;	../../fuzzy.h:1758: static float fuzzy_aggregation(
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
	C$fuzzy.h$1764$1_0$102 ==.
;	../../fuzzy.h:1764: aggregated = fuzzy_clamp(aggregated);
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
	C$fuzzy.h$1765$1_0$102 ==.
;	../../fuzzy.h:1765: implied = fuzzy_clamp(implied);
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
	C$fuzzy.h$1767$1_0$102 ==.
;	../../fuzzy.h:1767: switch (method) {
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
	C$fuzzy.h$1768$2_0$103 ==.
;	../../fuzzy.h:1768: case FUZZY_AGGREGATION_MAX:
00101$:
	C$fuzzy.h$1770$1_0$102 ==.
;	../../fuzzy.h:1770: ? aggregated
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
	C$fuzzy.h$1771$2_0$103 ==.
;	../../fuzzy.h:1771: : implied;
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
	C$fuzzy.h$1773$2_0$103 ==.
;	../../fuzzy.h:1773: case FUZZY_AGGREGATION_ALGEBRAIC:
00102$:
	C$fuzzy.h$1775$1_0$102 ==.
;	../../fuzzy.h:1775: implied -
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
	C$fuzzy.h$1776$1_0$102 ==.
;	../../fuzzy.h:1776: aggregated * implied;
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
	C$fuzzy.h$1778$2_0$103 ==.
;	../../fuzzy.h:1778: case FUZZY_AGGREGATION_BOUNDED:
	sjmp	00106$
00103$:
	C$fuzzy.h$1782$1_0$102 ==.
;	../../fuzzy.h:1782: );
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
	C$fuzzy.h$1784$2_0$103 ==.
;	../../fuzzy.h:1784: default:
	sjmp	00106$
00104$:
	C$fuzzy.h$1785$2_0$103 ==.
;	../../fuzzy.h:1785: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$1786$1_0$102 ==.
;	../../fuzzy.h:1786: }
00106$:
	C$fuzzy.h$1787$1_0$102 ==.
;	../../fuzzy.h:1787: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1787$1_0$102 ==.
	XFsugeno_demo$fuzzy_aggregation$0$0 ==.
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
;rules         Allocated to stack - _bp +1 +3 
;weighted_sum  Allocated to stack - _bp +16 +4 
;height_sum    Allocated to stack - _bp +20 +4 
;maximum_height Allocated to stack - _bp +24 +4 
;maximum_position_sum Allocated to stack - _bp +28 +4 
;smallest_maximum Allocated to stack - _bp +32 +4 
;largest_maximum Allocated to stack - _bp +36 +4 
;value         Allocated to stack - _bp +40 +4 
;aggregated_height Allocated to stack - _bp +44 +4 
;output_membership Allocated to stack - _bp +48 +4 
;implied_height Allocated to registers r4 r5 r6 r7 
;maximum_count Allocated to stack - _bp +52 +2 
;index         Allocated to stack - _bp +54 +2 
;maximum_found Allocated to stack - _bp +56 +1 
;sloc0         Allocated to stack - _bp +4 +3 
;sloc1         Allocated to stack - _bp +7 +4 
;sloc2         Allocated to stack - _bp +11 +2 
;sloc3         Allocated to stack - _bp +13 +3 
;------------------------------------------------------------
	G$fuzzy_rules_defuzzify_method$0$0 ==.
	C$fuzzy.h$1804$1_0$105 ==.
;	../../fuzzy.h:1804: float fuzzy_rules_defuzzify_method(
;	-----------------------------------------
;	 function fuzzy_rules_defuzzify_method
;	-----------------------------------------
_fuzzy_rules_defuzzify_method:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	mov	a,sp
	add	a,#0x35
	mov	sp,a
	C$fuzzy.h$1814$2_0$105 ==.
;	../../fuzzy.h:1814: float weighted_sum = 0.0f;
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
	C$fuzzy.h$1815$2_0$105 ==.
;	../../fuzzy.h:1815: float height_sum = 0.0f;
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
	C$fuzzy.h$1816$2_0$105 ==.
;	../../fuzzy.h:1816: float maximum_height = LEVEL_LO;
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
	C$fuzzy.h$1817$2_0$105 ==.
;	../../fuzzy.h:1817: float maximum_position_sum = 0.0f;
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
	C$fuzzy.h$1818$2_0$105 ==.
;	../../fuzzy.h:1818: float smallest_maximum = lower;
	mov	a,_bp
	add	a,#0xfa
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
	C$fuzzy.h$1819$2_0$105 ==.
;	../../fuzzy.h:1819: float largest_maximum = lower;
	mov	a,_bp
	add	a,#0x20
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
	C$fuzzy.h$1824$2_0$105 ==.
;	../../fuzzy.h:1824: size_t maximum_count = 0u;
	mov	a,_bp
	add	a,#0x34
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$1826$2_0$105 ==.
;	../../fuzzy.h:1826: bool maximum_found = false;
	mov	a,_bp
	add	a,#0x38
	mov	r0,a
	mov	@r0,#0x00
	C$fuzzy.h$1829$1_0$105 ==.
;	../../fuzzy.h:1829: rules == NULL ||
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00217$
	ljmp	00101$
00217$:
	C$fuzzy.h$1830$1_0$105 ==.
;	../../fuzzy.h:1830: rules->count == 0u ||
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
	C$fuzzy.h$1831$1_0$105 ==.
;	../../fuzzy.h:1831: lower > upper ||
	mov	a,_bp
	add	a,#0x20
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
	C$fuzzy.h$1833$1_0$105 ==.
;	../../fuzzy.h:1833: ) {
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
	C$fuzzy.h$1834$2_0$106 ==.
;	../../fuzzy.h:1834: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00130$
00102$:
	C$fuzzy.h$1838$2_0$107 ==.
;	../../fuzzy.h:1838: value = lower;
	mov	a,_bp
	add	a,#0x20
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
00128$:
	C$fuzzy.h$1839$1_0$105 ==.
;	../../fuzzy.h:1839: value <= upper;
	mov	a,_bp
	add	a,#0x28
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
	jnc	00221$
	ljmp	00113$
00221$:
	C$fuzzy.h$1842$3_0$108 ==.
;	../../fuzzy.h:1842: aggregated_height = LEVEL_LO;
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
	C$fuzzy.h$1845$1_0$105 ==.
;	../../fuzzy.h:1845: index = 0u;
	mov	a,_bp
	add	a,#0x36
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
00125$:
	C$fuzzy.h$1846$1_0$105 ==.
;	../../fuzzy.h:1846: index < rules->count;
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
	mov	r7,a
	mov	a,_bp
	add	a,#0x36
	mov	r0,a
	clr	c
	mov	a,@r0
	subb	a,r4
	inc	r0
	mov	a,@r0
	subb	a,r7
	jc	00222$
	ljmp	00106$
00222$:
	C$fuzzy.h$1850$5_0$110 ==.
;	../../fuzzy.h:1850: rules->rules[index].output_function(value)
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	a,_bp
	add	a,#0x0b
	mov	r1,a
	mov	a,@r1
	add	a, @r0
	mov	r4,a
	inc	r1
	mov	a,@r1
	inc	r0
	addc	a, @r0
	mov	r5,a
	inc	r0
	mov	ar6,@r0
	mov	a,#0x07
	add	a, r4
	mov	r4,a
	clr	a
	addc	a, r5
	mov	r5,a
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	lcall	00223$
	sjmp	00224$
00223$:
	push	ar4
	push	ar5
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
	ret
00224$:
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
	C$fuzzy.h$1855$5_0$110 ==.
;	../../fuzzy.h:1855: rules->rules[index].value,
	mov	r0,_bp
	inc	r0
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
	C$fuzzy.h$1854$5_0$110 ==.
;	../../fuzzy.h:1854: implication_method,
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
	push	ar2
	push	ar3
	push	ar7
	push	ar6
	mov	a,_bp
	add	a,#0xf0
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
	C$fuzzy.h$1860$5_0$110 ==.
;	../../fuzzy.h:1860: aggregation_method,
	push	ar4
	push	ar5
	push	ar6
	push	ar7
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
	add	a,#0xef
	mov	r0,a
	mov	dpl, @r0
	lcall	_fuzzy_aggregation
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
	add	a,#0xf8
	mov	sp,a
	C$fuzzy.h$1847$1_0$105 ==.
;	../../fuzzy.h:1847: index++
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
	add	a,#0x36
	mov	r0,a
	inc	@r0
	cjne	@r0,#0x00,00225$
	inc	r0
	inc	@r0
00225$:
	ljmp	00125$
00106$:
	C$fuzzy.h$1867$3_0$108 ==.
;	../../fuzzy.h:1867: aggregated_height
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
	add	a,#0x2c
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	C$fuzzy.h$1872$1_0$105 ==.
;	../../fuzzy.h:1872: aggregated_height;
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
	add	a,#0x28
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
	C$fuzzy.h$1875$1_0$105 ==.
;	../../fuzzy.h:1875: aggregated_height;
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
	C$fuzzy.h$1878$1_0$105 ==.
;	../../fuzzy.h:1878: !maximum_found ||
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
	add	a,#0x38
	mov	r0,a
	mov	a,@r0
	jz	00109$
	C$fuzzy.h$1880$1_0$105 ==.
;	../../fuzzy.h:1880: ) {
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
	add	a,#0x18
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
	jz	00110$
00109$:
	C$fuzzy.h$1881$4_0$111 ==.
;	../../fuzzy.h:1881: maximum_height = aggregated_height;
	mov	a,_bp
	add	a,#0x2c
	mov	r0,a
	mov	a,_bp
	add	a,#0x18
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
	C$fuzzy.h$1882$4_0$111 ==.
;	../../fuzzy.h:1882: smallest_maximum = value;
	mov	a,_bp
	add	a,#0x28
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
	C$fuzzy.h$1883$4_0$111 ==.
;	../../fuzzy.h:1883: largest_maximum = value;
	mov	a,_bp
	add	a,#0x28
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
	C$fuzzy.h$1884$4_0$111 ==.
;	../../fuzzy.h:1884: maximum_position_sum = value;
	mov	a,_bp
	add	a,#0x28
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
	C$fuzzy.h$1885$4_0$111 ==.
;	../../fuzzy.h:1885: maximum_count = 1u;
	mov	a,_bp
	add	a,#0x34
	mov	r0,a
	mov	@r0,#0x01
	inc	r0
	mov	@r0,#0x00
	C$fuzzy.h$1886$4_0$111 ==.
;	../../fuzzy.h:1886: maximum_found = true;
	mov	a,_bp
	add	a,#0x38
	mov	r0,a
	mov	@r0,#0x01
	ljmp	00129$
00110$:
	C$fuzzy.h$1888$1_0$105 ==.
;	../../fuzzy.h:1888: else if (aggregated_height == maximum_height) {
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
	add	a,#0x2c
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
	jz	00129$
	C$fuzzy.h$1889$4_0$112 ==.
;	../../fuzzy.h:1889: largest_maximum = value;
	mov	a,_bp
	add	a,#0x28
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
	C$fuzzy.h$1890$1_0$105 ==.
;	../../fuzzy.h:1890: maximum_position_sum += value;
	mov	a,_bp
	add	a,#0x28
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
	C$fuzzy.h$1891$1_0$105 ==.
;	../../fuzzy.h:1891: maximum_count++;
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
	lcall	___fsadd
	xch	a,r0
	mov	a,_bp
	add	a,#0x1c
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
	add	a,#0x34
	mov	r0,a
	inc	@r0
	cjne	@r0,#0x00,00229$
	inc	r0
	inc	@r0
00229$:
00129$:
	C$fuzzy.h$1841$1_0$105 ==.
;	../../fuzzy.h:1841: ) {
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
	add	a,#0x28
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
	add	a,#0x28
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
	ljmp	00128$
00113$:
	C$fuzzy.h$1896$1_0$105 ==.
;	../../fuzzy.h:1896: !maximum_found ||
	mov	a,_bp
	add	a,#0x38
	mov	r0,a
	mov	a,@r0
	jz	00114$
	C$fuzzy.h$1897$1_0$105 ==.
;	../../fuzzy.h:1897: maximum_height <= LEVEL_LO ||
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
	jnc	00114$
	C$fuzzy.h$1899$1_0$105 ==.
;	../../fuzzy.h:1899: ) {
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
	jc	00115$
00114$:
	C$fuzzy.h$1900$2_0$113 ==.
;	../../fuzzy.h:1900: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00130$
00115$:
	C$fuzzy.h$1903$1_0$105 ==.
;	../../fuzzy.h:1903: switch (defuzz_method) {
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	mov	a,@r0
	add	a,#0xff - 0x03
	jnc	00233$
	ljmp	00122$
00233$:
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	mov	a,@r0
	add	a,@r0
	add	a,@r0
	mov	dptr,#00234$
	jmp	@a+dptr
00234$:
	ljmp	00118$
	ljmp	00119$
	ljmp	00120$
	ljmp	00121$
	C$fuzzy.h$1904$2_0$114 ==.
;	../../fuzzy.h:1904: case FUZZY_DEFUZZ_COG:
00118$:
	C$fuzzy.h$1906$1_0$105 ==.
;	../../fuzzy.h:1906: height_sum;
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
	add	a,#0x10
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
	C$fuzzy.h$1908$2_0$114 ==.
;	../../fuzzy.h:1908: case FUZZY_DEFUZZ_MOM:
	sjmp	00130$
00119$:
	C$fuzzy.h$1910$1_0$105 ==.
;	../../fuzzy.h:1910: (float)maximum_count;
	mov	a,_bp
	add	a,#0x34
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
	add	a,#0x1c
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
	C$fuzzy.h$1912$2_0$114 ==.
;	../../fuzzy.h:1912: case FUZZY_DEFUZZ_SOM:
	sjmp	00130$
00120$:
	C$fuzzy.h$1913$2_0$114 ==.
;	../../fuzzy.h:1913: return smallest_maximum;
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
	C$fuzzy.h$1915$2_0$114 ==.
;	../../fuzzy.h:1915: case FUZZY_DEFUZZ_LOM:
	sjmp	00130$
00121$:
	C$fuzzy.h$1916$2_0$114 ==.
;	../../fuzzy.h:1916: return largest_maximum;
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
	C$fuzzy.h$1918$2_0$114 ==.
;	../../fuzzy.h:1918: default:
	sjmp	00130$
00122$:
	C$fuzzy.h$1919$2_0$114 ==.
;	../../fuzzy.h:1919: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$1920$1_0$105 ==.
;	../../fuzzy.h:1920: }
00130$:
	C$fuzzy.h$1921$1_0$105 ==.
;	../../fuzzy.h:1921: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1921$1_0$105 ==.
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
	C$fuzzy.h$1923$1_0$116 ==.
;	../../fuzzy.h:1923: float fuzzy_rules_defuzzify(
;	-----------------------------------------
;	 function fuzzy_rules_defuzzify
;	-----------------------------------------
_fuzzy_rules_defuzzify:
	push	_bp
	mov	_bp,sp
	mov	r5, dpl
	mov	r6, dph
	mov	r7, b
	C$fuzzy.h$1932$1_0$116 ==.
;	../../fuzzy.h:1932: rules,
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
	C$fuzzy.h$1940$1_0$116 ==.
;	../../fuzzy.h:1940: }
	pop	_bp
	C$fuzzy.h$1940$1_0$116 ==.
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
	C$fuzzy.h$1945$1_0$118 ==.
;	../../fuzzy.h:1945: float fuzzy_rules_cog(
;	-----------------------------------------
;	 function fuzzy_rules_cog
;	-----------------------------------------
_fuzzy_rules_cog:
	push	_bp
	mov	_bp,sp
	mov	r5, dpl
	mov	r6, dph
	mov	r7, b
	C$fuzzy.h$1953$1_0$118 ==.
;	../../fuzzy.h:1953: rules,
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
	C$fuzzy.h$1959$1_0$118 ==.
;	../../fuzzy.h:1959: }
	pop	_bp
	C$fuzzy.h$1959$1_0$118 ==.
	XG$fuzzy_rules_cog$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_free'
;------------------------------------------------------------
;rules         Allocated to registers r5 r6 r7 
;------------------------------------------------------------
	G$fuzzy_rules_free$0$0 ==.
	C$fuzzy.h$1961$1_0$120 ==.
;	../../fuzzy.h:1961: void fuzzy_rules_free(fuzzy_rules_t *rules)
;	-----------------------------------------
;	 function fuzzy_rules_free
;	-----------------------------------------
_fuzzy_rules_free:
	mov	r5, dpl
	mov	r6, dph
	mov	r7, b
	C$fuzzy.h$1963$1_0$120 ==.
;	../../fuzzy.h:1963: if (rules == NULL) return;
	mov	a,r5
	orl	a,r6
	jnz	00102$
	sjmp	00103$
00102$:
	C$fuzzy.h$1970$1_0$120 ==.
;	../../fuzzy.h:1970: rules->count = 0;
	mov	a,#0x90
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
	C$fuzzy.h$1971$1_0$120 ==.
;	../../fuzzy.h:1971: }
	C$fuzzy.h$1971$1_0$120 ==.
	XG$fuzzy_rules_free$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'temperature_low'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$temperature_low$0$0 ==.
	C$sugeno_demo.c$62$1_0$122 ==.
;	../../sugeno_demo.c:62: static float temperature_low(float value)
;	-----------------------------------------
;	 function temperature_low
;	-----------------------------------------
_temperature_low:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$sugeno_demo.c$69$1_0$122 ==.
;	../../sugeno_demo.c:69: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$sugeno_demo.c$65$1_0$122 ==.
;	../../sugeno_demo.c:65: 15.0f,
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
	mov	b, #0x70
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
	C$sugeno_demo.c$71$1_0$122 ==.
;	../../sugeno_demo.c:71: }
	C$sugeno_demo.c$71$1_0$122 ==.
	XFsugeno_demo$temperature_low$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'temperature_high'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$temperature_high$0$0 ==.
	C$sugeno_demo.c$74$1_0$124 ==.
;	../../sugeno_demo.c:74: static float temperature_high(float value)
;	-----------------------------------------
;	 function temperature_high
;	-----------------------------------------
_temperature_high:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$sugeno_demo.c$81$1_0$124 ==.
;	../../sugeno_demo.c:81: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$sugeno_demo.c$77$1_0$124 ==.
;	../../sugeno_demo.c:77: 35.0f,
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
	mov	a,#0x96
	push	acc
	mov	a,#0x42
	push	acc
	mov	dptr,#0x0000
	mov	b, #0x0c
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
	C$sugeno_demo.c$83$1_0$124 ==.
;	../../sugeno_demo.c:83: }
	C$sugeno_demo.c$83$1_0$124 ==.
	XFsugeno_demo$temperature_high$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'load_low'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$load_low$0$0 ==.
	C$sugeno_demo.c$90$1_0$126 ==.
;	../../sugeno_demo.c:90: static float load_low(float value)
;	-----------------------------------------
;	 function load_low
;	-----------------------------------------
_load_low:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$sugeno_demo.c$97$1_0$126 ==.
;	../../sugeno_demo.c:97: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$sugeno_demo.c$93$1_0$126 ==.
;	../../sugeno_demo.c:93: 20.0f,
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
	C$sugeno_demo.c$99$1_0$126 ==.
;	../../sugeno_demo.c:99: }
	C$sugeno_demo.c$99$1_0$126 ==.
	XFsugeno_demo$load_low$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'load_high'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$load_high$0$0 ==.
	C$sugeno_demo.c$102$1_0$128 ==.
;	../../sugeno_demo.c:102: static float load_high(float value)
;	-----------------------------------------
;	 function load_high
;	-----------------------------------------
_load_high:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$sugeno_demo.c$109$1_0$128 ==.
;	../../sugeno_demo.c:109: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$sugeno_demo.c$105$1_0$128 ==.
;	../../sugeno_demo.c:105: 45.0f,
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
	mov	a,#0xaa
	push	acc
	mov	a,#0x42
	push	acc
	mov	dptr,#0x0000
	mov	b, #0x34
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
	C$sugeno_demo.c$111$1_0$128 ==.
;	../../sugeno_demo.c:111: }
	C$sugeno_demo.c$111$1_0$128 ==.
	XFsugeno_demo$load_high$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'vibration_low'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$vibration_low$0$0 ==.
	C$sugeno_demo.c$118$1_0$130 ==.
;	../../sugeno_demo.c:118: static float vibration_low(float value)
;	-----------------------------------------
;	 function vibration_low
;	-----------------------------------------
_vibration_low:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$sugeno_demo.c$125$1_0$130 ==.
;	../../sugeno_demo.c:125: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$sugeno_demo.c$121$1_0$130 ==.
;	../../sugeno_demo.c:121: 1.0f,
	push	ar3
	clr	a
	push	acc
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	push	acc
	push	acc
	mov	a,#0x80
	push	acc
	rr	a
	push	acc
	mov	dptr,#0x0000
	mov	b, #0x80
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
	C$sugeno_demo.c$127$1_0$130 ==.
;	../../sugeno_demo.c:127: }
	C$sugeno_demo.c$127$1_0$130 ==.
	XFsugeno_demo$vibration_low$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'vibration_high'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$vibration_high$0$0 ==.
	C$sugeno_demo.c$130$1_0$132 ==.
;	../../sugeno_demo.c:130: static float vibration_high(float value)
;	-----------------------------------------
;	 function vibration_high
;	-----------------------------------------
_vibration_high:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$sugeno_demo.c$137$1_0$132 ==.
;	../../sugeno_demo.c:137: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$sugeno_demo.c$133$1_0$132 ==.
;	../../sugeno_demo.c:133: 3.0f,
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
	push	acc
	mov	a,#0x41
	push	acc
	mov	dptr,#0x0000
	mov	b, #0x40
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
	C$sugeno_demo.c$139$1_0$132 ==.
;	../../sugeno_demo.c:139: }
	C$sugeno_demo.c$139$1_0$132 ==.
	XFsugeno_demo$vibration_high$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'response_idle'
;------------------------------------------------------------
;load          Allocated to stack - _bp -6 +4 
;vibration     Allocated to stack - _bp -10 +4 
;temperature   Allocated to registers r4 r5 r6 r7 
;sloc0         Allocated to stack - _bp +1 +4 
;------------------------------------------------------------
	Fsugeno_demo$response_idle$0$0 ==.
	C$sugeno_demo.c$146$1_0$134 ==.
;	../../sugeno_demo.c:146: static float response_idle(
;	-----------------------------------------
;	 function response_idle
;	-----------------------------------------
_response_idle:
	push	_bp
	mov	_bp,sp
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	mov	a,sp
	add	a,#0x04
	mov	sp,a
	C$sugeno_demo.c$154$1_0$134 ==.
;	../../sugeno_demo.c:154: 0.20f * temperature +
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#0xcccd
	mov	b, #0x4c
	mov	a, #0x3e
	lcall	___fsmul
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
	push	acc
	mov	a,#0x41
	push	acc
	C$sugeno_demo.c$155$1_0$134 ==.
;	../../sugeno_demo.c:155: 0.08f * load +
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
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
	mov	dptr,#0xd70a
	mov	b, #0xa3
	mov	a, #0x3d
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
	C$sugeno_demo.c$156$1_0$134 ==.
;	../../sugeno_demo.c:156: 0.50f * vibration;
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
	mov	dptr,#(0x00&0x00ff)
	clr	a
	mov	b,a
	mov	a,#0x3f
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
	C$sugeno_demo.c$157$1_0$134 ==.
;	../../sugeno_demo.c:157: }
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$157$1_0$134 ==.
	XFsugeno_demo$response_idle$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'response_economy'
;------------------------------------------------------------
;load          Allocated to stack - _bp -6 +4 
;vibration     Allocated to stack - _bp -10 +4 
;temperature   Allocated to registers r4 r5 r6 r7 
;sloc0         Allocated to stack - _bp +1 +4 
;------------------------------------------------------------
	Fsugeno_demo$response_economy$0$0 ==.
	C$sugeno_demo.c$160$1_0$136 ==.
;	../../sugeno_demo.c:160: static float response_economy(
;	-----------------------------------------
;	 function response_economy
;	-----------------------------------------
_response_economy:
	push	_bp
	mov	_bp,sp
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	mov	a,sp
	add	a,#0x04
	mov	sp,a
	C$sugeno_demo.c$168$1_0$136 ==.
;	../../sugeno_demo.c:168: 0.30f * temperature +
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#0x999a
	mov	b, #0x99
	mov	a, #0x3e
	lcall	___fsmul
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
	mov	a,#0x40
	push	acc
	inc	a
	push	acc
	C$sugeno_demo.c$169$1_0$136 ==.
;	../../sugeno_demo.c:169: 0.18f * load +
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
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
	mov	dptr,#0x51ec
	mov	b, #0x38
	mov	a, #0x3e
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
	C$sugeno_demo.c$170$1_0$136 ==.
;	../../sugeno_demo.c:170: 0.80f * vibration;
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
	mov	dptr,#0xcccd
	mov	b, #0x4c
	mov	a, #0x3f
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
	C$sugeno_demo.c$171$1_0$136 ==.
;	../../sugeno_demo.c:171: }
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$171$1_0$136 ==.
	XFsugeno_demo$response_economy$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'response_balanced'
;------------------------------------------------------------
;load          Allocated to stack - _bp -6 +4 
;vibration     Allocated to stack - _bp -10 +4 
;temperature   Allocated to registers r4 r5 r6 r7 
;sloc0         Allocated to stack - _bp +1 +4 
;------------------------------------------------------------
	Fsugeno_demo$response_balanced$0$0 ==.
	C$sugeno_demo.c$174$1_0$138 ==.
;	../../sugeno_demo.c:174: static float response_balanced(
;	-----------------------------------------
;	 function response_balanced
;	-----------------------------------------
_response_balanced:
	push	_bp
	mov	_bp,sp
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	mov	a,sp
	add	a,#0x04
	mov	sp,a
	C$sugeno_demo.c$182$1_0$138 ==.
;	../../sugeno_demo.c:182: 0.42f * temperature +
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#0x0a3d
	mov	b, #0xd7
	mov	a, #0x3e
	lcall	___fsmul
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
	mov	a,#0x70
	push	acc
	mov	a,#0x41
	push	acc
	C$sugeno_demo.c$183$1_0$138 ==.
;	../../sugeno_demo.c:183: 0.25f * load +
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
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
	mov	dptr,#0x0000
	mov	b, #0x80
	mov	a, #0x3e
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
	C$sugeno_demo.c$184$1_0$138 ==.
;	../../sugeno_demo.c:184: 1.20f * vibration;
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
	mov	dptr,#0x999a
	mov	b, #0x99
	mov	a, #0x3f
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
	C$sugeno_demo.c$185$1_0$138 ==.
;	../../sugeno_demo.c:185: }
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$185$1_0$138 ==.
	XFsugeno_demo$response_balanced$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'response_cooling'
;------------------------------------------------------------
;load          Allocated to stack - _bp -6 +4 
;vibration     Allocated to stack - _bp -10 +4 
;temperature   Allocated to registers r4 r5 r6 r7 
;sloc0         Allocated to stack - _bp +1 +4 
;------------------------------------------------------------
	Fsugeno_demo$response_cooling$0$0 ==.
	C$sugeno_demo.c$188$1_0$140 ==.
;	../../sugeno_demo.c:188: static float response_cooling(
;	-----------------------------------------
;	 function response_cooling
;	-----------------------------------------
_response_cooling:
	push	_bp
	mov	_bp,sp
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	mov	a,sp
	add	a,#0x04
	mov	sp,a
	C$sugeno_demo.c$196$1_0$140 ==.
;	../../sugeno_demo.c:196: 0.65f * temperature +
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#0x6666
	mov	b, #0x26
	mov	a, #0x3f
	lcall	___fsmul
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
	mov	a,#0xa0
	push	acc
	rl	a
	push	acc
	C$sugeno_demo.c$197$1_0$140 ==.
;	../../sugeno_demo.c:197: 0.12f * load +
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
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
	mov	dptr,#0xc28f
	mov	b, #0xf5
	mov	a, #0x3d
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
	C$sugeno_demo.c$198$1_0$140 ==.
;	../../sugeno_demo.c:198: 1.50f * vibration;
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
	mov	dptr,#0x0000
	mov	b, #0xc0
	mov	a, #0x3f
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
	C$sugeno_demo.c$199$1_0$140 ==.
;	../../sugeno_demo.c:199: }
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$199$1_0$140 ==.
	XFsugeno_demo$response_cooling$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'response_heavy_load'
;------------------------------------------------------------
;load          Allocated to stack - _bp -6 +4 
;vibration     Allocated to stack - _bp -10 +4 
;temperature   Allocated to registers r4 r5 r6 r7 
;sloc0         Allocated to stack - _bp +1 +4 
;------------------------------------------------------------
	Fsugeno_demo$response_heavy_load$0$0 ==.
	C$sugeno_demo.c$202$1_0$142 ==.
;	../../sugeno_demo.c:202: static float response_heavy_load(
;	-----------------------------------------
;	 function response_heavy_load
;	-----------------------------------------
_response_heavy_load:
	push	_bp
	mov	_bp,sp
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	mov	a,sp
	add	a,#0x04
	mov	sp,a
	C$sugeno_demo.c$210$1_0$142 ==.
;	../../sugeno_demo.c:210: 0.30f * temperature +
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#0x999a
	mov	b, #0x99
	mov	a, #0x3e
	lcall	___fsmul
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
	mov	a,#0x90
	push	acc
	mov	a,#0x41
	push	acc
	C$sugeno_demo.c$211$1_0$142 ==.
;	../../sugeno_demo.c:211: 0.55f * load +
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
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
	mov	dptr,#0xcccd
	mov	b, #0x0c
	mov	a, #0x3f
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
	C$sugeno_demo.c$212$1_0$142 ==.
;	../../sugeno_demo.c:212: 1.00f * vibration;
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
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
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
	C$sugeno_demo.c$213$1_0$142 ==.
;	../../sugeno_demo.c:213: }
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$213$1_0$142 ==.
	XFsugeno_demo$response_heavy_load$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'response_protection'
;------------------------------------------------------------
;load          Allocated to stack - _bp -6 +4 
;vibration     Allocated to stack - _bp -10 +4 
;temperature   Allocated to registers r4 r5 r6 r7 
;sloc0         Allocated to stack - _bp +1 +4 
;------------------------------------------------------------
	Fsugeno_demo$response_protection$0$0 ==.
	C$sugeno_demo.c$216$1_0$144 ==.
;	../../sugeno_demo.c:216: static float response_protection(
;	-----------------------------------------
;	 function response_protection
;	-----------------------------------------
_response_protection:
	push	_bp
	mov	_bp,sp
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	mov	a,sp
	add	a,#0x04
	mov	sp,a
	C$sugeno_demo.c$224$1_0$144 ==.
;	../../sugeno_demo.c:224: 0.45f * temperature +
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#0x6666
	mov	b, #0xe6
	mov	a, #0x3e
	lcall	___fsmul
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
	mov	a,#0x0c
	push	acc
	mov	a,#0x42
	push	acc
	C$sugeno_demo.c$225$1_0$144 ==.
;	../../sugeno_demo.c:225: 0.30f * load +
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
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
	mov	dptr,#0x999a
	mov	b, #0x99
	mov	a, #0x3e
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
	C$sugeno_demo.c$226$1_0$144 ==.
;	../../sugeno_demo.c:226: 2.50f * vibration;
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
	mov	dptr,#0x0000
	mov	b, #0x20
	mov	a, #0x40
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
	C$sugeno_demo.c$227$1_0$144 ==.
;	../../sugeno_demo.c:227: }
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$227$1_0$144 ==.
	XFsugeno_demo$response_protection$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'calculate_fan_speed'
;------------------------------------------------------------
;load          Allocated to stack - _bp -6 +4 
;vibration     Allocated to stack - _bp -10 +4 
;temperature   Allocated to stack - _bp +1 +4 
;temperature_low_value Allocated to registers r7 r6 r5 r4 
;temperature_high_value Allocated to stack - _bp +5 +4 
;load_low_value Allocated to stack - _bp +9 +4 
;load_high_value Allocated to stack - _bp +13 +4 
;vibration_low_value Allocated to stack - _bp +17 +4 
;vibration_high_value Allocated to stack - _bp +21 +4 
;rule1         Allocated to stack - _bp +25 +4 
;rule2         Allocated to stack - _bp +29 +4 
;rule3         Allocated to stack - _bp +33 +4 
;rule4         Allocated to stack - _bp +37 +4 
;rule5         Allocated to stack - _bp +41 +4 
;rule6         Allocated to stack - _bp +45 +4 
;rule6_thermal Allocated to stack - _bp +49 +4 
;rule6_mechanical Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$calculate_fan_speed$0$0 ==.
	C$sugeno_demo.c$254$1_0$146 ==.
;	../../sugeno_demo.c:254: static float calculate_fan_speed(
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
	add	a,#0x30
	mov	sp,a
	C$sugeno_demo.c$281$1_0$146 ==.
;	../../sugeno_demo.c:281: temperature
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
	mov	r7, dpl
	mov	r6, dph
	mov	r5, b
	mov	r4, a
	C$sugeno_demo.c$286$1_0$146 ==.
;	../../sugeno_demo.c:286: temperature
	mov	r0,_bp
	inc	r0
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	push	ar7
	push	ar6
	push	ar5
	push	ar4
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
	C$sugeno_demo.c$291$1_0$146 ==.
;	../../sugeno_demo.c:291: load
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
	lcall	_load_low
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
	C$sugeno_demo.c$296$1_0$146 ==.
;	../../sugeno_demo.c:296: load
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
	lcall	_load_high
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
	C$sugeno_demo.c$301$1_0$146 ==.
;	../../sugeno_demo.c:301: vibration
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
	lcall	_vibration_low
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
	C$sugeno_demo.c$306$1_0$146 ==.
;	../../sugeno_demo.c:306: vibration
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
	lcall	_vibration_high
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
	C$sugeno_demo.c$310$1_0$146 ==.
;	../../sugeno_demo.c:310: fuzzy_and_method(
	lcall	_fuzzy_values_initialize
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	(_fuzzy_values_buffer + 0),r7
	mov	(_fuzzy_values_buffer + 1),r6
	mov	(_fuzzy_values_buffer + 2),r5
	mov	(_fuzzy_values_buffer + 3),r4
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	mov	((_fuzzy_values_buffer + 0x0004) + 0),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0004) + 1),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0004) + 2),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0004) + 3),@r0
	mov	a,_bp
	add	a,#0x11
	mov	r0,a
	mov	((_fuzzy_values_buffer + 0x0008) + 0),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0008) + 1),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0008) + 2),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0008) + 3),@r0
	mov	a,#_fuzzy_values_buffer
	push	acc
	mov	a,#(_fuzzy_values_buffer >> 8)
	push	acc
	mov	a,#0x40
	push	acc
	mov	a,#0x03
	push	acc
	clr	a
	push	acc
	mov	dpl, #0x00
	lcall	_fuzzy_and_array
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
	add	a,#0xfb
	mov	sp,a
	C$sugeno_demo.c$318$1_0$146 ==.
;	../../sugeno_demo.c:318: fuzzy_and_method(
	lcall	_fuzzy_values_initialize
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
	lcall	_fuzzy_not
	mov	r2, dpl
	mov	r3, dph
	mov	r6, b
	mov	r7, a
	mov	(_fuzzy_values_buffer + 0),r2
	mov	(_fuzzy_values_buffer + 1),r3
	mov	(_fuzzy_values_buffer + 2),r6
	mov	(_fuzzy_values_buffer + 3),r7
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	((_fuzzy_values_buffer + 0x0004) + 0),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0004) + 1),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0004) + 2),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0004) + 3),@r0
	mov	a,#_fuzzy_values_buffer
	push	acc
	mov	a,#(_fuzzy_values_buffer >> 8)
	push	acc
	mov	a,#0x40
	push	acc
	mov	a,#0x02
	push	acc
	clr	a
	push	acc
	mov	dpl, #0x00
	lcall	_fuzzy_and_array
	xch	a,r0
	mov	a,_bp
	add	a,#0x1d
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
	C$sugeno_demo.c$327$1_0$146 ==.
;	../../sugeno_demo.c:327: fuzzy_or_method(
	lcall	_fuzzy_values_initialize
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	(_fuzzy_values_buffer + 0),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 1),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 2),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 3),@r0
	mov	a,_bp
	add	a,#0x15
	mov	r0,a
	mov	((_fuzzy_values_buffer + 0x0004) + 0),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0004) + 1),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0004) + 2),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0004) + 3),@r0
	mov	a,#_fuzzy_values_buffer
	push	acc
	mov	a,#(_fuzzy_values_buffer >> 8)
	push	acc
	mov	a,#0x40
	push	acc
	mov	a,#0x02
	push	acc
	clr	a
	push	acc
	mov	dpl, #0x00
	lcall	_fuzzy_or_array
	xch	a,r0
	mov	a,_bp
	add	a,#0x21
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
	C$sugeno_demo.c$334$1_0$146 ==.
;	../../sugeno_demo.c:334: fuzzy_and_method(
	lcall	_fuzzy_values_initialize
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	(_fuzzy_values_buffer + 0),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 1),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 2),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 3),@r0
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	((_fuzzy_values_buffer + 0x0004) + 0),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0004) + 1),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0004) + 2),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0004) + 3),@r0
	mov	a,#_fuzzy_values_buffer
	push	acc
	mov	a,#(_fuzzy_values_buffer >> 8)
	push	acc
	mov	a,#0x40
	push	acc
	mov	a,#0x02
	push	acc
	clr	a
	push	acc
	mov	dpl, #0x00
	lcall	_fuzzy_and_array
	xch	a,r0
	mov	a,_bp
	add	a,#0x25
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
	C$sugeno_demo.c$341$1_0$146 ==.
;	../../sugeno_demo.c:341: fuzzy_and_method(
	lcall	_fuzzy_values_initialize
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	(_fuzzy_values_buffer + 0),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 1),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 2),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 3),@r0
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
	lcall	_fuzzy_not
	mov	r2, dpl
	mov	r3, dph
	mov	r6, b
	mov	r7, a
	mov	((_fuzzy_values_buffer + 0x0004) + 0),r2
	mov	((_fuzzy_values_buffer + 0x0004) + 1),r3
	mov	((_fuzzy_values_buffer + 0x0004) + 2),r6
	mov	((_fuzzy_values_buffer + 0x0004) + 3),r7
	mov	a,#_fuzzy_values_buffer
	push	acc
	mov	a,#(_fuzzy_values_buffer >> 8)
	push	acc
	mov	a,#0x40
	push	acc
	mov	a,#0x02
	push	acc
	clr	a
	push	acc
	mov	dpl, #0x00
	lcall	_fuzzy_and_array
	xch	a,r0
	mov	a,_bp
	add	a,#0x29
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
	C$sugeno_demo.c$350$1_0$146 ==.
;	../../sugeno_demo.c:350: fuzzy_and_method(
	lcall	_fuzzy_values_initialize
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	(_fuzzy_values_buffer + 0),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 1),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 2),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 3),@r0
	mov	a,_bp
	add	a,#0x15
	mov	r0,a
	mov	((_fuzzy_values_buffer + 0x0004) + 0),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0004) + 1),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0004) + 2),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0004) + 3),@r0
	mov	a,#_fuzzy_values_buffer
	push	acc
	mov	a,#(_fuzzy_values_buffer >> 8)
	push	acc
	mov	a,#0x40
	push	acc
	mov	a,#0x02
	push	acc
	clr	a
	push	acc
	mov	dpl, #0x00
	lcall	_fuzzy_and_array
	xch	a,r0
	mov	a,_bp
	add	a,#0x31
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
	C$sugeno_demo.c$357$1_0$146 ==.
;	../../sugeno_demo.c:357: fuzzy_and_method(
	lcall	_fuzzy_values_initialize
	mov	a,_bp
	add	a,#0x0d
	mov	r0,a
	mov	(_fuzzy_values_buffer + 0),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 1),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 2),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 3),@r0
	mov	a,_bp
	add	a,#0x15
	mov	r0,a
	mov	((_fuzzy_values_buffer + 0x0004) + 0),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0004) + 1),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0004) + 2),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0004) + 3),@r0
	mov	a,#_fuzzy_values_buffer
	push	acc
	mov	a,#(_fuzzy_values_buffer >> 8)
	push	acc
	mov	a,#0x40
	push	acc
	mov	a,#0x02
	push	acc
	clr	a
	push	acc
	mov	dpl, #0x00
	lcall	_fuzzy_and_array
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
	C$sugeno_demo.c$364$1_0$146 ==.
;	../../sugeno_demo.c:364: fuzzy_or_method(
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	lcall	_fuzzy_values_initialize
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a,_bp
	add	a,#0x31
	mov	r0,a
	mov	(_fuzzy_values_buffer + 0),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 1),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 2),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 3),@r0
	mov	((_fuzzy_values_buffer + 0x0004) + 0),r4
	mov	((_fuzzy_values_buffer + 0x0004) + 1),r5
	mov	((_fuzzy_values_buffer + 0x0004) + 2),r6
	mov	((_fuzzy_values_buffer + 0x0004) + 3),r7
	mov	a,#_fuzzy_values_buffer
	push	acc
	mov	a,#(_fuzzy_values_buffer >> 8)
	push	acc
	mov	a,#0x40
	push	acc
	mov	a,#0x02
	push	acc
	clr	a
	push	acc
	mov	dpl, #0x00
	lcall	_fuzzy_or_array
	xch	a,r0
	mov	a,_bp
	add	a,#0x2d
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
	C$sugeno_demo.c$370$1_0$146 ==.
;	../../sugeno_demo.c:370: return fuzzy_sugeno_weighted_average(
	lcall	_fuzzy_values_initialize
	mov	a,_bp
	add	a,#0x19
	mov	r0,a
	mov	(_fuzzy_values_buffer + 0),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 1),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 2),@r0
	inc	r0
	mov	(_fuzzy_values_buffer + 3),@r0
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
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	_response_idle
	mov	r2, dpl
	mov	r3, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
	mov	((_fuzzy_values_buffer + 0x0004) + 0),r2
	mov	((_fuzzy_values_buffer + 0x0004) + 1),r3
	mov	((_fuzzy_values_buffer + 0x0004) + 2),r6
	mov	((_fuzzy_values_buffer + 0x0004) + 3),r7
	mov	a,_bp
	add	a,#0x1d
	mov	r0,a
	mov	((_fuzzy_values_buffer + 0x0008) + 0),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0008) + 1),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0008) + 2),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0008) + 3),@r0
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
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	_response_economy
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
	mov	((_fuzzy_values_buffer + 0x000c) + 0),r4
	mov	((_fuzzy_values_buffer + 0x000c) + 1),r5
	mov	((_fuzzy_values_buffer + 0x000c) + 2),r6
	mov	((_fuzzy_values_buffer + 0x000c) + 3),r7
	mov	a,_bp
	add	a,#0x21
	mov	r0,a
	mov	((_fuzzy_values_buffer + 0x0010) + 0),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0010) + 1),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0010) + 2),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0010) + 3),@r0
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
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	_response_balanced
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
	mov	((_fuzzy_values_buffer + 0x0014) + 0),r4
	mov	((_fuzzy_values_buffer + 0x0014) + 1),r5
	mov	((_fuzzy_values_buffer + 0x0014) + 2),r6
	mov	((_fuzzy_values_buffer + 0x0014) + 3),r7
	mov	a,_bp
	add	a,#0x25
	mov	r0,a
	mov	((_fuzzy_values_buffer + 0x0018) + 0),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0018) + 1),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0018) + 2),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0018) + 3),@r0
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
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	_response_cooling
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
	mov	((_fuzzy_values_buffer + 0x001c) + 0),r4
	mov	((_fuzzy_values_buffer + 0x001c) + 1),r5
	mov	((_fuzzy_values_buffer + 0x001c) + 2),r6
	mov	((_fuzzy_values_buffer + 0x001c) + 3),r7
	mov	a,_bp
	add	a,#0x29
	mov	r0,a
	mov	((_fuzzy_values_buffer + 0x0020) + 0),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0020) + 1),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0020) + 2),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0020) + 3),@r0
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
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	_response_heavy_load
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
	mov	((_fuzzy_values_buffer + 0x0024) + 0),r4
	mov	((_fuzzy_values_buffer + 0x0024) + 1),r5
	mov	((_fuzzy_values_buffer + 0x0024) + 2),r6
	mov	((_fuzzy_values_buffer + 0x0024) + 3),r7
	mov	a,_bp
	add	a,#0x2d
	mov	r0,a
	mov	((_fuzzy_values_buffer + 0x0028) + 0),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0028) + 1),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0028) + 2),@r0
	inc	r0
	mov	((_fuzzy_values_buffer + 0x0028) + 3),@r0
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
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	_response_protection
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
	mov	((_fuzzy_values_buffer + 0x002c) + 0),r4
	mov	((_fuzzy_values_buffer + 0x002c) + 1),r5
	mov	((_fuzzy_values_buffer + 0x002c) + 2),r6
	mov	((_fuzzy_values_buffer + 0x002c) + 3),r7
	mov	a,#_fuzzy_values_buffer
	push	acc
	mov	a,#(_fuzzy_values_buffer >> 8)
	push	acc
	mov	a,#0x40
	push	acc
	mov	dptr,#0x000c
	lcall	_fuzzy_sugeno_weighted_average_array
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	dec	sp
	dec	sp
	dec	sp
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	C$sugeno_demo.c$413$1_0$146 ==.
;	../../sugeno_demo.c:413: }
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$413$1_0$146 ==.
	XFsugeno_demo$calculate_fan_speed$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fan_speed_to_pwm'
;------------------------------------------------------------
;fan_speed     Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$fan_speed_to_pwm$0$0 ==.
	C$sugeno_demo.c$420$1_0$148 ==.
;	../../sugeno_demo.c:420: static unsigned char fan_speed_to_pwm(float fan_speed)
;	-----------------------------------------
;	 function fan_speed_to_pwm
;	-----------------------------------------
_fan_speed_to_pwm:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$sugeno_demo.c$422$1_0$148 ==.
;	../../sugeno_demo.c:422: if (fan_speed <= 0.0f) {
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
	C$sugeno_demo.c$423$2_0$149 ==.
;	../../sugeno_demo.c:423: return 0u;
	mov	dpl, #0x00
	sjmp	00105$
00102$:
	C$sugeno_demo.c$426$1_0$148 ==.
;	../../sugeno_demo.c:426: if (fan_speed >= 100.0f) {
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
	C$sugeno_demo.c$427$2_0$150 ==.
;	../../sugeno_demo.c:427: return 100u;
	mov	dpl, #0x64
	sjmp	00105$
00104$:
	C$sugeno_demo.c$432$1_0$148 ==.
;	../../sugeno_demo.c:432: );
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
	C$sugeno_demo.c$433$1_0$148 ==.
;	../../sugeno_demo.c:433: }
	C$sugeno_demo.c$433$1_0$148 ==.
	XFsugeno_demo$fan_speed_to_pwm$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;sloc0         Allocated to stack - _bp +1 +4 
;sloc1         Allocated to stack - _bp +5 +4 
;------------------------------------------------------------
	G$main$0$0 ==.
	C$sugeno_demo.c$456$1_0$152 ==.
;	../../sugeno_demo.c:456: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x08
	mov	sp,a
	C$sugeno_demo.c$459$1_0$152 ==.
;	../../sugeno_demo.c:459: 0x55u;
	mov	_P0,#0x55
	C$sugeno_demo.c$462$1_0$152 ==.
;	../../sugeno_demo.c:462: 0x00u;
	mov	_P1,#0x00
	C$sugeno_demo.c$465$1_0$152 ==.
;	../../sugeno_demo.c:465: test_temperature;
	mov	_P2,_test_temperature
	C$sugeno_demo.c$472$2_0$152 ==.
;	../../sugeno_demo.c:472: );
	mov	dpl, _test_vibration
	lcall	___uchar2fs
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
	C$sugeno_demo.c$470$2_0$152 ==.
;	../../sugeno_demo.c:470: (float)test_load,
	mov	dpl, _test_load
	lcall	___uchar2fs
	mov	r0,_bp
	inc	r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	C$sugeno_demo.c$469$2_0$152 ==.
;	../../sugeno_demo.c:469: (float)test_temperature,
	mov	dpl, _test_temperature
	lcall	___uchar2fs
	mov	r2, dpl
	mov	r3, dph
	mov	r6, b
	mov	r7, a
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
	mov	dpl, r2
	mov	dph, r3
	mov	b, r6
	mov	a, r7
	lcall	_calculate_fan_speed
	mov	_test_fan_speed,dpl
	mov	(_test_fan_speed + 1),dph
	mov	(_test_fan_speed + 2),b
	mov	(_test_fan_speed + 3),a
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
	C$sugeno_demo.c$476$1_0$152 ==.
;	../../sugeno_demo.c:476: test_fan_speed
	mov	dpl, _test_fan_speed
	mov	dph, (_test_fan_speed + 1)
	mov	b, (_test_fan_speed + 2)
	mov	a, (_test_fan_speed + 3)
	lcall	_fan_speed_to_pwm
	mov	_test_pwm,dpl
	C$sugeno_demo.c$480$1_0$152 ==.
;	../../sugeno_demo.c:480: test_pwm;
	mov	_P1,_test_pwm
	C$sugeno_demo.c$483$1_0$152 ==.
;	../../sugeno_demo.c:483: 0xAAu;
	mov	_P0,#0xaa
00103$:
	sjmp	00103$
	C$sugeno_demo.c$488$2_0$152 ==.
;	../../sugeno_demo.c:488: }
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$488$2_0$152 ==.
	XG$main$0$0 ==.
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area CONST   (CODE)
Fsugeno_demo$hedges$0_0$0 == .
_hedges:
	.db #0x01	; 1
	.db #0x02	; 2
	.db #0x03	; 3
	.area CSEG    (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
