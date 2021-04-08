/*
https://www.codechef.com/JUNE20B/problems/CHFICRM
*/

#include <stdio.h>

int main()
{
    int t, z;
    scanf("%d", &t);
    for(z=0; z<t; z++){
        int a[1001];
        int n, y, flag, c5, c10, c15;
        scanf("%d", &n);
        for(y=0; y<n; y++)
            scanf("%d", &a[y]);
        y=0; flag=1; c5=0; c10=0; c15=0;
        while(flag==1 && y<n){
            if(a[y] == 5)
                c5++;
            else if(a[y] == 10){
                if(c5 >= 1){
                    c10++;
                    c5--;
                }
                else
                    flag = 0;
            }
            else{
                if(c10 >= 1){
                    c15++;
                    c10--;
                }
                else if(c5 >= 2){
                    c15++;
                    c5 -= 2;
                }
                else{
                    flag = 0;
                }
            }
            y++;
        }
        if(flag == 1)
            printf("YES\n");
        else
            printf("NO\n");
        //printf("\n");    
    }
    return 0;
}