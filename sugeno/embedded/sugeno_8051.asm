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
	.globl _fuzzy_ramp
	.globl _fuzzy_triangle
	.globl _fuzzy_trapezoid
	.globl _fuzzy_rules_add_8051
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
	C$sugeno_demo.c$17$2_0$131 ==.
;	../../sugeno_demo.c:17: volatile unsigned char test_temperature = 0u;
	mov	_test_temperature,#0x00
	C$sugeno_demo.c$18$2_0$131 ==.
;	../../sugeno_demo.c:18: volatile unsigned char test_load = 0u;
	mov	_test_load,#0x00
	C$sugeno_demo.c$19$2_0$131 ==.
;	../../sugeno_demo.c:19: volatile unsigned char test_vibration = 0u;
	mov	_test_vibration,#0x00
	C$sugeno_demo.c$20$2_0$131 ==.
;	../../sugeno_demo.c:20: volatile unsigned char test_pwm = 0u;
	mov	_test_pwm,#0x00
	C$sugeno_demo.c$21$2_0$131 ==.
;	../../sugeno_demo.c:21: volatile float test_fan_speed = 0.0f;
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
;Allocation info for local variables in function 'fuzzy_8051_and2'
;------------------------------------------------------------
;a             Allocated to stack - _bp -6 +4 
;b             Allocated to stack - _bp -10 +4 
;method        Allocated to registers r7 
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$fuzzy_8051_and2$0$0 ==.
	C$fuzzy.h$116$0_0$35 ==.
;	../../fuzzy.h:116: static float fuzzy_8051_and2(fuzzy_logic_method_t method, float a, float b)
;	-----------------------------------------
;	 function fuzzy_8051_and2
;	-----------------------------------------
_fuzzy_8051_and2:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	push	_bp
	mov	_bp,sp
	mov	r7, dpl
	C$fuzzy.h$118$1_0$35 ==.
;	../../fuzzy.h:118: if (method == FUZZY_LOGIC_ALGEBRAIC) {
	cjne	r7,#0x01,00102$
	C$fuzzy.h$119$1_0$35 ==.
;	../../fuzzy.h:119: return a * b;
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
	lcall	___fsmul
	mov	r3, dpl
	mov	r4, dph
	mov	r5, b
	mov	r6, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	dpl, r3
	mov	dph, r4
	mov	b, r5
	mov	a, r6
	ljmp	00105$
00102$:
	C$fuzzy.h$122$1_0$35 ==.
;	../../fuzzy.h:122: if (method == FUZZY_LOGIC_BOUNDED) {
	cjne	r7,#0x02,00137$
	sjmp	00138$
00137$:
	ljmp	00104$
00138$:
	C$fuzzy.h$123$1_0$35 ==.
;	../../fuzzy.h:123: float value = a + b - 1.0f;
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
	C$fuzzy.h$124$1_0$35 ==.
;	../../fuzzy.h:124: return value > 0.0f ? value : 0.0f;
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	lcall	___fssub
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
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
	mov	r3, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a,r3
	jnz	00108$
	mov	r4,a
	mov	r5,a
	mov	r6,a
	mov	r7,a
00108$:
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	sjmp	00105$
00104$:
	C$fuzzy.h$127$1_0$35 ==.
;	../../fuzzy.h:127: return a < b ? a : b;
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
	mov	r7, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,r7
	jz	00109$
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar7,@r0
	sjmp	00110$
00109$:
	mov	a,_bp
	add	a,#0xf6
	mov	r0,a
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar7,@r0
00110$:
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
00105$:
	C$fuzzy.h$128$1_0$35 ==.
;	../../fuzzy.h:128: }
	pop	_bp
	C$fuzzy.h$128$1_0$35 ==.
	XFsugeno_demo$fuzzy_8051_and2$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_8051_and3'
;------------------------------------------------------------
;a             Allocated to stack - _bp -6 +4 
;b             Allocated to stack - _bp -10 +4 
;c             Allocated to stack - _bp -14 +4 
;method        Allocated to registers r7 
;------------------------------------------------------------
	Fsugeno_demo$fuzzy_8051_and3$0$0 ==.
	C$fuzzy.h$130$1_0$39 ==.
;	../../fuzzy.h:130: static float fuzzy_8051_and3(fuzzy_logic_method_t method, float a, float b, float c)
;	-----------------------------------------
;	 function fuzzy_8051_and3
;	-----------------------------------------
_fuzzy_8051_and3:
	push	_bp
	mov	_bp,sp
	mov	r7, dpl
	C$fuzzy.h$132$1_0$39 ==.
;	../../fuzzy.h:132: return fuzzy_8051_and2(method, fuzzy_8051_and2(method, a, b), c);
	push	ar7
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
	mov	dpl, r7
	lcall	_fuzzy_8051_and2
	mov	r3, dpl
	mov	r4, dph
	mov	r5, b
	mov	r6, a
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
	pop	ar7
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
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	mov	dpl, r7
	lcall	_fuzzy_8051_and2
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	C$fuzzy.h$133$1_0$39 ==.
;	../../fuzzy.h:133: }
	pop	_bp
	C$fuzzy.h$133$1_0$39 ==.
	XFsugeno_demo$fuzzy_8051_and3$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_8051_or2'
;------------------------------------------------------------
;a             Allocated to stack - _bp -6 +4 
;b             Allocated to stack - _bp -10 +4 
;method        Allocated to registers r7 
;value         Allocated to registers r4 r5 r6 r7 
;sloc0         Allocated to stack - _bp +1 +4 
;------------------------------------------------------------
	Fsugeno_demo$fuzzy_8051_or2$0$0 ==.
	C$fuzzy.h$135$1_0$41 ==.
;	../../fuzzy.h:135: static float fuzzy_8051_or2(fuzzy_logic_method_t method, float a, float b)
;	-----------------------------------------
;	 function fuzzy_8051_or2
;	-----------------------------------------
_fuzzy_8051_or2:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x04
	mov	sp,a
	mov	r7, dpl
	C$fuzzy.h$137$1_0$41 ==.
;	../../fuzzy.h:137: if (method == FUZZY_LOGIC_ALGEBRAIC) {
	cjne	r7,#0x01,00135$
	sjmp	00136$
00135$:
	ljmp	00102$
00136$:
	C$fuzzy.h$138$1_0$41 ==.
;	../../fuzzy.h:138: return a + b - a * b;
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
	lcall	___fsmul
	mov	r2, dpl
	mov	r4, dph
	mov	r5, b
	mov	r6, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	push	ar2
	push	ar4
	push	ar5
	push	ar6
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
	mov	r3, dpl
	mov	r4, dph
	mov	r5, b
	mov	r6, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	dpl, r3
	mov	dph, r4
	mov	b, r5
	mov	a, r6
	ljmp	00105$
00102$:
	C$fuzzy.h$141$1_0$41 ==.
;	../../fuzzy.h:141: if (method == FUZZY_LOGIC_BOUNDED) {
	cjne	r7,#0x02,00104$
	C$fuzzy.h$142$1_0$41 ==.
;	../../fuzzy.h:142: float value = a + b;
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
	C$fuzzy.h$143$1_0$41 ==.
;	../../fuzzy.h:143: return value < 1.0f ? value : 1.0f;
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
	lcall	___fsadd
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	clr	a
	push	acc
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0x3f
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
	jz	00107$
	sjmp	00108$
00107$:
	mov	r4,#0x00
	mov	r5,#0x00
	mov	r6,#0x80
	mov	r7,#0x3f
00108$:
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	sjmp	00105$
00104$:
	C$fuzzy.h$146$1_0$41 ==.
;	../../fuzzy.h:146: return a > b ? a : b;
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
	jz	00109$
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar7,@r0
	sjmp	00110$
00109$:
	mov	a,_bp
	add	a,#0xf6
	mov	r0,a
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar7,@r0
00110$:
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
00105$:
	C$fuzzy.h$147$1_0$41 ==.
;	../../fuzzy.h:147: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$147$1_0$41 ==.
	XFsugeno_demo$fuzzy_8051_or2$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_8051_or3'
;------------------------------------------------------------
;a             Allocated to stack - _bp -6 +4 
;b             Allocated to stack - _bp -10 +4 
;c             Allocated to stack - _bp -14 +4 
;method        Allocated to registers r7 
;------------------------------------------------------------
	Fsugeno_demo$fuzzy_8051_or3$0$0 ==.
	C$fuzzy.h$149$1_0$45 ==.
;	../../fuzzy.h:149: static float fuzzy_8051_or3(fuzzy_logic_method_t method, float a, float b, float c)
;	-----------------------------------------
;	 function fuzzy_8051_or3
;	-----------------------------------------
_fuzzy_8051_or3:
	push	_bp
	mov	_bp,sp
	mov	r7, dpl
	C$fuzzy.h$151$1_0$45 ==.
;	../../fuzzy.h:151: return fuzzy_8051_or2(method, fuzzy_8051_or2(method, a, b), c);
	push	ar7
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
	mov	dpl, r7
	lcall	_fuzzy_8051_or2
	mov	r3, dpl
	mov	r4, dph
	mov	r5, b
	mov	r6, a
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
	pop	ar7
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
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	mov	dpl, r7
	lcall	_fuzzy_8051_or2
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	C$fuzzy.h$152$1_0$45 ==.
;	../../fuzzy.h:152: }
	pop	_bp
	C$fuzzy.h$152$1_0$45 ==.
	XFsugeno_demo$fuzzy_8051_or3$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_8051_clamp'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$fuzzy_8051_clamp$0$0 ==.
	C$fuzzy.h$162$1_0$47 ==.
;	../../fuzzy.h:162: static float fuzzy_8051_clamp(float value)
;	-----------------------------------------
;	 function fuzzy_8051_clamp
;	-----------------------------------------
_fuzzy_8051_clamp:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$fuzzy.h$164$1_0$47 ==.
;	../../fuzzy.h:164: if (value < 0.0f) {
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
	C$fuzzy.h$165$2_0$48 ==.
;	../../fuzzy.h:165: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00105$
00102$:
	C$fuzzy.h$168$1_0$47 ==.
;	../../fuzzy.h:168: if (value > 1.0f) {
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
	C$fuzzy.h$169$2_0$49 ==.
;	../../fuzzy.h:169: return 1.0f;
	mov	dptr,#0x0000
	mov	b, #0x80
	mov	a, #0x3f
	sjmp	00105$
00104$:
	C$fuzzy.h$172$1_0$47 ==.
;	../../fuzzy.h:172: return value;
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
00105$:
	C$fuzzy.h$173$1_0$47 ==.
;	../../fuzzy.h:173: }
	C$fuzzy.h$173$1_0$47 ==.
	XFsugeno_demo$fuzzy_8051_clamp$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_8051_hedge'
;------------------------------------------------------------
;hedge         Allocated to stack - _bp -3 +1 
;value         Allocated to stack - _bp +1 +4 
;result        Allocated to registers r2 r3 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$fuzzy_8051_hedge$0$0 ==.
	C$fuzzy.h$175$1_0$51 ==.
;	../../fuzzy.h:175: static float fuzzy_8051_hedge(float value, fuzzy_hedge_t hedge)
;	-----------------------------------------
;	 function fuzzy_8051_hedge
;	-----------------------------------------
_fuzzy_8051_hedge:
	push	_bp
	mov	_bp,sp
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	mov	a,sp
	add	a,#0x04
	mov	sp,a
	C$fuzzy.h$179$1_0$51 ==.
;	../../fuzzy.h:179: value = fuzzy_8051_clamp(value);
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	lcall	_fuzzy_8051_clamp
	mov	r0,_bp
	inc	r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	C$fuzzy.h$181$1_0$51 ==.
;	../../fuzzy.h:181: if (hedge == 0u) {
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	a,@r0
	jnz	00102$
	C$fuzzy.h$182$2_0$52 ==.
;	../../fuzzy.h:182: hedge = 1u;
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	@r0,#0x01
00102$:
	C$fuzzy.h$185$1_0$51 ==.
;	../../fuzzy.h:185: result = 1.0f;
	mov	r2,#0x00
	mov	r3,#0x00
	mov	r6,#0x80
	mov	r7,#0x3f
	C$fuzzy.h$187$1_0$51 ==.
;	../../fuzzy.h:187: while (hedge != 0u) {
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	ar5,@r0
00103$:
	mov	a,r5
	jz	00105$
	C$fuzzy.h$188$1_0$51 ==.
;	../../fuzzy.h:188: result *= value;
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
	C$fuzzy.h$189$1_0$51 ==.
;	../../fuzzy.h:189: --hedge;
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
	C$fuzzy.h$192$1_0$51 ==.
;	../../fuzzy.h:192: return fuzzy_8051_clamp(result);
	mov	dpl, r2
	mov	dph, r3
	mov	b, r6
	mov	a, r7
	lcall	_fuzzy_8051_clamp
	C$fuzzy.h$193$1_0$51 ==.
;	../../fuzzy.h:193: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$193$1_0$51 ==.
	XFsugeno_demo$fuzzy_8051_hedge$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_not'
;------------------------------------------------------------
;membership    Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	G$fuzzy_not$0$0 ==.
	C$fuzzy.h$195$1_0$55 ==.
;	../../fuzzy.h:195: float fuzzy_not(float membership)
;	-----------------------------------------
;	 function fuzzy_not
;	-----------------------------------------
_fuzzy_not:
	C$fuzzy.h$197$1_0$55 ==.
;	../../fuzzy.h:197: return 1.0f - fuzzy_8051_clamp(membership);
	lcall	_fuzzy_8051_clamp
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
	C$fuzzy.h$198$1_0$55 ==.
;	../../fuzzy.h:198: }
	C$fuzzy.h$198$1_0$55 ==.
	XG$fuzzy_not$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_ramp'
;------------------------------------------------------------
;b             Allocated to stack - _bp -6 +4 
;x             Allocated to stack - _bp -10 +4 
;up            Allocated to stack - _bp -11 +1 
;hedge         Allocated to stack - _bp -12 +1 
;a             Allocated to registers r7 r6 r5 r4 
;result        Allocated to stack - _bp +5 +4 
;sloc0         Allocated to stack - _bp +1 +4 
;------------------------------------------------------------
	G$fuzzy_ramp$0$0 ==.
	C$fuzzy.h$200$1_0$57 ==.
;	../../fuzzy.h:200: float fuzzy_ramp(float a, float b, float x, bool up, fuzzy_hedge_t hedge)
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
	C$fuzzy.h$204$1_0$57 ==.
;	../../fuzzy.h:204: if (a >= b) {
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
	C$fuzzy.h$205$2_0$58 ==.
;	../../fuzzy.h:205: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00111$
00102$:
	C$fuzzy.h$208$1_0$57 ==.
;	../../fuzzy.h:208: if (x <= a) {
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
	jc	00109$
	C$fuzzy.h$209$2_0$59 ==.
;	../../fuzzy.h:209: result = up ? 0.0f : 1.0f;
	mov	a,_bp
	add	a,#0xf5
	mov	r0,a
	mov	a,@r0
	jz	00113$
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
	sjmp	00114$
00113$:
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
	ljmp	00110$
00109$:
	C$fuzzy.h$211$1_0$57 ==.
;	../../fuzzy.h:211: else if (x >= b) {
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
	jc	00106$
	C$fuzzy.h$212$2_0$60 ==.
;	../../fuzzy.h:212: result = up ? 1.0f : 0.0f;
	mov	a,_bp
	add	a,#0xf5
	mov	r0,a
	mov	a,@r0
	jz	00115$
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
	sjmp	00116$
00115$:
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
00116$:
	mov	r0,_bp
	inc	r0
	mov	ar7,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar4,@r0
	ljmp	00110$
00106$:
	C$fuzzy.h$215$1_0$57 ==.
;	../../fuzzy.h:215: result = (x - a) / (b - a);
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar7
	push	ar6
	push	ar5
	push	ar4
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
	C$fuzzy.h$217$1_0$57 ==.
;	../../fuzzy.h:217: if (!up) {
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
	mov	r7, dpl
	mov	r6, dph
	mov	r5, b
	mov	r4, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,_bp
	add	a,#0xf5
	mov	r0,a
	mov	a,@r0
	jnz	00110$
	C$fuzzy.h$218$1_0$57 ==.
;	../../fuzzy.h:218: result = 1.0f - result;
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	dptr,#0x0000
	mov	b, #0x80
	mov	a, #0x3f
	lcall	___fssub
	mov	r7, dpl
	mov	r6, dph
	mov	r5, b
	mov	r4, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
00110$:
	C$fuzzy.h$222$1_0$57 ==.
;	../../fuzzy.h:222: return fuzzy_8051_hedge(result, hedge);
	mov	a,_bp
	add	a,#0xf4
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	dpl, r7
	mov	dph, r6
	mov	b, r5
	mov	a, r4
	lcall	_fuzzy_8051_hedge
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	dec	sp
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
00111$:
	C$fuzzy.h$223$1_0$57 ==.
;	../../fuzzy.h:223: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$223$1_0$57 ==.
	XG$fuzzy_ramp$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_triangle'
;------------------------------------------------------------
;b             Allocated to stack - _bp -6 +4 
;c             Allocated to stack - _bp -10 +4 
;x             Allocated to stack - _bp -14 +4 
;hedge         Allocated to stack - _bp -15 +1 
;a             Allocated to registers r7 r6 r5 r4 
;result        Allocated to stack - _bp +1 +4 
;sloc0         Allocated to stack - _bp +1 +4 
;sloc1         Allocated to stack - _bp +5 +4 
;------------------------------------------------------------
	G$fuzzy_triangle$0$0 ==.
	C$fuzzy.h$225$1_0$64 ==.
;	../../fuzzy.h:225: float fuzzy_triangle(float a, float b, float c, float x, fuzzy_hedge_t hedge)
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
	C$fuzzy.h$229$1_0$64 ==.
;	../../fuzzy.h:229: if (a >= b || b >= c || x <= a || x >= c) {
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
	C$fuzzy.h$230$2_0$65 ==.
;	../../fuzzy.h:230: result = 0.0f;
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
	C$fuzzy.h$232$1_0$64 ==.
;	../../fuzzy.h:232: else if (x == b) {
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
	C$fuzzy.h$233$2_0$66 ==.
;	../../fuzzy.h:233: result = 1.0f;
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
	C$fuzzy.h$235$1_0$64 ==.
;	../../fuzzy.h:235: else if (x < b) {
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
	C$fuzzy.h$236$1_0$64 ==.
;	../../fuzzy.h:236: result = (x - a) / (b - a);
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar7
	push	ar6
	push	ar5
	push	ar4
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
	C$fuzzy.h$239$1_0$64 ==.
;	../../fuzzy.h:239: result = (c - x) / (c - b);
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
	C$fuzzy.h$242$1_0$64 ==.
;	../../fuzzy.h:242: return fuzzy_8051_hedge(result, hedge);
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
	lcall	_fuzzy_8051_hedge
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	dec	sp
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	C$fuzzy.h$243$1_0$64 ==.
;	../../fuzzy.h:243: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$243$1_0$64 ==.
	XG$fuzzy_triangle$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_trapezoid'
;------------------------------------------------------------
;b             Allocated to stack - _bp -6 +4 
;c             Allocated to stack - _bp -10 +4 
;d             Allocated to stack - _bp -14 +4 
;x             Allocated to stack - _bp -18 +4 
;hedge         Allocated to stack - _bp -19 +1 
;a             Allocated to registers r7 r6 r5 r4 
;result        Allocated to stack - _bp +1 +4 
;sloc0         Allocated to stack - _bp +1 +4 
;sloc1         Allocated to stack - _bp +5 +4 
;------------------------------------------------------------
	G$fuzzy_trapezoid$0$0 ==.
	C$fuzzy.h$245$1_0$70 ==.
;	../../fuzzy.h:245: float fuzzy_trapezoid(float a, float b, float c, float d, float x, fuzzy_hedge_t hedge)
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
	C$fuzzy.h$249$1_0$70 ==.
;	../../fuzzy.h:249: if (a >= b || b > c || c >= d || x <= a || x >= d) {
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
	C$fuzzy.h$250$2_0$71 ==.
;	../../fuzzy.h:250: result = 0.0f;
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
	C$fuzzy.h$252$1_0$70 ==.
;	../../fuzzy.h:252: else if (x >= b && x <= c) {
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
	C$fuzzy.h$253$2_0$72 ==.
;	../../fuzzy.h:253: result = 1.0f;
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
	C$fuzzy.h$255$1_0$70 ==.
;	../../fuzzy.h:255: else if (x < b) {
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
	C$fuzzy.h$256$1_0$70 ==.
;	../../fuzzy.h:256: result = (x - a) / (b - a);
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar7
	push	ar6
	push	ar5
	push	ar4
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
	C$fuzzy.h$259$1_0$70 ==.
;	../../fuzzy.h:259: result = (d - x) / (d - c);
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
	C$fuzzy.h$262$1_0$70 ==.
;	../../fuzzy.h:262: return fuzzy_8051_hedge(result, hedge);
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
	lcall	_fuzzy_8051_hedge
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	dec	sp
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	C$fuzzy.h$263$1_0$70 ==.
;	../../fuzzy.h:263: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$263$1_0$70 ==.
	XG$fuzzy_trapezoid$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_8051_eval'
;------------------------------------------------------------
;value         Allocated to stack - _bp -6 +4 
;variable      Allocated to stack - _bp +1 +3 
;sloc0         Allocated to stack - _bp +4 +1 
;sloc1         Allocated to stack - _bp +5 +1 
;sloc2         Allocated to stack - _bp +5 +4 
;sloc3         Allocated to stack - _bp +9 +4 
;sloc4         Allocated to stack - _bp +13 +4 
;sloc5         Allocated to stack - _bp +17 +4 
;------------------------------------------------------------
	Fsugeno_demo$fuzzy_8051_eval$0$0 ==.
	C$fuzzy.h$265$1_0$76 ==.
;	../../fuzzy.h:265: static float fuzzy_8051_eval(const fuzzy_variable_8051_t *variable, float value)
;	-----------------------------------------
;	 function fuzzy_8051_eval
;	-----------------------------------------
_fuzzy_8051_eval:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	mov	a,sp
	add	a,#0x11
	mov	sp,a
	C$fuzzy.h$267$1_0$76 ==.
;	../../fuzzy.h:267: if (variable->shape == FUZZY_SHAPE_RAMP) {
	mov	r0,_bp
	inc	r0
	mov	ar2,@r0
	inc	r0
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r4,a
	jz	00127$
	ljmp	00102$
00127$:
	C$fuzzy.h$268$2_0$77 ==.
;	../../fuzzy.h:268: return fuzzy_ramp(variable->parameters[0], variable->parameters[1], value, variable->parameters[2] != 0.0f, variable->hedge);
	mov	r0,_bp
	inc	r0
	mov	a,#0x01
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
	lcall	__gptrget
	mov	r4,a
	mov	r0,_bp
	inc	r0
	mov	a,#0x0a
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
	mov	r3,a
	mov	b,r5
	mov	a,r6
	orl	b,a
	mov	a,r7
	orl	b,a
	mov	a,r3
	anl	a,#0x7F
	orl	a,b
	cjne	a,#0x01,00128$
00128$:
	cpl	c
	mov	b0,c
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	c,b0
	clr	a
	rlc	a
	mov	@r0,a
	mov	r0,_bp
	inc	r0
	mov	a,#0x06
	add	a, @r0
	mov	r3,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r5,a
	inc	r0
	mov	ar6,@r0
	mov	dpl,r3
	mov	dph,r5
	mov	b,r6
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
	mov	r0,_bp
	inc	r0
	mov	a,#0x02
	add	a, @r0
	mov	r2,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r6,a
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
	push	ar4
	mov	a,_bp
	add	a,#0x04
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
	mov	dpl, r2
	mov	dph, r6
	mov	b, r7
	mov	a, r5
	lcall	_fuzzy_ramp
	mov	r3, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf6
	mov	sp,a
	mov	dpl, r3
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	ljmp	00107$
00102$:
	C$fuzzy.h$271$1_0$76 ==.
;	../../fuzzy.h:271: if (variable->shape == FUZZY_SHAPE_TRIANGLE) {
	cjne	r4,#0x01,00129$
	sjmp	00130$
00129$:
	ljmp	00104$
00130$:
	C$fuzzy.h$272$2_0$78 ==.
;	../../fuzzy.h:272: return fuzzy_triangle(variable->parameters[0], variable->parameters[1], variable->parameters[2], value, variable->hedge);
	mov	r0,_bp
	inc	r0
	mov	a,#0x01
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
	mov	r4,a
	mov	r0,_bp
	inc	r0
	mov	a,#0x0a
	add	a, @r0
	mov	r3,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r6,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r3
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
	mov	r0,_bp
	inc	r0
	mov	a,#0x06
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
	add	a,#0x0d
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
	mov	r0,_bp
	inc	r0
	mov	a,#0x02
	add	a, @r0
	mov	r2,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r6,a
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
	mov	a,@r0
	push	acc
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
	mov	dpl, r2
	mov	dph, r6
	mov	b, r7
	mov	a, r5
	lcall	_fuzzy_triangle
	mov	r3, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf3
	mov	sp,a
	mov	dpl, r3
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	ljmp	00107$
00104$:
	C$fuzzy.h$275$1_0$76 ==.
;	../../fuzzy.h:275: if (variable->shape == FUZZY_SHAPE_TRAPEZOID) {
	cjne	r4,#0x02,00131$
	sjmp	00132$
00131$:
	ljmp	00106$
00132$:
	C$fuzzy.h$276$2_0$79 ==.
;	../../fuzzy.h:276: return fuzzy_trapezoid(variable->parameters[0], variable->parameters[1], variable->parameters[2], variable->parameters[3], value, variable->hedge);
	mov	r0,_bp
	inc	r0
	mov	a,#0x01
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
	add	a,#0x0d
	mov	r0,a
	lcall	__gptrget
	mov	@r0,a
	mov	r0,_bp
	inc	r0
	mov	a,#0x0e
	add	a, @r0
	mov	r4,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r6,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r4
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
	mov	r0,_bp
	inc	r0
	mov	a,#0x0a
	add	a, @r0
	mov	r2,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r5,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r2
	mov	dph,r5
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
	mov	r0,_bp
	inc	r0
	mov	a,#0x06
	add	a, @r0
	mov	r3,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r4,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r3
	mov	dph,r4
	mov	b,r7
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
	mov	r0,_bp
	inc	r0
	mov	a,#0x02
	add	a, @r0
	mov	r2,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r5,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r2
	mov	dph,r5
	mov	b,r7
	lcall	__gptrget
	mov	r2,a
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
	add	a,#0x0d
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
	mov	a,@r0
	push	acc
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
	mov	a,@r0
	push	acc
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
	mov	dph, r5
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
	sjmp	00107$
00106$:
	C$fuzzy.h$279$1_0$76 ==.
;	../../fuzzy.h:279: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
00107$:
	C$fuzzy.h$280$1_0$76 ==.
;	../../fuzzy.h:280: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$280$1_0$76 ==.
	XFsugeno_demo$fuzzy_8051_eval$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_add_8051'
;------------------------------------------------------------
;value         Allocated to stack - _bp -6 +4 
;output        Allocated to stack - _bp -9 +3 
;rules         Allocated to stack - _bp +1 +3 
;index         Allocated to registers r3 
;sloc0         Allocated to stack - _bp +5 +1 
;sloc1         Allocated to stack - _bp +4 +3 
;sloc2         Allocated to stack - _bp +7 +3 
;------------------------------------------------------------
	G$fuzzy_rules_add_8051$0$0 ==.
	C$fuzzy.h$282$1_0$81 ==.
;	../../fuzzy.h:282: bool fuzzy_rules_add_8051(fuzzy_rules_t *rules, float value, const fuzzy_variable_8051_t *output)
;	-----------------------------------------
;	 function fuzzy_rules_add_8051
;	-----------------------------------------
_fuzzy_rules_add_8051:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	mov	a,sp
	add	a,#0x06
	mov	sp,a
	C$fuzzy.h$286$1_0$81 ==.
;	../../fuzzy.h:286: if (rules->count >= FUZZY_MAX_RULES) {
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x07
	mov	r1,a
	mov	a,#0x70
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
	add	a,#0x07
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r7,a
	cjne	r7,#0x10,00111$
00111$:
	jc	00102$
	C$fuzzy.h$287$2_0$82 ==.
;	../../fuzzy.h:287: return false;
	mov	dpl, #0x00
	ljmp	00103$
00102$:
	C$fuzzy.h$290$1_0$81 ==.
;	../../fuzzy.h:290: index = rules->count;
	mov	ar3,r7
	C$fuzzy.h$291$1_0$81 ==.
;	../../fuzzy.h:291: rules->rules[index].value = fuzzy_8051_clamp(value);
	mov	a,r3
	mov	b,#0x07
	mul	ab
	mov	r2,a
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x04
	mov	r1,a
	mov	a,r2
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
	add	a,#0xfa
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	push	ar3
	push	ar2
	lcall	_fuzzy_8051_clamp
	mov	r5, dpl
	mov	r6, dph
	mov	r4, b
	mov	r7, a
	pop	ar2
	pop	ar3
	mov	a,_bp
	add	a,#0x04
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
	C$fuzzy.h$292$1_0$81 ==.
;	../../fuzzy.h:292: rules->rules[index].output = output;
	mov	r0,_bp
	inc	r0
	mov	a,r2
	add	a, @r0
	mov	r5,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r6,a
	inc	r0
	mov	ar7,@r0
	mov	a,#0x04
	add	a, r5
	mov	r5,a
	clr	a
	addc	a, r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	mov	a,_bp
	add	a,#0xf7
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
	C$fuzzy.h$293$1_0$81 ==.
;	../../fuzzy.h:293: rules->count = index + 1u;
	mov	a,r3
	inc	a
	mov	r7,a
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,r7
	lcall	__gptrput
	C$fuzzy.h$295$1_0$81 ==.
;	../../fuzzy.h:295: return true;
	mov	dpl, #0x01
00103$:
	C$fuzzy.h$296$1_0$81 ==.
;	../../fuzzy.h:296: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$296$1_0$81 ==.
	XG$fuzzy_rules_add_8051$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_8051_height'
;------------------------------------------------------------
;x             Allocated to stack - _bp -6 +4 
;rules         Allocated to stack - _bp +1 +3 
;index         Allocated to registers r7 
;aggregate     Allocated to stack - _bp +14 +4 
;membership    Allocated to stack - _bp +18 +4 
;implied       Allocated to registers r3 r4 r5 r6 
;sloc0         Allocated to stack - _bp +4 +3 
;sloc1         Allocated to stack - _bp +7 +3 
;sloc2         Allocated to stack - _bp +10 +4 
;------------------------------------------------------------
	Fsugeno_demo$fuzzy_8051_height$0$0 ==.
	C$fuzzy.h$298$1_0$84 ==.
;	../../fuzzy.h:298: static float fuzzy_8051_height(const fuzzy_rules_t *rules, float x)
;	-----------------------------------------
;	 function fuzzy_8051_height
;	-----------------------------------------
_fuzzy_8051_height:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	mov	a,sp
	add	a,#0x12
	mov	sp,a
	C$fuzzy.h$305$1_0$84 ==.
;	../../fuzzy.h:305: aggregate = 0.0f;
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$307$3_0$86 ==.
;	../../fuzzy.h:307: for (index = 0u; index < rules->count; ++index) {
	mov	r0,_bp
	inc	r0
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
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x04
	mov	r1,a
	mov	a,#0x70
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
	mov	r7,#0x00
00105$:
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
	clr	c
	mov	a,r7
	subb	a,r6
	jc	00136$
	ljmp	00103$
00136$:
	C$fuzzy.h$308$3_0$86 ==.
;	../../fuzzy.h:308: membership = fuzzy_8051_eval(rules->rules[index].output, x);
	mov	a,r7
	mov	b,#0x07
	mul	ab
	mov	r6,a
	push	ar7
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	a,r6
	add	a, @r0
	mov	r4,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r5,a
	inc	r0
	mov	ar7,@r0
	mov	a,#0x04
	add	a, r4
	mov	r4,a
	clr	a
	addc	a, r5
	mov	r5,a
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
	push	ar7
	push	ar6
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
	mov	dpl, r4
	mov	dph, r5
	mov	b, r7
	lcall	_fuzzy_8051_eval
	xch	a,r0
	mov	a,_bp
	add	a,#0x12
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
	C$fuzzy.h$309$3_0$86 ==.
;	../../fuzzy.h:309: implied = rules->rules[index].value < membership ? rules->rules[index].value : membership;
	mov	r0,_bp
	inc	r0
	mov	a,r6
	add	a, @r0
	mov	r6,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r7,a
	inc	r0
	mov	ar5,@r0
	mov	dpl,r6
	mov	dph,r7
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
	mov	a,_bp
	add	a,#0x12
	mov	r0,a
	mov	a,@r0
	push	acc
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
	mov	a,r7
	pop	ar7
	jz	00109$
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
	sjmp	00110$
00109$:
	mov	a,_bp
	add	a,#0x12
	mov	r0,a
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
00110$:
	C$fuzzy.h$311$1_0$84 ==.
;	../../fuzzy.h:311: if (implied > aggregate) {
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	lcall	___fslt
	mov	r2, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a,r2
	jz	00106$
	C$fuzzy.h$312$4_0$87 ==.
;	../../fuzzy.h:312: aggregate = implied;
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	mov	@r0,ar3
	inc	r0
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar5
	inc	r0
	mov	@r0,ar6
00106$:
	C$fuzzy.h$307$2_0$85 ==.
;	../../fuzzy.h:307: for (index = 0u; index < rules->count; ++index) {
	inc	r7
	ljmp	00105$
00103$:
	C$fuzzy.h$316$1_0$84 ==.
;	../../fuzzy.h:316: return aggregate;
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	C$fuzzy.h$317$1_0$84 ==.
;	../../fuzzy.h:317: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$317$1_0$84 ==.
	XFsugeno_demo$fuzzy_8051_height$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_defuzzify'
;------------------------------------------------------------
;lower         Allocated to stack - _bp -6 +4 
;upper         Allocated to stack - _bp -10 +4 
;step          Allocated to stack - _bp -14 +4 
;method        Allocated to stack - _bp -15 +1 
;rules         Allocated to stack - _bp +1 +3 
;x             Allocated to stack - _bp +4 +4 
;height        Allocated to stack - _bp +8 +4 
;weighted      Allocated to stack - _bp +12 +4 
;sum           Allocated to stack - _bp +16 +4 
;maximum       Allocated to stack - _bp +20 +4 
;maximum_sum   Allocated to stack - _bp +24 +4 
;smallest      Allocated to stack - _bp +28 +4 
;largest       Allocated to stack - _bp +32 +4 
;maximum_count Allocated to registers r5 r4 
;------------------------------------------------------------
	G$fuzzy_rules_defuzzify$0$0 ==.
	C$fuzzy.h$319$1_0$89 ==.
;	../../fuzzy.h:319: float fuzzy_rules_defuzzify(const fuzzy_rules_t *rules, float lower, float upper, float step, fuzzy_defuzz_method_t method)
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
	add	a,#0x20
	mov	sp,a
	C$fuzzy.h$331$1_0$89 ==.
;	../../fuzzy.h:331: if (rules->count == 0u || lower > upper || step <= 0.0f) {
	mov	r0,_bp
	inc	r0
	mov	a,#0x70
	add	a, @r0
	mov	r2,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r3,a
	inc	r0
	mov	ar4,@r0
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	jz	00101$
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
	mov	a,r4
	jnz	00101$
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
	C$fuzzy.h$332$2_0$90 ==.
;	../../fuzzy.h:332: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00120$
00102$:
	C$fuzzy.h$335$1_0$89 ==.
;	../../fuzzy.h:335: weighted = 0.0f;
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
	C$fuzzy.h$336$1_0$89 ==.
;	../../fuzzy.h:336: sum = 0.0f;
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
	C$fuzzy.h$337$1_0$89 ==.
;	../../fuzzy.h:337: maximum = -1.0f;
	mov	a,_bp
	add	a,#0x14
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,#0x80
	inc	r0
	mov	@r0,#0xbf
	C$fuzzy.h$338$1_0$89 ==.
;	../../fuzzy.h:338: maximum_sum = 0.0f;
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
	C$fuzzy.h$339$1_0$89 ==.
;	../../fuzzy.h:339: maximum_count = 0u;
	mov	r5,a
	mov	r4,a
	C$fuzzy.h$340$1_0$89 ==.
;	../../fuzzy.h:340: smallest = lower;
	mov	a,_bp
	add	a,#0xfa
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
	C$fuzzy.h$341$1_0$89 ==.
;	../../fuzzy.h:341: largest = lower;
	mov	a,_bp
	add	a,#0x1c
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
	C$fuzzy.h$343$2_0$91 ==.
;	../../fuzzy.h:343: for (x = lower; x <= upper; x += step) {
	mov	a,_bp
	add	a,#0x1c
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
00118$:
	push	ar5
	push	ar4
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
	pop	ar4
	pop	ar5
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jnc	00211$
	ljmp	00110$
00211$:
	C$fuzzy.h$344$3_0$92 ==.
;	../../fuzzy.h:344: height = fuzzy_8051_height(rules, x);
	push	ar5
	push	ar4
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
	lcall	_fuzzy_8051_height
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
	C$fuzzy.h$346$1_0$89 ==.
;	../../fuzzy.h:346: weighted += x * height;
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
	C$fuzzy.h$347$1_0$89 ==.
;	../../fuzzy.h:347: sum += height;
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
	C$fuzzy.h$349$1_0$89 ==.
;	../../fuzzy.h:349: if (height > maximum) {
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
	add	a,#0x14
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
	pop	ar4
	pop	ar5
	mov	a,r7
	jz	00108$
	C$fuzzy.h$350$4_0$93 ==.
;	../../fuzzy.h:350: maximum = height;
	mov	a,_bp
	add	a,#0x08
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
	C$fuzzy.h$351$4_0$93 ==.
;	../../fuzzy.h:351: maximum_sum = x;
	mov	a,_bp
	add	a,#0x04
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
	C$fuzzy.h$352$4_0$93 ==.
;	../../fuzzy.h:352: maximum_count = 1u;
	mov	r5,#0x01
	mov	r4,#0x00
	C$fuzzy.h$353$4_0$93 ==.
;	../../fuzzy.h:353: smallest = x;
	mov	a,_bp
	add	a,#0x04
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
	C$fuzzy.h$354$4_0$93 ==.
;	../../fuzzy.h:354: largest = x;
	mov	a,_bp
	add	a,#0x04
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
	ljmp	00119$
00108$:
	C$fuzzy.h$356$1_0$89 ==.
;	../../fuzzy.h:356: else if (height == maximum) {
	push	ar5
	push	ar4
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
	add	a,#0x08
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
	pop	ar4
	pop	ar5
	mov	a,r7
	jz	00119$
	C$fuzzy.h$357$1_0$89 ==.
;	../../fuzzy.h:357: maximum_sum += x;
	push	ar5
	push	ar4
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
	C$fuzzy.h$358$1_0$89 ==.
;	../../fuzzy.h:358: ++maximum_count;
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
	pop	ar4
	pop	ar5
	inc	r5
	cjne	r5,#0x00,00214$
	inc	r4
00214$:
	C$fuzzy.h$359$4_0$94 ==.
;	../../fuzzy.h:359: largest = x;
	mov	a,_bp
	add	a,#0x04
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
00119$:
	C$fuzzy.h$343$1_0$89 ==.
;	../../fuzzy.h:343: for (x = lower; x <= upper; x += step) {
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
	pop	ar4
	pop	ar5
	ljmp	00118$
00110$:
	C$fuzzy.h$363$1_0$89 ==.
;	../../fuzzy.h:363: if (method == FUZZY_DEFUZZ_MOM) {
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	cjne	@r0,#0x03,00215$
	sjmp	00216$
00215$:
	sjmp	00112$
00216$:
	C$fuzzy.h$364$1_0$89 ==.
;	../../fuzzy.h:364: return maximum > 0.0f ? maximum_sum / (float)maximum_count : 0.0f;
	push	ar5
	push	ar4
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
	mov	r7, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar4
	pop	ar5
	mov	a,r7
	jz	00122$
	mov	dpl, r5
	mov	dph, r4
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
	add	a,#0x18
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
	sjmp	00123$
00122$:
	mov	r4,#0x00
	mov	r5,#0x00
	mov	r6,#0x00
	mov	r7,#0x00
00123$:
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	ljmp	00120$
00112$:
	C$fuzzy.h$367$1_0$89 ==.
;	../../fuzzy.h:367: if (method == FUZZY_DEFUZZ_SOM) {
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	cjne	@r0,#0x04,00114$
	C$fuzzy.h$368$1_0$89 ==.
;	../../fuzzy.h:368: return maximum > 0.0f ? smallest : 0.0f;
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
	mov	r7, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,r7
	jz	00124$
	mov	a,_bp
	add	a,#0x1c
	mov	r0,a
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar7,@r0
	sjmp	00125$
00124$:
	mov	r4,#0x00
	mov	r5,#0x00
	mov	r6,#0x00
	mov	r7,#0x00
00125$:
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	ljmp	00120$
00114$:
	C$fuzzy.h$371$1_0$89 ==.
;	../../fuzzy.h:371: if (method == FUZZY_DEFUZZ_LOM) {
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	cjne	@r0,#0x05,00116$
	C$fuzzy.h$372$1_0$89 ==.
;	../../fuzzy.h:372: return maximum > 0.0f ? largest : 0.0f;
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
	mov	r7, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,r7
	jz	00126$
	mov	a,_bp
	add	a,#0x20
	mov	r0,a
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar7,@r0
	sjmp	00127$
00126$:
	mov	r4,#0x00
	mov	r5,#0x00
	mov	r6,#0x00
	mov	r7,#0x00
00127$:
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	sjmp	00120$
00116$:
	C$fuzzy.h$375$1_0$89 ==.
;	../../fuzzy.h:375: return sum > 0.0f ? weighted / sum : 0.0f;
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
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	lcall	___fslt
	mov	r7, dpl
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,r7
	jz	00128$
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
	lcall	___fsdiv
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	sjmp	00129$
00128$:
	mov	r4,#0x00
	mov	r5,#0x00
	mov	r6,#0x00
	mov	r7,#0x00
00129$:
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
00120$:
	C$fuzzy.h$376$1_0$89 ==.
;	../../fuzzy.h:376: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$376$1_0$89 ==.
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
	C$fuzzy.h$378$1_0$99 ==.
;	../../fuzzy.h:378: float fuzzy_rules_cog(const fuzzy_rules_t *rules, float lower, float upper, float step)
;	-----------------------------------------
;	 function fuzzy_rules_cog
;	-----------------------------------------
_fuzzy_rules_cog:
	push	_bp
	mov	_bp,sp
	mov	r5, dpl
	mov	r6, dph
	mov	r7, b
	C$fuzzy.h$380$1_0$99 ==.
;	../../fuzzy.h:380: return fuzzy_rules_defuzzify(rules, lower, upper, step, FUZZY_DEFUZZ_COG);
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
	C$fuzzy.h$381$1_0$99 ==.
;	../../fuzzy.h:381: }
	pop	_bp
	C$fuzzy.h$381$1_0$99 ==.
	XG$fuzzy_rules_cog$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'temperature_low'
;------------------------------------------------------------
;x             Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$temperature_low$0$0 ==.
	C$sugeno_demo.c$29$1_0$101 ==.
;	../../sugeno_demo.c:29: FUZZY_VAR(temperature_low, FUZZY_SHAPE_RAMP, HEDGE_NONE, 15.0f, 40.0f, false)
;	-----------------------------------------
;	 function temperature_low
;	-----------------------------------------
_temperature_low:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#_temperature_low_fuzzy_variable
	mov	b, #0x80
	lcall	_fuzzy_8051_eval
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
	C$sugeno_demo.c$29$1_0$101 ==.
	XFsugeno_demo$temperature_low$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'temperature_high'
;------------------------------------------------------------
;x             Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$temperature_high$0$0 ==.
	C$sugeno_demo.c$30$1_0$103 ==.
;	../../sugeno_demo.c:30: FUZZY_VAR(temperature_high, FUZZY_SHAPE_RAMP, HEDGE_NONE, 35.0f, 75.0f, true)
;	-----------------------------------------
;	 function temperature_high
;	-----------------------------------------
_temperature_high:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#_temperature_high_fuzzy_variable
	mov	b, #0x80
	lcall	_fuzzy_8051_eval
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
	C$sugeno_demo.c$30$1_0$103 ==.
	XFsugeno_demo$temperature_high$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'load_low'
;------------------------------------------------------------
;x             Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$load_low$0$0 ==.
	C$sugeno_demo.c$31$1_0$105 ==.
;	../../sugeno_demo.c:31: FUZZY_VAR(load_low, FUZZY_SHAPE_RAMP, HEDGE_NONE, 20.0f, 50.0f, false)
;	-----------------------------------------
;	 function load_low
;	-----------------------------------------
_load_low:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#_load_low_fuzzy_variable
	mov	b, #0x80
	lcall	_fuzzy_8051_eval
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
	C$sugeno_demo.c$31$1_0$105 ==.
	XFsugeno_demo$load_low$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'load_high'
;------------------------------------------------------------
;x             Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$load_high$0$0 ==.
	C$sugeno_demo.c$32$1_0$107 ==.
;	../../sugeno_demo.c:32: FUZZY_VAR(load_high, FUZZY_SHAPE_RAMP, HEDGE_NONE, 45.0f, 85.0f, true)
;	-----------------------------------------
;	 function load_high
;	-----------------------------------------
_load_high:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#_load_high_fuzzy_variable
	mov	b, #0x80
	lcall	_fuzzy_8051_eval
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
	C$sugeno_demo.c$32$1_0$107 ==.
	XFsugeno_demo$load_high$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'vibration_low'
;------------------------------------------------------------
;x             Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$vibration_low$0$0 ==.
	C$sugeno_demo.c$33$1_0$109 ==.
;	../../sugeno_demo.c:33: FUZZY_VAR(vibration_low, FUZZY_SHAPE_RAMP, HEDGE_NONE, 1.0f, 4.0f, false)
;	-----------------------------------------
;	 function vibration_low
;	-----------------------------------------
_vibration_low:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#_vibration_low_fuzzy_variable
	mov	b, #0x80
	lcall	_fuzzy_8051_eval
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
	C$sugeno_demo.c$33$1_0$109 ==.
	XFsugeno_demo$vibration_low$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'vibration_high'
;------------------------------------------------------------
;x             Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$vibration_high$0$0 ==.
	C$sugeno_demo.c$34$1_0$111 ==.
;	../../sugeno_demo.c:34: FUZZY_VAR(vibration_high, FUZZY_SHAPE_RAMP, HEDGE_NONE, 3.0f, 8.0f, true)
;	-----------------------------------------
;	 function vibration_high
;	-----------------------------------------
_vibration_high:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#_vibration_high_fuzzy_variable
	mov	b, #0x80
	lcall	_fuzzy_8051_eval
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
	C$sugeno_demo.c$34$1_0$111 ==.
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
	C$sugeno_demo.c$36$1_0$113 ==.
;	../../sugeno_demo.c:36: static float response_idle(float temperature, float load, float vibration) { return 8.0f + 0.20f * temperature + 0.08f * load + 0.50f * vibration; }
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
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$36$1_0$113 ==.
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
	C$sugeno_demo.c$37$1_0$115 ==.
;	../../sugeno_demo.c:37: static float response_economy(float temperature, float load, float vibration) { return 12.0f + 0.30f * temperature + 0.18f * load + 0.80f * vibration; }
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
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$37$1_0$115 ==.
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
	C$sugeno_demo.c$38$1_0$117 ==.
;	../../sugeno_demo.c:38: static float response_balanced(float temperature, float load, float vibration) { return 15.0f + 0.42f * temperature + 0.25f * load + 1.20f * vibration; }
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
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$38$1_0$117 ==.
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
	C$sugeno_demo.c$39$1_0$119 ==.
;	../../sugeno_demo.c:39: static float response_cooling(float temperature, float load, float vibration) { return 20.0f + 0.65f * temperature + 0.12f * load + 1.50f * vibration; }
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
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$39$1_0$119 ==.
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
	C$sugeno_demo.c$40$1_0$121 ==.
;	../../sugeno_demo.c:40: static float response_heavy_load(float temperature, float load, float vibration) { return 18.0f + 0.30f * temperature + 0.55f * load + 1.00f * vibration; }
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
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$40$1_0$121 ==.
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
	C$sugeno_demo.c$41$1_0$123 ==.
;	../../sugeno_demo.c:41: static float response_protection(float temperature, float load, float vibration) { return 35.0f + 0.45f * temperature + 0.30f * load + 2.50f * vibration; }
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
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$41$1_0$123 ==.
	XFsugeno_demo$response_protection$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'calculate_fan_speed'
;------------------------------------------------------------
;load          Allocated to stack - _bp -6 +4 
;vibration     Allocated to stack - _bp -10 +4 
;temperature   Allocated to stack - _bp +1 +4 
;temperature_low_value Allocated to registers r7 r6 r5 r4 
;temperature_high_value Allocated to stack - _bp +9 +4 
;load_low_value Allocated to stack - _bp +13 +4 
;load_high_value Allocated to stack - _bp +17 +4 
;vibration_low_value Allocated to stack - _bp +21 +4 
;vibration_high_value Allocated to stack - _bp +25 +4 
;rule1         Allocated to stack - _bp +29 +4 
;rule2         Allocated to stack - _bp +33 +4 
;rule3         Allocated to stack - _bp +37 +4 
;rule4         Allocated to stack - _bp +41 +4 
;rule5         Allocated to stack - _bp +45 +4 
;rule6         Allocated to stack - _bp +49 +4 
;sloc0         Allocated to stack - _bp +5 +4 
;------------------------------------------------------------
	Fsugeno_demo$calculate_fan_speed$0$0 ==.
	C$sugeno_demo.c$43$1_0$125 ==.
;	../../sugeno_demo.c:43: static float calculate_fan_speed(float temperature, float load, float vibration)
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
	C$sugeno_demo.c$45$1_0$125 ==.
;	../../sugeno_demo.c:45: float temperature_low_value = temperature_low(temperature);
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
	C$sugeno_demo.c$46$1_0$125 ==.
;	../../sugeno_demo.c:46: float temperature_high_value = temperature_high(temperature);
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
	add	a,#0x09
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	C$sugeno_demo.c$47$1_0$125 ==.
;	../../sugeno_demo.c:47: float load_low_value = load_low(load);
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
	add	a,#0x0d
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	C$sugeno_demo.c$48$1_0$125 ==.
;	../../sugeno_demo.c:48: float load_high_value = load_high(load);
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
	add	a,#0x11
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	C$sugeno_demo.c$49$1_0$125 ==.
;	../../sugeno_demo.c:49: float vibration_low_value = vibration_low(vibration);
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
	add	a,#0x15
	xch	a,r0
	mov	@r0, dpl
	inc	r0
	mov	@r0, dph
	inc	r0
	mov	@r0, b
	inc	r0
	mov	@r0,a
	C$sugeno_demo.c$50$1_0$125 ==.
;	../../sugeno_demo.c:50: float vibration_high_value = vibration_high(vibration);
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
	add	a,#0x19
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
	C$sugeno_demo.c$52$1_0$125 ==.
;	../../sugeno_demo.c:52: float rule1 = fuzzy_and_method(FUZZY_LOGIC_STANDARD, temperature_low_value, load_low_value, vibration_low_value);
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
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	mov	dpl, #0x00
	lcall	_fuzzy_8051_and3
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
	add	a,#0xf4
	mov	sp,a
	C$sugeno_demo.c$53$1_0$125 ==.
;	../../sugeno_demo.c:53: float rule2 = fuzzy_and_method(FUZZY_LOGIC_STANDARD, fuzzy_not(temperature_high_value), load_high_value);
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
	lcall	_fuzzy_not
	mov	r2, dpl
	mov	r3, dph
	mov	r6, b
	mov	r7, a
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
	push	ar2
	push	ar3
	push	ar6
	push	ar7
	mov	dpl, #0x00
	lcall	_fuzzy_8051_and2
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
	add	a,#0xf8
	mov	sp,a
	C$sugeno_demo.c$54$1_0$125 ==.
;	../../sugeno_demo.c:54: float rule3 = fuzzy_or_method(FUZZY_LOGIC_STANDARD, temperature_high_value, vibration_high_value);
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
	mov	dpl, #0x00
	lcall	_fuzzy_8051_or2
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
	add	a,#0xf8
	mov	sp,a
	C$sugeno_demo.c$55$1_0$125 ==.
;	../../sugeno_demo.c:55: float rule4 = fuzzy_and_method(FUZZY_LOGIC_STANDARD, temperature_high_value, load_high_value);
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
	mov	dpl, #0x00
	lcall	_fuzzy_8051_and2
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
	add	a,#0xf8
	mov	sp,a
	C$sugeno_demo.c$56$1_0$125 ==.
;	../../sugeno_demo.c:56: float rule5 = fuzzy_and_method(FUZZY_LOGIC_STANDARD, load_high_value, fuzzy_not(vibration_high_value));
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
	lcall	_fuzzy_not
	mov	r2, dpl
	mov	r3, dph
	mov	r6, b
	mov	r7, a
	push	ar2
	push	ar3
	push	ar6
	push	ar7
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
	mov	dpl, #0x00
	lcall	_fuzzy_8051_and2
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
	add	a,#0xf8
	mov	sp,a
	C$sugeno_demo.c$57$1_0$125 ==.
;	../../sugeno_demo.c:57: float rule6 = fuzzy_or_method(FUZZY_LOGIC_STANDARD, fuzzy_and_method(FUZZY_LOGIC_STANDARD, temperature_high_value, vibration_high_value), fuzzy_and_method(FUZZY_LOGIC_STANDARD, load_high_value, vibration_high_value));
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
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	dpl, #0x00
	lcall	_fuzzy_8051_and2
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
	add	a,#0xf8
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
	mov	dpl, #0x00
	lcall	_fuzzy_8051_and2
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
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
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dpl, #0x00
	lcall	_fuzzy_8051_or2
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
	add	a,#0xf8
	mov	sp,a
	C$sugeno_demo.c$59$1_0$125 ==.
;	../../sugeno_demo.c:59: return fuzzy_sugeno_weighted_average(rule1, response_idle(temperature, load, vibration), rule2, response_economy(temperature, load, vibration), rule3, response_balanced(temperature, load, vibration), rule4, response_cooling(temperature, load, vibration), rule5, response_heavy_load(temperature, load, vibration), rule6, response_protection(temperature, load, vibration));
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
	push	ar2
	push	ar3
	push	ar6
	push	ar7
	mov	a,_bp
	add	a,#0x1d
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
	mov	r2, dpl
	mov	r3, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
	push	ar2
	push	ar3
	push	ar6
	push	ar7
	mov	a,_bp
	add	a,#0x21
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
	mov	r2, dpl
	mov	r3, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
	push	ar2
	push	ar3
	push	ar6
	push	ar7
	mov	a,_bp
	add	a,#0x25
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
	mov	r2, dpl
	mov	r3, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
	push	ar2
	push	ar3
	push	ar6
	push	ar7
	mov	a,_bp
	add	a,#0x29
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
	mov	r2, dpl
	mov	r3, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
	push	ar2
	push	ar3
	push	ar6
	push	ar7
	mov	a,_bp
	add	a,#0x2d
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
	mov	r2, dpl
	mov	r3, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xf8
	mov	sp,a
	push	ar2
	push	ar3
	push	ar6
	push	ar7
	mov	a,_bp
	add	a,#0x31
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
	add	a,#0x21
	mov	r0,a
	mov	a,@r0
	push	acc
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
	add	a,#0x1d
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
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,_bp
	add	a,#0x25
	mov	r0,a
	mov	a,@r0
	push	acc
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
	lcall	___fsadd
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,_bp
	add	a,#0x29
	mov	r0,a
	mov	a,@r0
	push	acc
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
	add	a,#0x2d
	mov	r0,a
	mov	a,@r0
	push	acc
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
	add	a,#0x31
	mov	r0,a
	mov	a,@r0
	push	acc
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
	C$sugeno_demo.c$60$1_0$125 ==.
;	../../sugeno_demo.c:60: }
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$60$1_0$125 ==.
	XFsugeno_demo$calculate_fan_speed$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fan_speed_to_pwm'
;------------------------------------------------------------
;fan_speed     Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fsugeno_demo$fan_speed_to_pwm$0$0 ==.
	C$sugeno_demo.c$62$1_0$127 ==.
;	../../sugeno_demo.c:62: static unsigned char fan_speed_to_pwm(float fan_speed)
;	-----------------------------------------
;	 function fan_speed_to_pwm
;	-----------------------------------------
_fan_speed_to_pwm:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$sugeno_demo.c$64$1_0$127 ==.
;	../../sugeno_demo.c:64: if (fan_speed <= 0.0f) return 0u;
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
	mov	dpl, #0x00
	sjmp	00105$
00102$:
	C$sugeno_demo.c$65$1_0$127 ==.
;	../../sugeno_demo.c:65: if (fan_speed >= 100.0f) return 100u;
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
	mov	dpl, #0x64
	sjmp	00105$
00104$:
	C$sugeno_demo.c$66$1_0$127 ==.
;	../../sugeno_demo.c:66: return (unsigned char)(fan_speed + 0.5f);
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
	C$sugeno_demo.c$67$1_0$127 ==.
;	../../sugeno_demo.c:67: }
	C$sugeno_demo.c$67$1_0$127 ==.
	XFsugeno_demo$fan_speed_to_pwm$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'update_controller'
;------------------------------------------------------------
;load          Allocated to stack - _bp -3 +1 
;vibration     Allocated to stack - _bp -4 +1 
;temperature   Allocated to registers 
;sloc0         Allocated to stack - _bp +1 +4 
;sloc1         Allocated to stack - _bp +5 +4 
;------------------------------------------------------------
	Fsugeno_demo$update_controller$0$0 ==.
	C$sugeno_demo.c$69$1_0$129 ==.
;	../../sugeno_demo.c:69: static void update_controller(unsigned char temperature, unsigned char load, unsigned char vibration)
;	-----------------------------------------
;	 function update_controller
;	-----------------------------------------
_update_controller:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x08
	mov	sp,a
	mov	_test_temperature,dpl
	C$sugeno_demo.c$72$1_0$129 ==.
;	../../sugeno_demo.c:72: test_load = load;
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	_test_load,@r0
	C$sugeno_demo.c$73$1_0$129 ==.
;	../../sugeno_demo.c:73: test_vibration = vibration;
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	_test_vibration,@r0
	C$sugeno_demo.c$74$1_0$129 ==.
;	../../sugeno_demo.c:74: test_fan_speed = calculate_fan_speed((float)test_temperature, (float)test_load, (float)test_vibration);
	mov	dpl, _test_vibration
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
	mov	dpl, _test_load
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
	mov	dpl, _test_temperature
	lcall	___uchar2fs
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
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
	C$sugeno_demo.c$75$1_0$129 ==.
;	../../sugeno_demo.c:75: test_pwm = fan_speed_to_pwm(test_fan_speed);
	mov	dpl, _test_fan_speed
	mov	dph, (_test_fan_speed + 1)
	mov	b, (_test_fan_speed + 2)
	mov	a, (_test_fan_speed + 3)
	lcall	_fan_speed_to_pwm
	mov	_test_pwm,dpl
	C$sugeno_demo.c$76$1_0$129 ==.
;	../../sugeno_demo.c:76: }
	mov	sp,_bp
	pop	_bp
	C$sugeno_demo.c$76$1_0$129 ==.
	XFsugeno_demo$update_controller$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
	G$main$0$0 ==.
	C$sugeno_demo.c$80$1_0$131 ==.
;	../../sugeno_demo.c:80: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	C$sugeno_demo.c$82$1_0$131 ==.
;	../../sugeno_demo.c:82: P1 = 0x00u;
	mov	_P1,#0x00
00107$:
	C$sugeno_demo.c$85$3_0$133 ==.
;	../../sugeno_demo.c:85: test_vibration = P0;
	mov	_test_vibration,_P0
	C$sugeno_demo.c$86$3_0$133 ==.
;	../../sugeno_demo.c:86: test_temperature = P2;
	mov	_test_temperature,_P2
	C$sugeno_demo.c$87$3_0$133 ==.
;	../../sugeno_demo.c:87: test_load = P3;
	mov	_test_load,_P3
	C$sugeno_demo.c$89$3_0$133 ==.
;	../../sugeno_demo.c:89: if (test_temperature > 100u || test_load > 100u || test_vibration > 10u) {
	mov	a,_test_temperature
	add	a,#0xff - 0x64
	jc	00101$
	mov	a,_test_load
	add	a,#0xff - 0x64
	jc	00101$
	mov	a,_test_vibration
	add	a,#0xff - 0x0a
	jnc	00102$
00101$:
	C$sugeno_demo.c$90$4_0$134 ==.
;	../../sugeno_demo.c:90: P1 = 0x00u;
	mov	_P1,#0x00
	C$sugeno_demo.c$91$4_0$134 ==.
;	../../sugeno_demo.c:91: continue;
	sjmp	00107$
00102$:
	C$sugeno_demo.c$95$3_0$133 ==.
;	../../sugeno_demo.c:95: test_temperature,
	push	_test_vibration
	push	_test_load
	mov	dpl, _test_temperature
	lcall	_update_controller
	dec	sp
	dec	sp
	C$sugeno_demo.c$100$3_0$133 ==.
;	../../sugeno_demo.c:100: P1 = test_pwm;
	mov	_P1,_test_pwm
	sjmp	00107$
	C$sugeno_demo.c$102$2_0$131 ==.
;	../../sugeno_demo.c:102: }
	C$sugeno_demo.c$102$2_0$131 ==.
	XG$main$0$0 ==.
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area CONST   (CODE)
Fsugeno_demo$temperature_low_fuzzy_variable$0_0$0 == .
_temperature_low_fuzzy_variable:
	.db #0x00	; 0
	.db #0x01	; 1
	.byte #0x00, #0x00, #0x70, #0x41	;  1.500000e+01
	.byte #0x00, #0x00, #0x20, #0x42	;  4.000000e+01
	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
	.area CSEG    (CODE)
	.area CONST   (CODE)
Fsugeno_demo$temperature_high_fuzzy_variable$0_0$0 == .
_temperature_high_fuzzy_variable:
	.db #0x00	; 0
	.db #0x01	; 1
	.byte #0x00, #0x00, #0x0c, #0x42	;  3.500000e+01
	.byte #0x00, #0x00, #0x96, #0x42	;  7.500000e+01
	.byte #0x00, #0x00, #0x80, #0x3f	;  1.000000e+00
	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
	.area CSEG    (CODE)
	.area CONST   (CODE)
Fsugeno_demo$load_low_fuzzy_variable$0_0$0 == .
_load_low_fuzzy_variable:
	.db #0x00	; 0
	.db #0x01	; 1
	.byte #0x00, #0x00, #0xa0, #0x41	;  2.000000e+01
	.byte #0x00, #0x00, #0x48, #0x42	;  5.000000e+01
	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
	.area CSEG    (CODE)
	.area CONST   (CODE)
Fsugeno_demo$load_high_fuzzy_variable$0_0$0 == .
_load_high_fuzzy_variable:
	.db #0x00	; 0
	.db #0x01	; 1
	.byte #0x00, #0x00, #0x34, #0x42	;  4.500000e+01
	.byte #0x00, #0x00, #0xaa, #0x42	;  8.500000e+01
	.byte #0x00, #0x00, #0x80, #0x3f	;  1.000000e+00
	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
	.area CSEG    (CODE)
	.area CONST   (CODE)
Fsugeno_demo$vibration_low_fuzzy_variable$0_0$0 == .
_vibration_low_fuzzy_variable:
	.db #0x00	; 0
	.db #0x01	; 1
	.byte #0x00, #0x00, #0x80, #0x3f	;  1.000000e+00
	.byte #0x00, #0x00, #0x80, #0x40	;  4.000000e+00
	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
	.area CSEG    (CODE)
	.area CONST   (CODE)
Fsugeno_demo$vibration_high_fuzzy_variable$0_0$0 == .
_vibration_high_fuzzy_variable:
	.db #0x00	; 0
	.db #0x01	; 1
	.byte #0x00, #0x00, #0x40, #0x40	;  3.000000e+00
	.byte #0x00, #0x00, #0x00, #0x41	;  8.000000e+00
	.byte #0x00, #0x00, #0x80, #0x3f	;  1.000000e+00
	.byte #0x00, #0x00, #0x00, #0x00	;  0.000000e+00
	.area CSEG    (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
