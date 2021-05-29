/*
https://practice.geeksforgeeks.org/problems/c-complex-number-addition-operator-overloading/1/?page=1&category[]=OOP&query=page1category[]OOP#
*/

//Initial Template for C++

#include <iostream>
using namespace std;



 // } Driver Code Ends
//User function Template for C++

class complex
{
    int x, y;
    
    public:
    complex()
    {
        
    }
    
    complex(int real, int imag)
    {
        x = real; 
        y = imag;
    }
    
    complex operator + (const complex &c_obj)
    {
        // Add your code here.
        int real_part = this -> x + c_obj.x;
        int imag_part = this -> y + c_obj.y;
        return complex(real_part, imag_part);
    }
    
    void display()
    {
        cout<<x<<" + "<<y<<"i"<<endl;
       
    }
    
    
};

/*
Input:

2
3 6 -1 4
2 2 -1 -1

Output:

2 + 10i
1 + 1i
*/

// { Driver Code Starts.

int main() {
    
    int t;
    cin>>t;
    while(t--)
    {
        int c11, c12, c21, c22;
        cin>>c11>>c12>>c21>>c22;
     
        
	
	complex c1, c2, c3;
	c1 = complex(c11, c12);
	c2 = complex(c21, c22);
	c3 = c1 + c2;
	
	c3.display();
    }
	return 0;
}  // } Driver Code Ends