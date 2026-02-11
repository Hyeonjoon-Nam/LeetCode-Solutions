class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // ================================
        // Approach 1: DP
        // - Time  Complexity: O(n)
        //   (We iterate through the cost array once.)
        // - Space Complexity: O(n)
        //   (To store optimal cost each step to the array dp.)
        // - Pros: Intuitive.
        // - Cons: Uses extra space.
        // ================================
        // if (cost.empty()) return 0;

        // int n = cost.size();

        // int dp[n + 2];
        // dp[n] = 0;
        // dp[n+1] = 0;

        // for (int i = n - 1; i >= 0; i--) {
        //     dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        // }
        // return min(dp[0], dp[1]);
        
        // ================================
        // Approach 2: DP + optimize
        // - Time  Complexity: O(n)
        //   (We iterate through the cost array once.)
        // - Space Complexity: O(1)
        //   (We only store the costs for the next two steps.)
        // - Pros: Memory efficient. Constant space used.
        // - Cons: Modifies variables.
        // ================================
        if (cost.empty()) return 0;

        int n = cost.size();

        int next1 = 0;
        int next2 = 0;

        for (int i = n - 1; i >= 0; i--) {
            int current = cost[i] + min(next1, next2);

            next2 = next1;
            next1 = current;
        }

        return min(next1, next2);
    }
};