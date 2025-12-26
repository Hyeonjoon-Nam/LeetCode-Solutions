class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // ================================
        // Approach 1: Sorting
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        if (nums.size() == 0) return 0;
        
        sort(nums.begin(), nums.end());
        int m = 1;
        int cur = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                continue;
            else if (nums[i] + 1 == nums[i + 1])
            {
                cur++;
                m = max(m, cur);   
            }
            else
            {
                cur = 1;
            }
        }
        return m;
    }
};