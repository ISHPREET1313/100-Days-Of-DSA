/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* next;
    struct node* prev;
};

typedef struct node node;

int main(){
    node*head=NULL,*temp=NULL,*ptr=NULL;
    int n;
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
        temp->prev=NULL;
        if(i==0){
            head=temp;
        }
        if(i>0){
            temp->prev=ptr;
            ptr->next=temp;
        }
        ptr=temp;
    }

    ptr=head;
    printf("NULL<-");
    while(ptr!=NULL){
        printf("%d<->",ptr->value);
        ptr=ptr->next;
    }
    printf("NULL");
}