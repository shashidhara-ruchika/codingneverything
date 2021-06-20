#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool canBeSplit(set<string>& words_set, string s)
{
    for (int i = 1; i < s.length(); i++) {
        string seg1 = s.substr(0, i);
        string seg2 = s.substr(i, s.length());
        if (words_set.find(seg1) != words_set.end() && words_set.find(seg2) != words_set.end())
            return true;
    }
    return false;
}

bool canHaveMultipleSplits(set<string>& words_set, string s)
{
    if (s.empty()) {
        return false;
    }

    for (int i = 0; i < s.length(); i++) {
        string seg1 = s.substr(0, i);
        string seg2 = s.substr(i, s.length());
        if (words_set.find(seg1) != words_set.end() ) {
                if (words_set.find(seg2) != words_set.end())
                    return true;
                return canHaveMultipleSplits(words_set, seg2);
                /*bool check = canHaveMultipleSplits(words_set, seg2);
                if (check)
                    return true;
                else
                    continue;*/
            }
            else {
                continue;
            }
    }
    return false;
}

int main() 
{
    //string s = "applepie";
    string s = "carpetcat";
    set<string> words_set;
    /*
    words_set.insert("apple");
    words_set.insert("pie");
    words_set.insert("sundae");
    words_set.insert("ice");
    words_set.insert("cream");
    */
    words_set.insert("car");
    words_set.insert("carpet");
    words_set.insert("cat");
    cout << canBeSplit(words_set, s) << endl;
    return 0;
}

/*
Question Inputs & Outputs
string a pplepie (2 segments)
n words in dict - apple, pie, 
26 - mod10 1 2
apple 

car carpet cat
carpetcatcar

car carpet pet
carpetcat
carpet cat
carpet cat
*/

/*
Initial brute force pseudo code
input(string_to_be_split)
index_splitted = 0
for word in dict_words:
    for i (0 -  len(string_to_be_split)):
        if (! word[i] == string_to_be_split[i]):
            break
        else if (word[len(word) - 1] == string_to_be_split[i]):
            index_splitted = i
*/

/*
python implementation
def canBeSplit(set_words, string_to_be_split):
    for i in range(1,len(string_to_be_split) - 1):
        seg1 = string_to_be_split[:i]
        seg2 = string_to_be_split[i:]
        if (seg1 in set_words and seg2 in set_words):
            return True
    return False  

set_words = {"apple", "pie", "sundae", "ice", "cream"}
string_to_be_split = "applepie"

print(canBeSplit(set_words, string_to_be_split))
*/