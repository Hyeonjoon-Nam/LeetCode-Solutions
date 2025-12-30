class Solution {
public:
    int maxArea(vector<int>& height) {
        // ================================
        // Approach 1: Brute Force
        // - Time  Complexity: O(N²)
        //   (Iterate two for-loops)
        // - Space Complexity: O(1)
        //   (No extra space used)
        // - Pros: Intuitive, easy to code
        // - Cons: Time limie exceeds
        // ================================
        // int size = height.size();
        // int max_water = 0;

        // for (int i = 0; i < size - 1; i++)
        // {
        //     for (int j = i + 1; j < size; j++)
        //     {
        //         max_water = max(max_water, (j - i) * min(height[i], height[j]));
        //     }
        // }
        // return max_water;
        

        // ================================
        // Approach 2: Two pointers
        // - Time  Complexity: O(N)
        //   (Iterate one for-loop)
        // - Space Complexity: O(1)
        //   (No extra space used)
        // - Pros: Pass all the tests
        // - Cons: 
        // ================================
        int size = height.size();

        int p0 = 0;
        int p1 = size - 1;

        int max_water = 0;

        while (p0 < p1)
        {
            max_water = max(max_water, (p1 - p0) * min(height[p0], height[p1]));

            if (height[p0] < height[p1])
                ++p0;
            else
                --p1;
        }
        return max_water;
    }
};