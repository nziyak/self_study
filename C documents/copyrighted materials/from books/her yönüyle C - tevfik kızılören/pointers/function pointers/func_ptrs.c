#include <stdio.h>

int faktoriyelHesapla(int);

int main()
{
    int sayi = 0;

    //int parametresi alan ve int döndüren fonkPtr isimli bir fonksiyon işaretçisi tanımlayalım:
    int (*fonkPtr)(int);

    //fonksiyon adresini fonksiyon işaretçisine atayalım: 
    fonkPtr = faktoriyelHesapla;

    printf("faktoriyeli bulunacak sayiyi giriniz: ");
    scanf("%d", &sayi);

    //fonksiyonu işaretçi aracılığıyla çağıralım:
    int faktoriyel = (*fonkPtr)(sayi);

    printf("%d\n", faktoriyel);

    return 0;
}

int faktoriyelHesapla(int sayi)
{
    //sıfır ve sıfırdan büyük sayıların faktoriyeli aşağıdaki gibi hesaplanabilir:
    //negatif sayılar için 1 döndürülür.
    
    int sonuc = 1;

    if(sayi <= 0)
        return sonuc;

    int i;

    for(i = sayi; i >= 1; i--)
    {
        sonuc = sonuc * i;
    }

    return sonuc;
}