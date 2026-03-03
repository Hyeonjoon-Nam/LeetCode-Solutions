class Solution {
public:
    int reverseBits(int n) {
        // ================================
        // Approach 1: Bit Manipulation
        // - Time  Complexity: O(1)
        //   (Runs at most 32 times.)
        // - Space Complexity: O(1)
        //   (Constant space used.)
        // - Pros: Optimal.
        // - Cons: 
        // ================================
        int res = 0, pow = 31;
        while (n) {
            res |= (n & 1) << pow;
            n >>= 1;
            --pow;
        }
        return res;
    }
};