class Solution {
public:
    int rob(vector<int>& nums) {
        // ================================
        // Approach 1: Dynamic Programming
        // - Time  Complexity: O(N)
        //   (Two linear passes: 0 to n-2, 1 to n-1, so O(2N))
        // - Space Complexity: O(1)
        //   (Constant space used.)
        // - Pros: Optimal time and space.
        // - Cons: 
        // ================================
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }

private:
    // For approach 1
    int robLinear(vector<int>& nums, int start, int end) {
        int prev1 = 0;
        int prev2 = 0;
        int current;

        for (int i = start; i <= end; i++) {
            current = max(prev2, prev1 + nums[i]);
            prev1 = prev2;
            prev2 = current;
        }
        return prev2;
    }
};