class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // ================================
        // Approach 1: Math
        // - Time  Complexity: O(N)
        //   (A single pass through nums.)
        // - Space Complexity: O(1)
        //   (Constant space used.)
        // - Pros: Intuitive.
        // - Cons: Potential integer overflow.
        // ================================
        // int current_sum = 0;
        // int n = nums.size();

        // for (int x : nums) {
        //     current_sum += x;
        // }
        
        // int correct_sum = (n + 1) * n / 2;
        // return correct_sum - current_sum;

        // ================================
        // Approach 2: Bit Manipulation
        // - Time  Complexity: O(N)
        //   (A single linear pass through nums.)
        // - Space Complexity: O(1)
        //   (Constant space used.)
        // - Pros: Optimal.
        // - Cons: Less intuitive.
        // ================================
        int n = nums.size(); 
        int res = n;

        for (int i = 0; i < n; ++i) {
            res ^= i;
            res ^= nums[i];
        }
        
        return res;
    }
};