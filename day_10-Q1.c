/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards
*/

#include<stdio.h>
#include<string.h>

int main(){
    char str[50];
    printf("Enter string: ");
    scanf("%s",&str);
    int n=strlen(str);
    int palindrome=1;
    char *p1,*p2;
    p1=str;
    p2=&str[n-1];
    for(int i=0;i<n/2;i++){
        if(*p1!=*p2){
            printf("NO");
            palindrome=0;
            break;
        }
        p1++;
        p2--;
    }
    if(palindrome){
        printf("YES");
    }
    return 0;
}