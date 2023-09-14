#include <stdio.h>
#include <stdarg.h>

void myPrintf(char* format, ...);

int main()
{
    int tamsayi = 5;
    float ondalikSayi = 3.14;
    char *kitapIsmi = "Her Yonuyle C";

    myPrintf("Tamsayi = %d\n", tamsayi);
    myPrintf("Ondalik Sayi = %f\n", ondalikSayi);
    myPrintf("Kitap Ismi = %s\n", kitapIsmi);

    myPrintf("Tamsayi = %d\nOndalik Sayi = %f\nKitap Ismi = %s\n", tamsayi, ondalikSayi, kitapIsmi);

    return 0;
}

void myPrintf(char* bicimlendirilecekMetin, ...)
{
    int tamsayiParametre;
    double ondalikSayiParametre;
    char* metinParametre;

    va_list parametreler;
    va_start(parametreler, bicimlendirilecekMetin);

    char* ptr = bicimlendirilecekMetin;

    while(*ptr != '\0')
    {
        // % varsa bicim niteleyicisi gelmiştir
        if(*ptr == '%')
        {
            // % işaretinden sonraki karakteri incele
            switch(*++ptr)
            {
                case 'd':
                    tamsayiParametre = va_arg(parametreler, int);
                    printf("%d", tamsayiParametre);
                    break;

                case 's':
                    metinParametre = va_arg(parametreler, char*);
                    printf("%s", metinParametre);
                    break;

                case 'f':
                    ondalikSayiParametre = va_arg(parametreler, double);
                    printf("%f", ondalikSayiParametre);
                    break;
                
                //bilmediğin bir şeyse direkt yazdır
                default:
                    putchar(*ptr);
                    break;
            }
        }

        else
        {
            //eger karakter % degilse direkt yazdir
            putchar(*ptr);
        }

        //sonraki karaktere geç
        ptr++;
    }

    //parametreleri boşalt
    va_end(parametreler);
}