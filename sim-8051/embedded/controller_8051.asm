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
	.globl _fuzzy_ramp
	.globl _fuzzy_rules_create
	.globl _fuzzy_rules_add
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
	C$controller_8051.c$20$2_0$83 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:20: volatile unsigned char test_temperature = 0u;
	mov	_test_temperature,#0x00
	C$controller_8051.c$21$2_0$83 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:21: volatile unsigned char test_pwm = 0u;
	mov	_test_pwm,#0x00
	C$controller_8051.c$22$2_0$83 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:22: volatile float test_fan_speed = 0.0f;
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
	C$fuzzy.h$465$0_0$35 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:465: static float fuzzy_clamp(float value)
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
	C$fuzzy.h$467$1_0$35 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:467: if (value < LEVEL_LO) {
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
	C$fuzzy.h$468$2_0$36 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:468: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00105$
00102$:
	C$fuzzy.h$471$1_0$35 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:471: if (value > LEVEL_HI) {
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
	C$fuzzy.h$472$2_0$37 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:472: return LEVEL_HI;
	mov	dptr,#0x0000
	mov	b, #0x80
	mov	a, #0x3f
	sjmp	00105$
00104$:
	C$fuzzy.h$475$1_0$35 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:475: return value;
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
00105$:
	C$fuzzy.h$476$1_0$35 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:476: }
	C$fuzzy.h$476$1_0$35 ==.
	XFcontroller_8051$fuzzy_clamp$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_apply_hedge'
;------------------------------------------------------------
;hedge         Allocated to stack - _bp -3 +1 
;membership    Allocated to stack - _bp +1 +4 
;result        Allocated to registers r2 r3 r6 r7 
;------------------------------------------------------------
	Fcontroller_8051$fuzzy_apply_hedge$0$0 ==.
	C$fuzzy.h$486$1_0$39 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:486: static float fuzzy_apply_hedge(
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
	C$fuzzy.h$498$1_0$39 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:498: fuzzy_clamp(membership);
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
	C$fuzzy.h$513$1_0$39 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:513: if (hedge == 0u) {
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	a,@r0
	jnz	00102$
	C$fuzzy.h$514$2_0$40 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:514: hedge = 1u;
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	@r0,#0x01
00102$:
	C$fuzzy.h$517$1_0$39 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:517: result = LEVEL_HI;
	mov	r2,#0x00
	mov	r3,#0x00
	mov	r6,#0x80
	mov	r7,#0x3f
	C$fuzzy.h$519$1_0$39 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:519: while (hedge > 0u) {
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	ar5,@r0
00103$:
	mov	a,r5
	jz	00105$
	C$fuzzy.h$520$1_0$39 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:520: result *= membership;
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
	C$fuzzy.h$521$1_0$39 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:521: hedge--;
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
	C$fuzzy.h$525$1_0$39 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:525: result
	mov	dpl, r2
	mov	dph, r3
	mov	b, r6
	mov	a, r7
	lcall	_fuzzy_clamp
	C$fuzzy.h$529$1_0$39 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:529: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$529$1_0$39 ==.
	XFcontroller_8051$fuzzy_apply_hedge$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_ramp'
;------------------------------------------------------------
;lower_boundary Allocated to stack - _bp -6 +4 
;upper_boundary Allocated to stack - _bp -10 +4 
;value         Allocated to stack - _bp -14 +4 
;ramp_up       Allocated to stack - _bp -15 +1 
;hedge         Allocated to stack - _bp -16 +1 
;name          Allocated to registers 
;result        Allocated to stack - _bp +5 +4 
;normalized    Allocated to registers r7 r6 r5 r4 
;sloc0         Allocated to stack - _bp +12 +4 
;sloc1         Allocated to stack - _bp +1 +4 
;------------------------------------------------------------
	G$fuzzy_ramp$0$0 ==.
	C$fuzzy.h$616$1_0$43 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:616: float fuzzy_ramp(
;	-----------------------------------------
;	 function fuzzy_ramp
;	-----------------------------------------
_fuzzy_ramp:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x08
	mov	sp,a
	C$fuzzy.h$630$1_0$43 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:630: if (lower_boundary >= upper_boundary) {
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
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00102$
	C$fuzzy.h$631$2_0$44 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:631: return LEVEL_LO;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00109$
00102$:
	C$fuzzy.h$634$1_0$43 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:634: if (value <= lower_boundary) {
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
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00107$
	C$fuzzy.h$636$2_0$45 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:636: ramp_up
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	mov	a,@r0
	jz	00111$
	C$fuzzy.h$637$2_0$45 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:637: ? LEVEL_LO
	mov	r4,#0x00
	mov	r5,#0x00
	mov	r6,#0x00
	mov	r7,#0x00
	sjmp	00112$
00111$:
	C$fuzzy.h$638$2_0$45 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:638: : LEVEL_HI;
	mov	r4,#0x00
	mov	r5,#0x00
	mov	r6,#0x80
	mov	r7,#0x3f
00112$:
	ljmp	00108$
00107$:
	C$fuzzy.h$640$1_0$43 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:640: else if (value >= upper_boundary) {
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
	mov	a, dpl
	add	a,#0xff
	mov	b0,c
	jc	00104$
	C$fuzzy.h$642$2_0$46 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:642: ramp_up
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	mov	a,@r0
	jz	00113$
	C$fuzzy.h$643$2_0$46 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:643: ? LEVEL_HI
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
	C$fuzzy.h$644$2_0$46 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:644: : LEVEL_LO;
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
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar7,@r0
	ljmp	00108$
00104$:
	C$fuzzy.h$648$1_0$43 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:648: (value - lower_boundary) /
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
	C$fuzzy.h$649$1_0$43 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:649: (upper_boundary - lower_boundary);
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
	C$fuzzy.h$652$1_0$43 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:652: ramp_up
	mov	dpl, r7
	mov	dph, r6
	mov	b, r5
	mov	a, r4
	lcall	___fsdiv
	mov	r7, dpl
	mov	r6, dph
	mov	r5, b
	mov	r4, a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,_bp
	add	a,#0xf1
	mov	r0,a
	mov	a,@r0
	jz	00115$
	C$fuzzy.h$653$2_0$47 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:653: ? normalized
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	@r0,ar7
	inc	r0
	mov	@r0,ar6
	inc	r0
	mov	@r0,ar5
	inc	r0
	mov	@r0,ar4
	sjmp	00116$
00115$:
	C$fuzzy.h$654$1_0$43 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:654: : LEVEL_HI - normalized;
	push	ar7
	push	ar6
	push	ar5
	push	ar4
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
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar7,@r0
00108$:
	C$fuzzy.h$658$1_0$43 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:658: result,
	mov	a,_bp
	add	a,#0xf0
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
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
	C$fuzzy.h$661$1_0$43 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:661: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$661$1_0$43 ==.
	XG$fuzzy_ramp$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_create'
;------------------------------------------------------------
;rules         Allocated to registers r5 r6 r7 
;------------------------------------------------------------
	G$fuzzy_rules_create$0$0 ==.
	C$fuzzy.h$1079$1_0$49 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1079: void fuzzy_rules_create(
;	-----------------------------------------
;	 function fuzzy_rules_create
;	-----------------------------------------
_fuzzy_rules_create:
	mov	r5, dpl
	mov	r6, dph
	mov	r7, b
	C$fuzzy.h$1083$1_0$49 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1083: if (rules == NULL) {
	mov	a,r5
	orl	a,r6
	jnz	00102$
	C$fuzzy.h$1084$2_0$50 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1084: return;
	sjmp	00103$
00102$:
	C$fuzzy.h$1087$1_0$49 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1087: rules->count = 0;
	mov	a,#0x0c
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
	C$fuzzy.h$1088$1_0$49 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1088: }
	C$fuzzy.h$1088$1_0$49 ==.
	XG$fuzzy_rules_create$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_add'
;------------------------------------------------------------
;name          Allocated to stack - _bp -5 +3 
;value         Allocated to stack - _bp -9 +4 
;output_function Allocated to stack - _bp -11 +2 
;rules         Allocated to stack - _bp +1 +3 
;index         Allocated to registers 
;sloc0         Allocated to stack - _bp +6 +2 
;sloc1         Allocated to stack - _bp +4 +3 
;sloc2         Allocated to stack - _bp +7 +3 
;------------------------------------------------------------
	G$fuzzy_rules_add$0$0 ==.
	C$fuzzy.h$1091$1_0$52 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1091: bool fuzzy_rules_add(
;	-----------------------------------------
;	 function fuzzy_rules_add
;	-----------------------------------------
_fuzzy_rules_add:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	mov	a,sp
	add	a,#0x06
	mov	sp,a
	C$fuzzy.h$1101$1_0$52 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1101: rules == NULL ||
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jz	00101$
	C$fuzzy.h$1102$1_0$52 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1102: output_function == NULL
	mov	a,_bp
	add	a,#0xf5
	mov	r0,a
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00102$
00101$:
	C$fuzzy.h$1104$2_0$53 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1104: return false;
	mov	dpl, #0x00
	ljmp	00106$
00102$:
	C$fuzzy.h$1107$1_0$52 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1107: if (rules->count >= FUZZY_MAX_RULES) {
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x07
	mov	r1,a
	mov	a,#0x0c
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
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	clr	c
	mov	a,r7
	subb	a,#0x02
	mov	a,r6
	subb	a,#0x00
	jc	00105$
	C$fuzzy.h$1116$2_0$54 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1116: return false;
	mov	dpl, #0x00
	ljmp	00106$
00105$:
	C$fuzzy.h$1133$1_0$52 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1133: rules->rules[index].value =
	push	ar7
	push	ar6
	mov	dptr,#0x0006
	lcall	__mulint
	mov	r3, dpl
	mov	r2, dph
	dec	sp
	dec	sp
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x04
	mov	r1,a
	mov	a,r3
	add	a, @r0
	mov	@r1,a
	mov	a,r2
	inc	r0
	addc	a, @r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	C$fuzzy.h$1134$1_0$52 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1134: fuzzy_clamp(value);
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
	push	ar3
	push	ar2
	lcall	_fuzzy_clamp
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
	C$fuzzy.h$1136$1_0$52 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1136: rules->rules[index].output_function =
	mov	r0,_bp
	inc	r0
	mov	a,r3
	add	a, @r0
	mov	r5,a
	mov	a,r2
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
	add	a,#0xf5
	mov	r0,a
	mov	a,@r0
	lcall	__gptrput
	inc	dptr
	inc	r0
	mov	a,@r0
	lcall	__gptrput
	C$fuzzy.h$1139$1_0$52 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1139: rules->count++;
	mov	a,_bp
	add	a,#0x07
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
	add	a,#0x07
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
	C$fuzzy.h$1141$1_0$52 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1141: return true;
	mov	dpl, #0x01
00106$:
	C$fuzzy.h$1142$1_0$52 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1142: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1142$1_0$52 ==.
	XG$fuzzy_rules_add$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_cog'
;------------------------------------------------------------
;lower         Allocated to stack - _bp -6 +4 
;upper         Allocated to stack - _bp -10 +4 
;step          Allocated to stack - _bp -14 +4 
;rules         Allocated to stack - _bp +1 +3 
;weighted_sum  Allocated to stack - _bp +14 +4 
;height_sum    Allocated to stack - _bp +18 +4 
;value         Allocated to stack - _bp +22 +4 
;aggregated_height Allocated to stack - _bp +26 +4 
;output_membership Allocated to stack - _bp +30 +4 
;clipped_height Allocated to stack - _bp +34 +4 
;i             Allocated to stack - _bp +38 +2 
;sloc0         Allocated to stack - _bp +4 +3 
;sloc1         Allocated to stack - _bp +7 +3 
;sloc2         Allocated to stack - _bp +10 +4 
;------------------------------------------------------------
	G$fuzzy_rules_cog$0$0 ==.
	C$fuzzy.h$1175$1_0$56 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1175: float fuzzy_rules_cog(
;	-----------------------------------------
;	 function fuzzy_rules_cog
;	-----------------------------------------
_fuzzy_rules_cog:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	mov	a,sp
	add	a,#0x24
	mov	sp,a
	C$fuzzy.h$1191$1_0$56 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1191: rules == NULL ||
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00183$
	ljmp	00101$
00183$:
	C$fuzzy.h$1192$1_0$56 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1192: rules->count == 0 ||
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x04
	mov	r1,a
	mov	a,#0x0c
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
	C$fuzzy.h$1193$1_0$56 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1193: lower > upper ||
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
	C$fuzzy.h$1195$1_0$56 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1195: ) {
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
	C$fuzzy.h$1196$2_0$57 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1196: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00116$
00102$:
	C$fuzzy.h$1199$1_0$56 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1199: weighted_sum = 0.0f;
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
	C$fuzzy.h$1200$1_0$56 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1200: height_sum = 0.0f;
	mov	a,_bp
	add	a,#0x12
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$1203$2_0$58 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1203: value = lower;
	mov	a,_bp
	add	a,#0xfa
	mov	r0,a
	mov	a,_bp
	add	a,#0x16
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
00114$:
	C$fuzzy.h$1204$1_0$56 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1204: value <= upper;
	mov	a,_bp
	add	a,#0x16
	mov	r0,a
	mov	a,@r0
	push	acc
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
	jnc	00187$
	ljmp	00107$
00187$:
	C$fuzzy.h$1208$3_0$59 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1208: LEVEL_LO;
	mov	a,_bp
	add	a,#0x1a
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	inc	r0
	mov	@r0,a
	C$fuzzy.h$1211$1_0$56 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1211: i = 0;
	mov	a,_bp
	add	a,#0x26
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
	mov	r2,a
	mov	r3,a
00111$:
	C$fuzzy.h$1212$1_0$56 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1212: i < rules->count;
	push	ar2
	push	ar3
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
	mov	r3,a
	mov	a,_bp
	add	a,#0x26
	mov	r0,a
	clr	c
	mov	a,@r0
	subb	a,r2
	inc	r0
	mov	a,@r0
	subb	a,r3
	pop	ar3
	pop	ar2
	jc	00188$
	ljmp	00106$
00188$:
	C$fuzzy.h$1216$1_0$56 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1216: rules->rules[i]
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	a,r2
	add	a, @r0
	mov	r5,a
	mov	a,r3
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
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	C$fuzzy.h$1217$5_0$61 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1217: .output_function(value);
	push	ar6
	push	ar5
	push	ar3
	push	ar2
	lcall	00189$
	sjmp	00190$
00189$:
	push	ar5
	push	ar6
	mov	a,_bp
	add	a,#0x16
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
	ret
00190$:
	xch	a,r0
	mov	a,_bp
	add	a,#0x1e
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
	pop	ar5
	pop	ar6
	C$fuzzy.h$1220$5_0$61 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1220: rules->rules[i].value <
	mov	r0,_bp
	inc	r0
	mov	a,r2
	add	a, @r0
	mov	r5,a
	mov	a,r3
	inc	r0
	addc	a, @r0
	mov	r6,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
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
	push	ar3
	push	ar2
	mov	a,_bp
	add	a,#0x1e
	mov	r0,a
	mov	a,@r0
	push	acc
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
	pop	ar2
	pop	ar3
	mov	a,r7
	jz	00118$
	C$fuzzy.h$1222$5_0$61 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1222: ? rules->rules[i].value
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	ar7,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar4,@r0
	sjmp	00119$
00118$:
	C$fuzzy.h$1223$5_0$61 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1223: : output_membership;
	mov	a,_bp
	add	a,#0x1e
	mov	r0,a
	mov	ar7,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar4,@r0
00119$:
	mov	a,_bp
	add	a,#0x22
	mov	r0,a
	mov	@r0,ar7
	inc	r0
	mov	@r0,ar6
	inc	r0
	mov	@r0,ar5
	inc	r0
	mov	@r0,ar4
	C$fuzzy.h$1228$1_0$56 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1228: ? aggregated_height
	push	ar3
	push	ar2
	mov	a,_bp
	add	a,#0x1a
	mov	r0,a
	mov	a,@r0
	push	acc
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
	add	a,#0x22
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
	mov	a,_bp
	add	a,#0x1a
	mov	r0,a
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar7,@r0
	sjmp	00121$
00120$:
	C$fuzzy.h$1229$5_0$61 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1229: : clipped_height;
	mov	a,_bp
	add	a,#0x22
	mov	r0,a
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar7,@r0
00121$:
	mov	a,_bp
	add	a,#0x1a
	mov	r0,a
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar5
	inc	r0
	mov	@r0,ar6
	inc	r0
	mov	@r0,ar7
	C$fuzzy.h$1213$1_0$56 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1213: i++
	mov	a,#0x06
	add	a, r2
	mov	r2,a
	clr	a
	addc	a, r3
	mov	r3,a
	mov	a,_bp
	add	a,#0x26
	mov	r0,a
	inc	@r0
	cjne	@r0,#0x00,00193$
	inc	r0
	inc	@r0
00193$:
	ljmp	00111$
00106$:
	C$fuzzy.h$1234$1_0$56 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1234: aggregated_height;
	mov	a,_bp
	add	a,#0x1a
	mov	r0,a
	mov	a,@r0
	push	acc
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
	add	a,#0x16
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
	C$fuzzy.h$1237$1_0$56 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1237: aggregated_height;
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
	lcall	___fsadd
	xch	a,r0
	mov	a,_bp
	add	a,#0x0e
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
	add	a,#0x1a
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	C$fuzzy.h$1206$1_0$56 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1206: ) {
	mov	a,_bp
	add	a,#0x12
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
	add	a,#0x16
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
	add	a,#0x16
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
	ljmp	00114$
00107$:
	C$fuzzy.h$1240$1_0$56 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1240: if (height_sum == 0.0f) {
	mov	a,_bp
	add	a,#0x12
	mov	r0,a
	mov	b,@r0
	inc	r0
	mov	a,@r0
	orl	b,a
	inc	r0
	mov	a,@r0
	orl	b,a
	inc	r0
	mov	a,@r0
	anl	a,#0x7F
	orl	a,b
	jnz	00109$
	C$fuzzy.h$1241$2_0$62 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1241: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00116$
00109$:
	C$fuzzy.h$1245$1_0$56 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1245: height_sum;
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
	add	a,#0x0e
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
00116$:
	C$fuzzy.h$1246$1_0$56 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1246: }
	mov	sp,_bp
	pop	_bp
	C$fuzzy.h$1246$1_0$56 ==.
	XG$fuzzy_rules_cog$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fuzzy_rules_free'
;------------------------------------------------------------
;rules         Allocated to registers r5 r6 r7 
;------------------------------------------------------------
	G$fuzzy_rules_free$0$0 ==.
	C$fuzzy.h$1248$1_0$64 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1248: void fuzzy_rules_free(
;	-----------------------------------------
;	 function fuzzy_rules_free
;	-----------------------------------------
_fuzzy_rules_free:
	mov	r5, dpl
	mov	r6, dph
	mov	r7, b
	C$fuzzy.h$1252$1_0$64 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1252: if (rules == NULL) {
	mov	a,r5
	orl	a,r6
	jnz	00102$
	C$fuzzy.h$1253$2_0$65 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1253: return;
	sjmp	00103$
00102$:
	C$fuzzy.h$1261$1_0$64 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1261: rules->count = 0;
	mov	a,#0x0c
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
	C$fuzzy.h$1262$1_0$64 ==.
;	/mnt/c/Users/viktor/Downloads/CI/fuzzy.h:1262: }
	C$fuzzy.h$1262$1_0$64 ==.
	XG$fuzzy_rules_free$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'temperature_low'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fcontroller_8051$temperature_low$0$0 ==.
	C$controller_8051.c$40$1_0$67 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:40: static float temperature_low(
;	-----------------------------------------
;	 function temperature_low
;	-----------------------------------------
_temperature_low:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$controller_8051.c$50$1_0$67 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:50: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$controller_8051.c$45$1_0$67 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:45: NULL,
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
	clr	a
	push	acc
	push	acc
	mov	a,#0xa0
	push	acc
	rl	a
	push	acc
	mov	dptr,#0x0000
	mov	b, #0x00
	lcall	_fuzzy_ramp
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
	C$controller_8051.c$52$1_0$67 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:52: }
	C$controller_8051.c$52$1_0$67 ==.
	XFcontroller_8051$temperature_low$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'temperature_high'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fcontroller_8051$temperature_high$0$0 ==.
	C$controller_8051.c$55$1_0$69 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:55: static float temperature_high(
;	-----------------------------------------
;	 function temperature_high
;	-----------------------------------------
_temperature_high:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$controller_8051.c$65$1_0$69 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:65: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$controller_8051.c$60$1_0$69 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:60: NULL,
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
	clr	a
	push	acc
	push	acc
	mov	a,#0xf0
	push	acc
	mov	a,#0x41
	push	acc
	mov	dptr,#0x0000
	mov	b, #0x00
	lcall	_fuzzy_ramp
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
	C$controller_8051.c$67$1_0$69 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:67: }
	C$controller_8051.c$67$1_0$69 ==.
	XFcontroller_8051$temperature_high$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fan_slow'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fcontroller_8051$fan_slow$0$0 ==.
	C$controller_8051.c$74$1_0$71 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:74: static float fan_slow(
;	-----------------------------------------
;	 function fan_slow
;	-----------------------------------------
_fan_slow:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$controller_8051.c$84$1_0$71 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:84: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$controller_8051.c$79$1_0$71 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:79: NULL,
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
	clr	a
	push	acc
	push	acc
	mov	a,#0xa0
	push	acc
	rl	a
	push	acc
	mov	dptr,#0x0000
	mov	b, #0x00
	lcall	_fuzzy_ramp
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
	C$controller_8051.c$86$1_0$71 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:86: }
	C$controller_8051.c$86$1_0$71 ==.
	XFcontroller_8051$fan_slow$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fan_fast'
;------------------------------------------------------------
;value         Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fcontroller_8051$fan_fast$0$0 ==.
	C$controller_8051.c$89$1_0$73 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:89: static float fan_fast(
;	-----------------------------------------
;	 function fan_fast
;	-----------------------------------------
_fan_fast:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$controller_8051.c$99$1_0$73 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:99: hedges.none
	mov	dptr,#_hedges
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	C$controller_8051.c$94$1_0$73 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:94: NULL,
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
	clr	a
	push	acc
	push	acc
	mov	a,#0x20
	push	acc
	mov	a,#0x42
	push	acc
	mov	dptr,#0x0000
	mov	b, #0x00
	lcall	_fuzzy_ramp
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
	C$controller_8051.c$101$1_0$73 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:101: }
	C$controller_8051.c$101$1_0$73 ==.
	XFcontroller_8051$fan_fast$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'calculate_fan_speed'
;------------------------------------------------------------
;temperature   Allocated to stack - _bp +1 +4 
;rules         Allocated to stack - _bp +9 +14 
;result        Allocated to stack - _bp +23 +4 
;sloc0         Allocated to stack - _bp +5 +4 
;------------------------------------------------------------
	Fcontroller_8051$calculate_fan_speed$0$0 ==.
	C$controller_8051.c$108$1_0$75 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:108: static float calculate_fan_speed(
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
	add	a,#0x16
	mov	sp,a
	C$controller_8051.c$117$1_0$75 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:117: );
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
	C$controller_8051.c$119$1_0$75 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:119: if (!FUZZY_RULE_ADD(
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
	clr	a
	push	acc
	push	acc
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
	jnz	00102$
	C$controller_8051.c$124$2_0$76 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:124: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	ljmp	00105$
00102$:
	C$controller_8051.c$127$1_0$75 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:127: if (!FUZZY_RULE_ADD(
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
	clr	a
	push	acc
	push	acc
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
	jnz	00104$
	C$controller_8051.c$132$2_0$77 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:132: return 0.0f;
	mov	dptr,#0x0000
	clr	a
	mov	b,a
	sjmp	00105$
00104$:
	C$controller_8051.c$137$1_0$75 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:137: &rules,
	mov	ar5,r3
	mov	r6,#0x00
	mov	r7,#0x40
	push	ar3
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
	lcall	_fuzzy_rules_cog
	xch	a,r0
	mov	a,_bp
	add	a,#0x17
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
	pop	ar3
	C$controller_8051.c$145$1_0$75 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:145: );
	mov	ar2,r3
	mov	r3,#0x00
	mov	r7,#0x40
	mov	dpl, r2
	mov	dph, r3
	mov	b, r7
	lcall	_fuzzy_rules_free
	C$controller_8051.c$147$1_0$75 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:147: return result;
	mov	a,_bp
	add	a,#0x17
	mov	r0,a
	mov	dpl, @r0
	inc	r0
	mov	dph, @r0
	inc	r0
	mov	b, @r0
	inc	r0
	mov	a, @r0
00105$:
	C$controller_8051.c$148$1_0$75 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:148: }
	mov	sp,_bp
	pop	_bp
	C$controller_8051.c$148$1_0$75 ==.
	XFcontroller_8051$calculate_fan_speed$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'fan_speed_to_pwm'
;------------------------------------------------------------
;fan_speed     Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
	Fcontroller_8051$fan_speed_to_pwm$0$0 ==.
	C$controller_8051.c$155$1_0$79 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:155: static unsigned char fan_speed_to_pwm(
;	-----------------------------------------
;	 function fan_speed_to_pwm
;	-----------------------------------------
_fan_speed_to_pwm:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	C$controller_8051.c$159$1_0$79 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:159: if (fan_speed <= 0.0f) {
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
	C$controller_8051.c$160$2_0$80 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:160: return 0u;
	mov	dpl, #0x00
	sjmp	00105$
00102$:
	C$controller_8051.c$163$1_0$79 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:163: if (fan_speed >= 100.0f) {
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
	C$controller_8051.c$164$2_0$81 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:164: return 100u;
	mov	dpl, #0x64
	sjmp	00105$
00104$:
	C$controller_8051.c$169$1_0$79 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:169: );
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
	C$controller_8051.c$170$1_0$79 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:170: }
	C$controller_8051.c$170$1_0$79 ==.
	XFcontroller_8051$fan_speed_to_pwm$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
	G$main$0$0 ==.
	C$controller_8051.c$185$1_0$83 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:185: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	C$controller_8051.c$192$1_0$83 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:192: test_temperature = 42u;
	mov	_test_temperature,#0x2a
	C$controller_8051.c$197$1_0$83 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:197: P0 = 0x55u;
	mov	_P0,#0x55
	C$controller_8051.c$198$1_0$83 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:198: P1 = 0x00u;
	mov	_P1,#0x00
	C$controller_8051.c$199$1_0$83 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:199: P2 = test_temperature;
	mov	_P2,_test_temperature
	C$controller_8051.c$204$2_0$83 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:204: );
	mov	dpl, _test_temperature
	lcall	___uchar2fs
	lcall	_calculate_fan_speed
	mov	_test_fan_speed,dpl
	mov	(_test_fan_speed + 1),dph
	mov	(_test_fan_speed + 2),b
	mov	(_test_fan_speed + 3),a
	C$controller_8051.c$208$1_0$83 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:208: test_fan_speed
	mov	dpl, _test_fan_speed
	mov	dph, (_test_fan_speed + 1)
	mov	b, (_test_fan_speed + 2)
	mov	a, (_test_fan_speed + 3)
	lcall	_fan_speed_to_pwm
	mov	_test_pwm,dpl
	C$controller_8051.c$214$1_0$83 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:214: P1 = test_pwm;
	mov	_P1,_test_pwm
	C$controller_8051.c$219$1_0$83 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:219: P0 = 0xAAu;
	mov	_P0,#0xaa
00103$:
	sjmp	00103$
	C$controller_8051.c$224$2_0$83 ==.
;	/mnt/c/Users/viktor/Downloads/CI/controller_8051.c:224: }
	C$controller_8051.c$224$2_0$83 ==.
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
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
