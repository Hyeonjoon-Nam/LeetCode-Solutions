class Solution {
public:
    int countSubstrings(string s) {
        // ================================
        // Approach 1: Expand from center
        // - Time  Complexity: O(N²)
        //   (N centers, and each expansion takes up to O(N).)
        // - Space Complexity: O(1)
        //   (Only constant space used.)
        // - Pros: Optimal space.
        // - Cons: Still O(N²) time.
        // ================================
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++) {
            expand(s, i, i, count);
            expand(s, i, i+1, count);
        }

        return count;
    }

    // For approach 1
    void expand(const string& s, int left, int right, int& count) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
            count++;
        }
    }
};