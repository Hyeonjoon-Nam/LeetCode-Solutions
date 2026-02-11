class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // ================================
        // Approach 1: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
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
        // Approach 2: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
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