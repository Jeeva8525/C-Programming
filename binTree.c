// binary tree implementation
#include <stdio.h>
#include <stdlib.h>
typedef struct binTree
{
    int data;
    struct binTree *left;
    struct binTree *right;
} bin;
bin *createNode(int val)
{
    bin *newNode = (bin *)malloc(sizeof(bin));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void insert(bin **top, int val)
{
    if ((*top) == NULL)
    {
        (*top) = createNode(val);
        return;
    }
    if (val < (*top)->data)
    {
        if ((*top)->left == NULL)
        {
            (*top)->left = createNode(val);
            return;
        }
        insert(&(*top)->left, val);
    }
    else if (val > (*top)->data)
    {
        if ((*top)->right == NULL)
        {
            (*top)->right = createNode(val);
            return;
        }
        insert(&(*top)->right, val);
    }
}
void displayDLR(bin *root) // DLR fromat
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    displayDLR(root->left);
    displayDLR(root->right);
}
void displayLDR(bin *root) // DLR fromat
{
    if (root == NULL)
    {
        // printf("TEST1\n");
        return;
    }
    displayLDR(root->left);
    printf("%d ", root->data);
    displayLDR(root->right);
}
void displayLRD(bin *root) // DLR fromat
{
    if (root == NULL)
    {
        return;
    }
    displayLRD(root->left);
    displayLRD(root->right);
    printf("%d ", root->data);
}
int sum(bin *top)
{
    if (top == NULL)
        return 0;
    return sum(top->left) + top->data + sum(top->right);
}
int main()
{
    bin *root = NULL;
    int ch = 1, val;
    while (ch != 0)
    {
        printf("Do you want to continue: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter the value: ");
            scanf("%d", &val);
            insert(&root, val);
        }
    }
    printf("Displaying in DLR format: ");
    displayDLR(root);
    printf("\n");
    printf("Displaying in LDR format: ");
    displayLDR(root);
    printf("\n");
    printf("Displaying in LRD format: ");
    displayLRD(root);
    printf("\n");
    printf("The sum of all numbers in the binary tree is %d",sum(root));
}

/* bin *insertLeft(bin *top, int val)
{
    top->left = createNode(val);
    return top->left;
}
bin *insertRight(bin *top, int val)
{
    top->right = createNode(val);
    return top->right;
} */