#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void change_string(char* pt) {
    
    int index=0,beginning=0,count=0;
    char temp;

    while(pt[index] != '\0') {

        while(pt[index] != ' ' && pt[index] != '\0') {
            count++;
            index++;
        }

        
        for(int i=0;i<count/2;i++) {
            temp = pt[beginning+i];
            pt[beginning+i] = pt[beginning+count-i-1];
            pt[beginning+count-i-1] = temp;
        }
        

        beginning += (count+1);
        count = 0;
        index=beginning;
        
    }
}

int main(void) {

    char *pt;
    pt = (char*)malloc(sizeof(char)*17);
    strcpy(pt,"This is a string");

    printf("%s\n",pt);
    change_string(pt);
    printf("%s\n",pt);

    return (0);
}