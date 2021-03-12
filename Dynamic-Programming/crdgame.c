/*
https://www.codechef.com/JULY20B/problems/CRDGAME
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int t, zt;
    scanf("%d", &t);
    for(zt=0; zt<t; zt++){
        int n, zn, i, ascore, bscore, chefscore = 0, mortyscore = 0;
        char a[10], b[10];
        scanf("%d", &n);
        for(zn=0; zn<n; zn++){
            scanf("%s %s", a, b);
            ascore = 0;
            bscore = 0;
            i=0;
            while(a[i] != '\0'){
                //printf("%c", a[i]);
                ascore += a[i] - '0';
                i++;
            }
            i=0;
            while(b[i] != '\0'){
                //printf("%c", b[i]);
                bscore += b[i] - '0';
                i++;
            }
            //printf("%s %d %s %d\n", a, ascore, b, bscore);
            if(ascore == bscore){
                chefscore ++; 
                mortyscore ++;
            }
            else if(ascore > bscore){
                chefscore ++;
            }
            else{
                mortyscore ++;
            }
        }
        if(chefscore == mortyscore){
            printf("%d %d\n", 2, chefscore);    
        }
        else if(chefscore > mortyscore){
            printf("%d %d\n", 0, chefscore);
        }
        else{
            printf("%d %d\n", 1, mortyscore);
        }
        //printf("\n");
    }
    return 0;
}