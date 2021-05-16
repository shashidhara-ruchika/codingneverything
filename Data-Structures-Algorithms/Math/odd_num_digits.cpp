/*
https://binarysearch.com/problems/Odd-Number-of-Digits
*/

# include <bits/stdc++.h>

using namespace std;

bool is_digits_odd_num(int n)
{
    int digits = log10((double)abs(n)) + 1;
    //cout << n << " " << digits << endl;
    if (digits % 2)
        return true;
    else
        return false;
}

int solve(vector<int>& nums) 
{
    int total_odd_digits = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(is_digits_odd_num(nums[i]))
            total_odd_digits++;
    }
    return total_odd_digits;    
}

/*
Input
5
1 800 2 10 3

Output
4

Explanation
1, 800, 2, 3 have odd number of digits.
*/

int main()
{
    int n, num;
    cin >> n;
    vector<int> nums;
    while(n-- > 0) {
        cin >> num;
        nums.push_back(num);
    }
    cout << solve(nums) << endl;
    return 0;
}