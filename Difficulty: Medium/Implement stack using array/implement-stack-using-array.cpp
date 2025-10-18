class myStack {
  public:
    int *arr;
    int used;
    int size;
    
    myStack(int n) {
        arr=new int[n];
        used=-1;
        size=n;
        
        
        // Define Data Structures
    }

    bool isEmpty() {
        if(used==-1) return true;
        else return false;// check if the stack is empty
    }

    bool isFull() {
        if(used==(size-1))return true;
        else return false;
        // check if the stack is full
    }

    void push(int x) {
        used++;
        arr[used]=x;
        // inserts x at the top of the stack
    }

    void pop() {
        if(used>-1)used--;
        // removes an element from the top of the stack
    }

    int peek() {
        if(used>-1)return arr[used];
        else return -1;
        // Returns the top element of the stack
    }
};