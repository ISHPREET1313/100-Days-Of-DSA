/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* next;
};
typedef struct node node;
int main(){
    node*head=NULL,*temp=NULL,*ptr=NULL;
    int n,k;
    printf("Enter nummber of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        temp=(node*)malloc(sizeof(node));
        if(temp==NULL){
            printf("Malloc failed");
            return 1;
        }
        scanf("%d",&temp->value);
        temp->next=NULL;
        if(i==0)
            head=temp;
        if(i>0)
            ptr->next=temp;
        ptr=temp;
    }
    printf("Enter k: ");
    scanf("%d",&k);
    k = k % n;
    ptr=head;
    while(ptr->next!= NULL){
        ptr=ptr->next;
    }
    ptr->next=head;
    ptr=head;
    int i=0;
    while(i<n-k-1){
        ptr=ptr->next;
        i++;
    }
    temp=ptr;
    ptr=ptr->next;
    temp->next=NULL;
    head=ptr;
    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->value);
        ptr=ptr->next;
    }
}