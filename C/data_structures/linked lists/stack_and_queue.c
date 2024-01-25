#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct stu{
    char name[20];
    int age;
    int id;
    struct stu* next;
}student_t;


void addStu(student_t**, char*, int); //adds new student

student_t* findEndRec(student_t*); //finds the end of the list recursively
student_t* findEndIt(student_t*); //finds the end of the list iteratively

void printStusIt(student_t*); //prints students iteratively
void printStusRec(student_t*); //prints students recursively

void printStusRevRec(student_t*); //prints students reversely recursively
void printStusRevIt(student_t*); //prints students reversely iteratively

void remStuIt(student_t**, int); //removes student with given id iteratively
void remStuRec(student_t**, int); //removes student with given id recursively

void remStuIndIt(student_t**, int); //removes student with given index iteratively
void remStuIndRec(student_t**, int); //removes student with given index recursively

int countStusIt(student_t*); //counts students iteratively
int countStusRec(student_t*); //counts students recursively

void freeStusIt(student_t**); //frees the students linked list
void freeStusRec(student_t**);

void reverseListIt(student_t**); //reverses the list iteratively
void reverseListRec(student_t**, student_t*, student_t*); //reverses the list recursively


int main(void) 
{
    int age, sel, id, nOs; //nOs: num of students
    char name[20];
    student_t* first = NULL;
    student_t* current = NULL;
    
    printf("\nwelcome to Ziya's student database management system!\n");

    do{
        
        nOs = countStusRec(first);
        printf("\nnumber of students: %d\n", nOs);
        printf("enter operation:\n");
        printf("(1)add student\n");
        printf("(2)remove student with id\n");
        printf("(3)remove student with index\n");
        printf("(4)view all students\n");
        printf("(5)make students list reverse\n");
        printf("(6)view all students reversely\n");
        printf("(7)sort students by their age\n");
        printf("(8)exit\n");
        printf("> ");
        scanf("%d", &sel);

        switch(sel)
        {
            case 1:
                
                printf("enter the name of the student: ");
                scanf("%s", name);
                printf("enter the age of the student: ");
                scanf("%d", &age);
                addStu(&first, name, age);

                break;

            case 2:
                
                if(nOs == 0)
                {
                    printf("number of students is already 0!");
                    break;
                }

                printf("enter the id of the student: ");
                scanf("%d", &id);

                remStuIt(&first, id);

                break;

            case 3:
                
                if(nOs == 0)
                {
                    printf("number of students is already 0!");
                    break;
                }

                printf("enter the index of the student: ");
                scanf("%d", &id);

                remStuIndRec(&first, id);

                break;
            
            case 4:
                
                printStusIt(first);

                break;

            case 5:
                
                //reverseListIt(&first);

                current = first;
                reverseListRec(&first, NULL, current);

                break;

            case 6:
                
                printStusRevIt(first);

                break;

            case 7:
                
                sortList(first);

                break;

            case 8:

                freeStusIt(&first);
                printf("byesssss! ;)");
                return 0;
        }
            
    }while(sel > 0 && sel < 9);

    return 0;
}

void addStu(student_t** firstStu, char* name, int age)
{
    static int id = 1;

    student_t* stu = (student_t*)malloc(sizeof(student_t));
    student_t* lastStu;
    
    strcpy(stu->name, name);
    stu->age = age;
    stu->id = id++;
    stu->next = NULL;

    if(*firstStu == NULL) *firstStu = stu;

    else
    {
        lastStu = findEndRec(*firstStu);
        lastStu->next = stu;
    }
}

student_t* findEndRec(student_t* root)
{
    if(root == NULL) return NULL;
    else if(root->next == NULL) return root;
    else return findEndRec(root->next);
}

student_t* findEndIt(student_t* root)
{
    if(root == NULL) return NULL;
    for(; root->next != NULL; root = root->next){}
    return root;
}

void printStusIt(student_t* root)
{
    if(root == NULL)
    {
        printf("no student is added!\n");
        return;
    }
    
    for(; root != NULL; root = root->next)
    {
        printf("\n\nname: %s\n", root->name);
        printf("age: %d\n", root->age);
        printf("id: %d\n\n", root->id);
    }
}

void printStusRec(student_t* root)
{
    if(root == NULL) return;

    printf("\n\nname: %s\n", root->name);
    printf("age: %d\n", root->age);
    printf("id: %d\n\n", root->id);

    printStusRec(root->next);
}

void remStuIt(student_t** root, int id)
{
    if (*root == NULL) return;

    if ((*root)->id == id) //if the first node is the to be deleted node,
    {
        student_t* temp = *root; //temp points what *root points
        *root = (*root)->next; //take one step
        free(temp); //free root
        return;
    }

    while ((*root)->next != NULL && (*root)->next->id != id)
    {
        (*root) = (*root)->next;
    }

    student_t* temp = (*root)->next;
    (*root)->next = (*root)->next->next;
    free(temp);    
}

void remStuRec(student_t** root, int id)
{
    if (*root == NULL) return;

    if ((*root)->id == id) //if the node is the to be deleted node,
    {
        student_t* temp = *root; //temp points what *root points
        *root = (*root)->next; //take one step
        free(temp); //free root
        return;
    }

    remStuRec(&((*root)->next), id);    
}

int countStusIt(student_t* root)
{
    int numStu = 0;
    
    if(root == NULL) return 0;

    else if(root->next == NULL) return 1;

    else
    {
        numStu++;
        while(root->next != NULL)
        {
            numStu++;
            root = root->next;
        }

        return numStu;
    }
}

int countStusRec(student_t* root)
{
    if(root == NULL) return 0;

    if(root->next == NULL) return 1;

    else return 1 + countStusRec(root->next);
}

void remStuIndIt(student_t** root, int index)
{
    if((*root) == NULL) return;

    if(index == 0)
    {
        student_t* temp = *root;
        (*root) = (*root)->next;
        free(temp);
    }

    else
    {
        for(int i = 1; i < index-1 && (*root)->next != NULL; i++) (*root) = (*root)->next; //go to the node just before the indicated node

        student_t* temp = (*root)->next;
        (*root)->next = (*root)->next->next;
        free(temp); 
    }
}

void remStuIndRec(student_t** root, int index) 
{
    if (*root == NULL || index < 0) return; //If the list is empty or the index is negative, do nothing

    if (index == 0) //If the index is 0, remove the current node
    {
        student_t* temp = *root;
        (*root) = (*root)->next;
        free(temp);
        return;
    }

    remStuIndRec(&((*root)->next), index - 1); //Call the function on the next node with decremented index
}

void freeStusIt(student_t** root)
{
    while(*root != NULL)
    {
        student_t* temp = *root;
        *root = (*root)->next;
        free(temp);
    }
}

void freeStusRec(student_t** root)
{
    if (*root == NULL) return; //if root is null do not do anything
    
    if ((*root)->next != NULL) freeStusRec(&((*root)->next)); //free the rest of the list
    
    free(*root); //Free the current node and set the root to NULL
    *root = NULL;
}

void reverseListIt(student_t** root) 
{
    student_t* prev = NULL;
    student_t* current = *root;
    student_t* next = NULL;

    while (current != NULL) 
    {
        next = current->next; //store the next node
        current->next = prev; //reverse the current node 
        prev = current; //update the previous
        current = next; //take one step
    }

    *root = prev; //set the new beginning node
}

void reverseListRec(student_t** root, student_t* prev, student_t* current) 
{
    if (current == NULL) 
    {
        *root = prev; // Listenin sonuna gelindiğinde, yeni başlangıç düğümü olarak önceki düğümü kullan
        return;
    }

    student_t* next = current->next; //Bir sonraki düğümü geçici olarak sakla

    current->next = prev; // Geçerli düğümün next'ini ters çevir

    reverseListRec(root, current, next); // Recursive olarak bir sonraki düğüme geç
}

void printStusRevRec(student_t* root)
{
    if(root == NULL) return;

    printStusRevRec(root->next);

    printf("\n\nname: %s\n", root->name);
    printf("age: %d\n", root->age);
    printf("id: %d\n\n", root->id);
}

void printStusRevIt(student_t* root)
{
    if (root == NULL) return;
    
    student_t* current = root;
    student_t* prev = NULL;
    student_t* next = NULL;

    while(current != NULL) //reverse the list
    {
        next = current->next; 
        current->next = prev;
        prev = current;
        current = next;
    }

    current = prev; //print reversed list
    while(current != NULL)
    {
        printf("\n\nname: %s\n", current->name);
        printf("age: %d\n", current->age);
        printf("id: %d\n\n", current->id);
        current = current->next;
    }

    current = prev;
    prev = NULL;

    while(current != NULL) //reverse the reversed list
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
}

void printStusRevIterWithoutArray(student_t* root) {
    if (root == NULL) return;

    student_t* current = root;
    student_t* prev = NULL;
    student_t* next = NULL;

    // Bağlı listeyi ters sırayla yazdırmak için düğümleri tersine çevir
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Tersine çevrilen bağlı listeyi yazdır
    current = prev;
    while (current != NULL) {
        printf("\n\nname: %s\n", current->name);
        printf("age: %d\n", current->age);
        printf("id: %d\n\n", current->id);
        current = current->next;
    }

    // Bağlı listeyi tekrar eski haline getir
    current = prev;
    prev = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
}