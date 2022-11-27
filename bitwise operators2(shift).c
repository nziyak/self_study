// first operand(left operand) << second operand(right operand)
/* the left part is whose bits get left shifted.
 decides the number of places to shift the bits
 
 when bits are shifted left then the trailing positions are filled with zeros*/

 #include <stdio.h>

 int main(){

    char var = 3;          // 3 in binary 0000 0011
    printf("%d", var<<1);
    return 0;
 }
                          //                      right operand
 /*left shift is equivalent to multiplication by 2                */

 // in right shift operation, leading positions are filled with zero and this operation is equivalent to division by 2