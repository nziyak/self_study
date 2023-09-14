
/*u can define a scope for variables. scope of variable means the lifetime of variables, 
so, an automatic variable will destroyed when a block or region that a variable is  declared, 
defined and used and when that block or region ends
*/

/*   {

            ...
            
            {

                          the content of outer block is visible to internal block but the content of outer block is not visible to internal block.
                          so we can use a variable which is defined in outer block in internal block. but we cant use a variable which is defined
                          in internal block in outer block.

                          we can summarize the scoping rule like that: content of a block is not visible outside of it. 

                          and a variable that declared in internal block -local of outer block- will be priority while been printing.
            }

            ...

     }                  
     
     
     */


    #include <stdio.h>

    int fun();

    int var = 10; /* because of this variable is at outside of all functions, it is available for all functions and its named as 'global variable'*/

    int main();

    ...


