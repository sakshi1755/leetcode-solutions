class MinStack {
public:
  stack<long long> s; 
    long long mini;   

    MinStack() {
        mini = LLONG_MAX; 
    }
    
    void push(int val) {
        long long vali=val;
        if(s.empty()){
            s.push(vali);
            mini=vali;
        }
        else {
            if(vali>mini)s.push(vali);
            else {
               long long curr=2LL*vali-mini;
               // int prevmini=mini;
                mini=vali;
                s.push(curr);
            }
        }
    }
    
    void pop() {
        long long topi=s.top();
        if(topi>mini){
            s.pop();
        }
        else{
            long long curr=topi;
            mini=2LL*mini-curr;
            s.pop();
        }
    }
    
    int top() {
        long long topi=s.top();
        if(topi>mini){
            return topi;
        }
        else{
            return mini;
        }
    }
    
    int getMin() {
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