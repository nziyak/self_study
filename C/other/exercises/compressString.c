#include <stdio.h>
#include <string.h>

void compress(const char*, char*);
void decompress(const char*, char*);

int main() 
{
    const char input[] = "aaabbcccc";
    char compressed[100];
    char decompressed[100];
    
    printf("first state: %s\n", input);
    compress(input, compressed);
    printf("compressed: %s\n", compressed);
    
    decompress(compressed, decompressed);
    printf("decompressed: %s\n", decompressed);
    
    return 0;
}

void compress(const char *input, char *output) 
{
    int length = strlen(input);
    int count;
    
    for (int i = 0; i < length; i++) 
	{
        count = 1;
        while (i < length - 1 && input[i] == input[i + 1]) //check characters two by two
        {
            count++;
            i++;
        }
        
        sprintf(output, "%d%c", count, input[i]);
        output += 2; //take 2 steps to add the next two chars
    }
    
    *output = '\0'; //add NULL to the end of the string
}

void decompress(const char *input, char *output) 
{
    int length = strlen(input);
    int count;
    
    for (int i = 0; i < length; i += 2) 
    {
        count = input[i] - '0'; //take the info of occurency
        
        for (int j = 0; j < count; j++) //decompress the compressed string and add to output string
        {
            *output = input[i + 1];
            output++;
        }
    }
    
    *output = '\0'; //add NULL to the end of the string
}
