class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // ================================
        // Approach 1: Dynamic Programming
        // - Time  Complexity: O(n * amount)
        //   (n is the number of coin denominations.)
        // - Space Complexity: O(amount)
        //   (The 'dp' array takes O(amont) space.)
        // - Pros: Space efficient.
        // - Cons: Requires unsigned int to handle signed integer overflow.
        // ================================
        vector<unsigned int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};