.text
.global _start
.extern printf



_start:
    .global main

	
main:
	adr x10, minValue
	ldur d15, [x10]
	ldr x8, =N
	ldr x8, [x8]
	sub x8, x8, #0
	lsl x8, x8, #3 
	ldr x2, =y
	ldr x1, =x
	mov x3, #0
	

   b outerLoop



outerLoop:

	cmp x3, x8
	mov x4, x3
	add x4, x4, #8 
	b.lt innerLoop
	b exit

innerLoop:
	cmp x4, x8
	b.ge increment
	ldr d8, [x2, x3]
	ldr d9, [x1, x3]
	ldr d10, [x2, x4]
	ldr d11, [x1, x4]
	fsub d12, d8, d10
	fmul d12, d12, d12
	fsub d13, d9, d11
	fmul d13, d13, d13
	fadd d12, d12, d13
	fcmp d12, d14
	b.gt max
	fcmp d12, d15
	b.lt min
	add x4, x4, #8
	b innerLoop
	
max:
	fmov d14, d12
	mov x5, x3
	mov x6, x4
	add x4, x4, #8
	b innerLoop
min:
	fmov d15, d12
	mov x11, x3
	mov x12, x4
	add x4, x4, #8
	b innerLoop

increment:
	add x3, x3, #8
	b outerLoop
exit:
   ldr x0, =string
     fmov d0, d14
     fmov d1, d15
	mov x1, x5
	lsr x1, x1, #3
	mov x2, x6
	lsr x2, x2, #3
	mov x3, x11
	mov x4, x12
	lsr x3, x3, #3
	lsr x4, x4, #3
	

    bl printf
    svc     #0          /* invoke syscall */
    mov     x0, #0      /* status := 0 */
    mov     w8, #93     /* exit is syscall #1 */
    ret

.data
N:
	.dword 8
x:
	.double 0.0, 0.4140, 1.4949, 5.0014, 6.5163, 3.9303, 8.4813, 2.6505
y: 	
	.double 0.0, 3.9862, 6.1488, 1.047, 4.6102, 1.4057,5.0371, 4.1196
string:
	.asciz "Furthest indices are %d %d\nClosest indexes are %d %d\n"
minValue:
	.double 100000.0
.end


   

