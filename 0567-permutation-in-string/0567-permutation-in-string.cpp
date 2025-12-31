class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // ================================
        // Approach 1: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        sort(s1.begin(), s1.end());
        size_t length1 = s1.length();
        size_t length2 = s2.length();
        if (length1 > length2) return false;
        
        for (int i = 0; i < length2 - length1 + 1; i++)
        {
            string sub = s2.substr(i, length1);
            sort(sub.begin(), sub.end());
            if (s1 == sub) return true;
        }
        return false;

    }
};