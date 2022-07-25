.globl reset
reset:
	ldr sp, =STACK_TOP
	bl main
stop: b stop
	