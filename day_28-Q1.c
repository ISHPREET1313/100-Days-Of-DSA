/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.
*/

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
int main() {
    int n, i;
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    scanf("%d", &n);
    if (n <= 0)
        return 0;
    head = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &head->data);
    head->next = head;  
    temp = head;
    for (i = 2; i <= n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = head;
        temp->next = newnode;
        temp = newnode;
    }
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    return 0;
}