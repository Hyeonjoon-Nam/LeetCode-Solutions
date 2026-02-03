class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // ================================
        // Approach 1: DFS
        // - Time  Complexity: O(M * N)
        //   (M is the rows, N is the columns. Visits each node at most once.)
        // - Space Complexity: O(M * N)
        //   (In the worst case, recursion stack depth is M * N.)
        // - Pros: Optimal, meets the requirement in-place replacing.
        // - Cons: Potential for Stack Overflow on very large grids.
        // ================================
        if (board.empty()) return;

        int m = board.size();
        int n = board[0].size();

        vector<pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') backtrack(board, i, 0);
            if (board[i][n - 1] == 'O') backtrack(board, i, n - 1);
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') backtrack(board, 0, i);
            if (board[m - 1][i] == 'O') backtrack(board, m - 1, i);
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                else if (board[r][c] == 'T') board[r][c] = 'O';
            }
        }
    }

    // For approach 1
    void backtrack(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != 'O') return;
        
        board[r][c] = 'T';

        backtrack(board, r+1, c);
        backtrack(board, r-1, c);
        backtrack(board, r, c+1);
        backtrack(board, r, c-1);

        return;
    }
};