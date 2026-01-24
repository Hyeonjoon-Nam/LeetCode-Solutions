class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;

        backtrack(0, candidates, path, res, target);
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());

        return res;
    }

    void backtrack(int start, vector<int>& candidates, vector<int>& path, vector<vector<int>>& res, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        } else if (target < 0) {
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            path.push_back(candidates[i]);
            backtrack(i + 1, candidates, path, res, target - candidates[i]);
            path.pop_back();
        }
    }
};