class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // ================================
        // Approach 1: brute force
        // - Time  Complexity: O(N²)
        //   (N * N times)
        // - Space Complexity: O(1)
        //   (No extra space used)
        // - Pros: Space efficient
        // - Cons: Doesn't meet the requirement (better than O(N²))
        // ================================
        // int size = nums.size();
        // for (int i = 0; i < nums.size() - 1; ++i)
        // {
        //     for (int j = i + 1; j < nums.size(); ++j)
        //     {
        //         if (nums[i] + nums[j] == target) return { i, j };
        //     }
        // }
        // return {};


        // ================================
        // Approach 2: Sorting
        // - Time  Complexity: O(N log N)
        //   (Sorting takes O(N log N))
        // - Space Complexity: O(N)
        //   (To store numbers in vector)
        // - Pros: Better than O(N²)
        // - Cons: Uses extra space
        // ================================
        vector<pair<int, int>> pairs;
        //pairs.reserve(nums.size());

        for (int i = 0; i < nums.size(); ++i)
        {
            pairs.push_back({ nums[i], i });
        }
        sort(pairs.begin(), pairs.end());

        int p0 = 0;
        int p1 = nums.size() - 1;

        while (p0 < p1)
        {
            int sum = pairs[p0].first + pairs[p1].first;
            if (sum == target)
            {
                return {pairs[p0].second, pairs[p1].second};
            }
            else if (sum > target) p1--;
            else p0++;
        }
        return {};

        
        // ================================
        // Approach 3: Hash Map
        // - Time  Complexity: O(N)
        //   (Insert, find takes O(1) with unordered_map, we do it N times)
        // - Space Complexity: O(N)
        //   (To store numbers to unordered_map)
        // - Pros: Even better than O(N log N)
        // - Cons: Uses extra space O(N)
        // ================================
        // unordered_map<int, int> hash;

        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     int complement = target - nums[i];
        //     if (hash.find(complement) != hash.end())
        //     {
        //         return { hash[complement], i };
        //     }
        //     hash[nums[i]] = i;
        // }
        // return {};
    }
};