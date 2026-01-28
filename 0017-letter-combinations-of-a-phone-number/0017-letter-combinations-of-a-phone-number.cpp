class Solution {
public:
    unordered_map<char, string> dict = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };

public:
    vector<string> letterCombinations(string digits) {
        // ================================
        // Approach 1: Backtrack
        // - Time  Complexity: O(4^N * N)
        //   (N is the number of digits.)
        // - Space Complexity: O(N)
        //   (The recursion stack is equal to the length of digits N.)
        // - Pros: Concise.
        // - Cons: Recursive overhead.
        // ================================
        if (digits.empty()) return {};

        vector<string> res;
        string path = "";
        backtrack(0, digits, path, res);

        return res;
    }

    // For approach 1
    void backtrack(int index, const string& digits, string& path, vector<string>& res) {
        if (index == digits.length()) {
            res.push_back(path);
            return;
        }

        string letters = dict[digits[index]];

        for (char c : letters) {
            path.push_back(c);
            backtrack(index + 1, digits, path, res);
            path.pop_back();
        }
    }
};