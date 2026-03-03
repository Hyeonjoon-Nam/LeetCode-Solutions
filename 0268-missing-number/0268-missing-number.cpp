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
        int current_sum = 0;
        int n = nums.size();

        for (int x : nums) {
            current_sum += x;
        }
        
        int correct_sum = (n + 1) * n / 2;
        return correct_sum - current_sum;

        // ================================
        // Approach 1: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        
    }
};