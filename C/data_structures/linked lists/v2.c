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

int main() {
    int movieCounter, sel;
    char movieToDelete[50];
    movie_t* head = NULL;
    movie_t* current = NULL;

    do {
        printf("Enter an operation number\n1 to add movie,\n2 to delete a movie\n-> ");
        scanf("%d", &sel);

        switch (sel) {
            case 1:
                printf("How many movies do you want to add? ");
                scanf("%d", &movieCounter);

                // Buffer temizleme işlemi
                clearInputBuffer();

                for (int i = 0; i < movieCounter; i++) {
                    movie_t* newMovie = createMovie();

                    if (head == NULL) {
                        head = newMovie;
                        current = newMovie;
                    } else {
                        current->nextMovie = newMovie;
                        current = newMovie;
                    }
                }
                break;

            case 2:
                printf("Enter the name of the movie you want to delete: ");
                scanf("%s", movieToDelete);
                deleteMovie(&head, movieToDelete);
                break;
        }

        // Print the linked list
        printf("\nLinked List of Movies:\n");
        current = head;

        while (current != NULL) {
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

movie_t* createMovie() {
    movie_t* newMovie = (movie_t*)malloc(sizeof(movie_t));

    if (newMovie == NULL) {
        printf("Unsuccessful memory allocation\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter movie name: ");
    fgets(newMovie->name, sizeof(newMovie->name), stdin);
    newMovie->name[strcspn(newMovie->name, "\n")] = '\0';
    
    printf("Enter director name: ");
    fgets(newMovie->director, sizeof(newMovie->director), stdin);
    newMovie->director[strcspn(newMovie->director, "\n")] = '\0';

    printf("Enter movie type: ");
    fgets(newMovie->type, sizeof(newMovie->type), stdin);
    newMovie->type[strcspn(newMovie->type, "\n")] = '\0';

    printf("Enter movie duration: ");
    scanf("%lf", &newMovie->duration);

    // Buffer temizleme işlemi
    clearInputBuffer();

    newMovie->nextMovie = NULL;

    return newMovie;
}

void deleteMovie(movie_t** head, const char* movieName) {
    if (*head == NULL) {
        printf("List is empty, no movie to delete.\n");
        return;
    }

    movie_t* temp = *head;

    if (strcmp(temp->name, movieName) == 0) {
        *head = temp->nextMovie;
        free(temp);
        printf("%s movie is deleted\n", movieName);
        return;
    }

    movie_t* previous = NULL;
    while (temp != NULL && strcmp(temp->name, movieName) != 0) {
        previous = temp;
        temp = temp->nextMovie;
    }

    if (temp == NULL) {
        printf("%s movie could not be found\n", movieName);
        return;
    }

    previous->nextMovie = temp->nextMovie;
    free(temp);
    printf("%s movie is deleted\n", movieName);
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
