class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // ================================
        // Approach 1: Backtrack with placement constraints
        // - Time  Complexity: O(4^n * n)
        //   (nth Catalan number, representing the count of valid parentheses.)
        // - Space Complexity: O(n)
        //   (The maximum depth of the recursion tree is 2n)
        // - Pros: Only explores valid paths.
        // - Cons: 
        // ================================
        int open = 0, close = 0;

        string path = "";
        vector<string> res;

        backtrack(open, close, n, path, res);

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