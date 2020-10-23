/*
https://www.codechef.com/JUNE20B/problems/PRICECON
*/

#include <stdio.h>
#include <math.h>

int main(void) {
	int t, n, k, z, y, init, final;
	int num;
	scanf("%d", &t);
	for(z=0; z<t; z++){
	    scanf("%d %d", &n, &k);
	    init = 0; final = 0;
	    for(y=0; y<n; y++){
	        scanf("%d", &num);
	        init += num;
	        if(num > k)
	            final += k;
	        else
	            final += num;
	    }
	    printf("%d\n", init - final);
	}
	return 0;
}

