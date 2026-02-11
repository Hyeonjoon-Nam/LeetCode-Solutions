class Solution {
public:
    int rob(vector<int>& nums) {
        // ================================
        // Approach 1: Dynamic Programming
        // - Time  Complexity: O(n)
        //   (One pass through the house.)
        // - Space Complexity: O(1)
        //   (Constant space used.)
        // - Pros: Optimal time and space complexitiy.
        // - Cons: Cannot reconstruct the exact list of robbed houses without O(n) space.
        // ================================
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        int prev1 = nums[0];
        int prev2 = max(nums[0], nums[1]);
        int current = 0;

        for (int i = 2; i < n; i++) {
            current = max(prev2, prev1 + nums[i]);

            prev1 = prev2;
            prev2 = current;
        }
        return prev2;
    }
};