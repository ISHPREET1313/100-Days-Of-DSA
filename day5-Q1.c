/*
Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int p;
    printf("Enter number of entries in server log 1:");
    scanf("%d",&p);
    int* arr1=(int*)malloc(p*sizeof(int));
    if (arr1 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter sorted integers representing arrival times from server 1(space separated):");
    for(int i=0;i<p;i++)
        scanf("%d",&arr1[i]);

    int q;
    printf("Enter number of entries in server log 2:");
    scanf("%d",&q);
    int* arr2=(int*)malloc(q*sizeof(int));
    if (arr2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter sorted integers representing arrival times from server 1(space separated):");
    for(int i=0;i<q;i++)
        scanf("%d",&arr2[i]);
    
    int*result=(int*)(malloc((p+q)*sizeof(int)));
    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    while (i < p) {
        result[k++] = arr1[i++];
    }

    while (j < q) {
        result[k++] = arr2[j++];
    }

    for(int i=0;i<(p+q);i++)
        printf("%d ",result[i]);
    
    free(arr1);
    free(arr2);
    free(result);

    return 0;
}