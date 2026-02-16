class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // ================================
        // Approach 1: Dynamic Programming
        // - Time  Complexity: O(N²)
        //   (Nested loops: for each element, we scan all previous elements.)
        // - Space Complexity: O(N)
        //   (An array of size N is used to store the LIS length ending at each index.)
        // - Pros: Intuitive.
        // - Cons: Doesn't meet the follow up requirement time complexity O(n log(n))
        // ================================
        // int n = nums.size();
        // vector<int> dp(n, 1);

        // for (int i = 1; i < n; ++i)
        // {
        //     for (int j = 0; j < i; ++j)
        //     {
        //         if (nums[i] > nums[j])
        //         {
        //             dp[i] =  max(dp[i], dp[j] + 1);
        //         }
        //     }
        // }

        // int ans = 0;
        // for (int x : dp)
        // {
        //     ans = max(ans, x);
        // }
        // return ans;
        
        // ================================
        // Approach 2: Binary Search
        // - Time  Complexity: O(N log N)
        //   (We iterate through N elements, and for each, we perform binary search.)
        // - Space Complexity: O(N)
        //   (In the worst case, the tails array can grwo to size N.)
        // - Pros: Efficient, faster than DP appraoch.
        // - Cons: Does not directly store the LIS itself.
        // ================================
        if (nums.empty()) return 0;

        vector<int> tails;

        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);

            if (it == tails.end()) {
                tails.push_back(x);
            }
            else {
                *it = x;
            }
        }
        return tails.size();
    }

};