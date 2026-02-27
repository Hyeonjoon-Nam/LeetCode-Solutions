class Solution {
public:
    int minDistance(string word1, string word2) {
        // ================================
        // Approach 1: 2D Dynamic Programming
        // - Time  Complexity: O(M * N)
        //   (We iterate through every cell in the (M+1) * (N+1) matrix once.)
        // - Space Complexity: O(M * N)
        //   (Allocates a 2D vector to store all intermediate states.)
        // - Pros: Intuitive.
        // - Cons: 
        // ================================
        int m = word1.length(), n = word2.length();
        if (m == 0) return n;
        if (n == 0) return m;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int j = 0; j <= n; ++j) dp[0][j] = j;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j - 1];
                }
                else {
                    int replaced = dp[i-1][j-1];
                    int deleted = dp[i-1][j];
                    int inserted = dp[i][j-1];

                    dp[i][j] = min({replaced, deleted, inserted}) + 1;
                }
            }
        }
        return dp[m][n];
    }
};