/*
https://www.hackerrank.com/challenges/c-tutorial-class/
*/

#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student {
  
  private:
    int age;
    int standard;
    string first_name;
    string last_name;    
    
  public:  
    
    void set_age(int age);
    void set_standard(int std);
    void set_first_name(string name);
    void set_last_name(string name);    
    
    int get_age();
    int get_standard();
    string get_first_name();
    string get_last_name();  
    
    string to_string();  
    
};

void Student :: set_age(int age) {
    this -> age = age;
}

void Student :: set_standard(int std) {
    this -> standard = std;   
}

void Student :: set_first_name(string name) {
    this -> first_name = name;
}

void Student :: set_last_name(string name) {
    this -> last_name = name;
}   

int Student :: get_age() {
    return this -> age;
}

int Student :: get_standard() {
    return this -> standard;
}

string Student :: get_first_name() {
    return this -> first_name;
}

string Student :: get_last_name() {
    return this -> last_name;
}  

string Student :: to_string() {
    stringstream ss;
    ss << this -> age << ',' << this -> first_name << ',' <<
          this -> last_name << ',' << this -> standard;
    return ss.str();
} 

/*
Sample Input

15
john
carmack
10

Sample Output

15
carmack, john
10

15,john,carmack,10
*/

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}