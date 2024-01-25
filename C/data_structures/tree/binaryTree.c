#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int age;
    struct n* rightChild;
    struct n* leftChild;
}treeNode_t;

treeNode_t* createNode(int);
treeNode_t* insertNode(treeNode_t*, int);
treeNode_t* deleteNode(treeNode_t*, int);
treeNode_t* minValNode(treeNode_t*); //finds the min val node of the right subtree
int depthTreeRec(treeNode_t*);
int depthTreeIt(treeNode_t*);
int depthNodeRec(treeNode_t*, int);
int depthNodeIt(treeNode_t*, int);
int heightNode(treeNode_t*, int);
void printTree(treeNode_t*, int);

int main(void)
{
    treeNode_t* root = NULL;
    int age;

    for(scanf("%d", &age); age > 0; scanf("%d", &age))
    {
        root = insertNode(root, age);
    }

    printTree(root, 1);
    printf("\n");

    /*printf("enter the age to delete: ");
    scanf("%d", &age);

    root = deleteNode(root, age);

    printf("after deleting age %d: ", age);
    printTree(root, 1);
    printf("\n");

    printf("enter the age to add: ");
    scanf("%d", &age);

    root = insertNode(root, age);

    printf("after adding age %d: ", age);
    printTree(root, 1);
    printf("\n");*/

    printf("depth of the tree: %d\n", depthTreeIt(root));
    printf("enter a age to find its depth and height: ");
    scanf("%d", &age);
    printf("depth of the age %d is: %d\n", age, depthNodeRec(root, age));
    printf("height of the age %d is: %d\n", age, heightNode(root, age));

    return 0;
}

treeNode_t* createNode(int age)
{
    treeNode_t* child = (treeNode_t*)malloc(sizeof(treeNode_t));

    child->age = age;
    child->rightChild = NULL;
    child->leftChild = NULL;

    return child;
}

treeNode_t* insertNode(treeNode_t* root, int age)
{
    if(root == NULL) return createNode(age);

    else
    {
        if(age < root->age) 
            root->leftChild = insertNode(root->leftChild, age);
            
        else if(age > root->age) 
            root->rightChild = insertNode(root->rightChild, age);
    }

    return root;
}

treeNode_t* deleteNode(treeNode_t* root, int toBeDeletedAge)
{
    if(root == NULL) return root; //if tree is empty, return

    if(toBeDeletedAge < root->age) //if the to be deleted key is less than the age of the current node,
        root->leftChild = deleteNode(root->leftChild, toBeDeletedAge); //recur left

    else if(toBeDeletedAge > root->age) //if the to be deleted key is greater than the age of the current node,
        root->rightChild = deleteNode(root->rightChild, toBeDeletedAge); //recur right

    else //if found
    {
        treeNode_t* temp;
        
        //if to be deleted node has only one child
        if(root->leftChild == NULL) //if node does not have left child, right child is need to be conserved
        {
            temp = root->rightChild;
            free(root);
            return temp;
        }

        //if to be deleted node has only one child
        else if(root->rightChild == NULL) //if node does not have right child, left child is need to be conserved
        {
            temp = root->leftChild;
            free(root);
            return temp;
        }

        else //if none of the child ptrs are null, that means node has two children
        { //take the min val node of the right subtree to the place of to be deleted node
            temp = minValNode(root->rightChild);
            root->age = temp->age;
            root->rightChild = deleteNode(root->rightChild, temp->age); //remove the min val node from its original place
        }
    }

    return root;
}

treeNode_t* minValNode(treeNode_t* root)
{
    treeNode_t* current = root;

    while(current->leftChild != NULL) 
        current = current->leftChild;

    return current;
}

void printTree(treeNode_t* root, int order)
{
    if(root == NULL) return;
    
    if(order == 1)
    {
        printTree(root->leftChild, 1);
        printf("(%d)->", root->age);
        printTree(root->rightChild, 1);
    }

    else if(order == 2)
    {
        printTree(root->rightChild, 2);
        printf("(%d)->", root->age);
        printTree(root->leftChild, 2);
    } 
}

int depthTreeRec(treeNode_t* root)
{
    if (root == NULL) 
        return 0;

    int leftDepth = depthTreeRec(root->leftChild);
    int rightDepth = depthTreeRec(root->rightChild);

    if (leftDepth > rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
}

int depthTreeIt(treeNode_t* root)
{
    if (root == NULL) 
        return 0;

    int leftDepth = 0;
    int rightDepth = 0;
    
    treeNode_t* curr = root;
    while(curr->leftChild != NULL)
    {
        leftDepth++;
        curr = curr->leftChild;
    }

    curr = root;
    while(curr->rightChild != NULL)
    {
        rightDepth++;
        curr = curr->rightChild;
    }

    if (leftDepth > rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
}

int depthNodeRec(treeNode_t* root, int age)
{
    if(root == NULL) return -1;

    else
    {
        int depth = -1;

        if((root->age == age) 
        || (depth = depthNodeRec(root->leftChild, age)) >= 0 
        || (depth = depthNodeRec(root->rightChild, age)) >= 0)
        {
            return depth + 1;
        }
        
        else return depth;
    }
}

int heightNode(treeNode_t* root, int age)
{
    if(root == NULL) return -1;

    else
    {
        int heightL, heightR, heightCur; //heights of the left tree, right tree, current node

        heightL = heightNode(root->leftChild, age);
        heightR = heightNode(root->rightChild, age);

        if(heightL > heightR) 
            heightCur = heightL+1;
        
        else 
            heightCur = heightR+1;

        if(root->age == age) 
            return heightCur;

        return heightCur;
    }
}
