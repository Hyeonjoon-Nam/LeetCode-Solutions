class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // ================================
        // Approach 1: Dynamic Programming
        // - Time  Complexity: O(N * M * K)
        //   (N: string length, M: wordDict size, K: average word length)
        // - Space Complexity: O(N)
        //   (DP array of size n + 1 stores breakability of prefixes.)
        // - Pros: Intuitive, optimal.
        // - Cons: 
        // ================================
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (const string& word : wordDict) {
                int len = word.length();

                if (i >= len && dp[i - len]) {
                    if (s.compare(i - len, len, word) == 0) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};