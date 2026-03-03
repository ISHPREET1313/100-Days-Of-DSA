/*Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'

Example:
Input:
5
1 10
1 20
3
2
3

Output:
20 10
20
10*/

#include<stdio.h>

#define MAX 100
int stack[MAX], top = -1;

void push(int x){
    if(top == MAX-1)
        printf("\nStack Overflow\n");
    else
        stack[++top] = x;
}

void pop(){
    if(top == -1)
        printf("\nStack Underflow\n");
    else
        printf("\n%d\n", stack[top--]);
}

void display(){
    for(int i=top;i>=0;i--)
        printf("%d ", stack[i]);
}

int main(){
    int n,input,x;
    scanf("%d",&n);
    int operation[MAX],value[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &operation[i]);
        if (operation[i] == 1) {
            scanf("%d", &value[i]);
        }
    }
    for(int i=0;i<n;i++){
        switch (operation[i]){
            case 1:
                push(value[i]);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default : 
                printf("\ninvalid input\n");
                break;
        }
    }
    return 0;
}
