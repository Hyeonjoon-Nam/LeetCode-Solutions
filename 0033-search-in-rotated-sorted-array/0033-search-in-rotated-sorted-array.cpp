class Solution {
public:
    int search(vector<int>& nums, int target) {
        // ================================
        // Approach 1: Find pivot -> Binary search
        // - Time  Complexity: O(log N)
        //   (Two binary searches: 1. Find pivot, 2. Search target)
        // - Space Complexity: O(1)
        //   (Constant space used for pointers)
        // - Pros: Logical separation, easier to debug
        // - Cons: Slightly more verbose, two passes of binary search
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
        //   (Identify the sorted half and narrow search in one pass)
        // - Space Complexity: O(1)
        //   (Constant space used)
        // - Pros: Concise, and slightly better constant performance.
        // - Cons: Tricky conditional logic compared to two-pass approach.
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