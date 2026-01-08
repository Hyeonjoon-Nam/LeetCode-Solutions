class Solution {
public:
    int search(vector<int>& nums, int target) {
        // ================================
        // Approach 1: Find pivot -> Binary search
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        int n = nums.size();
        int left = 0, right = n - 1;
        int mid = 0;
        
        if (n == 1) return nums[0] == target ? 0 : -1;
        if (!(nums[right] > nums[0]))
        {
            while (left <= right)
            {
                mid = left + (right - left) / 2;

                if (nums[mid] > nums[mid+1]) break;
                if (nums[mid-1] < nums[mid]) { mid--; break;}

                if (nums[mid] > nums[0]) left = mid + 1;
                else right = mid - 1;
            }
        }

        if (target > nums[mid]) return -1;
        if (target < nums[mid + 1]) return -1;

        if (target >= nums[0])
        {
            left = 0;
            right = mid;
        }
        else
        {
            left = mid + 1;
            right = n - 1;
        }
        
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        
        return -1;
    }
};