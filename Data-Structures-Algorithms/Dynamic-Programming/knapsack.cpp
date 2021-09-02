#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, vector<int> wt, vector<int> val, int n)
{
	// making and initializing dp array
	int dp[W + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i < n + 1; i++) {
		for (int w = W; w >= 0; w--) {

			if (wt[i - 1] <= w)
				// finding the maximum value
				dp[w] = max(dp[w],
							dp[w - wt[i - 1]] + val[i - 1]);
		}
	}

	return dp[W]; // returning the maximum value of knapsack
}
int main()
{
	//int val[] = { 60, 100, 120 };
	//int wt[] = { 10, 20, 30 };
    int currval[] = {175, 133, 109, 210, 97};
    int futuval[] = {200, 125, 128, 228, 133};

    vector<int> weight;
    vector<int> profit;

    int n = 5;

    for (int i = 0; i < n; i++) {
        int diffp = futuval[i] - currval[i];
        if (diffp > 0) {
            weight.push_back(currval[i]);
            profit.push_back(diffp);
        }
    }

	int W = 250;
	cout << knapSack(W, weight, profit, n);
	return 0;
}
