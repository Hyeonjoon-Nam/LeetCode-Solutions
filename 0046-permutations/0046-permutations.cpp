class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // ================================
        // Approach 1: Backtracking with 'used' array
        // - Time  Complexity: O(N * N!)
        //   (There are N! permutations, and copying each to 'res' takes O(N) time.)
        // - Space Complexity: O(N)
        //   (Recursion depth is N, 'path' and 'used' arrays take O(N) space.)
        // - Pros: Intuitive.
        // - Cons: Requires extra space for the 'used' array.
        // ================================
        // vector<int> path;
        // vector<bool> used(nums.size(), false);
        // vector<vector<int>> res;
        
        // backtrack(nums, path, used, res);

        // return res;

        // ================================
        // Approach 2: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        vector<vector<int>> res;
        
        backtrack_swap(0, nums, res);

        return res;
    }

    // For approach 1
    void backtrack(vector<int>& nums, vector<int>& path, vector<bool>& used, vector<vector<int>>& res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            used[i] = true;
            path.push_back(nums[i]);

            backtrack(nums, path, used, res);

            path.pop_back();
            used[i] = false;
        }
    }

    // For approach 2
    void backtrack_swap(int start, vector<int>& nums, vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            backtrack_swap(start + 1, nums, res);
            swap(nums[i], nums[start]);
        }
    }
};