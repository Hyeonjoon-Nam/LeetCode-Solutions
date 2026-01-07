class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // ================================
        // Approach 1: Linear
        // - Time  Complexity: O(m*n)
        //   (Lineary iterate all the elements)
        // - Space Complexity: O(1)
        //   (No extra space used)
        // - Pros: Intuitive
        // - Cons: Doesn't meet the requirement O(log(m*n))
        // ================================
        // int row = matrix.size();
        // int col = matrix[0].size();

        // for (int r = 0; r < row; r++)
        // {
        //     for (int c = 0; c < col; c++)
        //     {
        //         int num = matrix[r][c];
        //         if (num == target) return true;
        //         else if (num < target) continue;
        //         else return false;
        //     }
        // }
        // return false;

        // ================================
        // Approach 2: Binary search
        // - Time  Complexity: O(log(m*n))
        //   (Treat the 2D matrix as a sorted 1D array)
        // - Space Complexity: O(1)
        //   (No extra space used)
        // - Pros: Cleaner logic, single binary search pass
        // - Cons: 
        // ================================
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int num = matrix[mid/n][mid%n];

            if (num == target) return true;
            else if (num < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};