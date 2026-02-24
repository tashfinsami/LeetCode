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
        stack<int> temp;
        int min_val = buffer.top();
        temp.push(buffer.top());
        buffer.pop();

        while(!buffer.empty()) {
            min_val = min(min_val, buffer.top());
            temp.push(buffer.top());
            buffer.pop();
        }
        while(!temp.empty()) {
            buffer.push(temp.top());
            temp.pop();
        }
        return min_val;
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