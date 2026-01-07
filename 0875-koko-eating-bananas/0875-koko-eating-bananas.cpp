class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // ================================
        // Approach 1: Binary search
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        int n = piles.size();
        int left = 1;
        int right = 0;
        int ans = 0;
        for (int x : piles) right = max(right, x);

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            long long time = 0;
            for (int x : piles)
            {
                time += (x + mid - 1) / mid;
            }
            if (time <= h)
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};