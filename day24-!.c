/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.
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
    int key;
    printf("Enter Element to delete: ");
    scanf("%d",&key);
    temp=head,ptr=head;
    while(ptr!= NULL){
        if(ptr->value==key){
            temp->next=ptr->next;
            free(ptr);
            break;
        }
        else{
            temp=ptr;
            ptr=ptr->next;
        }
    }
    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->value);
        ptr=ptr->next;
    }
}