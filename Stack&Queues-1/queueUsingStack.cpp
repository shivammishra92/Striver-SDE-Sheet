class MyQueue {
public:
    stack<int>in;
    stack<int>out;
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
        int item = out.top();
        out.pop();
        while(!out.empty()){
            in.push(out.top());
            out.pop();
        }
        return item;
    }
    
    int peek() {
         while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
        int item = out.top();
        while(!out.empty()){
            in.push(out.top());
            out.pop();
        }
        return item;
    }
    
    bool empty() {
        if(!in.empty())
        return false;
        else return true;
    }
};

