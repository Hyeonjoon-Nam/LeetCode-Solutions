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
        // int n = nums.size();
        // if (n == 0) return -1;
        // if (n == 1) return nums[0] == target ? 0 : -1;
        // int pivot = -1;

        // if (nums[0] > nums[n - 1])
        // {
        //     int left = 0, right = n - 1;

        //     while (left <= right)
        //     {
        //         int mid = left + (right - left) / 2;

        //         if (mid < n - 1 && nums[mid] > nums[mid + 1])
        //         {
        //             pivot = mid;
        //             break;
        //         }
        //         if (mid > 0 && nums[mid - 1] > nums[mid])
        //         {
        //             pivot = mid - 1;
        //             break;
        //         }

        //         if (nums[mid] >= nums[0]) left = mid + 1;
        //         else right = mid - 1;
        //     }
        // }
        // else
        //     pivot = n - 1;
        
        // int left, right;
        // if (target >= nums[0])
        // {
        //     left = 0;
        //     right = pivot;
        // }
        // else
        // {
        //     left = pivot + 1;
        //     right = n - 1;
        // }
        
        // while (left <= right)
        // {
        //     int mid = left + (right - left) / 2;

        //     if (nums[mid] == target) return mid;
        //     else if (nums[mid] < target) left = mid + 1;
        //     else right = mid - 1;
        // }
        
        // return -1;
        
        // ================================
        // Approach 2: One-Pass Binary Search
        // - Time  Complexity: O(log N)
        // - Space Complexity: O(1)
        // ================================
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;

            if (nums[left] <= nums[mid])
            {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};