/*
https://practice.geeksforgeeks.org/problems/c-inheritance-introduction/1/?page=1&category[]=OOP&query=page1category[]OOP#
*/

//Initial Template for C++

#include <iostream>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Cuboid 
{
   //Add your code here.
   protected:
   int length;
   int width;
   int height;
   
   public:
   virtual void display();
   
};

class CuboidVol: public Cuboid
{
    //Add your code here.
    private:
    int calc_vol();
    
    public:
    void read_input(int l, int w, int h);
    void display();
};

void Cuboid :: display() {
    cout << this -> length << " " << this -> width << " " << this -> height << endl;
}

int CuboidVol :: calc_vol() {
    return this -> length * this -> width * this -> height;
}

void CuboidVol :: read_input(int l, int w, int h) {
    this -> length = l;
    this -> width = w;
    this -> height = h;
}

void CuboidVol :: display() {
    int v = this -> calc_vol();
    cout << v << endl;
}
/*
Sample input:

1
12 10 2

Sample output:

12 10 2 
240
*/
// { Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int l, w, h;
        cin>>l>>w>>h;
    
    // Declare a CuboidVol object
    
    CuboidVol c_vol;
    
    
    // Read length width and height
     
    c_vol.read_input(l,w,h);
    
    
    //  Print length, width and height
    
    c_vol.Cuboid::display();
    
    
    // Print the Volume
     
    c_vol.display();
    }
    
    return 0;
}  // } Driver Code Ends