/* there are 2 kinds of usages of "const" keyword with pointers
 1) constant pointers
 2) pointers to constants
*/
 

// *********CONSTANT POINTERS*********

// an address that is holded by a constant pointer cant be changed
// it's definition: 
// int* const ptr1; 
// or
// char* const ptr2;

// an example program:

int num1 = 5, num2 = 10;

int* const ptr = &num1; // from now on, any other value can not be assigned to ptr1

// for example, the expression below produces an error:
// ptr = &num2;


// *********POINTERS to CONSTANTS*********

// these pointers must point to constant values

// it's definition: 
// const int* ptr1;
// const char* ptr2;

// an example program:

const int* ptr1;

int sayi1 = 5;
const int sayi2 = 10;

// expression below produces error:
//ptr1 = &sayi1;

// expression below is a correct usage of pointers to constants:
const int* ptr2 = &sayi2;
printf("%d", *ptr2); 