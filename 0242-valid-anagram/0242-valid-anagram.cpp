class Solution {
public:
    bool isAnagram(string s, string t) {
        // ================================
        // Approach 1: Counting with array
        // - Time  Complexity: O(N)
        //   (Accessing array index takes O(1), and we iterate N times)
        // - Space Complexity: O(1)
        //   (We use only one fixed-size array of 26 integers)
        // - Pros: Fastest & Space efficient
        // - Cons: Limited to specific character set (e.g., lowercase alphabet)
        // ================================
        size_t length1 = s.length(), length2 = t.length();
        if (length1 != length2) return false;

        int count[26] = {};
        for (int i = 0; i < length1; ++i)
        {
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (count[i] != 0) return false;
        }
        return true;

        // ================================
        // Approach 2: Sorting
        // - Time  Complexity: O(N log N)
        //   (Sorting overhead)
        // - Space Complexity: O(1)
        //   (No extra space used)
        // - Pros: Super simple code, works with any unicode characters
        // - Cons: Slower O(N log N)
        // ================================
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;
    }
};