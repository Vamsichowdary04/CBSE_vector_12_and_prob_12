.include "/storage/self/primary/Documents/arduinio/assembly/m328Pdef.inc"


ldi r16, 0b00100000 ; Define LED pin (PB5)

ldi r17, 0xFF ; Initialize PORTB (LED pin) as output
out DDRB, r17

loop:
    ; Input A = 0, Input B = 0
    cbi PORTB, 5 ; Turn on LED
    rcall delay
    sbi PORTB, 5 ; Turn off LED
    rcall delay

    ; Input A = 0, Input B = 1
    cbi PORTB, 5 ; Turn on LED
    rcall delay
    sbi PORTB, 5 ; Turn off LED
    rcall delay

    ; Input A = 1, Input B = 0
    sbi PORTB, 5 ; Turn off LED
    rcall delay
    cbi PORTB, 5 ; Turn on LED
    rcall delay

    ; Input A = 1, Input B = 1
    sbi PORTB, 5 ; Turn off LED
    rcall delay
    cbi PORTB, 5 ; Turn on LED
    rcall delay

    rjmp loop ; Repeat the loop indefinitely

delay:
    ldi r18, 255
outer_loop:
    ldi r19, 255
inner_loop:
    ldi r20, 49
inner_inner_loop:
    dec r20
    brne inner_inner_loop
    dec r19
    brne inner_loop
    dec r18
    brne outer_loop
    ret
