class Solution {
public:
    int characterReplacement(string s, int k) {
        // ================================
        // Approach 1: Sliding window
        // - Time  Complexity: O(N)
        //   (Iterate all the elements once)
        // - Space Complexity: O(1)
        //   (Constant space used)
        // - Pros: Optimal
        // - Cons: 
        // ================================
        int count[26] = { 0 };
        int maxCount = 0;
        int left = 0;
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++)
        {
            maxCount = max(maxCount, ++count[s[i] - 'A']);

            if ((i - left + 1) - maxCount > k)
            {
                count[s[left] - 'A']--;
                left++;
            }
            maxLength = max(maxLength, i - left + 1);
        }
        return maxLength;
    }
};