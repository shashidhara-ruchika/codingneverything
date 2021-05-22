/*
https://binarysearch.com/problems/Rolling-Median
*/

# include <bits/stdc++.h>

using namespace std;

class RollingMedian {
    private:
        vector<double> curr_ele;
        
    public:
    RollingMedian() {

    }

    void add(int val) {
        auto it = upper_bound(curr_ele.begin(), curr_ele.end(), val);
        curr_ele.insert(it, val);
    }

    double median() {
        int total_size = curr_ele.size();
        if (total_size % 2) // odd 
        {
            return curr_ele[total_size / 2];
        }
        else { //even
            cout << total_size << endl;
            return (curr_ele[total_size / 2 - 1] + curr_ele[total_size / 2] ) / 2;
        }
    }
};

/*
Input
1 1
1 2
1 3
2
1 4
2

Output
2
2.5
*/

int main() {
    
    RollingMedian *rm_ptr = new RollingMedian();
    cout << "Choose the option:\n0. Exit\n1. To add\n2. To get Median\n\n";
    int n;
    cin >> n;
    do {

        if (n == 0) //exit
        {
            break;
        }
        else if (n == 1) //add
        {
            int num;
            cin >> num;
            rm_ptr -> add(num);
        }
        else if (n == 2) //median
        {
            double rolling_median = rm_ptr -> median();
            cout << rolling_median << endl;
        }
        else 
        {
            cout << "Enter correct option\n";
        }

        cin >> n;

    } while(n != 0);
    
    return 0;
}
