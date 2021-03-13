/*
https://practice.geeksforgeeks.org/problems/run-length-encoding/1#
*/

#include <bits/stdc++.h>
using namespace std;

char *encode(char *src);    
int appendRunLen(char *encoded_str, int es_i);
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		char str[10000];
		cin>>str;
		cout<< encode(str) <<endl;
	}
	return 0;
}

/*
wwwwaaadexxxxxxxxxxxxxtty
*/

/*
w4a3d1e1x13t2y1
*/

/*
char *encode(char *src)
{     
    char *encoded_str = (char*)malloc(sizeof(char) * (201));;
    
    encoded_str[0] = src[0];
    encoded_str[1] = 1 + '0';
    
    int src_i = 1;
    int es_i = 1;
    
    while (src[src_i] != '\0') {
        
        if (src[src_i - 1] == src[src_i]) {
            encoded_str[es_i] += 1;
        }
        else {
            encoded_str[++es_i] = src[src_i];
            encoded_str[++es_i] = 1 + '0';
        }
        
        src_i++;
    }
    encoded_str[++es_i] = '\0';
    
    return encoded_str;
}     
*/

int appendRunLen(char *encoded_str, int es_i) 
{
    int len_val = encoded_str[es_i] - '0' + 1;
    if (len_val <= 9)
        encoded_str[es_i] = len_val + '0';
    else {
        encoded_str[es_i++] = (len_val / 10) + '0';
        encoded_str[es_i] = (len_val % 10) + '0';
    }
    return es_i;
}

char *encode(char *src)
{     
    char *encoded_str = (char*) malloc(sizeof(char) * (20001));;
    
    encoded_str[0] = src[0];
    encoded_str[1] = 1 + '0';
    
    int src_i = 1;
    int es_i = 1;
    int len_val;
    
    while (src[src_i] != '\0') {
        
        if (src[src_i - 1] == src[src_i]) {
            es_i = appendRunLen(encoded_str, es_i);
        }
        else {
            encoded_str[++es_i] = src[src_i];
            encoded_str[++es_i] = 1 + '0';
        }
        
        src_i++;
    }
    encoded_str[++es_i] = '\0';
    
    return encoded_str;
} 
