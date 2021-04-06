/*
https://www.hackerrank.com/challenges/box-it/problem
*/

#include<bits/stdc++.h>

using namespace std;

//Implement the class Box  
//l,b,h are integers representing the dimensions of the box
class Box {

private:
    int l;
    int b;
    int h;    

public:
    
    // The class should have the following functions : 
    //ctors
    Box();
    Box(int length, int breadth, int height);
    Box(const Box& B);
    
    // functions
    int getLength(); // Return box's length
    int getBreadth(); // Return box's breadth
    int getHeight();  //Return box's height
    long long CalculateVolume(); // Return the volume of the box    
    bool operator < (Box& b); //Overload operator < as specified
        
};

// Constructors: 
Box :: Box() : l{0}, b{0}, h{0} 
{
}

Box :: Box(int length, int breadth, int height) : l{length}, b{breadth}, h{height} 
{
}

Box :: Box(const Box& B) : l{B.l}, b{B.b}, h{B.h}
{    
}

int Box :: getLength() {
    return this -> l;
}

int Box :: getBreadth() {
    return this -> b;
}

int Box :: getHeight() {
    return this -> h;
}

long long Box :: CalculateVolume() {
    return (long long)(this -> l) * (long long)(this -> b) * (long long)(this -> h);
}

bool Box :: operator < (Box& b) {
     
    if ((this -> l < b.l) ||
         (this -> b < b.b && this -> l == b.l) ||
         (this -> h < b.h && this -> b < b.h && this -> l == b.l))
         return true;
    else 
        return false;
     
}

ostream& operator << (ostream& out, Box& B) {
    out << B.getLength() << " " 
        << B.getBreadth() << " "
        << B.getHeight();
    return out;
}

/*
Box b1; // Should set b1.l = b1.b = b1.h = 0;
Box b2(2, 3, 4); // Should set b1.l = 2, b1.b = 3, b1.h = 4;
b2.getLength();	// Should return 2
b2.getBreadth(); // Should return 3
b2.getheight();	// Should return 4
b2.CalculateVolume(); // Should return 24
bool x = (b1 < b2);	// Should return true based on the conditions given
cout<<b2; // Should print 2 3 4 in order.
*/

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}