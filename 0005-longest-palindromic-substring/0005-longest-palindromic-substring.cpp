class Solution {
public:
    string longestPalindrome(string s) {
        // ================================
        // Approach 1: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        if (s.length() <= 1) return s;

        int start = 0;
        int maxLen = 0;
        string res;

        for (int i = 0; i < s.length(); i++) {
            int len1 = Palindrome(s, i, i);
            int len2 = Palindrome(s, i, i + 1);

            int currentMax = max(len1, len2);

            if (currentMax > maxLen) {
                maxLen = currentMax;
                start = i - (currentMax - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }

    int Palindrome(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};