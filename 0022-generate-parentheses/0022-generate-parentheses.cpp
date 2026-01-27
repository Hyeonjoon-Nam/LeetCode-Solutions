class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // ================================
        // Approach 1: Backtrack with pass-by-value
        // - Time  Complexity: O(4^n * √n)
        //   (Specifically, it's the nth Catalan number, which counts valid parentheses pairs.)
        // - Space Complexity: O(n)
        //   (The maximum depth of the recursion tree is 2n)
        // - Pros: Extremely clean and readable. Avoids manual state backtracking (un-choose).
        // - Cons: Minor overhead due to string allocations during each recursive call.
        // ================================
        vector<string> res;

        backtrack(0, 0, n, "", res);

        return res;
    }

    void backtrack(int open, int close, int n, string path, vector<string>& res) {
        if (path.size() == n * 2) {
            res.push_back(path);
            return;
        }

        if (open < n) backtrack(open + 1, close, n, path + "(", res);
        if (close < open) backtrack(open, close + 1, n, path + ")", res);
    }
};