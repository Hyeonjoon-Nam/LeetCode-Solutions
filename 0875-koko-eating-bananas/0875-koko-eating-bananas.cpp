class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // ================================
        // Approach 1: Binary search
        // - Time  Complexity: O(N * log(max(P)))
        //   (N is the number of piles, log(max(P)) is the search space for speed)
        // - Space Complexity: O(1)
        //   (No extra data structures used)
        // - Pros: Extremly efficient for large value ranges
        // - Cons: Requires careful handling of integer overflow
        // ================================
        int n = piles.size();
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = 0;

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