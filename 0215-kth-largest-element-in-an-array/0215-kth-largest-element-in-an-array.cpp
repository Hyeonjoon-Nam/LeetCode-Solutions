class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // ================================
        // Approach 1: Min-Heap (K-sized)
        // - Time  Complexity: O(N log k)
        //   (N times of push/pop computation, each computation takes O(log k))
        // - Space Complexity: O(k)
        //   (Only stores k number of elements)
        // - Pros: 
        // - Cons: 
        // ================================
        // priority_queue<int, vector<int>, greater<int>> q;

        // for (int x : nums) {
        //     q.push(x);

        //     if (q.size() > k) q.pop();
        // }

        // return q.top();

        // ================================
        // Approach 2: Quickselect
        // - Time  Complexity: Average O(N), Worst O(N²)
        //   (Average O(N) due to random pivot selection, O(N²) if pivot is consistently the min/max)
        // - Space Complexity: O(N)
        //   (New vector left, mid, right are created at each steps)
        // - Pros: Faster on average than Heap approach.
        // - Cons: Performance is highly dependent on pivot choice, O(N) extra space
        // ================================
        return quickSelect(nums, k);
    }
    
    // For approach 2
    int quickSelect(vector<int>& nums, int k) {
        int pivot = nums[rand() % nums.size()];

        vector<int> left;
        vector<int> mid;
        vector<int> right;

        for (int num : nums) {
            if (num > pivot) {
                left.push_back(num);
            } else if (num < pivot) {
                right.push_back(num);
            } else {
                mid.push_back(num);
            }
        }

        if (k <= left.size()) {
            return quickSelect(left, k);
        }

        if (left.size() + mid.size() < k) {
            return quickSelect(right, k - left.size() - mid.size());
        }

        return pivot;
    }
};