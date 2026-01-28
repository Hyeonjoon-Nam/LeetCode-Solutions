class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // ================================
        // Approach 1: Backtracking with hashing
        // - Time  Complexity: O(N!)
        //   (As we place queens row by row, the number of available columns decreases.)
        // - Space Complexity: O(N²)
        //   (To store the board and the recursion stack, plus O(N) for hash sets.)
        // - Pros: O(1) validity check for columns and diagonals using Sets.
        // - Cons: Exponential time complexity, which is inherent to the N-Queens problem.
        // ================================
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        unordered_set<int> cols;
        unordered_set<int> posDiag;
        unordered_set<int> negDiag;
        
        backtrack(0, n, board, res, cols, posDiag, negDiag);

        return res;
    }

    // For approach 1
    void backtrack(int r, int n, vector<string>& board, vector<vector<string>>& res, 
    unordered_set<int>& cols, unordered_set<int>& posDiag, unordered_set<int>& negDiag) {
        if (r == n) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (cols.count(c) || posDiag.count(r + c) || negDiag.count(r - c)) {
                continue;
            }

            board[r][c] = 'Q';
            cols.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);
            
            backtrack(r + 1, n, board, res, cols, posDiag, negDiag);

            board[r][c] = '.';
            cols.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
        }
    }
};