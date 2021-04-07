/*
https://practice.geeksforgeeks.org/problems/c-multi-level-inheritance/1/?page=1&category[]=OOP&query=page1category[]OOP#
*/

//Initial Template for C++

#include <iostream>
using namespace std;

class student
{
    protected :
        int roll_number;
        
    public:
        void set_number(int a)
        {
            roll_number = a;
        }
        
        void display_number()
        {
            cout<<roll_number<<endl;
        }
};


 // } Driver Code Ends
//User function Template for C++
class test: public student 
{
    // Add set_marks() method here.
    protected:
    int marks_arr[5];
    
    public:
    void set_marks(float *arr) {
        for (int i = 0; i < 5; i++) {
            this -> marks_arr[i] = arr[i];
        }
    }
    
};

class result: public test
{
    // Add display() method here.
    protected:
    float total_marks = -1.0;
    float avg_marks;
    
    public:
    
    void total_test_marks() {
        float total = 0;
        for (int i = 0; i < 5; i++) {
            total += this -> marks_arr[i];
        }
        this -> total_marks = total;
    }
    
    void avg_test_marks() {
        if (total_marks == -1.0)
            total_test_marks();
            
        this -> avg_marks = this -> total_marks / 5.0;
    }
    
    void display() {
        total_test_marks();
        avg_test_marks();
        cout << this -> roll_number << " " << 
                this -> total_marks << " " << 
                this -> avg_marks << endl;
    }
};

/*
Input:

3
1
10 10 10 10 10
2
8 8 8 8 8 
3 
7 7 7 7 7

Output:

1 50 10
2 40 8
3 35 7
*/

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
    	result student1;
	    int n;
	    cin>>n;
	    student1.set_number(n);
	    float temp[5];
	    int i;
	
	    for(i = 0; i < 5; i++)
	        cin>>temp[i];
	
	    student1.set_marks(temp);
	    student1.display();
	}

	return 0;    
}
  // } Driver Code Ends