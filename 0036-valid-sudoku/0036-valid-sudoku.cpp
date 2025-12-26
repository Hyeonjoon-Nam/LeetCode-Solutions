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
                for (int col = i; col < i + 3; col++)
                {
                    for (int row = j; row < j + 3; row++)
                    {
                        if (board[col][row] == '.') continue;
                        if (hash.find(board[col][row]) != hash.end())
                            return false;
                        
                        hash.insert(board[col][row]);
                    }
                }
            }
        }

        // Check each col
        for (int col = 0; col < size; ++col)
        {
            hash.clear();
            for (int row = 0; row < size; ++row)
            {
                if (board[col][row] == '.') continue;
                if (hash.find(board[col][row]) != hash.end())
                    return false;
                
                hash.insert(board[col][row]);
            }
        }

        // Check each row
        for (int row = 0; row < size; ++row)
        {
            hash.clear();
            for (int col = 0; col < size; ++col)
            {
                if (board[col][row] == '.') continue;
                if (hash.find(board[col][row]) != hash.end())
                    return false;
                
                hash.insert(board[col][row]);
            }
        }

        return true;
    }
};