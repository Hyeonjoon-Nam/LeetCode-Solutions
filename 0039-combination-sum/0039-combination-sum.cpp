class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        backtrack(0, candidates, path, ans, target);

        return ans;
    }

    void backtrack(int start, vector<int>& candidates, vector<int>& path, vector<vector<int>>& ans, int target) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        else if (target < 0) {
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            backtrack(i, candidates, path, ans, target - candidates[i]);
            path.pop_back();
        }
    }
};