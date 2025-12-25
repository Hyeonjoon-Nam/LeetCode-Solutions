class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // ================================
        // Approach 1: brute force
        // - Time  Complexity: O(N²)
        //   (N * N times)
        // - Space Complexity: O(1)
        //   (No extra space used)
        // - Pros: 
        // - Cons: 
        // ================================
        // int size = nums.size();
        // for (int i = 0; i < nums.size() - 1; ++i)
        // {
        //     for (int j = i + 1; j < nums.size(); ++j)
        //     {
        //         if (i == j) continue;

        //         if (nums[i] + nums[j] == target) return { i, j };
        //     }
        // }
        // return {};


        // ================================
        // Approach 2: hash map
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        vector<pair<int, int>> nice;
        for (int i = 0; i < nums.size(); ++i)
        {
            nice.push_back({ nums[i], i });
        }
        sort(nice.begin(), nice.end());

        int p0 = 0;
        int p1 = nums.size() - 1;

        while (p0 < p1)
        {
            int sum = nice[p0].first + nice[p1].first;
            if (sum == target)
            {
                return {nice[p0].second, nice[p1].second};
            }
            else if (sum > target) p1--;
            else p0++;
        }
        return {};
    }
};