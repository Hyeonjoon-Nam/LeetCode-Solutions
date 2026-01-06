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
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (nums[i] == target) return i;
        // }
        // return -1;

        // ================================
        // Approach 2: Find Upper bound
        // - Time  Complexity: O(log N)
        //   (Binary search)
        // - Space Complexity: O(1)
        //   (Constant space used)
        // - Pros: Optimal for sorted arrays
        // - Cons: 
        // ================================
        // int left = 0;
        // int right = nums.size() - 1;
        
        // while (left <= right)
        // {
        //     int mid = left + (right - left) / 2;

        //     if (nums[mid] == target)
        //         return mid;
        //     else if (nums[mid] <= target)
        //         left = mid + 1;
        //     else
        //         right = mid - 1;
        // }

        // return -1;

        // ================================
        // Approach 3: Using upper_bound()
        // - Time  Complexity: O(log N)
        //   (std::upped_bound uses binary seach that takes O(log N))
        // - Space Complexity: O(1)
        //   (No extra space used)
        // - Pros: Concise
        // - Cons: 
        // ================================
        int index = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (index > 0 && nums[index - 1] == target) return index - 1;
        else return -1;
    }
};