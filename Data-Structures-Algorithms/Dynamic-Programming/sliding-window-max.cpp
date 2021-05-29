/*
https://binarysearch.com/problems/Sliding-Window-Max
*/

# include <bits/stdc++.h>

using namespace std;

class Sliding_Window {
    private:
        vector<int> nums;
        void input_vector();
        int find_max_ele_index(int start, int end);
    public:
        Sliding_Window();
        vector<int> get_each_sliding_window_max(int k);
};

Sliding_Window :: Sliding_Window() {
    input_vector();
}

void Sliding_Window :: input_vector() {
    int n, num;
    cin >> n;
    while (n-- > 0) {
        cin >> num;
        nums.push_back(num);
    }
}

int Sliding_Window :: find_max_ele_index(int start, int end) {
    int index = 0;
    int max_val = -1;
    for(int i = start; i < end; i++) {
        if (nums[i] >= max_val) {
            max_val = nums[i];
            index = i;
        }
    }
    return index;
}

vector<int> Sliding_Window :: get_each_sliding_window_max(int k) {
    if (k > nums.size()) {
        vector<int> max_ele(1, 0);
        max_ele[0] = nums[find_max_ele_index(0, nums.size())];
        return max_ele;
    }

    vector<int> max_ele;
    int curr_max_index = find_max_ele_index(0, k);
    max_ele.push_back(nums[curr_max_index]);
    
    for (int i = 1; i < nums.size() - k + 1; i++) {
        //cout << i << " " << nums[i + k - 1] << endl;
        if (nums[i + k - 1] <= nums[curr_max_index]) {
            if (curr_max_index != i - 1) {
                max_ele.push_back(nums[curr_max_index]);
            }
            else {                
                curr_max_index = find_max_ele_index(i, i + k);                
                max_ele.push_back(nums[curr_max_index]);
            }
        }
        else {
            curr_max_index = i + k - 1;
            max_ele.push_back(nums[curr_max_index]);
        }
    }
    
    return max_ele;
    
}

/*
Input
6
10 5 2 7 8 7
3

Output
10 7 8 8
*/

int main() {
    Sliding_Window *sw_ptr = new Sliding_Window();
    int k; 
    cin >> k;
    vector<int> nums = sw_ptr -> get_each_sliding_window_max(k);
    for(auto n : nums)
        cout << n << " ";
    cout << endl;
    return 0;
}