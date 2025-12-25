class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // ================================
        // Approach 1: brute force
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        int size = nums.size();
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (i == j) continue;

                if (nums[i] + nums[j] == target) return { i, j };
            }
        }
        return {};
    }
};