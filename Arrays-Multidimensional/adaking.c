/*
https://www.codechef.com/JULY20B/problems/ADAKING
*/

#include <stdio.h>

int main()
{
    int t, zt;
    scanf("%d", &t);
    
    for(zt=0; zt<t; zt++)
    {
        char b[8][8];
        int n, i, j;
        scanf("%d", &n);
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(n>0)
                {
                    b[i][j] = '.';
                    n--;
                }
                else
                {
                    b[i][j] = 'X';
                }
            }
        }
        
        b[0][0] = 'O';
        
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                printf("%c", b[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        
    }
    return 0;
}