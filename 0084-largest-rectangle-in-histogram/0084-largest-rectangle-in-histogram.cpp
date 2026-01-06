class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // ================================
        // Approach 1: Brute force
        // - Time  Complexity: O(N²)
        //   (Iterate each elements using two loops)
        // - Space Complexity: O(1)
        //   (Constant space used)
        // - Pros: Easy to implement
        // - Cons: Too slow (O(N²)), so time limit exceeds
        // ================================
        // int n = heights.size();
        // int maxArea = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     int height = heights[i];
        //     int left = i - 1;
        //     int right = i + 1;

        //     while (left >= 0 && heights[left] >= height) left--;
        //     while (right < n && heights[right] >= height) right++;
        //     left++;
        //     right--;

        //     int area = (right - left + 1) * height;
        //     maxArea = max(maxArea, area);
        // }
        // return maxArea;
        
        // ================================
        // Approach 2: Stack
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        heights.push_back(0);
        int n = heights.size();
        stack<int> stk;
        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && heights[stk.top()] > heights[i])
            {
                int h = heights[stk.top()];
                stk.pop();

                int width = stk.empty() ? i : (i - stk.top() - 1);
                
                maxArea = max(maxArea, h * width);
            }
            stk.push(i);
        }
        return maxArea;
    }
};