/*
https://www.hackerrank.com/challenges/30-sorting/problem
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class BubbleSortArr {
    private:
    vector<int> arr;
    int arr_len;
    int total_swaps;
    
    public:
    BubbleSortArr(int n);
    void bubbleSort();
    int getTotalSwaps();
    int getFirstEle();
    int getLastEle();
};

BubbleSortArr :: BubbleSortArr (int n) {
    this -> arr_len = n;    
    int num;
    for(int i = 0; i < this -> arr_len; i++) {
        cin >> num;
        this -> arr.push_back(num);
    }
}

void BubbleSortArr :: bubbleSort() {
   
    for (int i = 0; i < this -> arr_len; i++) {        
        
        // Track number of elements swapped during a single array traversal
        int num_swaps = 0;
        
        for (int j = 0; j < (this -> arr_len - 1); j++) {
            
            // Swap adjacent elements if they are in decreasing order
            if (this -> arr[j] > this -> arr[j + 1]) {                
                swap(this -> arr[j], this -> arr[j + 1]);
                num_swaps++;                               
            }  
                      
        }
        
        // Sum up the total num of swaps for all traversals
        this -> total_swaps += num_swaps;
        
        // If no elements were swapped during a traversal, array is sorted
        if (num_swaps == 0)
            break;
    }
    
}

int BubbleSortArr :: getTotalSwaps() {
    return this -> total_swaps;
}

int BubbleSortArr :: getFirstEle() {
    return this -> arr[0];
}

int BubbleSortArr :: getLastEle() {
    return this -> arr[this -> arr_len - 1];
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    BubbleSortArr *bsa_ptr = new BubbleSortArr(n);
    bsa_ptr -> bubbleSort();
    cout << "Array is sorted in " << bsa_ptr -> getTotalSwaps() << " swaps.\n";
    cout << "First Element: " << bsa_ptr -> getFirstEle() << endl;
    cout << "Last Element: " << bsa_ptr -> getLastEle() << endl;
    return 0;
}

/*
Sample Input

3
3 2 1

Sample Output

Array is sorted in 3 swaps.
First Element: 1
Last Element: 3
*/