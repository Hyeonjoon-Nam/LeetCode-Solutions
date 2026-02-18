class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // ================================
        // Approach 1: Dynamic Programming (2D Array)
        // - Time  Complexity: O(N)
        //   (Single pass through the price array.)
        // - Space Complexity: O(N)
        //   (2D array to store 'hold' and 'sell' states for each day.)
        // - Pros: Intuitive.
        // - Cons: Uses extra memory.
        // ================================
        // int n = prices.size();
        // if (n < 2) return 0;

        // vector<vector<int>> dp(n, vector<int>(2, 0));
        // dp[0][0] = 0;
        // dp[0][1] = -prices[0];

        // dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
        // dp[1][1] = max(dp[0][1], -prices[1]);

        // for (int i = 2; i < n; i++) {
        //     dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
        //     dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
        // }

        // return dp[n-1][0];

        // ================================
        // Approach 2: Dynamic Programming (Space Optimized)
        // - Time  Complexity: O(N)
        //   (Single pass through the price array.)
        // - Space Complexity: O(1)
        //   (Only a few variables used to track state transitions.)
        // - Pros: Optimal time and space complexity.
        // - Cons: Slightly more complex.
        // ================================
        int n = prices.size();
        if (n < 2) return 0;

        int hold = -prices[0];
        int sell = 0;
        int prev_sell = 0;

        for (int i = 1; i < n; i++) {
            int temp = sell;

            sell = max(sell, hold + prices[i]);
            hold = max(hold, prev_sell - prices[i]);

            prev_sell = temp;
        }
        return sell;
    }
};