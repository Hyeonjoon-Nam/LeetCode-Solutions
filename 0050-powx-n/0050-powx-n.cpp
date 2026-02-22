class Solution {
public:
    double myPow(double x, int n) {
        // ================================
        // Approach 1: Binary Exponentiation
        // - Time  Complexity: O(log n)
        //   (The exponent is reduced by half in each recursive call.)
        // - Space Complexity: O(log n)
        //   (The recursive stack can use at most O(log n) space.)
        // - Pros: Optimal.
        // - Cons: Recursive overhead.
        // ================================
        return binaryExp(x, (long long) n);
    }
    
    // For approach 1
    double binaryExp(double x, long long n) {
        if (n == 0) {
            return 1;
        }
       
        if (n < 0) {
            return 1.0 / binaryExp(x, -1 * n);
        }
       
        if (n % 2 == 1) {
            return x * binaryExp(x * x, (n - 1) / 2);
        }
        else {
            return binaryExp(x * x, n / 2);
        }
    }
};