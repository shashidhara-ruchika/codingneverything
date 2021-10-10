// https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/

/*
Given an integer N representing the number of pairs of parentheses, 
the task is to generate all combinations of well-formed(balanced) parentheses.
*/

/*
Input:
N = 3

Output:
((()))
(()())
(())()
()(())
()()()
*/

//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution  //optimized
{
    private:
    vector<string> allparen;
    
    void genparen(int leftrem, int rightrem, string str, int index) {
        
        if (leftrem < 0 || rightrem < leftrem)     // invalid state
            return; 
        
        if (leftrem == 0 && rightrem == 0)
            this -> allparen.push_back(str);
        
        else {
            str[index] = '(';   // add left & recurse
            genparen(leftrem - 1, rightrem, str, index + 1);
            
            str[index] = ')';   // add right & recurse
            genparen(leftrem, rightrem - 1, str, index + 1);
        }
        
    }
    
    public:
    vector<string> AllParenthesis(int n) {
        string str(n * 2, ' ');
        
        genparen(n, n, str, 0);
        
        return this -> allparen;
    }
};

class Solution2
{
    private:
    set<string> gen(int n) {
        set<string> genstr;
        if (n == 0) {
            genstr.insert("");
        }
        else {
            set<string> prevgenstr = gen(n - 1);
            for (auto &s : prevgenstr) {
                for (int i = 0; i < s.length(); ++i) {
                    if (s[i] == '(') {
                        string news = s.substr(0, i + 1) + "()" + s.substr(i + 1, s.length());
                        genstr.insert(news);
                    }
                }
                genstr.insert("()" + s);
            }
            
        }
        return genstr;
            
    }
    public:
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        set<string> s = gen(n);
        vector<string> v(s.begin(), s.end());
        return v;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends