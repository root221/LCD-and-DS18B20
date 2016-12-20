.syntax unified
.cpu cortex-m4
.thumb

.text
	.global delay


.func delay
delay:
	// r0: n us
	push {r4-r11, lr} // 10 cyc
	movs r4, #20
	mul r0, r4
	sub r0, #20
	add r0, #1
	delay_loop:
		subs r0, #1
		bne delay_loop
	pop { r4-r11, lr} //10 cyc
	bx lr
.endfunc
