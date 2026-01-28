class Solution {
public:
    vector<vector<string>> partition(string s) {
        // ================================
        // Approach 1: Backtracking
        // - Time  Complexity: O(N * 2^N)
        //   (There are 2^(N-1) possible ways to partition the string, for each way, palindrome checks takes O(N))
        // - Space Complexity: O(N)
        //   (The maximum depth of the recursion stack is the length of the string N)
        // - Pros: Finds all possible valid partitions. Prunes invalid branches early via palindrome check.
        // - Cons: Involves multiple string allocations due to substr(), which can be costly for large inputs.
        // ================================
        vector<vector<string>> res;
        vector<string> path;
        backtrack(0, s, path, res);
        return res;
    }

    // For approach 1
    void backtrack(int start, string& s, vector<string>& path, vector<vector<string>>& res) {
        if (start == s.length()) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < s.length(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                backtrack(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};