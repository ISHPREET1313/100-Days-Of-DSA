/*Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;

Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* buildTree(int arr[], int n){
    if(n==0 || arr[0]==-1)
        return NULL;
    Node* root = createNode(arr[0]);
    Node* queue[n];
    int front=0, rear=0;
    queue[rear++] = root;
    int i=1;
    while(i<n && front<rear){
        Node* curr = queue[front++];
        if(arr[i]!=-1){
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if(i<n && arr[i]!=-1){
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

void levelOrder(Node* root){
    if(root == NULL)
        return;
    Node* queue[100];
    int front=0, rear=0;
    queue[rear++] = root;
    while(front < rear){
        Node* curr = queue[front++];
        printf("%d ", curr->data);
        if(curr->left)
            queue[rear++] = curr->left;
        if(curr->right)
            queue[rear++] = curr->right;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    Node* root = buildTree(arr,n);
    levelOrder(root);
    return 0;
}