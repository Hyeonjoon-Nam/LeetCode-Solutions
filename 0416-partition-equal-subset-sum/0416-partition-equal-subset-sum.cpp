class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // ================================
        // Approach 1: Dynamic Programming
        // - Time  Complexity: O(m * n)
        //   (m is the target sum (total sum / 2), n is the number of array elemetns.)
        // - Space Complexity: O(m)
        //   (1D DP array stores whether each sum up to T is achievable.)
        // - Pros: Optimal.
        // - Cons: 
        // ================================
        int sum = 0;
        for (int x : nums) sum += x;

        if (sum & 1) return false;
        int target = sum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                if (dp[j - num]) {
                    dp[j] = true;
                }
            }
            if (dp[target]) return true;
        }
        return dp[target];
    }
};