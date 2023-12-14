#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct movie {
    double duration;
    char name[50], director[50], type[50];
    struct movie* nextMovie;
} movie_t;

movie_t* createMovie();
void deleteMovie(movie_t** head, const char* movieName);
void clearInputBuffer();

/*
    INSERT(add a new record into a linked list):
    
    dynamically allocate space for a new record
    
    IF no records exist in the list:
        set the address field of the new record to NULL
        set the address in the first record pointer to the address of the newly created record
        
    ELSE (we are working with an existing list):
        locate where this new record should be placed
        
        IF this record should be the new first record in the list
            copy the current contents of the first record pointer into the address field of the newly created record
            set the address in the first record pointer to the address of the newly created record
            
        ELSE
            copy the address in the prior record's address member into the address field of the newly created record
            set the address field of the prior record's address member to the address of the newly created record
        ENDIF
    ENDIF
*/

/*
    DELETE(delete a record from the linked list):

    IF no records exist in the list:
        PRINT "Error: Cannot delete from an empty list."
        
    ELSE (we are working with an existing list):
        locate the node to delete
        
        IF the node to delete is the first record in the list:
            set the address in the first record pointer to the address of the next node
            free the memory allocated for the node to delete
            
        ELSE
            locate the prior node to the one to delete
            
            set the address field of the prior node's address member to the address of the next node
            free the memory allocated for the node to delete
        ENDIF
    ENDIF

*/

int main() 
{
    int movieCounter, sel;
    char movieToDelete[50];
    movie_t* head = NULL;
    movie_t* current = NULL;

    do {
            
        printf("enter an operation number\n1 to add movie,\n2 to delete a movie\n-> ");
        scanf("%d", &sel);

        switch(sel)
        {
            case 1:

                printf("How many movies do you want to add? ");
                scanf("%d", &movieCounter);
                flush(stdin);

                for (int i = 0; i < movieCounter; i++) 
                {
                    movie_t* newMovie = createMovie();

                    if (head == NULL) 
                    {
                        // If no records exist in the list
                        head = newMovie;
                        current = newMovie;
                    } 
                    
                    else 
                    {
                        // Working with an existing list
                        // Insert the new record at the end of the list
                        current->nextMovie = newMovie; //connect the current node to the new node
                        current = newMovie; //make the current to the new node
                    }
                }

                break;

            case 2:

                printf("enter the name of the movie you want to delete: ");
                scanf("%s", movieToDelete);

                deleteMovie(&head, movieToDelete);

                break;
        }

        // Print the linked list
        printf("\nLinked List of Movies:\n");
        
        current = head;
        
        while (current != NULL) 
        {
            printf("Name: %s\n", current->name);
            printf("Director: %s\n", current->director);
            printf("Type: %s\n", current->type);
            printf("Duration: %.2f\n", current->duration);
            printf("\n");
            current = current->nextMovie;
        }
    
    } while (movieCounter > 0);

    return 0;
}

//creates a new node in type of movie_t
movie_t* createMovie() 
{
    movie_t* newMovie = (movie_t*)malloc(sizeof(movie_t));

    if (newMovie == NULL) 
    {
        printf("unsuccesful memory allocation\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter movie name: ");
    fgets(newMovie->name, sizeof(newMovie->name), stdin); //takes size of newMovie->name bytes of input from standart input(keyboard) to newMovie->name string
    newMovie->name[strcspn(newMovie->name, "\n")] = '\0'; //replaces \n with \0 character. (a null char is required at the end of strings)
    //printf("test");


    clearInputBuffer(); 

    printf("Enter director name: ");
    fgets(newMovie->director, sizeof(newMovie->director), stdin);
    newMovie->director[strcspn(newMovie->director, "\n")] = '\0'; 
    
    clearInputBuffer(); 

    printf("Enter movie type: ");
    fgets(newMovie->type, sizeof(newMovie->type), stdin); 
    newMovie->type[strcspn(newMovie->type, "\n")] = '\0';

    clearInputBuffer();

    printf("Enter movie duration: ");
    scanf("%lf", &newMovie->duration);

    newMovie->nextMovie = NULL;

    return newMovie;
}

void deleteMovie(movie_t** head, const char* movieName) 
{
    //if list is empty or there is no movie to be deleted, quit
    if (*head == NULL) 
    {
        printf("Liste bos, silinecek film yok.\n");
        return;
    }

    movie_t* temp = *head; //a temp ptr holds the first node

    //if the first node is the to be deleted node,
    if (strcmp(temp->name, movieName) == 0) 
    {
        *head = temp->nextMovie; //new head node is the next node
        free(temp); //free the head
        printf("%s movie is deleted\n", movieName);
        return;
    }

    //use the temp and previous nodes to find the to be deleted movie
    movie_t* previous = NULL;
    while (temp != NULL && strcmp(temp->name, movieName) != 0) 
    {
        previous = temp; //we use previous to do not miss the current(temp) node. 
        temp = temp->nextMovie; //after that we use temp to look at the next node. 
    }

    //if the movie could not been found
    if (temp == NULL) 
    {
        printf("%s movie could not been found\n", movieName);
        return;
    }

    //to be deleted movie is found, rearrange the connections and free the memory of node
    previous->nextMovie = temp->nextMovie; //before deleting the to be deleted node, we need to connect previous node to next of the next node
    free(temp); //then free the to be deleted node
    printf("%s movie is found\n", movieName);
}

void clearInputBuffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}