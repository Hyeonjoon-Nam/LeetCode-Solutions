class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverseRow(matrix);
    }

    void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void reverseRow(vector<vector<int>>& matrix) {
        for (vector<int>& v : matrix) {
            reverse(v.begin(), v.end());
        }
    }
};