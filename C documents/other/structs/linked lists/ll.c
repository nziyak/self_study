#include <stdio.h>
#include<stdlib.h>

typedef struct movie{
    
    double duration;
    
    char name[50], 
         director[50],
         type[50];
    
    struct movie* nextMovie;

}movie_t;

int main()
{
    //movie_t* film1 = (movie_t*)malloc(sizeof(movie_t));
    int movieCounter;

    do{
        printf("how many movies do you want to add? ");
        scanf("%d", &movieCounter);

        movie_t* head = NULL;

        for(int i = 0; i < movieCounter; i++)
        {
            movie_t* newMovie = addMovie();

            newMovie->nextMovie = 
        }

    }while(movieCounter > 0)
}