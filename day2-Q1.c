/*Delete an Element from an Array

Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n ,pos;
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
    printf("Enter position to delete:");
    scanf("%d",&pos);
    for(int i=pos;i<(n-1);i++)
        arr[i]=arr[i+1];
    n--;
    arr=(int*)realloc(arr,(n)*sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Array after deletion: ");
    for(int j=0;j<n;j++)
        printf("%d ",arr[j]);
    free(arr);
    return 0;
}
    