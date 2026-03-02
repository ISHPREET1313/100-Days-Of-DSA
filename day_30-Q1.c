/*
Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef;
    int exp;
    struct node *next;
};

struct node* insert(struct node *head, int c, int e);
void display(struct node *head);

struct node* insert(struct node *head, int c, int e) {
    struct node *new = malloc(sizeof(struct node));
    new->coef = c;
    new->exp = e;
    new->next = NULL;

    if (head == NULL || head->exp < e) {
        new->next = head;
        return new;
    }

    struct node *temp = head;
    while (temp->next && temp->next->exp > e)
        temp = temp->next;

    if (temp->next && temp->next->exp == e) {
        temp->next->coef += c;
        free(new);
    } else {
        new->next = temp->next;
        temp->next = new;
    }
    return head;
}

void display(struct node *head) {
    if (!head) {
        printf("0\n");
        return;
    }

    while (head) {
        printf("%dx^%d", head->coef, head->exp);
        if (head->next) printf(" + ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *p1 = NULL;
    int choice, n, c, e;
    p1 = NULL;
    printf("Number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Coef & Exp: ");
        scanf("%d%d", &c, &e);
        p1 = insert(p1, c, e);
    }
    display(p1);
    return 0;
}
