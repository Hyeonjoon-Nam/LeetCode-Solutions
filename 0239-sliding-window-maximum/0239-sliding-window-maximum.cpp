class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // ================================
        // Approach 1: Brute force
        // - Time  Complexity: O(N²)
        //   (Iterate elements using two for-loops)
        // - Space Complexity: O(1)
        //   (Constant space used except for a vector for the output)
        // - Pros: Intuitive, easy to code
        // - Cons: Time limit exceeds
        // ================================
        // size_t n = nums.size();
        // vector<int> ans;

        // for (int i = 0; i <= n - k; i++)
        // {
        //     int max_num = INT_MIN;
        //     for (int j = i; j < i + k; j++)
        //     {
        //         max_num = max(max_num, nums[j]);
        //     }
        //     ans.push_back(max_num);
        // }
        // return ans;


        // ================================
        // Approach 2: Sliding window
        // - Time  Complexity: O(N)
        //   (Every element is pushed/popped at most once)
        // - Space Complexity: O(k)
        //   (Deque stores at most k elements)
        // - Pros: Optimal
        // - Cons: 
        // ================================
        vector<int> ans;
        size_t n = nums.size();
        deque<pair<int, int>> myDeque;

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];

            while (!myDeque.empty() && myDeque.back().first < num)
                myDeque.pop_back();

            myDeque.push_back({num, i});

            if (myDeque.front().second <= i - k)
                myDeque.pop_front();

            if (i >= k - 1)
                ans.push_back(myDeque.front().first);
        }
        return ans;
    }
};