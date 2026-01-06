class Solution {
public:
    int search(vector<int>& nums, int target) {
        // ================================
        // Approach 1: Linear search
        // - Time  Complexity: O(N)
        //   (Iterate each elements linearly)
        // - Space Complexity: O(1)
        //   (No extra space used)
        // - Pros: Easy
        // - Cons: Doens't meet the requirement O(log N)
        // ================================
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target) return i;
        }
        return -1;

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