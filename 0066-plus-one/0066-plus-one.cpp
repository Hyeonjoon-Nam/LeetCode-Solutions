class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // ================================
        // Approach 1: Reconstruct with reverse.
        // - Time  Complexity: O(n)
        //   (Single pass plus a reverse operation.)
        // - Space Complexity: O(n)
        //   (Creates a new vector to store results.)
        // - Pros: Simple.
        // - Cons: Uses extra memory.
        // ================================
        // vector<int> res;
        // int n = digits.size();
        // int add = 1;

        // for (int i = n - 1; i >= 0; i--) {
        //     int sum = digits[i] + add;
        //     if (sum == 10) {
        //         add = 1;
        //         res.push_back(0);
        //     }
        //     else {
        //         add = 0;
        //         res.push_back(sum);
        //     }
        // }
        // if (add) res.push_back(1);
        // reverse(res.begin(), res.end());
        // return res;

        
        // ================================
        // Approach 2: In-place
        // - Time  Complexity: O(n)
        //   (Average O(1) if the last digit is not 9, worst O(n).)
        // - Space Complexity: O(1)
        //   (Constant space used.)
        // - Pros: Memory efficient.
        // - Cons: Modifies the original input vector.
        // ================================
        int n = digits.size();

        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            }
            else {
                digits[i]++;
                return digits;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};