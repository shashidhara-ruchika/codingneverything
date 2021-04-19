/*
https://www.hackerrank.com/challenges/inherited-code/problem
*/

#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/* Define the exception here */
class BadLengthException : public exception {
    private:
    int n;
    
    public:
    BadLengthException(int name_err_len) : n(name_err_len) {}
    
    int what() {
        return this -> n;
    }
};

bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

/*
Sample Input

3
Peter
Me
Arxwwz

Sample Output

Valid
Too short: 2
Invalid

Explanation

Username Me is too short because it only contains 2 characters, 
so your exception prints Too short: 2.
All other validation is handled by the locked code in your editor.
*/

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}
