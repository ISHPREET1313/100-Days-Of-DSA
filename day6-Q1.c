/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3
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
    int temp=arr[0];
    printf("%d ",temp);
    for(int i=0;i<n;i++){
        if(temp!=arr[i]){
            temp=arr[i];
            printf("%d ",temp);
        }
    }
    free(arr);
    return 0;
}