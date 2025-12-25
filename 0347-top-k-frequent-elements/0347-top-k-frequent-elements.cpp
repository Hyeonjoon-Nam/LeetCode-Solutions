class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // ================================
        // Approach 1: Sorting + map
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        
        map<int, int> count;
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