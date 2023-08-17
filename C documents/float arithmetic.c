 #include <stdio.h>

 int main(){

   int var = 4/9;            /*we are performing division between two integer values and storing the result as a integer. so the part after
   decimal point will be truncated.*/
      printf("%d\n", var);

   float var1 = 4/9;              /*again we are performing division between two integer values.*/
      printf("%.2f\n", var1);  

   float var2 = 4.0/9.0;
      printf("%.2f\n", var2);      
    
 }