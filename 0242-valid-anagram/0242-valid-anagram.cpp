class Solution {
public:
    bool isAnagram(string s, string t) {
        // Approach 1: Counting with array
        // size_t length1 = s.length(), length2 = t.length();
        // if (length1 != length2) return false;

        // int count[26] = {};
        // for (int i = 0; i < length1; ++i)
        // {
        //     count[s[i]-'a']++;
        //     count[t[i]-'a']--;
        // }
        // for (int i = 0; i < 26; ++i)
        // {
        //     if (count[i] != 0) return false;
        // }
        // return true;

        // Approach 2: Sorting
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};