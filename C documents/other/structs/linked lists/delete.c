// Düğümü listeden silen fonksiyon
void deleteNode(movie_t** head, const char* movieName) {
    // Liste boşsa veya silinecek film bulunmuyorsa çık
    if (*head == NULL) {
        printf("Liste bos, silinecek film yok.\n");
        return;
    }

    // İlk düğümü tutan geçici bir değişken
    movie_t* temp = *head;

    // Eğer ilk düğüm silinecek filmse
    if (strcmp(temp->name, movieName) == 0) {
        *head = temp->nextMovie;
        free(temp);
        printf("%s filmi silindi.\n", movieName);
        return;
    }

    // Silinecek filmi bulmak için geçici ve önceki düğümleri kullan
    movie_t* previous = NULL;
    while (temp != NULL && strcmp(temp->name, movieName) != 0) {
        previous = temp;
        temp = temp->nextMovie;
    }

    // Film bulunamadıysa
    if (temp == NULL) {
        printf("%s filmi bulunamadi.\n", movieName);
        return;
    }

    // Film bulundu, bağlantıları düzenle ve belleği serbest bırak
    previous->nextMovie = temp->nextMovie;
    free(temp);
    printf("%s filmi silindi.\n", movieName);
}

// main fonksiyonunun devamı...

int main() {
    // Önceki kodlar...

    // Örnek olarak bir film silelim (silinmek istenen filmin adını girebilirsiniz)
    char movieToDelete[50];
    printf("\nEnter the name of the movie to delete: ");
    scanf("%s", movieToDelete);

    // Düğümü sil
    deleteNode(&head, movieToDelete);

    // Silindikten sonraki linked listi yazdır
    printf("\nLinked List after deletion:\n");
    current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Director: %s\n", current->director);
        printf("Type: %s\n", current->type);
        printf("Duration: %.2f\n", current->duration);
        printf("\n");
        current = current->nextMovie;
    }

    // Geri kalan kodlar...
    
    return 0;
}
