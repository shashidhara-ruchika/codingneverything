/*
https://www.hackerrank.com/challenges/virtual-functions/problem
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
protected:
    int age;
    string name;

public:   
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

class Professor : public Person {
private:
    int cur_id;
    int publications; 
    static int total_ids; 
    
public:
    Professor();
    void getdata();
    void putdata();    
};

class Student : public Person {
private:
    int cur_id;
    int marks[6];  
    static int total_ids;  
    int sum_marks();
    
public:
    Student();
    void getdata();
    void putdata();    
};

Professor :: Professor() {
    this -> total_ids = this -> total_ids + 1;
    this -> cur_id = this -> total_ids;
}

void Professor :: getdata() {
    cin >> this -> name >> this -> age >> this -> publications; 
}

void Professor :: putdata() {
    cout << this -> name << " " << this -> age << " " << 
            this -> publications << " " << this -> cur_id << endl;
}

Student :: Student () {
    this -> total_ids = this -> total_ids + 1;
    this -> cur_id = this -> total_ids;
}

int Student :: sum_marks() {
    int marks_sum = 0;
    for (int i = 0; i < 6; i++) {
        marks_sum += this -> marks[i];
    }
    return marks_sum;
}

void Student :: getdata() {
    cin >> this -> name >> this -> age;
    for (int i = 0; i < 6; i++) {
        cin >> this -> marks[i];
    }
}

void Student :: putdata() {
    int sum_s = this -> sum_marks();
    cout << this -> name << " " << this -> age << " " << 
            sum_s << " " << this -> cur_id << endl;
}

int Professor :: total_ids = 0;
int Student :: total_ids = 0;

/*
Sample Input 

7
2
10311999121109101 9 16 35 64 78 36 94
1
104102122101107106115104 61 808
1
115 34 310
1
1031179710110210410111410111797106103108 72 139
2
117100105111121102113 10 96 30 13 67 47 49
1
101109103108120122114120 33 418
2
1191149710610798113116104101106109103110111100110 2 52 27 100 91 60 98

Sample Output

10311999121109101 9 323 1
104102122101107106115104 61 808 1
115 34 310 2
1031179710110210410111410111797106103108 72 139 3
117100105111121102113 10 302 2
101109103108120122114120 33 418 4
1191149710610798113116104101106109103110111100110 2 428 3
*/

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
