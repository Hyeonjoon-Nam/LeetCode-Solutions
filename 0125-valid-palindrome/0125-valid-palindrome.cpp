class Solution {
public:
    bool isPalindrome(string s) {
        // ================================
        // Approach 1: Two pointers
        // - Time  Complexity: O(N)
        //   (Iterate all characters)
        // - Space Complexity: O(1)
        //   (No extra space used)
        // - Pros: Intuitive
        // - Cons: 
        // ================================
        int n = s.length();
        if (n == 0) return true;

        int p0 = 0;
        int p1 = n - 1;

        while (p0 < p1)
        {
            // if (!isalpha(s[p0]) && !isdigit(s[p0])) { p0++; continue; }
            // if (!isalpha(s[p1]) && !isdigit(s[p1])) { p1--; continue; }
            if (!isalnum(s[p0])) { p0++; continue; }
            if (!isalnum(s[p1])) { p1--; continue; }
            
            if (tolower(s[p0]) != tolower(s[p1])) return false;
            ++p0;
            --p1;
        }
        return true;

        
        // ================================
        // Approach 1: Two pointers
        // - Time  Complexity: O(N)
        //   (Iterate all characters)
        // - Space Complexity: O(1)
        //   (No extra space used)
        // - Pros: Intuitive
        // - Cons: 
        // ================================
    }
};