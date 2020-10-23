/*
https://www.codechef.com/JUNE20B/problems/XYSTR
*/

#include <stdio.h>
#include <string.h>

void printlenmat(int *mat, int len){
    int i;
    for(i=0; i<len; i++)
        printf("%d", mat[i]);
    printf("\n");
}

int getcount(int *mat, int len){
    int i, c=0;
    for(i=0; i<len; i++){
        if(mat[i]==1)
           c++;
    }
    return c;
}

int main() {
	int t,z;
	scanf("%d", &t);
	char string[100009];
	for(z=0; z<t; z++)
	{
	    scanf("%s", &string);
	    //printf("%s\n", string);
	    int len = strlen(string);
	    int lenmat[100009];
	    int i;
	    for(i=0; i<len; i++)
	        lenmat[i] = 0;
	    for(i=1; i<len; i++){
	        if(string[i] != string[i-1] && lenmat[i-1]!=1)
	           lenmat[i]++;
	    }
	    //printlenmat(lenmat, len);
	    printf("%d\n", getcount(lenmat, len));
	}
	return 0;
}

