class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // ================================
        // Approach 1: Linear
        // - Time  Complexity: O(m*n)
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        int row = matrix.size();
        int col = matrix[0].size();

        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                int num = matrix[r][c];
                if (num == target) return true;
                else if (num < target) continue;
                else return false;
            }
        }
        return false;
        // ================================
        // Approach 1: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
    }
};