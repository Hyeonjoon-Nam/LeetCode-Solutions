class Solution {
public:
    int climbStairs(int n) {
        // ================================
        // Approach 1: Dynamic Programming
        // - Time  Complexity: O(n)
        //   (Iterate from 3 to n once.)
        // - Space Complexity: O(1)
        //   (Constant space used.)
        // - Pros: Space efficient.
        // - Cons: Does not store previous values.
        // ================================
        if (n <= 2) return n;

        int first = 1;
        int second = 2;
        int current = 0;

        for (int i = 3; i <= n; i++) {
            current = first + second;
            first = second;
            second = current;
        }
        return second;
    }
};