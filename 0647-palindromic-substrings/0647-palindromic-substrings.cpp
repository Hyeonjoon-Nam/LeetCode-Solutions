class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++) {
            expand(s, i, i, count);
            expand(s, i, i+1, count);
        }

        return count;
    }

    void expand(const string& s, int left, int right, int& count) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
            count++;
        }
    }
};