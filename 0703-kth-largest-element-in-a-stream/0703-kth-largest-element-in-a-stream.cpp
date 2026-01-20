class KthLargest {
public:
    int kSize;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    // ================================
    // Approach 1: Min-Heap (K-sized)
    // - Time  Complexity: O(N log K)
    //   (Constructor: O(N log K), add(): O(log K))
    // - Space Complexity: O(K)
    //   (Only stores the K largest elements)
    // - Pros: Optimal for data streams.
    // - Cons: Cannot access elements other than the K-th largest.
    // ================================
    KthLargest(int k, vector<int>& nums) {
        kSize = k;

        for (int x : nums) {
            add(x);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        if (minHeap.size() > kSize) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */