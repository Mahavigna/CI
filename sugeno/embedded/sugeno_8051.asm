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
	C$sugeno_demo.c$25$2_0$136 ==.
;	../../sugeno_demo.c:25: volatile unsigned char test_temperature = 42u;
	mov	_test_temperature,#0x2a
	C$sugeno_demo.c$26$2_0$136 ==.
;	../../sugeno_demo.c:26: volatile unsigned char test_load = 65u;
	mov	_test_load,#0x41
	C$sugeno_demo.c$27$2_0$136 ==.
;	../../sugeno_demo.c:27: volatile unsigned char test_vibration = 4u;
	mov	_test_vibration,#0x04
	C$sugeno_demo.c$29$2_0$136 ==.
;	../../sugeno_demo.c:29: volatile unsigned char test_pwm = 0u;
	mov	_test_pwm,#0x00
	C$sugeno_demo.c$30$2_0$136 ==.
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
;	../../fuzzy.h:111: fuzzy_values_buffer[index] =
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
	C$fuzzy.h$115$1_0$3 ==.
;	../../fuzzy.h:115: return fuzzy_values_buffer;
	mov	dptr,#_fuzzy_values_buffer
	mov	b, #0x40
	C$fuzzy.h$116$1_0$3 ==.
;	../../fuzzy.h:116: }
	C$fuzzy.h$116$1_0$3 ==.
	XFsugeno_demo$fuzzy_values_initialize$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_clamp'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$fuzzy_clamp$0$0 ==.
	C$fuzzy.h$674$1_0$20 ==.
;	../../fuzzy.h:674: static float fuzzy_clamp(float value)
;	-----------------------------------------
;	 function fuzzy_clamp
;	-----------------------------------------
_fuzzy_clamp:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$fuzzy.h$676$1_0$20 ==.
;	../../fuzzy.h:676: if (value < LEVEL_LO) {
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
	C$fuzzy.h$677$2_0$21 ==.
;	../../fuzzy.h:677: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00105$
00102$:
	C$fuzzy.h$680$1_0$20 ==.
;	../../fuzzy.h:680: if (value > LEVEL_HI) {
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
	C$fuzzy.h$681$2_0$22 ==.
;	../../fuzzy.h:681: return LEVEL_HI;
	mov	dptr,#0x0000
	mov	b, #0x80
	mov	a, #0x3f
	sjmp	00105$
00104$:
	C$fuzzy.h$684$1_0$20 ==.
;	../../fuzzy.h:684: return value;
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
00105$:
	C$fuzzy.h$685$1_0$20 ==.
;	../../fuzzy.h:685: }
	C$fuzzy.h$685$1_0$20 ==.
	XFsugeno_demo$fuzzy_clamp$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_not'
;------------------------------------------------------------
;membership    Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	G$fuzzy_not$0$0 ==.
	C$fuzzy.h$690$1_0$24 ==.
;	../../fuzzy.h:690: float fuzzy_not(
;	-----------------------------------------
;	 function fuzzy_not
;	-----------------------------------------
_fuzzy_not:
	C$fuzzy.h$696$1_0$24 ==.
;	../../fuzzy.h:696: membership
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
	C$fuzzy.h$698$1_0$24 ==.
;	../../fuzzy.h:698: }
	C$fuzzy.h$698$1_0$24 ==.
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
	C$fuzzy.h$708$1_0$26 ==.
;	../../fuzzy.h:708: static float fuzzy_apply_hedge(
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
	C$fuzzy.h$715$1_0$26 ==.
;	../../fuzzy.h:715: membership
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
	C$fuzzy.h$720$2_0$27 ==.
;	../../fuzzy.h:720: float result =
	mov	r2,#0x00
	mov	r3,#0x00
	mov	r6,#0x80
	mov	r7,#0x3f
	C$fuzzy.h$723$1_1$27 ==.
;	../../fuzzy.h:723: if (hedge == 0u) {
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	a,@r0
	jnz	00110$
	C$fuzzy.h$725$2_1$28 ==.
;	../../fuzzy.h:725: 1u;
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	@r0,#0x01
	C$fuzzy.h$728$1_1$26 ==.
;	../../fuzzy.h:728: while (hedge > 0u) {
00110$:
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	ar5,@r0
00103$:
	mov	a,r5
	jz	00105$
	C$fuzzy.h$730$1_1$26 ==.
;	../../fuzzy.h:730: membership;
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
	C$fuzzy.h$732$1_1$26 ==.
;	../../fuzzy.h:732: hedge--;
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
	C$fuzzy.h$736$1_1$27 ==.
;	../../fuzzy.h:736: result
	mov	dpl, r2
	mov	dph, r3
	mov	b, r6
	mov	a, r7
	lcall	_fuzzy_clamp
	C$fuzzy.h$752$1_1$26 ==.
;	../../fuzzy.h:752: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$752$1_1$26 ==.
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
	C$fuzzy.h$766$1_1$31 ==.
;	../../fuzzy.h:766: float fuzzy_and_array(
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
	C$fuzzy.h$777$1_0$31 ==.
;	../../fuzzy.h:777: args == NULL ||
	mov	a,_bp
	add	a,#0xf9
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$778$1_0$31 ==.
;	../../fuzzy.h:778: count == 0u
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00102$
00101$:
	C$fuzzy.h$780$2_0$32 ==.
;	../../fuzzy.h:780: return LEVEL_HI;
	mov	dptr,#0x0000
	mov	b, #0x80
	mov	a, #0x3f
	ljmp	00121$
00102$:
	C$fuzzy.h$784$1_0$31 ==.
;	../../fuzzy.h:784: method != FUZZY_LOGIC_STANDARD &&
	mov	a,r5
	jz	00105$
	C$fuzzy.h$785$1_0$31 ==.
;	../../fuzzy.h:785: method != FUZZY_LOGIC_ALGEBRAIC &&
	cjne	r5,#0x01,00192$
	sjmp	00105$
00192$:
	C$fuzzy.h$787$1_0$31 ==.
;	../../fuzzy.h:787: ) {
	cjne	r5,#0x02,00193$
	sjmp	00105$
00193$:
	C$fuzzy.h$788$2_0$33 ==.
;	../../fuzzy.h:788: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00121$
00105$:
	C$fuzzy.h$793$1_0$31 ==.
;	../../fuzzy.h:793: args[0]
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
	C$fuzzy.h$797$3_0$35 ==.
;	../../fuzzy.h:797: index = 1u;
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
	C$fuzzy.h$798$2_0$34 ==.
;	../../fuzzy.h:798: index < count;
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
	C$fuzzy.h$803$1_0$31 ==.
;	../../fuzzy.h:803: args[index]
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
	C$fuzzy.h$806$1_0$31 ==.
;	../../fuzzy.h:806: switch (method) {
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
	C$fuzzy.h$807$4_0$36 ==.
;	../../fuzzy.h:807: case FUZZY_LOGIC_STANDARD:
00108$:
	C$fuzzy.h$808$1_0$31 ==.
;	../../fuzzy.h:808: if (next < result) {
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
	C$fuzzy.h$809$5_0$37 ==.
;	../../fuzzy.h:809: result = next;
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
	C$fuzzy.h$811$4_0$36 ==.
;	../../fuzzy.h:811: break;
	ljmp	00120$
	C$fuzzy.h$813$4_0$36 ==.
;	../../fuzzy.h:813: case FUZZY_LOGIC_ALGEBRAIC:
00111$:
	C$fuzzy.h$815$1_0$31 ==.
;	../../fuzzy.h:815: next;
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
	C$fuzzy.h$816$1_0$31 ==.
;	../../fuzzy.h:816: break;
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
	C$fuzzy.h$818$4_0$36 ==.
;	../../fuzzy.h:818: case FUZZY_LOGIC_BOUNDED:
00112$:
	C$fuzzy.h$821$1_0$31 ==.
;	../../fuzzy.h:821: next -
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
	C$fuzzy.h$824$1_0$31 ==.
;	../../fuzzy.h:824: if (result < LEVEL_LO) {
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
	C$fuzzy.h$825$5_0$38 ==.
;	../../fuzzy.h:825: result = LEVEL_LO;
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
	C$fuzzy.h$827$4_0$36 ==.
;	../../fuzzy.h:827: break;
	C$fuzzy.h$829$4_0$36 ==.
;	../../fuzzy.h:829: default:
	sjmp	00120$
00115$:
	C$fuzzy.h$830$4_0$36 ==.
;	../../fuzzy.h:830: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$831$3_0$35 ==.
;	../../fuzzy.h:831: }
	sjmp	00121$
00120$:
	C$fuzzy.h$799$2_0$34 ==.
;	../../fuzzy.h:799: index++
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
	C$fuzzy.h$835$1_0$31 ==.
;	../../fuzzy.h:835: result
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
	C$fuzzy.h$837$1_0$31 ==.
;	../../fuzzy.h:837: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$837$1_0$31 ==.
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
	C$fuzzy.h$852$1_0$40 ==.
;	../../fuzzy.h:852: float fuzzy_or_array(
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
	C$fuzzy.h$863$1_0$40 ==.
;	../../fuzzy.h:863: args == NULL ||
	mov	a,_bp
	add	a,#0xf9
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$864$1_0$40 ==.
;	../../fuzzy.h:864: count == 0u
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00102$
00101$:
	C$fuzzy.h$866$2_0$41 ==.
;	../../fuzzy.h:866: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00121$
00102$:
	C$fuzzy.h$870$1_0$40 ==.
;	../../fuzzy.h:870: method != FUZZY_LOGIC_STANDARD &&
	mov	a,r5
	jz	00105$
	C$fuzzy.h$871$1_0$40 ==.
;	../../fuzzy.h:871: method != FUZZY_LOGIC_ALGEBRAIC &&
	cjne	r5,#0x01,00192$
	sjmp	00105$
00192$:
	C$fuzzy.h$873$1_0$40 ==.
;	../../fuzzy.h:873: ) {
	cjne	r5,#0x02,00193$
	sjmp	00105$
00193$:
	C$fuzzy.h$874$2_0$42 ==.
;	../../fuzzy.h:874: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00121$
00105$:
	C$fuzzy.h$879$1_0$40 ==.
;	../../fuzzy.h:879: args[0]
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
	C$fuzzy.h$883$3_0$44 ==.
;	../../fuzzy.h:883: index = 1u;
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
	C$fuzzy.h$884$2_0$43 ==.
;	../../fuzzy.h:884: index < count;
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
	C$fuzzy.h$889$1_0$40 ==.
;	../../fuzzy.h:889: args[index]
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
	C$fuzzy.h$892$1_0$40 ==.
;	../../fuzzy.h:892: switch (method) {
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
	C$fuzzy.h$893$4_0$45 ==.
;	../../fuzzy.h:893: case FUZZY_LOGIC_STANDARD:
00108$:
	C$fuzzy.h$894$1_0$40 ==.
;	../../fuzzy.h:894: if (next > result) {
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
	C$fuzzy.h$895$5_0$46 ==.
;	../../fuzzy.h:895: result = next;
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
	C$fuzzy.h$897$4_0$45 ==.
;	../../fuzzy.h:897: break;
	ljmp	00120$
	C$fuzzy.h$899$4_0$45 ==.
;	../../fuzzy.h:899: case FUZZY_LOGIC_ALGEBRAIC:
00111$:
	C$fuzzy.h$902$1_0$40 ==.
;	../../fuzzy.h:902: next -
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
	C$fuzzy.h$903$1_0$40 ==.
;	../../fuzzy.h:903: result * next;
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
	C$fuzzy.h$904$1_0$40 ==.
;	../../fuzzy.h:904: break;
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
	C$fuzzy.h$906$4_0$45 ==.
;	../../fuzzy.h:906: case FUZZY_LOGIC_BOUNDED:
	sjmp	00120$
00112$:
	C$fuzzy.h$908$1_0$40 ==.
;	../../fuzzy.h:908: next;
	push	ar2
	push	ar4
	push	ar5
	push	ar6
	push	ar3
	C$fuzzy.h$910$1_0$40 ==.
;	../../fuzzy.h:910: if (result > LEVEL_HI) {
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
	C$fuzzy.h$911$5_0$47 ==.
;	../../fuzzy.h:911: result = LEVEL_HI;
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
	C$fuzzy.h$913$4_0$45 ==.
;	../../fuzzy.h:913: break;
	C$fuzzy.h$915$4_0$45 ==.
;	../../fuzzy.h:915: default:
	sjmp	00120$
00115$:
	C$fuzzy.h$916$4_0$45 ==.
;	../../fuzzy.h:916: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$917$3_0$44 ==.
;	../../fuzzy.h:917: }
	sjmp	00121$
00120$:
	C$fuzzy.h$885$2_0$43 ==.
;	../../fuzzy.h:885: index++
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
	C$fuzzy.h$921$1_0$40 ==.
;	../../fuzzy.h:921: result
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
	C$fuzzy.h$923$1_0$40 ==.
;	../../fuzzy.h:923: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$923$1_0$40 ==.
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
	C$fuzzy.h$934$1_0$49 ==.
;	../../fuzzy.h:934: float fuzzy_sugeno_weighted_average_array(
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
	C$fuzzy.h$947$1_0$49 ==.
;	../../fuzzy.h:947: values == NULL ||
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$948$1_0$49 ==.
;	../../fuzzy.h:948: value_count == 0u ||
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$949$1_0$49 ==.
;	../../fuzzy.h:949: value_count % 2u != 0u
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	jnb	acc.0,00102$
00101$:
	C$fuzzy.h$951$2_0$50 ==.
;	../../fuzzy.h:951: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00111$
00102$:
	C$fuzzy.h$955$1_0$49 ==.
;	../../fuzzy.h:955: 0.0f;
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
	C$fuzzy.h$958$1_0$49 ==.
;	../../fuzzy.h:958: 0.0f;
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
	C$fuzzy.h$961$1_0$49 ==.
;	../../fuzzy.h:961: index = 0u;
	mov	r6,a
	mov	r7,a
00109$:
	C$fuzzy.h$962$2_0$51 ==.
;	../../fuzzy.h:962: index < value_count;
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
	C$fuzzy.h$967$3_0$52 ==.
;	../../fuzzy.h:967: values[index]
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
	C$fuzzy.h$971$3_0$52 ==.
;	../../fuzzy.h:971: values[index + 1u];
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
	C$fuzzy.h$976$1_0$49 ==.
;	../../fuzzy.h:976: consequent;
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
	C$fuzzy.h$979$1_0$49 ==.
;	../../fuzzy.h:979: firing_strength;
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
	C$fuzzy.h$964$1_0$49 ==.
;	../../fuzzy.h:964: ) {
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
	C$fuzzy.h$982$1_0$49 ==.
;	../../fuzzy.h:982: if (firing_sum <= LEVEL_LO) {
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
	C$fuzzy.h$983$2_0$53 ==.
;	../../fuzzy.h:983: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00111$
00107$:
	C$fuzzy.h$987$1_0$49 ==.
;	../../fuzzy.h:987: firing_sum;
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
	C$fuzzy.h$988$1_0$49 ==.
;	../../fuzzy.h:988: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$988$1_0$49 ==.
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
	C$fuzzy.h$998$1_0$55 ==.
;	../../fuzzy.h:998: float fuzzy_sugeno_weighted_sum_array(
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
	C$fuzzy.h$1010$1_0$55 ==.
;	../../fuzzy.h:1010: values == NULL ||
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$1011$1_0$55 ==.
;	../../fuzzy.h:1011: value_count == 0u ||
	mov	a,r6
	orl	a,r7
	jz	00101$
	C$fuzzy.h$1012$1_0$55 ==.
;	../../fuzzy.h:1012: value_count % 2u != 0u
	mov	a,r6
	jnb	acc.0,00102$
00101$:
	C$fuzzy.h$1014$2_0$56 ==.
;	../../fuzzy.h:1014: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00109$
00102$:
	C$fuzzy.h$1018$1_0$55 ==.
;	../../fuzzy.h:1018: 0.0f;
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
	C$fuzzy.h$1021$1_0$55 ==.
;	../../fuzzy.h:1021: index = 0u;
	mov	r4,a
	mov	r5,a
00107$:
	C$fuzzy.h$1022$2_0$57 ==.
;	../../fuzzy.h:1022: index < value_count;
	clr	c
	mov	a,r4
	subb	a,r6
	mov	a,r5
	subb	a,r7
	jc	00139$
	ljmp	00105$
00139$:
	C$fuzzy.h$1027$1_0$55 ==.
;	../../fuzzy.h:1027: values[index]
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
	C$fuzzy.h$1031$3_0$58 ==.
;	../../fuzzy.h:1031: values[index + 1u];
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
	C$fuzzy.h$1036$1_0$55 ==.
;	../../fuzzy.h:1036: consequent;
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
	C$fuzzy.h$1024$1_0$55 ==.
;	../../fuzzy.h:1024: ) {
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
	C$fuzzy.h$1039$1_0$55 ==.
;	../../fuzzy.h:1039: return weighted_sum;
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
	C$fuzzy.h$1040$1_0$55 ==.
;	../../fuzzy.h:1040: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1040$1_0$55 ==.
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
	C$fuzzy.h$1046$1_0$60 ==.
;	../../fuzzy.h:1046: float fuzzy_ramp(
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
	C$fuzzy.h$1057$1_0$60 ==.
;	../../fuzzy.h:1057: if (lower_boundary >= upper_boundary) {
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
	C$fuzzy.h$1058$2_0$61 ==.
;	../../fuzzy.h:1058: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00109$
00102$:
	C$fuzzy.h$1061$1_0$60 ==.
;	../../fuzzy.h:1061: if (value <= lower_boundary) {
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
	C$fuzzy.h$1063$2_0$62 ==.
;	../../fuzzy.h:1063: ramp_up
	mov	a,_bp
	add	a,#0xf5
	mov	r0,a
	mov	a,@r0
	jz	00111$
	C$fuzzy.h$1064$2_0$62 ==.
;	../../fuzzy.h:1064: ? LEVEL_LO
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
	C$fuzzy.h$1065$2_0$62 ==.
;	../../fuzzy.h:1065: : LEVEL_HI;
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
	C$fuzzy.h$1067$1_0$60 ==.
;	../../fuzzy.h:1067: else if (value >= upper_boundary) {
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
	C$fuzzy.h$1069$2_0$63 ==.
;	../../fuzzy.h:1069: ramp_up
	mov	a,_bp
	add	a,#0xf5
	mov	r0,a
	mov	a,@r0
	jz	00113$
	C$fuzzy.h$1070$2_0$63 ==.
;	../../fuzzy.h:1070: ? LEVEL_HI
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
	C$fuzzy.h$1071$2_0$63 ==.
;	../../fuzzy.h:1071: : LEVEL_LO;
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
	C$fuzzy.h$1075$1_0$60 ==.
;	../../fuzzy.h:1075: (value - lower_boundary) /
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	C$fuzzy.h$1076$1_0$60 ==.
;	../../fuzzy.h:1076: (upper_boundary - lower_boundary);
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
	C$fuzzy.h$1079$1_0$60 ==.
;	../../fuzzy.h:1079: ramp_up
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
	C$fuzzy.h$1080$2_0$64 ==.
;	../../fuzzy.h:1080: ? normalized
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
	C$fuzzy.h$1081$1_0$60 ==.
;	../../fuzzy.h:1081: : LEVEL_HI - normalized;
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
	C$fuzzy.h$1085$1_0$60 ==.
;	../../fuzzy.h:1085: result,
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
	C$fuzzy.h$1088$1_0$60 ==.
;	../../fuzzy.h:1088: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1088$1_0$60 ==.
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
	C$fuzzy.h$1128$1_0$66 ==.
;	../../fuzzy.h:1128: float fuzzy_function_array(
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
	C$fuzzy.h$1150$1_0$66 ==.
;	../../fuzzy.h:1150: if (parameters == NULL) {
	mov	a,_bp
	add	a,#0xf4
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00102$
	C$fuzzy.h$1151$2_0$67 ==.
;	../../fuzzy.h:1151: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00145$
00102$:
	C$fuzzy.h$1154$1_0$66 ==.
;	../../fuzzy.h:1154: switch (shape) {
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
	C$fuzzy.h$1155$2_0$68 ==.
;	../../fuzzy.h:1155: case FUZZY_SHAPE_RAMP:
00103$:
	C$fuzzy.h$1156$2_0$68 ==.
;	../../fuzzy.h:1156: if (parameter_count != 3u) {
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	cjne	@r0,#0x03,00270$
	inc	r0
	cjne	@r0,#0x00,00270$
	sjmp	00105$
00270$:
	C$fuzzy.h$1157$3_0$69 ==.
;	../../fuzzy.h:1157: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00145$
00105$:
	C$fuzzy.h$1160$2_0$68 ==.
;	../../fuzzy.h:1160: parameter_1 = parameters[0];
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
	C$fuzzy.h$1161$2_0$68 ==.
;	../../fuzzy.h:1161: parameter_2 = parameters[1];
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
	C$fuzzy.h$1162$2_0$68 ==.
;	../../fuzzy.h:1162: ramp_up = parameters[2] != 0.0f;
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
	C$fuzzy.h$1165$2_0$68 ==.
;	../../fuzzy.h:1165: parameter_1,
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
	C$fuzzy.h$1172$2_0$68 ==.
;	../../fuzzy.h:1172: case FUZZY_SHAPE_TRIANGLE:
00106$:
	C$fuzzy.h$1173$2_0$68 ==.
;	../../fuzzy.h:1173: if (parameter_count != 3u) {
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	cjne	@r0,#0x03,00272$
	inc	r0
	cjne	@r0,#0x00,00272$
	sjmp	00108$
00272$:
	C$fuzzy.h$1174$3_0$70 ==.
;	../../fuzzy.h:1174: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00145$
00108$:
	C$fuzzy.h$1177$2_0$68 ==.
;	../../fuzzy.h:1177: parameter_1 = parameters[0];
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
	C$fuzzy.h$1178$2_0$68 ==.
;	../../fuzzy.h:1178: parameter_2 = parameters[1];
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
	C$fuzzy.h$1179$2_0$68 ==.
;	../../fuzzy.h:1179: parameter_3 = parameters[2];
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
	C$fuzzy.h$1182$1_0$66 ==.
;	../../fuzzy.h:1182: parameter_1 >= parameter_2 ||
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
	C$fuzzy.h$1183$1_0$66 ==.
;	../../fuzzy.h:1183: parameter_2 >= parameter_3 ||
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
	C$fuzzy.h$1184$1_0$66 ==.
;	../../fuzzy.h:1184: value <= parameter_1 ||
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
	C$fuzzy.h$1186$1_0$66 ==.
;	../../fuzzy.h:1186: ) {
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
	C$fuzzy.h$1187$3_0$71 ==.
;	../../fuzzy.h:1187: result = LEVEL_LO;
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
	C$fuzzy.h$1189$1_0$66 ==.
;	../../fuzzy.h:1189: else if (value == parameter_2) {
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
	C$fuzzy.h$1190$3_0$72 ==.
;	../../fuzzy.h:1190: result = LEVEL_HI;
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
	C$fuzzy.h$1192$1_0$66 ==.
;	../../fuzzy.h:1192: else if (value < parameter_2) {
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
	C$fuzzy.h$1194$1_0$66 ==.
;	../../fuzzy.h:1194: (value - parameter_1) /
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
	C$fuzzy.h$1195$1_0$66 ==.
;	../../fuzzy.h:1195: (parameter_2 - parameter_1);
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
	C$fuzzy.h$1199$1_0$66 ==.
;	../../fuzzy.h:1199: (parameter_3 - value) /
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
	C$fuzzy.h$1200$1_0$66 ==.
;	../../fuzzy.h:1200: (parameter_3 - parameter_2);
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
	C$fuzzy.h$1202$1_0$66 ==.
;	../../fuzzy.h:1202: break;
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
	C$fuzzy.h$1204$2_0$68 ==.
;	../../fuzzy.h:1204: case FUZZY_SHAPE_TRAPEZOID:
00121$:
	C$fuzzy.h$1205$2_0$68 ==.
;	../../fuzzy.h:1205: if (parameter_count != 4u) {
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	cjne	@r0,#0x04,00279$
	inc	r0
	cjne	@r0,#0x00,00279$
	sjmp	00123$
00279$:
	C$fuzzy.h$1206$3_0$75 ==.
;	../../fuzzy.h:1206: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00145$
00123$:
	C$fuzzy.h$1209$2_0$68 ==.
;	../../fuzzy.h:1209: parameter_1 = parameters[0];
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
	C$fuzzy.h$1210$2_0$68 ==.
;	../../fuzzy.h:1210: parameter_2 = parameters[1];
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
	C$fuzzy.h$1211$2_0$68 ==.
;	../../fuzzy.h:1211: parameter_3 = parameters[2];
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
	C$fuzzy.h$1212$2_0$68 ==.
;	../../fuzzy.h:1212: parameter_4 = parameters[3];
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
	C$fuzzy.h$1215$1_0$66 ==.
;	../../fuzzy.h:1215: parameter_1 >= parameter_2 ||
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
	C$fuzzy.h$1216$1_0$66 ==.
;	../../fuzzy.h:1216: parameter_2 > parameter_3 ||
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
	C$fuzzy.h$1217$1_0$66 ==.
;	../../fuzzy.h:1217: parameter_3 >= parameter_4 ||
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
	C$fuzzy.h$1218$1_0$66 ==.
;	../../fuzzy.h:1218: value <= parameter_1 ||
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
	C$fuzzy.h$1220$1_0$66 ==.
;	../../fuzzy.h:1220: ) {
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
	C$fuzzy.h$1221$3_0$76 ==.
;	../../fuzzy.h:1221: result = LEVEL_LO;
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
	C$fuzzy.h$1224$1_0$66 ==.
;	../../fuzzy.h:1224: value >= parameter_2 &&
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
	C$fuzzy.h$1226$1_0$66 ==.
;	../../fuzzy.h:1226: ) {
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
	C$fuzzy.h$1227$3_0$77 ==.
;	../../fuzzy.h:1227: result = LEVEL_HI;
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
	C$fuzzy.h$1229$1_0$66 ==.
;	../../fuzzy.h:1229: else if (value < parameter_2) {
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
	C$fuzzy.h$1231$1_0$66 ==.
;	../../fuzzy.h:1231: (value - parameter_1) /
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
	C$fuzzy.h$1232$1_0$66 ==.
;	../../fuzzy.h:1232: (parameter_2 - parameter_1);
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
	C$fuzzy.h$1236$1_0$66 ==.
;	../../fuzzy.h:1236: (parameter_4 - value) /
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
	C$fuzzy.h$1237$1_0$66 ==.
;	../../fuzzy.h:1237: (parameter_4 - parameter_3);
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
	C$fuzzy.h$1239$1_0$66 ==.
;	../../fuzzy.h:1239: break;
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
	C$fuzzy.h$1385$2_0$68 ==.
;	../../fuzzy.h:1385: case FUZZY_SHAPE_SIGMOID:
	sjmp	00144$
00142$:
	C$fuzzy.h$1386$2_0$68 ==.
;	../../fuzzy.h:1386: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$1390$2_0$68 ==.
;	../../fuzzy.h:1390: default:
	sjmp	00145$
00143$:
	C$fuzzy.h$1391$2_0$68 ==.
;	../../fuzzy.h:1391: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$1392$1_0$66 ==.
;	../../fuzzy.h:1392: }
	sjmp	00145$
00144$:
	C$fuzzy.h$1395$1_0$66 ==.
;	../../fuzzy.h:1395: result,
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
	C$fuzzy.h$1398$1_0$66 ==.
;	../../fuzzy.h:1398: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1398$1_0$66 ==.
	XG$fuzzy_function_array$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_create'
;------------------------------------------------------------
;rules         Allocated to registers r5 r6 r7 
;------------------------------------------------------------
	G$fuzzy_rules_create$0$0 ==.
	C$fuzzy.h$1401$1_0$81 ==.
;	../../fuzzy.h:1401: void fuzzy_rules_create(
;	-----------------------------------------
;	 function fuzzy_rules_create
;	-----------------------------------------
_fuzzy_rules_create:
	mov	r5, dpl
	mov	r6, dph
	mov	r7, b
	C$fuzzy.h$1405$1_0$81 ==.
;	../../fuzzy.h:1405: if (rules == NULL) {
	mov	a,r5
	orl	a,r6
	jnz	00102$
	C$fuzzy.h$1406$2_0$82 ==.
;	../../fuzzy.h:1406: return;
	sjmp	00103$
00102$:
	C$fuzzy.h$1409$1_0$81 ==.
;	../../fuzzy.h:1409: rules->count = 0;
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
	C$fuzzy.h$1410$1_0$81 ==.
;	../../fuzzy.h:1410: }
	C$fuzzy.h$1410$1_0$81 ==.
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
	C$fuzzy.h$1413$1_0$84 ==.
;	../../fuzzy.h:1413: bool fuzzy_rules_add(
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
	C$fuzzy.h$1423$1_0$84 ==.
;	../../fuzzy.h:1423: rules == NULL ||
	mov	a,r2
	orl	a,r3
	jz	00101$
	C$fuzzy.h$1424$1_0$84 ==.
;	../../fuzzy.h:1424: output_function == NULL
	mov	a,_bp
	add	a,#0xf5
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00102$
00101$:
	C$fuzzy.h$1426$2_0$85 ==.
;	../../fuzzy.h:1426: return false;
	mov	dpl, #0x00
	ljmp	00106$
00102$:
	C$fuzzy.h$1429$1_0$84 ==.
;	../../fuzzy.h:1429: if (rules->count >= FUZZY_MAX_RULES) {
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
	C$fuzzy.h$1430$2_0$86 ==.
;	../../fuzzy.h:1430: return false;
	mov	dpl, #0x00
	ljmp	00106$
00105$:
	C$fuzzy.h$1436$1_0$84 ==.
;	../../fuzzy.h:1436: rules->rules[index].name =
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
	C$fuzzy.h$1439$1_0$84 ==.
;	../../fuzzy.h:1439: rules->rules[index].value =
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
	C$fuzzy.h$1440$1_0$84 ==.
;	../../fuzzy.h:1440: fuzzy_clamp(value);
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
	C$fuzzy.h$1442$1_0$84 ==.
;	../../fuzzy.h:1442: rules->rules[index].output_function =
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
	C$fuzzy.h$1445$1_0$84 ==.
;	../../fuzzy.h:1445: rules->count++;
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
	C$fuzzy.h$1447$1_0$84 ==.
;	../../fuzzy.h:1447: return true;
	mov	dpl, #0x01
00106$:
	C$fuzzy.h$1448$1_0$84 ==.
;	../../fuzzy.h:1448: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1448$1_0$84 ==.
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
	C$fuzzy.h$1496$1_0$88 ==.
;	../../fuzzy.h:1496: float fuzzy_rules_defuzzify(
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
	C$fuzzy.h$1524$1_0$88 ==.
;	../../fuzzy.h:1524: rules == NULL ||
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00277$
	ljmp	00101$
00277$:
	C$fuzzy.h$1525$1_0$88 ==.
;	../../fuzzy.h:1525: rules->count == 0 ||
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
	C$fuzzy.h$1526$1_0$88 ==.
;	../../fuzzy.h:1526: lower > upper ||
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
	C$fuzzy.h$1528$1_0$88 ==.
;	../../fuzzy.h:1528: ) {
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
	C$fuzzy.h$1529$2_0$89 ==.
;	../../fuzzy.h:1529: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00137$
00102$:
	C$fuzzy.h$1533$1_0$88 ==.
;	../../fuzzy.h:1533: method != FUZZY_DEFUZZ_COG &&
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	mov	a,@r0
	jz	00107$
	C$fuzzy.h$1534$1_0$88 ==.
;	../../fuzzy.h:1534: method != FUZZY_DEFUZZ_MOM &&
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	cjne	@r0,#0x01,00282$
	sjmp	00107$
00282$:
	C$fuzzy.h$1535$1_0$88 ==.
;	../../fuzzy.h:1535: method != FUZZY_DEFUZZ_SOM &&
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	cjne	@r0,#0x02,00283$
	sjmp	00107$
00283$:
	C$fuzzy.h$1537$1_0$88 ==.
;	../../fuzzy.h:1537: ) {
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	cjne	@r0,#0x03,00284$
	sjmp	00107$
00284$:
	C$fuzzy.h$1538$2_0$90 ==.
;	../../fuzzy.h:1538: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00137$
00107$:
	C$fuzzy.h$1542$1_0$88 ==.
;	../../fuzzy.h:1542: 0.0f;
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
	C$fuzzy.h$1545$1_0$88 ==.
;	../../fuzzy.h:1545: 0.0f;
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
	C$fuzzy.h$1548$1_0$88 ==.
;	../../fuzzy.h:1548: LEVEL_LO;
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
	C$fuzzy.h$1551$1_0$88 ==.
;	../../fuzzy.h:1551: 0.0f;
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
	C$fuzzy.h$1554$1_0$88 ==.
;	../../fuzzy.h:1554: lower;
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
	C$fuzzy.h$1557$1_0$88 ==.
;	../../fuzzy.h:1557: lower;
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
	C$fuzzy.h$1560$1_0$88 ==.
;	../../fuzzy.h:1560: 0u;
	mov	a,_bp
	add	a,#0x38
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$1563$1_0$88 ==.
;	../../fuzzy.h:1563: false;
	mov	a,_bp
	add	a,#0x3c
	mov	r0,a
	mov	@r0,#0x00
	C$fuzzy.h$1566$2_0$91 ==.
;	../../fuzzy.h:1566: value = lower;
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
	C$fuzzy.h$1567$1_0$88 ==.
;	../../fuzzy.h:1567: value <= upper;
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
	C$fuzzy.h$1571$3_0$92 ==.
;	../../fuzzy.h:1571: LEVEL_LO;
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
	C$fuzzy.h$1580$1_0$88 ==.
;	../../fuzzy.h:1580: i = 0;
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
	C$fuzzy.h$1581$1_0$88 ==.
;	../../fuzzy.h:1581: i < rules->count;
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
	C$fuzzy.h$1585$1_0$88 ==.
;	../../fuzzy.h:1585: rules->rules[i]
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
	C$fuzzy.h$1587$5_0$94 ==.
;	../../fuzzy.h:1587: value
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
	C$fuzzy.h$1592$5_0$94 ==.
;	../../fuzzy.h:1592: output_membership
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
	C$fuzzy.h$1596$5_0$94 ==.
;	../../fuzzy.h:1596: rules->rules[i].value <
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
	C$fuzzy.h$1598$5_0$94 ==.
;	../../fuzzy.h:1598: ? rules->rules[i].value
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
	C$fuzzy.h$1599$5_0$94 ==.
;	../../fuzzy.h:1599: : output_membership;
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
	C$fuzzy.h$1604$1_0$88 ==.
;	../../fuzzy.h:1604: ? aggregated_height
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
	C$fuzzy.h$1605$5_0$94 ==.
;	../../fuzzy.h:1605: : clipped_height;
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
	C$fuzzy.h$1582$1_0$88 ==.
;	../../fuzzy.h:1582: i++
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
	C$fuzzy.h$1610$3_0$92 ==.
;	../../fuzzy.h:1610: aggregated_height
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
	C$fuzzy.h$1618$1_0$88 ==.
;	../../fuzzy.h:1618: aggregated_height;
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
	C$fuzzy.h$1621$1_0$88 ==.
;	../../fuzzy.h:1621: aggregated_height;
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
	C$fuzzy.h$1629$1_0$88 ==.
;	../../fuzzy.h:1629: !maximum_found ||
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
	C$fuzzy.h$1631$1_0$88 ==.
;	../../fuzzy.h:1631: ) {
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
	C$fuzzy.h$1633$4_0$95 ==.
;	../../fuzzy.h:1633: aggregated_height;
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
	C$fuzzy.h$1636$4_0$95 ==.
;	../../fuzzy.h:1636: value;
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
	C$fuzzy.h$1639$4_0$95 ==.
;	../../fuzzy.h:1639: value;
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
	C$fuzzy.h$1642$4_0$95 ==.
;	../../fuzzy.h:1642: value;
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
	C$fuzzy.h$1645$4_0$95 ==.
;	../../fuzzy.h:1645: 1u;
	mov	a,_bp
	add	a,#0x38
	mov	r0,a
	mov	@r0,#0x01
	inc	r0
	mov	@r0,#0x00
	C$fuzzy.h$1648$4_0$95 ==.
;	../../fuzzy.h:1648: true;
	mov	a,_bp
	add	a,#0x3c
	mov	r0,a
	mov	@r0,#0x01
	ljmp	00136$
00115$:
	C$fuzzy.h$1652$1_0$88 ==.
;	../../fuzzy.h:1652: ) {
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
	C$fuzzy.h$1654$4_0$96 ==.
;	../../fuzzy.h:1654: value;
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
	C$fuzzy.h$1657$1_0$88 ==.
;	../../fuzzy.h:1657: value;
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
	C$fuzzy.h$1659$1_0$88 ==.
;	../../fuzzy.h:1659: maximum_count++;
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
	C$fuzzy.h$1569$1_0$88 ==.
;	../../fuzzy.h:1569: ) {
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
	C$fuzzy.h$1667$1_0$88 ==.
;	../../fuzzy.h:1667: !maximum_found ||
	mov	a,_bp
	add	a,#0x3c
	mov	r0,a
	mov	a,@r0
	jz	00119$
	C$fuzzy.h$1668$1_0$88 ==.
;	../../fuzzy.h:1668: maximum_height <= LEVEL_LO ||
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
	C$fuzzy.h$1670$1_0$88 ==.
;	../../fuzzy.h:1670: ) {
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
	C$fuzzy.h$1671$2_0$97 ==.
;	../../fuzzy.h:1671: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00137$
00120$:
	C$fuzzy.h$1674$1_0$88 ==.
;	../../fuzzy.h:1674: switch (method) {
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
	C$fuzzy.h$1675$2_0$98 ==.
;	../../fuzzy.h:1675: case FUZZY_DEFUZZ_COG:
00123$:
	C$fuzzy.h$1677$1_0$88 ==.
;	../../fuzzy.h:1677: height_sum;
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
	C$fuzzy.h$1679$2_0$98 ==.
;	../../fuzzy.h:1679: case FUZZY_DEFUZZ_MOM:
00124$:
	C$fuzzy.h$1680$2_0$98 ==.
;	../../fuzzy.h:1680: if (maximum_count == 0u) {
	mov	a,_bp
	add	a,#0x38
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00126$
	C$fuzzy.h$1681$3_0$99 ==.
;	../../fuzzy.h:1681: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00137$
00126$:
	C$fuzzy.h$1685$1_0$88 ==.
;	../../fuzzy.h:1685: (float)maximum_count;
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
	C$fuzzy.h$1687$2_0$98 ==.
;	../../fuzzy.h:1687: case FUZZY_DEFUZZ_SOM:
	sjmp	00137$
00127$:
	C$fuzzy.h$1688$2_0$98 ==.
;	../../fuzzy.h:1688: return smallest_maximum;
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
	C$fuzzy.h$1690$2_0$98 ==.
;	../../fuzzy.h:1690: case FUZZY_DEFUZZ_LOM:
	sjmp	00137$
00128$:
	C$fuzzy.h$1691$2_0$98 ==.
;	../../fuzzy.h:1691: return largest_maximum;
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
	C$fuzzy.h$1693$2_0$98 ==.
;	../../fuzzy.h:1693: default:
	sjmp	00137$
00129$:
	C$fuzzy.h$1694$2_0$98 ==.
;	../../fuzzy.h:1694: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	C$fuzzy.h$1695$1_0$88 ==.
;	../../fuzzy.h:1695: }
00137$:
	C$fuzzy.h$1696$1_0$88 ==.
;	../../fuzzy.h:1696: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1696$1_0$88 ==.
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
	C$fuzzy.h$1702$1_0$101 ==.
;	../../fuzzy.h:1702: float fuzzy_rules_cog(
;	-----------------------------------------
;	 function fuzzy_rules_cog
;	-----------------------------------------
_fuzzy_rules_cog:
	push	_bp
	mov	_bp,sp
	mov	r5, dpl
	mov	r6, dph
	mov	r7, b
	C$fuzzy.h$1710$1_0$101 ==.
;	../../fuzzy.h:1710: rules,
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
	C$fuzzy.h$1716$1_0$101 ==.
;	../../fuzzy.h:1716: }
	pop	_bp
	C$fuzzy.h$1716$1_0$101 ==.
	XG$fuzzy_rules_cog$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_free'
;------------------------------------------------------------
;rules         Allocated to registers r5 r6 r7 
;------------------------------------------------------------
	G$fuzzy_rules_free$0$0 ==.
	C$fuzzy.h$1718$1_0$103 ==.
;	../../fuzzy.h:1718: void fuzzy_rules_free(
;	-----------------------------------------
;	 function fuzzy_rules_free
;	-----------------------------------------
_fuzzy_rules_free:
	mov	r5, dpl
	mov	r6, dph
	mov	r7, b
	C$fuzzy.h$1722$1_0$103 ==.
;	../../fuzzy.h:1722: if (rules == NULL) {
	mov	a,r5
	orl	a,r6
	jnz	00102$
	C$fuzzy.h$1723$2_0$104 ==.
;	../../fuzzy.h:1723: return;
	sjmp	00103$
00102$:
	C$fuzzy.h$1731$1_0$103 ==.
;	../../fuzzy.h:1731: rules->count = 0;
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
	C$fuzzy.h$1732$1_0$103 ==.
;	../../fuzzy.h:1732: }
	C$fuzzy.h$1732$1_0$103 ==.
	XG$fuzzy_rules_free$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'temperature_low'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$temperature_low$0$0 ==.
	C$sugeno_demo.c$62$1_0$106 ==.
;	../../sugeno_demo.c:62: static float temperature_low(float value)
;	-----------------------------------------
;	 function temperature_low
;	-----------------------------------------
_temperature_low:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$sugeno_demo.c$69$1_0$106 ==.
;	../../sugeno_demo.c:69: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$sugeno_demo.c$65$1_0$106 ==.
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
	C$sugeno_demo.c$71$1_0$106 ==.
;	../../sugeno_demo.c:71: }
	C$sugeno_demo.c$71$1_0$106 ==.
	XFsugeno_demo$temperature_low$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'temperature_high'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$temperature_high$0$0 ==.
	C$sugeno_demo.c$74$1_0$108 ==.
;	../../sugeno_demo.c:74: static float temperature_high(float value)
;	-----------------------------------------
;	 function temperature_high
;	-----------------------------------------
_temperature_high:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$sugeno_demo.c$81$1_0$108 ==.
;	../../sugeno_demo.c:81: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$sugeno_demo.c$77$1_0$108 ==.
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
	C$sugeno_demo.c$83$1_0$108 ==.
;	../../sugeno_demo.c:83: }
	C$sugeno_demo.c$83$1_0$108 ==.
	XFsugeno_demo$temperature_high$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'load_low'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$load_low$0$0 ==.
	C$sugeno_demo.c$90$1_0$110 ==.
;	../../sugeno_demo.c:90: static float load_low(float value)
;	-----------------------------------------
;	 function load_low
;	-----------------------------------------
_load_low:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$sugeno_demo.c$97$1_0$110 ==.
;	../../sugeno_demo.c:97: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$sugeno_demo.c$93$1_0$110 ==.
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
	C$sugeno_demo.c$99$1_0$110 ==.
;	../../sugeno_demo.c:99: }
	C$sugeno_demo.c$99$1_0$110 ==.
	XFsugeno_demo$load_low$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'load_high'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$load_high$0$0 ==.
	C$sugeno_demo.c$102$1_0$112 ==.
;	../../sugeno_demo.c:102: static float load_high(float value)
;	-----------------------------------------
;	 function load_high
;	-----------------------------------------
_load_high:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$sugeno_demo.c$109$1_0$112 ==.
;	../../sugeno_demo.c:109: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$sugeno_demo.c$105$1_0$112 ==.
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
	C$sugeno_demo.c$111$1_0$112 ==.
;	../../sugeno_demo.c:111: }
	C$sugeno_demo.c$111$1_0$112 ==.
	XFsugeno_demo$load_high$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'vibration_low'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$vibration_low$0$0 ==.
	C$sugeno_demo.c$118$1_0$114 ==.
;	../../sugeno_demo.c:118: static float vibration_low(float value)
;	-----------------------------------------
;	 function vibration_low
;	-----------------------------------------
_vibration_low:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$sugeno_demo.c$125$1_0$114 ==.
;	../../sugeno_demo.c:125: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$sugeno_demo.c$121$1_0$114 ==.
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
	C$sugeno_demo.c$127$1_0$114 ==.
;	../../sugeno_demo.c:127: }
	C$sugeno_demo.c$127$1_0$114 ==.
	XFsugeno_demo$vibration_low$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'vibration_high'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$vibration_high$0$0 ==.
	C$sugeno_demo.c$130$1_0$116 ==.
;	../../sugeno_demo.c:130: static float vibration_high(float value)
;	-----------------------------------------
;	 function vibration_high
;	-----------------------------------------
_vibration_high:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$sugeno_demo.c$137$1_0$116 ==.
;	../../sugeno_demo.c:137: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$sugeno_demo.c$133$1_0$116 ==.
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
	C$sugeno_demo.c$139$1_0$116 ==.
;	../../sugeno_demo.c:139: }
	C$sugeno_demo.c$139$1_0$116 ==.
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
	C$sugeno_demo.c$146$1_0$118 ==.
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
	C$sugeno_demo.c$154$1_0$118 ==.
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
	C$sugeno_demo.c$155$1_0$118 ==.
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
	C$sugeno_demo.c$156$1_0$118 ==.
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
	C$sugeno_demo.c$157$1_0$118 ==.
;	../../sugeno_demo.c:157: }
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$157$1_0$118 ==.
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
	C$sugeno_demo.c$160$1_0$120 ==.
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
	C$sugeno_demo.c$168$1_0$120 ==.
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
	C$sugeno_demo.c$169$1_0$120 ==.
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
	C$sugeno_demo.c$170$1_0$120 ==.
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
	C$sugeno_demo.c$171$1_0$120 ==.
;	../../sugeno_demo.c:171: }
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$171$1_0$120 ==.
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
	C$sugeno_demo.c$174$1_0$122 ==.
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
	C$sugeno_demo.c$182$1_0$122 ==.
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
	C$sugeno_demo.c$183$1_0$122 ==.
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
	C$sugeno_demo.c$184$1_0$122 ==.
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
	C$sugeno_demo.c$185$1_0$122 ==.
;	../../sugeno_demo.c:185: }
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$185$1_0$122 ==.
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
	C$sugeno_demo.c$188$1_0$124 ==.
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
	C$sugeno_demo.c$196$1_0$124 ==.
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
	C$sugeno_demo.c$197$1_0$124 ==.
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
	C$sugeno_demo.c$198$1_0$124 ==.
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
	C$sugeno_demo.c$199$1_0$124 ==.
;	../../sugeno_demo.c:199: }
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$199$1_0$124 ==.
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
	C$sugeno_demo.c$202$1_0$126 ==.
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
	C$sugeno_demo.c$210$1_0$126 ==.
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
	C$sugeno_demo.c$211$1_0$126 ==.
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
	C$sugeno_demo.c$212$1_0$126 ==.
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
	C$sugeno_demo.c$213$1_0$126 ==.
;	../../sugeno_demo.c:213: }
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$213$1_0$126 ==.
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
	C$sugeno_demo.c$216$1_0$128 ==.
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
	C$sugeno_demo.c$224$1_0$128 ==.
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
	C$sugeno_demo.c$225$1_0$128 ==.
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
	C$sugeno_demo.c$226$1_0$128 ==.
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
	C$sugeno_demo.c$227$1_0$128 ==.
;	../../sugeno_demo.c:227: }
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$227$1_0$128 ==.
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
	C$sugeno_demo.c$254$1_0$130 ==.
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
	C$sugeno_demo.c$281$1_0$130 ==.
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
	C$sugeno_demo.c$286$1_0$130 ==.
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
	C$sugeno_demo.c$291$1_0$130 ==.
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
	C$sugeno_demo.c$296$1_0$130 ==.
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
	C$sugeno_demo.c$301$1_0$130 ==.
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
	C$sugeno_demo.c$306$1_0$130 ==.
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
	C$sugeno_demo.c$310$1_0$130 ==.
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
	C$sugeno_demo.c$318$1_0$130 ==.
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
	C$sugeno_demo.c$327$1_0$130 ==.
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
	C$sugeno_demo.c$334$1_0$130 ==.
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
	C$sugeno_demo.c$341$1_0$130 ==.
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
	C$sugeno_demo.c$350$1_0$130 ==.
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
	C$sugeno_demo.c$357$1_0$130 ==.
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
	C$sugeno_demo.c$364$1_0$130 ==.
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
	C$sugeno_demo.c$370$1_0$130 ==.
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
	C$sugeno_demo.c$413$1_0$130 ==.
;	../../sugeno_demo.c:413: }
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$413$1_0$130 ==.
	XFsugeno_demo$calculate_fan_speed$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fan_speed_to_pwm'
;------------------------------------------------------------
;fan_speed     Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$fan_speed_to_pwm$0$0 ==.
	C$sugeno_demo.c$420$1_0$132 ==.
;	../../sugeno_demo.c:420: static unsigned char fan_speed_to_pwm(float fan_speed)
;	-----------------------------------------
;	 function fan_speed_to_pwm
;	-----------------------------------------
_fan_speed_to_pwm:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$sugeno_demo.c$422$1_0$132 ==.
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
	C$sugeno_demo.c$423$2_0$133 ==.
;	../../sugeno_demo.c:423: return 0u;
	mov	dpl, #0x00
	sjmp	00105$
00102$:
	C$sugeno_demo.c$426$1_0$132 ==.
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
	C$sugeno_demo.c$427$2_0$134 ==.
;	../../sugeno_demo.c:427: return 100u;
	mov	dpl, #0x64
	sjmp	00105$
00104$:
	C$sugeno_demo.c$432$1_0$132 ==.
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
	C$sugeno_demo.c$433$1_0$132 ==.
;	../../sugeno_demo.c:433: }
	C$sugeno_demo.c$433$1_0$132 ==.
	XFsugeno_demo$fan_speed_to_pwm$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;sloc0         Allocated to stack - _bp +1 +4 
;sloc1         Allocated to stack - _bp +5 +4 
;------------------------------------------------------------
	G$main$0$0 ==.
	C$sugeno_demo.c$456$1_0$136 ==.
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
	C$sugeno_demo.c$459$1_0$136 ==.
;	../../sugeno_demo.c:459: 0x55u;
	mov	_P0,#0x55
	C$sugeno_demo.c$462$1_0$136 ==.
;	../../sugeno_demo.c:462: 0x00u;
	mov	_P1,#0x00
	C$sugeno_demo.c$465$1_0$136 ==.
;	../../sugeno_demo.c:465: test_temperature;
	mov	_P2,_test_temperature
	C$sugeno_demo.c$472$2_0$136 ==.
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
	C$sugeno_demo.c$470$2_0$136 ==.
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
	C$sugeno_demo.c$469$2_0$136 ==.
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
	C$sugeno_demo.c$476$1_0$136 ==.
;	../../sugeno_demo.c:476: test_fan_speed
	mov	dpl, _test_fan_speed
	mov	dph, (_test_fan_speed + 1)
	mov	b, (_test_fan_speed + 2)
	mov	a, (_test_fan_speed + 3)
	lcall	_fan_speed_to_pwm
	mov	_test_pwm,dpl
	C$sugeno_demo.c$480$1_0$136 ==.
;	../../sugeno_demo.c:480: test_pwm;
	mov	_P1,_test_pwm
	C$sugeno_demo.c$483$1_0$136 ==.
;	../../sugeno_demo.c:483: 0xAAu;
	mov	_P0,#0xaa
00103$:
	sjmp	00103$
	C$sugeno_demo.c$488$2_0$136 ==.
;	../../sugeno_demo.c:488: }
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$488$2_0$136 ==.
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
