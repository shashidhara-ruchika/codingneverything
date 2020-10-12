/*
https://www.codechef.com/COBT2019/problems/CB2001
*/

#include <stdio.h>

unsigned long int gcd(unsigned long long int a, unsigned long int b){
    if(a==0)
        return b;
    else
        return gcd(b % a, a);
}

unsigned long int lcm(unsigned long int a, unsigned long int b){
    return (a*b)/gcd(a, b);
}

unsigned long int lcmAvg(unsigned long int N){
    unsigned long int sum, i;
    sum = N;
    for(i=0; i<N; ++i){
        sum += lcm(i, N);
    }
    return sum/N;
}

int main(void) {

	int T;
	scanf("%d", &T);
	unsigned long int arrN[100];
	int i;
	for(i=0; i<T; i++){
	    scanf("%lu", &arrN[i]);
	    printf("%lu\n", lcmAvg(arrN[i]));
	}
	return 0;
}

