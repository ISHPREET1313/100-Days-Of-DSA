/*
Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.
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
    printf("Enter key: ");
    scanf("%d",&key);
    int count=0;
    ptr=head;
    while(ptr!= NULL){
        if(ptr->value==key)
            count++;    
        ptr=ptr->next;
    }
    printf("%d",count);
}