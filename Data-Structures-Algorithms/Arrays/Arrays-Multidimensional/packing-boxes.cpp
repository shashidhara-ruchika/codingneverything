/*
https://binarysearch.com/problems/Packing-Boxes
*/

#include <bits/stdc++.h>
using namespace std;

class pack_list {
    private:
        vector<int> nums;
        vector<vector<int>> sublist;
        void pack_into_sublist();

    public:
        void input_nums();
        vector<vector<int>> get_packed_list();
};

void pack_list :: input_nums() {
    int n, num; 
    cin >> n;
    while(n-- > 0) {
        cin >> num;
        this -> nums.push_back(num);
    }
}

vector<vector<int>> pack_list :: get_packed_list() {
    pack_into_sublist();
    return this -> sublist;
}

void pack_list :: pack_into_sublist() {
    
    if (nums.size() == 0)
        return;
           
    vector<int> v;
    v.push_back(nums[0]);

    if (nums.size() == 1) {
        this -> sublist.push_back(v);
        return;
    }

    for(int i = 1; i < this -> nums.size(); i++) {
        if(this -> nums[i] != this -> nums[i - 1]) {
            this -> sublist.push_back(v);
            v.clear();            
            v.push_back(this -> nums[i]);
        }
        else {
            v.push_back(this -> nums[i]);
        }
    }
    this -> sublist.push_back(v);
    return;
}

/*
Input
10
4 4 1 6 6 6 1 1 1 1

Output
4 4
1
6 6 6
1 1 1 1
*/

int main() {
    pack_list *pl_ptr = new pack_list();
    pl_ptr -> input_nums();
    vector<vector<int>> packed_sublist = pl_ptr -> get_packed_list();

    for(int v_list = 0; v_list < packed_sublist.size(); v_list++) {
        for(auto v_it : packed_sublist[v_list]) 
            cout << v_it << " ";
        cout << endl;
    }
    return 0;
}