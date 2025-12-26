class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // ================================
        // Approach 1: Hash map
        // - Time  Complexity: O(N)
        //   (Use multiple for-loop, but the total number of call is equals to O(N))
        // - Space Complexity: O(N)
        //   (To store numbers to unordered_set)
        // - Pros: Intuitive
        // - Cons: 
        // ================================
        // int size = 9;
        
        // // Check each 3 * 3 cell
        // for (int i = 0; i < size; i += 3)
        // {
        //     for (int j = 0; j < size; j += 3)
        //     {
        //         hash.clear();
        //         for (int row = i; row < i + 3; row++)
        //         {
        //             for (int col = j; col < j + 3; col++)
        //             {
        //                 if (board[row][col] == '.') continue;
        //                 if (hash.find(board[row][col]) != hash.end())
        //                     return false;
                        
        //                 hash.insert(board[row][col]);
        //             }
        //         }
        //     }
        // }

        // // Check each col
        // for (int row = 0; row < size; ++row)
        // {
        //     hash.clear();
        //     for (int col = 0; col < size; ++col)
        //     {
        //         if (board[row][col] == '.') continue;
        //         if (hash.find(board[row][col]) != hash.end())
        //             return false;
                
        //         hash.insert(board[row][col]);
        //     }
        // }

        // // Check each row
        // for (int col = 0; col < size; ++col)
        // {
        //     hash.clear();
        //     for (int row = 0; row < size; ++row)
        //     {
        //         if (board[row][col] == '.') continue;
        //         if (hash.find(board[row][col]) != hash.end())
        //             return false;
                
        //         hash.insert(board[row][col]);
        //     }
        // }

        // return true;

        
        // ================================
        // Approach 2: Single pass with fixed size array
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        // int size = 9;
        // vector<vector<bool>>  rows(size, vector<bool>(size, 0));
        // vector<vector<bool>>  cols(size, vector<bool>(size, 0));
        // vector<vector<bool>> boxes(size, vector<bool>(size, 0));

        // for (int row = 0; row < size; row++)
        // {
        //     for (int col = 0; col < size; col++)
        //     {
        //         if (board[row][col] == '.') continue;
        //         int pos = board[row][col] - '1';

        //         if (rows[row][pos] == true) return false;
        //         rows[row][pos] = true;

        //         if (cols[col][pos] == true) return false;
        //         cols[col][pos] = true;

        //         int index = (row / 3) * 3 + col / 3;
        //         if (boxes[index][pos] == true) return false;
        //         boxes[index][pos] = true;
        //     }
        // }
        // return true;

        
        // ================================
        // Approach 3: Bit Manipulation
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        const int size = 9;
        int rows[size] = {0};
        int cols[size] = {0};
        int boxes[size] = {0};
        
        for (int row = 0; row < size; row++)
        {
            for (int col = 0; col < size; col++)
            {
                if (board[row][col] == '.') continue;

                int val = board[row][col] - '0';
                int pos = 1 << (val - 1);

                if (rows[row] & pos) return false;
                rows[row] |= pos;

                if (cols[col] & pos) return false;
                cols[col] |= pos;
                
                int index = (row / 3) * 3 + col / 3;
                if (boxes[index] & pos) return false;
                boxes[index] |= pos;
            }
        }
        return true;
    }
};