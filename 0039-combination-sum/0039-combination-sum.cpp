class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // ================================
        // Approach 1: Backtracking with Element Reuse & Pruning
        // - Time  Complexity: O(N ^ ((T/M) + 1))
        //   (N: number of candidates, T: target value, M: minimal value in candidates)
        // - Space Complexity: O(T/M)
        //   (The maximum depth of the recursion stack is target divided by the smallest candidate.)
        // - Pros: Efficiently finds all unique combinations, sorting allows for early pruning.
        // - Cons: Can be slow if the target is large ans candidates are very small numbers.
        // ================================
        vector<vector<int>> ans;
        vector<int> path;

        sort(candidates.begin(), candidates.end());
        backtrack(0, candidates, path, ans, target);

        return ans;
    }

    // For approach 1
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