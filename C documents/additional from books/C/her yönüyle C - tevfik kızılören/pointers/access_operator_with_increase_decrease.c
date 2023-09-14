/*

int sayi = *ptr++; komutunda önce ptr değişkeninin tuttuğu bellek adresindeki değer sayi değişkenine kopyalanır,
 sonra ptr değişkeninin tuttuğu değer bir artırılır. 

int sayi = *++ptr; komutunda ise önce ptr değişkeninin tuttuğu bellek adresi değeri bir artırlır (4 bayt ileri gidilir)
daha sonra yeni bellek adresindeki değer sayi değerine atanır.

netleştirmek adına aşağıdaki örneğe bakalım:

 */ 

#include <stdio.h>

int main()
{
    int dizi[5] = {1,2,3,4,5};
    int *ptr = NULL;
    int sayi;

    ptr = dizi;
    sayi = *ptr++;

    printf("\n----------------------\n");
    printf("*ptr++ komutu sonrasi\n");
    printf("----------------------\n");
    printf("sayi:%d\n", sayi);
    printf("*ptr:%d\n", *ptr);

    ptr = dizi;
    sayi = *++ptr;

    printf("----------------------\n");
    printf("*++ptr komutu sonrasi\n");
    printf("----------------------\n");
    printf("sayi:%d\n", sayi);
    printf("*ptr:%d\n\n", *ptr);
}