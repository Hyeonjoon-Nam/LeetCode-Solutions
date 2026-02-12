class Solution {
public:
    string longestPalindrome(string s) {
        // ================================
        // Approach 1: Expand from centers
        // - Time  Complexity: O(N²)
        //   (Each of the N characters is treated as a potential center, expanding up to N times.)
        // - Space Complexity: O(1)
        //   (Only constant space used.)
        // - Pros: Space efficient.
        // - Cons: Not optimal (Time complexity O(N²))
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