class MyStack {
public:
    deque<int>dq;
    MyStack() {
        
    }
    
    void push(int x) {
        dq.push_back(x);
    }
    
    int pop() {
       // if(!dq.empty())
        int elem = dq.back();
        dq.pop_back();
        return elem;
    }
    
    int top() {
        int topElem = dq.back();
        return topElem;
    }
    
    bool empty() {
       return dq.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */