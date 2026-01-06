class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // ================================
        // Approach 1: Brute force
        // - Time  Complexity: O(N²)
        //   (Iterate two for-loops)
        // - Space Complexity: O(1)
        //   (No extra space used except for a vector for ans)
        // - Pros: Easy to implement
        // - Cons: Time limit exceeds
        // ================================
        // int n = temperatures.size();
        // vector<int> ans;

        // for (int i = 0; i < n - 1; i++)
        // {
        //     int cur = temperatures[i];
        //     int future = i;
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         int temp = temperatures[j];

        //         if (temp > cur)
        //         {
        //             future = j;
        //             break;
        //         }
        //     }
        //     ans.push_back(future - i);
        // }
        // ans.push_back(0);
        // return ans;

        
        // ================================
        // Approach 2: Monotonic Stack
        // - Time  Complexity: O(N)
        //   (Each index is pushed and popped exactly once)
        // - Space Complexity: O(N)
        //   (In the worst case, the stack stores all indices)
        // - Pros: Optimal linear time solution, much faster than O(N²)
        // - Cons: Requires O(N) extra space for stack
        // ================================
        stack<int> stk;
        int n = temperatures.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            int temp = temperatures[i];

            while (!stk.empty() && temp > temperatures[stk.top()])
            {
                int prev = stk.top(); stk.pop();
                ans[prev] = i - prev;
            }
            stk.push(i);
        }
        return ans;
    }
};