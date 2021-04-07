/*
https://practice.geeksforgeeks.org/problems/c-classes-introduction/1/?page=1&category[]=Class&query=page1category[]Class#
*/

//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

// CollegeCourse Class 
class CollegeCourse
{
    //your code here
    private:
    char grade;
    int credits;
    int gradePoints;
    float honorPoints;
    string courseID;
    
    public:
    void set_CourseId(string CID);
    void set_Grade(char g);
    void set_Credit(int cr);
    int calculateGradePoints(char g);
    void calculateHonorPoints(int gp, int cr);
    void display();
};

void CollegeCourse :: set_CourseId(string CID) {
    this -> courseID = CID;
}

void CollegeCourse :: set_Grade(char g) {
    this -> grade = g;
}

void CollegeCourse :: set_Credit(int cr) {
    this -> credits = cr;
}

int CollegeCourse :: calculateGradePoints(char g) {
    
    
    char grade = g;
    
    // convert lower to upper char
    
    if (g - 70 > 0)
        grade = g - 32;
    
    //cout << grade << endl;
    // returns 10 for A, 9 for B, 8 for C, 7 for D, 6 for E, 5 for F
    this -> gradePoints = 75 - grade;
    return this -> gradePoints;
    
    //return 10;
}

//float 
void CollegeCourse :: calculateHonorPoints(int gp, int cr) {
    this -> honorPoints = (float)gp * (float)cr;
    //return this -> honorPoints;
}

void CollegeCourse :: display() {
    cout << this -> gradePoints << " " << this -> honorPoints << endl;
}

/*
Input
2
CSN-206 A 4
ECE-500 d 3

Output
10 40
7 21
*/


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    CollegeCourse cc;
    string courseId;
    int gp;
    char grade;
    int credits;
    cin>>courseId>>grade>>credits;
    cc.set_CourseId(courseId);
    cc.set_Grade(grade);
    cc.set_Credit(credits);
    gp=cc.calculateGradePoints(grade);
    cc.calculateHonorPoints(gp,credits);
    cc.display();
    }
    return 0;
}
  // } Driver Code Ends