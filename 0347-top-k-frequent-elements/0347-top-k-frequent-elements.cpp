class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // ================================
        // Approach 1: sort + unordered_map
        // - Time  Complexity: O(N log N)
        //   (O(N) for unordered_map (insert takes O(1), we do it N times), O(N log N) for sorting)
        // - Space Complexity: O(N)
        //   (To store numbers in map)
        // - Pros: 
        // - Cons: 
        // ================================
        // unordered_map<int, int> count;
        // for (int x : nums)
        // {
        //     count[x]++;
        // }

        // std::vector<std::pair<int, int>> freq;
        // for (auto& it : count)
        // {
        //     freq.push_back(it);
        // }

        // sort(freq.begin(), freq.end(), [](auto& a, auto& b) {
        //     return a.second > b.second;
        // });

        // vector<int> ans;
        // for (int i = 0; i < k; ++i)
        // {
        //     ans.push_back(freq[i].first);
        // }

        // return ans;
        
        // ================================
        // Approach 2: bucket sort
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        unordered_map<int, int> count;
        for (int x : nums)
        {
            count[x]++;
        }

        int n = nums.size();
        vector<vector<int>> buckets(n + 1);

        for (auto& it : count)
        {
            int num = it.first;
            int freq = it.second;
            buckets[freq].push_back(num);
        }

        vector<int> ans;
        for (int i = n; i >= 0; --i)
        {
            if (buckets[i].empty()) continue;

            for (int num : buckets[i])
            {
                ans.push_back(num);
                if (ans.size() == k) return ans;
            }
        }

        return ans;
    }
};