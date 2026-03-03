class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // ================================
        // Approach 1: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
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
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        int n = nums.size(); 
        int res = 0;
        for (int x = 0; x <= n; ++x) {
            res ^= x;
        }
        for (int x : nums) {
            res ^= x;
        }
        return res;
    }
};