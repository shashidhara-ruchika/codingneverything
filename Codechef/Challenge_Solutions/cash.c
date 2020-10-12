/*
https://www.codechef.com/FEB20B/problems/CASH
*/

#include <stdlib.h>
#include <stdio.h>

int main()
{
    long int t;
    scanf("%ld", &t);
    long int i, n, k, j, sum;
    for(i=0; i<t; i++){
        sum = 0;
        scanf("%ld %ld", &n, &k);
        long int *a = (long int*)malloc(n * sizeof(long int));
        for(j=0; j<n; j++){
            scanf("%ld", &a[j]);
            sum += a[j];
        }
        printf("%ld\n", sum%k);
    }

    return 0;
}


