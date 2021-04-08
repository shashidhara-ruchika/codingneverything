/*
https://www.hackerrank.com/challenges/classes-objects/problem?isFullScreen=true
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Write your Student class here
class Student {
  
  private:
    vector<int> scores;
  
  public:  
    void input();
    int calculateTotalScore();
    
};

void Student :: input() {
    int score;
    for (int i = 0; i < 5; i++) {
        cin >> score;
        this -> scores.push_back(score);
    }
}

int Student :: calculateTotalScore() {
    int total_score = 0;
    for(int i = 0; i < 5; i++) {
        //cout << "s " << this -> scores[i] << endl;
        total_score = total_score + this -> scores[i];
    }
    //cout << "t = " << total_score<< endl << endl;
    return total_score;
}

/*

Sample Input

The first line contains n, the number of students in Kristen's class. 
The n subsequent lines contain each student's 5 exam grades for this semester.

3
30 40 45 10 10
40 40 40 10 10
50 20 30 10 10

Sample Output

1
*/

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}
