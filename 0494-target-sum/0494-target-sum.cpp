class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // ================================
        // Approach 1: Dynamic Programming
        // - Time  Complexity: O(N * P)
        //   (N: nums.size(), P: (totalSum + target) / 2. We iterate the grid once.)
        // - Space Complexity: O(P)
        //   (1D DP array stores ways to achieve each subset sum.)
        // - Pros: Optimal.
        // - Cons: 
        // ================================
        int n = nums.size();
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        if (abs(target) > totalSum) return 0;
        int P = totalSum + target;
        if (P & 1) return 0;
        P >>= 1;

        vector<int> dp(P + 1);
        dp[0] = 1;

        for (int num : nums) {
            for (int i = P; i>= num; i--) {
                dp[i] = dp[i] + dp[i - num];
            }
        }

        return dp[P];
    }
};