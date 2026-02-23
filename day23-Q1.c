/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* next;
};
typedef struct node node;
int main(){
    node*head=NULL,*head2=NULL,*head3=NULL,*temp=NULL,*ptr=NULL,*ptr2=NULL,*ptr3=NULL;
    int n,m;
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
    head2=NULL,temp=NULL,ptr=NULL;
    printf("Enter nummber of elements: ");
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        temp=(node*)malloc(sizeof(node));
        if(temp==NULL){
            printf("Malloc failed");
            return 1;
        }
        scanf("%d",&temp->value);
        temp->next=NULL;
        if(i==0)
            head2=temp;
        if(i>0)
            ptr->next=temp;
        ptr=temp;
    }
    temp=NULL,ptr=NULL;
    ptr2=head;
    ptr3=head2;
    int i=0;
    while(ptr2 != NULL && ptr3 != NULL){
        temp=(node*)malloc(sizeof(node));
        if(temp==NULL){
            printf("Malloc failed");
            return 1;
        }
        if(ptr2->value<ptr3->value){
            temp->value=ptr2->value;
            ptr2=ptr2->next;
        }
        else{
            temp->value=ptr3->value;
            ptr3=ptr3->next;
        }
        temp->next=NULL;
        if(i==0)
            head3=temp;
        if(i>0)
            ptr->next=temp;
        ptr=temp;
        i++;
    }
    while(ptr2 != NULL) {
    temp = (node*)malloc(sizeof(node));
    temp->value = ptr2->value;
    temp->next = NULL;
    ptr->next = temp;
    ptr = temp;
    ptr2 = ptr2->next;
    }
    while(ptr3 != NULL) {
    temp = (node*)malloc(sizeof(node));
    temp->value = ptr3->value;
    temp->next = NULL;
    ptr->next = temp;
    ptr = temp;
    ptr3 = ptr3->next;
    }
    ptr=head3;
    while(ptr!=NULL){
        printf("%d ",ptr->value);
        ptr=ptr->next;
    }
}