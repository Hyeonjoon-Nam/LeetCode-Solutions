class Solution {
public:
    bool canJump(vector<int>& nums) {
        // ================================
        // Approach 1: Dynamic Programming
        // - Time  Complexity: O(N²)
        //   (In the worst case, the inner loop runs up to N times for each element.)
        // - Space Complexity: O(N)
        //   (Allocates a boolean vector of size N.)
        // - Pros: Intuitive.
        // - Cons: Not optimal.
        // ================================
        // int n = nums.size();
        // if (n <= 0) return true;

        // vector<bool> possible(n, false);
        // possible[0] = true;

        // for (int i = 0; i < n; ++i) {
        //     if (!possible[i]) return false;

        //     for (int j = 0; j < nums[i]; ++j) {
        //         int index = i + j + 1;
        //         if (index >= n) break;
        //         else possible[index] = true;
        //     }
        // }
        // return true;

        // ================================
        // Approach 2: Greedy
        // - Time  Complexity: O(N)
        //   (A single linear pass through the array.)
        // - Space Complexity: O(1)
        //   (Constant space used.)
        // - Pros: Optimal.
        // - Cons: 
        // ================================
        int n = nums.size();
        int max_reach = 0;

        for (int i = 0; i < n; ++i) {
            if (i > max_reach) return false;

            max_reach = max(max_reach, i + nums[i]);

            if (max_reach >= n - 1) return true;
        }
        return true;
    }
};