/* 
Prints the elements in the same level and included finding the height of the tree
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct binTree
{
    int data;
    struct binTree *left, *right;
} bin;
void printLevel(bin *root, int level)
{
    if (root == NULL)
    {
        printf(" ");
        return;
    }
    if (level == 1)
    {
        printf("%d ", root->data);
        return;
    }
    printLevel(root->left, level - 1);
    printLevel(root->right, level - 1);
}

int heightOfTree(bin *root)
{
    if(NULL == root)
    {
        return 0;
    }
    int leftHeight = heightOfTree(root->left)+1;
    int rightHeight = heightOfTree(root->right)+1;
    return leftHeight>rightHeight?leftHeight:rightHeight; //max of both
} 

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
        else
        {
            ch = 0;
        }
        printBinaryTree(root, 0);
    } while (ch != 0);
    int lv=1;
    printf("Enter the level number to print the elements in the level: ");
    scanf("%d",&lv);
    printf("The elements in the level are \n");
    printLevel(root,lv);

    printf("\nThe height of the tree is %d",heightOfTree(root));
}