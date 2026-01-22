class MedianFinder {
public:
    // ================================
    // Approach 1: Two Heaps
    // - Time  Complexity: O(logN)
    //   addNum: O(logN) Standard heap insertion and rebalancing
    //   findMedian: O(1) Immediate access to the tops of the heaps
    // - Space Complexity: O(N)
    //   (All elements are stored in the two priority queues)
    // - Pros: Finding the median is extremely efficient.
    // - Cons: Requires more logic to maintain balance between two heaps.
    // ================================
    priority_queue<int> leftMax;
    priority_queue<int, vector<int>, greater<int>> rightMin;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        leftMax.push(num);

        rightMin.push(leftMax.top());
        leftMax.pop();

        if (leftMax.size() < rightMin.size()) {
            leftMax.push(rightMin.top());
            rightMin.pop();
        }
    }
    
    double findMedian() {
        if (leftMax.size() > rightMin.size()) {
            return leftMax.top();
        } else {
            return (leftMax.top() + rightMin.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */