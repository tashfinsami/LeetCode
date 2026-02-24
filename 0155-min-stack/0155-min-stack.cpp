class MinStack {
public:
    stack<int> buffer;
    MinStack() {
        
    }
    
    void push(int val) {
        buffer.push(val);
    }
    
    void pop() {
        buffer.pop();
    }

    int top() {
        return buffer.top();
    }
    
    int getMin() {
        stack<int> temp = buffer;
        int mini = temp.top();
        temp.pop();
        while(!temp.empty()) {
            mini = min(mini, temp.top());
            temp.pop();
        }
        return mini;
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