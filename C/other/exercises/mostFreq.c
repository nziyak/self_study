#include <stdio.h>
#include <string.h>

int main()
{
    char str[20] = "mmmmmmmmmmmmmmmmgggggggggyyyyyygyyy";
    int issame = 0, ctr1 = 0, ctr2 = 0, strLen = strlen(str);
    char mostFrequent;

    for(int i = 0; i < strLen; i++)
    {
        if (issame) {
            issame = 0;
            continue;
        }

        ctr1 = 1; 
        for(int j = i + 1; j < strLen; j++)
        {
            if (str[i] == str[j]) {
                ctr1++;
            }
        }

        if (ctr1 > ctr2) {
            ctr2 = ctr1;
            mostFrequent = str[i];
        }

        for (int k = i + 1; k < strLen; k++) {
            if (str[k] == str[i]) {
                issame = 1;
                break;
            }
        }
    }

    printf("En sik geçen harf: %c\n", mostFrequent);

    return 0;
}
