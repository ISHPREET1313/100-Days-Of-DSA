/*
Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1

Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
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
    int *p1,*p2;
    p1=arr;
    p2=&arr[n-1];
    for(int i=0;i<n/2;i++){
        *p1=*p2^*p1;
        *p2=*p1^*p2;
        *p1=*p2^*p1;
        p1++;
        p2--;
    }
    printf("Reversing array:");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    free(arr);
    return 0;
}