;
;  Copyright 2002 by Texas Instruments Incorporated.
;  All rights reserved. Property of Texas Instruments Incorporated.
;  Restricted rights to use, duplicate or disclose this code are
;  granted through contract.
;  
;
; "@(#) DSP/BIOS 4.80.208 12-06-02 (barracuda-l19)"
;
;  ======== load.asm ========
;
;  C-callable interface to assembly language utility functions for the
;  volume example.


        .global _load

        .text

N       .set    1000

;
;  ======== _load ========
;  This function simulates a load on the DSP by executing N * loopCount
;  instructions, where loopCount is the input parameter to load().
;
;      void _load(int loopCount)
;
;  The loop is using 8 instructions. One instruction for sub, nop and
;  b, plus nop 5. The extra nop added after sub is to make the number
;  of instructions in the loop a power of 2.
;
_load:

        mv a4, b0               ; use b0 as loop counter
  [!b0] b lend  
        mvk N,b1
        mpy b1,b0,b0
        nop
        shru b0,3,b0            ; (loop counter)= (# loops)/8 

loop:
        sub b0,1,b0
        nop
   [b0] b loop
        nop 5

lend:   b b3
        nop 5                   ; return
        
        .end

