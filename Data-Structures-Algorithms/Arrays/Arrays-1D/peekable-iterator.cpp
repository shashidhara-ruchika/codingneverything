/*
https://binarysearch.com/problems/Peekable-Iterator
*/

# include <bits/stdc++.h>

using namespace std;

class PeekableIterator {
    
    private:
        vector<int> arr;
        int it;
    
    public:
    PeekableIterator(vector<int>& nums) {
        this -> arr = nums;
        this -> it = 0;
    }

    int peek() {
        return this -> arr[this -> it];
    }

    int next() {
        if (this -> it < this -> arr.size())
            return this -> arr[this -> it++];
        return 0;
    }

    bool hasnext() {
        if (this -> it < this -> arr.size())
            return true;
        return false;
    }
};

/*
Input
2
1 2
1
3
2
1
3
2
0

Output
1
1
1   //true
2
2
0   //false

Explanation
First we create a PeekableIterator with values [1, 2]
We peek the next element which is 1
We poll the next element which is 1
We check if the next element exists, which it does since 2 is next in the iterator.
We peek the next element which is 2
We poll the next element which is 2
We check if the next element exists which it doesn't
*/

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    PeekableIterator pi(nums);
    int c;
    cin >> c;
    while(c != 0) {
        switch(c) {
            case 1:
                cout << pi.peek() << endl;
                break;
            
            case 2:
                cout << pi.hasnext() << endl;
                break;
            
            case 3:
                cout << pi.next() << endl;
                break;
            
            default:
                break;                
        }
        cin >> c;
    }
    return 0;
}
