#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int num;
    struct n* next;
}node;

void printListesi(node*);
void delete(node**);

int main()
{
    node* head = (node*)malloc(sizeof(node));

    head->num = 0;

    node* temp = head;

    int i;
    for(i = 0; i < 10; i++)
    {
        node* new = (node*)malloc(sizeof(node));
        temp->next = new;
        if(i == 0) new->num = 2;
        else new->num = i+1;
        new->next = NULL;
        temp = new;
    }

    printf("ilk hali:\n");
    printListesi(head);
    printf("\n");

    delete(&head);
    printf("ikinci hali:\n");
    printListesi(head);
    printf("\n");

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void printListesi(node* head)
{
    if(head == NULL) return;

    if(head->next != NULL) printf("%d->", head->num);
    else printf("%d", head->num);

    printListesi(head->next);
}

void delete(node** head)
{
    node* current = *head;
    node* temp;

    while (current != NULL)
    {
        if ((*head)->num % 2 == 0)
        {
            // Başlangıçtaki çift sayılı düğümleri sil
            temp = *head;
            *head = (*head)->next;
            free(temp);
            current = *head;
        }
        else if (current->next != NULL && current->next->num % 2 == 0)
        {
            // Diğer çift sayılı düğümleri sil
            temp = current->next;
            current->next = temp->next;
            free(temp);
        }
        else
        {
            current = current->next;
        }
    }
}