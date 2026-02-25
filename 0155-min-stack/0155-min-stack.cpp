class MinStack {
public:
    stack<long> stk;
    long min;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()) {
            stk.push(0);
            min = val;
        }
        else {
            stk.push(val - min);
            if(val < min) min = val;
        }
    }
    
    void pop() {
        if(stk.top() < 0) min -= stk.top();
        stk.pop();
    }

    int top() {
        if(stk.top() < 0) return min;
        else return stk.top() + min;
    }
    
    int getMin() {
        return min;
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