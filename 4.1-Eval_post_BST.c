#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

typedef struct node *Node;
Node root = NULL;

Node get_node(char data)
{
    Node nn = (Node)malloc(sizeof(struct node));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    if (nn == NULL)
        printf("Out of memory\n");
    else
    {
        return nn;
    }
}

Node stack[50];
int top = -1;

void push(Node x)
{
    stack[++top] = x;
}

Node pop()
{
    return stack[top--];
}

void preorder(Node root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c -> \t", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%c -> \t", root->data);
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
    printf("%c -> \t", root->data);
}

int main()
{
    char *e, exp[40];
    printf("Enter the postfix expression : ");
    scanf("%s", exp);
    e = exp;

    while (*e != '\0')
    {
        if (isalnum(*e))
        {
            Node nn = get_node(*e);
            push(nn);
        }

        else
        {
            Node cur = get_node(*e);
            cur->right = pop();
            cur->left = pop();
            push(cur);
        }
        e++;
    }
    root = stack[top];
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    return 0;
}