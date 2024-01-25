#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary search tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int); //Function to create a new node with a given key
struct TreeNode* insertNode(struct TreeNode*, int); //Function to insert a key into a binary search tree
struct TreeNode* minValueNode(struct TreeNode*); //Function to find the node with the minimum value in a tree
struct TreeNode* deleteNode(struct TreeNode*, int); //Function to delete a key from a binary search tree
void inOrderTraversal(struct TreeNode*); //Function to perform an in-order traversal of the binary search tree
int depthTree(struct TreeNode* root);

int main() 
{
    struct TreeNode* root = NULL;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};
    int arrLen = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < arrLen; i++) root = insertNode(root, keys[i]);

    printf("In-order traversal of the binary search tree: ");
    inOrderTraversal(root);
    printf("\n");

    int keyToDelete = 30;
    root = deleteNode(root, keyToDelete);
    printf("After deleting %d, in-order traversal: ", keyToDelete);
    inOrderTraversal(root);
    printf("\n");

    printf("depth of the tree: %d\n", depthTree(root));

    return 0;
}

struct TreeNode* createNode(int key) 
{
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, int key) 
{
    // If the tree is empty, return a new node
    if (root == NULL)
        return createNode(key);

    // Otherwise, recur down the tree
    if (key < root->data)
        root->left = insertNode(root->left, key);
    else if (key > root->data)
        root->right = insertNode(root->right, key);

    // Return the (unchanged) node pointer
    return root;
}

struct TreeNode* minValueNode(struct TreeNode* node) 
{
    struct TreeNode* current = node;
    // Find the leftmost leaf
    while (current->left != NULL) current = current->left;
    return current;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) 
{
    // Base case: if the tree is empty
    if (root == NULL) return root;

    // Recur down the tree
    if (key < root->data) root->left = deleteNode(root->left, key);
    
    else if (key > root->data) root->right = deleteNode(root->right, key);
    
    else //if found
    {
        // Node with only one child or no child
        if (root->left == NULL) 
        {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } 
        
        else if (root->right == NULL) 
        {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct TreeNode* temp = minValueNode(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inOrderTraversal(struct TreeNode* root) 
{
    if (root != NULL) 
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int depthTree(struct TreeNode* root)
{
    if (root == NULL) 
        return 0;

    int leftDepth = depthTree(root->left);
    int rightDepth = depthTree(root->right);

    if (leftDepth > rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
}