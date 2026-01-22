class MedianFinder {
public:
    priority_queue<int> q;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        q.push(num);
    }
    
    double findMedian() {
        int n = q.size();
        auto temp = q;

        bool odd = n & 0x1;

        for (int i = 0; i < ((n - 1) / 2); i++) {
            temp.pop();
        }

        if (odd) {
            cout<<"odd: "<<temp.top()<<endl;
            return temp.top(); 
        } else {
            double n1 = temp.top(); temp.pop();
            double n2 = temp.top();
            cout<<"even: "<<n1<<", "<<n2<<endl;
            return (n1 + n2) / 2.0;
        }
        return -1;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */