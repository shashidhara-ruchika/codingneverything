/*
https://binarysearch.com/problems/Narcissistic-Number
*/

# include <bits/stdc++.h>

using namespace std;

int get_num_digits(int n)
{
    return log10((double)abs(n)) + 1;
}

bool solve(int n) {
    int num = n;
    int total_num_digits = get_num_digits(n);
    int sum_power = 0;
    while(n > 0)
    {
        sum_power += pow(n % 10, total_num_digits);
        n = n / 10;
    }
    if (num == (int)sum_power)
        return true;
    else
        return false;
}

int main() {
    int num;
    cin >> num;
    cout << solve(num) << endl;
    return 0;
}