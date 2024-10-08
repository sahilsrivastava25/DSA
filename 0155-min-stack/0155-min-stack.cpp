class MinStack {
public:
    stack<long long int> st;
    long long int min;

    MinStack() {
        
    }
    
    void push(long long int val) {
        if(st.empty()){
            min = val;
            st.push(val);
        }

        else if(val < min){
            st.push(2*val - min);
            min = val;
        }

        else st.push(val);
    }
    
    void pop() {
        if(st.top() < min) min = 2*min - st.top();
        st.pop();
    }
    
    long long int top() {
        if(st.top() < min) return min;
        else return st.top(); 
    }
    
    long long int getMin() {
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