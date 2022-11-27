/* & is AND (it takes two bits at a time and perform AND operation.)
   | is OR ()
   ~ is NOT
   << is LEFT SHIFT
   >> is RIGHT SHIFT
   ^ is XOR */

// to understand the difference between bitwise operators and logical operators, you can write this;
#include <stdio.h>
int main(){

char x = 1, y = 2; // x = 1(0000 0001), y = 2(0000 0010)
if(x&y){        // 1&2 = 0(0000 0000). 0 simply means false, so this will not be evaulated
  printf("Result of x&y is 1 ");
}

if(x&&y){       // 1&&2 = TRUE && TRUE = TRUE = 1
  printf("Result of x&&y is 1 ");
}

  return 0;
}
