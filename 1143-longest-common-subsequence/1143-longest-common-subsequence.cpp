class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // ================================
        // Approach 1: Dynamic Programming (2D Array)
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        // int m = text1.length();
        // int n = text2.length();

        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // for (int i = 1; i <= m; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         if (text1[i - 1] == text2[j - 1]) {
        //             dp[i][j] = 1 + dp[i-1][j-1];
        //         }
        //         else {
        //             dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        //         }
        //     }
        // }

        // return dp[m][n];

        // ================================
        // Approach 2: Dynamic Programming (Optimized 1D Array)
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        int m = text1.length();
        int n = text2.length();

        if (m < n) return longestCommonSubsequence(text2, text1);

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= m; i++) {
            int prev = 0;
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];

                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = 1 + prev;
                }
                else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                prev = temp;
            }
        }

        return dp[n];
    }
};