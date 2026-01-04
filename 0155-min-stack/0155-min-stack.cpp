class MinStack {
public:
    stack<pair<int, int>> minStack;
public:
    // ================================
    // Approach 1: Single Stack with Pair
    // - Time  Complexity: O(1)
    //   (push, pop, top, getMin all take constant time)
    // - Space Complexity: O(N)
    //   (Each element is stored as a pair {value, current_min})
    // - Pros: Easy to code, no extra logic for sync
    // - Cons: Use 2x memory compared to a standard stack
    // ================================
    MinStack() {

    }
    
    void push(int val) {
        if (minStack.empty())
        {
            minStack.push({val, val});
        }
        else
        {
            minStack.push({val, min(val, getMin())});
        }
    }
    
    void pop() {
        minStack.pop();
    }
    
    int top() {
        return minStack.top().first;
    }
    
    int getMin() {
        return minStack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */