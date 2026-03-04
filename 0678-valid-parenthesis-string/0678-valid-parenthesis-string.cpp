class Solution {
public:
    bool checkValidString(string s) {
        // ================================
        // Approach 1: Greedy
        // - Time  Complexity: O(N)
        //   (A single linear pass through the string.)
        // - Space Complexity: O(1)
        //   (Constant space used.)
        // - Pros: Optimal.
        // - Cons: Tricky logic.
        // ================================
        int leftMin = 0, leftMax = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                ++leftMin;
                ++leftMax;
            }
            else if (s[i] == ')') {
                --leftMin;
                --leftMax;
            }
            else {
                --leftMin;
                ++leftMax;
            }

            if (leftMax < 0) return false;
            if (leftMin < 0) leftMin = 0;

        }
        return leftMin == 0;
    }
};