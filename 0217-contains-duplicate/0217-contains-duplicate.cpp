class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // ================================
        // Approach 1: Using set.
        // ================================
        // set<int> seen;

        // for (int x : nums)
        // {
        //     if (seen.find(x) != seen.end())
        //         return true;

        //     seen.insert(x);
        // }
        // return false;

        // ================================
        // Approach 2: Using unordered_set
        // ================================
        // unordered_set<int> seen;

        // for (int x : nums)
        // {
        //     if (seen.find(x) != seen.end())
        //         return true;
            
        //     seen.insert(x);
        // }
        // return false;
        
        // ================================
        // Approach 3: Sorting
        // ================================
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] == nums[i+1]) return true;
        }
        return false;
    }
};