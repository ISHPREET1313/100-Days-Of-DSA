/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.
*/

#include<stdio.h>

int main(){
    int n;
    printf("Enter no. of elements:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int min=arr[0]+arr[1],mini=0,minj=1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int current_sum=arr[i]+arr[j];
            if(min<0){
                min*=-1;
            }
            if(current_sum<0){
                current_sum*=-1;
            }
            if(min>current_sum){
                min=arr[i]+arr[j];
                mini=i;
                minj=j;
            }
        }
    }
    printf("%d %d",arr[mini],arr[minj]);
}
