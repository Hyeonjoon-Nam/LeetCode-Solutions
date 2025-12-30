class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // ================================
        // Approach 1: Sliding window
        // - Time  Complexity: O(N)
        //   (Iterate elements once, insert/find functions of unordered_map takes O(1))
        // - Space Complexity: O(min(m, n))
        //   (m is the size of character set, n is the length of the string)
        // - Pros: Optimal time and space
        // - Cons: Hash map overhead
        // ================================
        unordered_map<char, int> hash;
        int left = 0;
        int max_length = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (hash.find(c) != hash.end() && hash[c] >= left)
            {
                left = hash[c] + 1;
            }
            hash[c] = i;
            max_length = max(max_length, i - left + 1);
        }
        return max_length;
    }
};