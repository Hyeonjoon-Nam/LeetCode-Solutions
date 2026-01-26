class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> path;

        backtrack(0, path, nums, res);
        return res;
    }

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