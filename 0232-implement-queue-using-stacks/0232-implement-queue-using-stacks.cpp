class MyQueue {
    stack<int>st;
    stack<int>st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
        
        
    }
    
    int pop() {
        if(!st2.empty()){
            int val=st2.top();
            st2.pop();
            return val;
        }
        int val=st.top();
        st2.push(val);
        st.pop();
        while(!st.empty()){
            val=st.top();
        st2.push(val);
        st.pop();
            
        }
        st2.pop();
        return val;
    }
    
    int peek() {
         if(!st2.empty()){
            int val=st2.top();
           
            return val;
        }
        int val=st.top();
        st2.push(val);
        st.pop();
        while(!st.empty()){
            val=st.top();
        st2.push(val);
        st.pop();
            
        }
        return val;

        
    }
    
    bool empty() {
        if(st.empty() && st2.empty())return true;
        else return false;
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