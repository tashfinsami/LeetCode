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
        int min = temp.top();
        temp.pop();
        while(!temp.empty()) {
            if(temp.top() < min) min = temp.top();
            temp.pop();
        }
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