class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Approach 1: Using set.
        // set<int> seen;

        // for (int x : nums)
        // {
        //     if (seen.find(x) != seen.end())
        //         return true;

        //     seen.insert(x);
        // }

        // return false;

        // Approach 2: Using unordered_set
        unordered_set<int> seen;

        for (int x : nums)
        {
            if (seen.find(x) != seen.end())
                return true;
            
            seen.insert(x);
        }
        
        return false;
    }
};