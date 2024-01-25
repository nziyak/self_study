#include <stdio.h>

int main()
{
    FILE* reader;
    int a, b;

    reader = fopen("read.txt", "r");

    if(reader == NULL) 
    {
        perror("file could not been opened for reading");
        return 1;
    }
    
    long int konum = ftell(reader);
    
    printf("position of ptr at the beginning: %ld\n", konum);
    
    fscanf(reader, "%d   %d", &a, &b);

    konum = ftell(reader);

    printf("position of ptr after reading 2 integers: %ld\n", konum);

    printf("first bigram: %d %d\n", a, b);

    fseek(reader, -2, SEEK_CUR);

    konum = ftell(reader);

    printf("position of ptr after taking it back 2 bytes: %ld\n", konum);

    fscanf(reader, "%d   %d\n", &a, &b);

    printf("second bigram: %d %d", a, b);

    return 0;
}