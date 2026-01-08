class Solution {
public:
    int findMin(vector<int>& nums) {
        // ================================
        // Approach 1: Binary search
        // - Time  Complexity: O(log N)
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        int n = nums.size();
        int left = 0, right = n - 1;
        int mid = 0;
        if (n == 1) return nums[0];
        if (nums[right] > nums[0]) return nums[0];

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1]) return nums[mid + 1];
            if (nums[mid - 1] > nums[mid]) return nums[mid];

            if (nums[mid] > nums[0]) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};