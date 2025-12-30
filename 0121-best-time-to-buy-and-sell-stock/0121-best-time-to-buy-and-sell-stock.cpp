class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // ================================
        // Approach 1: Brute Force
        // - Time  Complexity: O(N²)
        //   (Two for-loops)
        // - Space Complexity: O(1)
        //   (Constant space)
        // - Pros: Intuitive
        // - Cons: Time limit exceeds
        // ================================
        // int mProfit = 0;
        // int cur;
        // int size = prices.size();

        // for (int i = 0; i < size - 1; i++)
        // {
        //     int buy = prices[i];

        //     for (int j = i + 1; j < size; j++)
        //     {
        //         int sell = prices[j];

        //         mProfit = max(mProfit, sell-buy);
        //     }
        // }
        // return mProfit;
        
        // ================================
        // Approach 2: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        int sum = 0;
        int buy = INT_MAX;
        int sell = 0;
        bool bought = false;
        for (int x : prices)
        {
            if (x < buy && !bought)
            {
                buy = x;
            }
            else if (x >= buy)
            {
                sum += x - buy;
                buy = x;
                bought = true;
            }

        }
        return sum;
    }
};