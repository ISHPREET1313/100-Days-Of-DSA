/*Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

Input:
- Single integer n

Output:
- Print the n-th Fibonacci number

Example:
Input:
6

Output:
8

Explanation: Sequence: 0,1,1,2,3,5,8 at positions 0,1,2,3,4,5,6
*/

#include<stdio.h>

int fibonacci(int);

int main(){
    int n;
    printf("Enter position of which fibonacci series element want: ");
    scanf("%d",&n);
    int result=fibonacci(n);
    printf("%d",result);
}

int fibonacci(int n){
    if(n==0){
        return 0;
    }
    else if (n==1){
        return 1;
    }
    else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}