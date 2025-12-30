class Solution {
public:
    int trap(vector<int>& height) {
        // ================================
        // Approach 1: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        int maxIndex = 0;
        int maxHeight = 0;
        int sum = 0;

        for (int i = 0; i < height.size(); i++)
        {
            if (maxHeight < height[i])
            {
                maxHeight = height[i];
                maxIndex = i;
            }
        }

        int localMax = 0;
        for (int i = 0; i < maxIndex; i++)
        {
            if (localMax < height[i])
            {
                localMax = height[i];
            }
            else
            {
                sum += localMax - height[i];
            }
        }

        localMax = 0;
        for (int i = height.size() - 1; i >= maxIndex; i--)
        {
            if (localMax < height[i])
            {
                localMax = height[i];
            }
            else
            {
                sum += localMax - height[i];
            }
        }

        return sum;

        // ================================
        // Approach 1: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
    }
};