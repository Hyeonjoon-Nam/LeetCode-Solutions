class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // ================================
        // Approach 1: Sorting + unordered_map
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        unordered_map<string, vector<string>> count;

        for (string str : strs)
        {
            string sorted = str;
            sort(sorted.begin(), sorted.end());

            count[sorted].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto& it : count)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};