/*
https://www.codechef.com/JUNE20B/problems/EOEO
*/

#include <stdio.h>

int main() {
	int t,z;
	scanf("%d", &t);
	for(z=0; z<t; z++)
	{
	    unsigned long long int ts, p;
	    scanf("%llu", &ts);
        while(ts%2!=1)
            ts/=2;
        p = ts/2;
	    printf("%llu\n",p);
	}
	return 0;
}

