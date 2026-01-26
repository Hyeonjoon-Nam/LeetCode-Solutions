class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // ================================
        // Approach 1: Backtracking with Pruning
        // - Time  Complexity: O(N * 2^N)
        //   (Sorting takes O(N log N), and there are at most 2^N subsets)
        // - Space Complexity: O(N)
        //   (The depth of the recursion stack is N.)
        // - Pros: Efficiently hadnles duplicate elements without post-processing.
        // - Cons: Requires the input array to be sorted first.
        // ================================
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> path;

        backtrack(0, path, nums, res);
        return res;
    }

    // For approach 1
    void backtrack(int start, vector<int>& path, vector<int>& nums, vector<vector<int>>& res) {
        res.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;

            path.push_back(nums[i]);
            backtrack(i + 1, path, nums, res);
            path.pop_back();
        }
    }
};