class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // ================================
        // Approach 1: Backtracking with Pruning
        // - Time  Complexity: O(2^N)
        //   (In the worst case, we explore all subsets, but pruning significantly reduces the constant factor.)
        // - Space Complexity: O(N)
        //   (Maximum recursion depth is N)
        // - Pros: Handles duplicate candidates efficiently by skipping identical elements at the same level.
        // - Cons: Sorting is mandatory for the duplicate-skipping logic to work.
        // ================================
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;

        backtrack(0, candidates, path, res, target);

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
            if (candidates[i] > target) break;

            path.push_back(candidates[i]);
            backtrack(i + 1, candidates, path, res, target - candidates[i]);
            path.pop_back();
        }
    }
};