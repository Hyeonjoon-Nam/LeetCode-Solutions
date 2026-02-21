class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // ================================
        // Approach 1: Transpse & Reverse
        // - Time  Complexity: O(N²)
        //   (We visit each element twice, once for transpose, once for reverse.)
        // - Space Complexity: O(1)
        //   (Rotation is performed in-place.)
        // - Pros: Neat.
        // - Cons: 
        // ================================
        transpose(matrix);
        reverseRow(matrix);
    }

    // For approach 1
    void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    // For approach 1
    void reverseRow(vector<vector<int>>& matrix) {
        for (vector<int>& v : matrix) {
            reverse(v.begin(), v.end());
        }
    }
};