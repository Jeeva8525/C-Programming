// Deletion of a binary search tree's node
#include <stdio.h>
#include <stdlib.h>
typedef struct binTree
{
    int data;
    struct binTree *left, *right;
} bin;
int spaceCounter = 5;
void printBinaryTree(bin *root, int space)
{
    if (NULL == root)
    {
        return;
    }
    space += spaceCounter;
    printBinaryTree(root->right, space);
    for (int x = 5; x < space; x++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);
    // printf("\n");
    printBinaryTree(root->left, space);
}
bin *createNode(int val)
{
    bin *newNode = (bin *)malloc(sizeof(bin));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}
bin *getSuccessor(bin *root)
{
    root = root->right;
    while (root->left)
    {
        root = root->left;
    }
    return root;
}
void deleteNode(bin **root, int val)
{
    if (NULL == *root)
    {
        printf("No elements to delete\n");
        return;
    }
    else if (val > (*root)->data)
    {
        deleteNode(&(*root)->right, val);
    }
    else if (val < (*root)->data)
    {
        deleteNode(&(*root)->left, val);
    }
    else if ((*root)->left && (*root)->right)
    {
        bin *temp = getSuccessor(*root);
        (*root)->data = temp->data;
        deleteNode(&(*root)->right,temp->data);
    }
    else
    {
        bin *temp = *root;
        if(NULL == (*root)->right)
        {
            *root = (*root)->left;
        }
        else if(NULL == (*root)->left)
        {
            *root = (*root)->right;
        }
        free(temp);
    }
}
void BSTinsert(bin **root, int val)
{
    if ((*root) == NULL)
    {
        (*root) = createNode(val);
        return;
    }
    if (val == (*root)->data)
    {
        return;
    }
    else if (val < (*root)->data)
    {
        BSTinsert(&(*root)->left, val);
    }
    else
    {
        BSTinsert(&(*root)->right, val);
    }
}
int main()
{
    bin *root = NULL;
    int ch, val;
    printf("1 : Add an element to the Binary Search Tree\n2 : Delete an element from the tree\n0 : exit\n");
    do
    {
        printf("Choice: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter the number: ");
            scanf("%d", &val);
            BSTinsert(&root, val);
        }
        else if(2 == ch)
        {
            printf("Enter the number: ");
            scanf("%d",&val);
            deleteNode(&root,val);
            // printf("Deleted\n");
        }
        else
        {
            printf("The final Tree is\n\n");
            ch = 0;
        }
        printBinaryTree(root, 0);
    } while (ch != 0);
}