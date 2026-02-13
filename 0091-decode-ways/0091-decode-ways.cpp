class Solution {
public:
    int numDecodings(string s) {
        // ================================
        // Approach 1: Dynamic Programming (Lineary Array)
        // - Time  Complexity: O(N)
        //   (Single pass through the string to fill the dp table.)
        // - Space Complexity: O(N)
        //   (Stores decoding counts for each prefix of the string.)
        // - Pros: Intuitive.
        // - Cons: Uses extra memory.
        // ================================
        // if (s.empty() || s[0] == '0') return 0;

        // int n = s.length();
        // vector<int> dp(n + 1, 0);

        // dp[0] = 1;
        // dp[1] = 1;

        // for (int i = 2; i <= n; i++) {
        //     int oneDigit = s[i - 1] - '0';
        //     if (oneDigit >= 1 && oneDigit <= 9) {
        //         dp[i] += dp[i - 1];
        //     }

        //     int twoDigit = (s[i - 2] - '0') * 10 + oneDigit;
        //     if (twoDigit >= 10 && twoDigit <= 26) {
        //         dp[i] += dp[i - 2];
        //     }
        // }
        // return dp[n];


        // ================================
        // Approach 2: Dynamic Programming (Space Optimized)
        // - Time  Complexity: O(N)
        //   (Single pass through the string.)
        // - Space Complexity: O(1)
        //   (Only uses a fixed number of variables.)
        // - Pros: Space efficient.
        // - Cons: 
        // ================================
        if (s.empty() || s[0] == '0') return 0;

        int n = s.length();

        int prev1 = 1;
        int prev2 = 1;
        int current = 1;

        for (int i = 2; i <= n; i++) {
            current = 0;
            int oneDigit = s[i - 1] - '0';
            if (oneDigit >= 1 && oneDigit <= 9) {
                current += prev1;
            }

            int twoDigit = (s[i - 2] - '0') * 10 + oneDigit;
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += prev2;
            }

            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
};