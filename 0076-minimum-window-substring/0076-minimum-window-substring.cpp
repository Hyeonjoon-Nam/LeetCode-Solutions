class Solution {
public:
    string minWindow(string s, string t) {
        // ================================
        // Approach 1: Sliding window
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        if (s.length() < t.length()) return "";

        int targetCount[128] = {0};
        int windowCount[128] = {0};
        int need = 0;

        for (char c : t)
        {
            if (targetCount[c] == 0) need++;
            targetCount[c]++;
        }

        int have = 0;
        int left = 0;
        int minLen = INT_MAX;
        int ansStart = 0;

        for (int right = 0; right < s.length(); right++)
        {
            char c = s[right];
            windowCount[c]++;

            if (targetCount[c] > 0 && windowCount[c] == targetCount[c])
                have++;

            while (have == need)
            {
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    ansStart = left;
                }
                char d = s[left];
                windowCount[d]--;

                if (targetCount[d] > 0 && windowCount[d] < targetCount[d])
                    have--;
                
                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(ansStart, minLen);
    }
};