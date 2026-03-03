class Solution {
public:
    vector<int> countBits(int n) {
        // ================================
        // Approach 1: Bit Manipulation + Dynamic Programming
        // - Time  Complexity: O(n)
        //   (A single linear iteration.)
        // - Space Complexity: O(1)
        //   (Constant space used except for the required result vector.)
        // - Pros: Optimal.
        // - Cons: 
        // ================================
        vector<int> res(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            res[i] = res[i>>1] + (i&1);
        }
        return res;
    }
};