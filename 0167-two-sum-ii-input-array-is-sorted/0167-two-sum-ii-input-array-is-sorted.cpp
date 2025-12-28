class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // ================================
        // Approach 1: Two pointers
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        int n = numbers.size();
        int p0 = 0;
        int p1 = n - 1;
        int sum = 0;

        while (p0 < p1)
        {
            sum = numbers[p0] + numbers[p1];
            if (sum == target) return { p0 + 1, p1 + 1 };
            else if (sum > target) p1--;
            else p0++;
        }
        return {};
    }
};