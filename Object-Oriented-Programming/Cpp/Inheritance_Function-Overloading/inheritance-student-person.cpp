/*
https://www.hackerrank.com/challenges/30-inheritance/problem?isFullScreen=true
*/

#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
        /*	
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here
        Student(string firstName, string lastName, int id, vector<int> scores) : Person(firstName, lastName, id) {
            this -> testScores = scores;   
        }
        /*	
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here
        char calculate() {
            int avg = 0;
            for (int i = 0; i < this -> testScores.size(); i++) {
                avg += this -> testScores[i];
            }
            avg = avg / this -> testScores.size();
            
            if (avg >= 90 && avg <= 100) 
                return 'O';
            else if (avg >= 80)
                return 'E';
            else if (avg >= 70)
                return 'A';
            else if (avg >= 55)
                return 'P';
            else if (avg >= 40)
                return 'D';
            else 
                return 'T';            
        }
};

/*
 Sample Input
 Heraldo Memelli 8135627
 2
 100 80

 Sample Output
 Name: Memelli, Heraldo
 ID: 8135627
 Grade: O
*/  

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}