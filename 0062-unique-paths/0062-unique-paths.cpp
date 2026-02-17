class Solution {
public:
    int uniquePaths(int m, int n) {
        // ================================
        // Approach 1: Dynamic Programming (2D Array)
        // - Time  Complexity: O(m * n)
        //   (Iterates through each cell in the grid once.)
        // - Space Complexity: O(m * n)
        //   (Stores path counts for the entire grid.)
        // - Pros: Intuitive, mirrors the problem's 2D structure.
        // - Cons: Suboptimal memory usage for large grids.
        // ================================
        // vector<vector<int>> dp(m, vector<int>(n, 1));

        // for (int i = 1; i < m; i++) {
        //     for (int j = 1; j < n; j++) {
        //         dp[i][j] = dp[i-1][j] + dp[i][j-1];
        //     }
        // }
        // return dp[m-1][n-1];

        // ================================
        // Approach 2: Dynamic Programming (Optimized 1D Array)
        // - Time  Complexity: O(m * n)
        //   (Still processes every cell once.)
        // - Space Complexity: O(n)
        //   (Reduces memory to a single row)
        // - Pros: Significantly better space efficiency, better cache locality.
        // - Cons: Less intuitive.
        // ================================
        vector<int> dp(n, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};