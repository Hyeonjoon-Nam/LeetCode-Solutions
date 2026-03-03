class Solution {
public:
    int reverse(int x) {
        // ================================
        // Approach 1: Math
        // - Time  Complexity: O(log x)
        //   (log base 10 of x.)
        // - Space Complexity: O(1)
        //   (Constant space used.)
        // - Pros: Optimal.  
        // - Cons: 
        // ================================
        int res = 0;
        while (x) {
            if (res > INT_MAX / 10 || res < INT_MIN / 10) return 0;
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        return res;
    }
};