/*
https://www.hackerrank.com/challenges/30-more-exceptions/problem
*/
#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

//Write your code here
class Calculator {
    
    public:
    int power(int n, int p) {
        
        if (n < 0 || p < 0) {
            throw invalid_argument("n and p should be non-negative");
        }
        
        double res = pow((double)n, (double)p);
        return (int)res;        
    }
};

int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl; 
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }
    
}

/*
Input

10
10 0
0 10
-1 4
2 -3
-2 -2
5 6
3 3
8 0
2 3
3 -3

Output

1
0
n and p should be non-negative
n and p should be non-negative
n and p should be non-negative
15625
27
1
8
n and p should be non-negative
*/