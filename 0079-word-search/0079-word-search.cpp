class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // ================================
        // Approach 1: DFS Backtracking with In-place marking
        // - Time  Complexity: O(N * 3^L)
        //   (N is the number of cells in the board, L is the length of the word)
        // - Space Complexity: O(L)
        //   (The recursion stack depth equls to the length of the word.)
        // - Pros: Memory efficient by using in-place marking instaed of visited array.
        // - Cons: Modifies the input board temporarily.
        // ================================
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (backtrack(board, r, c, word, 0)) return true;
            }
        }
        return false;
    }

    // Approach 1
    bool backtrack(vector<vector<char>>& board, int r, int c, string& word, int index) {
        if (index == word.length()) return true;

        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index])
            return false;
        
        char temp = board[r][c];
        board[r][c] = '#';

        bool found = backtrack(board, r + 1, c, word, index + 1) ||
                     backtrack(board, r - 1, c, word, index + 1) ||
                     backtrack(board, r, c + 1, word, index + 1) ||
                     backtrack(board, r, c - 1, word, index + 1);

        board[r][c] = temp;

        return found;
    }
};