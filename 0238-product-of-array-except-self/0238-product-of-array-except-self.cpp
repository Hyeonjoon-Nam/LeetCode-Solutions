class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // ================================
        // Approach 1: brute force
        // - Time  Complexity: O(N²)
        //   (Iterate all numbers in the vector N² times)
        // - Space Complexity: O(1)
        //   (Excluding a vector for the output)
        // - Pros: Easy to code
        // - Cons: Time limit exceeds
        // ================================
        // vector<int> sol;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     int mul = 1;
        //     for (int j = 0; j < nums.size(); j++)
        //     {
        //         if (i == j) continue;
        //         mul *= nums[j];
        //     }
        //     sol.push_back(mul);
        // }
        // return sol;

        
        // ================================
        // Approach 2: Yeah
        // - Time  Complexity: O(N)
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        vector<int> leftToRight;
        leftToRight.reserve(nums.size());
        int mul = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            mul *= nums[i];
            leftToRight.emplace_back(mul);
        }

        vector<int> rightToLeft;
        rightToLeft.reserve(nums.size());
        mul = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            mul *= nums[i];
            rightToLeft.emplace_back(mul);
        }
        reverse(rightToLeft.begin(), rightToLeft.end());

        vector<int> sol;
        sol.reserve(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                sol.emplace_back(rightToLeft[i+1]);
            }
            else if (i == nums.size() - 1)
            {
                sol.emplace_back(leftToRight[i - 1]);
            }
            else
            {
                sol.emplace_back(leftToRight[i - 1] * rightToLeft[i + 1]);
            }
        }
        return sol;
    }
};