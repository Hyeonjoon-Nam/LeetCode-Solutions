class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // ================================
        // Approach 1: Hash map
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        unordered_set<int> hash;
        int size = 9;
        
        // Check each 3 * 3 cell
        for (int i = 0; i < size; i += 3)
        {
            for (int j = 0; j < size; j += 3)
            {
                hash.clear();
                for (int row = i; row < i + 3; row++)
                {
                    for (int col = j; col < j + 3; col++)
                    {
                        if (board[row][col] == '.') continue;
                        if (hash.find(board[row][col]) != hash.end())
                            return false;
                        
                        hash.insert(board[row][col]);
                    }
                }
            }
        }

        // Check each col
        for (int row = 0; row < size; ++row)
        {
            hash.clear();
            for (int col = 0; col < size; ++col)
            {
                if (board[row][col] == '.') continue;
                if (hash.find(board[row][col]) != hash.end())
                    return false;
                
                hash.insert(board[row][col]);
            }
        }

        // Check each row
        for (int col = 0; col < size; ++col)
        {
            hash.clear();
            for (int row = 0; row < size; ++row)
            {
                if (board[row][col] == '.') continue;
                if (hash.find(board[row][col]) != hash.end())
                    return false;
                
                hash.insert(board[row][col]);
            }
        }

        return true;
    }
};