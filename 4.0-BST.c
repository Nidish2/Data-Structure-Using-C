#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} *Node; // Direct initialisation

// typedef struct node *Node;

Node get_node()
{
    Node nn = (Node)malloc(sizeof(struct node));
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

Node insert(int data, Node root)
{
    Node temp = get_node();
    if (temp == NULL)
    {
        return NULL;
    }

    if (root == NULL)
    {
        temp->data = data;
        return temp;
    }

    if (data < root->data)
    {
        root->left = insert(data, root->left);
    }
    else
    {
        root->right = insert(data, root->right);
    }
    return root;
}

void search(Node root, int key)
{
    if (root == NULL)
    {
        printf("Element not found\n");
        return;
    }
    if (root->data == key)
    {
        printf("Element found\n");
        return;
    }
    if (key < root->data)
    {
        search(root->left, key);
    }
    else
    {
        search(root->right, key);
    }
}
void min(Node root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        min(root->left);
    }
    else
    {
        printf("Minimum element is %d\n", root->data);
    }
}

void max(Node root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->right != NULL)
    {
        max(root->right);
    }
    else
    {
        printf("Maximum element is %d\n", root->data);
    }
}

void inorder(Node root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d->", root->data);
    inorder(root->right);
}

void postorder(Node root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d->", root->data);
}

void preorder(Node root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d->", root->data);
    preorder(root->left);
    preorder(root->right);
}

void delete_tree(Node root)
{
    if (root == NULL)
    {
        return;
    }
    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
}

int main()
{
    Node root = NULL;
    int op, data, key;

    while (1)
    {
        printf("1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Delete\n6. Find Min\n7. Find Max\n8. Search Element\n9. Exit\nEnter option: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insert(data, root); // imp;
            break;

        case 2:
            if (root == NULL)
            {
                printf("Tree is empty\n");
            }
            else
            {
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
            }
            break;

        case 3:
            if (root == NULL)
            {
                printf("Tree is empty\n");
            }
            else
            {
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
            }
            break;

        case 4:
            if (root == NULL)
            {
                printf("Tree is empty\n");
            }
            else
            {
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
            }
            break;

        case 5:
            if (root == NULL)
            {
                printf("Tree is empty\n");
            }
            else
            {
                delete_tree(root);
                root = NULL;
                printf("Tree deleted\n");
            }
            break;
        case 6:
            min(root);
            break;

        case 7:
            max(root);
            break;

        case 8:
            printf("Enter Element to search: ");
            scanf("%d", &key);
            search(root, key);
            break;

        case 9:
            exit(0);

        default:
            printf("Invalid option\n");
        }
    }

    return 0;
}
