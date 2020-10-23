/*
https://www.codechef.com/COOK119B/problems/CACHEHIT
*/

#include <stdio.h>

int main()
{
    int t, zt;
    scanf("%d", &t);
    for(zt=0; zt<t; zt++){
        int ch = 0, n, b, m, cache = 0, x, i;
        scanf("%d %d %d", &n, &b, &m);
        for(i = 0; i < m; i++){
            scanf("%d", &x);
            if(i == 0){
                cache = x/b;
                ch += 1;
            }
            //printf("%d %d\n", cache, x);
            if(x/b != cache){
                cache = x/b;
                ch += 1;
            }
        }
        printf("%d\n", ch);
    }
    return 0;
}