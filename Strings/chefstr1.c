/*
https://www.codechef.com/JULY20B/problems/CHEFSTR1
*/

#include <stdio.h>

int main()
{
    int t, zt;
    scanf("%d", &t);
    for(zt=0; zt<t; zt++){
        int n, zn;
        long int sum = 0, prev, next;
        scanf("%d", &n);
        scanf("%ld", &prev);
        for(zn=1; zn<n; zn++){
            scanf("%ld", &next);
            if(prev < next)
                sum = sum + next - prev - 1;
            else
                sum = sum + prev - next - 1;
            prev = next;
        }
        printf("%ld\n", sum);
    }
    return 0;
}