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

        int center = 0, left = 0, right = 0;
        int maxLength = 0;
        string res;
        for (int i = 0; i < s.length(); i++) {
            string odd = oddPalindrome(i, s);
            string even = evenPalindrome(i, i+1, s);

            if (maxLength < odd.length()) {
                maxLength = odd.length();
                res = odd;
            }
            if (maxLength < even.length()) {
                maxLength = even.length();
                res = even;
            }
        }
        return res;
    }

    string oddPalindrome(int center, const string& s) {
        int left = center - 1;
        int right = center + 1;

        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        left++;
        right--;
        return s.substr(left, right - left + 1);
    }
    
    string evenPalindrome(int left, int right, const string& s) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        left++;
        right--;
        return s.substr(left, right - left + 1);
    }
};