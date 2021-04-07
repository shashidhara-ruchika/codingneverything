/*
https://practice.geeksforgeeks.org/problems/c-function-overloading-1587115620/1/?page=1&category[]=OOP&query=page1category[]OOP#
*/

//Initial Template for C++

#include <iostream>
using namespace std;



 // } Driver Code Ends
//User function Template for C++

// prints vol of cube
void volume(int s)
{
    // Add your code here.
    cout << s * s * s << endl;
}

// prints vol of cylinder
void volume(int r, int h)
{
    // Add your code here.
    cout << 3.14159 * r * r * h << endl;
}

// prints vol of cuboid
void volume(int l, int b, int h)
{
    // Add your code here.
    cout << l * b * h << endl;
}

/*
Input:

3
1 2
2 1 2
3 1 2 3

Output:

8
6.29038
6
*/

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        
        switch (q)
        {
            case 1:
            int edge;
            cin>>edge;
            volume(edge);
            break;
            
            case 2:
            int radius, heigh;
            cin>>radius>>heigh;
            volume(radius, heigh);
            break;
            
            case 3:
            int length, width, height;
            cin>>length>>width>>height;
            volume(length, width, height);
            break;
            
        }
        
        
        
    }
	
	return 0;
}  // } Driver Code Ends