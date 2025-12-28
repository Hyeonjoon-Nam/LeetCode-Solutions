class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // ================================
        // Approach 1: Sorting + Brute Force
        // - Time  Complexity: O(N³)
        //   (Iterate 3 for-loops)
        // - Space Complexity: O(1)
        //   (No extra space used except for the vector for output)
        // - Pros: Intuitive, easy to code
        // - Cons: Time limit exceeds
        // ================================
        // int size = nums.size();
        // sort(nums.begin(), nums.end());
        // vector<vector<int>> ans;

        // for (int i = 0; i < size - 2; i++)
        // {
        //     for (int j = i + 1; j < size - 1; j++)
        //     {
        //         for (int k = j + 1; k < size; k++)
        //         {
        //             if (nums[i] + nums[j] + nums[k] == 0)
        //             {
        //                 vector<int> temp{nums[i], nums[j], nums[k]};
        //                 if (find(ans.begin(), ans.end(), temp) == ans.end())
        //                     ans.push_back(temp);
        //             }
        //         }
        //     }
        // }
        // return ans;
        

        // ================================
        // Approach 2: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i];
            int p0 = i + 1;
            int p1 = n - 1;

            while (p0 < p1)
            {
                int sum = nums[p0] + nums[p1];
                if (sum == target)
                {
                    ans.push_back({nums[i], nums[p0], nums[p1]});

                    while (p0 < p1 && nums[p0] == nums[p0+1]) p0++;
                    while (p0 < p1 && nums[p1] == nums[p1-1]) p1--;

                    p0++;
                    p1--;
                }
                else if (sum > target)
                {
                    p1--;
                }
                else
                {
                    p0++;
                }
            }
        }
        return ans;
    }
};