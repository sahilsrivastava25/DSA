class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(!s2.empty()){
            int el = s2.top();
            s2.pop();
            return el;
        }

        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }

        int el = s2.top();
        s2.pop();
        return el;
    }
    
    int peek() {
         if(!s2.empty()) return s2.top();

        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }

        return s2.top();
    }
    
    bool empty() {
        if(s2.empty()){
            if(s1.empty())
            return true;
        }

        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */