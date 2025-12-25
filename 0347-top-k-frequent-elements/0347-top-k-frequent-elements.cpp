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
        
        unordered_map<int, int> count;
        for (int x : nums)
        {
            count[x]++;
        }

        std::vector<std::pair<int, int>> freq;
        for (auto& it : count)
        {
            freq.push_back(it);
        }

        sort(freq.begin(), freq.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });

        vector<int> ans;
        for (int i = 0; i < k; ++i)
        {
            ans.push_back(freq[i].first);
        }

        return ans;
    }
};