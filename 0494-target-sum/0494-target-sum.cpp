class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
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