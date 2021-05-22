/*
https://binarysearch.com/problems/Sentence-Reversal
*/

#include <bits/stdc++.h>
using namespace std;

class reverse_words {
    private:
        vector<string> sentence;
        vector<string> rev_sentence;
        void input_sentence();
        void reverse_sentence();
    
    public:
        reverse_words();        
        vector<string> get_reversed_sentence();
        void print_reversed_sentence();
};

reverse_words :: reverse_words() {
    this -> input_sentence();
    this -> reverse_sentence();
}

void reverse_words :: input_sentence() {
    int n;
    cin >> n;
    while(n-- > 0) {
        string s;
        cin >> s;
        sentence.push_back(s);
    }
}

vector<string> reverse_words :: get_reversed_sentence() {
    return this -> rev_sentence;
}

void reverse_words :: print_reversed_sentence() {
    for(auto c : this -> rev_sentence)
        cout << c;
    cout << endl;
}

void reverse_words :: reverse_sentence() {
    
    this -> rev_sentence.assign(this -> sentence.begin(), this -> sentence.end());
    
    this -> rev_sentence.push_back(" ");

    auto start_it = 0;
    auto end_it = 1;    
    
    while (end_it < this -> rev_sentence.size()) {
        
        if (this -> rev_sentence[end_it] == " ") {
            reverse(this -> rev_sentence.begin() + start_it, this -> rev_sentence.begin() +  end_it);
            start_it = end_it + 1;
            end_it += 2;
        }
        else {
            end_it++;
        }
    }

    this -> rev_sentence.pop_back();
}

vector<string> solve(vector<string>& sentence) {    
    
    reverse(sentence.begin(), sentence.end());
    sentence.push_back(" ");
    
    auto start_it = 0;
    auto end_it = 1;    
    
    while (end_it < sentence.size()) {
        
        if (sentence[end_it] == " ") {
            reverse(sentence.begin() + start_it, sentence.begin() +  end_it);
            start_it = end_it + 1;
            end_it += 2;
        }
        else {
            end_it++;
        }
    }

    for(auto c : sentence) {
        cout << c;
    }
    sentence.pop_back();

    return sentence;
}

/*
Input
10
hi world z

Output
z world hi
*/

int main() {

    reverse_words* rev_ptr = new reverse_words();
    rev_ptr -> print_reversed_sentence();
    return 0;
}