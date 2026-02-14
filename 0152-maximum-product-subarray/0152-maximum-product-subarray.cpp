class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // ================================
        // Approach 1: Dynamic Programming
        // - Time  Complexity: O(N)
        //   (Single pass through the array.)
        // - Space Complexity: O(1)
        //   (Constant space used.)
        // - Pros: Optimal time & space efficiency.
        // - Cons: Potential for integer overflow.
        // ================================
        int res = nums[0];
        int curMax = nums[0], curMin = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];

            int tempMax = max(curr, max(curMax * curr, curMin * curr));
            curMin = min(curr, min(curMax * curr, curMin * curr));

            curMax = tempMax;
            res = max(res, curMax);
        }

        return res;
    }
};