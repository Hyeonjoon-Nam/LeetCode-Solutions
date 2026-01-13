class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // ================================
        // Approach 1: Brute force
        // - Time  Complexity: O(N²)
        //   (Iterate each elements using two for-loops)
        // - Space Complexity: O(1)
        //   (No extra space used)
        // - Pros: Intuitive, easy to imeplement
        // - Cons: Too slow (O(N²)), time limit exceeds
        // ================================
        // int n = nums.size();
        // for (int i = 0; i < n - 1; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (i == j) continue;;
        //         if (nums[i] == nums[j]) return nums[i];
        //     }
        // }
        // return -1;

        // ================================
        // Approach 2: Floyd's Tortoise and Hare 
        // - Time  Complexity: O(N)
        //   (Finding meeting point, finding entry point)
        // - Space Complexity: O(1)
        //   (Constant space without modifying the input array)
        // - Pros: Meets all constraints (No extra space, No modification)
        // - Cons: Slightly compley logic
        // ================================
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};