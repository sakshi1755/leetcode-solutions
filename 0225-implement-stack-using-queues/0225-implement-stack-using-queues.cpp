class MyStack {
    vector<int> stk;
public:
    MyStack() {

        
    }
    
    void push(int x) {
        stk.push_back(x);
    }
    
    int pop() {
        int val=stk.back();
        stk.pop_back();
        return val;
        
    }
    
    int top() {
        return stk.back();
    }
    
    bool empty() {
        return stk.empty();
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