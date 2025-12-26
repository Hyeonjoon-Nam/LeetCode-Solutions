class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // ================================
        // Approach 1: Sorting
        // - Time  Complexity: O(N log N)
        //   (Sorting takes O(N log N). Traverse N elements)
        // - Space Complexity: O(1)
        //   (No extra space used)
        // - Pros: Easy to code. Intuitive
        // - Cons: Does not meet the requirement O(n)
        // ================================
        // if (nums.size() == 0) return 0;

        // sort(nums.begin(), nums.end());
        // int m = 1;
        // int cur = 1;
        // for (int i = 0; i < nums.size() - 1; i++)
        // {
        //     if (nums[i] == nums[i + 1])
        //         continue;
        //     else if (nums[i] + 1 == nums[i + 1])
        //     {
        //         cur++;
        //         m = max(m, cur);   
        //     }
        //     else
        //     {
        //         cur = 1;
        //     }
        // }
        // return m;

        
        // ================================
        // Approach 2: Hash set
        // - Time  Complexity: O(N)
        //   ()
        // - Space Complexity: O(N)
        //   ()
        // - Pros: Meets the requirement O(N)
        // - Cons: High memory usage compared to O(1) space
        // ================================
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longestStreak = 0;
        for (int num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;
                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};