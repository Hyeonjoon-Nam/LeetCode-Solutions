class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // ================================
        // Approach 1: Dynamic Programming
        // - Time  Complexity: O(N * M)
        //   (N is amount, M is the number of coin denominations.)
        // - Space Complexity: O(N)
        //   (An array of size amount + 1 is used to store minimum coins.)
        // - Pros: Optimal time complexity.
        // - Cons: Requires O(N) extra space.
        // ================================
        if (amount == 0) return 0;
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        
        for (int i = 0; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};