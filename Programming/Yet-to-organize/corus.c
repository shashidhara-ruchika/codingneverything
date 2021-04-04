/*
https://www.codechef.com/MAY20B/problems/CORUS
*/

#include <stdio.h>

int main(void) {
	int t, z, n, q, i, c, j, count;
	int alarr[26];
	scanf("%d", &t);
	for(z=0; z<t; z++)
	{
    	for(i=0; i<26; i++)
    	{
    	    alarr[i] = 0;
    	    //printf("%d-%d ",i, alarr[i]);
    	}
	    scanf("%d", &n);
	    scanf("%d", &q);
	    //printf("\n%d %d\n", n, q);
	    char s;
	    for(i=0; i<n+1; i++)
	    {   
                scanf("%c", &s);
                if(i !=0)
                {
                    alarr[((int)s) - 97]++;
                    //printf("%d ", s);
                }
	    } 
	    /*for(i=0; i<26; i++)
    	{
    	    printf("%c-%d ",i+97, alarr[i]);
    	}*/
	    for(i=0; i<q; i++)
	    {
	        scanf("%d", &c);
	        //printf("\n%d", c);
	        count = 0;
	        for(j=0; j<26; j++)
	        {
	            if(alarr[j] > c)
	                count += alarr[j] - c;
	        }
	        printf("%d\n", count);
	    }
    	//printf("\n");
	}
	return 0;
}

