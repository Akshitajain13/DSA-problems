class Solution {
public:
    vector<vector<int>> dp;

    int solve(int W, vector<int> &val, vector<int> &wt, int n) {
        if (n == 0 || W == 0)
            return 0;

        if (dp[n][W] != -1)
            return dp[n][W];

        if (wt[n - 1] > W) {
            return dp[n][W] = solve(W, val, wt, n - 1);
        }

        return dp[n][W] = max(
            val[n - 1] + solve(W - wt[n - 1], val, wt, n - 1),
            solve(W, val, wt, n - 1)
        );
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        dp.assign(n + 1, vector<int>(W + 1, -1));
        return solve(W, val, wt, n);
    }
};
