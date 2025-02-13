#include <stdio.h>
#include <stdlib.h>
struct term
{
    int cons;
    int powx;
    int powy;
    struct term *next;
};

struct term *start1 = NULL, *start2 = NULL, *start3 = NULL, *current3 = NULL;

void poly1(int cons, int powx, int powy)
{
    struct term *p1 = (struct term *)malloc(sizeof(struct term));
    p1->cons = cons;
    p1->powx = powx;
    p1->powy = powy;
    p1->next = NULL;

    if (start1 == NULL)
    {
        start1 = p1;
    }
    else
    {
        struct term *temp = start1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p1;
    }
}

void poly2(int cons, int powx, int powy)
{
    struct term *p2 = (struct term *)malloc(sizeof(struct term));
    p2->cons = cons;
    p2->powx = powx;
    p2->powy = powy;
    p2->next = NULL;

    if (start2 == NULL)
    {
        start2 = p2;
    }
    else
    {
        struct term *temp = start2;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p2;
    }
}

void add()
{
    start3 = NULL;
    struct term *temp1 = start1, *temp2 = start2;

    while (temp1 != NULL || temp2 != NULL)
    {
        struct term *temp3 = (struct term *)malloc(sizeof(struct term));
        temp3->next = NULL;

        if (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->powx == temp2->powx && temp1->powy == temp2->powy)
            {
                temp3->cons = temp1->cons + temp2->cons;
                temp3->powx = temp1->powx;
                temp3->powy = temp1->powy;

                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if ((temp1->powx > temp2->powx) || ((temp1->powx == temp2->powx) && (temp1->powy > temp2->powy)))
            {
                temp3->cons = temp1->cons;
                temp3->powx = temp1->powx;
                temp3->powy = temp1->powy;

                temp1 = temp1->next;
            }
            else
            {
                temp3->cons = temp2->cons;
                temp3->powx = temp2->powx;
                temp3->powy = temp2->powy;

                temp2 = temp2->next;
            }
        }
        else if (temp1 != NULL)
        {
            temp3->cons = temp1->cons;
            temp3->powx = temp1->powx;
            temp3->powy = temp1->powy;

            temp1 = temp1->next;
        }
        else if (temp2 != NULL)
        {
            temp3->cons = temp2->cons;
            temp3->powx = temp2->powx;
            temp3->powy = temp2->powy;

            temp2 = temp2->next;
        }

        if (start3 == NULL)
        {
            start3 = temp3;
            current3 = temp3;
        }
        else
        {
            current3->next = temp3;
            current3 = temp3;
        }
    }
}

void display()
{
    struct term *temp = start3;
    if (start3 == NULL)
    {
        printf("Single linked list is empty\n");
    }
    else
    {
        printf("The final added polynomial is: ");
        while (temp != NULL)
        {
            printf("%d*x^%d*y^%d + ", temp->cons, temp->powx, temp->powy);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main()
{
    int max1, max2, i = 1, j = 1, cons, powx, powy;
    printf("Enter the total terms in first and second polynomial : ");
    scanf("%d %d", &max1, &max2);
    while (i <= max1)
    {
        printf("Enter the %dth term's constant,powx,powy of first polynomial : ", i);
        scanf("%d %d %d", &cons, &powx, &powy);
        poly1(cons, powx, powy);
        i++;
    }
    while (j <= max2)
    {
        printf("Enter the %dth term's constant,powx,powy of second polynomial : ", j);
        scanf("%d %d %d", &cons, &powx, &powy);
        poly2(cons, powx, powy);
        j++;
    }
    add();
    display();
}


/*
#include <stdio.h>
#include <stdlib.h>

typedef struct term {
    int cons, powx, powy;
    struct term *next;
} Term;

Term* createTerm(int cons, int powx, int powy) {
    Term *newTerm = (Term *)malloc(sizeof(Term));
    newTerm->cons = cons;
    newTerm->powx = powx;
    newTerm->powy = powy;
    newTerm->next = NULL;
    return newTerm;
}

Term* addPolynomials(Term *poly1, Term *poly2) {
    Term *result = NULL, *temp = NULL;

    while (poly1 && poly2) {
        Term *newNode = createTerm(0, 0, 0);

        if (poly1->powx == poly2->powx && poly1->powy == poly2->powy) {
            newNode->cons = poly1->cons + poly2->cons;
            newNode->powx = poly1->powx;
            newNode->powy = poly1->powy;
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if ((poly1->powx > poly2->powx) || (poly1->powx == poly2->powx && poly1->powy > poly2->powy)) {
            newNode->cons = poly1->cons;
            newNode->powx = poly1->powx;
            newNode->powy = poly1->powy;
            poly1 = poly1->next;
        } else {
            newNode->cons = poly2->cons;
            newNode->powx = poly2->powx;
            newNode->powy = poly2->powy;
            poly2 = poly2->next;
        }

        if (!result) {
            result = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    while (poly1) {
        Term *newNode = createTerm(poly1->cons, poly1->powx, poly1->powy);
        if (!result) {
            result = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
        poly1 = poly1->next;
    }

    while (poly2) {
        Term *newNode = createTerm(poly2->cons, poly2->powx, poly2->powy);
        if (!result) {
            result = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
        poly2 = poly2->next;
    }

    return result;
}

void display(Term *poly) {
    if (!poly) {
        printf("Polynomial is empty\n");
        return;
    }
    printf("The final added polynomial is: ");
    while (poly != NULL) {
        printf("%d*x^%d*y^%d + ", poly->cons, poly->powx, poly->powy);
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    Term *start1 = NULL, *start2 = NULL;
    int max1, max2, i = 1, j = 1, cons, powx, powy;

    printf("Enter the total terms in first and second polynomial: ");
    scanf("%d %d", &max1, &max2);

    printf("Enter the terms of first polynomial (constant, powx, powy):\n");
    while (i <= max1) {
        scanf("%d %d %d", &cons, &powx, &powy);
        Term *newTerm = createTerm(cons, powx, powy);
        if (!start1) {
            start1 = newTerm;
        } else {
            Term *temp = start1;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newTerm;
        }
        i++;
    }

    printf("Enter the terms of second polynomial (constant, powx, powy):\n");
    while (j <= max2) {
        scanf("%d %d %d", &cons, &powx, &powy);
        Term *newTerm = createTerm(cons, powx, powy);
        if (!start2) {
            start2 = newTerm;
        } else {
            Term *temp = start2;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newTerm;
        }
        j++;
    }

    Term *result = addPolynomials(start1, start2);
    display(result);

    // Free allocated memory
    while (start1) {
        Term *temp = start1;
        start1 = start1->next;
        free(temp);
    }
    while (start2) {
        Term *temp = start2;
        start2 = start2->next;
        free(temp);
    }
    while (result) {
        Term *temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}


*/