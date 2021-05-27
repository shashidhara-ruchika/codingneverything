/*
https://www.codechef.com/JUNE20B/problems/EVENM
*/

#include <stdio.h>

int main()
{
    int t, z;
    scanf("%d", &t);
    for(z=0; z<t; z++){
        int n;
        scanf("%d", &n);
        int i = 0, j;
        while(i < n){
            if(i%2==0){
                j=1;
                while(j<n+1){
                    printf("%d ", j+(n*i));
                    j++;
                }
            }
            else{
                j=n;
                while(j>0){
                    printf("%d ", j+(n*i));
                    j--;
                }
            }
            printf("\n");
            i++;
        }
    }
    return 0;
}