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

        
        // ================================
        // Approach 2: std::vector::find
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            int cur = nums[i];

            auto it = find(nums.begin(), nums.end(), target - cur);
            if (it != nums.end())
            {
                int dist = it - nums.begin();
                if (dist == 0) continue;

                return {i, dist};
            }
        }
    }
};