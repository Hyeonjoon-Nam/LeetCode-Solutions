class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // ================================
        // Approach 1: Using set.
        // - Time  Complexity: O(N log N)
        //   (Insert/Find takes O(log N), we do this N times.)
        // - Space Complexity: O(N)
        // - Pros: Data are always sorted (ordered)
        // - Cons: slower than unordered_set
        //         no reason to sort to solve this problem
        // ================================
        // set<int> seen;

        // for (int x : nums)
        // {
        //     if (seen.find(x) != seen.end())
        //         return true;

        //     seen.insert(x);
        // }
        // return false;

        // ================================
        // Approach 2: Using unordered_set
        // - Time  Complexity: O(N)
        // - Space Complexity: O(N)
        // - Pros: Best time complexity
        // - Cons: Space overhead
        // ================================
        unordered_set<int> seen;

        for (int x : nums)
        {
            if (seen.find(x) != seen.end())
                return true;
            
            seen.insert(x);
        }
        return false;
        
        // ================================
        // Approach 3: Sorting
        // - Time  Complexity: O(N log N)
        //   (std::sort uses Introsort which is O(N log N))
        // - Space Complexity: O(1)
        //   (No extra data structure used.)
        // - Pros: Space efficient
        // - Cons: Changes the original order of the number
        // ================================
        // sort(nums.begin(), nums.end());
        // for (int i = 0; i < nums.size() - 1; ++i)
        // {
        //     if (nums[i] == nums[i+1]) return true;
        // }
        // return false;
    }
};