/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,key,count=1,found=0;
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
    printf("Enter key to search:");
    scanf("%d",&key);
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            found=1;
            printf("Found at index %d",i);
            printf("\nComparisons = %d",count);
        }
        count++;
    }
    if(!found){
        printf("Not found");
    }
    free(arr);
    return 0;
}