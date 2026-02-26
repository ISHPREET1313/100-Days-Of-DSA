/*Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50
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
        if(i==0)
            head=temp;
        if(i>0)
            ptr->next=temp;
        ptr=temp;
    }
    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->value);
        ptr=ptr->next;
    }
}