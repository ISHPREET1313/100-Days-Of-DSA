/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.
*/
#include<stdio.h>
#include<ctype.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int x){
    stack[++top] = x;
}

int pop(){
    return stack[top--];
}

int main(){
    char postfix[100];
    printf("Enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    for(int i = 0; postfix[i] != '\0'; i++){

        if(postfix[i] == ' ' || postfix[i] == '\n')
            continue;

        if(isdigit(postfix[i])){
            push(postfix[i] - '0');
        }
        else{
            int val1 = pop();
            int val2 = pop();

            switch(postfix[i]){
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
            }
        }
    }

    printf("Result: %d", pop());
    return 0;
}