class Solution {
public:
    int getSum(int a, int b) {
        // ================================
        // Approach 1: Bit Manipulation
        // - Time  Complexity: O(1)
        //   (Worst case 32 iterations.)
        // - Space Complexity: O(1)
        //   (Constant space used.)
        // - Pros: Optimal.
        // - Cons: Slightly tricky.
        // ================================
        while (b) {
            int res = a ^ b;
            unsigned int carry = (unsigned int)(a & b) << 1;
            a = res;
            b = carry;
        }
        return a;
    }
};