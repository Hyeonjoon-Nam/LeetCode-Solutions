class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // ================================
        // Approach 1: Backtracking (Decision Tree)
        // - Time  Complexity: O(N * 2^N)
        //   (There are 2^N possible subsets, and for each subset, 
        //   we take O(N) time to copy the current path to the result list.)
        // - Space Complexity: O(N)
        //   (The recursion stack and 'path' vector use O(N) space.)
        // - Pros: Very standard recursive approach. Intuitive.
        // - Cons: Exponential time growth.
        // ================================
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(0, nums, path, ans);

        return ans;
    }

    // For approach 1
    void backtrack(int start, vector<int>& nums, vector<int>& path, vector<vector<int>>& ans) {
        ans.push_back(path);
        
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(i + 1, nums, path, ans);
            path.pop_back();
        }
    }
};