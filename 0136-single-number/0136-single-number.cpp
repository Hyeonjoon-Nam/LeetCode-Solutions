class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // ================================
        // Approach 1: Bit Manipulation
        // - Time  Complexity: O(N)
        //   (A single linear pass through nums vector.)
        // - Space Complexity: O(1)
        //   (Only an integer for the answer used.)
        // - Pros: Optimal!
        // - Cons: Slightly tricky.
        // ================================
        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }
        return ans;
    }
};