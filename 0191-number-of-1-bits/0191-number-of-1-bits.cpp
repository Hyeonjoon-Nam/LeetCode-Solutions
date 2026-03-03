class Solution {
public:
    int hammingWeight(int n) {
        // ================================
        // Approach 1: Bit Manipulation
        // - Time  Complexity: O(1)
        //   (Worst case 32 iterations, but practically runs exactly 'k' times where 'k' is the number of 1 bits.)
        // - Space Complexity: O(1)
        //   (Only an integer used for the answer.)
        // - Pros: Optimal.
        // - Cons: 
        // ================================
        int count = 0;
        while (n) {
            count += n & 0x1;
            n >>= 1;
        }
        return count;
    }
};