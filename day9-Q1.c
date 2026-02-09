/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored
*/

#include<stdio.h>

int main(){
    char str[50];
    printf("Enter code: ");
    scanf("%s",&str);
    int n=0;
    for(int i=0;str[i]!='\0';i++){
        n++;
    }
    char *p1,*p2;
    p1=str;
    p2=&str[n-1];
    for(int i=0;i<n/2;i++){
        *p1=*p2^*p1;
        *p2=*p1^*p2;
        *p1=*p2^*p1;
        p1++;
        p2--;
    }
    printf("Transformed code after mirror operation: ");
    printf("%s",str);
    return 0;
}