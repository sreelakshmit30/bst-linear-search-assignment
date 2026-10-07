#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char id[20];
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(char id[])
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->id, id);
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *root, char id[])
{
    if (root == NULL)
    {
        return createNode(id);
    }

    if (strcmp(id, root->id) < 0)
    {
        root->left = insert(root->left, id);
    }
    else
    {
        root->right = insert(root->right, id);
    }

    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s ", root->id);
        inorder(root->right);
    }
}

int bstSearch(struct Node *root, char key[], int *comparisons)
{
    while (root != NULL)
    {
        (*comparisons)++;

        if (strcmp(key, root->id) == 0)
        {
            return 1;
        }
        else if (strcmp(key, root->id) < 0)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    return 0;
}

int linearSearch(char ids[][20], int n, char key[], int *comparisons)
{
    int i;

    for (i = 0; i < n; i++)
    {
        (*comparisons)++;

        if (strcmp(ids[i], key) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    struct Node *root = NULL;

    char ids[8][20] =
    {
        "A102",
        "A25",
        "A7",
        "B100",
        "B12",
        "A120",
        "B3",
        "A45"
    };

    char key[20];

    int i;
    int bstComparisons = 0;
    int linearComparisons = 0;

    /* Insert identification numbers into BST */

    for (i = 0; i < 8; i++)
    {
        root = insert(root, ids[i]);
    }

    /* Display inorder traversal */

    printf("Inorder Traversal:\n");

    inorder(root);

    printf("\n");

    /* Input search key */

    printf("\nEnter identification number to search: ");
    scanf("%s", key);

    /* BST Search */

    if (bstSearch(root, key, &bstComparisons))
    {
        printf("\nBST Search: Found");
    }
    else
    {
        printf("\nBST Search: Not Found");
    }

    /* Linear Search */

    if (linearSearch(ids, 8, key, &linearComparisons))
    {
        printf("\nLinear Search: Found");
    }
    else
    {
        printf("\nLinear Search: Not Found");
    }

    /* Display comparisons */

    printf("\n\nBST Comparisons: %d", bstComparisons);
    printf("\nLinear Search Comparisons: %d\n", linearComparisons);

    return 0;
}
