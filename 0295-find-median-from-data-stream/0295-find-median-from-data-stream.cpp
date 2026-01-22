class MedianFinder {
public:
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