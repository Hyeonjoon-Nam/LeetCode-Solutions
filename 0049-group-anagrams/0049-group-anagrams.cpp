class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // ================================
        // Approach 1: Sorting + unordered_map
        // - Time  Complexity: O(N * K log K)
        //   (We iterate N strings, and sorting each string takes O(K log K) where K is max string length)
        // - Space Complexity: O(N * K)
        //   (To store all strings in the map)
        // - Pros: Easy to implement
        // - Cons: Sorting cost (K log K)
        // ================================
        // unordered_map<string, vector<string>> count;

        // for (string str : strs)
        // {
        //     string sorted = str;
        //     sort(sorted.begin(), sorted.end());

        //     count[sorted].push_back(str);
        // }
        // vector<vector<string>> ans;
        // for (auto& it : count)
        // {
        //     ans.push_back(it.second);
        // }

        // return ans;
        
        // ================================
        // Approach 2: Counting(Not sorting) + unordered_map
        // - Time  Complexity: O(N * K log K)
        //   (We iterate N strings, and sorting each string takes O(K log K) where K is max string length)
        // - Space Complexity: O(N * K)
        //   (To store all strings in the map)
        // - Pros: Easy to implement
        // - Cons: Sorting cost (K log K)
        // ================================
        unordered_map<string, vector<string>> count;

        for (string str : strs)
        {
            int* temp = new int[26];

            for (char c : str)
            {
                temp[c-'a']++;
            }
            string key = "";
            for (int i = 0; i < 26; i++)
            {
                key += to_string(temp[i]);
            }
            count[key].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto it : count)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};