/*
Insert an Element in an Array

Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n ,pos,x;
    printf("Enter number of elments:");
    scanf("%d",&n);
    int* arr=(int*)malloc(n*sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter array elements(space separated):");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter position to insert:");
    scanf("%d",&pos);
    printf("Enter element to insert");
    scanf("%d",&x);
    arr=(int*)realloc(arr,(n+1)*sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    int i;
    for(i=n;i>=pos;i--)
        arr[i]=arr[i-1];
    arr[pos-1]=x;
    printf("Array after insertion");
    for(int j=0;j<n+1;j++)
        printf("%d ",arr[j]);
    free(arr);
    return 0;
}