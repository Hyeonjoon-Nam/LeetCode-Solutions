class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // ================================
        // Approach 1: Sorting
        // - Time  Complexity: O(N² log N)
        //   (std::sort takes O(N log N), we do it N times)
        // - Space Complexity: O(log N)
        //   (std::sort takes O(log N))
        // - Pros: Intuitive
        // - Cons: Not optimal
        // ================================
        // sort(s1.begin(), s1.end());
        // size_t length1 = s1.length();
        // size_t length2 = s2.length();
        // if (length1 > length2) return false;

        // for (int i = 0; i < length2 - length1 + 1; i++)
        // {
        //     string sub = s2.substr(i, length1);
        //     sort(sub.begin(), sub.end());
        //     if (s1 == sub) return true;
        // }
        // return false;
        
        // ================================
        // Approach 2: Sliding window
        // - Time  Complexity: O(N2)
        //   (N2 is length of s2)
        // - Space Complexity: O(1)
        //   (Fixed size array of 26)
        // - Pros: Optimal
        // - Cons: 
        // ================================
        int n1 = s1.length();
        int n2 = s2.length();

        if (n1 > n2) return false;

        array<int, 26> count1 = { 0 };
        array<int, 26> count2 = { 0 };
        
        for (int i = 0; i < n1; i++)
        {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        if (count1 == count2) return true;

        for (int i = n1; i < n2; i++)
        {
            count2[s2[i - n1] - 'a']--;
            count2[s2[i] - 'a']++;

            if (count1 == count2) return true;
        }

        return false;
    }
};