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
        // - Time  Complexity: O(N)
        //   (Iterate once)
        // - Space Complexity: O(1)
        //   (Constant space for mProfit, min_buy_price)
        // - Pros: Optimal, passes all the tests
        // - Cons: 
        // ================================
        int mProfit = 0;
        int min_buy_price = INT_MAX;

        for (int price : prices)
        {
            if (price < min_buy_price)
            {
                min_buy_price = price;
            }
            else if (price - min_buy_price > mProfit)
            {
                mProfit = price - min_buy_price;
            }
        }
        return mProfit;
    }
};