/*
https://binarysearch.com/problems/Trailing-Zeros
*/

# include <bits/stdc++.h>

using namespace std;

/*
Intuition
Consider a number 6 for example. To solve this problem, we need to find effectively lcm(1, 2, 3, 4, 5, 6). Let the lcm aside for a moment and think about a number that can be multiple of all the numbers from 1 to 6.
Simple, 1 * 2 * 3 * 4 * 5 * 6 = 720.
But this is not the smallest multiple of all the numbers from 1 to 6. why?.
Because some of the factors are counted multiple times. for example, 6 = 2*3,
we have already included 2 and 3 so we must not include 6. After removing those number our sequence become 1 * 2 * 3 * 2 * 5. So, In this sequence, we need to count the number of 2 and 5 because 2 * 5 = 10. but 5 = 2**2 + 1, so it is expected that 2 will be twice of the number of 5 in any sequence. For the counting of zeros, the number of fives will do the job. In the above, example five occurs one time so the answer is 1.
Now finally we need to find a way to count the number of times 5 occur in seq.
it is very simple, log(k, 5) is the number.

Implementation
the log can be easily calculated by using the log function from the math library.

Time Complexity
Only one log and floor operation is performed so O(1)

Space Complexity
no extra variable is created hence O(1)
*/

/*
Input
5

Output
1

Explanation
The smallest x here is 60, 
since 60 is evenly divided by 1, 2, 3, 4, and 5, and has 1 trailing zero.
*/

int getTrailingZeroes(int k) {
    return log(k) / log(5);
}

int main() {
    int k;
    cin >> k;
    cout << getTrailingZeroes(k) << endl;
    return 0;
}