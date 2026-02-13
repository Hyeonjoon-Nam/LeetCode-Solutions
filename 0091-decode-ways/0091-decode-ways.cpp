class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;

        int n = s.length();
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        int temp = (s[0] - '0') * 10 + s[1] - '0';
        if (s[1] - '0' == 0 && temp >= 30) return 0;
        if (temp >= 10 && temp <= 26 && s[1] - '0' != 0)
            dp[1] = 2;
        else
            dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            int num1 = s[i] - '0';
            int num2 = (s[i - 1] - '0') * 10 + num1;

            if (num2 == 0 || (num1 == 0 && num2 > 26)) return 0;

            if (num1 == 0) {
                dp[i] += dp[i - 2];
            }
            else {
                dp[i] += dp[i - 1];
                if (num2 >= 10 && num2 <= 26)
                    dp[i] += dp[i - 2];
            }
        }

        for (int x : dp) cout<<x<<endl;

        return dp[n-1];
    }
};