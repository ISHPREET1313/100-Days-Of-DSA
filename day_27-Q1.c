/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* intersectPoint(struct Node* head1, struct Node* head2) {
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;
    if (!ptr1 || !ptr2) return NULL;
    while (ptr1 != ptr2) {
        ptr1 = (ptr1 != NULL) ? ptr1->next : head2;
        ptr2 = (ptr2 != NULL) ? ptr2->next : head1;
    }
    return ptr1;
}
struct Node* findNode(struct Node* head, int value) {
    while (head) {
        if (head->data == value)
            return head;
        head = head->next;
    }
    return NULL;
}

int main() {
    int n, m, x;
    struct Node *head1 = NULL, *ptr = NULL;
    struct Node *head2 = NULL, *ptr2 = NULL;
    struct Node* temp = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        temp = createNode(x);
        if (!head1)
            head1 = temp;
        else
            ptr->next = temp;
        ptr = temp;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        struct Node* existing = findNode(head1, x);
        if (existing) {
            temp = existing;
        } else {
            temp = createNode(x);
        }
        if (!head2)
            head2 = temp;
        else
            ptr2->next = temp;
        ptr2 = temp;
    }
    struct Node* ptr3 = intersectPoint(head1, head2);
    if (!ptr3)
        printf("No Intersection");
    else
        printf("%d", ptr3->data);
    return 0;
}