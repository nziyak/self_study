/*float -->4 bytes = 32 bits
double  -->8 bytes = 64 bits
long double --> 12 bytes = 96 bits 
size of those data types depends on the system*/

#include <stdio.h>

int main() {

float var1 = 3.138378457578573;
double var2 = 3.138378457578573;
long double var3 = 3.13837845757857387654;

printf("%d\n",sizeof(float));
printf("%d\n",sizeof(double));
printf("%d\n",sizeof(long double));
printf("%.14f\n", var1);
printf("%.13lf\n", var2);
printf("%.19Lf\n", var3);





}